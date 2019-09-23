#ifndef LOAD3D_H
#define LOAD3D_H

extern char HashExtensions[7][4]; // offset 0x800CE4D0

static struct _LoadStatus loadStatus; // offset 0x800D0D84

struct CdlFILE // hashcode: 0x2EE126E0 (dec: 786507488)
{
	struct CdlLOC pos;  // size=4, offset=0 //  hashcode: 0xF29C5144 (dec: -224636604), parent name: 'CdlFILE', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long size; // size=0, offset=4 //  hashcode: 0x61EC2F6F (dec: 1642868591), parent name: 'CdlFILE', parent hashcode: 0xFFFFFFFF (dec: -1)
	char name[16];		// size=16, offset=8 //  hashcode: 0x891F2FB9 (dec: -1994444871), parent name: 'CdlFILE', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_73fake // hashcode: 0x84F5435F (dec: -2064301217)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x8E30A0C2 (dec: -1909415742), parent name: 'LOAD3D_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x006BD3A6 (dec: 7066534), parent name: 'LOAD3D_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_74fake // hashcode: 0xFAC17EA8 (dec: -87982424)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x1E8FCAB1 (dec: 512740017), parent name: 'LOAD3D_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x7AFA69FD (dec: 2063231485), parent name: 'LOAD3D_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_75fake // hashcode: 0x914F43F0 (dec: -1857076240)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x81629F1E (dec: -2124243170), parent name: 'LOAD3D_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xC3E05EF3 (dec: -1008705805), parent name: 'LOAD3D_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union LOAD3D_76fake // Hashcode: 0x8D4B684D (dec: -1924437939)
{
	struct LOAD3D_73fake callback; // size=8, offset=0
	struct LOAD3D_74fake vector;   // size=12, offset=0
	struct LOAD3D_75fake quat;	 // size=16, offset=0
};

union LOAD3D_77fake // Hashcode: 0xD696E2BF (dec: -694754625)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union LOAD3D_78fake // Hashcode: 0x35E2C7C4 (dec: 904054724)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct LOAD3D_79fake // hashcode: 0xE752CFE7 (dec: -414003225)
{
	union LOAD3D_78fake size; // size=4, offset=0 //  hashcode: 0x6171AA4D (dec: 1634839117), parent name: 'LOAD3D_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_80fake // hashcode: 0xB7158E71 (dec: -1223324047)
{
	short x;				// size=0, offset=0 //  hashcode: 0x1E3C77A1 (dec: 507279265), parent name: 'LOAD3D_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xE3CD7CB2 (dec: -473072462), parent name: 'LOAD3D_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x199BF465 (dec: 429651045), parent name: 'LOAD3D_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x552CB24A (dec: 1428992586), parent name: 'LOAD3D_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xE8099B27 (dec: -402023641), parent name: 'LOAD3D_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_81fake // hashcode: 0xAB635683 (dec: -1419553149)
{
	long index; // size=0, offset=0 //  hashcode: 0x159C1CC1 (dec: 362552513), parent name: 'LOAD3D_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x483885E6 (dec: 1211663846), parent name: 'LOAD3D_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_82fake // hashcode: 0xCF4ED9E9 (dec: -816915991)
{
	long index; // size=0, offset=0 //  hashcode: 0x5536AADD (dec: 1429646045), parent name: 'LOAD3D_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x133B28B8 (dec: 322644152), parent name: 'LOAD3D_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_83fake // hashcode: 0xFA15DAB0 (dec: -99231056)
{
	long index; // size=0, offset=0 //  hashcode: 0xD95F8E7D (dec: -648049027), parent name: 'LOAD3D_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x39E21C9B (dec: 971119771), parent name: 'LOAD3D_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_84fake // hashcode: 0xEE64CE21 (dec: -295383519)
{
	long time;  // size=0, offset=0 //  hashcode: 0x246E3ED4 (dec: 611204820), parent name: 'LOAD3D_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x04BFBEE5 (dec: 79675109), parent name: 'LOAD3D_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_85fake // hashcode: 0x7E7C90B4 (dec: 2122092724)
{
	long action;   // size=0, offset=0 //  hashcode: 0x0077EE68 (dec: 7859816), parent name: 'LOAD3D_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xA8172A14 (dec: -1474876908), parent name: 'LOAD3D_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_86fake // hashcode: 0xB191D952 (dec: -1315841710)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xCD992640 (dec: -845601216), parent name: 'LOAD3D_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xF0D18ED6 (dec: -254701866), parent name: 'LOAD3D_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_87fake // hashcode: 0x41C0D14C (dec: 1103155532)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x88D00098 (dec: -1999634280), parent name: 'LOAD3D_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0xF3D09642 (dec: -204433854), parent name: 'LOAD3D_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_88fake // hashcode: 0x30B81608 (dec: 817370632)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x72495AD1 (dec: 1917410001), parent name: 'LOAD3D_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x6B81AAA7 (dec: 1803659943), parent name: 'LOAD3D_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_89fake // hashcode: 0xD9B9928B (dec: -642149749)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x7EBB0785 (dec: 2126186373), parent name: 'LOAD3D_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x06029660 (dec: 100832864), parent name: 'LOAD3D_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xB3CC9E66 (dec: -1278435738), parent name: 'LOAD3D_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x031303F5 (dec: 51577845), parent name: 'LOAD3D_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x63F20D1D (dec: 1676807453), parent name: 'LOAD3D_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_90fake // hashcode: 0x34381A8F (dec: 876092047)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x94D2EF53 (dec: -1798115501), parent name: 'LOAD3D_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x7DCB8AD3 (dec: 2110491347), parent name: 'LOAD3D_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_91fake // hashcode: 0x95530E13 (dec: -1789719021)
{
	short index;					// size=0, offset=0 //  hashcode: 0x2D70C91D (dec: 762366237), parent name: 'LOAD3D_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xF76216AD (dec: -144566611), parent name: 'LOAD3D_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x0F5CF2D7 (dec: 257749719), parent name: 'LOAD3D_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xAE025A63 (dec: -1375577501), parent name: 'LOAD3D_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_92fake // hashcode: 0xEFA2D22D (dec: -274542035)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xA54A0C80 (dec: -1521873792), parent name: 'LOAD3D_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x021CA108 (dec: 35430664), parent name: 'LOAD3D_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x9A2A4A63 (dec: -1708504477), parent name: 'LOAD3D_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_93fake // hashcode: 0xB9A2791C (dec: -1180534500)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xE9A4079B (dec: -375126117), parent name: 'LOAD3D_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x9E9A98FF (dec: -1634035457), parent name: 'LOAD3D_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xD07E4BEA (dec: -797029398), parent name: 'LOAD3D_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x78C09E7A (dec: 2025889402), parent name: 'LOAD3D_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x197C460A (dec: 427574794), parent name: 'LOAD3D_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xBAA22A57 (dec: -1163777449), parent name: 'LOAD3D_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x08D235E7 (dec: 147994087), parent name: 'LOAD3D_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_94fake // hashcode: 0x0FA4797F (dec: 262437247)
{
	long index;  // size=0, offset=0 //  hashcode: 0x6BC46AD3 (dec: 1808034515), parent name: 'LOAD3D_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xC1E0A1A3 (dec: -1042243165), parent name: 'LOAD3D_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_95fake // hashcode: 0xD59E04BD (dec: -711064387)
{
	short type; // size=0, offset=0 //  hashcode: 0x80ED2B36 (dec: -2131940554), parent name: 'LOAD3D_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xB37D3065 (dec: -1283641243), parent name: 'LOAD3D_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_96fake // hashcode: 0x9D802C1E (dec: -1652544482)
{
	long time;   // size=0, offset=0 //  hashcode: 0xCBFFB33C (dec: -872434884), parent name: 'LOAD3D_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x67140F9A (dec: 1729367962), parent name: 'LOAD3D_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_97fake // hashcode: 0x86988221 (dec: -2036825567)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x60710930 (dec: 1618020656), parent name: 'LOAD3D_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x10FF2962 (dec: 285157730), parent name: 'LOAD3D_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_98fake // hashcode: 0xA2AEBF61 (dec: -1565606047)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x04250D11 (dec: 69537041), parent name: 'LOAD3D_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x798FCCD6 (dec: 2039467222), parent name: 'LOAD3D_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_99fake // hashcode: 0x2452F3FD (dec: 609416189)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x429CD5B9 (dec: 1117574585), parent name: 'LOAD3D_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x2ECBFA99 (dec: 785119897), parent name: 'LOAD3D_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_100fake // hashcode: 0x3D59BDE7 (dec: 1029291495)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x4FA4D9A3 (dec: 1336203683), parent name: 'LOAD3D_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x71F3A57D (dec: 1911793021), parent name: 'LOAD3D_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x1421A22C (dec: 337748524), parent name: 'LOAD3D_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xC750D0C3 (dec: -951004989), parent name: 'LOAD3D_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_101fake // hashcode: 0xA24BE148 (dec: -1572085432)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x7F29D37A (dec: 2133447546), parent name: 'LOAD3D_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x43DEE326 (dec: 1138680614), parent name: 'LOAD3D_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xF57F0BA9 (dec: -176223319), parent name: 'LOAD3D_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xFBC8CED0 (dec: -70725936), parent name: 'LOAD3D_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x5BAA8524 (dec: 1537901860), parent name: 'LOAD3D_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union LOAD3D_102fake // Hashcode: 0x09EAB038 (dec: 166375480)
{
	struct LOAD3D_79fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	  // size=24, offset=0
	struct LOAD3D_80fake teleport;	 // size=16, offset=0
	struct LOAD3D_81fake cameraValue;  // size=8, offset=0
	struct LOAD3D_82fake miscValue;	// size=8, offset=0
	struct LOAD3D_83fake logicValue;   // size=8, offset=0
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
	struct LOAD3D_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				   // size=0, offset=0
	long cameraRestore;				   // size=0, offset=0
	struct _BGObject *bgObject;		   // size=24, offset=0
	long value[2];					   // size=8, offset=0
	struct LOAD3D_85fake sound;		   // size=12, offset=0
	void *intro;					   // size=0, offset=0
	long deathZ;					   // size=0, offset=0
	struct LOAD3D_86fake dsignal;	  // size=8, offset=0
	void *mirror;					   // size=0, offset=0
	long fogNear;					   // size=0, offset=0
	long fogFar;					   // size=0, offset=0
	struct LOAD3D_87fake gotoFrame;	// size=8, offset=0
	struct LOAD3D_88fake changeModel;  // size=8, offset=0
	void *vmObject;					   // size=0, offset=0
	struct LOAD3D_89fake logic;		   // size=8, offset=0
	void *callSignal;				   // size=0, offset=0
	struct _SVector offset;			   // size=8, offset=0
	struct Signal *gotoLabel;		   // size=0, offset=0
	struct Signal *gosubLabel;		   // size=0, offset=0
	struct LOAD3D_90fake control;	  // size=8, offset=0
	struct LOAD3D_91fake zSignal;	  // size=12, offset=0
	struct LOAD3D_92fake StreamLevel;  // size=24, offset=0
	struct LOAD3D_93fake shards;	   // size=12, offset=0
	struct LOAD3D_94fake cameraSpline; // size=8, offset=0
	struct LOAD3D_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				   // size=0, offset=0
	struct LOAD3D_96fake introFX;	  // size=8, offset=0
	struct LOAD3D_97fake introActive;  // size=8, offset=0
	struct LOAD3D_98fake levelChange;  // size=18, offset=0
	long blendStart;				   // size=0, offset=0
	struct LOAD3D_99fake setTimes;	 // size=8, offset=0
	struct LOAD3D_100fake color;	   // size=4, offset=0
	struct LOAD3D_101fake print;	   // size=12, offset=0
	long slideAngle;				   // size=0, offset=0
};

union LOAD3D_103fake // Hashcode: 0xDEAF0373 (dec: -558955661)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union LOAD3D_108fake // Hashcode: 0x808711C7 (dec: -2138631737)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct LOAD3D_110fake // hashcode: 0x7DA23632 (dec: 2107782706)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x5CB74187 (dec: 1555513735), parent name: 'LOAD3D_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xA5E772F4 (dec: -1511558412), parent name: 'LOAD3D_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x02D9279A (dec: 47785882), parent name: 'LOAD3D_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x18F16E96 (dec: 418475670), parent name: 'LOAD3D_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x75F15CA4 (dec: 1978752164), parent name: 'LOAD3D_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x1335A39D (dec: 322282397), parent name: 'LOAD3D_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xB38155A7 (dec: -1283369561), parent name: 'LOAD3D_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_111fake // hashcode: 0x289E3164 (dec: 681455972)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0xCAB66110 (dec: -894017264), parent name: 'LOAD3D_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x9C4FE9C4 (dec: -1672484412), parent name: 'LOAD3D_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xEDC8181E (dec: -305653730), parent name: 'LOAD3D_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_112fake // hashcode: 0xE1FE7C43 (dec: -503415741)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xD63B2225 (dec: -700767707), parent name: 'LOAD3D_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x2B32A1D9 (dec: 724738521), parent name: 'LOAD3D_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x45F25288 (dec: 1173508744), parent name: 'LOAD3D_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x6B694D81 (dec: 1802063233), parent name: 'LOAD3D_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x319E6B08 (dec: 832465672), parent name: 'LOAD3D_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_113fake // hashcode: 0xFF61DD49 (dec: -10363575)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xEA0E9024 (dec: -368144348), parent name: 'LOAD3D_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x118E23AA (dec: 294527914), parent name: 'LOAD3D_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x2B98F693 (dec: 731444883), parent name: 'LOAD3D_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x4DFFCC31 (dec: 1308609585), parent name: 'LOAD3D_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x208CBB9C (dec: 546093980), parent name: 'LOAD3D_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LOAD3D_114fake // hashcode: 0x1C723D51 (dec: 477248849)
{
	struct LOAD3D_110fake Cinematic; // size=28, offset=0 //  hashcode: 0xB241FB12 (dec: -1304298734), parent name: 'LOAD3D_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LOAD3D_111fake Idle;		 // size=20, offset=28 //  hashcode: 0x1241E9C2 (dec: 306309570), parent name: 'LOAD3D_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LOAD3D_112fake Behind;	// size=28, offset=48 //  hashcode: 0x660A56D6 (dec: 1711953622), parent name: 'LOAD3D_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LOAD3D_113fake Follow;	// size=20, offset=76 //  hashcode: 0x9436C102 (dec: -1808350974), parent name: 'LOAD3D_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _LoadStatus // hashcode: 0x3D15BA2C (dec: 1024834092)
{
	struct _ReadQueueEntry currentQueueFile; // size=44, offset=0 //  hashcode: 0xFB0E2667 (dec: -82958745), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long state;								 // size=0, offset=44 //  hashcode: 0xAC0049D0 (dec: -1409267248), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long bytesTransferred;					 // size=0, offset=48 //  hashcode: 0x429F18E0 (dec: 1117722848), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long lastCheckPos;						 // size=0, offset=52 //  hashcode: 0xF09AE050 (dec: -258285488), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long cdWaitTime;						 // size=0, offset=56 //  hashcode: 0x3A057232 (dec: 973435442), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char *compSrcAddr;				 // size=0, offset=60 //  hashcode: 0x5C77AF7C (dec: 1551347580), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char *compDstAddr;				 // size=0, offset=64 //  hashcode: 0x3699AE45 (dec: 916041285), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long compControlbits;					 // size=0, offset=68 //  hashcode: 0xE4610A9E (dec: -463402338), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long compControl;						 // size=0, offset=72 //  hashcode: 0x80A14FC8 (dec: -2136911928), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long compEndBytes;						 // size=0, offset=76 //  hashcode: 0x4C009F1B (dec: 1275109147), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long decompressLen;						 // size=0, offset=80 //  hashcode: 0xD0DB324D (dec: -790941107), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long checksum;							 // size=0, offset=84 //  hashcode: 0x1448D12F (dec: 340316463), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long *checkAddr;						 // size=0, offset=88 //  hashcode: 0xE1734DBB (dec: -512537157), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BigFile bigFile;				 // size=36, offset=92 //  hashcode: 0x04F450D7 (dec: 83120343), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *buffer1;							 // size=0, offset=128 //  hashcode: 0x73E9A110 (dec: 1944690960), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *buffer2;							 // size=0, offset=132 //  hashcode: 0x1CCEBDD8 (dec: 483311064), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	int changeDir;							 // size=0, offset=136 //  hashcode: 0xC7D3EF81 (dec: -942411903), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long endLoadTime;						 // size=0, offset=140 //  hashcode: 0x15C7B22A (dec: 365408810), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long currentDirLoading;					 // size=0, offset=144 //  hashcode: 0x3F63342C (dec: 1063466028), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long currentSector;						 // size=0, offset=148 //  hashcode: 0xB681C35E (dec: -1233009826), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RedirectList // hashcode: 0x4C185B3B (dec: 1276664635)
{
	long numPointers; // size=0, offset=0 //  hashcode: 0xCA632F37 (dec: -899469513), parent name: 'RedirectList', parent hashcode: 0xFFFFFFFF (dec: -1)
	long *data;		  // size=0, offset=4 //  hashcode: 0x37905B9C (dec: 932207516), parent name: 'RedirectList', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct CdlFILE CdlFILE;

typedef struct _LoadStatus LoadStatus;

typedef struct RedirectList RedirectList;

extern void LOAD_InitCd(); // 0x80036D44

extern void LOAD_CdSeekCallback(unsigned char intr, unsigned char *result); // 0x80036D74

extern void LOAD_CdDataReady(); // 0x80036D90

extern void LOAD_CdReadReady(unsigned char intr, unsigned char *result); // 0x80036EB0

extern void LOAD_UpdateCheckSum(long bytes); // 0x80036F9C

extern void LOAD_DoCDReading(); // 0x80036FE0

extern void LOAD_DoCDBufferedReading(); // 0x8003708C

extern void LOAD_SetupFileToDoCDReading(); // 0x800370A8

extern void LOAD_SetupFileToDoBufferedCDReading(); // 0x80037124

extern void LOAD_ProcessReadQueue(); // 0x80037198

extern char *LOAD_ReadFileFromCD(char *filename, int memType); // 0x80037314

extern void LOAD_CdReadFromBigFile(long fileOffset, unsigned long *loadAddr, long bytes, long chksumLevel, long checksum); // 0x800373F4

extern struct _BigFileDir *LOAD_ReadDirectory(struct _BigFileDirEntry *dirEntry); // 0x80037420

extern void LOAD_InitCdLoader(char *bigFileName, char *voiceFileName); // 0x80037488

extern int LOAD_SetupFileInfo(struct _NonBlockLoadEntry *loadEntry); // 0x800375DC

extern void LOAD_CD_ReadPartOfFile(struct _NonBlockLoadEntry *loadEntry); // 0x80037664

extern long LOAD_HashName(char *string); // 0x80037704

extern long LOAD_HashUnit(char *name); // 0x80037858

extern struct _BigFileEntry *LOAD_GetBigFileEntryByHash(long hash); // 0x800378FC

extern struct _BigFileEntry *LOAD_GetBigFileEntry(char *fileName); // 0x80037984

extern long LOAD_DoesFileExist(char *fileName); // 0x800379AC

extern void LOAD_NonBlockingReadFile(struct _NonBlockLoadEntry *loadEntry); // 0x800379E0

extern void LOAD_LoadTIM(long *addr, long x_pos, long y_pos, long clut_x, long clut_y); // 0x80037A9C

extern void LOAD_LoadTIM2(long *addr, long x_pos, long y_pos, long width, long height); // 0x80037B3C

extern long LOAD_RelocBinaryData(long *data, long fileSize); // 0x80037B84

extern void LOAD_CleanUpBuffers(); // 0x80037C3C

extern void *LOAD_InitBuffers(); // 0x80037C84

extern void LOAD_InitCdStreamMode(); // 0x80037CD4

extern void LOAD_DumpCurrentDir(); // 0x80037D1C

extern int LOAD_ChangeDirectoryByID(int id); // 0x80037D6C

extern void LOAD_SetSearchDirectory(long id); // 0x80037E74

extern long LOAD_GetSearchDirectory(); // 0x80037E80

extern int LOAD_ChangeDirectoryFlag(); // 0x80037E8C

extern void LOAD_UpdateBigFilePointers(struct _BigFileDir *oldDir, struct _BigFileDir *newDir); // 0x80037E98

extern int LOAD_IsFileLoading(); // 0x80037EC8

extern void LOAD_StopLoad(); // 0x80037ED4

#endif
