#ifndef CAMERA_H
#define CAMERA_H

static long ACE_amount; // offset 0x800CFE80

static short Camera_lookDist; // offset 0x800CFE8E

static short Camera_lookHeight; // offset 0x800CFE8C

extern long camera_modeToIndex[15]; // offset 0x800CDF38

static struct _SVector camera_plane; // offset 0x800CFE64

static struct _SVector camera_shakeOffset[16]; // offset 0x800CFDE4

static short camera_still; // offset 0x800CDF78

static short CameraLookStickyFlag; // offset 0x800CDF96

static short CenterFlag; // offset 0x800CFDDC

static short combat_cam_angle; // offset 0x800CFDD6

static short combat_cam_debounce; // offset 0x800CFDDA

static short combat_cam_distance; // offset 0x800CFDD4

static short combat_cam_weight; // offset 0x800CFDD8

static long current_roll_amount; // offset 0x800CDF80

static struct MATRIX cwTransform2X; // offset 0x800CFDB4

static short hitline_rot; // offset 0x800CFE7C

static struct _SVector left_point; // offset 0x800CFE6C

static short panic_count; // offset 0x800CDF9A

static struct _SVector right_point; // offset 0x800CFE74

static int roll_inc; // offset 0x800CDF84

static long roll_target; // offset 0x800CDF7C

static short shorten_count; // offset 0x800CDF74

static short shorten_flag; // offset 0x800CDF76

static struct _Rotation splinecam_helprot; // offset 0x800CFE84

extern struct Camera theCamera; // offset 0x800CFE90

static struct MATRIX wcTransform2X; // offset 0x800CFD94

static struct MATRIX wcTransformX; // offset 0x800CFD74

struct CAMERA_68fake // hashcode: 0x147325F8 (dec: 343090680)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x1ADAD6E8 (dec: 450549480), parent name: 'CAMERA_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x1AE32062 (dec: 451092578), parent name: 'CAMERA_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_69fake // hashcode: 0xC87BF6C8 (dec: -931399992)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x10E22DC6 (dec: 283258310), parent name: 'CAMERA_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xB49E14BF (dec: -1264708417), parent name: 'CAMERA_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_70fake // hashcode: 0x102F26BB (dec: 271525563)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xC247503D (dec: -1035513795), parent name: 'CAMERA_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x84D1F41D (dec: -2066615267), parent name: 'CAMERA_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union CAMERA_71fake // Hashcode: 0x0F6F6CC4 (dec: 258960580)
{
	struct CAMERA_68fake callback; // size=8, offset=0
	struct CAMERA_69fake vector;   // size=12, offset=0
	struct CAMERA_70fake quat;	 // size=16, offset=0
};

