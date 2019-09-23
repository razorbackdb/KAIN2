#ifndef MISSILE_H
#define MISSILE_H

static struct MissileGraphics MISSILE_objectTable[4]; // offset 0x800CA9C0

struct MISSILE_73fake // hashcode: 0xF258C925 (dec: -229062363)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x88CC209C (dec: -1999888228), parent name: 'MISSILE_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x43CE4518 (dec: 1137591576), parent name: 'MISSILE_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_74fake // hashcode: 0xF14EBB8A (dec: -246498422)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xEFA30A5A (dec: -274527654), parent name: 'MISSILE_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x2E4A2AAA (dec: 776612522), parent name: 'MISSILE_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_75fake // hashcode: 0x2F8201B6 (dec: 797049270)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x3C1C9DF9 (dec: 1008508409), parent name: 'MISSILE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xC657473C (dec: -967358660), parent name: 'MISSILE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MISSILE_76fake // Hashcode: 0x770AB642 (dec: 1997190722)
{
	struct MISSILE_73fake callback; // size=8, offset=0
	struct MISSILE_74fake vector;   // size=12, offset=0
	struct MISSILE_75fake quat;		// size=16, offset=0
};

union MISSILE_77fake // Hashcode: 0x00D3FAB3 (dec: 13892275)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MISSILE_78fake // Hashcode: 0x826B4A56 (dec: -2106897834)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct MISSILE_79fake // hashcode: 0x90533C8B (dec: -1873593205)
{
	union MISSILE_78fake size; // size=4, offset=0 //  hashcode: 0xE589E0AC (dec: -443948884), parent name: 'MISSILE_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_80fake // hashcode: 0xE2468F8C (dec: -498692212)
{
	short x;				// size=0, offset=0 //  hashcode: 0xC77E0FD4 (dec: -948039724), parent name: 'MISSILE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xE247F2E7 (dec: -498601241), parent name: 'MISSILE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xDED512FE (dec: -556461314), parent name: 'MISSILE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xB46509BF (dec: -1268446785), parent name: 'MISSILE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x775A77FD (dec: 2002417661), parent name: 'MISSILE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_81fake // hashcode: 0x6522838D (dec: 1696760717)
{
	long index; // size=0, offset=0 //  hashcode: 0xCBDB3833 (dec: -874825677), parent name: 'MISSILE_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xDE101D84 (dec: -569369212), parent name: 'MISSILE_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_82fake // hashcode: 0xBF3F30A0 (dec: -1086377824)
{
	long index; // size=0, offset=0 //  hashcode: 0xE6060E41 (dec: -435810751), parent name: 'MISSILE_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x7FC0D7FF (dec: 2143344639), parent name: 'MISSILE_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_83fake // hashcode: 0xBEE52A98 (dec: -1092277608)
{
	long index; // size=0, offset=0 //  hashcode: 0x3264EB72 (dec: 845474674), parent name: 'MISSILE_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x69202112 (dec: 1763713298), parent name: 'MISSILE_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_84fake // hashcode: 0x87861290 (dec: -2021256560)
{
	long time;  // size=0, offset=0 //  hashcode: 0xA5D951B7 (dec: -1512484425), parent name: 'MISSILE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x8A41DE4C (dec: -1975394740), parent name: 'MISSILE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_85fake // hashcode: 0x1B19185B (dec: 454629467)
{
	long action;   // size=0, offset=0 //  hashcode: 0xD53F2A12 (dec: -717280750), parent name: 'MISSILE_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xEF23696E (dec: -282891922), parent name: 'MISSILE_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_86fake // hashcode: 0x0AB872A4 (dec: 179860132)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xB0291AE3 (dec: -1339483421), parent name: 'MISSILE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x343DC9EE (dec: 876464622), parent name: 'MISSILE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_87fake // hashcode: 0xE6BE63D1 (dec: -423730223)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xD1252F09 (dec: -786092279), parent name: 'MISSILE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0xF0EBF575 (dec: -252971659), parent name: 'MISSILE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_88fake // hashcode: 0x7D0B10E7 (dec: 2097877223)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x2474FDF7 (dec: 611646967), parent name: 'MISSILE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x22865C54 (dec: 579230804), parent name: 'MISSILE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_89fake // hashcode: 0x563C308F (dec: 1446785167)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x6268568D (dec: 1651005069), parent name: 'MISSILE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xFE1B15CE (dec: -31779378), parent name: 'MISSILE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x0742C11F (dec: 121815327), parent name: 'MISSILE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x97CDE234 (dec: -1748114892), parent name: 'MISSILE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xB76E709B (dec: -1217498981), parent name: 'MISSILE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_90fake // hashcode: 0xAD28776F (dec: -1389856913)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xF3F86AE1 (dec: -201823519), parent name: 'MISSILE_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x7CBCDAF6 (dec: 2092751606), parent name: 'MISSILE_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_91fake // hashcode: 0x32DBB468 (dec: 853259368)
{
	short index;					// size=0, offset=0 //  hashcode: 0x9AF6318C (dec: -1695141492), parent name: 'MISSILE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x38DB8118 (dec: 953909528), parent name: 'MISSILE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x8DD2DB7A (dec: -1915561094), parent name: 'MISSILE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x75D62EFA (dec: 1976971002), parent name: 'MISSILE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_92fake // hashcode: 0xACFDCE33 (dec: -1392652749)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x28E03073 (dec: 685781107), parent name: 'MISSILE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xE5288323 (dec: -450329821), parent name: 'MISSILE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xE6B6121E (dec: -424275426), parent name: 'MISSILE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_93fake // hashcode: 0xDF35CC1B (dec: -550122469)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x5D89AA24 (dec: 1569303076), parent name: 'MISSILE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x4A5B1EC1 (dec: 1247485633), parent name: 'MISSILE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x3F51CBD8 (dec: 1062325208), parent name: 'MISSILE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x962A0618 (dec: -1775630824), parent name: 'MISSILE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x250F573E (dec: 621762366), parent name: 'MISSILE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xDD865636 (dec: -578398666), parent name: 'MISSILE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x6C602A4E (dec: 1818241614), parent name: 'MISSILE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_94fake // hashcode: 0x28B5DF5A (dec: 683007834)
{
	long index;  // size=0, offset=0 //  hashcode: 0xC9348920 (dec: -919303904), parent name: 'MISSILE_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x2612D8FE (dec: 638769406), parent name: 'MISSILE_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_95fake // hashcode: 0xA2544042 (dec: -1571536830)
{
	short type; // size=0, offset=0 //  hashcode: 0x8572C7C5 (dec: -2056075323), parent name: 'MISSILE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xD53F2193 (dec: -717282925), parent name: 'MISSILE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_96fake // hashcode: 0x186AF653 (dec: 409663059)
{
	long time;   // size=0, offset=0 //  hashcode: 0xAF72630A (dec: -1351458038), parent name: 'MISSILE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x9AECE02F (dec: -1695752145), parent name: 'MISSILE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_97fake // hashcode: 0x5D703AD2 (dec: 1567636178)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x8998AC08 (dec: -1986483192), parent name: 'MISSILE_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x7D6DCBE9 (dec: 2104347625), parent name: 'MISSILE_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_98fake // hashcode: 0x4E0398CC (dec: 1308858572)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xD78F97FC (dec: -678455300), parent name: 'MISSILE_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xC2ED1434 (dec: -1024650188), parent name: 'MISSILE_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_99fake // hashcode: 0x0EF0C7F6 (dec: 250660854)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xA09B6644 (dec: -1600428476), parent name: 'MISSILE_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x271A3C61 (dec: 656030817), parent name: 'MISSILE_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_100fake // hashcode: 0x8CE2E36F (dec: -1931287697)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x0E4D5485 (dec: 239948933), parent name: 'MISSILE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x9851E10A (dec: -1739464438), parent name: 'MISSILE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x9545093B (dec: -1790637765), parent name: 'MISSILE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x6225C4F9 (dec: 1646642425), parent name: 'MISSILE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_101fake // hashcode: 0xBB4227E0 (dec: -1153292320)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x006DE2D8 (dec: 7201496), parent name: 'MISSILE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x8AC6E385 (dec: -1966677115), parent name: 'MISSILE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xEE6D60FE (dec: -294821634), parent name: 'MISSILE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xD736FE87 (dec: -684261753), parent name: 'MISSILE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x2E1750DB (dec: 773279963), parent name: 'MISSILE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MISSILE_102fake // Hashcode: 0xDCEFF34F (dec: -588254385)
{
	struct MISSILE_79fake misc[3];		// size=12, offset=0
	struct _CameraKey *cameraKey;		// size=24, offset=0
	struct MISSILE_80fake teleport;		// size=16, offset=0
	struct MISSILE_81fake cameraValue;  // size=8, offset=0
	struct MISSILE_82fake miscValue;	// size=8, offset=0
	struct MISSILE_83fake logicValue;   // size=8, offset=0
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
	struct MISSILE_84fake cameraShake;  // size=8, offset=0
	long cameraSave;					// size=0, offset=0
	long cameraRestore;					// size=0, offset=0
	struct _BGObject *bgObject;			// size=24, offset=0
	long value[2];						// size=8, offset=0
	struct MISSILE_85fake sound;		// size=12, offset=0
	void *intro;						// size=0, offset=0
	long deathZ;						// size=0, offset=0
	struct MISSILE_86fake dsignal;		// size=8, offset=0
	void *mirror;						// size=0, offset=0
	long fogNear;						// size=0, offset=0
	long fogFar;						// size=0, offset=0
	struct MISSILE_87fake gotoFrame;	// size=8, offset=0
	struct MISSILE_88fake changeModel;  // size=8, offset=0
	void *vmObject;						// size=0, offset=0
	struct MISSILE_89fake logic;		// size=8, offset=0
	void *callSignal;					// size=0, offset=0
	struct _SVector offset;				// size=8, offset=0
	struct Signal *gotoLabel;			// size=0, offset=0
	struct Signal *gosubLabel;			// size=0, offset=0
	struct MISSILE_90fake control;		// size=8, offset=0
	struct MISSILE_91fake zSignal;		// size=12, offset=0
	struct MISSILE_92fake StreamLevel;  // size=24, offset=0
	struct MISSILE_93fake shards;		// size=12, offset=0
	struct MISSILE_94fake cameraSpline; // size=8, offset=0
	struct MISSILE_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;					// size=0, offset=0
	struct MISSILE_96fake introFX;		// size=8, offset=0
	struct MISSILE_97fake introActive;  // size=8, offset=0
	struct MISSILE_98fake levelChange;  // size=18, offset=0
	long blendStart;					// size=0, offset=0
	struct MISSILE_99fake setTimes;		// size=8, offset=0
	struct MISSILE_100fake color;		// size=4, offset=0
	struct MISSILE_101fake print;		// size=12, offset=0
	long slideAngle;					// size=0, offset=0
};

union MISSILE_103fake // Hashcode: 0x73AF3911 (dec: 1940863249)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union MISSILE_108fake // Hashcode: 0xDC421032 (dec: -599650254)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct MISSILE_110fake // hashcode: 0x1CE2B869 (dec: 484620393)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x23DB3428 (dec: 601568296), parent name: 'MISSILE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x50A0387D (dec: 1352677501), parent name: 'MISSILE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0xFA4A8B9B (dec: -95777893), parent name: 'MISSILE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x8364EB61 (dec: -2090538143), parent name: 'MISSILE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0xFE2973C9 (dec: -30837815), parent name: 'MISSILE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x7A216373 (dec: 2049008499), parent name: 'MISSILE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xB9B74241 (dec: -1179172287), parent name: 'MISSILE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_111fake // hashcode: 0xC45DB7F8 (dec: -1000491016)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x9772E9A6 (dec: -1754076762), parent name: 'MISSILE_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xB11F1458 (dec: -1323363240), parent name: 'MISSILE_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xAA91AF1D (dec: -1433293027), parent name: 'MISSILE_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_112fake // hashcode: 0x1683FB40 (dec: 377748288)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x6DF5B85A (dec: 1844820058), parent name: 'MISSILE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x851558A4 (dec: -2062198620), parent name: 'MISSILE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xCB318733 (dec: -885946573), parent name: 'MISSILE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xE22456A8 (dec: -500935000), parent name: 'MISSILE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x8A946F8E (dec: -1969983602), parent name: 'MISSILE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_113fake // hashcode: 0x53335506 (dec: 1395873030)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x576A99CA (dec: 1466603978), parent name: 'MISSILE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x75ECD93D (dec: 1978456381), parent name: 'MISSILE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x0D501CF3 (dec: 223354099), parent name: 'MISSILE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x0812D6BC (dec: 135452348), parent name: 'MISSILE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xBBB493D7 (dec: -1145793577), parent name: 'MISSILE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_114fake // hashcode: 0xA1EFD7AB (dec: -1578117205)
{
	struct MISSILE_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x784FE02E (dec: 2018500654), parent name: 'MISSILE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MISSILE_111fake Idle;	  // size=20, offset=28 //  hashcode: 0x69969CBA (dec: 1771478202), parent name: 'MISSILE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MISSILE_112fake Behind;	// size=28, offset=48 //  hashcode: 0x7FE0039E (dec: 2145387422), parent name: 'MISSILE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MISSILE_113fake Follow;	// size=20, offset=76 //  hashcode: 0x7F7A2905 (dec: 2138712325), parent name: 'MISSILE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MISSILE_196fake // Hashcode: 0xC6BB167F (dec: -960817537)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct MISSILE_236fake // hashcode: 0x07630C38 (dec: 123931704)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x61EA5D1A (dec: 1642749210), parent name: 'MISSILE_236fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0xDED3F2A5 (dec: -556535131), parent name: 'MISSILE_236fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MISSILE_237fake // hashcode: 0xD1E1A81E (dec: -773740514)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0xB6A7BE6A (dec: -1230520726), parent name: 'MISSILE_237fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x30C088E0 (dec: 817924320), parent name: 'MISSILE_237fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x762FC3DD (dec: 1982841821), parent name: 'MISSILE_237fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0xD22C9494 (dec: -768830316), parent name: 'MISSILE_237fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0xB0B91A94 (dec: -1330046316), parent name: 'MISSILE_237fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x9AFADEEB (dec: -1694834965), parent name: 'MISSILE_237fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MISSILE_238fake // Hashcode: 0x9FC824FD (dec: -1614273283)
{
	struct MISSILE_236fake flame; // size=8, offset=0
	struct MISSILE_237fake phys;  // size=12, offset=0
};

struct MissileGraphics // hashcode: 0xD28383EB (dec: -763132949)
{
	unsigned char object; // size=0, offset=0 //  hashcode: 0xA8A63A16 (dec: -1465501162), parent name: 'MissileGraphics', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char model;  // size=0, offset=1 //  hashcode: 0xE9D5230B (dec: -371907829), parent name: 'MissileGraphics', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct MissileGraphics MissileGraphics;

extern void MISSILE_Process(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007D7BC

extern void MISSILE_Collide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007D814

extern struct _Instance *MISSILE_Find(struct _Instance *instance, struct _MonsterMissile *missiledef); // 0x8007D850

extern struct _Instance *MISSILE_Birth(struct _Instance *instance, struct _MonsterMissile *missiledef); // 0x8007D8CC

extern struct _Instance *MISSILE_Fire(struct _Instance *instance, struct _MonsterMissile *missiledef, void *target, int type); // 0x8007D9A0

extern struct _Instance *MISSILE_FireAtInstance(struct _Instance *instance, struct _MonsterMissile *missiledef, struct _Instance *target); // 0x8007DA60

#endif
