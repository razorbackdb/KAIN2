#ifndef SLUAGH_H
#define SLUAGH_H

extern struct _MonsterFunctionTable SLUAGH_FunctionTable; // offset 0x800CF6AC

extern struct _MonsterStateChoice SLUAGH_StateChoiceTable[4]; // offset 0x800CAB18

struct SLUAGH_73fake // hashcode: 0x57E232C5 (dec: 1474441925)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x14C7701B (dec: 348614683), parent name: 'SLUAGH_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0xAD77E186 (dec: -1384652410), parent name: 'SLUAGH_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_74fake // hashcode: 0x96EF2CDB (dec: -1762710309)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x95C8563A (dec: -1782032838), parent name: 'SLUAGH_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xD27AB785 (dec: -763709563), parent name: 'SLUAGH_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_75fake // hashcode: 0x314D1179 (dec: 827134329)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x79F4ACCA (dec: 2046078154), parent name: 'SLUAGH_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xD9EA6D12 (dec: -638948078), parent name: 'SLUAGH_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SLUAGH_76fake // Hashcode: 0x38C12C3D (dec: 952183869)
{
	struct SLUAGH_73fake callback; // size=8, offset=0
	struct SLUAGH_74fake vector;   // size=12, offset=0
	struct SLUAGH_75fake quat;	 // size=16, offset=0
};

