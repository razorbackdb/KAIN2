#ifndef SOUND_H
#define SOUND_H

static int gSramFullMsgCnt; // offset 0x800CEA8C

extern struct MusicLoadInfo musicInfo; // offset 0x800D1510

static long objectOneShotTriggerTbl[3]; // offset 0x800CEA90

extern char soundBuffer[13256]; // offset 0x800D5C08

extern struct SoundEffectChannel soundEffectChannelTbl[16]; // offset 0x800D12C0

struct SOUND_73fake // hashcode: 0x9E98DDD3 (dec: -1634148909)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x5BB7B244 (dec: 1538765380), parent name: 'SOUND_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x44FD0278 (dec: 1157431928), parent name: 'SOUND_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_74fake // hashcode: 0x9F5DEC28 (dec: -1621234648)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xF1E0AD87 (dec: -236933753), parent name: 'SOUND_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x98359D8A (dec: -1741316726), parent name: 'SOUND_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_75fake // hashcode: 0x2358D800 (dec: 593025024)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x1EEFEC18 (dec: 519040024), parent name: 'SOUND_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x1E8E1275 (dec: 512627317), parent name: 'SOUND_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SOUND_76fake // Hashcode: 0xA905F6AB (dec: -1459226965)
{
	struct SOUND_73fake callback; // size=8, offset=0
	struct SOUND_74fake vector;   // size=12, offset=0
	struct SOUND_75fake quat;	 // size=16, offset=0
};

