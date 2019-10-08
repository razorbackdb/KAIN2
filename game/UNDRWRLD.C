#include "THISDUST.H"
#include "UNDRWRLD.H"

void UNDERWORLD_StartProcess(void)

{
  INSTANCE_Query(gameTrackerX.playerInstance, 0x40001, 0);
  STREAM_DumpAllLevels((gameTrackerX.playerInstance)->currentStreamUnitID, 1);
  InitDisplay();
  STREAM_LoadLevel("under1", &gameTrackerX);
  if (ScreenMorphArray != (UW_ScreenXY *)0x0)
  {
    MEMPACK_Init((char *)ScreenMorphArray);
    ScreenMorphArray = (UW_ScreenXY *)0x0;
  }
  return;
}

long UNDERWORLD_RotateScreenStep(long time)

{
  UW_ScreenXY *pUVar1;
  u_long uVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  UW_ScreenXY *pUVar8;
  int iVar9;
  int iVar10;
  int iVar11;

  uVar2 = gameTrackerX.vblCount;
  if ((gameTrackerX.vblCount != time) && (UW_scalex != 0))
  {
    iVar4 = rsin(UW_angle);
    iVar5 = rcos(UW_angle);
    lVar3 = UW_scalex;
    pUVar1 = ScreenMorphArray;
    iVar11 = 0;
    iVar10 = 0;
    do
    {
      iVar9 = 0;
      iVar6 = iVar10;
      do
      {
        pUVar8 = pUVar1 + iVar6;
        iVar7 = (int)pUVar8->sx + -0x100;
        iVar6 = (int)pUVar8->sy + -0x78;
        iVar9 = iVar9 + 1;
        pUVar8->dx = (short)((iVar7 * iVar5 - iVar6 * iVar4 >> 0xc) * lVar3 >> 0xc) + 0x100;
        pUVar8->dy = (short)((iVar7 * iVar4 + iVar6 * iVar5 >> 0xc) * lVar3 >> 0xc) + 0x78;
        iVar6 = iVar9 + iVar10;
      } while (iVar9 < 3);
      iVar11 = iVar11 + 1;
      iVar10 = iVar10 + 3;
    } while (iVar11 < 3);
    UW_scalex = UW_scalex + UW_scalexInc;
    UW_angle = UW_angle + UW_angleInc & 0xfff;
    if (UW_scalex < 0)
    {
      UW_scalex = 0;
    }
    UNDERWORLD_DisplayFrame((long *)(gameTrackerX.primPool)->nextPrim,
                            (gameTrackerX.gameData.asmData.dispPage ^ 1U) << 8);
    time = uVar2;
  }
  return time;
}

void UNDERWORLD_DoUV(u_char *uv, UW_ScreenXY *p0, int tx)

{
  tx = p0->sx - tx;
  if (tx < 0x100)
  {
    *uv = (u_char)tx;
  }
  else
  {
    *uv = -1;
  }
  if (0xff < p0->sy)
  {
    uv[1] = -1;
    return;
  }
  uv[1] = *(u_char *)&p0->sy;
  return;
}

POLY_GT3 *UNDERWORLD_Poly(POLY_GT3 *last, UW_ScreenXY *p0, UW_ScreenXY *p1, UW_ScreenXY *p2, int drawY)

{
  u_short uVar1;
  int iVar2;
  u_int tx;
  POLY_GT3 *pPVar3;

  uVar1 = p0->sx;
  pPVar3 = last + 1;
  if ((int)p0->sx < (int)p1->sx)
  {
    iVar2 = (int)p2->sx << 0x10;
    if ((int)p2->sx <= (int)p0->sx)
      goto LAB_800b3790;
  }
  else
  {
    iVar2 = (int)p2->sx << 0x10;
    uVar1 = p1->sx;
    if ((int)p2->sx <= (int)p1->sx)
      goto LAB_800b3790;
  }
  iVar2 = (u_int)uVar1 << 0x10;
LAB_800b3790:
  tx = iVar2 >> 0x10 & 0xffffffc0;
  *(undefined *)((int)&last[1].tag + 3) = 9;
  last[1].code = '4';
  *(u_char *)&last[1].x0 = *(u_char *)&p0->dx;
  *(u_char *)&last[1].x1 = *(u_char *)&p1->dx;
  *(u_char *)&last[1].x2 = *(u_char *)&p2->dx;
  UNDERWORLD_DoUV(&last[1].u0, p0, tx);
  UNDERWORLD_DoUV(&last[1].u1, p1, tx);
  UNDERWORLD_DoUV(&last[1].u2, p2, tx);
  tx = GetTPage(2, 1, tx, drawY);
  last[1].tpage = (u_short)tx;
  last[1].r0 = '\x10';
  last[1].g0 = '\x10';
  last[1].b0 = '\x10';
  last[1].r1 = '\x10';
  last[1].g1 = '\x10';
  last[1].b1 = '\x10';
  last[1].r2 = '\x10';
  last[1].g2 = '\x10';
  last[1].b2 = '\x10';
  pPVar3->tag = pPVar3->tag & 0xff000000 | (u_int)last & 0xffffff;
  last[1].code = last[1].code | 2;
  return pPVar3;
}

