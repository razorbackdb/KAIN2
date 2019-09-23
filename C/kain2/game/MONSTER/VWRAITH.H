#ifndef VWRAITH_H
#define VWRAITH_H

extern struct _MonsterFunctionTable VWRAITH_FunctionTable; // offset 0x800CF6F4

extern struct _MonsterStateChoice VWRAITH_StateChoiceTable[7]; // offset 0x800CAB9C

struct VWRAITH_73fake // hashcode: 0xB42FFB15 (dec: -1271923947)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xB4D5F8D0 (dec: -1261045552), parent name: 'VWRAITH_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x25A64A3E (dec: 631654974), parent name: 'VWRAITH_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_74fake // hashcode: 0x6A4EFBDE (dec: 1783561182)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xD2BB57DC (dec: -759474212), parent name: 'VWRAITH_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xBAACC53A (dec: -1163082438), parent name: 'VWRAITH_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_75fake // hashcode: 0x887582CF (dec: -2005564721)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x149BFCC2 (dec: 345767106), parent name: 'VWRAITH_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x4D14E0EE (dec: 1293213934), parent name: 'VWRAITH_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union VWRAITH_76fake // Hashcode: 0x3BD14D9A (dec: 1003572634)
{
	struct VWRAITH_73fake callback; // size=8, offset=0
	struct VWRAITH_74fake vector;   // size=12, offset=0
	struct VWRAITH_75fake quat;		// size=16, offset=0
};

