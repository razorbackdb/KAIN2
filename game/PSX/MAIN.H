#ifndef MAIN_H
#define MAIN_H

#include "../G2/MAING2.H"
#include "../STRMLOAD.H"
#include "../GAMELOOP.H"
#include "../LOCAL/LOCALSTR.H"
//#include "AADLIB.H"

struct _G2AppDataVM_Type // hashcode: 0xC1BF7B11 (dec: -1044415727)
{
	int argc; // size=0, offset=0
	int *argv; // size=0, offset=4
};

typedef struct _G2AppDataVM_Type G2AppDataVM;

static struct _G2AppDataVM_Type _appDataVM; 

struct _Position // hashcode: 0x2523C22F (dec: 623100463)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
};

struct _Rotation // hashcode: 0x5A40CBB0 (dec: 1514195888)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short pad; // size=0, offset=6
};

struct _Normal // hashcode: 0xC59D5A5B (dec: -979543461)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short pad; // size=0, offset=6
};

struct _Sphere // hashcode: 0x361BDD31 (dec: 907795761)
{
	struct _Position position; // size=6, offset=0
	unsigned short radius; // size=0, offset=6
	unsigned long radiusSquared; // size=0, offset=8
};

struct _Sphere_noSq // hashcode: 0xA031058C (dec: -1607400052)
{
	struct _Position position; // size=6, offset=0
	unsigned short radius; // size=0, offset=6
};

struct MATRIX // hashcode: 0x610186A2 (dec: 1627489954)
{
	short m[3][3]; // size=18, offset=0
	long t[3]; // size=12, offset=20
};

struct _SVector // hashcode: 0x73B07C09 (dec: 1940945929)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short pad; // size=0, offset=6
};

struct _G2Quat_Type // hashcode: 0xC71F9EB1 (dec: -954229071)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short w; // size=0, offset=6
};

struct vecS // hashcode: 0xEADB8F3A (dec: -354709702)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
};

struct vecL // hashcode: 0x7575CB14 (dec: 1970653972)
{
	long x; // size=0, offset=0
	long y; // size=0, offset=4
	long z; // size=0, offset=8
};

struct _Vertex // hashcode: 0x97101469 (dec: -1760553879)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
};

struct _Face // hashcode: 0x8775891B (dec: -2022340325)
{
	unsigned short v0; // size=0, offset=0
	unsigned short v1; // size=0, offset=2
	unsigned short v2; // size=0, offset=4
};

struct _PlaneConstants // hashcode: 0xE1AAD777 (dec: -508897417)
{
	short a; // size=0, offset=0
	short b; // size=0, offset=2
	short c; // size=0, offset=4
	short flags; // size=0, offset=6
	long d; // size=0, offset=8
};

struct _TFace // hashcode: 0x85FE430F (dec: -2046934257)
{
	struct _Face face; // size=6, offset=0
	unsigned char attr; // size=0, offset=6
	char sortPush; // size=0, offset=7
	unsigned short normal; // size=0, offset=8
	unsigned short textoff; // size=0, offset=10
};

struct _TVertex // hashcode: 0x0883ABD5 (dec: 142846933)
{
	struct _Vertex vertex; // size=6, offset=0
	unsigned short rgb15; // size=0, offset=6
	unsigned char r0; // size=0, offset=8
	unsigned char g0; // size=0, offset=9
	unsigned char b0; // size=0, offset=10
	unsigned char code; // size=0, offset=11
};

struct _MVertex // hashcode: 0x2B95C05B (dec: 731234395)
{
	struct _Vertex vertex; // size=6, offset=0
	unsigned short normal; // size=0, offset=6
};

struct SplineKey // hashcode: 0x5D3D994D (dec: 1564318029)
{
	short count; // size=0, offset=0
	struct vecS point; // size=6, offset=2
	struct vecL dd; // size=12, offset=8
	struct vecL ds; // size=12, offset=20
};

struct Spline // hashcode: 0xA7B8D53F (dec: -1481059009)
{
	struct SplineKey *key; // size=32, offset=0
	short numkeys; // size=0, offset=4
	unsigned char type; // size=0, offset=6
	unsigned char flags; // size=0, offset=7
};

struct SplineRotKey // hashcode: 0xD2E3A87E (dec: -756832130)
{
	short count; // size=0, offset=0
	struct _G2Quat_Type q; // size=8, offset=2
};

struct RSpline // hashcode: 0xD9C500BD (dec: -641400643)
{
	struct SplineRotKey *key; // size=10, offset=0
	short numkeys; // size=0, offset=4
	unsigned char type; // size=0, offset=6
	unsigned char flags; // size=0, offset=7
};

struct SplineDef // hashcode: 0x04DD5459 (dec: 81613913)
{
	short currkey; // size=0, offset=0
	unsigned short denomFlag; // size=0, offset=2
	long fracCurr; // size=0, offset=4
};

struct MultiSpline // hashcode: 0x2823B2CF (dec: 673428175)
{
	struct Spline *positional; // size=8, offset=0
	struct RSpline *rotational; // size=8, offset=4
	struct Spline *scaling; // size=8, offset=8
	struct Spline *color; // size=8, offset=12
	struct SplineDef curPositional; // size=8, offset=16
	struct SplineDef curRotational; // size=8, offset=24
	struct SplineDef curScaling; // size=8, offset=32
	struct SplineDef curColor; // size=8, offset=40
	struct MATRIX curRotMatrix; // size=32, offset=48
};

struct NodeType // hashcode: 0x5BF613D7 (dec: 1542853591)
{
	struct NodeType *prev; // size=8, offset=0
	struct NodeType *next; // size=8, offset=4
};

struct Intro // hashcode: 0x796E766D (dec: 2037282413)
{
	char name[16]; // size=16, offset=0
	long intronum; // size=0, offset=16
	long UniqueID; // size=0, offset=20
	struct _Rotation rotation; // size=8, offset=24
	struct _Position position; // size=6, offset=32
	short maxRad; // size=0, offset=38
	long maxRadSq; // size=0, offset=40
	long flags; // size=0, offset=44
	void *data; // size=0, offset=48
	//struct _Instance *instance; // size=616, offset=52
	struct MultiSpline *multiSpline; // size=0, offset=56
	void *dsignal; // size=0, offset=60
	short specturalLightGroup; // size=0, offset=64
	short meshColor; // size=0, offset=66
	struct _Position spectralPosition; // size=6, offset=68
	short spad; // size=0, offset=74
};

struct _BVertex // hashcode: 0xADD3BD2F (dec: -1378632401)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short pad; // size=0, offset=6
};

struct _BFace // hashcode: 0x69100F99 (dec: 1762660249)
{
	short v0; // size=0, offset=0
	short v1; // size=0, offset=2
	short v2; // size=0, offset=4
	short pad; // size=0, offset=6
	struct TextureFT3 *texture; // size=12, offset=8
};

struct _BGObject // hashcode: 0xEC69FB30 (dec: -328598736)
{
	short flags; // size=0, offset=0
	short numFaces; // size=0, offset=2
	struct _BVertex *vertexList; // size=8, offset=4
	struct _BFace *faceList; // size=12, offset=8
	short x; // size=0, offset=12
	short y; // size=0, offset=14
	short z; // size=0, offset=16
	short radius; // size=0, offset=18
	long numVertices; // size=0, offset=20
};

