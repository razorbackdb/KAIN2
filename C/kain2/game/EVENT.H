#ifndef EVENT_H
#define EVENT_H

static struct ScriptPCode *currentActionScript; // offset 0x800D2738

static struct Event *currentEventInstance; // offset 0x800D2734

static long CurrentEventLine; // offset 0x800CF53C

static struct Level *CurrentPuzzleLevel; // offset 0x800D27D0

static short *EventAbortedPosition; // offset 0x800D273C

static short EventAbortLine; // offset 0x800CF534

static long EventCurrentEventIndex; // offset 0x800CF540

static short EventJustRecievedTimer; // offset 0x800CF536

extern struct _Instance(*eventListArray[20][10]); // offset 0x800D2B0C

extern long eventListNumInstances[20]; // offset 0x800D2A1C

static struct EventTimer eventTimerArray[24]; // offset 0x800D27D4

extern struct HintSystemStruct gHintSystem; // offset 0x800D2AFC

static long MoveCodeStreamExtra; // offset 0x800CF538

static long numActiveEventTimers; // offset 0x800D2A14

extern struct SignalResetStruct ResetSignalArray[16]; // offset 0x800D2A74

static struct WaterLevelProcess WaterLevelArray[5]; // offset 0x800D2744

struct EVENT_73fake // hashcode: 0xA70F7DDA (dec: -1492156966)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x4019FE00 (dec: 1075445248), parent name: 'EVENT_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0xEE4D512E (dec: -296922834), parent name: 'EVENT_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_74fake // hashcode: 0xE126AEFD (dec: -517558531)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x0F8F74DC (dec: 261059804), parent name: 'EVENT_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xF8781E5A (dec: -126345638), parent name: 'EVENT_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_75fake // hashcode: 0x47A387C3 (dec: 1201899459)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x8CC51166 (dec: -1933242010), parent name: 'EVENT_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x254AB6AE (dec: 625653422), parent name: 'EVENT_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union EVENT_76fake // Hashcode: 0x5ECA26A1 (dec: 1590306465)
{
	struct EVENT_73fake callback; // size=8, offset=0
	struct EVENT_74fake vector;   // size=12, offset=0
	struct EVENT_75fake quat;	 // size=16, offset=0
};

