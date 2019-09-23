#ifndef AADLIB_H
#define AADLIB_H

static unsigned long __hblankEvent; // offset 0x800D18E8

static unsigned short aadHblanksPerUpdate[4]; // offset 0x800CECC0

extern struct AadMemoryStruct *aadMem; // offset 0x800CECD8

static unsigned long aadReverbModeSize[10]; // offset 0x800CED5C

static unsigned long aadUpdateRate[4]; // offset 0x800CECC8

static int gDefragRequest; // offset 0x800CECDC

static unsigned long smfBytesLeft; // offset 0x800D18F0

static unsigned char *smfDataPtr; // offset 0x800D18EC

static struct AadDynamicSfxLoadInfo *smfInfo; // offset 0x800D18F4

struct AadMemoryStruct // hashcode: 0x46CEF45B (dec: 1187968091)
{
	unsigned long updateCounter;					   // size=0, offset=0 //  hashcode: 0x25EB8F48 (dec: 636194632), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numSlots;									   // size=0, offset=4 //  hashcode: 0x6E9FBDA4 (dec: 1855962532), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int updateMode;									   // size=0, offset=8 //  hashcode: 0x24BF7ED2 (dec: 616529618), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int masterVolume;								   // size=0, offset=12 //  hashcode: 0x5A840FF8 (dec: 1518604280), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadVolFader masterVolFader;				   // size=12, offset=16 //  hashcode: 0x038FFEEF (dec: 59768559), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int sfxMasterVol;								   // size=0, offset=28 //  hashcode: 0x6158C376 (dec: 1633207158), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int musicMasterVol;								   // size=0, offset=32 //  hashcode: 0xC2BC0542 (dec: -1027865278), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int flags;										   // size=0, offset=36 //  hashcode: 0x2117E833 (dec: 555214899), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadVolFader musicMasterVolFader;			   // size=12, offset=40 //  hashcode: 0x764E7E7A (dec: 1984855674), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _AadSequenceSlot(*sequenceSlots[8]);		   // size=32, offset=52 //  hashcode: 0x1790C2ED (dec: 395363053), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadSfxSlot sfxSlot;						   // size=392, offset=84 //  hashcode: 0x3EE3983D (dec: 1055103037), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadSynthVoice synthVoice[24];			   // size=672, offset=476 //  hashcode: 0x54C580BE (dec: 1422229694), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	char voiceStatus[24];							   // size=24, offset=1148 //  hashcode: 0x6B6BCD7F (dec: 1802227071), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short voicePitchSave[24];				   // size=48, offset=1172 //  hashcode: 0x28C9AA69 (dec: 684305001), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long voiceKeyOffRequest;				   // size=0, offset=1220 //  hashcode: 0x16E1DE78 (dec: 383901304), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long voiceKeyOnRequest;				   // size=0, offset=1224 //  hashcode: 0x5A2F9046 (dec: 1513066566), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long voiceReverbRequest;				   // size=0, offset=1228 //  hashcode: 0x90421083 (dec: -1874718589), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadSoundBankHdr(*dynamicSoundBankHdr[2]);   // size=8, offset=1232 //  hashcode: 0xCF1E979C (dec: -820078692), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadProgramAtr(*dynamicProgramAtr[2]);	   // size=8, offset=1240 //  hashcode: 0x03270CED (dec: 52890861), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadToneAtr(*dynamicToneAtr[2]);			   // size=8, offset=1248 //  hashcode: 0x9AFAA5A9 (dec: -1694849623), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long(*dynamicWaveAddr[2]);				   // size=8, offset=1256 //  hashcode: 0xCFEFACEA (dec: -806376214), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char(**dynamicSequenceAddressTbl[2]);	 // size=8, offset=1264 //  hashcode: 0x796E6392 (dec: 2037277586), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long(*dynamicSequenceLabelOffsetTbl[2]);  // size=8, offset=1272 //  hashcode: 0x9D506E22 (dec: -1655673310), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int dynamicBankStatus[2];						   // size=8, offset=1280 //  hashcode: 0xA2982677 (dec: -1567086985), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char(*dynamicSoundBankData[2]);		   // size=8, offset=1288 //  hashcode: 0xA233F1A5 (dec: -1573654107), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long dynamicSoundBankSramData[2];		   // size=8, offset=1296 //  hashcode: 0x9AC2212B (dec: -1698553557), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadDynamicLoadRequest loadRequestQueue[16]; // size=448, offset=1304 //  hashcode: 0x5FAA1837 (dec: 1604982839), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadDynamicBankLoadInfo dynamicBankLoadInfo; // size=88, offset=1752 //  hashcode: 0x05106291 (dec: 84959889), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*nonBlockLoadProc)();						   // size=0, offset=1840 //  hashcode: 0x5D64DE72 (dec: 1566891634), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*nonBlockBufferedLoadProc)();				   // size=0, offset=1844 //  hashcode: 0x78C4D356 (dec: 2026165078), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (**memoryMallocProc)();					   // size=0, offset=1848 //  hashcode: 0x3AD50EC8 (dec: 987041480), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*memoryFreeProc)();						   // size=0, offset=1852 //  hashcode: 0x98F62268 (dec: -1728699800), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nextLoadReqIn;								   // size=0, offset=1856 //  hashcode: 0x93C3FEC3 (dec: -1815871805), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nextLoadReqOut;								   // size=0, offset=1860 //  hashcode: 0xB4150756 (dec: -1273690282), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numLoadReqsQueued;							   // size=0, offset=1864 //  hashcode: 0x3E63EFA3 (dec: 1046736803), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadDynamicSfxLoadInfo dynamicSfxLoadInfo;   // size=148, offset=1868 //  hashcode: 0x15447F89 (dec: 356810633), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _AadDynSfxFileHdr *firstDynSfxFile;		   // size=20, offset=2016 //  hashcode: 0x2B7765B4 (dec: 729245108), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nextFileHandle;								   // size=0, offset=2020 //  hashcode: 0x4E4F5852 (dec: 1313822802), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadSramDefragInfo sramDefragInfo;		   // size=32, offset=2024 //  hashcode: 0x1A0EED64 (dec: 437185892), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sfxToneMasterList[512];			   // size=512, offset=2056 //  hashcode: 0xBDFB3852 (dec: -1107609518), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sfxWaveMasterList[512];			   // size=512, offset=2568 //  hashcode: 0x1CD55713 (dec: 483743507), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadLoadedSfxToneAttr sfxToneAttrTbl[128];   // size=2560, offset=3080 //  hashcode: 0x53E79A5F (dec: 1407687263), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadLoadedSfxWaveAttr sfxWaveAttrTbl[120];   // size=480, offset=5640 //  hashcode: 0xD46C2406 (dec: -731110394), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nextToneIndex;								   // size=0, offset=6120 //  hashcode: 0xCF2CB446 (dec: -819153850), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nextWaveIndex;								   // size=0, offset=6124 //  hashcode: 0xF4A92710 (dec: -190241008), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadNewSramBlockDesc sramDescriptorTbl[128]; // size=1024, offset=6128 //  hashcode: 0x3514D111 (dec: 890556689), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nextSramDescIndex;							   // size=0, offset=7152 //  hashcode: 0xA8E1C6B7 (dec: -1461598537), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int firstSramBlockDescIndex;					   // size=0, offset=7156 //  hashcode: 0xEA340B90 (dec: -365687920), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*controller11Callback)();					   // size=0, offset=7160 //  hashcode: 0xEBBF7717 (dec: -339773673), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*endSequenceCallback)();					   // size=0, offset=7164 //  hashcode: 0x125399BC (dec: 307468732), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	long controller11CallbackData;					   // size=0, offset=7168 //  hashcode: 0x800BE034 (dec: -2146705356), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	long endSequenceCallbackData;					   // size=0, offset=7172 //  hashcode: 0xDBBD1D7D (dec: -608363139), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char userVariables[128];				   // size=128, offset=7176 //  hashcode: 0x576294DA (dec: 1466078426), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadSlotAttributes // hashcode: 0x7DE97E8C (dec: 2112454284)
{
	int sequenceNumberAssigned;		 // size=0, offset=0 //  hashcode: 0x083B91EB (dec: 138121707), parent name: 'AadSlotAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	int sequenceAssignedDynamicBank; // size=0, offset=4 //  hashcode: 0x0F0EBD23 (dec: 252624163), parent name: 'AadSlotAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	int playingStatus;				 // size=0, offset=8 //  hashcode: 0x186034D7 (dec: 408958167), parent name: 'AadSlotAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	int channelMute;				 // size=0, offset=12 //  hashcode: 0xB301B340 (dec: -1291734208), parent name: 'AadSlotAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	int slotVolume;					 // size=0, offset=16 //  hashcode: 0xDBC4BBB6 (dec: -607863882), parent name: 'AadSlotAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	int slotPan;					 // size=0, offset=20 //  hashcode: 0xF53CD9B4 (dec: -180561484), parent name: 'AadSlotAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	int eventsInQueue[16];			 // size=64, offset=24 //  hashcode: 0x3ED09602 (dec: 1053857282), parent name: 'AadSlotAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_112fake // hashcode: 0x881B3967 (dec: -2011481753)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0xAA75BFB7 (dec: -1435123785), parent name: 'AADLIB_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x92E0BEDD (dec: -1830764835), parent name: 'AADLIB_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_113fake // hashcode: 0x0F622ABC (dec: 258091708)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x9376AA82 (dec: -1820939646), parent name: 'AADLIB_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xDC0AA89E (dec: -603281250), parent name: 'AADLIB_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_114fake // hashcode: 0x970DA94C (dec: -1760712372)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x60A9E86F (dec: 1621747823), parent name: 'AADLIB_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xC61C7B78 (dec: -971211912), parent name: 'AADLIB_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union AADLIB_115fake // Hashcode: 0xBBFB2637 (dec: -1141168585)
{
	struct AADLIB_112fake callback; // size=8, offset=0
	struct AADLIB_113fake vector;   // size=12, offset=0
	struct AADLIB_114fake quat;		// size=16, offset=0
};

union AADLIB_116fake // Hashcode: 0x1F25FD4D (dec: 522583373)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union AADLIB_117fake // Hashcode: 0xFBDBB008 (dec: -69488632)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct AADLIB_118fake // hashcode: 0xBBD9595F (dec: -1143383713)
{
	union AADLIB_117fake size; // size=4, offset=0 //  hashcode: 0x8CBB868F (dec: -1933867377), parent name: 'AADLIB_118fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_119fake // hashcode: 0x3A3D4A29 (dec: 977095209)
{
	short x;				// size=0, offset=0 //  hashcode: 0x1A915DE2 (dec: 445734370), parent name: 'AADLIB_119fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x999790FD (dec: -1718120195), parent name: 'AADLIB_119fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x36D3C01D (dec: 919846941), parent name: 'AADLIB_119fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xBA5605BF (dec: -1168767553), parent name: 'AADLIB_119fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x8F6E826E (dec: -1888583058), parent name: 'AADLIB_119fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_120fake // hashcode: 0xB20BCFC6 (dec: -1307848762)
{
	long index; // size=0, offset=0 //  hashcode: 0x41E157A1 (dec: 1105287073), parent name: 'AADLIB_120fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x71BA1C9F (dec: 1908022431), parent name: 'AADLIB_120fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_121fake // hashcode: 0xBE16357E (dec: -1105840770)
{
	long index; // size=0, offset=0 //  hashcode: 0xF0015758 (dec: -268347560), parent name: 'AADLIB_121fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x0642EC5D (dec: 105049181), parent name: 'AADLIB_121fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_122fake // hashcode: 0x0B85C722 (dec: 193316642)
{
	long index; // size=0, offset=0 //  hashcode: 0xCD7B6F52 (dec: -847548590), parent name: 'AADLIB_122fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x5572AFDF (dec: 1433579487), parent name: 'AADLIB_122fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_123fake // hashcode: 0xADC4E662 (dec: -1379604894)
{
	long time;  // size=0, offset=0 //  hashcode: 0x74EF128F (dec: 1961824911), parent name: 'AADLIB_123fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x0B526BA8 (dec: 189950888), parent name: 'AADLIB_123fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_124fake // hashcode: 0xED6206C9 (dec: -312342839)
{
	long action;   // size=0, offset=0 //  hashcode: 0x74BE8ABD (dec: 1958644413), parent name: 'AADLIB_124fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x4193B343 (dec: 1100198723), parent name: 'AADLIB_124fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_125fake // hashcode: 0x160919E3 (dec: 369695203)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x457B1523 (dec: 1165694243), parent name: 'AADLIB_125fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x573326B2 (dec: 1462970034), parent name: 'AADLIB_125fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_126fake // hashcode: 0x7FA70BD5 (dec: 2141653973)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x60FA7BCD (dec: 1627028429), parent name: 'AADLIB_126fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x066E7291 (dec: 107901585), parent name: 'AADLIB_126fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_127fake // hashcode: 0x179191F5 (dec: 395416053)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x8A6391B2 (dec: -1973186126), parent name: 'AADLIB_127fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x11AE91F8 (dec: 296653304), parent name: 'AADLIB_127fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_128fake // hashcode: 0x0A303BEE (dec: 170933230)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x498E336D (dec: 1234056045), parent name: 'AADLIB_128fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x07195CF7 (dec: 119102711), parent name: 'AADLIB_128fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x7E4093CB (dec: 2118161355), parent name: 'AADLIB_128fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xCD4A330D (dec: -850775283), parent name: 'AADLIB_128fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x93AD810A (dec: -1817345782), parent name: 'AADLIB_128fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_129fake // hashcode: 0xA64B3FE7 (dec: -1505017881)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xB001B89A (dec: -1342064486), parent name: 'AADLIB_129fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x329730FE (dec: 848769278), parent name: 'AADLIB_129fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_130fake // hashcode: 0x0A8E1848 (dec: 177084488)
{
	short index;					// size=0, offset=0 //  hashcode: 0x5F108E30 (dec: 1594920496), parent name: 'AADLIB_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x07D5B28E (dec: 131445390), parent name: 'AADLIB_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xCE9927C6 (dec: -828823610), parent name: 'AADLIB_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xE33BC802 (dec: -482621438), parent name: 'AADLIB_130fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_131fake // hashcode: 0x0E7E0B04 (dec: 243141380)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xFABDC2B9 (dec: -88227143), parent name: 'AADLIB_131fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xEBA67B15 (dec: -341411051), parent name: 'AADLIB_131fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x70C986CB (dec: 1892255435), parent name: 'AADLIB_131fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_132fake // hashcode: 0x275A86A5 (dec: 660244133)
{
	char num;			   // size=0, offset=0 //  hashcode: 0xDCE99CA4 (dec: -588669788), parent name: 'AADLIB_132fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xE06DE68C (dec: -529668468), parent name: 'AADLIB_132fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xE84A92AA (dec: -397765974), parent name: 'AADLIB_132fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xE9CA1C19 (dec: -372630503), parent name: 'AADLIB_132fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0xB711754D (dec: -1223592627), parent name: 'AADLIB_132fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x964074F8 (dec: -1774160648), parent name: 'AADLIB_132fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x79F8056E (dec: 2046297454), parent name: 'AADLIB_132fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_133fake // hashcode: 0xD821A34E (dec: -668884146)
{
	long index;  // size=0, offset=0 //  hashcode: 0xD7789427 (dec: -679963609), parent name: 'AADLIB_133fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xD0F53B3E (dec: -789234882), parent name: 'AADLIB_133fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_134fake // hashcode: 0xC5A7DA2A (dec: -978855382)
{
	short type; // size=0, offset=0 //  hashcode: 0xDE715331 (dec: -562998479), parent name: 'AADLIB_134fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x2E6628DA (dec: 778447066), parent name: 'AADLIB_134fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_135fake // hashcode: 0xEBE3E68F (dec: -337385841)
{
	long time;   // size=0, offset=0 //  hashcode: 0x05742EC1 (dec: 91500225), parent name: 'AADLIB_135fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x51204D6F (dec: 1361071471), parent name: 'AADLIB_135fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_136fake // hashcode: 0x8B1F04DA (dec: -1960901414)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xA6E9DF1C (dec: -1494622436), parent name: 'AADLIB_136fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xC8074711 (dec: -939047151), parent name: 'AADLIB_136fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_137fake // hashcode: 0xBD881C0C (dec: -1115153396)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x20E1B528 (dec: 551662888), parent name: 'AADLIB_137fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x167723A7 (dec: 376906663), parent name: 'AADLIB_137fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_138fake // hashcode: 0x371CE36D (dec: 924640109)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x99BD8644 (dec: -1715632572), parent name: 'AADLIB_138fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x8176BF81 (dec: -2122924159), parent name: 'AADLIB_138fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_139fake // hashcode: 0x2CDE1EA8 (dec: 752754344)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x8239513E (dec: -2110172866), parent name: 'AADLIB_139fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xDF94980E (dec: -543909874), parent name: 'AADLIB_139fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xD38AFBE4 (dec: -745866268), parent name: 'AADLIB_139fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x3AEC7786 (dec: 988575622), parent name: 'AADLIB_139fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_140fake // hashcode: 0xCB64FF1F (dec: -882573537)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x8C1AB035 (dec: -1944408011), parent name: 'AADLIB_140fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xB247F535 (dec: -1303907019), parent name: 'AADLIB_140fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x7CCBEB6A (dec: 2093738858), parent name: 'AADLIB_140fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x357C51FD (dec: 897339901), parent name: 'AADLIB_140fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0xC08E34A7 (dec: -1064422233), parent name: 'AADLIB_140fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union AADLIB_141fake // Hashcode: 0x66F7C5F7 (dec: 1727514103)
{
	struct AADLIB_118fake misc[3];		// size=12, offset=0
	struct _CameraKey *cameraKey;		// size=24, offset=0
	struct AADLIB_119fake teleport;		// size=16, offset=0
	struct AADLIB_120fake cameraValue;  // size=8, offset=0
	struct AADLIB_121fake miscValue;	// size=8, offset=0
	struct AADLIB_122fake logicValue;   // size=8, offset=0
	long timer;							// size=0, offset=0
	long times;							// size=0, offset=0
	long lightGroup;					// size=0, offset=0
	long farPlane;						// size=0, offset=0
	long cameraAdjust;					// size=0, offset=0
	long cameraMode;					// size=0, offset=0
	long cameraLock;					// size=0, offset=0
	long cameraUnlock;					// size=0, offset=0
	long cameraSmooth;					// size=0, offset=0
	long cameraTimer;					// size=0, offset=0
	struct AADLIB_123fake cameraShake;  // size=8, offset=0
	long cameraSave;					// size=0, offset=0
	long cameraRestore;					// size=0, offset=0
	struct _BGObject *bgObject;			// size=24, offset=0
	long value[2];						// size=8, offset=0
	struct AADLIB_124fake sound;		// size=12, offset=0
	void *intro;						// size=0, offset=0
	long deathZ;						// size=0, offset=0
	struct AADLIB_125fake dsignal;		// size=8, offset=0
	void *mirror;						// size=0, offset=0
	long fogNear;						// size=0, offset=0
	long fogFar;						// size=0, offset=0
	struct AADLIB_126fake gotoFrame;	// size=8, offset=0
	struct AADLIB_127fake changeModel;  // size=8, offset=0
	void *vmObject;						// size=0, offset=0
	struct AADLIB_128fake logic;		// size=8, offset=0
	void *callSignal;					// size=0, offset=0
	struct _SVector offset;				// size=8, offset=0
	struct Signal *gotoLabel;			// size=0, offset=0
	struct Signal *gosubLabel;			// size=0, offset=0
	struct AADLIB_129fake control;		// size=8, offset=0
	struct AADLIB_130fake zSignal;		// size=12, offset=0
	struct AADLIB_131fake StreamLevel;  // size=24, offset=0
	struct AADLIB_132fake shards;		// size=12, offset=0
	struct AADLIB_133fake cameraSpline; // size=8, offset=0
	struct AADLIB_134fake screenWipe;   // size=4, offset=0
	long voiceSitId;					// size=0, offset=0
	struct AADLIB_135fake introFX;		// size=8, offset=0
	struct AADLIB_136fake introActive;  // size=8, offset=0
	struct AADLIB_137fake levelChange;  // size=18, offset=0
	long blendStart;					// size=0, offset=0
	struct AADLIB_138fake setTimes;		// size=8, offset=0
	struct AADLIB_139fake color;		// size=4, offset=0
	struct AADLIB_140fake print;		// size=12, offset=0
	long slideAngle;					// size=0, offset=0
};

union AADLIB_142fake // Hashcode: 0x2757AD36 (dec: 660057398)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union AADLIB_147fake // Hashcode: 0x77090075 (dec: 1997078645)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct AADLIB_149fake // hashcode: 0x5C4FB28B (dec: 1548726923)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xB2F00D90 (dec: -1292890736), parent name: 'AADLIB_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x6E19A307 (dec: 1847173895), parent name: 'AADLIB_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x13CC2B6D (dec: 332147565), parent name: 'AADLIB_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xC02D5B3E (dec: -1070769346), parent name: 'AADLIB_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0xBC9C38C9 (dec: -1130612535), parent name: 'AADLIB_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x64B0CD30 (dec: 1689308464), parent name: 'AADLIB_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0xF119A55F (dec: -249977505), parent name: 'AADLIB_149fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_150fake // hashcode: 0x676F650B (dec: 1735353611)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x9C936485 (dec: -1668062075), parent name: 'AADLIB_150fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x86E323A5 (dec: -2031934555), parent name: 'AADLIB_150fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x54CAA663 (dec: 1422567011), parent name: 'AADLIB_150fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_151fake // hashcode: 0x1A976FD7 (dec: 446132183)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x794A9DD2 (dec: 2034933202), parent name: 'AADLIB_151fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x750C8215 (dec: 1963754005), parent name: 'AADLIB_151fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xB96F8F63 (dec: -1183871133), parent name: 'AADLIB_151fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x1C616C3C (dec: 476146748), parent name: 'AADLIB_151fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xA01F1621 (dec: -1608575455), parent name: 'AADLIB_151fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_152fake // hashcode: 0x7B7ECFF8 (dec: 2071908344)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x73BA8BE3 (dec: 1941605347), parent name: 'AADLIB_152fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x9C25CAC5 (dec: -1675244859), parent name: 'AADLIB_152fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x43FF182F (dec: 1140791343), parent name: 'AADLIB_152fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x331C1200 (dec: 857477632), parent name: 'AADLIB_152fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x6FA5EEDB (dec: 1873145563), parent name: 'AADLIB_152fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AADLIB_153fake // hashcode: 0x95DB25F7 (dec: -1780800009)
{
	struct AADLIB_149fake Cinematic; // size=28, offset=0 //  hashcode: 0xAD68C091 (dec: -1385643887), parent name: 'AADLIB_153fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AADLIB_150fake Idle;		 // size=20, offset=28 //  hashcode: 0x201C1AB0 (dec: 538712752), parent name: 'AADLIB_153fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AADLIB_151fake Behind;	// size=28, offset=48 //  hashcode: 0x8383C5A3 (dec: -2088516189), parent name: 'AADLIB_153fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AADLIB_152fake Follow;	// size=20, offset=76 //  hashcode: 0x68659748 (dec: 1751488328), parent name: 'AADLIB_153fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union AADLIB_190fake // Hashcode: 0x9F6EB891 (dec: -1620133743)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

typedef struct AadMemoryStruct AadMemoryStruct;

typedef struct AadSlotAttributes AadSlotAttributes;

extern unsigned long aadGetMemorySize(struct AadInitAttr *attributes); // 0x800514D4

extern int aadInit(struct AadInitAttr *attributes, unsigned char *memoryPtr); // 0x800514F8

extern void aadInstallUpdateFunc(TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr updateFuncPtr, int hblanksPerUpdate); // 0x800517A0

extern void aadInitVolume(); // 0x8005181C

extern void aadSetMasterVolume(int volume); // 0x80051850

extern void aadStartMasterVolumeFade(int targetVolume, int volumeStep, TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback fadeCompleteCallback); // 0x80051880

extern void aadSetSfxMasterVolume(int volume); // 0x80051898

extern void aadSetMusicMasterVolume(int volume); // 0x800518A8

extern void aadStartMusicMasterVolFade(int targetVolume, int volumeStep, TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback fadeCompleteCallback); // 0x8005190C

extern void aadShutdown(); // 0x80051924

extern long aadSlotUpdateWrapper(); // 0x800519AC

extern void aadSlotUpdate(); // 0x800519F0

extern unsigned long aadCreateFourCharID(char a, char b, char c, char d); // 0x80051F38

extern int aadLoadDynamicSoundBank(char *sndFileName, char *smpFileName, int dynamicBankIndex, int loadOption, TDRFuncPtr_aadLoadDynamicSoundBank4retProc retProc); // 0x80051F60

extern void aadLoadDynamicSoundBankReturn(void *loadedDataPtr, void *data, void *data2); // 0x800520B8

extern void aadLoadDynamicSoundBankReturn2(void *loadedDataPtr, long loadedDataSize, short status, void *data1, void *data2); // 0x80052188

extern int aadFreeDynamicSoundBank(int dynamicBankIndex); // 0x800523B4

extern int aadOpenDynamicSoundBank(unsigned char *soundBank, int dynamicBankIndex); // 0x80052430

extern int aadLoadDynamicSfx(char *fileName, long directoryID, long flags); // 0x80052550

extern int aadFreeDynamicSfx(int handle); // 0x80052604

extern void aadRelocateMusicMemoryBegin(); // 0x800526E0

extern void aadRelocateMusicMemoryEnd(struct MemHeader *newAddress, long offset, void *oldAddress); // 0x800526FC

extern void aadRelocateSfxMemory(void *oldAddress, int offset); // 0x80052924

extern int aadGetNumLoadsQueued(); // 0x8005298C

extern void aadPurgeLoadQueue(); // 0x800529A0

extern void aadProcessLoadQueue(); // 0x800529B8

extern void aadLoadDynamicSfxAbort(struct AadDynamicSfxLoadInfo *info, int error); // 0x80052CF8

extern void aadLoadDynamicSfxDone(struct AadDynamicSfxLoadInfo *info); // 0x80052D7C

extern void aadLoadDynamicSfxReturn(void *loadedDataPtr, void *data, void *data2); // 0x80052D84

extern int aadWaveMalloc(unsigned short waveID, unsigned long waveSize); // 0x80052EFC

extern unsigned long aadGetSramBlockAddr(int handle); // 0x80053144

extern void aadWaveFree(int handle); // 0x80053170

extern void aadFreeSingleDynSfx(int sfxID); // 0x80053280

extern void setSramFullAlarm(); // 0x80053348

extern void aadLoadSingleDynSfx(struct AadDynamicSfxLoadInfo *info); // 0x80053424

extern void HackCallback(); // 0x800536F4

extern void aadLoadDynamicSfxReturn2(void *loadedDataPtr, long loadedDataSize, short status, void *data1, void *data2); // 0x8005372C

extern int aadCheckSramFragmented(); // 0x800539F4

extern void aadProcessSramDefrag(); // 0x80053AA8

extern int aadIsSfxLoaded(unsigned int toneID); // 0x80053E0C

extern void aadInitSequenceSlot(struct _AadSequenceSlot *slot); // 0x80053E48

extern int aadWaitForSramTransferComplete(); // 0x80053F54

extern void aadInitReverb(); // 0x80053F94

extern void aadShutdownReverb(); // 0x80054018

extern int aadGetReverbMode(); // 0x80054050

extern unsigned long aadGetReverbSize(); // 0x80054058

extern int aadGetReverbDepth(); // 0x80054088

extern int aadGetNumDynamicSequences(int bank); // 0x80054090

extern int aadAssignDynamicSequence(int bank, int sequenceNumber, int slotNumber); // 0x800540C0

extern struct AadTempo *aadGetTempoFromDynamicSequence(int bank, int sequenceNumber, struct AadTempo *tempo); // 0x8005419C

extern void aadSetSlotTempo(int slotNumber, struct AadTempo *tempo); // 0x800541EC

extern void aadStartSlot(int slotNumber); // 0x800542A0

extern void aadStopSlot(int slotNumber); // 0x8005431C

extern void aadStopAllSlots(); // 0x80054388

extern void aadDisableSlot(int slotNumber); // 0x80054418

extern void aadEnableSlot(int slotNumber); // 0x80054468

extern void aadPauseSlot(int slotNumber); // 0x800544A8

extern void aadResumeSlot(int slotNumber); // 0x800544F8

extern int aadGetSlotStatus(int slotNumber); // 0x80054568

extern void aadAllNotesOff(int slotNumber); // 0x80054588

extern void aadMuteChannels(struct _AadSequenceSlot *slot, unsigned long channelList); // 0x80054628

extern void aadUnMuteChannels(struct _AadSequenceSlot *slot, unsigned long channelList); // 0x80054704

extern TDRFuncPtr_aadInstallEndSequenceCallback aadInstallEndSequenceCallback(TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc callbackProc, long data); // 0x8005473C

extern void aadSetUserVariable(int variableNumber, int value); // 0x80054754

extern void aadSetNoUpdateMode(int noUpdate); // 0x80054768

extern void aadPauseSound(); // 0x800547A8

extern void aadCancelPauseSound(); // 0x80054840

extern void aadResumeSound(); // 0x8005485C

typedef long (*TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr)();

typedef void (*TDRFuncPtr_aadInstallEndSequenceCallback)();

typedef void (*TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc)();

typedef void (*TDRFuncPtr_aadLoadDynamicSoundBank4retProc)();

typedef void (*TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback)();

typedef void (*TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)();

#endif