struct Signal // hashcode: 0xA0225F88 (dec: -1608360056)
{
	long id; // size=0, offset=0
	union {
		struct {
			union {
				long l; // size=0, offset=0
				short s[2]; // size=4, offset=0
				char c[4]; // size=4, offset=0
			} size; // size=4, offset=0, found in object files: player.o, player.o
		} misc; // size=12, offset=0, found in object files: player.o, player.o
		struct _CameraKey *cameraKey; // size=24, offset=0
		struct {
			short x; // size=0, offset=0
			short y; // size=0, offset=2
			short z; // size=0, offset=4
			short zrot; // size=0, offset=6
			struct _SVector offset; // size=8, offset=8
		} teleport; // size=16, offset=0, found in object files: player.o, player.o
		struct {
			long index; // size=0, offset=0
			long value; // size=0, offset=4
		} cameraValue; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			long index; // size=0, offset=0
			long value; // size=0, offset=4
		} miscValue; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			long index; // size=0, offset=0
			long value; // size=0, offset=4
		} logicValue; // size=8, offset=0, found in object files: player.o, player.o
		long timer; // size=0, offset=0
		long times; // size=0, offset=0
		long lightGroup; // size=0, offset=0
		long farPlane; // size=0, offset=0
		long cameraAdjust; // size=0, offset=0
		long cameraMode; // size=0, offset=0
		long cameraLock; // size=0, offset=0
		long cameraUnlock; // size=0, offset=0
		long cameraSmooth; // size=0, offset=0
		long cameraTimer; // size=0, offset=0
		struct {
			long time; // size=0, offset=0
			long scale; // size=0, offset=4
		} cameraShake; // size=8, offset=0, found in object files: player.o, player.o
		long cameraSave; // size=0, offset=0
		long cameraRestore; // size=0, offset=0
		struct _BGObject *bgObject; // size=24, offset=0
		long value[2]; // size=8, offset=0
		struct {
			long action; // size=0, offset=0
			long value[2]; // size=8, offset=4
		} sound; // size=12, offset=0, found in object files: player.o, player.o
		void *intro; // size=0, offset=0
		long deathZ; // size=0, offset=0
		struct {
			void *intro; // size=0, offset=0
			void *data; // size=0, offset=4
		} dsignal; // size=8, offset=0, found in object files: player.o, player.o
		void *mirror; // size=0, offset=0
		long fogNear; // size=0, offset=0
		long fogFar; // size=0, offset=0
		struct {
			void *intro; // size=0, offset=0
			long frame; // size=0, offset=4
		} gotoFrame; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			void *intro; // size=0, offset=0
			long model; // size=0, offset=4
		} changeModel; // size=8, offset=0, found in object files: player.o, player.o
		void *vmObject; // size=0, offset=0
		struct {
			unsigned char target; // size=0, offset=0
			unsigned char source1; // size=0, offset=1
			unsigned char source2; // size=0, offset=2
			unsigned char pad; // size=0, offset=3
			struct Signal *gotoLabel; // size=0, offset=4
		} logic; // size=8, offset=0, found in object files: player.o, player.o
		void *callSignal; // size=0, offset=0
		struct _SVector offset; // size=8, offset=0
		struct Signal *gotoLabel; // size=0, offset=0
		struct Signal *gosubLabel; // size=0, offset=0
		struct {
			long timer; // size=0, offset=0
			long action; // size=0, offset=4
		} control; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			short index; // size=0, offset=0
			short z; // size=0, offset=2
			struct MultiSignal *upSignal; // size=0, offset=4
			struct MultiSignal *downSignal; // size=0, offset=8
		} zSignal; // size=12, offset=0, found in object files: player.o, player.o
		struct {
			long currentnum; // size=0, offset=0
			long streamID; // size=0, offset=4
			char toname[16]; // size=16, offset=8
		} StreamLevel; // size=24, offset=0, found in object files: player.o, player.o
		struct {
			char num; // size=0, offset=0
			char vel; // size=0, offset=1
			short misc; // size=0, offset=2
			char flags; // size=0, offset=4
			char timeToLive; // size=0, offset=5
			short dummy2; // size=0, offset=6
			struct Object *object; // size=0, offset=8
		} shards; // size=12, offset=0, found in object files: player.o, player.o
		struct {
			long index; // size=0, offset=0
			void *intro; // size=0, offset=4
		} cameraSpline; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			short type; // size=0, offset=0
			short time; // size=0, offset=2
		} screenWipe; // size=4, offset=0, found in object files: player.o, player.o
		long voiceSitId; // size=0, offset=0
		struct {
			long time; // size=0, offset=0
			void *intro; // size=0, offset=4
		} introFX; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			void *intro; // size=0, offset=0
			struct Signal *gotoLabel; // size=0, offset=4
		} introActive; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			char world[9]; // size=9, offset=0
			char level[9]; // size=9, offset=9
		} levelChange; // size=18, offset=0, found in object files: player.o, player.o
		long blendStart; // size=0, offset=0
		struct {
			struct Signal *signal; // size=0, offset=0
			long times; // size=0, offset=4
		} setTimes; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			unsigned char r; // size=0, offset=0
			unsigned char g; // size=0, offset=1
			unsigned char b; // size=0, offset=2
			unsigned char pad; // size=0, offset=3
		} color; // size=4, offset=0, found in object files: player.o, player.o
		struct {
			short x; // size=0, offset=0
			short y; // size=0, offset=2
			short time; // size=0, offset=4
			short index; // size=0, offset=6
			char *text; // size=0, offset=8
		} print; // size=12, offset=0, found in object files: player.o, player.o
		long slideAngle; // size=0, offset=0
	} data; // size=24, offset=4, found in object files: player.o, player.o
};

struct _MultiSignal // hashcode: 0x0620B768 (dec: 102807400)
{
	long numSignals; // size=0, offset=0
	short signalNum; // size=0, offset=4
	short flags; // size=0, offset=6
	struct Signal signalList[32]; // size=896, offset=8
};

struct _HFace // hashcode: 0x30CA5CA6 (dec: 818568358)
{
	short v0; // size=0, offset=0
	short v1; // size=0, offset=2
	short v2; // size=0, offset=4
	unsigned char attr; // size=0, offset=6
	char pad; // size=0, offset=7
	unsigned short normal; // size=0, offset=8
	unsigned short n0; // size=0, offset=10
};

struct _HSphere // hashcode: 0x8E7B7191 (dec: -1904512623)
{
	long attr; // size=0, offset=0
	unsigned char id; // size=0, offset=4
	unsigned char rank; // size=0, offset=5
	short pad; // size=0, offset=6
	struct _Position position; // size=6, offset=8
	unsigned short radius; // size=0, offset=14
	unsigned long radiusSquared; // size=0, offset=16
};

struct _HBox // hashcode: 0x47CD8BDA (dec: 1204653018)
{
	short flags; // size=0, offset=0
	unsigned char id; // size=0, offset=2
	unsigned char rank; // size=0, offset=3
	short minX; // size=0, offset=4
	short minY; // size=0, offset=6
	short minZ; // size=0, offset=8
	short maxX; // size=0, offset=10
	short maxY; // size=0, offset=12
	short maxZ; // size=0, offset=14
	short refMinX; // size=0, offset=16
	short refMinY; // size=0, offset=18
	short refMinZ; // size=0, offset=20
	short refMaxX; // size=0, offset=22
	short refMaxY; // size=0, offset=24
	short refMaxZ; // size=0, offset=26
};

struct _HPrim // hashcode: 0x988F5E11 (dec: -1735434735)
{
	unsigned char hpFlags; // size=0, offset=0
	unsigned char withFlags; // size=0, offset=1
	unsigned char type; // size=0, offset=2
	unsigned char segment; // size=0, offset=3
	union {
		struct _HSphere *hsphere; // size=20, offset=0
		struct _HBox *hbox; // size=28, offset=0
		struct _HFace *hface; // size=12, offset=0
	} data; // size=4, offset=4, found in object files: player.o, player.o
};

struct _HModel // hashcode: 0xBC680356 (dec: -1134034090)
{
	struct _HPrim *hPrimList; // size=8, offset=0
	long numHPrims; // size=0, offset=4
};

struct _HInfo // hashcode: 0x6AC9807F (dec: 1791590527)
{
	long numHFaces; // size=0, offset=0
	struct _HFace *hfaceList; // size=12, offset=4
	long numHSpheres; // size=0, offset=8
	struct _HSphere *hsphereList; // size=20, offset=12
	long numHBoxes; // size=0, offset=16
	struct _HBox *hboxList; // size=28, offset=20
};

struct _Segment // hashcode: 0x2F06BF28 (dec: 788971304)
{
	long flags; // size=0, offset=0
	short firstTri; // size=0, offset=4
	short lastTri; // size=0, offset=6
	short firstVertex; // size=0, offset=8
	short lastVertex; // size=0, offset=10
	short px; // size=0, offset=12
	short py; // size=0, offset=14
	short pz; // size=0, offset=16
	short parent; // size=0, offset=18
	struct _HInfo *hInfo; // size=24, offset=20
};

struct _Model // hashcode: 0x9BCE1D24 (dec: -1680990940)
{
	long numVertices; // size=0, offset=0
	struct _MVertex *vertexList; // size=8, offset=4
	long numNormals; // size=0, offset=8
	struct _SVectorNoPad *normalList; // size=6, offset=12
	long numFaces; // size=0, offset=16
	struct _MFace *faceList; // size=12, offset=20
	long numSegments; // size=0, offset=24
	struct _Segment *segmentList; // size=24, offset=28
	struct AniTex *aniTextures; // size=16, offset=32
	short maxRad; // size=0, offset=36
	short pad; // size=0, offset=38
	long maxRadSq; // size=0, offset=40
	struct MultiSpline *multiSpline; // size=0, offset=44
	struct TextureMT3 *startTextures; // size=16, offset=48
	struct TextureMT3 *endTextures; // size=16, offset=52
};

