#ifndef PLAYER_H
#define PLAYER_H

struct TCB // hashcode: 0x6A70BBF4 (dec: 1785773044)
{
	long status;		   // size=0, offset=0 //  hashcode: 0x086B0C51 (dec: 141233233), parent name: 'TCB', parent hashcode: 0xFFFFFFFF (dec: -1)
	long mode;			   // size=0, offset=4 //  hashcode: 0xDA5CDBD9 (dec: -631448615), parent name: 'TCB', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long reg[40]; // size=160, offset=8 //  hashcode: 0x3A73ABEE (dec: 980659182), parent name: 'TCB', parent hashcode: 0xFFFFFFFF (dec: -1)
	long system[6];		   // size=24, offset=168 //  hashcode: 0x677F28CC (dec: 1736386764), parent name: 'TCB', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EXEC // hashcode: 0x4291A2AD (dec: 1116840621)
{
	unsigned long pc0;	// size=0, offset=0 //  hashcode: 0xE5B8530C (dec: -440904948), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long gp0;	// size=0, offset=4 //  hashcode: 0xDAFC2018 (dec: -621010920), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long t_addr; // size=0, offset=8 //  hashcode: 0x0D6CBDF7 (dec: 225230327), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long t_size; // size=0, offset=12 //  hashcode: 0x5F6A2CAA (dec: 1600793770), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long d_addr; // size=0, offset=16 //  hashcode: 0x0115E2A4 (dec: 18211492), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long d_size; // size=0, offset=20 //  hashcode: 0x3E22DED3 (dec: 1042472659), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long b_addr; // size=0, offset=24 //  hashcode: 0xEBA37B64 (dec: -341607580), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long b_size; // size=0, offset=28 //  hashcode: 0x152B199A (dec: 355146138), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long s_addr; // size=0, offset=32 //  hashcode: 0x25334277 (dec: 624116343), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long s_size; // size=0, offset=36 //  hashcode: 0x8B038609 (dec: -1962703351), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long sp;	 // size=0, offset=40 //  hashcode: 0xAADDBAD6 (dec: -1428309290), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long fp;	 // size=0, offset=44 //  hashcode: 0xF2E0481A (dec: -220182502), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long gp;	 // size=0, offset=48 //  hashcode: 0x196AF344 (dec: 426439492), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long ret;	// size=0, offset=52 //  hashcode: 0xBB7C0EB0 (dec: -1149497680), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long base;   // size=0, offset=56 //  hashcode: 0xD37F8BB6 (dec: -746615882), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DIRENTRY // hashcode: 0xD989A944 (dec: -645289660)
{
	char name[20];		   // size=20, offset=0 //  hashcode: 0xA2DA0F6A (dec: -1562767510), parent name: 'DIRENTRY', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attr;			   // size=0, offset=20 //  hashcode: 0x5A6CBB0B (dec: 1517075211), parent name: 'DIRENTRY', parent hashcode: 0xFFFFFFFF (dec: -1)
	long size;			   // size=0, offset=24 //  hashcode: 0x6EA817AC (dec: 1856509868), parent name: 'DIRENTRY', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DIRENTRY *next; // size=40, offset=28 //  hashcode: 0xFB2C47E3 (dec: -80984093), parent name: 'DIRENTRY', parent hashcode: 0xFFFFFFFF (dec: -1)
	long head;			   // size=0, offset=32 //  hashcode: 0x902962D3 (dec: -1876335917), parent name: 'DIRENTRY', parent hashcode: 0xFFFFFFFF (dec: -1)
	char system[4];		   // size=4, offset=36 //  hashcode: 0x6DC6A881 (dec: 1841735809), parent name: 'DIRENTRY', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATRIX // hashcode: 0x610186A2 (dec: 1627489954)
{
	short m[3][3]; // size=18, offset=0 //  hashcode: 0x6AA97C11 (dec: 1789492241), parent name: 'MATRIX', parent hashcode: 0xFFFFFFFF (dec: -1)
	long t[3];	 // size=12, offset=20 //  hashcode: 0xF6C8EB24 (dec: -154604764), parent name: 'MATRIX', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VECTOR // hashcode: 0xE0DB0D68 (dec: -522515096)
{
	long vx;  // size=0, offset=0 //  hashcode: 0x996D64A0 (dec: -1720884064), parent name: 'VECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	long vy;  // size=0, offset=4 //  hashcode: 0xB7193B4C (dec: -1223083188), parent name: 'VECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	long vz;  // size=0, offset=8 //  hashcode: 0x5E86BD61 (dec: 1585888609), parent name: 'VECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	long pad; // size=0, offset=12 //  hashcode: 0x0E0ECF3A (dec: 235851578), parent name: 'VECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SVECTOR // hashcode: 0x55473CEB (dec: 1430732011)
{
	short vx;  // size=0, offset=0 //  hashcode: 0x0FEA65B5 (dec: 267019701), parent name: 'SVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vy;  // size=0, offset=2 //  hashcode: 0xA5CFF704 (dec: -1513097468), parent name: 'SVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vz;  // size=0, offset=4 //  hashcode: 0xB161FAFA (dec: -1318978822), parent name: 'SVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad; // size=0, offset=6 //  hashcode: 0x343FD367 (dec: 876598119), parent name: 'SVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CVECTOR // hashcode: 0xDE4B0C81 (dec: -565506943)
{
	unsigned char r;  // size=0, offset=0 //  hashcode: 0xA80BB350 (dec: -1475628208), parent name: 'CVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;  // size=0, offset=1 //  hashcode: 0x974498FB (dec: -1757112069), parent name: 'CVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;  // size=0, offset=2 //  hashcode: 0xE728DF60 (dec: -416751776), parent name: 'CVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char cd; // size=0, offset=3 //  hashcode: 0xB1430357 (dec: -1321008297), parent name: 'CVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DVECTOR // hashcode: 0x5BF12E56 (dec: 1542532694)
{
	short vx; // size=0, offset=0 //  hashcode: 0xF310A60F (dec: -217012721), parent name: 'DVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vy; // size=0, offset=2 //  hashcode: 0x6BBA1CDB (dec: 1807359195), parent name: 'DVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RVECTOR // hashcode: 0xEC34D5C3 (dec: -332081725)
{
	struct SVECTOR v;	// size=8, offset=0 //  hashcode: 0xB7041025 (dec: -1224470491), parent name: 'RVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char uv[2]; // size=2, offset=8 //  hashcode: 0x808A12B3 (dec: -2138434893), parent name: 'RVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad;  // size=0, offset=10 //  hashcode: 0x8B27972D (dec: -1960339667), parent name: 'RVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CVECTOR c;	// size=4, offset=12 //  hashcode: 0xDC1A314B (dec: -602263221), parent name: 'RVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DVECTOR sxy;  // size=4, offset=16 //  hashcode: 0x2BC5F879 (dec: 734394489), parent name: 'RVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long sz;	// size=0, offset=20 //  hashcode: 0x27E2CB2A (dec: 669174570), parent name: 'RVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CRVECTOR3 // hashcode: 0x9A564233 (dec: -1705622989)
{
	struct RVECTOR r01; // size=24, offset=0 //  hashcode: 0x000D78BD (dec: 882877), parent name: 'CRVECTOR3', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR r12; // size=24, offset=24 //  hashcode: 0x826D2953 (dec: -2106775213), parent name: 'CRVECTOR3', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR r20; // size=24, offset=48 //  hashcode: 0x1F7A8086 (dec: 528121990), parent name: 'CRVECTOR3', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR *r0; // size=24, offset=72 //  hashcode: 0xF81284E1 (dec: -133004063), parent name: 'CRVECTOR3', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR *r1; // size=24, offset=76 //  hashcode: 0x51F9CE08 (dec: 1375325704), parent name: 'CRVECTOR3', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR *r2; // size=24, offset=80 //  hashcode: 0xDA788D60 (dec: -629633696), parent name: 'CRVECTOR3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long *rtn; // size=0, offset=84 //  hashcode: 0x74F8EE65 (dec: 1962471013), parent name: 'CRVECTOR3', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CRVECTOR4 // hashcode: 0x56AED614 (dec: 1454298644)
{
	struct RVECTOR r01; // size=24, offset=0 //  hashcode: 0xD4F361EF (dec: -722247185), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR r02; // size=24, offset=24 //  hashcode: 0x6D1A3CC4 (dec: 1830436036), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR r31; // size=24, offset=48 //  hashcode: 0x66AC02A0 (dec: 1722548896), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR r32; // size=24, offset=72 //  hashcode: 0xA93A6458 (dec: -1455791016), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR rc;  // size=24, offset=96 //  hashcode: 0x62654CFA (dec: 1650806010), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR *r0; // size=24, offset=120 //  hashcode: 0x7AAF6598 (dec: 2058315160), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR *r1; // size=24, offset=124 //  hashcode: 0xF9DC21B4 (dec: -103013964), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR *r2; // size=24, offset=128 //  hashcode: 0xDBFA7F03 (dec: -604340477), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR *r3; // size=24, offset=132 //  hashcode: 0xA6596016 (dec: -1504092138), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long *rtn; // size=0, offset=136 //  hashcode: 0x03A50899 (dec: 61147289), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RECT // hashcode: 0xDFC821CB (dec: -540532277)
{
	short x; // size=0, offset=0 //  hashcode: 0x186E0F52 (dec: 409866066), parent name: 'RECT', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0x283654C7 (dec: 674649287), parent name: 'RECT', parent hashcode: 0xFFFFFFFF (dec: -1)
	short w; // size=0, offset=4 //  hashcode: 0x621DCD6A (dec: 1646120298), parent name: 'RECT', parent hashcode: 0xFFFFFFFF (dec: -1)
	short h; // size=0, offset=6 //  hashcode: 0x435C8B63 (dec: 1130138467), parent name: 'RECT', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DR_ENV // hashcode: 0xD77E7FD5 (dec: -679575595)
{
	unsigned long tag;		// size=0, offset=0 //  hashcode: 0x7FDBA6FD (dec: 2145101565), parent name: 'DR_ENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long code[15]; // size=60, offset=4 //  hashcode: 0x2B044D34 (dec: 721702196), parent name: 'DR_ENV', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct P_TAG // hashcode: 0x962C4103 (dec: -1775484669)
{
	unsigned int addr : 24; // offset=0.0 //  hashcode: 0x23A9DDAE (dec: 598334894), parent name: 'P_TAG', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned int len : 8;   // offset=3.0 //  hashcode: 0x71A373C6 (dec: 1906537414), parent name: 'P_TAG', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;		// size=0, offset=4 //  hashcode: 0xB1E724A6 (dec: -1310251866), parent name: 'P_TAG', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;		// size=0, offset=5 //  hashcode: 0xBE8E9D4B (dec: -1097949877), parent name: 'P_TAG', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;		// size=0, offset=6 //  hashcode: 0x82E3551E (dec: -2099030754), parent name: 'P_TAG', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code;		// size=0, offset=7 //  hashcode: 0x4F836FCC (dec: 1334013900), parent name: 'P_TAG', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CdlLOC // hashcode: 0x449289F8 (dec: 1150454264)
{
	unsigned char minute; // size=0, offset=0 //  hashcode: 0x78480741 (dec: 2017986369), parent name: 'CdlLOC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char second; // size=0, offset=1 //  hashcode: 0xF17180C7 (dec: -244219705), parent name: 'CdlLOC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sector; // size=0, offset=2 //  hashcode: 0x8F8413F3 (dec: -1887169549), parent name: 'CdlLOC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char track;  // size=0, offset=3 //  hashcode: 0x802BF1C8 (dec: -2144603704), parent name: 'CdlLOC', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LightInstance // hashcode: 0xB8D5E61F (dec: -1193941473)
{
	struct _Instance *lightInstance; // size=0, offset=0 //  hashcode: 0x4943BD3B (dec: 1229176123), parent name: 'LightInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long r;							 // size=0, offset=4 //  hashcode: 0xEF59AD24 (dec: -279335644), parent name: 'LightInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long g;							 // size=0, offset=8 //  hashcode: 0x25B68F2C (dec: 632721196), parent name: 'LightInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long b;							 // size=0, offset=12 //  hashcode: 0x0B22743C (dec: 186807356), parent name: 'LightInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short radius;					 // size=0, offset=16 //  hashcode: 0xFF2623BD (dec: -14277699), parent name: 'LightInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segment;			 // size=0, offset=18 //  hashcode: 0xF05D456B (dec: -262322837), parent name: 'LightInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;			 // size=0, offset=19 //  hashcode: 0xA2BEECD4 (dec: -1564545836), parent name: 'LightInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Instance // hashcode: 0x699A5B3D (dec: 1771723581)
{
	struct NodeType node;						 // size=8, offset=0 //  hashcode: 0x99208B91 (dec: -1725920367), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *next;						 // size=616, offset=8 //  hashcode: 0xB3A164B8 (dec: -1281268552), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *prev;						 // size=616, offset=12 //  hashcode: 0x42C61B4A (dec: 1120279370), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long instanceID;							 // size=0, offset=16 //  hashcode: 0xA6884804 (dec: -1501018108), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;									 // size=0, offset=20 //  hashcode: 0xD1775B28 (dec: -780707032), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags2;								 // size=0, offset=24 //  hashcode: 0x21861BFC (dec: 562437116), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object;						 // size=76, offset=28 //  hashcode: 0x1F65FB30 (dec: 526777136), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Intro *intro;						 // size=0, offset=32 //  hashcode: 0x0F03F6CB (dec: 251918027), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;									 // size=0, offset=36 //  hashcode: 0x19CC04EB (dec: 432801003), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *introData;							 // size=0, offset=40 //  hashcode: 0xA50D07DB (dec: -1525872677), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *parent;					 // size=616, offset=44 //  hashcode: 0x1BBBD8B7 (dec: 465295543), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long introNum;								 // size=0, offset=48 //  hashcode: 0x8279A896 (dec: -2105956202), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long birthStreamUnitID;						 // size=0, offset=52 //  hashcode: 0xED885CFD (dec: -309830403), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long currentStreamUnitID;					 // size=0, offset=56 //  hashcode: 0x72D30C56 (dec: 1926433878), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long introUniqueID;							 // size=0, offset=60 //  hashcode: 0x2BFA69A1 (dec: 737831329), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX *matrix;						 // size=32, offset=64 //  hashcode: 0xE317A8AB (dec: -484988757), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX *oldMatrix;					 // size=32, offset=68 //  hashcode: 0x32B1418F (dec: 850477455), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SoundInstance soundInstanceTbl[4];	// size=12, offset=72 //  hashcode: 0x6758AC4D (dec: 1733864525), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long maxCheckDistance;				 // size=0, offset=84 //  hashcode: 0x0E842D43 (dec: 243543363), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long checkMask;					 // size=0, offset=88 //  hashcode: 0xEC138633 (dec: -334264781), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position;					 // size=6, offset=92 //  hashcode: 0xD4957DF0 (dec: -728400400), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char lightGroup;					 // size=0, offset=98 //  hashcode: 0x8CAE4B99 (dec: -1934734439), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position oldPos;					 // size=6, offset=100 //  hashcode: 0x1063D144 (dec: 274977092), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char spectralLightGroup;			 // size=0, offset=106 //  hashcode: 0x8584656E (dec: -2054920850), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short currentTextureAnimFrame;				 // size=0, offset=108 //  hashcode: 0x960093A5 (dec: -1778347099), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position initialPos;				 // size=6, offset=110 //  hashcode: 0x386B385F (dec: 946550879), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation;					 // size=8, offset=116 //  hashcode: 0x74BE2D34 (dec: 1958620468), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation oldRotation;				 // size=8, offset=124 //  hashcode: 0xA1D5C67F (dec: -1579825537), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector scale;						 // size=8, offset=132 //  hashcode: 0xDA9E0E9F (dec: -627175777), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attachedID;							 // size=0, offset=140 //  hashcode: 0x9BCBC65C (dec: -1681144228), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attachedSegment;						 // size=0, offset=144 //  hashcode: 0xC10D1191 (dec: -1056108143), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX relativeMatrix;				 // size=32, offset=148 //  hashcode: 0xE3835060 (dec: -477933472), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;						 // size=12, offset=180 //  hashcode: 0x88C4C8FF (dec: -2000369409), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;					 // size=12, offset=184 //  hashcode: 0xF2256D72 (dec: -232428174), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *tfaceLevel;							 // size=0, offset=188 //  hashcode: 0x11BB7061 (dec: 297496673), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *collideInfo;							 // size=0, offset=192 //  hashcode: 0x66F9A20E (dec: 1727635982), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long bspTree;								 // size=0, offset=196 //  hashcode: 0x9EF645B5 (dec: -1628027467), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cachedTFace;							 // size=0, offset=200 //  hashcode: 0xFAF15585 (dec: -84847227), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cachedBSPTree;						 // size=0, offset=202 //  hashcode: 0xF04425B4 (dec: -263969356), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *cachedTFaceLevel;						 // size=0, offset=204 //  hashcode: 0xF192C521 (dec: -242039519), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Normal oldWNormal;					 // size=8, offset=208 //  hashcode: 0x5B7F4794 (dec: 1535068052), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Normal wNormal;						 // size=8, offset=216 //  hashcode: 0xB9F91D63 (dec: -1174856349), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset;						 // size=8, offset=224 //  hashcode: 0xE2B8BD56 (dec: -491209386), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HModel *hModelList;					 // size=8, offset=232 //  hashcode: 0xC12D7847 (dec: -1053984697), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadeValue;							 // size=0, offset=236 //  hashcode: 0x564EF969 (dec: 1448016233), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lightMatrix;							 // size=0, offset=238 //  hashcode: 0x3BCAE250 (dec: 1003151952), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*processFunc)();						 // size=0, offset=240 //  hashcode: 0x509F6C31 (dec: 1352625201), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*collideFunc)();						 // size=0, offset=244 //  hashcode: 0x590F8C01 (dec: 1494191105), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*additionalCollideFunc)();			 // size=0, offset=248 //  hashcode: 0xBD63CD14 (dec: -1117532908), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long (*queryFunc)();				 // size=0, offset=252 //  hashcode: 0x7F7E6E8A (dec: 2138992266), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*messageFunc)();						 // size=0, offset=256 //  hashcode: 0xFCD61AC7 (dec: -53077305), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position shadowPosition;			 // size=6, offset=260 //  hashcode: 0xD0781A43 (dec: -797435325), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short currentModel;							 // size=0, offset=266 //  hashcode: 0x57010A87 (dec: 1459686023), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *waterFace;					 // size=12, offset=268 //  hashcode: 0x0AC072B0 (dec: 180384432), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldWaterFace;				 // size=12, offset=272 //  hashcode: 0x2FE681B5 (dec: 803635637), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Terrain *waterFaceTerrain;			 // size=0, offset=276 //  hashcode: 0xF61F0A62 (dec: -165737886), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _PlaneConstants halvePlane;			 // size=12, offset=280 //  hashcode: 0x3436D438 (dec: 876008504), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector splitPoint;					 // size=8, offset=292 //  hashcode: 0xEAB4289D (dec: -357291875), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *LinkParent;				 // size=616, offset=300 //  hashcode: 0xA2F719D6 (dec: -1560864298), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *LinkChild;				 // size=616, offset=304 //  hashcode: 0x5DB1CE79 (dec: 1571933817), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *LinkSibling;				 // size=616, offset=308 //  hashcode: 0x92292860 (dec: -1842796448), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long ParentLinkNode;						 // size=0, offset=312 //  hashcode: 0xA312388F (dec: -1559086961), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *InstanceState;						 // size=0, offset=316 //  hashcode: 0x79B2FE86 (dec: 2041773702), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	char introName[12];							 // size=12, offset=320 //  hashcode: 0xBDFED102 (dec: -1107373822), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *extraData;							 // size=0, offset=332 //  hashcode: 0x694711D8 (dec: 1766265304), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short constrictAngle;						 // size=0, offset=336 //  hashcode: 0xB6F7367A (dec: -1225312646), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short petrifyValue;							 // size=0, offset=338 //  hashcode: 0x9B0240A1 (dec: -1694351199), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long xVel;									 // size=0, offset=340 //  hashcode: 0x42ACBBB9 (dec: 1118616505), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long yVel;									 // size=0, offset=344 //  hashcode: 0xD6EEAB82 (dec: -689001598), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long zVel;									 // size=0, offset=348 //  hashcode: 0xA21ED791 (dec: -1575037039), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long xAccl;									 // size=0, offset=352 //  hashcode: 0xF0501CF6 (dec: -263185162), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long yAccl;									 // size=0, offset=356 //  hashcode: 0xC49C9B60 (dec: -996369568), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long zAccl;									 // size=0, offset=360 //  hashcode: 0x588735F2 (dec: 1485256178), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxXVel;								 // size=0, offset=364 //  hashcode: 0x699F6B15 (dec: 1772055317), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxYVel;								 // size=0, offset=368 //  hashcode: 0xB840A661 (dec: -1203722655), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxZVel;								 // size=0, offset=372 //  hashcode: 0x237D351E (dec: 595408158), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long currentMainState;						 // size=0, offset=376 //  hashcode: 0x67C6BFB0 (dec: 1741078448), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long work0;									 // size=0, offset=380 //  hashcode: 0xDE8C79D1 (dec: -561219119), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long work1;									 // size=0, offset=384 //  hashcode: 0x1281F305 (dec: 310506245), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long work2;									 // size=0, offset=388 //  hashcode: 0xD1CF0CA9 (dec: -774959959), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long work3;									 // size=0, offset=392 //  hashcode: 0x27BB560D (dec: 666588685), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long work4;									 // size=0, offset=396 //  hashcode: 0xDFE8F832 (dec: -538380238), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long work5;									 // size=0, offset=400 //  hashcode: 0x8C138638 (dec: -1944877512), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Anim_Type anim;					 // size=180, offset=404 //  hashcode: 0xC5CB720A (dec: -976522742), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	enum _G2Bool_Enum (*rebuildCallback)();		 // size=4, offset=584 //  hashcode: 0xFE6A12C9 (dec: -26602807), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splineFlags;							 // size=0, offset=588 //  hashcode: 0x38C7970D (dec: 952604429), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short targetFrame;							 // size=0, offset=590 //  hashcode: 0xACE5BB38 (dec: -1394230472), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clipBeg;								 // size=0, offset=592 //  hashcode: 0xA006AD90 (dec: -1610175088), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clipEnd;								 // size=0, offset=594 //  hashcode: 0x834CD393 (dec: -2092117101), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct EventAliasCommandStruct aliasCommand; // size=12, offset=596 //  hashcode: 0x6CD7E213 (dec: 1826087443), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long light_color;							 // size=0, offset=608 //  hashcode: 0xF86FC59E (dec: -126892642), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CVECTOR *perVertexColor;				 // size=4, offset=612 //  hashcode: 0x6B4D42DF (dec: 1800225503), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GameTrackerASMData_Type // hashcode: 0x28F0BFB9 (dec: 686866361)
{
	long drawBackFaces;						// size=0, offset=0 //  hashcode: 0x2855ACCA (dec: 676703434), parent name: '_GameTrackerASMData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long dispPage;							// size=0, offset=4 //  hashcode: 0xC14ECA9E (dec: -1051800930), parent name: '_GameTrackerASMData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short MorphTime;						// size=0, offset=8 //  hashcode: 0x4797A3AD (dec: 1201120173), parent name: '_GameTrackerASMData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short MorphType;						// size=0, offset=10 //  hashcode: 0x5E21D98C (dec: 1579276684), parent name: '_GameTrackerASMData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LightInstance lightInstances[1]; // size=20, offset=12 //  hashcode: 0x7D6DD3A3 (dec: 2104349603), parent name: '_GameTrackerASMData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GameData_Type // hashcode: 0xE05EBAD0 (dec: -530662704)
{
	struct _GameTrackerASMData_Type asmData; // size=32, offset=0 //  hashcode: 0xC31E75FB (dec: -1021413893), parent name: '_GameData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct NodeType // hashcode: 0x5BF613D7 (dec: 1542853591)
{
	struct NodeType *prev; // size=8, offset=0 //  hashcode: 0x8B4DA622 (dec: -1957845470), parent name: 'NodeType', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType *next; // size=8, offset=4 //  hashcode: 0xDB8CB0B1 (dec: -611536719), parent name: 'NodeType', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TextureFT3 // hashcode: 0x2D2801D6 (dec: 757596630)
{
	unsigned char u0;	 // size=0, offset=0 //  hashcode: 0x4D995D02 (dec: 1301896450), parent name: 'TextureFT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v0;	 // size=0, offset=1 //  hashcode: 0x5C499D7A (dec: 1548328314), parent name: 'TextureFT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short clut;  // size=0, offset=2 //  hashcode: 0x7B31A1EB (dec: 2066850283), parent name: 'TextureFT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u1;	 // size=0, offset=4 //  hashcode: 0x6FFCC88C (dec: 1878837388), parent name: 'TextureFT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v1;	 // size=0, offset=5 //  hashcode: 0xCD34547F (dec: -852208513), parent name: 'TextureFT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short tpage; // size=0, offset=6 //  hashcode: 0x0086BEC0 (dec: 8830656), parent name: 'TextureFT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u2;	 // size=0, offset=8 //  hashcode: 0xE6FDFD96 (dec: -419562090), parent name: 'TextureFT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v2;	 // size=0, offset=9 //  hashcode: 0x79D36CD3 (dec: 2043899091), parent name: 'TextureFT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short attr;  // size=0, offset=10 //  hashcode: 0x612E6034 (dec: 1630429236), parent name: 'TextureFT3', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TextureMT3 // hashcode: 0xC9D0A5B9 (dec: -909072967)
{
	unsigned char u0;	 // size=0, offset=0 //  hashcode: 0x7D4F5DFE (dec: 2102353406), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v0;	 // size=0, offset=1 //  hashcode: 0x9DE39147 (dec: -1646030521), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short clut;  // size=0, offset=2 //  hashcode: 0x7447FD16 (dec: 1950874902), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u1;	 // size=0, offset=4 //  hashcode: 0xE3131B99 (dec: -485287015), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v1;	 // size=0, offset=5 //  hashcode: 0x36AA29CB (dec: 917121483), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short tpage; // size=0, offset=6 //  hashcode: 0x0178C08A (dec: 24690826), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u2;	 // size=0, offset=8 //  hashcode: 0x96D670D5 (dec: -1764331307), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v2;	 // size=0, offset=9 //  hashcode: 0x33EE7C9B (dec: 871267483), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pad1;			  // size=0, offset=10 //  hashcode: 0x55A74212 (dec: 1437024786), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	char sortPush;		  // size=0, offset=11 //  hashcode: 0xC7CA6541 (dec: -943037119), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;			  // size=0, offset=12 //  hashcode: 0xCEF04C6A (dec: -823112598), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AniTexInfo // hashcode: 0x907C013D (dec: -1870921411)
{
	struct TextureMT3 *texture; // size=16, offset=0 //  hashcode: 0xEFFB17CC (dec: -268757044), parent name: 'AniTexInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numFrames;				// size=0, offset=4 //  hashcode: 0x0FA39D76 (dec: 262380918), parent name: 'AniTexInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long speed;					// size=0, offset=8 //  hashcode: 0x276B896E (dec: 661358958), parent name: 'AniTexInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AniTex // hashcode: 0xE4DA2729 (dec: -455465175)
{
	long numAniTextues;			  // size=0, offset=0 //  hashcode: 0x99F85565 (dec: -1711778459), parent name: 'AniTex', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AniTexInfo aniTexInfo; // size=12, offset=4 //  hashcode: 0x1CA1CA01 (dec: 480365057), parent name: 'AniTex', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DrMoveAniTexSrcInfo // hashcode: 0x4AD6E543 (dec: 1255597379)
{
	short pixSrcX;  // size=0, offset=0 //  hashcode: 0x413F2180 (dec: 1094656384), parent name: 'DrMoveAniTexSrcInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pixSrcY;  // size=0, offset=2 //  hashcode: 0x3030263E (dec: 808461886), parent name: 'DrMoveAniTexSrcInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clutSrcX; // size=0, offset=4 //  hashcode: 0xA579D3CE (dec: -1518742578), parent name: 'DrMoveAniTexSrcInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clutSrcY; // size=0, offset=6 //  hashcode: 0x74796042 (dec: 1954111554), parent name: 'DrMoveAniTexSrcInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DrMoveAniTexDestInfo // hashcode: 0xF3A982EE (dec: -206994706)
{
	short pixDstX;					  // size=0, offset=0 //  hashcode: 0x1033CEC8 (dec: 271830728), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pixDstY;					  // size=0, offset=2 //  hashcode: 0x6BE2A260 (dec: 1810014816), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pixW;						  // size=0, offset=4 //  hashcode: 0x45E03E34 (dec: 1172323892), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pixH;						  // size=0, offset=6 //  hashcode: 0x1769E174 (dec: 392814964), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clutDstX;					  // size=0, offset=8 //  hashcode: 0xCB8A1C1A (dec: -880141286), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clutDstY;					  // size=0, offset=10 //  hashcode: 0x482A68D9 (dec: 1210738905), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clutW;					  // size=0, offset=12 //  hashcode: 0x8AC04915 (dec: -1967109867), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clutH;					  // size=0, offset=14 //  hashcode: 0x6280EEC5 (dec: 1652616901), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pixCurrentX;				  // size=0, offset=16 //  hashcode: 0xEDA21C0C (dec: -308143092), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pixCurrentY;				  // size=0, offset=18 //  hashcode: 0xB422357D (dec: -1272826499), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clutCurrentX;				  // size=0, offset=20 //  hashcode: 0x632AD4F4 (dec: 1663751412), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clutCurrentY;				  // size=0, offset=22 //  hashcode: 0xDE48ED84 (dec: -565645948), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numFrames;					  // size=0, offset=24 //  hashcode: 0x1307837F (dec: 319259519), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long speed;						  // size=0, offset=28 //  hashcode: 0xC05E0971 (dec: -1067579023), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DrMoveAniTexSrcInfo frame; // size=8, offset=32 //  hashcode: 0xB9784A51 (dec: -1183298991), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DrMoveAniTex // hashcode: 0x0820A5D4 (dec: 136357332)
{
	long numAniTextues;						 // size=0, offset=0 //  hashcode: 0xDB35395F (dec: -617268897), parent name: 'DrMoveAniTex', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DrMoveAniTexDestInfo *aniTexInfo; // size=40, offset=4 //  hashcode: 0xD5502A20 (dec: -716166624), parent name: 'DrMoveAniTex', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MemHeader // hashcode: 0xDAEE4890 (dec: -621918064)
{
	unsigned short magicNumber; // size=0, offset=0 //  hashcode: 0xAEFD2C60 (dec: -1359139744), parent name: 'MemHeader', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char memStatus;	// size=0, offset=2 //  hashcode: 0xFC04094E (dec: -66844338), parent name: 'MemHeader', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char memType;		// size=0, offset=3 //  hashcode: 0x8725D009 (dec: -2027565047), parent name: 'MemHeader', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long memSize;		// size=0, offset=4 //  hashcode: 0x32D81A75 (dec: 853023349), parent name: 'MemHeader', parent hashcode: 0xFFFFFFFF (dec: -1)
};

enum _G2Bool_Enum // Hashcode: 0xFDD7E4E7 (dec: -36182809)
{
	G2FALSE = 0,
};

struct _G2SVector3_Type // hashcode: 0x60FF7CCD (dec: 1627356365)
{
	short x; // size=0, offset=0 //  hashcode: 0x5877A7D1 (dec: 1484236753), parent name: '_G2SVector3_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0xE07F7772 (dec: -528517262), parent name: '_G2SVector3_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z; // size=0, offset=4 //  hashcode: 0x04E69F44 (dec: 82222916), parent name: '_G2SVector3_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2LVector3_Type // hashcode: 0xD8D79EE7 (dec: -656957721)
{
	long x; // size=0, offset=0 //  hashcode: 0xA568D983 (dec: -1519855229), parent name: '_G2LVector3_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long y; // size=0, offset=4 //  hashcode: 0x19F4A5EB (dec: 435463659), parent name: '_G2LVector3_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long z; // size=0, offset=8 //  hashcode: 0x8EE70E23 (dec: -1897460189), parent name: '_G2LVector3_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2Matrix_Type // hashcode: 0x647D6F57 (dec: 1685942103)
{
	short rotScale[3][3];		   // size=18, offset=0 //  hashcode: 0x2C774BDD (dec: 746015709), parent name: '_G2Matrix_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short scaleFlag;			   // size=0, offset=18 //  hashcode: 0x1A7B8837 (dec: 444303415), parent name: '_G2Matrix_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2LVector3_Type trans; // size=12, offset=20 //  hashcode: 0x055DB992 (dec: 90028434), parent name: '_G2Matrix_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2Quat_Type // hashcode: 0xC71F9EB1 (dec: -954229071)
{
	short x; // size=0, offset=0 //  hashcode: 0xE241F858 (dec: -498993064), parent name: '_G2Quat_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0xE76648C7 (dec: -412727097), parent name: '_G2Quat_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z; // size=0, offset=4 //  hashcode: 0x40B7587D (dec: 1085757565), parent name: '_G2Quat_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short w; // size=0, offset=6 //  hashcode: 0x8A8835F1 (dec: -1970784783), parent name: '_G2Quat_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimQuatInfo_Type // hashcode: 0x5A520473 (dec: 1515324531)
{
	struct _G2Quat_Type srcQuat;	   // size=8, offset=0 //  hashcode: 0x7A6AA796 (dec: 2053810070), parent name: '_G2AnimQuatInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type destQuat;	  // size=8, offset=8 //  hashcode: 0x6CAE778A (dec: 1823373194), parent name: '_G2AnimQuatInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type srcScale;  // size=6, offset=16 //  hashcode: 0xD872F456 (dec: -663554986), parent name: '_G2AnimQuatInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type destScale; // size=6, offset=22 //  hashcode: 0xA4731159 (dec: -1535962791), parent name: '_G2AnimQuatInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type srcTrans;  // size=6, offset=28 //  hashcode: 0x2EA5B2E7 (dec: 782611175), parent name: '_G2AnimQuatInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type destTrans; // size=6, offset=34 //  hashcode: 0x63E9DC06 (dec: 1676270598), parent name: '_G2AnimQuatInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimAlphaTable_Type // hashcode: 0x2288BF48 (dec: 579387208)
{
	unsigned short size; // size=0, offset=0 //  hashcode: 0x375CABA1 (dec: 928820129), parent name: '_G2AnimAlphaTable_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long data[0];		 // size=0, offset=4 //  hashcode: 0x12E4EFF6 (dec: 316993526), parent name: '_G2AnimAlphaTable_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimInterpStateBlock_Type // hashcode: 0xFB03DD89 (dec: -83632759)
{
	struct _G2AnimInterpStateBlock_Type *next; // size=164, offset=0 //  hashcode: 0x666A4BDD (dec: 1718242269), parent name: '_G2AnimInterpStateBlock_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimQuatInfo_Type quatInfo[4];   // size=160, offset=4 //  hashcode: 0xEA9207EB (dec: -359528469), parent name: '_G2AnimInterpStateBlock_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimInterpInfo_Type // hashcode: 0xAE13EB6F (dec: -1374426257)
{
	short duration;										 // size=0, offset=0 //  hashcode: 0xFA4DC0A3 (dec: -95567709), parent name: '_G2AnimInterpInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short targetTime;									 // size=0, offset=2 //  hashcode: 0x1965766E (dec: 426079854), parent name: '_G2AnimInterpInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimAlphaTable_Type *alphaTable;			 // size=4, offset=4 //  hashcode: 0xD44893E8 (dec: -733441048), parent name: '_G2AnimInterpInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimInterpStateBlock_Type *stateBlockList; // size=164, offset=8 //  hashcode: 0xBABBAB42 (dec: -1162106046), parent name: '_G2AnimInterpInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimChanStatus_Type // hashcode: 0x575B81AB (dec: 1465614763)
{
	short keyData; // size=0, offset=0 //  hashcode: 0x6B107CCF (dec: 1796242639), parent name: '_G2AnimChanStatus_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index;   // size=0, offset=2 //  hashcode: 0xEDF9A9A5 (dec: -302405211), parent name: '_G2AnimChanStatus_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimChanStatusBlock_Type // hashcode: 0xC6C09C4F (dec: -960455601)
{
	struct _G2AnimChanStatusBlock_Type *next; // size=36, offset=0 //  hashcode: 0x5C5FD595 (dec: 1549784469), parent name: '_G2AnimChanStatusBlock_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimChanStatus_Type chunks[8];  // size=32, offset=4 //  hashcode: 0x1D83554C (dec: 495146316), parent name: '_G2AnimChanStatusBlock_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimFxHeader_Type // hashcode: 0xA004B4ED (dec: -1610304275)
{
	unsigned char sizeAndSection; // size=0, offset=0 //  hashcode: 0xDD59A185 (dec: -581328507), parent name: '_G2AnimFxHeader_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	char type;					  // size=0, offset=1 //  hashcode: 0x00F2293B (dec: 15870267), parent name: '_G2AnimFxHeader_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short keyframeID;	// size=0, offset=2 //  hashcode: 0x5B00B5AA (dec: 1526773162), parent name: '_G2AnimFxHeader_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimKeylist_Type // hashcode: 0x87A15165 (dec: -2019471003)
{
	unsigned char sectionCount;			 // size=0, offset=0 //  hashcode: 0x5E5D1974 (dec: 1583159668), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char s0TailTime;			 // size=0, offset=1 //  hashcode: 0x5989B3F1 (dec: 1502196721), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char s1TailTime;			 // size=0, offset=2 //  hashcode: 0x21ED4B27 (dec: 569199399), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char s2TailTime;			 // size=0, offset=3 //  hashcode: 0xB8509689 (dec: -1202678135), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short keyCount;			 // size=0, offset=4 //  hashcode: 0x76D00229 (dec: 1993343529), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timePerKey;					 // size=0, offset=6 //  hashcode: 0xBC182987 (dec: -1139267193), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad00;				 // size=0, offset=8 //  hashcode: 0x2185428D (dec: 562381453), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad01;						 // size=0, offset=10 //  hashcode: 0x027658CB (dec: 41310411), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad10;				 // size=0, offset=12 //  hashcode: 0x6159986E (dec: 1633261678), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad11;						 // size=0, offset=14 //  hashcode: 0x6A65958A (dec: 1785042314), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimFxHeader_Type *fxList; // size=4, offset=16 //  hashcode: 0xC1F74E0C (dec: -1040757236), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short(*sectionData[0]);	 // size=0, offset=20 //  hashcode: 0xCD4909BC (dec: -850851396), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_73fake // hashcode: 0x2277CCA5 (dec: 578276517)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xA68942C3 (dec: -1500953917), parent name: 'PLAYER_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x0286FEB8 (dec: 42401464), parent name: 'PLAYER_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_74fake // hashcode: 0xDF6D7596 (dec: -546474602)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xB9D76D37 (dec: -1177064137), parent name: 'PLAYER_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x8F1808A7 (dec: -1894250329), parent name: 'PLAYER_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_75fake // hashcode: 0x7F2DAB29 (dec: 2133699369)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xD3ACCD78 (dec: -743649928), parent name: 'PLAYER_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x313BFF90 (dec: 826015632), parent name: 'PLAYER_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLAYER_76fake // Hashcode: 0x35EA4737 (dec: 904546103)
{
	struct PLAYER_73fake callback; // size=8, offset=0
	struct PLAYER_74fake vector;   // size=12, offset=0
	struct PLAYER_75fake quat;	 // size=16, offset=0
};

struct _G2AnimSection_Type // hashcode: 0xFC80328C (dec: -58707316)
{
	unsigned char flags;									 // size=0, offset=0 //  hashcode: 0xF87764F1 (dec: -126393103), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sectionID;								 // size=0, offset=1 //  hashcode: 0x2DF2EE39 (dec: 770895417), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char firstSeg;									 // size=0, offset=2 //  hashcode: 0xF890807D (dec: -124747651), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segCount;									 // size=0, offset=3 //  hashcode: 0xBAF5F0E5 (dec: -1158287131), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short elapsedTime;										 // size=0, offset=4 //  hashcode: 0x613FDBCF (dec: 1631574991), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short storedTime;										 // size=0, offset=6 //  hashcode: 0xF1B1B4B2 (dec: -240012110), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short loopStartTime;									 // size=0, offset=8 //  hashcode: 0x16C94137 (dec: 382288183), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short loopEndTime;										 // size=0, offset=10 //  hashcode: 0xBFFC4220 (dec: -1073987040), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *swAlarmTable;									 // size=0, offset=12 //  hashcode: 0x7AE0FAA5 (dec: 2061564581), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long speedAdjustment;									 // size=0, offset=16 //  hashcode: 0xEB4F93DB (dec: -347106341), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short keylistID;								 // size=0, offset=20 //  hashcode: 0x9F1C1719 (dec: -1625549031), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long alarmFlags;								 // size=0, offset=24 //  hashcode: 0x79E79922 (dec: 2045221154), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long (*callback)();										 // size=0, offset=28 //  hashcode: 0xCEFECCF5 (dec: -822162187), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *callbackData;										 // size=0, offset=32 //  hashcode: 0x5365FD9D (dec: 1399192989), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimKeylist_Type *keylist;					 // size=20, offset=36 //  hashcode: 0x40DB96D1 (dec: 1088132817), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimChanStatusBlock_Type *chanStatusBlockList; // size=36, offset=40 //  hashcode: 0xD1FEA901 (dec: -771839743), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimInterpInfo_Type *interpInfo;				 // size=12, offset=44 //  hashcode: 0x8472DC51 (dec: -2072847279), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2Anim_Type // hashcode: 0xF35FCCD2 (dec: -211825454)
{
	unsigned char sectionCount;			   // size=0, offset=0 //  hashcode: 0x6F91B40F (dec: 1871819791), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char masterSection;		   // size=0, offset=1 //  hashcode: 0x499570DE (dec: 1234530526), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short controllerList;		   // size=0, offset=2 //  hashcode: 0x462BE3AE (dec: 1177281454), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short disabledControllerList; // size=0, offset=4 //  hashcode: 0x5E72B05B (dec: 1584574555), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad;					   // size=0, offset=6 //  hashcode: 0x9E15AE52 (dec: -1642746286), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type rootTrans;	 // size=6, offset=8 //  hashcode: 0xDBBA9B2F (dec: -608527569), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short flags;				   // size=0, offset=14 //  hashcode: 0x261EE835 (dec: 639559733), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Model *modelData;			   // size=0, offset=16 //  hashcode: 0xDDBB0FAC (dec: -574943316), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Matrix_Type *segMatrices;	// size=32, offset=20 //  hashcode: 0xDF91277D (dec: -544135299), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long disabledBits[3];		   // size=12, offset=24 //  hashcode: 0x7B9833E0 (dec: 2073572320), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimSection_Type section[3]; // size=144, offset=36 //  hashcode: 0x035F348C (dec: 56571020), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Model // hashcode: 0x9BCE1D24 (dec: -1680990940)
{
	long numVertices;				  // size=0, offset=0 //  hashcode: 0x9921215F (dec: -1725882017), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MVertex *vertexList;	  // size=8, offset=4 //  hashcode: 0x9FF4C9CC (dec: -1611347508), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numNormals;				  // size=0, offset=8 //  hashcode: 0xB84CACC2 (dec: -1202934590), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVectorNoPad *normalList; // size=6, offset=12 //  hashcode: 0xD0880622 (dec: -796391902), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numFaces;					  // size=0, offset=16 //  hashcode: 0x522BC4E3 (dec: 1378600163), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MFace *faceList;		  // size=12, offset=20 //  hashcode: 0x28E8B574 (dec: 686339444), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numSegments;				  // size=0, offset=24 //  hashcode: 0x63A67EB5 (dec: 1671855797), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Segment *segmentList;	 // size=24, offset=28 //  hashcode: 0x3EA68E82 (dec: 1051102850), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AniTex *aniTextures;		  // size=16, offset=32 //  hashcode: 0x38962AFC (dec: 949365500), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxRad;					  // size=0, offset=36 //  hashcode: 0xB96B9ACC (dec: -1184130356), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;						  // size=0, offset=38 //  hashcode: 0x0087EE79 (dec: 8908409), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxRadSq;					  // size=0, offset=40 //  hashcode: 0xE1F4BAFA (dec: -504055046), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *multiSpline;  // size=0, offset=44 //  hashcode: 0x17BA1509 (dec: 398071049), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct TextureMT3 *startTextures; // size=16, offset=48 //  hashcode: 0xF16A4447 (dec: -244693945), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct TextureMT3 *endTextures;   // size=16, offset=52 //  hashcode: 0x4F56DA2B (dec: 1331092011), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _SVector // hashcode: 0x73B07C09 (dec: 1940945929)
{
	short x;   // size=0, offset=0 //  hashcode: 0x08A052A7 (dec: 144724647), parent name: '_SVector', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;   // size=0, offset=2 //  hashcode: 0x74BDBE34 (dec: 1958592052), parent name: '_SVector', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;   // size=0, offset=4 //  hashcode: 0x973AA93D (dec: -1757763267), parent name: '_SVector', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad; // size=0, offset=6 //  hashcode: 0x45EF1DAC (dec: 1173298604), parent name: '_SVector', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _SVectorNoPad // hashcode: 0xA6EDBBC6 (dec: -1494369338)
{
	short x; // size=0, offset=0 //  hashcode: 0x05A8A295 (dec: 94937749), parent name: '_SVectorNoPad', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0xD04029C5 (dec: -801101371), parent name: '_SVectorNoPad', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z; // size=0, offset=4 //  hashcode: 0x685B61F9 (dec: 1750819321), parent name: '_SVectorNoPad', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Position // hashcode: 0x2523C22F (dec: 623100463)
{
	short x; // size=0, offset=0 //  hashcode: 0x583D5468 (dec: 1480414312), parent name: '_Position', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0x66ACC135 (dec: 1722597685), parent name: '_Position', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z; // size=0, offset=4 //  hashcode: 0xE498BAB5 (dec: -459752779), parent name: '_Position', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Rotation // hashcode: 0x5A40CBB0 (dec: 1514195888)
{
	short x;   // size=0, offset=0 //  hashcode: 0x33B21012 (dec: 867307538), parent name: '_Rotation', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;   // size=0, offset=2 //  hashcode: 0x900454E1 (dec: -1878764319), parent name: '_Rotation', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;   // size=0, offset=4 //  hashcode: 0x9D9370BD (dec: -1651281731), parent name: '_Rotation', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad; // size=0, offset=6 //  hashcode: 0xE7BFC418 (dec: -406862824), parent name: '_Rotation', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Normal // hashcode: 0xC59D5A5B (dec: -979543461)
{
	short x;   // size=0, offset=0 //  hashcode: 0x7473D7DA (dec: 1953748954), parent name: '_Normal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;   // size=0, offset=2 //  hashcode: 0x21D414C5 (dec: 567547077), parent name: '_Normal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;   // size=0, offset=4 //  hashcode: 0xEAE589EA (dec: -354055702), parent name: '_Normal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad; // size=0, offset=6 //  hashcode: 0x33C50399 (dec: 868549529), parent name: '_Normal', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _PlaneConstants // hashcode: 0xE1AAD777 (dec: -508897417)
{
	short a;	 // size=0, offset=0 //  hashcode: 0x1F992779 (dec: 530130809), parent name: '_PlaneConstants', parent hashcode: 0xFFFFFFFF (dec: -1)
	short b;	 // size=0, offset=2 //  hashcode: 0x6F77C59B (dec: 1870120347), parent name: '_PlaneConstants', parent hashcode: 0xFFFFFFFF (dec: -1)
	short c;	 // size=0, offset=4 //  hashcode: 0x7C10A909 (dec: 2081466633), parent name: '_PlaneConstants', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags; // size=0, offset=6 //  hashcode: 0x295E591C (dec: 694049052), parent name: '_PlaneConstants', parent hashcode: 0xFFFFFFFF (dec: -1)
	long d;		 // size=0, offset=8 //  hashcode: 0xE0DBA5D5 (dec: -522476075), parent name: '_PlaneConstants', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Vertex // hashcode: 0x97101469 (dec: -1760553879)
{
	short x; // size=0, offset=0 //  hashcode: 0xBDB7C875 (dec: -1112029067), parent name: '_Vertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0x1E17E0FD (dec: 504881405), parent name: '_Vertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z; // size=0, offset=4 //  hashcode: 0x997C0D51 (dec: -1719923375), parent name: '_Vertex', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Face // hashcode: 0x8775891B (dec: -2022340325)
{
	unsigned short v0; // size=0, offset=0 //  hashcode: 0x86B628EA (dec: -2034882326), parent name: '_Face', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short v1; // size=0, offset=2 //  hashcode: 0x2C1049EF (dec: 739265007), parent name: '_Face', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short v2; // size=0, offset=4 //  hashcode: 0x0BB6F73B (dec: 196540219), parent name: '_Face', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MVertex // hashcode: 0x2B95C05B (dec: 731234395)
{
	struct _Vertex vertex; // size=6, offset=0 //  hashcode: 0x6CC4E410 (dec: 1824842768), parent name: '_MVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short normal; // size=0, offset=6 //  hashcode: 0x690A4802 (dec: 1762281474), parent name: '_MVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MFace // hashcode: 0xB75C604D (dec: -1218682803)
{
	struct _Face face;	// size=6, offset=0 //  hashcode: 0x71B0D230 (dec: 1907413552), parent name: '_MFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char normal; // size=0, offset=6 //  hashcode: 0x9FFF9D21 (dec: -1610638047), parent name: '_MFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;  // size=0, offset=7 //  hashcode: 0x0C27CFB3 (dec: 203935667), parent name: '_MFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;			  // size=0, offset=8 //  hashcode: 0xF15E1C0E (dec: -245490674), parent name: '_MFace', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _RGBAColor // hashcode: 0xF7174D90 (dec: -149467760)
{
	unsigned char r; // size=0, offset=0 //  hashcode: 0x30F25BDF (dec: 821189599), parent name: '_RGBAColor', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g; // size=0, offset=1 //  hashcode: 0xA1938AAA (dec: -1584166230), parent name: '_RGBAColor', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b; // size=0, offset=2 //  hashcode: 0xBCE3FD2D (dec: -1125909203), parent name: '_RGBAColor', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char a; // size=0, offset=3 //  hashcode: 0xA7DFD488 (dec: -1478503288), parent name: '_RGBAColor', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLAYER_77fake // Hashcode: 0xBB3AB3AC (dec: -1153780820)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct _PVertex // hashcode: 0x4AC0ECE8 (dec: 1254157544)
{
	short x;  // size=0, offset=0 //  hashcode: 0xFFCCEB52 (dec: -3347630), parent name: '_PVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;  // size=0, offset=2 //  hashcode: 0x7D8D8533 (dec: 2106426675), parent name: '_PVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	long otz; // size=0, offset=4 //  hashcode: 0x04224934 (dec: 69355828), parent name: '_PVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _VertexPool // hashcode: 0x98F8C96E (dec: -1728525970)
{
	struct _PVertex vertex[528]; // size=4224, offset=0 //  hashcode: 0xA3AEACE8 (dec: -1548833560), parent name: '_VertexPool', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CVECTOR color[528];   // size=2112, offset=4224 //  hashcode: 0xAB87CE80 (dec: -1417163136), parent name: '_VertexPool', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _PrimPool // hashcode: 0x9529B283 (dec: -1792429437)
{
	long numPrims;			   // size=0, offset=0 //  hashcode: 0x498A21E7 (dec: 1233789415), parent name: '_PrimPool', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long *nextPrim;   // size=0, offset=4 //  hashcode: 0xAB396725 (dec: -1422301403), parent name: '_PrimPool', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long *lastPrim;   // size=0, offset=8 //  hashcode: 0x923639E4 (dec: -1841939996), parent name: '_PrimPool', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long prim[24000]; // size=96000, offset=12 //  hashcode: 0xE19E53F7 (dec: -509717513), parent name: '_PrimPool', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Sphere // hashcode: 0x361BDD31 (dec: 907795761)
{
	struct _Position position;   // size=6, offset=0 //  hashcode: 0xE3EEA9D9 (dec: -470898215), parent name: '_Sphere', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short radius;		 // size=0, offset=6 //  hashcode: 0xB22C8E58 (dec: -1305702824), parent name: '_Sphere', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long radiusSquared; // size=0, offset=8 //  hashcode: 0xA375AC20 (dec: -1552569312), parent name: '_Sphere', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Sphere_noSq // hashcode: 0xA031058C (dec: -1607400052)
{
	struct _Position position; // size=6, offset=0 //  hashcode: 0x7F78BF7C (dec: 2138619772), parent name: '_Sphere_noSq', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short radius;	 // size=0, offset=6 //  hashcode: 0x87DD193F (dec: -2015553217), parent name: '_Sphere_noSq', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _CameraKey // hashcode: 0xB9E6B724 (dec: -1176062172)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x13BAB6BA (dec: 331003578), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xB3884FFA (dec: -1282912262), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;	 // size=0, offset=4 //  hashcode: 0x09F28463 (dec: 166888547), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short id;	// size=0, offset=6 //  hashcode: 0x502DF9D3 (dec: 1345190355), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rx;	// size=0, offset=8 //  hashcode: 0x42907FCD (dec: 1116766157), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ry;	// size=0, offset=10 //  hashcode: 0x21990E3C (dec: 563678780), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rz;	// size=0, offset=12 //  hashcode: 0x53989B7F (dec: 1402510207), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags; // size=0, offset=14 //  hashcode: 0xE7A9FE6F (dec: -408289681), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short tx;	// size=0, offset=16 //  hashcode: 0xCC4C3A90 (dec: -867419504), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ty;	// size=0, offset=18 //  hashcode: 0x6FF95733 (dec: 1878611763), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short tz;	// size=0, offset=20 //  hashcode: 0xB3E47FE7 (dec: -1276870681), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;   // size=0, offset=22 //  hashcode: 0x0A6047E7 (dec: 174082023), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct Object // hashcode: 0xEC12E9AC (dec: -334304852)
{
	long oflags;						   // size=0, offset=0 //  hashcode: 0xDA3627CB (dec: -633985077), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short id;							   // size=0, offset=4 //  hashcode: 0x59373C64 (dec: 1496792164), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sfxFileHandle;				   // size=0, offset=6 //  hashcode: 0x6C480C2C (dec: 1816661036), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numModels;					   // size=0, offset=8 //  hashcode: 0x9527F657 (dec: -1792543145), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numAnims;						   // size=0, offset=10 //  hashcode: 0x1D8EBDF4 (dec: 495894004), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Model **modelList;			   // size=56, offset=12 //  hashcode: 0x70631414 (dec: 1885541396), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimKeylist_Type **animList; // size=20, offset=16 //  hashcode: 0xA2158DDF (dec: -1575645729), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short introDist;					   // size=0, offset=20 //  hashcode: 0xB4B4CF74 (dec: -1263218828), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vvIntroDist;					   // size=0, offset=22 //  hashcode: 0x7778B825 (dec: 2004400165), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short removeDist;					   // size=0, offset=24 //  hashcode: 0xCCB7623F (dec: -860396993), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vvRemoveDist;					   // size=0, offset=26 //  hashcode: 0x17315AEB (dec: 389110507), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;							   // size=0, offset=28 //  hashcode: 0x4026883B (dec: 1076267067), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *script;						   // size=0, offset=32 //  hashcode: 0x543F7EE6 (dec: 1413447398), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *name;							   // size=0, offset=36 //  hashcode: 0xA37E2F44 (dec: -1552011452), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char *soundData;			   // size=0, offset=40 //  hashcode: 0xE70F395C (dec: -418432676), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	long oflags2;						   // size=0, offset=44 //  hashcode: 0x6283252E (dec: 1652761902), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sectionA;						   // size=0, offset=48 //  hashcode: 0x7B140262 (dec: 2064908898), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sectionB;						   // size=0, offset=50 //  hashcode: 0x96BC3E8B (dec: -1766048117), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sectionC;						   // size=0, offset=52 //  hashcode: 0xFD846DDC (dec: -41652772), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numberOfEffects;				   // size=0, offset=54 //  hashcode: 0x2E3D8DBC (dec: 775785916), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct ObjectEffect *effectList;	   // size=4, offset=56 //  hashcode: 0xDFF64033 (dec: -537509837), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long *relocList;			   // size=0, offset=60 //  hashcode: 0x58294F36 (dec: 1479102262), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *relocModule;					   // size=0, offset=64 //  hashcode: 0xC026F20D (dec: -1071189491), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct VramSize vramSize;			   // size=8, offset=68 //  hashcode: 0x31E46F0D (dec: 837054221), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BVertex // hashcode: 0xADD3BD2F (dec: -1378632401)
{
	short x;   // size=0, offset=0 //  hashcode: 0xB6040E5B (dec: -1241248165), parent name: '_BVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;   // size=0, offset=2 //  hashcode: 0x01AEFFA3 (dec: 28245923), parent name: '_BVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;   // size=0, offset=4 //  hashcode: 0x74B349FF (dec: 1957906943), parent name: '_BVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad; // size=0, offset=6 //  hashcode: 0xCD0D01C3 (dec: -854785597), parent name: '_BVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BFace // hashcode: 0x69100F99 (dec: 1762660249)
{
	short v0;					// size=0, offset=0 //  hashcode: 0xBB1F9B80 (dec: -1155556480), parent name: '_BFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short v1;					// size=0, offset=2 //  hashcode: 0x5AEDB1C9 (dec: 1525526985), parent name: '_BFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short v2;					// size=0, offset=4 //  hashcode: 0x9CA5E9A9 (dec: -1666848343), parent name: '_BFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;					// size=0, offset=6 //  hashcode: 0x03FB21A7 (dec: 66789799), parent name: '_BFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct TextureFT3 *texture; // size=12, offset=8 //  hashcode: 0x75565B2D (dec: 1968593709), parent name: '_BFace', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BGObject // hashcode: 0xEC69FB30 (dec: -328598736)
{
	short flags;				 // size=0, offset=0 //  hashcode: 0xAD4DCD55 (dec: -1387410091), parent name: '_BGObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numFaces;				 // size=0, offset=2 //  hashcode: 0xF8DFCE4B (dec: -119550389), parent name: '_BGObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BVertex *vertexList; // size=8, offset=4 //  hashcode: 0x3A1CB45D (dec: 974959709), parent name: '_BGObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BFace *faceList;	 // size=12, offset=8 //  hashcode: 0x969F847D (dec: -1767930755), parent name: '_BGObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x;					 // size=0, offset=12 //  hashcode: 0x51D75797 (dec: 1373067159), parent name: '_BGObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;					 // size=0, offset=14 //  hashcode: 0x7ED407A3 (dec: 2127824803), parent name: '_BGObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;					 // size=0, offset=16 //  hashcode: 0xD18CDEC8 (dec: -779297080), parent name: '_BGObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short radius;				 // size=0, offset=18 //  hashcode: 0x420AA500 (dec: 1107993856), parent name: '_BGObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numVertices;			 // size=0, offset=20 //  hashcode: 0xD9D925D6 (dec: -640080426), parent name: '_BGObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLAYER_78fake // Hashcode: 0xDC9E4F50 (dec: -593604784)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct PLAYER_79fake // hashcode: 0x20F1CC05 (dec: 552717317)
{
	union PLAYER_78fake size; // size=4, offset=0 //  hashcode: 0xDE701A1F (dec: -563078625), parent name: 'PLAYER_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_80fake // hashcode: 0x6CD442DE (dec: 1825850078)
{
	short x;				// size=0, offset=0 //  hashcode: 0xE9083E4F (dec: -385335729), parent name: 'PLAYER_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x2FEFD8E3 (dec: 804247779), parent name: 'PLAYER_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xFB054C1E (dec: -83538914), parent name: 'PLAYER_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xA8404D25 (dec: -1472180955), parent name: 'PLAYER_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x3F8C60F2 (dec: 1066164466), parent name: 'PLAYER_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_81fake // hashcode: 0x28855D2C (dec: 679828780)
{
	long index; // size=0, offset=0 //  hashcode: 0x3C28BE74 (dec: 1009303156), parent name: 'PLAYER_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x00FBD577 (dec: 16504183), parent name: 'PLAYER_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_82fake // hashcode: 0x07EB41CA (dec: 132858314)
{
	long index; // size=0, offset=0 //  hashcode: 0xCE4AB7B2 (dec: -833964110), parent name: 'PLAYER_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xE3E5AF81 (dec: -471486591), parent name: 'PLAYER_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_83fake // hashcode: 0x3500539D (dec: 889213853)
{
	long index; // size=0, offset=0 //  hashcode: 0x02DFE8CF (dec: 48228559), parent name: 'PLAYER_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x85D337E4 (dec: -2049755164), parent name: 'PLAYER_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_84fake // hashcode: 0x3C11B70B (dec: 1007793931)
{
	long time;  // size=0, offset=0 //  hashcode: 0x3FF33796 (dec: 1072904086), parent name: 'PLAYER_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xD922C9DD (dec: -652031523), parent name: 'PLAYER_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_85fake // hashcode: 0xEA90FDE8 (dec: -359596568)
{
	long action;   // size=0, offset=0 //  hashcode: 0x9725AC0F (dec: -1759138801), parent name: 'PLAYER_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x3184949B (dec: 830772379), parent name: 'PLAYER_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_86fake // hashcode: 0x591DEB55 (dec: 1495133013)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x3317FE41 (dec: 857210433), parent name: 'PLAYER_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x02FB9BB7 (dec: 50043831), parent name: 'PLAYER_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_87fake // hashcode: 0xAB018DA4 (dec: -1425961564)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xE1167F48 (dec: -518619320), parent name: 'PLAYER_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x98E5A44B (dec: -1729780661), parent name: 'PLAYER_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_88fake // hashcode: 0xCA01041F (dec: -905903073)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x9E8E444F (dec: -1634843569), parent name: 'PLAYER_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x2B0A45A6 (dec: 722093478), parent name: 'PLAYER_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_89fake // hashcode: 0xB104F157 (dec: -1325076137)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x3C5EC5BB (dec: 1012843963), parent name: 'PLAYER_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x618FBD5F (dec: 1636810079), parent name: 'PLAYER_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xBA7D760A (dec: -1166182902), parent name: 'PLAYER_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xFDD8ED67 (dec: -36115097), parent name: 'PLAYER_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x17414AA4 (dec: 390154916), parent name: 'PLAYER_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct Signal // hashcode: 0xA0225F88 (dec: -1608360056)
{
	long id;				   // size=0, offset=0 //  hashcode: 0x6B9BBF4A (dec: 1805369162), parent name: 'Signal', parent hashcode: 0xFFFFFFFF (dec: -1)
	union PLAYER_102fake data; // size=24, offset=4 //  hashcode: 0xF501B407 (dec: -184437753), parent name: 'Signal', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_90fake // hashcode: 0x92CB9988 (dec: -1832150648)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x6E3CE53B (dec: 1849484603), parent name: 'PLAYER_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x8AB3A26F (dec: -1967938961), parent name: 'PLAYER_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_91fake // hashcode: 0x5193A947 (dec: 1368631623)
{
	short index;					// size=0, offset=0 //  hashcode: 0x38873341 (dec: 948384577), parent name: 'PLAYER_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x2B7FED70 (dec: 729804144), parent name: 'PLAYER_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xA204EC43 (dec: -1576735677), parent name: 'PLAYER_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x67D3CD09 (dec: 1741933833), parent name: 'PLAYER_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_92fake // hashcode: 0xD1146EEE (dec: -787190034)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xE405BBE7 (dec: -469386265), parent name: 'PLAYER_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x5E0560F7 (dec: 1577410807), parent name: 'PLAYER_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xB722CA58 (dec: -1222456744), parent name: 'PLAYER_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_93fake // hashcode: 0x014CF670 (dec: 21821040)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x64BADDDB (dec: 1689968091), parent name: 'PLAYER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x7DAEA4FE (dec: 2108597502), parent name: 'PLAYER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x2142DCBB (dec: 558030011), parent name: 'PLAYER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x74D01F1F (dec: 1959796511), parent name: 'PLAYER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xD6FF5FFC (dec: -687906820), parent name: 'PLAYER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xC09970AB (dec: -1063685973), parent name: 'PLAYER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xB1DB1304 (dec: -1311042812), parent name: 'PLAYER_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_94fake // hashcode: 0x90CF391D (dec: -1865467619)
{
	long index;  // size=0, offset=0 //  hashcode: 0x1DD467F5 (dec: 500459509), parent name: 'PLAYER_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x985C63DF (dec: -1738775585), parent name: 'PLAYER_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_95fake // hashcode: 0xBE6C473C (dec: -1100200132)
{
	short type; // size=0, offset=0 //  hashcode: 0x99AC4FB8 (dec: -1716760648), parent name: 'PLAYER_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xE69E1CEE (dec: -425845522), parent name: 'PLAYER_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_96fake // hashcode: 0x62EB0A24 (dec: 1659570724)
{
	long time;   // size=0, offset=0 //  hashcode: 0x0111A240 (dec: 17932864), parent name: 'PLAYER_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xE756B1F6 (dec: -413748746), parent name: 'PLAYER_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_97fake // hashcode: 0x0AA8A647 (dec: 178824775)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x2B784EAD (dec: 729304749), parent name: 'PLAYER_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x3B231C7F (dec: 992156799), parent name: 'PLAYER_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_98fake // hashcode: 0x134A9B24 (dec: 323656484)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x1AA3D38C (dec: 446944140), parent name: 'PLAYER_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x68528D8A (dec: 1750240650), parent name: 'PLAYER_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_99fake // hashcode: 0xB61AB07A (dec: -1239764870)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x2D12FF12 (dec: 756219666), parent name: 'PLAYER_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xF7A06440 (dec: -140483520), parent name: 'PLAYER_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_100fake // hashcode: 0xD1E253E7 (dec: -773696537)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0xA99A502C (dec: -1449504724), parent name: 'PLAYER_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x4F02B139 (dec: 1325576505), parent name: 'PLAYER_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xEAF85838 (dec: -352823240), parent name: 'PLAYER_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xBADCA838 (dec: -1159944136), parent name: 'PLAYER_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_101fake // hashcode: 0x0B40B4F9 (dec: 188790009)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x0F51B7EE (dec: 257013742), parent name: 'PLAYER_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xA8F0AD1A (dec: -1460622054), parent name: 'PLAYER_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x35D12C61 (dec: 902900833), parent name: 'PLAYER_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x7099344F (dec: 1889088591), parent name: 'PLAYER_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x802BAF40 (dec: -2144620736), parent name: 'PLAYER_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLAYER_102fake // Hashcode: 0xEF0F9FA5 (dec: -284188763)
{
	struct PLAYER_79fake misc[3];	  // size=12, offset=0
	struct _CameraKey *cameraKey;	  // size=24, offset=0
	struct PLAYER_80fake teleport;	 // size=16, offset=0
	struct PLAYER_81fake cameraValue;  // size=8, offset=0
	struct PLAYER_82fake miscValue;	// size=8, offset=0
	struct PLAYER_83fake logicValue;   // size=8, offset=0
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
	struct PLAYER_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				   // size=0, offset=0
	long cameraRestore;				   // size=0, offset=0
	struct _BGObject *bgObject;		   // size=24, offset=0
	long value[2];					   // size=8, offset=0
	struct PLAYER_85fake sound;		   // size=12, offset=0
	void *intro;					   // size=0, offset=0
	long deathZ;					   // size=0, offset=0
	struct PLAYER_86fake dsignal;	  // size=8, offset=0
	void *mirror;					   // size=0, offset=0
	long fogNear;					   // size=0, offset=0
	long fogFar;					   // size=0, offset=0
	struct PLAYER_87fake gotoFrame;	// size=8, offset=0
	struct PLAYER_88fake changeModel;  // size=8, offset=0
	void *vmObject;					   // size=0, offset=0
	struct PLAYER_89fake logic;		   // size=8, offset=0
	void *callSignal;				   // size=0, offset=0
	struct _SVector offset;			   // size=8, offset=0
	struct Signal *gotoLabel;		   // size=0, offset=0
	struct Signal *gosubLabel;		   // size=0, offset=0
	struct PLAYER_90fake control;	  // size=8, offset=0
	struct PLAYER_91fake zSignal;	  // size=12, offset=0
	struct PLAYER_92fake StreamLevel;  // size=24, offset=0
	struct PLAYER_93fake shards;	   // size=12, offset=0
	struct PLAYER_94fake cameraSpline; // size=8, offset=0
	struct PLAYER_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				   // size=0, offset=0
	struct PLAYER_96fake introFX;	  // size=8, offset=0
	struct PLAYER_97fake introActive;  // size=8, offset=0
	struct PLAYER_98fake levelChange;  // size=18, offset=0
	long blendStart;				   // size=0, offset=0
	struct PLAYER_99fake setTimes;	 // size=8, offset=0
	struct PLAYER_100fake color;	   // size=4, offset=0
	struct PLAYER_101fake print;	   // size=12, offset=0
	long slideAngle;				   // size=0, offset=0
};

struct _MultiSignal // hashcode: 0x0620B768 (dec: 102807400)
{
	long numSignals;			  // size=0, offset=0 //  hashcode: 0xF4A14626 (dec: -190757338), parent name: '_MultiSignal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short signalNum;			  // size=0, offset=4 //  hashcode: 0x5C48DC21 (dec: 1548278817), parent name: '_MultiSignal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;				  // size=0, offset=6 //  hashcode: 0xC0D461F2 (dec: -1059823118), parent name: '_MultiSignal', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal signalList[32]; // size=896, offset=8 //  hashcode: 0x362EB6D1 (dec: 909031121), parent name: '_MultiSignal', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _HFace // hashcode: 0x30CA5CA6 (dec: 818568358)
{
	short v0;			   // size=0, offset=0 //  hashcode: 0xFA36FB0F (dec: -97060081), parent name: '_HFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short v1;			   // size=0, offset=2 //  hashcode: 0x2D224B98 (dec: 757222296), parent name: '_HFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short v2;			   // size=0, offset=4 //  hashcode: 0xD93621E1 (dec: -650763807), parent name: '_HFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char attr;	// size=0, offset=6 //  hashcode: 0x472219A6 (dec: 1193417126), parent name: '_HFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pad;			   // size=0, offset=7 //  hashcode: 0xE55101B2 (dec: -447675982), parent name: '_HFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short normal; // size=0, offset=8 //  hashcode: 0xA9D1AED6 (dec: -1445876010), parent name: '_HFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short n0;	 // size=0, offset=10 //  hashcode: 0x779C9497 (dec: 2006750359), parent name: '_HFace', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _HSphere // hashcode: 0x8E7B7191 (dec: -1904512623)
{
	long attr;					 // size=0, offset=0 //  hashcode: 0xB0ACAEC1 (dec: -1330860351), parent name: '_HSphere', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char id;			 // size=0, offset=4 //  hashcode: 0x3636D2F7 (dec: 909562615), parent name: '_HSphere', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char rank;			 // size=0, offset=5 //  hashcode: 0x4B46C0C0 (dec: 1262928064), parent name: '_HSphere', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;					 // size=0, offset=6 //  hashcode: 0xE155D32D (dec: -514469075), parent name: '_HSphere', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position;   // size=6, offset=8 //  hashcode: 0xD4FA72E8 (dec: -721784088), parent name: '_HSphere', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short radius;		 // size=0, offset=14 //  hashcode: 0x93E3A271 (dec: -1813798287), parent name: '_HSphere', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long radiusSquared; // size=0, offset=16 //  hashcode: 0xDF9EB4BD (dec: -543247171), parent name: '_HSphere', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _HBox // hashcode: 0x47CD8BDA (dec: 1204653018)
{
	short flags;		// size=0, offset=0 //  hashcode: 0xEE9EA6D5 (dec: -291592491), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char id;   // size=0, offset=2 //  hashcode: 0xF5D49465 (dec: -170617755), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char rank; // size=0, offset=3 //  hashcode: 0xA2E924F3 (dec: -1561778957), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minX;			// size=0, offset=4 //  hashcode: 0xBCECC914 (dec: -1125332716), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minY;			// size=0, offset=6 //  hashcode: 0x3FC05179 (dec: 1069568377), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minZ;			// size=0, offset=8 //  hashcode: 0x3E30F2DE (dec: 1043395294), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxX;			// size=0, offset=10 //  hashcode: 0xAE66E2C3 (dec: -1368988989), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxY;			// size=0, offset=12 //  hashcode: 0x10C050B2 (dec: 281039026), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxZ;			// size=0, offset=14 //  hashcode: 0x47D12A07 (dec: 1204890119), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short refMinX;		// size=0, offset=16 //  hashcode: 0x2EE494F1 (dec: 786732273), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short refMinY;		// size=0, offset=18 //  hashcode: 0x09AFCC35 (dec: 162516021), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short refMinZ;		// size=0, offset=20 //  hashcode: 0x60F6AE5D (dec: 1626779229), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short refMaxX;		// size=0, offset=22 //  hashcode: 0xA173830B (dec: -1586265333), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short refMaxY;		// size=0, offset=24 //  hashcode: 0x0B08CF4F (dec: 185126735), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short refMaxZ;		// size=0, offset=26 //  hashcode: 0x593F988D (dec: 1497340045), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLAYER_103fake // Hashcode: 0x99350876 (dec: -1724577674)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

struct _HPrim // hashcode: 0x988F5E11 (dec: -1735434735)
{
	unsigned char hpFlags;	 // size=0, offset=0 //  hashcode: 0xAB881355 (dec: -1417145515), parent name: '_HPrim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char withFlags;   // size=0, offset=1 //  hashcode: 0xE18A5ABC (dec: -511026500), parent name: '_HPrim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;		   // size=0, offset=2 //  hashcode: 0xAE4E7EE7 (dec: -1370587417), parent name: '_HPrim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segment;	 // size=0, offset=3 //  hashcode: 0x47B85330 (dec: 1203262256), parent name: '_HPrim', parent hashcode: 0xFFFFFFFF (dec: -1)
	union PLAYER_103fake data; // size=4, offset=4 //  hashcode: 0xF7F81D7D (dec: -134734467), parent name: '_HPrim', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _HModel // hashcode: 0xBC680356 (dec: -1134034090)
{
	struct _HPrim *hPrimList; // size=8, offset=0 //  hashcode: 0x9BF5B7F8 (dec: -1678395400), parent name: '_HModel', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numHPrims;			  // size=0, offset=4 //  hashcode: 0x058DBE2D (dec: 93175341), parent name: '_HModel', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _HInfo // hashcode: 0x6AC9807F (dec: 1791590527)
{
	long numHFaces;				  // size=0, offset=0 //  hashcode: 0x915BDB99 (dec: -1856250983), parent name: '_HInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HFace *hfaceList;	 // size=12, offset=4 //  hashcode: 0x52D8AD66 (dec: 1389931878), parent name: '_HInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numHSpheres;			  // size=0, offset=8 //  hashcode: 0xA035ABDE (dec: -1607095330), parent name: '_HInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HSphere *hsphereList; // size=20, offset=12 //  hashcode: 0xF7FF3A13 (dec: -134268397), parent name: '_HInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numHBoxes;				  // size=0, offset=16 //  hashcode: 0xE20B3D5D (dec: -502579875), parent name: '_HInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HBox *hboxList;		  // size=28, offset=20 //  hashcode: 0x6E61EEDA (dec: 1851911898), parent name: '_HInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Segment // hashcode: 0x2F06BF28 (dec: 788971304)
{
	long flags;			  // size=0, offset=0 //  hashcode: 0x31B05B61 (dec: 833641313), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
	short firstTri;		  // size=0, offset=4 //  hashcode: 0x2525E857 (dec: 623241303), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lastTri;		  // size=0, offset=6 //  hashcode: 0xA4768FE8 (dec: -1535733784), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
	short firstVertex;	// size=0, offset=8 //  hashcode: 0x8343A559 (dec: -2092718759), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lastVertex;	 // size=0, offset=10 //  hashcode: 0xB1F41DAC (dec: -1309401684), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
	short px;			  // size=0, offset=12 //  hashcode: 0x5430B013 (dec: 1412476947), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
	short py;			  // size=0, offset=14 //  hashcode: 0x2A80BDF3 (dec: 713080307), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pz;			  // size=0, offset=16 //  hashcode: 0x94F0BE47 (dec: -1796161977), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
	short parent;		  // size=0, offset=18 //  hashcode: 0x990CE600 (dec: -1727207936), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HInfo *hInfo; // size=24, offset=20 //  hashcode: 0x83DD51B5 (dec: -2082647627), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MultiSpline // hashcode: 0x2823B2CF (dec: 673428175)
{
	struct Spline *positional;		// size=8, offset=0 //  hashcode: 0xD111C04C (dec: -787365812), parent name: 'MultiSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RSpline *rotational;		// size=8, offset=4 //  hashcode: 0xACBF6077 (dec: -1396744073), parent name: 'MultiSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Spline *scaling;			// size=8, offset=8 //  hashcode: 0xB162004A (dec: -1318977462), parent name: 'MultiSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Spline *color;			// size=8, offset=12 //  hashcode: 0x7E26D337 (dec: 2116473655), parent name: 'MultiSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SplineDef curPositional; // size=8, offset=16 //  hashcode: 0xDA32CD3C (dec: -634204868), parent name: 'MultiSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SplineDef curRotational; // size=8, offset=24 //  hashcode: 0x90E53563 (dec: -1864026781), parent name: 'MultiSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SplineDef curScaling;	// size=8, offset=32 //  hashcode: 0x5497DB32 (dec: 1419238194), parent name: 'MultiSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SplineDef curColor;		// size=8, offset=40 //  hashcode: 0xD84C232E (dec: -666098898), parent name: 'MultiSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX curRotMatrix;		// size=32, offset=48 //  hashcode: 0x2DD49D2B (dec: 768908587), parent name: 'MultiSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SoundInstance // hashcode: 0xFF235679 (dec: -14461319)
{
	unsigned char channel; // size=0, offset=0 //  hashcode: 0x61316CDF (dec: 1630629087), parent name: 'SoundInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char state;   // size=0, offset=1 //  hashcode: 0xB9825B15 (dec: -1182639339), parent name: 'SoundInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char delay;   // size=0, offset=2 //  hashcode: 0x184E0534 (dec: 407766324), parent name: 'SoundInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ObjectEffect // hashcode: 0x2892438D (dec: 680674189)
{
	unsigned char effectNumber;	// size=0, offset=0 //  hashcode: 0x3175E9DA (dec: 829811162), parent name: 'ObjectEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char modifierList[3]; // size=3, offset=1 //  hashcode: 0xDA8EB51C (dec: -628181732), parent name: 'ObjectEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VramSize // hashcode: 0xD96A55BF (dec: -647342657)
{
	short x; // size=0, offset=0 //  hashcode: 0x2CD17F07 (dec: 751927047), parent name: 'VramSize', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0xC9E6A47F (dec: -907631489), parent name: 'VramSize', parent hashcode: 0xFFFFFFFF (dec: -1)
	short w; // size=0, offset=4 //  hashcode: 0x7C86671F (dec: 2089183007), parent name: 'VramSize', parent hashcode: 0xFFFFFFFF (dec: -1)
	short h; // size=0, offset=6 //  hashcode: 0xD6FF3001 (dec: -687919103), parent name: 'VramSize', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _TFace // hashcode: 0x85FE430F (dec: -2046934257)
{
	struct _Face face;		// size=6, offset=0 //  hashcode: 0xBC252B12 (dec: -1138414830), parent name: '_TFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char attr;		// size=0, offset=6 //  hashcode: 0xD33E54AE (dec: -750889810), parent name: '_TFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	char sortPush;			// size=0, offset=7 //  hashcode: 0x3C4C893F (dec: 1011648831), parent name: '_TFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short normal;  // size=0, offset=8 //  hashcode: 0x89B85E8D (dec: -1984405875), parent name: '_TFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short textoff; // size=0, offset=10 //  hashcode: 0xA1C778A0 (dec: -1580762976), parent name: '_TFace', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _TVertex // hashcode: 0x0883ABD5 (dec: 142846933)
{
	struct _Vertex vertex; // size=6, offset=0 //  hashcode: 0x5411C965 (dec: 1410451813), parent name: '_TVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short rgb15;  // size=0, offset=6 //  hashcode: 0x6A65F2DF (dec: 1785066207), parent name: '_TVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;	  // size=0, offset=8 //  hashcode: 0x89534380 (dec: -1991031936), parent name: '_TVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;	  // size=0, offset=9 //  hashcode: 0x55EB9CA8 (dec: 1441504424), parent name: '_TVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;	  // size=0, offset=10 //  hashcode: 0x419FCC84 (dec: 1100991620), parent name: '_TVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code;	// size=0, offset=11 //  hashcode: 0x081CD78E (dec: 136107918), parent name: '_TVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EventAliasCommandStruct // hashcode: 0xB6EF2AF6 (dec: -1225839882)
{
	struct _Instance *hostInstance; // size=0, offset=0 //  hashcode: 0x95780CB0 (dec: -1787294544), parent name: 'EventAliasCommandStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	short newanim;					// size=0, offset=4 //  hashcode: 0x062156E0 (dec: 102848224), parent name: 'EventAliasCommandStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	short newframe;					// size=0, offset=6 //  hashcode: 0x6E942D47 (dec: 1855204679), parent name: 'EventAliasCommandStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	short interpframes;				// size=0, offset=8 //  hashcode: 0xD8B030B7 (dec: -659541833), parent name: 'EventAliasCommandStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	short speed;					// size=0, offset=10 //  hashcode: 0x2EF91381 (dec: 788075393), parent name: 'EventAliasCommandStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct Intro // hashcode: 0x796E766D (dec: 2037282413)
{
	char name[16];					   // size=16, offset=0 //  hashcode: 0xC2754532 (dec: -1032501966), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	long intronum;					   // size=0, offset=16 //  hashcode: 0xA96E7D71 (dec: -1452376719), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	long UniqueID;					   // size=0, offset=20 //  hashcode: 0x7B82EEBB (dec: 2072178363), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation;		   // size=8, offset=24 //  hashcode: 0x5F5A2464 (dec: 1599743076), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position;		   // size=6, offset=32 //  hashcode: 0x580491CB (dec: 1476694475), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxRad;					   // size=0, offset=38 //  hashcode: 0x007C5445 (dec: 8148037), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxRadSq;					   // size=0, offset=40 //  hashcode: 0x75B72979 (dec: 1974937977), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;						   // size=0, offset=44 //  hashcode: 0x8CFD65F2 (dec: -1929550350), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;						   // size=0, offset=48 //  hashcode: 0xF903CCE0 (dec: -117191456), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance;		   // size=616, offset=52 //  hashcode: 0xB1B1DF29 (dec: -1313743063), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *multiSpline;   // size=0, offset=56 //  hashcode: 0x07975918 (dec: 127359256), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *dsignal;					   // size=0, offset=60 //  hashcode: 0x91743A47 (dec: -1854653881), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short specturalLightGroup;		   // size=0, offset=64 //  hashcode: 0x2D1DD0FE (dec: 756928766), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short meshColor;				   // size=0, offset=66 //  hashcode: 0xA3A9A752 (dec: -1549162670), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position spectralPosition; // size=6, offset=68 //  hashcode: 0x6D5DB4B4 (dec: 1834857652), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short spad;						   // size=0, offset=74 //  hashcode: 0x292681F7 (dec: 690389495), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Terrain // hashcode: 0x5D541B4E (dec: 1565793102)
{
	short UnitChangeFlags;				 // size=0, offset=0 //  hashcode: 0x0B08990E (dec: 185112846), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	short spad;							 // size=0, offset=2 //  hashcode: 0x950AFF28 (dec: -1794441432), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	long lpad2;							 // size=0, offset=4 //  hashcode: 0xB4F2EDC0 (dec: -1259147840), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numIntros;						 // size=0, offset=8 //  hashcode: 0xCB1FC486 (dec: -887110522), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Intro *introList;			 // size=76, offset=12 //  hashcode: 0x70B2B76E (dec: 1890760558), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numVertices;					 // size=0, offset=16 //  hashcode: 0xBE68AD4D (dec: -1100436147), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numFaces;						 // size=0, offset=20 //  hashcode: 0x7A8DFBFF (dec: 2056125439), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numNormals;					 // size=0, offset=24 //  hashcode: 0x4BF4B848 (dec: 1274329160), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TVertex *vertexList;		 // size=12, offset=28 //  hashcode: 0x31755B3F (dec: 829774655), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *faceList;			 // size=12, offset=32 //  hashcode: 0xB57A4B90 (dec: -1250276464), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Normal *normalList;			 // size=8, offset=36 //  hashcode: 0x435B3ED6 (dec: 1130053334), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DrMoveAniTex *aniList;		 // size=8, offset=40 //  hashcode: 0xF9F89AB4 (dec: -101147980), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	long pad;							 // size=0, offset=44 //  hashcode: 0x2794AE3A (dec: 664055354), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *StreamUnits;					 // size=0, offset=48 //  hashcode: 0x86156EE7 (dec: -2045415705), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct TextureFT3 *StartTextureList; // size=12, offset=52 //  hashcode: 0xDFDA72D1 (dec: -539331887), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct TextureFT3 *EndTextureList;   // size=12, offset=56 //  hashcode: 0xA8C81A5C (dec: -1463281060), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MorphVertex *MorphDiffList;  // size=14, offset=60 //  hashcode: 0xEB791D80 (dec: -344384128), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MorphColor *MorphColorList;  // size=2, offset=64 //  hashcode: 0x43B6C45F (dec: 1136051295), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numBSPTrees;					 // size=0, offset=68 //  hashcode: 0xF1E1DFD1 (dec: -236855343), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct BSPTree *BSPTreeArray;		 // size=36, offset=72 //  hashcode: 0xBE28E1C4 (dec: -1104617020), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *morphNormalIdx;				 // size=0, offset=76 //  hashcode: 0xD7B3EF24 (dec: -676073692), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *signals;		 // size=904, offset=80 //  hashcode: 0x35619AA6 (dec: 895589030), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _InstancePool // hashcode: 0xC591AB92 (dec: -980309102)
{
	long nextInstanceID;		   // size=0, offset=0 //  hashcode: 0x422FE033 (dec: 1110433843), parent name: '_InstancePool', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numFreeInstances;		   // size=0, offset=4 //  hashcode: 0x0FA0249B (dec: 262153371), parent name: '_InstancePool', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance instance[62]; // size=38192, offset=8 //  hashcode: 0xE86D66D3 (dec: -395483437), parent name: '_InstancePool', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *first_free;  // size=616, offset=38200 //  hashcode: 0x1B13C44F (dec: 454280271), parent name: '_InstancePool', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _InstanceList // hashcode: 0x7594B1C7 (dec: 1972679111)
{
	long numInstances;			// size=0, offset=0 //  hashcode: 0x21FD3B1F (dec: 570243871), parent name: '_InstanceList', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *first;	// size=616, offset=4 //  hashcode: 0x20982907 (dec: 546842887), parent name: '_InstanceList', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _InstancePool *pool; // size=38204, offset=8 //  hashcode: 0x8C8C76FB (dec: -1936951557), parent name: '_InstanceList', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType group[32];  // size=256, offset=12 //  hashcode: 0x52503FB5 (dec: 1380990901), parent name: '_InstanceList', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _ObjectTracker // hashcode: 0xFE4678BF (dec: -28936001)
{
	char name[16];		   // size=16, offset=0 //  hashcode: 0xDA8A6108 (dec: -628465400), parent name: '_ObjectTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=76, offset=16 //  hashcode: 0x31DF6E1A (dec: 836726298), parent name: '_ObjectTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short objectStatus;	// size=0, offset=20 //  hashcode: 0x9355A5CE (dec: -1823103538), parent name: '_ObjectTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numInUse;		   // size=0, offset=22 //  hashcode: 0xEF2F7994 (dec: -282101356), parent name: '_ObjectTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *vramBlock;	   // size=0, offset=24 //  hashcode: 0xD2986C96 (dec: -761762666), parent name: '_ObjectTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numObjectsUsing;  // size=0, offset=28 //  hashcode: 0xBB715EF1 (dec: -1150198031), parent name: '_ObjectTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char objectsUsing[7];  // size=7, offset=29 //  hashcode: 0x6DA2B8E6 (dec: 1839380710), parent name: '_ObjectTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BoundingBox // hashcode: 0x2183782B (dec: 562264107)
{
	short minX; // size=0, offset=0 //  hashcode: 0x10EFDC3C (dec: 284154940), parent name: '_BoundingBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minY; // size=0, offset=2 //  hashcode: 0xCD05DC81 (dec: -855253887), parent name: '_BoundingBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minZ; // size=0, offset=4 //  hashcode: 0xE20BE7A6 (dec: -502536282), parent name: '_BoundingBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxX; // size=0, offset=6 //  hashcode: 0xE90F98F4 (dec: -384853772), parent name: '_BoundingBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxY; // size=0, offset=8 //  hashcode: 0x79938292 (dec: 2039710354), parent name: '_BoundingBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxZ; // size=0, offset=10 //  hashcode: 0xB6C99CB2 (dec: -1228301134), parent name: '_BoundingBox', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CDLight // hashcode: 0xD90757B8 (dec: -653830216)
{
	struct NodeType node;  // size=8, offset=0 //  hashcode: 0xCE1EB76E (dec: -836847762), parent name: 'CDLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r;	   // size=0, offset=8 //  hashcode: 0xD6DF80B9 (dec: -689995591), parent name: 'CDLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;	   // size=0, offset=9 //  hashcode: 0x00FF516E (dec: 16732526), parent name: 'CDLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;	   // size=0, offset=10 //  hashcode: 0xEA975FB7 (dec: -359178313), parent name: 'CDLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;   // size=0, offset=11 //  hashcode: 0x9C721215 (dec: -1670245867), parent name: 'CDLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Sphere sphere; // size=12, offset=12 //  hashcode: 0x54A5342D (dec: 1420112941), parent name: 'CDLight', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BSPNode // hashcode: 0x60C20F69 (dec: 1623330665)
{
	struct _Sphere_noSq sphere;			// size=8, offset=0 //  hashcode: 0xBAC2A12B (dec: -1161649877), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	short a;							// size=0, offset=8 //  hashcode: 0xF3C59F98 (dec: -205152360), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	short b;							// size=0, offset=10 //  hashcode: 0xA2D863BE (dec: -1562876994), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	short c;							// size=0, offset=12 //  hashcode: 0x9FBB8919 (dec: -1615099623), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;						// size=0, offset=14 //  hashcode: 0x6808269B (dec: 1745364635), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	long d;								// size=0, offset=16 //  hashcode: 0x365C5DBE (dec: 912022974), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *front;						// size=0, offset=20 //  hashcode: 0x481B194F (dec: 1209735503), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *back;							// size=0, offset=24 //  hashcode: 0x7DB3B4E7 (dec: 2108929255), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Sphere_noSq spectralSphere; // size=8, offset=28 //  hashcode: 0x07390564 (dec: 121177444), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	short front_spectral_error;			// size=0, offset=36 //  hashcode: 0xD7F8AF74 (dec: -671568012), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	short back_spectral_error;			// size=0, offset=38 //  hashcode: 0x5A7B2876 (dec: 1518020726), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	short front_material_error;			// size=0, offset=40 //  hashcode: 0x30A887E7 (dec: 816351207), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	short back_material_error;			// size=0, offset=42 //  hashcode: 0x31DBBFDB (dec: 836485083), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BSPLeaf // hashcode: 0xB2C1AC71 (dec: -1295930255)
{
	struct _Sphere_noSq sphere;			// size=8, offset=0 //  hashcode: 0x3010FA6B (dec: 806419051), parent name: '_BSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *faceList;			// size=12, offset=8 //  hashcode: 0xEE63CD00 (dec: -295449344), parent name: '_BSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numFaces;						// size=0, offset=12 //  hashcode: 0xD5419252 (dec: -717122990), parent name: '_BSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;						// size=0, offset=14 //  hashcode: 0xB8183EC0 (dec: -1206370624), parent name: '_BSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BoundingBox box;			// size=12, offset=16 //  hashcode: 0x6CEF6C69 (dec: 1827630185), parent name: '_BSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BoundingBox spectralBox;	// size=12, offset=28 //  hashcode: 0xD6142920 (dec: -703321824), parent name: '_BSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Sphere_noSq spectralSphere; // size=8, offset=40 //  hashcode: 0xCFE97895 (dec: -806782827), parent name: '_BSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MorphVertex // hashcode: 0xAAB8DABE (dec: -1430725954)
{
	short x;	  // size=0, offset=0 //  hashcode: 0x238413F3 (dec: 595858419), parent name: '_MorphVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	  // size=0, offset=2 //  hashcode: 0xCF4775EF (dec: -817400337), parent name: '_MorphVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;	  // size=0, offset=4 //  hashcode: 0xE320E1CB (dec: -484384309), parent name: '_MorphVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vindex; // size=0, offset=6 //  hashcode: 0xEC131B3E (dec: -334292162), parent name: '_MorphVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short hx;	 // size=0, offset=8 //  hashcode: 0xA8EBCA8F (dec: -1460942193), parent name: '_MorphVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short hy;	 // size=0, offset=10 //  hashcode: 0xF284CD2F (dec: -226177745), parent name: '_MorphVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short hz;	 // size=0, offset=12 //  hashcode: 0x912B81F3 (dec: -1859419661), parent name: '_MorphVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MorphColor // hashcode: 0xA6BA0326 (dec: -1497758938)
{
	short morphColor15; // size=0, offset=0 //  hashcode: 0x785DA197 (dec: 2019402135), parent name: '_MorphColor', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct Level // hashcode: 0x012B0198 (dec: 19595672)
{
	struct _Terrain *terrain;						 // size=84, offset=0 //  hashcode: 0x20D0F548 (dec: 550565192), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LightList *lightList;					 // size=12, offset=4 //  hashcode: 0x73C27F07 (dec: 1942126343), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numVMObjects;								 // size=0, offset=8 //  hashcode: 0x8BFE056C (dec: -1946286740), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _VMObject *vmobjectList;					 // size=60, offset=12 //  hashcode: 0xD6CF9197 (dec: -691039849), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numSpotLights;								 // size=0, offset=16 //  hashcode: 0x0A4A64C2 (dec: 172647618), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SpotLight *spotLightList;				 // size=40, offset=20 //  hashcode: 0x4D9B61A1 (dec: 1302028705), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numPointLights;							 // size=0, offset=24 //  hashcode: 0xDFF8F236 (dec: -537333194), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PointLight *pointLightList;				 // size=24, offset=28 //  hashcode: 0xAD7AC183 (dec: -1384463997), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numSpotSpecturalLights;					 // size=0, offset=32 //  hashcode: 0xF6D5857C (dec: -153778820), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SpotLight *spotSpecturalLightList;		 // size=40, offset=36 //  hashcode: 0x0E8B661D (dec: 244016669), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numPointSpecturalLights;					 // size=0, offset=40 //  hashcode: 0x79F5BC8A (dec: 2046147722), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PointLight *pointSpecturalLightList;		 // size=24, offset=44 //  hashcode: 0xBA3A3ED1 (dec: -1170587951), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numBGObjects;								 // size=0, offset=48 //  hashcode: 0x1551FC7F (dec: 357694591), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BGObject *bgObjectList;					 // size=24, offset=52 //  hashcode: 0xDCFD4D2A (dec: -587379414), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long waterZLevel;								 // size=0, offset=56 //  hashcode: 0x3E96367F (dec: 1050031743), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char backColorR;						 // size=0, offset=60 //  hashcode: 0x9DEFAA09 (dec: -1645237751), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char backColorG;						 // size=0, offset=61 //  hashcode: 0x47DE997D (dec: 1205770621), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char backColorB;						 // size=0, offset=62 //  hashcode: 0x671D6186 (dec: 1729978758), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char cpad1;							 // size=0, offset=63 //  hashcode: 0x8D5F8636 (dec: -1923119562), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char specturalColorR;					 // size=0, offset=64 //  hashcode: 0xE9BAB588 (dec: -373639800), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char specturalColorG;					 // size=0, offset=65 //  hashcode: 0x55EF1D0F (dec: 1441733903), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char specturalColorB;					 // size=0, offset=66 //  hashcode: 0x7588A244 (dec: 1971888708), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char cpad2;							 // size=0, offset=67 //  hashcode: 0xA17E2B36 (dec: -1585566922), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short fogFar;							 // size=0, offset=68 //  hashcode: 0x8793FC5D (dec: -2020344739), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short fogNear;							 // size=0, offset=70 //  hashcode: 0xA1C2D875 (dec: -1581066123), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short spectralFogFar;					 // size=0, offset=72 //  hashcode: 0x0353B049 (dec: 55816265), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short spectralFogNear;					 // size=0, offset=74 //  hashcode: 0xFBBB881A (dec: -71596006), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short waterFogFar;						 // size=0, offset=76 //  hashcode: 0xB109F8C1 (dec: -1324746559), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short waterFogNear;					 // size=0, offset=78 //  hashcode: 0x74E84A76 (dec: 1961380470), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long depthQBlendStart;							 // size=0, offset=80 //  hashcode: 0x5F9ACD11 (dec: 1603980561), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LightList *spectrallightList;			 // size=12, offset=84 //  hashcode: 0xDFEC81F3 (dec: -538148365), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numCameras;								 // size=0, offset=88 //  hashcode: 0xEC398DC4 (dec: -331772476), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *cameraList;								 // size=0, offset=92 //  hashcode: 0x4AB9BAE1 (dec: 1253685985), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long bspPlaneError;								 // size=0, offset=96 //  hashcode: 0xFA877C1D (dec: -91784163), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numVGroups;								 // size=0, offset=100 //  hashcode: 0xBC44B950 (dec: -1136346800), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _VGroup *vGroupList;						 // size=12, offset=104 //  hashcode: 0xB60A3BB4 (dec: -1240843340), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long deathZ;									 // size=0, offset=108 //  hashcode: 0x0963F7A5 (dec: 157546405), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;										 // size=0, offset=112 //  hashcode: 0xB584207B (dec: -1249632133), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *startSignal;				 // size=904, offset=116 //  hashcode: 0xF4A00A8A (dec: -190838134), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numIntros;									 // size=0, offset=120 //  hashcode: 0x5ED2BA04 (dec: 1590868484), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Intro *introList;						 // size=76, offset=124 //  hashcode: 0xD52388D0 (dec: -719091504), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DrMoveAniTex *bgAniList;					 // size=8, offset=128 //  hashcode: 0xF725CCB6 (dec: -148517706), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numHotSpots;								 // size=0, offset=132 //  hashcode: 0x351C612B (dec: 891052331), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HotSpot *hotSpotList;					 // size=8, offset=136 //  hashcode: 0xB3DC79E1 (dec: -1277396511), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *objectNameList;							 // size=0, offset=140 //  hashcode: 0xE1DB60FB (dec: -505716485), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long depthQFogStart;							 // size=0, offset=144 //  hashcode: 0x9AE3D729 (dec: -1696344279), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long morphLastStep;								 // size=0, offset=148 //  hashcode: 0xC35D3CD9 (dec: -1017299751), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *worldName;								 // size=0, offset=152 //  hashcode: 0xAD0BF68A (dec: -1391724918), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct VramSize vramSize;						 // size=8, offset=156 //  hashcode: 0x553894F9 (dec: 1429771513), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short holdFogFar;						 // size=0, offset=164 //  hashcode: 0x7F4E96CD (dec: 2135856845), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short holdFogNear;						 // size=0, offset=166 //  hashcode: 0x0D70999D (dec: 225483165), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numberEnemyUnits;							 // size=0, offset=168 //  hashcode: 0xAD4D69E8 (dec: -1387435544), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	char **enemyUnitsNames;							 // size=0, offset=172 //  hashcode: 0xFB96904A (dec: -74018742), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long **timesSignalList;							 // size=0, offset=176 //  hashcode: 0x4C9BCBCD (dec: 1285278669), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *spectralSignal;			 // size=904, offset=180 //  hashcode: 0xE709EBB5 (dec: -418780235), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *materialSignal;			 // size=904, offset=184 //  hashcode: 0x6FFEC2D2 (dec: 1878966994), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *startUnitLoadedSignal;		 // size=904, offset=188 //  hashcode: 0x8A5ACFB8 (dec: -1973760072), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *startUnitMainSignal;		 // size=904, offset=192 //  hashcode: 0xA9E87DAA (dec: -1444381270), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *startGoingIntoWaterSignal;  // size=904, offset=196 //  hashcode: 0x31016BBF (dec: 822176703), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *startGoingOutOfWaterSignal; // size=904, offset=200 //  hashcode: 0x37077710 (dec: 923236112), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long unitFlags;									 // size=0, offset=204 //  hashcode: 0x9081B794 (dec: -1870547052), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *SignalListStart;			 // size=904, offset=208 //  hashcode: 0xD3EC85DC (dec: -739473956), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *SignalListEnd;				 // size=904, offset=212 //  hashcode: 0xF9B37150 (dec: -105680560), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numBSPLeaves;								 // size=0, offset=216 //  hashcode: 0x9E876AA6 (dec: -1635292506), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct EventPointers *PuzzleInstances;			 // size=0, offset=220 //  hashcode: 0xAC11F995 (dec: -1408108139), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long NumberOfPlanMarkers;						 // size=0, offset=224 //  hashcode: 0x3539FD2D (dec: 892992813), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _PlanMkr *PlanMarkerList;				 // size=8, offset=228 //  hashcode: 0x7D8D32C8 (dec: 2106405576), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long NumberOfSFXMarkers;						 // size=0, offset=232 //  hashcode: 0x12E7384B (dec: 317143115), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SFXMkr *SFXMarkerList;					 // size=36, offset=236 //  hashcode: 0x6131D268 (dec: 1630655080), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long versionNumber;					 // size=0, offset=240 //  hashcode: 0x1CD00287 (dec: 483394183), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *dynamicMusicName;							 // size=0, offset=244 //  hashcode: 0xA636B923 (dec: -1506363101), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamUnitID;								 // size=0, offset=248 //  hashcode: 0x46B8847E (dec: 1186497662), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct TClassAttr tClassAttr[16];				 // size=64, offset=252 //  hashcode: 0x5BB2A8AA (dec: 1538435242), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	short TODLighting[4][3];						 // size=24, offset=316 //  hashcode: 0xE0A3FF49 (dec: -526123191), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char TODbackColor[4][3];				 // size=12, offset=340 //  hashcode: 0x81BD54B6 (dec: -2118298442), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short TODfogNearFar[4][2];				 // size=16, offset=352 //  hashcode: 0xFFDEF18D (dec: -2166387), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	short TODRedScale;								 // size=0, offset=368 //  hashcode: 0xB8579D52 (dec: -1202217646), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	short TODGrnScale;								 // size=0, offset=370 //  hashcode: 0x7FBA8576 (dec: 2142930294), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	short TODBluScale;								 // size=0, offset=372 //  hashcode: 0x813C1AB7 (dec: -2126767433), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	short TODfogNear;								 // size=0, offset=374 //  hashcode: 0x84575141 (dec: -2074652351), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	short TODfogFar;								 // size=0, offset=376 //  hashcode: 0x1340DAC3 (dec: 323017411), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	short short_pad;								 // size=0, offset=378 //  hashcode: 0x38F60ACD (dec: 955648717), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char TODbackColorR;					 // size=0, offset=380 //  hashcode: 0x666BE11F (dec: 1718346015), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char TODbackColorG;					 // size=0, offset=381 //  hashcode: 0x79B8B09D (dec: 2042146973), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char TODbackColorB;					 // size=0, offset=382 //  hashcode: 0x18DFFC08 (dec: 417332232), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char cpad3;							 // size=0, offset=383 //  hashcode: 0x4F399C1C (dec: 1329175580), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LightGroup *razielLightGroup;			 // size=64, offset=384 //  hashcode: 0x4591579D (dec: 1167153053), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LightGroup *razielSpectralLightGroup;	 // size=64, offset=388 //  hashcode: 0xDBFDF20A (dec: -604114422), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _SavedCinematic // hashcode: 0x1E29151B (dec: 506008859)
{
	struct _Position position;			  // size=6, offset=0 //  hashcode: 0x73B9AD10 (dec: 1941548304), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position focusPoint;		  // size=6, offset=6 //  hashcode: 0xB7AD97A7 (dec: -1213360217), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position base;				  // size=6, offset=12 //  hashcode: 0xC8422881 (dec: -935188351), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position targetPos;			  // size=6, offset=18 //  hashcode: 0x4164D05D (dec: 1097125981), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position targetFocusPoint;	// size=6, offset=24 //  hashcode: 0xD276C055 (dec: -763969451), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position targetBase;		  // size=6, offset=30 //  hashcode: 0xD334350D (dec: -751553267), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation baseRot;			  // size=8, offset=36 //  hashcode: 0x1B65F18B (dec: 459665803), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation focusRotation;		  // size=8, offset=44 //  hashcode: 0x6823EBE7 (dec: 1747184615), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation targetFocusRotation; // size=8, offset=52 //  hashcode: 0x0310EEE0 (dec: 51441376), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	short focusDistance;				  // size=0, offset=60 //  hashcode: 0xF609D123 (dec: -167128797), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	short targetFocusDistance;			  // size=0, offset=62 //  hashcode: 0x7A099078 (dec: 2047447160), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector focusPointVel;		  // size=8, offset=64 //  hashcode: 0x6207E444 (dec: 1644684356), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector focusPointAccl;		  // size=8, offset=72 //  hashcode: 0x72615266 (dec: 1918980710), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector baseVel;			  // size=8, offset=80 //  hashcode: 0x63F93494 (dec: 1677276308), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector baseAccl;			  // size=8, offset=88 //  hashcode: 0xE37A8BE9 (dec: -478508055), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxVel;						  // size=0, offset=96 //  hashcode: 0x1DB96136 (dec: 498688310), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *posSpline;		  // size=0, offset=100 //  hashcode: 0x721B558C (dec: 1914393996), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline;	 // size=0, offset=104 //  hashcode: 0x7B10388D (dec: 2064660621), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Level *level;				  // size=0, offset=108 //  hashcode: 0x8D5ACA7B (dec: -1923429765), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSPTree // hashcode: 0x17800192 (dec: 394264978)
{
	struct _BSPNode *bspRoot;		  // size=44, offset=0 //  hashcode: 0xA143BC7A (dec: -1589396358), parent name: 'BSPTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BSPLeaf *startLeaves;	 // size=48, offset=4 //  hashcode: 0x3B4AFA26 (dec: 994769446), parent name: 'BSPTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BSPLeaf *endLeaves;		  // size=48, offset=8 //  hashcode: 0x16C6CE8D (dec: 382127757), parent name: 'BSPTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position globalOffset;	// size=6, offset=12 //  hashcode: 0xFCAA6A3E (dec: -55940546), parent name: 'BSPTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;					  // size=0, offset=18 //  hashcode: 0x2BE6C8EF (dec: 736545007), parent name: 'BSPTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position localOffset;	 // size=6, offset=20 //  hashcode: 0x3DCFF4CF (dec: 1037038799), parent name: 'BSPTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ID;						  // size=0, offset=26 //  hashcode: 0xCA22BB51 (dec: -903693487), parent name: 'BSPTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	long splineID;					  // size=0, offset=28 //  hashcode: 0x6E9A6CB1 (dec: 1855614129), parent name: 'BSPTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instanceSpline; // size=616, offset=32 //  hashcode: 0xFECE5A33 (dec: -20030925), parent name: 'BSPTree', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LightGroup // hashcode: 0xBB5FF847 (dec: -1151338425)
{
	struct MATRIX lightMatrix; // size=32, offset=0 //  hashcode: 0x13930C8D (dec: 328404109), parent name: 'LightGroup', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX colorMatrix; // size=32, offset=32 //  hashcode: 0xF798E7DA (dec: -140974118), parent name: 'LightGroup', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LightList // hashcode: 0xC8448BB7 (dec: -935031881)
{
	struct CVECTOR ambient;			   // size=4, offset=0 //  hashcode: 0x8F106EC3 (dec: -1894748477), parent name: 'LightList', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numLightGroups;			   // size=0, offset=4 //  hashcode: 0x08D77FC0 (dec: 148340672), parent name: 'LightList', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LightGroup *lightGroupList; // size=64, offset=8 //  hashcode: 0x59BD23DD (dec: 1505567709), parent name: 'LightList', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PointLight // hashcode: 0xFEFDD2F2 (dec: -16919822)
{
	struct NodeType node;	  // size=8, offset=0 //  hashcode: 0xD7310D4F (dec: -684651185), parent name: 'PointLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r;		   // size=0, offset=8 //  hashcode: 0x72F36FB8 (dec: 1928556472), parent name: 'PointLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;		   // size=0, offset=9 //  hashcode: 0xD8A2C658 (dec: -660421032), parent name: 'PointLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;		   // size=0, offset=10 //  hashcode: 0x84A26CC4 (dec: -2069730108), parent name: 'PointLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;	   // size=0, offset=11 //  hashcode: 0x637E399B (dec: 1669216667), parent name: 'PointLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position; // size=6, offset=12 //  hashcode: 0x2C8CCB48 (dec: 747424584), parent name: 'PointLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	short radius;			   // size=0, offset=18 //  hashcode: 0xBF963819 (dec: -1080674279), parent name: 'PointLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	long radiusSquared;		   // size=0, offset=20 //  hashcode: 0xAFEA42E7 (dec: -1343601945), parent name: 'PointLight', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SpotLight // hashcode: 0xEF8B4C2E (dec: -276083666)
{
	struct NodeType node;		// size=8, offset=0 //  hashcode: 0x23129B83 (dec: 588422019), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r;			// size=0, offset=8 //  hashcode: 0x684970CA (dec: 1749643466), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;			// size=0, offset=9 //  hashcode: 0x7C4D73BD (dec: 2085450685), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;			// size=0, offset=10 //  hashcode: 0x42818A1D (dec: 1115785757), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;		// size=0, offset=11 //  hashcode: 0xC1456019 (dec: -1052418023), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position centroid;  // size=6, offset=12 //  hashcode: 0xB76C7E5B (dec: -1217626533), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	short radius;				// size=0, offset=18 //  hashcode: 0x2B82412D (dec: 729956653), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	long radiusSquared;			// size=0, offset=20 //  hashcode: 0xA24F0B01 (dec: -1571878143), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position;  // size=6, offset=24 //  hashcode: 0xCE23C8B1 (dec: -836515663), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position direction; // size=6, offset=30 //  hashcode: 0xBE36806C (dec: -1103724436), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cosFalloffAngle;		// size=0, offset=36 //  hashcode: 0xDBC14BA3 (dec: -608089181), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	short attenuationScale;		// size=0, offset=38 //  hashcode: 0xEE480CD1 (dec: -297268015), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LightInfo // hashcode: 0x2A95530E (dec: 714429198)
{
	long numPointLights;				  // size=0, offset=0 //  hashcode: 0xDC1B4D6B (dec: -602190485), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PointLight pointLightPool[32]; // size=768, offset=4 //  hashcode: 0xEF8899CD (dec: -276260403), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType usedPointLightList;   // size=8, offset=772 //  hashcode: 0x019A44AE (dec: 26887342), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType freePointLightList;   // size=8, offset=780 //  hashcode: 0x458B8326 (dec: 1166770982), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType activePointLightList; // size=8, offset=788 //  hashcode: 0xECB0B5A0 (dec: -323963488), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numSpotLights;					  // size=0, offset=796 //  hashcode: 0xD0D8B487 (dec: -791104377), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SpotLight spotLightPool[8];	// size=320, offset=800 //  hashcode: 0x3AD66BE1 (dec: 987130849), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType usedSpotLightList;	// size=8, offset=1120 //  hashcode: 0xE84038B0 (dec: -398444368), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType freeSpotLightList;	// size=8, offset=1128 //  hashcode: 0xD967C6DE (dec: -647510306), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType activeSpotLightList;  // size=8, offset=1136 //  hashcode: 0x88D898DC (dec: -1999071012), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numSavedColors;				  // size=0, offset=1144 //  hashcode: 0xB805D728 (dec: -1207576792), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _VMOffset // hashcode: 0x680AC445 (dec: 1745536069)
{
	short dx; // size=0, offset=0 //  hashcode: 0x5505881F (dec: 1426425887), parent name: '_VMOffset', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dy; // size=0, offset=2 //  hashcode: 0xE6A62D1E (dec: -425317090), parent name: '_VMOffset', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dz; // size=0, offset=4 //  hashcode: 0x58057201 (dec: 1476751873), parent name: '_VMOffset', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _VMColorOffset // hashcode: 0xFD3FB530 (dec: -46156496)
{
	char dr; // size=0, offset=0 //  hashcode: 0xDFD0113A (dec: -540012230), parent name: '_VMColorOffset', parent hashcode: 0xFFFFFFFF (dec: -1)
	char dg; // size=0, offset=1 //  hashcode: 0x8D92E713 (dec: -1919752429), parent name: '_VMColorOffset', parent hashcode: 0xFFFFFFFF (dec: -1)
	char db; // size=0, offset=2 //  hashcode: 0xDE4E850E (dec: -565279474), parent name: '_VMColorOffset', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _VMInterpolated // hashcode: 0x3A40B5C0 (dec: 977319360)
{
	short tvIdx;	// size=0, offset=0 //  hashcode: 0x35437F10 (dec: 893615888), parent name: '_VMInterpolated', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startIdx; // size=0, offset=2 //  hashcode: 0x6C5D1F98 (dec: 1818042264), parent name: '_VMInterpolated', parent hashcode: 0xFFFFFFFF (dec: -1)
	short endIdx;   // size=0, offset=4 //  hashcode: 0x994C86FA (dec: -1723037958), parent name: '_VMInterpolated', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;		// size=0, offset=6 //  hashcode: 0xA3F349E3 (dec: -1544336925), parent name: '_VMInterpolated', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLAYER_108fake // Hashcode: 0xCAC73339 (dec: -892914887)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct _VMOffsetTable // hashcode: 0xE4A13881 (dec: -459196287)
{
	long numVMOffsets;			  // size=0, offset=0 //  hashcode: 0xDB72177E (dec: -613279874), parent name: '_VMOffsetTable', parent hashcode: 0xFFFFFFFF (dec: -1)
	union PLAYER_108fake offsets; // size=6, offset=4 //  hashcode: 0x190FAAA4 (dec: 420457124), parent name: '_VMOffsetTable', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _VMObject // hashcode: 0x436E75EB (dec: 1131312619)
{
	unsigned short flags;						// size=0, offset=0 //  hashcode: 0xB184C3C4 (dec: -1316699196), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short bspIdx;								// size=0, offset=2 //  hashcode: 0x4669C93F (dec: 1181337919), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short materialIdx;							// size=0, offset=4 //  hashcode: 0x96DC66D9 (dec: -1763940647), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short spectralIdx;							// size=0, offset=6 //  hashcode: 0x7082EF29 (dec: 1887629097), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short currentIdx;							// size=0, offset=8 //  hashcode: 0xA76916F3 (dec: -1486285069), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeScale;							// size=0, offset=10 //  hashcode: 0xC88B2745 (dec: -930404539), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;									// size=0, offset=12 //  hashcode: 0x570A83D5 (dec: 1460306901), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position;					// size=6, offset=16 //  hashcode: 0x5C194B47 (dec: 1545161543), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short radius;								// size=0, offset=22 //  hashcode: 0xBB5F2233 (dec: -1151393229), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long radiusSquared;							// size=0, offset=24 //  hashcode: 0x27D209EB (dec: 668076523), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numVMOffsetTables;						// size=0, offset=28 //  hashcode: 0xA4BC0D5F (dec: -1531179681), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _VMOffsetTable **vmoffsetTableList;  // size=12, offset=32 //  hashcode: 0xB6341789 (dec: -1238100087), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _VMOffsetTable *curVMOffsetTable;	// size=12, offset=36 //  hashcode: 0xABCA43BA (dec: -1412807750), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numVMVertices;							// size=0, offset=40 //  hashcode: 0xDF2CC9C1 (dec: -550712895), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *vmvertexList;							// size=0, offset=44 //  hashcode: 0x8971902B (dec: -1989046229), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numVMInterpolated;						// size=0, offset=48 //  hashcode: 0xC1422E3D (dec: -1052627395), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _VMInterpolated *vminterpolatedList; // size=8, offset=52 //  hashcode: 0xD2BE065F (dec: -759298465), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *name;									// size=0, offset=56 //  hashcode: 0x27312B41 (dec: 657533761), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _VGroup // hashcode: 0x4421FB39 (dec: 1143077689)
{
	long id;					  // size=0, offset=0 //  hashcode: 0x5699E95F (dec: 1452927327), parent name: '_VGroup', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numVertices;			  // size=0, offset=4 //  hashcode: 0xF2F62F3B (dec: -218747077), parent name: '_VGroup', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TVertex **vertexList; // size=12, offset=8 //  hashcode: 0x6BCA02A7 (dec: 1808401063), parent name: '_VGroup', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _HotSpot // hashcode: 0x6EC4F776 (dec: 1858402166)
{
	short x;  // size=0, offset=0 //  hashcode: 0x201A4C22 (dec: 538594338), parent name: '_HotSpot', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;  // size=0, offset=2 //  hashcode: 0x896CC5A0 (dec: -1989360224), parent name: '_HotSpot', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;  // size=0, offset=4 //  hashcode: 0x3B2B945D (dec: 992711773), parent name: '_HotSpot', parent hashcode: 0xFFFFFFFF (dec: -1)
	short id; // size=0, offset=6 //  hashcode: 0x7172621E (dec: 1903321630), parent name: '_HotSpot', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _PlanMkr // hashcode: 0xBC0DD043 (dec: -1139945405)
{
	struct _Position pos; // size=6, offset=0 //  hashcode: 0x66433A5B (dec: 1715681883), parent name: '_PlanMkr', parent hashcode: 0xFFFFFFFF (dec: -1)
	short id;			  // size=0, offset=6 //  hashcode: 0x27F924A6 (dec: 670639270), parent name: '_PlanMkr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _SFXMkr // hashcode: 0x74BB4848 (dec: 1958430792)
{
	unsigned char *soundData;		// size=0, offset=0 //  hashcode: 0xE6DD4FA6 (dec: -421703770), parent name: '_SFXMkr', parent hashcode: 0xFFFFFFFF (dec: -1)
	long uniqueID;					// size=0, offset=4 //  hashcode: 0x80069EB9 (dec: -2147049799), parent name: '_SFXMkr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SoundInstance sfxTbl[4]; // size=12, offset=8 //  hashcode: 0x58EAFA43 (dec: 1491794499), parent name: '_SFXMkr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position pos;			// size=6, offset=20 //  hashcode: 0x98E94F3D (dec: -1729540291), parent name: '_SFXMkr', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;						// size=0, offset=26 //  hashcode: 0xADB9F7C6 (dec: -1380321338), parent name: '_SFXMkr', parent hashcode: 0xFFFFFFFF (dec: -1)
	long livesInOnePlace;			// size=0, offset=28 //  hashcode: 0xFC53279B (dec: -61659237), parent name: '_SFXMkr', parent hashcode: 0xFFFFFFFF (dec: -1)
	long inSpectral;				// size=0, offset=32 //  hashcode: 0x862E6B84 (dec: -2043778172), parent name: '_SFXMkr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TClassAttr // hashcode: 0x4DC02369 (dec: 1304437609)
{
	short flags;		  // size=0, offset=0 //  hashcode: 0x96D0AA12 (dec: -1764709870), parent name: 'TClassAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short sound; // size=0, offset=2 //  hashcode: 0xE1AEBF5E (dec: -508641442), parent name: 'TClassAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _ColorType // hashcode: 0x440E837C (dec: 1141801852)
{
	unsigned char r;	// size=0, offset=0 //  hashcode: 0x30691506 (dec: 812193030), parent name: '_ColorType', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;	// size=0, offset=1 //  hashcode: 0x3AC221E1 (dec: 985801185), parent name: '_ColorType', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;	// size=0, offset=2 //  hashcode: 0xDD40F703 (dec: -582945021), parent name: '_ColorType', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code; // size=0, offset=3 //  hashcode: 0x3106BA69 (dec: 822524521), parent name: '_ColorType', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _CameraCore_Type // hashcode: 0xD341D51C (dec: -750660324)
{
	struct _Position position;			// size=6, offset=0 //  hashcode: 0x04450A99 (dec: 71633561), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad1;							// size=0, offset=6 //  hashcode: 0xE3B0906D (dec: -474967955), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX vvNormalWorVecMat[2]; // size=64, offset=8 //  hashcode: 0x56099686 (dec: 1443468934), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long vvPlaneConsts[6];				// size=24, offset=72 //  hashcode: 0x60D06D16 (dec: 1624272150), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX *wcTransform;			// size=32, offset=96 //  hashcode: 0xE6A98993 (dec: -425096813), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long farPlane;						// size=0, offset=100 //  hashcode: 0x9590622C (dec: -1785699796), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long projDistance;					// size=0, offset=104 //  hashcode: 0x3A7BDE22 (dec: 981196322), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long nearPlane;						// size=0, offset=108 //  hashcode: 0x3E57CE29 (dec: 1045941801), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX *wcTransform2;		// size=32, offset=112 //  hashcode: 0x513E600B (dec: 1363042315), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX *cwTransform2;		// size=32, offset=116 //  hashcode: 0x5ABF4F26 (dec: 1522487078), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Normal viewVolumeNormal[5]; // size=40, offset=120 //  hashcode: 0xE4630ED0 (dec: -463270192), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	int leftX;							// size=0, offset=160 //  hashcode: 0x697AF9BC (dec: 1769667004), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	int rightX;							// size=0, offset=164 //  hashcode: 0x9DEC597F (dec: -1645454977), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	int topY;							// size=0, offset=168 //  hashcode: 0x23165E05 (dec: 588668421), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	int bottomY;						// size=0, offset=172 //  hashcode: 0xC95F735A (dec: -916491430), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation;			// size=8, offset=176 //  hashcode: 0x46EB939D (dec: 1189843869), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad2;							// size=0, offset=184 //  hashcode: 0x2393E6C9 (dec: 596895433), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector screenScale;		// size=8, offset=186 //  hashcode: 0x9C530D2A (dec: -1672278742), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad3;							// size=0, offset=194 //  hashcode: 0xCEF48FEB (dec: -822833173), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position debugPos;			// size=6, offset=196 //  hashcode: 0x3DBF60F3 (dec: 1035952371), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad4;							// size=0, offset=202 //  hashcode: 0x32BA2BF5 (dec: 851061749), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation debugRot;			// size=8, offset=204 //  hashcode: 0x48CEBAC9 (dec: 1221507785), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad5;							// size=0, offset=212 //  hashcode: 0x209ABA51 (dec: 547011153), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position nondebugPos;		// size=6, offset=214 //  hashcode: 0xB78E323C (dec: -1215417796), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad6;							// size=0, offset=220 //  hashcode: 0xF4FCF396 (dec: -184749162), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_110fake // hashcode: 0x26DB91B2 (dec: 651923890)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x99320550 (dec: -1724775088), parent name: 'PLAYER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xC4F79447 (dec: -990407609), parent name: 'PLAYER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x9F3F80D9 (dec: -1623228199), parent name: 'PLAYER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x2CEF3B9E (dec: 753875870), parent name: 'PLAYER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0xEFDF8765 (dec: -270563483), parent name: 'PLAYER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x417AF6B0 (dec: 1098577584), parent name: 'PLAYER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x539BF4EB (dec: 1402729707), parent name: 'PLAYER_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_111fake // hashcode: 0x21359924 (dec: 557160740)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x87957499 (dec: -2020248423), parent name: 'PLAYER_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x9F93CA01 (dec: -1617704447), parent name: 'PLAYER_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x15D1DB3B (dec: 366074683), parent name: 'PLAYER_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_112fake // hashcode: 0x651BC28F (dec: 1696318095)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x479361C2 (dec: 1200841154), parent name: 'PLAYER_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x8DD17CA1 (dec: -1915650911), parent name: 'PLAYER_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x292645D7 (dec: 690374103), parent name: 'PLAYER_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x6F4E0A3C (dec: 1867385404), parent name: 'PLAYER_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xBAF6792D (dec: -1158252243), parent name: 'PLAYER_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_113fake // hashcode: 0xFC9AA643 (dec: -56973757)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xC730E63F (dec: -953096641), parent name: 'PLAYER_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x8D6E095D (dec: -1922168483), parent name: 'PLAYER_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x86F6E187 (dec: -2030640761), parent name: 'PLAYER_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x5FE06914 (dec: 1608542484), parent name: 'PLAYER_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x86E0EABB (dec: -2032080197), parent name: 'PLAYER_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAYER_114fake // hashcode: 0x5A1E67AD (dec: 1511942061)
{
	struct PLAYER_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x92394F49 (dec: -1841737911), parent name: 'PLAYER_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PLAYER_111fake Idle;		 // size=20, offset=28 //  hashcode: 0x25ACC5D1 (dec: 632079825), parent name: 'PLAYER_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PLAYER_112fake Behind;	// size=28, offset=48 //  hashcode: 0x3DB6DC16 (dec: 1035394070), parent name: 'PLAYER_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PLAYER_113fake Follow;	// size=20, offset=76 //  hashcode: 0xCEDBCE3D (dec: -824455619), parent name: 'PLAYER_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SpuVolume // hashcode: 0x1BD13981 (dec: 466696577)
{
	short left;  // size=0, offset=0 //  hashcode: 0xFF38BD5D (dec: -13058723), parent name: 'SpuVolume', parent hashcode: 0xFFFFFFFF (dec: -1)
	short right; // size=0, offset=2 //  hashcode: 0xC2E190AA (dec: -1025404758), parent name: 'SpuVolume', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SpuVoiceAttr // hashcode: 0x819E0A50 (dec: -2120349104)
{
	unsigned long voice;		// size=0, offset=0 //  hashcode: 0xF2AD1C4A (dec: -223536054), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long mask;			// size=0, offset=4 //  hashcode: 0x7309BDC7 (dec: 1930018247), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SpuVolume volume;	// size=4, offset=8 //  hashcode: 0xC0ED7605 (dec: -1058179579), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SpuVolume volmode;   // size=4, offset=12 //  hashcode: 0x543F4075 (dec: 1413431413), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SpuVolume volumex;   // size=4, offset=16 //  hashcode: 0x976E4CC7 (dec: -1754379065), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pitch;		// size=0, offset=20 //  hashcode: 0x0C6AC648 (dec: 208324168), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short note;		// size=0, offset=22 //  hashcode: 0x6BB3224F (dec: 1806901839), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short sample_note; // size=0, offset=24 //  hashcode: 0x3F2F9006 (dec: 1060081670), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	short envx;					// size=0, offset=26 //  hashcode: 0xCB86849F (dec: -880376673), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long addr;			// size=0, offset=28 //  hashcode: 0x7CBA62EA (dec: 2092589802), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long loop_addr;	// size=0, offset=32 //  hashcode: 0xA7451591 (dec: -1488644719), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	long a_mode;				// size=0, offset=36 //  hashcode: 0xFB2F028C (dec: -80805236), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	long s_mode;				// size=0, offset=40 //  hashcode: 0x0AEB80C8 (dec: 183206088), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	long r_mode;				// size=0, offset=44 //  hashcode: 0x4F522FF5 (dec: 1330786293), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short ar;			// size=0, offset=48 //  hashcode: 0x4D0B8D70 (dec: 1292602736), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short dr;			// size=0, offset=50 //  hashcode: 0x297C02CC (dec: 695993036), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short sr;			// size=0, offset=52 //  hashcode: 0xC0565B50 (dec: -1068082352), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short rr;			// size=0, offset=54 //  hashcode: 0x8B1E7A24 (dec: -1960936924), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short sl;			// size=0, offset=56 //  hashcode: 0xE68344D9 (dec: -427604775), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short adsr1;		// size=0, offset=58 //  hashcode: 0x480B27FA (dec: 1208690682), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short adsr2;		// size=0, offset=60 //  hashcode: 0xF0BE2BED (dec: -255972371), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SpuExtAttr // hashcode: 0x58B0F474 (dec: 1487991924)
{
	struct SpuVolume volume; // size=4, offset=0 //  hashcode: 0x556AA871 (dec: 1433053297), parent name: 'SpuExtAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	long reverb;			 // size=0, offset=4 //  hashcode: 0xF47F6D0F (dec: -192975601), parent name: 'SpuExtAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	long mix;				 // size=0, offset=8 //  hashcode: 0xF3E0B3BF (dec: -203377729), parent name: 'SpuExtAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SpuStVoiceAttr // hashcode: 0xAFDFBA7E (dec: -1344292226)
{
	char status;			 // size=0, offset=0 //  hashcode: 0xCD9554BD (dec: -845851459), parent name: 'SpuStVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pad1;				 // size=0, offset=1 //  hashcode: 0x709A532D (dec: 1889162029), parent name: 'SpuStVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pad2;				 // size=0, offset=2 //  hashcode: 0xAB38E2C5 (dec: -1422335291), parent name: 'SpuStVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pad3;				 // size=0, offset=3 //  hashcode: 0x179C76A5 (dec: 396129957), parent name: 'SpuStVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	long last_size;			 // size=0, offset=4 //  hashcode: 0x751C1280 (dec: 1964774016), parent name: 'SpuStVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long buf_addr;  // size=0, offset=8 //  hashcode: 0x3D210012 (dec: 1025572882), parent name: 'SpuStVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long data_addr; // size=0, offset=12 //  hashcode: 0x6C032923 (dec: 1812146467), parent name: 'SpuStVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadSoundBankHdr // hashcode: 0x453DB83F (dec: 1161672767)
{
	unsigned long bankID;	 // size=0, offset=0 //  hashcode: 0x09B7DDBC (dec: 163044796), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long headerSize; // size=0, offset=4 //  hashcode: 0xFC55B636 (dec: -61491658), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	int bankVersion;		  // size=0, offset=8 //  hashcode: 0x8CF91365 (dec: -1929833627), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numPrograms;		  // size=0, offset=12 //  hashcode: 0x835962F3 (dec: -2091293965), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numTones;			  // size=0, offset=16 //  hashcode: 0x9063E1F5 (dec: -1872502283), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numWaves;			  // size=0, offset=20 //  hashcode: 0x60D1EF84 (dec: 1624371076), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numSequences;		  // size=0, offset=24 //  hashcode: 0xFF862253 (dec: -7986605), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numLabels;			  // size=0, offset=28 //  hashcode: 0x9D78B4EC (dec: -1653033748), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	int reverbMode;			  // size=0, offset=32 //  hashcode: 0x94C063E1 (dec: -1799330847), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	int reverbDepth;		  // size=0, offset=36 //  hashcode: 0x99F70189 (dec: -1711865463), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadProgramAtr // hashcode: 0x13FC0BEF (dec: 335285231)
{
	unsigned short numTones;   // size=0, offset=0 //  hashcode: 0xF3AC8930 (dec: -206796496), parent name: 'AadProgramAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short firstTone;  // size=0, offset=2 //  hashcode: 0x400CDE3D (dec: 1074585149), parent name: 'AadProgramAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char volume;	  // size=0, offset=4 //  hashcode: 0x63A47070 (dec: 1671721072), parent name: 'AadProgramAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char panPosition; // size=0, offset=5 //  hashcode: 0x2FF7BDC2 (dec: 804765122), parent name: 'AadProgramAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short unused;	 // size=0, offset=6 //  hashcode: 0x2F4A5097 (dec: 793399447), parent name: 'AadProgramAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadToneAtr // hashcode: 0x990CD685 (dec: -1727211899)
{
	unsigned char priority;		 // size=0, offset=0 //  hashcode: 0xB812E6B9 (dec: -1206720839), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char parentProgram; // size=0, offset=1 //  hashcode: 0xDD4F94DF (dec: -581987105), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char volume;		 // size=0, offset=2 //  hashcode: 0x29997F63 (dec: 697925475), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char panPosition;   // size=0, offset=3 //  hashcode: 0xADAA1BA4 (dec: -1381360732), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char centerNote;	// size=0, offset=4 //  hashcode: 0xB8624AFE (dec: -1201517826), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	char centerFine;			 // size=0, offset=5 //  hashcode: 0x8BFDCD9C (dec: -1946301028), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char minNote;		 // size=0, offset=6 //  hashcode: 0x11F84945 (dec: 301484357), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char maxNote;		 // size=0, offset=7 //  hashcode: 0x0CFD221F (dec: 217915935), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char mode;			 // size=0, offset=8 //  hashcode: 0x5090D81D (dec: 1351669789), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pitchBendMax;  // size=0, offset=9 //  hashcode: 0x527D0476 (dec: 1383924854), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short adsr1;		 // size=0, offset=10 //  hashcode: 0xA8E0E5CC (dec: -1461656116), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short adsr2;		 // size=0, offset=12 //  hashcode: 0x641F1D73 (dec: 1679760755), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	short waveIndex;			 // size=0, offset=14 //  hashcode: 0xE5228057 (dec: -450723753), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _AadDynSfxFileHdr // hashcode: 0xB9609773 (dec: -1184852109)
{
	unsigned long snfID;					  // size=0, offset=0 //  hashcode: 0x727AC2FA (dec: 1920647930), parent name: '_AadDynSfxFileHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short snfVersion;				  // size=0, offset=4 //  hashcode: 0x002E56D2 (dec: 3036882), parent name: '_AadDynSfxFileHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short uniqueID;				  // size=0, offset=6 //  hashcode: 0xD10C25E1 (dec: -787733023), parent name: '_AadDynSfxFileHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short handle;					  // size=0, offset=8 //  hashcode: 0x2B693BC1 (dec: 728316865), parent name: '_AadDynSfxFileHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short numSfxInFile;			  // size=0, offset=10 //  hashcode: 0xE81F0ACB (dec: -400618805), parent name: '_AadDynSfxFileHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _AadDynSfxFileHdr *prevDynSfxFile; // size=20, offset=12 //  hashcode: 0x4CD7BEFC (dec: 1289207548), parent name: '_AadDynSfxFileHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _AadDynSfxFileHdr *nextDynSfxFile; // size=20, offset=16 //  hashcode: 0x669E3D33 (dec: 1721646387), parent name: '_AadDynSfxFileHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadDynSfxAttr // hashcode: 0x20751E4B (dec: 544546379)
{
	unsigned short sfxID;		// size=0, offset=0 //  hashcode: 0xA54FF529 (dec: -1521486551), parent name: 'AadDynSfxAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short waveID;		// size=0, offset=2 //  hashcode: 0x81E5CE63 (dec: -2115645853), parent name: 'AadDynSfxAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadToneAtr toneAttr; // size=16, offset=4 //  hashcode: 0x7B508BAC (dec: 2068876204), parent name: 'AadDynSfxAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long waveSize;		// size=0, offset=20 //  hashcode: 0x4BABDE70 (dec: 1269554800), parent name: 'AadDynSfxAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadTempoCounter // hashcode: 0x15707CC0 (dec: 359693504)
{
	unsigned long currentTick;	 // size=0, offset=0 //  hashcode: 0x8F7DC901 (dec: -1887581951), parent name: 'AadTempoCounter', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long currentError;	// size=0, offset=4 //  hashcode: 0x70723E31 (dec: 1886535217), parent name: 'AadTempoCounter', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long tickTimeFixed;   // size=0, offset=8 //  hashcode: 0x13A30D9F (dec: 329452959), parent name: 'AadTempoCounter', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long errorPerUpdate;  // size=0, offset=12 //  hashcode: 0x47423E0A (dec: 1195523594), parent name: 'AadTempoCounter', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short ticksPerUpdate; // size=0, offset=16 //  hashcode: 0x898E7763 (dec: -1987152029), parent name: 'AadTempoCounter', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short ppqn;		   // size=0, offset=18 //  hashcode: 0xB2F1CAD1 (dec: -1292776751), parent name: 'AadTempoCounter', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long quarterNoteTime; // size=0, offset=20 //  hashcode: 0x3A4ABAAA (dec: 977975978), parent name: 'AadTempoCounter', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadSeqEvent // hashcode: 0x3E306185 (dec: 1043358085)
{
	unsigned long deltaTime;  // size=0, offset=0 //  hashcode: 0x10F5D4C2 (dec: 284546242), parent name: 'AadSeqEvent', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char track;	  // size=0, offset=4 //  hashcode: 0x8C892EBE (dec: -1937166658), parent name: 'AadSeqEvent', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char statusByte; // size=0, offset=5 //  hashcode: 0x7FC4B205 (dec: 2143597061), parent name: 'AadSeqEvent', parent hashcode: 0xFFFFFFFF (dec: -1)
	char dataByte[6];		  // size=6, offset=6 //  hashcode: 0xDF2C9C66 (dec: -550724506), parent name: 'AadSeqEvent', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _AadSequenceSlot // hashcode: 0xD7421DD6 (dec: -683532842)
{
	struct AadTempoCounter tempo;				 // size=24, offset=0 //  hashcode: 0xBE75829B (dec: -1099595109), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadSeqEvent eventQueue[4][16];		 // size=768, offset=24 //  hashcode: 0x663B795A (dec: 1715173722), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char eventIn[16];					 // size=16, offset=792 //  hashcode: 0xDBC0E4FE (dec: -608115458), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char eventOut[16];					 // size=16, offset=808 //  hashcode: 0xCFC0CAF7 (dec: -809448713), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char eventsInQueue[16];			 // size=16, offset=824 //  hashcode: 0x479BB3B3 (dec: 1201386419), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char(*sequencePosition[16]);		 // size=64, offset=840 //  hashcode: 0xE71D6B69 (dec: -417502359), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long lastEventExecutedTime[16];	 // size=64, offset=904 //  hashcode: 0xC498AD8B (dec: -996627061), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char runningStatus[16];			 // size=16, offset=968 //  hashcode: 0xB66C16BB (dec: -1234430277), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char trackFlags[16];				 // size=16, offset=984 //  hashcode: 0x466441AF (dec: 1180975535), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char(*loopSequencePosition[4][16]); // size=256, offset=1000 //  hashcode: 0x88E52EBE (dec: -1998246210), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char loopCurrentNestLevel[16];		 // size=16, offset=1256 //  hashcode: 0xCCD842CB (dec: -858242357), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char loopCounter[4][16];			 // size=64, offset=1272 //  hashcode: 0xF8737FEE (dec: -126648338), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _AadSequenceSlot *selectedSlotPtr;	// size=1488, offset=1336 //  hashcode: 0x03D1C0FA (dec: 64078074), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char selectedSlotNum;				 // size=0, offset=1340 //  hashcode: 0xA4D4F054 (dec: -1529548716), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char selectedChannel;				 // size=0, offset=1341 //  hashcode: 0x86BB5B7C (dec: -2034541700), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sequenceNumberAssigned;		 // size=0, offset=1342 //  hashcode: 0x8B72987E (dec: -1955424130), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char thisSlotNumber;				 // size=0, offset=1343 //  hashcode: 0x594404A5 (dec: 1497629861), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short status;						 // size=0, offset=1344 //  hashcode: 0x47214A2F (dec: 1193364015), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short channelMute;					 // size=0, offset=1346 //  hashcode: 0x5741AADB (dec: 1463921371), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short delayedMuteMode;				 // size=0, offset=1348 //  hashcode: 0x6448E84F (dec: 1682499663), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short delayedMuteCmds;				 // size=0, offset=1350 //  hashcode: 0xF6412225 (dec: -163503579), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short delayedUnMuteCmds;			 // size=0, offset=1352 //  hashcode: 0x56008C57 (dec: 1442876503), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short unused;						 // size=0, offset=1354 //  hashcode: 0x01607ED9 (dec: 23101145), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short enableSustainUpdate;			 // size=0, offset=1356 //  hashcode: 0x043D690B (dec: 71133451), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short ignoreTranspose;				 // size=0, offset=1358 //  hashcode: 0xB7113158 (dec: -1223610024), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char slotFlags;					 // size=0, offset=1360 //  hashcode: 0xF80B3D3E (dec: -133481154), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char slotID;						 // size=0, offset=1361 //  hashcode: 0x6106A32F (dec: 1627824943), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char slotVolume;					 // size=0, offset=1362 //  hashcode: 0x031CF4A7 (dec: 52229287), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char slotPan;						 // size=0, offset=1363 //  hashcode: 0xB2FF4622 (dec: -1291893214), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	int *masterVolPtr;							 // size=0, offset=1364 //  hashcode: 0x512CC372 (dec: 1361888114), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	int selectedDynamicBank;					 // size=0, offset=1368 //  hashcode: 0x40F02D5B (dec: 1089482075), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	int sequenceAssignedDynamicBank;			 // size=0, offset=1372 //  hashcode: 0xA42F0F60 (dec: -1540419744), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char currentDynamicBank[16];		 // size=16, offset=1376 //  hashcode: 0x8364B898 (dec: -2090551144), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pitchWheel[16];				 // size=32, offset=1392 //  hashcode: 0x8973675A (dec: -1988925606), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char currentProgram[16];			 // size=16, offset=1424 //  hashcode: 0xEF22FB55 (dec: -282920107), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char volume[16];					 // size=16, offset=1440 //  hashcode: 0x2B9A10EB (dec: 731517163), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char panPosition[16];				 // size=16, offset=1456 //  hashcode: 0x98C4B883 (dec: -1731938173), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	char transpose[16];							 // size=16, offset=1472 //  hashcode: 0x94FE096A (dec: -1795290774), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadSfxCommand // hashcode: 0xD8F832F6 (dec: -654822666)
{
	unsigned char statusByte;  // size=0, offset=0 //  hashcode: 0x36DCA4C6 (dec: 920429766), parent name: 'AadSfxCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char dataByte[3]; // size=3, offset=1 //  hashcode: 0x131BD9FC (dec: 320592380), parent name: 'AadSfxCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long ulongParam;  // size=0, offset=4 //  hashcode: 0x65AA49C3 (dec: 1705658819), parent name: 'AadSfxCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	short shortParam;		   // size=0, offset=8 //  hashcode: 0x313D0297 (dec: 826081943), parent name: 'AadSfxCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short unused;	 // size=0, offset=10 //  hashcode: 0xC1185BDA (dec: -1055368230), parent name: 'AadSfxCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadSfxSlot // hashcode: 0x6E655A78 (dec: 1852136056)
{
	struct AadSfxCommand commandQueue[32]; // size=384, offset=0 //  hashcode: 0x4F46A043 (dec: 1330028611), parent name: 'AadSfxSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char commandIn;			   // size=0, offset=384 //  hashcode: 0x69F30E0A (dec: 1777536522), parent name: 'AadSfxSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char commandOut;			   // size=0, offset=385 //  hashcode: 0xB5A554B2 (dec: -1247456078), parent name: 'AadSfxSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short commandsInQueue;		   // size=0, offset=386 //  hashcode: 0x5AFA4919 (dec: 1526352153), parent name: 'AadSfxSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short handleCounter;		   // size=0, offset=388 //  hashcode: 0xF14464B3 (dec: -247176013), parent name: 'AadSfxSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sfxVolume;			   // size=0, offset=390 //  hashcode: 0x54D7574F (dec: 1423398735), parent name: 'AadSfxSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sfxPan;				   // size=0, offset=391 //  hashcode: 0x3DDC4EE8 (dec: 1037848296), parent name: 'AadSfxSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadSynthVoice // hashcode: 0x12E02CA2 (dec: 316681378)
{
	unsigned long voiceMask;	   // size=0, offset=0 //  hashcode: 0xDCC4123A (dec: -591130054), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long handle;		   // size=0, offset=4 //  hashcode: 0x64780F9C (dec: 1685589916), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char voiceID;		   // size=0, offset=8 //  hashcode: 0x4086F9FB (dec: 1082587643), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char priority;		   // size=0, offset=9 //  hashcode: 0xD8DEDD66 (dec: -656482970), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char note;			   // size=0, offset=10 //  hashcode: 0x9060A2B1 (dec: -1872715087), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char unused;		   // size=0, offset=11 //  hashcode: 0xE9F05061 (dec: -370126751), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char program;		   // size=0, offset=12 //  hashcode: 0x7749D51A (dec: 2001327386), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char baseProg;		   // size=0, offset=13 //  hashcode: 0xBEDD9D70 (dec: -1092772496), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char volume;		   // size=0, offset=14 //  hashcode: 0xA167F72C (dec: -1587022036), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char updateVol;	   // size=0, offset=15 //  hashcode: 0x00F4C41F (dec: 16040991), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pan;			   // size=0, offset=16 //  hashcode: 0xE5B14075 (dec: -441368459), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char voiceNum;		   // size=0, offset=17 //  hashcode: 0x21197190 (dec: 555315600), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short flags;		   // size=0, offset=18 //  hashcode: 0xA363F1DA (dec: -1553731110), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadToneAtr *toneAtr;	// size=16, offset=20 //  hashcode: 0x49FE752B (dec: 1241412907), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadProgramAtr *progAtr; // size=8, offset=24 //  hashcode: 0xC5E67525 (dec: -974752475), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadDynamicLoadRequest // hashcode: 0xBC9D60B7 (dec: -1130536777)
{
	int type;		   // size=0, offset=0 //  hashcode: 0x50BED30B (dec: 1354683147), parent name: 'AadDynamicLoadRequest', parent hashcode: 0xFFFFFFFF (dec: -1)
	int handle;		   // size=0, offset=4 //  hashcode: 0x27A9F97A (dec: 665450874), parent name: 'AadDynamicLoadRequest', parent hashcode: 0xFFFFFFFF (dec: -1)
	long directoryID;  // size=0, offset=8 //  hashcode: 0xEC1D2F0C (dec: -333631732), parent name: 'AadDynamicLoadRequest', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;		   // size=0, offset=12 //  hashcode: 0x6ACDEFF2 (dec: 1791881202), parent name: 'AadDynamicLoadRequest', parent hashcode: 0xFFFFFFFF (dec: -1)
	char fileName[12]; // size=12, offset=16 //  hashcode: 0xE0F0CC8F (dec: -521089905), parent name: 'AadDynamicLoadRequest', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadDynamicBankLoadInfo // hashcode: 0x6A3AE9FB (dec: 1782245883)
{
	char sndFileName[32];		// size=32, offset=0 //  hashcode: 0x1CDB1D29 (dec: 484121897), parent name: 'AadDynamicBankLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	char smpFileName[32];		// size=32, offset=32 //  hashcode: 0x35875704 (dec: 898062084), parent name: 'AadDynamicBankLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int dynamicBankIndex;		// size=0, offset=64 //  hashcode: 0x47E2F608 (dec: 1206056456), parent name: 'AadDynamicBankLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int loadOption;				// size=0, offset=68 //  hashcode: 0xDA81DFA7 (dec: -629022809), parent name: 'AadDynamicBankLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*userCallbackProc)(); // size=0, offset=72 //  hashcode: 0x97655251 (dec: -1754967471), parent name: 'AadDynamicBankLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long sramDataSize; // size=0, offset=76 //  hashcode: 0x9A39BB6D (dec: -1707492499), parent name: 'AadDynamicBankLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long nextSramAddr; // size=0, offset=80 //  hashcode: 0x9E5B9C2D (dec: -1638163411), parent name: 'AadDynamicBankLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long flags;		// size=0, offset=84 //  hashcode: 0x3053F3E3 (dec: 810808291), parent name: 'AadDynamicBankLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadDynamicSfxLoadInfo // hashcode: 0xEDD41D4C (dec: -304865972)
{
	char snfFileName[40];			   // size=40, offset=0 //  hashcode: 0x9109B610 (dec: -1861634544), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	char smfFileName[40];			   // size=40, offset=40 //  hashcode: 0xC747B7DF (dec: -951601185), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int fileHandle;					   // size=0, offset=80 //  hashcode: 0x1CFCEF11 (dec: 486338321), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long directoryID;				   // size=0, offset=84 //  hashcode: 0x6AE5A115 (dec: 1793433877), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long loadFlags;					   // size=0, offset=88 //  hashcode: 0xEC30FBC5 (dec: -332334139), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;						   // size=0, offset=92 //  hashcode: 0x660C73C0 (dec: 1712092096), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int smfLoadingState;			   // size=0, offset=96 //  hashcode: 0x1F3DB6BB (dec: 524138171), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long bytesToLoad;		   // size=0, offset=100 //  hashcode: 0x2F2B68D3 (dec: 791374035), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numSfxToLoad;				   // size=0, offset=104 //  hashcode: 0xA601210F (dec: -1509875441), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int error;						   // size=0, offset=108 //  hashcode: 0x00FC95AC (dec: 16553388), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long waveTransferAddr;	// size=0, offset=112 //  hashcode: 0x4BA1390A (dec: 1268857098), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long totalSramUsed;	   // size=0, offset=116 //  hashcode: 0x65EADDD2 (dec: 1709891026), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _AadDynSfxFileHdr *snfFile; // size=20, offset=120 //  hashcode: 0x565A0AE1 (dec: 1448741601), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadDynSfxAttr attr;		   // size=24, offset=124 //  hashcode: 0xB81E0705 (dec: -1205991675), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadNewSramBlockDesc // hashcode: 0x4DF7A665 (dec: 1308075621)
{
	unsigned short waveID;   // size=0, offset=0 //  hashcode: 0xA81DBA6A (dec: -1474446742), parent name: 'AadNewSramBlockDesc', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short address;  // size=0, offset=2 //  hashcode: 0x7224FF9E (dec: 1915027358), parent name: 'AadNewSramBlockDesc', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short size;	 // size=0, offset=4 //  hashcode: 0x544CA169 (dec: 1414308201), parent name: 'AadNewSramBlockDesc', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char prevIndex; // size=0, offset=6 //  hashcode: 0x3C190D00 (dec: 1008274688), parent name: 'AadNewSramBlockDesc', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char nextIndex; // size=0, offset=7 //  hashcode: 0x08120358 (dec: 135398232), parent name: 'AadNewSramBlockDesc', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadLoadedSfxToneAttr // hashcode: 0xC1F66431 (dec: -1040817103)
{
	unsigned short referenceCount; // size=0, offset=0 //  hashcode: 0x5DB3CED7 (dec: 1572064983), parent name: 'AadLoadedSfxToneAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short waveID;		   // size=0, offset=2 //  hashcode: 0xA6197A5F (dec: -1508279713), parent name: 'AadLoadedSfxToneAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadToneAtr toneAttr;	// size=16, offset=4 //  hashcode: 0x79AD9507 (dec: 2041419015), parent name: 'AadLoadedSfxToneAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadLoadedSfxWaveAttr // hashcode: 0x3EFD9321 (dec: 1056805665)
{
	unsigned short referenceCount; // size=0, offset=0 //  hashcode: 0x961CC897 (dec: -1776498537), parent name: 'AadLoadedSfxWaveAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char unused;		   // size=0, offset=2 //  hashcode: 0x4418BAD1 (dec: 1142471377), parent name: 'AadLoadedSfxWaveAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sramHandle;	  // size=0, offset=3 //  hashcode: 0x06F91C7C (dec: 116989052), parent name: 'AadLoadedSfxWaveAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadSramDefragInfo // hashcode: 0xB08B77B9 (dec: -1333037127)
{
	int status;					// size=0, offset=0 //  hashcode: 0x76B51AB3 (dec: 1991580339), parent name: 'AadSramDefragInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char *fragBuffer;  // size=0, offset=4 //  hashcode: 0x691D9F50 (dec: 1763549008), parent name: 'AadSramDefragInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int masterListEntry;		// size=0, offset=8 //  hashcode: 0x6A591CB1 (dec: 1784224945), parent name: 'AadSramDefragInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int waveID;					// size=0, offset=12 //  hashcode: 0xABE4150A (dec: -1411115766), parent name: 'AadSramDefragInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long destSramAddr; // size=0, offset=16 //  hashcode: 0x24139D04 (dec: 605265156), parent name: 'AadSramDefragInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long srcSramAddr;  // size=0, offset=20 //  hashcode: 0x0D31F03A (dec: 221376570), parent name: 'AadSramDefragInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long moveSize;		// size=0, offset=24 //  hashcode: 0x86191719 (dec: -2045176039), parent name: 'AadSramDefragInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long readSize;		// size=0, offset=28 //  hashcode: 0x15E10429 (dec: 367068201), parent name: 'AadSramDefragInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadVolFader // hashcode: 0x053CCA3C (dec: 87870012)
{
	int volumeStep;					// size=0, offset=0 //  hashcode: 0x5DF62C65 (dec: 1576414309), parent name: 'AadVolFader', parent hashcode: 0xFFFFFFFF (dec: -1)
	int targetVolume;				// size=0, offset=4 //  hashcode: 0x480A10C6 (dec: 1208619206), parent name: 'AadVolFader', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*fadeCompleteCallback)(); // size=0, offset=8 //  hashcode: 0xE596D469 (dec: -443100055), parent name: 'AadVolFader', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MusicLoadCmd // hashcode: 0x575883B8 (dec: 1465418680)
{
	int type; // size=0, offset=0 //  hashcode: 0xFC15F2A2 (dec: -65670494), parent name: 'MusicLoadCmd', parent hashcode: 0xFFFFFFFF (dec: -1)
	int data; // size=0, offset=4 //  hashcode: 0xCB66475B (dec: -882489509), parent name: 'MusicLoadCmd', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct gSoundData // hashcode: 0x100090FC (dec: 268472572)
{
	unsigned long gMasterVol; // size=0, offset=0 //  hashcode: 0xE5F9D1AF (dec: -436612689), parent name: 'gSoundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long gMusicVol;  // size=0, offset=4 //  hashcode: 0x166AD6C8 (dec: 376100552), parent name: 'gSoundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long gSfxVol;	// size=0, offset=8 //  hashcode: 0x51870753 (dec: 1367803731), parent name: 'gSoundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long gVoiceVol;  // size=0, offset=12 //  hashcode: 0xCC6ABF25 (dec: -865419483), parent name: 'gSoundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char gSfxOn;			  // size=0, offset=16 //  hashcode: 0xDDC3CE78 (dec: -574370184), parent name: 'gSoundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char gMusicOn;			  // size=0, offset=17 //  hashcode: 0x5A3B45CC (dec: 1513833932), parent name: 'gSoundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char gVoiceOn;			  // size=0, offset=18 //  hashcode: 0x6611B269 (dec: 1712435817), parent name: 'gSoundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char soundsLoaded;		  // size=0, offset=19 //  hashcode: 0xAB545E1A (dec: -1420534246), parent name: 'gSoundData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GameTracker // hashcode: 0x4EB3EFC5 (dec: 1320415173)
{
	struct _GameData_Type gameData;		   // size=32, offset=0 //  hashcode: 0xFB1AACBA (dec: -82137926), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct menu_t *menu;				   // size=0, offset=32 //  hashcode: 0xCB3010C7 (dec: -886042425), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct memcard_t *memcard;			   // size=0, offset=36 //  hashcode: 0xEBCB1E02 (dec: -339010046), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Level *level;				   // size=392, offset=40 //  hashcode: 0x6913D826 (dec: 1762908198), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *playerInstance;	  // size=616, offset=44 //  hashcode: 0x5C10B034 (dec: 1544597556), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long drawPage;						   // size=0, offset=48 //  hashcode: 0xB51B4E5C (dec: -1256501668), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _InstanceList *instanceList;	// size=268, offset=52 //  hashcode: 0x69147538 (dec: 1762948408), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _InstancePool *instancePool;	// size=38204, offset=56 //  hashcode: 0xBD5FAA28 (dec: -1117803992), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _VertexPool *vertexPool;		   // size=6336, offset=60 //  hashcode: 0x8B4054A1 (dec: -1958718303), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _PrimPool *primPool;			   // size=96012, offset=64 //  hashcode: 0xB64AC98F (dec: -1236612721), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _ObjectTracker *GlobalObjects;  // size=36, offset=68 //  hashcode: 0x618FCE64 (dec: 1636814436), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long controlCommand[2][5];			   // size=40, offset=72 //  hashcode: 0xDC3F5BB3 (dec: -599827533), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long controlData[2][5];				   // size=40, offset=112 //  hashcode: 0xF84CC799 (dec: -129185895), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long overrideData[2][5];			   // size=40, offset=152 //  hashcode: 0xA67495E2 (dec: -1502308894), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long debugFlags;					   // size=0, offset=192 //  hashcode: 0x4E8E6534 (dec: 1317954868), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long debugFlags2;					   // size=0, offset=196 //  hashcode: 0xD7D25762 (dec: -674080926), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CVECTOR wipeColor;			   // size=4, offset=200 //  hashcode: 0x6E0C3FBF (dec: 1846296511), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short wipeTime;						   // size=0, offset=204 //  hashcode: 0xC7899393 (dec: -947285101), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxWipeTime;					   // size=0, offset=206 //  hashcode: 0xA3CF3BC7 (dec: -1546699833), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short wipeType;						   // size=0, offset=208 //  hashcode: 0x712767FB (dec: 1898407931), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numGSignals;					   // size=0, offset=210 //  hashcode: 0x180D2AAA (dec: 403516074), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void(*gSignal[16]);					   // size=64, offset=212 //  hashcode: 0xF9C3CFDE (dec: -104607778), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LightInfo *lightInfo;		   // size=1148, offset=276 //  hashcode: 0x4BEF4E3E (dec: 1273974334), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *reqDisp;						   // size=0, offset=280 //  hashcode: 0xCF65BCE8 (dec: -815416088), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long *drawTimerReturn;				   // size=0, offset=284 //  hashcode: 0x0B34ECC9 (dec: 188017865), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long usecsStartDraw;				   // size=0, offset=288 //  hashcode: 0xEF31F650 (dec: -281938352), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *disp;							   // size=0, offset=292 //  hashcode: 0x96EF737B (dec: -1762692229), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long displayFrameCount;	   // size=0, offset=296 //  hashcode: 0x6F32F7C8 (dec: 1865611208), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long frameCount;			   // size=0, offset=300 //  hashcode: 0x43442FB2 (dec: 1128542130), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long fps30Count;			   // size=0, offset=304 //  hashcode: 0xECF3353C (dec: -319605444), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long vblFrames;			   // size=0, offset=308 //  hashcode: 0x43EC0657 (dec: 1139541591), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long vblCount;				   // size=0, offset=312 //  hashcode: 0x4B91F163 (dec: 1267855715), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numMatrices;					   // size=0, offset=316 //  hashcode: 0x45231FD8 (dec: 1159929816), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long gameFlags;						   // size=0, offset=320 //  hashcode: 0x7268FE50 (dec: 1919483472), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamFlags;					   // size=0, offset=324 //  hashcode: 0xA0418619 (dec: -1606318567), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *drawNonAnimatedSegmentFunc;	  // size=0, offset=328 //  hashcode: 0xADFB7E10 (dec: -1376027120), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *drawAnimatedModelFunc;		   // size=0, offset=332 //  hashcode: 0xF540634C (dec: -180329652), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *drawDisplayPolytopeListFunc;	 // size=0, offset=336 //  hashcode: 0xB8F6E327 (dec: -1191779545), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *drawBgFunc;					   // size=0, offset=340 //  hashcode: 0xA1513DD8 (dec: -1588511272), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Level *mainDrawUnit;			   // size=392, offset=344 //  hashcode: 0x3E159911 (dec: 1041602833), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char baseAreaName[16];				   // size=16, offset=348 //  hashcode: 0x1E6ACC6F (dec: 510315631), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short levelDone;					   // size=0, offset=364 //  hashcode: 0xD31DA260 (dec: -753032608), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short levelChange;					   // size=0, offset=366 //  hashcode: 0x4CC31879 (dec: 1287854201), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short hideBG;						   // size=0, offset=368 //  hashcode: 0x25430AFB (dec: 625150715), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short gameMode;						   // size=0, offset=370 //  hashcode: 0x01375BDE (dec: 20405214), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long currentHotSpot;				   // size=0, offset=372 //  hashcode: 0x08449614 (dec: 138712596), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long StreamUnitID;					   // size=0, offset=376 //  hashcode: 0x6DB03675 (dec: 1840264821), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short SwitchToNewStreamUnit;		   // size=0, offset=380 //  hashcode: 0x520882B5 (dec: 1376289461), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short SwitchToNewWarpIndex;			   // size=0, offset=382 //  hashcode: 0x9CC8E654 (dec: -1664555436), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char S_baseAreaName[16];			   // size=16, offset=384 //  hashcode: 0x8DC972C8 (dec: -1916177720), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short toSignal;						   // size=0, offset=400 //  hashcode: 0x5014E082 (dec: 1343545474), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fromSignal;					   // size=0, offset=402 //  hashcode: 0x997B71C4 (dec: -1719963196), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char LastSignal;					   // size=0, offset=404 //  hashcode: 0xE50E01BB (dec: -452066885), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short StreamNormalA;				   // size=0, offset=406 //  hashcode: 0x941546B7 (dec: -1810544969), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short StreamNormalB;				   // size=0, offset=408 //  hashcode: 0x34B085B1 (dec: 883983793), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short StreamNormalC;				   // size=0, offset=410 //  hashcode: 0x39F03389 (dec: 972043145), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long StreamNormalD;					   // size=0, offset=412 //  hashcode: 0xE0637F00 (dec: -530350336), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long moveRazielToStreamID;			   // size=0, offset=416 //  hashcode: 0xEAB12346 (dec: -357489850), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _ColorType animObjLine;		   // size=4, offset=420 //  hashcode: 0x4014052B (dec: 1075053867), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _ColorType animObjShade;		   // size=4, offset=424 //  hashcode: 0x24B438FD (dec: 615790845), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxIntroFXTime;				   // size=0, offset=428 //  hashcode: 0x1496A3BD (dec: 345416637), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct gSoundData sound;			   // size=20, offset=432 //  hashcode: 0x74DE62D3 (dec: 1960731347), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short controllerMode;				   // size=0, offset=452 //  hashcode: 0xD4076C70 (dec: -737710992), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char plan_collide_override;   // size=0, offset=454 //  hashcode: 0x4E84FC8F (dec: 1317338255), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char cheatMode;			   // size=0, offset=455 //  hashcode: 0x2ECD1517 (dec: 785192215), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char currentLvl;					   // size=0, offset=456 //  hashcode: 0x3C8861C6 (dec: 1015570886), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char lastLvl;						   // size=0, offset=457 //  hashcode: 0xD320064F (dec: -752875953), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *introFX;				   // size=76, offset=460 //  hashcode: 0x55AF4BF0 (dec: 1437551600), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Intro *introFXIntro;			   // size=76, offset=464 //  hashcode: 0xD95C7B56 (dec: -648250538), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long **drawOT;				   // size=0, offset=468 //  hashcode: 0x5960E6E6 (dec: 1499522790), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long **dispOT;				   // size=0, offset=472 //  hashcode: 0x8DDF4171 (dec: -1914748559), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct P_TAG *savedOTStart;			   // size=8, offset=476 //  hashcode: 0x19505A0C (dec: 424696332), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct P_TAG *savedOTEnd;			   // size=8, offset=480 //  hashcode: 0x00BF756E (dec: 12547438), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long introWaitTime;					   // size=0, offset=484 //  hashcode: 0x0940B7E4 (dec: 155236324), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long mirrorZPush;					   // size=0, offset=488 //  hashcode: 0x41215F86 (dec: 1092706182), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long defVVRemoveDist;				   // size=0, offset=492 //  hashcode: 0xBCE12403 (dec: -1126095869), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long defRemoveDist;					   // size=0, offset=496 //  hashcode: 0x7F468407 (dec: 2135327751), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position forcedStartPosition;  // size=6, offset=500 //  hashcode: 0xC0B42A58 (dec: -1061934504), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short hudCollDisplay;				   // size=0, offset=506 //  hashcode: 0xDDF3B673 (dec: -571230605), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long primMemUsed;					   // size=0, offset=508 //  hashcode: 0xE0BEE552 (dec: -524360366), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long cheatTimerCount;				   // size=0, offset=512 //  hashcode: 0x45C2C200 (dec: 1170391552), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long playerCheatFlags;				   // size=0, offset=516 //  hashcode: 0xA33DDE98 (dec: -1556226408), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long savedPlayerCameraMode;			   // size=0, offset=520 //  hashcode: 0x42B6D10C (dec: 1119277324), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long debugDrawFlags;				   // size=0, offset=524 //  hashcode: 0x3969E52D (dec: 963241261), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *planningPool;					   // size=0, offset=528 //  hashcode: 0x9572765F (dec: -1787660705), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *enemyPlanPool;				   // size=0, offset=532 //  hashcode: 0x6BF07F6B (dec: 1810923371), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char block_collide_override;  // size=0, offset=536 //  hashcode: 0x5A773944 (dec: 1517762884), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char raziel_collide_override; // size=0, offset=537 //  hashcode: 0x5AC22135 (dec: 1522671925), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeOfDay;					   // size=0, offset=538 //  hashcode: 0x44229214 (dec: 1143116308), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long decoupleGame;					   // size=0, offset=540 //  hashcode: 0xA4A03A99 (dec: -1533003111), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long multGameTime;					   // size=0, offset=544 //  hashcode: 0xD2FADDC0 (dec: -755311168), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short spectral_fadeValue;			   // size=0, offset=548 //  hashcode: 0x8D33CA3B (dec: -1925985733), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short material_fadeValue;			   // size=0, offset=550 //  hashcode: 0x4053D11B (dec: 1079234843), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long drawTime;				   // size=0, offset=552 //  hashcode: 0x5AFC7D06 (dec: 1526496518), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long currentTime;			   // size=0, offset=556 //  hashcode: 0x73FEBC36 (dec: 1946074166), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long currentMaterialTime;	 // size=0, offset=560 //  hashcode: 0xB94ECD64 (dec: -1186017948), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long currentSpectralTime;	 // size=0, offset=564 //  hashcode: 0x2FCC0915 (dec: 801900821), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long currentTimeOfDayTime;	// size=0, offset=568 //  hashcode: 0xE531BFA3 (dec: -449724509), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long lastLoopTime;			   // size=0, offset=572 //  hashcode: 0x75EDA14A (dec: 1978507594), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long timeMult;				   // size=0, offset=576 //  hashcode: 0x9BA6BB33 (dec: -1683571917), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long globalTimeMult;		   // size=0, offset=580 //  hashcode: 0x1AE9ABE9 (dec: 451521513), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long spectralTimeMult;		   // size=0, offset=584 //  hashcode: 0xC8B619A9 (dec: -927589975), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long materialTimeMult;		   // size=0, offset=588 //  hashcode: 0xF1562EA7 (dec: -246010201), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long currentTicks;			   // size=0, offset=592 //  hashcode: 0xD0AD73C3 (dec: -793939005), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long totalTime;			   // size=0, offset=596 //  hashcode: 0x719137F7 (dec: 1905342455), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long idleTime;				   // size=0, offset=600 //  hashcode: 0xBAEBF3C3 (dec: -1158941757), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long visibleInstances;				   // size=0, offset=604 //  hashcode: 0x522F59BB (dec: 1378834875), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	int gameFramePassed;				   // size=0, offset=608 //  hashcode: 0xD6D03AA2 (dec: -690996574), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long timeSinceLastGameFrame;  // size=0, offset=612 //  hashcode: 0x046A0E92 (dec: 74059410), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frameRateLock;					   // size=0, offset=616 //  hashcode: 0x86FDE68A (dec: -2030180726), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short frameRate24fps;				   // size=0, offset=620 //  hashcode: 0x4C573F2D (dec: 1280786221), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char monster_collide_override;		   // size=0, offset=622 //  hashcode: 0xE2991E45 (dec: -493281723), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pad;							   // size=0, offset=623 //  hashcode: 0x17FF5B97 (dec: 402611095), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct Spline // hashcode: 0xA7B8D53F (dec: -1481059009)
{
	struct SplineKey *key; // size=32, offset=0 //  hashcode: 0xEA9B1E6B (dec: -358932885), parent name: 'Spline', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numkeys;		   // size=0, offset=4 //  hashcode: 0x305A2DA2 (dec: 811216290), parent name: 'Spline', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;	// size=0, offset=6 //  hashcode: 0xE422B7A9 (dec: -467486807), parent name: 'Spline', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;   // size=0, offset=7 //  hashcode: 0xD2B27167 (dec: -760057497), parent name: 'Spline', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct vecS // hashcode: 0xEADB8F3A (dec: -354709702)
{
	short x; // size=0, offset=0 //  hashcode: 0xE1D712EE (dec: -505998610), parent name: 'vecS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0x354AEC4E (dec: 894102606), parent name: 'vecS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z; // size=0, offset=4 //  hashcode: 0xE27947F8 (dec: -495368200), parent name: 'vecS', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct vecL // hashcode: 0x7575CB14 (dec: 1970653972)
{
	long x; // size=0, offset=0 //  hashcode: 0xB1A05BF0 (dec: -1314890768), parent name: 'vecL', parent hashcode: 0xFFFFFFFF (dec: -1)
	long y; // size=0, offset=4 //  hashcode: 0xD8547182 (dec: -665554558), parent name: 'vecL', parent hashcode: 0xFFFFFFFF (dec: -1)
	long z; // size=0, offset=8 //  hashcode: 0x0BC29D80 (dec: 197303680), parent name: 'vecL', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SplineRotKey // hashcode: 0xD2E3A87E (dec: -756832130)
{
	short count;		   // size=0, offset=0 //  hashcode: 0x4B2B0B6A (dec: 1261112170), parent name: 'SplineRotKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type q; // size=8, offset=2 //  hashcode: 0xBDD47E35 (dec: -1110147531), parent name: 'SplineRotKey', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RSpline // hashcode: 0xD9C500BD (dec: -641400643)
{
	struct SplineRotKey *key; // size=10, offset=0 //  hashcode: 0xD28D6E10 (dec: -762483184), parent name: 'RSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numkeys;			  // size=0, offset=4 //  hashcode: 0x7E35A815 (dec: 2117445653), parent name: 'RSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;		  // size=0, offset=6 //  hashcode: 0xDC28CC49 (dec: -601306039), parent name: 'RSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;	  // size=0, offset=7 //  hashcode: 0x858FC28C (dec: -2054176116), parent name: 'RSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SplineKey // hashcode: 0x5D3D994D (dec: 1564318029)
{
	short count;	   // size=0, offset=0 //  hashcode: 0x069A044D (dec: 110756941), parent name: 'SplineKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct vecS point; // size=6, offset=2 //  hashcode: 0x62EC022F (dec: 1659634223), parent name: 'SplineKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct vecL dd;	// size=12, offset=8 //  hashcode: 0xBBD5FE2F (dec: -1143603665), parent name: 'SplineKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct vecL ds;	// size=12, offset=20 //  hashcode: 0x7B14706A (dec: 2064937066), parent name: 'SplineKey', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SplineDef // hashcode: 0x04DD5459 (dec: 81613913)
{
	short currkey;			  // size=0, offset=0 //  hashcode: 0x6FA7FC69 (dec: 1873280105), parent name: 'SplineDef', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short denomFlag; // size=0, offset=2 //  hashcode: 0x260F27CE (dec: 638527438), parent name: 'SplineDef', parent hashcode: 0xFFFFFFFF (dec: -1)
	long fracCurr;			  // size=0, offset=4 //  hashcode: 0x015C7A29 (dec: 22837801), parent name: 'SplineDef', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _HVertex // hashcode: 0xC488A83D (dec: -997676995)
{
	short x;	  // size=0, offset=0 //  hashcode: 0xB9F1587A (dec: -1175365510), parent name: '_HVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	  // size=0, offset=2 //  hashcode: 0x4429A526 (dec: 1143579942), parent name: '_HVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;	  // size=0, offset=4 //  hashcode: 0x0F7CAAEA (dec: 259828458), parent name: '_HVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short normal; // size=0, offset=6 //  hashcode: 0x614ADC74 (dec: 1632296052), parent name: '_HVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	long pad;	 // size=0, offset=8 //  hashcode: 0xB54B0E9B (dec: -1253372261), parent name: '_HVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MONAPI_Regenerator // hashcode: 0x37E0AA1B (dec: 937470491)
{
	unsigned long regenTime; // size=0, offset=0 //  hashcode: 0xEC2FF312 (dec: -332401902), parent name: '_MONAPI_Regenerator', parent hashcode: 0xFFFFFFFF (dec: -1)
	short introUniqueID;	 // size=0, offset=4 //  hashcode: 0xAABB76F1 (dec: -1430554895), parent name: '_MONAPI_Regenerator', parent hashcode: 0xFFFFFFFF (dec: -1)
	short streamUnitID;		 // size=0, offset=6 //  hashcode: 0xC80E291B (dec: -938596069), parent name: '_MONAPI_Regenerator', parent hashcode: 0xFFFFFFFF (dec: -1)
};

enum DEBUG_LINE_TYPE // Hashcode: 0x03F31324 (dec: 66261796)
{
	DEBUG_LINE_TYPE_BIT = 0,
	DEBUG_LINE_TYPE_LONG = 1,
	DEBUG_LINE_TYPE_ACTION = 2,
	DEBUG_LINE_TYPE_ACTION_WITH_LINE = 3,
	DEBUG_LINE_TYPE_MENU = 4,
	DEBUG_LINE_TYPE_ENDLIST = 5,
	DEBUG_LINE_TYPE_FORMAT = 6,
	DEBUG_LINE_TYPE_INFO = 7,
};

struct __Event // hashcode: 0xBC16D673 (dec: -1139353997)
{
	int ID;   // size=0, offset=0 //  hashcode: 0x0BF58C0F (dec: 200641551), parent name: '__Event', parent hashcode: 0xFFFFFFFF (dec: -1)
	int Data; // size=0, offset=4 //  hashcode: 0x0EE1962C (dec: 249665068), parent name: '__Event', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __MessageQueue // hashcode: 0x473062B5 (dec: 1194353333)
{
	int Head;				  // size=0, offset=0 //  hashcode: 0x8162EC2D (dec: -2124223443), parent name: '__MessageQueue', parent hashcode: 0xFFFFFFFF (dec: -1)
	int Tail;				  // size=0, offset=4 //  hashcode: 0x005AB14A (dec: 5943626), parent name: '__MessageQueue', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __Event Queue[16]; // size=128, offset=8 //  hashcode: 0x137F4350 (dec: 327107408), parent name: '__MessageQueue', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __State // hashcode: 0xA27CC1F7 (dec: -1568882185)
{
	void (*Process)();			 // size=0, offset=0 //  hashcode: 0xC4F743A7 (dec: -990428249), parent name: '__State', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __MessageQueue Event; // size=136, offset=4 //  hashcode: 0xD1DE0AE6 (dec: -773977370), parent name: '__State', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __MessageQueue Defer; // size=136, offset=140 //  hashcode: 0x6F4D44FB (dec: 1867334907), parent name: '__State', parent hashcode: 0xFFFFFFFF (dec: -1)
	int Data1;					 // size=0, offset=276 //  hashcode: 0x50C407D0 (dec: 1355024336), parent name: '__State', parent hashcode: 0xFFFFFFFF (dec: -1)
	int Data2;					 // size=0, offset=280 //  hashcode: 0x0535811A (dec: 87392538), parent name: '__State', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLAYER_208fake // Hashcode: 0xD87F8A52 (dec: -662730158)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

typedef struct MATRIX MATRIX;

typedef struct VECTOR VECTOR;

typedef struct SVECTOR SVECTOR;

typedef struct CVECTOR CVECTOR;

typedef struct DVECTOR DVECTOR;

typedef struct RVECTOR RVECTOR;

typedef struct CRVECTOR3 CRVECTOR3;

typedef struct CRVECTOR4 CRVECTOR4;

typedef struct RECT RECT;

typedef struct DR_ENV DR_ENV;

typedef struct P_TAG P_TAG;

typedef struct CdlLOC CdlLOC;

typedef struct LightInstance LightInstance;

typedef struct _GameTrackerASMData_Type GameTrackerASMData;

typedef struct _GameData_Type GameData;

typedef struct NodeType NodeType;

typedef struct TextureFT3 TextureFT3;

typedef struct TextureMT3 TextureMT3;

typedef struct AniTexInfo AniTexInfo;

typedef struct AniTex AniTex;

typedef struct DrMoveAniTexSrcInfo DrMoveAniTexSrcInfo;

typedef struct DrMoveAniTexDestInfo DrMoveAniTexDestInfo;

typedef struct DrMoveAniTex DrMoveAniTex;

typedef struct MemHeader MemHeader;

typedef enum _G2Bool_Enum G2Bool;

typedef struct _G2SVector3_Type G2SVector3;

typedef struct _G2LVector3_Type G2LVector3;

typedef struct _G2Matrix_Type G2Matrix;

typedef struct _G2Quat_Type G2Quat;

typedef struct _G2AnimQuatInfo_Type G2AnimQuatInfo;

typedef struct _G2AnimAlphaTable_Type G2AnimAlphaTable;

typedef struct _G2AnimInterpStateBlock_Type G2AnimInterpStateBlock;

typedef struct _G2AnimInterpInfo_Type G2AnimInterpInfo;

typedef struct _G2AnimChanStatus_Type G2AnimChanStatus;

typedef struct _G2AnimChanStatusBlock_Type G2AnimChanStatusBlock;

typedef struct _G2AnimFxHeader_Type G2AnimFxHeader;

typedef struct _G2AnimKeylist_Type G2AnimKeylist;

typedef struct _G2AnimSection_Type G2AnimSection;

typedef struct _G2Anim_Type G2Anim;

typedef struct _SVector SVector;

typedef struct _SVectorNoPad SVectorNoPad;

typedef struct MATRIX Transform;

typedef struct _Position Position;

typedef struct _Rotation Rotation;

typedef struct _Normal Normal;

typedef struct _PlaneConstants PlaneConstants;

typedef struct _Vertex Vertex;

typedef struct _Face Face;

typedef struct _MVertex MVertex;

typedef struct _MFace MFace;

typedef struct _RGBAColor RGBAColor;

typedef struct _PVertex PVertex;

typedef struct _VertexPool VertexPool;

typedef struct _PrimPool PrimPool;

typedef struct _Sphere Sphere;

typedef struct _Sphere_noSq Sphere_noSq;

typedef struct _CameraKey CameraKey;

typedef struct Object Object;

typedef struct _BVertex BVertex;

typedef struct _BFace BFace;

typedef struct _BGObject BGObject;

typedef struct Signal Signal;

typedef struct _MultiSignal MultiSignal;

typedef struct _HFace HFace;

typedef struct _HSphere HSphere;

typedef struct _HBox HBox;

typedef struct _HPrim HPrim;

typedef struct _HModel HModel;

typedef struct _HInfo HInfo;

typedef struct _Segment Segment;

typedef struct MultiSpline MultiSpline;

typedef struct _Model Model;

typedef struct SoundInstance SoundInstance;

typedef struct ObjectEffect ObjectEffect;

typedef struct ObjectEffect AnimEffectData;

typedef struct VramSize VramSize;

typedef struct _TFace TFace;

typedef struct _TVertex TVertex;

typedef struct EventAliasCommandStruct EventAliasCommandStruct;

typedef struct _Instance Instance;

typedef struct _InstancePool InstancePool;

typedef struct _InstanceList InstanceList;

typedef struct _ObjectTracker ObjectTracker;

typedef struct Intro Intro;

typedef struct _BoundingBox BoundingBox;

typedef struct CDLight CDLight;

typedef struct _BSPNode BSPNode;

typedef struct _BSPNode SBSPNode;

typedef struct _BSPLeaf BSPLeaf;

typedef struct _MorphVertex MorphVertex;

typedef struct _MorphColor MorphColor;

typedef struct _SavedCinematic SavedCinematic;

typedef struct BSPTree BSPTree;

typedef struct _Terrain Terrain;

typedef struct LightGroup LightGroup;

typedef struct LightList LightList;

typedef struct PointLight PointLight;

typedef struct SpotLight SpotLight;

typedef struct LightInfo LightInfo;

typedef struct _VMOffset VMMoveOffset;

typedef struct _VMColorOffset VMColorOffset;

typedef struct _VMInterpolated VMInterpolated;

typedef struct _VMOffsetTable VMOffsetTable;

typedef struct _VMObject VMObject;

typedef struct _VGroup VGroup;

typedef struct _HotSpot HotSpot;

typedef struct _PlanMkr PlanMkr;

typedef struct _SFXMkr SFXMkr;

typedef struct TClassAttr TClassAttr;

typedef struct Level Level;

typedef struct _ColorType ColorType;

typedef struct _CameraCore_Type CameraCore;

typedef struct SpuVolume SpuVolume;

typedef struct SpuVoiceAttr SpuVoiceAttr;

typedef struct SpuExtAttr SpuExtAttr;

typedef struct SpuStVoiceAttr SpuStVoiceAttr;

typedef struct AadSoundBankHdr AadSoundBankHdr;

typedef struct AadProgramAtr AadProgramAtr;

typedef struct AadToneAtr AadToneAtr;

typedef struct _AadDynSfxFileHdr AadDynSfxSnfFileHdr;

typedef struct AadDynSfxAttr AadDynSfxAttr;

typedef struct AadTempoCounter AadTempoCounter;

typedef struct AadSeqEvent AadSeqEvent;

typedef struct _AadSequenceSlot AadSequenceSlot;

typedef struct AadSfxCommand AadSfxCommand;

typedef struct AadSfxSlot AadSfxSlot;

typedef struct AadSynthVoice AadSynthVoice;

typedef struct AadDynamicLoadRequest AadDynamicLoadRequest;

typedef struct AadDynamicBankLoadInfo AadDynamicBankLoadInfo;

typedef struct AadDynamicSfxLoadInfo AadDynamicSfxLoadInfo;

typedef struct AadNewSramBlockDesc AadNewSramBlockDesc;

typedef struct AadLoadedSfxToneAttr AadLoadedSfxToneAttr;

typedef struct AadLoadedSfxWaveAttr AadLoadedSfxWaveAttr;

typedef struct AadSramDefragInfo AadSramDefragInfo;

typedef struct AadVolFader AadVolFader;

typedef struct MusicLoadCmd MusicLoadCmd;

typedef struct gSoundData gSoundData;

typedef struct GameTracker GameTracker;

typedef struct Spline Spline;

typedef struct vecS vecS;

typedef struct vecL vecL;

typedef struct SplineRotKey SplineRotKey;

typedef struct RSpline RSpline;

typedef struct SplineKey SplineKey;

typedef struct SplineDef SplineDef;

typedef struct _HVertex HVertex;

typedef struct _MONAPI_Regenerator MONAPI_Regenerator;

typedef enum DEBUG_LINE_TYPE DEBUG_LINE_TYPE;

typedef struct __Event Message;

typedef struct __MessageQueue MessageQueue;

typedef struct __State State;

typedef unsigned char u_char;

typedef unsigned short u_short;

typedef unsigned int u_int;

typedef unsigned long u_long;

typedef unsigned short ushort;

typedef struct _physadr *physadr;

typedef long daddr_t;

typedef char *caddr_t;

typedef long *qaddr_t;

typedef unsigned long ino_t;

typedef long swblk_t;

typedef unsigned int size_t;

typedef long time_t;

typedef short dev_t;

typedef long off_t;

typedef unsigned short uid_t;

typedef unsigned short gid_t;

typedef unsigned long wchar_t;

typedef void (*CdlCB)();

typedef void *va_list;

typedef unsigned char uchar;

typedef unsigned char u_byte;

typedef unsigned char ubyte;

typedef unsigned long ulong;

typedef char int8;

typedef short int16;

typedef long int32;

typedef long int64;

typedef unsigned char uint8;

typedef unsigned short uint16;

typedef unsigned long uint32;

typedef unsigned long uint64;

typedef char BYTE;

typedef unsigned char UBYTE;

typedef unsigned long ULONG;

typedef unsigned short USHORT;

typedef unsigned long bool;

typedef long ListOrderFunc();

typedef unsigned long *OTag;

typedef unsigned char G2UInt8;

typedef unsigned short G2UInt16;

typedef unsigned long G2UInt32;

typedef char G2Int8;

typedef short G2Int16;

typedef long G2Int32;

typedef long G2fp4dot12;

typedef long G2fp8dot24;

typedef short G2TimerAtomicUnit;

typedef int G2AnimKeyframeNumber;

typedef int G2AnimKeylistID;

typedef int G2AnimSectionID;

typedef unsigned char G2AnimSegmentID;

typedef unsigned char G2AnimControllerType;

typedef unsigned short G2AnimChanMask;

typedef long (*G2AnimCallback)();

typedef unsigned long (*G2AnimControllerFn)();

typedef short G2AnimChanKeyData;

typedef short G2AnimChanFinalValue;

typedef enum _G2Bool_Enum (*G2InstanceRebuildCallback)();

typedef long lfixed;

typedef short sfixed;

typedef short MatEntry;

typedef short Fraction;

typedef long VectorCoord;

typedef short SVectorCoord;

typedef short NormalCoord;

typedef short TrigVal;

typedef short Angle;

typedef short Matrix[3][3];

typedef void InitFunc();

typedef void ProcessFunc();

typedef void CollideFunc();

typedef unsigned long QueryFunc();

typedef void MessageFunc();

typedef void RelocateTuneFunc();

typedef void (*SpuIRQCallbackProc)();

typedef void (*SpuTransferCallbackProc)();

typedef void (*SpuStCallbackProc)();

typedef int AADRESULT;

typedef int AadFileHandle;

typedef unsigned long AadChannelList;

typedef void (*AadFadeCompleteCallbackProc)();

typedef void (*AadLockVoiceCallbackProc)();

typedef void (*AadController11CallbackProc)();

typedef void (*AadEndSequenceCallbackProc)();

typedef void (*AadLoadDynamicSoundBankReturnProc)();

typedef void (*AadLoadDynamicSfxReturnProc)();

typedef void (**AadMemoryMallocProc)();

typedef void (*AadMemoryFreeProc)();

typedef void (*AadNonBlockLoadReturnProc)();

typedef void (*AadNonBlockLoadProc)();

typedef void (*AadNonBlockBufferedLoadReturnProc)();

typedef void (*AadNonBlockBufferedLoadProc)();

typedef unsigned char AadNewSramBlockHandle;

typedef unsigned long AadSfxHandle;

typedef unsigned int AadSfxToneID;

typedef void (*EndSequenceCallbackProc)();

typedef void (*Controller11CallbackProc)();

typedef unsigned long *DrawNonAnimatedSegmentFunc();

typedef unsigned long *DrawAnimatedModelFunc();

typedef unsigned long *DrawDisplayPolytopeListFunc();

typedef unsigned long *AdditionalDrawFunc();

typedef void BG_DisplayFunc();

typedef void RelocateInstObFunc();

typedef void (*VoidProc)();

typedef void (*StateHandler)();

extern void PLAYER_TurnHead(struct _Instance *instance, short *rotx, short *rotz, struct GameTracker *gameTracker); // 0x80012D5C

extern long PLAYER_OkToLookAround(struct _Instance *instance); // 0x80012DDC

extern void PLAYER_SetLookAround(struct _Instance *instance); // 0x80012E28

extern void PLAYER_ReSetLookAround(struct _Instance *instance); // 0x80012E74

#endif
