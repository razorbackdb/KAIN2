#ifndef SCRIPT_H
#define SCRIPT_H

extern char(*selectMenuText[5]); // offset 0x800C8768

struct SCRIPT_73fake // hashcode: 0x5B4FE26C (dec: 1531961964)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xE25A64BD (dec: -497392451), parent name: 'SCRIPT_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x8B6072C4 (dec: -1956613436), parent name: 'SCRIPT_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_74fake // hashcode: 0x973F0507 (dec: -1757477625)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x7776EB4E (dec: 2004282190), parent name: 'SCRIPT_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x844B3764 (dec: -2075445404), parent name: 'SCRIPT_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_75fake // hashcode: 0x9327337F (dec: -1826147457)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x8E8DC025 (dec: -1903312859), parent name: 'SCRIPT_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x103399AF (dec: 271817135), parent name: 'SCRIPT_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SCRIPT_76fake // Hashcode: 0x07CCD3E7 (dec: 130864103)
{
	struct SCRIPT_73fake callback; // size=8, offset=0
	struct SCRIPT_74fake vector;   // size=12, offset=0
	struct SCRIPT_75fake quat;	 // size=16, offset=0
};

union SCRIPT_77fake // Hashcode: 0xA89A9D98 (dec: -1466262120)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union SCRIPT_78fake // Hashcode: 0x3E9AF40B (dec: 1050342411)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct SCRIPT_79fake // hashcode: 0xB9F299AD (dec: -1175283283)
{
	union SCRIPT_78fake size; // size=4, offset=0 //  hashcode: 0xF89DEB7C (dec: -123868292), parent name: 'SCRIPT_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_80fake // hashcode: 0xB87C59EA (dec: -1199810070)
{
	short x;				// size=0, offset=0 //  hashcode: 0x12C50AE0 (dec: 314903264), parent name: 'SCRIPT_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x9F23DB9A (dec: -1625039974), parent name: 'SCRIPT_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x77B93677 (dec: 2008626807), parent name: 'SCRIPT_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x0072952B (dec: 7509291), parent name: 'SCRIPT_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x3B3B9713 (dec: 993761043), parent name: 'SCRIPT_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_81fake // hashcode: 0xCFF12621 (dec: -806279647)
{
	long index; // size=0, offset=0 //  hashcode: 0xD0D0495B (dec: -791656101), parent name: 'SCRIPT_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xC5AED832 (dec: -978397134), parent name: 'SCRIPT_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_82fake // hashcode: 0x3DD05357 (dec: 1037062999)
{
	long index; // size=0, offset=0 //  hashcode: 0xD4A1DB36 (dec: -727590090), parent name: 'SCRIPT_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x625850F1 (dec: 1649955057), parent name: 'SCRIPT_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_83fake // hashcode: 0x64CB1A24 (dec: 1691032100)
{
	long index; // size=0, offset=0 //  hashcode: 0xC8B7DEA8 (dec: -927474008), parent name: 'SCRIPT_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xFCC1C7CC (dec: -54409268), parent name: 'SCRIPT_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_84fake // hashcode: 0xE88BEE17 (dec: -393482729)
{
	long time;  // size=0, offset=0 //  hashcode: 0x788F4154 (dec: 2022654292), parent name: 'SCRIPT_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xDD69D6E6 (dec: -580266266), parent name: 'SCRIPT_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_85fake // hashcode: 0x06B36A83 (dec: 112421507)
{
	long action;   // size=0, offset=0 //  hashcode: 0xD28F3C73 (dec: -762364813), parent name: 'SCRIPT_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x906B2449 (dec: -1872026551), parent name: 'SCRIPT_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_86fake // hashcode: 0x5AB0C3B7 (dec: 1521533879)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x380F1E55 (dec: 940514901), parent name: 'SCRIPT_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xE1299122 (dec: -517369566), parent name: 'SCRIPT_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_87fake // hashcode: 0x6292ED12 (dec: 1653796114)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x38E895EB (dec: 954766827), parent name: 'SCRIPT_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0xCDE3F910 (dec: -840697584), parent name: 'SCRIPT_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_88fake // hashcode: 0x8383A67A (dec: -2088524166)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xA952A74E (dec: -1454201010), parent name: 'SCRIPT_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xFDD77C36 (dec: -36209610), parent name: 'SCRIPT_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_89fake // hashcode: 0x380ED797 (dec: 940496791)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x7F21F94A (dec: 2132932938), parent name: 'SCRIPT_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xF40384E2 (dec: -201095966), parent name: 'SCRIPT_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xD9A56C51 (dec: -643470255), parent name: 'SCRIPT_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x3F11EE2C (dec: 1058139692), parent name: 'SCRIPT_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xD54DE45C (dec: -716315556), parent name: 'SCRIPT_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_90fake // hashcode: 0xE606EC2C (dec: -435753940)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x6068CAB5 (dec: 1617480373), parent name: 'SCRIPT_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x2049E096 (dec: 541712534), parent name: 'SCRIPT_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_91fake // hashcode: 0x8A5E442F (dec: -1973533649)
{
	short index;					// size=0, offset=0 //  hashcode: 0x6245B916 (dec: 1648736534), parent name: 'SCRIPT_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xCB3BA284 (dec: -885284220), parent name: 'SCRIPT_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xE760558B (dec: -413117045), parent name: 'SCRIPT_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x1016D6E3 (dec: 269932259), parent name: 'SCRIPT_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_92fake // hashcode: 0x43D06473 (dec: 1137730675)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x8DC157E7 (dec: -1916708889), parent name: 'SCRIPT_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x7F080E10 (dec: 2131234320), parent name: 'SCRIPT_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xC9B67DE5 (dec: -910787099), parent name: 'SCRIPT_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_93fake // hashcode: 0xCCCC84AD (dec: -859011923)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xC12EA930 (dec: -1053906640), parent name: 'SCRIPT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x294244BB (dec: 692208827), parent name: 'SCRIPT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xFC88BA94 (dec: -58148204), parent name: 'SCRIPT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xE1C09D72 (dec: -507470478), parent name: 'SCRIPT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xFA499B5F (dec: -95839393), parent name: 'SCRIPT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x7E7463D0 (dec: 2121556944), parent name: 'SCRIPT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x141C340C (dec: 337392652), parent name: 'SCRIPT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_94fake // hashcode: 0xFDD0ACA1 (dec: -36655967)
{
	long index;  // size=0, offset=0 //  hashcode: 0xDE01C47A (dec: -570309510), parent name: 'SCRIPT_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xB79882F3 (dec: -1214741773), parent name: 'SCRIPT_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_95fake // hashcode: 0xFBD61318 (dec: -69856488)
{
	short type; // size=0, offset=0 //  hashcode: 0x285AFA83 (dec: 677051011), parent name: 'SCRIPT_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x15224A30 (dec: 354568752), parent name: 'SCRIPT_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_96fake // hashcode: 0xC9E6B553 (dec: -907627181)
{
	long time;   // size=0, offset=0 //  hashcode: 0x05705DFB (dec: 91250171), parent name: 'SCRIPT_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x97EA76A5 (dec: -1746241883), parent name: 'SCRIPT_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_97fake // hashcode: 0x35BC69AF (dec: 901540271)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x4FF16C6C (dec: 1341221996), parent name: 'SCRIPT_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x079080FB (dec: 126910715), parent name: 'SCRIPT_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_98fake // hashcode: 0xB80047AC (dec: -1207941204)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x0CC2CF4B (dec: 214093643), parent name: 'SCRIPT_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x2333F923 (dec: 590608675), parent name: 'SCRIPT_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_99fake // hashcode: 0x6B827983 (dec: 1803712899)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x2B98F40A (dec: 731444234), parent name: 'SCRIPT_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xDC87F35C (dec: -595070116), parent name: 'SCRIPT_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_100fake // hashcode: 0xA046466A (dec: -1606007190)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x9BA84871 (dec: -1683470223), parent name: 'SCRIPT_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x37A7BF30 (dec: 933740336), parent name: 'SCRIPT_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x014F3C17 (dec: 21969943), parent name: 'SCRIPT_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xCFBD0740 (dec: -809695424), parent name: 'SCRIPT_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_101fake // hashcode: 0x5C28B7AE (dec: 1546172334)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xE22A56DC (dec: -500541732), parent name: 'SCRIPT_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xED315E61 (dec: -315531679), parent name: 'SCRIPT_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x2D54CB84 (dec: 760531844), parent name: 'SCRIPT_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xD9F7BAAB (dec: -638076245), parent name: 'SCRIPT_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xA5812D88 (dec: -1518260856), parent name: 'SCRIPT_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SCRIPT_102fake // Hashcode: 0x7B8BAC98 (dec: 2072751256)
{
	struct SCRIPT_79fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	  // size=24, offset=0
	struct SCRIPT_80fake teleport;	 // size=16, offset=0
	struct SCRIPT_81fake cameraValue;  // size=8, offset=0
	struct SCRIPT_82fake miscValue;	// size=8, offset=0
	struct SCRIPT_83fake logicValue;   // size=8, offset=0
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
	struct SCRIPT_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				   // size=0, offset=0
	long cameraRestore;				   // size=0, offset=0
	struct _BGObject *bgObject;		   // size=24, offset=0
	long value[2];					   // size=8, offset=0
	struct SCRIPT_85fake sound;		   // size=12, offset=0
	void *intro;					   // size=0, offset=0
	long deathZ;					   // size=0, offset=0
	struct SCRIPT_86fake dsignal;	  // size=8, offset=0
	void *mirror;					   // size=0, offset=0
	long fogNear;					   // size=0, offset=0
	long fogFar;					   // size=0, offset=0
	struct SCRIPT_87fake gotoFrame;	// size=8, offset=0
	struct SCRIPT_88fake changeModel;  // size=8, offset=0
	void *vmObject;					   // size=0, offset=0
	struct SCRIPT_89fake logic;		   // size=8, offset=0
	void *callSignal;				   // size=0, offset=0
	struct _SVector offset;			   // size=8, offset=0
	struct Signal *gotoLabel;		   // size=0, offset=0
	struct Signal *gosubLabel;		   // size=0, offset=0
	struct SCRIPT_90fake control;	  // size=8, offset=0
	struct SCRIPT_91fake zSignal;	  // size=12, offset=0
	struct SCRIPT_92fake StreamLevel;  // size=24, offset=0
	struct SCRIPT_93fake shards;	   // size=12, offset=0
	struct SCRIPT_94fake cameraSpline; // size=8, offset=0
	struct SCRIPT_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				   // size=0, offset=0
	struct SCRIPT_96fake introFX;	  // size=8, offset=0
	struct SCRIPT_97fake introActive;  // size=8, offset=0
	struct SCRIPT_98fake levelChange;  // size=18, offset=0
	long blendStart;				   // size=0, offset=0
	struct SCRIPT_99fake setTimes;	 // size=8, offset=0
	struct SCRIPT_100fake color;	   // size=4, offset=0
	struct SCRIPT_101fake print;	   // size=12, offset=0
	long slideAngle;				   // size=0, offset=0
};

union SCRIPT_103fake // Hashcode: 0x98FBD484 (dec: -1728326524)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union SCRIPT_108fake // Hashcode: 0x0CCFCA4B (dec: 214944331)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct SCRIPT_110fake // hashcode: 0xDE6F39F2 (dec: -563136014)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x340875BF (dec: 872969663), parent name: 'SCRIPT_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x08055F41 (dec: 134569793), parent name: 'SCRIPT_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x51B52382 (dec: 1370825602), parent name: 'SCRIPT_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xBEACE0F8 (dec: -1095966472), parent name: 'SCRIPT_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0xDD6AEA5D (dec: -580195747), parent name: 'SCRIPT_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x1C151261 (dec: 471143009), parent name: 'SCRIPT_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x2CB2F7E1 (dec: 749926369), parent name: 'SCRIPT_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_111fake // hashcode: 0x28B6C596 (dec: 683066774)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0xA82A6C0C (dec: -1473614836), parent name: 'SCRIPT_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x79D6B68F (dec: 2044114575), parent name: 'SCRIPT_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x7436FE6F (dec: 1949761135), parent name: 'SCRIPT_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_112fake // hashcode: 0x6E89409A (dec: 1854488730)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xA6F72574 (dec: -1493752460), parent name: 'SCRIPT_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x4F90122E (dec: 1334841902), parent name: 'SCRIPT_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xF5CC5598 (dec: -171158120), parent name: 'SCRIPT_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x716F033E (dec: 1903100734), parent name: 'SCRIPT_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x8C9075A3 (dec: -1936689757), parent name: 'SCRIPT_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_113fake // hashcode: 0x76EDB971 (dec: 1995290993)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xF88FAF9D (dec: -124801123), parent name: 'SCRIPT_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x459C19DF (dec: 1167858143), parent name: 'SCRIPT_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0xD9FC3F17 (dec: -637780201), parent name: 'SCRIPT_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xAC05B2AA (dec: -1408912726), parent name: 'SCRIPT_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xFC75E4AA (dec: -59382614), parent name: 'SCRIPT_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_114fake // hashcode: 0x918B5BD9 (dec: -1853137959)
{
	struct SCRIPT_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x78C64BE2 (dec: 2026261474), parent name: 'SCRIPT_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SCRIPT_111fake Idle;		 // size=20, offset=28 //  hashcode: 0xF7D0D848 (dec: -137308088), parent name: 'SCRIPT_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SCRIPT_112fake Behind;	// size=28, offset=48 //  hashcode: 0xED386B86 (dec: -315069562), parent name: 'SCRIPT_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SCRIPT_113fake Follow;	// size=20, offset=76 //  hashcode: 0x57EEB51B (dec: 1475261723), parent name: 'SCRIPT_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SCRIPT_202fake // Hashcode: 0x28E126E1 (dec: 685844193)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct SCRIPT_223fake // hashcode: 0xB39DC0B9 (dec: -1281507143)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x91E3FA78 (dec: -1847330184), parent name: 'SCRIPT_223fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x0D0CF9E5 (dec: 218954213), parent name: 'SCRIPT_223fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCRIPT_224fake // hashcode: 0x560427D8 (dec: 1443112920)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x644D18B5 (dec: 1682774197), parent name: 'SCRIPT_224fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x9893EE9C (dec: -1735135588), parent name: 'SCRIPT_224fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0xD7512DA5 (dec: -682545755), parent name: 'SCRIPT_224fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x072D5E6A (dec: 120413802), parent name: 'SCRIPT_224fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0xE9D8F648 (dec: -371657144), parent name: 'SCRIPT_224fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x51FE66EE (dec: 1375626990), parent name: 'SCRIPT_224fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union SCRIPT_225fake // Hashcode: 0x156396DA (dec: 358848218)
{
	struct SCRIPT_223fake flame; // size=8, offset=0
	struct SCRIPT_224fake phys;  // size=12, offset=0
};

struct FXSplinter // hashcode: 0x3E763456 (dec: 1047934038)
{
	short flags;	   // size=0, offset=0 //  hashcode: 0x289DFF38 (dec: 681443128), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundFx;	 // size=0, offset=2 //  hashcode: 0xFFE2480E (dec: -1947634), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	short chunkVelXY;  // size=0, offset=4 //  hashcode: 0x341D3DEC (dec: 874331628), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	short chunkVelZ;   // size=0, offset=6 //  hashcode: 0xDB11C0FE (dec: -619593474), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	short chunkVelRng; // size=0, offset=8 //  hashcode: 0xECDB74C7 (dec: -321162041), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	short triVelRng;   // size=0, offset=10 //  hashcode: 0x42AB1582 (dec: 1118508418), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifetime;	// size=0, offset=12 //  hashcode: 0xDF895D27 (dec: -544645849), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	short faceLimit;   // size=0, offset=14 //  hashcode: 0xAC74E668 (dec: -1401624984), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rotRateRng;  // size=0, offset=16 //  hashcode: 0x716C95A6 (dec: 1902941606), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	short gravityZ;	// size=0, offset=18 //  hashcode: 0x14D4563A (dec: 349460026), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct FXSplinter FXSplinter;

extern void SCRIPT_CombineEulerAngles(struct _Rotation *combinedRotation, struct _Rotation *inputRotation1, struct _Rotation *inputRotation2); // 0x8003C6B0

extern void SCRIPT_InstanceSplineInit(struct _Instance *instance); // 0x8003C730

extern short SCRIPTCountFramesInSpline(struct _Instance *instance); // 0x8003C980

extern struct Spline *ScriptGetPosSpline(struct _Instance *instance); // 0x8003CAD0

extern struct RSpline *ScriptGetRotSpline(struct _Instance *instance); // 0x8003CB08

extern int SCRIPT_GetSplineFrameNumber(struct _Instance *instance, struct SplineDef *splineDef); // 0x8003CB40

extern struct MultiSpline *SCRIPT_GetMultiSpline(struct _Instance *instance, unsigned long *isParent, unsigned long *isClass); // 0x8003CBA0

extern struct SplineDef *SCRIPT_GetPosSplineDef(struct _Instance *instance, struct MultiSpline *multi, unsigned long isParent, unsigned long isClass); // 0x8003CC4C

extern struct SplineDef *SCRIPT_GetRotSplineDef(struct _Instance *instance, struct MultiSpline *multi, unsigned long isParent, unsigned long isClass); // 0x8003CC78

extern struct SplineDef *SCRIPT_GetScaleSplineDef(struct _Instance *instance, struct MultiSpline *multi, unsigned long isParent, unsigned long isClass); // 0x8003CCA4

extern void SCRIPT_RelativisticSpline(struct _Instance *instance, struct _SVector *point); // 0x8003CCD0

extern void SCRIPT_InstanceSplineSet(struct _Instance *instance, short frameNum, struct SplineDef *splineDef, struct SplineDef *rsplineDef, struct SplineDef *ssplineDef); // 0x8003CEC0

extern long SCRIPT_SplineProcess(struct _Instance *instance, struct MultiSpline *multi, struct SplineDef *splineDef, struct SplineDef *rsplineDef, struct SplineDef *ssplineDef, int direction, int isClass); // 0x8003D198

extern long SCRIPT_InstanceSplineProcess(struct _Instance *instance, struct SplineDef *splineDef, struct SplineDef *rsplineDef, struct SplineDef *ssplineDef, int direction); // 0x8003D480

extern void SCRIPT_FadeOutProcess(struct _Instance *instance); // 0x8003D588

extern void ScriptKillInstance(struct _Instance *instance, int effect); // 0x8003D5D0

#endif
