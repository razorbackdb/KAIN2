#ifndef UNDRWRLD_H
#define UNDRWRLD_H

static struct UW_ScreenXY *ScreenMorphArray; // offset 0x800CF894

static long UW_angle; // offset 0x800D59B0

static long UW_angleInc; // offset 0x800D59BC

static long UW_scalex; // offset 0x800D59B4

static long UW_scalexInc; // offset 0x800D59B8

struct DR_STP // hashcode: 0x8C972396 (dec: -1936252010)
{
	unsigned long tag;	 // size=0, offset=0 //  hashcode: 0xCAA11100 (dec: -895414016), parent name: 'DR_STP', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long code[2]; // size=8, offset=4 //  hashcode: 0x7C326E37 (dec: 2083679799), parent name: 'DR_STP', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_73fake // hashcode: 0xB5A9801A (dec: -1247182822)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x12F4D7B7 (dec: 318035895), parent name: 'UNDRWRLD_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x20B1F74B (dec: 548534091), parent name: 'UNDRWRLD_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_74fake // hashcode: 0x5DF99F02 (dec: 1576640258)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x0170AD0F (dec: 24161551), parent name: 'UNDRWRLD_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x62426ED1 (dec: 1648520913), parent name: 'UNDRWRLD_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_75fake // hashcode: 0x20AE4C69 (dec: 548293737)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x9376267C (dec: -1820973444), parent name: 'UNDRWRLD_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x7967380A (dec: 2036807690), parent name: 'UNDRWRLD_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union UNDRWRLD_76fake // Hashcode: 0x6E59B9C2 (dec: 1851374018)
{
	struct UNDRWRLD_73fake callback; // size=8, offset=0
	struct UNDRWRLD_74fake vector;   // size=12, offset=0
	struct UNDRWRLD_75fake quat;	 // size=16, offset=0
};

union UNDRWRLD_77fake // Hashcode: 0x395B97AA (dec: 962303914)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union UNDRWRLD_78fake // Hashcode: 0xA1209DA1 (dec: -1591698015)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct UNDRWRLD_79fake // hashcode: 0xEA7A236F (dec: -361094289)
{
	union UNDRWRLD_78fake size; // size=4, offset=0 //  hashcode: 0xEDBC2BCF (dec: -306435121), parent name: 'UNDRWRLD_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_80fake // hashcode: 0x12E004A4 (dec: 316671140)
{
	short x;				// size=0, offset=0 //  hashcode: 0x9030A65B (dec: -1875859877), parent name: 'UNDRWRLD_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x0479150F (dec: 75044111), parent name: 'UNDRWRLD_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x55B2CEFF (dec: 1437781759), parent name: 'UNDRWRLD_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x0F394334 (dec: 255410996), parent name: 'UNDRWRLD_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x88D6781F (dec: -1999210465), parent name: 'UNDRWRLD_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_81fake // hashcode: 0x336BECB7 (dec: 862710967)
{
	long index; // size=0, offset=0 //  hashcode: 0xF842EE5C (dec: -129831332), parent name: 'UNDRWRLD_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xA204AECC (dec: -1576751412), parent name: 'UNDRWRLD_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_82fake // hashcode: 0x629E6705 (dec: 1654548229)
{
	long index; // size=0, offset=0 //  hashcode: 0x67B2DA53 (dec: 1739774547), parent name: 'UNDRWRLD_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x1B2D19C6 (dec: 455940550), parent name: 'UNDRWRLD_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_83fake // hashcode: 0xDE84155D (dec: -561769123)
{
	long index; // size=0, offset=0 //  hashcode: 0x657DCAD3 (dec: 1702742739), parent name: 'UNDRWRLD_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xF5D0DF60 (dec: -170860704), parent name: 'UNDRWRLD_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_84fake // hashcode: 0xE48374A9 (dec: -461146967)
{
	long time;  // size=0, offset=0 //  hashcode: 0xAEB577C9 (dec: -1363839031), parent name: 'UNDRWRLD_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x70A5FCD1 (dec: 1889926353), parent name: 'UNDRWRLD_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_85fake // hashcode: 0xABA1707C (dec: -1415483268)
{
	long action;   // size=0, offset=0 //  hashcode: 0xCC304F3B (dec: -869249221), parent name: 'UNDRWRLD_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x69505E4F (dec: 1766874703), parent name: 'UNDRWRLD_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_86fake // hashcode: 0x233667CD (dec: 590768077)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xC520DCFA (dec: -987702022), parent name: 'UNDRWRLD_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xDB346233 (dec: -617323981), parent name: 'UNDRWRLD_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_87fake // hashcode: 0x34A8B97C (dec: 883472764)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x4491761E (dec: 1150383646), parent name: 'UNDRWRLD_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0xA533C082 (dec: -1523335038), parent name: 'UNDRWRLD_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_88fake // hashcode: 0x0735D364 (dec: 120968036)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xB0AE72EE (dec: -1330744594), parent name: 'UNDRWRLD_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xE114EF5F (dec: -518721697), parent name: 'UNDRWRLD_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_89fake // hashcode: 0xAB4CCC30 (dec: -1421030352)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x83E540DF (dec: -2082127649), parent name: 'UNDRWRLD_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x51B26260 (dec: 1370645088), parent name: 'UNDRWRLD_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x0F00A119 (dec: 251699481), parent name: 'UNDRWRLD_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x3CF85738 (dec: 1022908216), parent name: 'UNDRWRLD_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xA08BCCBE (dec: -1601450818), parent name: 'UNDRWRLD_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_90fake // hashcode: 0x379D9770 (dec: 933074800)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x61987F8C (dec: 1637384076), parent name: 'UNDRWRLD_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x3AF0CF31 (dec: 988860209), parent name: 'UNDRWRLD_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_91fake // hashcode: 0x5B16D92A (dec: 1528224042)
{
	short index;					// size=0, offset=0 //  hashcode: 0x618EFD69 (dec: 1636760937), parent name: 'UNDRWRLD_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x42D45F97 (dec: 1121214359), parent name: 'UNDRWRLD_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x144D97C8 (dec: 340629448), parent name: 'UNDRWRLD_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xA77CD1D0 (dec: -1484992048), parent name: 'UNDRWRLD_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_92fake // hashcode: 0xA15BF1DB (dec: -1587809829)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x55A4EFE6 (dec: 1436872678), parent name: 'UNDRWRLD_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xD1EBB0CB (dec: -773082933), parent name: 'UNDRWRLD_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xF7814201 (dec: -142523903), parent name: 'UNDRWRLD_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_93fake // hashcode: 0x4A76EB15 (dec: 1249307413)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x0C2EF9C5 (dec: 204405189), parent name: 'UNDRWRLD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xD41783A7 (dec: -736656473), parent name: 'UNDRWRLD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xA18E9859 (dec: -1584490407), parent name: 'UNDRWRLD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x5F996490 (dec: 1603888272), parent name: 'UNDRWRLD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x20DBE09C (dec: 551280796), parent name: 'UNDRWRLD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x3EA3B35D (dec: 1050915677), parent name: 'UNDRWRLD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xEA3525D1 (dec: -365615663), parent name: 'UNDRWRLD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_94fake // hashcode: 0x0C4389ED (dec: 205752813)
{
	long index;  // size=0, offset=0 //  hashcode: 0x41597396 (dec: 1096381334), parent name: 'UNDRWRLD_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xD30E0998 (dec: -754054760), parent name: 'UNDRWRLD_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_95fake // hashcode: 0x67B9A0E0 (dec: 1740218592)
{
	short type; // size=0, offset=0 //  hashcode: 0xF25F2802 (dec: -228644862), parent name: 'UNDRWRLD_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x12523488 (dec: 307377288), parent name: 'UNDRWRLD_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_96fake // hashcode: 0x07C9C6B3 (dec: 130664115)
{
	long time;   // size=0, offset=0 //  hashcode: 0xC636EF19 (dec: -969478375), parent name: 'UNDRWRLD_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x5EF1ACF4 (dec: 1592896756), parent name: 'UNDRWRLD_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_97fake // hashcode: 0xE2DD1F3F (dec: -488825025)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xCA8A34EF (dec: -896912145), parent name: 'UNDRWRLD_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xD50A3F78 (dec: -720748680), parent name: 'UNDRWRLD_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_98fake // hashcode: 0x4F15B920 (dec: 1326823712)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x0D2CDB8D (dec: 221043597), parent name: 'UNDRWRLD_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x0A04AA93 (dec: 168077971), parent name: 'UNDRWRLD_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_99fake // hashcode: 0xAE8C6C53 (dec: -1366528941)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xAE0FCF55 (dec: -1374695595), parent name: 'UNDRWRLD_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xAAA227B3 (dec: -1432213581), parent name: 'UNDRWRLD_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_100fake // hashcode: 0xE84F3C46 (dec: -397460410)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0xB9FF443F (dec: -1174453185), parent name: 'UNDRWRLD_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x2F59DDD8 (dec: 794418648), parent name: 'UNDRWRLD_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xA734A27F (dec: -1489722753), parent name: 'UNDRWRLD_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x2E63923E (dec: 778277438), parent name: 'UNDRWRLD_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_101fake // hashcode: 0xB130863B (dec: -1322219973)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x81F358E7 (dec: -2114758425), parent name: 'UNDRWRLD_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x227084C4 (dec: 577799364), parent name: 'UNDRWRLD_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xCDBA782D (dec: -843417555), parent name: 'UNDRWRLD_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xBB8B5AB6 (dec: -1148495178), parent name: 'UNDRWRLD_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x3203D359 (dec: 839111513), parent name: 'UNDRWRLD_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union UNDRWRLD_102fake // Hashcode: 0x15BF52AB (dec: 364860075)
{
	struct UNDRWRLD_79fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;		 // size=24, offset=0
	struct UNDRWRLD_80fake teleport;	 // size=16, offset=0
	struct UNDRWRLD_81fake cameraValue;  // size=8, offset=0
	struct UNDRWRLD_82fake miscValue;	// size=8, offset=0
	struct UNDRWRLD_83fake logicValue;   // size=8, offset=0
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
	struct UNDRWRLD_84fake cameraShake;  // size=8, offset=0
	long cameraSave;					 // size=0, offset=0
	long cameraRestore;					 // size=0, offset=0
	struct _BGObject *bgObject;			 // size=24, offset=0
	long value[2];						 // size=8, offset=0
	struct UNDRWRLD_85fake sound;		 // size=12, offset=0
	void *intro;						 // size=0, offset=0
	long deathZ;						 // size=0, offset=0
	struct UNDRWRLD_86fake dsignal;		 // size=8, offset=0
	void *mirror;						 // size=0, offset=0
	long fogNear;						 // size=0, offset=0
	long fogFar;						 // size=0, offset=0
	struct UNDRWRLD_87fake gotoFrame;	// size=8, offset=0
	struct UNDRWRLD_88fake changeModel;  // size=8, offset=0
	void *vmObject;						 // size=0, offset=0
	struct UNDRWRLD_89fake logic;		 // size=8, offset=0
	void *callSignal;					 // size=0, offset=0
	struct _SVector offset;				 // size=8, offset=0
	struct Signal *gotoLabel;			 // size=0, offset=0
	struct Signal *gosubLabel;			 // size=0, offset=0
	struct UNDRWRLD_90fake control;		 // size=8, offset=0
	struct UNDRWRLD_91fake zSignal;		 // size=12, offset=0
	struct UNDRWRLD_92fake StreamLevel;  // size=24, offset=0
	struct UNDRWRLD_93fake shards;		 // size=12, offset=0
	struct UNDRWRLD_94fake cameraSpline; // size=8, offset=0
	struct UNDRWRLD_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;					 // size=0, offset=0
	struct UNDRWRLD_96fake introFX;		 // size=8, offset=0
	struct UNDRWRLD_97fake introActive;  // size=8, offset=0
	struct UNDRWRLD_98fake levelChange;  // size=18, offset=0
	long blendStart;					 // size=0, offset=0
	struct UNDRWRLD_99fake setTimes;	 // size=8, offset=0
	struct UNDRWRLD_100fake color;		 // size=4, offset=0
	struct UNDRWRLD_101fake print;		 // size=12, offset=0
	long slideAngle;					 // size=0, offset=0
};

union UNDRWRLD_103fake // Hashcode: 0x539A1D7B (dec: 1402609019)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union UNDRWRLD_108fake // Hashcode: 0xF0632AED (dec: -261936403)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct UNDRWRLD_110fake // hashcode: 0xC5E3B76C (dec: -974932116)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xDBA7C752 (dec: -609761454), parent name: 'UNDRWRLD_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x56536A12 (dec: 1448307218), parent name: 'UNDRWRLD_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x65EDB513 (dec: 1710077203), parent name: 'UNDRWRLD_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x4DD49028 (dec: 1305776168), parent name: 'UNDRWRLD_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x67B510CE (dec: 1739919566), parent name: 'UNDRWRLD_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x825D9E35 (dec: -2107793867), parent name: 'UNDRWRLD_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xD3F0DA32 (dec: -739190222), parent name: 'UNDRWRLD_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_111fake // hashcode: 0xB4ED07C2 (dec: -1259534398)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0xE6DBB866 (dec: -421808026), parent name: 'UNDRWRLD_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x6A979466 (dec: 1788318822), parent name: 'UNDRWRLD_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x27F4C0BC (dec: 670351548), parent name: 'UNDRWRLD_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_112fake // hashcode: 0xDAB30BA0 (dec: -625800288)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x9A07B31F (dec: -1710771425), parent name: 'UNDRWRLD_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xC35E3B62 (dec: -1017234590), parent name: 'UNDRWRLD_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xB59885C9 (dec: -1248295479), parent name: 'UNDRWRLD_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xFB748525 (dec: -76249819), parent name: 'UNDRWRLD_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xFBB9F7BB (dec: -71698501), parent name: 'UNDRWRLD_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_113fake // hashcode: 0xA8ADBAE1 (dec: -1465009439)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x74696817 (dec: 1953064983), parent name: 'UNDRWRLD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x2F3DBBEC (dec: 792574956), parent name: 'UNDRWRLD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x29FA44D2 (dec: 704267474), parent name: 'UNDRWRLD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xE8D5E3AB (dec: -388635733), parent name: 'UNDRWRLD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xDAE91394 (dec: -622259308), parent name: 'UNDRWRLD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_114fake // hashcode: 0x3CF3A383 (dec: 1022600067)
{
	struct UNDRWRLD_110fake Cinematic; // size=28, offset=0 //  hashcode: 0xDD53DEDE (dec: -581706018), parent name: 'UNDRWRLD_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct UNDRWRLD_111fake Idle;	  // size=20, offset=28 //  hashcode: 0x0F5ECB81 (dec: 257870721), parent name: 'UNDRWRLD_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct UNDRWRLD_112fake Behind;	// size=28, offset=48 //  hashcode: 0x0314BE53 (dec: 51691091), parent name: 'UNDRWRLD_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct UNDRWRLD_113fake Follow;	// size=20, offset=76 //  hashcode: 0x2BA23271 (dec: 732050033), parent name: 'UNDRWRLD_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union UNDRWRLD_195fake // Hashcode: 0xA8618D78 (dec: -1470001800)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct UNDRWRLD_221fake // hashcode: 0xAF7DFF06 (dec: -1350697210)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x7857CD20 (dec: 2019020064), parent name: 'UNDRWRLD_221fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x22320221 (dec: 573702689), parent name: 'UNDRWRLD_221fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UNDRWRLD_222fake // hashcode: 0x7CE0EF84 (dec: 2095116164)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0xED5A7A3B (dec: -312837573), parent name: 'UNDRWRLD_222fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x6C43E1A5 (dec: 1816388005), parent name: 'UNDRWRLD_222fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x1F5DB1BE (dec: 526234046), parent name: 'UNDRWRLD_222fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x732208B9 (dec: 1931610297), parent name: 'UNDRWRLD_222fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0xD5FAF38F (dec: -704973937), parent name: 'UNDRWRLD_222fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x03323185 (dec: 53621125), parent name: 'UNDRWRLD_222fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union UNDRWRLD_223fake // Hashcode: 0x298755E5 (dec: 696735205)
{
	struct UNDRWRLD_221fake flame; // size=8, offset=0
	struct UNDRWRLD_222fake phys;  // size=12, offset=0
};

struct UW_ScreenXY // hashcode: 0x88757B16 (dec: -2005566698)
{
	short sx; // size=0, offset=0 //  hashcode: 0xB7D75544 (dec: -1210624700), parent name: 'UW_ScreenXY', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sy; // size=0, offset=2 //  hashcode: 0x075C8EBC (dec: 123506364), parent name: 'UW_ScreenXY', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dx; // size=0, offset=4 //  hashcode: 0x15E657C8 (dec: 367417288), parent name: 'UW_ScreenXY', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dy; // size=0, offset=6 //  hashcode: 0x8C82ED03 (dec: -1937576701), parent name: 'UW_ScreenXY', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct DR_STP DR_STP;

typedef struct UW_ScreenXY UW_ScreenXY;

extern void UNDERWORLD_StartProcess(); // 0x800B4B90

extern long UNDERWORLD_RotateScreenStep(long time); // 0x800B4C14

extern void UNDERWORLD_DoUV(unsigned char *uv, struct UW_ScreenXY *p0, int tx); // 0x800B4D80

extern struct POLY_GT3 *UNDERWORLD_Poly(struct POLY_GT3 *last, struct UW_ScreenXY *p0, struct UW_ScreenXY *p1, struct UW_ScreenXY *p2, int drawY); // 0x800B4DCC

extern void UNDERWORLD_DisplayFrame(long *primStart, long drawY); // 0x800B4F44

extern void UNDERWORLD_SetupSource(); // 0x800B509C

extern void UNDERWORLD_InitDisplayProcess(); // 0x800B5148

extern struct _StreamUnit *UNDERWORLD_LoadLevel(char *baseAreaName, struct GameTracker *gameTracker); // 0x800B5208

extern void UNDERWORLD_UpdatePlayer(struct Intro *playerIntro, struct _Instance *instance); // 0x800B5500

#endif
