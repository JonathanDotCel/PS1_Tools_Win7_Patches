
# XKiller 0.56 patches

Big love to Tim S for XKiller and XFlash
patches ~july 2013, sickle

Just a little patch to disable the "This ROM is too big message" when attempting
to upload 512k ROMs to the Xplorer FX. (Also, the "Author doesn't have this" box).

Note, always remember to go to settings and turn off the "Caetla" setting before 
attempting to flash with the XFlash CD!


# Original Readme

 Last changed on 03-10-1999 (X-Killer 0.56)
 
 Thank you for downloading this program :)

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 WHAT CAN YOU DO WITH X-KILLER THAT YOU CAN'T DO WITH X-LINK ?
 -------------------------------------------------------------

 * ROM - no territory check when upgrading the ROM
       - upgrade with AR/GS/Caetla ROM's (requires X-Flash CD)
       - encrypt and decrypt ROM files
       - backup ROM without having to upgrade it
       - information about FCD ROM files without having to upgrade
       - limited support for Caetla 0.34 ROM (download/upload/flash)
       
 * CODES - extract xcheats.txt file from ROM files
         - encrypt and encrypt codes (2 different enc/dec methods)
       
 * MEMORY EDITOR - no restrictions on viewing and downloading memory (Xplorer ROM / PSX BIOS)

 * MEMCARD MANAGER - dump and upload memorycards (= raw data)

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 COMPATIBILITY TEST FOR X-KILLER REGARDING XPLORER ROM'S
 -------------------------------------------------------

 " + " = it is supposed to work :)
 " ~ " = it works but not on all ROM's
 " - " = it doesn't work (yet)
 " ? " = I don't know if it works or not
 1 = 1.x ROM (V1)
 2 = 2.x ROM (V2/PRO)
 3 = 3.x ROM (V3/PRO/FX)
 4 = X-Flash v0.1
 5 = X-Flash v1.0
 6 = Caetla 0.34

 ******************************************************
 | Function                   | 1 | 2 | 3 | 4 | 5 | 6 |
 ******************************************************
 | PSX - Reset                | + | + | + | ? | + | - |
 |       Freeze               | + | + | + | - | - | - |
 |       Unfreeze             | + | + | + | - | - | - |
 |       Video mode           | - | - | + | - | - | - |
 | CODES - Backup             | + | + | + | - | + | - |
 | OTHER - Upload PSX-EXE     | - | ~ | ~ | - | + | - |
 |         Jump               | + | + | + | - | - | - |
 |         Speed Test         | + | + | + | + | + | + |
 |         Grab screen        | ? | + | - | - | - | - |
 |         Dump               | - | - | + | - | - | - |
 | MEMORY EDITOR              | + | + | + | - | + | + |
 | MEMCARD MANAGER            | + | + | + | - | - | - |
 | ROM Manager                | + | + | + | + | + | + |
 ******************************************************

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 QUICK EXPLANATION
 -----------------

 SETTINGS
   General 
     Lpt Port : address of the LPT port
     Timeout  : time after which you get a timeout dialog if a timeout occurs
     Memory : amount of memory to reserve for X-Killer (only needed when dumping N64 games)
     Transfer warnings : displays a message when a data transfer is corrupted
   Memory Editor
     Jump : absolute jump (relative to address 0)
            relative jump (relative to the begin address of the selected memory region)
   ROM
     Caetla 0.34 : enable it if your Xplorer contains the Caetla 0.34 ROM
   Upload EXE
     Force X-Run : always use X-Run when uploading & executing a psx-exe file

 TOOLS
   PSX
     RESET : resets the PSX
     FREEZE : freezes the PSX
     UNFREEZE : unfreezes the PSX
     VIDEO MODE : changes video mode to PAL/NTSC
   CODES
     BACKUP : downloads the codes from the cartridge to the PC
     ENCRYPT/DECRYPT : Code format must be "xxxxxxxx xxxx" or "xxxxxxxxxxxx"
                       You can also enc/dec only the last 2 or 4 bytes of a code, by placing
                       those bytes (or sequence of bytes) between an "<" and ">" character
   OTHER
     UPLOAD PSX-EXE : sends a Playstation EXE file to the Xplorer and executes it
     JUMP : PSX jumps to the specified address
     SPEED TEST : tests data transfer speed of download and upload functions
     GRAB SCREEN : downloads the Playstation screen to the PC
     DUMP
       GPU : dumps the GPU
       SPU : dumps the SPU
   MEMORY EDITOR
     [dump] : downloads the current memory region
     [jump] : shows to the specified memory address (has to be in the current memory region)
     [download] : downloads selected memory (address + length)
     [upload] : uploads a file to the selected memory
   MEMCARD MANAGER
     [refresh] : refreshes both memory cards
     [dump] : dumps a memorycard
     [upload] : uploads a memorycard image
   ROM MANAGER
     [detect] : detects cartridge
     [upgrade] : upgrades ROM
     [backup] : backups ROM
     [encrypt] : encrypts a ROM file
     [decrypt] : decrypts a ROM file
     [extract codes] : extract codes from a ROM file

 VIEW
   LOG
     Views the X-Killer log to see what happened when

 HELP
   INFORMATION
     Information about X-Killer (this file)
   ABOUT X-KILLER
     Credits

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 HISTORY :
 ---------

 v0.56 - * Fixed : when changing PAL<->NTSC using X-Killer, Xplorer can be killed

 v0.55 - * Added : ROM Manager
                   Support for X-Flash 1.0
                   Dump GPU (3.x ROM only)
                   Video mode (PAL/NTSC) switch (3.x ROM only)
                   Minimize button
                   "Force X-Run" option
                   "Memory" option
                   Automatic ROM recognition (46 PSX FCD ROM's are known)
         * Removed : "X2 Protocol" option

 v0.50 - * Added : Upload memcard image
                   Upload psx-exe's on Xplorer FX
                   "Dump SPU" function
         * Fixed : 101 bugs :)
         * Removed : many options and the minimize button :((
                     "REPAIR" function, "UPGRADE" should work 100% with X-Flash v0.1

 v0.47 - * Added : Missing file required to upgrade XP + caetla 0.34 ROM
                   "REPAIR" function to make ROM upgrades compatible again with X-Flash CD
         * Fixed : Upgrade cancel bug
                   SPEED TEST and V3/FX upload problem

 v0.45 - * SETTINGS - Added : Caetla 0.34 support
         * SPEED TEST - Added
         * MEMCARD MANAGER - Fixed : Bug with 2nd memorycard slot
         * VALIDATE UPGRADE - Fixed : False errors (only full 128-byte blocks will be reported)
         * Other small corrections I can't remember (security/bugs/...)

 v0.39 - * SETTINGS - Added : Validate upgrade
                      Added : Transfer warnings
         * ROM BACKUP - Added : Support for V3 ROM's
         *     DETECT - Added : Display flashrom size (256KB/384KB)
         * PSX UPLOAD EXE - Fixed : 2 stupid bugs which prevented it to work at all

 v0.35 - * CODES DOWNLOAD - Added : Support for FX cartridges
	 * CODES EXTRACT FROM FILE - Added : Support for FX ROM files
         * MEMCARD MANAGER - Fixed : Repeating "[01]" instead of 1-15
                             Fixed : Filesize only 1024 bytes when dumping a memorycard
         * Fixed : Stupid bug regarding 1.x ROM's

 v0.30 - * CODES ENC/DEC - Added : New encryption/decryption routine added (eat this FCD!!)
         * MEMORY EDITOR - Fixed : "prefix" problem ("&" symbol)
                           Fixed : Redraw background to prevent "empty" screen
                           Added : Dump function added (downloads current memory region)
         * Added : Show information about selected ROM file in "open" and "save as" dialog boxes

 v0.26 - * Fix for NT users, X-Killer will work perfectly after "giveio.sys" has been installed

 v0.25 - * CODES ENC/DEC : Ability to enc/dec only the last 2 or 4 bytes of a code
                           They have to be placed between an "<" and ">" character
                           Example : ".... < 00 01 0002 0920 > ...."
                           [feature requested by Snakebite]
         * CODES : "Extract From File" added (doesn't work with FX ROM's)
         * ROM : "Detect" added which reads version/date/language of Xplorer (FX)
         * PSX : "Xplorer Status" removed
         * HELP : "Information" added
         * Main title problem fixed (empty dialog + number)
         * Registry bug on NT systems fixed
                          
 v0.20 - * MEMORY EDITOR : More memory regions
         * MEMORY EDITOR : Download function works
         * SETTINGS :  Enable/disable startup I/O
         * ROM : Support for Xplorer FX (backup, encrypt and decrypt)

 v0.12 - * ROM UPGRADE : Support for incompatible ROM's (ar/gs/caetla)
                         !! X-Flash CD is required !!
         * Faster data transfer on older PC's (XP->PC)

 v0.10 - * First release of X-Killer

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 EXISTING ROM'S
 --------------

 << PLEASE CHECK MY HOMEPAGE FOR AN UP-TO-DATE ROMLIST >>

 Any other ROM's would be greatly appreciated :)
 Before e-mailing any ROM's, please contact me as I may already have it
 !! X-Killer 0.55 automaticly detects if you have a ROM that I might not have !!

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 ABREVIATIONS USED
 -----------------

 XP  : Xplorer
 PSX : Playstation
 AR  : Action Replay (Datel's Xplorer for Europe)
 GS  : GameShark (Datel's Xplorer for America)

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 HOW TO CONTACT ME ?
 -------------------

 E-Mail  : Tim.Schuerewegen@village.uunet.be
 Web     : http://www.cherryroms.com/firefly
           http://gallery.uunet.be/Tim.Schuerewegen
           http://members.xoom.com/Schuerewegen
 eGroup  : http://www.egroups.com/list/x-killer
 Tel     : (032) 03/646.98.35

 If you want to give me money, an Xplorer FX or something else, then send it to :
  
  ********************
  * Tim Schuerewegen *
  * du Chastellei 5  *
  * 2170 Merksem     *
  * BELGIUM          *
  ********************

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 SPECIAL THANKS TO
 -----------------
 
 Snakebite, Hackman, Avid Gamer, Murray Moffatt, Dave Wallace - for sending me ROM's
 Neal, Melonhead - for beta-testing X-Flash
 Blaze / FCD - for sending me an Xplorer FX (for free)

 Did I forget you ? Send me an e-mail !

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 Thank you for reading this document and I hope you will enjoy X-Killer

 Logging off .......
