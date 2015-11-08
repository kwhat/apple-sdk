#!/bin/sh
 
# XCode 3.0
# https://developer.apple.com/downloads/
7z x xcode_3.0.dmg 
mv "Xcode Tools/Packages/MacOSX10.5.pkg" .
rm -Rf "Xcode Tools"
7z x -so MacOSX10.5.pkg | cpio -i -u
rm -f *.pkg

# XCode 3.1 Developer Tools
# https://developer.apple.com/downloads/
7z x xcode31_2199_developerdvd.dmg
mv "Xcode Tools/Packages/MacOSX10.5.pkg" .
rm -Rf "Xcode Tools"
7z x -so MacOSX10.5.pkg | cpio -i -u
rm -f *.pkg

# XCode 3.1.1 Developer Tools
# https://developer.apple.com/downloads/
7z x xcode311_9m2517_developerdvd.dmg
mv "Xcode Tools/Packages/MacOSX10.5.pkg" .
rm -Rf "Xcode Tools"
7z x -so MacOSX10.5.pkg | cpio -i -u
rm -f *.pkg

# XCode 3.1.2 Developer Tools
# https://developer.apple.com/downloads/
7z x xcode312_2621_developerdvd.dmg
mv "Xcode Tools/Packages/MacOSX10.5.pkg" .
rm -Rf "Xcode Tools"
7z x -so MacOSX10.5.pkg | cpio -i -u
rm -f *.pkg

# XCode 3.1.3 Developer Tools
# https://developer.apple.com/downloads/
7z x xcode313_2736_developerdvd.dmg
mv "Xcode Tools/Packages/MacOSX10.5.pkg" .
rm -Rf "Xcode Tools"
7z x -so MacOSX10.5.pkg | cpio -i -u
rm -f *.pkg

# XCode 3.1.4 Developer Tools
# https://developer.apple.com/downloads/
7z x xcode314_2809_developerdvd.dmg
mv "Xcode Tools/Packages/MacOSX10.5.pkg" .
rm -Rf "Xcode Tools"
7z x -so MacOSX10.5.pkg | cpio -i -u
rm -f *.pkg

# Xcode 3.2
# https://developer.apple.com/downloads/
7z x xcode3210a432.dmg
mv Xcode/Packages/MacOSX10.5.pkg .
rm -Rf Xcode
7z x -so MacOSX10.5.pkg | cpio -i -u
rm -f *.pkg

# Xcode 3.2.1 Developer Tools
# https://developer.apple.com/downloads/
7z x xcode321_10m2003_developerdvd.dmg
mv Xcode/Packages/MacOSX10.5.pkg .
rm -Rf Xcode
7z x -so MacOSX10.5.pkg | cpio -i -u
rm -f *.pkg

# Xcode 3.2.2 Developer Tools
# https://developer.apple.com/downloads/
7z x xcode322_2148_developerdvd.dmg
mv Xcode/Packages/MacOSX10.5.pkg .
rm -Rf Xcode
7z x -so MacOSX10.5.pkg | cpio -i -u
rm -f *.pkg

# Xcode 3.2.3 and iOS SDK 4.0.1 or Xcode 3.2.3 and iOS SDK 4.0.2
# https://developer.apple.com/downloads/
7z x xcode_3.2.3_and_ios_sdk_4.0.?.dmg
mv "Xcode and iPhone SDK/Packages/MacOSX10.5.pkg" .
rm -Rf "Xcode and iPhone SDK"
7z x -so MacOSX10.5.pkg | cpio -i -u
rm -f *.pkg

# Xcode 3.2.4 and iOS SDK 4.1
# https://developer.apple.com/downloads/
7z x xcode_3.2.4_and_ios_sdk_4.1.dmg
mv "Xcode and iOS SDK/Packages/MacOSX10.5.pkg" .
rm -Rf "Xcode and iOS SDK"
7z x -so MacOSX10.5.pkg | cpio -i -u
rm -f *.pkg

# Xcode 3.2.5 and iOS SDK 4.2
# https://developer.apple.com/downloads/
7z x xcode_3.2.5_and_ios_sdk_4.2_final.dmg
mv "Xcode and iOS SDK/Packages/MacOSX10.5.pkg" .
rm -Rf "Xcode and iOS SDK"
7z x -so MacOSX10.5.pkg | cpio -i -u
rm -f *.pkg
