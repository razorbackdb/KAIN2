#ifndef MONSENSE_H
#define MONSENSE_H

static int gNumMaterialMonsters; // offset 0x800CF634

static int gNumMonsters; // offset 0x800CF62C

static int gNumSpectralMonsters; // offset 0x800CF630

static int lastSenseFrame; // offset 0x800D49C8

static struct _MonsterVars(*monsterSenseArray[40]); // offset 0x800D4900

static char monsterSensed[40]; // offset 0x800D49A0

static struct RadarInfo radarDir[8]; // offset 0x800CF638

static unsigned char radarDirIndex[8]; // offset 0x800CF668

struct MONSENSE_73fake // hashcode: 0xEC22D839 (dec: -333260743)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xD494B23C (dec: -728452548), parent name: 'MONSENSE_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x161E84E2 (dec: 371098850), parent name: 'MONSENSE_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_74fake // hashcode: 0x90E3C442 (dec: -1864121278)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xC1997AFB (dec: -1046906117), parent name: 'MONSENSE_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x2D053976 (dec: 755317110), parent name: 'MONSENSE_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_75fake // hashcode: 0x2CD47D4C (dec: 752123212)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x188EC099 (dec: 412008601), parent name: 'MONSENSE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xDC88E9DD (dec: -595007011), parent name: 'MONSENSE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONSENSE_76fake // Hashcode: 0x2B30D328 (dec: 724620072)
{
	struct MONSENSE_73fake callback; // size=8, offset=0
	struct MONSENSE_74fake vector;   // size=12, offset=0
	struct MONSENSE_75fake quat;	 // size=16, offset=0
};

