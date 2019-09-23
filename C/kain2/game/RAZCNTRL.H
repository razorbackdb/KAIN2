#ifndef RAZCNTRL_H
#define RAZCNTRL_H

static int Down; // offset 0x800CF590

static int Pending; // offset 0x800CF588

extern long RazielCommands[10]; // offset 0x800CF560

static int Up; // offset 0x800CF58C

struct RAZCNTRL_68fake // hashcode: 0xEE65C89E (dec: -295319394)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x939A599A (dec: -1818601062), parent name: 'RAZCNTRL_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x074CCA93 (dec: 122473107), parent name: 'RAZCNTRL_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_69fake // hashcode: 0x547DE882 (dec: 1417537666)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x04CFCC05 (dec: 80727045), parent name: 'RAZCNTRL_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x219A45E0 (dec: 563758560), parent name: 'RAZCNTRL_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_70fake // hashcode: 0x6C4B2285 (dec: 1816863365)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xE37A9840 (dec: -478504896), parent name: 'RAZCNTRL_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x6751920C (dec: 1733399052), parent name: 'RAZCNTRL_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union RAZCNTRL_71fake // Hashcode: 0x71649135 (dec: 1902416181)
{
	struct RAZCNTRL_68fake callback; // size=8, offset=0
	struct RAZCNTRL_69fake vector;   // size=12, offset=0
	struct RAZCNTRL_70fake quat;	 // size=16, offset=0
};

