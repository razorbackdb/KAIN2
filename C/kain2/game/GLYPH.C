#include "THISDUST.H"
#include "GLYPH.H"

// int @0x800D48CC, len = 0x00000004
blast_range = null;
// _FXBlastringEffect * @0x800CF5D0, len = 0x00000004
fx_blastring = 00000000;
// short @0x800CF5CC, len = 0x00000002
fx_going = 0x0;
// int @0x800D48D0, len = 0x00000004
fx_radius_old = null;
// int @0x800D48F8, len = 0x00000004
glowdeg = null;
// short @0x800D48C4, len = 0x00000002
glyph_cost = null;
// short @0x800D48C0, len = 0x00000002
glyph_time = null;
// short @0x800D48C2, len = 0x00000002
glyph_trigger = null;
// _SVector @0x800D48E4, len = 0x00000008
HUD_Cap_Pos =
    {
        // short @0x800D48E4, len = 0x00000002
        .x = null,
        // short @0x800D48E6, len = 0x00000002
        .y = null,
        // short @0x800D48E8, len = 0x00000002
        .z = null,
        // short @0x800D48EA, len = 0x00000002
        .pad = null};
// _SVector @0x800D48EC, len = 0x00000008
HUD_Cap_Vel =
    {
        // short @0x800D48EC, len = 0x00000002
        .x = null,
        // short @0x800D48EE, len = 0x00000002
        .y = null,
        // short @0x800D48F0, len = 0x00000002
        .z = null,
        // short @0x800D48F2, len = 0x00000002
        .pad = null};
// short @0x800CF5D4, len = 0x00000002
HUD_Captured = 0x0;
// short @0x800D48C6, len = 0x00000002
HUD_Count = null;
// short @0x800D48C8, len = 0x00000002
HUD_Count_Overall = null;
// short @0x800D48DE, len = 0x00000002
HUD_Pos_vel = null;
// short @0x800D48DC, len = 0x00000002
HUD_Position = null;
// short @0x800D48DA, len = 0x00000002
HUD_Rot_vel = null;
// short @0x800D48D8, len = 0x00000002
HUD_Rotation = null;
// short @0x800D48E0, len = 0x00000002
HUD_State = null;
// short @0x800D48E2, len = 0x00000002
HUD_Wait = null;
// int @0x800D48D4, len = 0x00000004
MANNA_Pickup_Time = null;
// short @0x800D48BE, len = 0x00000002
MANNA_Pos_vel = null;
// short @0x800D48BC, len = 0x00000002
MANNA_Position = null;
// int @0x800D48F4, len = 0x00000004
warpDraw = null;
// decompiled code
// original method signature:
// void /*$ra*/ GlyphInit(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$a1*/)
// line 126, offset 0x8007a8bc
/* begin block 1 */
// Start line: 127
// Start offset: 0x8007A8BC
// Variables:
// 		struct __GlyphData *data; // $s1
/* end block 1 */
// End offset: 0x8007A9A8
// End Line: 170

/* begin block 2 */
// Start line: 252
/* end block 2 */
// End Line: 253

void GlyphInit(_Instance *instance, GameTracker *gameTracker)

