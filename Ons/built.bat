@echo off
echo  Compiling resources...
windres resource.rc -o resource.o
echo  Building OnsiApp...
g++ main.cpp zikr.cpp resource.o -o OnsiApp.exe -mwindows -lwinmm
echo Run OnsiApp.exe
pause
