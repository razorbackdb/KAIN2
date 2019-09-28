#include "THISDUST.H"
#include "GLYPH.H"

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
  if ((instance->flags & 0x20000U) != 0)
  {
    /* WARNING: Subroutine does not return */
    MEMPACK_Free((char *)instance->extraData);
  }
  /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(0x9c, '\x1d');
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
    /* WARNING: Subroutine does not return */
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

  In = (__MessageQueue *)((int)instance->extraData + 4);
  PurgeMessageQueue(In);
  /* WARNING: Subroutine does not return */
  EnMessageQueueData(In, (int)&DAT_00100004, 0);
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
  /* WARNING: Subroutine does not return */
  INSTANCE_Query(DAT_800d0fd8, 0x24);
}

// decompiled code
// original method signature:
// int /*$ra*/ _GlyphIsGlyphUsable(int glyph /*$s0*/)
// line 304, offset 0x8007abb4
/* begin block 1 */
// Start line: 673
/* end block 1 */
// End Line: 674

void _GlyphIsGlyphUsable(void)

{
  /* WARNING: Subroutine does not return */
  INSTANCE_Query(p_Gpffffb524, 0x13);
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
  /* WARNING: Subroutine does not return */
  INSTANCE_Query(DAT_800d0fd8, 0x24);
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
  /* WARNING: Subroutine does not return */
  INSTANCE_Query(DAT_800d0fd8, 0x30);
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
  PushMatrix();
  SetRotMatrix(DAT_800cfef0);
  /* WARNING: Subroutine does not return */
  SetTransMatrix((int)DAT_800cfef0);
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
  /* WARNING: Subroutine does not return */
  INSTANCE_Query(DAT_800d0fd8, 0x20);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ShrinkGlyphMenu(_Instance *instance)

{
  int iVar1;
  long lVar2;
  void *pvVar3;
  short asStack24[4];

  pvVar3 = instance->extraData;
  DAT_800d10f0 = DAT_800d10f0 & 0xffefffff;
  if (*(short *)((int)pvVar3 + 0x90) < 1)
  {
    _glyph_cost = 0xffff;
  }
  else
  {
    iVar1 = (uint) * (ushort *)((int)pvVar3 + 0x90) - ((uint)(DAT_800d11ec << 9) >> 0xc);
    *(undefined2 *)((int)pvVar3 + 0x90) = (short)iVar1;
    if (iVar1 * 0x10000 < 0)
    {
      *(undefined2 *)((int)pvVar3 + 0x90) = 0;
    }
    _glyph_time = *(undefined2 *)((int)pvVar3 + 0x90);
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
  if (_MANNA_Pickup_Time < 1)
  {
    CriticalDampValue(5, (short *)&MANNA_Position, -0x40, (short *)&MANNA_Pos_vel, asStack24, 0xc);
    *(undefined2 *)((int)pvVar3 + 0x8e) = 0;
  }
  else
  {
    _MANNA_Pickup_Time = _MANNA_Pickup_Time - DAT_800d11ec;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void EnlargeGlyphMenu(_Instance *instance)

{
  int iVar1;
  long lVar2;
  void *pvVar3;
  short asStack24[4];

  pvVar3 = instance->extraData;
  DAT_800d10f0 = DAT_800d10f0 | 0x100000;
  if (*(short *)((int)pvVar3 + 0x90) < 0x1000)
  {
    iVar1 = (uint) * (ushort *)((int)pvVar3 + 0x90) + ((uint)(DAT_800d11ec << 9) >> 0xc);
    *(undefined2 *)((int)pvVar3 + 0x90) = (short)iVar1;
    if (0x1000 < iVar1 * 0x10000 >> 0x10)
    {
      *(undefined2 *)((int)pvVar3 + 0x90) = 0x1000;
    }
    _glyph_time = *(undefined2 *)((int)pvVar3 + 0x90);
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
  _MANNA_Pickup_Time = 0;
  CriticalDampValue(5, (short *)&MANNA_Position, 0x18, (short *)&MANNA_Pos_vel, asStack24, 0xc);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GlyphSelectProcess(_Instance *instance, int data1, int data2)

{
  bool bVar1;
  __Event *p_Var2;
  int iVar3;
  undefined *puVar4;
  uint sample;
  ushort vol;
  void *pvVar5;
  _GlyphTuneData *glyphtunedata;

  bVar1 = false;
  pvVar5 = instance->extraData;
  glyphtunedata = (_GlyphTuneData *)instance->object->data;
  do
  {
    p_Var2 = PeekMessageQueue((__MessageQueue *)((int)pvVar5 + 4));
    if (p_Var2 == (__Event *)0x0)
    {
      iVar3 = GlyphIsPuppetShowModeOn();
      if ((iVar3 != 0) && (*(short *)((int)pvVar5 + 0x8e) == 1))
      {
        bVar1 = true;
        *(undefined2 *)((int)pvVar5 + 0x8e) = 0;
        _GlyphSwitchProcess(instance, _GlyphOffProcess);
      }
      if (!bVar1)
      {
        iVar3 = _GlyphCost(glyphtunedata, (int)*(short *)((int)pvVar5 + 0x8c));
        _glyph_cost = (undefined2)iVar3;
        EnlargeGlyphMenu(instance);
      }
      Glyph_DoFX(instance);
      return;
    }
    puVar4 = (undefined *)p_Var2->ID;
    if (puVar4 == &DAT_00100001)
    {
      bVar1 = true;
      *(undefined2 *)((int)pvVar5 + 0x8c) = 7;
      *(undefined2 *)((int)pvVar5 + 0x98) = 0xdb6;
      *(short *)((int)pvVar5 + 0x96) = (*(short *)((int)pvVar5 + 0x8c) + -1) * 0x249;
      *(undefined2 *)((int)pvVar5 + 0x96) = *(undefined2 *)((int)pvVar5 + 0x98);
    }
    else
    {
      if ((int)puVar4 < 0x100002)
      {
        if (puVar4 == (undefined *)0x80000000)
        {
          if (((short)debug_cameraMode == 0) &&
              (iVar3 = _GlyphIsGlyphSet((int)*(short *)((int)pvVar5 + 0x8c)), iVar3 != 0))
          {
            /* WARNING: Subroutine does not return */
            INSTANCE_Query(DAT_800d0fd8, 0x20);
          }
          sample = 0x10;
          vol = 100;
        }
        else
        {
          if (puVar4 != &DAT_80000010)
            goto LAB_8007b8d0;
          bVar1 = true;
          _GlyphSwitchProcess(instance, _GlyphOffProcess);
          *(undefined2 *)((int)pvVar5 + 0x8e) = 0;
          sample = 0xf;
          vol = 0x7f;
        }
        SndPlayVolPan(sample, vol, 0x40, 0);
      }
      else
      {
        if (puVar4 == (undefined *)0x10000002)
        {
          iVar3 = _GlyphIsAnyGlyphSet();
          if (iVar3 != 0)
          {
            /* WARNING: Subroutine does not return */
            AngleDiff(*(short *)((int)pvVar5 + 0x96), *(short *)((int)pvVar5 + 0x98));
          }
        }
        else
        {
          if ((int)puVar4 < 0x10000003)
          {
            if (puVar4 == &DAT_00100004)
            {
              bVar1 = true;
            }
            else
            {
            LAB_8007b8d0:
              _GlyphDefaultProcess(instance, data1, data2);
            }
          }
          else
          {
            if (puVar4 != (undefined *)0x10000004)
              goto LAB_8007b8d0;
            iVar3 = _GlyphIsAnyGlyphSet();
            if (iVar3 != 0)
            {
              /* WARNING: Subroutine does not return */
              AngleDiff(*(short *)((int)pvVar5 + 0x96), *(short *)((int)pvVar5 + 0x98));
            }
          }
        }
      }
    }
    DeMessageQueue((__MessageQueue *)((int)pvVar5 + 4));
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

void Glyph_StartSpell(undefined4 param_1, undefined4 param_2)

{
  int Message;

  Message = 0;
  switch (param_2)
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
  /* WARNING: Subroutine does not return */
  INSTANCE_Post(p_Gpffffb524, Message, 0);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Glyph_Broadcast(_Instance *sender, int glyphnum)

{
  if (glyphnum - 1U < 7)
  {
    switch (glyphnum)
    {
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      goto switchD_8007baac_caseD_7;
    }
  }
  if (*(_Instance **)(DAT_800d0fe0 + 4) != (_Instance *)0x0)
  {
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(*(_Instance **)(DAT_800d0fe0 + 4), 1);
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

void Glyph_DoSpell(int param_1, int param_2)

{
  long startColor;
  int colorChangeRadius;
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
  colorChangeRadius = *(int *)(*(int *)(param_1 + 0x1c) + 0x1c);
  sGpffff9b18 = 0;
  local_30 = 0;
  MATH3D_SetUnityMatrix(&MStack80);
  uGpffffee1c = 0;
  iGpffffee18 = (int)*(short *)(colorChangeRadius + (param_2 + -1) * 2 + 0xc);
  pred_offset = 0;
  colorChangeRadius = iGpffffee18;
  if (iGpffffee18 < 0)
  {
    colorChangeRadius = iGpffffee18 + 3;
  }
  colorChangeRadius = iGpffffee18 - (colorChangeRadius >> 2);
  startColor = local_30;
  switch (param_2)
  {
  case 1:
    radius = 1;
    startColor = 0xc0c0c0;
    height1 = -0x100;
    height2 = 0x100;
    height3 = 0x300;
    vel = (undefined *)0x200000;
    size1 = -0x280;
    sGpffff9b18 = 1;
    size2 = 0;
    break;
  case 2:
    CAMERA_SetShake((Camera *)&gp0xffffa3dc, 0x3c, 0x800);
    radius = 0x280;
    vel = &UNK_00140000;
    startColor = 0xa0a0a0;
    height3 = 0;
    height2 = 0;
    height1 = 0;
    size1 = 0x280;
    sGpffff9b18 = 2;
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
    sGpffff9b18 = 3;
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
    sGpffff9b18 = 4;
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
    sGpffff9b18 = 5;
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
    sGpffff9b18 = 6;
    size2 = 0x340;
  }
  if ((sGpffff9b18 != 0) &&
      (p_Gpffff9b1c = FX_DoBlastRing((_Instance *)0x0, (_SVector *)(param_1 + 0x5c), &MStack80, -1,
                                     radius, iGpffffee18, colorChangeRadius, size1, size2, (int)vel, -0x800, height1, height2, height3, startColor, 0, pred_offset, -99, 0),
       p_Gpffff9b1c == (_FXBlastringEffect *)0x0))
  {
    sGpffff9b18 = 0;
  }
  iGpffffee18 = iGpffffee18 << 0xc;
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
  long lVar1;

  lVar1 = debugVoiceIndex;
  debug_cameraMode._0_2_ = 0;
  debugVoiceIndex = 0;
  *(undefined2 *)(lVar1 + 0xe) = 0;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Glyph_DoFX(_Instance *instance)

{
  int *piVar1;
  long lVar2;

  if (((DAT_800d111e != 6) && ((DAT_800d10f0 & 0x100000) == 0)) &&
      ((int)(short)debug_cameraMode != 0))
  {
    Glyph_Broadcast(instance, (int)(short)debug_cameraMode);
    _fx_radius_old = *(int *)(debugVoiceIndex + 0x3c);
    if (_blast_range < _fx_radius_old)
    {
      Glyph_EndFX();
    }
    lVar2 = debugVoiceIndex;
    if ((short)debug_cameraMode == 5)
    {
      piVar1 = (int *)(debugVoiceIndex + 100);
      *(int *)(debugVoiceIndex + 0x5c) = *(int *)(debugVoiceIndex + 0x5c) + -0x3c;
      *(int *)(lVar2 + 100) = *piVar1 + 0x3c;
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

void _GlyphGenericProcess(_Instance *param_1, int param_2, int param_3)

{
  __Event *p_Var1;
  int Data;
  undefined *puVar2;
  _GlyphTuneData *glyphtunedata;
  void *pvVar3;

  pvVar3 = param_1->extraData;
  ShrinkGlyphMenu(param_1);
  do
  {
    p_Var1 = PeekMessageQueue((__MessageQueue *)((int)pvVar3 + 4));
    if (p_Var1 == (__Event *)0x0)
    {
      if (sGpffffee0e == 0)
      {
        Glyph_DoFX(param_1);
        return;
      }
      glyphtunedata = (_GlyphTuneData *)param_1->object->data;
      Glyph_DoSpell((int)param_1, (int)*(short *)((int)pvVar3 + 0x8c));
      sGpffffee0e = 0;
      Data = _GlyphCost(glyphtunedata, (int)*(short *)((int)pvVar3 + 0x8c));
      /* WARNING: Subroutine does not return */
      INSTANCE_Post(p_Gpffffb524, 0x40008, Data);
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == &DAT_00100001)
    {
      Glyph_StartSpell(param_1, (int)*(short *)((int)pvVar3 + 0x8c));
    }
    else
    {
      if ((int)puVar2 < 0x100002)
      {
        if (puVar2 == (undefined *)0x80000000)
        {
          _GlyphSwitchProcess(param_1, _GlyphOffProcess);
          *(undefined2 *)((int)pvVar3 + 0x8e) = 0;
        }
        else
        {
        LAB_8007c088:
          _GlyphDefaultProcess(param_1, param_2, param_3);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void GlyphTrigger(void)

{
  if ((short)debug_cameraMode == 0)
  {
    _glyph_trigger = 1;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void MANNA_Pickup(void)

{
  _MANNA_Position = 0x18;
  _MANNA_Pickup_Time = 0x1e000;
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
  /* WARNING: Subroutine does not return */
  ApplyMatrixSV(DAT_800cff00, &instance->position, &HUD_Cap_Pos);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void HUD_Init(void)

{
  _HUD_Count = 0;
  _HUD_Count_Overall = 0;
  _HUD_Rotation = 0;
  _HUD_Rot_vel = 0;
  _HUD_Position = 0xfc18;
  _HUD_Pos_vel = 0;
  _HUD_State = 0;
  _HUD_Wait = 0;
  _warpDraw = 0;
  _glowdeg = 0;
  _hud_warp_arrow_flash = 0;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void HUD_Setup_Chit_Count(int chits)

{
  _HUD_Count = (short)chits + (short)(chits / 5) * -5;
  _HUD_Count_Overall = (short)chits;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void HUD_Update(void)

{
  bool bVar1;
  short sVar2;
  short asStack16[4];

  if ((DAT_800d111e == 6) && (_HUD_State == 0))
  {
    _HUD_State = 10;
  }
  else
  {
    if (DAT_800d111e == 6)
    {
      if ((1 < (short)_HUD_State) && ((short)_HUD_State < 7))
      {
        return;
      }
    }
    else
    {
      if ((uint)_HUD_State - 10 < 2)
      {
        _HUD_State = 0xc;
      }
    }
  }
  sVar2 = _HUD_Wait + -1;
  if (_HUD_Wait < 1)
  {
    sVar2 = _HUD_Wait;
    switch (_HUD_State)
    {
    default:
      _HUD_Position = -1000;
      _HUD_Rotation = 0;
      _HUD_Rot_vel = 0;
      _HUD_Pos_vel = 0;
      if (_HUD_Count == 5)
      {
        _HUD_Count = 0;
      }
      break;
    case 1:
    case 10:
      HUD_Damp((short *)&HUD_Position, 0, (short *)&HUD_Pos_vel, 0x60);
      if (-1 < _HUD_Position)
      {
        _HUD_Position = 0;
        bVar1 = _HUD_State != 10;
        _HUD_State = 0xb;
        if ((bVar1) && (_HUD_State = 2, _HUD_Count < 1))
        {
          _HUD_State = 3;
        }
      }
      sVar2 = _HUD_Wait;
      if (_HUD_State == 10)
      {
        _MANNA_Pickup_Time = 0;
        CriticalDampValue(5, (short *)&MANNA_Position, 0x18, (short *)&MANNA_Pos_vel, asStack16, 0xc);
        sVar2 = _HUD_Wait;
      }
      break;
    case 2:
      HUD_Damp((short *)&HUD_Rotation, 0x333, (short *)&HUD_Rot_vel, 0x50);
      sVar2 = _HUD_Wait;
      if (0x332 < _HUD_Rotation)
      {
        _HUD_Rotation = 0x333;
        _HUD_State = 3;
      }
      break;
    case 3:
    case 4:
    case 0xb:
      break;
    case 5:
      _HUD_State = 6;
      _HUD_Wait = 10;
      _HUD_Rotation = 0;
      debugTimeMult._0_2_ = 0;
      _HUD_Count = _HUD_Count + 1;
      _HUD_Count_Overall = _HUD_Count_Overall + 1;
      sVar2 = _HUD_Wait;
      break;
    case 6:
    case 0xc:
      HUD_Damp((short *)&HUD_Position, -1000, (short *)&HUD_Pos_vel, 0x60);
      sVar2 = _HUD_Wait;
      if (_HUD_Position < -999)
      {
        _HUD_State = 0;
      }
    }
  }
  _HUD_Wait = sVar2;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void HUD_Draw(void)

{
  bool bVar1;
  uint uVar2;
  undefined **ppuVar3;
  _SVector local_50;
  _SVector local_48;
  _SVector local_40;
  DVECTOR local_38[2];
  _Position local_30;
  _SVector _Stack40;
  _SVector local_20;

  if ((DAT_800d032c & 0x80000000) == 0)
  {
    if (_warpDraw == 0)
    {
      HUD_Update();
      local_40.x = 0;
      local_40.y = 0;
      local_40.z = 0x87;
      if (-0x40 < _MANNA_Position)
      {
        /* WARNING: Subroutine does not return */
        INSTANCE_Query(DAT_800d0fd8, 0x20);
      }
      if (-1000 < _HUD_Position)
      {
        if (((short)debugTimeMult != 0) && (DAT_800d111e != 6))
        {
          local_20.x = 0x400;
          local_30.x = -0x600;
          local_20.y = 0;
          local_20.z = 0;
          local_30.z = 0xa00;
          if (_HUD_State < 4)
          {
            local_30.y = 0x120;
          }
          else
          {
            local_30.y = 0x260;
          }
          CriticalDampPosition(1, (_Position *)&HUD_Cap_Pos, &local_30, (_SVector *)&HUD_Cap_Vel, &_Stack40, 0x80);
          if (((_HUD_Cap_Vel == 0) && (_CHAR____800d48ee == 0)) && (_CHAR____800d48f0 == 0))
          {
            if (_HUD_State == 3)
            {
              _HUD_State = 4;
            }
            else
            {
              if (_HUD_State == 4)
              {
                _HUD_State = 5;
              }
            }
          }
          FX_DrawModel((Object *)DebugMenuLine_800c8828.type, 0, &local_20, (_SVector *)&HUD_Cap_Pos,
                       &local_40, 0);
        }
        local_50.x = 0x400;
        local_48.y = 0x260;
        local_48.z = 0xa00;
        local_50.y = 0;
        local_40.z = 0;
        local_50.z = _HUD_Rotation;
        local_48.x = _HUD_Position + -0x600;
        if ((_HUD_Count != 0) || (_HUD_Count_Overall < 0xf))
        {
          uVar2 = 0;
          ppuVar3 = PTR_ARRAY_80011e70;
          bVar1 = true;
          do
          {
            if (bVar1)
            {
              /* WARNING: Could not recover jumptable at 0x8007c8d4. Too many branches */
              /* WARNING: Treating indirect jump as call */
              (*(code *)*ppuVar3)();
              return;
            }
            ppuVar3 = (code **)ppuVar3 + 1;
            local_50.z = local_50.z - _HUD_Rotation & 0xfff;
            FX_DrawModel((Object *)DebugMenuLine_800c8840.type, 0, &local_50, &local_48, &local_40,
                         (uint)((int)uVar2 < (int)_HUD_Count) ^ 1);
            uVar2 = uVar2 + 1;
            bVar1 = uVar2 < 5;
          } while ((int)uVar2 < 5);
        }
      }
      return;
    }
    _warpDraw = _warpDraw - (DAT_800d11ec >> 4);
    if (_warpDraw < 0)
    {
      _warpDraw = 0;
    }
  }
  else
  {
    _warpDraw = _warpDraw + (DAT_800d11ec >> 4);
    if (0x1000 < _warpDraw)
    {
      _warpDraw = 0x1000;
    }
  }
  HUD_GetPlayerScreenPt(local_38);
  /* WARNING: Subroutine does not return */
  rcos(_glowdeg);
}