union MONSENSE_77fake // Hashcode: 0x25544503 (dec: 626279683)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MONSENSE_78fake // Hashcode: 0xB93C7E8C (dec: -1187217780)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct MONSENSE_79fake // hashcode: 0x9350B570 (dec: -1823427216)
{
	union MONSENSE_78fake size; // size=4, offset=0 //  hashcode: 0xD16FEC08 (dec: -781194232), parent name: 'MONSENSE_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_80fake // hashcode: 0x1D956F04 (dec: 496332548)
{
	short x;				// size=0, offset=0 //  hashcode: 0x22F5FE77 (dec: 586546807), parent name: 'MONSENSE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x5205D45C (dec: 1376113756), parent name: 'MONSENSE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xA3D9B23D (dec: -1546014147), parent name: 'MONSENSE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x9EC330E5 (dec: -1631375131), parent name: 'MONSENSE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x7A30B695 (dec: 2050012821), parent name: 'MONSENSE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_81fake // hashcode: 0x5830B8BD (dec: 1479588029)
{
	long index; // size=0, offset=0 //  hashcode: 0x1573D53B (dec: 359912763), parent name: 'MONSENSE_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x98920538 (dec: -1735260872), parent name: 'MONSENSE_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_82fake // hashcode: 0x1631D3D3 (dec: 372364243)
{
	long index; // size=0, offset=0 //  hashcode: 0xEB403917 (dec: -348112617), parent name: 'MONSENSE_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x44EA962D (dec: 1156224557), parent name: 'MONSENSE_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_83fake // hashcode: 0x2E46B677 (dec: 776386167)
{
	long index; // size=0, offset=0 //  hashcode: 0x082DC522 (dec: 137217314), parent name: 'MONSENSE_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x7925758B (dec: 2032498059), parent name: 'MONSENSE_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_84fake // hashcode: 0x3E2135CE (dec: 1042363854)
{
	long time;  // size=0, offset=0 //  hashcode: 0x40002AE1 (dec: 1073752801), parent name: 'MONSENSE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x49625FF0 (dec: 1231183856), parent name: 'MONSENSE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_85fake // hashcode: 0xA9A4DE55 (dec: -1448812971)
{
	long action;   // size=0, offset=0 //  hashcode: 0xF45DC2D2 (dec: -195181870), parent name: 'MONSENSE_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x855D48D7 (dec: -2057484073), parent name: 'MONSENSE_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_86fake // hashcode: 0x24DB33A9 (dec: 618345385)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x92C0ADD6 (dec: -1832866346), parent name: 'MONSENSE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xABA3DD72 (dec: -1415324302), parent name: 'MONSENSE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_87fake // hashcode: 0xD8B135EF (dec: -659474961)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x1C52D55D (dec: 475190621), parent name: 'MONSENSE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x7DB6433A (dec: 2109096762), parent name: 'MONSENSE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_88fake // hashcode: 0x241E656D (dec: 605971821)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xF5FFD2A7 (dec: -167783769), parent name: 'MONSENSE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x0D6436E3 (dec: 224671459), parent name: 'MONSENSE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_89fake // hashcode: 0x083A7468 (dec: 138048616)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x95A39C68 (dec: -1784439704), parent name: 'MONSENSE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xBBEB52D7 (dec: -1142205737), parent name: 'MONSENSE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x340F78FF (dec: 873429247), parent name: 'MONSENSE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xA9BBBAC0 (dec: -1447314752), parent name: 'MONSENSE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x5DE5295B (dec: 1575299419), parent name: 'MONSENSE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_90fake // hashcode: 0x461ED26D (dec: 1176425069)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x62356E33 (dec: 1647668787), parent name: 'MONSENSE_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xB9D2F655 (dec: -1177356715), parent name: 'MONSENSE_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_91fake // hashcode: 0xD7570091 (dec: -682164079)
{
	short index;					// size=0, offset=0 //  hashcode: 0xDC8A6D48 (dec: -594907832), parent name: 'MONSENSE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x66F31D18 (dec: 1727208728), parent name: 'MONSENSE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x995DF199 (dec: -1721896551), parent name: 'MONSENSE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x98F8D79A (dec: -1728522342), parent name: 'MONSENSE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_92fake // hashcode: 0x8F1E1721 (dec: -1893853407)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xC5C9A67A (dec: -976640390), parent name: 'MONSENSE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x31B75942 (dec: 834099522), parent name: 'MONSENSE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x637BDE4B (dec: 1669062219), parent name: 'MONSENSE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_93fake // hashcode: 0x09468A8B (dec: 155617931)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x4199CADA (dec: 1100597978), parent name: 'MONSENSE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x213C5401 (dec: 557601793), parent name: 'MONSENSE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xBA50F500 (dec: -1169099520), parent name: 'MONSENSE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x29DF0124 (dec: 702480676), parent name: 'MONSENSE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x720E8490 (dec: 1913554064), parent name: 'MONSENSE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xB3C2D598 (dec: -1279076968), parent name: 'MONSENSE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x71F7CD8E (dec: 1912065422), parent name: 'MONSENSE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_94fake // hashcode: 0xD009F5D2 (dec: -804653614)
{
	long index;  // size=0, offset=0 //  hashcode: 0x467EBBA7 (dec: 1182710695), parent name: 'MONSENSE_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xAD0DE574 (dec: -1391598220), parent name: 'MONSENSE_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_95fake // hashcode: 0x227B9246 (dec: 578523718)
{
	short type; // size=0, offset=0 //  hashcode: 0xD1A64CA9 (dec: -777630551), parent name: 'MONSENSE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x4C663213 (dec: 1281765907), parent name: 'MONSENSE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_96fake // hashcode: 0x2907ADC7 (dec: 688369095)
{
	long time;   // size=0, offset=0 //  hashcode: 0xB55C6401 (dec: -1252236287), parent name: 'MONSENSE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x6DE36180 (dec: 1843618176), parent name: 'MONSENSE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_97fake // hashcode: 0x071ED0BF (dec: 119460031)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xDE40CD3C (dec: -566178500), parent name: 'MONSENSE_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x33F31D35 (dec: 871570741), parent name: 'MONSENSE_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_98fake // hashcode: 0xCAFE6969 (dec: -889296535)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xFC93D0C9 (dec: -57421623), parent name: 'MONSENSE_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x71CA04FC (dec: 1909064956), parent name: 'MONSENSE_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_99fake // hashcode: 0xC04A1034 (dec: -1068888012)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x0D40D80D (dec: 222353421), parent name: 'MONSENSE_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x886E107A (dec: -2006052742), parent name: 'MONSENSE_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_100fake // hashcode: 0xC13B197C (dec: -1053091460)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0xAFEBD9DE (dec: -1343497762), parent name: 'MONSENSE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x4952A836 (dec: 1230153782), parent name: 'MONSENSE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x4768CD9F (dec: 1198050719), parent name: 'MONSENSE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xD9716841 (dec: -646879167), parent name: 'MONSENSE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_101fake // hashcode: 0x9BC4339D (dec: -1681640547)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x2A6CA7D6 (dec: 711763926), parent name: 'MONSENSE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x4981F6A0 (dec: 1233254048), parent name: 'MONSENSE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x70F612E2 (dec: 1895174882), parent name: 'MONSENSE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x4DC69E37 (dec: 1304862263), parent name: 'MONSENSE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x65EAC6AE (dec: 1709885102), parent name: 'MONSENSE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONSENSE_102fake // Hashcode: 0x6536825F (dec: 1698071135)
{
	struct MONSENSE_79fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;		 // size=24, offset=0
	struct MONSENSE_80fake teleport;	 // size=16, offset=0
	struct MONSENSE_81fake cameraValue;  // size=8, offset=0
	struct MONSENSE_82fake miscValue;	// size=8, offset=0
	struct MONSENSE_83fake logicValue;   // size=8, offset=0
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
	struct MONSENSE_84fake cameraShake;  // size=8, offset=0
	long cameraSave;					 // size=0, offset=0
	long cameraRestore;					 // size=0, offset=0
	struct _BGObject *bgObject;			 // size=24, offset=0
	long value[2];						 // size=8, offset=0
	struct MONSENSE_85fake sound;		 // size=12, offset=0
	void *intro;						 // size=0, offset=0
	long deathZ;						 // size=0, offset=0
	struct MONSENSE_86fake dsignal;		 // size=8, offset=0
	void *mirror;						 // size=0, offset=0
	long fogNear;						 // size=0, offset=0
	long fogFar;						 // size=0, offset=0
	struct MONSENSE_87fake gotoFrame;	// size=8, offset=0
	struct MONSENSE_88fake changeModel;  // size=8, offset=0
	void *vmObject;						 // size=0, offset=0
	struct MONSENSE_89fake logic;		 // size=8, offset=0
	void *callSignal;					 // size=0, offset=0
	struct _SVector offset;				 // size=8, offset=0
	struct Signal *gotoLabel;			 // size=0, offset=0
	struct Signal *gosubLabel;			 // size=0, offset=0
	struct MONSENSE_90fake control;		 // size=8, offset=0
	struct MONSENSE_91fake zSignal;		 // size=12, offset=0
	struct MONSENSE_92fake StreamLevel;  // size=24, offset=0
	struct MONSENSE_93fake shards;		 // size=12, offset=0
	struct MONSENSE_94fake cameraSpline; // size=8, offset=0
	struct MONSENSE_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;					 // size=0, offset=0
	struct MONSENSE_96fake introFX;		 // size=8, offset=0
	struct MONSENSE_97fake introActive;  // size=8, offset=0
	struct MONSENSE_98fake levelChange;  // size=18, offset=0
	long blendStart;					 // size=0, offset=0
	struct MONSENSE_99fake setTimes;	 // size=8, offset=0
	struct MONSENSE_100fake color;		 // size=4, offset=0
	struct MONSENSE_101fake print;		 // size=12, offset=0
	long slideAngle;					 // size=0, offset=0
};

union MONSENSE_103fake // Hashcode: 0xBADB3D06 (dec: -1160037114)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union MONSENSE_108fake // Hashcode: 0xF7DF379A (dec: -136366182)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct MONSENSE_110fake // hashcode: 0xF03A03BB (dec: -264633413)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x1D9E5BC8 (dec: 496917448), parent name: 'MONSENSE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xF62048B6 (dec: -165656394), parent name: 'MONSENSE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x0B2F6538 (dec: 187655480), parent name: 'MONSENSE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x70B0215E (dec: 1890591070), parent name: 'MONSENSE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x3F05332F (dec: 1057305391), parent name: 'MONSENSE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x8EF4B853 (dec: -1896564653), parent name: 'MONSENSE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x2FFDFA39 (dec: 805173817), parent name: 'MONSENSE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_111fake // hashcode: 0x4D293F0A (dec: 1294548746)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x7B128D7A (dec: 2064813434), parent name: 'MONSENSE_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x4E6F6BFA (dec: 1315924986), parent name: 'MONSENSE_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xB221E013 (dec: -1306402797), parent name: 'MONSENSE_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_112fake // hashcode: 0x63A61752 (dec: 1671829330)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x6B43FC1A (dec: 1799617562), parent name: 'MONSENSE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xF8B666F9 (dec: -122263815), parent name: 'MONSENSE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xC1BDAA31 (dec: -1044534735), parent name: 'MONSENSE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x8D2C6184 (dec: -1926471292), parent name: 'MONSENSE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x07D8438E (dec: 131613582), parent name: 'MONSENSE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_113fake // hashcode: 0x7AC9A4F3 (dec: 2060035315)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x31147E1F (dec: 823426591), parent name: 'MONSENSE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0xB6C794C0 (dec: -1228434240), parent name: 'MONSENSE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x806FDA6F (dec: -2140153233), parent name: 'MONSENSE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xBD019CA0 (dec: -1123967840), parent name: 'MONSENSE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x2150F564 (dec: 558953828), parent name: 'MONSENSE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSENSE_114fake // hashcode: 0x5589BD82 (dec: 1435090306)
{
	struct MONSENSE_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x3826056A (dec: 942015850), parent name: 'MONSENSE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MONSENSE_111fake Idle;	  // size=20, offset=28 //  hashcode: 0x559B4DAC (dec: 1436241324), parent name: 'MONSENSE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MONSENSE_112fake Behind;	// size=28, offset=48 //  hashcode: 0x8268878D (dec: -2107078771), parent name: 'MONSENSE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MONSENSE_113fake Follow;	// size=20, offset=76 //  hashcode: 0x925F3D2F (dec: -1839252177), parent name: 'MONSENSE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONSENSE_196fake // Hashcode: 0xA7338706 (dec: -1489795322)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct RadarInfo // hashcode: 0xB8957CDE (dec: -1198162722)
{
	short angle; // size=0, offset=0 //  hashcode: 0x5EEC704C (dec: 1592553548), parent name: 'RadarInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x;	 // size=0, offset=2 //  hashcode: 0x93A642D8 (dec: -1817820456), parent name: 'RadarInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=4 //  hashcode: 0xAC2AC700 (dec: -1406482688), parent name: 'RadarInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct RadarInfo RadarInfo;

extern struct _MonsterIR *MONSENSE_FindIR(struct _MonsterVars *mv, struct _Instance *instance); // 0x80085AA4

extern int MONSENSE_See(struct _Instance *instance, struct evCollideInstanceStatsData *data); // 0x80085ADC

extern int MONSENSE_Hear(struct _Instance *instance, struct evCollideInstanceStatsData *data); // 0x80085C78

extern int MONSENSE_Smell(struct _Instance *instance, struct evCollideInstanceStatsData *data); // 0x80085D08

extern struct _MonsterIR *MONSENSE_FirstSense(struct _Instance *instance, struct _Instance *sensed); // 0x80085D30

extern void MONSENSE_SetupMIR(struct _Instance *instance, struct evCollideInstanceStatsData *data, int flags); // 0x80085ED4

extern void MONSENSE_SenseInstance(struct _Instance *instance, struct evCollideInstanceStatsData *data); // 0x80086300

extern void MONSENSE_StartMonsterIRList(struct _Instance *instance); // 0x800864F4

extern struct _MonsterIR *MONSENSE_GetMonsterIR(struct _MonsterVars *mv); // 0x80086608

extern void MONSENSE_InitIRList(struct _MonsterVars *mv, struct _MonsterIR *list, int num); // 0x80086630

extern struct _MonsterIR *MONSENSE_SetEnemy(struct _Instance *instance, struct _Instance *newenemy); // 0x8008665C

extern void MONSENSE_ProcessIRList(struct _Instance *instance); // 0x8008677C

extern void MONSENSE_SetupSenses(struct _Instance *instance); // 0x8008699C

extern void MONSENSE_RemoveSenses(struct _Instance *instance); // 0x80086B08

extern void MONSENSE_Radar(struct _Instance *instance); // 0x80086BA8

extern short MONSENSE_GetClosestFreeDirection(struct _Instance *instance, short angle, long range); // 0x80086DE4

extern int MONSENSE_GetDistanceInDirection(struct _Instance *instance, short angle); // 0x80086EE8

extern void MONSENSE_DoSenses(struct _Instance *instance); // 0x80086F20

extern void MONSENSE_AdjustRadarFromObjects(struct _Instance *instance); // 0x80087018

#endif
