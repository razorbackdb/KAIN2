#ifndef QUATVM_H
#define QUATVM_H

struct QUATVM_68fake // hashcode: 0x07D34F35 (dec: 131288885)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xDA598B10 (dec: -631665904), parent name: 'QUATVM_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0xEF6DF118 (dec: -278007528), parent name: 'QUATVM_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_69fake // hashcode: 0x62C30142 (dec: 1656947010)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x6A3497DC (dec: 1781831644), parent name: 'QUATVM_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xADB81A92 (dec: -1380443502), parent name: 'QUATVM_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_70fake // hashcode: 0x37A8D98F (dec: 933812623)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x5AF117ED (dec: 1525749741), parent name: 'QUATVM_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x6FF38C00 (dec: 1878232064), parent name: 'QUATVM_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union QUATVM_71fake // Hashcode: 0x3F855776 (dec: 1065703286)
{
	struct QUATVM_68fake callback; // size=8, offset=0
	struct QUATVM_69fake vector;   // size=12, offset=0
	struct QUATVM_70fake quat;	 // size=16, offset=0
};

union QUATVM_72fake // Hashcode: 0x0E200AE9 (dec: 236980969)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union QUATVM_73fake // Hashcode: 0x199B77BE (dec: 429619134)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct QUATVM_74fake // hashcode: 0xFC5D7AB3 (dec: -60982605)
{
	union QUATVM_73fake size; // size=4, offset=0 //  hashcode: 0x87108EDB (dec: -2028957989), parent name: 'QUATVM_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_75fake // hashcode: 0x0CD68AEA (dec: 215386858)
{
	short x;				// size=0, offset=0 //  hashcode: 0x8E939ACE (dec: -1902929202), parent name: 'QUATVM_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x24B6C17C (dec: 615956860), parent name: 'QUATVM_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x17D90FB6 (dec: 400101302), parent name: 'QUATVM_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x733D184C (dec: 1933383756), parent name: 'QUATVM_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x7BBB27D6 (dec: 2075862998), parent name: 'QUATVM_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_76fake // hashcode: 0xC8FC90BB (dec: -922971973)
{
	long index; // size=0, offset=0 //  hashcode: 0xE6E9964F (dec: -420899249), parent name: 'QUATVM_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xD6F5F2B4 (dec: -688524620), parent name: 'QUATVM_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_77fake // hashcode: 0x1E7BFE6B (dec: 511442539)
{
	long index; // size=0, offset=0 //  hashcode: 0xB4EFEB00 (dec: -1259345152), parent name: 'QUATVM_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x1373F199 (dec: 326365593), parent name: 'QUATVM_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_78fake // hashcode: 0xD33929E7 (dec: -751228441)
{
	long index; // size=0, offset=0 //  hashcode: 0xCA7E3C8E (dec: -897696626), parent name: 'QUATVM_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x3645013F (dec: 910491967), parent name: 'QUATVM_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_79fake // hashcode: 0x66EC314D (dec: 1726755149)
{
	long time;  // size=0, offset=0 //  hashcode: 0xB635701A (dec: -1238011878), parent name: 'QUATVM_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x6A83CF4C (dec: 1787023180), parent name: 'QUATVM_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_80fake // hashcode: 0xA7A7704C (dec: -1482198964)
{
	long action;   // size=0, offset=0 //  hashcode: 0x5BA1662C (dec: 1537304108), parent name: 'QUATVM_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xD88777A2 (dec: -662210654), parent name: 'QUATVM_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_81fake // hashcode: 0xB985448C (dec: -1182448500)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x3B8D07CF (dec: 999098319), parent name: 'QUATVM_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x64CE91FB (dec: 1691259387), parent name: 'QUATVM_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_82fake // hashcode: 0xB875C08B (dec: -1200242549)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x06D89889 (dec: 114858121), parent name: 'QUATVM_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x5EC2FC15 (dec: 1589836821), parent name: 'QUATVM_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_83fake // hashcode: 0xBDA9A39B (dec: -1112956005)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x8F5423BC (dec: -1890311236), parent name: 'QUATVM_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x1EC6A8B4 (dec: 516335796), parent name: 'QUATVM_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_84fake // hashcode: 0x07417719 (dec: 121730841)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xF855BC0A (dec: -128599030), parent name: 'QUATVM_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x1C755A6B (dec: 477452907), parent name: 'QUATVM_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x87507DFE (dec: -2024768002), parent name: 'QUATVM_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xA29AC5C2 (dec: -1566915134), parent name: 'QUATVM_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x613ADE47 (dec: 1631247943), parent name: 'QUATVM_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_85fake // hashcode: 0xC6B63614 (dec: -961137132)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xD36B6C81 (dec: -747934591), parent name: 'QUATVM_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x50E49B0C (dec: 1357159180), parent name: 'QUATVM_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_86fake // hashcode: 0xDDE22078 (dec: -572383112)
{
	short index;					// size=0, offset=0 //  hashcode: 0x7A4F2C04 (dec: 2052008964), parent name: 'QUATVM_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x3C7CC9EC (dec: 1014811116), parent name: 'QUATVM_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xF5D8574A (dec: -170371254), parent name: 'QUATVM_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x9A927991 (dec: -1701676655), parent name: 'QUATVM_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_87fake // hashcode: 0x55EF82AF (dec: 1441759919)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x643480CD (dec: 1681162445), parent name: 'QUATVM_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xBBDF0A7E (dec: -1143010690), parent name: 'QUATVM_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x5F01BCD6 (dec: 1593949398), parent name: 'QUATVM_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_88fake // hashcode: 0xFD904304 (dec: -40877308)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xFB1CC01D (dec: -82001891), parent name: 'QUATVM_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xABCB1D50 (dec: -1412752048), parent name: 'QUATVM_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x563F5EB4 (dec: 1446993588), parent name: 'QUATVM_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xF3A4AC78 (dec: -207311752), parent name: 'QUATVM_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x0E3DE681 (dec: 238937729), parent name: 'QUATVM_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x3089318C (dec: 814297484), parent name: 'QUATVM_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xF5241BCA (dec: -182182966), parent name: 'QUATVM_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_89fake // hashcode: 0x71E83922 (dec: 1911044386)
{
	long index;  // size=0, offset=0 //  hashcode: 0x1F4172AB (dec: 524382891), parent name: 'QUATVM_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xD0A8C69D (dec: -794245475), parent name: 'QUATVM_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_90fake // hashcode: 0x09B8BD06 (dec: 163101958)
{
	short type; // size=0, offset=0 //  hashcode: 0xB64D22FD (dec: -1236458755), parent name: 'QUATVM_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x2BC5A54D (dec: 734373197), parent name: 'QUATVM_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_91fake // hashcode: 0x7C40ECB7 (dec: 2084629687)
{
	long time;   // size=0, offset=0 //  hashcode: 0xBD2EFFDE (dec: -1120993314), parent name: 'QUATVM_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x798BCE5B (dec: 2039205467), parent name: 'QUATVM_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_92fake // hashcode: 0xE14DA8D5 (dec: -515004203)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x64C8DCB7 (dec: 1690885303), parent name: 'QUATVM_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xDC2DD6A9 (dec: -600975703), parent name: 'QUATVM_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_93fake // hashcode: 0xC6ED4EAC (dec: -957526356)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xFA1AD414 (dec: -98905068), parent name: 'QUATVM_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x2C814B41 (dec: 746670913), parent name: 'QUATVM_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_94fake // hashcode: 0x631561CF (dec: 1662345679)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x938BA720 (dec: -1819564256), parent name: 'QUATVM_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x60B6F0A0 (dec: 1622601888), parent name: 'QUATVM_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_95fake // hashcode: 0x82FAC6F4 (dec: -2097494284)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x3B79070A (dec: 997787402), parent name: 'QUATVM_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x2E53B955 (dec: 777238869), parent name: 'QUATVM_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x4711B445 (dec: 1192342597), parent name: 'QUATVM_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x5F8490F5 (dec: 1602523381), parent name: 'QUATVM_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct QUATVM_96fake // hashcode: 0xE3974DF1 (dec: -476623375)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xDC34E718 (dec: -600512744), parent name: 'QUATVM_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x6F1FA087 (dec: 1864343687), parent name: 'QUATVM_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xA0010716 (dec: -1610545386), parent name: 'QUATVM_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x89CF84E3 (dec: -1982888733), parent name: 'QUATVM_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x55148D6F (dec: 1427410287), parent name: 'QUATVM_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union QUATVM_97fake // Hashcode: 0x9D4F0BAD (dec: -1655764051)
{
	struct QUATVM_74fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	  // size=24, offset=0
	struct QUATVM_75fake teleport;	 // size=16, offset=0
	struct QUATVM_76fake cameraValue;  // size=8, offset=0
	struct QUATVM_77fake miscValue;	// size=8, offset=0
	struct QUATVM_78fake logicValue;   // size=8, offset=0
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
	struct QUATVM_79fake cameraShake;  // size=8, offset=0
	long cameraSave;				   // size=0, offset=0
	long cameraRestore;				   // size=0, offset=0
	struct _BGObject *bgObject;		   // size=24, offset=0
	long value[2];					   // size=8, offset=0
	struct QUATVM_80fake sound;		   // size=12, offset=0
	void *intro;					   // size=0, offset=0
	long deathZ;					   // size=0, offset=0
	struct QUATVM_81fake dsignal;	  // size=8, offset=0
	void *mirror;					   // size=0, offset=0
	long fogNear;					   // size=0, offset=0
	long fogFar;					   // size=0, offset=0
	struct QUATVM_82fake gotoFrame;	// size=8, offset=0
	struct QUATVM_83fake changeModel;  // size=8, offset=0
	void *vmObject;					   // size=0, offset=0
	struct QUATVM_84fake logic;		   // size=8, offset=0
	void *callSignal;				   // size=0, offset=0
	struct _SVector offset;			   // size=8, offset=0
	struct Signal *gotoLabel;		   // size=0, offset=0
	struct Signal *gosubLabel;		   // size=0, offset=0
	struct QUATVM_85fake control;	  // size=8, offset=0
	struct QUATVM_86fake zSignal;	  // size=12, offset=0
	struct QUATVM_87fake StreamLevel;  // size=24, offset=0
	struct QUATVM_88fake shards;	   // size=12, offset=0
	struct QUATVM_89fake cameraSpline; // size=8, offset=0
	struct QUATVM_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;				   // size=0, offset=0
	struct QUATVM_91fake introFX;	  // size=8, offset=0
	struct QUATVM_92fake introActive;  // size=8, offset=0
	struct QUATVM_93fake levelChange;  // size=18, offset=0
	long blendStart;				   // size=0, offset=0
	struct QUATVM_94fake setTimes;	 // size=8, offset=0
	struct QUATVM_95fake color;		   // size=4, offset=0
	struct QUATVM_96fake print;		   // size=12, offset=0
	long slideAngle;				   // size=0, offset=0
};

union QUATVM_98fake // Hashcode: 0x19B08759 (dec: 430999385)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union QUATVM_103fake // Hashcode: 0x0D13BFD5 (dec: 219398101)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

extern void G2Quat_Slerp_VM(long ratio, struct _G2Quat_Type *quatA, struct _G2Quat_Type *quatB, struct _G2Quat_Type *quatOut, int spin); // 0x800962F4

#endif
