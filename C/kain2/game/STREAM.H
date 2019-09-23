#ifndef STREAM_H
#define STREAM_H

extern short MORPH_Component[3]; // offset 0x800D1914

extern struct _TFace *MORPH_SavedFace; // offset 0x800D1D20

extern struct Level *MORPH_SavedLevel; // offset 0x800D1910

extern short MORPH_Track[2]; // offset 0x800D191C

static int s_zval; // offset 0x800D18F8

extern struct STracker StreamTracker; // offset 0x800D1920

extern struct STREAM_294fake WarpGateLoadInfo; // offset 0x800D18FC

extern struct WarpRoom WarpRoomArray[14]; // offset 0x800CF200

struct POLY_G4 // hashcode: 0x82B947DC (dec: -2101786660)
{
	unsigned long tag;  // size=0, offset=0 //  hashcode: 0xC24CBE56 (dec: -1035157930), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;   // size=0, offset=4 //  hashcode: 0x3866D3E2 (dec: 946263010), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;   // size=0, offset=5 //  hashcode: 0x9A4BFB05 (dec: -1706296571), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;   // size=0, offset=6 //  hashcode: 0x1C32063A (dec: 473040442), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code; // size=0, offset=7 //  hashcode: 0x772954CD (dec: 1999197389), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			// size=0, offset=8 //  hashcode: 0x4463911B (dec: 1147375899), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			// size=0, offset=10 //  hashcode: 0x724998C7 (dec: 1917425863), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r1;   // size=0, offset=12 //  hashcode: 0x9910D713 (dec: -1726949613), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g1;   // size=0, offset=13 //  hashcode: 0x56896334 (dec: 1451844404), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b1;   // size=0, offset=14 //  hashcode: 0x22CE5AB7 (dec: 583948983), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad1; // size=0, offset=15 //  hashcode: 0x48456F3C (dec: 1212510012), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			// size=0, offset=16 //  hashcode: 0xBACE8FBF (dec: -1160867905), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			// size=0, offset=18 //  hashcode: 0xAAD11BD3 (dec: -1429136429), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r2;   // size=0, offset=20 //  hashcode: 0xEDDAECB5 (dec: -304419659), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g2;   // size=0, offset=21 //  hashcode: 0xF31976B5 (dec: -216435019), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b2;   // size=0, offset=22 //  hashcode: 0xEEFE7F51 (dec: -285311151), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad2; // size=0, offset=23 //  hashcode: 0xC595D8AB (dec: -980035413), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;			// size=0, offset=24 //  hashcode: 0x92715D30 (dec: -1838064336), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;			// size=0, offset=26 //  hashcode: 0x01B18D32 (dec: 28413234), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r3;   // size=0, offset=28 //  hashcode: 0xD7B6E1BF (dec: -675880513), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g3;   // size=0, offset=29 //  hashcode: 0x94093031 (dec: -1811337167), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b3;   // size=0, offset=30 //  hashcode: 0x61618730 (dec: 1633781552), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad3; // size=0, offset=31 //  hashcode: 0xE1B4F777 (dec: -508233865), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x3;			// size=0, offset=32 //  hashcode: 0x9EC6F39A (dec: -1631128678), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y3;			// size=0, offset=34 //  hashcode: 0x2460B56E (dec: 610317678), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DR_AREA // hashcode: 0xE0CED39B (dec: -523316325)
{
	unsigned long tag;	 // size=0, offset=0 //  hashcode: 0x3F19BDB7 (dec: 1058651575), parent name: 'DR_AREA', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long code[2]; // size=8, offset=4 //  hashcode: 0xAFBADC76 (dec: -1346708362), parent name: 'DR_AREA', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_73fake // hashcode: 0xCCE1BBC6 (dec: -857621562)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xE31B8044 (dec: -484736956), parent name: 'STREAM_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x4D53BE78 (dec: 1297333880), parent name: 'STREAM_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_74fake // hashcode: 0xB441BB27 (dec: -1270760665)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xAAF2A187 (dec: -1426939513), parent name: 'STREAM_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x0826048A (dec: 136709258), parent name: 'STREAM_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_75fake // hashcode: 0x62A1F22F (dec: 1654780463)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x9C754798 (dec: -1670035560), parent name: 'STREAM_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x41DECFF5 (dec: 1105121269), parent name: 'STREAM_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union STREAM_76fake // Hashcode: 0x4C037A0C (dec: 1275296268)
{
	struct STREAM_73fake callback; // size=8, offset=0
	struct STREAM_74fake vector;   // size=12, offset=0
	struct STREAM_75fake quat;	 // size=16, offset=0
};

union STREAM_77fake // Hashcode: 0x616584A0 (dec: 1634043040)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union STREAM_78fake // Hashcode: 0x555BF793 (dec: 1432090515)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct STREAM_79fake // hashcode: 0xE7D50225 (dec: -405470683)
{
	union STREAM_78fake size; // size=4, offset=0 //  hashcode: 0x708B7E86 (dec: 1888190086), parent name: 'STREAM_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_80fake // hashcode: 0x73283DCF (dec: 1932017103)
{
	short x;				// size=0, offset=0 //  hashcode: 0xDAA07FA0 (dec: -627015776), parent name: 'STREAM_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x0E604A3C (dec: 241191484), parent name: 'STREAM_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x6D2835DE (dec: 1831351774), parent name: 'STREAM_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x2CE71460 (dec: 753341536), parent name: 'STREAM_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x63169D20 (dec: 1662426400), parent name: 'STREAM_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_81fake // hashcode: 0xA2547A77 (dec: -1571521929)
{
	long index; // size=0, offset=0 //  hashcode: 0xED63CD99 (dec: -312226407), parent name: 'STREAM_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xD7087FB4 (dec: -687308876), parent name: 'STREAM_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_82fake // hashcode: 0x3F3E6C4E (dec: 1061055566)
{
	long index; // size=0, offset=0 //  hashcode: 0x2D0AB9A7 (dec: 755677607), parent name: 'STREAM_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x31249513 (dec: 824481043), parent name: 'STREAM_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_83fake // hashcode: 0x72B9D803 (dec: 1924782083)
{
	long index; // size=0, offset=0 //  hashcode: 0x6E5EFC5A (dec: 1851718746), parent name: 'STREAM_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x9CD46B9F (dec: -1663800417), parent name: 'STREAM_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_84fake // hashcode: 0x307C369E (dec: 813446814)
{
	long time;  // size=0, offset=0 //  hashcode: 0xDF9452A1 (dec: -543927647), parent name: 'STREAM_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x0733256B (dec: 120792427), parent name: 'STREAM_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_85fake // hashcode: 0x080854CA (dec: 134763722)
{
	long action;   // size=0, offset=0 //  hashcode: 0x403E7428 (dec: 1077834792), parent name: 'STREAM_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xF9A5460E (dec: -106609138), parent name: 'STREAM_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_86fake // hashcode: 0xFC308B2A (dec: -63927510)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x72AC914E (dec: 1923912014), parent name: 'STREAM_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x8948CCFB (dec: -1991717637), parent name: 'STREAM_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_87fake // hashcode: 0x16214EBC (dec: 371281596)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x34B4E38C (dec: 884269964), parent name: 'STREAM_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x88654376 (dec: -2006629514), parent name: 'STREAM_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_88fake // hashcode: 0x6DA13C37 (dec: 1839283255)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x1BB4EED7 (dec: 464842455), parent name: 'STREAM_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xDF33B6C0 (dec: -550259008), parent name: 'STREAM_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_89fake // hashcode: 0x5725798B (dec: 1462073739)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x4B898CC6 (dec: 1267305670), parent name: 'STREAM_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xF59761A3 (dec: -174628445), parent name: 'STREAM_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x90E10C80 (dec: -1864299392), parent name: 'STREAM_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x2800605F (dec: 671113311), parent name: 'STREAM_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x301B9D23 (dec: 807116067), parent name: 'STREAM_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_90fake // hashcode: 0x2842B777 (dec: 675460983)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x74B4EC81 (dec: 1958014081), parent name: 'STREAM_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xDB07F231 (dec: -620236239), parent name: 'STREAM_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_91fake // hashcode: 0xAD3ACD5B (dec: -1388655269)
{
	short index;					// size=0, offset=0 //  hashcode: 0x68BD2E84 (dec: 1757228676), parent name: 'STREAM_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xB6E2D323 (dec: -1226648797), parent name: 'STREAM_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xE6FEF6A1 (dec: -419498335), parent name: 'STREAM_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x54C463BA (dec: 1422156730), parent name: 'STREAM_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_92fake // hashcode: 0xE036938A (dec: -533294198)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x321B418B (dec: 840647051), parent name: 'STREAM_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x1A816D8E (dec: 444689806), parent name: 'STREAM_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xDF3FD4FE (dec: -549464834), parent name: 'STREAM_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_93fake // hashcode: 0x628D1175 (dec: 1653412213)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x006112E1 (dec: 6361825), parent name: 'STREAM_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x42F67ECA (dec: 1123450570), parent name: 'STREAM_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x2B802082 (dec: 729817218), parent name: 'STREAM_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xB898D278 (dec: -1197944200), parent name: 'STREAM_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xC47EB740 (dec: -998328512), parent name: 'STREAM_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xB3E01416 (dec: -1277160426), parent name: 'STREAM_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x00037106 (dec: 225542), parent name: 'STREAM_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_94fake // hashcode: 0x1257B9BD (dec: 307739069)
{
	long index;  // size=0, offset=0 //  hashcode: 0x8A9C2BBB (dec: -1969476677), parent name: 'STREAM_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x8E9B9B00 (dec: -1902404864), parent name: 'STREAM_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_95fake // hashcode: 0x47B78226 (dec: 1203208742)
{
	short type; // size=0, offset=0 //  hashcode: 0x0F3681A8 (dec: 255230376), parent name: 'STREAM_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x9A6EBD49 (dec: -1704018615), parent name: 'STREAM_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_96fake // hashcode: 0x46158C29 (dec: 1175817257)
{
	long time;   // size=0, offset=0 //  hashcode: 0xA2ED90E2 (dec: -1561489182), parent name: 'STREAM_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xFB9C5438 (dec: -73640904), parent name: 'STREAM_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_97fake // hashcode: 0xD6647EBB (dec: -698057029)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x21732B77 (dec: 561195895), parent name: 'STREAM_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x2FCFC576 (dec: 802145654), parent name: 'STREAM_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_98fake // hashcode: 0xEE6662AD (dec: -295279955)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x68BC499D (dec: 1757170077), parent name: 'STREAM_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x4A168C34 (dec: 1242991668), parent name: 'STREAM_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_99fake // hashcode: 0xEE771380 (dec: -294186112)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x334DC2A0 (dec: 860734112), parent name: 'STREAM_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x0E9B2A74 (dec: 245049972), parent name: 'STREAM_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_100fake // hashcode: 0x2DCABFFB (dec: 768262139)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x0F177F42 (dec: 253198146), parent name: 'STREAM_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x0C85D3A3 (dec: 210097059), parent name: 'STREAM_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xB6C59442 (dec: -1228565438), parent name: 'STREAM_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x6E70C6A1 (dec: 1852884641), parent name: 'STREAM_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_101fake // hashcode: 0x735D8CA3 (dec: 1935510691)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xA6309678 (dec: -1506765192), parent name: 'STREAM_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x826468E4 (dec: -2107348764), parent name: 'STREAM_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x14D84616 (dec: 349718038), parent name: 'STREAM_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xF69053AA (dec: -158313558), parent name: 'STREAM_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x2BC1F3FE (dec: 734131198), parent name: 'STREAM_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union STREAM_102fake // Hashcode: 0xFFAD6F03 (dec: -5411069)
{
	struct STREAM_79fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	  // size=24, offset=0
	struct STREAM_80fake teleport;	 // size=16, offset=0
	struct STREAM_81fake cameraValue;  // size=8, offset=0
	struct STREAM_82fake miscValue;	// size=8, offset=0
	struct STREAM_83fake logicValue;   // size=8, offset=0
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
	struct STREAM_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				   // size=0, offset=0
	long cameraRestore;				   // size=0, offset=0
	struct _BGObject *bgObject;		   // size=24, offset=0
	long value[2];					   // size=8, offset=0
	struct STREAM_85fake sound;		   // size=12, offset=0
	void *intro;					   // size=0, offset=0
	long deathZ;					   // size=0, offset=0
	struct STREAM_86fake dsignal;	  // size=8, offset=0
	void *mirror;					   // size=0, offset=0
	long fogNear;					   // size=0, offset=0
	long fogFar;					   // size=0, offset=0
	struct STREAM_87fake gotoFrame;	// size=8, offset=0
	struct STREAM_88fake changeModel;  // size=8, offset=0
	void *vmObject;					   // size=0, offset=0
	struct STREAM_89fake logic;		   // size=8, offset=0
	void *callSignal;				   // size=0, offset=0
	struct _SVector offset;			   // size=8, offset=0
	struct Signal *gotoLabel;		   // size=0, offset=0
	struct Signal *gosubLabel;		   // size=0, offset=0
	struct STREAM_90fake control;	  // size=8, offset=0
	struct STREAM_91fake zSignal;	  // size=12, offset=0
	struct STREAM_92fake StreamLevel;  // size=24, offset=0
	struct STREAM_93fake shards;	   // size=12, offset=0
	struct STREAM_94fake cameraSpline; // size=8, offset=0
	struct STREAM_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				   // size=0, offset=0
	struct STREAM_96fake introFX;	  // size=8, offset=0
	struct STREAM_97fake introActive;  // size=8, offset=0
	struct STREAM_98fake levelChange;  // size=18, offset=0
	long blendStart;				   // size=0, offset=0
	struct STREAM_99fake setTimes;	 // size=8, offset=0
	struct STREAM_100fake color;	   // size=4, offset=0
	struct STREAM_101fake print;	   // size=12, offset=0
	long slideAngle;				   // size=0, offset=0
};

union STREAM_103fake // Hashcode: 0xECCB1DCE (dec: -322232882)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union STREAM_108fake // Hashcode: 0x651A6CA8 (dec: 1696230568)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct STREAM_110fake // hashcode: 0x9E0CD274 (dec: -1643326860)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x6F963548 (dec: 1872115016), parent name: 'STREAM_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x7589C7E1 (dec: 1971963873), parent name: 'STREAM_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x1C8F07D8 (dec: 479135704), parent name: 'STREAM_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x87D59251 (dec: -2016046511), parent name: 'STREAM_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x454FC71A (dec: 1162856218), parent name: 'STREAM_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xCED3B292 (dec: -824986990), parent name: 'STREAM_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x2F4DA3DF (dec: 793617375), parent name: 'STREAM_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_111fake // hashcode: 0x4BE87AD4 (dec: 1273526996)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x86D13B46 (dec: -2033108154), parent name: 'STREAM_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xD63ED9FA (dec: -700524038), parent name: 'STREAM_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xC5A5FE59 (dec: -978977191), parent name: 'STREAM_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_112fake // hashcode: 0x5CAB7475 (dec: 1554740341)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x02DC3F92 (dec: 47988626), parent name: 'STREAM_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x93B6597D (dec: -1816766083), parent name: 'STREAM_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x9DC7F941 (dec: -1647838911), parent name: 'STREAM_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x11AE3D2B (dec: 296631595), parent name: 'STREAM_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x01508628 (dec: 22054440), parent name: 'STREAM_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_113fake // hashcode: 0x34D98A2A (dec: 886671914)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xCAC66682 (dec: -892967294), parent name: 'STREAM_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x98230298 (dec: -1742536040), parent name: 'STREAM_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x43A3399A (dec: 1134770586), parent name: 'STREAM_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xF22734DD (dec: -232311587), parent name: 'STREAM_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xD6473C68 (dec: -699974552), parent name: 'STREAM_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_114fake // hashcode: 0x16F90362 (dec: 385418082)
{
	struct STREAM_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x0F1EAEC4 (dec: 253669060), parent name: 'STREAM_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct STREAM_111fake Idle;		 // size=20, offset=28 //  hashcode: 0x46BC9DC1 (dec: 1186766273), parent name: 'STREAM_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct STREAM_112fake Behind;	// size=28, offset=48 //  hashcode: 0x2DCA7C51 (dec: 768244817), parent name: 'STREAM_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct STREAM_113fake Follow;	// size=20, offset=76 //  hashcode: 0x57293855 (dec: 1462319189), parent name: 'STREAM_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_182fake // hashcode: 0x31A0D0DD (dec: 832622813)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x74285065 (dec: 1948799077), parent name: 'STREAM_182fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0xB2A2CF92 (dec: -1297952878), parent name: 'STREAM_182fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_183fake // hashcode: 0x61941C65 (dec: 1637096549)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0xFDF14A8A (dec: -34518390), parent name: 'STREAM_183fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0xECB39840 (dec: -323774400), parent name: 'STREAM_183fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x995A1CB6 (dec: -1722147658), parent name: 'STREAM_183fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x668A2A2C (dec: 1720330796), parent name: 'STREAM_183fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x197C34A3 (dec: 427570339), parent name: 'STREAM_183fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0xA035DCE0 (dec: -1607082784), parent name: 'STREAM_183fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union STREAM_184fake // Hashcode: 0xD0227047 (dec: -803049401)
{
	struct STREAM_182fake flame; // size=8, offset=0
	struct STREAM_183fake phys;  // size=12, offset=0
};

struct evPositionData // hashcode: 0x853C21E0 (dec: -2059656736)
{
	short x;   // size=0, offset=0 //  hashcode: 0x7A03B3AF (dec: 2047062959), parent name: 'evPositionData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;   // size=0, offset=2 //  hashcode: 0xF1ADA5EB (dec: -240278037), parent name: 'evPositionData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;   // size=0, offset=4 //  hashcode: 0xC344F5B7 (dec: -1018890825), parent name: 'evPositionData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad; // size=0, offset=6 //  hashcode: 0x3C48AFD6 (dec: 1011396566), parent name: 'evPositionData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union STREAM_210fake // Hashcode: 0x3DCA0E3B (dec: 1036652091)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct STracker // hashcode: 0xAED5E069 (dec: -1361715095)
{
	struct _StreamUnit StreamList[16]; // size=1024, offset=0 //  hashcode: 0x6C7846B6 (dec: 1819821750), parent name: 'STracker', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FaceExtents // hashcode: 0x22E8BE79 (dec: 585678457)
{
	long smallx; // size=0, offset=0 //  hashcode: 0xD545E4F0 (dec: -716839696), parent name: 'FaceExtents', parent hashcode: 0xFFFFFFFF (dec: -1)
	long bigx;   // size=0, offset=4 //  hashcode: 0x005AEA79 (dec: 5958265), parent name: 'FaceExtents', parent hashcode: 0xFFFFFFFF (dec: -1)
	long smally; // size=0, offset=8 //  hashcode: 0xF17A5F9D (dec: -243638371), parent name: 'FaceExtents', parent hashcode: 0xFFFFFFFF (dec: -1)
	long bigy;   // size=0, offset=12 //  hashcode: 0x3FFD72CF (dec: 1073574607), parent name: 'FaceExtents', parent hashcode: 0xFFFFFFFF (dec: -1)
	long smallz; // size=0, offset=16 //  hashcode: 0xB63FACC8 (dec: -1237340984), parent name: 'FaceExtents', parent hashcode: 0xFFFFFFFF (dec: -1)
	long bigz;   // size=0, offset=20 //  hashcode: 0x59145268 (dec: 1494504040), parent name: 'FaceExtents', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WarpRoom // hashcode: 0x34E00E66 (dec: 887098982)
{
	char name[16];					// size=16, offset=0 //  hashcode: 0x76196044 (dec: 1981374532), parent name: 'WarpRoom', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _StreamUnit *streamUnit; // size=64, offset=16 //  hashcode: 0x4593671A (dec: 1167288090), parent name: 'WarpRoom', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PlanningNode // hashcode: 0xDB9F3065 (dec: -610324379)
{
	struct _Position pos;			// size=6, offset=0 //  hashcode: 0x3E6B2F48 (dec: 1047211848), parent name: 'PlanningNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short flags;			// size=0, offset=6 //  hashcode: 0xD3929A7C (dec: -745366916), parent name: 'PlanningNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long connectionStatus; // size=0, offset=8 //  hashcode: 0x76644118 (dec: 1986281752), parent name: 'PlanningNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long connections;		// size=0, offset=12 //  hashcode: 0x87CCC702 (dec: -2016622846), parent name: 'PlanningNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short cost;			// size=0, offset=16 //  hashcode: 0x381EF499 (dec: 941552793), parent name: 'PlanningNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short parent;			// size=0, offset=18 //  hashcode: 0xC8949B22 (dec: -929785054), parent name: 'PlanningNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short nodeType;		// size=0, offset=20 //  hashcode: 0x18529B78 (dec: 408066936), parent name: 'PlanningNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short id;				// size=0, offset=22 //  hashcode: 0xF24224D8 (dec: -230546216), parent name: 'PlanningNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamUnitID;				// size=0, offset=24 //  hashcode: 0xDCB4C975 (dec: -592131723), parent name: 'PlanningNode', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union STREAM_261fake // Hashcode: 0x825DBD24 (dec: -2107785948)
{
	struct Intro *intro;	   // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

union STREAM_263fake // Hashcode: 0x0DFDB5FB (dec: 234731003)
{
	struct _Instance *instance; // size=616, offset=0
	struct _SFXMkr *sfxMarker;  // size=36, offset=0
};

struct STREAM_264fake // hashcode: 0xB5E200C7 (dec: -1243479865)
{
	long instanceNumber; // size=0, offset=0 //  hashcode: 0x609578D8 (dec: 1620408536), parent name: 'STREAM_264fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;		 // size=0, offset=4 //  hashcode: 0x5EC6370B (dec: 1590048523), parent name: 'STREAM_264fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_265fake // hashcode: 0x7AF5D1F0 (dec: 2062930416)
{
	struct _SavedIntro *intro; // size=40, offset=0 //  hashcode: 0x65859012 (dec: 1703251986), parent name: 'STREAM_265fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;			   // size=0, offset=4 //  hashcode: 0xB4393435 (dec: -1271319499), parent name: 'STREAM_265fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_266fake // hashcode: 0xA0EB2092 (dec: -1595203438)
{
	long currentNumber; // size=0, offset=0 //  hashcode: 0xFA99387D (dec: -90621827), parent name: 'STREAM_266fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long error;			// size=0, offset=4 //  hashcode: 0x9941BA2D (dec: -1723745747), parent name: 'STREAM_266fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;		// size=0, offset=8 //  hashcode: 0x5F87F62F (dec: 1602745903), parent name: 'STREAM_266fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_267fake // hashcode: 0xD787F4D2 (dec: -678955822)
{
	short vx; // size=0, offset=0 //  hashcode: 0x54C32B6D (dec: 1422076781), parent name: 'STREAM_267fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vy; // size=0, offset=2 //  hashcode: 0x5D3DF1F7 (dec: 1564340727), parent name: 'STREAM_267fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_268fake // hashcode: 0x383EE328 (dec: 943645480)
{
	char *pointer; // size=0, offset=0 //  hashcode: 0xEDA080C3 (dec: -308248381), parent name: 'STREAM_268fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_269fake // hashcode: 0x104545E3 (dec: 272975331)
{
	short *pointer; // size=0, offset=0 //  hashcode: 0xE121F1C0 (dec: -517869120), parent name: 'STREAM_269fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_270fake // hashcode: 0x12ECC5B1 (dec: 317506993)
{
	long *pointer; // size=0, offset=0 //  hashcode: 0x60CC12A9 (dec: 1623986857), parent name: 'STREAM_270fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union STREAM_271fake // Hashcode: 0x67C9D9C4 (dec: 1741281732)
{
	struct STREAM_264fake Object;					  // size=8, offset=0
	struct STREAM_265fake SavedIntroObject;			  // size=8, offset=0
	struct InstanceSpline instanceSpline;			  // size=24, offset=0
	struct STREAM_266fake Number;					  // size=12, offset=0
	struct STREAM_267fake Vector2d;					  // size=4, offset=0
	struct STREAM_268fake CharPointer;				  // size=4, offset=0
	struct STREAM_269fake ShortPointer;				  // size=4, offset=0
	struct STREAM_270fake LongPointer;				  // size=4, offset=0
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

union STREAM_292fake // Hashcode: 0x8500823E (dec: -2063564226)
{
	struct _StreamUnit *streamUnit;		 // size=64, offset=0
	struct _ObjectTracker *streamObject; // size=36, offset=0
	struct _ButtonTexture *button;		 // size=16, offset=0
};

struct VramBuffer // hashcode: 0x13A80E34 (dec: 329780788)
{
	long flags;					// size=0, offset=0 //  hashcode: 0x31093EAD (dec: 822689453), parent name: 'VramBuffer', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x;					// size=0, offset=4 //  hashcode: 0x4A311568 (dec: 1244730728), parent name: 'VramBuffer', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;					// size=0, offset=6 //  hashcode: 0x0487647A (dec: 75981946), parent name: 'VramBuffer', parent hashcode: 0xFFFFFFFF (dec: -1)
	short w;					// size=0, offset=8 //  hashcode: 0x86FDF24D (dec: -2030177715), parent name: 'VramBuffer', parent hashcode: 0xFFFFFFFF (dec: -1)
	short h;					// size=0, offset=10 //  hashcode: 0x127245C6 (dec: 309478854), parent name: 'VramBuffer', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yOffset;				// size=0, offset=12 //  hashcode: 0x295553FD (dec: 693457917), parent name: 'VramBuffer', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lengthOfLeftOverData; // size=0, offset=14 //  hashcode: 0x52C5052A (dec: 1388643626), parent name: 'VramBuffer', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *lineOverFlow;		// size=0, offset=16 //  hashcode: 0xE16BEE5D (dec: -513020323), parent name: 'VramBuffer', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STREAM_294fake // hashcode: 0x4C00FE3C (dec: 1275133500)
{
	int warpgate_in_use;				// size=0, offset=0 //  hashcode: 0xFAE8227D (dec: -85450115), parent name: 'STREAM_294fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char loading;						// size=0, offset=4 //  hashcode: 0x73EBDF8E (dec: 1944838030), parent name: 'STREAM_294fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char blocked;						// size=0, offset=5 //  hashcode: 0x5901DCCC (dec: 1493294284), parent name: 'STREAM_294fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadeValue;					// size=0, offset=6 //  hashcode: 0x18F2B286 (dec: 418558598), parent name: 'STREAM_294fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long curTime;						// size=0, offset=8 //  hashcode: 0x87EDBF93 (dec: -2014462061), parent name: 'STREAM_294fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxTime;						// size=0, offset=12 //  hashcode: 0xD1B0F9F6 (dec: -776930826), parent name: 'STREAM_294fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *warpFaceInstance; // size=616, offset=16 //  hashcode: 0xF91724EB (dec: -115923733), parent name: 'STREAM_294fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct POLY_G4 POLY_G4;

typedef struct DR_AREA DR_AREA;

typedef struct evPositionData evPositionData;

typedef struct STracker STracker;

typedef struct FaceExtents FaceExtents;

typedef struct WarpRoom WarpRoom;

typedef struct PlanningNode PlanningNode;

typedef struct VramBuffer VramBuffer;

extern void STREAM_FillOutFileNames(char *baseAreaName, char *dramName, char *vramName, char *sfxName); // 0x800584E4

extern void STREAM_AbortAreaLoad(char *baseAreaName); // 0x800585A4

extern void STREAM_Init(); // 0x800585EC

extern int FindObjectName(char *name); // 0x80058618

extern struct _ObjectTracker *FindObjectInTracker(struct Object *object); // 0x80058684

extern struct _StreamUnit *FindStreamUnitFromLevel(struct Level *level); // 0x800586D4

extern void STREAM_LoadObjectReturn(void *loadData, void *data, void *data2); // 0x80058724

extern void STREAM_DumpMonster(struct _ObjectTracker *dumpee); // 0x8005882C

extern int STREAM_InList(char *name, char **nameList); // 0x800588A0

extern int STREAM_IsSpecialMonster(char *name); // 0x80058908

extern void STREAM_DumpSomeMonsters(); // 0x8005892C

extern void STREAM_NoMonsters(); // 0x800589BC

extern void STREAM_YesMonsters(); // 0x800589EC

extern int STREAM_IsMonster(char *name); // 0x80058A08

extern int STREAM_TryAndDumpANonResidentObject(); // 0x80058A2C

extern int InsertGlobalObject(char *name, struct GameTracker *gameTracker); // 0x80058A7C

extern struct _ObjectTracker *STREAM_GetObjectTracker(char *name); // 0x80058C18

extern void LoadLevelObjects(struct _StreamUnit *stream); // 0x80058C64

extern long STREAM_IsAnInstanceUsingObject(struct Object *object); // 0x80058D88

extern void STREAM_StreamLoadObjectAbort(void *loadData, void *data, void *data2); // 0x80058DC8

extern void STREAM_DumpLoadingObjects(); // 0x80058DF8

extern void STREAM_DumpObject(struct _ObjectTracker *objectTracker); // 0x80058E58

extern int STREAM_IsObjectInAnyUnit(struct _ObjectTracker *tracker); // 0x80058F40

extern void STREAM_RemoveAllObjectsNotInUse(); // 0x80059000

extern void RemoveAllObjects(struct GameTracker *gameTracker); // 0x800592C0

extern struct Level *STREAM_GetLevelWithID(long id); // 0x80059318

extern struct _StreamUnit *STREAM_GetStreamUnitWithID(long id); // 0x80059370

extern struct _StreamUnit *STREAM_GetStreamUnitWithName(char *name); // 0x800593C0

extern void STREAM_CalculateWaterLevel(struct Level *level); // 0x80059450

extern int STREAM_IsMorphInProgress(); // 0x80059580

extern long STREAM_GetWaterZLevel(struct Level *level, struct _Instance *instance); // 0x80059594

extern void STREAM_SetMainFog(struct _StreamUnit *streamUnit); // 0x80059614

extern void STREAM_SetStreamFog(struct _StreamUnit *streamUnit, short fogNear, short fogFar); // 0x80059668

extern void STREAM_ConnectStream(struct _StreamUnit *streamUnit); // 0x800596F8

extern void STREAM_StreamLoadLevelAbort(void *loadData, void *data, void *data2); // 0x80059B04

extern void STREAM_DoObjectLoadAndDump(struct _StreamUnit *streamUnit); // 0x80059B3C

extern void STREAM_FinishLoad(struct _StreamUnit *streamUnit); // 0x80059B84

extern void STREAM_LoadLevelReturn(void *loadData, void *data, void *data2); // 0x80059CD0

extern void STREAM_StreamLoadLevelReturn(void *loadData, void *data, void *data2); // 0x80059D30

extern void STREAM_UpdateLevelPointer(struct Level *oldLevel, struct Level *newLevel, long sizeOfLevel); // 0x80059E18

extern struct _StreamUnit *STREAM_WhichUnitPointerIsIn(void *pointer); // 0x8005A108

extern void STREAM_UpdateObjectPointer(struct Object *oldObject, struct Object *newObject, long sizeOfObject); // 0x8005A1B4

extern void STREAM_UpdateInstanceCollisionInfo(struct _HModel *oldHModel, struct _HModel *newHModel); // 0x8005A454

extern void STREAM_LoadMainVram(struct GameTracker *gameTracker, char *baseAreaName, struct _StreamUnit *streamUnit); // 0x8005A498

extern void STREAM_MoveIntoNewStreamUnit(); // 0x8005A540

extern struct _StreamUnit *STREAM_LoadLevel(char *baseAreaName, struct StreamUnitPortal *streamPortal, int loadnext); // 0x8005A5D4

extern void RemoveIntroducedLights(struct Level *level); // 0x8005A7F8

extern void STREAM_RemoveInstancesWithIDInInstanceList(struct _InstanceList *list, long id, struct Level *level); // 0x8005A8DC

extern void STREAM_MarkUnitNeeded(long streamID); // 0x8005A988

extern void STREAM_DumpUnit(struct _StreamUnit *streamUnit, long doSave); // 0x8005A9D4

extern void STREAM_DumpAllUnitsNotNeeded(); // 0x8005ABB8

extern void STREAM_DumpAllLevels(long IDNoRemove, int DoSave); // 0x8005AC20

extern void STREAM_LoadCurrentWarpRoom(struct StreamUnitPortal *streamPortal, struct _StreamUnit *mainStreamUnit); // 0x8005AC9C

extern void WARPGATE_RelocateLoadedWarpRooms(struct _StreamUnit *mainUnit, struct StreamUnitPortal *streamPortal); // 0x8005AD58

extern long WARPGATE_GetWarpRoomIndex(char *name); // 0x8005AE00

extern void WARPGATE_UpdateAddToArray(struct _StreamUnit *streamUnit); // 0x8005AE60

extern void WARPGATE_RemoveFromArray(struct _StreamUnit *streamUnit); // 0x8005AEAC

extern void WARPGATE_Init(); // 0x8005AEDC

extern void WARPGATE_StartUsingWarpgate(); // 0x8005AF24

extern void WARPGATE_EndUsingWarpgate(); // 0x8005AF5C

extern int WARPGATE_IsWarpgateInUse(); // 0x8005AF94

extern int WARPGATE_IsWarpgateActive(); // 0x8005AFA0

extern int WARPGATE_IsWarpgateUsable(); // 0x8005AFAC

extern int WARPGATE_IsWarpgateReady(); // 0x8005AFC0

extern int WARPGATE_IsWarpgateSpectral(); // 0x8005AFD4

extern int WARPGATE_IsObjectOnWarpSide(struct _Instance *instance); // 0x8005B010

extern void WARPGATE_IsItActive(struct _StreamUnit *streamUnit); // 0x8005B074

extern long WARPGATE_IsUnitWarpRoom(struct _StreamUnit *streamUnit); // 0x8005B13C

extern void WARPGATE_FixUnit(struct _StreamUnit *streamUnit); // 0x8005B194

extern void STREAM_MarkWarpUnitsNeeded(); // 0x8005B1C8

extern long WARPGATE_IncrementIndex(); // 0x8005B208

extern void WARPGATE_CalcWarpFade(int timeInc); // 0x8005B320

extern long WARPGATE_DecrementIndex(); // 0x8005B390

extern void PreloadAllConnectedUnits(struct _StreamUnit *streamUnit, struct _SVector *offset); // 0x8005B468

extern void RelocateLevel(struct Level *level, struct _SVector *offset); // 0x8005B62C

extern void RelocateCameras(struct _CameraKey *cameraList, long numCameras, struct _SVector *offset); // 0x8005B76C

extern void RelocateSavedCameras(struct Camera *camera, struct Level *level, struct _SVector *offset); // 0x8005B800

extern void RelocateLevelWithInstances(struct Level *level, struct _SVector *offset); // 0x8005B938

extern void RelocateTerrain(struct _Terrain *terrain, struct _SVector *offset); // 0x8005B970

extern void RelocateVMObjects(struct _VMObject *vobjectlist, long numvmobjs, struct _SVector *offset); // 0x8005BA60

extern void RelocateBGObjects(struct _BGObject *BGObjList, long numBGObjs, struct _SVector *offset); // 0x8005BAB8

extern void RelocatePlanPool(struct PlanningNode *planPool, struct _SVector *offset); // 0x8005BB5C

extern void RelocatePlanMarkers(struct _PlanMkr *planMkrList, int numPlanMkrs, struct _SVector *offset); // 0x8005BC10

extern void RelocateSFXMarkers(struct _SFXMkr *sfxMkrList, int numSFXMkrs, struct _SVector *offset); // 0x8005BC64

extern void STREAM_AdjustMultiSpline(struct MultiSpline *multi, struct _SVector *offset); // 0x8005BCB0

extern void STREAM_RelocateInstance(struct _Instance *instance, struct _SVector *offset); // 0x8005BD60

extern void STREAM_OffsetInstancePosition(struct _Instance *instance, struct _SVector *offset, int streamSignalFlag); // 0x8005BDA8

extern void STREAM_SetInstancePosition(struct _Instance *instance, struct evPositionData *data); // 0x8005BEC0

extern void RelocateInstances(struct _SVector *offset); // 0x8005BF18

extern void RelocateStreamPortals(struct StreamUnitPortal *StreamUnitList, int NumStreamUnits, struct _SVector *offset); // 0x8005BF74

extern void STREAM_PackVRAMObject(struct _ObjectTracker *objectTracker); // 0x8005C0A4

extern void MORPH_SetupInstanceFlags(struct _Instance *instance); // 0x8005C1A4

extern void MORPH_SetupInstanceListFlags(); // 0x8005C2D8

extern void MORPH_InMorphInstanceListFlags(); // 0x8005C320

extern void MORPH_InMorphDoFadeValues(); // 0x8005C388

extern void MORPH_UpdateTimeMult(); // 0x8005C3E0

extern void MORPH_UpdateNormals(struct Level *BaseLevel); // 0x8005C554

extern void MORPH_BringBackNormals(struct Level *BaseLevel); // 0x8005CA08

extern void MORPH_AddOffsets(struct Level *BaseLevel, int time); // 0x8005CE78

extern void MORPH_SubtractOffsets(struct Level *BaseLevel, int time); // 0x8005D244

extern void MORPH_GetComponentsForTrackingPoint(struct _TFace *face, struct Level *level); // 0x8005D618

extern void MORPH_AveragePoint(struct _SVector *start, struct _SVector *end, int interp, struct _SVector *out); // 0x8005D8F8

extern void MORPH_UpdateTrackingPoint(struct _TFace *face, struct Level *level); // 0x8005D970

extern void MORPH_ToggleMorph(); // 0x8005DB14

extern void MORPH_DoStep(struct _StreamUnit *streamUnit, char *baseAreaName); // 0x8005DC60

extern void MORPH_SetFog(struct _StreamUnit *streamUnit, int mainUnitFlag); // 0x8005DD3C

extern void MORPH_UpdateTextures(); // 0x8005DE10

extern void MORPH_Continue(); // 0x8005DE68

extern void STREAM_MORPH_Relocate(); // 0x8005DFDC

extern int AddVertex(struct VECTOR *v0, struct RECT *rect); // 0x8005DFEC

extern int GetPlaneDist(int k, int j, int i, struct VECTOR *v); // 0x8005E178

extern void CalcVert(struct VECTOR *v, struct VECTOR *v1, struct VECTOR *v2, int dist1, int dist2, int k, int j); // 0x8005E204

extern int AddClippedTri(struct SVECTOR *iv, struct RECT *cliprect, int *minz); // 0x8005E28C

extern int STREAM_GetClipRect(struct StreamUnitPortal *portal, struct RECT *rect); // 0x8005E534

extern long GetFogColor(struct StreamUnitPortal *portal, struct _StreamUnit *mainStreamUnit, struct Level *mainLevel); // 0x8005EAFC

extern void DrawFogRectangle(struct RECT *cliprect, struct _PrimPool *primPool, int otzpos, unsigned long **drawot, long color); // 0x8005EE20

extern void STREAM_RenderAdjacantUnit(unsigned long **curOT, struct StreamUnitPortal *curStreamPortal, struct _StreamUnit *toStreamUnit, struct _StreamUnit *mainStreamUnit, struct RECT *cliprect); // 0x8005EF0C

extern struct BSPTree *STREAM_GetBspTree(struct _StreamUnit *streamUnit, long bspNumber); // 0x8005EFB8

extern void WARPGATE_BlockWarpGateEntrance(struct _StreamUnit *streamUnit, long collideOn); // 0x8005F018

extern void WARPGATE_DrawWarpGateRim(struct _StreamUnit *streamUnit, long drawOn); // 0x8005F088

extern void WARPGATE_HideAllCloudCovers(); // 0x8005F0E0

extern struct _Instance *WARPGATE_UnHideCloudCoverInUnit(long streamUnitID); // 0x8005F140

extern void STREAM_RenderWarpGate(unsigned long **mainOT, struct StreamUnitPortal *curStreamPortal, struct _StreamUnit *mainStreamUnit, struct RECT *cliprect); // 0x8005F1B8

extern void WARPGATE_RenderWarpUnit(unsigned long **mainOT, struct StreamUnitPortal *curStreamPortal, struct _StreamUnit *mainStreamUnit, struct RECT *cliprect); // 0x8005F4F0

extern void STREAM_DumpNonResidentObjects(); // 0x8005F8C8

extern int STREAM_TryAndDumpNonResident(struct _ObjectTracker *otr); // 0x8005F978

#endif
