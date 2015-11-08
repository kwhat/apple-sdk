/*
    NSGestureRecognizer.h
    Application Kit
    Copyright (c) 2013-2014, Apple Inc.
    All rights reserved.
*/

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@protocol NSGestureRecognizerDelegate;
@class NSView, NSEvent;

NS_ENUM_AVAILABLE_MAC(10_10)
typedef NS_ENUM(NSInteger, NSGestureRecognizerState) {
    NSGestureRecognizerStatePossible,   // the recognizer has not yet recognized its gesture, but may be evaluating events. this is the default state
    
    NSGestureRecognizerStateBegan,      // the recognizer has received events recognized as the gesture. the action method will be called at the next turn of the run loop
    NSGestureRecognizerStateChanged,    // the recognizer has received events recognized as a change to the gesture. the action method will be called at the next turn of the run loop
    NSGestureRecognizerStateEnded,      // the recognizer has received events recognized as the end of the gesture. the action method will be called at the next turn of the run loop and the recognizer will be reset to NSGestureRecognizerStatePossible
    NSGestureRecognizerStateCancelled,  // the recognizer has received events resulting in the cancellation of the gesture. the action method will be called at the next turn of the run loop. the recognizer will be reset to NSGestureRecognizerStatePossible
    
    NSGestureRecognizerStateFailed,     // the recognizer has received an event sequence that can not be recognized as the gesture. the action method will not be called and the recognizer will be reset to NSGestureRecognizerStatePossible
    
    // Discrete Gestures – gesture recognizers that recognize a discrete event but do not report changes (for example, a click) do not transition through the Began and Changed states and can not fail or be cancelled
    NSGestureRecognizerStateRecognized = NSGestureRecognizerStateEnded // the recognizer has received events recognized as the gesture. the action method will be called at the next turn of the run loop and the recognizer will be reset to NSGestureRecognizerStatePossible
};

NS_CLASS_AVAILABLE_MAC(10_10)
@interface NSGestureRecognizer : NSObject <NSCoding> {
  @private
    NSMutableArray                   *_targets;
    __weak id                        _target;
    SEL                              _action;
    NSMutableArray                   *_delayedEvents;
    __weak NSView                    *_view;
    NSEvent                          *_updateEvent;
    __weak id <NSGestureRecognizerDelegate>  _delegate;
    NSMutableSet                     *_friends;
    NSGestureRecognizerState          _state;
    NSUInteger                        _gestureFlags;
    NSUInteger                        _delayFlags;
    
    NSMutableSet                     *_failureRequirements;
    NSMutableSet                     *_failureDependents;
    NSMutableSet                     *_dynamicFailureRequirements;
    NSMutableSet                     *_dynamicFailureDependents;
    id                                _failureMap;
    
    id                                _reserved;
}

/* valid action method signatures:
     -(void)handleGesture;
     -(void)handleGesture:(NSGestureRecognizer*)gestureRecognizer;
*/
- (instancetype)initWithTarget:(id)target action:(SEL)action NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

@property (weak) id target;
@property SEL action;

/* the current state of the gesture recognizer */
@property (readonly) NSGestureRecognizerState state;

/* the gesture recognizer's delegate */
@property (weak) id <NSGestureRecognizerDelegate> delegate;

/* default is YES. disabled gesture recognizers will not receive events. when changed to NO the gesture recognizer will be cancelled if it's currently recognizing a gesture */
@property (getter=isEnabled) BOOL enabled;

/* an NSGestureRecognizer receives events hit-tested to its view and any of that view's subviews
   the view the gesture is attached to. set by adding the recognizer to a NSView using the addGestureRecognizer: method
*/
@property (readonly) NSView *view;

/*  causes the specified events to be delivered to the target view only after this gesture has failed recognition. set to YES to prevent views from processing any events that may be recognized as part of this gesture. note: once a gesture recognizer starts delaying one type of event, all event types are delayed until this gesture has failed recognition. refer to specific gesture subclasses as they have different defaults.
*/
@property BOOL delaysPrimaryMouseButtonEvents;      // default is NO.
@property BOOL delaysSecondaryMouseButtonEvents;    // default is NO.
@property BOOL delaysOtherMouseButtonEvents;        // default is NO.
@property BOOL delaysKeyEvents;                     // default is NO.
@property BOOL delaysMagnificationEvents;           // default is NO.
@property BOOL delaysRotationEvents;                // default is NO.

/* individual NSGestureRecognizer subclasses may provide subclass-specific location information. see individual subclasses for details */
- (NSPoint)locationInView:(NSView*)view;

