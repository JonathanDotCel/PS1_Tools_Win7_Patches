
#ifndef _CATFLAPDLL_H_
#define _CATFLAPDLL_H_

/*
===========================================================================
CatFlap DLL  (C) Copyright 1998-2000 Intar Technologies Limited
---------------------------------------------------------------------------
Support for Communication with Caetla ROM on PAR or XPlorer type Cartridges
for Sony PlayStation
===========================================================================
# Include file compatible with v2.31-v2.36 of CCaetla class


[1] #include "CatFlap.h"   (ie *this* file) in your application


[2] Load the DLL in the following way:

    HINSTANCE    dll=LoadLibrary("CatFlap");

Remember to check if the DLL handle is NULL, as this signifies an error in
loading the DLL.


[3] Find the address of the CatFlap DLL gateway function:

    CatFunc func=(CatFunc) GetProcAddress(dll,"CatFlap");


[4] Create an instance of the CatFlapS struct in your application:

    struct CatFlapS CF;


[5] Call a function by setting variables in the CatFlapS structure, and
    calling the gateway function:

    CF.iPort=0x310;
    CF.iCartType=CARTTYPE_PAR;
    func(&CF,CF_CMD_INIT);

    The gateway function always takes 2 arguments: a pointer to a CatFlapS
    structure; and the desired command to execute.

[6] When exiting your application, unload the DLL:

    FreeLibrary(dll);


---------------------------------------------------------------------------
Errorcodes from the DLL are stored in the iResult parameter of the CatFlapS
structure after execution. For the most part, it is safe to assume that a
result of zero means a successful execution, non-zero indicates an error.
---------------------------------------------------------------------------
2 Hookable functions are provided. The KeyHook is called from within the
console loop and enables the calling application to provide keycodes to the
console system. If specified, the TextHook function will receive a string
pointer to do with as it wishes - all text output will be passed to it. If
unspecified, all text output will go to stdout via printf().
---------------------------------------------------------------------------
*/


