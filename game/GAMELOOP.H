#ifndef GAMELOOP_H
#define GAMELOOP_H

struct _Instance
{
	struct NodeType node;
	struct _Instance *next;
	struct _Instance *prev;
	long instanceID;
	long flags;
	long flags2;
	struct Object *object;
	struct Intro *intro;
	void *data;
	void *introData;
	struct _Instance *parent;
	long introNum;
	long birthStreamUnitID;
	long currentStreamUnitID;
	long introUniqueID;
	struct MATRIX *matrix;
	struct MATRIX *oldMatrix;
	struct SoundInstance soundInstanceTbl[4];
	unsigned long maxCheckDistance;
	unsigned long checkMask;
	struct _Position position;
	unsigned char lightGroup;
	struct _Position oldPos;
	unsigned char spectralLightGroup;
	short currentTextureAnimFrame;
	struct _Position initialPos;
	struct _Rotation rotation;
	struct _Rotation oldRotation;
	struct _SVector scale;
	long attachedID;
	long attachedSegment;
	struct MATRIX relativeMatrix;
	struct _TFace *tface;
	struct _TFace *oldTFace;
	void *tfaceLevel;
	void *collideInfo;
	long bspTree;
	short cachedTFace;
	short cachedBSPTree;
	struct _Normal oldWNormal;
	struct _Normal wNormal;
	struct _SVector offset;
	void *dsignal;
	void *shadow0;
	void *shadow1;
	void *extraLight;
	struct _Position extraLightDir;
	short extraLightScale;
	struct _HModel *hModelList;
	short fadeValue;
	short lightMatrix;
	void (*processFunc)();
	void (*collideFunc)();
	void (*additionalCollideFunc)();
	void *additionalDrawFunc;
	unsigned long (*queryFunc)();
	void (*messageFunc)();
	struct _Position shadowPosition;
	short currentModel;
	struct _TFace *waterFace;
	struct _TFace *oldWaterFace;
	struct _Terrain *waterFaceTerrain;
	struct _PlaneConstants halvePlane;
	struct _SVector splitPoint;
	struct _Instance *LinkParent;
	struct _Instance *LinkChild;
	struct _Instance *LinkSibling;
	long ParentLinkNode;
	void *InstanceState;
	char introName[16];
	void *extraData;
	short constrictAngle;
	short petrifyValue;
	long xVel;
	long yVel;
	long zVel;
	long xAccl;
	long yAccl;
	long zAccl;
	long maxXVel;
	long maxYVel;
	long maxZVel;
	long currentMainState;
	long currentSubState;
	long work0;
	long work1;
	long work2;
	long work3;
	long work4;
	long work5;
	long work6;
	long work7;
	long work8;
	long work9;
	struct _G2Anim_Type anim;
	enum _G2Bool_Enum (*rebuildCallback)();
	short splineFlags;
	short targetFrame;
	short clipBeg;
	short clipEnd;
	struct EventAliasCommandStruct aliasCommand;
	long light_color;
	struct CVECTOR *perVertexColor;
};

struct LightInstance
{
	struct _Instance *lightInstance;
	long r;
	long g;
	long b;
	short radius;
	unsigned char segment;
	unsigned char flags;
};

struct _GameTrackerASMData_Type
{
	long drawBackFaces;
	long dispPage;
	short MorphTime;
	short MorphType;
	struct LightInstance lightInstances[1];
};

struct _GameData_Type
{
	struct _GameTrackerASMData_Type asmData;
};

