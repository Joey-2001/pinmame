#ifndef INC_S11
#define INC_S11

#include "core.h"
#include "wpcsam.h"
#include "sim.h"

/*-- Common Inports for S11Games --*/
#define S11_COMPORTS \
  PORT_START /* 0 */ \
    /* Switch Column 1 */ \
    COREPORT_BITDEF(  0x0001, IPT_TILT,           KEYCODE_INSERT)  \
    COREPORT_BIT(     0x0002, "Ball Tilt",        KEYCODE_2)  \
    COREPORT_BITDEF(  0x0004, IPT_START1,         IP_KEY_DEFAULT)  \
    COREPORT_BITDEF(  0x0008, IPT_COIN1,          IP_KEY_DEFAULT) \
    COREPORT_BITDEF(  0x0010, IPT_COIN2,          IP_KEY_DEFAULT) \
    COREPORT_BITDEF(  0x0020, IPT_COIN3,          KEYCODE_3) \
    COREPORT_BIT(     0x0040, "Slam Tilt",        KEYCODE_HOME)  \
    COREPORT_BIT(     0x0080, "Hiscore Reset",    KEYCODE_4) \
    /* These are put in switch column 0 */ \
    COREPORT_BIT(     0x0100, "Advance",          KEYCODE_8) \
    COREPORT_BITTOG(  0x0200, "Up/Down",      KEYCODE_7) \
    COREPORT_BIT(     0x0400, "CPU Diagnostic",   KEYCODE_9) \
    COREPORT_BIT(     0x0800, "Sound Diagnostic", KEYCODE_0) \
  PORT_START /* 1 */ \
    COREPORT_DIPNAME( 0x0001, 0x0000, "Country") \
      COREPORT_DIPSET(0x0001, "Germany" ) \
      COREPORT_DIPSET(0x0000, "USA" )

#define DE_COMPORTS \
  PORT_START /* 0 */ \
    /* Switch Column 1 */ \
    COREPORT_BITDEF(  0x0001, IPT_TILT,           KEYCODE_INSERT)  \
    COREPORT_BIT(     0x0002, "Ball Tilt",        KEYCODE_2)  \
    COREPORT_BITDEF(  0x0004, IPT_START1,         IP_KEY_DEFAULT)  \
    COREPORT_BITDEF(  0x0008, IPT_COIN1,          IP_KEY_DEFAULT) \
    COREPORT_BITDEF(  0x0010, IPT_COIN2,          IP_KEY_DEFAULT) \
    COREPORT_BITDEF(  0x0020, IPT_COIN3,          KEYCODE_3) \
    COREPORT_BIT(     0x0040, "Slam Tilt",        KEYCODE_HOME)  \
    /* These are put in switch column 0 */ \
    COREPORT_BIT(     0x0100, "Black Button",     KEYCODE_8) \
    COREPORT_BITTOG(  0x0200, "Green Button",     KEYCODE_7)

/*-- Standard input ports --*/
#define S11_INPUT_PORTS_START(name,balls) \
  INPUT_PORTS_START(name) \
    CORE_PORTS \
    SIM_PORTS(balls) \
    S11_COMPORTS

#define S11_INPUT_PORTS_END INPUT_PORTS_END

#define S11_COMINPORT       CORE_COREINPORT

#define DE_INPUT_PORTS_START(name,balls) \
  INPUT_PORTS_START(name) \
    CORE_PORTS \
    SIM_PORTS(balls) \
    DE_COMPORTS

#define DE_INPUT_PORTS_END INPUT_PORTS_END

#define DE_COMINPORT       CORE_COREINPORT

#define S11_SOLSMOOTH       4 /* Smooth the Solenoids over this numer of VBLANKS */
#define S11_LAMPSMOOTH      2 /* Smooth the lamps over this number of VBLANKS */
#define S11_DISPLAYSMOOTH   2 /* Smooth the display over this number of VBLANKS */

