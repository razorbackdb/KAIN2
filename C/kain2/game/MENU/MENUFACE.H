#ifndef MENUFACE_H
#define MENUFACE_H

static struct _ButtonTexture *FaceButtons; // offset 0x800D5C04

static int hack_initialized; // offset 0x800CFB3C

static struct menuface_t MenuFaces[8]; // offset 0x800CFABC

struct MENUFACE_68fake // hashcode: 0x4722A2B2 (dec: 1193452210)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xD464183D (dec: -731637699), parent name: 'MENUFACE_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x416D38D4 (dec: 1097677012), parent name: 'MENUFACE_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_69fake // hashcode: 0xDD16BD5D (dec: -585712291)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x150794BE (dec: 352818366), parent name: 'MENUFACE_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x04B56784 (dec: 78997380), parent name: 'MENUFACE_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_70fake // hashcode: 0xA6FCAAA9 (dec: -1493390679)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xD16A7395 (dec: -781552747), parent name: 'MENUFACE_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x4A82D7EF (dec: 1250088943), parent name: 'MENUFACE_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MENUFACE_71fake // Hashcode: 0x1C6ACF56 (dec: 476761942)
{
	struct MENUFACE_68fake callback; // size=8, offset=0
	struct MENUFACE_69fake vector;   // size=12, offset=0
	struct MENUFACE_70fake quat;	 // size=16, offset=0
};

