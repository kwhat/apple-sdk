/*
        NSSpellProtocol.h
        Application Kit
        Copyright (c) 1990-2009, Apple Inc.
        All rights reserved.
*/

#import <Foundation/NSObject.h>

/*
SpellCheckable objects can respond to this method if they want to support not only spell-checking, but spell correction.  This message is sent down the responder chain.  The receiver should ask the sender for its selectedCell's stringValue (the correct spelling of the word) and replace its selection if appropriate.
*/
 
@protocol NSChangeSpelling
- (void)changeSpelling:(id)sender;
@end

/*
SpellCheckable objects can respond to this method if they wish to be able to ignore words.  This message is sent down the responder chain.  To enable ignoring you should implement this method like this: [[NSSpellChecker sharedSpellChecker] ignoreWord:[sender stringValue] inSpellDocumentWithTag:<document tag>].  Each document in your app which can be spell checked should have a unique tag.  This tag is used here to tell the spell checker what document to ignore the word in, and you also pass it as an argument to the checkSpellingOfString:... method when you initiate a spell check.  Unique tags can be generated by the NSSpellChecker factory with the +uniqueSpellDocumentTag method.
*/

@protocol NSIgnoreMisspelledWords
- (void)ignoreSpelling:(id)sender;
@end
