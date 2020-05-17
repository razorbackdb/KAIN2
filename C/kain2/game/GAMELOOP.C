#include "THISDUST.H"
#include "GAMELOOP.H"


// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_AllocStaticMemory()
 // line 143, offset 0x8002db28
	/* begin block 1 */
		// Start line: 286
	/* end block 1 */
	// End Line: 287

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_AllocStaticMemory(void)

{
  instanceList = (_InstanceList *)MEMPACK_Malloc(0x10c,'\x06');
  instancePool = (_InstancePool *)MEMPACK_Malloc((ulong)&DAT_00009c9c,'\x06');
  gOt2 = (ulong **)MEMPACK_Malloc((ulong)&LAB_00034e18,'\x06');
  PTR_800d2fa8 = gOt2 + 0xc00;
  primPool2 = (_PrimPool *)(gOt2 + 0x1800);
  PTR_800d2fb0 = (_PrimPool *)(gOt2 + 0x75c3);
  primBase = (char *)gOt2;
  gLightInfo = (LightInfo *)MEMPACK_Malloc(0x47c,'\x06');
  memset(gLightInfo,0,0x47c);
  gPolytopeList = (_PolytopeList *)MEMPACK_Malloc((ulong)&DAT_000018c0,'\x06');
  gVertexPool = (_VertexPool *)gPolytopeList;
  gFXT = (_FXTracker *)MEMPACK_Malloc((ulong)&DAT_00006da8,'\x06');
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
 // line 189, offset 0x8002dc18
	/* begin block 1 */
		// Start line: 190
		// Start offset: 0x8002DC18

		/* begin block 1.1 */
			// Start line: 190
			// Start offset: 0x8002DC18
			// Variables:
		// 		int i; // $t4
		/* end block 1.1 */
		// End offset: 0x8002DCF0
		// End Line: 264
	/* end block 1 */
	// End offset: 0x8002DCF0
	// End Line: 270

	/* begin block 2 */
		// Start line: 412
	/* end block 2 */
	// End Line: 413

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_InitGameTracker(void)

{
  int iVar1;
  int iVar2;
  
  gameTrackerX.GlobalObjects = GlobalObjects;
  gameTrackerX.planningPool = planningPool;
  gameTrackerX.enemyPlanPool = enemyPlanPool;
  gameTrackerX.vertexPool = gVertexPool;
  primPool2->lastPrim = primPool2->prim + 0x5db4;
  gameTrackerX.instanceList = instanceList;
  PTR_800d2fb0->lastPrim = PTR_800d2fb0->prim + 0x5db4;
  gameTrackerX.lightInfo = gLightInfo;
  primPool2->nextPrim = primPool2->prim;
  gameTrackerX.instancePool = instancePool;
  PTR_800d2fb0->nextPrim = PTR_800d2fb0->prim;
  iVar2 = 0;
  iVar1 = 0;
  gameTrackerX.multGameTime = 10;
  gameTrackerX.material_fadeValue = 0x1000;
  gameTrackerX.spectral_fadeValue = 0;
  gameTrackerX.decoupleGame = 1;
  gameTrackerX.frameRateLock = 1;
  gameTrackerX.primPool = primPool2;
  gameTrackerX.drawOT = gOt2;
  gameTrackerX.dispOT = PTR_800d2fa8;
  gameTrackerX.frameRate24fps = 1;
  do {
    iVar2 = iVar2 + 1;
    *(undefined2 *)((int)&(gameTrackerX.GlobalObjects)->objectStatus + iVar1) = 0;
    iVar1 = iVar1 + 0x24;
  } while (iVar2 < 0x30);
  gameTrackerX.gameData.asmData.MorphTime = 1000;
  OBTABLE_ClearObjectReferences();
  EVENT_Init();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SystemInit(struct GameTracker *gameTracker /*$a0*/)
 // line 285, offset 0x8002dd18
	/* begin block 1 */
		// Start line: 804
	/* end block 1 */
	// End Line: 805

void GAMELOOP_SystemInit(GameTracker *gameTracker)

{
  GAMELOOP_AllocStaticMemory();
  INSTANCE_InitInstanceList(instanceList,instancePool);
  GAMELOOP_InitGameTracker();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_ResetGameStates()
 // line 298, offset 0x8002dd50
	/* begin block 1 */
		// Start line: 830
	/* end block 1 */
	// End Line: 831

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ResetGameStates(void)

{
  EVENT_Init();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_ClearGameTracker()
 // line 304, offset 0x8002dd70
	/* begin block 1 */
		// Start line: 842
	/* end block 1 */
	// End Line: 843

	/* begin block 2 */
		// Start line: 853
	/* end block 2 */
	// End Line: 854

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ClearGameTracker(void)

{
  pause_redraw_flag = 0;
  pause_redraw_prim = (void *)0x0;
  gameTrackerX.gameData.asmData.drawBackFaces = 0;
  gameTrackerX.gameData.asmData.MorphTime = 1000;
  gameTrackerX.debugFlags = gameTrackerX.debugFlags | 0x40000;
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
 // line 334, offset 0x8002ddb8
	/* begin block 1 */
		// Start line: 336
		// Start offset: 0x8002DDB8
		// Variables:
	// 		long time; // $a1
	/* end block 1 */
	// End offset: 0x8002DDB8
	// End Line: 340

	/* begin block 2 */
		// Start line: 905
	/* end block 2 */
	// End Line: 906

	/* begin block 3 */
		// Start line: 918
	/* end block 3 */
	// End Line: 919

	/* begin block 4 */
		// Start line: 919
	/* end block 4 */
	// End Line: 920

	/* begin block 5 */
		// Start line: 923
	/* end block 5 */
	// End Line: 924

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
 // line 345, offset 0x8002de64
	/* begin block 1 */
		// Start line: 346
		// Start offset: 0x8002DE64
		// Variables:
	// 		long tim; // $v1
	/* end block 1 */
	// End offset: 0x8002DEBC
	// End Line: 352

	/* begin block 2 */
		// Start line: 942
	/* end block 2 */
	// End Line: 943

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
 // line 362, offset 0x8002def8
	/* begin block 1 */
		// Start line: 364
		// Start offset: 0x8002DEF8
		// Variables:
	// 		int timeOfDay; // $v1
	/* end block 1 */
	// End offset: 0x8002DF3C
	// End Line: 389

	/* begin block 2 */
		// Start line: 979
	/* end block 2 */
	// End Line: 980

	/* begin block 3 */
		// Start line: 980
	/* end block 3 */
	// End Line: 981

	/* begin block 4 */
		// Start line: 982
	/* end block 4 */
	// End Line: 983

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
 // line 391, offset 0x8002df44
	/* begin block 1 */
		// Start line: 1047
	/* end block 1 */
	// End Line: 1048

	/* begin block 2 */
		// Start line: 1049
	/* end block 2 */
	// End Line: 1050

int GAMELOOP_GetTimeOfDayIdx(int timeOfDay)

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
 // line 819, offset 0x8002df88
	/* begin block 1 */
		// Start line: 1505
	/* end block 1 */
	// End Line: 1506

	/* begin block 2 */
		// Start line: 1913
	/* end block 2 */
	// End Line: 1914

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
 // line 836, offset 0x8002dfc0
	/* begin block 1 */
		// Start line: 837
		// Start offset: 0x8002DFC0
		// Variables:
	// 		struct _SVector offset; // stack offset -32
	// 		struct _StreamUnit *streamUnit; // $s0
	// 		static char oldArea[16]; // offset 0xc

		/* begin block 1.1 */
			// Start line: 855
			// Start offset: 0x8002E034
			// Variables:
		// 		int num; // $v0
		// 		int waitFor; // $s1
		/* end block 1.1 */
		// End offset: 0x8002E0A8
		// End Line: 877

		/* begin block 1.2 */
			// Start line: 905
			// Start offset: 0x8002E12C
			// Variables:
		// 		short _x0; // $a2
		// 		short _y0; // $a3
		// 		short _z0; // $v0
		// 		short _x1; // $v1
		// 		short _y1; // $t1
		// 		short _z1; // $t0
		// 		struct _SVector *_v; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $t0
		/* end block 1.2 */
		// End offset: 0x8002E12C
		// End Line: 905
	/* end block 1 */
	// End offset: 0x8002E12C
	// End Line: 905

	/* begin block 2 */
		// Start line: 1947
	/* end block 2 */
	// End Line: 1948

_StreamUnit * LoadLevels(char *baseAreaName,GameTracker *gameTracker)

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
  strcpy("",baseAreaName);
  LOAD_ChangeDirectory(baseAreaName);
  streamUnit = STREAM_LoadLevel(baseAreaName,(StreamUnitPortal *)0x0,0);
  if (streamUnit->used == 1) {
    DRAW_LoadingMessage();
    sVar1 = streamUnit->used;
    while (sVar1 == 1) {
      GAMELOOP_WaitForLoad();
      sVar1 = streamUnit->used;
    }
    STREAM_NextLoadFromHead();
    STREAM_LoadMainVram(gameTracker,baseAreaName,streamUnit);
    STREAM_NextLoadAsNormal();
    iVar3 = GAMELOOP_WaitForLoad();
    do {
      iVar4 = GAMELOOP_WaitForLoad();
      if (iVar4 == 0) break;
    } while (iVar3 + -1 <= iVar4);
  }
  else {
    STREAM_DumpLoadingObjects();
    STREAM_LoadMainVram(gameTracker,baseAreaName,streamUnit);
  }
  pLVar5 = streamUnit->level;
  p_Var7 = pLVar5->startUnitMainSignal;
  if (p_Var7 != (_MultiSignal *)0x0) {
    if (gameTracker->playerInstance != (_Instance *)0x0) {
      p_Var7->flags = p_Var7->flags | 1;
      SIGNAL_HandleSignal(gameTracker->playerInstance,
                          streamUnit->level->startUnitMainSignal->signalList,0);
      EVENT_AddSignalToReset(streamUnit->level->startUnitMainSignal);
    }
    pLVar5 = streamUnit->level;
  }
  pBVar8 = pLVar5->terrain->BSPTreeArray;
  p_Var6 = pBVar8->bspRoot;
  local_20.x = -((p_Var6->sphere).position.x + (pBVar8->globalOffset).x);
  local_20.y = -((p_Var6->sphere).position.y + (pBVar8->globalOffset).y);
  local_20.z = -((p_Var6->sphere).position.z + (pBVar8->globalOffset).z);
  PreloadAllConnectedUnits(streamUnit,&local_20);
  return streamUnit;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_InitStandardObjects()
 // line 914, offset 0x8002e1c0
	/* begin block 1 */
		// Start line: 915
		// Start offset: 0x8002E1C0
		// Variables:
	// 		static char (*sobjects[10]); // offset 0x0
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x8002E200
	// End Line: 930

	/* begin block 2 */
		// Start line: 2112
	/* end block 2 */
	// End Line: 2113

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_InitStandardObjects(void)

{
  char *name;
  undefined **ppuVar1;
  uint uVar2;
  
  LOAD_DumpCurrentDir();
  uVar2 = 0;
  ppuVar1 = &PTR_s_raziel_800ca1f4;
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
 // line 933, offset 0x8002e214
	/* begin block 1 */
		// Start line: 934
		// Start offset: 0x8002E214
		// Variables:
	// 		long i; // $s1
	// 		struct _StreamUnit *streamUnit; // $s2

		/* begin block 1.1 */
			// Start line: 1012
			// Start offset: 0x8002E340
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $a0
		// 		short _z1; // $v1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v1
		/* end block 1.1 */
		// End offset: 0x8002E340
		// End Line: 1012
	/* end block 1 */
	// End offset: 0x8002E508
	// End Line: 1117

	/* begin block 2 */
		// Start line: 2154
	/* end block 2 */
	// End Line: 2155

void GAMELOOP_LevelLoadAndInit(char *baseAreaName,GameTracker *gameTracker)

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
  GAMELOOP_ClearGameTracker();
  CAMERA_Initialize(&theCamera);
  PLANAPI_InitPlanning(planningPool);
  ENMYPLAN_InitEnemyPlanPool(enemyPlanPool);
  FX_Init(fxTracker);
  WARPGATE_Init();
  DRAW_InitShadow();
  GAMELOOP_InitStandardObjects();
  p_Var1 = LoadLevels(baseAreaName,gameTracker);
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
      iVar3 = strcmpi(pLVar6->introList->name + iVar7,"raziel");
      if (iVar3 == 0) {
        INSTANCE_IntroduceInstance
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
  CAMERA_SetInstanceFocus(&theCamera,gameTracker->playerInstance);
  p_Var4 = gameTracker->playerInstance;
  theCamera.core.position.x = (p_Var4->position).x;
  theCamera.core.position.y = (p_Var4->position).y;
  theCamera.core.position.z = (p_Var4->position).z;
  SetFogNearFar((uint)p_Var1->level->fogNear,(uint)p_Var1->level->fogFar,0x140);
  SetFarColor(0,0,0);
  clearRect.r0 = p_Var1->level->backColorR;
                    /* WARNING: Read-only address (ram,0x800d3340) is written */
  clearRect.g0 = p_Var1->level->backColorG;
                    /* WARNING: Read-only address (ram,0x800d3341) is written */
  clearRect.b0 = p_Var1->level->backColorB;
                    /* WARNING: Read-only address (ram,0x800d3342) is written */
  BLK_FILL_800d334c.r0 = p_Var1->level->backColorR;
                    /* WARNING: Read-only address (ram,0x800d3350) is written */
  BLK_FILL_800d334c.g0 = p_Var1->level->backColorG;
                    /* WARNING: Read-only address (ram,0x800d3351) is written */
  BLK_FILL_800d334c.b0 = p_Var1->level->backColorB;
                    /* WARNING: Read-only address (ram,0x800d3352) is written */
  gameTracker->wipeType = 10;
  gameTracker->hideBG = 0;
  gameTracker->wipeTime = 0x1e;
  gameTracker->maxWipeTime = 0x1e;
  p_Var5 = p_Var1->level->startSignal;
  if (p_Var5 != (_MultiSignal *)0x0) {
    p_Var5->flags = p_Var5->flags | 1;
    SIGNAL_HandleSignal(gameTracker->playerInstance,p_Var1->level->startSignal->signalList,0);
    EVENT_AddSignalToReset(p_Var1->level->startSignal);
  }
  gameTracker->vblFrames = 0;
  p_Var5 = p_Var1->level->startUnitMainSignal;
  if ((p_Var5 != (_MultiSignal *)0x0) && (gameTracker->playerInstance != (_Instance *)0x0)) {
    p_Var5->flags = p_Var5->flags | 1;
    SIGNAL_HandleSignal(gameTracker->playerInstance,p_Var1->level->startUnitMainSignal->signalList,0
                       );
    EVENT_AddSignalToReset(p_Var1->level->startUnitMainSignal);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_StreamLevelLoadAndInit(char *baseAreaName /*$a0*/, struct GameTracker *gameTracker /*$a1*/, int toSignalNum /*$a2*/, int fromSignalNum /*$a3*/)
 // line 1120, offset 0x8002e524
	/* begin block 1 */
		// Start line: 1121
		// Start offset: 0x8002E524
	/* end block 1 */
	// End offset: 0x8002E524
	// End Line: 1121

	/* begin block 2 */
		// Start line: 2556
	/* end block 2 */
	// End Line: 2557

void GAMELOOP_StreamLevelLoadAndInit
               (char *baseAreaName,GameTracker *gameTracker,int toSignalNum,int fromSignalNum)

{
  LoadLevels(baseAreaName,gameTracker);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SetScreenWipe(int time /*$a0*/, int maxTime /*$a1*/, int type /*$a2*/)
 // line 1139, offset 0x8002e544
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
 // line 1147, offset 0x8002e558
	/* begin block 1 */
		// Start line: 1148
		// Start offset: 0x8002E558
		// Variables:
	// 		long temp; // $s0
	// 		struct _PrimPool *primPool; // $s3
	/* end block 1 */
	// End offset: 0x8002E998
	// End Line: 1496

	/* begin block 2 */
		// Start line: 2610
	/* end block 2 */
	// End Line: 2611

	/* begin block 3 */
		// Start line: 2625
	/* end block 3 */
	// End Line: 2626

void GAMELOOP_HandleScreenWipes(ulong **drawot)

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
 // line 1639, offset 0x8002e9b8
	/* begin block 1 */
		// Start line: 1640
		// Start offset: 0x8002E9B8
		// Variables:
	// 		int changed; // $a2
	// 		int setflag; // $s1
	// 		int FogFar; // $a1
	// 		int FogNear; // $a0
	/* end block 1 */
	// End offset: 0x8002EAC8
	// End Line: 1687

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
  uint uVar6;
  int iVar7;
  int iVar8;
  
  bVar4 = false;
  uVar1 = currentUnit->TargetFogNear;
  iVar7 = (int)(short)uVar1;
  uVar6 = (uint)level->fogNear;
  uVar2 = currentUnit->TargetFogFar;
  iVar8 = (int)(short)uVar2;
  bVar5 = false;
  if (iVar7 < (int)uVar6) {
    level->fogNear = (ushort)(uVar6 - 500);
    bVar3 = iVar7 < (int)(uVar6 - 500 & 0xffff);
LAB_8002ea24:
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
      goto LAB_8002ea24;
    }
    bVar5 = true;
  }
  uVar6 = (uint)level->fogFar;
  if (iVar8 < (int)uVar6) {
    level->fogFar = (ushort)(uVar6 - 500);
    bVar4 = true;
    if (iVar8 < (int)(uVar6 - 500 & 0xffff)) {
      bVar5 = false;
      goto LAB_8002ea98;
    }
  }
  else {
    if (iVar8 <= (int)uVar6) goto LAB_8002ea98;
    level->fogFar = (ushort)(uVar6 + 500);
    bVar4 = true;
    if ((int)(uVar6 + 500 & 0xffff) < iVar8) {
      bVar5 = false;
      goto LAB_8002ea98;
    }
  }
  bVar4 = true;
  level->fogFar = uVar2;
LAB_8002ea98:
  if ((bVar4) && (LIGHT_CalcDQPTable(level), bVar5)) {
    currentUnit->TargetFogNear = level->fogNear;
    currentUnit->TargetFogFar = level->fogFar;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CheckForNoBlend(struct _ColorType *Color /*$a0*/)
 // line 1689, offset 0x8002eae0
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
 // line 1699, offset 0x8002eb28
	/* begin block 1 */
		// Start line: 3742
	/* end block 1 */
	// End Line: 3743

void BlendToColor(_ColorType *target,_ColorType *current,_ColorType *dest)

{
  int iVar1;
  
  LoadAverageCol((byte *)target,(byte *)current,0x200,0xe00,(undefined *)dest);
  iVar1 = (uint)target->r - (uint)dest->r;
  if (iVar1 < 0) {
    if (4 < (int)((uint)dest->r - (uint)target->r)) goto LAB_8002ec04;
  }
  else {
    if (4 < iVar1) {
      dest->code = '\0';
      return;
    }
  }
  iVar1 = (uint)target->g - (uint)dest->g;
  if (iVar1 < 0) {
    if (4 < (int)((uint)dest->g - (uint)target->g)) goto LAB_8002ec04;
  }
  else {
    if (4 < iVar1) {
      dest->code = '\0';
      return;
    }
  }
  iVar1 = (uint)target->b - (uint)dest->b;
  if (iVar1 < 0) {
    if (4 < (int)((uint)dest->b - (uint)target->b)) goto LAB_8002ec04;
  }
  else {
    if (4 < iVar1) {
      dest->code = '\0';
      return;
    }
  }
  *dest = *target;
LAB_8002ec04:
  dest->code = '\0';
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MainRenderLevel(struct _StreamUnit *currentUnit /*$s7*/, unsigned long **drawot /*$fp*/)
 // line 1716, offset 0x8002ec1c
	/* begin block 1 */
		// Start line: 1717
		// Start offset: 0x8002EC1C
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
			// Start line: 1769
			// Start offset: 0x8002ECEC
			// Variables:
		// 		int time; // $a2
		/* end block 1.1 */
		// End offset: 0x8002ED20
		// End Line: 1775

		/* begin block 1.2 */
			// Start line: 1783
			// Start offset: 0x8002ED6C
			// Variables:
		// 		int tod; // $v1
		/* end block 1.2 */
		// End offset: 0x8002EDE8
		// End Line: 1797

		/* begin block 1.3 */
			// Start line: 1875
			// Start offset: 0x8002EF04
			// Variables:
		// 		struct _SVector tmp; // stack offset -56
		// 		struct BSPTree *bsp; // $s0
		/* end block 1.3 */
		// End offset: 0x8002EFFC
		// End Line: 1932
	/* end block 1 */
	// End offset: 0x8002F0E0
	// End Line: 1952

	/* begin block 2 */
		// Start line: 3777
	/* end block 2 */
	// End Line: 3778

/* WARNING: This function may have set the stack pointer */
/* WARNING: Could not reconcile some variable overlaps */

void MainRenderLevel(_StreamUnit *currentUnit,ulong **drawot)

{
  MATRIX *pMVar1;
  LightInfo *lightInfo;
  _Instance *p_Var2;
  ulong *puVar3;
  ushort uVar4;
  int unitID;
  uint uVar5;
  Level *level;
  int **ppiVar6;
  _Instance *p_Var7;
  int iVar8;
  _Terrain *terrain;
  int **local_64;
  undefined4 local_60;
  short local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
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
  SetFogNearFar((uint)level->fogNear,(uint)level->fogFar,0x140);
  SetFarColor(0,0,0);
  clearRect.r0 = level->backColorR;
                    /* WARNING: Read-only address (ram,0x800d3340) is written */
  clearRect.g0 = level->backColorG;
                    /* WARNING: Read-only address (ram,0x800d3341) is written */
  clearRect.b0 = level->backColorB;
                    /* WARNING: Read-only address (ram,0x800d3342) is written */
  BLK_FILL_800d334c.r0 = level->backColorR;
                    /* WARNING: Read-only address (ram,0x800d3350) is written */
  BLK_FILL_800d334c.g0 = level->backColorG;
                    /* WARNING: Read-only address (ram,0x800d3351) is written */
  BLK_FILL_800d334c.b0 = level->backColorB;
                    /* WARNING: Read-only address (ram,0x800d3352) is written */
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
  depthQFogStart = (uint)level->fogNear;
  depthQFogFar = (uint)level->fogFar;
  unitID = CheckForNoBlend((_ColorType *)&depthQBackColor);
  depthQBlendStart = 0xffff;
  if (unitID == 0) {
    depthQBlendStart = depthQFogStart;
  }
                    /* WARNING: Read-only address (ram,0x800d3340) is written */
  clearRect.r0 = (uchar)depthQBackColor;
                    /* WARNING: Read-only address (ram,0x800d3341) is written */
  clearRect.g0 = depthQBackColor._1_1_;
                    /* WARNING: Read-only address (ram,0x800d3342) is written */
  clearRect.b0 = depthQBackColor._2_1_;
                    /* WARNING: Read-only address (ram,0x800d3350) is written */
  BLK_FILL_800d334c.r0 = (uchar)depthQBackColor;
                    /* WARNING: Read-only address (ram,0x800d3351) is written */
  BLK_FILL_800d334c.g0 = depthQBackColor._1_1_;
                    /* WARNING: Read-only address (ram,0x800d3352) is written */
  BLK_FILL_800d334c.b0 = depthQBackColor._2_1_;
  PIPE3D_AnimateTerrainTextures
            (terrain->aniList,gameTrackerX.frameCount,gameTrackerX.primPool,drawot);
  PIPE3D_AnimateTerrainTextures
            (level->bgAniList,gameTrackerX.frameCount,gameTrackerX.primPool,drawot);
  gLightInfo->numSavedColors = 0;
  PIPE3D_InstanceListTransformAndDraw
            (currentUnit,&gameTrackerX,drawot,(_CameraCore_Type *)&theCamera);
  local_60 = theCamera.core.position._0_4_;
  local_5c = theCamera.core.position.z;
  local_58 = *(undefined4 *)(theCamera.core.wcTransform)->m;
  local_54 = *(undefined4 *)((theCamera.core.wcTransform)->m + 2);
  local_50 = *(undefined4 *)((theCamera.core.wcTransform)->m + 4);
  local_4c = *(undefined4 *)((theCamera.core.wcTransform)->m + 6);
  local_48 = *(undefined4 *)((theCamera.core.wcTransform)->m + 8);
  local_44 = (theCamera.core.wcTransform)->t[0];
  local_40 = (theCamera.core.wcTransform)->t[1];
  local_3c = (theCamera.core.wcTransform)->t[2];
  unitID = 0;
  if (0 < terrain->numBSPTrees) {
    iVar8 = 0;
    do {
      p_Var2 = gameTrackerX.gameData.asmData.lightInstances[0].lightInstance;
      ppiVar6 = (int **)((int)&terrain->BSPTreeArray->bspRoot + iVar8);
      if ((-1 < *(short *)((int)ppiVar6 + 0x1a)) && ((*(ushort *)((int)ppiVar6 + 0x12) & 1) == 0)) {
        p_Var7 = (_Instance *)0x0;
        if ((*(ushort *)((int)ppiVar6 + 0x12) & 0x40) != 0) {
          gameTrackerX.gameData.asmData.lightInstances[0].lightInstance = (_Instance *)0x0;
          p_Var7 = p_Var2;
        }
        uVar5 = (local_60 & 0xffff) - (uint)*(ushort *)(ppiVar6 + 3);
        local_38 = -(short)uVar5;
        uVar4 = local_60._2_2_ - *(short *)((int)ppiVar6 + 0xe);
        theCamera.core.position._0_4_ = uVar5 & 0xffff | (uint)uVar4 << 0x10;
        local_36 = -uVar4;
        theCamera.core.position.z = local_5c - *(short *)(ppiVar6 + 4);
        local_34 = -theCamera.core.position.z;
        ApplyMatrix(&local_58,&local_38,(theCamera.core.wcTransform)->t);
        BSP_MarkVisibleLeaves_S(ppiVar6,(undefined4 *)&theCamera,(int *)gPolytopeList);
        local_64 = ppiVar6 + 3;
        puVar3 = (ulong *)(*(code *)gameTrackerX.drawDisplayPolytopeListFunc)
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
  *(undefined4 *)(theCamera.core.wcTransform)->m = local_58;
  *(undefined4 *)(pMVar1->m + 2) = local_54;
  *(undefined4 *)(pMVar1->m + 4) = local_50;
  *(undefined4 *)(pMVar1->m + 6) = local_4c;
  *(undefined4 *)(pMVar1->m + 8) = local_48;
  pMVar1->t[0] = local_44;
  pMVar1->t[1] = local_40;
  pMVar1->t[2] = local_3c;
  SBSP_IntroduceInstancesAndLights(terrain,(_CameraCore_Type *)&theCamera,lightInfo,unitID);
  StackSave = (ulong)&stack0xffffff88;
  FX_DrawList(fxTracker,&gameTrackerX,gameTrackerX.drawOT,theCamera.core.wcTransform);
  if ((gameTrackerX.playerInstance)->currentStreamUnitID == currentUnit->StreamUnitID) {
    FX_DrawReaver(gameTrackerX.primPool,gameTrackerX.drawOT,theCamera.core.wcTransform);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StreamIntroInstancesForUnit(struct _StreamUnit *currentUnit /*$a1*/)
 // line 1959, offset 0x8002f11c
	/* begin block 1 */
		// Start line: 1960
		// Start offset: 0x8002F11C
	/* end block 1 */
	// End offset: 0x8002F14C
	// End Line: 1972

	/* begin block 2 */
		// Start line: 4443
	/* end block 2 */
	// End Line: 4444

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
 // line 1976, offset 0x8002f15c
	/* begin block 1 */
		// Start line: 1977
		// Start offset: 0x8002F15C
		// Variables:
	// 		struct GameTracker *gameTracker; // $s4
	// 		struct Level *level; // $s1
	// 		struct _Terrain *terrain; // $s2
	// 		int curTree; // $s1
	// 		int farplanesave; // $fp
	// 		struct _Position cam_pos_save; // stack offset -88
	// 		struct MATRIX cam_mat_save; // stack offset -80

		/* begin block 1.1 */
			// Start line: 2062
			// Start offset: 0x8002F2C0
			// Variables:
		// 		struct _SVector tmp; // stack offset -48
		// 		struct BSPTree *bsp; // $s0
		/* end block 1.1 */
		// End offset: 0x8002F38C
		// End Line: 2110

		/* begin block 1.2 */
			// Start line: 2128
			// Start offset: 0x8002F438
		/* end block 1.2 */
		// End offset: 0x8002F46C
		// End Line: 2138
	/* end block 1 */
	// End offset: 0x8002F46C
	// End Line: 2140

	/* begin block 2 */
		// Start line: 4477
	/* end block 2 */
	// End Line: 4478

/* WARNING: This function may have set the stack pointer */
/* WARNING: Could not reconcile some variable overlaps */

long StreamRenderLevel(_StreamUnit *currentUnit,Level *mainLevel,ulong **drawot,long portalFogColor)

{
  MATRIX *pMVar1;
  long lVar2;
  LightInfo *lightInfo;
  int unitID;
  ulong *puVar3;
  ushort uVar4;
  uint uVar5;
  int **ppiVar6;
  Level *level;
  _Terrain *terrain;
  int iVar7;
  undefined auStack112 [16];
  ulong **local_60;
  int **local_5c;
  undefined4 local_58;
  short local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
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
  depthQFogFar = (uint)level->fogFar;
  depthQFogStart = (uint)level->fogNear;
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
  PIPE3D_InstanceListTransformAndDraw
            (currentUnit,&gameTrackerX,drawot,(_CameraCore_Type *)&theCamera);
  local_58 = theCamera.core.position._0_4_;
  local_54 = theCamera.core.position.z;
  local_50 = *(undefined4 *)(theCamera.core.wcTransform)->m;
  local_4c = *(undefined4 *)((theCamera.core.wcTransform)->m + 2);
  local_48 = *(undefined4 *)((theCamera.core.wcTransform)->m + 4);
  local_44 = *(undefined4 *)((theCamera.core.wcTransform)->m + 6);
  local_40 = *(undefined4 *)((theCamera.core.wcTransform)->m + 8);
  local_3c = (theCamera.core.wcTransform)->t[0];
  local_38 = (theCamera.core.wcTransform)->t[1];
  local_34 = (theCamera.core.wcTransform)->t[2];
  unitID = 0;
  if (0 < terrain->numBSPTrees) {
    iVar7 = 0;
    do {
      ppiVar6 = (int **)((int)&terrain->BSPTreeArray->bspRoot + iVar7);
      if ((-1 < *(short *)((int)ppiVar6 + 0x1a)) && ((*(ushort *)((int)ppiVar6 + 0x12) & 1) == 0)) {
        uVar5 = (local_58 & 0xffff) - (uint)*(ushort *)(ppiVar6 + 3);
        local_30 = -(short)uVar5;
        uVar4 = local_58._2_2_ - *(short *)((int)ppiVar6 + 0xe);
        theCamera.core.position._0_4_ = uVar5 & 0xffff | (uint)uVar4 << 0x10;
        local_2e = -uVar4;
        theCamera.core.position.z = local_54 - *(short *)(ppiVar6 + 4);
        local_2c = -theCamera.core.position.z;
        ApplyMatrix(&local_50,&local_30,(theCamera.core.wcTransform)->t);
        BSP_MarkVisibleLeaves_S(ppiVar6,(undefined4 *)&theCamera,(int *)gPolytopeList);
        local_5c = ppiVar6 + 3;
        local_60 = drawot;
        puVar3 = (ulong *)(*(code *)gameTrackerX.drawDisplayPolytopeListFunc)
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
  *(undefined4 *)(theCamera.core.wcTransform)->m = local_50;
  *(undefined4 *)(pMVar1->m + 2) = local_4c;
  *(undefined4 *)(pMVar1->m + 4) = local_48;
  *(undefined4 *)(pMVar1->m + 6) = local_44;
  *(undefined4 *)(pMVar1->m + 8) = local_40;
  pMVar1->t[0] = local_3c;
  pMVar1->t[1] = local_38;
  pMVar1->t[2] = local_34;
  SBSP_IntroduceInstancesAndLights(terrain,(_CameraCore_Type *)&theCamera,lightInfo,unitID);
  InStreamUnit = 0;
  theCamera.core.farPlane = lVar2;
  if ((gameTrackerX.playerInstance)->currentStreamUnitID == currentUnit->StreamUnitID) {
    hackOT = drawot;
    StackSave = (ulong)auStack112;
    FX_DrawReaver(gameTrackerX.primPool,drawot,theCamera.core.wcTransform);
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_FlipScreenAndDraw(struct GameTracker *gameTracker /*$s0*/, unsigned long **drawot /*$a1*/)
 // line 2164, offset 0x8002f4a4
	/* begin block 1 */
		// Start line: 5010
	/* end block 1 */
	// End Line: 5011

void GAMELOOP_FlipScreenAndDraw(GameTracker *gameTracker,ulong **drawot)

{
  int iVar1;
  uint uVar2;
  
  DrawOTag(drawot + 0xbff);
  do {
    iVar1 = CheckVolatile(gameTracker->drawTimerReturn);
  } while (iVar1 != 0);
  ResetPrimPool();
  PutDrawEnv((undefined4 *)(&draw + gameTracker->drawPage));
  do {
    iVar1 = CheckVolatile(gameTracker->reqDisp);
  } while (iVar1 != 0);
  uVar2 = GetRCnt(0xf2000000);
  *(ulong **)&gameTracker->drawTimerReturn = &gameTracker->drawTime;
  iVar1 = (gameTracker->gameData).asmData.dispPage;
  gameTracker->usecsStartDraw = uVar2 & 0xffff | gameTimer << 0x10;
  (gameTracker->gameData).asmData.dispPage = 1 - iVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_AddClearPrim(unsigned long **drawot /*$a3*/, int override /*$a1*/)
 // line 2196, offset 0x8002f558
	/* begin block 1 */
		// Start line: 2197
		// Start offset: 0x8002F558

		/* begin block 1.1 */
			// Start line: 2201
			// Start offset: 0x8002F574
			// Variables:
		// 		struct BLK_FILL *blkfill; // $a0
		/* end block 1.1 */
		// End offset: 0x8002F574
		// End Line: 2201

		/* begin block 1.2 */
			// Start line: 2217
			// Start offset: 0x8002F5E0
			// Variables:
		// 		struct BLK_FILL *blkfill; // $v1
		/* end block 1.2 */
		// End offset: 0x8002F5F8
		// End Line: 2219
	/* end block 1 */
	// End offset: 0x8002F5F8
	// End Line: 2220

	/* begin block 2 */
		// Start line: 5081
	/* end block 2 */
	// End Line: 5082

	/* begin block 3 */
		// Start line: 5083
	/* end block 3 */
	// End Line: 5084

void GAMELOOP_AddClearPrim(ulong **drawot,int override)

{
  ulong *puVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  if (((gameTrackerX.gameFlags & 0x8000000U) != 0) && (override == 0)) {
    *(ushort *)&(gameTrackerX.savedOTStart)->b0 = (&clearRect)[gameTrackerX.drawPage].y0;
    return;
  }
  puVar1 = (gameTrackerX.primPool)->nextPrim;
  uVar2 = *(ulong *)&(&clearRect)[gameTrackerX.drawPage].r0;
  uVar3 = *(ulong *)&(&clearRect)[gameTrackerX.drawPage].x0;
  uVar4 = *(ulong *)&(&clearRect)[gameTrackerX.drawPage].w;
  *puVar1 = (&clearRect)[gameTrackerX.drawPage].tag;
  puVar1[1] = uVar2;
  puVar1[2] = uVar3;
  puVar1[3] = uVar4;
  (gameTrackerX.primPool)->nextPrim = puVar1 + 4;
  *puVar1 = (uint)drawot[0xbff] & 0xffffff | 0x3000000;
  drawot[0xbff] = (ulong *)((uint)puVar1 & 0xffffff);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SwitchTheDrawBuffer(unsigned long **drawot /*$a0*/)
 // line 2222, offset 0x8002f600
	/* begin block 1 */
		// Start line: 5152
	/* end block 1 */
	// End Line: 5153

void GAMELOOP_SwitchTheDrawBuffer(ulong **drawot)

{
  GAMELOOP_AddClearPrim(drawot,0);
  DrawSync(0);
  if (gameTrackerX.drawTimerReturn != (long *)0x0) {
    gameTrackerX.drawTimerReturn = (long *)0x0;
    gameTrackerX.reqDisp =
         (void *)((int)gameTrackerX.disp + gameTrackerX.gameData.asmData.dispPage * 0x14);
  }
  PutDrawEnv((undefined4 *)(&draw + gameTrackerX.drawPage));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SetupRenderFunction(struct GameTracker *gameTracker /*$a0*/)
 // line 2254, offset 0x8002f680
	/* begin block 1 */
		// Start line: 5217
	/* end block 1 */
	// End Line: 5218

	/* begin block 2 */
		// Start line: 5232
	/* end block 2 */
	// End Line: 5233

void GAMELOOP_SetupRenderFunction(GameTracker *gameTracker)

{
  *(undefined **)&gameTracker->drawAnimatedModelFunc = &DRAW_AnimatedModel_S;
  *(undefined **)&gameTracker->drawDisplayPolytopeListFunc = &DRAW_DisplayPolytopeList_S;
  return;
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ GAMELOOP_GetMainRenderUnit()
 // line 2280, offset 0x8002f69c
	/* begin block 1 */
		// Start line: 2281
		// Start offset: 0x8002F69C
		// Variables:
	// 		struct _StreamUnit *streamUnit; // $s0

		/* begin block 1.1 */
			// Start line: 2292
			// Start offset: 0x8002F6CC
			// Variables:
		// 		struct _Instance *focusInstance; // $s1

			/* begin block 1.1.1 */
				// Start line: 2313
				// Start offset: 0x8002F72C
				// Variables:
			// 		struct _StreamUnit *cameraUnit; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8002F744
			// End Line: 2321
		/* end block 1.1 */
		// End offset: 0x8002F744
		// End Line: 2322
	/* end block 1 */
	// End offset: 0x8002F748
	// End Line: 2326

	/* begin block 2 */
		// Start line: 5269
	/* end block 2 */
	// End Line: 5270

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
 // line 2332, offset 0x8002f75c
	/* begin block 1 */
		// Start line: 2333
		// Start offset: 0x8002F75C
		// Variables:
	// 		unsigned long **drawot; // stack offset -64
	// 		struct Level *mainLevel; // stack offset -60
	// 		struct StreamUnitPortal *streamPortal; // stack offset -56
	// 		int numportals; // stack offset -52
	// 		int d; // $s6
	// 		struct _StreamUnit *mainStreamUnit; // $fp
	// 		void *savedNextPrim; // stack offset -48

		/* begin block 1.1 */
			// Start line: 2444
			// Start offset: 0x8002F9D4
			// Variables:
		// 		struct _StreamUnit *toStreamUnit; // $s3
		// 		long toStreamUnitID; // stack offset -44
		// 		struct StreamUnitPortal *streamPortal2; // $s4
		// 		int i; // $s5
		// 		int draw; // $s2
		// 		struct RECT cliprect; // stack offset -72

			/* begin block 1.1.1 */
				// Start line: 2485
				// Start offset: 0x8002FAA8
				// Variables:
			// 		int streamID; // $s0
			// 		struct _Instance *instance; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8002FB08
			// End Line: 2495
		/* end block 1.1 */
		// End offset: 0x8002FC8C
		// End Line: 2564
	/* end block 1 */
	// End offset: 0x8002FEE8
	// End Line: 2681

	/* begin block 2 */
		// Start line: 5376
	/* end block 2 */
	// End Line: 5377

void GAMELOOP_DisplayFrame(GameTracker *gameTracker)

{
  bool bVar1;
  _StreamUnit *currentUnit;
  long lVar2;
  int *piVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  STracker *currentUnit_00;
  ulong **polyAddr;
  int **ppiVar8;
  _StreamUnit *currentUnit_01;
  StreamUnitPortal *portal;
  int iVar9;
  int iVar10;
  ushort *puVar11;
  RECT local_48;
  ulong **local_40;
  Level *local_3c;
  StreamUnitPortal *local_38;
  int local_34;
  ulong *local_30;
  int *local_2c;
  
  local_40 = gameTracker->drawOT;
  if (((gameTrackerX.gameFlags & 0x8000000U) == 0) || (pause_redraw_flag != 0)) {
    if (pause_redraw_flag == 0) {
      pause_redraw_prim = (gameTrackerX.primPool)->nextPrim;
    }
    else {
      local_30 = (gameTrackerX.primPool)->nextPrim;
      DrawSync(0);
      Switch_For_Redraw();
      local_40 = gameTracker->drawOT;
      ClearOTagR(gameTrackerX.drawOT,0xc00);
      if (pause_redraw_prim == (void *)0x0) {
        (gameTrackerX.primPool)->nextPrim = (gameTrackerX.primPool)->prim;
      }
      else {
        (gameTrackerX.primPool)->nextPrim = pause_redraw_prim;
      }
    }
    gameTrackerX.visibleInstances = 0;
    gameTrackerX.displayFrameCount = gameTrackerX.displayFrameCount + 1;
    GAMELOOP_SetupRenderFunction(&gameTrackerX);
    if (((GlobalSave->flags & 1U) == 0) &&
       (((gameTracker->wipeType != 0xb || (gameTracker->wipeTime == 0)) &&
        ((gameTracker->debugFlags2 & 0x800U) != 0)))) {
      FX_Spiral(gameTrackerX.primPool,local_40);
    }
    if (pause_redraw_flag == 0) {
      HUD_Draw();
    }
    currentUnit = GAMELOOP_GetMainRenderUnit();
    local_3c = currentUnit->level;
    if ((gameTracker->debugFlags & 4U) != 0) {
      FONT_Print("Cameraunit: %s\n");
    }
    RENDER_currentStreamUnitID = *(short *)&currentUnit->StreamUnitID;
    theCamera.core.rightX = 0x140;
    theCamera.core.leftX = 0;
    theCamera.core.topY = 0;
    theCamera.core.bottomY = 0xf0;
    CAMERA_SetViewVolume(&theCamera);
    lVar2 = MEMPACK_MemoryValidFunc((char *)local_3c);
    if (lVar2 != 0) {
      if ((uint)local_3c->fogFar != theCamera.core.farPlane) {
        theCamera.core.farPlane = (uint)local_3c->fogFar;
      }
      if ((gameTracker->debugFlags & 0x8000U) == 0) {
        MainRenderLevel(currentUnit,local_40);
      }
    }
    piVar3 = (int *)local_3c->terrain->StreamUnits;
    local_34 = *piVar3;
    local_38 = (StreamUnitPortal *)(piVar3 + 1);
    iVar10 = 0;
    if (0 < local_34) {
      puVar11 = (ushort *)((int)piVar3 + 0x22);
      do {
        local_2c = *(int **)(puVar11 + -5);
        currentUnit_01 = *(_StreamUnit **)(puVar11 + 5);
        if ((currentUnit_01 == (_StreamUnit *)0x0) ||
           (currentUnit_01->FrameCount != gameTrackerX.displayFrameCount)) {
          local_48.x = 0x200;
          local_48.y = 0xf0;
          local_48.w = -0x200;
          local_48.h = -0xf0;
          theCamera.core.rightX = 0x140;
          theCamera.core.leftX = 0;
          theCamera.core.topY = 0;
          theCamera.core.bottomY = 0xf0;
          CAMERA_SetViewVolume(&theCamera);
          iVar9 = 0;
          bVar1 = false;
          pvVar4 = local_3c->terrain->StreamUnits;
          portal = (StreamUnitPortal *)((int)pvVar4 + 4);
          if (0 < local_34) {
            ppiVar8 = (int **)((int)pvVar4 + 0x2c);
            do {
              if (ppiVar8[-5] == local_2c) {
                iVar5 = STREAM_GetClipRect(portal,&local_48);
                if (iVar5 == 0) {
                  if ((theCamera.instance_mode & 0x2000000) != 0) {
                    iVar5 = **ppiVar8;
                    uVar7 = INSTANCE_Query(gameTrackerX.playerInstance,0x22);
                    if ((iVar5 == (gameTrackerX.playerInstance)->currentStreamUnitID) ||
                       ((uVar7 != 0 && (iVar5 == *(int *)(uVar7 + 0x38))))) {
                      bVar1 = true;
                      local_48.w = 0x200;
                      local_48.x = 0;
                      local_48.y = 0;
                      local_48.h = 0xf0;
                    }
                  }
                }
                else {
                  bVar1 = true;
                }
              }
              iVar9 = iVar9 + 1;
              ppiVar8 = ppiVar8 + 0x17;
              portal = portal + 1;
            } while (iVar9 < local_34);
          }
          if (bVar1) {
            theCamera.core.leftX = (int)local_48.x * 0x140;
            if (theCamera.core.leftX < 0) {
              theCamera.core.leftX = theCamera.core.leftX + 0x1ff;
            }
            theCamera.core.topY = (int)local_48.y;
            theCamera.core.leftX = theCamera.core.leftX >> 9;
            theCamera.core.rightX = ((int)local_48.x + (int)local_48.w) * 0x140;
            if (theCamera.core.rightX < 0) {
              theCamera.core.rightX = theCamera.core.rightX + 0x1ff;
            }
            theCamera.core.rightX = theCamera.core.rightX >> 9;
            theCamera.core.bottomY = theCamera.core.topY + local_48.h;
            CAMERA_SetViewVolume(&theCamera);
            SetRotMatrix((undefined4 *)theCamera.core.wcTransform);
            SetTransMatrix((int)theCamera.core.wcTransform);
            if ((*puVar11 & 1) == 0) {
              if ((currentUnit_01 != (_StreamUnit *)0x0) &&
                 (currentUnit_01->FrameCount != gameTrackerX.displayFrameCount)) {
                currentUnit_01->FrameCount = gameTrackerX.displayFrameCount;
                STREAM_RenderAdjacantUnit(local_40,local_38,currentUnit_01,currentUnit,&local_48);
              }
            }
            else {
              if ((currentUnit->flags & 8U) == 0) {
                WARPGATE_IsItActive(currentUnit);
              }
              else {
                if (currentUnit_01 != (_StreamUnit *)0x0) {
                  if (currentUnit_01->FrameCount == gameTrackerX.displayFrameCount)
                  goto LAB_8002fc8c;
                  currentUnit_01->FrameCount = gameTrackerX.displayFrameCount;
                }
                STREAM_RenderWarpGate(local_40,local_38,currentUnit,&local_48);
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
LAB_8002fc8c:
        iVar10 = iVar10 + 1;
        local_38 = local_38 + 1;
        puVar11 = puVar11 + 0x2e;
      } while (iVar10 < local_34);
    }
    iVar10 = 0;
    currentUnit_00 = &StreamTracker;
    do {
      if ((*(short *)currentUnit_00->StreamList == 2) &&
         (*(ulong *)currentUnit_00->StreamList != gameTrackerX.displayFrameCount)) {
        *(ulong *)currentUnit_00->StreamList = gameTrackerX.displayFrameCount;
        StreamIntroInstancesForUnit((_StreamUnit *)currentUnit_00);
      }
      iVar10 = iVar10 + 1;
      currentUnit_00 = (STracker *)(currentUnit_00->StreamList + 1);
    } while (iVar10 < 0x10);
    theCamera.core.rightX = 0x140;
    theCamera.core.leftX = 0;
    theCamera.core.topY = 0;
    theCamera.core.bottomY = 0xf0;
    CAMERA_SetViewVolume(&theCamera);
    if (pause_redraw_flag != 0) {
      GAMELOOP_AddClearPrim(local_40,1);
      SaveOT();
      ClearOTagR(gameTrackerX.drawOT,0xc00);
      Switch_For_Redraw();
      local_40 = gameTracker->drawOT;
      pause_redraw_flag = 0;
      (gameTrackerX.primPool)->nextPrim = local_30;
    }
  }
  if ((gameTrackerX.gameFlags & 0x8000000U) != 0) {
    HUD_Draw();
  }
  DEBUG_Draw(gameTracker,local_40);
  FONT_Flush();
  GAMELOOP_SwitchTheDrawBuffer(local_40);
  uVar6 = GetRCnt(0xf2000000);
  gameTracker->idleTime = uVar6 & 0xffff | gameTimer << 0x10;
  if ((uint)gameTracker->frameRateLock < gameTracker->vblFrames) {
    if ((ushort *)gameTracker->reqDisp != (ushort *)0x0) {
      PutDispEnv((ushort *)gameTracker->reqDisp);
      gameTracker->reqDisp = (void *)0x0;
      gameTracker->vblFrames = 0;
    }
  }
  else {
    do {
      iVar10 = CheckVolatile(gameTracker->reqDisp);
    } while (iVar10 != 0);
  }
  uVar7 = TIMER_TimeDiff(gameTracker->idleTime);
  polyAddr = local_40 + 0xbff;
  iVar10 = (gameTracker->gameData).asmData.dispPage;
  gameTracker->idleTime = uVar7;
  (gameTracker->gameData).asmData.dispPage = 1 - iVar10;
  DEBUG_DrawShrinkCels(polyAddr);
  GAMELOOP_HandleScreenWipes(local_40);
  uVar6 = GetRCnt(0xf2000000);
  *(ulong **)&gameTracker->drawTimerReturn = &gameTracker->drawTime;
  gameTracker->usecsStartDraw = uVar6 & 0xffff | gameTimer << 0x10;
  if ((gameTrackerX.gameFlags & 0x8000000U) == 0) {
    DrawOTag(polyAddr);
  }
  else {
    GAMELOOP_DrawSavedOT(local_40);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_DrawSavedOT(unsigned long **newOT /*$t3*/)
 // line 2687, offset 0x8002ff18
	/* begin block 1 */
		// Start line: 2688
		// Start offset: 0x8002FF18
		// Variables:
	// 		struct P_TAG *tag; // $a1
	// 		int y; // $a2

		/* begin block 1.1 */
			// Start line: 2696
			// Start offset: 0x8002FF7C
			// Variables:
		// 		int tpage; // $v1
		/* end block 1.1 */
		// End offset: 0x8002FFA4
		// End Line: 2704

		/* begin block 1.2 */
			// Start line: 2709
			// Start offset: 0x8002FFB8
			// Variables:
		// 		int tpage; // $v1
		/* end block 1.2 */
		// End offset: 0x8002FFE0
		// End Line: 2717

		/* begin block 1.3 */
			// Start line: 2722
			// Start offset: 0x8002FFF4
		/* end block 1.3 */
		// End offset: 0x80030028
		// End Line: 2733
	/* end block 1 */
	// End offset: 0x8003004C
	// End Line: 2736

	/* begin block 2 */
		// Start line: 6339
	/* end block 2 */
	// End Line: 6340

void GAMELOOP_DrawSavedOT(ulong **newOT)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
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
              uVar6 = *(uint *)&pPVar7->r0 & 0xfffbffff;
            }
            else {
              uVar4 = pPVar7->len | 0x40000;
              uVar6 = *(uint *)&pPVar7->r0 | 0x40000;
            }
            pPVar7->len = uVar4;
            *(uint *)&pPVar7->r0 = uVar6;
          }
        }
      }
      pPVar7 = (P_TAG *)(pPVar7->addr & 0xffffff | 0x80000000);
    } while (pPVar7 != gameTrackerX.savedOTEnd);
  }
  (gameTrackerX.savedOTEnd)->addr =
       (gameTrackerX.savedOTEnd)->addr & 0xff000000 | (uint)(newOT + 0xbff) & 0xffffff;
  DrawOTag((undefined4 *)gameTrackerX.savedOTStart);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ResetPrimPool()
 // line 2741, offset 0x80030090
	/* begin block 1 */
		// Start line: 6497
	/* end block 1 */
	// End Line: 6498

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ResetPrimPool(void)

{
  undefined **ppuVar1;
  
  ResetDrawPage();
  if ((gameTrackerX.gameFlags & 0x8000000U) == 0) {
    if (gameTrackerX.primPool == primPool2) {
      gameTrackerX.primPool = PTR_800d2fb0;
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
         (ulong *)((int)&(gameTrackerX.primPool)->numPrims + (int)ppuVar1);
  }
  (gameTrackerX.primPool)->numPrims = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Switch_For_Redraw()
 // line 2770, offset 0x8003013c
	/* begin block 1 */
		// Start line: 2772
		// Start offset: 0x8003013C
		// Variables:
	// 		unsigned long **temp; // $v1
	/* end block 1 */
	// End offset: 0x8003019C
	// End Line: 2797

	/* begin block 2 */
		// Start line: 6555
	/* end block 2 */
	// End Line: 6556

	/* begin block 3 */
		// Start line: 6556
	/* end block 3 */
	// End Line: 6557

	/* begin block 4 */
		// Start line: 6559
	/* end block 4 */
	// End Line: 6560

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Switch_For_Redraw(void)

{
  bool bVar1;
  ulong **ppuVar2;
  
  ppuVar2 = gameTrackerX.drawOT;
  gameTrackerX.drawOT = gameTrackerX.dispOT;
  gameTrackerX.dispOT = ppuVar2;
  bVar1 = gameTrackerX.drawPage == 0;
  gameTrackerX.drawPage = ZEXT14(bVar1);
  gameTrackerX.gameData.asmData.dispPage = ZEXT14(!bVar1);
  if (gameTrackerX.primPool == primPool2) {
    gameTrackerX.primPool = PTR_800d2fb0;
  }
  else {
    gameTrackerX.primPool = primPool2;
  }
  (gameTrackerX.primPool)->nextPrim = (gameTrackerX.primPool)->prim;
  (gameTrackerX.primPool)->numPrims = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_Set_Pause_Redraw()
 // line 2801, offset 0x800301b8
	/* begin block 1 */
		// Start line: 6620
	/* end block 1 */
	// End Line: 6621

	/* begin block 2 */
		// Start line: 6621
	/* end block 2 */
	// End Line: 6622

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_Set_Pause_Redraw(void)

{
  pause_redraw_flag = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SaveOT()
 // line 2806, offset 0x800301c8
	/* begin block 1 */
		// Start line: 2807
		// Start offset: 0x800301C8
		// Variables:
	// 		struct P_TAG *tag; // $a0
	// 		struct P_TAG *last; // $s0
	// 		struct P_TAG *lastlast; // $s1
	/* end block 1 */
	// End offset: 0x80030354
	// End Line: 2857

	/* begin block 2 */
		// Start line: 6630
	/* end block 2 */
	// End Line: 6631

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SaveOT(void)

{
  char cVar1;
  P_TAG *pPVar2;
  P_TAG *pPVar3;
  uint uVar4;
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
    if (uVar4 == 0xffffff) goto LAB_80030244;
    cVar1 = *(char *)((int)&pPVar5->addr + 3);
  }
  if ((pPVar5->addr & 0xffffff) == 0xffffff) {
LAB_80030244:
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
          if (uVar4 == 0xffffff) goto LAB_80030330;
          pPVar2 = (P_TAG *)(uVar4 | 0x80000000);
          pPVar3 = pPVar5;
          pPVar7 = pPVar6;
        }
        if ((pPVar5->addr & 0xffffff) == 0xffffff) goto LAB_80030330;
        cVar1 = *(char *)((int)&pPVar5->addr + 3);
        while ((cVar1 == '\0' && (uVar4 = pPVar5->addr & 0xffffff, uVar4 != 0xffffff))) {
          pPVar5 = (P_TAG *)(uVar4 | 0x80000000);
          cVar1 = *(char *)((int)&pPVar5->addr + 3);
        }
        pPVar6->addr = pPVar6->addr & 0xff000000 | (uint)pPVar5 & 0xffffff;
        pPVar2 = pPVar5;
        pPVar3 = pPVar6;
      } while ((pPVar5->addr & 0xffffff) != 0xffffff);
      if ((pPVar5->addr & 0xffffff) != 0xffffff) {
        gameTrackerX.savedOTEnd = pPVar5;
        return;
      }
    }
LAB_80030330:
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
 // line 2859, offset 0x80030368
	/* begin block 1 */
		// Start line: 2860
		// Start offset: 0x80030368

		/* begin block 1.1 */
			// Start line: 2860
			// Start offset: 0x80030368
			// Variables:
		// 		unsigned long **temp; // $v0
		/* end block 1.1 */
		// End offset: 0x80030368
		// End Line: 2860
	/* end block 1 */
	// End offset: 0x80030368
	// End Line: 2860

	/* begin block 2 */
		// Start line: 6756
	/* end block 2 */
	// End Line: 6757

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ResetDrawPage(void)

{
  ulong **ppuVar1;
  
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
 // line 2891, offset 0x800303a8
	/* begin block 1 */
		// Start line: 6832
	/* end block 1 */
	// End Line: 6833

	/* begin block 2 */
		// Start line: 6833
	/* end block 2 */
	// End Line: 6834

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_Set24FPS(void)

{
  gameTrackerX.frameRate24fps = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_Reset24FPS()
 // line 2897, offset 0x800303b8
	/* begin block 1 */
		// Start line: 6844
	/* end block 1 */
	// End Line: 6845

	/* begin block 2 */
		// Start line: 6845
	/* end block 2 */
	// End Line: 6846

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_Reset24FPS(void)

{
  gameTrackerX.frameRate24fps = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_DoTimeProcess()
 // line 2902, offset 0x800303c4
	/* begin block 1 */
		// Start line: 2903
		// Start offset: 0x800303C4
		// Variables:
	// 		int holdTime; // $s1

		/* begin block 1.1 */
			// Start line: 2938
			// Start offset: 0x800304A8
			// Variables:
		// 		int lockRate; // $a1
		// 		unsigned long last; // $a0
		/* end block 1.1 */
		// End offset: 0x80030558
		// End Line: 2975
	/* end block 1 */
	// End offset: 0x800305B0
	// End Line: 2991

	/* begin block 2 */
		// Start line: 6854
	/* end block 2 */
	// End Line: 6855

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_DoTimeProcess(void)

{
  bool bVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = TIMER_GetTimeMS();
  if ((gameTrackerX.gameFlags & 0x10000000U) == 0) {
    gameTrackerX.totalTime = TIMER_TimeDiff(gameTrackerX.currentTicks);
    uVar3 = GetRCnt(0xf2000000);
    gameTrackerX.currentTicks = uVar3 & 0xffff | gameTimer << 0x10;
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
      uVar3 = (uint)((ulonglong)(gameTrackerX.lastLoopTime << 0xc) * 0x3e0f83e1 >> 0x20);
    }
    else {
      uVar4 = 0x21;
      if ((gameTrackerX.frameRateLock != 1) && (gameTrackerX.frameRateLock == 2)) {
        uVar4 = 0x32;
      }
      uVar3 = uVar4;
      if (gameTrackerX.lastLoopTime != 0xffffffff) {
        uVar3 = uVar2 - gameTrackerX.currentTime;
      }
      bVar1 = uVar3 < uVar4;
      if ((gameTrackerX.frameRateLock == 1) &&
         (bVar1 = uVar3 < uVar4, gameTrackerX.frameRate24fps != 0)) {
        uVar3 = uVar3 - 9;
        bVar1 = uVar3 < uVar4;
      }
      if (((!bVar1) && (gameTrackerX.gameData.asmData.MorphTime == 1000)) &&
         (uVar4 = uVar3, 0x42 < uVar3)) {
        uVar4 = 0x42;
      }
      uVar3 = (uint)((ulonglong)(uVar4 << 0xc) * 0x3e0f83e1 >> 0x20);
      gameTrackerX.lastLoopTime = uVar4;
    }
    gameTrackerX.timeMult = uVar3 >> 3;
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
  gameTrackerX.currentTime = uVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_Process(struct GameTracker *gameTracker /*$s5*/)
 // line 2998, offset 0x800305c8
	/* begin block 1 */
		// Start line: 2999
		// Start offset: 0x800305C8
		// Variables:
	// 		int d; // $s2

		/* begin block 1.1 */
			// Start line: 3041
			// Start offset: 0x80030670
			// Variables:
		// 		int useTime; // $s0

			/* begin block 1.1.1 */
				// Start line: 3044
				// Start offset: 0x80030680
				// Variables:
			// 		struct Level *level; // $v0
			/* end block 1.1.1 */
			// End offset: 0x800306A4
			// End Line: 3049
		/* end block 1.1 */
		// End offset: 0x800306D4
		// End Line: 3054

		/* begin block 1.2 */
			// Start line: 3158
			// Start offset: 0x80030858
			// Variables:
		// 		int i; // $s0

			/* begin block 1.2.1 */
				// Start line: 3165
				// Start offset: 0x80030884
				// Variables:
			// 		struct _SFXMkr *sfxMkr; // $a2
			/* end block 1.2.1 */
			// End offset: 0x800308D8
			// End Line: 3177
		/* end block 1.2 */
		// End offset: 0x80030900
		// End Line: 3179
	/* end block 1 */
	// End offset: 0x80030BD4
	// End Line: 3381

	/* begin block 2 */
		// Start line: 7063
	/* end block 2 */
	// End Line: 7064

	/* begin block 3 */
		// Start line: 7072
	/* end block 3 */
	// End Line: 7073

/* WARNING: This function may have set the stack pointer */

void GAMELOOP_Process(GameTracker *gameTracker)

{
  bool bVar1;
  Level *pLVar2;
  int iVar3;
  uchar **ppuVar4;
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
           (pLVar2 = STREAM_GetLevelWithID((gameTrackerX.playerInstance)->currentStreamUnitID),
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
    if (gameTrackerX.gameMode == 6) {
      DAT_1f800000 = theCamera.core.position._0_4_;
      DAT_1f800004 = theCamera.core._4_4_;
      StackSave = (ulong)&stack0xffffffc0;
      G2Instance_BuildTransformsForList(gameTracker->instanceList->first);
      puVar8 = (undefined *)StackSave;
      DEBUG_Process(gameTracker,*(undefined *)StackSave);
    }
    else {
      if ((gameTrackerX.streamFlags & 0x100000U) == 0) {
        if (gameTrackerX.SwitchToNewStreamUnit == 1) {
          INSTANCE_Post(gameTrackerX.playerInstance,0x4000006,0);
          STREAM_MoveIntoNewStreamUnit();
        }
        if ((VRAM_NeedToUpdateMorph != 0) && (iVar3 = STREAM_IsCdBusy((long *)0x0), iVar3 == 0)) {
          VRAM_UpdateMorphPalettes();
          VRAM_NeedToUpdateMorph = 0;
        }
        if ((gameTracker->gameData).asmData.MorphTime < 1000) {
          MORPH_Continue();
        }
        if ((gameTracker->streamFlags & 0x80000U) != 0) {
          gameTracker->streamFlags = gameTracker->streamFlags & 0xfff7ffff;
          UNDERWORLD_StartProcess();
        }
        EVENT_DoProcess();
        streamUnit = &StreamTracker;
        do {
          if (*(short *)streamUnit->StreamList == 2) {
            if ((*(Level **)streamUnit->StreamList)->PuzzleInstances != (EventPointers *)0x0) {
              if ((gameTrackerX.debugFlags2 & 0x100U) != 0) {
                FONT_Print("Processing unit %s\n");
              }
              EVENT_ProcessEvents((*(Level **)streamUnit->StreamList)->PuzzleInstances,
                                  *(Level **)streamUnit->StreamList);
            }
            EVENT_BSPProcess((_StreamUnit *)streamUnit);
          }
          streamUnit = (STracker *)(streamUnit->StreamList + 1);
        } while ((int)streamUnit < -0x7ff2bf2c);
        EVENT_ResetAllOneTimeVariables();
      }
      iVar3 = 0;
      EVENT_ProcessHints();
      iVar7 = 0;
      streamUnit = &StreamTracker;
      do {
        if ((streamUnit->StreamList[0].used == 2) &&
           (iVar5 = 0, 0 < (streamUnit->StreamList[0].level)->NumberOfSFXMarkers)) {
          iVar6 = 0;
          do {
            ppuVar4 = (uchar **)
                      (*(int *)(*(int *)((int)&StreamTracker.StreamList[0].level + iVar7) + 0xec) +
                      iVar6);
            if ((ppuVar4 != (uchar **)0x0) && (*ppuVar4 != (uchar *)0x0)) {
              SOUND_ProcessInstanceSounds
                        (*ppuVar4,(SoundInstance *)(ppuVar4 + 2),(_Position *)(ppuVar4 + 5),
                         (int)ppuVar4[7],(int)ppuVar4[8],0,0,(long *)0x0);
            }
            iVar5 = iVar5 + 1;
            iVar6 = iVar6 + 0x24;
          } while (iVar5 < (StreamTracker.StreamList[iVar3].level)->NumberOfSFXMarkers);
        }
        iVar7 = iVar7 + 0x40;
        iVar3 = iVar3 + 1;
        streamUnit = (STracker *)(streamUnit->StreamList + 1);
      } while (iVar3 < 0x10);
      if ((gameTrackerX.streamFlags & 0x100000U) == 0) {
        INSTANCE_SpatialRelationships(instanceList);
      }
      INSTANCE_ProcessFunctions(gameTracker->instanceList);
      INSTANCE_CleanUpInstanceList(gameTracker->instanceList,0);
      INSTANCE_DeactivateFarInstances(gameTracker);
      MONAPI_ProcessGenerator();
      DAT_1f800000 = theCamera.core.position._0_4_;
      DAT_1f800004 = theCamera.core._4_4_;
      StackSave = (ulong)&stack0xffffffc0;
      G2Instance_BuildTransformsForList(gameTracker->instanceList->first);
      puVar8 = (undefined *)StackSave;
      if ((gameTrackerX.streamFlags & 0x100000U) == 0) {
        FX_ProcessList(fxTracker);
        puVar8 = (undefined *)StackSave;
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
          if ((gameTrackerX.streamFlags & 0x100000U) == 0) {
            PLANAPI_UpdatePlanningDatabase(gameTracker,gameTrackerX.playerInstance,*puVar8);
          }
        }
      }
      DEBUG_Process(gameTracker,*puVar8);
      COLLIDE_InstanceList(gameTracker->instanceList,*puVar8);
      COLLIDE_InstanceListTerrain(gameTracker->instanceList,*puVar8);
      INSTANCE_AdditionalCollideFunctions(instanceList,*puVar8);
      COLLIDE_InstanceListWithSignals(instanceList,*puVar8);
      if ((gameTrackerX.streamFlags & 0x100000U) == 0) {
        LIGHT_CalcShadowPositions(gameTracker,*puVar8);
        INSTANCE_CleanUpInstanceList(gameTracker->instanceList,0x10,*puVar8);
      }
      CAMERA_Process(&theCamera,*puVar8);
      PIPE3D_CalculateWCTransform(&theCamera,*puVar8);
      *(undefined2 *)&(theCamera.core.wcTransform2)->field_0x12 = 0;
      PIPE3D_InvertTransform(theCamera.core.cwTransform2,theCamera.core.wcTransform2,*puVar8);
      CAMERA_CalcVVClipInfo(&theCamera,*puVar8);
      if (gameTracker->levelChange != 0) {
        gameTracker->levelChange = 0;
      }
      SAVE_IntroduceBufferIntros(*puVar8);
    }
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
 // line 3385, offset 0x80030bfc
	/* begin block 1 */
		// Start line: 7924
	/* end block 1 */
	// End Line: 7925

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ModeStartRunning(void)

{
  if (((gameTrackerX.gameMode == 4) || (gameTrackerX.gameMode == 6)) &&
     (DEBUG_ExitMenus(), gameTrackerX.gameMode == 6)) {
    currentMenu = &standardMenu;
    SOUND_ResumeAllSound();
    VOICEXA_Resume();
  }
  if ((gameTrackerX.gameFlags & 0x8000000U) != 0) {
    gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xf7ffffff;
    gameTrackerX.savedOTStart = (P_TAG *)0x0;
    DrawSync(0);
  }
  gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xefffffff;
  (gameTrackerX.playerInstance)->flags = (gameTrackerX.playerInstance)->flags & 0xfffffeff;
  gameTrackerX.gameMode = 0;
  GAMEPAD_RestoreControllers();
  INSTANCE_Post(gameTrackerX.playerInstance,(int)&DAT_0010000a,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_ModeStartPause()
 // line 3415, offset 0x80030cd4
	/* begin block 1 */
		// Start line: 7987
	/* end block 1 */
	// End Line: 7988

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ModeStartPause(void)

{
  gameTrackerX.gameMode = 6;
  INSTANCE_Post(gameTrackerX.playerInstance,(int)&DAT_0010000a,1);
  currentMenu = &pauseMenu;
  menu_set(gameTrackerX.menu,menudefs_pause_menu);
  SOUND_PauseAllSound();
  VOICEXA_Pause();
  SndPlay(5);
  gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x10000000;
  GAMEPAD_SaveControllers();
  gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x8000000;
  if (gameTrackerX.primPool == primPool2) {
    gameTrackerX.primPool = PTR_800d2fb0;
  }
  else {
    gameTrackerX.primPool = primPool2;
  }
  (gameTrackerX.primPool)->nextPrim = (gameTrackerX.primPool)->prim;
  (gameTrackerX.primPool)->numPrims = 0;
  SaveOT();
  pause_redraw_flag = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_ChangeMode()
 // line 3467, offset 0x80030dac
	/* begin block 1 */
		// Start line: 3468
		// Start offset: 0x80030DAC
		// Variables:
	// 		long *controlCommand; // $s0
	/* end block 1 */
	// End offset: 0x80031148
	// End Line: 3635

	/* begin block 2 */
		// Start line: 6934
	/* end block 2 */
	// End Line: 6935

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ChangeMode(void)

{
  uint uVar1;
  
  if ((gameTrackerX.debugFlags & 0x40000U) == 0) {
    if ((gameTrackerX.debugFlags & 0x200000U) == 0) {
      if ((gameTrackerX.controlCommand[0][0] & 0xa01U) == 0xa01) {
        theCamera.forced_movement = 1;
        ((gameTrackerX.playerInstance)->position).z =
             ((gameTrackerX.playerInstance)->position).z + 100;
        (gameTrackerX.playerInstance)->zVel = 0;
        gameTrackerX.cheatMode = '\x01';
        INSTANCE_Post(gameTrackerX.playerInstance,(int)&DAT_00100010,1);
        (gameTrackerX.playerInstance)->flags = (gameTrackerX.playerInstance)->flags & 0xfffff7ff;
      }
      else {
        if ((gameTrackerX.controlCommand[0][0] & 0xa02U) == 0xa02) {
          theCamera.forced_movement = 1;
          ((gameTrackerX.playerInstance)->position).z =
               ((gameTrackerX.playerInstance)->position).z + -100;
          (gameTrackerX.playerInstance)->zVel = 0;
          gameTrackerX.cheatMode = '\0';
          INSTANCE_Post(gameTrackerX.playerInstance,(int)&DAT_00100010,0);
          gameTrackerX.gameMode = 0;
        }
      }
    }
    if ((gameTrackerX.debugFlags & 0x40000U) != 0) goto LAB_80030e9c;
  }
  else {
LAB_80030e9c:
    if ((gameTrackerX.playerCheatFlags & 2U) == 0) goto LAB_80030fbc;
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
        DEBUG_EndViewVram(&gameTrackerX);
        gameTrackerX.gameMode = 0;
      }
      else {
        GAMELOOP_ModeStartRunning();
      }
    }
  }
LAB_80030fbc:
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
      GAMELOOP_ModeStartRunning();
    }
  }
  else {
    GAMELOOP_ModeStartPause();
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
 // line 3638, offset 0x80031158
	/* begin block 1 */
		// Start line: 8495
	/* end block 1 */
	// End Line: 8496

void GAMELOOP_RequestLevelChange(char *name,short number,GameTracker *gameTracker)

{
  if (gameTracker->levelChange == 0) {
    gameTracker->gameFlags = gameTracker->gameFlags | 1;
    SOUND_ResetAllSound();
    sprintf(gameTracker->baseAreaName,"%s%d");
    gameTracker->levelChange = 1;
    gameTracker->levelDone = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PSX_GameLoop(struct GameTracker *gameTracker /*$s0*/)
 // line 3660, offset 0x800311d8
	/* begin block 1 */
		// Start line: 8539
	/* end block 1 */
	// End Line: 8540

void PSX_GameLoop(GameTracker *gameTracker)

{
  GAMEPAD_Process(gameTracker);
  GAMELOOP_Process(gameTracker);
  return;
}



// decompiled code
// original method signature: 
// struct MATRIX * /*$ra*/ GAMELOOP_GetMatrices(int numMatrices /*$a0*/)
 // line 3670, offset 0x80031204
	/* begin block 1 */
		// Start line: 3672
		// Start offset: 0x80031204
		// Variables:
	// 		struct MATRIX *matrix; // $a1
	// 		struct _PrimPool *pool; // $v1
	/* end block 1 */
	// End offset: 0x80031228
	// End Line: 3689

	/* begin block 2 */
		// Start line: 8559
	/* end block 2 */
	// End Line: 8560

	/* begin block 3 */
		// Start line: 8560
	/* end block 3 */
	// End Line: 8561

	/* begin block 4 */
		// Start line: 8561
	/* end block 4 */
	// End Line: 8562

MATRIX * GAMELOOP_GetMatrices(int numMatrices)

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
 // line 3694, offset 0x80031238
	/* begin block 1 */
		// Start line: 8609
	/* end block 1 */
	// End Line: 8610

	/* begin block 2 */
		// Start line: 8610
	/* end block 2 */
	// End Line: 8611

/* WARNING: Unknown calling convention yet parameter storage is locked */

GameTracker * GAMELOOP_GetGT(void)

{
  return &gameTrackerX;
}