struct _G2AnimFxHeader_Type // hashcode: 0xA004B4ED (dec: -1610304275)
{
	unsigned char sizeAndSection; // size=0, offset=0
	char type; // size=0, offset=1
	unsigned short keyframeID; // size=0, offset=2
};

struct _G2AnimKeylist_Type // hashcode: 0x87A15165 (dec: -2019471003)
{
	unsigned char sectionCount; // size=0, offset=0
	unsigned char s0TailTime; // size=0, offset=1
	unsigned char s1TailTime; // size=0, offset=2
	unsigned char s2TailTime; // size=0, offset=3
	unsigned short keyCount; // size=0, offset=4
	short timePerKey; // size=0, offset=6
	unsigned short pad00; // size=0, offset=8
	short pad01; // size=0, offset=10
	unsigned short pad10; // size=0, offset=12
	short pad11; // size=0, offset=14
	struct _G2AnimFxHeader_Type *fxList; // size=4, offset=16
	unsigned short (*sectionData[0]); // size=0, offset=20
};

struct ObjectEffect // hashcode: 0x2892438D (dec: 680674189)
{
	unsigned char effectNumber; // size=0, offset=0
	unsigned char modifierList[3]; // size=3, offset=1
};

struct VramSize // hashcode: 0xD96A55BF (dec: -647342657)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short w; // size=0, offset=4
	short h; // size=0, offset=6
};

struct Object // hashcode: 0xEC12E9AC (dec: -334304852)
{
	long oflags; // size=0, offset=0
	short id; // size=0, offset=4
	short sfxFileHandle; // size=0, offset=6
	short numModels; // size=0, offset=8
	short numAnims; // size=0, offset=10
	struct _Model **modelList; // size=56, offset=12
	struct _G2AnimKeylist_Type **animList; // size=20, offset=16
	short introDist; // size=0, offset=20
	short vvIntroDist; // size=0, offset=22
	short removeDist; // size=0, offset=24
	short vvRemoveDist; // size=0, offset=26
	void *data; // size=0, offset=28
	char *script; // size=0, offset=32
	char *name; // size=0, offset=36
	unsigned char *soundData; // size=0, offset=40
	long oflags2; // size=0, offset=44
	short sectionA; // size=0, offset=48
	short sectionB; // size=0, offset=50
	short sectionC; // size=0, offset=52
	short numberOfEffects; // size=0, offset=54
	struct ObjectEffect *effectList; // size=4, offset=56
	unsigned long *relocList; // size=0, offset=60
	void *relocModule; // size=0, offset=64
	struct VramSize vramSize; // size=8, offset=68
};

struct SoundInstance // hashcode: 0xFF235679 (dec: -14461319)
{
	unsigned char channel; // size=0, offset=0
	unsigned char state; // size=0, offset=1
	unsigned char delay; // size=0, offset=2
};

struct _G2SVector3_Type // hashcode: 0x60FF7CCD (dec: 1627356365)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
};

struct _G2LVector3_Type // hashcode: 0xD8D79EE7 (dec: -656957721)
{
	long x; // size=0, offset=0
	long y; // size=0, offset=4
	long z; // size=0, offset=8
};

struct _G2Matrix_Type // hashcode: 0x647D6F57 (dec: 1685942103)
{
	short rotScale[3][3]; // size=18, offset=0
	short scaleFlag; // size=0, offset=18
	struct _G2LVector3_Type trans; // size=12, offset=20
};

struct _G2AnimSection_Type // hashcode: 0xFC80328C (dec: -58707316)
{
	unsigned char flags; // size=0, offset=0
	unsigned char sectionID; // size=0, offset=1
	unsigned char firstSeg; // size=0, offset=2
	unsigned char segCount; // size=0, offset=3
	short elapsedTime; // size=0, offset=4
	short storedTime; // size=0, offset=6
	short loopStartTime; // size=0, offset=8
	short loopEndTime; // size=0, offset=10
	short *swAlarmTable; // size=0, offset=12
	long speedAdjustment; // size=0, offset=16
	unsigned short keylistID; // size=0, offset=20
	unsigned long alarmFlags; // size=0, offset=24
	long (*callback)(); // size=0, offset=28
	void *callbackData; // size=0, offset=32
	struct _G2AnimKeylist_Type *keylist; // size=20, offset=36
	struct _G2AnimChanStatusBlock_Type *chanStatusBlockList; // size=36, offset=40
	struct _G2AnimInterpInfo_Type *interpInfo; // size=12, offset=44
};

struct _G2Anim_Type // hashcode: 0xF35FCCD2 (dec: -211825454)
{
	unsigned char sectionCount; // size=0, offset=0
	unsigned char masterSection; // size=0, offset=1
	unsigned short controllerList; // size=0, offset=2
	unsigned short disabledControllerList; // size=0, offset=4
	unsigned short pad; // size=0, offset=6
	struct _G2SVector3_Type rootTrans; // size=6, offset=8
	unsigned short flags; // size=0, offset=14
	struct _Model *modelData; // size=0, offset=16
	struct _G2Matrix_Type *segMatrices; // size=32, offset=20
	unsigned long disabledBits[3]; // size=12, offset=24
	struct _G2AnimSection_Type section[3]; // size=144, offset=36
};

struct EventAliasCommandStruct // hashcode: 0xB6EF2AF6 (dec: -1225839882)
{
	struct _Instance *hostInstance; // size=0, offset=0
	short newanim; // size=0, offset=4
	short newframe; // size=0, offset=6
	short interpframes; // size=0, offset=8
	short speed; // size=0, offset=10
};

struct CVECTOR // hashcode: 0xDE4B0C81 (dec: -565506943)
{
	unsigned char r; // size=0, offset=0
	unsigned char g; // size=0, offset=1
	unsigned char b; // size=0, offset=2
	unsigned char cd; // size=0, offset=3
};

struct _Instance // hashcode: 0x699A5B3D (dec: 1771723581)
{
	struct NodeType node; // size=8, offset=0
	struct _Instance *next; // size=616, offset=8
	struct _Instance *prev; // size=616, offset=12
	long instanceID; // size=0, offset=16
	long flags; // size=0, offset=20
	long flags2; // size=0, offset=24
	struct Object *object; // size=76, offset=28
	struct Intro *intro; // size=0, offset=32
	void *data; // size=0, offset=36
	void *introData; // size=0, offset=40
	struct _Instance *parent; // size=616, offset=44
	long introNum; // size=0, offset=48
	long birthStreamUnitID; // size=0, offset=52
	long currentStreamUnitID; // size=0, offset=56
	long introUniqueID; // size=0, offset=60
	struct MATRIX *matrix; // size=32, offset=64
	struct MATRIX *oldMatrix; // size=32, offset=68
	struct SoundInstance soundInstanceTbl[4]; // size=12, offset=72
	unsigned long maxCheckDistance; // size=0, offset=84
	unsigned long checkMask; // size=0, offset=88
	struct _Position position; // size=6, offset=92
	unsigned char lightGroup; // size=0, offset=98
	struct _Position oldPos; // size=6, offset=100
	unsigned char spectralLightGroup; // size=0, offset=106
	short currentTextureAnimFrame; // size=0, offset=108
	struct _Position initialPos; // size=6, offset=110
	struct _Rotation rotation; // size=8, offset=116
	struct _Rotation oldRotation; // size=8, offset=124
	struct _SVector scale; // size=8, offset=132
	long attachedID; // size=0, offset=140
	long attachedSegment; // size=0, offset=144
	struct MATRIX relativeMatrix; // size=32, offset=148
	struct _TFace *tface; // size=12, offset=180
	struct _TFace *oldTFace; // size=12, offset=184
	void *tfaceLevel; // size=0, offset=188
	void *collideInfo; // size=0, offset=192
	long bspTree; // size=0, offset=196
	short cachedTFace; // size=0, offset=200
	short cachedBSPTree; // size=0, offset=202
	void *cachedTFaceLevel; // size=0, offset=204
	struct _Normal oldWNormal; // size=8, offset=208
	struct _Normal wNormal; // size=8, offset=216
	struct _SVector offset; // size=8, offset=224
	struct _HModel *hModelList; // size=8, offset=232
	short fadeValue; // size=0, offset=236
	short lightMatrix; // size=0, offset=238
	void (*processFunc)(); // size=0, offset=240
	void (*collideFunc)(); // size=0, offset=244
	void (*additionalCollideFunc)(); // size=0, offset=248
	unsigned long (*queryFunc)(); // size=0, offset=252
	void (*messageFunc)(); // size=0, offset=256
	struct _Position shadowPosition; // size=6, offset=260
	short currentModel; // size=0, offset=266
	struct _TFace *waterFace; // size=12, offset=268
	struct _TFace *oldWaterFace; // size=12, offset=272
	struct _Terrain *waterFaceTerrain; // size=0, offset=276
	struct _PlaneConstants halvePlane; // size=12, offset=280
	struct _SVector splitPoint; // size=8, offset=292
	struct _Instance *LinkParent; // size=616, offset=300
	struct _Instance *LinkChild; // size=616, offset=304
	struct _Instance *LinkSibling; // size=616, offset=308
	long ParentLinkNode; // size=0, offset=312
	void *InstanceState; // size=0, offset=316
	char introName[12]; // size=12, offset=320
	void *extraData; // size=0, offset=332
	short constrictAngle; // size=0, offset=336
	short petrifyValue; // size=0, offset=338
	long xVel; // size=0, offset=340
	long yVel; // size=0, offset=344
	long zVel; // size=0, offset=348
	long xAccl; // size=0, offset=352
	long yAccl; // size=0, offset=356
	long zAccl; // size=0, offset=360
	long maxXVel; // size=0, offset=364
	long maxYVel; // size=0, offset=368
	long maxZVel; // size=0, offset=372
	long currentMainState; // size=0, offset=376
	long work0; // size=0, offset=380
	long work1; // size=0, offset=384
	long work2; // size=0, offset=388
	long work3; // size=0, offset=392
	long work4; // size=0, offset=396
	long work5; // size=0, offset=400
	struct _G2Anim_Type anim; // size=180, offset=404
	enum _G2Bool_Enum (*rebuildCallback)(); // size=4, offset=584
	short splineFlags; // size=0, offset=588
	short targetFrame; // size=0, offset=590
	short clipBeg; // size=0, offset=592
	short clipEnd; // size=0, offset=594
	struct EventAliasCommandStruct aliasCommand; // size=12, offset=596
	long light_color; // size=0, offset=608
	struct CVECTOR *perVertexColor; // size=4, offset=612
};

