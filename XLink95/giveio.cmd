@echo off
if _%1_ == __ goto Recurse
echo.
echo Firing up GiveIO Driver.
net stop giveio >nul 2>nul
net start giveio >nul
if ERRORLEVEL 1 goto Problem
echo q > %SystemDrive%\q.txt
debug \\.\giveio <%SystemDrive%\q.txt 2>nul >nul
del %SystemDrive%\q.txt
if not _%1_ == __HACK__ goto Exec
title "*** You may now start Caetla-Tools from this window ***"
echo You may now start Caetla-Tools from this shell.
goto End
:Exec
echo Executing the command: %1 %2 %3 %4 %5 %6 %7 %8 %9
echo.
%1 %2 %3 %4 %5 %6 %7 %8 %9
goto End
:Recurse
start %0 _HACK_
goto End
:Problem
echo.
echo ERROR: Could not start the giveio service!
echo ERROR: Make sure it is installed ok.
echo.
:End
