#ifndef DRAW_H
#define DRAW_H

extern struct UVTYPE *face_uv0; // offset 0x800CE1B8

extern struct UVTYPE *face_uv01; // offset 0x800CE1C4

extern struct UVTYPE *face_uv1; // offset 0x800CE1BC

extern struct UVTYPE *face_uv12; // offset 0x800CE1C8

extern struct UVTYPE *face_uv2; // offset 0x800CE1C0

extern struct UVTYPE *face_uv20; // offset 0x800CE1CC

extern struct SVECTOR *face_v0; // offset 0x800CE1A0

extern struct SVECTOR *face_v01; // offset 0x800CE1AC

extern struct SVECTOR *face_v1; // offset 0x800CE1A4

extern struct SVECTOR *face_v12; // offset 0x800CE1B0

extern struct SVECTOR *face_v2; // offset 0x800CE1A8

extern struct SVECTOR *face_v20; // offset 0x800CE1B4

extern struct SVECTOR shadow_vertices[11]; // offset 0x800D038C

struct POLY_GT3 // hashcode: 0x405DA246 (dec: 1079878214)
{
	unsigned long tag;	// size=0, offset=0 //  hashcode: 0xBE8A9AB5 (dec: -1098212683), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;	 // size=0, offset=4 //  hashcode: 0x785FCCA0 (dec: 2019544224), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;	 // size=0, offset=5 //  hashcode: 0x45000AC4 (dec: 1157630660), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;	 // size=0, offset=6 //  hashcode: 0x32D9B328 (dec: 853127976), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code;   // size=0, offset=7 //  hashcode: 0xC602ED1A (dec: -972886758), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			  // size=0, offset=8 //  hashcode: 0xBE17DBE7 (dec: -1105732633), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			  // size=0, offset=10 //  hashcode: 0x7E684DEB (dec: 2120764907), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u0;	 // size=0, offset=12 //  hashcode: 0x3705F885 (dec: 923138181), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v0;	 // size=0, offset=13 //  hashcode: 0x2EB067DE (dec: 783312862), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short clut;  // size=0, offset=14 //  hashcode: 0x2C1AFD5D (dec: 739966301), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r1;	 // size=0, offset=16 //  hashcode: 0x1766D7B3 (dec: 392615859), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g1;	 // size=0, offset=17 //  hashcode: 0x4E858BF1 (dec: 1317374961), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b1;	 // size=0, offset=18 //  hashcode: 0xC341687C (dec: -1019123588), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char p1;	 // size=0, offset=19 //  hashcode: 0x1C6D49EC (dec: 476924396), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			  // size=0, offset=20 //  hashcode: 0xB090760E (dec: -1332709874), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			  // size=0, offset=22 //  hashcode: 0xFCFB8946 (dec: -50624186), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u1;	 // size=0, offset=24 //  hashcode: 0xBCABD01A (dec: -1129590758), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v1;	 // size=0, offset=25 //  hashcode: 0x6337F204 (dec: 1664610820), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short tpage; // size=0, offset=26 //  hashcode: 0x2CE813C8 (dec: 753406920), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r2;	 // size=0, offset=28 //  hashcode: 0x242D5B3B (dec: 606952251), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g2;	 // size=0, offset=29 //  hashcode: 0x496118CE (dec: 1231100110), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b2;	 // size=0, offset=30 //  hashcode: 0xE38C0927 (dec: -477361881), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char p2;	 // size=0, offset=31 //  hashcode: 0x06F0BC2F (dec: 116440111), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;			  // size=0, offset=32 //  hashcode: 0x2458A5B2 (dec: 609789362), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;			  // size=0, offset=34 //  hashcode: 0xB2E515C7 (dec: -1293609529), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u2;	 // size=0, offset=36 //  hashcode: 0x57C334DF (dec: 1472410847), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v2;	 // size=0, offset=37 //  hashcode: 0x25CA6371 (dec: 634020721), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad2;  // size=0, offset=38 //  hashcode: 0x77B6B984 (dec: 2008463748), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct POLY_GT4 // hashcode: 0x596BAA44 (dec: 1500228164)
{
	unsigned long tag;	// size=0, offset=0 //  hashcode: 0x03522704 (dec: 55715588), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;	 // size=0, offset=4 //  hashcode: 0xE3D60335 (dec: -472513739), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;	 // size=0, offset=5 //  hashcode: 0x31D0E196 (dec: 835772822), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;	 // size=0, offset=6 //  hashcode: 0xE1C564FC (dec: -507157252), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code;   // size=0, offset=7 //  hashcode: 0x29B920BF (dec: 699998399), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			  // size=0, offset=8 //  hashcode: 0xB3E3D0B5 (dec: -1276915531), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			  // size=0, offset=10 //  hashcode: 0x27B8975A (dec: 666408794), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u0;	 // size=0, offset=12 //  hashcode: 0xD17831B7 (dec: -780652105), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v0;	 // size=0, offset=13 //  hashcode: 0x35B75E85 (dec: 901209733), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short clut;  // size=0, offset=14 //  hashcode: 0xE20653F1 (dec: -502901775), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r1;	 // size=0, offset=16 //  hashcode: 0xB7E1EF91 (dec: -1209929839), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g1;	 // size=0, offset=17 //  hashcode: 0x06CF8466 (dec: 114263142), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b1;	 // size=0, offset=18 //  hashcode: 0x70AF607F (dec: 1890541695), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char p1;	 // size=0, offset=19 //  hashcode: 0x85C66D4F (dec: -2050593457), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			  // size=0, offset=20 //  hashcode: 0x92C5AA60 (dec: -1832539552), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			  // size=0, offset=22 //  hashcode: 0x1F4EC695 (dec: 525256341), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u1;	 // size=0, offset=24 //  hashcode: 0xE370E163 (dec: -479141533), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v1;	 // size=0, offset=25 //  hashcode: 0x1E2D57D6 (dec: 506288086), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short tpage; // size=0, offset=26 //  hashcode: 0xDEA755DE (dec: -559458850), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r2;	 // size=0, offset=28 //  hashcode: 0x890E0EDA (dec: -1995567398), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g2;	 // size=0, offset=29 //  hashcode: 0xE46825BF (dec: -462936641), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b2;	 // size=0, offset=30 //  hashcode: 0xFD4806C5 (dec: -45611323), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char p2;	 // size=0, offset=31 //  hashcode: 0x3F1E7AA4 (dec: 1058962084), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;			  // size=0, offset=32 //  hashcode: 0x997AB78C (dec: -1720010868), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;			  // size=0, offset=34 //  hashcode: 0xA2CBAA60 (dec: -1563710880), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u2;	 // size=0, offset=36 //  hashcode: 0x215E270E (dec: 559818510), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v2;	 // size=0, offset=37 //  hashcode: 0x715BFA9F (dec: 1901853343), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad2;  // size=0, offset=38 //  hashcode: 0x619FA6F2 (dec: 1637852914), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r3;	 // size=0, offset=40 //  hashcode: 0x89275E95 (dec: -1993908587), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g3;	 // size=0, offset=41 //  hashcode: 0xBA177650 (dec: -1172867504), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b3;	 // size=0, offset=42 //  hashcode: 0x9EDC1752 (dec: -1629743278), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char p3;	 // size=0, offset=43 //  hashcode: 0xF74348D0 (dec: -146585392), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x3;			  // size=0, offset=44 //  hashcode: 0x03124477 (dec: 51528823), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y3;			  // size=0, offset=46 //  hashcode: 0x7B38C10F (dec: 2067317007), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u3;	 // size=0, offset=48 //  hashcode: 0x7578E5B1 (dec: 1970857393), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v3;	 // size=0, offset=49 //  hashcode: 0xB89054C7 (dec: -1198500665), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad3;  // size=0, offset=50 //  hashcode: 0xB4A55548 (dec: -1264233144), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_68fake // hashcode: 0x47B6FB1A (dec: 1203174170)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x7B68EDF6 (dec: 2070474230), parent name: 'DRAW_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x8E4483E3 (dec: -1908112413), parent name: 'DRAW_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_69fake // hashcode: 0x7D659FD5 (dec: 2103812053)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xCE30FAFD (dec: -835650819), parent name: 'DRAW_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x95E9A558 (dec: -1779849896), parent name: 'DRAW_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_70fake // hashcode: 0x03B38BF6 (dec: 62098422)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x1EECAA40 (dec: 518826560), parent name: 'DRAW_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x1FB2B2F2 (dec: 531804914), parent name: 'DRAW_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union DRAW_71fake // Hashcode: 0x10652FFA (dec: 275066874)
{
	struct DRAW_68fake callback; // size=8, offset=0
	struct DRAW_69fake vector;   // size=12, offset=0
	struct DRAW_70fake quat;	 // size=16, offset=0
};

union DRAW_72fake // Hashcode: 0x5A7FA683 (dec: 1518315139)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct _PFace // hashcode: 0xD6E8EAC4 (dec: -689378620)
{
	unsigned long *tag;   // size=0, offset=0 //  hashcode: 0x192AF2BE (dec: 422245054), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;	 // size=0, offset=4 //  hashcode: 0x2F7F2A1B (dec: 796863003), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;	 // size=0, offset=5 //  hashcode: 0x81C26D70 (dec: -2117964432), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;	 // size=0, offset=6 //  hashcode: 0xC0F21D95 (dec: -1057874539), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code;   // size=0, offset=7 //  hashcode: 0x5B0628CD (dec: 1527130317), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			  // size=0, offset=8 //  hashcode: 0xE14504BF (dec: -515570497), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			  // size=0, offset=10 //  hashcode: 0x0EC33AC9 (dec: 247675593), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u0;	 // size=0, offset=12 //  hashcode: 0xA1AD1942 (dec: -1582491326), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v0;	 // size=0, offset=13 //  hashcode: 0x16F38B9F (dec: 385059743), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clut;			  // size=0, offset=14 //  hashcode: 0xAB74E3CE (dec: -1418402866), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			  // size=0, offset=16 //  hashcode: 0xD280DE64 (dec: -763306396), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			  // size=0, offset=18 //  hashcode: 0x65D2C543 (dec: 1708311875), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u1;	 // size=0, offset=20 //  hashcode: 0xA39FA19E (dec: -1549819490), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v1;	 // size=0, offset=21 //  hashcode: 0x3CB1CB99 (dec: 1018284953), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short tpage; // size=0, offset=22 //  hashcode: 0x5E3B370E (dec: 1580939022), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;			  // size=0, offset=24 //  hashcode: 0xEA136BBF (dec: -367825985), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;			  // size=0, offset=26 //  hashcode: 0x1C8FC847 (dec: 479184967), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u2;	 // size=0, offset=28 //  hashcode: 0xEDC8BCB2 (dec: -305611598), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v2;	 // size=0, offset=29 //  hashcode: 0xEB5E9507 (dec: -346123001), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad1;			  // size=0, offset=30 //  hashcode: 0xE97923FD (dec: -377936899), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	long pad2;			  // size=0, offset=32 //  hashcode: 0x7D8DB5DA (dec: 2106439130), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	long pad3;			  // size=0, offset=36 //  hashcode: 0xE87F7997 (dec: -394298985), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union DRAW_73fake // Hashcode: 0x7CE10B10 (dec: 2095123216)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct DRAW_74fake // hashcode: 0xD354B658 (dec: -749423016)
{
	union DRAW_73fake size; // size=4, offset=0 //  hashcode: 0xFDFF95DC (dec: -33581604), parent name: 'DRAW_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_75fake // hashcode: 0x794F0D1B (dec: 2035223835)
{
	short x;				// size=0, offset=0 //  hashcode: 0x4E9666F1 (dec: 1318479601), parent name: 'DRAW_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xE924309E (dec: -383504226), parent name: 'DRAW_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x47E68732 (dec: 1206290226), parent name: 'DRAW_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x791A9E72 (dec: 2031787634), parent name: 'DRAW_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x46D5D287 (dec: 1188418183), parent name: 'DRAW_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_76fake // hashcode: 0xF9E8F8B3 (dec: -102172493)
{
	long index; // size=0, offset=0 //  hashcode: 0xECEE2272 (dec: -319937934), parent name: 'DRAW_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x102F81F2 (dec: 271548914), parent name: 'DRAW_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_77fake // hashcode: 0x7C08A005 (dec: 2080940037)
{
	long index; // size=0, offset=0 //  hashcode: 0xE2ADC15A (dec: -491929254), parent name: 'DRAW_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x50EFADC7 (dec: 1357884871), parent name: 'DRAW_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_78fake // hashcode: 0x355450D6 (dec: 894718166)
{
	long index; // size=0, offset=0 //  hashcode: 0x21AEB0E0 (dec: 565096672), parent name: 'DRAW_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xD960D99B (dec: -647964261), parent name: 'DRAW_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_79fake // hashcode: 0x286A292B (dec: 678045995)
{
	long time;  // size=0, offset=0 //  hashcode: 0xF7C06328 (dec: -138386648), parent name: 'DRAW_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xDB7D190F (dec: -612558577), parent name: 'DRAW_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_80fake // hashcode: 0x59D7E8BF (dec: 1507322047)
{
	long action;   // size=0, offset=0 //  hashcode: 0x22D0061C (dec: 584058396), parent name: 'DRAW_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x3D7A9F3C (dec: 1031446332), parent name: 'DRAW_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_81fake // hashcode: 0xE0A9B7FE (dec: -525748226)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x83932FE2 (dec: -2087505950), parent name: 'DRAW_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x0542BA20 (dec: 88259104), parent name: 'DRAW_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_82fake // hashcode: 0xAD8A8BEF (dec: -1383429137)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x56D5C9CF (dec: 1456851407), parent name: 'DRAW_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x2453AAC2 (dec: 609462978), parent name: 'DRAW_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_83fake // hashcode: 0x4E48E7AB (dec: 1313400747)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xDB40A03A (dec: -616521670), parent name: 'DRAW_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xE92A6E79 (dec: -383095175), parent name: 'DRAW_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_84fake // hashcode: 0x2F762AD7 (dec: 796273367)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xDAB01D92 (dec: -625992302), parent name: 'DRAW_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x11496E29 (dec: 290025001), parent name: 'DRAW_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x946D5138 (dec: -1804775112), parent name: 'DRAW_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xA99CD895 (dec: -1449338731), parent name: 'DRAW_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x3D8792C4 (dec: 1032295108), parent name: 'DRAW_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_85fake // hashcode: 0x31307539 (dec: 825259321)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x26022C53 (dec: 637676627), parent name: 'DRAW_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xE5C3287F (dec: -440194945), parent name: 'DRAW_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_86fake // hashcode: 0xE641FA88 (dec: -431883640)
{
	short index;					// size=0, offset=0 //  hashcode: 0xDADA663E (dec: -623221186), parent name: 'DRAW_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xA20028AC (dec: -1577047892), parent name: 'DRAW_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x104DAF97 (dec: 273526679), parent name: 'DRAW_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xECCABA97 (dec: -322258281), parent name: 'DRAW_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_87fake // hashcode: 0xEA81587F (dec: -360621953)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x70417C4C (dec: 1883339852), parent name: 'DRAW_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xCD9E7234 (dec: -845254092), parent name: 'DRAW_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xEC88A452 (dec: -326589358), parent name: 'DRAW_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_88fake // hashcode: 0x6CD5B8E0 (dec: 1825945824)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x814FDA97 (dec: -2125473129), parent name: 'DRAW_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xBCE8317F (dec: -1125633665), parent name: 'DRAW_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x8780829B (dec: -2021621093), parent name: 'DRAW_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x86248F46 (dec: -2044424378), parent name: 'DRAW_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x10A2C6DB (dec: 279103195), parent name: 'DRAW_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x31A01282 (dec: 832574082), parent name: 'DRAW_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xEF71B184 (dec: -277761660), parent name: 'DRAW_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_89fake // hashcode: 0xC33F4575 (dec: -1019263627)
{
	long index;  // size=0, offset=0 //  hashcode: 0x1B5C7693 (dec: 459044499), parent name: 'DRAW_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x730447EF (dec: 1929660399), parent name: 'DRAW_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_90fake // hashcode: 0xD7CC34C3 (dec: -674483005)
{
	short type; // size=0, offset=0 //  hashcode: 0xF04FC63C (dec: -263207364), parent name: 'DRAW_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0xD6756229 (dec: -696950231), parent name: 'DRAW_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_91fake // hashcode: 0xA781614D (dec: -1484693171)
{
	long time;   // size=0, offset=0 //  hashcode: 0x641EE494 (dec: 1679746196), parent name: 'DRAW_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x429ABE0C (dec: 1117437452), parent name: 'DRAW_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_92fake // hashcode: 0xD5F51045 (dec: -705359803)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x825FE63A (dec: -2107644358), parent name: 'DRAW_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x8758367F (dec: -2024262017), parent name: 'DRAW_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_93fake // hashcode: 0x163E4F4E (dec: 373182286)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x638BC271 (dec: 1670103665), parent name: 'DRAW_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x9D08E297 (dec: -1660362089), parent name: 'DRAW_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_94fake // hashcode: 0xE195D13B (dec: -510275269)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xD0A4A8A7 (dec: -794515289), parent name: 'DRAW_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xA7619D78 (dec: -1486774920), parent name: 'DRAW_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_95fake // hashcode: 0x89FF9267 (dec: -1979739545)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x3ADD30E4 (dec: 987574500), parent name: 'DRAW_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x6D50414F (dec: 1833976143), parent name: 'DRAW_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x7150600C (dec: 1901092876), parent name: 'DRAW_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xA0C66D38 (dec: -1597608648), parent name: 'DRAW_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_96fake // hashcode: 0xC5410FD6 (dec: -985591850)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x58A4617A (dec: 1487167866), parent name: 'DRAW_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x588BD18A (dec: 1485558154), parent name: 'DRAW_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xBD5A47E8 (dec: -1118156824), parent name: 'DRAW_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x5FBAC0EF (dec: 1606074607), parent name: 'DRAW_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xE2BC43E4 (dec: -490978332), parent name: 'DRAW_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union DRAW_97fake // Hashcode: 0x6135146B (dec: 1630868587)
{
	struct DRAW_74fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;	// size=24, offset=0
	struct DRAW_75fake teleport;	 // size=16, offset=0
	struct DRAW_76fake cameraValue;  // size=8, offset=0
	struct DRAW_77fake miscValue;	// size=8, offset=0
	struct DRAW_78fake logicValue;   // size=8, offset=0
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
	struct DRAW_79fake cameraShake;  // size=8, offset=0
	long cameraSave;				 // size=0, offset=0
	long cameraRestore;				 // size=0, offset=0
	struct _BGObject *bgObject;		 // size=24, offset=0
	long value[2];					 // size=8, offset=0
	struct DRAW_80fake sound;		 // size=12, offset=0
	void *intro;					 // size=0, offset=0
	long deathZ;					 // size=0, offset=0
	struct DRAW_81fake dsignal;		 // size=8, offset=0
	void *mirror;					 // size=0, offset=0
	long fogNear;					 // size=0, offset=0
	long fogFar;					 // size=0, offset=0
	struct DRAW_82fake gotoFrame;	// size=8, offset=0
	struct DRAW_83fake changeModel;  // size=8, offset=0
	void *vmObject;					 // size=0, offset=0
	struct DRAW_84fake logic;		 // size=8, offset=0
	void *callSignal;				 // size=0, offset=0
	struct _SVector offset;			 // size=8, offset=0
	struct Signal *gotoLabel;		 // size=0, offset=0
	struct Signal *gosubLabel;		 // size=0, offset=0
	struct DRAW_85fake control;		 // size=8, offset=0
	struct DRAW_86fake zSignal;		 // size=12, offset=0
	struct DRAW_87fake StreamLevel;  // size=24, offset=0
	struct DRAW_88fake shards;		 // size=12, offset=0
	struct DRAW_89fake cameraSpline; // size=8, offset=0
	struct DRAW_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;				 // size=0, offset=0
	struct DRAW_91fake introFX;		 // size=8, offset=0
	struct DRAW_92fake introActive;  // size=8, offset=0
	struct DRAW_93fake levelChange;  // size=18, offset=0
	long blendStart;				 // size=0, offset=0
	struct DRAW_94fake setTimes;	 // size=8, offset=0
	struct DRAW_95fake color;		 // size=4, offset=0
	struct DRAW_96fake print;		 // size=12, offset=0
	long slideAngle;				 // size=0, offset=0
};

union DRAW_98fake // Hashcode: 0x9E9A392F (dec: -1634059985)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

struct _PolytopeList // hashcode: 0xAC7B9901 (dec: -1401186047)
{
	long numPolytopes;	 // size=0, offset=0 //  hashcode: 0xA5893285 (dec: -1517735291), parent name: '_PolytopeList', parent hashcode: 0xFFFFFFFF (dec: -1)
	void(*polytope[1024]); // size=4096, offset=4 //  hashcode: 0xD8FF0675 (dec: -654375307), parent name: '_PolytopeList', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union DRAW_103fake // Hashcode: 0x7D60F8E7 (dec: 2103507175)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct DRAW_105fake // hashcode: 0x0DC8D89B (dec: 231266459)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x4F59B62C (dec: 1331279404), parent name: 'DRAW_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xE25D6E61 (dec: -497193375), parent name: 'DRAW_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x665E5DF0 (dec: 1717460464), parent name: 'DRAW_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xF58C815E (dec: -175341218), parent name: 'DRAW_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0xA5B3A406 (dec: -1514953722), parent name: 'DRAW_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x26AC3027 (dec: 648818727), parent name: 'DRAW_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xE901DA48 (dec: -385754552), parent name: 'DRAW_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_106fake // hashcode: 0xF5213ED0 (dec: -182370608)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0xA5EF1095 (dec: -1511059307), parent name: 'DRAW_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x1818870D (dec: 404260621), parent name: 'DRAW_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x2ECE4C39 (dec: 785271865), parent name: 'DRAW_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_107fake // hashcode: 0x30722B57 (dec: 812788567)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x2CDDB5D6 (dec: 752727510), parent name: 'DRAW_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xA7B8FEA1 (dec: -1481048415), parent name: 'DRAW_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xFBBC3ECF (dec: -71549233), parent name: 'DRAW_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x8675FA4C (dec: -2039088564), parent name: 'DRAW_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x4AE5E7A2 (dec: 1256581026), parent name: 'DRAW_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_108fake // hashcode: 0xAF7BF583 (dec: -1350830717)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0xED98E4E3 (dec: -308747037), parent name: 'DRAW_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x0DB51A59 (dec: 229972569), parent name: 'DRAW_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x30E595BD (dec: 820352445), parent name: 'DRAW_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x4F056207 (dec: 1325752839), parent name: 'DRAW_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xB97A6274 (dec: -1183161740), parent name: 'DRAW_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_109fake // hashcode: 0x13B53E5F (dec: 330645087)
{
	struct DRAW_105fake Cinematic; // size=28, offset=0 //  hashcode: 0x91874CA8 (dec: -1853403992), parent name: 'DRAW_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DRAW_106fake Idle;	  // size=20, offset=28 //  hashcode: 0xEEC81262 (dec: -288877982), parent name: 'DRAW_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DRAW_107fake Behind;	// size=28, offset=48 //  hashcode: 0x363E208C (dec: 910041228), parent name: 'DRAW_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DRAW_108fake Follow;	// size=20, offset=76 //  hashcode: 0xBA50D942 (dec: -1169106622), parent name: 'DRAW_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UVTYPE // hashcode: 0x7D142F71 (dec: 2098474865)
{
	unsigned char u; // size=0, offset=0 //  hashcode: 0x42B7FF60 (dec: 1119354720), parent name: 'UVTYPE', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v; // size=0, offset=1 //  hashcode: 0x35CEBD18 (dec: 902741272), parent name: 'UVTYPE', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;		 // size=0, offset=2 //  hashcode: 0xE306C083 (dec: -486096765), parent name: 'UVTYPE', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct POLY_G3_SEMITRANS // hashcode: 0x323808D7 (dec: 842533079)
{
	unsigned long tag;		// size=0, offset=0 //  hashcode: 0x2385722E (dec: 595948078), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long dr_tpage; // size=0, offset=4 //  hashcode: 0x36E96E52 (dec: 921267794), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;		// size=0, offset=8 //  hashcode: 0x8B5A1BDA (dec: -1957028902), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;		// size=0, offset=9 //  hashcode: 0xA8DEDBD1 (dec: -1461789743), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;		// size=0, offset=10 //  hashcode: 0xD8FB7C5E (dec: -654607266), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code;		// size=0, offset=11 //  hashcode: 0x58301034 (dec: 1479544884), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;				// size=0, offset=12 //  hashcode: 0x36EF830E (dec: 921666318), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;				// size=0, offset=14 //  hashcode: 0x52ACF878 (dec: 1387067512), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r1;		// size=0, offset=16 //  hashcode: 0x5397A436 (dec: 1402446902), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g1;		// size=0, offset=17 //  hashcode: 0x310AC6A8 (dec: 822789800), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b1;		// size=0, offset=18 //  hashcode: 0x2B1EF59E (dec: 723449246), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad1;		// size=0, offset=19 //  hashcode: 0xD8578E9D (dec: -665350499), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;				// size=0, offset=20 //  hashcode: 0xC06B9D52 (dec: -1066689198), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;				// size=0, offset=22 //  hashcode: 0x07095888 (dec: 118053000), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r2;		// size=0, offset=24 //  hashcode: 0xF55B169F (dec: -178579809), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g2;		// size=0, offset=25 //  hashcode: 0x329AE304 (dec: 849011460), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b2;		// size=0, offset=26 //  hashcode: 0xB4429189 (dec: -1270705783), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad2;		// size=0, offset=27 //  hashcode: 0xE3071164 (dec: -486076060), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;				// size=0, offset=28 //  hashcode: 0xE727ABBB (dec: -416830533), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;				// size=0, offset=30 //  hashcode: 0x4EF083C5 (dec: 1324385221), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_184fake // hashcode: 0x376E6C49 (dec: 929983561)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x07F4C169 (dec: 133480809), parent name: 'DRAW_184fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x4595C42C (dec: 1167442988), parent name: 'DRAW_184fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAW_185fake // hashcode: 0x4494C578 (dec: 1150600568)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0xFFD8D637 (dec: -2566601), parent name: 'DRAW_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0xBE15210E (dec: -1105911538), parent name: 'DRAW_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x3BBC663D (dec: 1002202685), parent name: 'DRAW_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x028D170D (dec: 42800909), parent name: 'DRAW_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0x9BE1AEF5 (dec: -1679708427), parent name: 'DRAW_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0xE2764E5D (dec: -495563171), parent name: 'DRAW_185fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union DRAW_186fake // Hashcode: 0x33FFD219 (dec: 872403481)
{
	struct DRAW_184fake flame; // size=8, offset=0
	struct DRAW_185fake phys;  // size=12, offset=0
};

struct _POLY_NG4 // hashcode: 0x65B704BE (dec: 1706493118)
{
	unsigned long tag;		  // size=0, offset=0 //  hashcode: 0x786EF570 (dec: 2020537712), parent name: '_POLY_NG4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long drawTPage1; // size=0, offset=4 //  hashcode: 0x0ED930BD (dec: 249114813), parent name: '_POLY_NG4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BASIC_G4 p1;	  // size=32, offset=8 //  hashcode: 0x55A16BE7 (dec: 1436642279), parent name: '_POLY_NG4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union DRAW_212fake // Hashcode: 0xA8C66167 (dec: -1463393945)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union DRAW_237fake // Hashcode: 0x06F23F62 (dec: 116539234)
{
	struct _StreamUnit *streamUnit;		 // size=64, offset=0
	struct _ObjectTracker *streamObject; // size=36, offset=0
	struct _ButtonTexture *button;		 // size=16, offset=0
};

struct _GT3ZVertexD3D_Type // hashcode: 0xBD55FA10 (dec: -1118438896)
{
	float x;		   // size=0, offset=0 //  hashcode: 0xC6CCF292 (dec: -959647086), parent name: '_GT3ZVertexD3D_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	float y;		   // size=0, offset=4 //  hashcode: 0x814192CB (dec: -2126409013), parent name: '_GT3ZVertexD3D_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	float z;		   // size=0, offset=8 //  hashcode: 0x454053A1 (dec: 1161843617), parent name: '_GT3ZVertexD3D_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	float rhw;		   // size=0, offset=12 //  hashcode: 0x90B9D15F (dec: -1866870433), parent name: '_GT3ZVertexD3D_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned int rgba; // size=0, offset=16 //  hashcode: 0xEE992457 (dec: -291953577), parent name: '_GT3ZVertexD3D_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	float u;		   // size=0, offset=20 //  hashcode: 0x8E3CC7EB (dec: -1908619285), parent name: '_GT3ZVertexD3D_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	float v;		   // size=0, offset=24 //  hashcode: 0xB55637B4 (dec: -1252640844), parent name: '_GT3ZVertexD3D_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SP_SUBDIV_STRUCT // hashcode: 0x4C4B55E8 (dec: 1280005608)
{
	struct _SVector vertex0;   // size=8, offset=0 //  hashcode: 0xAD86EDAD (dec: -1383666259), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector vertex1;   // size=8, offset=8 //  hashcode: 0x7EDF77A5 (dec: 2128574373), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector vertex2;   // size=8, offset=16 //  hashcode: 0x03A3D930 (dec: 61069616), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR face_v0;	// size=8, offset=24 //  hashcode: 0x5DFC25A4 (dec: 1576805796), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR face_v1;	// size=8, offset=32 //  hashcode: 0xEA9E1DCF (dec: -358736433), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR face_v2;	// size=8, offset=40 //  hashcode: 0xFB867286 (dec: -75074938), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR face_v01;   // size=8, offset=48 //  hashcode: 0x9DC75C6B (dec: -1647879061), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR face_v12;   // size=8, offset=56 //  hashcode: 0x0DBF4E53 (dec: 230641235), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR face_v20;   // size=8, offset=64 //  hashcode: 0x14CAE5FD (dec: 348841469), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct UVTYPE face_uv0;	// size=4, offset=72 //  hashcode: 0xDAA29741 (dec: -626878655), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct UVTYPE face_uv1;	// size=4, offset=76 //  hashcode: 0xD877F612 (dec: -663226862), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct UVTYPE face_uv2;	// size=4, offset=80 //  hashcode: 0xDC4339C6 (dec: -599574074), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct UVTYPE face_uv01;   // size=4, offset=84 //  hashcode: 0x83FDCA5D (dec: -2080519587), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct UVTYPE face_uv12;   // size=4, offset=88 //  hashcode: 0xC2FA948B (dec: -1023765365), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct UVTYPE face_uv20;   // size=4, offset=92 //  hashcode: 0x7EE35CF3 (dec: 2128829683), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _ColorType color0;  // size=4, offset=96 //  hashcode: 0x5FE6FE90 (dec: 1608973968), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _ColorType color1;  // size=4, offset=100 //  hashcode: 0xA81D62FF (dec: -1474469121), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _ColorType color2;  // size=4, offset=104 //  hashcode: 0x3A4832E1 (dec: 977810145), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _ColorType color01; // size=4, offset=108 //  hashcode: 0xFD683308 (dec: -43502840), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _ColorType color12; // size=4, offset=112 //  hashcode: 0x6C93B2E3 (dec: 1821618915), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _ColorType color20; // size=4, offset=116 //  hashcode: 0x3528BCF0 (dec: 891862256), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Vector out[4];	 // size=48, offset=120 //  hashcode: 0xC3320CC8 (dec: -1020130104), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color[4];			   // size=16, offset=168 //  hashcode: 0x3A3D8B36 (dec: 977111862), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	long texinfo[3];		   // size=12, offset=184 //  hashcode: 0x3137C61F (dec: 825738783), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DVECTOR sxy[4];	 // size=16, offset=196 //  hashcode: 0x1A0A4610 (dec: 436880912), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct POLY_GT3 POLY_GT3;

typedef struct POLY_GT4 POLY_GT4;

typedef struct _PFace PFace;

typedef struct _PolytopeList PolytopeList;

typedef struct UVTYPE UVTYPE;

typedef struct POLY_G3_SEMITRANS POLY_G3_SEMITRANS;

typedef struct _POLY_NG4 POLY_NG4;

typedef struct _GT3ZVertexD3D_Type GT3ZVertexD3D;

typedef struct SP_SUBDIV_STRUCT SP_SUBDIV_STRUCT;

typedef void G2AppData;

extern void fDRAW_SPLIT_INTPL_XYZ(struct _SVector *newVertex, struct _SVector *pvb, struct _SVector *pvc); // 0x8002A5B0

extern void DRAW_InitShadow(); // 0x8002A62C

extern unsigned long *DRAW_DrawShadow(struct _PrimPool *primPool, struct _Model *model, unsigned long **ot, long fadeValue); // 0x8002A6F4

extern void DRAW_FlatQuad(struct CVECTOR *color, short x0, short y0, short x1, int y1, int x2, int y2, int x3, int y3, struct _PrimPool *primPool, unsigned long **ot); // 0x8002A8B4

extern void DRAW_TranslucentQuad(short x0, short y0, short x1, short y1, int x2, int y2, int x3, int y3, int r, int g, int b, int abr, struct _PrimPool *primPool, unsigned long **ot); // 0x8002A95C

extern void DRAW_DrawButton(struct _ButtonTexture *button, short x, short y, unsigned long **ot); // 0x8002AA40

extern void DRAW_LoadButton(long *addr, struct _ButtonTexture *button); // 0x8002ABA8

extern void DRAW_FreeButton(struct _ButtonTexture *button); // 0x8002AD48

extern void DRAW_RingLine(struct _PrimPool *primPool, unsigned long **ot, long color); // 0x8002AD6C

extern void DRAW_RingPoint(struct _PrimPool *primPool, unsigned long **ot, long color, struct _SVector *vel, struct _SVector *acc); // 0x8002AE9C

extern unsigned long *DRAW_DrawRingPoints(struct _Model *model, struct _VertexPool *vertexPool, struct MATRIX *pcTransform, struct _PrimPool *primPool, unsigned long **ot, long color, int ring_type); // 0x8002AFAC

extern void DRAW_GlowQuad(struct _PrimPool *primPool, unsigned long **ot, long otz, long color, struct _Vector *v0, struct _Vector *v1, struct _Vector *v2, struct _Vector *v3); // 0x8002B2C8

extern void DRAW_CreateAGlowingCircle(struct _Vector *f1, long z, struct _PrimPool *primPool, unsigned long **ot, long otz, long color, long w, long h, long angle); // 0x8002B52C

extern unsigned long *DRAW_DrawGlowPoints2(struct _Instance *instance, long seg1, long seg2, struct _PrimPool *primPool, unsigned long **ot, long color, long height); // 0x8002BAD8

extern unsigned long *DRAW_DrawGlowPoint(struct _Instance *instance, long seg1, struct _PrimPool *primPool, unsigned long **ot, long color, int width, int height); // 0x8002BC44

extern int DRAW_DisplayTFace_zclipped_C(struct SVECTOR *vertex0, struct SVECTOR *vertex1, struct SVECTOR *vertex2, struct UVTYPE *uv0, struct UVTYPE *uv1, struct UVTYPE *uv2, long color0, long color1, long color2, struct _PrimPool *primPool, unsigned long **ot, int ndiv); // 0x8002BD14

extern long *DRAW_Zclip_subdiv(struct POLY_GT3 *texture, unsigned long **ot, int ndiv); // 0x8002C554

extern void DRAW_LoadingMessage(); // 0x8002CA58

#endif
