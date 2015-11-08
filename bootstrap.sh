#!/bin/sh
 
# Xcode Tools 2.2.1
# https://developer.apple.com/downloads/
7z x xcode_2.2.1_8g1165_018213632.dmg
gzip -cd "Xcode Tools/Packages/MacOSX10.3.9.pkg/Contents/Archive.pax.gz" | pax -r -u
rm -Rf "Xcode Tools"
mv Developer/SDKs .
rm -Rf Developer

# Xcode 2.3
# https://developer.apple.com/downloads/
7z x xcode_2.3_8m1780_oz693620813.dmg
gzip -cd "Xcode Tools/Packages/MacOSX10.3.9.pkg/Contents/Archive.pax.gz" | pax -r -u
rm -Rf "Xcode Tools"
cp -Rf Developer/SDKs/* ./SDKs/
rm -Rf Developer

# Xcode 2.4
# https://developer.apple.com/downloads/
7z x xcode_2.4_8k1079_6936199.dmg
gzip -cd "Xcode Tools/Packages/MacOSX10.3.9.pkg/Contents/Archive.pax.gz" | pax -r -u
rm -Rf "Xcode Tools"
# FIXME
rm -Rf ./SDKs/MacOSX10.3.9.sdk/usr/include/c++/4.0.0 
cp -Rf Developer/SDKs/* ./SDKs/
rm -Rf Developer

# Xcode 2.4.1
# https://developer.apple.com/downloads/
7z x xcode_2.4.1_8m1910_6936315.dmg
gzip -cd "Xcode Tools/Packages/MacOSX10.3.9.pkg/Contents/Archive.pax.gz" | pax -r -u
rm -Rf "Xcode Tools"
cp -Rf Developer/SDKs/* ./SDKs/
rm -Rf Developer

# Xcode 2.5 Developer Tools
# https://developer.apple.com/downloads/
7z x xcode25_8m2558_developerdvd.dmg
gzip -cd "Xcode Tools/Packages/Packages/MacOSX10.3.9.pkg/Contents/Archive.pax.gz" | pax -r -u
rm -Rf "Xcode Tools"

# Xcode 3.0
# https://developer.apple.com/downloads/
7z x xcode_3.0.dmg 
mv "Xcode Tools/Packages/MacOSX10.3.9.pkg" .
rm -Rf "Xcode Tools"
7z x -so MacOSX10.3.9.pkg | cpio -i -u
rm -f *.pkg

# Xcode 3.1 Developer Tools
# https://developer.apple.com/downloads/
7z x xcode31_2199_developerdvd.dmg
mv "Xcode Tools/Packages/MacOSX10.3.9.pkg" .
rm -Rf "Xcode Tools"
7z x -so MacOSX10.3.9.pkg | cpio -i -u
rm -f *.pkg

# Xcode 3.1.1 Developer Tools
# https://developer.apple.com/downloads/
7z x xcode311_9m2517_developerdvd.dmg
mv "Xcode Tools/Packages/MacOSX10.3.9.pkg" .
rm -Rf "Xcode Tools"
7z x -so MacOSX10.3.9.pkg | cpio -i -u
rm -f *.pkg

# Xcode 3.1.2 Developer Tools
# https://developer.apple.com/downloads/
7z x xcode312_2621_developerdvd.dmg
mv "Xcode Tools/Packages/MacOSX10.3.9.pkg" .
rm -Rf "Xcode Tools"
7z x -so MacOSX10.3.9.pkg | cpio -i -u
rm -f *.pkg

# Xcode 3.1.3 Developer Tools
# https://developer.apple.com/downloads/
7z x xcode313_2736_developerdvd.dmg
mv "Xcode Tools/Packages/MacOSX10.3.9.pkg" .
rm -Rf "Xcode Tools"
7z x -so MacOSX10.3.9.pkg | cpio -i -u
rm -f *.pkg

# Xcode 3.1.4 Developer Tools
# https://developer.apple.com/downloads/
7z x xcode314_2809_developerdvd.dmg
mv "Xcode Tools/Packages/MacOSX10.3.9.pkg" .
rm -Rf "Xcode Tools"
7z x -so MacOSX10.3.9.pkg | cpio -i -u
rm -f *.pkg