/*
COMMAND                     PARAMETERS
===========================================================================
CF_CMD_NOP                  -

                     Notes: -
---------------------------------------------------------------------------
CF_CMD_INIT                 iPort        == Port Address
                            iCartType    == Cartridge Type

                     Notes: Only needs to be called once at startup
---------------------------------------------------------------------------
CF_CMD_SETPORT              iPort        == Port Address

                     Notes: Can be used to dynamically alter comms address
---------------------------------------------------------------------------
CF_CMD_SETCARTTYPE          iCartType    == Cartridge Type

                     Notes: Can be used to dynamically alter cartridge type
---------------------------------------------------------------------------
CF_CMD_SETLOGFILE           pName        -> Logfile Name

                     Notes: Sets name of optional text logfile
                            * If used, call before CF_CMD_INIT
---------------------------------------------------------------------------
CF_CMD_SETTEXTHOOK          fpTextHook   -> Hookable Function

                     Notes: Set hook to your own pointer to receive text
                            output
---------------------------------------------------------------------------
CF_CMD_KEYHOOK              fpKeyHook    -> Hookable Function

                     Notes: Hook in your own function to feed keycodes to
                            the console
---------------------------------------------------------------------------
CF_CMD_SETKEYADDR           iAddress     == Target Address to send keycodes

                     Notes: -
---------------------------------------------------------------------------
CF_CMD_DETECT               -

                     Notes: Senses status of commlink and cartridge
---------------------------------------------------------------------------
CF_CMD_NTSTATUS             -

                     Notes: Returns non-zero if running on NT4 or Win2000
---------------------------------------------------------------------------
CF_CMD_IOSTATUS             -

                     Notes: Returns non-zero if I/O link status is up,
                            mostly of use to check NT4/2000 I/O driver.
                            Always non-zero on Win95/98.
---------------------------------------------------------------------------
CF_CMD_GETVERSION           -

                     Notes: Returns internal version of Caetla comms class
                            (MAJOR*100)+MINOR (eg 215 == v2.15)
---------------------------------------------------------------------------
CF_CMD_ENABLEINFOBARS       bBool        == true/false

                     Notes: Enables or disables progress bars on transfers
---------------------------------------------------------------------------
CF_CMD_RESUME               -

                     Notes: Returns control to the target. Many functions
                            cause the target to remain suspended under PC
                            control, use CF_CMD_RESUME to let the target
                            continue execution.
---------------------------------------------------------------------------

===========================================================================
The following commands are used to set Caetla into specific modes, the same
which appear on Caetla's on-screen menu.
---------------------------------------------------------------------------
CF_CMD_MODEQUERY            -

                     Notes: Check current Caetla mode
                            * bByte receives mode:
                                     0 - Main Menu
                                     1 - Memory Card Manager
                                     2 - VRAM Manager
                                     3 - <Reserved>
                                     4 - CD Manager
                                     5 - <Reserved>
                                     6 - Debug Mode
                            * Check iResult for any errorcode to determine
                              if bByte result is valid
---------------------------------------------------------------------------
CF_CMD_MODEMAIN             -

                     Notes: 'Listen' to target in Main Menu mode
---------------------------------------------------------------------------
CF_CMD_MODEMEMCARD          -

                     Notes: 'Listen' to target in Memory Card Manager mode
---------------------------------------------------------------------------
CF_CMD_MODEVRAM             -

                     Notes: 'Listen' to target in VRAM Manager mode
---------------------------------------------------------------------------
CF_CMD_MODECDMANAGER        -

                     Notes: 'Listen' to target in CD Manager mode
---------------------------------------------------------------------------
CF_CMD_MODEDEBUG            -

                     Notes: 'Listen' to target in Debug Mode
---------------------------------------------------------------------------

===========================================================================
CF_CMD_RESET                -

                     Notes: Reset the target
---------------------------------------------------------------------------
CF_CMD_RUNEXEFILE           pName        -> Filename
                            bBool        == Run Immediately (true/false)
                            bByte        == Enable Caetla Hook (true/false)

                     Notes: Execution by filename. Set bBool to non-zero to
                            enable immediate execution, otherwise execution
                            is queued until CF_CMD_INITCONSOLE is called.
                            Set bByte to non-zero to enable Caetla Hook on
                            execution.
                            * Resets target before transferring executable
---------------------------------------------------------------------------
CF_CMD_RUNEXE               pDataIn      -> File Data in RAM
                            bBool        == Run Immediately (true/false)
                            bByte        == Enable Caetla Hook (true/false)

                     Notes: Execution by filename. Set bBool to non-zero to
                            enable immediate execution, otherwise execution
                            is queued until CF_CMD_INITCONSOLE is called.
                            Set bByte to non-zero to enable Caetla Hook on
                            execution.
---------------------------------------------------------------------------
CF_CMD_SENDFILE             pName        -> Filename
                            iAddress     == Target Address

                     Notes: Send a file to target RAM
---------------------------------------------------------------------------
CF_CMD_SEND                 pDataIn      -> File Data in RAM
                            iAddress     == Target Address
                            iDataCount   == Transfer Size

                     Notes: Send data from RAM to target
---------------------------------------------------------------------------
CF_CMD_RECEIVEFILE          pName        -> Filename
                            iAddress     == Target Address
                            iDataCount   == Transfer Size

                     Notes: Receive data from target to RAM
---------------------------------------------------------------------------
CF_CMD_RECEIVE              pDataOut     -> Destination Data
                            iAddress     == Target Address
                            iDataCount   == Transfer Size

                     Notes: Receive data from target to file
---------------------------------------------------------------------------
CF_CMD_RECEIVEVRAM          pDataOut     -> Destination Data
                            iX/iY/iW/iH  == Rectangular region of VRAM
                            iDepth       == Destination bit-depth (16 or 24)

                     Notes: Receive VRAM from target to RAM
                            * Calls CF_CMD_MODEVRAM internally
---------------------------------------------------------------------------
CF_CMD_RECEIVEVRAMFILE      pName        -> Filename
                            iX/iY/iW/iH  == Rectangular region of VRAM
                            iDepth       == Output bit-depth (16 or 24)

                     Notes: Receive VRAM from target to file (specify name
                            "*.BMP" to output as .BMP format)
                            * Calls CF_CMD_MODEVRAM internally
--------------------------------------------------------------------------

===========================================================================
The console loop will handle all fileserver commands from Caetla during a
program's execution, and is also responsible for calling the Hookback for
keyboard input. A typical console loop would look like:

   func(&CF,CF_CMD_INITCONSOLE);
   while(!func(&CF,CF_CMD_CONSOLEQUITSTATUS))
       {
       func(&CF,CF_CMD_CALLCONSOLE);
       }
   func(&CF,CF_CMD_ENDCONSOLE);

This is, in fact, exactly what the CF_CMD_CONSOLELOOP function does.

The console periodically checks the commslink and will self-terminate if it
detects that the link is no longer valid.
An input of 0x1B (ESCAPE in ASCII) from the keyhook function will also
cause the console to self-terminate.
If running your own console loop be prepared for these possible events.
---------------------------------------------------------------------------
CF_CMD_INITCONSOLE          -

                     Notes: Call once to initiate a console loop. May start
                            execution of an executable (see CF_CMD_RUNEXE)
---------------------------------------------------------------------------
CF_CMD_CALLCONSOLE          -

                     Notes: Call repeatedly to handle a console loop. It is
                            within this function that the KeyHook hookable
                            function is called, along with all fileserver
                            functions
---------------------------------------------------------------------------
CF_CMD_ENDCONSOLE           -

                     Notes: Call once to terminate a console loop
---------------------------------------------------------------------------
CF_CMD_CONSOLEQUITSTATUS    -

                     Notes: Returns non-zero if the console wishes to be
                            terminated (occurs if ESCAPE keycode 0x1B is
                            fed to the console loop via the KeyHook)
---------------------------------------------------------------------------
CF_CMD_CONSOLELOOP          -

                     Notes: Self-contained 'blocking' Console Mode
---------------------------------------------------------------------------
CF_CMD_SETCONSOLEAUTOSENSE  bBool        == true/false

                     Notes: Enables or disables the periodic commlink
                            autosensing in console mode (on by default)
---------------------------------------------------------------------------

===========================================================================
Under Windows NT & Windows2000 direct hardware access to the comms ports
is not allowed, so CatFlap uses a kernel-mode driver to enable it to access
these ports. The driver is fully compatible with NT4 & Windows2000, and
only needs to be installed once, when a reboot is required to activate it.
---------------------------------------------------------------------------
CF_CMD_INSTALLNT            -

                     Notes: Installs kernel-mode I/O driver on NT4/Win2000
---------------------------------------------------------------------------
CF_CMD_UNINSTALLNT          -

                     Notes: Removes kernel-mode I/O driver on NT4/Win2000
---------------------------------------------------------------------------

===========================================================================
The following memory card functions are self-contained in that they will
automatically set Caetla to 'Listen' in Memory Card Manager mode.
---------------------------------------------------------------------------
CF_CMD_MEMCARDSYNC          iCardSlot    == Card Slot (0 or 1)

                     Notes: Checks memory card and retrieves information
                            * Call before any of the following memory card
                              functions
---------------------------------------------------------------------------
CF_CMD_MEMCARDLIST          iCardSlot    == Card Slot (0 or 1)

                     Notes: Lists memory card contents
---------------------------------------------------------------------------
CF_CMD_MEMCARDUP            pName        -> Savegame Filename
                            iCardSlot    == Card Slot (0 or 1)

                     Notes: Uploads savegame file to memory card
---------------------------------------------------------------------------
CF_CMD_MEMCARDDOWN          pName        -> Savegame Filename
                            iCardSlot    == Card Slot (0 or 1)
                            iCardFile    == Card File (0->15)

                     Notes: Downloads savegame from memory card to file
---------------------------------------------------------------------------
CF_CMD_MEMCARDBACKUP        pName        -> Backup Filename
                            iCardSlot    == Card Slot (0 or 1)

                     Notes: Backup whole memory card to file
---------------------------------------------------------------------------
CF_CMD_MEMCARDRESTORE       pName        -> Backup Filename
                            iCardSlot    == Card Slot (0 or 1)

                     Notes: Restore whole memory card from file
---------------------------------------------------------------------------
CF_CMD_MEMCARDDELETE        iCardSlot    == Card Slot (0 or 1)
                            iCardFile    == Card File (0->15)

                     Notes: Delete savegame from memory card
---------------------------------------------------------------------------
CF_CMD_MEMCARDFORMAT        iCardSlot    == Card Slot (0 or 1)

                     Notes: Format memory card
---------------------------------------------------------------------------

===========================================================================
Debug Mode functions require that Caetla be placed in Debug Mode with the
CF_CMD_MODEDEBUG command. Some of these functions only work correctly if
the target is already executing a program. CF_CMD_RESUME is required after
these commands, but need only be called once after all Debug Mode commands
have been issued.
---------------------------------------------------------------------------
CF_CMD_DBGUPDATEBYTE        iAddress     == Target address
                            bByte        == Byte Data

                     Notes: Store 8-bit Byte at address
                            * Only works during program execution
---------------------------------------------------------------------------
CF_CMD_DBGGETREGISTERS      pDataOut     == Buffer to receive registers
                                            (36 32-bit values)

                            * Register list:
                              00: at   01: v0   02: v1   03: a0
                              04: a1   05: a2   06: a3   07: t0
                              08: t1   09: t2   10: t3   11: t4
                              12: t5   13: t6   14: t7   15: s0
                              16: s1   17: s2   18: s3   19: s4
                              20: s5   21: s6   22: s7   23: t8
                              24: t9   25: k0   26: k1   27: gp
                              28: sp   29: fp   30: ra   31: epc
                              32: hi   33: lo   34: sr   35: cr

                     Notes: Retrieve R3000 registers in Debug Mode
                            * Only works during program execution
---------------------------------------------------------------------------
CF_CMD_DBGSETREGISTER       iWord        == 32-bit Data Value
                            iByte        == Register Number (as above)

                     Notes: Set a register value
                            * Only works during program execution
---------------------------------------------------------------------------
CF_CMD_DBGGETCPCOND         -

                     Notes: Get Cp Condition
                            * bByte == Bit 0:Cop0
                                       Bit 1:Cop1
                                       Bit 2:Cop2
                                       Bit 3:Cop3
                              0:True, 1:False
                            * Only works during program execution
---------------------------------------------------------------------------
CF_CMD_DBGFLUSHICACHE       -

                     Notes: Flushes the I-Cache
                            * Only works during program execution
---------------------------------------------------------------------------
CF_CMD_DBGSETHBP            HBP[0]       == BP Address
                            HBP[1]       == Watch Condition
                                            0xE0800000: None
                                            0xEA800000: On Write
                                            0xE1800000: On Execute
                                            0xEB800000: On Write & Execute
                            HBP[2]       == Mask of Data Address
                            HBP[3]       == Mask of Execution Address

                     Notes: Set BreakPoint
                            * Only works during program execution
---------------------------------------------------------------------------
CF_CMD_DBGDISABLEHBP        -

                     Notes: Disable BreakPoint
                            * Only works during program execution
---------------------------------------------------------------------------

===========================================================================
The following functions are LOW-LEVEL and should only be used by those who
have documentation on the Caetla Protocol and know what they are doing.
===========================================================================
Low-level commands enabling you to send and receive at a byte level. Most
transfers with Caetla are actually performed as a 'swap', ie a Send *and* a
Receive, irrespective of transfer direction. However, when using an XPlorer
cartridge, there are occasions when the Caetla protocol differs from PAR
and will only require either the essential send or receive. Since XPlorer
communications is slower than for PAR this improves speed.

Because of this, 3 low-level commands are included, all of which perform
the necessary handshaking and byte transfer.

Although data to PAR is sent and received a byte at a time, with XPlorer it
is exchanged in 3 transfers with more complicated handshaking.
---------------------------------------------------------------------------
CF_CMD_SWAPBYTE             bByte        == Byte Data

                     Notes: Send Byte & Receive Byte
                            * Received Byte is stored in bByte
---------------------------------------------------------------------------
CF_CMD_SENDBYTE             bByte        == Byte Data

                     Notes: Send Byte Only
                            * For PAR cartridge, this function is in fact
                              identical to CF_CMD_SWAPBYTE
---------------------------------------------------------------------------
CF_CMD_GETBYTE              -

                     Notes: Receive Byte Only
                            * For XPlorer this performs all necessary
                              handshaking and data exchange
                            * For PAR it simply returns the byte from the
                              comms port
---------------------------------------------------------------------------
Performing a CF_CMD_SENDBYTE followed by a CF_CMD_GETBYTE is identical to
a CF_CMD_SWAPBYTE. For PAR the CF_CMD_SENDBYTE command will actually return
the input data immediately from the comms port, due to the fact that PAR
handshaking takes place on sending a byte and not on receiving. This means
that duplicate attempts to get the received byte (such as with a following
CF_CMD_GETBYTE) are perfectly safe as no handshaking occurs, the byte is
read directly from the comms port and will not change until another send
takes place.
---------------------------------------------------------------------------
*/