union VWRAITH_77fake // Hashcode: 0x1DF0AFEB (dec: 502312939)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union VWRAITH_78fake // Hashcode: 0x72C2A3E7 (dec: 1925358567)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct VWRAITH_79fake // hashcode: 0xF78B7572 (dec: -141855374)
{
	union VWRAITH_78fake size; // size=4, offset=0 //  hashcode: 0x3F588262 (dec: 1062765154), parent name: 'VWRAITH_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_80fake // hashcode: 0x8C5382B1 (dec: -1940684111)
{
	short x;				// size=0, offset=0 //  hashcode: 0x3004BE14 (dec: 805617172), parent name: 'VWRAITH_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xACAB9BD4 (dec: -1398039596), parent name: 'VWRAITH_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x02E48DE9 (dec: 48532969), parent name: 'VWRAITH_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x2E1636E3 (dec: 773207779), parent name: 'VWRAITH_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x71290C41 (dec: 1898515521), parent name: 'VWRAITH_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_81fake // hashcode: 0x4E50910F (dec: 1313902863)
{
	long index; // size=0, offset=0 //  hashcode: 0xF2CB451A (dec: -221559526), parent name: 'VWRAITH_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xDE8CBD94 (dec: -561201772), parent name: 'VWRAITH_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_82fake // hashcode: 0x0EA2275A (dec: 245507930)
{
	long index; // size=0, offset=0 //  hashcode: 0x4225E554 (dec: 1109779796), parent name: 'VWRAITH_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x75B6F64C (dec: 1974924876), parent name: 'VWRAITH_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_83fake // hashcode: 0x3300C4CD (dec: 855688397)
{
	long index; // size=0, offset=0 //  hashcode: 0xFD4C3AF1 (dec: -45335823), parent name: 'VWRAITH_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xE3649AC6 (dec: -479946042), parent name: 'VWRAITH_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_84fake // hashcode: 0x7C038ABB (dec: 2080606907)
{
	long time;  // size=0, offset=0 //  hashcode: 0x71EAD463 (dec: 1911215203), parent name: 'VWRAITH_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x9D2FF864 (dec: -1657800604), parent name: 'VWRAITH_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_85fake // hashcode: 0x91A35FCF (dec: -1851564081)
{
	long action;   // size=0, offset=0 //  hashcode: 0x1A63632C (dec: 442721068), parent name: 'VWRAITH_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x521E996F (dec: 1377737071), parent name: 'VWRAITH_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_86fake // hashcode: 0x95314CC7 (dec: -1791931193)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xDD506E77 (dec: -581931401), parent name: 'VWRAITH_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x730DEF0E (dec: 1930293006), parent name: 'VWRAITH_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_87fake // hashcode: 0x7118D7EB (dec: 1897453547)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x40EFE43C (dec: 1089463356), parent name: 'VWRAITH_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x7DB24755 (dec: 2108835669), parent name: 'VWRAITH_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_88fake // hashcode: 0x7C2C7F6B (dec: 2083290987)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xE190DAC0 (dec: -510600512), parent name: 'VWRAITH_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x56FFD8BB (dec: 1459607739), parent name: 'VWRAITH_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_89fake // hashcode: 0x33EF69D0 (dec: 871328208)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x652CFE8A (dec: 1697447562), parent name: 'VWRAITH_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x6AECA698 (dec: 1793894040), parent name: 'VWRAITH_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x02427B9F (dec: 37911455), parent name: 'VWRAITH_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x4C3DA74C (dec: 1279108940), parent name: 'VWRAITH_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xFDBE9FC7 (dec: -37838905), parent name: 'VWRAITH_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_90fake // hashcode: 0xE1D3A445 (dec: -506223547)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x57661C8B (dec: 1466309771), parent name: 'VWRAITH_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x4C52CF30 (dec: 1280495408), parent name: 'VWRAITH_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_91fake // hashcode: 0x87D26EE5 (dec: -2016252187)
{
	short index;					// size=0, offset=0 //  hashcode: 0x094EF66C (dec: 156169836), parent name: 'VWRAITH_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x3ACCBF71 (dec: 986496881), parent name: 'VWRAITH_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xF4AFD668 (dec: -189802904), parent name: 'VWRAITH_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x4E88FE66 (dec: 1317600870), parent name: 'VWRAITH_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_92fake // hashcode: 0x892EDDAE (dec: -1993417298)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x62322EC3 (dec: 1647455939), parent name: 'VWRAITH_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x5744E856 (dec: 1464133718), parent name: 'VWRAITH_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x0526580F (dec: 86398991), parent name: 'VWRAITH_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_93fake // hashcode: 0x8512D8CF (dec: -2062362417)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x70B87B68 (dec: 1891138408), parent name: 'VWRAITH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x402A534D (dec: 1076515661), parent name: 'VWRAITH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x1E8F0443 (dec: 512689219), parent name: 'VWRAITH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x11F196B8 (dec: 301045432), parent name: 'VWRAITH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x5E65CBCD (dec: 1583729613), parent name: 'VWRAITH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xDAC55EC3 (dec: -624599357), parent name: 'VWRAITH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xC7C6121B (dec: -943320549), parent name: 'VWRAITH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_94fake // hashcode: 0xBD623937 (dec: -1117636297)
{
	long index;  // size=0, offset=0 //  hashcode: 0xBDE612A0 (dec: -1108995424), parent name: 'VWRAITH_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xCBCB42EA (dec: -875871510), parent name: 'VWRAITH_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_95fake // hashcode: 0x79CF1629 (dec: 2043614761)
{
	short type; // size=0, offset=0 //  hashcode: 0x87BF31BD (dec: -2017513027), parent name: 'VWRAITH_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x96BD514D (dec: -1765977779), parent name: 'VWRAITH_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_96fake // hashcode: 0x883B47B5 (dec: -2009380939)
{
	long time;   // size=0, offset=0 //  hashcode: 0x91EACF5D (dec: -1846882467), parent name: 'VWRAITH_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x401AC613 (dec: 1075496467), parent name: 'VWRAITH_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_97fake // hashcode: 0x38726C14 (dec: 947022868)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x4B649488 (dec: 1264882824), parent name: 'VWRAITH_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x9414747E (dec: -1810598786), parent name: 'VWRAITH_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_98fake // hashcode: 0x101EEF6F (dec: 270462831)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x0CA08BCC (dec: 211848140), parent name: 'VWRAITH_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xCF8AA711 (dec: -812996847), parent name: 'VWRAITH_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_99fake // hashcode: 0x1805550B (dec: 403002635)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x102068F1 (dec: 270559473), parent name: 'VWRAITH_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x335D8500 (dec: 861766912), parent name: 'VWRAITH_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_100fake // hashcode: 0x158FFAE4 (dec: 361757412)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x27C1D4FF (dec: 667014399), parent name: 'VWRAITH_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xED5CC352 (dec: -312687790), parent name: 'VWRAITH_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xCF08F8FB (dec: -821495557), parent name: 'VWRAITH_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x4B5146D5 (dec: 1263617749), parent name: 'VWRAITH_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_101fake // hashcode: 0x550CCD20 (dec: 1426902304)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xDABEA922 (dec: -625039070), parent name: 'VWRAITH_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xD4394127 (dec: -734445273), parent name: 'VWRAITH_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x7D0AE59E (dec: 2097866142), parent name: 'VWRAITH_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x7053E16C (dec: 1884545388), parent name: 'VWRAITH_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x6C7F96E5 (dec: 1820301029), parent name: 'VWRAITH_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union VWRAITH_102fake // Hashcode: 0x40434805 (dec: 1078151173)
{
	struct VWRAITH_79fake misc[3];		// size=12, offset=0
	struct _CameraKey *cameraKey;		// size=24, offset=0
	struct VWRAITH_80fake teleport;		// size=16, offset=0
	struct VWRAITH_81fake cameraValue;  // size=8, offset=0
	struct VWRAITH_82fake miscValue;	// size=8, offset=0
	struct VWRAITH_83fake logicValue;   // size=8, offset=0
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
	struct VWRAITH_84fake cameraShake;  // size=8, offset=0
	long cameraSave;					// size=0, offset=0
	long cameraRestore;					// size=0, offset=0
	struct _BGObject *bgObject;			// size=24, offset=0
	long value[2];						// size=8, offset=0
	struct VWRAITH_85fake sound;		// size=12, offset=0
	void *intro;						// size=0, offset=0
	long deathZ;						// size=0, offset=0
	struct VWRAITH_86fake dsignal;		// size=8, offset=0
	void *mirror;						// size=0, offset=0
	long fogNear;						// size=0, offset=0
	long fogFar;						// size=0, offset=0
	struct VWRAITH_87fake gotoFrame;	// size=8, offset=0
	struct VWRAITH_88fake changeModel;  // size=8, offset=0
	void *vmObject;						// size=0, offset=0
	struct VWRAITH_89fake logic;		// size=8, offset=0
	void *callSignal;					// size=0, offset=0
	struct _SVector offset;				// size=8, offset=0
	struct Signal *gotoLabel;			// size=0, offset=0
	struct Signal *gosubLabel;			// size=0, offset=0
	struct VWRAITH_90fake control;		// size=8, offset=0
	struct VWRAITH_91fake zSignal;		// size=12, offset=0
	struct VWRAITH_92fake StreamLevel;  // size=24, offset=0
	struct VWRAITH_93fake shards;		// size=12, offset=0
	struct VWRAITH_94fake cameraSpline; // size=8, offset=0
	struct VWRAITH_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;					// size=0, offset=0
	struct VWRAITH_96fake introFX;		// size=8, offset=0
	struct VWRAITH_97fake introActive;  // size=8, offset=0
	struct VWRAITH_98fake levelChange;  // size=18, offset=0
	long blendStart;					// size=0, offset=0
	struct VWRAITH_99fake setTimes;		// size=8, offset=0
	struct VWRAITH_100fake color;		// size=4, offset=0
	struct VWRAITH_101fake print;		// size=12, offset=0
	long slideAngle;					// size=0, offset=0
};

union VWRAITH_103fake // Hashcode: 0xFD9EC704 (dec: -39926012)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union VWRAITH_108fake // Hashcode: 0x46B37C21 (dec: 1186167841)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct VWRAITH_110fake // hashcode: 0x05932676 (dec: 93529718)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xC934499C (dec: -919320164), parent name: 'VWRAITH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x2FD59D4D (dec: 802528589), parent name: 'VWRAITH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x46B068C0 (dec: 1185966272), parent name: 'VWRAITH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x092B794A (dec: 153844042), parent name: 'VWRAITH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x2C45D12D (dec: 742773037), parent name: 'VWRAITH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x27E5313F (dec: 669331775), parent name: 'VWRAITH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x6DA5B808 (dec: 1839577096), parent name: 'VWRAITH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_111fake // hashcode: 0xA56F15C5 (dec: -1519446587)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0xD7FC6D3E (dec: -671322818), parent name: 'VWRAITH_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x7BC04849 (dec: 2076198985), parent name: 'VWRAITH_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x1807E742 (dec: 403171138), parent name: 'VWRAITH_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_112fake // hashcode: 0x1F25BD3A (dec: 522566970)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x418C3209 (dec: 1099706889), parent name: 'VWRAITH_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x41048D90 (dec: 1090817424), parent name: 'VWRAITH_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xCB7E5D6F (dec: -880910993), parent name: 'VWRAITH_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x07106378 (dec: 118514552), parent name: 'VWRAITH_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x94FF394C (dec: -1795212980), parent name: 'VWRAITH_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_113fake // hashcode: 0x287363F4 (dec: 678650868)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x0A7B75B7 (dec: 175863223), parent name: 'VWRAITH_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0xB10C27B1 (dec: -1324603471), parent name: 'VWRAITH_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0xAB7D28B3 (dec: -1417860941), parent name: 'VWRAITH_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x463AB80D (dec: 1178253325), parent name: 'VWRAITH_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x595B54B7 (dec: 1499157687), parent name: 'VWRAITH_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_114fake // hashcode: 0x99946622 (dec: -1718327774)
{
	struct VWRAITH_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x6296F19B (dec: 1654059419), parent name: 'VWRAITH_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct VWRAITH_111fake Idle;	  // size=20, offset=28 //  hashcode: 0x839EB777 (dec: -2086750345), parent name: 'VWRAITH_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct VWRAITH_112fake Behind;	// size=28, offset=48 //  hashcode: 0x046EB05F (dec: 74362975), parent name: 'VWRAITH_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct VWRAITH_113fake Follow;	// size=20, offset=76 //  hashcode: 0x94C02989 (dec: -1799345783), parent name: 'VWRAITH_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union VWRAITH_193fake // Hashcode: 0x3F7542F5 (dec: 1064649461)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct VWRAITH_217fake // hashcode: 0x07A790BD (dec: 128422077)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x4E3210E2 (dec: 1311903970), parent name: 'VWRAITH_217fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x01F3993D (dec: 32741693), parent name: 'VWRAITH_217fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VWRAITH_218fake // hashcode: 0xE53A6196 (dec: -449158762)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0xA402CD1E (dec: -1543320290), parent name: 'VWRAITH_218fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x8EC2BC86 (dec: -1899840378), parent name: 'VWRAITH_218fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x87E584DF (dec: -2015001377), parent name: 'VWRAITH_218fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0xB3BA9E84 (dec: -1279615356), parent name: 'VWRAITH_218fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x09EB7815 (dec: 166426645), parent name: 'VWRAITH_218fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x5F15E605 (dec: 1595270661), parent name: 'VWRAITH_218fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union VWRAITH_219fake // Hashcode: 0x775FC549 (dec: 2002765129)
{
	struct VWRAITH_217fake flame; // size=8, offset=0
	struct VWRAITH_218fake phys;  // size=12, offset=0
};

extern void VWRAITH_MoveVertical(struct _Instance *instance, long targetZ, int velocity); // 0x8008E8F4

extern void VWRAITH_Init(struct _Instance *instance); // 0x8008E94C

extern int VWRAITH_ShouldISwoop(struct _Instance *instance); // 0x8008EA00

extern void VWRAITH_PursueEntry(struct _Instance *instance); // 0x8008EA84

extern void VWRAITH_Pursue(struct _Instance *instance); // 0x8008EB1C

extern void VWRAITH_VerticalMove(struct _Instance *instance); // 0x8008ECEC

extern void VWRAITH_CombatEntry(struct _Instance *instance); // 0x8008ED70

extern void VWRAITH_Combat(struct _Instance *instance); // 0x8008ED90

extern void VWRAITH_EmbraceEntry(struct _Instance *instance); // 0x8008EDBC

extern void VWRAITH_Embrace(struct _Instance *instance); // 0x8008EDDC

#endif
