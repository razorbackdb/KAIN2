#ifndef GAMEPAD_H
#define GAMEPAD_H

static short align_flag; // offset 0x800CE358

extern unsigned char controllerType[2]; // offset 0x800D0CC8

static int dualShock; // offset 0x800CE35C

extern unsigned char dualshock_align[6]; // offset 0x800C8760

extern unsigned char dualshock_motors[2]; // offset 0x800C875C

static short dualshock_onflag; // offset 0x800CE35A

static long dualshock0_time; // offset 0x800D0C68

static long dualshock1_time; // offset 0x800D0C6C

extern long gDummyCommand[2][2]; // offset 0x800D0D60

extern struct ControllerPacket gpbuffer1; // offset 0x800D0CD0

extern struct ControllerPacket gpbuffer2; // offset 0x800D0D18

static int gpSaved; // offset 0x800CE3A4

static int ignoreFind; // offset 0x800D0C64

extern unsigned short lastData[2]; // offset 0x800CE3A0

static long overrideCommand[2][5]; // offset 0x800D0CA0

static long overrideData[2][5]; // offset 0x800D0C70

extern unsigned short psxData[2]; // offset 0x800D0CCC

extern struct ControllerPacket readGPBuffer1; // offset 0x800D0CF4

extern struct ControllerPacket readGPBuffer2; // offset 0x800D0D3C

struct GAMEPAD_73fake // hashcode: 0x24E08705 (dec: 618694405)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x6DEAFA77 (dec: 1844116087), parent name: 'GAMEPAD_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0xD56297AD (dec: -714958931), parent name: 'GAMEPAD_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_74fake // hashcode: 0xCCD9CC28 (dec: -858141656)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xA7775232 (dec: -1485352398), parent name: 'GAMEPAD_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x5FAAF46E (dec: 1605039214), parent name: 'GAMEPAD_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_75fake // hashcode: 0x08FC32EC (dec: 150745836)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xD45363AF (dec: -732732497), parent name: 'GAMEPAD_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x305249D8 (dec: 810699224), parent name: 'GAMEPAD_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union GAMEPAD_76fake // Hashcode: 0xCC53CC9A (dec: -866923366)
{
	struct GAMEPAD_73fake callback; // size=8, offset=0
	struct GAMEPAD_74fake vector;   // size=12, offset=0
	struct GAMEPAD_75fake quat;		// size=16, offset=0
};

