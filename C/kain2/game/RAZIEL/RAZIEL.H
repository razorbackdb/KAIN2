#ifndef RAZIEL_H
#define RAZIEL_H

static int AlgoControlFlag; // offset 0x800CF858

static int BlockCount; // offset 0x800CF880

extern struct __CannedSound cannedSound[4]; // offset 0x800CF808

static struct __FitPoint constrictData[32]; // offset 0x800D5804

extern struct __razController controllerList[24]; // offset 0x800CF7A8

static unsigned short cowlList[19]; // offset 0x800CF780

extern struct __Idle **currentIdleList; // offset 0x800CF874

static struct __EngagedInstance EngagedList[15]; // offset 0x800D5924

static struct __Force ExternalForces[4]; // offset 0x800D58C4

static struct _G2SVector3_Type *ExtraRot; // offset 0x800D58B4

static struct _G2SVector3_Type ExtraRotData; // offset 0x800D58AC

static struct GameTracker *gameTracker; // offset 0x800D58A4

static int LastBlock; // offset 0x800CF884

static int LastRC; // offset 0x800D59A4

static struct _Normal Norm; // offset 0x800D599C

static long *PadData; // offset 0x800D58A8

static int PhysicsMode; // offset 0x800D5914

static unsigned char PickupList[4]; // offset 0x800CF77C

static struct RazielData *PlayerData; // offset 0x800D57D0

static struct __Player Raziel; // offset 0x800D5214

static struct _G2AnimInterpInfo_Type razInterpInfo[3]; // offset 0x800D57D4

static struct MATRIX TempMat; // offset 0x800D5884

static int WaterStatus; // offset 0x800CF778

static int ZoneDelta; // offset 0x800CF85C

struct RAZIEL_68fake // hashcode: 0xA152AE1F (dec: -1588416993)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xFD1E8AC8 (dec: -48330040), parent name: 'RAZIEL_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x3F3CF63A (dec: 1060959802), parent name: 'RAZIEL_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_69fake // hashcode: 0xAF63A127 (dec: -1352425177)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x83F0A2C6 (dec: -2081381690), parent name: 'RAZIEL_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x7C4C0EA7 (dec: 2085359271), parent name: 'RAZIEL_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_70fake // hashcode: 0x8B29243C (dec: -1960238020)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xDBCBD785 (dec: -607398011), parent name: 'RAZIEL_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x97CDB0DD (dec: -1748127523), parent name: 'RAZIEL_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union RAZIEL_71fake // Hashcode: 0xF5AF9DDD (dec: -173040163)
{
	struct RAZIEL_68fake callback; // size=8, offset=0
	struct RAZIEL_69fake vector;   // size=12, offset=0
	struct RAZIEL_70fake quat;	 // size=16, offset=0
};

