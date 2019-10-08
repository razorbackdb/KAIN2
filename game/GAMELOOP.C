#include "THISDUST.H"
#include "GAMELOOP.H"

void GAMELOOP_AllocStaticMemory(void)

{
  instanceList = (_InstanceList *)MEMPACK_Malloc(0x10c, '\x06');
  instancePool = (_InstancePool *)MEMPACK_Malloc((u_long)&DAT_00009bac, '\x06');
  gOt2 = (u_long **)MEMPACK_Malloc(0x34e18, '\x06');
  PTR_800d1d1c = gOt2 + 0xc00;
  primPool2 = (_PrimPool *)(gOt2 + 0x1800);
  PTR_800d1d24 = (_PrimPool *)(gOt2 + 0x75c3);
  primBase = (char *)gOt2;
  gLightInfo = (LightInfo *)MEMPACK_Malloc(0x47c, '\x06');
  memset(gLightInfo, 0, 0x47c);
  gPolytopeList = (_PolytopeList *)MEMPACK_Malloc((u_long)&DAT_000018c0, '\x06');
  gVertexPool = (_VertexPool *)gPolytopeList;
  gFXT = (_FXTracker *)MEMPACK_Malloc((u_long)&DAT_000079a8, '\x06');
  fxTracker = gFXT;
  planningPool = MEMPACK_Malloc(3000, '\x06');
  enemyPlanPool = MEMPACK_Malloc(1000, '\x06');
  GlobalObjects = (_ObjectTracker *)MEMPACK_Malloc(0x6c0, '\x06');
  G2Anim_Install();
  return;
}

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
  do
  {
    iVar2 = iVar2 + 1;
    *(undefined2 *)((int)&(gameTrackerX.GlobalObjects)->objectStatus + iVar1) = 0;
    iVar1 = iVar1 + 0x24;
  } while (iVar2 < 0x30);
  gameTrackerX.gameData.asmData.MorphTime = 1000;
  OBTABLE_ClearObjectReferences();
  EVENT_InitTimers();
  return;
}

void GAMELOOP_SystemInit(GameTracker *gameTracker)

{
  GAMELOOP_AllocStaticMemory();
  INSTANCE_InitInstanceList(instanceList, instancePool);
  GAMELOOP_ClearGameTracker();
  return;
}

void GAMELOOP_ResetGameStates(void)

{
  EVENT_InitTimers();
  return;
}

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

void GAMELOOP_CalcGameTime(void)

{
  int iVar1;
  int iVar2;

  60000 + 0x2d0;
  0x3c;
  gameTrackerX.timeOfDay =
       (short)iVar1 * 0x28 +
 6 + (iVar1 >> 0x1f) >> 2) - (short)(iVar1 >> 0x1f)) * -0x960 + (short)iVar2;
  return;
}

void GAMELOOP_SetGameTime(long timeOfDay)

{
  int iVar1;
  int iVar2;

 100) * -0x28;
 iVar2 = iVar1 + -0x2d0;
 if (iVar2 < 0)
 {
   iVar2 = iVar1 + 0x2d0;
 }
 gameTrackerX.multGameTime;
 gameTrackerX.timeOfDay = (short)timeOfDay;
 gameTrackerX.currentTimeOfDayTime = gameTrackerX.currentMaterialTime;
 return;
}

int GAMELOOP_GetTimeOfDay(void)

{
  int iVar1;
  int iVar2;

  iVar2 = (int)gameTrackerX.timeOfDay;
  if (iVar2 - 0x259U < 99)
  {
    return 600;
  }
  iVar1 = 700;
  if ((1099 < iVar2 - 700U) && (iVar1 = 0x708, 99 < iVar2 - 0x708U))
  {
    return 0x76c;
  }
  return iVar1;
}

int GAMELOOP_GetMatrices(int timeOfDay)

{
  int iVar1;

  if (timeOfDay - 0x259U < 99)
  {
    return 1;
  }
  iVar1 = 2;
  if ((1099 < timeOfDay - 700U) && (iVar1 = 3, 99 < timeOfDay - 0x708U))
  {
    return 0;
  }
  return iVar1;
}

int GAMELOOP_WaitForLoad(void)

{
  int iVar1;

  if ((gameTrackerX.debugFlags & 0x80000U) != 0)
  {
    VOICEXA_Tick();
  }
  iVar1 = STREAM_PollLoadQueue();
  return iVar1;
}

_StreamUnit *UNDERWORLD_LoadLevel(char *baseAreaName, GameTracker *gameTracker)

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
  if (sVar2 != 0)
  {
    STREAM_AbortAreaLoad("");
  }
  strcmp("", baseAreaName);
  LOAD_ReadDirectory(baseAreaName);
  streamUnit = LoadLevels(gameTracker, baseAreaName, (StreamUnitPortal *)0x0, 0);
  if (streamUnit->used == 1)
  {
    DRAW_LoadingMessage();
    sVar1 = streamUnit->used;
    while (sVar1 == 1)
    {
      GAMELOOP_WaitForLoad();
      sVar1 = streamUnit->used;
    }
    STREAM_NextLoadFromHead();
    STREAM_LoadMainVram(gameTracker, baseAreaName, streamUnit);
    iVar3 = GAMELOOP_WaitForLoad();
    do
    {
      iVar4 = GAMELOOP_WaitForLoad();
      if (iVar4 == 0)
        break;
    } while (iVar3 + -1 <= iVar4);
  }
  else
  {
    STREAM_LoadMainVram(gameTracker, baseAreaName, streamUnit);
  }
  pLVar5 = streamUnit->level;
  p_Var7 = pLVar5->startUnitMainSignal;
  if (p_Var7 != (_MultiSignal *)0x0)
  {
    if (gameTracker->playerInstance != (_Instance *)0x0)
    {
      p_Var7->flags = p_Var7->flags | 1;
      SIGNAL_HandleFogNear(gameTracker->playerInstance, streamUnit->level->startUnitMainSignal->signalList, 0);
      EVENT_AddSignalToReset(streamUnit->level->startUnitMainSignal);
    }
    pLVar5 = streamUnit->level;
  }
  pBVar8 = pLVar5->terrain->BSPTreeArray;
  p_Var6 = pBVar8->bspRoot;
  local_20.x = -((p_Var6->sphere).position.x + (pBVar8->globalOffset).x);
  local_20.y = -((p_Var6->sphere).position.y + (pBVar8->globalOffset).y);
  local_20.z = -((p_Var6->sphere).position.z + (pBVar8->globalOffset).z);
  PreloadAllConnectedUnits(gameTracker, streamUnit, &local_20);
  return streamUnit;
}

void GAMELOOP_InitStandardObjects(void)

{
  char *name;
  undefined **ppuVar1;
  u_int uVar2;

  LOAD_DumpCurrentDir();
  uVar2 = 0;
  ppuVar1 = &PTR_s_raziel_800c8e94;
  do
  {
    name = *ppuVar1;
    ppuVar1 = ppuVar1 + 1;
    uVar2 = uVar2 + 1;
    InsertGlobalObject(name, &gameTrackerX);
  } while (uVar2 < 10);
  return;
}

