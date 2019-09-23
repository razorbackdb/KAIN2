#ifndef SOUL_H
#define SOUL_H

extern struct _MonsterFunctionTable SOUL_FunctionTable; // offset 0x800CF6D4

extern struct _MonsterStateChoice SOUL_StateChoiceTable[7]; // offset 0x800CAB48

struct SOUL_73fake // hashcode: 0x17CB5CCA (dec: 399203530)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xB6B37940 (dec: -1229752000), parent name: 'SOUL_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x6FAD5DEE (dec: 1873632750), parent name: 'SOUL_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_74fake // hashcode: 0x18C46A6F (dec: 415525487)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x5146EADC (dec: 1363602140), parent name: 'SOUL_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x18AECC5A (dec: 414108762), parent name: 'SOUL_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_75fake // hashcode: 0x9200E588 (dec: -1845435000)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xF404AE86 (dec: -201019770), parent name: 'SOUL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xF75D4D2E (dec: -144880338), parent name: 'SOUL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SOUL_76fake // Hashcode: 0xCC0D2587 (dec: -871553657)
{
	struct SOUL_73fake callback; // size=8, offset=0
	struct SOUL_74fake vector;   // size=12, offset=0
	struct SOUL_75fake quat;	 // size=16, offset=0
};

union SOUL_77fake // Hashcode: 0x7DA1E6FA (dec: 2107762426)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union SOUL_78fake // Hashcode: 0x887BA6C9 (dec: -2005162295)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct SOUL_79fake // hashcode: 0x6276C563 (dec: 1651950947)
{
	union SOUL_78fake size; // size=4, offset=0 //  hashcode: 0xD085E1E3 (dec: -796532253), parent name: 'SOUL_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_80fake // hashcode: 0x10D2A548 (dec: 282240328)
{
	short x;				// size=0, offset=0 //  hashcode: 0x6E105DA0 (dec: 1846566304), parent name: 'SOUL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x04D850F0 (dec: 81285360), parent name: 'SOUL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x3F900FF1 (dec: 1066405873), parent name: 'SOUL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x4C8CAA5F (dec: 1284287071), parent name: 'SOUL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x1276D3CD (dec: 309777357), parent name: 'SOUL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_81fake // hashcode: 0x6DC24E77 (dec: 1841450615)
{
	long index; // size=0, offset=0 //  hashcode: 0xE215E71A (dec: -501881062), parent name: 'SOUL_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x8B106C04 (dec: -1961858044), parent name: 'SOUL_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_82fake // hashcode: 0x792F39B9 (dec: 2033138105)
{
	long index; // size=0, offset=0 //  hashcode: 0xA18B43C0 (dec: -1584708672), parent name: 'SOUL_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xD2A35C0C (dec: -761046004), parent name: 'SOUL_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_83fake // hashcode: 0xE4B06CA6 (dec: -458199898)
{
	long index; // size=0, offset=0 //  hashcode: 0x6F3FEF35 (dec: 1866460981), parent name: 'SOUL_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x45CDF6DA (dec: 1171125978), parent name: 'SOUL_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_84fake // hashcode: 0x9CF3B7D5 (dec: -1661749291)
{
	long time;  // size=0, offset=0 //  hashcode: 0xCD6965CF (dec: -848730673), parent name: 'SOUL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xF320EA4C (dec: -215946676), parent name: 'SOUL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_85fake // hashcode: 0x0DA61751 (dec: 228988753)
{
	long action;   // size=0, offset=0 //  hashcode: 0x71CFB0C8 (dec: 1909436616), parent name: 'SOUL_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x94A66D83 (dec: -1801032317), parent name: 'SOUL_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_86fake // hashcode: 0x8FD81E41 (dec: -1881661887)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xEC90CF87 (dec: -326054009), parent name: 'SOUL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x7E64CFFE (dec: 2120536062), parent name: 'SOUL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_87fake // hashcode: 0xE7E9982C (dec: -404121556)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x934518B0 (dec: -1824188240), parent name: 'SOUL_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x2AC72ED5 (dec: 717696725), parent name: 'SOUL_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_88fake // hashcode: 0xA6DD51B8 (dec: -1495445064)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xDE67D98C (dec: -563619444), parent name: 'SOUL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xF81384BB (dec: -132938565), parent name: 'SOUL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_89fake // hashcode: 0xD5F1F7A5 (dec: -705562715)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xF67E00BE (dec: -159514434), parent name: 'SOUL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x62BA5504 (dec: 1656378628), parent name: 'SOUL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xB5A463E3 (dec: -1247517725), parent name: 'SOUL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xE26DE714 (dec: -496113900), parent name: 'SOUL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xF5BBD087 (dec: -172240761), parent name: 'SOUL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_90fake // hashcode: 0xA0C8ABFA (dec: -1597461510)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x87E3BC2F (dec: -2015118289), parent name: 'SOUL_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x9653EF0C (dec: -1772884212), parent name: 'SOUL_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_91fake // hashcode: 0x6D34945D (dec: 1832162397)
{
	short index;					// size=0, offset=0 //  hashcode: 0x93C1F87C (dec: -1816004484), parent name: 'SOUL_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x01A838B5 (dec: 27801781), parent name: 'SOUL_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x63CED9CC (dec: 1674500556), parent name: 'SOUL_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x11C0D4EE (dec: 297850094), parent name: 'SOUL_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_92fake // hashcode: 0x65F60A65 (dec: 1710623333)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xEAF03A8B (dec: -353355125), parent name: 'SOUL_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x7FAFA3CA (dec: 2142217162), parent name: 'SOUL_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xA2E008EF (dec: -1562375953), parent name: 'SOUL_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_93fake // hashcode: 0x00D51A4F (dec: 13965903)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x2B1DB7E8 (dec: 723367912), parent name: 'SOUL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x74FFCC99 (dec: 1962921113), parent name: 'SOUL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x0A5E6BE3 (dec: 173960163), parent name: 'SOUL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xBDC520D8 (dec: -1111154472), parent name: 'SOUL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xABE3FFC1 (dec: -1411121215), parent name: 'SOUL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xADA74D63 (dec: -1381544605), parent name: 'SOUL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x2890C6B3 (dec: 680576691), parent name: 'SOUL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_94fake // hashcode: 0x466C8737 (dec: 1181517623)
{
	long index;  // size=0, offset=0 //  hashcode: 0x03FAA034 (dec: 66756660), parent name: 'SOUL_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xDFD5F4CA (dec: -539626294), parent name: 'SOUL_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_95fake // hashcode: 0x138DEE36 (dec: 328068662)
{
	short type; // size=0, offset=0 //  hashcode: 0xD7126F45 (dec: -686657723), parent name: 'SOUL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x970F2AED (dec: -1760613651), parent name: 'SOUL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_96fake // hashcode: 0xD65BDFCD (dec: -698622003)
{
	long time;   // size=0, offset=0 //  hashcode: 0x3639E4DD (dec: 909763805), parent name: 'SOUL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x348214E3 (dec: 880940259), parent name: 'SOUL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_97fake // hashcode: 0x29BBD899 (dec: 700176537)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x6EC83B4C (dec: 1858616140), parent name: 'SOUL_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x8467766E (dec: -2073594258), parent name: 'SOUL_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_98fake // hashcode: 0x637D121A (dec: 1669141018)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x6AE71ED4 (dec: 1793531604), parent name: 'SOUL_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x3B15BBB1 (dec: 991280049), parent name: 'SOUL_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_99fake // hashcode: 0x952399C1 (dec: -1792828991)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x59AE7A6D (dec: 1504606829), parent name: 'SOUL_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x6EC15AA0 (dec: 1858165408), parent name: 'SOUL_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_100fake // hashcode: 0x102D662E (dec: 271410734)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x96E2BA5F (dec: -1763526049), parent name: 'SOUL_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xE13BDBAE (dec: -516170834), parent name: 'SOUL_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xF522DBBF (dec: -182264897), parent name: 'SOUL_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xAD050C15 (dec: -1392178155), parent name: 'SOUL_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_101fake // hashcode: 0xD81E73DA (dec: -669092902)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x4DB55F52 (dec: 1303732050), parent name: 'SOUL_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x0AE3CEC7 (dec: 182701767), parent name: 'SOUL_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xF142262E (dec: -247323090), parent name: 'SOUL_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xBE49BBF8 (dec: -1102464008), parent name: 'SOUL_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xF76D48B5 (dec: -143832907), parent name: 'SOUL_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SOUL_102fake // Hashcode: 0x17482CD0 (dec: 390606032)
{
	struct SOUL_79fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;	// size=24, offset=0
	struct SOUL_80fake teleport;	 // size=16, offset=0
	struct SOUL_81fake cameraValue;  // size=8, offset=0
	struct SOUL_82fake miscValue;	// size=8, offset=0
	struct SOUL_83fake logicValue;   // size=8, offset=0
	long timer;						 // size=0, offset=0
	long times;						 // size=0, offset=0
	long lightGroup;				 // size=0, offset=0
	long farPlane;					 // size=0, offset=0
	long cameraAdjust;				 // size=0, offset=0
	long cameraMode;				 // size=0, offset=0
	long cameraLock;				 // size=0, offset=0
	long cameraUnlock;				 // size=0, offset=0
	long cameraSmooth;				 // size=0, offset=0
	long cameraTimer;				 // size=0, offset=0
	struct SOUL_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				 // size=0, offset=0
	long cameraRestore;				 // size=0, offset=0
	struct _BGObject *bgObject;		 // size=24, offset=0
	long value[2];					 // size=8, offset=0
	struct SOUL_85fake sound;		 // size=12, offset=0
	void *intro;					 // size=0, offset=0
	long deathZ;					 // size=0, offset=0
	struct SOUL_86fake dsignal;		 // size=8, offset=0
	void *mirror;					 // size=0, offset=0
	long fogNear;					 // size=0, offset=0
	long fogFar;					 // size=0, offset=0
	struct SOUL_87fake gotoFrame;	// size=8, offset=0
	struct SOUL_88fake changeModel;  // size=8, offset=0
	void *vmObject;					 // size=0, offset=0
	struct SOUL_89fake logic;		 // size=8, offset=0
	void *callSignal;				 // size=0, offset=0
	struct _SVector offset;			 // size=8, offset=0
	struct Signal *gotoLabel;		 // size=0, offset=0
	struct Signal *gosubLabel;		 // size=0, offset=0
	struct SOUL_90fake control;		 // size=8, offset=0
	struct SOUL_91fake zSignal;		 // size=12, offset=0
	struct SOUL_92fake StreamLevel;  // size=24, offset=0
	struct SOUL_93fake shards;		 // size=12, offset=0
	struct SOUL_94fake cameraSpline; // size=8, offset=0
	struct SOUL_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				 // size=0, offset=0
	struct SOUL_96fake introFX;		 // size=8, offset=0
	struct SOUL_97fake introActive;  // size=8, offset=0
	struct SOUL_98fake levelChange;  // size=18, offset=0
	long blendStart;				 // size=0, offset=0
	struct SOUL_99fake setTimes;	 // size=8, offset=0
	struct SOUL_100fake color;		 // size=4, offset=0
	struct SOUL_101fake print;		 // size=12, offset=0
	long slideAngle;				 // size=0, offset=0
};

union SOUL_103fake // Hashcode: 0xFCECF414 (dec: -51579884)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union SOUL_108fake // Hashcode: 0x9ADAC4E4 (dec: -1696938780)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct SOUL_110fake // hashcode: 0xBB177B9E (dec: -1156088930)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xCB1EF4F4 (dec: -887163660), parent name: 'SOUL_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x709C9CE1 (dec: 1889311969), parent name: 'SOUL_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x545CC0AC (dec: 1415364780), parent name: 'SOUL_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x326188AA (dec: 845252778), parent name: 'SOUL_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x1CC5DE41 (dec: 482729537), parent name: 'SOUL_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xA58DE0BB (dec: -1517428549), parent name: 'SOUL_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xD0E524F8 (dec: -790289160), parent name: 'SOUL_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_111fake // hashcode: 0x1322894A (dec: 321030474)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x986A7B3E (dec: -1737852098), parent name: 'SOUL_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xB65E650D (dec: -1235327731), parent name: 'SOUL_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x5CB973A2 (dec: 1555657634), parent name: 'SOUL_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_112fake // hashcode: 0xBE593225 (dec: -1101450715)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xBBBF287D (dec: -1145100163), parent name: 'SOUL_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xC1717E6C (dec: -1049526676), parent name: 'SOUL_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xB3A9B6FB (dec: -1280723205), parent name: 'SOUL_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x546F1F68 (dec: 1416568680), parent name: 'SOUL_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x5A5ED7E0 (dec: 1516165088), parent name: 'SOUL_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_113fake // hashcode: 0xA14281AD (dec: -1589476947)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x8BE895AB (dec: -1947691605), parent name: 'SOUL_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x33242F71 (dec: 858009457), parent name: 'SOUL_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0xDE594EA3 (dec: -564572509), parent name: 'SOUL_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x3B949DC9 (dec: 999595465), parent name: 'SOUL_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x5125B7D7 (dec: 1361426391), parent name: 'SOUL_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_114fake // hashcode: 0x75056227 (dec: 1963287079)
{
	struct SOUL_110fake Cinematic; // size=28, offset=0 //  hashcode: 0xD9021FDA (dec: -654172198), parent name: 'SOUL_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SOUL_111fake Idle;	  // size=20, offset=28 //  hashcode: 0xF9A8024F (dec: -106429873), parent name: 'SOUL_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SOUL_112fake Behind;	// size=28, offset=48 //  hashcode: 0x6B0D3D14 (dec: 1796029716), parent name: 'SOUL_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SOUL_113fake Follow;	// size=20, offset=76 //  hashcode: 0xE26F7817 (dec: -496011241), parent name: 'SOUL_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SOUL_193fake // Hashcode: 0xC2BEE064 (dec: -1027678108)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct SOUL_217fake // hashcode: 0x54B470AD (dec: 1421111469)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x1746540E (dec: 390485006), parent name: 'SOUL_217fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x3195BECD (dec: 831897293), parent name: 'SOUL_217fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUL_218fake // hashcode: 0x2721C801 (dec: 656525313)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x4E50014E (dec: 1313866062), parent name: 'SOUL_218fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0xE86BD17A (dec: -395587206), parent name: 'SOUL_218fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0xD60739AB (dec: -704169557), parent name: 'SOUL_218fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x27B94EE4 (dec: 666455780), parent name: 'SOUL_218fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x9C474E11 (dec: -1673048559), parent name: 'SOUL_218fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x9B5F07F1 (dec: -1688270863), parent name: 'SOUL_218fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SOUL_219fake // Hashcode: 0xF29C6AF5 (dec: -224630027)
{
	struct SOUL_217fake flame; // size=8, offset=0
	struct SOUL_218fake phys;  // size=12, offset=0
};

extern void SOUL_QueueHandler(struct _Instance *instance); // 0x8008D6D4

extern void SOUL_Physics(struct _Instance *instance, long time); // 0x8008D770

extern void SOUL_Fade(struct _Instance *instance); // 0x8008D7D0

extern void SOUL_MoveToDest(struct _Instance *instance, long maxAccel, long time); // 0x8008D884

extern void SOUL_MovePastWall(struct _Instance *instance, struct _Instance *sucker); // 0x8008D974

extern void SOUL_Init(struct _Instance *instance); // 0x8008DAE4

extern void SOUL_CleanUp(struct _Instance *instance); // 0x8008DBA8

extern void SOUL_BirthEntry(struct _Instance *instance); // 0x8008DBC8

extern void SOUL_Birth(struct _Instance *instance); // 0x8008DC1C

extern void SOUL_SoulSuckEntry(struct _Instance *instance); // 0x8008DC84

extern long SOUL_CalcAccel(long delta, long vel, long magnitude); // 0x8008DCAC

extern void SOUL_SoulSuck(struct _Instance *instance); // 0x8008DCEC

extern void SOUL_WanderEntry(struct _Instance *instance); // 0x8008E294

extern void SOUL_Wander(struct _Instance *instance); // 0x8008E304

extern void SOUL_FleeEntry(struct _Instance *instance); // 0x8008E494

extern void SOUL_Flee(struct _Instance *instance); // 0x8008E4C4

extern void SOUL_IdleEntry(struct _Instance *instance); // 0x8008E628

extern void SOUL_Idle(struct _Instance *instance); // 0x8008E6CC

extern void SOUL_ReanimateEntry(struct _Instance *instance); // 0x8008E7CC

extern void SOUL_Reanimate(struct _Instance *instance); // 0x8008E834

extern void SOUL_Effect(struct _Instance *instance, struct evFXHitData *data); // 0x8008E8EC

#endif
