#ifndef DEBUG_H
#define DEBUG_H

extern struct DebugMenuLine AIMenu[1]; // offset 0x800CFB94

extern struct DebugMenuLine BossAreasMenu[1]; // offset 0x800CFB7C

extern struct DebugMenuLine cameraMenu[1]; // offset 0x800CFCE0

static int cem_cursor_width; // offset 0x800CDCEC

static int cem_item_leading; // offset 0x800CDCF8

static int cem_line_leading; // offset 0x800CDCF4

static int cem_line_width; // offset 0x800CDCF0

static int cem_x_base; // offset 0x800CDCE4

static int cem_y_base; // offset 0x800CDCE8

static long cheatCodeLastCommand; // offset 0x800CDB44

static long CheatKeyMap[10]; // offset 0x800CDB48

extern struct DebugMenuLine *currentMenu; // offset 0x800CDB3C

static struct debug_dispatch_t debug_dispatch_table[5]; // offset 0x800C84D8

extern struct DebugMenuLine debugForgedAbilitiesMenu[1]; // offset 0x800CFBF4

extern struct DebugMenuLine debugGlyphAbilitiesMenu[1]; // offset 0x800CFBC4

extern struct DebugMenuLine debugHealthSystemMenu[1]; // offset 0x800CFC3C

extern struct DebugMenuLine debugImbueSoulReaverMenu[1]; // offset 0x800CFD28

static long debugMenuChoice; // offset 0x800CDB40

extern struct DebugMenuLine debugRazielMenu[1]; // offset 0x800CFD4C

extern struct DebugMenuLine debugSoundMenu[1]; // offset 0x800CFBAC

extern struct DebugMenuLine debugSpecialAbilitiesMenu[1]; // offset 0x800CFC0C

extern struct DebugMenuLine eventMenu[1]; // offset 0x800CFB64

extern struct DebugMenuLine fogMenu[1]; // offset 0x800CFC58

static struct GameCheat GameCheats[23]; // offset 0x800CDB70

extern struct DebugMenuLine goodiesMenu[1]; // offset 0x800CFBDC

extern struct DebugMenuLine level2SelectMenu[1]; // offset 0x800CFD10

extern struct DebugMenuLine levelSelectMenu[1]; // offset 0x800CFCF8

static char mainFormatString[20]; // offset 0x800CDACC

extern struct DebugMenuLine mainMenu[8]; // offset 0x800C8418

extern struct DebugMenuLine mcardMenu[1]; // offset 0x800CFC24

static char pauseFormatString[20]; // offset 0x800CDAB8

extern struct DebugMenuLine pauseMenu[1]; // offset 0x800CFCC8

extern struct DebugMenuLine saveMenu[1]; // offset 0x800CFC70

extern struct DebugMenuLine standardMenu[1]; // offset 0x800CFCB0

extern struct DebugMenuLine statsMenu[1]; // offset 0x800CFC98

static char *the_format_string; // offset 0x800CDAE0

extern struct DebugMenuLine *the_previous_menu; // offset 0x800CDCE0