@end


@protocol NSGestureRecognizerDelegate <NSObject>
@optional
/* called when a gesture recognizer attempts to transition out of NSGestureRecognizerStatePossible. returning NO causes it to transition to NSGestureRecognizerStateFailed */
- (BOOL)gestureRecognizerShouldBegin:(NSGestureRecognizer *)gestureRecognizer;

/* called when the recognition of one of gestureRecognizer or otherGestureRecognizer would be blocked by the other
   return YES to allow both to recognize simultaneously. the default implementation returns NO (by default no two gestures can be recognized simultaneously)

   note: returning YES is guaranteed to allow simultaneous recognition. returning NO is not guaranteed to prevent simultaneous recognition, as the other gesture's delegate may return YES
*/
- (BOOL)gestureRecognizer:(NSGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(NSGestureRecognizer *)otherGestureRecognizer;

/* called once per attempt to recognize, so failure requirements can be determined lazily and may be set up between recognizers across view hierarchies
   return YES to set up a dynamic failure requirement between gestureRecognizer and otherGestureRecognizer

   note: returning YES is guaranteed to set up the failure requirement. returning NO does not guarantee that there will not be a failure requirement as the other gesture's counterpart delegate or subclass methods may return YES
*/
- (BOOL)gestureRecognizer:(NSGestureRecognizer *)gestureRecognizer shouldRequireFailureOfGestureRecognizer:(NSGestureRecognizer *)otherGestureRecognizer;
- (BOOL)gestureRecognizer:(NSGestureRecognizer *)gestureRecognizer shouldBeRequiredToFailByGestureRecognizer:(NSGestureRecognizer *)otherGestureRecognizer;

@end

// the extensions in this header are to be used only by subclasses of NSGestureRecognizer
// code that uses NSGestureRecognizers must never call these

@interface NSGestureRecognizer (NSSubclassUse)

// readonly for users of a gesture recognizer. may only be changed by direct subclasses of NSGestureRecognizer
@property NSGestureRecognizerState state;  // the current state of the gesture recognizer. can only be set by subclasses of NSGestureRecognizer, but can be read by consumers

// the following methods are to be overridden by subclasses of NSGestureRecognizer
// if you override one you must call super

// called automatically by the runtime after the gesture state has been set to NSGestureRecognizerStateEnded
// any internal state should be reset to prepare for a new attempt to recognize the gesture
// after this is received all remaining active touches will be ignored (no further updates will be received for touches that had already begun but haven't ended)
- (void)reset;

// same behavior as the equivalent delegate methods, but can be used by subclasses to define class-wide prevention rules
// for example, a NSTapGestureRecognizer never prevents another NSTapGestureRecognizer with a higher tap count
- (BOOL)canPreventGestureRecognizer:(NSGestureRecognizer *)preventedGestureRecognizer;
- (BOOL)canBePreventedByGestureRecognizer:(NSGestureRecognizer *)preventingGestureRecognizer;

// same behavior as the equivalent delegate methods, but can be used by subclasses to define class-wide failure requirements
- (BOOL)shouldRequireFailureOfGestureRecognizer:(NSGestureRecognizer *)otherGestureRecognizer;
- (BOOL)shouldBeRequiredToFailByGestureRecognizer:(NSGestureRecognizer *)otherGestureRecognizer;

// mirror of the event-delivery methods on NSResponder
// NSGestureRecognizers aren't in the responder chain, but observe events hit-tested to their view and their view's subviews
// NSGestureRecognizers receive events before the view to which the event was hit-tested
- (void)mouseDown:(NSEvent *)event;
- (void)rightMouseDown:(NSEvent *)event;
- (void)otherMouseDown:(NSEvent *)event;
- (void)mouseUp:(NSEvent *)event;
- (void)rightMouseUp:(NSEvent *)event;
- (void)otherMouseUp:(NSEvent *)event;
- (void)mouseDragged:(NSEvent *)event;
- (void)rightMouseDragged:(NSEvent *)event;
- (void)otherMouseDragged:(NSEvent *)event;
- (void)keyDown:(NSEvent *)event;
- (void)keyUp:(NSEvent *)event;
- (void)flagsChanged:(NSEvent *)event;
- (void)tabletPoint:(NSEvent *)event;
- (void)magnifyWithEvent:(NSEvent *)event;
- (void)rotateWithEvent:(NSEvent *)event;
- (void)pressureChangeWithEvent:(NSEvent *)event NS_AVAILABLE_MAC(10_10_3);

@end