void GAMELOOP_StreamLevelLoadAndInit(char *baseAreaName, GameTracker *gameTracker)

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
  INSTANCE_InitInstanceList(list, pool);
  GAMELOOP_InitGameTracker();
  CAMERA_Normalize(&theCamera);
  PLANAPI_InitPlanning(planningPool);
  ENMYPLAN_InitEnemyPlanPool(enemyPlanPool);
  FX_Init(fxTracker);
  WARPGATE_IsWarpgateInUse();
  DRAW_InitShadow();
  GAMELOOP_InitStandardObjects();
  p_Var1 = UNDERWORLD_LoadLevel(baseAreaName, gameTracker);
  do
  {
    iVar2 = STREAM_PollLoadQueue();
  } while (iVar2 != 0);
  gameTracker->introFX = (void *)0x0;
  pLVar6 = p_Var1->level;
  RENDER_currentStreamUnitID = *(short *)&gameTracker->StreamUnitID;
  fontsObject = (Object *)(void *)0x0;
  iVar2 = 0;
  if (0 < pLVar6->numIntros)
  {
    iVar7 = 0;
    do
    {
      iVar3 = strcpy(pLVar6->introList->name + iVar7, "raziel");
      if (iVar3 == 0)
      {
        INSTANCE_InsertInstanceGroup((Intro *)(p_Var1->level->introList->name + iVar7), *(short *)&p_Var1->StreamUnitID);
        break;
      }
      pLVar6 = p_Var1->level;
      iVar2 = iVar2 + 1;
      iVar7 = iVar7 + 0x4c;
    } while (iVar2 < pLVar6->numIntros);
  }
  gameTracker->playerInstance->data = gameTracker->playerInstance->object->data;
  CAMERA_SetProjDistance(&theCamera, gameTracker->playerInstance);
  p_Var4 = gameTracker->playerInstance;
  theCamera.core.position.x = (p_Var4->position).x;
  theCamera.core.position.y = (p_Var4->position).y;
  theCamera.core.position.z = (p_Var4->position).z;
  SetFogNearFar((u_int)p_Var1->level->fogNear, (u_int)p_Var1->level->fogFar, 0x140);
  SetFarColor(0, 0, 0);
  clearRect.r0 = p_Var1->level->backColorR;

  clearRect.g0 = p_Var1->level->backColorG;

  clearRect.b0 = p_Var1->level->backColorB;

  BLK_FILL_800d20b8.r0 = p_Var1->level->backColorR;

  BLK_FILL_800d20b8.g0 = p_Var1->level->backColorG;

  BLK_FILL_800d20b8.b0 = p_Var1->level->backColorB;

  LIGHT_ActivateSources(gLightInfo);
  gameTracker->wipeType = 10;
  gameTracker->hideBG = 0;
  gameTracker->wipeTime = 0x1e;
  gameTracker->maxWipeTime = 0x1e;
  p_Var5 = p_Var1->level->startSignal;
  if (p_Var5 != (_MultiSignal *)0x0)
  {
    p_Var5->flags = p_Var5->flags | 1;
    SIGNAL_HandleFogNear(gameTracker->playerInstance, p_Var1->level->startSignal->signalList, 0);
    EVENT_AddSignalToReset(p_Var1->level->startSignal);
  }
  gameTracker->vblFrames = 0;
  p_Var5 = p_Var1->level->startUnitMainSignal;
  if ((p_Var5 != (_MultiSignal *)0x0) && (gameTracker->playerInstance != (_Instance *)0x0))
  {
    p_Var5->flags = p_Var5->flags | 1;
    SIGNAL_HandleFogNear(gameTracker->playerInstance, p_Var1->level->startUnitMainSignal->signalList, 0);
    EVENT_AddSignalToReset(p_Var1->level->startUnitMainSignal);
  }
  return;
}

void GAMELOOP_LevelLoadAndInit(char *baseAreaName, GameTracker *gameTracker, int toSignalNum, int fromSignalNum)

{
  UNDERWORLD_LoadLevel(baseAreaName, gameTracker);
  return;
}

void GAMELOOP_SetScreenWipe(int time, int maxTime, int type)

{
  gameTrackerX.wipeTime = (short)time;
  gameTrackerX.maxWipeTime = (short)maxTime;
  gameTrackerX.wipeType = (short)type;
  return;
}

void SIGNAL_HandleScreenWipe(u_long **drawot)

{
  _PrimPool *primPool;
  int r;

  primPool = gameTrackerX.primPool;
  if ((GlobalSave->flags & 1U) != 0)
  {
    DRAW_FlatQuad(&gameTrackerX.wipeColor, 0, 0, 0x200, 0, 0, 0x1e, 0x200, 0x1e, gameTrackerX.primPool, drawot);
    DRAW_FlatQuad(&gameTrackerX.wipeColor, 0, 0xd2, 0x200, 0xd2, 0, 0xf0, 0x200, 0xf0, primPool, drawot);
  }
  r = (int)gameTrackerX.wipeTime;
  if (r < 1)
  {
    if (r < -1)
    {
      if (gameTrackerX.wipeType == 10)
      {

                        (int)gameTrackerX.maxWipeTime);
                        DRAW_TranslucentQuad(0, 0, 0x200, 0, 0, 0xf0, 0x200, 0xf0, r, r, r, 2, primPool, drawot);
      }
      else
      {
        if (gameTrackerX.wipeType == 0xb)
        {

                          (int)gameTrackerX.maxWipeTime);
                          DRAW_TranslucentQuad(0, 0, 0x200, 0, 0, 0x1e, 0x200, 0x1e, r, r, r, 2, primPool, drawot);
                          DRAW_TranslucentQuad(0, 0xd2, 0x200, 0xd2, 0, 0xf0, 0x200, 0xf0, r, r, r, 2, primPool, drawot);
                          if (gameTrackerX.wipeTime == -2)
                          {
                            GlobalSave->flags = GlobalSave->flags | 1;
                          }
        }
      }
      if (gameTrackerX.gameFramePassed != 0)
      {
        gameTrackerX.wipeTime = gameTrackerX.wipeTime + 1;
      }
    }
    else
    {
      if (r == -1)
      {
        if (gameTrackerX.wipeType == 0xb)
        {
          GlobalSave->flags = GlobalSave->flags | 1;
        }
        else
        {
          DRAW_FlatQuad(&gameTrackerX.wipeColor, 0, 0, 0x200, 0, 0, 0xf0, 0x200, 0xf0, primPool, drawot);
        }
      }
      else
      {
        theCamera.core.screenScale.z = 0x1000;
        theCamera.core.screenScale.y = 0x1000;
        theCamera.core.screenScale.x = 0x1000;
      }
    }
  }
  else
  {
    if (gameTrackerX.wipeType == 10)
    {
 (int)gameTrackerX.maxWipeTime);
 DRAW_TranslucentQuad(0, 0, 0x200, 0, 0, 0xf0, 0x200, 0xf0, r, r, r, 2, primPool, drawot);
    }
    else
    {
      if (gameTrackerX.wipeType == 0xb)
      {
 (int)gameTrackerX.maxWipeTime);
 DRAW_TranslucentQuad(0, 0, 0x200, 0, 0, 0x1e, 0x200, 0x1e, r, r, r, 2, primPool, drawot);
 DRAW_TranslucentQuad(0, 0xd2, 0x200, 0xd2, 0, 0xf0, 0x200, 0xf0, r, r, r, 2, primPool, drawot);
 GlobalSave->flags = GlobalSave->flags & 0xfffe;
      }
    }
    if (gameTrackerX.gameFramePassed != 0)
    {
      gameTrackerX.wipeTime = gameTrackerX.wipeTime + -1;
    }
  }
  return;
}

void UpdateFogSettings(_StreamUnit *currentUnit, Level *level)

