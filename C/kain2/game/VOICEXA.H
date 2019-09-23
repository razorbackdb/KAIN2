#ifndef VOICEXA_H
#define VOICEXA_H

extern struct XAVoiceTracker voiceTracker; // offset 0x800D5AD4

struct CdlFILTER // hashcode: 0x62FCDD39 (dec: 1660738873)
{
	unsigned char file; // size=0, offset=0 //  hashcode: 0x9628E755 (dec: -1775704235), parent name: 'CdlFILTER', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char chan; // size=0, offset=1 //  hashcode: 0x1255EC13 (dec: 307620883), parent name: 'CdlFILTER', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad; // size=0, offset=2 //  hashcode: 0x900EE70F (dec: -1878071537), parent name: 'CdlFILTER', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SpuCommonAttr // hashcode: 0xCB591BFF (dec: -883352577)
{
	unsigned long mask;		   // size=0, offset=0 //  hashcode: 0xE4CBE348 (dec: -456400056), parent name: 'SpuCommonAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SpuVolume mvol;	 // size=4, offset=4 //  hashcode: 0xECADDB23 (dec: -324150493), parent name: 'SpuCommonAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SpuVolume mvolmode; // size=4, offset=8 //  hashcode: 0x43487801 (dec: 1128822785), parent name: 'SpuCommonAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SpuVolume mvolx;	// size=4, offset=12 //  hashcode: 0x6A0E4EDB (dec: 1779322587), parent name: 'SpuCommonAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SpuExtAttr cd;	  // size=12, offset=16 //  hashcode: 0x7B0EDCD6 (dec: 2064571606), parent name: 'SpuCommonAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SpuExtAttr ext;	 // size=12, offset=28 //  hashcode: 0xB9C04D49 (dec: -1178579639), parent name: 'SpuCommonAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_83fake // hashcode: 0xA89170BD (dec: -1466863427)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xDA8032CE (dec: -629132594), parent name: 'VOICEXA_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0xFD8597B3 (dec: -41576525), parent name: 'VOICEXA_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_84fake // hashcode: 0xDE3105CC (dec: -567212596)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xECBD57B5 (dec: -323135563), parent name: 'VOICEXA_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x56C39F94 (dec: 1455660948), parent name: 'VOICEXA_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_85fake // hashcode: 0xFF44B794 (dec: -12273772)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xE65D8E10 (dec: -430076400), parent name: 'VOICEXA_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x5CA6DE08 (dec: 1554439688), parent name: 'VOICEXA_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union VOICEXA_86fake // Hashcode: 0x5344B4D5 (dec: 1397011669)
{
	struct VOICEXA_83fake callback; // size=8, offset=0
	struct VOICEXA_84fake vector;   // size=12, offset=0
	struct VOICEXA_85fake quat;		// size=16, offset=0
};

union VOICEXA_87fake // Hashcode: 0xEAE9F72B (dec: -353765589)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union VOICEXA_88fake // Hashcode: 0x77455B10 (dec: 2001034000)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct VOICEXA_89fake // hashcode: 0xF37A2E65 (dec: -210096539)
{
	union VOICEXA_88fake size; // size=4, offset=0 //  hashcode: 0x804CCB14 (dec: -2142450924), parent name: 'VOICEXA_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_90fake // hashcode: 0xF8896BE0 (dec: -125211680)
{
	short x;				// size=0, offset=0 //  hashcode: 0xB0E6ACA8 (dec: -1327059800), parent name: 'VOICEXA_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x48909A06 (dec: 1217436166), parent name: 'VOICEXA_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x050E0732 (dec: 84805426), parent name: 'VOICEXA_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xE2BA6D13 (dec: -491098861), parent name: 'VOICEXA_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x6461E4AF (dec: 1684137135), parent name: 'VOICEXA_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_91fake // hashcode: 0x3DF4772C (dec: 1039431468)
{
	long index; // size=0, offset=0 //  hashcode: 0x06C68337 (dec: 113673015), parent name: 'VOICEXA_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xB8F91557 (dec: -1191635625), parent name: 'VOICEXA_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_92fake // hashcode: 0xAF92778C (dec: -1349355636)
{
	long index; // size=0, offset=0 //  hashcode: 0xCCB7E6FA (dec: -860363014), parent name: 'VOICEXA_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xF96891D3 (dec: -110587437), parent name: 'VOICEXA_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_93fake // hashcode: 0x8F707558 (dec: -1888455336)
{
	long index; // size=0, offset=0 //  hashcode: 0x83C12E8F (dec: -2084491633), parent name: 'VOICEXA_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x1CAB91EB (dec: 481006059), parent name: 'VOICEXA_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_94fake // hashcode: 0x56DA1530 (dec: 1457132848)
{
	long time;  // size=0, offset=0 //  hashcode: 0xBF5AC2DB (dec: -1084570917), parent name: 'VOICEXA_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x98A13176 (dec: -1734266506), parent name: 'VOICEXA_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_95fake // hashcode: 0xBAF30305 (dec: -1158479099)
{
	long action;   // size=0, offset=0 //  hashcode: 0x5679BABA (dec: 1450818234), parent name: 'VOICEXA_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x60E6164C (dec: 1625691724), parent name: 'VOICEXA_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_96fake // hashcode: 0xEF30AF07 (dec: -282022137)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x95C837E8 (dec: -1782040600), parent name: 'VOICEXA_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x7D2ADE8C (dec: 2099961484), parent name: 'VOICEXA_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_97fake // hashcode: 0x60DBEB11 (dec: 1625025297)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x2A7FFAE7 (dec: 713030375), parent name: 'VOICEXA_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x8357332F (dec: -2091437265), parent name: 'VOICEXA_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_98fake // hashcode: 0x25A0C9E9 (dec: 631294441)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x77D2F730 (dec: 2010314544), parent name: 'VOICEXA_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x59DD5AE2 (dec: 1507678946), parent name: 'VOICEXA_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_99fake // hashcode: 0x4D7AC144 (dec: 1299890500)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x95532E24 (dec: -1789710812), parent name: 'VOICEXA_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xD602CF41 (dec: -704458943), parent name: 'VOICEXA_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x00A2ADD5 (dec: 10661333), parent name: 'VOICEXA_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x7A3C4038 (dec: 2050768952), parent name: 'VOICEXA_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x8713F495 (dec: -2028735339), parent name: 'VOICEXA_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_100fake // hashcode: 0x36BF2374 (dec: 918496116)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xD5B29BD4 (dec: -709714988), parent name: 'VOICEXA_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xA2898D2F (dec: -1568043729), parent name: 'VOICEXA_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_101fake // hashcode: 0x7D52E8B7 (dec: 2102585527)
{
	short index;					// size=0, offset=0 //  hashcode: 0xE939C442 (dec: -382090174), parent name: 'VOICEXA_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x4EFA38BB (dec: 1325021371), parent name: 'VOICEXA_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xFED54FF6 (dec: -19574794), parent name: 'VOICEXA_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xF0B405A8 (dec: -256637528), parent name: 'VOICEXA_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_102fake // hashcode: 0x27CD59B0 (dec: 667769264)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x592BBA4B (dec: 1496037963), parent name: 'VOICEXA_102fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x4738C674 (dec: 1194903156), parent name: 'VOICEXA_102fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xA1263212 (dec: -1591332334), parent name: 'VOICEXA_102fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_103fake // hashcode: 0x07D63D0E (dec: 131480846)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x56AC7A84 (dec: 1454144132), parent name: 'VOICEXA_103fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xD84A14A7 (dec: -666233689), parent name: 'VOICEXA_103fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x2754609C (dec: 659841180), parent name: 'VOICEXA_103fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x037BD73D (dec: 58447677), parent name: 'VOICEXA_103fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xCB7ADB3B (dec: -881140933), parent name: 'VOICEXA_103fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x5FEEDF22 (dec: 1609490210), parent name: 'VOICEXA_103fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xB1B8476D (dec: -1313323155), parent name: 'VOICEXA_103fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_104fake // hashcode: 0xA4880878 (dec: -1534588808)
{
	long index;  // size=0, offset=0 //  hashcode: 0x7D524293 (dec: 2102542995), parent name: 'VOICEXA_104fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x10D76302 (dec: 282551042), parent name: 'VOICEXA_104fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_105fake // hashcode: 0x3005A1C9 (dec: 805675465)
{
	short type; // size=0, offset=0 //  hashcode: 0xA371C5CB (dec: -1552824885), parent name: 'VOICEXA_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xCEE11FA7 (dec: -824107097), parent name: 'VOICEXA_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_106fake // hashcode: 0x0D306AB9 (dec: 221276857)
{
	long time;   // size=0, offset=0 //  hashcode: 0x7ACFA864 (dec: 2060429412), parent name: 'VOICEXA_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x95258CA6 (dec: -1792701274), parent name: 'VOICEXA_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_107fake // hashcode: 0x137BD66F (dec: 326882927)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x0C11793A (dec: 202471738), parent name: 'VOICEXA_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x2E3F0487 (dec: 775881863), parent name: 'VOICEXA_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_108fake // hashcode: 0x24E3C686 (dec: 618907270)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xEE9B4E72 (dec: -291811726), parent name: 'VOICEXA_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xA7009525 (dec: -1493134043), parent name: 'VOICEXA_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_109fake // hashcode: 0xE22E3A90 (dec: -500286832)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xB18148A6 (dec: -1316927322), parent name: 'VOICEXA_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xFAE0B96E (dec: -85935762), parent name: 'VOICEXA_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_110fake // hashcode: 0x34FE5932 (dec: 889084210)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x1CB4C764 (dec: 481609572), parent name: 'VOICEXA_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x6B724BCC (dec: 1802652620), parent name: 'VOICEXA_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x6F75F117 (dec: 1870000407), parent name: 'VOICEXA_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x6F0A72DF (dec: 1862955743), parent name: 'VOICEXA_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_111fake // hashcode: 0x31D2C46F (dec: 835896431)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x81F77F0F (dec: -2114486513), parent name: 'VOICEXA_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xD6BEC5EA (dec: -692140566), parent name: 'VOICEXA_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x051B203C (dec: 85663804), parent name: 'VOICEXA_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xBDBB32C2 (dec: -1111805246), parent name: 'VOICEXA_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xC52E818F (dec: -986807921), parent name: 'VOICEXA_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union VOICEXA_112fake // Hashcode: 0x70466784 (dec: 1883662212)
{
	struct VOICEXA_89fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;		 // size=24, offset=0
	struct VOICEXA_90fake teleport;		 // size=16, offset=0
	struct VOICEXA_91fake cameraValue;   // size=8, offset=0
	struct VOICEXA_92fake miscValue;	 // size=8, offset=0
	struct VOICEXA_93fake logicValue;	// size=8, offset=0
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
	struct VOICEXA_94fake cameraShake;   // size=8, offset=0
	long cameraSave;					 // size=0, offset=0
	long cameraRestore;					 // size=0, offset=0
	struct _BGObject *bgObject;			 // size=24, offset=0
	long value[2];						 // size=8, offset=0
	struct VOICEXA_95fake sound;		 // size=12, offset=0
	void *intro;						 // size=0, offset=0
	long deathZ;						 // size=0, offset=0
	struct VOICEXA_96fake dsignal;		 // size=8, offset=0
	void *mirror;						 // size=0, offset=0
	long fogNear;						 // size=0, offset=0
	long fogFar;						 // size=0, offset=0
	struct VOICEXA_97fake gotoFrame;	 // size=8, offset=0
	struct VOICEXA_98fake changeModel;   // size=8, offset=0
	void *vmObject;						 // size=0, offset=0
	struct VOICEXA_99fake logic;		 // size=8, offset=0
	void *callSignal;					 // size=0, offset=0
	struct _SVector offset;				 // size=8, offset=0
	struct Signal *gotoLabel;			 // size=0, offset=0
	struct Signal *gosubLabel;			 // size=0, offset=0
	struct VOICEXA_100fake control;		 // size=8, offset=0
	struct VOICEXA_101fake zSignal;		 // size=12, offset=0
	struct VOICEXA_102fake StreamLevel;  // size=24, offset=0
	struct VOICEXA_103fake shards;		 // size=12, offset=0
	struct VOICEXA_104fake cameraSpline; // size=8, offset=0
	struct VOICEXA_105fake screenWipe;   // size=4, offset=0
	long voiceSitId;					 // size=0, offset=0
	struct VOICEXA_106fake introFX;		 // size=8, offset=0
	struct VOICEXA_107fake introActive;  // size=8, offset=0
	struct VOICEXA_108fake levelChange;  // size=18, offset=0
	long blendStart;					 // size=0, offset=0
	struct VOICEXA_109fake setTimes;	 // size=8, offset=0
	struct VOICEXA_110fake color;		 // size=4, offset=0
	struct VOICEXA_111fake print;		 // size=12, offset=0
	long slideAngle;					 // size=0, offset=0
};

union VOICEXA_113fake // Hashcode: 0x49E9D972 (dec: 1240062322)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union VOICEXA_118fake // Hashcode: 0xDE2D0E18 (dec: -567472616)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct VOICEXA_171fake // hashcode: 0x6DFF8A5A (dec: 1845463642)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x4AEDA376 (dec: 1257087862), parent name: 'VOICEXA_171fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x19510101 (dec: 424739073), parent name: 'VOICEXA_171fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x2D0540A6 (dec: 755318950), parent name: 'VOICEXA_171fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xD470B1BD (dec: -730811971), parent name: 'VOICEXA_171fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0xA80D13FD (dec: -1475537923), parent name: 'VOICEXA_171fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x11DD6215 (dec: 299721237), parent name: 'VOICEXA_171fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x9C145595 (dec: -1676388971), parent name: 'VOICEXA_171fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_172fake // hashcode: 0xBE66D879 (dec: -1100556167)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x110AAE2D (dec: 285912621), parent name: 'VOICEXA_172fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x601BFBDB (dec: 1612446683), parent name: 'VOICEXA_172fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xB7498399 (dec: -1219918951), parent name: 'VOICEXA_172fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_173fake // hashcode: 0xFBF1AE53 (dec: -68047277)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xBDCC049B (dec: -1110702949), parent name: 'VOICEXA_173fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x4543EA39 (dec: 1162078777), parent name: 'VOICEXA_173fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xF56E3A17 (dec: -177325545), parent name: 'VOICEXA_173fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x4B3C12E6 (dec: 1262228198), parent name: 'VOICEXA_173fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xFA4AC0DE (dec: -95764258), parent name: 'VOICEXA_173fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_174fake // hashcode: 0xCC5C27C1 (dec: -866375743)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xBCB8D0CC (dec: -1128738612), parent name: 'VOICEXA_174fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x1B66BB52 (dec: 459717458), parent name: 'VOICEXA_174fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0xBF9AB615 (dec: -1080379883), parent name: 'VOICEXA_174fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xFF614B36 (dec: -10400970), parent name: 'VOICEXA_174fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xD587D089 (dec: -712519543), parent name: 'VOICEXA_174fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VOICEXA_175fake // hashcode: 0xD4103ED4 (dec: -737132844)
{
	struct VOICEXA_171fake Cinematic; // size=28, offset=0 //  hashcode: 0xEF5EE75E (dec: -278993058), parent name: 'VOICEXA_175fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct VOICEXA_172fake Idle;	  // size=20, offset=28 //  hashcode: 0x87B4CBCD (dec: -2018194483), parent name: 'VOICEXA_175fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct VOICEXA_173fake Behind;	// size=28, offset=48 //  hashcode: 0x6E7921FC (dec: 1853432316), parent name: 'VOICEXA_175fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct VOICEXA_174fake Follow;	// size=20, offset=76 //  hashcode: 0x864BE183 (dec: -2041847421), parent name: 'VOICEXA_175fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct XAVoiceListEntry // hashcode: 0xDBE9AB23 (dec: -605443293)
{
	unsigned short length; // size=0, offset=0 //  hashcode: 0xD068A02F (dec: -798449617), parent name: 'XAVoiceListEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct XAVoiceTracker // hashcode: 0x77052065 (dec: 1996824677)
{
	struct CdlLOC currentPos;			   // size=4, offset=0 //  hashcode: 0xB5DC4D4A (dec: -1243853494), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	int currentSector;					   // size=0, offset=4 //  hashcode: 0x7A1DE940 (dec: 2048780608), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	int endSector;						   // size=0, offset=8 //  hashcode: 0x69F75941 (dec: 1777817921), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*prevCallback)();				   // size=0, offset=12 //  hashcode: 0x2217280A (dec: 571942922), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char cdResult[8];			   // size=8, offset=16 //  hashcode: 0xA13E6722 (dec: -1589745886), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CdCommand cdCmdQueue[8];		   // size=64, offset=24 //  hashcode: 0xB11F13E4 (dec: -1323363356), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short requestQueue[4];		   // size=8, offset=88 //  hashcode: 0xB74255C1 (dec: -1220389439), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct VoiceCommand voiceCmdQueue[16]; // size=64, offset=96 //  hashcode: 0x1E2A3532 (dec: 506082610), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char cdCmdIn;				   // size=0, offset=160 //  hashcode: 0x75D62A33 (dec: 1976969779), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char cdCmdOut;				   // size=0, offset=161 //  hashcode: 0x5BAFE9FC (dec: 1538255356), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char cdCmdsQueued;			   // size=0, offset=162 //  hashcode: 0xDCDB0748 (dec: -589625528), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char reqIn;				   // size=0, offset=163 //  hashcode: 0x3D1CBF31 (dec: 1025294129), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char reqOut;				   // size=0, offset=164 //  hashcode: 0x29C02728 (dec: 700458792), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char reqsQueued;			   // size=0, offset=165 //  hashcode: 0xA265D251 (dec: -1570385327), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char voiceCmdIn;			   // size=0, offset=166 //  hashcode: 0x09B39E10 (dec: 162766352), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char voiceCmdOut;			   // size=0, offset=167 //  hashcode: 0x08BF7895 (dec: 146765973), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char voiceCmdsQueued;		   // size=0, offset=168 //  hashcode: 0x7D4DD03B (dec: 2102251579), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char unused1;				   // size=0, offset=169 //  hashcode: 0xA8213710 (dec: -1474218224), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char voiceStatus;			   // size=0, offset=170 //  hashcode: 0x5223DF5A (dec: 1378082650), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char cdStatus;				   // size=0, offset=171 //  hashcode: 0x527CDD0C (dec: 1383914764), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fileNum;						   // size=0, offset=172 //  hashcode: 0x53A10E08 (dec: 1403063816), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short unused2;						   // size=0, offset=174 //  hashcode: 0x33501085 (dec: 860885125), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct XAFileInfo xaFileInfo[30];	  // size=120, offset=176 //  hashcode: 0xA0259A53 (dec: -1608148397), parent name: 'XAVoiceTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct CdlFILTER CdlFILTER;

typedef struct SpuCommonAttr SpuCommonAttr;

typedef struct XAVoiceListEntry XAVoiceListEntry;

typedef struct XAVoiceTracker XAVoiceTracker;

typedef void (*VoiceCmdProc)();

extern void VOICEXA_Init(); // 0x800B6E14

extern void putCdCommand(struct XAVoiceTracker *vt, unsigned char cdCommand, int numParams, unsigned char *params); // 0x800B6EE0

extern void VOICEXA_CdSyncCallback(unsigned char status, unsigned char *result); // 0x800B6F64

extern void processCdCommands(struct XAVoiceTracker *vt); // 0x800B6FD0

extern void putVoiceCommand(struct XAVoiceTracker *vt, unsigned char voiceCmd, unsigned char nextVoiceStatus, int voiceCmdParam); // 0x800B7078

extern void processVoiceCommands(struct XAVoiceTracker *vt); // 0x800B70F4

extern void voiceCmdPlay(struct XAVoiceTracker *vt, short voiceIndex); // 0x800B71A4

extern void voiceCmdStop(struct XAVoiceTracker *vt, short cmdParam); // 0x800B7314

extern void voiceCmdPause(struct XAVoiceTracker *vt, short cmdParam); // 0x800B7370

extern void voiceCmdResume(struct XAVoiceTracker *vt, short cmdParam); // 0x800B73AC

extern void voiceCmdNull(struct XAVoiceTracker *vt, short cmdParam); // 0x800B73E0

extern void VOICEXA_Play(int voiceIndex, int queueRequests); // 0x800B73E8

extern int VOICEXA_FinalStatus(struct XAVoiceTracker *vt); // 0x800B74AC

extern void VOICEXA_Pause(); // 0x800B74F0

extern void VOICEXA_Resume(); // 0x800B7560

extern void VOICEXA_Tick(); // 0x800B75D0

extern int VOICEXA_IsPlaying(); // 0x800B7728

extern int VOICEXA_IsPlayingOrPaused(); // 0x800B7768

#endif
