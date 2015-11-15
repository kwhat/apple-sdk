#!/bin/sh

mkdir ./SDKs/

# Xcode 7
# https://developer.apple.com/downloads/
7z x Xcode_7.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk ./SDKs/
rm -Rf Xcode

# Xcode 7.0.1
# https://developer.apple.com/downloads/
7z x Xcode_7.0.1.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk ./SDKs/
rm -Rf Xcode

# Xcode 7.1
# https://developer.apple.com/downloads/
7z x Xcode_7.1.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk ./SDKs/
rm -Rf Xcode

# Xcode 7.1.1
# https://developer.apple.com/downloads/
7z x Xcode_7.1.1.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk ./SDKs/
rm -Rf Xcode

# Look for missing symlinks
find . -type l -exec sh -c "file -b {} | grep -q ^broken" \; -print
