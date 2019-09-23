#ifndef LIGHT3D_H
#define LIGHT3D_H

static struct LightGroup default_lightgroup; // offset 0x800CE460

extern struct LightInfo *light_lightInfo; // offset 0x800D0D80

extern struct _Terrain *light_terrain; // offset 0x800D0D7C

struct LIGHT3D_68fake // hashcode: 0xE7346C18 (dec: -415994856)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x56297A10 (dec: 1445558800), parent name: 'LIGHT3D_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0xB7972459 (dec: -1214831527), parent name: 'LIGHT3D_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_69fake // hashcode: 0xD201A2CF (dec: -771644721)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x2B1E6CE6 (dec: 723414246), parent name: 'LIGHT3D_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xD620D706 (dec: -702490874), parent name: 'LIGHT3D_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_70fake // hashcode: 0x229A9CBE (dec: 580558014)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x4AE2E655 (dec: 1256384085), parent name: 'LIGHT3D_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xD78BDE81 (dec: -678699391), parent name: 'LIGHT3D_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union LIGHT3D_71fake // Hashcode: 0xEEF7B666 (dec: -285755802)
{
	struct LIGHT3D_68fake callback; // size=8, offset=0
	struct LIGHT3D_69fake vector;   // size=12, offset=0
	struct LIGHT3D_70fake quat;		// size=16, offset=0
};