union MENUFACE_72fake // Hashcode: 0xFB4CCE52 (dec: -78852526)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MENUFACE_73fake // Hashcode: 0xA2FCBA4E (dec: -1560495538)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct MENUFACE_74fake // hashcode: 0xF867D95D (dec: -127411875)
{
	union MENUFACE_73fake size; // size=4, offset=0 //  hashcode: 0x81EE73B5 (dec: -2115079243), parent name: 'MENUFACE_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_75fake // hashcode: 0xFAEDC377 (dec: -85081225)
{
	short x;				// size=0, offset=0 //  hashcode: 0x1A002F80 (dec: 436219776), parent name: 'MENUFACE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x0C93FA0A (dec: 211024394), parent name: 'MENUFACE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x76FC3F77 (dec: 1996242807), parent name: 'MENUFACE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x9010DE4B (dec: -1877942709), parent name: 'MENUFACE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xC1F78573 (dec: -1040743053), parent name: 'MENUFACE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_76fake // hashcode: 0x55D9B0DE (dec: 1440329950)
{
	long index; // size=0, offset=0 //  hashcode: 0xE823BA2B (dec: -400311765), parent name: 'MENUFACE_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xCF871F52 (dec: -813228206), parent name: 'MENUFACE_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_77fake // hashcode: 0x75A8A0B1 (dec: 1973985457)
{
	long index; // size=0, offset=0 //  hashcode: 0xF4149D26 (dec: -199975642), parent name: 'MENUFACE_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xB52D90C1 (dec: -1255305023), parent name: 'MENUFACE_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_78fake // hashcode: 0x36D6B732 (dec: 920041266)
{
	long index; // size=0, offset=0 //  hashcode: 0xF07D61F8 (dec: -260218376), parent name: 'MENUFACE_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xB70C3D6C (dec: -1223934612), parent name: 'MENUFACE_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_79fake // hashcode: 0x65C3FD48 (dec: 1707343176)
{
	long time;  // size=0, offset=0 //  hashcode: 0x53201184 (dec: 1394610564), parent name: 'MENUFACE_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x74B36736 (dec: 1957914422), parent name: 'MENUFACE_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_80fake // hashcode: 0x14056DCC (dec: 335900108)
{
	long action;   // size=0, offset=0 //  hashcode: 0x7AFAF213 (dec: 2063266323), parent name: 'MENUFACE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x19107009 (dec: 420507657), parent name: 'MENUFACE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_81fake // hashcode: 0xAEA99ED9 (dec: -1364615463)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x93C579D5 (dec: -1815774763), parent name: 'MENUFACE_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xFA3BED42 (dec: -96735934), parent name: 'MENUFACE_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_82fake // hashcode: 0x408F533C (dec: 1083134780)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xDB1CC77B (dec: -618870917), parent name: 'MENUFACE_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x93A47A40 (dec: -1817937344), parent name: 'MENUFACE_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_83fake // hashcode: 0x3EB36725 (dec: 1051944741)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xFCA430CE (dec: -56348466), parent name: 'MENUFACE_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xEEC4BDE6 (dec: -289096218), parent name: 'MENUFACE_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_84fake // hashcode: 0x51F31017 (dec: 1374883863)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x76AF2D2A (dec: 1991191850), parent name: 'MENUFACE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x7F5EF712 (dec: 2136930066), parent name: 'MENUFACE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xCE38F661 (dec: -835127711), parent name: 'MENUFACE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xDC98DCFC (dec: -593961732), parent name: 'MENUFACE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xD65BB68C (dec: -698632564), parent name: 'MENUFACE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_85fake // hashcode: 0x6EAA0781 (dec: 1856636801)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x7E97B295 (dec: 2123870869), parent name: 'MENUFACE_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xF06C2166 (dec: -261349018), parent name: 'MENUFACE_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_86fake // hashcode: 0x80C958B3 (dec: -2134288205)
{
	short index;					// size=0, offset=0 //  hashcode: 0xA453C2C6 (dec: -1538014522), parent name: 'MENUFACE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x704964F4 (dec: 1883858164), parent name: 'MENUFACE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x8AF3CA0B (dec: -1963734517), parent name: 'MENUFACE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xE664B663 (dec: -429607325), parent name: 'MENUFACE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_87fake // hashcode: 0xC0DEF4B3 (dec: -1059130189)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xAA775B87 (dec: -1435018361), parent name: 'MENUFACE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x4C1878E0 (dec: 1276672224), parent name: 'MENUFACE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x822C0DF5 (dec: -2111042059), parent name: 'MENUFACE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_88fake // hashcode: 0x60C9283A (dec: 1623795770)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x93542980 (dec: -1823200896), parent name: 'MENUFACE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xFEEAC20B (dec: -18169333), parent name: 'MENUFACE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x7EF56094 (dec: 2130010260), parent name: 'MENUFACE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x1FDF0952 (dec: 534710610), parent name: 'MENUFACE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x3D20188F (dec: 1025513615), parent name: 'MENUFACE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x206A8960 (dec: 543852896), parent name: 'MENUFACE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x5CDD8D4C (dec: 1558023500), parent name: 'MENUFACE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_89fake // hashcode: 0x98C5F966 (dec: -1731856026)
{
	long index;  // size=0, offset=0 //  hashcode: 0x0C116F9A (dec: 202469274), parent name: 'MENUFACE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xEB8650A3 (dec: -343519069), parent name: 'MENUFACE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_90fake // hashcode: 0x4267019E (dec: 1114046878)
{
	short type; // size=0, offset=0 //  hashcode: 0x7FCF2A63 (dec: 2144283235), parent name: 'MENUFACE_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x9F9D1CD0 (dec: -1617093424), parent name: 'MENUFACE_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_91fake // hashcode: 0xC666037B (dec: -966392965)
{
	long time;   // size=0, offset=0 //  hashcode: 0x00EF3CFB (dec: 15678715), parent name: 'MENUFACE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xE9115AF5 (dec: -384738571), parent name: 'MENUFACE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_92fake // hashcode: 0xADCBAA7C (dec: -1379161476)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x07AADBDC (dec: 128637916), parent name: 'MENUFACE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xBD5187FB (dec: -1118730245), parent name: 'MENUFACE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_93fake // hashcode: 0x715E45CE (dec: 1902003662)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x8780F0EB (dec: -2021592853), parent name: 'MENUFACE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x3421A593 (dec: 874620307), parent name: 'MENUFACE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_94fake // hashcode: 0xA74F2CB6 (dec: -1487983434)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x725A4E8A (dec: 1918520970), parent name: 'MENUFACE_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xCF229DAC (dec: -819814996), parent name: 'MENUFACE_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_95fake // hashcode: 0xC2217196 (dec: -1037995626)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x2A30ADC1 (dec: 707833281), parent name: 'MENUFACE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xF6C55F80 (dec: -154837120), parent name: 'MENUFACE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x69B9D5B7 (dec: 1773786551), parent name: 'MENUFACE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x995D0290 (dec: -1721957744), parent name: 'MENUFACE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_96fake // hashcode: 0x57519EFB (dec: 1464966907)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xE11E5C0C (dec: -518104052), parent name: 'MENUFACE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x95EDD221 (dec: -1779576287), parent name: 'MENUFACE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x63932C54 (dec: 1670589524), parent name: 'MENUFACE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x2147ADDB (dec: 558345691), parent name: 'MENUFACE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x1DF62208 (dec: 502669832), parent name: 'MENUFACE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MENUFACE_97fake // Hashcode: 0xA8921966 (dec: -1466820250)
{
	struct MENUFACE_74fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;		 // size=24, offset=0
	struct MENUFACE_75fake teleport;	 // size=16, offset=0
	struct MENUFACE_76fake cameraValue;  // size=8, offset=0
	struct MENUFACE_77fake miscValue;	// size=8, offset=0
	struct MENUFACE_78fake logicValue;   // size=8, offset=0
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
	struct MENUFACE_79fake cameraShake;  // size=8, offset=0
	long cameraSave;					 // size=0, offset=0
	long cameraRestore;					 // size=0, offset=0
	struct _BGObject *bgObject;			 // size=24, offset=0
	long value[2];						 // size=8, offset=0
	struct MENUFACE_80fake sound;		 // size=12, offset=0
	void *intro;						 // size=0, offset=0
	long deathZ;						 // size=0, offset=0
	struct MENUFACE_81fake dsignal;		 // size=8, offset=0
	void *mirror;						 // size=0, offset=0
	long fogNear;						 // size=0, offset=0
	long fogFar;						 // size=0, offset=0
	struct MENUFACE_82fake gotoFrame;	// size=8, offset=0
	struct MENUFACE_83fake changeModel;  // size=8, offset=0
	void *vmObject;						 // size=0, offset=0
	struct MENUFACE_84fake logic;		 // size=8, offset=0
	void *callSignal;					 // size=0, offset=0
	struct _SVector offset;				 // size=8, offset=0
	struct Signal *gotoLabel;			 // size=0, offset=0
	struct Signal *gosubLabel;			 // size=0, offset=0
	struct MENUFACE_85fake control;		 // size=8, offset=0
	struct MENUFACE_86fake zSignal;		 // size=12, offset=0
	struct MENUFACE_87fake StreamLevel;  // size=24, offset=0
	struct MENUFACE_88fake shards;		 // size=12, offset=0
	struct MENUFACE_89fake cameraSpline; // size=8, offset=0
	struct MENUFACE_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;					 // size=0, offset=0
	struct MENUFACE_91fake introFX;		 // size=8, offset=0
	struct MENUFACE_92fake introActive;  // size=8, offset=0
	struct MENUFACE_93fake levelChange;  // size=18, offset=0
	long blendStart;					 // size=0, offset=0
	struct MENUFACE_94fake setTimes;	 // size=8, offset=0
	struct MENUFACE_95fake color;		 // size=4, offset=0
	struct MENUFACE_96fake print;		 // size=12, offset=0
	long slideAngle;					 // size=0, offset=0
};

union MENUFACE_98fake // Hashcode: 0x41019063 (dec: 1090621539)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union MENUFACE_103fake // Hashcode: 0xABDA5D2E (dec: -1411752658)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct MENUFACE_105fake // hashcode: 0x903E2FBE (dec: -1874972738)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xB736EE0F (dec: -1221136881), parent name: 'MENUFACE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x84B92441 (dec: -2068241343), parent name: 'MENUFACE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x4C4A2B42 (dec: 1279929154), parent name: 'MENUFACE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xF2452208 (dec: -230350328), parent name: 'MENUFACE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0xFE49184D (dec: -28764083), parent name: 'MENUFACE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x91B46631 (dec: -1850448335), parent name: 'MENUFACE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x81736091 (dec: -2123145071), parent name: 'MENUFACE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_106fake // hashcode: 0x2CA53E35 (dec: 749026869)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x0A24840C (dec: 170165260), parent name: 'MENUFACE_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x44B21C2F (dec: 1152523311), parent name: 'MENUFACE_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xF007119F (dec: -267972193), parent name: 'MENUFACE_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_107fake // hashcode: 0xE1B5B602 (dec: -508185086)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x139BAC94 (dec: 328969364), parent name: 'MENUFACE_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x7BE4C7FE (dec: 2078590974), parent name: 'MENUFACE_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x6334DE58 (dec: 1664409176), parent name: 'MENUFACE_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xEFCA9BDE (dec: -271934498), parent name: 'MENUFACE_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xAC22FD73 (dec: -1406993037), parent name: 'MENUFACE_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_108fake // hashcode: 0x0B4E4EF2 (dec: 189681394)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x90E098AD (dec: -1864329043), parent name: 'MENUFACE_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x2C30227F (dec: 741352063), parent name: 'MENUFACE_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x937CBB77 (dec: -1820542089), parent name: 'MENUFACE_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x1820DDEA (dec: 404807146), parent name: 'MENUFACE_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x971DB4DA (dec: -1759660838), parent name: 'MENUFACE_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUFACE_109fake // hashcode: 0xD61A4E22 (dec: -702919134)
{
	struct MENUFACE_105fake Cinematic; // size=28, offset=0 //  hashcode: 0x62B24185 (dec: 1655849349), parent name: 'MENUFACE_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MENUFACE_106fake Idle;	  // size=20, offset=28 //  hashcode: 0x6DA422D7 (dec: 1839473367), parent name: 'MENUFACE_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MENUFACE_107fake Behind;	// size=28, offset=48 //  hashcode: 0x7F30F499 (dec: 2133914777), parent name: 'MENUFACE_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MENUFACE_108fake Follow;	// size=20, offset=76 //  hashcode: 0xF6BBB03C (dec: -155471812), parent name: 'MENUFACE_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MENUFACE_172fake // Hashcode: 0xE1BFF286 (dec: -507514234)
{
	struct _StreamUnit *streamUnit;		 // size=0, offset=0
	struct _ObjectTracker *streamObject; // size=36, offset=0
	struct _ButtonTexture *button;		 // size=16, offset=0
};

enum bdepth // Hashcode: 0x70F5AFBC (dec: 1895149500)
{
	TIM_4BIT = 0,
	TIM_8BIT = 1,
	TIM_16BIT = 2,
};

struct menuface_t // hashcode: 0xC2732FD8 (dec: -1032638504)
{
	short x;			   // size=0, offset=0 //  hashcode: 0x2C25380F (dec: 740636687), parent name: 'menuface_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;			   // size=0, offset=2 //  hashcode: 0x662F936B (dec: 1714393963), parent name: 'menuface_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	char w;				   // size=0, offset=4 //  hashcode: 0xDBD4AE70 (dec: -606818704), parent name: 'menuface_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	char h;				   // size=0, offset=5 //  hashcode: 0xE165AE6A (dec: -513429910), parent name: 'menuface_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	char frames;		   // size=0, offset=6 //  hashcode: 0xE6C54C29 (dec: -423277527), parent name: 'menuface_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	short curFrame;		   // size=0, offset=8 //  hashcode: 0x6EB5A93F (dec: 1857399103), parent name: 'menuface_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	short transitionDir;   // size=0, offset=10 //  hashcode: 0xBE6C54B1 (dec: -1100196687), parent name: 'menuface_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short delay;  // size=0, offset=12 //  hashcode: 0x415518E2 (dec: 1096095970), parent name: 'menuface_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short loaded; // size=0, offset=14 //  hashcode: 0x15136D60 (dec: 353594720), parent name: 'menuface_t', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef enum bdepth bdepth;

typedef struct menuface_t menuface_t;

extern char *NextTimAddr(char *addr, int w, int h, enum bdepth bpp); // 0x800B9538

extern void menuface_initialize(); // 0x800B9580

extern void menuface_terminate(); // 0x800B96AC

extern void MENUFACE_ChangeStateRandomly(int index); // 0x800B9758

extern void MENUFACE_RefreshFaces(); // 0x800B987C

#endif
