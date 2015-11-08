#!/bin/sh

mkdir ./SDKs/

# Xcode 4.4
# https://developer.apple.com/downloads/
7z x xcode446938108a.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk ./SDKs/
rm -Rf Xcode

# Xcode 4.4.1
# https://developer.apple.com/downloads/
7z x xcode_4.4.1_6938145.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk ./SDKs/
rm -Rf Xcode

# Xcode 4.5
# https://developer.apple.com/downloads/
7z x xcode_4.5.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk ./SDKs/
rm -Rf Xcode

# Xcode 4.5.1
# https://developer.apple.com/downloads/
7z x xcode4510417539a.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk ./SDKs/
rm -Rf Xcode

# Xcode 4.5.2
# https://developer.apple.com/downloads/
7z x xcode4520418508a.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk ./SDKs/
rm -Rf Xcode

# Xcode 4.6
# https://developer.apple.com/downloads/
7z x xcode460417218a.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk ./SDKs/
rm -Rf Xcode

# Xcode 4.6.1
# https://developer.apple.com/downloads/
7z x xcode4610419628a.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk ./SDKs/
rm -Rf Xcode

# Xcode 4.6.2
# https://developer.apple.com/downloads/
7z x xcode4620419895a.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk ./SDKs/
rm -Rf Xcode

# Xcode 5.0.1
# https://developer.apple.com/downloads/
7z x xcode_5.0.1.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk ./SDKs/
rm -Rf Xcode

# Xcode 5.0.2
# https://developer.apple.com/downloads/
7z x xcode_5.0.2.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk ./SDKs/
rm -Rf Xcode

# Xcode 5.1
# https://developer.apple.com/downloads/
7z x xcode_5.1.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk ./SDKs/
rm -Rf Xcode

# Xcode 5.1.1
# https://developer.apple.com/downloads/
7z x xcode_5.1.1.dmg Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk ./SDKs/
rm -Rf Xcode

# FIXME
find . -type l -exec sh -c "file -b {} | grep -q ^broken" \; -print
