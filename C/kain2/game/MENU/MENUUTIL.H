#ifndef MENUUTIL_H
#define MENUUTIL_H

static struct menu_sound_entry_t the_menu_sounds[6]; // offset 0x800CAD98

struct MENUUTIL_68fake // hashcode: 0x2466E360 (dec: 610722656)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x4006CF5B (dec: 1074188123), parent name: 'MENUUTIL_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0xCE18FCC1 (dec: -837223231), parent name: 'MENUUTIL_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_69fake // hashcode: 0xCE0A09C0 (dec: -838202944)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x826216C8 (dec: -2107500856), parent name: 'MENUUTIL_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x53C500DA (dec: 1405419738), parent name: 'MENUUTIL_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_70fake // hashcode: 0x8DD94E0C (dec: -1915138548)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x42ED4EC7 (dec: 1122848455), parent name: 'MENUUTIL_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xAC8B8FA8 (dec: -1400139864), parent name: 'MENUUTIL_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MENUUTIL_71fake // Hashcode: 0x6C5644DB (dec: 1817593051)
{
	struct MENUUTIL_68fake callback; // size=8, offset=0
	struct MENUUTIL_69fake vector;   // size=12, offset=0
	struct MENUUTIL_70fake quat;	 // size=16, offset=0
};

union MENUUTIL_72fake // Hashcode: 0x9906017D (dec: -1727659651)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MENUUTIL_73fake // Hashcode: 0x092A4FD0 (dec: 153767888)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct MENUUTIL_74fake // hashcode: 0x4BEB62B4 (dec: 1273717428)
{
	union MENUUTIL_73fake size; // size=4, offset=0 //  hashcode: 0x4ACB420B (dec: 1254834699), parent name: 'MENUUTIL_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_75fake // hashcode: 0xA1A2ACC2 (dec: -1583174462)
{
	short x;				// size=0, offset=0 //  hashcode: 0x9F793B01 (dec: -1619444991), parent name: 'MENUUTIL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x72EACF09 (dec: 1927991049), parent name: 'MENUUTIL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xE7E47831 (dec: -404457423), parent name: 'MENUUTIL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x0AA0A2CD (dec: 178299597), parent name: 'MENUUTIL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xCF60117D (dec: -815787651), parent name: 'MENUUTIL_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_76fake // hashcode: 0x4D5E6B85 (dec: 1298033541)
{
	long index; // size=0, offset=0 //  hashcode: 0x1D1A2BE6 (dec: 488254438), parent name: 'MENUUTIL_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x9C6A6271 (dec: -1670749583), parent name: 'MENUUTIL_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_77fake // hashcode: 0xBFD4E203 (dec: -1076567549)
{
	long index; // size=0, offset=0 //  hashcode: 0xE389F3CC (dec: -477498420), parent name: 'MENUUTIL_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xD593494C (dec: -711767732), parent name: 'MENUUTIL_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_78fake // hashcode: 0xA7CAD4A7 (dec: -1479879513)
{
	long index; // size=0, offset=0 //  hashcode: 0x9ADC57D2 (dec: -1696835630), parent name: 'MENUUTIL_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xB1395046 (dec: -1321643962), parent name: 'MENUUTIL_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_79fake // hashcode: 0xE1B8EA64 (dec: -507975068)
{
	long time;  // size=0, offset=0 //  hashcode: 0x9A72823C (dec: -1703771588), parent name: 'MENUUTIL_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0x787C4149 (dec: 2021409097), parent name: 'MENUUTIL_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_80fake // hashcode: 0x5305DE0F (dec: 1392893455)
{
	long action;   // size=0, offset=0 //  hashcode: 0xA50FE8F5 (dec: -1525683979), parent name: 'MENUUTIL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xB9E83539 (dec: -1175964359), parent name: 'MENUUTIL_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_81fake // hashcode: 0x82695F4F (dec: -2107023537)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x93F72A93 (dec: -1812518253), parent name: 'MENUUTIL_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x5FC61D6E (dec: 1606819182), parent name: 'MENUUTIL_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_82fake // hashcode: 0x8FF67AF9 (dec: -1879672071)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x6DE8284E (dec: 1843931214), parent name: 'MENUUTIL_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x15EE42FD (dec: 367936253), parent name: 'MENUUTIL_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_83fake // hashcode: 0xDAD18263 (dec: -623803805)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x1F4C348C (dec: 525087884), parent name: 'MENUUTIL_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x24E4339B (dec: 618935195), parent name: 'MENUUTIL_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_84fake // hashcode: 0x6BD523DC (dec: 1809130460)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x1EE85AAD (dec: 518544045), parent name: 'MENUUTIL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xF9AC39FE (dec: -106153474), parent name: 'MENUUTIL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x992DD46A (dec: -1725049750), parent name: 'MENUUTIL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xC905694C (dec: -922392244), parent name: 'MENUUTIL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x80ADF8CA (dec: -2136082230), parent name: 'MENUUTIL_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_85fake // hashcode: 0x5BEEAFC1 (dec: 1542369217)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xFC35DAC2 (dec: -63579454), parent name: 'MENUUTIL_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x70781564 (dec: 1886917988), parent name: 'MENUUTIL_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_86fake // hashcode: 0x965A6309 (dec: -1772461303)
{
	short index;					// size=0, offset=0 //  hashcode: 0x6876505C (dec: 1752584284), parent name: 'MENUUTIL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x404BC6EE (dec: 1078707950), parent name: 'MENUUTIL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x6431BA7A (dec: 1680980602), parent name: 'MENUUTIL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x1ED37062 (dec: 517173346), parent name: 'MENUUTIL_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_87fake // hashcode: 0xCFE0A489 (dec: -807361399)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xE1336758 (dec: -516724904), parent name: 'MENUUTIL_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xD31A6515 (dec: -753244907), parent name: 'MENUUTIL_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xB54A3CCF (dec: -1253425969), parent name: 'MENUUTIL_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_88fake // hashcode: 0xEDFB583B (dec: -302294981)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x6F7ADD36 (dec: 1870322998), parent name: 'MENUUTIL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x7F89F701 (dec: 2139748097), parent name: 'MENUUTIL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x4C82C63F (dec: 1283638847), parent name: 'MENUUTIL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x7106A9BF (dec: 1896262079), parent name: 'MENUUTIL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x0BFFA4B5 (dec: 201303221), parent name: 'MENUUTIL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xAD0D79C3 (dec: -1391625789), parent name: 'MENUUTIL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x09A44AEE (dec: 161762030), parent name: 'MENUUTIL_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_89fake // hashcode: 0x9EA50B88 (dec: -1633350776)
{
	long index;  // size=0, offset=0 //  hashcode: 0x00D4A21C (dec: 13935132), parent name: 'MENUUTIL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0xCAB2BC9B (dec: -894255973), parent name: 'MENUUTIL_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_90fake // hashcode: 0xA1DE7BAA (dec: -1579254870)
{
	short type; // size=0, offset=0 //  hashcode: 0x523929CA (dec: 1379477962), parent name: 'MENUUTIL_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x44E71F1A (dec: 1155997466), parent name: 'MENUUTIL_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_91fake // hashcode: 0xF3BCC959 (dec: -205731495)
{
	long time;   // size=0, offset=0 //  hashcode: 0xC15500E3 (dec: -1051393821), parent name: 'MENUUTIL_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x9185B1DF (dec: -1853509153), parent name: 'MENUUTIL_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_92fake // hashcode: 0x18729401 (dec: 410162177)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xF83D0478 (dec: -130218888), parent name: 'MENUUTIL_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xC8EE9D24 (dec: -923886300), parent name: 'MENUUTIL_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_93fake // hashcode: 0x4C2BC60F (dec: 1277937167)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xB36432FC (dec: -1285278980), parent name: 'MENUUTIL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x26DA6315 (dec: 651846421), parent name: 'MENUUTIL_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_94fake // hashcode: 0x15D10E18 (dec: 366022168)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xA206DFD5 (dec: -1576607787), parent name: 'MENUUTIL_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x0EF24461 (dec: 250758241), parent name: 'MENUUTIL_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_95fake // hashcode: 0xA41661C9 (dec: -1542037047)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x5EE18131 (dec: 1591836977), parent name: 'MENUUTIL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0xB6C8839D (dec: -1228373091), parent name: 'MENUUTIL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x1D3A90BB (dec: 490377403), parent name: 'MENUUTIL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x14ABDEFA (dec: 346808058), parent name: 'MENUUTIL_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_96fake // hashcode: 0x13F4CADB (dec: 334809819)
{
	short x;	 // size=0, offset=0 //  hashcode: 0xBE0206F9 (dec: -1107163399), parent name: 'MENUUTIL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x7AECB6C3 (dec: 2062333635), parent name: 'MENUUTIL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xF3EBAE6E (dec: -202658194), parent name: 'MENUUTIL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0xAFC9148D (dec: -1345776499), parent name: 'MENUUTIL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x20C9896F (dec: 550078831), parent name: 'MENUUTIL_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MENUUTIL_97fake // Hashcode: 0xD3570AA2 (dec: -749270366)
{
	struct MENUUTIL_74fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;		 // size=24, offset=0
	struct MENUUTIL_75fake teleport;	 // size=16, offset=0
	struct MENUUTIL_76fake cameraValue;  // size=8, offset=0
	struct MENUUTIL_77fake miscValue;	// size=8, offset=0
	struct MENUUTIL_78fake logicValue;   // size=8, offset=0
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
	struct MENUUTIL_79fake cameraShake;  // size=8, offset=0
	long cameraSave;					 // size=0, offset=0
	long cameraRestore;					 // size=0, offset=0
	struct _BGObject *bgObject;			 // size=24, offset=0
	long value[2];						 // size=8, offset=0
	struct MENUUTIL_80fake sound;		 // size=12, offset=0
	void *intro;						 // size=0, offset=0
	long deathZ;						 // size=0, offset=0
	struct MENUUTIL_81fake dsignal;		 // size=8, offset=0
	void *mirror;						 // size=0, offset=0
	long fogNear;						 // size=0, offset=0
	long fogFar;						 // size=0, offset=0
	struct MENUUTIL_82fake gotoFrame;	// size=8, offset=0
	struct MENUUTIL_83fake changeModel;  // size=8, offset=0
	void *vmObject;						 // size=0, offset=0
	struct MENUUTIL_84fake logic;		 // size=8, offset=0
	void *callSignal;					 // size=0, offset=0
	struct _SVector offset;				 // size=8, offset=0
	struct Signal *gotoLabel;			 // size=0, offset=0
	struct Signal *gosubLabel;			 // size=0, offset=0
	struct MENUUTIL_85fake control;		 // size=8, offset=0
	struct MENUUTIL_86fake zSignal;		 // size=12, offset=0
	struct MENUUTIL_87fake StreamLevel;  // size=24, offset=0
	struct MENUUTIL_88fake shards;		 // size=12, offset=0
	struct MENUUTIL_89fake cameraSpline; // size=8, offset=0
	struct MENUUTIL_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;					 // size=0, offset=0
	struct MENUUTIL_91fake introFX;		 // size=8, offset=0
	struct MENUUTIL_92fake introActive;  // size=8, offset=0
	struct MENUUTIL_93fake levelChange;  // size=18, offset=0
	long blendStart;					 // size=0, offset=0
	struct MENUUTIL_94fake setTimes;	 // size=8, offset=0
	struct MENUUTIL_95fake color;		 // size=4, offset=0
	struct MENUUTIL_96fake print;		 // size=12, offset=0
	long slideAngle;					 // size=0, offset=0
};

union MENUUTIL_98fake // Hashcode: 0x50357424 (dec: 1345680420)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union MENUUTIL_103fake // Hashcode: 0xEC62A6FF (dec: -329079041)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct MENUUTIL_105fake // hashcode: 0x80A9F4B3 (dec: -2136345421)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0xE8CD6830 (dec: -389191632), parent name: 'MENUUTIL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x955104CC (dec: -1789852468), parent name: 'MENUUTIL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0xD74C2359 (dec: -682876071), parent name: 'MENUUTIL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x66C7D28A (dec: 1724371594), parent name: 'MENUUTIL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0xDF8C516F (dec: -544452241), parent name: 'MENUUTIL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x62BB2C73 (dec: 1656433779), parent name: 'MENUUTIL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x307DADDC (dec: 813542876), parent name: 'MENUUTIL_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_106fake // hashcode: 0x63B04C53 (dec: 1672498259)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x627A2737 (dec: 1652172599), parent name: 'MENUUTIL_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x36F55B21 (dec: 922049313), parent name: 'MENUUTIL_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x98415822 (dec: -1740548062), parent name: 'MENUUTIL_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_107fake // hashcode: 0xF3BDF72C (dec: -205654228)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x9F4F0B02 (dec: -1622209790), parent name: 'MENUUTIL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0xF856C1D0 (dec: -128532016), parent name: 'MENUUTIL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0xCC9ECFE0 (dec: -862007328), parent name: 'MENUUTIL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x619A03AD (dec: 1637483437), parent name: 'MENUUTIL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x79C45821 (dec: 2042910753), parent name: 'MENUUTIL_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_108fake // hashcode: 0x7A4446AC (dec: 2051294892)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x79626C8D (dec: 2036493453), parent name: 'MENUUTIL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x3930FE65 (dec: 959512165), parent name: 'MENUUTIL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x30C9FF53 (dec: 818544467), parent name: 'MENUUTIL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x77BFD43B (dec: 2009060411), parent name: 'MENUUTIL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x2CADD1EF (dec: 749588975), parent name: 'MENUUTIL_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MENUUTIL_109fake // hashcode: 0x36B25773 (dec: 917657459)
{
	struct MENUUTIL_105fake Cinematic; // size=28, offset=0 //  hashcode: 0x070F8974 (dec: 118458740), parent name: 'MENUUTIL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MENUUTIL_106fake Idle;	  // size=20, offset=28 //  hashcode: 0xBFD9BB91 (dec: -1076249711), parent name: 'MENUUTIL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MENUUTIL_107fake Behind;	// size=28, offset=48 //  hashcode: 0xA0EF24B1 (dec: -1594940239), parent name: 'MENUUTIL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MENUUTIL_108fake Follow;	// size=20, offset=76 //  hashcode: 0x254BEC1F (dec: 625732639), parent name: 'MENUUTIL_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct menu_sound_entry_t // hashcode: 0xFFB1DFB2 (dec: -5120078)
{
	enum menu_sound_t sound; // size=4, offset=0 //  hashcode: 0xF4C87358 (dec: -188189864), parent name: 'menu_sound_entry_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int sfx;				 // size=0, offset=4 //  hashcode: 0x4F0F0B22 (dec: 1326385954), parent name: 'menu_sound_entry_t', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct menu_sound_entry_t menu_sound_entry_t;

extern enum menu_ctrl_t menu_get_ctrl(void *gt); // 0x800B87FC

extern void menu_print(int xpos, int ypos, char *text, int color); // 0x800B887C

extern int menu_text_width(char *text); // 0x800B88E4

extern void menu_sound(enum menu_sound_t sound); // 0x800B8904

#endif
