#ifndef PLANAPI_H
#define PLANAPI_H

extern struct PoolManagementData *poolManagementData; // offset 0x800D51D0

static struct PoolManagementData poolManagementDataStorage; // offset 0x800D5184

static long timerArray[10]; // offset 0x800D51A4

static long timerIndex; // offset 0x800D51CC

struct PLANAPI_110fake // hashcode: 0x76A5A5DE (dec: 1990567390)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xC7A3659C (dec: -945592932), parent name: 'PLANAPI_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0xFEC0CF6C (dec: -20918420), parent name: 'PLANAPI_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_111fake // hashcode: 0x0EE9FAC4 (dec: 250215108)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x324EF5BF (dec: 844035519), parent name: 'PLANAPI_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x8CEE5E3E (dec: -1930535362), parent name: 'PLANAPI_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_112fake // hashcode: 0xC53FA924 (dec: -985683676)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xA2931C4F (dec: -1567417265), parent name: 'PLANAPI_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x7340284D (dec: 1933584461), parent name: 'PLANAPI_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLANAPI_113fake // Hashcode: 0xC8F8AFA3 (dec: -923226205)
{
	struct PLANAPI_110fake callback; // size=8, offset=0
	struct PLANAPI_111fake vector;   // size=12, offset=0
	struct PLANAPI_112fake quat;	 // size=16, offset=0
};

