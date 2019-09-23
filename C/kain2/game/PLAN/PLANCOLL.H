#ifndef PLANCOLL_H
#define PLANCOLL_H

static struct _fth directionList[6]; // offset 0x800CF75C

struct PLANCOLL_73fake // hashcode: 0x04D9B734 (dec: 81377076)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xCF67995A (dec: -815294118), parent name: 'PLANCOLL_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x0BE19724 (dec: 199333668), parent name: 'PLANCOLL_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_74fake // hashcode: 0x68473DE1 (dec: 1749499361)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xBB526E05 (dec: -1152225787), parent name: 'PLANCOLL_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xF811748B (dec: -133073781), parent name: 'PLANCOLL_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_75fake // hashcode: 0x915CB848 (dec: -1856194488)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x74486531 (dec: 1950901553), parent name: 'PLANCOLL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x26E4B4FF (dec: 652522751), parent name: 'PLANCOLL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLANCOLL_76fake // Hashcode: 0x735BBCE0 (dec: 1935391968)
{
	struct PLANCOLL_73fake callback; // size=8, offset=0
	struct PLANCOLL_74fake vector;   // size=12, offset=0
	struct PLANCOLL_75fake quat;	 // size=16, offset=0
};

union PLANCOLL_77fake // Hashcode: 0x61131CC4 (dec: 1628642500)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PLANCOLL_78fake // Hashcode: 0x1F824E6B (dec: 528633451)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct PLANCOLL_79fake // hashcode: 0x8B5E534C (dec: -1956752564)
{
	union PLANCOLL_78fake size; // size=4, offset=0 //  hashcode: 0xDDA6C10E (dec: -576274162), parent name: 'PLANCOLL_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_80fake // hashcode: 0xD497BB93 (dec: -728253549)
{
	short x;				// size=0, offset=0 //  hashcode: 0x6691D5BA (dec: 1720833466), parent name: 'PLANCOLL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xB2AD121E (dec: -1297280482), parent name: 'PLANCOLL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x7597DFAA (dec: 1972887466), parent name: 'PLANCOLL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xEF482C96 (dec: -280482666), parent name: 'PLANCOLL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xF8313063 (dec: -130994077), parent name: 'PLANCOLL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_81fake // hashcode: 0xE24DF42B (dec: -498207701)
{
	long index; // size=0, offset=0 //  hashcode: 0x02024419 (dec: 33702937), parent name: 'PLANCOLL_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xA189FEDE (dec: -1584791842), parent name: 'PLANCOLL_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_82fake // hashcode: 0x79C21185 (dec: 2042761605)
{
	long index; // size=0, offset=0 //  hashcode: 0xC2EEF6DA (dec: -1024526630), parent name: 'PLANCOLL_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xBA662124 (dec: -1167711964), parent name: 'PLANCOLL_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_83fake // hashcode: 0x52BAAEB3 (dec: 1387966131)
{
	long index; // size=0, offset=0 //  hashcode: 0x38F5D9A0 (dec: 955636128), parent name: 'PLANCOLL_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xE5C0314C (dec: -440389300), parent name: 'PLANCOLL_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_84fake // hashcode: 0x353069EC (dec: 892365292)
{
	long time;  // size=0, offset=0 //  hashcode: 0x6603AEBB (dec: 1711517371), parent name: 'PLANCOLL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xD3FCE61E (dec: -738400738), parent name: 'PLANCOLL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_85fake // hashcode: 0x6EDE4313 (dec: 1860059923)
{
	long action;   // size=0, offset=0 //  hashcode: 0xEDEA4C00 (dec: -303412224), parent name: 'PLANCOLL_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x60945908 (dec: 1620334856), parent name: 'PLANCOLL_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_86fake // hashcode: 0x3E1156FC (dec: 1041323772)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xC6D82474 (dec: -958913420), parent name: 'PLANCOLL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x14AF0AD8 (dec: 347015896), parent name: 'PLANCOLL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_87fake // hashcode: 0x544BB046 (dec: 1414246470)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xE05F5547 (dec: -530623161), parent name: 'PLANCOLL_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0xB5DFF680 (dec: -1243613568), parent name: 'PLANCOLL_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_88fake // hashcode: 0x964B6620 (dec: -1773443552)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xFE0196B0 (dec: -33450320), parent name: 'PLANCOLL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x4E09866E (dec: 1309247086), parent name: 'PLANCOLL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_89fake // hashcode: 0xE331AC70 (dec: -483283856)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x48B470C6 (dec: 1219784902), parent name: 'PLANCOLL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x3A421132 (dec: 977408306), parent name: 'PLANCOLL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x1DD4BFF2 (dec: 500482034), parent name: 'PLANCOLL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x47E6C39E (dec: 1206305694), parent name: 'PLANCOLL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x2BEF8B75 (dec: 737119093), parent name: 'PLANCOLL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_90fake // hashcode: 0x78EAD16E (dec: 2028654958)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x06FFD275 (dec: 117428853), parent name: 'PLANCOLL_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x3A25F4DF (dec: 975566047), parent name: 'PLANCOLL_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_91fake // hashcode: 0xC987FEE9 (dec: -913834263)
{
	short index;					// size=0, offset=0 //  hashcode: 0xD5A66BA7 (dec: -710513753), parent name: 'PLANCOLL_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x60507618 (dec: 1615885848), parent name: 'PLANCOLL_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xDDA7290B (dec: -576247541), parent name: 'PLANCOLL_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xFF9CEC6C (dec: -6493076), parent name: 'PLANCOLL_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_92fake // hashcode: 0x11BA5C4D (dec: 297425997)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xE10843F1 (dec: -519552015), parent name: 'PLANCOLL_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x1FE411D4 (dec: 535040468), parent name: 'PLANCOLL_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x2E1F317E (dec: 773796222), parent name: 'PLANCOLL_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_93fake // hashcode: 0xBC8C6F67 (dec: -1131647129)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xD911FC17 (dec: -653132777), parent name: 'PLANCOLL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x5208DB0B (dec: 1376312075), parent name: 'PLANCOLL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x0E0BA8E6 (dec: 235645158), parent name: 'PLANCOLL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xBB9D8BFE (dec: -1147302914), parent name: 'PLANCOLL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x0736C03B (dec: 121028667), parent name: 'PLANCOLL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x5A67865B (dec: 1516734043), parent name: 'PLANCOLL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x53586F84 (dec: 1398304644), parent name: 'PLANCOLL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_94fake // hashcode: 0xDDC43898 (dec: -574343016)
{
	long index;  // size=0, offset=0 //  hashcode: 0x7C240A9A (dec: 2082736794), parent name: 'PLANCOLL_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xD93F0F1A (dec: -650178790), parent name: 'PLANCOLL_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_95fake // hashcode: 0x0CB993A9 (dec: 213488553)
{
	short type; // size=0, offset=0 //  hashcode: 0xD440B457 (dec: -733957033), parent name: 'PLANCOLL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x64EF8CE1 (dec: 1693420769), parent name: 'PLANCOLL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_96fake // hashcode: 0x0085BD83 (dec: 8764803)
{
	long time;   // size=0, offset=0 //  hashcode: 0x861793C0 (dec: -2045275200), parent name: 'PLANCOLL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x7A3884B6 (dec: 2050524342), parent name: 'PLANCOLL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_97fake // hashcode: 0x34B1E532 (dec: 884073778)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xEC8C9966 (dec: -326330010), parent name: 'PLANCOLL_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xBC7711A7 (dec: -1133047385), parent name: 'PLANCOLL_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_98fake // hashcode: 0x535E9A57 (dec: 1398708823)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x5C2EB10B (dec: 1546563851), parent name: 'PLANCOLL_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xC5D9AB65 (dec: -975590555), parent name: 'PLANCOLL_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_99fake // hashcode: 0xC5A85643 (dec: -978823613)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x4CF5ABF2 (dec: 1291168754), parent name: 'PLANCOLL_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x7D9EED38 (dec: 2107567416), parent name: 'PLANCOLL_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_100fake // hashcode: 0x03536526 (dec: 55797030)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x4700659D (dec: 1191208349), parent name: 'PLANCOLL_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xCDE7CDC1 (dec: -840446527), parent name: 'PLANCOLL_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xB8663785 (dec: -1201260667), parent name: 'PLANCOLL_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xA45463F3 (dec: -1537973261), parent name: 'PLANCOLL_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_101fake // hashcode: 0x882D85E6 (dec: -2010282522)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xF01458DC (dec: -267101988), parent name: 'PLANCOLL_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x1E7BE66A (dec: 511436394), parent name: 'PLANCOLL_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x9073F60B (dec: -1871448565), parent name: 'PLANCOLL_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x6DD200CF (dec: 1842479311), parent name: 'PLANCOLL_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x9C7BE328 (dec: -1669602520), parent name: 'PLANCOLL_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLANCOLL_102fake // Hashcode: 0x37C12433 (dec: 935404595)
{
	struct PLANCOLL_79fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;		 // size=24, offset=0
	struct PLANCOLL_80fake teleport;	 // size=16, offset=0
	struct PLANCOLL_81fake cameraValue;  // size=8, offset=0
	struct PLANCOLL_82fake miscValue;	// size=8, offset=0
	struct PLANCOLL_83fake logicValue;   // size=8, offset=0
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
	struct PLANCOLL_84fake cameraShake;  // size=8, offset=0
	long cameraSave;					 // size=0, offset=0
	long cameraRestore;					 // size=0, offset=0
	struct _BGObject *bgObject;			 // size=24, offset=0
	long value[2];						 // size=8, offset=0
	struct PLANCOLL_85fake sound;		 // size=12, offset=0
	void *intro;						 // size=0, offset=0
	long deathZ;						 // size=0, offset=0
	struct PLANCOLL_86fake dsignal;		 // size=8, offset=0
	void *mirror;						 // size=0, offset=0
	long fogNear;						 // size=0, offset=0
	long fogFar;						 // size=0, offset=0
	struct PLANCOLL_87fake gotoFrame;	// size=8, offset=0
	struct PLANCOLL_88fake changeModel;  // size=8, offset=0
	void *vmObject;						 // size=0, offset=0
	struct PLANCOLL_89fake logic;		 // size=8, offset=0
	void *callSignal;					 // size=0, offset=0
	struct _SVector offset;				 // size=8, offset=0
	struct Signal *gotoLabel;			 // size=0, offset=0
	struct Signal *gosubLabel;			 // size=0, offset=0
	struct PLANCOLL_90fake control;		 // size=8, offset=0
	struct PLANCOLL_91fake zSignal;		 // size=12, offset=0
	struct PLANCOLL_92fake StreamLevel;  // size=24, offset=0
	struct PLANCOLL_93fake shards;		 // size=12, offset=0
	struct PLANCOLL_94fake cameraSpline; // size=8, offset=0
	struct PLANCOLL_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;					 // size=0, offset=0
	struct PLANCOLL_96fake introFX;		 // size=8, offset=0
	struct PLANCOLL_97fake introActive;  // size=8, offset=0
	struct PLANCOLL_98fake levelChange;  // size=18, offset=0
	long blendStart;					 // size=0, offset=0
	struct PLANCOLL_99fake setTimes;	 // size=8, offset=0
	struct PLANCOLL_100fake color;		 // size=4, offset=0
	struct PLANCOLL_101fake print;		 // size=12, offset=0
	long slideAngle;					 // size=0, offset=0
};

union PLANCOLL_103fake // Hashcode: 0xCB19F3E3 (dec: -887491613)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union PLANCOLL_108fake // Hashcode: 0xD910D456 (dec: -653208490)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct PLANCOLL_110fake // hashcode: 0xBEF0EEB1 (dec: -1091506511)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xD9C8B42A (dec: -641158102), parent name: 'PLANCOLL_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x87BC536F (dec: -2017701009), parent name: 'PLANCOLL_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0xCD8666BE (dec: -846829890), parent name: 'PLANCOLL_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xB0490545 (dec: -1337391803), parent name: 'PLANCOLL_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0xB3978C98 (dec: -1281913704), parent name: 'PLANCOLL_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x4C7C8259 (dec: 1283228249), parent name: 'PLANCOLL_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x92610E4F (dec: -1839133105), parent name: 'PLANCOLL_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_111fake // hashcode: 0x08489A80 (dec: 138975872)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0xB4E5BE38 (dec: -1260011976), parent name: 'PLANCOLL_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x128D07EB (dec: 311232491), parent name: 'PLANCOLL_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x14A2F14A (dec: 346222922), parent name: 'PLANCOLL_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_112fake // hashcode: 0xAE5212BE (dec: -1370352962)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x14E00B9C (dec: 350227356), parent name: 'PLANCOLL_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xC9AC297E (dec: -911464066), parent name: 'PLANCOLL_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x0AF2267F (dec: 183641727), parent name: 'PLANCOLL_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xDAB7C2FE (dec: -625491202), parent name: 'PLANCOLL_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x9603CFB0 (dec: -1778135120), parent name: 'PLANCOLL_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_113fake // hashcode: 0x6CE8624E (dec: 1827168846)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x98E5BBB0 (dec: -1729774672), parent name: 'PLANCOLL_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0xA3D4E48E (dec: -1546328946), parent name: 'PLANCOLL_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0xEA5543F1 (dec: -363510799), parent name: 'PLANCOLL_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x2403060E (dec: 604177934), parent name: 'PLANCOLL_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x8694172A (dec: -2037115094), parent name: 'PLANCOLL_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_114fake // hashcode: 0xB6BC32DF (dec: -1229180193)
{
	struct PLANCOLL_110fake Cinematic; // size=28, offset=0 //  hashcode: 0xEE01DC23 (dec: -301867997), parent name: 'PLANCOLL_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PLANCOLL_111fake Idle;	  // size=20, offset=28 //  hashcode: 0xD37EB95B (dec: -746669733), parent name: 'PLANCOLL_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PLANCOLL_112fake Behind;	// size=28, offset=48 //  hashcode: 0xD084D221 (dec: -796601823), parent name: 'PLANCOLL_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PLANCOLL_113fake Follow;	// size=20, offset=76 //  hashcode: 0x60FB1B10 (dec: 1627069200), parent name: 'PLANCOLL_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_181fake // hashcode: 0xDAAF5539 (dec: -626043591)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x40F55F63 (dec: 1089822563), parent name: 'PLANCOLL_181fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0xE0596773 (dec: -531011725), parent name: 'PLANCOLL_181fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLANCOLL_182fake // hashcode: 0x71C0DDAC (dec: 1908465068)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0xBB762340 (dec: -1149885632), parent name: 'PLANCOLL_182fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0xC2BC639C (dec: -1027841124), parent name: 'PLANCOLL_182fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x309967EC (dec: 815359980), parent name: 'PLANCOLL_182fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x6FF82D9B (dec: 1878535579), parent name: 'PLANCOLL_182fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0xE38C5B9C (dec: -477340772), parent name: 'PLANCOLL_182fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x1254CDFE (dec: 307547646), parent name: 'PLANCOLL_182fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLANCOLL_183fake // Hashcode: 0xEFF1E73A (dec: -269359302)
{
	struct PLANCOLL_181fake flame; // size=8, offset=0
	struct PLANCOLL_182fake phys;  // size=12, offset=0
};

union PLANCOLL_216fake // Hashcode: 0x15330FC6 (dec: 355667910)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct _fth // hashcode: 0xDEECEA3E (dec: -554898882)
{
	char x;		   // size=0, offset=0 //  hashcode: 0x42043A54 (dec: 1107573332), parent name: '_fth', parent hashcode: 0xFFFFFFFF (dec: -1)
	char y;		   // size=0, offset=1 //  hashcode: 0x89BD1CDF (dec: -1984095009), parent name: '_fth', parent hashcode: 0xFFFFFFFF (dec: -1)
	char z;		   // size=0, offset=2 //  hashcode: 0xDC998DDE (dec: -593916450), parent name: '_fth', parent hashcode: 0xFFFFFFFF (dec: -1)
	char nodeType; // size=0, offset=3 //  hashcode: 0xAF8D4294 (dec: -1349696876), parent name: '_fth', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct _fth FindTerrainHit;

extern int PLANCOLL_DoesLOSExistFinal(struct _Position *startPos, struct _Position *endPos, int collideType, int passThroughHit, int zoffset); // 0x80098B14

extern int PLANCOLL_CheckUnderwaterPoint(struct _Position *position); // 0x80098C18

extern int PLANCOLL_FindTerrainHitFinal(struct _PlanCollideInfo *pci, int *placement, int distBefore, int distAfter, int start, int end); // 0x80098D84

extern int PLANCOLL_DoesStraightLinePathExist(struct _Position *startPos, struct _Position *endPos, int collideType); // 0x80099044

extern int PLANCOLL_DoesWaterPathUpExist(struct _Position *startPos, struct _Position *endPos, int collideType, struct _Position *peakPos, int passThroughHit); // 0x800990D0

#endif
