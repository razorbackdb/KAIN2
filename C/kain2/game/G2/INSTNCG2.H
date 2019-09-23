#ifndef INSTNCG2_H
#define INSTNCG2_H

struct INSTNCG2_20fake // hashcode: 0x10A11C27 (dec: 278993959)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x36244D82 (dec: 908348802), parent name: 'INSTNCG2_20fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x3FC7CB04 (dec: 1070058244), parent name: 'INSTNCG2_20fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_21fake // hashcode: 0x0785138D (dec: 126161805)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xA7256EF9 (dec: -1490718983), parent name: 'INSTNCG2_21fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x0DBEFEE1 (dec: 230620897), parent name: 'INSTNCG2_21fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_22fake // hashcode: 0x8F2E1AAE (dec: -1892803922)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x0A9A1B6B (dec: 177871723), parent name: 'INSTNCG2_22fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x4215C3EF (dec: 1108722671), parent name: 'INSTNCG2_22fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union INSTNCG2_23fake // Hashcode: 0x7E6DF599 (dec: 2121135513)
{
	struct INSTNCG2_20fake callback; // size=8, offset=0
	struct INSTNCG2_21fake vector;   // size=12, offset=0
	struct INSTNCG2_22fake quat;	 // size=16, offset=0
};

union INSTNCG2_72fake // Hashcode: 0x7883E999 (dec: 2021910937)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union INSTNCG2_73fake // Hashcode: 0xBC9CFF26 (dec: -1130561754)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct INSTNCG2_74fake // hashcode: 0xC1D2CCD0 (dec: -1043149616)
{
	union INSTNCG2_73fake size; // size=4, offset=0 //  hashcode: 0x321AA56A (dec: 840607082), parent name: 'INSTNCG2_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_75fake // hashcode: 0xF41D8CE3 (dec: -199389981)
{
	short x;				// size=0, offset=0 //  hashcode: 0x0226A7CC (dec: 36087756), parent name: 'INSTNCG2_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xCAA97A72 (dec: -894862734), parent name: 'INSTNCG2_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xE33310EA (dec: -483192598), parent name: 'INSTNCG2_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x96D90761 (dec: -1764161695), parent name: 'INSTNCG2_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x19CB03A4 (dec: 432735140), parent name: 'INSTNCG2_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_76fake // hashcode: 0x01266C38 (dec: 19295288)
{
	long index; // size=0, offset=0 //  hashcode: 0x58D3E195 (dec: 1490280853), parent name: 'INSTNCG2_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x0AB9108A (dec: 179900554), parent name: 'INSTNCG2_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_77fake // hashcode: 0xFF98B580 (dec: -6769280)
{
	long index; // size=0, offset=0 //  hashcode: 0x2E5A9B33 (dec: 777689907), parent name: 'INSTNCG2_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xDDE8D3E4 (dec: -571943964), parent name: 'INSTNCG2_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_78fake // hashcode: 0x2CB44778 (dec: 750012280)
{
	long index; // size=0, offset=0 //  hashcode: 0x08196B6D (dec: 135883629), parent name: 'INSTNCG2_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x6EFACED3 (dec: 1861930707), parent name: 'INSTNCG2_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_79fake // hashcode: 0x6F840EA1 (dec: 1870925473)
{
	long time;  // size=0, offset=0 //  hashcode: 0x368384D4 (dec: 914588884), parent name: 'INSTNCG2_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xE07F838A (dec: -528514166), parent name: 'INSTNCG2_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_80fake // hashcode: 0xA6A5014F (dec: -1499135665)
{
	long action;   // size=0, offset=0 //  hashcode: 0x2BF3ADB4 (dec: 737390004), parent name: 'INSTNCG2_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x7B5ABF60 (dec: 2069544800), parent name: 'INSTNCG2_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_81fake // hashcode: 0x3F5AF64E (dec: 1062925902)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x3F6CF846 (dec: 1064106054), parent name: 'INSTNCG2_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x51C2ACF5 (dec: 1371712757), parent name: 'INSTNCG2_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_82fake // hashcode: 0x39FAC4FD (dec: 972735741)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x18DE708B (dec: 417230987), parent name: 'INSTNCG2_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0xA316AD20 (dec: -1558794976), parent name: 'INSTNCG2_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_83fake // hashcode: 0x415244D6 (dec: 1095910614)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x309893AD (dec: 815305645), parent name: 'INSTNCG2_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xF16264EE (dec: -245209874), parent name: 'INSTNCG2_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_84fake // hashcode: 0x0055E57B (dec: 5629307)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xC24D2E65 (dec: -1035129243), parent name: 'INSTNCG2_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x1DC32849 (dec: 499329097), parent name: 'INSTNCG2_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x3B895041 (dec: 998854721), parent name: 'INSTNCG2_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xE8B03E3C (dec: -391102916), parent name: 'INSTNCG2_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xB753258D (dec: -1219287667), parent name: 'INSTNCG2_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_85fake // hashcode: 0xB763500A (dec: -1218228214)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x1CAB9FB5 (dec: 481009589), parent name: 'INSTNCG2_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xD8540BC3 (dec: -665580605), parent name: 'INSTNCG2_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_86fake // hashcode: 0x461D9FDA (dec: 1176346586)
{
	short index;					// size=0, offset=0 //  hashcode: 0x2EA0BA01 (dec: 782285313), parent name: 'INSTNCG2_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x571879E2 (dec: 1461221858), parent name: 'INSTNCG2_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xF3A6AD0B (dec: -207180533), parent name: 'INSTNCG2_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xD097F271 (dec: -795348367), parent name: 'INSTNCG2_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_87fake // hashcode: 0x6057C4E7 (dec: 1616364775)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x064A5427 (dec: 105534503), parent name: 'INSTNCG2_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x4BE14FA8 (dec: 1273057192), parent name: 'INSTNCG2_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x56028346 (dec: 1443005254), parent name: 'INSTNCG2_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_88fake // hashcode: 0x4F17F474 (dec: 1326969972)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x872E2BBA (dec: -2027017286), parent name: 'INSTNCG2_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x4A92B30E (dec: 1251128078), parent name: 'INSTNCG2_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x62ECBD32 (dec: 1659682098), parent name: 'INSTNCG2_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xACD6D832 (dec: -1395206094), parent name: 'INSTNCG2_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x72A43FE4 (dec: 1923366884), parent name: 'INSTNCG2_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xE49B80EB (dec: -459570965), parent name: 'INSTNCG2_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x60FDF1E7 (dec: 1627255271), parent name: 'INSTNCG2_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_89fake // hashcode: 0x459C3EB4 (dec: 1167867572)
{
	long index;  // size=0, offset=0 //  hashcode: 0x54D681AF (dec: 1423344047), parent name: 'INSTNCG2_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xC68425F3 (dec: -964418061), parent name: 'INSTNCG2_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_90fake // hashcode: 0x84ADD26D (dec: -2068983187)
{
	short type; // size=0, offset=0 //  hashcode: 0xB619C77F (dec: -1239824513), parent name: 'INSTNCG2_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x32AE7F05 (dec: 850296581), parent name: 'INSTNCG2_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_91fake // hashcode: 0xDB13A0EA (dec: -619470614)
{
	long time;   // size=0, offset=0 //  hashcode: 0x2A9BEE48 (dec: 714862152), parent name: 'INSTNCG2_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xF03ED244 (dec: -264318396), parent name: 'INSTNCG2_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_92fake // hashcode: 0x488A155C (dec: 1217008988)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x1558B4AD (dec: 358134957), parent name: 'INSTNCG2_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x26FF0A13 (dec: 654248467), parent name: 'INSTNCG2_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_93fake // hashcode: 0x13900D01 (dec: 328207617)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xAC65036B (dec: -1402666133), parent name: 'INSTNCG2_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x6FAF7896 (dec: 1873770646), parent name: 'INSTNCG2_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_94fake // hashcode: 0xA3E8137C (dec: -1545071748)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xA7A33132 (dec: -1482477262), parent name: 'INSTNCG2_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x20CCD9C9 (dec: 550296009), parent name: 'INSTNCG2_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_95fake // hashcode: 0xED004FA8 (dec: -318746712)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0xA92CF26C (dec: -1456672148), parent name: 'INSTNCG2_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x03D773C0 (dec: 64451520), parent name: 'INSTNCG2_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xF1285B43 (dec: -249013437), parent name: 'INSTNCG2_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xB4E3792B (dec: -1260160725), parent name: 'INSTNCG2_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_96fake // hashcode: 0x9E1E0658 (dec: -1642199464)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x5817B15C (dec: 1477947740), parent name: 'INSTNCG2_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x7F00CB6E (dec: 2130758510), parent name: 'INSTNCG2_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x1B0CD14D (dec: 453824845), parent name: 'INSTNCG2_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x453E0891 (dec: 1161693329), parent name: 'INSTNCG2_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xD8B24BA8 (dec: -659403864), parent name: 'INSTNCG2_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union INSTNCG2_97fake // Hashcode: 0x673F1B0B (dec: 1732188939)
{
	struct INSTNCG2_74fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;		 // size=24, offset=0
	struct INSTNCG2_75fake teleport;	 // size=16, offset=0
	struct INSTNCG2_76fake cameraValue;  // size=8, offset=0
	struct INSTNCG2_77fake miscValue;	// size=8, offset=0
	struct INSTNCG2_78fake logicValue;   // size=8, offset=0
	long timer;							 // size=0, offset=0
	long times;							 // size=0, offset=0
	long lightGroup;					 // size=0, offset=0
	long farPlane;						 // size=0, offset=0
	long cameraAdjust;					 // size=0, offset=0
	long cameraMode;					 // size=0, offset=0
	long cameraLock;					 // size=0, offset=0
	long cameraUnlock;					 // size=0, offset=0
	long cameraSmooth;					 // size=0, offset=0
	long cameraTimer;					 // size=0, offset=0
	struct INSTNCG2_79fake cameraShake;  // size=8, offset=0
	long cameraSave;					 // size=0, offset=0
	long cameraRestore;					 // size=0, offset=0
	struct _BGObject *bgObject;			 // size=24, offset=0
	long value[2];						 // size=8, offset=0
	struct INSTNCG2_80fake sound;		 // size=12, offset=0
	void *intro;						 // size=0, offset=0
	long deathZ;						 // size=0, offset=0
	struct INSTNCG2_81fake dsignal;		 // size=8, offset=0
	void *mirror;						 // size=0, offset=0
	long fogNear;						 // size=0, offset=0
	long fogFar;						 // size=0, offset=0
	struct INSTNCG2_82fake gotoFrame;	// size=8, offset=0
	struct INSTNCG2_83fake changeModel;  // size=8, offset=0
	void *vmObject;						 // size=0, offset=0
	struct INSTNCG2_84fake logic;		 // size=8, offset=0
	void *callSignal;					 // size=0, offset=0
	struct _SVector offset;				 // size=8, offset=0
	struct Signal *gotoLabel;			 // size=0, offset=0
	struct Signal *gosubLabel;			 // size=0, offset=0
	struct INSTNCG2_85fake control;		 // size=8, offset=0
	struct INSTNCG2_86fake zSignal;		 // size=12, offset=0
	struct INSTNCG2_87fake StreamLevel;  // size=24, offset=0
	struct INSTNCG2_88fake shards;		 // size=12, offset=0
	struct INSTNCG2_89fake cameraSpline; // size=8, offset=0
	struct INSTNCG2_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;					 // size=0, offset=0
	struct INSTNCG2_91fake introFX;		 // size=8, offset=0
	struct INSTNCG2_92fake introActive;  // size=8, offset=0
	struct INSTNCG2_93fake levelChange;  // size=18, offset=0
	long blendStart;					 // size=0, offset=0
	struct INSTNCG2_94fake setTimes;	 // size=8, offset=0
	struct INSTNCG2_95fake color;		 // size=4, offset=0
	struct INSTNCG2_96fake print;		 // size=12, offset=0
	long slideAngle;					 // size=0, offset=0
};

union INSTNCG2_98fake // Hashcode: 0xBEFFECD5 (dec: -1090523947)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union INSTNCG2_103fake // Hashcode: 0x290C4086 (dec: 688668806)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct INSTNCG2_105fake // hashcode: 0x537618DD (dec: 1400248541)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xC525BD91 (dec: -987382383), parent name: 'INSTNCG2_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x8C0E476D (dec: -1945221267), parent name: 'INSTNCG2_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x8F08C44A (dec: -1895250870), parent name: 'INSTNCG2_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xEBDBF2BD (dec: -337907011), parent name: 'INSTNCG2_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x6E5AA2D3 (dec: 1851433683), parent name: 'INSTNCG2_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x6A29F996 (dec: 1781135766), parent name: 'INSTNCG2_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x643DA17B (dec: 1681760635), parent name: 'INSTNCG2_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_106fake // hashcode: 0x1FF6A4D5 (dec: 536257749)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x0482C1FC (dec: 75678204), parent name: 'INSTNCG2_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xFD121946 (dec: -49145530), parent name: 'INSTNCG2_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xDE3B4A2A (dec: -566539734), parent name: 'INSTNCG2_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_107fake // hashcode: 0x385E29DF (dec: 945695199)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x503F012D (dec: 1346306349), parent name: 'INSTNCG2_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x265589A9 (dec: 643140009), parent name: 'INSTNCG2_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xD79B75F8 (dec: -677677576), parent name: 'INSTNCG2_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x61939952 (dec: 1637062994), parent name: 'INSTNCG2_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x2053215C (dec: 542318940), parent name: 'INSTNCG2_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_108fake // hashcode: 0x67863AA8 (dec: 1736850088)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xED487270 (dec: -314019216), parent name: 'INSTNCG2_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0xCD8D2FF8 (dec: -846385160), parent name: 'INSTNCG2_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x51E881F0 (dec: 1374192112), parent name: 'INSTNCG2_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xDF016B3A (dec: -553555142), parent name: 'INSTNCG2_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x7B9C767A (dec: 2073851514), parent name: 'INSTNCG2_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTNCG2_109fake // hashcode: 0x507B5C94 (dec: 1350261908)
{
	struct INSTNCG2_105fake Cinematic; // size=28, offset=0 //  hashcode: 0x99F632E7 (dec: -1711918361), parent name: 'INSTNCG2_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct INSTNCG2_106fake Idle;	  // size=20, offset=28 //  hashcode: 0x636CEA66 (dec: 1668082278), parent name: 'INSTNCG2_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct INSTNCG2_107fake Behind;	// size=28, offset=48 //  hashcode: 0x585F2FBF (dec: 1482633151), parent name: 'INSTNCG2_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct INSTNCG2_108fake Follow;	// size=20, offset=76 //  hashcode: 0x39FC9CB6 (dec: 972856502), parent name: 'INSTNCG2_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

extern void G2Instance_BuildTransformsForList(struct _Instance *listHead); // 0x80094D90

extern void G2Instance_BuildTransforms(struct _Instance *instance); // 0x80094F0C

extern void G2Instance_RebuildTransforms(struct _Instance *instance); // 0x80094F68

extern struct _G2AnimKeylist_Type *G2Instance_GetKeylist(struct _Instance *instance, int id); // 0x80094FC4

extern void _G2Instance_RebuildAnimatedTransforms(struct _Instance *instance); // 0x80094FE4

extern void G2Instance_ClearMatrices(struct _Instance *instance); // 0x80095418

extern void _G2Instance_BuildAnimatedTransforms(struct _Instance *instance); // 0x8009546C

extern void _G2Instance_RebuildNonAnimatedTransforms(struct _Instance *instance); // 0x80095528

extern void _G2Instance_BuildDeactivatedTransforms(struct _Instance *instance); // 0x800957B4

extern void _G2Instance_BuildNonAnimatedTransforms(struct _Instance *instance); // 0x80095934

extern void _G2Instance_BuildFacadeTransforms(struct _Instance *instance, struct _Segment *segment, struct MATRIX *segMatrix, struct MATRIX *matrixPool, long scale_flag); // 0x800959F0

#endif