union LIGHT3D_72fake // Hashcode: 0xA2C28EAD (dec: -1564307795)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union LIGHT3D_73fake // Hashcode: 0x06B158A8 (dec: 112285864)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct LIGHT3D_74fake // hashcode: 0x5C544C52 (dec: 1549028434)
{
	union LIGHT3D_73fake size; // size=4, offset=0 //  hashcode: 0x7631F815 (dec: 1982986261), parent name: 'LIGHT3D_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_75fake // hashcode: 0x338690F6 (dec: 864456950)
{
	short x;				// size=0, offset=0 //  hashcode: 0xF85626B2 (dec: -128571726), parent name: 'LIGHT3D_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xEABABB70 (dec: -356861072), parent name: 'LIGHT3D_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x9CB9E8FD (dec: -1665537795), parent name: 'LIGHT3D_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xC716A94C (dec: -954816180), parent name: 'LIGHT3D_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xAF00F2D9 (dec: -1358892327), parent name: 'LIGHT3D_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_76fake // hashcode: 0x48214C47 (dec: 1210141767)
{
	long index; // size=0, offset=0 //  hashcode: 0x0275157A (dec: 41227642), parent name: 'LIGHT3D_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xAB72B05D (dec: -1418547107), parent name: 'LIGHT3D_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_77fake // hashcode: 0x400D9E20 (dec: 1074634272)
{
	long index; // size=0, offset=0 //  hashcode: 0x0E07FDC0 (dec: 235404736), parent name: 'LIGHT3D_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x8890387D (dec: -2003814275), parent name: 'LIGHT3D_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_78fake // hashcode: 0x776A5534 (dec: 2003457332)
{
	long index; // size=0, offset=0 //  hashcode: 0x7572FC2E (dec: 1970469934), parent name: 'LIGHT3D_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xC6ED4991 (dec: -957527663), parent name: 'LIGHT3D_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_79fake // hashcode: 0xF3512441 (dec: -212786111)
{
	long time;  // size=0, offset=0 //  hashcode: 0x6A2C50E5 (dec: 1781289189), parent name: 'LIGHT3D_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x8C913078 (dec: -1936641928), parent name: 'LIGHT3D_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_80fake // hashcode: 0x304E37E3 (dec: 810432483)
{
	long action;   // size=0, offset=0 //  hashcode: 0xD336ACDC (dec: -751391524), parent name: 'LIGHT3D_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x57C93715 (dec: 1472804629), parent name: 'LIGHT3D_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_81fake // hashcode: 0x52D986C9 (dec: 1389987529)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x7970E7DF (dec: 2037442527), parent name: 'LIGHT3D_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x2DBE0C5A (dec: 767429722), parent name: 'LIGHT3D_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_82fake // hashcode: 0x7E1B8A58 (dec: 2115734104)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x7153A830 (dec: 1901307952), parent name: 'LIGHT3D_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x0164C614 (dec: 23381524), parent name: 'LIGHT3D_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_83fake // hashcode: 0x20FE0605 (dec: 553518597)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x1BCFC8DE (dec: 466602206), parent name: 'LIGHT3D_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xF192006C (dec: -242089876), parent name: 'LIGHT3D_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_84fake // hashcode: 0xC4661EAD (dec: -999940435)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x2EA225CA (dec: 782378442), parent name: 'LIGHT3D_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x053FDA17 (dec: 88070679), parent name: 'LIGHT3D_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x45071334 (dec: 1158091572), parent name: 'LIGHT3D_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xCDC2CAC0 (dec: -842872128), parent name: 'LIGHT3D_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xFADD8E07 (dec: -86143481), parent name: 'LIGHT3D_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_85fake // hashcode: 0xE87F494A (dec: -394311350)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x1D4E3662 (dec: 491664994), parent name: 'LIGHT3D_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x184243EA (dec: 406995946), parent name: 'LIGHT3D_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_86fake // hashcode: 0xD213F2C1 (dec: -770444607)
{
	short index;					// size=0, offset=0 //  hashcode: 0xB4BE0DF8 (dec: -1262613000), parent name: 'LIGHT3D_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x6629AAAC (dec: 1714006700), parent name: 'LIGHT3D_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xF9E6A639 (dec: -102324679), parent name: 'LIGHT3D_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xF9CFDC86 (dec: -103818106), parent name: 'LIGHT3D_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_87fake // hashcode: 0x15CF5824 (dec: 365910052)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xB4863AD1 (dec: -1266271535), parent name: 'LIGHT3D_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x107894CA (dec: 276337866), parent name: 'LIGHT3D_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x7FC9311B (dec: 2143891739), parent name: 'LIGHT3D_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_88fake // hashcode: 0xA9DA44FE (dec: -1445313282)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xA3BC047D (dec: -1547959171), parent name: 'LIGHT3D_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x43688215 (dec: 1130922517), parent name: 'LIGHT3D_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x800451C3 (dec: -2147200573), parent name: 'LIGHT3D_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x80E9BCF7 (dec: -2132165385), parent name: 'LIGHT3D_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x51C0FC55 (dec: 1371602005), parent name: 'LIGHT3D_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x68CD62F8 (dec: 1758290680), parent name: 'LIGHT3D_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x9C573042 (dec: -1672007614), parent name: 'LIGHT3D_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_89fake // hashcode: 0xF26070D6 (dec: -228560682)
{
	long index;  // size=0, offset=0 //  hashcode: 0x07CBEBF9 (dec: 130804729), parent name: 'LIGHT3D_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x70D05780 (dec: 1892702080), parent name: 'LIGHT3D_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_90fake // hashcode: 0x3781C875 (dec: 931252341)
{
	short type; // size=0, offset=0 //  hashcode: 0x642D71E1 (dec: 1680699873), parent name: 'LIGHT3D_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x9C673D2D (dec: -1670955731), parent name: 'LIGHT3D_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_91fake // hashcode: 0x94B66E14 (dec: -1799983596)
{
	long time;   // size=0, offset=0 //  hashcode: 0x96FC299B (dec: -1761859173), parent name: 'LIGHT3D_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x6F24A94B (dec: 1864673611), parent name: 'LIGHT3D_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_92fake // hashcode: 0x58F5BD3F (dec: 1492499775)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xFF214C54 (dec: -14594988), parent name: 'LIGHT3D_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x792C423E (dec: 2032943678), parent name: 'LIGHT3D_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_93fake // hashcode: 0x05AB7A68 (dec: 95124072)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xF09E3EB3 (dec: -258064717), parent name: 'LIGHT3D_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xCE33BAEB (dec: -835470613), parent name: 'LIGHT3D_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_94fake // hashcode: 0x882F7710 (dec: -2010155248)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x6059D898 (dec: 1616500888), parent name: 'LIGHT3D_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xD3BBE220 (dec: -742661600), parent name: 'LIGHT3D_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_95fake // hashcode: 0x5ED6CAE1 (dec: 1591134945)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x8126579E (dec: -2128193634), parent name: 'LIGHT3D_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xC565E8FB (dec: -983176965), parent name: 'LIGHT3D_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xEECB61DF (dec: -288661025), parent name: 'LIGHT3D_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xF02EC675 (dec: -265369995), parent name: 'LIGHT3D_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_96fake // hashcode: 0xE16F7789 (dec: -512788599)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x5DCE01D9 (dec: 1573781977), parent name: 'LIGHT3D_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xD6AC8DE1 (dec: -693334559), parent name: 'LIGHT3D_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xC4B6922A (dec: -994667990), parent name: 'LIGHT3D_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xEE53F72B (dec: -296487125), parent name: 'LIGHT3D_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xCFCCACD2 (dec: -808669998), parent name: 'LIGHT3D_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union LIGHT3D_97fake // Hashcode: 0x3FCEC108 (dec: 1070514440)
{
	struct LIGHT3D_74fake misc[3];		// size=12, offset=0
	struct _CameraKey *cameraKey;		// size=24, offset=0
	struct LIGHT3D_75fake teleport;		// size=16, offset=0
	struct LIGHT3D_76fake cameraValue;  // size=8, offset=0
	struct LIGHT3D_77fake miscValue;	// size=8, offset=0
	struct LIGHT3D_78fake logicValue;   // size=8, offset=0
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
	struct LIGHT3D_79fake cameraShake;  // size=8, offset=0
	long cameraSave;					// size=0, offset=0
	long cameraRestore;					// size=0, offset=0
	struct _BGObject *bgObject;			// size=24, offset=0
	long value[2];						// size=8, offset=0
	struct LIGHT3D_80fake sound;		// size=12, offset=0
	void *intro;						// size=0, offset=0
	long deathZ;						// size=0, offset=0
	struct LIGHT3D_81fake dsignal;		// size=8, offset=0
	void *mirror;						// size=0, offset=0
	long fogNear;						// size=0, offset=0
	long fogFar;						// size=0, offset=0
	struct LIGHT3D_82fake gotoFrame;	// size=8, offset=0
	struct LIGHT3D_83fake changeModel;  // size=8, offset=0
	void *vmObject;						// size=0, offset=0
	struct LIGHT3D_84fake logic;		// size=8, offset=0
	void *callSignal;					// size=0, offset=0
	struct _SVector offset;				// size=8, offset=0
	struct Signal *gotoLabel;			// size=0, offset=0
	struct Signal *gosubLabel;			// size=0, offset=0
	struct LIGHT3D_85fake control;		// size=8, offset=0
	struct LIGHT3D_86fake zSignal;		// size=12, offset=0
	struct LIGHT3D_87fake StreamLevel;  // size=24, offset=0
	struct LIGHT3D_88fake shards;		// size=12, offset=0
	struct LIGHT3D_89fake cameraSpline; // size=8, offset=0
	struct LIGHT3D_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;					// size=0, offset=0
	struct LIGHT3D_91fake introFX;		// size=8, offset=0
	struct LIGHT3D_92fake introActive;  // size=8, offset=0
	struct LIGHT3D_93fake levelChange;  // size=18, offset=0
	long blendStart;					// size=0, offset=0
	struct LIGHT3D_94fake setTimes;		// size=8, offset=0
	struct LIGHT3D_95fake color;		// size=4, offset=0
	struct LIGHT3D_96fake print;		// size=12, offset=0
	long slideAngle;					// size=0, offset=0
};

union LIGHT3D_98fake // Hashcode: 0xD1C636D0 (dec: -775538992)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union LIGHT3D_103fake // Hashcode: 0xB7D36D6E (dec: -1210880658)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct LIGHT3D_105fake // hashcode: 0x02553079 (dec: 39137401)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xD242235C (dec: -767417508), parent name: 'LIGHT3D_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x222C6E87 (dec: 573337223), parent name: 'LIGHT3D_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x77CDBEEC (dec: 2009972460), parent name: 'LIGHT3D_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xC38CD33E (dec: -1014181058), parent name: 'LIGHT3D_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0xF35FAA26 (dec: -211834330), parent name: 'LIGHT3D_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x0C9C6467 (dec: 211575911), parent name: 'LIGHT3D_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xB3C09488 (dec: -1279224696), parent name: 'LIGHT3D_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_106fake // hashcode: 0x5AE99599 (dec: 1525257625)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x3AD9B50B (dec: 987346187), parent name: 'LIGHT3D_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xACC7ACAD (dec: -1396200275), parent name: 'LIGHT3D_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xA8D6FCA3 (dec: -1462305629), parent name: 'LIGHT3D_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_107fake // hashcode: 0x9CE42171 (dec: -1662770831)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x3C8DABEE (dec: 1015917550), parent name: 'LIGHT3D_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x58B198DF (dec: 1488034015), parent name: 'LIGHT3D_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x08CFFE5D (dec: 147848797), parent name: 'LIGHT3D_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x44BA57BC (dec: 1153062844), parent name: 'LIGHT3D_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xA76B0CA4 (dec: -1486156636), parent name: 'LIGHT3D_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_108fake // hashcode: 0xCF8EE88B (dec: -812717941)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x2D79D9C9 (dec: 762960329), parent name: 'LIGHT3D_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x91F63A19 (dec: -1846134247), parent name: 'LIGHT3D_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x8897B917 (dec: -2003322601), parent name: 'LIGHT3D_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x09A329B9 (dec: 161687993), parent name: 'LIGHT3D_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x9C56E3FE (dec: -1672027138), parent name: 'LIGHT3D_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LIGHT3D_109fake // hashcode: 0xCB7DE4CA (dec: -880941878)
{
	struct LIGHT3D_105fake Cinematic; // size=28, offset=0 //  hashcode: 0xF1B85E4D (dec: -239575475), parent name: 'LIGHT3D_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LIGHT3D_106fake Idle;	  // size=20, offset=28 //  hashcode: 0x5D072D8E (dec: 1560751502), parent name: 'LIGHT3D_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LIGHT3D_107fake Behind;	// size=28, offset=48 //  hashcode: 0xA42E042B (dec: -1540488149), parent name: 'LIGHT3D_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LIGHT3D_108fake Follow;	// size=20, offset=76 //  hashcode: 0xB4FE31C4 (dec: -1258409532), parent name: 'LIGHT3D_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union LIGHT3D_209fake // Hashcode: 0xF250A22A (dec: -229596630)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

typedef long LightFunc();

extern void LIGHT_GetLightMatrix(struct _Instance *instance, struct Level *level, struct MATRIX *lightM, struct MATRIX *colorM); // 0x80035824

extern void LIGHT_PresetInstanceLight(struct _Instance *instance, short attenuate, struct MATRIX *lm); // 0x80035B98

extern void LIGHT_GetAmbient(struct _ColorType *color, struct _Instance *instance); // 0x80035D14

extern void LIGHT_CalcLightValue(struct _TFace *tface, struct _Instance *instance, struct _Terrain *terrain); // 0x80035D44

extern void LIGHT_SetAmbientInstance(struct _Instance *instance, struct Level *level); // 0x80036498

extern void LIGHT_SetMatrixForLightGroupInstance(struct _Instance *instance, struct Level *level); // 0x800364C8

extern void LIGHT_DrawShadow(struct MATRIX *wcTransform, struct _Instance *instance, struct _PrimPool *primPool, unsigned long **ot); // 0x80036644

extern void LIGHT_CalcShadowPositions(struct GameTracker *gameTracker); // 0x80036928

extern void LIGHT_Restore(struct LightInfo *lightInfo); // 0x80036C28

extern void LIGHT_CalcDQPTable(struct Level *level); // 0x80036C30

#endif
