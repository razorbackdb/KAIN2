#ifndef MEMPACK_H
#define MEMPACK_H

#include "PLAYER.H"
#include "DEBUG.H"

struct NewMemTracker // hashcode: 0x5C68280F (dec: 1550329871)
{
	struct MemHeader *rootNode;		 // size=8, offset=0 //  hashcode: 0x1223120A (dec: 304288266), parent name: 'NewMemTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long totalMemory;		 // size=0, offset=4 //  hashcode: 0x6AF9C2EC (dec: 1794753260), parent name: 'NewMemTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long currentMemoryUsed; // size=0, offset=8 //  hashcode: 0xB0F25C39 (dec: -1326293959), parent name: 'NewMemTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *lastMemoryAddress;		 // size=0, offset=12 //  hashcode: 0x23345FE6 (dec: 590634982), parent name: 'NewMemTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long doingGarbageCollection;	 // size=0, offset=16 //  hashcode: 0x4C0110B4 (dec: 1275138228), parent name: 'NewMemTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
};

static struct NewMemTracker newMemTracker; // offset 0x800D18D4

struct MEMPACK_68fake // hashcode: 0xE87C49A0 (dec: -394507872)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x163901A8 (dec: 372834728), parent name: 'MEMPACK_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x32CD4B4B (dec: 852314955), parent name: 'MEMPACK_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_69fake // hashcode: 0xC4FF4348 (dec: -989904056)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x06564ECB (dec: 106319563), parent name: 'MEMPACK_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x3FEB8A32 (dec: 1072400946), parent name: 'MEMPACK_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_70fake // hashcode: 0x0F0C1516 (dec: 252450070)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xC0033EFF (dec: -1073529089), parent name: 'MEMPACK_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x0F23A365 (dec: 253993829), parent name: 'MEMPACK_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MEMPACK_71fake // Hashcode: 0x13120B58 (dec: 319949656)
{
	struct MEMPACK_68fake callback; // size=8, offset=0
	struct MEMPACK_69fake vector;   // size=12, offset=0
	struct MEMPACK_70fake quat;		// size=16, offset=0
};