void UNDERWORLD_DisplayFrame(long *primStart, long drawY)

{
  POLY_GT3 *last;
  int iVar1;
  UW_ScreenXY *p0;
  int iVar2;
  UW_ScreenXY *p1;
  UW_ScreenXY *p2;
  UW_ScreenXY *p2_00;
  int iVar3;
  int iVar4;
  u_int *puVar5;

  puVar5 = (u_int *)(primStart + 10);
  iVar3 = 0;
  iVar4 = 0;
  *primStart = 0xffffff;
  do
  {
    iVar2 = 0;
    iVar1 = iVar4;
    do
    {
      p0 = ScreenMorphArray + iVar1;
      p1 = ScreenMorphArray + iVar1 + 1;
      p2 = ScreenMorphArray + iVar1 + 4;
      p2_00 = ScreenMorphArray + iVar1 + 3;
      if (((iVar3 < 1) && (1 < iVar2)) || ((1 < iVar3 && (iVar2 < 1))))
      {
        last = UNDERWORLD_Poly((POLY_GT3 *)primStart, p0, p1, p2_00, drawY);
        p0 = p1;
      }
      else
      {
        last = UNDERWORLD_Poly((POLY_GT3 *)primStart, p0, p1, p2, drawY);
      }
      primStart = (long *)UNDERWORLD_Poly(last, p0, p2, p2_00, drawY);
      iVar2 = iVar2 + 1;
      iVar1 = iVar4 + iVar2;
    } while (iVar2 < 2);
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 3;
  } while (iVar3 < 2);
  *puVar5 = *puVar5 | 0xffffff;
  DrawOTag(primStart);
  return;
}

void UNDERWORLD_SetupSource(void)

{
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined auStack24[16];

  SetDrawArea((int)auStack24, 1);
  DrawPrim((int)auStack24);
  local_1c = 0x200;
  local_20 = 0;
  local_1a = 0xf0;
  local_1e = (undefined2)(gameTrackerX.gameData.asmData.dispPage << 8);
  MoveImage((u_char *)&local_20, 0, (gameTrackerX.gameData.asmData.dispPage ^ 1U) << 8);
  SetDrawArea((int)auStack24, 0);
  DrawPrim((int)auStack24);
  DrawSync(0);
  PutDrawEnv((u_char *)(&draw + gameTrackerX.gameData.asmData.dispPage));
  return;
}

void InitDisplay(void)

{
  int iVar1;
  UW_ScreenXY *pUVar2;
  short *psVar3;
  UW_ScreenXY *pUVar4;
  short sVar5;
  int iVar6;
  short sVar7;
  int iVar8;

  do
  {
    do
    {
      iVar1 = CheckVolatile(gameTrackerX.drawTimerReturn);
    } while (iVar1 != 0);
    iVar1 = CheckVolatile(gameTrackerX.reqDisp);
  } while (iVar1 != 0);
  pUVar2 = (UW_ScreenXY *)MEMPACK_Malloc(0x48, '\x18');
  iVar8 = 0;
  sVar7 = 1;
  iVar1 = 0;
  ScreenMorphArray = pUVar2;
  do
  {
    iVar6 = 0;
    sVar5 = 1;
    pUVar4 = pUVar2;
    do
    {
      psVar3 = (short *)((int)&pUVar4->sx + iVar1);
      *psVar3 = sVar5;
      sVar5 = sVar5 + 0xfe;
      iVar6 = iVar6 + 1;
      psVar3[1] = sVar7;
      pUVar4 = pUVar4 + 1;
    } while (iVar6 < 3);
    sVar7 = sVar7 + 0x77;
    iVar8 = iVar8 + 1;
    iVar1 = iVar1 + 0x18;
  } while (iVar8 < 3);
  UW_scalex = 0x1000;
  UW_scalexInc = 0x20;
  UW_angle = 0;
  UW_angleInc = 8;
  UNDERWORLD_SetupSource();
  return;
}

