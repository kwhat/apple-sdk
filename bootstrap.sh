#!/bin/sh
 
# Xcode 3.2
# https://developer.apple.com/downloads/
7z x xcode3210a432.dmg
mv Xcode/Packages/MacOSX10.6.pkg .
rm -Rf Xcode
7z x -so MacOSX10.6.pkg | cpio -i -u
rm -f *.pkg

# Xcode 3.2.1 Developer Tools
# https://developer.apple.com/downloads/
7z x xcode321_10m2003_developerdvd.dmg
mv Xcode/Packages/MacOSX10.6.pkg .
rm -Rf Xcode
7z x -so MacOSX10.6.pkg | cpio -i -u
rm -f *.pkg

# Xcode 3.2.2 Developer Tools
# https://developer.apple.com/downloads/
7z x xcode322_2148_developerdvd.dmg
mv Xcode/Packages/MacOSX10.6.pkg .
rm -Rf Xcode
7z x -so MacOSX10.6.pkg | cpio -i -u
rm -f *.pkg

# Xcode 3.2.3 and iOS SDK 4.0.1 or Xcode 3.2.3 and iOS SDK 4.0.2
# https://developer.apple.com/downloads/
7z x xcode_3.2.3_and_ios_sdk_4.0.?.dmg
mv "Xcode and iPhone SDK/Packages/MacOSX10.6.pkg" .
rm -Rf "Xcode and iPhone SDK"
7z x -so MacOSX10.6.pkg | cpio -i -u
rm -f *.pkg

# Xcode 3.2.4 and iOS SDK 4.1
# https://developer.apple.com/downloads/
7z x xcode_3.2.4_and_ios_sdk_4.1.dmg
mv "Xcode and iOS SDK/Packages/MacOSX10.6.pkg" .
rm -Rf "Xcode and iOS SDK"
7z x -so MacOSX10.6.pkg | cpio -i -u
rm -f *.pkg

# Xcode 3.2.5 and iOS SDK 4.2
# https://developer.apple.com/downloads/
7z x xcode_3.2.5_and_ios_sdk_4.2_final.dmg
mv "Xcode and iOS SDK/Packages/MacOSX10.6.pkg" .
rm -Rf "Xcode and iOS SDK"
7z x -so MacOSX10.6.pkg | cpio -i -u
rm -f *.pkg

# Xcode 4.1 for Lion
# https://developer.apple.com/downloads/
7z x installxcode_41_lion.dmg
7z x -so "Install Xcode/InstallXcodeLion.pkg" | cpio -i -u
rm -Rf "Install Xcode"
mv "Applications/Install Xcode.app/Contents/Resources/Packages/MacOSX10.6.pkg" .
rm -Rf "Applications"
7z x -so MacOSX10.6.pkg | cpio -i -u
rm -f *.pkg

# Xcode 4.2 for Lion
# https://developer.apple.com/downloads/
7z x installxcode_421_lion.dmg
7z x -so "Install Xcode/InstallXcodeLion.pkg" | cpio -i -u
rm -Rf "Install Xcode"
mv "Applications/Install Xcode.app/Contents/Resources/Packages/MacOSX10.6.pkg" .
rm -Rf "Applications"
7z x -so MacOSX10.6.pkg | cpio -i -u
rm -f *.pkg

# Xcode 4.3 for Lion
# https://developer.apple.com/downloads/
7z x xcode_43_lion.dmg
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.6.sdk ./SDKs/
rm -Rf Xcode

# Xcode 4.3.1 for Lion
# https://developer.apple.com/downloads/
7z x xcode_431_lion.dmg
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.6.sdk ./SDKs/
rm -Rf Xcode

# Xcode 4.3.2 for Lion
# https://developer.apple.com/downloads/
7z x xcode_432_lion.dmg
7z x -so "Install Xcode/InstallXcodeLion.pkg" | cpio -i -u
rm -Rf "Install Xcode"
cp -Rf Xcode/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.6.sdk ./SDKs/
rm -Rf Xcode

# FIXME
find . -type l -exec sh -c "file -b {} | grep -q ^broken" \; -print