union MEMPACK_72fake // Hashcode: 0x11956E16 (dec: 295005718)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MEMPACK_73fake // Hashcode: 0xA320CFFA (dec: -1558130694)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct MEMPACK_74fake // hashcode: 0x5E3DF4E5 (dec: 1581118693)
{
	union MEMPACK_73fake size; // size=4, offset=0 //  hashcode: 0x65AF2D3F (dec: 1705979199), parent name: 'MEMPACK_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_75fake // hashcode: 0x5014D9E5 (dec: 1343543781)
{
	short x;				// size=0, offset=0 //  hashcode: 0x50474E33 (dec: 1346850355), parent name: 'MEMPACK_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xC95943C5 (dec: -916896827), parent name: 'MEMPACK_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x0C07CAE2 (dec: 201837282), parent name: 'MEMPACK_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x4FDBBF2C (dec: 1339801388), parent name: 'MEMPACK_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x1BDAC6D6 (dec: 467322582), parent name: 'MEMPACK_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_76fake // hashcode: 0xE5F15A1A (dec: -437167590)
{
	long index; // size=0, offset=0 //  hashcode: 0x5B45E8A1 (dec: 1531308193), parent name: 'MEMPACK_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xA93BAC8C (dec: -1455706996), parent name: 'MEMPACK_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_77fake // hashcode: 0x8B57EC05 (dec: -1957172219)
{
	long index; // size=0, offset=0 //  hashcode: 0x14193755 (dec: 337196885), parent name: 'MEMPACK_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xCF311019 (dec: -818868199), parent name: 'MEMPACK_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_78fake // hashcode: 0xF54980D3 (dec: -179732269)
{
	long index; // size=0, offset=0 //  hashcode: 0xCB21273D (dec: -887019715), parent name: 'MEMPACK_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x496FEFB3 (dec: 1232072627), parent name: 'MEMPACK_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_79fake // hashcode: 0x8A684D11 (dec: -1972876015)
{
	long time;  // size=0, offset=0 //  hashcode: 0xC0E90F6A (dec: -1058467990), parent name: 'MEMPACK_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x5C6FDBD1 (dec: 1550834641), parent name: 'MEMPACK_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_80fake // hashcode: 0xEEDB6739 (dec: -287611079)
{
	long action;   // size=0, offset=0 //  hashcode: 0x677C05EB (dec: 1736181227), parent name: 'MEMPACK_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x8EAFB4CF (dec: -1901087537), parent name: 'MEMPACK_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_81fake // hashcode: 0xCC4AEEBB (dec: -867504453)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x02307230 (dec: 36729392), parent name: 'MEMPACK_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x5FE952AB (dec: 1609126571), parent name: 'MEMPACK_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_82fake // hashcode: 0xB006929B (dec: -1341746533)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x05549055 (dec: 89428053), parent name: 'MEMPACK_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0xB144FCA2 (dec: -1320878942), parent name: 'MEMPACK_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_83fake // hashcode: 0x3FC8EDBA (dec: 1070132666)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xB6F0E98B (dec: -1225725557), parent name: 'MEMPACK_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x992F971F (dec: -1724934369), parent name: 'MEMPACK_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_84fake // hashcode: 0xCC548705 (dec: -866875643)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x01C0556B (dec: 29381995), parent name: 'MEMPACK_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x2C6189A3 (dec: 744589731), parent name: 'MEMPACK_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x961C4DB4 (dec: -1776529996), parent name: 'MEMPACK_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x66DEED3F (dec: 1725885759), parent name: 'MEMPACK_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xE444C44F (dec: -465255345), parent name: 'MEMPACK_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_85fake // hashcode: 0xD3BB0BE2 (dec: -742716446)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x671D664C (dec: 1729979980), parent name: 'MEMPACK_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xCB6DA069 (dec: -882007959), parent name: 'MEMPACK_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_86fake // hashcode: 0x0CDC0712 (dec: 215746322)
{
	short index;					// size=0, offset=0 //  hashcode: 0xBA76B404 (dec: -1166625788), parent name: 'MEMPACK_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xE46BFBC2 (dec: -462685246), parent name: 'MEMPACK_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x45A91B21 (dec: 1168710433), parent name: 'MEMPACK_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x7EBD08FF (dec: 2126317823), parent name: 'MEMPACK_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_87fake // hashcode: 0x29EE86AA (dec: 703497898)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x531E54BE (dec: 1394496702), parent name: 'MEMPACK_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x6FB1AACD (dec: 1873914573), parent name: 'MEMPACK_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xBCB15696 (dec: -1129228650), parent name: 'MEMPACK_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_88fake // hashcode: 0x98797668 (dec: -1736870296)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x61444B1D (dec: 1631865629), parent name: 'MEMPACK_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xB84DD510 (dec: -1202858736), parent name: 'MEMPACK_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x0E72FBDE (dec: 242416606), parent name: 'MEMPACK_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x16761240 (dec: 376836672), parent name: 'MEMPACK_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x11C1553A (dec: 297882938), parent name: 'MEMPACK_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xE81D6ECC (dec: -400724276), parent name: 'MEMPACK_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x9F6CD52B (dec: -1620257493), parent name: 'MEMPACK_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_89fake // hashcode: 0xF4DC6262 (dec: -186883486)
{
	long index;  // size=0, offset=0 //  hashcode: 0x84B9ABFB (dec: -2068206597), parent name: 'MEMPACK_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x6BB30829 (dec: 1806895145), parent name: 'MEMPACK_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_90fake // hashcode: 0x800637B2 (dec: -2147076174)
{
	short type; // size=0, offset=0 //  hashcode: 0x526D1F06 (dec: 1382883078), parent name: 'MEMPACK_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xA4D44A38 (dec: -1529591240), parent name: 'MEMPACK_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_91fake // hashcode: 0xB8692D5D (dec: -1201066659)
{
	long time;   // size=0, offset=0 //  hashcode: 0xF7E8BB09 (dec: -135742711), parent name: 'MEMPACK_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x9834B7DE (dec: -1741375522), parent name: 'MEMPACK_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_92fake // hashcode: 0x4B64CA86 (dec: 1264896646)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xE3176307 (dec: -485006585), parent name: 'MEMPACK_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x0D8E55E1 (dec: 227431905), parent name: 'MEMPACK_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_93fake // hashcode: 0xAC1FDC2A (dec: -1407198166)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xEC24D0DD (dec: -333131555), parent name: 'MEMPACK_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x7DB1FBA8 (dec: 2108816296), parent name: 'MEMPACK_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_94fake // hashcode: 0x347A74AE (dec: 880440494)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x201AC561 (dec: 538625377), parent name: 'MEMPACK_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xB1E44F93 (dec: -1310437485), parent name: 'MEMPACK_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_95fake // hashcode: 0xCC63569F (dec: -865904993)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0xBDE57CC2 (dec: -1109033790), parent name: 'MEMPACK_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x7F1B56DB (dec: 2132498139), parent name: 'MEMPACK_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x5D10A556 (dec: 1561371990), parent name: 'MEMPACK_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xF372850D (dec: -210598643), parent name: 'MEMPACK_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_96fake // hashcode: 0x8AC5433F (dec: -1966783681)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x350B8CE7 (dec: 889949415), parent name: 'MEMPACK_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xC921AA88 (dec: -920540536), parent name: 'MEMPACK_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x024FF8D6 (dec: 38795478), parent name: 'MEMPACK_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x0F0E3F05 (dec: 252591877), parent name: 'MEMPACK_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x46745FA6 (dec: 1182031782), parent name: 'MEMPACK_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MEMPACK_97fake // Hashcode: 0x96CA1511 (dec: -1765141231)
{
	struct MEMPACK_74fake misc[3];		// size=12, offset=0
	struct _CameraKey *cameraKey;		// size=24, offset=0
	struct MEMPACK_75fake teleport;		// size=16, offset=0
	struct MEMPACK_76fake cameraValue;  // size=8, offset=0
	struct MEMPACK_77fake miscValue;	// size=8, offset=0
	struct MEMPACK_78fake logicValue;   // size=8, offset=0
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
	struct MEMPACK_79fake cameraShake;  // size=8, offset=0
	long cameraSave;					// size=0, offset=0
	long cameraRestore;					// size=0, offset=0
	struct _BGObject *bgObject;			// size=24, offset=0
	long value[2];						// size=8, offset=0
	struct MEMPACK_80fake sound;		// size=12, offset=0
	void *intro;						// size=0, offset=0
	long deathZ;						// size=0, offset=0
	struct MEMPACK_81fake dsignal;		// size=8, offset=0
	void *mirror;						// size=0, offset=0
	long fogNear;						// size=0, offset=0
	long fogFar;						// size=0, offset=0
	struct MEMPACK_82fake gotoFrame;	// size=8, offset=0
	struct MEMPACK_83fake changeModel;  // size=8, offset=0
	void *vmObject;						// size=0, offset=0
	struct MEMPACK_84fake logic;		// size=8, offset=0
	void *callSignal;					// size=0, offset=0
	struct _SVector offset;				// size=8, offset=0
	struct Signal *gotoLabel;			// size=0, offset=0
	struct Signal *gosubLabel;			// size=0, offset=0
	struct MEMPACK_85fake control;		// size=8, offset=0
	struct MEMPACK_86fake zSignal;		// size=12, offset=0
	struct MEMPACK_87fake StreamLevel;  // size=24, offset=0
	struct MEMPACK_88fake shards;		// size=12, offset=0
	struct MEMPACK_89fake cameraSpline; // size=8, offset=0
	struct MEMPACK_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;					// size=0, offset=0
	struct MEMPACK_91fake introFX;		// size=8, offset=0
	struct MEMPACK_92fake introActive;  // size=8, offset=0
	struct MEMPACK_93fake levelChange;  // size=18, offset=0
	long blendStart;					// size=0, offset=0
	struct MEMPACK_94fake setTimes;		// size=8, offset=0
	struct MEMPACK_95fake color;		// size=4, offset=0
	struct MEMPACK_96fake print;		// size=12, offset=0
	long slideAngle;					// size=0, offset=0
};

union MEMPACK_98fake // Hashcode: 0x73D5A53E (dec: 1943381310)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union MEMPACK_103fake // Hashcode: 0x873067CD (dec: -2026870835)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct MEMPACK_105fake // hashcode: 0x60F5A5A4 (dec: 1626711460)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xC54C4427 (dec: -984857561), parent name: 'MEMPACK_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x53BA6352 (dec: 1404724050), parent name: 'MEMPACK_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x5BE77145 (dec: 1541894469), parent name: 'MEMPACK_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x3330720D (dec: 858812941), parent name: 'MEMPACK_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x07958A96 (dec: 127240854), parent name: 'MEMPACK_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x8D678228 (dec: -1922596312), parent name: 'MEMPACK_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xF9C16A57 (dec: -104764841), parent name: 'MEMPACK_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_106fake // hashcode: 0x9A54DECE (dec: -1705713970)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0xE2EB6376 (dec: -487890058), parent name: 'MEMPACK_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x78658814 (dec: 2019919892), parent name: 'MEMPACK_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x3F0D86D7 (dec: 1057851095), parent name: 'MEMPACK_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_107fake // hashcode: 0x083A7DB6 (dec: 138050998)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x1387F14D (dec: 327676237), parent name: 'MEMPACK_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xC916ED49 (dec: -921244343), parent name: 'MEMPACK_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x62A5C53A (dec: 1655031098), parent name: 'MEMPACK_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x4BCC377D (dec: 1271674749), parent name: 'MEMPACK_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x8DD2611B (dec: -1915592421), parent name: 'MEMPACK_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_108fake // hashcode: 0xE1608411 (dec: -513768431)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x5B4DE6FF (dec: 1531832063), parent name: 'MEMPACK_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x87D5503A (dec: -2016063430), parent name: 'MEMPACK_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x6D302BA2 (dec: 1831873442), parent name: 'MEMPACK_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x8BA572C0 (dec: -1952091456), parent name: 'MEMPACK_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xB0B56E64 (dec: -1330287004), parent name: 'MEMPACK_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_109fake // hashcode: 0xD24D2E1C (dec: -766693860)
{
	struct MEMPACK_105fake Cinematic; // size=28, offset=0 //  hashcode: 0x27DB8F0B (dec: 668700427), parent name: 'MEMPACK_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MEMPACK_106fake Idle;	  // size=20, offset=28 //  hashcode: 0x16641646 (dec: 375658054), parent name: 'MEMPACK_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MEMPACK_107fake Behind;	// size=28, offset=48 //  hashcode: 0xEE2135B5 (dec: -299813451), parent name: 'MEMPACK_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MEMPACK_108fake Follow;	// size=20, offset=76 //  hashcode: 0x86B96597 (dec: -2034670185), parent name: 'MEMPACK_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MEMPACK_188fake // Hashcode: 0x583B4A58 (dec: 1480280664)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct MEMPACK_235fake // hashcode: 0xD67F31CB (dec: -696307253)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x68FC5D11 (dec: 1761369361), parent name: 'MEMPACK_235fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x6A721EEA (dec: 1785863914), parent name: 'MEMPACK_235fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_236fake // hashcode: 0xAA4CBC41 (dec: -1437811647)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0xAE8D0F96 (dec: -1366487146), parent name: 'MEMPACK_236fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0xBC63A565 (dec: -1134320283), parent name: 'MEMPACK_236fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x9B9393BE (dec: -1684827202), parent name: 'MEMPACK_236fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x5F4C324C (dec: 1598829132), parent name: 'MEMPACK_236fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x96B7ED6A (dec: -1766331030), parent name: 'MEMPACK_236fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x8EFB1B28 (dec: -1896146136), parent name: 'MEMPACK_236fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MEMPACK_237fake // Hashcode: 0x1F0179C2 (dec: 520190402)
{
	struct MEMPACK_235fake flame; // size=8, offset=0
	struct MEMPACK_236fake phys;  // size=12, offset=0
};

union MEMPACK_243fake // Hashcode: 0xFF7DC21B (dec: -8535525)
{
	struct Intro *intro;	   // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

union MEMPACK_245fake // Hashcode: 0x1B45761F (dec: 457537055)
{
	struct _Instance *instance; // size=616, offset=0
	struct _SFXMkr *sfxMarker;  // size=36, offset=0
};

struct MEMPACK_246fake // hashcode: 0xCA960F5D (dec: -896135331)
{
	long instanceNumber; // size=0, offset=0 //  hashcode: 0x3624E9EC (dec: 908388844), parent name: 'MEMPACK_246fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;		 // size=0, offset=4 //  hashcode: 0x7A9683AB (dec: 2056684459), parent name: 'MEMPACK_246fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_247fake // hashcode: 0xB2793581 (dec: -1300679295)
{
	struct _SavedIntro *intro; // size=40, offset=0 //  hashcode: 0x0AC62D18 (dec: 180759832), parent name: 'MEMPACK_247fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;			   // size=0, offset=4 //  hashcode: 0x8E98527E (dec: -1902620034), parent name: 'MEMPACK_247fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_248fake // hashcode: 0xDECDF8AD (dec: -556926803)
{
	long currentNumber; // size=0, offset=0 //  hashcode: 0xD192DF19 (dec: -778903783), parent name: 'MEMPACK_248fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long error;			// size=0, offset=4 //  hashcode: 0x6BE8668D (dec: 1810392717), parent name: 'MEMPACK_248fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;		// size=0, offset=8 //  hashcode: 0x5E6F5808 (dec: 1584355336), parent name: 'MEMPACK_248fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_249fake // hashcode: 0x68B8572C (dec: 1756911404)
{
	short vx; // size=0, offset=0 //  hashcode: 0xD08DA3ED (dec: -796023827), parent name: 'MEMPACK_249fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vy; // size=0, offset=2 //  hashcode: 0xC93FCD2E (dec: -918565586), parent name: 'MEMPACK_249fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_250fake // hashcode: 0x7DC65E13 (dec: 2110152211)
{
	char *pointer; // size=0, offset=0 //  hashcode: 0xFDC66622 (dec: -37329374), parent name: 'MEMPACK_250fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_251fake // hashcode: 0x4383AFEA (dec: 1132703722)
{
	short *pointer; // size=0, offset=0 //  hashcode: 0xDCF116B9 (dec: -588179783), parent name: 'MEMPACK_251fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMPACK_252fake // hashcode: 0x3B8BD94A (dec: 999020874)
{
	long *pointer; // size=0, offset=0 //  hashcode: 0x12F02D37 (dec: 317730103), parent name: 'MEMPACK_252fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MEMPACK_253fake // Hashcode: 0x8DD50FBE (dec: -1915416642)
{
	struct MEMPACK_246fake Object;					  // size=8, offset=0
	struct MEMPACK_247fake SavedIntroObject;		  // size=8, offset=0
	struct InstanceSpline instanceSpline;			  // size=24, offset=0
	struct MEMPACK_248fake Number;					  // size=12, offset=0
	struct MEMPACK_249fake Vector2d;				  // size=4, offset=0
	struct MEMPACK_250fake CharPointer;				  // size=4, offset=0
	struct MEMPACK_251fake ShortPointer;			  // size=4, offset=0
	struct MEMPACK_252fake LongPointer;				  // size=4, offset=0
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

typedef struct NewMemTracker NewMemTracker;

extern void MEMPACK_Init(); // 0x8004FAA4

extern struct MemHeader *MEMPACK_GetSmallestBlockTopBottom(long allocSize); // 0x8004FB0C

extern struct MemHeader *MEMPACK_GetSmallestBlockBottomTop(long allocSize); // 0x8004FB74

extern long MEMPACK_RelocatableType(long memType); // 0x8004FBE0

extern char *MEMPACK_Malloc(unsigned long allocSize, unsigned char memType); // 0x8004FC18

extern char *MEMPACK_MallocFailOk(unsigned long allocSize, unsigned char memType); // 0x8004FC94

extern void MEMORY_MergeAddresses(struct MemHeader *firstAddress, struct MemHeader *secondAddress); // 0x8004FE20

extern void MEMPACK_Return(char *address, long takeBackSize); // 0x8004FE68

extern void MEMPACK_Free(char *address); // 0x8004FEEC

extern void MEMPACK_FreeByType(unsigned char memType); // 0x8004FF9C

extern unsigned long MEMPACK_Size(char *address); // 0x80050034

extern unsigned long MEMPACK_ReportFreeMemory(); // 0x80050040

extern void MEMPACK_ReportMemory2(); // 0x80050050

extern void MEMPACK_ReportMemory(); // 0x80050080

extern void MEMPACK_SetMemoryBeingStreamed(char *address); // 0x8005011C

extern void MEMPACK_SetMemoryDoneStreamed(char *address); // 0x80050128

extern long MEMPACK_MemoryValidFunc(char *address); // 0x80050134

extern char *MEMPACK_GarbageCollectMalloc(unsigned long *allocSize, unsigned char memType, unsigned long *freeSize); // 0x80050168

extern void MEMPACK_GarbageSplitMemoryNow(unsigned long allocSize, struct MemHeader *bestAddress, long memType, unsigned long freeSize); // 0x800502CC

extern void MEMPACK_GarbageCollectFree(struct MemHeader *memAddress); // 0x800502F0

extern void MEMPACK_DoGarbageCollection(); // 0x800503A0

extern void MEMPACK_RelocateAreaType(struct MemHeader *newAddress, long offset, struct Level *oldLevel); // 0x800505BC

extern void MEMPACK_RelocateG2AnimKeylistType(struct _G2AnimKeylist_Type **pKeylist, int offset, char *start, char *end); // 0x80050EA0

extern void MEMPACK_RelocateObjectType(struct MemHeader *newAddress, long offset, struct Object *oldObject); // 0x80050F40

extern void MEMPACK_RelocateCDMemory(struct MemHeader *newAddress, long offset, struct _BigFileDir *oldDir); // 0x800514B0

#endif
