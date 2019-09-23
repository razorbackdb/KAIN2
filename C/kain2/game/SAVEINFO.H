#ifndef SAVEINFO_H
#define SAVEINFO_H

static struct SavedBasic(*bufferSavedIntroArray[64]); // offset 0x800D59D0

extern struct _GlobalSaveTracker *GlobalSave; // offset 0x800CF8A8

static long numbufferedIntros; // offset 0x800CF8AC

extern long SaveArraySize[10]; // offset 0x800CF8B4

static struct SavedInfoTracker savedInfoTracker; // offset 0x800D59C0

static int the_header_size; // offset 0x800CF8B0

struct SAVEINFO_73fake // hashcode: 0x6BA3C177 (dec: 1805894007)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x9A3D507C (dec: -1707257732), parent name: 'SAVEINFO_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0xCB0AB3DE (dec: -888491042), parent name: 'SAVEINFO_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_74fake // hashcode: 0x8BFBE012 (dec: -1946427374)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x362E60E0 (dec: 909009120), parent name: 'SAVEINFO_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x3597F7C2 (dec: 899151810), parent name: 'SAVEINFO_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_75fake // hashcode: 0xC21FF748 (dec: -1038092472)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xBC0B854F (dec: -1140095665), parent name: 'SAVEINFO_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x6339A42E (dec: 1664721966), parent name: 'SAVEINFO_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SAVEINFO_76fake // Hashcode: 0xD1DD7996 (dec: -774014570)
{
	struct SAVEINFO_73fake callback; // size=8, offset=0
	struct SAVEINFO_74fake vector;   // size=12, offset=0
	struct SAVEINFO_75fake quat;	 // size=16, offset=0
};

