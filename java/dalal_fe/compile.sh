export PATH=$PATH:/d/dalal/thisiscool-gcc/swt/win32/3218:/d/dalal/thisiscool-gcc/gcc-4.3/bin
i686-pc-mingw32-gcj -c -fjni -s --classpath=./classes:.:/d/dalal/thisiscool-gcc/swt/win32/3218/swt.jar *.java  -L /d/dalal/thisiscool-gcc/swt/win32/3218
i686-pc-mingw32-gcj -s --main=Applicationt -s --classpath=./classes:.:/d/dalal/thisiscool-gcc/swt/win32/3218/swt.jar -o DalalStreet.exe *.o  -L /c/thisiscool-gcc/swt/win32/3218 -Wl,--whole-archive -Wl,--no-whole-archive -lswt -lswtimgloader -mwindows