union RAZIEL_72fake // Hashcode: 0x9204611F (dec: -1845206753)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union RAZIEL_73fake // Hashcode: 0x4F2C05D1 (dec: 1328285137)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct RAZIEL_74fake // hashcode: 0xA5FBC14E (dec: -1510227634)
{
	union RAZIEL_73fake size; // size=4, offset=0 //  hashcode: 0x50FAF1FE (dec: 1358623230), parent name: 'RAZIEL_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_75fake // hashcode: 0x1AED4EAD (dec: 451759789)
{
	short x;				// size=0, offset=0 //  hashcode: 0xE86C8957 (dec: -395540137), parent name: 'RAZIEL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x4B68E65F (dec: 1265165919), parent name: 'RAZIEL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x690137D0 (dec: 1761687504), parent name: 'RAZIEL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x579BBACC (dec: 1469823692), parent name: 'RAZIEL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xE37088B1 (dec: -479164239), parent name: 'RAZIEL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_76fake // hashcode: 0x1A8344C9 (dec: 444810441)
{
	long index; // size=0, offset=0 //  hashcode: 0x3C73124F (dec: 1014174287), parent name: 'RAZIEL_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x59FD2260 (dec: 1509761632), parent name: 'RAZIEL_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_77fake // hashcode: 0x1A689431 (dec: 443061297)
{
	long index; // size=0, offset=0 //  hashcode: 0x84A1E815 (dec: -2069764075), parent name: 'RAZIEL_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xE6262A1E (dec: -433706466), parent name: 'RAZIEL_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_78fake // hashcode: 0xCAE38A6C (dec: -891057556)
{
	long index; // size=0, offset=0 //  hashcode: 0x917A0BB6 (dec: -1854272586), parent name: 'RAZIEL_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xB8452B5F (dec: -1203426465), parent name: 'RAZIEL_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_79fake // hashcode: 0x4AD3BA58 (dec: 1255389784)
{
	long time;  // size=0, offset=0 //  hashcode: 0x10A4FD8E (dec: 279248270), parent name: 'RAZIEL_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x1E360530 (dec: 506856752), parent name: 'RAZIEL_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_80fake // hashcode: 0xBE1166A3 (dec: -1106155869)
{
	long action;   // size=0, offset=0 //  hashcode: 0x765AEF7B (dec: 1985671035), parent name: 'RAZIEL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xDC4FC696 (dec: -598751594), parent name: 'RAZIEL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_81fake // hashcode: 0x4DF1BD18 (dec: 1307688216)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x40088A5F (dec: 1074301535), parent name: 'RAZIEL_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xF483D5FC (dec: -192686596), parent name: 'RAZIEL_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_82fake // hashcode: 0xD9DE4647 (dec: -639744441)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xCFCB8B89 (dec: -808744055), parent name: 'RAZIEL_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x987C2AF6 (dec: -1736693002), parent name: 'RAZIEL_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_83fake // hashcode: 0x4F718ACA (dec: 1332841162)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x13AAD463 (dec: 329962595), parent name: 'RAZIEL_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x932E908D (dec: -1825664883), parent name: 'RAZIEL_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_84fake // hashcode: 0x2B597B40 (dec: 727284544)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x559502A6 (dec: 1435828902), parent name: 'RAZIEL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x172C89D7 (dec: 388794839), parent name: 'RAZIEL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x80B7ABB4 (dec: -2135446604), parent name: 'RAZIEL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xFC951D0A (dec: -57336566), parent name: 'RAZIEL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xE7E9E2DF (dec: -404102433), parent name: 'RAZIEL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_85fake // hashcode: 0xBC9A38CF (dec: -1130743601)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xE2C833AF (dec: -490196049), parent name: 'RAZIEL_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xB53F58CA (dec: -1254139702), parent name: 'RAZIEL_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_86fake // hashcode: 0x941CE3AE (dec: -1810046034)
{
	short index;					// size=0, offset=0 //  hashcode: 0x16E99BDF (dec: 384408543), parent name: 'RAZIEL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xEF2DE790 (dec: -282204272), parent name: 'RAZIEL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xD9C52A59 (dec: -641389991), parent name: 'RAZIEL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xDA9F77EF (dec: -627083281), parent name: 'RAZIEL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_87fake // hashcode: 0xC7C3516D (dec: -943500947)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xED47F90A (dec: -314050294), parent name: 'RAZIEL_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x84CB6A3B (dec: -2067043781), parent name: 'RAZIEL_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xC19411D4 (dec: -1047260716), parent name: 'RAZIEL_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_88fake // hashcode: 0x99125219 (dec: -1726852583)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xB34373DD (dec: -1287425059), parent name: 'RAZIEL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x114E8CE1 (dec: 290360545), parent name: 'RAZIEL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xD08CF2C0 (dec: -796069184), parent name: 'RAZIEL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x7828662C (dec: 2015913516), parent name: 'RAZIEL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x9B6D36B2 (dec: -1687341390), parent name: 'RAZIEL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xBC4B29C1 (dec: -1135924799), parent name: 'RAZIEL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x301E4782 (dec: 807290754), parent name: 'RAZIEL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_89fake // hashcode: 0xD4D55EBA (dec: -724214086)
{
	long index;  // size=0, offset=0 //  hashcode: 0x5E7B61E7 (dec: 1585144295), parent name: 'RAZIEL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x44327B8D (dec: 1144159117), parent name: 'RAZIEL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_90fake // hashcode: 0x6A39DB87 (dec: 1782176647)
{
	short type; // size=0, offset=0 //  hashcode: 0xFFC1C6A9 (dec: -4077911), parent name: 'RAZIEL_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xE408C2B8 (dec: -469187912), parent name: 'RAZIEL_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_91fake // hashcode: 0x3D377039 (dec: 1027043385)
{
	long time;   // size=0, offset=0 //  hashcode: 0x86CA45B6 (dec: -2033564234), parent name: 'RAZIEL_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x9797A16B (dec: -1751670421), parent name: 'RAZIEL_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_92fake // hashcode: 0xFFBE8F50 (dec: -4288688)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x16F9E01E (dec: 385474590), parent name: 'RAZIEL_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xE5075569 (dec: -452504215), parent name: 'RAZIEL_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_93fake // hashcode: 0xDAC6930D (dec: -624520435)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x43563CF9 (dec: 1129725177), parent name: 'RAZIEL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xCE343658 (dec: -835439016), parent name: 'RAZIEL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_94fake // hashcode: 0xD3CE91B5 (dec: -741437003)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x2F0CF88B (dec: 789379211), parent name: 'RAZIEL_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xEDB88718 (dec: -306673896), parent name: 'RAZIEL_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_95fake // hashcode: 0xAC9598CD (dec: -1399482163)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0xEE7746DE (dec: -294172962), parent name: 'RAZIEL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x4C757B43 (dec: 1282767683), parent name: 'RAZIEL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xCF07FE59 (dec: -821559719), parent name: 'RAZIEL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x1B0496BD (dec: 453285565), parent name: 'RAZIEL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_96fake // hashcode: 0x48E544F2 (dec: 1222984946)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xDA8DC526 (dec: -628243162), parent name: 'RAZIEL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x56FD6DC1 (dec: 1459449281), parent name: 'RAZIEL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x1BCC6667 (dec: 466380391), parent name: 'RAZIEL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x99DC17C3 (dec: -1713629245), parent name: 'RAZIEL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x0CC5DFAE (dec: 214294446), parent name: 'RAZIEL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union RAZIEL_97fake // Hashcode: 0xF0FEAD99 (dec: -251744871)
{
	struct RAZIEL_74fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	  // size=24, offset=0
	struct RAZIEL_75fake teleport;	 // size=16, offset=0
	struct RAZIEL_76fake cameraValue;  // size=8, offset=0
	struct RAZIEL_77fake miscValue;	// size=8, offset=0
	struct RAZIEL_78fake logicValue;   // size=8, offset=0
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
	struct RAZIEL_79fake cameraShake;  // size=8, offset=0
	long cameraSave;				   // size=0, offset=0
	long cameraRestore;				   // size=0, offset=0
	struct _BGObject *bgObject;		   // size=24, offset=0
	long value[2];					   // size=8, offset=0
	struct RAZIEL_80fake sound;		   // size=12, offset=0
	void *intro;					   // size=0, offset=0
	long deathZ;					   // size=0, offset=0
	struct RAZIEL_81fake dsignal;	  // size=8, offset=0
	void *mirror;					   // size=0, offset=0
	long fogNear;					   // size=0, offset=0
	long fogFar;					   // size=0, offset=0
	struct RAZIEL_82fake gotoFrame;	// size=8, offset=0
	struct RAZIEL_83fake changeModel;  // size=8, offset=0
	void *vmObject;					   // size=0, offset=0
	struct RAZIEL_84fake logic;		   // size=8, offset=0
	void *callSignal;				   // size=0, offset=0
	struct _SVector offset;			   // size=8, offset=0
	struct Signal *gotoLabel;		   // size=0, offset=0
	struct Signal *gosubLabel;		   // size=0, offset=0
	struct RAZIEL_85fake control;	  // size=8, offset=0
	struct RAZIEL_86fake zSignal;	  // size=12, offset=0
	struct RAZIEL_87fake StreamLevel;  // size=24, offset=0
	struct RAZIEL_88fake shards;	   // size=12, offset=0
	struct RAZIEL_89fake cameraSpline; // size=8, offset=0
	struct RAZIEL_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;				   // size=0, offset=0
	struct RAZIEL_91fake introFX;	  // size=8, offset=0
	struct RAZIEL_92fake introActive;  // size=8, offset=0
	struct RAZIEL_93fake levelChange;  // size=18, offset=0
	long blendStart;				   // size=0, offset=0
	struct RAZIEL_94fake setTimes;	 // size=8, offset=0
	struct RAZIEL_95fake color;		   // size=4, offset=0
	struct RAZIEL_96fake print;		   // size=12, offset=0
	long slideAngle;				   // size=0, offset=0
};

union RAZIEL_98fake // Hashcode: 0x18E1A0D3 (dec: 417439955)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union RAZIEL_103fake // Hashcode: 0xA43908AB (dec: -1539766101)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct RAZIEL_105fake // hashcode: 0xBA21BEA0 (dec: -1172193632)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x89F79AA7 (dec: -1980261721), parent name: 'RAZIEL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x8BFD53D6 (dec: -1946332202), parent name: 'RAZIEL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x6D9CB353 (dec: 1838986067), parent name: 'RAZIEL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x9A366C23 (dec: -1707709405), parent name: 'RAZIEL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x8C5C4326 (dec: -1940110554), parent name: 'RAZIEL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xF3A8FA67 (dec: -207029657), parent name: 'RAZIEL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x0804932D (dec: 134517549), parent name: 'RAZIEL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_106fake // hashcode: 0x7A01D7AC (dec: 2046941100)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x1882ADB2 (dec: 411217330), parent name: 'RAZIEL_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x934CBBCC (dec: -1823687732), parent name: 'RAZIEL_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x572D98E4 (dec: 1462606052), parent name: 'RAZIEL_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_107fake // hashcode: 0xA1FB21EE (dec: -1577377298)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xC7C82CFE (dec: -943182594), parent name: 'RAZIEL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xD4253AD5 (dec: -735757611), parent name: 'RAZIEL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x24FE8E9E (dec: 620662430), parent name: 'RAZIEL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xDFDF3F84 (dec: -539017340), parent name: 'RAZIEL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x0440C6FB (dec: 71354107), parent name: 'RAZIEL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_108fake // hashcode: 0x9E4A0FA5 (dec: -1639313499)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xCFF00E0A (dec: -806351350), parent name: 'RAZIEL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x2F24BDF9 (dec: 790937081), parent name: 'RAZIEL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x5B9DA3BD (dec: 1537057725), parent name: 'RAZIEL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x9ED9C514 (dec: -1629895404), parent name: 'RAZIEL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x026F38B0 (dec: 40843440), parent name: 'RAZIEL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_109fake // hashcode: 0x3CBFDB30 (dec: 1019206448)
{
	struct RAZIEL_105fake Cinematic; // size=28, offset=0 //  hashcode: 0x9F54011D (dec: -1621884643), parent name: 'RAZIEL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RAZIEL_106fake Idle;		 // size=20, offset=28 //  hashcode: 0x8C47D27D (dec: -1941450115), parent name: 'RAZIEL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RAZIEL_107fake Behind;	// size=28, offset=48 //  hashcode: 0xF4406D3C (dec: -197104324), parent name: 'RAZIEL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RAZIEL_108fake Follow;	// size=20, offset=76 //  hashcode: 0x5D93FB24 (dec: 1569979172), parent name: 'RAZIEL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union RAZIEL_203fake // Hashcode: 0x2DB038C4 (dec: 766523588)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct RAZIEL_219fake // hashcode: 0xB286ACC4 (dec: -1299796796)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x1FB06551 (dec: 531653969), parent name: 'RAZIEL_219fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0xFF749E87 (dec: -9134457), parent name: 'RAZIEL_219fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_220fake // hashcode: 0x2E7B779F (dec: 779843487)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x0734E376 (dec: 120906614), parent name: 'RAZIEL_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x46A3B7B2 (dec: 1185134514), parent name: 'RAZIEL_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0xEC2C8251 (dec: -332627375), parent name: 'RAZIEL_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0xDD050A5B (dec: -586872229), parent name: 'RAZIEL_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x52937E9C (dec: 1385397916), parent name: 'RAZIEL_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x4160A9D0 (dec: 1096853968), parent name: 'RAZIEL_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union RAZIEL_221fake // Hashcode: 0x9235F9B7 (dec: -1841956425)
{
	struct RAZIEL_219fake flame; // size=8, offset=0
	struct RAZIEL_220fake phys;  // size=12, offset=0
};

union RAZIEL_257fake // Hashcode: 0x017E7D66 (dec: 25066854)
{
	struct Intro *intro;	   // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

union RAZIEL_259fake // Hashcode: 0x2756E344 (dec: 660005700)
{
	struct _Instance *instance; // size=616, offset=0
	struct _SFXMkr *sfxMarker;  // size=36, offset=0
};

struct RAZIEL_260fake // hashcode: 0xE21C2FCC (dec: -501469236)
{
	long instanceNumber; // size=0, offset=0 //  hashcode: 0x797D4D0C (dec: 2038254860), parent name: 'RAZIEL_260fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;		 // size=0, offset=4 //  hashcode: 0xCEE5D9BF (dec: -823797313), parent name: 'RAZIEL_260fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_261fake // hashcode: 0x159EF2F2 (dec: 362738418)
{
	struct _SavedIntro *intro; // size=40, offset=0 //  hashcode: 0x0FFB883A (dec: 268142650), parent name: 'RAZIEL_261fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;			   // size=0, offset=4 //  hashcode: 0x331A57D0 (dec: 857364432), parent name: 'RAZIEL_261fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_262fake // hashcode: 0xE20F2AA5 (dec: -502322523)
{
	long currentNumber; // size=0, offset=0 //  hashcode: 0x30B19359 (dec: 816943961), parent name: 'RAZIEL_262fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long error;			// size=0, offset=4 //  hashcode: 0xDD10257C (dec: -586144388), parent name: 'RAZIEL_262fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;		// size=0, offset=8 //  hashcode: 0x99E692D2 (dec: -1712942382), parent name: 'RAZIEL_262fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_263fake // hashcode: 0xD36BAD20 (dec: -747918048)
{
	short vx; // size=0, offset=0 //  hashcode: 0x4ED5FF79 (dec: 1322647417), parent name: 'RAZIEL_263fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vy; // size=0, offset=2 //  hashcode: 0x7059CB86 (dec: 1884932998), parent name: 'RAZIEL_263fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_264fake // hashcode: 0x62706936 (dec: 1651534134)
{
	char *pointer; // size=0, offset=0 //  hashcode: 0x86BD269F (dec: -2034424161), parent name: 'RAZIEL_264fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_265fake // hashcode: 0x3A8F0B92 (dec: 982453138)
{
	short *pointer; // size=0, offset=0 //  hashcode: 0xCBE67DBC (dec: -874086980), parent name: 'RAZIEL_265fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZIEL_266fake // hashcode: 0xDDAEB162 (dec: -575753886)
{
	long *pointer; // size=0, offset=0 //  hashcode: 0xB64E158B (dec: -1236396661), parent name: 'RAZIEL_266fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union RAZIEL_267fake // Hashcode: 0xBCDF166E (dec: -1126230418)
{
	struct RAZIEL_260fake Object;					  // size=8, offset=0
	struct RAZIEL_261fake SavedIntroObject;			  // size=8, offset=0
	struct InstanceSpline instanceSpline;			  // size=24, offset=0
	struct RAZIEL_262fake Number;					  // size=12, offset=0
	struct RAZIEL_263fake Vector2d;					  // size=4, offset=0
	struct RAZIEL_264fake CharPointer;				  // size=4, offset=0
	struct RAZIEL_265fake ShortPointer;				  // size=4, offset=0
	struct RAZIEL_266fake LongPointer;				  // size=4, offset=0
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

struct __CannedSound // hashcode: 0x8A7588C2 (dec: -1972008766)
{
	short bank;		   // size=0, offset=0 //  hashcode: 0x4BF70B87 (dec: 1274481543), parent name: '__CannedSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sound;	   // size=0, offset=2 //  hashcode: 0x72414B3D (dec: 1916881725), parent name: '__CannedSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startPitch;  // size=0, offset=4 //  hashcode: 0xA6699293 (dec: -1503030637), parent name: '__CannedSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	short endPitch;	// size=0, offset=6 //  hashcode: 0xF39964FC (dec: -208050948), parent name: '__CannedSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startVolume; // size=0, offset=8 //  hashcode: 0x5D472BA2 (dec: 1564945314), parent name: '__CannedSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	short endVolume;   // size=0, offset=10 //  hashcode: 0x5DE1AB99 (dec: 1575070617), parent name: '__CannedSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	long time;		   // size=0, offset=12 //  hashcode: 0xD59B21DA (dec: -711253542), parent name: '__CannedSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	long distance;	 // size=0, offset=16 //  hashcode: 0x33EF788D (dec: 871331981), parent name: '__CannedSound', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __AlarmData // hashcode: 0x49AF2B39 (dec: 1236216633)
{
	short command; // size=0, offset=0 //  hashcode: 0xE2721A74 (dec: -495838604), parent name: '__AlarmData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short data;	// size=0, offset=2 //  hashcode: 0x61BCBB7A (dec: 1639758714), parent name: '__AlarmData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _SoundRamp // hashcode: 0xB5503009 (dec: -1253036023)
{
	unsigned long soundHandle;   // size=0, offset=0 //  hashcode: 0x99EED1EC (dec: -1712401940), parent name: '_SoundRamp', parent hashcode: 0xFFFFFFFF (dec: -1)
	long soundTimer;			 // size=0, offset=4 //  hashcode: 0x9AC7A69E (dec: -1698191714), parent name: '_SoundRamp', parent hashcode: 0xFFFFFFFF (dec: -1)
	long soundTotalTime;		 // size=0, offset=8 //  hashcode: 0x0B2DF29A (dec: 187560602), parent name: '_SoundRamp', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long soundDistance; // size=0, offset=12 //  hashcode: 0x2E9F4828 (dec: 782190632), parent name: '_SoundRamp', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundStartPitch;		 // size=0, offset=16 //  hashcode: 0x9DFDAE6E (dec: -1644319122), parent name: '_SoundRamp', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundEndPitch;		 // size=0, offset=18 //  hashcode: 0xBB4A250A (dec: -1152768758), parent name: '_SoundRamp', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundStartVolume;		 // size=0, offset=20 //  hashcode: 0x1011964C (dec: 269588044), parent name: '_SoundRamp', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundEndVolume;		 // size=0, offset=22 //  hashcode: 0xA103114B (dec: -1593634485), parent name: '_SoundRamp', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PlayerSaveData // hashcode: 0x12C2C060 (dec: 314753120)
{
	unsigned long abilities;		  // size=0, offset=0 //  hashcode: 0x8DE5B4E8 (dec: -1914325784), parent name: 'PlayerSaveData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long currentPlane;		  // size=0, offset=4 //  hashcode: 0xB757E18D (dec: -1218977395), parent name: 'PlayerSaveData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long healthScale;		  // size=0, offset=8 //  hashcode: 0x4997FD00 (dec: 1234697472), parent name: 'PlayerSaveData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long healthBalls;		  // size=0, offset=12 //  hashcode: 0x61EFA505 (dec: 1643095301), parent name: 'PlayerSaveData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short manaBalls;		  // size=0, offset=16 //  hashcode: 0x2D5E90DF (dec: 761172191), parent name: 'PlayerSaveData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short manaMax;			  // size=0, offset=18 //  hashcode: 0x7DF317F6 (dec: 2113083382), parent name: 'PlayerSaveData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long playerEventHistory; // size=0, offset=20 //  hashcode: 0x4AE32713 (dec: 1256400659), parent name: 'PlayerSaveData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RazielData // hashcode: 0x40AA7C96 (dec: 1084914838)
{
	unsigned long version;					  // size=0, offset=0 //  hashcode: 0x99A436DA (dec: -1717291302), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long nonBurningRibbonStartColor; // size=0, offset=4 //  hashcode: 0x03ED8C6E (dec: 65899630), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long nonBurningRibbonEndColor;   // size=0, offset=8 //  hashcode: 0x5BEEE442 (dec: 1542382658), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __Idle ***idleList;				  // size=4, offset=12 //  hashcode: 0x9068A3B7 (dec: -1872190537), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __AttackItem ***attackList;		  // size=36, offset=16 //  hashcode: 0xE0DCE502 (dec: -522394366), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __ThrowItem **throwList;			  // size=32, offset=20 //  hashcode: 0x9617175B (dec: -1776871589), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __VAnim *virtualAnimations;		  // size=8, offset=24 //  hashcode: 0xDB9FC9CA (dec: -610285110), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __VAnim *virtualAnimSingle;		  // size=8, offset=28 //  hashcode: 0x72739FB4 (dec: 1920180148), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __SAnim **stringAnimations;		  // size=16, offset=32 //  hashcode: 0xCF668DB0 (dec: -815362640), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short throwFadeValue;					  // size=0, offset=36 //  hashcode: 0x9492F591 (dec: -1802308207), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short throwFadeInRate;					  // size=0, offset=38 //  hashcode: 0x187B577F (dec: 410736511), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int throwFadeOutRate;					  // size=0, offset=40 //  hashcode: 0xBD6CDC89 (dec: -1116939127), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int throwManualDistance;				  // size=0, offset=44 //  hashcode: 0x895B5C21 (dec: -1990501343), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short healthMaterialRate;				  // size=0, offset=48 //  hashcode: 0xF03587FA (dec: -264927238), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short healthSpectralRate;				  // size=0, offset=50 //  hashcode: 0x528A560C (dec: 1384797708), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short healthInvinciblePostHit;			  // size=0, offset=52 //  hashcode: 0x19CF4569 (dec: 433014121), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short healthInvinciblePostShunt;		  // size=0, offset=54 //  hashcode: 0x38EB93AC (dec: 954962860), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short forceMinPitch;					  // size=0, offset=56 //  hashcode: 0x39CD599A (dec: 969759130), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short forceMaxPitch;					  // size=0, offset=58 //  hashcode: 0x150A4683 (dec: 352994947), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short forceMinVolume;					  // size=0, offset=60 //  hashcode: 0x0A471BCD (dec: 172432333), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short forceMaxVolume;					  // size=0, offset=62 //  hashcode: 0x9EE46CD5 (dec: -1629197099), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long forceRampTime;			  // size=0, offset=64 //  hashcode: 0x893BDAC3 (dec: -1992566077), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsFallDamping;				  // size=0, offset=68 //  hashcode: 0xC51242C3 (dec: -988659005), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsWaterFrequency;			  // size=0, offset=72 //  hashcode: 0xC1C5015F (dec: -1044053665), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsWaterAmplitude;			  // size=0, offset=76 //  hashcode: 0x5CE87858 (dec: 1558739032), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsUnderDeceleration;		  // size=0, offset=80 //  hashcode: 0x5598F3F8 (dec: 1436087288), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsUnderKickVelocity;		  // size=0, offset=84 //  hashcode: 0x4FA25F0B (dec: 1336041227), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsUnderKickAccel;			  // size=0, offset=88 //  hashcode: 0x7B5F4CEB (dec: 2069843179), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsUnderVelocity;			  // size=0, offset=92 //  hashcode: 0x49EBC99D (dec: 1240189341), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsUnderKickDecel;			  // size=0, offset=96 //  hashcode: 0x961CBCD4 (dec: -1776501548), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsUnderStealthAdjust;		  // size=0, offset=100 //  hashcode: 0x08D459EA (dec: 148134378), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsCoilVelocity;			  // size=0, offset=104 //  hashcode: 0x7DD5BE29 (dec: 2111159849), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsCoilDecelerationIn;		  // size=0, offset=108 //  hashcode: 0x7B42A57C (dec: 2067965308), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsCoilDecelerationOut;		  // size=0, offset=112 //  hashcode: 0x29123C9A (dec: 689061018), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsShotVelocity;			  // size=0, offset=116 //  hashcode: 0x5F8B812E (dec: 1602978094), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsShotAccelerationIn;		  // size=0, offset=120 //  hashcode: 0x58ABA3CC (dec: 1487643596), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsShotAccelerationOut;		  // size=0, offset=124 //  hashcode: 0x5255D214 (dec: 1381356052), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsSurfVelocity;			  // size=0, offset=128 //  hashcode: 0xA76A64DD (dec: -1486199587), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsSurfAccelerationIn;		  // size=0, offset=132 //  hashcode: 0xD4C289B5 (dec: -725448267), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsSurfAccelerationOut;		  // size=0, offset=136 //  hashcode: 0xBDFDF1E9 (dec: -1107430935), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsSurfKickVelocity;		  // size=0, offset=140 //  hashcode: 0x8C01B837 (dec: -1946044361), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsSurfKickAccel;			  // size=0, offset=144 //  hashcode: 0xF66A41D7 (dec: -160808489), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsSurfMinRotation;			  // size=0, offset=148 //  hashcode: 0xFE6C2B23 (dec: -26465501), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsSurfMaxRotation;			  // size=0, offset=152 //  hashcode: 0xDC27ABFD (dec: -601379843), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int SwimPhysicsSurfKickDecel;			  // size=0, offset=156 //  hashcode: 0xA1C01F3C (dec: -1581244612), parent name: 'RazielData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __razController // hashcode: 0x694854B2 (dec: 1766347954)
{
	unsigned short segment; // size=0, offset=0 //  hashcode: 0x775A4E0E (dec: 2002406926), parent name: '__razController', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short type;	// size=0, offset=2 //  hashcode: 0xACC8FD54 (dec: -1396114092), parent name: '__razController', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct __CannedSound CannedSound;

typedef struct __AlarmData AlarmData;

typedef struct _SoundRamp SoundRamp;

typedef struct PlayerSaveData PlayerSaveData;

typedef struct RazielData RazielData;

typedef struct __razController razController;

extern void InitStates(struct _Instance *PlayerInstance); // 0x800A80C8

extern void StateInitIdle(struct __CharacterState *In, int CurrentSection, int Ptr); // 0x800A83B0

extern void StateHandlerIdle(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A8668

extern void StateHandlerLookAround(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A8F28

extern void StateHandlerCrouch(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A9270

extern void StateHandlerDropAction(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A99E8

extern void StateHandlerSoulSuck(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A9C68

extern void StateHandlerStartTurn(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AA1A0

extern void StateInitStartMove(struct __CharacterState *In, int CurrentSection, int Frame); // 0x800AA3A0

extern void StateHandlerStartMove(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AA44C

extern void StateInitMove(struct __CharacterState *In, int CurrentSection, int Frames); // 0x800AAAEC

extern void StateHandlerMove(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AAD30

extern void StateHandlerStopMove(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AB430

extern void StateHandlerCompression(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AB788

extern void StateHandlerJump(struct __CharacterState *In, int CurrentSection, int Data); // 0x800ABB4C

extern void StateHandlerFall(struct __CharacterState *In, int CurrentSection, int Data); // 0x800ABF84

extern void StateHandlerSlide(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AC3F8

extern void StateHandlerBlock(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AC5D8

extern void StateHandlerDeCompression(struct __CharacterState *In, int CurrentSection, int Data); // 0x800ACA44

extern void StateHandlerGlide(struct __CharacterState *In, int CurrentSection, int Data); // 0x800ACDB4

extern void StateHandlerHang(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AD520

extern void StateHandlerPushObject(struct __CharacterState *In, int CurrentSection, int Data); // 0x800ADAC4

extern void StateHandlerBreakOff(struct __CharacterState *In, int CurrentSection, int Data); // 0x800ADDF0

extern void StateHandlerPullSwitch(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AE1F4

extern void StateHandlerDragObject(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AE804

extern void StateHandlerPickupObject(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AEF2C

extern void StateHandlerAutoFace(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AF148

extern void StateHandlerGlyphs(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AF888

extern void DefaultStateHandler(struct __CharacterState *In, int CurrentSection, int Data); // 0x800B0114

extern long RazielAnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, void *data); // 0x800B0AAC

extern long RazielAnimCallbackDuringPause(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, void *data); // 0x800B10B0

extern unsigned long RazielQuery(struct _Instance *instance, unsigned long Query); // 0x800B1164

extern void RazielPost(struct _Instance *instance, unsigned long Message, unsigned long Data); // 0x800B1528

extern int SetStates(struct _Instance *instance, struct GameTracker *GT, long *controlCommand, int AnalogLength); // 0x800B1EF8

extern void ProcessConstrict(); // 0x800B2588

extern void RelocateConstrict(struct _SVector *offset); // 0x800B285C

extern void ProcessEffects(struct _Instance *instance); // 0x800B29BC

extern void ProcessHints(); // 0x800B2BD0

extern void ProcessInteractiveMusic(struct _Instance *instance); // 0x800B2D08

extern void ProcessTimers(struct _Instance *instance); // 0x800B2EB8

extern void SetTimer(int ticks); // 0x800B33AC

extern void ProcessSpecialAbilities(struct _Instance *instance); // 0x800B33BC

extern int GetControllerMessages(long *controlCommand); // 0x800B3574

extern void RazielAdditionalCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x800B377C

extern int GetEngageEvent(struct _Instance *instance); // 0x800B3C78

extern int SetupReaction(struct _Instance *player, struct _Instance *instance); // 0x800B3CD0

extern int CheckHolding(struct _Instance *instance); // 0x800B3DC0

extern void DisableWristCollision(struct _Instance *instance, int Side); // 0x800B3DCC

extern void EnableWristCollision(struct _Instance *instance, int Side); // 0x800B3E1C

extern int GetCollisionType(struct _Instance *instance); // 0x800B3E6C

extern void InitGlyphSystem(struct _Instance *instance); // 0x800B4014

extern void mdRazielProcess(struct _Instance *playerInstance, struct GameTracker *gameTracker, long *controlCommand); // 0x800B404C

extern void RazielProcess(struct _Instance *playerInstance, struct GameTracker *gameTracker); // 0x800B4104

extern void RazielInit(struct _Instance *instance, struct GameTracker *gameTracker); // 0x800B4148

extern void RazielCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x800B420C

extern void RAZIEL_TurnHead(struct _Instance *instance, short *rotx, short *rotz, struct GameTracker *gameTracker); // 0x800B4470

extern void RAZIEL_SetLookAround(struct _Instance *instance); // 0x800B4694

extern void RAZIEL_ResetLookAround(struct _Instance *instance); // 0x800B470C

extern long RAZIEL_OkToLookAround(struct _Instance *playerInstance); // 0x800B4788

extern void TrailWaterFX(struct _Instance *instance, int Segment, int Bubbles, int Type); // 0x800B4810

#endif