/*
 * Definition of the CatFlapS management structure
 */

typedef struct CatFlapS {
    int             iLastCommand;       /* Last command processed */
    int             iResult;            /* Last result from CatFlap */
    int             iPort;              /* I/O Port */
    int             iCartType;          /* Cart Type */
    char            *pName;             /* Pointer to Name String */
    void            *pDataIn;           /* Pointer to Data Buffer */
    void            *pDataOut;          /* Pointer to Data Buffer */
    int             iDataCount;         /* Size of Data Transfer */
    unsigned long   iAddress;           /* Target Address */
    int             iX,iY,iW,iH,iDepth; /* For VRAM Functions */
    int             iCardSlot;          /* For MEMCARD Functions */
    int             iCardFile;          /* For MEMCARD Functions */
    BOOL            bBool;              /* Boolean Flag (true/false) */
    unsigned long   HBP[4];             /* Breakpoints */
    unsigned long   iWord;              /* General Data Usage */
    unsigned char   bByte;              /* General Data Usage */

/* Callbacks */
    short           (*fpKeyHook)(void);
    void            (*fpTextHook)(char *);
    FILE            *pFile;

} CatFlapS;


/*
 * Definition of the gateway function in the DLL
 */

typedef int (* CatFunc)(struct CatFlapS *, int);