struct POLY_F4 // hashcode: 0xE2AC295D (dec: -492033699)
{
	unsigned long tag;  // size=0, offset=0 //  hashcode: 0x3A1ED5A5 (dec: 975099301), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;   // size=0, offset=4 //  hashcode: 0x6C46B9C5 (dec: 1816574405), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;   // size=0, offset=5 //  hashcode: 0xF44CC904 (dec: -196294396), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;   // size=0, offset=6 //  hashcode: 0xF54A3033 (dec: -179687373), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code; // size=0, offset=7 //  hashcode: 0xB3ED72A1 (dec: -1276284255), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			// size=0, offset=8 //  hashcode: 0x0A0E8504 (dec: 168723716), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			// size=0, offset=10 //  hashcode: 0xD678DA29 (dec: -696722903), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			// size=0, offset=12 //  hashcode: 0x79D93CF1 (dec: 2044280049), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			// size=0, offset=14 //  hashcode: 0xA8DD9D2F (dec: -1461871313), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;			// size=0, offset=16 //  hashcode: 0x1C3902A7 (dec: 473498279), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;			// size=0, offset=18 //  hashcode: 0x3D323DD1 (dec: 1026702801), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x3;			// size=0, offset=20 //  hashcode: 0xFC27D558 (dec: -64498344), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y3;			// size=0, offset=22 //  hashcode: 0x8C784AAE (dec: -1938273618), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_115fake // hashcode: 0x8FDB6F2D (dec: -1881444563)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x5B851A5E (dec: 1535449694), parent name: 'DEBUG_115fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0xED297B70 (dec: -316048528), parent name: 'DEBUG_115fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_116fake // hashcode: 0x75F37FC9 (dec: 1978892233)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x476F4489 (dec: 1198474377), parent name: 'DEBUG_116fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x74D96F07 (dec: 1960406791), parent name: 'DEBUG_116fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_117fake // hashcode: 0x094BC0F4 (dec: 155959540)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xC91FD20A (dec: -920661494), parent name: 'DEBUG_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xDE2252B3 (dec: -568175949), parent name: 'DEBUG_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union DEBUG_118fake // Hashcode: 0x841D74D1 (dec: -2078444335)
{
	struct DEBUG_115fake callback; // size=8, offset=0
	struct DEBUG_116fake vector;   // size=12, offset=0
	struct DEBUG_117fake quat;	 // size=16, offset=0
};

struct _SmallRotation // hashcode: 0xB9CA5EE3 (dec: -1177919773)
{
	short x; // size=0, offset=0 //  hashcode: 0x6E2F6572 (dec: 1848599922), parent name: '_SmallRotation', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0xB3A85AA4 (dec: -1280812380), parent name: '_SmallRotation', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z; // size=0, offset=4 //  hashcode: 0x22FB259D (dec: 586884509), parent name: '_SmallRotation', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union DEBUG_119fake // Hashcode: 0xED3B4C32 (dec: -314880974)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union DEBUG_120fake // Hashcode: 0x8F165569 (dec: -1894361751)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct DEBUG_121fake // hashcode: 0xBF9D9024 (dec: -1080192988)
{
	union DEBUG_120fake size; // size=4, offset=0 //  hashcode: 0x5B0AA845 (dec: 1527425093), parent name: 'DEBUG_121fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_122fake // hashcode: 0xCBB59C57 (dec: -877290409)
{
	short x;				// size=0, offset=0 //  hashcode: 0xA472CE75 (dec: -1535979915), parent name: 'DEBUG_122fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xD2AC2252 (dec: -760470958), parent name: 'DEBUG_122fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xA94D8E4C (dec: -1454535092), parent name: 'DEBUG_122fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xE845C5CA (dec: -398080566), parent name: 'DEBUG_122fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x69370082 (dec: 1765212290), parent name: 'DEBUG_122fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_123fake // hashcode: 0xA10DE547 (dec: -1592924857)
{
	long index; // size=0, offset=0 //  hashcode: 0x646D7C8E (dec: 1684896910), parent name: 'DEBUG_123fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x6B73DC71 (dec: 1802755185), parent name: 'DEBUG_123fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_124fake // hashcode: 0xE5D984D1 (dec: -438729519)
{
	long index; // size=0, offset=0 //  hashcode: 0xF315AE33 (dec: -216682957), parent name: 'DEBUG_124fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xD146DC84 (dec: -783885180), parent name: 'DEBUG_124fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_125fake // hashcode: 0x43D12F13 (dec: 1137782547)
{
	long index; // size=0, offset=0 //  hashcode: 0xBB037F41 (dec: -1157398719), parent name: 'DEBUG_125fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x7069B7D9 (dec: 1885976537), parent name: 'DEBUG_125fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_126fake // hashcode: 0xF00F2352 (dec: -267443374)
{
	long time;  // size=0, offset=0 //  hashcode: 0xAA5893FC (dec: -1437035524), parent name: 'DEBUG_126fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x2A2D87B1 (dec: 707626929), parent name: 'DEBUG_126fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_127fake // hashcode: 0xC0CDAE37 (dec: -1060262345)
{
	long action;   // size=0, offset=0 //  hashcode: 0xB2972478 (dec: -1298717576), parent name: 'DEBUG_127fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xDE5CD999 (dec: -564340327), parent name: 'DEBUG_127fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_128fake // hashcode: 0x256787E2 (dec: 627541986)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xA8CDF756 (dec: -1462896810), parent name: 'DEBUG_128fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x04FB4B0D (dec: 83577613), parent name: 'DEBUG_128fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_129fake // hashcode: 0x216F2194 (dec: 560931220)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x973F0B84 (dec: -1757475964), parent name: 'DEBUG_129fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x808B8B2D (dec: -2138338515), parent name: 'DEBUG_129fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_130fake // hashcode: 0x6926D850 (dec: 1764153424)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xCF8CB732 (dec: -812861646), parent name: 'DEBUG_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x112AFC7B (dec: 288029819), parent name: 'DEBUG_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_131fake // hashcode: 0xE0CC02D8 (dec: -523500840)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x77263045 (dec: 1998991429), parent name: 'DEBUG_131fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x09A94B85 (dec: 162089861), parent name: 'DEBUG_131fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xAE5EF11C (dec: -1369509604), parent name: 'DEBUG_131fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x88E7E941 (dec: -1998067391), parent name: 'DEBUG_131fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x0F3CA078 (dec: 255631480), parent name: 'DEBUG_131fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_132fake // hashcode: 0x3EAE3B70 (dec: 1051605872)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x48663D1A (dec: 1214659866), parent name: 'DEBUG_132fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xDBB3B62B (dec: -608979413), parent name: 'DEBUG_132fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_133fake // hashcode: 0xE0B97C3D (dec: -524714947)
{
	short index;					// size=0, offset=0 //  hashcode: 0x94258FFB (dec: -1809477637), parent name: 'DEBUG_133fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x0526ECAD (dec: 86437037), parent name: 'DEBUG_133fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x113A7A73 (dec: 289045107), parent name: 'DEBUG_133fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x6060F382 (dec: 1616966530), parent name: 'DEBUG_133fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_134fake // hashcode: 0x4211C131 (dec: 1108459825)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x56C53BD4 (dec: 1455766484), parent name: 'DEBUG_134fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x3F148D28 (dec: 1058311464), parent name: 'DEBUG_134fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xA613D324 (dec: -1508650204), parent name: 'DEBUG_134fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_135fake // hashcode: 0x2E077AFF (dec: 772242175)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x5DF2287F (dec: 1576151167), parent name: 'DEBUG_135fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x98286370 (dec: -1742183568), parent name: 'DEBUG_135fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xA7E6D5D7 (dec: -1478044201), parent name: 'DEBUG_135fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xE770A73F (dec: -412047553), parent name: 'DEBUG_135fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x9E8654E4 (dec: -1635363612), parent name: 'DEBUG_135fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x4F41365B (dec: 1329673819), parent name: 'DEBUG_135fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xC16CB627 (dec: -1049840089), parent name: 'DEBUG_135fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_136fake // hashcode: 0x9AAFD05E (dec: -1699753890)
{
	long index;  // size=0, offset=0 //  hashcode: 0xDD028059 (dec: -587038631), parent name: 'DEBUG_136fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xCC047A2B (dec: -872121813), parent name: 'DEBUG_136fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_137fake // hashcode: 0x708DDE15 (dec: 1888345621)
{
	short type; // size=0, offset=0 //  hashcode: 0xD9CA217E (dec: -641064578), parent name: 'DEBUG_137fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x5B7C50E5 (dec: 1534873829), parent name: 'DEBUG_137fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_138fake // hashcode: 0x1F833B5B (dec: 528694107)
{
	long time;   // size=0, offset=0 //  hashcode: 0x591E4533 (dec: 1495156019), parent name: 'DEBUG_138fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x727D9EC4 (dec: 1920835268), parent name: 'DEBUG_138fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_139fake // hashcode: 0x6A0670F8 (dec: 1778807032)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x6F78F819 (dec: 1870198809), parent name: 'DEBUG_139fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x3002532A (dec: 805458730), parent name: 'DEBUG_139fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_140fake // hashcode: 0xCFE6659D (dec: -806984291)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xD4C5D3D4 (dec: -725232684), parent name: 'DEBUG_140fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x2554314F (dec: 626274639), parent name: 'DEBUG_140fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_141fake // hashcode: 0x85CE3CD1 (dec: -2050081583)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xAC5C7FF1 (dec: -1403224079), parent name: 'DEBUG_141fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xFDCBAA09 (dec: -36984311), parent name: 'DEBUG_141fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_142fake // hashcode: 0xA9708689 (dec: -1452243319)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x33ACEEAC (dec: 866971308), parent name: 'DEBUG_142fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xC43F1E57 (dec: -1002496425), parent name: 'DEBUG_142fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x9089D040 (dec: -1870016448), parent name: 'DEBUG_142fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xA06EF45C (dec: -1603341220), parent name: 'DEBUG_142fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_143fake // hashcode: 0x03C05AFC (dec: 62937852)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xBC4FE971 (dec: -1135613583), parent name: 'DEBUG_143fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x88832826 (dec: -2004670426), parent name: 'DEBUG_143fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xD33E9C5B (dec: -750871461), parent name: 'DEBUG_143fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x0D88E4D0 (dec: 227075280), parent name: 'DEBUG_143fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x268D4800 (dec: 646793216), parent name: 'DEBUG_143fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union DEBUG_144fake // Hashcode: 0x66DB8E80 (dec: 1725664896)
{
	struct DEBUG_121fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	  // size=24, offset=0
	struct DEBUG_122fake teleport;	 // size=16, offset=0
	struct DEBUG_123fake cameraValue;  // size=8, offset=0
	struct DEBUG_124fake miscValue;	// size=8, offset=0
	struct DEBUG_125fake logicValue;   // size=8, offset=0
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
	struct DEBUG_126fake cameraShake;  // size=8, offset=0
	long cameraSave;				   // size=0, offset=0
	long cameraRestore;				   // size=0, offset=0
	struct _BGObject *bgObject;		   // size=24, offset=0
	long value[2];					   // size=8, offset=0
	struct DEBUG_127fake sound;		   // size=12, offset=0
	void *intro;					   // size=0, offset=0
	long deathZ;					   // size=0, offset=0
	struct DEBUG_128fake dsignal;	  // size=8, offset=0
	void *mirror;					   // size=0, offset=0
	long fogNear;					   // size=0, offset=0
	long fogFar;					   // size=0, offset=0
	struct DEBUG_129fake gotoFrame;	// size=8, offset=0
	struct DEBUG_130fake changeModel;  // size=8, offset=0
	void *vmObject;					   // size=0, offset=0
	struct DEBUG_131fake logic;		   // size=8, offset=0
	void *callSignal;				   // size=0, offset=0
	struct _SVector offset;			   // size=8, offset=0
	struct Signal *gotoLabel;		   // size=0, offset=0
	struct Signal *gosubLabel;		   // size=0, offset=0
	struct DEBUG_132fake control;	  // size=8, offset=0
	struct DEBUG_133fake zSignal;	  // size=12, offset=0
	struct DEBUG_134fake StreamLevel;  // size=24, offset=0
	struct DEBUG_135fake shards;	   // size=12, offset=0
	struct DEBUG_136fake cameraSpline; // size=8, offset=0
	struct DEBUG_137fake screenWipe;   // size=4, offset=0
	long voiceSitId;				   // size=0, offset=0
	struct DEBUG_138fake introFX;	  // size=8, offset=0
	struct DEBUG_139fake introActive;  // size=8, offset=0
	struct DEBUG_140fake levelChange;  // size=18, offset=0
	long blendStart;				   // size=0, offset=0
	struct DEBUG_141fake setTimes;	 // size=8, offset=0
	struct DEBUG_142fake color;		   // size=4, offset=0
	struct DEBUG_143fake print;		   // size=12, offset=0
	long slideAngle;				   // size=0, offset=0
};

union DEBUG_145fake // Hashcode: 0x4D2E85B5 (dec: 1294894517)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union DEBUG_150fake // Hashcode: 0x3F4E349F (dec: 1062089887)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct EventPointers // hashcode: 0x3787E212 (dec: 931652114)
{
	long numPuzzles;				  // size=0, offset=0 //  hashcode: 0x49AB248E (dec: 1235952782), parent name: 'EventPointers', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Event(*eventInstances[1]); // size=4, offset=4 //  hashcode: 0x4DBDCD5F (dec: 1304284511), parent name: 'EventPointers', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_152fake // hashcode: 0xDCB0D147 (dec: -592391865)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x7C3EF3F8 (dec: 2084500472), parent name: 'DEBUG_152fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xE10B34A3 (dec: -519359325), parent name: 'DEBUG_152fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x75932938 (dec: 1972578616), parent name: 'DEBUG_152fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x0DDFF7D7 (dec: 232781783), parent name: 'DEBUG_152fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x37F483BA (dec: 938771386), parent name: 'DEBUG_152fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x26C4ECE8 (dec: 650439912), parent name: 'DEBUG_152fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xF1E68999 (dec: -236549735), parent name: 'DEBUG_152fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_153fake // hashcode: 0x1E0AACB1 (dec: 504016049)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0xADDC96CE (dec: -1378052402), parent name: 'DEBUG_153fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xAD9DE298 (dec: -1382161768), parent name: 'DEBUG_153fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xCE5A11F7 (dec: -832957961), parent name: 'DEBUG_153fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_154fake // hashcode: 0x4ACC8F50 (dec: 1254920016)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x541A87AA (dec: 1411024810), parent name: 'DEBUG_154fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x644FDFBB (dec: 1682956219), parent name: 'DEBUG_154fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xD241F153 (dec: -767430317), parent name: 'DEBUG_154fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x1C5528FD (dec: 475343101), parent name: 'DEBUG_154fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x24572836 (dec: 609691702), parent name: 'DEBUG_154fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_155fake // hashcode: 0x79479CFD (dec: 2034736381)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x6D89FE26 (dec: 1837760038), parent name: 'DEBUG_155fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0xD9A5FF6E (dec: -643432594), parent name: 'DEBUG_155fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0xBF4615F2 (dec: -1085925902), parent name: 'DEBUG_155fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xEC075807 (dec: -335063033), parent name: 'DEBUG_155fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x30DC54A2 (dec: 819745954), parent name: 'DEBUG_155fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_156fake // hashcode: 0xD437FF19 (dec: -734527719)
{
	struct DEBUG_152fake Cinematic; // size=28, offset=0 //  hashcode: 0x43B192C5 (dec: 1135710917), parent name: 'DEBUG_156fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DEBUG_153fake Idle;		// size=20, offset=28 //  hashcode: 0x035166CD (dec: 55666381), parent name: 'DEBUG_156fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DEBUG_154fake Behind;	// size=28, offset=48 //  hashcode: 0x84704688 (dec: -2073016696), parent name: 'DEBUG_156fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DEBUG_155fake Follow;	// size=20, offset=76 //  hashcode: 0x49B9FE37 (dec: 1236926007), parent name: 'DEBUG_156fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct Camera // hashcode: 0x0670C20F (dec: 108053007)
{
	struct _CameraCore_Type core;				   // size=224, offset=0 //  hashcode: 0xB71B3EC2 (dec: -1222951230), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long shake;									   // size=0, offset=224 //  hashcode: 0x1C9EF1D6 (dec: 480178646), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short shakeFrame;							   // size=0, offset=228 //  hashcode: 0x4BC89F68 (dec: 1271439208), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short shakeScale;							   // size=0, offset=230 //  hashcode: 0x37C2D6D9 (dec: 935515865), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;									   // size=0, offset=232 //  hashcode: 0xEC14ECF9 (dec: -334172935), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long lock;									   // size=0, offset=236 //  hashcode: 0x2DCAF4AA (dec: 768275626), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short mode;									   // size=0, offset=240 //  hashcode: 0x70608F8E (dec: 1885376398), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short state;								   // size=0, offset=242 //  hashcode: 0x9CC6B8A2 (dec: -1664698206), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short posState;								   // size=0, offset=244 //  hashcode: 0xDCE24ECC (dec: -589148468), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rotState;								   // size=0, offset=246 //  hashcode: 0x47D4E55E (dec: 1205134686), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short tiltState;							   // size=0, offset=248 //  hashcode: 0x3F92D74B (dec: 1066587979), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short distanceState;						   // size=0, offset=250 //  hashcode: 0x360A6442 (dec: 906650690), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lagZ;									   // size=0, offset=252 //  hashcode: 0x3928868C (dec: 958957196), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short tilt;									   // size=0, offset=254 //  hashcode: 0xF749C5D8 (dec: -146160168), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position focusPoint;				   // size=6, offset=256 //  hashcode: 0x18245CA1 (dec: 405036193), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short focusDistance;						   // size=0, offset=262 //  hashcode: 0x39F98172 (dec: 972652914), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *focusInstance;			   // size=616, offset=264 //  hashcode: 0x47F453E1 (dec: 1207194593), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position oldFocusInstancePos;		   // size=6, offset=268 //  hashcode: 0x3E9EDD49 (dec: 1050598729), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position newFocusInstancePos;		   // size=6, offset=274 //  hashcode: 0x7ECD076B (dec: 2127365995), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation oldFocusInstanceRot;		   // size=8, offset=280 //  hashcode: 0x9F92ED3A (dec: -1617760966), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation newFocusInstanceRot;		   // size=8, offset=288 //  hashcode: 0xAE8DF9E7 (dec: -1366427161), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector focusInstanceVelVec;		   // size=8, offset=296 //  hashcode: 0x401C4CFD (dec: 1075596541), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position focusLeadPivot;			   // size=6, offset=304 //  hashcode: 0x3745EF27 (dec: 927330087), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position focusOffset;				   // size=6, offset=310 //  hashcode: 0xA9FF70D2 (dec: -1442877230), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation focusRotation;				   // size=8, offset=316 //  hashcode: 0x3EBA90A1 (dec: 1052414113), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short tiltVel;								   // size=0, offset=324 //  hashcode: 0x8557FDFB (dec: -2057830917), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short tiltAccl;								   // size=0, offset=326 //  hashcode: 0x3CBC1700 (dec: 1018959616), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector positionVel;				   // size=8, offset=328 //  hashcode: 0x6AEBAB26 (dec: 1793829670), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector positionAccl;				   // size=8, offset=336 //  hashcode: 0x60585723 (dec: 1616402211), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector focusPointVel;				   // size=8, offset=344 //  hashcode: 0x15B08035 (dec: 363888693), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector focusPointAccl;				   // size=8, offset=352 //  hashcode: 0x50A539B6 (dec: 1353005494), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short focusDistanceVel;						   // size=0, offset=360 //  hashcode: 0x9E19988C (dec: -1642489716), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short focusDistanceAccl;					   // size=0, offset=362 //  hashcode: 0x456F6EE2 (dec: 1164930786), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector focusRotVel;				   // size=8, offset=364 //  hashcode: 0xE4CF75FB (dec: -456165893), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector focusRotAccl;				   // size=8, offset=372 //  hashcode: 0xD8A0DB47 (dec: -660546745), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector maxFocusVel;				   // size=8, offset=380 //  hashcode: 0x08478D36 (dec: 138906934), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector rotationVel;				   // size=8, offset=388 //  hashcode: 0xCE63F2E8 (dec: -832310552), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector rotationAccl;				   // size=8, offset=396 //  hashcode: 0x79F7325E (dec: 2046243422), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxVel;								   // size=0, offset=404 //  hashcode: 0x7346037B (dec: 1933968251), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxRot;								   // size=0, offset=406 //  hashcode: 0x53177DF1 (dec: 1394048497), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position targetPos;					   // size=6, offset=408 //  hashcode: 0x35A555D7 (dec: 900027863), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short targetTilt;							   // size=0, offset=414 //  hashcode: 0x081097A8 (dec: 135305128), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation targetRotation;			   // size=8, offset=416 //  hashcode: 0x32C0A0C5 (dec: 851484869), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short targetFocusDistance;					   // size=0, offset=424 //  hashcode: 0x75AB15D3 (dec: 1974146515), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position targetFocusPoint;			   // size=6, offset=426 //  hashcode: 0xED70C4BB (dec: -311376709), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short collisionTargetFocusDistance;			   // size=0, offset=432 //  hashcode: 0x2C156FA7 (dec: 739602343), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation targetFocusRotation;		   // size=8, offset=434 //  hashcode: 0x952ED195 (dec: -1792093803), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short tfaceTilt;							   // size=0, offset=442 //  hashcode: 0x5DD9405B (dec: 1574518875), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation collisionTargetFocusRotation; // size=8, offset=444 //  hashcode: 0x23EBBECA (dec: 602652362), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short smooth;								   // size=0, offset=452 //  hashcode: 0x9374CA20 (dec: -1821062624), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _CameraKey *cameraKey;				   // size=24, offset=456 //  hashcode: 0x8C872914 (dec: -1937299180), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Sphere focusSphere;					   // size=12, offset=460 //  hashcode: 0x5AC83249 (dec: 1523069513), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Sphere smallBaseSphere;				   // size=12, offset=472 //  hashcode: 0x4F1F228B (dec: 1327440523), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Sphere posSphere;					   // size=12, offset=484 //  hashcode: 0xCE8142E6 (dec: -830389530), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lookTimer;							   // size=0, offset=496 //  hashcode: 0x94A51721 (dec: -1801119967), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lookSavedMode;						   // size=0, offset=498 //  hashcode: 0x0F13A83B (dec: 252946491), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short presetIndex;							   // size=0, offset=500 //  hashcode: 0x6BA97F6D (dec: 1806270317), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short presetFocusDistance[3];				   // size=6, offset=502 //  hashcode: 0xB775384D (dec: -1217054643), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long minFocusDistance;						   // size=0, offset=508 //  hashcode: 0xE4CADCA9 (dec: -456467287), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxFocusDistance;						   // size=0, offset=512 //  hashcode: 0x97EFC287 (dec: -1745894777), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long minTilt;								   // size=0, offset=516 //  hashcode: 0x74EFB39D (dec: 1961866141), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxTilt;								   // size=0, offset=520 //  hashcode: 0x0556C805 (dec: 89573381), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long pad[3];								   // size=12, offset=524 //  hashcode: 0x40458686 (dec: 1078298246), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long minXYDist;								   // size=0, offset=536 //  hashcode: 0x57C53CA5 (dec: 1472543909), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxXYDist;								   // size=0, offset=540 //  hashcode: 0x9CE3FCC0 (dec: -1662780224), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long oppositeError;							   // size=0, offset=544 //  hashcode: 0x9F18649F (dec: -1625791329), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long tempsplinePointAhead;					   // size=0, offset=548 //  hashcode: 0xEE69B122 (dec: -295063262), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long noTeleport;							   // size=0, offset=552 //  hashcode: 0xD7BC9591 (dec: -675506799), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistanceList[3][3];				   // size=36, offset=556 //  hashcode: 0xB1482F87 (dec: -1320669305), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long tiltList[3][3];						   // size=36, offset=592 //  hashcode: 0xB68E94FA (dec: -1232169734), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long cineControl;							   // size=0, offset=628 //  hashcode: 0xB56E575B (dec: -1251059877), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short stack;								   // size=0, offset=632 //  hashcode: 0x02D8B44E (dec: 47756366), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short targetStack;							   // size=0, offset=634 //  hashcode: 0x0D89E34B (dec: 227140427), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long savedMode[3];							   // size=12, offset=636 //  hashcode: 0x388C6CF8 (dec: 948727032), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long savedTargetFocusDistance[3];			   // size=12, offset=648 //  hashcode: 0x338E8CFE (dec: 864980222), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation savedFocusRotation;		   // size=8, offset=660 //  hashcode: 0xCF29CEAB (dec: -819343701), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short savedFocusDistance;					   // size=0, offset=668 //  hashcode: 0x7F1EB735 (dec: 2132719413), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short signalFocusDistance;					   // size=0, offset=670 //  hashcode: 0x1D221C08 (dec: 488774664), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SavedCinematic savedCinematic[3];	  // size=336, offset=672 //  hashcode: 0x757F4CE8 (dec: 1971277032), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation savedfocusRotation;		   // size=8, offset=1008 //  hashcode: 0xCAC1F444 (dec: -893258684), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position signalPos;					   // size=6, offset=1016 //  hashcode: 0xA8C4292E (dec: -1463539410), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad11;								   // size=0, offset=1022 //  hashcode: 0xEBF5A869 (dec: -336222103), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation signalRot;					   // size=8, offset=1024 //  hashcode: 0xC048E250 (dec: -1068965296), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short forced_movement;						   // size=0, offset=1032 //  hashcode: 0x49A024F3 (dec: 1235231987), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short last_forced_movement;					   // size=0, offset=1034 //  hashcode: 0x5BA99C98 (dec: 1537842328), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rotDirection;							   // size=0, offset=1036 //  hashcode: 0xA800FFA8 (dec: -1476329560), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long lastModTime;					   // size=0, offset=1040 //  hashcode: 0x73DAD159 (dec: 1943720281), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation lookRot;					   // size=8, offset=1044 //  hashcode: 0x5F9D6287 (dec: 1604149895), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *Spline00;				   // size=0, offset=1052 //  hashcode: 0x6547B7DE (dec: 1699198942), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *Spline01;				   // size=0, offset=1056 //  hashcode: 0x2601BFFF (dec: 637648895), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DEBUG_156fake data;					   // size=96, offset=1060 //  hashcode: 0x8C01F486 (dec: -1946028922), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long cuckooTimer;							   // size=0, offset=1156 //  hashcode: 0x0CA6C5A1 (dec: 212256161), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short teleportZRot;							   // size=0, offset=1160 //  hashcode: 0x6C46F9E0 (dec: 1816590816), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short extraZRot;							   // size=0, offset=1162 //  hashcode: 0xC508003D (dec: -989331395), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short extraXRot;							   // size=0, offset=1164 //  hashcode: 0x5C75856E (dec: 1551205742), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short leftTimer;							   // size=0, offset=1166 //  hashcode: 0x8C9E23EF (dec: -1935793169), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rightTimer;							   // size=0, offset=1168 //  hashcode: 0xEB56484A (dec: -346666934), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short collideRotControl;					   // size=0, offset=1170 //  hashcode: 0xE88E52E6 (dec: -393325850), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short collision_lastPush;					   // size=0, offset=1172 //  hashcode: 0x8CA271EC (dec: -1935511060), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short collision_timer;						   // size=0, offset=1174 //  hashcode: 0xF59D6FB4 (dec: -174231628), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long prev_instance_mode;			   // size=0, offset=1176 //  hashcode: 0xE15BA6F0 (dec: -514087184), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long instance_mode;				   // size=0, offset=1180 //  hashcode: 0x74E9B06A (dec: 1961472106), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long instance_xyvel;						   // size=0, offset=1184 //  hashcode: 0x3F9F2BDA (dec: 1067396058), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long instance_prev_xyvel;					   // size=0, offset=1188 //  hashcode: 0x6DF15B40 (dec: 1844534080), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position real_focuspoint;			   // size=6, offset=1192 //  hashcode: 0xF9A7AAB6 (dec: -106452298), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short always_rotate_flag;					   // size=0, offset=1198 //  hashcode: 0x2E0C5F86 (dec: 772562822), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short follow_flag;							   // size=0, offset=1200 //  hashcode: 0x8E258268 (dec: -1910144408), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short actual_x_rot;							   // size=0, offset=1202 //  hashcode: 0xE0704148 (dec: -529514168), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short actual_vel_x;							   // size=0, offset=1204 //  hashcode: 0xD4311279 (dec: -734981511), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short actual_acc_x;							   // size=0, offset=1206 //  hashcode: 0xB2CEF55C (dec: -1295059620), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x_rot_change;							   // size=0, offset=1208 //  hashcode: 0x9F1FDAE6 (dec: -1625302298), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short focuspoint_fallz;						   // size=0, offset=1210 //  hashcode: 0xF5952CF4 (dec: -174773004), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lead_angle;							   // size=0, offset=1212 //  hashcode: 0xE252596D (dec: -497919635), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lead_vel;								   // size=0, offset=1214 //  hashcode: 0xFB132107 (dec: -82632441), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lead_accl;							   // size=0, offset=1216 //  hashcode: 0xFFF4A335 (dec: -744651), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lead_timer;							   // size=0, offset=1218 //  hashcode: 0x9CFC306B (dec: -1661194133), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DebugMenuLine // hashcode: 0x1BD18E81 (dec: 466718337)
{
	enum DEBUG_LINE_TYPE type; // size=4, offset=0 //  hashcode: 0x6B5319F8 (dec: 1800608248), parent name: 'DebugMenuLine', parent hashcode: 0xFFFFFFFF (dec: -1)
	long lower;				   // size=0, offset=4 //  hashcode: 0x332DD11F (dec: 858640671), parent name: 'DebugMenuLine', parent hashcode: 0xFFFFFFFF (dec: -1)
	long upper;				   // size=0, offset=8 //  hashcode: 0xB9603885 (dec: -1184876411), parent name: 'DebugMenuLine', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;				   // size=0, offset=12 //  hashcode: 0xC29858D6 (dec: -1030203178), parent name: 'DebugMenuLine', parent hashcode: 0xFFFFFFFF (dec: -1)
	long *var_address;		   // size=0, offset=16 //  hashcode: 0xD7925AA2 (dec: -678274398), parent name: 'DebugMenuLine', parent hashcode: 0xFFFFFFFF (dec: -1)
	long bit_mask;			   // size=0, offset=20 //  hashcode: 0x36F209C5 (dec: 921831877), parent name: 'DebugMenuLine', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _ButtonTexture // hashcode: 0x9E750D8C (dec: -1636495988)
{
	short tpage;					   // size=0, offset=0 //  hashcode: 0x10E05350 (dec: 283136848), parent name: '_ButtonTexture', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clut;						   // size=0, offset=2 //  hashcode: 0x11AD70EE (dec: 296579310), parent name: '_ButtonTexture', parent hashcode: 0xFFFFFFFF (dec: -1)
	short textureW;					   // size=0, offset=4 //  hashcode: 0x2DDD0E2F (dec: 769461807), parent name: '_ButtonTexture', parent hashcode: 0xFFFFFFFF (dec: -1)
	short textureH;					   // size=0, offset=6 //  hashcode: 0xE6EC1033 (dec: -420736973), parent name: '_ButtonTexture', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BlockVramEntry *vramBlock; // size=0, offset=8 //  hashcode: 0xA598F210 (dec: -1516703216), parent name: '_ButtonTexture', parent hashcode: 0xFFFFFFFF (dec: -1)
	long xshift;					   // size=0, offset=12 //  hashcode: 0xE0D05F17 (dec: -523215081), parent name: '_ButtonTexture', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BlockVramEntry // hashcode: 0x24B2FBC5 (dec: 615709637)
{
	struct _BlockVramEntry *next; // size=28, offset=0 //  hashcode: 0x2B063515 (dec: 721827093), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;			  // size=0, offset=4 //  hashcode: 0xED655898 (dec: -312125288), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;		  // size=0, offset=5 //  hashcode: 0x37B0CC5B (dec: 934333531), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;					  // size=0, offset=6 //  hashcode: 0x604196BF (dec: 1614911167), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short newX;					  // size=0, offset=8 //  hashcode: 0x98FD2A6C (dec: -1728238996), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short newY;					  // size=0, offset=10 //  hashcode: 0x0C5FB18C (dec: 207597964), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x;					  // size=0, offset=12 //  hashcode: 0x97DFFDBB (dec: -1746928197), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;					  // size=0, offset=14 //  hashcode: 0xE21E64A4 (dec: -501324636), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short w;					  // size=0, offset=16 //  hashcode: 0x323945A6 (dec: 842614182), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short h;					  // size=0, offset=18 //  hashcode: 0x7DBD24C2 (dec: 2109547714), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long area;					  // size=0, offset=20 //  hashcode: 0x1410AEFB (dec: 336637691), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	union DEBUG_256fake udata;	// size=4, offset=24 //  hashcode: 0x883FA1B5 (dec: -2009095755), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FontChar // hashcode: 0x5A2F9F5B (dec: 1513070427)
{
	short x;	// size=0, offset=0 //  hashcode: 0x8B5A4F5B (dec: -1957015717), parent name: 'FontChar', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	// size=0, offset=2 //  hashcode: 0x9960E669 (dec: -1721702807), parent name: 'FontChar', parent hashcode: 0xFFFFFFFF (dec: -1)
	char c;		// size=0, offset=4 //  hashcode: 0xFF90D02C (dec: -7286740), parent name: 'FontChar', parent hashcode: 0xFFFFFFFF (dec: -1)
	char color; // size=0, offset=5 //  hashcode: 0x82F3535C (dec: -2097982628), parent name: 'FontChar', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BigFileEntry // hashcode: 0xA904436B (dec: -1459338389)
{
	long fileHash;	 // size=0, offset=0 //  hashcode: 0xE98AD6B5 (dec: -376777035), parent name: '_BigFileEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long fileLen;	  // size=0, offset=4 //  hashcode: 0xD8CE80E4 (dec: -657555228), parent name: '_BigFileEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long filePos;	  // size=0, offset=8 //  hashcode: 0x24E59CE8 (dec: 619027688), parent name: '_BigFileEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long checkSumFull; // size=0, offset=12 //  hashcode: 0x0101C660 (dec: 16893536), parent name: '_BigFileEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BigFileDirEntry // hashcode: 0x7D70C603 (dec: 2104542723)
{
	short streamUnitID; // size=0, offset=0 //  hashcode: 0x86FD1308 (dec: -2030234872), parent name: '_BigFileDirEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numFiles;		// size=0, offset=2 //  hashcode: 0x78277B21 (dec: 2015853345), parent name: '_BigFileDirEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long subDirOffset;  // size=0, offset=4 //  hashcode: 0xADCD33BC (dec: -1379060804), parent name: '_BigFileDirEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BigFileDir // hashcode: 0x4E39D3E2 (dec: 1312412642)
{
	long numFiles;					  // size=0, offset=0 //  hashcode: 0xBF3883E4 (dec: -1086815260), parent name: '_BigFileDir', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BigFileEntry fileList[0]; // size=0, offset=4 //  hashcode: 0x8F247DAF (dec: -1893433937), parent name: '_BigFileDir', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BigFile // hashcode: 0x50C273F3 (dec: 1354920947)
{
	long bigfileBaseOffset;				 // size=0, offset=0 //  hashcode: 0x76905C03 (dec: 1989172227), parent name: '_BigFile', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BigFileDir *rootDir;		 // size=4, offset=4 //  hashcode: 0x348B3A13 (dec: 881539603), parent name: '_BigFile', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BigFileDir *currentDir;		 // size=4, offset=8 //  hashcode: 0x0A4EA20B (dec: 172925451), parent name: '_BigFile', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BigFileDir *cachedDir;		 // size=4, offset=12 //  hashcode: 0xD13BF95B (dec: -784598693), parent name: '_BigFile', parent hashcode: 0xFFFFFFFF (dec: -1)
	long currentDirID;					 // size=0, offset=16 //  hashcode: 0xEDDF2D37 (dec: -304141001), parent name: '_BigFile', parent hashcode: 0xFFFFFFFF (dec: -1)
	long cachedDirID;					 // size=0, offset=20 //  hashcode: 0xE3CEA1D7 (dec: -472997417), parent name: '_BigFile', parent hashcode: 0xFFFFFFFF (dec: -1)
	long searchDirID;					 // size=0, offset=24 //  hashcode: 0xD61F3273 (dec: -702598541), parent name: '_BigFile', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numSubDirs;					 // size=0, offset=28 //  hashcode: 0x951F31EA (dec: -1793117718), parent name: '_BigFile', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BigFileDirEntry *subDirList; // size=8, offset=32 //  hashcode: 0xD778D282 (dec: -679947646), parent name: '_BigFile', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _NonBlockLoadEntry // hashcode: 0x722059B4 (dec: 1914722740)
{
	long fileHash;	 // size=0, offset=0 //  hashcode: 0xC98BD924 (dec: -913581788), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long dirHash;	  // size=0, offset=4 //  hashcode: 0x6771AD6F (dec: 1735503215), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long filePos;	  // size=0, offset=8 //  hashcode: 0x69FD602E (dec: 1778212910), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long *loadAddr;	// size=0, offset=12 //  hashcode: 0xBB6A8EE5 (dec: -1150644507), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long loadSize;	 // size=0, offset=16 //  hashcode: 0xEC3F6FC9 (dec: -331386935), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long checksum;	 // size=0, offset=20 //  hashcode: 0xB11B9F6D (dec: -1323589779), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long checksumType; // size=0, offset=24 //  hashcode: 0x16DD728D (dec: 383611533), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long memType;	  // size=0, offset=28 //  hashcode: 0x89F9350E (dec: -1980156658), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long posInFile;	// size=0, offset=32 //  hashcode: 0x5C8653CB (dec: 1552307147), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long mallocFailOk; // size=0, offset=36 //  hashcode: 0x32B8DA90 (dec: 850975376), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *retFunc;	 // size=0, offset=40 //  hashcode: 0xE467DC81 (dec: -462955391), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *retData;	 // size=0, offset=44 //  hashcode: 0x8AB34B76 (dec: -1967961226), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *retData2;	// size=0, offset=48 //  hashcode: 0xDB4A56C6 (dec: -615885114), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	void **retPointer; // size=0, offset=52 //  hashcode: 0x6C0FD9BE (dec: 1812978110), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _ReadQueueEntry // hashcode: 0x5360DCDA (dec: 1398856922)
{
	long readStartPos;   // size=0, offset=0 //  hashcode: 0xFBE56610 (dec: -68852208), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long readSize;		 // size=0, offset=4 //  hashcode: 0xCF2356EE (dec: -819767570), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long readCurSize;	// size=0, offset=8 //  hashcode: 0x31591E7B (dec: 827924091), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *readStartDest; // size=0, offset=12 //  hashcode: 0xEB5834E7 (dec: -346540825), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *readCurDest;   // size=0, offset=16 //  hashcode: 0x91D06F25 (dec: -1848611035), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long readStatus;	 // size=0, offset=20 //  hashcode: 0xF11CE0ED (dec: -249765651), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long checksum;		 // size=0, offset=24 //  hashcode: 0xE57C74BA (dec: -444828486), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long checksumType;   // size=0, offset=28 //  hashcode: 0xA391B7E7 (dec: -1550731289), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *retFunc;		 // size=0, offset=32 //  hashcode: 0xD43526EE (dec: -734714130), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *retData;		 // size=0, offset=36 //  hashcode: 0x9EF32CFB (dec: -1628230405), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *retData2;		 // size=0, offset=40 //  hashcode: 0xF584EEF2 (dec: -175837454), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FX_MATRIX // hashcode: 0x13190ADD (dec: 320408285)
{
	struct NodeType node;	  // size=8, offset=0 //  hashcode: 0x90D41827 (dec: -1865148377), parent name: '_FX_MATRIX', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;				   // size=0, offset=8 //  hashcode: 0x49496543 (dec: 1229546819), parent name: '_FX_MATRIX', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX lwTransform; // size=32, offset=12 //  hashcode: 0xF6826A43 (dec: -159225277), parent name: '_FX_MATRIX', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_196fake // hashcode: 0x84DF3D7C (dec: -2065744516)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x291F06D9 (dec: 689899225), parent name: 'DEBUG_196fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0xF5063700 (dec: -184142080), parent name: 'DEBUG_196fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_197fake // hashcode: 0xFEE59B62 (dec: -18506910)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x4C903F75 (dec: 1284521845), parent name: 'DEBUG_197fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0x2C92556B (dec: 747787627), parent name: 'DEBUG_197fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x71EB6FB0 (dec: 1911254960), parent name: 'DEBUG_197fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0xEAF1624B (dec: -353279413), parent name: 'DEBUG_197fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x9F3E7A9D (dec: -1623295331), parent name: 'DEBUG_197fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0x68404516 (dec: 1749042454), parent name: 'DEBUG_197fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union DEBUG_198fake // Hashcode: 0x3EC5C78D (dec: 1053149069)
{
	struct DEBUG_196fake flame; // size=8, offset=0
	struct DEBUG_197fake phys;  // size=12, offset=0
};

struct _FX_PRIM // hashcode: 0x16BF818E (dec: 381649294)
{
	struct NodeType node;		// size=8, offset=0 //  hashcode: 0xF8DDCF96 (dec: -119681130), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct TextureMT3 *texture; // size=16, offset=8 //  hashcode: 0x08CDFFD5 (dec: 147718101), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;					// size=0, offset=12 //  hashcode: 0x26847C6F (dec: 646216815), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeToLive;			// size=0, offset=16 //  hashcode: 0x10759784 (dec: 276141956), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short curFrame;				// size=0, offset=18 //  hashcode: 0x73C0DBD1 (dec: 1942019025), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *process;				// size=0, offset=20 //  hashcode: 0xBA24973F (dec: -1172007105), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _FX_MATRIX *matrix;  // size=44, offset=24 //  hashcode: 0x02BC91BF (dec: 45912511), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;					// size=0, offset=28 //  hashcode: 0xF87EF425 (dec: -125897691), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	long startColor;			// size=0, offset=32 //  hashcode: 0xABC6184C (dec: -1413081012), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	long endColor;				// size=0, offset=36 //  hashcode: 0xB35D9630 (dec: -1285712336), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short colorFadeValue;		// size=0, offset=40 //  hashcode: 0x6452F1BB (dec: 1683157435), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short colorFadeStep;		// size=0, offset=42 //  hashcode: 0x47D9621B (dec: 1205428763), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position;  // size=6, offset=44 //  hashcode: 0xA20D9868 (dec: -1576167320), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadeStep;				// size=0, offset=50 //  hashcode: 0x0A80643A (dec: 176186426), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadeValue[4];			// size=8, offset=52 //  hashcode: 0xA96FD6FE (dec: -1452288258), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position v0;		// size=6, offset=60 //  hashcode: 0xF4FEA6D3 (dec: -184637741), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short work0;				// size=0, offset=66 //  hashcode: 0x4A6D5875 (dec: 1248680053), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position v1;		// size=6, offset=68 //  hashcode: 0x267CCCAE (dec: 645713070), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short work1;				// size=0, offset=74 //  hashcode: 0x53EFDEA4 (dec: 1408229028), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position v2;		// size=6, offset=76 //  hashcode: 0x02EDDAE0 (dec: 49142496), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short work2;				// size=0, offset=82 //  hashcode: 0x585D11CF (dec: 1482494415), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position v3;		// size=6, offset=84 //  hashcode: 0x74106F93 (dec: 1947234195), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short work3;				// size=0, offset=90 //  hashcode: 0x06FE9AE3 (dec: 117349091), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	union DEBUG_198fake duo;	// size=12, offset=92 //  hashcode: 0xB71D6DC5 (dec: -1222808123), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BASIC_LINE_G2 // hashcode: 0x684545B2 (dec: 1749370290)
{
	unsigned char r0;   // size=0, offset=0 //  hashcode: 0x5EB3D861 (dec: 1588844641), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;   // size=0, offset=1 //  hashcode: 0xF684EACC (dec: -159061300), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;   // size=0, offset=2 //  hashcode: 0x2EF4ECD5 (dec: 787803349), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code; // size=0, offset=3 //  hashcode: 0x8D79C2E6 (dec: -1921400090), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			// size=0, offset=4 //  hashcode: 0x95D0B537 (dec: -1781484233), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			// size=0, offset=6 //  hashcode: 0x6F33FD3B (dec: 1865678139), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r1;   // size=0, offset=8 //  hashcode: 0xA85510EC (dec: -1470820116), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g1;   // size=0, offset=9 //  hashcode: 0x83128C78 (dec: -2095936392), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b1;   // size=0, offset=10 //  hashcode: 0x005DB8A4 (dec: 6142116), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char p1;   // size=0, offset=11 //  hashcode: 0x02FD468D (dec: 50153101), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			// size=0, offset=12 //  hashcode: 0x4D0362E3 (dec: 1292067555), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			// size=0, offset=14 //  hashcode: 0x0405EC9F (dec: 67497119), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BASIC_G4 // hashcode: 0xC15AD9EF (dec: -1051010577)
{
	unsigned char r0;   // size=0, offset=0 //  hashcode: 0xCB592A2C (dec: -883348948), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;   // size=0, offset=1 //  hashcode: 0xB30FF061 (dec: -1290801055), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;   // size=0, offset=2 //  hashcode: 0x104A1250 (dec: 273289808), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code; // size=0, offset=3 //  hashcode: 0xB8EF85FD (dec: -1192262147), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			// size=0, offset=4 //  hashcode: 0x8116EEC2 (dec: -2129203518), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			// size=0, offset=6 //  hashcode: 0x8B34F51E (dec: -1959463650), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r1;   // size=0, offset=8 //  hashcode: 0x8C847921 (dec: -1937475295), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g1;   // size=0, offset=9 //  hashcode: 0x7A2BA1D5 (dec: 2049679829), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b1;   // size=0, offset=10 //  hashcode: 0x22103FEC (dec: 571490284), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad1; // size=0, offset=11 //  hashcode: 0xACFA51DC (dec: -1392881188), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			// size=0, offset=12 //  hashcode: 0xBE00444C (dec: -1107278772), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			// size=0, offset=14 //  hashcode: 0x22121FFF (dec: 571613183), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r2;   // size=0, offset=16 //  hashcode: 0xF9881FC7 (dec: -108519481), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g2;   // size=0, offset=17 //  hashcode: 0x4989BE42 (dec: 1233763906), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b2;   // size=0, offset=18 //  hashcode: 0x5CF1B4EB (dec: 1559344363), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad2; // size=0, offset=19 //  hashcode: 0x4D854EE5 (dec: 1300582117), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;			// size=0, offset=20 //  hashcode: 0x3F5B2776 (dec: 1062938486), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;			// size=0, offset=22 //  hashcode: 0xA789DEF3 (dec: -1484136717), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r3;   // size=0, offset=24 //  hashcode: 0x2C50E986 (dec: 743500166), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g3;   // size=0, offset=25 //  hashcode: 0x07734216 (dec: 124994070), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b3;   // size=0, offset=26 //  hashcode: 0x9B89DCF1 (dec: -1685463823), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad3; // size=0, offset=27 //  hashcode: 0xC427EAB9 (dec: -1004016967), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x3;			// size=0, offset=28 //  hashcode: 0x02A50B7C (dec: 44370812), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y3;			// size=0, offset=30 //  hashcode: 0x8F68DEFC (dec: -1888952580), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BASIC_F4 // hashcode: 0x2871008E (dec: 678494350)
{
	unsigned char r0;   // size=0, offset=0 //  hashcode: 0x1F82BA0A (dec: 528661002), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;   // size=0, offset=1 //  hashcode: 0x9E777553 (dec: -1636338349), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;   // size=0, offset=2 //  hashcode: 0x68018CD6 (dec: 1744932054), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code; // size=0, offset=3 //  hashcode: 0x2D34FE58 (dec: 758447704), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			// size=0, offset=4 //  hashcode: 0xB8F15223 (dec: -1192144349), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			// size=0, offset=6 //  hashcode: 0x6F7CA4CC (dec: 1870439628), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			// size=0, offset=8 //  hashcode: 0x3336ED07 (dec: 859237639), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			// size=0, offset=10 //  hashcode: 0x46E92EF5 (dec: 1189687029), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;			// size=0, offset=12 //  hashcode: 0xAC793AF5 (dec: -1401341195), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;			// size=0, offset=14 //  hashcode: 0x6900528D (dec: 1761628813), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x3;			// size=0, offset=16 //  hashcode: 0xBB4D5F63 (dec: -1152557213), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y3;			// size=0, offset=18 //  hashcode: 0xE33041D1 (dec: -483376687), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __BubbleParams // hashcode: 0xE483C494 (dec: -461126508)
{
	short DisperseFrames;  // size=0, offset=0 //  hashcode: 0x7969B823 (dec: 2036971555), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short KillScale;	   // size=0, offset=2 //  hashcode: 0xFE20574E (dec: -31434930), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short MinSplashSize;   // size=0, offset=4 //  hashcode: 0x46AC0D3E (dec: 1185680702), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short MaxSpeed;		   // size=0, offset=6 //  hashcode: 0x8A3B34FE (dec: -1975831298), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short MaxSpeedRange;   // size=0, offset=8 //  hashcode: 0x2C9EE7A2 (dec: 748611490), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ScaleRate;	   // size=0, offset=10 //  hashcode: 0xCE6112EC (dec: -832498964), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ScaleRateRange;  // size=0, offset=12 //  hashcode: 0xB5F64E4E (dec: -1242149298), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short StartScale;	  // size=0, offset=14 //  hashcode: 0xE32E4681 (dec: -483506559), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short StartScaleRange; // size=0, offset=16 //  hashcode: 0xBDE2BA65 (dec: -1109214619), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short UniqueBubbles;   // size=0, offset=18 //  hashcode: 0x59AE432F (dec: 1504592687), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GenericParticleParams // hashcode: 0x7A6370AD (dec: 2053337261)
{
	short size;						  // size=0, offset=0 //  hashcode: 0x769735AB (dec: 1989621163), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char StartOnInit;		  // size=0, offset=2 //  hashcode: 0x02244A14 (dec: 35932692), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;				  // size=0, offset=3 //  hashcode: 0xDFEE5C9E (dec: -538026850), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short birthRadius;				  // size=0, offset=4 //  hashcode: 0x80AAF608 (dec: -2136279544), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char startSegment;				  // size=0, offset=6 //  hashcode: 0xF60B3966 (dec: -167036570), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char endSegment;				  // size=0, offset=7 //  hashcode: 0xC6179A37 (dec: -971531721), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position direction;		  // size=6, offset=8 //  hashcode: 0xEFE021D2 (dec: -270523950), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char spectral_colorize;  // size=0, offset=14 //  hashcode: 0xEE3E2295 (dec: -297917803), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char absolute_direction; // size=0, offset=15 //  hashcode: 0x60E25F36 (dec: 1625448246), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char accx;						  // size=0, offset=16 //  hashcode: 0x32997FDE (dec: 848920542), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char accy;						  // size=0, offset=17 //  hashcode: 0x93167049 (dec: -1827246007), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char accz;						  // size=0, offset=18 //  hashcode: 0x17D046EB (dec: 399525611), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char useInstanceModel;			  // size=0, offset=19 //  hashcode: 0x7611E55F (dec: 1980884319), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char startColor_red;	 // size=0, offset=20 //  hashcode: 0x4251EA56 (dec: 1112664662), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char startColor_green;   // size=0, offset=21 //  hashcode: 0x2EBA3CB0 (dec: 783957168), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char startColor_blue;	// size=0, offset=22 //  hashcode: 0xE68FB79B (dec: -426788965), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char model;						  // size=0, offset=23 //  hashcode: 0xF2E83972 (dec: -219661966), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char endColor_red;		  // size=0, offset=24 //  hashcode: 0x10BE5549 (dec: 280909129), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char endColor_green;	 // size=0, offset=25 //  hashcode: 0x205C44FE (dec: 542917886), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char endColor_blue;	  // size=0, offset=26 //  hashcode: 0xEEAC0638 (dec: -290716104), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char texture;					  // size=0, offset=27 //  hashcode: 0x01A20C2D (dec: 27397165), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;					  // size=0, offset=28 //  hashcode: 0x1E1A8601 (dec: 505054721), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char primLifeTime;		  // size=0, offset=30 //  hashcode: 0x431AC5CA (dec: 1125828042), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char use_child;					  // size=0, offset=31 //  hashcode: 0x8DD01033 (dec: -1915744205), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startFadeValue;			  // size=0, offset=32 //  hashcode: 0x35C5AB98 (dec: 902146968), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadeStep;					  // size=0, offset=34 //  hashcode: 0xD766C900 (dec: -681129728), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numberBirthParticles;		  // size=0, offset=36 //  hashcode: 0xF37277E3 (dec: -210602013), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char z_undulation_mode;			  // size=0, offset=37 //  hashcode: 0x75215E98 (dec: 1965121176), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short scaleSpeed;				  // size=0, offset=38 //  hashcode: 0x8E0A7667 (dec: -1911916953), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position offset;		  // size=6, offset=40 //  hashcode: 0xF5948813 (dec: -174815213), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startScale;				  // size=0, offset=46 //  hashcode: 0xEB136AFB (dec: -351048965), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GenericRibbonParams // hashcode: 0xD243E3C9 (dec: -767302711)
{
	char id;			  // size=0, offset=0 //  hashcode: 0xF6C0924F (dec: -155151793), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char StartOnInit;	 // size=0, offset=1 //  hashcode: 0x9DB08E6A (dec: -1649373590), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char startSegment;	// size=0, offset=2 //  hashcode: 0x3414A882 (dec: 873769090), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char endSegment;	  // size=0, offset=3 //  hashcode: 0xDCF6F968 (dec: -587794072), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char type;			  // size=0, offset=4 //  hashcode: 0xFF426991 (dec: -12424815), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char use_child;		  // size=0, offset=5 //  hashcode: 0x178BD049 (dec: 395038793), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ribbonLifeTime; // size=0, offset=6 //  hashcode: 0x8B80214A (dec: -1954537142), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short faceLifeTime;   // size=0, offset=8 //  hashcode: 0x6C60300A (dec: 1818243082), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startFadeValue; // size=0, offset=10 //  hashcode: 0x1E0F128D (dec: 504304269), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	long startColor;	  // size=0, offset=12 //  hashcode: 0x729295DC (dec: 1922209244), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	long endColor;		  // size=0, offset=16 //  hashcode: 0x7E8A5C8A (dec: 2122996874), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GenericGlowParams // hashcode: 0xF67692B8 (dec: -160001352)
{
	char StartOnInit;		  // size=0, offset=0 //  hashcode: 0x6798E26C (dec: 1738072684), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segment;	// size=0, offset=1 //  hashcode: 0x2E2C37AF (dec: 774649775), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segmentEnd; // size=0, offset=2 //  hashcode: 0xEF814F60 (dec: -276738208), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numSegments;		  // size=0, offset=3 //  hashcode: 0x771A9BFB (dec: 1998232571), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char color_num;  // size=0, offset=4 //  hashcode: 0x2E768337 (dec: 779518775), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char use_child;			  // size=0, offset=5 //  hashcode: 0x85E1104F (dec: -2048847793), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numColors;  // size=0, offset=6 //  hashcode: 0x7249E956 (dec: 1917446486), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char id;				  // size=0, offset=7 //  hashcode: 0x21559665 (dec: 559257189), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	long atuColorCycleRate;   // size=0, offset=8 //  hashcode: 0xFAC1DA22 (dec: -87959006), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short width;			  // size=0, offset=12 //  hashcode: 0x37CACAF1 (dec: 936037105), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short height;			  // size=0, offset=14 //  hashcode: 0xBA5C9726 (dec: -1168337114), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	long lifetime;			  // size=0, offset=16 //  hashcode: 0x962EF371 (dec: -1775307919), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadein_time;		  // size=0, offset=20 //  hashcode: 0x2A88FDC4 (dec: 713620932), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadeout_time;		  // size=0, offset=22 //  hashcode: 0xD26C8145 (dec: -764640955), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GenericLightningParams // hashcode: 0x226C68CF (dec: 577530063)
{
	char type;					   // size=0, offset=0 //  hashcode: 0xE8D53ACD (dec: -388678963), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char use_child;				   // size=0, offset=1 //  hashcode: 0x9D9FFF26 (dec: -1650458842), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;				   // size=0, offset=2 //  hashcode: 0x24B5CFF2 (dec: 615895026), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short deg;					   // size=0, offset=4 //  hashcode: 0x6D56B56F (dec: 1834399087), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short deg_inc;				   // size=0, offset=6 //  hashcode: 0x3985A90D (dec: 965060877), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position start_offset; // size=6, offset=8 //  hashcode: 0xB1D8595B (dec: -1311221413), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char startSeg;				   // size=0, offset=14 //  hashcode: 0xFF7AB124 (dec: -8736476), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char endSeg;				   // size=0, offset=15 //  hashcode: 0x827364F3 (dec: -2106366733), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position end_offset;   // size=6, offset=16 //  hashcode: 0x3317AC37 (dec: 857189431), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char matrixSeg;				   // size=0, offset=22 //  hashcode: 0x81487843 (dec: -2125957053), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segs;			   // size=0, offset=23 //  hashcode: 0x21E594E4 (dec: 568693988), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short width;				   // size=0, offset=24 //  hashcode: 0x091CB88D (dec: 152877197), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short small_width;			   // size=0, offset=26 //  hashcode: 0x4EA21B42 (dec: 1319246658), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sine_size;			   // size=0, offset=28 //  hashcode: 0x0D9FF394 (dec: 228586388), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short variation;			   // size=0, offset=30 //  hashcode: 0x603B4311 (dec: 1614496529), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;					   // size=0, offset=32 //  hashcode: 0xD8ED63CA (dec: -655531062), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	long glow_color;			   // size=0, offset=36 //  hashcode: 0x0C9CDF4A (dec: 211607370), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GenericBlastringParams // hashcode: 0xAB3B2462 (dec: -1422187422)
{
	char type;				  // size=0, offset=0 //  hashcode: 0x5804911E (dec: 1476694302), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char use_child;			  // size=0, offset=1 //  hashcode: 0x591DAC99 (dec: 1495116953), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;			  // size=0, offset=2 //  hashcode: 0x6BDD7B5F (dec: 1809677151), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position offset;  // size=6, offset=4 //  hashcode: 0xF5DEEA20 (dec: -169940448), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short matrixSeg;		  // size=0, offset=10 //  hashcode: 0x22F4ACF6 (dec: 586460406), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char segment;			  // size=0, offset=12 //  hashcode: 0x2FED1273 (dec: 804065907), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char sortInWorld;		  // size=0, offset=13 //  hashcode: 0x4ABB9FF5 (dec: 1253810165), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short radius;			  // size=0, offset=14 //  hashcode: 0x40C03804 (dec: 1086339076), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short size1;			  // size=0, offset=16 //  hashcode: 0x094CA7AA (dec: 156018602), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short size2;			  // size=0, offset=18 //  hashcode: 0xA2F0FBAE (dec: -1561265234), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short endRadius;		  // size=0, offset=20 //  hashcode: 0x35F4CE1F (dec: 905235999), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short colorchange_radius; // size=0, offset=22 //  hashcode: 0xC4429797 (dec: -1002268777), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	int vel;				  // size=0, offset=24 //  hashcode: 0xCC76180D (dec: -864675827), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	int accl;				  // size=0, offset=28 //  hashcode: 0x0150CE5F (dec: 22072927), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short height1;			  // size=0, offset=32 //  hashcode: 0xF071A391 (dec: -260988015), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short height2;			  // size=0, offset=34 //  hashcode: 0xB5826B69 (dec: -1249744023), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short height3;			  // size=0, offset=36 //  hashcode: 0x70AD7876 (dec: 1890416758), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char predator_offset;	 // size=0, offset=38 //  hashcode: 0x57198240 (dec: 1461289536), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char stay_in_place;		  // size=0, offset=39 //  hashcode: 0xC0C7C4A1 (dec: -1060649823), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	long startColor;		  // size=0, offset=40 //  hashcode: 0xA0F8908C (dec: -1594322804), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	long endColor;			  // size=0, offset=44 //  hashcode: 0x41E408F1 (dec: 1105463537), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GenericFlashParams // hashcode: 0x06D8DB60 (dec: 114875232)
{
	short type;			 // size=0, offset=0 //  hashcode: 0xC9290798 (dec: -920057960), parent name: '_GenericFlashParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeToColor;   // size=0, offset=2 //  hashcode: 0x913796F7 (dec: -1858627849), parent name: '_GenericFlashParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;			 // size=0, offset=4 //  hashcode: 0x652FDAAD (dec: 1697634989), parent name: '_GenericFlashParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeAtColor;   // size=0, offset=8 //  hashcode: 0xEAFFB3DC (dec: -352341028), parent name: '_GenericFlashParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeFromColor; // size=0, offset=10 //  hashcode: 0x80A95C4E (dec: -2136384434), parent name: '_GenericFlashParams', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union DEBUG_224fake // Hashcode: 0x0131C19B (dec: 20038043)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct _StreamUnit // hashcode: 0xAC366E40 (dec: -1405718976)
{
	long StreamUnitID;		 // size=0, offset=0 //  hashcode: 0x70253426 (dec: 1881486374), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short used;				 // size=0, offset=4 //  hashcode: 0xD50A5FEF (dec: -720740369), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;			 // size=0, offset=6 //  hashcode: 0x011DF715 (dec: 18741013), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Level *level;	 // size=392, offset=8 //  hashcode: 0xC1929217 (dec: -1047358953), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	char baseAreaName[16];   // size=16, offset=12 //  hashcode: 0xEED64F14 (dec: -287944940), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short toSignal;			 // size=0, offset=28 //  hashcode: 0xE6DDB7D1 (dec: -421677103), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fromSignal;		 // size=0, offset=30 //  hashcode: 0x7F10163B (dec: 2131760699), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	long FrameCount;		 // size=0, offset=32 //  hashcode: 0xD88CC300 (dec: -661863680), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short eventVariables[6]; // size=12, offset=36 //  hashcode: 0xF6988113 (dec: -157777645), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	long FogColor;			 // size=0, offset=48 //  hashcode: 0x09AA685E (dec: 162162782), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short UnitFogFar;		 // size=0, offset=52 //  hashcode: 0x9234EEA2 (dec: -1842024798), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short UnitFogNear;		 // size=0, offset=54 //  hashcode: 0x4C147E54 (dec: 1276411476), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short TargetFogFar;		 // size=0, offset=56 //  hashcode: 0x40A0B5E0 (dec: 1084274144), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short TargetFogNear;	 // size=0, offset=58 //  hashcode: 0xB63649AD (dec: -1237956179), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sfxFileHandle;	 // size=0, offset=60 //  hashcode: 0x608568D6 (dec: 1619355862), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;				 // size=0, offset=62 //  hashcode: 0x92DF4D19 (dec: -1830859495), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct XAFileInfo // hashcode: 0xD7260012 (dec: -685375470)
{
	int startPos; // size=0, offset=0 //  hashcode: 0x2A3E5B5E (dec: 708729694), parent name: 'XAFileInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CdCommand // hashcode: 0x042C215C (dec: 70000988)
{
	unsigned short flags;		 // size=0, offset=0 //  hashcode: 0x5EC8DC9F (dec: 1590221983), parent name: 'CdCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char unused;		 // size=0, offset=2 //  hashcode: 0x8EF2A6EE (dec: -1896700178), parent name: 'CdCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char cdCommand;	 // size=0, offset=3 //  hashcode: 0x3CE6F8AF (dec: 1021769903), parent name: 'CdCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char cdCmdParam[4]; // size=4, offset=4 //  hashcode: 0xED8E3D3D (dec: -309445315), parent name: 'CdCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VoiceCommand // hashcode: 0xEEB8F864 (dec: -289867676)
{
	unsigned char voiceCmd;		   // size=0, offset=0 //  hashcode: 0xDC3C1FDA (dec: -600039462), parent name: 'VoiceCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char nextVoiceStatus; // size=0, offset=1 //  hashcode: 0x7FED7877 (dec: 2146269303), parent name: 'VoiceCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short voiceCmdParam;  // size=0, offset=2 //  hashcode: 0x8186774D (dec: -2121894067), parent name: 'VoiceCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _LoadQueueEntry // hashcode: 0xFEE70962 (dec: -18413214)
{
	struct _LoadQueueEntry *next;		 // size=64, offset=0 //  hashcode: 0xCA94D546 (dec: -896215738), parent name: '_LoadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short status;						 // size=0, offset=4 //  hashcode: 0x3756C2CB (dec: 928432843), parent name: '_LoadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	char relocateBinary;				 // size=0, offset=6 //  hashcode: 0xDCECAC2B (dec: -588469205), parent name: '_LoadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	char mempackUsed;					 // size=0, offset=7 //  hashcode: 0x33E3363C (dec: 870528572), parent name: '_LoadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _NonBlockLoadEntry loadEntry; // size=56, offset=8 //  hashcode: 0x4314A741 (dec: 1125427009), parent name: '_LoadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union DEBUG_256fake // Hashcode: 0xC4D985DA (dec: -992377382)
{
	struct _StreamUnit *streamUnit;		 // size=64, offset=0
	struct _ObjectTracker *streamObject; // size=36, offset=0
	struct _ButtonTexture *button;		 // size=16, offset=0
};

struct SavedBasic // hashcode: 0x6198E1EF (dec: 1637409263)
{
	unsigned char savedID;		   // size=0, offset=0 //  hashcode: 0x8EBF79CC (dec: -1900054068), parent name: 'SavedBasic', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char shiftedSaveSize; // size=0, offset=1 //  hashcode: 0xC0C3F48D (dec: -1060899699), parent name: 'SavedBasic', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _SavedIntro // hashcode: 0x8389D216 (dec: -2088119786)
{
	unsigned char savedID;				 // size=0, offset=0 //  hashcode: 0x9F02E82E (dec: -1627199442), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char shiftedSaveSize;		 // size=0, offset=1 //  hashcode: 0xA54C5886 (dec: -1521723258), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char lightGroup;			 // size=0, offset=2 //  hashcode: 0xE8D6B2B9 (dec: -388582727), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char specturalLightGroup;   // size=0, offset=3 //  hashcode: 0xAD9F648C (dec: -1382062964), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	char name[8];						 // size=8, offset=4 //  hashcode: 0x61579E62 (dec: 1633132130), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short introUniqueID;				 // size=0, offset=12 //  hashcode: 0x0C1FB867 (dec: 203405415), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short streamUnitID;					 // size=0, offset=14 //  hashcode: 0xCC8A5432 (dec: -863349710), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short birthUnitID;					 // size=0, offset=16 //  hashcode: 0x5B1FFEF2 (dec: 1528823538), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short attachedUniqueID;	 // size=0, offset=18 //  hashcode: 0x19BFC314 (dec: 431997716), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SmallRotation smallRotation; // size=6, offset=20 //  hashcode: 0x428F595D (dec: 1116690781), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position;			 // size=6, offset=26 //  hashcode: 0xDA9008A8 (dec: -628094808), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;							 // size=0, offset=32 //  hashcode: 0xECFBE103 (dec: -319037181), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags2;						 // size=0, offset=36 //  hashcode: 0xCAE51F8F (dec: -890953841), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SavedEvent // hashcode: 0x429B6172 (dec: 1117479282)
{
	unsigned char savedID;		   // size=0, offset=0 //  hashcode: 0x8A4C3ABF (dec: -1974715713), parent name: 'SavedEvent', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char shiftedSaveSize; // size=0, offset=1 //  hashcode: 0xD1AA0C35 (dec: -777384907), parent name: 'SavedEvent', parent hashcode: 0xFFFFFFFF (dec: -1)
	short areaID;				   // size=0, offset=2 //  hashcode: 0x8F097B9B (dec: -1895203941), parent name: 'SavedEvent', parent hashcode: 0xFFFFFFFF (dec: -1)
	short eventNumber;			   // size=0, offset=4 //  hashcode: 0x5F844075 (dec: 1602502773), parent name: 'SavedEvent', parent hashcode: 0xFFFFFFFF (dec: -1)
	short eventVariables[5];	   // size=10, offset=6 //  hashcode: 0xEA057BFD (dec: -368739331), parent name: 'SavedEvent', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SavedBspTree // hashcode: 0x7AE7209C (dec: 2061967516)
{
	struct _Position localOffset;	  // size=6, offset=0 //  hashcode: 0x1C7CCC38 (dec: 477940792), parent name: 'SavedBspTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char importantFlagsSaved; // size=0, offset=6 //  hashcode: 0x4B782EA3 (dec: 1266167459), parent name: 'SavedBspTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char bspIndex;			   // size=0, offset=7 //  hashcode: 0x396A5643 (dec: 963270211), parent name: 'SavedBspTree', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EventBasicObject // hashcode: 0x9FC1DB2A (dec: -1614685398)
{
	short id; // size=0, offset=0 //  hashcode: 0x599099E8 (dec: 1502648808), parent name: 'EventBasicObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union DEBUG_260fake // Hashcode: 0x8C9106F7 (dec: -1936652553)
{
	struct Intro *intro;	   // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

struct EventWildCardObject // hashcode: 0x24FF3630 (dec: 620705328)
{
	short id;		  // size=0, offset=0 //  hashcode: 0xA164605B (dec: -1587257253), parent name: 'EventWildCardObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short spad;		  // size=0, offset=2 //  hashcode: 0xC22B0BB2 (dec: -1037366350), parent name: 'EventWildCardObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long unitID;	  // size=0, offset=4 //  hashcode: 0xD568A87A (dec: -714561414), parent name: 'EventWildCardObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *objectName; // size=0, offset=8 //  hashcode: 0x7F4E4A77 (dec: 2135837303), parent name: 'EventWildCardObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct Event // hashcode: 0x68F4AD26 (dec: 1760865574)
{
	short eventNumber;						// size=0, offset=0 //  hashcode: 0xA0939AD4 (dec: -1600939308), parent name: 'Event', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numInstances;						// size=0, offset=2 //  hashcode: 0xFB413530 (dec: -79612624), parent name: 'Event', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numActions;				// size=0, offset=4 //  hashcode: 0xB23399BC (dec: -1305241156), parent name: 'Event', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char processingPuppetShow;		// size=0, offset=5 //  hashcode: 0x80CE988E (dec: -2133944178), parent name: 'Event', parent hashcode: 0xFFFFFFFF (dec: -1)
	short eventVariables[5];				// size=10, offset=6 //  hashcode: 0x27BBBEAF (dec: 666615471), parent name: 'Event', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct EventBasicObject **instanceList; // size=2, offset=16 //  hashcode: 0xFD5F7979 (dec: -44074631), parent name: 'Event', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct ScriptPCode **conditionalList;   // size=8, offset=20 //  hashcode: 0xF168B7FF (dec: -244795393), parent name: 'Event', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct ScriptPCode **actionList;		// size=8, offset=24 //  hashcode: 0x5B7D28DE (dec: 1534929118), parent name: 'Event', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ScriptPCode // hashcode: 0x5E69DEB9 (dec: 1583996601)
{
	unsigned short sizeOfPcodeStream; // size=0, offset=0 //  hashcode: 0xD0F08437 (dec: -789543881), parent name: 'ScriptPCode', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short conditionBits;	 // size=0, offset=2 //  hashcode: 0x3A0C49EE (dec: 973883886), parent name: 'ScriptPCode', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *data;					  // size=0, offset=4 //  hashcode: 0x1E2FCB64 (dec: 506448740), parent name: 'ScriptPCode', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct InstanceSpline // hashcode: 0x88E38857 (dec: -1998354345)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0x6A7DADBA (dec: 1786621370), parent name: 'InstanceSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *spline; // size=80, offset=4 //  hashcode: 0xC9A2D3DE (dec: -912075810), parent name: 'InstanceSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;				// size=0, offset=8 //  hashcode: 0xEAD2451D (dec: -355318499), parent name: 'InstanceSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	long isParent;				// size=0, offset=12 //  hashcode: 0xD48792E4 (dec: -729312540), parent name: 'InstanceSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	long isClass;				// size=0, offset=16 //  hashcode: 0xE362A1BC (dec: -480075332), parent name: 'InstanceSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	long splineFlags;			// size=0, offset=20 //  hashcode: 0xB815589D (dec: -1206560611), parent name: 'InstanceSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct Vector3d // hashcode: 0x10BF06FC (dec: 280954620)
{
	short vx;		   // size=0, offset=0 //  hashcode: 0x6D235E4D (dec: 1831034445), parent name: 'Vector3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vy;		   // size=0, offset=2 //  hashcode: 0x24D3E177 (dec: 617865591), parent name: 'Vector3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vz;		   // size=0, offset=4 //  hashcode: 0xFFB5E117 (dec: -4857577), parent name: 'Vector3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad1;		   // size=0, offset=6 //  hashcode: 0x825950EF (dec: -2108075793), parent name: 'Vector3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short errorx;	  // size=0, offset=8 //  hashcode: 0x59BD489F (dec: 1505577119), parent name: 'Vector3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short errory;	  // size=0, offset=10 //  hashcode: 0xB5AB181C (dec: -1247078372), parent name: 'Vector3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short errorz;	  // size=0, offset=12 //  hashcode: 0x2C5ADEBF (dec: 744152767), parent name: 'Vector3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad2;		   // size=0, offset=14 //  hashcode: 0xE5A32263 (dec: -442293661), parent name: 'Vector3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamUnitID; // size=0, offset=16 //  hashcode: 0x466D6834 (dec: 1181575220), parent name: 'Vector3d', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct Rotation3d // hashcode: 0x646160C4 (dec: 1684103364)
{
	short vx;		// size=0, offset=0 //  hashcode: 0x9D16F17A (dec: -1659440774), parent name: 'Rotation3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vy;		// size=0, offset=2 //  hashcode: 0xDCF35637 (dec: -588032457), parent name: 'Rotation3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vz;		// size=0, offset=4 //  hashcode: 0x5913EBA4 (dec: 1494477732), parent name: 'Rotation3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad1;		// size=0, offset=6 //  hashcode: 0x17B1EBEC (dec: 397536236), parent name: 'Rotation3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short errorx;   // size=0, offset=8 //  hashcode: 0xF7FBFF34 (dec: -134480076), parent name: 'Rotation3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short errory;   // size=0, offset=10 //  hashcode: 0x4724D531 (dec: 1193596209), parent name: 'Rotation3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short errorz;   // size=0, offset=12 //  hashcode: 0x16BDF7CD (dec: 381548493), parent name: 'Rotation3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad2;		// size=0, offset=14 //  hashcode: 0xB23F50A8 (dec: -1304473432), parent name: 'Rotation3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute; // size=0, offset=16 //  hashcode: 0xCCAB05A4 (dec: -861207132), parent name: 'Rotation3d', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct InstanceObject // hashcode: 0xA445CB1D (dec: -1538929891)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0x6FF90A20 (dec: 1878592032), parent name: 'InstanceObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;				// size=0, offset=4 //  hashcode: 0xA54A10A6 (dec: -1521872730), parent name: 'InstanceObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EventObject // hashcode: 0x38B0B53D (dec: 951104829)
{
	struct Event *event; // size=28, offset=0 //  hashcode: 0x01BEDA5A (dec: 29284954), parent name: 'EventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;		 // size=0, offset=4 //  hashcode: 0xD221CA88 (dec: -769537400), parent name: 'EventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SavedEventObject // hashcode: 0xC69C23B2 (dec: -962845774)
{
	struct SavedBasic *savedEvent; // size=2, offset=0 //  hashcode: 0xFBE2452D (dec: -69057235), parent name: 'SavedEventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;				   // size=0, offset=4 //  hashcode: 0x675EA49F (dec: 1734255775), parent name: 'SavedEventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long areaID;				   // size=0, offset=8 //  hashcode: 0x3ECECF04 (dec: 1053740804), parent name: 'SavedEventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long eventNumber;			   // size=0, offset=12 //  hashcode: 0xB440B43A (dec: -1270827974), parent name: 'SavedEventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GameObject // hashcode: 0xFA1A30A9 (dec: -98946903)
{
	long attribute; // size=0, offset=0 //  hashcode: 0xB4381CAF (dec: -1271391057), parent name: 'GameObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SignalObject // hashcode: 0x42CFA9E2 (dec: 1120905698)
{
	struct _MultiSignal *msignal; // size=904, offset=0 //  hashcode: 0x103B9C59 (dec: 272342105), parent name: 'SignalObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;				  // size=0, offset=4 //  hashcode: 0x9C2D5749 (dec: -1674750135), parent name: 'SignalObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct IntroObject // hashcode: 0x13CCBC8C (dec: 332184716)
{
	struct Intro *intro; // size=76, offset=0 //  hashcode: 0x8DA7A7B6 (dec: -1918392394), parent name: 'IntroObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;		 // size=0, offset=4 //  hashcode: 0x2A3FBCF2 (dec: 708820210), parent name: 'IntroObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct InstanceAnimate // hashcode: 0x200AA21A (dec: 537567770)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0x38A9249C (dec: 950609052), parent name: 'InstanceAnimate', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;				// size=0, offset=4 //  hashcode: 0xA799B517 (dec: -1483098857), parent name: 'InstanceAnimate', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct InstanceAnimateTexture // hashcode: 0x5266C0BB (dec: 1382465723)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0x62E5A18E (dec: 1659216270), parent name: 'InstanceAnimateTexture', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AniTex *aniTextures; // size=16, offset=4 //  hashcode: 0x84E13522 (dec: -2065615582), parent name: 'InstanceAnimateTexture', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;				// size=0, offset=8 //  hashcode: 0x4220F79B (dec: 1109456795), parent name: 'InstanceAnimateTexture', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ListObject // hashcode: 0x1323C7B3 (dec: 321111987)
{
	struct EventWildCardObject *eventInstance; // size=12, offset=0 //  hashcode: 0xF56290D4 (dec: -178089772), parent name: 'ListObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute[5];						   // size=20, offset=4 //  hashcode: 0x32BE1921 (dec: 851319073), parent name: 'ListObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numberOfAttributes;				   // size=0, offset=24 //  hashcode: 0xB346ACF9 (dec: -1287213831), parent name: 'ListObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long lineID;							   // size=0, offset=28 //  hashcode: 0x0D13C584 (dec: 219399556), parent name: 'ListObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SubListObject // hashcode: 0xFDCC28E5 (dec: -36951835)
{
	struct _Instance **instanceList; // size=616, offset=0 //  hashcode: 0x85C76B77 (dec: -2050528393), parent name: 'SubListObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numberOfInstances;			 // size=0, offset=4 //  hashcode: 0xBE04F93E (dec: -1106970306), parent name: 'SubListObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numberOfAttributes;		 // size=0, offset=8 //  hashcode: 0xA3FC0F40 (dec: -1543762112), parent name: 'SubListObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute[5];				 // size=20, offset=12 //  hashcode: 0xFE76C980 (dec: -25769600), parent name: 'SubListObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TGroupObject // hashcode: 0x669B4B67 (dec: 1721453415)
{
	struct BSPTree *bspTree;		// size=36, offset=0 //  hashcode: 0xA6991537 (dec: -1499917001), parent name: 'TGroupObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _StreamUnit *streamUnit; // size=64, offset=4 //  hashcode: 0xA2A540AD (dec: -1566228307), parent name: 'TGroupObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;					// size=0, offset=8 //  hashcode: 0xD8EEA80A (dec: -655448054), parent name: 'TGroupObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short arg[2];					// size=4, offset=12 //  hashcode: 0x1E9A67D2 (dec: 513435602), parent name: 'TGroupObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ConstrictInfo // hashcode: 0xA586BA8A (dec: -1517897078)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0xD33EF9D3 (dec: -750847533), parent name: 'ConstrictInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;				// size=0, offset=4 //  hashcode: 0xC2FBDC9E (dec: -1023681378), parent name: 'ConstrictInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CameraObject // hashcode: 0xD3BF3ACE (dec: -742442290)
{
	struct Camera *camera; // size=1220, offset=0 //  hashcode: 0xE3D18800 (dec: -472807424), parent name: 'CameraObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frames;		   // size=0, offset=4 //  hashcode: 0x636CC6AA (dec: 1668073130), parent name: 'CameraObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;		   // size=0, offset=8 //  hashcode: 0x82542F73 (dec: -2108412045), parent name: 'CameraObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EventVmObject // hashcode: 0x9DE5D8F8 (dec: -1645881096)
{
	struct _VMObject *vmObjectPtr; // size=60, offset=0 //  hashcode: 0x6AC0262A (dec: 1790977578), parent name: 'EventVmObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Level *level;		   // size=392, offset=4 //  hashcode: 0xE6C15FAB (dec: -423534677), parent name: 'EventVmObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;				   // size=0, offset=8 //  hashcode: 0x1B8EACB3 (dec: 462335155), parent name: 'EventVmObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AreaObject // hashcode: 0x38AC5A77 (dec: 950819447)
{
	struct _StreamUnit *streamUnit; // size=64, offset=0 //  hashcode: 0x0F042FAF (dec: 251932591), parent name: 'AreaObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;					// size=0, offset=4 //  hashcode: 0x6305644A (dec: 1661297738), parent name: 'AreaObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long unitID;					// size=0, offset=8 //  hashcode: 0xFBD1182A (dec: -70182870), parent name: 'AreaObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union DEBUG_262fake // Hashcode: 0xD8F1044E (dec: -655293362)
{
	struct _Instance *instance; // size=616, offset=0
	struct _SFXMkr *sfxMarker;  // size=36, offset=0
};

struct SoundObject // hashcode: 0x9DA5ECE7 (dec: -1650070297)
{
	short flags;			  // size=0, offset=0 //  hashcode: 0x7AEABDDA (dec: 2062204378), parent name: 'SoundObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short attribute;		  // size=0, offset=2 //  hashcode: 0xE4B04425 (dec: -458210267), parent name: 'SoundObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long soundNumber;		  // size=0, offset=4 //  hashcode: 0xC2DDF5C8 (dec: -1025641016), parent name: 'SoundObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value;				  // size=0, offset=8 //  hashcode: 0xFAC13733 (dec: -88000717), parent name: 'SoundObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long duration;			  // size=0, offset=12 //  hashcode: 0x87824BCE (dec: -2021504050), parent name: 'SoundObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	union DEBUG_262fake data; // size=4, offset=16 //  hashcode: 0x952EF9A3 (dec: -1792083549), parent name: 'SoundObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_263fake // hashcode: 0x5ADDB32F (dec: 1524478767)
{
	long instanceNumber; // size=0, offset=0 //  hashcode: 0xDC3406A5 (dec: -600570203), parent name: 'DEBUG_263fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;		 // size=0, offset=4 //  hashcode: 0x5A2AB99D (dec: 1512749469), parent name: 'DEBUG_263fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_264fake // hashcode: 0xB18AA11E (dec: -1316314850)
{
	struct _SavedIntro *intro; // size=40, offset=0 //  hashcode: 0xA16FEF71 (dec: -1586499727), parent name: 'DEBUG_264fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;			   // size=0, offset=4 //  hashcode: 0xCA63A2B0 (dec: -899439952), parent name: 'DEBUG_264fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_265fake // hashcode: 0x999EC4A9 (dec: -1717648215)
{
	long currentNumber; // size=0, offset=0 //  hashcode: 0x406FCB77 (dec: 1081068407), parent name: 'DEBUG_265fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long error;			// size=0, offset=4 //  hashcode: 0x791486B5 (dec: 2031388341), parent name: 'DEBUG_265fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;		// size=0, offset=8 //  hashcode: 0xF36510D1 (dec: -211480367), parent name: 'DEBUG_265fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_266fake // hashcode: 0xE9461CD8 (dec: -381281064)
{
	short vx; // size=0, offset=0 //  hashcode: 0xDF739A06 (dec: -546072058), parent name: 'DEBUG_266fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vy; // size=0, offset=2 //  hashcode: 0x4F6B0AC4 (dec: 1332415172), parent name: 'DEBUG_266fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_267fake // hashcode: 0x64B78660 (dec: 1689749088)
{
	char *pointer; // size=0, offset=0 //  hashcode: 0x75EFA761 (dec: 1978640225), parent name: 'DEBUG_267fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_268fake // hashcode: 0xEAB4D447 (dec: -357247929)
{
	short *pointer; // size=0, offset=0 //  hashcode: 0x5CC4B15D (dec: 1556394333), parent name: 'DEBUG_268fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DEBUG_269fake // hashcode: 0x38AC90B6 (dec: 950833334)
{
	long *pointer; // size=0, offset=0 //  hashcode: 0x018E2329 (dec: 26092329), parent name: 'DEBUG_269fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union DEBUG_270fake // Hashcode: 0x65C9BE55 (dec: 1707720277)
{
	struct DEBUG_263fake Object;					  // size=8, offset=0
	struct DEBUG_264fake SavedIntroObject;			  // size=8, offset=0
	struct InstanceSpline instanceSpline;			  // size=24, offset=0
	struct DEBUG_265fake Number;					  // size=12, offset=0
	struct DEBUG_266fake Vector2d;					  // size=4, offset=0
	struct DEBUG_267fake CharPointer;				  // size=4, offset=0
	struct DEBUG_268fake ShortPointer;				  // size=4, offset=0
	struct DEBUG_269fake LongPointer;				  // size=4, offset=0
	struct AreaObject areaObject;					  // size=12, offset=0
	struct InstanceObject instanceObject;			  // size=8, offset=0
	struct Vector3d vector3d;						  // size=20, offset=0
	struct Rotation3d rotation3d;					  // size=20, offset=0
	struct SignalObject signalObject;				  // size=8, offset=0
	struct EventObject eventObject;					  // size=8, offset=0
	struct GameObject gameObject;					  // size=4, offset=0
	struct ListObject listObject;					  // size=32, offset=0
	struct IntroObject introObject;					  // size=8, offset=0
	struct InstanceAnimate instanceAnimate;			  // size=8, offset=0
	struct InstanceAnimateTexture instanceAniTexture; // size=12, offset=0
	struct SavedEventObject savedEventObject;		  // size=16, offset=0
	struct SubListObject subListObject;				  // size=32, offset=0
	struct TGroupObject terrainGroup;				  // size=16, offset=0
	struct ConstrictInfo constrictInfo;				  // size=8, offset=0
	struct CameraObject cameraObject;				  // size=12, offset=0
	struct EventVmObject vmObject;					  // size=12, offset=0
	struct SoundObject soundObject;					  // size=20, offset=0
};

struct StackType // hashcode: 0x9CE4C465 (dec: -1662729115)
{
	long id;				  // size=0, offset=0 //  hashcode: 0x8F826DBE (dec: -1887277634), parent name: 'StackType', parent hashcode: 0xFFFFFFFF (dec: -1)
	union DEBUG_270fake data; // size=32, offset=4 //  hashcode: 0x001AACD6 (dec: 1748182), parent name: 'StackType', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __ReaverSaveDat // hashcode: 0x18BBFFA1 (dec: 414973857)
{
	unsigned long pad; // size=0, offset=0 //  hashcode: 0x5B68CF70 (dec: 1533595504), parent name: '__ReaverSaveDat', parent hashcode: 0xFFFFFFFF (dec: -1)
};

enum option_ctrl_t // Hashcode: 0x33E11B37 (dec: 870390583)
{
	option_ctrl_bogus = 0,
	option_ctrl_none = 1,
	option_ctrl_select = 2,
	option_ctrl_left = 3,
	option_ctrl_right = 4,
	option_ctrl_num_states = 5,
};

struct GameCheat // hashcode: 0x9BFF36C0 (dec: -1677773120)
{
	unsigned char cheatKeys[12]; // size=12, offset=0 //  hashcode: 0x1CB6F39E (dec: 481751966), parent name: 'GameCheat', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cheatLen;				 // size=0, offset=12 //  hashcode: 0xAA3D38CF (dec: -1438828337), parent name: 'GameCheat', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cheatStage;			 // size=0, offset=14 //  hashcode: 0x9A7B5F63 (dec: -1703190685), parent name: 'GameCheat', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct debug_dispatch_t // hashcode: 0x928EA8E4 (dec: -1836144412)
{
	enum DEBUG_LINE_TYPE type; // size=4, offset=0 //  hashcode: 0x083F990E (dec: 138385678), parent name: 'debug_dispatch_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*fn)();			   // size=0, offset=4 //  hashcode: 0xC2E34713 (dec: -1025292525), parent name: 'debug_dispatch_t', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct debug_format_t // hashcode: 0xCC4C6103 (dec: -867409661)
{
	int xpos;		 // size=0, offset=0 //  hashcode: 0xC702D854 (dec: -956114860), parent name: 'debug_format_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int ypos;		 // size=0, offset=4 //  hashcode: 0xA45DA649 (dec: -1537366455), parent name: 'debug_format_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int is_centered; // size=0, offset=8 //  hashcode: 0xBF3A21FC (dec: -1086709252), parent name: 'debug_format_t', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct POLY_F4 POLY_F4;

typedef struct _SmallRotation SmallRotation;

typedef struct Camera Camera;

typedef struct DebugMenuLine DebugMenuLine;

typedef struct _ButtonTexture ButtonTexture;

typedef struct FontChar FontChar;

typedef struct _BigFileEntry BigFileEntry;

typedef struct _BigFileDirEntry BigFileDirEntry;

typedef struct _BigFileDir BigFileDir;

typedef struct _BigFile BigFile;

typedef struct _NonBlockLoadEntry NonBlockLoadEntry;

typedef struct _ReadQueueEntry ReadQueueEntry;

typedef struct _FX_MATRIX FX_MATRIX;

typedef struct _FX_PRIM FX_PRIM;

typedef struct BASIC_LINE_G2 BASIC_LINE_G2;

typedef struct _BASIC_G4 BASIC_G4;

typedef struct _BASIC_F4 BASIC_F4;

typedef struct __BubbleParams BubbleParams;

typedef struct _GenericParticleParams GenericParticleParams;

typedef struct _GenericRibbonParams GenericRibbonParams;

typedef struct _GenericGlowParams GenericGlowParams;

typedef struct _GenericLightningParams GenericLightningParams;

typedef struct _GenericBlastringParams GenericBlastringParams;

typedef struct _GenericFlashParams GenericFlashParams;

typedef struct _StreamUnit StreamUnit;

typedef struct XAFileInfo XAFileInfo;

typedef struct CdCommand CdCommand;

typedef struct VoiceCommand VoiceCommand;

typedef struct _LoadQueueEntry LoadQueueEntry;

typedef struct _BlockVramEntry BlockVramEntry;

typedef struct SavedBasic SavedBasic;

typedef struct _SavedIntro SavedIntro;

typedef struct SavedEvent SavedEvent;

typedef struct SavedBspTree SavedBspTree;

typedef struct EventBasicObject EventBasicObject;

typedef struct EventWildCardObject EventWildCardObject;

typedef struct ScriptPCode ScriptPCode;

typedef struct Event Event;

typedef struct EventPointers EventPointers;

typedef struct InstanceSpline InstanceSpline;

typedef struct Vector3d Vector3d;

typedef struct Rotation3d Rotation3d;

typedef struct InstanceObject InstanceObject;

typedef struct EventObject EventObject;

typedef struct SavedEventObject SavedEventObject;

typedef struct GameObject GameObject;

typedef struct SignalObject SignalObject;

typedef struct IntroObject IntroObject;

typedef struct InstanceAnimate InstanceAnimate;

typedef struct InstanceAnimateTexture InstanceAnimateTexture;

typedef struct ListObject ListObject;

typedef struct SubListObject SubListObject;

typedef struct TGroupObject TGroupObject;

typedef struct ConstrictInfo ConstrictInfo;

typedef struct CameraObject CameraObject;

typedef struct EventVmObject EventVmObject;

typedef struct AreaObject AreaObject;

typedef struct SoundObject SoundObject;

typedef struct StackType StackType;

typedef struct __ReaverSaveDat ReaverSaveData;

typedef enum option_ctrl_t option_ctrl_t;

typedef struct GameCheat GameCheat;

typedef struct debug_dispatch_t debug_dispatch_t;

typedef struct debug_format_t debug_format_t;

typedef void FX_PRIM_MODIFY_PROCESS();

typedef void FX_PROCESS();

typedef void FX_PARTICLE_PROCESS();

typedef void FX_GENERAL_PROCESS();

typedef void FX_SETUP();

typedef long TFract;

typedef void (*LoadReturnProc)();

typedef void (*BufferedLoadReturnProc)();

typedef void option_fn_t();

typedef int menu_fn_t();

typedef unsigned char CheatKey;

typedef void debug_dispatch_fn_t();

extern void DEBUG_UpdateHealth(long *var); // 0x80012EC0

extern void DEBUG_UpdateMana(long *var); // 0x80012EE4

extern void DEBUG_FillUpHealth(long *var); // 0x80012F08

extern void process_cheat_codes(struct GameTracker *gt, long *ctrl); // 0x80012F30

extern void DEBUG_Process(struct GameTracker *gameTracker); // 0x800131F8

extern void DEBUG_Draw(struct GameTracker *gameTracker, unsigned long **ot); // 0x800133A4

extern long DEBUG_MenuCountLength(struct DebugMenuLine *menu); // 0x800133EC

extern void DEBUG_ExitMenus(); // 0x80013418

extern struct DebugMenuLine *get_last_menu_line(struct DebugMenuLine *line); // 0x800134B0

extern int num_menu_items(struct DebugMenuLine *menu); // 0x800134E0

extern void maybe_change_menu_choice(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x80013510

extern void handle_line_type_long(struct GameTracker *gt, struct DebugMenuLine *line); // 0x800135D8

extern void handle_line_type_bit(struct GameTracker *gt, struct DebugMenuLine *line); // 0x800136C4

extern void handle_line_type_action(struct GameTracker *gt, struct DebugMenuLine *line); // 0x8001371C

extern void handle_line_type_action_with_line(struct GameTracker *gt, struct DebugMenuLine *line); // 0x80013758

extern void handle_line_type_menu(struct GameTracker *gt, struct DebugMenuLine *line); // 0x800137BC

extern void process_menu_line(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x8001383C

extern int pre_process_functions(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x800138A0

extern void post_process_functions(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x800138C8

extern void set_debug_leading(); // 0x8001396C

extern void set_user_leading(); // 0x80013984

extern int isdigit(char c); // 0x8001399C

extern void adjust_format(char *ctrl, struct debug_format_t *fmt); // 0x800139AC

extern char *find_eol(char *text); // 0x80013B54

extern void draw_menu_item(struct GameTracker *gt, struct debug_format_t *fmt, char *text); // 0x80013B8C

extern void draw_menu(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x80013C8C

extern void DEBUG_Menu(struct GameTracker *gt); // 0x80013E98

extern void DEBUG_DisplayStatus(struct GameTracker *gameTracker); // 0x80013FAC

extern void DEBUG_DrawShrinkCels(unsigned long **polyAddr); // 0x80014214

extern void DEBUG_ContinueGame(); // 0x8001421C

extern void DEBUG_ExitGame(); // 0x80014234

extern void DEBUG_EndViewVram(struct GameTracker *gameTracker); // 0x80014270

extern void DEBUG_ViewVram(struct GameTracker *gameTracker); // 0x800142C0

extern void DEBUG_CaptureScreen(struct GameTracker *gameTracker); // 0x800143E0

extern void DEBUG_PageFlip(); // 0x800143E8

extern void DEBUG_FatalError(char *fmt); // 0x800144F0

extern void DEBUG_ProcessSecondController(struct GameTracker *gameTracker); // 0x80014544

extern void DEBUG_ProcessCheat(struct GameTracker *gameTracker); // 0x8001454C

extern void DEBUG_DoAreaProtection(); // 0x800146C0

#endif
