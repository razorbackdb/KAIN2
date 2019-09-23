#ifndef PLANSRCH_H
#define PLANSRCH_H

struct PLANSRCH_110fake // hashcode: 0x647E2579 (dec: 1685988729)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x78CC4175 (dec: 2026652021), parent name: 'PLANSRCH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x5C7B6661 (dec: 1551591009), parent name: 'PLANSRCH_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_111fake // hashcode: 0x7A447F3B (dec: 2051309371)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x3BE7ED15 (dec: 1005055253), parent name: 'PLANSRCH_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x4047B06A (dec: 1078440042), parent name: 'PLANSRCH_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_112fake // hashcode: 0x75F5019A (dec: 1978991002)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xAE1D2F0E (dec: -1373819122), parent name: 'PLANSRCH_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x5EB0E347 (dec: 1588650823), parent name: 'PLANSRCH_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLANSRCH_113fake // Hashcode: 0x580A71C1 (dec: 1477079489)
{
	struct PLANSRCH_110fake callback; // size=8, offset=0
	struct PLANSRCH_111fake vector;   // size=12, offset=0
	struct PLANSRCH_112fake quat;	 // size=16, offset=0
};

union PLANSRCH_114fake // Hashcode: 0x3FB13975 (dec: 1068579189)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PLANSRCH_115fake // Hashcode: 0xC669FCEB (dec: -966132501)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct PLANSRCH_116fake // hashcode: 0x898C8C61 (dec: -1987277727)
{
	union PLANSRCH_115fake size; // size=4, offset=0 //  hashcode: 0xA7DA8F64 (dec: -1478848668), parent name: 'PLANSRCH_116fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_117fake // hashcode: 0xD0DF9976 (dec: -790652554)
{
	short x;				// size=0, offset=0 //  hashcode: 0x6D52C9F5 (dec: 1834142197), parent name: 'PLANSRCH_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xD4B9AA0B (dec: -726029813), parent name: 'PLANSRCH_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xE74AA7E9 (dec: -414537751), parent name: 'PLANSRCH_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x8F427229 (dec: -1891470807), parent name: 'PLANSRCH_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xF9630382 (dec: -110951550), parent name: 'PLANSRCH_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_118fake // hashcode: 0x8E3F37AA (dec: -1908459606)
{
	long index; // size=0, offset=0 //  hashcode: 0xE287CC02 (dec: -494416894), parent name: 'PLANSRCH_118fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x0DB1466B (dec: 229721707), parent name: 'PLANSRCH_118fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_119fake // hashcode: 0x95021928 (dec: -1795024600)
{
	long index; // size=0, offset=0 //  hashcode: 0xE6DBC54F (dec: -421804721), parent name: 'PLANSRCH_119fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x2EDDA4CC (dec: 786277580), parent name: 'PLANSRCH_119fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_120fake // hashcode: 0x27A4320C (dec: 665072140)
{
	long index; // size=0, offset=0 //  hashcode: 0x0BF967F3 (dec: 200894451), parent name: 'PLANSRCH_120fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xABF001F3 (dec: -1410334221), parent name: 'PLANSRCH_120fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_121fake // hashcode: 0x92AFF6D9 (dec: -1833961767)
{
	long time;  // size=0, offset=0 //  hashcode: 0x64BC0A5D (dec: 1690045021), parent name: 'PLANSRCH_121fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xD041E189 (dec: -800988791), parent name: 'PLANSRCH_121fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_122fake // hashcode: 0x9DB8E9FB (dec: -1648825861)
{
	long action;   // size=0, offset=0 //  hashcode: 0xC4C7B511 (dec: -993544943), parent name: 'PLANSRCH_122fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x1764BECF (dec: 392478415), parent name: 'PLANSRCH_122fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_123fake // hashcode: 0x4F080CB7 (dec: 1325927607)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xDF44BD97 (dec: -549143145), parent name: 'PLANSRCH_123fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x01F454BE (dec: 32789694), parent name: 'PLANSRCH_123fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_124fake // hashcode: 0x01B34097 (dec: 28524695)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xDDA6EE5A (dec: -576262566), parent name: 'PLANSRCH_124fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x28A0755D (dec: 681604445), parent name: 'PLANSRCH_124fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_125fake // hashcode: 0x1395AD23 (dec: 328576291)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x9ED71E49 (dec: -1630069175), parent name: 'PLANSRCH_125fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x7ECC823B (dec: 2127331899), parent name: 'PLANSRCH_125fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_126fake // hashcode: 0xF4BDE90B (dec: -188880629)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xBFFC0421 (dec: -1074002911), parent name: 'PLANSRCH_126fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xE0ADAE18 (dec: -525488616), parent name: 'PLANSRCH_126fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x296CF883 (dec: 695007363), parent name: 'PLANSRCH_126fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x930BAE59 (dec: -1827951015), parent name: 'PLANSRCH_126fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xCD43A6F8 (dec: -851204360), parent name: 'PLANSRCH_126fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_127fake // hashcode: 0x2CFB521C (dec: 754668060)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xA536A9D6 (dec: -1523144234), parent name: 'PLANSRCH_127fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x460D6837 (dec: 1175283767), parent name: 'PLANSRCH_127fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_128fake // hashcode: 0xD60529EA (dec: -704304662)
{
	short index;					// size=0, offset=0 //  hashcode: 0x4B907F8C (dec: 1267761036), parent name: 'PLANSRCH_128fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x34CBB431 (dec: 885765169), parent name: 'PLANSRCH_128fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x591BE523 (dec: 1495000355), parent name: 'PLANSRCH_128fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xE686C939 (dec: -427374279), parent name: 'PLANSRCH_128fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_129fake // hashcode: 0xFD4547F2 (dec: -45791246)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x235F9D94 (dec: 593468820), parent name: 'PLANSRCH_129fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x864105BB (dec: -2042559045), parent name: 'PLANSRCH_129fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xF319788F (dec: -216434545), parent name: 'PLANSRCH_129fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_130fake // hashcode: 0x11B3BEDA (dec: 296992474)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xF4C45336 (dec: -188460234), parent name: 'PLANSRCH_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x3E6534CC (dec: 1046820044), parent name: 'PLANSRCH_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x8AE512DB (dec: -1964698917), parent name: 'PLANSRCH_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xF215B925 (dec: -233457371), parent name: 'PLANSRCH_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x33A334BC (dec: 866333884), parent name: 'PLANSRCH_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x0BB58BA3 (dec: 196447139), parent name: 'PLANSRCH_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xADAE30F1 (dec: -1381093135), parent name: 'PLANSRCH_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_131fake // hashcode: 0xBAD4AADD (dec: -1160467747)
{
	long index;  // size=0, offset=0 //  hashcode: 0x94AD1C2F (dec: -1800594385), parent name: 'PLANSRCH_131fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x73801328 (dec: 1937773352), parent name: 'PLANSRCH_131fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_132fake // hashcode: 0xE052EEDD (dec: -531435811)
{
	short type; // size=0, offset=0 //  hashcode: 0x7C6219CA (dec: 2086803914), parent name: 'PLANSRCH_132fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x941F0822 (dec: -1809905630), parent name: 'PLANSRCH_132fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_133fake // hashcode: 0x93D25B93 (dec: -1814930541)
{
	long time;   // size=0, offset=0 //  hashcode: 0x91ABC8B5 (dec: -1851012939), parent name: 'PLANSRCH_133fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x41348F93 (dec: 1093963667), parent name: 'PLANSRCH_133fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_134fake // hashcode: 0x07F22C2F (dec: 133311535)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x6C634FB4 (dec: 1818447796), parent name: 'PLANSRCH_134fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x110AD6D8 (dec: 285923032), parent name: 'PLANSRCH_134fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_135fake // hashcode: 0xA7E1A4F4 (dec: -1478384396)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x83B7B53C (dec: -2085112516), parent name: 'PLANSRCH_135fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x92D3DB0A (dec: -1831609590), parent name: 'PLANSRCH_135fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_136fake // hashcode: 0x4019E2C5 (dec: 1075438277)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xAD444E6D (dec: -1388032403), parent name: 'PLANSRCH_136fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x054FFF8D (dec: 89128845), parent name: 'PLANSRCH_136fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_137fake // hashcode: 0x2847E9D1 (dec: 675801553)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x054763F7 (dec: 88564727), parent name: 'PLANSRCH_137fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x633636B2 (dec: 1664497330), parent name: 'PLANSRCH_137fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xB20ED4D8 (dec: -1307650856), parent name: 'PLANSRCH_137fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x62CA5258 (dec: 1657426520), parent name: 'PLANSRCH_137fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_138fake // hashcode: 0x2531509A (dec: 623988890)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x623EC6F1 (dec: 1648281329), parent name: 'PLANSRCH_138fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x46865AF2 (dec: 1183210226), parent name: 'PLANSRCH_138fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xED6EC2FE (dec: -311508226), parent name: 'PLANSRCH_138fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xF28E9D78 (dec: -225534600), parent name: 'PLANSRCH_138fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xFDB581C0 (dec: -38436416), parent name: 'PLANSRCH_138fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLANSRCH_139fake // Hashcode: 0xC64FE8D1 (dec: -967841583)
{
	struct PLANSRCH_116fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;		  // size=24, offset=0
	struct PLANSRCH_117fake teleport;	 // size=16, offset=0
	struct PLANSRCH_118fake cameraValue;  // size=8, offset=0
	struct PLANSRCH_119fake miscValue;	// size=8, offset=0
	struct PLANSRCH_120fake logicValue;   // size=8, offset=0
	long timer;							  // size=0, offset=0
	long times;							  // size=0, offset=0
	long lightGroup;					  // size=0, offset=0
	long farPlane;						  // size=0, offset=0
	long cameraAdjust;					  // size=0, offset=0
	long cameraMode;					  // size=0, offset=0
	long cameraLock;					  // size=0, offset=0
	long cameraUnlock;					  // size=0, offset=0
	long cameraSmooth;					  // size=0, offset=0
	long cameraTimer;					  // size=0, offset=0
	struct PLANSRCH_121fake cameraShake;  // size=8, offset=0
	long cameraSave;					  // size=0, offset=0
	long cameraRestore;					  // size=0, offset=0
	struct _BGObject *bgObject;			  // size=24, offset=0
	long value[2];						  // size=8, offset=0
	struct PLANSRCH_122fake sound;		  // size=12, offset=0
	void *intro;						  // size=0, offset=0
	long deathZ;						  // size=0, offset=0
	struct PLANSRCH_123fake dsignal;	  // size=8, offset=0
	void *mirror;						  // size=0, offset=0
	long fogNear;						  // size=0, offset=0
	long fogFar;						  // size=0, offset=0
	struct PLANSRCH_124fake gotoFrame;	// size=8, offset=0
	struct PLANSRCH_125fake changeModel;  // size=8, offset=0
	void *vmObject;						  // size=0, offset=0
	struct PLANSRCH_126fake logic;		  // size=8, offset=0
	void *callSignal;					  // size=0, offset=0
	struct _SVector offset;				  // size=8, offset=0
	struct Signal *gotoLabel;			  // size=0, offset=0
	struct Signal *gosubLabel;			  // size=0, offset=0
	struct PLANSRCH_127fake control;	  // size=8, offset=0
	struct PLANSRCH_128fake zSignal;	  // size=12, offset=0
	struct PLANSRCH_129fake StreamLevel;  // size=24, offset=0
	struct PLANSRCH_130fake shards;		  // size=12, offset=0
	struct PLANSRCH_131fake cameraSpline; // size=8, offset=0
	struct PLANSRCH_132fake screenWipe;   // size=4, offset=0
	long voiceSitId;					  // size=0, offset=0
	struct PLANSRCH_133fake introFX;	  // size=8, offset=0
	struct PLANSRCH_134fake introActive;  // size=8, offset=0
	struct PLANSRCH_135fake levelChange;  // size=18, offset=0
	long blendStart;					  // size=0, offset=0
	struct PLANSRCH_136fake setTimes;	 // size=8, offset=0
	struct PLANSRCH_137fake color;		  // size=4, offset=0
	struct PLANSRCH_138fake print;		  // size=12, offset=0
	long slideAngle;					  // size=0, offset=0
};

union PLANSRCH_140fake // Hashcode: 0xC151A2FD (dec: -1051614467)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union PLANSRCH_145fake // Hashcode: 0x2B1232B4 (dec: 722612916)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct PLANSRCH_147fake // hashcode: 0x77301E9F (dec: 1999642271)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xFD9A5E45 (dec: -40214971), parent name: 'PLANSRCH_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x2ADBDA08 (dec: 719051272), parent name: 'PLANSRCH_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x4D45ADBF (dec: 1296412095), parent name: 'PLANSRCH_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xE066200A (dec: -530178038), parent name: 'PLANSRCH_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x31BB2F9B (dec: 834351003), parent name: 'PLANSRCH_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xA156EF14 (dec: -1588138220), parent name: 'PLANSRCH_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x9C8C9EF0 (dec: -1668505872), parent name: 'PLANSRCH_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_148fake // hashcode: 0x3543EE97 (dec: 893644439)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0xB9AB7A89 (dec: -1179944311), parent name: 'PLANSRCH_148fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x6A1BC912 (dec: 1780205842), parent name: 'PLANSRCH_148fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xADFCE102 (dec: -1375936254), parent name: 'PLANSRCH_148fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_149fake // hashcode: 0x8A72E701 (dec: -1972181247)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xD3372B37 (dec: -751359177), parent name: 'PLANSRCH_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xC315A3C9 (dec: -1021991991), parent name: 'PLANSRCH_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xEB94FC95 (dec: -342557547), parent name: 'PLANSRCH_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x062EB08D (dec: 103723149), parent name: 'PLANSRCH_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x7A8D5D25 (dec: 2056084773), parent name: 'PLANSRCH_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_150fake // hashcode: 0x6FB59968 (dec: 1874172264)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xB2A69A7F (dec: -1297704321), parent name: 'PLANSRCH_150fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0xD5A501C1 (dec: -710606399), parent name: 'PLANSRCH_150fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x72B95BC3 (dec: 1924750275), parent name: 'PLANSRCH_150fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xE81CB0D7 (dec: -400772905), parent name: 'PLANSRCH_150fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x9D9BD70F (dec: -1650731249), parent name: 'PLANSRCH_150fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_151fake // hashcode: 0x490AB669 (dec: 1225438825)
{
	struct PLANSRCH_147fake Cinematic; // size=28, offset=0 //  hashcode: 0xFFB7AAB0 (dec: -4740432), parent name: 'PLANSRCH_151fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PLANSRCH_148fake Idle;	  // size=20, offset=28 //  hashcode: 0xD28B18A4 (dec: -762636124), parent name: 'PLANSRCH_151fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PLANSRCH_149fake Behind;	// size=28, offset=48 //  hashcode: 0x46447458 (dec: 1178891352), parent name: 'PLANSRCH_151fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PLANSRCH_150fake Follow;	// size=20, offset=76 //  hashcode: 0xC1C95DE1 (dec: -1043767839), parent name: 'PLANSRCH_151fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_176fake // hashcode: 0xB26F4E97 (dec: -1301328233)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x2C4D0FEE (dec: 743247854), parent name: 'PLANSRCH_176fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0xCBA26CF8 (dec: -878547720), parent name: 'PLANSRCH_176fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANSRCH_177fake // hashcode: 0x076896A6 (dec: 124294822)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x77CC76F9 (dec: 2009888505), parent name: 'PLANSRCH_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x4B679A0B (dec: 1265080843), parent name: 'PLANSRCH_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0xD7B88F04 (dec: -675770620), parent name: 'PLANSRCH_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0xFFA06FD4 (dec: -6262828), parent name: 'PLANSRCH_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x82438115 (dec: -2109505259), parent name: 'PLANSRCH_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x241311B6 (dec: 605229494), parent name: 'PLANSRCH_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLANSRCH_178fake // Hashcode: 0x5ECC1F61 (dec: 1590435681)
{
	struct PLANSRCH_176fake flame; // size=8, offset=0
	struct PLANSRCH_177fake phys;  // size=12, offset=0
};

union PLANSRCH_211fake // Hashcode: 0xDCCB3C3B (dec: -590660549)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

extern int PLANSRCH_ValidNode(struct PlanningNode *node, int validNodeTypes); // 0x80099DAC

extern struct PlanningNode *PLANSRCH_FindNodeToExpand(struct PlanningNode *planningPool, struct PlanningNode *goalNode, int validNodeTypes); // 0x80099DC4

extern void PLANSRCH_ExpandNode(struct PlanningNode *planningPool, struct PlanningNode *nodeToExpand); // 0x80099ED8

extern void PLANSRCH_InitNodesForSearch(struct PlanningNode *planningPool); // 0x80099FFC

extern struct PlanningNode *PLANSRCH_FindPathInGraph(struct PlanningNode *planningPool, struct PlanningNode *startNode, struct PlanningNode *goalNode, int validNodeTypes); // 0x8009A048

#endif
