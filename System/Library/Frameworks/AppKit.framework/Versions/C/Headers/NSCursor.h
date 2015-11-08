/*
	NSCursor.h
	Application Kit
	Copyright (c) 1994-2001, Apple Computer, Inc.
	All rights reserved.
*/

#import <Foundation/NSObject.h>
#import <Foundation/NSGeometry.h>

@class NSColor, NSEvent, NSImage;

@interface NSCursor : NSObject <NSCoding> {
    /*All instance variables are private*/
    NSPoint _hotSpot;
    struct _cursorFlags {
	unsigned int onMouseExited:1;
	unsigned int onMouseEntered:1;
	unsigned int :30;
    } _flags;
    id _image;
#ifdef WIN32
    void *_windowsCursor;
#endif
}

+ (NSCursor *)currentCursor;
+ (NSCursor *)arrowCursor;
+ (NSCursor *)IBeamCursor;

- (id)initWithImage:(NSImage *)newImage hotSpot:(NSPoint)aPoint;
- (id)initWithImage:(NSImage *)newImage	foregroundColorHint:(NSColor *)fg backgroundColorHint:(NSColor *)bg hotSpot:(NSPoint)hotSpot;

+ (void)hide;
+ (void)unhide;
+ (void)setHiddenUntilMouseMoves:(BOOL)flag;
+ (void)pop;

- (NSImage *)image;
- (NSPoint)hotSpot;
- (void)push;
- (void)pop;
- (void)set;
- (void)setOnMouseExited:(BOOL)flag;
- (void)setOnMouseEntered:(BOOL)flag;
- (BOOL)isSetOnMouseExited;
- (BOOL)isSetOnMouseEntered;
- (void)mouseEntered:(NSEvent *)theEvent;
- (void)mouseExited:(NSEvent *)theEvent;

@end
