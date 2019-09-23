#ifndef PIPE3D_H
#define PIPE3D_H

struct POLY_FT3 // hashcode: 0x1FB59984 (dec: 531995012)
{
	unsigned long tag;	// size=0, offset=0 //  hashcode: 0x0FE3B4C8 (dec: 266581192), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;	 // size=0, offset=4 //  hashcode: 0xFED6AB43 (dec: -19485885), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;	 // size=0, offset=5 //  hashcode: 0x3BBC647F (dec: 1002202239), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;	 // size=0, offset=6 //  hashcode: 0xB2D6B141 (dec: -1294552767), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code;   // size=0, offset=7 //  hashcode: 0x39ACD9AD (dec: 967629229), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			  // size=0, offset=8 //  hashcode: 0x42E46D99 (dec: 1122266521), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			  // size=0, offset=10 //  hashcode: 0xC965A7A9 (dec: -916084823), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u0;	 // size=0, offset=12 //  hashcode: 0x3914C637 (dec: 957662775), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v0;	 // size=0, offset=13 //  hashcode: 0x39AA2222 (dec: 967451170), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short clut;  // size=0, offset=14 //  hashcode: 0x1421E8D4 (dec: 337766612), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			  // size=0, offset=16 //  hashcode: 0x67A80957 (dec: 1739065687), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			  // size=0, offset=18 //  hashcode: 0x4CC79D98 (dec: 1288150424), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u1;	 // size=0, offset=20 //  hashcode: 0x4DA3B20A (dec: 1302573578), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v1;	 // size=0, offset=21 //  hashcode: 0xC56186BB (dec: -983464261), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short tpage; // size=0, offset=22 //  hashcode: 0xC5F6EAAE (dec: -973673810), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;			  // size=0, offset=24 //  hashcode: 0xB73F7621 (dec: -1220577759), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;			  // size=0, offset=26 //  hashcode: 0x30C7703E (dec: 818376766), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u2;	 // size=0, offset=28 //  hashcode: 0x66B8D180 (dec: 1723388288), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v2;	 // size=0, offset=29 //  hashcode: 0x7674F301 (dec: 1987375873), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad1;  // size=0, offset=30 //  hashcode: 0xC54AD8A9 (dec: -984950615), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_68fake // hashcode: 0xF8B8398D (dec: -122144371)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x37ECD710 (dec: 938268432), parent name: 'PIPE3D_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x0D31667D (dec: 221341309), parent name: 'PIPE3D_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_69fake // hashcode: 0xD4A4780F (dec: -727418865)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x7EFF3A25 (dec: 2130655781), parent name: 'PIPE3D_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x90B755DD (dec: -1867033123), parent name: 'PIPE3D_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_70fake // hashcode: 0x6BAB5163 (dec: 1806389603)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x5BEB8FF2 (dec: 1542164466), parent name: 'PIPE3D_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x1D171564 (dec: 488052068), parent name: 'PIPE3D_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PIPE3D_71fake // Hashcode: 0x1EBB5F62 (dec: 515596130)
{
	struct PIPE3D_68fake callback; // size=8, offset=0
	struct PIPE3D_69fake vector;   // size=12, offset=0
	struct PIPE3D_70fake quat;	 // size=16, offset=0
};

union PIPE3D_72fake // Hashcode: 0x17C0E47B (dec: 398517371)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PIPE3D_73fake // Hashcode: 0x07A23957 (dec: 128072023)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct PIPE3D_74fake // hashcode: 0x030FF0BE (dec: 51376318)
{
	union PIPE3D_73fake size; // size=4, offset=0 //  hashcode: 0x440FB4A1 (dec: 1141879969), parent name: 'PIPE3D_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_75fake // hashcode: 0x8935959C (dec: -1992976996)
{
	short x;				// size=0, offset=0 //  hashcode: 0x3705E368 (dec: 923132776), parent name: 'PIPE3D_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x65A31835 (dec: 1705187381), parent name: 'PIPE3D_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xF3298CB5 (dec: -215380811), parent name: 'PIPE3D_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xECC70829 (dec: -322500567), parent name: 'PIPE3D_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x3FFD7C80 (dec: 1073577088), parent name: 'PIPE3D_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_76fake // hashcode: 0x452A5041 (dec: 1160400961)
{
	long index; // size=0, offset=0 //  hashcode: 0x74985A3A (dec: 1956141626), parent name: 'PIPE3D_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xEB7F8733 (dec: -343963853), parent name: 'PIPE3D_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_77fake // hashcode: 0xA432574C (dec: -1540204724)
{
	long index; // size=0, offset=0 //  hashcode: 0x5CFEDACF (dec: 1560206031), parent name: 'PIPE3D_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x308A262B (dec: 814360107), parent name: 'PIPE3D_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_78fake // hashcode: 0x401A03F4 (dec: 1075446772)
{
	long index; // size=0, offset=0 //  hashcode: 0x2A620975 (dec: 711068021), parent name: 'PIPE3D_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x821C99D2 (dec: -2112054830), parent name: 'PIPE3D_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_79fake // hashcode: 0x22A4F46B (dec: 581235819)
{
	long time;  // size=0, offset=0 //  hashcode: 0x91626C15 (dec: -1855820779), parent name: 'PIPE3D_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x0F4F3A88 (dec: 256850568), parent name: 'PIPE3D_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_80fake // hashcode: 0x8839CC5E (dec: -2009478050)
{
	long action;   // size=0, offset=0 //  hashcode: 0x1472C0AC (dec: 343064748), parent name: 'PIPE3D_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x366F3FD7 (dec: 913260503), parent name: 'PIPE3D_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_81fake // hashcode: 0x3F5AD028 (dec: 1062916136)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x247F8937 (dec: 612337975), parent name: 'PIPE3D_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xD6A7EDE9 (dec: -693637655), parent name: 'PIPE3D_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_82fake // hashcode: 0x889ED85A (dec: -2002855846)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xC78A9EF0 (dec: -947216656), parent name: 'PIPE3D_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x68BFAEC9 (dec: 1757392585), parent name: 'PIPE3D_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_83fake // hashcode: 0x5C82800B (dec: 1552056331)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xA61D651E (dec: -1508023010), parent name: 'PIPE3D_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x94C7C858 (dec: -1798846376), parent name: 'PIPE3D_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_84fake // hashcode: 0x0785136A (dec: 126161770)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x46EA0741 (dec: 1189742401), parent name: 'PIPE3D_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x217EBA5A (dec: 561953370), parent name: 'PIPE3D_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xAB38FA03 (dec: -1422329341), parent name: 'PIPE3D_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xB43B314D (dec: -1271189171), parent name: 'PIPE3D_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x8B770A87 (dec: -1955132793), parent name: 'PIPE3D_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_85fake // hashcode: 0xD456CAED (dec: -732509459)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x3CBAD81A (dec: 1018877978), parent name: 'PIPE3D_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xFE48AFD7 (dec: -28790825), parent name: 'PIPE3D_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_86fake // hashcode: 0x4DBB2040 (dec: 1304109120)
{
	short index;					// size=0, offset=0 //  hashcode: 0x9F6BC21D (dec: -1620327907), parent name: 'PIPE3D_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xD3B86271 (dec: -742890895), parent name: 'PIPE3D_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x8644135E (dec: -2042358946), parent name: 'PIPE3D_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xED54744E (dec: -313232306), parent name: 'PIPE3D_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_87fake // hashcode: 0xC8C6AF04 (dec: -926503164)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xAD0B2A6F (dec: -1391777169), parent name: 'PIPE3D_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xB2845301 (dec: -1299950847), parent name: 'PIPE3D_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x63CC83C3 (dec: 1674347459), parent name: 'PIPE3D_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_88fake // hashcode: 0x7DAF4E03 (dec: 2108640771)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x3777B962 (dec: 930593122), parent name: 'PIPE3D_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xC81ECF92 (dec: -937504878), parent name: 'PIPE3D_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x91600A03 (dec: -1855976957), parent name: 'PIPE3D_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xC81CF8D9 (dec: -937625383), parent name: 'PIPE3D_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x3553195C (dec: 894638428), parent name: 'PIPE3D_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x116DC7BA (dec: 292407226), parent name: 'PIPE3D_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x78C6DD4B (dec: 2026298699), parent name: 'PIPE3D_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_89fake // hashcode: 0x7C575DD6 (dec: 2086100438)
{
	long index;  // size=0, offset=0 //  hashcode: 0x45276788 (dec: 1160210312), parent name: 'PIPE3D_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xB3565D0C (dec: -1286185716), parent name: 'PIPE3D_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_90fake // hashcode: 0xBB32FEED (dec: -1154285843)
{
	short type; // size=0, offset=0 //  hashcode: 0x79E41C31 (dec: 2044992561), parent name: 'PIPE3D_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x627064ED (dec: 1651533037), parent name: 'PIPE3D_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_91fake // hashcode: 0xE2247715 (dec: -500926699)
{
	long time;   // size=0, offset=0 //  hashcode: 0x520B1B21 (dec: 1376459553), parent name: 'PIPE3D_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x4ED468C3 (dec: 1322543299), parent name: 'PIPE3D_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_92fake // hashcode: 0x91CB3F91 (dec: -1848950895)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xED0B78E1 (dec: -318015263), parent name: 'PIPE3D_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x70B44CAE (dec: 1890864302), parent name: 'PIPE3D_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_93fake // hashcode: 0x56A8B95E (dec: 1453898078)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x36A22248 (dec: 916595272), parent name: 'PIPE3D_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xB2D3D6B7 (dec: -1294739785), parent name: 'PIPE3D_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_94fake // hashcode: 0xFC680C45 (dec: -60289979)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xED162138 (dec: -317316808), parent name: 'PIPE3D_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xCFDA0CF5 (dec: -807793419), parent name: 'PIPE3D_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_95fake // hashcode: 0x5C2E32AA (dec: 1546531498)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x518E2AED (dec: 1368271597), parent name: 'PIPE3D_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x58D3C852 (dec: 1490274386), parent name: 'PIPE3D_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x6A5862D4 (dec: 1784177364), parent name: 'PIPE3D_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xDE4C7DF5 (dec: -565412363), parent name: 'PIPE3D_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_96fake // hashcode: 0x3E232FA6 (dec: 1042493350)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xE572A235 (dec: -445472203), parent name: 'PIPE3D_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xACB13632 (dec: -1397672398), parent name: 'PIPE3D_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xBA483DA9 (dec: -1169670743), parent name: 'PIPE3D_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xC1358BCC (dec: -1053455412), parent name: 'PIPE3D_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x7D5D1623 (dec: 2103252515), parent name: 'PIPE3D_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PIPE3D_97fake // Hashcode: 0xE5DFD122 (dec: -438316766)
{
	struct PIPE3D_74fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	  // size=24, offset=0
	struct PIPE3D_75fake teleport;	 // size=16, offset=0
	struct PIPE3D_76fake cameraValue;  // size=8, offset=0
	struct PIPE3D_77fake miscValue;	// size=8, offset=0
	struct PIPE3D_78fake logicValue;   // size=8, offset=0
	long timer;						   // size=0, offset=0
	long times;						   // size=0, offset=0
	long lightGroup;				   // size=0, offset=0
	long farPlane;					   // size=0, offset=0
	long cameraAdjust;				   // size=0, offset=0
	long cameraMode;				   // size=0, offset=0
	long cameraLock;				   // size=0, offset=0
	long cameraUnlock;				   // size=0, offset=0
	long cameraSmooth;				   // size=0, offset=0
	long cameraTimer;				   // size=0, offset=0
	struct PIPE3D_79fake cameraShake;  // size=8, offset=0
	long cameraSave;				   // size=0, offset=0
	long cameraRestore;				   // size=0, offset=0
	struct _BGObject *bgObject;		   // size=24, offset=0
	long value[2];					   // size=8, offset=0
	struct PIPE3D_80fake sound;		   // size=12, offset=0
	void *intro;					   // size=0, offset=0
	long deathZ;					   // size=0, offset=0
	struct PIPE3D_81fake dsignal;	  // size=8, offset=0
	void *mirror;					   // size=0, offset=0
	long fogNear;					   // size=0, offset=0
	long fogFar;					   // size=0, offset=0
	struct PIPE3D_82fake gotoFrame;	// size=8, offset=0
	struct PIPE3D_83fake changeModel;  // size=8, offset=0
	void *vmObject;					   // size=0, offset=0
	struct PIPE3D_84fake logic;		   // size=8, offset=0
	void *callSignal;				   // size=0, offset=0
	struct _SVector offset;			   // size=8, offset=0
	struct Signal *gotoLabel;		   // size=0, offset=0
	struct Signal *gosubLabel;		   // size=0, offset=0
	struct PIPE3D_85fake control;	  // size=8, offset=0
	struct PIPE3D_86fake zSignal;	  // size=12, offset=0
	struct PIPE3D_87fake StreamLevel;  // size=24, offset=0
	struct PIPE3D_88fake shards;	   // size=12, offset=0
	struct PIPE3D_89fake cameraSpline; // size=8, offset=0
	struct PIPE3D_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;				   // size=0, offset=0
	struct PIPE3D_91fake introFX;	  // size=8, offset=0
	struct PIPE3D_92fake introActive;  // size=8, offset=0
	struct PIPE3D_93fake levelChange;  // size=18, offset=0
	long blendStart;				   // size=0, offset=0
	struct PIPE3D_94fake setTimes;	 // size=8, offset=0
	struct PIPE3D_95fake color;		   // size=4, offset=0
	struct PIPE3D_96fake print;		   // size=12, offset=0
	long slideAngle;				   // size=0, offset=0
};

union PIPE3D_98fake // Hashcode: 0x00498669 (dec: 4818537)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

struct _Mirror // hashcode: 0x6161DBD4 (dec: 1633803220)
{
	short a; // size=0, offset=0 //  hashcode: 0xE7EA999C (dec: -404055652), parent name: '_Mirror', parent hashcode: 0xFFFFFFFF (dec: -1)
	short b; // size=0, offset=2 //  hashcode: 0xF235BF90 (dec: -231358576), parent name: '_Mirror', parent hashcode: 0xFFFFFFFF (dec: -1)
	short c; // size=0, offset=4 //  hashcode: 0x616092DD (dec: 1633719005), parent name: '_Mirror', parent hashcode: 0xFFFFFFFF (dec: -1)
	short d; // size=0, offset=6 //  hashcode: 0x9AF4CF4D (dec: -1695232179), parent name: '_Mirror', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PIPE3D_103fake // Hashcode: 0x8DEE28C4 (dec: -1913771836)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct PIPE3D_105fake // hashcode: 0x9500CFD1 (dec: -1795108911)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x8C604611 (dec: -1939847663), parent name: 'PIPE3D_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xB0FC8CDD (dec: -1325626147), parent name: 'PIPE3D_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x840927CA (dec: -2079774774), parent name: 'PIPE3D_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x433B4A45 (dec: 1127959109), parent name: 'PIPE3D_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0xD1D8FC13 (dec: -774308845), parent name: 'PIPE3D_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xD0FA379E (dec: -788908130), parent name: 'PIPE3D_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xBED23B03 (dec: -1093518589), parent name: 'PIPE3D_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_106fake // hashcode: 0xEEBC095C (dec: -289666724)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x241C8A0C (dec: 605850124), parent name: 'PIPE3D_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x7CB4FA3E (dec: 2092235326), parent name: 'PIPE3D_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x0E545D3A (dec: 240409914), parent name: 'PIPE3D_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_107fake // hashcode: 0xBE351E27 (dec: -1103815129)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x1CE4DDF5 (dec: 484761077), parent name: 'PIPE3D_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xA86C9DC1 (dec: -1469276735), parent name: 'PIPE3D_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x14B0A008 (dec: 347119624), parent name: 'PIPE3D_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x80704B6A (dec: -2140124310), parent name: 'PIPE3D_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xE4FABAA4 (dec: -453330268), parent name: 'PIPE3D_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_108fake // hashcode: 0xCD6EC577 (dec: -848378505)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x26C63378 (dec: 650523512), parent name: 'PIPE3D_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0xFF147120 (dec: -15437536), parent name: 'PIPE3D_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x6D3198A0 (dec: 1831966880), parent name: 'PIPE3D_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x384440B2 (dec: 943997106), parent name: 'PIPE3D_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x236389EA (dec: 593725930), parent name: 'PIPE3D_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_109fake // hashcode: 0xEADE4BF5 (dec: -354530315)
{
	struct PIPE3D_105fake Cinematic; // size=28, offset=0 //  hashcode: 0xCA2D9B47 (dec: -902980793), parent name: 'PIPE3D_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PIPE3D_106fake Idle;		 // size=20, offset=28 //  hashcode: 0xA1309AAE (dec: -1590650194), parent name: 'PIPE3D_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PIPE3D_107fake Behind;	// size=28, offset=48 //  hashcode: 0xD63054E7 (dec: -701475609), parent name: 'PIPE3D_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PIPE3D_108fake Follow;	// size=20, offset=76 //  hashcode: 0x2AF813BE (dec: 720901054), parent name: 'PIPE3D_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_171fake // hashcode: 0x1A1B1F53 (dec: 437985107)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0xA56A1308 (dec: -1519774968), parent name: 'PIPE3D_171fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0xF01BA965 (dec: -266622619), parent name: 'PIPE3D_171fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_172fake // hashcode: 0x22FCC304 (dec: 586990340)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0xDDF41B70 (dec: -571204752), parent name: 'PIPE3D_172fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x0CF91344 (dec: 217649988), parent name: 'PIPE3D_172fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0xF1D57CB8 (dec: -237667144), parent name: 'PIPE3D_172fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0xDC23B8E1 (dec: -601638687), parent name: 'PIPE3D_172fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0xC6F435FA (dec: -957073926), parent name: 'PIPE3D_172fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x1C19D05E (dec: 471453790), parent name: 'PIPE3D_172fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PIPE3D_173fake // Hashcode: 0xBB6C2CF3 (dec: -1150538509)
{
	struct PIPE3D_171fake flame; // size=8, offset=0
	struct PIPE3D_172fake phys;  // size=12, offset=0
};

struct _FXHalvePlane // hashcode: 0x10EBCD5A (dec: 283888986)
{
	void *next;						  // size=0, offset=0 //  hashcode: 0xDC2D21CA (dec: -601022006), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;			  // size=0, offset=4 //  hashcode: 0xA470B66F (dec: -1536117137), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance;		  // size=616, offset=8 //  hashcode: 0x60B8C40E (dec: 1622721550), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;		  // size=0, offset=12 //  hashcode: 0xABEFF58A (dec: -1410337398), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;				  // size=0, offset=13 //  hashcode: 0xEC38C608 (dec: -331823608), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;					  // size=0, offset=14 //  hashcode: 0x5057CEDF (dec: 1347931871), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	long diffTime;					  // size=0, offset=16 //  hashcode: 0xC54CA347 (dec: -984833209), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _PlaneConstants ringPlane; // size=12, offset=20 //  hashcode: 0x159D38D6 (dec: 362625238), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	long currentColor;				  // size=0, offset=32 //  hashcode: 0xADD90AA6 (dec: -1378284890), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	long *colorArray;				  // size=0, offset=36 //  hashcode: 0x2AD72B1E (dec: 718744350), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numColors;				  // size=0, offset=40 //  hashcode: 0x38FB83FA (dec: 956007418), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	short colorBlendLife;			  // size=0, offset=42 //  hashcode: 0xA5AFBD2B (dec: -1515209429), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXGlowEffect // hashcode: 0xCE07D6ED (dec: -838347027)
{
	void *next;					// size=0, offset=0 //  hashcode: 0x777F7481 (dec: 2004841601), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;		// size=0, offset=4 //  hashcode: 0x55BD79D8 (dec: 1438480856), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=8 //  hashcode: 0x6BEF8EF7 (dec: 1810861815), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;   // size=0, offset=12 //  hashcode: 0x329F814F (dec: 849314127), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;			// size=0, offset=13 //  hashcode: 0xA008D8E8 (dec: -1610032920), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;				// size=0, offset=14 //  hashcode: 0x29406ED8 (dec: 692088536), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long diffTime;		// size=0, offset=16 //  hashcode: 0x50635F30 (dec: 1348689712), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	long *colorArray;			// size=0, offset=20 //  hashcode: 0xF7D999F1 (dec: -136734223), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	long currentColor;			// size=0, offset=24 //  hashcode: 0x4FFEAC23 (dec: 1342090275), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numColors;			// size=0, offset=28 //  hashcode: 0xF2FCC473 (dec: -218315661), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short colorBlendCycle;		// size=0, offset=30 //  hashcode: 0x4611B94D (dec: 1175566669), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short width;				// size=0, offset=32 //  hashcode: 0x20FDA4D4 (dec: 553493716), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short height;				// size=0, offset=34 //  hashcode: 0x257D4FBE (dec: 628969406), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numSegments;  // size=0, offset=36 //  hashcode: 0xC7DEE4C1 (dec: -941693759), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char SegmentInc;   // size=0, offset=37 //  hashcode: 0x6A55D8BB (dec: 1784010939), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short segment;				// size=0, offset=38 //  hashcode: 0x1770CBBF (dec: 393268159), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadein_time;			// size=0, offset=40 //  hashcode: 0x824E46D3 (dec: -2108799277), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadeout_time;			// size=0, offset=42 //  hashcode: 0xBB96D08E (dec: -1147744114), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PIPE3D_199fake // Hashcode: 0x416C539D (dec: 1097618333)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct PIPE3D_239fake // hashcode: 0x11DBF281 (dec: 299627137)
{
	long m[3]; // size=12, offset=0 //  hashcode: 0x2A949B75 (dec: 714382197), parent name: 'PIPE3D_239fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PIPE3D_240fake // hashcode: 0xB73CD4A8 (dec: -1220750168)
{
	long m[5]; // size=20, offset=0 //  hashcode: 0xA189F73E (dec: -1584793794), parent name: 'PIPE3D_240fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TransformAnimatedInstanceVerticesWork_t // hashcode: 0x7584B74F (dec: 1971631951)
{
	struct MATRIX scTransform;  // size=32, offset=0 //  hashcode: 0xB2FFA2EF (dec: -1291869457), parent name: 'TransformAnimatedInstanceVerticesWork_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX mirrorMatrix; // size=32, offset=32 //  hashcode: 0xDFB5D800 (dec: -541730816), parent name: 'TransformAnimatedInstanceVerticesWork_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX llm;			// size=32, offset=64 //  hashcode: 0xCC85C1FB (dec: -863649285), parent name: 'TransformAnimatedInstanceVerticesWork_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Vector vector;		// size=12, offset=96 //  hashcode: 0x703980D9 (dec: 1882816729), parent name: 'TransformAnimatedInstanceVerticesWork_t', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct POLY_FT3 POLY_FT3;

typedef struct _Mirror Mirror;

typedef struct _FXHalvePlane FXHalvePlane;

typedef struct _FXGlowEffect FXGlowEffect;

typedef struct TransformAnimatedInstanceVerticesWork_t TransformAnimatedInstanceVerticesWork_t;

extern void PIPE3D_AspectAdjustMatrix(struct MATRIX *matrix); // 0x8003A1F0

extern void PIPE3D_CalculateWCTransform(struct _CameraCore_Type *cameraCore); // 0x8003A278

extern void PIPE3D_InvertTransform(struct MATRIX *target, struct MATRIX *source); // 0x8003A5F4

extern long PIPE3D_MatrixColumnLength(struct MATRIX *transform, long column); // 0x8003A688

extern void PIPE3D_NormalizeMatrix(struct MATRIX *target, struct MATRIX *source); // 0x8003A6C4

extern void PIPE3D_TransformVerticesToWorld(struct _Instance *instance, struct _SVector *poolVertex, long *vtxSegment, struct _Vector *Average); // 0x8003A7B0

extern void PIPE3D_InstanceTransformAndDraw(struct _Instance *instance, struct _CameraCore_Type *cameraCore, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _Mirror *mirror); // 0x8003AADC

extern void PIPE3D_InstanceListTransformAndDrawFunc(struct _StreamUnit *unit, unsigned long **ot, struct _CameraCore_Type *cameraCore, struct _Instance *instance); // 0x8003ADD0

extern void PIPE3D_InstanceListTransformAndDraw(struct _StreamUnit *unit, struct GameTracker *gameTracker, unsigned long **ot, struct _CameraCore_Type *cameraCore); // 0x8003B120

extern void PIPE3D_TransformFromZAxis(struct MATRIX *transform, struct _SVector *normal); // 0x8003B218

extern void PIPE3D_CalcWorldToSplitPlaneTransform(struct MATRIX *wpTransform, struct _SVector *normal, struct _SVector *translation); // 0x8003B408

extern long PIPE3D_TransformAnimatedSplitInstanceVertices(struct _MVertex *vertexList, struct _PVertex *poolVertex, struct _Model *model, struct MATRIX *wcTransform, struct MATRIX *matrixPool, struct _Mirror *mirror, struct MATRIX *lm, struct CVECTOR *vertexColor, struct CVECTOR *vertexSrcCol); // 0x8003B4DC

extern void PIPE3D_TransformSplitInstanceVertices(struct _MVertex *vertexList, struct _PVertex *pvertex, struct _Model *model, struct MATRIX *wpTransform, struct MATRIX *matrixPool, struct _Mirror *mirror); // 0x8003BAA8

extern void PIPE3D_AnimateTextures(struct AniTex *aniTextures, long req_frame); // 0x8003BC1C

extern void PIPE3D_AnimateTerrainTextures(struct DrMoveAniTex *aniTextures, long req_frame, struct _PrimPool *primPool, unsigned long **drawot); // 0x8003BCBC

extern void PIPE3D_HalvePlaneInstanceTransformAndDraw(struct _Instance *instance, struct MATRIX *wcTransform, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _Mirror *mirror); // 0x8003BE54

extern void PIPE3D_HalvePlaneGetRingPoints(struct _Instance *instance, struct MATRIX *wcTransform, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _FXHalvePlane *ring); // 0x8003C048

extern void PIPE3D_DoGlow(struct _Instance *instance, struct MATRIX *wcTransform, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _FXGlowEffect *glow); // 0x8003C218

extern long PIPE3D_Segment2ScreenPt(struct _Instance *instance, struct MATRIX *wcTransform, int segIndex, struct _Position *pos); // 0x8003C5F4

#endif
