#ifndef BSP_H
#define BSP_H

extern struct LightInfo *sbsp_lightInfo; // offset 0x800D12AC

struct BSP_68fake // hashcode: 0xC8F374D7 (dec: -923568937)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x97B9BD53 (dec: -1749435053), parent name: 'BSP_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x1E895366 (dec: 512316262), parent name: 'BSP_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_69fake // hashcode: 0xB978A499 (dec: -1183275879)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xF68C1445 (dec: -158591931), parent name: 'BSP_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xD8A14437 (dec: -660519881), parent name: 'BSP_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_70fake // hashcode: 0x39759E1D (dec: 964009501)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xEAA9831F (dec: -357989601), parent name: 'BSP_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x5C35D8E2 (dec: 1547032802), parent name: 'BSP_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union BSP_71fake // Hashcode: 0x81368942 (dec: -2127132350)
{
	struct BSP_68fake callback; // size=8, offset=0
	struct BSP_69fake vector;   // size=12, offset=0
	struct BSP_70fake quat;		// size=16, offset=0
};

union BSP_72fake // Hashcode: 0x1CB63B8E (dec: 481704846)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union BSP_73fake // Hashcode: 0x12608A3F (dec: 308316735)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct BSP_74fake // hashcode: 0xC6855AE7 (dec: -964338969)
{
	union BSP_73fake size; // size=4, offset=0 //  hashcode: 0xB5F7BA3F (dec: -1242056129), parent name: 'BSP_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_75fake // hashcode: 0x8E219C49 (dec: -1910399927)
{
	short x;				// size=0, offset=0 //  hashcode: 0xB8B0EAF1 (dec: -1196365071), parent name: 'BSP_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x2D0452A1 (dec: 755258017), parent name: 'BSP_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xA09208C5 (dec: -1601042235), parent name: 'BSP_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x316701F9 (dec: 828834297), parent name: 'BSP_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x1F4F842E (dec: 525304878), parent name: 'BSP_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_76fake // hashcode: 0x1774909F (dec: 393515167)
{
	long index; // size=0, offset=0 //  hashcode: 0x28FB7F52 (dec: 687570770), parent name: 'BSP_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x94A01266 (dec: -1801448858), parent name: 'BSP_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_77fake // hashcode: 0x9D8BEFD4 (dec: -1651773484)
{
	long index; // size=0, offset=0 //  hashcode: 0xC0E7E6EF (dec: -1058543889), parent name: 'BSP_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xEB71CDD0 (dec: -344863280), parent name: 'BSP_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_78fake // hashcode: 0xEF12829F (dec: -283999585)
{
	long index; // size=0, offset=0 //  hashcode: 0x36005FF1 (dec: 905994225), parent name: 'BSP_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x37FAF352 (dec: 939193170), parent name: 'BSP_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_79fake // hashcode: 0x925E8018 (dec: -1839300584)
{
	long time;  // size=0, offset=0 //  hashcode: 0x166B7628 (dec: 376141352), parent name: 'BSP_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x7AA67DCF (dec: 2057731535), parent name: 'BSP_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_80fake // hashcode: 0xFF6498B5 (dec: -10184523)
{
	long action;   // size=0, offset=0 //  hashcode: 0x8A60A215 (dec: -1973378539), parent name: 'BSP_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x4D415134 (dec: 1296126260), parent name: 'BSP_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_81fake // hashcode: 0x1AAFB269 (dec: 447722089)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x63BFDBA7 (dec: 1673517991), parent name: 'BSP_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xB777008D (dec: -1216937843), parent name: 'BSP_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_82fake // hashcode: 0xF5C1E1E8 (dec: -171843096)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xFE67AA5F (dec: -26760609), parent name: 'BSP_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x06435836 (dec: 105076790), parent name: 'BSP_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_83fake // hashcode: 0xF5F2C7B8 (dec: -168638536)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xD19E87C5 (dec: -778139707), parent name: 'BSP_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xA6969E09 (dec: -1500078583), parent name: 'BSP_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_84fake // hashcode: 0x6B80DC1A (dec: 1803607066)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x5BF71E29 (dec: 1542921769), parent name: 'BSP_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xE59C1220 (dec: -442756576), parent name: 'BSP_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xAB22C27E (dec: -1423785346), parent name: 'BSP_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xBCDDC015 (dec: -1126318059), parent name: 'BSP_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xEEE6C076 (dec: -286867338), parent name: 'BSP_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_85fake // hashcode: 0x87BD6DF3 (dec: -2017628685)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x5440D1CF (dec: 1413534159), parent name: 'BSP_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x511E0677 (dec: 1360922231), parent name: 'BSP_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_86fake // hashcode: 0xEB80359D (dec: -343919203)
{
	short index;					// size=0, offset=0 //  hashcode: 0xC9785C03 (dec: -914859005), parent name: 'BSP_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x95550976 (dec: -1789589130), parent name: 'BSP_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xD1EDAD30 (dec: -772952784), parent name: 'BSP_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x4FF74069 (dec: 1341603945), parent name: 'BSP_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_87fake // hashcode: 0xA585BDE8 (dec: -1517961752)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xD44CFB4C (dec: -733152436), parent name: 'BSP_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xFD35A1A1 (dec: -46816863), parent name: 'BSP_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xB925A363 (dec: -1188715677), parent name: 'BSP_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_88fake // hashcode: 0x7B93C55F (dec: 2073281887)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x8F9327A2 (dec: -1886181470), parent name: 'BSP_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xC382FE08 (dec: -1014825464), parent name: 'BSP_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xC0E4BB3B (dec: -1058751685), parent name: 'BSP_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xCC8D0B2A (dec: -863171798), parent name: 'BSP_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x2B1DC4BC (dec: 723371196), parent name: 'BSP_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x1143626F (dec: 289628783), parent name: 'BSP_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x2804C01B (dec: 671399963), parent name: 'BSP_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_89fake // hashcode: 0x5FA7CAC9 (dec: 1604831945)
{
	long index;  // size=0, offset=0 //  hashcode: 0x32D2A96C (dec: 852666732), parent name: 'BSP_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x6F6C5067 (dec: 1869369447), parent name: 'BSP_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_90fake // hashcode: 0x6EA67FFE (dec: 1856405502)
{
	short type; // size=0, offset=0 //  hashcode: 0x1AD4E38C (dec: 450159500), parent name: 'BSP_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x6D974D02 (dec: 1838632194), parent name: 'BSP_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_91fake // hashcode: 0xBBC58E26 (dec: -1144680922)
{
	long time;   // size=0, offset=0 //  hashcode: 0x09E88C5C (dec: 166235228), parent name: 'BSP_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xAAF72573 (dec: -1426643597), parent name: 'BSP_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_92fake // hashcode: 0xE4285D5A (dec: -467116710)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xDC6E0859 (dec: -596768679), parent name: 'BSP_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xA4306FAF (dec: -1540329553), parent name: 'BSP_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_93fake // hashcode: 0xA3456C1A (dec: -1555731430)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x15A34171 (dec: 363020657), parent name: 'BSP_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x327DEC2E (dec: 847113262), parent name: 'BSP_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_94fake // hashcode: 0xED7026F1 (dec: -311417103)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xAC887F9F (dec: -1400340577), parent name: 'BSP_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x0A06BF2D (dec: 168214317), parent name: 'BSP_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_95fake // hashcode: 0xD5E5299B (dec: -706401893)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x1242B9A3 (dec: 306362787), parent name: 'BSP_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xEA61D2A1 (dec: -362687839), parent name: 'BSP_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x2889966C (dec: 680105580), parent name: 'BSP_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x3A2A9F62 (dec: 975871842), parent name: 'BSP_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_96fake // hashcode: 0x869AC80D (dec: -2036676595)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xCAC11EDA (dec: -893313318), parent name: 'BSP_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xC57CD4D2 (dec: -981674798), parent name: 'BSP_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x15DB6C47 (dec: 366701639), parent name: 'BSP_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x62A861C5 (dec: 1655202245), parent name: 'BSP_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xB82F36B1 (dec: -1204865359), parent name: 'BSP_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union BSP_97fake // Hashcode: 0x1FC760AD (dec: 533160109)
{
	struct BSP_74fake misc[3];		// size=12, offset=0
	struct _CameraKey *cameraKey;   // size=24, offset=0
	struct BSP_75fake teleport;		// size=16, offset=0
	struct BSP_76fake cameraValue;  // size=8, offset=0
	struct BSP_77fake miscValue;	// size=8, offset=0
	struct BSP_78fake logicValue;   // size=8, offset=0
	long timer;						// size=0, offset=0
	long times;						// size=0, offset=0
	long lightGroup;				// size=0, offset=0
	long farPlane;					// size=0, offset=0
	long cameraAdjust;				// size=0, offset=0
	long cameraMode;				// size=0, offset=0
	long cameraLock;				// size=0, offset=0
	long cameraUnlock;				// size=0, offset=0
	long cameraSmooth;				// size=0, offset=0
	long cameraTimer;				// size=0, offset=0
	struct BSP_79fake cameraShake;  // size=8, offset=0
	long cameraSave;				// size=0, offset=0
	long cameraRestore;				// size=0, offset=0
	struct _BGObject *bgObject;		// size=24, offset=0
	long value[2];					// size=8, offset=0
	struct BSP_80fake sound;		// size=12, offset=0
	void *intro;					// size=0, offset=0
	long deathZ;					// size=0, offset=0
	struct BSP_81fake dsignal;		// size=8, offset=0
	void *mirror;					// size=0, offset=0
	long fogNear;					// size=0, offset=0
	long fogFar;					// size=0, offset=0
	struct BSP_82fake gotoFrame;	// size=8, offset=0
	struct BSP_83fake changeModel;  // size=8, offset=0
	void *vmObject;					// size=0, offset=0
	struct BSP_84fake logic;		// size=8, offset=0
	void *callSignal;				// size=0, offset=0
	struct _SVector offset;			// size=8, offset=0
	struct Signal *gotoLabel;		// size=0, offset=0
	struct Signal *gosubLabel;		// size=0, offset=0
	struct BSP_85fake control;		// size=8, offset=0
	struct BSP_86fake zSignal;		// size=12, offset=0
	struct BSP_87fake StreamLevel;  // size=24, offset=0
	struct BSP_88fake shards;		// size=12, offset=0
	struct BSP_89fake cameraSpline; // size=8, offset=0
	struct BSP_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;				// size=0, offset=0
	struct BSP_91fake introFX;		// size=8, offset=0
	struct BSP_92fake introActive;  // size=8, offset=0
	struct BSP_93fake levelChange;  // size=18, offset=0
	long blendStart;				// size=0, offset=0
	struct BSP_94fake setTimes;		// size=8, offset=0
	struct BSP_95fake color;		// size=4, offset=0
	struct BSP_96fake print;		// size=12, offset=0
	long slideAngle;				// size=0, offset=0
};

union BSP_98fake // Hashcode: 0xD061A6FC (dec: -798906628)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

struct _SBSPLeaf // hashcode: 0xAD21B7BA (dec: -1390299206)
{
	struct _Sphere_noSq sphere; // size=8, offset=0 //  hashcode: 0xE223E229 (dec: -500964823), parent name: '_SBSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Intro **introList;   // size=76, offset=8 //  hashcode: 0xFBCDDD26 (dec: -70394586), parent name: '_SBSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numIntros;			// size=0, offset=12 //  hashcode: 0xAA4749BA (dec: -1438168646), parent name: '_SBSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;				// size=0, offset=14 //  hashcode: 0x16B0D313 (dec: 380687123), parent name: '_SBSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CDLight **lightList; // size=24, offset=16 //  hashcode: 0x7B3D8A98 (dec: 2067630744), parent name: '_SBSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numLights;			// size=0, offset=20 //  hashcode: 0x29713909 (dec: 695286025), parent name: '_SBSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;					// size=0, offset=22 //  hashcode: 0x4BD391E7 (dec: 1272156647), parent name: '_SBSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union BSP_103fake // Hashcode: 0x9B04D207 (dec: -1694182905)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct BSP_105fake // hashcode: 0x2D05FD9D (dec: 755367325)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x6D982276 (dec: 1838686838), parent name: 'BSP_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x8C11006F (dec: -1945042833), parent name: 'BSP_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x87E042B6 (dec: -2015345994), parent name: 'BSP_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x28CB7229 (dec: 684421673), parent name: 'BSP_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x2D2BB19C (dec: 757838236), parent name: 'BSP_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x7C9F2E39 (dec: 2090806841), parent name: 'BSP_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x5F58972B (dec: 1599641387), parent name: 'BSP_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_106fake // hashcode: 0xFF6000C4 (dec: -10485564)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x83769E0C (dec: -2089378292), parent name: 'BSP_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xC29309AB (dec: -1030551125), parent name: 'BSP_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x85C38CDA (dec: -2050781990), parent name: 'BSP_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_107fake // hashcode: 0xCAE14B43 (dec: -891204797)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xF57387F8 (dec: -176977928), parent name: 'BSP_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x2500970E (dec: 620795662), parent name: 'BSP_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x87C3D773 (dec: -2017208461), parent name: 'BSP_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xE74A464A (dec: -414562742), parent name: 'BSP_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xE5A693B4 (dec: -442068044), parent name: 'BSP_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_108fake // hashcode: 0x7ECEDD8B (dec: 2127486347)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xEB9A6A50 (dec: -342201776), parent name: 'BSP_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x0654F352 (dec: 106230610), parent name: 'BSP_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x7973B95D (dec: 2037627229), parent name: 'BSP_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xFDC0467E (dec: -37730690), parent name: 'BSP_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x6A52FCBA (dec: 1783823546), parent name: 'BSP_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_109fake // hashcode: 0xF4A997D6 (dec: -190212138)
{
	struct BSP_105fake Cinematic; // size=28, offset=0 //  hashcode: 0x3CB6A7AF (dec: 1018603439), parent name: 'BSP_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct BSP_106fake Idle;	  // size=20, offset=28 //  hashcode: 0xC6091882 (dec: -972482430), parent name: 'BSP_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct BSP_107fake Behind;	// size=28, offset=48 //  hashcode: 0xDFFCA0FF (dec: -537091841), parent name: 'BSP_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct BSP_108fake Follow;	// size=20, offset=76 //  hashcode: 0x0EC81923 (dec: 247994659), parent name: 'BSP_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_180fake // hashcode: 0x92E375E9 (dec: -1830586903)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x8B32A37F (dec: -1959615617), parent name: 'BSP_180fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x7A5AD027 (dec: 2052771879), parent name: 'BSP_180fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSP_181fake // hashcode: 0x4A6302AA (dec: 1248002730)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x7C7A5044 (dec: 2088390724), parent name: 'BSP_181fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x3E4078BC (dec: 1044412604), parent name: 'BSP_181fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0xC940AD8C (dec: -918508148), parent name: 'BSP_181fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x4B7BFD37 (dec: 1266416951), parent name: 'BSP_181fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x48D81888 (dec: 1222121608), parent name: 'BSP_181fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x1F6F9A4E (dec: 527407694), parent name: 'BSP_181fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union BSP_182fake // Hashcode: 0x9A617198 (dec: -1704889960)
{
	struct BSP_180fake flame; // size=8, offset=0
	struct BSP_181fake phys;  // size=12, offset=0
};

union BSP_208fake // Hashcode: 0x2E8AEFCF (dec: 780857295)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct BSPScratch // hashcode: 0x17CFF45B (dec: 399504475)
{
	struct MATRIX vv[2];	   // size=64, offset=0 //  hashcode: 0xE802C4A2 (dec: -402471774), parent name: 'BSPScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX camMatrix;   // size=32, offset=64 //  hashcode: 0x56CBAA1B (dec: 1456187931), parent name: 'BSPScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct VECTOR dpv[3];	  // size=48, offset=96 //  hashcode: 0x9A0101FE (dec: -1711209986), parent name: 'BSPScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long d[6];				   // size=24, offset=144 //  hashcode: 0x6DB8C4A8 (dec: 1840825512), parent name: 'BSPScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX boundMatrix; // size=32, offset=168 //  hashcode: 0x67C3AD98 (dec: 1740877208), parent name: 'BSPScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long in_spectral;		   // size=0, offset=200 //  hashcode: 0x2455087B (dec: 609552507), parent name: 'BSPScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct _SBSPLeaf SBSPLeaf;

typedef void asm_fn();

typedef long hook_fn_1();

typedef long hook_fn_2();

typedef long hook_fn_3();

typedef long hook_fn_4();

typedef long hook_fn_5();

typedef long hook_fn_6();

typedef long hook_fn_7();

typedef long hook_fn_8();

extern void SBSP_IntroduceInstances(struct _Terrain *terrain, int unitID); // 0x8003D928

extern void SBSP_IntroduceInstancesAndLights(struct _Terrain *terrain, struct _CameraCore_Type *cameraCore, struct LightInfo *lightInfo, int unitID); // 0x8003D98C

#endif