struct TextureFT3 // hashcode: 0x2D2801D6 (dec: 757596630)
{
	unsigned char u0; // size=0, offset=0
	unsigned char v0; // size=0, offset=1
	unsigned short clut; // size=0, offset=2
	unsigned char u1; // size=0, offset=4
	unsigned char v1; // size=0, offset=5
	unsigned short tpage; // size=0, offset=6
	unsigned char u2; // size=0, offset=8
	unsigned char v2; // size=0, offset=9
	unsigned short attr; // size=0, offset=10
};

struct TextureMT3 // hashcode: 0xC9D0A5B9 (dec: -909072967)
{
	unsigned char u0; // size=0, offset=0
	unsigned char v0; // size=0, offset=1
	unsigned short clut; // size=0, offset=2
	unsigned char u1; // size=0, offset=4
	unsigned char v1; // size=0, offset=5
	unsigned short tpage; // size=0, offset=6
	unsigned char u2; // size=0, offset=8
	unsigned char v2; // size=0, offset=9
	char pad1; // size=0, offset=10
	char sortPush; // size=0, offset=11
	long color; // size=0, offset=12
};

struct AniTexInfo // hashcode: 0x907C013D (dec: -1870921411)
{
	struct TextureMT3 *texture; // size=16, offset=0
	long numFrames; // size=0, offset=4
	long speed; // size=0, offset=8
};

struct AniTex // hashcode: 0xE4DA2729 (dec: -455465175)
{
	long numAniTextues; // size=0, offset=0
	struct AniTexInfo aniTexInfo; // size=12, offset=4
};

struct DrMoveAniTexSrcInfo // hashcode: 0x4AD6E543 (dec: 1255597379)
{
	short pixSrcX; // size=0, offset=0
	short pixSrcY; // size=0, offset=2
	short clutSrcX; // size=0, offset=4
	short clutSrcY; // size=0, offset=6
};

struct DrMoveAniTexDestInfo // hashcode: 0xF3A982EE (dec: -206994706)
{
	short pixDstX; // size=0, offset=0
	short pixDstY; // size=0, offset=2
	short pixW; // size=0, offset=4
	short pixH; // size=0, offset=6
	short clutDstX; // size=0, offset=8
	short clutDstY; // size=0, offset=10
	short clutW; // size=0, offset=12
	short clutH; // size=0, offset=14
	short pixCurrentX; // size=0, offset=16
	short pixCurrentY; // size=0, offset=18
	short clutCurrentX; // size=0, offset=20
	short clutCurrentY; // size=0, offset=22
	long numFrames; // size=0, offset=24
	long speed; // size=0, offset=28
	struct DrMoveAniTexSrcInfo frame; // size=8, offset=32
};

struct DrMoveAniTex // hashcode: 0x0820A5D4 (dec: 136357332)
{
	long numAniTextues; // size=0, offset=0
	struct DrMoveAniTexDestInfo *aniTexInfo; // size=40, offset=4
};

struct _MorphVertex // hashcode: 0xAAB8DABE (dec: -1430725954)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short vindex; // size=0, offset=6
	short hx; // size=0, offset=8
	short hy; // size=0, offset=10
	short hz; // size=0, offset=12
};

struct _MorphColor // hashcode: 0xA6BA0326 (dec: -1497758938)
{
	short morphColor15; // size=0, offset=0
};

struct _BoundingBox // hashcode: 0x2183782B (dec: 562264107)
{
	short minX; // size=0, offset=0
	short minY; // size=0, offset=2
	short minZ; // size=0, offset=4
	short maxX; // size=0, offset=6
	short maxY; // size=0, offset=8
	short maxZ; // size=0, offset=10
};

struct _BSPNode // hashcode: 0x60C20F69 (dec: 1623330665)
{
	struct _Sphere_noSq sphere; // size=8, offset=0
	short a; // size=0, offset=8
	short b; // size=0, offset=10
	short c; // size=0, offset=12
	short flags; // size=0, offset=14
	long d; // size=0, offset=16
	void *front; // size=0, offset=20
	void *back; // size=0, offset=24
	struct _Sphere_noSq spectralSphere; // size=8, offset=28
	short front_spectral_error; // size=0, offset=36
	short back_spectral_error; // size=0, offset=38
	short front_material_error; // size=0, offset=40
	short back_material_error; // size=0, offset=42
};

struct _BSPLeaf // hashcode: 0xB2C1AC71 (dec: -1295930255)
{
	struct _Sphere_noSq sphere; // size=8, offset=0
	struct _TFace *faceList; // size=12, offset=8
	short numFaces; // size=0, offset=12
	short flags; // size=0, offset=14
	struct _BoundingBox box; // size=12, offset=16
	struct _BoundingBox spectralBox; // size=12, offset=28
	struct _Sphere_noSq spectralSphere; // size=8, offset=40
};

struct BSPTree // hashcode: 0x17800192 (dec: 394264978)
{
	struct _BSPNode *bspRoot; // size=44, offset=0
	struct _BSPLeaf *startLeaves; // size=48, offset=4
	struct _BSPLeaf *endLeaves; // size=48, offset=8
	struct _Position globalOffset; // size=6, offset=12
	short flags; // size=0, offset=18
	struct _Position localOffset; // size=6, offset=20
	short ID; // size=0, offset=26
	long splineID; // size=0, offset=28
	struct _Instance *instanceSpline; // size=616, offset=32
};

struct _Terrain // hashcode: 0x5D541B4E (dec: 1565793102)
{
	short UnitChangeFlags; // size=0, offset=0
	short spad; // size=0, offset=2
	long lpad2; // size=0, offset=4
	long numIntros; // size=0, offset=8
	struct Intro *introList; // size=76, offset=12
	long numVertices; // size=0, offset=16
	long numFaces; // size=0, offset=20
	long numNormals; // size=0, offset=24
	struct _TVertex *vertexList; // size=12, offset=28
	struct _TFace *faceList; // size=12, offset=32
	struct _Normal *normalList; // size=8, offset=36
	struct DrMoveAniTex *aniList; // size=8, offset=40
	long pad; // size=0, offset=44
	void *StreamUnits; // size=0, offset=48
	struct TextureFT3 *StartTextureList; // size=12, offset=52
	struct TextureFT3 *EndTextureList; // size=12, offset=56
	struct _MorphVertex *MorphDiffList; // size=14, offset=60
	struct _MorphColor *MorphColorList; // size=2, offset=64
	long numBSPTrees; // size=0, offset=68
	struct BSPTree *BSPTreeArray; // size=36, offset=72
	short *morphNormalIdx; // size=0, offset=76
	struct _MultiSignal *signals; // size=904, offset=80
};

