#ifndef REAVER_H
#define REAVER_H

static short FireReaverFlag; // offset 0x800D48B8

struct REAVER_73fake // hashcode: 0x573154C9 (dec: 1462850761)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xD3FFDAC8 (dec: -738207032), parent name: 'REAVER_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0xD37C71F8 (dec: -746819080), parent name: 'REAVER_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_74fake // hashcode: 0x5F206A2E (dec: 1595959854)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xF4E53897 (dec: -186304361), parent name: 'REAVER_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x2EB2F379 (dec: 783479673), parent name: 'REAVER_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_75fake // hashcode: 0x02A77AAA (dec: 44530346)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xC60C467C (dec: -972274052), parent name: 'REAVER_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xAC459394 (dec: -1404726380), parent name: 'REAVER_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union REAVER_76fake // Hashcode: 0x4667F1DF (dec: 1181217247)
{
	struct REAVER_73fake callback; // size=8, offset=0
	struct REAVER_74fake vector;   // size=12, offset=0
	struct REAVER_75fake quat;	 // size=16, offset=0
};

union REAVER_77fake // Hashcode: 0x1E75973B (dec: 511022907)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union REAVER_78fake // Hashcode: 0x59588D7A (dec: 1498975610)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct REAVER_79fake // hashcode: 0x7D98CD48 (dec: 2107166024)
{
	union REAVER_78fake size; // size=4, offset=0 //  hashcode: 0x70A9FB97 (dec: 1890188183), parent name: 'REAVER_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_80fake // hashcode: 0xEFF1E486 (dec: -269359994)
{
	short x;				// size=0, offset=0 //  hashcode: 0xFA860757 (dec: -91879593), parent name: 'REAVER_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xD1A6EEEF (dec: -777589009), parent name: 'REAVER_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x8EA80E9E (dec: -1901588834), parent name: 'REAVER_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x03247E94 (dec: 52723348), parent name: 'REAVER_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xFF3DA94C (dec: -12736180), parent name: 'REAVER_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_81fake // hashcode: 0xBE26611A (dec: -1104781030)
{
	long index; // size=0, offset=0 //  hashcode: 0x24A0F56F (dec: 614528367), parent name: 'REAVER_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xB1D4AE1B (dec: -1311461861), parent name: 'REAVER_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_82fake // hashcode: 0x7436C68D (dec: 1949746829)
{
	long index; // size=0, offset=0 //  hashcode: 0xE8716F55 (dec: -395219115), parent name: 'REAVER_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xE6EF19B2 (dec: -420537934), parent name: 'REAVER_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_83fake // hashcode: 0x928C321E (dec: -1836305890)
{
	long index; // size=0, offset=0 //  hashcode: 0x0B4441CB (dec: 189022667), parent name: 'REAVER_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x59229C24 (dec: 1495440420), parent name: 'REAVER_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_84fake // hashcode: 0x564E04A9 (dec: 1447953577)
{
	long time;  // size=0, offset=0 //  hashcode: 0x7A11D433 (dec: 2047988787), parent name: 'REAVER_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xC59F0897 (dec: -979433321), parent name: 'REAVER_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_85fake // hashcode: 0x9D198CC9 (dec: -1659269943)
{
	long action;   // size=0, offset=0 //  hashcode: 0x91FFD1CB (dec: -1845505589), parent name: 'REAVER_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xC17FD276 (dec: -1048587658), parent name: 'REAVER_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_86fake // hashcode: 0x9109CC89 (dec: -1861628791)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xB42473B0 (dec: -1272679504), parent name: 'REAVER_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xD2411A7F (dec: -767485313), parent name: 'REAVER_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_87fake // hashcode: 0xC2BF0C97 (dec: -1027666793)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xE3E35C5E (dec: -471638946), parent name: 'REAVER_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x30C7BDBB (dec: 818396603), parent name: 'REAVER_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_88fake // hashcode: 0xAFD3336E (dec: -1345113234)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x11B7D923 (dec: 297261347), parent name: 'REAVER_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x9AF0AE93 (dec: -1695502701), parent name: 'REAVER_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_89fake // hashcode: 0xD11500EE (dec: -787152658)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x23B3F5DF (dec: 598996447), parent name: 'REAVER_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x474ACD7F (dec: 1196084607), parent name: 'REAVER_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x2FFCA7B9 (dec: 805087161), parent name: 'REAVER_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x11093683 (dec: 285816451), parent name: 'REAVER_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x627254DF (dec: 1651659999), parent name: 'REAVER_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_90fake // hashcode: 0x5E8F5876 (dec: 1586452598)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xB7C430BD (dec: -1211879235), parent name: 'REAVER_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x2999963D (dec: 697931325), parent name: 'REAVER_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_91fake // hashcode: 0x0E7EE6F6 (dec: 243197686)
{
	short index;					// size=0, offset=0 //  hashcode: 0xAF9A7B6D (dec: -1348830355), parent name: 'REAVER_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x2D896597 (dec: 763979159), parent name: 'REAVER_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x17B458C2 (dec: 397695170), parent name: 'REAVER_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x99901E77 (dec: -1718608265), parent name: 'REAVER_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_92fake // hashcode: 0x3EBD5B09 (dec: 1052597001)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xF492CB8A (dec: -191706230), parent name: 'REAVER_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x029232C7 (dec: 43135687), parent name: 'REAVER_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xE59A863A (dec: -442857926), parent name: 'REAVER_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_93fake // hashcode: 0xDB1CEA08 (dec: -618862072)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xECC688E5 (dec: -322533147), parent name: 'REAVER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x13106186 (dec: 319840646), parent name: 'REAVER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xB00E4034 (dec: -1341243340), parent name: 'REAVER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xE33627B9 (dec: -482990151), parent name: 'REAVER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x6F2B77BA (dec: 1865119674), parent name: 'REAVER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x09559CD1 (dec: 156605649), parent name: 'REAVER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xE1DBEA05 (dec: -505681403), parent name: 'REAVER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_94fake // hashcode: 0xDF4BFB70 (dec: -548668560)
{
	long index;  // size=0, offset=0 //  hashcode: 0xB01999B2 (dec: -1340499534), parent name: 'REAVER_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xC33B5DF6 (dec: -1019519498), parent name: 'REAVER_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_95fake // hashcode: 0x9A5F812D (dec: -1705017043)
{
	short type; // size=0, offset=0 //  hashcode: 0xF2EFA324 (dec: -219176156), parent name: 'REAVER_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x711A6658 (dec: 1897555544), parent name: 'REAVER_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_96fake // hashcode: 0xE987E9CC (dec: -376968756)
{
	long time;   // size=0, offset=0 //  hashcode: 0xA8B704FA (dec: -1464400646), parent name: 'REAVER_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x236126DE (dec: 593569502), parent name: 'REAVER_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_97fake // hashcode: 0xA50A00AE (dec: -1526071122)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xD27C7E3B (dec: -763593157), parent name: 'REAVER_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xBCF78ACC (dec: -1124627764), parent name: 'REAVER_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_98fake // hashcode: 0x9A1654A0 (dec: -1709812576)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x9130F7FE (dec: -1859061762), parent name: 'REAVER_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x8BAFCE98 (dec: -1951412584), parent name: 'REAVER_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_99fake // hashcode: 0xDE11696F (dec: -569284241)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xC9BDEE15 (dec: -910299627), parent name: 'REAVER_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xE14E63F3 (dec: -514956301), parent name: 'REAVER_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_100fake // hashcode: 0xEE2BB50A (dec: -299125494)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0xCF252896 (dec: -819648362), parent name: 'REAVER_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x7405EEB8 (dec: 1946545848), parent name: 'REAVER_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x50A70C2E (dec: 1353124910), parent name: 'REAVER_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x7A6F0ECD (dec: 2054098637), parent name: 'REAVER_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_101fake // hashcode: 0x2C36221A (dec: 741745178)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x9C61C4A0 (dec: -1671314272), parent name: 'REAVER_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x90EA833C (dec: -1863679172), parent name: 'REAVER_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xF24AB035 (dec: -229986251), parent name: 'REAVER_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x10784AF6 (dec: 276318966), parent name: 'REAVER_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x897A90D3 (dec: -1988456237), parent name: 'REAVER_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union REAVER_102fake // Hashcode: 0x60D96612 (dec: 1624860178)
{
	struct REAVER_79fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	  // size=24, offset=0
	struct REAVER_80fake teleport;	 // size=16, offset=0
	struct REAVER_81fake cameraValue;  // size=8, offset=0
	struct REAVER_82fake miscValue;	// size=8, offset=0
	struct REAVER_83fake logicValue;   // size=8, offset=0
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
	struct REAVER_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				   // size=0, offset=0
	long cameraRestore;				   // size=0, offset=0
	struct _BGObject *bgObject;		   // size=24, offset=0
	long value[2];					   // size=8, offset=0
	struct REAVER_85fake sound;		   // size=12, offset=0
	void *intro;					   // size=0, offset=0
	long deathZ;					   // size=0, offset=0
	struct REAVER_86fake dsignal;	  // size=8, offset=0
	void *mirror;					   // size=0, offset=0
	long fogNear;					   // size=0, offset=0
	long fogFar;					   // size=0, offset=0
	struct REAVER_87fake gotoFrame;	// size=8, offset=0
	struct REAVER_88fake changeModel;  // size=8, offset=0
	void *vmObject;					   // size=0, offset=0
	struct REAVER_89fake logic;		   // size=8, offset=0
	void *callSignal;				   // size=0, offset=0
	struct _SVector offset;			   // size=8, offset=0
	struct Signal *gotoLabel;		   // size=0, offset=0
	struct Signal *gosubLabel;		   // size=0, offset=0
	struct REAVER_90fake control;	  // size=8, offset=0
	struct REAVER_91fake zSignal;	  // size=12, offset=0
	struct REAVER_92fake StreamLevel;  // size=24, offset=0
	struct REAVER_93fake shards;	   // size=12, offset=0
	struct REAVER_94fake cameraSpline; // size=8, offset=0
	struct REAVER_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				   // size=0, offset=0
	struct REAVER_96fake introFX;	  // size=8, offset=0
	struct REAVER_97fake introActive;  // size=8, offset=0
	struct REAVER_98fake levelChange;  // size=18, offset=0
	long blendStart;				   // size=0, offset=0
	struct REAVER_99fake setTimes;	 // size=8, offset=0
	struct REAVER_100fake color;	   // size=4, offset=0
	struct REAVER_101fake print;	   // size=12, offset=0
	long slideAngle;				   // size=0, offset=0
};

union REAVER_103fake // Hashcode: 0x3D792F65 (dec: 1031352165)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union REAVER_108fake // Hashcode: 0x8D81DA67 (dec: -1920869785)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct REAVER_110fake // hashcode: 0x2C843BA9 (dec: 746863529)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xAC60FA0F (dec: -1402930673), parent name: 'REAVER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x9B7BE176 (dec: -1686380170), parent name: 'REAVER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0xEF27A603 (dec: -282614269), parent name: 'REAVER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x359C75A9 (dec: 899446185), parent name: 'REAVER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x4084216E (dec: 1082401134), parent name: 'REAVER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xAEBDC16E (dec: -1363295890), parent name: 'REAVER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x75DBA37D (dec: 1977328509), parent name: 'REAVER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_111fake // hashcode: 0xA37C2953 (dec: -1552144045)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x760649A9 (dec: 1980123561), parent name: 'REAVER_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x06101A14 (dec: 101718548), parent name: 'REAVER_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x522122C0 (dec: 1377903296), parent name: 'REAVER_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_112fake // hashcode: 0x797348DB (dec: 2037598427)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xF00CA24F (dec: -267607473), parent name: 'REAVER_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xD30AB276 (dec: -754273674), parent name: 'REAVER_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xBB1C176F (dec: -1155786897), parent name: 'REAVER_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x4D2358FF (dec: 1294162175), parent name: 'REAVER_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x5E0B7BFB (dec: 1577810939), parent name: 'REAVER_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_113fake // hashcode: 0x2516F660 (dec: 622261856)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x784AB94A (dec: 2018163018), parent name: 'REAVER_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x63BEC012 (dec: 1673445394), parent name: 'REAVER_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x10D4999E (dec: 282368414), parent name: 'REAVER_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x8619F493 (dec: -2045119341), parent name: 'REAVER_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x3EF68885 (dec: 1056344197), parent name: 'REAVER_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_114fake // hashcode: 0x25B74FFD (dec: 632770557)
{
	struct REAVER_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x3E24420A (dec: 1042563594), parent name: 'REAVER_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct REAVER_111fake Idle;		 // size=20, offset=28 //  hashcode: 0xD6C76E98 (dec: -691573096), parent name: 'REAVER_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct REAVER_112fake Behind;	// size=28, offset=48 //  hashcode: 0xF6C1A476 (dec: -155081610), parent name: 'REAVER_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct REAVER_113fake Follow;	// size=20, offset=76 //  hashcode: 0x2C01058B (dec: 738264459), parent name: 'REAVER_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_185fake // hashcode: 0x5CDE95A5 (dec: 1558091173)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0xEE24E1C0 (dec: -299572800), parent name: 'REAVER_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x015AE246 (dec: 22733382), parent name: 'REAVER_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct REAVER_186fake // hashcode: 0x8D467655 (dec: -1924762027)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x09869696 (dec: 159815318), parent name: 'REAVER_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x7BC2669C (dec: 2076337820), parent name: 'REAVER_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x71C47E12 (dec: 1908702738), parent name: 'REAVER_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x6BF6E49D (dec: 1811342493), parent name: 'REAVER_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0xC6F4C12F (dec: -957038289), parent name: 'REAVER_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x7B1ECC63 (dec: 2065615971), parent name: 'REAVER_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union REAVER_187fake // Hashcode: 0xC560F585 (dec: -983501435)
{
	struct REAVER_185fake flame; // size=8, offset=0
	struct REAVER_186fake phys;  // size=12, offset=0
};

union REAVER_213fake // Hashcode: 0x859607D9 (dec: -2053765159)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

extern void SoulReaverInit(struct _Instance *instance, struct GameTracker *gameTracker); // 0x80079D48

extern void SoulReaverCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x80079DE8

extern void SoulReaverProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x80079F58

extern void CollideReaverProjectile(struct _Instance *instance, struct GameTracker *gameTracker); // 0x80079FA4

extern unsigned long SoulReaverQuery(struct _Instance *instance, unsigned long query); // 0x8007A100

extern void SoulReaverImbue(struct _Instance *instance, int number); // 0x8007A184

extern void SoulReaverCharge(struct _Instance *instance, struct __ReaverData *data); // 0x8007A210

extern void StopSoulReaverCharge(struct __ReaverData *data, struct _Instance *instance); // 0x8007A334

extern void SoulReaverPost(struct _Instance *instance, unsigned long message, unsigned long data); // 0x8007A374

extern unsigned long REAVER_GetGlowColor(struct _Instance *instance); // 0x8007A6D0

extern void _SoulReaverAnimate(struct _Instance *instance); // 0x8007A6F4

extern int SoulReaverFire(); // 0x8007A8B0

#endif
