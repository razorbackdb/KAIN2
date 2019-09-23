#ifndef FONT_H
#define FONT_H

extern char charMap[92][3]; // offset 0x800C8620

extern struct _BlockVramEntry *FONT_vramBlock; // offset 0x800D05E4

extern struct FontPos fontPos[72]; // offset 0x800C8500

extern struct FontTracker fontTracker; // offset 0x800D05EC

extern unsigned char fontTransTable[128]; // offset 0x800CE224

static char fp_str[512]; // offset 0x800D03E4

static struct font_color_t the_font_color_table[5]; // offset 0x800CE1D0

struct POLY_FT4 // hashcode: 0xAD2AA0E4 (dec: -1389715228)
{
	unsigned long tag;	// size=0, offset=0 //  hashcode: 0xCD016781 (dec: -855545983), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;	 // size=0, offset=4 //  hashcode: 0x4F8F7A3A (dec: 1334803002), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;	 // size=0, offset=5 //  hashcode: 0xA2B60DCB (dec: -1565127221), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;	 // size=0, offset=6 //  hashcode: 0x67B0DF2D (dec: 1739644717), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code;   // size=0, offset=7 //  hashcode: 0x85BC006C (dec: -2051276692), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			  // size=0, offset=8 //  hashcode: 0x9B4A87E6 (dec: -1689614362), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			  // size=0, offset=10 //  hashcode: 0x1826C8B5 (dec: 405194933), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u0;	 // size=0, offset=12 //  hashcode: 0xE5256FA6 (dec: -450531418), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v0;	 // size=0, offset=13 //  hashcode: 0xE8A116FE (dec: -392096002), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short clut;  // size=0, offset=14 //  hashcode: 0x5A0DE413 (dec: 1510859795), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			  // size=0, offset=16 //  hashcode: 0xB9E6F988 (dec: -1176045176), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			  // size=0, offset=18 //  hashcode: 0x7698ACCA (dec: 1989717194), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u1;	 // size=0, offset=20 //  hashcode: 0x5E0E44E2 (dec: 1577993442), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v1;	 // size=0, offset=21 //  hashcode: 0x52A2B6B2 (dec: 1386395314), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short tpage; // size=0, offset=22 //  hashcode: 0x2F3440CD (dec: 791953613), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;			  // size=0, offset=24 //  hashcode: 0x0B7CC8E1 (dec: 192727265), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;			  // size=0, offset=26 //  hashcode: 0xCE45D5BF (dec: -834284097), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u2;	 // size=0, offset=28 //  hashcode: 0x6B39DA23 (dec: 1798953507), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v2;	 // size=0, offset=29 //  hashcode: 0x759C9140 (dec: 1973195072), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad1;  // size=0, offset=30 //  hashcode: 0x5C80DFBB (dec: 1551949755), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x3;			  // size=0, offset=32 //  hashcode: 0x742248D3 (dec: 1948403923), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y3;			  // size=0, offset=34 //  hashcode: 0x91FD9D99 (dec: -1845650023), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u3;	 // size=0, offset=36 //  hashcode: 0xD546FB65 (dec: -716768411), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v3;	 // size=0, offset=37 //  hashcode: 0x14505E97 (dec: 340811415), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad2;  // size=0, offset=38 //  hashcode: 0x8EA73EA9 (dec: -1901642071), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_73fake // hashcode: 0x10ED4DB6 (dec: 283987382)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x3B504862 (dec: 995117154), parent name: 'FONT_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x95799C23 (dec: -1787192285), parent name: 'FONT_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_74fake // hashcode: 0xA72B17C6 (dec: -1490348090)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x9F0BA42E (dec: -1626627026), parent name: 'FONT_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x742679CC (dec: 1948678604), parent name: 'FONT_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_75fake // hashcode: 0xE566935D (dec: -446262435)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x0E4A83CF (dec: 239764431), parent name: 'FONT_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x65ECFF43 (dec: 1710030659), parent name: 'FONT_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union FONT_76fake // Hashcode: 0x7BE39A46 (dec: 2078513734)
{
	struct FONT_73fake callback; // size=8, offset=0
	struct FONT_74fake vector;   // size=12, offset=0
	struct FONT_75fake quat;	 // size=16, offset=0
};

union FONT_77fake // Hashcode: 0xADC7F886 (dec: -1379403642)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union FONT_78fake // Hashcode: 0x6EC60615 (dec: 1858471445)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct FONT_79fake // hashcode: 0xFF5C3CE3 (dec: -10732317)
{
	union FONT_78fake size; // size=4, offset=0 //  hashcode: 0xC1D6FBA6 (dec: -1042875482), parent name: 'FONT_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_80fake // hashcode: 0x8A54E388 (dec: -1974148216)
{
	short x;				// size=0, offset=0 //  hashcode: 0x1C2C300C (dec: 472657932), parent name: 'FONT_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xDF31A4FA (dec: -550394630), parent name: 'FONT_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xF7C87EF8 (dec: -137855240), parent name: 'FONT_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x749F456B (dec: 1956595051), parent name: 'FONT_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x5E550CC7 (dec: 1582632135), parent name: 'FONT_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_81fake // hashcode: 0xE4FB87AB (dec: -453277781)
{
	long index; // size=0, offset=0 //  hashcode: 0x2E9127F1 (dec: 781264881), parent name: 'FONT_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x05D29A19 (dec: 97688089), parent name: 'FONT_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_82fake // hashcode: 0x79BC47E9 (dec: 2042382313)
{
	long index; // size=0, offset=0 //  hashcode: 0xBA418C41 (dec: -1170109375), parent name: 'FONT_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x7054093F (dec: 1884555583), parent name: 'FONT_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_83fake // hashcode: 0x188C4EB9 (dec: 411848377)
{
	long index; // size=0, offset=0 //  hashcode: 0x20CDA558 (dec: 550348120), parent name: 'FONT_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xE5C691FD (dec: -439971331), parent name: 'FONT_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_84fake // hashcode: 0xC50A021D (dec: -989199843)
{
	long time;  // size=0, offset=0 //  hashcode: 0xE28B21C4 (dec: -494198332), parent name: 'FONT_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xFF171E6B (dec: -15262101), parent name: 'FONT_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_85fake // hashcode: 0xFD063560 (dec: -49924768)
{
	long action;   // size=0, offset=0 //  hashcode: 0x0114CC48 (dec: 18140232), parent name: 'FONT_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xCD4EC01C (dec: -850477028), parent name: 'FONT_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_86fake // hashcode: 0xAD067981 (dec: -1392084607)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x8A10AE41 (dec: -1978618303), parent name: 'FONT_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x919EF970 (dec: -1851852432), parent name: 'FONT_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_87fake // hashcode: 0x263A40C8 (dec: 641351880)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x3A819D23 (dec: 981572899), parent name: 'FONT_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x912E0F1C (dec: -1859252452), parent name: 'FONT_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_88fake // hashcode: 0x0C6FD488 (dec: 208655496)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x78E6F0CD (dec: 2028400845), parent name: 'FONT_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x8874C0D2 (dec: -2005614382), parent name: 'FONT_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_89fake // hashcode: 0xC89A7944 (dec: -929400508)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x342AAEB0 (dec: 875212464), parent name: 'FONT_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x0D3DD969 (dec: 222157161), parent name: 'FONT_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xDE87FAB1 (dec: -561513807), parent name: 'FONT_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x51F8C7D5 (dec: 1375258581), parent name: 'FONT_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x470C7E3D (dec: 1192001085), parent name: 'FONT_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_90fake // hashcode: 0x722044D4 (dec: 1914717396)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xE72D06B4 (dec: -416479564), parent name: 'FONT_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xDE204216 (dec: -568311274), parent name: 'FONT_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_91fake // hashcode: 0x78F2084E (dec: 2029127758)
{
	short index;					// size=0, offset=0 //  hashcode: 0x50F1B08A (dec: 1358016650), parent name: 'FONT_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xE3579602 (dec: -480799230), parent name: 'FONT_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x002D142F (dec: 2954287), parent name: 'FONT_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x0683CE23 (dec: 109301283), parent name: 'FONT_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_92fake // hashcode: 0x4673473F (dec: 1181959999)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xE52F2AEB (dec: -449893653), parent name: 'FONT_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x815A90F0 (dec: -2124771088), parent name: 'FONT_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x9B29A0BC (dec: -1691770692), parent name: 'FONT_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_93fake // hashcode: 0x04CF3351 (dec: 80687953)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x9B3DB760 (dec: -1690454176), parent name: 'FONT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x12804DDF (dec: 310398431), parent name: 'FONT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xF373540A (dec: -210545654), parent name: 'FONT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x33252113 (dec: 858071315), parent name: 'FONT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xC97B0DAA (dec: -914682454), parent name: 'FONT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x645AD80A (dec: 1683675146), parent name: 'FONT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x76DF6DA8 (dec: 1994354088), parent name: 'FONT_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_94fake // hashcode: 0x68415C81 (dec: 1749113985)
{
	long index;  // size=0, offset=0 //  hashcode: 0x4567D179 (dec: 1164431737), parent name: 'FONT_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xD10C41E3 (dec: -787725853), parent name: 'FONT_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_95fake // hashcode: 0x692694E4 (dec: 1764136164)
{
	short type; // size=0, offset=0 //  hashcode: 0x9C44EADC (dec: -1673205028), parent name: 'FONT_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x09ABA8A5 (dec: 162244773), parent name: 'FONT_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_96fake // hashcode: 0x2913D437 (dec: 689165367)
{
	long time;   // size=0, offset=0 //  hashcode: 0x100D06F4 (dec: 269289204), parent name: 'FONT_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x4E108E41 (dec: 1309707841), parent name: 'FONT_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_97fake // hashcode: 0xDD9D0D6B (dec: -576909973)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xF752CB7A (dec: -145568902), parent name: 'FONT_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xA1110B5B (dec: -1592718501), parent name: 'FONT_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_98fake // hashcode: 0x71C8FDB4 (dec: 1908997556)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xEF55353B (dec: -279628485), parent name: 'FONT_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x520EECA2 (dec: 1376709794), parent name: 'FONT_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_99fake // hashcode: 0xC92EE307 (dec: -919674105)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x7056F856 (dec: 1884747862), parent name: 'FONT_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xA5DC94D6 (dec: -1512270634), parent name: 'FONT_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_100fake // hashcode: 0x5D146D3A (dec: 1561619770)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0xF5D999A8 (dec: -170288728), parent name: 'FONT_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x8D7143A0 (dec: -1921956960), parent name: 'FONT_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x6A892B8C (dec: 1787374476), parent name: 'FONT_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x1D235F6B (dec: 488857451), parent name: 'FONT_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_101fake // hashcode: 0xB5F34C8F (dec: -1242346353)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x4091664F (dec: 1083270735), parent name: 'FONT_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xD65FEF21 (dec: -698355935), parent name: 'FONT_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x068E3F1C (dec: 109985564), parent name: 'FONT_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xCFFD981D (dec: -805464035), parent name: 'FONT_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x4503783C (dec: 1157855292), parent name: 'FONT_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union FONT_102fake // Hashcode: 0x0A54B69F (dec: 173323935)
{
	struct FONT_79fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;	// size=24, offset=0
	struct FONT_80fake teleport;	 // size=16, offset=0
	struct FONT_81fake cameraValue;  // size=8, offset=0
	struct FONT_82fake miscValue;	// size=8, offset=0
	struct FONT_83fake logicValue;   // size=8, offset=0
	long timer;						 // size=0, offset=0
	long times;						 // size=0, offset=0
	long lightGroup;				 // size=0, offset=0
	long farPlane;					 // size=0, offset=0
	long cameraAdjust;				 // size=0, offset=0
	long cameraMode;				 // size=0, offset=0
	long cameraLock;				 // size=0, offset=0
	long cameraUnlock;				 // size=0, offset=0
	long cameraSmooth;				 // size=0, offset=0
	long cameraTimer;				 // size=0, offset=0
	struct FONT_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				 // size=0, offset=0
	long cameraRestore;				 // size=0, offset=0
	struct _BGObject *bgObject;		 // size=24, offset=0
	long value[2];					 // size=8, offset=0
	struct FONT_85fake sound;		 // size=12, offset=0
	void *intro;					 // size=0, offset=0
	long deathZ;					 // size=0, offset=0
	struct FONT_86fake dsignal;		 // size=8, offset=0
	void *mirror;					 // size=0, offset=0
	long fogNear;					 // size=0, offset=0
	long fogFar;					 // size=0, offset=0
	struct FONT_87fake gotoFrame;	// size=8, offset=0
	struct FONT_88fake changeModel;  // size=8, offset=0
	void *vmObject;					 // size=0, offset=0
	struct FONT_89fake logic;		 // size=8, offset=0
	void *callSignal;				 // size=0, offset=0
	struct _SVector offset;			 // size=8, offset=0
	struct Signal *gotoLabel;		 // size=0, offset=0
	struct Signal *gosubLabel;		 // size=0, offset=0
	struct FONT_90fake control;		 // size=8, offset=0
	struct FONT_91fake zSignal;		 // size=12, offset=0
	struct FONT_92fake StreamLevel;  // size=24, offset=0
	struct FONT_93fake shards;		 // size=12, offset=0
	struct FONT_94fake cameraSpline; // size=8, offset=0
	struct FONT_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				 // size=0, offset=0
	struct FONT_96fake introFX;		 // size=8, offset=0
	struct FONT_97fake introActive;  // size=8, offset=0
	struct FONT_98fake levelChange;  // size=18, offset=0
	long blendStart;				 // size=0, offset=0
	struct FONT_99fake setTimes;	 // size=8, offset=0
	struct FONT_100fake color;		 // size=4, offset=0
	struct FONT_101fake print;		 // size=12, offset=0
	long slideAngle;				 // size=0, offset=0
};

union FONT_103fake // Hashcode: 0x23C35D2F (dec: 600005935)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union FONT_108fake // Hashcode: 0x54881E01 (dec: 1418206721)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct FontTracker // hashcode: 0xE32D3F0A (dec: -483574006)
{
	struct FontChar font_buffer[256]; // size=1536, offset=0 //  hashcode: 0x5B3A1402 (dec: 1530532866), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long font_xpos;					  // size=0, offset=1536 //  hashcode: 0xB4B93EA7 (dec: -1262928217), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long font_ypos;					  // size=0, offset=1540 //  hashcode: 0x61FDCDBC (dec: 1644023228), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long font_buffIndex;			  // size=0, offset=1544 //  hashcode: 0x221A1D70 (dec: 572136816), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short font_tpage;				  // size=0, offset=1548 //  hashcode: 0x08EFDE55 (dec: 149937749), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short font_clut;				  // size=0, offset=1550 //  hashcode: 0x415BF029 (dec: 1096544297), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short font_vramU;				  // size=0, offset=1552 //  hashcode: 0x79916141 (dec: 2039570753), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short font_vramV;				  // size=0, offset=1554 //  hashcode: 0xA7E70399 (dec: -1478032487), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short font_width;				  // size=0, offset=1556 //  hashcode: 0xCDDFDFFB (dec: -840966149), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sprite_sort_push;			  // size=0, offset=1558 //  hashcode: 0x059028D6 (dec: 93333718), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short font_vramX;				  // size=0, offset=1560 //  hashcode: 0x0100C3A0 (dec: 16827296), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short font_vramY;				  // size=0, offset=1562 //  hashcode: 0x87B76FB5 (dec: -2018021451), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char color_global;				  // size=0, offset=1564 //  hashcode: 0x71D32916 (dec: 1909664022), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char color_local;				  // size=0, offset=1565 //  hashcode: 0x9FBB7B08 (dec: -1615103224), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_114fake // hashcode: 0xAF56B66C (dec: -1353271700)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x67BCBF1B (dec: 1740422939), parent name: 'FONT_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x3E59EB56 (dec: 1046080342), parent name: 'FONT_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x316495C8 (dec: 828675528), parent name: 'FONT_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xA18AB809 (dec: -1584744439), parent name: 'FONT_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x587883DA (dec: 1484293082), parent name: 'FONT_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x7FDF8294 (dec: 2145354388), parent name: 'FONT_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x8764E0CE (dec: -2023431986), parent name: 'FONT_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_115fake // hashcode: 0xA3BB740D (dec: -1547996147)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x8FDBA05A (dec: -1881431974), parent name: 'FONT_115fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x0532F52A (dec: 87225642), parent name: 'FONT_115fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xCEAA63A0 (dec: -827694176), parent name: 'FONT_115fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_116fake // hashcode: 0xB379284F (dec: -1283905457)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x401B00FA (dec: 1075511546), parent name: 'FONT_116fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x37538E96 (dec: 928222870), parent name: 'FONT_116fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xBFAD5EE6 (dec: -1079157018), parent name: 'FONT_116fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x669D4C84 (dec: 1721584772), parent name: 'FONT_116fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xC35E45CE (dec: -1017231922), parent name: 'FONT_116fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_117fake // hashcode: 0xF9C0702F (dec: -104828881)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x1FF5297E (dec: 536160638), parent name: 'FONT_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0xFD9A7CB0 (dec: -40207184), parent name: 'FONT_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0xD926B74E (dec: -651774130), parent name: 'FONT_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x6F63A007 (dec: 1868800007), parent name: 'FONT_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xE886D0BE (dec: -393817922), parent name: 'FONT_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_118fake // hashcode: 0x5664C5CE (dec: 1449444814)
{
	struct FONT_114fake Cinematic; // size=28, offset=0 //  hashcode: 0x8A4D82A3 (dec: -1974631773), parent name: 'FONT_118fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct FONT_115fake Idle;	  // size=20, offset=28 //  hashcode: 0x6F8494AF (dec: 1870959791), parent name: 'FONT_118fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct FONT_116fake Behind;	// size=28, offset=48 //  hashcode: 0x0C5C900C (dec: 207392780), parent name: 'FONT_118fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct FONT_117fake Follow;	// size=20, offset=76 //  hashcode: 0x88972E6E (dec: -2003358098), parent name: 'FONT_118fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_185fake // hashcode: 0x05FEFFF7 (dec: 100597751)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x794435B5 (dec: 2034513333), parent name: 'FONT_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x1B5E6EB3 (dec: 459173555), parent name: 'FONT_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FONT_186fake // hashcode: 0x5D8EF9C0 (dec: 1569651136)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x90ED4D4F (dec: -1863496369), parent name: 'FONT_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x25EEA59C (dec: 636396956), parent name: 'FONT_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x2FB6DC36 (dec: 800513078), parent name: 'FONT_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x3630B14B (dec: 909160779), parent name: 'FONT_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0xA0B76E43 (dec: -1598591421), parent name: 'FONT_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x2B244A13 (dec: 723798547), parent name: 'FONT_186fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union FONT_187fake // Hashcode: 0x27623F1B (dec: 660750107)
{
	struct FONT_185fake flame; // size=8, offset=0
	struct FONT_186fake phys;  // size=12, offset=0
};

union FONT_213fake // Hashcode: 0x740A6D3C (dec: 1946840380)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union FONT_231fake // Hashcode: 0xC1E3D6C8 (dec: -1042032952)
{
	struct _StreamUnit *streamUnit;		 // size=64, offset=0
	struct _ObjectTracker *streamObject; // size=36, offset=0
	struct _ButtonTexture *button;		 // size=0, offset=0
};

struct font_color_t // hashcode: 0x5F515B79 (dec: 1599167353)
{
	int r; // size=0, offset=0 //  hashcode: 0xEC7E46C3 (dec: -327268669), parent name: 'font_color_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int g; // size=0, offset=4 //  hashcode: 0x8B5F3965 (dec: -1956693659), parent name: 'font_color_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int b; // size=0, offset=8 //  hashcode: 0xD71B4A20 (dec: -686077408), parent name: 'font_color_t', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FontPos // hashcode: 0x0084D7DD (dec: 8706013)
{
	char x; // size=0, offset=0 //  hashcode: 0xDDE4C1A3 (dec: -572210781), parent name: 'FontPos', parent hashcode: 0xFFFFFFFF (dec: -1)
	char y; // size=0, offset=1 //  hashcode: 0x291BFCEC (dec: 689700076), parent name: 'FontPos', parent hashcode: 0xFFFFFFFF (dec: -1)
	char w; // size=0, offset=2 //  hashcode: 0xF5DBD91A (dec: -170141414), parent name: 'FontPos', parent hashcode: 0xFFFFFFFF (dec: -1)
	char h; // size=0, offset=3 //  hashcode: 0xADC95CEF (dec: -1379312401), parent name: 'FontPos', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct POLY_FT4 POLY_FT4;

typedef struct FontTracker FontTracker;

typedef struct font_color_t font_color_t;

typedef struct FontPos FontPos;

extern void FONT_MakeSpecialFogClut(int x, int y); // 0x8002CB74

extern void FONT_Init(); // 0x8002CBF8

extern void FONT_ReloadFont(); // 0x8002CD18

extern void FONT_DrawChar(struct FontChar *fontChar); // 0x8002CD7C

extern long FONT_Get2DImageIndex(unsigned char c); // 0x8002CDB0

extern void drawChar2DPoly(long fpi, long x, long y); // 0x8002CDC8

extern void FONT_DrawChar2D(unsigned char c, long x, long y); // 0x8002CFC8

extern long FONT_CharSpacing(char c, long fontXSize); // 0x8002D1FC

extern void FONT_AddCharToBuffer(char c, long x, long y); // 0x8002D340

extern void FONT_Print(char *fmt); // 0x8002D3AC

extern void FONT_Print2(char *fmt); // 0x8002D43C

extern int FONT_GetStringWidth(char *str); // 0x8002D48C

extern void FONT_Flush(); // 0x8002D500

extern void FONT_SetCursor(short x, short y); // 0x8002D590

extern void FONT_VaReallyPrint(char *fmt, void *ap); // 0x8002D5B0

extern void FONT_FontPrintCentered(char *text, long y); // 0x8002D740

extern void FONT_SetColorIndex(int color); // 0x8002D798

extern void FONT_SetColorIndexCol(int color, int r, int g, int b); // 0x8002D7A4

#endif