struct TClassAttr // hashcode: 0x4DC02369 (dec: 1304437609)
{
	short flags; // size=0, offset=0
	unsigned short sound; // size=0, offset=2
};

struct Level // hashcode: 0x012B0198 (dec: 19595672)
{
	struct _Terrain *terrain; // size=84, offset=0
	struct LightList *lightList; // size=12, offset=4
	long numVMObjects; // size=0, offset=8
	struct _VMObject *vmobjectList; // size=60, offset=12
	long numSpotLights; // size=0, offset=16
	struct SpotLight *spotLightList; // size=40, offset=20
	long numPointLights; // size=0, offset=24
	struct PointLight *pointLightList; // size=24, offset=28
	long numSpotSpecturalLights; // size=0, offset=32
	struct SpotLight *spotSpecturalLightList; // size=40, offset=36
	long numPointSpecturalLights; // size=0, offset=40
	struct PointLight *pointSpecturalLightList; // size=24, offset=44
	long numBGObjects; // size=0, offset=48
	struct _BGObject *bgObjectList; // size=24, offset=52
	long waterZLevel; // size=0, offset=56
	unsigned char backColorR; // size=0, offset=60
	unsigned char backColorG; // size=0, offset=61
	unsigned char backColorB; // size=0, offset=62
	unsigned char cpad1; // size=0, offset=63
	unsigned char specturalColorR; // size=0, offset=64
	unsigned char specturalColorG; // size=0, offset=65
	unsigned char specturalColorB; // size=0, offset=66
	unsigned char cpad2; // size=0, offset=67
	unsigned short fogFar; // size=0, offset=68
	unsigned short fogNear; // size=0, offset=70
	unsigned short spectralFogFar; // size=0, offset=72
	unsigned short spectralFogNear; // size=0, offset=74
	unsigned short waterFogFar; // size=0, offset=76
	unsigned short waterFogNear; // size=0, offset=78
	long depthQBlendStart; // size=0, offset=80
	struct LightList *spectrallightList; // size=12, offset=84
	long numCameras; // size=0, offset=88
	void *cameraList; // size=0, offset=92
	long bspPlaneError; // size=0, offset=96
	long numVGroups; // size=0, offset=100
	struct _VGroup *vGroupList; // size=12, offset=104
	long deathZ; // size=0, offset=108
	long flags; // size=0, offset=112
	struct _MultiSignal *startSignal; // size=904, offset=116
	long numIntros; // size=0, offset=120
	struct Intro *introList; // size=76, offset=124
	struct DrMoveAniTex *bgAniList; // size=8, offset=128
	long numHotSpots; // size=0, offset=132
	struct _HotSpot *hotSpotList; // size=8, offset=136
	void *objectNameList; // size=0, offset=140
	long depthQFogStart; // size=0, offset=144
	long morphLastStep; // size=0, offset=148
	char *worldName; // size=0, offset=152
	struct VramSize vramSize; // size=8, offset=156
	unsigned short holdFogFar; // size=0, offset=164
	unsigned short holdFogNear; // size=0, offset=166
	long numberEnemyUnits; // size=0, offset=168
	char **enemyUnitsNames; // size=0, offset=172
	long **timesSignalList; // size=0, offset=176
	struct _MultiSignal *spectralSignal; // size=904, offset=180
	struct _MultiSignal *materialSignal; // size=904, offset=184
	struct _MultiSignal *startUnitLoadedSignal; // size=904, offset=188
	struct _MultiSignal *startUnitMainSignal; // size=904, offset=192
	struct _MultiSignal *startGoingIntoWaterSignal; // size=904, offset=196
	struct _MultiSignal *startGoingOutOfWaterSignal; // size=904, offset=200
	long unitFlags; // size=0, offset=204
	struct _MultiSignal *SignalListStart; // size=904, offset=208
	struct _MultiSignal *SignalListEnd; // size=904, offset=212
	long numBSPLeaves; // size=0, offset=216
	struct EventPointers *PuzzleInstances; // size=0, offset=220
	long NumberOfPlanMarkers; // size=0, offset=224
	struct _PlanMkr *PlanMarkerList; // size=8, offset=228
	long NumberOfSFXMarkers; // size=0, offset=232
	struct _SFXMkr *SFXMarkerList; // size=36, offset=236
	unsigned long versionNumber; // size=0, offset=240
	char *dynamicMusicName; // size=0, offset=244
	long streamUnitID; // size=0, offset=248
	struct TClassAttr tClassAttr[16]; // size=64, offset=252
	short TODLighting[4][3]; // size=24, offset=316
	unsigned char TODbackColor[4][3]; // size=12, offset=340
	unsigned short TODfogNearFar[4][2]; // size=16, offset=352
	short TODRedScale; // size=0, offset=368
	short TODGrnScale; // size=0, offset=370
	short TODBluScale; // size=0, offset=372
	short TODfogNear; // size=0, offset=374
	short TODfogFar; // size=0, offset=376
	short short_pad; // size=0, offset=378
	unsigned char TODbackColorR; // size=0, offset=380
	unsigned char TODbackColorG; // size=0, offset=381
	unsigned char TODbackColorB; // size=0, offset=382
	unsigned char cpad3; // size=0, offset=383
	struct LightGroup *razielLightGroup; // size=64, offset=384
	struct LightGroup *razielSpectralLightGroup; // size=64, offset=388
};


struct _SavedCinematic // hashcode: 0x1E29151B (dec: 506008859)
{
	struct _Position position; // size=6, offset=0
	struct _Position focusPoint; // size=6, offset=6
	struct _Position base; // size=6, offset=12
	struct _Position targetPos; // size=6, offset=18
	struct _Position targetFocusPoint; // size=6, offset=24
	struct _Position targetBase; // size=6, offset=30
	struct _Rotation baseRot; // size=8, offset=36
	struct _Rotation focusRotation; // size=8, offset=44
	struct _Rotation targetFocusRotation; // size=8, offset=52
	short focusDistance; // size=0, offset=60
	short targetFocusDistance; // size=0, offset=62
	struct _SVector focusPointVel; // size=8, offset=64
	struct _SVector focusPointAccl; // size=8, offset=72
	struct _SVector baseVel; // size=8, offset=80
	struct _SVector baseAccl; // size=8, offset=88
	long maxVel; // size=0, offset=96
	struct MultiSpline *posSpline; // size=0, offset=100
	struct MultiSpline *targetSpline; // size=0, offset=104
	struct Level *level; // size=0, offset=108
};

struct _CameraKey // hashcode: 0xB9E6B724 (dec: -1176062172)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short id; // size=0, offset=6
	short rx; // size=0, offset=8
	short ry; // size=0, offset=10
	short rz; // size=0, offset=12
	short flags; // size=0, offset=14
	short tx; // size=0, offset=16
	short ty; // size=0, offset=18
	short tz; // size=0, offset=20
	short pad; // size=0, offset=22
};

struct _CameraCore_Type // hashcode: 0xD341D51C (dec: -750660324)
{
	struct _Position position; // size=6, offset=0
	short pad1; // size=0, offset=6
	struct MATRIX vvNormalWorVecMat[2]; // size=64, offset=8
	long vvPlaneConsts[6]; // size=24, offset=72
	struct MATRIX *wcTransform; // size=32, offset=96
	long farPlane; // size=0, offset=100
	long projDistance; // size=0, offset=104
	long nearPlane; // size=0, offset=108
	struct MATRIX *wcTransform2; // size=32, offset=112
	struct MATRIX *cwTransform2; // size=32, offset=116
	struct _Normal viewVolumeNormal[5]; // size=40, offset=120
	int leftX; // size=0, offset=160
	int rightX; // size=0, offset=164
	int topY; // size=0, offset=168
	int bottomY; // size=0, offset=172
	struct _Rotation rotation; // size=8, offset=176
	short pad2; // size=0, offset=184
	struct _SVector screenScale; // size=8, offset=186
	short pad3; // size=0, offset=194
	struct _Position debugPos; // size=6, offset=196
	short pad4; // size=0, offset=202
	struct _Rotation debugRot; // size=8, offset=204
	short pad5; // size=0, offset=212
	struct _Position nondebugPos; // size=6, offset=214
	short pad6; // size=0, offset=220
};