struct GameTracker
{
	struct _GameData_Type gameData;
	struct menu_t *menu;
	struct memcard_t *memcard;
	struct Level *level;
	struct _Instance *playerInstance;
	long drawPage;
	struct _InstanceList *instanceList;
	struct _InstancePool *instancePool;
	struct _VertexPool *vertexPool;
	struct _PrimPool *primPool;
	struct _ObjectTracker *GlobalObjects;
	long controlCommand[2][5];
	long controlData[2][5];
	long overrideData[2][5];
	long debugFlags;
	long debugFlags2;
	struct CVECTOR wipeColor;
	short wipeTime;
	short maxWipeTime;
	short wipeType;
	short numGSignals;
	void(*gSignal[16]);
	struct LightInfo *lightInfo;
	void *reqDisp;
	long *drawTimerReturn;
	long usecsStartDraw;
	void *disp;
	unsigned long displayFrameCount;
	unsigned long frameCount;
	unsigned long fps30Count;
	unsigned long vblFrames;
	unsigned long vblCount;
	long numMatrices;
	long gameFlags;
	long streamFlags;
	void *drawNonAnimatedSegmentFunc;
	void *drawAnimatedModelFunc;
	void *drawDisplayPolytopeListFunc;
	void *drawBgFunc;
	struct Level *mainDrawUnit;
	char baseAreaName[16];
	short levelDone;
	short levelChange;
	short hideBG;
	short gameMode;
	long currentHotSpot;
	long StreamUnitID;
	short SwitchToNewStreamUnit;
	short SwitchToNewWarpIndex;
	char S_baseAreaName[16];
	short toSignal;
	short fromSignal;
	char LastSignal;
	short StreamNormalA;
	short StreamNormalB;
	short StreamNormalC;
	long StreamNormalD;
	long moveRazielToStreamID;
	struct _ColorType animObjLine;
	struct _ColorType animObjShade;
	long introFXTime;
	long maxIntroFXTime;
	struct gSoundData sound;
	short controllerMode;
	unsigned char plan_collide_override;
	unsigned char cheatMode;
	char currentLvl;
	char lastLvl;
	struct Object *introFX;
	struct Intro *introFXIntro;
	unsigned long **drawOT;
	unsigned long **dispOT;
	struct P_TAG *savedOTStart;
	struct P_TAG *savedOTEnd;
	long introWaitTime;
	long mirrorZPush;
	long defVVRemoveDist;
	long defRemoveDist;
	struct _Position forcedStartPosition;
	short hudCollDisplay;
	long primMemUsed;
	char demoMode;
	char setDemoMode;
	char demoIndex;
	char demoEnabled;
	long cheatTimerCount;
	long playerCheatFlags;
	long savedPlayerCameraMode;
	long debugDrawFlags;
	void *planningPool;
	void *enemyPlanPool;
	unsigned char block_collide_override;
	unsigned char raziel_collide_override;
	short timeOfDay;
	long decoupleGame;
	long multGameTime;
	short spectral_fadeValue;
	short material_fadeValue;
	unsigned long drawTime;
	unsigned long currentTime;
	unsigned long currentMaterialTime;
	unsigned long currentSpectralTime;
	unsigned long currentTimeOfDayTime;
	unsigned long lastLoopTime;
	unsigned long timeMult;
	unsigned long globalTimeMult;
	unsigned long spectralTimeMult;
	unsigned long materialTimeMult;
	unsigned long currentTicks;
	unsigned long totalTime;
	unsigned long idleTime;
	long visibleInstances;
	int gameFramePassed;
	unsigned long timeSinceLastGameFrame;
	long frameRateLock;
	short frameRate24fps;
};

static struct GameTracker *gameTracker;

extern struct GameTracker gameTrackerX;

extern void GAMELOOP_AllocStaticMemory();

extern void GAMELOOP_InitGameTracker();

extern void GAMELOOP_SystemInit(struct GameTracker *gameTracker);

extern void GAMELOOP_ResetGameStates();

extern void GAMELOOP_ClearGameTracker();

extern void GAMELOOP_CalcGameTime();

extern void GAMELOOP_SetGameTime(long timeOfDay);

extern int GAMELOOP_GetTimeOfDay();

extern int GAMELOOP_GetTimeOfDayIdx(int timeOfDay);

extern int GAMELOOP_WaitForLoad();

extern struct _StreamUnit *LoadLevels(char *baseAreaName, struct GameTracker *gameTracker);

extern void GAMELOOP_InitStandardObjects();

extern void GAMELOOP_LevelLoadAndInit(char *baseAreaName, struct GameTracker *gameTracker);

extern void GAMELOOP_StreamLevelLoadAndInit(char *baseAreaName, struct GameTracker *gameTracker, int toSignalNum, int fromSignalNum);

extern void GAMELOOP_SetScreenWipe(int time, int maxTime, int type);

extern void GAMELOOP_HandleScreenWipes(unsigned long **drawot);

extern void UpdateFogSettings(struct _StreamUnit *currentUnit, struct Level *level);

extern int CheckForNoBlend(struct _ColorType *Color);

extern void BlendToColor(struct _ColorType *target, struct _ColorType *current, struct _ColorType *dest);

extern void MainRenderLevel(struct _StreamUnit *currentUnit, unsigned long **drawot);

extern void StreamIntroInstancesForUnit(struct _StreamUnit *currentUnit);

extern long StreamRenderLevel(struct _StreamUnit *currentUnit, struct Level *mainLevel, unsigned long **drawot, long portalFogColor);

extern void GAMELOOP_FlipScreenAndDraw(struct GameTracker *gameTracker, unsigned long **drawot);

extern void GAMELOOP_AddClearPrim(unsigned long **drawot);

extern void GAMELOOP_SwitchTheDrawBuffer(unsigned long **drawot);

extern void GAMELOOP_SetupRenderFunction(struct GameTracker *gameTracker);

extern struct _StreamUnit *GAMELOOP_GetMainRenderUnit();

extern void GAMELOOP_DisplayFrame(struct GameTracker *gameTracker);

extern void GAMELOOP_DrawSavedOT(unsigned long **newOT);

extern void ResetPrimPool();

extern void SaveOT();

extern void ResetDrawPage();

extern void GAMELOOP_Set24FPS();

extern void GAMELOOP_Reset24FPS();

extern void GAMELOOP_DoTimeProcess();

extern void GAMELOOP_Process(struct GameTracker *gameTracker);

extern void GAMELOOP_ModeStartRunning();

extern void GAMELOOP_ModeStartPause();

extern void GAMELOOP_DemoSetup();

extern void GAMELOOP_ChangeMode();

extern void GAMELOOP_RequestLevelChange(char *name, short number, struct GameTracker *gameTracker);

extern void PSX_GameLoop(struct GameTracker *gameTracker);

extern struct MATRIX *GAMELOOP_GetMatrices(int numMatrices);

extern struct GameTracker *GAMELOOP_GetGT();

#endif
