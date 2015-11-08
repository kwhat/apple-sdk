#!/bin/sh

mkdir ./SDKs/

# Xcode 6.1
# https://developer.apple.com/downloads/
7z x 56841_xcode_6.1.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk ./SDKs/
rm -Rf Xcode

# Xcode 6.1.1
# https://developer.apple.com/downloads/
7z x xcode_6.1.1.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk ./SDKs/
rm -Rf Xcode

# Xcode 6.2
# https://developer.apple.com/downloads/
7z x Xcode_6.2.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk ./SDKs/
rm -Rf Xcode

# Xcode 6.3
# https://developer.apple.com/downloads/
7z x Xcode_6.3.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk ./SDKs/
rm -Rf Xcode

# Xcode 6.3.1
# https://developer.apple.com/downloads/
7z x Xcode_6.3.1.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk ./SDKs/
rm -Rf Xcode

# Xcode 6.3.2
# https://developer.apple.com/downloads/
7z x Xcode_6.3.2.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk ./SDKs/
rm -Rf Xcode

# Xcode 6.4
# https://developer.apple.com/downloads/
7z x Xcode_6.4.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk ./SDKs/
rm -Rf Xcode

# Look for missing symlinks
find . -type l -exec sh -c "file -b {} | grep -q ^broken" \; -print