struct Camera // hashcode: 0x0670C20F (dec: 108053007)
{
	struct _CameraCore_Type core; // size=224, offset=0
	long shake; // size=0, offset=224
	short shakeFrame; // size=0, offset=228
	short shakeScale; // size=0, offset=230
	long flags; // size=0, offset=232
	long lock; // size=0, offset=236
	short mode; // size=0, offset=240
	short state; // size=0, offset=242
	short posState; // size=0, offset=244
	short rotState; // size=0, offset=246
	short tiltState; // size=0, offset=248
	short distanceState; // size=0, offset=250
	short lagZ; // size=0, offset=252
	short tilt; // size=0, offset=254
	struct _Position focusPoint; // size=6, offset=256
	short focusDistance; // size=0, offset=262
	struct _Instance *focusInstance; // size=616, offset=264
	struct _Position oldFocusInstancePos; // size=6, offset=268
	struct _Position newFocusInstancePos; // size=6, offset=274
	struct _Rotation oldFocusInstanceRot; // size=8, offset=280
	struct _Rotation newFocusInstanceRot; // size=8, offset=288
	struct _SVector focusInstanceVelVec; // size=8, offset=296
	struct _Position focusLeadPivot; // size=6, offset=304
	struct _Position focusOffset; // size=6, offset=310
	struct _Rotation focusRotation; // size=8, offset=316
	short tiltVel; // size=0, offset=324
	short tiltAccl; // size=0, offset=326
	struct _SVector positionVel; // size=8, offset=328
	struct _SVector positionAccl; // size=8, offset=336
	struct _SVector focusPointVel; // size=8, offset=344
	struct _SVector focusPointAccl; // size=8, offset=352
	short focusDistanceVel; // size=0, offset=360
	short focusDistanceAccl; // size=0, offset=362
	struct _SVector focusRotVel; // size=8, offset=364
	struct _SVector focusRotAccl; // size=8, offset=372
	struct _SVector maxFocusVel; // size=8, offset=380
	struct _SVector rotationVel; // size=8, offset=388
	struct _SVector rotationAccl; // size=8, offset=396
	short maxVel; // size=0, offset=404
	short maxRot; // size=0, offset=406
	struct _Position targetPos; // size=6, offset=408
	short targetTilt; // size=0, offset=414
	struct _Rotation targetRotation; // size=8, offset=416
	short targetFocusDistance; // size=0, offset=424
	struct _Position targetFocusPoint; // size=6, offset=426
	short collisionTargetFocusDistance; // size=0, offset=432
	struct _Rotation targetFocusRotation; // size=8, offset=434
	short tfaceTilt; // size=0, offset=442
	struct _Rotation collisionTargetFocusRotation; // size=8, offset=444
	short smooth; // size=0, offset=452
	struct _CameraKey *cameraKey; // size=24, offset=456
	struct _Sphere focusSphere; // size=12, offset=460
	struct _Sphere smallBaseSphere; // size=12, offset=472
	struct _Sphere posSphere; // size=12, offset=484
	short lookTimer; // size=0, offset=496
	short lookSavedMode; // size=0, offset=498
	short presetIndex; // size=0, offset=500
	short presetFocusDistance[3]; // size=6, offset=502
	long minFocusDistance; // size=0, offset=508
	long maxFocusDistance; // size=0, offset=512
	long minTilt; // size=0, offset=516
	long maxTilt; // size=0, offset=520
	long pad[3]; // size=12, offset=524
	long minXYDist; // size=0, offset=536
	long maxXYDist; // size=0, offset=540
	long oppositeError; // size=0, offset=544
	long tempsplinePointAhead; // size=0, offset=548
	long noTeleport; // size=0, offset=552
	long focusDistanceList[3][3]; // size=36, offset=556
	long tiltList[3][3]; // size=36, offset=592
	long cineControl; // size=0, offset=628
	short stack; // size=0, offset=632
	short targetStack; // size=0, offset=634
	long savedMode[3]; // size=12, offset=636
	long savedTargetFocusDistance[3]; // size=12, offset=648
	struct _Rotation savedFocusRotation; // size=8, offset=660
	short savedFocusDistance; // size=0, offset=668
	short signalFocusDistance; // size=0, offset=670
	struct _SavedCinematic savedCinematic[3]; // size=336, offset=672
	struct _Rotation savedfocusRotation; // size=8, offset=1008
	struct _Position signalPos; // size=6, offset=1016
	short pad11; // size=0, offset=1022
	struct _Rotation signalRot; // size=8, offset=1024
	short forced_movement; // size=0, offset=1032
	short last_forced_movement; // size=0, offset=1034
	short rotDirection; // size=0, offset=1036
	unsigned long lastModTime; // size=0, offset=1040
	struct _Rotation lookRot; // size=8, offset=1044
	struct MultiSpline *Spline00; // size=0, offset=1052
	struct MultiSpline *Spline01; // size=0, offset=1056
	struct {
		struct {
			struct MultiSpline *posSpline; // size=0, offset=0
			struct MultiSpline *targetSpline; // size=0, offset=4
			struct _SVector lastSplinePos; // size=8, offset=8
			short splinePointAhead; // size=0, offset=16
			short cinema_done; // size=0, offset=18
			int splinecam_currkey; // size=0, offset=20
			int splinecam_helpkey; // size=0, offset=24
		} Cinematic; // size=28, offset=0, found in object files: debug.o, debug.o
		struct {
			struct _Position offset; // size=6, offset=0
			struct _Rotation rotation; // size=8, offset=6
			long focusDistance; // size=0, offset=16
		} Idle; // size=20, offset=28, found in object files: debug.o, debug.o
		struct {
			struct _TFace *tface; // size=12, offset=0
			struct _TFace *oldTFace; // size=12, offset=4
			struct _SVector oldTargetRot; // size=8, offset=8
			long timer; // size=0, offset=16
			struct _SVector oldFocusInstancePos; // size=8, offset=20
		} Behind; // size=28, offset=48, found in object files: debug.o, debug.o
		struct {
			long stopTimer; // size=0, offset=0
			long stopHit; // size=0, offset=4
			struct _TFace *tface; // size=12, offset=8
			struct _TFace *oldTFace; // size=12, offset=12
			long hit; // size=0, offset=16
		} Follow; // size=20, offset=76, found in object files: debug.o, debug.o
	} data; // size=96, offset=1060, found in object files: debug.o, debug.o
	long cuckooTimer; // size=0, offset=1156
	short teleportZRot; // size=0, offset=1160
	short extraZRot; // size=0, offset=1162
	short extraXRot; // size=0, offset=1164
	short leftTimer; // size=0, offset=1166
	short rightTimer; // size=0, offset=1168
	short collideRotControl; // size=0, offset=1170
	short collision_lastPush; // size=0, offset=1172
	short collision_timer; // size=0, offset=1174
	unsigned long prev_instance_mode; // size=0, offset=1176
	unsigned long instance_mode; // size=0, offset=1180
	long instance_xyvel; // size=0, offset=1184
	long instance_prev_xyvel; // size=0, offset=1188
	struct _Position real_focuspoint; // size=6, offset=1192
	short always_rotate_flag; // size=0, offset=1198
	short follow_flag; // size=0, offset=1200
	short actual_x_rot; // size=0, offset=1202
	short actual_vel_x; // size=0, offset=1204
	short actual_acc_x; // size=0, offset=1206
	short x_rot_change; // size=0, offset=1208
	short focuspoint_fallz; // size=0, offset=1210
	short lead_angle; // size=0, offset=1212
	short lead_vel; // size=0, offset=1214
	short lead_accl; // size=0, offset=1216
	short lead_timer; // size=0, offset=1218
};

struct LightInstance // hashcode: 0xB8D5E61F (dec: -1193941473)
{
	struct _Instance *lightInstance; // size=0, offset=0
	long r; // size=0, offset=4
	long g; // size=0, offset=8
	long b; // size=0, offset=12
	short radius; // size=0, offset=16
	unsigned char segment; // size=0, offset=18
	unsigned char flags; // size=0, offset=19
};

struct _GameTrackerASMData_Type // hashcode: 0x28F0BFB9 (dec: 686866361)
{
	long drawBackFaces; // size=0, offset=0
	long dispPage; // size=0, offset=4
	short MorphTime; // size=0, offset=8
	short MorphType; // size=0, offset=10
	struct LightInstance lightInstances[1]; // size=20, offset=12
};

