#include "THISDUST.H"
#include "GAMELOOP.H"


// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_AllocStaticMemory()
 // line 139, offset 0x8002d6f8
	/* begin block 1 */
		// Start line: 278
	/* end block 1 */
	// End Line: 279

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_AllocStaticMemory(void)

{
  instanceList = (_InstanceList *)MEMPACK_Malloc(0x10c,'\x06');
  instancePool = (_InstancePool *)MEMPACK_Malloc((u_long)&DAT_00009bac,'\x06');
  gOt2 = (u_long **)MEMPACK_Malloc(0x34e18,'\x06');
  PTR_800d1d1c = gOt2 + 0xc00;
  primPool2 = (_PrimPool *)(gOt2 + 0x1800);
  PTR_800d1d24 = (_PrimPool *)(gOt2 + 0x75c3);
  primBase = (char *)gOt2;
  gLightInfo = (LightInfo *)MEMPACK_Malloc(0x47c,'\x06');
  memset(gLightInfo,0,0x47c);
  gPolytopeList = (_PolytopeList *)MEMPACK_Malloc((u_long)&DAT_000018c0,'\x06');
  gVertexPool = (_VertexPool *)gPolytopeList;
  gFXT = (_FXTracker *)MEMPACK_Malloc((u_long)&DAT_000079a8,'\x06');
  fxTracker = gFXT;
  planningPool = MEMPACK_Malloc(3000,'\x06');
  enemyPlanPool = MEMPACK_Malloc(1000,'\x06');
  GlobalObjects = (_ObjectTracker *)MEMPACK_Malloc(0x6c0,'\x06');
  G2Anim_Install();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_InitGameTracker()
 // line 185, offset 0x8002d7e8
	/* begin block 1 */
		// Start line: 186
		// Start offset: 0x8002D7E8

		/* begin block 1.1 */
			// Start line: 186
			// Start offset: 0x8002D7E8
			// Variables:
		// 		int i; // $t4
		/* end block 1.1 */
		// End offset: 0x8002D8C0
		// End Line: 260
	/* end block 1 */
	// End offset: 0x8002D8C0
	// End Line: 266

	/* begin block 2 */
		// Start line: 404
	/* end block 2 */
	// End Line: 405

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ClearGameTracker(void)

{
  int iVar1;
  int iVar2;
  
  gameTrackerX.GlobalObjects = GlobalObjects;
  gameTrackerX.planningPool = planningPool;
  gameTrackerX.enemyPlanPool = enemyPlanPool;
  gameTrackerX.vertexPool = gVertexPool;
  primPool2->lastPrim = primPool2->prim + 0x5db4;
  gameTrackerX.instanceList = instanceList;
  PTR_800d1d24->lastPrim = PTR_800d1d24->prim + 0x5db4;
  gameTrackerX.lightInfo = gLightInfo;
  primPool2->nextPrim = primPool2->prim;
  gameTrackerX.instancePool = instancePool;
  PTR_800d1d24->nextPrim = PTR_800d1d24->prim;
  iVar2 = 0;
  iVar1 = 0;
  gameTrackerX.multGameTime = 10;
  gameTrackerX.material_fadeValue = 0x1000;
  gameTrackerX.spectral_fadeValue = 0;
  gameTrackerX.decoupleGame = 1;
  gameTrackerX.frameRateLock = 1;
  gameTrackerX.primPool = primPool2;
  gameTrackerX.drawOT = gOt2;
  gameTrackerX.dispOT = PTR_800d1d1c;
  gameTrackerX.frameRate24fps = 1;
  do {
    iVar2 = iVar2 + 1;
    *(undefined2 *)((int)&(gameTrackerX.GlobalObjects)->objectStatus + iVar1) = 0;
    iVar1 = iVar1 + 0x24;
  } while (iVar2 < 0x30);
  gameTrackerX.gameData.asmData.MorphTime = 1000;
  OBTABLE_ClearObjectReferences();
  EVENT_InitTimers();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SystemInit(struct GameTracker *gameTracker /*$a0*/)
 // line 281, offset 0x8002d8e8
	/* begin block 1 */
		// Start line: 796
	/* end block 1 */
	// End Line: 797

void GAMELOOP_SystemInit(GameTracker *gameTracker)

{
  GAMELOOP_AllocStaticMemory();
  INSTANCE_InitInstanceList(instanceList,instancePool);
  GAMELOOP_ClearGameTracker();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_ResetGameStates()
 // line 294, offset 0x8002d920
	/* begin block 1 */
		// Start line: 822
	/* end block 1 */
	// End Line: 823

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ResetGameStates(void)

{
  EVENT_InitTimers();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_ClearGameTracker()
 // line 300, offset 0x8002d940
	/* begin block 1 */
		// Start line: 834
	/* end block 1 */
	// End Line: 835

	/* begin block 2 */
		// Start line: 845
	/* end block 2 */
	// End Line: 846

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_InitGameTracker(void)

{
  gameTrackerX.gameData.asmData.drawBackFaces = 0;
  gameTrackerX.gameData.asmData.MorphTime = 1000;
  gameTrackerX.frameCount = 0;
  gameTrackerX.fps30Count = 0;
  gameTrackerX.gameFlags = 0;
  gameTrackerX.currentHotSpot = 0;
  gameTrackerX.SwitchToNewStreamUnit = 0;
  gameTrackerX.currentTime = 0;
  gameTrackerX.currentTicks = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_CalcGameTime()
 // line 323, offset 0x8002d970
	/* begin block 1 */
		// Start line: 325
		// Start offset: 0x8002D970
		// Variables:
	// 		long time; // $a1
	/* end block 1 */
	// End offset: 0x8002D970
	// End Line: 329

	/* begin block 2 */
		// Start line: 890
	/* end block 2 */
	// End Line: 891

	/* begin block 3 */
		// Start line: 891
	/* end block 3 */
	// End Line: 892

	/* begin block 4 */
		// Start line: 895
	/* end block 4 */
	// End Line: 896

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_CalcGameTime(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (gameTrackerX.currentTimeOfDayTime * gameTrackerX.multGameTime) / 60000 + 0x2d0;
  iVar1 = iVar2 / 0x3c;
  gameTrackerX.timeOfDay =
       (short)iVar1 * 0x28 +
       ((short)(iVar1 / 6 + (iVar1 >> 0x1f) >> 2) - (short)(iVar1 >> 0x1f)) * -0x960 + (short)iVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SetGameTime(long timeOfDay /*$a1*/)
 // line 334, offset 0x8002da1c
	/* begin block 1 */
		// Start line: 335
		// Start offset: 0x8002DA1C
		// Variables:
	// 		long tim; // $v1
	/* end block 1 */
	// End offset: 0x8002DA74
	// End Line: 341

	/* begin block 2 */
		// Start line: 914
	/* end block 2 */
	// End Line: 915

void GAMELOOP_SetGameTime(long timeOfDay)

{
  int iVar1;
  int iVar2;
  
  iVar1 = timeOfDay + (timeOfDay / 100) * -0x28;
  iVar2 = iVar1 + -0x2d0;
  if (iVar2 < 0) {
    iVar2 = iVar1 + 0x2d0;
  }
  gameTrackerX.currentMaterialTime = (iVar2 * 60000) / gameTrackerX.multGameTime;
  gameTrackerX.timeOfDay = (short)timeOfDay;
  gameTrackerX.currentTimeOfDayTime = gameTrackerX.currentMaterialTime;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GAMELOOP_GetTimeOfDay()
 // line 351, offset 0x8002dab0
	/* begin block 1 */
		// Start line: 353
		// Start offset: 0x8002DAB0
		// Variables:
	// 		int timeOfDay; // $v1
	/* end block 1 */
	// End offset: 0x8002DAF4
	// End Line: 378

	/* begin block 2 */
		// Start line: 951
	/* end block 2 */
	// End Line: 952

	/* begin block 3 */
		// Start line: 952
	/* end block 3 */
	// End Line: 953

	/* begin block 4 */
		// Start line: 954
	/* end block 4 */
	// End Line: 955

/* WARNING: Unknown calling convention yet parameter storage is locked */

int GAMELOOP_GetTimeOfDay(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)gameTrackerX.timeOfDay;
  if (iVar2 - 0x259U < 99) {
    return 600;
  }
  iVar1 = 700;
  if ((1099 < iVar2 - 700U) && (iVar1 = 0x708, 99 < iVar2 - 0x708U)) {
    return 0x76c;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GAMELOOP_GetTimeOfDayIdx(int timeOfDay /*$a0*/)
 // line 380, offset 0x8002dafc
	/* begin block 1 */
		// Start line: 1019
	/* end block 1 */
	// End Line: 1020

	/* begin block 2 */
		// Start line: 1021
	/* end block 2 */
	// End Line: 1022

int GAMELOOP_GetMatrices(int timeOfDay)

{
  int iVar1;
  
  if (timeOfDay - 0x259U < 99) {
    return 1;
  }
  iVar1 = 2;
  if ((1099 < timeOfDay - 700U) && (iVar1 = 3, 99 < timeOfDay - 0x708U)) {
    return 0;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GAMELOOP_WaitForLoad()
 // line 808, offset 0x8002db40
	/* begin block 1 */
		// Start line: 1477
	/* end block 1 */
	// End Line: 1478

	/* begin block 2 */
		// Start line: 1885
	/* end block 2 */
	// End Line: 1886

/* WARNING: Unknown calling convention yet parameter storage is locked */

int GAMELOOP_WaitForLoad(void)

{
  int iVar1;
  
  if ((gameTrackerX.debugFlags & 0x80000U) != 0) {
    VOICEXA_Tick();
  }
  iVar1 = STREAM_PollLoadQueue();
  return iVar1;
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ LoadLevels(char *baseAreaName /*$s2*/, struct GameTracker *gameTracker /*$s3*/)
 // line 825, offset 0x8002db78
	/* begin block 1 */
		// Start line: 826
		// Start offset: 0x8002DB78
		// Variables:
	// 		struct _SVector offset; // stack offset -32
	// 		struct _StreamUnit *streamUnit; // $s0
	// 		static char oldArea[16]; // offset 0xc

		/* begin block 1.1 */
			// Start line: 844
			// Start offset: 0x8002DBFC
			// Variables:
		// 		int num; // $v0
		// 		int waitFor; // $s1
		/* end block 1.1 */
		// End offset: 0x8002DC68
		// End Line: 865

		/* begin block 1.2 */
			// Start line: 888
			// Start offset: 0x8002DCE0
			// Variables:
		// 		short _x0; // $a3
		// 		short _y0; // $t0
		// 		short _z0; // $v0
		// 		short _x1; // $v1
		// 		short _y1; // $t2
		// 		short _z1; // $t1
		// 		struct _SVector *_v; // $a2
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $t1
		/* end block 1.2 */
		// End offset: 0x8002DCE0
		// End Line: 888
	/* end block 1 */
	// End offset: 0x8002DCE0
	// End Line: 892

	/* begin block 2 */
		// Start line: 1919
	/* end block 2 */
	// End Line: 1920

_StreamUnit * UNDERWORLD_LoadLevel(char *baseAreaName,GameTracker *gameTracker)

{
  short sVar1;
  size_t sVar2;
  _StreamUnit *streamUnit;
  int iVar3;
  int iVar4;
  Level *pLVar5;
  _BSPNode *p_Var6;
  _MultiSignal *p_Var7;
  BSPTree *pBVar8;
  _SVector local_20;
  
  sVar2 = strlen("");
  if (sVar2 != 0) {
    STREAM_AbortAreaLoad("");
  }
  strcmp("",baseAreaName);
  LOAD_ReadDirectory(baseAreaName);
  streamUnit = LoadLevels(gameTracker,baseAreaName,(StreamUnitPortal *)0x0,0);
  if (streamUnit->used == 1) {
    DRAW_LoadingMessage();
    sVar1 = streamUnit->used;
    while (sVar1 == 1) {
      GAMELOOP_WaitForLoad();
      sVar1 = streamUnit->used;
    }
    STREAM_NextLoadFromHead();
    STREAM_LoadMainVram(gameTracker,baseAreaName,streamUnit);
    iVar3 = GAMELOOP_WaitForLoad();
    do {
      iVar4 = GAMELOOP_WaitForLoad();
      if (iVar4 == 0) break;
    } while (iVar3 + -1 <= iVar4);
  }
  else {
    STREAM_LoadMainVram(gameTracker,baseAreaName,streamUnit);
  }
  pLVar5 = streamUnit->level;
  p_Var7 = pLVar5->startUnitMainSignal;
  if (p_Var7 != (_MultiSignal *)0x0) {
    if (gameTracker->playerInstance != (_Instance *)0x0) {
      p_Var7->flags = p_Var7->flags | 1;
      SIGNAL_HandleFogNear
                (gameTracker->playerInstance,streamUnit->level->startUnitMainSignal->signalList,0);
      EVENT_AddSignalToReset(streamUnit->level->startUnitMainSignal);
    }
    pLVar5 = streamUnit->level;
  }
  pBVar8 = pLVar5->terrain->BSPTreeArray;
  p_Var6 = pBVar8->bspRoot;
  local_20.x = -((p_Var6->sphere).position.x + (pBVar8->globalOffset).x);
  local_20.y = -((p_Var6->sphere).position.y + (pBVar8->globalOffset).y);
  local_20.z = -((p_Var6->sphere).position.z + (pBVar8->globalOffset).z);
  PreloadAllConnectedUnits(gameTracker,streamUnit,&local_20);
  return streamUnit;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_InitStandardObjects()
 // line 897, offset 0x8002dd74
	/* begin block 1 */
		// Start line: 898
		// Start offset: 0x8002DD74
		// Variables:
	// 		static char (*sobjects[10]); // offset 0x0
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x8002DDB8
	// End Line: 913

	/* begin block 2 */
		// Start line: 2080
	/* end block 2 */
	// End Line: 2081

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_InitStandardObjects(void)

{
  char *name;
  undefined **ppuVar1;
  u_int uVar2;
  
  LOAD_DumpCurrentDir();
  uVar2 = 0;
  ppuVar1 = &PTR_s_raziel_800c8e94;
  do {
    name = *ppuVar1;
    ppuVar1 = ppuVar1 + 1;
    uVar2 = uVar2 + 1;
    InsertGlobalObject(name,&gameTrackerX);
  } while (uVar2 < 10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_LevelLoadAndInit(char *baseAreaName /*$s0*/, struct GameTracker *gameTracker /*$s3*/)
 // line 916, offset 0x8002ddcc
	/* begin block 1 */
		// Start line: 917
		// Start offset: 0x8002DDCC
		// Variables:
	// 		long i; // $s1
	// 		struct _StreamUnit *streamUnit; // $s2

		/* begin block 1.1 */
			// Start line: 995
			// Start offset: 0x8002DEFC
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $a0
		// 		short _z1; // $v1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v1
		/* end block 1.1 */
		// End offset: 0x8002DEFC
		// End Line: 995
	/* end block 1 */
	// End offset: 0x8002E0D4
	// End Line: 1098

	/* begin block 2 */
		// Start line: 2122
	/* end block 2 */
	// End Line: 2123

void GAMELOOP_StreamLevelLoadAndInit(char *baseAreaName,GameTracker *gameTracker)

{
  _InstanceList *list;
  _InstancePool *pool;
  _StreamUnit *p_Var1;
  int iVar2;
  int iVar3;
  _Instance *p_Var4;
  _MultiSignal *p_Var5;
  Level *pLVar6;
  int iVar7;
  
  G2Anim_ResetInternalState();
  pool = instancePool;
  list = instanceList;
  gameTracker->playerInstance = (_Instance *)0x0;
  INSTANCE_InitInstanceList(list,pool);
  GAMELOOP_InitGameTracker();
  CAMERA_Normalize(&theCamera);
  PLANAPI_InitPlanning(planningPool);
  ENMYPLAN_InitEnemyPlanPool(enemyPlanPool);
  FX_Init(fxTracker);
  WARPGATE_IsWarpgateInUse();
  DRAW_InitShadow();
  GAMELOOP_InitStandardObjects();
  p_Var1 = UNDERWORLD_LoadLevel(baseAreaName,gameTracker);
  do {
    iVar2 = STREAM_PollLoadQueue();
  } while (iVar2 != 0);
  gameTracker->introFX = (void *)0x0;
  pLVar6 = p_Var1->level;
  RENDER_currentStreamUnitID = *(short *)&gameTracker->StreamUnitID;
  fontsObject = (Object *)(void *)0x0;
  iVar2 = 0;
  if (0 < pLVar6->numIntros) {
    iVar7 = 0;
    do {
      iVar3 = strcpy(pLVar6->introList->name + iVar7,"raziel");
      if (iVar3 == 0) {
        INSTANCE_InsertInstanceGroup
                  ((Intro *)(p_Var1->level->introList->name + iVar7),*(short *)&p_Var1->StreamUnitID
                  );
        break;
      }
      pLVar6 = p_Var1->level;
      iVar2 = iVar2 + 1;
      iVar7 = iVar7 + 0x4c;
    } while (iVar2 < pLVar6->numIntros);
  }
  gameTracker->playerInstance->data = gameTracker->playerInstance->object->data;
  CAMERA_SetProjDistance(&theCamera,gameTracker->playerInstance);
  p_Var4 = gameTracker->playerInstance;
  theCamera.core.position.x = (p_Var4->position).x;
  theCamera.core.position.y = (p_Var4->position).y;
  theCamera.core.position.z = (p_Var4->position).z;
  SetFogNearFar((u_int)p_Var1->level->fogNear,(u_int)p_Var1->level->fogFar,0x140);
  SetFarColor(0,0,0);
  clearRect.r0 = p_Var1->level->backColorR;
                    /* WARNING: Read-only address (ram,0x800d20ac) is written */
  clearRect.g0 = p_Var1->level->backColorG;
                    /* WARNING: Read-only address (ram,0x800d20ad) is written */
  clearRect.b0 = p_Var1->level->backColorB;
                    /* WARNING: Read-only address (ram,0x800d20ae) is written */
  BLK_FILL_800d20b8.r0 = p_Var1->level->backColorR;
                    /* WARNING: Read-only address (ram,0x800d20bc) is written */
  BLK_FILL_800d20b8.g0 = p_Var1->level->backColorG;
                    /* WARNING: Read-only address (ram,0x800d20bd) is written */
  BLK_FILL_800d20b8.b0 = p_Var1->level->backColorB;
                    /* WARNING: Read-only address (ram,0x800d20be) is written */
  LIGHT_ActivateSources(gLightInfo);
  gameTracker->wipeType = 10;
  gameTracker->hideBG = 0;
  gameTracker->wipeTime = 0x1e;
  gameTracker->maxWipeTime = 0x1e;
  p_Var5 = p_Var1->level->startSignal;
  if (p_Var5 != (_MultiSignal *)0x0) {
    p_Var5->flags = p_Var5->flags | 1;
    SIGNAL_HandleFogNear(gameTracker->playerInstance,p_Var1->level->startSignal->signalList,0);
    EVENT_AddSignalToReset(p_Var1->level->startSignal);
  }
  gameTracker->vblFrames = 0;
  p_Var5 = p_Var1->level->startUnitMainSignal;
  if ((p_Var5 != (_MultiSignal *)0x0) && (gameTracker->playerInstance != (_Instance *)0x0)) {
    p_Var5->flags = p_Var5->flags | 1;
    SIGNAL_HandleFogNear
              (gameTracker->playerInstance,p_Var1->level->startUnitMainSignal->signalList,0);
    EVENT_AddSignalToReset(p_Var1->level->startUnitMainSignal);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_StreamLevelLoadAndInit(char *baseAreaName /*$a0*/, struct GameTracker *gameTracker /*$a1*/, int toSignalNum /*$a2*/, int fromSignalNum /*$a3*/)
 // line 1101, offset 0x8002e0f0
	/* begin block 1 */
		// Start line: 1102
		// Start offset: 0x8002E0F0
	/* end block 1 */
	// End offset: 0x8002E0F0
	// End Line: 1102

	/* begin block 2 */
		// Start line: 2556
	/* end block 2 */
	// End Line: 2557

void GAMELOOP_LevelLoadAndInit
               (char *baseAreaName,GameTracker *gameTracker,int toSignalNum,int fromSignalNum)

{
  UNDERWORLD_LoadLevel(baseAreaName,gameTracker);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SetScreenWipe(int time /*$a0*/, int maxTime /*$a1*/, int type /*$a2*/)
 // line 1120, offset 0x8002e110
	/* begin block 1 */
		// Start line: 2594
	/* end block 1 */
	// End Line: 2595

	/* begin block 2 */
		// Start line: 2595
	/* end block 2 */
	// End Line: 2596

void GAMELOOP_SetScreenWipe(int time,int maxTime,int type)

{
  gameTrackerX.wipeTime = (short)time;
  gameTrackerX.maxWipeTime = (short)maxTime;
  gameTrackerX.wipeType = (short)type;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_HandleScreenWipes(unsigned long **drawot /*$s4*/)
 // line 1128, offset 0x8002e124
	/* begin block 1 */
		// Start line: 1129
		// Start offset: 0x8002E124
		// Variables:
	// 		long temp; // $s0
	// 		struct _PrimPool *primPool; // $s3
	/* end block 1 */
	// End offset: 0x8002E570
	// End Line: 1477

	/* begin block 2 */
		// Start line: 2610
	/* end block 2 */
	// End Line: 2611

	/* begin block 3 */
		// Start line: 2625
	/* end block 3 */
	// End Line: 2626

void SIGNAL_HandleScreenWipe(u_long **drawot)

{
  _PrimPool *primPool;
  int r;
  
  primPool = gameTrackerX.primPool;
  if ((GlobalSave->flags & 1U) != 0) {
    DRAW_FlatQuad(&gameTrackerX.wipeColor,0,0,0x200,0,0,0x1e,0x200,0x1e,gameTrackerX.primPool,drawot
                 );
    DRAW_FlatQuad(&gameTrackerX.wipeColor,0,0xd2,0x200,0xd2,0,0xf0,0x200,0xf0,primPool,drawot);
  }
  r = (int)gameTrackerX.wipeTime;
  if (r < 1) {
    if (r < -1) {
      if (gameTrackerX.wipeType == 10) {
        r = (int)(short)((((int)gameTrackerX.maxWipeTime + r + 2) * 0xff) /
                        (int)gameTrackerX.maxWipeTime);
        DRAW_TranslucentQuad(0,0,0x200,0,0,0xf0,0x200,0xf0,r,r,r,2,primPool,drawot);
      }
      else {
        if (gameTrackerX.wipeType == 0xb) {
          r = (int)(short)((((int)gameTrackerX.maxWipeTime + r) * 0xff) /
                          (int)gameTrackerX.maxWipeTime);
          DRAW_TranslucentQuad(0,0,0x200,0,0,0x1e,0x200,0x1e,r,r,r,2,primPool,drawot);
          DRAW_TranslucentQuad(0,0xd2,0x200,0xd2,0,0xf0,0x200,0xf0,r,r,r,2,primPool,drawot);
          if (gameTrackerX.wipeTime == -2) {
            GlobalSave->flags = GlobalSave->flags | 1;
          }
        }
      }
      if (gameTrackerX.gameFramePassed != 0) {
        gameTrackerX.wipeTime = gameTrackerX.wipeTime + 1;
      }
    }
    else {
      if (r == -1) {
        if (gameTrackerX.wipeType == 0xb) {
          GlobalSave->flags = GlobalSave->flags | 1;
        }
        else {
          DRAW_FlatQuad(&gameTrackerX.wipeColor,0,0,0x200,0,0,0xf0,0x200,0xf0,primPool,drawot);
        }
      }
      else {
        theCamera.core.screenScale.z = 0x1000;
        theCamera.core.screenScale.y = 0x1000;
        theCamera.core.screenScale.x = 0x1000;
      }
    }
  }
  else {
    if (gameTrackerX.wipeType == 10) {
      r = (int)(short)((r * 0xff) / (int)gameTrackerX.maxWipeTime);
      DRAW_TranslucentQuad(0,0,0x200,0,0,0xf0,0x200,0xf0,r,r,r,2,primPool,drawot);
    }
    else {
      if (gameTrackerX.wipeType == 0xb) {
        r = (int)(short)((r * 0xff) / (int)gameTrackerX.maxWipeTime);
        DRAW_TranslucentQuad(0,0,0x200,0,0,0x1e,0x200,0x1e,r,r,r,2,primPool,drawot);
        DRAW_TranslucentQuad(0,0xd2,0x200,0xd2,0,0xf0,0x200,0xf0,r,r,r,2,primPool,drawot);
        GlobalSave->flags = GlobalSave->flags & 0xfffe;
      }
    }
    if (gameTrackerX.gameFramePassed != 0) {
      gameTrackerX.wipeTime = gameTrackerX.wipeTime + -1;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ UpdateFogSettings(struct _StreamUnit *currentUnit /*$s2*/, struct Level *level /*$s0*/)
 // line 1620, offset 0x8002e590
	/* begin block 1 */
		// Start line: 1621
		// Start offset: 0x8002E590
		// Variables:
	// 		int changed; // $a2
	// 		int setflag; // $s1
	// 		int FogFar; // $a1
	// 		int FogNear; // $a0
	/* end block 1 */
	// End offset: 0x8002E6A0
	// End Line: 1668

	/* begin block 2 */
		// Start line: 3611
	/* end block 2 */
	// End Line: 3612

void UpdateFogSettings(_StreamUnit *currentUnit,Level *level)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  u_int uVar6;
  int iVar7;
  int iVar8;
  
  bVar4 = false;
  uVar1 = currentUnit->TargetFogNear;
  iVar7 = (int)(short)uVar1;
  uVar6 = (u_int)level->fogNear;
  uVar2 = currentUnit->TargetFogFar;
  iVar8 = (int)(short)uVar2;
  bVar5 = false;
  if (iVar7 < (int)uVar6) {
    level->fogNear = (ushort)(uVar6 - 500);
    bVar3 = iVar7 < (int)(uVar6 - 500 & 0xffff);
LAB_8002e5fc:
    bVar4 = true;
    if (!bVar3) {
      bVar5 = true;
      level->fogNear = uVar1;
    }
  }
  else {
    if ((int)uVar6 < iVar7) {
      level->fogNear = (ushort)(uVar6 + 500);
      bVar3 = (int)(uVar6 + 500 & 0xffff) < iVar7;
      goto LAB_8002e5fc;
    }
    bVar5 = true;
  }
  uVar6 = (u_int)level->fogFar;
  if (iVar8 < (int)uVar6) {
    level->fogFar = (ushort)(uVar6 - 500);
    bVar4 = true;
    if (iVar8 < (int)(uVar6 - 500 & 0xffff)) {
      bVar5 = false;
      goto LAB_8002e670;
    }
  }
  else {
    if (iVar8 <= (int)uVar6) goto LAB_8002e670;
    level->fogFar = (ushort)(uVar6 + 500);
    bVar4 = true;
    if ((int)(uVar6 + 500 & 0xffff) < iVar8) {
      bVar5 = false;
      goto LAB_8002e670;
    }
  }
  bVar4 = true;
  level->fogFar = uVar2;
LAB_8002e670:
  if ((bVar4) && (LIGHT_CalcDQPTable(level), bVar5)) {
    currentUnit->TargetFogNear = level->fogNear;
    currentUnit->TargetFogFar = level->fogFar;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CheckForNoBlend(struct _ColorType *Color /*$a0*/)
 // line 1670, offset 0x8002e6b8
	/* begin block 1 */
		// Start line: 3722
	/* end block 1 */
	// End Line: 3723

	/* begin block 2 */
		// Start line: 3723
	/* end block 2 */
	// End Line: 3724

int CheckForNoBlend(_ColorType *Color)

{
  int iVar1;
  
  iVar1 = 0;
  if (((Color->r < 5) && (iVar1 = 0, Color->g < 5)) && (iVar1 = 1, 4 < Color->b)) {
    iVar1 = 0;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ BlendToColor(struct _ColorType *target /*$s1*/, struct _ColorType *current /*$a1*/, struct _ColorType *dest /*$s0*/)
 // line 1680, offset 0x8002e700
	/* begin block 1 */
		// Start line: 3742
	/* end block 1 */
	// End Line: 3743

void BlendToColor(_ColorType *target,_ColorType *current,_ColorType *dest)

{
  int iVar1;
  
  LoadAverageCol((byte *)target,(byte *)current,0x200,0xe00,(undefined *)dest);
  iVar1 = (u_int)target->r - (u_int)dest->r;
  if (iVar1 < 0) {
    if (4 < (int)((u_int)dest->r - (u_int)target->r)) goto LAB_8002e7dc;
  }
  else {
    if (4 < iVar1) {
      dest->code = '\0';
      return;
    }
  }
  iVar1 = (u_int)target->g - (u_int)dest->g;
  if (iVar1 < 0) {
    if (4 < (int)((u_int)dest->g - (u_int)target->g)) goto LAB_8002e7dc;
  }
  else {
    if (4 < iVar1) {
      dest->code = '\0';
      return;
    }
  }
  iVar1 = (u_int)target->b - (u_int)dest->b;
  if (iVar1 < 0) {
    if (4 < (int)((u_int)dest->b - (u_int)target->b)) goto LAB_8002e7dc;
  }
  else {
    if (4 < iVar1) {
      dest->code = '\0';
      return;
    }
  }
  *dest = *target;
LAB_8002e7dc:
  dest->code = '\0';
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MainRenderLevel(struct _StreamUnit *currentUnit /*$s7*/, unsigned long **drawot /*$fp*/)
 // line 1697, offset 0x8002e7f4
	/* begin block 1 */
		// Start line: 1698
		// Start offset: 0x8002E7F4
		// Variables:
	// 		struct Level *level; // $s0
	// 		struct GameTracker *gameTracker; // $s5
	// 		struct _Terrain *terrain; // $s4
	// 		int curTree; // $s1
	// 		long BackColor; // stack offset -48
	// 		struct _Position cam_pos_save; // stack offset -96
	// 		struct MATRIX cam_mat_save; // stack offset -88
	// 		struct _Instance *saveLightInstance; // $s2

		/* begin block 1.1 */
			// Start line: 1750
			// Start offset: 0x8002E8D0
			// Variables:
		// 		int time; // $a2
		/* end block 1.1 */
		// End offset: 0x8002E904
		// End Line: 1756

		/* begin block 1.2 */
			// Start line: 1764
			// Start offset: 0x8002E950
			// Variables:
		// 		int tod; // $v1
		/* end block 1.2 */
		// End offset: 0x8002E9CC
		// End Line: 1778

		/* begin block 1.3 */
			// Start line: 1853
			// Start offset: 0x8002EB38
			// Variables:
		// 		struct _SVector tmp; // stack offset -56
		// 		struct BSPTree *bsp; // $s0
		/* end block 1.3 */
		// End offset: 0x8002EC30
		// End Line: 1910
	/* end block 1 */
	// End offset: 0x8002ED24
	// End Line: 1930

	/* begin block 2 */
		// Start line: 3777
	/* end block 2 */
	// End Line: 3778

/* WARNING: This function may have set the stack pointer */
/* WARNING: Could not reconcile some variable overlaps */

void MainRenderLevel(_StreamUnit *currentUnit,u_long **drawot)

{
  MATRIX *pMVar1;
  LightInfo *lightInfo;
  _Instance *p_Var2;
  u_long *puVar3;
  ushort uVar4;
  int unitID;
  u_int uVar5;
  Level *level;
  int **ppiVar6;
  _Instance *p_Var7;
  int iVar8;
  _Terrain *terrain;
  int **local_64;
  u_char local_60;
  short local_5c;
  u_char local_58;
  u_char local_54;
  u_char local_50;
  u_char local_4c;
  u_char local_48;
  long local_44;
  long local_40;
  long local_3c;
  short local_38;
  short local_36;
  short local_34;
  _ColorType local_30 [2];
  
  level = currentUnit->level;
  terrain = level->terrain;
  UpdateFogSettings(currentUnit,level);
  currentUnit->FrameCount = gameTrackerX.displayFrameCount;
  SetFogNearFar((u_int)level->fogNear,(u_int)level->fogFar,0x140);
  SetFarColor(0,0,0);
  clearRect.r0 = level->backColorR;
                    /* WARNING: Read-only address (ram,0x800d20ac) is written */
  clearRect.g0 = level->backColorG;
                    /* WARNING: Read-only address (ram,0x800d20ad) is written */
  clearRect.b0 = level->backColorB;
                    /* WARNING: Read-only address (ram,0x800d20ae) is written */
  BLK_FILL_800d20b8.r0 = level->backColorR;
                    /* WARNING: Read-only address (ram,0x800d20bc) is written */
  BLK_FILL_800d20b8.g0 = level->backColorG;
                    /* WARNING: Read-only address (ram,0x800d20bd) is written */
  BLK_FILL_800d20b8.b0 = level->backColorB;
                    /* WARNING: Read-only address (ram,0x800d20be) is written */
  if ((int)gameTrackerX.gameData.asmData.MorphTime == 1000) {
    if (gameTrackerX.gameData.asmData.MorphType == 1) {
      local_30[0] = *(_ColorType *)&level->specturalColorR;
    }
    else {
      local_30[0] = *(_ColorType *)&level->backColorR;
    }
  }
  else {
    unitID = ((int)gameTrackerX.gameData.asmData.MorphTime << 0xc) / 1000;
    if (gameTrackerX.gameData.asmData.MorphType == 1) {
      unitID = 0x1000 - unitID;
    }
    LoadAverageCol(&level->specturalColorR,&level->backColorR,unitID,0x1000 - unitID,
                   (undefined *)local_30);
  }
  BlendToColor(local_30,(_ColorType *)&currentUnit->FogColor,(_ColorType *)&currentUnit->FogColor);
  depthQBackColor = currentUnit->FogColor;
  unitID = GAMELOOP_GetTimeOfDay();
  if ((((unitID != 600) && (unitID != 0x708)) || ((level->unitFlags & 2U) == 0)) &&
     (gameTrackerX.gameData.asmData.MorphTime == 1000)) {
    depthQBackColor = depthQBackColor & 0xfff8f8f8 | 0x40404;
  }
  depthQFogStart = (u_int)level->fogNear;
  depthQFogFar = (u_int)level->fogFar;
  unitID = CheckForNoBlend((_ColorType *)&depthQBackColor);
  depthQBlendStart = 0xffff;
  if (unitID == 0) {
    depthQBlendStart = depthQFogStart;
  }
                    /* WARNING: Read-only address (ram,0x800d20ac) is written */
  clearRect.r0 = (u_char)depthQBackColor;
                    /* WARNING: Read-only address (ram,0x800d20ad) is written */
  clearRect.g0 = depthQBackColor._1_1_;
                    /* WARNING: Read-only address (ram,0x800d20ae) is written */
  clearRect.b0 = depthQBackColor._2_1_;
                    /* WARNING: Read-only address (ram,0x800d20bc) is written */
  BLK_FILL_800d20b8.r0 = (u_char)depthQBackColor;
                    /* WARNING: Read-only address (ram,0x800d20bd) is written */
  BLK_FILL_800d20b8.g0 = depthQBackColor._1_1_;
                    /* WARNING: Read-only address (ram,0x800d20be) is written */
  BLK_FILL_800d20b8.b0 = depthQBackColor._2_1_;
  PIPE3D_AnimateTerrainTextures
            (terrain->aniList,gameTrackerX.frameCount,gameTrackerX.primPool,drawot);
  PIPE3D_AnimateTerrainTextures
            (level->bgAniList,gameTrackerX.frameCount,gameTrackerX.primPool,drawot);
  unitID = 0;
  LIGHT_Restore(gLightInfo);
  lightInfo = gLightInfo;
  gLightInfo->numSavedColors = 0;
  LIGHT_InitSources((_CameraCore_Type *)&theCamera,level,lightInfo);
  LIGHT_SourcesAndInstances(gLightInfo,gameTrackerX.instanceList);
  LIGHT_SourcesAndTerrain(gLightInfo,terrain);
  PIPE3D_InstanceTransformAndDraw(currentUnit,&gameTrackerX,drawot,(_CameraCore_Type *)&theCamera);
  local_60 = theCamera.core.position._0_4_;
  local_5c = theCamera.core.position.z;
  local_58 = *(u_char *)(theCamera.core.wcTransform)->m;
  local_54 = *(u_char *)((theCamera.core.wcTransform)->m + 2);
  local_50 = *(u_char *)((theCamera.core.wcTransform)->m + 4);
  local_4c = *(u_char *)((theCamera.core.wcTransform)->m + 6);
  local_48 = *(u_char *)((theCamera.core.wcTransform)->m + 8);
  local_44 = (theCamera.core.wcTransform)->t[0];
  local_40 = (theCamera.core.wcTransform)->t[1];
  local_3c = (theCamera.core.wcTransform)->t[2];
  iVar8 = 0;
  if (0 < terrain->numBSPTrees) {
    do {
      p_Var2 = gameTrackerX.gameData.asmData.lightInstances[0].lightInstance;
      ppiVar6 = (int **)((int)&terrain->BSPTreeArray->bspRoot + iVar8);
      if ((-1 < *(short *)((int)ppiVar6 + 0x1a)) && ((*(ushort *)((int)ppiVar6 + 0x12) & 1) == 0)) {
        p_Var7 = (_Instance *)0x0;
        if ((*(ushort *)((int)ppiVar6 + 0x12) & 0x40) != 0) {
          gameTrackerX.gameData.asmData.lightInstances[0].lightInstance = (_Instance *)0x0;
          p_Var7 = p_Var2;
        }
        uVar5 = (local_60 & 0xffff) - (u_int)*(ushort *)(ppiVar6 + 3);
        local_38 = -(short)uVar5;
        uVar4 = local_60._2_2_ - *(short *)((int)ppiVar6 + 0xe);
        theCamera.core.position._0_4_ = uVar5 & 0xffff | (u_int)uVar4 << 0x10;
        local_36 = -uVar4;
        theCamera.core.position.z = local_5c - *(short *)(ppiVar6 + 4);
        local_34 = -theCamera.core.position.z;
        ApplyMatrixSV(&local_58,&local_38,(theCamera.core.wcTransform)->t);
        BSP_MarkVisibleLeaves_S(ppiVar6,(u_char *)&theCamera,(int *)gPolytopeList);
        local_64 = ppiVar6 + 3;
        puVar3 = (u_long *)(*(code *)gameTrackerX.drawDisplayPolytopeListFunc)
                                    (gPolytopeList,terrain,&theCamera,gameTrackerX.primPool);
        (gameTrackerX.primPool)->nextPrim = puVar3;
        if ((*(ushort *)((int)ppiVar6 + 0x12) & 0x40) != 0) {
          gameTrackerX.gameData.asmData.lightInstances[0].lightInstance = p_Var7;
        }
      }
      unitID = unitID + 1;
      iVar8 = iVar8 + 0x24;
    } while (unitID < terrain->numBSPTrees);
  }
  lightInfo = gLightInfo;
  pMVar1 = theCamera.core.wcTransform;
  unitID = (int)RENDER_currentStreamUnitID;
  theCamera.core.position._0_4_ = local_60;
  theCamera.core.position.z = local_5c;
  *(u_char *)(theCamera.core.wcTransform)->m = local_58;
  *(u_char *)(pMVar1->m + 2) = local_54;
  *(u_char *)(pMVar1->m + 4) = local_50;
  *(u_char *)(pMVar1->m + 6) = local_4c;
  *(u_char *)(pMVar1->m + 8) = local_48;
  pMVar1->t[0] = local_44;
  pMVar1->t[1] = local_40;
  pMVar1->t[2] = local_3c;
  INSTANCE_IntroduceSavedInstance(terrain,(_CameraCore_Type *)&theCamera,lightInfo,unitID);
  StackSave = (u_long)&stack0xffffff88;
  FX_DrawLightning(fxTracker,&gameTrackerX,gameTrackerX.drawOT,theCamera.core.wcTransform);
  if ((gameTrackerX.playerInstance)->currentStreamUnitID == currentUnit->StreamUnitID) {
    FX_DrawReaver(gameTrackerX.primPool,gameTrackerX.drawOT,theCamera.core.wcTransform);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StreamIntroInstancesForUnit(struct _StreamUnit *currentUnit /*$a1*/)
 // line 1937, offset 0x8002ed64
	/* begin block 1 */
		// Start line: 1938
		// Start offset: 0x8002ED64
	/* end block 1 */
	// End offset: 0x8002ED94
	// End Line: 1950

	/* begin block 2 */
		// Start line: 4417
	/* end block 2 */
	// End Line: 4418

void StreamIntroInstancesForUnit(_StreamUnit *currentUnit)

{
  if (currentUnit->used == 2) {
    SBSP_IntroduceInstances(currentUnit->level->terrain,currentUnit->StreamUnitID);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ StreamRenderLevel(struct _StreamUnit *currentUnit /*$s7*/, struct Level *mainLevel /*$a1*/, unsigned long **drawot /*$s6*/, long portalFogColor /*$s0*/)
 // line 1954, offset 0x8002eda4
	/* begin block 1 */
		// Start line: 1955
		// Start offset: 0x8002EDA4
		// Variables:
	// 		struct GameTracker *gameTracker; // $s4
	// 		struct Level *level; // $s1
	// 		struct _Terrain *terrain; // $s2
	// 		int curTree; // $s1
	// 		int farplanesave; // $fp
	// 		struct _Position cam_pos_save; // stack offset -88
	// 		struct MATRIX cam_mat_save; // stack offset -80

		/* begin block 1.1 */
			// Start line: 2037
			// Start offset: 0x8002EF3C
			// Variables:
		// 		struct _SVector tmp; // stack offset -48
		// 		struct BSPTree *bsp; // $s0
		/* end block 1.1 */
		// End offset: 0x8002F008
		// End Line: 2085

		/* begin block 1.2 */
			// Start line: 2103
			// Start offset: 0x8002F0BC
		/* end block 1.2 */
		// End offset: 0x8002F0F8
		// End Line: 2113
	/* end block 1 */
	// End offset: 0x8002F0F8
	// End Line: 2115

	/* begin block 2 */
		// Start line: 4451
	/* end block 2 */
	// End Line: 4452

/* WARNING: This function may have set the stack pointer */
/* WARNING: Could not reconcile some variable overlaps */

long StreamRenderLevel(_StreamUnit *currentUnit,Level *mainLevel,u_long **drawot,long portalFogColor)

{
  MATRIX *pMVar1;
  long lVar2;
  LightInfo *lightInfo;
  int unitID;
  u_long *puVar3;
  ushort uVar4;
  u_int uVar5;
  int **ppiVar6;
  Level *level;
  _Terrain *terrain;
  int iVar7;
  undefined auStack112 [16];
  u_long **local_60;
  int **local_5c;
  u_char local_58;
  short local_54;
  u_char local_50;
  u_char local_4c;
  u_char local_48;
  u_char local_44;
  u_char local_40;
  long local_3c;
  long local_38;
  long local_34;
  short local_30;
  short local_2e;
  short local_2c;
  
  lVar2 = theCamera.core.farPlane;
  level = currentUnit->level;
  terrain = level->terrain;
  SetFarColor(0,0,0);
  UpdateFogSettings(currentUnit,level);
  depthQFogFar = (u_int)level->fogFar;
  depthQFogStart = (u_int)level->fogNear;
  depthQBackColor = portalFogColor;
  currentUnit->FogColor = portalFogColor;
  theCamera.core.farPlane = depthQFogFar;
  unitID = CheckForNoBlend((_ColorType *)&depthQBackColor);
  depthQBlendStart = 0xffff;
  if (unitID == 0) {
    depthQBlendStart = depthQFogStart;
  }
  SetFogNearFar(depthQFogStart,depthQFogFar,0x140);
  PIPE3D_AnimateTerrainTextures
            (terrain->aniList,gameTrackerX.frameCount,gameTrackerX.primPool,drawot);
  PIPE3D_AnimateTerrainTextures
            (level->bgAniList,gameTrackerX.frameCount,gameTrackerX.primPool,drawot);
  LIGHT_InitSources((_CameraCore_Type *)&theCamera,level,gLightInfo);
  LIGHT_SourcesAndTerrain(gLightInfo,terrain);
  PIPE3D_InstanceTransformAndDraw(currentUnit,&gameTrackerX,drawot,(_CameraCore_Type *)&theCamera);
  local_58 = theCamera.core.position._0_4_;
  local_54 = theCamera.core.position.z;
  local_50 = *(u_char *)(theCamera.core.wcTransform)->m;
  local_4c = *(u_char *)((theCamera.core.wcTransform)->m + 2);
  local_48 = *(u_char *)((theCamera.core.wcTransform)->m + 4);
  local_44 = *(u_char *)((theCamera.core.wcTransform)->m + 6);
  local_40 = *(u_char *)((theCamera.core.wcTransform)->m + 8);
  local_3c = (theCamera.core.wcTransform)->t[0];
  local_38 = (theCamera.core.wcTransform)->t[1];
  local_34 = (theCamera.core.wcTransform)->t[2];
  unitID = 0;
  if (0 < terrain->numBSPTrees) {
    iVar7 = 0;
    do {
      ppiVar6 = (int **)((int)&terrain->BSPTreeArray->bspRoot + iVar7);
      if ((-1 < *(short *)((int)ppiVar6 + 0x1a)) && ((*(ushort *)((int)ppiVar6 + 0x12) & 1) == 0)) {
        uVar5 = (local_58 & 0xffff) - (u_int)*(ushort *)(ppiVar6 + 3);
        local_30 = -(short)uVar5;
        uVar4 = local_58._2_2_ - *(short *)((int)ppiVar6 + 0xe);
        theCamera.core.position._0_4_ = uVar5 & 0xffff | (u_int)uVar4 << 0x10;
        local_2e = -uVar4;
        theCamera.core.position.z = local_54 - *(short *)(ppiVar6 + 4);
        local_2c = -theCamera.core.position.z;
        ApplyMatrixSV(&local_50,&local_30,(theCamera.core.wcTransform)->t);
        BSP_MarkVisibleLeaves_S(ppiVar6,(u_char *)&theCamera,(int *)gPolytopeList);
        local_5c = ppiVar6 + 3;
        local_60 = drawot;
        puVar3 = (u_long *)(*(code *)gameTrackerX.drawDisplayPolytopeListFunc)
                                    (gPolytopeList,terrain,&theCamera,gameTrackerX.primPool);
        (gameTrackerX.primPool)->nextPrim = puVar3;
      }
      unitID = unitID + 1;
      iVar7 = iVar7 + 0x24;
    } while (unitID < terrain->numBSPTrees);
  }
  lightInfo = gLightInfo;
  pMVar1 = theCamera.core.wcTransform;
  unitID = (int)RENDER_currentStreamUnitID;
  theCamera.core.position._0_4_ = local_58;
  theCamera.core.position.z = local_54;
  InStreamUnit = 1;
  *(u_char *)(theCamera.core.wcTransform)->m = local_50;
  *(u_char *)(pMVar1->m + 2) = local_4c;
  *(u_char *)(pMVar1->m + 4) = local_48;
  *(u_char *)(pMVar1->m + 6) = local_44;
  *(u_char *)(pMVar1->m + 8) = local_40;
  pMVar1->t[0] = local_3c;
  pMVar1->t[1] = local_38;
  pMVar1->t[2] = local_34;
  INSTANCE_IntroduceSavedInstance(terrain,(_CameraCore_Type *)&theCamera,lightInfo,unitID);
  InStreamUnit = 0;
  theCamera.core.farPlane = lVar2;
  if ((gameTrackerX.playerInstance)->currentStreamUnitID == currentUnit->StreamUnitID) {
    hackOT = drawot;
    StackSave = (u_long)auStack112;
    FX_DrawReaver(gameTrackerX.primPool,drawot,theCamera.core.wcTransform);
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_FlipScreenAndDraw(struct GameTracker *gameTracker /*$s0*/, unsigned long **drawot /*$a1*/)
 // line 2139, offset 0x8002f130
	/* begin block 1 */
		// Start line: 4978
	/* end block 1 */
	// End Line: 4979

void GAMELOOP_FlipScreenAndDraw(GameTracker *gameTracker,u_long **drawot)

{
  int iVar1;
  u_int uVar2;
  
  DrawOTag(drawot + 0xbff);
  do {
    iVar1 = CheckVolatile(gameTracker->drawTimerReturn);
  } while (iVar1 != 0);
  ResetPrimPool();
  PutDrawEnv((u_char *)(&draw + gameTracker->drawPage));
  do {
    iVar1 = CheckVolatile(gameTracker->reqDisp);
  } while (iVar1 != 0);
  uVar2 = GetRCnt(0xf2000000);
  *(u_long **)&gameTracker->drawTimerReturn = &gameTracker->drawTime;
  iVar1 = (gameTracker->gameData).asmData.dispPage;
  gameTracker->usecsStartDraw = uVar2 & 0xffff | gameTimer << 0x10;
  (gameTracker->gameData).asmData.dispPage = 1 - iVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_AddClearPrim(unsigned long **drawot /*$a3*/)
 // line 2171, offset 0x8002f1e8
	/* begin block 1 */
		// Start line: 2172
		// Start offset: 0x8002F1E8

		/* begin block 1.1 */
			// Start line: 2176
			// Start offset: 0x8002F1FC
			// Variables:
		// 		struct BLK_FILL *blkfill; // $a0
		/* end block 1.1 */
		// End offset: 0x8002F1FC
		// End Line: 2176

		/* begin block 1.2 */
			// Start line: 2192
			// Start offset: 0x8002F26C
			// Variables:
		// 		struct BLK_FILL *blkfill; // $v1
		/* end block 1.2 */
		// End offset: 0x8002F288
		// End Line: 2194
	/* end block 1 */
	// End offset: 0x8002F288
	// End Line: 2195

	/* begin block 2 */
		// Start line: 5049
	/* end block 2 */
	// End Line: 5050

	/* begin block 3 */
		// Start line: 5051
	/* end block 3 */
	// End Line: 5052

void GAMELOOP_AddClearPrim(u_long **drawot)

{
  u_long *puVar1;
  u_long uVar2;
  u_long uVar3;
  u_long uVar4;
  
  if ((gameTrackerX.gameFlags & 0x8000000U) == 0) {
    puVar1 = (gameTrackerX.primPool)->nextPrim;
    uVar2 = *(u_long *)&(&clearRect)[gameTrackerX.drawPage].r0;
    uVar3 = *(u_long *)&(&clearRect)[gameTrackerX.drawPage].x0;
    uVar4 = *(u_long *)&(&clearRect)[gameTrackerX.drawPage].w;
    *puVar1 = (&clearRect)[gameTrackerX.drawPage].tag;
    puVar1[1] = uVar2;
    puVar1[2] = uVar3;
    puVar1[3] = uVar4;
    (gameTrackerX.primPool)->nextPrim = puVar1 + 4;
    *puVar1 = (u_int)drawot[0xbff] & 0xffffff | 0x3000000;
    drawot[0xbff] = (u_long *)((u_int)puVar1 & 0xffffff);
    return;
  }
  *(ushort *)&(gameTrackerX.savedOTStart)->b0 = (&clearRect)[gameTrackerX.drawPage].y0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SwitchTheDrawBuffer(unsigned long **drawot /*$a0*/)
 // line 2197, offset 0x8002f290
	/* begin block 1 */
		// Start line: 5120
	/* end block 1 */
	// End Line: 5121

void GAMELOOP_SwitchTheDrawBuffer(u_long **drawot)

{
  GAMELOOP_AddClearPrim(drawot);
  DrawSync(0);
  if (gameTrackerX.drawTimerReturn != (long *)0x0) {
    gameTrackerX.drawTimerReturn = (long *)0x0;
    gameTrackerX.reqDisp =
         (void *)((int)gameTrackerX.disp + gameTrackerX.gameData.asmData.dispPage * 0x14);
  }
  PutDrawEnv((u_char *)(&draw + gameTrackerX.drawPage));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SetupRenderFunction(struct GameTracker *gameTracker /*$a0*/)
 // line 2229, offset 0x8002f314
	/* begin block 1 */
		// Start line: 5185
	/* end block 1 */
	// End Line: 5186

	/* begin block 2 */
		// Start line: 5200
	/* end block 2 */
	// End Line: 5201

void GAMELOOP_SetupRenderFunction(GameTracker *gameTracker)

{
  *(undefined **)&gameTracker->drawAnimatedModelFunc = &DRAW_AnimatedModel_S;
  *(undefined **)&gameTracker->drawDisplayPolytopeListFunc = &DRAW_DisplayPolytopeList_S;
  return;
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ GAMELOOP_GetMainRenderUnit()
 // line 2255, offset 0x8002f330
	/* begin block 1 */
		// Start line: 2256
		// Start offset: 0x8002F330
		// Variables:
	// 		struct _StreamUnit *streamUnit; // $s0

		/* begin block 1.1 */
			// Start line: 2267
			// Start offset: 0x8002F360
			// Variables:
		// 		struct _Instance *focusInstance; // $s1

			/* begin block 1.1.1 */
				// Start line: 2288
				// Start offset: 0x8002F3C0
				// Variables:
			// 		struct _StreamUnit *cameraUnit; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8002F3DC
			// End Line: 2296
		/* end block 1.1 */
		// End offset: 0x8002F3DC
		// End Line: 2297
	/* end block 1 */
	// End offset: 0x8002F3E0
	// End Line: 2301

	/* begin block 2 */
		// Start line: 5237
	/* end block 2 */
	// End Line: 5238

/* WARNING: Unknown calling convention yet parameter storage is locked */

_StreamUnit * GAMELOOP_GetMainRenderUnit(void)

{
  _Instance *p_Var1;
  _StreamUnit *p_Var2;
  _StreamUnit *p_Var3;
  
  p_Var1 = theCamera.focusInstance;
  if (theCamera.mode == 5) {
    p_Var2 = STREAM_WhichUnitPointerIsIn(theCamera.data.Cinematic.posSpline);
  }
  else {
    if ((theCamera.focusInstance == gameTrackerX.playerInstance) &&
       (gameTrackerX.SwitchToNewStreamUnit != 0)) {
      p_Var2 = STREAM_GetStreamUnitWithID(gameTrackerX.moveRazielToStreamID);
      if (p_Var2 == (_StreamUnit *)0x0) {
        p_Var2 = STREAM_GetStreamUnitWithID(p_Var1->currentStreamUnitID);
        return p_Var2;
      }
    }
    else {
      p_Var2 = STREAM_GetStreamUnitWithID((theCamera.focusInstance)->currentStreamUnitID);
    }
    p_Var3 = COLLIDE_CameraWithStreamSignals(&theCamera);
    if (p_Var3 != (_StreamUnit *)0x0) {
      p_Var2 = p_Var3;
    }
  }
  return p_Var2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_DisplayFrame(struct GameTracker *gameTracker /*stack 0*/)
 // line 2306, offset 0x8002f3f4
	/* begin block 1 */
		// Start line: 2307
		// Start offset: 0x8002F3F4
		// Variables:
	// 		unsigned long **drawot; // stack offset -56
	// 		struct Level *mainLevel; // stack offset -52
	// 		struct StreamUnitPortal *streamPortal; // $fp
	// 		int numportals; // stack offset -48
	// 		int d; // $s4
	// 		struct _StreamUnit *mainStreamUnit; // $s7

		/* begin block 1.1 */
			// Start line: 2403
			// Start offset: 0x8002F5B8
			// Variables:
		// 		struct _StreamUnit *toStreamUnit; // $s3
		// 		long toStreamUnitID; // $s6
		// 		struct StreamUnitPortal *streamPortal2; // $s0
		// 		int i; // $s1
		// 		int draw; // $s2
		// 		struct RECT cliprect; // stack offset -64
		/* end block 1.1 */
		// End offset: 0x8002F7F4
		// End Line: 2508
	/* end block 1 */
	// End offset: 0x8002F9EC
	// End Line: 2613

	/* begin block 2 */
		// Start line: 5342
	/* end block 2 */
	// End Line: 5343

void GAMELOOP_DisplayFrame(GameTracker *gameTracker)

{
  bool bVar1;
  _StreamUnit *currentUnit;
  long lVar2;
  int *piVar3;
  int iVar4;
  u_int uVar5;
  u_long uVar6;
  StreamUnitPortal *portal;
  STracker *currentUnit_00;
  u_long **polyAddr;
  int iVar7;
  _StreamUnit *currentUnit_01;
  int iVar8;
  ushort *puVar9;
  int iVar10;
  StreamUnitPortal *curStreamPortal;
  RECT local_40;
  u_long **local_38;
  Level *local_34;
  int local_30;
  
  local_38 = gameTracker->drawOT;
  if ((gameTrackerX.gameFlags & 0x8000000U) == 0) {
    gameTrackerX.visibleInstances = 0;
    gameTrackerX.displayFrameCount = gameTrackerX.displayFrameCount + 1;
    GAMELOOP_SetupRenderFunction(&gameTrackerX);
    if (((GlobalSave->flags & 1U) == 0) &&
       (((gameTracker->wipeType != 0xb || (gameTracker->wipeTime == 0)) &&
        ((gameTracker->debugFlags2 & 0x800U) != 0)))) {
      FX_Spiral(gameTrackerX.primPool,local_38);
    }
    HUD_Draw();
    currentUnit = GAMELOOP_GetMainRenderUnit();
    local_34 = currentUnit->level;
    if ((gameTracker->debugFlags & 4U) != 0) {
      FONT_Print("Cameraunit: %s\n");
    }
    RENDER_currentStreamUnitID = *(short *)&currentUnit->StreamUnitID;
    theCamera.core.rightX = 0x140;
    theCamera.core.leftX = 0;
    theCamera.core.topY = 0;
    theCamera.core.bottomY = 0xf0;
    CAMERA_SetViewVolume(&theCamera);
    lVar2 = MEMPACK_ReportMemory((char *)local_34);
    if (lVar2 != 0) {
      if ((u_int)local_34->fogFar != theCamera.core.farPlane) {
        theCamera.core.farPlane = (u_int)local_34->fogFar;
      }
      if ((gameTracker->debugFlags & 0x8000U) == 0) {
        MainRenderLevel(currentUnit,local_38);
      }
    }
    piVar3 = (int *)local_34->terrain->StreamUnits;
    iVar8 = 0;
    local_30 = *piVar3;
    curStreamPortal = (StreamUnitPortal *)(piVar3 + 1);
    if (0 < local_30) {
      puVar9 = (ushort *)((int)piVar3 + 0x22);
      do {
        currentUnit_01 = *(_StreamUnit **)(puVar9 + 5);
        iVar10 = *(int *)(puVar9 + -5);
        if ((currentUnit_01 == (_StreamUnit *)0x0) ||
           (currentUnit_01->FrameCount != gameTrackerX.displayFrameCount)) {
          local_40.x = 0x200;
          local_40.y = 0xf0;
          local_40.w = -0x200;
          local_40.h = -0xf0;
          theCamera.core.rightX = 0x140;
          theCamera.core.leftX = 0;
          theCamera.core.topY = 0;
          theCamera.core.bottomY = 0xf0;
          CAMERA_SetViewVolume(&theCamera);
          iVar7 = 0;
          bVar1 = false;
          portal = (StreamUnitPortal *)((int)local_34->terrain->StreamUnits + 4);
          if (0 < local_30) {
            do {
              if ((portal->streamID == iVar10) &&
                 (iVar4 = STREAM_GetClipRect(portal,&local_40), iVar4 != 0)) {
                bVar1 = true;
              }
              iVar7 = iVar7 + 1;
              portal = portal + 1;
            } while (iVar7 < local_30);
          }
          if (bVar1) {
            theCamera.core.leftX = (int)local_40.x * 0x140;
            if (theCamera.core.leftX < 0) {
              theCamera.core.leftX = theCamera.core.leftX + 0x1ff;
            }
            theCamera.core.topY = (int)local_40.y;
            theCamera.core.leftX = theCamera.core.leftX >> 9;
            theCamera.core.rightX = ((int)local_40.x + (int)local_40.w) * 0x140;
            if (theCamera.core.rightX < 0) {
              theCamera.core.rightX = theCamera.core.rightX + 0x1ff;
            }
            theCamera.core.rightX = theCamera.core.rightX >> 9;
            theCamera.core.bottomY = theCamera.core.topY + local_40.h;
            CAMERA_SetViewVolume(&theCamera);
            SetRotMatrix((u_char *)theCamera.core.wcTransform);
            TransMatrix((int)theCamera.core.wcTransform);
            if ((*puVar9 & 1) == 0) {
              if ((currentUnit_01 != (_StreamUnit *)0x0) &&
                 (currentUnit_01->FrameCount != gameTrackerX.displayFrameCount)) {
                currentUnit_01->FrameCount = gameTrackerX.displayFrameCount;
                STREAM_RenderWarpGate(local_38,curStreamPortal,currentUnit_01,currentUnit,&local_40)
                ;
              }
            }
            else {
              if ((currentUnit->flags & 8U) == 0) {
                WARPGATE_Init(currentUnit);
              }
              else {
                if (currentUnit_01 != (_StreamUnit *)0x0) {
                  if (currentUnit_01->FrameCount == gameTrackerX.displayFrameCount)
                  goto LAB_8002f7f8;
                  currentUnit_01->FrameCount = gameTrackerX.displayFrameCount;
                }
                STREAM_RenderAdjacantUnit(local_38,curStreamPortal,currentUnit,&local_40);
              }
            }
          }
          else {
            if ((currentUnit_01 != (_StreamUnit *)0x0) &&
               (currentUnit_01->FrameCount != gameTrackerX.displayFrameCount)) {
              currentUnit_01->FrameCount = gameTrackerX.displayFrameCount;
              StreamIntroInstancesForUnit(currentUnit_01);
            }
          }
        }
LAB_8002f7f8:
        iVar8 = iVar8 + 1;
        puVar9 = puVar9 + 0x2e;
        curStreamPortal = curStreamPortal + 1;
      } while (iVar8 < local_30);
    }
    iVar8 = 0;
    currentUnit_00 = &StreamTracker;
    do {
      if ((*(short *)currentUnit_00->StreamList == 2) &&
         (*(u_long *)currentUnit_00->StreamList != gameTrackerX.displayFrameCount)) {
        *(u_long *)currentUnit_00->StreamList = gameTrackerX.displayFrameCount;
        StreamIntroInstancesForUnit((_StreamUnit *)currentUnit_00);
      }
      iVar8 = iVar8 + 1;
      currentUnit_00 = (STracker *)(currentUnit_00->StreamList + 1);
    } while (iVar8 < 0x10);
    theCamera.core.rightX = 0x140;
    theCamera.core.leftX = 0;
    theCamera.core.topY = 0;
    theCamera.core.bottomY = 0xf0;
    CAMERA_SetViewVolume(&theCamera);
  }
  else {
    HUD_Draw();
  }
  DEBUG_Draw(gameTracker,local_38);
  FONT_Flush();
  GAMELOOP_SwitchTheDrawBuffer(local_38);
  uVar5 = GetRCnt(0xf2000000);
  gameTracker->idleTime = uVar5 & 0xffff | gameTimer << 0x10;
  if ((u_int)gameTracker->frameRateLock < gameTracker->vblFrames) {
    if ((ushort *)gameTracker->reqDisp != (ushort *)0x0) {
      PutDispEnv((ushort *)gameTracker->reqDisp);
      gameTracker->reqDisp = (void *)0x0;
      gameTracker->vblFrames = 0;
    }
  }
  else {
    do {
      iVar8 = CheckVolatile(gameTracker->reqDisp);
    } while (iVar8 != 0);
  }
  uVar6 = TIMER_TimeDiff(gameTracker->idleTime);
  polyAddr = local_38 + 0xbff;
  iVar8 = (gameTracker->gameData).asmData.dispPage;
  gameTracker->idleTime = uVar6;
  (gameTracker->gameData).asmData.dispPage = 1 - iVar8;
  DEBUG_DrawShrinkCels(polyAddr);
  SIGNAL_HandleScreenWipe(local_38);
  uVar5 = GetRCnt(0xf2000000);
  *(u_long **)&gameTracker->drawTimerReturn = &gameTracker->drawTime;
  gameTracker->usecsStartDraw = uVar5 & 0xffff | gameTimer << 0x10;
  if ((gameTrackerX.gameFlags & 0x8000000U) == 0) {
    DrawOTag(polyAddr);
  }
  else {
    GAMELOOP_DrawSavedOT(local_38);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_DrawSavedOT(unsigned long **newOT /*$t3*/)
 // line 2619, offset 0x8002fa1c
	/* begin block 1 */
		// Start line: 2620
		// Start offset: 0x8002FA1C
		// Variables:
	// 		struct P_TAG *tag; // $a1
	// 		int y; // $a2

		/* begin block 1.1 */
			// Start line: 2628
			// Start offset: 0x8002FA84
			// Variables:
		// 		int tpage; // $v1
		/* end block 1.1 */
		// End offset: 0x8002FAAC
		// End Line: 2636

		/* begin block 1.2 */
			// Start line: 2641
			// Start offset: 0x8002FAC0
			// Variables:
		// 		int tpage; // $v1
		/* end block 1.2 */
		// End offset: 0x8002FAE8
		// End Line: 2649

		/* begin block 1.3 */
			// Start line: 2654
			// Start offset: 0x8002FAFC
		/* end block 1.3 */
		// End offset: 0x8002FB30
		// End Line: 2665
	/* end block 1 */
	// End offset: 0x8002FB54
	// End Line: 2668

	/* begin block 2 */
		// Start line: 6186
	/* end block 2 */
	// End Line: 6187

void GAMELOOP_DrawSavedOT(u_long **newOT)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  u_int uVar4;
  byte bVar5;
  u_int uVar6;
  P_TAG *pPVar7;
  
  sVar2 = (&draw)[gameTrackerX.drawPage].ofs[1];
  pPVar7 = gameTrackerX.savedOTStart;
  if (gameTrackerX.savedOTStart != gameTrackerX.savedOTEnd) {
    do {
      bVar1 = *(byte *)((int)&pPVar7->len + 3);
      bVar5 = bVar1 & 0xfc;
      if (bVar5 == 0x34) {
        uVar3 = *(ushort *)((int)&pPVar7[2].addr + 2);
        if ((uVar3 & 0xf) < 8) {
          if (sVar2 == 0) {
            *(ushort *)((int)&pPVar7[2].addr + 2) = uVar3 & 0xffef;
          }
          else {
            *(ushort *)((int)&pPVar7[2].addr + 2) = uVar3 | 0x10;
          }
        }
      }
      else {
        if (bVar5 == 0x24) {
          uVar3 = *(ushort *)&pPVar7[1].b0;
          if ((uVar3 & 0xf) < 8) {
            if (sVar2 == 0) {
              *(ushort *)&pPVar7[1].b0 = uVar3 & 0xffef;
            }
            else {
              *(ushort *)&pPVar7[1].b0 = uVar3 | 0x10;
            }
          }
        }
        else {
          if (bVar1 == 0xe3) {
            if (sVar2 == 0) {
              uVar4 = pPVar7->len & 0xfffbffff;
              uVar6 = *(u_int *)&pPVar7->r0 & 0xfffbffff;
            }
            else {
              uVar4 = pPVar7->len | 0x40000;
              uVar6 = *(u_int *)&pPVar7->r0 | 0x40000;
            }
            pPVar7->len = uVar4;
            *(u_int *)&pPVar7->r0 = uVar6;
          }
        }
      }
      pPVar7 = (P_TAG *)(pPVar7->addr & 0xffffff | 0x80000000);
    } while (pPVar7 != gameTrackerX.savedOTEnd);
  }
  (gameTrackerX.savedOTEnd)->addr =
       (gameTrackerX.savedOTEnd)->addr & 0xff000000 | (u_int)(newOT + 0xbff) & 0xffffff;
  DrawOTag((u_char *)gameTrackerX.savedOTStart);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ResetPrimPool()
 // line 2673, offset 0x8002fb98
	/* begin block 1 */
		// Start line: 6344
	/* end block 1 */
	// End Line: 6345

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ResetPrimPool(void)

{
  undefined **ppuVar1;
  
  ResetDrawPage();
  if ((gameTrackerX.gameFlags & 0x8000000U) == 0) {
    if (gameTrackerX.primPool == primPool2) {
      gameTrackerX.primPool = PTR_800d1d24;
    }
    else {
      gameTrackerX.primPool = primPool2;
    }
    (gameTrackerX.primPool)->nextPrim = (gameTrackerX.primPool)->prim;
  }
  else {
    if (gameTrackerX.drawPage == 0) {
      ppuVar1 = (undefined **)&DAT_00008cac;
    }
    else {
      ppuVar1 = &PTR_000101dc;
    }
    (gameTrackerX.primPool)->nextPrim =
         (u_long *)((int)&(gameTrackerX.primPool)->numPrims + (int)ppuVar1);
  }
  (gameTrackerX.primPool)->numPrims = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SaveOT()
 // line 2702, offset 0x8002fc44
	/* begin block 1 */
		// Start line: 2703
		// Start offset: 0x8002FC44
		// Variables:
	// 		struct P_TAG *tag; // $a0
	// 		struct P_TAG *last; // $s0
	// 		struct P_TAG *lastlast; // $s1
	/* end block 1 */
	// End offset: 0x8002FDD0
	// End Line: 2752

	/* begin block 2 */
		// Start line: 6402
	/* end block 2 */
	// End Line: 6403

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SaveOT(void)

{
  char cVar1;
  P_TAG *pPVar2;
  P_TAG *pPVar3;
  u_int uVar4;
  P_TAG *pPVar5;
  P_TAG *pPVar6;
  P_TAG *pPVar7;
  
  DrawSync(0);
  pPVar5 = (P_TAG *)(gameTrackerX.drawOT + 0xbff);
  cVar1 = *(char *)((int)gameTrackerX.drawOT + 0x2fff);
  pPVar7 = (P_TAG *)0x0;
  while (cVar1 == '\0') {
    uVar4 = pPVar5->addr & 0xffffff;
    pPVar5 = (P_TAG *)(uVar4 | 0x80000000);
    if (uVar4 == 0xffffff) goto LAB_8002fcc0;
    cVar1 = *(char *)((int)&pPVar5->addr + 3);
  }
  if ((pPVar5->addr & 0xffffff) == 0xffffff) {
LAB_8002fcc0:
    gameTrackerX.savedOTStart = (P_TAG *)0x0;
  }
  else {
    pPVar2 = pPVar5;
    pPVar3 = (P_TAG *)0x0;
    gameTrackerX.savedOTStart = pPVar5;
    if ((pPVar5->addr & 0xffffff) != 0xffffff) {
      do {
        while (pPVar6 = pPVar3, pPVar5 = pPVar2, *(char *)((int)&pPVar5->addr + 3) != '\0') {
          uVar4 = pPVar5->addr & 0xffffff;
          if (uVar4 == 0xffffff) goto LAB_8002fdac;
          pPVar2 = (P_TAG *)(uVar4 | 0x80000000);
          pPVar3 = pPVar5;
          pPVar7 = pPVar6;
        }
        if ((pPVar5->addr & 0xffffff) == 0xffffff) goto LAB_8002fdac;
        cVar1 = *(char *)((int)&pPVar5->addr + 3);
        while ((cVar1 == '\0' && (uVar4 = pPVar5->addr & 0xffffff, uVar4 != 0xffffff))) {
          pPVar5 = (P_TAG *)(uVar4 | 0x80000000);
          cVar1 = *(char *)((int)&pPVar5->addr + 3);
        }
        pPVar6->addr = pPVar6->addr & 0xff000000 | (u_int)pPVar5 & 0xffffff;
        pPVar2 = pPVar5;
        pPVar3 = pPVar6;
      } while ((pPVar5->addr & 0xffffff) != 0xffffff);
      if ((pPVar5->addr & 0xffffff) != 0xffffff) {
        gameTrackerX.savedOTEnd = pPVar5;
        return;
      }
    }
LAB_8002fdac:
    gameTrackerX.savedOTEnd = pPVar5;
    if (pPVar7 != (P_TAG *)0x0) {
      gameTrackerX.savedOTEnd = pPVar7;
      pPVar7->addr = pPVar7->addr | 0xffffff;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ResetDrawPage()
 // line 2754, offset 0x8002fde4
	/* begin block 1 */
		// Start line: 2755
		// Start offset: 0x8002FDE4

		/* begin block 1.1 */
			// Start line: 2755
			// Start offset: 0x8002FDE4
			// Variables:
		// 		unsigned long **temp; // $v0
		/* end block 1.1 */
		// End offset: 0x8002FDE4
		// End Line: 2755
	/* end block 1 */
	// End offset: 0x8002FDE4
	// End Line: 2755

	/* begin block 2 */
		// Start line: 6526
	/* end block 2 */
	// End Line: 6527

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ResetDrawPage(void)

{
  u_long **ppuVar1;
  
  ppuVar1 = gameTrackerX.dispOT;
  gameTrackerX.dispOT = gameTrackerX.drawOT;
  gameTrackerX.drawPage = 1 - gameTrackerX.drawPage;
  gameTrackerX.drawOT = ppuVar1;
  ClearOTagR(ppuVar1,0xc00);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_Set24FPS()
 // line 2786, offset 0x8002fe24
	/* begin block 1 */
		// Start line: 6602
	/* end block 1 */
	// End Line: 6603

	/* begin block 2 */
		// Start line: 6603
	/* end block 2 */
	// End Line: 6604

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_SystemInit(void)

{
  gameTrackerX.frameRate24fps = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_Reset24FPS()
 // line 2792, offset 0x8002fe34
	/* begin block 1 */
		// Start line: 6614
	/* end block 1 */
	// End Line: 6615

	/* begin block 2 */
		// Start line: 6615
	/* end block 2 */
	// End Line: 6616

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_Reset24FPS(void)

{
  gameTrackerX.frameRate24fps = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_DoTimeProcess()
 // line 2797, offset 0x8002fe40
	/* begin block 1 */
		// Start line: 2798
		// Start offset: 0x8002FE40
		// Variables:
	// 		int holdTime; // $s1

		/* begin block 1.1 */
			// Start line: 2833
			// Start offset: 0x8002FF24
			// Variables:
		// 		int lockRate; // $a1
		// 		unsigned long last; // $a0
		/* end block 1.1 */
		// End offset: 0x8002FFD4
		// End Line: 2876
	/* end block 1 */
	// End offset: 0x8003002C
	// End Line: 2892

	/* begin block 2 */
		// Start line: 6624
	/* end block 2 */
	// End Line: 6625

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_DoTimeProcess(void)

{
  u_long uVar1;
  u_int uVar2;
  u_int uVar3;
  
  uVar1 = TIMER_GetTimeMS();
  if ((gameTrackerX.gameFlags & 0x10000000U) == 0) {
    gameTrackerX.totalTime = TIMER_TimeDiff(gameTrackerX.currentTicks);
    uVar2 = GetRCnt(0xf2000000);
    gameTrackerX.currentTicks = uVar2 & 0xffff | gameTimer << 0x10;
    if (gameTrackerX.frameRateLock < 1) {
      gameTrackerX.frameRateLock = 1;
    }
    if (2 < gameTrackerX.frameRateLock) {
      gameTrackerX.frameRateLock = 2;
    }
    if ((gameTrackerX.decoupleGame == 0) || ((gameTrackerX.gameFlags & 0x10000000U) != 0)) {
      if (gameTrackerX.frameRateLock == 1) {
        gameTrackerX.lastLoopTime = 0x21;
      }
      else {
        if (gameTrackerX.frameRateLock == 2) {
          gameTrackerX.lastLoopTime = 0x32;
        }
      }
      uVar2 = (u_int)((u_longlong)(gameTrackerX.lastLoopTime << 0xc) * 0x3e0f83e1 >> 0x20);
    }
    else {
      uVar3 = 0x21;
      if ((gameTrackerX.frameRateLock != 1) && (gameTrackerX.frameRateLock == 2)) {
        uVar3 = 0x32;
      }
      uVar2 = uVar3;
      if (gameTrackerX.lastLoopTime != 0xffffffff) {
        uVar2 = uVar1 - gameTrackerX.currentTime;
      }
      if (((gameTrackerX.frameRateLock == 1) && (gameTrackerX.frameRate24fps != 0)) &&
         (uVar2 = uVar2 - 9, gameTrackerX.gameData.asmData.MorphTime != 1000)) {
        uVar2 = 0x21;
      }
      if ((uVar3 <= uVar2) && (uVar3 = uVar2, 0x42 < uVar2)) {
        uVar3 = 0x42;
      }
      uVar2 = (u_int)((u_longlong)(uVar3 << 0xc) * 0x3e0f83e1 >> 0x20);
      gameTrackerX.lastLoopTime = uVar3;
    }
    gameTrackerX.timeMult = uVar2 >> 3;
    gameTrackerX.gameFramePassed = 0;
    gameTrackerX.timeSinceLastGameFrame =
         gameTrackerX.timeSinceLastGameFrame + gameTrackerX.timeMult;
    while (gameTrackerX.globalTimeMult = gameTrackerX.timeMult,
          0x1000 < gameTrackerX.timeSinceLastGameFrame) {
      gameTrackerX.gameFramePassed = 1;
      gameTrackerX.timeSinceLastGameFrame = gameTrackerX.timeSinceLastGameFrame - 0x1000;
      gameTrackerX.fps30Count = gameTrackerX.fps30Count + 1;
    }
  }
  else {
    gameTrackerX.lastLoopTime = 0xffffffff;
  }
  gameTrackerX.currentTime = uVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_Process(struct GameTracker *gameTracker /*$s5*/)
 // line 2899, offset 0x80030044
	/* begin block 1 */
		// Start line: 2900
		// Start offset: 0x80030044
		// Variables:
	// 		int d; // $s2

		/* begin block 1.1 */
			// Start line: 2942
			// Start offset: 0x800300EC
			// Variables:
		// 		int useTime; // $s0

			/* begin block 1.1.1 */
				// Start line: 2945
				// Start offset: 0x800300FC
				// Variables:
			// 		struct Level *level; // $v0
			/* end block 1.1.1 */
			// End offset: 0x80030120
			// End Line: 2950
		/* end block 1.1 */
		// End offset: 0x80030150
		// End Line: 2955

		/* begin block 1.2 */
			// Start line: 3063
			// Start offset: 0x80030318
			// Variables:
		// 		int i; // $s0

			/* begin block 1.2.1 */
				// Start line: 3070
				// Start offset: 0x80030344
				// Variables:
			// 		struct _SFXMkr *sfxMkr; // $a2
			/* end block 1.2.1 */
			// End offset: 0x80030394
			// End Line: 3081
		/* end block 1.2 */
		// End offset: 0x800303C0
		// End Line: 3083
	/* end block 1 */
	// End offset: 0x800306E0
	// End Line: 3277

	/* begin block 2 */
		// Start line: 6845
	/* end block 2 */
	// End Line: 6846

	/* begin block 3 */
		// Start line: 6854
	/* end block 3 */
	// End Line: 6855

/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GAMELOOP_Process(GameTracker *gameTracker)

{
  bool bVar1;
  Level *pLVar2;
  int iVar3;
  u_char **ppuVar4;
  STracker *streamUnit;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  
  if (gEndGameNow == 0) {
    GAMELOOP_DoTimeProcess();
    if ((gameTrackerX.gameMode != 6) && ((gameTrackerX.streamFlags & 0x100000U) == 0)) {
      MORPH_UpdateTimeMult();
      GAMELOOP_CalcGameTime();
      if ((gameTracker->gameData).asmData.MorphType == 0) {
        bVar1 = true;
        if ((gameTrackerX.playerInstance != (_Instance *)0x0) &&
           (pLVar2 = STREAM_GetWaterZLevel((gameTrackerX.playerInstance)->currentStreamUnitID),
           pLVar2 != (Level *)0x0)) {
          bVar1 = (pLVar2->unitFlags & 0x2000U) == 0;
        }
        if (bVar1) {
          gameTracker->currentTimeOfDayTime =
               gameTracker->currentTimeOfDayTime + gameTracker->lastLoopTime;
        }
        gameTracker->currentMaterialTime =
             gameTracker->currentMaterialTime + gameTracker->lastLoopTime;
      }
      else {
        gameTracker->currentSpectralTime =
             gameTracker->currentSpectralTime + gameTracker->lastLoopTime;
      }
    }
    gameTracker->numGSignals = 0;
    GAMELOOP_ChangeMode();
    ResetPrimPool();
    memset(gameTracker->overrideData,0,0x28);
    if (gameTrackerX.gameMode != 6) {
      if ((gameTrackerX.streamFlags & 0x100000U) == 0) {
        if (gameTrackerX.SwitchToNewStreamUnit == 1) {
          INSTANCE_Query(gameTrackerX.playerInstance,0x4000006,0);
          STREAM_MoveIntoNewStreamUnit();
        }
        if ((VRAM_NeedToUpdateMorph != 0) && (iVar3 = STREAM_IsCdBusy((long *)0x0), iVar3 == 0)) {
          VRAM_InitMorphPalettes();
          VRAM_NeedToUpdateMorph = 0;
        }
        if ((gameTracker->gameData).asmData.MorphTime < 1000) {
          MORPH_Continue();
        }
        if ((gameTracker->streamFlags & 0x80000U) != 0) {
          gameTracker->streamFlags = gameTracker->streamFlags & 0xfff7ffff;
          UNDERWORLD_StartProcess();
        }
      }
      if (gameTrackerX.gameMode != 6) {
        if ((gameTrackerX.streamFlags & 0x100000U) == 0) {
          EVENT_ProcessEvents();
          streamUnit = &StreamTracker;
          do {
            if (*(short *)streamUnit->StreamList == 2) {
              if ((*(Level **)streamUnit->StreamList)->PuzzleInstances != (EventPointers *)0x0) {
                if ((gameTrackerX.debugFlags2 & 0x100U) != 0) {
                  FONT_Print("Processing unit %s\n");
                }
                EVENT_ProcessHints((*(Level **)streamUnit->StreamList)->PuzzleInstances,
                                   *(Level **)streamUnit->StreamList);
              }
              EVENT_DoProcess((_StreamUnit *)streamUnit);
            }
            streamUnit = (STracker *)(streamUnit->StreamList + 1);
          } while ((int)streamUnit < -0x7ff2d1f4);
          EVENT_ResetAllOneTimeVariables();
        }
        if (gameTrackerX.gameMode != 6) {
          EVENT_Process();
        }
      }
    }
    iVar7 = 0;
    streamUnit = &StreamTracker;
    iVar3 = iVar7;
    do {
      if ((streamUnit->StreamList[0].used == 2) &&
         (iVar5 = 0, 0 < (streamUnit->StreamList[0].level)->NumberOfSFXMarkers)) {
        iVar6 = 0;
        do {
          ppuVar4 = (u_char **)
                    (*(int *)(*(int *)((int)&StreamTracker.StreamList[0].level + iVar3) + 0xec) +
                    iVar6);
          if ((ppuVar4 != (u_char **)0x0) && (*ppuVar4 != (u_char *)0x0)) {
            SOUND_StartInstanceSound
                      (*ppuVar4,(SoundInstance *)(ppuVar4 + 2),(_Position *)(ppuVar4 + 5),
                       (int)ppuVar4[7],(int)ppuVar4[8],0,(long *)0x0);
          }
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + 0x24;
        } while (iVar5 < (StreamTracker.StreamList[iVar7].level)->NumberOfSFXMarkers);
      }
      iVar3 = iVar3 + 0x40;
      iVar7 = iVar7 + 1;
      streamUnit = (STracker *)(streamUnit->StreamList + 1);
    } while (iVar7 < 0x10);
    if ((gameTrackerX.gameMode != 6) && ((gameTrackerX.streamFlags & 0x100000U) == 0)) {
      INSTANCE_SpatialRelationships(instanceList);
    }
    INSTANCE_ProcessFunctions(gameTracker->instanceList);
    COLLIDE_InstanceListTerrain(gameTracker->instanceList,0);
    INSTANCE_Reactivate(gameTracker);
    MONAPI_ProcessGenerator();
    _DAT_1f800000 = theCamera.core.position._0_4_;
    _DAT_1f800004 = theCamera.core._4_4_;
    StackSave = (u_long)&stack0xffffffc0;
    G2Instance_RebuildTransforms(gameTracker->instanceList->first);
    puVar8 = (undefined *)StackSave;
    if (gameTrackerX.gameMode != 6) {
      if ((gameTrackerX.streamFlags & 0x100000U) == 0) {
        FX_ProcessList(fxTracker);
      }
      puVar8 = (undefined *)StackSave;
      if (gameTrackerX.gameMode != 6) {
        if ((gameTrackerX.streamFlags & 0x100000U) == 0) {
          VM_Tick(0x100,*(undefined *)StackSave);
          if ((gameTracker->debugFlags2 & 0x10000U) != 0) {
            FONT_Print("Military Time %04d\n",*puVar8);
          }
          iVar3 = 0;
          streamUnit = &StreamTracker;
          do {
            if (streamUnit->StreamList[0].used == 2) {
              VM_ProcessVMObjectList_S(streamUnit->StreamList[0].level,*puVar8);
            }
            iVar3 = iVar3 + 1;
            streamUnit = (STracker *)(streamUnit->StreamList + 1);
          } while (iVar3 < 0x10);
        }
        if ((gameTrackerX.gameMode != 6) && ((gameTrackerX.streamFlags & 0x100000U) == 0)) {
          PLANAPI_UpdatePlanningDatabase(gameTracker,gameTrackerX.playerInstance,*puVar8);
        }
      }
    }
    DEBUG_ProcessSecondController(gameTracker,*puVar8);
    if ((gameTrackerX.gameMode != 6) && ((gameTrackerX.streamFlags & 0x100000U) == 0)) {
      COLLIDE_PointAndInstanceTrivialReject(gameTracker->instanceList,*puVar8);
      COLLIDE_Instances(gameTracker->instanceList,*puVar8);
    }
    INSTANCE_AdditionalCollideFunctions(instanceList,*puVar8);
    COLLIDE_InstanceList(instanceList,*puVar8);
    if (gameTrackerX.gameMode != 6) {
      if ((gameTrackerX.streamFlags & 0x100000U) == 0) {
        LIGHT_CalcShadowPositions(gameTracker,*puVar8);
        COLLIDE_InstanceListTerrain(gameTracker->instanceList,0x10,*puVar8);
      }
      if (gameTrackerX.gameMode != 6) {
        CAMERA_Panic(&theCamera,*puVar8);
      }
    }
    PIPE3D_CalculateWCTransform(&theCamera,*puVar8);
    *(undefined2 *)&(theCamera.core.wcTransform2)->field_0x12 = 0;
    PIPE3D_InstanceListTransformAndDraw
              (theCamera.core.cwTransform2,theCamera.core.wcTransform2,*puVar8);
    CAMERA_CalcVVClipInfo(&theCamera,*puVar8);
    if (gameTracker->levelChange != 0) {
      gameTracker->levelChange = 0;
    }
    SAVE_IntroduceBufferIntros(*puVar8);
    if (gameTracker->levelDone == 0) {
      GAMELOOP_DisplayFrame(gameTracker,*puVar8);
    }
    else {
      ResetDrawPage(*puVar8);
    }
    gameTracker->frameCount = gameTracker->frameCount + 1;
    gameTracker->debugFlags = gameTracker->debugFlags & 0xf7ffffff;
  }
  else {
    DEBUG_ExitGame();
    gameTracker->levelDone = 3;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_ModeStartRunning()
 // line 3281, offset 0x80030708
	/* begin block 1 */
		// Start line: 7692
	/* end block 1 */
	// End Line: 7693

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ModeStartPause(void)

{
  if (((gameTrackerX.gameMode == 4) || (gameTrackerX.gameMode == 6)) &&
     (DEBUG_ExitMenus(), gameTrackerX.gameMode == 6)) {
    currentMenu = &standardMenu;
    SOUND_PauseAllSound();
    VOICEXA_Pause();
  }
  if ((gameTrackerX.gameFlags & 0x8000000U) != 0) {
    gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xf7ffffff;
    gameTrackerX.savedOTStart = (P_TAG *)0x0;
    DrawSync(0);
  }
  gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xefffffff;
  (gameTrackerX.playerInstance)->flags = (gameTrackerX.playerInstance)->flags & 0xfffffeff;
  gameTrackerX.gameMode = 0;
  GAMEPAD_DisplayControllerStatus();
  INSTANCE_Query(gameTrackerX.playerInstance,(int)&DAT_0010000a,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_ModeStartPause()
 // line 3311, offset 0x800307e0
	/* begin block 1 */
		// Start line: 7755
	/* end block 1 */
	// End Line: 7756

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ModeStartRunning(void)

{
  gameTrackerX.gameMode = 6;
  INSTANCE_Query(gameTrackerX.playerInstance,(int)&DAT_0010000a,1);
  currentMenu = &pauseMenu;
  menu_sound(gameTrackerX.menu,memcard_pause_menu);
  SOUND_ResetAllSound();
  VOICEXA_Resume();
  SndPlay(5);
  gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x10000000;
  GAMEPAD_RestoreControllers();
  gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x8000000;
  if (gameTrackerX.primPool == primPool2) {
    gameTrackerX.primPool = PTR_800d1d24;
  }
  else {
    gameTrackerX.primPool = primPool2;
  }
  (gameTrackerX.primPool)->nextPrim = (gameTrackerX.primPool)->prim;
  (gameTrackerX.primPool)->numPrims = 0;
  SaveOT();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_DemoSetup()
 // line 3341, offset 0x800308b4
	/* begin block 1 */
		// Start line: 7825
	/* end block 1 */
	// End Line: 7826

	/* begin block 2 */
		// Start line: 7826
	/* end block 2 */
	// End Line: 7827

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_Set24FPS(void)

{
  gameTrackerX.savedPlayerCameraMode = playerCameraMode;
  playerCameraMode = 0xd;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_ChangeMode()
 // line 3361, offset 0x800308cc
	/* begin block 1 */
		// Start line: 3362
		// Start offset: 0x800308CC
		// Variables:
	// 		long *controlCommand; // $s0
	/* end block 1 */
	// End offset: 0x80030C70
	// End Line: 3529

	/* begin block 2 */
		// Start line: 6719
	/* end block 2 */
	// End Line: 6720

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ChangeMode(void)

{
  u_int uVar1;
  
  if ((gameTrackerX.debugFlags & 0x40000U) == 0) {
    if ((gameTrackerX.debugFlags & 0x200000U) == 0) {
      if ((gameTrackerX.controlCommand[0][0] & 0xa01U) == 0xa01) {
        theCamera.forced_movement = 1;
        ((gameTrackerX.playerInstance)->position).z =
             ((gameTrackerX.playerInstance)->position).z + 100;
        (gameTrackerX.playerInstance)->zVel = 0;
        gameTrackerX.cheatMode = '\x01';
        INSTANCE_Query(gameTrackerX.playerInstance,(int)&DAT_00100010,1);
        (gameTrackerX.playerInstance)->flags = (gameTrackerX.playerInstance)->flags & 0xfffff7ff;
      }
      else {
        if ((gameTrackerX.controlCommand[0][0] & 0xa02U) == 0xa02) {
          theCamera.forced_movement = 1;
          ((gameTrackerX.playerInstance)->position).z =
               ((gameTrackerX.playerInstance)->position).z + -100;
          (gameTrackerX.playerInstance)->zVel = 0;
          gameTrackerX.cheatMode = '\0';
          INSTANCE_Query(gameTrackerX.playerInstance,(int)&DAT_00100010,0);
          gameTrackerX.gameMode = 0;
        }
      }
    }
    if ((gameTrackerX.debugFlags & 0x40000U) != 0) goto LAB_800309c0;
  }
  else {
LAB_800309c0:
    if ((gameTrackerX.playerCheatFlags & 2U) == 0) goto LAB_80030ae4;
  }
  if (((gameTrackerX.controlCommand[0][1] & 0x60U) == 0x60) &&
     ((gameTrackerX.controlCommand[0][0] & 0xfU) == 0)) {
    if (gameTrackerX.gameMode == 0) {
      gameTrackerX.gameMode = 4;
      currentMenu = &standardMenu;
      if (gameTrackerX.sound.gVoiceOn == '\0') {
        gameTrackerX.debugFlags = gameTrackerX.debugFlags & 0xfff7ffff;
      }
      else {
        gameTrackerX.debugFlags = gameTrackerX.debugFlags | 0x80000;
      }
      if (gameTrackerX.sound.gMusicOn == '\0') {
        uVar1 = gameTrackerX.debugFlags2 & 0xffffefff;
      }
      else {
        uVar1 = gameTrackerX.debugFlags2 | 0x1000;
      }
      if (gameTrackerX.sound.gSfxOn == '\0') {
        gameTrackerX.debugFlags2 = uVar1 & 0xffffdfff;
      }
      else {
        gameTrackerX.debugFlags2 = uVar1 | 0x2000;
      }
    }
    else {
      if (gameTrackerX.gameMode == 7) {
        DEBUG_ViewVram(&gameTrackerX);
        gameTrackerX.gameMode = 0;
      }
      else {
        GAMELOOP_ModeStartPause();
      }
    }
  }
LAB_80030ae4:
  if ((((((gameTrackerX.controlCommand[0][1] & 0x4000U) == 0) && (gamePadControllerOut < 6)) ||
       (gameTrackerX.gameMode != 0)) || ((gameTrackerX.gameFlags & 0x80U) != 0)) ||
     ((gameTrackerX.wipeTime != 0 &&
      ((gameTrackerX.wipeType == 0xb || (gameTrackerX.wipeTime != -1)))))) {
    if (((((gameTrackerX.controlCommand[0][1] & 0x4000U) != 0) ||
         ((gameTrackerX.gameFlags & 0x40000000U) != 0)) &&
        ((gameTrackerX.gameMode != 0 && ((gameTrackerX.gameFlags & 0x20000000U) == 0)))) &&
       ((gameTrackerX.wipeTime == 0 ||
        ((gameTrackerX.wipeType != 0xb && (gameTrackerX.wipeTime == -1)))))) {
      if (((gameTrackerX.controlCommand[0][1] & 0x4000U) != 0) &&
         ((gameTrackerX.gameFlags & 0x40000000U) == 0)) {
        SndPlay(5);
      }
      gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xbfffffff;
      GAMELOOP_ModeStartPause();
    }
  }
  else {
    GAMELOOP_ModeStartRunning();
  }
  if ((gameTrackerX.controlCommand[0][0] & 0x40000000U) == 0) {
    if ((gameTrackerX.controlCommand[0][2] & 0x40000000U) != 0) {
      (gameTrackerX.playerInstance)->flags = (gameTrackerX.playerInstance)->flags & 0xfffffeff;
    }
  }
  else {
    (gameTrackerX.playerInstance)->flags = (gameTrackerX.playerInstance)->flags | 0x100;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_RequestLevelChange(char *name /*$s2*/, short number /*$a1*/, struct GameTracker *gameTracker /*$s0*/)
 // line 3532, offset 0x80030c80
	/* begin block 1 */
		// Start line: 8268
	/* end block 1 */
	// End Line: 8269

void GAMELOOP_RequestLevelChange(char *name,short number,GameTracker *gameTracker)

{
  if (gameTracker->levelChange == 0) {
    gameTracker->gameFlags = gameTracker->gameFlags | 1;
    SOUND_StopAllSound();
    sprintf(gameTracker->baseAreaName,"%s%d");
    gameTracker->levelChange = 1;
    gameTracker->levelDone = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PSX_GameLoop(struct GameTracker *gameTracker /*$s0*/)
 // line 3554, offset 0x80030d00
	/* begin block 1 */
		// Start line: 8312
	/* end block 1 */
	// End Line: 8313

void PSX_GameLoop(GameTracker *gameTracker)

{
  DEBUG_Process(gameTracker);
  GAMELOOP_Process(gameTracker);
  return;
}



// decompiled code
// original method signature: 
// struct MATRIX * /*$ra*/ GAMELOOP_GetMatrices(int numMatrices /*$a0*/)
 // line 3564, offset 0x80030d2c
	/* begin block 1 */
		// Start line: 3566
		// Start offset: 0x80030D2C
		// Variables:
	// 		struct MATRIX *matrix; // $a1
	// 		struct _PrimPool *pool; // $v1
	/* end block 1 */
	// End offset: 0x80030D50
	// End Line: 3583

	/* begin block 2 */
		// Start line: 8332
	/* end block 2 */
	// End Line: 8333

	/* begin block 3 */
		// Start line: 8333
	/* end block 3 */
	// End Line: 8334

	/* begin block 4 */
		// Start line: 8334
	/* end block 4 */
	// End Line: 8335

MATRIX * GAMELOOP_GetTimeOfDayIdx(int numMatrices)

{
  MATRIX *pMVar1;
  MATRIX *pMVar2;
  
  pMVar2 = (MATRIX *)(gameTrackerX.primPool)->nextPrim;
  pMVar1 = pMVar2 + numMatrices;
  if (pMVar1 < (MATRIX *)(gameTrackerX.primPool)->lastPrim) {
    *(MATRIX **)&(gameTrackerX.primPool)->nextPrim = pMVar1;
    return pMVar2;
  }
  return (MATRIX *)0x0;
}



// decompiled code
// original method signature: 
// struct GameTracker * /*$ra*/ GAMELOOP_GetGT()
 // line 3588, offset 0x80030d60
	/* begin block 1 */
		// Start line: 8382
	/* end block 1 */
	// End Line: 8383

	/* begin block 2 */
		// Start line: 8383
	/* end block 2 */
	// End Line: 8384

/* WARNING: Unknown calling convention yet parameter storage is locked */

GameTracker * GAMELOOP_GetGT(void)

{
  return &gameTrackerX;
}





