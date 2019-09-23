#ifndef MONSTER_H
#define MONSTER_H

static struct burntTuneType burntTest; // offset 0x800CF674

struct MONSTER_73fake // hashcode: 0x481A7F52 (dec: 1209696082)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x5A68895B (dec: 1516800347), parent name: 'MONSTER_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0xE5ACDBAD (dec: -441656403), parent name: 'MONSTER_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_74fake // hashcode: 0x8B234073 (dec: -1960624013)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xDE1BE219 (dec: -568597991), parent name: 'MONSTER_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xCCEF7FE1 (dec: -856719391), parent name: 'MONSTER_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_75fake // hashcode: 0x68C6025B (dec: 1757807195)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xB86E927E (dec: -1200713090), parent name: 'MONSTER_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x0CF80C17 (dec: 217582615), parent name: 'MONSTER_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONSTER_76fake // Hashcode: 0x93E73915 (dec: -1813563115)
{
	struct MONSTER_73fake callback; // size=8, offset=0
	struct MONSTER_74fake vector;   // size=12, offset=0
	struct MONSTER_75fake quat;		// size=16, offset=0
};

union MONSTER_77fake // Hashcode: 0x2E7BD072 (dec: 779866226)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MONSTER_78fake // Hashcode: 0xD384184C (dec: -746317748)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct MONSTER_79fake // hashcode: 0xE25423C7 (dec: -497802297)
{
	union MONSTER_78fake size; // size=4, offset=0 //  hashcode: 0x73D1FFDC (dec: 1943142364), parent name: 'MONSTER_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_80fake // hashcode: 0x00BED96E (dec: 12507502)
{
	short x;				// size=0, offset=0 //  hashcode: 0xF87A2819 (dec: -126212071), parent name: 'MONSTER_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x8A870AF2 (dec: -1970861326), parent name: 'MONSTER_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x31678DE6 (dec: 828870118), parent name: 'MONSTER_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xA969C31E (dec: -1452686562), parent name: 'MONSTER_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x6E0352E4 (dec: 1845711588), parent name: 'MONSTER_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_81fake // hashcode: 0xF9AC5356 (dec: -106146986)
{
	long index; // size=0, offset=0 //  hashcode: 0xB9C1A42E (dec: -1178491858), parent name: 'MONSTER_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x390B7D2B (dec: 957054251), parent name: 'MONSTER_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_82fake // hashcode: 0xD27FB711 (dec: -763381999)
{
	long index; // size=0, offset=0 //  hashcode: 0x4842C74D (dec: 1212335949), parent name: 'MONSTER_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x909A9DA4 (dec: -1868915292), parent name: 'MONSTER_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_83fake // hashcode: 0x9D5AB2AC (dec: -1655000404)
{
	long index; // size=0, offset=0 //  hashcode: 0xFBD27097 (dec: -70094697), parent name: 'MONSTER_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x8E855B77 (dec: -1903862921), parent name: 'MONSTER_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_84fake // hashcode: 0x47E5933C (dec: 1206227772)
{
	long time;  // size=0, offset=0 //  hashcode: 0xDB41F5DC (dec: -616434212), parent name: 'MONSTER_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x7E8CB037 (dec: 2123149367), parent name: 'MONSTER_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_85fake // hashcode: 0x834BF6B1 (dec: -2092173647)
{
	long action;   // size=0, offset=0 //  hashcode: 0x234D852E (dec: 592282926), parent name: 'MONSTER_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x20D59E8F (dec: 550870671), parent name: 'MONSTER_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_86fake // hashcode: 0x341EF7E9 (dec: 874444777)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xFE6A40E0 (dec: -26591008), parent name: 'MONSTER_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x2CBCE5DD (dec: 750577117), parent name: 'MONSTER_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_87fake // hashcode: 0x3ED9F5E9 (dec: 1054471657)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x0FAE7C4E (dec: 263093326), parent name: 'MONSTER_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x64F1C85D (dec: 1693567069), parent name: 'MONSTER_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_88fake // hashcode: 0x3288E6F3 (dec: 847832819)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x48256AC8 (dec: 1210411720), parent name: 'MONSTER_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xD01A8161 (dec: -803569311), parent name: 'MONSTER_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_89fake // hashcode: 0xD5E766D1 (dec: -706255151)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xA9FA7CA5 (dec: -1443201883), parent name: 'MONSTER_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xE4CA8CC5 (dec: -456487739), parent name: 'MONSTER_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x83BA4E06 (dec: -2084942330), parent name: 'MONSTER_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x74795FE1 (dec: 1954111457), parent name: 'MONSTER_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x4B320BCA (dec: 1261571018), parent name: 'MONSTER_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_90fake // hashcode: 0x6FA4BC58 (dec: 1873067096)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x1C63F63A (dec: 476313146), parent name: 'MONSTER_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x36809863 (dec: 914397283), parent name: 'MONSTER_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_91fake // hashcode: 0xC799EE59 (dec: -946213287)
{
	short index;					// size=0, offset=0 //  hashcode: 0xB66C4D81 (dec: -1234416255), parent name: 'MONSTER_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x8554D649 (dec: -2058037687), parent name: 'MONSTER_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xDC7392B3 (dec: -596405581), parent name: 'MONSTER_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xE42A02A2 (dec: -467008862), parent name: 'MONSTER_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_92fake // hashcode: 0xAF99AED5 (dec: -1348882731)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x42E9B274 (dec: 1122611828), parent name: 'MONSTER_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x19580DA8 (dec: 425201064), parent name: 'MONSTER_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xEE8C0986 (dec: -292812410), parent name: 'MONSTER_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_93fake // hashcode: 0x3D8C6531 (dec: 1032611121)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x9596635F (dec: -1785306273), parent name: 'MONSTER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x6CDD9ABE (dec: 1826462398), parent name: 'MONSTER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xB7FC9F17 (dec: -1208180969), parent name: 'MONSTER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xBC374785 (dec: -1137227899), parent name: 'MONSTER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x962D031A (dec: -1775434982), parent name: 'MONSTER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x5D54EEDB (dec: 1565847259), parent name: 'MONSTER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x75335BA5 (dec: 1966300069), parent name: 'MONSTER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_94fake // hashcode: 0x8E6ADDFA (dec: -1905598982)
{
	long index;  // size=0, offset=0 //  hashcode: 0x0ED50C8F (dec: 248843407), parent name: 'MONSTER_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x4E1739DB (dec: 1310144987), parent name: 'MONSTER_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_95fake // hashcode: 0xB64001B2 (dec: -1237319246)
{
	short type; // size=0, offset=0 //  hashcode: 0x0D34CE50 (dec: 221564496), parent name: 'MONSTER_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x11C5888F (dec: 298158223), parent name: 'MONSTER_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_96fake // hashcode: 0x82ADD9DC (dec: -2102535716)
{
	long time;   // size=0, offset=0 //  hashcode: 0xC4F7C05D (dec: -990396323), parent name: 'MONSTER_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x47B7A502 (dec: 1203217666), parent name: 'MONSTER_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_97fake // hashcode: 0xC28D6B17 (dec: -1030919401)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x89090EAD (dec: -1995895123), parent name: 'MONSTER_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xD2466924 (dec: -767137500), parent name: 'MONSTER_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_98fake // hashcode: 0xD8797163 (dec: -663129757)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x1F18DD4C (dec: 521723212), parent name: 'MONSTER_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xB605A355 (dec: -1241144491), parent name: 'MONSTER_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_99fake // hashcode: 0xB9A5B635 (dec: -1180322251)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xBEFAA9A3 (dec: -1090868829), parent name: 'MONSTER_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x79739F89 (dec: 2037620617), parent name: 'MONSTER_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_100fake // hashcode: 0x8601CE40 (dec: -2046702016)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0xB878C2B8 (dec: -1200045384), parent name: 'MONSTER_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x165A5FFD (dec: 375021565), parent name: 'MONSTER_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x3730CE00 (dec: 925945344), parent name: 'MONSTER_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xB797D02A (dec: -1214787542), parent name: 'MONSTER_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_101fake // hashcode: 0xB5F59704 (dec: -1242196220)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xF41AB1CD (dec: -199577139), parent name: 'MONSTER_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x22BC2C86 (dec: 582757510), parent name: 'MONSTER_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xBECD2D4D (dec: -1093849779), parent name: 'MONSTER_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xA7C66DF0 (dec: -1480167952), parent name: 'MONSTER_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x1CCE4120 (dec: 483279136), parent name: 'MONSTER_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONSTER_102fake // Hashcode: 0x0A4A4A31 (dec: 172640817)
{
	struct MONSTER_79fake misc[3];		// size=12, offset=0
	struct _CameraKey *cameraKey;		// size=24, offset=0
	struct MONSTER_80fake teleport;		// size=16, offset=0
	struct MONSTER_81fake cameraValue;  // size=8, offset=0
	struct MONSTER_82fake miscValue;	// size=8, offset=0
	struct MONSTER_83fake logicValue;   // size=8, offset=0
	long timer;							// size=0, offset=0
	long times;							// size=0, offset=0
	long lightGroup;					// size=0, offset=0
	long farPlane;						// size=0, offset=0
	long cameraAdjust;					// size=0, offset=0
	long cameraMode;					// size=0, offset=0
	long cameraLock;					// size=0, offset=0
	long cameraUnlock;					// size=0, offset=0
	long cameraSmooth;					// size=0, offset=0
	long cameraTimer;					// size=0, offset=0
	struct MONSTER_84fake cameraShake;  // size=8, offset=0
	long cameraSave;					// size=0, offset=0
	long cameraRestore;					// size=0, offset=0
	struct _BGObject *bgObject;			// size=24, offset=0
	long value[2];						// size=8, offset=0
	struct MONSTER_85fake sound;		// size=12, offset=0
	void *intro;						// size=0, offset=0
	long deathZ;						// size=0, offset=0
	struct MONSTER_86fake dsignal;		// size=8, offset=0
	void *mirror;						// size=0, offset=0
	long fogNear;						// size=0, offset=0
	long fogFar;						// size=0, offset=0
	struct MONSTER_87fake gotoFrame;	// size=8, offset=0
	struct MONSTER_88fake changeModel;  // size=8, offset=0
	void *vmObject;						// size=0, offset=0
	struct MONSTER_89fake logic;		// size=8, offset=0
	void *callSignal;					// size=0, offset=0
	struct _SVector offset;				// size=8, offset=0
	struct Signal *gotoLabel;			// size=0, offset=0
	struct Signal *gosubLabel;			// size=0, offset=0
	struct MONSTER_90fake control;		// size=8, offset=0
	struct MONSTER_91fake zSignal;		// size=12, offset=0
	struct MONSTER_92fake StreamLevel;  // size=24, offset=0
	struct MONSTER_93fake shards;		// size=12, offset=0
	struct MONSTER_94fake cameraSpline; // size=8, offset=0
	struct MONSTER_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;					// size=0, offset=0
	struct MONSTER_96fake introFX;		// size=8, offset=0
	struct MONSTER_97fake introActive;  // size=8, offset=0
	struct MONSTER_98fake levelChange;  // size=18, offset=0
	long blendStart;					// size=0, offset=0
	struct MONSTER_99fake setTimes;		// size=8, offset=0
	struct MONSTER_100fake color;		// size=4, offset=0
	struct MONSTER_101fake print;		// size=12, offset=0
	long slideAngle;					// size=0, offset=0
};

union MONSTER_103fake // Hashcode: 0x6000BFE3 (dec: 1610661859)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union MONSTER_108fake // Hashcode: 0xC1191BCB (dec: -1055319093)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct MONSTER_110fake // hashcode: 0xC2D17641 (dec: -1026460095)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x30EAC5F0 (dec: 820692464), parent name: 'MONSTER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x94F6A04C (dec: -1795776436), parent name: 'MONSTER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x8E55E4AA (dec: -1906973526), parent name: 'MONSTER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x6547B329 (dec: 1699197737), parent name: 'MONSTER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0xF54CA668 (dec: -179526040), parent name: 'MONSTER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xF14F0356 (dec: -246480042), parent name: 'MONSTER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x018A53F4 (dec: 25842676), parent name: 'MONSTER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_111fake // hashcode: 0x16470EFE (dec: 373755646)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0xDA4B4289 (dec: -632601975), parent name: 'MONSTER_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x381D63A4 (dec: 941450148), parent name: 'MONSTER_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x3D88C32A (dec: 1032373034), parent name: 'MONSTER_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_112fake // hashcode: 0xB633A828 (dec: -1238128600)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xB1AA6F5B (dec: -1314230437), parent name: 'MONSTER_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x59ADF0D5 (dec: 1504571605), parent name: 'MONSTER_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x927E2190 (dec: -1837227632), parent name: 'MONSTER_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x94EA0827 (dec: -1796601817), parent name: 'MONSTER_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xBA85265A (dec: -1165679014), parent name: 'MONSTER_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_113fake // hashcode: 0x71A7516D (dec: 1906790765)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xAE5EF1B7 (dec: -1369509449), parent name: 'MONSTER_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x95946652 (dec: -1785436590), parent name: 'MONSTER_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x9EBFD2C0 (dec: -1631595840), parent name: 'MONSTER_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x03A7223B (dec: 61284923), parent name: 'MONSTER_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x0DE3638F (dec: 233005967), parent name: 'MONSTER_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_114fake // hashcode: 0xAC393E28 (dec: -1405534680)
{
	struct MONSTER_110fake Cinematic; // size=28, offset=0 //  hashcode: 0xD803AF59 (dec: -670847143), parent name: 'MONSTER_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MONSTER_111fake Idle;	  // size=20, offset=28 //  hashcode: 0x4BF57153 (dec: 1274376531), parent name: 'MONSTER_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MONSTER_112fake Behind;	// size=28, offset=48 //  hashcode: 0x44D1E2A2 (dec: 1154605730), parent name: 'MONSTER_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MONSTER_113fake Follow;	// size=20, offset=76 //  hashcode: 0x5177643A (dec: 1366778938), parent name: 'MONSTER_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_184fake // hashcode: 0xA160060F (dec: -1587542513)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x40546B47 (dec: 1079274311), parent name: 'MONSTER_184fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0xE6BA63D8 (dec: -423992360), parent name: 'MONSTER_184fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONSTER_185fake // hashcode: 0x1313C257 (dec: 320062039)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x6D4ED8F7 (dec: 1833883895), parent name: 'MONSTER_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x616983CF (dec: 1634304975), parent name: 'MONSTER_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x2E929A98 (dec: 781359768), parent name: 'MONSTER_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x98A1C231 (dec: -1734229455), parent name: 'MONSTER_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x77A6A2F5 (dec: 2007409397), parent name: 'MONSTER_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x3950D576 (dec: 961598838), parent name: 'MONSTER_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONSTER_186fake // Hashcode: 0xC0C8FF86 (dec: -1060569210)
{
	struct MONSTER_184fake flame; // size=8, offset=0
	struct MONSTER_185fake phys;  // size=12, offset=0
};

union MONSTER_212fake // Hashcode: 0xDED63187 (dec: -556387961)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct burntMessType // hashcode: 0x8C763516 (dec: -1938410218)
{
	int closestvert;				 // size=0, offset=0 //  hashcode: 0x7811BB1D (dec: 2014427933), parent name: 'burntMessType', parent hashcode: 0xFFFFFFFF (dec: -1)
	int closestdist;				 // size=0, offset=4 //  hashcode: 0x9F84C6CF (dec: -1618688305), parent name: 'burntMessType', parent hashcode: 0xFFFFFFFF (dec: -1)
	int closestseg;					 // size=0, offset=8 //  hashcode: 0x364BCB43 (dec: 910936899), parent name: 'burntMessType', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct burntTuneType *burntTune; // size=8, offset=12 //  hashcode: 0xAE953EAA (dec: -1365950806), parent name: 'burntMessType', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct bloodyMessType // hashcode: 0x5F4737FF (dec: 1598502911)
{
	int closestvert;	// size=0, offset=0 //  hashcode: 0x6926A003 (dec: 1764139011), parent name: 'bloodyMessType', parent hashcode: 0xFFFFFFFF (dec: -1)
	int closestdist;	// size=0, offset=4 //  hashcode: 0x527A90EC (dec: 1383764204), parent name: 'bloodyMessType', parent hashcode: 0xFFFFFFFF (dec: -1)
	int closestseg;		// size=0, offset=8 //  hashcode: 0xC18D7EEF (dec: -1047691537), parent name: 'bloodyMessType', parent hashcode: 0xFFFFFFFF (dec: -1)
	int bloodiedAVert;  // size=0, offset=12 //  hashcode: 0x1B83481D (dec: 461588509), parent name: 'bloodyMessType', parent hashcode: 0xFFFFFFFF (dec: -1)
	int bloodIntensity; // size=0, offset=16 //  hashcode: 0x2B4B249C (dec: 726344860), parent name: 'bloodyMessType', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct burntMessType burntMessType;

typedef struct bloodyMessType bloodyMessType;

extern void MON_DoCombatTimers(struct _Instance *instance); // 0x800871FC

extern void MON_ChangeHumanOpinion(struct _Instance *instance); // 0x800873E4

extern void MON_CutOut_Monster(struct _Instance *instance, int fade_amount, int startseg, int endseg); // 0x8008748C

extern void MON_DeadEntry(struct _Instance *instance); // 0x800876E0

extern void MON_Dead(struct _Instance *instance); // 0x800877D0

extern void MON_MissileHitEntry(struct _Instance *instance); // 0x80087F04

extern void MON_MissileHit(struct _Instance *instance); // 0x80087FD0

extern void MON_BirthEntry(struct _Instance *instance); // 0x800880B0

extern void MON_Birth(struct _Instance *instance); // 0x800880B8

extern void MON_ParryEntry(struct _Instance *instance); // 0x800880D8

extern void MON_Parry(struct _Instance *instance); // 0x80088128

extern void MON_LandOnFeetEntry(struct _Instance *instance); // 0x8008816C

extern void MON_LandOnFeet(struct _Instance *instance); // 0x80088230

extern void MON_LandInWaterEntry(struct _Instance *instance); // 0x800883BC

extern void MON_LandInWater(struct _Instance *instance); // 0x800883D0

extern void MON_BreakHoldEntry(struct _Instance *instance); // 0x800883F0

extern void MON_BreakHold(struct _Instance *instance); // 0x8008845C

extern void MON_ImpactEntry(struct _Instance *instance); // 0x80088638

extern void MON_Impact(struct _Instance *instance); // 0x8008871C

extern void MON_FallEntry(struct _Instance *instance); // 0x8008879C

extern void MON_Fall(struct _Instance *instance); // 0x8008885C

extern void MON_ThrownEntry(struct _Instance *instance); // 0x800889D8

extern void MON_Thrown(struct _Instance *instance); // 0x80088A74

extern void MON_ImpaleDeathEntry(struct _Instance *instance); // 0x80088BCC

extern void MON_ImpaleDeath(struct _Instance *instance); // 0x80088C4C

extern void MON_TerrainImpaleDeathEntry(struct _Instance *instance); // 0x80088E54

extern void MON_TerrainImpaleDeath(struct _Instance *instance); // 0x80088FA8

extern void MON_SurprisedEntry(struct _Instance *instance); // 0x80089190

extern void MON_Surprised(struct _Instance *instance); // 0x800891F0

extern void MON_StunnedEntry(struct _Instance *instance); // 0x800892B4

extern void MON_Stunned(struct _Instance *instance); // 0x80089464

extern void MON_GrabbedEntry(struct _Instance *instance); // 0x80089574

extern void MON_Grabbed(struct _Instance *instance); // 0x80089658

extern void MON_HitEntry(struct _Instance *instance); // 0x80089870

extern void MON_Hit(struct _Instance *instance); // 0x80089914

extern void MON_AttackEntry(struct _Instance *instance); // 0x800899FC

extern void MON_Attack(struct _Instance *instance); // 0x80089A70

extern void MON_CombatEntry(struct _Instance *instance); // 0x80089C50

extern void MON_Combat(struct _Instance *instance); // 0x80089C7C

extern void MON_ProjectileEntry(struct _Instance *instance); // 0x80089F64

extern void MON_Projectile(struct _Instance *instance); // 0x80089FBC

extern void MON_IdleEntry(struct _Instance *instance); // 0x8008A100

extern void MON_Idle(struct _Instance *instance); // 0x8008A1B8

extern void MON_FleeEntry(struct _Instance *instance); // 0x8008A3F4

extern void MON_Flee(struct _Instance *instance); // 0x8008A448

extern void MON_PursueEntry(struct _Instance *instance); // 0x8008A58C

extern void MON_Pursue(struct _Instance *instance); // 0x8008A61C

extern void MON_WanderEntry(struct _Instance *instance); // 0x8008AA54

extern void MON_Wander(struct _Instance *instance); // 0x8008AAFC

extern void MON_HideEntry(struct _Instance *instance); // 0x8008AD74

extern void MON_Hide(struct _Instance *instance); // 0x8008AD94

extern void MON_SurpriseAttackEntry(struct _Instance *instance); // 0x8008AF10

extern void MON_SurpriseAttack(struct _Instance *instance); // 0x8008AFA4

extern void MON_EnvironmentDamageEntry(struct _Instance *instance); // 0x8008AFC4

extern void MON_EnvironmentDamage(struct _Instance *instance); // 0x8008AFCC

extern void MON_MonsterGlow(struct _Instance *instance, long color, int glowtime, int glowin, int glowfade); // 0x8008AFD4

extern void MON_GeneralDeathEntry(struct _Instance *instance); // 0x8008B160

extern void MON_GeneralDeath(struct _Instance *instance); // 0x8008B3AC

extern void MON_NoticeEntry(struct _Instance *instance); // 0x8008B524

extern void MON_Notice(struct _Instance *instance); // 0x8008B5DC

extern void MON_PupateEntry(struct _Instance *instance); // 0x8008B67C

extern void MON_Pupate(struct _Instance *instance); // 0x8008B6DC

extern void MON_EmbraceEntry(struct _Instance *instance); // 0x8008BA1C

extern void MON_Embrace(struct _Instance *instance); // 0x8008BA7C

extern void MON_PetrifiedEntry(struct _Instance *instance); // 0x8008BBFC

extern void MON_Petrified(struct _Instance *instance); // 0x8008BC38

extern int MONSTER_CalcDamageIntensity(int hp, int maxHp); // 0x8008BD44

extern void MONSTER_ProcessClosestVerts(struct _Instance *instance, struct _SVector *location, TDRFuncPtr_MONSTER_ProcessClosestVerts2processVert_cb processVert_cb, void *cb_data); // 0x8008BD5C

extern void ProcessBloodyMess(struct _Instance *instance, int vertidx, int segidx, int dist, void *cb_data); // 0x8008BF24

extern void MONSTER_InitVertexColors(struct _Instance *instance, struct _Model *model); // 0x8008C030

extern int MONSTER_StartVertexBlood(struct _Instance *instance, struct _SVector *location, int amount); // 0x8008C098

extern void MONSTER_VertexBlood(struct _Instance *instance, int vert, int amount); // 0x8008C220

extern void ProcessBurntMess(struct _Instance *instance, int vertidx, int segidx, int dist, void *cb_data); // 0x8008C3EC

extern int MONSTER_StartVertexBurnt(struct _Instance *instance, struct _SVector *location, struct burntTuneType *burntTune); // 0x8008C498

extern void MONSTER_VertexBurnt(struct _Instance *instance, struct burntTuneType *burntTune); // 0x8008C618

extern void MON_DamageEffect(struct _Instance *instance, struct evFXHitData *data); // 0x8008C6C4

extern void MON_DefaultInit(struct _Instance *instance); // 0x8008CB28

extern void MON_CleanUp(struct _Instance *instance); // 0x8008CD74

typedef void (*TDRFuncPtr_MONSTER_ProcessClosestVerts2processVert_cb)();

#endif