union SLUAGH_77fake // Hashcode: 0x781A6F6B (dec: 2014998379)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union SLUAGH_78fake // Hashcode: 0x3104312E (dec: 822358318)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct SLUAGH_79fake // hashcode: 0xE2C15FA8 (dec: -490643544)
{
	union SLUAGH_78fake size; // size=4, offset=0 //  hashcode: 0x5B4343A1 (dec: 1531134881), parent name: 'SLUAGH_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_80fake // hashcode: 0x1091A44F (dec: 277980239)
{
	short x;				// size=0, offset=0 //  hashcode: 0x2CA8811C (dec: 749240604), parent name: 'SLUAGH_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xF003D641 (dec: -268183999), parent name: 'SLUAGH_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x3F6977B5 (dec: 1063876533), parent name: 'SLUAGH_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x03875A4A (dec: 59202122), parent name: 'SLUAGH_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x5DA5D110 (dec: 1571148048), parent name: 'SLUAGH_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_81fake // hashcode: 0xBC306906 (dec: -1137678074)
{
	long index; // size=0, offset=0 //  hashcode: 0x7AFF6B96 (dec: 2063559574), parent name: 'SLUAGH_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x98E81C8D (dec: -1729618803), parent name: 'SLUAGH_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_82fake // hashcode: 0xDEC0411A (dec: -557825766)
{
	long index; // size=0, offset=0 //  hashcode: 0xA824CBA8 (dec: -1473983576), parent name: 'SLUAGH_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xB9046BB8 (dec: -1190892616), parent name: 'SLUAGH_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_83fake // hashcode: 0x4CD1F8EE (dec: 1288829166)
{
	long index; // size=0, offset=0 //  hashcode: 0x11274F27 (dec: 287788839), parent name: 'SLUAGH_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xAAC35FB2 (dec: -1430036558), parent name: 'SLUAGH_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_84fake // hashcode: 0x52725AED (dec: 1383226093)
{
	long time;  // size=0, offset=0 //  hashcode: 0xCACB195C (dec: -892659364), parent name: 'SLUAGH_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x4EBF3388 (dec: 1321153416), parent name: 'SLUAGH_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_85fake // hashcode: 0xD6F3DE32 (dec: -688660942)
{
	long action;   // size=0, offset=0 //  hashcode: 0xE7DF9639 (dec: -404777415), parent name: 'SLUAGH_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x441EDDC4 (dec: 1142873540), parent name: 'SLUAGH_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_86fake // hashcode: 0xC37D3DCB (dec: -1015202357)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xC45F749E (dec: -1000377186), parent name: 'SLUAGH_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xFD6529DD (dec: -43701795), parent name: 'SLUAGH_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_87fake // hashcode: 0x2B786A58 (dec: 729311832)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x0EA7CD16 (dec: 245878038), parent name: 'SLUAGH_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0xCD872D01 (dec: -846779135), parent name: 'SLUAGH_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_88fake // hashcode: 0xA3485AD1 (dec: -1555539247)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xA00BCB32 (dec: -1609839822), parent name: 'SLUAGH_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x16DF58FF (dec: 383736063), parent name: 'SLUAGH_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_89fake // hashcode: 0x7C998605 (dec: 2090436101)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x6917FDA5 (dec: 1763179941), parent name: 'SLUAGH_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x408E19D4 (dec: 1083054548), parent name: 'SLUAGH_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xDE504B0C (dec: -565163252), parent name: 'SLUAGH_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xB001D75D (dec: -1342056611), parent name: 'SLUAGH_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xBDDA624A (dec: -1109761462), parent name: 'SLUAGH_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_90fake // hashcode: 0x61719752 (dec: 1634834258)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xB57B2D0F (dec: -1250218737), parent name: 'SLUAGH_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x649790E6 (dec: 1687654630), parent name: 'SLUAGH_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_91fake // hashcode: 0xF8D9ABA1 (dec: -119952479)
{
	short index;					// size=0, offset=0 //  hashcode: 0xB44E4C85 (dec: -1269937019), parent name: 'SLUAGH_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xBDF8FECD (dec: -1107755315), parent name: 'SLUAGH_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x3EF9150C (dec: 1056511244), parent name: 'SLUAGH_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x92630942 (dec: -1839003326), parent name: 'SLUAGH_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_92fake // hashcode: 0xF4C66E5F (dec: -188322209)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x18A735AF (dec: 413611439), parent name: 'SLUAGH_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xD62740D5 (dec: -702070571), parent name: 'SLUAGH_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x447757E3 (dec: 1148671971), parent name: 'SLUAGH_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_93fake // hashcode: 0x37DE61A1 (dec: 937320865)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x45AC986F (dec: 1168939119), parent name: 'SLUAGH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x824C82E2 (dec: -2108914974), parent name: 'SLUAGH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xA0DF1ADF (dec: -1595991329), parent name: 'SLUAGH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x8B11E9BB (dec: -1961760325), parent name: 'SLUAGH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x91C7A9ED (dec: -1849185811), parent name: 'SLUAGH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xA21B6007 (dec: -1575264249), parent name: 'SLUAGH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x75D3DE25 (dec: 1976819237), parent name: 'SLUAGH_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_94fake // hashcode: 0xB3F61CD0 (dec: -1275716400)
{
	long index;  // size=0, offset=0 //  hashcode: 0x352B75EC (dec: 892040684), parent name: 'SLUAGH_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x9BF33D2B (dec: -1678557909), parent name: 'SLUAGH_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_95fake // hashcode: 0x054A4219 (dec: 88752665)
{
	short type; // size=0, offset=0 //  hashcode: 0x115638E1 (dec: 290863329), parent name: 'SLUAGH_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x070E40EE (dec: 118374638), parent name: 'SLUAGH_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_96fake // hashcode: 0x85CD04F4 (dec: -2050161420)
{
	long time;   // size=0, offset=0 //  hashcode: 0xCB661E3C (dec: -882500036), parent name: 'SLUAGH_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xAA331DC8 (dec: -1439490616), parent name: 'SLUAGH_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_97fake // hashcode: 0xB40E8B52 (dec: -1274115246)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x1A73E4C5 (dec: 443802821), parent name: 'SLUAGH_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xF42E16A4 (dec: -198306140), parent name: 'SLUAGH_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_98fake // hashcode: 0x1AAE7164 (dec: 447639908)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x15BC5B10 (dec: 364665616), parent name: 'SLUAGH_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x1A4173AF (dec: 440497071), parent name: 'SLUAGH_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_99fake // hashcode: 0x5AC6951B (dec: 1522963739)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x11FA9E39 (dec: 301637177), parent name: 'SLUAGH_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xFF0833B9 (dec: -16239687), parent name: 'SLUAGH_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_100fake // hashcode: 0xB4A749F6 (dec: -1264104970)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0xE80C5903 (dec: -401843965), parent name: 'SLUAGH_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xB62FD9BB (dec: -1238378053), parent name: 'SLUAGH_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xFA1F1034 (dec: -98627532), parent name: 'SLUAGH_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x745C818A (dec: 1952219530), parent name: 'SLUAGH_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_101fake // hashcode: 0x4DE458DB (dec: 1306810587)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xDCC5C61A (dec: -591018470), parent name: 'SLUAGH_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x256DE6F5 (dec: 627959541), parent name: 'SLUAGH_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x2A005D69 (dec: 704666985), parent name: 'SLUAGH_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xA9ED2D14 (dec: -1444074220), parent name: 'SLUAGH_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x349F9229 (dec: 882872873), parent name: 'SLUAGH_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SLUAGH_102fake // Hashcode: 0xEECDD651 (dec: -288500143)
{
	struct SLUAGH_79fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	  // size=24, offset=0
	struct SLUAGH_80fake teleport;	 // size=16, offset=0
	struct SLUAGH_81fake cameraValue;  // size=8, offset=0
	struct SLUAGH_82fake miscValue;	// size=8, offset=0
	struct SLUAGH_83fake logicValue;   // size=8, offset=0
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
	struct SLUAGH_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				   // size=0, offset=0
	long cameraRestore;				   // size=0, offset=0
	struct _BGObject *bgObject;		   // size=24, offset=0
	long value[2];					   // size=8, offset=0
	struct SLUAGH_85fake sound;		   // size=12, offset=0
	void *intro;					   // size=0, offset=0
	long deathZ;					   // size=0, offset=0
	struct SLUAGH_86fake dsignal;	  // size=8, offset=0
	void *mirror;					   // size=0, offset=0
	long fogNear;					   // size=0, offset=0
	long fogFar;					   // size=0, offset=0
	struct SLUAGH_87fake gotoFrame;	// size=8, offset=0
	struct SLUAGH_88fake changeModel;  // size=8, offset=0
	void *vmObject;					   // size=0, offset=0
	struct SLUAGH_89fake logic;		   // size=8, offset=0
	void *callSignal;				   // size=0, offset=0
	struct _SVector offset;			   // size=8, offset=0
	struct Signal *gotoLabel;		   // size=0, offset=0
	struct Signal *gosubLabel;		   // size=0, offset=0
	struct SLUAGH_90fake control;	  // size=8, offset=0
	struct SLUAGH_91fake zSignal;	  // size=12, offset=0
	struct SLUAGH_92fake StreamLevel;  // size=24, offset=0
	struct SLUAGH_93fake shards;	   // size=12, offset=0
	struct SLUAGH_94fake cameraSpline; // size=8, offset=0
	struct SLUAGH_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				   // size=0, offset=0
	struct SLUAGH_96fake introFX;	  // size=8, offset=0
	struct SLUAGH_97fake introActive;  // size=8, offset=0
	struct SLUAGH_98fake levelChange;  // size=18, offset=0
	long blendStart;				   // size=0, offset=0
	struct SLUAGH_99fake setTimes;	 // size=8, offset=0
	struct SLUAGH_100fake color;	   // size=4, offset=0
	struct SLUAGH_101fake print;	   // size=12, offset=0
	long slideAngle;				   // size=0, offset=0
};

union SLUAGH_103fake // Hashcode: 0x06315E99 (dec: 103898777)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union SLUAGH_108fake // Hashcode: 0x1D6317C3 (dec: 493033411)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct SLUAGH_110fake // hashcode: 0xFF2AE061 (dec: -13967263)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x20EA2B90 (dec: 552217488), parent name: 'SLUAGH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x5516CDC5 (dec: 1427557829), parent name: 'SLUAGH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x898598C9 (dec: -1987733303), parent name: 'SLUAGH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xFF650806 (dec: -10156026), parent name: 'SLUAGH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x2694D984 (dec: 647289220), parent name: 'SLUAGH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xE572C17A (dec: -445464198), parent name: 'SLUAGH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x2AAB4954 (dec: 715868500), parent name: 'SLUAGH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_111fake // hashcode: 0x6A3B3A37 (dec: 1782266423)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x37A1E323 (dec: 933356323), parent name: 'SLUAGH_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x402AD755 (dec: 1076549461), parent name: 'SLUAGH_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x54FECCCE (dec: 1425984718), parent name: 'SLUAGH_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_112fake // hashcode: 0xE217C2B3 (dec: -501759309)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xF6CCF2BB (dec: -154340677), parent name: 'SLUAGH_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x48E75AD4 (dec: 1223121620), parent name: 'SLUAGH_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x9152A6D0 (dec: -1856854320), parent name: 'SLUAGH_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x7B2F4C6C (dec: 2066697324), parent name: 'SLUAGH_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xFA20D035 (dec: -98512843), parent name: 'SLUAGH_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_113fake // hashcode: 0x029D2D98 (dec: 43855256)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x52B2D6A4 (dec: 1387452068), parent name: 'SLUAGH_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0xBB36B038 (dec: -1154043848), parent name: 'SLUAGH_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x6D1B9218 (dec: 1830523416), parent name: 'SLUAGH_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x04054453 (dec: 67454035), parent name: 'SLUAGH_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x10FF8B23 (dec: 285182755), parent name: 'SLUAGH_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_114fake // hashcode: 0x17BD51C9 (dec: 398283209)
{
	struct SLUAGH_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x19B41664 (dec: 431232612), parent name: 'SLUAGH_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SLUAGH_111fake Idle;		 // size=20, offset=28 //  hashcode: 0xEF1D03FF (dec: -283311105), parent name: 'SLUAGH_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SLUAGH_112fake Behind;	// size=28, offset=48 //  hashcode: 0xC3FBCADB (dec: -1006908709), parent name: 'SLUAGH_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SLUAGH_113fake Follow;	// size=20, offset=76 //  hashcode: 0x46EDA09B (dec: 1189978267), parent name: 'SLUAGH_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SLUAGH_193fake // Hashcode: 0x537C56CA (dec: 1400657610)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct SLUAGH_212fake // hashcode: 0xB084EFDC (dec: -1333465124)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0xC1C771A9 (dec: -1043893847), parent name: 'SLUAGH_212fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0xDC64C6AC (dec: -597375316), parent name: 'SLUAGH_212fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SLUAGH_213fake // hashcode: 0x115F2FBE (dec: 291450814)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x9FEF1D77 (dec: -1611719305), parent name: 'SLUAGH_213fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0xD091C8F2 (dec: -795752206), parent name: 'SLUAGH_213fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0xEBD224DD (dec: -338549539), parent name: 'SLUAGH_213fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x9CB174BD (dec: -1666091843), parent name: 'SLUAGH_213fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x235833B9 (dec: 592982969), parent name: 'SLUAGH_213fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0xB21FDD09 (dec: -1306534647), parent name: 'SLUAGH_213fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SLUAGH_214fake // Hashcode: 0x406B78CB (dec: 1080785099)
{
	struct SLUAGH_212fake flame; // size=8, offset=0
	struct SLUAGH_213fake phys;  // size=12, offset=0
};

extern unsigned long SLUAGH_Query(struct _Instance *instance, unsigned long query); // 0x8008D04C

extern void SLUAGH_DamageEffect(struct _Instance *instance, struct evFXHitData *data); // 0x8008D0E0

extern void SLUAGH_Init(struct _Instance *instance); // 0x8008D2D4

extern void SLUAGH_DeathEntry(struct _Instance *instance); // 0x8008D390

extern void SLUAGH_Death(struct _Instance *instance); // 0x8008D454

extern void SLUAGH_AttackEntry(struct _Instance *instance); // 0x8008D4DC

extern void SLUAGH_Attack(struct _Instance *instance); // 0x8008D540

#endif
