#ifndef MONAPI_H
#define MONAPI_H

struct MONAPI_73fake // hashcode: 0x55B1D8D0 (dec: 1437718736)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x5BDF3737 (dec: 1541355319), parent name: 'MONAPI_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x0F237772 (dec: 253982578), parent name: 'MONAPI_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_74fake // hashcode: 0xE1E99304 (dec: -504786172)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x427CB380 (dec: 1115468672), parent name: 'MONAPI_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x5701B288 (dec: 1459729032), parent name: 'MONAPI_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_75fake // hashcode: 0xF76F62C9 (dec: -143695159)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xAB68B16B (dec: -1419202197), parent name: 'MONAPI_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xAE3479DF (dec: -1372292641), parent name: 'MONAPI_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONAPI_76fake // Hashcode: 0x56316C41 (dec: 1446079553)
{
	struct MONAPI_73fake callback; // size=8, offset=0
	struct MONAPI_74fake vector;   // size=12, offset=0
	struct MONAPI_75fake quat;	 // size=16, offset=0
};

union MONAPI_77fake // Hashcode: 0x8FFC132D (dec: -1879305427)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MONAPI_78fake // Hashcode: 0xA905ECF3 (dec: -1459229453)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct MONAPI_79fake // hashcode: 0x1F1A1570 (dec: 521803120)
{
	union MONAPI_78fake size; // size=4, offset=0 //  hashcode: 0xAF3A0732 (dec: -1355151566), parent name: 'MONAPI_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_80fake // hashcode: 0x151CCDB9 (dec: 354209209)
{
	short x;				// size=0, offset=0 //  hashcode: 0xE2D2F37A (dec: -489491590), parent name: 'MONAPI_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x97A8838A (dec: -1750563958), parent name: 'MONAPI_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x0987CD2B (dec: 159894827), parent name: 'MONAPI_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xA5BC12C1 (dec: -1514401087), parent name: 'MONAPI_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xCDDF9E4B (dec: -840982965), parent name: 'MONAPI_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_81fake // hashcode: 0x0F037844 (dec: 251885636)
{
	long index; // size=0, offset=0 //  hashcode: 0xDA6C57F5 (dec: -630433803), parent name: 'MONAPI_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xCF8E32BE (dec: -812764482), parent name: 'MONAPI_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_82fake // hashcode: 0x021E349B (dec: 35533979)
{
	long index; // size=0, offset=0 //  hashcode: 0x6C0DAEAE (dec: 1812836014), parent name: 'MONAPI_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x5593E507 (dec: 1435755783), parent name: 'MONAPI_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_83fake // hashcode: 0x940E957E (dec: -1810983554)
{
	long index; // size=0, offset=0 //  hashcode: 0xBE41A148 (dec: -1102995128), parent name: 'MONAPI_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xF9713FEC (dec: -110018580), parent name: 'MONAPI_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_84fake // hashcode: 0xF684783A (dec: -159090630)
{
	long time;  // size=0, offset=0 //  hashcode: 0xB0748634 (dec: -1334540748), parent name: 'MONAPI_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x8DBB378A (dec: -1917110390), parent name: 'MONAPI_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_85fake // hashcode: 0x6DE7313D (dec: 1843867965)
{
	long action;   // size=0, offset=0 //  hashcode: 0xEC8FCF13 (dec: -326119661), parent name: 'MONAPI_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xFDFE25D7 (dec: -33675817), parent name: 'MONAPI_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_86fake // hashcode: 0x2BDFB4E8 (dec: 736081128)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x5A6120E1 (dec: 1516314849), parent name: 'MONAPI_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x15355E70 (dec: 355819120), parent name: 'MONAPI_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_87fake // hashcode: 0x9FDC1975 (dec: -1612965515)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x082EBD8B (dec: 137280907), parent name: 'MONAPI_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x00DC98AE (dec: 14457006), parent name: 'MONAPI_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_88fake // hashcode: 0x8BFDD9C9 (dec: -1946297911)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x5B2242BC (dec: 1528971964), parent name: 'MONAPI_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xE9753FF6 (dec: -378191882), parent name: 'MONAPI_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_89fake // hashcode: 0xC0ED955D (dec: -1058171555)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x9AD7F250 (dec: -1697123760), parent name: 'MONAPI_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xC2D7ACD8 (dec: -1026052904), parent name: 'MONAPI_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x1B7C5C41 (dec: 461134913), parent name: 'MONAPI_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x29BDC39E (dec: 700302238), parent name: 'MONAPI_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x2356C31E (dec: 592888606), parent name: 'MONAPI_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_90fake // hashcode: 0xEC0D1B06 (dec: -334685434)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x144905B7 (dec: 340329911), parent name: 'MONAPI_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xD1FEEF24 (dec: -771821788), parent name: 'MONAPI_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_91fake // hashcode: 0xABDD066F (dec: -1411578257)
{
	short index;					// size=0, offset=0 //  hashcode: 0xDDCDF1F6 (dec: -573705738), parent name: 'MONAPI_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x59A33C4A (dec: 1503870026), parent name: 'MONAPI_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x13DBD32B (dec: 333173547), parent name: 'MONAPI_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xCBE686ED (dec: -874084627), parent name: 'MONAPI_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_92fake // hashcode: 0x0DEC75BD (dec: 233600445)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x49E09269 (dec: 1239454313), parent name: 'MONAPI_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xCD430470 (dec: -851245968), parent name: 'MONAPI_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xE3D254CD (dec: -472754995), parent name: 'MONAPI_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_93fake // hashcode: 0xF1AAD863 (dec: -240461725)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x2AFF1C56 (dec: 721362006), parent name: 'MONAPI_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x734D696B (dec: 1934453099), parent name: 'MONAPI_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xE9705EAA (dec: -378511702), parent name: 'MONAPI_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x0B4EA9D2 (dec: 189704658), parent name: 'MONAPI_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x89989967 (dec: -1986487961), parent name: 'MONAPI_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x81DADD5E (dec: -2116362914), parent name: 'MONAPI_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xE8272F28 (dec: -400085208), parent name: 'MONAPI_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_94fake // hashcode: 0x6C5A9878 (dec: 1817876600)
{
	long index;  // size=0, offset=0 //  hashcode: 0x57FE59FA (dec: 1476286970), parent name: 'MONAPI_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x69E34413 (dec: 1776501779), parent name: 'MONAPI_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_95fake // hashcode: 0x82544D60 (dec: -2108404384)
{
	short type; // size=0, offset=0 //  hashcode: 0x6209B403 (dec: 1644803075), parent name: 'MONAPI_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x69CAAF30 (dec: 1774890800), parent name: 'MONAPI_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_96fake // hashcode: 0xDFD1FD36 (dec: -539886282)
{
	long time;   // size=0, offset=0 //  hashcode: 0x37888AC5 (dec: 931695301), parent name: 'MONAPI_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x6F9F9FFD (dec: 1872732157), parent name: 'MONAPI_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_97fake // hashcode: 0xCD3A93BD (dec: -851799107)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x9B17DD2E (dec: -1692934866), parent name: 'MONAPI_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xFCE2B293 (dec: -52252013), parent name: 'MONAPI_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_98fake // hashcode: 0xD034646B (dec: -801872789)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x5648873D (dec: 1447593789), parent name: 'MONAPI_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x4F7F50A9 (dec: 1333743785), parent name: 'MONAPI_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_99fake // hashcode: 0xDEB253DB (dec: -558738469)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xDFD074AA (dec: -539986774), parent name: 'MONAPI_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xFEFA89F2 (dec: -17135118), parent name: 'MONAPI_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_100fake // hashcode: 0xD532E6D7 (dec: -718084393)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0xD64B1ECB (dec: -699719989), parent name: 'MONAPI_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x5F05C6E0 (dec: 1594214112), parent name: 'MONAPI_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xE6977685 (dec: -426281339), parent name: 'MONAPI_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xB7318A7E (dec: -1221490050), parent name: 'MONAPI_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_101fake // hashcode: 0x1979BACF (dec: 427408079)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x27C2028E (dec: 667026062), parent name: 'MONAPI_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x9F530413 (dec: -1621949421), parent name: 'MONAPI_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xF8D1EE00 (dec: -120459776), parent name: 'MONAPI_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x8E2CA8B9 (dec: -1909675847), parent name: 'MONAPI_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x78E66C28 (dec: 2028366888), parent name: 'MONAPI_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONAPI_102fake // Hashcode: 0x39821154 (dec: 964825428)
{
	struct MONAPI_79fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	  // size=24, offset=0
	struct MONAPI_80fake teleport;	 // size=16, offset=0
	struct MONAPI_81fake cameraValue;  // size=8, offset=0
	struct MONAPI_82fake miscValue;	// size=8, offset=0
	struct MONAPI_83fake logicValue;   // size=8, offset=0
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
	struct MONAPI_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				   // size=0, offset=0
	long cameraRestore;				   // size=0, offset=0
	struct _BGObject *bgObject;		   // size=24, offset=0
	long value[2];					   // size=8, offset=0
	struct MONAPI_85fake sound;		   // size=12, offset=0
	void *intro;					   // size=0, offset=0
	long deathZ;					   // size=0, offset=0
	struct MONAPI_86fake dsignal;	  // size=8, offset=0
	void *mirror;					   // size=0, offset=0
	long fogNear;					   // size=0, offset=0
	long fogFar;					   // size=0, offset=0
	struct MONAPI_87fake gotoFrame;	// size=8, offset=0
	struct MONAPI_88fake changeModel;  // size=8, offset=0
	void *vmObject;					   // size=0, offset=0
	struct MONAPI_89fake logic;		   // size=8, offset=0
	void *callSignal;				   // size=0, offset=0
	struct _SVector offset;			   // size=8, offset=0
	struct Signal *gotoLabel;		   // size=0, offset=0
	struct Signal *gosubLabel;		   // size=0, offset=0
	struct MONAPI_90fake control;	  // size=8, offset=0
	struct MONAPI_91fake zSignal;	  // size=12, offset=0
	struct MONAPI_92fake StreamLevel;  // size=24, offset=0
	struct MONAPI_93fake shards;	   // size=12, offset=0
	struct MONAPI_94fake cameraSpline; // size=8, offset=0
	struct MONAPI_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				   // size=0, offset=0
	struct MONAPI_96fake introFX;	  // size=8, offset=0
	struct MONAPI_97fake introActive;  // size=8, offset=0
	struct MONAPI_98fake levelChange;  // size=18, offset=0
	long blendStart;				   // size=0, offset=0
	struct MONAPI_99fake setTimes;	 // size=8, offset=0
	struct MONAPI_100fake color;	   // size=4, offset=0
	struct MONAPI_101fake print;	   // size=12, offset=0
	long slideAngle;				   // size=0, offset=0
};

union MONAPI_103fake // Hashcode: 0x77BD713F (dec: 2008903999)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union MONAPI_108fake // Hashcode: 0x5FD6C090 (dec: 1607909520)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct MONAPI_110fake // hashcode: 0x96919371 (dec: -1768844431)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x77500051 (dec: 2001731665), parent name: 'MONAPI_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xECEBD2AF (dec: -320089425), parent name: 'MONAPI_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x726308A2 (dec: 1919092898), parent name: 'MONAPI_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x7D6906A4 (dec: 2104034980), parent name: 'MONAPI_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x49D2B373 (dec: 1238545267), parent name: 'MONAPI_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x513C8139 (dec: 1362919737), parent name: 'MONAPI_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xB9307E63 (dec: -1188004253), parent name: 'MONAPI_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_111fake // hashcode: 0x5BEEB92E (dec: 1542371630)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x26393F18 (dec: 641285912), parent name: 'MONAPI_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xCB5C2F87 (dec: -883150969), parent name: 'MONAPI_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xA72CA235 (dec: -1490247115), parent name: 'MONAPI_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_112fake // hashcode: 0xE258E291 (dec: -497491311)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x94669F74 (dec: -1805213836), parent name: 'MONAPI_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x36C07446 (dec: 918582342), parent name: 'MONAPI_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xEF9E1DF8 (dec: -274850312), parent name: 'MONAPI_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x93272D92 (dec: -1826148974), parent name: 'MONAPI_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x2AD5CF53 (dec: 718655315), parent name: 'MONAPI_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_113fake // hashcode: 0x716F81F3 (dec: 1903133171)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x21BA4BBF (dec: 565857215), parent name: 'MONAPI_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x8F5B41F3 (dec: -1889844749), parent name: 'MONAPI_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0xE0B78FF1 (dec: -524840975), parent name: 'MONAPI_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x3E5338BA (dec: 1045641402), parent name: 'MONAPI_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xE7E70F90 (dec: -404287600), parent name: 'MONAPI_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_114fake // hashcode: 0x26233514 (dec: 639841556)
{
	struct MONAPI_110fake Cinematic; // size=28, offset=0 //  hashcode: 0xA9E0BC68 (dec: -1444889496), parent name: 'MONAPI_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MONAPI_111fake Idle;		 // size=20, offset=28 //  hashcode: 0x4622EE64 (dec: 1176694372), parent name: 'MONAPI_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MONAPI_112fake Behind;	// size=28, offset=48 //  hashcode: 0xC117E3B4 (dec: -1055398988), parent name: 'MONAPI_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MONAPI_113fake Follow;	// size=20, offset=76 //  hashcode: 0x6E405DF9 (dec: 1849712121), parent name: 'MONAPI_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evMonsterHitTerrainData // hashcode: 0x4CD2E030 (dec: 1288888368)
{
	struct _TFace *tface;  // size=12, offset=0 //  hashcode: 0x559AE552 (dec: 1436214610), parent name: 'evMonsterHitTerrainData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Normal normal; // size=8, offset=4 //  hashcode: 0x0B5BA367 (dec: 190554983), parent name: 'evMonsterHitTerrainData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short faceFlags;	   // size=0, offset=12 //  hashcode: 0x55ACAB8A (dec: 1437379466), parent name: 'evMonsterHitTerrainData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short bspFlags;		   // size=0, offset=14 //  hashcode: 0x04825007 (dec: 75649031), parent name: 'evMonsterHitTerrainData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evMonsterHitObjectData // hashcode: 0xB7192556 (dec: -1223088810)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0xB91B731D (dec: -1189383395), parent name: 'evMonsterHitObjectData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int hitType;				// size=0, offset=4 //  hashcode: 0x23159BF2 (dec: 588618738), parent name: 'evMonsterHitObjectData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONAPI_201fake // Hashcode: 0x68ED3057 (dec: 1760374871)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct MONAPI_222fake // hashcode: 0x645562E4 (dec: 1683317476)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x14CE22E5 (dec: 349053669), parent name: 'MONAPI_222fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x683B59E4 (dec: 1748720100), parent name: 'MONAPI_222fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONAPI_223fake // hashcode: 0xD927EC4B (dec: -651695029)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0xE3B0ED79 (dec: -474944135), parent name: 'MONAPI_223fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x801CC912 (dec: -2145597166), parent name: 'MONAPI_223fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x3164273C (dec: 828647228), parent name: 'MONAPI_223fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x02917776 (dec: 43087734), parent name: 'MONAPI_223fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0xF134647C (dec: -248224644), parent name: 'MONAPI_223fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x5C534A42 (dec: 1548962370), parent name: 'MONAPI_223fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONAPI_224fake // Hashcode: 0xE65C0385 (dec: -430177403)
{
	struct MONAPI_222fake flame; // size=8, offset=0
	struct MONAPI_223fake phys;  // size=12, offset=0
};

struct _MonsterSaveInfo // hashcode: 0x3088BC75 (dec: 814267509)
{
	long mvFlags;					// size=0, offset=0 //  hashcode: 0x5259468D (dec: 1381582477), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long auxFlags;					// size=0, offset=4 //  hashcode: 0x90F2B2F1 (dec: -1863142671), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soulID;					// size=0, offset=8 //  hashcode: 0xD7ABD5E6 (dec: -676604442), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soulJuice;				// size=0, offset=10 //  hashcode: 0x3142A27D (dec: 826450557), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned int age : 3;			// offset=12.0 //  hashcode: 0x47266391 (dec: 1193698193), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned int state : 6;			// offset=12.3 //  hashcode: 0xDEA78530 (dec: -559446736), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned int behaviorState : 5; // offset=13.1 //  hashcode: 0x948FA7BF (dec: -1802524737), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned int anim : 6;			// offset=13.6 //  hashcode: 0x5CFBC032 (dec: 1560002610), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned int animLooping : 1;   // offset=14.4 //  hashcode: 0x9558AB72 (dec: -1789351054), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned int causeOfDeath : 3;  // offset=14.5 //  hashcode: 0x4A49C3FE (dec: 1246348286), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct evMonsterHitTerrainData evMonsterHitTerrainData;

typedef struct evMonsterHitObjectData evMonsterHitObjectData;

typedef struct _MonsterSaveInfo MonsterSaveInfo;

extern void MonsterProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007DA80

extern void MonsterInit(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007DBB8

extern void SendHitObject(struct _Instance *instance, struct _Instance *hit, int type); // 0x8007DDC0

extern void MonsterCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007DE94

extern void MonsterAdditionalCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007E3A8

extern unsigned long MonsterQuery(struct _Instance *instance, unsigned long query); // 0x8007E3D8

extern void MonsterMessage(struct _Instance *instance, unsigned long message, unsigned long data); // 0x8007E638

extern void AnimDistanceAndVel(struct Object *object, struct _MonsterAnim *mAnim); // 0x8007E900

extern void TranslateAnimList(struct Object *object, struct _MonsterAnim *animList, int numAnims); // 0x8007EA68

extern void MonsterTranslateAnim(struct Object *object); // 0x8007EB64

extern void MonsterRelocateTune(struct Object *object, long offset); // 0x8007ED1C

extern void MonsterRelocateInstanceObject(struct _Instance *instance, long offset); // 0x8007EF38

extern void MONAPI_TurnHead(struct _Instance *instance, short *rotx, short *rotz, struct GameTracker *gameTracker); // 0x8007F05C

extern void MONAPI_SetLookAround(struct _Instance *instance); // 0x8007F0D8

extern void MONAPI_ResetLookAround(struct _Instance *instance); // 0x8007F108

extern long MONAPI_OkToLookAround(struct _Instance *instance); // 0x8007F138

extern void MONAPI_DeleteRegen(struct _MONAPI_Regenerator *regen); // 0x8007F14C

extern void MONAPI_ProcessGenerator(); // 0x8007F198

extern void MONAPI_AddToGenerator(struct _Instance *instance); // 0x8007F2D8

extern void MONAPI_CheckGenerator(struct _Instance *instance); // 0x8007F378

#endif