struct _GameData_Type // hashcode: 0xE05EBAD0 (dec: -530662704)
{
	struct _GameTrackerASMData_Type asmData; // size=32, offset=0
};

struct menu_format_t // hashcode: 0xD91CEBF0 (dec: -652416016)
{
	int xpos; // size=0, offset=0
	int ypos; // size=0, offset=4
	int lineskip; // size=0, offset=8
	int itemskip; // size=0, offset=12
	int width; // size=0, offset=16
	int center; // size=0, offset=20
	int border; // size=0, offset=24
};

struct menu_stack_t // hashcode: 0x04101191 (dec: 68161937)
{
	int (*fn)(); // size=0, offset=0
	int index; // size=0, offset=4
	struct menu_format_t format; // size=28, offset=8
};

struct menu_item_t // hashcode: 0xF260D8A8 (dec: -228534104)
{
	char *text; // size=0, offset=0
	int (*fn)(); // size=0, offset=4
	long parameter; // size=0, offset=8
	long flags; // size=0, offset=12
};

struct menu_t // hashcode: 0x8AB0D2F2 (dec: -1968123150)
{
	int nmenus; // size=0, offset=0
	int nitems; // size=0, offset=4
	int nbytes; // size=0, offset=8
	struct menu_stack_t stack[5]; // size=180, offset=12
	struct menu_item_t items[12]; // size=192, offset=192
	char bytes[512]; // size=512, offset=384
	void (*drawfn)(); // size=0, offset=896
	void *opaque; // size=0, offset=900
};

enum mcpsx_err_t // Hashcode: 0xB64074E4 (dec: -1237289756)
{
	mcpsx_err_none = 0,
	mcpsx_err_card_not_exist = 1,
	mcpsx_err_card_invalid = 2,
	mcpsx_err_new_card = 3,
	mcpsx_err_not_format = 4,
	mcpsx_err_file_not_exist = 5,
	mcpsx_err_already_exists = 6,
	mcpsx_err_block_full = 7,
	mcpsx_err_busy = 8,
	mcpsx_error = 9,
	mcpsx_err_num_items = 10,
};

enum mcard_status_t // Hashcode: 0xD1B8064B (dec: -776468917)
{
	mcard_status_card_not_exist = 0,
	mcard_status_card_invalid = 1,
	mcard_status_not_format = 2,
	mcard_status_new_card = 3,
	mcard_status_ready = 4,
	mcard_status_accessing = 5,
	mcard_status_error = 6,
	mcard_status_num_items = 7,
};

enum state_t // Hashcode: 0x67CC6ED5 (dec: 1741450965)
{
	fsmcard_card_not_exist = 0,
	fsmcard_card_invalid = 1,
	fsmcard_not_format = 2,
	fsmcard_new_card = 3,
	fsmcard_directory = 4,
	fsmcard_ready = 5,
	fsmcard_format = 6,
	fsmcard_unformat = 7,
	fsmcard_delete = 8,
	fsmcard_create = 9,
	fsmcard_write = 10,
	fsmcard_read = 11,
	fsmcard_error = 12,
	fsmcard_num_items = 13,
};

enum fsm_t // Hashcode: 0x64C4BA3C (dec: 1690614332)
{
	fsm_card_not_exist = 0,
	fsm_card_invalid = 1,
	fsm_not_format = 2,
	fsm_new_card = 3,
	fsm_ready = 4,
	fsm_format = 5,
	fsm_start = 6,
	fsm_loading = 7,
	fsm_query_overwrite = 8,
	fsm_overwrite = 9,
	fsm_saving = 10,
	fsm_create = 11,
	fsm_save_complete = 12,
	fsm_error = 13,
	fsm_num_items = 14,
};

struct mcmenu_table_t // hashcode: 0xB78C7C17 (dec: -1215529961)
{
	int (*data_size)(); // size=0, offset=0
	void (*initialize)(); // size=0, offset=4
	void (*terminate)(); // size=0, offset=8
	void (*begin)(); // size=0, offset=12
	void (*end)(); // size=0, offset=16
	int (*set_buffer)(); // size=0, offset=20
	int (*main)(); // size=0, offset=24
	int (*pause)(); // size=0, offset=28
	char *versionID; // size=0, offset=32
};

struct mcpsx_directory_t // hashcode: 0xED9CBF92 (dec: -308494446)
{
	char name[20]; // size=20, offset=0
	int nbytes; // size=0, offset=20
};

typedef enum mcpsx_err_t mcpsx_err_t;

typedef enum state_t fsmcard_t;

typedef enum mcard_status_t mcard_status_t;

typedef enum fsm_t fsm_t;

struct mcard_t // hashcode: 0x55AF6CB2 (dec: 1437559986)
{
	struct {
		mcpsx_err_t err; // size=4, offset=0
		//enum state_t fsm; // size=4, offset=4
		mcard_status_t status; // size=4, offset=8
		int not_exists; // size=0, offset=12
	} state; // size=16, offset=0, found in object files: memcard.o, memcard.o
	struct {
		long parameter; // size=0, offset=0
		long *nfilesptr; // size=0, offset=4
		struct mcpsx_directory_t *directory; // size=24, offset=8
		char *filename; // size=0, offset=12
		void *buffer; // size=0, offset=16
		int nbytes; // size=0, offset=20
		int nblocks; // size=0, offset=24
	} params; // size=28, offset=16, found in object files: memcard.o, memcard.o
	struct mcpsx_t *mcpsx; // size=56, offset=44
	void *opaque; // size=0, offset=48
};

struct mcmenu_t // hashcode: 0xCDD1805D (dec: -841908131)
{
	struct {
		fsm_t fsm; // size=4, offset=0
		fsm_t fsm_prev; // size=4, offset=4
		mcard_status_t status; // size=4, offset=8
		int running; // size=0, offset=12
		int slot; // size=0, offset=16
	} state; // size=20, offset=0, found in object files: memcard.o, memcard.o
	struct {
		int nblocks; // size=0, offset=0
		int nbytes; // size=0, offset=4
		void *buffer; // size=0, offset=8
		struct mcpsx_directory_t directory[15]; // size=360, offset=12
		long nfiles; // size=0, offset=372
	} params; // size=376, offset=20, found in object files: memcard.o, memcard.o
	struct mcard_t *mcard; // size=52, offset=396
	void *opaque; // size=0, offset=400
};

struct memcard_t // hashcode: 0xAEC9A344 (dec: -1362517180)
{
	struct Object *object; // size=76, offset=0
	struct mcmenu_table_t *table; // size=36, offset=4
	struct mcmenu_t *mcmenu; // size=404, offset=8
	short running; // size=0, offset=12
	short wrongVerison; // size=0, offset=14
};

struct _ColorType // hashcode: 0x440E837C (dec: 1141801852)
{
	unsigned char r; // size=0, offset=0
	unsigned char g; // size=0, offset=1
	unsigned char b; // size=0, offset=2
	unsigned char code; // size=0, offset=3
};

struct gSoundData // hashcode: 0x100090FC (dec: 268472572)
{
	unsigned long gMasterVol; // size=0, offset=0
	unsigned long gMusicVol; // size=0, offset=4
	unsigned long gSfxVol; // size=0, offset=8
	unsigned long gVoiceVol; // size=0, offset=12
	char gSfxOn; // size=0, offset=16
	char gMusicOn; // size=0, offset=17
	char gVoiceOn; // size=0, offset=18
	char soundsLoaded; // size=0, offset=19
};