{
  u_short uVar1;
  u_short uVar2;
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
  if (iVar7 < (int)uVar6)
  {
    level->fogNear = (u_short)(uVar6 - 500);
    bVar3 = iVar7 < (int)(uVar6 - 500 & 0xffff);
  LAB_8002e5fc:
    bVar4 = true;
    if (!bVar3)
    {
      bVar5 = true;
      level->fogNear = uVar1;
    }
  }
  else
  {
    if ((int)uVar6 < iVar7)
    {
      level->fogNear = (u_short)(uVar6 + 500);
      bVar3 = (int)(uVar6 + 500 & 0xffff) < iVar7;
      goto LAB_8002e5fc;
    }
    bVar5 = true;
  }
  uVar6 = (u_int)level->fogFar;
  if (iVar8 < (int)uVar6)
  {
    level->fogFar = (u_short)(uVar6 - 500);
    bVar4 = true;
    if (iVar8 < (int)(uVar6 - 500 & 0xffff))
    {
      bVar5 = false;
      goto LAB_8002e670;
    }
  }
  else
  {
    if (iVar8 <= (int)uVar6)
      goto LAB_8002e670;
    level->fogFar = (u_short)(uVar6 + 500);
    bVar4 = true;
    if ((int)(uVar6 + 500 & 0xffff) < iVar8)
    {
      bVar5 = false;
      goto LAB_8002e670;
    }
  }
  bVar4 = true;
  level->fogFar = uVar2;
LAB_8002e670:
  if ((bVar4) && (LIGHT_CalcDQPTable(level), bVar5))
  {
    currentUnit->TargetFogNear = level->fogNear;
    currentUnit->TargetFogFar = level->fogFar;
  }
  return;
}

int CheckForNoBlend(_ColorType *Color)

{
  int iVar1;

  iVar1 = 0;
  if (((Color->r < 5) && (iVar1 = 0, Color->g < 5)) && (iVar1 = 1, 4 < Color->b))
  {
    iVar1 = 0;
  }
  return iVar1;
}

void BlendToColor(_ColorType *target, _ColorType *current, _ColorType *dest)

{
  int iVar1;

  LoadAverageCol((byte *)target, (byte *)current, 0x200, 0xe00, (undefined *)dest);
  iVar1 = (u_int)target->r - (u_int)dest->r;
  if (iVar1 < 0)
  {
    if (4 < (int)((u_int)dest->r - (u_int)target->r))
      goto LAB_8002e7dc;
  }
  else
  {
    if (4 < iVar1)
    {
      dest->code = '\0';
      return;
    }
  }
  iVar1 = (u_int)target->g - (u_int)dest->g;
  if (iVar1 < 0)
  {
    if (4 < (int)((u_int)dest->g - (u_int)target->g))
      goto LAB_8002e7dc;
  }
  else
  {
    if (4 < iVar1)
    {
      dest->code = '\0';
      return;
    }
  }
  iVar1 = (u_int)target->b - (u_int)dest->b;
  if (iVar1 < 0)
  {
    if (4 < (int)((u_int)dest->b - (u_int)target->b))
      goto LAB_8002e7dc;
  }
  else
  {
    if (4 < iVar1)
    {
      dest->code = '\0';
      return;
    }
  }
  *dest = *target;
LAB_8002e7dc:
  dest->code = '\0';
  return;
}

void MainRenderLevel(_StreamUnit *currentUnit, u_long **drawot)

