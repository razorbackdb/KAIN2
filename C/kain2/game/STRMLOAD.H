#ifndef STRMLOAD_H
#define STRMLOAD_H

static int gCurDir; // offset 0x800CF4E8

static int loadCanFail; // offset 0x800CF4E4

static struct _LoadQueueEntry *loadFree; // offset 0x800D2724

static int loadFromHead; // offset 0x800CF4E0

static struct _LoadQueueEntry *loadHead; // offset 0x800D2728

static struct _LoadQueueEntry LoadQueue[40]; // offset 0x800D1D24

static struct _LoadQueueEntry *loadTail; // offset 0x800D272C

static int numLoads; // offset 0x800D2730

struct STRMLOAD_73fake // hashcode: 0xEE24FB79 (dec: -299566215)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x559804E1 (dec: 1436026081), parent name: 'STRMLOAD_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x88487B70 (dec: -2008515728), parent name: 'STRMLOAD_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_74fake // hashcode: 0xDFEACE95 (dec: -538259819)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x3AA3B6A0 (dec: 983807648), parent name: 'STRMLOAD_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x77EF664F (dec: 2012177999), parent name: 'STRMLOAD_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_75fake // hashcode: 0x4EFEEF5D (dec: 1325330269)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x90B8ED3E (dec: -1866928834), parent name: 'STRMLOAD_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x59FC5640 (dec: 1509709376), parent name: 'STRMLOAD_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union STRMLOAD_76fake // Hashcode: 0x11D0D844 (dec: 298899524)
{
	struct STRMLOAD_73fake callback; // size=8, offset=0
	struct STRMLOAD_74fake vector;   // size=12, offset=0
	struct STRMLOAD_75fake quat;	 // size=16, offset=0
};

