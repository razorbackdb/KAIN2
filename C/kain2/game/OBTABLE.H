#ifndef OBTABLE_H
#define OBTABLE_H

extern struct ObjectAccess objectAccess[28]; // offset 0x800C877C

struct OBTABLE_73fake // hashcode: 0xAE023F83 (dec: -1375584381)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xF0F74E05 (dec: -252228091), parent name: 'OBTABLE_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x79C2E255 (dec: 2042815061), parent name: 'OBTABLE_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_74fake // hashcode: 0xDD0A6FEE (dec: -586518546)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x94DBF2E5 (dec: -1797524763), parent name: 'OBTABLE_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x263DC64A (dec: 641582666), parent name: 'OBTABLE_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_75fake // hashcode: 0x0A51550E (dec: 173102350)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xD8BF8912 (dec: -658536174), parent name: 'OBTABLE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x595945D7 (dec: 1499022807), parent name: 'OBTABLE_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union OBTABLE_76fake // Hashcode: 0x95622E13 (dec: -1788727789)
{
	struct OBTABLE_73fake callback; // size=8, offset=0
	struct OBTABLE_74fake vector;   // size=12, offset=0
	struct OBTABLE_75fake quat;		// size=16, offset=0
};

union OBTABLE_77fake // Hashcode: 0x8EF4F21E (dec: -1896549858)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union OBTABLE_78fake // Hashcode: 0x4002183B (dec: 1073879099)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct OBTABLE_79fake // hashcode: 0xC37D6DC6 (dec: -1015190074)
{
	union OBTABLE_78fake size; // size=4, offset=0 //  hashcode: 0xB4524192 (dec: -1269677678), parent name: 'OBTABLE_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_80fake // hashcode: 0x920E2344 (dec: -1844567228)
{
	short x;				// size=0, offset=0 //  hashcode: 0x45348271 (dec: 1161069169), parent name: 'OBTABLE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x7E8721D3 (dec: 2122785235), parent name: 'OBTABLE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x24A489D9 (dec: 614762969), parent name: 'OBTABLE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xC938E8F9 (dec: -919017223), parent name: 'OBTABLE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x55AEEC8A (dec: 1437527178), parent name: 'OBTABLE_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_81fake // hashcode: 0x114BC284 (dec: 290177668)
{
	long index; // size=0, offset=0 //  hashcode: 0x6FAB2722 (dec: 1873487650), parent name: 'OBTABLE_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x7E907B3F (dec: 2123397951), parent name: 'OBTABLE_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_82fake // hashcode: 0x8A786B1A (dec: -1971819750)
{
	long index; // size=0, offset=0 //  hashcode: 0x3524802F (dec: 891584559), parent name: 'OBTABLE_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x0DB7DBAC (dec: 230153132), parent name: 'OBTABLE_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_83fake // hashcode: 0xB5474EF6 (dec: -1253617930)
{
	long index; // size=0, offset=0 //  hashcode: 0xC4FA472B (dec: -990230741), parent name: 'OBTABLE_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x49B9FA5F (dec: 1236925023), parent name: 'OBTABLE_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_84fake // hashcode: 0xC8D3367D (dec: -925682051)
{
	long time;  // size=0, offset=0 //  hashcode: 0x72FFAC15 (dec: 1929358357), parent name: 'OBTABLE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x45010971 (dec: 1157695857), parent name: 'OBTABLE_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_85fake // hashcode: 0xA0FD33AC (dec: -1594018900)
{
	long action;   // size=0, offset=0 //  hashcode: 0xBFF19495 (dec: -1074686827), parent name: 'OBTABLE_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xBD3F33D3 (dec: -1119931437), parent name: 'OBTABLE_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_86fake // hashcode: 0x88A752D8 (dec: -2002300200)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x3C32EB27 (dec: 1009969959), parent name: 'OBTABLE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x9BFBD14E (dec: -1677995698), parent name: 'OBTABLE_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_87fake // hashcode: 0x9A7A7F43 (dec: -1703248061)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x175513BA (dec: 391451578), parent name: 'OBTABLE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0xC6DDE5CD (dec: -958536243), parent name: 'OBTABLE_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_88fake // hashcode: 0xE40FBF58 (dec: -468730024)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x717AB885 (dec: 1903868037), parent name: 'OBTABLE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xD787235B (dec: -679009445), parent name: 'OBTABLE_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_89fake // hashcode: 0x4FE5F74E (dec: 1340471118)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x48663631 (dec: 1214658097), parent name: 'OBTABLE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xADF5A104 (dec: -1376411388), parent name: 'OBTABLE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x6C4246DF (dec: 1816282847), parent name: 'OBTABLE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x14C79E81 (dec: 348626561), parent name: 'OBTABLE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x86410F84 (dec: -2042556540), parent name: 'OBTABLE_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_90fake // hashcode: 0x2BA8DFBD (dec: 732487613)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xCF995D72 (dec: -812032654), parent name: 'OBTABLE_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x363E7697 (dec: 910063255), parent name: 'OBTABLE_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_91fake // hashcode: 0x4B951E4D (dec: 1268063821)
{
	short index;					// size=0, offset=0 //  hashcode: 0x21AC125C (dec: 564925020), parent name: 'OBTABLE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x016741AD (dec: 23544237), parent name: 'OBTABLE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xCAE91173 (dec: -890695309), parent name: 'OBTABLE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xE8386465 (dec: -398957467), parent name: 'OBTABLE_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_92fake // hashcode: 0x03DC405D (dec: 64766045)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xD2560778 (dec: -766113928), parent name: 'OBTABLE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x329901F7 (dec: 848888311), parent name: 'OBTABLE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x3B3FF5F7 (dec: 994047479), parent name: 'OBTABLE_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_93fake // hashcode: 0xE1C20358 (dec: -507378856)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xAE6BC122 (dec: -1368669918), parent name: 'OBTABLE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x7A0A4550 (dec: 2047493456), parent name: 'OBTABLE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xBD2502CB (dec: -1121647925), parent name: 'OBTABLE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x2F819085 (dec: 797020293), parent name: 'OBTABLE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x158F3138 (dec: 361705784), parent name: 'OBTABLE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xF5A8E5C3 (dec: -173480509), parent name: 'OBTABLE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xD90B54CD (dec: -653568819), parent name: 'OBTABLE_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_94fake // hashcode: 0xC44AA159 (dec: -1001741991)
{
	long index;  // size=0, offset=0 //  hashcode: 0x28BBE80F (dec: 683403279), parent name: 'OBTABLE_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x7778A46C (dec: 2004395116), parent name: 'OBTABLE_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_95fake // hashcode: 0xCC9A7526 (dec: -862292698)
{
	short type; // size=0, offset=0 //  hashcode: 0x13E0CFFE (dec: 333500414), parent name: 'OBTABLE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x2C2659C6 (dec: 740710854), parent name: 'OBTABLE_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_96fake // hashcode: 0x41EC6364 (dec: 1106010980)
{
	long time;   // size=0, offset=0 //  hashcode: 0x118B70BD (dec: 294351037), parent name: 'OBTABLE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x9167C843 (dec: -1855469501), parent name: 'OBTABLE_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_97fake // hashcode: 0xADFB1844 (dec: -1376053180)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x856CE7B8 (dec: -2056460360), parent name: 'OBTABLE_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x433162DC (dec: 1127310044), parent name: 'OBTABLE_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_98fake // hashcode: 0xFE89934E (dec: -24538290)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x6BC2091C (dec: 1807878428), parent name: 'OBTABLE_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xFEF07EEE (dec: -17793298), parent name: 'OBTABLE_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_99fake // hashcode: 0x0632B495 (dec: 103986325)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x46A6B2F1 (dec: 1185329905), parent name: 'OBTABLE_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x690A6705 (dec: 1762289413), parent name: 'OBTABLE_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_100fake // hashcode: 0xD5775A24 (dec: -713598428)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0xE56C2B5F (dec: -445895841), parent name: 'OBTABLE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x7D820506 (dec: 2105672966), parent name: 'OBTABLE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x79086E78 (dec: 2030595704), parent name: 'OBTABLE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x86A3BCB8 (dec: -2036089672), parent name: 'OBTABLE_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_101fake // hashcode: 0x8C71E430 (dec: -1938693072)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x0C3A823D (dec: 205161021), parent name: 'OBTABLE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x21F7E692 (dec: 569894546), parent name: 'OBTABLE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x64DE70CE (dec: 1692299470), parent name: 'OBTABLE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xF42014F4 (dec: -199224076), parent name: 'OBTABLE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xD8DE3D50 (dec: -656523952), parent name: 'OBTABLE_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union OBTABLE_102fake // Hashcode: 0x4E39B4D3 (dec: 1312404691)
{
	struct OBTABLE_79fake misc[3];		// size=12, offset=0
	struct _CameraKey *cameraKey;		// size=24, offset=0
	struct OBTABLE_80fake teleport;		// size=16, offset=0
	struct OBTABLE_81fake cameraValue;  // size=8, offset=0
	struct OBTABLE_82fake miscValue;	// size=8, offset=0
	struct OBTABLE_83fake logicValue;   // size=8, offset=0
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
	struct OBTABLE_84fake cameraShake;  // size=8, offset=0
	long cameraSave;					// size=0, offset=0
	long cameraRestore;					// size=0, offset=0
	struct _BGObject *bgObject;			// size=24, offset=0
	long value[2];						// size=8, offset=0
	struct OBTABLE_85fake sound;		// size=12, offset=0
	void *intro;						// size=0, offset=0
	long deathZ;						// size=0, offset=0
	struct OBTABLE_86fake dsignal;		// size=8, offset=0
	void *mirror;						// size=0, offset=0
	long fogNear;						// size=0, offset=0
	long fogFar;						// size=0, offset=0
	struct OBTABLE_87fake gotoFrame;	// size=8, offset=0
	struct OBTABLE_88fake changeModel;  // size=8, offset=0
	void *vmObject;						// size=0, offset=0
	struct OBTABLE_89fake logic;		// size=8, offset=0
	void *callSignal;					// size=0, offset=0
	struct _SVector offset;				// size=8, offset=0
	struct Signal *gotoLabel;			// size=0, offset=0
	struct Signal *gosubLabel;			// size=0, offset=0
	struct OBTABLE_90fake control;		// size=8, offset=0
	struct OBTABLE_91fake zSignal;		// size=12, offset=0
	struct OBTABLE_92fake StreamLevel;  // size=24, offset=0
	struct OBTABLE_93fake shards;		// size=12, offset=0
	struct OBTABLE_94fake cameraSpline; // size=8, offset=0
	struct OBTABLE_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;					// size=0, offset=0
	struct OBTABLE_96fake introFX;		// size=8, offset=0
	struct OBTABLE_97fake introActive;  // size=8, offset=0
	struct OBTABLE_98fake levelChange;  // size=18, offset=0
	long blendStart;					// size=0, offset=0
	struct OBTABLE_99fake setTimes;		// size=8, offset=0
	struct OBTABLE_100fake color;		// size=4, offset=0
	struct OBTABLE_101fake print;		// size=12, offset=0
	long slideAngle;					// size=0, offset=0
};

union OBTABLE_103fake // Hashcode: 0xA7CC62CD (dec: -1479777587)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

struct _ObjectOwnerInfo // hashcode: 0x04BCED5C (dec: 79490396)
{
	long magicnum;		// size=0, offset=0 //  hashcode: 0x726D841A (dec: 1919779866), parent name: '_ObjectOwnerInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short animID;		// size=0, offset=4 //  hashcode: 0x55AD8C8A (dec: 1437437066), parent name: '_ObjectOwnerInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	char objectName[0]; // size=0, offset=6 //  hashcode: 0x6EEE7219 (dec: 1861120537), parent name: '_ObjectOwnerInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union OBTABLE_108fake // Hashcode: 0x40387842 (dec: 1077442626)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct OBTABLE_110fake // hashcode: 0x0EC200A5 (dec: 247595173)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x2F1FACB4 (dec: 790604980), parent name: 'OBTABLE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xB2571EC7 (dec: -1302913337), parent name: 'OBTABLE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x15F9E04F (dec: 368697423), parent name: 'OBTABLE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xE0CC9006 (dec: -523464698), parent name: 'OBTABLE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0xEBD38141 (dec: -338460351), parent name: 'OBTABLE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x9B5B52E0 (dec: -1688513824), parent name: 'OBTABLE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x32307948 (dec: 842037576), parent name: 'OBTABLE_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_111fake // hashcode: 0x082CCE7A (dec: 137154170)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x837EB30B (dec: -2088848629), parent name: 'OBTABLE_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x10D324D0 (dec: 282272976), parent name: 'OBTABLE_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xF579D05B (dec: -176566181), parent name: 'OBTABLE_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_112fake // hashcode: 0x46CA70E1 (dec: 1187672289)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xA958418F (dec: -1453833841), parent name: 'OBTABLE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xA69C6014 (dec: -1499701228), parent name: 'OBTABLE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x6E9AFEBB (dec: 1855651515), parent name: 'OBTABLE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xE340B3CC (dec: -482298932), parent name: 'OBTABLE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x7ED0B3A2 (dec: 2127606690), parent name: 'OBTABLE_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_113fake // hashcode: 0xA3D3DBEE (dec: -1546396690)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x0C41F229 (dec: 205648425), parent name: 'OBTABLE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x8A4957E1 (dec: -1974904863), parent name: 'OBTABLE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x0AD021D4 (dec: 181412308), parent name: 'OBTABLE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x38D2EA07 (dec: 953346567), parent name: 'OBTABLE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x4D7D543B (dec: 1300059195), parent name: 'OBTABLE_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_114fake // hashcode: 0xA297FC58 (dec: -1567097768)
{
	struct OBTABLE_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x84340750 (dec: -2076965040), parent name: 'OBTABLE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct OBTABLE_111fake Idle;	  // size=20, offset=28 //  hashcode: 0xFDE56053 (dec: -35299245), parent name: 'OBTABLE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct OBTABLE_112fake Behind;	// size=28, offset=48 //  hashcode: 0x813B5303 (dec: -2126818557), parent name: 'OBTABLE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct OBTABLE_113fake Follow;	// size=20, offset=76 //  hashcode: 0x4A5F4776 (dec: 1247758198), parent name: 'OBTABLE_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ObjectAccess // hashcode: 0x1268C513 (dec: 308856083)
{
	char *objectName; // size=0, offset=0 //  hashcode: 0x114A340C (dec: 290075660), parent name: 'ObjectAccess', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *object;	 // size=0, offset=4 //  hashcode: 0x43185517 (dec: 1125668119), parent name: 'ObjectAccess', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union OBTABLE_196fake // Hashcode: 0x921E9F5C (dec: -1843486884)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct OBTABLE_223fake // hashcode: 0xECD53A99 (dec: -321570151)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0xE3ACEF20 (dec: -475205856), parent name: 'OBTABLE_223fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x14223FC6 (dec: 337788870), parent name: 'OBTABLE_223fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct OBTABLE_224fake // hashcode: 0xB2512020 (dec: -1303306208)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x719A2356 (dec: 1905926998), parent name: 'OBTABLE_224fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0xDE39CD72 (dec: -566637198), parent name: 'OBTABLE_224fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x3B617222 (dec: 996241954), parent name: 'OBTABLE_224fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x7043D5F7 (dec: 1883493879), parent name: 'OBTABLE_224fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0xA136337F (dec: -1590283393), parent name: 'OBTABLE_224fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0xFE25CE65 (dec: -31076763), parent name: 'OBTABLE_224fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union OBTABLE_225fake // Hashcode: 0x2A78F5C9 (dec: 712570313)
{
	struct OBTABLE_223fake flame; // size=8, offset=0
	struct OBTABLE_224fake phys;  // size=12, offset=0
};

typedef struct _ObjectOwnerInfo ObjectOwnerInfo;

typedef struct ObjectAccess ObjectAccess;

extern void OBTABLE_InstanceInit(struct _Instance *instance); // 0x8003D9AC

extern void OBTABLE_GetInstanceCollideFunc(struct _Instance *instance); // 0x8003DA90

extern void OBTABLE_GetInstanceAdditionalCollideFunc(struct _Instance *instance); // 0x8003DAD8

extern void OBTABLE_GetInstanceProcessFunc(struct _Instance *instance); // 0x8003DB18

extern void OBTABLE_GetInstanceQueryFunc(struct _Instance *instance); // 0x8003DB60

extern void OBTABLE_GetInstanceMessageFunc(struct _Instance *instance); // 0x8003DBA8

extern void OBTABLE_InitObjectWithID(struct Object *object); // 0x8003DBF0

extern void OBTABLE_ClearObjectReferences(); // 0x8003DDC8

extern void OBTABLE_RemoveObjectEntry(struct Object *object); // 0x8003DDFC

extern struct Object *OBTABLE_FindObject(char *objectName); // 0x8003DE44

extern void OBTABLE_ChangeObjectAccessPointers(struct Object *oldObject, struct Object *newObject); // 0x8003DEF0

extern void OBTABLE_RelocateObjectTune(struct Object *object, long offset); // 0x8003DF38

extern void OBTABLE_RelocateInstanceObject(struct _Instance *instance, long offset); // 0x8003DF9C

extern void OBTABLE_InitAnimPointers(struct _ObjectTracker *objectTracker); // 0x8003DFF8

#endif