/*
 * Available commands
 */

enum {
    CF_CMD_NOP=0,
    CF_CMD_INIT,
    CF_CMD_SETPORT,
    CF_CMD_SETCARTTYPE,
    CF_CMD_SETLOGFILE,
    CF_CMD_SETTEXTHOOK,
    CF_CMD_SETKEYHOOK,
    CF_CMD_SETKEYADDR,
    CF_CMD_DETECT,
    CF_CMD_NTSTATUS,
    CF_CMD_IOSTATUS,
    CF_CMD_GETVERSION,
    CF_CMD_ENABLEINFOBARS,

    CF_CMD_MODEQUERY,
    CF_CMD_MODEMAIN,
    CF_CMD_MODEMEMCARD,
    CF_CMD_MODEVRAM,
    CF_CMD_MODECDMANAGER,
    CF_CMD_MODEDEBUG,

    CF_CMD_RESUME,
    CF_CMD_RESET,
    CF_CMD_RUNEXEFILE,
    CF_CMD_RUNEXE,
    CF_CMD_SENDFILE,
    CF_CMD_SEND,
    CF_CMD_RECEIVEFILE,
    CF_CMD_RECEIVE,
    CF_CMD_RECEIVEVRAM,
    CF_CMD_RECEIVEVRAMFILE,

