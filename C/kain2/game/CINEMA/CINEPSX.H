#ifndef CINEPSX_H
#define CINEPSX_H

static struct cinema_fn_table_t *the_cine_table; // offset 0x800CAD90

static struct _ObjectTracker *the_cine_tracker; // offset 0x800CAD94

struct cinema_fn_table_t // hashcode: 0xBFD79C7E (dec: -1076388738)
{
	int (*play)();   // size=0, offset=0 //  hashcode: 0xC8491398 (dec: -934734952), parent name: 'cinema_fn_table_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *versionID; // size=0, offset=4 //  hashcode: 0x8EB31BA7 (dec: -1900864601), parent name: 'cinema_fn_table_t', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_68fake // hashcode: 0x7D4D2EB4 (dec: 2102210228)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xB12E2F50 (dec: -1322373296), parent name: 'CINEPSX_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x9D75D549 (dec: -1653222071), parent name: 'CINEPSX_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_69fake // hashcode: 0xE54B4D14 (dec: -448049900)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x24C1533C (dec: 616649532), parent name: 'CINEPSX_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xE5D65716 (dec: -438937834), parent name: 'CINEPSX_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_70fake // hashcode: 0x92FE8A84 (dec: -1828812156)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x2ADC7E3F (dec: 719093311), parent name: 'CINEPSX_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x3CFC2919 (dec: 1023158553), parent name: 'CINEPSX_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union CINEPSX_71fake // Hashcode: 0xC9DD8A44 (dec: -908228028)
{
	struct CINEPSX_68fake callback; // size=8, offset=0
	struct CINEPSX_69fake vector;   // size=12, offset=0
	struct CINEPSX_70fake quat;		// size=16, offset=0
};

union CINEPSX_72fake // Hashcode: 0x52A4E0FA (dec: 1386537210)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union CINEPSX_73fake // Hashcode: 0xB2170195 (dec: -1307115115)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct CINEPSX_74fake // hashcode: 0xE48656B8 (dec: -460958024)
{
	union CINEPSX_73fake size; // size=4, offset=0 //  hashcode: 0x1F88FE05 (dec: 529071621), parent name: 'CINEPSX_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_75fake // hashcode: 0xE1C442F3 (dec: -507231501)
{
	short x;				// size=0, offset=0 //  hashcode: 0xB1398998 (dec: -1321629288), parent name: 'CINEPSX_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x8B680D3C (dec: -1956115140), parent name: 'CINEPSX_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x36CD2D3D (dec: 919416125), parent name: 'CINEPSX_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x2955787C (dec: 693467260), parent name: 'CINEPSX_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xE019B871 (dec: -535185295), parent name: 'CINEPSX_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_76fake // hashcode: 0xF15B9D79 (dec: -245654151)
{
	long index; // size=0, offset=0 //  hashcode: 0xD14F179A (dec: -783345766), parent name: 'CINEPSX_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xD34893DF (dec: -750218273), parent name: 'CINEPSX_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_77fake // hashcode: 0x55BD4F15 (dec: 1438469909)
{
	long index; // size=0, offset=0 //  hashcode: 0xC8A87520 (dec: -928484064), parent name: 'CINEPSX_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x89BCE2CB (dec: -1984109877), parent name: 'CINEPSX_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_78fake // hashcode: 0xCBBE535D (dec: -876719267)
{
	long index; // size=0, offset=0 //  hashcode: 0x08FD30F6 (dec: 150810870), parent name: 'CINEPSX_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x3E1BCD2B (dec: 1042009387), parent name: 'CINEPSX_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_79fake // hashcode: 0x419C1E19 (dec: 1100750361)
{
	long time;  // size=0, offset=0 //  hashcode: 0x36AED4A3 (dec: 917427363), parent name: 'CINEPSX_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xA05AFAC8 (dec: -1604650296), parent name: 'CINEPSX_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_80fake // hashcode: 0xCF93B100 (dec: -812404480)
{
	long action;   // size=0, offset=0 //  hashcode: 0xBAC1B7A6 (dec: -1161709658), parent name: 'CINEPSX_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xB17AE48B (dec: -1317346165), parent name: 'CINEPSX_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_81fake // hashcode: 0xB00EAEB7 (dec: -1341215049)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xBC2F75CF (dec: -1137740337), parent name: 'CINEPSX_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x48F4987C (dec: 1223989372), parent name: 'CINEPSX_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_82fake // hashcode: 0xD32AA0E1 (dec: -752181023)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x794EEB3A (dec: 2035215162), parent name: 'CINEPSX_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x2660FCFA (dec: 643890426), parent name: 'CINEPSX_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_83fake // hashcode: 0x0FBF0FEB (dec: 264179691)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x04164520 (dec: 68568352), parent name: 'CINEPSX_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x3C1095A0 (dec: 1007719840), parent name: 'CINEPSX_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_84fake // hashcode: 0x4A3E025B (dec: 1245577819)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x6D6A5364 (dec: 1835684708), parent name: 'CINEPSX_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x74024CF7 (dec: 1946307831), parent name: 'CINEPSX_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x00672EDE (dec: 6762206), parent name: 'CINEPSX_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x0B0BDBBA (dec: 185326522), parent name: 'CINEPSX_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x6A4E15A7 (dec: 1783502247), parent name: 'CINEPSX_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_85fake // hashcode: 0x57059C05 (dec: 1459985413)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xF1E5DD4E (dec: -236593842), parent name: 'CINEPSX_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x3F467E30 (dec: 1061584432), parent name: 'CINEPSX_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_86fake // hashcode: 0xF82714BD (dec: -131656515)
{
	short index;					// size=0, offset=0 //  hashcode: 0x4DAD5610 (dec: 1303205392), parent name: 'CINEPSX_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x57DADAE2 (dec: 1473960674), parent name: 'CINEPSX_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x55AA7C45 (dec: 1437236293), parent name: 'CINEPSX_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x3EE2687E (dec: 1055025278), parent name: 'CINEPSX_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_87fake // hashcode: 0x6FE4DD47 (dec: 1877269831)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x35AD5DFF (dec: 900554239), parent name: 'CINEPSX_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xF109132A (dec: -251063510), parent name: 'CINEPSX_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xFE95E00B (dec: -23732213), parent name: 'CINEPSX_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_88fake // hashcode: 0xC8D2541B (dec: -925740005)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x684F26FD (dec: 1750017789), parent name: 'CINEPSX_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xB54CA2E1 (dec: -1253268767), parent name: 'CINEPSX_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xD89B30E3 (dec: -660918045), parent name: 'CINEPSX_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x1995F939 (dec: 429259065), parent name: 'CINEPSX_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xBC512E81 (dec: -1135530367), parent name: 'CINEPSX_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xB89E991A (dec: -1197565670), parent name: 'CINEPSX_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x3A03D6E2 (dec: 973330146), parent name: 'CINEPSX_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_89fake // hashcode: 0xC398170A (dec: -1013442806)
{
	long index;  // size=0, offset=0 //  hashcode: 0x617BC0A7 (dec: 1635500199), parent name: 'CINEPSX_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x109BDE32 (dec: 278650418), parent name: 'CINEPSX_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_90fake // hashcode: 0x5DB7FB56 (dec: 1572338518)
{
	short type; // size=0, offset=0 //  hashcode: 0x8DFF9CE1 (dec: -1912627999), parent name: 'CINEPSX_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x5543E9F7 (dec: 1430514167), parent name: 'CINEPSX_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_91fake // hashcode: 0x9948AE1A (dec: -1723290086)
{
	long time;   // size=0, offset=0 //  hashcode: 0x43C06AE1 (dec: 1136683745), parent name: 'CINEPSX_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x3A81155B (dec: 981538139), parent name: 'CINEPSX_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_92fake // hashcode: 0xC9A4BDB7 (dec: -911950409)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xA7AC0786 (dec: -1481898106), parent name: 'CINEPSX_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xC81CD75C (dec: -937633956), parent name: 'CINEPSX_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_93fake // hashcode: 0xD665382A (dec: -698009558)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x637B3A49 (dec: 1669020233), parent name: 'CINEPSX_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xDB8DDC11 (dec: -611460079), parent name: 'CINEPSX_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_94fake // hashcode: 0xC487D9D0 (dec: -997729840)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xD9D462B8 (dec: -640392520), parent name: 'CINEPSX_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x192F4686 (dec: 422528646), parent name: 'CINEPSX_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_95fake // hashcode: 0x0DC37A01 (dec: 230914561)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x04D6E6FE (dec: 81192702), parent name: 'CINEPSX_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xCDA2EBD5 (dec: -844960811), parent name: 'CINEPSX_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xC06EED59 (dec: -1066472103), parent name: 'CINEPSX_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x699CAC35 (dec: 1771875381), parent name: 'CINEPSX_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_96fake // hashcode: 0x14AE20D4 (dec: 346955988)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x6A190251 (dec: 1780023889), parent name: 'CINEPSX_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x81F84BE7 (dec: -2114434073), parent name: 'CINEPSX_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x95D74FAA (dec: -1781051478), parent name: 'CINEPSX_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x5AFC4905 (dec: 1526483205), parent name: 'CINEPSX_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x690673D2 (dec: 1762030546), parent name: 'CINEPSX_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union CINEPSX_97fake // Hashcode: 0x483691DC (dec: 1211535836)
{
	struct CINEPSX_74fake misc[3];		// size=12, offset=0
	struct _CameraKey *cameraKey;		// size=24, offset=0
	struct CINEPSX_75fake teleport;		// size=16, offset=0
	struct CINEPSX_76fake cameraValue;  // size=8, offset=0
	struct CINEPSX_77fake miscValue;	// size=8, offset=0
	struct CINEPSX_78fake logicValue;   // size=8, offset=0
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
	struct CINEPSX_79fake cameraShake;  // size=8, offset=0
	long cameraSave;					// size=0, offset=0
	long cameraRestore;					// size=0, offset=0
	struct _BGObject *bgObject;			// size=24, offset=0
	long value[2];						// size=8, offset=0
	struct CINEPSX_80fake sound;		// size=12, offset=0
	void *intro;						// size=0, offset=0
	long deathZ;						// size=0, offset=0
	struct CINEPSX_81fake dsignal;		// size=8, offset=0
	void *mirror;						// size=0, offset=0
	long fogNear;						// size=0, offset=0
	long fogFar;						// size=0, offset=0
	struct CINEPSX_82fake gotoFrame;	// size=8, offset=0
	struct CINEPSX_83fake changeModel;  // size=8, offset=0
	void *vmObject;						// size=0, offset=0
	struct CINEPSX_84fake logic;		// size=8, offset=0
	void *callSignal;					// size=0, offset=0
	struct _SVector offset;				// size=8, offset=0
	struct Signal *gotoLabel;			// size=0, offset=0
	struct Signal *gosubLabel;			// size=0, offset=0
	struct CINEPSX_85fake control;		// size=8, offset=0
	struct CINEPSX_86fake zSignal;		// size=12, offset=0
	struct CINEPSX_87fake StreamLevel;  // size=24, offset=0
	struct CINEPSX_88fake shards;		// size=12, offset=0
	struct CINEPSX_89fake cameraSpline; // size=8, offset=0
	struct CINEPSX_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;					// size=0, offset=0
	struct CINEPSX_91fake introFX;		// size=8, offset=0
	struct CINEPSX_92fake introActive;  // size=8, offset=0
	struct CINEPSX_93fake levelChange;  // size=18, offset=0
	long blendStart;					// size=0, offset=0
	struct CINEPSX_94fake setTimes;		// size=8, offset=0
	struct CINEPSX_95fake color;		// size=4, offset=0
	struct CINEPSX_96fake print;		// size=12, offset=0
	long slideAngle;					// size=0, offset=0
};

union CINEPSX_98fake // Hashcode: 0x5DEAB087 (dec: 1575661703)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union CINEPSX_103fake // Hashcode: 0xD88BF91F (dec: -661915361)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct CINEPSX_105fake // hashcode: 0x46E1FC38 (dec: 1189215288)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xD735E0F4 (dec: -684334860), parent name: 'CINEPSX_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xA8F07FA9 (dec: -1460633687), parent name: 'CINEPSX_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0xBE9D53A0 (dec: -1096985696), parent name: 'CINEPSX_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x904C779E (dec: -1874036834), parent name: 'CINEPSX_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x0A48C446 (dec: 172540998), parent name: 'CINEPSX_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x8E2355E7 (dec: -1910286873), parent name: 'CINEPSX_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x570FB098 (dec: 1460646040), parent name: 'CINEPSX_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_106fake // hashcode: 0x29B69AA2 (dec: 699832994)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x1AA454B5 (dec: 446977205), parent name: 'CINEPSX_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x2BD0AE85 (dec: 735096453), parent name: 'CINEPSX_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x09FED9A1 (dec: 167696801), parent name: 'CINEPSX_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_107fake // hashcode: 0xF8A5A9DC (dec: -123360804)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x6256DF8E (dec: 1649860494), parent name: 'CINEPSX_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x6FFE76F9 (dec: 1878947577), parent name: 'CINEPSX_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x8327A1F7 (dec: -2094554633), parent name: 'CINEPSX_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x84403A8C (dec: -2076165492), parent name: 'CINEPSX_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x091C4B22 (dec: 152849186), parent name: 'CINEPSX_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_108fake // hashcode: 0x516FDD89 (dec: 1366285705)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x044F7203 (dec: 72315395), parent name: 'CINEPSX_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x3B623A79 (dec: 996293241), parent name: 'CINEPSX_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0xD23B3E15 (dec: -767869419), parent name: 'CINEPSX_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xBAEBB407 (dec: -1158958073), parent name: 'CINEPSX_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x23282FFC (dec: 589836284), parent name: 'CINEPSX_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CINEPSX_109fake // hashcode: 0xCA47EDB9 (dec: -901255751)
{
	struct CINEPSX_105fake Cinematic; // size=28, offset=0 //  hashcode: 0x6750D79D (dec: 1733351325), parent name: 'CINEPSX_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CINEPSX_106fake Idle;	  // size=20, offset=28 //  hashcode: 0x0613EBAA (dec: 101968810), parent name: 'CINEPSX_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CINEPSX_107fake Behind;	// size=28, offset=48 //  hashcode: 0xE0754AEF (dec: -529184017), parent name: 'CINEPSX_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CINEPSX_108fake Follow;	// size=20, offset=76 //  hashcode: 0xB4012D94 (dec: -1274991212), parent name: 'CINEPSX_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union CINEPSX_188fake // Hashcode: 0x6F4C9E8E (dec: 1867292302)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union CINEPSX_211fake // Hashcode: 0x8DD526F5 (dec: -1915410699)
{
	unsigned short pad;			  // size=0, offset=0
	unsigned short multitap[16];  // size=32, offset=0
	unsigned short mouse[2];	  // size=4, offset=0
	unsigned short negcon[3];	 // size=6, offset=0
	struct AnalogueData analogue; // size=6, offset=0
};

typedef struct cinema_fn_table_t cinema_fn_table_t;

typedef int PlayCinematic_t();

extern int CINE_CDIntrQuery(); // 0x800B777C

extern unsigned short CINE_Pad(int pad); // 0x800B77A4

extern void CINE_Play(char *strfile, unsigned short mask, int buffers); // 0x800B77C8

extern int CINE_Load(); // 0x800B782C

extern int CINE_Loaded(); // 0x800B78D0

extern void CINE_Unload(); // 0x800B78E0

extern void CINE_PlayIngame(int number); // 0x800B7928

#endif