/*-- To access C-side multiplexed solenoid/flasher --*/
#define S11_CSOL(x) ((x)+(WPC_FIRSTFLIPPERSOL-1))
#define DE_CSOL(x) ((x)+24)
/*-- GameOn solenoids --*/
#define S11_GAMEONSOL 23
#define DE_GAMEONSOL  23

/*-- DE switch numbers --*/
#define DE_SWADVANCE     -7
#define DE_SWUPDN        -6

/*-- S11 switch numbers --*/
#define S11_SWADVANCE     -7
#define S11_SWUPDN        -6
#define S11_SWCPUDIAG     -5
#define S11_SWSOUNDDIAG   -4

/*-------------------------
/ Machine driver constants
/--------------------------*/
/*-- Memory regions --*/
#define S11_CPUREGION		REGION_CPU1

/*-- standard display layouts --*/
extern const core_tLCDLayout s11_dispS9[], s11_dispS11[], s11_dispS11a[], s11_dispS11b2[];
#define s11_dispS11b1 s11_dispS11a
#define s11_dispS11c  s11_dispS11b2

/*-- Main CPU regions and ROM --*/
#define S9_ROMSTARTx4(name, ver, n1, chk1) \
  ROM_START(name##_##ver) \
    NORMALREGION(0x10000, S11_CPUREGION) \
      ROM_LOAD(n1, 0x8000, 0x4000, chk1) \
      ROM_RELOAD(  0xc000, 0x4000)

#define S9_ROMSTART12(name, ver, n1, chk1,n2,chk2) \
  ROM_START(name##_##ver) \
    NORMALREGION(0x10000, S11_CPUREGION) \
      ROM_LOAD(n1, 0x5000, 0x1000, chk1) \
      ROM_RELOAD(  0xd000, 0x1000) \
      ROM_LOAD(n2, 0x6000, 0x2000, chk2) \
      ROM_RELOAD(  0xe000, 0x2000)

#define S11_ROMSTART48(name, ver, n1, chk1, n2, chk2) \
  ROM_START(name##_##ver) \
    NORMALREGION(0x10000, S11_CPUREGION) \
      ROM_LOAD(n1, 0x4000, 0x4000, chk1) \
      ROM_LOAD(n2, 0x8000, 0x8000, chk2)

#define S11_ROMSTART28(name, ver, n1, chk1, n2, chk2) \
  ROM_START(name##_##ver) \
    NORMALREGION(0x10000, S11_CPUREGION) \
      ROM_LOAD(n1, 0x4000, 0x2000, chk1) \
        ROM_RELOAD(  0x6000, 0x2000) \
      ROM_LOAD(n2, 0x8000, 0x8000, chk2)

#define S11_ROMSTART24(name, ver, n1, chk1, n2, chk2) \
  ROM_START(name##_##ver) \
    NORMALREGION(0x10000, S11_CPUREGION) \
      ROM_LOAD(n1, 0x4000, 0x2000, chk1) \
        ROM_RELOAD(  0x6000, 0x2000) \
      ROM_LOAD(n2, 0x8000, 0x4000, chk2) \
        ROM_RELOAD(  0xc000, 0x4000)

#define S11_ROMEND ROM_END
#define S9_ROMEND ROM_END

#define DE_CPUREGION		REGION_CPU1

//#define DE_MEMREG_SCPU1		REGION_CPU2	/*Sound is CPU #2 for alpha games*/
//#define DE_MEMREG_DCPU1		REGION_CPU2 /*DMD is CPU #2 for DMD games*/
//#define DE_MEMREG_SDCPU1	REGION_CPU3 /*Sound is CPU #3 for DMD games*/

//#define DE_MEMREG_SROM1		REGION_USER1 /*Sound rom loaded into Region #1*/
//#define DE_MEMREG_DROM1		REGION_USER1 /*DMD rom loaded into Region #1*/
//#define DE_MEMREG_SDROM1	REGION_USER2 /*Sound rom on DMD games loaded into Region #2*/

/**************************************/
/******* GAMES USING 2 ROMS     *******/
/**************************************/

/********************/
/** 16K & 32K ROMS **/
/********************/

/*-- Main CPU regions and ROM --*/
#define DE_ROMSTART12(name, n1, chk1, n2, chk2) \
   ROM_START(name) \
     NORMALREGION(0x10000, DE_CPUREGION) \
       ROM_LOAD(n1, 0x4000, 0x4000, chk1) \
       ROM_LOAD(n2, 0x8000, 0x8000, chk2)

/***********************************************/
/** 2 X 32K(1st 8K of B5 Chip is Blank) ROMS  **/
/***********************************************/

/*-- Main CPU regions and ROM --*/
#define DE_ROMSTART22(name, n1, chk1, n2, chk2) \
   ROM_START(name) \
     NORMALREGION(0x10000, DE_CPUREGION) \
       ROM_LOAD(n1, 0x0000, 0x8000, chk1) \
       ROM_LOAD(n2, 0x8000, 0x8000, chk2)

/**************************************/
/******* GAMES USING ONLY 1 ROM *******/
/**************************************/

/***********************/
/** 32K in 1 Rom Only **/
/***********************/

/*-- Main CPU regions and ROM --*/
#define DEx2_ROMSTART(name, n1, chk1) \
   ROM_START(name) \
     NORMALREGION(0x10000, DE_CPUREGION) \
	ROM_LOAD(n1, 0x8000, 0x8000, chk1)

/**************************************/
/** 64K(1st 8K of Chip is Blank) ROM **/
/**************************************/

/*-- Main CPU regions and ROM --*/
#define DE_ROMSTARTx4(name, n1, chk1) \
   ROM_START(name) \
     NORMALREGION(0x10000, DE_CPUREGION) \
       ROM_LOAD(n1, 0x0000, 0x10000, chk1)

/*-- These are only here so the game structure can be in the game file --*/
extern const struct MachineDriver machine_driver_s9;
extern const struct MachineDriver machine_driver_s11;
#define s9_mS9           s9
#define s11_mS11         s11
#define s11_mS11A        s11
#define s11_mS11B        s11
#define s11_mS11B2       s11
#define s11_mS11C        s11
#define de_mDEA          s11

extern const struct MachineDriver machine_driver_s9_s;
extern const struct MachineDriver machine_driver_s11_s;
extern const struct MachineDriver machine_driver_s11b2_s;
extern const struct MachineDriver machine_driver_s11c_s;
extern const struct MachineDriver machine_driver_des11_s;
#define s9_mS9S          s9_s
#define s11_mS11S        s11_s
#define s11_mS11AS       s11_s
#define s11_mS11BS       s11_s
#define s11_mS11B2S      s11b2_s
#define s11_mS11CS       s11c_s
#define de_mDEAS         des11_s

#define S11_BCDDIAG      0x01 // 7seg diagnostic led
#define S11_BCDDISP      0x02 // BCD display
#define S11_LOWALPHA     0x04 // Alphanumeric second line display
#define S11_DISPINV      0x08 // Display signals are inverted
#define S11_MUXSW2       0x01 // MUX Solenoid activates
#define S11_SNDOVERLAY   0x02 // Overlay solenoid board
#if 0
GEN_S9      BCDDIAG | BCDDISP
GEN_S11     BCDDIAG
GEN_S11A
GEN_S11B_1
GEN_S11B_2  LOWALPHA | INV                MUX2
GEN_S11B_2x LOWALPHA | INV | EXTSOLBOARD  MUX2
GEN_S11B_3  LOWALPHA | INV                MUX2
GEN_S11C    LOWALPHA | INV                MUX2
DE_ALPHA1
DE_ALPHA2
DE_ALPHA3   LOWALPHA
#endif
#endif /* INC_S11 */

