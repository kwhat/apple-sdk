#!/bin/sh
 
# Xcode 4.1 for Lion
# https://developer.apple.com/downloads/
7z x installxcode_41_lion.dmg
7z x -so "Install Xcode/InstallXcodeLion.pkg" | cpio -i -u
rm -Rf "Install Xcode"
mv "Applications/Install Xcode.app/Contents/Resources/Packages/MacOSX10.7.pkg" .
rm -Rf "Applications"
7z x -so MacOSX10.7.pkg | cpio -i -u
rm -f *.pkg

# Xcode 4.2 for Lion
# https://developer.apple.com/downloads/
7z x installxcode_421_lion.dmg
7z x -so "Install Xcode/InstallXcodeLion.pkg" | cpio -i -u
rm -Rf "Install Xcode"
mv "Applications/Install Xcode.app/Contents/Resources/Packages/MacOSX10.7.pkg" .
rm -Rf "Applications"
7z x -so MacOSX10.7.pkg | cpio -i -u
rm -f *.pkg

# Xcode 4.3 for Lion
# https://developer.apple.com/downloads/
7z x xcode_43_lion.dmg
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk ./SDKs/
rm -Rf Xcode

# Xcode 4.3.1 for Lion
# https://developer.apple.com/downloads/
7z x xcode_431_lion.dmg
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk ./SDKs/
rm -Rf Xcode

# Xcode 4.3.2 for Lion
# https://developer.apple.com/downloads/
7z x xcode_432_lion.dmg
7z x -so "Install Xcode/InstallXcodeLion.pkg" | cpio -i -u
rm -Rf "Install Xcode"
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk ./SDKs/
rm -Rf Xcode

# Xcode 4.4
# https://developer.apple.com/downloads/
7z x xcode446938108a.dmg
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk ./SDKs/
rm -Rf Xcode

# Xcode 4.4.1
# https://developer.apple.com/downloads/
7z x xcode_4.4.1_6938145.dmg
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk ./SDKs/
rm -Rf Xcode

# Xcode 4.5
# https://developer.apple.com/downloads/
7z x xcode_4.5.dmg
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk ./SDKs/
rm -Rf Xcode

# Xcode 4.5.1
# https://developer.apple.com/downloads/
7z x xcode4510417539a.dmg
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk ./SDKs/
rm -Rf Xcode

# Xcode 4.5.2
# https://developer.apple.com/downloads/
7z x xcode4520418508a.dmg
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk ./SDKs/
rm -Rf Xcode

# Xcode 4.6
# https://developer.apple.com/downloads/
7z x xcode460417218a.dmg
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk ./SDKs/
rm -Rf Xcode

# Xcode 4.6.1
# https://developer.apple.com/downloads/
7z x xcode4610419628a.dmg
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk ./SDKs/
rm -Rf Xcode

# Xcode 4.6.2
# https://developer.apple.com/downloads/
7z x xcode4620419895a.dmg
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk ./SDKs/
rm -Rf Xcode

# FIXME
find . -type l -exec sh -c "file -b {} | grep -q ^broken" \; -print
