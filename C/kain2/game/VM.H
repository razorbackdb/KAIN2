#ifndef VM_H
#define VM_H

static long vmClock; // offset 0x800CEBD8

static long vmRealClock; // offset 0x800CEBD4

struct VM_68fake // hashcode: 0xC23F5178 (dec: -1036037768)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x607138FC (dec: 1618032892), parent name: 'VM_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x19CA13DE (dec: 432673758), parent name: 'VM_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_69fake // hashcode: 0xD41EA1A5 (dec: -736190043)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xCDD7972F (dec: -841509073), parent name: 'VM_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x2E158A82 (dec: 773163650), parent name: 'VM_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_70fake // hashcode: 0x8BDDB0CA (dec: -1948405558)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x46C8BA18 (dec: 1187559960), parent name: 'VM_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x6F65B4B9 (dec: 1868936377), parent name: 'VM_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union VM_71fake // Hashcode: 0x577C0C3A (dec: 1467747386)
{
	struct VM_68fake callback; // size=8, offset=0
	struct VM_69fake vector;   // size=12, offset=0
	struct VM_70fake quat;	 // size=16, offset=0
};

union VM_72fake // Hashcode: 0x27CA656B (dec: 667575659)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union VM_73fake // Hashcode: 0x9C9CA2EA (dec: -1667456278)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct VM_74fake // hashcode: 0x4626A256 (dec: 1176937046)
{
	union VM_73fake size; // size=4, offset=0 //  hashcode: 0xEF7F99C0 (dec: -276850240), parent name: 'VM_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_75fake // hashcode: 0x06E0AAB8 (dec: 115387064)
{
	short x;				// size=0, offset=0 //  hashcode: 0x2EA2A9F6 (dec: 782412278), parent name: 'VM_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xA73ACD68 (dec: -1489318552), parent name: 'VM_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xE514BF4C (dec: -451625140), parent name: 'VM_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x99BF1DC0 (dec: -1715528256), parent name: 'VM_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x4286E1A6 (dec: 1116135846), parent name: 'VM_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_76fake // hashcode: 0xCF6B6AE7 (dec: -815043865)
{
	long index; // size=0, offset=0 //  hashcode: 0x8C90EE8B (dec: -1936658805), parent name: 'VM_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x3ACAFF44 (dec: 986382148), parent name: 'VM_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_77fake // hashcode: 0x2803E5AA (dec: 671344042)
{
	long index; // size=0, offset=0 //  hashcode: 0xA906C9BD (dec: -1459172931), parent name: 'VM_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xCE0ED819 (dec: -837887975), parent name: 'VM_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_78fake // hashcode: 0xE7F7EBC0 (dec: -403182656)
{
	long index; // size=0, offset=0 //  hashcode: 0xC9F25D7A (dec: -906863238), parent name: 'VM_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x7E41158D (dec: 2118194573), parent name: 'VM_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_79fake // hashcode: 0x71CBAE8D (dec: 1909173901)
{
	long time;  // size=0, offset=0 //  hashcode: 0x59884FDB (dec: 1502105563), parent name: 'VM_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xFF654E59 (dec: -10138023), parent name: 'VM_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_80fake // hashcode: 0xF14D528A (dec: -246590838)
{
	long action;   // size=0, offset=0 //  hashcode: 0xBFE673FA (dec: -1075416070), parent name: 'VM_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xB7764B8E (dec: -1216984178), parent name: 'VM_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_81fake // hashcode: 0xBAACDA26 (dec: -1163077082)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xC5ED4018 (dec: -974307304), parent name: 'VM_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x049DAB2B (dec: 77441835), parent name: 'VM_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_82fake // hashcode: 0x59FAE436 (dec: 1509614646)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x744E51F2 (dec: 1951289842), parent name: 'VM_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x62CD1388 (dec: 1657607048), parent name: 'VM_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_83fake // hashcode: 0x71E61675 (dec: 1910904437)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xDF393A77 (dec: -549897609), parent name: 'VM_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xEEA17C08 (dec: -291406840), parent name: 'VM_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_84fake // hashcode: 0x3AE27455 (dec: 987919445)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x23CF9448 (dec: 600806472), parent name: 'VM_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xCE29CE43 (dec: -836121021), parent name: 'VM_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x2C081E06 (dec: 738729478), parent name: 'VM_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x8DD0F33F (dec: -1915686081), parent name: 'VM_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xE393255B (dec: -476895909), parent name: 'VM_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_85fake // hashcode: 0x736B6212 (dec: 1936417298)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xF64C780F (dec: -162760689), parent name: 'VM_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xA52E0335 (dec: -1523711179), parent name: 'VM_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_86fake // hashcode: 0xDFDB68C9 (dec: -539268919)
{
	short index;					// size=0, offset=0 //  hashcode: 0xFA968F24 (dec: -90796252), parent name: 'VM_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x48CE4353 (dec: 1221477203), parent name: 'VM_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x9A8A55A1 (dec: -1702210143), parent name: 'VM_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x3A189BEA (dec: 974691306), parent name: 'VM_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_87fake // hashcode: 0x78CB03DC (dec: 2026570716)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xB4F8138D (dec: -1258810483), parent name: 'VM_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x0068A896 (dec: 6858902), parent name: 'VM_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xC30DACA4 (dec: -1022514012), parent name: 'VM_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_88fake // hashcode: 0xD23CC7C4 (dec: -767768636)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x37139819 (dec: 924031001), parent name: 'VM_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x882AC7E4 (dec: -2010462236), parent name: 'VM_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x712BF8A0 (dec: 1898707104), parent name: 'VM_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x9F88AD78 (dec: -1618432648), parent name: 'VM_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xC1FDC0FE (dec: -1040334594), parent name: 'VM_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x9CD8682C (dec: -1663539156), parent name: 'VM_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x39F0EED6 (dec: 972091094), parent name: 'VM_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_89fake // hashcode: 0x640BA4DE (dec: 1678484702)
{
	long index;  // size=0, offset=0 //  hashcode: 0x2DEED919 (dec: 770627865), parent name: 'VM_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x1F1067DE (dec: 521168862), parent name: 'VM_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_90fake // hashcode: 0xAD7C95B0 (dec: -1384344144)
{
	short type; // size=0, offset=0 //  hashcode: 0x32B4262A (dec: 850667050), parent name: 'VM_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xD60CBE6B (dec: -703807893), parent name: 'VM_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_91fake // hashcode: 0xCD24C4EB (dec: -853228309)
{
	long time;   // size=0, offset=0 //  hashcode: 0x0F9B56EE (dec: 261838574), parent name: 'VM_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x0528546A (dec: 86529130), parent name: 'VM_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_92fake // hashcode: 0x73A18462 (dec: 1939965026)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x981072B7 (dec: -1743752521), parent name: 'VM_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x9BC990F8 (dec: -1681288968), parent name: 'VM_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_93fake // hashcode: 0xA8F0BFFE (dec: -1460617218)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xF3E86DC3 (dec: -202871357), parent name: 'VM_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x3F11D99C (dec: 1058134428), parent name: 'VM_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_94fake // hashcode: 0x1CDFD39B (dec: 484430747)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x5CD6C594 (dec: 1557579156), parent name: 'VM_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x3AE7BC7A (dec: 988265594), parent name: 'VM_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_95fake // hashcode: 0x7E7D4C3E (dec: 2122140734)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x22AFEF2A (dec: 581955370), parent name: 'VM_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xCE20A1E1 (dec: -836722207), parent name: 'VM_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x3C980D56 (dec: 1016597846), parent name: 'VM_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x925858A9 (dec: -1839703895), parent name: 'VM_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_96fake // hashcode: 0x7626C51C (dec: 1982252316)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x05AF6D82 (dec: 95382914), parent name: 'VM_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xC19918DC (dec: -1046931236), parent name: 'VM_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x4C80B3D6 (dec: 1283503062), parent name: 'VM_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x8F15FF6A (dec: -1894383766), parent name: 'VM_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xF7374C3A (dec: -147370950), parent name: 'VM_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union VM_97fake // Hashcode: 0x9093C173 (dec: -1869364877)
{
	struct VM_74fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;  // size=24, offset=0
	struct VM_75fake teleport;	 // size=16, offset=0
	struct VM_76fake cameraValue;  // size=8, offset=0
	struct VM_77fake miscValue;	// size=8, offset=0
	struct VM_78fake logicValue;   // size=8, offset=0
	long timer;					   // size=0, offset=0
	long times;					   // size=0, offset=0
	long lightGroup;			   // size=0, offset=0
	long farPlane;				   // size=0, offset=0
	long cameraAdjust;			   // size=0, offset=0
	long cameraMode;			   // size=0, offset=0
	long cameraLock;			   // size=0, offset=0
	long cameraUnlock;			   // size=0, offset=0
	long cameraSmooth;			   // size=0, offset=0
	long cameraTimer;			   // size=0, offset=0
	struct VM_79fake cameraShake;  // size=8, offset=0
	long cameraSave;			   // size=0, offset=0
	long cameraRestore;			   // size=0, offset=0
	struct _BGObject *bgObject;	// size=24, offset=0
	long value[2];				   // size=8, offset=0
	struct VM_80fake sound;		   // size=12, offset=0
	void *intro;				   // size=0, offset=0
	long deathZ;				   // size=0, offset=0
	struct VM_81fake dsignal;	  // size=8, offset=0
	void *mirror;				   // size=0, offset=0
	long fogNear;				   // size=0, offset=0
	long fogFar;				   // size=0, offset=0
	struct VM_82fake gotoFrame;	// size=8, offset=0
	struct VM_83fake changeModel;  // size=8, offset=0
	void *vmObject;				   // size=0, offset=0
	struct VM_84fake logic;		   // size=8, offset=0
	void *callSignal;			   // size=0, offset=0
	struct _SVector offset;		   // size=8, offset=0
	struct Signal *gotoLabel;	  // size=0, offset=0
	struct Signal *gosubLabel;	 // size=0, offset=0
	struct VM_85fake control;	  // size=8, offset=0
	struct VM_86fake zSignal;	  // size=12, offset=0
	struct VM_87fake StreamLevel;  // size=24, offset=0
	struct VM_88fake shards;	   // size=12, offset=0
	struct VM_89fake cameraSpline; // size=8, offset=0
	struct VM_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;			   // size=0, offset=0
	struct VM_91fake introFX;	  // size=8, offset=0
	struct VM_92fake introActive;  // size=8, offset=0
	struct VM_93fake levelChange;  // size=18, offset=0
	long blendStart;			   // size=0, offset=0
	struct VM_94fake setTimes;	 // size=8, offset=0
	struct VM_95fake color;		   // size=4, offset=0
	struct VM_96fake print;		   // size=12, offset=0
	long slideAngle;			   // size=0, offset=0
};

union VM_98fake // Hashcode: 0x3194D184 (dec: 831836548)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union VM_103fake // Hashcode: 0x0E5FC352 (dec: 241156946)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct VM_105fake // hashcode: 0xE5F804B6 (dec: -436730698)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xC283CF38 (dec: -1031549128), parent name: 'VM_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x75A9AEDB (dec: 1974054619), parent name: 'VM_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x8E3959E4 (dec: -1908844060), parent name: 'VM_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xEAA3B137 (dec: -358371017), parent name: 'VM_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x37AAC042 (dec: 933937218), parent name: 'VM_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x1BBF7708 (dec: 465532680), parent name: 'VM_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x249AB6B9 (dec: 614119097), parent name: 'VM_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_106fake // hashcode: 0x06DED9ED (dec: 115268077)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x35AE383E (dec: 900610110), parent name: 'VM_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x1040C0BC (dec: 272679100), parent name: 'VM_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xF4BB6FF7 (dec: -189042697), parent name: 'VM_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_107fake // hashcode: 0xE68F0942 (dec: -426833598)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x66DC5E7A (dec: 1725718138), parent name: 'VM_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x59589B6B (dec: 1498979179), parent name: 'VM_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x063950E7 (dec: 104419559), parent name: 'VM_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xDAB75FFD (dec: -625516547), parent name: 'VM_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x73B3C6C6 (dec: 1941161670), parent name: 'VM_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_108fake // hashcode: 0x6126357E (dec: 1629894014)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xBF075A2A (dec: -1090037206), parent name: 'VM_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0xDAD3647A (dec: -623680390), parent name: 'VM_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0xCE437162 (dec: -834440862), parent name: 'VM_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xAF92D337 (dec: -1349332169), parent name: 'VM_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x52F07D02 (dec: 1391492354), parent name: 'VM_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VM_109fake // hashcode: 0x94EF070A (dec: -1796274422)
{
	struct VM_105fake Cinematic; // size=28, offset=0 //  hashcode: 0x45B05EA2 (dec: 1169186466), parent name: 'VM_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct VM_106fake Idle;		 // size=20, offset=28 //  hashcode: 0x9ED876DF (dec: -1629980961), parent name: 'VM_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct VM_107fake Behind;	// size=28, offset=48 //  hashcode: 0x4CCCA57D (dec: 1288480125), parent name: 'VM_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct VM_108fake Follow;	// size=20, offset=76 //  hashcode: 0xACEB8343 (dec: -1393851581), parent name: 'VM_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union VM_199fake // Hashcode: 0x1A8628B8 (dec: 444999864)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

extern void VM_Tick(long time); // 0x8004F638

extern void VM_UpdateMorph(struct Level *level, int initFlg); // 0x8004F658

extern void VM_VMObjectSetTable(struct Level *level, struct _VMObject *vmobject, int table); // 0x8004FA30

#endif
