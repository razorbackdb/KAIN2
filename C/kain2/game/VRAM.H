#ifndef VRAM_H
#define VRAM_H

extern struct _BlockVramEntry *openVramBlocks; // offset 0x800D482C

extern struct _BlockVramEntry TerrainVramBlock; // offset 0x800D480C

extern struct _BlockVramEntry *usedVramBlocks; // offset 0x800D4828

extern struct _BlockVramEntry vramBlockList[90]; // offset 0x800D3E2C

struct VRAM_73fake // hashcode: 0x1AB73E07 (dec: 448216583)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x83051A20 (dec: -2096817632), parent name: 'VRAM_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0xD6FBB27D (dec: -688147843), parent name: 'VRAM_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_74fake // hashcode: 0x486723DE (dec: 1214718942)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xE0A2BDDC (dec: -526205476), parent name: 'VRAM_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xB57F1CA6 (dec: -1249960794), parent name: 'VRAM_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_75fake // hashcode: 0xE81718BE (dec: -401139522)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x36FDA523 (dec: 922592547), parent name: 'VRAM_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xADFD541D (dec: -1375906787), parent name: 'VRAM_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union VRAM_76fake // Hashcode: 0xFB5FC5A7 (dec: -77609561)
{
	struct VRAM_73fake callback; // size=8, offset=0
	struct VRAM_74fake vector;   // size=12, offset=0
	struct VRAM_75fake quat;	 // size=16, offset=0
};