union RAZCNTRL_72fake // Hashcode: 0xF95E971E (dec: -111241442)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union RAZCNTRL_73fake // Hashcode: 0x3C1706C1 (dec: 1008142017)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct RAZCNTRL_74fake // hashcode: 0x85ACE3C6 (dec: -2052267066)
{
	union RAZCNTRL_73fake size; // size=4, offset=0 //  hashcode: 0xCDBEFFC5 (dec: -843120699), parent name: 'RAZCNTRL_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_75fake // hashcode: 0x4085CA37 (dec: 1082509879)
{
	short x;				// size=0, offset=0 //  hashcode: 0xFCF2B1DC (dec: -51203620), parent name: 'RAZCNTRL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xF35DAE2E (dec: -211964370), parent name: 'RAZCNTRL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x47E0F746 (dec: 1205925702), parent name: 'RAZCNTRL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x3E505F9F (dec: 1045454751), parent name: 'RAZCNTRL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x9ED1D0BF (dec: -1630416705), parent name: 'RAZCNTRL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_76fake // hashcode: 0xA57E7826 (dec: -1518438362)
{
	long index; // size=0, offset=0 //  hashcode: 0xD3A43757 (dec: -744212649), parent name: 'RAZCNTRL_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xB4082C53 (dec: -1274532781), parent name: 'RAZCNTRL_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_77fake // hashcode: 0x35BC986D (dec: 901552237)
{
	long index; // size=0, offset=0 //  hashcode: 0xD266D11A (dec: -765013734), parent name: 'RAZCNTRL_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x811FAF47 (dec: -2128629945), parent name: 'RAZCNTRL_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_78fake // hashcode: 0xDD94313F (dec: -577490625)
{
	long index; // size=0, offset=0 //  hashcode: 0xE952CD2F (dec: -380449489), parent name: 'RAZCNTRL_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xB86B9F97 (dec: -1200906345), parent name: 'RAZCNTRL_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_79fake // hashcode: 0x72441A8B (dec: 1917065867)
{
	long time;  // size=0, offset=0 //  hashcode: 0x2D7B50F7 (dec: 763056375), parent name: 'RAZCNTRL_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x7DF572C2 (dec: 2113237698), parent name: 'RAZCNTRL_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_80fake // hashcode: 0x084AC6A3 (dec: 139118243)
{
	long action;   // size=0, offset=0 //  hashcode: 0x83F44A42 (dec: -2081142206), parent name: 'RAZCNTRL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xFB2BAA9C (dec: -81024356), parent name: 'RAZCNTRL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_81fake // hashcode: 0xAFB41076 (dec: -1347153802)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x3B280FB4 (dec: 992481204), parent name: 'RAZCNTRL_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xC3E64970 (dec: -1008318096), parent name: 'RAZCNTRL_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_82fake // hashcode: 0x2C1FB541 (dec: 740275521)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x19821467 (dec: 427955303), parent name: 'RAZCNTRL_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x0A349DDB (dec: 171220443), parent name: 'RAZCNTRL_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_83fake // hashcode: 0x4B2EFAF3 (dec: 1261370099)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x14DB6B6C (dec: 349924204), parent name: 'RAZCNTRL_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xE3DAB19A (dec: -472206950), parent name: 'RAZCNTRL_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_84fake // hashcode: 0x814F0664 (dec: -2125527452)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x70A87FFC (dec: 1890091004), parent name: 'RAZCNTRL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x1B759BFD (dec: 460692477), parent name: 'RAZCNTRL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x6395B1F5 (dec: 1670754805), parent name: 'RAZCNTRL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x4E8C0558 (dec: 1317799256), parent name: 'RAZCNTRL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xC82FDF89 (dec: -936386679), parent name: 'RAZCNTRL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_85fake // hashcode: 0x19E4DE28 (dec: 434429480)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x642EC9D4 (dec: 1680787924), parent name: 'RAZCNTRL_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x2CB7B5AF (dec: 750237103), parent name: 'RAZCNTRL_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_86fake // hashcode: 0xD8ED867F (dec: -655522177)
{
	short index;					// size=0, offset=0 //  hashcode: 0xF4B0D27E (dec: -189738370), parent name: 'RAZCNTRL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xD1BB485B (dec: -776255397), parent name: 'RAZCNTRL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xB8B3223E (dec: -1196219842), parent name: 'RAZCNTRL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x819B4D4C (dec: -2120528564), parent name: 'RAZCNTRL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_87fake // hashcode: 0x985F7E58 (dec: -1738572200)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xC373746B (dec: -1015843733), parent name: 'RAZCNTRL_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x42FFB9BC (dec: 1124055484), parent name: 'RAZCNTRL_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x8C9F11F2 (dec: -1935732238), parent name: 'RAZCNTRL_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_88fake // hashcode: 0x49EFA0C8 (dec: 1240441032)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x65503044 (dec: 1699754052), parent name: 'RAZCNTRL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xD4413387 (dec: -733924473), parent name: 'RAZCNTRL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x3498DF48 (dec: 882433864), parent name: 'RAZCNTRL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x255BA91D (dec: 626764061), parent name: 'RAZCNTRL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x2F12930B (dec: 789746443), parent name: 'RAZCNTRL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xA57B0F82 (dec: -1518661758), parent name: 'RAZCNTRL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xEC1F8C91 (dec: -333476719), parent name: 'RAZCNTRL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_89fake // hashcode: 0xC3E0F31C (dec: -1008667876)
{
	long index;  // size=0, offset=0 //  hashcode: 0x089F6633 (dec: 144664115), parent name: 'RAZCNTRL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x95598B02 (dec: -1789293822), parent name: 'RAZCNTRL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_90fake // hashcode: 0x2F9DEF03 (dec: 798879491)
{
	short type; // size=0, offset=0 //  hashcode: 0x2D750767 (dec: 762644327), parent name: 'RAZCNTRL_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x7C7F5633 (dec: 2088719923), parent name: 'RAZCNTRL_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_91fake // hashcode: 0xCFE88716 (dec: -806844650)
{
	long time;   // size=0, offset=0 //  hashcode: 0x494872E4 (dec: 1229484772), parent name: 'RAZCNTRL_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xD1AF0586 (dec: -777058938), parent name: 'RAZCNTRL_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_92fake // hashcode: 0xB531C1AD (dec: -1255030355)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xA3D5BA1A (dec: -1546274278), parent name: 'RAZCNTRL_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x11DD4947 (dec: 299714887), parent name: 'RAZCNTRL_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_93fake // hashcode: 0x32432A98 (dec: 843262616)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x3C44A27E (dec: 1011131006), parent name: 'RAZCNTRL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x24DA5B7D (dec: 618290045), parent name: 'RAZCNTRL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_94fake // hashcode: 0xD15566EF (dec: -782932241)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x4AB203AE (dec: 1253180334), parent name: 'RAZCNTRL_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x3AACB182 (dec: 984396162), parent name: 'RAZCNTRL_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_95fake // hashcode: 0x9C1ABDF3 (dec: -1675969037)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x7E3656E8 (dec: 2117490408), parent name: 'RAZCNTRL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x35B1FACC (dec: 900856524), parent name: 'RAZCNTRL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xC6E0DAFB (dec: -958342405), parent name: 'RAZCNTRL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x878F9B53 (dec: -2020631725), parent name: 'RAZCNTRL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_96fake // hashcode: 0x34717D16 (dec: 879852822)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x06858BEF (dec: 109415407), parent name: 'RAZCNTRL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x8CEFAC9A (dec: -1930449766), parent name: 'RAZCNTRL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xBF54F8A0 (dec: -1084950368), parent name: 'RAZCNTRL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xCDE5D922 (dec: -840574686), parent name: 'RAZCNTRL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xB3E03B43 (dec: -1277150397), parent name: 'RAZCNTRL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union RAZCNTRL_97fake // Hashcode: 0xC23DFCDD (dec: -1036124963)
{
	struct RAZCNTRL_74fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;		 // size=24, offset=0
	struct RAZCNTRL_75fake teleport;	 // size=16, offset=0
	struct RAZCNTRL_76fake cameraValue;  // size=8, offset=0
	struct RAZCNTRL_77fake miscValue;	// size=8, offset=0
	struct RAZCNTRL_78fake logicValue;   // size=8, offset=0
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
	struct RAZCNTRL_79fake cameraShake;  // size=8, offset=0
	long cameraSave;					 // size=0, offset=0
	long cameraRestore;					 // size=0, offset=0
	struct _BGObject *bgObject;			 // size=24, offset=0
	long value[2];						 // size=8, offset=0
	struct RAZCNTRL_80fake sound;		 // size=12, offset=0
	void *intro;						 // size=0, offset=0
	long deathZ;						 // size=0, offset=0
	struct RAZCNTRL_81fake dsignal;		 // size=8, offset=0
	void *mirror;						 // size=0, offset=0
	long fogNear;						 // size=0, offset=0
	long fogFar;						 // size=0, offset=0
	struct RAZCNTRL_82fake gotoFrame;	// size=8, offset=0
	struct RAZCNTRL_83fake changeModel;  // size=8, offset=0
	void *vmObject;						 // size=0, offset=0
	struct RAZCNTRL_84fake logic;		 // size=8, offset=0
	void *callSignal;					 // size=0, offset=0
	struct _SVector offset;				 // size=8, offset=0
	struct Signal *gotoLabel;			 // size=0, offset=0
	struct Signal *gosubLabel;			 // size=0, offset=0
	struct RAZCNTRL_85fake control;		 // size=8, offset=0
	struct RAZCNTRL_86fake zSignal;		 // size=12, offset=0
	struct RAZCNTRL_87fake StreamLevel;  // size=24, offset=0
	struct RAZCNTRL_88fake shards;		 // size=12, offset=0
	struct RAZCNTRL_89fake cameraSpline; // size=8, offset=0
	struct RAZCNTRL_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;					 // size=0, offset=0
	struct RAZCNTRL_91fake introFX;		 // size=8, offset=0
	struct RAZCNTRL_92fake introActive;  // size=8, offset=0
	struct RAZCNTRL_93fake levelChange;  // size=18, offset=0
	long blendStart;					 // size=0, offset=0
	struct RAZCNTRL_94fake setTimes;	 // size=8, offset=0
	struct RAZCNTRL_95fake color;		 // size=4, offset=0
	struct RAZCNTRL_96fake print;		 // size=12, offset=0
	long slideAngle;					 // size=0, offset=0
};

union RAZCNTRL_98fake // Hashcode: 0x9CB0C77A (dec: -1666136198)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union RAZCNTRL_103fake // Hashcode: 0x36CB115B (dec: 919277915)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct RAZCNTRL_105fake // hashcode: 0x45C84246 (dec: 1170752070)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x3E386BAA (dec: 1043884970), parent name: 'RAZCNTRL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x314F55A5 (dec: 827282853), parent name: 'RAZCNTRL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0xFF0C3956 (dec: -15976106), parent name: 'RAZCNTRL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xC7BE5D21 (dec: -943825631), parent name: 'RAZCNTRL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x0E0FF981 (dec: 235927937), parent name: 'RAZCNTRL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x883882F5 (dec: -2009562379), parent name: 'RAZCNTRL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x8555D2B5 (dec: -2057973067), parent name: 'RAZCNTRL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_106fake // hashcode: 0x54EB830D (dec: 1424720653)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0xC5DC7CB9 (dec: -975405895), parent name: 'RAZCNTRL_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xF4CCF4BB (dec: -187894597), parent name: 'RAZCNTRL_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xC90A009D (dec: -922091363), parent name: 'RAZCNTRL_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_107fake // hashcode: 0xE074C407 (dec: -529218553)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x7C2DDE2B (dec: 2083380779), parent name: 'RAZCNTRL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x24714AED (dec: 611404525), parent name: 'RAZCNTRL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xB1E4EC03 (dec: -1310397437), parent name: 'RAZCNTRL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xD9F2588A (dec: -638429046), parent name: 'RAZCNTRL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x78EDD58E (dec: 2028852622), parent name: 'RAZCNTRL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_108fake // hashcode: 0x88EE322B (dec: -1997655509)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x8FEBF2AC (dec: -1880362324), parent name: 'RAZCNTRL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x3BE79F7E (dec: 1005035390), parent name: 'RAZCNTRL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x515452E9 (dec: 1364480745), parent name: 'RAZCNTRL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xE9A34736 (dec: -375175370), parent name: 'RAZCNTRL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xCCC7EEFD (dec: -859312387), parent name: 'RAZCNTRL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RAZCNTRL_109fake // hashcode: 0x79D2E6E3 (dec: 2043864803)
{
	struct RAZCNTRL_105fake Cinematic; // size=28, offset=0 //  hashcode: 0xC81EE382 (dec: -937499774), parent name: 'RAZCNTRL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RAZCNTRL_106fake Idle;	  // size=20, offset=28 //  hashcode: 0x8F6FF5CA (dec: -1888487990), parent name: 'RAZCNTRL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RAZCNTRL_107fake Behind;	// size=28, offset=48 //  hashcode: 0xEBD818D2 (dec: -338159406), parent name: 'RAZCNTRL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RAZCNTRL_108fake Follow;	// size=20, offset=76 //  hashcode: 0xCC03ED32 (dec: -872157902), parent name: 'RAZCNTRL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

extern void ProcessRazControl(long *command); // 0x80070694

#endif
