#ifndef HUMAN_H
#define HUMAN_H

extern struct _MonsterFunctionTable HUMAN_FunctionTable; // offset 0x800CF5E0

extern struct _MonsterStateChoice HUMAN_StateChoiceTable[6]; // offset 0x800CA978

struct HUMAN_73fake // hashcode: 0xE99DF5CD (dec: -375523891)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x10595343 (dec: 274289475), parent name: 'HUMAN_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0xCF25482F (dec: -819640273), parent name: 'HUMAN_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_74fake // hashcode: 0xDFBD7EE6 (dec: -541229338)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xC45ED0A8 (dec: -1000419160), parent name: 'HUMAN_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xF61F6DD0 (dec: -165712432), parent name: 'HUMAN_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_75fake // hashcode: 0x753EBF4C (dec: 1967046476)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x48E8D3DC (dec: 1223218140), parent name: 'HUMAN_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x3480F356 (dec: 880866134), parent name: 'HUMAN_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union HUMAN_76fake // Hashcode: 0xF9B1F2DA (dec: -105778470)
{
	struct HUMAN_73fake callback; // size=8, offset=0
	struct HUMAN_74fake vector;   // size=12, offset=0
	struct HUMAN_75fake quat;	 // size=16, offset=0
};

union HUMAN_77fake // Hashcode: 0x55AD237E (dec: 1437410174)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union HUMAN_78fake // Hashcode: 0x81C323AA (dec: -2117917782)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct HUMAN_79fake // hashcode: 0xD3E6C5CB (dec: -739850805)
{
	union HUMAN_78fake size; // size=4, offset=0 //  hashcode: 0x28C378D5 (dec: 683899093), parent name: 'HUMAN_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_80fake // hashcode: 0x3899B8A6 (dec: 949598374)
{
	short x;				// size=0, offset=0 //  hashcode: 0x0196B50F (dec: 26653967), parent name: 'HUMAN_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x1827AD1A (dec: 405253402), parent name: 'HUMAN_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x0D764037 (dec: 225853495), parent name: 'HUMAN_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xF6D81DF4 (dec: -153608716), parent name: 'HUMAN_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x82D6F27A (dec: -2099842438), parent name: 'HUMAN_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_81fake // hashcode: 0xDD848597 (dec: -578517609)
{
	long index; // size=0, offset=0 //  hashcode: 0x477AFFB4 (dec: 1199243188), parent name: 'HUMAN_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x81E63C05 (dec: -2115617787), parent name: 'HUMAN_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_82fake // hashcode: 0xB69DB6F6 (dec: -1231177994)
{
	long index; // size=0, offset=0 //  hashcode: 0x97232B0E (dec: -1759302898), parent name: 'HUMAN_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x47BE8871 (dec: 1203669105), parent name: 'HUMAN_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_83fake // hashcode: 0x54B0F1C0 (dec: 1420882368)
{
	long index; // size=0, offset=0 //  hashcode: 0x9FD86233 (dec: -1613209037), parent name: 'HUMAN_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x3F324804 (dec: 1060259844), parent name: 'HUMAN_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_84fake // hashcode: 0x37F102DA (dec: 938541786)
{
	long time;  // size=0, offset=0 //  hashcode: 0x0074B54F (dec: 7648591), parent name: 'HUMAN_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x6F949E9D (dec: 1872010909), parent name: 'HUMAN_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_85fake // hashcode: 0x4BCE1E51 (dec: 1271799377)
{
	long action;   // size=0, offset=0 //  hashcode: 0x66D3B793 (dec: 1725151123), parent name: 'HUMAN_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xD48A7109 (dec: -729124599), parent name: 'HUMAN_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_86fake // hashcode: 0xC0641A27 (dec: -1067181529)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xABA0E7BC (dec: -1415518276), parent name: 'HUMAN_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xB079A4E2 (dec: -1334205214), parent name: 'HUMAN_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_87fake // hashcode: 0x4D6E6B5F (dec: 1299082079)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xD4B35DD6 (dec: -726442538), parent name: 'HUMAN_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0xC3FEE86B (dec: -1006704533), parent name: 'HUMAN_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_88fake // hashcode: 0x4546CE18 (dec: 1162268184)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x03125504 (dec: 51533060), parent name: 'HUMAN_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x41E420D6 (dec: 1105469654), parent name: 'HUMAN_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_89fake // hashcode: 0x560E4065 (dec: 1443774565)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xD7E0A3F0 (dec: -673143824), parent name: 'HUMAN_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xAF872CE2 (dec: -1350095646), parent name: 'HUMAN_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xE4D9D719 (dec: -455485671), parent name: 'HUMAN_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x90D82967 (dec: -1864881817), parent name: 'HUMAN_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x89ADFD5E (dec: -1985086114), parent name: 'HUMAN_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_90fake // hashcode: 0xDF05DD83 (dec: -553263741)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x869EA928 (dec: -2036422360), parent name: 'HUMAN_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xC3B0955C (dec: -1011837604), parent name: 'HUMAN_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_91fake // hashcode: 0xEC033D5B (dec: -335332005)
{
	short index;					// size=0, offset=0 //  hashcode: 0x24E54AAA (dec: 619006634), parent name: 'HUMAN_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x0BB48C97 (dec: 196381847), parent name: 'HUMAN_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x7A1CD550 (dec: 2048709968), parent name: 'HUMAN_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x70F306FC (dec: 1894975228), parent name: 'HUMAN_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_92fake // hashcode: 0x57FC085B (dec: 1476135003)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x69365A72 (dec: 1765169778), parent name: 'HUMAN_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x447EBE30 (dec: 1149156912), parent name: 'HUMAN_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x9BE4548D (dec: -1679534963), parent name: 'HUMAN_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_93fake // hashcode: 0x2D838841 (dec: 763594817)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xED6B2335 (dec: -311745739), parent name: 'HUMAN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xDB60DD24 (dec: -614408924), parent name: 'HUMAN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x2CC533F9 (dec: 751121401), parent name: 'HUMAN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x4C8AD75F (dec: 1284167519), parent name: 'HUMAN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xE08C4087 (dec: -527679353), parent name: 'HUMAN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x3C4CD174 (dec: 1011667316), parent name: 'HUMAN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x9733B085 (dec: -1758220155), parent name: 'HUMAN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_94fake // hashcode: 0xC6471123 (dec: -968421085)
{
	long index;  // size=0, offset=0 //  hashcode: 0xBA16D5D2 (dec: -1172908590), parent name: 'HUMAN_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x9F654B06 (dec: -1620751610), parent name: 'HUMAN_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_95fake // hashcode: 0x250748DE (dec: 621234398)
{
	short type; // size=0, offset=0 //  hashcode: 0x1CF633CA (dec: 485897162), parent name: 'HUMAN_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xDB33D050 (dec: -617361328), parent name: 'HUMAN_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_96fake // hashcode: 0xF294D4D3 (dec: -225127213)
{
	long time;   // size=0, offset=0 //  hashcode: 0x2AB795FB (dec: 716674555), parent name: 'HUMAN_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xD193201E (dec: -778887138), parent name: 'HUMAN_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_97fake // hashcode: 0x68BC73D2 (dec: 1757180882)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x804F8C98 (dec: -2142270312), parent name: 'HUMAN_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xA624842C (dec: -1507556308), parent name: 'HUMAN_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_98fake // hashcode: 0xFC809C5E (dec: -58680226)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x961D335A (dec: -1776471206), parent name: 'HUMAN_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x61C90229 (dec: 1640563241), parent name: 'HUMAN_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_99fake // hashcode: 0x227EF8FA (dec: 578746618)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xCAD7E84A (dec: -891819958), parent name: 'HUMAN_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x098F2166 (dec: 160375142), parent name: 'HUMAN_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_100fake // hashcode: 0x097A0B52 (dec: 158993234)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x17ED0F71 (dec: 401411953), parent name: 'HUMAN_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x43443CB8 (dec: 1128545464), parent name: 'HUMAN_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xC125103E (dec: -1054535618), parent name: 'HUMAN_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x6203C7BA (dec: 1644414906), parent name: 'HUMAN_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_101fake // hashcode: 0x96B8743B (dec: -1766296517)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x1E79BBD3 (dec: 511294419), parent name: 'HUMAN_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x1414BF8B (dec: 336904075), parent name: 'HUMAN_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x57274170 (dec: 1462190448), parent name: 'HUMAN_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x25530456 (dec: 626197590), parent name: 'HUMAN_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xC3E0303D (dec: -1008717763), parent name: 'HUMAN_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union HUMAN_102fake // Hashcode: 0xC5EE66CE (dec: -974231858)
{
	struct HUMAN_79fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	 // size=24, offset=0
	struct HUMAN_80fake teleport;	 // size=16, offset=0
	struct HUMAN_81fake cameraValue;  // size=8, offset=0
	struct HUMAN_82fake miscValue;	// size=8, offset=0
	struct HUMAN_83fake logicValue;   // size=8, offset=0
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
	struct HUMAN_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				  // size=0, offset=0
	long cameraRestore;				  // size=0, offset=0
	struct _BGObject *bgObject;		  // size=24, offset=0
	long value[2];					  // size=8, offset=0
	struct HUMAN_85fake sound;		  // size=12, offset=0
	void *intro;					  // size=0, offset=0
	long deathZ;					  // size=0, offset=0
	struct HUMAN_86fake dsignal;	  // size=8, offset=0
	void *mirror;					  // size=0, offset=0
	long fogNear;					  // size=0, offset=0
	long fogFar;					  // size=0, offset=0
	struct HUMAN_87fake gotoFrame;	// size=8, offset=0
	struct HUMAN_88fake changeModel;  // size=8, offset=0
	void *vmObject;					  // size=0, offset=0
	struct HUMAN_89fake logic;		  // size=8, offset=0
	void *callSignal;				  // size=0, offset=0
	struct _SVector offset;			  // size=8, offset=0
	struct Signal *gotoLabel;		  // size=0, offset=0
	struct Signal *gosubLabel;		  // size=0, offset=0
	struct HUMAN_90fake control;	  // size=8, offset=0
	struct HUMAN_91fake zSignal;	  // size=12, offset=0
	struct HUMAN_92fake StreamLevel;  // size=24, offset=0
	struct HUMAN_93fake shards;		  // size=12, offset=0
	struct HUMAN_94fake cameraSpline; // size=8, offset=0
	struct HUMAN_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				  // size=0, offset=0
	struct HUMAN_96fake introFX;	  // size=8, offset=0
	struct HUMAN_97fake introActive;  // size=8, offset=0
	struct HUMAN_98fake levelChange;  // size=18, offset=0
	long blendStart;				  // size=0, offset=0
	struct HUMAN_99fake setTimes;	 // size=8, offset=0
	struct HUMAN_100fake color;		  // size=4, offset=0
	struct HUMAN_101fake print;		  // size=12, offset=0
	long slideAngle;				  // size=0, offset=0
};

union HUMAN_103fake // Hashcode: 0x9B84566A (dec: -1685825942)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union HUMAN_108fake // Hashcode: 0x8C0F4C13 (dec: -1945154541)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct HUMAN_110fake // hashcode: 0x9D8B6701 (dec: -1651808511)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xF6882832 (dec: -158848974), parent name: 'HUMAN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xF4FD767E (dec: -184715650), parent name: 'HUMAN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0xB7F90E12 (dec: -1208414702), parent name: 'HUMAN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xB81DD0D0 (dec: -1206005552), parent name: 'HUMAN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x9A71E60E (dec: -1703811570), parent name: 'HUMAN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xE7BB0BBC (dec: -407172164), parent name: 'HUMAN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x9265FBF2 (dec: -1838810126), parent name: 'HUMAN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_111fake // hashcode: 0x79BADD57 (dec: 2042289495)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x46F5CE2B (dec: 1190514219), parent name: 'HUMAN_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x25A84E17 (dec: 631787031), parent name: 'HUMAN_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xB148E75F (dec: -1320622241), parent name: 'HUMAN_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_112fake // hashcode: 0x23790D5B (dec: 595135835)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x9941AED7 (dec: -1723748649), parent name: 'HUMAN_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xC2718BFE (dec: -1032745986), parent name: 'HUMAN_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x536D776B (dec: 1399682923), parent name: 'HUMAN_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xB678FB29 (dec: -1233585367), parent name: 'HUMAN_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xA68E5493 (dec: -1500621677), parent name: 'HUMAN_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_113fake // hashcode: 0xFB1B2A41 (dec: -82105791)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x883862AD (dec: -2009570643), parent name: 'HUMAN_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x46FD3E46 (dec: 1191001670), parent name: 'HUMAN_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x44FFC38F (dec: 1157612431), parent name: 'HUMAN_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x34ED656B (dec: 887973227), parent name: 'HUMAN_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x0F504375 (dec: 256918389), parent name: 'HUMAN_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_114fake // hashcode: 0xC7C43F22 (dec: -943440094)
{
	struct HUMAN_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x4EE62447 (dec: 1323705415), parent name: 'HUMAN_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct HUMAN_111fake Idle;		// size=20, offset=28 //  hashcode: 0x950F3D66 (dec: -1794163354), parent name: 'HUMAN_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct HUMAN_112fake Behind;	// size=28, offset=48 //  hashcode: 0x9DF218F1 (dec: -1645078287), parent name: 'HUMAN_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct HUMAN_113fake Follow;	// size=20, offset=76 //  hashcode: 0x2C1FB9BF (dec: 740276671), parent name: 'HUMAN_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union HUMAN_193fake // Hashcode: 0x24019F16 (dec: 604086038)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct HUMAN_222fake // hashcode: 0x6266D043 (dec: 1650905155)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x687F5130 (dec: 1753174320), parent name: 'HUMAN_222fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x41DAA5FA (dec: 1104848378), parent name: 'HUMAN_222fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HUMAN_223fake // hashcode: 0x7E24C850 (dec: 2116339792)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0xB76448DB (dec: -1218164517), parent name: 'HUMAN_223fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x4073B739 (dec: 1081325369), parent name: 'HUMAN_223fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0xDD21EECB (dec: -584978741), parent name: 'HUMAN_223fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0xD89730FE (dec: -661180162), parent name: 'HUMAN_223fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x97FCF97F (dec: -1745028737), parent name: 'HUMAN_223fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0xC0FD229D (dec: -1057152355), parent name: 'HUMAN_223fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union HUMAN_224fake // Hashcode: 0x3015A3DF (dec: 806724575)
{
	struct HUMAN_222fake flame; // size=8, offset=0
	struct HUMAN_223fake phys;  // size=12, offset=0
};

struct _MonsterFunctionTable // hashcode: 0x82983F8D (dec: -2103951475)
{
	void (*initFunc)();						// size=0, offset=0 //  hashcode: 0xCBBC575B (dec: -876849317), parent name: '_MonsterFunctionTable', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*cleanUpFunc)();					// size=0, offset=4 //  hashcode: 0xD6170F83 (dec: -703131773), parent name: '_MonsterFunctionTable', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*damageEffectFunc)();				// size=0, offset=8 //  hashcode: 0x2E1BD309 (dec: 773575433), parent name: '_MonsterFunctionTable', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long (*queryFunc)();			// size=0, offset=12 //  hashcode: 0x782B0EDC (dec: 2016087772), parent name: '_MonsterFunctionTable', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*messageFunc)();					// size=0, offset=16 //  hashcode: 0xFF570DEC (dec: -11072020), parent name: '_MonsterFunctionTable', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterStateChoice *stateFuncs; // size=12, offset=20 //  hashcode: 0x24D95F5F (dec: 618225503), parent name: '_MonsterFunctionTable', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *versionID;						// size=0, offset=24 //  hashcode: 0x2D456AF8 (dec: 759524088), parent name: '_MonsterFunctionTable', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *localVersionID;					// size=0, offset=28 //  hashcode: 0x5E7F8D29 (dec: 1585417513), parent name: '_MonsterFunctionTable', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct _MonsterFunctionTable MonsterFunctionTable;

extern void HUMAN_WaitForWeapon(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007CB40

extern struct _Instance *HUMAN_CreateWeapon(struct _Instance *instance, int weaponid, int segment); // 0x8007CBB0

extern void HUMAN_Init(struct _Instance *instance); // 0x8007CC84

extern void HUMAN_CleanUp(struct _Instance *instance); // 0x8007CD7C

extern unsigned long HUMAN_Query(struct _Instance *instance, unsigned long query); // 0x8007CD9C

extern void HUMAN_DeadEntry(struct _Instance *instance); // 0x8007CE8C

extern void HUMAN_Dead(struct _Instance *instance); // 0x8007CF04

extern void HUMAN_StunnedEntry(struct _Instance *instance); // 0x8007CFEC

extern void HUMAN_Stunned(struct _Instance *instance); // 0x8007D064

extern void HUMAN_EmbraceEntry(struct _Instance *instance); // 0x8007D10C

extern void HUMAN_Embrace(struct _Instance *instance); // 0x8007D168

extern void HUMAN_IdleEntry(struct _Instance *instance); // 0x8007D330

extern void HUMAN_Idle(struct _Instance *instance); // 0x8007D378

extern void HUMAN_Flee(struct _Instance *instance); // 0x8007D530

extern void HUMAN_GetAngry(); // 0x8007D688

extern int HUMAN_TypeOfHuman(struct _Instance *instance); // 0x8007D750

#endif
