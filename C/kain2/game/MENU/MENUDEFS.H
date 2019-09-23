#ifndef MENUDEFS_H
#define MENUDEFS_H

static int hack_attract; // offset 0x800CFA70

static int hack_attract_movie; // offset 0x800CFA74

static int hack_reset_attract; // offset 0x800CFA68

static int ITEMSKIP; // offset 0x800CFA64

static int LINESKIP; // offset 0x800CFA60

static int MAIN_WIDTH; // offset 0x800CFA54

static int MAIN_XPOS; // offset 0x800CFA50

static int MAIN_YPOS; // offset 0x800CFA48

static int PAUSE_WIDTH; // offset 0x800CFA5C

static int PAUSE_XPOS; // offset 0x800CFA58

static int PAUSE_YPOS; // offset 0x800CFA4C

static int StartGameFading; // offset 0x800CFA6C

static char(*the_attract_movies[4]); // offset 0x800CADC8

struct MENUDEFS_68fake // hashcode: 0x6446B8F2 (dec: 1682356466)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x98041721 (dec: -1744562399), parent name: 'MENUDEFS_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x122F3911 (dec: 305084689), parent name: 'MENUDEFS_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_69fake // hashcode: 0x31471EE7 (dec: 826744551)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xA83113FE (dec: -1473178626), parent name: 'MENUDEFS_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xD201BC72 (dec: -771638158), parent name: 'MENUDEFS_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_70fake // hashcode: 0xB3D6C282 (dec: -1277771134)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xFDB69DF9 (dec: -38363655), parent name: 'MENUDEFS_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x072AC37E (dec: 120243070), parent name: 'MENUDEFS_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MENUDEFS_71fake // Hashcode: 0x2BC919B9 (dec: 734599609)
{
	struct MENUDEFS_68fake callback; // size=8, offset=0
	struct MENUDEFS_69fake vector;   // size=12, offset=0
	struct MENUDEFS_70fake quat;	 // size=16, offset=0
};

