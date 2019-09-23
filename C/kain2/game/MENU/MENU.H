#ifndef MENU_H
#define MENU_H

enum menu_ctrl_t // Hashcode: 0xE0BD1E93 (dec: -524476781)
{
	menu_ctrl_none = 0,
	menu_ctrl_up = 1,
	menu_ctrl_down = 2,
	menu_ctrl_left = 3,
	menu_ctrl_right = 4,
	menu_ctrl_engage = 5,
	menu_ctrl_cancel = 6,
	menu_ctrl_start = 7,
	menu_ctrl_num_items = 8,
};

enum menu_sound_t // Hashcode: 0x0248C7C9 (dec: 38324169)
{
	menu_sound_none = 0,
	menu_sound_default = 1,
	menu_sound_select = 2,
	menu_sound_adjust = 3,
	menu_sound_engage = 4,
	menu_sound_pop = 5,
};

struct menu_t // hashcode: 0x8AB0D2F2 (dec: -1968123150)
{
	int nmenus;					  // size=0, offset=0 //  hashcode: 0xE063411F (dec: -530366177), parent name: 'menu_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nitems;					  // size=0, offset=4 //  hashcode: 0xE1E03A81 (dec: -505398655), parent name: 'menu_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nbytes;					  // size=0, offset=8 //  hashcode: 0xC1054799 (dec: -1056618599), parent name: 'menu_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct menu_stack_t stack[5]; // size=180, offset=12 //  hashcode: 0xB6099EBA (dec: -1240883526), parent name: 'menu_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct menu_item_t items[12]; // size=192, offset=192 //  hashcode: 0x09AAC749 (dec: 162187081), parent name: 'menu_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	char bytes[512];			  // size=512, offset=384 //  hashcode: 0x75ACB0C4 (dec: 1974251716), parent name: 'menu_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*drawfn)();			  // size=0, offset=896 //  hashcode: 0x1187ADD6 (dec: 294104534), parent name: 'menu_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *opaque;				  // size=0, offset=900 //  hashcode: 0x4892C470 (dec: 1217578096), parent name: 'menu_t', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_68fake // hashcode: 0x12F31026 (dec: 317919270)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x1C7D8D50 (dec: 477990224), parent name: 'MENU_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x8FF2B159 (dec: -1879920295), parent name: 'MENU_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_69fake // hashcode: 0x7916AE53 (dec: 2031529555)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xF7F1B3FD (dec: -135154691), parent name: 'MENU_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xCB052207 (dec: -888856057), parent name: 'MENU_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_70fake // hashcode: 0xE63D8D58 (dec: -432173736)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x155E47CE (dec: 358500302), parent name: 'MENU_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x1C1D480A (dec: 471681034), parent name: 'MENU_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MENU_71fake // Hashcode: 0x9417F09E (dec: -1810370402)
{
	struct MENU_68fake callback; // size=8, offset=0
	struct MENU_69fake vector;   // size=12, offset=0
	struct MENU_70fake quat;	 // size=16, offset=0
};

union MENU_72fake // Hashcode: 0xE575C374 (dec: -445267084)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MENU_73fake // Hashcode: 0xEC39220B (dec: -331800053)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct MENU_74fake // hashcode: 0x153C7114 (dec: 356282644)
{
	union MENU_73fake size; // size=4, offset=0 //  hashcode: 0x0B62E755 (dec: 191031125), parent name: 'MENU_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_75fake // hashcode: 0x28B257F1 (dec: 682776561)
{
	short x;				// size=0, offset=0 //  hashcode: 0x3E074F82 (dec: 1040666498), parent name: 'MENU_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xDD9E9B03 (dec: -576808189), parent name: 'MENU_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x76A558C5 (dec: 1990547653), parent name: 'MENU_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x99581537 (dec: -1722280649), parent name: 'MENU_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xF959A63E (dec: -111565250), parent name: 'MENU_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_76fake // hashcode: 0x0115863F (dec: 18187839)
{
	long index; // size=0, offset=0 //  hashcode: 0xBE39BA3A (dec: -1103513030), parent name: 'MENU_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x7045044D (dec: 1883571277), parent name: 'MENU_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_77fake // hashcode: 0x1CD670A3 (dec: 483815587)
{
	long index; // size=0, offset=0 //  hashcode: 0x8D435E39 (dec: -1924964807), parent name: 'MENU_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xEA3C9C9D (dec: -365126499), parent name: 'MENU_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_78fake // hashcode: 0xA716283F (dec: -1491720129)
{
	long index; // size=0, offset=0 //  hashcode: 0xA7E85D13 (dec: -1477944045), parent name: 'MENU_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x78BCF232 (dec: 2025648690), parent name: 'MENU_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_79fake // hashcode: 0xE4508C74 (dec: -464483212)
{
	long time;  // size=0, offset=0 //  hashcode: 0x6CC7044F (dec: 1824982095), parent name: 'MENU_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x0DB1BE28 (dec: 229752360), parent name: 'MENU_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_80fake // hashcode: 0x4A347B21 (dec: 1244953377)
{
	long action;   // size=0, offset=0 //  hashcode: 0x5F60FFA6 (dec: 1600192422), parent name: 'MENU_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x614310F5 (dec: 1631785205), parent name: 'MENU_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_81fake // hashcode: 0xA04E3F92 (dec: -1605484654)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x8CBF40C7 (dec: -1933623097), parent name: 'MENU_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x1A211959 (dec: 438376793), parent name: 'MENU_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_82fake // hashcode: 0xAFCC8696 (dec: -1345550698)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x263E279A (dec: 641607578), parent name: 'MENU_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0xE77B3149 (dec: -411356855), parent name: 'MENU_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_83fake // hashcode: 0x67836132 (dec: 1736663346)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xD0679D74 (dec: -798515852), parent name: 'MENU_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xFA47A0B8 (dec: -95969096), parent name: 'MENU_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_84fake // hashcode: 0x584A3000 (dec: 1481256960)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x538FFC09 (dec: 1401945097), parent name: 'MENU_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xD20A22E0 (dec: -771087648), parent name: 'MENU_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x77C1A23F (dec: 2009178687), parent name: 'MENU_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x1ECB81ED (dec: 516653549), parent name: 'MENU_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x5602A0E7 (dec: 1443012839), parent name: 'MENU_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_85fake // hashcode: 0x46CAF822 (dec: 1187706914)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x650917BA (dec: 1695094714), parent name: 'MENU_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x2ED11297 (dec: 785453719), parent name: 'MENU_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_86fake // hashcode: 0x668F2679 (dec: 1720657529)
{
	short index;					// size=0, offset=0 //  hashcode: 0x47CC6F77 (dec: 1204580215), parent name: 'MENU_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x54898491 (dec: 1418298513), parent name: 'MENU_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x916C3AB0 (dec: -1855178064), parent name: 'MENU_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x8A42EF2E (dec: -1975324882), parent name: 'MENU_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_87fake // hashcode: 0x7A941733 (dec: 2056525619)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x42D4FBB5 (dec: 1121254325), parent name: 'MENU_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xF741A147 (dec: -146693817), parent name: 'MENU_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x82A8F323 (dec: -2102856925), parent name: 'MENU_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_88fake // hashcode: 0x53AFA3E3 (dec: 1404019683)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xE64D0348 (dec: -431160504), parent name: 'MENU_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xFC755C8C (dec: -59417460), parent name: 'MENU_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xA92AAEE3 (dec: -1456820509), parent name: 'MENU_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xD3E2C947 (dec: -740112057), parent name: 'MENU_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xEB913B96 (dec: -342803562), parent name: 'MENU_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x42DE6064 (dec: 1121869924), parent name: 'MENU_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x9E42EEBD (dec: -1639780675), parent name: 'MENU_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_89fake // hashcode: 0x0E069730 (dec: 235312944)
{
	long index;  // size=0, offset=0 //  hashcode: 0x590CD8DC (dec: 1494014172), parent name: 'MENU_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x6C54612A (dec: 1817469226), parent name: 'MENU_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_90fake // hashcode: 0x382142F7 (dec: 941703927)
{
	short type; // size=0, offset=0 //  hashcode: 0x4CBD57B1 (dec: 1287477169), parent name: 'MENU_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xC9C83BB7 (dec: -909624393), parent name: 'MENU_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_91fake // hashcode: 0x2D854CBB (dec: 763710651)
{
	long time;   // size=0, offset=0 //  hashcode: 0xCD58DA3B (dec: -849814981), parent name: 'MENU_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x49BC6273 (dec: 1237082739), parent name: 'MENU_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_92fake // hashcode: 0x5B463D32 (dec: 1531329842)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x220C03B5 (dec: 571212725), parent name: 'MENU_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x4FEB23DC (dec: 1340810204), parent name: 'MENU_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_93fake // hashcode: 0xEBCC74B7 (dec: -338922313)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x1AAA3F20 (dec: 447364896), parent name: 'MENU_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x4AB8D501 (dec: 1253627137), parent name: 'MENU_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_94fake // hashcode: 0x24F5D5C9 (dec: 620090825)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xB88B1164 (dec: -1198845596), parent name: 'MENU_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x3F42D115 (dec: 1061343509), parent name: 'MENU_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_95fake // hashcode: 0x29AAD7FB (dec: 699062267)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x646809A3 (dec: 1684539811), parent name: 'MENU_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xF1645192 (dec: -245083758), parent name: 'MENU_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x203BE214 (dec: 540795412), parent name: 'MENU_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xC1EE05B5 (dec: -1041365579), parent name: 'MENU_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_96fake // hashcode: 0x5624F398 (dec: 1445262232)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x16300241 (dec: 372245057), parent name: 'MENU_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x1C9F3DF2 (dec: 480198130), parent name: 'MENU_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x1B3D67EF (dec: 457009135), parent name: 'MENU_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xB5F447F8 (dec: -1242281992), parent name: 'MENU_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xB41158B9 (dec: -1273931591), parent name: 'MENU_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MENU_97fake // Hashcode: 0x999E96A2 (dec: -1717659998)
{
	struct MENU_74fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;	// size=24, offset=0
	struct MENU_75fake teleport;	 // size=16, offset=0
	struct MENU_76fake cameraValue;  // size=8, offset=0
	struct MENU_77fake miscValue;	// size=8, offset=0
	struct MENU_78fake logicValue;   // size=8, offset=0
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
	struct MENU_79fake cameraShake;  // size=8, offset=0
	long cameraSave;				 // size=0, offset=0
	long cameraRestore;				 // size=0, offset=0
	struct _BGObject *bgObject;		 // size=24, offset=0
	long value[2];					 // size=8, offset=0
	struct MENU_80fake sound;		 // size=12, offset=0
	void *intro;					 // size=0, offset=0
	long deathZ;					 // size=0, offset=0
	struct MENU_81fake dsignal;		 // size=8, offset=0
	void *mirror;					 // size=0, offset=0
	long fogNear;					 // size=0, offset=0
	long fogFar;					 // size=0, offset=0
	struct MENU_82fake gotoFrame;	// size=8, offset=0
	struct MENU_83fake changeModel;  // size=8, offset=0
	void *vmObject;					 // size=0, offset=0
	struct MENU_84fake logic;		 // size=8, offset=0
	void *callSignal;				 // size=0, offset=0
	struct _SVector offset;			 // size=8, offset=0
	struct Signal *gotoLabel;		 // size=0, offset=0
	struct Signal *gosubLabel;		 // size=0, offset=0
	struct MENU_85fake control;		 // size=8, offset=0
	struct MENU_86fake zSignal;		 // size=12, offset=0
	struct MENU_87fake StreamLevel;  // size=24, offset=0
	struct MENU_88fake shards;		 // size=12, offset=0
	struct MENU_89fake cameraSpline; // size=8, offset=0
	struct MENU_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;				 // size=0, offset=0
	struct MENU_91fake introFX;		 // size=8, offset=0
	struct MENU_92fake introActive;  // size=8, offset=0
	struct MENU_93fake levelChange;  // size=18, offset=0
	long blendStart;				 // size=0, offset=0
	struct MENU_94fake setTimes;	 // size=8, offset=0
	struct MENU_95fake color;		 // size=4, offset=0
	struct MENU_96fake print;		 // size=12, offset=0
	long slideAngle;				 // size=0, offset=0
};

union MENU_98fake // Hashcode: 0x5E4ECEB5 (dec: 1582223029)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union MENU_103fake // Hashcode: 0x544F515D (dec: 1414484317)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct MENU_109fake // hashcode: 0xC0391E8B (dec: -1069998453)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xFF6F0D74 (dec: -9499276), parent name: 'MENU_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x4C4848C7 (dec: 1279805639), parent name: 'MENU_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0xE515208F (dec: -451600241), parent name: 'MENU_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x5FFB83C6 (dec: 1610318790), parent name: 'MENU_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x5E5A5F01 (dec: 1582980865), parent name: 'MENU_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xB2A78420 (dec: -1297644512), parent name: 'MENU_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xD60C2DC8 (dec: -703844920), parent name: 'MENU_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_110fake // hashcode: 0x8C0203E2 (dec: -1946024990)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0xB8CD3ECB (dec: -1194508597), parent name: 'MENU_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xA4AB2B90 (dec: -1532286064), parent name: 'MENU_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x91A4E6DB (dec: -1851463973), parent name: 'MENU_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_111fake // hashcode: 0xA834055D (dec: -1472985763)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0xB970E84F (dec: -1183782833), parent name: 'MENU_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x7E82E794 (dec: 2122508180), parent name: 'MENU_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x8FC37CFB (dec: -1883013893), parent name: 'MENU_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xAA0E680C (dec: -1441896436), parent name: 'MENU_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xD92FEDA2 (dec: -651170398), parent name: 'MENU_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_112fake // hashcode: 0x9F9A7FF7 (dec: -1617264649)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xC14F31E9 (dec: -1051774487), parent name: 'MENU_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x633C7EA1 (dec: 1664908961), parent name: 'MENU_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x649ADB94 (dec: 1687870356), parent name: 'MENU_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x69022407 (dec: 1761747975), parent name: 'MENU_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xAC35DDFB (dec: -1405755909), parent name: 'MENU_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENU_113fake // hashcode: 0x792A6BAF (dec: 2032823215)
{
	struct MENU_109fake Cinematic; // size=28, offset=0 //  hashcode: 0x206F4682 (dec: 544163458), parent name: 'MENU_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MENU_110fake Idle;	  // size=20, offset=28 //  hashcode: 0xD98CA7BF (dec: -645093441), parent name: 'MENU_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MENU_111fake Behind;	// size=28, offset=48 //  hashcode: 0xE826D850 (dec: -400107440), parent name: 'MENU_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MENU_112fake Follow;	// size=20, offset=76 //  hashcode: 0x6A637F98 (dec: 1784905624), parent name: 'MENU_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct menu_format_t // hashcode: 0xD91CEBF0 (dec: -652416016)
{
	int xpos;	 // size=0, offset=0 //  hashcode: 0x9C76E395 (dec: -1669930091), parent name: 'menu_format_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int ypos;	 // size=0, offset=4 //  hashcode: 0x5192FBD2 (dec: 1368587218), parent name: 'menu_format_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int lineskip; // size=0, offset=8 //  hashcode: 0xDFCF8F70 (dec: -540045456), parent name: 'menu_format_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int itemskip; // size=0, offset=12 //  hashcode: 0x4A4857EA (dec: 1246255082), parent name: 'menu_format_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int width;	// size=0, offset=16 //  hashcode: 0x1D6B971D (dec: 493590301), parent name: 'menu_format_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int center;   // size=0, offset=20 //  hashcode: 0xE72FA6EF (dec: -416307473), parent name: 'menu_format_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int border;   // size=0, offset=24 //  hashcode: 0xC85DD871 (dec: -933373839), parent name: 'menu_format_t', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct menu_stack_t // hashcode: 0x04101191 (dec: 68161937)
{
	int (*fn)();				 // size=0, offset=0 //  hashcode: 0x92053651 (dec: -1845152175), parent name: 'menu_stack_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int index;					 // size=0, offset=4 //  hashcode: 0x00CD58AB (dec: 13457579), parent name: 'menu_stack_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct menu_format_t format; // size=28, offset=8 //  hashcode: 0x76C91D34 (dec: 1992891700), parent name: 'menu_stack_t', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct menu_item_t // hashcode: 0xF260D8A8 (dec: -228534104)
{
	char *text;		// size=0, offset=0 //  hashcode: 0x7AAA40F3 (dec: 2057978099), parent name: 'menu_item_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int (*fn)();	// size=0, offset=4 //  hashcode: 0x81F33CD6 (dec: -2114765610), parent name: 'menu_item_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	long parameter; // size=0, offset=8 //  hashcode: 0x4898D616 (dec: 1217975830), parent name: 'menu_item_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;		// size=0, offset=12 //  hashcode: 0x45F73888 (dec: 1173829768), parent name: 'menu_item_t', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct Extents2d // hashcode: 0x49E3CF7D (dec: 1239666557)
{
	int xmin; // size=0, offset=0 //  hashcode: 0x04F42BF5 (dec: 83110901), parent name: 'Extents2d', parent hashcode: 0xFFFFFFFF (dec: -1)
	int xmax; // size=0, offset=4 //  hashcode: 0x4F22D76A (dec: 1327683434), parent name: 'Extents2d', parent hashcode: 0xFFFFFFFF (dec: -1)
	int ymin; // size=0, offset=8 //  hashcode: 0x47F24F41 (dec: 1207062337), parent name: 'Extents2d', parent hashcode: 0xFFFFFFFF (dec: -1)
	int ymax; // size=0, offset=12 //  hashcode: 0x24015A63 (dec: 604068451), parent name: 'Extents2d', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef enum menu_ctrl_t menu_ctrl_t;

typedef enum menu_sound_t menu_sound_t;

typedef struct menu_t menu_t;

typedef struct menu_format_t menu_format_t;

typedef struct menu_stack_t menu_stack_t;

typedef struct menu_item_t menu_item_t;

typedef struct Extents2d Extents2d;

typedef int menu_item_fn_t();

typedef void menu_draw_fn_t();

extern int menu_data_size(); // 0x800B7A40

extern void menu_initialize(struct menu_t *menu, void *opaque); // 0x800B7A48

extern void menu_format(struct menu_t *menu, int center, int xpos, int ypos, int width, int lineskip, int itemskip, int border); // 0x800B7A8C

extern void menu_set(struct menu_t *menu, TDRFuncPtr_menu_set1fn fn); // 0x800B7ADC

extern void menu_push(struct menu_t *menu, TDRFuncPtr_menu_push1fn fn); // 0x800B7B00

extern void menu_pop(struct menu_t *menu); // 0x800B7B70

extern void menu_item_flags(struct menu_t *menu, TDRFuncPtr_menu_item_flags1fn fn, long parameter, long flags, char *format); // 0x800B7B84

extern void menu_item(struct menu_t *menu, TDRFuncPtr_menu_item1fn fn, long parameter, char *format); // 0x800B7C14

extern void menu_build(struct menu_t *menu); // 0x800B7CB8

extern void DisplayHintBox(int len, int y); // 0x800B7D10

extern void DisplayMenuBox(int x0, int x1, int y0, int y1); // 0x800B7E3C

extern int menu_draw_item(struct menu_t *menu, int ypos, int xadj, int yadj, char *text, int color, long flags, struct Extents2d *e); // 0x800B8074

extern void menu_draw(struct menu_t *menu); // 0x800B8478

extern void menu_run(struct menu_t *menu); // 0x800B85D8

extern void menu_process(struct menu_t *menu); // 0x800B87C8

typedef int (*TDRFuncPtr_menu_item_flags1fn)();

typedef int (*TDRFuncPtr_menu_item1fn)();

typedef int (*TDRFuncPtr_menu_push1fn)();

typedef int (*TDRFuncPtr_menu_set1fn)();

#endif
