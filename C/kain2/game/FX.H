#ifndef FX_H
#define FX_H

static short current_rain_fade; // offset 0x800CEB78

extern long FX_ColorArray[6]; // offset 0x800CEBAC

static struct _Instance *FX_ConstrictInstance; // offset 0x800CEB70

static struct _Position FX_ConstrictPosition; // offset 0x800D1594

static struct _Position *FX_ConstrictPositionPtr; // offset 0x800D159C

static struct _FXRibbon *FX_ConstrictRibbon; // offset 0x800CEB68

static short FX_ConstrictStage; // offset 0x800CEB6C

static short FX_Frames; // offset 0x800D15A4

static struct _FXGeneralEffect *FX_GeneralEffectTracker; // offset 0x800CEB64

static struct _FX_PRIM *FX_LastUsedPrim; // offset 0x800D15A0

static struct _Instance *FX_reaver_instance; // offset 0x800CEB7C

static short FX_TimeCount; // offset 0x800D15A6

static short rain_amount; // offset 0x800CEB76

static short snow_amount; // offset 0x800CEB74

static struct DVECTOR Spiral_Array[65]; // offset 0x800D15B4

static long Spiral_Current; // offset 0x800CEBC8

static short Spiral_Degrees; // offset 0x800CEBC6

static int Spiral_Glow_Size; // offset 0x800D18CC

static int Spiral_Glow_X; // offset 0x800D18C4

static int Spiral_Glow_Y; // offset 0x800D18C8

static long Spiral_Max; // offset 0x800CEBCC

static int Spiral_Mod; // offset 0x800D18D0

static short Spiral_Number; // offset 0x800CEBC4

static struct DVECTOR Spiral_OffsetM[64]; // offset 0x800D17C4

static struct DVECTOR Spiral_OffsetP[64]; // offset 0x800D16C4

static short wind_deg; // offset 0x800CEBA8

static short wind_speed; // offset 0x800CEBAA

static short windx; // offset 0x800CEBA4

static short windy; // offset 0x800CEBA6

