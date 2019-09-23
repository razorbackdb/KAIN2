#ifndef STATE_H
#define STATE_H

static char circBuf[4096]; // offset 0x800D2E2C

static void *circWhere; // offset 0x800CF5B0

static struct _G2AnimAlphaTable_Type(*G2AlphaTables[7]); // offset 0x800CF594

struct STATE_68fake // hashcode: 0xE3296EAC (dec: -483823956)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x0AB40A7C (dec: 179571324), parent name: 'STATE_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x38A2FA9E (dec: 950205086), parent name: 'STATE_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_69fake // hashcode: 0x1514A194 (dec: 353673620)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x505EE46F (dec: 1348396143), parent name: 'STATE_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x02C8CD82 (dec: 46714242), parent name: 'STATE_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_70fake // hashcode: 0x75D78F9E (dec: 1977061278)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x85188E18 (dec: -2061988328), parent name: 'STATE_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xA5AAF3F9 (dec: -1515523079), parent name: 'STATE_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union STATE_71fake // Hashcode: 0xAA58AF71 (dec: -1437028495)
{
	struct STATE_68fake callback; // size=8, offset=0
	struct STATE_69fake vector;   // size=12, offset=0
	struct STATE_70fake quat;	 // size=16, offset=0
};

union STATE_72fake // Hashcode: 0x5FE524E4 (dec: 1608852708)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union STATE_73fake // Hashcode: 0x778B5AC8 (dec: 2005621448)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct STATE_74fake // hashcode: 0x3444C5CA (dec: 876922314)
{
	union STATE_73fake size; // size=4, offset=0 //  hashcode: 0x8B4A6863 (dec: -1958057885), parent name: 'STATE_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_75fake // hashcode: 0x977E4CA4 (dec: -1753330524)
{
	short x;				// size=0, offset=0 //  hashcode: 0xA98B5EF6 (dec: -1450483978), parent name: 'STATE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x9F613D68 (dec: -1621017240), parent name: 'STATE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xA17D670C (dec: -1585617140), parent name: 'STATE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x5A6520C0 (dec: 1516576960), parent name: 'STATE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xA12608E6 (dec: -1591342874), parent name: 'STATE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_76fake // hashcode: 0x0BAD7875 (dec: 195917941)
{
	long index; // size=0, offset=0 //  hashcode: 0x65180D8B (dec: 1696075147), parent name: 'STATE_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xA3CE0984 (dec: -1546778236), parent name: 'STATE_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_77fake // hashcode: 0x8C560B3B (dec: -1940518085)
{
	long index; // size=0, offset=0 //  hashcode: 0x85F90E3D (dec: -2047275459), parent name: 'STATE_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xECA01299 (dec: -325053799), parent name: 'STATE_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_78fake // hashcode: 0x3A5B05CB (dec: 979043787)
{
	long index; // size=0, offset=0 //  hashcode: 0x9FBEFBBA (dec: -1614873670), parent name: 'STATE_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x1AE1934D (dec: 450990925), parent name: 'STATE_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_79fake // hashcode: 0x63A08B1A (dec: 1671465754)
{
	long time;  // size=0, offset=0 //  hashcode: 0xC88BE09B (dec: -930357093), parent name: 'STATE_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x2A5FA999 (dec: 710912409), parent name: 'STATE_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_80fake // hashcode: 0x640080EC (dec: 1677754604)
{
	long action;   // size=0, offset=0 //  hashcode: 0x0F8FF9BA (dec: 261093818), parent name: 'STATE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xE25AB5CE (dec: -497371698), parent name: 'STATE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_81fake // hashcode: 0x9041E8E4 (dec: -1874728732)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x2D898D98 (dec: 763989400), parent name: 'STATE_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xAE04936B (dec: -1375431829), parent name: 'STATE_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_82fake // hashcode: 0x8C09F1AF (dec: -1945505361)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x17D3C9F2 (dec: 399755762), parent name: 'STATE_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x94AF4788 (dec: -1800452216), parent name: 'STATE_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_83fake // hashcode: 0x2E6CD3CF (dec: 778884047)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x55972EB7 (dec: 1435971255), parent name: 'STATE_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x4B9B9208 (dec: 1268486664), parent name: 'STATE_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_84fake // hashcode: 0x72EED097 (dec: 1928253591)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x141283C8 (dec: 336757704), parent name: 'STATE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x53E584C3 (dec: 1407550659), parent name: 'STATE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x3A51D746 (dec: 978442054), parent name: 'STATE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x227AF4FF (dec: 578483455), parent name: 'STATE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xF0ECEE9B (dec: -252907877), parent name: 'STATE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_85fake // hashcode: 0xBBD6CF6F (dec: -1143550097)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xE5E7EE4F (dec: -437785009), parent name: 'STATE_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x94AB09B5 (dec: -1800730187), parent name: 'STATE_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_86fake // hashcode: 0x246BD5A4 (dec: 611046820)
{
	short index;					// size=0, offset=0 //  hashcode: 0x1896AE24 (dec: 412528164), parent name: 'STATE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x5426D613 (dec: 1411831315), parent name: 'STATE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x9ADDAAA1 (dec: -1696748895), parent name: 'STATE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xD0D3A8EA (dec: -791435030), parent name: 'STATE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_87fake // hashcode: 0x1B47916F (dec: 457675119)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x30B1918D (dec: 816943501), parent name: 'STATE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x2F924496 (dec: 798114966), parent name: 'STATE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xB80DA5A4 (dec: -1207065180), parent name: 'STATE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_88fake // hashcode: 0x8CF971E8 (dec: -1929809432)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xC2DD2919 (dec: -1025693415), parent name: 'STATE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xBD95ACE4 (dec: -1114264348), parent name: 'STATE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x63AA93E0 (dec: 1672123360), parent name: 'STATE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xBCC9C338 (dec: -1127627976), parent name: 'STATE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xE49B9CBE (dec: -459563842), parent name: 'STATE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xB05DD32C (dec: -1336028372), parent name: 'STATE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x756D7C56 (dec: 1970109526), parent name: 'STATE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_89fake // hashcode: 0x4F806FBC (dec: 1333817276)
{
	long index;  // size=0, offset=0 //  hashcode: 0x585F2599 (dec: 1482630553), parent name: 'STATE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xA22C07DE (dec: -1574172706), parent name: 'STATE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_90fake // hashcode: 0xDCB278EB (dec: -592283413)
{
	short type; // size=0, offset=0 //  hashcode: 0xCDD3742A (dec: -841780182), parent name: 'STATE_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x3B00BFAB (dec: 989904811), parent name: 'STATE_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_91fake // hashcode: 0x8E335D6A (dec: -1909236374)
{
	long time;   // size=0, offset=0 //  hashcode: 0xFA3879AE (dec: -96962130), parent name: 'STATE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x5BA484EA (dec: 1537508586), parent name: 'STATE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_92fake // hashcode: 0x53E310BA (dec: 1407389882)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x05A6B277 (dec: 94810743), parent name: 'STATE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xBC70AC38 (dec: -1133466568), parent name: 'STATE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_93fake // hashcode: 0x38B6BC18 (dec: 951499800)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x6904D203 (dec: 1761923587), parent name: 'STATE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x0AA499DC (dec: 178559452), parent name: 'STATE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_94fake // hashcode: 0x095B752D (dec: 156988717)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x8F26F9D4 (dec: -1893271084), parent name: 'STATE_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x3FFFC07A (dec: 1073725562), parent name: 'STATE_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_95fake // hashcode: 0x5BE3F171 (dec: 1541665137)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x8755F26A (dec: -2024410518), parent name: 'STATE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xAEBFD821 (dec: -1363159007), parent name: 'STATE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x07DA1F56 (dec: 131735382), parent name: 'STATE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x6EE837A9 (dec: 1860712361), parent name: 'STATE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_96fake // hashcode: 0x3FB89E9F (dec: 1069063839)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x673BB7C2 (dec: 1731966914), parent name: 'STATE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xF4900A1C (dec: -191886820), parent name: 'STATE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xF9CD4496 (dec: -103988074), parent name: 'STATE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xC646E32A (dec: -968432854), parent name: 'STATE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xCEC49D3A (dec: -825975494), parent name: 'STATE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union STATE_97fake // Hashcode: 0x45B8756A (dec: 1169716586)
{
	struct STATE_74fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	 // size=24, offset=0
	struct STATE_75fake teleport;	 // size=16, offset=0
	struct STATE_76fake cameraValue;  // size=8, offset=0
	struct STATE_77fake miscValue;	// size=8, offset=0
	struct STATE_78fake logicValue;   // size=8, offset=0
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
	struct STATE_79fake cameraShake;  // size=8, offset=0
	long cameraSave;				  // size=0, offset=0
	long cameraRestore;				  // size=0, offset=0
	struct _BGObject *bgObject;		  // size=24, offset=0
	long value[2];					  // size=8, offset=0
	struct STATE_80fake sound;		  // size=12, offset=0
	void *intro;					  // size=0, offset=0
	long deathZ;					  // size=0, offset=0
	struct STATE_81fake dsignal;	  // size=8, offset=0
	void *mirror;					  // size=0, offset=0
	long fogNear;					  // size=0, offset=0
	long fogFar;					  // size=0, offset=0
	struct STATE_82fake gotoFrame;	// size=8, offset=0
	struct STATE_83fake changeModel;  // size=8, offset=0
	void *vmObject;					  // size=0, offset=0
	struct STATE_84fake logic;		  // size=8, offset=0
	void *callSignal;				  // size=0, offset=0
	struct _SVector offset;			  // size=8, offset=0
	struct Signal *gotoLabel;		  // size=0, offset=0
	struct Signal *gosubLabel;		  // size=0, offset=0
	struct STATE_85fake control;	  // size=8, offset=0
	struct STATE_86fake zSignal;	  // size=12, offset=0
	struct STATE_87fake StreamLevel;  // size=24, offset=0
	struct STATE_88fake shards;		  // size=12, offset=0
	struct STATE_89fake cameraSpline; // size=8, offset=0
	struct STATE_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;				  // size=0, offset=0
	struct STATE_91fake introFX;	  // size=8, offset=0
	struct STATE_92fake introActive;  // size=8, offset=0
	struct STATE_93fake levelChange;  // size=18, offset=0
	long blendStart;				  // size=0, offset=0
	struct STATE_94fake setTimes;	 // size=8, offset=0
	struct STATE_95fake color;		  // size=4, offset=0
	struct STATE_96fake print;		  // size=12, offset=0
	long slideAngle;				  // size=0, offset=0
};

union STATE_98fake // Hashcode: 0x7552203B (dec: 1968316475)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union STATE_103fake // Hashcode: 0x9D54A092 (dec: -1655398254)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct STATE_105fake // hashcode: 0xD5BE73A1 (dec: -708938847)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x4DDA2B38 (dec: 1306143544), parent name: 'STATE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x76BB471B (dec: 1991984923), parent name: 'STATE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x114E6FE4 (dec: 290353124), parent name: 'STATE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x783C3A37 (dec: 2017212983), parent name: 'STATE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x61B7F282 (dec: 1639445122), parent name: 'STATE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x91A818C8 (dec: -1851254584), parent name: 'STATE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xBF2CFD39 (dec: -1087570631), parent name: 'STATE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_106fake // hashcode: 0xB811ED30 (dec: -1206784720)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x022F223E (dec: 36643390), parent name: 'STATE_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xE538DB7C (dec: -449258628), parent name: 'STATE_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x8A6EED37 (dec: -1972441801), parent name: 'STATE_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_107fake // hashcode: 0x6E3F5344 (dec: 1849643844)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x474D40FA (dec: 1196245242), parent name: 'STATE_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xE378A96B (dec: -478631573), parent name: 'STATE_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xE72D4827 (dec: -416462809), parent name: 'STATE_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x1C7E2D7D (dec: 478031229), parent name: 'STATE_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xC823CB06 (dec: -937178362), parent name: 'STATE_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_108fake // hashcode: 0x7AEF81E1 (dec: 2062516705)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xD5C7F0EA (dec: -708316950), parent name: 'STATE_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x6ED8083A (dec: 1859651642), parent name: 'STATE_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x169F63E2 (dec: 379544546), parent name: 'STATE_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x5D463E37 (dec: 1564884535), parent name: 'STATE_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x4CDD7CC2 (dec: 1289583810), parent name: 'STATE_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_109fake // hashcode: 0x5CC5AB24 (dec: 1556458276)
{
	struct STATE_105fake Cinematic; // size=28, offset=0 //  hashcode: 0xA0B8BCB8 (dec: -1598505800), parent name: 'STATE_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct STATE_106fake Idle;		// size=20, offset=28 //  hashcode: 0x6D71AF7C (dec: 1836167036), parent name: 'STATE_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct STATE_107fake Behind;	// size=28, offset=48 //  hashcode: 0xA9714E35 (dec: -1452192203), parent name: 'STATE_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct STATE_108fake Follow;	// size=20, offset=76 //  hashcode: 0x514EB932 (dec: 1364113714), parent name: 'STATE_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __CharacterState // hashcode: 0x6C0823BB (dec: 1812472763)
{
	struct _Instance *CharacterInstance; // size=616, offset=0 //  hashcode: 0xE481146D (dec: -461302675), parent name: '__CharacterState', parent hashcode: 0xFFFFFFFF (dec: -1)
	int TotalSections;					 // size=0, offset=4 //  hashcode: 0xB75C13B1 (dec: -1218702415), parent name: '__CharacterState', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __State SectionList[3];		 // size=852, offset=8 //  hashcode: 0xC7E6FA73 (dec: -941163917), parent name: '__CharacterState', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evMonsterHitData // hashcode: 0x5BC7AF7A (dec: 1539813242)
{
	struct _Instance *sender;  // size=616, offset=0 //  hashcode: 0x3D159193 (dec: 1024823699), parent name: 'evMonsterHitData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *lastHit; // size=616, offset=4 //  hashcode: 0xA5670431 (dec: -1519975375), parent name: 'evMonsterHitData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short knockBackDistance;   // size=0, offset=8 //  hashcode: 0x2D4F32A6 (dec: 760165030), parent name: 'evMonsterHitData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short knockBackDuration;   // size=0, offset=10 //  hashcode: 0x69307B31 (dec: 1764784945), parent name: 'evMonsterHitData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long power;				   // size=0, offset=12 //  hashcode: 0xCBAD5FA4 (dec: -877830236), parent name: 'evMonsterHitData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evMonsterThrownData // hashcode: 0x1A3E9058 (dec: 440307800)
{
	struct _Instance *sender;   // size=616, offset=0 //  hashcode: 0xC492AB88 (dec: -997020792), parent name: 'evMonsterThrownData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation direction; // size=8, offset=4 //  hashcode: 0x4E9C0ED0 (dec: 1318850256), parent name: 'evMonsterThrownData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short power;				// size=0, offset=12 //  hashcode: 0xF1271F5E (dec: -249094306), parent name: 'evMonsterThrownData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evMonsterAlarmData // hashcode: 0x5CC4F325 (dec: 1556411173)
{
	struct _Instance *sender;  // size=616, offset=0 //  hashcode: 0x8D3981B3 (dec: -1925611085), parent name: 'evMonsterAlarmData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position; // size=6, offset=4 //  hashcode: 0x3F3FCE8C (dec: 1061146252), parent name: 'evMonsterAlarmData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short type;				   // size=0, offset=10 //  hashcode: 0xC2E150CC (dec: -1025421108), parent name: 'evMonsterAlarmData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evMonsterSoulSuckData // hashcode: 0x24FA0E9A (dec: 620367514)
{
	struct _Instance *sender;	 // size=616, offset=0 //  hashcode: 0x47CA7C33 (dec: 1204452403), parent name: 'evMonsterSoulSuckData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position Destination; // size=6, offset=4 //  hashcode: 0x824744FD (dec: -2109258499), parent name: 'evMonsterSoulSuckData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evPhysicsDropOffData // hashcode: 0x240C7D71 (dec: 604798321)
{
	short xOffset;	// size=0, offset=0 //  hashcode: 0xF1F18DCF (dec: -235827761), parent name: 'evPhysicsDropOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yOffset;	// size=0, offset=2 //  hashcode: 0x8795AE40 (dec: -2020233664), parent name: 'evPhysicsDropOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short DropOffset; // size=0, offset=4 //  hashcode: 0x02B35F22 (dec: 45309730), parent name: 'evPhysicsDropOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short slipSlope;  // size=0, offset=6 //  hashcode: 0x47364B44 (dec: 1194740548), parent name: 'evPhysicsDropOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int UpperOffset;  // size=0, offset=8 //  hashcode: 0xF7C8EE4A (dec: -137826742), parent name: 'evPhysicsDropOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evPhysicsEdgeData // hashcode: 0x9E9E1CB3 (dec: -1633805133)
{
	short UpperOffset;			// size=0, offset=0 //  hashcode: 0x071D8E47 (dec: 119377479), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ForwardOffset;		// size=0, offset=2 //  hashcode: 0xCB48501E (dec: -884453346), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short AboveOffset;			// size=0, offset=4 //  hashcode: 0xCE8C0D0A (dec: -829682422), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short XDistance;			// size=0, offset=6 //  hashcode: 0xA774BC4C (dec: -1485521844), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short YDistance;			// size=0, offset=8 //  hashcode: 0x1B2E567A (dec: 456021626), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ZDistance;			// size=0, offset=10 //  hashcode: 0x4F5425E8 (dec: 1330914792), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector *Normal1;   // size=8, offset=12 //  hashcode: 0x55027A98 (dec: 1426225816), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector *Normal2;   // size=8, offset=16 //  hashcode: 0x94F33D44 (dec: -1795998396), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector *Delta;		// size=8, offset=20 //  hashcode: 0x26B7E086 (dec: 649584774), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=24 //  hashcode: 0xAD905425 (dec: -1383050203), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int zRot;					// size=0, offset=28 //  hashcode: 0x2654691D (dec: 643066141), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int rc;						// size=0, offset=32 //  hashcode: 0x526D2647 (dec: 1382884935), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evPhysicsWallCrawlData // hashcode: 0x27DFBF06 (dec: 668974854)
{
	short Segment;				   // size=0, offset=0 //  hashcode: 0xC6427418 (dec: -968723432), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Length;				   // size=0, offset=2 //  hashcode: 0x388E0813 (dec: 948832275), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ForwardOffset;		   // size=0, offset=4 //  hashcode: 0x9F16BA5A (dec: -1625900454), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short NormalDistance;		   // size=0, offset=6 //  hashcode: 0xB78EABDF (dec: -1215386657), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector DropNormal;	// size=8, offset=8 //  hashcode: 0xFE1182E7 (dec: -32406809), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector ForwardNormal; // size=8, offset=16 //  hashcode: 0x8A9BB55A (dec: -1969506982), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position NewPosition;  // size=6, offset=24 //  hashcode: 0x35423783 (dec: 893532035), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation DropRotation; // size=8, offset=30 //  hashcode: 0x692FBD3E (dec: 1764736318), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ForwardXRotation;		   // size=0, offset=38 //  hashcode: 0xFFD8A2F4 (dec: -2579724), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int rc;						   // size=0, offset=40 //  hashcode: 0x4D3CFC4C (dec: 1295842380), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evPhysicsSwimData // hashcode: 0x947F2BE5 (dec: -1803605019)
{
	short CheckDepth;			// size=0, offset=0 //  hashcode: 0xC7026775 (dec: -956143755), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short SwimDepth;			// size=0, offset=2 //  hashcode: 0xB680E8CE (dec: -1233065778), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short WadeDepth;			// size=0, offset=4 //  hashcode: 0x6E0FF4FA (dec: 1846539514), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short TreadDepth;			// size=0, offset=6 //  hashcode: 0xA4DB8D00 (dec: -1529115392), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector *iVelocity; // size=8, offset=8 //  hashcode: 0x4FA3A3EA (dec: 1336124394), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Depth;				// size=0, offset=12 //  hashcode: 0x9F1499E8 (dec: -1626039832), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short WaterDepth;			// size=0, offset=14 //  hashcode: 0xC4EEE3DD (dec: -990977059), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rc;					// size=0, offset=16 //  hashcode: 0x96AE20D1 (dec: -1766973231), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;					// size=0, offset=18 //  hashcode: 0x1FFF8FE2 (dec: 536842210), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int WaterLevel;				// size=0, offset=20 //  hashcode: 0x15E8916B (dec: 367563115), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evPhysicsDropHeightData // hashcode: 0x5DCE3926 (dec: 1573796134)
{
	struct _Position origin; // size=6, offset=0 //  hashcode: 0x58C47336 (dec: 1489269558), parent name: 'evPhysicsDropHeightData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short mode;				 // size=0, offset=6 //  hashcode: 0x8898B719 (dec: -2003257575), parent name: 'evPhysicsDropHeightData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short DropOffset;		 // size=0, offset=8 //  hashcode: 0x789522EC (dec: 2023039724), parent name: 'evPhysicsDropHeightData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short result;			 // size=0, offset=10 //  hashcode: 0x95F35881 (dec: -1779214207), parent name: 'evPhysicsDropHeightData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct BSPTree *bsp;	 // size=36, offset=12 //  hashcode: 0xDE001223 (dec: -570420701), parent name: 'evPhysicsDropHeightData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=16 //  hashcode: 0xAF928CEB (dec: -1349350165), parent name: 'evPhysicsDropHeightData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evPhysicsLinkedMoveData // hashcode: 0xB4C6EBA9 (dec: -1262031959)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0x70DBBDCF (dec: 1893449167), parent name: 'evPhysicsLinkedMoveData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int segment;				// size=0, offset=4 //  hashcode: 0xC7535325 (dec: -950840539), parent name: 'evPhysicsLinkedMoveData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector posDelta;   // size=8, offset=8 //  hashcode: 0x68F5F3AF (dec: 1760949167), parent name: 'evPhysicsLinkedMoveData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector rotDelta;   // size=8, offset=16 //  hashcode: 0x61D76E31 (dec: 1641508401), parent name: 'evPhysicsLinkedMoveData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evFXHitData // hashcode: 0x3D609E61 (dec: 1029742177)
{
	struct _SVector location; // size=8, offset=0 //  hashcode: 0x209A25E5 (dec: 546973157), parent name: 'evFXHitData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector velocity; // size=8, offset=8 //  hashcode: 0xCC8FE7F9 (dec: -862984199), parent name: 'evFXHitData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short amount;			  // size=0, offset=16 //  hashcode: 0x7849FBAF (dec: 2018114479), parent name: 'evFXHitData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short type;				  // size=0, offset=18 //  hashcode: 0x88F46757 (dec: -1997248681), parent name: 'evFXHitData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evAnimationControllerDoneData // hashcode: 0x06BA7BE4 (dec: 112884708)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0x952223E1 (dec: -1792924703), parent name: 'evAnimationControllerDoneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;				// size=0, offset=4 //  hashcode: 0x351A3C8E (dec: 890911886), parent name: 'evAnimationControllerDoneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long type;					// size=0, offset=8 //  hashcode: 0xB67CB427 (dec: -1233341401), parent name: 'evAnimationControllerDoneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int data;					// size=0, offset=12 //  hashcode: 0x0E5E87D6 (dec: 241076182), parent name: 'evAnimationControllerDoneData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evMonsterImpaleData // hashcode: 0x6537B50B (dec: 1698149643)
{
	struct _Instance *weapon;   // size=616, offset=0 //  hashcode: 0xB70582D9 (dec: -1224375591), parent name: 'evMonsterImpaleData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation direction; // size=8, offset=4 //  hashcode: 0xEB904A47 (dec: -342865337), parent name: 'evMonsterImpaleData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position;  // size=6, offset=12 //  hashcode: 0x364BBB3B (dec: 910932795), parent name: 'evMonsterImpaleData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short distance;				// size=0, offset=18 //  hashcode: 0x6F36A396 (dec: 1865851798), parent name: 'evMonsterImpaleData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union STATE_203fake // Hashcode: 0xE6D675A2 (dec: -422152798)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct evObjectBreakOffData // hashcode: 0xE7DCD1A1 (dec: -404958815)
{
	struct _Instance *force;  // size=616, offset=0 //  hashcode: 0xD313CAC8 (dec: -753677624), parent name: 'evObjectBreakOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short node;	  // size=0, offset=4 //  hashcode: 0xC8121721 (dec: -938338527), parent name: 'evObjectBreakOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short distance;			  // size=0, offset=6 //  hashcode: 0xDA5F713F (dec: -631279297), parent name: 'evObjectBreakOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short animation; // size=0, offset=8 //  hashcode: 0xD645CDCF (dec: -700068401), parent name: 'evObjectBreakOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short frame;	 // size=0, offset=10 //  hashcode: 0x5AFBD73B (dec: 1526454075), parent name: 'evObjectBreakOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short type;	  // size=0, offset=12 //  hashcode: 0xF86376B6 (dec: -127699274), parent name: 'evObjectBreakOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short action;	// size=0, offset=14 //  hashcode: 0xE91708A2 (dec: -384366430), parent name: 'evObjectBreakOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evObjectAbsorbData // hashcode: 0x1379C145 (dec: 326746437)
{
	struct _Instance *force; // size=616, offset=0 //  hashcode: 0x9AD7D097 (dec: -1697132393), parent name: 'evObjectAbsorbData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short node;	 // size=0, offset=4 //  hashcode: 0x8BC89C2E (dec: -1949787090), parent name: 'evObjectAbsorbData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short steps;	// size=0, offset=6 //  hashcode: 0x1F7E9409 (dec: 528389129), parent name: 'evObjectAbsorbData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evObjectIdleData // hashcode: 0x7C5C48CC (dec: 2086422732)
{
	long mode;					// size=0, offset=0 //  hashcode: 0xB327F483 (dec: -1289227133), parent name: 'evObjectIdleData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=4 //  hashcode: 0xFEC6B87D (dec: -20531075), parent name: 'evObjectIdleData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evControlInitHangData // hashcode: 0xA248117B (dec: -1572335237)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0x34F8F7AC (dec: 888731564), parent name: 'evControlInitHangData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int frame;					// size=0, offset=4 //  hashcode: 0x657A6A05 (dec: 1702521349), parent name: 'evControlInitHangData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int frames;					// size=0, offset=8 //  hashcode: 0xAA508410 (dec: -1437563888), parent name: 'evControlInitHangData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evControlInitIdleData // hashcode: 0xB37CA3C6 (dec: -1283677242)
{
	int mode;   // size=0, offset=0 //  hashcode: 0xF9F22FBA (dec: -101568582), parent name: 'evControlInitIdleData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int frame;  // size=0, offset=4 //  hashcode: 0x7DC2596F (dec: 2109888879), parent name: 'evControlInitIdleData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int frames; // size=0, offset=8 //  hashcode: 0x09759BA0 (dec: 158702496), parent name: 'evControlInitIdleData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evActionLookAroundData // hashcode: 0x27BD6BB6 (dec: 666725302)
{
	short *rotx; // size=0, offset=0 //  hashcode: 0xA11FA4B5 (dec: -1591761739), parent name: 'evActionLookAroundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *rotz; // size=0, offset=4 //  hashcode: 0xE6DCB884 (dec: -421742460), parent name: 'evActionLookAroundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minx;  // size=0, offset=8 //  hashcode: 0xA53902EC (dec: -1522990356), parent name: 'evActionLookAroundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxx;  // size=0, offset=10 //  hashcode: 0x5259CA21 (dec: 1381616161), parent name: 'evActionLookAroundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minz;  // size=0, offset=12 //  hashcode: 0x6B7C257E (dec: 1803298174), parent name: 'evActionLookAroundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxz;  // size=0, offset=14 //  hashcode: 0xA52064D0 (dec: -1524603696), parent name: 'evActionLookAroundData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evActionPlayHostAnimationData // hashcode: 0x89FEF84B (dec: -1979778997)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0xE5F64EC7 (dec: -436842809), parent name: 'evActionPlayHostAnimationData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *host;		// size=616, offset=4 //  hashcode: 0x5134C2CD (dec: 1362412237), parent name: 'evActionPlayHostAnimationData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int newAnim;				// size=0, offset=8 //  hashcode: 0x5C1D0510 (dec: 1545405712), parent name: 'evActionPlayHostAnimationData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int newFrame;				// size=0, offset=12 //  hashcode: 0x9FA43540 (dec: -1616628416), parent name: 'evActionPlayHostAnimationData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int frames;					// size=0, offset=16 //  hashcode: 0x1AEA738A (dec: 451572618), parent name: 'evActionPlayHostAnimationData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int mode;					// size=0, offset=20 //  hashcode: 0xFA1C7EED (dec: -98795795), parent name: 'evActionPlayHostAnimationData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evShadowSegmentData // hashcode: 0xE814E960 (dec: -401282720)
{
	unsigned long totalShadowSegments; // size=0, offset=0 //  hashcode: 0xE8B2B627 (dec: -390941145), parent name: 'evShadowSegmentData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short shadowSegments[4];  // size=8, offset=4 //  hashcode: 0x6E993041 (dec: 1855533121), parent name: 'evShadowSegmentData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_219fake // hashcode: 0x45D319DC (dec: 1171462620)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x5B77D97D (dec: 1534581117), parent name: 'STATE_219fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0xDB287A18 (dec: -618104296), parent name: 'STATE_219fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STATE_220fake // hashcode: 0xDE12CB8B (dec: -569193589)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0xD4715D93 (dec: -730767981), parent name: 'STATE_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0xC06B9D9C (dec: -1066689124), parent name: 'STATE_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0xAEFEF38C (dec: -1359023220), parent name: 'STATE_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x7F39F037 (dec: 2134503479), parent name: 'STATE_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x2640F7E6 (dec: 641791974), parent name: 'STATE_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0xF1F438F6 (dec: -235652874), parent name: 'STATE_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union STATE_221fake // Hashcode: 0xA42CE0BE (dec: -1540562754)
{
	struct STATE_219fake flame; // size=8, offset=0
	struct STATE_220fake phys;  // size=12, offset=0
};

typedef struct __CharacterState CharacterState;

typedef struct evMonsterHitData evMonsterHitData;

typedef struct evMonsterThrownData evMonsterThrownData;

typedef struct evMonsterAlarmData evMonsterAlarmData;

typedef struct evMonsterSoulSuckData evMonsterSoulSuckData;

typedef struct evPhysicsDropOffData evPhysicsDropOffData;

typedef struct evPhysicsEdgeData evPhysicsEdgeData;

typedef struct evPhysicsWallCrawlData evPhysicsWallCrawlData;

typedef struct evPhysicsSwimData evPhysicsSwimData;

typedef struct evPhysicsDropHeightData evPhysicsDropHeightData;

typedef struct evPhysicsLinkedMoveData evPhysicsLinkedMoveData;

typedef struct evFXHitData evFXHitData;

typedef struct evAnimationControllerDoneData evAnimationControllerDoneData;

typedef struct evMonsterImpaleData evMonsterImpaleData;

typedef struct evObjectBreakOffData evObjectBreakOffData;

typedef struct evObjectAbsorbData evObjectAbsorbData;

typedef struct evObjectIdleData evObjectIdleData;

typedef struct evControlInitHangData evControlInitHangData;

typedef struct evControlInitIdleData evControlInitIdleData;

typedef struct evActionLookAroundData evActionLookAroundData;

typedef struct evActionPlayHostAnimationData evActionPlayHostAnimationData;

typedef struct evShadowSegmentData evShadowSegmentData;

extern void InitMessageQueue(struct __MessageQueue *In); // 0x8007071C

extern struct __Event *DeMessageQueue(struct __MessageQueue *In); // 0x80070728

extern void PurgeMessageQueue(struct __MessageQueue *In); // 0x80070764

extern struct __Event *PeekMessageQueue(struct __MessageQueue *In); // 0x80070770

extern void EnMessageQueue(struct __MessageQueue *In, struct __Event *Element); // 0x80070798

extern void EnMessageQueueData(struct __MessageQueue *In, int ID, int Data); // 0x800707C4

extern void *CIRC_Alloc(int size); // 0x80070840

extern int SetCollideInfoData(struct _CollideInfo *srcCI); // 0x80070884

extern int SetMonsterHitData(struct _Instance *Sender, struct _Instance *lastHit, int Power, int knockBackDistance, int knockBackFrames); // 0x800708E0

extern int SetMonsterThrownData(struct _Instance *Sender, struct _Rotation *Direction, int Power); // 0x8007094C

extern int SetMonsterAlarmData(struct _Instance *sender, struct _Position *position, int type); // 0x800709B4

extern int SetMonsterSoulSuckData(struct _Instance *Sender, int x, int y, int z); // 0x80070A1C

extern int SetMonsterImpaleData(struct _Instance *weapon, struct _Rotation *direction, struct _Position *position, int distance); // 0x80070A78

extern int SetObjectData(int x, int y, int PathNumber, struct _Instance *Force, int node); // 0x80070B10

extern int SetPositionData(int x, int y, int z); // 0x80070B7C

extern int SetPhysicsGravityData(int UpperOffset, int LowerOffset, int x, int y, int z, int slope); // 0x80070BC8

extern int SetPhysicsEdgeData(int UpperOffset, int ForwardOffset, int AboveOffset, int x, int y, int z, struct _SVector *Normal1, struct _SVector *Normal2, struct _SVector *Delta); // 0x80070C44

extern int SetPhysicsSwimData(int CheckDepth, struct _SVector *iVelocity, int SwimDepth, int WadeDepth, int TreadDepth); // 0x80070CF0

extern int SetPhysicsDropOffData(int xOffset, int yOffset, int DropOffset, int slipSlope, int UpperOffset); // 0x80070D5C

extern int SetPhysicsSlideData(int Segment, int ForwardVectorX, int ForwardVectorY, int ForwardVectorZ, int DropOffset, int UpperOffset, int Height); // 0x80070DC8

extern int SetPhysicsWallCrawlData(int Segment, int Length, int ForwardOffset, int NormalDistance); // 0x80070E54

extern int SetPhysicsLinkedMoveData(struct _Instance *instance, int segment, struct _SVector *posDelta, struct _SVector *rotDelta); // 0x80070EB0

extern int SetPhysicsDropHeightData(struct _Position *offset, int dropOffset, int mode); // 0x80070F50

extern int SetAnimationControllerDoneData(struct _Instance *instance, long segment, long type, int data); // 0x80070FC0

extern int SetAnimationInstanceSwitchData(struct _Instance *instance, int anim, int frame, int frames, int mode); // 0x8007101C

extern int SetFXHitData(struct _Instance *hitter, int segment, int amount, int type); // 0x80071088

extern int SetObjectThrowData(void *target, struct _SVector *angularVel, unsigned short type, unsigned short spinType, int speed, int gravity, int zVel, int initialXRot); // 0x80071184

extern int SetObjectBreakOffData(struct _Instance *force, short node, short distance, short animation, int frame, int type, int action); // 0x800712F0

extern int SetControlInitHangData(struct _Instance *instance, long frame, long frames); // 0x8007137C

extern int SetControlInitIdleData(int mode, long frame, long frames); // 0x800713C8

extern int SetObjectDraftData(short force, unsigned short radius, unsigned short radiusCoef, unsigned short height, int maxVelocity); // 0x80071414

extern int SetObjectAbsorbData(struct _Instance *force, unsigned short node, unsigned short steps); // 0x80071480

extern int SetControlSaveDataData(long length, void *data); // 0x800714CC

extern int SetObjectIdleData(long mode, struct _Instance *instance); // 0x80071508

extern int SetActionPlayHostAnimationData(struct _Instance *instance, struct _Instance *host, int newAnim, int newFrame, int frames, int mode); // 0x80071544

extern int SetObjectBirthProjectileData(struct _Instance *instance, int joint, int type); // 0x800715C0

extern int SetShadowSegmentData(unsigned long total); // 0x80071610

extern void G2EmulationInit(); // 0x8007163C

extern void G2EmulationInstancePlayAnimation(struct _Instance *instance); // 0x80071828

extern void G2EmulatePlayAnimation(struct __CharacterState *In); // 0x80071890

extern void G2EmulationInstanceToInstanceSwitchAnimation(struct _Instance *instance, struct _Instance *host, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode); // 0x800718B4

extern void G2EmulationInstanceSwitchAnimation(struct _Instance *instance, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode); // 0x800719AC

extern void G2EmulationInstanceSwitchAnimationAlpha(struct _Instance *instance, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode, int AlphaTable); // 0x80071AA0

extern void G2EmulationSwitchAnimation(struct __CharacterState *In, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode); // 0x80071B0C

extern void G2EmulationSwitchAnimationAlpha(struct __CharacterState *In, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode, int AlphaTable); // 0x80071B50

extern void G2EmulationSwitchAnimationSync(struct __CharacterState *In, int SlaveSectionID, int MasterSectionID, int Frames); // 0x80071BC4

extern void G2EmulationInstanceToInstanceSwitchAnimationCharacter(struct _Instance *instance, struct _Instance *host, int NewAnim, int NewFrame, int Frames, int Mode); // 0x80071D90

extern void G2EmulationSwitchAnimationCharacter(struct __CharacterState *In, int NewAnim, int NewFrame, int Frames, int Mode); // 0x80071E7C

extern void G2EmulationInstanceSetAnimation(struct _Instance *instance, int CurrentSection, int NewAnim, int NewFrame, int Frames); // 0x80071F70

extern void G2EmulationSetAnimation(struct __CharacterState *In, int CurrentSection, int NewAnim, int NewFrame, int Frames); // 0x80072018

extern void G2EmulationInstanceSetMode(struct _Instance *instance, int CurrentSection, int Mode); // 0x80072050

extern void G2EmulationSetMode(struct __CharacterState *In, int CurrentSection, int Mode); // 0x800720D0

extern void G2EmulationInstanceSetAnimSpeed(struct _Instance *instance, int CurrentSection, int speed); // 0x800720F4

extern int G2EmulationInstanceQueryAnimation(struct _Instance *instance, int CurrentSection); // 0x80072110

extern int G2EmulationQueryAnimation(struct __CharacterState *In, int CurrentSection); // 0x80072130

extern int G2EmulationInstanceQueryFrame(struct _Instance *instance, int CurrentSection); // 0x80072154

extern int G2EmulationInstanceQueryLastFrame(struct _Instance *instance, int CurrentSection); // 0x80072188

extern int G2EmulationInstanceQueryPassedFrame(struct _Instance *instance, int CurrentSection, int frame); // 0x800721BC

extern int G2EmulationQueryFrame(struct __CharacterState *In, int CurrentSection); // 0x80072264

extern int G2EmulationInstanceQueryMode(struct _Instance *instance, int CurrentSection); // 0x80072288

extern int G2EmulationQueryMode(struct __CharacterState *In, int CurrentSection); // 0x800722D0

extern void G2EmulationInstanceSetStartAndEndSegment(struct _Instance *instance, int CurrentSection, short Start, short End); // 0x800722F4

extern void G2EmulationSetStartAndEndSegment(struct __CharacterState *In, int CurrentSection, short Start, short End); // 0x80072320

extern void G2EmulationInstanceSetTotalSections(struct _Instance *instance, short Total); // 0x80072350

extern void G2EmulationSetTotalSections(struct __CharacterState *In, short Total); // 0x800723D4

extern void G2EmulationInstanceInitSection(struct _Instance *instance, int CurrentSection, void *callback, void *data); // 0x80072404

extern void G2EmulationSetInterpController_Vector(struct _Instance *instance, long segment, long type, struct _G2SVector3_Type *vec, int Frames, int Data); // 0x80072428

extern void StateSwitchStateDataDefault(struct __CharacterState *In, int CurrentSection, TDRFuncPtr_StateSwitchStateDataDefault2NewProcess NewProcess, int Data); // 0x800724B0

extern void StateSwitchStateCharacterDataDefault(struct __CharacterState *In, TDRFuncPtr_StateSwitchStateCharacterDataDefault1NewProcess NewProcess, int Data); // 0x80072518

extern void StateSwitchStateData(struct __CharacterState *In, int CurrentSection, TDRFuncPtr_StateSwitchStateData2NewProcess NewProcess, int Data); // 0x80072590

extern void StateSwitchStateCharacterData(struct __CharacterState *In, TDRFuncPtr_StateSwitchStateCharacterData1NewProcess NewProcess, int Data); // 0x8007265C

extern void StateGovernState(struct __CharacterState *In, int Frames); // 0x80072750

typedef void (*TDRFuncPtr_StateSwitchStateCharacterData1NewProcess)();

typedef void (*TDRFuncPtr_StateSwitchStateCharacterDataDefault1NewProcess)();

typedef void (*TDRFuncPtr_StateSwitchStateData2NewProcess)();

typedef void (*TDRFuncPtr_StateSwitchStateDataDefault2NewProcess)();

#endif
