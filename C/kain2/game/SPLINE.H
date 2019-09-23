#ifndef SPLINE_H
#define SPLINE_H

struct SPLINE_68fake // hashcode: 0x8896102F (dec: -2003431377)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xAF7C1A3C (dec: -1350821316), parent name: 'SPLINE_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x38A70A6E (dec: 950471278), parent name: 'SPLINE_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_69fake // hashcode: 0x5DC7982D (dec: 1573361709)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xE6E99F9B (dec: -420896869), parent name: 'SPLINE_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x195B0E92 (dec: 425397906), parent name: 'SPLINE_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_70fake // hashcode: 0x6599E41E (dec: 1704584222)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xE85F3788 (dec: -396413048), parent name: 'SPLINE_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x2F890BC5 (dec: 797510597), parent name: 'SPLINE_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SPLINE_71fake // Hashcode: 0x4CDE9A19 (dec: 1289656857)
{
	struct SPLINE_68fake callback; // size=8, offset=0
	struct SPLINE_69fake vector;   // size=12, offset=0
	struct SPLINE_70fake quat;	 // size=16, offset=0
};

union SPLINE_72fake // Hashcode: 0x9E0EEC67 (dec: -1643189145)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union SPLINE_73fake // Hashcode: 0xD64C897A (dec: -699627142)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct SPLINE_74fake // hashcode: 0x4E3A6715 (dec: 1312450325)
{
	union SPLINE_73fake size; // size=4, offset=0 //  hashcode: 0x808575C2 (dec: -2138737214), parent name: 'SPLINE_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_75fake // hashcode: 0xF6170040 (dec: -166264768)
{
	short x;				// size=0, offset=0 //  hashcode: 0x77E6920E (dec: 2011599374), parent name: 'SPLINE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x1D965C04 (dec: 496393220), parent name: 'SPLINE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x992EE6FC (dec: -1724979460), parent name: 'SPLINE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xD242C0E8 (dec: -767377176), parent name: 'SPLINE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xB4C5BF56 (dec: -1262108842), parent name: 'SPLINE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_76fake // hashcode: 0xCD490D93 (dec: -850850413)
{
	long index; // size=0, offset=0 //  hashcode: 0x2D10F0DB (dec: 756084955), parent name: 'SPLINE_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x9A350D54 (dec: -1707799212), parent name: 'SPLINE_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_77fake // hashcode: 0xAD08EDC6 (dec: -1391923770)
{
	long index; // size=0, offset=0 //  hashcode: 0x0D707B99 (dec: 225475481), parent name: 'SPLINE_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xBDEB8E99 (dec: -1108636007), parent name: 'SPLINE_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_78fake // hashcode: 0x08D96242 (dec: 148464194)
{
	long index; // size=0, offset=0 //  hashcode: 0x411DF17A (dec: 1092481402), parent name: 'SPLINE_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xDAAC985D (dec: -626223011), parent name: 'SPLINE_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_79fake // hashcode: 0xF01A7BE9 (dec: -266699799)
{
	long time;  // size=0, offset=0 //  hashcode: 0xE64BDD17 (dec: -431235817), parent name: 'SPLINE_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x323324E9 (dec: 842212585), parent name: 'SPLINE_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_80fake // hashcode: 0x943F406E (dec: -1807794066)
{
	long action;   // size=0, offset=0 //  hashcode: 0xE842403A (dec: -398311366), parent name: 'SPLINE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xE72BFA0A (dec: -416548342), parent name: 'SPLINE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_81fake // hashcode: 0x7AEB4FFB (dec: 2062241787)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x740CEA3C (dec: 1947003452), parent name: 'SPLINE_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x14F303DB (dec: 351470555), parent name: 'SPLINE_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_82fake // hashcode: 0x1BE736AB (dec: 468137643)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x2C010232 (dec: 738263602), parent name: 'SPLINE_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0xBA7A0548 (dec: -1166408376), parent name: 'SPLINE_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_83fake // hashcode: 0x005F5137 (dec: 6246711)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xABC5BDF7 (dec: -1413104137), parent name: 'SPLINE_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x859055F4 (dec: -2054138380), parent name: 'SPLINE_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_84fake // hashcode: 0xE10AF294 (dec: -519376236)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x6DF57DE8 (dec: 1844805096), parent name: 'SPLINE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x42E0498B (dec: 1121995147), parent name: 'SPLINE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xFFAF3982 (dec: -5293694), parent name: 'SPLINE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xD002A1CB (dec: -805133877), parent name: 'SPLINE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x4EE36D5B (dec: 1323527515), parent name: 'SPLINE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_85fake // hashcode: 0xDD4BC9D7 (dec: -582235689)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x2733864B (dec: 657688139), parent name: 'SPLINE_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x73BB71D9 (dec: 1941664217), parent name: 'SPLINE_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_86fake // hashcode: 0xCB5BA2E9 (dec: -883186967)
{
	short index;					// size=0, offset=0 //  hashcode: 0x60414584 (dec: 1614890372), parent name: 'SPLINE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xAB6C1663 (dec: -1418979741), parent name: 'SPLINE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xF03BD1FD (dec: -264515075), parent name: 'SPLINE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x366657AA (dec: 912676778), parent name: 'SPLINE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_87fake // hashcode: 0xB8D4B52B (dec: -1194019541)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x430DEDA9 (dec: 1124986281), parent name: 'SPLINE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x4600A3A2 (dec: 1174447010), parent name: 'SPLINE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x75AB99F0 (dec: 1974180336), parent name: 'SPLINE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_88fake // hashcode: 0x79D8EB34 (dec: 2044259124)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x701CB469 (dec: 1880929385), parent name: 'SPLINE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xDF09BC90 (dec: -553010032), parent name: 'SPLINE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x97A6F81C (dec: -1750665188), parent name: 'SPLINE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xC151C0F8 (dec: -1051606792), parent name: 'SPLINE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xB378523E (dec: -1283960258), parent name: 'SPLINE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xD33FC600 (dec: -750795264), parent name: 'SPLINE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xFC76F616 (dec: -59312618), parent name: 'SPLINE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_89fake // hashcode: 0x5763B204 (dec: 1466151428)
{
	long index;  // size=0, offset=0 //  hashcode: 0x251866F5 (dec: 622356213), parent name: 'SPLINE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x9BB72B1E (dec: -1682494690), parent name: 'SPLINE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_90fake // hashcode: 0x0FBAD26C (dec: 263901804)
{
	short type; // size=0, offset=0 //  hashcode: 0x717032C6 (dec: 1903178438), parent name: 'SPLINE_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xC0C13C6F (dec: -1061077905), parent name: 'SPLINE_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_91fake // hashcode: 0x6E6A4CF3 (dec: 1852460275)
{
	long time;   // size=0, offset=0 //  hashcode: 0x08FE61AA (dec: 150888874), parent name: 'SPLINE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x45D9DCAA (dec: 1171905706), parent name: 'SPLINE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_92fake // hashcode: 0x6A9E3885 (dec: 1788754053)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x32DA25F7 (dec: 853157367), parent name: 'SPLINE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xEA4121C4 (dec: -364830268), parent name: 'SPLINE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_93fake // hashcode: 0xF61613E5 (dec: -166325275)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xAE2DE61F (dec: -1372723681), parent name: 'SPLINE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x1D60E034 (dec: 492888116), parent name: 'SPLINE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_94fake // hashcode: 0xEDED9F36 (dec: -303194314)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x35013740 (dec: 889272128), parent name: 'SPLINE_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x1350638E (dec: 324035470), parent name: 'SPLINE_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_95fake // hashcode: 0xDEF88733 (dec: -554137805)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x3D5524CA (dec: 1028990154), parent name: 'SPLINE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xF9E16A81 (dec: -102667647), parent name: 'SPLINE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x64BB906A (dec: 1690013802), parent name: 'SPLINE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x1DA78141 (dec: 497516865), parent name: 'SPLINE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SPLINE_96fake // hashcode: 0xFABAAF13 (dec: -88428781)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x5756EE92 (dec: 1465314962), parent name: 'SPLINE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x2AACE980 (dec: 715975040), parent name: 'SPLINE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x4BD98E56 (dec: 1272548950), parent name: 'SPLINE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xCE391B7A (dec: -835118214), parent name: 'SPLINE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x4B79D6E6 (dec: 1266276070), parent name: 'SPLINE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SPLINE_97fake // Hashcode: 0xD96D23AD (dec: -647158867)
{
	struct SPLINE_74fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	  // size=24, offset=0
	struct SPLINE_75fake teleport;	 // size=16, offset=0
	struct SPLINE_76fake cameraValue;  // size=8, offset=0
	struct SPLINE_77fake miscValue;	// size=8, offset=0
	struct SPLINE_78fake logicValue;   // size=8, offset=0
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
	struct SPLINE_79fake cameraShake;  // size=8, offset=0
	long cameraSave;				   // size=0, offset=0
	long cameraRestore;				   // size=0, offset=0
	struct _BGObject *bgObject;		   // size=24, offset=0
	long value[2];					   // size=8, offset=0
	struct SPLINE_80fake sound;		   // size=12, offset=0
	void *intro;					   // size=0, offset=0
	long deathZ;					   // size=0, offset=0
	struct SPLINE_81fake dsignal;	  // size=8, offset=0
	void *mirror;					   // size=0, offset=0
	long fogNear;					   // size=0, offset=0
	long fogFar;					   // size=0, offset=0
	struct SPLINE_82fake gotoFrame;	// size=8, offset=0
	struct SPLINE_83fake changeModel;  // size=8, offset=0
	void *vmObject;					   // size=0, offset=0
	struct SPLINE_84fake logic;		   // size=8, offset=0
	void *callSignal;				   // size=0, offset=0
	struct _SVector offset;			   // size=8, offset=0
	struct Signal *gotoLabel;		   // size=0, offset=0
	struct Signal *gosubLabel;		   // size=0, offset=0
	struct SPLINE_85fake control;	  // size=8, offset=0
	struct SPLINE_86fake zSignal;	  // size=12, offset=0
	struct SPLINE_87fake StreamLevel;  // size=24, offset=0
	struct SPLINE_88fake shards;	   // size=12, offset=0
	struct SPLINE_89fake cameraSpline; // size=8, offset=0
	struct SPLINE_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;				   // size=0, offset=0
	struct SPLINE_91fake introFX;	  // size=8, offset=0
	struct SPLINE_92fake introActive;  // size=8, offset=0
	struct SPLINE_93fake levelChange;  // size=18, offset=0
	long blendStart;				   // size=0, offset=0
	struct SPLINE_94fake setTimes;	 // size=8, offset=0
	struct SPLINE_95fake color;		   // size=4, offset=0
	struct SPLINE_96fake print;		   // size=12, offset=0
	long slideAngle;				   // size=0, offset=0
};

union SPLINE_98fake // Hashcode: 0xCF190D49 (dec: -820441783)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union SPLINE_103fake // Hashcode: 0xC6819935 (dec: -964585163)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

extern void _SplineS2Pos(struct vecS *p, long s, struct SplineKey *key, struct SplineKey *key2); // 0x80040C18

extern void SplineSetDefDenom(struct Spline *spline, struct SplineDef *def, int denomFlag); // 0x80040D88

extern unsigned short SplineGetFrameNumber(struct Spline *spline, struct SplineDef *def); // 0x80040E4C

extern short SplineSetDef2FrameNumber(struct Spline *spline, struct SplineDef *def, unsigned short frame_number); // 0x80040EE0

extern short SplineIsWhere(struct Spline *spline, struct SplineDef *def); // 0x80041010

extern short SplineMultiIsWhere(struct MultiSpline *multi); // 0x80041078

extern struct _G2Quat_Type *SplineGetFirstRot(struct RSpline *rspline, struct SplineDef *def); // 0x80041104

extern struct _SVector *SplineGetFirstPoint(struct Spline *spline, struct SplineDef *def); // 0x8004112C

extern struct _SVector *SplineGetNextPoint(struct Spline *spline, struct SplineDef *def); // 0x80041154

extern struct _SVector *SplineGetPreviousPoint(struct Spline *spline, struct SplineDef *def); // 0x800411AC

extern struct _SVector *SplineGetNearestPoint(struct Spline *spline, struct _SVector *point, struct SplineDef *def); // 0x80041204

extern unsigned long SplineGetData(struct Spline *spline, struct SplineDef *def, void *p); // 0x800415C0

extern unsigned long SplineGetQuatData(struct Spline *spline, struct SplineDef *def, void *p); // 0x800417D0

extern unsigned long SplineGetNext(struct Spline *spline, struct SplineDef *def); // 0x80041904

extern unsigned long SplineGetPrev(struct Spline *spline, struct SplineDef *def); // 0x80041A20

extern unsigned long SplineGetOffsetNext(struct Spline *spline, struct SplineDef *def, long fracOffset); // 0x80041B4C

extern unsigned long SplineGetOffsetPrev(struct Spline *spline, struct SplineDef *def, long fracOffset); // 0x80041D30

extern struct _SVector *SplineGetOffsetNextPoint(struct Spline *spline, struct SplineDef *def, long offset); // 0x80041EA4

extern struct _SVector *SplineGetOffsetPreviousPoint(struct Spline *spline, struct SplineDef *def, long offset); // 0x80041EFC

#endif
