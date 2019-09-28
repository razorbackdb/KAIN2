#include "THISDUST.H"
#include "GAMELOOP.H"

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_AllocStaticMemory()
// line 143, offset 0x8002d7c8
/* begin block 1 */
// Start line: 286
/* end block 1 */
// End Line: 287

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_AllocStaticMemory(void)

{
  /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(0x10c, '\x06');
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_InitGameTracker()
// line 189, offset 0x8002d8b8
/* begin block 1 */
// Start line: 190
// Start offset: 0x8002D8B8

/* begin block 1.1 */
// Start line: 190
// Start offset: 0x8002D8B8
// Variables:
// 		int i; // $t4
/* end block 1.1 */
// End offset: 0x8002D990
// End Line: 264
/* end block 1 */
// End offset: 0x8002D990
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

  DAT_800d0ff0 = GlobalObjects;
  DAT_800d11bc = planningPool;
  DAT_800d11c0 = enemyPlanPool;
  DAT_800d0fe8 = gVertexPool;
  primPool2->lastPrim = primPool2->prim + 0x5db4;
  DAT_800d0fe0 = instanceList;
  PTR_800d0c18->lastPrim = PTR_800d0c18->prim + 0x5db4;
  DAT_800d10c0 = gLightInfo;
  primPool2->nextPrim = primPool2->prim;
  DAT_800d0fe4 = instancePool;
  PTR_800d0c18->nextPrim = PTR_800d0c18->prim;
  iVar2 = 0;
  iVar1 = 0;
  DAT_800d11cc = 10;
  DAT_800d11d2 = 0x1000;
  DAT_800d11d0 = 0;
  DAT_800d11c8 = 1;
  ULONG_800d1214 = 1;
  DAT_800d0fec = primPool2;
  DAT_800d1180 = gOt2;
  DAT_800d1184 = PTR_800d0c10;
  ULONG_800d1218._0_2_ = 1;
  do
  {
    iVar2 = iVar2 + 1;
    *(undefined2 *)((int)&DAT_800d0ff0->objectStatus + iVar1) = 0;
    iVar1 = iVar1 + 0x24;
  } while (iVar2 < 0x30);
  DAT_800d0fb4 = 1000;
  OBTABLE_ClearObjectReferences();
  EVENT_Init();
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_SystemInit(struct GameTracker *gameTracker /*$a0*/)
// line 285, offset 0x8002d9b8
/* begin block 1 */
// Start line: 804
/* end block 1 */
// End Line: 805

void GAMELOOP_SystemInit(GameTracker *gameTracker)

{
  GAMELOOP_AllocStaticMemory();
  INSTANCE_InitInstanceList(instanceList, instancePool);
  GAMELOOP_InitGameTracker();
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_ResetGameStates()
// line 298, offset 0x8002d9f0
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
// line 304, offset 0x8002da10
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
  gameTrackerX = 0;
  DAT_800d0fb4 = 1000;
  vmRealClock = vmRealClock | 0x40000;
  DAT_800d10d8 = 0;
  DAT_800d10dc = 0;
  DAT_800d10ec = 0;
  DAT_800d1120 = 0;
  DAT_800d1128 = 0;
  DAT_800d11d8 = 0;
  ULONG_800d11fc = 0;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_CalcGameTime()
// line 334, offset 0x8002da58
/* begin block 1 */
// Start line: 336
// Start offset: 0x8002DA58
// Variables:
// 		long time; // $a1
/* end block 1 */
// End offset: 0x8002DA58
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

  iVar2 = (uint)(DAT_800d11e4 * DAT_800d11cc) / 60000 + 0x2d0;
  iVar1 = iVar2 / 0x3c;
  DAT_800d11c6 = (short)iVar1 * 0x28 +
                 ((short)(iVar1 / 6 + (iVar1 >> 0x1f) >> 2) - (short)(iVar1 >> 0x1f)) * -0x960 +
                 (short)iVar2;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_SetGameTime(long timeOfDay /*$a1*/)
// line 345, offset 0x8002db04
/* begin block 1 */
// Start line: 346
// Start offset: 0x8002DB04
// Variables:
// 		long tim; // $v1
/* end block 1 */
// End offset: 0x8002DB5C
// End Line: 352

/* begin block 2 */
// Start line: 942
/* end block 2 */
// End Line: 943

void FONT_SetColorIndexCol(int color, int r, int g, int b)

{
  int iVar1;
  int iVar2;

  iVar1 = color + (color / 100) * -0x28;
  iVar2 = iVar1 + -0x2d0;
  if (iVar2 < 0)
  {
    iVar2 = iVar1 + 0x2d0;
  }
  fontTracker.font_buffer[138]._0_4_ = (iVar2 * 60000) / fontTracker.font_buffer[135]._2_4_;
  /* WARNING: Read-only address (ram,0x800d2caa) is written */
  fontTracker.font_buffer[134].y = (short)color;
  fontTracker.font_buffer[139]._2_4_ = fontTracker.font_buffer[138]._0_4_;
  /* WARNING: Read-only address (ram,0x800d2cc8) is written */
  /* WARNING: Read-only address (ram,0x800d2cc0) is written */
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ GAMELOOP_GetTimeOfDay()
// line 362, offset 0x8002db98
/* begin block 1 */
// Start line: 364
// Start offset: 0x8002DB98
// Variables:
// 		int timeOfDay; // $v1
/* end block 1 */
// End offset: 0x8002DBDC
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

  iVar2 = (int)DAT_800d11c6;
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

// decompiled code
// original method signature:
// int /*$ra*/ GAMELOOP_GetTimeOfDayIdx(int timeOfDay /*$a0*/)
// line 391, offset 0x8002dbe4
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

// decompiled code
// original method signature:
// int /*$ra*/ GAMELOOP_WaitForLoad()
// line 819, offset 0x8002dc28
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

  if ((vmRealClock & 0x80000U) != 0)
  {
    VOICEXA_Tick();
  }
  iVar1 = STREAM_PollLoadQueue();
  return iVar1;
}

// decompiled code
// original method signature:
// struct _StreamUnit * /*$ra*/ LoadLevels(char *baseAreaName /*$s2*/, struct GameTracker *gameTracker /*$s4*/)
// line 836, offset 0x8002dc60
/* begin block 1 */
// Start line: 837
// Start offset: 0x8002DC60
// Variables:
// 		struct _SVector offset; // stack offset -32
// 		struct _StreamUnit *streamUnit; // $s0
// 		static char oldArea[16]; // offset 0xc
// 		int cd; // $s3

/* begin block 1.1 */
// Start line: 862
// Start offset: 0x8002DCEC
// Variables:
// 		int num; // $v0
// 		int waitFor; // $s1
/* end block 1.1 */
// End offset: 0x8002DD88
// End Line: 897

/* begin block 1.2 */
// Start line: 928
// Start offset: 0x8002DE24
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
// End offset: 0x8002DE24
// End Line: 928
/* end block 1 */
// End offset: 0x8002DE24
// End Line: 928

/* begin block 2 */
// Start line: 1947
/* end block 2 */
// End Line: 1948

/* begin block 3 */
// Start line: 1953
/* end block 3 */
// End Line: 1954

_StreamUnit *LoadLevels(char *baseAreaName, GameTracker *gameTracker)

{
  if (DAT_800ce2b0 != '\0')
  {
    STREAM_AbortAreaLoad(&DAT_800ce2b0);
  }
  /* WARNING: Subroutine does not return */
  strcpy(&DAT_800ce2b0, baseAreaName);
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_InitStandardObjects()
// line 937, offset 0x8002debc
/* begin block 1 */
// Start line: 938
// Start offset: 0x8002DEBC
// Variables:
// 		static char (*sobjects[10]); // offset 0x0
// 		int i; // $s1
/* end block 1 */
// End offset: 0x8002DEFC
// End Line: 953

/* begin block 2 */
// Start line: 2169
/* end block 2 */
// End Line: 2170

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_InitStandardObjects(void)

{
  char *name;
  char **ppcVar1;
  uint uVar2;

  LOAD_DumpCurrentDir();
  uVar2 = 0;
  ppcVar1 = (char **)&DebugMenuLine_800c8720.bit_mask;
  do
  {
    name = *ppcVar1;
    ppcVar1 = ppcVar1 + 1;
    uVar2 = uVar2 + 1;
    InsertGlobalObject(name, (GameTracker *)&gameTrackerX);
  } while (uVar2 < 10);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_LevelLoadAndInit(char *baseAreaName /*$s0*/, struct GameTracker *gameTracker /*$s3*/)
// line 956, offset 0x8002df10
/* begin block 1 */
// Start line: 957
// Start offset: 0x8002DF10
// Variables:
// 		long i; // $s1
// 		struct _StreamUnit *streamUnit; // $s2

/* begin block 1.1 */
// Start line: 1035
// Start offset: 0x8002E03C
// Variables:
// 		short _x1; // $v0
// 		short _y1; // $a0
// 		short _z1; // $v1
// 		struct _Position *_v0; // $v0
// 		struct _Position *_v1; // $v1
/* end block 1.1 */
// End offset: 0x8002E03C
// End Line: 1035
/* end block 1 */
// End offset: 0x8002E204
// End Line: 1140

/* begin block 2 */
// Start line: 2211
/* end block 2 */
// End Line: 2212

void GAMELOOP_LevelLoadAndInit(char *baseAreaName, GameTracker *gameTracker)

{
  long *plVar1;
  _InstanceList *list;
  _InstancePool *pool;
  _StreamUnit *p_Var2;
  int iVar3;
  _Instance *p_Var4;
  _MultiSignal *p_Var5;

  _G2Anim_AllocateInterpStateBlockList((_G2AnimSection_Type *)baseAreaName);
  pool = instancePool;
  list = instanceList;
  gameTracker->playerInstance = (_Instance *)0x0;
  INSTANCE_InitInstanceList(list, pool);
  GAMELOOP_ClearGameTracker();
  CAMERA_Initialize((Camera *)&theCamera);
  PLANAPI_InitPlanning(planningPool);
  ENMYPLAN_InitEnemyPlanPool(enemyPlanPool);
  FX_Init(fxTracker);
  WARPGATE_Init();
  DRAW_InitShadow();
  GAMELOOP_InitStandardObjects();
  p_Var2 = LoadLevels(baseAreaName, gameTracker);
  do
  {
    iVar3 = STREAM_PollLoadQueue();
    plVar1 = DebugMenuLine_800c8780.var_address;
  } while (iVar3 != 0);
  *(DEBUG_LINE_TYPE *)&gameTracker->introFX = debugForgedAbilitiesMenu.type;
  RENDER_currentStreamUnitID = *(short *)&gameTracker->StreamUnitID;
  fontsObject = (Object *)plVar1;
  if (0 < p_Var2->level->numIntros)
  {
    /* WARNING: Subroutine does not return */
    strcmpi((char *)p_Var2->level->introList, s_raziel_800ce310);
  }
  gameTracker->playerInstance->data = gameTracker->playerInstance->object->data;
  CAMERA_SetInstanceFocus((Camera *)&theCamera, gameTracker->playerInstance);
  p_Var4 = gameTracker->playerInstance;
  theCamera = (p_Var4->position).x;
  DAT_800cfe92 = (p_Var4->position).y;
  DAT_800cfe94 = (p_Var4->position).z;
  SetFogNearFar((uint)p_Var2->level->fogNear, (uint)p_Var2->level->fogFar, 0x140);
  SetFarColor(0, 0, 0);
  clearRect[0].r0 = p_Var2->level->backColorR;
  /* WARNING: Read-only address (ram,0x800d0f8c) is written */
  clearRect[0].g0 = p_Var2->level->backColorG;
  /* WARNING: Read-only address (ram,0x800d0f8d) is written */
  clearRect[0].b0 = p_Var2->level->backColorB;
  /* WARNING: Read-only address (ram,0x800d0f8e) is written */
  clearRect[1].r0 = p_Var2->level->backColorR;
  /* WARNING: Read-only address (ram,0x800d0f9c) is written */
  clearRect[1].g0 = p_Var2->level->backColorG;
  /* WARNING: Read-only address (ram,0x800d0f9d) is written */
  clearRect[1].b0 = p_Var2->level->backColorB;
  /* WARNING: Read-only address (ram,0x800d0f9e) is written */
  gameTracker->wipeType = 10;
  gameTracker->hideBG = 0;
  gameTracker->wipeTime = 0x1e;
  gameTracker->maxWipeTime = 0x1e;
  p_Var5 = p_Var2->level->startSignal;
  if (p_Var5 != (_MultiSignal *)0x0)
  {
    p_Var5->flags = p_Var5->flags | 1;
    SIGNAL_HandleSignal(gameTracker->playerInstance, p_Var2->level->startSignal->signalList, 0);
    EVENT_AddSignalToReset(p_Var2->level->startSignal);
  }
  gameTracker->vblFrames = 0;
  p_Var5 = p_Var2->level->startUnitMainSignal;
  if ((p_Var5 != (_MultiSignal *)0x0) && (gameTracker->playerInstance != (_Instance *)0x0))
  {
    p_Var5->flags = p_Var5->flags | 1;
    SIGNAL_HandleSignal(gameTracker->playerInstance, p_Var2->level->startUnitMainSignal->signalList, 0);
    EVENT_AddSignalToReset(p_Var2->level->startUnitMainSignal);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_StreamLevelLoadAndInit(char *baseAreaName /*$a0*/, struct GameTracker *gameTracker /*$a1*/, int toSignalNum /*$a2*/, int fromSignalNum /*$a3*/)
// line 1143, offset 0x8002e220
/* begin block 1 */
// Start line: 1144
// Start offset: 0x8002E220
/* end block 1 */
// End offset: 0x8002E220
// End Line: 1144

/* begin block 2 */
// Start line: 2613
/* end block 2 */
// End Line: 2614

void GAMELOOP_StreamLevelLoadAndInit(char *param_1, GameTracker *param_2)

{
  LoadLevels(param_1, param_2);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_SetScreenWipe(int time /*$a0*/, int maxTime /*$a1*/, int type /*$a2*/)
// line 1162, offset 0x8002e240
/* begin block 1 */
// Start line: 2651
/* end block 1 */
// End Line: 2652

/* begin block 2 */
// Start line: 2652
/* end block 2 */
// End Line: 2653

void GAMELOOP_SetScreenWipe(int time, int maxTime, int type)

{
  DAT_800d1078 = (short)time;
  DAT_800d107a = (short)maxTime;
  DAT_800d107c = (short)type;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_HandleScreenWipes(unsigned long **drawot /*$s4*/)
// line 1170, offset 0x8002e254
/* begin block 1 */
// Start line: 1171
// Start offset: 0x8002E254
// Variables:
// 		long temp; // $s0
// 		struct _PrimPool *primPool; // $s3
/* end block 1 */
// End offset: 0x8002E694
// End Line: 1519

/* begin block 2 */
// Start line: 2667
/* end block 2 */
// End Line: 2668

/* begin block 3 */
// Start line: 2682
/* end block 3 */
// End Line: 2683

void GAMELOOP_HandleScreenWipes(ulong **drawot)

{
  _PrimPool *primPool;
  int r;

  primPool = DAT_800d0fec;
  if ((GlobalSave->flags & 1U) != 0)
  {
    DRAW_FlatQuad((CVECTOR *)&DAT_800d1074, 0, 0, 0x200, 0, 0, 0x1e, 0x200, 0x1e, DAT_800d0fec, drawot);
    DRAW_FlatQuad((CVECTOR *)&DAT_800d1074, 0, 0xd2, 0x200, 0xd2, 0, 0xf0, 0x200, 0xf0, primPool, drawot);
  }
  r = (int)DAT_800d1078;
  if (r < 1)
  {
    if (r < -1)
    {
      if (DAT_800d107c == 10)
      {
        r = (int)(short)((((int)DAT_800d107a + r + 2) * 0xff) / (int)DAT_800d107a);
        DRAW_TranslucentQuad(0, 0, 0x200, 0, 0, 0xf0, 0x200, 0xf0, r, r, r, 2, primPool, drawot);
      }
      else
      {
        if (DAT_800d107c == 0xb)
        {
          r = (int)(short)((((int)DAT_800d107a + r) * 0xff) / (int)DAT_800d107a);
          DRAW_TranslucentQuad(0, 0, 0x200, 0, 0, 0x1e, 0x200, 0x1e, r, r, r, 2, primPool, drawot);
          DRAW_TranslucentQuad(0, 0xd2, 0x200, 0xd2, 0, 0xf0, 0x200, 0xf0, r, r, r, 2, primPool, drawot);
          if (DAT_800d1078 == -2)
          {
            GlobalSave->flags = GlobalSave->flags | 1;
          }
        }
      }
      if (ULONG_800d120c != 0)
      {
        DAT_800d1078 = DAT_800d1078 + 1;
      }
    }
    else
    {
      if (r == -1)
      {
        if (DAT_800d107c == 0xb)
        {
          GlobalSave->flags = GlobalSave->flags | 1;
        }
        else
        {
          DRAW_FlatQuad((CVECTOR *)&DAT_800d1074, 0, 0, 0x200, 0, 0, 0xf0, 0x200, 0xf0, primPool, drawot);
        }
      }
      else
      {
        DAT_800cff4e = 0x1000;
        DAT_800cff4c = 0x1000;
        DAT_800cff4a = 0x1000;
      }
    }
  }
  else
  {
    if (DAT_800d107c == 10)
    {
      r = (int)(short)((r * 0xff) / (int)DAT_800d107a);
      DRAW_TranslucentQuad(0, 0, 0x200, 0, 0, 0xf0, 0x200, 0xf0, r, r, r, 2, primPool, drawot);
    }
    else
    {
      if (DAT_800d107c == 0xb)
      {
        r = (int)(short)((r * 0xff) / (int)DAT_800d107a);
        DRAW_TranslucentQuad(0, 0, 0x200, 0, 0, 0x1e, 0x200, 0x1e, r, r, r, 2, primPool, drawot);
        DRAW_TranslucentQuad(0, 0xd2, 0x200, 0xd2, 0, 0xf0, 0x200, 0xf0, r, r, r, 2, primPool, drawot);
        GlobalSave->flags = GlobalSave->flags & 0xfffe;
      }
    }
    if (ULONG_800d120c != 0)
    {
      DAT_800d1078 = DAT_800d1078 + -1;
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ UpdateFogSettings(struct _StreamUnit *currentUnit /*$s2*/, struct Level *level /*$s0*/)
// line 1662, offset 0x8002e6b4
/* begin block 1 */
// Start line: 1663
// Start offset: 0x8002E6B4
// Variables:
// 		int changed; // $a2
// 		int setflag; // $s1
// 		int FogFar; // $a1
// 		int FogNear; // $a0
/* end block 1 */
// End offset: 0x8002E7C4
// End Line: 1710

/* begin block 2 */
// Start line: 3668
/* end block 2 */
// End Line: 3669

void UpdateFogSettings(_StreamUnit *currentUnit, Level *level)

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
  if (iVar7 < (int)uVar6)
  {
    level->fogNear = (ushort)(uVar6 - 500);
    bVar3 = iVar7 < (int)(uVar6 - 500 & 0xffff);
  LAB_8002e720:
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
      level->fogNear = (ushort)(uVar6 + 500);
      bVar3 = (int)(uVar6 + 500 & 0xffff) < iVar7;
      goto LAB_8002e720;
    }
    bVar5 = true;
  }
  uVar6 = (uint)level->fogFar;
  if (iVar8 < (int)uVar6)
  {
    level->fogFar = (ushort)(uVar6 - 500);
    bVar4 = true;
    if (iVar8 < (int)(uVar6 - 500 & 0xffff))
    {
      bVar5 = false;
      goto LAB_8002e794;
    }
  }
  else
  {
    if (iVar8 <= (int)uVar6)
      goto LAB_8002e794;
    level->fogFar = (ushort)(uVar6 + 500);
    bVar4 = true;
    if ((int)(uVar6 + 500 & 0xffff) < iVar8)
    {
      bVar5 = false;
      goto LAB_8002e794;
    }
  }
  bVar4 = true;
  level->fogFar = uVar2;
LAB_8002e794:
  if ((bVar4) && (LIGHT_CalcDQPTable(level), bVar5))
  {
    currentUnit->TargetFogNear = level->fogNear;
    currentUnit->TargetFogFar = level->fogFar;
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ CheckForNoBlend(struct _ColorType *Color /*$a0*/)
// line 1712, offset 0x8002e7dc
/* begin block 1 */
// Start line: 3779
/* end block 1 */
// End Line: 3780

/* begin block 2 */
// Start line: 3780
/* end block 2 */
// End Line: 3781

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

// decompiled code
// original method signature:
// void /*$ra*/ BlendToColor(struct _ColorType *target /*$s1*/, struct _ColorType *current /*$a1*/, struct _ColorType *dest /*$s0*/)
// line 1722, offset 0x8002e824
/* begin block 1 */
// Start line: 3799
/* end block 1 */
// End Line: 3800

void BlendToColor(_ColorType *target, _ColorType *current, _ColorType *dest)

{
  int iVar1;

  LoadAverageCol((byte *)target, (byte *)current, 0x200, 0xe00, (undefined *)dest);
  iVar1 = (uint)target->r - (uint)dest->r;
  if (iVar1 < 0)
  {
    if (4 < (int)((uint)dest->r - (uint)target->r))
      goto LAB_8002e900;
  }
  else
  {
    if (4 < iVar1)
    {
      dest->code = '\0';
      return;
    }
  }
  iVar1 = (uint)target->g - (uint)dest->g;
  if (iVar1 < 0)
  {
    if (4 < (int)((uint)dest->g - (uint)target->g))
      goto LAB_8002e900;
  }
  else
  {
    if (4 < iVar1)
    {
      dest->code = '\0';
      return;
    }
  }
  iVar1 = (uint)target->b - (uint)dest->b;
  if (iVar1 < 0)
  {
    if (4 < (int)((uint)dest->b - (uint)target->b))
      goto LAB_8002e900;
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
LAB_8002e900:
  dest->code = '\0';
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MainRenderLevel(struct _StreamUnit *currentUnit /*$s7*/, unsigned long **drawot /*$fp*/)
// line 1739, offset 0x8002e918
/* begin block 1 */
// Start line: 1740
// Start offset: 0x8002E918
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
// Start line: 1792
// Start offset: 0x8002E9E8
// Variables:
// 		int time; // $a2
/* end block 1.1 */
// End offset: 0x8002EA1C
// End Line: 1798

/* begin block 1.2 */
// Start line: 1806
// Start offset: 0x8002EA68
// Variables:
// 		int tod; // $v1
/* end block 1.2 */
// End offset: 0x8002EAE4
// End Line: 1820

/* begin block 1.3 */
// Start line: 1898
// Start offset: 0x8002EC00
// Variables:
// 		struct _SVector tmp; // stack offset -56
// 		struct BSPTree *bsp; // $s0
/* end block 1.3 */
// End offset: 0x8002ECF8
// End Line: 1955
/* end block 1 */
// End offset: 0x8002EDDC
// End Line: 1975

/* begin block 2 */
// Start line: 3834
/* end block 2 */
// End Line: 3835

/* WARNING: This function may have set the stack pointer */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MainRenderLevel(_StreamUnit *currentUnit, ulong **drawot)

{
  MATRIX *pMVar1;
  LightInfo *lightInfo;
  ushort uVar2;
  int unitID;
  uint uVar3;
  Level *level;
  int iVar4;
  int iVar5;
  _Terrain *terrain;
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
  _ColorType local_30[2];

  level = currentUnit->level;
  terrain = level->terrain;
  UpdateFogSettings(currentUnit, level);
  currentUnit->FrameCount = DAT_800d10d4;
  SetFogNearFar((uint)level->fogNear, (uint)level->fogFar, 0x140);
  SetFarColor(0, 0, 0);
  clearRect[0].r0 = level->backColorR;
  /* WARNING: Read-only address (ram,0x800d0f8c) is written */
  clearRect[0].g0 = level->backColorG;
  /* WARNING: Read-only address (ram,0x800d0f8d) is written */
  clearRect[0].b0 = level->backColorB;
  /* WARNING: Read-only address (ram,0x800d0f8e) is written */
  clearRect[1].r0 = level->backColorR;
  /* WARNING: Read-only address (ram,0x800d0f9c) is written */
  clearRect[1].g0 = level->backColorG;
  /* WARNING: Read-only address (ram,0x800d0f9d) is written */
  clearRect[1].b0 = level->backColorB;
  /* WARNING: Read-only address (ram,0x800d0f9e) is written */
  if ((int)DAT_800d0fb4 == 1000)
  {
    if (DAT_800d0fb6 == 1)
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
    unitID = ((int)DAT_800d0fb4 << 0xc) / 1000;
    if (DAT_800d0fb6 == 1)
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
      (DAT_800d0fb4 == 1000))
  {
    depthQBackColor = depthQBackColor & 0xfff8f8f8 | 0x40404;
  }
  depthQFogStart = (uint)level->fogNear;
  depthQFogFar = (uint)level->fogFar;
  unitID = CheckForNoBlend((_ColorType *)&depthQBackColor);
  depthQBlendStart = 0xffff;
  if (unitID == 0)
  {
    depthQBlendStart = depthQFogStart;
  }
  /* WARNING: Read-only address (ram,0x800d0f8c) is written */
  clearRect[0].r0 = (uchar)depthQBackColor;
  /* WARNING: Read-only address (ram,0x800d0f8d) is written */
  clearRect[0].g0 = depthQBackColor._1_1_;
  /* WARNING: Read-only address (ram,0x800d0f8e) is written */
  clearRect[0].b0 = depthQBackColor._2_1_;
  /* WARNING: Read-only address (ram,0x800d0f9c) is written */
  clearRect[1].r0 = (uchar)depthQBackColor;
  /* WARNING: Read-only address (ram,0x800d0f9d) is written */
  clearRect[1].g0 = depthQBackColor._1_1_;
  /* WARNING: Read-only address (ram,0x800d0f9e) is written */
  clearRect[1].b0 = depthQBackColor._2_1_;
  PIPE3D_AnimateTerrainTextures(terrain->aniList, DAT_800d10d8, DAT_800d0fec, drawot);
  PIPE3D_AnimateTerrainTextures(level->bgAniList, DAT_800d10d8, DAT_800d0fec, drawot);
  gLightInfo->numSavedColors = 0;
  PIPE3D_InstanceListTransformAndDraw(currentUnit, (GameTracker *)&gameTrackerX, drawot, (_CameraCore_Type *)&theCamera);
  lightInfo = gLightInfo;
  pMVar1 = DAT_800cfef0;
  local_60 = _theCamera;
  local_5c = DAT_800cfe94;
  local_58 = *(undefined4 *)DAT_800cfef0->m;
  local_54 = *(undefined4 *)(DAT_800cfef0->m + 2);
  local_50 = *(undefined4 *)(DAT_800cfef0->m + 4);
  local_4c = *(undefined4 *)(DAT_800cfef0->m + 6);
  local_48 = *(undefined4 *)(DAT_800cfef0->m + 8);
  local_44 = DAT_800cfef0->t[0];
  local_40 = DAT_800cfef0->t[1];
  local_3c = DAT_800cfef0->t[2];
  unitID = 0;
  if (0 < terrain->numBSPTrees)
  {
    iVar5 = 0;
    do
    {
      iVar4 = (int)&terrain->BSPTreeArray->bspRoot + iVar5;
      if ((-1 < *(short *)(iVar4 + 0x1a)) && ((*(ushort *)(iVar4 + 0x12) & 1) == 0))
      {
        if ((*(ushort *)(iVar4 + 0x12) & 0x40) != 0)
        {
          DAT_800d0fb8 = 0;
        }
        local_60._2_2_ = (short)(_theCamera >> 0x10);
        uVar3 = (_theCamera & 0xffff) - (uint) * (ushort *)(iVar4 + 0xc);
        local_38 = -(short)uVar3;
        uVar2 = local_60._2_2_ - *(short *)(iVar4 + 0xe);
        _theCamera = uVar3 & 0xffff | (uint)uVar2 << 0x10;
        local_36 = -uVar2;
        DAT_800cfe94 = DAT_800cfe94 - *(short *)(iVar4 + 0x10);
        local_34 = -DAT_800cfe94;
        /* WARNING: Subroutine does not return */
        ApplyMatrix(&local_58, &local_38, DAT_800cfef0->t);
      }
      unitID = unitID + 1;
      iVar5 = iVar5 + 0x24;
    } while (unitID < terrain->numBSPTrees);
  }
  unitID = (int)RENDER_currentStreamUnitID;
  *(undefined4 *)DAT_800cfef0->m = local_58;
  *(undefined4 *)(pMVar1->m + 2) = local_54;
  *(undefined4 *)(pMVar1->m + 4) = local_50;
  *(undefined4 *)(pMVar1->m + 6) = local_4c;
  *(undefined4 *)(pMVar1->m + 8) = local_48;
  pMVar1->t[0] = local_44;
  pMVar1->t[1] = local_40;
  pMVar1->t[2] = local_3c;
  SBSP_IntroduceInstancesAndLights(terrain, (_CameraCore_Type *)&theCamera, lightInfo, unitID);
  StackSave = (ulong)&stack0xffffff88;
  FX_DrawList(fxTracker, (GameTracker *)&gameTrackerX, DAT_800d1180, DAT_800cfef0);
  if (*(int *)(DAT_800d0fd8 + 0x38) == currentUnit->StreamUnitID)
  {
    FX_DrawReaver(DAT_800d0fec, DAT_800d1180, DAT_800cfef0);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ StreamIntroInstancesForUnit(struct _StreamUnit *currentUnit /*$a1*/)
// line 1982, offset 0x8002ee18
/* begin block 1 */
// Start line: 1983
// Start offset: 0x8002EE18
/* end block 1 */
// End offset: 0x8002EE48
// End Line: 1995

/* begin block 2 */
// Start line: 4500
/* end block 2 */
// End Line: 4501

void StreamIntroInstancesForUnit(_StreamUnit *currentUnit)

{
  if (currentUnit->used == 2)
  {
    SBSP_IntroduceInstances(currentUnit->level->terrain, currentUnit->StreamUnitID);
  }
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ StreamRenderLevel(struct _StreamUnit *currentUnit /*$s7*/, struct Level *mainLevel /*$a1*/, unsigned long **drawot /*$s6*/, long portalFogColor /*$s0*/)
// line 1999, offset 0x8002ee58
/* begin block 1 */
// Start line: 2000
// Start offset: 0x8002EE58
// Variables:
// 		struct GameTracker *gameTracker; // $s4
// 		struct Level *level; // $s1
// 		struct _Terrain *terrain; // $s2
// 		int curTree; // $s1
// 		int farplanesave; // $fp
// 		struct _Position cam_pos_save; // stack offset -88
// 		struct MATRIX cam_mat_save; // stack offset -80

/* begin block 1.1 */
// Start line: 2085
// Start offset: 0x8002EFBC
// Variables:
// 		struct _SVector tmp; // stack offset -48
// 		struct BSPTree *bsp; // $s0
/* end block 1.1 */
// End offset: 0x8002F088
// End Line: 2133

/* begin block 1.2 */
// Start line: 2151
// Start offset: 0x8002F134
/* end block 1.2 */
// End offset: 0x8002F168
// End Line: 2161
/* end block 1 */
// End offset: 0x8002F168
// End Line: 2163

/* begin block 2 */
// Start line: 4534
/* end block 2 */
// End Line: 4535

/* WARNING: This function may have set the stack pointer */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long StreamRenderLevel(_StreamUnit *currentUnit, Level *mainLevel, ulong **drawot, long portalFogColor)

{
  MATRIX *pMVar1;
  undefined4 uVar2;
  LightInfo *lightInfo;
  int unitID;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  Level *level;
  _Terrain *terrain;
  int iVar6;
  undefined auStack112[24];
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

  uVar2 = DAT_800cfef4;
  level = currentUnit->level;
  terrain = level->terrain;
  SetFarColor(0, 0, 0);
  UpdateFogSettings(currentUnit, level);
  depthQFogFar = (uint)level->fogFar;
  depthQFogStart = (uint)level->fogNear;
  depthQBackColor = portalFogColor;
  currentUnit->FogColor = portalFogColor;
  DAT_800cfef4 = depthQFogFar;
  unitID = CheckForNoBlend((_ColorType *)&depthQBackColor);
  depthQBlendStart = 0xffff;
  if (unitID == 0)
  {
    depthQBlendStart = depthQFogStart;
  }
  SetFogNearFar(depthQFogStart, depthQFogFar, 0x140);
  PIPE3D_AnimateTerrainTextures(terrain->aniList, DAT_800d10d8, DAT_800d0fec, drawot);
  PIPE3D_AnimateTerrainTextures(level->bgAniList, DAT_800d10d8, DAT_800d0fec, drawot);
  PIPE3D_InstanceListTransformAndDraw(currentUnit, (GameTracker *)&gameTrackerX, drawot, (_CameraCore_Type *)&theCamera);
  lightInfo = gLightInfo;
  pMVar1 = DAT_800cfef0;
  local_58 = _theCamera;
  local_54 = DAT_800cfe94;
  local_50 = *(undefined4 *)DAT_800cfef0->m;
  local_4c = *(undefined4 *)(DAT_800cfef0->m + 2);
  local_48 = *(undefined4 *)(DAT_800cfef0->m + 4);
  local_44 = *(undefined4 *)(DAT_800cfef0->m + 6);
  local_40 = *(undefined4 *)(DAT_800cfef0->m + 8);
  local_3c = DAT_800cfef0->t[0];
  local_38 = DAT_800cfef0->t[1];
  local_34 = DAT_800cfef0->t[2];
  unitID = 0;
  if (0 < terrain->numBSPTrees)
  {
    iVar6 = 0;
    do
    {
      iVar5 = (int)&terrain->BSPTreeArray->bspRoot + iVar6;
      if ((-1 < *(short *)(iVar5 + 0x1a)) && ((*(ushort *)(iVar5 + 0x12) & 1) == 0))
      {
        local_58._2_2_ = (short)(_theCamera >> 0x10);
        uVar4 = (_theCamera & 0xffff) - (uint) * (ushort *)(iVar5 + 0xc);
        local_30 = -(short)uVar4;
        uVar3 = local_58._2_2_ - *(short *)(iVar5 + 0xe);
        _theCamera = uVar4 & 0xffff | (uint)uVar3 << 0x10;
        local_2e = -uVar3;
        DAT_800cfe94 = DAT_800cfe94 - *(short *)(iVar5 + 0x10);
        local_2c = -DAT_800cfe94;
        /* WARNING: Subroutine does not return */
        ApplyMatrix(&local_50, &local_30, DAT_800cfef0->t);
      }
      unitID = unitID + 1;
      iVar6 = iVar6 + 0x24;
    } while (unitID < terrain->numBSPTrees);
  }
  unitID = (int)RENDER_currentStreamUnitID;
  InStreamUnit = 1;
  *(undefined4 *)DAT_800cfef0->m = local_50;
  *(undefined4 *)(pMVar1->m + 2) = local_4c;
  *(undefined4 *)(pMVar1->m + 4) = local_48;
  *(undefined4 *)(pMVar1->m + 6) = local_44;
  *(undefined4 *)(pMVar1->m + 8) = local_40;
  pMVar1->t[0] = local_3c;
  pMVar1->t[1] = local_38;
  pMVar1->t[2] = local_34;
  SBSP_IntroduceInstancesAndLights(terrain, (_CameraCore_Type *)&theCamera, lightInfo, unitID);
  InStreamUnit = 0;
  DAT_800cfef4 = uVar2;
  if (*(int *)(DAT_800d0fd8 + 0x38) == currentUnit->StreamUnitID)
  {
    hackOT = drawot;
    StackSave = (ulong)auStack112;
    FX_DrawReaver(DAT_800d0fec, drawot, DAT_800cfef0);
  }
  return 0;
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_FlipScreenAndDraw(struct GameTracker *gameTracker /*$s0*/, unsigned long **drawot /*$a1*/)
// line 2187, offset 0x8002f1a0
/* begin block 1 */
// Start line: 5067
/* end block 1 */
// End Line: 5068

void GAMELOOP_FlipScreenAndDraw(GameTracker *gameTracker, ulong **drawot)

{
  int iVar1;
  uint uVar2;

  DrawOTag(drawot + 0xbff);
  do
  {
    iVar1 = CheckVolatile(gameTracker->drawTimerReturn);
  } while (iVar1 != 0);
  ResetPrimPool();
  PutDrawEnv((undefined4 *)(&draw + gameTracker->drawPage));
  do
  {
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
// line 2219, offset 0x8002f254
/* begin block 1 */
// Start line: 2220
// Start offset: 0x8002F254

/* begin block 1.1 */
// Start line: 2224
// Start offset: 0x8002F270
// Variables:
// 		struct BLK_FILL *blkfill; // $a0
/* end block 1.1 */
// End offset: 0x8002F270
// End Line: 2224

/* begin block 1.2 */
// Start line: 2240
// Start offset: 0x8002F2DC
// Variables:
// 		struct BLK_FILL *blkfill; // $v1
/* end block 1.2 */
// End offset: 0x8002F2F4
// End Line: 2242
/* end block 1 */
// End offset: 0x8002F2F4
// End Line: 2243

/* begin block 2 */
// Start line: 5138
/* end block 2 */
// End Line: 5139

/* begin block 3 */
// Start line: 5140
/* end block 3 */
// End Line: 5141

void GAMELOOP_AddClearPrim(ulong **drawot, int override)

{
  ulong *puVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;

  if (((DAT_800d10ec & 0x8000000) != 0) && (override == 0))
  {
    *(ushort *)(DAT_800d1188 + 10) = clearRect[DAT_800d0fdc].y0;
    return;
  }
  puVar1 = *(ulong **)(DAT_800d0fec + 4);
  uVar2 = *(ulong *)&clearRect[DAT_800d0fdc].r0;
  uVar3 = *(ulong *)&clearRect[DAT_800d0fdc].x0;
  uVar4 = *(ulong *)&clearRect[DAT_800d0fdc].w;
  *puVar1 = clearRect[DAT_800d0fdc].tag;
  puVar1[1] = uVar2;
  puVar1[2] = uVar3;
  puVar1[3] = uVar4;
  *(ulong **)(DAT_800d0fec + 4) = puVar1 + 4;
  *puVar1 = (uint)drawot[0xbff] & 0xffffff | 0x3000000;
  drawot[0xbff] = (ulong *)((uint)puVar1 & 0xffffff);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_SwitchTheDrawBuffer(unsigned long **drawot /*$a0*/)
// line 2245, offset 0x8002f2fc
/* begin block 1 */
// Start line: 5209
/* end block 1 */
// End Line: 5210

void GAMELOOP_SwitchTheDrawBuffer(ulong **drawot)

{
  GAMELOOP_AddClearPrim(drawot, 0);
  DrawSync(0);
  if (DAT_800d10c8 != 0)
  {
    DAT_800d10c8 = 0;
    DAT_800d10c4 = DAT_800d10d0 + DAT_800d0fb0 * 0x14;
  }
  PutDrawEnv((undefined4 *)(&draw + DAT_800d0fdc));
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_SetupRenderFunction(struct GameTracker *gameTracker /*$a0*/)
// line 2277, offset 0x8002f37c
/* begin block 1 */
// Start line: 5274
/* end block 1 */
// End Line: 5275

/* begin block 2 */
// Start line: 5289
/* end block 2 */
// End Line: 5290

void GAMELOOP_SetupRenderFunction(GameTracker *gameTracker)

{
  *(undefined **)&gameTracker->drawAnimatedModelFunc = &DRAW_AnimatedModel_S;
  *(undefined **)&gameTracker->drawDisplayPolytopeListFunc = &DRAW_DisplayPolytopeList_S;
  return;
}

// decompiled code
// original method signature:
// struct _StreamUnit * /*$ra*/ GAMELOOP_GetMainRenderUnit()
// line 2303, offset 0x8002f398
/* begin block 1 */
// Start line: 2304
// Start offset: 0x8002F398
// Variables:
// 		struct _StreamUnit *streamUnit; // $s0

/* begin block 1.1 */
// Start line: 2315
// Start offset: 0x8002F3C8
// Variables:
// 		struct _Instance *focusInstance; // $s1

/* begin block 1.1.1 */
// Start line: 2336
// Start offset: 0x8002F428
// Variables:
// 		struct _StreamUnit *cameraUnit; // $v0
/* end block 1.1.1 */
// End offset: 0x8002F440
// End Line: 2344
/* end block 1.1 */
// End offset: 0x8002F440
// End Line: 2345
/* end block 1 */
// End offset: 0x8002F444
// End Line: 2349

/* begin block 2 */
// Start line: 5326
/* end block 2 */
// End Line: 5327

/* WARNING: Unknown calling convention yet parameter storage is locked */

_StreamUnit *GAMELOOP_GetMainRenderUnit(void)

{
  int iVar1;
  _StreamUnit *p_Var2;
  _StreamUnit *p_Var3;

  iVar1 = DAT_800cff98;
  if (DAT_800cff80 == 5)
  {
    p_Var2 = STREAM_WhichUnitPointerIsIn(DAT_800d02b4);
  }
  else
  {
    if ((DAT_800cff98 == DAT_800d0fd8) && (DAT_800d1128 != 0))
    {
      p_Var2 = STREAM_GetStreamUnitWithID(DAT_800d114c);
      if (p_Var2 == (_StreamUnit *)0x0)
      {
        p_Var2 = STREAM_GetStreamUnitWithID(*(long *)(iVar1 + 0x38));
        return p_Var2;
      }
    }
    else
    {
      p_Var2 = STREAM_GetStreamUnitWithID(*(long *)(DAT_800cff98 + 0x38));
    }
    p_Var3 = COLLIDE_CameraWithStreamSignals((Camera *)&theCamera);
    if (p_Var3 != (_StreamUnit *)0x0)
    {
      p_Var2 = p_Var3;
    }
  }
  /* WARNING: Read-only address (ram,0x800d0fd8) is written */
  /* WARNING: Read-only address (ram,0x800d114c) is written */
  return p_Var2;
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_DisplayFrame(struct GameTracker *gameTracker /*stack 0*/)
// line 2355, offset 0x8002f458
/* begin block 1 */
// Start line: 2356
// Start offset: 0x8002F458
// Variables:
// 		unsigned long **drawot; // stack offset -64
// 		struct Level *mainLevel; // stack offset -60
// 		struct StreamUnitPortal *streamPortal; // stack offset -56
// 		int numportals; // stack offset -52
// 		int d; // $s6
// 		struct _StreamUnit *mainStreamUnit; // $fp
// 		void *savedNextPrim; // stack offset -48

/* begin block 1.1 */
// Start line: 2467
// Start offset: 0x8002F6D0
// Variables:
// 		struct _StreamUnit *toStreamUnit; // $s2
// 		long toStreamUnitID; // stack offset -44
// 		struct StreamUnitPortal *streamPortal2; // $s4
// 		int i; // $s5
// 		int draw; // $s3
// 		struct RECT cliprect; // stack offset -72

/* begin block 1.1.1 */
// Start line: 2508
// Start offset: 0x8002F7B4
// Variables:
// 		int streamID; // $s0
// 		struct _Instance *instance; // $v0
/* end block 1.1.1 */
// End offset: 0x8002F810
// End Line: 2518
/* end block 1.1 */
// End offset: 0x8002F994
// End Line: 2587
/* end block 1 */
// End offset: 0x8002FBF0
// End Line: 2704

/* begin block 2 */
// Start line: 5433
/* end block 2 */
// End Line: 5434

void GAMELOOP_DisplayFrame(GameTracker *gameTracker)

{
  bool bVar1;
  _StreamUnit *currentUnit;
  long lVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  ulong **polyAddr;
  int *piVar7;
  StreamUnitPortal *portal;
  int iVar8;
  int iVar9;
  int iVar10;
  RECT local_48;
  ulong **local_40;
  Level *local_3c;
  int *local_38;
  int local_34;
  ulong *local_30;
  int local_2c;

  local_40 = gameTracker->drawOT;
  if (((DAT_800d10ec & 0x8000000) == 0) || (pause_redraw_flag != 0))
  {
    if (pause_redraw_flag == 0)
    {
      pause_redraw_prim = DAT_800d0fec->nextPrim;
    }
    else
    {
      local_30 = DAT_800d0fec->nextPrim;
      DrawSync(0);
      Switch_For_Redraw();
      local_40 = gameTracker->drawOT;
      ClearOTagR(DAT_800d1180, 0xc00);
      if (pause_redraw_prim == (void *)0x0)
      {
        DAT_800d0fec->nextPrim = DAT_800d0fec->prim;
      }
      else
      {
        DAT_800d0fec->nextPrim = pause_redraw_prim;
      }
    }
    ULONG_800d1208 = 0;
    DAT_800d10d4 = DAT_800d10d4 + 1;
    GAMELOOP_SetupRenderFunction((GameTracker *)&gameTrackerX);
    if (((GlobalSave->flags & 1U) == 0) &&
        (((gameTracker->wipeType != 0xb || (gameTracker->wipeTime == 0)) &&
          ((gameTracker->debugFlags2 & 0x800U) != 0))))
    {
      FX_Spiral(DAT_800d0fec, local_40);
    }
    if (pause_redraw_flag == 0)
    {
      HUD_Draw();
    }
    currentUnit = GAMELOOP_GetMainRenderUnit();
    local_3c = currentUnit->level;
    if ((gameTracker->debugFlags & 4U) != 0)
    {
      FONT_Print(s_Cameraunit___s_800ce318);
    }
    RENDER_currentStreamUnitID = *(short *)&currentUnit->StreamUnitID;
    DAT_800cff34 = 0x140;
    DAT_800cff30 = 0;
    DAT_800cff38 = 0;
    DAT_800cff3c = 0xf0;
    CAMERA_SetViewVolume((Camera *)&theCamera);
    lVar2 = MEMPACK_MemoryValidFunc((char *)local_3c);
    if (lVar2 != 0)
    {
      if ((uint)local_3c->fogFar != DAT_800cfef4)
      {
        DAT_800cfef4 = (uint)local_3c->fogFar;
      }
      if ((gameTracker->debugFlags & 0x8000U) == 0)
      {
        MainRenderLevel(currentUnit, local_40);
      }
    }
    piVar7 = (int *)local_3c->terrain->StreamUnits;
    local_34 = *piVar7;
    local_38 = piVar7 + 1;
    iVar9 = 0;
    if (0 < local_34)
    {
      iVar10 = (int)piVar7 + 0x22;
      do
      {
        local_2c = *(int *)(iVar10 + -10);
        currentUnit = *(_StreamUnit **)(iVar10 + 10);
        if ((currentUnit == (_StreamUnit *)0x0) || (currentUnit->FrameCount != DAT_800d10d4))
        {
          local_48.x = 0x200;
          local_48.y = 0xf0;
          local_48.w = -0x200;
          local_48.h = -0xf0;
          DAT_800cff34 = 0x140;
          DAT_800cff30 = 0;
          DAT_800cff38 = 0;
          DAT_800cff3c = 0xf0;
          CAMERA_SetViewVolume((Camera *)&theCamera);
          iVar8 = 0;
          bVar1 = false;
          pvVar3 = local_3c->terrain->StreamUnits;
          portal = (StreamUnitPortal *)((int)pvVar3 + 4);
          if (0 < local_34)
          {
            piVar7 = (int *)((int)pvVar3 + 0x2c);
            do
            {
              if (piVar7[-5] == local_2c)
              {
                iVar4 = STREAM_GetClipRect(portal, &local_48);
                if (iVar4 == 0)
                {
                  if (((DAT_800d032c & 0x2000000) != 0) && (*piVar7 != 0))
                  {
                    /* WARNING: Subroutine does not return */
                    INSTANCE_Query(DAT_800d0fd8, 0x22);
                  }
                }
                else
                {
                  bVar1 = true;
                }
              }
              iVar8 = iVar8 + 1;
              piVar7 = piVar7 + 0x17;
              portal = portal + 1;
            } while (iVar8 < local_34);
          }
          if (bVar1)
          {
            DAT_800cff30 = (int)local_48.x * 0x140;
            if (DAT_800cff30 < 0)
            {
              DAT_800cff30 = DAT_800cff30 + 0x1ff;
            }
            DAT_800cff38 = (int)local_48.y;
            DAT_800cff30 = DAT_800cff30 >> 9;
            DAT_800cff34 = ((int)local_48.x + (int)local_48.w) * 0x140;
            if (DAT_800cff34 < 0)
            {
              DAT_800cff34 = DAT_800cff34 + 0x1ff;
            }
            DAT_800cff34 = DAT_800cff34 >> 9;
            DAT_800cff3c = DAT_800cff38 + local_48.h;
            CAMERA_SetViewVolume((Camera *)&theCamera);
            SetRotMatrix(DAT_800cfef0);
            /* WARNING: Subroutine does not return */
            SetTransMatrix((int)DAT_800cfef0);
          }
          if ((currentUnit != (_StreamUnit *)0x0) && (currentUnit->FrameCount != DAT_800d10d4))
          {
            currentUnit->FrameCount = DAT_800d10d4;
            StreamIntroInstancesForUnit(currentUnit);
          }
        }
        iVar9 = iVar9 + 1;
        local_38 = local_38 + 0x17;
        iVar10 = iVar10 + 0x5c;
      } while (iVar9 < local_34);
    }
    iVar9 = 0;
    currentUnit = (_StreamUnit *)&StreamTracker;
    do
    {
      if ((currentUnit->used == 2) && (currentUnit->FrameCount != DAT_800d10d4))
      {
        currentUnit->FrameCount = DAT_800d10d4;
        StreamIntroInstancesForUnit(currentUnit);
      }
      iVar9 = iVar9 + 1;
      currentUnit = currentUnit + 1;
    } while (iVar9 < 0x10);
    DAT_800cff34 = 0x140;
    DAT_800cff30 = 0;
    DAT_800cff38 = 0;
    DAT_800cff3c = 0xf0;
    CAMERA_SetViewVolume((Camera *)&theCamera);
    if (pause_redraw_flag != 0)
    {
      GAMELOOP_AddClearPrim(local_40, 1);
      SaveOT();
      ClearOTagR(DAT_800d1180, 0xc00);
      Switch_For_Redraw();
      local_40 = gameTracker->drawOT;
      pause_redraw_flag = 0;
      DAT_800d0fec->nextPrim = local_30;
    }
  }
  if ((DAT_800d10ec & 0x8000000) != 0)
  {
    HUD_Draw();
  }
  DEBUG_Draw(gameTracker, local_40);
  FONT_Flush();
  GAMELOOP_SwitchTheDrawBuffer(local_40);
  uVar5 = GetRCnt(0xf2000000);
  gameTracker->idleTime = uVar5 & 0xffff | gameTimer << 0x10;
  if ((uint)gameTracker->frameRateLock < gameTracker->vblFrames)
  {
    if ((ushort *)gameTracker->reqDisp != (ushort *)0x0)
    {
      PutDispEnv((ushort *)gameTracker->reqDisp);
      gameTracker->reqDisp = (void *)0x0;
      gameTracker->vblFrames = 0;
    }
  }
  else
  {
    do
    {
      iVar9 = CheckVolatile(gameTracker->reqDisp);
    } while (iVar9 != 0);
  }
  uVar6 = TIMER_TimeDiff(gameTracker->idleTime);
  polyAddr = local_40 + 0xbff;
  iVar9 = (gameTracker->gameData).asmData.dispPage;
  gameTracker->idleTime = uVar6;
  (gameTracker->gameData).asmData.dispPage = 1 - iVar9;
  DEBUG_DrawShrinkCels(polyAddr);
  GAMELOOP_HandleScreenWipes(local_40);
  uVar5 = GetRCnt(0xf2000000);
  *(ulong **)&gameTracker->drawTimerReturn = &gameTracker->drawTime;
  gameTracker->usecsStartDraw = uVar5 & 0xffff | gameTimer << 0x10;
  if ((DAT_800d10ec & 0x8000000) == 0)
  {
    DrawOTag(polyAddr);
  }
  else
  {
    GAMELOOP_DrawSavedOT(local_40);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_DrawSavedOT(unsigned long **newOT /*$t3*/)
// line 2710, offset 0x8002fc20
/* begin block 1 */
// Start line: 2711
// Start offset: 0x8002FC20
// Variables:
// 		struct P_TAG *tag; // $a1
// 		int y; // $a2

/* begin block 1.1 */
// Start line: 2719
// Start offset: 0x8002FC84
// Variables:
// 		int tpage; // $v1
/* end block 1.1 */
// End offset: 0x8002FCAC
// End Line: 2727

/* begin block 1.2 */
// Start line: 2732
// Start offset: 0x8002FCC0
// Variables:
// 		int tpage; // $v1
/* end block 1.2 */
// End offset: 0x8002FCE8
// End Line: 2740

/* begin block 1.3 */
// Start line: 2745
// Start offset: 0x8002FCFC
/* end block 1.3 */
// End offset: 0x8002FD30
// End Line: 2756
/* end block 1 */
// End offset: 0x8002FD54
// End Line: 2759

/* begin block 2 */
// Start line: 6396
/* end block 2 */
// End Line: 6397

void GAMELOOP_DrawSavedOT(ulong **newOT)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  uint *puVar6;

  sVar1 = (&draw)[DAT_800d0fdc].ofs[1];
  puVar6 = DAT_800d1188;
  if (DAT_800d1188 != DAT_800d118c)
  {
    do
    {
      bVar4 = *(byte *)((int)puVar6 + 7) & 0xfc;
      if (bVar4 == 0x34)
      {
        uVar2 = *(ushort *)((int)puVar6 + 0x1a);
        if ((uVar2 & 0xf) < 8)
        {
          if (sVar1 == 0)
          {
            *(ushort *)((int)puVar6 + 0x1a) = uVar2 & 0xffef;
          }
          else
          {
            *(ushort *)((int)puVar6 + 0x1a) = uVar2 | 0x10;
          }
        }
      }
      else
      {
        if (bVar4 == 0x24)
        {
          uVar2 = *(ushort *)((int)puVar6 + 0x16);
          if ((uVar2 & 0xf) < 8)
          {
            if (sVar1 == 0)
            {
              *(ushort *)((int)puVar6 + 0x16) = uVar2 & 0xffef;
            }
            else
            {
              *(ushort *)((int)puVar6 + 0x16) = uVar2 | 0x10;
            }
          }
        }
        else
        {
          if (*(byte *)((int)puVar6 + 7) == 0xe3)
          {
            if (sVar1 == 0)
            {
              uVar3 = puVar6[1] & 0xfffbffff;
              uVar5 = puVar6[2] & 0xfffbffff;
            }
            else
            {
              uVar3 = puVar6[1] | 0x40000;
              uVar5 = puVar6[2] | 0x40000;
            }
            puVar6[1] = uVar3;
            puVar6[2] = uVar5;
          }
        }
      }
      puVar6 = (uint *)(*puVar6 & 0xffffff | 0x80000000);
    } while (puVar6 != DAT_800d118c);
  }
  *DAT_800d118c = *DAT_800d118c & 0xff000000 | (uint)(newOT + 0xbff) & 0xffffff;
  DrawOTag(DAT_800d1188);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ ResetPrimPool()
// line 2764, offset 0x8002fd98
/* begin block 1 */
// Start line: 6554
/* end block 1 */
// End Line: 6555

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ResetPrimPool(void)

{
  undefined **ppuVar1;

  ResetDrawPage();
  if ((DAT_800d10ec & 0x8000000) == 0)
  {
    if (DAT_800d0fec == primPool2)
    {
      DAT_800d0fec = PTR_800d0c18;
    }
    else
    {
      DAT_800d0fec = primPool2;
    }
    DAT_800d0fec->nextPrim = DAT_800d0fec->prim;
  }
  else
  {
    if (DAT_800d0fdc == 0)
    {
      ppuVar1 = (undefined **)&DAT_00008cac;
    }
    else
    {
      ppuVar1 = &PTR_000101dc;
    }
    DAT_800d0fec->nextPrim = (ulong *)((int)&DAT_800d0fec->numPrims + (int)ppuVar1);
  }
  DAT_800d0fec->numPrims = 0;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ Switch_For_Redraw()
// line 2793, offset 0x8002fe44
/* begin block 1 */
// Start line: 2795
// Start offset: 0x8002FE44
// Variables:
// 		unsigned long **temp; // $v1
/* end block 1 */
// End offset: 0x8002FEA4
// End Line: 2820

/* begin block 2 */
// Start line: 6612
/* end block 2 */
// End Line: 6613

/* begin block 3 */
// Start line: 6613
/* end block 3 */
// End Line: 6614

/* begin block 4 */
// Start line: 6616
/* end block 4 */
// End Line: 6617

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Switch_For_Redraw(void)

{
  bool bVar1;
  undefined4 uVar2;

  uVar2 = DAT_800d1180;
  DAT_800d1180 = DAT_800d1184;
  DAT_800d1184 = uVar2;
  bVar1 = DAT_800d0fdc == 0;
  DAT_800d0fdc = (uint)bVar1;
  DAT_800d0fb0 = (uint)!bVar1;
  if (DAT_800d0fec == primPool2)
  {
    DAT_800d0fec = PTR_800d0c18;
  }
  else
  {
    DAT_800d0fec = primPool2;
  }
  DAT_800d0fec->nextPrim = DAT_800d0fec->prim;
  DAT_800d0fec->numPrims = 0;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_Set_Pause_Redraw()
// line 2824, offset 0x8002fec0
/* begin block 1 */
// Start line: 6677
/* end block 1 */
// End Line: 6678

/* begin block 2 */
// Start line: 6678
/* end block 2 */
// End Line: 6679

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_Set_Pause_Redraw(void)

{
  pause_redraw_flag = 1;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SaveOT()
// line 2829, offset 0x8002fed0
/* begin block 1 */
// Start line: 2830
// Start offset: 0x8002FED0
// Variables:
// 		struct P_TAG *tag; // $a0
// 		struct P_TAG *last; // $s0
// 		struct P_TAG *lastlast; // $s1
/* end block 1 */
// End offset: 0x8003005C
// End Line: 2880

/* begin block 2 */
// Start line: 6687
/* end block 2 */
// End Line: 6688

/* WARNING: Unknown calling convention yet parameter storage is locked */

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
  puVar5 = (uint *)(&DAT_00002ffc + DAT_800d1180);
  cVar1 = (&DAT_00002fff)[DAT_800d1180];
  puVar7 = (uint *)0x0;
  while (cVar1 == '\0')
  {
    uVar4 = *puVar5;
    puVar5 = (uint *)(uVar4 & 0xffffff | 0x80000000);
    if ((uVar4 & 0xffffff) == 0xffffff)
      goto LAB_8002ff4c;
    cVar1 = *(char *)((int)puVar5 + 3);
  }
  if ((*puVar5 & 0xffffff) == 0xffffff)
  {
  LAB_8002ff4c:
    DAT_800d1188 = (uint *)0x0;
  }
  else
  {
    puVar2 = puVar5;
    puVar3 = (uint *)0x0;
    DAT_800d1188 = puVar5;
    if ((*puVar5 & 0xffffff) != 0xffffff)
    {
      do
      {
        while (puVar6 = puVar3, puVar5 = puVar2, *(char *)((int)puVar5 + 3) != '\0')
        {
          if ((*puVar5 & 0xffffff) == 0xffffff)
            goto LAB_80030038;
          puVar2 = (uint *)(*puVar5 & 0xffffff | 0x80000000);
          puVar3 = puVar5;
          puVar7 = puVar6;
        }
        if ((*puVar5 & 0xffffff) == 0xffffff)
          goto LAB_80030038;
        cVar1 = *(char *)((int)puVar5 + 3);
        while ((cVar1 == '\0' && ((*puVar5 & 0xffffff) != 0xffffff)))
        {
          puVar5 = (uint *)(*puVar5 & 0xffffff | 0x80000000);
          cVar1 = *(char *)((int)puVar5 + 3);
        }
        *puVar6 = *puVar6 & 0xff000000 | (uint)puVar5 & 0xffffff;
        puVar2 = puVar5;
        puVar3 = puVar6;
      } while ((*puVar5 & 0xffffff) != 0xffffff);
      if ((*puVar5 & 0xffffff) != 0xffffff)
      {
        DAT_800d118c = puVar5;
        return;
      }
    }
  LAB_80030038:
    DAT_800d118c = puVar5;
    if (puVar7 != (uint *)0x0)
    {
      DAT_800d118c = puVar7;
      *puVar7 = *puVar7 | 0xffffff;
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ ResetDrawPage()
// line 2882, offset 0x80030070
/* begin block 1 */
// Start line: 2883
// Start offset: 0x80030070

/* begin block 1.1 */
// Start line: 2883
// Start offset: 0x80030070
// Variables:
// 		unsigned long **temp; // $v0
/* end block 1.1 */
// End offset: 0x80030070
// End Line: 2883
/* end block 1 */
// End offset: 0x80030070
// End Line: 2883

/* begin block 2 */
// Start line: 6813
/* end block 2 */
// End Line: 6814

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ResetDrawPage(void)

{
  undefined4 *puVar1;

  puVar1 = DAT_800d1184;
  DAT_800d1184 = DAT_800d1180;
  DAT_800d0fdc = 1 - DAT_800d0fdc;
  DAT_800d1180 = puVar1;
  ClearOTagR(puVar1, 0xc00);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_Set24FPS()
// line 2914, offset 0x800300b0
/* begin block 1 */
// Start line: 6889
/* end block 1 */
// End Line: 6890

/* begin block 2 */
// Start line: 6890
/* end block 2 */
// End Line: 6891

void GAMELOOP_Set24FPS(void)

{
  uGpffffb764 = 1;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_Reset24FPS()
// line 2920, offset 0x800300c0
/* begin block 1 */
// Start line: 6901
/* end block 1 */
// End Line: 6902

/* begin block 2 */
// Start line: 6902
/* end block 2 */
// End Line: 6903

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_Reset24FPS(void)

{
  ULONG_800d1218._0_2_ = 0;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_DoTimeProcess()
// line 2925, offset 0x800300cc
/* begin block 1 */
// Start line: 2926
// Start offset: 0x800300CC
// Variables:
// 		int holdTime; // $s1

/* begin block 1.1 */
// Start line: 2961
// Start offset: 0x800301B0
// Variables:
// 		int lockRate; // $a1
// 		unsigned long last; // $a0
/* end block 1.1 */
// End offset: 0x80030260
// End Line: 2998
/* end block 1 */
// End offset: 0x800302B8
// End Line: 3014

/* begin block 2 */
// Start line: 6911
/* end block 2 */
// End Line: 6912

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_DoTimeProcess(void)

{
  bool bVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;

  uVar2 = TIMER_GetTimeMS();
  if ((DAT_800d10ec & 0x10000000) == 0)
  {
    ULONG_800d1200 = TIMER_TimeDiff(ULONG_800d11fc);
    uVar3 = GetRCnt(0xf2000000);
    ULONG_800d11fc = uVar3 & 0xffff | gameTimer << 0x10;
    if ((int)ULONG_800d1214 < 1)
    {
      ULONG_800d1214 = 1;
    }
    if (2 < (int)ULONG_800d1214)
    {
      ULONG_800d1214 = 2;
    }
    if ((DAT_800d11c8 == 0) || ((DAT_800d10ec & 0x10000000) != 0))
    {
      if (ULONG_800d1214 == 1)
      {
        DAT_800d11e8 = 0x21;
      }
      else
      {
        if (ULONG_800d1214 == 2)
        {
          DAT_800d11e8 = 0x32;
        }
      }
      DAT_800d11ec = (uint)((ulonglong)(DAT_800d11e8 << 0xc) * 0x3e0f83e1 >> 0x20);
    }
    else
    {
      uVar3 = 0x21;
      if ((ULONG_800d1214 != 1) && (ULONG_800d1214 == 2))
      {
        uVar3 = 0x32;
      }
      uVar4 = uVar3;
      if (DAT_800d11e8 != 0xffffffff)
      {
        uVar4 = uVar2 - DAT_800d11d8;
      }
      bVar1 = uVar4 < uVar3;
      if ((ULONG_800d1214 == 1) && (bVar1 = uVar4 < uVar3, (short)ULONG_800d1218 != 0))
      {
        uVar4 = uVar4 - 9;
        bVar1 = uVar4 < uVar3;
      }
      if (((!bVar1) && (DAT_800d0fb4 == 1000)) && (uVar3 = uVar4, 0x42 < uVar4))
      {
        uVar3 = 0x42;
      }
      DAT_800d11ec = (uint)((ulonglong)(uVar3 << 0xc) * 0x3e0f83e1 >> 0x20);
      DAT_800d11e8 = uVar3;
    }
    DAT_800d11ec = DAT_800d11ec >> 3;
    ULONG_800d120c = 0;
    ULONG_800d1210 = ULONG_800d1210 + DAT_800d11ec;
    while (DAT_800d11f0 = DAT_800d11ec, 0x1000 < ULONG_800d1210)
    {
      ULONG_800d120c = 1;
      ULONG_800d1210 = ULONG_800d1210 - 0x1000;
      DAT_800d10dc = DAT_800d10dc + 1;
    }
  }
  else
  {
    DAT_800d11e8 = 0xffffffff;
  }
  DAT_800d11d8 = uVar2;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_Process(struct GameTracker *gameTracker /*$s5*/)
// line 3021, offset 0x800302d0
/* begin block 1 */
// Start line: 3022
// Start offset: 0x800302D0
// Variables:
// 		int d; // $s2

/* begin block 1.1 */
// Start line: 3064
// Start offset: 0x80030378
// Variables:
// 		int useTime; // $s0

/* begin block 1.1.1 */
// Start line: 3067
// Start offset: 0x80030388
// Variables:
// 		struct Level *level; // $v0
/* end block 1.1.1 */
// End offset: 0x800303AC
// End Line: 3072
/* end block 1.1 */
// End offset: 0x800303DC
// End Line: 3077

/* begin block 1.2 */
// Start line: 3184
// Start offset: 0x8003057C
// Variables:
// 		int i; // $s0

/* begin block 1.2.1 */
// Start line: 3191
// Start offset: 0x800305A8
// Variables:
// 		struct _SFXMkr *sfxMkr; // $a2
/* end block 1.2.1 */
// End offset: 0x800305FC
// End Line: 3203
/* end block 1.2 */
// End offset: 0x80030624
// End Line: 3205
/* end block 1 */
// End offset: 0x800308F8
// End Line: 3407

/* begin block 2 */
// Start line: 7120
/* end block 2 */
// End Line: 7121

/* begin block 3 */
// Start line: 7129
/* end block 3 */
// End Line: 7130

void GAMELOOP_Process(GameTracker *gameTracker)

{
  GameTracker *offset;

  if (gEndGameNow != 0)
  {
    DEBUG_ExitGame();
    gameTracker->levelDone = 3;
    return;
  }
  offset = gameTracker;
  GAMELOOP_DoTimeProcess();
  if ((DAT_800d111e != 6) && ((DAT_800d10f0 & 0x100000) == 0))
  {
    RelocateInstances((_SVector *)offset);
    GAMELOOP_CalcGameTime();
    if ((gameTracker->gameData).asmData.MorphType == 0)
    {
      if (DAT_800d0fd8 != 0)
      {
        /* WARNING: Subroutine does not return */
        STREAM_GetLevelWithID(*(long *)(DAT_800d0fd8 + 0x38));
      }
      gameTracker->currentTimeOfDayTime =
          gameTracker->currentTimeOfDayTime + gameTracker->lastLoopTime;
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
  /* WARNING: Subroutine does not return */
  memset(gameTracker->overrideData, 0, 0x28);
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_ModeStartRunning()
// line 3411, offset 0x80030920
/* begin block 1 */
// Start line: 7987
/* end block 1 */
// End Line: 7988

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ModeStartRunning(void)

{
  if (((DAT_800d111e == 4) || (DAT_800d111e == 6)) && (DEBUG_ExitMenus(), DAT_800d111e == 6))
  {
    currentMenu = &standardMenu;
    SOUND_ResumeAllSound();
    VOICEXA_Resume();
  }
  if ((DAT_800d10ec & 0x8000000) != 0)
  {
    DAT_800d10ec = DAT_800d10ec & 0xf7ffffff;
    DAT_800d1188 = 0;
    DrawSync(0);
  }
  DAT_800d10ec = DAT_800d10ec & 0xefffffff;
  DAT_800d0fd8->flags = DAT_800d0fd8->flags & 0xfffffeff;
  DAT_800d111e = 0;
  GAMEPAD_RestoreControllers();
  /* WARNING: Subroutine does not return */
  INSTANCE_Post(DAT_800d0fd8, (int)&DAT_0010000a, 0);
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_ModeStartPause()
// line 3441, offset 0x800309f8
/* begin block 1 */
// Start line: 8050
/* end block 1 */
// End Line: 8051

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ModeStartPause(void)

{
  DAT_800d111e = 6;
  /* WARNING: Subroutine does not return */
  INSTANCE_Post(DAT_800d0fd8, (int)&DAT_0010000a, 1);
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_ChangeMode()
// line 3493, offset 0x80030ad0
/* begin block 1 */
// Start line: 3494
// Start offset: 0x80030AD0
// Variables:
// 		long *controlCommand; // $s0
/* end block 1 */
// End offset: 0x80030E6C
// End Line: 3661

/* begin block 2 */
// Start line: 6986
/* end block 2 */
// End Line: 6987

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ChangeMode(void)

{
  uint uVar1;

  if ((vmRealClock & 0x40000U) == 0)
  {
    if ((vmRealClock & 0x200000U) == 0)
    {
      if ((DAT_800d0ff4 & 0xa01) == 0xa01)
      {
        DAT_800d0298 = 1;
        (DAT_800d0fd8->position).z = (DAT_800d0fd8->position).z + 100;
        DAT_800d0fd8->zVel = 0;
        /* WARNING: Read-only address (ram,0x800d1173) is written */
        aadMem._3_1_ = 1;
        /* WARNING: Subroutine does not return */
        INSTANCE_Post(DAT_800d0fd8, (int)&DAT_00100010, 1);
      }
      if ((DAT_800d0ff4 & 0xa02) == 0xa02)
      {
        DAT_800d0298 = 1;
        (DAT_800d0fd8->position).z = (DAT_800d0fd8->position).z + -100;
        DAT_800d0fd8->zVel = 0;
        /* WARNING: Read-only address (ram,0x800d1173) is written */
        aadMem._3_1_ = 0;
        /* WARNING: Subroutine does not return */
        INSTANCE_Post(DAT_800d0fd8, (int)&DAT_00100010, 0);
      }
    }
    if ((vmRealClock & 0x40000U) != 0)
      goto LAB_80030bc0;
  }
  else
  {
  LAB_80030bc0:
    if ((DAT_800d11b0 & 2) == 0)
      goto LAB_80030ce0;
  }
  if (((DAT_800d0ff8 & 0x60) == 0x60) && ((DAT_800d0ff4 & 0xf) == 0))
  {
    if (DAT_800d111e == 0)
    {
      DAT_800d111e = 4;
      currentMenu = &standardMenu;
      if (ULONG_800d116c._2_1_ == '\0')
      {
        vmRealClock = vmRealClock & 0xfff7ffff;
      }
      else
      {
        vmRealClock = vmRealClock | 0x80000;
      }
      if (ULONG_800d116c._1_1_ == '\0')
      {
        uVar1 = vmClock & 0xffffefff;
      }
      else
      {
        uVar1 = vmClock | 0x1000;
      }
      if ((char)ULONG_800d116c == '\0')
      {
        vmClock = uVar1 & 0xffffdfff;
      }
      else
      {
        vmClock = uVar1 | 0x2000;
      }
    }
    else
    {
      if (DAT_800d111e == 7)
      {
        DEBUG_EndViewVram((GameTracker *)&gameTrackerX);
        DAT_800d111e = 0;
      }
      else
      {
        GAMELOOP_ModeStartRunning();
      }
    }
  }
LAB_80030ce0:
  if ((((((DAT_800d0ff8 & 0x4000) == 0) && (gamePadControllerOut < 6)) || (DAT_800d111e != 0)) ||
       ((DAT_800d10ec & 0x80) != 0)) ||
      ((DAT_800d1078 != 0 && ((DAT_800d107c == 0xb || (DAT_800d1078 != -1))))))
  {
    if (((((DAT_800d0ff8 & 0x4000) != 0) || ((DAT_800d10ec & 0x40000000) != 0)) &&
         ((DAT_800d111e != 0 && ((DAT_800d10ec & 0x20000000) == 0)))) &&
        ((DAT_800d1078 == 0 || ((DAT_800d107c != 0xb && (DAT_800d1078 == -1))))))
    {
      if (((DAT_800d0ff8 & 0x4000) != 0) && ((DAT_800d10ec & 0x40000000) == 0))
      {
        SndPlay(5);
      }
      DAT_800d10ec = DAT_800d10ec & 0xbfffffff;
      GAMELOOP_ModeStartRunning();
    }
  }
  else
  {
    GAMELOOP_ModeStartPause();
  }
  if ((DAT_800d0ff4 & 0x40000000) == 0)
  {
    if (((uint)FX_GeneralEffectTracker & 0x40000000) != 0)
    {
      DAT_800d0fd8->flags = DAT_800d0fd8->flags & 0xfffffeff;
    }
  }
  else
  {
    DAT_800d0fd8->flags = DAT_800d0fd8->flags | 0x100;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GAMELOOP_RequestLevelChange(char *name /*$s2*/, short number /*$a1*/, struct GameTracker *gameTracker /*$s0*/)
// line 3664, offset 0x80030e7c
/* begin block 1 */
// Start line: 8558
/* end block 1 */
// End Line: 8559

void GAMELOOP_RequestLevelChange(char *name, short number, GameTracker *gameTracker)

{
  if (gameTracker->levelChange == 0)
  {
    gameTracker->gameFlags = gameTracker->gameFlags | 1;
    SOUND_ResetAllSound();
    /* WARNING: Subroutine does not return */
    sprintf(gameTracker->baseAreaName, &DAT_800ce350);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PSX_GameLoop(struct GameTracker *gameTracker /*$s0*/)
// line 3686, offset 0x80030efc
/* begin block 1 */
// Start line: 8602
/* end block 1 */
// End Line: 8603

void PSX_GameLoop(GameTracker *gameTracker)

{
  GAMEPAD_Process(gameTracker);
  GAMELOOP_Process(gameTracker);
  return;
}

// decompiled code
// original method signature:
// struct MATRIX * /*$ra*/ GAMELOOP_GetMatrices(int numMatrices /*$a0*/)
// line 3696, offset 0x80030f28
/* begin block 1 */
// Start line: 3698
// Start offset: 0x80030F28
// Variables:
// 		struct MATRIX *matrix; // $a1
// 		struct _PrimPool *pool; // $v1
/* end block 1 */
// End offset: 0x80030F4C
// End Line: 3715

/* begin block 2 */
// Start line: 8622
/* end block 2 */
// End Line: 8623

/* begin block 3 */
// Start line: 8623
/* end block 3 */
// End Line: 8624

/* begin block 4 */
// Start line: 8624
/* end block 4 */
// End Line: 8625

MATRIX *GAMELOOP_GetMatrices(int numMatrices)

{
  MATRIX *pMVar1;
  MATRIX *pMVar2;

  pMVar2 = *(MATRIX **)(DAT_800d0fec + 4);
  pMVar1 = pMVar2 + numMatrices;
  if (pMVar1 < *(MATRIX **)(DAT_800d0fec + 8))
  {
    *(MATRIX **)(DAT_800d0fec + 4) = pMVar1;
    return pMVar2;
  }
  return (MATRIX *)0x0;
}

// decompiled code
// original method signature:
// struct GameTracker * /*$ra*/ GAMELOOP_GetGT()
// line 3720, offset 0x80030f5c
/* begin block 1 */
// Start line: 8672
/* end block 1 */
// End Line: 8673

/* begin block 2 */
// Start line: 8673
/* end block 2 */
// End Line: 8674

/* WARNING: Unknown calling convention yet parameter storage is locked */

GameTracker *GAMELOOP_GetGT(void)

{
  return (GameTracker *)&gameTrackerX;
}