struct DR_TPAGE // hashcode: 0xA93EABEF (dec: -1455510545)
{
	unsigned long tag;	 // size=0, offset=0 //  hashcode: 0x4FAD28E8 (dec: 1336748264), parent name: 'DR_TPAGE', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long code[1]; // size=4, offset=4 //  hashcode: 0x42985F7D (dec: 1117282173), parent name: 'DR_TPAGE', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_68fake // hashcode: 0xA2BF8D33 (dec: -1564504781)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x7342E322 (dec: 1933763362), parent name: 'FX_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x084D76F2 (dec: 139294450), parent name: 'FX_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_69fake // hashcode: 0xA5458740 (dec: -1522170048)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xFD3D7F19 (dec: -46301415), parent name: 'FX_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x2887991B (dec: 679975195), parent name: 'FX_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_70fake // hashcode: 0x77B5577F (dec: 2008373119)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x35E994E5 (dec: 904500453), parent name: 'FX_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x605CE8CF (dec: 1616701647), parent name: 'FX_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union FX_71fake // Hashcode: 0xB3324C63 (dec: -1288549277)
{
	struct FX_68fake callback; // size=8, offset=0
	struct FX_69fake vector;   // size=12, offset=0
	struct FX_70fake quat;	 // size=16, offset=0
};

union FX_72fake // Hashcode: 0x20C14C3E (dec: 549538878)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union FX_73fake // Hashcode: 0x8EDC3051 (dec: -1898172335)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct FX_74fake // hashcode: 0x51201034 (dec: 1361055796)
{
	union FX_73fake size; // size=4, offset=0 //  hashcode: 0xFD4BB25B (dec: -45370789), parent name: 'FX_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_75fake // hashcode: 0x86D7776A (dec: -2032699542)
{
	short x;				// size=0, offset=0 //  hashcode: 0x96D2411A (dec: -1764605670), parent name: 'FX_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x9C876832 (dec: -1668847566), parent name: 'FX_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x17BFC384 (dec: 398443396), parent name: 'FX_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x374AB34B (dec: 927642443), parent name: 'FX_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xB5FDE942 (dec: -1241650878), parent name: 'FX_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_76fake // hashcode: 0x056D67B7 (dec: 91056055)
{
	long index; // size=0, offset=0 //  hashcode: 0x9DB44A1B (dec: -1649128933), parent name: 'FX_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x29B9235E (dec: 699999070), parent name: 'FX_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_77fake // hashcode: 0x102AD405 (dec: 271242245)
{
	long index; // size=0, offset=0 //  hashcode: 0xFBDCF47D (dec: -69405571), parent name: 'FX_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x5E177D94 (dec: 1578597780), parent name: 'FX_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_78fake // hashcode: 0xADAFD111 (dec: -1380986607)
{
	long index; // size=0, offset=0 //  hashcode: 0x212BF9E7 (dec: 556530151), parent name: 'FX_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x18540B19 (dec: 408161049), parent name: 'FX_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_79fake // hashcode: 0x2578CC98 (dec: 628673688)
{
	long time;  // size=0, offset=0 //  hashcode: 0x01DD1714 (dec: 31266580), parent name: 'FX_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xEA6D279E (dec: -361945186), parent name: 'FX_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_80fake // hashcode: 0x42D9D8CD (dec: 1121573069)
{
	long action;   // size=0, offset=0 //  hashcode: 0xDE33388E (dec: -567068530), parent name: 'FX_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x30426308 (dec: 809657096), parent name: 'FX_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_81fake // hashcode: 0xDB840D11 (dec: -612102895)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x399DFF20 (dec: 966655776), parent name: 'FX_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xC044E381 (dec: -1069227135), parent name: 'FX_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_82fake // hashcode: 0x97EA1E82 (dec: -1746264446)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x78146EF3 (dec: 2014605043), parent name: 'FX_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0xEEBDFDCE (dec: -289538610), parent name: 'FX_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_83fake // hashcode: 0xDB00B6B9 (dec: -620710215)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xC810BE0D (dec: -938426867), parent name: 'FX_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xA2743D0E (dec: -1569440498), parent name: 'FX_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_84fake // hashcode: 0xEB80A60B (dec: -343890421)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x53D18E85 (dec: 1406242437), parent name: 'FX_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x3D3B8A85 (dec: 1027312261), parent name: 'FX_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x5A858A81 (dec: 1518701185), parent name: 'FX_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x22C9BC2A (dec: 583646250), parent name: 'FX_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x5EBE6DC9 (dec: 1589538249), parent name: 'FX_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_85fake // hashcode: 0x92851BB1 (dec: -1836770383)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x40042D67 (dec: 1074015591), parent name: 'FX_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xE63E98A3 (dec: -432105309), parent name: 'FX_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_86fake // hashcode: 0x2ED39741 (dec: 785618753)
{
	short index;					// size=0, offset=0 //  hashcode: 0x45E37717 (dec: 1172535063), parent name: 'FX_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xA2520880 (dec: -1571682176), parent name: 'FX_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x02415BAB (dec: 37837739), parent name: 'FX_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x017CF4E3 (dec: 24966371), parent name: 'FX_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_87fake // hashcode: 0xB7CC9CAA (dec: -1211327318)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x8202DF4D (dec: -2113740979), parent name: 'FX_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xB9DF2968 (dec: -1176557208), parent name: 'FX_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xD6377E7C (dec: -701006212), parent name: 'FX_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_88fake // hashcode: 0xBDEDD8DF (dec: -1108485921)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xD7A38220 (dec: -677150176), parent name: 'FX_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xF1EE63EC (dec: -236035092), parent name: 'FX_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x90AA1BE0 (dec: -1867899936), parent name: 'FX_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xB9937B92 (dec: -1181516910), parent name: 'FX_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x2BB67D12 (dec: 733379858), parent name: 'FX_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xA6BAFECB (dec: -1497694517), parent name: 'FX_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x42171899 (dec: 1108809881), parent name: 'FX_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_89fake // hashcode: 0x16F808F2 (dec: 385353970)
{
	long index;  // size=0, offset=0 //  hashcode: 0x1B83B111 (dec: 461615377), parent name: 'FX_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xF59BD4F3 (dec: -174336781), parent name: 'FX_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_90fake // hashcode: 0xD7A537AF (dec: -677038161)
{
	short type; // size=0, offset=0 //  hashcode: 0xCA441477 (dec: -901507977), parent name: 'FX_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x93BC4EFB (dec: -1816375557), parent name: 'FX_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_91fake // hashcode: 0xBD29159D (dec: -1121380963)
{
	long time;   // size=0, offset=0 //  hashcode: 0x502E2808 (dec: 1345202184), parent name: 'FX_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x2CDE601A (dec: 752771098), parent name: 'FX_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_92fake // hashcode: 0xBF3C7925 (dec: -1086555867)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x6853907D (dec: 1750306941), parent name: 'FX_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x0B7D77BB (dec: 192772027), parent name: 'FX_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_93fake // hashcode: 0xCC7D8427 (dec: -864189401)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x6E4190BD (dec: 1849790653), parent name: 'FX_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x396109D2 (dec: 962660818), parent name: 'FX_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_94fake // hashcode: 0xDFAC1A5E (dec: -542369186)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x8E06C972 (dec: -1912157838), parent name: 'FX_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x93ABA009 (dec: -1817468919), parent name: 'FX_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_95fake // hashcode: 0x556EACFD (dec: 1433316605)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0xF9D492AC (dec: -103509332), parent name: 'FX_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xC9BA2B30 (dec: -910546128), parent name: 'FX_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xB5F7964D (dec: -1242065331), parent name: 'FX_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xA05B3D43 (dec: -1604633277), parent name: 'FX_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_96fake // hashcode: 0x31466D33 (dec: 826699059)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xDEA4478E (dec: -559659122), parent name: 'FX_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xAAA6E386 (dec: -1431903354), parent name: 'FX_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xEF70B0BB (dec: -277827397), parent name: 'FX_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xB10E3FE3 (dec: -1324466205), parent name: 'FX_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x45E831C8 (dec: 1172845000), parent name: 'FX_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union FX_97fake // Hashcode: 0x67F73948 (dec: 1744255304)
{
	struct FX_74fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;  // size=24, offset=0
	struct FX_75fake teleport;	 // size=16, offset=0
	struct FX_76fake cameraValue;  // size=8, offset=0
	struct FX_77fake miscValue;	// size=8, offset=0
	struct FX_78fake logicValue;   // size=8, offset=0
	long timer;					   // size=0, offset=0
	long times;					   // size=0, offset=0
	long lightGroup;			   // size=0, offset=0
	long farPlane;				   // size=0, offset=0
	long cameraAdjust;			   // size=0, offset=0
	long cameraMode;			   // size=0, offset=0
	long cameraLock;			   // size=0, offset=0
	long cameraUnlock;			   // size=0, offset=0
	long cameraSmooth;			   // size=0, offset=0
	long cameraTimer;			   // size=0, offset=0
	struct FX_79fake cameraShake;  // size=8, offset=0
	long cameraSave;			   // size=0, offset=0
	long cameraRestore;			   // size=0, offset=0
	struct _BGObject *bgObject;	// size=24, offset=0
	long value[2];				   // size=8, offset=0
	struct FX_80fake sound;		   // size=12, offset=0
	void *intro;				   // size=0, offset=0
	long deathZ;				   // size=0, offset=0
	struct FX_81fake dsignal;	  // size=8, offset=0
	void *mirror;				   // size=0, offset=0
	long fogNear;				   // size=0, offset=0
	long fogFar;				   // size=0, offset=0
	struct FX_82fake gotoFrame;	// size=8, offset=0
	struct FX_83fake changeModel;  // size=8, offset=0
	void *vmObject;				   // size=0, offset=0
	struct FX_84fake logic;		   // size=8, offset=0
	void *callSignal;			   // size=0, offset=0
	struct _SVector offset;		   // size=8, offset=0
	struct Signal *gotoLabel;	  // size=0, offset=0
	struct Signal *gosubLabel;	 // size=0, offset=0
	struct FX_85fake control;	  // size=8, offset=0
	struct FX_86fake zSignal;	  // size=12, offset=0
	struct FX_87fake StreamLevel;  // size=24, offset=0
	struct FX_88fake shards;	   // size=12, offset=0
	struct FX_89fake cameraSpline; // size=8, offset=0
	struct FX_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;			   // size=0, offset=0
	struct FX_91fake introFX;	  // size=8, offset=0
	struct FX_92fake introActive;  // size=8, offset=0
	struct FX_93fake levelChange;  // size=18, offset=0
	long blendStart;			   // size=0, offset=0
	struct FX_94fake setTimes;	 // size=8, offset=0
	struct FX_95fake color;		   // size=4, offset=0
	struct FX_96fake print;		   // size=12, offset=0
	long slideAngle;			   // size=0, offset=0
};

union FX_98fake // Hashcode: 0x5506A570 (dec: 1426498928)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union FX_103fake // Hashcode: 0xD874A45B (dec: -663444389)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct FX_105fake // hashcode: 0x1909C509 (dec: 420070665)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xA716E187 (dec: -1491672697), parent name: 'FX_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x444A601F (dec: 1145724959), parent name: 'FX_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x4C0A1D3A (dec: 1275731258), parent name: 'FX_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x4FCB4E1F (dec: 1338723871), parent name: 'FX_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x1CC6A16D (dec: 482779501), parent name: 'FX_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xFB61D614 (dec: -77474284), parent name: 'FX_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xCB0EA149 (dec: -888233655), parent name: 'FX_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_106fake // hashcode: 0x1220F3D3 (dec: 304149459)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x952C0070 (dec: -1792278416), parent name: 'FX_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xF7F9A8EC (dec: -134633236), parent name: 'FX_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x6A6EC27A (dec: 1785643642), parent name: 'FX_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_107fake // hashcode: 0xE8E2770C (dec: -387811572)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xAD74E90B (dec: -1384847093), parent name: 'FX_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xF338221F (dec: -214425057), parent name: 'FX_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x716F03D8 (dec: 1903100888), parent name: 'FX_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x0BB6A4FE (dec: 196519166), parent name: 'FX_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x8C95874A (dec: -1936357558), parent name: 'FX_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_108fake // hashcode: 0x0BB10E33 (dec: 196152883)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x958D3338 (dec: -1785908424), parent name: 'FX_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x37E5F95A (dec: 937818458), parent name: 'FX_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x6DD17654 (dec: 1842443860), parent name: 'FX_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x70A916DA (dec: 1890129626), parent name: 'FX_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xB97B6490 (dec: -1183095664), parent name: 'FX_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_109fake // hashcode: 0x76D46C98 (dec: 1993632920)
{
	struct FX_105fake Cinematic; // size=28, offset=0 //  hashcode: 0x9A080094 (dec: -1710751596), parent name: 'FX_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct FX_106fake Idle;		 // size=20, offset=28 //  hashcode: 0xD5523075 (dec: -716033931), parent name: 'FX_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct FX_107fake Behind;	// size=28, offset=48 //  hashcode: 0x2C7A11B4 (dec: 746197428), parent name: 'FX_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct FX_108fake Follow;	// size=20, offset=76 //  hashcode: 0x00DBAE41 (dec: 14396993), parent name: 'FX_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_176fake // hashcode: 0x66DEE18F (dec: 1725882767)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x0B6D4678 (dec: 191710840), parent name: 'FX_176fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x983CC77F (dec: -1740847233), parent name: 'FX_176fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FX_177fake // hashcode: 0xD008016D (dec: -804781715)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0xBCBA50DC (dec: -1128640292), parent name: 'FX_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0xB6ADC3BA (dec: -1230126150), parent name: 'FX_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0xBE2B6C18 (dec: -1104450536), parent name: 'FX_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x055F4C8B (dec: 90131595), parent name: 'FX_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x67405604 (dec: 1732269572), parent name: 'FX_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x1E38136E (dec: 506991470), parent name: 'FX_177fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union FX_178fake // Hashcode: 0xBEEF29AC (dec: -1091622484)
{
	struct FX_176fake flame; // size=8, offset=0
	struct FX_177fake phys;  // size=12, offset=0
};

struct _POLY_SG4 // hashcode: 0xA49EA007 (dec: -1533108217)
{
	unsigned long tag;		  // size=0, offset=0 //  hashcode: 0xD4A49BC5 (dec: -727409723), parent name: '_POLY_SG4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long drawTPage1; // size=0, offset=4 //  hashcode: 0x67D71723 (dec: 1742149411), parent name: '_POLY_SG4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BASIC_G4 p1;	  // size=32, offset=8 //  hashcode: 0xE3E208CE (dec: -471725874), parent name: '_POLY_SG4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long drawTPage2; // size=0, offset=40 //  hashcode: 0x66B726A3 (dec: 1723279011), parent name: '_POLY_SG4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BASIC_F4 p2;	  // size=20, offset=44 //  hashcode: 0xFA051EDF (dec: -100327713), parent name: '_POLY_SG4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXGeneralEffect // hashcode: 0xC4783451 (dec: -998755247)
{
	void *next;					// size=0, offset=0 //  hashcode: 0x1F9D7D16 (dec: 530414870), parent name: '_FXGeneralEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;		// size=0, offset=4 //  hashcode: 0xECB75CF5 (dec: -323527435), parent name: '_FXGeneralEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=8 //  hashcode: 0x7DA8E1A8 (dec: 2108219816), parent name: '_FXGeneralEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;   // size=0, offset=12 //  hashcode: 0xAD4ECC4A (dec: -1387344822), parent name: '_FXGeneralEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;			// size=0, offset=13 //  hashcode: 0xD38627FB (dec: -746182661), parent name: '_FXGeneralEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;				// size=0, offset=14 //  hashcode: 0xDDBAC6F9 (dec: -574961927), parent name: '_FXGeneralEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXRibbon // hashcode: 0xB11070B8 (dec: -1324322632)
{
	void *next;					// size=0, offset=0 //  hashcode: 0x056D852E (dec: 91063598), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;		// size=0, offset=4 //  hashcode: 0xACC891BA (dec: -1396141638), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=8 //  hashcode: 0xCDC03BEC (dec: -843039764), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;   // size=0, offset=12 //  hashcode: 0x0B3DCBBC (dec: 188599228), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;			// size=0, offset=13 //  hashcode: 0x1E4C8317 (dec: 508330775), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;				// size=0, offset=14 //  hashcode: 0x4495A7C7 (dec: 1150658503), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numberVerts;			// size=0, offset=16 //  hashcode: 0xD42D12E3 (dec: -735243549), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	short endIndex;				// size=0, offset=18 //  hashcode: 0x18F8C28B (dec: 418955915), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR *vertexPool; // size=8, offset=20 //  hashcode: 0xA524991C (dec: -1524328164), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startSegment;			// size=0, offset=24 //  hashcode: 0x93B4A51B (dec: -1816877797), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	short endSegment;			// size=0, offset=26 //  hashcode: 0x538DAFC5 (dec: 1401794501), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	long startColor;			// size=0, offset=28 //  hashcode: 0x4893A6A7 (dec: 1217636007), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	long endColor;				// size=0, offset=32 //  hashcode: 0x5A645082 (dec: 1516523650), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	short colorStepValue;		// size=0, offset=36 //  hashcode: 0xA4B98F84 (dec: -1531342972), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	short faceLifeTime;			// size=0, offset=38 //  hashcode: 0x5B36C1B8 (dec: 1530315192), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startFadeValue;		// size=0, offset=40 //  hashcode: 0x45149539 (dec: 1158976825), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadeStep;				// size=0, offset=42 //  hashcode: 0xCB476C14 (dec: -884511724), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXParticle // hashcode: 0xDD6F143E (dec: -579922882)
{
	void *next;					   // size=0, offset=0 //  hashcode: 0x461C8125 (dec: 1176273189), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;		   // size=0, offset=4 //  hashcode: 0x839E23C7 (dec: -2086788153), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance;	// size=616, offset=8 //  hashcode: 0x840608DB (dec: -2079979301), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;	  // size=0, offset=12 //  hashcode: 0xCFAE488B (dec: -810661749), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;			   // size=0, offset=13 //  hashcode: 0x1F4BFD8C (dec: 525073804), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;				   // size=0, offset=14 //  hashcode: 0x68ECD6CB (dec: 1760351947), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct TextureMT3 *texture;	// size=16, offset=16 //  hashcode: 0xA45874DB (dec: -1537706789), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fxprim_modify_process;   // size=0, offset=20 //  hashcode: 0x2465EF96 (dec: 610660246), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fxprim_process;		   // size=0, offset=24 //  hashcode: 0x18CA35BD (dec: 415905213), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	short size;					   // size=0, offset=28 //  hashcode: 0xFB95B5AF (dec: -74074705), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	short primLifeTime;			   // size=0, offset=30 //  hashcode: 0x24ECCC15 (dec: 619498517), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	short birthRadius;			   // size=0, offset=32 //  hashcode: 0x92F5AE45 (dec: -1829392827), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	short scaleSpeed;			   // size=0, offset=34 //  hashcode: 0x4EC47547 (dec: 1321497927), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position direction;	// size=6, offset=36 //  hashcode: 0x9F67E731 (dec: -1620580559), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short flag_bits;	  // size=0, offset=42 //  hashcode: 0x68A2DE71 (dec: 1755504241), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position acceleration; // size=6, offset=44 //  hashcode: 0x314B8948 (dec: 827033928), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startScale;			   // size=0, offset=50 //  hashcode: 0xAD58E74E (dec: -1386682546), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position offset;	   // size=6, offset=52 //  hashcode: 0x92AEB6B4 (dec: -1834043724), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	char startSegment;			   // size=0, offset=58 //  hashcode: 0x85051D07 (dec: -2063262457), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	char z_undulate;			   // size=0, offset=59 //  hashcode: 0x678AEC64 (dec: 1737157732), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	long startColor;			   // size=0, offset=60 //  hashcode: 0x435F82D8 (dec: 1130332888), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	long endColor;				   // size=0, offset=64 //  hashcode: 0x47E09D6E (dec: 1205902702), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	short colorStepValue;		   // size=0, offset=68 //  hashcode: 0x3E5392D8 (dec: 1045664472), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numberBirthParticles;	 // size=0, offset=70 //  hashcode: 0x6F3CE68A (dec: 1866262154), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	char endSegment;			   // size=0, offset=71 //  hashcode: 0xCCF3E16B (dec: -856432277), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startFadeValue;		   // size=0, offset=72 //  hashcode: 0x67439963 (dec: 1732483427), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadeStep;				   // size=0, offset=74 //  hashcode: 0xC0364F05 (dec: -1070182651), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXLightBeam // hashcode: 0xDC9CA53F (dec: -593713857)
{
	void *next;					// size=0, offset=0 //  hashcode: 0x44A4FE33 (dec: 1151663667), parent name: '_FXLightBeam', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;		// size=0, offset=4 //  hashcode: 0x92230972 (dec: -1843197582), parent name: '_FXLightBeam', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=8 //  hashcode: 0x05586785 (dec: 89679749), parent name: '_FXLightBeam', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;   // size=0, offset=12 //  hashcode: 0x57F20C65 (dec: 1475480677), parent name: '_FXLightBeam', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;			// size=0, offset=13 //  hashcode: 0x7C9595E8 (dec: 2090178024), parent name: '_FXLightBeam', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;				// size=0, offset=14 //  hashcode: 0x85ADE82A (dec: -2052200406), parent name: '_FXLightBeam', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startSeg;				// size=0, offset=16 //  hashcode: 0x58DC47BF (dec: 1490831295), parent name: '_FXLightBeam', parent hashcode: 0xFFFFFFFF (dec: -1)
	short endSeg;				// size=0, offset=18 //  hashcode: 0x94F98912 (dec: -1795585774), parent name: '_FXLightBeam', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;					// size=0, offset=20 //  hashcode: 0xC1C7140A (dec: -1043917814), parent name: '_FXLightBeam', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXBlastringEffect // hashcode: 0x2F8F0E55 (dec: 797904469)
{
	void *next;					// size=0, offset=0 //  hashcode: 0xC6243C7C (dec: -970703748), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;		// size=0, offset=4 //  hashcode: 0x2A7835E5 (dec: 712521189), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=8 //  hashcode: 0x23DBC99E (dec: 601606558), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;   // size=0, offset=12 //  hashcode: 0x9E34B068 (dec: -1640714136), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;			// size=0, offset=13 //  hashcode: 0x30795D3E (dec: 813260094), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;				// size=0, offset=14 //  hashcode: 0xEE20786D (dec: -299861907), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector position;   // size=8, offset=16 //  hashcode: 0xBCC0B3A2 (dec: -1128221790), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX matrix;		// size=32, offset=24 //  hashcode: 0xC55FBC94 (dec: -983581548), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short segment;				// size=0, offset=56 //  hashcode: 0xF1C61BBF (dec: -238675009), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;					// size=0, offset=58 //  hashcode: 0x2EE0B64B (dec: 786478667), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int radius;					// size=0, offset=60 //  hashcode: 0x64CF8E02 (dec: 1691323906), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int size1;					// size=0, offset=64 //  hashcode: 0xB13C4517 (dec: -1321450217), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int size2;					// size=0, offset=68 //  hashcode: 0x9AFB4D85 (dec: -1694806651), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int startRadius;			// size=0, offset=72 //  hashcode: 0x9D3B98A3 (dec: -1657038685), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int endRadius;				// size=0, offset=76 //  hashcode: 0x9CC01C92 (dec: -1665131374), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int colorchange_radius;		// size=0, offset=80 //  hashcode: 0x86C29E6E (dec: -2034065810), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int vel;					// size=0, offset=84 //  hashcode: 0x9D29DC6D (dec: -1658200979), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int accl;					// size=0, offset=88 //  hashcode: 0x439556F0 (dec: 1133860592), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int height1;				// size=0, offset=92 //  hashcode: 0x7EECD58E (dec: 2129450382), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int height2;				// size=0, offset=96 //  hashcode: 0x8A0CF25E (dec: -1978863010), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int height3;				// size=0, offset=100 //  hashcode: 0x3BFF55CA (dec: 1006589386), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	char predator_offset;		// size=0, offset=104 //  hashcode: 0xB78D3ACE (dec: -1215481138), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	char predator_offset_orig;  // size=0, offset=105 //  hashcode: 0x3D3091F1 (dec: 1026593265), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	char stay_in_place;			// size=0, offset=106 //  hashcode: 0xF2E8D397 (dec: -219622505), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	char sortInWorld;			// size=0, offset=107 //  hashcode: 0x7367ABD5 (dec: 1936174037), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;					// size=0, offset=108 //  hashcode: 0x5CC5628B (dec: 1556439691), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	long startColor;			// size=0, offset=112 //  hashcode: 0x1631300D (dec: 372322317), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	long endColor;				// size=0, offset=116 //  hashcode: 0x4A5EF841 (dec: 1247737921), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXForceFieldEffect // hashcode: 0x59105BC4 (dec: 1494244292)
{
	void *next;					// size=0, offset=0 //  hashcode: 0x174119ED (dec: 390142445), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;		// size=0, offset=4 //  hashcode: 0x08938F17 (dec: 143888151), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=8 //  hashcode: 0xDCC7202B (dec: -590929877), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;   // size=0, offset=12 //  hashcode: 0x3CDA398B (dec: 1020934539), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;			// size=0, offset=13 //  hashcode: 0xBDE02CD8 (dec: -1109381928), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;				// size=0, offset=14 //  hashcode: 0x42E6C32B (dec: 1122419499), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset;		// size=8, offset=16 //  hashcode: 0xDBCD02AF (dec: -607321425), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short size;					// size=0, offset=24 //  hashcode: 0xE1B6DF4B (dec: -508108981), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short size_diff;			// size=0, offset=26 //  hashcode: 0x025CF3B0 (dec: 39646128), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short size_change;			// size=0, offset=28 //  hashcode: 0x4479F6D7 (dec: 1148843735), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short deg;					// size=0, offset=30 //  hashcode: 0xF6A65E73 (dec: -156869005), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short deg_change;			// size=0, offset=32 //  hashcode: 0x6E0D5A42 (dec: 1846368834), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short start_fade;			// size=0, offset=34 //  hashcode: 0x68397CDC (dec: 1748597980), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short end_fade;				// size=0, offset=36 //  hashcode: 0xEE8018E4 (dec: -293594908), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;					// size=0, offset=40 //  hashcode: 0x8BF69A1B (dec: -1946772965), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXLightning // hashcode: 0x552145A3 (dec: 1428243875)
{
	void *next;						// size=0, offset=0 //  hashcode: 0x0BF2E824 (dec: 200468516), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;			// size=0, offset=4 //  hashcode: 0x3F018F8A (dec: 1057066890), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance;		// size=616, offset=8 //  hashcode: 0x9C99A12C (dec: -1667653332), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;		// size=0, offset=12 //  hashcode: 0xA004DB26 (dec: -1610294490), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;				// size=0, offset=13 //  hashcode: 0x685C87B7 (dec: 1750894519), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;					// size=0, offset=14 //  hashcode: 0xCD99C6ED (dec: -845560083), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short deg;						// size=0, offset=16 //  hashcode: 0xB2F2D26A (dec: -1292709270), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short deg_inc;					// size=0, offset=18 //  hashcode: 0x7A8649C8 (dec: 2055621064), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position start_offset;  // size=6, offset=20 //  hashcode: 0xF115235F (dec: -250272929), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startSeg;					// size=0, offset=26 //  hashcode: 0x4098D1E8 (dec: 1083757032), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *end_instance; // size=616, offset=28 //  hashcode: 0x834A6C5E (dec: -2092274594), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position end_offset;	// size=6, offset=32 //  hashcode: 0x45F4C032 (dec: 1173667890), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short endSeg;					// size=0, offset=38 //  hashcode: 0xBAFABDF3 (dec: -1157972493), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short matrixSeg;				// size=0, offset=40 //  hashcode: 0xEDDEA2B4 (dec: -304176460), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short width;					// size=0, offset=42 //  hashcode: 0x48FED3FB (dec: 1224659963), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short small_width;				// size=0, offset=44 //  hashcode: 0x6DC83B76 (dec: 1841838966), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short segs;						// size=0, offset=46 //  hashcode: 0x74FAFA7A (dec: 1962605178), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sine_size;				// size=0, offset=48 //  hashcode: 0xB3EB3806 (dec: -1276430330), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short variation;				// size=0, offset=50 //  hashcode: 0x311043B5 (dec: 823149493), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;						// size=0, offset=52 //  hashcode: 0x2D820C5D (dec: 763497565), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	long glow_color;				// size=0, offset=56 //  hashcode: 0x1A485C97 (dec: 440949911), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXFlash // hashcode: 0xD3DE17A3 (dec: -740419677)
{
	void *next;					// size=0, offset=0 //  hashcode: 0x428224AC (dec: 1115825324), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;		// size=0, offset=4 //  hashcode: 0x36996701 (dec: 916023041), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=8 //  hashcode: 0xED212D9E (dec: -316592738), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;   // size=0, offset=12 //  hashcode: 0x04D5162C (dec: 81073708), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;			// size=0, offset=13 //  hashcode: 0x640122DE (dec: 1677796062), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;				// size=0, offset=14 //  hashcode: 0x8C1D0AF9 (dec: -1944253703), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timeToColor;			// size=0, offset=16 //  hashcode: 0xB7815216 (dec: -1216261610), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timeAtColor;			// size=0, offset=20 //  hashcode: 0x7388DCC0 (dec: 1938349248), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timeFromColor;			// size=0, offset=24 //  hashcode: 0x50A82F5E (dec: 1353199454), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	long currentTime;			// size=0, offset=28 //  hashcode: 0xF8155FD1 (dec: -132816943), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;					// size=0, offset=32 //  hashcode: 0x744C8B19 (dec: 1951173401), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GenericFXObject // hashcode: 0xD22FD65C (dec: -768616868)
{
	struct _GenericParticleParams *ParticleList;   // size=48, offset=0 //  hashcode: 0x4055E7DE (dec: 1079371742), parent name: 'GenericFXObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _GenericRibbonParams *RibbonList;	   // size=20, offset=4 //  hashcode: 0xD71CD0D4 (dec: -685977388), parent name: 'GenericFXObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _GenericGlowParams *GlowList;		   // size=24, offset=8 //  hashcode: 0xE5C0539F (dec: -440380513), parent name: 'GenericFXObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _GenericLightningParams *LightningList; // size=40, offset=12 //  hashcode: 0x15F04DCE (dec: 368070094), parent name: 'GenericFXObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _GenericBlastringParams *BlastList;	 // size=48, offset=16 //  hashcode: 0x033C2825 (dec: 54274085), parent name: 'GenericFXObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _GenericFlashParams *FlashList;		   // size=12, offset=20 //  hashcode: 0x1C442A8E (dec: 474229390), parent name: 'GenericFXObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long *ColorList;							   // size=0, offset=24 //  hashcode: 0x69B3289E (dec: 1773349022), parent name: 'GenericFXObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union FX_204fake // Hashcode: 0x83EDAC95 (dec: -2081575787)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct evObjectDraftData // hashcode: 0x73C6643E (dec: 1942381630)
{
	short force;				// size=0, offset=0 //  hashcode: 0xC4B917A8 (dec: -994502744), parent name: 'evObjectDraftData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short radius;		// size=0, offset=2 //  hashcode: 0xEBB7794B (dec: -340297397), parent name: 'evObjectDraftData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short radiusCoef;  // size=0, offset=4 //  hashcode: 0x2131DB3F (dec: 556915519), parent name: 'evObjectDraftData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short height;		// size=0, offset=6 //  hashcode: 0x2A97DF9C (dec: 714596252), parent name: 'evObjectDraftData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short maxVelocity; // size=0, offset=8 //  hashcode: 0x4DDEED09 (dec: 1306455305), parent name: 'evObjectDraftData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GlyphTuneData // hashcode: 0x14FFD660 (dec: 352310880)
{
	short glyph_size;	 // size=0, offset=0 //  hashcode: 0x07301BC5 (dec: 120593349), parent name: '_GlyphTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short glyph_darkness; // size=0, offset=2 //  hashcode: 0x7DEDCF25 (dec: 2112737061), parent name: '_GlyphTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char glyph_costs[8];  // size=8, offset=4 //  hashcode: 0xD9C04065 (dec: -641712027), parent name: '_GlyphTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short glyph_range[8]; // size=16, offset=12 //  hashcode: 0xC75EEA43 (dec: -950080957), parent name: '_GlyphTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color_array[28]; // size=112, offset=28 //  hashcode: 0x886BB28B (dec: -2006207861), parent name: '_GlyphTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __ReaverData // hashcode: 0xD1EA4FE0 (dec: -773173280)
{
	char ReaverPickedUp;			 // size=0, offset=0 //  hashcode: 0xC8AFBCBF (dec: -928006977), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char ReaverOn;					 // size=0, offset=1 //  hashcode: 0x94D6BE07 (dec: -1797865977), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ReaverSize;				 // size=0, offset=2 //  hashcode: 0x67691978 (dec: 1734941048), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short CurrentReaver;			 // size=0, offset=4 //  hashcode: 0xB320FC9F (dec: -1289683809), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ReaverDeg;				 // size=0, offset=6 //  hashcode: 0x6B473742 (dec: 1799829314), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long ReaverChargeTime;			 // size=0, offset=8 //  hashcode: 0x31BBA4D5 (dec: 834381013), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long ReaverShockAmount;			 // size=0, offset=12 //  hashcode: 0xC7285815 (dec: -953657323), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long ReaverGlowColor;			 // size=0, offset=16 //  hashcode: 0xE6291596 (dec: -433515114), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long ReaverBladeColor;			 // size=0, offset=20 //  hashcode: 0x6E28F71B (dec: 1848178459), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long ReaverBladeGlowColor;		 // size=0, offset=24 //  hashcode: 0xEC138772 (dec: -334264462), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ReaverScale;				 // size=0, offset=28 //  hashcode: 0xEE457180 (dec: -297438848), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ReaverTargetScale;		 // size=0, offset=30 //  hashcode: 0xE77B3928 (dec: -411354840), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __ReaverSaveDat saveData; // size=4, offset=32 //  hashcode: 0xB641333A (dec: -1237241030), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __ReaverTuneData // hashcode: 0xE4E74D43 (dec: -454603453)
{
	unsigned long spectralGlowColor;	  // size=0, offset=0 //  hashcode: 0xF33CF062 (dec: -214110110), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long materialGlowColor;	  // size=0, offset=4 //  hashcode: 0x493656E8 (dec: 1228297960), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long sunlightGlowColor;	  // size=0, offset=8 //  hashcode: 0x7A422364 (dec: 2051154788), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long waterGlowColor;		  // size=0, offset=12 //  hashcode: 0xD2F16E2E (dec: -755929554), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long stoneGlowColor;		  // size=0, offset=16 //  hashcode: 0x61F9544A (dec: 1643729994), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long fireGlowColor;		  // size=0, offset=20 //  hashcode: 0x5D772918 (dec: 1568090392), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long spiritGlowColor;		  // size=0, offset=24 //  hashcode: 0x8CAABE77 (dec: -1934967177), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long soundGlowColor;		  // size=0, offset=28 //  hashcode: 0xD7F99609 (dec: -671508983), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long spectralInnerColor;	 // size=0, offset=32 //  hashcode: 0x3C503C2E (dec: 1011891246), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long materialInnerColor;	 // size=0, offset=36 //  hashcode: 0x0F7982F1 (dec: 259621617), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long sunlightInnerColor;	 // size=0, offset=40 //  hashcode: 0x90116BA0 (dec: -1877906528), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long waterInnerColor;		  // size=0, offset=44 //  hashcode: 0x79CB2190 (dec: 2043355536), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long stoneInnerColor;		  // size=0, offset=48 //  hashcode: 0x05BC4B2A (dec: 96226090), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long fireInnerColor;		  // size=0, offset=52 //  hashcode: 0x1BD57E2D (dec: 466976301), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long spiritInnerColor;		  // size=0, offset=56 //  hashcode: 0x678BA871 (dec: 1737205873), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long soundInnerColor;		  // size=0, offset=60 //  hashcode: 0xFCCE42D8 (dec: -53591336), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long spectralInnerGlowColor; // size=0, offset=64 //  hashcode: 0xD7A7FCCE (dec: -676856626), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long materialInnerGlowColor; // size=0, offset=68 //  hashcode: 0x0305F378 (dec: 50721656), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long sunlightInnerGlowColor; // size=0, offset=72 //  hashcode: 0xD05F3152 (dec: -799067822), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long waterInnerGlowColor;	// size=0, offset=76 //  hashcode: 0xD44FFCAA (dec: -732955478), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long stoneInnerGlowColor;	// size=0, offset=80 //  hashcode: 0xA0F023FF (dec: -1594874881), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long fireInnerGlowColor;	 // size=0, offset=84 //  hashcode: 0xDE2F1C19 (dec: -567337959), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long spiritInnerGlowColor;   // size=0, offset=88 //  hashcode: 0x0D2BF8F3 (dec: 220985587), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long soundInnerGlowColor;	// size=0, offset=92 //  hashcode: 0x809E5545 (dec: -2137107131), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long icon_colors[24];		  // size=96, offset=96 //  hashcode: 0xC215EAF8 (dec: -1038750984), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _POLY_TF4 // hashcode: 0x871FC08E (dec: -2027962226)
{
	unsigned long tag;		 // size=0, offset=0 //  hashcode: 0x09B6CB48 (dec: 162974536), parent name: '_POLY_TF4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long drawTPage; // size=0, offset=4 //  hashcode: 0x500B97EB (dec: 1342937067), parent name: '_POLY_TF4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BASIC_F4 p1;	 // size=20, offset=8 //  hashcode: 0x44DA432B (dec: 1155154731), parent name: '_POLY_TF4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _POLY_2G4 // hashcode: 0x3FC1C531 (dec: 1069663537)
{
	unsigned long tag;   // size=0, offset=0 //  hashcode: 0xCBA71693 (dec: -878242157), parent name: '_POLY_2G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BASIC_G4 p1; // size=32, offset=4 //  hashcode: 0x1D50686D (dec: 491808877), parent name: '_POLY_2G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BASIC_G4 p2; // size=32, offset=36 //  hashcode: 0x6FD04F68 (dec: 1875922792), parent name: '_POLY_2G4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _POLY_2G4T // hashcode: 0xA357E01D (dec: -1554522083)
{
	unsigned long tag;		  // size=0, offset=0 //  hashcode: 0xDCE12199 (dec: -589225575), parent name: '_POLY_2G4T', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long drawTPage1; // size=0, offset=4 //  hashcode: 0x1AA0C030 (dec: 446742576), parent name: '_POLY_2G4T', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BASIC_G4 p1;	  // size=32, offset=8 //  hashcode: 0x20553C71 (dec: 542456945), parent name: '_POLY_2G4T', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BASIC_G4 p2;	  // size=32, offset=40 //  hashcode: 0xCB2E0089 (dec: -886177655), parent name: '_POLY_2G4T', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct DR_TPAGE DR_TPAGE;

typedef struct _POLY_SG4 POLY_SG4;

typedef struct _FXGeneralEffect FXGeneralEffect;

typedef struct _FXRibbon FXRibbon;

typedef struct _FXParticle FXParticle;

typedef struct _FXLightBeam FXLightBeam;

typedef struct _FXBlastringEffect FXBlastringEffect;

typedef struct _FXForceFieldEffect FXForceFieldEffect;

typedef struct _FXLightning FXLightning;

typedef struct _FXFlash FXFlash;

typedef struct GenericFXObject GenericFXObject;

typedef struct evObjectDraftData evObjectDraftData;

typedef struct _GlyphTuneData GlyphTuneData;

typedef struct __ReaverData ReaverData;

typedef struct __ReaverTuneData ReaverTuneData;

typedef struct _POLY_TF4 POLY_TF4;

typedef struct _POLY_2G4 POLY_2G4;

typedef struct _POLY_2G4T POLY_2G4T;

extern void FX_Init(struct _FXTracker *fxTracker); // 0x80041F54

extern void FX_Die(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80042034

extern struct _FX_MATRIX *FX_GetMatrix(struct _FXTracker *fxTracker); // 0x800420A4

extern struct _FX_PRIM *FX_GetPrim(struct _FXTracker *fxTracker); // 0x800420F4

extern struct _FXParticle *FX_GetParticle(struct _Instance *instance, short startSegment); // 0x80042164

extern void FX_AniTexSetup(struct _FX_PRIM *fxPrim, struct _MFace *mface, struct _Model *model, struct _FXTracker *fxTracker); // 0x80042200

extern void FX_StandardProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x8004227C

extern void FX_ShatterProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x8004229C

extern void FX_DFacadeProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80042544

extern struct _FX_PRIM *_FX_BuildSingleFaceWithModel(struct _Model *model, struct _MFace *mface, struct SVECTOR *center, struct SVECTOR *vel, struct SVECTOR *accl, struct _FXTracker *fxTracker, TDRFuncPtr__FX_BuildSingleFaceWithModel6fxSetup fxSetup, TDRFuncPtr__FX_BuildSingleFaceWithModel7fxProcess fxProcess, struct _FX_MATRIX *fxMatrix, int timeToLive); // 0x80042718

extern struct _FX_PRIM *FX_BuildSingleFaceWithModel(struct _Model *model, struct _MFace *mface, struct SVECTOR *center, struct SVECTOR *vel, struct SVECTOR *accl, struct _FXTracker *fxTracker, TDRFuncPtr_FX_BuildSingleFaceWithModel6fxSetup fxSetup, TDRFuncPtr_FX_BuildSingleFaceWithModel7fxProcess fxProcess, int timeToLive); // 0x80042814

extern void _FX_SetupLighting(struct _Instance *instance); // 0x80042864

extern long _FX_DoLighting(struct _MFace *mface); // 0x800428B4

extern void _FX_BuildSegmentedSplinters(struct _Instance *instance, struct SVECTOR *center, struct SVECTOR *vel, struct SVECTOR *accl, struct FXSplinter *splintDef, struct _FXTracker *fxTracker, TDRFuncPtr__FX_BuildSegmentedSplinters6fxSetup fxSetup, TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess fxProcess, int shardFlags); // 0x800429CC

extern void _FX_BuildNonSegmentedSplinters(struct _Instance *instance, struct SVECTOR *center, struct SVECTOR *vel, struct SVECTOR *accl, struct FXSplinter *splintDef, struct _FXTracker *fxTracker, TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup fxSetup, TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess fxProcess, int shardFlags); // 0x80043450

extern void _FX_BuildSplinters(struct _Instance *instance, struct SVECTOR *center, struct SVECTOR *vel, struct SVECTOR *accl, struct FXSplinter *splintDef, struct _FXTracker *fxTracker, TDRFuncPtr__FX_BuildSplinters6fxSetup fxSetup, TDRFuncPtr__FX_BuildSplinters7fxProcess fxProcess, int shardFlags); // 0x8004403C

extern void _FX_Build(struct _Instance *instance, struct SVECTOR *center, struct SVECTOR *vel, struct SVECTOR *accl, struct _FXTracker *fxTracker, TDRFuncPtr__FX_Build5fxSetup fxSetup, TDRFuncPtr__FX_Build6fxProcess fxProcess, int shardFlags); // 0x80044190

extern void FX_Build(struct _Instance *instance, struct SVECTOR *center, struct SVECTOR *vel, struct SVECTOR *accl, struct _FXTracker *fxTracker, TDRFuncPtr_FX_Build5fxSetup fxSetup, TDRFuncPtr_FX_Build6fxProcess fxProcess); // 0x800442A4

extern void FX_UpdatePos(struct _FX_PRIM *fxPrim, struct _SVector *offset, int spriteflag); // 0x800442DC

extern void FX_Relocate(struct _SVector *offset); // 0x80044430

extern void FX_UpdateTexturePointers(struct _FX_PRIM *fxPrim, struct Object *oldObject, long sizeOfObject, long offset); // 0x800445E0

extern void FX_RelocateFXPointers(struct Object *oldObject, struct Object *newObject, long sizeOfObject); // 0x80044640

extern void FX_ProcessList(struct _FXTracker *fxTracker); // 0x80044710

extern void FX_DrawReaver(struct _PrimPool *primPool, unsigned long **ot, struct MATRIX *wcTransform); // 0x8004490C

extern void FX_DrawList(struct _FXTracker *fxTracker, struct GameTracker *gameTracker, unsigned long **ot, struct MATRIX *wcTransform); // 0x80044958

extern void FX_SimpleQuadSetup(struct _FX_PRIM *fxPrim, TDRFuncPtr_FX_SimpleQuadSetup1fxProcess fxProcess, struct _FX_MATRIX *fxMatrix, struct _Instance *instance, struct _MFace *mface, struct _MVertex *vertexList, struct SVECTOR *center, struct SVECTOR *vel, struct SVECTOR *accl, struct _FXTracker *fxTracker, int timeToLive); // 0x80045B60

extern void FX_WaterRingProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80045D9C

extern void FX_WaterBubbleProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80045E18

extern void FX_Sprite_Insert(struct NodeType *list, struct _FX_PRIM *fxPrim); // 0x80046030

extern struct TextureMT3 *FX_GetTextureObject(struct Object *object, int modelnum, int texnum); // 0x80046068

extern void FX_MakeWaterBubble(struct _SVector *position, struct _SVector *vel, struct _SVector *accl, long splashZ, struct __BubbleParams *BP); // 0x800460A4

extern void FX_DrawScreenPoly(int transtype, unsigned long color, int zdepth); // 0x80046254

extern struct POLY_GT4 *FX_SetupPolyGT4(int x1, int y1, int x2, int y2, int otz, struct TextureMT3 *texture, long color0, long color1, long color2, long color3); // 0x80046300

extern void FX_MakeWarpArrow(int x, int y, int xsize, int ysize, int fade); // 0x80046404

extern void FX_MakeMannaIcon(int x, int y, int xsize, int ysize); // 0x800464E4

extern void FX_MakeGlyphIcon(struct _Position *position, struct Object *glyphObject, int size, int glyphnum, int enabled); // 0x80046690

extern void FX_SoulDustProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80046854

extern void FX_MakeSoulDust(struct _Instance *instance, short segment); // 0x80046A08

extern void FX_WaterTrailProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80046C48

extern void FX_MakeWaterTrail(struct _Instance *instance, int depth); // 0x80046D60

extern struct _FXRibbon *FX_StartRibbon(struct _Instance *instance, short startSegment, short endSegment, short type, int ribbonLifeTime, int faceLifeTime, int startFadeValue, long startColor, long endColor); // 0x80046F94

extern void FX_RibbonProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80047264

extern void FX_ConstrictProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80047358

extern void FX_StartConstrict(struct _Instance *instance, struct _SVector *constrict_point, short startSegment, short endSegment); // 0x800475FC

extern void FX_EndConstrict(int ConstrictEnemyFlag, struct _Instance *instance); // 0x8004768C

extern void FX_SubDividePrim(struct _FX_PRIM *fxPrim1, struct _FX_PRIM *fxPrim2); // 0x800476F8

extern void FX_ContinueRibbon(struct _FXRibbon *ribbon, struct _FXTracker *fxTracker); // 0x800477BC

extern void FX_StandardFXPrimProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80047D8C

extern void FX_AttachedParticlePrimProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x800480FC

extern void FX_FlamePrimProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80048190

extern void FX_DFacadeParticleSetup(struct _FX_PRIM *fxPrim, struct SVECTOR *center, short halveWidth, short halveHeight, long color, struct SVECTOR *vel, struct SVECTOR *accl, struct _FXTracker *fxTracker, int timeToLive); // 0x80048364

extern struct _FX_PRIM *FX_Dot(struct _SVector *location, struct _SVector *vel, struct _SVector *accel, int scale_speed, long color, long size, int lifetime, int texture_num); // 0x8004844C

extern void FX_Blood(struct _SVector *location, struct _SVector *input_vel, struct _SVector *accel, int amount, long color, long size); // 0x800485B8

extern void FX_Blood2(struct _SVector *location, struct _SVector *input_vel, struct _SVector *accel, int amount, long color, long dummyCrapShouldRemove); // 0x800486F4

extern void FX_Blood_Impale(struct _Instance *locinst, short locseg, struct _Instance *instance, short segment); // 0x80048720

extern struct _FXParticle *FX_BloodCone(struct _Instance *instance, short startSegment, long time); // 0x800488EC

extern struct _FXParticle *FX_GetTorchParticle(struct _Instance *instance, short startSegment, int tex, int birthRadius, int num); // 0x800489B8

extern struct _FXParticle *FX_TorchFlame(struct _Instance *instance, short startSegment); // 0x80048A9C

extern int FX_GetMorphFadeVal(); // 0x80048BF8

extern void FX_ConvertCamPersToWorld(struct SVECTOR *campos, struct SVECTOR *worldpos); // 0x80048C38

extern void FX_GetRandomScreenPt(struct SVECTOR *point); // 0x80048D50

extern void FX_ProcessSnow(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80048DDC

extern void FX_ContinueSnow(struct _FXTracker *fxTracker); // 0x80048F10

extern void FX_UpdateWind(struct _FXTracker *fxTracker); // 0x80049068

extern void FX_ProcessRain(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x800491E0

extern void FX_ContinueRain(struct _FXTracker *fxTracker); // 0x800492B0

extern void FX_MakeSpark(struct _Instance *instance, struct _Model *model, int segment); // 0x800495E8

extern void FX_ContinueParticle(struct _FXParticle *currentParticle, struct _FXTracker *fxTracker); // 0x800496A4

extern void FX_UpdraftPrimModify(struct _FX_PRIM *fxPrim, struct _Instance *instance, struct _FXParticle *particle, struct _FXTracker *fxTracker); // 0x80049EE4

extern void FX_MakeParticleTexFX(struct _FX_PRIM *fxPrim, struct _SVector *position, struct Object *object, int modelnum, int texnum, struct _SVector *vel, struct _SVector *accl, long color, int size, int life); // 0x8004A028

extern void FX_MakeHitFX(struct _SVector *position); // 0x8004A130

extern void FX_ContinueLightning(struct _FXLightning *zap, struct _FXTracker *fxTracker); // 0x8004A1C4

extern void FX_SetReaverInstance(struct _Instance *instance); // 0x8004A224

extern void FX_SoulReaverBlade(struct _Instance *instance, unsigned long **drawot); // 0x8004A230

extern void FX_ReaverBladeInit(); // 0x8004A620

extern void FX_SoulReaverWinding(struct _Instance *instance, struct _PrimPool *primPool, unsigned long **ot, struct MATRIX *wcTransform); // 0x8004A628

extern void FX_UpdateInstanceWaterSplit(struct _Instance *instance); // 0x8004A878

extern void FX_GetPlaneEquation(struct _SVector *normal, struct _SVector *poPlane, struct _PlaneConstants *plane); // 0x8004A948

extern void FX_DoInstancePowerRing(struct _Instance *instance, long atuTime, long *color, long numColors, int follow_halveplane); // 0x8004A9BC

extern void FX_UpdatePowerRing(struct _FXHalvePlane *ring); // 0x8004AB3C

extern void FX_UpdateInstanceSplitRing(struct _FXHalvePlane *ring, struct _FXTracker *fxTracker); // 0x8004ADC0

extern void FX_UpdateGlowEffect(struct _FXGlowEffect *effect, struct _FXTracker *fxTracker); // 0x8004AE50

extern void FX_InsertGeneralEffect(void *ptr); // 0x8004AE80

extern void FX_DeleteGeneralEffect(struct _FXGeneralEffect *effect); // 0x8004AE90

extern struct _FXGlowEffect *FX_DoInstanceOneSegmentGlow(struct _Instance *instance, long segment, long *color, long numColors, long atuColorCycleRate, long width, long height); // 0x8004AF2C

extern void FX_SetGlowFades(struct _FXGlowEffect *glowEffect, int fadein, int fadeout); // 0x8004B08C

extern struct _FXGlowEffect *FX_DoInstanceTwoSegmentGlow(struct _Instance *instance, long segment, long segmentEnd, long *color, long numColors, long atuColorCycleRate, long height); // 0x8004B0A8

extern struct _FXGlowEffect *FX_DoInstanceManySegmentGlow(struct _Instance *instance, long segment, long numSegments, long *color, long numColors, long atuColorCycleRate, long height); // 0x8004B100

extern struct _FXGlowEffect *FX_DoInstanceOneSegmentGlowWithTime(struct _Instance *instance, long segment, long *color, long numColors, long atuColorCycleRate, long width, long height, long ATULifeTime); // 0x8004B148

extern void FX_StopAllGlowEffects(struct _Instance *instance, int fadeout_time); // 0x8004B190

extern void FX_StopGlowEffect(struct _FXGlowEffect *glowEffect, int fadeout_time); // 0x8004B224

extern void FX_DrawLightning(struct _FXLightning *zap, struct MATRIX *wcTransform, unsigned long **ot); // 0x8004B2AC

extern void FX_DrawAllGeneralEffects(struct MATRIX *wcTransform, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot); // 0x8004B560

extern void FX_ContinueBlastRing(struct _FXBlastringEffect *blast, struct _FXTracker *fxTracker); // 0x8004B738

extern struct _FXBlastringEffect *FX_DoBlastRing(struct _Instance *instance, struct _SVector *position, struct MATRIX *mat, int segment, int radius, int endRadius, int colorChangeRadius, int size1, int size2, int vel, int accl, int height1, int height2, int height3, long startColor, long endColor, int pred_offset, int lifeTime, int sortInWorld); // 0x8004B94C

extern void FX_DrawBlastring(struct MATRIX *wcTransform, struct _FXBlastringEffect *blast); // 0x8004BB20

extern void FX_ContinueFlash(struct _FXFlash *flash, struct _FXTracker *fxTracker); // 0x8004BCEC

extern void FX_DrawFlash(struct _FXFlash *flash); // 0x8004BD3C

extern void FX_RelocateGeneric(struct Object *object, long offset); // 0x8004BE50

extern struct _FXParticle *FX_StartGenericParticle(struct _Instance *instance, int num, int segOverride, int lifeOverride, int InitFlag); // 0x8004BEEC

extern void FX_StartGenericRibbon(struct _Instance *instance, int num, int segOverride, int endOverride, int InitFlag); // 0x8004C23C

extern void FX_StartGenericGlow(struct _Instance *instance, int num, int segOverride, int seg2Override, int InitFlag); // 0x8004C2F8

extern struct _FXLightning *FX_CreateLightning(struct _Instance *instance, int lifeTime, int deg, int deg_inc, int width, int small_width, int segs, int sine_size, int variation, unsigned long color, unsigned long glow_color); // 0x8004C4A0

extern void FX_SetLightingPos(struct _FXLightning *zap, struct _Instance *startInstance, int startSeg, struct _Position *startOffset, struct _Instance *endInstance, int endSeg, struct _Position *endOffset, int matrixSeg); // 0x8004C5A8

extern struct _FXLightning *FX_StartGenericLightning(struct _Instance *instance, int num, int segOverride, int endSegOverride); // 0x8004C658

extern struct _FXBlastringEffect *FX_StartGenericBlastring(struct _Instance *instance, int num, int segOverride, int matrixSegOverride); // 0x8004C7FC

extern struct _FXFlash *FX_StartGenericFlash(struct _Instance *instance, int num); // 0x8004CA04

extern long FX_GetHealthColor(int currentHealth); // 0x8004CAE4

extern void FX_Start_Snow(int percent); // 0x8004CB38

extern void FX_Start_Rain(int percent); // 0x8004CB6C

extern void FX_StartLightbeam(struct _Instance *instance, int startSeg, int endSeg, int color_num); // 0x8004CBA8

extern void FX_StartInstanceEffect(struct _Instance *instance, struct ObjectEffect *effect, int InitFlag); // 0x8004CC4C

extern void FX_EndInstanceEffects(struct _Instance *instance); // 0x8004D06C

extern void FX_EndInstanceParticleEffects(struct _Instance *instance); // 0x8004D0C0

extern void FX_GetSpiralPoint(int radius, int deg, int *x, int *y); // 0x8004D130

extern void FX_GetLinePoint(int radius, int next_radius, int deg, int next_deg, int *pntx, int *pnty, int part); // 0x8004D204

extern void FX_CalcSpiral(int degchange); // 0x8004D2D0

extern void FX_Spiral(struct _PrimPool *primPool, unsigned long **ot); // 0x8004D5C8

extern void FX_Health_Spiral(int number, int current_health, int max_health); // 0x8004D9E8

extern void FX_Spiral_Init(); // 0x8004DB34

extern void FX_DrawModel(struct Object *object, int model_num, struct _SVector *rotation, struct _SVector *position, struct _SVector *offset, int transflag); // 0x8004DB74

extern void fx_calc_points(struct _SVector *points, int degrees, int radius, int radius2, int radius3); // 0x8004DDEC

extern long fx_get_startz(struct _SVector *position); // 0x8004DEFC

extern void FX_DrawRing(struct MATRIX *wcTransform, struct _SVector *position, struct MATRIX *matrix, int radius, int radius2, int radius3, int z1, int z2, int z3, long color, int sortInWorld); // 0x8004DF54

extern void fx_setTex(struct DVECTOR *x, unsigned char *uv, int tx, int offset); // 0x8004E200

extern void FX_DrawRing2(struct MATRIX *wcTransform, struct _SVector *position, struct MATRIX *matrix, int radius, int radius2, int radius3, int z1, int z2, int z3, long offset, int sortInWorld); // 0x8004E244

extern void FX_DrawFField(struct MATRIX *wcTransform, struct _FXForceFieldEffect *field); // 0x8004E61C

extern struct _FXForceFieldEffect *FX_StartFField(struct _Instance *instance, int size, struct _Position *offset, int size_diff, int size_change, int deg_change, long color); // 0x8004E810

extern void FX_EndFField(struct _Instance *instance); // 0x8004E8E4

extern void FX_Draw_Glowing_Line(unsigned long **ot, long otz, struct DVECTOR *sxy0, struct DVECTOR *sxy1, struct DVECTOR *xy0, struct DVECTOR *xy1, long color, long color2); // 0x8004E964

extern void FX_Lightning(struct MATRIX *wcTransform, unsigned long **ot, struct MATRIX *mat, short deg, struct _SVector *start, struct _SVector *end, int width, int small_width, int segs, int sine_size, int variation, long color, long glow_color); // 0x8004EB00

extern void FX_LightHouse(struct MATRIX *wcTransform, unsigned long **ot, struct _Instance *instance, int startSeg, int endSeg, int segs, long beam_color); // 0x8004EFF0

extern void FX_StartPassthruFX(struct _Instance *instance, struct _SVector *normal, struct _SVector *point); // 0x8004F46C

extern void FX_EndPassthruFX(struct _Instance *instance); // 0x8004F548

typedef void (*TDRFuncPtr__FX_Build5fxSetup)();

typedef void (*TDRFuncPtr__FX_Build6fxProcess)();

typedef void (*TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup)();

typedef void (*TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess)();

typedef void (*TDRFuncPtr__FX_BuildSegmentedSplinters6fxSetup)();

typedef void (*TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess)();

typedef void (*TDRFuncPtr__FX_BuildSingleFaceWithModel6fxSetup)();

typedef void (*TDRFuncPtr__FX_BuildSingleFaceWithModel7fxProcess)();

typedef void (*TDRFuncPtr__FX_BuildSplinters6fxSetup)();

typedef void (*TDRFuncPtr__FX_BuildSplinters7fxProcess)();

typedef void (*TDRFuncPtr_FX_Build5fxSetup)();

typedef void (*TDRFuncPtr_FX_Build6fxProcess)();

typedef void (*TDRFuncPtr_FX_BuildSingleFaceWithModel6fxSetup)();

typedef void (*TDRFuncPtr_FX_BuildSingleFaceWithModel7fxProcess)();

typedef void (*TDRFuncPtr_FX_SimpleQuadSetup1fxProcess)();

#endif