    CF_CMD_INITCONSOLE,
    CF_CMD_CALLCONSOLE,
    CF_CMD_ENDCONSOLE,
    CF_CMD_CONSOLELOOP,
    CF_CMD_CONSOLEQUITSTATUS,

    CF_CMD_INSTALLNT,
    CF_CMD_UNINSTALLNT,

    CF_CMD_MEMCARDSYNC,
    CF_CMD_MEMCARDLIST,
    CF_CMD_MEMCARDUP,
    CF_CMD_MEMCARDDOWN,
    CF_CMD_MEMCARDBACKUP,
    CF_CMD_MEMCARDRESTORE,
    CF_CMD_MEMCARDDELETE,
    CF_CMD_MEMCARDFORMAT,

    CF_CMD_DBGUPDATEBYTE,
    CF_CMD_DBGGETREGISTERS,
    CF_CMD_DBGSETREGISTER,
    CF_CMD_DBGGETCPCOND,
    CF_CMD_DBGFLUSHICACHE,
    CF_CMD_DBGSETHBP,
    CF_CMD_DBGDISABLEHBP,

    CF_CMD_SWAPBYTE,
    CF_CMD_SENDBYTE,
    CF_CMD_GETBYTE,

    CF_CMD_SETCONSOLEAUTOSENSE,

    CF_CMD_MAX
};


/*
 * Cartridge Types
 */

enum {
    CARTTYPE_PAR=0,
    CARTTYPE_XP,

    CARTTYPE_MAX
};


/*
 * Internal errorcodes from the Caetla communications class
 */

enum {
    CATFLAP_ERROR_OK=0,
    CATFLAP_ERROR_UNKNOWN,
    CATFLAP_ERROR_BADSTATUS,
    CATFLAP_ERROR_TIMEOUT,
    CATFLAP_ERROR_PROTOCOL,
    CATFLAP_ERROR_FILE,
    CATFLAP_ERROR_FILEFORMAT,
    CATFLAP_ERROR_FILENOTEXIST,
    CATFLAP_ERROR_LOWRAM,
    CATFLAP_ERROR_NTNODRIVER,
    CATFLAP_ERROR_NTIO,
    CATFLAP_ERROR_OUTOFRANGE,
    CATFLAP_ERROR_MC_NOCARD,
    CATFLAP_ERROR_MC_CARDFULL,
    CATFLAP_ERROR_MC_NOTFORMATTED,
    CATFLAP_ERROR_MC_FILEEXISTS,
};

#endif  //_CATFLAPDLL_H_
