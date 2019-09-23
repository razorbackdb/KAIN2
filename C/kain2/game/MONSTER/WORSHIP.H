#ifndef WORSHIP_H
#define WORSHIP_H

extern struct _MonsterFunctionTable WORSHIP_FunctionTable; // offset 0x800CF714

extern struct _MonsterStateChoice WORSHIP_StateChoiceTable[5]; // offset 0x800CABF0

struct WORSHIP_73fake // hashcode: 0x2C95F391 (dec: 748024721)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x28684EFC (dec: 677924604), parent name: 'WORSHIP_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x24346062 (dec: 607412322), parent name: 'WORSHIP_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_74fake // hashcode: 0xF748A279 (dec: -146234759)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xC6690A87 (dec: -966194553), parent name: 'WORSHIP_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xA1C32FFE (dec: -1581043714), parent name: 'WORSHIP_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_75fake // hashcode: 0xF60CDE4C (dec: -166928820)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xAFD6C1C9 (dec: -1344880183), parent name: 'WORSHIP_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x15DA69E1 (dec: 366635489), parent name: 'WORSHIP_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union WORSHIP_76fake // Hashcode: 0x67B6B44E (dec: 1740026958)
{
	struct WORSHIP_73fake callback; // size=8, offset=0
	struct WORSHIP_74fake vector;   // size=12, offset=0
	struct WORSHIP_75fake quat;		// size=16, offset=0
};