union CAMERA_72fake // Hashcode: 0x598765BC (dec: 1502045628)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union CAMERA_73fake // Hashcode: 0x698A9E79 (dec: 1770692217)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct CAMERA_74fake // hashcode: 0x999C696E (dec: -1717802642)
{
	union CAMERA_73fake size; // size=4, offset=0 //  hashcode: 0xD5FFA72F (dec: -704665809), parent name: 'CAMERA_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_75fake // hashcode: 0x3132AAA7 (dec: 825404071)
{
	short x;				// size=0, offset=0 //  hashcode: 0x8D2A8507 (dec: -1926593273), parent name: 'CAMERA_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x89AF67BF (dec: -1984993345), parent name: 'CAMERA_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xA1206510 (dec: -1591712496), parent name: 'CAMERA_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x478A028C (dec: 1200226956), parent name: 'CAMERA_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x1CB55929 (dec: 481646889), parent name: 'CAMERA_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_76fake // hashcode: 0xBB069DDD (dec: -1157194275)
{
	long index; // size=0, offset=0 //  hashcode: 0xD6AC16AF (dec: -693365073), parent name: 'CAMERA_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x1370A838 (dec: 326150200), parent name: 'CAMERA_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_77fake // hashcode: 0x06887C7E (dec: 109608062)
{
	long index; // size=0, offset=0 //  hashcode: 0x751C9975 (dec: 1964808565), parent name: 'CAMERA_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x90BF914E (dec: -1866493618), parent name: 'CAMERA_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_78fake // hashcode: 0xDE8EC79B (dec: -561068133)
{
	long index; // size=0, offset=0 //  hashcode: 0xCC1D182E (dec: -870508498), parent name: 'CAMERA_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x169E7B17 (dec: 379484951), parent name: 'CAMERA_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_79fake // hashcode: 0x46BEF3E2 (dec: 1186919394)
{
	long time;  // size=0, offset=0 //  hashcode: 0xF93C2A7E (dec: -113497474), parent name: 'CAMERA_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x3E5F1F50 (dec: 1046421328), parent name: 'CAMERA_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_80fake // hashcode: 0x400FF5E6 (dec: 1074787814)
{
	long action;   // size=0, offset=0 //  hashcode: 0x19DA510B (dec: 433737995), parent name: 'CAMERA_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xCF5AA706 (dec: -816142586), parent name: 'CAMERA_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_81fake // hashcode: 0xDCCE8780 (dec: -590444672)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xE3BFBD5F (dec: -473973409), parent name: 'CAMERA_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xF2EB9EDC (dec: -219439396), parent name: 'CAMERA_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_82fake // hashcode: 0x81945B17 (dec: -2120983785)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x95DA3571 (dec: -1780861583), parent name: 'CAMERA_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x53089A1E (dec: 1393072670), parent name: 'CAMERA_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_83fake // hashcode: 0x11E80D78 (dec: 300420472)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x3150E35B (dec: 827384667), parent name: 'CAMERA_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x303DA6A5 (dec: 809346725), parent name: 'CAMERA_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_84fake // hashcode: 0x6D696E67 (dec: 1835626087)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xD17DF0BE (dec: -780275522), parent name: 'CAMERA_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xC7396CD7 (dec: -952537897), parent name: 'CAMERA_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xFFF04CB4 (dec: -1028940), parent name: 'CAMERA_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xC89D616A (dec: -929210006), parent name: 'CAMERA_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x5EEDAB1F (dec: 1592634143), parent name: 'CAMERA_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_85fake // hashcode: 0x5ECDB26C (dec: 1590538860)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xA6C9AC37 (dec: -1496732617), parent name: 'CAMERA_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xB9B6D72A (dec: -1179199702), parent name: 'CAMERA_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_86fake // hashcode: 0x639AA797 (dec: 1671079831)
{
	short index;					// size=0, offset=0 //  hashcode: 0xDFAD3E37 (dec: -542294473), parent name: 'CAMERA_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x88507AF8 (dec: -2007991560), parent name: 'CAMERA_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x40DF2119 (dec: 1088364825), parent name: 'CAMERA_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xDF365D77 (dec: -550085257), parent name: 'CAMERA_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_87fake // hashcode: 0x4F8EF7FD (dec: 1334769661)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xCA6FF26A (dec: -898633110), parent name: 'CAMERA_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x5FC84A03 (dec: 1606961667), parent name: 'CAMERA_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x6CBAEE3C (dec: 1824190012), parent name: 'CAMERA_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_88fake // hashcode: 0xBE5591E5 (dec: -1101688347)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x33F0585D (dec: 871389277), parent name: 'CAMERA_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x807FECB9 (dec: -2139099975), parent name: 'CAMERA_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xC7A26748 (dec: -945658040), parent name: 'CAMERA_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xA12F6574 (dec: -1590729356), parent name: 'CAMERA_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x7B0FE6AA (dec: 2064639658), parent name: 'CAMERA_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x3D99D8C1 (dec: 1033492673), parent name: 'CAMERA_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x908744CA (dec: -1870183222), parent name: 'CAMERA_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_89fake // hashcode: 0xF0A28972 (dec: -257783438)
{
	long index;  // size=0, offset=0 //  hashcode: 0x66F865E7 (dec: 1727555047), parent name: 'CAMERA_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xC42C7AB5 (dec: -1003717963), parent name: 'CAMERA_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_90fake // hashcode: 0x828D5090 (dec: -2104668016)
{
	short type; // size=0, offset=0 //  hashcode: 0x9AF871E9 (dec: -1694993943), parent name: 'CAMERA_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xA1534FA8 (dec: -1588375640), parent name: 'CAMERA_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_91fake // hashcode: 0xA9094FC6 (dec: -1459007546)
{
	long time;   // size=0, offset=0 //  hashcode: 0x05980B96 (dec: 93850518), parent name: 'CAMERA_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x1C7C640B (dec: 477914123), parent name: 'CAMERA_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_92fake // hashcode: 0x4DA550A1 (dec: 1302679713)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x8C463486 (dec: -1941556090), parent name: 'CAMERA_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xCED38581 (dec: -824998527), parent name: 'CAMERA_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_93fake // hashcode: 0x4F615850 (dec: 1331779664)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x3D7796B9 (dec: 1031247545), parent name: 'CAMERA_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x9B2C5138 (dec: -1691594440), parent name: 'CAMERA_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_94fake // hashcode: 0xE77D1976 (dec: -411231882)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x4BE7860B (dec: 1273464331), parent name: 'CAMERA_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xDCD552A0 (dec: -589999456), parent name: 'CAMERA_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_95fake // hashcode: 0xD87CD696 (dec: -662907242)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x7F86905E (dec: 2139525214), parent name: 'CAMERA_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xAE11A2DB (dec: -1374575909), parent name: 'CAMERA_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x483506E9 (dec: 1211434729), parent name: 'CAMERA_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x72CC41DD (dec: 1925988829), parent name: 'CAMERA_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_96fake // hashcode: 0xE96CEA16 (dec: -378738154)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xBE2A4ECE (dec: -1104523570), parent name: 'CAMERA_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x992B5A39 (dec: -1725212103), parent name: 'CAMERA_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xD72BDF8F (dec: -684990577), parent name: 'CAMERA_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x1CEAE57B (dec: 485156219), parent name: 'CAMERA_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xDE42D166 (dec: -566046362), parent name: 'CAMERA_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union CAMERA_97fake // Hashcode: 0xC2E2DEB5 (dec: -1025319243)
{
	struct CAMERA_74fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	  // size=24, offset=0
	struct CAMERA_75fake teleport;	 // size=16, offset=0
	struct CAMERA_76fake cameraValue;  // size=8, offset=0
	struct CAMERA_77fake miscValue;	// size=8, offset=0
	struct CAMERA_78fake logicValue;   // size=8, offset=0
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
	struct CAMERA_79fake cameraShake;  // size=8, offset=0
	long cameraSave;				   // size=0, offset=0
	long cameraRestore;				   // size=0, offset=0
	struct _BGObject *bgObject;		   // size=24, offset=0
	long value[2];					   // size=8, offset=0
	struct CAMERA_80fake sound;		   // size=12, offset=0
	void *intro;					   // size=0, offset=0
	long deathZ;					   // size=0, offset=0
	struct CAMERA_81fake dsignal;	  // size=8, offset=0
	void *mirror;					   // size=0, offset=0
	long fogNear;					   // size=0, offset=0
	long fogFar;					   // size=0, offset=0
	struct CAMERA_82fake gotoFrame;	// size=8, offset=0
	struct CAMERA_83fake changeModel;  // size=8, offset=0
	void *vmObject;					   // size=0, offset=0
	struct CAMERA_84fake logic;		   // size=8, offset=0
	void *callSignal;				   // size=0, offset=0
	struct _SVector offset;			   // size=8, offset=0
	struct Signal *gotoLabel;		   // size=0, offset=0
	struct Signal *gosubLabel;		   // size=0, offset=0
	struct CAMERA_85fake control;	  // size=8, offset=0
	struct CAMERA_86fake zSignal;	  // size=12, offset=0
	struct CAMERA_87fake StreamLevel;  // size=24, offset=0
	struct CAMERA_88fake shards;	   // size=12, offset=0
	struct CAMERA_89fake cameraSpline; // size=8, offset=0
	struct CAMERA_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;				   // size=0, offset=0
	struct CAMERA_91fake introFX;	  // size=8, offset=0
	struct CAMERA_92fake introActive;  // size=8, offset=0
	struct CAMERA_93fake levelChange;  // size=18, offset=0
	long blendStart;				   // size=0, offset=0
	struct CAMERA_94fake setTimes;	 // size=8, offset=0
	struct CAMERA_95fake color;		   // size=4, offset=0
	struct CAMERA_96fake print;		   // size=12, offset=0
	long slideAngle;				   // size=0, offset=0
};

union CAMERA_98fake // Hashcode: 0x4101CD9B (dec: 1090637211)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union CAMERA_103fake // Hashcode: 0xF7FDA182 (dec: -134372990)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct CAMERA_105fake // hashcode: 0x4EFE3B00 (dec: 1325284096)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x9D18C50F (dec: -1659321073), parent name: 'CAMERA_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xDABAC296 (dec: -625294698), parent name: 'CAMERA_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x4AA9EAD3 (dec: 1252649683), parent name: 'CAMERA_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x773D6EA3 (dec: 2000514723), parent name: 'CAMERA_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x390BE4F6 (dec: 957080822), parent name: 'CAMERA_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x22D8EF77 (dec: 584642423), parent name: 'CAMERA_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x7E683D5D (dec: 2120760669), parent name: 'CAMERA_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_106fake // hashcode: 0xF2C4C29D (dec: -221986147)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x86C4137A (dec: -2033970310), parent name: 'CAMERA_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x0B5F12D4 (dec: 190780116), parent name: 'CAMERA_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x37201FBC (dec: 924852156), parent name: 'CAMERA_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_107fake // hashcode: 0x7F6CCE95 (dec: 2137837205)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xD7741DE6 (dec: -680256026), parent name: 'CAMERA_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x2498DBC5 (dec: 613997509), parent name: 'CAMERA_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x50DE3156 (dec: 1356738902), parent name: 'CAMERA_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xDB542124 (dec: -615243484), parent name: 'CAMERA_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x2544A22B (dec: 625254955), parent name: 'CAMERA_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_108fake // hashcode: 0x06C47ACD (dec: 113539789)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x8D477F22 (dec: -1924694238), parent name: 'CAMERA_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x7B839919 (dec: 2072221977), parent name: 'CAMERA_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0xB26BBC35 (dec: -1301562315), parent name: 'CAMERA_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x55F3E354 (dec: 1442046804), parent name: 'CAMERA_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x0D093280 (dec: 218706560), parent name: 'CAMERA_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_109fake // hashcode: 0xE68807D6 (dec: -427292714)
{
	struct CAMERA_105fake Cinematic; // size=28, offset=0 //  hashcode: 0x34F12C12 (dec: 888220690), parent name: 'CAMERA_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CAMERA_106fake Idle;		 // size=20, offset=28 //  hashcode: 0xBCD02102 (dec: -1127210750), parent name: 'CAMERA_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CAMERA_107fake Behind;	// size=28, offset=48 //  hashcode: 0x5017C0E3 (dec: 1343733987), parent name: 'CAMERA_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CAMERA_108fake Follow;	// size=20, offset=76 //  hashcode: 0x4E375B63 (dec: 1312250723), parent name: 'CAMERA_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CameraCollisionInfo // hashcode: 0x76C89E59 (dec: 1992859225)
{
	struct _TFace(*tfaceList[5]);	  // size=20, offset=0 //  hashcode: 0x74EE6417 (dec: 1961780247), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Terrain(*tfaceTerrain[5]); // size=20, offset=20 //  hashcode: 0x492EAC0A (dec: 1227795466), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short bspTree[6];				   // size=12, offset=40 //  hashcode: 0xB68473C2 (dec: -1232833598), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lengthList[6];			   // size=12, offset=52 //  hashcode: 0xEAE61A2C (dec: -354018772), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;						   // size=0, offset=64 //  hashcode: 0xD5EC9DDE (dec: -705913378), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long line;						   // size=0, offset=68 //  hashcode: 0xCA7C5922 (dec: -897820382), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numCollided;				   // size=0, offset=72 //  hashcode: 0xCCECB82E (dec: -856901586), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long lenCenterToExtend;			   // size=0, offset=76 //  hashcode: 0xA581EBAC (dec: -1518212180), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Sphere *start;			   // size=12, offset=80 //  hashcode: 0xFA552EA4 (dec: -95080796), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Sphere *end;			   // size=12, offset=84 //  hashcode: 0x12735630 (dec: 309548592), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long cldLines;					   // size=0, offset=88 //  hashcode: 0x69BEB3C1 (dec: 1774105537), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union CAMERA_206fake // Hashcode: 0x6CD0C7C3 (dec: 1825621955)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct CAMERA_229fake // hashcode: 0xC239AD60 (dec: -1036407456)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0xC993972B (dec: -913074389), parent name: 'CAMERA_229fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x8F191584 (dec: -1894181500), parent name: 'CAMERA_229fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CAMERA_230fake // hashcode: 0xD392F032 (dec: -745344974)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x86AA34FC (dec: -2035665668), parent name: 'CAMERA_230fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x25517BB2 (dec: 626097074), parent name: 'CAMERA_230fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x45BD3770 (dec: 1170028400), parent name: 'CAMERA_230fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x53421705 (dec: 1396840197), parent name: 'CAMERA_230fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x7CF83585 (dec: 2096641413), parent name: 'CAMERA_230fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0xEB400062 (dec: -348127134), parent name: 'CAMERA_230fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union CAMERA_231fake // Hashcode: 0xC9CF5889 (dec: -909158263)
{
	struct CAMERA_229fake flame; // size=8, offset=0
	struct CAMERA_230fake phys;  // size=12, offset=0
};

typedef struct CameraCollisionInfo CameraCollisionInfo;

extern void CAMERA_CalculateViewVolumeNormals(struct Camera *camera); // 0x800146E8

extern void CAMERA_CalcVVClipInfo(struct Camera *camera); // 0x80014A24

extern void CAMERA_SetViewVolume(struct Camera *camera); // 0x80014B44

extern void CAMERA_SetProjDistance(struct Camera *camera, long distance); // 0x80014B70

extern void CAMERA_CreateNewFocuspoint(struct Camera *camera); // 0x80014C14

extern void CAMERA_SaveMode(struct Camera *camera, long mode); // 0x80014CB8

extern void CAMERA_RestoreMode(struct Camera *camera); // 0x80014FF0

extern void CAMERA_Save(struct Camera *camera, long save); // 0x80015498

extern void CAMERA_Restore(struct Camera *camera, long restore); // 0x80015568

extern struct _SVector *SplineGetNextPointDC(struct Spline *spline, struct SplineDef *def); // 0x80015624

extern void CAMERA_SetMode(struct Camera *camera, long mode); // 0x80015680

extern void CAMERA_Initialize(struct Camera *camera); // 0x80015B30

extern void CAMERA_SetInstanceFocus(struct Camera *camera, struct _Instance *instance); // 0x80015E30

extern void CAMERA_SetZRotation(struct Camera *camera, short zrot); // 0x80015E90

extern long CAMERA_LengthSVector(struct _SVector *sv); // 0x80015EB4

extern void CAMERA_SetValue(struct Camera *camera, long index, long value); // 0x80015F08

extern short CAMERA_AngleDifference(short angle0, short angle1); // 0x80016334

extern short CAMERA_SignedAngleDifference(short angle0, short angle1); // 0x800163AC

extern unsigned long CAMERA_QueryMode(struct Camera *camera); // 0x800163DC

extern void CAMERA_SetMaxVel(struct Camera *camera); // 0x80016478

extern void CAMERA_SetTarget(struct Camera *camera, struct _Position *pos); // 0x80016584

extern void CAMERA_CalcPosition(struct _Position *position, struct _Position *base, struct _Rotation *rotation, short distance); // 0x80016600

extern void CAMERA_SetFocus(struct Camera *camera, struct _Position *targetfocusPoint); // 0x80016728

extern void CAMERA_Lock(struct Camera *camera, long lock); // 0x800169A4

extern void CAMERA_Unlock(struct Camera *camera, long unlock); // 0x800169B8

extern void CAMERA_SetSmoothValue(struct Camera *camera, long smooth); // 0x800169CC

extern void CAMERA_SetTimer(struct Camera *camera, long time); // 0x80016A1C

extern void CAMERA_Adjust_tilt(struct Camera *camera, long tilt); // 0x80016A3C

extern void CAMERA_Adjust_distance(struct Camera *camera, long dist); // 0x80016A78

extern void CAMERA_Adjust_rotation(struct Camera *camera, long rotation); // 0x80016AF4

extern void CAMERA_Adjust_roll(long roll_degrees, int frames); // 0x80016B78

extern void CAMERA_Adjust(struct Camera *camera, long adjust); // 0x80016BFC

extern void CAMERA_ChangeTo(struct Camera *camera, struct _CameraKey *cameraKey); // 0x80016CBC

extern void CAMERA_SetShake(struct Camera *camera, long shake, long scale); // 0x80016CC4

extern void Decouple_AngleMoveToward(short *current_ptr, short destination, short step); // 0x80016D74

extern void CriticalDampValue(long dampMode, short *sourceVal, short targetVal, short *vel, short *accl, int smooth); // 0x80016DC4

extern void CriticalDampPosition(long dampMode, struct _Position *position, struct _Position *targetPos, struct _SVector *vel, struct _SVector *accl, int smooth); // 0x80016F78

extern void CriticalDampAngle(long dampMode, short *currentVal, short target, short *vel, short *accl, int smooth); // 0x8001763C

extern short CAMERA_CalcZRotation(struct _Position *target, struct _Position *position); // 0x800176DC

extern void CAMERA_CalcRotation(struct _Rotation *rotation, struct _Position *target, struct _Position *position); // 0x80017754

extern void CAMERA_CalcFSRotation(struct Camera *camera, struct _Rotation *rotation, struct _Position *target, struct _Position *position); // 0x800177F0

extern void CAMERA_Relocate(struct Camera *camera, struct _SVector *offset, int streamSignalFlag); // 0x8001789C

extern struct _TFace *CAMERA_SphereToSphereWithLines(struct Camera *camera, struct CameraCollisionInfo *colInfo, int secondcheck_flag); // 0x800179E8

extern long CAMERA_CalcTilt(struct _Normal *normal, short zRot); // 0x80018524

extern void CAMERA_SetLookFocusAndBase(struct _Instance *focusInstance, struct _Position *focusPoint); // 0x80018598

extern void CAMERA_SetLookFocusAndDistance(struct Camera *camera, struct VECTOR *focuspoint, int distance); // 0x800185E0

extern void CAMERA_LookProcess(struct Camera *camera); // 0x80018608

extern void CAMERA_Normalize(struct _SVector *svector); // 0x8001885C

extern void CAMERA_HandleTransitions(struct Camera *camera); // 0x800188D4

extern void CAMERA_CalcFocusOffset(struct _SVector *offset, struct Camera *camera); // 0x80018A88

extern void CAMERA_CalcFocusOffsetForSwim(struct _SVector *offset, struct Camera *camera); // 0x80018B3C

extern short CAMERA_CalcIntersectAngle(struct _SVector *linept, struct _SVector *vertex0, struct _SVector *vertex1, short *high, short *low); // 0x80018BA8

extern short CAMERA_GetLineAngle(struct Camera *camera, struct CameraCollisionInfo *colInfo, struct _SVector *linept, int line); // 0x80018C98

extern long CAMERA_ACForcedMovement(struct Camera *camera, struct CameraCollisionInfo *colInfo); // 0x80018E60

extern void CAMERA_update_dist_debounced(struct Camera *camera, short dist); // 0x80018F30

extern short CAMERA_dampgetline(short angle); // 0x80018FA0

extern long CAMERA_ACNoForcedMovement(struct Camera *camera, struct CameraCollisionInfo *colInfo); // 0x8001904C

extern long CAMERA_AbsoluteCollision(struct Camera *camera, struct CameraCollisionInfo *colInfo); // 0x80019550

extern short CAMERA_update_z_damped(struct Camera *camera, short current, short target); // 0x80019678

extern void CAMERA_CombatCamDist(struct Camera *camera); // 0x800198E8

extern void CAMERA_GenericCameraProcess(struct Camera *camera); // 0x80019BAC

extern void CAMERA_CinematicProcess(struct Camera *camera); // 0x8001A028

extern int CAMERA_GetDistSq(struct _SVector *point1, struct _SVector *point2); // 0x8001A544

extern void CAMERA_NearestPointOnLineVec(struct _SVector *linePoint, struct _SVector *start, struct _SVector *line, struct _Position *point); // 0x8001A5C0

extern int CAMERA_CheckPoint(int linePoint, int linept1, int linept2); // 0x8001A6EC

extern int CAMERA_CheckIfPointOnLine(struct _SVector *linePoint, struct _SVector *linept1, struct _SVector *linept2); // 0x8001A730

extern int CAMERA_FindLinePoint(struct _Position *point, struct _SVector *linept1, struct _SVector *linept2, int target_dist_sq, struct _SVector *results); // 0x8001A7C0

extern void CAMERA_SplineGetNearestPoint2(struct Camera *camera, struct Spline *spline, struct _SVector *point, int *currkey, struct _SVector *ret_dpoint); // 0x8001A984

extern void CAMERA_SplineGetNearestPoint(struct Spline *spline, struct _SVector *point, int *currkey, struct _SVector *ret_dpoint); // 0x8001AB6C

extern void CAMERA_SplineHelpMove(struct Camera *camera); // 0x8001AF04

extern void CAMERA_SplineProcess(struct Camera *camera); // 0x8001B074

extern void CAMERA_ShakeCamera(struct Camera *camera); // 0x8001B3C8

extern void CAMERA_Process(struct Camera *camera); // 0x8001B4B0

extern void CAMERA_CenterCamera(struct Camera *camera); // 0x8001B6FC

extern void CAMERA_SetLookRot(struct Camera *camera, int x_rotation, int z_rotation); // 0x8001B7E4

extern void CAMERA_StartLookaroundMode(struct Camera *camera); // 0x8001B7F0

extern void CAMERA_StartSwimThrowMode(struct Camera *camera); // 0x8001B880

extern void CAMERA_EndSwimThrowMode(struct Camera *camera); // 0x8001B8C0

extern void CAMERA_ForceEndLookaroundMode(struct Camera *camera); // 0x8001B8E4

extern void CAMERA_Control(struct Camera *camera, struct _Instance *playerInstance); // 0x8001B920

extern void CAMERA_EndLook(struct Camera *camera); // 0x8001BE68

extern void CAMERA_ChangeToUnderWater(struct Camera *camera, struct _Instance *instance); // 0x8001BF5C

extern void CAMERA_ChangeToOutOfWater(struct Camera *camera, struct _Instance *instance); // 0x8001C008

extern void CAMERA_UpdateFocusDistance(struct Camera *camera); // 0x8001C07C

extern void CAMERA_UpdateFocusTilt(struct Camera *camera); // 0x8001C14C

extern void CAMERA_UpdateFocusRoll(struct Camera *camera); // 0x8001C218

extern void CAMERA_UpdateFocusRotate(struct Camera *camera); // 0x8001C334

extern void CAMERA_UpdateFocusRotationX(struct Camera *camera, struct _Instance *focusInstance); // 0x8001C420

extern void CAMERA_FollowPlayerTilt(struct Camera *camera, struct _Instance *focusInstance); // 0x8001C6A0

extern void CAMERA_FollowGoBehindPlayerWithTimer(struct Camera *camera); // 0x8001C8B0

extern void CAMERA_FollowGoBehindPlayer(struct Camera *camera); // 0x8001C9AC

extern void CAMERA_CalculateLead(struct Camera *camera); // 0x8001C9E8

extern void CAMERA_CalcFollowPosition(struct Camera *camera, struct _Rotation *rotation); // 0x8001CB90

extern void CAMERA_SetupColInfo(struct Camera *camera, struct CameraCollisionInfo *colInfo, struct _Position *targetCamPos); // 0x8001CE8C

extern void CAMERA_DoPanicCheck(struct Camera *camera, struct CameraCollisionInfo *tmpcolInfo, struct _Rotation *rotation, short *best_z, short *max_dist); // 0x8001CF4C

extern void CAMERA_Panic(struct Camera *camera, short min_dist); // 0x8001D01C

extern long CAMERA_DoCameraCollision2(struct Camera *camera, struct _Position *targetCamPos, int simpleflag); // 0x8001D1CC

extern int CAMERA_FocusInstanceMoved(struct Camera *camera); // 0x8001D7D0

#endif
