#ifndef GAMELOOP_H
#define GAMELOOP_H

static void *enemyPlanPool; // offset 0x800D0C30

extern struct Object *fontsObject; // offset 0x800CE2AC

extern struct _FXTracker *fxTracker; // offset 0x800D0C58

extern struct _FXTracker *gFXT; // offset 0x800D0C44

static struct LightInfo *gLightInfo; // offset 0x800D0C2C

static struct _ObjectTracker *GlobalObjects; // offset 0x800D0C38

static unsigned long(**gOt[2]); // offset 0x800D0C0C

static struct _PolytopeList *gPolytopeList; // offset 0x800D0C1C

static struct _VertexPool *gVertexPool; // offset 0x800D0C28

static struct _InstanceList *instanceList; // offset 0x800D0C20

static struct _InstancePool *instancePool; // offset 0x800D0C24

static short pause_redraw_flag; // offset 0x800D0C3C

static void *pause_redraw_prim; // offset 0x800D0C40

static void *planningPool; // offset 0x800D0C34

static struct _PrimPool(*primPool[2]); // offset 0x800D0C14

struct GAMELOOP_73fake // hashcode: 0xBE222E53 (dec: -1105056173)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x1E6A75E4 (dec: 510293476), parent name: 'GAMELOOP_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x13C3A818 (dec: 331589656), parent name: 'GAMELOOP_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_74fake // hashcode: 0xEB23DEAA (dec: -349970774)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x785C2687 (dec: 2019305095), parent name: 'GAMELOOP_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x2F8972EA (dec: 797537002), parent name: 'GAMELOOP_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_75fake // hashcode: 0xF9E4709B (dec: -102469477)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x15C99E78 (dec: 365534840), parent name: 'GAMELOOP_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x9DDF3235 (dec: -1646317003), parent name: 'GAMELOOP_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union GAMELOOP_76fake // Hashcode: 0x8976D081 (dec: -1988702079)
{
	struct GAMELOOP_73fake callback; // size=8, offset=0
	struct GAMELOOP_74fake vector;   // size=12, offset=0
	struct GAMELOOP_75fake quat;	 // size=16, offset=0
};

