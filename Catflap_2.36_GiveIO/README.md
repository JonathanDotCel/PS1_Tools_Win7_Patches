
# Catflap 2.36

Patched to work with GiveIO under Win7

Tiny patch at 0x1C188 to switch the driver from \\.\CatFlap to \\.\giveio.
That's it.

For those who prefer InpOut32, there's aso Orion's version here:
http://www.psxdev.net/forum/viewtopic.php?f=60&t=226

# Instructions

-Unzip to same directory as CatFlap (preferably)
-Copy giveio.sys to \windows\system32\drivers\giveio.sys
-run loaddrv.exe
-add giveio.sys to the end of the path
(i.e. c:\windows\system32\drivers\giveio.sys )
-hit install
-hit start

# Credits

1998-2000, Intar Technologies

Patched 10/8/2015:
-Switch from the CatFlap driver to giveio.

GiveIO from:
http://www.cs.ucr.edu/~eblock/db/downloads/giveio.zip