union STRMLOAD_77fake // Hashcode: 0xBBC25C92 (dec: -1144890222)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union STRMLOAD_78fake // Hashcode: 0x1C8AB3A7 (dec: 478852007)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct STRMLOAD_79fake // hashcode: 0xD27EB7C2 (dec: -763447358)
{
	union STRMLOAD_78fake size; // size=4, offset=0 //  hashcode: 0xAB4DEBCC (dec: -1420956724), parent name: 'STRMLOAD_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_80fake // hashcode: 0x0228531B (dec: 36197147)
{
	short x;				// size=0, offset=0 //  hashcode: 0xAA31D642 (dec: -1439574462), parent name: 'STRMLOAD_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x687BED87 (dec: 1752952199), parent name: 'STRMLOAD_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xBDADDB95 (dec: -1112679531), parent name: 'STRMLOAD_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xFE7D9E3E (dec: -25321922), parent name: 'STRMLOAD_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x1762412E (dec: 392315182), parent name: 'STRMLOAD_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_81fake // hashcode: 0xFD212BAD (dec: -48157779)
{
	long index; // size=0, offset=0 //  hashcode: 0x75AAD556 (dec: 1974130006), parent name: 'STRMLOAD_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xAFFEEA47 (dec: -1342248377), parent name: 'STRMLOAD_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_82fake // hashcode: 0xC46655E2 (dec: -999926302)
{
	long index; // size=0, offset=0 //  hashcode: 0x90DF1794 (dec: -1864427628), parent name: 'STRMLOAD_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x8E34D498 (dec: -1909140328), parent name: 'STRMLOAD_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_83fake // hashcode: 0x8714B309 (dec: -2028686583)
{
	long index; // size=0, offset=0 //  hashcode: 0x2EDE60ED (dec: 786325741), parent name: 'STRMLOAD_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x85712012 (dec: -2056183790), parent name: 'STRMLOAD_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_84fake // hashcode: 0x87CCCFC9 (dec: -2016620599)
{
	long time;  // size=0, offset=0 //  hashcode: 0x37BDC3BC (dec: 935183292), parent name: 'STRMLOAD_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xA5C38F68 (dec: -1513910424), parent name: 'STRMLOAD_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_85fake // hashcode: 0x478CD9ED (dec: 1200413165)
{
	long action;   // size=0, offset=0 //  hashcode: 0x60875A4D (dec: 1619483213), parent name: 'STRMLOAD_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x31EB2C44 (dec: 837495876), parent name: 'STRMLOAD_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_86fake // hashcode: 0x070A28EC (dec: 118106348)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xEDD86934 (dec: -304584396), parent name: 'STRMLOAD_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xB52B7799 (dec: -1255442535), parent name: 'STRMLOAD_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_87fake // hashcode: 0xBE7DAFBC (dec: -1099059268)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xFCE71098 (dec: -51965800), parent name: 'STRMLOAD_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x26C641A1 (dec: 650527137), parent name: 'STRMLOAD_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_88fake // hashcode: 0xFD10BF7D (dec: -49234051)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xC25FB9C8 (dec: -1033913912), parent name: 'STRMLOAD_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xF0E0CEB9 (dec: -253702471), parent name: 'STRMLOAD_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_89fake // hashcode: 0x2AD82F52 (dec: 718810962)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x525C1D05 (dec: 1381768453), parent name: 'STRMLOAD_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xD07F5E3A (dec: -796959174), parent name: 'STRMLOAD_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xA1F51AC2 (dec: -1577772350), parent name: 'STRMLOAD_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x455E7CDD (dec: 1163820253), parent name: 'STRMLOAD_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x84F409CC (dec: -2064381492), parent name: 'STRMLOAD_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_90fake // hashcode: 0x7797E995 (dec: 2006444437)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x097D0C39 (dec: 159190073), parent name: 'STRMLOAD_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x96DA4718 (dec: -1764079848), parent name: 'STRMLOAD_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_91fake // hashcode: 0x8206DF09 (dec: -2113478903)
{
	short index;					// size=0, offset=0 //  hashcode: 0xB9CD7FC3 (dec: -1177714749), parent name: 'STRMLOAD_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xDB2935AD (dec: -618056275), parent name: 'STRMLOAD_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x7C1C0EDE (dec: 2082213598), parent name: 'STRMLOAD_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xF4084E62 (dec: -200782238), parent name: 'STRMLOAD_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_92fake // hashcode: 0x46C3EFEB (dec: 1187246059)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xFC55FFB5 (dec: -61472843), parent name: 'STRMLOAD_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x7B5405EF (dec: 2069104111), parent name: 'STRMLOAD_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x1A110483 (dec: 437322883), parent name: 'STRMLOAD_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_93fake // hashcode: 0x3BE6BD1F (dec: 1004977439)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xB719B9AF (dec: -1223050833), parent name: 'STRMLOAD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x79F0D7A8 (dec: 2045826984), parent name: 'STRMLOAD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x82CE6FFF (dec: -2100400129), parent name: 'STRMLOAD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x86281881 (dec: -2044192639), parent name: 'STRMLOAD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x5BC14E4D (dec: 1539395149), parent name: 'STRMLOAD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x72501FAF (dec: 1917853615), parent name: 'STRMLOAD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xB658CE67 (dec: -1235693977), parent name: 'STRMLOAD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_94fake // hashcode: 0xA216BEF2 (dec: -1575567630)
{
	long index;  // size=0, offset=0 //  hashcode: 0xFB384D78 (dec: -80196232), parent name: 'STRMLOAD_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x412E89DB (dec: 1093568987), parent name: 'STRMLOAD_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_95fake // hashcode: 0xA36A7A49 (dec: -1553302967)
{
	short type; // size=0, offset=0 //  hashcode: 0x79372AC1 (dec: 2033658561), parent name: 'STRMLOAD_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x34DC978E (dec: 886871950), parent name: 'STRMLOAD_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_96fake // hashcode: 0x1757DDB1 (dec: 391634353)
{
	long time;   // size=0, offset=0 //  hashcode: 0xD96CDE3C (dec: -647176644), parent name: 'STRMLOAD_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x3BFB8D32 (dec: 1006341426), parent name: 'STRMLOAD_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_97fake // hashcode: 0x167FA50A (dec: 377464074)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x3A891FF5 (dec: 982065141), parent name: 'STRMLOAD_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x51230F6A (dec: 1361252202), parent name: 'STRMLOAD_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_98fake // hashcode: 0xAE584809 (dec: -1369946103)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x97D3E6A8 (dec: -1747720536), parent name: 'STRMLOAD_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x1D5ED335 (dec: 492753717), parent name: 'STRMLOAD_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_99fake // hashcode: 0x9CCC9963 (dec: -1664312989)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xF2D99BDF (dec: -220619809), parent name: 'STRMLOAD_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x35449419 (dec: 893686809), parent name: 'STRMLOAD_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_100fake // hashcode: 0xEF12011F (dec: -284032737)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x845337C9 (dec: -2074921015), parent name: 'STRMLOAD_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xE3F20A8D (dec: -470676851), parent name: 'STRMLOAD_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x0E1F3C94 (dec: 236928148), parent name: 'STRMLOAD_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x1AF61D54 (dec: 452336980), parent name: 'STRMLOAD_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_101fake // hashcode: 0xD16B7D49 (dec: -781484727)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x686263A0 (dec: 1751278496), parent name: 'STRMLOAD_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xA13E67C3 (dec: -1589745725), parent name: 'STRMLOAD_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x0BB1652F (dec: 196175151), parent name: 'STRMLOAD_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xDCCBD300 (dec: -590621952), parent name: 'STRMLOAD_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xAA2A7567 (dec: -1440058009), parent name: 'STRMLOAD_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union STRMLOAD_102fake // Hashcode: 0x5E79F844 (dec: 1585051716)
{
	struct STRMLOAD_79fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;		 // size=24, offset=0
	struct STRMLOAD_80fake teleport;	 // size=16, offset=0
	struct STRMLOAD_81fake cameraValue;  // size=8, offset=0
	struct STRMLOAD_82fake miscValue;	// size=8, offset=0
	struct STRMLOAD_83fake logicValue;   // size=8, offset=0
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
	struct STRMLOAD_84fake cameraShake;  // size=8, offset=0
	long cameraSave;					 // size=0, offset=0
	long cameraRestore;					 // size=0, offset=0
	struct _BGObject *bgObject;			 // size=24, offset=0
	long value[2];						 // size=8, offset=0
	struct STRMLOAD_85fake sound;		 // size=12, offset=0
	void *intro;						 // size=0, offset=0
	long deathZ;						 // size=0, offset=0
	struct STRMLOAD_86fake dsignal;		 // size=8, offset=0
	void *mirror;						 // size=0, offset=0
	long fogNear;						 // size=0, offset=0
	long fogFar;						 // size=0, offset=0
	struct STRMLOAD_87fake gotoFrame;	// size=8, offset=0
	struct STRMLOAD_88fake changeModel;  // size=8, offset=0
	void *vmObject;						 // size=0, offset=0
	struct STRMLOAD_89fake logic;		 // size=8, offset=0
	void *callSignal;					 // size=0, offset=0
	struct _SVector offset;				 // size=8, offset=0
	struct Signal *gotoLabel;			 // size=0, offset=0
	struct Signal *gosubLabel;			 // size=0, offset=0
	struct STRMLOAD_90fake control;		 // size=8, offset=0
	struct STRMLOAD_91fake zSignal;		 // size=12, offset=0
	struct STRMLOAD_92fake StreamLevel;  // size=24, offset=0
	struct STRMLOAD_93fake shards;		 // size=12, offset=0
	struct STRMLOAD_94fake cameraSpline; // size=8, offset=0
	struct STRMLOAD_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;					 // size=0, offset=0
	struct STRMLOAD_96fake introFX;		 // size=8, offset=0
	struct STRMLOAD_97fake introActive;  // size=8, offset=0
	struct STRMLOAD_98fake levelChange;  // size=18, offset=0
	long blendStart;					 // size=0, offset=0
	struct STRMLOAD_99fake setTimes;	 // size=8, offset=0
	struct STRMLOAD_100fake color;		 // size=4, offset=0
	struct STRMLOAD_101fake print;		 // size=12, offset=0
	long slideAngle;					 // size=0, offset=0
};

union STRMLOAD_103fake // Hashcode: 0x81AE44D5 (dec: -2119285547)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union STRMLOAD_108fake // Hashcode: 0x20DF247A (dec: 551494778)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct STRMLOAD_112fake // hashcode: 0x4B621843 (dec: 1264719939)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x2D3AC3F0 (dec: 758825968), parent name: 'STRMLOAD_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x76866447 (dec: 1988518983), parent name: 'STRMLOAD_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x8A17685B (dec: -1978177445), parent name: 'STRMLOAD_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xBFEE08A6 (dec: -1074919258), parent name: 'STRMLOAD_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x43424DB8 (dec: 1128418744), parent name: 'STRMLOAD_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x28978B10 (dec: 681020176), parent name: 'STRMLOAD_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x47BB19A4 (dec: 1203444132), parent name: 'STRMLOAD_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_113fake // hashcode: 0xEEB3697D (dec: -290231939)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0xBE631895 (dec: -1100801899), parent name: 'STRMLOAD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xAC72F4A1 (dec: -1401752415), parent name: 'STRMLOAD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xFC9536EE (dec: -57329938), parent name: 'STRMLOAD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_114fake // hashcode: 0xDB68752A (dec: -613911254)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xB60EE72D (dec: -1240537299), parent name: 'STRMLOAD_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x8608143C (dec: -2046290884), parent name: 'STRMLOAD_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xBBD8FC20 (dec: -1143407584), parent name: 'STRMLOAD_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x810814CC (dec: -2130176820), parent name: 'STRMLOAD_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xAADD05D1 (dec: -1428355631), parent name: 'STRMLOAD_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_115fake // hashcode: 0x6FE477AF (dec: 1877243823)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x9601C7E4 (dec: -1778268188), parent name: 'STRMLOAD_115fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x97D4EE26 (dec: -1747653082), parent name: 'STRMLOAD_115fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x2547F464 (dec: 625472612), parent name: 'STRMLOAD_115fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x2E11FE19 (dec: 772931097), parent name: 'STRMLOAD_115fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x9B494FDB (dec: -1689694245), parent name: 'STRMLOAD_115fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STRMLOAD_116fake // hashcode: 0x9FFC6FB9 (dec: -1610846279)
{
	struct STRMLOAD_112fake Cinematic; // size=28, offset=0 //  hashcode: 0x47D53937 (dec: 1205156151), parent name: 'STRMLOAD_116fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct STRMLOAD_113fake Idle;	  // size=20, offset=28 //  hashcode: 0x6BC4B690 (dec: 1808053904), parent name: 'STRMLOAD_116fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct STRMLOAD_114fake Behind;	// size=28, offset=48 //  hashcode: 0xE1A429D6 (dec: -509335082), parent name: 'STRMLOAD_116fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct STRMLOAD_115fake Follow;	// size=20, offset=76 //  hashcode: 0xB6394E2C (dec: -1237758420), parent name: 'STRMLOAD_116fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union STRMLOAD_189fake // Hashcode: 0xF25C1B8D (dec: -228844659)
{
	struct _StreamUnit *streamUnit;		 // size=0, offset=0
	struct _ObjectTracker *streamObject; // size=36, offset=0
	struct _ButtonTexture *button;		 // size=0, offset=0
};

extern void STREAM_NextLoadFromHead(); // 0x8005FAE8

extern void STREAM_NextLoadCanFail(); // 0x8005FAF8

extern void STREAM_NextLoadAsNormal(); // 0x8005FB08

extern void STREAM_InitLoader(char *bigFileName, char *voiceFileName); // 0x8005FB18

extern void STREAM_RemoveQueueHead(); // 0x8005FB6C

extern void STREAM_RemoveQueueEntry(struct _LoadQueueEntry *entry, struct _LoadQueueEntry *prev); // 0x8005FBAC

extern struct _LoadQueueEntry *STREAM_AddQueueEntryToTail(); // 0x8005FC08

extern struct _LoadQueueEntry *STREAM_AddQueueEntryToHead(); // 0x8005FC74

extern int STREAM_IsCdBusy(long *numberInQueue); // 0x8005FD28

extern int STREAM_PollLoadQueue(); // 0x8005FD48

extern struct _LoadQueueEntry *STREAM_SetUpQueueEntry(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer, int fromhead); // 0x800600C8

extern void STREAM_QueueNonblockingLoads(char *fileName, unsigned char memType, void *retFunc, void *retData, void *retData2, void **retPointer, long relocateBinary); // 0x800601B4

extern void LOAD_LoadToAddress(char *fileName, void *loadAddr, long relocateBinary); // 0x80060240

extern void LOAD_NonBlockingBinaryLoad(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer, int memType); // 0x800602A8

extern void LOAD_NonBlockingFileLoad(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer, int memType); // 0x800602EC

extern void LOAD_NonBlockingBufferedLoad(char *fileName, void *retFunc, void *retData, void *retData2); // 0x8006032C

extern int LOAD_IsXAInQueue(); // 0x80060368

extern void LOAD_PlayXA(int number); // 0x800603B0

extern long *LOAD_ReadFile(char *fileName, unsigned char memType); // 0x800603E0

extern void LOAD_ChangeDirectory(char *name); // 0x8006042C

extern void LOAD_AbortDirectoryChange(char *name); // 0x80060478

extern void LOAD_AbortFileLoad(char *fileName, void *retFunc); // 0x80060500

#endif
