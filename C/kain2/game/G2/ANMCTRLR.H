#ifndef ANMCTRLR_H
#define ANMCTRLR_H

static struct _G2AnimChanStatusBlockPool_Type _chanStatusBlockPool; // offset 0x800D49CC

static struct _G2AnimControllerPool_Type _controllerPool; // offset 0x800D515C

static int _indexTable[16]; // offset 0x800CAC2C

static struct _G2AnimInterpStateBlockPool_Type _interpStateBlockPool; // offset 0x800D516C

static struct _G2AnimSegValue_Type _segValues[80]; // offset 0x800D49DC

static int _stepSizeTable[64]; // offset 0x800CAC6C

struct ANIMG2_20fake // hashcode: 0x15042EE5 (dec: 352595685)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x77810720 (dec: 2004944672), parent name: 'ANIMG2_20fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x0FF12DD0 (dec: 267464144), parent name: 'ANIMG2_20fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_21fake // hashcode: 0x70E46C04 (dec: 1894018052)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xFBDCDB4C (dec: -69412020), parent name: 'ANIMG2_21fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x4221BEB2 (dec: 1109507762), parent name: 'ANIMG2_21fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_22fake // hashcode: 0x70C642CB (dec: 1892041419)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x4D8C10D5 (dec: 1301024981), parent name: 'ANIMG2_22fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x01A50EA8 (dec: 27594408), parent name: 'ANIMG2_22fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union ANIMG2_23fake // Hashcode: 0x75C9973C (dec: 1976145724)
{
	struct ANIMG2_20fake callback; // size=8, offset=0
	struct ANIMG2_21fake vector;   // size=12, offset=0
	struct ANIMG2_22fake quat;	 // size=16, offset=0
};

