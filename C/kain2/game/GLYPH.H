#ifndef GLYPH_H
#define GLYPH_H

static int blast_range; // offset 0x800D48CC

extern struct _FXBlastringEffect *fx_blastring; // offset 0x800CF5D0

static short fx_going; // offset 0x800CF5CC

static int fx_radius_old; // offset 0x800D48D0

static int glowdeg; // offset 0x800D48F8

static short glyph_cost; // offset 0x800D48C4

static short glyph_time; // offset 0x800D48C0

static short glyph_trigger; // offset 0x800D48C2

static struct _SVector HUD_Cap_Pos; // offset 0x800D48E4

static struct _SVector HUD_Cap_Vel; // offset 0x800D48EC

static short HUD_Captured; // offset 0x800CF5D4

static short HUD_Count; // offset 0x800D48C6

static short HUD_Count_Overall; // offset 0x800D48C8

static short HUD_Pos_vel; // offset 0x800D48DE

static short HUD_Position; // offset 0x800D48DC

static short HUD_Rot_vel; // offset 0x800D48DA

static short HUD_Rotation; // offset 0x800D48D8

static short HUD_State; // offset 0x800D48E0

static short HUD_Wait; // offset 0x800D48E2

static int MANNA_Pickup_Time; // offset 0x800D48D4

static short MANNA_Pos_vel; // offset 0x800D48BE

static short MANNA_Position; // offset 0x800D48BC

static int warpDraw; // offset 0x800D48F4

struct GLYPH_73fake // hashcode: 0xFAAF7054 (dec: -89165740)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x0C70E139 (dec: 208724281), parent name: 'GLYPH_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x95388C1B (dec: -1791456229), parent name: 'GLYPH_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_74fake // hashcode: 0xE731A0FF (dec: -416177921)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x2ADA1C62 (dec: 718937186), parent name: 'GLYPH_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x6FCB7F8B (dec: 1875607435), parent name: 'GLYPH_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_75fake // hashcode: 0x93B06107 (dec: -1817157369)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xD8D11E90 (dec: -657383792), parent name: 'GLYPH_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x77D34E4A (dec: 2010336842), parent name: 'GLYPH_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union GLYPH_76fake // Hashcode: 0xA7755406 (dec: -1485483002)
{
	struct GLYPH_73fake callback; // size=8, offset=0
	struct GLYPH_74fake vector;   // size=12, offset=0
	struct GLYPH_75fake quat;	 // size=16, offset=0
};