{
  undefined4 *puVar1;

  if ((instance->flags & 0x20000U) == 0)
  {
    puVar1 = (undefined4 *)MEMPACK_Malloc(0x9c, '\x1d');
    *(undefined4 **)&instance->extraData = puVar1;
    InitMessageQueue((__MessageQueue *)(puVar1 + 1));
    EnMessageQueueData((__MessageQueue *)(puVar1 + 1), (int)&DAT_00100001, 0);
    *puVar1 = 0x8007b328;
    *(undefined2 *)(puVar1 + 0x23) = 7;
    *(undefined2 *)(puVar1 + 0x26) = 0xdb6;
    *(undefined2 *)(puVar1 + 0x24) = 0;
    glyph_time = 0;
    *(undefined2 *)((int)puVar1 + 0x92) = 0;
    *(undefined2 *)(puVar1 + 0x25) = 0;
    *(undefined2 *)((int)puVar1 + 0x9a) = 1;
    *(undefined2 *)((int)puVar1 + 0x8e) = 0;
    glyph_trigger = 0;
    fx_blastring = (_FXBlastringEffect *)0x0;
    fx_going = 0;
    *(short *)((int)puVar1 + 0x96) = (*(short *)(puVar1 + 0x23) + -1) * 0x249;
    glyph_cost = -1;
    instance->flags = instance->flags | 0x10800;
  }
  else
  {
    MEMPACK_Free((char *)instance->extraData);
  }
  HUD_Init();
  MANNA_Position = -0x40;
  MANNA_Pos_vel = 0;
  MANNA_Pickup_Time = 0;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GlyphCollide(struct _Instance *instance /*$a0*/, struct GameTracker *gameTracker /*$a1*/)
// line 179, offset 0x8007a9d8
/* begin block 1 */
// Start line: 398
/* end block 1 */
// End Line: 399

/* begin block 2 */
// Start line: 400
/* end block 2 */
// End Line: 401

void GlyphCollide(_Instance *instance, GameTracker *gameTracker)

{
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GlyphProcess(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
// line 186, offset 0x8007a9e0
/* begin block 1 */
// Start line: 187
// Start offset: 0x8007A9E0
// Variables:
// 		struct __GlyphData *data; // $v0
/* end block 1 */
// End offset: 0x8007A9E0
// End Line: 187

/* begin block 2 */
// Start line: 412
/* end block 2 */
// End Line: 413

void GlyphProcess(_Instance *instance, GameTracker *gameTracker)

{
  short sVar1;
  long lVar2;

  (**(code **)instance->extraData)(instance, 0, 0);
  sVar1 = (instance->parent->position).z;
  *(undefined4 *)&instance->oldPos = *(undefined4 *)&instance->parent->position;
  (instance->oldPos).z = sVar1;
  sVar1 = (instance->oldPos).z;
  *(undefined4 *)&instance->position = *(undefined4 *)&instance->oldPos;
  (instance->position).z = sVar1;
  lVar2 = instance->parent->currentStreamUnitID;
  instance->flags = instance->flags | 0xc00;
  instance->currentStreamUnitID = lVar2;
  return;
}

// decompiled code
// original method signature:
// unsigned long /*$ra*/ GlyphQuery(struct _Instance *instance /*$a0*/, unsigned long query /*$a1*/)
// line 216, offset 0x8007aa68
/* begin block 1 */
// Start line: 475
/* end block 1 */
// End Line: 476

/* begin block 2 */
// Start line: 476
/* end block 2 */
// End Line: 477

ulong GlyphQuery(_Instance *instance, ulong query)

{
  return 0;
}

// decompiled code
// original method signature:
// void /*$ra*/ GlyphPost(struct _Instance *instance /*$a0*/, unsigned long message /*$a1*/, unsigned long messageData /*$a2*/)
// line 233, offset 0x8007aa88
/* begin block 1 */
// Start line: 234
// Start offset: 0x8007AA88
// Variables:
// 		struct __GlyphData *data; // $a0
/* end block 1 */
// End offset: 0x8007AAAC
// End Line: 251

/* begin block 2 */
// Start line: 509
/* end block 2 */
// End Line: 510

void GlyphPost(_Instance *instance, ulong message, ulong messageData)

{
  if ((undefined *)message != &DAT_00100007)
  {
    EnMessageQueueData((__MessageQueue *)((int)instance->extraData + 4), message, messageData);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ _GlyphSwitchProcess(struct _Instance *instance /*$s1*/, TDRFuncPtr__GlyphSwitchProcess1process process /*$s3*/)
// line 261, offset 0x8007aabc
/* begin block 1 */
// Start line: 262
// Start offset: 0x8007AABC
// Variables:
// 		struct __GlyphData *data; // $s2
/* end block 1 */
// End offset: 0x8007AABC
// End Line: 262

/* begin block 2 */
// Start line: 574
/* end block 2 */
// End Line: 575

void _GlyphSwitchProcess(_Instance *instance, TDRFuncPtr__GlyphSwitchProcess1process process)

{
  __MessageQueue *In;
  TDRFuncPtr__GlyphSwitchProcess1process *ppTVar1;

  ppTVar1 = (TDRFuncPtr__GlyphSwitchProcess1process *)instance->extraData;
  In = (__MessageQueue *)(ppTVar1 + 1);
  PurgeMessageQueue(In);
  EnMessageQueueData(In, (int)&DAT_00100004, 0);
  (**ppTVar1)(instance, 0, 0);
  EnMessageQueueData(In, (int)&DAT_00100001, 0);
  *ppTVar1 = process;
  (*process)(instance, 0, 0);
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ GlyphIsGlyphOpen(struct _Instance *instance /*$a0*/)
// line 282, offset 0x8007ab5c
/* begin block 1 */
// Start line: 284
// Start offset: 0x8007AB5C
// Variables:
// 		struct __GlyphData *data; // $v0
/* end block 1 */
// End offset: 0x8007AB5C
// End Line: 287

/* begin block 2 */
// Start line: 620
/* end block 2 */
// End Line: 621

/* begin block 3 */
// Start line: 621
/* end block 3 */
// End Line: 622

/* begin block 4 */
// Start line: 624
/* end block 4 */
// End Line: 625

int GlyphIsGlyphOpen(_Instance *instance)

{
  return (int)*(short *)((int)instance->extraData + 0x8e);
}

// decompiled code
// original method signature:
// int /*$ra*/ _GlyphIsGlyphSet(int glyph /*$s0*/)
// line 295, offset 0x8007ab70
/* begin block 1 */
// Start line: 296
// Start offset: 0x8007AB70
// Variables:
// 		unsigned long abilities; // $v1
/* end block 1 */
// End offset: 0x8007AB70
// End Line: 296

/* begin block 2 */
// Start line: 646
/* end block 2 */
// End Line: 647

int _GlyphIsGlyphSet(int glyph)

{
  ulong uVar1;

  uVar1 = INSTANCE_Query(gameTrackerX.playerInstance, 0x24);
  return 1 << (glyph + 0x11U & 0x1f) & (uVar1 | debugRazielFlags3);
}

// decompiled code
// original method signature:
// int /*$ra*/ _GlyphIsGlyphUsable(int glyph /*$s0*/)
// line 304, offset 0x8007abb4
/* begin block 1 */
// Start line: 673
/* end block 1 */
// End Line: 674

int _GlyphIsGlyphUsable(int glyph)

{
  ulong uVar1;

  uVar1 = INSTANCE_Query(gameTrackerX.playerInstance, 0x13);
  return 1 << (glyph + 0x11U & 0x1f) & uVar1;
}

// decompiled code
// original method signature:
// int /*$ra*/ _GlyphIsAnyGlyphSet()
// line 308, offset 0x8007abf0
/* begin block 1 */
// Start line: 309
// Start offset: 0x8007ABF0
// Variables:
// 		unsigned long abilities; // $v0
/* end block 1 */
// End offset: 0x8007ABF0
// End Line: 309

/* begin block 2 */
// Start line: 682
/* end block 2 */
// End Line: 683

/* WARNING: Unknown calling convention yet parameter storage is locked */

int _GlyphIsAnyGlyphSet(void)

{
  ulong uVar1;

  uVar1 = INSTANCE_Query(gameTrackerX.playerInstance, 0x24);
  return (uVar1 | debugRazielFlags3) & 0x1fc0000;
}

// decompiled code
// original method signature:
// int /*$ra*/ _GlyphCost(struct _GlyphTuneData *glyphtunedata /*$a0*/, int glyphNum /*$a1*/)
// line 318, offset 0x8007ac20
/* begin block 1 */
// Start line: 708
/* end block 1 */
// End Line: 709

/* begin block 2 */
// Start line: 709
/* end block 2 */
// End Line: 710

int _GlyphCost(_GlyphTuneData *glyphtunedata, int glyphNum)

{
  return (uint) * (byte *)((int)&glyphtunedata->glyph_darkness + glyphNum + 1);
}

// decompiled code
// original method signature:
// int /*$ra*/ GlyphIsPuppetShowModeOn()
// line 324, offset 0x8007ac30
/* begin block 1 */
// Start line: 720
/* end block 1 */
// End Line: 721

/* WARNING: Unknown calling convention yet parameter storage is locked */

int GlyphIsPuppetShowModeOn(void)

{
  ulong uVar1;

  uVar1 = INSTANCE_Query(gameTrackerX.playerInstance, 0x30);
  return uVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ _GlyphDefaultProcess(struct _Instance *instance /*$s1*/, int data1 /*$a1*/, int data2 /*$a2*/)
// line 336, offset 0x8007ac54
/* begin block 1 */
// Start line: 337
// Start offset: 0x8007AC54
// Variables:
// 		struct __Event *Ptr; // $v0
// 		struct __GlyphData *data; // $s0
/* end block 1 */
// End offset: 0x8007ACE0
// End Line: 360

/* begin block 2 */
// Start line: 745
/* end block 2 */
// End Line: 746

void _GlyphDefaultProcess(_Instance *instance, int data1, int data2)

{
  __Event *p_Var1;
  int iVar2;
  void *pvVar3;

  pvVar3 = instance->extraData;
  while (p_Var1 = PeekMessageQueue((__MessageQueue *)((int)pvVar3 + 4)), p_Var1 != (__Event *)0x0)
  {
    if (((undefined *)p_Var1->ID == &DAT_80000010) &&
        (iVar2 = GlyphIsPuppetShowModeOn(), iVar2 == 0))
    {
      _GlyphSwitchProcess(instance, _GlyphSelectProcess);
      SndPlayVolPan(0x11, 0x7f, 0x40, 0);
      *(undefined2 *)((int)pvVar3 + 0x8e) = 1;
    }
    DeMessageQueue((__MessageQueue *)((int)pvVar3 + 4));
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HUD_GetPlayerScreenPt(struct DVECTOR *center /*$s0*/)
// line 362, offset 0x8007acf8
/* begin block 1 */
// Start line: 363
// Start offset: 0x8007ACF8
// Variables:
// 		struct _Position position; // stack offset -16
/* end block 1 */
// End offset: 0x8007ACF8
// End Line: 363

/* begin block 2 */
// Start line: 805
/* end block 2 */
// End Line: 806

void HUD_GetPlayerScreenPt(DVECTOR *center)

{
  DVECTOR DVar1;
  undefined4 in_zero;
  undefined4 in_at;
  uint local_c;

  PushMatrix();
  SetRotMatrix((undefined4 *)theCamera.core.wcTransform);
  SetTransMatrix((int)theCamera.core.wcTransform);
  local_c = local_c & 0xffff0000 |
            (uint)(ushort)(((gameTrackerX.playerInstance)->position).z + 0x1c0);
  setCopReg(2, in_zero, *(undefined4 *)&(gameTrackerX.playerInstance)->position);
  setCopReg(2, in_at, local_c);
  copFunction(2, 0x180001);
  DVar1 = (DVECTOR)getCopReg(2, 0xe);
  *center = DVar1;
  PopMatrix();
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ GlyphDrawMenu(struct _Instance *instance /*stack 0*/)
// line 380, offset 0x8007ad88
/* begin block 1 */
// Start line: 381
// Start offset: 0x8007AD88
// Variables:
// 		struct _Position place; // stack offset -72
// 		struct DVECTOR center; // stack offset -64
// 		int n; // $s5
// 		int rot; // $s3
// 		int radius; // $s6
// 		int glyph_rotation_speed; // $s0
// 		int MANNA_Count; // $fp
// 		struct __GlyphData *data; // $s4
// 		struct _GlyphTuneData *glyphtunedata; // $s7

/* begin block 1.1 */
// Start line: 403
// Start offset: 0x8007ADF4
// Variables:
// 		int diff; // $v0
/* end block 1.1 */
// End offset: 0x8007AE58
// End Line: 419

/* begin block 1.2 */
// Start line: 430
// Start offset: 0x8007AE88
// Variables:
// 		int enabled; // $v1
// 		int scale_modify; // $s2
// 		int num; // $s1
/* end block 1.2 */
// End offset: 0x8007AFC8
// End Line: 472

/* begin block 1.3 */
// Start line: 481
// Start offset: 0x8007B030
// Variables:
// 		struct _Vector f1; // stack offset -56
/* end block 1.3 */
// End offset: 0x8007B08C
// End Line: 497

/* begin block 1.4 */
// Start line: 502
// Start offset: 0x8007B08C
/* end block 1.4 */
// End offset: 0x8007B08C
// End Line: 504
/* end block 1 */
// End offset: 0x8007B08C
// End Line: 504

/* begin block 2 */
// Start line: 841
/* end block 2 */
// End Line: 842

/* begin block 3 */
// Start line: 857
/* end block 3 */
// End Line: 858

void GlyphDrawMenu(_Instance *instance)

{
  short current;
  ushort uVar1;
  ulong uVar2;
  int iVar3;
  int glyphnum;
  uint enabled;
  uint uVar4;
  int glyph;
  int iVar5;
  void *pvVar6;
  int iVar7;
  _GlyphTuneData *glyphtunedata;
  _Position local_48;
  DVECTOR local_40[2];
  _Vector local_38;

  uVar4 = (gameTrackerX.timeMult << 6) >> 0xc;
  pvVar6 = instance->extraData;
  glyphtunedata = (_GlyphTuneData *)instance->object->data;
  uVar2 = INSTANCE_Query(gameTrackerX.playerInstance, 0x20);
  if (*(short *)((int)pvVar6 + 0x98) != *(short *)((int)pvVar6 + 0x96))
  {
    current = AngleDiff(*(short *)((int)pvVar6 + 0x98), *(short *)((int)pvVar6 + 0x96));
    iVar3 = (int)current;
    if (iVar3 < 0)
    {
      iVar3 = -iVar3;
    }
    if ((int)uVar4 < iVar3)
    {
      current = (short)uVar4;
      if (*(short *)((int)pvVar6 + 0x9a) < 1)
      {
        uVar1 = *(short *)((int)pvVar6 + 0x96) - current;
      }
      else
      {
        uVar1 = *(short *)((int)pvVar6 + 0x96) + current;
      }
      *(ushort *)((int)pvVar6 + 0x96) = uVar1 & 0xfff;
    }
    else
    {
      *(undefined2 *)((int)pvVar6 + 0x96) = *(undefined2 *)((int)pvVar6 + 0x98);
    }
  }
  HUD_GetPlayerScreenPt(local_40);
  if (local_40[0].vy < 0x48)
  {
    local_40[0].vy = 0x48;
  }
  iVar7 = 0;
  iVar3 = (int)*(short *)((int)pvVar6 + 0x92);
  uVar4 = (int)*(short *)((int)pvVar6 + 0x96) + 0xc00;
  do
  {
    uVar4 = uVar4 & 0xfff;
    current = (short)uVar4;
    uVar1 = AngleDiff(current, 0xc00);
    if ((int)((uint)uVar1 << 0x10) < 0)
    {
      uVar1 = AngleDiff(current, 0xc00);
      iVar5 = (int)((uint)uVar1 << 0x10) >> 0xf;
    }
    else
    {
      uVar1 = AngleDiff(current, 0xc00);
      iVar5 = -((int)((uint)uVar1 << 0x10) >> 0xf);
    }
    iVar5 = iVar5 + 0x1000;
    if (iVar5 < 0x600)
    {
      iVar5 = 0x600;
    }
    iVar5 = (int)*(short *)((int)pvVar6 + 0x94) * iVar5;
    if (iVar5 < 0)
    {
      iVar5 = iVar5 + 0xfff;
    }
    glyphnum = rcos(uVar4);
    local_48.x = local_40[0].vx + (short)(glyphnum * iVar3 >> 0xc);
    glyphnum = rsin(uVar4);
    glyphnum = glyphnum * iVar3 >> 0xc;
    glyph = iVar7 + 1;
    if (glyphnum < 0)
    {
      glyphnum = glyphnum + 7;
    }
    local_48.y = local_40[0].vy - (short)(glyphnum >> 3);
    glyphnum = _GlyphIsGlyphSet(glyph);
    if (glyphnum == 0)
    {
      glyphnum = 7;
      if (glyph == 7)
        goto LAB_8007afa8;
      enabled = 1;
    }
    else
    {
      glyphnum = _GlyphIsGlyphUsable(glyph);
      if (glyphnum == 0)
      {
      LAB_8007afa8:
        enabled = 0;
        glyphnum = iVar7;
      }
      else
      {
        glyphnum = _GlyphCost(glyphtunedata, glyph);
        enabled = (uint)((int)uVar2 < glyphnum) ^ 1;
        glyphnum = iVar7;
      }
    }
    iVar5 = (int)glyphtunedata->glyph_size * (iVar5 >> 0xc);
    if (iVar5 < 0)
    {
      iVar5 = iVar5 + 0x1fff;
    }
    uVar4 = uVar4 - 0x249;
    iVar7 = iVar7 + 1;
    FX_MakeGlyphIcon(&local_48, instance->object, iVar5 >> 0xd, glyphnum, enabled);
    if (6 < iVar7)
    {
      iVar7 = (int)*(short *)((int)pvVar6 + 0x90);
      if (iVar7 == 0x1000)
      {
        if ((*(short *)((int)pvVar6 + 0x98) == *(short *)((int)pvVar6 + 0x96)) &&
            (iVar7 = _GlyphCost(glyphtunedata, (int)*(short *)((int)pvVar6 + 0x8c)),
             iVar7 <= (int)uVar2))
        {
          local_38.x = (int)local_40[0].vx;
          if (iVar3 < 0)
          {
            iVar3 = iVar3 + 7;
          }
          local_38.y = (int)local_40[0].vy + (iVar3 >> 3);
          DRAW_CreateAGlowingCircle(&local_38, 0x140, gameTrackerX.primPool, gameTrackerX.drawOT, 5, 0x1404040, 0x14, 0x18, 0);
        }
        iVar7 = (int)*(short *)((int)pvVar6 + 0x90);
      }
      uVar4 = iVar7 / (int)glyphtunedata->glyph_darkness;
      FX_DrawScreenPoly(2, uVar4 | uVar4 << 0x10 | uVar4 << 8, 0x20);
      return;
    }
  } while (true);
}

// decompiled code
// original method signature:
// long /*$ra*/ GlyphTime(int time /*$a0*/)
// line 510, offset 0x8007b0ec
/* begin block 1 */
// Start line: 1238
/* end block 1 */
// End Line: 1239

/* begin block 2 */
// Start line: 1239
/* end block 2 */
// End Line: 1240

long GlyphTime(int time)

{
  time = time * time;
  if (time < 0)
  {
    time = time + 0xfff;
  }
  return time >> 0xc;
}

// decompiled code
// original method signature:
// void /*$ra*/ ShrinkGlyphMenu(struct _Instance *instance /*$s1*/)
// line 517, offset 0x8007b108
/* begin block 1 */
// Start line: 518
// Start offset: 0x8007B108
// Variables:
// 		struct __GlyphData *data; // $s0
// 		int time; // $a0
// 		short accl; // stack offset -24
/* end block 1 */
// End offset: 0x8007B214
// End Line: 556

/* begin block 2 */
// Start line: 1252
/* end block 2 */
// End Line: 1253

void ShrinkGlyphMenu(_Instance *instance)

{
  int iVar1;
  long lVar2;
  void *pvVar3;
  short asStack24[4];

  pvVar3 = instance->extraData;
  gameTrackerX.streamFlags = gameTrackerX.streamFlags & 0xffefffff;
  if (*(short *)((int)pvVar3 + 0x90) < 1)
  {
    glyph_cost = -1;
  }
  else
  {
    iVar1 = (uint) * (ushort *)((int)pvVar3 + 0x90) - ((gameTrackerX.timeMult << 9) >> 0xc);
    *(undefined2 *)((int)pvVar3 + 0x90) = (short)iVar1;
    if (iVar1 * 0x10000 < 0)
    {
      *(undefined2 *)((int)pvVar3 + 0x90) = 0;
    }
    glyph_time = *(short *)((int)pvVar3 + 0x90);
    lVar2 = GlyphTime((int)*(short *)((int)pvVar3 + 0x90));
    iVar1 = lVar2 * 0x96;
    if (iVar1 < 0)
    {
      iVar1 = iVar1 + 0xfff;
    }
    *(undefined2 *)((int)pvVar3 + 0x92) = (short)(iVar1 >> 0xc);
    *(undefined2 *)((int)pvVar3 + 0x94) = (short)lVar2;
    if (0 < *(short *)((int)pvVar3 + 0x90))
    {
      GlyphDrawMenu(instance);
    }
  }
  if (MANNA_Pickup_Time < 1)
  {
    CriticalDampValue(5, &MANNA_Position, -0x40, &MANNA_Pos_vel, asStack24, 0xc);
    *(undefined2 *)((int)pvVar3 + 0x8e) = 0;
  }
  else
  {
    MANNA_Pickup_Time = MANNA_Pickup_Time - gameTrackerX.timeMult;
    *(undefined2 *)((int)pvVar3 + 0x8e) = 0;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EnlargeGlyphMenu(struct _Instance *instance /*$s1*/)
// line 559, offset 0x8007b22c
/* begin block 1 */
// Start line: 560
// Start offset: 0x8007B22C
// Variables:
// 		struct __GlyphData *data; // $s0
// 		int time; // $a1
// 		short accl; // stack offset -24
/* end block 1 */
// End offset: 0x8007B2D4
// End Line: 583

/* begin block 2 */
// Start line: 1351
/* end block 2 */
// End Line: 1352

void EnlargeGlyphMenu(_Instance *instance)

{
  int iVar1;
  long lVar2;
  void *pvVar3;
  short asStack24[4];

  pvVar3 = instance->extraData;
  gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x100000;
  if (*(short *)((int)pvVar3 + 0x90) < 0x1000)
  {
    iVar1 = (uint) * (ushort *)((int)pvVar3 + 0x90) + ((gameTrackerX.timeMult << 9) >> 0xc);
    *(undefined2 *)((int)pvVar3 + 0x90) = (short)iVar1;
    if (0x1000 < iVar1 * 0x10000 >> 0x10)
    {
      *(undefined2 *)((int)pvVar3 + 0x90) = 0x1000;
    }
    glyph_time = *(short *)((int)pvVar3 + 0x90);
  }
  lVar2 = GlyphTime((int)*(short *)((int)pvVar3 + 0x90));
  iVar1 = lVar2 * 0x96;
  if (iVar1 < 0)
  {
    iVar1 = iVar1 + 0xfff;
  }
  *(undefined2 *)((int)pvVar3 + 0x92) = (short)(iVar1 >> 0xc);
  *(undefined2 *)((int)pvVar3 + 0x94) = (short)lVar2;
  GlyphDrawMenu(instance);
  MANNA_Pickup_Time = 0;
  CriticalDampValue(5, &MANNA_Position, 0x18, &MANNA_Pos_vel, asStack24, 0xc);
  *(undefined2 *)((int)pvVar3 + 0x8e) = 1;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ _GlyphOffProcess(struct _Instance *instance /*$s1*/, int data1 /*$s4*/, int data2 /*$s5*/)
// line 596, offset 0x8007b328
/* begin block 1 */
// Start line: 597
// Start offset: 0x8007B328
// Variables:
// 		struct __Event *Ptr; // $v0
// 		struct __GlyphData *data; // $s0
/* end block 1 */
// End offset: 0x8007B444
// End Line: 634

/* begin block 2 */
// Start line: 1438
/* end block 2 */
// End Line: 1439

void _GlyphOffProcess(_Instance *instance, int data1, int data2)

{
  __Event *p_Var1;
  int iVar2;
  undefined *puVar3;
  code **ppcVar4;

  ppcVar4 = (code **)instance->extraData;
  ShrinkGlyphMenu(instance);
  do
  {
    p_Var1 = PeekMessageQueue((__MessageQueue *)(ppcVar4 + 1));
    if (p_Var1 == (__Event *)0x0)
    {
      if (*ppcVar4 == _GlyphSelectProcess)
      {
        SndPlayVolPan(0x11, 0x7f, 0x40, 0);
      }
      Glyph_DoFX(instance);
      return;
    }
    puVar3 = (undefined *)p_Var1->ID;
    if (puVar3 != &DAT_00100001)
    {
      if ((int)puVar3 < 0x100002)
      {
        if (puVar3 == &DAT_80000010)
        {
          if (*ppcVar4 == _GlyphSelectProcess)
          {
            _GlyphSwitchProcess(instance, _GlyphOffProcess);
            *(undefined2 *)((int)ppcVar4 + 0x8e) = 0;
          }
          else
          {
            iVar2 = GlyphIsPuppetShowModeOn();
            if (iVar2 == 0)
            {
              _GlyphSwitchProcess(instance, _GlyphSelectProcess);
              *(undefined2 *)((int)ppcVar4 + 0x8e) = 1;
            }
          }
        }
        else
        {
        LAB_8007b408:
          _GlyphDefaultProcess(instance, data1, data2);
        }
      }
      else
      {
        if (puVar3 != &DAT_00100004)
          goto LAB_8007b408;
      }
    }
    DeMessageQueue((__MessageQueue *)(ppcVar4 + 1));
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ _GlyphSelectProcess(struct _Instance *instance /*$s3*/, int data1 /*$s6*/, int data2 /*$s7*/)
// line 639, offset 0x8007b470
/* begin block 1 */
// Start line: 640
// Start offset: 0x8007B470
// Variables:
// 		struct __Event *Ptr; // $v0
// 		struct __GlyphData *data; // $s1
// 		struct _GlyphTuneData *glyphtunedata; // $s4
// 		int dontdraw_flag; // $s2

/* begin block 1.1 */
// Start line: 712
// Start offset: 0x8007B85C
// Variables:
// 		int MANNA_Count; // $s0
/* end block 1.1 */
// End offset: 0x8007B8B0
// End Line: 721
/* end block 1 */
// End offset: 0x8007B93C
// End Line: 751

/* begin block 2 */
// Start line: 1524
/* end block 2 */
// End Line: 1525

void _GlyphSelectProcess(_Instance *instance, int data1, int data2)

{
  bool bVar1;
  ushort vol;
  short sVar2;
  __Event *p_Var3;
  int iVar4;
  ulong uVar5;
  undefined *puVar6;
  uint sample;
  void *pvVar7;
  _GlyphTuneData *glyphtunedata;

  bVar1 = false;
  pvVar7 = instance->extraData;
  glyphtunedata = (_GlyphTuneData *)instance->object->data;
  do
  {
    p_Var3 = PeekMessageQueue((__MessageQueue *)((int)pvVar7 + 4));
    if (p_Var3 == (__Event *)0x0)
    {
      iVar4 = GlyphIsPuppetShowModeOn();
      if ((iVar4 != 0) && (*(short *)((int)pvVar7 + 0x8e) == 1))
      {
        bVar1 = true;
        *(undefined2 *)((int)pvVar7 + 0x8e) = 0;
        _GlyphSwitchProcess(instance, _GlyphOffProcess);
      }
      if (!bVar1)
      {
        iVar4 = _GlyphCost(glyphtunedata, (int)*(short *)((int)pvVar7 + 0x8c));
        glyph_cost = (short)iVar4;
        EnlargeGlyphMenu(instance);
      }
      Glyph_DoFX(instance);
      return;
    }
    puVar6 = (undefined *)p_Var3->ID;
    if (puVar6 == &DAT_00100001)
    {
      bVar1 = true;
      *(undefined2 *)((int)pvVar7 + 0x8c) = 7;
      *(undefined2 *)((int)pvVar7 + 0x98) = 0xdb6;
      *(short *)((int)pvVar7 + 0x96) = (*(short *)((int)pvVar7 + 0x8c) + -1) * 0x249;
      *(undefined2 *)((int)pvVar7 + 0x96) = *(undefined2 *)((int)pvVar7 + 0x98);
      goto LAB_8007b8d8;
    }
    if ((int)puVar6 < 0x100002)
    {
      if (puVar6 == (undefined *)0x80000000)
      {
        sample = 0x10;
        if (fx_going == 0)
        {
          iVar4 = _GlyphIsGlyphSet((int)*(short *)((int)pvVar7 + 0x8c));
          sample = 0x10;
          if (iVar4 != 0)
          {
            uVar5 = INSTANCE_Query(gameTrackerX.playerInstance, 0x20);
            iVar4 = _GlyphCost(glyphtunedata, (int)*(short *)((int)pvVar7 + 0x8c));
            sample = 0x10;
            if (iVar4 <= (int)uVar5)
            {
              iVar4 = _GlyphIsGlyphUsable((int)*(short *)((int)pvVar7 + 0x8c));
              if (iVar4 != 0)
              {
                bVar1 = true;
                _GlyphSwitchProcess(instance, _GlyphGenericProcess);
                goto LAB_8007b8d8;
              }
              sample = 0x10;
            }
          }
        }
      LAB_8007b8b4:
        vol = 100;
      }
      else
      {
        if (puVar6 != &DAT_80000010)
          goto LAB_8007b8d0;
        bVar1 = true;
        _GlyphSwitchProcess(instance, _GlyphOffProcess);
        *(undefined2 *)((int)pvVar7 + 0x8e) = 0;
        sample = 0xf;
        vol = 0x7f;
      }
    LAB_8007b8b8:
      SndPlayVolPan(sample, vol, 0x40, 0);
    }
    else
    {
      if (puVar6 == (undefined *)0x10000002)
      {
        iVar4 = _GlyphIsAnyGlyphSet();
        if (iVar4 != 0)
        {
          vol = AngleDiff(*(short *)((int)pvVar7 + 0x96), *(short *)((int)pvVar7 + 0x98));
          if ((int)((uint)vol << 0x10) < 0)
          {
            sVar2 = AngleDiff(*(short *)((int)pvVar7 + 0x96), *(short *)((int)pvVar7 + 0x98));
            if (-(int)sVar2 < 0x40)
              goto LAB_8007b768;
          }
          else
          {
            sVar2 = AngleDiff(*(short *)((int)pvVar7 + 0x96), *(short *)((int)pvVar7 + 0x98));
            if (sVar2 < 0x40)
            {
            LAB_8007b768:
              do
              {
                *(short *)((int)pvVar7 + 0x8c) = *(short *)((int)pvVar7 + 0x8c) + 1;
                *(undefined2 *)((int)pvVar7 + 0x9a) = 1;
                if (7 < *(short *)((int)pvVar7 + 0x8c))
                {
                  *(undefined2 *)((int)pvVar7 + 0x8c) = 1;
                }
                *(short *)((int)pvVar7 + 0x98) = (*(short *)((int)pvVar7 + 0x8c) + -1) * 0x249;
                iVar4 = _GlyphIsGlyphSet((int)*(short *)((int)pvVar7 + 0x8c));
              } while (iVar4 == 0);
              vol = AngleDiff(*(short *)((int)pvVar7 + 0x96), *(short *)((int)pvVar7 + 0x98));
              if ((int)((uint)vol << 0x10) < 0)
              {
                sVar2 = AngleDiff(*(short *)((int)pvVar7 + 0x96), *(short *)((int)pvVar7 + 0x98));
                sample = 0x12;
                if (0x3f < -(int)sVar2)
                {
                  vol = 100;
                  goto LAB_8007b8b8;
                }
              }
              else
              {
                sVar2 = AngleDiff(*(short *)((int)pvVar7 + 0x96), *(short *)((int)pvVar7 + 0x98));
              joined_r0x8007b7f8:
                sample = 0x12;
                if (0x3f < sVar2)
                  goto LAB_8007b8b4;
              }
            }
          }
        }
      }
      else
      {
        if ((int)puVar6 < 0x10000003)
        {
          if (puVar6 == &DAT_00100004)
          {
            bVar1 = true;
            goto LAB_8007b8d8;
          }
        }
        else
        {
          if (puVar6 == (undefined *)0x10000004)
          {
            iVar4 = _GlyphIsAnyGlyphSet();
            if (iVar4 != 0)
            {
              vol = AngleDiff(*(short *)((int)pvVar7 + 0x96), *(short *)((int)pvVar7 + 0x98));
              if ((int)((uint)vol << 0x10) < 0)
              {
                sVar2 = AngleDiff(*(short *)((int)pvVar7 + 0x96), *(short *)((int)pvVar7 + 0x98));
                if (-(int)sVar2 < 0x40)
                  goto LAB_8007b620;
              }
              else
              {
                sVar2 = AngleDiff(*(short *)((int)pvVar7 + 0x96), *(short *)((int)pvVar7 + 0x98));
                if (sVar2 < 0x40)
                {
                LAB_8007b620:
                  do
                  {
                    *(undefined2 *)((int)pvVar7 + 0x9a) = 0xffff;
                    vol = *(short *)((int)pvVar7 + 0x8c) - 1;
                    *(ushort *)((int)pvVar7 + 0x8c) = vol;
                    if ((int)((uint)vol << 0x10) < 1)
                    {
                      *(undefined2 *)((int)pvVar7 + 0x8c) = 7;
                    }
                    *(short *)((int)pvVar7 + 0x98) = (*(short *)((int)pvVar7 + 0x8c) + -1) * 0x249;
                    iVar4 = _GlyphIsGlyphSet((int)*(short *)((int)pvVar7 + 0x8c));
                  } while (iVar4 == 0);
                  vol = AngleDiff(*(short *)((int)pvVar7 + 0x96), *(short *)((int)pvVar7 + 0x98));
                  if (-1 < (int)((uint)vol << 0x10))
                  {
                    sVar2 = AngleDiff(*(short *)((int)pvVar7 + 0x96), *(short *)((int)pvVar7 + 0x98));
                    goto joined_r0x8007b7f8;
                  }
                  sVar2 = AngleDiff(*(short *)((int)pvVar7 + 0x96), *(short *)((int)pvVar7 + 0x98));
                  sample = 0x12;
                  if (0x3f < -(int)sVar2)
                  {
                    vol = 100;
                    goto LAB_8007b8b8;
                  }
                }
              }
            }
            goto LAB_8007b8d8;
          }
        }
      LAB_8007b8d0:
        _GlyphDefaultProcess(instance, data1, data2);
      }
    }
  LAB_8007b8d8:
    DeMessageQueue((__MessageQueue *)((int)pvVar7 + 4));
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ Glyph_StartSpell(struct _Instance *instance /*$a0*/, int glyphnum /*$a1*/)
// line 757, offset 0x8007b970
/* begin block 1 */
// Start line: 758
// Start offset: 0x8007B970
// Variables:
// 		int message; // $a2
/* end block 1 */
// End offset: 0x8007B9F8
// End Line: 791

/* begin block 2 */
// Start line: 1791
/* end block 2 */
// End Line: 1792

void Glyph_StartSpell(_Instance *instance, int glyphnum)

{
  int Message;

  Message = 0;
  switch (glyphnum)
  {
  case 1:
    Message = 0x80001;
    break;
  case 2:
    Message = 0x80002;
    break;
  case 3:
    Message = 0x80003;
    break;
  case 4:
    Message = 0x80004;
    break;
  case 5:
    Message = 0x80005;
    break;
  case 6:
    Message = 0x80006;
    break;
  case 7:
    Message = 0x80007;
  }
  INSTANCE_Post(gameTrackerX.playerInstance, Message, 0);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ Glyph_Broadcast(struct _Instance *sender /*$s6*/, int glyphnum /*$a1*/)
// line 794, offset 0x8007ba18
/* begin block 1 */
// Start line: 795
// Start offset: 0x8007BA18
// Variables:
// 		struct _Instance *instance; // $s2
// 		int plane; // $s7
// 		long whatAmIMask; // $s4
// 		int Message; // $s3
// 		int radius; // stack offset -48
// 		int radius_old; // $fp
// 		int range; // $s5

/* begin block 1.1 */
// Start line: 847
// Start offset: 0x8007BB28
// Variables:
// 		int dist; // $s0
// 		int old_dist; // $v0
// 		int old_x; // $s0
// 		int old_y; // $s1
// 		int new_x; // $v0
// 		int new_y; // $v1
// 		long whatAmI; // $s0
/* end block 1.1 */
// End offset: 0x8007BC30
// End Line: 878
/* end block 1 */
// End offset: 0x8007BC40
// End Line: 879

/* begin block 2 */
// Start line: 1865
/* end block 2 */
// End Line: 1866

/* begin block 3 */
// Start line: 1875
/* end block 3 */
// End Line: 1876

void Glyph_Broadcast(_Instance *sender, int glyphnum)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  MATRIX *pMVar4;
  int iVar5;
  MATRIX *pMVar6;
  int iVar7;
  int iVar8;
  _Instance *Inst;
  int Message;
  uint uVar9;
  int plane;
  int iVar10;

  plane = (int)gameTrackerX.gameData.asmData.MorphType;
  uVar9 = 0;
  iVar5 = (blast_range >> 0xc) * 7;
  Message = 0;
  iVar1 = fx_blastring->radius;
  iVar10 = fx_radius_old >> 0xc;
  if (iVar5 < 0)
  {
    iVar5 = iVar5 + 7;
  }
  switch (glyphnum)
  {
  case 1:
    uVar9 = 10;
    Message = 0x80001;
    break;
  case 2:
    uVar9 = 10;
    Message = 0x80002;
    break;
  case 3:
    uVar9 = 10;
    Message = 0x80003;
    break;
  case 4:
    uVar9 = 10;
    Message = 0x80004;
    break;
  case 5:
    uVar9 = 0x2a;
    Message = 0x80005;
    break;
  case 6:
    uVar9 = 10;
    Message = 0x80006;
    break;
  case 7:
    goto switchD_8007baac_caseD_7;
  }
  Inst = (gameTrackerX.instanceList)->first;
  while (Inst != (_Instance *)0x0)
  {
    uVar2 = INSTANCE_Query(Inst, 1);
    if (((((Inst != sender) && ((uVar2 & uVar9) != 0)) &&
          (iVar3 = INSTANCE_InPlane(Inst, plane), iVar3 != 0)) &&
         ((uVar2 != 0x20 || (uVar2 = INSTANCE_Query(Inst, 2), (uVar2 & 0x4000) != 0)))) &&
        ((pMVar6 = Inst->oldMatrix, pMVar6 != (MATRIX *)0x0 &&
                                        (pMVar4 = Inst->matrix, pMVar4 != (MATRIX *)0x0))))
    {
      iVar7 = pMVar6->t[0];
      iVar8 = pMVar6->t[1];
      iVar3 = MATH3D_veclen2(pMVar4->t[0] - (int)(sender->position).x,
                             pMVar4->t[1] - (int)(sender->position).y);
      iVar7 = MATH3D_veclen2(iVar7 - (int)(sender->position).x, iVar8 - (int)(sender->position).y);
      if ((iVar3 <= iVar1 >> 0xc) && (iVar10 < iVar7))
      {
        iVar8 = (int)(sender->position).z;
        iVar7 = Inst->matrix->t[2];
        iVar3 = iVar7 - iVar8;
        if (iVar3 < 0)
        {
          iVar3 = iVar8 - iVar7;
        }
        if (iVar3<iVar5>> 3)
        {
          INSTANCE_Post(Inst, Message, 0);
        }
      }
    }
    Inst = Inst->next;
  }
switchD_8007baac_caseD_7:
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ Glyph_DoSpell(struct _Instance *instance /*stack 0*/, int glyphnum /*$s1*/)
// line 881, offset 0x8007bc70
/* begin block 1 */
// Start line: 882
// Start offset: 0x8007BC70
// Variables:
// 		int fx_radius; // $fp
// 		int fx_accl; // $v0
// 		int fx_vel; // $s5
// 		long fx_color; // $a3
// 		int fx_height1; // $s7
// 		int fx_height2; // $s6
// 		int fx_height3; // $s4
// 		int fx_rad2; // $s3
// 		int fx_rad3; // $s2
// 		int pred_offset; // $s0
// 		int color_change_radius; // $s1
// 		struct MATRIX mat; // stack offset -80
// 		struct _GlyphTuneData *glyphtunedata; // $s0
/* end block 1 */
// End offset: 0x8007BED8
// End Line: 981

/* begin block 2 */
// Start line: 2104
/* end block 2 */
// End Line: 2105

void Glyph_DoSpell(_Instance *instance, int glyphnum)

{
  int colorChangeRadius;
  long startColor;
  void *pvVar1;
  int pred_offset;
  int size2;
  int size1;
  int height3;
  undefined *vel;
  int height2;
  int height1;
  int radius;
  MATRIX MStack80;
  long local_30;

  radius = 0;
  vel = (undefined *)0x0;
  height1 = 0;
  height2 = 0;
  height3 = 0;
  size1 = 0;
  size2 = 0;
  pvVar1 = instance->object->data;
  fx_going = 0;
  local_30 = 0;
  MATH3D_SetUnityMatrix(&MStack80);
  fx_radius_old = 0;
  blast_range = (int)*(short *)((int)pvVar1 + (glyphnum + -1) * 2 + 0xc);
  pred_offset = 0;
  colorChangeRadius = blast_range;
  if (blast_range < 0)
  {
    colorChangeRadius = blast_range + 3;
  }
  colorChangeRadius = blast_range - (colorChangeRadius >> 2);
  startColor = local_30;
  switch (glyphnum)
  {
  case 1:
    radius = 1;
    startColor = 0xc0c0c0;
    height1 = -0x100;
    height2 = 0x100;
    height3 = 0x300;
    vel = (undefined *)0x200000;
    size1 = -0x280;
    fx_going = 1;
    size2 = 0;
    break;
  case 2:
    CAMERA_SetShake(&theCamera, 0x3c, 0x800);
    radius = 0x280;
    vel = &UNK_00140000;
    startColor = 0xa0a0a0;
    height3 = 0;
    height2 = 0;
    height1 = 0;
    size1 = 0x280;
    fx_going = 2;
    size2 = 0x340;
    break;
  case 3:
    radius = 1;
    startColor = 0xffffff;
    height1 = 0;
    height2 = 0x40;
    height3 = 0x80;
    vel = (undefined *)0x100000;
    size1 = 0x280;
    size2 = 0x340;
    fx_going = 3;
    pred_offset = 5;
    break;
  case 4:
    radius = 1;
    startColor = 0xff0000;
    height1 = -0x200;
    height2 = 0;
    height3 = 0x200;
    vel = (undefined *)0x100000;
    size1 = 0x280;
    fx_going = 4;
    size2 = 0x340;
    break;
  case 5:
    radius = 1;
    vel = (undefined *)0x100000;
    startColor = 0xff;
    height1 = -0x200;
    height2 = 0;
    height3 = 0x200;
    size1 = 0x280;
    fx_going = 5;
    size2 = 0x340;
    break;
  case 6:
    radius = 1;
    startColor = 0xffffff;
    height1 = -0x200;
    height2 = 0;
    height3 = 0x200;
    vel = (undefined *)0x100000;
    size1 = 0x280;
    fx_going = 6;
    size2 = 0x340;
  }
  if ((fx_going != 0) &&
      (fx_blastring = FX_DoBlastRing((_Instance *)0x0, (_SVector *)&instance->position, &MStack80, -1,
                                     radius, blast_range, colorChangeRadius, size1, size2, (int)vel, -0x800, height1, height2, height3, startColor, 0, pred_offset, -99, 0),
       fx_blastring == (_FXBlastringEffect *)0x0))
  {
    fx_going = 0;
  }
  blast_range = blast_range << 0xc;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ Glyph_EndFX()
// line 984, offset 0x8007bf14
/* begin block 1 */
// Start line: 2346
/* end block 1 */
// End Line: 2347

/* begin block 2 */
// Start line: 2347
/* end block 2 */
// End Line: 2348

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Glyph_EndFX(void)

{
  _FXBlastringEffect *p_Var1;

  p_Var1 = fx_blastring;
  fx_going = 0;
  fx_blastring = (_FXBlastringEffect *)0x0;
  p_Var1->lifeTime = 0;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ Glyph_DoFX(struct _Instance *instance /*$a0*/)
// line 991, offset 0x8007bf28
/* begin block 1 */
// Start line: 2358
/* end block 1 */
// End Line: 2359

/* begin block 2 */
// Start line: 2362
/* end block 2 */
// End Line: 2363

void Glyph_DoFX(_Instance *instance)

{
  int *piVar1;
  _FXBlastringEffect *p_Var2;

  if (((gameTrackerX.gameMode != 6) && ((gameTrackerX.streamFlags & 0x100000U) == 0)) &&
      ((int)fx_going != 0))
  {
    Glyph_Broadcast(instance, (int)fx_going);
    fx_radius_old = fx_blastring->radius;
    if (blast_range < fx_radius_old)
    {
      Glyph_EndFX();
    }
    p_Var2 = fx_blastring;
    if (fx_going == 5)
    {
      piVar1 = &fx_blastring->height3;
      fx_blastring->height1 = fx_blastring->height1 + -0x3c;
      p_Var2->height3 = *piVar1 + 0x3c;
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ _GlyphGenericProcess(struct _Instance *instance /*$s2*/, int data1 /*$s3*/, int data2 /*$s4*/)
// line 1024, offset 0x8007bfd8
/* begin block 1 */
// Start line: 1025
// Start offset: 0x8007BFD8
// Variables:
// 		struct __Event *Ptr; // $v0
// 		struct __GlyphData *data; // $s1

/* begin block 1.1 */
// Start line: 1056
// Start offset: 0x8007C0B0
// Variables:
// 		struct _GlyphTuneData *glyphtunedata; // $s0
/* end block 1.1 */
// End offset: 0x8007C0E8
// End Line: 1062
/* end block 1 */
// End offset: 0x8007C0E8
// End Line: 1064

/* begin block 2 */
// Start line: 2432
/* end block 2 */
// End Line: 2433

void _GlyphGenericProcess(_Instance *instance, int data1, int data2)

{
  __Event *p_Var1;
  int Data;
  undefined *puVar2;
  _GlyphTuneData *glyphtunedata;
  void *pvVar3;

  pvVar3 = instance->extraData;
  ShrinkGlyphMenu(instance);
  do
  {
    p_Var1 = PeekMessageQueue((__MessageQueue *)((int)pvVar3 + 4));
    if (p_Var1 == (__Event *)0x0)
    {
      if (glyph_trigger != 0)
      {
        glyphtunedata = (_GlyphTuneData *)instance->object->data;
        Glyph_DoSpell(instance, (int)*(short *)((int)pvVar3 + 0x8c));
        glyph_trigger = 0;
        Data = _GlyphCost(glyphtunedata, (int)*(short *)((int)pvVar3 + 0x8c));
        INSTANCE_Post(gameTrackerX.playerInstance, 0x40008, Data);
      }
      Glyph_DoFX(instance);
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == &DAT_00100001)
    {
      Glyph_StartSpell(instance, (int)*(short *)((int)pvVar3 + 0x8c));
    }
    else
    {
      if ((int)puVar2 < 0x100002)
      {
        if (puVar2 == (undefined *)0x80000000)
        {
          _GlyphSwitchProcess(instance, _GlyphOffProcess);
          *(undefined2 *)((int)pvVar3 + 0x8e) = 0;
        }
        else
        {
        LAB_8007c088:
          _GlyphDefaultProcess(instance, data1, data2);
        }
      }
      else
      {
        if (puVar2 != &DAT_00100004)
          goto LAB_8007c088;
      }
    }
    DeMessageQueue((__MessageQueue *)((int)pvVar3 + 4));
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ GlyphTrigger()
// line 1067, offset 0x8007c110
/* begin block 1 */
// Start line: 2520
/* end block 1 */
// End Line: 2521

/* begin block 2 */
// Start line: 2521
/* end block 2 */
// End Line: 2522

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GlyphTrigger(void)

{
  if (fx_going == 0)
  {
    glyph_trigger = 1;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MANNA_Pickup()
// line 1084, offset 0x8007c12c
/* begin block 1 */
// Start line: 2554
/* end block 1 */
// End Line: 2555

/* begin block 2 */
// Start line: 2555
/* end block 2 */
// End Line: 2556

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MANNA_Pickup(void)

{
  MANNA_Position = 0x18;
  MANNA_Pickup_Time = 0x1e000;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HEALTHU_Pickup(struct _Instance *instance /*$s0*/)
// line 1090, offset 0x8007c148
/* begin block 1 */
// Start line: 2566
/* end block 1 */
// End Line: 2567

void HEALTHU_Pickup(_Instance *instance)

{
  ApplyMatrixSV(theCamera.core.wcTransform2, &instance->position, &HUD_Cap_Pos);
  HUD_Cap_Pos.x = HUD_Cap_Pos.x + *(short *)(theCamera.core.wcTransform2)->t;
  HUD_Cap_Pos.y = HUD_Cap_Pos.y + *(short *)((theCamera.core.wcTransform2)->t + 1);
  HUD_Cap_Vel.z = 0;
  HUD_Cap_Vel.y = 0;
  HUD_Cap_Vel.x = 0;
  HUD_Cap_Pos.z = HUD_Cap_Pos.z + *(short *)((theCamera.core.wcTransform2)->t + 2);
  INSTANCE_KillInstance(instance);
  HUD_Captured = 1;
  HUD_State = 1;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HUD_Damp(short *val /*$v1*/, short target /*$a1*/, short *vel /*$a3*/, short max /*$a3*/)
// line 1106, offset 0x8007c1d4
/* begin block 1 */
// Start line: 1107
// Start offset: 0x8007C1D4
// Variables:
// 		short accl; // stack offset -16
/* end block 1 */
// End offset: 0x8007C1D4
// End Line: 1107

/* begin block 2 */
// Start line: 2601
/* end block 2 */
// End Line: 2602

void HUD_Damp(short *val, short target, short *vel, short max)

{
  short asStack16[4];

  CriticalDampValue(1, val, target, vel, asStack16, (int)max);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HUD_Init()
// line 1113, offset 0x8007c21c
/* begin block 1 */
// Start line: 2621
/* end block 1 */
// End Line: 2622

/* begin block 2 */
// Start line: 2627
/* end block 2 */
// End Line: 2628

/* WARNING: Unknown calling convention yet parameter storage is locked */

void HUD_Init(void)

{
  HUD_Count = 0;
  HUD_Count_Overall = 0;
  HUD_Rotation = 0;
  HUD_Rot_vel = 0;
  HUD_Position = -1000;
  HUD_Pos_vel = 0;
  HUD_State = 0;
  HUD_Wait = 0;
  warpDraw = 0;
  glowdeg = 0;
  hud_warp_arrow_flash = 0;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HUD_Setup_Chit_Count(int chits /*$a0*/)
// line 1128, offset 0x8007c254
/* begin block 1 */
// Start line: 2656
/* end block 1 */
// End Line: 2657

/* begin block 2 */
// Start line: 2658
/* end block 2 */
// End Line: 2659

void HUD_Setup_Chit_Count(int chits)

{
  HUD_Count = (short)chits + (short)(chits / 5) * -5;
  HUD_Count_Overall = (short)chits;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HUD_Update()
// line 1134, offset 0x8007c28c
/* begin block 1 */
// Start line: 1135
// Start offset: 0x8007C28C
// Variables:
// 		short accl; // stack offset -16
/* end block 1 */
// End offset: 0x8007C4B0
// End Line: 1220

/* begin block 2 */
// Start line: 2669
/* end block 2 */
// End Line: 2670

/* WARNING: Unknown calling convention yet parameter storage is locked */

void HUD_Update(void)

{
  bool bVar1;
  short sVar2;
  short asStack16[4];

  if ((gameTrackerX.gameMode == 6) && (HUD_State == 0))
  {
    HUD_State = 10;
  }
  else
  {
    if (gameTrackerX.gameMode == 6)
    {
      if ((1 < HUD_State) && (HUD_State < 7))
      {
        return;
      }
    }
    else
    {
      if ((uint)(ushort)HUD_State - 10 < 2)
      {
        HUD_State = 0xc;
      }
    }
  }
  sVar2 = HUD_Wait + -1;
  if (HUD_Wait < 1)
  {
    sVar2 = HUD_Wait;
    switch (HUD_State)
    {
    default:
      HUD_Position = -1000;
      HUD_Rotation = 0;
      HUD_Rot_vel = 0;
      HUD_Pos_vel = 0;
      sVar2 = HUD_Wait;
      if (HUD_Count == 5)
      {
        HUD_Count = 0;
        sVar2 = HUD_Wait;
      }
      break;
    case 1:
    case 10:
      HUD_Damp(&HUD_Position, 0, &HUD_Pos_vel, 0x60);
      if (-1 < HUD_Position)
      {
        HUD_Position = 0;
        bVar1 = HUD_State != 10;
        HUD_State = 0xb;
        if ((bVar1) && (HUD_State = 2, HUD_Count < 1))
        {
          HUD_State = 3;
        }
      }
      sVar2 = HUD_Wait;
      if (HUD_State == 10)
      {
        MANNA_Pickup_Time = 0;
        CriticalDampValue(5, &MANNA_Position, 0x18, &MANNA_Pos_vel, asStack16, 0xc);
        sVar2 = HUD_Wait;
      }
      break;
    case 2:
      HUD_Damp(&HUD_Rotation, 0x333, &HUD_Rot_vel, 0x50);
      sVar2 = HUD_Wait;
      if (0x332 < HUD_Rotation)
      {
        HUD_Rotation = 0x333;
        HUD_State = 3;
        sVar2 = HUD_Wait;
      }
      break;
    case 3:
    case 4:
    case 0xb:
      break;
    case 5:
      HUD_State = 6;
      HUD_Wait = 10;
      HUD_Rotation = 0;
      HUD_Captured = 0;
      HUD_Count = HUD_Count + 1;
      HUD_Count_Overall = HUD_Count_Overall + 1;
      sVar2 = HUD_Wait;
      break;
    case 6:
    case 0xc:
      HUD_Damp(&HUD_Position, -1000, &HUD_Pos_vel, 0x60);
      sVar2 = HUD_Wait;
      if (HUD_Position < -999)
      {
        HUD_State = 0;
        sVar2 = HUD_Wait;
      }
    }
  }
  HUD_Wait = sVar2;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HUD_Draw()
// line 1231, offset 0x8007c4c0
/* begin block 1 */
// Start line: 1232
// Start offset: 0x8007C4C0
// Variables:
// 		struct _SVector Rotation; // stack offset -80
// 		struct _SVector Pos; // stack offset -72
// 		struct _SVector offset; // stack offset -64
// 		int n; // $s0

/* begin block 1.1 */
// Start line: 1238
// Start offset: 0x8007C4F8
// Variables:
// 		struct DVECTOR center; // stack offset -56
// 		int glow; // $a1
// 		int left; // $t0
// 		int right; // $s0
/* end block 1.1 */
// End offset: 0x8007C66C
// End Line: 1276

/* begin block 1.2 */
// Start line: 1284
// Start offset: 0x8007C690
// Variables:
// 		int oldx; // $s2
// 		int oldy; // $s3
// 		int MANNA_Count; // $s1
// 		int MANNA_Max; // $s0
/* end block 1.2 */
// End offset: 0x8007C750
// End Line: 1307

/* begin block 1.3 */
// Start line: 1313
// Start offset: 0x8007C784
// Variables:
// 		struct _SVector targetPos; // stack offset -48
// 		struct _SVector accl; // stack offset -40
// 		struct _SVector HUD_Cap_Rot; // stack offset -32
/* end block 1.3 */
// End offset: 0x8007C85C
// End Line: 1334

/* begin block 1.4 */
// Start line: 1345
// Start offset: 0x8007C8C0
/* end block 1.4 */
// End offset: 0x8007C904
// End Line: 1355
/* end block 1 */
// End offset: 0x8007C958
// End Line: 1364

/* begin block 2 */
// Start line: 2880
/* end block 2 */
// End Line: 2881

/* WARNING: Unknown calling convention yet parameter storage is locked */

void HUD_Draw(void)

{
  bool bVar1;
  long lVar2;
  long lVar3;
  int fade;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  int fade_00;
  uint uVar7;
  undefined **ppuVar8;
  _SVector local_50;
  _SVector local_48;
  _SVector local_40;
  DVECTOR local_38[2];
  _Position local_30;
  _SVector _Stack40;
  _SVector local_20;

  if ((theCamera.instance_mode & 0x80000000) == 0)
  {
    if (warpDraw == 0)
      goto LAB_8007c66c;
    warpDraw = warpDraw - (gameTrackerX.timeMult >> 4);
    if (warpDraw < 0)
    {
      warpDraw = 0;
    }
  }
  else
  {
    warpDraw = warpDraw + (gameTrackerX.timeMult >> 4);
    if (0x1000 < warpDraw)
    {
      warpDraw = 0x1000;
    }
  }
  HUD_GetPlayerScreenPt(local_38);
  fade = rcos(glowdeg);
  fade = (warpDraw / 10) * fade;
  if (fade < 0)
  {
    fade = fade + 0xfff;
  }
  fade = warpDraw / 3 + (fade >> 0xc);
  if (fade < 0)
  {
    fade = 0;
  }
  glowdeg = glowdeg + (gameTrackerX.timeMult >> 5);
  fade_00 = fade;
  if (hud_warp_arrow_flash < 1)
  {
  LAB_8007c5f8:
    if (hud_warp_arrow_flash < 0)
    {
      iVar4 = hud_warp_arrow_flash + (gameTrackerX.timeMult >> 3);
      fade = fade - hud_warp_arrow_flash;
      hud_warp_arrow_flash = iVar4;
      if (0 < iVar4)
      {
        hud_warp_arrow_flash = 0;
      }
    }
  }
  else
  {
    iVar4 = hud_warp_arrow_flash - (gameTrackerX.timeMult >> 3);
    fade_00 = fade + hud_warp_arrow_flash;
    hud_warp_arrow_flash = iVar4;
    if (iVar4 < 0)
    {
      hud_warp_arrow_flash = 0;
      goto LAB_8007c5f8;
    }
  }
  FX_MakeWarpArrow((int)local_38[0].vx + -0x40, (int)local_38[0].vy, -0x40, 0x20, fade);
  FX_MakeWarpArrow((int)local_38[0].vx + 0x40, (int)local_38[0].vy, 0x40, 0x20, fade_00);
LAB_8007c66c:
  HUD_Update();
  lVar3 = fontTracker.font_ypos;
  lVar2 = fontTracker.font_xpos;
  local_40.x = 0;
  local_40.y = 0;
  local_40.z = 0x87;
  if (-0x40 < MANNA_Position)
  {
    uVar5 = INSTANCE_Query(gameTrackerX.playerInstance, 0x20);
    uVar6 = INSTANCE_Query(gameTrackerX.playerInstance, 0x2d);
    FX_MakeMannaIcon((int)MANNA_Position, 0x17, 0x33, 0x20);
    FONT_Flush();
    FONT_SetCursor((short)(((uint)(ushort)MANNA_Position + 0x3a) * 0x10000 >> 0x10), 0x20);
    if (glyph_cost != -1)
    {
      FONT_Print(&DAT_800cf5d8);
    }
    if ((int)uVar6 <= (int)uVar5)
    {
      FONT_SetColorIndex(2);
    }
    FONT_Print((char *)&PTR_DAT_800cf5dc);
    FONT_SetColorIndex(0);
    FONT_SetCursor((short)lVar2, (short)lVar3);
    FONT_Flush();
  }
  if (-1000 < HUD_Position)
  {
    if ((HUD_Captured != 0) && (gameTrackerX.gameMode != 6))
    {
      local_20.x = 0x400;
      local_30.x = -0x600;
      local_20.y = 0;
      local_20.z = 0;
      local_30.z = 0xa00;
      if (HUD_State < 4)
      {
        local_30.y = 0x120;
      }
      else
      {
        local_30.y = 0x260;
      }
      CriticalDampPosition(1, (_Position *)&HUD_Cap_Pos, &local_30, &HUD_Cap_Vel, &_Stack40, 0x80);
      if (((HUD_Cap_Vel.x == 0) && (HUD_Cap_Vel.y == 0)) && (HUD_Cap_Vel.z == 0))
      {
        if (HUD_State == 3)
        {
          HUD_State = 4;
        }
        else
        {
          if (HUD_State == 4)
          {
            HUD_State = 5;
          }
        }
      }
      FX_DrawModel((Object *)ObjectAccess_800c8824.object, 0, &local_20, &HUD_Cap_Pos, &local_40, 0);
    }
    local_50.x = 0x400;
    local_48.y = 0x260;
    local_48.z = 0xa00;
    local_50.y = 0;
    local_40.z = 0;
    local_50.z = HUD_Rotation;
    local_48.x = HUD_Position + -0x600;
    if ((HUD_Count != 0) || (HUD_Count_Overall < 0xf))
    {
      uVar7 = 0;
      ppuVar8 = PTR_ARRAY_80011e70;
      bVar1 = true;
      do
      {
        if (bVar1)
        {
          /* WARNING: Could not recover jumptable at 0x8007c8d4. Too many branches */
          /* WARNING: Treating indirect jump as call */
          (*(code *)*ppuVar8)();
          return;
        }
        ppuVar8 = (code **)ppuVar8 + 1;
        local_50.z = local_50.z - HUD_Rotation & 0xfff;
        FX_DrawModel((Object *)ObjectAccess_800c883c.object, 0, &local_50, &local_48, &local_40,
                     (uint)((int)uVar7 < (int)HUD_Count) ^ 1);
        uVar7 = uVar7 + 1;
        bVar1 = uVar7 < 5;
      } while ((int)uVar7 < 5);
    }
  }
  return;
}
