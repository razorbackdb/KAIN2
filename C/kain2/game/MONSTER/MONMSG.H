#ifndef MONMSG_H
#define MONMSG_H

struct MONMSG_73fake // hashcode: 0x8CEFA038 (dec: -1930452936)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xEC653C59 (dec: -328909735), parent name: 'MONMSG_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x496BC441 (dec: 1231799361), parent name: 'MONMSG_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_74fake // hashcode: 0xDDE913C1 (dec: -571927615)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xA0BF7679 (dec: -1598065031), parent name: 'MONMSG_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xC2B87DAB (dec: -1028096597), parent name: 'MONMSG_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_75fake // hashcode: 0xF699F8AE (dec: -157681490)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xBA430A76 (dec: -1170011530), parent name: 'MONMSG_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xACCC71E7 (dec: -1395887641), parent name: 'MONMSG_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONMSG_76fake // Hashcode: 0xE9C1A94D (dec: -373184179)
{
	struct MONMSG_73fake callback; // size=8, offset=0
	struct MONMSG_74fake vector;   // size=12, offset=0
	struct MONMSG_75fake quat;	 // size=16, offset=0
};

union MONMSG_77fake // Hashcode: 0x1D317893 (dec: 489781395)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MONMSG_78fake // Hashcode: 0x8F7092C6 (dec: -1888447802)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct MONMSG_79fake // hashcode: 0x6973763A (dec: 1769174586)
{
	union MONMSG_78fake size; // size=4, offset=0 //  hashcode: 0x7CCAFFD0 (dec: 2093678544), parent name: 'MONMSG_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_80fake // hashcode: 0x647E370E (dec: 1685993230)
{
	short x;				// size=0, offset=0 //  hashcode: 0x078C8035 (dec: 126648373), parent name: 'MONMSG_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xB30B1712 (dec: -1291118830), parent name: 'MONMSG_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x61FE9784 (dec: 1644074884), parent name: 'MONMSG_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x5F3F6FE2 (dec: 1597992930), parent name: 'MONMSG_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xE7CFA2CA (dec: -405822774), parent name: 'MONMSG_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_81fake // hashcode: 0x3F7FF3B9 (dec: 1065350073)
{
	long index; // size=0, offset=0 //  hashcode: 0xBACA7B06 (dec: -1161135354), parent name: 'MONMSG_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xCA1ADF01 (dec: -904208639), parent name: 'MONMSG_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_82fake // hashcode: 0x9E6FD68C (dec: -1636837748)
{
	long index; // size=0, offset=0 //  hashcode: 0x98E7BE5B (dec: -1729642917), parent name: 'MONMSG_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xDBD4A6D4 (dec: -606820652), parent name: 'MONMSG_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_83fake // hashcode: 0x459EAFC6 (dec: 1168027590)
{
	long index; // size=0, offset=0 //  hashcode: 0x4ECDB099 (dec: 1322102937), parent name: 'MONMSG_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x63D08619 (dec: 1674610201), parent name: 'MONMSG_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_84fake // hashcode: 0xF79BAF93 (dec: -140791917)
{
	long time;  // size=0, offset=0 //  hashcode: 0xB6694DFC (dec: -1234612740), parent name: 'MONMSG_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x82796519 (dec: -2105973479), parent name: 'MONMSG_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_85fake // hashcode: 0x7DACA89E (dec: 2108467358)
{
	long action;   // size=0, offset=0 //  hashcode: 0xFD146960 (dec: -48993952), parent name: 'MONMSG_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xBE65A9D1 (dec: -1100633647), parent name: 'MONMSG_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_86fake // hashcode: 0x19D9D3F6 (dec: 433705974)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x8C89141E (dec: -1937173474), parent name: 'MONMSG_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x4B611EA5 (dec: 1264656037), parent name: 'MONMSG_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_87fake // hashcode: 0xD998C626 (dec: -644299226)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xF27C8BBC (dec: -226718788), parent name: 'MONMSG_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x26EB14ED (dec: 652940525), parent name: 'MONMSG_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_88fake // hashcode: 0x23A2F0F1 (dec: 597881073)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x99D7B2B2 (dec: -1713917262), parent name: 'MONMSG_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xA75841BB (dec: -1487388229), parent name: 'MONMSG_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_89fake // hashcode: 0x03BAEB79 (dec: 62581625)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xF0DA9105 (dec: -254111483), parent name: 'MONMSG_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x6CBD8405 (dec: 1824359429), parent name: 'MONMSG_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x94038B5C (dec: -1811707044), parent name: 'MONMSG_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x74F02869 (dec: 1961896041), parent name: 'MONMSG_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xC357ED10 (dec: -1017647856), parent name: 'MONMSG_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_90fake // hashcode: 0x63354594 (dec: 1664435604)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x6E68A8C2 (dec: 1852352706), parent name: 'MONMSG_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x1BD72CD3 (dec: 467086547), parent name: 'MONMSG_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_91fake // hashcode: 0x0097966F (dec: 9934447)
{
	short index;					// size=0, offset=0 //  hashcode: 0x9D0E92BB (dec: -1659989317), parent name: 'MONMSG_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xD04A4255 (dec: -800439723), parent name: 'MONMSG_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x3B1B80F3 (dec: 991658227), parent name: 'MONMSG_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xFE33D8C2 (dec: -30156606), parent name: 'MONMSG_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_92fake // hashcode: 0x691A51B2 (dec: 1763332530)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x4C07F26C (dec: 1275589228), parent name: 'MONMSG_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x2E48B0A8 (dec: 776515752), parent name: 'MONMSG_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x82A7207C (dec: -2102976388), parent name: 'MONMSG_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_93fake // hashcode: 0x4B075C1A (dec: 1258773530)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xB707AAAF (dec: -1224234321), parent name: 'MONMSG_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x075145F0 (dec: 122766832), parent name: 'MONMSG_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x7072A95F (dec: 1886562655), parent name: 'MONMSG_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xC2E6B67F (dec: -1025067393), parent name: 'MONMSG_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xB3AB0764 (dec: -1280637084), parent name: 'MONMSG_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xD572AE2B (dec: -713904597), parent name: 'MONMSG_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x62A902A7 (dec: 1655243431), parent name: 'MONMSG_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_94fake // hashcode: 0xF809EF40 (dec: -133566656)
{
	long index;  // size=0, offset=0 //  hashcode: 0x54834F01 (dec: 1417891585), parent name: 'MONMSG_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x772E062B (dec: 1999504939), parent name: 'MONMSG_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_95fake // hashcode: 0xB28ED7B4 (dec: -1299261516)
{
	short type; // size=0, offset=0 //  hashcode: 0x82D8F63E (dec: -2099710402), parent name: 'MONMSG_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xA77A6F65 (dec: -1485148315), parent name: 'MONMSG_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_96fake // hashcode: 0x73CF9953 (dec: 1942985043)
{
	long time;   // size=0, offset=0 //  hashcode: 0x20C20FB3 (dec: 549588915), parent name: 'MONMSG_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xF37E4944 (dec: -209827516), parent name: 'MONMSG_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_97fake // hashcode: 0x9212440A (dec: -1844296694)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x1673ACD1 (dec: 376679633), parent name: 'MONMSG_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x28235212 (dec: 673403410), parent name: 'MONMSG_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_98fake // hashcode: 0x6CFC9B1A (dec: 1828494106)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x033B0ECC (dec: 54202060), parent name: 'MONMSG_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x02E3DD27 (dec: 48487719), parent name: 'MONMSG_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_99fake // hashcode: 0x278B38DF (dec: 663435487)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x8BEDD561 (dec: -1947347615), parent name: 'MONMSG_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x9F186699 (dec: -1625790823), parent name: 'MONMSG_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_100fake // hashcode: 0x657238F3 (dec: 1701984499)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x56B4075C (dec: 1454638940), parent name: 'MONMSG_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xE8452E87 (dec: -398119289), parent name: 'MONMSG_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x996BFF58 (dec: -1720975528), parent name: 'MONMSG_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x87DB0CF4 (dec: -2015687436), parent name: 'MONMSG_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_101fake // hashcode: 0x8CB5C82C (dec: -1934243796)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x1572D6F9 (dec: 359847673), parent name: 'MONMSG_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x4502C79E (dec: 1157810078), parent name: 'MONMSG_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x409A42EB (dec: 1083851499), parent name: 'MONMSG_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xBF6D6E50 (dec: -1083347376), parent name: 'MONMSG_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xCA535FB0 (dec: -900505680), parent name: 'MONMSG_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONMSG_102fake // Hashcode: 0xCF4810C8 (dec: -817360696)
{
	struct MONMSG_79fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	  // size=24, offset=0
	struct MONMSG_80fake teleport;	 // size=16, offset=0
	struct MONMSG_81fake cameraValue;  // size=8, offset=0
	struct MONMSG_82fake miscValue;	// size=8, offset=0
	struct MONMSG_83fake logicValue;   // size=8, offset=0
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
	struct MONMSG_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				   // size=0, offset=0
	long cameraRestore;				   // size=0, offset=0
	struct _BGObject *bgObject;		   // size=24, offset=0
	long value[2];					   // size=8, offset=0
	struct MONMSG_85fake sound;		   // size=12, offset=0
	void *intro;					   // size=0, offset=0
	long deathZ;					   // size=0, offset=0
	struct MONMSG_86fake dsignal;	  // size=8, offset=0
	void *mirror;					   // size=0, offset=0
	long fogNear;					   // size=0, offset=0
	long fogFar;					   // size=0, offset=0
	struct MONMSG_87fake gotoFrame;	// size=8, offset=0
	struct MONMSG_88fake changeModel;  // size=8, offset=0
	void *vmObject;					   // size=0, offset=0
	struct MONMSG_89fake logic;		   // size=8, offset=0
	void *callSignal;				   // size=0, offset=0
	struct _SVector offset;			   // size=8, offset=0
	struct Signal *gotoLabel;		   // size=0, offset=0
	struct Signal *gosubLabel;		   // size=0, offset=0
	struct MONMSG_90fake control;	  // size=8, offset=0
	struct MONMSG_91fake zSignal;	  // size=12, offset=0
	struct MONMSG_92fake StreamLevel;  // size=24, offset=0
	struct MONMSG_93fake shards;	   // size=12, offset=0
	struct MONMSG_94fake cameraSpline; // size=8, offset=0
	struct MONMSG_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				   // size=0, offset=0
	struct MONMSG_96fake introFX;	  // size=8, offset=0
	struct MONMSG_97fake introActive;  // size=8, offset=0
	struct MONMSG_98fake levelChange;  // size=18, offset=0
	long blendStart;				   // size=0, offset=0
	struct MONMSG_99fake setTimes;	 // size=8, offset=0
	struct MONMSG_100fake color;	   // size=4, offset=0
	struct MONMSG_101fake print;	   // size=12, offset=0
	long slideAngle;				   // size=0, offset=0
};

union MONMSG_103fake // Hashcode: 0x1A7CB30A (dec: 444379914)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union MONMSG_108fake // Hashcode: 0xB8785079 (dec: -1200074631)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct MONMSG_110fake // hashcode: 0xE0DBF246 (dec: -522456506)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xAAF4DCD0 (dec: -1426793264), parent name: 'MONMSG_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xCD55D550 (dec: -850012848), parent name: 'MONMSG_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x202A6D7A (dec: 539651450), parent name: 'MONMSG_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x2D99981F (dec: 765040671), parent name: 'MONMSG_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0xCC48C7C4 (dec: -867645500), parent name: 'MONMSG_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x4D7AA204 (dec: 1299882500), parent name: 'MONMSG_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xCB676F84 (dec: -882413692), parent name: 'MONMSG_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_111fake // hashcode: 0x5F2D548D (dec: 1596806285)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x289F0F47 (dec: 681512775), parent name: 'MONMSG_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x870B8F3E (dec: -2029285570), parent name: 'MONMSG_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x1CD8798A (dec: 483948938), parent name: 'MONMSG_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_112fake // hashcode: 0x3C243C8A (dec: 1009007754)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xC83553F1 (dec: -936029199), parent name: 'MONMSG_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x0D7FD1BF (dec: 226480575), parent name: 'MONMSG_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xFB12AF00 (dec: -82661632), parent name: 'MONMSG_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x379BAD25 (dec: 932949285), parent name: 'MONMSG_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x14392248 (dec: 339288648), parent name: 'MONMSG_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_113fake // hashcode: 0x144622BE (dec: 340140734)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x79BFC2A5 (dec: 2042610341), parent name: 'MONMSG_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x9E530ED0 (dec: -1638723888), parent name: 'MONMSG_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x888D5128 (dec: -2004004568), parent name: 'MONMSG_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xFE5D3025 (dec: -27447259), parent name: 'MONMSG_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x11F99FBF (dec: 301572031), parent name: 'MONMSG_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MONMSG_114fake // hashcode: 0x79F33A82 (dec: 2045983362)
{
	struct MONMSG_110fake Cinematic; // size=28, offset=0 //  hashcode: 0xFB844D8F (dec: -75215473), parent name: 'MONMSG_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MONMSG_111fake Idle;		 // size=20, offset=28 //  hashcode: 0x946E9670 (dec: -1804691856), parent name: 'MONMSG_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MONMSG_112fake Behind;	// size=28, offset=48 //  hashcode: 0xE513E400 (dec: -451681280), parent name: 'MONMSG_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MONMSG_113fake Follow;	// size=20, offset=76 //  hashcode: 0x88ABC1DD (dec: -2002009635), parent name: 'MONMSG_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MONMSG_196fake // Hashcode: 0x160BF936 (dec: 369883446)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct _MonsterAttributes // hashcode: 0x9EE88812 (dec: -1628927982)
{
	unsigned long magicnum;									// size=0, offset=0 //  hashcode: 0xC4E96AE4 (dec: -991335708), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *tunData;											// size=0, offset=4 //  hashcode: 0xDBEF3B8B (dec: -605078645), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *auxAnimList;										// size=0, offset=8 //  hashcode: 0xE1E0DD2A (dec: -505357014), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *ambientAnimList;									// size=0, offset=12 //  hashcode: 0x26CA08A4 (dec: 650774692), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	long whatAmI;											// size=0, offset=16 //  hashcode: 0x30C0439D (dec: 817906589), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numAuxAnims;										// size=0, offset=20 //  hashcode: 0x7CC394DC (dec: 2093192412), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numAmbientAnims;									// size=0, offset=21 //  hashcode: 0x4DE37AF1 (dec: 1306753777), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char defaultAge;								// size=0, offset=22 //  hashcode: 0x5B157D23 (dec: 1528134947), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pupateObject;										// size=0, offset=23 //  hashcode: 0xCAC4E5B8 (dec: -893065800), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char damageFXSegment;							// size=0, offset=24 //  hashcode: 0x2565BDF6 (dec: 627424758), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char headSegment;								// size=0, offset=25 //  hashcode: 0xF2F283D3 (dec: -218987565), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char neckSegment;								// size=0, offset=26 //  hashcode: 0xE284B47F (dec: -494619521), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char leftShoulderSegment;						// size=0, offset=27 //  hashcode: 0x5D689B63 (dec: 1567136611), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char rightShoulderSegment;						// size=0, offset=28 //  hashcode: 0x0E7566DF (dec: 242575071), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char waistSegment;								// size=0, offset=29 //  hashcode: 0x4CB8B2E6 (dec: 1287172838), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char leftKneeSegment;							// size=0, offset=30 //  hashcode: 0x336F27CE (dec: 862922702), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char rightKneeSegment;							// size=0, offset=31 //  hashcode: 0x9ECD5B71 (dec: -1630708879), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char leftFootSegment;							// size=0, offset=32 //  hashcode: 0x4411323F (dec: 1141977663), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char rightFootSegment;							// size=0, offset=33 //  hashcode: 0x0BA0DBE9 (dec: 195091433), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char spineSegment;								// size=0, offset=34 //  hashcode: 0x9B461EB5 (dec: -1689903435), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char leftWeaponSegment;						// size=0, offset=35 //  hashcode: 0xD144BA1A (dec: -784025062), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char rightWeaponSegment;						// size=0, offset=36 //  hashcode: 0xFE53DB50 (dec: -28058800), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char grabSegment;								// size=0, offset=37 //  hashcode: 0x08EF3ABA (dec: 149895866), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char bloodImpaleFrame;							// size=0, offset=38 //  hashcode: 0x8BE5AD48 (dec: -1947882168), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char bloodConeFrame;							// size=0, offset=39 //  hashcode: 0xC1689517 (dec: -1050110697), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numSubAttributes;									// size=0, offset=40 //  hashcode: 0x4351C6AB (dec: 1129432747), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numCombatAttributes;								// size=0, offset=41 //  hashcode: 0xB48F407E (dec: -1265680258), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numAttackAttributes;								// size=0, offset=42 //  hashcode: 0xE9A32073 (dec: -375185293), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numMissiles;										// size=0, offset=43 //  hashcode: 0xD4FF4294 (dec: -721468780), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numAnims;											// size=0, offset=44 //  hashcode: 0x356455CB (dec: 895768011), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numIdles;											// size=0, offset=45 //  hashcode: 0xE2B5AD87 (dec: -491410041), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numBehaviors;										// size=0, offset=46 //  hashcode: 0x6290709C (dec: 1653633180), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numShatters;										// size=0, offset=47 //  hashcode: 0xDC22804F (dec: -601718705), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterSubAttributes **subAttributesList;		// size=84, offset=48 //  hashcode: 0x4FD3C7CB (dec: 1339279307), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterCombatAttributes **combatAttributesList; // size=46, offset=52 //  hashcode: 0xF19FDF39 (dec: -241180871), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterAttackAttributes *attackAttributesList;  // size=32, offset=56 //  hashcode: 0xC1CB683D (dec: -1043634115), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterMissile *missileList;					// size=16, offset=60 //  hashcode: 0x84BAFE81 (dec: -2068119935), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterAnim *animList;							// size=16, offset=64 //  hashcode: 0x6629C28F (dec: 1714012815), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterIdle *idleList;							// size=4, offset=68 //  hashcode: 0x8D836C14 (dec: -1920766956), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterBehavior *behaviorList;					// size=8, offset=72 //  hashcode: 0xB38FEB92 (dec: -1282413678), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *shatterList;										// size=0, offset=76 //  hashcode: 0x49CC490B (dec: 1238124811), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterVars // hashcode: 0xEF80566F (dec: -276801937)
{
	unsigned long mvFlags;						 // size=0, offset=0 //  hashcode: 0x768E425C (dec: 1989034588), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long auxFlags;						 // size=0, offset=4 //  hashcode: 0xC8C91E15 (dec: -926343659), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __MessageQueue messageQueue;			 // size=136, offset=8 //  hashcode: 0x28863516 (dec: 679884054), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterIR *monsterIRList;			 // size=0, offset=144 //  hashcode: 0x598DE9CC (dec: 1502472652), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimInterpInfo_Type interpInfo[3]; // size=36, offset=148 //  hashcode: 0x7C0E4EB1 (dec: 2081312433), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterAttackAttributes *attackType; // size=32, offset=184 //  hashcode: 0xC0D8BCA8 (dec: -1059537752), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterAnim *anim;					 // size=16, offset=188 //  hashcode: 0x2773D794 (dec: 661903252), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *messageData;							 // size=0, offset=192 //  hashcode: 0xEC9E5567 (dec: -325167769), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterIR *enemy;					 // size=0, offset=196 //  hashcode: 0x3BB0EF54 (dec: 1001451348), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterIR *leader;					 // size=0, offset=200 //  hashcode: 0x1F24599E (dec: 522475934), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterIR *ally;					 // size=0, offset=204 //  hashcode: 0x2C60F583 (dec: 744551811), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *held;						 // size=616, offset=208 //  hashcode: 0xFD283D82 (dec: -47694462), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	long heldID;								 // size=0, offset=212 //  hashcode: 0x355E078F (dec: 895354767), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	long soulID;								 // size=0, offset=216 //  hashcode: 0xF946456F (dec: -112835217), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *effect;								 // size=0, offset=220 //  hashcode: 0x275336C8 (dec: 659764936), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short radarMap;					 // size=0, offset=224 //  hashcode: 0x7D4F2A89 (dec: 2102340233), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short radarCounter;				 // size=0, offset=226 //  hashcode: 0xCE1B227B (dec: -837082501), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short radarDistance[8];						 // size=16, offset=228 //  hashcode: 0x392F9569 (dec: 959419753), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long mode;							 // size=0, offset=244 //  hashcode: 0x32BC55DE (dec: 851203550), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long damageTimer;					 // size=0, offset=248 //  hashcode: 0x509A9B1B (dec: 1352309531), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long stunTimer;					 // size=0, offset=252 //  hashcode: 0xB51D27D5 (dec: -1256380459), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long generalTimer;					 // size=0, offset=256 //  hashcode: 0x47223912 (dec: 1193425170), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long generalTimer2;				 // size=0, offset=260 //  hashcode: 0x71DA2A3B (dec: 1910123067), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long effectTimer;					 // size=0, offset=264 //  hashcode: 0x03BB6E79 (dec: 62615161), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position *lookAtPos;				 // size=6, offset=268 //  hashcode: 0x8BE898D2 (dec: -1947690798), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short speed;								 // size=0, offset=272 //  hashcode: 0xF18FB0BC (dec: -242241348), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position destination;				 // size=6, offset=274 //  hashcode: 0xDF88008D (dec: -544735091), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fleeMarker;							 // size=0, offset=280 //  hashcode: 0x62D77D7F (dec: 1658289535), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position lastValidPos;				 // size=6, offset=282 //  hashcode: 0xF3A77350 (dec: -207129776), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short wanderRange;							 // size=0, offset=288 //  hashcode: 0xA098DAD8 (dec: -1600595240), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position lookAtPosData;				 // size=6, offset=290 //  hashcode: 0x094FC815 (dec: 156223509), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short guardRange;							 // size=0, offset=296 //  hashcode: 0xED2DB5CF (dec: -315771441), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ambushRange;							 // size=0, offset=298 //  hashcode: 0x6237C7C7 (dec: 1647822791), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ambushArc;							 // size=0, offset=300 //  hashcode: 0xB7BDC572 (dec: -1212299918), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ambushElevation;						 // size=0, offset=302 //  hashcode: 0x42EDBDFD (dec: 1122876925), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short hitPoints;							 // size=0, offset=304 //  hashcode: 0xD6A3DA6A (dec: -693904790), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxHitPoints;							 // size=0, offset=306 //  hashcode: 0x49687BF0 (dec: 1231584240), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soulJuice;							 // size=0, offset=308 //  hashcode: 0x56A74C32 (dec: 1453804594), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short regenTime;							 // size=0, offset=310 //  hashcode: 0x8DE26D84 (dec: -1914540668), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short mainColorVertex;						 // size=0, offset=312 //  hashcode: 0x37160066 (dec: 924188774), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lookAngleX;							 // size=0, offset=314 //  hashcode: 0xBACAC2E0 (dec: -1161116960), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lookAngleZ;							 // size=0, offset=316 //  hashcode: 0xD5B5DB53 (dec: -709502125), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short avoidMask;					 // size=0, offset=318 //  hashcode: 0x15A8504C (dec: 363352140), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short damageType;					 // size=0, offset=320 //  hashcode: 0x649FBCDE (dec: 1688190174), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char ambushMarker;							 // size=0, offset=322 //  hashcode: 0x8C3C9150 (dec: -1942187696), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char ambushJumpType;						 // size=0, offset=323 //  hashcode: 0x65C08AAB (dec: 1707117227), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char causeOfDeath;					 // size=0, offset=324 //  hashcode: 0xBB8CAC82 (dec: -1148408702), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char previousMainState;						 // size=0, offset=325 //  hashcode: 0x279A4FC0 (dec: 664424384), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char behaviorState;				 // size=0, offset=326 //  hashcode: 0xACC9242B (dec: -1396104149), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char initialBehavior;				 // size=0, offset=327 //  hashcode: 0x35828FC0 (dec: 897748928), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char triggeredBehavior;			 // size=0, offset=328 //  hashcode: 0xD31FF778 (dec: -752879752), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char activeBehavior;						 // size=0, offset=329 //  hashcode: 0x2735B770 (dec: 657831792), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char age;							 // size=0, offset=330 //  hashcode: 0xD838ACED (dec: -667374355), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char attackState;							 // size=0, offset=331 //  hashcode: 0xE635CAA3 (dec: -432682333), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char ambient;						 // size=0, offset=332 //  hashcode: 0x5BF2322A (dec: 1542599210), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char alertness;								 // size=0, offset=333 //  hashcode: 0x420D0F73 (dec: 1108152179), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char alertCount;							 // size=0, offset=334 //  hashcode: 0x9CD90F92 (dec: -1663496302), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char senseIndex;							 // size=0, offset=335 //  hashcode: 0x8B1E4B9E (dec: -1960948834), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char lastSideMove;							 // size=0, offset=336 //  hashcode: 0xB6F47FA4 (dec: -1225490524), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char chance;								 // size=0, offset=337 //  hashcode: 0x6D2778C4 (dec: 1831303364), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pathSlotID;							 // size=0, offset=338 //  hashcode: 0x744D9D31 (dec: 1951243569), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterSubAttributes *subAttr;		 // size=84, offset=340 //  hashcode: 0xA85C2D8E (dec: -1470354034), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterIR *freeIRs;					 // size=0, offset=344 //  hashcode: 0xABADEAB6 (dec: -1414665546), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *extraVars;							 // size=0, offset=348 //  hashcode: 0x4D5AB265 (dec: 1297789541), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short validUnits[10];						 // size=20, offset=352 //  hashcode: 0xD5CC575A (dec: -708028582), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short patrolMarkers[12];					 // size=24, offset=372 //  hashcode: 0x1C351963 (dec: 473241955), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *currentMarker;						 // size=0, offset=396 //  hashcode: 0xC520AC5D (dec: -987714467), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	long terrainImpaleID;						 // size=0, offset=400 //  hashcode: 0xFA9EBB2E (dec: -90260690), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short targetFade;							 // size=0, offset=404 //  hashcode: 0x32F3EDF4 (dec: 854846964), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadeRate;								 // size=0, offset=406 //  hashcode: 0x4766E253 (dec: 1197924947), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterIR // hashcode: 0x41A7CD43 (dec: 1101516099)
{
	struct _MonsterIR *next;		  // size=36, offset=0 //  hashcode: 0xD2C1DC42 (dec: -759047102), parent name: '_MonsterIR', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance;		  // size=616, offset=4 //  hashcode: 0xB02F0157 (dec: -1339096745), parent name: '_MonsterIR', parent hashcode: 0xFFFFFFFF (dec: -1)
	long handle;					  // size=0, offset=8 //  hashcode: 0xE50F67BF (dec: -451975233), parent name: '_MonsterIR', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector relativePosition; // size=8, offset=12 //  hashcode: 0x6A80DE42 (dec: 1786830402), parent name: '_MonsterIR', parent hashcode: 0xFFFFFFFF (dec: -1)
	short distance;					  // size=0, offset=20 //  hashcode: 0x98B0C3D3 (dec: -1733245997), parent name: '_MonsterIR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short mirFlags;		  // size=0, offset=22 //  hashcode: 0xC5929E47 (dec: -980246969), parent name: '_MonsterIR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short mirConditions;	 // size=0, offset=24 //  hashcode: 0x52BD2D80 (dec: 1388129664), parent name: '_MonsterIR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long forgetTimer;		  // size=0, offset=28 //  hashcode: 0x2EAB73D8 (dec: 782988248), parent name: '_MonsterIR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long idleTime;			  // size=0, offset=32 //  hashcode: 0xFBBB8526 (dec: -71596762), parent name: '_MonsterIR', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct burntTuneType // hashcode: 0x127E6332 (dec: 310272818)
{
	int burntDist; // size=0, offset=0 //  hashcode: 0xA116CDEA (dec: -1592341014), parent name: 'burntTuneType', parent hashcode: 0xFFFFFFFF (dec: -1)
	int fadeDelta; // size=0, offset=4 //  hashcode: 0xE89F35CC (dec: -392219188), parent name: 'burntTuneType', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterState // hashcode: 0x1B0172BB (dec: 453079739)
{
	void (*entryFunction)(); // size=0, offset=0 //  hashcode: 0x7172E8B7 (dec: 1903356087), parent name: '_MonsterState', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*stateFunction)(); // size=0, offset=4 //  hashcode: 0xF5BF6441 (dec: -172006335), parent name: '_MonsterState', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterStateChoice // hashcode: 0xE0AABD5C (dec: -525681316)
{
	int state;						// size=0, offset=0 //  hashcode: 0x0ECAC460 (dec: 248169568), parent name: '_MonsterStateChoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterState functions; // size=8, offset=4 //  hashcode: 0x5C21CE6E (dec: 1545719406), parent name: '_MonsterStateChoice', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct _MonsterAttributes MonsterAttributes;

typedef struct _MonsterVars MonsterVars;

typedef struct _MonsterIR MonsterIR;

typedef struct burntTuneType burntTuneType;

typedef struct _MonsterState MonsterState;

typedef struct _MonsterStateChoice MonsterStateChoice;

typedef void (*MonsterFunc)();

typedef void (*MonsterDamageFunc)();

extern int MON_GroundMoveQueueHandler(struct _Instance *instance); // 0x800847B8

extern void MON_PupateMessageHandler(struct _Instance *instance, struct __Event *message); // 0x80084840

extern void MON_IdleMessageHandler(struct _Instance *instance, struct __Event *message); // 0x80084A84

extern void MON_DefaultMessageHandler(struct _Instance *instance, struct __Event *message); // 0x80084BC8

extern void MON_PupateQueueHandler(struct _Instance *instance); // 0x800859C0

extern void MON_IdleQueueHandler(struct _Instance *instance); // 0x80085A0C

extern void MON_DefaultQueueHandler(struct _Instance *instance); // 0x80085A58

#endif
