#ifndef MBMISS_H
#define MBMISS_H

struct MBMISS_73fake // hashcode: 0xFD3BF94F (dec: -46401201)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x93331348 (dec: -1825369272), parent name: 'MBMISS_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x863C9C5B (dec: -2042848165), parent name: 'MBMISS_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_74fake // hashcode: 0x029A0B4A (dec: 43649866)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x9CFD22F7 (dec: -1661132041), parent name: 'MBMISS_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x5CB0FFC2 (dec: 1555103682), parent name: 'MBMISS_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_75fake // hashcode: 0xC6CC3752 (dec: -959695022)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xE197EB13 (dec: -510137581), parent name: 'MBMISS_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xEC7FEDB9 (dec: -327160391), parent name: 'MBMISS_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MBMISS_76fake // Hashcode: 0x99AC1F62 (dec: -1716773022)
{
	struct MBMISS_73fake callback; // size=8, offset=0
	struct MBMISS_74fake vector;   // size=12, offset=0
	struct MBMISS_75fake quat;	 // size=16, offset=0
};

union MBMISS_77fake // Hashcode: 0x2A18F047 (dec: 706277447)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MBMISS_78fake // Hashcode: 0xF01A4BF5 (dec: -266712075)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct MBMISS_79fake // hashcode: 0x144EBD4E (dec: 340704590)
{
	union MBMISS_78fake size; // size=4, offset=0 //  hashcode: 0x815C62D2 (dec: -2124651822), parent name: 'MBMISS_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_80fake // hashcode: 0x118BE7F0 (dec: 294381552)
{
	short x;				// size=0, offset=0 //  hashcode: 0x5930F6B3 (dec: 1496381107), parent name: 'MBMISS_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xD8F181C1 (dec: -655261247), parent name: 'MBMISS_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xDA8218FE (dec: -629008130), parent name: 'MBMISS_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x2C4F985C (dec: 743413852), parent name: 'MBMISS_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x9E812246 (dec: -1635704250), parent name: 'MBMISS_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_81fake // hashcode: 0xF730B13C (dec: -147803844)
{
	long index; // size=0, offset=0 //  hashcode: 0x8407C6F5 (dec: -2079865099), parent name: 'MBMISS_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x72E7AD4C (dec: 1927785804), parent name: 'MBMISS_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_82fake // hashcode: 0xABECA0F1 (dec: -1410555663)
{
	long index; // size=0, offset=0 //  hashcode: 0xB30EEAF9 (dec: -1290867975), parent name: 'MBMISS_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x62C874D9 (dec: 1657304281), parent name: 'MBMISS_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_83fake // hashcode: 0x2C3B71C8 (dec: 742093256)
{
	long index; // size=0, offset=0 //  hashcode: 0xEC115499 (dec: -334408551), parent name: 'MBMISS_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x2AAC1797 (dec: 715921303), parent name: 'MBMISS_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_84fake // hashcode: 0x632D48E1 (dec: 1663912161)
{
	long time;  // size=0, offset=0 //  hashcode: 0x95CCFD0E (dec: -1781727986), parent name: 'MBMISS_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xF0E994D1 (dec: -253127471), parent name: 'MBMISS_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_85fake // hashcode: 0xAF416B19 (dec: -1354667239)
{
	long action;   // size=0, offset=0 //  hashcode: 0xC14D096B (dec: -1051915925), parent name: 'MBMISS_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x24069F63 (dec: 604413795), parent name: 'MBMISS_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_86fake // hashcode: 0x5082111D (dec: 1350701341)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x83E87584 (dec: -2081917564), parent name: 'MBMISS_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x8F20AA3B (dec: -1893684677), parent name: 'MBMISS_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_87fake // hashcode: 0x53ED6C86 (dec: 1408068742)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x76BF0A59 (dec: 1992231513), parent name: 'MBMISS_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0xDBC772B6 (dec: -607685962), parent name: 'MBMISS_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_88fake // hashcode: 0x100E17A8 (dec: 269359016)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xAF7B1C5B (dec: -1350886309), parent name: 'MBMISS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xA9BC57AF (dec: -1447274577), parent name: 'MBMISS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_89fake // hashcode: 0x13497110 (dec: 323580176)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x390468BF (dec: 956590271), parent name: 'MBMISS_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x91AF7E2B (dec: -1850769877), parent name: 'MBMISS_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xA3028514 (dec: -1560115948), parent name: 'MBMISS_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xDDF55C93 (dec: -571122541), parent name: 'MBMISS_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xD6777FBF (dec: -696811585), parent name: 'MBMISS_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_90fake // hashcode: 0x9C78788E (dec: -1669826418)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x2B52A31C (dec: 726835996), parent name: 'MBMISS_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xAB0E09BD (dec: -1425143363), parent name: 'MBMISS_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_91fake // hashcode: 0x21069812 (dec: 554080274)
{
	short index;					// size=0, offset=0 //  hashcode: 0xB82FA464 (dec: -1204837276), parent name: 'MBMISS_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xD7A9A382 (dec: -676748414), parent name: 'MBMISS_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x1020F2C5 (dec: 270594757), parent name: 'MBMISS_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xC2BA5A37 (dec: -1027974601), parent name: 'MBMISS_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_92fake // hashcode: 0xA040334F (dec: -1606405297)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xD5BC8E8E (dec: -709063026), parent name: 'MBMISS_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xA4E0715D (dec: -1528794787), parent name: 'MBMISS_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x4E5BDA1E (dec: 1314642462), parent name: 'MBMISS_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_93fake // hashcode: 0xB95075B0 (dec: -1185909328)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x3D83D7DD (dec: 1032050653), parent name: 'MBMISS_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xA765CD34 (dec: -1486500556), parent name: 'MBMISS_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x73E30E3E (dec: 1944260158), parent name: 'MBMISS_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x2FBD8450 (dec: 800949328), parent name: 'MBMISS_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x9F9D56B2 (dec: -1617078606), parent name: 'MBMISS_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xA72D4D18 (dec: -1490203368), parent name: 'MBMISS_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xD542E893 (dec: -717035373), parent name: 'MBMISS_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_94fake // hashcode: 0x96DE7C30 (dec: -1763804112)
{
	long index;  // size=0, offset=0 //  hashcode: 0x736C1AD3 (dec: 1936464595), parent name: 'MBMISS_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x3D3BEDCD (dec: 1027337677), parent name: 'MBMISS_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_95fake // hashcode: 0x56DCE7B2 (dec: 1457317810)
{
	short type; // size=0, offset=0 //  hashcode: 0x1C6B0142 (dec: 476774722), parent name: 'MBMISS_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xCE2D4908 (dec: -835892984), parent name: 'MBMISS_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_96fake // hashcode: 0xFEC7B570 (dec: -20466320)
{
	long time;   // size=0, offset=0 //  hashcode: 0xC243EC39 (dec: -1035736007), parent name: 'MBMISS_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x5EB0B13E (dec: 1588638014), parent name: 'MBMISS_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_97fake // hashcode: 0xCA3BA0A5 (dec: -902061915)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x98AE39F7 (dec: -1733412361), parent name: 'MBMISS_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xC22645BD (dec: -1037679171), parent name: 'MBMISS_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_98fake // hashcode: 0xFACC74D0 (dec: -87264048)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x4F9255DD (dec: 1334990301), parent name: 'MBMISS_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x88CCA618 (dec: -1999854056), parent name: 'MBMISS_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_99fake // hashcode: 0xF67A7999 (dec: -159745639)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xA5D58A45 (dec: -1512732091), parent name: 'MBMISS_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x38D0F1EF (dec: 953217519), parent name: 'MBMISS_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_100fake // hashcode: 0x78E0632A (dec: 2027971370)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x6B81970A (dec: 1803654922), parent name: 'MBMISS_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xA9179BAF (dec: -1458070609), parent name: 'MBMISS_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xB4C4A202 (dec: -1262181886), parent name: 'MBMISS_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x600D365D (dec: 1611478621), parent name: 'MBMISS_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_101fake // hashcode: 0x0ABF539B (dec: 180310939)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x259F9417 (dec: 631215127), parent name: 'MBMISS_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xC857FD9C (dec: -933757540), parent name: 'MBMISS_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x79A8A556 (dec: 2041095510), parent name: 'MBMISS_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x7A3D6001 (dec: 2050842625), parent name: 'MBMISS_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x89E80BCA (dec: -1981281334), parent name: 'MBMISS_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MBMISS_102fake // Hashcode: 0x760406EE (dec: 1979975406)
{
	struct MBMISS_79fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	  // size=24, offset=0
	struct MBMISS_80fake teleport;	 // size=16, offset=0
	struct MBMISS_81fake cameraValue;  // size=8, offset=0
	struct MBMISS_82fake miscValue;	// size=8, offset=0
	struct MBMISS_83fake logicValue;   // size=8, offset=0
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
	struct MBMISS_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				   // size=0, offset=0
	long cameraRestore;				   // size=0, offset=0
	struct _BGObject *bgObject;		   // size=24, offset=0
	long value[2];					   // size=8, offset=0
	struct MBMISS_85fake sound;		   // size=12, offset=0
	void *intro;					   // size=0, offset=0
	long deathZ;					   // size=0, offset=0
	struct MBMISS_86fake dsignal;	  // size=8, offset=0
	void *mirror;					   // size=0, offset=0
	long fogNear;					   // size=0, offset=0
	long fogFar;					   // size=0, offset=0
	struct MBMISS_87fake gotoFrame;	// size=8, offset=0
	struct MBMISS_88fake changeModel;  // size=8, offset=0
	void *vmObject;					   // size=0, offset=0
	struct MBMISS_89fake logic;		   // size=8, offset=0
	void *callSignal;				   // size=0, offset=0
	struct _SVector offset;			   // size=8, offset=0
	struct Signal *gotoLabel;		   // size=0, offset=0
	struct Signal *gosubLabel;		   // size=0, offset=0
	struct MBMISS_90fake control;	  // size=8, offset=0
	struct MBMISS_91fake zSignal;	  // size=12, offset=0
	struct MBMISS_92fake StreamLevel;  // size=24, offset=0
	struct MBMISS_93fake shards;	   // size=12, offset=0
	struct MBMISS_94fake cameraSpline; // size=8, offset=0
	struct MBMISS_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				   // size=0, offset=0
	struct MBMISS_96fake introFX;	  // size=8, offset=0
	struct MBMISS_97fake introActive;  // size=8, offset=0
	struct MBMISS_98fake levelChange;  // size=18, offset=0
	long blendStart;				   // size=0, offset=0
	struct MBMISS_99fake setTimes;	 // size=8, offset=0
	struct MBMISS_100fake color;	   // size=4, offset=0
	struct MBMISS_101fake print;	   // size=12, offset=0
	long slideAngle;				   // size=0, offset=0
};

union MBMISS_103fake // Hashcode: 0x288C00D7 (dec: 680263895)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union MBMISS_108fake // Hashcode: 0xA778A8A7 (dec: -1485264729)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct MBMISS_110fake // hashcode: 0xEB04A351 (dec: -352017583)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xF5186EF3 (dec: -182948109), parent name: 'MBMISS_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x7F4ADCAA (dec: 2135612586), parent name: 'MBMISS_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0xC2EE1B31 (dec: -1024582863), parent name: 'MBMISS_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x70F969C1 (dec: 1895393729), parent name: 'MBMISS_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x2DF4CFA6 (dec: 771018662), parent name: 'MBMISS_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x089376C8 (dec: 143881928), parent name: 'MBMISS_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xCFA12A93 (dec: -811521389), parent name: 'MBMISS_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_111fake // hashcode: 0xFA718976 (dec: -93222538)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x5FD39C76 (dec: 1607703670), parent name: 'MBMISS_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xBD20E220 (dec: -1121918432), parent name: 'MBMISS_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x998AA7B7 (dec: -1718966345), parent name: 'MBMISS_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_112fake // hashcode: 0x49230A1B (dec: 1227033115)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x5A10F859 (dec: 1511061593), parent name: 'MBMISS_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xD400937D (dec: -738159747), parent name: 'MBMISS_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xF69E299E (dec: -157406818), parent name: 'MBMISS_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x2DC34A25 (dec: 767773221), parent name: 'MBMISS_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x1C24658B (dec: 472147339), parent name: 'MBMISS_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_113fake // hashcode: 0x37E487F5 (dec: 937723893)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xA6C1A96B (dec: -1497257621), parent name: 'MBMISS_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0xB9D92826 (dec: -1176950746), parent name: 'MBMISS_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x18C08662 (dec: 415270498), parent name: 'MBMISS_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x2CC1090C (dec: 750848268), parent name: 'MBMISS_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x5BF4EB68 (dec: 1542777704), parent name: 'MBMISS_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_114fake // hashcode: 0x8D708B2D (dec: -1922004179)
{
	struct MBMISS_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x6FE8F6E5 (dec: 1877538533), parent name: 'MBMISS_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MBMISS_111fake Idle;		 // size=20, offset=28 //  hashcode: 0x732C0673 (dec: 1932265075), parent name: 'MBMISS_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MBMISS_112fake Behind;	// size=28, offset=48 //  hashcode: 0x997E3981 (dec: -1719780991), parent name: 'MBMISS_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MBMISS_113fake Follow;	// size=20, offset=76 //  hashcode: 0x0A003B00 (dec: 167787264), parent name: 'MBMISS_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_176fake // hashcode: 0x0726431E (dec: 119948062)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x8B537281 (dec: -1957465471), parent name: 'MBMISS_176fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x2641C16E (dec: 641843566), parent name: 'MBMISS_176fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MBMISS_177fake // hashcode: 0x7023E8BA (dec: 1881401530)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x621E4376 (dec: 1646150518), parent name: 'MBMISS_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x33ADE6F5 (dec: 867034869), parent name: 'MBMISS_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0xD3A77702 (dec: -743999742), parent name: 'MBMISS_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x584A4D2C (dec: 1481264428), parent name: 'MBMISS_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0xCD6C7352 (dec: -848530606), parent name: 'MBMISS_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0xCC35EC1C (dec: -868881380), parent name: 'MBMISS_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MBMISS_178fake // Hashcode: 0xD332E4B2 (dec: -751639374)
{
	struct MBMISS_176fake flame; // size=8, offset=0
	struct MBMISS_177fake phys;  // size=12, offset=0
};

union MBMISS_212fake // Hashcode: 0xA059CF55 (dec: -1604726955)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct MBMISS_259fake // hashcode: 0x7210321E (dec: 1913664030)
{
	short plusDelta;	   // size=0, offset=0 //  hashcode: 0x2AB723C5 (dec: 716645317), parent name: 'MBMISS_259fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minusDelta;	  // size=0, offset=2 //  hashcode: 0x38800A5F (dec: 947915359), parent name: 'MBMISS_259fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short validAtHitPoint; // size=0, offset=4 //  hashcode: 0xE17C8E4C (dec: -511930804), parent name: 'MBMISS_259fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _walbossAttributes // hashcode: 0x300B2C35 (dec: 806038581)
{
	unsigned char segmentToAttach;		   // size=0, offset=0 //  hashcode: 0x8C902B70 (dec: -1936708752), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char frameToBirth;			   // size=0, offset=1 //  hashcode: 0xDB6E3C5C (dec: -613532580), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char frameToExpel;			   // size=0, offset=2 //  hashcode: 0xA22AF524 (dec: -1574243036), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char maxEggHits;			   // size=0, offset=3 //  hashcode: 0x32A2AEA7 (dec: 849522343), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxAngle;						   // size=0, offset=4 //  hashcode: 0x8377CDE0 (dec: -2089300512), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeForHitAgony;				   // size=0, offset=6 //  hashcode: 0x41DB7361 (dec: 1104900961), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short segmentForBodyTwist;			   // size=0, offset=8 //  hashcode: 0x264EB3FF (dec: 642692095), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeToThornPrep;				   // size=0, offset=10 //  hashcode: 0xF48F4E72 (dec: -191934862), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeToThornPoke;				   // size=0, offset=12 //  hashcode: 0x7D28407E (dec: 2099789950), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeToEggThrob;				   // size=0, offset=14 //  hashcode: 0xC58E2F7C (dec: -980537476), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeToEggExplode;				   // size=0, offset=16 //  hashcode: 0xACC23E7F (dec: -1396556161), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short razielStunTime;				   // size=0, offset=18 //  hashcode: 0x76664F1A (dec: 1986416410), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short eggIgniteDist;				   // size=0, offset=20 //  hashcode: 0x78D81C03 (dec: 2027428867), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short angleForShortAttack;			   // size=0, offset=22 //  hashcode: 0x7B2C3115 (dec: 2066493717), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short closeAttackStart;				   // size=0, offset=24 //  hashcode: 0x5E1CBDFE (dec: 1578941950), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short junk;							   // size=0, offset=26 //  hashcode: 0x76D82621 (dec: 1993877025), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MBMISS_259fake attackDeltas[0]; // size=0, offset=28 //  hashcode: 0xCC304422 (dec: -869252062), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct _walbossAttributes WalbossAttributes;

extern void WCBEGG_Message(struct _Instance *instance, unsigned long message, unsigned long data); // 0x8008EFA8

extern int WCBEGG_ShouldIgniteEgg(struct _Instance *egg, struct _walbossAttributes *wa); // 0x8008F04C

extern void WCBEGG_Process(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008F144

extern void WCBEGG_ExplodeProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008F338

extern void WCBEGG_SplitProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008F478

extern void WCBEGG_CommonPostProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008F574

extern void WCBEGG_CommonPostProcess2(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008F604

extern void WCBEGG_ExplodeCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008F678

extern void WCBEGG_Collide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008F7FC

extern long WALBOSC_AnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, struct _Instance *instance); // 0x8008F884

extern void WALBOSC_Collide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008F904

extern void WALBOSC_Message(struct _Instance *instance, unsigned long message, unsigned long data); // 0x8008F9C4

#endif