struct GameTracker // hashcode: 0x4EB3EFC5 (dec: 1320415173)
{
	struct _GameData_Type gameData; // size=32, offset=0
	struct menu_t *menu; // size=0, offset=32
	struct memcard_t *memcard; // size=0, offset=36
	struct Level *level; // size=392, offset=40
	struct _Instance *playerInstance; // size=616, offset=44
	long drawPage; // size=0, offset=48
	struct _InstanceList *instanceList; // size=268, offset=52
	struct _InstancePool *instancePool; // size=38204, offset=56
	struct _VertexPool *vertexPool; // size=6336, offset=60
	struct _PrimPool *primPool; // size=96012, offset=64
	struct _ObjectTracker *GlobalObjects; // size=36, offset=68
	long controlCommand[2][5]; // size=40, offset=72
	long controlData[2][5]; // size=40, offset=112
	long overrideData[2][5]; // size=40, offset=152
	long debugFlags; // size=0, offset=192
	long debugFlags2; // size=0, offset=196
	struct CVECTOR wipeColor; // size=4, offset=200
	short wipeTime; // size=0, offset=204
	short maxWipeTime; // size=0, offset=206
	short wipeType; // size=0, offset=208
	short numGSignals; // size=0, offset=210
	void (*gSignal[16]); // size=64, offset=212
	struct LightInfo *lightInfo; // size=1148, offset=276
	void *reqDisp; // size=0, offset=280
	long *drawTimerReturn; // size=0, offset=284
	long usecsStartDraw; // size=0, offset=288
	void *disp; // size=0, offset=292
	unsigned long displayFrameCount; // size=0, offset=296
	unsigned long frameCount; // size=0, offset=300
	unsigned long fps30Count; // size=0, offset=304
	unsigned long vblFrames; // size=0, offset=308
	unsigned long vblCount; // size=0, offset=312
	long numMatrices; // size=0, offset=316
	long gameFlags; // size=0, offset=320
	long streamFlags; // size=0, offset=324
	void *drawNonAnimatedSegmentFunc; // size=0, offset=328
	void *drawAnimatedModelFunc; // size=0, offset=332
	void *drawDisplayPolytopeListFunc; // size=0, offset=336
	void *drawBgFunc; // size=0, offset=340
	struct Level *mainDrawUnit; // size=392, offset=344
	char baseAreaName[16]; // size=16, offset=348
	short levelDone; // size=0, offset=364
	short levelChange; // size=0, offset=366
	short hideBG; // size=0, offset=368
	short gameMode; // size=0, offset=370
	long currentHotSpot; // size=0, offset=372
	long StreamUnitID; // size=0, offset=376
	short SwitchToNewStreamUnit; // size=0, offset=380
	short SwitchToNewWarpIndex; // size=0, offset=382
	char S_baseAreaName[16]; // size=16, offset=384
	short toSignal; // size=0, offset=400
	short fromSignal; // size=0, offset=402
	char LastSignal; // size=0, offset=404
	short StreamNormalA; // size=0, offset=406
	short StreamNormalB; // size=0, offset=408
	short StreamNormalC; // size=0, offset=410
	long StreamNormalD; // size=0, offset=412
	long moveRazielToStreamID; // size=0, offset=416
	struct _ColorType animObjLine; // size=4, offset=420
	struct _ColorType animObjShade; // size=4, offset=424
	long maxIntroFXTime; // size=0, offset=428
	struct gSoundData sound; // size=20, offset=432
	short controllerMode; // size=0, offset=452
	unsigned char plan_collide_override; // size=0, offset=454
	unsigned char cheatMode; // size=0, offset=455
	char currentLvl; // size=0, offset=456
	char lastLvl; // size=0, offset=457
	struct Object *introFX; // size=76, offset=460
	struct Intro *introFXIntro; // size=76, offset=464
	unsigned long **drawOT; // size=0, offset=468
	unsigned long **dispOT; // size=0, offset=472
	struct P_TAG *savedOTStart; // size=8, offset=476
	struct P_TAG *savedOTEnd; // size=8, offset=480
	long introWaitTime; // size=0, offset=484
	long mirrorZPush; // size=0, offset=488
	long defVVRemoveDist; // size=0, offset=492
	long defRemoveDist; // size=0, offset=496
	struct _Position forcedStartPosition; // size=6, offset=500
	short hudCollDisplay; // size=0, offset=506
	long primMemUsed; // size=0, offset=508
	long cheatTimerCount; // size=0, offset=512
	long playerCheatFlags; // size=0, offset=516
	long savedPlayerCameraMode; // size=0, offset=520
	long debugDrawFlags; // size=0, offset=524
	void *planningPool; // size=0, offset=528
	void *enemyPlanPool; // size=0, offset=532
	unsigned char block_collide_override; // size=0, offset=536
	unsigned char raziel_collide_override; // size=0, offset=537
	short timeOfDay; // size=0, offset=538
	long decoupleGame; // size=0, offset=540
	long multGameTime; // size=0, offset=544
	short spectral_fadeValue; // size=0, offset=548
	short material_fadeValue; // size=0, offset=550
	unsigned long drawTime; // size=0, offset=552
	unsigned long currentTime; // size=0, offset=556
	unsigned long currentMaterialTime; // size=0, offset=560
	unsigned long currentSpectralTime; // size=0, offset=564
	unsigned long currentTimeOfDayTime; // size=0, offset=568
	unsigned long lastLoopTime; // size=0, offset=572
	unsigned long timeMult; // size=0, offset=576
	unsigned long globalTimeMult; // size=0, offset=580
	unsigned long spectralTimeMult; // size=0, offset=584
	unsigned long materialTimeMult; // size=0, offset=588
	unsigned long currentTicks; // size=0, offset=592
	unsigned long totalTime; // size=0, offset=596
	unsigned long idleTime; // size=0, offset=600
	long visibleInstances; // size=0, offset=604
	int gameFramePassed; // size=0, offset=608
	unsigned long timeSinceLastGameFrame; // size=0, offset=612
	long frameRateLock; // size=0, offset=616
	short frameRate24fps; // size=0, offset=620
	char monster_collide_override; // size=0, offset=622
	char pad; // size=0, offset=623
};

struct FontChar // hashcode: 0x5A2F9F5B (dec: 1513070427)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	char c; // size=0, offset=4
	char color; // size=0, offset=5
};

struct FontTracker // hashcode: 0xE32D3F0A (dec: -483574006)
{
	struct FontChar font_buffer[256]; // size=1536, offset=0
	long font_xpos; // size=0, offset=1536
	long font_ypos; // size=0, offset=1540
	long font_buffIndex; // size=0, offset=1544
	short font_tpage; // size=0, offset=1548
	short font_clut; // size=0, offset=1550
	short font_vramU; // size=0, offset=1552
	short font_vramV; // size=0, offset=1554
	short font_width; // size=0, offset=1556
	short sprite_sort_push; // size=0, offset=1558
	short font_vramX; // size=0, offset=1560
	short font_vramY; // size=0, offset=1562
	char color_global; // size=0, offset=1564
	char color_local; // size=0, offset=1565
};

struct MainTracker // hashcode: 0x7F315B98 (dec: 2133941144)
{
	long mainState; // size=0, offset=0
	long previousState; // size=0, offset=4
	long movieNum; // size=0, offset=8
	long done; // size=0, offset=12
};

typedef struct GameTracker GameTracker;

typedef struct Camera Camera;

typedef struct MainTracker MainTracker;

extern unsigned char debugOrgFogRed;

extern struct FontTracker fontTracker;

extern void ClearDisplay(); // 0x80037EF8

extern void screen_to_vram(long *screen, int buffer); // 0x80037FB4

extern void show_screen(char *name); // 0x80037FE4

extern void play_movie(char *name); // 0x80038028

extern void InitMainTracker(struct MainTracker *mainTracker); // 0x80038070

extern char * FindTextInLine(char *search_match, char *search_str); // 0x80038080

extern void ExtractWorldName(char *worldName, char *levelName); // 0x80038108

extern void ExtractLevelNum(char *levelNum, char *levelName); // 0x80038154

extern void ProcessArgs(char *baseAreaName, struct GameTracker *gameTracker); // 0x800381C0

extern void InitDisplay(); // 0x800383D8

extern void StartTimer(); // 0x80038554

extern void VblTick(); // 0x800385C0

extern void DrawCallback(); // 0x8003862C

extern void FadeOutSayingLoading(struct GameTracker *gameTracker); // 0x80038684

extern void CheckForDevStation(); // 0x800387D4

extern void MAIN_ShowLoadingScreen(); // 0x80038834

extern long * MAIN_LoadTim(char *name); // 0x800388E4

extern void init_menus(struct GameTracker *gt); // 0x80038904

extern void MAIN_DoMainInit(); // 0x80038950

extern void MAIN_InitVolume(); // 0x80038A44

extern void MAIN_ResetGame(); // 0x80038A84

extern void MAIN_MainMenuInit(); // 0x80038AD4

extern void MAIN_FreeMainMenuStuff(); // 0x80038C6C

extern void MAIN_StartGame(); // 0x80038CDC

//extern long MAIN_DoMainMenu(struct GameTracker *gameTracker, struct MainTracker *mainTracker, long menuPos); // 0x80038D48

extern int MainG2(void *appData); // 0x80038E1C

extern void ProcessArgs(char *baseAreaName, GameTracker *gameTracker);

extern void StartTimer(void);

extern void InitMainTracker(MainTracker *mainTracker);

extern void LOAD_InitCd(void);

extern void EnterCriticalSection(void);

Camera theCamera;

#endif
