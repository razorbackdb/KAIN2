#ifndef MATH3D_H
#define MATH3D_H

extern short identityMatrix[3][3]; // offset 0x800CE870

struct MATH3D_73fake // hashcode: 0x157AD254 (dec: 360370772)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x325BF374 (dec: 844886900), parent name: 'MATH3D_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0xD981D7EE (dec: -645802002), parent name: 'MATH3D_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_74fake // hashcode: 0xC3F19EF7 (dec: -1007575305)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x5AD72230 (dec: 1524048432), parent name: 'MATH3D_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xE72B3C72 (dec: -416596878), parent name: 'MATH3D_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_75fake // hashcode: 0xE8868798 (dec: -393836648)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xA9CEB08B (dec: -1446072181), parent name: 'MATH3D_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x3652B9DE (dec: 911391198), parent name: 'MATH3D_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MATH3D_76fake // Hashcode: 0x663290A4 (dec: 1714589860)
{
	struct MATH3D_73fake callback; // size=8, offset=0
	struct MATH3D_74fake vector;   // size=12, offset=0
	struct MATH3D_75fake quat;	 // size=16, offset=0
};

union MATH3D_77fake // Hashcode: 0xA8CF04EA (dec: -1462827798)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MATH3D_78fake // Hashcode: 0xCED6CB94 (dec: -824783980)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct MATH3D_79fake // hashcode: 0xBECD41AB (dec: -1093844565)
{
	union MATH3D_78fake size; // size=4, offset=0 //  hashcode: 0x093019C9 (dec: 154147273), parent name: 'MATH3D_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_80fake // hashcode: 0xC9108AB3 (dec: -921662797)
{
	short x;				// size=0, offset=0 //  hashcode: 0x804E728E (dec: -2142342514), parent name: 'MATH3D_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x2DCAE09D (dec: 768270493), parent name: 'MATH3D_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x26D8FFA4 (dec: 651755428), parent name: 'MATH3D_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x4C2B58C5 (dec: 1277909189), parent name: 'MATH3D_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x6BCD94DD (dec: 1808635101), parent name: 'MATH3D_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_81fake // hashcode: 0xD5F31593 (dec: -705489517)
{
	long index; // size=0, offset=0 //  hashcode: 0xFA78A35D (dec: -92757155), parent name: 'MATH3D_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xDA95B494 (dec: -627723116), parent name: 'MATH3D_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_82fake // hashcode: 0x4DF39F2C (dec: 1307811628)
{
	long index; // size=0, offset=0 //  hashcode: 0xF82309A7 (dec: -131921497), parent name: 'MATH3D_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xFCD56CF9 (dec: -53121799), parent name: 'MATH3D_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_83fake // hashcode: 0xF1F6714D (dec: -235507379)
{
	long index; // size=0, offset=0 //  hashcode: 0xA7BC6882 (dec: -1480824702), parent name: 'MATH3D_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xCE0C0E12 (dec: -838070766), parent name: 'MATH3D_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_84fake // hashcode: 0x95C21ECD (dec: -1782440243)
{
	long time;  // size=0, offset=0 //  hashcode: 0xC5D535E1 (dec: -975882783), parent name: 'MATH3D_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x33972B24 (dec: 865544996), parent name: 'MATH3D_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_85fake // hashcode: 0x0C4905E8 (dec: 206112232)
{
	long action;   // size=0, offset=0 //  hashcode: 0x310BF374 (dec: 822866804), parent name: 'MATH3D_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x41E72DEE (dec: 1105669614), parent name: 'MATH3D_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_86fake // hashcode: 0x027907E1 (dec: 41486305)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x513A3753 (dec: 1362769747), parent name: 'MATH3D_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x6E359200 (dec: 1849004544), parent name: 'MATH3D_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_87fake // hashcode: 0xF2291023 (dec: -232189917)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x41E468CD (dec: 1105488077), parent name: 'MATH3D_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x5E829455 (dec: 1585615957), parent name: 'MATH3D_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_88fake // hashcode: 0xFB59C28D (dec: -78003571)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x751E9167 (dec: 1964937575), parent name: 'MATH3D_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x180870D4 (dec: 403206356), parent name: 'MATH3D_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_89fake // hashcode: 0xB9F3F04A (dec: -1175195574)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xD15877BD (dec: -782731331), parent name: 'MATH3D_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x0B54E128 (dec: 190112040), parent name: 'MATH3D_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xA43AEF3F (dec: -1539641537), parent name: 'MATH3D_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x657611DE (dec: 1702236638), parent name: 'MATH3D_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x8214C7FB (dec: -2112567301), parent name: 'MATH3D_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_90fake // hashcode: 0xF1A04972 (dec: -241153678)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x44B73E07 (dec: 1152859655), parent name: 'MATH3D_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x3F0F1A4C (dec: 1057954380), parent name: 'MATH3D_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_91fake // hashcode: 0xFB2EABB5 (dec: -80827467)
{
	short index;					// size=0, offset=0 //  hashcode: 0x92460D1C (dec: -1840902884), parent name: 'MATH3D_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xB4087CAE (dec: -1274512210), parent name: 'MATH3D_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xA124BCF8 (dec: -1591427848), parent name: 'MATH3D_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xDD77E60A (dec: -579344886), parent name: 'MATH3D_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_92fake // hashcode: 0x1D282C1E (dec: 489171998)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x18CC9449 (dec: 416060489), parent name: 'MATH3D_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x813B8655 (dec: -2126805419), parent name: 'MATH3D_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x549C29FC (dec: 1419520508), parent name: 'MATH3D_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_93fake // hashcode: 0x87198647 (dec: -2028370361)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x7E5CD6EE (dec: 2120013550), parent name: 'MATH3D_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xE3BD47CD (dec: -474134579), parent name: 'MATH3D_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x28526032 (dec: 676487218), parent name: 'MATH3D_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x69207D58 (dec: 1763736920), parent name: 'MATH3D_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xA4D8E440 (dec: -1529289664), parent name: 'MATH3D_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xE0265EB0 (dec: -534356304), parent name: 'MATH3D_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x56BAEDAE (dec: 1455091118), parent name: 'MATH3D_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_94fake // hashcode: 0xF35D9B59 (dec: -211969191)
{
	long index;  // size=0, offset=0 //  hashcode: 0x4CB247EC (dec: 1286752236), parent name: 'MATH3D_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xC7B21838 (dec: -944629704), parent name: 'MATH3D_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_95fake // hashcode: 0x7DBEA461 (dec: 2109645921)
{
	short type; // size=0, offset=0 //  hashcode: 0xC9868BE5 (dec: -913929243), parent name: 'MATH3D_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xE3175E69 (dec: -485007767), parent name: 'MATH3D_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_96fake // hashcode: 0xDB3BB0E3 (dec: -616845085)
{
	long time;   // size=0, offset=0 //  hashcode: 0x27DCB78E (dec: 668776334), parent name: 'MATH3D_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xDD8DA70F (dec: -577919217), parent name: 'MATH3D_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_97fake // hashcode: 0xE06D74BC (dec: -529697604)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xD5804CA2 (dec: -713012062), parent name: 'MATH3D_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x5AE8BD89 (dec: 1525202313), parent name: 'MATH3D_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_98fake // hashcode: 0x2C7106D9 (dec: 745604825)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xEF59CA34 (dec: -279328204), parent name: 'MATH3D_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xFB00EE8C (dec: -83825012), parent name: 'MATH3D_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_99fake // hashcode: 0xCF791637 (dec: -814148041)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x7E027050 (dec: 2114089040), parent name: 'MATH3D_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x9BFBD3E1 (dec: -1677995039), parent name: 'MATH3D_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_100fake // hashcode: 0x425AC2ED (dec: 1113244397)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0xA809A37F (dec: -1475763329), parent name: 'MATH3D_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x6993DA36 (dec: 1771297334), parent name: 'MATH3D_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xF2E3C345 (dec: -219954363), parent name: 'MATH3D_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x8C61CCC9 (dec: -1939747639), parent name: 'MATH3D_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATH3D_101fake // hashcode: 0x05FEC1B3 (dec: 100581811)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x8024CC02 (dec: -2145072126), parent name: 'MATH3D_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xCA0109AB (dec: -905901653), parent name: 'MATH3D_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x2CC5EF0E (dec: 751169294), parent name: 'MATH3D_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x71714321 (dec: 1903248161), parent name: 'MATH3D_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xE08A9EA5 (dec: -527786331), parent name: 'MATH3D_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MATH3D_102fake // Hashcode: 0x5C62AA16 (dec: 1549969942)
{
	struct MATH3D_79fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	  // size=24, offset=0
	struct MATH3D_80fake teleport;	 // size=16, offset=0
	struct MATH3D_81fake cameraValue;  // size=8, offset=0
	struct MATH3D_82fake miscValue;	// size=8, offset=0
	struct MATH3D_83fake logicValue;   // size=8, offset=0
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
	struct MATH3D_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				   // size=0, offset=0
	long cameraRestore;				   // size=0, offset=0
	struct _BGObject *bgObject;		   // size=24, offset=0
	long value[2];					   // size=8, offset=0
	struct MATH3D_85fake sound;		   // size=12, offset=0
	void *intro;					   // size=0, offset=0
	long deathZ;					   // size=0, offset=0
	struct MATH3D_86fake dsignal;	  // size=8, offset=0
	void *mirror;					   // size=0, offset=0
	long fogNear;					   // size=0, offset=0
	long fogFar;					   // size=0, offset=0
	struct MATH3D_87fake gotoFrame;	// size=8, offset=0
	struct MATH3D_88fake changeModel;  // size=8, offset=0
	void *vmObject;					   // size=0, offset=0
	struct MATH3D_89fake logic;		   // size=8, offset=0
	void *callSignal;				   // size=0, offset=0
	struct _SVector offset;			   // size=8, offset=0
	struct Signal *gotoLabel;		   // size=0, offset=0
	struct Signal *gosubLabel;		   // size=0, offset=0
	struct MATH3D_90fake control;	  // size=8, offset=0
	struct MATH3D_91fake zSignal;	  // size=12, offset=0
	struct MATH3D_92fake StreamLevel;  // size=24, offset=0
	struct MATH3D_93fake shards;	   // size=12, offset=0
	struct MATH3D_94fake cameraSpline; // size=8, offset=0
	struct MATH3D_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				   // size=0, offset=0
	struct MATH3D_96fake introFX;	  // size=8, offset=0
	struct MATH3D_97fake introActive;  // size=8, offset=0
	struct MATH3D_98fake levelChange;  // size=18, offset=0
	long blendStart;				   // size=0, offset=0
	struct MATH3D_99fake setTimes;	 // size=8, offset=0
	struct MATH3D_100fake color;	   // size=4, offset=0
	struct MATH3D_101fake print;	   // size=12, offset=0
	long slideAngle;				   // size=0, offset=0
};

union MATH3D_103fake // Hashcode: 0xFCB443C0 (dec: -55295040)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union MATH3D_108fake // Hashcode: 0xCCA9B3AE (dec: -861293650)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

enum MATH3D_AXIS // Hashcode: 0x325251CF (dec: 844255695)
{
	AXIS_X = 0,
	AXIS_Y = 1,
	AXIS_Z = 2,
	AXIS_NEG_X = 3,
	AXIS_NEG_Y = 4,
	AXIS_NEG_Z = 5,
};

extern void MATH3D_Sort3VectorCoords(long *a, long *b, long *c); // 0x80039478

extern long MATH3D_LengthXYZ(long x, long y, long z); // 0x800394FC

extern long MATH3D_LengthXY(long x, long y); // 0x800395CC

extern void MATH3D_Normalize(struct _Normal *normal); // 0x8003962C

extern short MATH3D_FastAtan2(long y, long x); // 0x800396BC

extern long MATH3D_FastSqrt(long square); // 0x800397D8

extern long MATH3D_FastSqrt0(long square); // 0x800398B8

extern long MATH3D_DistanceBetweenPositions(struct _Position *pos1, struct _Position *pos2); // 0x80039948

extern short MATH3D_AngleBetweenVectors(struct _SVector *vector1, struct _SVector *vector2); // 0x80039994

extern void MATH3D_RotMatAboutVec(struct _SVector *vec, struct MATRIX *mat, short angle); // 0x80039A80

extern void MATH3D_SetUnityMatrix(struct MATRIX *mat); // 0x80039B50

extern void AngleMoveToward(short *current_ptr, short destination, short step); // 0x80039B6C

extern short AngleDiff(short current, short destination); // 0x80039C18

extern short MATH3D_AngleFromPosToPos(struct _Position *from, struct _Position *to); // 0x80039C3C

extern void MATH3D_ZYXtoXYZ(struct _Rotation *rot); // 0x80039C74

extern short MATH3D_ElevationFromPosToPos(struct _Position *from, struct _Position *to); // 0x80039CD0

extern void MATH3D_RotationFromPosToPos(struct _Position *from, struct _Position *to, struct _Rotation *rot); // 0x80039D54

extern int MATH3D_veclen2(int ix, int iy); // 0x80039DA8

extern void MATH3D_RotateAxisToVector(struct MATRIX *dest, struct MATRIX *src, struct _SVector *vec, enum MATH3D_AXIS axis); // 0x80039E08

extern int MATH3D_ConeDetect(struct _SVector *pos, int arc, int elevation); // 0x8003A060

extern void MATH3D_CrossProduct(struct _SVector *t, struct _SVector *r, struct _SVector *s); // 0x8003A118

extern unsigned long MATH3D_SquareLength(long x, long y, long z); // 0x8003A1BC

#endif
