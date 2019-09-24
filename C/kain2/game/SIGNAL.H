#ifndef SIGNAL_H
#define SIGNAL_H

extern struct SignalInfo signalInfoList[27]; // offset 0x800CDFC0

struct SIGNAL_68fake // hashcode: 0x4CA45085 (dec: 1285836933)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xBDA82756 (dec: -1113053354), parent name: 'SIGNAL_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0xF79D0C88 (dec: -140702584), parent name: 'SIGNAL_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_69fake // hashcode: 0x101FD2FB (dec: 270521083)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xDB2F9D51 (dec: -617636527), parent name: 'SIGNAL_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x1173D2DF (dec: 292803295), parent name: 'SIGNAL_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_70fake // hashcode: 0xC84222EA (dec: -935189782)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x64669FFA (dec: 1684447226), parent name: 'SIGNAL_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x577E2DCB (dec: 1467887051), parent name: 'SIGNAL_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SIGNAL_71fake // Hashcode: 0x60202F31 (dec: 1612721969)
{
	struct SIGNAL_68fake callback; // size=8, offset=0
	struct SIGNAL_69fake vector;   // size=12, offset=0
	struct SIGNAL_70fake quat;	 // size=16, offset=0
};

union SIGNAL_72fake // Hashcode: 0x4AF92C48 (dec: 1257843784)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union SIGNAL_73fake // Hashcode: 0x2B1FC5EF (dec: 723502575)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct SIGNAL_74fake // hashcode: 0x3D90AB94 (dec: 1032891284)
{
	union SIGNAL_73fake size; // size=4, offset=0 //  hashcode: 0x99778DE6 (dec: -1720218138), parent name: 'SIGNAL_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_75fake // hashcode: 0xDA9B4BC5 (dec: -627356731)
{
	short x;				// size=0, offset=0 //  hashcode: 0xAD0FD439 (dec: -1391471559), parent name: 'SIGNAL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xF2609D52 (dec: -228549294), parent name: 'SIGNAL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xFC8AD6B5 (dec: -58009931), parent name: 'SIGNAL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xA5ED74DE (dec: -1511164706), parent name: 'SIGNAL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x25C40817 (dec: 633604119), parent name: 'SIGNAL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_76fake // hashcode: 0xCB30D9A7 (dec: -885991001)
{
	long index; // size=0, offset=0 //  hashcode: 0x84D6EFF3 (dec: -2066288653), parent name: 'SIGNAL_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x2ADE4BBA (dec: 719211450), parent name: 'SIGNAL_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_77fake // hashcode: 0xDF3CD107 (dec: -549662457)
{
	long index; // size=0, offset=0 //  hashcode: 0x5D64EFBB (dec: 1566896059), parent name: 'SIGNAL_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xB940B5D0 (dec: -1186941488), parent name: 'SIGNAL_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_78fake // hashcode: 0xCB465363 (dec: -884583581)
{
	long index; // size=0, offset=0 //  hashcode: 0xB5F32597 (dec: -1242356329), parent name: 'SIGNAL_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xFBB30CED (dec: -72151827), parent name: 'SIGNAL_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_79fake // hashcode: 0x3F07A700 (dec: 1057466112)
{
	long time;  // size=0, offset=0 //  hashcode: 0xE027AD54 (dec: -534270636), parent name: 'SIGNAL_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x5D15C76B (dec: 1561708395), parent name: 'SIGNAL_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_80fake // hashcode: 0x7DC48E09 (dec: 2110033417)
{
	long action;   // size=0, offset=0 //  hashcode: 0xBA390B2E (dec: -1170666706), parent name: 'SIGNAL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x7DFF4904 (dec: 2113882372), parent name: 'SIGNAL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_81fake // hashcode: 0x00043DA2 (dec: 277922)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x41B58156 (dec: 1102414166), parent name: 'SIGNAL_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x19AE89D8 (dec: 430868952), parent name: 'SIGNAL_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_82fake // hashcode: 0x3D412166 (dec: 1027678566)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x43F3D016 (dec: 1140051990), parent name: 'SIGNAL_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x9F885E1C (dec: -1618452964), parent name: 'SIGNAL_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_83fake // hashcode: 0xC1F722D6 (dec: -1040768298)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x59E56689 (dec: 1508206217), parent name: 'SIGNAL_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x77F7A5D5 (dec: 2012718549), parent name: 'SIGNAL_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_84fake // hashcode: 0x6C9537A0 (dec: 1821718432)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x753A7285 (dec: 1966764677), parent name: 'SIGNAL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x3B2E97FA (dec: 992909306), parent name: 'SIGNAL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x84508AAC (dec: -2075096404), parent name: 'SIGNAL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x85923C95 (dec: -2054013803), parent name: 'SIGNAL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xF130BE2D (dec: -248463827), parent name: 'SIGNAL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_85fake // hashcode: 0x7692A0BA (dec: 1989320890)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xB7F19279 (dec: -1208905095), parent name: 'SIGNAL_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x327FC42B (dec: 847234091), parent name: 'SIGNAL_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_86fake // hashcode: 0x349CE32D (dec: 882697005)
{
	short index;					// size=0, offset=0 //  hashcode: 0x9E134E5F (dec: -1642901921), parent name: 'SIGNAL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xAF025345 (dec: -1358802107), parent name: 'SIGNAL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xC896ADF7 (dec: -929649161), parent name: 'SIGNAL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x4D8CBDF1 (dec: 1301069297), parent name: 'SIGNAL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_87fake // hashcode: 0x711EF9C7 (dec: 1897855431)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x07CA0A74 (dec: 130681460), parent name: 'SIGNAL_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x5BE55CE8 (dec: 1541758184), parent name: 'SIGNAL_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xAE2269A3 (dec: -1373476445), parent name: 'SIGNAL_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_88fake // hashcode: 0xFBE93F77 (dec: -68599945)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xD3F614C3 (dec: -738847549), parent name: 'SIGNAL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x1022AD2F (dec: 270708015), parent name: 'SIGNAL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x15BCC0C8 (dec: 364691656), parent name: 'SIGNAL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x4F913CDA (dec: 1334918362), parent name: 'SIGNAL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x72C9FA64 (dec: 1925839460), parent name: 'SIGNAL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x53160AEF (dec: 1393953519), parent name: 'SIGNAL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x93330D25 (dec: -1825370843), parent name: 'SIGNAL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_89fake // hashcode: 0xD9DE33B4 (dec: -639749196)
{
	long index;  // size=0, offset=0 //  hashcode: 0xAE41D93D (dec: -1371416259), parent name: 'SIGNAL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xEB5B8593 (dec: -346323565), parent name: 'SIGNAL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_90fake // hashcode: 0xDDAF808B (dec: -575700853)
{
	short type; // size=0, offset=0 //  hashcode: 0x3E75595C (dec: 1047877980), parent name: 'SIGNAL_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xDA65E0FB (dec: -630857477), parent name: 'SIGNAL_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_91fake // hashcode: 0xF5EEBF7B (dec: -168902789)
{
	long time;   // size=0, offset=0 //  hashcode: 0x347C64FC (dec: 880567548), parent name: 'SIGNAL_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xA5E34524 (dec: -1511832284), parent name: 'SIGNAL_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_92fake // hashcode: 0x5335B392 (dec: 1396028306)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x0D5E741A (dec: 224293914), parent name: 'SIGNAL_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x033466A4 (dec: 53765796), parent name: 'SIGNAL_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_93fake // hashcode: 0x848410A3 (dec: -2071719773)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xD9D815CF (dec: -640150065), parent name: 'SIGNAL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xEF278F3A (dec: -282620102), parent name: 'SIGNAL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_94fake // hashcode: 0x1DE79739 (dec: 501716793)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xFC27FD57 (dec: -64488105), parent name: 'SIGNAL_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xF5E09469 (dec: -169831319), parent name: 'SIGNAL_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_95fake // hashcode: 0x6BE7D0F3 (dec: 1810354419)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0xC79789C9 (dec: -946370103), parent name: 'SIGNAL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x53ECB1D7 (dec: 1408020951), parent name: 'SIGNAL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x9CEB7B4C (dec: -1662289076), parent name: 'SIGNAL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x516ECC77 (dec: 1366215799), parent name: 'SIGNAL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_96fake // hashcode: 0x09E575AC (dec: 166032812)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xAFDE28E0 (dec: -1344395040), parent name: 'SIGNAL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xC348025E (dec: -1018690978), parent name: 'SIGNAL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x3D7F2B27 (dec: 1031744295), parent name: 'SIGNAL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x0927E16C (dec: 153608556), parent name: 'SIGNAL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x31FF701C (dec: 838823964), parent name: 'SIGNAL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SIGNAL_97fake // Hashcode: 0x9FFE0F36 (dec: -1610739914)
{
	struct SIGNAL_74fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	  // size=24, offset=0
	struct SIGNAL_75fake teleport;	 // size=16, offset=0
	struct SIGNAL_76fake cameraValue;  // size=8, offset=0
	struct SIGNAL_77fake miscValue;	// size=8, offset=0
	struct SIGNAL_78fake logicValue;   // size=8, offset=0
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
	struct SIGNAL_79fake cameraShake;  // size=8, offset=0
	long cameraSave;				   // size=0, offset=0
	long cameraRestore;				   // size=0, offset=0
	struct _BGObject *bgObject;		   // size=24, offset=0
	long value[2];					   // size=8, offset=0
	struct SIGNAL_80fake sound;		   // size=12, offset=0
	void *intro;					   // size=0, offset=0
	long deathZ;					   // size=0, offset=0
	struct SIGNAL_81fake dsignal;	  // size=8, offset=0
	void *mirror;					   // size=0, offset=0
	long fogNear;					   // size=0, offset=0
	long fogFar;					   // size=0, offset=0
	struct SIGNAL_82fake gotoFrame;	// size=8, offset=0
	struct SIGNAL_83fake changeModel;  // size=8, offset=0
	void *vmObject;					   // size=0, offset=0
	struct SIGNAL_84fake logic;		   // size=8, offset=0
	void *callSignal;				   // size=0, offset=0
	struct _SVector offset;			   // size=8, offset=0
	struct Signal *gotoLabel;		   // size=0, offset=0
	struct Signal *gosubLabel;		   // size=0, offset=0
	struct SIGNAL_85fake control;	  // size=8, offset=0
	struct SIGNAL_86fake zSignal;	  // size=12, offset=0
	struct SIGNAL_87fake StreamLevel;  // size=24, offset=0
	struct SIGNAL_88fake shards;	   // size=12, offset=0
	struct SIGNAL_89fake cameraSpline; // size=8, offset=0
	struct SIGNAL_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;				   // size=0, offset=0
	struct SIGNAL_91fake introFX;	  // size=8, offset=0
	struct SIGNAL_92fake introActive;  // size=8, offset=0
	struct SIGNAL_93fake levelChange;  // size=18, offset=0
	long blendStart;				   // size=0, offset=0
	struct SIGNAL_94fake setTimes;	 // size=8, offset=0
	struct SIGNAL_95fake color;		   // size=4, offset=0
	struct SIGNAL_96fake print;		   // size=12, offset=0
	long slideAngle;				   // size=0, offset=0
};

union SIGNAL_98fake // Hashcode: 0x03BDA18D (dec: 62759309)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union SIGNAL_103fake // Hashcode: 0x5A0D8B53 (dec: 1510837075)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct SIGNAL_105fake // hashcode: 0xBC8D9C97 (dec: -1131570025)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x9EFD3191 (dec: -1627573871), parent name: 'SIGNAL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xBA510D94 (dec: -1169093228), parent name: 'SIGNAL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0xB1106F7A (dec: -1324322950), parent name: 'SIGNAL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xFF32D6E6 (dec: -13445402), parent name: 'SIGNAL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x06BEB4A8 (dec: 113161384), parent name: 'SIGNAL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xF6D28B2D (dec: -153973971), parent name: 'SIGNAL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x186BF781 (dec: 409728897), parent name: 'SIGNAL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_106fake // hashcode: 0x3D24B54D (dec: 1025815885)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x513E4424 (dec: 1363035172), parent name: 'SIGNAL_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x9F00583E (dec: -1627367362), parent name: 'SIGNAL_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x89CF6FFE (dec: -1982894082), parent name: 'SIGNAL_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_107fake // hashcode: 0x1A5D15A6 (dec: 442308006)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xC7078B5B (dec: -955806885), parent name: 'SIGNAL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x2A9C653B (dec: 714892603), parent name: 'SIGNAL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x0FA98FF8 (dec: 262770680), parent name: 'SIGNAL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xDF1E4AEB (dec: -551662869), parent name: 'SIGNAL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x4902C14A (dec: 1224917322), parent name: 'SIGNAL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_108fake // hashcode: 0x4C387ED8 (dec: 1278770904)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x016E4B04 (dec: 24005380), parent name: 'SIGNAL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x018B54F8 (dec: 25908472), parent name: 'SIGNAL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0xC7C18D19 (dec: -943616743), parent name: 'SIGNAL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xA3188253 (dec: -1558674861), parent name: 'SIGNAL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xFDB37A9E (dec: -38569314), parent name: 'SIGNAL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_109fake // hashcode: 0xD12486F0 (dec: -786135312)
{
	struct SIGNAL_105fake Cinematic; // size=28, offset=0 //  hashcode: 0xF2875E29 (dec: -226009559), parent name: 'SIGNAL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SIGNAL_106fake Idle;		 // size=20, offset=28 //  hashcode: 0xC5A82207 (dec: -978836985), parent name: 'SIGNAL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SIGNAL_107fake Behind;	// size=28, offset=48 //  hashcode: 0x19C01025 (dec: 432017445), parent name: 'SIGNAL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SIGNAL_108fake Follow;	// size=20, offset=76 //  hashcode: 0x7B72E31F (dec: 2071126815), parent name: 'SIGNAL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SIGNAL_206fake // Hashcode: 0x2E97F42B (dec: 781710379)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct SIGNAL_227fake // hashcode: 0x5BD2E7B1 (dec: 1540548529)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x222A6169 (dec: 573202793), parent name: 'SIGNAL_227fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x60482514 (dec: 1615340820), parent name: 'SIGNAL_227fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SIGNAL_228fake // hashcode: 0x259DEBBC (dec: 631106492)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x94620068 (dec: -1805516696), parent name: 'SIGNAL_228fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0xAB531788 (dec: -1420617848), parent name: 'SIGNAL_228fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x68BB5AB0 (dec: 1757108912), parent name: 'SIGNAL_228fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x50734BC3 (dec: 1349733315), parent name: 'SIGNAL_228fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x946E34A9 (dec: -1804716887), parent name: 'SIGNAL_228fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0xC7DB82C2 (dec: -941915454), parent name: 'SIGNAL_228fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SIGNAL_229fake // Hashcode: 0x90049A0D (dec: -1878746611)
{
	struct SIGNAL_227fake flame; // size=8, offset=0
	struct SIGNAL_228fake phys;  // size=12, offset=0
};

struct _FXTracker // hashcode: 0xCC65A064 (dec: -865755036)
{
	struct _FX_MATRIX matrixPool[32];   // size=1408, offset=0 //  hashcode: 0x4A17E806 (dec: 1243080710), parent name: '_FXTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType usedMatrixList;		// size=8, offset=1408 //  hashcode: 0xD3E609D8 (dec: -739898920), parent name: '_FXTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType freeMatrixList;		// size=8, offset=1416 //  hashcode: 0x64490764 (dec: 1682507620), parent name: '_FXTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _FX_PRIM primPool[256];		// size=26624, offset=1424 //  hashcode: 0x0DD70DF8 (dec: 232197624), parent name: '_FXTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType usedPrimList;		// size=8, offset=28048 //  hashcode: 0x6244FD37 (dec: 1648688439), parent name: '_FXTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType usedPrimListSprite; // size=8, offset=28056 //  hashcode: 0x1339DA5E (dec: 322558558), parent name: '_FXTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType freePrimList;		// size=8, offset=28064 //  hashcode: 0x071A50C7 (dec: 119165127), parent name: '_FXTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SignalInfo // hashcode: 0x5899EF0F (dec: 1486483215)
{
	long (*signalHandleFunc)();   // size=0, offset=0 //  hashcode: 0x3FE7BEF6 (dec: 1072152310), parent name: 'SignalInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short length;				  // size=0, offset=4 //  hashcode: 0xFCEF96B2 (dec: -51407182), parent name: 'SignalInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short onlyPlayer;			  // size=0, offset=6 //  hashcode: 0xA3507863 (dec: -1555007389), parent name: 'SignalInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*signalRelocateFunc)(); // size=0, offset=8 //  hashcode: 0x3C27AA97 (dec: 1009232535), parent name: 'SignalInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct _FXTracker FXTracker;

typedef struct SignalInfo SignalInfo;

typedef void BSPLeafFunc();

typedef void SignalGlobalValueFunc();

typedef long HandleSignalFunc();

typedef long SignalHandleFunc();

typedef void RelocateSignalFunc();

extern long SIGNAL_HandleLightGroup(struct _Instance *instance, struct Signal *signal); // 0x8001D840

extern long SIGNAL_HandleCameraAdjust(struct _Instance *instance, struct Signal *signal); // 0x8001D85C

extern long SIGNAL_HandleCamera(struct _Instance *instance, struct Signal *signal); // 0x8001D884

extern void SIGNAL_RelocateCamera(struct Signal *signal, long offset); // 0x8001D8AC

extern long SIGNAL_HandleCameraMode(struct _Instance *instance, struct Signal *signal); // 0x8001D8C8

extern long SIGNAL_HandleCameraLock(struct _Instance *instance, struct Signal *signal); // 0x8001D8F0

extern long SIGNAL_HandleCameraUnlock(struct _Instance *instance, struct Signal *signal); // 0x8001D918

extern long SIGNAL_HandleCameraSmooth(struct _Instance *instance, struct Signal *signal); // 0x8001D940

extern long SIGNAL_HandleCameraTimer(struct _Instance *instance, struct Signal *signal); // 0x8001D968

extern long SIGNAL_HandleCameraSave(struct _Instance *instance, struct Signal *signal); // 0x8001D990

extern long SIGNAL_HandleCameraRestore(struct _Instance *instance, struct Signal *signal); // 0x8001D9B8

extern long SIGNAL_HandleCameraValue(struct _Instance *instance, struct Signal *signal); // 0x8001D9E0

extern long SIGNAL_HandleStreamLevel(struct _Instance *instance, struct Signal *signal); // 0x8001DA10

extern long SIGNAL_HandleFogNear(struct _Instance *instance, struct Signal *signal); // 0x8001DC6C

extern long SIGNAL_HandleFogFar(struct _Instance *instance, struct Signal *signal); // 0x8001DCC0

extern long SIGNAL_HandleCameraShake(struct _Instance *instance, struct Signal *signal); // 0x8001DD1C

extern long SIGNAL_HandleCallSignal(struct _Instance *instance, struct Signal *signal); // 0x8001DD4C

extern long SIGNAL_HandleStopPlayerControl(struct _Instance *instance, struct Signal *signal); // 0x8001DD74

extern long SIGNAL_HandleStartPlayerControl(struct _Instance *instance, struct Signal *signal); // 0x8001DD8C

extern void SIGNAL_RelocateCameraSpline(struct Signal *signal, long offset); // 0x8001DDAC

extern long SIGNAL_HandleCameraSpline(struct _Instance *instance, struct Signal *signal); // 0x8001DDC8

extern long SIGNAL_HandleScreenWipe(struct _Instance *instance, struct Signal *signal); // 0x8001DE48

extern long SIGNAL_HandleBlendStart(struct _Instance *instance, struct Signal *signal); // 0x8001DE80

extern long SIGNAL_HandleScreenWipeColor(struct _Instance *instance, struct Signal *signal); // 0x8001DE88

extern long SIGNAL_HandleSetSlideAngle(struct _Instance *instance, struct Signal *signal); // 0x8001DEB4

extern long SIGNAL_HandleResetSlideAngle(struct _Instance *instance, struct Signal *signal); // 0x8001DEE4

extern long SIGNAL_HandleSetCameraTilt(struct _Instance *instance, struct Signal *signal); // 0x8001DF10

extern long SIGNAL_HandleSetCameraDistance(struct _Instance *instance, struct Signal *signal); // 0x8001DF9C

extern long SIGNAL_HandleEnd(struct _Instance *instance, struct Signal *signal); // 0x8001DFCC

extern void COLLIDE_HandleSignal(struct _Instance *instance, struct Signal *signal, long numSignals, int dontForceDoSignal); // 0x8001DFD4

extern long SIGNAL_IsThisStreamAWarpGate(struct Signal *signal); // 0x8001E0D8

extern long SIGNAL_IsStreamSignal(struct Signal *signal, long *isWarpGate); // 0x8001E138

extern void SIGNAL_HandleSignal(struct _Instance *instance, struct Signal *signal, int dontForceDoSignal); // 0x8001E210

extern struct _MultiSignal *SIGNAL_RelocateSignal(struct _MultiSignal *multiSignal, long offset); // 0x8001E234

extern struct _MultiSignal *SIGNAL_FindSignal(struct Level *level, long id); // 0x8001E310

extern void SIGNAL_OutOfWater(struct _Instance *instance); // 0x8001E3C0

extern void SIGNAL_InWater(struct _Instance *instance); // 0x8001E410

#endif
