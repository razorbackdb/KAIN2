#ifndef COLLIDE_H
#define COLLIDE_H

extern struct _SVector collide_localPoint; // offset 0x800D0370

extern struct MATRIX *collide_lwTransform; // offset 0x800D0378

extern struct _SVector *collide_normal0; // offset 0x800D037C

extern struct _SVector *collide_normal1; // offset 0x800D0380

extern struct _SVector *collide_point0; // offset 0x800D0360

extern struct _SVector *collide_point1; // offset 0x800D0364

extern long dyna_clddyna[8]; // offset 0x800CE104

extern long dyna_cldstat[8]; // offset 0x800CE144

extern long stat_clddyna[8]; // offset 0x800CE124

struct COLLIDE_73fake // hashcode: 0xBA8EE625 (dec: -1165040091)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x87B9BCC3 (dec: -2017870653), parent name: 'COLLIDE_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x45A3713B (dec: 1168339259), parent name: 'COLLIDE_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_74fake // hashcode: 0x6121EE34 (dec: 1629613620)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x6A24164C (dec: 1780749900), parent name: 'COLLIDE_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x2D6DAEB1 (dec: 762162865), parent name: 'COLLIDE_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_75fake // hashcode: 0x6728ABA1 (dec: 1730718625)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x4CB5AEF0 (dec: 1286975216), parent name: 'COLLIDE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x153734C8 (dec: 355939528), parent name: 'COLLIDE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union COLLIDE_76fake // Hashcode: 0x3AA65B79 (dec: 983980921)
{
	struct COLLIDE_73fake callback; // size=8, offset=0
	struct COLLIDE_74fake vector;   // size=12, offset=0
	struct COLLIDE_75fake quat;		// size=16, offset=0
};