_StreamUnit *STREAM_LoadLevel(char *baseAreaName, GameTracker *gameTracker)

{
  int iVar1;
  u_long time;
  _StreamUnit *streamUnit;
  _BSPNode *p_Var2;
  int iVar3;
  long time_00;
  Level *pLVar4;
  char *pcVar5;
  _MultiSignal *p_Var6;
  int iVar7;
  _SVector local_48;
  undefined auStack64[3];
  undefined local_3d;
  undefined local_3c;
  undefined local_3b;
  undefined local_3a;
  undefined local_39;
  undefined2 local_38;
  undefined2 local_36;
  undefined2 local_34;
  undefined2 local_32;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined auStack40[3];
  undefined local_25;
  u_char local_24;

  time = gameTrackerX.vblCount;
  while (iVar1 = STREAM_PollLoadQueue(), iVar1 != 0)
  {
    time = UNDERWORLD_RotateScreenStep(time);
  }
  LOAD_ReadDirectory(baseAreaName);
  streamUnit = LoadLevels(gameTracker, baseAreaName, (StreamUnitPortal *)0x0, 0);
  while (iVar1 = STREAM_PollLoadQueue(), iVar1 != 0)
  {
    time = UNDERWORLD_RotateScreenStep(time);
  }
  p_Var6 = streamUnit->level->startUnitMainSignal;
  if (p_Var6 != (_MultiSignal *)0x0)
  {
    SIGNAL_HandleFogNear(gameTracker->playerInstance, p_Var6->signalList, 0);
  }
  STREAM_LoadMainVram(gameTracker, "under1", streamUnit);
  INSTANCE_Query(gameTracker->playerInstance, 0x40001, streamUnit->level->streamUnitID);
  p_Var2 = streamUnit->level->terrain->BSPTreeArray->bspRoot;
  local_48.x = -(p_Var2->sphere).position.x;
  local_48.y = -(p_Var2->sphere).position.y;
  local_48.z = -(p_Var2->sphere).position.z;
  pLVar4 = streamUnit->level;
  iVar1 = 0;
  if (0 < pLVar4->numIntros)
  {
    iVar7 = 0;
    do
    {
      iVar3 = strcpy(pLVar4->introList->name + iVar7, "raziel");
      if (iVar3 == 0)
      {
        pcVar5 = streamUnit->level->introList->name + iVar7;
        *(u_int *)(pcVar5 + 0x2c) = *(u_int *)(pcVar5 + 0x2c) | 8;
        break;
      }
      pLVar4 = streamUnit->level;
      iVar1 = iVar1 + 1;
      iVar7 = iVar7 + 0x4c;
    } while (iVar1 < pLVar4->numIntros);
  }
  (gameTrackerX.playerInstance)->currentStreamUnitID = gameTracker->StreamUnitID;
  PLAN_UpdatePlayerNode(streamUnit->level->introList + iVar1, gameTrackerX.playerInstance);
  time_00 = UNDERWORLD_RotateScreenStep(time);
  PreloadAllConnectedUnits(gameTracker, streamUnit, &local_48);
  RENDER_currentStreamUnitID = *(short *)&gameTracker->StreamUnitID;
  gameTracker->wipeType = 10;
  gameTracker->wipeTime = 0x1e;
  while (iVar1 = STREAM_PollLoadQueue(), iVar1 != 0)
  {
    time_00 = UNDERWORLD_RotateScreenStep(time_00);
  }
  iVar1 = 0;
  local_25 = 1;
  local_3d = 5;
  local_24 = 0xe1000740;
  local_2e = 0xf0;
  local_2a = 0xf0;
  local_3c = 8;
  local_3b = 8;
  local_3a = 8;
  local_38 = 0;
  local_36 = 0;
  local_34 = 0x200;
  local_32 = 0;
  local_30 = 0;
  local_2c = 0x200;
  local_39 = 0x2a;
  do
  {
    VSync(0);
    DrawPrim((int)auStack40);
    DrawPrim((int)auStack64);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x1e);
  DrawSync(0);
  return streamUnit;
}

void PLAN_UpdatePlayerNode(Intro *playerIntro, _Instance *instance)

{
  _SVector local_10;

  local_10.x = (playerIntro->position).x - (instance->position).x;
  local_10.y = (playerIntro->position).y - (instance->position).y;
  local_10.z = (playerIntro->position).z - (instance->position).z;
  RelocateInstances(&gameTrackerX, instance, &local_10);
  return;
}
