
# XLink95 Patches
region free, aftermarket fixes &  Windows NT patch
Jan 2016, repackaged Dec 2020.
  
There are two patched binaries; one auto loads GiveIO to work under Windows NT, the other remains compatible with Win9X.

# Extra fixes:

Both versions also include

- Fixed a bug which would reset ports 0x378 & 0x37A to 0x00 and 0x02
- Deprotected to allow addresses like 0x1F800000, 0x1F000000 and 0xBFC00000
- Allows flashing non-FX roms onto FX carts, etc.
- Removed ROM flashing region protection

# Instructions:

- Copy giveio.sys to \windows\system32\drivers\giveio.sys
- Run loaddrv.exe
- Add giveio.sys to the end of the path
(i.e. c:\windows\system32\drivers\giveio.sys )
- Hit Snstall
- Hit Start

Next time you need to use it, you can hit "Start" in LoadDrv 
first or run "net start giveio" from the command prompt, 
run dialogue, etc.

# Notes:
- Only tested on 0x378
- XPlorer FX rom seems to work better than regular, V2, Pro, etc.


