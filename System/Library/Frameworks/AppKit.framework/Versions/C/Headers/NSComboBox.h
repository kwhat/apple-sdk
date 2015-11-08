/*
	NSComboBox.h
	Application Kit
	Copyright (c) 1996-2007, Apple Inc.
	All rights reserved.
*/

#import <AppKit/NSTextField.h>

APPKIT_EXTERN NSString *NSComboBoxWillPopUpNotification;
APPKIT_EXTERN NSString *NSComboBoxWillDismissNotification;
APPKIT_EXTERN NSString *NSComboBoxSelectionDidChangeNotification;
APPKIT_EXTERN NSString *NSComboBoxSelectionIsChangingNotification;

@interface NSComboBox : NSTextField {
    /*All instance variables are private*/
    id _dataSource;
}

- (BOOL)hasVerticalScroller;
- (void)setHasVerticalScroller:(BOOL)flag;
- (NSSize)intercellSpacing;
- (void)setIntercellSpacing:(NSSize)aSize;
- (CGFloat)itemHeight;
- (void)setItemHeight:(CGFloat)itemHeight;
- (NSInteger)numberOfVisibleItems;
- (void)setNumberOfVisibleItems:(NSInteger)visibleItems;

#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_3
- (void)setButtonBordered:(BOOL)flag;
- (BOOL)isButtonBordered;
#endif

- (void)reloadData;
- (void)noteNumberOfItemsChanged;

- (void)setUsesDataSource:(BOOL)flag;
- (BOOL)usesDataSource;

- (void)scrollItemAtIndexToTop:(NSInteger)index;
- (void)scrollItemAtIndexToVisible:(NSInteger)index;

- (void)selectItemAtIndex:(NSInteger)index;
- (void)deselectItemAtIndex:(NSInteger)index;
- (NSInteger)indexOfSelectedItem;
- (NSInteger)numberOfItems;

- (BOOL)completes;
- (void)setCompletes:(BOOL)completes;

/* These two methods can only be used when usesDataSource is YES */
- (id)dataSource;
- (void)setDataSource:(id)aSource;

/* These methods can only be used when usesDataSource is NO */
- (void)addItemWithObjectValue:(id)object;
- (void)addItemsWithObjectValues:(NSArray *)objects;
- (void)insertItemWithObjectValue:(id)object atIndex:(NSInteger)index;
- (void)removeItemWithObjectValue:(id)object;
- (void)removeItemAtIndex:(NSInteger)index;
- (void)removeAllItems;
- (void)selectItemWithObjectValue:(id)object;
- (id)itemObjectValueAtIndex:(NSInteger)index;
- (id)objectValueOfSelectedItem;
- (NSInteger)indexOfItemWithObjectValue:(id)object;
- (NSArray *)objectValues;

@end

@interface NSObject (NSComboBoxDataSource)
- (NSInteger)numberOfItemsInComboBox:(NSComboBox *)aComboBox;
- (id)comboBox:(NSComboBox *)aComboBox objectValueForItemAtIndex:(NSInteger)index;
- (NSUInteger)comboBox:(NSComboBox *)aComboBox indexOfItemWithStringValue:(NSString *)string;
- (NSString *)comboBox:(NSComboBox *)aComboBox completedString:(NSString *)string;
@end

@interface NSObject (NSComboBoxNotifications)
- (void)comboBoxWillPopUp:(NSNotification *)notification;
- (void)comboBoxWillDismiss:(NSNotification *)notification;
- (void)comboBoxSelectionDidChange:(NSNotification *)notification;
- (void)comboBoxSelectionIsChanging:(NSNotification *)notification;
@end
