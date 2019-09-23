#ifndef TIMER_H
#define TIMER_H

struct TIMER_68fake // hashcode: 0x0DD01C17 (dec: 231742487)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x76900C36 (dec: 1989151798), parent name: 'TIMER_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0xCEFFFEB3 (dec: -822083917), parent name: 'TIMER_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_69fake // hashcode: 0x15D30AEF (dec: 366152431)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xEFD3D905 (dec: -271329019), parent name: 'TIMER_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x8A5B6A7C (dec: -1973720452), parent name: 'TIMER_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_70fake // hashcode: 0xDC8F3451 (dec: -594594735)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xD12CC880 (dec: -785594240), parent name: 'TIMER_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x948C7EA0 (dec: -1802731872), parent name: 'TIMER_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union TIMER_71fake // Hashcode: 0x3CBEC8D9 (dec: 1019136217)
{
	struct TIMER_68fake callback; // size=8, offset=0
	struct TIMER_69fake vector;   // size=12, offset=0
	struct TIMER_70fake quat;	 // size=16, offset=0
};

union TIMER_72fake // Hashcode: 0x2BECCC5B (dec: 736939099)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union TIMER_73fake // Hashcode: 0x1AA9A21E (dec: 447324702)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct TIMER_74fake // hashcode: 0x781E7E65 (dec: 2015264357)
{
	union TIMER_73fake size; // size=4, offset=0 //  hashcode: 0xD71072F9 (dec: -686787847), parent name: 'TIMER_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_75fake // hashcode: 0x52BAAB68 (dec: 1387965288)
{
	short x;				// size=0, offset=0 //  hashcode: 0xD73B4DB8 (dec: -683979336), parent name: 'TIMER_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xA6646F5E (dec: -1503367330), parent name: 'TIMER_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x688D3002 (dec: 1754083330), parent name: 'TIMER_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x0E9F8DE3 (dec: 245337571), parent name: 'TIMER_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x49E2AC6F (dec: 1239592047), parent name: 'TIMER_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_76fake // hashcode: 0x9368AE6A (dec: -1821856150)
{
	long index; // size=0, offset=0 //  hashcode: 0x83BDD857 (dec: -2084710313), parent name: 'TIMER_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x75A837FF (dec: 1973958655), parent name: 'TIMER_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_77fake // hashcode: 0xF37D5E3E (dec: -209887682)
{
	long index; // size=0, offset=0 //  hashcode: 0x83EBAEFA (dec: -2081706246), parent name: 'TIMER_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xB7E8CA33 (dec: -1209480653), parent name: 'TIMER_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_78fake // hashcode: 0x0CCA867E (dec: 214599294)
{
	long index; // size=0, offset=0 //  hashcode: 0x59BED08F (dec: 1505677455), parent name: 'TIMER_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x721CD31B (dec: 1914491675), parent name: 'TIMER_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_79fake // hashcode: 0xC8F877E2 (dec: -923240478)
{
	long time;  // size=0, offset=0 //  hashcode: 0x841EEB5B (dec: -2078348453), parent name: 'TIMER_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x355D487E (dec: 895305854), parent name: 'TIMER_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_80fake // hashcode: 0xA609713F (dec: -1509330625)
{
	long action;   // size=0, offset=0 //  hashcode: 0xFF4D0972 (dec: -11728526), parent name: 'TIMER_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x8F30818C (dec: -1892646516), parent name: 'TIMER_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_81fake // hashcode: 0xBA3F1392 (dec: -1170271342)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xF0DB3748 (dec: -254068920), parent name: 'TIMER_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xF774AC8C (dec: -143348596), parent name: 'TIMER_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_82fake // hashcode: 0x6B1E0370 (dec: 1797129072)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x96CD52A7 (dec: -1764928857), parent name: 'TIMER_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x460D000F (dec: 1175257103), parent name: 'TIMER_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_83fake // hashcode: 0xE861893E (dec: -396261058)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xAABAD1B0 (dec: -1430597200), parent name: 'TIMER_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xE8C405BA (dec: -389806662), parent name: 'TIMER_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_84fake // hashcode: 0xCAF1E916 (dec: -890115818)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x8B9E198C (dec: -1952573044), parent name: 'TIMER_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x6AE221A9 (dec: 1793204649), parent name: 'TIMER_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x5A43992D (dec: 1514379565), parent name: 'TIMER_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xE02A20B8 (dec: -534110024), parent name: 'TIMER_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x55F0B015 (dec: 1441837077), parent name: 'TIMER_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_85fake // hashcode: 0xC889568C (dec: -930523508)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xD3818AB4 (dec: -746485068), parent name: 'TIMER_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xF3BAD0DF (dec: -205860641), parent name: 'TIMER_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_86fake // hashcode: 0x404E67EC (dec: 1078880236)
{
	short index;					// size=0, offset=0 //  hashcode: 0xBA30CA0A (dec: -1171207670), parent name: 'TIMER_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x1663CEFB (dec: 375639803), parent name: 'TIMER_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x1777697E (dec: 393701758), parent name: 'TIMER_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x5170ED78 (dec: 1366355320), parent name: 'TIMER_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_87fake // hashcode: 0xC8AAB0BA (dec: -928337734)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xA93E9643 (dec: -1455516093), parent name: 'TIMER_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x4F3E563C (dec: 1329485372), parent name: 'TIMER_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x08333ED2 (dec: 137576146), parent name: 'TIMER_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_88fake // hashcode: 0xFAD15A3E (dec: -86943170)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x034419FC (dec: 54794748), parent name: 'TIMER_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x51AC65E7 (dec: 1370252775), parent name: 'TIMER_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xD3EA284C (dec: -739628980), parent name: 'TIMER_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x1978C75D (dec: 427345757), parent name: 'TIMER_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x895E20FB (dec: -1990319877), parent name: 'TIMER_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x2998547A (dec: 697848954), parent name: 'TIMER_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xCFEFF9CD (dec: -806356531), parent name: 'TIMER_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_89fake // hashcode: 0x39340AD5 (dec: 959711957)
{
	long index;  // size=0, offset=0 //  hashcode: 0xD5DF73DB (dec: -706776101), parent name: 'TIMER_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xDE0AE3DA (dec: -569711654), parent name: 'TIMER_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_90fake // hashcode: 0x1A6A711F (dec: 443183391)
{
	short type; // size=0, offset=0 //  hashcode: 0xEFAEF67B (dec: -273746309), parent name: 'TIMER_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x5A6DCB67 (dec: 1517144935), parent name: 'TIMER_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_91fake // hashcode: 0xCFAED863 (dec: -810624925)
{
	long time;   // size=0, offset=0 //  hashcode: 0x489682A4 (dec: 1217823396), parent name: 'TIMER_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x2E53E836 (dec: 777250870), parent name: 'TIMER_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_92fake // hashcode: 0x0C01FC08 (dec: 201456648)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x20763CDA (dec: 544619738), parent name: 'TIMER_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x197A5E87 (dec: 427449991), parent name: 'TIMER_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_93fake // hashcode: 0xE35BB9A3 (dec: -480527965)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xD4B76812 (dec: -726177774), parent name: 'TIMER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xEB4F8AED (dec: -347108627), parent name: 'TIMER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_94fake // hashcode: 0xD1C4583D (dec: -775661507)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x56C89C2E (dec: 1455987758), parent name: 'TIMER_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x0E46A90E (dec: 239511822), parent name: 'TIMER_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_95fake // hashcode: 0x19097886 (dec: 420051078)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x6A9D4F64 (dec: 1788694372), parent name: 'TIMER_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x6C28C154 (dec: 1814610260), parent name: 'TIMER_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xDE82E4CF (dec: -561847089), parent name: 'TIMER_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x67F8395F (dec: 1744320863), parent name: 'TIMER_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_96fake // hashcode: 0xC27B1889 (dec: -1032120183)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x58933E4F (dec: 1486044751), parent name: 'TIMER_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xDC4B7C4A (dec: -599032758), parent name: 'TIMER_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x9A06137C (dec: -1710877828), parent name: 'TIMER_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xAB9F9BE2 (dec: -1415603230), parent name: 'TIMER_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x55EB62BF (dec: 1441489599), parent name: 'TIMER_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union TIMER_97fake // Hashcode: 0x20503A99 (dec: 542128793)
{
	struct TIMER_74fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	 // size=24, offset=0
	struct TIMER_75fake teleport;	 // size=16, offset=0
	struct TIMER_76fake cameraValue;  // size=8, offset=0
	struct TIMER_77fake miscValue;	// size=8, offset=0
	struct TIMER_78fake logicValue;   // size=8, offset=0
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
	struct TIMER_79fake cameraShake;  // size=8, offset=0
	long cameraSave;				  // size=0, offset=0
	long cameraRestore;				  // size=0, offset=0
	struct _BGObject *bgObject;		  // size=24, offset=0
	long value[2];					  // size=8, offset=0
	struct TIMER_80fake sound;		  // size=12, offset=0
	void *intro;					  // size=0, offset=0
	long deathZ;					  // size=0, offset=0
	struct TIMER_81fake dsignal;	  // size=8, offset=0
	void *mirror;					  // size=0, offset=0
	long fogNear;					  // size=0, offset=0
	long fogFar;					  // size=0, offset=0
	struct TIMER_82fake gotoFrame;	// size=8, offset=0
	struct TIMER_83fake changeModel;  // size=8, offset=0
	void *vmObject;					  // size=0, offset=0
	struct TIMER_84fake logic;		  // size=8, offset=0
	void *callSignal;				  // size=0, offset=0
	struct _SVector offset;			  // size=8, offset=0
	struct Signal *gotoLabel;		  // size=0, offset=0
	struct Signal *gosubLabel;		  // size=0, offset=0
	struct TIMER_85fake control;	  // size=8, offset=0
	struct TIMER_86fake zSignal;	  // size=12, offset=0
	struct TIMER_87fake StreamLevel;  // size=24, offset=0
	struct TIMER_88fake shards;		  // size=12, offset=0
	struct TIMER_89fake cameraSpline; // size=8, offset=0
	struct TIMER_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;				  // size=0, offset=0
	struct TIMER_91fake introFX;	  // size=8, offset=0
	struct TIMER_92fake introActive;  // size=8, offset=0
	struct TIMER_93fake levelChange;  // size=18, offset=0
	long blendStart;				  // size=0, offset=0
	struct TIMER_94fake setTimes;	 // size=8, offset=0
	struct TIMER_95fake color;		  // size=4, offset=0
	struct TIMER_96fake print;		  // size=12, offset=0
	long slideAngle;				  // size=0, offset=0
};

union TIMER_98fake // Hashcode: 0x1A4089C0 (dec: 440437184)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union TIMER_103fake // Hashcode: 0x382585C5 (dec: 941983173)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct TIMER_105fake // hashcode: 0x7A1CCAB4 (dec: 2048707252)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x968CDA5E (dec: -1769153954), parent name: 'TIMER_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xF754D749 (dec: -145434807), parent name: 'TIMER_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x7D89F76E (dec: 2106193774), parent name: 'TIMER_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x69076025 (dec: 1762091045), parent name: 'TIMER_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0xC67643A5 (dec: -965327963), parent name: 'TIMER_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x9E62A695 (dec: -1637701995), parent name: 'TIMER_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xAA8EE515 (dec: -1433475819), parent name: 'TIMER_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_106fake // hashcode: 0x0F7448B2 (dec: 259279026)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x32365CCD (dec: 842423501), parent name: 'TIMER_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x0533DA7B (dec: 87284347), parent name: 'TIMER_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x4851AE01 (dec: 1213312513), parent name: 'TIMER_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_107fake // hashcode: 0x59974D48 (dec: 1503087944)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x7968EABB (dec: 2036918971), parent name: 'TIMER_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xA45FAB41 (dec: -1537234111), parent name: 'TIMER_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xAFAB3F3F (dec: -1347731649), parent name: 'TIMER_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x722CA506 (dec: 1915528454), parent name: 'TIMER_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x48DF9C66 (dec: 1222614118), parent name: 'TIMER_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_108fake // hashcode: 0x2B12E127 (dec: 722657575)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x0CDA561C (dec: 215635484), parent name: 'TIMER_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x28B3BA9A (dec: 682867354), parent name: 'TIMER_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x6CBDC62D (dec: 1824376365), parent name: 'TIMER_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x417A1B76 (dec: 1098521462), parent name: 'TIMER_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xF8E78201 (dec: -119045631), parent name: 'TIMER_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TIMER_109fake // hashcode: 0x38B8D1E3 (dec: 951636451)
{
	struct TIMER_105fake Cinematic; // size=28, offset=0 //  hashcode: 0x511DBAF4 (dec: 1360902900), parent name: 'TIMER_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct TIMER_106fake Idle;		// size=20, offset=28 //  hashcode: 0x72D679D3 (dec: 1926658515), parent name: 'TIMER_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct TIMER_107fake Behind;	// size=28, offset=48 //  hashcode: 0x52A8D1EE (dec: 1386795502), parent name: 'TIMER_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct TIMER_108fake Follow;	// size=20, offset=76 //  hashcode: 0x906F3DED (dec: -1871757843), parent name: 'TIMER_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

extern unsigned long TIMER_GetTimeMS(); // 0x8003D7B0

extern unsigned long TIMER_TimeDiff(unsigned long x); // 0x8003D840

#endif
