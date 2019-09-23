#ifndef PHYSOBS_H
#define PHYSOBS_H

struct PHYSOBS_68fake // hashcode: 0x657706ED (dec: 1702299373)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x193816A0 (dec: 423106208), parent name: 'PHYSOBS_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x6F3DC038 (dec: 1866317880), parent name: 'PHYSOBS_68fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_69fake // hashcode: 0x6CEF5793 (dec: 1827624851)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0xA178D722 (dec: -1585916126), parent name: 'PHYSOBS_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xA1A96C72 (dec: -1582732174), parent name: 'PHYSOBS_69fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_70fake // hashcode: 0x4E7C6BB2 (dec: 1316776882)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x1A36194E (dec: 439753038), parent name: 'PHYSOBS_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xED35F9A8 (dec: -315229784), parent name: 'PHYSOBS_70fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PHYSOBS_71fake // Hashcode: 0xF2195964 (dec: -233219740)
{
	struct PHYSOBS_68fake callback; // size=8, offset=0
	struct PHYSOBS_69fake vector;   // size=12, offset=0
	struct PHYSOBS_70fake quat;		// size=16, offset=0
};

union PHYSOBS_72fake // Hashcode: 0x97A84143 (dec: -1750580925)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PHYSOBS_73fake // Hashcode: 0xD3FF606C (dec: -738238356)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct PHYSOBS_74fake // hashcode: 0xC5748BD4 (dec: -982217772)
{
	union PHYSOBS_73fake size; // size=4, offset=0 //  hashcode: 0x6D0868F8 (dec: 1829267704), parent name: 'PHYSOBS_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_75fake // hashcode: 0x0566F3CA (dec: 90633162)
{
	short x;				// size=0, offset=0 //  hashcode: 0xDAADBA2E (dec: -626148818), parent name: 'PHYSOBS_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0xCEDED630 (dec: -824256976), parent name: 'PHYSOBS_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x8A7EC6F9 (dec: -1971403015), parent name: 'PHYSOBS_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0xB1B5D1A9 (dec: -1313484375), parent name: 'PHYSOBS_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0xF034BC21 (dec: -264979423), parent name: 'PHYSOBS_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_76fake // hashcode: 0x690AFC31 (dec: 1762327601)
{
	long index; // size=0, offset=0 //  hashcode: 0x127A97BA (dec: 310024122), parent name: 'PHYSOBS_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x15F75924 (dec: 368531748), parent name: 'PHYSOBS_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_77fake // hashcode: 0x6A2E62E5 (dec: 1781424869)
{
	long index; // size=0, offset=0 //  hashcode: 0x74BEB300 (dec: 1958654720), parent name: 'PHYSOBS_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x325F836C (dec: 845120364), parent name: 'PHYSOBS_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_78fake // hashcode: 0x511D9153 (dec: 1360892243)
{
	long index; // size=0, offset=0 //  hashcode: 0xCC8756FB (dec: -863545605), parent name: 'PHYSOBS_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xB43A3CB2 (dec: -1271251790), parent name: 'PHYSOBS_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_79fake // hashcode: 0x940487DC (dec: -1811642404)
{
	long time;  // size=0, offset=0 //  hashcode: 0xDE0CEFDD (dec: -569577507), parent name: 'PHYSOBS_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xAEDF69C4 (dec: -1361090108), parent name: 'PHYSOBS_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_80fake // hashcode: 0x4A292982 (dec: 1244211586)
{
	long action;   // size=0, offset=0 //  hashcode: 0x18C5E1B6 (dec: 415621558), parent name: 'PHYSOBS_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0xAAEDB039 (dec: -1427263431), parent name: 'PHYSOBS_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_81fake // hashcode: 0x4CA6006C (dec: 1285947500)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x2DD39C37 (dec: 768842807), parent name: 'PHYSOBS_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xDA5CD460 (dec: -631450528), parent name: 'PHYSOBS_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_82fake // hashcode: 0xC278A050 (dec: -1032282032)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x219E46DA (dec: 564020954), parent name: 'PHYSOBS_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x699C6795 (dec: 1771857813), parent name: 'PHYSOBS_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_83fake // hashcode: 0x38C7C8E0 (dec: 952617184)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x66CE545E (dec: 1724798046), parent name: 'PHYSOBS_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x3BB81285 (dec: 1001919109), parent name: 'PHYSOBS_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_84fake // hashcode: 0x9151D344 (dec: -1856908476)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xDAF4EB3C (dec: -621483204), parent name: 'PHYSOBS_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0xB9CF6E16 (dec: -1177588202), parent name: 'PHYSOBS_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0x077574DF (dec: 125138143), parent name: 'PHYSOBS_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0xFD5A0E46 (dec: -44429754), parent name: 'PHYSOBS_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x848E58A7 (dec: -2071045977), parent name: 'PHYSOBS_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_85fake // hashcode: 0x680EFF39 (dec: 1745813305)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xB84A70E1 (dec: -1203080991), parent name: 'PHYSOBS_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0xDBC1A54A (dec: -608066230), parent name: 'PHYSOBS_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_86fake // hashcode: 0x0922452F (dec: 153240879)
{
	short index;					// size=0, offset=0 //  hashcode: 0x918E805C (dec: -1852932004), parent name: 'PHYSOBS_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x889D81D1 (dec: -2002943535), parent name: 'PHYSOBS_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xFC1BC18A (dec: -65289846), parent name: 'PHYSOBS_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xAEC65606 (dec: -1362733562), parent name: 'PHYSOBS_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_87fake // hashcode: 0x76C29C4D (dec: 1992465485)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x69CA8B79 (dec: 1774881657), parent name: 'PHYSOBS_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0xB1D6F376 (dec: -1311313034), parent name: 'PHYSOBS_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x1A89A9D7 (dec: 445229527), parent name: 'PHYSOBS_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_88fake // hashcode: 0x169505E5 (dec: 378865125)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x5B53A282 (dec: 1532207746), parent name: 'PHYSOBS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x253B1E51 (dec: 624631377), parent name: 'PHYSOBS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x6708ECA3 (dec: 1728638115), parent name: 'PHYSOBS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xB4DFD958 (dec: -1260398248), parent name: 'PHYSOBS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x805E522D (dec: -2141302227), parent name: 'PHYSOBS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x043D06C3 (dec: 71108291), parent name: 'PHYSOBS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0xFB4FE1C9 (dec: -78650935), parent name: 'PHYSOBS_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_89fake // hashcode: 0xB4F95DB8 (dec: -1258725960)
{
	long index;  // size=0, offset=0 //  hashcode: 0x8A7D2460 (dec: -1971510176), parent name: 'PHYSOBS_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x3D7EF39C (dec: 1031730076), parent name: 'PHYSOBS_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_90fake // hashcode: 0x32E1DEF2 (dec: 853663474)
{
	short type; // size=0, offset=0 //  hashcode: 0xD426A7CD (dec: -735664179), parent name: 'PHYSOBS_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x46DE7167 (dec: 1188983143), parent name: 'PHYSOBS_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_91fake // hashcode: 0xA9B6B6E2 (dec: -1447643422)
{
	long time;   // size=0, offset=0 //  hashcode: 0x441BB3E3 (dec: 1142666211), parent name: 'PHYSOBS_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x522ED633 (dec: 1378801203), parent name: 'PHYSOBS_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_92fake // hashcode: 0x7E8457A0 (dec: 2122602400)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x2026ECA2 (dec: 539421858), parent name: 'PHYSOBS_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x956BF130 (dec: -1788088016), parent name: 'PHYSOBS_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_93fake // hashcode: 0x5033734C (dec: 1345549132)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xAB20E314 (dec: -1423908076), parent name: 'PHYSOBS_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0xB7C1CF07 (dec: -1212035321), parent name: 'PHYSOBS_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_94fake // hashcode: 0x070131EB (dec: 117518827)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x6DF18B93 (dec: 1844546451), parent name: 'PHYSOBS_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0x917A2296 (dec: -1854266730), parent name: 'PHYSOBS_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_95fake // hashcode: 0x7A76CDCA (dec: 2054606282)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0xEC652FE1 (dec: -328912927), parent name: 'PHYSOBS_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x03D88BA6 (dec: 64523174), parent name: 'PHYSOBS_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0x06EFCBAD (dec: 116378541), parent name: 'PHYSOBS_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xB63315D5 (dec: -1238166059), parent name: 'PHYSOBS_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_96fake // hashcode: 0xAEBB3A26 (dec: -1363461594)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x6750EFF8 (dec: 1733357560), parent name: 'PHYSOBS_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xE876B9FD (dec: -394872323), parent name: 'PHYSOBS_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x65225B6E (dec: 1696750446), parent name: 'PHYSOBS_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x156D6778 (dec: 359491448), parent name: 'PHYSOBS_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x1A3EB1FF (dec: 440316415), parent name: 'PHYSOBS_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PHYSOBS_97fake // Hashcode: 0xDE00BE59 (dec: -570376615)
{
	struct PHYSOBS_74fake misc[3];		// size=12, offset=0
	struct _CameraKey *cameraKey;		// size=24, offset=0
	struct PHYSOBS_75fake teleport;		// size=16, offset=0
	struct PHYSOBS_76fake cameraValue;  // size=8, offset=0
	struct PHYSOBS_77fake miscValue;	// size=8, offset=0
	struct PHYSOBS_78fake logicValue;   // size=8, offset=0
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
	struct PHYSOBS_79fake cameraShake;  // size=8, offset=0
	long cameraSave;					// size=0, offset=0
	long cameraRestore;					// size=0, offset=0
	struct _BGObject *bgObject;			// size=24, offset=0
	long value[2];						// size=8, offset=0
	struct PHYSOBS_80fake sound;		// size=12, offset=0
	void *intro;						// size=0, offset=0
	long deathZ;						// size=0, offset=0
	struct PHYSOBS_81fake dsignal;		// size=8, offset=0
	void *mirror;						// size=0, offset=0
	long fogNear;						// size=0, offset=0
	long fogFar;						// size=0, offset=0
	struct PHYSOBS_82fake gotoFrame;	// size=8, offset=0
	struct PHYSOBS_83fake changeModel;  // size=8, offset=0
	void *vmObject;						// size=0, offset=0
	struct PHYSOBS_84fake logic;		// size=8, offset=0
	void *callSignal;					// size=0, offset=0
	struct _SVector offset;				// size=8, offset=0
	struct Signal *gotoLabel;			// size=0, offset=0
	struct Signal *gosubLabel;			// size=0, offset=0
	struct PHYSOBS_85fake control;		// size=8, offset=0
	struct PHYSOBS_86fake zSignal;		// size=12, offset=0
	struct PHYSOBS_87fake StreamLevel;  // size=24, offset=0
	struct PHYSOBS_88fake shards;		// size=12, offset=0
	struct PHYSOBS_89fake cameraSpline; // size=8, offset=0
	struct PHYSOBS_90fake screenWipe;   // size=4, offset=0
	long voiceSitId;					// size=0, offset=0
	struct PHYSOBS_91fake introFX;		// size=8, offset=0
	struct PHYSOBS_92fake introActive;  // size=8, offset=0
	struct PHYSOBS_93fake levelChange;  // size=18, offset=0
	long blendStart;					// size=0, offset=0
	struct PHYSOBS_94fake setTimes;		// size=8, offset=0
	struct PHYSOBS_95fake color;		// size=4, offset=0
	struct PHYSOBS_96fake print;		// size=12, offset=0
	long slideAngle;					// size=0, offset=0
};

union PHYSOBS_98fake // Hashcode: 0x62692E58 (dec: 1651060312)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union PHYSOBS_103fake // Hashcode: 0xC47A6271 (dec: -998612367)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct PHYSOBS_105fake // hashcode: 0x75E6BACC (dec: 1978055372)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x4B6015CC (dec: 1264588236), parent name: 'PHYSOBS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x7706743B (dec: 1996911675), parent name: 'PHYSOBS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x03422F54 (dec: 54669140), parent name: 'PHYSOBS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xC9A832AA (dec: -911723862), parent name: 'PHYSOBS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x95DB088B (dec: -1780807541), parent name: 'PHYSOBS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x17ED3DAF (dec: 401423791), parent name: 'PHYSOBS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x22667D08 (dec: 577142024), parent name: 'PHYSOBS_105fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_106fake // hashcode: 0xF55E23D3 (dec: -178379821)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x20914F66 (dec: 546393958), parent name: 'PHYSOBS_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x50087E65 (dec: 1342733925), parent name: 'PHYSOBS_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0xFCC6DBA2 (dec: -54076510), parent name: 'PHYSOBS_106fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_107fake // hashcode: 0x8EF10440 (dec: -1896807360)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x8E3CB17F (dec: -1908625025), parent name: 'PHYSOBS_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x847AE984 (dec: -2072319612), parent name: 'PHYSOBS_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x989BAD6D (dec: -1734627987), parent name: 'PHYSOBS_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0xD342F190 (dec: -750587504), parent name: 'PHYSOBS_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0xA7D3B742 (dec: -1479297214), parent name: 'PHYSOBS_107fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_108fake // hashcode: 0x7243F9CF (dec: 1917057487)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x7B124FED (dec: 2064797677), parent name: 'PHYSOBS_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x4206D641 (dec: 1107744321), parent name: 'PHYSOBS_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x44BE05B9 (dec: 1153303993), parent name: 'PHYSOBS_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x7056FDB7 (dec: 1884749239), parent name: 'PHYSOBS_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xD3F5DA77 (dec: -738862473), parent name: 'PHYSOBS_108fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_109fake // hashcode: 0x64BC6ACF (dec: 1690069711)
{
	struct PHYSOBS_105fake Cinematic; // size=28, offset=0 //  hashcode: 0x985D389E (dec: -1738721122), parent name: 'PHYSOBS_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PHYSOBS_106fake Idle;	  // size=20, offset=28 //  hashcode: 0x260FC0AC (dec: 638566572), parent name: 'PHYSOBS_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PHYSOBS_107fake Behind;	// size=28, offset=48 //  hashcode: 0x1FA6384E (dec: 530987086), parent name: 'PHYSOBS_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PHYSOBS_108fake Follow;	// size=20, offset=76 //  hashcode: 0x2F7D6B92 (dec: 796748690), parent name: 'PHYSOBS_109fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evObjectData // hashcode: 0xE261F276 (dec: -496897418)
{
	short x;				 // size=0, offset=0 //  hashcode: 0xAC9B113D (dec: -1399123651), parent name: 'evObjectData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				 // size=0, offset=2 //  hashcode: 0x6BA49AF5 (dec: 1805949685), parent name: 'evObjectData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short PathNumber;		 // size=0, offset=4 //  hashcode: 0xE2C2630A (dec: -490577142), parent name: 'evObjectData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short LinkNode;			 // size=0, offset=6 //  hashcode: 0x57841C8A (dec: 1468275850), parent name: 'evObjectData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *Force; // size=616, offset=8 //  hashcode: 0x6DCFE7C6 (dec: 1842341830), parent name: 'evObjectData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int rc;					 // size=0, offset=12 //  hashcode: 0x577775AA (dec: 1467446698), parent name: 'evObjectData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evPhysicsGravityData // hashcode: 0xD13BDF0D (dec: -784605427)
{
	short UpperOffset; // size=0, offset=0 //  hashcode: 0x80AA34B6 (dec: -2136329034), parent name: 'evPhysicsGravityData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short LowerOffset; // size=0, offset=2 //  hashcode: 0x58CCB760 (dec: 1489811296), parent name: 'evPhysicsGravityData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x;		   // size=0, offset=4 //  hashcode: 0x6B49FFEF (dec: 1800011759), parent name: 'evPhysicsGravityData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;		   // size=0, offset=6 //  hashcode: 0x99D0A2B9 (dec: -1714380103), parent name: 'evPhysicsGravityData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;		   // size=0, offset=8 //  hashcode: 0x938BFB33 (dec: -1819542733), parent name: 'evPhysicsGravityData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short slipSlope;   // size=0, offset=10 //  hashcode: 0x770C72F3 (dec: 1997304563), parent name: 'evPhysicsGravityData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evPhysicsSlideData // hashcode: 0x42A65F7B (dec: 1118199675)
{
	struct _SVector ForwardVector;   // size=8, offset=0 //  hashcode: 0x7EE84ECC (dec: 2129153740), parent name: 'evPhysicsSlideData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector ForwardNormal;   // size=8, offset=8 //  hashcode: 0xB4186BD0 (dec: -1273467952), parent name: 'evPhysicsSlideData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector DropNormal;		 // size=8, offset=16 //  hashcode: 0x2DF6C7DF (dec: 771147743), parent name: 'evPhysicsSlideData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Segment;					 // size=0, offset=24 //  hashcode: 0x861DB2C6 (dec: -2044874042), parent name: 'evPhysicsSlideData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short DropOffset;				 // size=0, offset=26 //  hashcode: 0xC7681CB6 (dec: -949478218), parent name: 'evPhysicsSlideData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short UpperOffset;				 // size=0, offset=28 //  hashcode: 0x206A612C (dec: 543842604), parent name: 'evPhysicsSlideData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Height;					 // size=0, offset=30 //  hashcode: 0x8D3098C5 (dec: -1926195003), parent name: 'evPhysicsSlideData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *UpperInstance; // size=616, offset=32 //  hashcode: 0x2CF7C96D (dec: 754436461), parent name: 'evPhysicsSlideData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int Dot;						 // size=0, offset=36 //  hashcode: 0x6F8B2A65 (dec: 1871391333), parent name: 'evPhysicsSlideData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PHYSOBS_203fake // Hashcode: 0x650CBD45 (dec: 1695333701)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct evObjectThrowData // hashcode: 0x293A2507 (dec: 691676423)
{
	short type;					// size=0, offset=0 //  hashcode: 0x9DFD0E65 (dec: -1644360091), parent name: 'evObjectThrowData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short spinType;				// size=0, offset=2 //  hashcode: 0x58390A8C (dec: 1480133260), parent name: 'evObjectThrowData', parent hashcode: 0xFFFFFFFF (dec: -1)
	union PHYSOBS_203fake data; // size=8, offset=4 //  hashcode: 0x5EB14E82 (dec: 1588678274), parent name: 'evObjectThrowData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector angularVel; // size=8, offset=12 //  hashcode: 0x3D0514EF (dec: 1023743215), parent name: 'evObjectThrowData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short speed;		// size=0, offset=20 //  hashcode: 0x3E4CC4E0 (dec: 1045218528), parent name: 'evObjectThrowData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short gravity;				// size=0, offset=22 //  hashcode: 0x28543CD6 (dec: 676609238), parent name: 'evObjectThrowData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short initialXRot;			// size=0, offset=24 //  hashcode: 0x9F14B57D (dec: -1626032771), parent name: 'evObjectThrowData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;					// size=0, offset=26 //  hashcode: 0x0FF94DE9 (dec: 267996649), parent name: 'evObjectThrowData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evObjectBirthProjectileData // hashcode: 0xAA355F00 (dec: -1439342848)
{
	struct _Instance *instance;		 // size=616, offset=0 //  hashcode: 0x3F5A997F (dec: 1062902143), parent name: 'evObjectBirthProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int joint;						 // size=0, offset=4 //  hashcode: 0xC2B85DD2 (dec: -1028104750), parent name: 'evObjectBirthProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int type;						 // size=0, offset=8 //  hashcode: 0xE3BDC8ED (dec: -474101523), parent name: 'evObjectBirthProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *birthInstance; // size=616, offset=12 //  hashcode: 0x0B5DBBAF (dec: 190692271), parent name: 'evObjectBirthProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_219fake // hashcode: 0x1FF7E6E9 (dec: 536340201)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0x30C9348D (dec: 818492557), parent name: 'PHYSOBS_219fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x631C4444 (dec: 1662796868), parent name: 'PHYSOBS_219fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PHYSOBS_220fake // hashcode: 0x162925F6 (dec: 371795446)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x60351C55 (dec: 1614093397), parent name: 'PHYSOBS_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0xBBD31C06 (dec: -1143792634), parent name: 'PHYSOBS_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x306B833C (dec: 812352316), parent name: 'PHYSOBS_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0x2EA4C3A2 (dec: 782549922), parent name: 'PHYSOBS_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0xE6E37688 (dec: -421300600), parent name: 'PHYSOBS_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0xD2434EEA (dec: -767340822), parent name: 'PHYSOBS_220fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PHYSOBS_221fake // Hashcode: 0x44F896AD (dec: 1157142189)
{
	struct PHYSOBS_219fake flame; // size=8, offset=0
	struct PHYSOBS_220fake phys;  // size=12, offset=0
};

struct PhysObWeaponProperties // hashcode: 0xC3612955 (dec: -1017042603)
{
	struct PhysObProperties Properties;				// size=8, offset=0 //  hashcode: 0x7D61548E (dec: 2103530638), parent name: 'PhysObWeaponProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PhysObWeaponAttributes WeaponAttributes; // size=28, offset=8 //  hashcode: 0xE16C9346 (dec: -512978106), parent name: 'PhysObWeaponProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PhysObInteractProperties // hashcode: 0x668EE420 (dec: 1720640544)
{
	struct PhysObProperties Properties;	// size=8, offset=0 //  hashcode: 0x86C9C7E7 (dec: -2033596441), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short conditions;			   // size=0, offset=8 //  hashcode: 0xABA58548 (dec: -1415215800), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short auxConditions;		   // size=0, offset=10 //  hashcode: 0xB5AFEAA2 (dec: -1246762334), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short action;				   // size=0, offset=12 //  hashcode: 0xBDCB76C7 (dec: -1110739257), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short auxAction;			   // size=0, offset=14 //  hashcode: 0x96CC8218 (dec: -1764982248), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char startAnim;			   // size=0, offset=16 //  hashcode: 0xA3FEB919 (dec: -1543587559), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char endAnim;				   // size=0, offset=17 //  hashcode: 0x9702E3C3 (dec: -1761418301), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char razielAnim;			   // size=0, offset=18 //  hashcode: 0x9CB3AEF7 (dec: -1665945865), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char razielAuxAnim;		   // size=0, offset=19 //  hashcode: 0x058E1C2B (dec: 93199403), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char frame;				   // size=0, offset=20 //  hashcode: 0xD0BBA33D (dec: -793009347), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char startAnimMode;		   // size=0, offset=21 //  hashcode: 0xC0EAC6DC (dec: -1058355492), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short distance;			   // size=0, offset=22 //  hashcode: 0x2AA022A7 (dec: 715137703), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short newType;				   // size=0, offset=24 //  hashcode: 0xFECE23C5 (dec: -20044859), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short newClass;			   // size=0, offset=26 //  hashcode: 0x26A9E0CF (dec: 648667343), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short mode;				   // size=0, offset=28 //  hashcode: 0x8E378A4F (dec: -1908962737), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short engageXYDistance;	   // size=0, offset=30 //  hashcode: 0xCBADB033 (dec: -877809613), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	short engageZMinDelta;				   // size=0, offset=32 //  hashcode: 0xCBA782E8 (dec: -878214424), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	short engageZMaxDelta;				   // size=0, offset=34 //  hashcode: 0xF81DF5C3 (dec: -132254269), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char engageYCone;			   // size=0, offset=36 //  hashcode: 0x8F6D99CF (dec: -1888642609), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char engageZCone;			   // size=0, offset=37 //  hashcode: 0x2F93B2CB (dec: 798208715), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad;					   // size=0, offset=38 //  hashcode: 0xA1554B40 (dec: -1588245696), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PhysObWeaponAttributes *weapon; // size=28, offset=40 //  hashcode: 0x67FBDF8F (dec: 1744560015), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __PhysObProjectileProperties // hashcode: 0x0F1971B2 (dec: 253325746)
{
	struct PhysObProperties Properties;  // size=8, offset=0 //  hashcode: 0x5F5B96BC (dec: 1599837884), parent name: '__PhysObProjectileProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	long totalProjectiles;				 // size=0, offset=8 //  hashcode: 0x428D20B7 (dec: 1116545207), parent name: '__PhysObProjectileProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __PhysObProjectileData *data; // size=12, offset=12 //  hashcode: 0xED94D8D8 (dec: -309012264), parent name: '__PhysObProjectileProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PhysObDraftProperties // hashcode: 0x734F01FC (dec: 1934557692)
{
	struct PhysObProperties Properties; // size=8, offset=0 //  hashcode: 0x45533E5A (dec: 1163083354), parent name: 'PhysObDraftProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	short force;						// size=0, offset=8 //  hashcode: 0x492FCDB4 (dec: 1227869620), parent name: 'PhysObDraftProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short radius;				// size=0, offset=10 //  hashcode: 0xF6457D4C (dec: -163218100), parent name: 'PhysObDraftProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short radiusCoef;			// size=0, offset=12 //  hashcode: 0xAB8F80E8 (dec: -1416658712), parent name: 'PhysObDraftProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxVelocity;					// size=0, offset=14 //  hashcode: 0x0835AA15 (dec: 137734677), parent name: 'PhysObDraftProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long height;				// size=0, offset=16 //  hashcode: 0x84C9764B (dec: -2067171765), parent name: 'PhysObDraftProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PhysObSwitchProperties // hashcode: 0xF10C9EBB (dec: -250831173)
{
	struct PhysObProperties Properties; // size=8, offset=0 //  hashcode: 0x93C5498D (dec: -1815787123), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Distance;						// size=0, offset=8 //  hashcode: 0x7B066DC6 (dec: 2064018886), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Class;						// size=0, offset=10 //  hashcode: 0x3E24E3BD (dec: 1042604989), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char onAnim;				// size=0, offset=12 //  hashcode: 0xA3DD9E2F (dec: -1545757137), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char offAnim;				// size=0, offset=13 //  hashcode: 0x85931857 (dec: -2053957545), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char failedOnAnim;			// size=0, offset=14 //  hashcode: 0xC8AA754D (dec: -928352947), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char enableAnim;			// size=0, offset=15 //  hashcode: 0xCC2E3EC8 (dec: -869384504), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char shutAnim;				// size=0, offset=16 //  hashcode: 0xA2F06438 (dec: -1561304008), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char onWalkTimer;			// size=0, offset=17 //  hashcode: 0xDD4C5EE1 (dec: -582197535), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char offWalkTimer;			// size=0, offset=18 //  hashcode: 0xD80FAEB0 (dec: -670060880), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char walkMode;				// size=0, offset=19 //  hashcode: 0x42027290 (dec: 1107456656), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char razielOnAnim;			// size=0, offset=20 //  hashcode: 0xCE6A7C92 (dec: -831882094), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char razielOffAnim;		// size=0, offset=21 //  hashcode: 0x12039C3C (dec: 302226492), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char razielFailedOnAnim;   // size=0, offset=22 //  hashcode: 0x99AAA8A2 (dec: -1716868958), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char razielEnableAnim;		// size=0, offset=23 //  hashcode: 0x9E36526C (dec: -1640607124), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char startMode;			// size=0, offset=24 //  hashcode: 0xA416FDA5 (dec: -1541997147), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char startAnim;			// size=0, offset=25 //  hashcode: 0x42BB1D61 (dec: 1119559009), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short engageXYDistance;	// size=0, offset=26 //  hashcode: 0xA1C176A2 (dec: -1581156702), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	char engageZMinDelta;				// size=0, offset=28 //  hashcode: 0x6C71B4DA (dec: 1819391194), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	char engageZMaxDelta;				// size=0, offset=29 //  hashcode: 0x0DE994D9 (dec: 233411801), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char engageYCone;			// size=0, offset=30 //  hashcode: 0x66C3B611 (dec: 1724102161), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char engageZCone;			// size=0, offset=31 //  hashcode: 0x739D8CF7 (dec: 1939705079), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PhysObCollectibleProperties // hashcode: 0x80B1E807 (dec: -2135824377)
{
	struct PhysObProperties Properties; // size=8, offset=0 //  hashcode: 0xBF5AF1ED (dec: -1084558867), parent name: 'PhysObCollectibleProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	short collectClass;					// size=0, offset=8 //  hashcode: 0x4B50AEB3 (dec: 1263578803), parent name: 'PhysObCollectibleProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	short collectValue;					// size=0, offset=10 //  hashcode: 0xE6329995 (dec: -432891499), parent name: 'PhysObCollectibleProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long distance;				// size=0, offset=12 //  hashcode: 0xCF345A55 (dec: -818652587), parent name: 'PhysObCollectibleProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char idleAnim;				// size=0, offset=16 //  hashcode: 0xE4B7A72A (dec: -457726166), parent name: 'PhysObCollectibleProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char collectAnim;			// size=0, offset=17 //  hashcode: 0x2C995FAC (dec: 748249004), parent name: 'PhysObCollectibleProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short spatialNode;			// size=0, offset=18 //  hashcode: 0x7BC5763C (dec: 2076538428), parent name: 'PhysObCollectibleProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PhysObAnimatedProperties // hashcode: 0xC40C87E4 (dec: -1005811740)
{
	struct PhysObProperties Properties; // size=8, offset=0 //  hashcode: 0x7A4ECE28 (dec: 2051984936), parent name: 'PhysObAnimatedProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short flags;				// size=0, offset=8 //  hashcode: 0xDDB25257 (dec: -575516073), parent name: 'PhysObAnimatedProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad;					// size=0, offset=10 //  hashcode: 0x418DFA74 (dec: 1099823732), parent name: 'PhysObAnimatedProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PhysObData // hashcode: 0x95351304 (dec: -1791683836)
{
	long Mode;							// size=0, offset=0 //  hashcode: 0x92D1CB16 (dec: -1831744746), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xForce;						// size=0, offset=4 //  hashcode: 0xD241C181 (dec: -767442559), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yForce;						// size=0, offset=6 //  hashcode: 0xC4146A53 (dec: -1005295021), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *Force;			// size=616, offset=8 //  hashcode: 0x3C2BE9E5 (dec: 1009510885), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short LinkNode;						// size=0, offset=12 //  hashcode: 0x44D02815 (dec: 1154492437), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short px;							// size=0, offset=14 //  hashcode: 0x158065E1 (dec: 360736225), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short py;							// size=0, offset=16 //  hashcode: 0xDF63B7E9 (dec: -547112983), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pz;							// size=0, offset=18 //  hashcode: 0x894EDC65 (dec: -1991320475), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rx1;							// size=0, offset=20 //  hashcode: 0x6233DAF9 (dec: 1647565561), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ry1;							// size=0, offset=22 //  hashcode: 0x741102B0 (dec: 1947271856), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rz1;							// size=0, offset=24 //  hashcode: 0x60068B75 (dec: 1611041653), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Segment1;						// size=0, offset=26 //  hashcode: 0x6FA92B40 (dec: 1873357632), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rx2;							// size=0, offset=28 //  hashcode: 0x61712DC8 (dec: 1634807240), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ry2;							// size=0, offset=30 //  hashcode: 0x64697066 (dec: 1684631654), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rz2;							// size=0, offset=32 //  hashcode: 0x5DD39D89 (dec: 1574149513), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Segment2;						// size=0, offset=34 //  hashcode: 0x192E908B (dec: 422482059), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Steps;						// size=0, offset=36 //  hashcode: 0xAEB75CF5 (dec: -1363714827), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Step;							// size=0, offset=38 //  hashcode: 0xC841E577 (dec: -935205513), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short PathNumber;					// size=0, offset=40 //  hashcode: 0x6A62CADF (dec: 1784859359), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Pad1;							// size=0, offset=42 //  hashcode: 0x0FE57A14 (dec: 266697236), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HInfo *RightCollision;		// size=24, offset=44 //  hashcode: 0x924301E2 (dec: -1841102366), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HInfo *LeftCollision;		// size=24, offset=48 //  hashcode: 0xB64AA5BE (dec: -1236621890), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short burnAmpl;						// size=0, offset=52 //  hashcode: 0xFB50C9C8 (dec: -78591544), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short throwFlags;					// size=0, offset=54 //  hashcode: 0xFE50E9B9 (dec: -28251719), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short initialXRot;					// size=0, offset=56 //  hashcode: 0x12E39695 (dec: 316905109), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xRotVel;						// size=0, offset=58 //  hashcode: 0xAD24E6ED (dec: -1390090515), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yRotVel;						// size=0, offset=60 //  hashcode: 0x0A1DD8C2 (dec: 169728194), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zRotVel;						// size=0, offset=62 //  hashcode: 0x761F4CCE (dec: 1981762766), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *throwingInstance; // size=616, offset=64 //  hashcode: 0x3C703C83 (dec: 1013988483), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int physObTimer;					// size=0, offset=68 //  hashcode: 0x0484DD67 (dec: 75816295), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BreakOffData // hashcode: 0x47B171A7 (dec: 1202811303)
{
	short NewType;  // size=0, offset=0 //  hashcode: 0x9FF1EBD6 (dec: -1611535402), parent name: 'BreakOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short NewClass; // size=0, offset=2 //  hashcode: 0xCCC6D206 (dec: -859385338), parent name: 'BreakOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ProjectileData // hashcode: 0x05689657 (dec: 90740311)
{
	int Type; // size=0, offset=0 //  hashcode: 0xE3E13CF4 (dec: -471778060), parent name: 'ProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _PhysObSaveData // hashcode: 0xA353E0E7 (dec: -1554784025)
{
	struct SwitchData switchData; // size=4, offset=0 //  hashcode: 0x988FF956 (dec: -1735394986), parent name: '_PhysObSaveData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long Mode;					  // size=0, offset=4 //  hashcode: 0x53246187 (dec: 1394893191), parent name: '_PhysObSaveData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct evObjectData evObjectData;

typedef struct evPhysicsGravityData evPhysicsGravityData;

typedef struct evPhysicsSlideData evPhysicsSlideData;

typedef struct evObjectThrowData evObjectThrowData;

typedef struct evObjectBirthProjectileData evObjectBirthProjectileData;

typedef struct PhysObWeaponProperties PhysObWeaponProperties;

typedef struct PhysObInteractProperties PhysObInteractProperties;

typedef struct __PhysObProjectileProperties PhysObProjectileProperties;

typedef struct PhysObDraftProperties PhysObDraftProperties;

typedef struct PhysObSwitchProperties PhysObSwitchProperties;

typedef struct PhysObCollectibleProperties PhysObCollectibleProperties;

typedef struct PhysObAnimatedProperties PhysObAnimatedProperties;

typedef struct PhysObData PhysObData;

typedef struct BreakOffData BreakOffData;

typedef struct ProjectileData ProjectileData;

typedef struct _PhysObSaveData PhysObSaveData;

extern void PHYSOB_PlayDropSound(struct _Instance *instance); // 0x80068700

extern struct _Instance *PHYSOBS_IsAPushBlockAttached(struct _Instance *block); // 0x80068820

extern struct _Instance *PHYSOBS_IsAnythingAttached(struct _Instance *block); // 0x800688A8

extern int CheckPhysOb(struct _Instance *instance); // 0x800688F0

extern int CheckPhysObAbility(struct _Instance *instance, unsigned short ability); // 0x8006891C

extern int CheckPhysObFamily(struct _Instance *instance, unsigned short family); // 0x80068998

extern int GetPhysicalAbility(struct _Instance *instance); // 0x800689DC

extern int AnyBlocksInMotion(); // 0x80068A34

extern void SetThrowDirection(struct _Instance *instance, struct _Instance *parent, struct evObjectThrowData *throwData, struct PhysObData *Data); // 0x80068AD4

extern void ThrowPhysOb(struct _Instance *instance, struct evObjectThrowData *throwData); // 0x80068E20

extern int PushPhysOb(struct _Instance *instance, short x, short y, short PathNumber, struct _Instance *Force); // 0x80069200

extern void ResetSwitchPhysOb(struct _Instance *instance); // 0x8006935C

extern int SwitchPhysOb(struct _Instance *instance); // 0x800693F4

extern int InteractPhysOb(struct _Instance *instance, struct _Instance *Force, int LinkNode, int Action); // 0x800695D0

extern void ResetOrientation(struct _Instance *instance); // 0x80069930

extern void FinishPush(struct _Instance *instance); // 0x80069E4C

extern void PhysOb_AlignPush(struct _Instance *instance, int x, int y, int path, struct PhysObData *Data); // 0x80069E6C

extern int FlipPhysOb(struct _Instance *instance, short x, short y, struct _Instance *Force); // 0x80069FDC

extern int CanBePickedUp(struct _Instance *instance, struct _Instance *Force, int LinkNode); // 0x8006A120

extern int PickUpPhysOb(struct _Instance *instance, short Steps, struct _Instance *Force, int LinkNode); // 0x8006A2B8

extern struct _Instance *PHYSOB_BirthCollectible(struct _Instance *parent, int x, int y, int z, int type, int lifeTime); // 0x8006A3B8

extern struct evObjectBirthProjectileData *PHYSOB_BirthProjectile(struct _Instance *parent, int joint, int type); // 0x8006A468

extern struct _Instance *BirthProjectilePhysOb(struct _Instance *instance, int grabJoint, int type); // 0x8006A4C0

extern void PHYSOB_SetLightTable(struct _PhysObLight *pLight, struct LightInstance *li, short burnAmplitude); // 0x8006A694

extern void PHYSOB_EndLighting(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006A7FC

extern void PHYSOB_StartLighting(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006A820

extern void PHYSOB_StartBurnFX(struct _Instance *instance); // 0x8006A88C

extern void PHYSOB_StartBurning(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006A918

extern void PHYSOB_StopLighting(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006A954

extern void PHYSOB_StopBurning(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006A974

extern void PHYSOB_EndBurning(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006A998

extern void StopPhysOb(struct _Instance *instance); // 0x8006A9F8

extern void InitPhysicalObject(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8006AA34

extern void ProcessPhysicalObject(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8006B2B0

extern unsigned long PhysicalObjectQuery(struct _Instance *instance, unsigned long Query); // 0x8006BEE4

extern void PhysicalObjectPost(struct _Instance *instance, unsigned long Message, unsigned long Data); // 0x8006C3D4

extern long PhysobAnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, void *data); // 0x8006CCC4

extern void CheckForceCollision(struct _Instance *instance, struct _Instance *hitinst, struct _TFace *tface, struct _CollideInfo *collideInfo, struct _SVector *dir, int obliqueFlg); // 0x8006CD68

extern int GetObliqueDirection(struct _Instance *instance, struct _SVector *dir); // 0x8006CFD4

extern void CollidePhysicalObject(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8006D0B0

extern struct PhysObWeaponAttributes *PhysObGetWeapon(struct _Instance *instance); // 0x8006D884

extern struct _PhysObLight *PhysObGetLight(struct _Instance *instance); // 0x8006D928

extern struct PhysObSplinter *PhysObGetSplinter(struct _Instance *instance); // 0x8006D960

extern void TurnOnCollisionPhysOb(struct _Instance *instance, int coll); // 0x8006D994

extern void TurnOffCollisionPhysOb(struct _Instance *instance, int coll); // 0x8006DA38

extern int GetPhysObCollisionType(struct _Instance *instance); // 0x8006DAC0

extern void ExecuteThrow(struct _Instance *instance); // 0x8006DDFC

extern void ExecuteDrag(struct _Instance *instance); // 0x8006DF0C

extern void ExecuteSlideToStop(struct _Instance *instance); // 0x8006DFB4

extern void ExecuteFlip(struct _Instance *instance); // 0x8006E074

extern int CheckSlope(int Znormal, int Slope, int Slop); // 0x8006E164

extern int CheckBlockSlope(struct _Instance *instance, int x, int y, int hOff, int vOff, int dH, int dV); // 0x8006E184

extern int PHYSOBS_FigureDragForSlope(struct _Instance *instance, int pathNumber, int *result); // 0x8006E244

extern int PHYSOB_CheckThrownLineCollision(struct _Instance *instance, struct _Instance *parent); // 0x8006E2C4

extern int PHYSOB_CheckDroppedLineCollision(struct _Instance *instance, struct _Instance *parent); // 0x8006E7BC

extern int PHYSOB_CheckDirectedLineCollision(struct _Instance *instance, int xoffset, int yoffset, int startZOffset); // 0x8006EC78

extern long PHYSOBS_CheckForStackedForwardHits(struct _Instance *block, long xoffset, long yoffset); // 0x8006ECEC

extern void PHYSOBS_SetNewAnim(struct _Instance *instance, struct PhysObData *Data, unsigned long modeBits, int path, int resetflg); // 0x8006ED68

extern long PHYSOB_CheckForEnemyInBlkSpot(struct _Instance *instance, int dx, int dy); // 0x8006EDE0

extern long PHYSOBS_CheckForValidMove(struct _Instance *instance); // 0x8006EF14

extern void ExecuteGravitate(struct _Instance *instance); // 0x8006F460

extern void ExecuteFollow(struct _Instance *instance); // 0x8006F7D4

extern void PHYSOB_Normalize(struct _SVector *v); // 0x8006F82C

extern int PHYSOB_MoveTowardsAlign(struct _Instance *instance, struct _SVector *orgVec, struct _SVector *endVec); // 0x8006F8C8

extern int PHYSOB_ReAlignFalling(struct _Instance *instance, int zEndOff); // 0x8006FBA0

extern void DropPhysOb(struct _Instance *instance, int flags); // 0x800700C4

extern void PhysicalRelocateTune(struct Object *object, long offset); // 0x800701C0

extern int PHYSOBS_CheckObjectAxisAlignment(struct MATRIX *m0, struct MATRIX *m1, struct _SVector *axis); // 0x80070358

extern int PHYSOB_CheckSlide(struct _Instance *instance, int x, int y, struct evPhysicsSlideData **data); // 0x80070428

extern int PHYSOB_CheckSlide2(struct _Instance *instance, int x, int y, struct evPhysicsSlideData **data); // 0x800704B8

extern int PHYSOB_CheckDropOnSlope(struct _Instance *instance, int x, int y, struct evPhysicsSlideData **data); // 0x80070548

extern int PHYSOB_CheckSlideNormal(struct _Instance *instance, int x, int y, struct evPhysicsSlideData **data); // 0x800705DC

extern void PHYSOB_NormalToAxis(short *x, short *y); // 0x80070630

#endif
