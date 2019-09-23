#ifndef PLANPOOL_H
#define PLANPOOL_H

struct PLANPOOL_110fake // hashcode: 0x4AD87D6C (dec: 1255701868)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xC3E336FE (dec: -1008519426), parent name: 'PLANPOOL_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x15968B06 (dec: 362187526), parent name: 'PLANPOOL_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_111fake // hashcode: 0xA1DE6DA2 (dec: -1579258462)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xC6190919 (dec: -971437799), parent name: 'PLANPOOL_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xE43C0C79 (dec: -465826695), parent name: 'PLANPOOL_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_112fake // hashcode: 0xCFED194A (dec: -806545078)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x1336C9AA (dec: 322357674), parent name: 'PLANPOOL_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xE21152A3 (dec: -502181213), parent name: 'PLANPOOL_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLANPOOL_113fake // Hashcode: 0x56DC200F (dec: 1457266703)
{
	struct PLANPOOL_110fake callback; // size=8, offset=0
	struct PLANPOOL_111fake vector;   // size=12, offset=0
	struct PLANPOOL_112fake quat;	 // size=16, offset=0
};

union PLANPOOL_114fake // Hashcode: 0xC5FBA233 (dec: -973364685)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PLANPOOL_115fake // Hashcode: 0xE35335D9 (dec: -481085991)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct PLANPOOL_116fake // hashcode: 0x06FE9E72 (dec: 117350002)
{
	union PLANPOOL_115fake size; // size=4, offset=0 //  hashcode: 0x27F455F1 (dec: 670324209), parent name: 'PLANPOOL_116fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_117fake // hashcode: 0x551062D9 (dec: 1427137241)
{
	short x;				// size=0, offset=0 //  hashcode: 0x036AC33D (dec: 57328445), parent name: 'PLANPOOL_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x72BED552 (dec: 1925109074), parent name: 'PLANPOOL_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xEB910905 (dec: -342816507), parent name: 'PLANPOOL_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xAA25735E (dec: -1440386210), parent name: 'PLANPOOL_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x38102CA7 (dec: 940584103), parent name: 'PLANPOOL_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_118fake // hashcode: 0x27CF439B (dec: 667894683)
{
	long index; // size=0, offset=0 //  hashcode: 0xD5228BD5 (dec: -719156267), parent name: 'PLANPOOL_118fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x4C404C72 (dec: 1279282290), parent name: 'PLANPOOL_118fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_119fake // hashcode: 0x7CC356A5 (dec: 2093176485)
{
	long index; // size=0, offset=0 //  hashcode: 0x63658799 (dec: 1667598233), parent name: 'PLANPOOL_119fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xAFAE4178 (dec: -1347534472), parent name: 'PLANPOOL_119fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_120fake // hashcode: 0x6B0E2D65 (dec: 1796091237)
{
	long index; // size=0, offset=0 //  hashcode: 0x64241499 (dec: 1680086169), parent name: 'PLANPOOL_120fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x8E64A59F (dec: -1906006625), parent name: 'PLANPOOL_120fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_121fake // hashcode: 0xA5D1439B (dec: -1513012325)
{
	long time;  // size=0, offset=0 //  hashcode: 0x1926AE14 (dec: 421965332), parent name: 'PLANPOOL_121fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xC471CFE5 (dec: -999174171), parent name: 'PLANPOOL_121fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_122fake // hashcode: 0x84F15BAB (dec: -2064557141)
{
	long action;   // size=0, offset=0 //  hashcode: 0xD2271E74 (dec: -769188236), parent name: 'PLANPOOL_122fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x290CD884 (dec: 688707716), parent name: 'PLANPOOL_122fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_123fake // hashcode: 0x4F1E683A (dec: 1327392826)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xA84763D4 (dec: -1471716396), parent name: 'PLANPOOL_123fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x7B4253B6 (dec: 2067944374), parent name: 'PLANPOOL_123fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_124fake // hashcode: 0x3B4DB3F1 (dec: 994948081)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x27507984 (dec: 659585412), parent name: 'PLANPOOL_124fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x8B7363FE (dec: -1955372034), parent name: 'PLANPOOL_124fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_125fake // hashcode: 0x92373BA9 (dec: -1841874007)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x83147D4D (dec: -2095809203), parent name: 'PLANPOOL_125fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xB04AF527 (dec: -1337264857), parent name: 'PLANPOOL_125fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_126fake // hashcode: 0x2E72C732 (dec: 779274034)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x5DD9EEE5 (dec: 1574563557), parent name: 'PLANPOOL_126fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x48D0FC3C (dec: 1221655612), parent name: 'PLANPOOL_126fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x07108B72 (dec: 118524786), parent name: 'PLANPOOL_126fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x12180795 (dec: 303564693), parent name: 'PLANPOOL_126fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x67837691 (dec: 1736668817), parent name: 'PLANPOOL_126fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_127fake // hashcode: 0xB4814E9A (dec: -1266594150)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xB2AD294F (dec: -1297274545), parent name: 'PLANPOOL_127fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x50C3C713 (dec: 1355007763), parent name: 'PLANPOOL_127fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_128fake // hashcode: 0x57C1CDC4 (dec: 1472318916)
{
	short index;					// size=0, offset=0 //  hashcode: 0x1EF58DFD (dec: 519409149), parent name: 'PLANPOOL_128fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xF70699B9 (dec: -150562375), parent name: 'PLANPOOL_128fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xD814B80F (dec: -669730801), parent name: 'PLANPOOL_128fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xF0C6C1A3 (dec: -255409757), parent name: 'PLANPOOL_128fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_129fake // hashcode: 0xB8CE69F2 (dec: -1194432014)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x764E0ACC (dec: 1984826060), parent name: 'PLANPOOL_129fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x4AC86648 (dec: 1254647368), parent name: 'PLANPOOL_129fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xB2EAF643 (dec: -1293224381), parent name: 'PLANPOOL_129fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_130fake // hashcode: 0x52E5A2D6 (dec: 1390781142)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x06DF320F (dec: 115290639), parent name: 'PLANPOOL_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xB5D1D5FF (dec: -1244539393), parent name: 'PLANPOOL_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x1879F20A (dec: 410645002), parent name: 'PLANPOOL_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x04D9ECA6 (dec: 81390758), parent name: 'PLANPOOL_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x3197C5F2 (dec: 832030194), parent name: 'PLANPOOL_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xA8D4DFB7 (dec: -1462444105), parent name: 'PLANPOOL_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x0C4D77A7 (dec: 206403495), parent name: 'PLANPOOL_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_131fake // hashcode: 0x33AAF44D (dec: 866841677)
{
	long index;  // size=0, offset=0 //  hashcode: 0x2B53AECB (dec: 726904523), parent name: 'PLANPOOL_131fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x93A2E953 (dec: -1818039981), parent name: 'PLANPOOL_131fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_132fake // hashcode: 0x2044948A (dec: 541365386)
{
	short type; // size=0, offset=0 //  hashcode: 0xFB36A26A (dec: -80305558), parent name: 'PLANPOOL_132fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x36AE6085 (dec: 917397637), parent name: 'PLANPOOL_132fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_133fake // hashcode: 0xF9158F3E (dec: -116027586)
{
	long time;   // size=0, offset=0 //  hashcode: 0xE2B5CD7C (dec: -491401860), parent name: 'PLANPOOL_133fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xC375FF52 (dec: -1015677102), parent name: 'PLANPOOL_133fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_134fake // hashcode: 0xD1D3FA12 (dec: -774637038)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x44286804 (dec: 1143498756), parent name: 'PLANPOOL_134fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x3D47B36A (dec: 1028109162), parent name: 'PLANPOOL_134fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_135fake // hashcode: 0x33DF4F53 (dec: 870272851)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xB48DC531 (dec: -1265777359), parent name: 'PLANPOOL_135fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xC7BABE02 (dec: -944062974), parent name: 'PLANPOOL_135fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_136fake // hashcode: 0x0BC7A343 (dec: 197632835)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x7E52B7AD (dec: 2119350189), parent name: 'PLANPOOL_136fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x7C5EB099 (dec: 2086580377), parent name: 'PLANPOOL_136fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_137fake // hashcode: 0xE8DCFEA1 (dec: -388170079)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x77ECAEC3 (dec: 2011999939), parent name: 'PLANPOOL_137fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x3D7355DD (dec: 1030968797), parent name: 'PLANPOOL_137fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xCEB4DC4C (dec: -827007924), parent name: 'PLANPOOL_137fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xCE8C2837 (dec: -829675465), parent name: 'PLANPOOL_137fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_138fake // hashcode: 0x92FAA454 (dec: -1829067692)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x15A35D1A (dec: 363027738), parent name: 'PLANPOOL_138fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x38821D86 (dec: 948051334), parent name: 'PLANPOOL_138fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x550C7715 (dec: 1426880277), parent name: 'PLANPOOL_138fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xAC9C62A4 (dec: -1399037276), parent name: 'PLANPOOL_138fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x19E53FBC (dec: 434454460), parent name: 'PLANPOOL_138fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLANPOOL_139fake // Hashcode: 0x7F05C678 (dec: 2131084920)
{
	struct PLANPOOL_116fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;		  // size=24, offset=0
	struct PLANPOOL_117fake teleport;	 // size=16, offset=0
	struct PLANPOOL_118fake cameraValue;  // size=8, offset=0
	struct PLANPOOL_119fake miscValue;	// size=8, offset=0
	struct PLANPOOL_120fake logicValue;   // size=8, offset=0
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
	struct PLANPOOL_121fake cameraShake;  // size=8, offset=0
	long cameraSave;					  // size=0, offset=0
	long cameraRestore;					  // size=0, offset=0
	struct _BGObject *bgObject;			  // size=24, offset=0
	long value[2];						  // size=8, offset=0
	struct PLANPOOL_122fake sound;		  // size=12, offset=0
	void *intro;						  // size=0, offset=0
	long deathZ;						  // size=0, offset=0
	struct PLANPOOL_123fake dsignal;	  // size=8, offset=0
	void *mirror;						  // size=0, offset=0
	long fogNear;						  // size=0, offset=0
	long fogFar;						  // size=0, offset=0
	struct PLANPOOL_124fake gotoFrame;	// size=8, offset=0
	struct PLANPOOL_125fake changeModel;  // size=8, offset=0
	void *vmObject;						  // size=0, offset=0
	struct PLANPOOL_126fake logic;		  // size=8, offset=0
	void *callSignal;					  // size=0, offset=0
	struct _SVector offset;				  // size=8, offset=0
	struct Signal *gotoLabel;			  // size=0, offset=0
	struct Signal *gosubLabel;			  // size=0, offset=0
	struct PLANPOOL_127fake control;	  // size=8, offset=0
	struct PLANPOOL_128fake zSignal;	  // size=12, offset=0
	struct PLANPOOL_129fake StreamLevel;  // size=24, offset=0
	struct PLANPOOL_130fake shards;		  // size=12, offset=0
	struct PLANPOOL_131fake cameraSpline; // size=8, offset=0
	struct PLANPOOL_132fake screenWipe;   // size=4, offset=0
	long voiceSitId;					  // size=0, offset=0
	struct PLANPOOL_133fake introFX;	  // size=8, offset=0
	struct PLANPOOL_134fake introActive;  // size=8, offset=0
	struct PLANPOOL_135fake levelChange;  // size=18, offset=0
	long blendStart;					  // size=0, offset=0
	struct PLANPOOL_136fake setTimes;	 // size=8, offset=0
	struct PLANPOOL_137fake color;		  // size=4, offset=0
	struct PLANPOOL_138fake print;		  // size=12, offset=0
	long slideAngle;					  // size=0, offset=0
};

union PLANPOOL_140fake // Hashcode: 0x7C4EC907 (dec: 2085538055)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union PLANPOOL_145fake // Hashcode: 0x971914B4 (dec: -1759963980)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct PLANPOOL_147fake // hashcode: 0x0E27440B (dec: 237454347)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x4BD20653 (dec: 1272055379), parent name: 'PLANPOOL_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x6A746450 (dec: 1786012752), parent name: 'PLANPOOL_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x4C523E0A (dec: 1280458250), parent name: 'PLANPOOL_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xBB408936 (dec: -1153398474), parent name: 'PLANPOOL_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x05F8C6D0 (dec: 100189904), parent name: 'PLANPOOL_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x785B0FBD (dec: 2019233725), parent name: 'PLANPOOL_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x667A2C63 (dec: 1719282787), parent name: 'PLANPOOL_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_148fake // hashcode: 0xCFD355CA (dec: -808233526)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0xF5EB7EDC (dec: -169115940), parent name: 'PLANPOOL_148fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x516CBB08 (dec: 1366080264), parent name: 'PLANPOOL_148fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xBB06D8D6 (dec: -1157179178), parent name: 'PLANPOOL_148fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_149fake // hashcode: 0x316FD9F6 (dec: 829413878)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x23E605F1 (dec: 602277361), parent name: 'PLANPOOL_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xB9C5398D (dec: -1178257011), parent name: 'PLANPOOL_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x806CBD98 (dec: -2140357224), parent name: 'PLANPOOL_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x0699E0C1 (dec: 110747841), parent name: 'PLANPOOL_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x70175C9C (dec: 1880579228), parent name: 'PLANPOOL_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_150fake // hashcode: 0x51965309 (dec: 1368806153)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x35565DA4 (dec: 894852516), parent name: 'PLANPOOL_150fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x9E8A5E86 (dec: -1635099002), parent name: 'PLANPOOL_150fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x73D66663 (dec: 1943430755), parent name: 'PLANPOOL_150fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x1EB6E425 (dec: 515302437), parent name: 'PLANPOOL_150fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x003AB968 (dec: 3848552), parent name: 'PLANPOOL_150fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_151fake // hashcode: 0x1F99F3B2 (dec: 530183090)
{
	struct PLANPOOL_147fake Cinematic; // size=28, offset=0 //  hashcode: 0x96552785 (dec: -1772804219), parent name: 'PLANPOOL_151fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PLANPOOL_148fake Idle;	  // size=20, offset=28 //  hashcode: 0xF8FE98F9 (dec: -117532423), parent name: 'PLANPOOL_151fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PLANPOOL_149fake Behind;	// size=28, offset=48 //  hashcode: 0x516B9625 (dec: 1366005285), parent name: 'PLANPOOL_151fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PLANPOOL_150fake Follow;	// size=20, offset=76 //  hashcode: 0xD742A912 (dec: -683497198), parent name: 'PLANPOOL_151fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_176fake // hashcode: 0xC4F42EE6 (dec: -990630170)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0xB3C1C36B (dec: -1279147157), parent name: 'PLANPOOL_176fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x9E5AD5C4 (dec: -1638214204), parent name: 'PLANPOOL_176fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANPOOL_177fake // hashcode: 0x2CFF024E (dec: 754909774)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0xD235063C (dec: -768276932), parent name: 'PLANPOOL_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0xBB30F8F2 (dec: -1154418446), parent name: 'PLANPOOL_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0xFFF11348 (dec: -978104), parent name: 'PLANPOOL_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0xE030310D (dec: -533712627), parent name: 'PLANPOOL_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x98C5319D (dec: -1731907171), parent name: 'PLANPOOL_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0xCB187DAA (dec: -887587414), parent name: 'PLANPOOL_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLANPOOL_178fake // Hashcode: 0x659D8613 (dec: 1704822291)
{
	struct PLANPOOL_176fake flame; // size=8, offset=0
	struct PLANPOOL_177fake phys;  // size=12, offset=0
};

union PLANPOOL_211fake // Hashcode: 0x03C6821C (dec: 63341084)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

extern int PLANPOOL_NumNodesInPlan(struct PlanningNode *goalNode, struct PlanningNode *planningPool); // 0x80099208

extern int PLANPOOL_CountBitsSetInLong(long mylong); // 0x80099254

extern int PLANPOOL_NumConnectionsExaminedForNode(struct PlanningNode *node); // 0x80099274

extern int PLANPOOL_NumConnectionsForNode(struct PlanningNode *node); // 0x80099298

extern struct PlanningNode *PLANPOOL_GetFirstNodeOfSource(struct PlanningNode *planningPool, char nodeSource); // 0x800992BC

extern int PLANPOOL_NumberOfNodesOfType(struct PlanningNode *planningPool, char nodeType); // 0x8009930C

extern int PLANPOOL_NumberOfNodesOfSource(struct PlanningNode *planningPool, char nodeSource); // 0x80099358

extern struct PlanningNode *PLANPOOL_GetNodeWithID(struct PlanningNode *planningPool, int type, int id, long suID); // 0x800993A8

extern struct PlanningNode *PLANPOOL_GetNodeByPosition(struct _Position *currentPos, struct PlanningNode *planningPool); // 0x80099414

extern struct PlanningNode *PLANPOOL_GetClosestNode(struct _Position *pos, struct PlanningNode *planningPool, char distanceType); // 0x800994E8

extern int PLANPOOL_AppropriatePair(struct PlanningNode *node1, struct PlanningNode *node2); // 0x800995E8

extern int PLANPOOL_AreTwoNodesConnected(struct PlanningNode *node1, struct PlanningNode *node2, struct PlanningNode *planningPool); // 0x8009975C

extern void PLANPOOL_MarkTwoNodesAsConnected(struct PlanningNode *node1, struct PlanningNode *node2, struct PlanningNode *planningPool); // 0x800997CC

extern void PLANPOOL_MarkTwoNodesAsNotConnected(struct PlanningNode *node1, struct PlanningNode *node2, struct PlanningNode *planningPool); // 0x800998C8

extern struct PlanningNode *PLANPOOL_GetClosestUnexploredValidNeighbor(struct PlanningNode *startNode, struct PlanningNode *planningPool); // 0x80099924

extern void PLANPOOL_ChangeNodePosition(struct _Position *newPos, struct PlanningNode *nodeToChange, struct PlanningNode *planningPool); // 0x80099A34

extern struct PlanningNode *PLANPOOL_AddNodeToPool(struct _Position *pos, struct PlanningNode *planningPool, short nodeType, short nodeID, long streamUnitID); // 0x80099AEC

extern void PLANPOOL_DeleteNodeFromPool(struct PlanningNode *nodeToDelete, struct PlanningNode *planningPool); // 0x80099BE0

#endif