struct _G2AnimController_Type // hashcode: 0x74838F3C (dec: 1954778940)
{
	unsigned short next;					   // size=0, offset=0 //  hashcode: 0x1B668904 (dec: 459704580), parent name: '_G2AnimController_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;						   // size=0, offset=2 //  hashcode: 0xED779F15 (dec: -310927595), parent name: '_G2AnimController_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segNumber;				   // size=0, offset=3 //  hashcode: 0xA2FE6B4F (dec: -1560384689), parent name: '_G2AnimController_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *callbackData;						   // size=0, offset=4 //  hashcode: 0x6E2B2FA2 (dec: 1848324002), parent name: '_G2AnimController_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short flags;					   // size=0, offset=8 //  hashcode: 0x92C8626B (dec: -1832361365), parent name: '_G2AnimController_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short duration;							   // size=0, offset=10 //  hashcode: 0xBB90E2A1 (dec: -1148132703), parent name: '_G2AnimController_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short elapsedTime;						   // size=0, offset=12 //  hashcode: 0x223F105E (dec: 574558302), parent name: '_G2AnimController_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimAlphaTable_Type *alphaTable; // size=4, offset=16 //  hashcode: 0xEC7B97FF (dec: -327444481), parent name: '_G2AnimController_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	union ANIMG2_23fake data;				   // size=16, offset=20 //  hashcode: 0x33EB88FA (dec: 871074042), parent name: '_G2AnimController_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union ANIMG2_72fake // Hashcode: 0x67F203D2 (dec: 1743913938)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union ANIMG2_73fake // Hashcode: 0x15BDCCF9 (dec: 364760313)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct ANIMG2_74fake // hashcode: 0xCFA52541 (dec: -811260607)
{
	union ANIMG2_73fake size; // size=4, offset=0 //  hashcode: 0x2D746BFE (dec: 762604542), parent name: 'ANIMG2_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_75fake // hashcode: 0x50D53B08 (dec: 1356151560)
{
	short x;				// size=0, offset=0 //  hashcode: 0x0E2EF91B (dec: 237959451), parent name: 'ANIMG2_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x2DFF5519 (dec: 771708185), parent name: 'ANIMG2_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x419C0CEB (dec: 1100745963), parent name: 'ANIMG2_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x797F8BC0 (dec: 2038401984), parent name: 'ANIMG2_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x499A9BF4 (dec: 1234869236), parent name: 'ANIMG2_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_76fake // hashcode: 0x5F858E96 (dec: 1602588310)
{
	long index; // size=0, offset=0 //  hashcode: 0x3CD6FC34 (dec: 1020722228), parent name: 'ANIMG2_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xB0AE736C (dec: -1330744468), parent name: 'ANIMG2_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_77fake // hashcode: 0xEFB0C26F (dec: -273628561)
{
	long index; // size=0, offset=0 //  hashcode: 0x9F8F0932 (dec: -1618015950), parent name: 'ANIMG2_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x1DAA5FDA (dec: 497704922), parent name: 'ANIMG2_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_78fake // hashcode: 0x00302EED (dec: 3157741)
{
	long index; // size=0, offset=0 //  hashcode: 0x6EA9B17A (dec: 1856614778), parent name: 'ANIMG2_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x36B7213F (dec: 917971263), parent name: 'ANIMG2_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_79fake // hashcode: 0x2AB8184D (dec: 716707917)
{
	long time;  // size=0, offset=0 //  hashcode: 0xF34BEA76 (dec: -213128586), parent name: 'ANIMG2_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xD15736FF (dec: -782813441), parent name: 'ANIMG2_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_80fake // hashcode: 0x2E8E9D7A (dec: 781098362)
{
	long action;   // size=0, offset=0 //  hashcode: 0xD21F8657 (dec: -769685929), parent name: 'ANIMG2_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xD782A50F (dec: -679303921), parent name: 'ANIMG2_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_81fake // hashcode: 0xD688A4A1 (dec: -695688031)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x88814D68 (dec: -2004791960), parent name: 'ANIMG2_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xDF88977B (dec: -544696453), parent name: 'ANIMG2_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_82fake // hashcode: 0xC2B4C2ED (dec: -1028341011)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x41F3CE82 (dec: 1106497154), parent name: 'ANIMG2_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x608F0016 (dec: 1619984406), parent name: 'ANIMG2_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_83fake // hashcode: 0x1C9C1FD2 (dec: 479993810)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xD7FB052F (dec: -671414993), parent name: 'ANIMG2_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xBEB7D021 (dec: -1095249887), parent name: 'ANIMG2_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_84fake // hashcode: 0xD82DD119 (dec: -668085991)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x78AAF868 (dec: 2024470632), parent name: 'ANIMG2_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x3DA63D20 (dec: 1034304800), parent name: 'ANIMG2_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x9422A326 (dec: -1809669338), parent name: 'ANIMG2_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x7C7713D3 (dec: 2088178643), parent name: 'ANIMG2_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x2E4F57EA (dec: 776951786), parent name: 'ANIMG2_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_85fake // hashcode: 0xAB6E9E72 (dec: -1418813838)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xBE9D6FCC (dec: -1096978484), parent name: 'ANIMG2_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x72DA24A8 (dec: 1926898856), parent name: 'ANIMG2_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_86fake // hashcode: 0xAA687C1D (dec: -1435993059)
{
	short index;					// size=0, offset=0 //  hashcode: 0xBEE58BC3 (dec: -1092252733), parent name: 'ANIMG2_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xCFFF3BE3 (dec: -805356573), parent name: 'ANIMG2_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xA1A5ACF1 (dec: -1582977807), parent name: 'ANIMG2_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x3B41C819 (dec: 994166809), parent name: 'ANIMG2_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_87fake // hashcode: 0xA2970B99 (dec: -1567159399)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xC5A624E6 (dec: -978967322), parent name: 'ANIMG2_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xFDDE79C9 (dec: -35751479), parent name: 'ANIMG2_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xDC45A0AD (dec: -599416659), parent name: 'ANIMG2_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_88fake // hashcode: 0xF26CAF72 (dec: -227758222)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x0B4D7C69 (dec: 189627497), parent name: 'ANIMG2_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x7CF0B3CA (dec: 2096149450), parent name: 'ANIMG2_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xF8180F41 (dec: -132640959), parent name: 'ANIMG2_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x81B40490 (dec: -2118908784), parent name: 'ANIMG2_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xAED88673 (dec: -1361541517), parent name: 'ANIMG2_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x14DB1FA5 (dec: 349904805), parent name: 'ANIMG2_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x623B8016 (dec: 1648066582), parent name: 'ANIMG2_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_89fake // hashcode: 0x8978EDB3 (dec: -1988563533)
{
	long index;  // size=0, offset=0 //  hashcode: 0xCC62DF6B (dec: -865935509), parent name: 'ANIMG2_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xE2C8D7F1 (dec: -490153999), parent name: 'ANIMG2_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_90fake // hashcode: 0xC125C2A0 (dec: -1054489952)
{
	short type; // size=0, offset=0 //  hashcode: 0xF3F74C28 (dec: -201896920), parent name: 'ANIMG2_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xB580C104 (dec: -1249853180), parent name: 'ANIMG2_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_91fake // hashcode: 0x079D2EC3 (dec: 127741635)
{
	long time;   // size=0, offset=0 //  hashcode: 0x0D791C49 (dec: 226040905), parent name: 'ANIMG2_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x82141A52 (dec: -2112611758), parent name: 'ANIMG2_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_92fake // hashcode: 0x8F3D1CB1 (dec: -1891820367)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x5C155127 (dec: 1544900903), parent name: 'ANIMG2_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x22DC5A04 (dec: 584866308), parent name: 'ANIMG2_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_93fake // hashcode: 0xF9DCE675 (dec: -102963595)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x66C145DD (dec: 1723942365), parent name: 'ANIMG2_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x26BB587C (dec: 649812092), parent name: 'ANIMG2_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_94fake // hashcode: 0x548D1D37 (dec: 1418534199)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x6170693F (dec: 1634756927), parent name: 'ANIMG2_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x6098012E (dec: 1620574510), parent name: 'ANIMG2_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_95fake // hashcode: 0xECAF2EF2 (dec: -324063502)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x5280739F (dec: 1384149919), parent name: 'ANIMG2_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x78C94449 (dec: 2026456137), parent name: 'ANIMG2_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x3633CE76 (dec: 909364854), parent name: 'ANIMG2_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xB5396E82 (dec: -1254527358), parent name: 'ANIMG2_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_96fake // hashcode: 0xC1DF11A1 (dec: -1042345567)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x6F8C2ED7 (dec: 1871458007), parent name: 'ANIMG2_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x5DEC09DF (dec: 1575750111), parent name: 'ANIMG2_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x02A390C3 (dec: 44273859), parent name: 'ANIMG2_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xA0FF1DCA (dec: -1593893430), parent name: 'ANIMG2_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x5C942CA6 (dec: 1553214630), parent name: 'ANIMG2_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union ANIMG2_97fake // Hashcode: 0x9C8EC72B (dec: -1668364501)
{
	struct ANIMG2_74fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	  // size=24, offset=0
	struct ANIMG2_75fake teleport;	 // size=16, offset=0
	struct ANIMG2_76fake cameraValue;  // size=8, offset=0
	struct ANIMG2_77fake miscValue;	// size=8, offset=0
	struct ANIMG2_78fake logicValue;   // size=8, offset=0
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
	struct ANIMG2_79fake cameraShake;  // size=8, offset=0
	long cameraSave;				   // size=0, offset=0
	long cameraRestore;				   // size=0, offset=0
	struct _BGObject *bgObject;		   // size=24, offset=0
	long value[2];					   // size=8, offset=0
	struct ANIMG2_80fake sound;		   // size=12, offset=0
	void *intro;					   // size=0, offset=0
	long deathZ;					   // size=0, offset=0
	struct ANIMG2_81fake dsignal;	  // size=8, offset=0
	void *mirror;					   // size=0, offset=0
	long fogNear;					   // size=0, offset=0
	long fogFar;					   // size=0, offset=0
	struct ANIMG2_82fake gotoFrame;	// size=8, offset=0
	struct ANIMG2_83fake changeModel;  // size=8, offset=0
	void *vmObject;					   // size=0, offset=0
	struct ANIMG2_84fake logic;		   // size=8, offset=0
	void *callSignal;				   // size=0, offset=0
	struct _SVector offset;			   // size=8, offset=0
	struct Signal *gotoLabel;		   // size=0, offset=0
	struct Signal *gosubLabel;		   // size=0, offset=0
	struct ANIMG2_85fake control;	  // size=8, offset=0
	struct ANIMG2_86fake zSignal;	  // size=12, offset=0
	struct ANIMG2_87fake StreamLevel;  // size=24, offset=0
	struct ANIMG2_88fake shards;	   // size=12, offset=0
	struct ANIMG2_89fake cameraSpline; // size=8, offset=0
	struct ANIMG2_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;				   // size=0, offset=0
	struct ANIMG2_91fake introFX;	  // size=8, offset=0
	struct ANIMG2_92fake introActive;  // size=8, offset=0
	struct ANIMG2_93fake levelChange;  // size=18, offset=0
	long blendStart;				   // size=0, offset=0
	struct ANIMG2_94fake setTimes;	 // size=8, offset=0
	struct ANIMG2_95fake color;		   // size=4, offset=0
	struct ANIMG2_96fake print;		   // size=12, offset=0
	long slideAngle;				   // size=0, offset=0
};

union ANIMG2_98fake // Hashcode: 0xE78D9F48 (dec: -410149048)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union ANIMG2_103fake // Hashcode: 0xDF63A370 (dec: -547118224)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct ANIMG2_105fake // hashcode: 0xD8CE1C16 (dec: -657581034)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xBCA90FA9 (dec: -1129771095), parent name: 'ANIMG2_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x8F7529F2 (dec: -1888146958), parent name: 'ANIMG2_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x17D1C7A9 (dec: 399624105), parent name: 'ANIMG2_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xFA03A7AC (dec: -100423764), parent name: 'ANIMG2_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x61A10DF2 (dec: 1637944818), parent name: 'ANIMG2_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x9278225E (dec: -1837620642), parent name: 'ANIMG2_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x0E96BA3A (dec: 244759098), parent name: 'ANIMG2_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_106fake // hashcode: 0xDC3F3954 (dec: -599836332)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x32A39766 (dec: 849581926), parent name: 'ANIMG2_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x1D659063 (dec: 493195363), parent name: 'ANIMG2_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x8E8FE588 (dec: -1903172216), parent name: 'ANIMG2_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_107fake // hashcode: 0x86533A5E (dec: -2041365922)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x8B94F63A (dec: -1953171910), parent name: 'ANIMG2_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xC624CF9D (dec: -970666083), parent name: 'ANIMG2_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x7984C7F6 (dec: 2038745078), parent name: 'ANIMG2_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x5F11FC9F (dec: 1595014303), parent name: 'ANIMG2_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xFE20D93F (dec: -31401665), parent name: 'ANIMG2_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_108fake // hashcode: 0x3B132AD1 (dec: 991111889)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x343999FF (dec: 876190207), parent name: 'ANIMG2_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x884DDA52 (dec: -2008163758), parent name: 'ANIMG2_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x5942B32A (dec: 1497543466), parent name: 'ANIMG2_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xE71C6C07 (dec: -417567737), parent name: 'ANIMG2_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x7CAD0B08 (dec: 2091715336), parent name: 'ANIMG2_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_109fake // hashcode: 0x1C77A67E (dec: 477603454)
{
	struct ANIMG2_105fake Cinematic; // size=28, offset=0 //  hashcode: 0xA135E44B (dec: -1590303669), parent name: 'ANIMG2_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct ANIMG2_106fake Idle;		 // size=20, offset=28 //  hashcode: 0xA9BE6423 (dec: -1447140317), parent name: 'ANIMG2_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct ANIMG2_107fake Behind;	// size=28, offset=48 //  hashcode: 0xDE333BFC (dec: -567067652), parent name: 'ANIMG2_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct ANIMG2_108fake Follow;	// size=20, offset=76 //  hashcode: 0x7714D4E1 (dec: 1997853921), parent name: 'ANIMG2_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_171fake // hashcode: 0xFE97A26B (dec: -23616917)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x509731A7 (dec: 1352085927), parent name: 'ANIMG2_171fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0xA4E0264E (dec: -1528814002), parent name: 'ANIMG2_171fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ANIMG2_172fake // hashcode: 0x68A0CFE6 (dec: 1755369446)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0xBB9B79B7 (dec: -1147438665), parent name: 'ANIMG2_172fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0xBA572105 (dec: -1168695035), parent name: 'ANIMG2_172fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x7315ECFF (dec: 1930816767), parent name: 'ANIMG2_172fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x2F67538F (dec: 795300751), parent name: 'ANIMG2_172fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x9B773023 (dec: -1686687709), parent name: 'ANIMG2_172fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0xF35F8B68 (dec: -211842200), parent name: 'ANIMG2_172fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union ANIMG2_173fake // Hashcode: 0x9934018C (dec: -1724644980)
{
	struct ANIMG2_171fake flame; // size=8, offset=0
	struct ANIMG2_172fake phys;  // size=12, offset=0
};

union ANIMG2_199fake // Hashcode: 0x703D7969 (dec: 1883076969)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct _G2AnimSegKeyflagInfo_Type // hashcode: 0x5786AAF7 (dec: 1468443383)
{
	unsigned long *stream; // size=0, offset=0 //  hashcode: 0x6858794C (dec: 1750628684), parent name: '_G2AnimSegKeyflagInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long flags;   // size=0, offset=4 //  hashcode: 0x4A587299 (dec: 1247310489), parent name: '_G2AnimSegKeyflagInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	int bitCount;		   // size=0, offset=8 //  hashcode: 0x845127C6 (dec: -2075056186), parent name: '_G2AnimSegKeyflagInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimDecompressChannelInfo_Type // hashcode: 0x9B2AEA69 (dec: -1691686295)
{
	struct _G2AnimKeylist_Type *keylist; // size=20, offset=0 //  hashcode: 0x97C53942 (dec: -1748682430), parent name: '_G2AnimDecompressChannelInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short *chanData;			 // size=0, offset=4 //  hashcode: 0xD74D584F (dec: -682796977), parent name: '_G2AnimDecompressChannelInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	int storedKey;						 // size=0, offset=8 //  hashcode: 0x8C703DC8 (dec: -1938801208), parent name: '_G2AnimDecompressChannelInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	int targetKey;						 // size=0, offset=12 //  hashcode: 0x30A5CF22 (dec: 816172834), parent name: '_G2AnimDecompressChannelInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union ANIMG2_217fake // Hashcode: 0x362C1E5A (dec: 908861018)
{
	struct _G2SVector3_Type rot; // size=6, offset=0
	struct _G2Quat_Type quat;	// size=8, offset=0
};

struct _G2AnimSegValue_Type // hashcode: 0x862DA63B (dec: -2043828677)
{
	union ANIMG2_217fake rotQuat;  // size=8, offset=0 //  hashcode: 0xC199C4F0 (dec: -1046887184), parent name: '_G2AnimSegValue_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type scale; // size=6, offset=8 //  hashcode: 0x947C1CE1 (dec: -1803805471), parent name: '_G2AnimSegValue_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad;			   // size=0, offset=14 //  hashcode: 0x1E17E5F3 (dec: 504882675), parent name: '_G2AnimSegValue_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type trans; // size=6, offset=16 //  hashcode: 0x303F4D54 (dec: 809454932), parent name: '_G2AnimSegValue_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short bIsQuat;		   // size=0, offset=22 //  hashcode: 0x2DDE0F62 (dec: 769527650), parent name: '_G2AnimSegValue_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimChanStatusBlockPool_Type // hashcode: 0x795F01EF (dec: 2036269551)
{
	unsigned short blockSize;					   // size=0, offset=0 //  hashcode: 0x1DD678E4 (dec: 500594916), parent name: '_G2AnimChanStatusBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short stackTop;					   // size=0, offset=2 //  hashcode: 0x64A09B0A (dec: 1688247050), parent name: '_G2AnimChanStatusBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short stackSize;					   // size=0, offset=4 //  hashcode: 0xB304E082 (dec: -1291526014), parent name: '_G2AnimChanStatusBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short *stack;						   // size=0, offset=8 //  hashcode: 0x1C3DA993 (dec: 473803155), parent name: '_G2AnimChanStatusBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimChanStatusBlock_Type *blockPool; // size=36, offset=12 //  hashcode: 0x06A77474 (dec: 111637620), parent name: '_G2AnimChanStatusBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimControllerPool_Type // hashcode: 0x7F1B4AF1 (dec: 2132495089)
{
	unsigned short blockSize;				  // size=0, offset=0 //  hashcode: 0x9DB88D3A (dec: -1648849606), parent name: '_G2AnimControllerPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short stackTop;				  // size=0, offset=2 //  hashcode: 0xA5594098 (dec: -1520877416), parent name: '_G2AnimControllerPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short stackSize;				  // size=0, offset=4 //  hashcode: 0x246980FB (dec: 610894075), parent name: '_G2AnimControllerPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short *stack;					  // size=0, offset=8 //  hashcode: 0xDBFE7326 (dec: -604081370), parent name: '_G2AnimControllerPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimController_Type *blockPool; // size=36, offset=12 //  hashcode: 0x599FE1F6 (dec: 1503650294), parent name: '_G2AnimControllerPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimInterpStateBlockPool_Type // hashcode: 0x71F99BDD (dec: 1912183773)
{
	unsigned short blockSize;						// size=0, offset=0 //  hashcode: 0xE57DAAF1 (dec: -444749071), parent name: '_G2AnimInterpStateBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short stackTop;						// size=0, offset=2 //  hashcode: 0xAF7EA68A (dec: -1350654326), parent name: '_G2AnimInterpStateBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short stackSize;						// size=0, offset=4 //  hashcode: 0x81711D57 (dec: -2123293353), parent name: '_G2AnimInterpStateBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short *stack;							// size=0, offset=8 //  hashcode: 0x1912A588 (dec: 420652424), parent name: '_G2AnimInterpStateBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimInterpStateBlock_Type *blockPool; // size=164, offset=12 //  hashcode: 0x03BA71BC (dec: 62550460), parent name: '_G2AnimInterpStateBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct _G2AnimController_Type G2AnimController;

typedef struct _G2AnimSegKeyflagInfo_Type G2AnimSegKeyflagInfo;

typedef struct _G2AnimDecompressChannelInfo_Type G2AnimDecompressChannelInfo;

typedef struct _G2AnimSegValue_Type G2AnimSegValue;

typedef struct _G2AnimChanStatusBlockPool_Type G2AnimChanStatusBlockPool;

typedef struct _G2AnimControllerPool_Type G2AnimControllerPool;

typedef struct _G2AnimInterpStateBlockPool_Type G2AnimInterpStateBlockPool;

typedef void G2PoolMem;

typedef void (*G2AnimApplyControllerFn)();

extern void G2Anim_AttachControllerToSeg(struct _G2Anim_Type *anim, int segNumber, int type); // 0x80090318

extern void G2Anim_DetachControllerFromSeg(struct _G2Anim_Type *anim, int segNumber, int type); // 0x80090350

extern void G2Anim_EnableController(struct _G2Anim_Type *anim, int segNumber, int type); // 0x80090418

extern void G2Anim_DisableController(struct _G2Anim_Type *anim, int segNumber, int type); // 0x800904F4

extern void G2Anim_InterpDisableController(struct _G2Anim_Type *anim, int segNumber, int type, short duration); // 0x80090534

extern enum _G2Bool_Enum G2Anim_IsControllerActive(struct _G2Anim_Type *anim, int segNumber, int type); // 0x80090654

extern enum _G2Bool_Enum G2Anim_IsControllerInterpolating(struct _G2Anim_Type *anim, int segNumber, int type); // 0x800906A0

extern void G2Anim_GetControllerCurrentInterpVector(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2SVector3_Type *vector); // 0x800906F4

extern void G2Anim_SetControllerCallbackData(struct _G2Anim_Type *anim, int segNumber, int type, void *callbackData); // 0x80090854

extern void G2Anim_SetControllerAngleOrder(struct _G2Anim_Type *anim, int segNumber, int type, int order); // 0x8009087C

extern void G2Anim_SetController_Vector(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2SVector3_Type *vector); // 0x800908B4

extern void G2Anim_SetInterpController_Vector(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2SVector3_Type *vector, int duration); // 0x800908FC

extern void G2Anim_SetInterpController_Quat(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2Quat_Type *quat, int duration); // 0x80090A60

extern void _G2Anim_ApplyControllersToStoredFrame(struct _G2Anim_Type *anim); // 0x80090ADC

extern void _G2Anim_BuildTransformsWithControllers(struct _G2Anim_Type *anim); // 0x80090B3C

extern void _G2Anim_BuildSegTransformWithControllers(struct _G2Matrix_Type *segMatrix, struct _G2Matrix_Type *parentMatrix, struct _G2AnimController_Type *controller, enum _G2Bool_Enum bRootTransUpdated, int segIndex); // 0x80090D1C

extern unsigned long _G2AnimController_ApplyToSegValue(struct _G2AnimController_Type *controller, struct _G2AnimSegValue_Type *segValue, struct _G2Matrix_Type *segMatrix, struct _G2Matrix_Type *parentMatrix); // 0x80091028

extern void _G2Anim_UpdateControllers(struct _G2Anim_Type *anim); // 0x800913D0

extern void _G2Anim_CopyVectorWithOrder(struct _G2SVector3_Type *sourceVector, struct _G2EulerAngles_Type *destVector, int order); // 0x8009155C

extern void _G2AnimSection_ApplyControllersToStoredFrame(struct _G2AnimSection_Type *section); // 0x800915C0

extern unsigned long _G2AnimController_ApplyWorldToParentMatrix(struct _G2AnimController_Type *controller, struct _G2Matrix_Type *parentMatrix); // 0x80091834

extern void _G2AnimController_GetMatrix(struct _G2AnimController_Type *controller, struct _G2Matrix_Type *matrix); // 0x80091988

extern void _G2AnimController_GetVector(struct _G2AnimController_Type *controller, struct _G2SVector3_Type *vector); // 0x80091A60

extern struct _G2AnimController_Type *_G2Anim_FindController(struct _G2Anim_Type *anim, int segNumber, int type); // 0x80091AE8

extern struct _G2AnimController_Type *_G2AnimController_Create(int segNumber, int type); // 0x80091B44

extern struct _G2AnimController_Type *_G2AnimController_Destroy(struct _G2AnimController_Type *controller); // 0x80091BAC

extern void _G2AnimController_InsertIntoList(struct _G2AnimController_Type *controller, unsigned short *listPtr); // 0x80091C10

extern void _G2AnimController_GetCurrentInterpQuat(struct _G2AnimController_Type *controller, struct _G2Anim_Type *anim, struct _G2Quat_Type *quat); // 0x80091D40

extern void _G2AnimController_GetSimpleWorldRotQuat(struct _G2AnimController_Type *controller, struct _G2Anim_Type *anim, struct _G2Quat_Type *quat); // 0x80091E7C

extern struct _G2AnimController_Type *_G2AnimControllerST_FindInList(int segNumber, int type, unsigned short *listPtr); // 0x80091EFC

extern struct _G2AnimController_Type *_G2AnimControllerST_FindPtrInList(int segNumber, int type, unsigned short **listPtrPtr); // 0x80091F6C

extern struct _G2AnimController_Type *_G2AnimControllerST_RemoveFromList(int segNumber, int type, unsigned short *listPtr); // 0x8009200C

#endif