struct _Vector // hashcode: 0x5DEB6D24 (dec: 1575709988)
{
	long x; // size=0, offset=0 //  hashcode: 0x183E1804 (dec: 406722564), parent name: '_Vector', parent hashcode: 0xFFFFFFFF (dec: -1)
	long y; // size=0, offset=4 //  hashcode: 0x1A2D0179 (dec: 439157113), parent name: '_Vector', parent hashcode: 0xFFFFFFFF (dec: -1)
	long z; // size=0, offset=8 //  hashcode: 0x0AD6D16C (dec: 181850476), parent name: '_Vector', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Triangle2D // hashcode: 0xD422B451 (dec: -735923119)
{
	short x0; // size=0, offset=0 //  hashcode: 0xBEABDF2D (dec: -1096032467), parent name: '_Triangle2D', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0; // size=0, offset=2 //  hashcode: 0xEFB485B3 (dec: -273381965), parent name: '_Triangle2D', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1; // size=0, offset=4 //  hashcode: 0xB0899043 (dec: -1333161917), parent name: '_Triangle2D', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1; // size=0, offset=6 //  hashcode: 0x8A1C2EC5 (dec: -1977864507), parent name: '_Triangle2D', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2; // size=0, offset=8 //  hashcode: 0x41101274 (dec: 1091572340), parent name: '_Triangle2D', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2; // size=0, offset=10 //  hashcode: 0x4D349F22 (dec: 1295294242), parent name: '_Triangle2D', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union COLLIDE_77fake // Hashcode: 0xCA00C1AF (dec: -905920081)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union COLLIDE_78fake // Hashcode: 0xAEDCE883 (dec: -1361254269)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct COLLIDE_79fake // hashcode: 0xC52469B6 (dec: -987469386)
{
	union COLLIDE_78fake size; // size=4, offset=0 //  hashcode: 0x97BBEA24 (dec: -1749292508), parent name: 'COLLIDE_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_80fake // hashcode: 0x9551F152 (dec: -1789791918)
{
	short x;				// size=0, offset=0 //  hashcode: 0x552D677C (dec: 1429038972), parent name: 'COLLIDE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x297E44C6 (dec: 696140998), parent name: 'COLLIDE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x8DDA1204 (dec: -1915088380), parent name: 'COLLIDE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x807B1226 (dec: -2139418074), parent name: 'COLLIDE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x116FBE73 (dec: 292535923), parent name: 'COLLIDE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_81fake // hashcode: 0xCFAB3DA6 (dec: -810861146)
{
	long index; // size=0, offset=0 //  hashcode: 0x5EAE8257 (dec: 1588494935), parent name: 'COLLIDE_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xD944A21A (dec: -649813478), parent name: 'COLLIDE_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_82fake // hashcode: 0x79935A9A (dec: 2039700122)
{
	long index; // size=0, offset=0 //  hashcode: 0x0899225A (dec: 144253530), parent name: 'COLLIDE_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xEC3EA374 (dec: -331439244), parent name: 'COLLIDE_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_83fake // hashcode: 0x3DE4419D (dec: 1038369181)
{
	long index; // size=0, offset=0 //  hashcode: 0xD75D57A0 (dec: -681748576), parent name: 'COLLIDE_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xF4A0CB2C (dec: -190788820), parent name: 'COLLIDE_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_84fake // hashcode: 0x73E80835 (dec: 1944586293)
{
	long time;  // size=0, offset=0 //  hashcode: 0x54ECD685 (dec: 1424807557), parent name: 'COLLIDE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xBD3DE87E (dec: -1120016258), parent name: 'COLLIDE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_85fake // hashcode: 0xAB368EDF (dec: -1422487841)
{
	long action;   // size=0, offset=0 //  hashcode: 0xF689379A (dec: -158779494), parent name: 'COLLIDE_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x56B632F8 (dec: 1454781176), parent name: 'COLLIDE_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_86fake // hashcode: 0x91C952F0 (dec: -1849077008)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xC3794A02 (dec: -1015461374), parent name: 'COLLIDE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x81468C02 (dec: -2126083070), parent name: 'COLLIDE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_87fake // hashcode: 0xA26BBC54 (dec: -1569997740)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x37CC6B67 (dec: 936143719), parent name: 'COLLIDE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x437DA97E (dec: 1132308862), parent name: 'COLLIDE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_88fake // hashcode: 0x37CFD5F6 (dec: 936367606)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xB0307F5A (dec: -1338998950), parent name: 'COLLIDE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x7B68104E (dec: 2070417486), parent name: 'COLLIDE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_89fake // hashcode: 0xBA982A0D (dec: -1164432883)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x0C6337FC (dec: 207828988), parent name: 'COLLIDE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x3D21BE9C (dec: 1025621660), parent name: 'COLLIDE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x65C3E9B8 (dec: 1707338168), parent name: 'COLLIDE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x10091B74 (dec: 269032308), parent name: 'COLLIDE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x99F8D809 (dec: -1711745015), parent name: 'COLLIDE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_90fake // hashcode: 0xBDFD0FE1 (dec: -1107488799)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xF6EA79CF (dec: -152405553), parent name: 'COLLIDE_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xCBA7C20F (dec: -878198257), parent name: 'COLLIDE_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_91fake // hashcode: 0xF07DD035 (dec: -260190155)
{
	short index;					// size=0, offset=0 //  hashcode: 0x9053F3E1 (dec: -1873546271), parent name: 'COLLIDE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xC7008CF6 (dec: -956265226), parent name: 'COLLIDE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x8834F2EB (dec: -2009795861), parent name: 'COLLIDE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x5D5CC8D8 (dec: 1566361816), parent name: 'COLLIDE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_92fake // hashcode: 0x008C1BF5 (dec: 9182197)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x6C8F0927 (dec: 1821313319), parent name: 'COLLIDE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x89DBD764 (dec: -1982081180), parent name: 'COLLIDE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x91570FDC (dec: -1856565284), parent name: 'COLLIDE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_93fake // hashcode: 0x47FD0D69 (dec: 1207766377)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x0902B843 (dec: 151173187), parent name: 'COLLIDE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xC590BFBB (dec: -980369477), parent name: 'COLLIDE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xBE33CCCC (dec: -1103901492), parent name: 'COLLIDE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x95D793EE (dec: -1781034002), parent name: 'COLLIDE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xD834962B (dec: -667642325), parent name: 'COLLIDE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x0B29DFAB (dec: 187293611), parent name: 'COLLIDE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x10A76168 (dec: 279404904), parent name: 'COLLIDE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_94fake // hashcode: 0x25A9D931 (dec: 631888177)
{
	long index;  // size=0, offset=0 //  hashcode: 0x1AC51D1A (dec: 449125658), parent name: 'COLLIDE_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xB0E320F0 (dec: -1327292176), parent name: 'COLLIDE_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_95fake // hashcode: 0x3F62DD9C (dec: 1063443868)
{
	short type; // size=0, offset=0 //  hashcode: 0xB70FFDC3 (dec: -1223688765), parent name: 'COLLIDE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x7EFB14B7 (dec: 2130384055), parent name: 'COLLIDE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_96fake // hashcode: 0xC8BFF0FE (dec: -926945026)
{
	long time;   // size=0, offset=0 //  hashcode: 0xC746C6B0 (dec: -951662928), parent name: 'COLLIDE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xE5B5973C (dec: -441084100), parent name: 'COLLIDE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_97fake // hashcode: 0x96550730 (dec: -1772812496)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xC7804D18 (dec: -947892968), parent name: 'COLLIDE_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x7F2825C7 (dec: 2133337543), parent name: 'COLLIDE_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_98fake // hashcode: 0xF7F90918 (dec: -134674152)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x5F1FBCED (dec: 1595915501), parent name: 'COLLIDE_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x5DB2C073 (dec: 1571995763), parent name: 'COLLIDE_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_99fake // hashcode: 0xB761B8DD (dec: -1218332451)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x8C692122 (dec: -1939267294), parent name: 'COLLIDE_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x231852CE (dec: 588796622), parent name: 'COLLIDE_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_100fake // hashcode: 0x64739BFC (dec: 1685298172)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x4CD7CFAB (dec: 1289211819), parent name: 'COLLIDE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x0053E54F (dec: 5498191), parent name: 'COLLIDE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x3AAEAA43 (dec: 984525379), parent name: 'COLLIDE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x3C44CC23 (dec: 1011141667), parent name: 'COLLIDE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_101fake // hashcode: 0x474BA193 (dec: 1196138899)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x765C8C46 (dec: 1985776710), parent name: 'COLLIDE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xE314445A (dec: -485211046), parent name: 'COLLIDE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x56BC5621 (dec: 1455183393), parent name: 'COLLIDE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x1D35E3E5 (dec: 490071013), parent name: 'COLLIDE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x0A469308 (dec: 172397320), parent name: 'COLLIDE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union COLLIDE_102fake // Hashcode: 0x2E9D3454 (dec: 782054484)
{
	struct COLLIDE_79fake misc[3];		// size=12, offset=0
	struct _CameraKey *cameraKey;		// size=24, offset=0
	struct COLLIDE_80fake teleport;		// size=16, offset=0
	struct COLLIDE_81fake cameraValue;  // size=8, offset=0
	struct COLLIDE_82fake miscValue;	// size=8, offset=0
	struct COLLIDE_83fake logicValue;   // size=8, offset=0
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
	struct COLLIDE_84fake cameraShake;  // size=8, offset=0
	long cameraSave;					// size=0, offset=0
	long cameraRestore;					// size=0, offset=0
	struct _BGObject *bgObject;			// size=24, offset=0
	long value[2];						// size=8, offset=0
	struct COLLIDE_85fake sound;		// size=12, offset=0
	void *intro;						// size=0, offset=0
	long deathZ;						// size=0, offset=0
	struct COLLIDE_86fake dsignal;		// size=8, offset=0
	void *mirror;						// size=0, offset=0
	long fogNear;						// size=0, offset=0
	long fogFar;						// size=0, offset=0
	struct COLLIDE_87fake gotoFrame;	// size=8, offset=0
	struct COLLIDE_88fake changeModel;  // size=8, offset=0
	void *vmObject;						// size=0, offset=0
	struct COLLIDE_89fake logic;		// size=8, offset=0
	void *callSignal;					// size=0, offset=0
	struct _SVector offset;				// size=8, offset=0
	struct Signal *gotoLabel;			// size=0, offset=0
	struct Signal *gosubLabel;			// size=0, offset=0
	struct COLLIDE_90fake control;		// size=8, offset=0
	struct COLLIDE_91fake zSignal;		// size=12, offset=0
	struct COLLIDE_92fake StreamLevel;  // size=24, offset=0
	struct COLLIDE_93fake shards;		// size=12, offset=0
	struct COLLIDE_94fake cameraSpline; // size=8, offset=0
	struct COLLIDE_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;					// size=0, offset=0
	struct COLLIDE_96fake introFX;		// size=8, offset=0
	struct COLLIDE_97fake introActive;  // size=8, offset=0
	struct COLLIDE_98fake levelChange;  // size=18, offset=0
	long blendStart;					// size=0, offset=0
	struct COLLIDE_99fake setTimes;		// size=8, offset=0
	struct COLLIDE_100fake color;		// size=4, offset=0
	struct COLLIDE_101fake print;		// size=12, offset=0
	long slideAngle;					// size=0, offset=0
};

union COLLIDE_103fake // Hashcode: 0x33FE84CD (dec: 872318157)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

struct _PCollideInfo // hashcode: 0x32613C4B (dec: 845233227)
{
	short type;					// size=0, offset=0 //  hashcode: 0xEF8B3703 (dec: -276089085), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short segment;				// size=0, offset=2 //  hashcode: 0x00BF26F3 (dec: 12527347), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *prim;					// size=0, offset=4 //  hashcode: 0xE0291278 (dec: -534179208), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *inst;		// size=0, offset=8 //  hashcode: 0x78627B5B (dec: 2019720027), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR wNormal;		// size=8, offset=12 //  hashcode: 0xFBE566D9 (dec: -68852007), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR *newPoint;   // size=8, offset=20 //  hashcode: 0x9BE54E46 (dec: -1679471034), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR *oldPoint;   // size=8, offset=24 //  hashcode: 0x69F0F58B (dec: 1777399179), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR cldPoint;	// size=8, offset=28 //  hashcode: 0xAD7D25F0 (dec: -1384307216), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long collideType;			// size=0, offset=36 //  hashcode: 0xFC1456C0 (dec: -65775936), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=0, offset=40 //  hashcode: 0xBC294D1E (dec: -1138143970), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union COLLIDE_108fake // Hashcode: 0xC645C26B (dec: -968506773)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct COLLIDE_110fake // hashcode: 0x96B751A1 (dec: -1766370911)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x63BC95CE (dec: 1673303502), parent name: 'COLLIDE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x1C40601E (dec: 473980958), parent name: 'COLLIDE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x147DF9C7 (dec: 343800263), parent name: 'COLLIDE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x1D8E5E64 (dec: 495869540), parent name: 'COLLIDE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x447F0967 (dec: 1149176167), parent name: 'COLLIDE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x40E6FB81 (dec: 1088879489), parent name: 'COLLIDE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x6F2B5D95 (dec: 1865112981), parent name: 'COLLIDE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_111fake // hashcode: 0xCB4E04F8 (dec: -884079368)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x3C79B02B (dec: 1014607915), parent name: 'COLLIDE_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x103DD963 (dec: 272488803), parent name: 'COLLIDE_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x09946295 (dec: 160719509), parent name: 'COLLIDE_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_112fake // hashcode: 0x9F92E7C9 (dec: -1617762359)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xF5EF99CB (dec: -168846901), parent name: 'COLLIDE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xECAD3FCE (dec: -324190258), parent name: 'COLLIDE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x5A2E63CD (dec: 1512989645), parent name: 'COLLIDE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xE2EA5E83 (dec: -487956861), parent name: 'COLLIDE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xD34FFE1E (dec: -749732322), parent name: 'COLLIDE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_113fake // hashcode: 0x4FCA2919 (dec: 1338648857)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x90EE8FE5 (dec: -1863413787), parent name: 'COLLIDE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x5EBF43BB (dec: 1589593019), parent name: 'COLLIDE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x43162331 (dec: 1125524273), parent name: 'COLLIDE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x8A425D36 (dec: -1975362250), parent name: 'COLLIDE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x693041DA (dec: 1764770266), parent name: 'COLLIDE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_114fake // hashcode: 0xAAB68341 (dec: -1430879423)
{
	struct COLLIDE_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x5B01FA2D (dec: 1526856237), parent name: 'COLLIDE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct COLLIDE_111fake Idle;	  // size=20, offset=28 //  hashcode: 0x2A76C190 (dec: 712425872), parent name: 'COLLIDE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct COLLIDE_112fake Behind;	// size=28, offset=48 //  hashcode: 0x3C4F7DE2 (dec: 1011842530), parent name: 'COLLIDE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct COLLIDE_113fake Follow;	// size=20, offset=76 //  hashcode: 0xFDE75089 (dec: -35172215), parent name: 'COLLIDE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _HNormal // hashcode: 0xC53FB2BB (dec: -985681221)
{
	short x;   // size=0, offset=0 //  hashcode: 0x6EBB74BB (dec: 1857778875), parent name: '_HNormal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;   // size=0, offset=2 //  hashcode: 0xBD0A433D (dec: -1123400899), parent name: '_HNormal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;   // size=0, offset=4 //  hashcode: 0x939F422F (dec: -1818279377), parent name: '_HNormal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad; // size=0, offset=6 //  hashcode: 0x5E8A0D7B (dec: 1586105723), parent name: '_HNormal', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _HFaceInfo // hashcode: 0x0E79FF8C (dec: 242876300)
{
	long flags;				  // size=0, offset=0 //  hashcode: 0x2A75D7F0 (dec: 712366064), parent name: '_HFaceInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attr;				  // size=0, offset=4 //  hashcode: 0x016A08BA (dec: 23726266), parent name: '_HFaceInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HFace *hface;	 // size=12, offset=8 //  hashcode: 0x95CDA75E (dec: -1781684386), parent name: '_HFaceInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector normal;   // size=8, offset=12 //  hashcode: 0x46F48ECC (dec: 1190432460), parent name: '_HFaceInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HVertex *vertex0; // size=12, offset=20 //  hashcode: 0xA1CB0E43 (dec: -1580528061), parent name: '_HFaceInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HVertex *vertex1; // size=12, offset=24 //  hashcode: 0xACA7B6A8 (dec: -1398294872), parent name: '_HFaceInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HVertex *vertex2; // size=12, offset=28 //  hashcode: 0xA446FE1C (dec: -1538851300), parent name: '_HFaceInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _CollideInfo // hashcode: 0xCA2DF5E9 (dec: -902957591)
{
	void *level;			 // size=0, offset=0 //  hashcode: 0x53119B61 (dec: 1393662817), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;				 // size=0, offset=4 //  hashcode: 0x8914986B (dec: -1995138965), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	char segment;			 // size=0, offset=5 //  hashcode: 0x011FEB8E (dec: 18869134), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	char type0;				 // size=0, offset=6 //  hashcode: 0xD68DE3DF (dec: -695344161), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	char type1;				 // size=0, offset=7 //  hashcode: 0xBB7F1B09 (dec: -1149297911), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *prim0;			 // size=0, offset=8 //  hashcode: 0xAA5BCBFE (dec: -1436824578), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *prim1;			 // size=0, offset=12 //  hashcode: 0x03D75806 (dec: 64444422), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *inst0;			 // size=0, offset=16 //  hashcode: 0xC5CD0992 (dec: -976418414), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *inst1;			 // size=0, offset=20 //  hashcode: 0x65667B20 (dec: 1701215008), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR point0;   // size=8, offset=24 //  hashcode: 0x72E2B95E (dec: 1927461214), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR point1;   // size=8, offset=32 //  hashcode: 0x822619F8 (dec: -2111432200), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position offset; // size=6, offset=40 //  hashcode: 0x869AC941 (dec: -2036676287), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short bspID;			 // size=0, offset=46 //  hashcode: 0x2B597B88 (dec: 727284616), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _LCollideInfo // hashcode: 0xCC1DB336 (dec: -870468810)
{
	struct _TFace *tface;	 // size=12, offset=0 //  hashcode: 0xF22E9888 (dec: -231827320), parent name: '_LCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Terrain *terrain; // size=84, offset=4 //  hashcode: 0x6423E187 (dec: 1680073095), parent name: '_LCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int curTree;			  // size=0, offset=8 //  hashcode: 0x8E3301AE (dec: -1909259858), parent name: '_LCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCollideInfo // hashcode: 0x0DEAD21F (dec: 233493023)
{
	struct _Sphere *sphere;		// size=12, offset=0 //  hashcode: 0xAA4F0A39 (dec: -1437660615), parent name: 'SCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR *oldPos;		// size=8, offset=4 //  hashcode: 0x24F99E95 (dec: 620338837), parent name: 'SCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*collideFunc)();		// size=0, offset=8 //  hashcode: 0x77181FAA (dec: 1998069674), parent name: 'SCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long id;					// size=0, offset=12 //  hashcode: 0x9637A25C (dec: -1774738852), parent name: 'SCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;				// size=0, offset=16 //  hashcode: 0x6A54124B (dec: 1783894603), parent name: 'SCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=20 //  hashcode: 0x4A5BF10E (dec: 1247539470), parent name: 'SCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *prim;					// size=0, offset=24 //  hashcode: 0x43E5B881 (dec: 1139128449), parent name: 'SCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_190fake // hashcode: 0xB9D6BD5A (dec: -1177109158)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x292FA4E2 (dec: 690988258), parent name: 'COLLIDE_190fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x440F2F98 (dec: 1141845912), parent name: 'COLLIDE_190fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_191fake // hashcode: 0xAE6C53CB (dec: -1368632373)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0xA210A453 (dec: -1575967661), parent name: 'COLLIDE_191fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x7CD5722B (dec: 2094363179), parent name: 'COLLIDE_191fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x9CFB8484 (dec: -1661238140), parent name: 'COLLIDE_191fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x29CBB594 (dec: 701216148), parent name: 'COLLIDE_191fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x7B400851 (dec: 2067794001), parent name: 'COLLIDE_191fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0xB0B74AF6 (dec: -1330165002), parent name: 'COLLIDE_191fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union COLLIDE_192fake // Hashcode: 0x6F7377E1 (dec: 1869838305)
{
	struct COLLIDE_190fake flame; // size=8, offset=0
	struct COLLIDE_191fake phys;  // size=12, offset=0
};

union COLLIDE_218fake // Hashcode: 0x489C3F73 (dec: 1218199411)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union COLLIDE_246fake // Hashcode: 0x095377A5 (dec: 156465061)
{
	struct Intro *intro;	   // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

union COLLIDE_248fake // Hashcode: 0xEB79C6B5 (dec: -344340811)
{
	struct _Instance *instance; // size=616, offset=0
	struct _SFXMkr *sfxMarker;  // size=36, offset=0
};

struct COLLIDE_249fake // hashcode: 0xF5AEF652 (dec: -173083054)
{
	long instanceNumber; // size=0, offset=0 //  hashcode: 0xC4D960CC (dec: -992386868), parent name: 'COLLIDE_249fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;		 // size=0, offset=4 //  hashcode: 0xE0D39819 (dec: -523003879), parent name: 'COLLIDE_249fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_250fake // hashcode: 0xA666CB03 (dec: -1503212797)
{
	struct _SavedIntro *intro; // size=40, offset=0 //  hashcode: 0xE4050494 (dec: -469433196), parent name: 'COLLIDE_250fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;			   // size=0, offset=4 //  hashcode: 0x503D1CE3 (dec: 1346182371), parent name: 'COLLIDE_250fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_251fake // hashcode: 0x9BCCEB85 (dec: -1681069179)
{
	long currentNumber; // size=0, offset=0 //  hashcode: 0xF68AEC44 (dec: -158667708), parent name: 'COLLIDE_251fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long error;			// size=0, offset=4 //  hashcode: 0x3E0BF407 (dec: 1040970759), parent name: 'COLLIDE_251fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;		// size=0, offset=8 //  hashcode: 0x681BFC25 (dec: 1746664485), parent name: 'COLLIDE_251fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_252fake // hashcode: 0x8257F8A2 (dec: -2108163934)
{
	short vx; // size=0, offset=0 //  hashcode: 0x50EE5706 (dec: 1357797126), parent name: 'COLLIDE_252fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vy; // size=0, offset=2 //  hashcode: 0x5462AF5A (dec: 1415753562), parent name: 'COLLIDE_252fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_253fake // hashcode: 0x19C0F303 (dec: 432075523)
{
	char *pointer; // size=0, offset=0 //  hashcode: 0xE70EE499 (dec: -418454375), parent name: 'COLLIDE_253fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_254fake // hashcode: 0x3025466A (dec: 807749226)
{
	short *pointer; // size=0, offset=0 //  hashcode: 0x00615121 (dec: 6377761), parent name: 'COLLIDE_254fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_255fake // hashcode: 0x42CA9781 (dec: 1120573313)
{
	long *pointer; // size=0, offset=0 //  hashcode: 0x37B13D05 (dec: 934362373), parent name: 'COLLIDE_255fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union COLLIDE_256fake // Hashcode: 0xFABF6FA9 (dec: -88117335)
{
	struct COLLIDE_249fake Object;					  // size=8, offset=0
	struct COLLIDE_250fake SavedIntroObject;		  // size=8, offset=0
	struct InstanceSpline instanceSpline;			  // size=24, offset=0
	struct COLLIDE_251fake Number;					  // size=12, offset=0
	struct COLLIDE_252fake Vector2d;				  // size=4, offset=0
	struct COLLIDE_253fake CharPointer;				  // size=4, offset=0
	struct COLLIDE_254fake ShortPointer;			  // size=4, offset=0
	struct COLLIDE_255fake LongPointer;				  // size=4, offset=0
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

struct PandTScratch // hashcode: 0x53B2A743 (dec: 1404217155)
{
	struct MATRIX posMatrix;	 // size=32, offset=0 //  hashcode: 0x8C350B22 (dec: -1942680798), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector normal;		 // size=8, offset=32 //  hashcode: 0x6E267F4D (dec: 1848016717), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Vector dpv;			 // size=12, offset=40 //  hashcode: 0xB179CDE0 (dec: -1317417504), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector planePoint;  // size=8, offset=52 //  hashcode: 0x18AA988E (dec: 413833358), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long ignore_attr;			 // size=0, offset=60 //  hashcode: 0x4F4C3D07 (dec: 1330396423), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long accept_attr;			 // size=0, offset=64 //  hashcode: 0xED17D621 (dec: -317204959), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *backface_flag;		 // size=0, offset=68 //  hashcode: 0x0C51722D (dec: 206664237), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector newPos;		 // size=8, offset=72 //  hashcode: 0x8A99126F (dec: -1969679761), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldPos;		 // size=8, offset=80 //  hashcode: 0x0B5FA92D (dec: 190818605), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	int flags;					 // size=0, offset=88 //  hashcode: 0x9201D9FF (dec: -1845372417), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	int i;						 // size=0, offset=92 //  hashcode: 0xFCAFC877 (dec: -55588745), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	int slack;					 // size=0, offset=96 //  hashcode: 0x45CE9B94 (dec: 1171168148), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long in_spectral;			 // size=0, offset=100 //  hashcode: 0xFB76AC25 (dec: -76108763), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *normalList;			 // size=0, offset=104 //  hashcode: 0x9E4ABD00 (dec: -1639269120), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TVertex *vertexList; // size=12, offset=108 //  hashcode: 0x4AC836C4 (dec: 1254635204), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *result;		 // size=12, offset=112 //  hashcode: 0x451FB795 (dec: 1159706517), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector line;		 // size=8, offset=116 //  hashcode: 0x48684373 (dec: 1214792563), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct COLLIDE_258fake // hashcode: 0x1D802093 (dec: 494936211)
{
	long m[3]; // size=12, offset=0 //  hashcode: 0x6B2A73AE (dec: 1797944238), parent name: 'COLLIDE_258fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SandHFScratch // hashcode: 0x31C4E20D (dec: 834986509)
{
	struct _SVector normal;		// size=8, offset=0 //  hashcode: 0x4831F9FE (dec: 1211234814), parent name: 'SandHFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX posMatrix;	// size=32, offset=8 //  hashcode: 0x9DEEB877 (dec: -1645299593), parent name: 'SandHFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Vector dpv;			// size=12, offset=40 //  hashcode: 0x44002FB1 (dec: 1140862897), parent name: 'SandHFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector triPoint;   // size=8, offset=52 //  hashcode: 0xB292B371 (dec: -1299008655), parent name: 'SandHFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector planePoint; // size=8, offset=60 //  hashcode: 0xF1325F0A (dec: -248357110), parent name: 'SandHFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SandTScratch // hashcode: 0x2773448F (dec: 661865615)
{
	struct MATRIX posMatrix;		 // size=32, offset=0 //  hashcode: 0xBECEA753 (dec: -1093753005), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Vector dpv;				 // size=12, offset=32 //  hashcode: 0x010E5E0D (dec: 17718797), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HNormal *normalList;	 // size=8, offset=44 //  hashcode: 0x5A1CC228 (dec: 1511834152), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _CollideInfo collideInfo; // size=48, offset=48 //  hashcode: 0xBAF074DC (dec: -1158646564), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HFaceInfo hfaceInfo;	 // size=32, offset=96 //  hashcode: 0x4C91B874 (dec: 1284618356), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector midPoint;		 // size=8, offset=128 //  hashcode: 0x62D6F482 (dec: 1658254466), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector spherePos;		 // size=8, offset=136 //  hashcode: 0x1568ACF1 (dec: 359181553), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*collideFunc)();			 // size=0, offset=144 //  hashcode: 0x9B900165 (dec: -1685061275), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance;		 // size=616, offset=148 //  hashcode: 0x104D52FB (dec: 273502971), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long edge;						 // size=0, offset=152 //  hashcode: 0xEC088E14 (dec: -334983660), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long in_spectral;				 // size=0, offset=156 //  hashcode: 0xFE050F7C (dec: -33222788), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldPos;			 // size=8, offset=160 //  hashcode: 0xAD81F149 (dec: -1383993015), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *prim;						 // size=0, offset=168 //  hashcode: 0x9F44C239 (dec: -1622883783), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector normal;			 // size=8, offset=172 //  hashcode: 0x614F2EFC (dec: 1632579324), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Sphere sphere;			 // size=12, offset=180 //  hashcode: 0x640A6BF9 (dec: 1678404601), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	short result;					 // size=0, offset=192 //  hashcode: 0x788973E3 (dec: 2022274019), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	short i;						 // size=0, offset=194 //  hashcode: 0xD1EA771A (dec: -773163238), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long collide_ignoreAttr;		 // size=0, offset=196 //  hashcode: 0x3E097826 (dec: 1040807974), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long collide_acceptAttr;		 // size=0, offset=200 //  hashcode: 0x958585B9 (dec: -1786411591), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long midRadius;					 // size=0, offset=204 //  hashcode: 0xBE5016E4 (dec: -1102047516), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TVertex *vertexList;	 // size=12, offset=208 //  hashcode: 0xE4499D4E (dec: -464937650), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct IandTScratch // hashcode: 0xE0F1425D (dec: -521059747)
{
	struct MATRIX posMatrix;	 // size=32, offset=0 //  hashcode: 0x51AC1CC1 (dec: 1370234049), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector normal;		 // size=8, offset=32 //  hashcode: 0x62A578B4 (dec: 1655011508), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Vector dpv;			 // size=12, offset=40 //  hashcode: 0xCBB7C3EF (dec: -877149201), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector planePoint;  // size=8, offset=52 //  hashcode: 0xA1C874EB (dec: -1580698389), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector line;		 // size=8, offset=60 //  hashcode: 0xC3A2604B (dec: -1012768693), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldPos;		 // size=8, offset=68 //  hashcode: 0x026F3513 (dec: 40842515), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector newPos;		 // size=8, offset=76 //  hashcode: 0x21C78495 (dec: 566723733), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	int i;						 // size=0, offset=84 //  hashcode: 0xCC934323 (dec: -862764253), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long in_spectral;			 // size=0, offset=88 //  hashcode: 0x6ADD46B6 (dec: 1792886454), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *normalList;			 // size=0, offset=92 //  hashcode: 0xE9701432 (dec: -378530766), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TVertex *vertexList; // size=12, offset=96 //  hashcode: 0x288A03AE (dec: 680133550), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PandTFScratch // hashcode: 0x218F0B73 (dec: 563022707)
{
	struct MATRIX posMatrix;	// size=32, offset=0 //  hashcode: 0x672A99DB (dec: 1730845147), parent name: 'PandTFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector planePoint; // size=8, offset=32 //  hashcode: 0xCE5A1EC4 (dec: -832954684), parent name: 'PandTFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector newPos;		// size=8, offset=40 //  hashcode: 0x8115F2B2 (dec: -2129268046), parent name: 'PandTFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldPos;		// size=8, offset=48 //  hashcode: 0x0C68B577 (dec: 208188791), parent name: 'PandTFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector normal;		// size=8, offset=56 //  hashcode: 0x4495546B (dec: 1150637163), parent name: 'PandTFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Vector dpv;			// size=12, offset=64 //  hashcode: 0x5FC1DAB7 (dec: 1606539959), parent name: 'PandTFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct _Vector Vector;

typedef struct _Triangle2D Triangle2D;

typedef struct _PCollideInfo PCollideInfo;

typedef struct _HNormal HNormal;

typedef struct _HFaceInfo HFaceInfo;

typedef struct _CollideInfo CollideInfo;

typedef struct _LCollideInfo LCollideInfo;

typedef struct SCollideInfo SCollideInfo;

typedef long CollideBoundFunc();

extern int COLLIDE_PointInTriangle(struct _SVector *v0, struct _SVector *v1, struct _SVector *v2, struct _SVector *point, struct _SVector *normal); // 0x8001E460

extern int COLLIDE_PointInTriangle2DPub(short *v0, short *v1, short *v2, short *point); // 0x8001E704

extern long COLLIDE_GetNormal(short nNum, short *nrmlArray, struct _SVector *nrml); // 0x8001E750

extern void COLLIDE_MakeNormal(struct _Terrain *terrain, struct _TFace *tface, struct _SVector *normal); // 0x8001E7E8

extern void COLLIDE_UpdateAllTransforms(struct _Instance *instance, struct SVECTOR *offset); // 0x8001E9C0

extern void COLLIDE_MoveAllTransforms(struct _Instance *instance, struct _Position *offset); // 0x8001EA90

extern long COLLIDE_WithinYZBounds(struct _SVector *point, struct _HBox *hbox); // 0x8001EB60

extern long COLLIDE_WithinXZBounds(struct _SVector *point, struct _HBox *hbox); // 0x8001EBBC

extern long COLLIDE_WithinXYBounds(struct _SVector *point, struct _HBox *hbox); // 0x8001EC18

extern void COLLIDE_LineWithBoxFace(short startDist, long lineDist, short planeDist, struct _SVector *start, struct _Vector *line, struct _HBox *hbox, TDRFuncPtr_COLLIDE_LineWithBoxFace6collideBoundFunc collideBoundFunc, struct _SVector *normal); // 0x8001EC74

extern long COLLIDE_IntersectLineAndBox(struct _SVector *point0, struct _SVector *normal0, struct _SVector *point1, struct _SVector *normal1, struct _SVector *end, struct _SVector *start, struct _HBox *hbox); // 0x8001EE20

extern struct _TFace *COLLIDE_PointAndTerrain(struct _Terrain *terrain, struct _PCollideInfo *pcollideInfo, struct _LCollideInfo *lcol); // 0x8001F09C

extern struct _TFace *COLLIDE_PointAndTerrainFunc(struct _Terrain *terrain, struct _PCollideInfo *pCollideInfo, int Flags, short *Backface_Flag, long ignoreAttr, long acceptAttr, struct _LCollideInfo *lcolinfo); // 0x8001F0CC

extern int COLLIDE_PointAndHFace(struct _SVector *newPos, struct _SVector *oldPos, struct _HFace *hface, struct _Model *model, struct _SVector *hfNormal); // 0x8001FC64

extern void COLLIDE_PointAndInstance(struct _PCollideInfo *pcollideInfo, struct _Instance *instance); // 0x8001FEAC

extern void COLLIDE_PointAndInstanceTrivialReject(struct _PCollideInfo *pcollideInfo, struct _Instance *instance); // 0x800206E0

extern void COLLIDE_PointAndWorld(struct _PCollideInfo *pcollideInfo, struct Level *level); // 0x80020864

extern long COLLIDE_ClosestPointInBoxToPoint(struct _Position *boxPoint, struct _HBox *hbox, struct _SVector *point); // 0x80020C4C

extern long COLLIDE_SphereAndPoint(struct _Sphere *sphere, struct _SVector *point, struct _SVector *normal); // 0x80020D20

extern long COLLIDE_SphereAndHBox(struct _HBox *hbox, struct _Sphere *sphere, struct _Position *oldPos, struct _SVector *normal); // 0x80020F64

extern void COLLIDE_Instance1SpheresToInstance2(struct _Instance *instance1, struct _Instance *instance2, long sphereToSphere); // 0x800213DC

extern void COLLIDE_Instances(struct _Instance *instance1, struct _Instance *instance2); // 0x8002212C

extern void COLLIDE_InstanceList(struct _InstanceList *instanceList); // 0x80022274

extern long COLLIDE_SphereAndHFace(struct _Sphere *sphere, struct _Position *oldPos, struct _HFaceInfo *hfaceInfo, struct _SVector *intersect, long *edge); // 0x8002251C

extern long COLLIDE_SAndT(struct SCollideInfo *scollideInfo, struct Level *level); // 0x80022BF8

extern long COLLIDE_SphereAndTerrain(struct SCollideInfo *scollideInfo, struct Level *level); // 0x800236E4

extern void COLLIDE_InstanceTerrain(struct _Instance *instance, struct Level *level); // 0x800237CC

extern long COLLIDE_LineWithSignals(struct _SVector *startPoint, struct _SVector *endPoint, struct _MultiSignal **signalList, long maxSignals, struct Level *level); // 0x80023A38

extern void COLLIDE_InstanceTerrainSignal(struct _Instance *instance, struct Level *level); // 0x800241FC

extern struct _StreamUnit *COLLIDE_CameraWithStreamSignals(struct Camera *camera); // 0x80024444

extern void COLLIDE_InstanceListWithSignals(struct _InstanceList *instanceList); // 0x8002472C

extern void COLLIDE_InstanceListTerrain(struct _InstanceList *instanceList); // 0x800247A0

extern void COLLIDE_SegmentCollisionOn(struct _Instance *instance, int segment); // 0x80024850

extern void COLLIDE_SegmentCollisionOff(struct _Instance *instance, int segment); // 0x800248C8

extern long COLLIDE_FindCollisionFaceNormal(struct _CollideInfo *collideInfo, struct _Normal *normal); // 0x80024964

extern short *COLLIDE_GetBSPTreeFlag(struct _CollideInfo *collideInfo); // 0x80024AA0

extern void COLLIDE_SetBSPTreeFlag(struct _CollideInfo *collideInfo, short flag); // 0x80024AC8

extern int COLLIDE_PointAndTfaceFunc(struct _Terrain *terrain, struct BSPTree *bsp, struct _SVector *orgNewPos, struct _SVector *orgOldPos, struct _TFace *tface, long ignoreAttr, long flags); // 0x80024AFC

typedef long (*TDRFuncPtr_COLLIDE_LineWithBoxFace6collideBoundFunc)();

#endif