union SAVEINFO_77fake // Hashcode: 0xFB46A940 (dec: -79255232)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union SAVEINFO_78fake // Hashcode: 0xF8791DDE (dec: -126280226)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct SAVEINFO_79fake // hashcode: 0x4955338E (dec: 1230320526)
{
	union SAVEINFO_78fake size; // size=4, offset=0 //  hashcode: 0xBE0EDE05 (dec: -1106321915), parent name: 'SAVEINFO_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_80fake // hashcode: 0x5ED260E8 (dec: 1590845672)
{
	short x;				// size=0, offset=0 //  hashcode: 0xEE792C6E (dec: -294048658), parent name: 'SAVEINFO_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x5F7C8C09 (dec: 1601997833), parent name: 'SAVEINFO_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x72186404 (dec: 1914201092), parent name: 'SAVEINFO_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xE743D7E5 (dec: -414984219), parent name: 'SAVEINFO_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xBDFC4821 (dec: -1107539935), parent name: 'SAVEINFO_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_81fake // hashcode: 0xBD044223 (dec: -1123794397)
{
	long index; // size=0, offset=0 //  hashcode: 0xD018F099 (dec: -803671911), parent name: 'SAVEINFO_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x3DFC92D4 (dec: 1039962836), parent name: 'SAVEINFO_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_82fake // hashcode: 0x3739BF27 (dec: 926531367)
{
	long index; // size=0, offset=0 //  hashcode: 0xDB017667 (dec: -620661145), parent name: 'SAVEINFO_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x27474C59 (dec: 658984025), parent name: 'SAVEINFO_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_83fake // hashcode: 0xADABAC48 (dec: -1381258168)
{
	long index; // size=0, offset=0 //  hashcode: 0x5FDDE522 (dec: 1608377634), parent name: 'SAVEINFO_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x723565E6 (dec: 1916102118), parent name: 'SAVEINFO_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_84fake // hashcode: 0x3A872EF1 (dec: 981937905)
{
	long time;  // size=0, offset=0 //  hashcode: 0x9F6E5D01 (dec: -1620157183), parent name: 'SAVEINFO_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x396AD49C (dec: 963302556), parent name: 'SAVEINFO_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_85fake // hashcode: 0x6D595EAC (dec: 1834573484)
{
	long action;   // size=0, offset=0 //  hashcode: 0x702CFCA8 (dec: 1881996456), parent name: 'SAVEINFO_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xE7ECBB8A (dec: -403915894), parent name: 'SAVEINFO_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_86fake // hashcode: 0xA388D273 (dec: -1551314317)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x686EEC33 (dec: 1752099891), parent name: 'SAVEINFO_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x3F863254 (dec: 1065759316), parent name: 'SAVEINFO_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_87fake // hashcode: 0x51227AE9 (dec: 1361214185)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x4ECE70B9 (dec: 1322152121), parent name: 'SAVEINFO_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x61E6D475 (dec: 1642517621), parent name: 'SAVEINFO_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_88fake // hashcode: 0x4EED0EF5 (dec: 1324158709)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xF2AE6217 (dec: -223452649), parent name: 'SAVEINFO_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xFBFDDC08 (dec: -67249144), parent name: 'SAVEINFO_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_89fake // hashcode: 0x4059AE3F (dec: 1079619135)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xEA1A163D (dec: -367389123), parent name: 'SAVEINFO_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x066545A4 (dec: 107300260), parent name: 'SAVEINFO_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xB7AB94BB (dec: -1213492037), parent name: 'SAVEINFO_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x7BD2B302 (dec: 2077405954), parent name: 'SAVEINFO_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x802F3FBB (dec: -2144387141), parent name: 'SAVEINFO_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_90fake // hashcode: 0x96BDCF94 (dec: -1765945452)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x03644F8B (dec: 56905611), parent name: 'SAVEINFO_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x046649F8 (dec: 73812472), parent name: 'SAVEINFO_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_91fake // hashcode: 0x4F617418 (dec: 1331786776)
{
	short index;					// size=0, offset=0 //  hashcode: 0xAA6E356C (dec: -1435617940), parent name: 'SAVEINFO_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x6244E55E (dec: 1648682334), parent name: 'SAVEINFO_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x928F0494 (dec: -1836120940), parent name: 'SAVEINFO_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xAA808A8A (dec: -1434416502), parent name: 'SAVEINFO_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_92fake // hashcode: 0xB77C1A81 (dec: -1216603519)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x24A3C3CD (dec: 614712269), parent name: 'SAVEINFO_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x2E044FF5 (dec: 772034549), parent name: 'SAVEINFO_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xB80036F0 (dec: -1207945488), parent name: 'SAVEINFO_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_93fake // hashcode: 0x27497FAC (dec: 659128236)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xD8E1A07A (dec: -656301958), parent name: 'SAVEINFO_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x89BD7E71 (dec: -1984070031), parent name: 'SAVEINFO_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x13015932 (dec: 318855474), parent name: 'SAVEINFO_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xC8E78978 (dec: -924350088), parent name: 'SAVEINFO_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xD0E8AB44 (dec: -790058172), parent name: 'SAVEINFO_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x3BD77A4C (dec: 1003977292), parent name: 'SAVEINFO_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xCA7B7A6E (dec: -897877394), parent name: 'SAVEINFO_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_94fake // hashcode: 0xB3B6C02A (dec: -1279868886)
{
	long index;  // size=0, offset=0 //  hashcode: 0x166D7B60 (dec: 376273760), parent name: 'SAVEINFO_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x7C48C834 (dec: 2085144628), parent name: 'SAVEINFO_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_95fake // hashcode: 0x66B3D2C5 (dec: 1723060933)
{
	short type; // size=0, offset=0 //  hashcode: 0x1C30D6C5 (dec: 472962757), parent name: 'SAVEINFO_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x66F6B4C9 (dec: 1727444169), parent name: 'SAVEINFO_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_96fake // hashcode: 0xA02407B6 (dec: -1608251466)
{
	long time;   // size=0, offset=0 //  hashcode: 0xE9485B1A (dec: -381134054), parent name: 'SAVEINFO_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x5F4D95A7 (dec: 1598920103), parent name: 'SAVEINFO_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_97fake // hashcode: 0x7D540232 (dec: 2102657586)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x0A394602 (dec: 171525634), parent name: 'SAVEINFO_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xE31E0815 (dec: -484571115), parent name: 'SAVEINFO_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_98fake // hashcode: 0x9A167576 (dec: -1709804170)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xBEE888E4 (dec: -1092056860), parent name: 'SAVEINFO_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xF62963BC (dec: -165059652), parent name: 'SAVEINFO_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_99fake // hashcode: 0xDF91E3CF (dec: -544087089)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x7B24A1D4 (dec: 2065998292), parent name: 'SAVEINFO_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x3379A8C1 (dec: 863611073), parent name: 'SAVEINFO_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_100fake // hashcode: 0xCB718BA1 (dec: -881751135)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x4CC9B75F (dec: 1288288095), parent name: 'SAVEINFO_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xC8330F9A (dec: -936177766), parent name: 'SAVEINFO_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x57D2328D (dec: 1473393293), parent name: 'SAVEINFO_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x8BF67809 (dec: -1946781687), parent name: 'SAVEINFO_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_101fake // hashcode: 0x6B17FAE1 (dec: 1796733665)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x46AEB522 (dec: 1185854754), parent name: 'SAVEINFO_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x87E631C3 (dec: -2014957117), parent name: 'SAVEINFO_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x1819E32E (dec: 404349742), parent name: 'SAVEINFO_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x773E1F0D (dec: 2000559885), parent name: 'SAVEINFO_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x0B1C7A15 (dec: 186415637), parent name: 'SAVEINFO_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SAVEINFO_102fake // Hashcode: 0xFE5FADDD (dec: -27284003)
{
	struct SAVEINFO_79fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;		 // size=24, offset=0
	struct SAVEINFO_80fake teleport;	 // size=16, offset=0
	struct SAVEINFO_81fake cameraValue;  // size=8, offset=0
	struct SAVEINFO_82fake miscValue;	// size=8, offset=0
	struct SAVEINFO_83fake logicValue;   // size=8, offset=0
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
	struct SAVEINFO_84fake cameraShake;  // size=8, offset=0
	long cameraSave;					 // size=0, offset=0
	long cameraRestore;					 // size=0, offset=0
	struct _BGObject *bgObject;			 // size=24, offset=0
	long value[2];						 // size=8, offset=0
	struct SAVEINFO_85fake sound;		 // size=12, offset=0
	void *intro;						 // size=0, offset=0
	long deathZ;						 // size=0, offset=0
	struct SAVEINFO_86fake dsignal;		 // size=8, offset=0
	void *mirror;						 // size=0, offset=0
	long fogNear;						 // size=0, offset=0
	long fogFar;						 // size=0, offset=0
	struct SAVEINFO_87fake gotoFrame;	// size=8, offset=0
	struct SAVEINFO_88fake changeModel;  // size=8, offset=0
	void *vmObject;						 // size=0, offset=0
	struct SAVEINFO_89fake logic;		 // size=8, offset=0
	void *callSignal;					 // size=0, offset=0
	struct _SVector offset;				 // size=8, offset=0
	struct Signal *gotoLabel;			 // size=0, offset=0
	struct Signal *gosubLabel;			 // size=0, offset=0
	struct SAVEINFO_90fake control;		 // size=8, offset=0
	struct SAVEINFO_91fake zSignal;		 // size=12, offset=0
	struct SAVEINFO_92fake StreamLevel;  // size=24, offset=0
	struct SAVEINFO_93fake shards;		 // size=12, offset=0
	struct SAVEINFO_94fake cameraSpline; // size=8, offset=0
	struct SAVEINFO_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;					 // size=0, offset=0
	struct SAVEINFO_96fake introFX;		 // size=8, offset=0
	struct SAVEINFO_97fake introActive;  // size=8, offset=0
	struct SAVEINFO_98fake levelChange;  // size=18, offset=0
	long blendStart;					 // size=0, offset=0
	struct SAVEINFO_99fake setTimes;	 // size=8, offset=0
	struct SAVEINFO_100fake color;		 // size=4, offset=0
	struct SAVEINFO_101fake print;		 // size=12, offset=0
	long slideAngle;					 // size=0, offset=0
};

union SAVEINFO_103fake // Hashcode: 0x0F9F3E09 (dec: 262094345)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union SAVEINFO_108fake // Hashcode: 0x239A742D (dec: 597324845)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct SAVEINFO_110fake // hashcode: 0x2F951ED5 (dec: 798301909)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x3F6DF818 (dec: 1064171544), parent name: 'SAVEINFO_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x91FDAD63 (dec: -1845645981), parent name: 'SAVEINFO_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0xD2C8DC19 (dec: -758588391), parent name: 'SAVEINFO_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x66C16247 (dec: 1723949639), parent name: 'SAVEINFO_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x372F352F (dec: 925840687), parent name: 'SAVEINFO_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x29F169AF (dec: 703687087), parent name: 'SAVEINFO_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xDED2E3DF (dec: -556604449), parent name: 'SAVEINFO_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_111fake // hashcode: 0x83BB436B (dec: -2084879509)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x23F8CD3E (dec: 603508030), parent name: 'SAVEINFO_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xB9AB41AA (dec: -1179958870), parent name: 'SAVEINFO_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xDA95E1B7 (dec: -627711561), parent name: 'SAVEINFO_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_112fake // hashcode: 0xF3A407BE (dec: -207353922)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xE6F3CB22 (dec: -420230366), parent name: 'SAVEINFO_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x60ECCB30 (dec: 1626131248), parent name: 'SAVEINFO_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x75475161 (dec: 1967608161), parent name: 'SAVEINFO_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xEBBD7218 (dec: -339906024), parent name: 'SAVEINFO_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x95BDF128 (dec: -1782714072), parent name: 'SAVEINFO_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_113fake // hashcode: 0x92B8F929 (dec: -1833371351)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xCE1F7FF6 (dec: -836796426), parent name: 'SAVEINFO_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x81A45D4D (dec: -2119934643), parent name: 'SAVEINFO_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x09456905 (dec: 155543813), parent name: 'SAVEINFO_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x7356A864 (dec: 1935059044), parent name: 'SAVEINFO_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x34B56FD7 (dec: 884305879), parent name: 'SAVEINFO_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_114fake // hashcode: 0x472E0EDF (dec: 1194200799)
{
	struct SAVEINFO_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x5F105417 (dec: 1594905623), parent name: 'SAVEINFO_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SAVEINFO_111fake Idle;	  // size=20, offset=28 //  hashcode: 0x7CA9137A (dec: 2091455354), parent name: 'SAVEINFO_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SAVEINFO_112fake Behind;	// size=28, offset=48 //  hashcode: 0xBBA96B91 (dec: -1146524783), parent name: 'SAVEINFO_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SAVEINFO_113fake Follow;	// size=20, offset=76 //  hashcode: 0x04281729 (dec: 69736233), parent name: 'SAVEINFO_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SAVEINFO_196fake // Hashcode: 0x37750CF1 (dec: 930417905)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct SavedInfoTracker // hashcode: 0x03231C9A (dec: 52632730)
{
	char *MemoryCardBuffer; // size=0, offset=0 //  hashcode: 0x7EC15455 (dec: 2126599253), parent name: 'SavedInfoTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *InfoStart;		// size=0, offset=4 //  hashcode: 0x29BA30EF (dec: 700068079), parent name: 'SavedInfoTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *InfoEnd;			// size=0, offset=8 //  hashcode: 0xF88C197A (dec: -125036166), parent name: 'SavedInfoTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *EndOfMemory;		// size=0, offset=12 //  hashcode: 0x6648F36A (dec: 1716056938), parent name: 'SavedInfoTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SavedLevel // hashcode: 0xABBBA745 (dec: -1413765307)
{
	unsigned char savedID;		   // size=0, offset=0 //  hashcode: 0x6BC580EE (dec: 1808105710), parent name: 'SavedLevel', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char shiftedSaveSize; // size=0, offset=1 //  hashcode: 0x91D4A20D (dec: -1848335859), parent name: 'SavedLevel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short areaID;				   // size=0, offset=2 //  hashcode: 0x15B3B927 (dec: 364099879), parent name: 'SavedLevel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short waterZ;				   // size=0, offset=4 //  hashcode: 0xF1FAA69F (dec: -235231585), parent name: 'SavedLevel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numberBSPTreesSaved;	 // size=0, offset=6 //  hashcode: 0x6CE51034 (dec: 1826951220), parent name: 'SavedLevel', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ActualSavedLevel // hashcode: 0xE75849FD (dec: -413644291)
{
	unsigned char savedID;				 // size=0, offset=0 //  hashcode: 0x9D2865EE (dec: -1658296850), parent name: 'ActualSavedLevel', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char shiftedSaveSize;		 // size=0, offset=1 //  hashcode: 0x785C9718 (dec: 2019333912), parent name: 'ActualSavedLevel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short areaID;						 // size=0, offset=2 //  hashcode: 0x39BD7E79 (dec: 968719993), parent name: 'ActualSavedLevel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short waterZ;						 // size=0, offset=4 //  hashcode: 0xCB5AC8CB (dec: -883242805), parent name: 'ActualSavedLevel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numberBSPTreesSaved;			 // size=0, offset=6 //  hashcode: 0x618010D6 (dec: 1635782870), parent name: 'ActualSavedLevel', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SavedBspTree bspTreeArray[1]; // size=8, offset=8 //  hashcode: 0xE999E0D4 (dec: -375791404), parent name: 'ActualSavedLevel', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SavedDeadDeadBits // hashcode: 0x00B3140D (dec: 11736077)
{
	unsigned char savedID;		   // size=0, offset=0 //  hashcode: 0x9919E3CD (dec: -1726356531), parent name: 'SavedDeadDeadBits', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char shiftedSaveSize; // size=0, offset=1 //  hashcode: 0xEB8AD806 (dec: -343222266), parent name: 'SavedDeadDeadBits', parent hashcode: 0xFFFFFFFF (dec: -1)
	char deadDeadBits[832];		   // size=832, offset=2 //  hashcode: 0x1B5F32A1 (dec: 459223713), parent name: 'SavedDeadDeadBits', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GlobalSaveTracker // hashcode: 0x1972AA1A (dec: 426945050)
{
	short savedID;								 // size=0, offset=0 //  hashcode: 0x1F9A45C2 (dec: 530204098), parent name: '_GlobalSaveTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short saveSize;								 // size=0, offset=2 //  hashcode: 0x55AA1E69 (dec: 1437212265), parent name: '_GlobalSaveTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;								 // size=0, offset=4 //  hashcode: 0x1D78994A (dec: 494442826), parent name: '_GlobalSaveTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short saveVersion;							 // size=0, offset=6 //  hashcode: 0x5F7900F1 (dec: 1601765617), parent name: '_GlobalSaveTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long currentTime;					 // size=0, offset=8 //  hashcode: 0xA76D149E (dec: -1486023522), parent name: '_GlobalSaveTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short humanOpinionOfRaziel;					 // size=0, offset=12 //  hashcode: 0x8BF9B686 (dec: -1946569082), parent name: '_GlobalSaveTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numRegens;								 // size=0, offset=14 //  hashcode: 0x9229B1D8 (dec: -1842761256), parent name: '_GlobalSaveTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MONAPI_Regenerator regenEntries[10]; // size=80, offset=16 //  hashcode: 0x551611B7 (dec: 1427509687), parent name: '_GlobalSaveTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct gSoundData sound;					 // size=20, offset=96 //  hashcode: 0xC81FD168 (dec: -937438872), parent name: '_GlobalSaveTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sizeUsedInBlock;						 // size=0, offset=116 //  hashcode: 0xB95E7AC7 (dec: -1184990521), parent name: '_GlobalSaveTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short CurrentBirthID;						 // size=0, offset=118 //  hashcode: 0x1E4E436E (dec: 508445550), parent name: '_GlobalSaveTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SAVEINFO_223fake // Hashcode: 0x8FDE617F (dec: -1881251457)
{
	struct Intro *intro;	   // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

union SAVEINFO_225fake // Hashcode: 0x4B2E75DB (dec: 1261336027)
{
	struct _Instance *instance; // size=616, offset=0
	struct _SFXMkr *sfxMarker;  // size=36, offset=0
};

struct SAVEINFO_226fake // hashcode: 0x9E508500 (dec: -1638890240)
{
	long instanceNumber; // size=0, offset=0 //  hashcode: 0x6DF82A07 (dec: 1844980231), parent name: 'SAVEINFO_226fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;		 // size=0, offset=4 //  hashcode: 0x971ABE97 (dec: -1759854953), parent name: 'SAVEINFO_226fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_227fake // hashcode: 0x8544EB20 (dec: -2059080928)
{
	struct _SavedIntro *intro; // size=40, offset=0 //  hashcode: 0x58A3E7EC (dec: 1487136748), parent name: 'SAVEINFO_227fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;			   // size=0, offset=4 //  hashcode: 0x0BC84CB9 (dec: 197676217), parent name: 'SAVEINFO_227fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_228fake // hashcode: 0x20253C55 (dec: 539311189)
{
	long currentNumber; // size=0, offset=0 //  hashcode: 0x07804B50 (dec: 125848400), parent name: 'SAVEINFO_228fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long error;			// size=0, offset=4 //  hashcode: 0x3009C3EA (dec: 805946346), parent name: 'SAVEINFO_228fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;		// size=0, offset=8 //  hashcode: 0x26D0D610 (dec: 651220496), parent name: 'SAVEINFO_228fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_229fake // hashcode: 0x9AD72904 (dec: -1697175292)
{
	short vx; // size=0, offset=0 //  hashcode: 0xD4379CC4 (dec: -734552892), parent name: 'SAVEINFO_229fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vy; // size=0, offset=2 //  hashcode: 0xD69CFBB7 (dec: -694355017), parent name: 'SAVEINFO_229fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_230fake // hashcode: 0x14A86A52 (dec: 346581586)
{
	char *pointer; // size=0, offset=0 //  hashcode: 0x0818640A (dec: 135816202), parent name: 'SAVEINFO_230fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_231fake // hashcode: 0x192F7644 (dec: 422540868)
{
	short *pointer; // size=0, offset=0 //  hashcode: 0x395FD235 (dec: 962581045), parent name: 'SAVEINFO_231fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_232fake // hashcode: 0xF7B77A94 (dec: -138970476)
{
	long *pointer; // size=0, offset=0 //  hashcode: 0x87555A3E (dec: -2024449474), parent name: 'SAVEINFO_232fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SAVEINFO_233fake // Hashcode: 0x782BCB5A (dec: 2016136026)
{
	struct SAVEINFO_226fake Object;					  // size=8, offset=0
	struct SAVEINFO_227fake SavedIntroObject;		  // size=8, offset=0
	struct InstanceSpline instanceSpline;			  // size=24, offset=0
	struct SAVEINFO_228fake Number;					  // size=12, offset=0
	struct SAVEINFO_229fake Vector2d;				  // size=4, offset=0
	struct SAVEINFO_230fake CharPointer;			  // size=4, offset=0
	struct SAVEINFO_231fake ShortPointer;			  // size=4, offset=0
	struct SAVEINFO_232fake LongPointer;			  // size=4, offset=0
	struct AreaObject areaObject;					  // size=12, offset=0
	struct InstanceObject instanceObject;			  // size=8, offset=0
	struct Vector3d vector3d;						  // size=20, offset=0
	struct Rotation3d rotation3d;					  // size=20, offset=0
	struct SignalObject signalObject;				  // size=8, offset=0
	struct EventObject eventObject;					  // size=8, offset=0
	struct GameObject gameObject;					  // size=4, offset=0
	struct ListObject listObject;					  // size=32, offset=0
	struct IntroObject introObject;					  // size=8, offset=0
	struct InstanceAnimate instanceAnimate;			  // size=8, offset=0
	struct InstanceAnimateTexture instanceAniTexture; // size=12, offset=0
	struct SavedEventObject savedEventObject;		  // size=16, offset=0
	struct SubListObject subListObject;				  // size=32, offset=0
	struct TGroupObject terrainGroup;				  // size=16, offset=0
	struct ConstrictInfo constrictInfo;				  // size=8, offset=0
	struct CameraObject cameraObject;				  // size=12, offset=0
	struct EventVmObject vmObject;					  // size=12, offset=0
	struct SoundObject soundObject;					  // size=20, offset=0
};

struct SAVEINFO_235fake // hashcode: 0x95075999 (dec: -1794680423)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x261FCAE5 (dec: 639617765), parent name: 'SAVEINFO_235fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0xDFE4B37F (dec: -538659969), parent name: 'SAVEINFO_235fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SAVEINFO_236fake // hashcode: 0x7310D819 (dec: 1930483737)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0xB158E0FF (dec: -1319575297), parent name: 'SAVEINFO_236fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x05EF175C (dec: 99555164), parent name: 'SAVEINFO_236fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x3821B38A (dec: 941732746), parent name: 'SAVEINFO_236fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0xD1739327 (dec: -780954841), parent name: 'SAVEINFO_236fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x61BC2993 (dec: 1639721363), parent name: 'SAVEINFO_236fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x71A4EEF3 (dec: 1906634483), parent name: 'SAVEINFO_236fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SAVEINFO_237fake // Hashcode: 0xCED6533E (dec: -824814786)
{
	struct SAVEINFO_235fake flame; // size=8, offset=0
	struct SAVEINFO_236fake phys;  // size=12, offset=0
};

typedef struct SavedInfoTracker SavedInfoTracker;

typedef struct SavedLevel SavedLevel;

typedef struct ActualSavedLevel ActualSavedLevel;

typedef struct SavedDeadDeadBits SavedDeadDeadBits;

typedef struct _GlobalSaveTracker GlobalSaveTracker;

extern void SAVE_GetInstanceRotation(struct _Instance *instance, struct _SmallRotation *vector); // 0x800B5560

extern void SAVE_ClearMemory(struct GameTracker *gameTracker); // 0x800B55E8

extern void SAVE_Init(struct GameTracker *gt); // 0x800B5668

extern void *SAVE_GetSavedBlock(long saveType, long extraSize); // 0x800B56EC

extern long SAVE_PurgeAMemoryBlock(); // 0x800B5808

extern long SAVE_SaveableInstance(struct _Instance *instance); // 0x800B58A8

extern struct _SavedIntro *SAVE_UpdateSavedIntro(struct _Instance *instance, struct Level *level, struct _SavedIntro *savedIntro, struct evControlSaveDataData *extraData); // 0x800B59A4

extern struct _SavedIntroWithIntro *SAVE_UpdateSavedIntroWithIntro(struct _Instance *instance, struct Level *level, struct _SavedIntroWithIntro *savedIntro, struct evControlSaveDataData *extraData); // 0x800B5AB0

extern struct SavedBasic *SAVE_GetSavedEvent(long areaID, long eventNumber); // 0x800B5BE8

extern void SAVE_DeleteSavedEvent(long areaID, long eventNumber); // 0x800B5C90

extern struct SavedBasic *SAVE_GetSavedNextEvent(long areaID, struct SavedBasic *curSave); // 0x800B5CC0

extern void SAVE_BufferIntro(struct SavedBasic *savedIntro); // 0x800B5D64

extern void SAVE_IntroduceBufferIntros(); // 0x800B5DE4

extern void SAVE_IntroForStreamID(struct _StreamUnit *streamUnit); // 0x800B5EC0

extern long SAVE_HasSavedIntro(struct Intro *intro, long currentStreamID); // 0x800B5F9C

extern struct SavedLevel *SAVE_HasSavedLevel(long areaID); // 0x800B602C

extern void SAVE_UpdateLevelWithSave(struct _StreamUnit *streamUnit); // 0x800B6090

extern struct SavedLevel *SAVE_CreatedSavedLevel(long areaID, struct Level *level); // 0x800B61DC

extern void SAVE_DeleteBlock(struct SavedBasic *savedBlock); // 0x800B6398

extern void SAVE_Instance(struct _Instance *instance, struct Level *level); // 0x800B6424

extern void SAVE_DeleteInstance(struct _Instance *instance); // 0x800B6658

extern void SAVE_SetDeadDeadBit(int uniqueID, long set); // 0x800B6728

extern void SAVE_RestoreGlobalSavePointer(); // 0x800B67EC

extern long SAVE_IsUniqueIDDeadDead(long uniqueID); // 0x800B6844

extern long SAVE_IsIntroDeadDead(struct Intro *intro); // 0x800B68F0

extern void SAVE_DoInstanceDeadDead(struct _Instance *instance); // 0x800B6914

extern void SAVE_MarkDeadDead(struct _Instance *instance); // 0x800B6944

extern void SAVE_UndestroyInstance(struct _Instance *instance); // 0x800B6958

extern struct SavedIntroSmall *SAVE_GetSavedSmallIntro(struct _Instance *instance); // 0x800B697C

extern struct SavedIntroSpline *SAVE_GetIntroSpline(struct _Instance *instance); // 0x800B69E8

extern void SAVE_UpdateGlobalSaveTracker(); // 0x800B6A54

extern void SAVE_RestoreGlobalSaveTracker(); // 0x800B6AE8

extern void SAVE_SaveEverythingInMemory(); // 0x800B6BB8

extern void SAVE_SaveGame(); // 0x800B6C6C

extern void SAVE_RestoreGame(); // 0x800B6CB8

extern long SAVE_SizeOfFreeSpace(); // 0x800B6D1C

#endif
