
#include "GAMELOOP.H"


// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_AllocStaticMemory()
 // line 139, offset 0x8002d6f8
	/* begin block 1 */
		// Start line: 278
	/* end block 1 */
	// End Line: 279

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_AllocStaticMemory(void)

{
  instanceList = MEMPACK_Malloc(0x10c,'\x06');
  instancePool = MEMPACK_Malloc((ulong)&DAT_00009bac,'\x06');
  gOt = MEMPACK_Malloc((ulong)&LAB_00034e18,'\x06');
  DAT_800d1d1c = gOt + 0x3000;
  primPool = gOt + 0x6000;
  DAT_800d1d24 = gOt + 0x1d70c;
  primBase = gOt;
  gLightInfo = MEMPACK_Malloc(0x47c,'\x06');
  memset();
  gPolytopeList = (_PolytopeList *)MEMPACK_Malloc((ulong)&DAT_000018c0,'\x06');
  gVertexPool = (_VertexPool *)gPolytopeList;
  gFXT = MEMPACK_Malloc((ulong)&DAT_000079a8,'\x06');
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_InitGameTracker(void)

{
  int iVar1;
  int iVar2;
  
  DAT_800d2110 = GlobalObjects;
  DAT_800d22e4 = planningPool;
  DAT_800d22e8 = enemyPlanPool;
  DAT_800d2108 = gVertexPool;
  *(int *)(primPool + 8) = primPool + 0x176dc;
  DAT_800d2100 = instanceList;
  *(int *)(DAT_800d1d24 + 8) = DAT_800d1d24 + 0x176dc;
  DAT_800d21e0 = gLightInfo;
  *(int *)(primPool + 4) = primPool + 0xc;
  DAT_800d2104 = instancePool;
  *(int *)(DAT_800d1d24 + 4) = DAT_800d1d24 + 0xc;
  iVar2 = 0;
  iVar1 = 0;
  DAT_800d22f4 = 10;
  DAT_800d22fa = 0x1000;
  DAT_800d22f8 = 0;
  LAB_800d22f0 = 1;
  DAT_800d233c = 1;
  DAT_800d210c = primPool;
  DAT_800d22a4 = gOt;
  DAT_800d22a8 = DAT_800d1d1c;
  DAT_800d2340 = 1;
  do {
    iVar2 = iVar2 + 1;
    *(undefined2 *)((int)&DAT_800d2110->objectStatus + iVar1) = 0;
    iVar1 = iVar1 + 0x24;
  } while (iVar2 < 0x30);
  DAT_800d20d4 = 1000;
  OBTABLE_ClearObjectReferences();
  EVENT_Init();
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

/* File: C:\kain2\game\GAMELOOP.C */

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
 // line 294, offset 0x8002d920
	/* begin block 1 */
		// Start line: 822
	/* end block 1 */
	// End Line: 823

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_ResetGameStates(void)

{
  EVENT_Init();
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_ClearGameTracker(void)

{
  gameTrackerX = 0;
  DAT_800d20d4 = 1000;
  DAT_800d21f8 = 0;
  DAT_800d21fc = 0;
  DAT_800d220c = 0;
  DAT_800d2240 = 0;
  DAT_800d2248 = 0;
  DAT_800d2300 = 0;
  DAT_800d2324 = 0;
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_CalcGameTime(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (uint)(DAT_800d230c * DAT_800d22f4) / 60000 + 0x2d0;
  iVar1 = iVar2 / 0x3c;
  DAT_800d22ee = (short)iVar1 * 0x28 +
                 ((short)(iVar1 / 6 + (iVar1 >> 0x1f) >> 2) - (short)(iVar1 >> 0x1f)) * -0x960 +
                 (short)iVar2;
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_SetGameTime(long timeOfDay)

{
  int iVar1;
  int iVar2;
  
  iVar1 = timeOfDay + (timeOfDay / 100) * -0x28;
  iVar2 = iVar1 + -0x2d0;
  if (iVar2 < 0) {
    iVar2 = iVar1 + 0x2d0;
  }
  DAT_800d2304 = (iVar2 * 60000) / DAT_800d22f4;
  DAT_800d22ee = (short)timeOfDay;
  DAT_800d230c = DAT_800d2304;
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

/* File: C:\kain2\game\GAMELOOP.C */

int GAMELOOP_GetTimeOfDay(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)DAT_800d22ee;
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

/* File: C:\kain2\game\GAMELOOP.C */

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
 // line 808, offset 0x8002db40
	/* begin block 1 */
		// Start line: 1477
	/* end block 1 */
	// End Line: 1478

	/* begin block 2 */
		// Start line: 1885
	/* end block 2 */
	// End Line: 1886

/* File: C:\kain2\game\GAMELOOP.C */

int GAMELOOP_WaitForLoad(void)

{
  int iVar1;
  
  if ((DAT_800d218c & 0x80000) != 0) {
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

/* File: C:\kain2\game\GAMELOOP.C */

_StreamUnit * LoadLevels(char *baseAreaName,GameTracker *gameTracker)

{
  short sVar1;
  int iVar2;
  _StreamUnit *streamUnit;
  int iVar3;
  Level *pLVar4;
  _BSPNode *p_Var5;
  _MultiSignal *p_Var6;
  BSPTree *pBVar7;
  _SVector local_20;
  
  iVar2 = strlen();
  if (iVar2 != 0) {
    STREAM_AbortAreaLoad(&LAB_800cf450);
  }
  strcpy();
  LOAD_ChangeDirectory(baseAreaName);
  streamUnit = STREAM_LoadLevel(gameTracker,baseAreaName,(StreamUnitPortal *)0x0,0);
  if (streamUnit->used == 1) {
    DRAW_LoadingMessage();
    sVar1 = streamUnit->used;
    while (sVar1 == 1) {
      GAMELOOP_WaitForLoad();
      sVar1 = streamUnit->used;
    }
    STREAM_NextLoadFromHead();
    STREAM_LoadMainVram(gameTracker,baseAreaName,streamUnit);
    iVar2 = GAMELOOP_WaitForLoad();
    do {
      iVar3 = GAMELOOP_WaitForLoad();
      if (iVar3 == 0) break;
    } while (iVar2 + -1 <= iVar3);
  }
  else {
    STREAM_LoadMainVram(gameTracker,baseAreaName,streamUnit);
  }
  pLVar4 = streamUnit->level;
  p_Var6 = pLVar4->startUnitMainSignal;
  if (p_Var6 != (_MultiSignal *)0x0) {
    if (gameTracker->playerInstance != (_Instance *)0x0) {
      p_Var6->flags = p_Var6->flags | 1;
      SIGNAL_HandleSignal(gameTracker->playerInstance,
                          streamUnit->level->startUnitMainSignal->signalList,0);
      EVENT_AddSignalToReset(streamUnit->level->startUnitMainSignal);
    }
    pLVar4 = streamUnit->level;
  }
  pBVar7 = pLVar4->terrain->BSPTreeArray;
  p_Var5 = pBVar7->bspRoot;
  local_20.x = -((p_Var5->sphere).position.x + (pBVar7->globalOffset).x);
  local_20.y = -((p_Var5->sphere).position.y + (pBVar7->globalOffset).y);
  local_20.z = -((p_Var5->sphere).position.z + (pBVar7->globalOffset).z);
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_InitStandardObjects(void)

{
  char *name;
  undefined **ppuVar1;
  uint uVar2;
  
  LOAD_DumpCurrentDir();
  uVar2 = 0;
  ppuVar1 = &PTR_s_raziel_800c8e94;
  do {
    name = *ppuVar1;
    ppuVar1 = ppuVar1 + 1;
    uVar2 = uVar2 + 1;
    InsertGlobalObject(name,(GameTracker *)&gameTrackerX);
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_LevelLoadAndInit(char *baseAreaName,GameTracker *gameTracker)

{
  void *pvVar1;
  _InstanceList *list;
  _InstancePool *pool;
  _StreamUnit *p_Var2;
  int iVar3;
  int iVar4;
  _Instance *p_Var5;
  _MultiSignal *p_Var6;
  Level *pLVar7;
  int iVar8;
  
  G2Anim_ResetInternalState();
  pool = instancePool;
  list = instanceList;
  gameTracker->playerInstance = (_Instance *)0x0;
  INSTANCE_InitInstanceList(list,pool);
  GAMELOOP_ClearGameTracker();
  CAMERA_Initialize((Camera *)&theCamera);
  PLANAPI_InitPlanning(planningPool);
  ENMYPLAN_InitEnemyPlanPool(enemyPlanPool);
  FX_Init(fxTracker);
  WARPGATE_Init();
  DRAW_InitShadow();
  GAMELOOP_InitStandardObjects();
  p_Var2 = LoadLevels(baseAreaName,gameTracker);
  do {
    iVar3 = STREAM_PollLoadQueue();
    pvVar1 = objectAccess[2].object;
  } while (iVar3 != 0);
  gameTracker->introFX = objectAccess[6].object;
  pLVar7 = p_Var2->level;
  RENDER_currentStreamUnitID = *(undefined2 *)&gameTracker->StreamUnitID;
  fontsObject = (Object *)pvVar1;
  iVar3 = 0;
  if (0 < pLVar7->numIntros) {
    iVar8 = 0;
    do {
      iVar4 = strcmpi(pLVar7->introList->name + iVar8,s_raziel_800cf4b0);
      if (iVar4 == 0) {
        INSTANCE_IntroduceInstance
                  ((Intro *)(p_Var2->level->introList->name + iVar8),*(short *)&p_Var2->StreamUnitID
                  );
        break;
      }
      pLVar7 = p_Var2->level;
      iVar3 = iVar3 + 1;
      iVar8 = iVar8 + 0x4c;
    } while (iVar3 < pLVar7->numIntros);
  }
  gameTracker->playerInstance->data = gameTracker->playerInstance->object->data;
  CAMERA_SetInstanceFocus((Camera *)&theCamera,gameTracker->playerInstance);
  p_Var5 = gameTracker->playerInstance;
  theCamera = (p_Var5->position).x;
  DAT_800d0f9e = (p_Var5->position).y;
  DAT_800d0fa0 = (p_Var5->position).z;
  SetFogNearFar((uint)p_Var2->level->fogNear,(uint)p_Var2->level->fogFar,0x140);
  SetFarColor(0,0,0);
  clearRect[0].r0 = p_Var2->level->backColorR;
  clearRect[0].g0 = p_Var2->level->backColorG;
  clearRect[0].b0 = p_Var2->level->backColorB;
  clearRect[1].r0 = p_Var2->level->backColorR;
  clearRect[1].g0 = p_Var2->level->backColorG;
  clearRect[1].b0 = p_Var2->level->backColorB;
  LIGHT_InitSources(gLightInfo);
  gameTracker->wipeType = 10;
  gameTracker->hideBG = 0;
  gameTracker->wipeTime = 0x1e;
  gameTracker->maxWipeTime = 0x1e;
  p_Var6 = p_Var2->level->startSignal;
  if (p_Var6 != (_MultiSignal *)0x0) {
    p_Var6->flags = p_Var6->flags | 1;
    SIGNAL_HandleSignal(gameTracker->playerInstance,p_Var2->level->startSignal->signalList,0);
    EVENT_AddSignalToReset(p_Var2->level->startSignal);
  }
  gameTracker->vblFrames = 0;
  p_Var6 = p_Var2->level->startUnitMainSignal;
  if ((p_Var6 != (_MultiSignal *)0x0) && (gameTracker->playerInstance != (_Instance *)0x0)) {
    p_Var6->flags = p_Var6->flags | 1;
    SIGNAL_HandleSignal(gameTracker->playerInstance,p_Var2->level->startUnitMainSignal->signalList,0
                       );
    EVENT_AddSignalToReset(p_Var2->level->startUnitMainSignal);
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_StreamLevelLoadAndInit
               (char *baseAreaName,GameTracker *gameTracker,int toSignalNum,int fromSignalNum)

{
  LoadLevels(baseAreaName,gameTracker);
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_SetScreenWipe(int time,int maxTime,int type)

{
  DAT_800d2198 = (short)time;
  DAT_800d219a = (short)maxTime;
  LAB_800d219c = (short)type;
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_HandleScreenWipes(ulong **drawot)

{
  _PrimPool *primPool;
  int r;
  
  primPool = DAT_800d210c;
  if ((GlobalSave->flags & 1U) != 0) {
    DRAW_FlatQuad((CVECTOR *)&DAT_800d2194,0,0,0x200,0,0,0x1e,0x200,0x1e,DAT_800d210c,drawot);
    DRAW_FlatQuad((CVECTOR *)&DAT_800d2194,0,0xd2,0x200,0xd2,0,0xf0,0x200,0xf0,primPool,drawot);
  }
  r = (int)DAT_800d2198;
  if (r < 1) {
    if (r < -1) {
      if (LAB_800d219c == 10) {
        r = (int)(short)((((int)DAT_800d219a + r + 2) * 0xff) / (int)DAT_800d219a);
        DRAW_TranslucentQuad(0,0,0x200,0,0,0xf0,0x200,0xf0,r,r,r,2,primPool,drawot);
      }
      else {
        if (LAB_800d219c == 0xb) {
          r = (int)(short)((((int)DAT_800d219a + r) * 0xff) / (int)DAT_800d219a);
          DRAW_TranslucentQuad(0,0,0x200,0,0,0x1e,0x200,0x1e,r,r,r,2,primPool,drawot);
          DRAW_TranslucentQuad(0,0xd2,0x200,0xd2,0,0xf0,0x200,0xf0,r,r,r,2,primPool,drawot);
          if (DAT_800d2198 == -2) {
            GlobalSave->flags = GlobalSave->flags | 1;
          }
        }
      }
      if (DAT_800d2334 != 0) {
        DAT_800d2198 = DAT_800d2198 + 1;
      }
    }
    else {
      if (r == -1) {
        if (LAB_800d219c == 0xb) {
          GlobalSave->flags = GlobalSave->flags | 1;
        }
        else {
          DRAW_FlatQuad((CVECTOR *)&DAT_800d2194,0,0,0x200,0,0,0xf0,0x200,0xf0,primPool,drawot);
        }
      }
      else {
        DAT_800d105a = 0x1000;
        DAT_800d1058 = 0x1000;
        DAT_800d1056 = 0x1000;
      }
    }
  }
  else {
    if (LAB_800d219c == 10) {
      r = (int)(short)((r * 0xff) / (int)DAT_800d219a);
      DRAW_TranslucentQuad(0,0,0x200,0,0,0xf0,0x200,0xf0,r,r,r,2,primPool,drawot);
    }
    else {
      if (LAB_800d219c == 0xb) {
        r = (int)(short)((r * 0xff) / (int)DAT_800d219a);
        DRAW_TranslucentQuad(0,0,0x200,0,0,0x1e,0x200,0x1e,r,r,r,2,primPool,drawot);
        DRAW_TranslucentQuad(0,0xd2,0x200,0xd2,0,0xf0,0x200,0xf0,r,r,r,2,primPool,drawot);
        GlobalSave->flags = GlobalSave->flags & 0xfffe;
      }
    }
    if (DAT_800d2334 != 0) {
      DAT_800d2198 = DAT_800d2198 + -1;
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

/* File: C:\kain2\game\GAMELOOP.C */

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
  uVar6 = (uint)level->fogFar;
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

/* File: C:\kain2\game\GAMELOOP.C */

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

/* File: C:\kain2\game\GAMELOOP.C */

void BlendToColor(_ColorType *target,_ColorType *current,_ColorType *dest)

{
  int iVar1;
  
  LoadAverageCol((u_char *)target,(u_char *)current,0x200,0xe00,(u_char *)dest);
  iVar1 = (uint)target->r - (uint)dest->r;
  if (iVar1 < 0) {
    if (4 < (int)((uint)dest->r - (uint)target->r)) goto LAB_8002e7dc;
  }
  else {
    if (4 < iVar1) {
      dest->code = '\0';
      return;
    }
  }
  iVar1 = (uint)target->g - (uint)dest->g;
  if (iVar1 < 0) {
    if (4 < (int)((uint)dest->g - (uint)target->g)) goto LAB_8002e7dc;
  }
  else {
    if (4 < iVar1) {
      dest->code = '\0';
      return;
    }
  }
  iVar1 = (uint)target->b - (uint)dest->b;
  if (iVar1 < 0) {
    if (4 < (int)((uint)dest->b - (uint)target->b)) goto LAB_8002e7dc;
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
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* File: C:\kain2\game\GAMELOOP.C */

void MainRenderLevel(_StreamUnit *currentUnit,ulong **drawot)

{
  undefined4 *puVar1;
  LightInfo *lightInfo;
  undefined4 uVar2;
  ulong *puVar3;
  int p0;
  short sVar4;
  Level *level;
  int **ppiVar5;
  undefined4 uVar6;
  int iVar7;
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
  SVECTOR local_38;
  _ColorType local_30 [2];
  
  level = currentUnit->level;
  terrain = level->terrain;
  UpdateFogSettings(currentUnit,level);
  currentUnit->FrameCount = DAT_800d21f4;
  SetFogNearFar((uint)level->fogNear,(uint)level->fogFar,0x140);
  SetFarColor(0,0,0);
  clearRect[0].r0 = level->backColorR;
  clearRect[0].g0 = level->backColorG;
  clearRect[0].b0 = level->backColorB;
  clearRect[1].r0 = level->backColorR;
  clearRect[1].g0 = level->backColorG;
  clearRect[1].b0 = level->backColorB;
  if ((int)DAT_800d20d4 == 1000) {
    if (DAT_800d20d6 == 1) {
      local_30[0] = *(_ColorType *)&level->specturalColorR;
    }
    else {
      local_30[0] = *(_ColorType *)&level->backColorR;
    }
  }
  else {
    p0 = ((int)DAT_800d20d4 << 0xc) / 1000;
    if (DAT_800d20d6 == 1) {
      p0 = 0x1000 - p0;
    }
    LoadAverageCol(&level->specturalColorR,&level->backColorR,p0,0x1000 - p0,(u_char *)local_30);
  }
  BlendToColor(local_30,(_ColorType *)&currentUnit->FogColor,(_ColorType *)&currentUnit->FogColor);
  depthQBackColor = currentUnit->FogColor;
  p0 = GAMELOOP_GetTimeOfDay();
  if ((((p0 != 600) && (p0 != 0x708)) || ((level->unitFlags & 2U) == 0)) && (DAT_800d20d4 == 1000))
  {
    depthQBackColor = depthQBackColor & 0xfff8f8f8 | 0x40404;
  }
  depthQFogStart = (uint)level->fogNear;
  depthQFogFar = (uint)level->fogFar;
  p0 = CheckForNoBlend((_ColorType *)&depthQBackColor);
  depthQBlendStart = 0xffff;
  if (p0 == 0) {
    depthQBlendStart = depthQFogStart;
  }
  clearRect[0].r0 = (uchar)depthQBackColor;
  clearRect[0].g0 = depthQBackColor._1_1_;
  clearRect[0].b0 = depthQBackColor._2_1_;
  clearRect[1].r0 = (uchar)depthQBackColor;
  clearRect[1].g0 = depthQBackColor._1_1_;
  clearRect[1].b0 = depthQBackColor._2_1_;
  PIPE3D_AnimateTerrainTextures(terrain->aniList,DAT_800d21f8,DAT_800d210c,drawot);
  PIPE3D_AnimateTerrainTextures(level->bgAniList,DAT_800d21f8,DAT_800d210c,drawot);
  p0 = 0;
  LIGHT_Restore(gLightInfo);
  lightInfo = gLightInfo;
  gLightInfo->numSavedColors = 0;
  LIGHT_ClassifySources((_CameraCore_Type *)&theCamera,level,lightInfo);
  LIGHT_SourcesAndInstances(gLightInfo,DAT_800d2100);
  LIGHT_SourcesAndTerrain(gLightInfo,terrain);
  PIPE3D_InstanceListTransformAndDraw
            (currentUnit,(GameTracker *)&gameTrackerX,drawot,(_CameraCore_Type *)&theCamera);
  local_60 = _theCamera;
  local_5c = DAT_800d0fa0;
  local_58 = *DAT_800d0ffc;
  local_54 = DAT_800d0ffc[1];
  local_50 = DAT_800d0ffc[2];
  local_4c = DAT_800d0ffc[3];
  local_48 = DAT_800d0ffc[4];
  local_44 = DAT_800d0ffc[5];
  local_40 = DAT_800d0ffc[6];
  local_3c = DAT_800d0ffc[7];
  iVar7 = 0;
  if (0 < terrain->numBSPTrees) {
    do {
      uVar2 = DAT_800d20d8;
      ppiVar5 = (int **)((int)&terrain->BSPTreeArray->bspRoot + iVar7);
      if ((-1 < *(short *)((int)ppiVar5 + 0x1a)) && ((*(ushort *)((int)ppiVar5 + 0x12) & 1) == 0)) {
        uVar6 = 0;
        if ((*(ushort *)((int)ppiVar5 + 0x12) & 0x40) != 0) {
          DAT_800d20d8 = 0;
          uVar6 = uVar2;
        }
        sVar4 = (short)local_60 - *(short *)(ppiVar5 + 3);
        local_38.vx = -sVar4;
        local_38.vy = local_60._2_2_ - *(short *)((int)ppiVar5 + 0xe);
        _theCamera = CONCAT22(local_38.vy,sVar4);
        local_38.vy = -local_38.vy;
        DAT_800d0fa0 = local_5c - *(short *)(ppiVar5 + 4);
        local_38.vz = -DAT_800d0fa0;
        ApplyMatrix((MATRIX *)&local_58,&local_38,(VECTOR *)(DAT_800d0ffc + 5));
        BSP_MarkVisibleLeaves_S(ppiVar5,(undefined4 *)&theCamera,(int *)gPolytopeList);
        local_64 = ppiVar5 + 3;
        puVar3 = (ulong *)(*DAT_800d221c)(gPolytopeList,terrain,&theCamera,DAT_800d210c);
        DAT_800d210c->nextPrim = puVar3;
        if ((*(ushort *)((int)ppiVar5 + 0x12) & 0x40) != 0) {
          DAT_800d20d8 = uVar6;
        }
      }
      p0 = p0 + 1;
      iVar7 = iVar7 + 0x24;
    } while (p0 < terrain->numBSPTrees);
  }
  lightInfo = gLightInfo;
  puVar1 = DAT_800d0ffc;
  p0 = (int)RENDER_currentStreamUnitID;
  _theCamera = local_60;
  DAT_800d0fa0 = local_5c;
  *DAT_800d0ffc = local_58;
  puVar1[1] = local_54;
  puVar1[2] = local_50;
  puVar1[3] = local_4c;
  puVar1[4] = local_48;
  puVar1[5] = local_44;
  puVar1[6] = local_40;
  puVar1[7] = local_3c;
  SBSP_IntroduceInstancesAndLights(terrain,(_CameraCore_Type *)&theCamera,lightInfo,p0);
  StackSave = (ulong)&stack0xffffff88;
  FX_DrawList(fxTracker,(GameTracker *)&gameTrackerX,DAT_800d22a4,(char)DAT_800d0ffc);
  if (*(int *)(DAT_800d20f8 + 0x38) == currentUnit->StreamUnitID) {
    FX_DrawReaver(DAT_800d210c,DAT_800d22a4,(char)DAT_800d0ffc);
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

/* File: C:\kain2\game\GAMELOOP.C */

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
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* File: C:\kain2\game\GAMELOOP.C */

long StreamRenderLevel(_StreamUnit *currentUnit,Level *mainLevel,ulong **drawot,long portalFogColor)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  LightInfo *lightInfo;
  int unitID;
  ulong *puVar3;
  short sVar4;
  int **ppiVar5;
  Level *level;
  _Terrain *terrain;
  int iVar6;
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
  SVECTOR local_30;
  
  uVar2 = DAT_800d1000;
  level = currentUnit->level;
  terrain = level->terrain;
  SetFarColor(0,0,0);
  UpdateFogSettings(currentUnit,level);
  depthQFogFar = (uint)level->fogFar;
  depthQFogStart = (uint)level->fogNear;
  depthQBackColor = portalFogColor;
  currentUnit->FogColor = portalFogColor;
  DAT_800d1000 = depthQFogFar;
  unitID = CheckForNoBlend((_ColorType *)&depthQBackColor);
  depthQBlendStart = 0xffff;
  if (unitID == 0) {
    depthQBlendStart = depthQFogStart;
  }
  SetFogNearFar(depthQFogStart,depthQFogFar,0x140);
  PIPE3D_AnimateTerrainTextures(terrain->aniList,DAT_800d21f8,DAT_800d210c,drawot);
  PIPE3D_AnimateTerrainTextures(level->bgAniList,DAT_800d21f8,DAT_800d210c,drawot);
  LIGHT_ClassifySources((_CameraCore_Type *)&theCamera,level,gLightInfo);
  LIGHT_SourcesAndTerrain(gLightInfo,terrain);
  PIPE3D_InstanceListTransformAndDraw
            (currentUnit,(GameTracker *)&gameTrackerX,drawot,(_CameraCore_Type *)&theCamera);
  local_58 = _theCamera;
  local_54 = DAT_800d0fa0;
  local_50 = *DAT_800d0ffc;
  local_4c = DAT_800d0ffc[1];
  local_48 = DAT_800d0ffc[2];
  local_44 = DAT_800d0ffc[3];
  local_40 = DAT_800d0ffc[4];
  local_3c = DAT_800d0ffc[5];
  local_38 = DAT_800d0ffc[6];
  local_34 = DAT_800d0ffc[7];
  unitID = 0;
  if (0 < terrain->numBSPTrees) {
    iVar6 = 0;
    do {
      ppiVar5 = (int **)((int)&terrain->BSPTreeArray->bspRoot + iVar6);
      if ((-1 < *(short *)((int)ppiVar5 + 0x1a)) && ((*(ushort *)((int)ppiVar5 + 0x12) & 1) == 0)) {
        sVar4 = (short)local_58 - *(short *)(ppiVar5 + 3);
        local_30.vx = -sVar4;
        local_30.vy = local_58._2_2_ - *(short *)((int)ppiVar5 + 0xe);
        _theCamera = CONCAT22(local_30.vy,sVar4);
        local_30.vy = -local_30.vy;
        DAT_800d0fa0 = local_54 - *(short *)(ppiVar5 + 4);
        local_30.vz = -DAT_800d0fa0;
        ApplyMatrix((MATRIX *)&local_50,&local_30,(VECTOR *)(DAT_800d0ffc + 5));
        BSP_MarkVisibleLeaves_S(ppiVar5,(undefined4 *)&theCamera,(int *)gPolytopeList);
        local_5c = ppiVar5 + 3;
        local_60 = drawot;
        puVar3 = (ulong *)(*DAT_800d221c)(gPolytopeList,terrain,&theCamera,DAT_800d210c);
        DAT_800d210c->nextPrim = puVar3;
      }
      unitID = unitID + 1;
      iVar6 = iVar6 + 0x24;
    } while (unitID < terrain->numBSPTrees);
  }
  lightInfo = gLightInfo;
  puVar1 = DAT_800d0ffc;
  unitID = (int)RENDER_currentStreamUnitID;
  _theCamera = local_58;
  DAT_800d0fa0 = local_54;
  InStreamUnit = 1;
  *DAT_800d0ffc = local_50;
  puVar1[1] = local_4c;
  puVar1[2] = local_48;
  puVar1[3] = local_44;
  puVar1[4] = local_40;
  puVar1[5] = local_3c;
  puVar1[6] = local_38;
  puVar1[7] = local_34;
  SBSP_IntroduceInstancesAndLights(terrain,(_CameraCore_Type *)&theCamera,lightInfo,unitID);
  InStreamUnit = 0;
  DAT_800d1000 = uVar2;
  if (*(int *)(DAT_800d20f8 + 0x38) == currentUnit->StreamUnitID) {
    hackOT = drawot;
    StackSave = (ulong)auStack112;
    FX_DrawReaver(DAT_800d210c,drawot,(char)DAT_800d0ffc);
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_FlipScreenAndDraw(GameTracker *gameTracker,ulong **drawot)

{
  int iVar1;
  uint uVar2;
  
  DrawOTag((u_long *)(drawot + 0xbff));
  do {
    iVar1 = CheckVolatile(gameTracker->drawTimerReturn);
  } while (iVar1 != 0);
  ResetPrimPool();
  PutDrawEnv(draw + gameTracker->drawPage);
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_AddClearPrim(ulong **drawot)

{
  ulong *puVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  if ((DAT_800d220c & 0x8000000) == 0) {
    puVar1 = *(ulong **)(DAT_800d210c + 4);
    uVar2 = *(ulong *)&clearRect[DAT_800d20fc].r0;
    uVar3 = *(ulong *)&clearRect[DAT_800d20fc].x0;
    uVar4 = *(ulong *)&clearRect[DAT_800d20fc].w;
    *puVar1 = clearRect[DAT_800d20fc].tag;
    puVar1[1] = uVar2;
    puVar1[2] = uVar3;
    puVar1[3] = uVar4;
    *(ulong **)(DAT_800d210c + 4) = puVar1 + 4;
    *puVar1 = (uint)drawot[0xbff] & 0xffffff | 0x3000000;
    drawot[0xbff] = (ulong *)((uint)puVar1 & 0xffffff);
    return;
  }
  *(ushort *)(DAT_800d22ac + 10) = clearRect[DAT_800d20fc].y0;
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_SwitchTheDrawBuffer(ulong **drawot)

{
  GAMELOOP_AddClearPrim(drawot);
  DrawSync(0);
  if (DAT_800d21e8 != 0) {
    DAT_800d21e8 = 0;
    DAT_800d21e4 = DAT_800d21f0 + DAT_800d20d0 * 0x14;
  }
  PutDrawEnv(draw + DAT_800d20fc);
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

/* File: C:\kain2\game\GAMELOOP.C */

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

/* File: C:\kain2\game\GAMELOOP.C */

_StreamUnit * GAMELOOP_GetMainRenderUnit(void)

{
  int iVar1;
  _StreamUnit *p_Var2;
  _StreamUnit *p_Var3;
  
  iVar1 = DAT_800d10a4;
  if (DAT_800d108c == 5) {
    p_Var2 = STREAM_WhichUnitPointerIsIn(DAT_800d13c0);
  }
  else {
    if ((DAT_800d10a4 == DAT_800d20f8) && (DAT_800d2248 != 0)) {
      p_Var2 = STREAM_GetStreamUnitWithID(DAT_800d226c);
      if (p_Var2 == (_StreamUnit *)0x0) {
        p_Var2 = STREAM_GetStreamUnitWithID(*(long *)(iVar1 + 0x38));
        return p_Var2;
      }
    }
    else {
      p_Var2 = STREAM_GetStreamUnitWithID(*(long *)(DAT_800d10a4 + 0x38));
    }
    p_Var3 = COLLIDE_CameraWithStreamSignals((Camera *)&theCamera);
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

/* WARNING: Removing unreachable block (ram,0x8002f6a8) */
/* WARNING: Removing unreachable block (ram,0x8002f6d8) */
/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_DisplayFrame(GameTracker *gameTracker)

{
  bool bVar1;
  _StreamUnit *currentUnit;
  long lVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  ulong **ot;
  Level *address;
  int iVar7;
  StreamUnitPortal *portal;
  int iVar8;
  _StreamUnit *currentUnit_00;
  int iVar9;
  ushort *puVar10;
  int iVar11;
  StreamUnitPortal *curStreamPortal;
  
  ot = gameTracker->drawOT;
  if ((DAT_800d220c & 0x8000000) == 0) {
    DAT_800d2330 = 0;
    DAT_800d21f4 = DAT_800d21f4 + 1;
    GAMELOOP_SetupRenderFunction((GameTracker *)&gameTrackerX);
    if (((GlobalSave->flags & 1U) == 0) &&
       (((gameTracker->wipeType != 0xb || (gameTracker->wipeTime == 0)) &&
        ((gameTracker->debugFlags2 & 0x800U) != 0)))) {
      FX_Spiral(DAT_800d210c,ot);
    }
    HUD_Draw();
    currentUnit = GAMELOOP_GetMainRenderUnit();
    address = currentUnit->level;
    if ((gameTracker->debugFlags & 4U) != 0) {
      FONT_Print(s_Cameraunit___s_800cf4b8);
    }
    RENDER_currentStreamUnitID = *(undefined2 *)&currentUnit->StreamUnitID;
    DAT_800d1040 = 0x140;
    DAT_800d103c = 0;
    DAT_800d1044 = 0;
    DAT_800d1048 = 0xf0;
    CAMERA_SetViewVolume((Camera *)&theCamera);
    lVar2 = MEMPACK_MemoryValidFunc((char *)address);
    if (lVar2 != 0) {
      if ((uint)address->fogFar != DAT_800d1000) {
        DAT_800d1000 = (uint)address->fogFar;
      }
      if ((gameTracker->debugFlags & 0x8000U) == 0) {
        MainRenderLevel(currentUnit,ot);
      }
    }
    piVar3 = (int *)address->terrain->StreamUnits;
    iVar9 = 0;
    iVar7 = *piVar3;
    curStreamPortal = (StreamUnitPortal *)(piVar3 + 1);
    if (0 < iVar7) {
      puVar10 = (ushort *)((int)piVar3 + 0x22);
      do {
        currentUnit_00 = *(_StreamUnit **)(puVar10 + 5);
        iVar11 = *(int *)(puVar10 + -5);
        if ((currentUnit_00 == (_StreamUnit *)0x0) || (currentUnit_00->FrameCount != DAT_800d21f4))
        {
          DAT_800d1040 = 0x140;
          DAT_800d103c = 0;
          DAT_800d1044 = 0;
          DAT_800d1048 = 0xf0;
          CAMERA_SetViewVolume((Camera *)&theCamera);
          iVar8 = 0;
          bVar1 = false;
          portal = (StreamUnitPortal *)((int)address->terrain->StreamUnits + 4);
          if (0 < iVar7) {
            do {
              if ((portal->streamID == iVar11) &&
                 (iVar4 = STREAM_GetClipRect(portal,0xc0), iVar4 != 0)) {
                bVar1 = true;
              }
              iVar8 = iVar8 + 1;
              portal = portal + 1;
            } while (iVar8 < iVar7);
          }
          if (bVar1) {
            DAT_800d1044 = 0xf0;
            DAT_800d103c = 0x140;
            DAT_800d1040 = 0;
            DAT_800d1048 = 0;
            CAMERA_SetViewVolume((Camera *)&theCamera);
            SetRotMatrix(DAT_800d0ffc);
            SetTransMatrix(DAT_800d0ffc);
            if ((*puVar10 & 1) == 0) {
              if ((currentUnit_00 != (_StreamUnit *)0x0) &&
                 (currentUnit_00->FrameCount != DAT_800d21f4)) {
                currentUnit_00->FrameCount = DAT_800d21f4;
                STREAM_RenderAdjacantUnit(ot,curStreamPortal,currentUnit_00,currentUnit,0xc0);
              }
            }
            else {
              if ((currentUnit->flags & 8U) == 0) {
                WARPGATE_IsItActive(currentUnit);
              }
              else {
                if (currentUnit_00 != (_StreamUnit *)0x0) {
                  if (currentUnit_00->FrameCount == DAT_800d21f4) goto LAB_8002f7f8;
                  currentUnit_00->FrameCount = DAT_800d21f4;
                }
                STREAM_RenderWarpGate(ot,curStreamPortal,currentUnit,0xc0);
              }
            }
          }
          else {
            if ((currentUnit_00 != (_StreamUnit *)0x0) &&
               (currentUnit_00->FrameCount != DAT_800d21f4)) {
              currentUnit_00->FrameCount = DAT_800d21f4;
              StreamIntroInstancesForUnit(currentUnit_00);
            }
          }
        }
LAB_8002f7f8:
        iVar9 = iVar9 + 1;
        puVar10 = puVar10 + 0x2e;
        curStreamPortal = curStreamPortal + 1;
      } while (iVar9 < iVar7);
    }
    iVar7 = 0;
    currentUnit = (_StreamUnit *)&StreamTracker;
    do {
      if ((currentUnit->used == 2) && (currentUnit->FrameCount != DAT_800d21f4)) {
        currentUnit->FrameCount = DAT_800d21f4;
        StreamIntroInstancesForUnit(currentUnit);
      }
      iVar7 = iVar7 + 1;
      currentUnit = currentUnit + 1;
    } while (iVar7 < 0x10);
    DAT_800d1040 = 0x140;
    DAT_800d103c = 0;
    DAT_800d1044 = 0;
    DAT_800d1048 = 0xf0;
    CAMERA_SetViewVolume((Camera *)&theCamera);
  }
  else {
    HUD_Draw();
  }
  DEBUG_Draw(gameTracker,ot);
  FONT_Flush();
  GAMELOOP_SwitchTheDrawBuffer(ot);
  uVar5 = GetRCnt(0xf2000000);
  gameTracker->idleTime = uVar5 & 0xffff | gameTimer << 0x10;
  if ((uint)gameTracker->frameRateLock < gameTracker->vblFrames) {
    if ((DISPENV *)gameTracker->reqDisp != (DISPENV *)0x0) {
      PutDispEnv((DISPENV *)gameTracker->reqDisp);
      gameTracker->reqDisp = (void *)0x0;
      gameTracker->vblFrames = 0;
    }
  }
  else {
    do {
      iVar7 = CheckVolatile(gameTracker->reqDisp);
    } while (iVar7 != 0);
  }
  uVar6 = TIMER_TimeDiff(gameTracker->idleTime);
  iVar7 = (gameTracker->gameData).asmData.dispPage;
  gameTracker->idleTime = uVar6;
  (gameTracker->gameData).asmData.dispPage = 1 - iVar7;
  DEBUG_DrawShrinkCels(ot + 0xbff);
  GAMELOOP_HandleScreenWipes(ot);
  uVar5 = GetRCnt(0xf2000000);
  *(ulong **)&gameTracker->drawTimerReturn = &gameTracker->drawTime;
  gameTracker->usecsStartDraw = uVar5 & 0xffff | gameTimer << 0x10;
  if ((DAT_800d220c & 0x8000000) == 0) {
    DrawOTag((u_long *)(ot + 0xbff));
  }
  else {
    GAMELOOP_DrawSavedOT(ot);
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_DrawSavedOT(ulong **newOT)

{
  short sVar1;
  ushort uVar2;
  u_long uVar3;
  byte bVar4;
  u_long uVar5;
  u_long *puVar6;
  
  sVar1 = draw[DAT_800d20fc].ofs[1];
  puVar6 = DAT_800d22ac;
  if (DAT_800d22ac != LAB_800d22b0) {
    do {
      bVar4 = *(byte *)((int)puVar6 + 7) & 0xfc;
      if (bVar4 == 0x34) {
        uVar2 = *(ushort *)((int)puVar6 + 0x1a);
        if ((uVar2 & 0xf) < 8) {
          if (sVar1 == 0) {
            *(ushort *)((int)puVar6 + 0x1a) = uVar2 & 0xffef;
          }
          else {
            *(ushort *)((int)puVar6 + 0x1a) = uVar2 | 0x10;
          }
        }
      }
      else {
        if (bVar4 == 0x24) {
          uVar2 = *(ushort *)((int)puVar6 + 0x16);
          if ((uVar2 & 0xf) < 8) {
            if (sVar1 == 0) {
              *(ushort *)((int)puVar6 + 0x16) = uVar2 & 0xffef;
            }
            else {
              *(ushort *)((int)puVar6 + 0x16) = uVar2 | 0x10;
            }
          }
        }
        else {
          if (*(byte *)((int)puVar6 + 7) == 0xe3) {
            if (sVar1 == 0) {
              uVar3 = puVar6[1] & 0xfffbffff;
              uVar5 = puVar6[2] & 0xfffbffff;
            }
            else {
              uVar3 = puVar6[1] | 0x40000;
              uVar5 = puVar6[2] | 0x40000;
            }
            puVar6[1] = uVar3;
            puVar6[2] = uVar5;
          }
        }
      }
      puVar6 = (u_long *)(*puVar6 & 0xffffff | 0x80000000);
    } while (puVar6 != LAB_800d22b0);
  }
  *LAB_800d22b0 = *LAB_800d22b0 & 0xff000000 | (uint)(newOT + 0xbff) & 0xffffff;
  DrawOTag(DAT_800d22ac);
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

/* File: C:\kain2\game\GAMELOOP.C */

void ResetPrimPool(void)

{
  undefined **ppuVar1;
  
  ResetDrawPage();
  if ((DAT_800d220c & 0x8000000) == 0) {
    if (DAT_800d210c == primPool) {
      DAT_800d210c = DAT_800d1d24;
    }
    else {
      DAT_800d210c = primPool;
    }
    *(undefined4 **)(DAT_800d210c + 1) = DAT_800d210c + 3;
  }
  else {
    if (DAT_800d20fc == 0) {
      ppuVar1 = (undefined **)&DAT_00008cac;
    }
    else {
      ppuVar1 = &PTR_000101dc;
    }
    DAT_800d210c[1] = (int)DAT_800d210c + (int)ppuVar1;
  }
  *DAT_800d210c = 0;
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

/* File: C:\kain2\game\GAMELOOP.C */

void SaveOT(void)

{
  char cVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  
  DrawSync(0);
  puVar5 = (uint *)(&DAT_00002ffc + DAT_800d22a4);
  cVar1 = (&DAT_00002fff)[DAT_800d22a4];
  puVar7 = (uint *)0x0;
  while (cVar1 == '\0') {
    uVar4 = *puVar5;
    puVar5 = (uint *)(uVar4 & 0xffffff | 0x80000000);
    if ((uVar4 & 0xffffff) == 0xffffff) goto LAB_8002fcc0;
    cVar1 = *(char *)((int)puVar5 + 3);
  }
  if ((*puVar5 & 0xffffff) == 0xffffff) {
LAB_8002fcc0:
    DAT_800d22ac = (uint *)0x0;
  }
  else {
    puVar2 = puVar5;
    puVar3 = (uint *)0x0;
    DAT_800d22ac = puVar5;
    if ((*puVar5 & 0xffffff) != 0xffffff) {
      do {
        while (puVar6 = puVar3, puVar5 = puVar2, *(char *)((int)puVar5 + 3) != '\0') {
          if ((*puVar5 & 0xffffff) == 0xffffff) goto LAB_8002fdac;
          puVar2 = (uint *)(*puVar5 & 0xffffff | 0x80000000);
          puVar3 = puVar5;
          puVar7 = puVar6;
        }
        if ((*puVar5 & 0xffffff) == 0xffffff) goto LAB_8002fdac;
        cVar1 = *(char *)((int)puVar5 + 3);
        while ((cVar1 == '\0' && ((*puVar5 & 0xffffff) != 0xffffff))) {
          puVar5 = (uint *)(*puVar5 & 0xffffff | 0x80000000);
          cVar1 = *(char *)((int)puVar5 + 3);
        }
        *puVar6 = *puVar6 & 0xff000000 | (uint)puVar5 & 0xffffff;
        puVar2 = puVar5;
        puVar3 = puVar6;
      } while ((*puVar5 & 0xffffff) != 0xffffff);
      if ((*puVar5 & 0xffffff) != 0xffffff) {
        LAB_800d22b0 = puVar5;
        return;
      }
    }
LAB_8002fdac:
    LAB_800d22b0 = puVar5;
    if (puVar7 != (uint *)0x0) {
      LAB_800d22b0 = puVar7;
      *puVar7 = *puVar7 | 0xffffff;
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

/* File: C:\kain2\game\GAMELOOP.C */

void ResetDrawPage(void)

{
  u_long *ot;
  
  ot = DAT_800d22a8;
  DAT_800d22a8 = DAT_800d22a4;
  DAT_800d20fc = 1 - DAT_800d20fc;
  DAT_800d22a4 = ot;
  ClearOTagR(ot,0xc00);
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_Set24FPS(void)

{
  DAT_800d2340 = 1;
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_Reset24FPS(void)

{
  DAT_800d2340 = 0;
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_DoTimeProcess(void)

{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = TIMER_GetTimeMS();
  if ((DAT_800d220c & 0x10000000) == 0) {
    DAT_800d2328 = TIMER_TimeDiff(DAT_800d2324);
    uVar2 = GetRCnt(0xf2000000);
    DAT_800d2324 = uVar2 & 0xffff | gameTimer << 0x10;
    if (DAT_800d233c < 1) {
      DAT_800d233c = 1;
    }
    if (2 < DAT_800d233c) {
      DAT_800d233c = 2;
    }
    if ((LAB_800d22f0 == 0) || ((DAT_800d220c & 0x10000000) != 0)) {
      if (DAT_800d233c == 1) {
        DAT_800d2310 = 0x21;
      }
      else {
        if (DAT_800d233c == 2) {
          DAT_800d2310 = 0x32;
        }
      }
      DAT_800d2314 = (uint)((ulonglong)(DAT_800d2310 << 0xc) * 0x3e0f83e1 >> 0x20);
    }
    else {
      uVar2 = 0x21;
      if ((DAT_800d233c != 1) && (DAT_800d233c == 2)) {
        uVar2 = 0x32;
      }
      uVar3 = uVar2;
      if (DAT_800d2310 != 0xffffffff) {
        uVar3 = uVar1 - DAT_800d2300;
      }
      if (((DAT_800d233c == 1) && (DAT_800d2340 != 0)) && (uVar3 = uVar3 - 9, DAT_800d20d4 != 1000))
      {
        uVar3 = 0x21;
      }
      if ((uVar2 <= uVar3) && (uVar2 = uVar3, 0x42 < uVar3)) {
        uVar2 = 0x42;
      }
      DAT_800d2314 = (uint)((ulonglong)(uVar2 << 0xc) * 0x3e0f83e1 >> 0x20);
      DAT_800d2310 = uVar2;
    }
    DAT_800d2314 = DAT_800d2314 >> 3;
    DAT_800d2334 = 0;
    DAT_800d2338 = DAT_800d2338 + DAT_800d2314;
    while (DAT_800d2318 = DAT_800d2314, 0x1000 < DAT_800d2338) {
      DAT_800d2334 = 1;
      DAT_800d2338 = DAT_800d2338 - 0x1000;
      DAT_800d21fc = DAT_800d21fc + 1;
    }
  }
  else {
    DAT_800d2310 = 0xffffffff;
  }
  DAT_800d2300 = uVar1;
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
/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_Process(GameTracker *gameTracker)

{
  bool bVar1;
  Level *pLVar2;
  int iVar3;
  uchar **ppuVar4;
  _StreamUnit *streamUnit;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined *puVar9;
  
  if (gEndGameNow == 0) {
    GAMELOOP_DoTimeProcess();
    if ((DAT_800d223e != 6) && ((DAT_800d2210 & 0x100000) == 0)) {
      MORPH_UpdateTimeMult();
      GAMELOOP_CalcGameTime();
      if ((gameTracker->gameData).asmData.MorphType == 0) {
        bVar1 = true;
        if ((DAT_800d20f8 != (_Instance *)0x0) &&
           (pLVar2 = STREAM_GetLevelWithID(DAT_800d20f8->currentStreamUnitID),
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
    memset();
    if (DAT_800d223e != 6) {
      if ((DAT_800d2210 & 0x100000) == 0) {
        if (DAT_800d2248 == 1) {
          INSTANCE_Post(DAT_800d20f8,0x4000006,0);
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
      }
      if (DAT_800d223e != 6) {
        if ((DAT_800d2210 & 0x100000) == 0) {
          EVENT_DoProcess();
          streamUnit = (_StreamUnit *)&StreamTracker;
          do {
            if (streamUnit->used == 2) {
              if (streamUnit->level->PuzzleInstances != (EventPointers *)0x0) {
                if ((DAT_800d2190 & 0x100) != 0) {
                  FONT_Print(s_Processing_unit__s_800cf4c8);
                }
                EVENT_ProcessEvents(streamUnit->level->PuzzleInstances,streamUnit->level);
              }
              EVENT_BSPProcess(streamUnit);
            }
            streamUnit = streamUnit + 1;
          } while ((int)streamUnit < -0x7ff2d1f4);
          EVENT_ResetAllOneTimeVariables();
        }
        if (DAT_800d223e != 6) {
          EVENT_ProcessHints();
        }
      }
    }
    iVar7 = 0;
    puVar8 = &StreamTracker;
    iVar3 = iVar7;
    do {
      if ((*(short *)(puVar8 + 1) == 2) && (iVar5 = 0, 0 < *(int *)(puVar8[2] + 0xe8))) {
        iVar6 = 0;
        do {
          ppuVar4 = (uchar **)(*(int *)(*(int *)((int)&DAT_800d2a14 + iVar3) + 0xec) + iVar6);
          if ((ppuVar4 != (uchar **)0x0) && (*ppuVar4 != (uchar *)0x0)) {
            SOUND_ProcessInstanceSounds
                      (*ppuVar4,(SoundInstance *)(ppuVar4 + 2),(_Position *)(ppuVar4 + 5),
                       (int)ppuVar4[7],(int)ppuVar4[8],0,(long *)0x0);
          }
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + 0x24;
        } while (iVar5 < *(int *)((&DAT_800d2a14)[iVar7 * 0x10] + 0xe8));
      }
      iVar3 = iVar3 + 0x40;
      iVar7 = iVar7 + 1;
      puVar8 = puVar8 + 0x10;
    } while (iVar7 < 0x10);
    if ((DAT_800d223e != 6) && ((DAT_800d2210 & 0x100000) == 0)) {
      INSTANCE_SpatialRelationships(instanceList);
    }
    INSTANCE_ProcessFunctions(gameTracker->instanceList);
    INSTANCE_CleanUpInstanceList(gameTracker->instanceList,0);
    INSTANCE_DeactivateFarInstances(gameTracker);
    MONAPI_ProcessGenerator();
    DAT_1f800000 = _theCamera;
    DAT_1f800004 = _DAT_800d0fa0;
    StackSave = (ulong)&stack0xffffffc0;
    G2Instance_BuildTransformsForList(gameTracker->instanceList->first);
    puVar9 = (undefined *)StackSave;
    if (DAT_800d223e != 6) {
      if ((DAT_800d2210 & 0x100000) == 0) {
        FX_ProcessList(fxTracker);
      }
      puVar9 = (undefined *)StackSave;
      if (DAT_800d223e != 6) {
        if ((DAT_800d2210 & 0x100000) == 0) {
          VM_Tick(0x100,*(undefined *)StackSave);
          if ((gameTracker->debugFlags2 & 0x10000U) != 0) {
            FONT_Print(s_Military_Time__04d_800cf4dc,*puVar9);
          }
          iVar3 = 0;
          puVar8 = &StreamTracker;
          do {
            if (*(short *)(puVar8 + 1) == 2) {
              VM_ProcessVMObjectList_S(puVar8[2],*puVar9);
            }
            iVar3 = iVar3 + 1;
            puVar8 = puVar8 + 0x10;
          } while (iVar3 < 0x10);
        }
        if ((DAT_800d223e != 6) && ((DAT_800d2210 & 0x100000) == 0)) {
          PLANAPI_UpdatePlanningDatabase(gameTracker,DAT_800d20f8,*puVar9);
        }
      }
    }
    DEBUG_Process(gameTracker,*puVar9);
    if ((DAT_800d223e != 6) && ((DAT_800d2210 & 0x100000) == 0)) {
      COLLIDE_InstanceList(gameTracker->instanceList,*puVar9);
      COLLIDE_InstanceListTerrain(gameTracker->instanceList,*puVar9);
    }
    INSTANCE_AdditionalCollideFunctions(instanceList,*puVar9);
    COLLIDE_InstanceListWithSignals(instanceList,*puVar9);
    if (DAT_800d223e != 6) {
      if ((DAT_800d2210 & 0x100000) == 0) {
        LIGHT_CalcShadowPositions(gameTracker,*puVar9);
        INSTANCE_CleanUpInstanceList(gameTracker->instanceList,0x10,*puVar9);
      }
      if (DAT_800d223e != 6) {
        CAMERA_Process(&theCamera,*puVar9);
      }
    }
    PIPE3D_CalculateWCTransform(&theCamera,*puVar9);
    *(undefined2 *)(DAT_800d100c + 0x12) = 0;
    PIPE3D_InvertTransform((char)DAT_800d1010,(char)DAT_800d100c,*puVar9);
    CAMERA_CalcVVClipInfo(&theCamera,*puVar9);
    if (gameTracker->levelChange != 0) {
      gameTracker->levelChange = 0;
    }
    SAVE_IntroduceBufferIntros(*puVar9);
    if (gameTracker->levelDone == 0) {
      GAMELOOP_DisplayFrame(gameTracker,*puVar9);
    }
    else {
      ResetDrawPage(*puVar9);
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_ModeStartRunning(void)

{
  if (((DAT_800d223e == 4) || (DAT_800d223e == 6)) && (DEBUG_ExitMenus(), DAT_800d223e == 6)) {
    currentMenu = standardMenu;
    SOUND_ResumeAllSound();
    VOICEXA_Resume();
  }
  if ((DAT_800d220c & 0x8000000) != 0) {
    DAT_800d220c = DAT_800d220c & 0xf7ffffff;
    DAT_800d22ac = 0;
    DrawSync(0);
  }
  DAT_800d220c = DAT_800d220c & 0xefffffff;
  DAT_800d20f8->flags = DAT_800d20f8->flags & 0xfffffeff;
  DAT_800d223e = 0;
  GAMEPAD_RestoreControllers();
  INSTANCE_Post(DAT_800d20f8,(int)&DAT_0010000a,0);
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_ModeStartPause(void)

{
  DAT_800d223e = 6;
  INSTANCE_Post(DAT_800d20f8,(int)&DAT_0010000a,1);
  currentMenu = pauseMenu;
  menu_set(DAT_800d20ec,menudefs_pause_menu);
  SOUND_PauseAllSound();
  VOICEXA_Pause();
  SndPlay(5);
  DAT_800d220c = DAT_800d220c | 0x10000000;
  GAMEPAD_SaveControllers();
  DAT_800d220c = DAT_800d220c | 0x8000000;
  if (DAT_800d210c == primPool) {
    DAT_800d210c = DAT_800d1d24;
  }
  else {
    DAT_800d210c = primPool;
  }
  *(undefined4 **)(DAT_800d210c + 1) = DAT_800d210c + 3;
  *DAT_800d210c = 0;
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_DemoSetup(void)

{
  DAT_800d22dc = playerCameraMode;
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_ChangeMode(void)

{
  if ((DAT_800d218c & 0x40000) == 0) {
    if ((DAT_800d218c & 0x200000) == 0) {
      if ((DAT_800d2114 & 0xa01) == 0xa01) {
        DAT_800d13a4 = 1;
        (DAT_800d20f8->position).z = (DAT_800d20f8->position).z + 100;
        DAT_800d20f8->zVel = 0;
        DAT_800d2297 = 1;
        INSTANCE_Post(DAT_800d20f8,(int)&DAT_00100010,1);
        DAT_800d20f8->flags = DAT_800d20f8->flags & 0xfffff7ff;
      }
      else {
        if ((DAT_800d2114 & 0xa02) == 0xa02) {
          DAT_800d13a4 = 1;
          (DAT_800d20f8->position).z = (DAT_800d20f8->position).z + -100;
          DAT_800d20f8->zVel = 0;
          DAT_800d2297 = 0;
          INSTANCE_Post(DAT_800d20f8,(int)&DAT_00100010,0);
          DAT_800d223e = 0;
        }
      }
    }
    if ((DAT_800d218c & 0x40000) != 0) goto LAB_800309c0;
  }
  else {
LAB_800309c0:
    if ((DAT_800d22d8 & 2) == 0) goto LAB_80030ae4;
  }
  if (((DAT_800d2118 & 0x60) == 0x60) && ((DAT_800d2114 & 0xf) == 0)) {
    if (DAT_800d223e == 0) {
      DAT_800d223e = 4;
      currentMenu = standardMenu;
      if (DAT_800d2292 == '\0') {
        DAT_800d218c = DAT_800d218c & 0xfff7ffff;
      }
      else {
        DAT_800d218c = DAT_800d218c | 0x80000;
      }
      if (DAT_800d2291 == '\0') {
        DAT_800d2190 = DAT_800d2190 & 0xffffefff;
      }
      else {
        DAT_800d2190 = DAT_800d2190 | 0x1000;
      }
      if (DAT_800d2290 == '\0') {
        DAT_800d2190 = DAT_800d2190 & 0xffffdfff;
      }
      else {
        DAT_800d2190 = DAT_800d2190 | 0x2000;
      }
    }
    else {
      if (DAT_800d223e == 7) {
        DEBUG_EndViewVram((GameTracker *)&gameTrackerX);
        DAT_800d223e = 0;
      }
      else {
        GAMELOOP_ModeStartRunning();
      }
    }
  }
LAB_80030ae4:
  if ((((((DAT_800d2118 & 0x4000) == 0) && (gamePadControllerOut < 6)) || (DAT_800d223e != 0)) ||
      ((DAT_800d220c & 0x80) != 0)) ||
     ((DAT_800d2198 != 0 && ((LAB_800d219c == 0xb || (DAT_800d2198 != -1)))))) {
    if (((((DAT_800d2118 & 0x4000) != 0) || ((DAT_800d220c & 0x40000000) != 0)) &&
        ((DAT_800d223e != 0 && ((DAT_800d220c & 0x20000000) == 0)))) &&
       ((DAT_800d2198 == 0 || ((LAB_800d219c != 0xb && (DAT_800d2198 == -1)))))) {
      if (((DAT_800d2118 & 0x4000) != 0) && ((DAT_800d220c & 0x40000000) == 0)) {
        SndPlay(5);
      }
      DAT_800d220c = DAT_800d220c & 0xbfffffff;
      GAMELOOP_ModeStartRunning();
    }
  }
  else {
    GAMELOOP_ModeStartPause();
  }
  if ((DAT_800d2114 & 0x40000000) == 0) {
    if ((DAT_800d211c & 0x40000000) != 0) {
      DAT_800d20f8->flags = DAT_800d20f8->flags & 0xfffffeff;
    }
  }
  else {
    DAT_800d20f8->flags = DAT_800d20f8->flags | 0x100;
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

/* File: C:\kain2\game\GAMELOOP.C */

void GAMELOOP_RequestLevelChange(char *name,short number,GameTracker *gameTracker)

{
  if (gameTracker->levelChange == 0) {
    gameTracker->gameFlags = gameTracker->gameFlags | 1;
    SOUND_ResetAllSound();
    sprintf(gameTracker->baseAreaName,&LAB_800cf4f0,name,(int)number);
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

/* File: C:\kain2\game\GAMELOOP.C */

void PSX_GameLoop(GameTracker *gameTracker)

{
  GAMEPAD_Process(gameTracker);
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

/* File: C:\kain2\game\GAMELOOP.C */

MATRIX * GAMELOOP_GetMatrices(int numMatrices)

{
  MATRIX *pMVar1;
  MATRIX *pMVar2;
  
  pMVar2 = *(MATRIX **)(DAT_800d210c + 4);
  pMVar1 = pMVar2 + numMatrices;
  if (pMVar1 < *(MATRIX **)(DAT_800d210c + 8)) {
    *(MATRIX **)(DAT_800d210c + 4) = pMVar1;
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

/* File: C:\kain2\game\GAMELOOP.C */

GameTracker * GAMELOOP_GetGT(void)

{
  return (GameTracker *)&gameTrackerX;
}