union SOUND_77fake // Hashcode: 0xFD6718B0 (dec: -43575120)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union SOUND_78fake // Hashcode: 0x74BBC4C3 (dec: 1958462659)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct SOUND_79fake // hashcode: 0x0903C258 (dec: 151241304)
{
	union SOUND_78fake size; // size=4, offset=0 //  hashcode: 0xA1A8DFFA (dec: -1582768134), parent name: 'SOUND_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_80fake // hashcode: 0x090CD182 (dec: 151835010)
{
	short x;				// size=0, offset=0 //  hashcode: 0x834CABA0 (dec: -2092127328), parent name: 'SOUND_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x16DEED3C (dec: 383708476), parent name: 'SOUND_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xC291F25E (dec: -1030622626), parent name: 'SOUND_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x26D25C60 (dec: 651320416), parent name: 'SOUND_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xBA62DFA0 (dec: -1167925344), parent name: 'SOUND_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_81fake // hashcode: 0x64846B8A (dec: 1686399882)
{
	long index; // size=0, offset=0 //  hashcode: 0x54243399 (dec: 1411658649), parent name: 'SOUND_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x110C4C34 (dec: 286018612), parent name: 'SOUND_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_82fake // hashcode: 0xD9CC261C (dec: -640932324)
{
	long index; // size=0, offset=0 //  hashcode: 0xC4EB17A7 (dec: -991225945), parent name: 'SOUND_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x85D64993 (dec: -2049554029), parent name: 'SOUND_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_83fake // hashcode: 0x5CD2C4C8 (dec: 1557316808)
{
	long index; // size=0, offset=0 //  hashcode: 0xE86CDD5A (dec: -395518630), parent name: 'SOUND_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x1C0C4A9F (dec: 470567583), parent name: 'SOUND_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_84fake // hashcode: 0xDF5D81C9 (dec: -547520055)
{
	long time;  // size=0, offset=0 //  hashcode: 0x87204BA1 (dec: -2027926623), parent name: 'SOUND_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x793B076B (dec: 2033911659), parent name: 'SOUND_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_85fake // hashcode: 0x5E5A96C2 (dec: 1582995138)
{
	long action;   // size=0, offset=0 //  hashcode: 0xDA4280A8 (dec: -633175896), parent name: 'SOUND_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xFF87AD0E (dec: -7885554), parent name: 'SOUND_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_86fake // hashcode: 0xDEEC3CFE (dec: -554943234)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xE0F6464E (dec: -520731058), parent name: 'SOUND_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x45DA097B (dec: 1171917179), parent name: 'SOUND_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_87fake // hashcode: 0x299531C3 (dec: 697643459)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xE04F7B0C (dec: -531662068), parent name: 'SOUND_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x72D722F6 (dec: 1926701814), parent name: 'SOUND_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_88fake // hashcode: 0x2BA24A4E (dec: 732056142)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x8E58F4D7 (dec: -1906772777), parent name: 'SOUND_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xDC72DD40 (dec: -596452032), parent name: 'SOUND_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_89fake // hashcode: 0xBFCF0880 (dec: -1076950912)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x3318FE46 (dec: 857275974), parent name: 'SOUND_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x22B4C3A3 (dec: 582271907), parent name: 'SOUND_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xC4624E00 (dec: -1000190464), parent name: 'SOUND_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x575F6CDF (dec: 1465871583), parent name: 'SOUND_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xDDB32EA3 (dec: -575459677), parent name: 'SOUND_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_90fake // hashcode: 0x3E43F021 (dec: 1044639777)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x39EC8901 (dec: 971802881), parent name: 'SOUND_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x775C4A31 (dec: 2002537009), parent name: 'SOUND_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_91fake // hashcode: 0xCEE71D29 (dec: -823714519)
{
	short index;					// size=0, offset=0 //  hashcode: 0x75171784 (dec: 1964447620), parent name: 'SOUND_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x606E06A3 (dec: 1617823395), parent name: 'SOUND_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x5B630921 (dec: 1533217057), parent name: 'SOUND_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xAA71183A (dec: -1435428806), parent name: 'SOUND_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_92fake // hashcode: 0x93AD62F1 (dec: -1817353487)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x8166CC0B (dec: -2123969525), parent name: 'SOUND_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x8E0E200E (dec: -1911676914), parent name: 'SOUND_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xC30D497E (dec: -1022539394), parent name: 'SOUND_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_93fake // hashcode: 0x7B4D1EEA (dec: 2068651754)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x50214B61 (dec: 1344359265), parent name: 'SOUND_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x1675664A (dec: 376792650), parent name: 'SOUND_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x05029902 (dec: 84056322), parent name: 'SOUND_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x5AC104F8 (dec: 1522599160), parent name: 'SOUND_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x1046FE40 (dec: 273088064), parent name: 'SOUND_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x88120B96 (dec: -2012083306), parent name: 'SOUND_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x0AB1AF06 (dec: 179416838), parent name: 'SOUND_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_94fake // hashcode: 0xC58B7525 (dec: -980716251)
{
	long index;  // size=0, offset=0 //  hashcode: 0xCD7338BB (dec: -848086853), parent name: 'SOUND_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xEA7E0080 (dec: -360841088), parent name: 'SOUND_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_95fake // hashcode: 0x8CD08DF0 (dec: -1932489232)
{
	short type; // size=0, offset=0 //  hashcode: 0xBA8E2828 (dec: -1165088728), parent name: 'SOUND_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x933A64C9 (dec: -1824889655), parent name: 'SOUND_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_96fake // hashcode: 0xF7255266 (dec: -148549018)
{
	long time;   // size=0, offset=0 //  hashcode: 0x4539E1E2 (dec: 1161421282), parent name: 'SOUND_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x114173B8 (dec: 289502136), parent name: 'SOUND_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_97fake // hashcode: 0xE1A59EBE (dec: -509239618)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x29390077 (dec: 691601527), parent name: 'SOUND_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x1F79F576 (dec: 528086390), parent name: 'SOUND_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_98fake // hashcode: 0x8FFFF7F0 (dec: -1879050256)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x2FD22A1D (dec: 802302493), parent name: 'SOUND_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x8C5122B4 (dec: -1940839756), parent name: 'SOUND_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_99fake // hashcode: 0x45FB11C1 (dec: 1174081985)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x154C3C20 (dec: 357317664), parent name: 'SOUND_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x35410FF4 (dec: 893456372), parent name: 'SOUND_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_100fake // hashcode: 0xEF64DE27 (dec: -278602201)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x081BAAC2 (dec: 136030914), parent name: 'SOUND_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xC80E0BA3 (dec: -938603613), parent name: 'SOUND_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x9054AC42 (dec: -1873499070), parent name: 'SOUND_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x537EF521 (dec: 1400829217), parent name: 'SOUND_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_101fake // hashcode: 0x28E08B2D (dec: 685804333)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x8BA07DF8 (dec: -1952416264), parent name: 'SOUND_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x8B746A64 (dec: -1955304860), parent name: 'SOUND_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xFA0D8696 (dec: -99776874), parent name: 'SOUND_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xB35C282A (dec: -1285806038), parent name: 'SOUND_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x4F2645FE (dec: 1327908350), parent name: 'SOUND_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SOUND_102fake // Hashcode: 0xCA4F9B8A (dec: -900752502)
{
	struct SOUND_79fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	 // size=24, offset=0
	struct SOUND_80fake teleport;	 // size=16, offset=0
	struct SOUND_81fake cameraValue;  // size=8, offset=0
	struct SOUND_82fake miscValue;	// size=8, offset=0
	struct SOUND_83fake logicValue;   // size=8, offset=0
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
	struct SOUND_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				  // size=0, offset=0
	long cameraRestore;				  // size=0, offset=0
	struct _BGObject *bgObject;		  // size=24, offset=0
	long value[2];					  // size=8, offset=0
	struct SOUND_85fake sound;		  // size=12, offset=0
	void *intro;					  // size=0, offset=0
	long deathZ;					  // size=0, offset=0
	struct SOUND_86fake dsignal;	  // size=8, offset=0
	void *mirror;					  // size=0, offset=0
	long fogNear;					  // size=0, offset=0
	long fogFar;					  // size=0, offset=0
	struct SOUND_87fake gotoFrame;	// size=8, offset=0
	struct SOUND_88fake changeModel;  // size=8, offset=0
	void *vmObject;					  // size=0, offset=0
	struct SOUND_89fake logic;		  // size=8, offset=0
	void *callSignal;				  // size=0, offset=0
	struct _SVector offset;			  // size=8, offset=0
	struct Signal *gotoLabel;		  // size=0, offset=0
	struct Signal *gosubLabel;		  // size=0, offset=0
	struct SOUND_90fake control;	  // size=8, offset=0
	struct SOUND_91fake zSignal;	  // size=12, offset=0
	struct SOUND_92fake StreamLevel;  // size=24, offset=0
	struct SOUND_93fake shards;		  // size=12, offset=0
	struct SOUND_94fake cameraSpline; // size=8, offset=0
	struct SOUND_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				  // size=0, offset=0
	struct SOUND_96fake introFX;	  // size=8, offset=0
	struct SOUND_97fake introActive;  // size=8, offset=0
	struct SOUND_98fake levelChange;  // size=18, offset=0
	long blendStart;				  // size=0, offset=0
	struct SOUND_99fake setTimes;	 // size=8, offset=0
	struct SOUND_100fake color;		  // size=4, offset=0
	struct SOUND_101fake print;		  // size=12, offset=0
	long slideAngle;				  // size=0, offset=0
};

union SOUND_103fake // Hashcode: 0x62CD2016 (dec: 1657610262)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union SOUND_108fake // Hashcode: 0xA5EEF07C (dec: -1511067524)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct SOUND_110fake // hashcode: 0xD537BACB (dec: -717767989)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x4F25FD48 (dec: 1327889736), parent name: 'SOUND_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x110EFFE1 (dec: 286195681), parent name: 'SOUND_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0xD71A56D8 (dec: -686139688), parent name: 'SOUND_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x3FBD0A51 (dec: 1069353553), parent name: 'SOUND_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x05B4349A (dec: 95696026), parent name: 'SOUND_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x55306792 (dec: 1429235602), parent name: 'SOUND_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x525A2EDF (dec: 1381641951), parent name: 'SOUND_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_111fake // hashcode: 0xE0CF31B1 (dec: -523292239)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x1F8FC146 (dec: 529514822), parent name: 'SOUND_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x95E53BFA (dec: -1780139014), parent name: 'SOUND_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x2E185859 (dec: 773347417), parent name: 'SOUND_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_112fake // hashcode: 0x3DCCF300 (dec: 1036841728)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x4F487D92 (dec: 1330150802), parent name: 'SOUND_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x859AE17D (dec: -2053447299), parent name: 'SOUND_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xD0EAC0C1 (dec: -789921599), parent name: 'SOUND_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xB1CEC2AB (dec: -1311849813), parent name: 'SOUND_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xEE806FA8 (dec: -293572696), parent name: 'SOUND_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_113fake // hashcode: 0x122F8F91 (dec: 305106833)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x5C453282 (dec: 1548038786), parent name: 'SOUND_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0xB33B6C18 (dec: -1287951336), parent name: 'SOUND_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0xBD51339A (dec: -1118751846), parent name: 'SOUND_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xA30D6CDD (dec: -1559401251), parent name: 'SOUND_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x90A1A9E8 (dec: -1868453400), parent name: 'SOUND_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_114fake // hashcode: 0xEE28F284 (dec: -299306364)
{
	struct SOUND_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x33F3F307 (dec: 871625479), parent name: 'SOUND_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SOUND_111fake Idle;		// size=20, offset=28 //  hashcode: 0xDE5B53DF (dec: -564440097), parent name: 'SOUND_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SOUND_112fake Behind;	// size=28, offset=48 //  hashcode: 0xD02B81DC (dec: -802455076), parent name: 'SOUND_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SOUND_113fake Follow;	// size=20, offset=76 //  hashcode: 0xA7899735 (dec: -1484155083), parent name: 'SOUND_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadInitAttr // hashcode: 0x0549E29A (dec: 88728218)
{
	int updateMode;						// size=0, offset=0 //  hashcode: 0xA9B4C853 (dec: -1447770029), parent name: 'AadInitAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numSlots;						// size=0, offset=4 //  hashcode: 0x122207D5 (dec: 304220117), parent name: 'AadInitAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*nonBlockLoadProc)();			// size=0, offset=8 //  hashcode: 0xDF629717 (dec: -547186921), parent name: 'AadInitAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*nonBlockBufferedLoadProc)(); // size=0, offset=12 //  hashcode: 0xBB250499 (dec: -1155201895), parent name: 'AadInitAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (**memoryMallocProc)();		// size=0, offset=16 //  hashcode: 0xC7A8043B (dec: -945290181), parent name: 'AadInitAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*memoryFreeProc)();			// size=0, offset=20 //  hashcode: 0x915EA09C (dec: -1856069476), parent name: 'AadInitAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MusicLoadInfo // hashcode: 0xC8F67C40 (dec: -923370432)
{
	int state;							 // size=0, offset=0 //  hashcode: 0x2A00FE35 (dec: 704708149), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nextState;						 // size=0, offset=4 //  hashcode: 0xF43194C2 (dec: -198077246), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int errorStatus;					 // size=0, offset=8 //  hashcode: 0x9B37669F (dec: -1690868065), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int bankLoaded;						 // size=0, offset=12 //  hashcode: 0x4CD1A67A (dec: 1288808058), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int checkMusicDelay;				 // size=0, offset=16 //  hashcode: 0xDB30728A (dec: -617581942), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int currentMusicPlane;				 // size=0, offset=20 //  hashcode: 0xC8F2EF1F (dec: -923603169), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	char currentMusicName[8];			 // size=8, offset=24 //  hashcode: 0x0207E647 (dec: 34072135), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MusicLoadCmd commandQueue[4]; // size=32, offset=32 //  hashcode: 0x7B1D43BE (dec: 2065515454), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int commandIn;						 // size=0, offset=64 //  hashcode: 0x31641503 (dec: 828642563), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int commandOut;						 // size=0, offset=68 //  hashcode: 0xDC53301D (dec: -598527971), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numCmdsInQueue;					 // size=0, offset=72 //  hashcode: 0x63B9A61B (dec: 1673111067), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ObjectPeriodicSound // hashcode: 0x931DBADB (dec: -1826768165)
{
	unsigned char type;					 // size=0, offset=0 //  hashcode: 0x393A6813 (dec: 960129043), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numSfxIDs;			 // size=0, offset=1 //  hashcode: 0x81738108 (dec: -2123136760), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char soundInst;			 // size=0, offset=2 //  hashcode: 0x280FB866 (dec: 672118886), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;				 // size=0, offset=3 //  hashcode: 0xE686DB36 (dec: -427369674), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short minVolDistance;		 // size=0, offset=4 //  hashcode: 0x9BD772E3 (dec: -1680379165), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitch;						 // size=0, offset=6 //  hashcode: 0x723DE05C (dec: 1916657756), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pitchVariation;		 // size=0, offset=8 //  hashcode: 0x3A3D6B67 (dec: 977103719), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char maxVolume;			 // size=0, offset=10 //  hashcode: 0xB57FE884 (dec: -1249908604), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char maxVolVariation;		 // size=0, offset=11 //  hashcode: 0xDCB0DC38 (dec: -592389064), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char initialDelay;			 // size=0, offset=12 //  hashcode: 0xB461AA1B (dec: -1268667877), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char initialDelayVariation; // size=0, offset=13 //  hashcode: 0x1FDB5C41 (dec: 534469697), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char onTime;				 // size=0, offset=14 //  hashcode: 0x2D8144EC (dec: 763446508), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char onTimeVariation;		 // size=0, offset=15 //  hashcode: 0x1FFE0C71 (dec: 536743025), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char offTime;				 // size=0, offset=16 //  hashcode: 0x1516B274 (dec: 353809012), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char offTimeVariation;		 // size=0, offset=17 //  hashcode: 0xF6E4AC6D (dec: -152785811), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ObjectEventSound // hashcode: 0x02927CD2 (dec: 43154642)
{
	unsigned char type;					 // size=0, offset=0 //  hashcode: 0x375DFCA9 (dec: 928906409), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numSfxIDs;			 // size=0, offset=1 //  hashcode: 0x083FAB7A (dec: 138390394), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char soundInst;			 // size=0, offset=2 //  hashcode: 0x236704EB (dec: 593954027), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;				 // size=0, offset=3 //  hashcode: 0xEF5B2ED2 (dec: -279236910), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short minVolDistance;		 // size=0, offset=4 //  hashcode: 0x1EC3AE50 (dec: 516140624), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitch;						 // size=0, offset=6 //  hashcode: 0x33E03EFD (dec: 870334205), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pitchVariation;		 // size=0, offset=8 //  hashcode: 0xD022F5FD (dec: -803015171), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char maxVolume;			 // size=0, offset=10 //  hashcode: 0x223D1FC1 (dec: 574431169), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char maxVolVariation;		 // size=0, offset=11 //  hashcode: 0xCCBF2380 (dec: -859888768), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char initialDelay;			 // size=0, offset=12 //  hashcode: 0x60DCB389 (dec: 1625076617), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char initialDelayVariation; // size=0, offset=13 //  hashcode: 0xDBE21D52 (dec: -605938350), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ObjectOneShotSound // hashcode: 0xF16FD213 (dec: -244329965)
{
	unsigned char type;					 // size=0, offset=0 //  hashcode: 0x8D5E26FD (dec: -1923209475), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numSfxIDs;			 // size=0, offset=1 //  hashcode: 0x8665135C (dec: -2040196260), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char soundInst;			 // size=0, offset=2 //  hashcode: 0x8CF90BB4 (dec: -1929835596), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;				 // size=0, offset=3 //  hashcode: 0xA15E5E92 (dec: -1587650926), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short minVolDistance;		 // size=0, offset=4 //  hashcode: 0x4404D1BA (dec: 1141166522), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitch;						 // size=0, offset=6 //  hashcode: 0x6E71AA58 (dec: 1852942936), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pitchVariation;		 // size=0, offset=8 //  hashcode: 0x71223B0A (dec: 1898068746), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char maxVolume;			 // size=0, offset=10 //  hashcode: 0x3E5000CB (dec: 1045430475), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char maxVolVariation;		 // size=0, offset=11 //  hashcode: 0x1B9BC6EB (dec: 463193835), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char initialDelay;			 // size=0, offset=12 //  hashcode: 0xE7E8BB63 (dec: -404178077), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char initialDelayVariation; // size=0, offset=13 //  hashcode: 0x4D2C1267 (dec: 1294733927), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SoundEffectChannel // hashcode: 0xA19502FD (dec: -1584069891)
{
	unsigned char inUse;			// size=0, offset=0 //  hashcode: 0xD6A6F070 (dec: -693702544), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char unused;			// size=0, offset=1 //  hashcode: 0xDF09456C (dec: -553040532), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short unused1;			// size=0, offset=2 //  hashcode: 0x22755B50 (dec: 578116432), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long handle;			// size=0, offset=4 //  hashcode: 0x5E541FB9 (dec: 1582571449), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short volume;					// size=0, offset=8 //  hashcode: 0x3D520CAD (dec: 1028787373), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short volumeChangeTime;			// size=0, offset=10 //  hashcode: 0xC2519EF7 (dec: -1034838281), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short volumeChangeTimeSave;		// size=0, offset=12 //  hashcode: 0xE1B1AF70 (dec: -508448912), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short volumeChangePerUpdate;	// size=0, offset=14 //  hashcode: 0x0EA7185B (dec: 245831771), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short volumeChangeSign;			// size=0, offset=16 //  hashcode: 0x0B285366 (dec: 187192166), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short volumeChangeErrPerUpdate; // size=0, offset=18 //  hashcode: 0x0B801F75 (dec: 192946037), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short volumeChangeError;		// size=0, offset=20 //  hashcode: 0x949D5B49 (dec: -1801626807), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitch;					// size=0, offset=22 //  hashcode: 0xF69E960F (dec: -157379057), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitchChangeTime;			// size=0, offset=24 //  hashcode: 0xB6DC3537 (dec: -1227082441), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitchChangeTimeSave;		// size=0, offset=26 //  hashcode: 0xBA1698F4 (dec: -1172924172), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitchChangePerUpdate;		// size=0, offset=28 //  hashcode: 0x44D22ACB (dec: 1154624203), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitchChangeSign;			// size=0, offset=30 //  hashcode: 0x4E5D20EA (dec: 1314726122), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitchChangeErrPerUpdate;  // size=0, offset=32 //  hashcode: 0x1389DFE7 (dec: 327802855), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitchChangeError;			// size=0, offset=34 //  hashcode: 0xF1E57A16 (dec: -236619242), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SOUND_205fake // Hashcode: 0x2C15C540 (dec: 739624256)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct SOUND_228fake // hashcode: 0xEFC26FBF (dec: -272470081)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0xC04D6F08 (dec: -1068667128), parent name: 'SOUND_228fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0xFA35667D (dec: -97163651), parent name: 'SOUND_228fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SOUND_229fake // hashcode: 0x4F3A8CE4 (dec: 1329237220)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x0ED33608 (dec: 248722952), parent name: 'SOUND_229fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x3591649C (dec: 898720924), parent name: 'SOUND_229fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0xB8BD2FD0 (dec: -1195561008), parent name: 'SOUND_229fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x41309B61 (dec: 1093704545), parent name: 'SOUND_229fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x28770912 (dec: 678889746), parent name: 'SOUND_229fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0xD2848A9E (dec: -763065698), parent name: 'SOUND_229fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SOUND_230fake // Hashcode: 0x8F35CD18 (dec: -1892299496)
{
	struct SOUND_228fake flame; // size=8, offset=0
	struct SOUND_229fake phys;  // size=12, offset=0
};

typedef struct AadInitAttr AadInitAttr;

typedef struct MusicLoadInfo MusicLoadInfo;

typedef struct ObjectPeriodicSound ObjectPeriodicSound;

typedef struct ObjectEventSound ObjectEventSound;

typedef struct ObjectOneShotSound ObjectOneShotSound;

typedef struct SoundEffectChannel SoundEffectChannel;

extern struct SoundEffectChannel *SndOpenSfxChannel(unsigned char *channelNum); // 0x8003E64C

extern void SndCloseSfxChannel(int channelNum); // 0x8003E694

extern struct SoundEffectChannel *SndGetSfxChannel(int channelNum); // 0x8003E6BC

extern void SOUND_ProcessInstanceSounds(unsigned char *sfxFileData, struct SoundInstance *soundInstTbl, struct _Position *position, int livesInOnePlace, int inSpectral, int hidden, int burning, long *triggerFlags); // 0x8003E6E4

extern void SOUND_EndInstanceSounds(unsigned char *sfxFileData, struct SoundInstance *soundInstTbl); // 0x8003E86C

extern int isOkayToPlaySound(int flags, int spectralPlane, int hidden, int burning); // 0x8003E9D8

extern void setPeriodicSoundStateOff(struct SoundInstance *soundInst, struct ObjectPeriodicSound *sound); // 0x8003EAEC

extern void processPeriodicSound(struct _Position *position, int livesInOnePlane, int inSpectral, int hidden, int burning, struct SoundInstance *soundInst, struct ObjectPeriodicSound *sound); // 0x8003EB78

extern void processEventSound(struct _Position *position, struct SoundInstance *soundInst, struct ObjectEventSound *sound); // 0x8003F018

extern void SOUND_StartInstanceSound(struct SoundInstance *soundInst); // 0x8003F3BC

extern void SOUND_StopInstanceSound(struct SoundInstance *soundInst); // 0x8003F3DC

extern int SOUND_IsInstanceSoundLoaded(unsigned char *sfxFileData, long soundNumber); // 0x8003F438

extern void SOUND_SetInstanceSoundPitch(struct SoundInstance *soundInst, long pitchChangeAmt, long time); // 0x8003F534

extern void SOUND_SetInstanceSoundVolume(struct SoundInstance *soundInst, long volumeChangeAmt, long time); // 0x8003F5F4

extern void processOneShotSound(struct _Position *position, int hidden, int burning, long *triggerFlags, struct SoundInstance *soundInst, struct ObjectOneShotSound *sound); // 0x8003F6F8

extern unsigned long SOUND_Play3dSound(struct _Position *position, int sfxToneID, int pitch, int maxVolume, int minVolDist); // 0x8003FA40

extern unsigned long SOUND_Update3dSound(struct _Position *position, unsigned long handle, int pitch, int maxVolume, int minVolDist); // 0x8003FC7C

extern void SOUND_HandleGlobalValueSignal(int name, long data); // 0x8003FEB0

extern void SOUND_Init(); // 0x8003FEB8

extern void SOUND_Free(); // 0x8003FF6C

extern void SOUND_SetMusicVariable(int variable, int value); // 0x8003FF90

extern void SOUND_SetMusicVolume(int newVolume); // 0x8003FFB0

extern void SOUND_SetSfxVolume(int newVolume); // 0x8003FFE4

extern void SOUND_SetVoiceVolume(int newVolume); // 0x80040018

extern void SOUND_PauseAllSound(); // 0x80040038

extern void SOUND_ResumeAllSound(); // 0x80040068

extern void SOUND_StopAllSound(); // 0x80040098

extern void SOUND_ResetAllSound(); // 0x800400D8

extern void SOUND_MusicOff(); // 0x80040108

extern void SOUND_MusicOn(); // 0x8004016C

extern void SOUND_SfxOff(); // 0x800401A4

extern void SOUND_SfxOn(); // 0x800401C4

extern int SndIsPlaying(unsigned long handle); // 0x800401CC

extern int SndIsPlayingOrRequested(unsigned long handle); // 0x800401EC

extern int SndTypeIsPlayingOrRequested(unsigned int sfxToneID); // 0x8004020C

extern unsigned long SndPlay(unsigned int sample); // 0x8004022C

extern void SndEndLoop(unsigned long handle); // 0x80040264

extern unsigned long SndPlayVolPan(unsigned int sample, unsigned short vol, unsigned short pan, short pitch); // 0x80040284

extern unsigned long SndUpdateVolPanPitch(unsigned long handle, unsigned short vol, unsigned short pan, short pitch); // 0x800402C0

extern void musicLoadReturnFunc(int dynamicBankIndex, int errorStatus); // 0x80040308

extern void musicFadeoutReturnFunc(); // 0x8004031C

extern void musicEndCallbackFunc(long userData, int slot, int loopFlag); // 0x80040330

extern void SOUND_PutMusicCommand(int cmdType, int cmdData); // 0x80040390

extern void SOUND_MusicInit(); // 0x800403D8

extern int SOUND_IsMusicLoading(); // 0x80040404

extern void SOUND_ProcessMusicLoad(); // 0x80040434

extern void SOUND_UpdateSound(); // 0x80040930

extern void SOUND_PlaneShift(int newPlane); // 0x800409DC

extern void SOUND_ShutdownMusic(); // 0x80040A18

extern void SOUND_SetMusicModifier(long modifier); // 0x80040ACC

extern void SOUND_ResetMusicModifier(long modifier); // 0x80040B8C

#endif
