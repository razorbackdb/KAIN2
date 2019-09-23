#ifndef CONTROL_H
#define CONTROL_H

static struct __Force *ExternalForces; // offset 0x800D51D4

static struct MATRIX TempMat; // offset 0x800D51E4

struct CONTROL_68fake // hashcode: 0xB2DAE6D4 (dec: -1294276908)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x8EA025DB (dec: -1902107173), parent name: 'CONTROL_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x1B105F09 (dec: 454057737), parent name: 'CONTROL_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_69fake // hashcode: 0x4B4F5864 (dec: 1263491172)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xA310402E (dec: -1559216082), parent name: 'CONTROL_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xFD3F2CFE (dec: -46191362), parent name: 'CONTROL_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_70fake // hashcode: 0xBD3F0BB3 (dec: -1119941709)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xC0C7F2FB (dec: -1060637957), parent name: 'CONTROL_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x4B05FEA4 (dec: 1258684068), parent name: 'CONTROL_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union CONTROL_71fake // Hashcode: 0x043A48B4 (dec: 70928564)
{
	struct CONTROL_68fake callback; // size=8, offset=0
	struct CONTROL_69fake vector;   // size=12, offset=0
	struct CONTROL_70fake quat;		// size=16, offset=0
};

union CONTROL_72fake // Hashcode: 0xC9FAD521 (dec: -906308319)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union CONTROL_73fake // Hashcode: 0x5B54EA63 (dec: 1532291683)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct CONTROL_74fake // hashcode: 0xC6CF295D (dec: -959501987)
{
	union CONTROL_73fake size; // size=4, offset=0 //  hashcode: 0x99D4BA4E (dec: -1714111922), parent name: 'CONTROL_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_75fake // hashcode: 0x89B34278 (dec: -1984740744)
{
	short x;				// size=0, offset=0 //  hashcode: 0xC02AB102 (dec: -1070943998), parent name: 'CONTROL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x135463C1 (dec: 324297665), parent name: 'CONTROL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xAF1A98BD (dec: -1357211459), parent name: 'CONTROL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x32CFAA2B (dec: 852470315), parent name: 'CONTROL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x2E8D667E (dec: 781018750), parent name: 'CONTROL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_76fake // hashcode: 0x214EC394 (dec: 558810004)
{
	long index; // size=0, offset=0 //  hashcode: 0x377C45CD (dec: 930891213), parent name: 'CONTROL_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xA73BAA73 (dec: -1489261965), parent name: 'CONTROL_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_77fake // hashcode: 0xAE9A4A8E (dec: -1365620082)
{
	long index; // size=0, offset=0 //  hashcode: 0x293A8294 (dec: 691700372), parent name: 'CONTROL_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xA3E13FED (dec: -1545519123), parent name: 'CONTROL_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_78fake // hashcode: 0x473F8563 (dec: 1195345251)
{
	long index; // size=0, offset=0 //  hashcode: 0xFAB37602 (dec: -88902142), parent name: 'CONTROL_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xF9F1A52B (dec: -101604053), parent name: 'CONTROL_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_79fake // hashcode: 0xDDC6C628 (dec: -574175704)
{
	long time;  // size=0, offset=0 //  hashcode: 0x317B709B (dec: 830173339), parent name: 'CONTROL_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x22D59268 (dec: 584421992), parent name: 'CONTROL_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_80fake // hashcode: 0x23EC24F9 (dec: 602678521)
{
	long action;   // size=0, offset=0 //  hashcode: 0x3F4B4599 (dec: 1061897625), parent name: 'CONTROL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xC320B657 (dec: -1021266345), parent name: 'CONTROL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_81fake // hashcode: 0x55CE8AD5 (dec: 1439599317)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x41700423 (dec: 1097860131), parent name: 'CONTROL_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x614DA132 (dec: 1632477490), parent name: 'CONTROL_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_82fake // hashcode: 0xCB75BD1D (dec: -881476323)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x65D0C521 (dec: 1708180769), parent name: 'CONTROL_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x6BD09A69 (dec: 1808833129), parent name: 'CONTROL_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_83fake // hashcode: 0x836658D9 (dec: -2090444583)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xADC45222 (dec: -1379642846), parent name: 'CONTROL_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xA0D136FC (dec: -1596901636), parent name: 'CONTROL_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_84fake // hashcode: 0x38920789 (dec: 949094281)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xCB69A37D (dec: -882269315), parent name: 'CONTROL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x7766BC57 (dec: 2003221591), parent name: 'CONTROL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x381548D7 (dec: 940918999), parent name: 'CONTROL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xA4F85BED (dec: -1527227411), parent name: 'CONTROL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x16A791CA (dec: 380080586), parent name: 'CONTROL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_85fake // hashcode: 0x9CC24B68 (dec: -1664988312)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x89BF4C0E (dec: -1983951858), parent name: 'CONTROL_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x0BB37DA6 (dec: 196312486), parent name: 'CONTROL_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_86fake // hashcode: 0x23B770E2 (dec: 599224546)
{
	short index;					// size=0, offset=0 //  hashcode: 0xEC3DB150 (dec: -331501232), parent name: 'CONTROL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xA4D6A13E (dec: -1529437890), parent name: 'CONTROL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x0D3124DE (dec: 221324510), parent name: 'CONTROL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x9849DA02 (dec: -1739990526), parent name: 'CONTROL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_87fake // hashcode: 0x507670B2 (dec: 1349939378)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x06F3B8A5 (dec: 116635813), parent name: 'CONTROL_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xC40C18D5 (dec: -1005840171), parent name: 'CONTROL_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xDCC27ABB (dec: -591234373), parent name: 'CONTROL_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_88fake // hashcode: 0xD0397F3D (dec: -801538243)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xBA2F039C (dec: -1171324004), parent name: 'CONTROL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x68CE1C18 (dec: 1758338072), parent name: 'CONTROL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x93706422 (dec: -1821350878), parent name: 'CONTROL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x767623C1 (dec: 1987453889), parent name: 'CONTROL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x9FBAF3B9 (dec: -1615137863), parent name: 'CONTROL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x5F2ABFF4 (dec: 1596637172), parent name: 'CONTROL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x279F9E6E (dec: 664772206), parent name: 'CONTROL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_89fake // hashcode: 0xAEE8098C (dec: -1360524916)
{
	long index;  // size=0, offset=0 //  hashcode: 0x2657AB57 (dec: 643279703), parent name: 'CONTROL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x37395E7E (dec: 926506622), parent name: 'CONTROL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_90fake // hashcode: 0x45B5307D (dec: 1169502333)
{
	short type; // size=0, offset=0 //  hashcode: 0x0DBB0721 (dec: 230360865), parent name: 'CONTROL_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xFA81F2E6 (dec: -92146970), parent name: 'CONTROL_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_91fake // hashcode: 0xD4DE4E27 (dec: -723628505)
{
	long time;   // size=0, offset=0 //  hashcode: 0xBFDFD701 (dec: -1075849471), parent name: 'CONTROL_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x480DC77F (dec: 1208862591), parent name: 'CONTROL_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_92fake // hashcode: 0x5DE35E1B (dec: 1575181851)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xAB1F88E0 (dec: -1423996704), parent name: 'CONTROL_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x6FF98A95 (dec: 1878624917), parent name: 'CONTROL_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_93fake // hashcode: 0xF568ED6A (dec: -177672854)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xE2306978 (dec: -500143752), parent name: 'CONTROL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x15F8E33B (dec: 368632635), parent name: 'CONTROL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_94fake // hashcode: 0x3AE4F875 (dec: 988084341)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x9693CF98 (dec: -1768697960), parent name: 'CONTROL_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x91AF1C81 (dec: -1850794879), parent name: 'CONTROL_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_95fake // hashcode: 0x1A39BAB9 (dec: 439990969)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x16D4D9BE (dec: 383048126), parent name: 'CONTROL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xC77D808A (dec: -948076406), parent name: 'CONTROL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x7AD42A14 (dec: 2060724756), parent name: 'CONTROL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x05438F7A (dec: 88313722), parent name: 'CONTROL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_96fake // hashcode: 0x8EAC60D4 (dec: -1901305644)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x829F9FF9 (dec: -2103468039), parent name: 'CONTROL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x376DA701 (dec: 929933057), parent name: 'CONTROL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xB5C50AA2 (dec: -1245377886), parent name: 'CONTROL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x0E3C98F9 (dec: 238852345), parent name: 'CONTROL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xC1288E23 (dec: -1054306781), parent name: 'CONTROL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union CONTROL_97fake // Hashcode: 0x11C4E1A9 (dec: 298115497)
{
	struct CONTROL_74fake misc[3];		// size=12, offset=0
	struct _CameraKey *cameraKey;		// size=24, offset=0
	struct CONTROL_75fake teleport;		// size=16, offset=0
	struct CONTROL_76fake cameraValue;  // size=8, offset=0
	struct CONTROL_77fake miscValue;	// size=8, offset=0
	struct CONTROL_78fake logicValue;   // size=8, offset=0
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
	struct CONTROL_79fake cameraShake;  // size=8, offset=0
	long cameraSave;					// size=0, offset=0
	long cameraRestore;					// size=0, offset=0
	struct _BGObject *bgObject;			// size=24, offset=0
	long value[2];						// size=8, offset=0
	struct CONTROL_80fake sound;		// size=12, offset=0
	void *intro;						// size=0, offset=0
	long deathZ;						// size=0, offset=0
	struct CONTROL_81fake dsignal;		// size=8, offset=0
	void *mirror;						// size=0, offset=0
	long fogNear;						// size=0, offset=0
	long fogFar;						// size=0, offset=0
	struct CONTROL_82fake gotoFrame;	// size=8, offset=0
	struct CONTROL_83fake changeModel;  // size=8, offset=0
	void *vmObject;						// size=0, offset=0
	struct CONTROL_84fake logic;		// size=8, offset=0
	void *callSignal;					// size=0, offset=0
	struct _SVector offset;				// size=8, offset=0
	struct Signal *gotoLabel;			// size=0, offset=0
	struct Signal *gosubLabel;			// size=0, offset=0
	struct CONTROL_85fake control;		// size=8, offset=0
	struct CONTROL_86fake zSignal;		// size=12, offset=0
	struct CONTROL_87fake StreamLevel;  // size=24, offset=0
	struct CONTROL_88fake shards;		// size=12, offset=0
	struct CONTROL_89fake cameraSpline; // size=8, offset=0
	struct CONTROL_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;					// size=0, offset=0
	struct CONTROL_91fake introFX;		// size=8, offset=0
	struct CONTROL_92fake introActive;  // size=8, offset=0
	struct CONTROL_93fake levelChange;  // size=18, offset=0
	long blendStart;					// size=0, offset=0
	struct CONTROL_94fake setTimes;		// size=8, offset=0
	struct CONTROL_95fake color;		// size=4, offset=0
	struct CONTROL_96fake print;		// size=12, offset=0
	long slideAngle;					// size=0, offset=0
};

union CONTROL_98fake // Hashcode: 0x6BD98910 (dec: 1809418512)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union CONTROL_103fake // Hashcode: 0xA0D450C0 (dec: -1596698432)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct CONTROL_105fake // hashcode: 0xEC5C58EB (dec: -329492245)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x4ABB33D0 (dec: 1253782480), parent name: 'CONTROL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x44E125C7 (dec: 1155605959), parent name: 'CONTROL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0xC1F62989 (dec: -1040832119), parent name: 'CONTROL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xA5D89A9E (dec: -1512531298), parent name: 'CONTROL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0xD16BA2E5 (dec: -781475099), parent name: 'CONTROL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x19B8ABC0 (dec: 431532992), parent name: 'CONTROL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xB2B92C9B (dec: -1296487269), parent name: 'CONTROL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_106fake // hashcode: 0x1C21B4C4 (dec: 471971012)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0xF9E1DA99 (dec: -102638951), parent name: 'CONTROL_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x3F657C41 (dec: 1063615553), parent name: 'CONTROL_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x44F63A3B (dec: 1156987451), parent name: 'CONTROL_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_107fake // hashcode: 0xFCAA49C3 (dec: -55948861)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xDEF09522 (dec: -554658526), parent name: 'CONTROL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xDA1D2A11 (dec: -635622895), parent name: 'CONTROL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x57EC22E7 (dec: 1475093223), parent name: 'CONTROL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xA3A349EC (dec: -1549579796), parent name: 'CONTROL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xA9A6D6FD (dec: -1448683779), parent name: 'CONTROL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_108fake // hashcode: 0x41BC83C4 (dec: 1102873540)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x17001F9F (dec: 385884063), parent name: 'CONTROL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0xA20DEC6D (dec: -1576145811), parent name: 'CONTROL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x075F38E7 (dec: 123680999), parent name: 'CONTROL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x2F4E99A4 (dec: 793680292), parent name: 'CONTROL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x3887BE3B (dec: 948420155), parent name: 'CONTROL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_109fake // hashcode: 0x745D7876 (dec: 1952282742)
{
	struct CONTROL_105fake Cinematic; // size=28, offset=0 //  hashcode: 0x7B61969E (dec: 2069993118), parent name: 'CONTROL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CONTROL_106fake Idle;	  // size=20, offset=28 //  hashcode: 0x1384CDB5 (dec: 327470517), parent name: 'CONTROL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CONTROL_107fake Behind;	// size=28, offset=48 //  hashcode: 0x40741E2F (dec: 1081351727), parent name: 'CONTROL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CONTROL_108fake Follow;	// size=20, offset=76 //  hashcode: 0xAEB705F3 (dec: -1363737101), parent name: 'CONTROL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union CONTROL_203fake // Hashcode: 0xA503E0F9 (dec: -1526472455)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct CONTROL_219fake // hashcode: 0x77040EFD (dec: 1996754685)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x68FB22BA (dec: 1761288890), parent name: 'CONTROL_219fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0xE5B1134C (dec: -441380020), parent name: 'CONTROL_219fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CONTROL_220fake // hashcode: 0xE61284BB (dec: -434993989)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x9C37C917 (dec: -1674065641), parent name: 'CONTROL_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x80C11953 (dec: -2134828717), parent name: 'CONTROL_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0xE8271B95 (dec: -400090219), parent name: 'CONTROL_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x6D10EA70 (dec: 1829825136), parent name: 'CONTROL_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x51A47B2E (dec: 1369733934), parent name: 'CONTROL_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x99E167DF (dec: -1713281057), parent name: 'CONTROL_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union CONTROL_221fake // Hashcode: 0x5E10B5AC (dec: 1578153388)
{
	struct CONTROL_219fake flame; // size=8, offset=0
	struct CONTROL_220fake phys;  // size=12, offset=0
};

struct __Force // hashcode: 0x2CC8F311 (dec: 751366929)
{
	int Type;					// size=0, offset=0 //  hashcode: 0x70C84DDE (dec: 1892175326), parent name: '__Force', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Vector LinearForce; // size=12, offset=4 //  hashcode: 0x3FC324EB (dec: 1069753579), parent name: '__Force', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Friction;				// size=0, offset=16 //  hashcode: 0x71E1EF58 (dec: 1910632280), parent name: '__Force', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __Idle // hashcode: 0xA4E3256E (dec: -1528617618)
{
	unsigned char anim;   // size=0, offset=0 //  hashcode: 0xD2137F84 (dec: -770474108), parent name: '__Idle', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char frame;  // size=0, offset=1 //  hashcode: 0x799C3668 (dec: 2040280680), parent name: '__Idle', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char frames; // size=0, offset=2 //  hashcode: 0x1EE54249 (dec: 518341193), parent name: '__Idle', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;   // size=0, offset=3 //  hashcode: 0x30265BB4 (dec: 807820212), parent name: '__Idle', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __VAnim // hashcode: 0xDC662191 (dec: -597286511)
{
	unsigned char anim0;  // size=0, offset=0 //  hashcode: 0x262CCF73 (dec: 640470899), parent name: '__VAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char anim1;  // size=0, offset=1 //  hashcode: 0x8418CDAC (dec: -2078749268), parent name: '__VAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char anim2;  // size=0, offset=2 //  hashcode: 0xE395D30D (dec: -476720371), parent name: '__VAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char frames; // size=0, offset=3 //  hashcode: 0xA5B27153 (dec: -1515032237), parent name: '__VAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char mode;   // size=0, offset=4 //  hashcode: 0xFA2911F0 (dec: -97971728), parent name: '__VAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char alpha;  // size=0, offset=5 //  hashcode: 0xD445B1D8 (dec: -733629992), parent name: '__VAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short frame; // size=0, offset=6 //  hashcode: 0x080422D7 (dec: 134488791), parent name: '__VAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __SAnim // hashcode: 0xD19E5798 (dec: -778152040)
{
	struct __VAnim *anim;	 // size=8, offset=0 //  hashcode: 0x113E71BA (dec: 289305018), parent name: '__SAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __SAnim *nextAnim; // size=16, offset=4 //  hashcode: 0x5F47203E (dec: 1598496830), parent name: '__SAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	short mode;				  // size=0, offset=8 //  hashcode: 0xB2112A3A (dec: -1307497926), parent name: '__SAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	short data;				  // size=0, offset=10 //  hashcode: 0xC8D67D04 (dec: -925467388), parent name: '__SAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	short speedAdjust;		  // size=0, offset=12 //  hashcode: 0x9080609F (dec: -1870634849), parent name: '__SAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;				  // size=0, offset=14 //  hashcode: 0xC6D91123 (dec: -958852829), parent name: '__SAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __AttackItem // hashcode: 0x6E34BA91 (dec: 1848949393)
{
	unsigned char anim;				   // size=0, offset=0 //  hashcode: 0x6768D52B (dec: 1734923563), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char framesIn;			   // size=0, offset=1 //  hashcode: 0xC1B1EE0C (dec: -1045303796), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char alphaIn;			   // size=0, offset=2 //  hashcode: 0x3FD40076 (dec: 1070858358), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char framesOut;		   // size=0, offset=3 //  hashcode: 0x62D62C80 (dec: 1658203264), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char switchDelay;		   // size=0, offset=4 //  hashcode: 0x2BE5AB37 (dec: 736471863), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char ignoreDelay;		   // size=0, offset=5 //  hashcode: 0x236077C9 (dec: 593524681), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segmentToGlow;	   // size=0, offset=6 //  hashcode: 0x4B566E11 (dec: 1263955473), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char startCollisionFrame; // size=0, offset=7 //  hashcode: 0x1F01BA83 (dec: 520206979), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char handsToCollide;	  // size=0, offset=8 //  hashcode: 0xB323E832 (dec: -1289492430), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char endCollisionFrame;   // size=0, offset=9 //  hashcode: 0x0470BC7E (dec: 74497150), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char ribbonStartFrame;	// size=0, offset=10 //  hashcode: 0x6E8EC54B (dec: 1854850379), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char ribbonStartSegment;  // size=0, offset=11 //  hashcode: 0xE530D0E7 (dec: -449785625), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char ribbonEndSegment;	// size=0, offset=12 //  hashcode: 0x0E8F2D1D (dec: 244264221), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char ribbonLifeTime;	  // size=0, offset=13 //  hashcode: 0x1FD478D9 (dec: 534018265), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char ribbonFaceLifeTime;  // size=0, offset=14 //  hashcode: 0x70FF4D3B (dec: 1895779643), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char knockBackFrames;	 // size=0, offset=15 //  hashcode: 0x9FD021FA (dec: -1613749766), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char glowFadeInFrames;	// size=0, offset=16 //  hashcode: 0x49B0AE13 (dec: 1236315667), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char glowFadeOutFrames;   // size=0, offset=17 //  hashcode: 0x706C7C86 (dec: 1886157958), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short ribbonStartOpacity; // size=0, offset=18 //  hashcode: 0x8D640D50 (dec: -1922822832), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long ribbonStartColor;	// size=0, offset=20 //  hashcode: 0x8B36576F (dec: -1959372945), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long ribbonEndColor;	  // size=0, offset=24 //  hashcode: 0xEE5DC004 (dec: -295845884), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long glowColor;		   // size=0, offset=28 //  hashcode: 0x535BB8A4 (dec: 1398519972), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short knockBackDistance;  // size=0, offset=32 //  hashcode: 0xBD658B10 (dec: -1117418736), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short hitPowerScale;	  // size=0, offset=34 //  hashcode: 0xBFE54987 (dec: -1075492473), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __ThrowItem // hashcode: 0xABF5F7A3 (dec: -1409943645)
{
	unsigned char prepAnim;				   // size=0, offset=0 //  hashcode: 0xBE13C27E (dec: -1106001282), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char prepAnimFramesIn;		   // size=0, offset=1 //  hashcode: 0xA672A5BA (dec: -1502435910), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char prepAnimAlphaIn;		   // size=0, offset=2 //  hashcode: 0x4C22D5A2 (dec: 1277351330), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char coilAnim;				   // size=0, offset=3 //  hashcode: 0x8E112CE0 (dec: -1911477024), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char coilAnimFramesIn;		   // size=0, offset=4 //  hashcode: 0xB2751737 (dec: -1300949193), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char coilAnimAlphaIn;		   // size=0, offset=5 //  hashcode: 0xA8F88A3E (dec: -1460106690), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char throwAnim;			   // size=0, offset=6 //  hashcode: 0x015F43F7 (dec: 23020535), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char throwAnimFramesInFactor; // size=0, offset=7 //  hashcode: 0x41FEF410 (dec: 1107227664), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char throwFrameToLaunch;	  // size=0, offset=8 //  hashcode: 0x10E04183 (dec: 283132291), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char framesOut;			   // size=0, offset=9 //  hashcode: 0x77579E20 (dec: 2002230816), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short launchPointX;					   // size=0, offset=10 //  hashcode: 0xCD6A84BE (dec: -848657218), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short launchPointY;					   // size=0, offset=12 //  hashcode: 0x4B997CE0 (dec: 1268350176), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short launchPointZ;					   // size=0, offset=14 //  hashcode: 0xA0C3BAFC (dec: -1597785348), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxXRotation;					   // size=0, offset=16 //  hashcode: 0xA7991854 (dec: -1483138988), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minXRotation;					   // size=0, offset=18 //  hashcode: 0xDFEDDE75 (dec: -538059147), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxZRotation;					   // size=0, offset=20 //  hashcode: 0x8436C7EA (dec: -2076784662), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minZRotation;					   // size=0, offset=22 //  hashcode: 0x157E9C51 (dec: 360619089), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short velocity;						   // size=0, offset=24 //  hashcode: 0xC3708BBE (dec: -1016034370), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short gravity;						   // size=0, offset=26 //  hashcode: 0x381F02F8 (dec: 941556472), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short coilRot;						   // size=0, offset=28 //  hashcode: 0xBF528072 (dec: -1085112206), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short selfAdjustingFlag;			   // size=0, offset=30 //  hashcode: 0x4307A220 (dec: 1124573728), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __EngagedInstance // hashcode: 0x504DFFAD (dec: 1347289005)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0x4F3203E5 (dec: 1328677861), parent name: '__EngagedInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long distance;		// size=0, offset=4 //  hashcode: 0x3BF42CCF (dec: 1005857999), parent name: '__EngagedInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __FitPoint // hashcode: 0xFA3F31C2 (dec: -96521790)
{
	short x; // size=0, offset=0 //  hashcode: 0x0E62A52F (dec: 241345839), parent name: '__FitPoint', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0x9A12F7AB (dec: -1710032981), parent name: '__FitPoint', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __SensoryData // hashcode: 0x3A2E27FD (dec: 976103421)
{
	int Flags;							   // size=0, offset=0 //  hashcode: 0x32BB083D (dec: 851118141), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector ForwardNormal;		   // size=8, offset=4 //  hashcode: 0xD6EC8D33 (dec: -689140429), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector AboveNormal;		   // size=8, offset=12 //  hashcode: 0xC4BDD5D4 (dec: -994191916), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector BelowNormal;		   // size=8, offset=20 //  hashcode: 0x9DE81916 (dec: -1645733610), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector BelowPoint;			   // size=8, offset=28 //  hashcode: 0xF451E8C5 (dec: -195958587), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector Delta;				   // size=8, offset=36 //  hashcode: 0x56DAC50C (dec: 1457177868), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *HitMonster;		   // size=616, offset=44 //  hashcode: 0x088BC1B5 (dec: 143376821), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *CurrentAutoFace;	 // size=616, offset=48 //  hashcode: 0xDB3D5BD1 (dec: -616735791), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *LastAutoFace;		   // size=616, offset=52 //  hashcode: 0x30FEF2DE (dec: 822014686), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *Portal;			   // size=616, offset=56 //  hashcode: 0x227CE75F (dec: 578611039), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __EngagedInstance *EngagedList; // size=8, offset=60 //  hashcode: 0x9A766834 (dec: -1703516108), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long EngagedMask;			   // size=0, offset=64 //  hashcode: 0x14F31D2E (dec: 351477038), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Vector lookAtPoint;			   // size=12, offset=68 //  hashcode: 0xF1A89AC6 (dec: -240608570), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long heldClass;			   // size=0, offset=80 //  hashcode: 0x7A66A389 (dec: 2053546889), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __Player // hashcode: 0x0712E7A5 (dec: 118679461)
{
	int footPrint;						 // size=0, offset=0 //  hashcode: 0x2D1D761F (dec: 756905503), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __CharacterState State;		 // size=860, offset=4 //  hashcode: 0x1F6F6473 (dec: 527393907), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int Mode;							 // size=0, offset=864 //  hashcode: 0xC900E96B (dec: -922687125), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int Anim;							 // size=0, offset=868 //  hashcode: 0xA60808D8 (dec: -1509422888), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int RotationSegment;				 // size=0, offset=872 //  hashcode: 0x9D1BA26F (dec: -1659133329), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector iVelocity;			 // size=8, offset=876 //  hashcode: 0x2221B914 (dec: 572635412), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int Magnitude;						 // size=0, offset=884 //  hashcode: 0x2DEA1796 (dec: 770316182), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int input;							 // size=0, offset=888 //  hashcode: 0x797F3FCC (dec: 2038382540), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int lastInput;						 // size=0, offset=892 //  hashcode: 0xDF329EA1 (dec: -550330719), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int ZDirection;						 // size=0, offset=896 //  hashcode: 0xBC8F5B30 (dec: -1131455696), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Bearing;						 // size=0, offset=900 //  hashcode: 0xC488C97E (dec: -997668482), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short LastBearing;					 // size=0, offset=902 //  hashcode: 0xA238A9F5 (dec: -1573344779), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int steeringMode;					 // size=0, offset=904 //  hashcode: 0x7E126845 (dec: 2115135557), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short steeringVelocity;				 // size=0, offset=908 //  hashcode: 0xECE46814 (dec: -320575468), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short steeringAcceleration;			 // size=0, offset=910 //  hashcode: 0x94D6D6A5 (dec: -1797859675), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int steeringLockRotation;			 // size=0, offset=912 //  hashcode: 0xCE5A0423 (dec: -832961501), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short movementMinRate;				 // size=0, offset=916 //  hashcode: 0x73BB6D13 (dec: 1941662995), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short movementMaxRate;				 // size=0, offset=918 //  hashcode: 0xB6992ACC (dec: -1231476020), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short movementMinAnalog;			 // size=0, offset=920 //  hashcode: 0x275837D9 (dec: 660092889), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short movementMaxAnalog;			 // size=0, offset=922 //  hashcode: 0x216FB9F7 (dec: 560970231), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __SensoryData Senses;		 // size=84, offset=924 //  hashcode: 0x30C01728 (dec: 817895208), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *attachedPlatform;  // size=616, offset=1008 //  hashcode: 0x35C751F2 (dec: 902255090), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dropOffHeight;				 // size=0, offset=1012 //  hashcode: 0xA98F3A09 (dec: -1450231287), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fallZVelocity;				 // size=0, offset=1014 //  hashcode: 0x3502EA36 (dec: 889383478), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short HealthScale;					 // size=0, offset=1016 //  hashcode: 0xC308B148 (dec: -1022840504), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short HealthBalls;					 // size=0, offset=1018 //  hashcode: 0x598F9714 (dec: 1502582548), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int HitPoints;						 // size=0, offset=1020 //  hashcode: 0x6E9298D3 (dec: 1855101139), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int DamageFrequency;				 // size=0, offset=1024 //  hashcode: 0xA51209D9 (dec: -1525544487), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int invincibleTimer;				 // size=0, offset=1028 //  hashcode: 0x6EE8824E (dec: 1860731470), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int Abilities;						 // size=0, offset=1032 //  hashcode: 0xF400554E (dec: -201304754), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *GlyphSystem;		 // size=616, offset=1036 //  hashcode: 0x30DEA6D0 (dec: 819898064), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short GlyphManaBalls;		 // size=0, offset=1040 //  hashcode: 0x8BD2B739 (dec: -1949124807), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short GlyphManaMax;		 // size=0, offset=1042 //  hashcode: 0x35903A23 (dec: 898644515), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __FitPoint *constrictData;	// size=4, offset=1044 //  hashcode: 0x43CAF4F6 (dec: 1137374454), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short constrictIndex;				 // size=0, offset=1048 //  hashcode: 0xB5FABF6D (dec: -1241858195), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short constrictWaitIndex;			 // size=0, offset=1050 //  hashcode: 0x15A72622 (dec: 363275810), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector constrictCenter;	 // size=8, offset=1052 //  hashcode: 0xC768BA27 (dec: -949437913), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short constrictFlag;				 // size=0, offset=1060 //  hashcode: 0x8AF25BF1 (dec: -1963828239), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short constrictGoodCircle;			 // size=0, offset=1062 //  hashcode: 0x787DAE0C (dec: 2021502476), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long constrictXTotal;		 // size=0, offset=1064 //  hashcode: 0x7B7EE37F (dec: 2071913343), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long constrictYTotal;		 // size=0, offset=1068 //  hashcode: 0x87B8102C (dec: -2017980372), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *soulReaver;		 // size=616, offset=1072 //  hashcode: 0x67B08A5C (dec: 1739623004), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long currentSoulReaver;	 // size=0, offset=1076 //  hashcode: 0x72FC1275 (dec: 1929122421), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int CurrentPlane;					 // size=0, offset=1080 //  hashcode: 0xA8666835 (dec: -1469683659), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int slipSlope;						 // size=0, offset=1084 //  hashcode: 0xC5D240EF (dec: -976076561), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long idleCount;			 // size=0, offset=1088 //  hashcode: 0x51DA042F (dec: 1373242415), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *idleInstance;		 // size=616, offset=1092 //  hashcode: 0x0CF91658 (dec: 217650776), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __AttackItem *attack;		 // size=36, offset=1096 //  hashcode: 0xCAF36990 (dec: -890017392), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int attackFlags;					 // size=0, offset=1100 //  hashcode: 0x5DB3536B (dec: 1572033387), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int currentAttack;					 // size=0, offset=1104 //  hashcode: 0xB685E2CE (dec: -1232739634), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *attackCurrentHit;  // size=616, offset=1108 //  hashcode: 0x2D1E0854 (dec: 756942932), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *attackLastHit;	 // size=616, offset=1112 //  hashcode: 0x5CF7680B (dec: 1559717899), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _FXGlowEffect *glowEffect;	// size=44, offset=1116 //  hashcode: 0x1F347697 (dec: 523531927), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *attackedBy;		 // size=616, offset=1120 //  hashcode: 0xC062A5F1 (dec: -1067276815), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __ThrowItem *throwData;		 // size=32, offset=1124 //  hashcode: 0x9AA9787D (dec: -1700169603), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int throwMode;						 // size=0, offset=1128 //  hashcode: 0xE2742BB2 (dec: -495703118), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position throwTarget;		 // size=6, offset=1132 //  hashcode: 0x845893D8 (dec: -2074569768), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *throwInstance;	 // size=616, offset=1140 //  hashcode: 0xE3C6B733 (dec: -473516237), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short throwXRot;					 // size=0, offset=1144 //  hashcode: 0x782B03E3 (dec: 2016084963), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short throwZRot;					 // size=0, offset=1146 //  hashcode: 0x8B0F3A73 (dec: -1961936269), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int throwReturnRot;					 // size=0, offset=1148 //  hashcode: 0x87F5ABBF (dec: -2013942849), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __MessageQueue padCommands;   // size=136, offset=1152 //  hashcode: 0x9EF4F4C2 (dec: -1628113726), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*returnState)();				 // size=0, offset=1288 //  hashcode: 0x1557F996 (dec: 358087062), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long passedMask;			 // size=0, offset=1292 //  hashcode: 0xC91EF5B0 (dec: -920717904), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type extraRot;	// size=6, offset=1296 //  hashcode: 0xA919EB9F (dec: -1457919073), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	long blankPad;						 // size=0, offset=1304 //  hashcode: 0xC8E2C15F (dec: -924663457), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int effectsFlags;					 // size=0, offset=1308 //  hashcode: 0x838678D0 (dec: -2088339248), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short effectsFadeSource;			 // size=0, offset=1312 //  hashcode: 0x8440EF21 (dec: -2076119263), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short effectsFadeDest;				 // size=0, offset=1314 //  hashcode: 0xC9DD08F1 (dec: -908261135), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int effectsFadeStep;				 // size=0, offset=1316 //  hashcode: 0x51053C65 (dec: 1359297637), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int effectsFadeSteps;				 // size=0, offset=1320 //  hashcode: 0xD7B74887 (dec: -675854201), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short autoFaceZone;					 // size=0, offset=1324 //  hashcode: 0x52D21507 (dec: 1389499655), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short autoFaceAngle;				 // size=0, offset=1326 //  hashcode: 0xDC0B489E (dec: -603240290), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int autoFaceLastRootAngle;			 // size=0, offset=1328 //  hashcode: 0x1AE52EB9 (dec: 451227321), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int autoFaceRootAngle;				 // size=0, offset=1332 //  hashcode: 0xEB1B7294 (dec: -350522732), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int autoFaceTrueAngle;				 // size=0, offset=1336 //  hashcode: 0x9779B67E (dec: -1753631106), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int autoFaceAnim;					 // size=0, offset=1340 //  hashcode: 0xA62DBB24 (dec: -1506952412), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int autoFaceLastAnim;				 // size=0, offset=1344 //  hashcode: 0x4F0F22D3 (dec: 1326392019), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nothingCounter;					 // size=0, offset=1348 //  hashcode: 0x60D0BDC3 (dec: 1624292803), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int timeAccumulator;				 // size=0, offset=1352 //  hashcode: 0x18EBFFF5 (dec: 418119669), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position puppetMoveToPoint;  // size=6, offset=1356 //  hashcode: 0xC7F832C1 (dec: -940035391), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position puppetRotToPoint;   // size=6, offset=1362 //  hashcode: 0x07B2BAAD (dec: 129153709), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int puppetHint;						 // size=0, offset=1368 //  hashcode: 0x31BB2E54 (dec: 834350676), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int soundModifier;					 // size=0, offset=1372 //  hashcode: 0x25AE720A (dec: 632189450), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short alarmTable;					 // size=0, offset=1376 //  hashcode: 0x57829D4B (dec: 1468177739), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short terminator;					 // size=0, offset=1378 //  hashcode: 0xEEA1A58F (dec: -291396209), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short swimSpeedAdjustment;			 // size=0, offset=1380 //  hashcode: 0x25D42462 (dec: 634659938), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short swimTargetSpeed;				 // size=0, offset=1382 //  hashcode: 0x5769F143 (dec: 1466560835), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long soundHandle;			 // size=0, offset=1384 //  hashcode: 0x23DA0D32 (dec: 601492786), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	long soundTimer;					 // size=0, offset=1388 //  hashcode: 0xAB7F34B1 (dec: -1417726799), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	long soundTotalTime;				 // size=0, offset=1392 //  hashcode: 0xB8928B7D (dec: -1198355587), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long soundDistance;		 // size=0, offset=1396 //  hashcode: 0x46D67C57 (dec: 1188461655), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundStartPitch;				 // size=0, offset=1400 //  hashcode: 0x3DC68551 (dec: 1036420433), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundEndPitch;				 // size=0, offset=1402 //  hashcode: 0x13683BF7 (dec: 325598199), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundStartVolume;				 // size=0, offset=1404 //  hashcode: 0x8C774C1A (dec: -1938338790), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundEndVolume;				 // size=0, offset=1406 //  hashcode: 0xCA372314 (dec: -902356204), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long soundHandle2;			 // size=0, offset=1408 //  hashcode: 0x7BA1A411 (dec: 2074190865), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	long soundTimer2;					 // size=0, offset=1412 //  hashcode: 0x92A8D3AA (dec: -1834429526), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	long soundTotalTime2;				 // size=0, offset=1416 //  hashcode: 0x02286FF2 (dec: 36204530), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long soundDistance2;		 // size=0, offset=1420 //  hashcode: 0xC7FFDB85 (dec: -939533435), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundStartPitch2;				 // size=0, offset=1424 //  hashcode: 0xE6804946 (dec: -427800250), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundEndPitch2;				 // size=0, offset=1426 //  hashcode: 0xAEF89055 (dec: -1359441835), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundStartVolume2;			 // size=0, offset=1428 //  hashcode: 0x41229AA4 (dec: 1092786852), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundEndVolume2;				 // size=0, offset=1430 //  hashcode: 0x7AF81508 (dec: 2063078664), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	long soundTimerNext;				 // size=0, offset=1432 //  hashcode: 0xA09EEC06 (dec: -1600197626), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long soundTimerData;		 // size=0, offset=1436 //  hashcode: 0x723DAC05 (dec: 1916644357), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long forcedGlideSpeed;		 // size=0, offset=1440 //  hashcode: 0x7E2767EE (dec: 2116511726), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector collisionEdgeOffset; // size=8, offset=1444 //  hashcode: 0x799B382E (dec: 2040215598), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __SAnim *currentSAnim;		 // size=16, offset=1452 //  hashcode: 0x42E31AF8 (dec: 1122179832), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long playerEvent;			 // size=0, offset=1456 //  hashcode: 0x4C9EEDE4 (dec: 1285484004), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long playerEventHistory;	// size=0, offset=1460 //  hashcode: 0x021A7BAC (dec: 35290028), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int currentHint;					 // size=0, offset=1464 //  hashcode: 0x76E0ED44 (dec: 1994452292), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct __Force Force;

typedef struct __Idle Idle;

typedef struct __VAnim VAnim;

typedef struct __SAnim SAnim;

typedef struct __AttackItem AttackItem;

typedef struct __ThrowItem ThrowItem;

typedef struct __EngagedInstance EngagedInstance;

typedef struct __FitPoint FitPoint;

typedef struct __SensoryData SensoryData;

typedef struct __Player Player;

extern void SetPhysics(struct _Instance *instance, short gravity, long x, long y, long z); // 0x8009A1B0

extern void ResetPhysics(struct _Instance *instance, short gravity); // 0x8009A224

extern void SetDampingPhysics(struct _Instance *instance, int damping); // 0x8009A2E0

extern void SetImpulsePhysics(struct _Instance *instance, struct __Player *player); // 0x8009A388

extern void SetDropPhysics(struct _Instance *instance, struct __Player *player); // 0x8009A4B8

extern void InitExternalForces(struct __Force *Forces, int MaxForces); // 0x8009A4F0

extern void SetExternalForce(struct __Force *In, short x, short y, short z, int Space, int Friction); // 0x8009A530

extern void SetExternalTransitionForce(struct __Force *in, struct _Instance *instance, int time, int x, int y, int z); // 0x8009A570

extern void ProcessPhysics(struct __Player *player, struct __CharacterState *In, int CurrentSection, int Mode); // 0x8009A5D8

extern void ApplyExternalLocalForces(struct __Player *player, struct _Instance *instance, struct __Force *Forces, int MaxForces, struct _Vector *Out); // 0x8009A7D0

#endif
