#ifndef MONTABLE_H
#define MONTABLE_H

static struct _MonsterFunctionTable DefaultFunctionTable; // offset 0x800CF68C

static struct _MonsterState DefaultStateTable[31]; // offset 0x800CAA20

static struct MONTABLE_207fake functionChoiceTable[6]; // offset 0x800CA9F0

struct MONTABLE_68fake // hashcode: 0x1B499A8D (dec: 457808525)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x8463E7AF (dec: -2073827409), parent name: 'MONTABLE_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0xD9A9D9CC (dec: -643180084), parent name: 'MONTABLE_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_69fake // hashcode: 0x12252360 (dec: 304423776)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x891790FB (dec: -1994944261), parent name: 'MONTABLE_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x5E406FDF (dec: 1581281247), parent name: 'MONTABLE_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_70fake // hashcode: 0x2AAF4937 (dec: 716130615)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x18592048 (dec: 408494152), parent name: 'MONTABLE_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x094809F4 (dec: 155716084), parent name: 'MONTABLE_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONTABLE_71fake // Hashcode: 0xD5F65CA7 (dec: -705274713)
{
	struct MONTABLE_68fake callback; // size=8, offset=0
	struct MONTABLE_69fake vector;   // size=12, offset=0
	struct MONTABLE_70fake quat;	 // size=16, offset=0
};