{
  MATRIX *pMVar1;
  LightInfo *lightInfo;
  _Instance *p_Var2;
  u_long *puVar3;
  u_short uVar4;
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
  _ColorType local_30[2];

  level = currentUnit->level;
  terrain = level->terrain;
  UpdateFogSettings(currentUnit, level);
  currentUnit->FrameCount = gameTrackerX.displayFrameCount;
  SetFogNearFar((u_int)level->fogNear, (u_int)level->fogFar, 0x140);
  SetFarColor(0, 0, 0);
  clearRect.r0 = level->backColorR;

  clearRect.g0 = level->backColorG;

  clearRect.b0 = level->backColorB;

  BLK_FILL_800d20b8.r0 = level->backColorR;

  BLK_FILL_800d20b8.g0 = level->backColorG;

  BLK_FILL_800d20b8.b0 = level->backColorB;

  if ((int)gameTrackerX.gameData.asmData.MorphTime == 1000)
  {
    if (gameTrackerX.gameData.asmData.MorphType == 1)
    {
      local_30[0] = *(_ColorType *)&level->specturalColorR;
    }
    else
    {
      local_30[0] = *(_ColorType *)&level->backColorR;
    }
  }
  else
  {
    1000;
    if (gameTrackerX.gameData.asmData.MorphType == 1)
    {
      unitID = 0x1000 - unitID;
    }
    LoadAverageCol(&level->specturalColorR, &level->backColorR, unitID, 0x1000 - unitID,
                   (undefined *)local_30);
  }
  BlendToColor(local_30, (_ColorType *)&currentUnit->FogColor, (_ColorType *)&currentUnit->FogColor);
  depthQBackColor = currentUnit->FogColor;
  unitID = GAMELOOP_GetTimeOfDay();
  if ((((unitID != 600) && (unitID != 0x708)) || ((level->unitFlags & 2U) == 0)) &&
      (gameTrackerX.gameData.asmData.MorphTime == 1000))
  {
    depthQBackColor = depthQBackColor & 0xfff8f8f8 | 0x40404;
  }
  depthQFogStart = (u_int)level->fogNear;
  depthQFogFar = (u_int)level->fogFar;
  unitID = CheckForNoBlend((_ColorType *)&depthQBackColor);
  depthQBlendStart = 0xffff;
  if (unitID == 0)
  {
    depthQBlendStart = depthQFogStart;
  }

  clearRect.r0 = (u_char)depthQBackColor;

  clearRect.g0 = depthQBackColor._1_1_;

  clearRect.b0 = depthQBackColor._2_1_;

  BLK_FILL_800d20b8.r0 = (u_char)depthQBackColor;

  BLK_FILL_800d20b8.g0 = depthQBackColor._1_1_;

  BLK_FILL_800d20b8.b0 = depthQBackColor._2_1_;
  PIPE3D_AnimateTerrainTextures(terrain->aniList, gameTrackerX.frameCount, gameTrackerX.primPool, drawot);
  PIPE3D_AnimateTerrainTextures(level->bgAniList, gameTrackerX.frameCount, gameTrackerX.primPool, drawot);
  unitID = 0;
  LIGHT_Restore(gLightInfo);
  lightInfo = gLightInfo;
  gLightInfo->numSavedColors = 0;
  LIGHT_InitSources((_CameraCore_Type *)&theCamera, level, lightInfo);
  LIGHT_SourcesAndInstances(gLightInfo, gameTrackerX.instanceList);
  LIGHT_SourcesAndTerrain(gLightInfo, terrain);
  PIPE3D_InstanceTransformAndDraw(currentUnit, &gameTrackerX, drawot, (_CameraCore_Type *)&theCamera);
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
  if (0 < terrain->numBSPTrees)
  {
    do
    {
      p_Var2 = gameTrackerX.gameData.asmData.lightInstances[0].lightInstance;
      ppiVar6 = (int **)((int)&terrain->BSPTreeArray->bspRoot + iVar8);
      if ((-1 < *(short *)((int)ppiVar6 + 0x1a)) && ((*(u_short *)((int)ppiVar6 + 0x12) & 1) == 0))
      {
        p_Var7 = (_Instance *)0x0;
        if ((*(u_short *)((int)ppiVar6 + 0x12) & 0x40) != 0)
        {
          gameTrackerX.gameData.asmData.lightInstances[0].lightInstance = (_Instance *)0x0;
          p_Var7 = p_Var2;
        }
        uVar5 = (local_60 & 0xffff) - (u_int) * (u_short *)(ppiVar6 + 3);
        local_38 = -(short)uVar5;
        uVar4 = local_60._2_2_ - *(short *)((int)ppiVar6 + 0xe);
        theCamera.core.position._0_4_ = uVar5 & 0xffff | (u_int)uVar4 << 0x10;
        local_36 = -uVar4;
        theCamera.core.position.z = local_5c - *(short *)(ppiVar6 + 4);
        local_34 = -theCamera.core.position.z;
        ApplyMatrixSV(&local_58, &local_38, (theCamera.core.wcTransform)->t);
        BSP_MarkVisibleLeaves_S(ppiVar6, (u_char *)&theCamera, (int *)gPolytopeList);
        local_64 = ppiVar6 + 3;
        puVar3 = (u_long *)(*(code *)gameTrackerX.drawDisplayPolytopeListFunc)(gPolytopeList, terrain, &theCamera, gameTrackerX.primPool);
        (gameTrackerX.primPool)->nextPrim = puVar3;
        if ((*(u_short *)((int)ppiVar6 + 0x12) & 0x40) != 0)
        {
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
  INSTANCE_IntroduceSavedInstance(terrain, (_CameraCore_Type *)&theCamera, lightInfo, unitID);
  StackSave = (u_long)&stack0xffffff88;
  FX_DrawLightning(fxTracker, &gameTrackerX, gameTrackerX.drawOT, theCamera.core.wcTransform);
  if ((gameTrackerX.playerInstance)->currentStreamUnitID == currentUnit->StreamUnitID)
  {
    FX_DrawReaver(gameTrackerX.primPool, gameTrackerX.drawOT, theCamera.core.wcTransform);
  }
  return;
}

void StreamIntroInstancesForUnit(_StreamUnit *currentUnit)

{
  if (currentUnit->used == 2)
  {
    SBSP_IntroduceInstances(currentUnit->level->terrain, currentUnit->StreamUnitID);
  }
  return;
}

long StreamRenderLevel(_StreamUnit *currentUnit, Level *mainLevel, u_long **drawot, long portalFogColor)

{
  MATRIX *pMVar1;
  long lVar2;
  LightInfo *lightInfo;
  int unitID;
  u_long *puVar3;
  u_short uVar4;
  u_int uVar5;
  int **ppiVar6;
  Level *level;
  _Terrain *terrain;
  int iVar7;
  undefined auStack112[16];
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
  SetFarColor(0, 0, 0);
  UpdateFogSettings(currentUnit, level);
  depthQFogFar = (u_int)level->fogFar;
  depthQFogStart = (u_int)level->fogNear;
  depthQBackColor = portalFogColor;
  currentUnit->FogColor = portalFogColor;
  theCamera.core.farPlane = depthQFogFar;
  unitID = CheckForNoBlend((_ColorType *)&depthQBackColor);
  depthQBlendStart = 0xffff;
  if (unitID == 0)
  {
    depthQBlendStart = depthQFogStart;
  }
  SetFogNearFar(depthQFogStart, depthQFogFar, 0x140);
  PIPE3D_AnimateTerrainTextures(terrain->aniList, gameTrackerX.frameCount, gameTrackerX.primPool, drawot);
  PIPE3D_AnimateTerrainTextures(level->bgAniList, gameTrackerX.frameCount, gameTrackerX.primPool, drawot);
  LIGHT_InitSources((_CameraCore_Type *)&theCamera, level, gLightInfo);
  LIGHT_SourcesAndTerrain(gLightInfo, terrain);
  PIPE3D_InstanceTransformAndDraw(currentUnit, &gameTrackerX, drawot, (_CameraCore_Type *)&theCamera);
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
  if (0 < terrain->numBSPTrees)
  {
    iVar7 = 0;
    do
    {
      ppiVar6 = (int **)((int)&terrain->BSPTreeArray->bspRoot + iVar7);
      if ((-1 < *(short *)((int)ppiVar6 + 0x1a)) && ((*(u_short *)((int)ppiVar6 + 0x12) & 1) == 0))
      {
        uVar5 = (local_58 & 0xffff) - (u_int) * (u_short *)(ppiVar6 + 3);
        local_30 = -(short)uVar5;
        uVar4 = local_58._2_2_ - *(short *)((int)ppiVar6 + 0xe);
        theCamera.core.position._0_4_ = uVar5 & 0xffff | (u_int)uVar4 << 0x10;
        local_2e = -uVar4;
        theCamera.core.position.z = local_54 - *(short *)(ppiVar6 + 4);
        local_2c = -theCamera.core.position.z;
        ApplyMatrixSV(&local_50, &local_30, (theCamera.core.wcTransform)->t);
        BSP_MarkVisibleLeaves_S(ppiVar6, (u_char *)&theCamera, (int *)gPolytopeList);
        local_5c = ppiVar6 + 3;
        local_60 = drawot;
        puVar3 = (u_long *)(*(code *)gameTrackerX.drawDisplayPolytopeListFunc)(gPolytopeList, terrain, &theCamera, gameTrackerX.primPool);
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
  INSTANCE_IntroduceSavedInstance(terrain, (_CameraCore_Type *)&theCamera, lightInfo, unitID);
  InStreamUnit = 0;
  theCamera.core.farPlane = lVar2;
  if ((gameTrackerX.playerInstance)->currentStreamUnitID == currentUnit->StreamUnitID)
  {
    hackOT = drawot;
    StackSave = (u_long)auStack112;
    FX_DrawReaver(gameTrackerX.primPool, drawot, theCamera.core.wcTransform);
  }
  return 0;
}

void GAMELOOP_FlipScreenAndDraw(GameTracker *gameTracker, u_long **drawot)

{
  int iVar1;
  u_int uVar2;

  DrawOTag(drawot + 0xbff);
  do
  {
    iVar1 = CheckVolatile(gameTracker->drawTimerReturn);
  } while (iVar1 != 0);
  ResetPrimPool();
  PutDrawEnv((u_char *)(&draw + gameTracker->drawPage));
  do
  {
    iVar1 = CheckVolatile(gameTracker->reqDisp);
  } while (iVar1 != 0);
  uVar2 = GetRCnt(0xf2000000);
  *(u_long **)&gameTracker->drawTimerReturn = &gameTracker->drawTime;
  iVar1 = (gameTracker->gameData).asmData.dispPage;
  gameTracker->usecsStartDraw = uVar2 & 0xffff | gameTimer << 0x10;
  (gameTracker->gameData).asmData.dispPage = 1 - iVar1;
  return;
}

void GAMELOOP_AddClearPrim(u_long **drawot)

{
  u_long *puVar1;
  u_long uVar2;
  u_long uVar3;
  u_long uVar4;

  if ((gameTrackerX.gameFlags & 0x8000000U) == 0)
  {
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
  *(u_short *)&(gameTrackerX.savedOTStart)->b0 = (&clearRect)[gameTrackerX.drawPage].y0;
  return;
}

void GAMELOOP_SwitchTheDrawBuffer(u_long **drawot)

{
  GAMELOOP_AddClearPrim(drawot);
  DrawSync(0);
  if (gameTrackerX.drawTimerReturn != (long *)0x0)
  {
    gameTrackerX.drawTimerReturn = (long *)0x0;
    gameTrackerX.reqDisp =
        (void *)((int)gameTrackerX.disp + gameTrackerX.gameData.asmData.dispPage * 0x14);
  }
  PutDrawEnv((u_char *)(&draw + gameTrackerX.drawPage));
  return;
}

void GAMELOOP_SetupRenderFunction(GameTracker *gameTracker)

{
  *(undefined **)&gameTracker->drawAnimatedModelFunc = &DRAW_AnimatedModel_S;
  *(undefined **)&gameTracker->drawDisplayPolytopeListFunc = &DRAW_DisplayPolytopeList_S;
  return;
}

_StreamUnit *GAMELOOP_GetMainRenderUnit(void)

{
  _Instance *p_Var1;
  _StreamUnit *p_Var2;
  _StreamUnit *p_Var3;

  p_Var1 = theCamera.focusInstance;
  if (theCamera.mode == 5)
  {
    p_Var2 = STREAM_WhichUnitPointerIsIn(theCamera.data.Cinematic.posSpline);
  }
  else
  {
    if ((theCamera.focusInstance == gameTrackerX.playerInstance) &&
        (gameTrackerX.SwitchToNewStreamUnit != 0))
    {
      p_Var2 = STREAM_GetStreamUnitWithID(gameTrackerX.moveRazielToStreamID);
      if (p_Var2 == (_StreamUnit *)0x0)
      {
        p_Var2 = STREAM_GetStreamUnitWithID(p_Var1->currentStreamUnitID);
        return p_Var2;
      }
    }
    else
    {
      p_Var2 = STREAM_GetStreamUnitWithID((theCamera.focusInstance)->currentStreamUnitID);
    }
    p_Var3 = COLLIDE_CameraWithStreamSignals(&theCamera);
    if (p_Var3 != (_StreamUnit *)0x0)
    {
      p_Var2 = p_Var3;
    }
  }
  return p_Var2;
}

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
  u_short *puVar9;
  int iVar10;
  StreamUnitPortal *curStreamPortal;
  RECT local_40;
  u_long **local_38;
  Level *local_34;
  int local_30;

  local_38 = gameTracker->drawOT;
  if ((gameTrackerX.gameFlags & 0x8000000U) == 0)
  {
    gameTrackerX.visibleInstances = 0;
    gameTrackerX.displayFrameCount = gameTrackerX.displayFrameCount + 1;
    GAMELOOP_SetupRenderFunction(&gameTrackerX);
    if (((GlobalSave->flags & 1U) == 0) &&
        (((gameTracker->wipeType != 0xb || (gameTracker->wipeTime == 0)) &&
          ((gameTracker->debugFlags2 & 0x800U) != 0))))
    {
      FX_Spiral(gameTrackerX.primPool, local_38);
    }
    HUD_Draw();
    currentUnit = GAMELOOP_GetMainRenderUnit();
    local_34 = currentUnit->level;
    if ((gameTracker->debugFlags & 4U) != 0)
    {
      FONT_Print("Cameraunit: %s\n");
    }
    RENDER_currentStreamUnitID = *(short *)&currentUnit->StreamUnitID;
    theCamera.core.rightX = 0x140;
    theCamera.core.leftX = 0;
    theCamera.core.topY = 0;
    theCamera.core.bottomY = 0xf0;
    CAMERA_SetViewVolume(&theCamera);
    lVar2 = MEMPACK_ReportMemory((char *)local_34);
    if (lVar2 != 0)
    {
      if ((u_int)local_34->fogFar != theCamera.core.farPlane)
      {
        theCamera.core.farPlane = (u_int)local_34->fogFar;
      }
      if ((gameTracker->debugFlags & 0x8000U) == 0)
      {
        MainRenderLevel(currentUnit, local_38);
      }
    }
    piVar3 = (int *)local_34->terrain->StreamUnits;
    iVar8 = 0;
    local_30 = *piVar3;
    curStreamPortal = (StreamUnitPortal *)(piVar3 + 1);
    if (0 < local_30)
    {
      puVar9 = (u_short *)((int)piVar3 + 0x22);
      do
      {
        currentUnit_01 = *(_StreamUnit **)(puVar9 + 5);
        iVar10 = *(int *)(puVar9 + -5);
        if ((currentUnit_01 == (_StreamUnit *)0x0) ||
            (currentUnit_01->FrameCount != gameTrackerX.displayFrameCount))
        {
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
          if (0 < local_30)
          {
            do
            {
              if ((portal->streamID == iVar10) &&
                  (iVar4 = STREAM_GetClipRect(portal, &local_40), iVar4 != 0))
              {
                bVar1 = true;
              }
              iVar7 = iVar7 + 1;
              portal = portal + 1;
            } while (iVar7 < local_30);
          }
          if (bVar1)
          {
            theCamera.core.leftX = (int)local_40.x * 0x140;
            if (theCamera.core.leftX < 0)
            {
              theCamera.core.leftX = theCamera.core.leftX + 0x1ff;
            }
            theCamera.core.topY = (int)local_40.y;
            theCamera.core.leftX = theCamera.core.leftX >> 9;
            theCamera.core.rightX = ((int)local_40.x + (int)local_40.w) * 0x140;
            if (theCamera.core.rightX < 0)
            {
              theCamera.core.rightX = theCamera.core.rightX + 0x1ff;
            }
            theCamera.core.rightX = theCamera.core.rightX >> 9;
            theCamera.core.bottomY = theCamera.core.topY + local_40.h;
            CAMERA_SetViewVolume(&theCamera);
            SetRotMatrix((u_char *)theCamera.core.wcTransform);
            TransMatrix((int)theCamera.core.wcTransform);
            if ((*puVar9 & 1) == 0)
            {
              if ((currentUnit_01 != (_StreamUnit *)0x0) &&
                  (currentUnit_01->FrameCount != gameTrackerX.displayFrameCount))
              {
                currentUnit_01->FrameCount = gameTrackerX.displayFrameCount;
                STREAM_RenderWarpGate(local_38, curStreamPortal, currentUnit_01, currentUnit, &local_40);
              }
            }
            else
            {
              if ((currentUnit->flags & 8U) == 0)
              {
                WARPGATE_Init(currentUnit);
              }
              else
              {
                if (currentUnit_01 != (_StreamUnit *)0x0)
                {
                  if (currentUnit_01->FrameCount == gameTrackerX.displayFrameCount)
                    goto LAB_8002f7f8;
                  currentUnit_01->FrameCount = gameTrackerX.displayFrameCount;
                }
                STREAM_RenderAdjacantUnit(local_38, curStreamPortal, currentUnit, &local_40);
              }
            }
          }
          else
          {
            if ((currentUnit_01 != (_StreamUnit *)0x0) &&
                (currentUnit_01->FrameCount != gameTrackerX.displayFrameCount))
            {
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
    do
    {
      if ((*(short *)currentUnit_00->StreamList == 2) &&
          (*(u_long *)currentUnit_00->StreamList != gameTrackerX.displayFrameCount))
      {
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
  else
  {
    HUD_Draw();
  }
  DEBUG_Draw(gameTracker, local_38);
  FONT_Flush();
  GAMELOOP_SwitchTheDrawBuffer(local_38);
  uVar5 = GetRCnt(0xf2000000);
  gameTracker->idleTime = uVar5 & 0xffff | gameTimer << 0x10;
  if ((u_int)gameTracker->frameRateLock < gameTracker->vblFrames)
  {
    if ((u_short *)gameTracker->reqDisp != (u_short *)0x0)
    {
      PutDispEnv((u_short *)gameTracker->reqDisp);
      gameTracker->reqDisp = (void *)0x0;
      gameTracker->vblFrames = 0;
    }
  }
  else
  {
    do
    {
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
  if ((gameTrackerX.gameFlags & 0x8000000U) == 0)
  {
    DrawOTag(polyAddr);
  }
  else
  {
    GAMELOOP_DrawSavedOT(local_38);
  }
  return;
}

void GAMELOOP_DrawSavedOT(u_long **newOT)

{
  byte bVar1;
  short sVar2;
  u_short uVar3;
  u_int uVar4;
  byte bVar5;
  u_int uVar6;
  P_TAG *pPVar7;

  sVar2 = (&draw)[gameTrackerX.drawPage].ofs[1];
  pPVar7 = gameTrackerX.savedOTStart;
  if (gameTrackerX.savedOTStart != gameTrackerX.savedOTEnd)
  {
    do
    {
      bVar1 = *(byte *)((int)&pPVar7->len + 3);
      bVar5 = bVar1 & 0xfc;
      if (bVar5 == 0x34)
      {
        uVar3 = *(u_short *)((int)&pPVar7[2].addr + 2);
        if ((uVar3 & 0xf) < 8)
        {
          if (sVar2 == 0)
          {
            *(u_short *)((int)&pPVar7[2].addr + 2) = uVar3 & 0xffef;
          }
          else
          {
            *(u_short *)((int)&pPVar7[2].addr + 2) = uVar3 | 0x10;
          }
        }
      }
      else
      {
        if (bVar5 == 0x24)
        {
          uVar3 = *(u_short *)&pPVar7[1].b0;
          if ((uVar3 & 0xf) < 8)
          {
            if (sVar2 == 0)
            {
              *(u_short *)&pPVar7[1].b0 = uVar3 & 0xffef;
            }
            else
            {
              *(u_short *)&pPVar7[1].b0 = uVar3 | 0x10;
            }
          }
        }
        else
        {
          if (bVar1 == 0xe3)
          {
            if (sVar2 == 0)
            {
              uVar4 = pPVar7->len & 0xfffbffff;
              uVar6 = *(u_int *)&pPVar7->r0 & 0xfffbffff;
            }
            else
            {
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

void ResetPrimPool(void)

{
  undefined **ppuVar1;

  ResetDrawPage();
  if ((gameTrackerX.gameFlags & 0x8000000U) == 0)
  {
    if (gameTrackerX.primPool == primPool2)
    {
      gameTrackerX.primPool = PTR_800d1d24;
    }
    else
    {
      gameTrackerX.primPool = primPool2;
    }
    (gameTrackerX.primPool)->nextPrim = (gameTrackerX.primPool)->prim;
  }
  else
  {
    if (gameTrackerX.drawPage == 0)
    {
      ppuVar1 = (undefined **)&DAT_00008cac;
    }
    else
    {
      ppuVar1 = &PTR_000101dc;
    }
    (gameTrackerX.primPool)->nextPrim =
        (u_long *)((int)&(gameTrackerX.primPool)->numPrims + (int)ppuVar1);
  }
  (gameTrackerX.primPool)->numPrims = 0;
  return;
}

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
  while (cVar1 == '\0')
  {
    uVar4 = pPVar5->addr & 0xffffff;
    pPVar5 = (P_TAG *)(uVar4 | 0x80000000);
    if (uVar4 == 0xffffff)
      goto LAB_8002fcc0;
    cVar1 = *(char *)((int)&pPVar5->addr + 3);
  }
  if ((pPVar5->addr & 0xffffff) == 0xffffff)
  {
  LAB_8002fcc0:
    gameTrackerX.savedOTStart = (P_TAG *)0x0;
  }
  else
  {
    pPVar2 = pPVar5;
    pPVar3 = (P_TAG *)0x0;
    gameTrackerX.savedOTStart = pPVar5;
    if ((pPVar5->addr & 0xffffff) != 0xffffff)
    {
      do
      {
        while (pPVar6 = pPVar3, pPVar5 = pPVar2, *(char *)((int)&pPVar5->addr + 3) != '\0')
        {
          uVar4 = pPVar5->addr & 0xffffff;
          if (uVar4 == 0xffffff)
            goto LAB_8002fdac;
          pPVar2 = (P_TAG *)(uVar4 | 0x80000000);
          pPVar3 = pPVar5;
          pPVar7 = pPVar6;
        }
        if ((pPVar5->addr & 0xffffff) == 0xffffff)
          goto LAB_8002fdac;
        cVar1 = *(char *)((int)&pPVar5->addr + 3);
        while ((cVar1 == '\0' && (uVar4 = pPVar5->addr & 0xffffff, uVar4 != 0xffffff)))
        {
          pPVar5 = (P_TAG *)(uVar4 | 0x80000000);
          cVar1 = *(char *)((int)&pPVar5->addr + 3);
        }
        pPVar6->addr = pPVar6->addr & 0xff000000 | (u_int)pPVar5 & 0xffffff;
        pPVar2 = pPVar5;
        pPVar3 = pPVar6;
      } while ((pPVar5->addr & 0xffffff) != 0xffffff);
      if ((pPVar5->addr & 0xffffff) != 0xffffff)
      {
        gameTrackerX.savedOTEnd = pPVar5;
        return;
      }
    }
  LAB_8002fdac:
    gameTrackerX.savedOTEnd = pPVar5;
    if (pPVar7 != (P_TAG *)0x0)
    {
      gameTrackerX.savedOTEnd = pPVar7;
      pPVar7->addr = pPVar7->addr | 0xffffff;
    }
  }
  return;
}

void ResetDrawPage(void)

{
  u_long **ppuVar1;

  ppuVar1 = gameTrackerX.dispOT;
  gameTrackerX.dispOT = gameTrackerX.drawOT;
  gameTrackerX.drawPage = 1 - gameTrackerX.drawPage;
  gameTrackerX.drawOT = ppuVar1;
  ClearOTagR(ppuVar1, 0xc00);
  return;
}

void GAMELOOP_SystemInit(void)

{
  gameTrackerX.frameRate24fps = 1;
  return;
}

void GAMELOOP_Reset24FPS(void)

{
  gameTrackerX.frameRate24fps = 0;
  return;
}

void GAMELOOP_DoTimeProcess(void)

{
  u_long uVar1;
  u_int uVar2;
  u_int uVar3;

  uVar1 = TIMER_GetTimeMS();
  if ((gameTrackerX.gameFlags & 0x10000000U) == 0)
  {
    gameTrackerX.totalTime = TIMER_TimeDiff(gameTrackerX.currentTicks);
    uVar2 = GetRCnt(0xf2000000);
    gameTrackerX.currentTicks = uVar2 & 0xffff | gameTimer << 0x10;
    if (gameTrackerX.frameRateLock < 1)
    {
      gameTrackerX.frameRateLock = 1;
    }
    if (2 < gameTrackerX.frameRateLock)
    {
      gameTrackerX.frameRateLock = 2;
    }
    if ((gameTrackerX.decoupleGame == 0) || ((gameTrackerX.gameFlags & 0x10000000U) != 0))
    {
      if (gameTrackerX.frameRateLock == 1)
      {
        gameTrackerX.lastLoopTime = 0x21;
      }
      else
      {
        if (gameTrackerX.frameRateLock == 2)
        {
          gameTrackerX.lastLoopTime = 0x32;
        }
      }
      uVar2 = (u_int)((u_longlong)(gameTrackerX.lastLoopTime << 0xc) * 0x3e0f83e1 >> 0x20);
    }
    else
    {
      uVar3 = 0x21;
      if ((gameTrackerX.frameRateLock != 1) && (gameTrackerX.frameRateLock == 2))
      {
        uVar3 = 0x32;
      }
      uVar2 = uVar3;
      if (gameTrackerX.lastLoopTime != 0xffffffff)
      {
        uVar2 = uVar1 - gameTrackerX.currentTime;
      }
      if (((gameTrackerX.frameRateLock == 1) && (gameTrackerX.frameRate24fps != 0)) &&
          (uVar2 = uVar2 - 9, gameTrackerX.gameData.asmData.MorphTime != 1000))
      {
        uVar2 = 0x21;
      }
      if ((uVar3 <= uVar2) && (uVar3 = uVar2, 0x42 < uVar2))
      {
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
           0x1000 < gameTrackerX.timeSinceLastGameFrame)
    {
      gameTrackerX.gameFramePassed = 1;
      gameTrackerX.timeSinceLastGameFrame = gameTrackerX.timeSinceLastGameFrame - 0x1000;
      gameTrackerX.fps30Count = gameTrackerX.fps30Count + 1;
    }
  }
  else
  {
    gameTrackerX.lastLoopTime = 0xffffffff;
  }
  gameTrackerX.currentTime = uVar1;
  return;
}

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

  if (gEndGameNow == 0)
  {
    GAMELOOP_DoTimeProcess();
    if ((gameTrackerX.gameMode != 6) && ((gameTrackerX.streamFlags & 0x100000U) == 0))
    {
      MORPH_UpdateTimeMult();
      GAMELOOP_CalcGameTime();
      if ((gameTracker->gameData).asmData.MorphType == 0)
      {
        bVar1 = true;
        if ((gameTrackerX.playerInstance != (_Instance *)0x0) &&
            (pLVar2 = STREAM_GetWaterZLevel((gameTrackerX.playerInstance)->currentStreamUnitID),
             pLVar2 != (Level *)0x0))
        {
          bVar1 = (pLVar2->unitFlags & 0x2000U) == 0;
        }
        if (bVar1)
        {
          gameTracker->currentTimeOfDayTime =
              gameTracker->currentTimeOfDayTime + gameTracker->lastLoopTime;
        }
        gameTracker->currentMaterialTime =
            gameTracker->currentMaterialTime + gameTracker->lastLoopTime;
      }
      else
      {
        gameTracker->currentSpectralTime =
            gameTracker->currentSpectralTime + gameTracker->lastLoopTime;
      }
    }
    gameTracker->numGSignals = 0;
    GAMELOOP_ChangeMode();
    ResetPrimPool();
    memset(gameTracker->overrideData, 0, 0x28);
    if (gameTrackerX.gameMode != 6)
    {
      if ((gameTrackerX.streamFlags & 0x100000U) == 0)
      {
        if (gameTrackerX.SwitchToNewStreamUnit == 1)
        {
          INSTANCE_Query(gameTrackerX.playerInstance, 0x4000006, 0);
          STREAM_MoveIntoNewStreamUnit();
        }
        if ((VRAM_NeedToUpdateMorph != 0) && (iVar3 = STREAM_IsCdBusy((long *)0x0), iVar3 == 0))
        {
          VRAM_InitMorphPalettes();
          VRAM_NeedToUpdateMorph = 0;
        }
        if ((gameTracker->gameData).asmData.MorphTime < 1000)
        {
          MORPH_Continue();
        }
        if ((gameTracker->streamFlags & 0x80000U) != 0)
        {
          gameTracker->streamFlags = gameTracker->streamFlags & 0xfff7ffff;
          UNDERWORLD_StartProcess();
        }
      }
      if (gameTrackerX.gameMode != 6)
      {
        if ((gameTrackerX.streamFlags & 0x100000U) == 0)
        {
          EVENT_ProcessEvents();
          streamUnit = &StreamTracker;
          do
          {
            if (*(short *)streamUnit->StreamList == 2)
            {
              if ((*(Level **)streamUnit->StreamList)->PuzzleInstances != (EventPointers *)0x0)
              {
                if ((gameTrackerX.debugFlags2 & 0x100U) != 0)
                {
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
        if (gameTrackerX.gameMode != 6)
        {
          EVENT_Process();
        }
      }
    }
    iVar7 = 0;
    streamUnit = &StreamTracker;
    iVar3 = iVar7;
    do
    {
      if ((streamUnit->StreamList[0].used == 2) &&
          (iVar5 = 0, 0 < (streamUnit->StreamList[0].level)->NumberOfSFXMarkers))
      {
        iVar6 = 0;
        do
        {
          ppuVar4 = (u_char **)(*(int *)(*(int *)((int)&StreamTracker.StreamList[0].level + iVar3) + 0xec) +
                                iVar6);
          if ((ppuVar4 != (u_char **)0x0) && (*ppuVar4 != (u_char *)0x0))
          {
            SOUND_StartInstanceSound(*ppuVar4, (SoundInstance *)(ppuVar4 + 2), (_Position *)(ppuVar4 + 5),
                                     (int)ppuVar4[7], (int)ppuVar4[8], 0, (long *)0x0);
          }
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + 0x24;
        } while (iVar5 < (StreamTracker.StreamList[iVar7].level)->NumberOfSFXMarkers);
      }
      iVar3 = iVar3 + 0x40;
      iVar7 = iVar7 + 1;
      streamUnit = (STracker *)(streamUnit->StreamList + 1);
    } while (iVar7 < 0x10);
    if ((gameTrackerX.gameMode != 6) && ((gameTrackerX.streamFlags & 0x100000U) == 0))
    {
      INSTANCE_SpatialRelationships(instanceList);
    }
    INSTANCE_ProcessFunctions(gameTracker->instanceList);
    COLLIDE_InstanceListTerrain(gameTracker->instanceList, 0);
    INSTANCE_Reactivate(gameTracker);
    MONAPI_ProcessGenerator();
    _DAT_1f800000 = theCamera.core.position._0_4_;
    _DAT_1f800004 = theCamera.core._4_4_;
    StackSave = (u_long)&stack0xffffffc0;
    G2Instance_RebuildTransforms(gameTracker->instanceList->first);
    puVar8 = (undefined *)StackSave;
    if (gameTrackerX.gameMode != 6)
    {
      if ((gameTrackerX.streamFlags & 0x100000U) == 0)
      {
        FX_ProcessList(fxTracker);
      }
      puVar8 = (undefined *)StackSave;
      if (gameTrackerX.gameMode != 6)
      {
        if ((gameTrackerX.streamFlags & 0x100000U) == 0)
        {
          VM_Tick(0x100, *(undefined *)StackSave);
          if ((gameTracker->debugFlags2 & 0x10000U) != 0)
          {
            FONT_Print("Military Time %04d\n", *puVar8);
          }
          iVar3 = 0;
          streamUnit = &StreamTracker;
          do
          {
            if (streamUnit->StreamList[0].used == 2)
            {
              VM_ProcessVMObjectList_S(streamUnit->StreamList[0].level, *puVar8);
            }
            iVar3 = iVar3 + 1;
            streamUnit = (STracker *)(streamUnit->StreamList + 1);
          } while (iVar3 < 0x10);
        }
        if ((gameTrackerX.gameMode != 6) && ((gameTrackerX.streamFlags & 0x100000U) == 0))
        {
          PLANAPI_UpdatePlanningDatabase(gameTracker, gameTrackerX.playerInstance, *puVar8);
        }
      }
    }
    DEBUG_ProcessSecondController(gameTracker, *puVar8);
    if ((gameTrackerX.gameMode != 6) && ((gameTrackerX.streamFlags & 0x100000U) == 0))
    {
      COLLIDE_PointAndInstanceTrivialReject(gameTracker->instanceList, *puVar8);
      COLLIDE_Instances(gameTracker->instanceList, *puVar8);
    }
    INSTANCE_AdditionalCollideFunctions(instanceList, *puVar8);
    COLLIDE_InstanceList(instanceList, *puVar8);
    if (gameTrackerX.gameMode != 6)
    {
      if ((gameTrackerX.streamFlags & 0x100000U) == 0)
      {
        LIGHT_CalcShadowPositions(gameTracker, *puVar8);
        COLLIDE_InstanceListTerrain(gameTracker->instanceList, 0x10, *puVar8);
      }
      if (gameTrackerX.gameMode != 6)
      {
        CAMERA_Panic(&theCamera, *puVar8);
      }
    }
    PIPE3D_CalculateWCTransform(&theCamera, *puVar8);
    *(undefined2 *)&(theCamera.core.wcTransform2)->field_0x12 = 0;
    PIPE3D_InstanceListTransformAndDraw(theCamera.core.cwTransform2, theCamera.core.wcTransform2, *puVar8);
    CAMERA_CalcVVClipInfo(&theCamera, *puVar8);
    if (gameTracker->levelChange != 0)
    {
      gameTracker->levelChange = 0;
    }
    SAVE_IntroduceBufferIntros(*puVar8);
    if (gameTracker->levelDone == 0)
    {
      GAMELOOP_DisplayFrame(gameTracker, *puVar8);
    }
    else
    {
      ResetDrawPage(*puVar8);
    }
    gameTracker->frameCount = gameTracker->frameCount + 1;
    gameTracker->debugFlags = gameTracker->debugFlags & 0xf7ffffff;
  }
  else
  {
    DEBUG_ExitGame();
    gameTracker->levelDone = 3;
  }
  return;
}

void GAMELOOP_ModeStartPause(void)

{
  if (((gameTrackerX.gameMode == 4) || (gameTrackerX.gameMode == 6)) &&
      (DEBUG_ExitMenus(), gameTrackerX.gameMode == 6))
  {
    currentMenu = &standardMenu;
    SOUND_PauseAllSound();
    VOICEXA_Pause();
  }
  if ((gameTrackerX.gameFlags & 0x8000000U) != 0)
  {
    gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xf7ffffff;
    gameTrackerX.savedOTStart = (P_TAG *)0x0;
    DrawSync(0);
  }
  gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xefffffff;
  (gameTrackerX.playerInstance)->flags = (gameTrackerX.playerInstance)->flags & 0xfffffeff;
  gameTrackerX.gameMode = 0;
  GAMEPAD_DisplayControllerStatus();
  INSTANCE_Query(gameTrackerX.playerInstance, (int)&DAT_0010000a, 0);
  return;
}

void GAMELOOP_ModeStartRunning(void)

{
  gameTrackerX.gameMode = 6;
  INSTANCE_Query(gameTrackerX.playerInstance, (int)&DAT_0010000a, 1);
  currentMenu = &pauseMenu;
  menu_sound(gameTrackerX.menu, memcard_pause_menu);
  SOUND_ResetAllSound();
  VOICEXA_Resume();
  SndPlay(5);
  gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x10000000;
  GAMEPAD_RestoreControllers();
  gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x8000000;
  if (gameTrackerX.primPool == primPool2)
  {
    gameTrackerX.primPool = PTR_800d1d24;
  }
  else
  {
    gameTrackerX.primPool = primPool2;
  }
  (gameTrackerX.primPool)->nextPrim = (gameTrackerX.primPool)->prim;
  (gameTrackerX.primPool)->numPrims = 0;
  SaveOT();
  return;
}

void GAMELOOP_Set24FPS(void)

{
  gameTrackerX.savedPlayerCameraMode = playerCameraMode;
  playerCameraMode = 0xd;
  return;
}

void GAMELOOP_ChangeMode(void)

{
  u_int uVar1;

  if ((gameTrackerX.debugFlags & 0x40000U) == 0)
  {
    if ((gameTrackerX.debugFlags & 0x200000U) == 0)
    {
      if ((gameTrackerX.controlCommand[0][0] & 0xa01U) == 0xa01)
      {
        theCamera.forced_movement = 1;
        ((gameTrackerX.playerInstance)->position).z =
            ((gameTrackerX.playerInstance)->position).z + 100;
        (gameTrackerX.playerInstance)->zVel = 0;
        gameTrackerX.cheatMode = '\x01';
        INSTANCE_Query(gameTrackerX.playerInstance, (int)&DAT_00100010, 1);
        (gameTrackerX.playerInstance)->flags = (gameTrackerX.playerInstance)->flags & 0xfffff7ff;
      }
      else
      {
        if ((gameTrackerX.controlCommand[0][0] & 0xa02U) == 0xa02)
        {
          theCamera.forced_movement = 1;
          ((gameTrackerX.playerInstance)->position).z =
              ((gameTrackerX.playerInstance)->position).z + -100;
          (gameTrackerX.playerInstance)->zVel = 0;
          gameTrackerX.cheatMode = '\0';
          INSTANCE_Query(gameTrackerX.playerInstance, (int)&DAT_00100010, 0);
          gameTrackerX.gameMode = 0;
        }
      }
    }
    if ((gameTrackerX.debugFlags & 0x40000U) != 0)
      goto LAB_800309c0;
  }
  else
  {
  LAB_800309c0:
    if ((gameTrackerX.playerCheatFlags & 2U) == 0)
      goto LAB_80030ae4;
  }
  if (((gameTrackerX.controlCommand[0][1] & 0x60U) == 0x60) &&
      ((gameTrackerX.controlCommand[0][0] & 0xfU) == 0))
  {
    if (gameTrackerX.gameMode == 0)
    {
      gameTrackerX.gameMode = 4;
      currentMenu = &standardMenu;
      if (gameTrackerX.sound.gVoiceOn == '\0')
      {
        gameTrackerX.debugFlags = gameTrackerX.debugFlags & 0xfff7ffff;
      }
      else
      {
        gameTrackerX.debugFlags = gameTrackerX.debugFlags | 0x80000;
      }
      if (gameTrackerX.sound.gMusicOn == '\0')
      {
        uVar1 = gameTrackerX.debugFlags2 & 0xffffefff;
      }
      else
      {
        uVar1 = gameTrackerX.debugFlags2 | 0x1000;
      }
      if (gameTrackerX.sound.gSfxOn == '\0')
      {
        gameTrackerX.debugFlags2 = uVar1 & 0xffffdfff;
      }
      else
      {
        gameTrackerX.debugFlags2 = uVar1 | 0x2000;
      }
    }
    else
    {
      if (gameTrackerX.gameMode == 7)
      {
        DEBUG_ViewVram(&gameTrackerX);
        gameTrackerX.gameMode = 0;
      }
      else
      {
        GAMELOOP_ModeStartPause();
      }
    }
  }
LAB_80030ae4:
  if ((((((gameTrackerX.controlCommand[0][1] & 0x4000U) == 0) && (gamePadControllerOut < 6)) ||
        (gameTrackerX.gameMode != 0)) ||
       ((gameTrackerX.gameFlags & 0x80U) != 0)) ||
      ((gameTrackerX.wipeTime != 0 &&
        ((gameTrackerX.wipeType == 0xb || (gameTrackerX.wipeTime != -1))))))
  {
    if (((((gameTrackerX.controlCommand[0][1] & 0x4000U) != 0) ||
          ((gameTrackerX.gameFlags & 0x40000000U) != 0)) &&
         ((gameTrackerX.gameMode != 0 && ((gameTrackerX.gameFlags & 0x20000000U) == 0)))) &&
        ((gameTrackerX.wipeTime == 0 ||
          ((gameTrackerX.wipeType != 0xb && (gameTrackerX.wipeTime == -1))))))
    {
      if (((gameTrackerX.controlCommand[0][1] & 0x4000U) != 0) &&
          ((gameTrackerX.gameFlags & 0x40000000U) == 0))
      {
        SndPlay(5);
      }
      gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xbfffffff;
      GAMELOOP_ModeStartPause();
    }
  }
  else
  {
    GAMELOOP_ModeStartRunning();
  }
  if ((gameTrackerX.controlCommand[0][0] & 0x40000000U) == 0)
  {
    if ((gameTrackerX.controlCommand[0][2] & 0x40000000U) != 0)
    {
      (gameTrackerX.playerInstance)->flags = (gameTrackerX.playerInstance)->flags & 0xfffffeff;
    }
  }
  else
  {
    (gameTrackerX.playerInstance)->flags = (gameTrackerX.playerInstance)->flags | 0x100;
  }
  return;
}

void GAMELOOP_RequestLevelChange(char *name, short number, GameTracker *gameTracker)

{
  if (gameTracker->levelChange == 0)
  {
    gameTracker->gameFlags = gameTracker->gameFlags | 1;
    SOUND_StopAllSound();
    sprintf(gameTracker->baseAreaName, "%s%d");
    gameTracker->levelChange = 1;
    gameTracker->levelDone = 1;
  }
  return;
}

void PSX_GameLoop(GameTracker *gameTracker)

{
  DEBUG_Process(gameTracker);
  GAMELOOP_Process(gameTracker);
  return;
}

MATRIX *GAMELOOP_GetTimeOfDayIdx(int numMatrices)

{
  MATRIX *pMVar1;
  MATRIX *pMVar2;

  pMVar2 = (MATRIX *)(gameTrackerX.primPool)->nextPrim;
  pMVar1 = pMVar2 + numMatrices;
  if (pMVar1 < (MATRIX *)(gameTrackerX.primPool)->lastPrim)
  {
    *(MATRIX **)&(gameTrackerX.primPool)->nextPrim = pMVar1;
    return pMVar2;
  }
  return (MATRIX *)0x0;
}

GameTracker *GAMELOOP_GetGT(void)

{
  return &gameTrackerX;
}