union WORSHIP_77fake // Hashcode: 0x11B9D34C (dec: 297390924)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union WORSHIP_78fake // Hashcode: 0x6CEBFF28 (dec: 1827405608)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct WORSHIP_79fake // hashcode: 0xED9CCB58 (dec: -308491432)
{
	union WORSHIP_78fake size; // size=4, offset=0 //  hashcode: 0xF53252D0 (dec: -181251376), parent name: 'WORSHIP_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_80fake // hashcode: 0x6CA444D8 (dec: 1822704856)
{
	short x;				// size=0, offset=0 //  hashcode: 0x61DA29E7 (dec: 1641687527), parent name: 'WORSHIP_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x401CBFA8 (dec: 1075625896), parent name: 'WORSHIP_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xEF96B65D (dec: -275335587), parent name: 'WORSHIP_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x9EE17715 (dec: -1629391083), parent name: 'WORSHIP_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xB2806489 (dec: -1300208503), parent name: 'WORSHIP_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_81fake // hashcode: 0xC9954E88 (dec: -912961912)
{
	long index; // size=0, offset=0 //  hashcode: 0x22A2D7D3 (dec: 581097427), parent name: 'WORSHIP_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x6C626EB8 (dec: 1818390200), parent name: 'WORSHIP_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_82fake // hashcode: 0x18EA8793 (dec: 418023315)
{
	long index; // size=0, offset=0 //  hashcode: 0x900FB5A7 (dec: -1878018649), parent name: 'WORSHIP_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x1F400FC5 (dec: 524292037), parent name: 'WORSHIP_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_83fake // hashcode: 0x678D8248 (dec: 1737327176)
{
	long index; // size=0, offset=0 //  hashcode: 0xD479F9B2 (dec: -730203726), parent name: 'WORSHIP_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x42695E07 (dec: 1114201607), parent name: 'WORSHIP_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_84fake // hashcode: 0x076CAEEA (dec: 124563178)
{
	long time;  // size=0, offset=0 //  hashcode: 0x3971E321 (dec: 963765025), parent name: 'WORSHIP_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xEE715910 (dec: -294561520), parent name: 'WORSHIP_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_85fake // hashcode: 0x5B48EF9C (dec: 1531506588)
{
	long action;   // size=0, offset=0 //  hashcode: 0xFE4E81FA (dec: -28409350), parent name: 'WORSHIP_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x08C28EC3 (dec: 146968259), parent name: 'WORSHIP_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_86fake // hashcode: 0x902D2AED (dec: -1876088083)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xC65A192E (dec: -967173842), parent name: 'WORSHIP_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xAAF8324A (dec: -1426574774), parent name: 'WORSHIP_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_87fake // hashcode: 0x6CEF805B (dec: 1827635291)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x112AD6F1 (dec: 288020209), parent name: 'WORSHIP_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x4BF06BD6 (dec: 1274047446), parent name: 'WORSHIP_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_88fake // hashcode: 0x79CEBA6B (dec: 2043591275)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xF28E25E7 (dec: -225565209), parent name: 'WORSHIP_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xB0162753 (dec: -1340725421), parent name: 'WORSHIP_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_89fake // hashcode: 0x139F9A7A (dec: 329226874)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x1C76D458 (dec: 477549656), parent name: 'WORSHIP_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x6A9F11B7 (dec: 1788809655), parent name: 'WORSHIP_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xCD730B3B (dec: -848098501), parent name: 'WORSHIP_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x106523F0 (dec: 275063792), parent name: 'WORSHIP_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x114F9E9B (dec: 290430619), parent name: 'WORSHIP_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_90fake // hashcode: 0xA0A78CA8 (dec: -1599632216)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x5C6854D7 (dec: 1550341335), parent name: 'WORSHIP_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x44328891 (dec: 1144162449), parent name: 'WORSHIP_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_91fake // hashcode: 0xD98CC943 (dec: -645084861)
{
	short index;					// size=0, offset=0 //  hashcode: 0xE0578B50 (dec: -531133616), parent name: 'WORSHIP_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x6B868FB4 (dec: 1803980724), parent name: 'WORSHIP_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xD40A3D2D (dec: -737526483), parent name: 'WORSHIP_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x730BBF8A (dec: 1930149770), parent name: 'WORSHIP_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_92fake // hashcode: 0x058645C3 (dec: 92685763)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x1A63A7CA (dec: 442738634), parent name: 'WORSHIP_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x368EF6EE (dec: 915338990), parent name: 'WORSHIP_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x3993397B (dec: 965949819), parent name: 'WORSHIP_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_93fake // hashcode: 0xCA4B59DB (dec: -901031461)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x001F649E (dec: 2057374), parent name: 'WORSHIP_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x384FC6C5 (dec: 944752325), parent name: 'WORSHIP_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x463CB8DC (dec: 1178384604), parent name: 'WORSHIP_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x66B4D50C (dec: 1723127052), parent name: 'WORSHIP_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xF3750C24 (dec: -210432988), parent name: 'WORSHIP_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xC0770474 (dec: -1065941900), parent name: 'WORSHIP_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xEF7D9A4E (dec: -276981170), parent name: 'WORSHIP_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_94fake // hashcode: 0x8EC351CD (dec: -1899802163)
{
	long index;  // size=0, offset=0 //  hashcode: 0x8040A857 (dec: -2143246249), parent name: 'WORSHIP_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x3A841FC0 (dec: 981737408), parent name: 'WORSHIP_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_95fake // hashcode: 0xEC670F03 (dec: -328790269)
{
	short type; // size=0, offset=0 //  hashcode: 0x0B7E6389 (dec: 192832393), parent name: 'WORSHIP_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x1ED0C6EF (dec: 516998895), parent name: 'WORSHIP_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_96fake // hashcode: 0xB8A250A8 (dec: -1197322072)
{
	long time;   // size=0, offset=0 //  hashcode: 0x2F027D01 (dec: 788692225), parent name: 'WORSHIP_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x2D33296C (dec: 758327660), parent name: 'WORSHIP_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_97fake // hashcode: 0xF12FFD43 (dec: -248513213)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x4AEA8240 (dec: 1256882752), parent name: 'WORSHIP_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xC6791141 (dec: -965144255), parent name: 'WORSHIP_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_98fake // hashcode: 0x120AD29C (dec: 302699164)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xA5966459 (dec: -1516870567), parent name: 'WORSHIP_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x64908B8C (dec: 1687194508), parent name: 'WORSHIP_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_99fake // hashcode: 0xA78469B0 (dec: -1484494416)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xCB175B59 (dec: -887661735), parent name: 'WORSHIP_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xBECA4B2E (dec: -1094038738), parent name: 'WORSHIP_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_100fake // hashcode: 0x5A083986 (dec: 1510488454)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x82D3535E (dec: -2100079778), parent name: 'WORSHIP_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xD01A5C4A (dec: -803578806), parent name: 'WORSHIP_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x8F90C393 (dec: -1886338157), parent name: 'WORSHIP_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x6D086449 (dec: 1829266505), parent name: 'WORSHIP_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_101fake // hashcode: 0x35559716 (dec: 894801686)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x0A0A524E (dec: 168448590), parent name: 'WORSHIP_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x8549FAE4 (dec: -2058749212), parent name: 'WORSHIP_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xD5F7B6A2 (dec: -705186142), parent name: 'WORSHIP_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x4B2F8A47 (dec: 1261406791), parent name: 'WORSHIP_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x7E1A67B2 (dec: 2115659698), parent name: 'WORSHIP_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union WORSHIP_102fake // Hashcode: 0xC6380D91 (dec: -969405039)
{
	struct WORSHIP_79fake misc[3];		// size=12, offset=0
	struct _CameraKey *cameraKey;		// size=24, offset=0
	struct WORSHIP_80fake teleport;		// size=16, offset=0
	struct WORSHIP_81fake cameraValue;  // size=8, offset=0
	struct WORSHIP_82fake miscValue;	// size=8, offset=0
	struct WORSHIP_83fake logicValue;   // size=8, offset=0
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
	struct WORSHIP_84fake cameraShake;  // size=8, offset=0
	long cameraSave;					// size=0, offset=0
	long cameraRestore;					// size=0, offset=0
	struct _BGObject *bgObject;			// size=24, offset=0
	long value[2];						// size=8, offset=0
	struct WORSHIP_85fake sound;		// size=12, offset=0
	void *intro;						// size=0, offset=0
	long deathZ;						// size=0, offset=0
	struct WORSHIP_86fake dsignal;		// size=8, offset=0
	void *mirror;						// size=0, offset=0
	long fogNear;						// size=0, offset=0
	long fogFar;						// size=0, offset=0
	struct WORSHIP_87fake gotoFrame;	// size=8, offset=0
	struct WORSHIP_88fake changeModel;  // size=8, offset=0
	void *vmObject;						// size=0, offset=0
	struct WORSHIP_89fake logic;		// size=8, offset=0
	void *callSignal;					// size=0, offset=0
	struct _SVector offset;				// size=8, offset=0
	struct Signal *gotoLabel;			// size=0, offset=0
	struct Signal *gosubLabel;			// size=0, offset=0
	struct WORSHIP_90fake control;		// size=8, offset=0
	struct WORSHIP_91fake zSignal;		// size=12, offset=0
	struct WORSHIP_92fake StreamLevel;  // size=24, offset=0
	struct WORSHIP_93fake shards;		// size=12, offset=0
	struct WORSHIP_94fake cameraSpline; // size=8, offset=0
	struct WORSHIP_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;					// size=0, offset=0
	struct WORSHIP_96fake introFX;		// size=8, offset=0
	struct WORSHIP_97fake introActive;  // size=8, offset=0
	struct WORSHIP_98fake levelChange;  // size=18, offset=0
	long blendStart;					// size=0, offset=0
	struct WORSHIP_99fake setTimes;		// size=8, offset=0
	struct WORSHIP_100fake color;		// size=4, offset=0
	struct WORSHIP_101fake print;		// size=12, offset=0
	long slideAngle;					// size=0, offset=0
};

union WORSHIP_103fake // Hashcode: 0xA7764D67 (dec: -1485419161)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union WORSHIP_108fake // Hashcode: 0xF0B0B296 (dec: -256855402)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct WORSHIP_110fake // hashcode: 0xFA76F5A4 (dec: -92867164)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xD274CCB8 (dec: -764097352), parent name: 'WORSHIP_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x9B5BCAF6 (dec: -1688483082), parent name: 'WORSHIP_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x905074BC (dec: -1873775428), parent name: 'WORSHIP_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xE5549FFE (dec: -447438850), parent name: 'WORSHIP_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x334E30C7 (dec: 860762311), parent name: 'WORSHIP_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x4779EE97 (dec: 1199173271), parent name: 'WORSHIP_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x91049F79 (dec: -1861968007), parent name: 'WORSHIP_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_111fake // hashcode: 0x90C3FC97 (dec: -1866204009)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x6BB73792 (dec: 1807169426), parent name: 'WORSHIP_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xF80CE32A (dec: -133373142), parent name: 'WORSHIP_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x55214AE3 (dec: 1428245219), parent name: 'WORSHIP_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_112fake // hashcode: 0x2152F835 (dec: 559085621)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x82C8963A (dec: -2100783558), parent name: 'WORSHIP_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x7492A6D5 (dec: 1955768021), parent name: 'WORSHIP_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x85E82871 (dec: -2048382863), parent name: 'WORSHIP_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xF93D6704 (dec: -113416444), parent name: 'WORSHIP_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x001BB93E (dec: 1816894), parent name: 'WORSHIP_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_113fake // hashcode: 0x9F4EA509 (dec: -1622235895)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xA18E6EE3 (dec: -1584501021), parent name: 'WORSHIP_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x4DA78F10 (dec: 1302826768), parent name: 'WORSHIP_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x1DBE402F (dec: 499007535), parent name: 'WORSHIP_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xA997E17C (dec: -1449664132), parent name: 'WORSHIP_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x2D637980 (dec: 761493888), parent name: 'WORSHIP_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_114fake // hashcode: 0x92B54E7B (dec: -1833611653)
{
	struct WORSHIP_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x0839A2DE (dec: 137994974), parent name: 'WORSHIP_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct WORSHIP_111fake Idle;	  // size=20, offset=28 //  hashcode: 0x32E2C9B5 (dec: 853723573), parent name: 'WORSHIP_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct WORSHIP_112fake Behind;	// size=28, offset=48 //  hashcode: 0xD38AB677 (dec: -745884041), parent name: 'WORSHIP_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct WORSHIP_113fake Follow;	// size=20, offset=76 //  hashcode: 0x143C98F0 (dec: 339515632), parent name: 'WORSHIP_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union WORSHIP_193fake // Hashcode: 0xB9C6ED01 (dec: -1178145535)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct WORSHIP_217fake // hashcode: 0xC8CB19CA (dec: -926213686)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x559F4176 (dec: 1436500342), parent name: 'WORSHIP_217fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x010FCFB9 (dec: 17813433), parent name: 'WORSHIP_217fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WORSHIP_218fake // hashcode: 0xD8DE4543 (dec: -656521917)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x5BEA0EDA (dec: 1542065882), parent name: 'WORSHIP_218fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x145078F2 (dec: 340818162), parent name: 'WORSHIP_218fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x99658F56 (dec: -1721397418), parent name: 'WORSHIP_218fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0xBF8E5B30 (dec: -1081189584), parent name: 'WORSHIP_218fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x7231BA08 (dec: 1915861512), parent name: 'WORSHIP_218fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x269EC254 (dec: 647938644), parent name: 'WORSHIP_218fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union WORSHIP_219fake // Hashcode: 0xE4518F0F (dec: -464417009)
{
	struct WORSHIP_217fake flame; // size=8, offset=0
	struct WORSHIP_218fake phys;  // size=12, offset=0
};

extern void WORSHIP_Init(struct _Instance *instance); // 0x8008EE08

extern void WORSHIP_CombatEntry(struct _Instance *instance); // 0x8008EEA8

#endif