union MONTABLE_72fake // Hashcode: 0x14670472 (dec: 342295666)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MONTABLE_73fake // Hashcode: 0x2113D71C (dec: 554948380)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct MONTABLE_74fake // hashcode: 0xF4BCAEE3 (dec: -188961053)
{
	union MONTABLE_73fake size; // size=4, offset=0 //  hashcode: 0xE1B5B005 (dec: -508186619), parent name: 'MONTABLE_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_75fake // hashcode: 0xB3E8FB58 (dec: -1276576936)
{
	short x;				// size=0, offset=0 //  hashcode: 0xF762C847 (dec: -144521145), parent name: 'MONTABLE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x50774F68 (dec: 1349996392), parent name: 'MONTABLE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xB61A5CCA (dec: -1239786294), parent name: 'MONTABLE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xFADF9E58 (dec: -86008232), parent name: 'MONTABLE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xADF7BB2A (dec: -1376273622), parent name: 'MONTABLE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_76fake // hashcode: 0x2AC2D3B8 (dec: 717411256)
{
	long index; // size=0, offset=0 //  hashcode: 0x3877A694 (dec: 947365524), parent name: 'MONTABLE_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xA9FCF3C0 (dec: -1443040320), parent name: 'MONTABLE_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_77fake // hashcode: 0x720CECBC (dec: 1913449660)
{
	long index; // size=0, offset=0 //  hashcode: 0xCD946127 (dec: -845913817), parent name: 'MONTABLE_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x9BE7940E (dec: -1679322098), parent name: 'MONTABLE_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_78fake // hashcode: 0x5E2E7575 (dec: 1580103029)
{
	long index; // size=0, offset=0 //  hashcode: 0x7E1E7C5A (dec: 2115927130), parent name: 'MONTABLE_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x33EEE334 (dec: 871293748), parent name: 'MONTABLE_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_79fake // hashcode: 0x68DA50C5 (dec: 1759137989)
{
	long time;  // size=0, offset=0 //  hashcode: 0x0A4CCD6A (dec: 172805482), parent name: 'MONTABLE_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x09DC6190 (dec: 165437840), parent name: 'MONTABLE_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_80fake // hashcode: 0x514CF136 (dec: 1363996982)
{
	long action;   // size=0, offset=0 //  hashcode: 0x9D07969A (dec: -1660447078), parent name: 'MONTABLE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xBDDFE9B6 (dec: -1109399114), parent name: 'MONTABLE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_81fake // hashcode: 0x65C12045 (dec: 1707155525)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xA83F7B6E (dec: -1472234642), parent name: 'MONTABLE_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x792B9B07 (dec: 2032900871), parent name: 'MONTABLE_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_82fake // hashcode: 0x1B47BBEA (dec: 457685994)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xBA27F9F2 (dec: -1171785230), parent name: 'MONTABLE_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x0B2B995C (dec: 187406684), parent name: 'MONTABLE_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_83fake // hashcode: 0x8FE0C00B (dec: -1881096181)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x6D305F67 (dec: 1831886695), parent name: 'MONTABLE_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xAE872ED9 (dec: -1366872359), parent name: 'MONTABLE_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_84fake // hashcode: 0x292375F1 (dec: 690189809)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x58961718 (dec: 1486231320), parent name: 'MONTABLE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x2BBF029F (dec: 733938335), parent name: 'MONTABLE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x27363D48 (dec: 657866056), parent name: 'MONTABLE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xC7BD51EA (dec: -943894038), parent name: 'MONTABLE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xC059A922 (dec: -1067865822), parent name: 'MONTABLE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_85fake // hashcode: 0x0D7DCC96 (dec: 226348182)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xD0963DFD (dec: -795460099), parent name: 'MONTABLE_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xAE0F70A5 (dec: -1374719835), parent name: 'MONTABLE_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_86fake // hashcode: 0x5E6555F3 (dec: 1583699443)
{
	short index;					// size=0, offset=0 //  hashcode: 0xF89BDA8B (dec: -124003701), parent name: 'MONTABLE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x412A1FF3 (dec: 1093279731), parent name: 'MONTABLE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xF2671242 (dec: -228126142), parent name: 'MONTABLE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x62A8768B (dec: 1655207563), parent name: 'MONTABLE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_87fake // hashcode: 0x5ACC2130 (dec: 1523327280)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x40D952CA (dec: 1087984330), parent name: 'MONTABLE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x8A633F96 (dec: -1973207146), parent name: 'MONTABLE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xC08F0DDA (dec: -1064366630), parent name: 'MONTABLE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_88fake // hashcode: 0x9B901170 (dec: -1685057168)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x290C5219 (dec: 688673305), parent name: 'MONTABLE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x2856E4F8 (dec: 676783352), parent name: 'MONTABLE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x52EF5A41 (dec: 1391417921), parent name: 'MONTABLE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x29C90F14 (dec: 701042452), parent name: 'MONTABLE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x7F49C518 (dec: 2135541016), parent name: 'MONTABLE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x3B1FC5D1 (dec: 991938001), parent name: 'MONTABLE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xEA9822E6 (dec: -359128346), parent name: 'MONTABLE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_89fake // hashcode: 0xF3F0DD7B (dec: -202318469)
{
	long index;  // size=0, offset=0 //  hashcode: 0x4BC2F732 (dec: 1271068466), parent name: 'MONTABLE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x7810FD41 (dec: 2014379329), parent name: 'MONTABLE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_90fake // hashcode: 0x290A5E8A (dec: 688545418)
{
	short type; // size=0, offset=0 //  hashcode: 0x209B5909 (dec: 547051785), parent name: 'MONTABLE_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x252D606F (dec: 623730799), parent name: 'MONTABLE_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_91fake // hashcode: 0x64429814 (dec: 1682085908)
{
	long time;   // size=0, offset=0 //  hashcode: 0x47690C9A (dec: 1198066842), parent name: 'MONTABLE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x908AA7B8 (dec: -1869961288), parent name: 'MONTABLE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_92fake // hashcode: 0x64BE4CA9 (dec: 1690193065)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x52F28FBB (dec: 1391628219), parent name: 'MONTABLE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xD6358A38 (dec: -701134280), parent name: 'MONTABLE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_93fake // hashcode: 0x6566CC90 (dec: 1701235856)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xB34F6873 (dec: -1286641549), parent name: 'MONTABLE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xC6E96CFC (dec: -957780740), parent name: 'MONTABLE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_94fake // hashcode: 0xCCCFC334 (dec: -858799308)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x93B0714B (dec: -1817153205), parent name: 'MONTABLE_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x28A8382E (dec: 682113070), parent name: 'MONTABLE_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_95fake // hashcode: 0xFEAE0448 (dec: -22150072)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x50705DC6 (dec: 1349541318), parent name: 'MONTABLE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x7F5B17FB (dec: 2136676347), parent name: 'MONTABLE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xC01AC5D9 (dec: -1071987239), parent name: 'MONTABLE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x7CCA0DDE (dec: 2093616606), parent name: 'MONTABLE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_96fake // hashcode: 0xCE4050AF (dec: -834645841)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x9DAFFC14 (dec: -1649411052), parent name: 'MONTABLE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x1D4557F0 (dec: 491083760), parent name: 'MONTABLE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x828DC517 (dec: -2104638185), parent name: 'MONTABLE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x69853C0A (dec: 1770339338), parent name: 'MONTABLE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xF94B5183 (dec: -112504445), parent name: 'MONTABLE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONTABLE_97fake // Hashcode: 0x40894F64 (dec: 1082740580)
{
	struct MONTABLE_74fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;		 // size=24, offset=0
	struct MONTABLE_75fake teleport;	 // size=16, offset=0
	struct MONTABLE_76fake cameraValue;  // size=8, offset=0
	struct MONTABLE_77fake miscValue;	// size=8, offset=0
	struct MONTABLE_78fake logicValue;   // size=8, offset=0
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
	struct MONTABLE_79fake cameraShake;  // size=8, offset=0
	long cameraSave;					 // size=0, offset=0
	long cameraRestore;					 // size=0, offset=0
	struct _BGObject *bgObject;			 // size=24, offset=0
	long value[2];						 // size=8, offset=0
	struct MONTABLE_80fake sound;		 // size=12, offset=0
	void *intro;						 // size=0, offset=0
	long deathZ;						 // size=0, offset=0
	struct MONTABLE_81fake dsignal;		 // size=8, offset=0
	void *mirror;						 // size=0, offset=0
	long fogNear;						 // size=0, offset=0
	long fogFar;						 // size=0, offset=0
	struct MONTABLE_82fake gotoFrame;	// size=8, offset=0
	struct MONTABLE_83fake changeModel;  // size=8, offset=0
	void *vmObject;						 // size=0, offset=0
	struct MONTABLE_84fake logic;		 // size=8, offset=0
	void *callSignal;					 // size=0, offset=0
	struct _SVector offset;				 // size=8, offset=0
	struct Signal *gotoLabel;			 // size=0, offset=0
	struct Signal *gosubLabel;			 // size=0, offset=0
	struct MONTABLE_85fake control;		 // size=8, offset=0
	struct MONTABLE_86fake zSignal;		 // size=12, offset=0
	struct MONTABLE_87fake StreamLevel;  // size=24, offset=0
	struct MONTABLE_88fake shards;		 // size=12, offset=0
	struct MONTABLE_89fake cameraSpline; // size=8, offset=0
	struct MONTABLE_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;					 // size=0, offset=0
	struct MONTABLE_91fake introFX;		 // size=8, offset=0
	struct MONTABLE_92fake introActive;  // size=8, offset=0
	struct MONTABLE_93fake levelChange;  // size=18, offset=0
	long blendStart;					 // size=0, offset=0
	struct MONTABLE_94fake setTimes;	 // size=8, offset=0
	struct MONTABLE_95fake color;		 // size=4, offset=0
	struct MONTABLE_96fake print;		 // size=12, offset=0
	long slideAngle;					 // size=0, offset=0
};

union MONTABLE_98fake // Hashcode: 0x26981036 (dec: 647499830)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union MONTABLE_103fake // Hashcode: 0xAA94E813 (dec: -1433081837)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct MONTABLE_105fake // hashcode: 0x6924B44C (dec: 1764013132)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xC6DDE167 (dec: -958537369), parent name: 'MONTABLE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xA63D9116 (dec: -1505914602), parent name: 'MONTABLE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x6E5D0724 (dec: 1851590436), parent name: 'MONTABLE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x27FF577D (dec: 671045501), parent name: 'MONTABLE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0xEA0B1ABA (dec: -368371014), parent name: 'MONTABLE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xE95EBE74 (dec: -379666828), parent name: 'MONTABLE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x9821455A (dec: -1742650022), parent name: 'MONTABLE_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_106fake // hashcode: 0x41311884 (dec: 1093736580)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x523A7B72 (dec: 1379564402), parent name: 'MONTABLE_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x02F53C3A (dec: 49626170), parent name: 'MONTABLE_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x343CD874 (dec: 876402804), parent name: 'MONTABLE_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_107fake // hashcode: 0x6A402D2A (dec: 1782590762)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x9CBEDDEA (dec: -1665212950), parent name: 'MONTABLE_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xEE55FDA6 (dec: -296354394), parent name: 'MONTABLE_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x5B8A1FC2 (dec: 1535778754), parent name: 'MONTABLE_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xD5C6C024 (dec: -708394972), parent name: 'MONTABLE_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x67770D3E (dec: 1735855422), parent name: 'MONTABLE_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_108fake // hashcode: 0xE960DCE1 (dec: -379527967)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xE214E64A (dec: -501946806), parent name: 'MONTABLE_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0xD4434D38 (dec: -733786824), parent name: 'MONTABLE_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x3DD45C3E (dec: 1037327422), parent name: 'MONTABLE_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x5D549A37 (dec: 1565825591), parent name: 'MONTABLE_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x54E6FD76 (dec: 1424424310), parent name: 'MONTABLE_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONTABLE_109fake // hashcode: 0xD09BCEF5 (dec: -795095307)
{
	struct MONTABLE_105fake Cinematic; // size=28, offset=0 //  hashcode: 0xD5C1C2BA (dec: -708721990), parent name: 'MONTABLE_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MONTABLE_106fake Idle;	  // size=20, offset=28 //  hashcode: 0xE2C7794A (dec: -490243766), parent name: 'MONTABLE_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MONTABLE_107fake Behind;	// size=28, offset=48 //  hashcode: 0xD6E9910D (dec: -689336051), parent name: 'MONTABLE_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MONTABLE_108fake Follow;	// size=20, offset=76 //  hashcode: 0x0A271257 (dec: 170332759), parent name: 'MONTABLE_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONTABLE_188fake // Hashcode: 0x19B6D4AD (dec: 431412397)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct MONTABLE_207fake // hashcode: 0x35A35A66 (dec: 899897958)
{
	long whatAmI;						 // size=0, offset=0 //  hashcode: 0x5B1E8F98 (dec: 1528729496), parent name: 'MONTABLE_207fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterFunctionTable *table; // size=32, offset=4 //  hashcode: 0x44133B16 (dec: 1142110998), parent name: 'MONTABLE_207fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

extern void MONTABLE_SetupTablePointer(struct Object *object); // 0x8008CE88

extern struct _MonsterState *MONTABLE_GetStateFuncs(struct _Instance *instance, int state); // 0x8008CED8

extern TDRFuncPtr_MONTABLE_GetDamageEffectFunc MONTABLE_GetDamageEffectFunc(struct _Instance *instance); // 0x8008CF48

extern TDRFuncPtr_MONTABLE_GetInitFunc MONTABLE_GetInitFunc(struct _Instance *instance); // 0x8008CF7C

extern TDRFuncPtr_MONTABLE_GetCleanUpFunc MONTABLE_GetCleanUpFunc(struct _Instance *instance); // 0x8008CFB0

extern void MONTABLE_SetQueryFunc(struct _Instance *instance); // 0x8008CFE4

extern void MONTABLE_SetMessageFunc(struct _Instance *instance); // 0x8008D018

typedef void (*TDRFuncPtr_MONTABLE_GetCleanUpFunc)();

typedef void (*TDRFuncPtr_MONTABLE_GetDamageEffectFunc)();

typedef void (*TDRFuncPtr_MONTABLE_GetInitFunc)();

#endif
