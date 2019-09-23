#ifndef INSTANCE_H
#define INSTANCE_H

struct _G2EulerAngles_Type // hashcode: 0xB3709AC5 (dec: -1284465979)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x95F20D13 (dec: -1779299053), parent name: '_G2EulerAngles_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x9118431F (dec: -1860680929), parent name: '_G2EulerAngles_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;	 // size=0, offset=4 //  hashcode: 0x13F1660C (dec: 334587404), parent name: '_G2EulerAngles_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short order; // size=0, offset=6 //  hashcode: 0x5DF97F2A (dec: 1576632106), parent name: '_G2EulerAngles_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

enum _G2AnimCallbackMsg_Enum // Hashcode: 0xA8F4A89C (dec: -1460361060)
{
	G2ANIM_MSG_DONE = 1,
	G2ANIM_MSG_LOOPPOINT = 2,
	G2ANIM_MSG_SECTION_INTERPDONE = 3,
	G2ANIM_MSG_SEGCTRLR_INTERPDONE = 4,
	G2ANIM_MSG_SWALARMSET = 5,
	G2ANIM_MSG_PLAYEFFECT = 6,
};

struct INSTANCE_73fake // hashcode: 0xA257EA48 (dec: -1571296696)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x44B00D3F (dec: 1152388415), parent name: 'INSTANCE_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x003787A6 (dec: 3639206), parent name: 'INSTANCE_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_74fake // hashcode: 0x3B6C6FAE (dec: 996962222)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x9B8C5FD5 (dec: -1685299243), parent name: 'INSTANCE_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x5103076F (dec: 1359153007), parent name: 'INSTANCE_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_75fake // hashcode: 0x6A7CA87D (dec: 1786554493)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x43CF3B63 (dec: 1137654627), parent name: 'INSTANCE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xFF1E131A (dec: -14806246), parent name: 'INSTANCE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union INSTANCE_76fake // Hashcode: 0x868EC9CC (dec: -2037462580)
{
	struct INSTANCE_73fake callback; // size=8, offset=0
	struct INSTANCE_74fake vector;   // size=12, offset=0
	struct INSTANCE_75fake quat;	 // size=16, offset=0
};

