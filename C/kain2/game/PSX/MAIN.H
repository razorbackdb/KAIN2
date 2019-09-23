#ifndef MAIN_H
#define MAIN_H

#include "PLAYER.H"
#include "MAING2.H"

extern struct _ButtonTexture BexitLine[2]; // offset 0x800D0E20

extern struct _ButtonTexture BmenuLines[3][2]; // offset 0x800D0F24

extern struct BLK_FILL clearRect[2]; // offset 0x800D0F88

extern struct DISPENV disp[2]; // offset 0x800D0E40

extern struct DRAWENV draw[2]; // offset 0x800D0E6C

extern struct GameTracker gameTrackerX; // offset 0x800D0FAC

extern struct InterfaceItem InterfaceItems[6]; // offset 0x800CE570

static int mainMenuSfx; // offset 0x800D0E1C

extern struct MainTracker mainTrackerX; // offset 0x800D121C

extern struct _ButtonTexture PauseButtons[4][2]; // offset 0x800D122C

struct DRAWENV // hashcode: 0x1D93A150 (dec: 496214352)
{
	struct RECT clip;	 // size=8, offset=0 //  hashcode: 0x4C63EAC0 (dec: 1281616576), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ofs[2];		  // size=4, offset=8 //  hashcode: 0x811CCC37 (dec: -2128819145), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RECT tw;		  // size=8, offset=12 //  hashcode: 0x235C14A6 (dec: 593237158), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short tpage; // size=0, offset=20 //  hashcode: 0xE83FE25C (dec: -398466468), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char dtd;	// size=0, offset=22 //  hashcode: 0x84ED4935 (dec: -2064824011), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char dfe;	// size=0, offset=23 //  hashcode: 0x5A7DA12B (dec: 1518182699), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char isbg;   // size=0, offset=24 //  hashcode: 0xEDDCCA89 (dec: -304297335), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;	 // size=0, offset=25 //  hashcode: 0x440EF004 (dec: 1141829636), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;	 // size=0, offset=26 //  hashcode: 0x54C07503 (dec: 1421899011), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;	 // size=0, offset=27 //  hashcode: 0x192F6508 (dec: 422536456), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DR_ENV dr_env; // size=64, offset=28 //  hashcode: 0x9CF0BBB7 (dec: -1661944905), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DISPENV // hashcode: 0x286FCE3D (dec: 678415933)
{
	struct RECT disp;	  // size=8, offset=0 //  hashcode: 0x9E74ADCC (dec: -1636520500), parent name: 'DISPENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RECT screen;	// size=8, offset=8 //  hashcode: 0x7ACC2C19 (dec: 2060200985), parent name: 'DISPENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char isinter; // size=0, offset=16 //  hashcode: 0xB5FC78DB (dec: -1241745189), parent name: 'DISPENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char isrgb24; // size=0, offset=17 //  hashcode: 0x61F6050C (dec: 1643513100), parent name: 'DISPENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad0;	// size=0, offset=18 //  hashcode: 0x7C32F70F (dec: 2083714831), parent name: 'DISPENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad1;	// size=0, offset=19 //  hashcode: 0xD0CAE7F3 (dec: -792008717), parent name: 'DISPENV', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BLK_FILL // hashcode: 0x2490546A (dec: 613438570)
{
	unsigned long tag;  // size=0, offset=0 //  hashcode: 0xC952401C (dec: -917356516), parent name: 'BLK_FILL', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;   // size=0, offset=4 //  hashcode: 0xFAAE3FCD (dec: -89243699), parent name: 'BLK_FILL', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;   // size=0, offset=5 //  hashcode: 0x5F4DC1D2 (dec: 1598931410), parent name: 'BLK_FILL', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;   // size=0, offset=6 //  hashcode: 0x90542E00 (dec: -1873531392), parent name: 'BLK_FILL', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code; // size=0, offset=7 //  hashcode: 0x299478C4 (dec: 697596100), parent name: 'BLK_FILL', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short x0;  // size=0, offset=8 //  hashcode: 0xF22C3537 (dec: -231983817), parent name: 'BLK_FILL', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short y0;  // size=0, offset=10 //  hashcode: 0xC2BAFFCC (dec: -1027932212), parent name: 'BLK_FILL', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short w;   // size=0, offset=12 //  hashcode: 0xBA30832F (dec: -1171225809), parent name: 'BLK_FILL', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short h;   // size=0, offset=14 //  hashcode: 0x404EFE45 (dec: 1078918725), parent name: 'BLK_FILL', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_73fake // hashcode: 0xFFEE4A6C (dec: -1160596)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xBC49F5EF (dec: -1136003601), parent name: 'MAIN_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x65442CC7 (dec: 1698966727), parent name: 'MAIN_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_74fake // hashcode: 0x20BE9927 (dec: 549361959)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xDF399B06 (dec: -549872890), parent name: 'MAIN_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xD3F2CF79 (dec: -739061895), parent name: 'MAIN_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_75fake // hashcode: 0x324CF732 (dec: 843904818)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x29C75C88 (dec: 700931208), parent name: 'MAIN_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x1E2F0656 (dec: 506398294), parent name: 'MAIN_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MAIN_76fake // Hashcode: 0x1DB2E0D5 (dec: 498262229)
{
	struct MAIN_73fake callback; // size=8, offset=0
	struct MAIN_74fake vector;   // size=12, offset=0
	struct MAIN_75fake quat;	 // size=16, offset=0
};

union MAIN_77fake // Hashcode: 0x7C857C0F (dec: 2089122831)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MAIN_78fake // Hashcode: 0xF02C1ADC (dec: -265544996)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct MAIN_79fake // hashcode: 0xDBDEB236 (dec: -606162378)
{
	union MAIN_78fake size; // size=4, offset=0 //  hashcode: 0x32107B26 (dec: 839940902), parent name: 'MAIN_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_80fake // hashcode: 0x515CE0F0 (dec: 1365041392)
{
	short x;				// size=0, offset=0 //  hashcode: 0xEE69DD6F (dec: -295051921), parent name: 'MAIN_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x3AD3EB3D (dec: 986966845), parent name: 'MAIN_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x08ABBD30 (dec: 145472816), parent name: 'MAIN_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xE74C08A3 (dec: -414447453), parent name: 'MAIN_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x3A83F2EC (dec: 981725932), parent name: 'MAIN_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_81fake // hashcode: 0xF06450FD (dec: -261861123)
{
	long index; // size=0, offset=0 //  hashcode: 0x2AFAF214 (dec: 721089044), parent name: 'MAIN_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x0F05087D (dec: 251988093), parent name: 'MAIN_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_82fake // hashcode: 0xD6183327 (dec: -703057113)
{
	long index; // size=0, offset=0 //  hashcode: 0xA339EF92 (dec: -1556484206), parent name: 'MAIN_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xF3D3D17B (dec: -204222085), parent name: 'MAIN_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_83fake // hashcode: 0x2FE8BF02 (dec: 803782402)
{
	long index; // size=0, offset=0 //  hashcode: 0xC4344E75 (dec: -1003205003), parent name: 'MAIN_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x456B7C84 (dec: 1164672132), parent name: 'MAIN_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_84fake // hashcode: 0x074A898C (dec: 122325388)
{
	long time;  // size=0, offset=0 //  hashcode: 0xAE5C64D6 (dec: -1369676586), parent name: 'MAIN_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x4EDB3497 (dec: 1322988695), parent name: 'MAIN_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_85fake // hashcode: 0x6BC38330 (dec: 1807975216)
{
	long action;   // size=0, offset=0 //  hashcode: 0x625D38CF (dec: 1650276559), parent name: 'MAIN_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x4099F0C9 (dec: 1083830473), parent name: 'MAIN_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_86fake // hashcode: 0xADBDB7CD (dec: -1380075571)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xF65A31D1 (dec: -161861167), parent name: 'MAIN_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x73F1903F (dec: 1945210943), parent name: 'MAIN_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_87fake // hashcode: 0x0AFB8122 (dec: 184254754)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x43A01D72 (dec: 1134566770), parent name: 'MAIN_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0xA6648A37 (dec: -1503360457), parent name: 'MAIN_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_88fake // hashcode: 0x22104D6E (dec: 571493742)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xA291D89F (dec: -1567500129), parent name: 'MAIN_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x8A4C5186 (dec: -1974709882), parent name: 'MAIN_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_89fake // hashcode: 0xE564995D (dec: -446391971)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xF5E8E3DB (dec: -169286693), parent name: 'MAIN_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x413F68DF (dec: 1094674655), parent name: 'MAIN_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x5337B360 (dec: 1396159328), parent name: 'MAIN_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x3ED1C3A7 (dec: 1053934503), parent name: 'MAIN_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x0106C8EA (dec: 17221866), parent name: 'MAIN_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_90fake // hashcode: 0x3AFF6FEF (dec: 989818863)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x3A634880 (dec: 979585152), parent name: 'MAIN_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x8484F3A2 (dec: -2071661662), parent name: 'MAIN_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_91fake // hashcode: 0xEE380467 (dec: -298318745)
{
	short index;					// size=0, offset=0 //  hashcode: 0xC2C6DA6D (dec: -1027155347), parent name: 'MAIN_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xE3AC8BF3 (dec: -475231245), parent name: 'MAIN_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xC1520890 (dec: -1051588464), parent name: 'MAIN_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xF82C7E3B (dec: -131301829), parent name: 'MAIN_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_92fake // hashcode: 0x4C313A4C (dec: 1278294604)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x3BD08E32 (dec: 1003523634), parent name: 'MAIN_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x772F98C1 (dec: 1999608001), parent name: 'MAIN_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xDDD117F8 (dec: -573499400), parent name: 'MAIN_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_93fake // hashcode: 0x35C64A6C (dec: 902187628)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xA6B7589C (dec: -1497933668), parent name: 'MAIN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x70D2E65E (dec: 1892869726), parent name: 'MAIN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x97EA4651 (dec: -1746254255), parent name: 'MAIN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xFE11A05F (dec: -32399265), parent name: 'MAIN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x3E7101D3 (dec: 1047593427), parent name: 'MAIN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x16D95A2E (dec: 383343150), parent name: 'MAIN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x453B745F (dec: 1161524319), parent name: 'MAIN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_94fake // hashcode: 0xF7B69F7B (dec: -139026565)
{
	long index;  // size=0, offset=0 //  hashcode: 0x24633F42 (dec: 610484034), parent name: 'MAIN_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xCE4B7AC5 (dec: -833914171), parent name: 'MAIN_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_95fake // hashcode: 0x5CC0C2A6 (dec: 1556136614)
{
	short type; // size=0, offset=0 //  hashcode: 0x0296AE24 (dec: 43429412), parent name: 'MAIN_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x78C5CDAC (dec: 2026229164), parent name: 'MAIN_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_96fake // hashcode: 0xF8516C87 (dec: -128881529)
{
	long time;   // size=0, offset=0 //  hashcode: 0x2B7D251B (dec: 729621787), parent name: 'MAIN_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x398DD9A9 (dec: 965597609), parent name: 'MAIN_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_97fake // hashcode: 0xD16438E0 (dec: -781960992)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x89E383FB (dec: -1981578245), parent name: 'MAIN_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x2DBDC350 (dec: 767411024), parent name: 'MAIN_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_98fake // hashcode: 0x57879ADA (dec: 1468504794)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x40FE7B06 (dec: 1090419462), parent name: 'MAIN_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x04A5725C (dec: 77951580), parent name: 'MAIN_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_99fake // hashcode: 0x43FC3102 (dec: 1140601090)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x85302DAA (dec: -2060440150), parent name: 'MAIN_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x2EB9961B (dec: 783914523), parent name: 'MAIN_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_100fake // hashcode: 0x86F324A9 (dec: -2030885719)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x643A3976 (dec: 1681537398), parent name: 'MAIN_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x6D932BE7 (dec: 1838361575), parent name: 'MAIN_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xE85A430A (dec: -396737782), parent name: 'MAIN_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x7CA43586 (dec: 2091136390), parent name: 'MAIN_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_101fake // hashcode: 0x56940EF5 (dec: 1452543733)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xFAA1A713 (dec: -90069229), parent name: 'MAIN_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xEE8F12C1 (dec: -292613439), parent name: 'MAIN_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xE723B6B5 (dec: -417089867), parent name: 'MAIN_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x26D9F68A (dec: 651818634), parent name: 'MAIN_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x45E133FD (dec: 1172386813), parent name: 'MAIN_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MAIN_102fake // Hashcode: 0xC5908511 (dec: -980384495)
{
	struct MAIN_79fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;	// size=24, offset=0
	struct MAIN_80fake teleport;	 // size=16, offset=0
	struct MAIN_81fake cameraValue;  // size=8, offset=0
	struct MAIN_82fake miscValue;	// size=8, offset=0
	struct MAIN_83fake logicValue;   // size=8, offset=0
	long timer;						 // size=0, offset=0
	long times;						 // size=0, offset=0
	long lightGroup;				 // size=0, offset=0
	long farPlane;					 // size=0, offset=0
	long cameraAdjust;				 // size=0, offset=0
	long cameraMode;				 // size=0, offset=0
	long cameraLock;				 // size=0, offset=0
	long cameraUnlock;				 // size=0, offset=0
	long cameraSmooth;				 // size=0, offset=0
	long cameraTimer;				 // size=0, offset=0
	struct MAIN_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				 // size=0, offset=0
	long cameraRestore;				 // size=0, offset=0
	struct _BGObject *bgObject;		 // size=24, offset=0
	long value[2];					 // size=8, offset=0
	struct MAIN_85fake sound;		 // size=12, offset=0
	void *intro;					 // size=0, offset=0
	long deathZ;					 // size=0, offset=0
	struct MAIN_86fake dsignal;		 // size=8, offset=0
	void *mirror;					 // size=0, offset=0
	long fogNear;					 // size=0, offset=0
	long fogFar;					 // size=0, offset=0
	struct MAIN_87fake gotoFrame;	// size=8, offset=0
	struct MAIN_88fake changeModel;  // size=8, offset=0
	void *vmObject;					 // size=0, offset=0
	struct MAIN_89fake logic;		 // size=8, offset=0
	void *callSignal;				 // size=0, offset=0
	struct _SVector offset;			 // size=8, offset=0
	struct Signal *gotoLabel;		 // size=0, offset=0
	struct Signal *gosubLabel;		 // size=0, offset=0
	struct MAIN_90fake control;		 // size=8, offset=0
	struct MAIN_91fake zSignal;		 // size=12, offset=0
	struct MAIN_92fake StreamLevel;  // size=24, offset=0
	struct MAIN_93fake shards;		 // size=12, offset=0
	struct MAIN_94fake cameraSpline; // size=8, offset=0
	struct MAIN_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				 // size=0, offset=0
	struct MAIN_96fake introFX;		 // size=8, offset=0
	struct MAIN_97fake introActive;  // size=8, offset=0
	struct MAIN_98fake levelChange;  // size=18, offset=0
	long blendStart;				 // size=0, offset=0
	struct MAIN_99fake setTimes;	 // size=8, offset=0
	struct MAIN_100fake color;		 // size=4, offset=0
	struct MAIN_101fake print;		 // size=12, offset=0
	long slideAngle;				 // size=0, offset=0
};

union MAIN_103fake // Hashcode: 0x6B181E95 (dec: 1796742805)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union MAIN_108fake // Hashcode: 0xEB2013E8 (dec: -350219288)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct MAIN_110fake // hashcode: 0x7C2BCE42 (dec: 2083245634)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x415DE99B (dec: 1096673691), parent name: 'MAIN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xC1BC62DE (dec: -1044618530), parent name: 'MAIN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0xE8BF9D4D (dec: -390095539), parent name: 'MAIN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x10182103 (dec: 270016771), parent name: 'MAIN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x490EDD25 (dec: 1225710885), parent name: 'MAIN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xB4209DA6 (dec: -1272930906), parent name: 'MAIN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x2262273A (dec: 576857914), parent name: 'MAIN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_111fake // hashcode: 0xB623B3CA (dec: -1239174198)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x1287B213 (dec: 310882835), parent name: 'MAIN_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x17A11F63 (dec: 396435299), parent name: 'MAIN_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x1DA789B9 (dec: 497519033), parent name: 'MAIN_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_112fake // hashcode: 0x9855DE28 (dec: -1739203032)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xBB2BF555 (dec: -1154747051), parent name: 'MAIN_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xB9EC9CAE (dec: -1175675730), parent name: 'MAIN_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x0F256796 (dec: 254109590), parent name: 'MAIN_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x1D7C381F (dec: 494680095), parent name: 'MAIN_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x6BC3DCB7 (dec: 1807998135), parent name: 'MAIN_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_113fake // hashcode: 0x42EA10F2 (dec: 1122636018)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xA6C3539D (dec: -1497148515), parent name: 'MAIN_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x68FEA12B (dec: 1761517867), parent name: 'MAIN_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x21669586 (dec: 560371078), parent name: 'MAIN_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xCB16CDB7 (dec: -887697993), parent name: 'MAIN_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xF2C9B161 (dec: -221662879), parent name: 'MAIN_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_114fake // hashcode: 0x6BBD5265 (dec: 1807569509)
{
	struct MAIN_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x5688E643 (dec: 1451812419), parent name: 'MAIN_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MAIN_111fake Idle;	  // size=20, offset=28 //  hashcode: 0x45FCA36C (dec: 1174184812), parent name: 'MAIN_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MAIN_112fake Behind;	// size=28, offset=48 //  hashcode: 0xD8A5DE7F (dec: -660218241), parent name: 'MAIN_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MAIN_113fake Follow;	// size=20, offset=76 //  hashcode: 0x7D2DD696 (dec: 2100156054), parent name: 'MAIN_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_185fake // hashcode: 0xC40A0559 (dec: -1005976231)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0xD85AAD6D (dec: -665146003), parent name: 'MAIN_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x25DC3E9A (dec: 635190938), parent name: 'MAIN_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MAIN_186fake // hashcode: 0xDF569968 (dec: -547972760)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0xA2D338EF (dec: -1563215633), parent name: 'MAIN_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x223A6629 (dec: 574252585), parent name: 'MAIN_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x189B5739 (dec: 412833593), parent name: 'MAIN_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0xDA47843D (dec: -632847299), parent name: 'MAIN_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x5B9112D3 (dec: 1536234195), parent name: 'MAIN_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x42BA099D (dec: 1119488413), parent name: 'MAIN_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MAIN_187fake // Hashcode: 0xFE15F5B0 (dec: -32115280)
{
	struct MAIN_185fake flame; // size=8, offset=0
	struct MAIN_186fake phys;  // size=12, offset=0
};

union MAIN_213fake // Hashcode: 0xFBB8D531 (dec: -71772879)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct MainTracker // hashcode: 0x7F315B98 (dec: 2133941144)
{
	long mainState;		// size=0, offset=0 //  hashcode: 0xF9F15A02 (dec: -101623294), parent name: 'MainTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long previousState; // size=0, offset=4 //  hashcode: 0xB5EABACC (dec: -1242907956), parent name: 'MainTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long movieNum;		// size=0, offset=8 //  hashcode: 0x419E5207 (dec: 1100894727), parent name: 'MainTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long done;			// size=0, offset=12 //  hashcode: 0x56D0BE7E (dec: 1456520830), parent name: 'MainTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AnalogueData // hashcode: 0xD8EB0F12 (dec: -655683822)
{
	unsigned short pad; // size=0, offset=0 //  hashcode: 0xD8D2758E (dec: -657295986), parent name: 'AnalogueData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char xR;   // size=0, offset=2 //  hashcode: 0x84491B5B (dec: -2075583653), parent name: 'AnalogueData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char yR;   // size=0, offset=3 //  hashcode: 0xFD3E63AA (dec: -46242902), parent name: 'AnalogueData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char xL;   // size=0, offset=4 //  hashcode: 0xCC80890F (dec: -863991537), parent name: 'AnalogueData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char yL;   // size=0, offset=5 //  hashcode: 0x0BFBC8B2 (dec: 201050290), parent name: 'AnalogueData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MAIN_243fake // Hashcode: 0xD076C382 (dec: -797523070)
{
	unsigned short pad;			  // size=0, offset=0
	unsigned short multitap[16];  // size=32, offset=0
	unsigned short mouse[2];	  // size=4, offset=0
	unsigned short negcon[3];	 // size=6, offset=0
	struct AnalogueData analogue; // size=6, offset=0
};

struct POLY_F4_SEMITRANS // hashcode: 0xE3D17AA2 (dec: -472810846)
{
	unsigned long tag;		// size=0, offset=0 //  hashcode: 0x98A33C45 (dec: -1734132667), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long dr_tpage; // size=0, offset=4 //  hashcode: 0x525DB744 (dec: 1381873476), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;		// size=0, offset=8 //  hashcode: 0x164D4A76 (dec: 374164086), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;		// size=0, offset=9 //  hashcode: 0xE823EDD2 (dec: -400298542), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;		// size=0, offset=10 //  hashcode: 0xDAA20371 (dec: -626916495), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code;		// size=0, offset=11 //  hashcode: 0x9151ED0C (dec: -1856901876), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;				// size=0, offset=12 //  hashcode: 0x30FCE018 (dec: 821878808), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;				// size=0, offset=14 //  hashcode: 0x48D99878 (dec: 1222219896), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;				// size=0, offset=16 //  hashcode: 0xAD46799B (dec: -1387890277), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;				// size=0, offset=18 //  hashcode: 0x13E78BD5 (dec: 333941717), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;				// size=0, offset=20 //  hashcode: 0x754F9545 (dec: 1968149829), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;				// size=0, offset=22 //  hashcode: 0xC3709566 (dec: -1016031898), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x3;				// size=0, offset=24 //  hashcode: 0x9E9C407F (dec: -1633927041), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y3;				// size=0, offset=26 //  hashcode: 0xA162D5A4 (dec: -1587358300), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MAIN_259fake // Hashcode: 0xF742589E (dec: -146646882)
{
	struct _StreamUnit *streamUnit;		 // size=64, offset=0
	struct _ObjectTracker *streamObject; // size=36, offset=0
	struct _ButtonTexture *button;		 // size=16, offset=0
};

struct PhysObProperties // hashcode: 0xD5487B33 (dec: -716670157)
{
	unsigned short version; // size=0, offset=0 //  hashcode: 0x2CA34176 (dec: 748896630), parent name: 'PhysObProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short family;  // size=0, offset=2 //  hashcode: 0x6F0BF69D (dec: 1863055005), parent name: 'PhysObProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short ID;		// size=0, offset=4 //  hashcode: 0x37849938 (dec: 931436856), parent name: 'PhysObProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short Type;	// size=0, offset=6 //  hashcode: 0xEE4C4926 (dec: -296990426), parent name: 'PhysObProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PhysObSplinter // hashcode: 0x933D3752 (dec: -1824704686)
{
	long numSplintData; // size=0, offset=0 //  hashcode: 0x5411882A (dec: 1410435114), parent name: 'PhysObSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *splinterData; // size=0, offset=4 //  hashcode: 0xE48359E9 (dec: -461153815), parent name: 'PhysObSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PhysObWeaponAttributes // hashcode: 0x6EB0170A (dec: 1857033994)
{
	long Damage;					// size=0, offset=0 //  hashcode: 0x727AC17E (dec: 1920647550), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	long AltDamage;					// size=0, offset=4 //  hashcode: 0x38EA81C2 (dec: 954892738), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short knockBackDistance;		// size=0, offset=8 //  hashcode: 0xDD6F3323 (dec: -579914973), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char knockBackFrames;			// size=0, offset=10 //  hashcode: 0x02DEB442 (dec: 48149570), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char dropSound;					// size=0, offset=11 //  hashcode: 0xBF708F16 (dec: -1083142378), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char Class;						// size=0, offset=12 //  hashcode: 0x9BB7F572 (dec: -1682442894), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char ThrowSphere;				// size=0, offset=13 //  hashcode: 0x4E6F9541 (dec: 1315935553), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char LeftHandSphere;			// size=0, offset=14 //  hashcode: 0xA15655CE (dec: -1588177458), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char RightHandSphere;			// size=0, offset=15 //  hashcode: 0x74B7A4C7 (dec: 1958192327), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _PhysObLight *Light;		// size=0, offset=16 //  hashcode: 0x897C1792 (dec: -1988356206), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PhysObSplinter splinter; // size=8, offset=20 //  hashcode: 0x2B328C22 (dec: 724732962), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _PhysObLight // hashcode: 0x873DE727 (dec: -2025986265)
{
	unsigned char length;				// size=0, offset=0 //  hashcode: 0xAD935552 (dec: -1382853294), parent name: '_PhysObLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segment;				// size=0, offset=1 //  hashcode: 0x853546AF (dec: -2060106065), parent name: '_PhysObLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	short speed;						// size=0, offset=2 //  hashcode: 0xD42244C2 (dec: -735951678), parent name: '_PhysObLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LightTableEntry *lightTable; // size=8, offset=4 //  hashcode: 0xC8B8E0B4 (dec: -927407948), parent name: '_PhysObLight', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __PhysObProjectileData // hashcode: 0x12820E13 (dec: 310513171)
{
	char model;							   // size=0, offset=0 //  hashcode: 0x1D35E28F (dec: 490070671), parent name: '__PhysObProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char startAnim;						   // size=0, offset=1 //  hashcode: 0xCB0D949B (dec: -888302437), parent name: '__PhysObProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char loopAnim;						   // size=0, offset=2 //  hashcode: 0xDDF3FABB (dec: -571213125), parent name: '__PhysObProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char endAnim;						   // size=0, offset=3 //  hashcode: 0x9C01DF96 (dec: -1677598826), parent name: '__PhysObProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;							   // size=0, offset=4 //  hashcode: 0xE0919E81 (dec: -527327615), parent name: '__PhysObProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PhysObWeaponAttributes *weapon; // size=28, offset=8 //  hashcode: 0x59204295 (dec: 1495286421), parent name: '__PhysObProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SwitchData // hashcode: 0x34EE19D8 (dec: 888019416)
{
	short state;	   // size=0, offset=0 //  hashcode: 0x493CF527 (dec: 1228731687), parent name: 'SwitchData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short accumulator; // size=0, offset=2 //  hashcode: 0x3FCA891F (dec: 1070237983), parent name: 'SwitchData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LightTableEntry // hashcode: 0x952494E4 (dec: -1792764700)
{
	short r;	  // size=0, offset=0 //  hashcode: 0x990C37A1 (dec: -1727252575), parent name: 'LightTableEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short g;	  // size=0, offset=2 //  hashcode: 0x0C60BBBC (dec: 207666108), parent name: 'LightTableEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short b;	  // size=0, offset=4 //  hashcode: 0xC9A3829B (dec: -912031077), parent name: 'LightTableEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short radius; // size=0, offset=6 //  hashcode: 0xFFD726CC (dec: -2677044), parent name: 'LightTableEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct InterfaceItem // hashcode: 0xB8494031 (dec: -1203158991)
{
	char name[48];				  // size=48, offset=0 //  hashcode: 0x0E607344 (dec: 241201988), parent name: 'InterfaceItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short timeout;		  // size=0, offset=48 //  hashcode: 0x5186B569 (dec: 1367782761), parent name: 'InterfaceItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short buttonTimeout; // size=0, offset=50 //  hashcode: 0x63D76AFC (dec: 1675062012), parent name: 'InterfaceItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short itemType;				  // size=0, offset=52 //  hashcode: 0x232581BF (dec: 589660607), parent name: 'InterfaceItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short nextItem;				  // size=0, offset=54 //  hashcode: 0x2F319B2A (dec: 791780138), parent name: 'InterfaceItem', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct DRAWENV DRAWENV;

typedef struct DISPENV DISPENV;

typedef struct BLK_FILL BLK_FILL;

typedef struct MainTracker MainTracker;

typedef struct AnalogueData AnalogueData;

typedef struct POLY_F4_SEMITRANS POLY_F4_SEMITRANS;

typedef struct PhysObProperties PhysObProperties;

typedef struct PhysObSplinter PhysObSplinter;

typedef struct PhysObWeaponAttributes PhysObWeaponAttributes;

typedef struct __PhysObProjectileData PhysObProjData;

typedef struct SwitchData SwitchData;

typedef struct LightTableEntry LightTableEntry;

typedef struct _PhysObLight PhysObLight;

typedef struct InterfaceItem InterfaceItem;

extern void ClearDisplay(); // 0x80037EF8

extern void screen_to_vram(long *screen, int buffer); // 0x80037FB4

extern void show_screen(char *name); // 0x80037FE4

extern void play_movie(char *name); // 0x80038028

extern void InitMainTracker(struct MainTracker *mainTracker); // 0x80038070

extern char *FindTextInLine(char *search_match, char *search_str); // 0x80038080

extern void ExtractWorldName(char *worldName, char *levelName); // 0x80038108

extern void ExtractLevelNum(char *levelNum, char *levelName); // 0x80038154

extern void ProcessArgs(char *baseAreaName, struct GameTracker *gameTracker); // 0x800381C0

extern void InitDisplay(); // 0x800383D8

extern void StartTimer(); // 0x80038554

extern void VblTick(); // 0x800385C0

extern void DrawCallback(); // 0x8003862C

extern void FadeOutSayingLoading(struct GameTracker *gameTracker); // 0x80038684

extern void CheckForDevStation(); // 0x800387D4

extern void MAIN_ShowLoadingScreen(); // 0x80038834

extern long *MAIN_LoadTim(char *name); // 0x800388E4

extern void init_menus(struct GameTracker *gt); // 0x80038904

extern void MAIN_DoMainInit(); // 0x80038950

extern void MAIN_InitVolume(); // 0x80038A44

extern void MAIN_ResetGame(); // 0x80038A84

extern void MAIN_MainMenuInit(); // 0x80038AD4

extern void MAIN_FreeMainMenuStuff(); // 0x80038C6C

extern void MAIN_StartGame(); // 0x80038CDC

extern long MAIN_DoMainMenu(struct GameTracker *gameTracker, struct MainTracker *mainTracker, long menuPos); // 0x80038D48

extern int MainG2(void *appData); // 0x80038E1C

#endif
