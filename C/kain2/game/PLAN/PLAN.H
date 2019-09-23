#ifndef PLAN_H
#define PLAN_H

struct PLAN_73fake // hashcode: 0xEACB4D84 (dec: -355775100)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x2EF35E0A (dec: 787701258), parent name: 'PLAN_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x2FF3D8E3 (dec: 804509923), parent name: 'PLAN_73fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_74fake // hashcode: 0x40800B92 (dec: 1082133394)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x139CAA2D (dec: 329034285), parent name: 'PLAN_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0x0494519C (dec: 76829084), parent name: 'PLAN_74fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_75fake // hashcode: 0xE94BD606 (dec: -380905978)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0xE1C82E80 (dec: -506974592), parent name: 'PLAN_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0xF9697A6A (dec: -110527894), parent name: 'PLAN_75fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLAN_76fake // Hashcode: 0x1EE5CF14 (dec: 518377236)
{
	struct PLAN_73fake callback; // size=8, offset=0
	struct PLAN_74fake vector;   // size=12, offset=0
	struct PLAN_75fake quat;	 // size=16, offset=0
};

union PLAN_77fake // Hashcode: 0xF5480003 (dec: -179830781)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PLAN_78fake // Hashcode: 0x9166F3EF (dec: -1855523857)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct PLAN_79fake // hashcode: 0x2CE00B88 (dec: 752880520)
{
	union PLAN_78fake size; // size=4, offset=0 //  hashcode: 0x02930B5C (dec: 43191132), parent name: 'PLAN_79fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_80fake // hashcode: 0x62F348A6 (dec: 1660111014)
{
	short x;				// size=0, offset=0 //  hashcode: 0xD2DEC006 (dec: -757153786), parent name: 'PLAN_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x3F188E26 (dec: 1058573862), parent name: 'PLAN_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0xEC1DD668 (dec: -333588888), parent name: 'PLAN_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x7F195585 (dec: 2132366725), parent name: 'PLAN_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x3627C45F (dec: 908575839), parent name: 'PLAN_80fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_81fake // hashcode: 0xD8845440 (dec: -662416320)
{
	long index; // size=0, offset=0 //  hashcode: 0x4688DDED (dec: 1183374829), parent name: 'PLAN_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x7652F779 (dec: 1985148793), parent name: 'PLAN_81fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_82fake // hashcode: 0x436098E3 (dec: 1130404067)
{
	long index; // size=0, offset=0 //  hashcode: 0xEBC9E99A (dec: -339088998), parent name: 'PLAN_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x7AC2BC3D (dec: 2059582525), parent name: 'PLAN_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_83fake // hashcode: 0x2DB14E15 (dec: 766594581)
{
	long index; // size=0, offset=0 //  hashcode: 0x11E25895 (dec: 300046485), parent name: 'PLAN_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x2B2C67AD (dec: 724330413), parent name: 'PLAN_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_84fake // hashcode: 0x910407F9 (dec: -1862006791)
{
	long time;  // size=0, offset=0 //  hashcode: 0x96BAE39D (dec: -1766136931), parent name: 'PLAN_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xE09B3DB2 (dec: -526697038), parent name: 'PLAN_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_85fake // hashcode: 0x0929C9BA (dec: 153733562)
{
	long action;   // size=0, offset=0 //  hashcode: 0x1EEE258C (dec: 518923660), parent name: 'PLAN_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x6C62681C (dec: 1818388508), parent name: 'PLAN_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_86fake // hashcode: 0x67D69A7B (dec: 1742117499)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xE59504E2 (dec: -443218718), parent name: 'PLAN_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x013830F6 (dec: 20459766), parent name: 'PLAN_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_87fake // hashcode: 0x78160EB3 (dec: 2014711475)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xCC4BBAC7 (dec: -867452217), parent name: 'PLAN_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x5E6A2CAB (dec: 1584016555), parent name: 'PLAN_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_88fake // hashcode: 0xC58299A1 (dec: -981296735)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xD29B675A (dec: -761567398), parent name: 'PLAN_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0x22B1AD72 (dec: 582069618), parent name: 'PLAN_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_89fake // hashcode: 0x61C0F737 (dec: 1640036151)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0x63961492 (dec: 1670780050), parent name: 'PLAN_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x5BE2691D (dec: 1541564701), parent name: 'PLAN_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xCC6E5395 (dec: -865184875), parent name: 'PLAN_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x4C16DE36 (dec: 1276567094), parent name: 'PLAN_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xC5B31E35 (dec: -978117067), parent name: 'PLAN_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_90fake // hashcode: 0xD3970536 (dec: -745077450)
{
	long timer;  // size=0, offset=0 //  hashcode: 0x75CC6C34 (dec: 1976331316), parent name: 'PLAN_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x992F72BF (dec: -1724943681), parent name: 'PLAN_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_91fake // hashcode: 0x058B959F (dec: 93033887)
{
	short index;					// size=0, offset=0 //  hashcode: 0xC1BDD93E (dec: -1044522690), parent name: 'PLAN_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0x5FB4A23B (dec: 1605673531), parent name: 'PLAN_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0x490B6C78 (dec: 1225485432), parent name: 'PLAN_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0xA35EA55C (dec: -1554078372), parent name: 'PLAN_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_92fake // hashcode: 0x3716D337 (dec: 924242743)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0xA03CCA31 (dec: -1606628815), parent name: 'PLAN_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x09ABA6FC (dec: 162244348), parent name: 'PLAN_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0x0E3F4874 (dec: 239028340), parent name: 'PLAN_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_93fake // hashcode: 0xA770DB2B (dec: -1485776085)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x3E2F656E (dec: 1043293550), parent name: 'PLAN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0x4A9E1AA7 (dec: 1251875495), parent name: 'PLAN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0xC0F10116 (dec: -1057947370), parent name: 'PLAN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0xE8EF23E7 (dec: -386980889), parent name: 'PLAN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x41B3CBCB (dec: 1102302155), parent name: 'PLAN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0xB3632F18 (dec: -1285345512), parent name: 'PLAN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x6809251F (dec: 1745429791), parent name: 'PLAN_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_94fake // hashcode: 0xCA88241D (dec: -897047523)
{
	long index;  // size=0, offset=0 //  hashcode: 0xCD626D39 (dec: -849187527), parent name: 'PLAN_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x3446B808 (dec: 877049864), parent name: 'PLAN_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_95fake // hashcode: 0xB89CED7E (dec: -1197675138)
{
	short type; // size=0, offset=0 //  hashcode: 0x0D1667DB (dec: 219572187), parent name: 'PLAN_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x7DCDD4E9 (dec: 2110641385), parent name: 'PLAN_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_96fake // hashcode: 0x807465E6 (dec: -2139855386)
{
	long time;   // size=0, offset=0 //  hashcode: 0x4C15D2D4 (dec: 1276498644), parent name: 'PLAN_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x5E6E1658 (dec: 1584272984), parent name: 'PLAN_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_97fake // hashcode: 0x3B62FFF1 (dec: 996343793)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0x1AC494C4 (dec: 449090756), parent name: 'PLAN_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xA020C5A7 (dec: -1608464985), parent name: 'PLAN_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_98fake // hashcode: 0x596E11E9 (dec: 1500385769)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0xB4366FCA (dec: -1271500854), parent name: 'PLAN_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x755B6133 (dec: 1968922931), parent name: 'PLAN_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_99fake // hashcode: 0x44E43703 (dec: 1155806979)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0xB9A6C5CE (dec: -1180252722), parent name: 'PLAN_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xA2AE2CF8 (dec: -1565643528), parent name: 'PLAN_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_100fake // hashcode: 0xE0AD003D (dec: -525533123)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0x15C81AA4 (dec: 365435556), parent name: 'PLAN_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x5FBABB7C (dec: 1606073212), parent name: 'PLAN_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xCD6127D1 (dec: -849270831), parent name: 'PLAN_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0x4358A1E3 (dec: 1129882083), parent name: 'PLAN_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_101fake // hashcode: 0x0E685FEB (dec: 241721323)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x2844C6CF (dec: 675595983), parent name: 'PLAN_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x6D2D4A2A (dec: 1831684650), parent name: 'PLAN_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0x4B74411C (dec: 1265910044), parent name: 'PLAN_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x40C52462 (dec: 1086661730), parent name: 'PLAN_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x935D7E69 (dec: -1822589335), parent name: 'PLAN_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLAN_102fake // Hashcode: 0x45BC06CC (dec: 1169950412)
{
	struct PLAN_79fake misc[3];		 // size=12, offset=0
	struct _CameraKey *cameraKey;	// size=24, offset=0
	struct PLAN_80fake teleport;	 // size=16, offset=0
	struct PLAN_81fake cameraValue;  // size=8, offset=0
	struct PLAN_82fake miscValue;	// size=8, offset=0
	struct PLAN_83fake logicValue;   // size=8, offset=0
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
	struct PLAN_84fake cameraShake;  // size=8, offset=0
	long cameraSave;				 // size=0, offset=0
	long cameraRestore;				 // size=0, offset=0
	struct _BGObject *bgObject;		 // size=24, offset=0
	long value[2];					 // size=8, offset=0
	struct PLAN_85fake sound;		 // size=12, offset=0
	void *intro;					 // size=0, offset=0
	long deathZ;					 // size=0, offset=0
	struct PLAN_86fake dsignal;		 // size=8, offset=0
	void *mirror;					 // size=0, offset=0
	long fogNear;					 // size=0, offset=0
	long fogFar;					 // size=0, offset=0
	struct PLAN_87fake gotoFrame;	// size=8, offset=0
	struct PLAN_88fake changeModel;  // size=8, offset=0
	void *vmObject;					 // size=0, offset=0
	struct PLAN_89fake logic;		 // size=8, offset=0
	void *callSignal;				 // size=0, offset=0
	struct _SVector offset;			 // size=8, offset=0
	struct Signal *gotoLabel;		 // size=0, offset=0
	struct Signal *gosubLabel;		 // size=0, offset=0
	struct PLAN_90fake control;		 // size=8, offset=0
	struct PLAN_91fake zSignal;		 // size=12, offset=0
	struct PLAN_92fake StreamLevel;  // size=24, offset=0
	struct PLAN_93fake shards;		 // size=12, offset=0
	struct PLAN_94fake cameraSpline; // size=8, offset=0
	struct PLAN_95fake screenWipe;   // size=4, offset=0
	long voiceSitId;				 // size=0, offset=0
	struct PLAN_96fake introFX;		 // size=8, offset=0
	struct PLAN_97fake introActive;  // size=8, offset=0
	struct PLAN_98fake levelChange;  // size=18, offset=0
	long blendStart;				 // size=0, offset=0
	struct PLAN_99fake setTimes;	 // size=8, offset=0
	struct PLAN_100fake color;		 // size=4, offset=0
	struct PLAN_101fake print;		 // size=12, offset=0
	long slideAngle;				 // size=0, offset=0
};

union PLAN_103fake // Hashcode: 0x4AF15405 (dec: 1257329669)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union PLAN_108fake // Hashcode: 0xB4ABD0A9 (dec: -1263808343)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct PLAN_110fake // hashcode: 0x695776B8 (dec: 1767339704)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x1AA4F7D6 (dec: 447018966), parent name: 'PLAN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0x634C74C3 (dec: 1665955011), parent name: 'PLAN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0x5C48FFC6 (dec: 1548287942), parent name: 'PLAN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0xC4B3F08B (dec: -994840437), parent name: 'PLAN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0x52048C57 (dec: 1376029783), parent name: 'PLAN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0xBDC551C5 (dec: -1111141947), parent name: 'PLAN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x7B17A40B (dec: 2065146891), parent name: 'PLAN_110fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_111fake // hashcode: 0x3579B748 (dec: 897169224)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x6BD35847 (dec: 1809012807), parent name: 'PLAN_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0x0CB95A7B (dec: 213473915), parent name: 'PLAN_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x6A087D03 (dec: 1778941187), parent name: 'PLAN_111fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_112fake // hashcode: 0xEAC1CDA3 (dec: -356397661)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x065EC3D5 (dec: 106873813), parent name: 'PLAN_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x8F9A7CF3 (dec: -1885700877), parent name: 'PLAN_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x91B282B5 (dec: -1850572107), parent name: 'PLAN_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x197641AA (dec: 427180458), parent name: 'PLAN_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x73D7E98C (dec: 1943529868), parent name: 'PLAN_112fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_113fake // hashcode: 0xFCDBDE93 (dec: -52699501)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x719D6AFC (dec: 1906141948), parent name: 'PLAN_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x88AB5014 (dec: -2002038764), parent name: 'PLAN_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0xD3BEB663 (dec: -742476189), parent name: 'PLAN_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0x2FAC558E (dec: 799823246), parent name: 'PLAN_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0xDFBEC19D (dec: -541146723), parent name: 'PLAN_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_114fake // hashcode: 0xA74547B8 (dec: -1488631880)
{
	struct PLAN_110fake Cinematic; // size=28, offset=0 //  hashcode: 0x17AC68BB (dec: 397174971), parent name: 'PLAN_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PLAN_111fake Idle;	  // size=20, offset=28 //  hashcode: 0x69C96CC9 (dec: 1774808265), parent name: 'PLAN_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PLAN_112fake Behind;	// size=28, offset=48 //  hashcode: 0xB7170D6B (dec: -1223226005), parent name: 'PLAN_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PLAN_113fake Follow;	// size=20, offset=76 //  hashcode: 0x30CF9C31 (dec: 818912305), parent name: 'PLAN_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_181fake // hashcode: 0xC8B0144E (dec: -927984562)
{
	struct _Instance *parent; // size=616, offset=0 //  hashcode: 0xA1B12C14 (dec: -1582224364), parent name: 'PLAN_181fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;			  // size=0, offset=4 //  hashcode: 0x964B5CAB (dec: -1773445973), parent name: 'PLAN_181fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PLAN_182fake // hashcode: 0x6B7FB4F6 (dec: 1803531510)
{
	short xVel;  // size=0, offset=0 //  hashcode: 0x5D42D150 (dec: 1564660048), parent name: 'PLAN_182fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yVel;  // size=0, offset=2 //  hashcode: 0xB9AF31BD (dec: -1179700803), parent name: 'PLAN_182fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;  // size=0, offset=4 //  hashcode: 0x3E5372DC (dec: 1045656284), parent name: 'PLAN_182fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xAccl; // size=0, offset=6 //  hashcode: 0xAB017002 (dec: -1425969150), parent name: 'PLAN_182fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yAccl; // size=0, offset=8 //  hashcode: 0xAA6F973B (dec: -1435527365), parent name: 'PLAN_182fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zAccl; // size=0, offset=10 //  hashcode: 0xA964D435 (dec: -1453009867), parent name: 'PLAN_182fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union PLAN_183fake // Hashcode: 0x027850E8 (dec: 41439464)
{
	struct PLAN_181fake flame; // size=8, offset=0
	struct PLAN_182fake phys;  // size=12, offset=0
};

union PLAN_216fake // Hashcode: 0xA458DD1A (dec: -1537680102)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

extern long PLAN_CalcMinDistFromExistingNodes(struct _Position *pos, struct PlanningNode *planningPool, int distanceType); // 0x80097188

extern void PLAN_UpdatePlanMkrNodes(struct PlanningNode *planningPool, struct _Position *playerPos); // 0x80097224

extern void PLAN_UpdatePlayerNode(struct PlanningNode *planningPool, struct _Position *playerPos); // 0x80097470

extern void PLAN_AddRandomNode(struct PlanningNode *planningPool, struct _Position *playerPos); // 0x800975C4

extern void PLAN_DeleteRandomNode(struct PlanningNode *planningPool); // 0x800977D0

extern void PLAN_DeleteOutOfRangeNodesOfSource(struct PlanningNode *planningPool, struct _Position *playerPos, int nodeSourceToCheck, long removeDist); // 0x80097804

extern void PLAN_AddOrRemoveRandomNodes(struct PlanningNode *planningPool, struct _Position *playerPos); // 0x800978DC

extern void PLAN_AddInitialNodes(struct PlanningNode *planningPool, struct _Instance *player); // 0x8009792C

extern void PLAN_AddOrRemoveNodes(struct PlanningNode *planningPool, struct _Instance *player); // 0x800979E8

extern struct PlanningNode *PLAN_FindNodeMostInNeedOfConnectivityExpansion(struct PlanningNode *planningPool); // 0x80097AD0

#endif