union INSTANCE_77fake // Hashcode: 0x2031C6D4 (dec: 540133076)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union INSTANCE_78fake // Hashcode: 0x09FECA95 (dec: 167692949)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct INSTANCE_79fake // hashcode: 0xB0EDB28F (dec: -1326599537)
{
	union INSTANCE_78fake size; // size=4, offset=0 //  hashcode: 0xD09C324F (dec: -795069873), parent name: 'INSTANCE_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_80fake // hashcode: 0x208DA64D (dec: 546154061)
{
	short x;				// size=0, offset=0 //  hashcode: 0x8A6F013D (dec: -1972436675), parent name: 'INSTANCE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x832FE355 (dec: -2094013611), parent name: 'INSTANCE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xC53E6065 (dec: -985767835), parent name: 'INSTANCE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x861E6029 (dec: -2044829655), parent name: 'INSTANCE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xE0C0976E (dec: -524249234), parent name: 'INSTANCE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_81fake // hashcode: 0xA76ED81E (dec: -1485907938)
{
	long index; // size=0, offset=0 //  hashcode: 0xEDF777E2 (dec: -302549022), parent name: 'INSTANCE_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x792DCFDA (dec: 2033045466), parent name: 'INSTANCE_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_82fake // hashcode: 0xB322D127 (dec: -1289563865)
{
	long index; // size=0, offset=0 //  hashcode: 0xDAFAF40F (dec: -621087729), parent name: 'INSTANCE_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x41A5AF60 (dec: 1101377376), parent name: 'INSTANCE_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_83fake // hashcode: 0x39D3D53F (dec: 970183999)
{
	long index; // size=0, offset=0 //  hashcode: 0xC3E6B995 (dec: -1008289387), parent name: 'INSTANCE_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x1BF0A75E (dec: 468756318), parent name: 'INSTANCE_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_84fake // hashcode: 0x7827404A (dec: 2015838282)
{
	long time;  // size=0, offset=0 //  hashcode: 0xD2466300 (dec: -767139072), parent name: 'INSTANCE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xD617BE0B (dec: -703087093), parent name: 'INSTANCE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_85fake // hashcode: 0x4EA8380B (dec: 1319647243)
{
	long action;   // size=0, offset=0 //  hashcode: 0x65BC0781 (dec: 1706821505), parent name: 'INSTANCE_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x13151384 (dec: 320148356), parent name: 'INSTANCE_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_86fake // hashcode: 0x67FBDB65 (dec: 1744558949)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x9C7B3DD7 (dec: -1669644841), parent name: 'INSTANCE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x2A623D59 (dec: 711081305), parent name: 'INSTANCE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_87fake // hashcode: 0x526328A7 (dec: 1382230183)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x84BBFB5F (dec: -2068055201), parent name: 'INSTANCE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x4D56F442 (dec: 1297544258), parent name: 'INSTANCE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_88fake // hashcode: 0x3B757554 (dec: 997553492)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x5C88AD89 (dec: 1552461193), parent name: 'INSTANCE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xDF5F438D (dec: -547404915), parent name: 'INSTANCE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_89fake // hashcode: 0x136E617E (dec: 326001022)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xA57B1A21 (dec: -1518659039), parent name: 'INSTANCE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x184CED04 (dec: 407694596), parent name: 'INSTANCE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xB1989CE2 (dec: -1315398430), parent name: 'INSTANCE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x100740B5 (dec: 268910773), parent name: 'INSTANCE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x1A0C9736 (dec: 437032758), parent name: 'INSTANCE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_90fake // hashcode: 0x7E1B6DBF (dec: 2115726783)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xBF739173 (dec: -1082945165), parent name: 'INSTANCE_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x5CB5BD97 (dec: 1555414423), parent name: 'INSTANCE_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_91fake // hashcode: 0x90ECB9F0 (dec: -1863534096)
{
	short index;					// size=0, offset=0 //  hashcode: 0x0662905F (dec: 107122783), parent name: 'INSTANCE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xC85A45D6 (dec: -933607978), parent name: 'INSTANCE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x03DD1274 (dec: 64819828), parent name: 'INSTANCE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xE906D0A5 (dec: -385429339), parent name: 'INSTANCE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_92fake // hashcode: 0x6D63FFC1 (dec: 1835270081)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xA2C6D120 (dec: -1564028640), parent name: 'INSTANCE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xC1118449 (dec: -1055816631), parent name: 'INSTANCE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x40538B43 (dec: 1079216963), parent name: 'INSTANCE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_93fake // hashcode: 0x3225C7B3 (dec: 841336755)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x70CBAD56 (dec: 1892396374), parent name: 'INSTANCE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x14905C94 (dec: 345005204), parent name: 'INSTANCE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xAEB4CE2B (dec: -1363882453), parent name: 'INSTANCE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xDA1F582E (dec: -635480018), parent name: 'INSTANCE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x285137E0 (dec: 676411360), parent name: 'INSTANCE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x4BDA69B7 (dec: 1272605111), parent name: 'INSTANCE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x1A85F0B3 (dec: 444985523), parent name: 'INSTANCE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_94fake // hashcode: 0x4E02C423 (dec: 1308804131)
{
	long index;  // size=0, offset=0 //  hashcode: 0x1BBA5088 (dec: 465195144), parent name: 'INSTANCE_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x47EC56E7 (dec: 1206671079), parent name: 'INSTANCE_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_95fake // hashcode: 0x7CD95315 (dec: 2094617365)
{
	short type; // size=0, offset=0 //  hashcode: 0xEA426EDC (dec: -364744996), parent name: 'INSTANCE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xD6EA642E (dec: -689282002), parent name: 'INSTANCE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_96fake // hashcode: 0xF167C45E (dec: -244857762)
{
	long time;   // size=0, offset=0 //  hashcode: 0x628A9A7C (dec: 1653250684), parent name: 'INSTANCE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xD33065F3 (dec: -751802893), parent name: 'INSTANCE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_97fake // hashcode: 0x22DF25FB (dec: 585049595)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xB3F1C735 (dec: -1276000459), parent name: 'INSTANCE_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x145D435F (dec: 341656415), parent name: 'INSTANCE_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_98fake // hashcode: 0x2E04C211 (dec: 772063761)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xC5A53D71 (dec: -979026575), parent name: 'INSTANCE_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xA5CF6BEA (dec: -1513133078), parent name: 'INSTANCE_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_99fake // hashcode: 0x72A46AB0 (dec: 1923377840)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x2D96FD5F (dec: 764869983), parent name: 'INSTANCE_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xA33DCA55 (dec: -1556231595), parent name: 'INSTANCE_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_100fake // hashcode: 0xE6FAAFAC (dec: -419778644)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x9E8730C3 (dec: -1635307325), parent name: 'INSTANCE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xA131EB21 (dec: -1590564063), parent name: 'INSTANCE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xE2D5E16C (dec: -489299604), parent name: 'INSTANCE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x5DA72DB6 (dec: 1571237302), parent name: 'INSTANCE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_101fake // hashcode: 0x8556E4D9 (dec: -2057902887)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xFF88F17A (dec: -7802502), parent name: 'INSTANCE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x1DC7B852 (dec: 499628114), parent name: 'INSTANCE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x9E8F8DF7 (dec: -1634759177), parent name: 'INSTANCE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xA19580F9 (dec: -1584037639), parent name: 'INSTANCE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xDF60BC11 (dec: -547308527), parent name: 'INSTANCE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union INSTANCE_102fake // Hashcode: 0x23185CF5 (dec: 588799221)
{
	struct INSTANCE_79fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;		 // size=24, offset=0
	struct INSTANCE_80fake teleport;	 // size=16, offset=0
	struct INSTANCE_81fake cameraValue;  // size=8, offset=0
	struct INSTANCE_82fake miscValue;	// size=8, offset=0
	struct INSTANCE_83fake logicValue;   // size=8, offset=0
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
	struct INSTANCE_84fake cameraShake;  // size=8, offset=0
	long cameraSave;					 // size=0, offset=0
	long cameraRestore;					 // size=0, offset=0
	struct _BGObject *bgObject;			 // size=24, offset=0
	long value[2];						 // size=8, offset=0
	struct INSTANCE_85fake sound;		 // size=12, offset=0
	void *intro;						 // size=0, offset=0
	long deathZ;						 // size=0, offset=0
	struct INSTANCE_86fake dsignal;		 // size=8, offset=0
	void *mirror;						 // size=0, offset=0
	long fogNear;						 // size=0, offset=0
	long fogFar;						 // size=0, offset=0
	struct INSTANCE_87fake gotoFrame;	// size=8, offset=0
	struct INSTANCE_88fake changeModel;  // size=8, offset=0
	void *vmObject;						 // size=0, offset=0
	struct INSTANCE_89fake logic;		 // size=8, offset=0
	void *callSignal;					 // size=0, offset=0
	struct _SVector offset;				 // size=8, offset=0
	struct Signal *gotoLabel;			 // size=0, offset=0
	struct Signal *gosubLabel;			 // size=0, offset=0
	struct INSTANCE_90fake control;		 // size=8, offset=0
	struct INSTANCE_91fake zSignal;		 // size=12, offset=0
	struct INSTANCE_92fake StreamLevel;  // size=24, offset=0
	struct INSTANCE_93fake shards;		 // size=12, offset=0
	struct INSTANCE_94fake cameraSpline; // size=8, offset=0
	struct INSTANCE_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;					 // size=0, offset=0
	struct INSTANCE_96fake introFX;		 // size=8, offset=0
	struct INSTANCE_97fake introActive;  // size=8, offset=0
	struct INSTANCE_98fake levelChange;  // size=18, offset=0
	long blendStart;					 // size=0, offset=0
	struct INSTANCE_99fake setTimes;	 // size=8, offset=0
	struct INSTANCE_100fake color;		 // size=4, offset=0
	struct INSTANCE_101fake print;		 // size=12, offset=0
	long slideAngle;					 // size=0, offset=0
};

union INSTANCE_103fake // Hashcode: 0x7C82B3A3 (dec: 2088940451)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

struct _AnimSoundData_Type // hashcode: 0x5367FF66 (dec: 1399324518)
{
	short sfxToneID;	  // size=0, offset=0 //  hashcode: 0x268BC670 (dec: 646694512), parent name: '_AnimSoundData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short volume;		  // size=0, offset=2 //  hashcode: 0x43A9B4B2 (dec: 1135195314), parent name: '_AnimSoundData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitch;		  // size=0, offset=4 //  hashcode: 0x63C904E4 (dec: 1674118372), parent name: '_AnimSoundData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minVolDistance; // size=0, offset=6 //  hashcode: 0x07E159DE (dec: 132209118), parent name: '_AnimSoundData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _InstanceHandle // hashcode: 0xDC7D3685 (dec: -595773819)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0xC46068C7 (dec: -1000314681), parent name: '_InstanceHandle', parent hashcode: 0xFFFFFFFF (dec: -1)
	long instanceID;			// size=0, offset=4 //  hashcode: 0xBB947E30 (dec: -1147896272), parent name: '_InstanceHandle', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union INSTANCE_108fake // Hashcode: 0x4226D69F (dec: 1109841567)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct INSTANCE_110fake // hashcode: 0x4D2D9CAD (dec: 1294834861)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xBEBFED90 (dec: -1094718064), parent name: 'INSTANCE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x7589BF9C (dec: 1971961756), parent name: 'INSTANCE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x76A65F9B (dec: 1990614939), parent name: 'INSTANCE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x6729608A (dec: 1730764938), parent name: 'INSTANCE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x7FDB1665 (dec: 2145064549), parent name: 'INSTANCE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x360F9103 (dec: 906989827), parent name: 'INSTANCE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xA61EF604 (dec: -1507920380), parent name: 'INSTANCE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_111fake // hashcode: 0x50938616 (dec: 1351845398)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x187E0EFD (dec: 410914557), parent name: 'INSTANCE_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x8BE2329D (dec: -1948110179), parent name: 'INSTANCE_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x68752EA2 (dec: 1752510114), parent name: 'INSTANCE_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_112fake // hashcode: 0x85CCCAAE (dec: -2050176338)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x0837B36A (dec: 137868138), parent name: 'INSTANCE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x57D3F3A8 (dec: 1473508264), parent name: 'INSTANCE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x3591E690 (dec: 898754192), parent name: 'INSTANCE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xF4CD7917 (dec: -187860713), parent name: 'INSTANCE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x42A30101 (dec: 1117978881), parent name: 'INSTANCE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_113fake // hashcode: 0xCFF720B0 (dec: -805887824)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x0D37E33B (dec: 221766459), parent name: 'INSTANCE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0xF83D79A5 (dec: -130188891), parent name: 'INSTANCE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x346C4FF9 (dec: 879513593), parent name: 'INSTANCE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xE159D165 (dec: -514207387), parent name: 'INSTANCE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x052DB7DF (dec: 86882271), parent name: 'INSTANCE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_114fake // hashcode: 0xEC292DCB (dec: -332845621)
{
	struct INSTANCE_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x2958E561 (dec: 693691745), parent name: 'INSTANCE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct INSTANCE_111fake Idle;	  // size=20, offset=28 //  hashcode: 0xCCB0D9E8 (dec: -860825112), parent name: 'INSTANCE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct INSTANCE_112fake Behind;	// size=28, offset=48 //  hashcode: 0x90FDEA26 (dec: -1862407642), parent name: 'INSTANCE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct INSTANCE_113fake Follow;	// size=20, offset=76 //  hashcode: 0x1C098ECE (dec: 470388430), parent name: 'INSTANCE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_176fake // hashcode: 0x9BA24315 (dec: -1683864811)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x1EA2C169 (dec: 513982825), parent name: 'INSTANCE_176fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x1D3E7BFB (dec: 490634235), parent name: 'INSTANCE_176fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_177fake // hashcode: 0x5D75B1F5 (dec: 1567994357)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x2EA80001 (dec: 782761985), parent name: 'INSTANCE_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0xE0525DB3 (dec: -531472973), parent name: 'INSTANCE_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x39572F3D (dec: 962015037), parent name: 'INSTANCE_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x2EF38414 (dec: 787710996), parent name: 'INSTANCE_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x2B703664 (dec: 728774244), parent name: 'INSTANCE_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x43E3AF11 (dec: 1138994961), parent name: 'INSTANCE_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union INSTANCE_178fake // Hashcode: 0xC480AFF2 (dec: -998199310)
{
	struct INSTANCE_176fake flame; // size=8, offset=0
	struct INSTANCE_177fake phys;  // size=12, offset=0
};

struct evCollideInstanceStatsData // hashcode: 0xD8198216 (dec: -669416938)
{
	struct _Instance *instance;		  // size=616, offset=0 //  hashcode: 0x47B4DB2E (dec: 1203034926), parent name: 'evCollideInstanceStatsData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long distance;			  // size=0, offset=4 //  hashcode: 0xDC244C48 (dec: -601600952), parent name: 'evCollideInstanceStatsData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector relativePosition; // size=8, offset=8 //  hashcode: 0xB119B40E (dec: -1323715570), parent name: 'evCollideInstanceStatsData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long xyDistance;				  // size=0, offset=16 //  hashcode: 0x2F299ABA (dec: 791255738), parent name: 'evCollideInstanceStatsData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long zDelta;					  // size=0, offset=20 //  hashcode: 0x76615985 (dec: 1986091397), parent name: 'evCollideInstanceStatsData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union INSTANCE_204fake // Hashcode: 0x3FD2E4BE (dec: 1070785726)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct INICommand // hashcode: 0x04B02DE1 (dec: 78654945)
{
	short command;		 // size=0, offset=0 //  hashcode: 0x4CE52546 (dec: 1290085702), parent name: 'INICommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numParameters; // size=0, offset=2 //  hashcode: 0x79915334 (dec: 2039567156), parent name: 'INICommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	long parameter[0];   // size=0, offset=4 //  hashcode: 0x229D9C16 (dec: 580754454), parent name: 'INICommand', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SavedIntroSmall // hashcode: 0x42C7682C (dec: 1120364588)
{
	unsigned char savedID;		   // size=0, offset=0 //  hashcode: 0x20E2A9C7 (dec: 551725511), parent name: 'SavedIntroSmall', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char shiftedSaveSize; // size=0, offset=1 //  hashcode: 0xD068F0A5 (dec: -798429019), parent name: 'SavedIntroSmall', parent hashcode: 0xFFFFFFFF (dec: -1)
	short introUniqueID;		   // size=0, offset=2 //  hashcode: 0x09D334BD (dec: 164836541), parent name: 'SavedIntroSmall', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SavedIntroSpline // hashcode: 0x018B74DF (dec: 25916639)
{
	unsigned char savedID;		   // size=0, offset=0 //  hashcode: 0xCF3EDF4B (dec: -817963189), parent name: 'SavedIntroSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char shiftedSaveSize; // size=0, offset=1 //  hashcode: 0x0F13F035 (dec: 252964917), parent name: 'SavedIntroSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	short introUniqueID;		   // size=0, offset=2 //  hashcode: 0x36BAFD04 (dec: 918224132), parent name: 'SavedIntroSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splineFlags;			   // size=0, offset=4 //  hashcode: 0x4CC5C597 (dec: 1288029591), parent name: 'SavedIntroSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splineKeyFrame;		   // size=0, offset=6 //  hashcode: 0xBD2E0D77 (dec: -1121055369), parent name: 'SavedIntroSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splineClipBeg;		   // size=0, offset=8 //  hashcode: 0x3BCAE3DE (dec: 1003152350), parent name: 'SavedIntroSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splineClipEnd;		   // size=0, offset=10 //  hashcode: 0xF52B2AD1 (dec: -181720367), parent name: 'SavedIntroSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _SavedIntroWithIntro // hashcode: 0xF234DCD6 (dec: -231416618)
{
	unsigned char savedID;				 // size=0, offset=0 //  hashcode: 0x8F1A8F84 (dec: -1894084732), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char shiftedSaveSize;		 // size=0, offset=1 //  hashcode: 0xCE2AEA2D (dec: -836048339), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short attachedUniqueID;	 // size=0, offset=2 //  hashcode: 0xFDA53D9F (dec: -39502433), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short introOffset;					 // size=0, offset=4 //  hashcode: 0x7D65DBFE (dec: 2103827454), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short birthUnitID;					 // size=0, offset=6 //  hashcode: 0xAD70F586 (dec: -1385106042), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short introUniqueID;				 // size=0, offset=8 //  hashcode: 0xB926C30E (dec: -1188642034), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char lightGroup;			 // size=0, offset=10 //  hashcode: 0x5183D0FE (dec: 1367593214), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char specturalLightGroup;   // size=0, offset=11 //  hashcode: 0x332D1993 (dec: 858593683), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;							 // size=0, offset=12 //  hashcode: 0xA64D47CE (dec: -1504884786), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags2;						 // size=0, offset=16 //  hashcode: 0xCC6FA251 (dec: -865099183), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SmallRotation smallRotation; // size=6, offset=20 //  hashcode: 0xC4EE43EF (dec: -991018001), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position;			 // size=6, offset=26 //  hashcode: 0xC4E919F6 (dec: -991356426), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union INSTANCE_270fake // Hashcode: 0xB44B3EBC (dec: -1270137156)
{
	struct Intro *intro;	   // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

union INSTANCE_272fake // Hashcode: 0x1926BDC3 (dec: 421969347)
{
	struct _Instance *instance; // size=616, offset=0
	struct _SFXMkr *sfxMarker;  // size=36, offset=0
};

struct INSTANCE_273fake // hashcode: 0x2B052A30 (dec: 721758768)
{
	long instanceNumber; // size=0, offset=0 //  hashcode: 0x832CF890 (dec: -2094204784), parent name: 'INSTANCE_273fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;		 // size=0, offset=4 //  hashcode: 0xEFA2380A (dec: -274581494), parent name: 'INSTANCE_273fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_274fake // hashcode: 0x2B9954AD (dec: 731468973)
{
	struct _SavedIntro *intro; // size=40, offset=0 //  hashcode: 0x03C5A349 (dec: 63284041), parent name: 'INSTANCE_274fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;			   // size=0, offset=4 //  hashcode: 0x4DB29ED1 (dec: 1303551697), parent name: 'INSTANCE_274fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_275fake // hashcode: 0xA31B1FCD (dec: -1558503475)
{
	long currentNumber; // size=0, offset=0 //  hashcode: 0xE8946ABC (dec: -392926532), parent name: 'INSTANCE_275fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long error;			// size=0, offset=4 //  hashcode: 0xE9FB8342 (dec: -369392830), parent name: 'INSTANCE_275fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;		// size=0, offset=8 //  hashcode: 0x4D510112 (dec: 1297154322), parent name: 'INSTANCE_275fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_276fake // hashcode: 0xADD6A8E0 (dec: -1378440992)
{
	short vx; // size=0, offset=0 //  hashcode: 0x55F514FF (dec: 1442125055), parent name: 'INSTANCE_276fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vy; // size=0, offset=2 //  hashcode: 0xA621AD13 (dec: -1507742445), parent name: 'INSTANCE_276fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_277fake // hashcode: 0x12A8B1F8 (dec: 313045496)
{
	char *pointer; // size=0, offset=0 //  hashcode: 0x70863622 (dec: 1887843874), parent name: 'INSTANCE_277fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_278fake // hashcode: 0x5FFFA728 (dec: 1610589992)
{
	short *pointer; // size=0, offset=0 //  hashcode: 0xC6734CC2 (dec: -965522238), parent name: 'INSTANCE_278fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INSTANCE_279fake // hashcode: 0x48560F36 (dec: 1213599542)
{
	long *pointer; // size=0, offset=0 //  hashcode: 0x8BAC907E (dec: -1951625090), parent name: 'INSTANCE_279fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union INSTANCE_280fake // Hashcode: 0x9EB07B35 (dec: -1632601291)
{
	struct INSTANCE_273fake Object;					  // size=8, offset=0
	struct INSTANCE_274fake SavedIntroObject;		  // size=8, offset=0
	struct InstanceSpline instanceSpline;			  // size=24, offset=0
	struct INSTANCE_275fake Number;					  // size=12, offset=0
	struct INSTANCE_276fake Vector2d;				  // size=4, offset=0
	struct INSTANCE_277fake CharPointer;			  // size=4, offset=0
	struct INSTANCE_278fake ShortPointer;			  // size=4, offset=0
	struct INSTANCE_279fake LongPointer;			  // size=4, offset=0
	struct AreaObject areaObject;					  // size=12, offset=0
	struct InstanceObject instanceObject;			  // size=8, offset=0
	struct Vector3d vector3d;						  // size=20, offset=0
	struct Rotation3d rotation3d;					  // size=20, offset=0
	struct SignalObject signalObject;				  // size=8, offset=0
	struct EventObject eventObject;					  // size=8, offset=0
	struct GameObject gameObject;					  // size=4, offset=0
	struct ListObject listObject;					  // size=32, offset=0
	struct IntroObject introObject;					  // size=8, offset=0
	struct InstanceAnimate instanceAnimate;			  // size=8, offset=0
	struct InstanceAnimateTexture instanceAniTexture; // size=12, offset=0
	struct SavedEventObject savedEventObject;		  // size=16, offset=0
	struct SubListObject subListObject;				  // size=32, offset=0
	struct TGroupObject terrainGroup;				  // size=16, offset=0
	struct ConstrictInfo constrictInfo;				  // size=8, offset=0
	struct CameraObject cameraObject;				  // size=12, offset=0
	struct EventVmObject vmObject;					  // size=12, offset=0
	struct SoundObject soundObject;					  // size=20, offset=0
};

struct _MonsterAnim // hashcode: 0xF5F8CA4B (dec: -168244661)
{
	unsigned short velocity;		  // size=0, offset=0 //  hashcode: 0x4CDB0574 (dec: 1289422196), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short distance;		  // size=0, offset=2 //  hashcode: 0x1E43AADC (dec: 507751132), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short playSpeed;		  // size=0, offset=4 //  hashcode: 0x01DA6C19 (dec: 31091737), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char interpFrames;		  // size=0, offset=6 //  hashcode: 0x60D2D2BE (dec: 1624429246), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char startFrame;		  // size=0, offset=7 //  hashcode: 0x59EC2B56 (dec: 1508649814), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char interpOut;		  // size=0, offset=8 //  hashcode: 0xCBBD0416 (dec: -876805098), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char alphaTable;		  // size=0, offset=9 //  hashcode: 0xB0697BEF (dec: -1335264273), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char alphaTableOut;	  // size=0, offset=10 //  hashcode: 0x26C23E6B (dec: 650264171), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char controllingSection; // size=0, offset=11 //  hashcode: 0x4673309B (dec: 1181954203), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	char index[3];					  // size=3, offset=12 //  hashcode: 0xF2FF172A (dec: -218163414), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pad;						  // size=0, offset=15 //  hashcode: 0x387D5922 (dec: 947738914), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterIdle // hashcode: 0x181712FA (dec: 404165370)
{
	char anim;		  // size=0, offset=0 //  hashcode: 0x11AE2EF5 (dec: 296627957), parent name: '_MonsterIdle', parent hashcode: 0xFFFFFFFF (dec: -1)
	char alertMod;	// size=0, offset=1 //  hashcode: 0x713DC824 (dec: 1899874340), parent name: '_MonsterIdle', parent hashcode: 0xFFFFFFFF (dec: -1)
	char probability; // size=0, offset=2 //  hashcode: 0xE6B270DB (dec: -424513317), parent name: '_MonsterIdle', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pad;		  // size=0, offset=3 //  hashcode: 0xDF690836 (dec: -546764746), parent name: '_MonsterIdle', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterBehavior // hashcode: 0x6D7D1660 (dec: 1836914272)
{
	char alertness;   // size=0, offset=0 //  hashcode: 0x13065412 (dec: 319181842), parent name: '_MonsterBehavior', parent hashcode: 0xFFFFFFFF (dec: -1)
	char idleFreq;	// size=0, offset=1 //  hashcode: 0x7B4177C2 (dec: 2067888066), parent name: '_MonsterBehavior', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numIdles;	// size=0, offset=2 //  hashcode: 0x025D2532 (dec: 39658802), parent name: '_MonsterBehavior', parent hashcode: 0xFFFFFFFF (dec: -1)
	char idleList[5]; // size=5, offset=3 //  hashcode: 0x7B66E39F (dec: 2070340511), parent name: '_MonsterBehavior', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterSenses // hashcode: 0x1AA0E325 (dec: 446751525)
{
	short sightArc;				// size=0, offset=0 //  hashcode: 0x3BF0671D (dec: 1005610781), parent name: '_MonsterSenses', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sightRadius;			// size=0, offset=2 //  hashcode: 0x3BEA3583 (dec: 1005204867), parent name: '_MonsterSenses', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sightElevation;		// size=0, offset=4 //  hashcode: 0xF30E6844 (dec: -217159612), parent name: '_MonsterSenses', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundArc;				// size=0, offset=6 //  hashcode: 0x7BA29C99 (dec: 2074254489), parent name: '_MonsterSenses', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundRadius;			// size=0, offset=8 //  hashcode: 0x7FD08FFA (dec: 2144374778), parent name: '_MonsterSenses', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundElevation;		// size=0, offset=10 //  hashcode: 0xB92979E5 (dec: -1188464155), parent name: '_MonsterSenses', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short scentRadius; // size=0, offset=12 //  hashcode: 0x094BAEAA (dec: 155954858), parent name: '_MonsterSenses', parent hashcode: 0xFFFFFFFF (dec: -1)
	short alarmRadius;			// size=0, offset=14 //  hashcode: 0x0262C2DF (dec: 40026847), parent name: '_MonsterSenses', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short allyRadius;  // size=0, offset=16 //  hashcode: 0xA9517304 (dec: -1454279932), parent name: '_MonsterSenses', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterAllegiances // hashcode: 0x1F15B182 (dec: 521515394)
{
	unsigned long enemies; // size=0, offset=0 //  hashcode: 0x0E8A8977 (dec: 243960183), parent name: '_MonsterAllegiances', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long allies;  // size=0, offset=4 //  hashcode: 0x73836E6A (dec: 1937993322), parent name: '_MonsterAllegiances', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long food;	// size=0, offset=8 //  hashcode: 0xB2E46B0C (dec: -1293653236), parent name: '_MonsterAllegiances', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long gods;	// size=0, offset=12 //  hashcode: 0x6EAF0460 (dec: 1856963680), parent name: '_MonsterAllegiances', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterAttackAttributes // hashcode: 0x4F8BA493 (dec: 1334551699)
{
	short attackRange;			// size=0, offset=0 //  hashcode: 0xE6B47E83 (dec: -424378749), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short attackHeight;			// size=0, offset=2 //  hashcode: 0x97BC874D (dec: -1749252275), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short knockBackDistance;	// size=0, offset=4 //  hashcode: 0xE5B64C8A (dec: -441037686), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char knockBackDuration;		// size=0, offset=6 //  hashcode: 0x4EE86CFD (dec: 1323855101), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char damage;				// size=0, offset=7 //  hashcode: 0x599E155F (dec: 1503532383), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char sphereSegment;			// size=0, offset=8 //  hashcode: 0x30A0DE04 (dec: 815848964), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char sphereOnFrame;			// size=0, offset=9 //  hashcode: 0xB9755618 (dec: -1183492584), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char sphereOnAnim;			// size=0, offset=10 //  hashcode: 0xD935E51C (dec: -650779364), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char sphereOffFrame;		// size=0, offset=11 //  hashcode: 0x5D7FA242 (dec: 1568645698), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char sphereOffAnim;			// size=0, offset=12 //  hashcode: 0x8DD3EAB8 (dec: -1915491656), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char turnFrames;			// size=0, offset=13 //  hashcode: 0x34C2C2F2 (dec: 885179122), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numAnims;				// size=0, offset=14 //  hashcode: 0x7F74B567 (dec: 2138355047), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char attackProbability[12]; // size=12, offset=15 //  hashcode: 0x0376294F (dec: 58075471), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char animList[5];			// size=5, offset=27 //  hashcode: 0x6324EBDE (dec: 1663364062), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterMissile // hashcode: 0xC37A9403 (dec: -1015376893)
{
	unsigned short speed;   // size=0, offset=0 //  hashcode: 0x850C34BA (dec: -2062797638), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short range;   // size=0, offset=2 //  hashcode: 0xD88ACDE9 (dec: -661991959), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char frame;	// size=0, offset=4 //  hashcode: 0x52ACB26D (dec: 1387049581), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char anim;		// size=0, offset=5 //  hashcode: 0xE6ABD897 (dec: -424945513), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segment;  // size=0, offset=6 //  hashcode: 0xC65C9D04 (dec: -967009020), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char damage;   // size=0, offset=7 //  hashcode: 0xFDD30A97 (dec: -36500841), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;		// size=0, offset=8 //  hashcode: 0xB2071A73 (dec: -1308157325), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char graphic;  // size=0, offset=9 //  hashcode: 0x6763A8B5 (dec: 1734584501), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	char gravity;			// size=0, offset=10 //  hashcode: 0x82EF177C (dec: -2098260100), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	char reload;			// size=0, offset=11 //  hashcode: 0x3465644E (dec: 879060046), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	char fireChance;		// size=0, offset=12 //  hashcode: 0x25C7BD2B (dec: 633847083), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numAnims; // size=0, offset=13 //  hashcode: 0x00AD08FB (dec: 11340027), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	char animList[2];		// size=2, offset=14 //  hashcode: 0xFA955D22 (dec: -90874590), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterCombatAttributes // hashcode: 0x1CD3787B (dec: 483620987)
{
	short stunTime;				// size=0, offset=0 //  hashcode: 0x0C9E853E (dec: 211715390), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short damageTime;			// size=0, offset=2 //  hashcode: 0x6CE699F3 (dec: 1827052019), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short recovery;				// size=0, offset=4 //  hashcode: 0x53CB5161 (dec: 1405833569), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short surpriseTime;			// size=0, offset=6 //  hashcode: 0x32D9FA2E (dec: 853146158), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short grabTime;				// size=0, offset=8 //  hashcode: 0x0B9332B8 (dec: 194196152), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short combatRange;			// size=0, offset=10 //  hashcode: 0xF083688D (dec: -259823475), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short surpriseRange;		// size=0, offset=12 //  hashcode: 0x5BEE1683 (dec: 1542329987), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short allyRange;			// size=0, offset=14 //  hashcode: 0xFC7B68B8 (dec: -59021128), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short enemyAttackRange;		// size=0, offset=16 //  hashcode: 0x0EB1D3E6 (dec: 246535142), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short enemyRunAttackRange;  // size=0, offset=18 //  hashcode: 0x87BEE73C (dec: -2017532100), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short preferredCombatRange; // size=0, offset=20 //  hashcode: 0x3485376A (dec: 881145706), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short suckPower;			// size=0, offset=22 //  hashcode: 0xB854BB6E (dec: -1202406546), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short suckRange;			// size=0, offset=24 //  hashcode: 0xF4CEC73F (dec: -187775169), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short suckTime;				// size=0, offset=26 //  hashcode: 0xE333FF9B (dec: -483131493), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char hitPoints;				// size=0, offset=28 //  hashcode: 0xF73AECDD (dec: -147133219), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numAttacks;			// size=0, offset=29 //  hashcode: 0x75EE3451 (dec: 1978545233), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char missileAttack;			// size=0, offset=30 //  hashcode: 0xA1C26E13 (dec: -1581093357), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char ambushAttack;			// size=0, offset=31 //  hashcode: 0xB3B77EDE (dec: -1279820066), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char evadeProbability[12];  // size=12, offset=32 //  hashcode: 0x0A9B842D (dec: 177964077), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char attackList[1];			// size=1, offset=44 //  hashcode: 0x08EC831D (dec: 149717789), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterSubAttributes // hashcode: 0xD249D756 (dec: -766912682)
{
	char *animList;									   // size=0, offset=0 //  hashcode: 0xBB4C3E8A (dec: -1152631158), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterSenses *senses;					   // size=18, offset=4 //  hashcode: 0x3D0CC33B (dec: 1024246587), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterCombatAttributes *combatAttributes; // size=46, offset=8 //  hashcode: 0xA25F0CBA (dec: -1570829126), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterAllegiances *allegiances;		   // size=16, offset=12 //  hashcode: 0x725064C5 (dec: 1917871301), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *behaviorList;								   // size=0, offset=16 //  hashcode: 0x1DECA7D4 (dec: 502048724), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short scale;									   // size=0, offset=20 //  hashcode: 0xA695EB39 (dec: -1500124359), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fallDistance;								   // size=0, offset=22 //  hashcode: 0xE5C14E93 (dec: -440316269), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short defAmbushRange;							   // size=0, offset=24 //  hashcode: 0x097DE633 (dec: 159245875), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fleeRange;								   // size=0, offset=26 //  hashcode: 0xC1FE0F42 (dec: -1040314558), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short speedPivotTurn;							   // size=0, offset=28 //  hashcode: 0x202F1177 (dec: 539955575), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short speedWalkTurn;							   // size=0, offset=30 //  hashcode: 0x76EA9ADD (dec: 1995086557), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short speedRunTurn;								   // size=0, offset=32 //  hashcode: 0x0B1E0EB6 (dec: 186519222), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short speedFleeTurn;							   // size=0, offset=34 //  hashcode: 0x4335E730 (dec: 1127606064), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short forgetTime;								   // size=0, offset=36 //  hashcode: 0x81BB331A (dec: -2118438118), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char modelNum;							   // size=0, offset=38 //  hashcode: 0xB0461FDB (dec: -1337581605), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char physAbility;						   // size=0, offset=39 //  hashcode: 0xCBD4A8C7 (dec: -875255609), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char stunnable;						   // size=0, offset=40 //  hashcode: 0x776C5289 (dec: 2003587721), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char grabable;							   // size=0, offset=41 //  hashcode: 0xE88C156E (dec: -393472658), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numSections;						   // size=0, offset=42 //  hashcode: 0x03F046F0 (dec: 66078448), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sectionEnd[3];					   // size=3, offset=43 //  hashcode: 0x20F5F31A (dec: 552989466), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short defPlayerAttitude;						   // size=0, offset=46 //  hashcode: 0x6B27A50A (dec: 1797760266), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short defWanderRange;							   // size=0, offset=48 //  hashcode: 0x0B5D3AFC (dec: 190659324), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short defGuardRange;							   // size=0, offset=50 //  hashcode: 0x6BB12BF4 (dec: 1806773236), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char defInitialBehavior;				   // size=0, offset=52 //  hashcode: 0x565AC0EA (dec: 1448788202), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char defTriggeredBehavior;				   // size=0, offset=53 //  hashcode: 0x1A33FEEB (dec: 439615211), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char defActiveBehavior;							   // size=0, offset=54 //  hashcode: 0x86CA4178 (dec: -2033565320), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char defSpectral;						   // size=0, offset=55 //  hashcode: 0x4B89ADAD (dec: 1267314093), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sunVuln;							   // size=0, offset=56 //  hashcode: 0xB8A67D8B (dec: -1197048437), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char fireVuln;							   // size=0, offset=57 //  hashcode: 0xBF088A28 (dec: -1089959384), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char waterVuln;						   // size=0, offset=58 //  hashcode: 0xC1A2CAE9 (dec: -1046295831), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char impaleVuln;						   // size=0, offset=59 //  hashcode: 0x04C8BD82 (dec: 80264578), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char soundVuln;						   // size=0, offset=60 //  hashcode: 0x17C20715 (dec: 398591765), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char weaponVuln;						   // size=0, offset=61 //  hashcode: 0x0EC73D10 (dec: 247938320), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char missileVuln;						   // size=0, offset=62 //  hashcode: 0x1F5D856D (dec: 526222701), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char bruiseRed;						   // size=0, offset=63 //  hashcode: 0x80F52391 (dec: -2131418223), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char bruiseGreen;						   // size=0, offset=64 //  hashcode: 0x99364082 (dec: -1724497790), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char bruiseBlue;						   // size=0, offset=65 //  hashcode: 0xBC9CD2C4 (dec: -1130573116), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minSpikeRange;							   // size=0, offset=66 //  hashcode: 0x799CE3AD (dec: 2040325037), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxSpikeRange;							   // size=0, offset=68 //  hashcode: 0x32EAD5D1 (dec: 854250961), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxSpikeAngle;							   // size=0, offset=70 //  hashcode: 0x7844D2CE (dec: 2017776334), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minSpikeHorzSpeed;						   // size=0, offset=72 //  hashcode: 0x09AB6B78 (dec: 162229112), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxSpikeHorzSpeed;						   // size=0, offset=74 //  hashcode: 0x98E4B79B (dec: -1729841253), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxSpikeVertSpeed;						   // size=0, offset=76 //  hashcode: 0x55945492 (dec: 1435784338), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short upOnGroundOffset;							   // size=0, offset=78 //  hashcode: 0x78039E99 (dec: 2013503129), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short downOnGroundOffset;						   // size=0, offset=80 //  hashcode: 0xDEBFF149 (dec: -557846199), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct _G2EulerAngles_Type G2EulerAngles;

typedef enum _G2AnimCallbackMsg_Enum G2AnimCallbackMsg;

typedef struct _AnimSoundData_Type AnimSoundData;

typedef struct _InstanceHandle InstanceHandle;

typedef struct evCollideInstanceStatsData evCollideInstanceStatsData;

typedef struct INICommand INICommand;

typedef struct SavedIntroSmall SavedIntroSmall;

typedef struct SavedIntroSpline SavedIntroSpline;

typedef struct _SavedIntroWithIntro SavedIntroWithIntro;

typedef struct _MonsterAnim MonsterAnim;

typedef struct _MonsterIdle MonsterIdle;

typedef struct _MonsterBehavior MonsterBehavior;

typedef struct _MonsterSenses MonsterSenses;

typedef struct _MonsterAllegiances MonsterAllegiances;

typedef struct _MonsterAttackAttributes MonsterAttackAttributes;

typedef struct _MonsterMissile MonsterMissile;

typedef struct _MonsterCombatAttributes MonsterCombatAttributes;

typedef struct _MonsterSubAttributes MonsterSubAttributes;

typedef void (*processVert_t)();

extern void INSTANCE_ClearTfaces(struct _Instance *instance); // 0x80031ED8

extern void INSTANCE_Deactivate(struct _Instance *instance); // 0x80031F04

extern void INSTANCE_Reactivate(struct _Instance *instance); // 0x80031FC0

extern void INSTANCE_ForceActive(struct _Instance *instance); // 0x80032058

extern void INSTANCE_DeactivatedProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8003208C

extern void INSTANCE_DeactivateFarInstances(struct GameTracker *gameTracker); // 0x80032094

extern void INSTANCE_InitInstanceList(struct _InstanceList *list, struct _InstancePool *pool); // 0x80032310

extern struct _Instance *INSTANCE_NewInstance(struct _InstanceList *list); // 0x800323B0

extern long INSTANCE_InstanceGroupNumber(struct _Instance *instance); // 0x8003243C

extern void INSTANCE_InsertInstanceGroup(struct _InstanceList *list, struct _Instance *instance); // 0x80032558

extern void INSTANCE_ReallyRemoveInstance(struct _InstanceList *list, struct _Instance *instance, long reset); // 0x800325A0

extern void INSTANCE_CleanUpInstanceList(struct _InstanceList *list, long reset); // 0x800327E4

extern long INSTANCE_Introduced(struct Intro *intro, short streamUnitID); // 0x800328A0

extern struct INICommand *INSTANCE_GetIntroCommand(struct INICommand *command, int cmd); // 0x80032958

extern struct INICommand *INSTANCE_FindIntroCommand(struct _Instance *instance, int cmd); // 0x800329A8

extern void INSTANCE_ProcessIntro(struct _Instance *instance); // 0x800329CC

extern void INSTANCE_InitEffects(struct _Instance *instance, struct Object *object); // 0x80032A48

extern struct _Instance *INSTANCE_IntroduceInstance(struct Intro *intro, short streamUnitID); // 0x80032AD0

extern void INSTANCE_AdditionalCollideFunctions(struct _InstanceList *instanceList); // 0x800331F0

extern long INSTANCE_GetSplineFrameNumber(struct _Instance *instance, struct MultiSpline *spline); // 0x80033318

extern void INSTANCE_ProcessFunctions(struct _InstanceList *instanceList); // 0x80033350

extern struct _Instance *INSTANCE_BirthObject(struct _Instance *parent, struct Object *object, int modelNum); // 0x80033BFC

extern void INSTANCE_BuildStaticShadow(struct _Instance *instance); // 0x80033E6C

extern void INSTANCE_DefaultInit(struct _Instance *instance, struct Object *object, int modelNum); // 0x80033E74

extern void INSTANCE_PlainDeath(struct _Instance *instance); // 0x80034230

extern void INSTANCE_KillInstance(struct _Instance *instance); // 0x80034360

extern unsigned long INSTANCE_Query(struct _Instance *Inst, int Query); // 0x80034394

extern void INSTANCE_Post(struct _Instance *Inst, int Message, int Data); // 0x800343D0

extern void INSTANCE_Broadcast(struct _Instance *sender, long whatAmIMask, int Message, int Data); // 0x80034434

extern int INSTANCE_InPlane(struct _Instance *instance, int plane); // 0x800344E0

extern long INSTANCE_FindWithID(long uniqueID); // 0x8003453C

extern struct _Instance *INSTANCE_FindWithName(long areaID, char *instanceName, struct _Instance *startInstance); // 0x8003457C

extern struct Intro *INSTANCE_FindIntro(long areaID, long introUniqueID); // 0x80034650

extern struct _Instance *INSTANCE_Find(long introUniqueID); // 0x800346D4

extern struct _Instance *INSTANCE_IntroduceSavedInstance(struct _SavedIntro *savedIntro, struct _StreamUnit *streamUnit, int *deleted); // 0x80034714

extern struct _Instance *INSTANCE_IntroduceSavedInstanceWithIntro(struct _SavedIntroWithIntro *savedIntro, struct _StreamUnit *streamUnit, int *deleted); // 0x80034B8C

extern void INSTANCE_SpatialRelationships(struct _InstanceList *instanceList); // 0x80035000

extern int INSTANCE_SetStatsData(struct _Instance *instance, struct _Instance *checkee, struct _Vector *checkPoint, struct evCollideInstanceStatsData *data, struct MATRIX *mat); // 0x80035164

extern void INSTANCE_LinkToParent(struct _Instance *instance, struct _Instance *parent, int node); // 0x80035274

extern void INSTANCE_UnlinkFromParent(struct _Instance *instance); // 0x80035330

extern void INSTANCE_UnlinkChildren(struct _Instance *instance); // 0x80035494

extern void INSTANCE_UpdateFamilyStreamUnitID(struct _Instance *instance); // 0x80035500

extern void INSTANCE_ReallyRemoveAllChildren(struct _Instance *instance); // 0x80035558

extern struct _Instance *INSTANCE_GetChildLinkedToSegment(struct _Instance *instance, int segment); // 0x800355B4

extern int INSTANCE_Linked(struct _Instance *instance1, struct _Instance *instance2); // 0x800355EC

extern int INSTANCE_GetFadeValue(struct _Instance *instance); // 0x8003563C

extern unsigned long INSTANCE_DefaultAnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, struct _Instance *instance); // 0x80035720

#endif