union GAMELOOP_77fake // Hashcode: 0x5136BCA3 (dec: 1362541731)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union GAMELOOP_78fake // Hashcode: 0x44371514 (dec: 1144460564)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct GAMELOOP_79fake // hashcode: 0x2F0156DD (dec: 788616925)
{
	union GAMELOOP_78fake size; // size=4, offset=0 //  hashcode: 0xAABCF753 (dec: -1430456493), parent name: 'GAMELOOP_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_80fake // hashcode: 0x2A0633DB (dec: 705049563)
{
	short x;				// size=0, offset=0 //  hashcode: 0xD1B815A0 (dec: -776464992), parent name: 'GAMELOOP_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x6314E43C (dec: 1662313532), parent name: 'GAMELOOP_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x3460C8DE (dec: 878758110), parent name: 'GAMELOOP_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x9FB44F20 (dec: -1615573216), parent name: 'GAMELOOP_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xF07F7DA0 (dec: -260080224), parent name: 'GAMELOOP_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_81fake // hashcode: 0xD2F0895C (dec: -755988132)
{
	long index; // size=0, offset=0 //  hashcode: 0x567FC139 (dec: 1451213113), parent name: 'GAMELOOP_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xA39DB2F4 (dec: -1549946124), parent name: 'GAMELOOP_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_82fake // hashcode: 0x63C7F483 (dec: 1674048643)
{
	long index; // size=0, offset=0 //  hashcode: 0x4AEB2D67 (dec: 1256926567), parent name: 'GAMELOOP_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x307171F3 (dec: 812741107), parent name: 'GAMELOOP_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_83fake // hashcode: 0xB719CC99 (dec: -1223045991)
{
	long index; // size=0, offset=0 //  hashcode: 0x26AA8ABA (dec: 648710842), parent name: 'GAMELOOP_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xEAB72E3F (dec: -357093825), parent name: 'GAMELOOP_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_84fake // hashcode: 0xA6824037 (dec: -1501413321)
{
	long time;  // size=0, offset=0 //  hashcode: 0x1A6F4A41 (dec: 443501121), parent name: 'GAMELOOP_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x316C80CB (dec: 829194443), parent name: 'GAMELOOP_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_85fake // hashcode: 0x73C8845A (dec: 1942520922)
{
	long action;   // size=0, offset=0 //  hashcode: 0x8CF41CC8 (dec: -1930158904), parent name: 'GAMELOOP_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xC8ABD92E (dec: -928261842), parent name: 'GAMELOOP_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_86fake // hashcode: 0x187CDC2F (dec: 410836015)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x141AD4EE (dec: 337302766), parent name: 'GAMELOOP_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xB39DF45B (dec: -1281493925), parent name: 'GAMELOOP_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_87fake // hashcode: 0x8DD39A00 (dec: -1915512320)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x5BFE374C (dec: 1543386956), parent name: 'GAMELOOP_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x323BC016 (dec: 842776598), parent name: 'GAMELOOP_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_88fake // hashcode: 0x70DF5DD5 (dec: 1893686741)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x6FC3A177 (dec: 1875091831), parent name: 'GAMELOOP_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xF945B820 (dec: -112871392), parent name: 'GAMELOOP_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_89fake // hashcode: 0x9AABAFBE (dec: -1700024386)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xDD80DC86 (dec: -578757498), parent name: 'GAMELOOP_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x521BADE3 (dec: 1377545699), parent name: 'GAMELOOP_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x9A9C4880 (dec: -1701033856), parent name: 'GAMELOOP_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x09E2F15F (dec: 165867871), parent name: 'GAMELOOP_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x58132703 (dec: 1477650179), parent name: 'GAMELOOP_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_90fake // hashcode: 0x9BC69CEC (dec: -1681482516)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x59CBD321 (dec: 1506530081), parent name: 'GAMELOOP_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xA9A6C491 (dec: -1448688495), parent name: 'GAMELOOP_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_91fake // hashcode: 0x3B642C21 (dec: 996420641)
{
	short index;					// size=0, offset=0 //  hashcode: 0x64496284 (dec: 1682530948), parent name: 'GAMELOOP_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xE0386FE3 (dec: -533172253), parent name: 'GAMELOOP_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xBA464EC1 (dec: -1169797439), parent name: 'GAMELOOP_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xF339DA1A (dec: -214312422), parent name: 'GAMELOOP_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_92fake // hashcode: 0xABF57D70 (dec: -1409974928)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x7DCD722B (dec: 2110616107), parent name: 'GAMELOOP_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xCB173D2E (dec: -887669458), parent name: 'GAMELOOP_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xCDD27F1E (dec: -841842914), parent name: 'GAMELOOP_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_93fake // hashcode: 0x9ADF90E4 (dec: -1696624412)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x29DF0A81 (dec: 702483073), parent name: 'GAMELOOP_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xA74873AA (dec: -1488424022), parent name: 'GAMELOOP_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xCFFA7582 (dec: -805669502), parent name: 'GAMELOOP_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x6ABB69D8 (dec: 1790667224), parent name: 'GAMELOOP_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xD4ECA440 (dec: -722688960), parent name: 'GAMELOOP_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xDAF85A16 (dec: -621258218), parent name: 'GAMELOOP_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xCCE7EA06 (dec: -857216506), parent name: 'GAMELOOP_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_94fake // hashcode: 0x4DA46C7C (dec: 1302621308)
{
	long index;  // size=0, offset=0 //  hashcode: 0xB97E85DB (dec: -1182890533), parent name: 'GAMELOOP_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xE2F37600 (dec: -487361024), parent name: 'GAMELOOP_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_95fake // hashcode: 0xCF6E4E0F (dec: -814854641)
{
	short type; // size=0, offset=0 //  hashcode: 0x26FF6CC8 (dec: 654273736), parent name: 'GAMELOOP_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x09F9D849 (dec: 167368777), parent name: 'GAMELOOP_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_96fake // hashcode: 0xA4D959C0 (dec: -1529259584)
{
	long time;   // size=0, offset=0 //  hashcode: 0xA9431882 (dec: -1455220606), parent name: 'GAMELOOP_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xCE9E47D8 (dec: -828487720), parent name: 'GAMELOOP_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_97fake // hashcode: 0x96694C9B (dec: -1771484005)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x86D124D7 (dec: -2033113897), parent name: 'GAMELOOP_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xB928E376 (dec: -1188502666), parent name: 'GAMELOOP_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_98fake // hashcode: 0xA9F75733 (dec: -1443408077)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x3DCC609D (dec: 1036804253), parent name: 'GAMELOOP_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xD00DB234 (dec: -804408780), parent name: 'GAMELOOP_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_99fake // hashcode: 0xEABB0DF3 (dec: -356839949)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xD71422C0 (dec: -686546240), parent name: 'GAMELOOP_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x93CF4C14 (dec: -1815131116), parent name: 'GAMELOOP_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_100fake // hashcode: 0xC3075533 (dec: -1022929613)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x1B1947A2 (dec: 454641570), parent name: 'GAMELOOP_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x27CE4863 (dec: 667830371), parent name: 'GAMELOOP_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xCE946342 (dec: -829136062), parent name: 'GAMELOOP_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x44F505A1 (dec: 1156908449), parent name: 'GAMELOOP_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_101fake // hashcode: 0xD5767296 (dec: -713657706)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x0D3905D8 (dec: 221840856), parent name: 'GAMELOOP_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xF1F37564 (dec: -235702940), parent name: 'GAMELOOP_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x0BD00156 (dec: 198181206), parent name: 'GAMELOOP_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xE1002EAA (dec: -520081750), parent name: 'GAMELOOP_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xAF2E7B5E (dec: -1355908258), parent name: 'GAMELOOP_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union GAMELOOP_102fake // Hashcode: 0xB3638643 (dec: -1285323197)
{
	struct GAMELOOP_79fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;		 // size=24, offset=0
	struct GAMELOOP_80fake teleport;	 // size=16, offset=0
	struct GAMELOOP_81fake cameraValue;  // size=8, offset=0
	struct GAMELOOP_82fake miscValue;	// size=8, offset=0
	struct GAMELOOP_83fake logicValue;   // size=8, offset=0
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
	struct GAMELOOP_84fake cameraShake;  // size=8, offset=0
	long cameraSave;					 // size=0, offset=0
	long cameraRestore;					 // size=0, offset=0
	struct _BGObject *bgObject;			 // size=24, offset=0
	long value[2];						 // size=8, offset=0
	struct GAMELOOP_85fake sound;		 // size=12, offset=0
	void *intro;						 // size=0, offset=0
	long deathZ;						 // size=0, offset=0
	struct GAMELOOP_86fake dsignal;		 // size=8, offset=0
	void *mirror;						 // size=0, offset=0
	long fogNear;						 // size=0, offset=0
	long fogFar;						 // size=0, offset=0
	struct GAMELOOP_87fake gotoFrame;	// size=8, offset=0
	struct GAMELOOP_88fake changeModel;  // size=8, offset=0
	void *vmObject;						 // size=0, offset=0
	struct GAMELOOP_89fake logic;		 // size=8, offset=0
	void *callSignal;					 // size=0, offset=0
	struct _SVector offset;				 // size=8, offset=0
	struct Signal *gotoLabel;			 // size=0, offset=0
	struct Signal *gosubLabel;			 // size=0, offset=0
	struct GAMELOOP_90fake control;		 // size=8, offset=0
	struct GAMELOOP_91fake zSignal;		 // size=12, offset=0
	struct GAMELOOP_92fake StreamLevel;  // size=24, offset=0
	struct GAMELOOP_93fake shards;		 // size=12, offset=0
	struct GAMELOOP_94fake cameraSpline; // size=8, offset=0
	struct GAMELOOP_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;					 // size=0, offset=0
	struct GAMELOOP_96fake introFX;		 // size=8, offset=0
	struct GAMELOOP_97fake introActive;  // size=8, offset=0
	struct GAMELOOP_98fake levelChange;  // size=18, offset=0
	long blendStart;					 // size=0, offset=0
	struct GAMELOOP_99fake setTimes;	 // size=8, offset=0
	struct GAMELOOP_100fake color;		 // size=4, offset=0
	struct GAMELOOP_101fake print;		 // size=12, offset=0
	long slideAngle;					 // size=0, offset=0
};

union GAMELOOP_103fake // Hashcode: 0x5A2261CA (dec: 1512202698)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union GAMELOOP_108fake // Hashcode: 0x0EA590BB (dec: 245731515)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct GAMELOOP_110fake // hashcode: 0xEDEB677B (dec: -303339653)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x7667AB48 (dec: 1986505544), parent name: 'GAMELOOP_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xD4FD06E1 (dec: -721615135), parent name: 'GAMELOOP_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x83F10178 (dec: -2081357448), parent name: 'GAMELOOP_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x82CEA591 (dec: -2100386415), parent name: 'GAMELOOP_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x61FE551A (dec: 1644057882), parent name: 'GAMELOOP_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xEC0E72F2 (dec: -334597390), parent name: 'GAMELOOP_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x324E659F (dec: 843998623), parent name: 'GAMELOOP_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_111fake // hashcode: 0x175D39A7 (dec: 391985575)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0xAF603806 (dec: -1352648698), parent name: 'GAMELOOP_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xEBB2813A (dec: -340623046), parent name: 'GAMELOOP_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x2738E5F9 (dec: 658040313), parent name: 'GAMELOOP_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_112fake // hashcode: 0x9E206300 (dec: -1642044672)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x9E7BF032 (dec: -1636044750), parent name: 'GAMELOOP_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x2490AB7D (dec: 613460861), parent name: 'GAMELOOP_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x27650F21 (dec: 660934433), parent name: 'GAMELOOP_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xE6595ECB (dec: -430350645), parent name: 'GAMELOOP_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xDCF8B328 (dec: -587680984), parent name: 'GAMELOOP_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_113fake // hashcode: 0x5815D9A1 (dec: 1477826977)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xDD4D3342 (dec: -582143166), parent name: 'GAMELOOP_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x9D36CD38 (dec: -1657352904), parent name: 'GAMELOOP_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x6E7C7C7A (dec: 1853652090), parent name: 'GAMELOOP_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x97BC57BD (dec: -1749264451), parent name: 'GAMELOOP_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xA80CDF08 (dec: -1475551480), parent name: 'GAMELOOP_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_114fake // hashcode: 0xC69001FD (dec: -963640835)
{
	struct GAMELOOP_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x874A5507 (dec: -2025171705), parent name: 'GAMELOOP_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct GAMELOOP_111fake Idle;	  // size=20, offset=28 //  hashcode: 0xC8C64112 (dec: -926531310), parent name: 'GAMELOOP_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct GAMELOOP_112fake Behind;	// size=28, offset=48 //  hashcode: 0x8E8D92BA (dec: -1903324486), parent name: 'GAMELOOP_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct GAMELOOP_113fake Follow;	// size=20, offset=76 //  hashcode: 0x9C82855E (dec: -1669167778), parent name: 'GAMELOOP_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union GAMELOOP_192fake // Hashcode: 0x2687240D (dec: 646390797)
{
	struct Intro *intro;	   // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

struct TGroupObject_alt_definition_0001 // hashcode: 0xE78E7F4B (dec: -410091701)
{
	struct BSPTree *bspTree;		// size=36, offset=0 //  hashcode: 0xE2879003 (dec: -494432253), parent name: 'TGroupObject_alt_definition_0001', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _StreamUnit *streamUnit; // size=0, offset=4 //  hashcode: 0xA83F4313 (dec: -1472249069), parent name: 'TGroupObject_alt_definition_0001', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;					// size=0, offset=8 //  hashcode: 0xE406A04F (dec: -469327793), parent name: 'TGroupObject_alt_definition_0001', parent hashcode: 0xFFFFFFFF (dec: -1)
	short arg[2];					// size=4, offset=12 //  hashcode: 0x07829358 (dec: 125997912), parent name: 'TGroupObject_alt_definition_0001', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AreaObject_alt_definition_0001 // hashcode: 0x03F64396 (dec: 66470806)
{
	struct _StreamUnit *streamUnit; // size=0, offset=0 //  hashcode: 0xA8E460B3 (dec: -1461428045), parent name: 'AreaObject_alt_definition_0001', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;					// size=0, offset=4 //  hashcode: 0x1C8DF077 (dec: 479064183), parent name: 'AreaObject_alt_definition_0001', parent hashcode: 0xFFFFFFFF (dec: -1)
	long unitID;					// size=0, offset=8 //  hashcode: 0x3E1EACDE (dec: 1042197726), parent name: 'AreaObject_alt_definition_0001', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union GAMELOOP_194fake // Hashcode: 0xECD2DF0D (dec: -321724659)
{
	struct _Instance *instance; // size=616, offset=0
	struct _SFXMkr *sfxMarker;  // size=36, offset=0
};

struct GAMELOOP_195fake // hashcode: 0x402C6123 (dec: 1076650275)
{
	long instanceNumber; // size=0, offset=0 //  hashcode: 0x9E6D7653 (dec: -1636993453), parent name: 'GAMELOOP_195fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;		 // size=0, offset=4 //  hashcode: 0xEA6BC1B7 (dec: -362036809), parent name: 'GAMELOOP_195fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_196fake // hashcode: 0x9259C219 (dec: -1839611367)
{
	struct _SavedIntro *intro; // size=40, offset=0 //  hashcode: 0xC786D2CC (dec: -947465524), parent name: 'GAMELOOP_196fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;			   // size=0, offset=4 //  hashcode: 0x642C6F5D (dec: 1680633693), parent name: 'GAMELOOP_196fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_197fake // hashcode: 0xED48B2B1 (dec: -314002767)
{
	long currentNumber; // size=0, offset=0 //  hashcode: 0x09062B88 (dec: 151399304), parent name: 'GAMELOOP_197fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long error;			// size=0, offset=4 //  hashcode: 0xBF78BD1A (dec: -1082606310), parent name: 'GAMELOOP_197fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;		// size=0, offset=8 //  hashcode: 0x922812A0 (dec: -1842867552), parent name: 'GAMELOOP_197fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_198fake // hashcode: 0xAB9FA2B3 (dec: -1415601485)
{
	short vx; // size=0, offset=0 //  hashcode: 0xCAFE058C (dec: -889322100), parent name: 'GAMELOOP_198fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vy; // size=0, offset=2 //  hashcode: 0x916597D7 (dec: -1855612969), parent name: 'GAMELOOP_198fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_199fake // hashcode: 0x6DF52D52 (dec: 1844784466)
{
	char *pointer; // size=0, offset=0 //  hashcode: 0x59024F96 (dec: 1493323670), parent name: 'GAMELOOP_199fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_200fake // hashcode: 0x03AFB75C (dec: 61847388)
{
	short *pointer; // size=0, offset=0 //  hashcode: 0xB0A81F95 (dec: -1331159147), parent name: 'GAMELOOP_200fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_201fake // hashcode: 0xDE6DA7AB (dec: -563238997)
{
	long *pointer; // size=0, offset=0 //  hashcode: 0xAD09C01E (dec: -1391869922), parent name: 'GAMELOOP_201fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union GAMELOOP_202fake // Hashcode: 0x88772473 (dec: -2005457805)
{
	struct GAMELOOP_195fake Object;					  // size=8, offset=0
	struct GAMELOOP_196fake SavedIntroObject;		  // size=8, offset=0
	struct InstanceSpline instanceSpline;			  // size=24, offset=0
	struct GAMELOOP_197fake Number;					  // size=12, offset=0
	struct GAMELOOP_198fake Vector2d;				  // size=4, offset=0
	struct GAMELOOP_199fake CharPointer;			  // size=4, offset=0
	struct GAMELOOP_200fake ShortPointer;			  // size=4, offset=0
	struct GAMELOOP_201fake LongPointer;			  // size=4, offset=0
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

struct GAMELOOP_208fake // hashcode: 0x427F55FA (dec: 1115641338)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x8BD889DD (dec: -1948743203), parent name: 'GAMELOOP_208fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x67A18BD3 (dec: 1738640339), parent name: 'GAMELOOP_208fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMELOOP_209fake // hashcode: 0x60F040D0 (dec: 1626357968)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x419B7277 (dec: 1100706423), parent name: 'GAMELOOP_209fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x2F53F924 (dec: 794032420), parent name: 'GAMELOOP_209fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x0231CB06 (dec: 36817670), parent name: 'GAMELOOP_209fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x479141CB (dec: 1200701899), parent name: 'GAMELOOP_209fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0xC7ABA1A3 (dec: -945053277), parent name: 'GAMELOOP_209fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x621C26A3 (dec: 1646012067), parent name: 'GAMELOOP_209fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union GAMELOOP_210fake // Hashcode: 0x673E5D23 (dec: 1732140323)
{
	struct GAMELOOP_208fake flame; // size=8, offset=0
	struct GAMELOOP_209fake phys;  // size=12, offset=0
};

union GAMELOOP_236fake // Hashcode: 0x41C73D01 (dec: 1103576321)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct StreamUnitPortal // hashcode: 0x7C52D8D9 (dec: 2085804249)
{
	char tolevelname[16];			  // size=16, offset=0 //  hashcode: 0xAF64698B (dec: -1352373877), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	long MSignalID;					  // size=0, offset=16 //  hashcode: 0x67DD3149 (dec: 1742549321), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;					  // size=0, offset=20 //  hashcode: 0x89976466 (dec: -1986567066), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minx;						  // size=0, offset=24 //  hashcode: 0xD517597D (dec: -719890051), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short miny;						  // size=0, offset=26 //  hashcode: 0xC8012DFE (dec: -939446786), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minz;						  // size=0, offset=28 //  hashcode: 0xB82176A3 (dec: -1205766493), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;					  // size=0, offset=30 //  hashcode: 0x77C049D9 (dec: 2009090521), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxx;						  // size=0, offset=32 //  hashcode: 0xD5329B86 (dec: -718103674), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxy;						  // size=0, offset=34 //  hashcode: 0x9E7B3FAB (dec: -1636089941), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxz;						  // size=0, offset=36 //  hashcode: 0xB96C9A64 (dec: -1184064924), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad2;						  // size=0, offset=38 //  hashcode: 0x4444FB2F (dec: 1145371439), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _StreamUnit *toStreamUnit; // size=64, offset=40 //  hashcode: 0x2662837A (dec: 643990394), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector t1[3];			  // size=24, offset=44 //  hashcode: 0xC469BFB5 (dec: -999702603), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector t2[3];			  // size=24, offset=68 //  hashcode: 0xE7EA50BF (dec: -404074305), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union GAMELOOP_291fake // Hashcode: 0x8314828D (dec: -2095807859)
{
	struct _StreamUnit *streamUnit;		 // size=64, offset=0
	struct _ObjectTracker *streamObject; // size=36, offset=0
	struct _ButtonTexture *button;		 // size=16, offset=0
};

typedef struct StreamUnitPortal StreamUnitPortal;

typedef void GlyphProcessFunction();

extern void GAMELOOP_AllocStaticMemory(); // 0x8002D7C8

extern void GAMELOOP_InitGameTracker(); // 0x8002D8B8

extern void GAMELOOP_SystemInit(struct GameTracker *gameTracker); // 0x8002D9B8

extern void GAMELOOP_ResetGameStates(); // 0x8002D9F0

extern void GAMELOOP_ClearGameTracker(); // 0x8002DA10

extern void GAMELOOP_CalcGameTime(); // 0x8002DA58

extern void GAMELOOP_SetGameTime(long timeOfDay); // 0x8002DB04

extern int GAMELOOP_GetTimeOfDay(); // 0x8002DB98

extern int GAMELOOP_GetTimeOfDayIdx(int timeOfDay); // 0x8002DBE4

extern int GAMELOOP_WaitForLoad(); // 0x8002DC28

extern struct _StreamUnit *LoadLevels(char *baseAreaName, struct GameTracker *gameTracker); // 0x8002DC60

extern void GAMELOOP_InitStandardObjects(); // 0x8002DEBC

extern void GAMELOOP_LevelLoadAndInit(char *baseAreaName, struct GameTracker *gameTracker); // 0x8002DF10

extern void GAMELOOP_StreamLevelLoadAndInit(char *baseAreaName, struct GameTracker *gameTracker, int toSignalNum, int fromSignalNum); // 0x8002E220

extern void GAMELOOP_SetScreenWipe(int time, int maxTime, int type); // 0x8002E240

extern void GAMELOOP_HandleScreenWipes(unsigned long **drawot); // 0x8002E254

extern void UpdateFogSettings(struct _StreamUnit *currentUnit, struct Level *level); // 0x8002E6B4

extern int CheckForNoBlend(struct _ColorType *Color); // 0x8002E7DC

extern void BlendToColor(struct _ColorType *target, struct _ColorType *current, struct _ColorType *dest); // 0x8002E824

extern void MainRenderLevel(struct _StreamUnit *currentUnit, unsigned long **drawot); // 0x8002E918

extern void StreamIntroInstancesForUnit(struct _StreamUnit *currentUnit); // 0x8002EE18

extern long StreamRenderLevel(struct _StreamUnit *currentUnit, struct Level *mainLevel, unsigned long **drawot, long portalFogColor); // 0x8002EE58

extern void GAMELOOP_FlipScreenAndDraw(struct GameTracker *gameTracker, unsigned long **drawot); // 0x8002F1A0

extern void GAMELOOP_AddClearPrim(unsigned long **drawot, int override); // 0x8002F254

extern void GAMELOOP_SwitchTheDrawBuffer(unsigned long **drawot); // 0x8002F2FC

extern void GAMELOOP_SetupRenderFunction(struct GameTracker *gameTracker); // 0x8002F37C

extern struct _StreamUnit *GAMELOOP_GetMainRenderUnit(); // 0x8002F398

extern void GAMELOOP_DisplayFrame(struct GameTracker *gameTracker); // 0x8002F458

extern void GAMELOOP_DrawSavedOT(unsigned long **newOT); // 0x8002FC20

extern void ResetPrimPool(); // 0x8002FD98

extern void Switch_For_Redraw(); // 0x8002FE44

extern void GAMELOOP_Set_Pause_Redraw(); // 0x8002FEC0

extern void SaveOT(); // 0x8002FED0

extern void ResetDrawPage(); // 0x80030070

extern void GAMELOOP_Set24FPS(); // 0x800300B0

extern void GAMELOOP_Reset24FPS(); // 0x800300C0

extern void GAMELOOP_DoTimeProcess(); // 0x800300CC

extern void GAMELOOP_Process(struct GameTracker *gameTracker); // 0x800302D0

extern void GAMELOOP_ModeStartRunning(); // 0x80030920

extern void GAMELOOP_ModeStartPause(); // 0x800309F8

extern void GAMELOOP_ChangeMode(); // 0x80030AD0

extern void GAMELOOP_RequestLevelChange(char *name, short number, struct GameTracker *gameTracker); // 0x80030E7C

extern void PSX_GameLoop(struct GameTracker *gameTracker); // 0x80030EFC

extern struct MATRIX *GAMELOOP_GetMatrices(int numMatrices); // 0x80030F28

extern struct GameTracker *GAMELOOP_GetGT(); // 0x80030F5C

#endif