union GAMEPAD_77fake // Hashcode: 0xD392046D (dec: -745405331)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union GAMEPAD_78fake // Hashcode: 0xD502333D (dec: -721276099)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct GAMEPAD_79fake // hashcode: 0x65A7CCF6 (dec: 1705495798)
{
	union GAMEPAD_78fake size; // size=4, offset=0 //  hashcode: 0x72ED2CC8 (dec: 1928146120), parent name: 'GAMEPAD_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_80fake // hashcode: 0xA9D23722 (dec: -1445841118)
{
	short x;				// size=0, offset=0 //  hashcode: 0x5A4C6192 (dec: 1514955154), parent name: 'GAMEPAD_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x043B019D (dec: 70975901), parent name: 'GAMEPAD_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x68CCE81D (dec: 1758259229), parent name: 'GAMEPAD_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x464BC1AF (dec: 1179369903), parent name: 'GAMEPAD_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xC1C3103E (dec: -1044180930), parent name: 'GAMEPAD_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_81fake // hashcode: 0x1F3701B7 (dec: 523698615)
{
	long index; // size=0, offset=0 //  hashcode: 0xAF808D11 (dec: -1350529775), parent name: 'GAMEPAD_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x021BC33F (dec: 35373887), parent name: 'GAMEPAD_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_82fake // hashcode: 0xB2AA0E61 (dec: -1297478047)
{
	long index; // size=0, offset=0 //  hashcode: 0x9027BF28 (dec: -1876443352), parent name: 'GAMEPAD_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xD9081BAD (dec: -653780051), parent name: 'GAMEPAD_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_83fake // hashcode: 0x3AE08F89 (dec: 987795337)
{
	long index; // size=0, offset=0 //  hashcode: 0x424A4C02 (dec: 1112165378), parent name: 'GAMEPAD_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x6481B91F (dec: 1686223135), parent name: 'GAMEPAD_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_84fake // hashcode: 0xDED91477 (dec: -556198793)
{
	long time;  // size=0, offset=0 //  hashcode: 0x3065BF9F (dec: 811974559), parent name: 'GAMEPAD_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x9917BD98 (dec: -1726497384), parent name: 'GAMEPAD_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_85fake // hashcode: 0xDEF9C086 (dec: -554057594)
{
	long action;   // size=0, offset=0 //  hashcode: 0x7B32B7ED (dec: 2066921453), parent name: 'GAMEPAD_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xC8C19093 (dec: -926838637), parent name: 'GAMEPAD_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_86fake // hashcode: 0x267ACB01 (dec: 645581569)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x9C8B33A3 (dec: -1668598877), parent name: 'GAMEPAD_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xB4E3B8F2 (dec: -1260144398), parent name: 'GAMEPAD_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_87fake // hashcode: 0x6B6336BA (dec: 1801664186)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xEF6481DD (dec: -278625827), parent name: 'GAMEPAD_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x6E282101 (dec: 1848123649), parent name: 'GAMEPAD_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_88fake // hashcode: 0x1D94E852 (dec: 496298066)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x7876BB62 (dec: 2021047138), parent name: 'GAMEPAD_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xEF61C948 (dec: -278804152), parent name: 'GAMEPAD_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_89fake // hashcode: 0xA8783293 (dec: -1468517741)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xCD67495D (dec: -848869027), parent name: 'GAMEPAD_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x93BCB4B7 (dec: -1816349513), parent name: 'GAMEPAD_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xFA54247B (dec: -95148933), parent name: 'GAMEPAD_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x0BFFD79D (dec: 201316253), parent name: 'GAMEPAD_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x0639B00A (dec: 104443914), parent name: 'GAMEPAD_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_90fake // hashcode: 0xC40B69BB (dec: -1005884997)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xFC32F6BA (dec: -63768902), parent name: 'GAMEPAD_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x9C179ABE (dec: -1676174658), parent name: 'GAMEPAD_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_91fake // hashcode: 0x7118B1BA (dec: 1897443770)
{
	short index;					// size=0, offset=0 //  hashcode: 0xCF9E9470 (dec: -811690896), parent name: 'GAMEPAD_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x2FF5E99E (dec: 804645278), parent name: 'GAMEPAD_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xF6AEDF56 (dec: -156311722), parent name: 'GAMEPAD_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x656ED5C2 (dec: 1701762498), parent name: 'GAMEPAD_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_92fake // hashcode: 0x57623704 (dec: 1466054404)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xDB06FE29 (dec: -620298711), parent name: 'GAMEPAD_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x9E043695 (dec: -1643891051), parent name: 'GAMEPAD_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x7938F4DB (dec: 2033775835), parent name: 'GAMEPAD_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_93fake // hashcode: 0xF1E7F15E (dec: -236457634)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x814BC134 (dec: -2125741772), parent name: 'GAMEPAD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x454CED6C (dec: 1162669420), parent name: 'GAMEPAD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x41E6AAAA (dec: 1105636010), parent name: 'GAMEPAD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xB44AFFB9 (dec: -1270153287), parent name: 'GAMEPAD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xD9A1F3ED (dec: -643697683), parent name: 'GAMEPAD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x8D1E5C58 (dec: -1927390120), parent name: 'GAMEPAD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x9C79E7AE (dec: -1669732434), parent name: 'GAMEPAD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_94fake // hashcode: 0x51957875 (dec: 1368750197)
{
	long index;  // size=0, offset=0 //  hashcode: 0x43966E17 (dec: 1133932055), parent name: 'GAMEPAD_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xF7C418FE (dec: -138143490), parent name: 'GAMEPAD_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_95fake // hashcode: 0xD01651CB (dec: -803843637)
{
	short type; // size=0, offset=0 //  hashcode: 0x0E093001 (dec: 235483137), parent name: 'GAMEPAD_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xAC443A3A (dec: -1404814790), parent name: 'GAMEPAD_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_96fake // hashcode: 0x0816D123 (dec: 135713059)
{
	long time;   // size=0, offset=0 //  hashcode: 0xC83FB781 (dec: -935348351), parent name: 'GAMEPAD_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x5B1C78FF (dec: 1528592639), parent name: 'GAMEPAD_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_97fake // hashcode: 0x1EA7619C (dec: 514285980)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xC4314E8C (dec: -1003401588), parent name: 'GAMEPAD_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xA92EDFA1 (dec: -1456545887), parent name: 'GAMEPAD_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_98fake // hashcode: 0xB40965E9 (dec: -1274452503)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x10456268 (dec: 272982632), parent name: 'GAMEPAD_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xDB3E9D97 (dec: -616653417), parent name: 'GAMEPAD_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_99fake // hashcode: 0x4CCA93B9 (dec: 1288344505)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xAE374A54 (dec: -1372108204), parent name: 'GAMEPAD_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x39D649C1 (dec: 970344897), parent name: 'GAMEPAD_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_100fake // hashcode: 0x83A903A6 (dec: -2086075482)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x91302BDE (dec: -1859114018), parent name: 'GAMEPAD_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xA4397B4E (dec: -1539736754), parent name: 'GAMEPAD_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x3BC53374 (dec: 1002779508), parent name: 'GAMEPAD_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x8819C7D6 (dec: -2011576362), parent name: 'GAMEPAD_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_101fake // hashcode: 0x420F0CED (dec: 1108282605)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x74F63655 (dec: 1962292821), parent name: 'GAMEPAD_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xB3BE4E05 (dec: -1279373819), parent name: 'GAMEPAD_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xAFA76E9A (dec: -1347981670), parent name: 'GAMEPAD_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x3EE8EB4D (dec: 1055451981), parent name: 'GAMEPAD_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x84616BC7 (dec: -2073990201), parent name: 'GAMEPAD_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union GAMEPAD_102fake // Hashcode: 0x78A3518C (dec: 2023969164)
{
	struct GAMEPAD_79fake misc[3];		// size=12, offset=0
	struct _CameraKey *cameraKey;		// size=24, offset=0
	struct GAMEPAD_80fake teleport;		// size=16, offset=0
	struct GAMEPAD_81fake cameraValue;  // size=8, offset=0
	struct GAMEPAD_82fake miscValue;	// size=8, offset=0
	struct GAMEPAD_83fake logicValue;   // size=8, offset=0
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
	struct GAMEPAD_84fake cameraShake;  // size=8, offset=0
	long cameraSave;					// size=0, offset=0
	long cameraRestore;					// size=0, offset=0
	struct _BGObject *bgObject;			// size=24, offset=0
	long value[2];						// size=8, offset=0
	struct GAMEPAD_85fake sound;		// size=12, offset=0
	void *intro;						// size=0, offset=0
	long deathZ;						// size=0, offset=0
	struct GAMEPAD_86fake dsignal;		// size=8, offset=0
	void *mirror;						// size=0, offset=0
	long fogNear;						// size=0, offset=0
	long fogFar;						// size=0, offset=0
	struct GAMEPAD_87fake gotoFrame;	// size=8, offset=0
	struct GAMEPAD_88fake changeModel;  // size=8, offset=0
	void *vmObject;						// size=0, offset=0
	struct GAMEPAD_89fake logic;		// size=8, offset=0
	void *callSignal;					// size=0, offset=0
	struct _SVector offset;				// size=8, offset=0
	struct Signal *gotoLabel;			// size=0, offset=0
	struct Signal *gosubLabel;			// size=0, offset=0
	struct GAMEPAD_90fake control;		// size=8, offset=0
	struct GAMEPAD_91fake zSignal;		// size=12, offset=0
	struct GAMEPAD_92fake StreamLevel;  // size=24, offset=0
	struct GAMEPAD_93fake shards;		// size=12, offset=0
	struct GAMEPAD_94fake cameraSpline; // size=8, offset=0
	struct GAMEPAD_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;					// size=0, offset=0
	struct GAMEPAD_96fake introFX;		// size=8, offset=0
	struct GAMEPAD_97fake introActive;  // size=8, offset=0
	struct GAMEPAD_98fake levelChange;  // size=18, offset=0
	long blendStart;					// size=0, offset=0
	struct GAMEPAD_99fake setTimes;		// size=8, offset=0
	struct GAMEPAD_100fake color;		// size=4, offset=0
	struct GAMEPAD_101fake print;		// size=12, offset=0
	long slideAngle;					// size=0, offset=0
};

union GAMEPAD_103fake // Hashcode: 0x2FA3E996 (dec: 799271318)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union GAMEPAD_108fake // Hashcode: 0xA0CF42DB (dec: -1597029669)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct GAMEPAD_110fake // hashcode: 0xFF405D5D (dec: -12559011)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x2C766090 (dec: 745955472), parent name: 'GAMEPAD_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xF4A71007 (dec: -190377977), parent name: 'GAMEPAD_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0xE220305D (dec: -501206947), parent name: 'GAMEPAD_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x5AD8407E (dec: 1524121726), parent name: 'GAMEPAD_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x49A45C49 (dec: 1235508297), parent name: 'GAMEPAD_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x2672AB20 (dec: 645049120), parent name: 'GAMEPAD_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x89E67F9F (dec: -1981382753), parent name: 'GAMEPAD_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_111fake // hashcode: 0x77342B6F (dec: 1999907695)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x51A78595 (dec: 1369933205), parent name: 'GAMEPAD_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x3113E595 (dec: 823387541), parent name: 'GAMEPAD_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x54E84013 (dec: 1424506899), parent name: 'GAMEPAD_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_112fake // hashcode: 0xA6D3BCAC (dec: -1496073044)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x7EE23832 (dec: 2128754738), parent name: 'GAMEPAD_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xFDA18A05 (dec: -39745019), parent name: 'GAMEPAD_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xC2566BD3 (dec: -1034523693), parent name: 'GAMEPAD_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xF4D0C66C (dec: -187644308), parent name: 'GAMEPAD_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xB5532671 (dec: -1252841871), parent name: 'GAMEPAD_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_113fake // hashcode: 0x7CEA765B (dec: 2095740507)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x273F3B63 (dec: 658455395), parent name: 'GAMEPAD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x0F2977C5 (dec: 254375877), parent name: 'GAMEPAD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x910E4B3F (dec: -1861334209), parent name: 'GAMEPAD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x0E7C08D0 (dec: 243009744), parent name: 'GAMEPAD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xC78809FB (dec: -947385861), parent name: 'GAMEPAD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GAMEPAD_114fake // hashcode: 0xA495E8C3 (dec: -1533679421)
{
	struct GAMEPAD_110fake Cinematic; // size=28, offset=0 //  hashcode: 0xC96EB6AF (dec: -915491153), parent name: 'GAMEPAD_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct GAMEPAD_111fake Idle;	  // size=20, offset=28 //  hashcode: 0xB43D041C (dec: -1271069668), parent name: 'GAMEPAD_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct GAMEPAD_112fake Behind;	// size=28, offset=48 //  hashcode: 0x4B8A01E2 (dec: 1267335650), parent name: 'GAMEPAD_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct GAMEPAD_113fake Follow;	// size=20, offset=76 //  hashcode: 0x3830A5EA (dec: 942712298), parent name: 'GAMEPAD_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union GAMEPAD_200fake // Hashcode: 0xE2465038 (dec: -498708424)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct JoypadMappingStruct // hashcode: 0x312F2BE8 (dec: 825175016)
{
	unsigned short psxData;		// size=0, offset=0 //  hashcode: 0x881D51BF (dec: -2011344449), parent name: 'JoypadMappingStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short translation; // size=0, offset=2 //  hashcode: 0xA6DF2CC6 (dec: -1495323450), parent name: 'JoypadMappingStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union GAMEPAD_219fake // Hashcode: 0x0901469D (dec: 151078557)
{
	unsigned short pad;			  // size=0, offset=0
	unsigned short multitap[16];  // size=32, offset=0
	unsigned short mouse[2];	  // size=4, offset=0
	unsigned short negcon[3];	 // size=6, offset=0
	struct AnalogueData analogue; // size=6, offset=0
};

struct ControllerPacket // hashcode: 0x9621B4F3 (dec: -1776175885)
{
	unsigned char transStatus;  // size=0, offset=0 //  hashcode: 0xBADF7D43 (dec: -1159758525), parent name: 'ControllerPacket', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char dataFormat;   // size=0, offset=1 //  hashcode: 0x8A9C2707 (dec: -1969477881), parent name: 'ControllerPacket', parent hashcode: 0xFFFFFFFF (dec: -1)
	union GAMEPAD_219fake data; // size=32, offset=2 //  hashcode: 0xAF56816A (dec: -1353285270), parent name: 'ControllerPacket', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct JoypadMappingStruct JoypadMapping;

typedef struct ControllerPacket ControllerPacket;

extern void GAMEPAD_Commands(long (*command)[5], long (*data)[5], long pad); // 0x80030F68

extern int GAMEPAD_ControllerIsDualShock(); // 0x80031324

extern int GAMEPAD_DualShockEnabled(); // 0x80031330

extern void GAMEPAD_DisableDualShock(); // 0x8003133C

extern void GAMEPAD_EnableDualShock(); // 0x8003137C

extern void GAMEPAD_HandleDualShock(); // 0x80031390

extern void GAMEPAD_Shock(int motor0_speed, int motor0_time, int motor1_speed, int motor1_time); // 0x80031488

extern void GAMEPAD_Shock0(int motor0_speed, int motor0_time); // 0x800314CC

extern void GAMEPAD_Shock1(int motor1_speed, int motor1_time); // 0x80031508

extern void GAMEPAD_Detect(); // 0x80031544

extern void GAMEPAD_Init(); // 0x8003164C

extern void PSXPAD_TranslateData(long *data, unsigned short padData, unsigned short lastData); // 0x800316D4

extern unsigned short GAMEPAD_RemapAnalogueButtons(unsigned short in); // 0x800317F8

extern void GAMEPAD_DetectInit(); // 0x80031844

extern void GAMEPAD_GetData(long (*data)[5]); // 0x8003188C

extern void GAMEPAD_DisplayControllerStatus(int msgY); // 0x80031CC8

extern void GAMEPAD_Process(struct GameTracker *gameTracker); // 0x80031D28

extern void GAMEPAD_SaveControllers(); // 0x80031D80

extern void GAMEPAD_RestoreControllers(); // 0x80031E1C

#endif
