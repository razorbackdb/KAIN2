#ifndef MONLIB_H
#define MONLIB_H

struct MONLIB_73fake // hashcode: 0xDB6B421F (dec: -613727713)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xC8B446E2 (dec: -927709470), parent name: 'MONLIB_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0xBD132EAA (dec: -1122816342), parent name: 'MONLIB_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_74fake // hashcode: 0x6DE71DB3 (dec: 1843862963)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x34600D01 (dec: 878710017), parent name: 'MONLIB_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xA8A757DB (dec: -1465428005), parent name: 'MONLIB_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_75fake // hashcode: 0x12F6B755 (dec: 318158677)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xEF18105D (dec: -283635619), parent name: 'MONLIB_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x07BD275F (dec: 129836895), parent name: 'MONLIB_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONLIB_76fake // Hashcode: 0x270AB0E0 (dec: 655012064)
{
	struct MONLIB_73fake callback; // size=8, offset=0
	struct MONLIB_74fake vector;   // size=12, offset=0
	struct MONLIB_75fake quat;	 // size=16, offset=0
};

union MONLIB_77fake // Hashcode: 0x3370E575 (dec: 863036789)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MONLIB_78fake // Hashcode: 0x22857CFB (dec: 579173627)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct MONLIB_79fake // hashcode: 0xB487B8D6 (dec: -1266173738)
{
	union MONLIB_78fake size; // size=4, offset=0 //  hashcode: 0x8BF94129 (dec: -1946599127), parent name: 'MONLIB_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_80fake // hashcode: 0x9988C3FD (dec: -1719090179)
{
	short x;				// size=0, offset=0 //  hashcode: 0xC2EB2F1A (dec: -1024774374), parent name: 'MONLIB_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xCE945AB2 (dec: -829138254), parent name: 'MONLIB_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xEA3644BC (dec: -365542212), parent name: 'MONLIB_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x43D9194B (dec: 1138301259), parent name: 'MONLIB_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x95442A1A (dec: -1790694886), parent name: 'MONLIB_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_81fake // hashcode: 0xE2D097C6 (dec: -489646138)
{
	long index; // size=0, offset=0 //  hashcode: 0x80A16873 (dec: -2136905613), parent name: 'MONLIB_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x1AFE914E (dec: 452890958), parent name: 'MONLIB_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_82fake // hashcode: 0x765D9ACE (dec: 1985845966)
{
	long index; // size=0, offset=0 //  hashcode: 0x04B0AADD (dec: 78686941), parent name: 'MONLIB_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x39E88854 (dec: 971540564), parent name: 'MONLIB_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_83fake // hashcode: 0xC67F2BC0 (dec: -964744256)
{
	long index; // size=0, offset=0 //  hashcode: 0x128A0577 (dec: 311035255), parent name: 'MONLIB_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x3E1E6DF9 (dec: 1042181625), parent name: 'MONLIB_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_84fake // hashcode: 0xC57431F8 (dec: -982240776)
{
	long time;  // size=0, offset=0 //  hashcode: 0x5BCE8404 (dec: 1540260868), parent name: 'MONLIB_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x1AF41F66 (dec: 452206438), parent name: 'MONLIB_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_85fake // hashcode: 0xD8240DB9 (dec: -668725831)
{
	long action;   // size=0, offset=0 //  hashcode: 0xB9528DEE (dec: -1185772050), parent name: 'MONLIB_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xAFEC7710 (dec: -1343457520), parent name: 'MONLIB_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_86fake // hashcode: 0xC812380E (dec: -938330098)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x075EB940 (dec: 123648320), parent name: 'MONLIB_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xDEF10661 (dec: -554629535), parent name: 'MONLIB_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_87fake // hashcode: 0x8DF24CC2 (dec: -1913500478)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xF466B3AB (dec: -194595925), parent name: 'MONLIB_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x324F33D6 (dec: 844051414), parent name: 'MONLIB_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_88fake // hashcode: 0x1C4E776D (dec: 474904429)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x1567D18D (dec: 359125389), parent name: 'MONLIB_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x64A593EE (dec: 1688572910), parent name: 'MONLIB_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_89fake // hashcode: 0x87CC6D1A (dec: -2016645862)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x59B3E445 (dec: 1504961605), parent name: 'MONLIB_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xA2A09EA5 (dec: -1566531931), parent name: 'MONLIB_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x63906451 (dec: 1670407249), parent name: 'MONLIB_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x825CF47A (dec: -2107837318), parent name: 'MONLIB_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xA4776931 (dec: -1535678159), parent name: 'MONLIB_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_90fake // hashcode: 0x8E2EB25E (dec: -1909542306)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xCB91DE2F (dec: -879632849), parent name: 'MONLIB_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xEAEAA48B (dec: -353721205), parent name: 'MONLIB_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_91fake // hashcode: 0x6BDA8BBD (dec: 1809484733)
{
	short index;					// size=0, offset=0 //  hashcode: 0xD10144FF (dec: -788445953), parent name: 'MONLIB_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x80252838 (dec: -2145048520), parent name: 'MONLIB_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xF255E3AB (dec: -229252181), parent name: 'MONLIB_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x1C090963 (dec: 470354275), parent name: 'MONLIB_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_92fake // hashcode: 0xA5E49CA3 (dec: -1511744349)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x32CA07AD (dec: 852101037), parent name: 'MONLIB_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x565EA808 (dec: 1449043976), parent name: 'MONLIB_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xAF623D34 (dec: -1352516300), parent name: 'MONLIB_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_93fake // hashcode: 0xE1A7C779 (dec: -509098119)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xEDF0D870 (dec: -302983056), parent name: 'MONLIB_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xEB99DDA4 (dec: -342237788), parent name: 'MONLIB_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xE9936E38 (dec: -376213960), parent name: 'MONLIB_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x46745AF2 (dec: 1182030578), parent name: 'MONLIB_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x5E53FAEA (dec: 1582562026), parent name: 'MONLIB_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x804E533B (dec: -2142350533), parent name: 'MONLIB_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x1BA6A271 (dec: 463905393), parent name: 'MONLIB_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_94fake // hashcode: 0x138FB200 (dec: 328184320)
{
	long index;  // size=0, offset=0 //  hashcode: 0x08FBCD79 (dec: 150719865), parent name: 'MONLIB_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xA9B385D3 (dec: -1447852589), parent name: 'MONLIB_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_95fake // hashcode: 0x083392F1 (dec: 137597681)
{
	short type; // size=0, offset=0 //  hashcode: 0x894E991F (dec: -1991337697), parent name: 'MONLIB_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xE9791913 (dec: -377939693), parent name: 'MONLIB_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_96fake // hashcode: 0x3DB68D4A (dec: 1035373898)
{
	long time;   // size=0, offset=0 //  hashcode: 0xF7012F30 (dec: -150917328), parent name: 'MONLIB_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xE1B92302 (dec: -507960574), parent name: 'MONLIB_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_97fake // hashcode: 0x0EE0B953 (dec: 249608531)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xA7D4A20D (dec: -1479237107), parent name: 'MONLIB_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x477300A3 (dec: 1198719139), parent name: 'MONLIB_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_98fake // hashcode: 0xAEC3330C (dec: -1362939124)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x3EA34625 (dec: 1050887717), parent name: 'MONLIB_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xF93380A2 (dec: -114065246), parent name: 'MONLIB_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_99fake // hashcode: 0x59C302A2 (dec: 1505952418)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x31126442 (dec: 823288898), parent name: 'MONLIB_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x507359A9 (dec: 1349736873), parent name: 'MONLIB_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_100fake // hashcode: 0x7811EB06 (dec: 2014440198)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x384A907C (dec: 944410748), parent name: 'MONLIB_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x6BEC6150 (dec: 1810653520), parent name: 'MONLIB_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xAF94E165 (dec: -1349197467), parent name: 'MONLIB_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x2681DBEB (dec: 646044651), parent name: 'MONLIB_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_101fake // hashcode: 0xF73E5318 (dec: -146910440)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xADABBF06 (dec: -1381253370), parent name: 'MONLIB_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x34F5091E (dec: 888473886), parent name: 'MONLIB_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x909EB42B (dec: -1868647381), parent name: 'MONLIB_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xD4BD888B (dec: -725776245), parent name: 'MONLIB_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x6E1261E8 (dec: 1846698472), parent name: 'MONLIB_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONLIB_102fake // Hashcode: 0xC749FE58 (dec: -951452072)
{
	struct MONLIB_79fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	  // size=24, offset=0
	struct MONLIB_80fake teleport;	 // size=16, offset=0
	struct MONLIB_81fake cameraValue;  // size=8, offset=0
	struct MONLIB_82fake miscValue;	// size=8, offset=0
	struct MONLIB_83fake logicValue;   // size=8, offset=0
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
	struct MONLIB_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				   // size=0, offset=0
	long cameraRestore;				   // size=0, offset=0
	struct _BGObject *bgObject;		   // size=24, offset=0
	long value[2];					   // size=8, offset=0
	struct MONLIB_85fake sound;		   // size=12, offset=0
	void *intro;					   // size=0, offset=0
	long deathZ;					   // size=0, offset=0
	struct MONLIB_86fake dsignal;	  // size=8, offset=0
	void *mirror;					   // size=0, offset=0
	long fogNear;					   // size=0, offset=0
	long fogFar;					   // size=0, offset=0
	struct MONLIB_87fake gotoFrame;	// size=8, offset=0
	struct MONLIB_88fake changeModel;  // size=8, offset=0
	void *vmObject;					   // size=0, offset=0
	struct MONLIB_89fake logic;		   // size=8, offset=0
	void *callSignal;				   // size=0, offset=0
	struct _SVector offset;			   // size=8, offset=0
	struct Signal *gotoLabel;		   // size=0, offset=0
	struct Signal *gosubLabel;		   // size=0, offset=0
	struct MONLIB_90fake control;	  // size=8, offset=0
	struct MONLIB_91fake zSignal;	  // size=12, offset=0
	struct MONLIB_92fake StreamLevel;  // size=24, offset=0
	struct MONLIB_93fake shards;	   // size=12, offset=0
	struct MONLIB_94fake cameraSpline; // size=8, offset=0
	struct MONLIB_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				   // size=0, offset=0
	struct MONLIB_96fake introFX;	  // size=8, offset=0
	struct MONLIB_97fake introActive;  // size=8, offset=0
	struct MONLIB_98fake levelChange;  // size=18, offset=0
	long blendStart;				   // size=0, offset=0
	struct MONLIB_99fake setTimes;	 // size=8, offset=0
	struct MONLIB_100fake color;	   // size=4, offset=0
	struct MONLIB_101fake print;	   // size=12, offset=0
	long slideAngle;				   // size=0, offset=0
};

union MONLIB_103fake // Hashcode: 0x552471A9 (dec: 1428451753)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union MONLIB_108fake // Hashcode: 0x2CB19586 (dec: 749835654)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct MONLIB_110fake // hashcode: 0x5638B229 (dec: 1446556201)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x6173646F (dec: 1634952303), parent name: 'MONLIB_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x2B93543F (dec: 731075647), parent name: 'MONLIB_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x568AD9EA (dec: 1451940330), parent name: 'MONLIB_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xF8AD0F27 (dec: -122876121), parent name: 'MONLIB_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x0ED3DB25 (dec: 248765221), parent name: 'MONLIB_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x9603666C (dec: -1778162068), parent name: 'MONLIB_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x8D1372F1 (dec: -1928105231), parent name: 'MONLIB_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_111fake // hashcode: 0xE6416A0D (dec: -431920627)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x79215E38 (dec: 2032229944), parent name: 'MONLIB_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x0A9A4A84 (dec: 177883780), parent name: 'MONLIB_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x80F6915A (dec: -2131324582), parent name: 'MONLIB_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_112fake // hashcode: 0xF933E71D (dec: -114039011)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x44C7040B (dec: 1153893387), parent name: 'MONLIB_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xAE132DBF (dec: -1374474817), parent name: 'MONLIB_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x217A5E58 (dec: 561667672), parent name: 'MONLIB_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x380D291E (dec: 940386590), parent name: 'MONLIB_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x91D220BA (dec: -1848500038), parent name: 'MONLIB_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_113fake // hashcode: 0x2601F121 (dec: 637661473)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x4891D530 (dec: 1217516848), parent name: 'MONLIB_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x8FE72BB2 (dec: -1880675406), parent name: 'MONLIB_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x83CE129C (dec: -2083646820), parent name: 'MONLIB_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x72F7BFD2 (dec: 1928839122), parent name: 'MONLIB_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x3A288050 (dec: 975732816), parent name: 'MONLIB_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_114fake // hashcode: 0x0EFC9F39 (dec: 251436857)
{
	struct MONLIB_110fake Cinematic; // size=28, offset=0 //  hashcode: 0xC88EDA8E (dec: -930162034), parent name: 'MONLIB_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MONLIB_111fake Idle;		 // size=20, offset=28 //  hashcode: 0xE8984887 (dec: -392673145), parent name: 'MONLIB_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MONLIB_112fake Behind;	// size=28, offset=48 //  hashcode: 0xE8118F26 (dec: -401502426), parent name: 'MONLIB_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MONLIB_113fake Follow;	// size=20, offset=76 //  hashcode: 0x90D02B0B (dec: -1865405685), parent name: 'MONLIB_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evPhysicsLOSData // hashcode: 0x3AEAF56B (dec: 988476779)
{
	struct _Position destination; // size=6, offset=0 //  hashcode: 0x2194F4E1 (dec: 563410145), parent name: 'evPhysicsLOSData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short arc;					  // size=0, offset=6 //  hashcode: 0xD8A1B988 (dec: -660489848), parent name: 'evPhysicsLOSData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position origin;	  // size=6, offset=8 //  hashcode: 0x4E51F161 (dec: 1313993057), parent name: 'evPhysicsLOSData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;				  // size=0, offset=14 //  hashcode: 0x0F842AAC (dec: 260319916), parent name: 'evPhysicsLOSData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short result;				  // size=0, offset=16 //  hashcode: 0xA757D920 (dec: -1487415008), parent name: 'evPhysicsLOSData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONLIB_208fake // Hashcode: 0x7EC2D3DE (dec: 2126697438)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

enum MonsterAnim // Hashcode: 0xCB25B8B5 (dec: -886720331)
{
	MONSTER_ANIM_HIT1 = 0,
	MONSTER_ANIM_HIT2 = 1,
	MONSTER_ANIM_WALK = 2,
	MONSTER_ANIM_RUN = 3,
	MONSTER_ANIM_GRABBED = 4,
	MONSTER_ANIM_STUNNED = 5,
	MONSTER_ANIM_JUMPFORWARD = 6,
	MONSTER_ANIM_JUMPBACK = 7,
	MONSTER_ANIM_JUMPLEFT = 8,
	MONSTER_ANIM_JUMPRIGHT = 9,
	MONSTER_ANIM_STANCE_HEALTHY = 10,
	MONSTER_ANIM_STANCE_VULNERABLE = 11,
	MONSTER_ANIM_STUNNED_RECOVERY = 12,
	MONSTER_ANIM_IMPALED = 13,
	MONSTER_ANIM_STRUGGLE = 14,
	MONSTER_ANIM_BREAKHOLD = 15,
	MONSTER_ANIM_THROWN = 16,
	MONSTER_ANIM_IMPACT = 17,
	MONSTER_ANIM_LANDONFEET = 18,
	MONSTER_ANIM_FALL = 19,
	MONSTER_ANIM_BREAKFALL = 20,
	MONSTER_ANIM_SPINLAND = 21,
	MONSTER_ANIM_IMPALEDEATH = 22,
	MONSTER_ANIM_GETUP = 23,
	MONSTER_ANIM_GENERALDEATH = 24,
	MONSTER_ANIM_MISSILEIMPALEDEATH = 25,
	MONSTER_ANIM_SURPRISED = 26,
	MONSTER_ANIM_AGONY = 27,
	MONSTER_ANIM_PUPATE = 28,
	MONSTER_ANIM_NOTICE = 29,
	MONSTER_ANIM_SOULSUCK = 30,
	MONSTER_ANIM_IMPALEHORZ = 31,
	MONSTER_ANIM_IMPALEVERT = 32,
	MONSTER_ANIM_SOULOUTGRND = 33,
	MONSTER_ANIM_SOULOUTHORZ = 34,
	MONSTER_ANIM_SOULOUTVERT = 35,
	MONSTER_ANIM_FALLOVER = 36,
	MONSTER_ANIM_EMBRACE = 37,
	MONSTER_ANIM_SHOVE = 38,
	MONSTER_ANIM_FLIPSWITCH = 39,
	MONSTER_ANIM_EVADELEFT = 40,
	MONSTER_ANIM_EVADERIGHT = 41,
	MONSTER_ANIM_ALARM = 42,
	MONSTER_ANIM_DEAF = 43,
	MONSTER_ANIM_BLIND = 44,
	MONSTER_ANIM_SUCKED = 45,
	MONSTER_NUM_ANIMS = 46,
};

enum MonsterState // Hashcode: 0xD129E7A3 (dec: -785782877)
{
	MONSTER_STATE_BIRTH = 0,
	MONSTER_STATE_PURSUE = 1,
	MONSTER_STATE_IDLE = 2,
	MONSTER_STATE_MISSILEHIT = 3,
	MONSTER_STATE_FALL = 4,
	MONSTER_STATE_WANDER = 5,
	MONSTER_STATE_ATTACK = 6,
	MONSTER_STATE_IMPALEDEATH = 7,
	MONSTER_STATE_HIT = 8,
	MONSTER_STATE_STUNNED = 9,
	MONSTER_STATE_GRABBED = 10,
	MONSTER_STATE_THROWN = 11,
	MONSTER_STATE_IMPACT = 12,
	MONSTER_STATE_COMBAT = 13,
	MONSTER_STATE_BREAKHOLD = 14,
	MONSTER_STATE_LANDONFEET = 15,
	MONSTER_STATE_GENERALDEATH = 16,
	MONSTER_STATE_ENVIRONMENTDAMAGE = 17,
	MONSTER_STATE_LANDINWATER = 18,
	MONSTER_STATE_FLEE = 19,
	MONSTER_STATE_HIDE = 20,
	MONSTER_STATE_SURPRISEATTACK = 21,
	MONSTER_STATE_PARRY = 22,
	MONSTER_STATE_DEAD = 23,
	MONSTER_STATE_SURPRISED = 24,
	MONSTER_STATE_NOTICE = 25,
	MONSTER_STATE_PUPATE = 26,
	MONSTER_STATE_EMBRACE = 27,
	MONSTER_STATE_PROJECTILE = 28,
	MONSTER_STATE_TERRAINIMPALEDEATH = 29,
	MONSTER_STATE_PETRIFIED = 30,
	MONSTER_NUM_STATES = 31,
};

struct MONLIB_268fake // hashcode: 0xE134467C (dec: -516667780)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0xBE3F4243 (dec: -1103150525), parent name: 'MONLIB_268fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0xC8997AFB (dec: -929465605), parent name: 'MONLIB_268fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONLIB_269fake // hashcode: 0x2BCF3B2D (dec: 735001389)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x4F9DC5CE (dec: 1335739854), parent name: 'MONLIB_269fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x80802090 (dec: -2139086704), parent name: 'MONLIB_269fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x28EB6C5F (dec: 686517343), parent name: 'MONLIB_269fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x2BF066AC (dec: 737175212), parent name: 'MONLIB_269fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0xEF54C8DC (dec: -279656228), parent name: 'MONLIB_269fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x45140CAB (dec: 1158941867), parent name: 'MONLIB_269fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONLIB_270fake // Hashcode: 0x7358211B (dec: 1935155483)
{
	struct MONLIB_268fake flame; // size=8, offset=0
	struct MONLIB_269fake phys;  // size=12, offset=0
};

typedef struct evPhysicsLOSData evPhysicsLOSData;

extern void MON_TurnOffWeaponSpheres(struct _Instance *instance); // 0x8007F3E4

extern void MON_TurnOnWeaponSpheres(struct _Instance *instance); // 0x8007F4DC

extern void MON_TurnOnWeaponSphere(struct _Instance *instance, int segment); // 0x8007F594

extern void MON_TurnOffBodySpheres(struct _Instance *instance); // 0x8007F69C

extern void MON_TurnOnBodySpheres(struct _Instance *instance); // 0x8007F744

extern void MON_TurnOffAllSpheres(struct _Instance *instance); // 0x8007F7F8

extern void MON_TurnOnAllSpheres(struct _Instance *instance); // 0x8007F824

extern void MON_SwitchState(struct _Instance *instance, enum MonsterState state); // 0x8007F850

extern void MON_SwitchStateDoEntry(struct _Instance *instance, enum MonsterState state); // 0x8007F94C

extern int MON_TransNodeAnimation(struct _Instance *instance); // 0x8007F9B4

extern struct _MonsterAnim *MON_GetAnim(struct _Instance *instance, char *animList, int index); // 0x8007F9DC

extern void MON_PlayAnimID(struct _Instance *instance, int index, int mode); // 0x8007FA10

extern void MON_PlayAnimFromList(struct _Instance *instance, char *animList, int animtype, int mode); // 0x8007FBC8

extern int MON_AnimIDPlaying(struct _Instance *instance, int index); // 0x8007FBF0

extern void MON_PlayAnimIDIfNotPlaying(struct _Instance *instance, int index, int mode); // 0x8007FC14

extern int MON_AnimPlayingFromList(struct _Instance *instance, char *animList, int animtype); // 0x8007FC64

extern void MON_PlayAnimFromListIfNotPlaying(struct _Instance *instance, char *animList, int animtype, int mode); // 0x8007FC8C

extern void MON_PlayAnim(struct _Instance *instance, enum MonsterAnim animtype, int mode); // 0x8007FCE4

extern int MON_AnimPlaying(struct _Instance *instance, enum MonsterAnim animtype); // 0x8007FD18

extern void MON_PlayAnimIfNotPlaying(struct _Instance *instance, enum MonsterAnim animtype, int mode); // 0x8007FD4C

extern long MON_AnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, void *data); // 0x8007FD80

extern void MON_AnimInit(struct _Instance *instance); // 0x8007FE30

extern short MON_FacingOffset(struct _Instance *instance, struct _Instance *target); // 0x8007FFA8

extern int MON_CheckConditions(struct _Instance *instance, struct _MonsterIR *mir, char *probArray); // 0x8007FFE4

extern int MON_ShouldIAttackInstance(struct _Instance *instance, struct _Instance *ei); // 0x800800BC

extern int MON_ShouldIAttack(struct _Instance *instance, struct _MonsterIR *enemy, struct _MonsterAttackAttributes *attack); // 0x800801E0

extern struct _MonsterAttackAttributes *MON_ChooseAttack(struct _Instance *instance, struct _MonsterIR *enemy); // 0x80080388

extern int MON_ShouldIEvade(struct _Instance *instance); // 0x800804E8

extern int MON_ChooseLeftOrRight(struct _Instance *instance, struct _MonsterIR *enemy); // 0x80080594

extern int MON_ChooseEvadeMove(struct _Instance *instance); // 0x80080638

extern int MON_ChooseCombatMove(struct _Instance *instance, int reason); // 0x80080694

extern void MON_PlayRandomIdle(struct _Instance *instance, int mode); // 0x80080ADC

extern void MON_PlayCombatIdle(struct _Instance *instance, int mode); // 0x80080C80

extern void MON_GetRandomPoint(struct _Position *out, struct _Position *in, short r); // 0x80080CC0

extern int MON_GetRandomDestinationInWorld(struct _Instance *instance, struct _Position *in, short r); // 0x80080D6C

extern void MON_MoveForward(struct _Instance *instance); // 0x80080F54

extern int MON_TurnToPosition(struct _Instance *instance, struct _Position *position, short turnspeed); // 0x80080FA4

extern void MON_MoveToPosition(struct _Instance *instance, struct _Position *position, short turnSpeed); // 0x80081014

extern int MON_OnGround(struct _Instance *instance); // 0x80081058

extern void MON_ApplyPhysics(struct _Instance *instance); // 0x80081148

extern void MON_ChangeBehavior(struct _Instance *instance, int behavior); // 0x8008116C

extern void MON_CheckEnvironment(struct _Instance *instance); // 0x800811F4

extern void MON_CheckTerrainAndRespond(struct _Instance *instance, struct BSPTree *bsp, struct _TFace *tface); // 0x80081628

extern unsigned long MON_CheckTerrain(struct _Instance *instance, struct BSPTree *bsp, struct _TFace *tface); // 0x800816AC

extern int MON_CheckPointSuitability(struct _Instance *instance, struct _Position *origin, struct _Position *destination); // 0x8008176C

extern unsigned long MON_GetTime(struct _Instance *instance); // 0x80081844

extern void MON_BirthSoul(struct _Instance *instance, int link); // 0x80081898

extern void MON_ProcessIntro(struct _Instance *instance); // 0x800819FC

extern void MON_SetDefaults(struct _Instance *instance); // 0x80081F28

extern void MON_GetPlanSlot(struct _MonsterVars *mv); // 0x80082128

extern int MON_DefaultPlanMovement(struct _Instance *instance, int anim, long distance); // 0x8008216C

extern void MON_DropAllObjects(struct _Instance *instance); // 0x8008240C

extern void MON_EnableHeadMove(struct _Instance *instance); // 0x8008247C

extern void MON_DisableHeadMove(struct _Instance *instance); // 0x80082524

extern void MON_LookInDirection(struct _Instance *instance, short tx, short tz); // 0x800825B0

extern void MON_LookAtPos(struct _Instance *instance, struct _Position *position); // 0x80082724

extern void MON_ProcessLookAt(struct _Instance *instance); // 0x80082800

extern int MON_TakeDamage(struct _Instance *instance, int damage, int type); // 0x800828F4

extern void MON_SetUpSaveInfo(struct _Instance *instance, struct _MonsterSaveInfo *saveData); // 0x800829A0

extern void MON_GetSaveInfo(struct _Instance *instance, struct _MonsterSaveInfo *saveData); // 0x80082B0C

extern void MON_KillMonster(struct _Instance *instance); // 0x80082D50

extern int MON_ShouldIAmbushEnemy(struct _Instance *instance); // 0x80082F28

extern int MON_ShouldIFireAtTarget(struct _Instance *instance, struct _MonsterIR *target); // 0x80083094

extern int MON_ShouldIFlee(struct _Instance *instance); // 0x80083184

extern void MON_RelocateCoords(struct _Instance *instance, struct _SVector *offset); // 0x80083284

extern int MON_ValidUnit(struct _Instance *instance, unsigned long unitId); // 0x80083310

extern int MON_ValidPosition(struct _Instance *instance); // 0x8008335C

extern void MON_SphereWorldPos(struct MATRIX *mat, struct _HSphere *sphere, struct _Position *ret); // 0x800833B4

extern struct _HPrim *MON_FindSphereForTerrain(struct _Instance *instance); // 0x80083424

extern struct Intro *MON_FindNearestImpalingIntro(int unitID, struct _Position *position); // 0x800834B0

extern struct Intro *MON_TestForTerrainImpale(struct _Instance *instance, struct _Terrain *terrain); // 0x800835E0

extern void MON_MoveInstanceToImpalePoint(struct _Instance *instance); // 0x800836DC

extern int MON_ReachableIntro(struct _Instance *instance, struct _Position *pos, struct _Position *introPos, struct _Rotation *introRot, int checkOrientation); // 0x800837C0

extern int MON_SetVelocityTowardsImpalingObject(struct _Instance *instance, int checkOrientation); // 0x80083BAC

extern void MON_TurnOffSphereCollisions(struct _Instance *instance); // 0x80083D20

extern void MON_TurnOnSphereCollisions(struct _Instance *instance); // 0x80083D7C

extern void MON_ProcessSpecialFade(struct _Instance *instance); // 0x80083DD8

extern void MON_StartSpecialFade(struct _Instance *instance, int fadeLevel, int fadeTime); // 0x80084014

extern void MON_UnlinkFromRaziel(struct _Instance *instance); // 0x8008407C

extern void MON_BurnInAir(struct _Instance *instance, int currentState); // 0x8008411C

extern void MON_BirthMana(struct _Instance *instance); // 0x800841D8

extern void MON_SoulSucked(struct _Instance *instance); // 0x80084290

extern int MON_SetUpKnockBack(struct _Instance *instance, struct _Instance *enemy, struct evMonsterHitData *data); // 0x80084308

extern void MON_DoDrainEffects(struct _Instance *instance, struct _Instance *ei); // 0x8008440C

extern void MON_SetFXHitData(struct _Instance *instance, struct evFXHitData *data, int type, int amount); // 0x80084698

extern void MON_LaunchMonster(struct _Instance *instance, int zDirection, int power, int loft); // 0x80084724

#endif