union GLYPH_77fake // Hashcode: 0x56F23318 (dec: 1458713368)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union GLYPH_78fake // Hashcode: 0x59EAC86D (dec: 1508558957)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct GLYPH_79fake // hashcode: 0xAE164FFA (dec: -1374269446)
{
	union GLYPH_78fake size; // size=4, offset=0 //  hashcode: 0xE8FE58F9 (dec: -385984263), parent name: 'GLYPH_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_80fake // hashcode: 0xB1C49DEC (dec: -1312514580)
{
	short x;				// size=0, offset=0 //  hashcode: 0xCF402B66 (dec: -817878170), parent name: 'GLYPH_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xF737EA6B (dec: -147330453), parent name: 'GLYPH_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x33E3536B (dec: 870536043), parent name: 'GLYPH_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x6317549F (dec: 1662473375), parent name: 'GLYPH_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xD77E007F (dec: -679608193), parent name: 'GLYPH_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_81fake // hashcode: 0xFF5326BA (dec: -11327814)
{
	long index; // size=0, offset=0 //  hashcode: 0xE427FFF7 (dec: -467140617), parent name: 'GLYPH_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x60DB9E79 (dec: 1625005689), parent name: 'GLYPH_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_82fake // hashcode: 0x4467771E (dec: 1147631390)
{
	long index; // size=0, offset=0 //  hashcode: 0xC9235A52 (dec: -920429998), parent name: 'GLYPH_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x31A855A6 (dec: 833115558), parent name: 'GLYPH_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_83fake // hashcode: 0x8DFC476E (dec: -1912846482)
{
	long index; // size=0, offset=0 //  hashcode: 0x987D802F (dec: -1736605649), parent name: 'GLYPH_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x0CD84BB8 (dec: 215501752), parent name: 'GLYPH_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_84fake // hashcode: 0x693C9932 (dec: 1765579058)
{
	long time;  // size=0, offset=0 //  hashcode: 0xFCF1C977 (dec: -51263113), parent name: 'GLYPH_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x7C0E4FA6 (dec: 2081312678), parent name: 'GLYPH_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_85fake // hashcode: 0xBB63438A (dec: -1151122550)
{
	long action;   // size=0, offset=0 //  hashcode: 0x9382F4B7 (dec: -1820134217), parent name: 'GLYPH_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x6980363F (dec: 1770010175), parent name: 'GLYPH_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_86fake // hashcode: 0x280DB807 (dec: 671987719)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xDB8178E1 (dec: -612271903), parent name: 'GLYPH_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x0076CF43 (dec: 7786307), parent name: 'GLYPH_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_87fake // hashcode: 0x38597239 (dec: 945386041)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x01B60C17 (dec: 28707863), parent name: 'GLYPH_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x4951E023 (dec: 1230102563), parent name: 'GLYPH_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_88fake // hashcode: 0xAB307BBB (dec: -1422885957)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x3431045F (dec: 875627615), parent name: 'GLYPH_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x4875A175 (dec: 1215668597), parent name: 'GLYPH_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_89fake // hashcode: 0x633F2E33 (dec: 1665084979)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x6CD55B67 (dec: 1825921895), parent name: 'GLYPH_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xDFA46120 (dec: -542875360), parent name: 'GLYPH_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x9A34D09D (dec: -1707814755), parent name: 'GLYPH_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xC7571E82 (dec: -950591870), parent name: 'GLYPH_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x05748CA4 (dec: 91524260), parent name: 'GLYPH_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_90fake // hashcode: 0x77DDAAB8 (dec: 2011015864)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x474D7DFC (dec: 1196260860), parent name: 'GLYPH_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x099F2E92 (dec: 161427090), parent name: 'GLYPH_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_91fake // hashcode: 0x7628B1A8 (dec: 1982378408)
{
	short index;					// size=0, offset=0 //  hashcode: 0x23E72A07 (dec: 602352135), parent name: 'GLYPH_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xC2BE917B (dec: -1027698309), parent name: 'GLYPH_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x16F38DC8 (dec: 385060296), parent name: 'GLYPH_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xC2D79F3B (dec: -1026056389), parent name: 'GLYPH_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_92fake // hashcode: 0xB932F68A (dec: -1187842422)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x518E2FA5 (dec: 1368272805), parent name: 'GLYPH_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x910A186F (dec: -1861609361), parent name: 'GLYPH_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xCA443E0D (dec: -901497331), parent name: 'GLYPH_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_93fake // hashcode: 0x4042F85E (dec: 1078130782)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x7201FD44 (dec: 1912732996), parent name: 'GLYPH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xB05165C7 (dec: -1336842809), parent name: 'GLYPH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x363B880C (dec: 909871116), parent name: 'GLYPH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xF4E82AA7 (dec: -186111321), parent name: 'GLYPH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xA7BF0933 (dec: -1480652493), parent name: 'GLYPH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x27031F79 (dec: 654516089), parent name: 'GLYPH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x10E8C0CD (dec: 283689165), parent name: 'GLYPH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_94fake // hashcode: 0xD6666511 (dec: -697932527)
{
	long index;  // size=0, offset=0 //  hashcode: 0x4BA8C8F6 (dec: 1269352694), parent name: 'GLYPH_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xD68459D2 (dec: -695969326), parent name: 'GLYPH_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_95fake // hashcode: 0x9DAD1C10 (dec: -1649599472)
{
	short type; // size=0, offset=0 //  hashcode: 0xBBECDAFF (dec: -1142105345), parent name: 'GLYPH_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xC022128C (dec: -1071508852), parent name: 'GLYPH_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_96fake // hashcode: 0x9A687994 (dec: -1704429164)
{
	long time;   // size=0, offset=0 //  hashcode: 0x767C0289 (dec: 1987838601), parent name: 'GLYPH_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x59406F79 (dec: 1497395065), parent name: 'GLYPH_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_97fake // hashcode: 0xC90FFEC3 (dec: -921698621)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xC5ECFCDF (dec: -974324513), parent name: 'GLYPH_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xBF842907 (dec: -1081857785), parent name: 'GLYPH_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_98fake // hashcode: 0x666D2234 (dec: 1718428212)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xF6C521EA (dec: -154852886), parent name: 'GLYPH_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x941F4D8C (dec: -1809887860), parent name: 'GLYPH_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_99fake // hashcode: 0x509CFBF6 (dec: 1352465398)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x128F29F7 (dec: 311372279), parent name: 'GLYPH_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x6A15D79B (dec: 1779816347), parent name: 'GLYPH_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_100fake // hashcode: 0x5925217F (dec: 1495605631)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0xD08463A7 (dec: -796630105), parent name: 'GLYPH_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xE2BF1254 (dec: -490794412), parent name: 'GLYPH_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x48F64731 (dec: 1224099633), parent name: 'GLYPH_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x1B92EB7C (dec: 462613372), parent name: 'GLYPH_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_101fake // hashcode: 0xB7E28D6F (dec: -1209889425)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x5D3D9AA7 (dec: 1564318375), parent name: 'GLYPH_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x8F54F415 (dec: -1890257899), parent name: 'GLYPH_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xD0507623 (dec: -800033245), parent name: 'GLYPH_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xC5018242 (dec: -989756862), parent name: 'GLYPH_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x147B6FD9 (dec: 343633881), parent name: 'GLYPH_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union GLYPH_102fake // Hashcode: 0x2E66B38E (dec: 778482574)
{
	struct GLYPH_79fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	 // size=24, offset=0
	struct GLYPH_80fake teleport;	 // size=16, offset=0
	struct GLYPH_81fake cameraValue;  // size=8, offset=0
	struct GLYPH_82fake miscValue;	// size=8, offset=0
	struct GLYPH_83fake logicValue;   // size=8, offset=0
	long timer;						  // size=0, offset=0
	long times;						  // size=0, offset=0
	long lightGroup;				  // size=0, offset=0
	long farPlane;					  // size=0, offset=0
	long cameraAdjust;				  // size=0, offset=0
	long cameraMode;				  // size=0, offset=0
	long cameraLock;				  // size=0, offset=0
	long cameraUnlock;				  // size=0, offset=0
	long cameraSmooth;				  // size=0, offset=0
	long cameraTimer;				  // size=0, offset=0
	struct GLYPH_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				  // size=0, offset=0
	long cameraRestore;				  // size=0, offset=0
	struct _BGObject *bgObject;		  // size=24, offset=0
	long value[2];					  // size=8, offset=0
	struct GLYPH_85fake sound;		  // size=12, offset=0
	void *intro;					  // size=0, offset=0
	long deathZ;					  // size=0, offset=0
	struct GLYPH_86fake dsignal;	  // size=8, offset=0
	void *mirror;					  // size=0, offset=0
	long fogNear;					  // size=0, offset=0
	long fogFar;					  // size=0, offset=0
	struct GLYPH_87fake gotoFrame;	// size=8, offset=0
	struct GLYPH_88fake changeModel;  // size=8, offset=0
	void *vmObject;					  // size=0, offset=0
	struct GLYPH_89fake logic;		  // size=8, offset=0
	void *callSignal;				  // size=0, offset=0
	struct _SVector offset;			  // size=8, offset=0
	struct Signal *gotoLabel;		  // size=0, offset=0
	struct Signal *gosubLabel;		  // size=0, offset=0
	struct GLYPH_90fake control;	  // size=8, offset=0
	struct GLYPH_91fake zSignal;	  // size=12, offset=0
	struct GLYPH_92fake StreamLevel;  // size=24, offset=0
	struct GLYPH_93fake shards;		  // size=12, offset=0
	struct GLYPH_94fake cameraSpline; // size=8, offset=0
	struct GLYPH_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				  // size=0, offset=0
	struct GLYPH_96fake introFX;	  // size=8, offset=0
	struct GLYPH_97fake introActive;  // size=8, offset=0
	struct GLYPH_98fake levelChange;  // size=18, offset=0
	long blendStart;				  // size=0, offset=0
	struct GLYPH_99fake setTimes;	 // size=8, offset=0
	struct GLYPH_100fake color;		  // size=4, offset=0
	struct GLYPH_101fake print;		  // size=12, offset=0
	long slideAngle;				  // size=0, offset=0
};

union GLYPH_103fake // Hashcode: 0x706CE308 (dec: 1886184200)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union GLYPH_108fake // Hashcode: 0x6E8B2EF2 (dec: 1854615282)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct GLYPH_110fake // hashcode: 0xEAE020A0 (dec: -354410336)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x21F10BFB (dec: 569445371), parent name: 'GLYPH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xB0DF110B (dec: -1327558389), parent name: 'GLYPH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0xA302A297 (dec: -1560108393), parent name: 'GLYPH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xE65139EC (dec: -430884372), parent name: 'GLYPH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x33A46C41 (dec: 866413633), parent name: 'GLYPH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x0D978005 (dec: 228032517), parent name: 'GLYPH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xEAF22455 (dec: -353229739), parent name: 'GLYPH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_111fake // hashcode: 0xA6A77344 (dec: -1498975420)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x7FB40047 (dec: 2142502983), parent name: 'GLYPH_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xFB740123 (dec: -76283613), parent name: 'GLYPH_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x02EFC01C (dec: 49266716), parent name: 'GLYPH_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_112fake // hashcode: 0xA7233EA9 (dec: -1490862423)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xE091BC1B (dec: -527320037), parent name: 'GLYPH_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x67AE30D2 (dec: 1739469010), parent name: 'GLYPH_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x1FC98113 (dec: 533299475), parent name: 'GLYPH_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xCC302736 (dec: -869259466), parent name: 'GLYPH_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xD943DA2F (dec: -649864657), parent name: 'GLYPH_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_113fake // hashcode: 0x0DC2C7EB (dec: 230868971)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x6703BD87 (dec: 1728298375), parent name: 'GLYPH_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x875A67DB (dec: -2024118309), parent name: 'GLYPH_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x8A3FB96A (dec: -1975535254), parent name: 'GLYPH_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xF03A9306 (dec: -264596730), parent name: 'GLYPH_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x4620E9BD (dec: 1176562109), parent name: 'GLYPH_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_114fake // hashcode: 0x249332FF (dec: 613626623)
{
	struct GLYPH_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x9FE5DEB8 (dec: -1612325192), parent name: 'GLYPH_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct GLYPH_111fake Idle;		// size=20, offset=28 //  hashcode: 0xA1A2CA9B (dec: -1583166821), parent name: 'GLYPH_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct GLYPH_112fake Behind;	// size=28, offset=48 //  hashcode: 0x3919916A (dec: 957976938), parent name: 'GLYPH_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct GLYPH_113fake Follow;	// size=20, offset=76 //  hashcode: 0x76D83ACB (dec: 1993882315), parent name: 'GLYPH_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_185fake // hashcode: 0x0041CCC1 (dec: 4312257)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0xB2F9A9E4 (dec: -1292260892), parent name: 'GLYPH_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x5E540A27 (dec: 1582565927), parent name: 'GLYPH_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GLYPH_186fake // hashcode: 0xC9E3FD9F (dec: -907805281)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0xCBC1B715 (dec: -876497131), parent name: 'GLYPH_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x4FD4A6D5 (dec: 1339336405), parent name: 'GLYPH_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x174F22C9 (dec: 391062217), parent name: 'GLYPH_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0xBDAFC8A3 (dec: -1112553309), parent name: 'GLYPH_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x4A7A3A3B (dec: 1249524283), parent name: 'GLYPH_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0xE3432285 (dec: -482139515), parent name: 'GLYPH_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union GLYPH_187fake // Hashcode: 0x0DB3A09C (dec: 229875868)
{
	struct GLYPH_185fake flame; // size=8, offset=0
	struct GLYPH_186fake phys;  // size=12, offset=0
};

union GLYPH_213fake // Hashcode: 0x655BB5FA (dec: 1700509178)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct __GlyphData // hashcode: 0x9C88C1F1 (dec: -1668759055)
{
	void (*process)();				// size=0, offset=0 //  hashcode: 0x85A72949 (dec: -2052642487), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __MessageQueue messages; // size=136, offset=4 //  hashcode: 0x60191D97 (dec: 1612258711), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short selectedGlyph;			// size=0, offset=140 //  hashcode: 0xDC89F698 (dec: -594938216), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short glyph_open;				// size=0, offset=142 //  hashcode: 0x5B86EEAE (dec: 1535569582), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short glyph_time;				// size=0, offset=144 //  hashcode: 0xFE369858 (dec: -29976488), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short glyph_radius;				// size=0, offset=146 //  hashcode: 0x3496F851 (dec: 882309201), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short glyph_scale;				// size=0, offset=148 //  hashcode: 0xD1B74662 (dec: -776518046), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short glyph_rotation;			// size=0, offset=150 //  hashcode: 0xA8AD58B4 (dec: -1465034572), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short target_glyph_rotation;	// size=0, offset=152 //  hashcode: 0x55AD99DC (dec: 1437440476), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short glyph_movement;			// size=0, offset=154 //  hashcode: 0x33CAF248 (dec: 868938312), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct __GlyphData GlyphData;

extern void GlyphInit(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007A8BC

extern void GlyphCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007A9D8

extern void GlyphProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007A9E0

extern unsigned long GlyphQuery(struct _Instance *instance, unsigned long query); // 0x8007AA68

extern void GlyphPost(struct _Instance *instance, unsigned long message, unsigned long messageData); // 0x8007AA88

extern void _GlyphSwitchProcess(struct _Instance *instance, TDRFuncPtr__GlyphSwitchProcess1process process); // 0x8007AABC

extern int GlyphIsGlyphOpen(struct _Instance *instance); // 0x8007AB5C

extern int _GlyphIsGlyphSet(int glyph); // 0x8007AB70

extern int _GlyphIsGlyphUsable(int glyph); // 0x8007ABB4

extern int _GlyphIsAnyGlyphSet(); // 0x8007ABF0

extern int _GlyphCost(struct _GlyphTuneData *glyphtunedata, int glyphNum); // 0x8007AC20

extern int GlyphIsPuppetShowModeOn(); // 0x8007AC30

extern void _GlyphDefaultProcess(struct _Instance *instance, int data1, int data2); // 0x8007AC54

extern void HUD_GetPlayerScreenPt(struct DVECTOR *center); // 0x8007ACF8

extern void GlyphDrawMenu(struct _Instance *instance); // 0x8007AD88

extern long GlyphTime(int time); // 0x8007B0EC

extern void ShrinkGlyphMenu(struct _Instance *instance); // 0x8007B108

extern void EnlargeGlyphMenu(struct _Instance *instance); // 0x8007B22C

extern void _GlyphOffProcess(struct _Instance *instance, int data1, int data2); // 0x8007B328

extern void _GlyphSelectProcess(struct _Instance *instance, int data1, int data2); // 0x8007B470

extern void Glyph_StartSpell(struct _Instance *instance, int glyphnum); // 0x8007B970

extern void Glyph_Broadcast(struct _Instance *sender, int glyphnum); // 0x8007BA18

extern void Glyph_DoSpell(struct _Instance *instance, int glyphnum); // 0x8007BC70

extern void Glyph_EndFX(); // 0x8007BF14

extern void Glyph_DoFX(struct _Instance *instance); // 0x8007BF28

extern void _GlyphGenericProcess(struct _Instance *instance, int data1, int data2); // 0x8007BFD8

extern void GlyphTrigger(); // 0x8007C110

extern void MANNA_Pickup(); // 0x8007C12C

extern void HEALTHU_Pickup(struct _Instance *instance); // 0x8007C148

extern void HUD_Damp(short *val, short target, short *vel, short max); // 0x8007C1D4

extern void HUD_Init(); // 0x8007C21C

extern void HUD_Setup_Chit_Count(int chits); // 0x8007C254

extern void HUD_Update(); // 0x8007C28C

extern void HUD_Draw(); // 0x8007C4C0

typedef void (*TDRFuncPtr__GlyphSwitchProcess1process)();

#endif