union PLANAPI_114fake // Hashcode: 0xCACF262B (dec: -892393941)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PLANAPI_115fake // Hashcode: 0x0BEC5C1E (dec: 200039454)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct PLANAPI_116fake // hashcode: 0x9EDE23B4 (dec: -1629609036)
{
	union PLANAPI_115fake size; // size=4, offset=0 //  hashcode: 0x38EB3398 (dec: 954938264), parent name: 'PLANAPI_116fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_117fake // hashcode: 0x2EFC9C14 (dec: 788306964)
{
	short x;				// size=0, offset=0 //  hashcode: 0xEC38BE47 (dec: -331825593), parent name: 'PLANAPI_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x0B6F6748 (dec: 191850312), parent name: 'PLANAPI_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x386F22BD (dec: 946807485), parent name: 'PLANAPI_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x012BB5AB (dec: 19641771), parent name: 'PLANAPI_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x293813B1 (dec: 691540913), parent name: 'PLANAPI_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_118fake // hashcode: 0x078B3733 (dec: 126564147)
{
	long index; // size=0, offset=0 //  hashcode: 0xEB153B51 (dec: -350930095), parent name: 'PLANAPI_118fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xE4AA8580 (dec: -458586752), parent name: 'PLANAPI_118fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_119fake // hashcode: 0x76DC86EF (dec: 1994163951)
{
	long index; // size=0, offset=0 //  hashcode: 0xFBE060B1 (dec: -69181263), parent name: 'PLANAPI_119fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x00CCBC97 (dec: 13417623), parent name: 'PLANAPI_119fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_120fake // hashcode: 0x20285A67 (dec: 539515495)
{
	long index; // size=0, offset=0 //  hashcode: 0x9D55BD52 (dec: -1655325358), parent name: 'PLANAPI_120fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xEF26A101 (dec: -282681087), parent name: 'PLANAPI_120fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_121fake // hashcode: 0x36A81670 (dec: 916985456)
{
	long time;  // size=0, offset=0 //  hashcode: 0xAD6FA5FB (dec: -1385191941), parent name: 'PLANAPI_121fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x3C7413B0 (dec: 1014240176), parent name: 'PLANAPI_121fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_122fake // hashcode: 0x35E5D611 (dec: 904254993)
{
	long action;   // size=0, offset=0 //  hashcode: 0xA8B64EA8 (dec: -1464447320), parent name: 'PLANAPI_122fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x4A229D05 (dec: 1243782405), parent name: 'PLANAPI_122fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_123fake // hashcode: 0x316ED38F (dec: 829346703)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x7BB4AFBC (dec: 2075439036), parent name: 'PLANAPI_123fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xD1B72488 (dec: -776526712), parent name: 'PLANAPI_123fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_124fake // hashcode: 0x6728EBCF (dec: 1730735055)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x473CC7FD (dec: 1195165693), parent name: 'PLANAPI_124fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0xA72872E4 (dec: -1490521372), parent name: 'PLANAPI_124fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_125fake // hashcode: 0x528F681F (dec: 1385130015)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x86C8B0C7 (dec: -2033667897), parent name: 'PLANAPI_125fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xB195DC2D (dec: -1315578835), parent name: 'PLANAPI_125fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_126fake // hashcode: 0xFB5FB04C (dec: -77615028)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xA483E81E (dec: -1534859234), parent name: 'PLANAPI_126fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xD841F397 (dec: -666766441), parent name: 'PLANAPI_126fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xB5723A9F (dec: -1250805089), parent name: 'PLANAPI_126fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xCAE583BE (dec: -890928194), parent name: 'PLANAPI_126fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x536959E3 (dec: 1399413219), parent name: 'PLANAPI_126fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_127fake // hashcode: 0xF2322D3D (dec: -231592643)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x3663D375 (dec: 912511861), parent name: 'PLANAPI_127fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xDACB0225 (dec: -624229851), parent name: 'PLANAPI_127fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_128fake // hashcode: 0x5D916097 (dec: 1569808535)
{
	short index;					// size=0, offset=0 //  hashcode: 0xD76BC9B8 (dec: -680801864), parent name: 'PLANAPI_128fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x054935AE (dec: 88683950), parent name: 'PLANAPI_128fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xD1730B25 (dec: -780989659), parent name: 'PLANAPI_128fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x1F4B37DA (dec: 525023194), parent name: 'PLANAPI_128fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_129fake // hashcode: 0x6E821001 (dec: 1854017537)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x49736C6A (dec: 1232301162), parent name: 'PLANAPI_129fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xBD6F9E62 (dec: -1116758430), parent name: 'PLANAPI_129fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x8978C11B (dec: -1988574949), parent name: 'PLANAPI_129fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_130fake // hashcode: 0x0D174B43 (dec: 219630403)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xC6BFB91C (dec: -960513764), parent name: 'PLANAPI_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x312C7911 (dec: 824998161), parent name: 'PLANAPI_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x5DB4BCAA (dec: 1572125866), parent name: 'PLANAPI_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x85ACC614 (dec: -2052274668), parent name: 'PLANAPI_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x6C096BFE (dec: 1812556798), parent name: 'PLANAPI_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x154F53A2 (dec: 357520290), parent name: 'PLANAPI_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x7BFCA82E (dec: 2080155694), parent name: 'PLANAPI_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_131fake // hashcode: 0x3991EE74 (dec: 965865076)
{
	long index;  // size=0, offset=0 //  hashcode: 0xDC60E5A1 (dec: -597629535), parent name: 'PLANAPI_131fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xFC4D62DE (dec: -62037282), parent name: 'PLANAPI_131fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_132fake // hashcode: 0xFCC21AEE (dec: -54387986)
{
	short type; // size=0, offset=0 //  hashcode: 0x79AFB0E9 (dec: 2041557225), parent name: 'PLANAPI_132fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xAFD0B249 (dec: -1345277367), parent name: 'PLANAPI_132fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_133fake // hashcode: 0x12A49705 (dec: 312776453)
{
	long time;   // size=0, offset=0 //  hashcode: 0xACC91F9F (dec: -1396105313), parent name: 'PLANAPI_133fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xFB3FEC8A (dec: -79696758), parent name: 'PLANAPI_133fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_134fake // hashcode: 0x8684818F (dec: -2038136433)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xDF2EB936 (dec: -550586058), parent name: 'PLANAPI_134fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x43065A89 (dec: 1124489865), parent name: 'PLANAPI_134fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_135fake // hashcode: 0x0109960B (dec: 17405451)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x367A1043 (dec: 913969219), parent name: 'PLANAPI_135fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x84874614 (dec: -2071509484), parent name: 'PLANAPI_135fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_136fake // hashcode: 0xCC89A6F8 (dec: -863394056)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xDB59C88B (dec: -614872949), parent name: 'PLANAPI_136fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xC9316634 (dec: -919509452), parent name: 'PLANAPI_136fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_137fake // hashcode: 0xA6C26635 (dec: -1497209291)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0xCE8C7BBE (dec: -829654082), parent name: 'PLANAPI_137fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xC9D873EA (dec: -908561430), parent name: 'PLANAPI_137fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x877F7009 (dec: -2021691383), parent name: 'PLANAPI_137fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xBAC36F41 (dec: -1161597119), parent name: 'PLANAPI_137fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_138fake // hashcode: 0xC09992F5 (dec: -1063677195)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xFB8C294C (dec: -74700468), parent name: 'PLANAPI_138fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xFEF823FC (dec: -17292292), parent name: 'PLANAPI_138fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x7D123B02 (dec: 2098346754), parent name: 'PLANAPI_138fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xD1E8985D (dec: -773285795), parent name: 'PLANAPI_138fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x3EA2475E (dec: 1050822494), parent name: 'PLANAPI_138fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLANAPI_139fake // Hashcode: 0x28E91DE4 (dec: 686366180)
{
	struct PLANAPI_116fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;		 // size=24, offset=0
	struct PLANAPI_117fake teleport;	 // size=16, offset=0
	struct PLANAPI_118fake cameraValue;  // size=8, offset=0
	struct PLANAPI_119fake miscValue;	// size=8, offset=0
	struct PLANAPI_120fake logicValue;   // size=8, offset=0
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
	struct PLANAPI_121fake cameraShake;  // size=8, offset=0
	long cameraSave;					 // size=0, offset=0
	long cameraRestore;					 // size=0, offset=0
	struct _BGObject *bgObject;			 // size=24, offset=0
	long value[2];						 // size=8, offset=0
	struct PLANAPI_122fake sound;		 // size=12, offset=0
	void *intro;						 // size=0, offset=0
	long deathZ;						 // size=0, offset=0
	struct PLANAPI_123fake dsignal;		 // size=8, offset=0
	void *mirror;						 // size=0, offset=0
	long fogNear;						 // size=0, offset=0
	long fogFar;						 // size=0, offset=0
	struct PLANAPI_124fake gotoFrame;	// size=8, offset=0
	struct PLANAPI_125fake changeModel;  // size=8, offset=0
	void *vmObject;						 // size=0, offset=0
	struct PLANAPI_126fake logic;		 // size=8, offset=0
	void *callSignal;					 // size=0, offset=0
	struct _SVector offset;				 // size=8, offset=0
	struct Signal *gotoLabel;			 // size=0, offset=0
	struct Signal *gosubLabel;			 // size=0, offset=0
	struct PLANAPI_127fake control;		 // size=8, offset=0
	struct PLANAPI_128fake zSignal;		 // size=12, offset=0
	struct PLANAPI_129fake StreamLevel;  // size=24, offset=0
	struct PLANAPI_130fake shards;		 // size=12, offset=0
	struct PLANAPI_131fake cameraSpline; // size=8, offset=0
	struct PLANAPI_132fake screenWipe;   // size=4, offset=0
	long voiceSitId;					 // size=0, offset=0
	struct PLANAPI_133fake introFX;		 // size=8, offset=0
	struct PLANAPI_134fake introActive;  // size=8, offset=0
	struct PLANAPI_135fake levelChange;  // size=18, offset=0
	long blendStart;					 // size=0, offset=0
	struct PLANAPI_136fake setTimes;	 // size=8, offset=0
	struct PLANAPI_137fake color;		 // size=4, offset=0
	struct PLANAPI_138fake print;		 // size=12, offset=0
	long slideAngle;					 // size=0, offset=0
};

union PLANAPI_140fake // Hashcode: 0x4B89AA72 (dec: 1267313266)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union PLANAPI_145fake // Hashcode: 0x9C7FBED5 (dec: -1669349675)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct PLANAPI_147fake // hashcode: 0x0F8B1C33 (dec: 260774963)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x722BA618 (dec: 1915463192), parent name: 'PLANAPI_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x6AEF4B56 (dec: 1794067286), parent name: 'PLANAPI_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x0486B784 (dec: 75937668), parent name: 'PLANAPI_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x47BD1BBE (dec: 1203575742), parent name: 'PLANAPI_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0xE91181A5 (dec: -384728667), parent name: 'PLANAPI_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xD2F8EF37 (dec: -755437769), parent name: 'PLANAPI_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x82860B5F (dec: -2105144481), parent name: 'PLANAPI_147fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_148fake // hashcode: 0x838F8CE3 (dec: -2087744285)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x76211052 (dec: 1981878354), parent name: 'PLANAPI_148fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x542D8298 (dec: 1412268696), parent name: 'PLANAPI_148fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xF973F425 (dec: -109841371), parent name: 'PLANAPI_148fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_149fake // hashcode: 0x9A7A559C (dec: -1703258724)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x0C444BD2 (dec: 205802450), parent name: 'PLANAPI_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x9D75F61F (dec: -1653213665), parent name: 'PLANAPI_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xD60B6AE7 (dec: -703894809), parent name: 'PLANAPI_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x8CA08144 (dec: -1935638204), parent name: 'PLANAPI_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x2D36BDA8 (dec: 758562216), parent name: 'PLANAPI_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_150fake // hashcode: 0xFDA154B2 (dec: -39758670)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x2BD0E989 (dec: 735111561), parent name: 'PLANAPI_150fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x5E63E95E (dec: 1583606110), parent name: 'PLANAPI_150fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0xC67086A1 (dec: -965704031), parent name: 'PLANAPI_150fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x109B94E8 (dec: 278631656), parent name: 'PLANAPI_150fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x371100CE (dec: 923861198), parent name: 'PLANAPI_150fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_151fake // hashcode: 0xCFA0CAB4 (dec: -811545932)
{
	struct PLANAPI_147fake Cinematic; // size=28, offset=0 //  hashcode: 0xCF8319BC (dec: -813491780), parent name: 'PLANAPI_151fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PLANAPI_148fake Idle;	  // size=20, offset=28 //  hashcode: 0x127B2065 (dec: 310059109), parent name: 'PLANAPI_151fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PLANAPI_149fake Behind;	// size=28, offset=48 //  hashcode: 0x07D84747 (dec: 131614535), parent name: 'PLANAPI_151fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PLANAPI_150fake Follow;	// size=20, offset=76 //  hashcode: 0x55C0D7CC (dec: 1438701516), parent name: 'PLANAPI_151fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_176fake // hashcode: 0x663D4F56 (dec: 1715294038)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x046E7EDA (dec: 74350298), parent name: 'PLANAPI_176fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0xC2008A33 (dec: -1040152013), parent name: 'PLANAPI_176fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANAPI_177fake // hashcode: 0x141F5729 (dec: 337598249)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x76CBBFC2 (dec: 1993064386), parent name: 'PLANAPI_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0xB1D264FC (dec: -1311611652), parent name: 'PLANAPI_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0xB19AD5A2 (dec: -1315252830), parent name: 'PLANAPI_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x82583218 (dec: -2108149224), parent name: 'PLANAPI_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x5316605E (dec: 1393975390), parent name: 'PLANAPI_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x8A103594 (dec: -1978649196), parent name: 'PLANAPI_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLANAPI_178fake // Hashcode: 0x5AA6D7B4 (dec: 1520883636)
{
	struct PLANAPI_176fake flame; // size=8, offset=0
	struct PLANAPI_177fake phys;  // size=12, offset=0
};

union PLANAPI_211fake // Hashcode: 0xE4701505 (dec: -462416635)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct PoolManagementData // hashcode: 0xA005D5E0 (dec: -1610230304)
{
	char state;									   // size=0, offset=0 //  hashcode: 0x3658C5A3 (dec: 911787427), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numNodesInPool;				   // size=0, offset=1 //  hashcode: 0x54F91C79 (dec: 1425611897), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position playerPosAtLastPlanMkrUpdate; // size=6, offset=2 //  hashcode: 0x617F71D7 (dec: 1635742167), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PlanningNode *expansionNode1;		   // size=28, offset=8 //  hashcode: 0xCADB7802 (dec: -891586558), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PlanningNode *expansionNode2;		   // size=28, offset=12 //  hashcode: 0x50313C4B (dec: 1345403979), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short (*distanceMatrix)[32];		   // size=4, offset=16 //  hashcode: 0x7E6AABEC (dec: 2120920044), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pairType;					   // size=0, offset=20 //  hashcode: 0xC2F189C1 (dec: -1024357951), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position peakPos;					   // size=6, offset=22 //  hashcode: 0x3C40485C (dec: 1010845788), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char currentNode;					   // size=0, offset=28 //  hashcode: 0xE1A0E5F3 (dec: -509549069), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char currentBit;					   // size=0, offset=29 //  hashcode: 0xE53310C3 (dec: -449638205), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EnemyPlanData // hashcode: 0xE792BD02 (dec: -409813758)
{
	unsigned char nodeSkipArray[8];	// size=8, offset=0 //  hashcode: 0x9085EAF0 (dec: -1870271760), parent name: 'EnemyPlanData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char nodeTypeArray[8];	// size=8, offset=8 //  hashcode: 0xAC92416B (dec: -1399701141), parent name: 'EnemyPlanData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position wayPointArray[8]; // size=48, offset=16 //  hashcode: 0x4245AF3A (dec: 1111863098), parent name: 'EnemyPlanData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short goalUnitID;				   // size=0, offset=64 //  hashcode: 0xD91AF375 (dec: -652545163), parent name: 'EnemyPlanData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numWayPoints;		   // size=0, offset=66 //  hashcode: 0xBFCC8414 (dec: -1077115884), parent name: 'EnemyPlanData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _PlanCollideInfo // hashcode: 0x3B1266CC (dec: 991061708)
{
	long StreamUnitID;			 // size=0, offset=0 //  hashcode: 0x6192A9AC (dec: 1637001644), parent name: '_PlanCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tFace;		 // size=12, offset=4 //  hashcode: 0x8CA3BB83 (dec: -1935426685), parent name: '_PlanCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position collidePos; // size=6, offset=8 //  hashcode: 0xAFBB9A20 (dec: -1346659808), parent name: '_PlanCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct PoolManagementData PoolManagementData;

typedef struct EnemyPlanData EnemyPlanData;

typedef struct _PlanCollideInfo PlanCollideInfo;

extern void PLANAPI_ConvertPlanIntoEnmyPlanDataFormat(struct PlanningNode *goalNode, struct EnemyPlanData *planData, struct PlanningNode *planningPool); // 0x80097B8C

extern int PLANAPI_FindPathBetweenNodes(struct PlanningNode *startNode, struct PlanningNode *goalNode, struct EnemyPlanData *planData, int validNodeTypes); // 0x80097C40

extern void PLANAPI_DoTimingCalcsAndDrawing(long startTime, struct PlanningNode *planningPool); // 0x80097CC8

extern int PLANAPI_AddNodeOfTypeToPool(struct _Position *pos, int type); // 0x80097DE4

extern void PLANAPI_DeleteNodesFromPoolByType(int nodeSource); // 0x80097EC4

extern void PLANAPI_DeleteNodeFromPoolByUnit(long streamUnitID); // 0x80097F60

extern int PLANAPI_FindPathInGraphToTarget(struct _Position *startPos, struct EnemyPlanData *planData, int validNodeTypes); // 0x80097FF8

extern void PLANAPI_InitPlanning(void *planningPool); // 0x8009805C

extern short PLANAPI_PairType(struct PlanningNode *node1, struct PlanningNode *node2); // 0x800980DC

extern int PLANAPI_PassThroughHit(struct PlanningNode *node1, struct PlanningNode *node2); // 0x80098124

extern int PLANAPI_CheckTargetToEnemyNode(struct PlanningNode **node1, struct PlanningNode **node2); // 0x80098190

extern void PLANAPI_UpdatePlanningDatabase(struct GameTracker *gameTracker, struct _Instance *player); // 0x800982A0

extern int PLANAPI_NumNodesInPool(void *planningPool); // 0x8009874C

extern void PLANAPI_InitPlanMkrList(struct _StreamUnit *streamUnit); // 0x80098760

extern int PLANAPI_GetFlags(int type); // 0x80098884

extern int PLANAPI_FindNodePositionInUnit(struct _StreamUnit *streamUnit, struct _Position *pos, int id, int type); // 0x800988EC

extern int PLANAPI_FindClosestNodePositionInUnit(struct _StreamUnit *streamUnit, struct _Position *target, struct _Position *pos, int offset, int max, int type, int distanceCheck); // 0x80098990

#endif