union VRAM_77fake // Hashcode: 0xE4B92D7A (dec: -457626246)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union VRAM_78fake // Hashcode: 0xFDD22514 (dec: -36559596)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct VRAM_79fake // hashcode: 0x6B86011E (dec: 1803944222)
{
	union VRAM_78fake size; // size=4, offset=0 //  hashcode: 0xB78EC45C (dec: -1215380388), parent name: 'VRAM_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_80fake // hashcode: 0xF79F8DB2 (dec: -140538446)
{
	short x;				// size=0, offset=0 //  hashcode: 0xAF5E8474 (dec: -1352760204), parent name: 'VRAM_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x9C6B1B30 (dec: -1670702288), parent name: 'VRAM_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x6F517A5D (dec: 1867610717), parent name: 'VRAM_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x001164CC (dec: 1139916), parent name: 'VRAM_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xD392A0A5 (dec: -745365339), parent name: 'VRAM_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_81fake // hashcode: 0x59F039B7 (dec: 1508915639)
{
	long index; // size=0, offset=0 //  hashcode: 0xF0C34A5A (dec: -255636902), parent name: 'VRAM_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x03D381F3 (dec: 64193011), parent name: 'VRAM_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_82fake // hashcode: 0x5EE79EAA (dec: 1592237738)
{
	long index; // size=0, offset=0 //  hashcode: 0x2BA38154 (dec: 732135764), parent name: 'VRAM_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xE95856BF (dec: -380086593), parent name: 'VRAM_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_83fake // hashcode: 0x36F9E4F9 (dec: 922346745)
{
	long index; // size=0, offset=0 //  hashcode: 0x0F0CA20E (dec: 252486158), parent name: 'VRAM_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xED7CF8BF (dec: -310576961), parent name: 'VRAM_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_84fake // hashcode: 0x9368DDCC (dec: -1821844020)
{
	long time;  // size=0, offset=0 //  hashcode: 0xEF296497 (dec: -282499945), parent name: 'VRAM_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x7E8F5058 (dec: 2123321432), parent name: 'VRAM_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_85fake // hashcode: 0x83F0F99B (dec: -2081359461)
{
	long action;   // size=0, offset=0 //  hashcode: 0x61B389F6 (dec: 1639156214), parent name: 'VRAM_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x9A5903A7 (dec: -1705442393), parent name: 'VRAM_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_86fake // hashcode: 0xF0379F7D (dec: -264790147)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xD181BA8F (dec: -780027249), parent name: 'VRAM_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x563B6608 (dec: 1446733320), parent name: 'VRAM_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_87fake // hashcode: 0x98321D08 (dec: -1741546232)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x8263C6FA (dec: -2107390214), parent name: 'VRAM_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x5CBD1ED6 (dec: 1555898070), parent name: 'VRAM_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_88fake // hashcode: 0xE1EED97B (dec: -504440453)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x849964CC (dec: -2070321972), parent name: 'VRAM_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x221EE0CC (dec: 572448972), parent name: 'VRAM_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_89fake // hashcode: 0x52DEECC4 (dec: 1390341316)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x8B58FA3C (dec: -1957103044), parent name: 'VRAM_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xA7529257 (dec: -1487760809), parent name: 'VRAM_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xCD1E428A (dec: -853654902), parent name: 'VRAM_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xBE655BC6 (dec: -1100653626), parent name: 'VRAM_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xFA2E88A7 (dec: -97613657), parent name: 'VRAM_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_90fake // hashcode: 0x89E27915 (dec: -1981646571)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xD09D1D9A (dec: -795009638), parent name: 'VRAM_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xB8B33D64 (dec: -1196212892), parent name: 'VRAM_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_91fake // hashcode: 0x7B473432 (dec: 2068263986)
{
	short index;					// size=0, offset=0 //  hashcode: 0xAC9A9898 (dec: -1399154536), parent name: 'VRAM_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xA4101DFA (dec: -1542447622), parent name: 'VRAM_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x8420C759 (dec: -2078226599), parent name: 'VRAM_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xFCB3192E (dec: -55371474), parent name: 'VRAM_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_92fake // hashcode: 0x8D0412F1 (dec: -1929112847)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x25C04E2F (dec: 633359919), parent name: 'VRAM_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x72BBD756 (dec: 1924912982), parent name: 'VRAM_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x15191E3B (dec: 353967675), parent name: 'VRAM_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_93fake // hashcode: 0xF0D0EF2E (dec: -254742738)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x9201965D (dec: -1845389731), parent name: 'VRAM_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x979A9645 (dec: -1751476667), parent name: 'VRAM_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xD12DC543 (dec: -785529533), parent name: 'VRAM_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xA5E100B1 (dec: -1511980879), parent name: 'VRAM_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xA1D5966D (dec: -1579837843), parent name: 'VRAM_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x8791C64A (dec: -2020489654), parent name: 'VRAM_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xF0D249EA (dec: -254653974), parent name: 'VRAM_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_94fake // hashcode: 0x9A804266 (dec: -1702870426)
{
	long index;  // size=0, offset=0 //  hashcode: 0x5757F397 (dec: 1465381783), parent name: 'VRAM_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x7F474362 (dec: 2135376738), parent name: 'VRAM_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_95fake // hashcode: 0xA8D72786 (dec: -1462294650)
{
	short type; // size=0, offset=0 //  hashcode: 0xB5937611 (dec: -1248627183), parent name: 'VRAM_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xCF933673 (dec: -812435853), parent name: 'VRAM_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_96fake // hashcode: 0x5CC960CB (dec: 1556701387)
{
	long time;   // size=0, offset=0 //  hashcode: 0x5C30BA61 (dec: 1546697313), parent name: 'VRAM_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x00E2C75B (dec: 14862171), parent name: 'VRAM_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_97fake // hashcode: 0xE74CF155 (dec: -414387883)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x344DB1D6 (dec: 877507030), parent name: 'VRAM_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xF5490500 (dec: -179763968), parent name: 'VRAM_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_98fake // hashcode: 0x57119039 (dec: 1460768825)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x23349CF9 (dec: 590650617), parent name: 'VRAM_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xE6847ED1 (dec: -427524399), parent name: 'VRAM_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_99fake // hashcode: 0x0BDBEC9C (dec: 198962332)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xC0DC04C4 (dec: -1059322684), parent name: 'VRAM_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x1D81D2E2 (dec: 495047394), parent name: 'VRAM_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_100fake // hashcode: 0x8E11394D (dec: -1911473843)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x7CA641BE (dec: 2091270590), parent name: 'VRAM_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x09755335 (dec: 158683957), parent name: 'VRAM_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x399F5779 (dec: 966743929), parent name: 'VRAM_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xBFA01BD5 (dec: -1080026155), parent name: 'VRAM_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_101fake // hashcode: 0x544E01F0 (dec: 1414398448)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x5487EE35 (dec: 1418194485), parent name: 'VRAM_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x1D692D87 (dec: 493432199), parent name: 'VRAM_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x60F0CFE2 (dec: 1626394594), parent name: 'VRAM_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x5D9A2099 (dec: 1570381977), parent name: 'VRAM_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x17C0E966 (dec: 398518630), parent name: 'VRAM_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union VRAM_102fake // Hashcode: 0x19A101D8 (dec: 429982168)
{
	struct VRAM_79fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;	// size=24, offset=0
	struct VRAM_80fake teleport;	 // size=16, offset=0
	struct VRAM_81fake cameraValue;  // size=8, offset=0
	struct VRAM_82fake miscValue;	// size=8, offset=0
	struct VRAM_83fake logicValue;   // size=8, offset=0
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
	struct VRAM_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				 // size=0, offset=0
	long cameraRestore;				 // size=0, offset=0
	struct _BGObject *bgObject;		 // size=24, offset=0
	long value[2];					 // size=8, offset=0
	struct VRAM_85fake sound;		 // size=12, offset=0
	void *intro;					 // size=0, offset=0
	long deathZ;					 // size=0, offset=0
	struct VRAM_86fake dsignal;		 // size=8, offset=0
	void *mirror;					 // size=0, offset=0
	long fogNear;					 // size=0, offset=0
	long fogFar;					 // size=0, offset=0
	struct VRAM_87fake gotoFrame;	// size=8, offset=0
	struct VRAM_88fake changeModel;  // size=8, offset=0
	void *vmObject;					 // size=0, offset=0
	struct VRAM_89fake logic;		 // size=8, offset=0
	void *callSignal;				 // size=0, offset=0
	struct _SVector offset;			 // size=8, offset=0
	struct Signal *gotoLabel;		 // size=0, offset=0
	struct Signal *gosubLabel;		 // size=0, offset=0
	struct VRAM_90fake control;		 // size=8, offset=0
	struct VRAM_91fake zSignal;		 // size=12, offset=0
	struct VRAM_92fake StreamLevel;  // size=24, offset=0
	struct VRAM_93fake shards;		 // size=12, offset=0
	struct VRAM_94fake cameraSpline; // size=8, offset=0
	struct VRAM_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				 // size=0, offset=0
	struct VRAM_96fake introFX;		 // size=8, offset=0
	struct VRAM_97fake introActive;  // size=8, offset=0
	struct VRAM_98fake levelChange;  // size=18, offset=0
	long blendStart;				 // size=0, offset=0
	struct VRAM_99fake setTimes;	 // size=8, offset=0
	struct VRAM_100fake color;		 // size=4, offset=0
	struct VRAM_101fake print;		 // size=12, offset=0
	long slideAngle;				 // size=0, offset=0
};

union VRAM_103fake // Hashcode: 0xB8AF7EC3 (dec: -1196458301)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union VRAM_108fake // Hashcode: 0x0263D026 (dec: 40095782)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct VRAM_110fake // hashcode: 0x152900B1 (dec: 355008689)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x8BA21D74 (dec: -1952309900), parent name: 'VRAM_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x53F8A445 (dec: 1408803909), parent name: 'VRAM_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x2A5722D4 (dec: 710353620), parent name: 'VRAM_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xF3B191BE (dec: -206466626), parent name: 'VRAM_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x7C4135D6 (dec: 2084648406), parent name: 'VRAM_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xD647E0AB (dec: -699932501), parent name: 'VRAM_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x777ACED8 (dec: 2004537048), parent name: 'VRAM_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_111fake // hashcode: 0xB7CC5E00 (dec: -1211343360)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x6EFA4199 (dec: 1861894553), parent name: 'VRAM_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xC98C5599 (dec: -913549927), parent name: 'VRAM_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x4E079525 (dec: 1309119781), parent name: 'VRAM_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_112fake // hashcode: 0xA45A1454 (dec: -1537600428)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x2989228E (dec: 696853134), parent name: 'VRAM_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x62F57205 (dec: 1660252677), parent name: 'VRAM_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x7538E27B (dec: 1966662267), parent name: 'VRAM_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x1437F11C (dec: 339210524), parent name: 'VRAM_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xE701D432 (dec: -419310542), parent name: 'VRAM_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_113fake // hashcode: 0xD9AE1C6F (dec: -642900881)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x91E3C4B7 (dec: -1847343945), parent name: 'VRAM_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0xE377F8D9 (dec: -478676775), parent name: 'VRAM_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x1C634F61 (dec: 476270433), parent name: 'VRAM_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x3AF373F7 (dec: 989033463), parent name: 'VRAM_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x8250F4F0 (dec: -2108623632), parent name: 'VRAM_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_114fake // hashcode: 0xBB89CDD4 (dec: -1148596780)
{
	struct VRAM_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x0ED41D9F (dec: 248782239), parent name: 'VRAM_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct VRAM_111fake Idle;	  // size=20, offset=28 //  hashcode: 0x1788E6A5 (dec: 394847909), parent name: 'VRAM_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct VRAM_112fake Behind;	// size=28, offset=48 //  hashcode: 0xD3D2D19F (dec: -741158497), parent name: 'VRAM_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct VRAM_113fake Follow;	// size=20, offset=76 //  hashcode: 0xCAD96C29 (dec: -891720663), parent name: 'VRAM_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_182fake // hashcode: 0x8515261D (dec: -2062211555)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0xA9C9BFD3 (dec: -1446395949), parent name: 'VRAM_182fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x7398DD53 (dec: 1939397971), parent name: 'VRAM_182fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VRAM_183fake // hashcode: 0x51513790 (dec: 1364277136)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x2F6C608E (dec: 795631758), parent name: 'VRAM_183fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x1619E847 (dec: 370796615), parent name: 'VRAM_183fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0xCA1955CB (dec: -904309301), parent name: 'VRAM_183fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0xF2D95950 (dec: -220636848), parent name: 'VRAM_183fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x0F49EF0A (dec: 256503562), parent name: 'VRAM_183fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x4CA31B08 (dec: 1285757704), parent name: 'VRAM_183fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union VRAM_184fake // Hashcode: 0x9601B59F (dec: -1778272865)
{
	struct VRAM_182fake flame; // size=8, offset=0
	struct VRAM_183fake phys;  // size=12, offset=0
};

union VRAM_210fake // Hashcode: 0x69CCA192 (dec: 1775018386)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union VRAM_249fake // Hashcode: 0x0793E106 (dec: 127131910)
{
	struct _StreamUnit *streamUnit;		 // size=64, offset=0
	struct _ObjectTracker *streamObject; // size=36, offset=0
	struct _ButtonTexture *button;		 // size=16, offset=0
};

extern void VRAM_InitVramBlockCache(); // 0x800728D0

extern void VRAM_EnableTerrainArea(); // 0x80072930

extern void VRAM_DisableTerrainArea(); // 0x80072960

extern int VRAM_ConcatanateMemory(struct _BlockVramEntry *curBlock); // 0x8007298C

extern void VRAM_GarbageCollect(); // 0x80072B74

extern int VRAM_InsertFreeBlock(struct _BlockVramEntry *block); // 0x80072BA8

extern void VRAM_DeleteFreeBlock(struct _BlockVramEntry *block); // 0x80072C38

extern void VRAM_InsertUsedBlock(struct _BlockVramEntry *block); // 0x80072CA0

extern void VRAM_DeleteUsedBlock(struct _BlockVramEntry *block); // 0x80072CD4

extern struct _BlockVramEntry *VRAM_GetOpenBlock(); // 0x80072D38

extern int VRAM_DeleteFreeVram(short x, short y, short w, short h); // 0x80072D6C

extern int VRAM_InsertFreeVram(short x, short y, short w, short h, int flags); // 0x80072E9C

extern struct _BlockVramEntry *VRAM_CheckVramSlot(short *x, short *y, short w, short h, int type, int startY); // 0x80073030

extern void VRAM_ClearVramBlock(struct _BlockVramEntry *block); // 0x8007342C

extern void AdjustVramCoordsObject(int oldx, int oldy, int newx, int newy, struct Object *object); // 0x80073460

extern struct _BlockVramEntry *VRAM_InsertionSort(struct _BlockVramEntry *rootNode, struct _BlockVramEntry *newBlock, int pack_type); // 0x8007364C

extern void VRAM_ClearVram(); // 0x80073704

extern struct _BlockVramEntry *VRAM_RearrangeVramsLayer(long whichLayer, short *AddX, short *AddY, short AddW, int AddH, int AddType, int AddStartY); // 0x80073740

extern void VRAM_TransferBufferToVram(void *dataPtr, long dataSize, short status, void *data1, void *data2); // 0x80073DC8

extern void VRAM_LoadReturn(void *dataPtr, void *data1, void *data2); // 0x80074040

extern long VRAM_GetObjectVramSpace(struct VramSize *vramSize, struct _ObjectTracker *objectTracker); // 0x80074060

extern void VRAM_InitMorphPalettes(); // 0x80074158

extern void VRAM_UpdateMorphPalettes(); // 0x80074160

extern void MORPH_ChangeAreaPalettes(long time); // 0x80074168

#endif