union MENUDEFS_72fake // Hashcode: 0x8E6F3A2D (dec: -1905313235)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MENUDEFS_73fake // Hashcode: 0x4D29C0AB (dec: 1294581931)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct MENUDEFS_74fake // hashcode: 0xCFF2A6E2 (dec: -806181150)
{
	union MENUDEFS_73fake size; // size=4, offset=0 //  hashcode: 0x1E79D839 (dec: 511301689), parent name: 'MENUDEFS_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_75fake // hashcode: 0x08089263 (dec: 134779491)
{
	short x;				// size=0, offset=0 //  hashcode: 0xA8392641 (dec: -1472649663), parent name: 'MENUDEFS_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xDBD2B5E7 (dec: -606947865), parent name: 'MENUDEFS_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x2A44C9B9 (dec: 709151161), parent name: 'MENUDEFS_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x34DA452B (dec: 886719787), parent name: 'MENUDEFS_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x4218D8DD (dec: 1108924637), parent name: 'MENUDEFS_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_76fake // hashcode: 0x4774DAD3 (dec: 1198840531)
{
	long index; // size=0, offset=0 //  hashcode: 0x52825786 (dec: 1384273798), parent name: 'MENUDEFS_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x125E98DF (dec: 308189407), parent name: 'MENUDEFS_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_77fake // hashcode: 0xCF96A98F (dec: -812209777)
{
	long index; // size=0, offset=0 //  hashcode: 0xE3219418 (dec: -484338664), parent name: 'MENUDEFS_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x142D22AC (dec: 338502316), parent name: 'MENUDEFS_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_78fake // hashcode: 0x9591BCB4 (dec: -1785611084)
{
	long index; // size=0, offset=0 //  hashcode: 0xAA234372 (dec: -1440529550), parent name: 'MENUDEFS_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xBAEE6E46 (dec: -1158779322), parent name: 'MENUDEFS_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_79fake // hashcode: 0xA12CC162 (dec: -1590902430)
{
	long time;  // size=0, offset=0 //  hashcode: 0xA96B4E3C (dec: -1452585412), parent name: 'MENUDEFS_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xF8421D37 (dec: -129884873), parent name: 'MENUDEFS_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_80fake // hashcode: 0xA850189C (dec: -1471145828)
{
	long action;   // size=0, offset=0 //  hashcode: 0x11B59655 (dec: 297113173), parent name: 'MENUDEFS_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x88810ADB (dec: -2004808997), parent name: 'MENUDEFS_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_81fake // hashcode: 0x4B34F90F (dec: 1261762831)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xA4112DA3 (dec: -1542378077), parent name: 'MENUDEFS_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x1C5FB7A8 (dec: 476034984), parent name: 'MENUDEFS_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_82fake // hashcode: 0x7BE2535F (dec: 2078430047)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xCB2D9704 (dec: -886204668), parent name: 'MENUDEFS_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x9C55675D (dec: -1672124579), parent name: 'MENUDEFS_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_83fake // hashcode: 0x5ADFED55 (dec: 1524624725)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x2DE34D02 (dec: 769871106), parent name: 'MENUDEFS_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xB085D661 (dec: -1333406111), parent name: 'MENUDEFS_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_84fake // hashcode: 0x89DD4CDA (dec: -1981985574)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x546FBBDD (dec: 1416608733), parent name: 'MENUDEFS_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x72EFA104 (dec: 1928306948), parent name: 'MENUDEFS_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xC959F3BC (dec: -916851780), parent name: 'MENUDEFS_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xF083EA76 (dec: -259790218), parent name: 'MENUDEFS_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x9DF529B8 (dec: -1644877384), parent name: 'MENUDEFS_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_85fake // hashcode: 0x36C6A7F2 (dec: 918988786)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x8F5A7CB6 (dec: -1889895242), parent name: 'MENUDEFS_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xE26253BE (dec: -496872514), parent name: 'MENUDEFS_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_86fake // hashcode: 0x4248A4C8 (dec: 1112057032)
{
	short index;					// size=0, offset=0 //  hashcode: 0x1A1CAB1C (dec: 438086428), parent name: 'MENUDEFS_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xFA0C98F0 (dec: -99837712), parent name: 'MENUDEFS_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xD9F63524 (dec: -638175964), parent name: 'MENUDEFS_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xA33D0502 (dec: -1556282110), parent name: 'MENUDEFS_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_87fake // hashcode: 0xE1AADAB2 (dec: -508896590)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x790662CC (dec: 2030461644), parent name: 'MENUDEFS_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x44D460A3 (dec: 1154769059), parent name: 'MENUDEFS_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xD0A0160F (dec: -794814961), parent name: 'MENUDEFS_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_88fake // hashcode: 0x5743A5D7 (dec: 1464051159)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x2788611C (dec: 663249180), parent name: 'MENUDEFS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x27112F2D (dec: 655437613), parent name: 'MENUDEFS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xE0CC4B5F (dec: -523482273), parent name: 'MENUDEFS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x0D317585 (dec: 221345157), parent name: 'MENUDEFS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x066A5315 (dec: 107631381), parent name: 'MENUDEFS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xDFBBB0C3 (dec: -541347645), parent name: 'MENUDEFS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xBC7F564E (dec: -1132505522), parent name: 'MENUDEFS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_89fake // hashcode: 0x15D82C2A (dec: 366488618)
{
	long index;  // size=0, offset=0 //  hashcode: 0x59500840 (dec: 1498417216), parent name: 'MENUDEFS_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xC22D92EB (dec: -1037200661), parent name: 'MENUDEFS_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_90fake // hashcode: 0x46FB79C5 (dec: 1190885829)
{
	short type; // size=0, offset=0 //  hashcode: 0xEE135850 (dec: -300722096), parent name: 'MENUDEFS_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x694623A6 (dec: 1766204326), parent name: 'MENUDEFS_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_91fake // hashcode: 0xFBC2D103 (dec: -71118589)
{
	long time;   // size=0, offset=0 //  hashcode: 0xC5718BE5 (dec: -982414363), parent name: 'MENUDEFS_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x2F96276F (dec: 798369647), parent name: 'MENUDEFS_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_92fake // hashcode: 0x69C56819 (dec: 1774544921)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xD303F122 (dec: -754716382), parent name: 'MENUDEFS_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xBE2D036A (dec: -1104346262), parent name: 'MENUDEFS_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_93fake // hashcode: 0xD8EB2F29 (dec: -655675607)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x504FC11C (dec: 1347404060), parent name: 'MENUDEFS_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x6B1F8C7B (dec: 1797229691), parent name: 'MENUDEFS_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_94fake // hashcode: 0xC04F3AA6 (dec: -1068549466)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x1E9C2AB3 (dec: 513551027), parent name: 'MENUDEFS_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xE9DA2CA1 (dec: -371577695), parent name: 'MENUDEFS_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_95fake // hashcode: 0x41F21748 (dec: 1106384712)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x508B055F (dec: 1351288159), parent name: 'MENUDEFS_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xE664E3E3 (dec: -429595677), parent name: 'MENUDEFS_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x97E1614D (dec: -1746837171), parent name: 'MENUDEFS_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x5BDE068C (dec: 1541277324), parent name: 'MENUDEFS_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_96fake // hashcode: 0x89AA7503 (dec: -1985317629)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x386415B9 (dec: 946083257), parent name: 'MENUDEFS_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x403562F9 (dec: 1077240569), parent name: 'MENUDEFS_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x11C1478E (dec: 297879438), parent name: 'MENUDEFS_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x904CF9B7 (dec: -1874003529), parent name: 'MENUDEFS_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xDEF85025 (dec: -554151899), parent name: 'MENUDEFS_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MENUDEFS_97fake // Hashcode: 0xA6177165 (dec: -1508413083)
{
	struct MENUDEFS_74fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;		 // size=24, offset=0
	struct MENUDEFS_75fake teleport;	 // size=16, offset=0
	struct MENUDEFS_76fake cameraValue;  // size=8, offset=0
	struct MENUDEFS_77fake miscValue;	// size=8, offset=0
	struct MENUDEFS_78fake logicValue;   // size=8, offset=0
	long timer;							 // size=0, offset=0
	long times;							 // size=0, offset=0
	long lightGroup;					 // size=0, offset=0
	long farPlane;						 // size=0, offset=0
	long cameraAdjust;					 // size=0, offset=0
	long cameraMode;					 // size=0, offset=0
	long cameraLock;					 // size=0, offset=0
	long cameraUnlock;					 // size=0, offset=0
	long cameraSmooth;					 // size=0, offset=0
	long cameraTimer;					 // size=0, offset=0
	struct MENUDEFS_79fake cameraShake;  // size=8, offset=0
	long cameraSave;					 // size=0, offset=0
	long cameraRestore;					 // size=0, offset=0
	struct _BGObject *bgObject;			 // size=24, offset=0
	long value[2];						 // size=8, offset=0
	struct MENUDEFS_80fake sound;		 // size=12, offset=0
	void *intro;						 // size=0, offset=0
	long deathZ;						 // size=0, offset=0
	struct MENUDEFS_81fake dsignal;		 // size=8, offset=0
	void *mirror;						 // size=0, offset=0
	long fogNear;						 // size=0, offset=0
	long fogFar;						 // size=0, offset=0
	struct MENUDEFS_82fake gotoFrame;	// size=8, offset=0
	struct MENUDEFS_83fake changeModel;  // size=8, offset=0
	void *vmObject;						 // size=0, offset=0
	struct MENUDEFS_84fake logic;		 // size=8, offset=0
	void *callSignal;					 // size=0, offset=0
	struct _SVector offset;				 // size=8, offset=0
	struct Signal *gotoLabel;			 // size=0, offset=0
	struct Signal *gosubLabel;			 // size=0, offset=0
	struct MENUDEFS_85fake control;		 // size=8, offset=0
	struct MENUDEFS_86fake zSignal;		 // size=12, offset=0
	struct MENUDEFS_87fake StreamLevel;  // size=24, offset=0
	struct MENUDEFS_88fake shards;		 // size=12, offset=0
	struct MENUDEFS_89fake cameraSpline; // size=8, offset=0
	struct MENUDEFS_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;					 // size=0, offset=0
	struct MENUDEFS_91fake introFX;		 // size=8, offset=0
	struct MENUDEFS_92fake introActive;  // size=8, offset=0
	struct MENUDEFS_93fake levelChange;  // size=18, offset=0
	long blendStart;					 // size=0, offset=0
	struct MENUDEFS_94fake setTimes;	 // size=8, offset=0
	struct MENUDEFS_95fake color;		 // size=4, offset=0
	struct MENUDEFS_96fake print;		 // size=12, offset=0
	long slideAngle;					 // size=0, offset=0
};

union MENUDEFS_98fake // Hashcode: 0x1EFA5E0A (dec: 519724554)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union MENUDEFS_103fake // Hashcode: 0xA120D3E0 (dec: -1591684128)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct MENUDEFS_105fake // hashcode: 0x7777602D (dec: 2004312109)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x21843A90 (dec: 562313872), parent name: 'MENUDEFS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xE1FAA7CC (dec: -503666740), parent name: 'MENUDEFS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x3F5E05CB (dec: 1063126475), parent name: 'MENUDEFS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x8C9F02CA (dec: -1935736118), parent name: 'MENUDEFS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x0D05C9E5 (dec: 218483173), parent name: 'MENUDEFS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xCF889983 (dec: -813131389), parent name: 'MENUDEFS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x43C31404 (dec: 1136858116), parent name: 'MENUDEFS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_106fake // hashcode: 0xA44FC125 (dec: -1538277083)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0xFB4551FD (dec: -79343107), parent name: 'MENUDEFS_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xD73566BD (dec: -684366147), parent name: 'MENUDEFS_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xC5CC4E22 (dec: -976466398), parent name: 'MENUDEFS_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_107fake // hashcode: 0x3FC4BB73 (dec: 1069857651)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xEDA76EDA (dec: -307794214), parent name: 'MENUDEFS_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x36FC71B8 (dec: 922513848), parent name: 'MENUDEFS_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x71ED4480 (dec: 1911374976), parent name: 'MENUDEFS_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x0EA33427 (dec: 245576743), parent name: 'MENUDEFS_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xA3679CB1 (dec: -1553490767), parent name: 'MENUDEFS_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_108fake // hashcode: 0x9215CD62 (dec: -1844064926)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x0057E98B (dec: 5761419), parent name: 'MENUDEFS_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x739668C5 (dec: 1939237061), parent name: 'MENUDEFS_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0xE540E589 (dec: -448731767), parent name: 'MENUDEFS_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x1A0E2345 (dec: 437134149), parent name: 'MENUDEFS_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x6254F30F (dec: 1649734415), parent name: 'MENUDEFS_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUDEFS_109fake // hashcode: 0x99AA84CD (dec: -1716878131)
{
	struct MENUDEFS_105fake Cinematic; // size=28, offset=0 //  hashcode: 0x40C2CEA0 (dec: 1086508704), parent name: 'MENUDEFS_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MENUDEFS_106fake Idle;	  // size=20, offset=28 //  hashcode: 0x91534D51 (dec: -1856811695), parent name: 'MENUDEFS_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MENUDEFS_107fake Behind;	// size=28, offset=48 //  hashcode: 0xD814AECF (dec: -669733169), parent name: 'MENUDEFS_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MENUDEFS_108fake Follow;	// size=20, offset=76 //  hashcode: 0x4539EE1F (dec: 1161424415), parent name: 'MENUDEFS_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

enum sfx_t // Hashcode: 0x9EDBE31D (dec: -1629756643)
{
	sfx_sound = 0,
	sfx_music = 1,
	sfx_voice = 2,
	sfx_error = 3,
};

typedef enum sfx_t sfx_t;

extern void do_check_controller(void *gt); // 0x800B8938

extern int do_push_menu(void *gt, long menuparam, enum menu_ctrl_t ctrl); // 0x800B896C

extern int do_pop_menu(void *gt, long param, enum menu_ctrl_t ctrl); // 0x800B89A4

extern int do_function(void *gt, long fnparam, enum menu_ctrl_t ctrl); // 0x800B89DC

extern int do_start_game(void *gt, long parameter, enum menu_ctrl_t ctrl); // 0x800B8A10

extern int do_save_menu(void *gt, long parameter, enum menu_ctrl_t ctrl); // 0x800B8A74

extern void womp_background(char *tim_path); // 0x800B8AB0

extern void play_movie(char *name); // 0x800B8AE8

extern void menudefs_reset_hack_attract_mode(); // 0x800B8B30

extern void check_hack_attract(); // 0x800B8B54

extern int get_volume(void *gt, enum sfx_t sfx); // 0x800B8BC4

extern void set_volume(enum sfx_t sfx, int cooked); // 0x800B8C30

extern int do_sound_adjust(void *gt, long sfxparam, enum menu_ctrl_t ctrl); // 0x800B8CBC

extern void sound_item(void *gt, char *text, enum sfx_t sfx); // 0x800B8D38

extern int menudefs_toggle_dualshock(void *gt, long param, enum menu_ctrl_t ctrl); // 0x800B8D9C

extern int options_menu(void *gt, int index); // 0x800B8E00

extern int main_menu(void *gt, int index); // 0x800B8F48

extern int do_main_menu(void *gt, long param, enum menu_ctrl_t ctrl); // 0x800B904C

extern char *flashStart(); // 0x800B90A0

extern int menudefs_main_menu(void *gt, int index); // 0x800B92A4

extern int menudefs_confirmexit_menu(void *gt, int index); // 0x800B934C

extern int menudefs_pause_menu(void *gt, int index); // 0x800B93F4

#endif
