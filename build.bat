@echo off
cd bin

set "archivo=Terra.exe"

color 0b
echo The compilation process takes time depending on the speed of your computer.
echo
echo
call :CompileCPPProyect

if exist %archivo% (
    color 02
    echo File compiled successfully by running it.
    Terra
    pause
) else (
    color 04
    echo Error during compilation file does not exist.
    pause
)

:CompileCPPProyect
mingw32-make