#ifndef PHYSICS_H
#define PHYSICS_H

struct PHYSICS_68fake // hashcode: 0xB946C92B (dec: -1186543317)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x6DA5F354 (dec: 1839592276), parent name: 'PHYSICS_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x9171AF6E (dec: -1854820498), parent name: 'PHYSICS_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_69fake // hashcode: 0x4BE571EF (dec: 1273328111)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xA8F5D6CF (dec: -1460283697), parent name: 'PHYSICS_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xC6359BE2 (dec: -969565214), parent name: 'PHYSICS_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_70fake // hashcode: 0x5B58D2D9 (dec: 1532547801)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x6AC6BC38 (dec: 1791409208), parent name: 'PHYSICS_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xAA70B311 (dec: -1435454703), parent name: 'PHYSICS_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PHYSICS_71fake // Hashcode: 0x71AB8CEE (dec: 1907068142)
{
	struct PHYSICS_68fake callback; // size=8, offset=0
	struct PHYSICS_69fake vector;   // size=12, offset=0
	struct PHYSICS_70fake quat;		// size=16, offset=0
};

union PHYSICS_72fake // Hashcode: 0x4F67EB4B (dec: 1332210507)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PHYSICS_73fake // Hashcode: 0x2F1B946A (dec: 790336618)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct PHYSICS_74fake // hashcode: 0xCD440845 (dec: -851179451)
{
	union PHYSICS_73fake size; // size=4, offset=0 //  hashcode: 0xABEF8B62 (dec: -1410364574), parent name: 'PHYSICS_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_75fake // hashcode: 0xDCBCAC95 (dec: -591614827)
{
	short x;				// size=0, offset=0 //  hashcode: 0xB84FE3AE (dec: -1202723922), parent name: 'PHYSICS_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x68E90728 (dec: 1760102184), parent name: 'PHYSICS_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x64A55FE4 (dec: 1688559588), parent name: 'PHYSICS_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xD6DE59E8 (dec: -690071064), parent name: 'PHYSICS_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x7DD0E646 (dec: 2110842438), parent name: 'PHYSICS_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_76fake // hashcode: 0x476DED8D (dec: 1198386573)
{
	long index; // size=0, offset=0 //  hashcode: 0xE13BB893 (dec: -516179821), parent name: 'PHYSICS_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xD26804A4 (dec: -764935004), parent name: 'PHYSICS_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_77fake // hashcode: 0x1E312B4F (dec: 506538831)
{
	long index; // size=0, offset=0 //  hashcode: 0x3B8BEE1D (dec: 999026205), parent name: 'PHYSICS_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x73DBACB9 (dec: 1943776441), parent name: 'PHYSICS_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_78fake // hashcode: 0x3ACCA2C5 (dec: 986489541)
{
	long index; // size=0, offset=0 //  hashcode: 0xCBA0D15A (dec: -878653094), parent name: 'PHYSICS_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x60C62CE5 (dec: 1623600357), parent name: 'PHYSICS_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_79fake // hashcode: 0xFFDB9CCA (dec: -2384694)
{
	long time;  // size=0, offset=0 //  hashcode: 0xDC58BE3B (dec: -598163909), parent name: 'PHYSICS_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xDF3373D1 (dec: -550276143), parent name: 'PHYSICS_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_80fake // hashcode: 0xB26E55C6 (dec: -1301391930)
{
	long action;   // size=0, offset=0 //  hashcode: 0x2A393392 (dec: 708391826), parent name: 'PHYSICS_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xA8F7591E (dec: -1460184802), parent name: 'PHYSICS_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_81fake // hashcode: 0x1B48D23D (dec: 457757245)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x1D5FB2C8 (dec: 492810952), parent name: 'PHYSICS_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x2578107B (dec: 628625531), parent name: 'PHYSICS_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_82fake // hashcode: 0xFB1D87D1 (dec: -81950767)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xF375B832 (dec: -210388942), parent name: 'PHYSICS_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x834E2528 (dec: -2092030680), parent name: 'PHYSICS_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_83fake // hashcode: 0x76979DD5 (dec: 1989647829)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x5DB86917 (dec: 1572366615), parent name: 'PHYSICS_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x1C5FD660 (dec: 476042848), parent name: 'PHYSICS_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_84fake // hashcode: 0x5BA85984 (dec: 1537759620)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xA5B7F728 (dec: -1514670296), parent name: 'PHYSICS_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x60CA958B (dec: 1623889291), parent name: 'PHYSICS_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x1527DFF6 (dec: 354934774), parent name: 'PHYSICS_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x44FD68BF (dec: 1157458111), parent name: 'PHYSICS_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xE9841B13 (dec: -377218285), parent name: 'PHYSICS_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_85fake // hashcode: 0xB472780A (dec: -1267566582)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xEDA07F07 (dec: -308248825), parent name: 'PHYSICS_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x273687C5 (dec: 657885125), parent name: 'PHYSICS_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_86fake // hashcode: 0x7174102F (dec: 1903431727)
{
	short index;					// size=0, offset=0 //  hashcode: 0xEC54B364 (dec: -329993372), parent name: 'PHYSICS_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x33CCB1C3 (dec: 869052867), parent name: 'PHYSICS_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x4C60B5D1 (dec: 1281406417), parent name: 'PHYSICS_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xCE5B47EA (dec: -832878614), parent name: 'PHYSICS_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_87fake // hashcode: 0x3754F673 (dec: 928314995)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x1507ED6D (dec: 352841069), parent name: 'PHYSICS_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xC0380C5E (dec: -1070068642), parent name: 'PHYSICS_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x02F04E7C (dec: 49303164), parent name: 'PHYSICS_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_88fake // hashcode: 0x8F764419 (dec: -1888074727)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x57DD08E1 (dec: 1474103521), parent name: 'PHYSICS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x8FD8C6EC (dec: -1881618708), parent name: 'PHYSICS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xE6E95988 (dec: -420914808), parent name: 'PHYSICS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x28EBBC18 (dec: 686537752), parent name: 'PHYSICS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x19FF5A9E (dec: 436165278), parent name: 'PHYSICS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x71EC54EC (dec: 1911313644), parent name: 'PHYSICS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xB489E7B6 (dec: -1266030666), parent name: 'PHYSICS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_89fake // hashcode: 0x54504564 (dec: 1414546788)
{
	long index;  // size=0, offset=0 //  hashcode: 0x6693ABF1 (dec: 1720953841), parent name: 'PHYSICS_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x19C2D4BE (dec: 432198846), parent name: 'PHYSICS_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_90fake // hashcode: 0xD25C4A56 (dec: -765703594)
{
	short type; // size=0, offset=0 //  hashcode: 0xD011FCD2 (dec: -804127534), parent name: 'PHYSICS_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x9EB60F53 (dec: -1632235693), parent name: 'PHYSICS_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_91fake // hashcode: 0x3A8A8C0C (dec: 982158348)
{
	long time;   // size=0, offset=0 //  hashcode: 0x4E60347E (dec: 1314927742), parent name: 'PHYSICS_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x24F81DF2 (dec: 620240370), parent name: 'PHYSICS_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_92fake // hashcode: 0xC33107B0 (dec: -1020196944)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x0E7B6517 (dec: 242967831), parent name: 'PHYSICS_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xE8D84C10 (dec: -388477936), parent name: 'PHYSICS_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_93fake // hashcode: 0x131F1DA8 (dec: 320806312)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xF7254263 (dec: -148553117), parent name: 'PHYSICS_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xC83E8D44 (dec: -935424700), parent name: 'PHYSICS_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_94fake // hashcode: 0x79640C2C (dec: 2036599852)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x7251891C (dec: 1917946140), parent name: 'PHYSICS_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x536D9B42 (dec: 1399692098), parent name: 'PHYSICS_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_95fake // hashcode: 0x5B9C8A9C (dec: 1536985756)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x4E51E612 (dec: 1313990162), parent name: 'PHYSICS_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x9EFB59B9 (dec: -1627694663), parent name: 'PHYSICS_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xABA3DA56 (dec: -1415325098), parent name: 'PHYSICS_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xB6F1B861 (dec: -1225672607), parent name: 'PHYSICS_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_96fake // hashcode: 0xDD0CCD6B (dec: -586363541)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x0843A802 (dec: 138651650), parent name: 'PHYSICS_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xF8397594 (dec: -130452076), parent name: 'PHYSICS_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xCE092C56 (dec: -838259626), parent name: 'PHYSICS_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x5F93B7BA (dec: 1603516346), parent name: 'PHYSICS_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x208B62FA (dec: 546005754), parent name: 'PHYSICS_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PHYSICS_97fake // Hashcode: 0xBFEB76FD (dec: -1075087619)
{
	struct PHYSICS_74fake misc[3];		// size=12, offset=0
	struct _CameraKey *cameraKey;		// size=24, offset=0
	struct PHYSICS_75fake teleport;		// size=16, offset=0
	struct PHYSICS_76fake cameraValue;  // size=8, offset=0
	struct PHYSICS_77fake miscValue;	// size=8, offset=0
	struct PHYSICS_78fake logicValue;   // size=8, offset=0
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
	struct PHYSICS_79fake cameraShake;  // size=8, offset=0
	long cameraSave;					// size=0, offset=0
	long cameraRestore;					// size=0, offset=0
	struct _BGObject *bgObject;			// size=24, offset=0
	long value[2];						// size=8, offset=0
	struct PHYSICS_80fake sound;		// size=12, offset=0
	void *intro;						// size=0, offset=0
	long deathZ;						// size=0, offset=0
	struct PHYSICS_81fake dsignal;		// size=8, offset=0
	void *mirror;						// size=0, offset=0
	long fogNear;						// size=0, offset=0
	long fogFar;						// size=0, offset=0
	struct PHYSICS_82fake gotoFrame;	// size=8, offset=0
	struct PHYSICS_83fake changeModel;  // size=8, offset=0
	void *vmObject;						// size=0, offset=0
	struct PHYSICS_84fake logic;		// size=8, offset=0
	void *callSignal;					// size=0, offset=0
	struct _SVector offset;				// size=8, offset=0
	struct Signal *gotoLabel;			// size=0, offset=0
	struct Signal *gosubLabel;			// size=0, offset=0
	struct PHYSICS_85fake control;		// size=8, offset=0
	struct PHYSICS_86fake zSignal;		// size=12, offset=0
	struct PHYSICS_87fake StreamLevel;  // size=24, offset=0
	struct PHYSICS_88fake shards;		// size=12, offset=0
	struct PHYSICS_89fake cameraSpline; // size=8, offset=0
	struct PHYSICS_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;					// size=0, offset=0
	struct PHYSICS_91fake introFX;		// size=8, offset=0
	struct PHYSICS_92fake introActive;  // size=8, offset=0
	struct PHYSICS_93fake levelChange;  // size=18, offset=0
	long blendStart;					// size=0, offset=0
	struct PHYSICS_94fake setTimes;		// size=8, offset=0
	struct PHYSICS_95fake color;		// size=4, offset=0
	struct PHYSICS_96fake print;		// size=12, offset=0
	long slideAngle;					// size=0, offset=0
};

union PHYSICS_98fake // Hashcode: 0x054420DB (dec: 88350939)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union PHYSICS_103fake // Hashcode: 0x4BD92F15 (dec: 1272524565)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct PHYSICS_105fake // hashcode: 0x9F2C8588 (dec: -1624472184)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xB630F968 (dec: -1238304408), parent name: 'PHYSICS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x303DDD63 (dec: 809360739), parent name: 'PHYSICS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0xDFEBCF4C (dec: -538194100), parent name: 'PHYSICS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x8666175F (dec: -2040129697), parent name: 'PHYSICS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x04089E1A (dec: 67673626), parent name: 'PHYSICS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xD4738C48 (dec: -730624952), parent name: 'PHYSICS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xF655DF31 (dec: -162144463), parent name: 'PHYSICS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_106fake // hashcode: 0x67C26D99 (dec: 1740795289)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x57F7990E (dec: 1475844366), parent name: 'PHYSICS_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x9C6ABB24 (dec: -1670726876), parent name: 'PHYSICS_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x34AAD5F7 (dec: 883611127), parent name: 'PHYSICS_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_107fake // hashcode: 0x51F541D4 (dec: 1375027668)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xDDA21EBA (dec: -576577862), parent name: 'PHYSICS_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xAA1CA2C3 (dec: -1440963901), parent name: 'PHYSICS_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xE3DEE09F (dec: -471932769), parent name: 'PHYSICS_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x35DCB605 (dec: 903656965), parent name: 'PHYSICS_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x86C545EE (dec: -2033891858), parent name: 'PHYSICS_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_108fake // hashcode: 0x2BDC72F3 (dec: 735867635)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x91029672 (dec: -1862101390), parent name: 'PHYSICS_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x6DB948B2 (dec: 1840859314), parent name: 'PHYSICS_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0xF3F86012 (dec: -201826286), parent name: 'PHYSICS_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xB2651ED7 (dec: -1301995817), parent name: 'PHYSICS_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xC3397282 (dec: -1019645310), parent name: 'PHYSICS_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_109fake // hashcode: 0xC9F7DBFE (dec: -906503170)
{
	struct PHYSICS_105fake Cinematic; // size=28, offset=0 //  hashcode: 0x3588A51D (dec: 898147613), parent name: 'PHYSICS_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PHYSICS_106fake Idle;	  // size=20, offset=28 //  hashcode: 0x7AE2451F (dec: 2061649183), parent name: 'PHYSICS_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PHYSICS_107fake Behind;	// size=28, offset=48 //  hashcode: 0x872D8070 (dec: -2027061136), parent name: 'PHYSICS_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PHYSICS_108fake Follow;	// size=20, offset=76 //  hashcode: 0x386FA9E5 (dec: 946842085), parent name: 'PHYSICS_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PHYSICS_203fake // Hashcode: 0x0B2D1FCE (dec: 187506638)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct PHYSICS_219fake // hashcode: 0x251771F4 (dec: 622293492)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0xC43D0627 (dec: -1002633689), parent name: 'PHYSICS_219fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x4032CEF2 (dec: 1077071602), parent name: 'PHYSICS_219fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSICS_220fake // hashcode: 0xB317789A (dec: -1290307430)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0xF78C0582 (dec: -141818494), parent name: 'PHYSICS_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x2A78247A (dec: 712516730), parent name: 'PHYSICS_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x6015ABCA (dec: 1612032970), parent name: 'PHYSICS_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x93FAB8EC (dec: -1812285204), parent name: 'PHYSICS_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x77A402B3 (dec: 2007237299), parent name: 'PHYSICS_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x6F91AA70 (dec: 1871817328), parent name: 'PHYSICS_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PHYSICS_221fake // Hashcode: 0x366BB4FD (dec: 913028349)
{
	struct PHYSICS_219fake flame; // size=8, offset=0
	struct PHYSICS_220fake phys;  // size=12, offset=0
};

extern void SetNoPtCollideInFamily(struct _Instance *instance); // 0x80074628

extern void ResetNoPtCollideInFamily(struct _Instance *instance); // 0x80074670

extern void PHYSICS_CheckLineInWorld(struct _Instance *instance, struct _PCollideInfo *pcollideInfo); // 0x800746BC

extern void PHYSICS_CheckLineInWorldMask(struct _Instance *instance, struct _PCollideInfo *pcollideInfo); // 0x800746E0

extern int PhysicsCheckLinkedMove(struct _Instance *instance, int Data, short Mode); // 0x80074754

extern void PhysicsDefaultLinkedMoveResponse(struct _Instance *instance, struct evPhysicsLinkedMoveData *Data, int updateTransforms); // 0x80074BB0

extern int PhysicsCheckGravity(struct _Instance *instance, int Data, short Mode); // 0x80074C38

extern void PhysicsDefaultGravityResponse(struct _Instance *instance, struct evPhysicsGravityData *Data); // 0x800753F0

extern int PhysicsCheckEdgeGrabbing(struct _Instance *instance, struct GameTracker *gameTracker, int Data, short Mode); // 0x80075468

extern void PhysicsDefaultEdgeGrabResponse(struct _Instance *instance, struct evPhysicsEdgeData *Data, int blockFlag); // 0x80075B20

extern int PhysicsCheckSliding(struct _Instance *instance, int Data, short Mode); // 0x80075DC4

extern int PhysicsUpdateTface(struct _Instance *instance, int Data); // 0x80076270

extern int PhysicsCheckBlockers(struct _Instance *instance, struct GameTracker *gameTracker, int Data, short Mode); // 0x8007636C

extern int PhysicsCheckSwim(struct _Instance *instance, int Data, short Mode); // 0x8007670C

extern int PhysicsDefaultCheckSwimResponse(struct _Instance *instance, struct evPhysicsSwimData *Data); // 0x800768FC

extern void PhysicsForceSetWater(struct _Instance *instance, int *Time, int Depth, int rate, int maxAmplitude); // 0x80076AF4

extern int PhysicsCheckLOS(struct _Instance *instance, int Data, int Mode); // 0x80076BCC

extern int PhysicsCheckDropHeight(struct _Instance *instance, int Data, int Mode); // 0x80076BFC

extern int PhysicsCheckDropOff(struct _Instance *instance, int Data, short Mode); // 0x80076E8C

extern int PhysicsFollowWall(struct _Instance *instance, struct GameTracker *gameTracker, int Data, short Mode); // 0x800770AC

extern void PhysicsMoveLocalZClamp(struct _Instance *instance, long segment, long time, long clamp); // 0x800775BC

extern void PhysicsMove(struct _Instance *instance, struct _Position *position, long time); // 0x80077694

extern void PhysicsSetVelFromZRot(struct _Instance *instance, short angle, long magnitude); // 0x80077830

extern void PhysicsSetVelFromRot(struct _Instance *instance, struct _Rotation *rot, long magnitude); // 0x800778A0

extern void PHYSICS_SetVAndAFromRot(struct _Instance *instance, struct _Rotation *rot, long v, long a); // 0x80077910

extern long PHYSICS_FindAFromDAndT(long d, long t); // 0x80077A00

extern long PHYSICS_FindVFromAAndD(long a, long d); // 0x80077A3C

extern void PHYSICS_StopIfCloseToTarget(struct _Instance *instance, int x, int y, int z); // 0x80077A74

extern int PHYSICS_CheckForTerrainCollide(struct _Instance *instance, struct SVECTOR *startVec, struct SVECTOR *endVec, int segment); // 0x80077B54

extern int PHYSICS_CheckForObjectCollide(struct _Instance *instance, struct SVECTOR *startVec, struct SVECTOR *endVec, int segment); // 0x80077B9C

extern int PHYSICS_CheckForValidMove(struct _Instance *instance, struct SVECTOR *startVec, struct SVECTOR *endVec, int segment); // 0x80077BE0

extern int PHYSICS_CheckFaceStick(struct _PCollideInfo *CInfo); // 0x80077C4C

extern int PHYSICS_CheckDontGrabEdge(struct _PCollideInfo *CInfo); // 0x80077CB0

extern void PHYSICS_GenericLineCheckSetup(short x, short y, short z, struct SVECTOR *inVec); // 0x80077DD8

extern void PHYSICS_GenericLineCheck(struct _Instance *instance, struct MATRIX *transMat, struct MATRIX *rotMat, struct _PCollideInfo *cInfo); // 0x80077DE8

extern void PHYSICS_GenericLineCheckMask(struct _Instance *instance, struct MATRIX *transMat, struct MATRIX *rotMat, struct _PCollideInfo *cInfo); // 0x80077E0C

#endif