union EVENT_77fake // Hashcode: 0xCEC39DA9 (dec: -826040919)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union EVENT_78fake // Hashcode: 0xCE09E508 (dec: -838212344)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct EVENT_79fake // hashcode: 0x26076F18 (dec: 638021400)
{
	union EVENT_78fake size; // size=4, offset=0 //  hashcode: 0xDEFDD4D4 (dec: -553790252), parent name: 'EVENT_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_80fake // hashcode: 0x6D33FB48 (dec: 1832123208)
{
	short x;				// size=0, offset=0 //  hashcode: 0xCAAE60A0 (dec: -894541664), parent name: 'EVENT_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x262F71F0 (dec: 640643568), parent name: 'EVENT_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x0428F4F1 (dec: 69793009), parent name: 'EVENT_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xAA0E12BF (dec: -1441918273), parent name: 'EVENT_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x526168AD (dec: 1382115501), parent name: 'EVENT_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_81fake // hashcode: 0x6F49F406 (dec: 1867117574)
{
	long index; // size=0, offset=0 //  hashcode: 0xD4B1BF7A (dec: -726548614), parent name: 'EVENT_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x996D7764 (dec: -1720879260), parent name: 'EVENT_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_82fake // hashcode: 0xDF02632C (dec: -553491668)
{
	long index; // size=0, offset=0 //  hashcode: 0xBD5D7560 (dec: -1117948576), parent name: 'EVENT_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xEE62EB6C (dec: -295507092), parent name: 'EVENT_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_83fake // hashcode: 0x464357FC (dec: 1178818556)
{
	long index; // size=0, offset=0 //  hashcode: 0x4CB87595 (dec: 1287157141), parent name: 'EVENT_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x4CFA57DA (dec: 1291474906), parent name: 'EVENT_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_84fake // hashcode: 0x7E32B62B (dec: 2117252651)
{
	long time;  // size=0, offset=0 //  hashcode: 0xCD93FC2F (dec: -845939665), parent name: 'EVENT_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xDF60F4AC (dec: -547294036), parent name: 'EVENT_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_85fake // hashcode: 0xF4C13F7A (dec: -188661894)
{
	long action;   // size=0, offset=0 //  hashcode: 0x9B971F28 (dec: -1684594904), parent name: 'EVENT_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x3A83A023 (dec: 981704739), parent name: 'EVENT_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_86fake // hashcode: 0x747552F2 (dec: 1953846002)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x7A41E9C7 (dec: 2051140039), parent name: 'EVENT_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xC156A53E (dec: -1051286210), parent name: 'EVENT_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_87fake // hashcode: 0x2CEA8178 (dec: 753566072)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x0766A6F0 (dec: 124167920), parent name: 'EVENT_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x89759535 (dec: -1988782795), parent name: 'EVENT_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_88fake // hashcode: 0x8B806EDC (dec: -1954517284)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x2E7B57CC (dec: 779835340), parent name: 'EVENT_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x23BC331B (dec: 599536411), parent name: 'EVENT_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_89fake // hashcode: 0x2B2138ED (dec: 723597549)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x64CEE4BE (dec: 1691280574), parent name: 'EVENT_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xCBFA91E4 (dec: -872771100), parent name: 'EVENT_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xAAD21FE3 (dec: -1429069853), parent name: 'EVENT_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x971931D4 (dec: -1759956524), parent name: 'EVENT_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x070B7687 (dec: 118191751), parent name: 'EVENT_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_90fake // hashcode: 0x989B695B (dec: -1734645413)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x78A031CF (dec: 2023764431), parent name: 'EVENT_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x0CDF766C (dec: 215971436), parent name: 'EVENT_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_91fake // hashcode: 0xAC80892E (dec: -1400862418)
{
	short index;					// size=0, offset=0 //  hashcode: 0xF4CB905C (dec: -187985828), parent name: 'EVENT_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x43C5B635 (dec: 1137030709), parent name: 'EVENT_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x473FB3CC (dec: 1195357132), parent name: 'EVENT_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x90019EEE (dec: -1878941970), parent name: 'EVENT_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_92fake // hashcode: 0x1AB120AB (dec: 447815851)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x99425A2B (dec: -1723704789), parent name: 'EVENT_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x8195D2CA (dec: -2120887606), parent name: 'EVENT_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x016F918F (dec: 24088975), parent name: 'EVENT_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_93fake // hashcode: 0x958C0471 (dec: -1785985935)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xD92AEE88 (dec: -651497848), parent name: 'EVENT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x0F8F0239 (dec: 261030457), parent name: 'EVENT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xBCD73123 (dec: -1126747869), parent name: 'EVENT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x86B69A78 (dec: -2034853256), parent name: 'EVENT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x54F512C1 (dec: 1425347265), parent name: 'EVENT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xB1510263 (dec: -1320091037), parent name: 'EVENT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xD689FEB3 (dec: -695599437), parent name: 'EVENT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_94fake // hashcode: 0xFB4E4BC0 (dec: -78754880)
{
	long index;  // size=0, offset=0 //  hashcode: 0x413EA314 (dec: 1094624020), parent name: 'EVENT_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x55DC812A (dec: 1440514346), parent name: 'EVENT_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_95fake // hashcode: 0x002688CD (dec: 2525389)
{
	short type; // size=0, offset=0 //  hashcode: 0xE1700605 (dec: -512752123), parent name: 'EVENT_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x5154C18D (dec: 1364509069), parent name: 'EVENT_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_96fake // hashcode: 0x399B26D5 (dec: 966469333)
{
	long time;   // size=0, offset=0 //  hashcode: 0x1DA2B07D (dec: 497201277), parent name: 'EVENT_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x4A6863E3 (dec: 1248355299), parent name: 'EVENT_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_97fake // hashcode: 0x763E0DBD (dec: 1983778237)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x4734930C (dec: 1194627852), parent name: 'EVENT_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x21F6606E (dec: 569794670), parent name: 'EVENT_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_98fake // hashcode: 0xFEAC81B2 (dec: -22249038)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xB7692FB4 (dec: -1217843276), parent name: 'EVENT_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x12A4C6D1 (dec: 312788689), parent name: 'EVENT_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_99fake // hashcode: 0x8BE69B09 (dec: -1947821303)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xCF138C6D (dec: -820802451), parent name: 'EVENT_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x38EE31C0 (dec: 955134400), parent name: 'EVENT_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_100fake // hashcode: 0x51065801 (dec: 1359370241)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x2B0CFC5F (dec: 722271327), parent name: 'EVENT_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x9C9883AE (dec: -1667726418), parent name: 'EVENT_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x41609DBF (dec: 1096850879), parent name: 'EVENT_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x29856815 (dec: 696608789), parent name: 'EVENT_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_101fake // hashcode: 0xA98238EA (dec: -1451083542)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xF0C885B2 (dec: -255294030), parent name: 'EVENT_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x01BA2447 (dec: 28976199), parent name: 'EVENT_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x213E376E (dec: 557725550), parent name: 'EVENT_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x879E9EF8 (dec: -2019647752), parent name: 'EVENT_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x1B476255 (dec: 457663061), parent name: 'EVENT_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union EVENT_102fake // Hashcode: 0xA1EA8675 (dec: -1578465675)
{
	struct EVENT_79fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	 // size=24, offset=0
	struct EVENT_80fake teleport;	 // size=16, offset=0
	struct EVENT_81fake cameraValue;  // size=8, offset=0
	struct EVENT_82fake miscValue;	// size=8, offset=0
	struct EVENT_83fake logicValue;   // size=8, offset=0
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
	struct EVENT_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				  // size=0, offset=0
	long cameraRestore;				  // size=0, offset=0
	struct _BGObject *bgObject;		  // size=24, offset=0
	long value[2];					  // size=8, offset=0
	struct EVENT_85fake sound;		  // size=12, offset=0
	void *intro;					  // size=0, offset=0
	long deathZ;					  // size=0, offset=0
	struct EVENT_86fake dsignal;	  // size=8, offset=0
	void *mirror;					  // size=0, offset=0
	long fogNear;					  // size=0, offset=0
	long fogFar;					  // size=0, offset=0
	struct EVENT_87fake gotoFrame;	// size=8, offset=0
	struct EVENT_88fake changeModel;  // size=8, offset=0
	void *vmObject;					  // size=0, offset=0
	struct EVENT_89fake logic;		  // size=8, offset=0
	void *callSignal;				  // size=0, offset=0
	struct _SVector offset;			  // size=8, offset=0
	struct Signal *gotoLabel;		  // size=0, offset=0
	struct Signal *gosubLabel;		  // size=0, offset=0
	struct EVENT_90fake control;	  // size=8, offset=0
	struct EVENT_91fake zSignal;	  // size=12, offset=0
	struct EVENT_92fake StreamLevel;  // size=24, offset=0
	struct EVENT_93fake shards;		  // size=12, offset=0
	struct EVENT_94fake cameraSpline; // size=8, offset=0
	struct EVENT_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				  // size=0, offset=0
	struct EVENT_96fake introFX;	  // size=8, offset=0
	struct EVENT_97fake introActive;  // size=8, offset=0
	struct EVENT_98fake levelChange;  // size=18, offset=0
	long blendStart;				  // size=0, offset=0
	struct EVENT_99fake setTimes;	 // size=8, offset=0
	struct EVENT_100fake color;		  // size=4, offset=0
	struct EVENT_101fake print;		  // size=12, offset=0
	long slideAngle;				  // size=0, offset=0
};

union EVENT_103fake // Hashcode: 0xD7BA5F82 (dec: -675651710)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union EVENT_108fake // Hashcode: 0x9D43D902 (dec: -1656497918)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct EVENT_110fake // hashcode: 0x7358D14B (dec: 1935200587)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xCACFD6F4 (dec: -892348684), parent name: 'EVENT_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x7E4B9EE1 (dec: 2118885089), parent name: 'EVENT_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x07D6D4EC (dec: 131519724), parent name: 'EVENT_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xC21F05AA (dec: -1038154326), parent name: 'EVENT_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x0AC48A01 (dec: 180652545), parent name: 'EVENT_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xD98903BB (dec: -645332037), parent name: 'EVENT_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x22C94758 (dec: 583616344), parent name: 'EVENT_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_111fake // hashcode: 0x4A00CAFA (dec: 1241565946)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x2BC20D3E (dec: 734137662), parent name: 'EVENT_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xB2D0AB0D (dec: -1294947571), parent name: 'EVENT_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xEF742742 (dec: -277600446), parent name: 'EVENT_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_112fake // hashcode: 0x7688376D (dec: 1988638573)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xBDBCBA5D (dec: -1111704995), parent name: 'EVENT_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xB368C86C (dec: -1284978580), parent name: 'EVENT_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xC2DE40BB (dec: -1025621829), parent name: 'EVENT_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x3A1A3CA8 (dec: 974797992), parent name: 'EVENT_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x648D6700 (dec: 1686988544), parent name: 'EVENT_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_113fake // hashcode: 0x3AB8C749 (dec: 985188169)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x211A934B (dec: 555389771), parent name: 'EVENT_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x274A8691 (dec: 659195537), parent name: 'EVENT_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0xC65547C3 (dec: -967489597), parent name: 'EVENT_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x48348F89 (dec: 1211404169), parent name: 'EVENT_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x8EB19F77 (dec: -1900961929), parent name: 'EVENT_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_114fake // hashcode: 0x8860152B (dec: -2006969045)
{
	struct EVENT_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x12F05616 (dec: 317740566), parent name: 'EVENT_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct EVENT_111fake Idle;		// size=20, offset=28 //  hashcode: 0x54902F4E (dec: 1418735438), parent name: 'EVENT_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct EVENT_112fake Behind;	// size=28, offset=48 //  hashcode: 0x5D3BAE76 (dec: 1564192374), parent name: 'EVENT_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct EVENT_113fake Follow;	// size=20, offset=76 //  hashcode: 0xF1E2CD68 (dec: -236794520), parent name: 'EVENT_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SavedEventSmallVars // hashcode: 0xE3137261 (dec: -485264799)
{
	unsigned char savedID;		   // size=0, offset=0 //  hashcode: 0x0C9ED883 (dec: 211736707), parent name: 'SavedEventSmallVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char shiftedSaveSize; // size=0, offset=1 //  hashcode: 0x0A0D022C (dec: 168624684), parent name: 'SavedEventSmallVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short areaID;				   // size=0, offset=2 //  hashcode: 0xB6A1B5C2 (dec: -1230916158), parent name: 'SavedEventSmallVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char eventNumber;			   // size=0, offset=4 //  hashcode: 0xC306B80D (dec: -1022969843), parent name: 'SavedEventSmallVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char eventVariables[5];		   // size=5, offset=5 //  hashcode: 0x00C4D7FE (dec: 12900350), parent name: 'SavedEventSmallVars', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WaterLevelProcess // hashcode: 0x43FF89D3 (dec: 1140820435)
{
	long flags;						// size=0, offset=0 //  hashcode: 0x65AC427B (dec: 1705788027), parent name: 'WaterLevelProcess', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct BSPTree *bspTree;		// size=36, offset=4 //  hashcode: 0x8BC295C0 (dec: -1950181952), parent name: 'WaterLevelProcess', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _StreamUnit *streamUnit; // size=0, offset=8 //  hashcode: 0x880425E2 (dec: -2012994078), parent name: 'WaterLevelProcess', parent hashcode: 0xFFFFFFFF (dec: -1)
	short oldWaterZ;				// size=0, offset=12 //  hashcode: 0x29AED2B5 (dec: 699323061), parent name: 'WaterLevelProcess', parent hashcode: 0xFFFFFFFF (dec: -1)
	short oldGlobalOffset;			// size=0, offset=14 //  hashcode: 0xDB850091 (dec: -612040559), parent name: 'WaterLevelProcess', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zValueFrom;				// size=0, offset=16 //  hashcode: 0xB6838D0C (dec: -1232892660), parent name: 'WaterLevelProcess', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zValueTo;					// size=0, offset=18 //  hashcode: 0xB553046F (dec: -1252850577), parent name: 'WaterLevelProcess', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxSteps;					// size=0, offset=20 //  hashcode: 0xC0C59FE5 (dec: -1060790299), parent name: 'WaterLevelProcess', parent hashcode: 0xFFFFFFFF (dec: -1)
	long curStep;					// size=0, offset=24 //  hashcode: 0x44F671E6 (dec: 1157001702), parent name: 'WaterLevelProcess', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union EVENT_181fake // Hashcode: 0xEA00FFD7 (dec: -369033257)
{
	struct Intro *intro;	   // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

struct EventInstanceObject // hashcode: 0xC22B6786 (dec: -1037342842)
{
	short id;					// size=0, offset=0 //  hashcode: 0x6DBCCEE0 (dec: 1841090272), parent name: 'EventInstanceObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;				// size=0, offset=2 //  hashcode: 0x4718173F (dec: 1192761151), parent name: 'EventInstanceObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long unitID;				// size=0, offset=4 //  hashcode: 0x83956E14 (dec: -2087358956), parent name: 'EventInstanceObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long introUniqueID;			// size=0, offset=8 //  hashcode: 0x1F6DC8E9 (dec: 527288553), parent name: 'EventInstanceObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=12 //  hashcode: 0xFF6746CF (dec: -10008881), parent name: 'EventInstanceObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	union EVENT_181fake data;   // size=4, offset=16 //  hashcode: 0x98327B6B (dec: -1741522069), parent name: 'EventInstanceObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EventEventObject // hashcode: 0x59DD7B24 (dec: 1507687204)
{
	short id;			 // size=0, offset=0 //  hashcode: 0x9DB55121 (dec: -1649061599), parent name: 'EventEventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short eventNumber;   // size=0, offset=2 //  hashcode: 0x53B7C129 (dec: 1404551465), parent name: 'EventEventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long unitID;		 // size=0, offset=4 //  hashcode: 0x6F4A580F (dec: 1867143183), parent name: 'EventEventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Event *event; // size=0, offset=8 //  hashcode: 0x69364663 (dec: 1765164643), parent name: 'EventEventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EventTGroupObject // hashcode: 0x9ED92E4E (dec: -1629934002)
{
	short id;					// size=0, offset=0 //  hashcode: 0x79FEDB88 (dec: 2046745480), parent name: 'EventTGroupObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short tgroupNumber;			// size=0, offset=2 //  hashcode: 0xAAC86F65 (dec: -1429704859), parent name: 'EventTGroupObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long unitID;				// size=0, offset=4 //  hashcode: 0x3ABD6A27 (dec: 985492007), parent name: 'EventTGroupObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct BSPTree *bspTree;	// size=36, offset=8 //  hashcode: 0x89BD6506 (dec: -1984076538), parent name: 'EventTGroupObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _StreamUnit *stream; // size=0, offset=12 //  hashcode: 0x22B3A822 (dec: 582199330), parent name: 'EventTGroupObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TGroupObject_alt_definition_0002 // hashcode: 0x2189023C (dec: 562627132)
{
	struct BSPTree *bspTree;		// size=36, offset=0 //  hashcode: 0x174C221D (dec: 390865437), parent name: 'TGroupObject_alt_definition_0002', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _StreamUnit *streamUnit; // size=0, offset=4 //  hashcode: 0x85EFE4C8 (dec: -2047875896), parent name: 'TGroupObject_alt_definition_0002', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;					// size=0, offset=8 //  hashcode: 0x34DDDEB2 (dec: 886955698), parent name: 'TGroupObject_alt_definition_0002', parent hashcode: 0xFFFFFFFF (dec: -1)
	short arg[2];					// size=4, offset=12 //  hashcode: 0x4E196F33 (dec: 1310289715), parent name: 'TGroupObject_alt_definition_0002', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AreaObject_alt_definition_0002 // hashcode: 0x28FC6B98 (dec: 687631256)
{
	struct _StreamUnit *streamUnit; // size=0, offset=0 //  hashcode: 0x947D6C72 (dec: -1803719566), parent name: 'AreaObject_alt_definition_0002', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;					// size=0, offset=4 //  hashcode: 0x346DC52F (dec: 879609135), parent name: 'AreaObject_alt_definition_0002', parent hashcode: 0xFFFFFFFF (dec: -1)
	long unitID;					// size=0, offset=8 //  hashcode: 0x343D7503 (dec: 876442883), parent name: 'AreaObject_alt_definition_0002', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union EVENT_183fake // Hashcode: 0xB5B21B00 (dec: -1246618880)
{
	struct _Instance *instance; // size=616, offset=0
	struct _SFXMkr *sfxMarker;  // size=36, offset=0
};

struct EVENT_184fake // hashcode: 0x28B52E5A (dec: 682962522)
{
	long instanceNumber; // size=0, offset=0 //  hashcode: 0x1D2B4E18 (dec: 489377304), parent name: 'EVENT_184fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;		 // size=0, offset=4 //  hashcode: 0x638CDD4F (dec: 1670176079), parent name: 'EVENT_184fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_185fake // hashcode: 0x8B5502FA (dec: -1957362950)
{
	struct _SavedIntro *intro; // size=40, offset=0 //  hashcode: 0x7F8AB567 (dec: 2139796839), parent name: 'EVENT_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;			   // size=0, offset=4 //  hashcode: 0x904F55CA (dec: -1873848886), parent name: 'EVENT_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_186fake // hashcode: 0xF3748F7B (dec: -210464901)
{
	long currentNumber; // size=0, offset=0 //  hashcode: 0x6F60C595 (dec: 1868613013), parent name: 'EVENT_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long error;			// size=0, offset=4 //  hashcode: 0xA35550C9 (dec: -1554689847), parent name: 'EVENT_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;		// size=0, offset=8 //  hashcode: 0x23B2B90F (dec: 598915343), parent name: 'EVENT_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_187fake // hashcode: 0x00039490 (dec: 234640)
{
	short vx; // size=0, offset=0 //  hashcode: 0xD5A08139 (dec: -710901447), parent name: 'EVENT_187fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vy; // size=0, offset=2 //  hashcode: 0xB3021504 (dec: -1291709180), parent name: 'EVENT_187fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_188fake // hashcode: 0xE7B998E8 (dec: -407267096)
{
	char *pointer; // size=0, offset=0 //  hashcode: 0x999EECBB (dec: -1717637957), parent name: 'EVENT_188fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_189fake // hashcode: 0x6E7F75C7 (dec: 1853846983)
{
	short *pointer; // size=0, offset=0 //  hashcode: 0x96BB1E60 (dec: -1766121888), parent name: 'EVENT_189fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_190fake // hashcode: 0xD0F736D6 (dec: -789104938)
{
	long *pointer; // size=0, offset=0 //  hashcode: 0xEF57AD96 (dec: -279466602), parent name: 'EVENT_190fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union EVENT_191fake // Hashcode: 0x71FFC418 (dec: 1912587288)
{
	struct EVENT_184fake Object;					  // size=8, offset=0
	struct EVENT_185fake SavedIntroObject;			  // size=8, offset=0
	struct InstanceSpline instanceSpline;			  // size=24, offset=0
	struct EVENT_186fake Number;					  // size=12, offset=0
	struct EVENT_187fake Vector2d;					  // size=4, offset=0
	struct EVENT_188fake CharPointer;				  // size=4, offset=0
	struct EVENT_189fake ShortPointer;				  // size=4, offset=0
	struct EVENT_190fake LongPointer;				  // size=4, offset=0
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

struct _PCodeStack // hashcode: 0x88A5C96B (dec: -2002400917)
{
	long topOfStack;			// size=0, offset=0 //  hashcode: 0x2EEB274F (dec: 787162959), parent name: '_PCodeStack', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct StackType stack[32]; // size=1152, offset=4 //  hashcode: 0x7D79DC62 (dec: 2105138274), parent name: '_PCodeStack', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union EVENT_219fake // Hashcode: 0xED7CCDD7 (dec: -310587945)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct EVENT_255fake // hashcode: 0x0630D4A1 (dec: 103863457)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0xBF5472BB (dec: -1084984645), parent name: 'EVENT_255fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x09976AB2 (dec: 160918194), parent name: 'EVENT_255fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EVENT_256fake // hashcode: 0x843BCF05 (dec: -2076455163)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x01708E3D (dec: 24153661), parent name: 'EVENT_256fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0xD1697181 (dec: -781618815), parent name: 'EVENT_256fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0xA05FF357 (dec: -1604324521), parent name: 'EVENT_256fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0xC7D80AEF (dec: -942142737), parent name: 'EVENT_256fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x9BE35503 (dec: -1679600381), parent name: 'EVENT_256fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0xB9A24703 (dec: -1180547325), parent name: 'EVENT_256fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union EVENT_257fake // Hashcode: 0x85EA03D0 (dec: -2048261168)
{
	struct EVENT_255fake flame; // size=8, offset=0
	struct EVENT_256fake phys;  // size=12, offset=0
};

struct EventTimer // hashcode: 0xAA55BC81 (dec: -1437221759)
{
	long flags : 1;					  // offset=0.0 //  hashcode: 0xDE37D1E7 (dec: -566767129), parent name: 'EventTimer', parent hashcode: 0xFFFFFFFF (dec: -1)
	long time : 31;					  // offset=0.1 //  hashcode: 0xAD262168 (dec: -1390010008), parent name: 'EventTimer', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Event *event;			  // size=28, offset=4 //  hashcode: 0xA2F750C1 (dec: -1560850239), parent name: 'EventTimer', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct ScriptPCode *actionScript; // size=8, offset=8 //  hashcode: 0x4BDED8C7 (dec: 1272895687), parent name: 'EventTimer', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *scriptPos;				  // size=0, offset=12 //  hashcode: 0x7A7D9083 (dec: 2055049347), parent name: 'EventTimer', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Level *level;			  // size=392, offset=16 //  hashcode: 0xE45C1371 (dec: -463727759), parent name: 'EventTimer', parent hashcode: 0xFFFFFFFF (dec: -1)
	long nextEventIndex;			  // size=0, offset=20 //  hashcode: 0x86965A60 (dec: -2036966816), parent name: 'EventTimer', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SignalResetStruct // hashcode: 0x8D08210C (dec: -1928847092)
{
	struct _MultiSignal *mSignal; // size=904, offset=0 //  hashcode: 0xED2FF6E9 (dec: -315623703), parent name: 'SignalResetStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timeLeft;				  // size=0, offset=4 //  hashcode: 0x111BC0CE (dec: 287031502), parent name: 'SignalResetStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HintSystemStruct // hashcode: 0xAD521037 (dec: -1387130825)
{
	short flags;		 // size=0, offset=0 //  hashcode: 0x1DE3DDE6 (dec: 501472742), parent name: 'HintSystemStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	short hintNumber;	// size=0, offset=2 //  hashcode: 0x7F31C941 (dec: 2133969217), parent name: 'HintSystemStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	short stringNumber;  // size=0, offset=4 //  hashcode: 0x76A79509 (dec: 1990694153), parent name: 'HintSystemStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;			 // size=0, offset=6 //  hashcode: 0xAAAC2BB9 (dec: -1431557191), parent name: 'HintSystemStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	long fadeTimer;		 // size=0, offset=8 //  hashcode: 0xF633EDDC (dec: -164368932), parent name: 'HintSystemStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	long spawningUnitID; // size=0, offset=12 //  hashcode: 0x91F53A0D (dec: -1846199795), parent name: 'HintSystemStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct SavedEventSmallVars SavedEventSmallVars;

typedef struct WaterLevelProcess WaterLevelProcess;

typedef struct EventInstanceObject EventInstanceObject;

typedef struct EventEventObject EventEventObject;

typedef struct EventTGroupObject EventTGroupObject;

typedef struct _PCodeStack PCodeStack;

typedef struct EventTimer EventTimer;

typedef struct SignalResetStruct SignalResetStruct;

typedef struct HintSystemStruct HintSystemStruct;

extern void EVENT_UpdateResetSignalArrayAndWaterMovement(struct Level *oldLevel, struct Level *newLevel, long sizeOfLevel); // 0x800605D0

extern void EVENT_ResetAllOneTimeVariables(); // 0x800606AC

extern void EVENT_AddSignalToReset(struct _MultiSignal *mSignal); // 0x80060714

extern void HINT_ResetHint(); // 0x80060770

extern void HINT_StartHint(short hintNumber); // 0x80060798

extern void HINT_StopHint(); // 0x800607FC

extern void HINT_KillSpecificHint(short hintNumber); // 0x80060860

extern long HINT_GetCurrentHint(); // 0x80060890

extern void EVENT_ProcessTimers(); // 0x800608B0

extern void EVENT_ProcessHints(); // 0x800609CC

extern struct EventTimer *EVENT_GetNextTimer(); // 0x80060B8C

extern void EVENT_RemoveTimer(struct EventTimer *timer); // 0x80060BF8

extern void EVENT_InitTimers(); // 0x80060C28

extern void EVENT_InitTerrainMovement(); // 0x80060C54

extern void EVENT_Init(); // 0x80060CA4

extern struct WaterLevelProcess *EVENT_GetNextTerrainMove(); // 0x80060CF0

extern void EVENT_ProcessMovingWater(); // 0x80060D28

extern void EVENT_DoProcess(); // 0x80060E58

extern void EVENT_BSPProcess(struct _StreamUnit *streamUnit); // 0x80060E80

extern void EVENT_Process(struct Event *eventInstance, long startIndex); // 0x800610C0

extern void EVENT_ProcessPuppetShow(struct Event *eventInstance, long startIndex); // 0x80061220

extern void EVENT_ProcessEvents(struct EventPointers *eventPointers, struct Level *level); // 0x800613F8

extern long EVENT_DoAction(struct Event *eventInstance, struct ScriptPCode *actionScript, short *scriptData); // 0x800614BC

extern long EVENT_IsConditionTrue(struct Event *eventInstance, struct ScriptPCode *conditionScript); // 0x80061634

extern long EVENT_WriteEventObject(struct StackType *stackEntry, long areaID, struct Event *event, long number); // 0x80061724

extern struct _MultiSignal *EVENT_ResolveObjectSignal(struct _StreamUnit *stream, long signalNumber); // 0x800617D4

extern struct Intro *EVENT_ResolveObjectIntro(struct EventInstanceObject *instanceObject); // 0x8006186C

extern struct _SFXMkr *EVENT_ResolveSFXMarker(struct _StreamUnit *stream, struct EventInstanceObject *instanceObject); // 0x80061898

extern void EVENT_AddGameObjectToStack(struct _PCodeStack *stack); // 0x800618F8

extern void EVENT_AddPlayerObjectToStack(struct _PCodeStack *stack); // 0x80061944

extern void EVENT_AddObjectToStack(struct _PCodeStack *stack, long item); // 0x8006199C

extern void EVENT_AddCharPointerToStack(struct _PCodeStack *stack, char *pointer); // 0x80061BD0

extern void EVENT_AddShortPointerToStack(struct _PCodeStack *stack, short *pointer); // 0x80061C18

extern void EVENT_AddNumberToStack(struct _PCodeStack *stack, long item, long flags); // 0x80061C60

extern void EVENT_ChangeOperandToNumber(struct StackType *operand, long item, long flags); // 0x80061CB0

extern void EVENT_ChangeOperandVector3d(struct StackType *operand, short x, short y, short z, long streamUnitID); // 0x80061CC8

extern void EVENT_Addvector3dToStack(struct _PCodeStack *stack, short x, short y, short z, long streamUnitID); // 0x80061CF8

extern void EVENT_ChangeOperandRotation3d(struct StackType *operand, struct Rotation3d *rotation); // 0x80061D70

extern long EVENT_AddSubListObjectToStack(struct _PCodeStack *stack, long listNumber); // 0x80061DC8

extern void EVENT_StackDuplicate(struct _PCodeStack *stack); // 0x80061E54

extern long EVENT_TransformTGroupAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80061EEC

extern long EVENT_TransformConstrictAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x80061F7C

extern long EVENT_TransformInstanceAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80061FE8

extern long EVENT_TransformSoundObjectAttribute(struct _PCodeStack *stack, struct SoundObject *soundObject, long item, short *codeStream); // 0x8006264C

extern long EVENT_GetGameValue(struct GameObject *gameObject); // 0x80062764

extern long EVENT_TransformGameAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80062800

extern long EVENT_TransformAreaAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80062C80

extern long EVENT_TransformEventAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80062D5C

extern long EVENT_TransformSavedEventAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80062DEC

extern long EVENT_TransformSubListObjectAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x80062EA8

extern long EVENT_TransformListObjectAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x80062EDC

extern long EVENT_TransformCameraObjectAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80062F10

extern long EVENT_TransformSplineAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x8006303C

extern long EVENT_TransformIntroAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x80063140

extern long EVENT_ParseOperand2(struct StackType *operand2, long *error, long *trueValue); // 0x8006325C

extern long EVENT_DoVMObjectAction(struct EventVmObject *vmobject, struct StackType *operand2); // 0x800632B4

extern long EVENT_GetVMObjectValue(struct EventVmObject *vmobject); // 0x80063474

extern long EVENT_DoGameAction(struct GameObject *gameObject, struct StackType *operand2); // 0x8006353C

extern long EVENT_DoSignalAction(struct SignalObject *signalObject, struct StackType *operand2); // 0x80063830

extern long EVENT_TransformSignalAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x800638AC

extern long EVENT_TransformRotation3dAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80063904

extern long EVENT_TransformVector3dAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x8006393C

extern void EVENT_ModifyObjectToStackWithAttribute(struct _PCodeStack *stack, long item, short *codeStream); // 0x80063A38

extern long EVENT_DoInstanceAnimateTextureAction(struct InstanceAnimateTexture *instanceAniTexture, struct StackType *operand2); // 0x80063A68

extern void EVENT_ResetAllSplineFlags(struct MultiSpline *spline); // 0x80063B70

extern void EVENT_SetSplineLoop(struct MultiSpline *spline); // 0x80063BF8

extern long EVENT_DoSplineAction(struct InstanceSpline *instanceSpline, struct StackType *operand2); // 0x80063C80

extern long EVENT_DoAnimateAction(struct InstanceAnimate *instanceAnimate, struct StackType *operand2); // 0x8006404C

extern long EVENT_DoInstanceAction(struct InstanceObject *instanceObject, struct StackType *operand2, short *codeStream); // 0x80064320

extern long EVENT_GetTGroupValue(struct TGroupObject *terrainGroup); // 0x80064DC4

extern long EVENT_DoTGroupAction(struct TGroupObject *terrainGroup, struct StackType *operand2); // 0x80064F30

extern long EVENT_DoCameraAction(struct CameraObject *cameraObject, struct StackType *operand2, short *codeStream); // 0x80065238

extern long EVENT_DoObjectSoundAction(struct SoundObject *soundObject, struct StackType *operand2); // 0x800655B8

extern long EVENT_DoSoundMarkerAction(struct SoundObject *soundObject, struct StackType *operand2); // 0x800656EC

extern long EVENT_GetSoundValue(struct SoundObject *soundObject); // 0x80065820

extern long EVENT_DoAreaAction(struct AreaObject *areaObject, struct StackType *operand2); // 0x80065828

extern long EVENT_DoIntroAction(struct IntroObject *introObject, struct StackType *operand2); // 0x800658D4

extern void EVENT_DoStackOperationEquals(struct _PCodeStack *stack, short *codeStream); // 0x80065AE4

extern long EVENT_CompareVector3d(struct Vector3d *vector1, struct Vector3d *vector2); // 0x80065BD0

extern long EVENT_CompareRotationVectors(struct Rotation3d *rot1, struct Rotation3d *rot2, long trueValue); // 0x80065D8C

extern long EVENT_CompareListWithOperation(struct _PCodeStack *stack, struct ListObject *listObject, struct StackType *operand2, long operation); // 0x80065F84

extern long EVENT_CompareSubListWithOperation(struct _PCodeStack *stack, struct SubListObject *subListObject, struct StackType *operand2, long operation); // 0x80066178

extern long EVENT_CompareOperandsWithOperation(struct _PCodeStack *stack, struct StackType *operand1, struct StackType *operand2, long operation); // 0x80066314

extern void EVENT_DoStackMathOperation(struct _PCodeStack *stack, long operation); // 0x8006664C

extern short *EVENT_ParseOpcode(struct _PCodeStack *stack, short *codeStream, long *operateOnStack); // 0x80066834

extern long EVENT_GetIntroValue(struct IntroObject *introObject); // 0x80066AB0

extern void EVENT_DoSubListAction(struct SubListObject *subListObject, struct StackType *operand2, struct _PCodeStack *stack, short *codeStream); // 0x80066B44

extern long EVENT_GetInstanceValue(struct InstanceObject *instanceObject); // 0x80066C3C

extern long EVENT_GetSplineFrameNumber(struct InstanceSpline *instanceSpline); // 0x80066DB4

extern long EVENT_GetSplineValue(struct InstanceSpline *instanceSpline); // 0x80066DF8

extern long EVENT_GetAnimateTextureValue(struct InstanceAnimateTexture *instanceAniTexture); // 0x80066EF4

extern long EVENT_GetAnimateValue(struct InstanceAnimate *instanceAnimate); // 0x80066FA4

extern long EVENT_TransformObjectOnStack(struct _PCodeStack *stack, long item, short *codeStream); // 0x8006701C

extern void EVENT_UpdatePuzzlePointers(struct EventPointers *events, long offset); // 0x80067070

extern void EVENT_SaveEventsFromLevel(long levelID, struct Level *level); // 0x8006724C

extern void EVENT_LoadEventsForLevel(long levelID, struct Level *level); // 0x800673C8

extern struct SavedBasic *EVENT_CreateSaveEvent(long levelID, long eventNumber); // 0x80067504

extern void EVENT_RemoveInstanceFromInstanceList(struct _Instance *instance); // 0x80067570

extern void EVENT_UpdatePuzzleWithInstance(struct EventPointers *puzzle, struct _Instance *instance); // 0x80067658

extern void EVENT_AddInstanceToInstanceList(struct _Instance *instance); // 0x800676FC

extern struct _VMObject *EVENT_FindVMObject(struct _StreamUnit *stream, char *vmoName); // 0x800677E8

extern void EVENT_FixPuzzlesForStream(struct _StreamUnit *stream); // 0x80067888

extern void EVENT_AddStreamToInstanceList(struct _StreamUnit *stream); // 0x80067B6C

extern void EVENT_RemoveStreamToInstanceList(struct _StreamUnit *stream); // 0x80067E54

extern void EVENT_RelocateInstanceList(struct Level *oldLevel, struct Level *newLevel, long sizeOfLevel); // 0x80068018

extern void EVENT_PrintVars(); // 0x80068218

extern void EVENT_ExecuteActionCommand(struct StackType *operand1, struct StackType *operand2, struct _PCodeStack *stack, short *codeStream); // 0x80068220

extern long EVENT_GetScalerValueFromOperand(struct StackType *operand, long *error, short *flags); // 0x800683E8

extern long EVENT_TransformOperand(struct StackType *stackObject, struct _PCodeStack *stack, long item, short *codeStream); // 0x80068558

#endif
