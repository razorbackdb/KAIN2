#include "THISDUST.H"
#include "EVENT.H"

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_UpdateResetSignalArrayAndWaterMovement(struct Level *oldLevel /*$a0*/, struct Level *newLevel /*$a1*/, long sizeOfLevel /*$a2*/)
// line 151, offset 0x800605d0
/* begin block 1 */
// Start line: 152
// Start offset: 0x800605D0
// Variables:
// 		long offset; // $a1
// 		long i; // $t0

/* begin block 1.1 */
// Start line: 173
// Start offset: 0x80060648
// Variables:
// 		struct WaterLevelProcess *curWater; // $t1
/* end block 1.1 */
// End offset: 0x800606A4
// End Line: 186
/* end block 1 */
// End offset: 0x800606A4
// End Line: 188

/* begin block 2 */
// Start line: 302
/* end block 2 */
// End Line: 303

/* begin block 3 */
// Start line: 307
/* end block 3 */
// End Line: 308

void EVENT_UpdateResetSignalArrayAndWaterMovement(Level *oldLevel, Level *newLevel, long sizeOfLevel)

{
  int iVar1;
  Level *pLVar2;
  Level *pLVar3;
  FontChar *pFVar4;
  Level **ppLVar5;
  int iVar6;
  SVECTOR *pSVar7;

  if (NumSignalsToReset != 0)
  {
    iVar6 = 0;
    pFVar4 = fontTracker.font_buffer + 0x28;
    do
    {
      if (0 < *(int *)&pFVar4->c)
      {
        pLVar3 = *(Level **)pFVar4;
        if ((oldLevel <= pLVar3) && (pLVar3 <= (Level *)((int)&oldLevel->terrain + sizeOfLevel)))
        {
          iVar1 = 0;
          if (pLVar3 != (Level *)0x0)
          {
            iVar1 = (int)pLVar3 + (int)(Level *)((int)newLevel - (int)oldLevel);
          }
          *(int *)pFVar4 = iVar1;
        }
      }
      iVar6 = iVar6 + 1;
      pFVar4 = (FontChar *)&pFVar4[1].y;
    } while (iVar6 < 0x10);
  }
  iVar6 = 5;
  if (WaterInUse != 0)
  {
    pSVar7 = &WaterLevelArray;
    ppLVar5 = (Level **)&WaterLevelArray.vz;
    do
    {
      if ((*(uint *)pSVar7 & 1) != 0)
      {
        pLVar3 = *ppLVar5;
        if ((oldLevel <= pLVar3) && (pLVar3 <= (Level *)((int)&oldLevel->terrain + sizeOfLevel)))
        {
          pLVar2 = (Level *)0x0;
          if (pLVar3 != (Level *)0x0)
          {
            pLVar2 = (Level *)((int)pLVar3 + (int)(Level *)((int)newLevel - (int)oldLevel));
          }
          *ppLVar5 = pLVar2;
        }
      }
      iVar6 = iVar6 + -1;
      ppLVar5 = ppLVar5 + 7;
      pSVar7 = (SVECTOR *)&pSVar7[3].vz;
    } while (0 < iVar6);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_ResetAllOneTimeVariables()
// line 191, offset 0x800606ac
/* begin block 1 */
// Start line: 193
// Start offset: 0x800606AC
// Variables:
// 		int i; // $a2
/* end block 1 */
// End offset: 0x8006070C
// End Line: 213

/* begin block 2 */
// Start line: 394
/* end block 2 */
// End Line: 395

/* begin block 3 */
// Start line: 395
/* end block 3 */
// End Line: 396

/* begin block 4 */
// Start line: 398
/* end block 4 */
// End Line: 399

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_ResetAllOneTimeVariables(void)

{
  int iVar1;
  FontChar *pFVar2;
  int iVar3;

  iVar3 = 0;
  if (NumSignalsToReset != 0)
  {
    pFVar2 = fontTracker.font_buffer + 0x28;
    do
    {
      iVar1 = *(int *)&pFVar2->c + -1;
      if ((0 < *(int *)&pFVar2->c) && (*(int *)&pFVar2->c = iVar1, iVar1 == 0))
      {
        NumSignalsToReset = NumSignalsToReset + -1;
        *(ushort *)(*(int *)pFVar2 + 6) = *(ushort *)(*(int *)pFVar2 + 6) & 0xfffe;
        *(undefined4 *)&pFVar2->c = 0;
      }
      iVar3 = iVar3 + 1;
      pFVar2 = (FontChar *)&pFVar2[1].y;
    } while (iVar3 < 0x10);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_AddSignalToReset(struct _MultiSignal *mSignal /*$a0*/)
// line 215, offset 0x80060714
/* begin block 1 */
// Start line: 217
// Start offset: 0x80060714
// Variables:
// 		int i; // $a1
/* end block 1 */
// End offset: 0x80060768
// End Line: 240

/* begin block 2 */
// Start line: 454
/* end block 2 */
// End Line: 455

/* begin block 3 */
// Start line: 455
/* end block 3 */
// End Line: 456

/* begin block 4 */
// Start line: 457
/* end block 4 */
// End Line: 458

void EVENT_AddSignalToReset(_MultiSignal *mSignal)

{
  FontChar *pFVar1;
  int iVar2;

  iVar2 = 0;
  if (NumSignalsToReset < 0x10)
  {
    pFVar1 = fontTracker.font_buffer + 0x28;
    while (iVar2 = iVar2 + 1, *(int *)&pFVar1->c != 0)
    {
      pFVar1 = (FontChar *)&pFVar1[1].y;
      if (0xf < iVar2)
      {
        return;
      }
    }
    *(undefined **)&pFVar1->c = &UNK_00000001;
    *(_MultiSignal **)pFVar1 = mSignal;
    NumSignalsToReset = NumSignalsToReset + 1;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HINT_ResetHint()
// line 266, offset 0x80060770
/* begin block 1 */
// Start line: 565
/* end block 1 */
// End Line: 566

/* WARNING: Unknown calling convention yet parameter storage is locked */

void HINT_ResetHint(void)

{
  /* WARNING: Subroutine does not return */
  memset(&fontTracker.font_buffer[0x3e].c, 0, 0x10);
}

// decompiled code
// original method signature:
// void /*$ra*/ HINT_StartHint(short hintNumber /*$a0*/)
// line 271, offset 0x80060798
/* begin block 1 */
// Start line: 273
// Start offset: 0x80060798
// Variables:
// 		int h; // $a1
/* end block 1 */
// End offset: 0x800607F4
// End Line: 296

/* begin block 2 */
// Start line: 576
/* end block 2 */
// End Line: 577

/* begin block 3 */
// Start line: 577
/* end block 3 */
// End Line: 578

/* begin block 4 */
// Start line: 580
/* end block 4 */
// End Line: 581

void HINT_StartHint(short hintNumber)

{
  if ((GlobalSave->flags & 1U) == 0)
  {
    fontTracker.font_buffer[63].y = hintNumber + 0x37;
    /* WARNING: Read-only address (ram,0x800d2afc) is written */
    fontTracker.font_buffer[62]._4_2_ = 3;
    /* WARNING: Read-only address (ram,0x800d2afe) is written */
    if (0x35 < (ushort)hintNumber)
    {
      fontTracker.font_buffer[63].y = 0x6c;
    }
    /* WARNING: Read-only address (ram,0x800d2b00) is written */
    /* WARNING: Read-only address (ram,0x800d2b04) is written */
    fontTracker.font_buffer[64]._0_4_ = 0xf000;
    fontTracker.font_buffer._388_4_ = *(undefined4 *)(DAT_800d0fd8 + 0x38);
    /* WARNING: Read-only address (ram,0x800d2b08) is written */
    fontTracker.font_buffer[63].x = hintNumber;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HINT_StopHint()
// line 298, offset 0x800607fc
/* begin block 1 */
// Start line: 645
/* end block 1 */
// End Line: 646

/* begin block 2 */
// Start line: 650
/* end block 2 */
// End Line: 651

/* WARNING: Unknown calling convention yet parameter storage is locked */

void HINT_StopHint(void)

{
  uint uVar1;

  uVar1 = fontTracker.font_buffer._376_4_;
  if ((fontTracker.font_buffer._376_4_ & 1) == 0)
  {
    /* WARNING: Read-only address (ram,0x800d2afc) is written */
    /* WARNING: Read-only address (ram,0x800d2b04) is written */
    return;
  }
  if ((fontTracker.font_buffer._376_4_ & 6) == 0)
  {
    /* WARNING: Read-only address (ram,0x800d2afc) is written */
    fontTracker.font_buffer._376_4_ = fontTracker.font_buffer._376_4_ | 4;
    if ((uVar1 & 2) == 0)
    {
      fontTracker.font_buffer[64]._0_4_ = 0xf000;
      return;
    }
    /* WARNING: Read-only address (ram,0x800d2afc) is written */
    fontTracker.font_buffer._376_4_ = uVar1 & 0xfffffffd | 4;
    fontTracker.font_buffer[64]._0_4_ = 0xf000 - fontTracker.font_buffer[64]._0_4_;
    /* WARNING: Read-only address (ram,0x800d2b04) is written */
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HINT_KillSpecificHint(short hintNumber /*$a0*/)
// line 323, offset 0x80060860
/* begin block 1 */
// Start line: 696
/* end block 1 */
// End Line: 697

void HINT_KillSpecificHint(short hintNumber)

{
  if (fontTracker.font_buffer[63].x == hintNumber)
  {
    HINT_StopHint();
  }
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ HINT_GetCurrentHint()
// line 331, offset 0x80060890
/* begin block 1 */
// Start line: 712
/* end block 1 */
// End Line: 713

/* begin block 2 */
// Start line: 713
/* end block 2 */
// End Line: 714

/* WARNING: Unknown calling convention yet parameter storage is locked */

long HINT_GetCurrentHint(void)

{
  long lVar1;

  lVar1 = -1;
  if ((fontTracker.font_buffer[62]._4_2_ & 1) != 0)
  {
    lVar1 = (long)fontTracker.font_buffer[63].x;
  }
  return lVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_ProcessTimers()
// line 343, offset 0x800608b0
/* begin block 1 */
// Start line: 344
// Start offset: 0x800608B0
// Variables:
// 		int i; // $s2
// 		struct EventTimer *eventTimer; // $s0
/* end block 1 */
// End offset: 0x800609B4
// End Line: 397

/* begin block 2 */
// Start line: 736
/* end block 2 */
// End Line: 737

/* begin block 3 */
// Start line: 746
/* end block 3 */
// End Line: 747

void LOAD_PlayXA(int number)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  EventTimer *timer;
  int iVar4;
  int iVar5;

  if (PTR_800d44f8 != (_Instance *)0x0)
  {
    iVar5 = 0;
    iVar4 = 0;
    do
    {
      timer = (EventTimer *)((int)&EventTimer_800d42a0.nextEventIndex + iVar4);
      uVar2 = timer->flags;
      if ((uVar2 & 1) != 0)
      {
        if ((uint)((int)uVar2 >> 1) < fontTracker.font_buffer._844_4_)
        {
          timer->flags = uVar2 & 1;
        }
        else
        {
          timer->flags = uVar2 & 1 | (((int)uVar2 >> 1) - fontTracker.font_buffer._844_4_) * 2;
        }
        if (timer->flags >> 1 < 1)
        {
          iVar3 = *(int *)((int)&EventTimer_800d42bc.time + iVar4);
          EventTimer_800d4214.time = *(long *)((int)&EventTimer_800d42bc.flags + iVar4);
          timer->flags = timer->flags & 1;
          /* WARNING: Read-only address (ram,0x800d4218) is written */
          *(ushort *)(iVar3 + 2) = *(ushort *)(iVar3 + 2) & 0xfffe;
          EVENT_RemoveTimer(timer);
          EventTimer_800d42a0.level = *(Level **)((int)&EventTimer_800d42bc.actionScript + iVar4);
          DAT_800d1024 = *(int *)((int)&EventTimer_800d42bc.scriptPos + iVar4);
          DAT_800d1018 = 0;
          /* WARNING: Read-only address (ram,0x800d42b4) is written */
          lVar1 = EVENT_DoAction(*(Event **)((int)&EventTimer_800d42bc.flags + iVar4),
                                 *(ScriptPCode **)((int)&EventTimer_800d42bc.time + iVar4),
                                 *(short **)((int)&EventTimer_800d42bc.event + iVar4));
          if ((lVar1 != 0) && (DAT_800d1024 != -1))
          {
            EVENT_Process(*(Event **)((int)&EventTimer_800d42bc.flags + iVar4), DAT_800d1024);
          }
        }
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x18;
    } while (iVar5 < 0x18);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_ProcessHints()
// line 398, offset 0x800609cc
/* begin block 1 */
// Start line: 399
// Start offset: 0x800609CC

/* begin block 1.1 */
// Start line: 404
// Start offset: 0x800609E4
// Variables:
// 		char string[128]; // stack offset -136
// 		long y; // $s0
/* end block 1.1 */
// End offset: 0x80060B7C
// End Line: 471
/* end block 1 */
// End offset: 0x80060B7C
// End Line: 472

/* begin block 2 */
// Start line: 899
/* end block 2 */
// End Line: 900

/* begin block 3 */
// Start line: 902
/* end block 3 */
// End Line: 903

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_ProcessHints(void)

{
  char acStack136[128];

  if ((fontTracker.font_buffer[62]._4_2_ & 1) != 0)
  {
    localstr_get((int)fontTracker.font_buffer[63].y);
    /* WARNING: Subroutine does not return */
    sprintf(acStack136, (char *)&PTR_LAB_000a7324_1_800cf54c);
  }
  return;
}

// decompiled code
// original method signature:
// struct EventTimer * /*$ra*/ EVENT_GetNextTimer()
// line 474, offset 0x80060b8c
/* begin block 1 */
// Start line: 475
// Start offset: 0x80060B8C
// Variables:
// 		int i; // $a0

/* begin block 1.1 */
// Start line: 480
// Start offset: 0x80060BA0
// Variables:
// 		struct EventTimer *eventTimer; // $v1
/* end block 1.1 */
// End offset: 0x80060BEC
// End Line: 492
/* end block 1 */
// End offset: 0x80060BF0
// End Line: 494

/* begin block 2 */
// Start line: 1056
/* end block 2 */
// End Line: 1057

/* begin block 3 */
// Start line: 1059
/* end block 3 */
// End Line: 1060

void EVENT_UpdateResetSignalArrayAndWaterMovement(Level *oldLevel, Level *newLevel, long sizeOfLevel)

{
  uint *puVar1;
  int iVar2;

  if ((int)PTR_800d44f8 < 0x18)
  {
    puVar1 = (uint *)&EventTimer_800d42a0.nextEventIndex;
    iVar2 = 0x18;
    do
    {
      iVar2 = iVar2 + -1;
      if ((*puVar1 & 1) == 0)
      {
        PTR_800d44f8 = (_Instance *)((int)&(PTR_800d44f8->node).prev + 1);
        *puVar1 = *puVar1 & 0xfffffffe | 1;
        return;
      }
      puVar1 = puVar1 + 6;
    } while (0 < iVar2);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_RemoveTimer(struct EventTimer *timer /*$a0*/)
// line 496, offset 0x80060bf8
/* begin block 1 */
// Start line: 1109
/* end block 1 */
// End Line: 1110

/* begin block 2 */
// Start line: 1110
/* end block 2 */
// End Line: 1111

void EVENT_RemoveTimer(EventTimer *timer)

{
  if (timer != (EventTimer *)0x0)
  {
    fontTracker.font_buffer[24]._0_4_ = fontTracker.font_buffer[24]._0_4_ + -1;
    /* WARNING: Read-only address (ram,0x800d2a14) is written */
    timer->flags = timer->flags & 0xfffffffe;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_InitTimers()
// line 506, offset 0x80060c28
/* begin block 1 */
// Start line: 1129
/* end block 1 */
// End Line: 1130

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_InitTimers(void)

{
  /* WARNING: Read-only address (ram,0x800d2a14) is written */
  fontTracker.font_buffer[24]._0_4_ = 0;
  /* WARNING: Subroutine does not return */
  memset(&eventTimerArray, 0, 0x240);
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_InitTerrainMovement()
// line 512, offset 0x80060c54
/* begin block 1 */
// Start line: 513
// Start offset: 0x80060C54
// Variables:
// 		long i; // $s1
/* end block 1 */
// End offset: 0x80060C8C
// End Line: 520

/* begin block 2 */
// Start line: 1143
/* end block 2 */
// End Line: 1144

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_InitTerrainMovement(void)

{
  /* WARNING: Subroutine does not return */
  memset(&WaterLevelArray, 0x1c, 0);
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_Init()
// line 523, offset 0x80060ca4
/* begin block 1 */
// Start line: 1174
/* end block 1 */
// End Line: 1175

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_Init(void)

{
  EVENT_InitTerrainMovement();
  EVENT_InitTimers();
  HINT_ResetHint();
  fontTracker.font_buffer._148_4_ = 0x96000;
  fontTracker.font_buffer[38]._4_2_ = 0;
  fontTracker.font_buffer[39].y = -1;
  fontTracker.font_buffer[61]._2_4_ = 0x96000;
  fontTracker.font_buffer[62]._0_4_ = 0xffffffff;
  /* WARNING: Read-only address (ram,0x800d2af8) is written */
  /* WARNING: Read-only address (ram,0x800d2a18) is written */
  /* WARNING: Read-only address (ram,0x800d2af4) is written */
  /* WARNING: Read-only address (ram,0x800d2a6c) is written */
  /* WARNING: Read-only address (ram,0x800d2a70) is written */
  return;
}

// decompiled code
// original method signature:
// struct WaterLevelProcess * /*$ra*/ EVENT_GetNextTerrainMove()
// line 535, offset 0x80060cf0
/* begin block 1 */
// Start line: 537
// Start offset: 0x80060CF0
// Variables:
// 		int i; // $a0
/* end block 1 */
// End offset: 0x80060D20
// End Line: 551

/* begin block 2 */
// Start line: 1202
/* end block 2 */
// End Line: 1203

/* begin block 3 */
// Start line: 1203
/* end block 3 */
// End Line: 1204

/* begin block 4 */
// Start line: 1206
/* end block 4 */
// End Line: 1207

/* WARNING: Unknown calling convention yet parameter storage is locked */

WaterLevelProcess *EVENT_GetNextTerrainMove(void)

{
  SVECTOR *pSVar1;
  int iVar2;

  iVar2 = 0;
  pSVar1 = &WaterLevelArray;
  do
  {
    iVar2 = iVar2 + 1;
    if ((((WaterLevelProcess *)pSVar1)->flags & 1U) == 0)
    {
      return (WaterLevelProcess *)pSVar1;
    }
    pSVar1 = (SVECTOR *)((WaterLevelProcess *)pSVar1 + 1);
  } while (iVar2 < 5);
  return (WaterLevelProcess *)0x0;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_ProcessMovingWater()
// line 570, offset 0x80060d28
/* begin block 1 */
// Start line: 572
// Start offset: 0x80060D28
// Variables:
// 		long i; // $a3
// 		long inUse; // $t0

/* begin block 1.1 */
// Start line: 577
// Start offset: 0x80060D38
// Variables:
// 		struct WaterLevelProcess *curWater; // $a2
/* end block 1.1 */
// End offset: 0x80060E44
// End Line: 606
/* end block 1 */
// End offset: 0x80060E50
// End Line: 612

/* begin block 2 */
// Start line: 1140
/* end block 2 */
// End Line: 1141

/* begin block 3 */
// Start line: 1259
/* end block 3 */
// End Line: 1260

/* begin block 4 */
// Start line: 1262
/* end block 4 */
// End Line: 1263

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_ProcessMovingWater(void)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  SVECTOR *pSVar5;
  int iVar6;

  bVar2 = false;
  if (WaterInUse != 0)
  {
    pSVar5 = &WaterLevelArray;
    iVar6 = 5;
    piVar4 = (int *)&SVECTOR_800d2754.vz;
    do
    {
      if ((*(uint *)pSVar5 & 1) != 0)
      {
        iVar3 = piVar4[1] + DAT_800d11ec;
        piVar4[1] = iVar3;
        bVar2 = true;
        if (*piVar4 < iVar3)
        {
          piVar4[1] = *piVar4;
        }
        iVar3 = (((int)*(short *)((int)piVar4 + -2) - (int)*(short *)(piVar4 + -1)) *
                 (piVar4[1] >> 0xc)) /
                (*piVar4 >> 0xc);
        sVar1 = (short)iVar3;
        *(short *)(piVar4[-4] + 0x10) = *(short *)((int)piVar4 + -6) + sVar1;
        *(short *)(piVar4[-4] + 0x18) = *(short *)(piVar4 + -1) + sVar1;
        if ((*(uint *)pSVar5 & 2) != 0)
        {
          *(int *)(*(int *)(piVar4[-3] + 8) + 0x38) = *(short *)(piVar4 + -2) + iVar3;
          ***(ushort ***)(piVar4[-3] + 8) = ***(ushort ***)(piVar4[-3] + 8) | 1;
        }
        if (piVar4[1] == *piVar4)
        {
          *(uint *)pSVar5 = 0;
        }
      }
      iVar6 = iVar6 + -1;
      piVar4 = piVar4 + 7;
      pSVar5 = (SVECTOR *)&pSVar5[3].vz;
    } while (0 < iVar6);
  }
  if (!bVar2)
  {
    WaterInUse = 0;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_DoProcess()
// line 615, offset 0x80060e58
/* begin block 1 */
// Start line: 1372
/* end block 1 */
// End Line: 1373

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_DoProcess(void)

{
  int in_a0;

  EVENT_ProcessMovingWater();
  LOAD_PlayXA(in_a0);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_BSPProcess(struct _StreamUnit *streamUnit /*$fp*/)
// line 621, offset 0x80060e80
/* begin block 1 */
// Start line: 622
// Start offset: 0x80060E80
// Variables:
// 		long curTree; // $s5
// 		struct Level *level; // $v0
// 		struct _Terrain *terrain; // $s6

/* begin block 1.1 */
// Start line: 634
// Start offset: 0x80060ED4
// Variables:
// 		struct BSPTree *bspTree; // $a3

/* begin block 1.1.1 */
// Start line: 642
// Start offset: 0x80060EF0
// Variables:
// 		struct _Instance *instance; // $s1

/* begin block 1.1.1.1 */
// Start line: 646
// Start offset: 0x80060F00
// Variables:
// 		short dx; // $s4
// 		short dy; // $s3
// 		short dz; // $s2

/* begin block 1.1.1.1.1 */
// Start line: 663
// Start offset: 0x80060F84
// Variables:
// 		struct _Instance *attachedInstance; // $s0
// 		struct SVECTOR offset; // stack offset -48
/* end block 1.1.1.1.1 */
// End offset: 0x8006107C
// End Line: 694
/* end block 1.1.1.1 */
// End offset: 0x8006107C
// End Line: 697
/* end block 1.1.1 */
// End offset: 0x8006107C
// End Line: 698
/* end block 1.1 */
// End offset: 0x8006107C
// End Line: 699
/* end block 1 */
// End offset: 0x80061090
// End Line: 701

/* begin block 2 */
// Start line: 1384
/* end block 2 */
// End Line: 1385

void EVENT_BSPProcess(_StreamUnit *streamUnit)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  _Instance *instance;
  int iVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  int iVar9;
  _Terrain *p_Var10;
  int iVar11;
  SVECTOR local_30;

  p_Var10 = streamUnit->level->terrain;
  iVar9 = 0;
  if (0 < p_Var10->numBSPTrees)
  {
    iVar11 = 0;
    do
    {
      iVar4 = (int)&p_Var10->BSPTreeArray->bspRoot + iVar11;
      if ((-1 < *(short *)(iVar4 + 0x1a)) && (iVar5 = *(int *)(iVar4 + 0x20), iVar5 != 0))
      {
        iVar2 = *(int *)(iVar5 + 0x40);
        if ((iVar2 == 0) || (iVar3 = *(int *)(iVar5 + 0x44), iVar3 == 0))
        {
          sVar6 = *(short *)(iVar5 + 0x60);
          sVar8 = *(short *)(iVar5 + 0x5c) - *(short *)(iVar5 + 100);
          sVar1 = *(short *)(iVar5 + 0x68);
          sVar7 = *(short *)(iVar5 + 0x5e) - *(short *)(iVar5 + 0x66);
        }
        else
        {
          sVar6 = *(short *)(iVar2 + 0x1c);
          sVar8 = *(short *)(iVar2 + 0x14) - *(short *)(iVar3 + 0x14);
          sVar1 = *(short *)(iVar3 + 0x1c);
          sVar7 = *(short *)(iVar2 + 0x18) - *(short *)(iVar3 + 0x18);
        }
        sVar6 = sVar6 - sVar1;
        if (((sVar8 != 0) || (sVar7 != 0)) || (sVar6 != 0))
        {
          *(short *)(iVar4 + 0xc) = *(short *)(iVar4 + 0xc) + sVar8;
          *(short *)(iVar4 + 0xe) = *(short *)(iVar4 + 0xe) + sVar7;
          *(short *)(iVar4 + 0x10) = *(short *)(iVar4 + 0x10) + sVar6;
          *(short *)(iVar4 + 0x14) = *(short *)(iVar4 + 0x14) + sVar8;
          *(short *)(iVar4 + 0x16) = *(short *)(iVar4 + 0x16) + sVar7;
          *(short *)(iVar4 + 0x18) = *(short *)(iVar4 + 0x18) + sVar6;
          p_Var10->UnitChangeFlags = p_Var10->UnitChangeFlags | 2;
          instance = *(_Instance **)(DAT_800d0fe0 + 4);
          local_30.vx = sVar8;
          local_30.vy = sVar7;
          local_30.vz = sVar6;
          while (instance != (_Instance *)0x0)
          {
            if (((*(int *)(iVar5 + 0x8c) == 0) && (instance->tface != (_TFace *)0x0)) &&
                ((instance->currentStreamUnitID == streamUnit->StreamUnitID &&
                  (instance->bspTree == iVar9))))
            {
              (instance->position).x = (instance->position).x + sVar8;
              (instance->position).z = (instance->position).z + sVar6;
              (instance->position).y = (instance->position).y + sVar7;
              COLLIDE_UpdateAllTransforms(instance, &local_30);
            }
            instance = instance->next;
          }
        }
      }
      iVar9 = iVar9 + 1;
      iVar11 = iVar11 + 0x24;
    } while (iVar9 < p_Var10->numBSPTrees);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_Process(struct Event *eventInstance /*$s2*/, long startIndex /*$a1*/)
// line 703, offset 0x800610c0
/* begin block 1 */
// Start line: 704
// Start offset: 0x800610C0
// Variables:
// 		long i; // $s1
/* end block 1 */
// End offset: 0x80061208
// End Line: 793

/* begin block 2 */
// Start line: 1646
/* end block 2 */
// End Line: 1647

void EVENT_Process(Event *eventInstance, long startIndex)

{
  long lVar1;
  ScriptPCode **ppSVar2;
  ScriptPCode *actionScript;
  int iVar3;

  iVar3 = startIndex << 2;
  currentEventInstance._0_4_ = eventInstance;
  if (startIndex < (int)(uint)eventInstance->numActions)
  {
    do
    {
      EventCurrentEventIndex = startIndex + 1;
      if (EventCurrentEventIndex == (uint)eventInstance->numActions)
      {
        EventCurrentEventIndex = -1;
      }
      if (*(int *)(iVar3 + (int)eventInstance->conditionalList) == 0)
      {
      LAB_800611a8:
        if ((*(ushort *)(*(int *)(iVar3 + (int)eventInstance->actionList) + 2) & 2) == 0)
        {
          actionScript = *(ScriptPCode **)(iVar3 + (int)eventInstance->actionList);
          EventAbortLine = 0;
          EVENT_DoAction(eventInstance, actionScript, actionScript->data);
        }
      }
      else
      {
        EventAbortLine = 0;
        CurrentEventLine = 0;
        lVar1 = EVENT_IsConditionTrue(eventInstance,
                                      *(ScriptPCode **)(iVar3 + (int)eventInstance->conditionalList));
        if (lVar1 != 0)
        {
          if (*(int *)(iVar3 + (int)eventInstance->actionList) == 0)
          {
            ppSVar2 = eventInstance->actionList + startIndex;
            do
            {
              ppSVar2 = ppSVar2 + 1;
              if ((int)(uint)eventInstance->numActions <= startIndex)
                goto LAB_800611f4;
              iVar3 = iVar3 + 4;
              startIndex = startIndex + 1;
            } while (*ppSVar2 == (ScriptPCode *)0x0);
          }
          if (startIndex < (int)(uint)eventInstance->numActions)
            goto LAB_800611a8;
        }
      }
    LAB_800611f4:
      startIndex = startIndex + 1;
      iVar3 = iVar3 + 4;
    } while (startIndex < (int)(uint)eventInstance->numActions);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_ProcessPuppetShow(struct Event *eventInstance /*$s1*/, long startIndex /*$a1*/)
// line 795, offset 0x80061220
/* begin block 1 */
// Start line: 796
// Start offset: 0x80061220
// Variables:
// 		long i; // $s0
// 		long conditionIsStatisfied; // $s3
/* end block 1 */
// End offset: 0x800613DC
// End Line: 859

/* begin block 2 */
// Start line: 1888
/* end block 2 */
// End Line: 1889

void EVENT_ProcessPuppetShow(Event *eventInstance, long startIndex)

{
  bool bVar1;
  long lVar2;
  ScriptPCode **ppSVar3;
  ScriptPCode *actionScript;
  char cVar4;

  cVar4 = (char)startIndex;
  EventJustRecievedTimer = 0;
  bVar1 = true;
  if ((eventInstance->actionList[startIndex]->conditionBits & 2) != 0)
  {
    EventJustRecievedTimer = 0;
    currentEventInstance._0_4_ = eventInstance;
    return;
  }
  EventCurrentEventIndex = startIndex + 1;
  if (EventCurrentEventIndex == (uint)eventInstance->numActions)
  {
    EventCurrentEventIndex = -1;
  }
  currentEventInstance._0_4_ = eventInstance;
  if (eventInstance->conditionalList[startIndex] == (ScriptPCode *)0x0)
  {
    if ((eventInstance->actionList[startIndex]->conditionBits & 2) != 0)
      goto LAB_80061390;
    actionScript = eventInstance->actionList[startIndex];
  }
  else
  {
    EventAbortLine = 0;
    CurrentEventLine = 0;
    lVar2 = EVENT_IsConditionTrue(eventInstance, eventInstance->conditionalList[startIndex]);
    if (lVar2 == 0)
    {
      bVar1 = false;
      goto LAB_80061390;
    }
    ppSVar3 = eventInstance->actionList + startIndex;
    if (*ppSVar3 == (ScriptPCode *)0x0)
    {
      do
      {
        cVar4 = (char)startIndex;
        ppSVar3 = ppSVar3 + 1;
        if ((int)(uint)eventInstance->numActions <= startIndex)
          goto LAB_80061390;
        startIndex = startIndex + 1;
      } while (*ppSVar3 == (ScriptPCode *)0x0);
    }
    cVar4 = (char)startIndex;
    if ((int)(uint)eventInstance->numActions <= startIndex)
      goto LAB_80061390;
    actionScript = eventInstance->actionList[startIndex];
  }
  EventAbortLine = 0;
  EVENT_DoAction(eventInstance, actionScript, actionScript->data);
LAB_80061390:
  if ((((EventAbortLine == 0) || (EventJustRecievedTimer == 1)) && (bVar1)) &&
      (eventInstance->processingPuppetShow = cVar4 + '\x02',
       (uint)eventInstance->numActions + 1 <= (uint)eventInstance->processingPuppetShow))
  {
    eventInstance->processingPuppetShow = '\0';
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_ProcessEvents(struct EventPointers *eventPointers /*$s2*/, struct Level *level /*$a1*/)
// line 861, offset 0x800613f8
/* begin block 1 */
// Start line: 862
// Start offset: 0x800613F8
// Variables:
// 		long i; // $s0
/* end block 1 */
// End offset: 0x800614A4
// End Line: 892

/* begin block 2 */
// Start line: 2031
/* end block 2 */
// End Line: 2032

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void EVENT_ProcessEvents(EventPointers *eventPointers, Level *level)

{
  Event *eventInstance;
  int iVar1;
  EventPointers *pEVar2;

  iVar1 = 0;
  pEVar2 = eventPointers;
  _CurrentPuzzleLevel = level;
  if (0 < eventPointers->numPuzzles)
  {
    do
    {
      eventInstance = (Event *)pEVar2->eventInstances[0];
      if (eventInstance->eventNumber < 0)
      {
        if (eventInstance->processingPuppetShow != 0)
        {
          EVENT_ProcessPuppetShow(eventInstance, (uint)eventInstance->processingPuppetShow - 1);
        }
      }
      else
      {
        EVENT_Process(eventInstance, 0);
      }
      iVar1 = iVar1 + 1;
      pEVar2 = (EventPointers *)pEVar2->eventInstances;
    } while (iVar1 < eventPointers->numPuzzles);
  }
  if ((int)fontTracker.font_buffer[39].y != -1)
  {
    CINE_PlayIngame((int)fontTracker.font_buffer[39].y);
    /* WARNING: Read-only address (ram,0x800d2a70) is written */
    fontTracker.font_buffer[39].y = -1;
    /* WARNING: Read-only address (ram,0x800d2a6c) is written */
    fontTracker.font_buffer[38]._4_2_ = 1;
  }
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_DoAction(struct Event *eventInstance /*$s4*/, struct ScriptPCode *actionScript /*$s1*/, short *scriptData /*$s0*/)
// line 894, offset 0x800614bc
/* begin block 1 */
// Start line: 895
// Start offset: 0x800614BC
// Variables:
// 		long retValue; // $s3
// 		long operateOnStack; // stack offset -32
// 		struct _PCodeStack stack; // stack offset -1192

/* begin block 1.1 */
// Start line: 911
// Start offset: 0x80061550
// Variables:
// 		struct EventTimer *timer; // $a1
/* end block 1.1 */
// End offset: 0x800615A0
// End Line: 931
/* end block 1 */
// End offset: 0x80061610
// End Line: 944

/* begin block 2 */
// Start line: 2110
/* end block 2 */
// End Line: 2111

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long EVENT_DoAction(Event *eventInstance, ScriptPCode *actionScript, short *scriptData)

{
  long lVar1;
  short *psVar2;
  uint uVar3;
  Level *codeStream;
  uint *puVar4;
  int iVar5;
  _PCodeStack *stack;
  long *operateOnStack;
  long lVar6;
  _PCodeStack local_4a8;
  int local_20[2];

  local_4a8.topOfStack = 0;
  EventJustRecievedTimer = 0;
  lVar6 = 1;
  currentEventInstance._4_4_ = actionScript;
  EventAbortedPosition._0_4_ = scriptData;
  if ((((actionScript->conditionBits & 1) == 0) && (lVar6 = 1, scriptData != (short *)0x0)) &&
      (lVar6 = 1, EventAbortLine == 0))
  {
    lVar6 = 1;
    do
    {
      stack = &local_4a8;
      operateOnStack = local_20;
      codeStream = (Level *)EVENT_ParseOpcode(stack, scriptData, operateOnStack);
      if (((EventAbortLine != 0) &&
           (puVar4 = (uint *)(int)EventJustRecievedTimer, puVar4 == (uint *)0x0)) &&
          (EVENT_UpdateResetSignalArrayAndWaterMovement((Level *)stack, (Level *)scriptData, (long)operateOnStack),
           psVar2 = EventAbortedPosition._0_4_, lVar1 = EventCurrentEventIndex, puVar4 != (uint *)0x0))
      {
        lVar6 = 0;
        *(Event **)(puVar4 + 1) = eventInstance;
        *(ScriptPCode **)(puVar4 + 2) = actionScript;
        *puVar4 = *puVar4 & 1;
        *(short **)(puVar4 + 3) = psVar2;
        uVar3 = _CurrentPuzzleLevel;
        actionScript->conditionBits = actionScript->conditionBits | 1;
        puVar4[4] = uVar3;
        puVar4[5] = lVar1;
      }
      if (((local_20[0] != 0) && (EventAbortLine == 0)) &&
          (iVar5 = local_4a8.topOfStack + -1, 0 < local_4a8.topOfStack))
      {
        local_4a8.topOfStack = iVar5;
        EVENT_ExecuteActionCommand(local_4a8.stack + iVar5, (StackType *)0x0, &local_4a8, (short *)codeStream);
      }
    } while ((codeStream != (Level *)0x0) && (scriptData = (short *)codeStream, EventAbortLine == 0));
  }
  return lVar6;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_IsConditionTrue(struct Event *eventInstance /*$a0*/, struct ScriptPCode *conditionScript /*$a1*/)
// line 948, offset 0x80061634
/* begin block 1 */
// Start line: 949
// Start offset: 0x80061634
// Variables:
// 		long retValue; // $s0
// 		long error; // stack offset -28
// 		long operateOnStack; // stack offset -32
// 		short flags; // stack offset -24
// 		struct _PCodeStack stack; // stack offset -1192
// 		short *scriptData; // $s1
/* end block 1 */
// End offset: 0x8006170C
// End Line: 1004

/* begin block 2 */
// Start line: 2236
/* end block 2 */
// End Line: 2237

long EVENT_IsConditionTrue(Event *eventInstance, ScriptPCode *conditionScript)

{
  int iVar1;
  long lVar2;
  short *codeStream;
  _PCodeStack local_4a8;
  int local_20;
  int local_1c;
  short asStack24[4];

  local_4a8.topOfStack = 0;
  codeStream = conditionScript->data;
  currentEventInstance._4_4_ = 0;
  lVar2 = 0;
  while (true)
  {
    do
    {
      do
      {
        if ((codeStream == (short *)0x0) || (EventAbortLine != 0))
          goto LAB_800616f8;
        codeStream = EVENT_ParseOpcode(&local_4a8, codeStream, &local_20);
      } while ((local_20 == 0) || (EventAbortLine != 0));
      CurrentEventLine = CurrentEventLine + 1;
      iVar1 = local_4a8.topOfStack + -1;
    } while (local_4a8.topOfStack < 1);
    local_4a8.topOfStack = iVar1;
    lVar2 = EVENT_GetScalerValueFromOperand(local_4a8.stack + iVar1, &local_1c, asStack24);
    if (local_1c != 0)
      break;
    if (lVar2 == 0)
    {
    LAB_800616f8:
      if (EventAbortLine == 1)
      {
        lVar2 = 0;
      }
      return lVar2;
    }
  }
  lVar2 = 0;
  goto LAB_800616f8;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_WriteEventObject(struct StackType *stackEntry /*$s0*/, long areaID /*$s1*/, struct Event *event /*$a2*/, long number /*$s2*/)
// line 1007, offset 0x80061724
/* begin block 1 */
// Start line: 1008
// Start offset: 0x80061724
// Variables:
// 		long retValue; // $a0

/* begin block 1.1 */
// Start line: 1023
// Start offset: 0x80061760
// Variables:
// 		struct SavedBasic *savedEvent; // $v1
/* end block 1.1 */
// End offset: 0x800617B8
// End Line: 1047
/* end block 1 */
// End offset: 0x800617B8
// End Line: 1050

/* begin block 2 */
// Start line: 2375
/* end block 2 */
// End Line: 2376

long EVENT_WriteEventObject(StackType *stackEntry, long areaID, Event *event, long number)

{
  SavedBasic *pSVar1;
  long lVar2;

  lVar2 = 0;
  if (event == (Event *)0x0)
  {
    pSVar1 = SAVE_GetSavedEvent(areaID, number);
    if (pSVar1 == (SavedBasic *)0x0)
    {
      stackEntry->id = 0x15;
      pSVar1 = EVENT_CreateSaveEvent(areaID, number);
      *(SavedBasic **)stackEntry->data = pSVar1;
    }
    else
    {
      stackEntry->id = 0x15;
      *(SavedBasic **)stackEntry->data = pSVar1;
    }
    lVar2 = 1;
    *(long *)(stackEntry->data + 8) = areaID;
    *(long *)(stackEntry->data + 0xc) = number;
  }
  else
  {
    stackEntry->id = 0x10;
    *(Event **)stackEntry->data = event;
  }
  *(undefined4 *)(stackEntry->data + 4) = 0xffffffff;
  return lVar2;
}

// decompiled code
// original method signature:
// struct _MultiSignal * /*$ra*/ EVENT_ResolveObjectSignal(struct _StreamUnit *stream /*$a0*/, long signalNumber /*$a1*/)
// line 1053, offset 0x800617d4
/* begin block 1 */
// Start line: 1054
// Start offset: 0x800617D4
// Variables:
// 		struct _MultiSignal *retValue; // $a2
// 		struct Level *level; // $a0
/* end block 1 */
// End offset: 0x8006185C
// End Line: 1109

/* begin block 2 */
// Start line: 2476
/* end block 2 */
// End Line: 2477

_MultiSignal *EVENT_ResolveObjectSignal(_StreamUnit *stream, long signalNumber)

{
  Level *level;
  _MultiSignal *p_Var1;

  level = stream->level;
  p_Var1 = (_MultiSignal *)0x0;
  if (signalNumber < 0)
  {
    switch (signalNumber)
    {
    case -5:
      p_Var1 = level->startUnitMainSignal;
      break;
    case -4:
      p_Var1 = level->startUnitLoadedSignal;
      break;
    case -3:
      p_Var1 = level->materialSignal;
      break;
    case -2:
      p_Var1 = level->spectralSignal;
      break;
    case -1:
      p_Var1 = level->startSignal;
    }
  }
  else
  {
    p_Var1 = SIGNAL_FindSignal(level, signalNumber);
  }
  return p_Var1;
}

// decompiled code
// original method signature:
// struct Intro * /*$ra*/ EVENT_ResolveObjectIntro(struct EventInstanceObject *instanceObject /*$v0*/)
// line 1112, offset 0x8006186c
/* begin block 1 */
// Start line: 1113
// Start offset: 0x8006186C
/* end block 1 */
// End offset: 0x8006186C
// End Line: 1113

/* begin block 2 */
// Start line: 2595
/* end block 2 */
// End Line: 2596

Intro *EVENT_ResolveObjectIntro(EventInstanceObject *instanceObject)

{
  Intro *pIVar1;

  pIVar1 = INSTANCE_FindIntro(instanceObject->unitID, instanceObject->introUniqueID);
  return pIVar1;
}

// decompiled code
// original method signature:
// struct _SFXMkr * /*$ra*/ EVENT_ResolveSFXMarker(struct _StreamUnit *stream /*$a0*/, struct EventInstanceObject *instanceObject /*$a1*/)
// line 1123, offset 0x80061898
/* begin block 1 */
// Start line: 1125
// Start offset: 0x80061898
// Variables:
// 		int i; // $a0
// 		struct Level *level; // $t0
// 		struct _SFXMkr *result; // $a2
/* end block 1 */
// End offset: 0x800618F0
// End Line: 1143

/* begin block 2 */
// Start line: 2617
/* end block 2 */
// End Line: 2618

/* begin block 3 */
// Start line: 2618
/* end block 3 */
// End Line: 2619

/* begin block 4 */
// Start line: 2622
/* end block 4 */
// End Line: 2623

_SFXMkr *EVENT_ResolveSFXMarker(_StreamUnit *stream, EventInstanceObject *instanceObject)

{
  int iVar1;
  _SFXMkr *p_Var2;
  int iVar3;

  iVar1 = stream->level->NumberOfSFXMarkers;
  if ((iVar1 != 0) && (iVar3 = 0, 0 < iVar1))
  {
    p_Var2 = stream->level->SFXMarkerList;
    do
    {
      iVar3 = iVar3 + 1;
      if (instanceObject->introUniqueID == p_Var2->uniqueID)
      {
        return p_Var2;
      }
      p_Var2 = p_Var2 + 1;
    } while (iVar3 < iVar1);
  }
  return (_SFXMkr *)0x0;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_AddGameObjectToStack(struct _PCodeStack *stack /*$a0*/)
// line 1146, offset 0x800618f8
/* begin block 1 */
// Start line: 1148
// Start offset: 0x800618F8

/* begin block 1.1 */
// Start line: 1150
// Start offset: 0x8006190C
// Variables:
// 		struct StackType *stackEntry; // $v0
/* end block 1.1 */
// End offset: 0x8006193C
// End Line: 1154
/* end block 1 */
// End offset: 0x8006193C
// End Line: 1160

/* begin block 2 */
// Start line: 2673
/* end block 2 */
// End Line: 2674

/* begin block 3 */
// Start line: 2674
/* end block 3 */
// End Line: 2675

void EVENT_AddGameObjectToStack(_PCodeStack *stack)

{
  int iVar1;

  iVar1 = stack->topOfStack;
  if (iVar1 < 0x20)
  {
    stack->stack[iVar1].id = 3;
    *(undefined4 *)stack->stack[iVar1].data = 0xffffffff;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_AddPlayerObjectToStack(struct _PCodeStack *stack /*$a1*/)
// line 1162, offset 0x80061944
/* begin block 1 */
// Start line: 1163
// Start offset: 0x80061944

/* begin block 1.1 */
// Start line: 1166
// Start offset: 0x8006195C
// Variables:
// 		struct StackType *stackEntry; // $v0
/* end block 1.1 */
// End offset: 0x80061994
// End Line: 1171
/* end block 1 */
// End offset: 0x80061994
// End Line: 1177

/* begin block 2 */
// Start line: 2705
/* end block 2 */
// End Line: 2706

void EVENT_AddPlayerObjectToStack(_PCodeStack *stack)

{
  undefined4 uVar1;
  StackType *pSVar2;

  if (stack->topOfStack < 0x20)
  {
    pSVar2 = stack->stack + stack->topOfStack;
    pSVar2->id = 2;
    uVar1 = DAT_800d0fd8;
    *(undefined4 *)(pSVar2->data + 4) = 0xffffffff;
    *(undefined4 *)pSVar2->data = uVar1;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_AddObjectToStack(struct _PCodeStack *stack /*$s2*/, long item /*$a1*/)
// line 1179, offset 0x8006199c
/* begin block 1 */
// Start line: 1180
// Start offset: 0x8006199C
// Variables:
// 		struct EventBasicObject *basicObject; // $a0
// 		int topOfStack; // $s1

/* begin block 1.1 */
// Start line: 1192
// Start offset: 0x800619C8
// Variables:
// 		struct StackType *stackEntry; // $s0

/* begin block 1.1.1 */
// Start line: 1198
// Start offset: 0x80061A24
/* end block 1.1.1 */
// End offset: 0x80061A44
// End Line: 1214

/* begin block 1.1.2 */
// Start line: 1222
// Start offset: 0x80061A44
/* end block 1.1.2 */
// End offset: 0x80061A78
// End Line: 1239

/* begin block 1.1.3 */
// Start line: 1254
// Start offset: 0x80061A94
/* end block 1.1.3 */
// End offset: 0x80061A94
// End Line: 1256

/* begin block 1.1.4 */
// Start line: 1264
// Start offset: 0x80061AB0
/* end block 1.1.4 */
// End offset: 0x80061AB0
// End Line: 1266

/* begin block 1.1.5 */
// Start line: 1274
// Start offset: 0x80061AD4
/* end block 1.1.5 */
// End offset: 0x80061B60
// End Line: 1324

/* begin block 1.1.6 */
// Start line: 1336
// Start offset: 0x80061B60
/* end block 1.1.6 */
// End offset: 0x80061BB0
// End Line: 1358
/* end block 1.1 */
// End offset: 0x80061BB4
// End Line: 1366
/* end block 1 */
// End offset: 0x80061BB4
// End Line: 1372

/* begin block 2 */
// Start line: 2740
/* end block 2 */
// End Line: 2741

void EVENT_ProcessEvents(EventPointers *eventPointers, Level *level)

{
  undefined4 uVar1;
  ushort *puVar2;
  StackType *stackEntry;
  long lVar3;

  uVar1 = DAT_800d1020;
  lVar3 = eventPointers->numPuzzles;
  if (0x1f < lVar3)
    goto LAB_80061bb4;
  puVar2 = *(ushort **)((int)level * 4 + *(int *)(EventTimer_800d4214.time + 0x10));
  stackEntry = (StackType *)((int)eventPointers + lVar3 * 0x24 + 4);
  switch ((int)(((uint)*puVar2 - 1) * 0x10000) >> 0x10)
  {
  case 0:
    if ((puVar2[1] & 1) == 0)
    {
      if (*(int *)(puVar2 + 6) == 0)
      {
        if (*(int *)(puVar2 + 8) == 0)
          goto LAB_80061b9c;
        stackEntry->id = 4;
        uVar1 = *(undefined4 *)(puVar2 + 8);
      }
      else
      {
        stackEntry->id = 2;
        uVar1 = *(undefined4 *)(puVar2 + 6);
      }
    LAB_80061b54:
      *(undefined4 *)(stackEntry->data + 4) = 0xffffffff;
      *(undefined4 *)stackEntry->data = uVar1;
    }
    else
    {
      stackEntry->id = 0x1b;
      *(undefined2 *)stackEntry->data = 1;
      uVar1 = *(undefined4 *)(puVar2 + 8);
      *(undefined2 *)(stackEntry->data + 2) = 0xffff;
      *(undefined4 *)(stackEntry->data + 4) = 0xffffffff;
      *(undefined4 *)(stackEntry->data + 8) = 0xffffffff;
      *(undefined4 *)(stackEntry->data + 0xc) = 0xffffffff;
      *(undefined4 *)(stackEntry->data + 0x10) = uVar1;
    }
    break;
  case 1:
    stackEntry->id = 0x12;
    *(ushort **)stackEntry->data = puVar2;
    *(undefined4 *)(stackEntry->data + 0x18) = 0;
    *(undefined4 *)(stackEntry->data + 0x1c) = uVar1;
    break;
  case 2:
    EVENT_WriteEventObject(stackEntry, *(long *)(puVar2 + 2), *(Event **)(puVar2 + 4), (int)(short)puVar2[1]);
    lVar3 = lVar3 + 1;
    goto LAB_80061bb4;
  case 3:
    if (*(int *)(puVar2 + 4) == 0)
      goto LAB_80061b9c;
    stackEntry->id = 0x17;
    *(undefined4 *)stackEntry->data = *(undefined4 *)(puVar2 + 4);
    uVar1 = *(undefined4 *)(puVar2 + 6);
    *(undefined4 *)(stackEntry->data + 8) = 0xffffffff;
    *(undefined4 *)(stackEntry->data + 4) = uVar1;
    break;
  case 4:
    stackEntry->id = 1;
    uVar1 = *(undefined4 *)(puVar2 + 4);
    *(undefined4 *)(stackEntry->data + 4) = 0xffffffff;
    *(undefined4 *)stackEntry->data = uVar1;
    *(undefined4 *)(stackEntry->data + 8) = *(undefined4 *)(puVar2 + 2);
    break;
  case 5:
    if (*(int *)(puVar2 + 4) != 0)
    {
      stackEntry->id = 0x11;
      uVar1 = *(undefined4 *)(puVar2 + 4);
      goto LAB_80061b54;
    }
    goto LAB_80061b9c;
  case 6:
    if (*(int *)(puVar2 + 10) != 0)
    {
      stackEntry->id = 0x1a;
      *(undefined4 *)stackEntry->data = *(undefined4 *)(puVar2 + 10);
      /* WARNING: Subroutine does not return */
      STREAM_GetLevelWithID(*(long *)(puVar2 + 2));
    }
  LAB_80061b9c:
    stackEntry->id = 6;
    *(Level **)stackEntry->data = level;
    *(undefined4 *)(stackEntry->data + 4) = 0xffffffff;
  }
  lVar3 = lVar3 + 1;
LAB_80061bb4:
  eventPointers->numPuzzles = lVar3;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_AddCharPointerToStack(struct _PCodeStack *stack /*$a0*/, char *pointer /*$a1*/)
// line 1379, offset 0x80061bd0
/* begin block 1 */
// Start line: 1381
// Start offset: 0x80061BD0

/* begin block 1.1 */
// Start line: 1383
// Start offset: 0x80061BE4
// Variables:
// 		struct StackType *stackEntry; // $v0
/* end block 1.1 */
// End offset: 0x80061C10
// End Line: 1387
/* end block 1 */
// End offset: 0x80061C10
// End Line: 1393

/* begin block 2 */
// Start line: 3155
/* end block 2 */
// End Line: 3156

/* begin block 3 */
// Start line: 3156
/* end block 3 */
// End Line: 3157

void EVENT_AddCharPointerToStack(_PCodeStack *stack, char *pointer)

{
  int iVar1;

  iVar1 = stack->topOfStack;
  if (iVar1 < 0x20)
  {
    stack->stack[iVar1].id = 0x1c;
    *(char **)stack->stack[iVar1].data = pointer;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_AddShortPointerToStack(struct _PCodeStack *stack /*$a0*/, short *pointer /*$a1*/)
// line 1395, offset 0x80061c18
/* begin block 1 */
// Start line: 1397
// Start offset: 0x80061C18

/* begin block 1.1 */
// Start line: 1399
// Start offset: 0x80061C2C
// Variables:
// 		struct StackType *stackEntry; // $v0
/* end block 1.1 */
// End offset: 0x80061C58
// End Line: 1403
/* end block 1 */
// End offset: 0x80061C58
// End Line: 1409

/* begin block 2 */
// Start line: 3187
/* end block 2 */
// End Line: 3188

/* begin block 3 */
// Start line: 3188
/* end block 3 */
// End Line: 3189

void EVENT_AddShortPointerToStack(_PCodeStack *stack, short *pointer)

{
  int iVar1;

  iVar1 = stack->topOfStack;
  if (iVar1 < 0x20)
  {
    stack->stack[iVar1].id = 10;
    *(short **)stack->stack[iVar1].data = pointer;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_AddNumberToStack(struct _PCodeStack *stack /*$a0*/, long item /*$a1*/, long flags /*$a2*/)
// line 1411, offset 0x80061c60
/* begin block 1 */
// Start line: 1413
// Start offset: 0x80061C60

/* begin block 1.1 */
// Start line: 1415
// Start offset: 0x80061C74
// Variables:
// 		struct StackType *stackEntry; // $v0
/* end block 1.1 */
// End offset: 0x80061CA8
// End Line: 1421
/* end block 1 */
// End offset: 0x80061CA8
// End Line: 1427

/* begin block 2 */
// Start line: 3219
/* end block 2 */
// End Line: 3220

/* begin block 3 */
// Start line: 3220
/* end block 3 */
// End Line: 3221

void EVENT_AddNumberToStack(_PCodeStack *stack, long item, long flags)

{
  StackType *pSVar1;

  if (stack->topOfStack < 0x20)
  {
    pSVar1 = stack->stack + stack->topOfStack;
    pSVar1->id = 7;
    *(long *)pSVar1->data = item;
    *(undefined4 *)(pSVar1->data + 4) = 0;
    *(short *)(pSVar1->data + 8) = (short)flags;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_ChangeOperandToNumber(struct StackType *operand /*$a0*/, long item /*$a1*/, long flags /*$a2*/)
// line 1429, offset 0x80061cb0
/* begin block 1 */
// Start line: 3255
/* end block 1 */
// End Line: 3256

/* begin block 2 */
// Start line: 3256
/* end block 2 */
// End Line: 3257

void EVENT_ChangeOperandToNumber(StackType *operand, long item, long flags)

{
  operand->id = 7;
  *(long *)operand->data = item;
  *(undefined4 *)(operand->data + 4) = 0;
  *(short *)(operand->data + 8) = (short)flags;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_ChangeOperandVector3d(struct StackType *operand /*$a0*/, short x /*$a1*/, short y /*$a2*/, short z /*$a3*/, long streamUnitID /*stack 16*/)
// line 1437, offset 0x80061cc8
/* begin block 1 */
// Start line: 3271
/* end block 1 */
// End Line: 3272

/* begin block 2 */
// Start line: 3272
/* end block 2 */
// End Line: 3273

long EVENT_WriteEventObject(StackType *stackEntry, long areaID, Event *event, long number)

{
  undefined4 in_stack_00000010;

  stackEntry->id = 9;
  *(short *)stackEntry->data = (short)areaID;
  *(short *)(stackEntry->data + 2) = (short)event;
  *(short *)(stackEntry->data + 4) = (short)number;
  *(undefined2 *)(stackEntry->data + 8) = 0xa0;
  *(undefined2 *)(stackEntry->data + 10) = 0xa0;
  *(undefined2 *)(stackEntry->data + 0xc) = 0xa0;
  *(undefined4 *)(stackEntry->data + 0x10) = in_stack_00000010;
  return 0xa0;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_Addvector3dToStack(struct _PCodeStack *stack /*$s0*/, short x /*$a1*/, short y /*$a2*/, short z /*$a3*/, long streamUnitID /*stack 16*/)
// line 1449, offset 0x80061cf8
/* begin block 1 */
// Start line: 3299
/* end block 1 */
// End Line: 3300

void EVENT_Addvector3dToStack(_PCodeStack *stack, short x, short y, short z, long streamUnitID)

{
  if (stack->topOfStack < 0x20)
  {
    EVENT_WriteEventObject(stack->stack + stack->topOfStack, (int)x, (Event *)(int)y, (int)z);
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_ChangeOperandRotation3d(struct StackType *operand /*$a0*/, struct Rotation3d *rotation /*$a1*/)
// line 1464, offset 0x80061d70
/* begin block 1 */
// Start line: 3329
/* end block 1 */
// End Line: 3330

/* begin block 2 */
// Start line: 3330
/* end block 2 */
// End Line: 3331

void EVENT_ChangeOperandRotation3d(StackType *operand, Rotation3d *rotation)

{
  short sVar1;

  operand->id = 0xe;
  *(short *)operand->data = rotation->vx;
  *(short *)(operand->data + 2) = rotation->vy;
  *(short *)(operand->data + 4) = rotation->vz;
  *(short *)(operand->data + 8) = rotation->errorx;
  *(short *)(operand->data + 10) = rotation->errory;
  sVar1 = rotation->errorz;
  *(undefined4 *)(operand->data + 0x10) = 0xffffffff;
  *(short *)(operand->data + 0xc) = sVar1;
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_AddSubListObjectToStack(struct _PCodeStack *stack /*$a0*/, long listNumber /*$a1*/)
// line 1490, offset 0x80061dc8
/* begin block 1 */
// Start line: 1492
// Start offset: 0x80061DC8

/* begin block 1.1 */
// Start line: 1499
// Start offset: 0x80061DDC
// Variables:
// 		struct StackType *stackEntry; // $a3
/* end block 1.1 */
// End offset: 0x80061E4C
// End Line: 1513
/* end block 1 */
// End offset: 0x80061E4C
// End Line: 1519

/* begin block 2 */
// Start line: 2980
/* end block 2 */
// End Line: 2981

/* begin block 3 */
// Start line: 3364
/* end block 3 */
// End Line: 3365

/* begin block 4 */
// Start line: 3369
/* end block 4 */
// End Line: 3370

long EVENT_AddSubListObjectToStack(_PCodeStack *stack, long listNumber)

{
  int *piVar1;
  StackType *pSVar2;

  if (stack->topOfStack < 0x20)
  {
    pSVar2 = stack->stack + stack->topOfStack;
    pSVar2->id = 0x16;
    piVar1 = (int *)(&fontTracker.font_buffer[0x19].y + listNumber * 2);
    if (*piVar1 < 1)
    {
      *(undefined4 *)pSVar2->data = 0;
    }
    else
    {
      *(long *)pSVar2->data = listNumber * 0x28 + -0x7ff2d4f4;
    }
    *(int *)(pSVar2->data + 4) = *piVar1;
    *(undefined4 *)(pSVar2->data + 8) = 0;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return 0;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_StackDuplicate(struct _PCodeStack *stack /*$a0*/)
// line 1569, offset 0x80061e54
/* begin block 1 */
// Start line: 3138
/* end block 1 */
// End Line: 3139

/* begin block 2 */
// Start line: 3473
/* end block 2 */
// End Line: 3474

void EVENT_StackDuplicate(_PCodeStack *stack)

{
  int iVar1;
  long *plVar2;
  StackType *pSVar3;
  long lVar4;
  long lVar5;
  long lVar6;

  iVar1 = stack->topOfStack;
  if ((iVar1 < 0x20) && (iVar1 != 0))
  {
    pSVar3 = stack->stack + iVar1;
    plVar2 = &stack->topOfStack + (iVar1 + -1) * 9 + 1;
    do
    {
      lVar4 = plVar2[1];
      lVar5 = plVar2[2];
      lVar6 = plVar2[3];
      pSVar3->id = *plVar2;
      *(long *)pSVar3->data = lVar4;
      *(long *)(pSVar3->data + 4) = lVar5;
      *(long *)(pSVar3->data + 8) = lVar6;
      plVar2 = plVar2 + 4;
      pSVar3 = (StackType *)(pSVar3->data + 0xc);
    } while (plVar2 != &stack->topOfStack + (iVar1 + -1) * 9 + 9);
    pSVar3->id = *plVar2;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_TransformTGroupAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a1*/, long item /*$a2*/, short *codeStream /*$a3*/)
// line 1591, offset 0x80061eec
/* begin block 1 */
// Start line: 1593
// Start offset: 0x80061EEC
// Variables:
// 		long retValue; // $a0
/* end block 1 */
// End offset: 0x80061F74
// End Line: 1638

/* begin block 2 */
// Start line: 3516
/* end block 2 */
// End Line: 3517

/* begin block 3 */
// Start line: 3517
/* end block 3 */
// End Line: 3518

/* begin block 4 */
// Start line: 3518
/* end block 4 */
// End Line: 3519

long EVENT_TransformTGroupAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  long lVar1;

  lVar1 = 0;
  if (*(int *)(stackObject->data + 8) == -1)
  {
    *(long *)(stackObject->data + 8) = item;
    lVar1 = 1;
    switch (item)
    {
    default:
      goto switchD_80061f28_caseD_5;
    case 0x2c:
    case 0x2e:
      if (codeStream != (short *)0x0)
      {
        MoveCodeStreamExtra = 2;
        *(short *)(stackObject->data + 0xc) = codeStream[1];
        *(short *)(stackObject->data + 0xe) = codeStream[2];
      }
      break;
    case 0x2d:
    case 0x2f:
      if (codeStream != (short *)0x0)
      {
        MoveCodeStreamExtra = 1;
        *(short *)(stackObject->data + 0xc) = codeStream[1];
      }
    }
    lVar1 = 1;
  }
switchD_80061f28_caseD_5:
  return lVar1;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_TransformConstrictAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a0*/, long item /*$a2*/)
// line 1641, offset 0x80061f7c
/* begin block 1 */
// Start line: 1642
// Start offset: 0x80061F7C
// Variables:
// 		long retValue; // $v1
// 		struct _Instance *instance; // $a1

/* begin block 1.1 */
// Start line: 1652
// Start offset: 0x80061FAC
/* end block 1.1 */
// End offset: 0x80061FAC
// End Line: 1655

/* begin block 1.2 */
// Start line: 1666
// Start offset: 0x80061FBC
/* end block 1.2 */
// End offset: 0x80061FD8
// End Line: 1675
/* end block 1 */
// End offset: 0x80061FD8
// End Line: 1687

/* begin block 2 */
// Start line: 3616
/* end block 2 */
// End Line: 3617

long EVENT_TransformConstrictAttribute(_PCodeStack *stack, StackType *stackObject, long item)

{
  uint item_00;

  if (item == 0x3a)
  {
    item_00 = (uint)(*(short *)(*(int *)stackObject->data + 0x150) < -1);
  }
  else
  {
    if (item != 0x3b)
    {
      return 0;
    }
    item_00 = (uint)(*(short *)(*(int *)stackObject->data + 0x150) < 2) ^ 1;
  }
  /* WARNING: Subroutine does not return */
  EVENT_ChangeOperandToNumber(stackObject, item_00, 0);
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_TransformInstanceAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$s1*/, long item /*$a2*/, short *codeStream /*$a3*/)
// line 1693, offset 0x80061fe8
/* begin block 1 */
// Start line: 1694
// Start offset: 0x80061FE8
// Variables:
// 		long retValue; // $a0
// 		long x; // $a1
// 		long y; // $a2
// 		long z; // $a3
// 		struct _Instance *instance; // $s0

/* begin block 1.1 */
// Start line: 1705
// Start offset: 0x80062034
// Variables:
// 		struct evPositionData *position; // $v0
/* end block 1.1 */
// End offset: 0x80062068
// End Line: 1720

/* begin block 1.2 */
// Start line: 1726
// Start offset: 0x80062080
// Variables:
// 		struct evPositionData *rotation; // $v1
// 		struct Rotation3d vector; // stack offset -40
/* end block 1.2 */
// End offset: 0x800620E0
// End Line: 1745

/* begin block 1.3 */
// Start line: 1773
// Start offset: 0x80062138
// Variables:
// 		int status; // $v1
/* end block 1.3 */
// End offset: 0x800621C0
// End Line: 1810

/* begin block 1.4 */
// Start line: 1832
// Start offset: 0x800621E8
/* end block 1.4 */
// End offset: 0x800621E8
// End Line: 1834

/* begin block 1.5 */
// Start line: 1845
// Start offset: 0x8006220C
/* end block 1.5 */
// End offset: 0x8006220C
// End Line: 1845

/* begin block 1.6 */
// Start line: 1852
// Start offset: 0x80062230
/* end block 1.6 */
// End offset: 0x80062230
// End Line: 1852

/* begin block 1.7 */
// Start line: 1859
// Start offset: 0x80062254
/* end block 1.7 */
// End offset: 0x80062254
// End Line: 1859

/* begin block 1.8 */
// Start line: 1866
// Start offset: 0x80062278
// Variables:
// 		struct _Instance *tmpI; // $s0
// 		long value; // $a1

/* begin block 1.8.1 */
// Start line: 1878
// Start offset: 0x800622AC
/* end block 1.8.1 */
// End offset: 0x800622C8
// End Line: 1887
/* end block 1.8 */
// End offset: 0x800622CC
// End Line: 1893

/* begin block 1.9 */
// Start line: 1902
// Start offset: 0x800622E0
/* end block 1.9 */
// End offset: 0x800622E0
// End Line: 1904

/* begin block 1.10 */
// Start line: 1915
// Start offset: 0x80062308
/* end block 1.10 */
// End offset: 0x80062308
// End Line: 1917

/* begin block 1.11 */
// Start line: 1926
// Start offset: 0x80062330
/* end block 1.11 */
// End offset: 0x80062330
// End Line: 1928

/* begin block 1.12 */
// Start line: 1955
// Start offset: 0x80062358
/* end block 1.12 */
// End offset: 0x80062358
// End Line: 1957

/* begin block 1.13 */
// Start line: 1965
// Start offset: 0x8006237C
/* end block 1.13 */
// End offset: 0x8006237C
// End Line: 1968

/* begin block 1.14 */
// Start line: 1991
// Start offset: 0x800623F4
// Variables:
// 		long value; // $s2

/* begin block 1.14.1 */
// Start line: 1994
// Start offset: 0x80062404
// Variables:
// 		struct _StreamUnit *streamUnit; // $v0
/* end block 1.14.1 */
// End offset: 0x8006243C
// End Line: 2001
/* end block 1.14 */
// End offset: 0x80062468
// End Line: 2011

/* begin block 1.15 */
// Start line: 2035
// Start offset: 0x800624E8
// Variables:
// 		long value; // $a1
/* end block 1.15 */
// End offset: 0x8006250C
// End Line: 2042

/* begin block 1.16 */
// Start line: 2048
// Start offset: 0x80062520
// Variables:
// 		long value; // $a1
/* end block 1.16 */
// End offset: 0x80062544
// End Line: 2055

/* begin block 1.17 */
// Start line: 2061
// Start offset: 0x80062558
// Variables:
// 		long value; // $a1
/* end block 1.17 */
// End offset: 0x8006257C
// End Line: 2069

/* begin block 1.18 */
// Start line: 2075
// Start offset: 0x80062590
// Variables:
// 		long value; // $a1
/* end block 1.18 */
// End offset: 0x800625B4
// End Line: 2083

/* begin block 1.19 */
// Start line: 2089
// Start offset: 0x800625C8
// Variables:
// 		long value; // $a1
/* end block 1.19 */
// End offset: 0x800625F0
// End Line: 2097
/* end block 1 */
// End offset: 0x80062634
// End Line: 2167

/* begin block 2 */
// Start line: 3727
/* end block 2 */
// End Line: 3728

long EVENT_TransformInstanceAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  bool bVar1;
  MultiSpline *pMVar2;
  int item_00;
  _StreamUnit *p_Var3;
  long lVar4;
  AniTex *pAVar5;
  uint uVar6;
  long lVar7;
  _Terrain *p_Var8;
  _Instance *Inst;

  Inst = *(_Instance **)stackObject->data;
  lVar7 = 0;
  switch (item)
  {
  case 4:
  case 10:
  case 0xb:
  case 0x14:
  case 0x15:
  case 0x20:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x3e:
  case 0x40:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x5b:
  case 0x5c:
  case 0x5e:
  case 0x5f:
  case 0x67:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x72:
  case 0x74:
  case 0x7b:
  case 0x7c:
  case 0x8a:
  case 0x8c:
  case 0x8d:
  case 0x8f:
  case 0x90:
  case 0xa3:
  case 0xa4:
  case 0xa5:
    *(long *)(stackObject->data + 4) = item;
    lVar7 = 1;
    break;
  case 5:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, 6);
  case 9:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, 7);
  case 0xc:
    stackObject->id = 0xf;
    *(_Instance **)stackObject->data = Inst;
    pMVar2 = SCRIPT_GetMultiSpline(Inst, (ulong *)(stackObject->data + 0xc), (ulong *)(stackObject->data + 0x10));
    lVar7 = 1;
    *(MultiSpline **)(stackObject->data + 4) = pMVar2;
    *(undefined4 *)(stackObject->data + 0x14) = 0;
    *(undefined4 *)(stackObject->data + 8) = 0xffffffff;
    break;
  case 0x12:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, 9);
  case 0x13:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, 10);
  case 0x1d:
    lVar4 = 0x13;
    if (Inst->object->animList == (_G2AnimKeylist_Type **)0x0)
    {
      return 0;
    }
    goto LAB_800624d4;
  case 0x21:
    stackObject->id = 0x14;
    *(_Instance **)stackObject->data = Inst;
    lVar7 = 1;
    pAVar5 = Inst->object->modelList[Inst->currentModel]->aniTextures;
    *(undefined4 *)(stackObject->data + 8) = 0xffffffff;
    *(AniTex **)(stackObject->data + 4) = pAVar5;
    break;
  case 0x2b:
    item_00 = Inst->attachedID;
    if ((item_00 == 0) &&
        (p_Var3 = STREAM_GetStreamUnitWithID(Inst->currentStreamUnitID), item_00 = 0,
         p_Var3 != (_StreamUnit *)0x0))
    {
      p_Var8 = p_Var3->level->terrain;
      if (Inst->bspTree < p_Var8->numBSPTrees)
      {
        item_00 = -(Inst->currentStreamUnitID * 0x100 + (int)p_Var8->BSPTreeArray[Inst->bspTree].ID);
      }
    }
    /* WARNING: Subroutine does not return */
    EVENT_ChangeOperandToNumber(stackObject, item_00, 0);
  case 0x38:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, 0x1e);
  case 0x39:
    lVar4 = 0x18;
  LAB_800624d4:
    lVar7 = 1;
    stackObject->id = lVar4;
    *(_Instance **)stackObject->data = Inst;
    *(undefined4 *)(stackObject->data + 4) = 0xffffffff;
    break;
  case 0x3c:
    bVar1 = (Inst->flags & 4U) != 0;
    if (bVar1)
    {
      Inst->flags = Inst->flags & 0xfffffffb;
    }
    /* WARNING: Subroutine does not return */
    EVENT_ChangeOperandToNumber(stackObject, (uint)bVar1, 0);
  case 0x3f:
    /* WARNING: Subroutine does not return */
    EVENT_ChangeOperandToNumber(stackObject, 1, 0);
  case 0x6a:
    uVar6 = Inst->flags;
    if ((int)uVar6 < 0)
    {
      Inst->flags = uVar6 & 0x7fffffff;
    }
    /* WARNING: Subroutine does not return */
    EVENT_ChangeOperandToNumber(stackObject, (uint)((int)uVar6 < 0), 0);
  case 0x79:
    bVar1 = (Inst->flags & 8U) != 0;
    if (bVar1)
    {
      Inst->flags = Inst->flags & 0xfffffff7;
    }
    /* WARNING: Subroutine does not return */
    EVENT_ChangeOperandToNumber(stackObject, (uint)bVar1, 0);
  case 0x7a:
    bVar1 = (Inst->flags & 0x10U) != 0;
    if (bVar1)
    {
      Inst->flags = Inst->flags & 0xffffffef;
    }
    /* WARNING: Subroutine does not return */
    EVENT_ChangeOperandToNumber(stackObject, (uint)bVar1, 0);
  case 0x7d:
    bVar1 = (Inst->flags2 & 0x10000U) != 0;
    if (bVar1)
    {
      Inst->flags2 = Inst->flags2 & 0xfffeffff;
    }
    /* WARNING: Subroutine does not return */
    EVENT_ChangeOperandToNumber(stackObject, (uint)bVar1, 0);
  case 0x7e:
    stackObject->id = 0x1b;
    *(_Instance **)(stackObject->data + 0x10) = Inst;
    *(undefined2 *)(stackObject->data + 2) = 0xffff;
    if (codeStream != (short *)0x0)
    {
      MoveCodeStreamExtra = 1;
      *(int *)(stackObject->data + 4) = (int)codeStream[1];
    }
    item_00 = SOUND_IsInstanceSoundLoaded(Inst->object->soundData, *(long *)(stackObject->data + 4));
    if (item_00 == 0)
    {
      /* WARNING: Read-only address (ram,0x800d2a18) is written */
      if (0 < fontTracker.font_buffer._148_4_ - DAT_800d11ec)
      {
        EventAbortLine = 1;
        fontTracker.font_buffer._148_4_ = fontTracker.font_buffer._148_4_ - DAT_800d11ec;
        return 1;
      }
    }
    else
    {
      if (item_00 == -1)
      {
        return 1;
      }
    }
    /* WARNING: Read-only address (ram,0x800d2a18) is written */
    fontTracker.font_buffer._148_4_ = 0x96000;
    lVar7 = 1;
    break;
  case 0x89:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, 0x24);
  case 0x8b:
  case 0xa6:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, 0);
  case 0x92:
    /* WARNING: Subroutine does not return */
    EVENT_ChangeOperandToNumber(stackObject, 0, 0);
  case 0x97:
    /* WARNING: Subroutine does not return */
    EVENT_ChangeOperandToNumber(stackObject, Inst->currentStreamUnitID, 0);
  case 0x99:
    /* WARNING: Subroutine does not return */
    EVENT_ChangeOperandToNumber(stackObject, (uint)(Inst->tface != (_TFace *)0x0), 0);
  case 0x9f:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, 0x2b);
  case 0xa0:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, 1);
  case 0xa1:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, 0x2c);
  case 0xa7:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, 0);
  case 0xa9:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, 0x1f);
  case 0xaa:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, 0x20);
  }
  /* WARNING: Read-only address (ram,0x800d2a18) is written */
  return lVar7;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_TransformSoundObjectAttribute(struct _PCodeStack *stack /*$a0*/, struct SoundObject *soundObject /*$a1*/, long item /*$a2*/, short *codeStream /*$a3*/)
// line 2169, offset 0x8006264c
/* begin block 1 */
// Start line: 2170
// Start offset: 0x8006264C
// Variables:
// 		long retValue; // $v1

/* begin block 1.1 */
// Start line: 2178
// Start offset: 0x800626A0
// Variables:
// 		int status; // $v1
/* end block 1.1 */
// End offset: 0x80062714
// End Line: 2211
/* end block 1 */
// End offset: 0x80062754
// End Line: 2257

/* begin block 2 */
// Start line: 4723
/* end block 2 */
// End Line: 4724

long EVENT_TransformSoundObjectAttribute(_PCodeStack *stack, SoundObject *soundObject, long item, short *codeStream)

{
  int iVar1;
  long lVar2;

  lVar2 = 0;
  if (item == 0x7e)
  {
    if (codeStream != (short *)0x0)
    {
      MoveCodeStreamExtra = 1;
      soundObject->soundNumber = (int)codeStream[1];
    }
    iVar1 = SOUND_IsInstanceSoundLoaded(*(uchar **)soundObject->data, soundObject->soundNumber);
    if (iVar1 == 0)
    {
      /* WARNING: Read-only address (ram,0x800d2af4) is written */
      if (0 < fontTracker.font_buffer[61]._2_4_ - DAT_800d11ec)
      {
        EventAbortLine = 1;
        fontTracker.font_buffer[61]._2_4_ = fontTracker.font_buffer[61]._2_4_ - DAT_800d11ec;
        return 1;
      }
    }
    else
    {
      if (iVar1 == -1)
      {
        return 1;
      }
    }
    /* WARNING: Read-only address (ram,0x800d2af4) is written */
    fontTracker.font_buffer[61]._2_4_ = 0x96000;
    lVar2 = 1;
  }
  else
  {
    if (item < 0x7f)
    {
      if ((item < 0xf) && (0xc < item))
      {
        soundObject->attribute = (short)item;
        lVar2 = 1;
      }
    }
    else
    {
      if ((item == 0x7f) || (item == 0x80))
      {
        soundObject->attribute = (short)item;
        if (codeStream != (short *)0x0)
        {
          MoveCodeStreamExtra = 2;
          soundObject->value = (int)codeStream[1];
          soundObject->duration = (int)codeStream[2];
        }
        lVar2 = 1;
      }
    }
  }
  /* WARNING: Read-only address (ram,0x800d2af4) is written */
  return lVar2;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_GetGameValue(struct GameObject *gameObject /*$a0*/)
// line 2260, offset 0x80062764
/* begin block 1 */
// Start line: 2261
// Start offset: 0x80062764
// Variables:
// 		long value; // $v1
/* end block 1 */
// End offset: 0x800627F0
// End Line: 2293

/* begin block 2 */
// Start line: 4907
/* end block 2 */
// End Line: 4908

long EVENT_GetGameValue(GameObject *gameObject)

{
  int iVar1;

  if (gameObject->attribute != -1)
  {
    if (gameObject->attribute != 2)
    {
      return 0;
    }
    iVar1 = GAMELOOP_GetTimeOfDay();
    if (iVar1 == 700)
    {
      return 2;
    }
    if (700 < iVar1)
    {
      if (iVar1 == 0x708)
      {
        return 3;
      }
      if (iVar1 != 0x76c)
      {
        return iVar1;
      }
      return 4;
    }
    if (iVar1 != 600)
    {
      return iVar1;
    }
  }
  return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_TransformGameAttribute(struct _PCodeStack *stack /*$s1*/, struct StackType *stackObject /*$s2*/, long item /*$a2*/, short *codeStream /*$s0*/)
// line 2297, offset 0x80062800
/* begin block 1 */
// Start line: 2298
// Start offset: 0x80062800
// Variables:
// 		long value; // $s0
// 		long retValue; // $a0

/* begin block 1.1 */
// Start line: 2363
// Start offset: 0x8006297C
// Variables:
// 		struct EventTimer *timer; // $a2
// 		short time; // $v1
/* end block 1.1 */
// End offset: 0x800629F4
// End Line: 2391

/* begin block 1.2 */
// Start line: 2410
// Start offset: 0x80062A44
// Variables:
// 		long wipeType; // $v1
// 		long wipeTime; // $a0
/* end block 1.2 */
// End offset: 0x80062AAC
// End Line: 2432

/* begin block 1.3 */
// Start line: 2438
// Start offset: 0x80062ABC
// Variables:
// 		long motor0Time; // $a1
// 		long motor0Speed; // $a0
// 		long motor1Time; // $a3
// 		long motor1Speed; // $a2
/* end block 1.3 */
// End offset: 0x80062AF4
// End Line: 2462

/* begin block 1.4 */
// Start line: 2477
// Start offset: 0x80062B44
// Variables:
// 		short rand1; // $s1
// 		short rand2; // $s0
/* end block 1.4 */
// End offset: 0x80062B8C
// End Line: 2490

/* begin block 1.5 */
// Start line: 2495
// Start offset: 0x80062B94
/* end block 1.5 */
// End offset: 0x80062B94
// End Line: 2497

/* begin block 1.6 */
// Start line: 2505
// Start offset: 0x80062BB4
// Variables:
// 		int number; // $a1
/* end block 1.6 */
// End offset: 0x80062BB4
// End Line: 2507

/* begin block 1.7 */
// Start line: 2515
// Start offset: 0x80062BD4
/* end block 1.7 */
// End offset: 0x80062BD4
// End Line: 2517

/* begin block 1.8 */
// Start line: 2524
// Start offset: 0x80062BF8
/* end block 1.8 */
// End offset: 0x80062BF8
// End Line: 2526
/* end block 1 */
// End offset: 0x80062C64
// End Line: 2576

/* begin block 2 */
// Start line: 4982
/* end block 2 */
// End Line: 4983

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long EVENT_TransformGameAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  int Data;
  long item_00;
  uint item_01;

  item_00 = 0;
  puVar8 = (uint *)switchdataD_80010738[item + -1];
  switch (item)
  {
  case 1:
    /* WARNING: Subroutine does not return */
    EVENT_ChangeOperandToNumber(stackObject, (uint)(DAT_800d11d8 * 0x1e) / 1000, 0);
  case 2:
  case 0x58:
  case 0x59:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x76:
  case 0x77:
  case 0x87:
  case 0x88:
  case 0x89:
  case 0x8c:
  case 0x8e:
  case 0x93:
  case 0x96:
  case 0x9c:
    *(long *)stackObject->data = item;
    break;
  default:
    goto switchD_80062848_caseD_3;
  case 0x14:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(DAT_800d0fd8, 0xb);
  case 0x15:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(DAT_800d0fd8, 0xb);
  case 0x1b:
    item_01 = DAT_800d0ff4;
    if ((DAT_800d0ff4 & 0x90) == 0x90)
    {
      item_01 = DAT_800d0ff4 & 0xffffff6f;
    }
    /* WARNING: Subroutine does not return */
    EVENT_ChangeOperandToNumber(stackObject, item_01, 1);
  case 0x31:
    EVENT_UpdateResetSignalArrayAndWaterMovement((Level *)0x0, (Level *)stackObject, item);
    uVar7 = _CurrentPuzzleLevel;
    uVar6 = currentEventInstance._4_4_;
    item_01 = currentEventInstance._0_4_;
    if (puVar8 == (uint *)0x0)
    {
      return 1;
    }
    if (codeStream == (short *)0x0)
    {
      return 1;
    }
    MoveCodeStreamExtra = 1;
    uVar5 = codeStream[1];
    EventAbortLine = 1;
    EventJustRecievedTimer = 1;
    *(short **)(puVar8 + 3) = codeStream + 2;
    *puVar8 = *puVar8 & 1 | (int)((uint)uVar5 << 0x10) >> 3;
    puVar8[2] = uVar6;
    puVar8[1] = item_01;
    item_00 = EventCurrentEventIndex;
    *(ushort *)(uVar6 + 2) = *(ushort *)(uVar6 + 2) | 1;
    puVar8[4] = uVar7;
    puVar8[5] = item_00;
    break;
  case 0x3d:
    /* WARNING: Subroutine does not return */
    EVENT_ChangeOperandToNumber(stackObject, (int)DAT_800d11c6, 0);
  case 0x42:
    stackObject->id = 0x19;
    *(undefined4 *)stackObject->data = 0x800cfe90;
    *(undefined4 *)(stackObject->data + 8) = 0xffffffff;
    return 1;
  case 0x4a:
    if (codeStream != (short *)0x0)
    {
      MoveCodeStreamExtra = 2;
      DAT_800d1078 = codeStream[2];
      DAT_800d107c = codeStream[1];
      DAT_800d107a = DAT_800d1078;
      if (DAT_800d1078 < 0)
      {
        DAT_800d107a = -DAT_800d1078;
      }
      if (DAT_800d107c == 0xb)
      {
        if (DAT_800d1078 < 0)
        {
          DAT_800d10f0 = DAT_800d10f0 | 0x2000000;
        }
        else
        {
          DAT_800d10f0 = DAT_800d10f0 & 0xfdffffff;
        }
      }
      stack->topOfStack = stack->topOfStack + -1;
    }
    break;
  case 0x51:
    item_00 = 10;
    Data = 0;
    goto LAB_80062b28;
  case 0x52:
    item_00 = 0x2a;
    Data = 1;
  LAB_80062b28:
    INSTANCE_Broadcast((_Instance *)0x0, item_00, (int)&LAB_0004000c_2, Data);
    stack->topOfStack = stack->topOfStack + -1;
    return 1;
  case 0x5a:
    if (codeStream != (short *)0x0)
    {
      MoveCodeStreamExtra = 2;
      /* WARNING: Subroutine does not return */
      rand();
    }
    break;
  case 0x78:
    Data = LOAD_IsXAInQueue();
    /* WARNING: Subroutine does not return */
    EVENT_ChangeOperandToNumber(stackObject, (uint)(Data == 0), 0);
  case 0x86:
    /* WARNING: Subroutine does not return */
    EVENT_ChangeOperandToNumber(stackObject, DAT_800d10f0 >> 0x17 & 1, 0);
  case 0x91:
    stack->topOfStack = stack->topOfStack + -1;
    EVENT_AddShortPointerToStack(stack, &gEndGameNow);
    return 1;
  case 0x9a:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(DAT_800d0fd8, 0x29);
  case 0x9b:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(DAT_800d0fd8, 0x2a);
  case 0x9d:
    item_00 = HINT_GetCurrentHint();
    /* WARNING: Subroutine does not return */
    EVENT_ChangeOperandToNumber(stackObject, item_00, 0);
  case 0x9e:
    /* WARNING: Subroutine does not return */
    EVENT_ChangeOperandToNumber(stackObject, DAT_800d10f0 & 0x100000, 0);
  case 0xa2:
    if (codeStream != (short *)0x0)
    {
      MoveCodeStreamExtra = 4;
      sVar1 = codeStream[1];
      sVar2 = codeStream[2];
      sVar3 = codeStream[4];
      sVar4 = codeStream[3];
      stack->topOfStack = stack->topOfStack + -1;
      GAMEPAD_Shock((int)sVar1, (int)sVar2 << 0xc, (int)sVar4, (int)sVar3 << 0xc);
      return 1;
    }
    break;
  case 0xa8:
    stack->topOfStack = stack->topOfStack + -1;
    if ((vmRealClock & 0x80000U) == 0)
    {
      return 1;
    }
    Data = LOAD_IsXAInQueue();
    if (Data != 0)
    {
      EventAbortLine = 1;
      item_00 = 1;
      goto switchD_80062848_caseD_3;
    }
  }
  item_00 = 1;
switchD_80062848_caseD_3:
  /* WARNING: Read-only address (ram,0x800d0fd8) is written */
  return item_00;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_TransformAreaAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a1*/, long item /*$a2*/, short *codeStream /*$a3*/)
// line 2580, offset 0x80062c80
/* begin block 1 */
// Start line: 2581
// Start offset: 0x80062C80
// Variables:
// 		long retValue; // $v1
// 		long offset; // $a1
// 		struct _StreamUnit *streamUnit; // $t0
/* end block 1 */
// End offset: 0x80062D4C
// End Line: 2635

/* begin block 2 */
// Start line: 5598
/* end block 2 */
// End Line: 5599

long EVENT_TransformAreaAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  short sVar1;
  long lVar2;
  int iVar3;

  iVar3 = *(int *)stackObject->data;
  lVar2 = 0;
  if (iVar3 == 0)
  {
    EventAbortLine = 1;
    lVar2 = 1;
  }
  else
  {
    if (item == 0x41)
    {
      stack->topOfStack = stack->topOfStack + -1;
      EVENT_AddShortPointerToStack(stack, (short *)(*(int *)(iVar3 + 8) + 0x38));
      lVar2 = 1;
    }
    else
    {
      if (item < 0x42)
      {
        if (item == 3)
        {
          MoveCodeStreamExtra = 1;
          sVar1 = codeStream[1];
          if ((uint)(int)sVar1 < 6)
          {
            stack->topOfStack = stack->topOfStack + -1;
            EVENT_AddShortPointerToStack(stack, (short *)(iVar3 + (int)sVar1 * 2 + 0x24));
            lVar2 = 1;
          }
        }
      }
      else
      {
        if ((item < 0x72) && (0x6f < item))
        {
          *(long *)(stackObject->data + 4) = item;
          lVar2 = 1;
        }
      }
    }
  }
  return lVar2;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_TransformEventAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a1*/, long item /*$a2*/, short *codeStream /*$a3*/)
// line 2639, offset 0x80062d5c
/* begin block 1 */
// Start line: 2640
// Start offset: 0x80062D5C
// Variables:
// 		long retValue; // $v1
// 		long offset; // $a1
// 		struct Event *event; // $t0
/* end block 1 */
// End offset: 0x80062DDC
// End Line: 2691

/* begin block 2 */
// Start line: 5722
/* end block 2 */
// End Line: 5723

long EVENT_TransformEventAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  short sVar1;
  long lVar2;
  int iVar3;

  iVar3 = *(int *)stackObject->data;
  lVar2 = 0;
  if (item == 3)
  {
    MoveCodeStreamExtra = 1;
    sVar1 = codeStream[1];
    if ((uint)(int)sVar1 < 6)
    {
      stack->topOfStack = stack->topOfStack + -1;
      EVENT_AddShortPointerToStack(stack, (short *)(iVar3 + (int)sVar1 * 2 + 6));
      lVar2 = 1;
    }
  }
  else
  {
    if ((item == 0x1a) && (lVar2 = 1, *(char *)(iVar3 + 5) == '\0'))
    {
      *(undefined *)(iVar3 + 5) = 1;
    }
  }
  return lVar2;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_TransformSavedEventAttribute(struct _PCodeStack *stack /*$t0*/, struct StackType *stackObject /*$a0*/, long item /*$a2*/, short *codeStream /*$a3*/)
// line 2694, offset 0x80062dec
/* begin block 1 */
// Start line: 2695
// Start offset: 0x80062DEC
// Variables:
// 		long retValue; // $v1
// 		long offset; // $a1

/* begin block 1.1 */
// Start line: 2713
// Start offset: 0x80062E44
/* end block 1.1 */
// End offset: 0x80062E44
// End Line: 2715

/* begin block 1.2 */
// Start line: 2722
// Start offset: 0x80062E68
/* end block 1.2 */
// End offset: 0x80062E68
// End Line: 2724
/* end block 1 */
// End offset: 0x80062E98
// End Line: 2753

/* begin block 2 */
// Start line: 5843
/* end block 2 */
// End Line: 5844

long EVENT_TransformSavedEventAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  long lVar1;
  uint uVar2;
  char *pcVar3;

  lVar1 = 0;
  if (item == 3)
  {
    MoveCodeStreamExtra = 1;
    uVar2 = SEXT24(codeStream[1]);
    if (uVar2 < 6)
    {
      pcVar3 = *(char **)stackObject->data;
      if (pcVar3 == (char *)0x0)
      {
        /* WARNING: Subroutine does not return */
        EVENT_ChangeOperandToNumber(stackObject, 0, 0);
      }
      if (*pcVar3 == '\x02')
      {
        stack->topOfStack = stack->topOfStack + -1;
        EVENT_AddShortPointerToStack(stack, (short *)(pcVar3 + uVar2 * 2 + 6));
        lVar1 = 1;
      }
      else
      {
        stack->topOfStack = stack->topOfStack + -1;
        EVENT_AddCharPointerToStack(stack, pcVar3 + uVar2 + 5);
        lVar1 = 1;
      }
    }
  }
  return lVar1;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_TransformSubListObjectAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a1*/, long item /*$a2*/)
// line 2756, offset 0x80062ea8
/* begin block 1 */
// Start line: 2758
// Start offset: 0x80062EA8
// Variables:
// 		long retValue; // $a0
/* end block 1 */
// End offset: 0x80062ED4
// End Line: 2777

/* begin block 2 */
// Start line: 5970
/* end block 2 */
// End Line: 5971

/* begin block 3 */
// Start line: 5971
/* end block 3 */
// End Line: 5972

/* begin block 4 */
// Start line: 5977
/* end block 4 */
// End Line: 5978

long EVENT_TransformSubListObjectAttribute(_PCodeStack *stack, StackType *stackObject, long item)

{
  int iVar1;

  iVar1 = *(int *)(stackObject->data + 8);
  if (iVar1 < 5)
  {
    *(long *)(stackObject->data + iVar1 * 4 + 0xc) = item;
    *(int *)(stackObject->data + 8) = iVar1 + 1;
  }
  return (uint)(iVar1 < 5);
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_TransformListObjectAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a1*/, long item /*$a2*/)
// line 2780, offset 0x80062edc
/* begin block 1 */
// Start line: 2782
// Start offset: 0x80062EDC
// Variables:
// 		long retValue; // $a0
/* end block 1 */
// End offset: 0x80062F08
// End Line: 2801

/* begin block 2 */
// Start line: 6019
/* end block 2 */
// End Line: 6020

/* begin block 3 */
// Start line: 6020
/* end block 3 */
// End Line: 6021

/* begin block 4 */
// Start line: 6026
/* end block 4 */
// End Line: 6027

long EVENT_TransformListObjectAttribute(_PCodeStack *stack, StackType *stackObject, long item)

{
  int iVar1;

  iVar1 = *(int *)(stackObject->data + 0x18);
  if (iVar1 < 5)
  {
    *(long *)(stackObject->data + iVar1 * 4 + 4) = item;
    *(int *)(stackObject->data + 0x18) = iVar1 + 1;
  }
  return (uint)(iVar1 < 5);
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_TransformCameraObjectAttribute(struct _PCodeStack *stack /*$s0*/, struct StackType *stackObject /*$a0*/, long item /*$a2*/, short *codeStream /*$a3*/)
// line 2804, offset 0x80062f10
/* begin block 1 */
// Start line: 2805
// Start offset: 0x80062F10
// Variables:
// 		long retValue; // $v1
// 		struct Camera *camera; // $t0

/* begin block 1.1 */
// Start line: 2816
// Start offset: 0x80062F98
// Variables:
// 		short time; // $a1
/* end block 1.1 */
// End offset: 0x80062FEC
// End Line: 2830

/* begin block 1.2 */
// Start line: 2846
// Start offset: 0x8006300C
/* end block 1.2 */
// End offset: 0x8006300C
// End Line: 2848
/* end block 1 */
// End offset: 0x80063028
// End Line: 2877

/* begin block 2 */
// Start line: 6068
/* end block 2 */
// End Line: 6069

long EVENT_TransformCameraObjectAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  if (item < 0x4a)
  {
    if (((item < 0x43) && (item != 9)) && (item != 0x10))
    {
      return 0;
    }
  }
  else
  {
    if (item != 0x68)
    {
      if (item < 0x69)
      {
        if (item != 0x5d)
        {
          return 0;
        }
        if (codeStream == (short *)0x0)
        {
          return 1;
        }
        MoveCodeStreamExtra = 2;
        CAMERA_SetShake(*(Camera **)stackObject->data, (int)codeStream[1],
                        ((int)codeStream[2] << 0xc) / 100);
        stack->topOfStack = stack->topOfStack + -1;
        return 1;
      }
      if (item != 0x69)
      {
        if (item == 0x75)
        {
          /* WARNING: Subroutine does not return */
          EVENT_ChangeOperandToNumber(stackObject,
                                      (uint)(((*(Camera **)stackObject->data)->data).Cinematic.cinema_done != 0), 0);
        }
        return 0;
      }
      if (codeStream != (short *)0x0)
      {
        MoveCodeStreamExtra = 1;
        *(int *)(stackObject->data + 4) = (int)codeStream[1];
      }
    }
  }
  *(long *)(stackObject->data + 8) = item;
  return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_TransformSplineAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a1*/, long item /*$a2*/, short *codeStream /*$a3*/)
// line 2880, offset 0x8006303c
/* begin block 1 */
// Start line: 2881
// Start offset: 0x8006303C
// Variables:
// 		long retValue; // $v1
// 		struct _Instance *instance; // $s0

/* begin block 1.1 */
// Start line: 2903
// Start offset: 0x800630C4
// Variables:
// 		long maxKeyFrames; // $v0
/* end block 1.1 */
// End offset: 0x800630F8
// End Line: 2914
/* end block 1 */
// End offset: 0x8006312C
// End Line: 2932

/* begin block 2 */
// Start line: 6240
/* end block 2 */
// End Line: 6241

long EVENT_TransformSplineAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  ushort uVar1;
  short sVar2;
  _Instance *instance;

  instance = *(_Instance **)stackObject->data;
  if (item == 0x22)
  {
    *(uint *)(stackObject->data + 0x14) = *(uint *)(stackObject->data + 0x14) | 4;
  }
  else
  {
    if (item < 0x23)
    {
      if (item == 0x1f)
      {
        MoveCodeStreamExtra = 2;
        instance->clipBeg = codeStream[1];
        uVar1 = instance->splineFlags;
        instance->clipEnd = codeStream[2];
        instance->splineFlags = uVar1 | 2;
        if (*(int *)&instance->clipBeg == -1)
        {
          instance->splineFlags = uVar1 & 0xfffd;
        }
        else
        {
          sVar2 = SCRIPTCountFramesInSpline(instance);
          if (sVar2 <= instance->clipEnd)
          {
            instance->clipEnd = sVar2;
          }
          if (instance->clipBeg < 0)
          {
            instance->clipBeg = 0;
          }
        }
      }
      else
      {
        *(long *)(stackObject->data + 8) = item;
      }
    }
    else
    {
      if (item == 0x23)
      {
        *(uint *)(stackObject->data + 0x14) = *(uint *)(stackObject->data + 0x14) | 8;
      }
      else
      {
        *(long *)(stackObject->data + 8) = item;
      }
    }
  }
  return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_TransformIntroAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$s3*/, long item /*$a2*/)
// line 2935, offset 0x80063140
/* begin block 1 */
// Start line: 2936
// Start offset: 0x80063140
// Variables:
// 		long retValue; // $v0
// 		long x; // $s0
// 		long y; // $s1
// 		long z; // $s2
// 		struct Intro *intro; // $a3

/* begin block 1.1 */
// Start line: 2947
// Start offset: 0x8006318C
/* end block 1.1 */
// End offset: 0x800631D8
// End Line: 2962

/* begin block 1.2 */
// Start line: 2969
// Start offset: 0x800631D8
// Variables:
// 		struct Rotation3d vector; // stack offset -48
/* end block 1.2 */
// End offset: 0x800631D8
// End Line: 2972
/* end block 1 */
// End offset: 0x80063240
// End Line: 3039

/* begin block 2 */
// Start line: 6363
/* end block 2 */
// End Line: 6364

long EVENT_TransformIntroAttribute(_PCodeStack *stack, StackType *stackObject, long item)

{
  short sVar1;
  short sVar2;
  short sVar3;
  void *pointer;
  Rotation3d local_30;

  pointer = *(void **)stackObject->data;
  switch (item)
  {
  case 4:
  case 0x3e:
  case 0x8a:
  case 0x92:
  case 0xa0:
  case 0xa6:
    *(long *)(stackObject->data + 4) = item;
    break;
  case 5:
    if ((*(uint *)((int)pointer + 0x2c) & 0x4000) != 0)
    {
      sVar1 = *(short *)((int)pointer + 0x20);
      sVar2 = *(short *)((int)pointer + 0x22);
      sVar3 = *(short *)((int)pointer + 0x24);
      STREAM_WhichUnitPointerIsIn(pointer);
      EVENT_WriteEventObject(stackObject, (int)sVar1, (Event *)(int)sVar2, (int)sVar3);
      return 1;
    }
  default:
    EventAbortLine = 1;
    break;
  case 9:
    local_30.vx = *(short *)((int)pointer + 0x18);
    local_30.vy = *(short *)((int)pointer + 0x1a);
    local_30.vz = *(short *)((int)pointer + 0x1c);
    local_30.errorx = 0x200;
    local_30.errorz = 0x200;
    local_30.errory = 0x200;
    EVENT_ChangeOperandRotation3d(stackObject, &local_30);
    break;
  case 0x3f:
    /* WARNING: Subroutine does not return */
    EVENT_ChangeOperandToNumber(stackObject, 0, 0);
  }
  return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_ParseOperand2(struct StackType *operand2 /*$a0*/, long *error /*$s0*/, long *trueValue /*$s1*/)
// line 3041, offset 0x8006325c
/* begin block 1 */
// Start line: 3042
// Start offset: 0x8006325C
// Variables:
// 		long number; // $v0

/* begin block 1.1 */
// Start line: 3047
// Start offset: 0x8006327C
// Variables:
// 		short flags; // stack offset -24
/* end block 1.1 */
// End offset: 0x800632A0
// End Line: 3055
/* end block 1 */
// End offset: 0x800632A0
// End Line: 3057

/* begin block 2 */
// Start line: 6616
/* end block 2 */
// End Line: 6617

long EVENT_ParseOperand2(StackType *operand2, long *error, long *trueValue)

{
  long lVar1;
  short asStack24[4];

  lVar1 = -1;
  if (((operand2 != (StackType *)0x0) &&
       (lVar1 = EVENT_GetScalerValueFromOperand(operand2, error, asStack24), *error == 0)) &&
      (lVar1 == 0))
  {
    *trueValue = 0;
  }
  return lVar1;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_DoVMObjectAction(struct EventVmObject *vmobject /*$s0*/, struct StackType *operand2 /*$a0*/)
// line 3059, offset 0x800632b4
/* begin block 1 */
// Start line: 3060
// Start offset: 0x800632B4
// Variables:
// 		long result; // $s1
// 		long trueValue; // stack offset -20
// 		long number; // $a2
// 		long error; // stack offset -24
/* end block 1 */
// End offset: 0x80063458
// End Line: 3134

/* begin block 2 */
// Start line: 6653
/* end block 2 */
// End Line: 6654

long EVENT_DoVMObjectAction(EventVmObject *vmobject, StackType *operand2)

{
  long table;
  int iVar1;
  StackType *stackObject;
  short *in_a3;
  long local_18;
  uint local_14;

  local_14 = 1;
  local_18 = 1;
  if (vmobject->attribute == -1)
  {
    return 0;
  }
  stackObject = (StackType *)&local_18;
  table = EVENT_ParseOperand2(operand2, (long *)stackObject, (long *)&local_14);
  iVar1 = vmobject->attribute;
  if (iVar1 == 0xe)
  {
    local_14 = (uint)(local_14 == 0);
  }
  else
  {
    if (0xe < iVar1)
    {
      if (iVar1 == 99)
      {
        if (table == -1)
        {
          return 0;
        }
        if (table < 0)
        {
          return 0;
        }
        if (vmobject->vmObjectPtr->numVMOffsetTables <= table)
        {
          return 0;
        }
        VM_VMObjectSetTable(vmobject->level, vmobject->vmObjectPtr, table);
        if ((vmobject->vmObjectPtr->flags & 2) != 0)
        {
          if (vmobject->level != (Level *)0x0)
          {
            VM_ProcessVMObjectSetColor_S();
            return 0;
          }
          return 0;
        }
        return 0;
      }
      if (iVar1 != 100)
      {
        return 0;
      }
      if (table == -1)
      {
        return 1;
      }
      vmobject->vmObjectPtr->timer = table;
      if ((vmobject->vmObjectPtr->flags & 2) == 0)
      {
        return 1;
      }
      if (vmobject->level != (Level *)0x0)
      {
        VM_ProcessVMObjectSetColor_S();
        return 1;
      }
      return 1;
    }
    if (iVar1 != 0xd)
    {
      return 0;
    }
  }
  if (local_14 == 0)
  {
    vmobject->vmObjectPtr->flags = vmobject->vmObjectPtr->flags | 2;
    return 1;
  }
  table = EVENT_TransformSavedEventAttribute((_PCodeStack *)operand2, stackObject, table, in_a3);
  return table;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_GetVMObjectValue(struct EventVmObject *vmobject /*$a0*/)
// line 3137, offset 0x80063474
/* begin block 1 */
// Start line: 3139
// Start offset: 0x80063474
// Variables:
// 		long value; // $a1
// 		long trueValue; // $a2
/* end block 1 */
// End offset: 0x8006352C
// End Line: 3167

/* begin block 2 */
// Start line: 6811
/* end block 2 */
// End Line: 6812

/* begin block 3 */
// Start line: 6812
/* end block 3 */
// End Line: 6813

long EVENT_GetVMObjectValue(EventVmObject *vmobject)

{
  int iVar1;
  uint uVar2;

  iVar1 = vmobject->attribute;
  uVar2 = 1;
  if (iVar1 == 0xe)
  {
    uVar2 = 0;
  }
  else
  {
    if (0xe < iVar1)
    {
      if (iVar1 == 99)
      {
        return (int)vmobject->vmObjectPtr->currentIdx;
      }
      if (iVar1 != 100)
      {
        return 0;
      }
      return vmobject->vmObjectPtr->timer % vmobject->vmObjectPtr->curVMOffsetTable->numVMOffsets;
    }
    if (iVar1 == -1)
    {
      return 1;
    }
    if (iVar1 != 0xd)
    {
      return 0;
    }
  }
  if ((vmobject->vmObjectPtr->flags & 2) != 0)
  {
    uVar2 = (uint)(uVar2 == 0);
  }
  return uVar2;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_DoGameAction(struct GameObject *gameObject /*$s2*/, struct StackType *operand2 /*$a0*/)
// line 3170, offset 0x8006353c
/* begin block 1 */
// Start line: 3171
// Start offset: 0x8006353C
// Variables:
// 		long error; // stack offset -32
// 		long number; // $s0
// 		long trueValue; // stack offset -28
/* end block 1 */
// End offset: 0x80063810
// End Line: 3303

/* begin block 2 */
// Start line: 6877
/* end block 2 */
// End Line: 6878

long EVENT_DoGameAction(GameObject *gameObject, StackType *operand2)

{
  long modifier;
  short hintNumber;
  int iVar1;
  long *error;
  long *trueValue;
  int in_a3;
  int local_20;
  long local_1c;

  local_20 = 1;
  local_1c = 1;
  if (gameObject->attribute != -1)
  {
    error = &local_20;
    trueValue = &local_1c;
    modifier = EVENT_ParseOperand2(operand2, error, trueValue);
    iVar1 = gameObject->attribute;
    if (iVar1 == 0x87)
    {
      SOUND_SetMusicModifier(modifier);
    }
    else
    {
      if (iVar1 < 0x88)
      {
        if (iVar1 == 0x59)
        {
          if (local_20 != 0)
          {
            FX_Start_Rain(100);
            return 1;
          }
          FX_Start_Rain(modifier);
          return 1;
        }
        if (iVar1 < 0x5a)
        {
          if (iVar1 != 2)
          {
            if (iVar1 != 0x58)
            {
              return 1;
            }
            if (local_20 != 0)
            {
              FX_Start_Snow(100);
              return 1;
            }
            FX_Start_Snow(modifier);
            return 1;
          }
          if (modifier == 2)
          {
            FONT_SetColorIndexCol(700, (int)error, (int)trueValue, in_a3);
            return 1;
          }
          if (modifier < 3)
          {
            if (modifier != 1)
            {
              return 1;
            }
            FONT_SetColorIndexCol(600, (int)error, (int)trueValue, in_a3);
            return 1;
          }
          if (modifier == 3)
          {
            FONT_SetColorIndexCol(0x708, (int)error, (int)trueValue, in_a3);
            return 1;
          }
          if (modifier != 4)
          {
            return 1;
          }
          FONT_SetColorIndexCol(0x76c, (int)error, (int)trueValue, in_a3);
          return 1;
        }
        if (iVar1 != 0x76)
        {
          if (iVar1 != 0x77)
          {
            return 1;
          }
          if (0x7e < modifier - 1U)
          {
            return 1;
          }
          SOUND_SetVoiceVolume(modifier);
          return 1;
        }
        if (modifier < 0)
        {
          return 1;
        }
        if ((vmRealClock & 0x80000U) == 0)
        {
          return 1;
        }
        if (fontTracker.font_buffer[62]._0_4_ == modifier)
        {
          iVar1 = VOICEXA_IsPlaying();
          if (iVar1 == 2)
          {
            fontTracker.font_buffer[62]._0_4_ = 0xffffffff;
            return 1;
          }
        }
        else
        {
          iVar1 = LOAD_IsXAInQueue();
          if (iVar1 == 0)
          {
            LOAD_PlayXA(modifier);
            EventAbortLine = 1;
            fontTracker.font_buffer[62]._0_4_ = modifier;
            return 1;
            /* WARNING: Read-only address (ram,0x800d2af8) is written */
          }
        }
      }
      else
      {
        if (iVar1 == 0x93)
        {
          HINT_StopHint();
          return 1;
        }
        hintNumber = (short)modifier;
        if (iVar1 < 0x94)
        {
          if (iVar1 == 0x88)
          {
            SOUND_ResetMusicModifier(modifier);
            return 1;
          }
          if (iVar1 != 0x8e)
          {
            return 1;
          }
          HINT_StartHint(hintNumber);
          return 1;
        }
        if (iVar1 != 0x96)
        {
          if (iVar1 != 0x9c)
          {
            return 1;
          }
          HINT_KillSpecificHint(hintNumber);
          return 1;
        }
        fontTracker.font_buffer[39].y = hintNumber;
        if (fontTracker.font_buffer[38]._4_2_ != 0)
        {
          fontTracker.font_buffer[38]._4_2_ = 0;
          fontTracker.font_buffer[39].y = -1;
          return 1;
        }
      }
      EventAbortLine = 1;
    }
  }
  /* WARNING: Read-only address (ram,0x800d2a6c) is written */
  /* WARNING: Read-only address (ram,0x800d2a70) is written */
  /* WARNING: Read-only address (ram,0x800d2af8) is written */
  return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_DoSignalAction(struct SignalObject *signalObject /*$s0*/, struct StackType *operand2 /*$a0*/)
// line 3306, offset 0x80063830
/* begin block 1 */
// Start line: 3307
// Start offset: 0x80063830
// Variables:
// 		long trueValue; // stack offset -12
// 		long number; // $v1
// 		long error; // stack offset -16
/* end block 1 */
// End offset: 0x80063898
// End Line: 3339

/* begin block 2 */
// Start line: 7151
/* end block 2 */
// End Line: 7152

long EVENT_DoSignalAction(SignalObject *signalObject, StackType *operand2)

{
  long lStack16;
  int local_c;

  local_c = 1;
  if (((signalObject->attribute != -1) &&
       (EVENT_ParseOperand2(operand2, &lStack16, &local_c), signalObject->attribute == 0x1a)) &&
      (local_c != 0))
  {
    COLLIDE_HandleSignal(DAT_800d0fd8, signalObject->msignal->signalList, signalObject->msignal->numSignals, 0);
  }
  return 0;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_TransformSignalAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a0*/, long item /*$a2*/)
// line 3342, offset 0x800638ac
/* begin block 1 */
// Start line: 3343
// Start offset: 0x800638AC
// Variables:
// 		long retValue; // $v1
// 		struct _MultiSignal *msignal; // $a1
/* end block 1 */
// End offset: 0x800638F4
// End Line: 3371

/* begin block 2 */
// Start line: 7228
/* end block 2 */
// End Line: 7229

long EVENT_TransformSignalAttribute(_PCodeStack *stack, StackType *stackObject, long item)

{
  long lVar1;

  lVar1 = 0;
  if (item == 0x1a)
  {
    *(undefined4 *)(stackObject->data + 4) = 0x1a;
    lVar1 = 1;
  }
  else
  {
    if (item == 0x32)
    {
      /* WARNING: Subroutine does not return */
      EVENT_ChangeOperandToNumber(stackObject, (uint) * (ushort *)(*(int *)stackObject->data + 6) & 1, 0);
    }
  }
  return lVar1;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_TransformRotation3dAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a1*/, long item /*$a2*/, short *codeStream /*$a3*/)
// line 3375, offset 0x80063904
/* begin block 1 */
// Start line: 3377
// Start offset: 0x80063904
// Variables:
// 		long retValue; // $v0
/* end block 1 */
// End offset: 0x80063934
// End Line: 3397

/* begin block 2 */
// Start line: 7302
/* end block 2 */
// End Line: 7303

/* begin block 3 */
// Start line: 7303
/* end block 3 */
// End Line: 7304

/* begin block 4 */
// Start line: 7305
/* end block 4 */
// End Line: 7306

long EVENT_TransformRotation3dAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  if ((5 < item) && ((item < 9 || ((item < 99 && (0x5f < item))))))
  {
    *(long *)(stackObject->data + 0x10) = item;
    return 1;
  }
  return 0;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_TransformVector3dAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a0*/, long item /*$a2*/, short *codeStream /*$a3*/)
// line 3399, offset 0x8006393c
/* begin block 1 */
// Start line: 3400
// Start offset: 0x8006393C
// Variables:
// 		long retValue; // $a2
/* end block 1 */
// End offset: 0x80063A28
// End Line: 3452

/* begin block 2 */
// Start line: 7350
/* end block 2 */
// End Line: 7351

long EVENT_TransformVector3dAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  short sVar1;
  long item_00;

  switch (item)
  {
  case 6:
    item_00 = (long)*(short *)stackObject->data;
    goto LAB_80063990;
  case 7:
    item_00 = (long)*(short *)(stackObject->data + 2);
    goto LAB_80063990;
  case 8:
    item_00 = (long)*(short *)(stackObject->data + 4);
  LAB_80063990:
    /* WARNING: Subroutine does not return */
    EVENT_ChangeOperandToNumber(stackObject, item_00, 0);
  default:
    item_00 = 0;
    break;
  case 0x17:
    item_00 = 1;
    sVar1 = codeStream[1];
    *(undefined2 *)(stackObject->data + 10) = 0xffff;
    *(undefined2 *)(stackObject->data + 0xc) = 0xffff;
    MoveCodeStreamExtra = 1;
    *(short *)(stackObject->data + 8) = sVar1;
    break;
  case 0x18:
    MoveCodeStreamExtra = 2;
    item_00 = 1;
    *(short *)(stackObject->data + 8) = codeStream[1];
    sVar1 = codeStream[2];
    *(undefined2 *)(stackObject->data + 0xc) = 0xffff;
    *(short *)(stackObject->data + 10) = sVar1;
    break;
  case 0x19:
    MoveCodeStreamExtra = 3;
    *(short *)(stackObject->data + 8) = codeStream[1];
    *(short *)(stackObject->data + 10) = codeStream[2];
    item_00 = 1;
    *(short *)(stackObject->data + 0xc) = codeStream[3];
  }
  return item_00;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_ModifyObjectToStackWithAttribute(struct _PCodeStack *stack /*$a0*/, long item /*$a1*/, short *codeStream /*$a2*/)
// line 3455, offset 0x80063a38
/* begin block 1 */
// Start line: 7479
/* end block 1 */
// End Line: 7480

void EVENT_ModifyObjectToStackWithAttribute(_PCodeStack *stack, long item, short *codeStream)

{
  if (stack->topOfStack != 0)
  {
    EVENT_TransformObjectOnStack(stack, item, codeStream);
  }
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_DoInstanceAnimateTextureAction(struct InstanceAnimateTexture *instanceAniTexture /*$s1*/, struct StackType *operand2 /*$a0*/)
// line 3478, offset 0x80063a68
/* begin block 1 */
// Start line: 3479
// Start offset: 0x80063A68
// Variables:
// 		long trueValue; // stack offset -20
// 		long number; // $a2
// 		long result; // $s0
// 		long error; // stack offset -24
/* end block 1 */
// End offset: 0x80063B58
// End Line: 3532

/* begin block 2 */
// Start line: 7525
/* end block 2 */
// End Line: 7526

long EVENT_DoInstanceAnimateTextureAction(InstanceAnimateTexture *instanceAniTexture, StackType *operand2)

{
  long lVar1;
  long lVar2;
  int local_18;
  uint local_14;

  local_14 = 1;
  local_18 = 1;
  if (instanceAniTexture->attribute == -1)
  {
    lVar2 = 1;
  }
  else
  {
    lVar1 = EVENT_ParseOperand2(operand2, &local_18, (long *)&local_14);
    lVar2 = 0;
    switch (instanceAniTexture->attribute)
    {
    case 0xe:
      local_14 = local_14 ^ 1;
    case 0xd:
    case 0x29:
      lVar2 = 1;
      if (local_14 == 0)
      {
        instanceAniTexture->instance->flags = instanceAniTexture->instance->flags | 0x80;
      }
      else
      {
        instanceAniTexture->instance->flags = instanceAniTexture->instance->flags & 0xffffff7f;
      }
      break;
    case 0xf:
    case 0x28:
      lVar2 = 0;
      if (local_18 == 0)
      {
        instanceAniTexture->instance->currentTextureAnimFrame = (short)lVar1;
        lVar2 = 0;
      }
    }
  }
  return lVar2;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_ResetAllSplineFlags(struct MultiSpline *spline /*$a0*/)
// line 3535, offset 0x80063b70
/* begin block 1 */
// Start line: 7650
/* end block 1 */
// End Line: 7651

/* begin block 2 */
// Start line: 7651
/* end block 2 */
// End Line: 7652

void EVENT_ResetAllSplineFlags(MultiSpline *spline)

{
  Spline *pSVar1;
  RSpline *pRVar2;

  pSVar1 = spline->positional;
  if (pSVar1 != (Spline *)0x0)
  {
    pSVar1->flags = pSVar1->flags & 0xf8;
  }
  pRVar2 = spline->rotational;
  if (pRVar2 != (RSpline *)0x0)
  {
    pRVar2->flags = pRVar2->flags & 0xf8;
  }
  pSVar1 = spline->scaling;
  if (pSVar1 != (Spline *)0x0)
  {
    pSVar1->flags = pSVar1->flags & 0xf8;
  }
  pSVar1 = spline->color;
  if (pSVar1 != (Spline *)0x0)
  {
    pSVar1->flags = pSVar1->flags & 0xf8;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_SetSplineLoop(struct MultiSpline *spline /*$a0*/)
// line 3543, offset 0x80063bf8
/* begin block 1 */
// Start line: 7666
/* end block 1 */
// End Line: 7667

/* begin block 2 */
// Start line: 7667
/* end block 2 */
// End Line: 7668

void EVENT_SetSplineLoop(MultiSpline *spline)

{
  Spline *pSVar1;
  RSpline *pRVar2;

  pSVar1 = spline->positional;
  if (pSVar1 != (Spline *)0x0)
  {
    pSVar1->flags = pSVar1->flags | 2;
  }
  pRVar2 = spline->rotational;
  if (pRVar2 != (RSpline *)0x0)
  {
    pRVar2->flags = pRVar2->flags | 2;
  }
  pSVar1 = spline->scaling;
  if (pSVar1 != (Spline *)0x0)
  {
    pSVar1->flags = pSVar1->flags | 2;
  }
  pSVar1 = spline->color;
  if (pSVar1 != (Spline *)0x0)
  {
    pSVar1->flags = pSVar1->flags | 2;
  }
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_DoSplineAction(struct InstanceSpline *instanceSpline /*$s3*/, struct StackType *operand2 /*$a0*/)
// line 3551, offset 0x80063c80
/* begin block 1 */
// Start line: 3552
// Start offset: 0x80063C80
// Variables:
// 		long trueValue; // stack offset -28
// 		long number; // $s0
// 		long result; // $s4
// 		long error; // stack offset -32

/* begin block 1.1 */
// Start line: 3563
// Start offset: 0x80063CC4
// Variables:
// 		struct _Instance *instance; // $s1
// 		struct MultiSpline *spline; // $s2

/* begin block 1.1.1 */
// Start line: 3615
// Start offset: 0x80063D84
// Variables:
// 		long curKeyFrame; // $a0

/* begin block 1.1.1.1 */
// Start line: 3623
// Start offset: 0x80063D94
// Variables:
// 		long maxKeyFrames; // $v1
/* end block 1.1.1.1 */
// End offset: 0x80063DB4
// End Line: 3631
/* end block 1.1.1 */
// End offset: 0x80063EA8
// End Line: 3675
/* end block 1.1 */
// End offset: 0x80064028
// End Line: 3715
/* end block 1 */
// End offset: 0x80064028
// End Line: 3717

/* begin block 2 */
// Start line: 7682
/* end block 2 */
// End Line: 7683

long EVENT_DoSplineAction(InstanceSpline *instanceSpline, StackType *operand2)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  uint uVar6;
  Spline *pSVar7;
  RSpline *pRVar8;
  _Instance *instance;
  MultiSpline *spline;
  long lVar9;
  long lStack32;
  uint local_1c;

  lVar9 = 0;
  local_1c = 1;
  if (instanceSpline->attribute == -1)
  {
    return 1;
  }
  instance = instanceSpline->instance;
  spline = instanceSpline->spline;
  iVar3 = EVENT_ParseOperand2(operand2, &lStack32, (long *)&local_1c);
  switch (instanceSpline->attribute)
  {
  case 0xd:
  case 0x29:
    goto switchD_80063d04_caseD_d;
  case 0xe:
    local_1c = local_1c ^ 1;
  switchD_80063d04_caseD_d:
    lVar9 = 1;
    if (local_1c == 0)
    {
      uVar6 = instance->flags;
      uVar4 = 0xfdffffff;
    LAB_80063eb4:
      instance->flags = uVar6 & uVar4;
    }
    else
    {
      uVar4 = instance->flags;
      uVar6 = 0x2000000;
    LAB_80063e9c:
      instance->flags = uVar4 | uVar6;
    }
  switchD_80063d04_caseD_12:
    return lVar9;
  case 0xf:
  case 0x28:
    if (iVar3 == -1)
    {
      return 0;
    }
    SCRIPT_InstanceSplineSet(instance, (short)iVar3, (SplineDef *)0x0, (SplineDef *)0x0, (SplineDef *)0x0);
    uVar4 = 0xfdff0000;
    goto LAB_80063eac;
  case 0x10:
    EVENT_ResetAllSplineFlags(spline);
    instance->splineFlags = instance->splineFlags & 0xff8f;
    if (iVar3 == 2)
    {
      EVENT_SetSplineLoop(spline);
      uVar2 = instance->splineFlags | 0x20;
    }
    else
    {
      if ((iVar3 < 3) && (iVar3 == 1))
      {
        pSVar7 = spline->positional;
        if (pSVar7 != (Spline *)0x0)
        {
          pSVar7->flags = pSVar7->flags | 1;
        }
        pRVar8 = spline->rotational;
        if (pRVar8 != (RSpline *)0x0)
        {
          pRVar8->flags = pRVar8->flags | 1;
        }
        pSVar7 = spline->scaling;
        if (pSVar7 != (Spline *)0x0)
        {
          pSVar7->flags = pSVar7->flags | 1;
        }
        pSVar7 = spline->color;
        if (pSVar7 != (Spline *)0x0)
        {
          pSVar7->flags = pSVar7->flags | 1;
        }
        uVar2 = instance->splineFlags | 0x10;
      }
      else
      {
        pSVar7 = spline->positional;
        if (pSVar7 != (Spline *)0x0)
        {
          pSVar7->flags = pSVar7->flags | 4;
        }
        pRVar8 = spline->rotational;
        if (pRVar8 != (RSpline *)0x0)
        {
          pRVar8->flags = pRVar8->flags | 4;
        }
        pSVar7 = spline->scaling;
        if (pSVar7 != (Spline *)0x0)
        {
          pSVar7->flags = pSVar7->flags | 4;
        }
        pSVar7 = spline->color;
        if (pSVar7 != (Spline *)0x0)
        {
          pSVar7->flags = pSVar7->flags | 4;
        }
        uVar2 = instance->splineFlags | 0x40;
      }
    }
    instance->splineFlags = uVar2;
    return 0;
  case 0x11:
    uVar4 = 0xfeff0000;
    if (iVar3 < 1)
      goto LAB_80063e94;
  LAB_80063eac:
    uVar6 = instance->flags;
    uVar4 = uVar4 | 0xffff;
    goto LAB_80063eb4;
  default:
    goto switchD_80063d04_caseD_12;
  case 0x1c:
    if (iVar3 < 0)
    {
      iVar3 = 0;
    }
    else
    {
      sVar1 = SCRIPTCountFramesInSpline(instance);
      if ((int)sVar1 <= iVar3)
      {
        iVar3 = (int)sVar1;
      }
    }
    lVar5 = EVENT_GetSplineFrameNumber(instanceSpline);
    if (lVar5 == iVar3)
    {
      SCRIPT_InstanceSplineSet(instance, (short)iVar3, (SplineDef *)0x0, (SplineDef *)0x0, (SplineDef *)0x0);
      uVar4 = 0xfdff0000;
      goto LAB_80063eac;
    }
    instance->splineFlags = instance->splineFlags | 1;
    instance->targetFrame = (short)iVar3;
    instance->flags = instance->flags | 0x2000000;
    if (iVar3 < lVar5)
    {
      uVar4 = instanceSpline->splineFlags & 4;
      instanceSpline->splineFlags = uVar4;
      if (uVar4 != 0)
      {
        EVENT_ResetAllSplineFlags(spline);
        EVENT_SetSplineLoop(spline);
        instance->splineFlags = instance->splineFlags | 0x20;
        instance->flags = instance->flags & 0xfeffffff;
        return 0;
      }
    }
    else
    {
      uVar4 = instanceSpline->splineFlags & 8;
      instanceSpline->splineFlags = uVar4;
      if (uVar4 == 0)
      {
        uVar4 = 0xfeff0000;
        goto LAB_80063eac;
      }
      EVENT_ResetAllSplineFlags(spline);
      EVENT_SetSplineLoop(spline);
      instance->splineFlags = instance->splineFlags | 0x20;
    }
  LAB_80063e94:
    uVar4 = instance->flags;
    uVar6 = 0x1000000;
    goto LAB_80063e9c;
  }
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_DoAnimateAction(struct InstanceAnimate *instanceAnimate /*$s1*/, struct StackType *operand2 /*$s3*/)
// line 3720, offset 0x8006404c
/* begin block 1 */
// Start line: 3721
// Start offset: 0x8006404C
// Variables:
// 		long trueValue; // stack offset -28
// 		long number; // $a0
// 		long result; // $s2
// 		long error; // stack offset -32
// 		struct _Instance *instance; // $s0

/* begin block 1.1 */
// Start line: 3786
// Start offset: 0x80064128
// Variables:
// 		struct _Instance *hostInstance; // $v0
/* end block 1.1 */
// End offset: 0x80064128
// End Line: 3787
/* end block 1 */
// End offset: 0x80064300
// End Line: 3941

/* begin block 2 */
// Start line: 8043
/* end block 2 */
// End Line: 8044

long EVENT_DoAnimateAction(InstanceAnimate *instanceAnimate, StackType *operand2)

{
  long lVar1;
  int Data;
  short sVar2;
  undefined *Message;
  _Instance *instance;
  long lVar3;
  long lStack32;
  uint local_1c;

  lVar3 = 0;
  local_1c = 1;
  if (instanceAnimate->attribute != -1)
  {
    instance = instanceAnimate->instance;
    lVar1 = EVENT_ParseOperand2(operand2, &lStack32, (long *)&local_1c);
    sVar2 = (short)lVar1;
    switch (instanceAnimate->attribute)
    {
    case 0xe:
      local_1c = local_1c ^ 1;
    case 0xd:
    case 0x29:
      if (local_1c == 0)
      {
        Message = (undefined *)0x8000010;
        Data = 0;
      }
      else
      {
        if ((instance->aliasCommand).hostInstance == (_Instance *)0x0)
        {
          Data = SetAnimationInstanceSwitchData(instance, (int)(instance->aliasCommand).newanim,
                                                (int)(instance->aliasCommand).newframe,
                                                (int)(instance->aliasCommand).interpframes, 1);
          Message = (undefined *)0x8000008;
        }
        else
        {
          Data = SetActionPlayHostAnimationData(instance, (instance->aliasCommand).hostInstance,
                                                (int)(instance->aliasCommand).newanim,
                                                (int)(instance->aliasCommand).newframe,
                                                (int)(instance->aliasCommand).interpframes, 1);
          Message = &DAT_00040003;
        }
      }
      /* WARNING: Subroutine does not return */
      INSTANCE_Post(instance, (int)Message, Data);
    case 0xf:
    case 0x28:
      lVar3 = 0;
      if (lVar1 != -1)
      {
        (instance->aliasCommand).newframe = sVar2;
      }
      break;
    case 0x1e:
      lVar3 = 1;
      if (lVar1 != -1)
      {
        (instance->aliasCommand).newanim = sVar2;
      }
      break;
    case 0x2a:
      if ((instance->aliasCommand).hostInstance == (_Instance *)0x0)
      {
        Data = SetAnimationInstanceSwitchData(instance, (int)(instance->aliasCommand).newanim,
                                              (int)(instance->aliasCommand).newframe,
                                              (int)(instance->aliasCommand).interpframes, 2);
        Message = (undefined *)0x8000008;
      }
      else
      {
        Data = SetActionPlayHostAnimationData(instance, (instance->aliasCommand).hostInstance,
                                              (int)(instance->aliasCommand).newanim,
                                              (int)(instance->aliasCommand).newframe,
                                              (int)(instance->aliasCommand).interpframes, 2);
        Message = &DAT_00040003;
      }
      /* WARNING: Subroutine does not return */
      INSTANCE_Post(instance, (int)Message, Data);
    case 0x65:
      if (operand2 != (StackType *)0x0)
      {
        if (operand2->id == 2)
        {
          (instance->aliasCommand).hostInstance = *(_Instance **)operand2->data;
        }
        else
        {
          EventAbortLine = 1;
          lVar3 = 0;
        }
      }
      break;
    case 0x66:
      lVar3 = 0;
      if (lVar1 != -1)
      {
        (instance->aliasCommand).interpframes = sVar2;
      }
      break;
    case 0x6b:
      if ((instance->aliasCommand).hostInstance == (_Instance *)0x0)
      {
        Data = SetAnimationInstanceSwitchData(instance, (int)(instance->aliasCommand).newanim,
                                              (int)(instance->aliasCommand).newframe,
                                              (int)(instance->aliasCommand).interpframes, 0);
        Message = (undefined *)0x8000008;
      }
      else
      {
        Data = SetActionPlayHostAnimationData(instance, (instance->aliasCommand).hostInstance,
                                              (int)(instance->aliasCommand).newanim,
                                              (int)(instance->aliasCommand).newframe,
                                              (int)(instance->aliasCommand).interpframes, 0);
        Message = &DAT_00040003;
      }
      /* WARNING: Subroutine does not return */
      INSTANCE_Post(instance, (int)Message, Data);
    case 0x84:
      (instance->aliasCommand).speed = sVar2;
    }
  }
  return lVar3;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_DoInstanceAction(struct InstanceObject *instanceObject /*$s3*/, struct StackType *operand2 /*$s2*/, short *codeStream /*$s5*/)
// line 3945, offset 0x80064320
/* begin block 1 */
// Start line: 3946
// Start offset: 0x80064320
// Variables:
// 		long trueValue; // stack offset -36
// 		long number; // $s0
// 		long error; // stack offset -40
// 		long result; // $s4
// 		struct _Instance *instance; // $s1

/* begin block 1.1 */
// Start line: 4077
// Start offset: 0x800646B4
// Variables:
// 		int x; // $a0
// 		int y; // $a1
/* end block 1.1 */
// End offset: 0x80064714
// End Line: 4095

/* begin block 1.2 */
// Start line: 4102
// Start offset: 0x80064730
// Variables:
// 		struct Object *object; // $s2
// 		int i; // $s0
/* end block 1.2 */
// End offset: 0x80064794
// End Line: 4121

/* begin block 1.3 */
// Start line: 4142
// Start offset: 0x800647E4
// Variables:
// 		struct Intro *intro; // $a0
/* end block 1.3 */
// End offset: 0x80064818
// End Line: 4153

/* begin block 1.4 */
// Start line: 4185
// Start offset: 0x800648A0
// Variables:
// 		struct Vector3d *vector3d; // $s0
/* end block 1.4 */
// End offset: 0x800648A0
// End Line: 4188

/* begin block 1.5 */
// Start line: 4203
// Start offset: 0x800648F0
/* end block 1.5 */
// End offset: 0x800648F0
// End Line: 4209

/* begin block 1.6 */
// Start line: 4215
// Start offset: 0x8006492C
/* end block 1.6 */
// End offset: 0x8006492C
// End Line: 4221

/* begin block 1.7 */
// Start line: 4230
// Start offset: 0x80064978
/* end block 1.7 */
// End offset: 0x80064978
// End Line: 4235

/* begin block 1.8 */
// Start line: 4241
// Start offset: 0x800649B4
/* end block 1.8 */
// End offset: 0x800649B4
// End Line: 4247

/* begin block 1.9 */
// Start line: 4253
// Start offset: 0x800649F0
/* end block 1.9 */
// End offset: 0x800649F0
// End Line: 4259

/* begin block 1.10 */
// Start line: 4281
// Start offset: 0x80064A88
// Variables:
// 		struct EventTimer *timer; // $a2
/* end block 1.10 */
// End offset: 0x80064A9C
// End Line: 4286

/* begin block 1.11 */
// Start line: 4320
// Start offset: 0x80064B4C
/* end block 1.11 */
// End offset: 0x80064B4C
// End Line: 4325

/* begin block 1.12 */
// Start line: 4373
// Start offset: 0x80064C2C
/* end block 1.12 */
// End offset: 0x80064C70
// End Line: 4378
/* end block 1 */
// End offset: 0x80064D9C
// End Line: 4431

/* begin block 2 */
// Start line: 8508
/* end block 2 */
// End Line: 8509

long EVENT_DoInstanceAction(InstanceObject *instanceObject, StackType *operand2, short *codeStream)

{
  uint type;
  int Data;
  Intro *pIVar1;
  code *Message;
  undefined *Message_00;
  uint Message_01;
  int y;
  _Instance *sender;
  Object *pOVar2;
  long lStack40;
  uint local_24;

  local_24 = 1;
  sender = instanceObject->instance;
  if (instanceObject->attribute == -1)
  {
    return 0;
  }
  type = EVENT_ParseOperand2(operand2, &lStack40, (long *)&local_24);
  switch (instanceObject->attribute)
  {
  case 4:
    if (0xff < (int)type)
    {
      /* WARNING: Subroutine does not return */
      INSTANCE_Post(sender, (int)&LAB_00040014_3, type - 0x100);
    }
    if (6 < type - 1)
    {
      if (type == 0)
      {
        SAVE_UndestroyInstance(sender);
        return 0;
      }
      return 0;
    }
    ScriptKillInstance(sender, type);
    return 0;
  case 10:
    goto switchD_800643a4_caseD_a;
  case 0xb:
    local_24 = local_24 ^ 1;
  switchD_800643a4_caseD_a:
    if (local_24 == 0)
    {
      type = sender->flags;
      sender->flags2 = sender->flags2 & 0xdfffffff;
      sender->flags = type & 0xfffff7ff;
      sender->flags = type & 0xfffbf7ff;
      if ((sender->object->oflags2 & 0x80000U) == 0)
        goto LAB_800645ec;
      type = sender->flags2 & 0xefffffff;
    }
    else
    {
      sender->flags = sender->flags | 0x800;
      sender->flags2 = sender->flags2 | 0x20000000;
      sender->flags = sender->flags | 0x40000;
      if ((sender->object->oflags2 & 0x80000U) == 0)
        goto LAB_800645ec;
      type = sender->flags2 | 0x10000000;
    }
    sender->flags2 = type;
  LAB_800645ec:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(sender, 1);
  case 0x14:
    local_24 = local_24 ^ 1;
  case 0x15:
    if (local_24 == 0)
    {
      Data = 0x10002001;
    }
    else
    {
      Data = 0x10002002;
    }
    /* WARNING: Subroutine does not return */
    INSTANCE_Post(sender, Data, 0);
  case 0x20:
    if (type == 2)
    {
      Message_00 = &LAB_00040010_2;
    }
    else
    {
      if ((int)type < 3)
      {
        if (type != 1)
        {
          return 0;
        }
        Message_00 = (undefined *)0x40000;
      }
      else
      {
        if (type != 3)
        {
          if (type == 4)
          {
            /* WARNING: Subroutine does not return */
            INSTANCE_Post(sender, (int)&DAT_00040005, (int)&DAT_0000a000);
          }
          return 0;
        }
        Message_00 = &LAB_00040014;
      }
    }
    goto LAB_80064d48;
  case 0x24:
    goto switchD_800643a4_caseD_24;
  case 0x25:
    local_24 = local_24 ^ 1;
  switchD_800643a4_caseD_24:
    if (local_24 != 0)
    {
      /* WARNING: Subroutine does not return */
      INSTANCE_Query(instanceObject->instance, 5);
    }
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(instanceObject->instance, 5);
  case 0x26:
    local_24 = local_24 ^ 1;
  case 0x27:
    if (local_24 == 0)
    {
      type = 0x800000;
    LAB_80064d44:
      Message_00 = (undefined *)(type | 0x22);
    }
    else
    {
      Message_00 = (undefined *)0x800021;
    }
    goto LAB_80064d48;
  case 0x33:
    if (type == 0xffffffff)
    {
      type = 0;
    }
    Message_01 = 0x1000017;
    goto LAB_80064d2c;
  case 0x34:
    if (local_24 == 0)
    {
      type = sender->flags & 0xfffff7ff;
    }
    else
    {
      type = sender->flags | 0x800;
    }
    goto LAB_800644b4;
  case 0x35:
    if (local_24 == 0)
    {
      sender->flags2 = sender->flags2 & 0xdfffffff;
      sender->flags = sender->flags & 0xfffbffff;
      return 1;
    }
    sender->flags2 = sender->flags2 | 0x20000000;
    type = sender->flags | 0x40000;
  LAB_800644b4:
    sender->flags = type;
    return 1;
    /* WARNING: Read-only address (ram,0x800d0fd8) is written */
  case 0x36:
    Data = 0;
    if (type < 4)
    {
      y = 0;
      if (type == 1)
      {
        Data = 1;
      }
      else
      {
        if ((int)type < 2)
        {
          if (type == 0)
          {
            y = 1;
          }
        }
        else
        {
          if (type == 2)
          {
            Data = 0;
            y = -1;
          }
          else
          {
            if (type == 3)
            {
              Data = -1;
            }
          }
        }
      }
      Data = SetObjectData(Data, y, 6, (_Instance *)0x0, 0);
      Message = (code *)0x800000;
    LAB_80064c9c:
      /* WARNING: Subroutine does not return */
      INSTANCE_Post(sender, (int)Message, Data);
    }
    break;
  case 0x37:
    pOVar2 = sender->object;
    Data = (int)pOVar2->numberOfEffects;
    if (Data != 0)
    {
      if (type == 0xffffffff)
      {
        y = 0;
        if (0 < Data)
        {
          do
          {
            FX_StartInstanceEffect(sender, pOVar2->effectList + y, 0);
            y = y + 1;
          } while (y < pOVar2->numberOfEffects);
          return 0;
        }
      }
      else
      {
        if ((int)type < Data)
        {
          FX_StartInstanceEffect(sender, pOVar2->effectList + type, 0);
          return 0;
        }
      }
    }
    break;
  case 0x40:
    if (type != 0)
    {
      type = 1;
    }
    Message_01 = 0x100001a;
    goto LAB_80064d2c;
  case 0x4b:
    if (operand2 != (StackType *)0x0)
    {
      if (operand2->id != 9)
      {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data, (int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      Message = (code *)&LAB_00040014_2;
      goto LAB_80064c9c;
    }
    break;
  case 0x4c:
    if (operand2 != (StackType *)0x0)
    {
      if (operand2->id == 9)
      {
        Data = SetPositionData((int)*(short *)operand2->data, (int)*(short *)(operand2->data + 2),
                               (int)*(short *)(operand2->data + 4));
        /* WARNING: Subroutine does not return */
        INSTANCE_Post(sender, (int)&DAT_0004000a, Data);
      }
      return 0;
    }
    break;
  case 0x4d:
    if (operand2 != (StackType *)0x0)
    {
      if (operand2->id != 0xe)
      {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data, (int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      Message = (code *)&DAT_0004000b;
      goto LAB_80064c9c;
    }
    break;
  case 0x4e:
    goto switchD_800643a4_caseD_4e;
  case 0x4f:
    local_24 = (uint)(local_24 == 0);
  switchD_800643a4_caseD_4e:
    if (sender == DAT_800d0fd8)
    {
      /* WARNING: Subroutine does not return */
      INSTANCE_Post(sender, (int)&LAB_0004000c_2, local_24);
    }
    /* WARNING: Subroutine does not return */
    INSTANCE_Post(sender, (int)&LAB_0004000c_2, local_24);
  case 0x50:
    if (operand2 != (StackType *)0x0)
    {
      if (operand2->id != 0xe)
      {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data, (int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      Message = (code *)&LAB_0004000c_1;
      goto LAB_80064c9c;
    }
    break;
  case 0x53:
    if (operand2 != (StackType *)0x0)
    {
      if (operand2->id != 9)
      {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data, (int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      Message = (code *)&LAB_0004000c_3;
      goto LAB_80064c9c;
    }
    break;
  case 0x54:
    if (local_24 != 0)
    {
      Message_00 = &LAB_00040010;
      goto LAB_80064d48;
    }
    break;
  case 0x55:
    /* WARNING: Subroutine does not return */
    INSTANCE_Post(sender, 0x800027, local_24);
  case 0x5b:
    if (-1 < (int)type)
    {
      sender->lightGroup = (uchar)type;
      return 0;
    }
    return 0;
  case 0x5c:
    if (-1 < (int)type)
    {
      sender->spectralLightGroup = (uchar)type;
      return 0;
    }
    return 0;
  case 0x5e:
    goto switchD_800643a4_caseD_5e;
  case 0x5f:
    local_24 = 0;
  switchD_800643a4_caseD_5e:
    /* WARNING: Subroutine does not return */
    INSTANCE_Post(sender, 0x800029, local_24);
  case 0x67:
    if (local_24 == 0)
    {
      sender->flags = sender->flags | 0x400000;
    }
    else
    {
      sender->flags = sender->flags & 0xffbfffff;
    }
    break;
  case 0x6c:
    Data = (int)type % 0x168;
    if (Data < 0)
    {
      Data = Data + 0x168;
    }
    /* WARNING: Subroutine does not return */
    rcos((Data * 0x1000) / 0x168);
  case 0x6d:
    Message_00 = (undefined *)0x4000006;
    goto LAB_80064d48;
  case 0x6e:
    Message_00 = &LAB_00040010_1;
  LAB_80064d48:
    /* WARNING: Subroutine does not return */
    INSTANCE_Post(sender, (int)Message_00, 0);
  case 0x6f:
    /* WARNING: Subroutine does not return */
    INSTANCE_Post(sender, (int)&LAB_00040014_1, 1 << (type & 0x1f));
  case 0x72:
    if (operand2 != (StackType *)0x0)
    {
      if (operand2->id != 9)
      {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data, (int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      Message = (code *)&LAB_0004000c;
      goto LAB_80064c9c;
    }
    break;
  case 0x74:
    /* WARNING: Subroutine does not return */
    INSTANCE_Post(sender, (int)&PTR_00040006, type << 0xc);
  case 0x7b:
    if (operand2 != (StackType *)0x0)
    {
      if (operand2->id != 9)
      {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data, (int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      Message = FUN_00040018;
      goto LAB_80064c9c;
    }
    break;
  case 0x7c:
    /* WARNING: Subroutine does not return */
    INSTANCE_Post(sender, 0x40019, type << 0xc);
  case 0x85:
    Message_01 = 0x40021;
    goto LAB_80064d2c;
  case 0x8a:
    pIVar1 = sender->intro;
    if (pIVar1 == (Intro *)0x0)
    {
      return 0;
    }
    if (local_24 == 0)
    {
      pIVar1->flags = pIVar1->flags & 0xfffffbff;
    }
    else
    {
      pIVar1->flags = pIVar1->flags | 0x400;
    }
    break;
  case 0x8c:
    Message_01 = 0x40000;
    goto LAB_80064d28;
  case 0x8d:
    if (-1 < (int)type)
    {
      Data = SetMonsterAlarmData(sender, (_Position *)0x0, type);
      INSTANCE_Broadcast((_Instance *)0x0, 10, 0x1000011, Data);
      return 0;
    }
    break;
  case 0xa3:
    Message_01 = 0x1000000;
  LAB_80064d28:
    Message_01 = Message_01 | 0x22;
  LAB_80064d2c:
    /* WARNING: Subroutine does not return */
    INSTANCE_Post(sender, Message_01, type);
  case 0xa4:
    type = 0x1000000;
    goto LAB_80064d44;
  case 0xa5:
    if (sender != DAT_800d0fd8)
    {
      return 0;
    }
    if (local_24 == 0)
    {
      DAT_800d10ec = DAT_800d10ec & 0xffffff6f;
    }
    else
    {
      DAT_800d10ec = DAT_800d10ec | 0x90;
    }
  }
  /* WARNING: Read-only address (ram,0x800d0fd8) is written */
  /* WARNING: Read-only address (ram,0x800d0fd8) is written */
  return 0;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_GetTGroupValue(struct TGroupObject *terrainGroup /*$a0*/)
// line 4434, offset 0x80064dc4
/* begin block 1 */
// Start line: 4436
// Start offset: 0x80064DC4
// Variables:
// 		long value; // $a2
// 		long trueValue; // $a3
// 		struct BSPTree *bspTree; // $a1
/* end block 1 */
// End offset: 0x80064F24
// End Line: 4543

/* begin block 2 */
// Start line: 9517
/* end block 2 */
// End Line: 9518

/* begin block 3 */
// Start line: 9518
/* end block 3 */
// End Line: 9519

long EVENT_GetTGroupValue(TGroupObject *terrainGroup)

{
  ushort uVar1;
  int iVar2;
  BSPTree *pBVar3;
  uint uVar4;

  iVar2 = terrainGroup->attribute;
  pBVar3 = terrainGroup->bspTree;
  uVar4 = 1;
  if (iVar2 == 0x35)
  {
    uVar1 = pBVar3->flags & 2;
  }
  else
  {
    if (iVar2 < 0x36)
    {
      if (iVar2 != 10)
      {
        if (iVar2 < 0xb)
        {
          if (iVar2 != -1)
          {
            return 0;
          }
          return -(terrainGroup->streamUnit->StreamUnitID * 0x100 + (int)pBVar3->ID);
        }
        if (iVar2 != 0xb)
        {
          if (iVar2 != 0x34)
          {
            return 0;
          }
          return (uint)(ushort)pBVar3->flags & 1;
        }
        uVar4 = 0;
      }
      if ((pBVar3->flags & 3U) == 3)
      {
        return uVar4;
      }
      return uVar4 ^ 1;
    }
    if (iVar2 == 0x73)
    {
      uVar1 = pBVar3->flags & 0x40;
    }
    else
    {
      if (iVar2 < 0x74)
      {
        if (iVar2 == 0x3c)
        {
          if ((pBVar3->flags & 0x800U) == 0)
          {
            return 0;
          }
          pBVar3->flags = pBVar3->flags & 0xf7ff;
          return 1;
        }
        if (iVar2 != 0x6a)
        {
          return 0;
        }
        if ((pBVar3->flags & 0x400U) == 0)
        {
          return 0;
        }
        pBVar3->flags = pBVar3->flags & 0xfbff;
        return 1;
      }
      if (iVar2 == 0x7d)
      {
        return 0;
      }
      if (iVar2 != 0x95)
      {
        return 0;
      }
      uVar1 = pBVar3->flags & 0x20;
    }
  }
  return (uint)(uVar1 != 0);
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_DoTGroupAction(struct TGroupObject *terrainGroup /*$s1*/, struct StackType *operand2 /*$a0*/)
// line 4546, offset 0x80064f30
/* begin block 1 */
// Start line: 4547
// Start offset: 0x80064F30
// Variables:
// 		long trueValue; // stack offset -20
// 		long number; // $v0
// 		long error; // stack offset -24
// 		long result; // $s2

/* begin block 1.1 */
// Start line: 4558
// Start offset: 0x80064F64
// Variables:
// 		struct BSPTree *bspTree; // $s0

/* begin block 1.1.1 */
// Start line: 4566
// Start offset: 0x80065010
// Variables:
// 		struct WaterLevelProcess *curWater; // $a0
/* end block 1.1.1 */
// End offset: 0x8006509C
// End Line: 4582

/* begin block 1.1.2 */
// Start line: 4590
// Start offset: 0x800650B0
// Variables:
// 		long offsetz; // $a0
/* end block 1.1.2 */
// End offset: 0x80065134
// End Line: 4603
/* end block 1.1 */
// End offset: 0x8006521C
// End Line: 4673
/* end block 1 */
// End offset: 0x8006521C
// End Line: 4675

/* begin block 2 */
// Start line: 9745
/* end block 2 */
// End Line: 9746

long EVENT_DoTGroupAction(TGroupObject *terrainGroup, StackType *operand2)

{
  short sVar1;
  ushort uVar2;
  WaterLevelProcess *pWVar3;
  int iVar4;
  Level *pLVar5;
  _Terrain *p_Var6;
  int iVar7;
  BSPTree *pBVar8;
  long lStack24;
  uint local_14;

  local_14 = 1;
  if (terrainGroup->attribute == -1)
  {
    return 0;
  }
  pBVar8 = terrainGroup->bspTree;
  EVENT_ParseOperand2(operand2, &lStack24, (long *)&local_14);
  iVar4 = terrainGroup->attribute;
  if (iVar4 != 0x2e)
  {
    if (iVar4 < 0x2f)
    {
      if (iVar4 == 0xb)
      {
        local_14 = local_14 ^ 1;
      }
      else
      {
        if (0xb < iVar4)
        {
          if (iVar4 != 0x2c)
          {
            if (iVar4 != 0x2d)
            {
              return 0;
            }
          LAB_800650b0:
            iVar4 = (int)(pBVar8->localOffset).z;
            iVar7 = (int)terrainGroup->arg[0] - iVar4;
            if (iVar4 == (int)terrainGroup->arg[0])
            {
              return 1;
            }
            (pBVar8->globalOffset).z = (pBVar8->globalOffset).z + (short)iVar7;
            (pBVar8->localOffset).z = terrainGroup->arg[0];
            if (terrainGroup->attribute == 0x2f)
            {
              pLVar5 = terrainGroup->streamUnit->level;
              pLVar5->waterZLevel = pLVar5->waterZLevel + iVar7;
              p_Var6 = terrainGroup->streamUnit->level->terrain;
              p_Var6->UnitChangeFlags = p_Var6->UnitChangeFlags | 3;
              return 1;
            }
            return 1;
          }
          goto LAB_80065010;
        }
        if (iVar4 != 10)
        {
          return 0;
        }
      }
      if (local_14 == 0)
      {
        uVar2 = pBVar8->flags & 0xfffc;
      }
      else
      {
        uVar2 = pBVar8->flags | 3;
      }
    }
    else
    {
      if (iVar4 == 0x35)
      {
        if (local_14 == 0)
        {
          uVar2 = pBVar8->flags & 0xfffd;
        }
        else
        {
          uVar2 = pBVar8->flags | 2;
        }
      }
      else
      {
        if (iVar4 < 0x36)
        {
          if (iVar4 == 0x2f)
            goto LAB_800650b0;
          if (iVar4 != 0x34)
          {
            return 0;
          }
          if (local_14 == 0)
          {
            uVar2 = pBVar8->flags & 0xfffe;
          }
          else
          {
            uVar2 = pBVar8->flags | 1;
          }
        }
        else
        {
          if (iVar4 == 0x73)
          {
            if (local_14 == 0)
            {
              uVar2 = pBVar8->flags & 0xffbf;
            }
            else
            {
              uVar2 = pBVar8->flags | 0x40;
            }
          }
          else
          {
            if (iVar4 != 0x95)
            {
              return 0;
            }
            if (local_14 == 0)
            {
              uVar2 = pBVar8->flags & 0xffdf;
            }
            else
            {
              uVar2 = pBVar8->flags | 0x20;
            }
          }
        }
      }
    }
    pBVar8->flags = uVar2;
    return 1;
  }
LAB_80065010:
  pWVar3 = EVENT_GetNextTerrainMove();
  if (pWVar3 == (WaterLevelProcess *)0x0)
  {
    return 0;
  }
  pWVar3->bspTree = pBVar8;
  pWVar3->streamUnit = terrainGroup->streamUnit;
  pWVar3->oldWaterZ = *(short *)&terrainGroup->streamUnit->level->waterZLevel;
  pWVar3->oldGlobalOffset = (pBVar8->globalOffset).z;
  pWVar3->zValueFrom = (pBVar8->localOffset).z;
  pWVar3->zValueTo = terrainGroup->arg[0];
  sVar1 = terrainGroup->arg[1];
  WaterInUse = 1;
  pWVar3->curStep = 0;
  pWVar3->flags = 1;
  pWVar3->maxSteps = (int)sVar1 << 0xc;
  if (terrainGroup->attribute == 0x2e)
  {
    pWVar3->flags = pWVar3->flags | 2;
    return 0;
  }
  return 0;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_DoCameraAction(struct CameraObject *cameraObject /*$s2*/, struct StackType *operand2 /*$s0*/, short *codeStream /*$a2*/)
// line 4678, offset 0x80065238
/* begin block 1 */
// Start line: 4679
// Start offset: 0x80065238
// Variables:
// 		long trueValue; // stack offset -20
// 		long number; // $a1
// 		long error; // stack offset -24
// 		struct Camera *camera; // $s1

/* begin block 1.1 */
// Start line: 4712
// Start offset: 0x800652D4
// Variables:
// 		struct Intro *intro; // $a0
/* end block 1.1 */
// End offset: 0x8006533C
// End Line: 4742

/* begin block 1.2 */
// Start line: 4751
// Start offset: 0x80065358
// Variables:
// 		long angle; // $a1
/* end block 1.2 */
// End offset: 0x8006541C
// End Line: 4772

/* begin block 1.3 */
// Start line: 4784
// Start offset: 0x80065448
// Variables:
// 		long angle; // $v0
/* end block 1.3 */
// End offset: 0x80065498
// End Line: 4794

/* begin block 1.4 */
// Start line: 4808
// Start offset: 0x800654B8
// Variables:
// 		long angle; // $v0
/* end block 1.4 */
// End offset: 0x800654F8
// End Line: 4817

/* begin block 1.5 */
// Start line: 4845
// Start offset: 0x80065570
/* end block 1.5 */
// End offset: 0x80065570
// End Line: 4849
/* end block 1 */
// End offset: 0x8006559C
// End Line: 4879

/* begin block 2 */
// Start line: 10019
/* end block 2 */
// End Line: 10020

long EVENT_DoCameraAction(CameraObject *cameraObject, StackType *operand2, short *codeStream)

{
  long dist;
  int iVar1;
  int frames;
  Camera *camera;
  int iVar2;
  int local_18;
  long local_14;

  local_14 = 1;
  local_18 = 1;
  camera = cameraObject->camera;
  if (cameraObject->attribute == -1)
  {
    return 0;
  }
  dist = EVENT_ParseOperand2(operand2, &local_18, &local_14);
  switch (cameraObject->attribute)
  {
  case 9:
  case 0x46:
    if (local_18 == 0)
    {
      if (cameraObject->attribute == 0x46)
      {
        iVar1 = -dist % 0x168;
        if (iVar1 < 0)
        {
          iVar1 = iVar1 + 0x168;
        }
        CAMERA_Adjust_tilt(cameraObject->camera, (iVar1 * 0x1000) / 0x168);
      }
      else
      {
        iVar1 = -dist % 0x168;
        if (iVar1 < 0)
        {
          iVar1 = iVar1 + 0x168;
        }
        CAMERA_Adjust_rotation(cameraObject->camera, (iVar1 * 0x1000) / 0x168);
      }
    }
    break;
  case 0x10:
    if (local_18 == 0)
    {
      CAMERA_SetMode(camera, dist);
    }
    break;
  case 0x43:
    if (local_18 == 0)
    {
      CAMERA_SetSmoothValue(camera, dist);
    }
    break;
  case 0x44:
  case 0x45:
    iVar1 = 0;
    if (operand2 != (StackType *)0x0)
    {
      if (operand2->id == 2)
      {
        iVar1 = *(int *)(*(int *)operand2->data + 0x20);
      }
      else
      {
        if (operand2->id == 4)
        {
          iVar1 = *(int *)operand2->data;
        }
      }
    }
    if (iVar1 != 0)
    {
      if (cameraObject->attribute == 0x44)
      {
        camera->Spline00 = *(MultiSpline **)(iVar1 + 0x38);
      }
      else
      {
        camera->Spline01 = *(MultiSpline **)(iVar1 + 0x38);
      }
    }
    break;
  case 0x47:
    if (local_18 == 0)
    {
      CAMERA_Adjust_distance(cameraObject->camera, dist);
    }
    break;
  case 0x48:
    CAMERA_RestoreMode(camera);
    break;
  case 0x49:
    if ((operand2 != (StackType *)0x0) && (operand2->id == 2))
    {
      CAMERA_SetInstanceFocus(camera, *(_Instance **)operand2->data);
    }
    break;
  case 0x68:
    if (local_18 != 0)
    {
      return 0;
    }
    iVar1 = dist % 0x168;
    if (iVar1 < 0)
    {
      iVar1 = iVar1 + 0x168;
    }
    iVar1 = iVar1 << 0xc;
    iVar2 = (int)((ulonglong)((longlong)iVar1 * -0x49f49f49) >> 0x20);
    frames = 0;
    goto LAB_80065504;
  case 0x69:
    if (local_18 != 0)
    {
      return 0;
    }
    iVar1 = dist % 0x168;
    if (iVar1 < 0)
    {
      iVar1 = iVar1 + 0x168;
    }
    iVar1 = iVar1 << 0xc;
    frames = cameraObject->frames;
    iVar2 = (int)((ulonglong)((longlong)iVar1 * -0x49f49f49) >> 0x20);
  LAB_80065504:
    CAMERA_Adjust_roll((iVar2 + iVar1 >> 8) - (iVar1 >> 0x1f), frames);
  }
  return 0;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_DoObjectSoundAction(struct SoundObject *soundObject /*$s0*/, struct StackType *operand2 /*$a0*/)
// line 4882, offset 0x800655b8
/* begin block 1 */
// Start line: 4883
// Start offset: 0x800655B8
// Variables:
// 		long trueValue; // stack offset -20
// 		long number; // $v1
// 		long error; // stack offset -24
// 		long result; // $s2
// 		struct _Instance *instance; // $a3

/* begin block 1.1 */
// Start line: 4898
// Start offset: 0x800655F0
// Variables:
// 		struct SoundInstance *soundInstance; // $s1
/* end block 1.1 */
// End offset: 0x800656D0
// End Line: 4936
/* end block 1 */
// End offset: 0x800656D0
// End Line: 4937

/* begin block 2 */
// Start line: 10435
/* end block 2 */
// End Line: 10436

long EVENT_DoObjectSoundAction(SoundObject *soundObject, StackType *operand2)

{
  short sVar1;
  SoundInstance *soundInst;
  long lVar2;
  long lStack24;
  uint local_14;

  lVar2 = 1;
  local_14 = 1;
  if (soundObject->attribute != -1)
  {
    soundInst = (SoundInstance *)(soundObject->data + soundObject->soundNumber * 3 + 0x48);
    EVENT_ParseOperand2(operand2, &lStack24, (long *)&local_14);
    sVar1 = soundObject->attribute;
    if (sVar1 == 0x7f)
    {
      SOUND_SetInstanceSoundVolume(soundInst, soundObject->value, soundObject->duration);
      lVar2 = 1;
    }
    else
    {
      if (sVar1 < 0x80)
      {
        if (sVar1 != 0xd)
        {
          if (sVar1 != 0xe)
          {
            return 0;
          }
          local_14 = (uint)(local_14 == 0);
        }
        if (local_14 == 0)
        {
          SOUND_StopInstanceSound(soundInst);
          lVar2 = 1;
        }
        else
        {
          SOUND_StartInstanceSound(soundInst);
          lVar2 = 1;
        }
      }
      else
      {
        if (sVar1 == 0x80)
        {
          SOUND_SetInstanceSoundPitch(soundInst, soundObject->value, soundObject->duration);
          lVar2 = 1;
        }
        else
        {
          lVar2 = 1;
          if (0x83 < sVar1)
          {
            lVar2 = 0;
          }
        }
      }
    }
  }
  return lVar2;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_DoSoundMarkerAction(struct SoundObject *soundObject /*$s0*/, struct StackType *operand2 /*$a0*/)
// line 4940, offset 0x800656ec
/* begin block 1 */
// Start line: 4941
// Start offset: 0x800656EC
// Variables:
// 		long trueValue; // stack offset -20
// 		long number; // $v1
// 		long error; // stack offset -24
// 		long result; // $s2
// 		struct _SFXMkr *sfxMarker; // $a3

/* begin block 1.1 */
// Start line: 4956
// Start offset: 0x80065724
// Variables:
// 		struct SoundInstance *soundInstance; // $s1
/* end block 1.1 */
// End offset: 0x80065804
// End Line: 4994
/* end block 1 */
// End offset: 0x80065804
// End Line: 4995

/* begin block 2 */
// Start line: 10560
/* end block 2 */
// End Line: 10561

long EVENT_DoSoundMarkerAction(SoundObject *soundObject, StackType *operand2)

{
  short sVar1;
  SoundInstance *soundInst;
  long lVar2;
  long lStack24;
  uint local_14;

  lVar2 = 1;
  local_14 = 1;
  if (soundObject->attribute != -1)
  {
    soundInst = (SoundInstance *)(soundObject->data + soundObject->soundNumber * 3 + 8);
    EVENT_ParseOperand2(operand2, &lStack24, (long *)&local_14);
    sVar1 = soundObject->attribute;
    if (sVar1 == 0x7f)
    {
      SOUND_SetInstanceSoundVolume(soundInst, soundObject->value, soundObject->duration);
      lVar2 = 1;
    }
    else
    {
      if (sVar1 < 0x80)
      {
        if (sVar1 != 0xd)
        {
          if (sVar1 != 0xe)
          {
            return 0;
          }
          local_14 = (uint)(local_14 == 0);
        }
        if (local_14 == 0)
        {
          SOUND_StopInstanceSound(soundInst);
          lVar2 = 1;
        }
        else
        {
          SOUND_StartInstanceSound(soundInst);
          lVar2 = 1;
        }
      }
      else
      {
        if (sVar1 == 0x80)
        {
          SOUND_SetInstanceSoundPitch(soundInst, soundObject->value, soundObject->duration);
          lVar2 = 1;
        }
        else
        {
          lVar2 = 1;
          if (0x83 < sVar1)
          {
            lVar2 = 0;
          }
        }
      }
    }
  }
  return lVar2;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_GetSoundValue(struct SoundObject *soundObject /*$a0*/)
// line 4998, offset 0x80065820
/* begin block 1 */
// Start line: 5000
// Start offset: 0x80065820
/* end block 1 */
// End offset: 0x80065820
// End Line: 5032

/* begin block 2 */
// Start line: 10685
/* end block 2 */
// End Line: 10686

/* begin block 3 */
// Start line: 10686
/* end block 3 */
// End Line: 10687

/* begin block 4 */
// Start line: 10718
/* end block 4 */
// End Line: 10719

/* begin block 5 */
// Start line: 10719
/* end block 5 */
// End Line: 10720

long EVENT_GetSoundValue(SoundObject *soundObject)

{
  return 0;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_DoAreaAction(struct AreaObject *areaObject /*$s1*/, struct StackType *operand2 /*$a0*/)
// line 5035, offset 0x80065828
/* begin block 1 */
// Start line: 5036
// Start offset: 0x80065828
// Variables:
// 		long trueValue; // stack offset -20
// 		long number; // $v1
// 		long error; // stack offset -24
// 		struct _StreamUnit *streamUnit; // $s0
/* end block 1 */
// End offset: 0x800658BC
// End Line: 5079

/* begin block 2 */
// Start line: 10759
/* end block 2 */
// End Line: 10760

long EVENT_DoAreaAction(AreaObject *areaObject, StackType *operand2)

{
  long lVar1;
  ushort uVar2;
  _StreamUnit *p_Var3;
  int local_18;
  long local_14;

  local_14 = 1;
  p_Var3 = areaObject->streamUnit;
  if (areaObject->attribute != -1)
  {
    lVar1 = EVENT_ParseOperand2(operand2, &local_18, &local_14);
    uVar2 = (ushort)lVar1;
    if (areaObject->attribute == 0x70)
    {
      if (local_18 == 0)
      {
        p_Var3->TargetFogFar = uVar2;
        p_Var3->level->fogFar = uVar2;
      }
    }
    else
    {
      if ((areaObject->attribute == 0x71) && (local_18 == 0))
      {
        p_Var3->TargetFogNear = uVar2;
        p_Var3->level->fogNear = uVar2;
      }
    }
  }
  return 0;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_DoIntroAction(struct IntroObject *introObject /*$s1*/, struct StackType *operand2 /*$a0*/)
// line 5082, offset 0x800658d4
/* begin block 1 */
// Start line: 5083
// Start offset: 0x800658D4
// Variables:
// 		long trueValue; // stack offset -20
// 		long number; // $a2
// 		long error; // stack offset -24
// 		long result; // $s2

/* begin block 1.1 */
// Start line: 5094
// Start offset: 0x80065908
// Variables:
// 		struct Intro *intro; // $s0

/* begin block 1.1.1 */
// Start line: 5144
// Start offset: 0x80065A3C
// Variables:
// 		int i; // $a2
// 		int j; // $v1
// 		int id; // $a1

/* begin block 1.1.1.1 */
// Start line: 5147
// Start offset: 0x80065A4C

/* begin block 1.1.1.1.1 */
// Start line: 5150
// Start offset: 0x80065A5C
// Variables:
// 		struct Intro *intro1; // $v0
/* end block 1.1.1.1.1 */
// End offset: 0x80065A94
// End Line: 5159
/* end block 1.1.1.1 */
// End offset: 0x80065A94
// End Line: 5160
/* end block 1.1.1 */
// End offset: 0x80065AC8
// End Line: 5163
/* end block 1.1 */
// End offset: 0x80065AC8
// End Line: 5170
/* end block 1 */
// End offset: 0x80065AC8
// End Line: 5172

/* begin block 2 */
// Start line: 10861
/* end block 2 */
// End Line: 10862

long EVENT_DoIntroAction(IntroObject *introObject, StackType *operand2)

{
  long lVar1;
  uint uVar2;
  Intro *pIVar3;
  _Instance *p_Var4;
  long lVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  Intro *intro;
  long lVar11;
  long lStack24;
  uint local_14;

  lVar11 = 0;
  local_14 = 1;
  lVar5 = lVar11;
  if (introObject->attribute != -1)
  {
    intro = introObject->intro;
    lVar1 = EVENT_ParseOperand2(operand2, &lStack24, (long *)&local_14);
    iVar8 = introObject->attribute;
    if (iVar8 != 0x14)
    {
      if (iVar8 < 0x15)
      {
        if (iVar8 != 10)
        {
          if (iVar8 < 0xb)
          {
            if (iVar8 != 4)
            {
              return 0;
            }
            if (lVar1 != 0)
            {
              return 0;
            }
            SAVE_SetDeadDeadBit(intro->UniqueID, 0);
            return 0;
          }
          if (iVar8 != 0xb)
          {
            return 0;
          }
          local_14 = local_14 ^ 1;
        }
        uVar6 = 0xfffffff7;
        if (local_14 == 0)
        {
          uVar2 = intro->flags;
          uVar6 = 0xffffff7f;
        }
        else
        {
          uVar2 = intro->flags | 0x80;
        }
        intro->flags = uVar2 & uVar6;
        lVar5 = 1;
      }
      else
      {
        if (iVar8 == 0x3e)
        {
          uVar10 = 0;
          iVar8 = 0;
          puVar9 = &StreamTracker;
          do
          {
            if (*(short *)(puVar9 + 1) == 2)
            {
              iVar7 = *(int *)(puVar9[2] + 0x78);
              pIVar3 = *(Intro **)(puVar9[2] + 0x7c);
              while (iVar7 != 0)
              {
                if (pIVar3 == intro)
                {
                  uVar10 = *puVar9;
                  break;
                }
                iVar7 = iVar7 + -1;
                pIVar3 = pIVar3 + 1;
              }
            }
            puVar9 = puVar9 + 0x10;
            iVar8 = iVar8 + 1;
          } while (iVar8 < 0x10);
          p_Var4 = INSTANCE_IntroduceInstance(intro, (short)uVar10);
          lVar5 = 0;
          if (p_Var4 == (_Instance *)0x0)
          {
            EventAbortLine = 1;
            lVar5 = lVar11;
          }
        }
        else
        {
          lVar5 = 0;
          if ((0x3e < iVar8) && (lVar5 = 0, iVar8 == 0x8a))
          {
            if (local_14 == 0)
            {
              intro->flags = intro->flags & 0xfffffbff;
              lVar5 = lVar11;
            }
            else
            {
              intro->flags = intro->flags | 0x400;
              lVar5 = lVar11;
            }
          }
        }
      }
    }
  }
  return lVar5;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_DoStackOperationEquals(struct _PCodeStack *stack /*$a2*/, short *codeStream /*$a3*/)
// line 5189, offset 0x80065ae4
/* begin block 1 */
// Start line: 5190
// Start offset: 0x80065AE4
// Variables:
// 		struct StackType operand1; // stack offset -88
// 		struct StackType operand2; // stack offset -48
/* end block 1 */
// End offset: 0x80065BA8
// End Line: 5204

/* begin block 2 */
// Start line: 10378
/* end block 2 */
// End Line: 10379

void EVENT_DoStackOperationEquals(_PCodeStack *stack, short *codeStream)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long local_58[10];
  long local_30[10];

  plVar3 = (long *)local_30;
  iVar1 = stack->topOfStack + -1;
  plVar2 = &stack->topOfStack + iVar1 * 9 + 1;
  stack->topOfStack = iVar1;
  do
  {
    lVar4 = plVar2[1];
    lVar5 = plVar2[2];
    lVar6 = plVar2[3];
    *plVar3 = *plVar2;
    plVar3[1] = lVar4;
    plVar3[2] = lVar5;
    plVar3[3] = lVar6;
    plVar2 = plVar2 + 4;
    plVar3 = plVar3 + 4;
  } while (plVar2 != &stack->topOfStack + iVar1 * 9 + 9);
  *plVar3 = *plVar2;
  plVar3 = (long *)local_58;
  iVar1 = stack->topOfStack + -1;
  plVar2 = &stack->topOfStack + iVar1 * 9 + 1;
  stack->topOfStack = iVar1;
  do
  {
    lVar4 = plVar2[1];
    lVar5 = plVar2[2];
    lVar6 = plVar2[3];
    *plVar3 = *plVar2;
    plVar3[1] = lVar4;
    plVar3[2] = lVar5;
    plVar3[3] = lVar6;
    plVar2 = plVar2 + 4;
    plVar3 = plVar3 + 4;
  } while (plVar2 != &stack->topOfStack + iVar1 * 9 + 9);
  *plVar3 = *plVar2;
  EVENT_ExecuteActionCommand((StackType *)local_58, (StackType *)local_30, stack, codeStream);
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_CompareVector3d(struct Vector3d *vector1 /*$a0*/, struct Vector3d *vector2 /*$a1*/)
// line 5209, offset 0x80065bd0
/* begin block 1 */
// Start line: 5211
// Start offset: 0x80065BD0
// Variables:
// 		long retValue; // $t2

/* begin block 1.1 */
// Start line: 5240
// Start offset: 0x80065C88
// Variables:
// 		long dist; // $v0
/* end block 1.1 */
// End offset: 0x80065D08
// End Line: 5250

/* begin block 1.2 */
// Start line: 5256
// Start offset: 0x80065D10
// Variables:
// 		long dist; // $v0
/* end block 1.2 */
// End offset: 0x80065D80
// End Line: 5266
/* end block 1 */
// End offset: 0x80065D80
// End Line: 5270

/* begin block 2 */
// Start line: 11134
/* end block 2 */
// End Line: 11135

/* begin block 3 */
// Start line: 11135
/* end block 3 */
// End Line: 11136

/* begin block 4 */
// Start line: 11137
/* end block 4 */
// End Line: 11138

long EVENT_CompareVector3d(Vector3d *vector1, Vector3d *vector2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;

  if (vector1->streamUnitID != vector2->streamUnitID)
  {
    return 0;
  }
  iVar4 = (int)vector1->errory;
  if (iVar4 != -1)
  {
    iVar3 = (int)vector1->errorz;
    if (iVar3 != -1)
    {
      if ((int)vector2->vx < (int)vector1->vx - (int)vector1->errorx)
      {
        return 0;
      }
      if ((int)vector1->vx + (int)vector1->errorx < (int)vector2->vx)
      {
        return 0;
      }
      if ((int)vector2->vy < vector1->vy - iVar4)
      {
        return 0;
      }
      if ((int)vector2->vy <= vector1->vy + iVar4)
      {
        if (vector1->vz - iVar3 <= (int)vector2->vz)
        {
          return (uint)(vector1->vz + iVar3 < (int)vector2->vz) ^ 1;
        }
        return 0;
      }
      return 0;
    }
    if (iVar4 != -1)
    {
      iVar3 = (int)vector2->vx - (int)vector1->vx;
      iVar2 = (int)vector2->vy - (int)vector1->vy;
      if ((int)vector1->errorx * (int)vector1->errorx <= iVar3 * iVar3 + iVar2 * iVar2)
      {
        return 0;
      }
      iVar3 = (int)vector2->vz - (int)vector1->vz;
      if (-1 < iVar3)
      {
        if (iVar3 < iVar4)
        {
          return 1;
        }
        return 0;
      }
      bVar1 = (int)vector1->vz - (int)vector2->vz < iVar4;
      goto LAB_80065d74;
    }
  }
  iVar4 = (int)vector2->vx - (int)vector1->vx;
  iVar3 = (int)vector2->vy - (int)vector1->vy;
  iVar2 = (int)vector2->vz - (int)vector1->vz;
  bVar1 = iVar4 * iVar4 + iVar3 * iVar3 + iVar2 * iVar2 <
          (int)vector1->errorx * (int)vector1->errorx;
LAB_80065d74:
  if (bVar1)
  {
    return 1;
  }
  return 0;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_CompareRotationVectors(struct Rotation3d *rot1 /*$a0*/, struct Rotation3d *rot2 /*$s1*/, long trueValue /*$s6*/)
// line 5279, offset 0x80065d8c
/* begin block 1 */
// Start line: 5280
// Start offset: 0x80065D8C
// Variables:
// 		struct MATRIX matrix1; // stack offset -104
// 		struct MATRIX matrix2; // stack offset -72
// 		long result; // $s2
// 		long c1; // $v1
// 		long attribute; // $s0
// 		struct _SVector axis; // stack offset -40
// 		long doSoft; // $s4
/* end block 1 */
// End offset: 0x80065F58
// End Line: 5377

/* begin block 2 */
// Start line: 11280
/* end block 2 */
// End Line: 11281

long EVENT_CompareRotationVectors(Rotation3d *rot1, Rotation3d *rot2, long trueValue)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  MATRIX MStack104;
  MATRIX MStack72;
  _SVector local_28;

  uVar4 = (uint)(trueValue == 0);
  iVar3 = rot1->attribute;
  bVar1 = false;
  if (iVar3 == -1)
  {
    iVar3 = rot2->attribute;
  }
  RotMatrixZYX((ushort *)rot1, (uint *)&MStack104);
  RotMatrixZYX((ushort *)rot2, (uint *)&MStack72);
  if (iVar3 == 8)
  {
  LAB_80065eec:
    local_28.x = 0;
    local_28.y = 0;
    local_28.z = 0x1000;
    goto LAB_80065f00;
  }
  if (iVar3 < 9)
  {
    if (iVar3 == 6)
    {
    LAB_80065ebc:
      local_28.x = 0x1000;
      local_28.y = 0;
      local_28.z = 0;
      goto LAB_80065f00;
    }
    if (iVar3 < 7)
    {
      if (iVar3 == -1)
      {
        local_28.x = 0x1000;
        local_28.y = 0;
        local_28.z = 0;
        iVar2 = PHYSOBS_CheckObjectAxisAlignment(&MStack104, &MStack72, &local_28);
        if (iVar2 - 0xf80U < 0x101)
        {
          local_28.x = 0;
          local_28.y = 0x1000;
          local_28.z = 0;
          iVar2 = PHYSOBS_CheckObjectAxisAlignment(&MStack104, &MStack72, &local_28);
          if (iVar2 - 0xf80U < 0x101)
          {
            uVar4 = trueValue;
          }
        }
      }
      goto LAB_80065f00;
    }
  }
  else
  {
    if (iVar3 != 0x61)
    {
      if (0x61 < iVar3)
      {
        if (iVar3 != 0x62)
          goto LAB_80065f00;
        bVar1 = true;
        goto LAB_80065eec;
      }
      if (iVar3 != 0x60)
        goto LAB_80065f00;
      bVar1 = true;
      goto LAB_80065ebc;
    }
    bVar1 = true;
  }
  local_28.x = 0;
  local_28.y = 0x1000;
  local_28.z = 0;
LAB_80065f00:
  if (iVar3 != -1)
  {
    iVar3 = PHYSOBS_CheckObjectAxisAlignment(&MStack104, &MStack72, &local_28);
    if (bVar1)
    {
      uVar4 = trueValue;
      if ((0x100 < iVar3 - 0xf80U) && (&UNK_00000100 < &DAT_00001080 + iVar3))
      {
        uVar4 = (uint)(trueValue == 0);
      }
    }
    else
    {
      uVar4 = trueValue;
      if (0x100 < iVar3 - 0xf80U)
      {
        uVar4 = (uint)(trueValue == 0);
      }
    }
  }
  return uVar4;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_CompareListWithOperation(struct _PCodeStack *stack /*$s7*/, struct ListObject *listObject /*$s3*/, struct StackType *operand2 /*stack 8*/, long operation /*$fp*/)
// line 5394, offset 0x80065f84
/* begin block 1 */
// Start line: 5395
// Start offset: 0x80065F84
// Variables:
// 		long retValue; // $s4
// 		long d; // $s0
// 		struct StackType operand1; // stack offset -96
// 		char objectName[16]; // stack offset -56
// 		char *temp; // $v0
// 		struct _Instance *instance; // $s2
// 		long areaID; // $s5
/* end block 1 */
// End offset: 0x80066144
// End Line: 5460

/* begin block 2 */
// Start line: 11514
/* end block 2 */
// End Line: 11515

/* begin block 3 */
// Start line: 11521
/* end block 3 */
// End Line: 11522

long EVENT_CompareListWithOperation(_PCodeStack *stack, ListObject *listObject, StackType *operand2, long operation)

{
  char acStack56[16];

  if (CurrentEventLine < 0x14)
  {
    *(undefined4 *)(&fontTracker.font_buffer[0x19].y + CurrentEventLine * 2) = 0;
  }
  /* WARNING: Subroutine does not return */
  strcpy(acStack56, listObject->eventInstance->objectName);
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_CompareSubListWithOperation(struct _PCodeStack *stack /*$s6*/, struct SubListObject *subListObject /*$s3*/, struct StackType *operand2 /*$s7*/, long operation /*$fp*/)
// line 5464, offset 0x80066178
/* begin block 1 */
// Start line: 5465
// Start offset: 0x80066178
// Variables:
// 		long i; // $s4
// 		long retValue; // $s5
// 		long d; // $s0
// 		struct StackType operand1; // stack offset -80
/* end block 1 */
// End offset: 0x800662E0
// End Line: 5498

/* begin block 2 */
// Start line: 11665
/* end block 2 */
// End Line: 11666

/* begin block 3 */
// Start line: 11669
/* end block 3 */
// End Line: 11670

long EVENT_CompareSubListWithOperation(_PCodeStack *stack, SubListObject *subListObject, StackType *operand2, long operation)

{
  long lVar1;
  int *piVar2;
  int iVar3;
  SubListObject *pSVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  long local_50;
  undefined4 local_4c;
  undefined4 local_48;

  lVar7 = 0;
  if (CurrentEventLine < 0x14)
  {
    *(undefined4 *)(&fontTracker.font_buffer[0x19].y + CurrentEventLine * 2) = 0;
  }
  iVar6 = 0;
  if (0 < subListObject->numberOfInstances)
  {
    iVar5 = 0;
    do
    {
      local_50 = 2;
      local_4c = *(undefined4 *)(iVar5 + (int)subListObject->instanceList);
      local_48 = 0xffffffff;
      iVar3 = 0;
      pSVar4 = subListObject;
      if (0 < subListObject->numberOfAttributes)
      {
        do
        {
          EVENT_TransformOperand((StackType *)&local_50, stack, pSVar4->attribute[0], (short *)0x0);
          iVar3 = iVar3 + 1;
          pSVar4 = (SubListObject *)&pSVar4->numberOfInstances;
        } while (iVar3 < subListObject->numberOfAttributes);
      }
      lVar1 = EVENT_CompareOperandsWithOperation(stack, (StackType *)&local_50, operand2, operation);
      if (lVar1 != 0)
      {
        if (CurrentEventLine < 0x14)
        {
          piVar2 = (int *)(&fontTracker.font_buffer[0x19].y + CurrentEventLine * 2);
          iVar3 = *piVar2;
          if (iVar3 < 10)
          {
            *(undefined4 *)((int)fontTracker.font_buffer + iVar3 * 4 + CurrentEventLine * 0x28 + 0x188) =
                *(undefined4 *)(iVar5 + (int)subListObject->instanceList);
            *piVar2 = iVar3 + 1;
          }
        }
        lVar7 = 1;
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar6 < subListObject->numberOfInstances);
  }
  return lVar7;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_CompareOperandsWithOperation(struct _PCodeStack *stack /*$a0*/, struct StackType *operand1 /*$t0*/, struct StackType *operand2 /*$s3*/, long operation /*$s4*/)
// line 5501, offset 0x80066314
/* begin block 1 */
// Start line: 5502
// Start offset: 0x80066314
// Variables:
// 		long number; // $s1
// 		long number1; // $s0
// 		long number2; // $a0
// 		long error; // stack offset -32
// 		long trueValue; // $s2
// 		short flags1; // stack offset -28
// 		short flags2; // stack offset -26
/* end block 1 */
// End offset: 0x80066628
// End Line: 5707

/* begin block 2 */
// Start line: 11768
/* end block 2 */
// End Line: 11769

long EVENT_CompareOperandsWithOperation(_PCodeStack *stack, StackType *operand1, StackType *operand2, long operation)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  short z;
  uint uVar5;
  uint trueValue;
  long lStack32;
  ushort local_1c;
  ushort local_1a;

  uVar5 = 0;
  trueValue = 1;
  switch (operand1->id)
  {
  case 8:
    break;
  case 9:
    if (operand2->id != 9)
    {
      return 0;
    }
    if (operation == 2)
    {
      iVar3 = (uint) * (ushort *)operand1->data - (uint) * (ushort *)operand2->data;
      iVar4 = (uint) * (ushort *)(operand1->data + 2) - (uint) * (ushort *)(operand2->data + 2);
      z = *(short *)(operand1->data + 4) - *(short *)(operand2->data + 4);
    }
    else
    {
      if (2 < operation)
      {
        uVar5 = trueValue;
        if (operation != 10)
        {
          if (operation != 0xb)
          {
            return 0;
          }
          uVar5 = 0;
        }
        trueValue = EVENT_CompareVector3d((Vector3d *)operand1->data, (Vector3d *)operand2->data);
        goto LAB_800665a8;
      }
      if (operation != 1)
      {
        return 0;
      }
      iVar3 = (uint) * (ushort *)operand1->data + (uint) * (ushort *)operand2->data;
      iVar4 = (uint) * (ushort *)(operand1->data + 2) + (uint) * (ushort *)(operand2->data + 2);
      z = *(short *)(operand1->data + 4) + *(short *)(operand2->data + 4);
    }
    EVENT_Addvector3dToStack(stack, (short)((uint)(iVar3 * 0x10000) >> 0x10),
                             (short)((uint)(iVar4 * 0x10000) >> 0x10), z, 0);
    uVar5 = 0xffffffff;
    break;
  default:
    uVar1 = EVENT_GetScalerValueFromOperand(operand1, &lStack32, (short *)&local_1c);
    uVar2 = EVENT_GetScalerValueFromOperand(operand2, &lStack32, (short *)&local_1a);
    switch (operation)
    {
    case 1:
      uVar5 = uVar1 + uVar2;
      break;
    case 2:
      uVar5 = uVar1 - uVar2;
      break;
    case 3:
      uVar5 = uVar1 * uVar2;
      break;
    case 4:
      uVar5 = 0;
      if (uVar2 != 0)
      {
        uVar5 = (int)uVar1 / (int)uVar2;
      }
      break;
    case 5:
      uVar5 = (int)uVar1 % uVar2;
      if ((int)uVar5 < 0)
      {
        uVar5 = uVar5 + uVar2;
      }
      break;
    case 6:
    switchD_80066530_caseD_6:
      uVar5 = trueValue;
      trueValue = (uint)((int)uVar2 < (int)uVar1);
      goto LAB_800665a8;
    case 7:
    switchD_80066530_caseD_7:
      uVar5 = trueValue;
      trueValue = (uint)((int)uVar1 < (int)uVar2);
      goto LAB_800665a8;
    case 8:
      trueValue = 0;
      goto switchD_80066530_caseD_7;
    case 9:
      trueValue = 0;
      goto switchD_80066530_caseD_6;
    case 10:
    switchD_80066530_caseD_a:
      uVar5 = trueValue;
      if (((local_1c & 1) == 0) && ((local_1a & 1) == 0))
      {
        if (uVar1 != uVar2)
        {
          uVar5 = uVar5 ^ 1;
        }
      }
      else
      {
        if ((local_1c & 2) != 0)
        {
          uVar2 = 1 << (uVar2 & 0x1f);
        }
        if ((uVar1 & uVar2) != uVar2)
        {
          uVar5 = uVar5 ^ 1;
        }
      }
      break;
    case 0xb:
      trueValue = 0;
      goto switchD_80066530_caseD_a;
    case 0xc:
      uVar5 = (uint)((uVar1 & uVar2) != 0);
    }
    break;
  case 0xe:
    uVar5 = 0;
    if (operand2->id == 0xe)
    {
      if (operation != 10)
      {
        if (operation != 0xb)
        {
          return 0;
        }
        trueValue = 0;
      }
      uVar5 = EVENT_CompareRotationVectors((Rotation3d *)operand1->data, (Rotation3d *)operand2->data, trueValue);
    }
    break;
  case 0x12:
    trueValue = EVENT_CompareListWithOperation(stack, (ListObject *)operand1->data, operand2, operation);
    uVar5 = 1;
    goto LAB_800665a8;
  case 0x16:
    trueValue = EVENT_CompareSubListWithOperation(stack, (SubListObject *)operand1->data, operand2, operation);
    uVar5 = 1;
  LAB_800665a8:
    if (trueValue == 0)
    {
      uVar5 = uVar5 ^ 1;
    }
  }
  return uVar5;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_DoStackMathOperation(struct _PCodeStack *stack /*$s0*/, long operation /*$a3*/)
// line 5713, offset 0x8006664c
/* begin block 1 */
// Start line: 5714
// Start offset: 0x8006664C
// Variables:
// 		struct StackType operand1; // stack offset -128
// 		struct StackType operand2; // stack offset -88

/* begin block 1.1 */
// Start line: 5732
// Start offset: 0x80066738
// Variables:
// 		struct StackType holdOperand; // stack offset -48
/* end block 1.1 */
// End offset: 0x80066804
// End Line: 5737
/* end block 1 */
// End offset: 0x80066804
// End Line: 5739

/* begin block 2 */
// Start line: 12207
/* end block 2 */
// End Line: 12208

void EVENT_DoStackMathOperation(_PCodeStack *stack, long operation)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  long *plVar4;
  long *plVar5;
  long item;
  undefined4 uVar6;
  long lVar7;
  undefined4 uVar8;
  long lVar9;
  undefined4 uVar10;
  long local_80[8];
  undefined4 auStack96[2];
  int local_58;
  long local_54[7];
  undefined4 auStack56[2];
  undefined4 local_30[8];
  undefined4 auStack16[2];

  plVar5 = (long *)&local_58;
  iVar2 = stack->topOfStack + -1;
  plVar4 = &stack->topOfStack + iVar2 * 9 + 1;
  stack->topOfStack = iVar2;
  do
  {
    item = plVar4[1];
    lVar7 = plVar4[2];
    lVar9 = plVar4[3];
    *plVar5 = *plVar4;
    plVar5[1] = item;
    plVar5[2] = lVar7;
    plVar5[3] = lVar9;
    plVar4 = plVar4 + 4;
    plVar5 = plVar5 + 4;
  } while (plVar4 != &stack->topOfStack + iVar2 * 9 + 9);
  *plVar5 = *plVar4;
  plVar5 = (long *)local_80;
  iVar2 = stack->topOfStack + -1;
  plVar4 = &stack->topOfStack + iVar2 * 9 + 1;
  stack->topOfStack = iVar2;
  do
  {
    item = plVar4[1];
    lVar7 = plVar4[2];
    lVar9 = plVar4[3];
    *plVar5 = *plVar4;
    plVar5[1] = item;
    plVar5[2] = lVar7;
    plVar5[3] = lVar9;
    plVar4 = plVar4 + 4;
    plVar5 = plVar5 + 4;
  } while (plVar4 != &stack->topOfStack + iVar2 * 9 + 9);
  *plVar5 = *plVar4;
  if ((local_58 == 0x12) || (local_58 == 0x16))
  {
    puVar3 = local_30;
    puVar1 = (undefined4 *)local_80;
    do
    {
      uVar6 = puVar1[1];
      uVar8 = puVar1[2];
      uVar10 = puVar1[3];
      *puVar3 = *puVar1;
      puVar3[1] = uVar6;
      puVar3[2] = uVar8;
      puVar3[3] = uVar10;
      puVar1 = puVar1 + 4;
      puVar3 = puVar3 + 4;
    } while (puVar1 != auStack96);
    *puVar3 = *puVar1;
    puVar3 = (undefined4 *)local_80;
    puVar1 = (undefined4 *)&local_58;
    do
    {
      uVar6 = puVar1[1];
      uVar8 = puVar1[2];
      uVar10 = puVar1[3];
      *puVar3 = *puVar1;
      puVar3[1] = uVar6;
      puVar3[2] = uVar8;
      puVar3[3] = uVar10;
      puVar1 = puVar1 + 4;
      puVar3 = puVar3 + 4;
    } while (puVar1 != auStack56);
    *puVar3 = *puVar1;
    puVar3 = (undefined4 *)&local_58;
    puVar1 = local_30;
    do
    {
      uVar6 = puVar1[1];
      uVar8 = puVar1[2];
      uVar10 = puVar1[3];
      *puVar3 = *puVar1;
      puVar3[1] = uVar6;
      puVar3[2] = uVar8;
      puVar3[3] = uVar10;
      puVar1 = puVar1 + 4;
      puVar3 = puVar3 + 4;
    } while (puVar1 != auStack16);
    *puVar3 = *puVar1;
  }
  item = EVENT_CompareOperandsWithOperation(stack, (StackType *)local_80, (StackType *)&local_58, operation);
  EVENT_AddNumberToStack(stack, item, 0);
  return;
}

// decompiled code
// original method signature:
// short * /*$ra*/ EVENT_ParseOpcode(struct _PCodeStack *stack /*$s0*/, short *codeStream /*$s1*/, long *operateOnStack /*$a2*/)
// line 5743, offset 0x80066834
/* begin block 1 */
// Start line: 5744
// Start offset: 0x80066834
// Variables:
// 		short pcode; // $v0
/* end block 1 */
// End offset: 0x80066A90
// End Line: 5860

/* begin block 2 */
// Start line: 12271
/* end block 2 */
// End Line: 12272

short *EVENT_ParseOpcode(_PCodeStack *stack, short *codeStream, long *operateOnStack)

{
  ushort uVar1;
  long operation;
  short *codeStream_00;

  uVar1 = *codeStream;
  codeStream_00 = codeStream + 1;
  MoveCodeStreamExtra = 0;
  *operateOnStack = 0;
  switch ((int)(((uint)uVar1 - 1) * 0x10000) >> 0x10)
  {
  case 0:
    EVENT_ProcessEvents((EventPointers *)stack, (Level *)(int)*codeStream_00);
    codeStream_00 = codeStream + 2;
    break;
  case 1:
    EVENT_ModifyObjectToStackWithAttribute(stack, (int)*codeStream_00, codeStream_00);
    codeStream_00 = codeStream + 2;
    break;
  case 2:
    goto switchD_80066888_caseD_2;
  case 3:
    EVENT_DoStackMathOperation(stack, 10);
    break;
  case 4:
    EventAbortedPosition._0_4_ = codeStream_00;
    *operateOnStack = 1;
    break;
  case 6:
  case 8:
  case 9:
    codeStream_00 = (short *)0x0;
    break;
  case 0xb:
    EVENT_AddNumberToStack(stack, (int)*codeStream_00, 0);
    codeStream_00 = codeStream + 2;
    break;
  case 0xc:
    EVENT_DoStackMathOperation(stack, 1);
    break;
  case 0xd:
    EVENT_DoStackMathOperation(stack, 2);
    break;
  case 0xe:
    EVENT_DoStackMathOperation(stack, 3);
    break;
  case 0xf:
    EVENT_DoStackMathOperation(stack, 4);
    break;
  case 0x10:
    EVENT_StackDuplicate(stack);
    EVENT_AddNumberToStack(stack, 1, 0);
    operation = 1;
    goto LAB_800669c8;
  case 0x11:
    EVENT_StackDuplicate(stack);
    EVENT_AddNumberToStack(stack, 1, 0);
    operation = 2;
  LAB_800669c8:
    EVENT_DoStackMathOperation(stack, operation);
  switchD_80066888_caseD_2:
    EVENT_DoStackOperationEquals(stack, codeStream_00);
    break;
  case 0x12:
    EVENT_DoStackMathOperation(stack, 6);
    break;
  case 0x13:
    EVENT_DoStackMathOperation(stack, 8);
    break;
  case 0x14:
    EVENT_DoStackMathOperation(stack, 7);
    break;
  case 0x15:
    EVENT_DoStackMathOperation(stack, 9);
    break;
  case 0x16:
    EVENT_DoStackMathOperation(stack, 0xb);
    break;
  case 0x17:
    EVENT_DoStackMathOperation(stack, 5);
    break;
  case 0x1b:
    EVENT_AddGameObjectToStack(stack);
    break;
  case 0x1c:
    EVENT_AddPlayerObjectToStack(stack);
    break;
  case 0x1d:
    EVENT_AddSubListObjectToStack(stack, (int)*codeStream_00);
    codeStream_00 = codeStream + 2;
    break;
  case 0x1e:
    if (currentEventInstance._4_4_ != 0)
    {
      *(ushort *)(currentEventInstance._4_4_ + 2) = *(ushort *)(currentEventInstance._4_4_ + 2) | 2;
    }
    break;
  case 0x1f:
    EVENT_DoStackMathOperation(stack, 0xc);
  }
  return codeStream_00 + MoveCodeStreamExtra;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_GetIntroValue(struct IntroObject *introObject /*$a0*/)
// line 5864, offset 0x80066ab0
/* begin block 1 */
// Start line: 5866
// Start offset: 0x80066AB0
// Variables:
// 		long value; // $a1
// 		long trueValue; // $a2
/* end block 1 */
// End offset: 0x80066B3C
// End Line: 5943

/* begin block 2 */
// Start line: 12519
/* end block 2 */
// End Line: 12520

/* begin block 3 */
// Start line: 12520
/* end block 3 */
// End Line: 12521

/* begin block 4 */
// Start line: 12525
/* end block 4 */
// End Line: 12526

long EVENT_GetIntroValue(IntroObject *introObject)

{
  uint uVar1;
  uint uVar2;

  uVar2 = 0;
  uVar1 = 1;
  switch (introObject->attribute)
  {
  case 5:
  case 9:
  case 0xc:
  case 0x10:
  case 0x24:
  case 0x25:
  case 0x2b:
  case 0x7e:
  case 0x8f:
  case 0x90:
  case 0xa0:
    uVar2 = 0;
    break;
  case 0xb:
    uVar1 = 0;
  case 10:
    uVar2 = uVar1;
    uVar1 = introObject->intro->flags & 0x80;
    goto LAB_80066b28;
  case 0x14:
  case 0x15:
    uVar2 = 0xffffffff;
    break;
  case 0x92:
  case 0xa6:
    uVar2 = 1;
    uVar1 = introObject->intro->flags & 8;
  LAB_80066b28:
    if (uVar1 == 0)
    {
      uVar2 = uVar2 ^ 1;
    }
    break;
  case -1:
    uVar2 = 1;
  }
  return uVar2;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_DoSubListAction(struct SubListObject *subListObject /*$s3*/, struct StackType *operand2 /*$s5*/, struct _PCodeStack *stack /*$s4*/, short *codeStream /*$s6*/)
// line 5946, offset 0x80066b44
/* begin block 1 */
// Start line: 5947
// Start offset: 0x80066B44
// Variables:
// 		long i; // $s2
// 		long d; // $s0
// 		struct StackType operand1; // stack offset -72
/* end block 1 */
// End offset: 0x80066C14
// End Line: 5966

/* begin block 2 */
// Start line: 12691
/* end block 2 */
// End Line: 12692

void EVENT_DoSubListAction(SubListObject *subListObject, StackType *operand2, _PCodeStack *stack,
                           short *codeStream)

{
  int iVar1;
  SubListObject *pSVar2;
  int iVar3;
  long local_48;
  _Instance *local_44;
  undefined4 local_40;

  iVar3 = 0;
  if (0 < subListObject->numberOfInstances)
  {
    do
    {
      local_48 = 2;
      local_44 = subListObject->instanceList[iVar3];
      local_40 = 0xffffffff;
      iVar1 = 0;
      pSVar2 = subListObject;
      if (0 < subListObject->numberOfAttributes)
      {
        do
        {
          EVENT_TransformOperand((StackType *)&local_48, stack, pSVar2->attribute[0], (short *)0x0);
          iVar1 = iVar1 + 1;
          pSVar2 = (SubListObject *)&pSVar2->numberOfInstances;
        } while (iVar1 < subListObject->numberOfAttributes);
      }
      EVENT_ExecuteActionCommand((StackType *)&local_48, operand2, stack, codeStream);
      iVar3 = iVar3 + 1;
    } while (iVar3 < subListObject->numberOfInstances);
  }
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_GetInstanceValue(struct InstanceObject *instanceObject /*$a0*/)
// line 5969, offset 0x80066c3c
/* begin block 1 */
// Start line: 5970
// Start offset: 0x80066C3C
// Variables:
// 		long value; // $s0
// 		struct _Instance *instance; // $a0
/* end block 1 */
// End offset: 0x80066D9C
// End Line: 6104

/* begin block 2 */
// Start line: 12752
/* end block 2 */
// End Line: 12753

long EVENT_GetInstanceValue(InstanceObject *instanceObject)

{
  _Instance *Inst;
  int Query;
  uint uVar1;

  Inst = instanceObject->instance;
  uVar1 = 0;
  switch (instanceObject->attribute)
  {
  case 5:
  case 9:
  case 0xc:
  case 0x20:
  case 0x36:
  case 0x37:
  case 0x5e:
  case 0x5f:
  case 0x7e:
    uVar1 = 0;
    break;
  case 10:
  case 0x34:
    uVar1 = (uint)((Inst->flags & 0x800U) != 0);
    break;
  case 0xb:
    uVar1 = (uint)((Inst->flags & 0x800U) == 0);
    break;
  case 0x10:
    Query = 10;
    goto LAB_80066d68;
  case 0x14:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, 0xb);
  case 0x15:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, 0xb);
  case 0x24:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, 5);
  case 0x25:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, 5);
  case 0x26:
    Query = 0x1b;
    goto LAB_80066d68;
  case 0x27:
    Query = 0x1a;
  LAB_80066d68:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, Query);
  case 0x35:
    uVar1 = (uint)((Inst->flags2 & 0x20000000U) != 0);
    break;
  case 0x5b:
    uVar1 = (uint)Inst->lightGroup;
    break;
  case 0x5c:
    uVar1 = (uint)Inst->spectralLightGroup;
    break;
  case 0x67:
    uVar1 = (uint)((Inst->flags & 0x400000U) == 0);
    break;
  case 0x8f:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, 5);
  case 0x90:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst, 5);
  case -1:
    uVar1 = Inst->introUniqueID;
  }
  return uVar1;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_GetSplineFrameNumber(struct InstanceSpline *instanceSpline /*$s0*/)
// line 6107, offset 0x80066db4
/* begin block 1 */
// Start line: 6108
// Start offset: 0x80066DB4
/* end block 1 */
// End offset: 0x80066DB4
// End Line: 6108

/* begin block 2 */
// Start line: 13031
/* end block 2 */
// End Line: 13032

long EVENT_GetSplineFrameNumber(InstanceSpline *instanceSpline)

{
  SplineDef *splineDef;
  int iVar1;

  splineDef = SCRIPT_GetPosSplineDef(instanceSpline->instance, instanceSpline->spline, instanceSpline->isParent,
                                     instanceSpline->isClass);
  iVar1 = SCRIPT_GetSplineFrameNumber(instanceSpline->instance, splineDef);
  return iVar1;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_GetSplineValue(struct InstanceSpline *instanceSpline /*$a2*/)
// line 6120, offset 0x80066df8
/* begin block 1 */
// Start line: 6121
// Start offset: 0x80066DF8
// Variables:
// 		long value; // $a1
// 		struct _Instance *instance; // $a0

/* begin block 1.1 */
// Start line: 6170
// Start offset: 0x80066EA4
// Variables:
// 		struct MultiSpline *spline; // $v0
/* end block 1.1 */
// End offset: 0x80066EE4
// End Line: 6189
/* end block 1 */
// End offset: 0x80066EE4
// End Line: 6196

/* begin block 2 */
// Start line: 13057
/* end block 2 */
// End Line: 13058

long EVENT_GetSplineValue(InstanceSpline *instanceSpline)

{
  byte bVar1;
  short sVar2;
  Spline *pSVar3;
  _Instance *instance;
  uint uVar4;

  instance = instanceSpline->instance;
  uVar4 = 0;
  switch (instanceSpline->attribute)
  {
  case 0xd:
  case 0x29:
    uVar4 = (uint)((instance->flags & 0x2000000U) != 0);
    break;
  case 0xe:
    uVar4 = (uint)((instance->flags & 0x2000000U) == 0);
    break;
  case 0xf:
  case 0x28:
    uVar4 = EVENT_GetSplineFrameNumber(instanceSpline);
    break;
  case 0x10:
    pSVar3 = instanceSpline->spline->positional;
    if (pSVar3 == (Spline *)0x0)
    {
      return 0;
    }
    bVar1 = pSVar3->flags;
    uVar4 = (uint)bVar1 & 1;
    if ((bVar1 & 2) != 0)
    {
      uVar4 = 2;
    }
    if ((bVar1 & 4) == 0)
    {
      return uVar4;
    }
  case -1:
    uVar4 = 1;
    break;
  case 0x11:
    uVar4 = 1;
    if ((instance->flags & 0x1000000U) != 0)
    {
      uVar4 = 0xffffffff;
    }
    break;
  case 0x16:
    sVar2 = SCRIPTCountFramesInSpline(instance);
    uVar4 = SEXT24(sVar2);
  }
  return uVar4;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_GetAnimateTextureValue(struct InstanceAnimateTexture *instanceAniTexture /*$a0*/)
// line 6200, offset 0x80066ef4
/* begin block 1 */
// Start line: 6202
// Start offset: 0x80066EF4
// Variables:
// 		long value; // $a1
// 		long trueValue; // $a2
// 		struct _Instance *instance; // $a3

/* begin block 1.1 */
// Start line: 6230
// Start offset: 0x80066F60
// Variables:
// 		struct AniTexInfo *ani_tex_info; // $a0
/* end block 1.1 */
// End offset: 0x80066F60
// End Line: 6231
/* end block 1 */
// End offset: 0x80066F98
// End Line: 6249

/* begin block 2 */
// Start line: 13220
/* end block 2 */
// End Line: 13221

/* begin block 3 */
// Start line: 13221
/* end block 3 */
// End Line: 13222

long EVENT_GetAnimateTextureValue(InstanceAnimateTexture *instanceAniTexture)

{
  uint uVar1;
  AniTex *pAVar2;
  uint uVar3;

  uVar3 = 0;
  uVar1 = 1;
  switch (instanceAniTexture->attribute)
  {
  case 0xd:
  case 0x29:
    uVar1 = 0;
  case 0xe:
    uVar3 = uVar1;
    if ((instanceAniTexture->instance->flags & 0x80U) == 0)
    {
      uVar3 = uVar3 ^ 1;
    }
    break;
  case 0xf:
  case 0x28:
    pAVar2 = instanceAniTexture->aniTextures;
    if (pAVar2 != (AniTex *)0x0)
    {
      return ((int)instanceAniTexture->instance->currentTextureAnimFrame /
              (pAVar2->aniTexInfo).speed) %
             (pAVar2->aniTexInfo).numFrames;
    }
    uVar3 = 0;
    break;
  case -1:
  case 0x11:
    uVar3 = 1;
  }
  return uVar3;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_GetAnimateValue(struct InstanceAnimate *instanceAnimate /*$a0*/)
// line 6253, offset 0x80066fa4
/* begin block 1 */
// Start line: 6254
// Start offset: 0x80066FA4
// Variables:
// 		long value; // $a1
// 		struct _Instance *instance; // $a0
/* end block 1 */
// End offset: 0x8006700C
// End Line: 6293

/* begin block 2 */
// Start line: 13329
/* end block 2 */
// End Line: 13330

long EVENT_GetAnimateValue(InstanceAnimate *instanceAnimate)

{
  long lVar1;
  int Query;

  lVar1 = 0;
  switch (instanceAnimate->attribute)
  {
  case 0xd:
  case 0x29:
    lVar1 = 0;
    break;
  case 0xf:
  case 0x28:
    Query = 0x12;
    goto LAB_80067000;
  case 0x1e:
    Query = 0x11;
  LAB_80067000:
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(instanceAnimate->instance, Query);
  case -1:
  case 0xe:
    lVar1 = 1;
  }
  return lVar1;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_TransformObjectOnStack(struct _PCodeStack *stack /*$t0*/, long item /*$t1*/, short *codeStream /*$a3*/)
// line 6298, offset 0x8006701c
/* begin block 1 */
// Start line: 6299
// Start offset: 0x8006701C
// Variables:
// 		long retValue; // $v0
/* end block 1 */
// End offset: 0x80067060
// End Line: 6314

/* begin block 2 */
// Start line: 13423
/* end block 2 */
// End Line: 13424

long EVENT_TransformObjectOnStack(_PCodeStack *stack, long item, short *codeStream)

{
  long lVar1;

  lVar1 = 0;
  if (stack->topOfStack != 0)
  {
    lVar1 = EVENT_TransformOperand((StackType *)stack[-1].stack[stack->topOfStack + 0x1f].data, stack, item,
                                   codeStream);
  }
  return lVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_UpdatePuzzlePointers(struct EventPointers *events /*$a0*/, long offset /*$a1*/)
// line 6318, offset 0x80067070
/* begin block 1 */
// Start line: 6320
// Start offset: 0x80067070
// Variables:
// 		long d; // $t3
// 		long d2; // $t1
// 		struct Event *curEvent; // $a3
/* end block 1 */
// End offset: 0x80067244
// End Line: 6359

/* begin block 2 */
// Start line: 13463
/* end block 2 */
// End Line: 13464

/* begin block 3 */
// Start line: 13464
/* end block 3 */
// End Line: 13465

/* begin block 4 */
// Start line: 13467
/* end block 4 */
// End Line: 13468

void EVENT_UpdatePuzzlePointers(EventPointers *events, long offset)

{
  _func_15 *p_Var1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  EventPointers *pEVar7;
  int iVar8;

  if ((events != (EventPointers *)0x0) && (iVar8 = 0, pEVar7 = events, 0 < events->numPuzzles))
  {
    do
    {
      p_Var1 = (_func_15 *)0x0;
      if (pEVar7->eventInstances[0] != (_func_15 *)0x0)
      {
        p_Var1 = pEVar7->eventInstances[0] + offset;
      }
      pEVar7->eventInstances[0] = p_Var1;
      iVar3 = 0;
      if (*(int *)(p_Var1 + 0x10) != 0)
      {
        iVar3 = *(int *)(p_Var1 + 0x10) + offset;
      }
      iVar5 = 0;
      *(int *)(p_Var1 + 0x10) = iVar3;
      if (*(int *)(p_Var1 + 0x14) != 0)
      {
        iVar5 = *(int *)(p_Var1 + 0x14) + offset;
      }
      iVar3 = 0;
      *(int *)(p_Var1 + 0x14) = iVar5;
      if (*(int *)(p_Var1 + 0x18) != 0)
      {
        iVar3 = *(int *)(p_Var1 + 0x18) + offset;
      }
      iVar5 = 0;
      *(int *)(p_Var1 + 0x18) = iVar3;
      if (0 < *(short *)(p_Var1 + 2))
      {
        iVar3 = 0;
        do
        {
          iVar4 = *(int *)(iVar3 + *(int *)(p_Var1 + 0x10));
          iVar2 = 0;
          if (iVar4 != 0)
          {
            iVar2 = iVar4 + offset;
          }
          *(int *)(iVar3 + *(int *)(p_Var1 + 0x10)) = iVar2;
          psVar6 = *(short **)(iVar3 + *(int *)(p_Var1 + 0x10));
          if (*psVar6 == 2)
          {
            iVar2 = 0;
            if (*(int *)(psVar6 + 4) != 0)
            {
              iVar2 = *(int *)(psVar6 + 4) + offset;
            }
            *(int *)(psVar6 + 4) = iVar2;
          }
          iVar5 = iVar5 + 1;
          iVar3 = iVar3 + 4;
        } while (iVar5 < *(short *)(p_Var1 + 2));
      }
      iVar3 = 0;
      if (p_Var1[4] != (_func_15)0x0)
      {
        iVar5 = 0;
        do
        {
          iVar2 = *(int *)(iVar5 + *(int *)(p_Var1 + 0x14));
          if (iVar2 != 0)
          {
            *(int *)(iVar5 + *(int *)(p_Var1 + 0x14)) = iVar2 + offset;
            iVar4 = *(int *)(*(int *)(iVar5 + *(int *)(p_Var1 + 0x14)) + 4);
            iVar2 = 0;
            if (iVar4 != 0)
            {
              iVar2 = iVar4 + offset;
            }
            *(int *)(*(int *)(iVar5 + *(int *)(p_Var1 + 0x14)) + 4) = iVar2;
          }
          iVar2 = *(int *)(iVar5 + *(int *)(p_Var1 + 0x18));
          if (iVar2 != 0)
          {
            *(int *)(iVar5 + *(int *)(p_Var1 + 0x18)) = iVar2 + offset;
            iVar4 = *(int *)(*(int *)(iVar5 + *(int *)(p_Var1 + 0x18)) + 4);
            iVar2 = 0;
            if (iVar4 != 0)
            {
              iVar2 = iVar4 + offset;
            }
            *(int *)(*(int *)(iVar5 + *(int *)(p_Var1 + 0x18)) + 4) = iVar2;
          }
          iVar3 = iVar3 + 1;
          iVar5 = iVar5 + 4;
        } while (iVar3 < (int)(uint)(byte)p_Var1[4]);
      }
      iVar8 = iVar8 + 1;
      pEVar7 = (EventPointers *)pEVar7->eventInstances;
    } while (iVar8 < events->numPuzzles);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_SaveEventsFromLevel(long levelID /*$s5*/, struct Level *level /*$a1*/)
// line 6363, offset 0x8006724c
/* begin block 1 */
// Start line: 6364
// Start offset: 0x8006724C
// Variables:
// 		struct EventPointers *eventPointers; // $s4
// 		struct Event *eventInstance; // $s0
// 		long i; // $s3
// 		long d; // $a1
// 		long saveEvent; // $s1

/* begin block 1.1 */
// Start line: 6377
// Start offset: 0x8006728C
// Variables:
// 		long useBigSave; // $s2

/* begin block 1.1.1 */
// Start line: 6403
// Start offset: 0x800672F8
// Variables:
// 		struct SavedEvent *savedEvent; // $v0
/* end block 1.1.1 */
// End offset: 0x80067340
// End Line: 6413

/* begin block 1.1.2 */
// Start line: 6416
// Start offset: 0x80067348
// Variables:
// 		struct SavedEventSmallVars *savedEvent; // $a2
/* end block 1.1.2 */
// End offset: 0x80067390
// End Line: 6426
/* end block 1.1 */
// End offset: 0x80067390
// End Line: 6428
/* end block 1 */
// End offset: 0x800673A4
// End Line: 6430

/* begin block 2 */
// Start line: 13588
/* end block 2 */
// End Line: 13589

void EVENT_SaveEventsFromLevel(long levelID, Level *level)

{
  bool bVar1;
  bool bVar2;
  short *psVar3;
  undefined *puVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  EventPointers *pEVar9;

  pEVar9 = level->PuzzleInstances;
  if ((pEVar9 != (EventPointers *)0x0) && (iVar8 = 0, 0 < pEVar9->numPuzzles))
  {
    do
    {
      bVar1 = false;
      psVar5 = (short *)pEVar9->eventInstances[iVar8];
      iVar6 = 0;
      psVar3 = psVar5;
      bVar2 = bVar1;
      do
      {
        if ((psVar3[3] != 0) && (bVar1 = true, 0xfe < (ushort)(psVar3[3] + 0x7fU)))
        {
          bVar2 = true;
        }
        iVar6 = iVar6 + 1;
        psVar3 = psVar3 + 1;
      } while (iVar6 < 5);
      SAVE_DeleteSavedEvent(levelID, (int)*psVar5);
      if (bVar1)
      {
        if (bVar2)
        {
          puVar4 = (undefined *)SAVE_GetSavedBlock(2, 0);
          iVar6 = 0;
          *puVar4 = 2;
          *(short *)(puVar4 + 2) = (short)levelID;
          *(short *)(puVar4 + 4) = *psVar5;
          do
          {
            psVar3 = psVar5 + 3;
            psVar5 = psVar5 + 1;
            iVar6 = iVar6 + 1;
            *(short *)(puVar4 + 6) = *psVar3;
            puVar4 = puVar4 + 2;
          } while (iVar6 < 5);
        }
        else
        {
          puVar4 = (undefined *)SAVE_GetSavedBlock(9, 0);
          *puVar4 = 9;
          *(short *)(puVar4 + 2) = (short)levelID;
          puVar4[4] = *(undefined *)psVar5;
          iVar6 = 0;
          do
          {
            iVar7 = iVar6 + 1;
            puVar4[iVar6 + 5] = *(undefined *)(psVar5 + 3);
            psVar5 = psVar5 + 1;
            iVar6 = iVar7;
          } while (iVar7 < 5);
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < pEVar9->numPuzzles);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_LoadEventsForLevel(long levelID /*$s2*/, struct Level *level /*$a1*/)
// line 6433, offset 0x800673c8
/* begin block 1 */
// Start line: 6434
// Start offset: 0x800673C8
// Variables:
// 		long d; // $v1
// 		struct EventPointers *eventPointers; // $s0
// 		struct Event *eventInstance; // $t0
// 		struct SavedBasic *savedEvent; // $a1

/* begin block 1.1 */
// Start line: 6448
// Start offset: 0x80067410
// Variables:
// 		long eventNumber; // $t1
/* end block 1.1 */
// End offset: 0x800674D8
// End Line: 6488
/* end block 1 */
// End offset: 0x800674EC
// End Line: 6496

/* begin block 2 */
// Start line: 13813
/* end block 2 */
// End Line: 13814

void EVENT_LoadEventsForLevel(long levelID, Level *level)

{
  byte *pbVar1;
  SavedBasic *curSave;
  int iVar2;
  short *psVar3;
  EventPointers *pEVar4;
  SavedBasic *pSVar5;
  uint uVar6;
  EventPointers *pEVar7;

  pEVar7 = level->PuzzleInstances;
  if (pEVar7 != (EventPointers *)0x0)
  {
    curSave = SAVE_GetSavedNextEvent(levelID, (SavedBasic *)0x0);
    while (curSave != (SavedBasic *)0x0)
    {
      if (pEVar7->numPuzzles != 0)
      {
        if (curSave->savedID == '\x02')
        {
          uVar6 = SEXT24((short)curSave[2]);
        }
        else
        {
          uVar6 = (uint)curSave[2].savedID;
        }
        iVar2 = 0;
        pEVar4 = pEVar7;
        psVar3 = (short *)0x0;
        if (0 < pEVar7->numPuzzles)
        {
          do
          {
            psVar3 = (short *)pEVar4->eventInstances[0];
            iVar2 = iVar2 + 1;
            if ((int)*psVar3 == uVar6)
              break;
            pEVar4 = (EventPointers *)pEVar4->eventInstances;
            psVar3 = (short *)0x0;
          } while (iVar2 < pEVar7->numPuzzles);
        }
        if (psVar3 != (short *)0x0)
        {
          iVar2 = 0;
          pSVar5 = curSave;
          if (curSave->savedID == '\x02')
          {
            do
            {
              iVar2 = iVar2 + 1;
              *(SavedBasic *)(psVar3 + 3) = pSVar5[3];
              psVar3 = psVar3 + 1;
              pSVar5 = pSVar5 + 1;
            } while (iVar2 < 5);
          }
          else
          {
            do
            {
              pbVar1 = &curSave[2].shiftedSaveSize + iVar2;
              iVar2 = iVar2 + 1;
              psVar3[3] = (ushort)*pbVar1;
              psVar3 = psVar3 + 1;
            } while (iVar2 < 5);
          }
        }
      }
      curSave = SAVE_GetSavedNextEvent(levelID, curSave);
    }
  }
  return;
}

// decompiled code
// original method signature:
// struct SavedBasic * /*$ra*/ EVENT_CreateSaveEvent(long levelID /*$s0*/, long eventNumber /*$s1*/)
// line 6499, offset 0x80067504
/* begin block 1 */
// Start line: 6500
// Start offset: 0x80067504
// Variables:
// 		struct SavedEventSmallVars *savedEvent; // $a1
// 		long d; // $a0
/* end block 1 */
// End offset: 0x80067558
// End Line: 6522

/* begin block 2 */
// Start line: 13969
/* end block 2 */
// End Line: 13970

SavedBasic *EVENT_CreateSaveEvent(long levelID, long eventNumber)

{
  SavedBasic *pSVar1;
  SavedBasic *pSVar2;
  int iVar3;

  pSVar1 = (SavedBasic *)SAVE_GetSavedBlock(9, 0);
  if (pSVar1 != (SavedBasic *)0x0)
  {
    iVar3 = 4;
    pSVar2 = pSVar1 + 2;
    pSVar1->savedID = '\t';
    pSVar1[1] = SUB42(levelID, 0);
    pSVar1[2].savedID = (uchar)eventNumber;
    do
    {
      pSVar2[2].shiftedSaveSize = '\0';
      iVar3 = iVar3 + -1;
      pSVar2 = (SavedBasic *)&pSVar2[-1].shiftedSaveSize;
    } while (-1 < iVar3);
  }
  return pSVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_RemoveInstanceFromInstanceList(struct _Instance *instance /*$a0*/)
// line 6526, offset 0x80067570
/* begin block 1 */
// Start line: 6528
// Start offset: 0x80067570
// Variables:
// 		int d; // $t3
// 		int i; // $t0
// 		int i2; // $a1
// 		struct EventPointers *puzzle; // $t2
// 		struct EventBasicObject **basicEventObject; // $v0
/* end block 1 */
// End offset: 0x80067650
// End Line: 6559

/* begin block 2 */
// Start line: 14034
/* end block 2 */
// End Line: 14035

/* begin block 3 */
// Start line: 14035
/* end block 3 */
// End Line: 14036

/* begin block 4 */
// Start line: 14040
/* end block 4 */
// End Line: 14041

void EVENT_RemoveInstanceFromInstanceList(_Instance *instance)

{
  short **ppsVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;

  iVar7 = 0;
  iVar2 = 0;
  do
  {
    if (((*(short *)((int)&DAT_800d1924 + iVar2) == 2) &&
         (piVar6 = *(int **)(*(int *)((int)&DAT_800d1928 + iVar2) + 0xdc), piVar6 != (int *)0x0)) &&
        (iVar2 = 0, piVar5 = piVar6, 0 < *piVar6))
    {
      do
      {
        ppsVar1 = *(short ***)(piVar5[1] + 0x10);
        iVar4 = 0;
        if (0 < *(short *)(piVar5[1] + 2))
        {
          do
          {
            psVar3 = *ppsVar1;
            if ((*psVar3 == 1) && (*(_Instance **)(psVar3 + 6) == instance))
            {
              *(undefined4 *)(psVar3 + 6) = 0;
              break;
            }
            iVar4 = iVar4 + 1;
            ppsVar1 = ppsVar1 + 1;
          } while (iVar4 < *(short *)(piVar5[1] + 2));
        }
        iVar2 = iVar2 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar2 < *piVar6);
    }
    iVar7 = iVar7 + 1;
    iVar2 = iVar7 * 0x40;
    if (0xf < iVar7)
    {
      return;
    }
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_UpdatePuzzleWithInstance(struct EventPointers *puzzle /*$a0*/, struct _Instance *instance /*$a1*/)
// line 6562, offset 0x80067658
/* begin block 1 */
// Start line: 6564
// Start offset: 0x80067658
// Variables:
// 		int i; // $t2
// 		int i2; // $t0
// 		struct EventBasicObject **basicEventObject; // $v0
/* end block 1 */
// End offset: 0x800676F4
// End Line: 6586

/* begin block 2 */
// Start line: 14125
/* end block 2 */
// End Line: 14126

/* begin block 3 */
// Start line: 14126
/* end block 3 */
// End Line: 14127

/* begin block 4 */
// Start line: 14130
/* end block 4 */
// End Line: 14131

void EVENT_UpdatePuzzleWithInstance(EventPointers *puzzle, _Instance *instance)

{
  short **ppsVar1;
  short *psVar2;
  int iVar3;
  EventPointers *pEVar4;
  int iVar5;

  iVar5 = 0;
  pEVar4 = puzzle;
  if (0 < puzzle->numPuzzles)
  {
    do
    {
      ppsVar1 = *(short ***)(pEVar4->eventInstances[0] + 0x10);
      iVar3 = 0;
      if (0 < *(short *)(pEVar4->eventInstances[0] + 2))
      {
        do
        {
          psVar2 = *ppsVar1;
          if ((*psVar2 == 1) && (instance->introUniqueID == *(int *)(psVar2 + 4)))
          {
            *(_Instance **)(psVar2 + 6) = instance;
            break;
          }
          iVar3 = iVar3 + 1;
          ppsVar1 = ppsVar1 + 1;
        } while (iVar3 < *(short *)(pEVar4->eventInstances[0] + 2));
      }
      iVar5 = iVar5 + 1;
      pEVar4 = (EventPointers *)pEVar4->eventInstances;
    } while (iVar5 < puzzle->numPuzzles);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_AddInstanceToInstanceList(struct _Instance *instance /*$s2*/)
// line 6588, offset 0x800676fc
/* begin block 1 */
// Start line: 6589
// Start offset: 0x800676FC
// Variables:
// 		int d; // $s1
// 		int curTree; // $a1
// 		struct EventPointers *puzzle; // $a0
// 		struct Level *level; // $s0

/* begin block 1.1 */
// Start line: 6608
// Start offset: 0x80067770
// Variables:
// 		struct BSPTree *bspTree; // $a0
/* end block 1.1 */
// End offset: 0x800677A4
// End Line: 6618
/* end block 1 */
// End offset: 0x800677D0
// End Line: 6621

/* begin block 2 */
// Start line: 14191
/* end block 2 */
// End Line: 14192

void EVENT_AddInstanceToInstanceList(_Instance *instance)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;

  iVar5 = 0;
  do
  {
    if ((&DAT_800d1924)[iVar5 * 0x20] == 2)
    {
      piVar4 = (int *)(&DAT_800d1928)[iVar5 * 0x10];
      if ((EventPointers *)piVar4[0x37] != (EventPointers *)0x0)
      {
        EVENT_UpdatePuzzleWithInstance((EventPointers *)piVar4[0x37], instance);
      }
      iVar1 = *piVar4;
      iVar2 = 0;
      if (0 < *(int *)(iVar1 + 0x44))
      {
        iVar3 = 0;
        do
        {
          iVar1 = *(int *)(iVar1 + 0x48) + iVar3;
          if ((-1 < *(short *)(iVar1 + 0x1a)) && (*(int *)(iVar1 + 0x1c) == instance->introUniqueID))
          {
            *(_Instance **)(iVar1 + 0x20) = instance;
          }
          iVar1 = *piVar4;
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0x24;
        } while (iVar2 < *(int *)(iVar1 + 0x44));
      }
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x10);
  return;
}

// decompiled code
// original method signature:
// struct _VMObject * /*$ra*/ EVENT_FindVMObject(struct _StreamUnit *stream /*$a0*/, char *vmoName /*$s4*/)
// line 6623, offset 0x800677e8
/* begin block 1 */
// Start line: 6624
// Start offset: 0x800677E8
// Variables:
// 		int i; // $s2
// 		struct _VMObject *vmObject; // $s3
// 		struct Level *level; // $s1
/* end block 1 */
// End offset: 0x80067864
// End Line: 6643

/* begin block 2 */
// Start line: 14290
/* end block 2 */
// End Line: 14291

_VMObject *EVENT_FindVMObject(_StreamUnit *stream, char *vmoName)

{
  if (0 < stream->level->numVMObjects)
  {
    /* WARNING: Subroutine does not return */
    strcmpi(stream->level->vmobjectList->name, vmoName);
  }
  return (_VMObject *)0x0;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_FixPuzzlesForStream(struct _StreamUnit *stream /*$s7*/)
// line 6646, offset 0x80067888
/* begin block 1 */
// Start line: 6647
// Start offset: 0x80067888
// Variables:
// 		struct EventPointers *puzzle; // $s5
// 		struct EventBasicObject **basicEventObject; // $s6
// 		struct _Instance *instance; // $a1
// 		struct _Instance *next; // $s0
// 		int i; // $s4
// 		int i2; // $s2
// 		int p; // $a2

/* begin block 1.1 */
// Start line: 6674
// Start offset: 0x80067938
// Variables:
// 		struct _StreamUnit *newStream; // $v0
/* end block 1.1 */
// End offset: 0x8006794C
// End Line: 6682

/* begin block 1.2 */
// Start line: 6689
// Start offset: 0x8006795C
// Variables:
// 		struct EventEventObject *eventEventObject; // $s1
// 		struct _StreamUnit *newStream; // $v0

/* begin block 1.2.1 */
// Start line: 6696
// Start offset: 0x80067970
// Variables:
// 		struct EventPointers *puzzleInstances; // $v1
/* end block 1.2.1 */
// End offset: 0x800679C8
// End Line: 6713
/* end block 1.2 */
// End offset: 0x800679C8
// End Line: 6714

/* begin block 1.3 */
// Start line: 6719
// Start offset: 0x800679D8
// Variables:
// 		struct EventTGroupObject *tgroupEventObject; // $s1
// 		struct _StreamUnit *newStream; // $v0

/* begin block 1.3.1 */
// Start line: 6724
// Start offset: 0x800679EC
// Variables:
// 		struct _Terrain *terrain; // $v0
/* end block 1.3.1 */
// End offset: 0x80067A3C
// End Line: 6746
/* end block 1.3 */
// End offset: 0x80067A3C
// End Line: 6747

/* begin block 1.4 */
// Start line: 6752
// Start offset: 0x80067A4C
// Variables:
// 		struct _StreamUnit *newStream; // $v0
/* end block 1.4 */
// End offset: 0x80067A60
// End Line: 6760

/* begin block 1.5 */
// Start line: 6769
// Start offset: 0x80067A7C
// Variables:
// 		void *pointer; // $v1

/* begin block 1.5.1 */
// Start line: 6779
// Start offset: 0x80067A98
// Variables:
// 		struct _StreamUnit *stream2; // $v0
/* end block 1.5.1 */
// End offset: 0x80067AC0
// End Line: 6787
/* end block 1.5 */
// End offset: 0x80067AC0
// End Line: 6787

/* begin block 1.6 */
// Start line: 6797
// Start offset: 0x80067AF0
// Variables:
// 		struct _StreamUnit *newStream; // $v0
/* end block 1.6 */
// End offset: 0x80067B10
// End Line: 6808
/* end block 1 */
// End offset: 0x80067B40
// End Line: 6817

/* begin block 2 */
// Start line: 14341
/* end block 2 */
// End Line: 14342

void EVENT_FixPuzzlesForStream(_StreamUnit *stream)

{
  short sVar1;
  long *plVar2;
  int iVar3;
  _StreamUnit *stream_00;
  _Terrain *p_Var4;
  _MultiSignal *p_Var5;
  Intro *pIVar6;
  _SFXMkr *p_Var7;
  _VMObject *p_Var8;
  EventPointers *pEVar9;
  _Instance *instance;
  int iVar10;
  BSPTree *pBVar11;
  _Instance *p_Var12;
  EventInstanceObject *instanceObject;
  int iVar13;
  EventPointers *pEVar14;
  int iVar15;
  EventPointers *puzzle;
  int iVar16;

  puzzle = stream->level->PuzzleInstances;
  instance = *(_Instance **)(DAT_800d0fe0 + 4);
  if (puzzle != (EventPointers *)0x0)
  {
    while (instance != (_Instance *)0x0)
    {
      p_Var12 = instance->next;
      EVENT_UpdatePuzzleWithInstance(puzzle, instance);
      instance = p_Var12;
    }
    iVar15 = 0;
    pEVar14 = puzzle;
    if (0 < puzzle->numPuzzles)
    {
      do
      {
        iVar16 = *(int *)(pEVar14->eventInstances[0] + 0x10);
        iVar13 = 0;
        if (0 < *(short *)(pEVar14->eventInstances[0] + 2))
        {
          iVar3 = 0;
          do
          {
            instanceObject = *(EventInstanceObject **)(iVar3 + iVar16);
            sVar1 = instanceObject->id;
            if (sVar1 == 5)
            {
              stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID);
              if (stream_00 != (_StreamUnit *)0x0)
              {
                *(_StreamUnit **)&instanceObject->introUniqueID = stream_00;
              }
            }
            else
            {
              if (sVar1 == 3)
              {
                stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID);
                if ((stream_00 != (_StreamUnit *)0x0) &&
                    (pEVar9 = stream_00->level->PuzzleInstances, pEVar9 != (EventPointers *)0x0))
                {
                  plVar2 = &pEVar9->numPuzzles;
                  iVar3 = 0;
                  if (0 < *plVar2)
                  {
                    do
                    {
                      iVar3 = iVar3 + 1;
                      if (*(short *)pEVar9->eventInstances[0] == instanceObject->flags)
                      {
                        *(_func_15 **)&instanceObject->introUniqueID = pEVar9->eventInstances[0];
                        break;
                      }
                      pEVar9 = (EventPointers *)pEVar9->eventInstances;
                    } while (iVar3 < *plVar2);
                  }
                }
              }
              else
              {
                if (sVar1 == 4)
                {
                  stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID);
                  if (stream_00 != (_StreamUnit *)0x0)
                  {
                    p_Var4 = stream_00->level->terrain;
                    iVar3 = p_Var4->numBSPTrees;
                    iVar10 = 0;
                    if (0 < iVar3)
                    {
                      pBVar11 = p_Var4->BSPTreeArray;
                      do
                      {
                        iVar10 = iVar10 + 1;
                        if (pBVar11->ID == instanceObject->flags)
                        {
                          *(BSPTree **)&instanceObject->introUniqueID = pBVar11;
                          *(_StreamUnit **)&instanceObject->instance = stream;
                          break;
                        }
                        pBVar11 = pBVar11 + 1;
                      } while (iVar10 < iVar3);
                    }
                  }
                }
                else
                {
                  if (sVar1 == 6)
                  {
                    stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID);
                    if (stream_00 != (_StreamUnit *)0x0)
                    {
                      p_Var5 = EVENT_ResolveObjectSignal(stream_00, (int)instanceObject->flags);
                      *(_MultiSignal **)&instanceObject->introUniqueID = p_Var5;
                    }
                  }
                  else
                  {
                    if (sVar1 == 1)
                    {
                      pIVar6 = EVENT_ResolveObjectIntro(instanceObject);
                      if (pIVar6 == (Intro *)0x0)
                      {
                        stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID);
                        if ((stream_00 != (_StreamUnit *)0x0) &&
                            (p_Var7 = EVENT_ResolveSFXMarker(stream_00, instanceObject),
                             p_Var7 != (_SFXMkr *)0x0))
                        {
                          *(_SFXMkr **)&instanceObject->data = p_Var7;
                          instanceObject->flags = instanceObject->flags | 1;
                        }
                      }
                      else
                      {
                        *(Intro **)&instanceObject->data = pIVar6;
                      }
                    }
                    else
                    {
                      if ((sVar1 == 7) &&
                          (stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID),
                           stream_00 != (_StreamUnit *)0x0))
                      {
                        p_Var8 = EVENT_FindVMObject(stream_00, (char *)&instanceObject->introUniqueID);
                        *(_VMObject **)(instanceObject + 1) = p_Var8;
                      }
                    }
                  }
                }
              }
            }
            iVar13 = iVar13 + 1;
            iVar3 = iVar13 * 4;
          } while (iVar13 < *(short *)(pEVar14->eventInstances[0] + 2));
        }
        iVar15 = iVar15 + 1;
        pEVar14 = (EventPointers *)pEVar14->eventInstances;
      } while (iVar15 < puzzle->numPuzzles);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_AddStreamToInstanceList(struct _StreamUnit *stream /*$s1*/)
// line 6819, offset 0x80067b6c
/* begin block 1 */
// Start line: 6820
// Start offset: 0x80067B6C
// Variables:
// 		int d; // $s6
// 		int i; // $s4
// 		int i2; // $s2
// 		int p; // $a2
// 		struct EventPointers *puzzle; // $s5
// 		struct EventBasicObject **basicEventObject; // $s7
// 		struct EventEventObject *eventEventObject; // $a1
// 		struct EventTGroupObject *tgroupEventObject; // $t0

/* begin block 1.1 */
// Start line: 6857
// Start offset: 0x80067C54
// Variables:
// 		struct EventPointers *puzzleInstances; // $v1
/* end block 1.1 */
// End offset: 0x80067CAC
// End Line: 6875

/* begin block 1.2 */
// Start line: 6882
// Start offset: 0x80067CD0
// Variables:
// 		struct _Terrain *terrain; // $v0
/* end block 1.2 */
// End offset: 0x80067D20
// End Line: 6906

/* begin block 1.3 */
// Start line: 6912
// Start offset: 0x80067D30
/* end block 1.3 */
// End offset: 0x80067D44
// End Line: 6917

/* begin block 1.4 */
// Start line: 6926
// Start offset: 0x80067D60
// Variables:
// 		void *pointer; // $v1
/* end block 1.4 */
// End offset: 0x80067D90
// End Line: 6940

/* begin block 1.5 */
// Start line: 6949
// Start offset: 0x80067DC0
/* end block 1.5 */
// End offset: 0x80067DE0
// End Line: 6958
/* end block 1 */
// End offset: 0x80067E20
// End Line: 6970

/* begin block 2 */
// Start line: 14936
/* end block 2 */
// End Line: 14937

void EVENT_AddStreamToInstanceList(_StreamUnit *stream)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  _Terrain *p_Var4;
  _MultiSignal *p_Var5;
  Intro *pIVar6;
  _SFXMkr *p_Var7;
  _VMObject *p_Var8;
  int iVar9;
  EventPointers *pEVar10;
  int iVar11;
  BSPTree *pBVar12;
  EventInstanceObject *instanceObject;
  int iVar13;
  int *piVar14;
  int *piVar15;
  int iVar16;
  int iVar17;

  iVar16 = 0;
  iVar9 = 0;
  do
  {
    if (((*(short *)((int)&DAT_800d1924 + iVar9) == 2) &&
         (piVar15 = *(int **)(*(int *)((int)&DAT_800d1928 + iVar9) + 0xdc), piVar15 != (int *)0x0)) &&
        (iVar9 = 0, piVar14 = piVar15, 0 < *piVar15))
    {
      do
      {
        iVar17 = *(int *)(piVar14[1] + 0x10);
        iVar13 = 0;
        if (0 < *(short *)(piVar14[1] + 2))
        {
          iVar3 = 0;
          do
          {
            instanceObject = *(EventInstanceObject **)(iVar3 + iVar17);
            sVar1 = instanceObject->id;
            if (sVar1 == 5)
            {
              if (instanceObject->unitID == stream->StreamUnitID)
              {
                *(_StreamUnit **)&instanceObject->introUniqueID = stream;
              }
            }
            else
            {
              if (sVar1 == 3)
              {
                if ((instanceObject->unitID == stream->StreamUnitID) &&
                    (pEVar10 = stream->level->PuzzleInstances, pEVar10 != (EventPointers *)0x0))
                {
                  piVar2 = &pEVar10->numPuzzles;
                  iVar3 = 0;
                  if (0 < *piVar2)
                  {
                    do
                    {
                      iVar3 = iVar3 + 1;
                      if (*(short *)pEVar10->eventInstances[0] == instanceObject->flags)
                      {
                        *(_func_15 **)&instanceObject->introUniqueID = pEVar10->eventInstances[0];
                        break;
                      }
                      pEVar10 = (EventPointers *)pEVar10->eventInstances;
                    } while (iVar3 < *piVar2);
                  }
                }
              }
              else
              {
                if (sVar1 == 4)
                {
                  if (instanceObject->unitID == stream->StreamUnitID)
                  {
                    p_Var4 = stream->level->terrain;
                    iVar3 = p_Var4->numBSPTrees;
                    iVar11 = 0;
                    if (0 < iVar3)
                    {
                      pBVar12 = p_Var4->BSPTreeArray;
                      do
                      {
                        iVar11 = iVar11 + 1;
                        if (pBVar12->ID == instanceObject->flags)
                        {
                          *(BSPTree **)&instanceObject->introUniqueID = pBVar12;
                          *(_StreamUnit **)&instanceObject->instance = stream;
                          break;
                        }
                        pBVar12 = pBVar12 + 1;
                      } while (iVar11 < iVar3);
                    }
                  }
                }
                else
                {
                  if (sVar1 == 6)
                  {
                    if (instanceObject->unitID == stream->StreamUnitID)
                    {
                      p_Var5 = EVENT_ResolveObjectSignal(stream, (int)instanceObject->flags);
                      *(_MultiSignal **)&instanceObject->introUniqueID = p_Var5;
                    }
                  }
                  else
                  {
                    if (sVar1 == 1)
                    {
                      pIVar6 = EVENT_ResolveObjectIntro(instanceObject);
                      if (pIVar6 == (Intro *)0x0)
                      {
                        p_Var7 = EVENT_ResolveSFXMarker(stream, instanceObject);
                        if (p_Var7 != (_SFXMkr *)0x0)
                        {
                          *(_SFXMkr **)&instanceObject->data = p_Var7;
                          instanceObject->flags = instanceObject->flags | 1;
                        }
                      }
                      else
                      {
                        *(Intro **)&instanceObject->data = pIVar6;
                      }
                    }
                    else
                    {
                      if ((sVar1 == 7) && (stream->StreamUnitID == instanceObject->unitID))
                      {
                        p_Var8 = EVENT_FindVMObject(stream, (char *)&instanceObject->introUniqueID);
                        *(_VMObject **)(instanceObject + 1) = p_Var8;
                      }
                    }
                  }
                }
              }
            }
            iVar13 = iVar13 + 1;
            iVar3 = iVar13 * 4;
          } while (iVar13 < *(short *)(piVar14[1] + 2));
        }
        iVar9 = iVar9 + 1;
        piVar14 = piVar14 + 1;
      } while (iVar9 < *piVar15);
    }
    iVar16 = iVar16 + 1;
    iVar9 = iVar16 * 0x40;
    if (0xf < iVar16)
    {
      EVENT_FixPuzzlesForStream(stream);
      return;
    }
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_RemoveStreamToInstanceList(struct _StreamUnit *stream /*$s2*/)
// line 6974, offset 0x80067e54
/* begin block 1 */
// Start line: 6975
// Start offset: 0x80067E54
// Variables:
// 		int d; // $t1
// 		int i; // $s1
// 		int i2; // $a1
// 		struct EventPointers *puzzle; // $t0
// 		struct EventBasicObject **basicEventObject; // $v0

/* begin block 1.1 */
// Start line: 7030
// Start offset: 0x80067F3C
/* end block 1.1 */
// End offset: 0x80067F50
// End Line: 7035

/* begin block 1.2 */
// Start line: 7042
// Start offset: 0x80067F60
/* end block 1.2 */
// End offset: 0x80067F78
// End Line: 7051
/* end block 1 */
// End offset: 0x80068000
// End Line: 7072

/* begin block 2 */
// Start line: 15468
/* end block 2 */
// End Line: 15469

void EVENT_RemoveStreamToInstanceList(_StreamUnit *stream)

{
  short sVar1;
  short **ppsVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  char *timer;

  iVar8 = 0;
  iVar3 = 0;
  do
  {
    if ((((*(short *)((int)&DAT_800d1924 + iVar3) == 2) &&
          ((_StreamUnit *)((int)&StreamTracker + iVar3) != stream)) &&
         (piVar7 = *(int **)(*(int *)((int)&DAT_800d1928 + iVar3) + 0xdc), piVar7 != (int *)0x0)) &&
        (iVar3 = 0, piVar6 = piVar7, 0 < *piVar7))
    {
      do
      {
        ppsVar2 = *(short ***)(piVar6[1] + 0x10);
        iVar5 = 0;
        if (0 < *(short *)(piVar6[1] + 2))
        {
          do
          {
            psVar4 = *ppsVar2;
            sVar1 = *psVar4;
            if ((sVar1 == 5) || (sVar1 == 3))
            {
            LAB_80067f3c:
              if (*(int *)(psVar4 + 2) == stream->StreamUnitID)
              {
                *(undefined4 *)(psVar4 + 4) = 0;
              }
            }
            else
            {
              if (sVar1 == 4)
              {
                if (*(int *)(psVar4 + 2) == stream->StreamUnitID)
                {
                  *(undefined4 *)(psVar4 + 4) = 0;
                  *(undefined4 *)(psVar4 + 6) = 0;
                }
              }
              else
              {
                if (sVar1 == 6)
                  goto LAB_80067f3c;
                if ((sVar1 == 1) && (*(int *)(psVar4 + 2) == stream->StreamUnitID))
                {
                  *(undefined4 *)(psVar4 + 8) = 0;
                }
              }
            }
            iVar5 = iVar5 + 1;
            ppsVar2 = ppsVar2 + 1;
          } while (iVar5 < *(short *)(piVar6[1] + 2));
        }
        iVar3 = iVar3 + 1;
        piVar6 = piVar6 + 1;
      } while (iVar3 < *piVar7);
    }
    iVar8 = iVar8 + 1;
    iVar3 = iVar8 * 0x40;
    if (0xf < iVar8)
    {
      iVar3 = 0;
      timer = &eventTimerArray;
      do
      {
        if (((((EventTimer *)timer)->flags & 1U) != 0) &&
            ((Level *)((EventTimer *)timer)->scriptPos == stream->level))
        {
          EVENT_RemoveTimer((EventTimer *)timer);
        }
        iVar3 = iVar3 + 1;
        timer = (char *)&((EventTimer *)timer)->nextEventIndex;
      } while (iVar3 < 0x18);
      return;
    }
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_RelocateInstanceList(struct Level *oldLevel /*$a0*/, struct Level *newLevel /*$a1*/, long sizeOfLevel /*$a2*/)
// line 7076, offset 0x80068018
/* begin block 1 */
// Start line: 7078
// Start offset: 0x80068018
// Variables:
// 		int d; // $t6
// 		int i; // $t4
// 		int i2; // $a3
// 		struct EventPointers *puzzle; // $t5
// 		struct EventBasicObject **basicEventObject; // $v0
// 		long offset; // $t0

/* begin block 1.1 */
// Start line: 7098
// Start offset: 0x800680A4
/* end block 1.1 */
// End offset: 0x800680A4
// End Line: 7103

/* begin block 1.2 */
// Start line: 7110
// Start offset: 0x800680AC
/* end block 1.2 */
// End offset: 0x800680AC
// End Line: 7115

/* begin block 1.3 */
// Start line: 7122
// Start offset: 0x800680B4
/* end block 1.3 */
// End offset: 0x800680DC
// End Line: 7127

/* begin block 1.4 */
// Start line: 7134
// Start offset: 0x800680EC
/* end block 1.4 */
// End offset: 0x80068114
// End Line: 7140

/* begin block 1.5 */
// Start line: 7147
// Start offset: 0x80068124
/* end block 1.5 */
// End offset: 0x80068150
// End Line: 7155
/* end block 1 */
// End offset: 0x80068210
// End Line: 7177

/* begin block 2 */
// Start line: 15754
/* end block 2 */
// End Line: 15755

/* begin block 3 */
// Start line: 15755
/* end block 3 */
// End Line: 15756

/* begin block 4 */
// Start line: 15760
/* end block 4 */
// End Line: 15761

void EVENT_RelocateInstanceList(Level *oldLevel, Level *newLevel, long sizeOfLevel)

{
  short sVar1;
  short **ppsVar2;
  int iVar3;
  int iVar4;
  Level *pLVar5;
  char *pcVar6;
  short *psVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  Level *pLVar11;
  Level *pLVar12;
  int *piVar13;
  int *piVar14;
  int iVar15;

  pLVar11 = (Level *)((int)newLevel - (int)oldLevel);
  iVar15 = 0;
  pLVar12 = (Level *)((int)&oldLevel->terrain + sizeOfLevel);
  iVar4 = 0;
  do
  {
    if (((*(short *)((int)&DAT_800d1924 + iVar4) == 2) &&
         (piVar14 = *(int **)(*(int *)((int)&DAT_800d1928 + iVar4) + 0xdc), piVar14 != (int *)0x0)) &&
        (iVar4 = 0, piVar13 = piVar14, 0 < *piVar14))
    {
      do
      {
        ppsVar2 = *(short ***)(piVar13[1] + 0x10);
        iVar9 = 0;
        if (0 < *(short *)(piVar13[1] + 2))
        {
          do
          {
            psVar7 = *ppsVar2;
            sVar1 = *psVar7;
            if (((sVar1 == 3) || (sVar1 == 4)) || (sVar1 == 6))
            {
              pLVar5 = *(Level **)(psVar7 + 4);
              if ((oldLevel <= pLVar5) && (pLVar5 <= pLVar12))
              {
                iVar3 = 0;
                if (pLVar5 != (Level *)0x0)
                {
                  iVar3 = (int)pLVar5 + (int)pLVar11;
                }
                *(int *)(psVar7 + 4) = iVar3;
              }
            }
            else
            {
              if (sVar1 == 1)
              {
                pLVar5 = *(Level **)(psVar7 + 8);
                if ((oldLevel <= pLVar5) && (pLVar5 <= pLVar12))
                {
                  iVar3 = 0;
                  if (pLVar5 != (Level *)0x0)
                  {
                    iVar3 = (int)pLVar5 + (int)pLVar11;
                  }
                  *(int *)(psVar7 + 8) = iVar3;
                }
              }
              else
              {
                if (sVar1 == 7)
                {
                  pLVar5 = *(Level **)(psVar7 + 10);
                  if ((oldLevel <= pLVar5) && (pLVar5 <= pLVar12))
                  {
                    iVar3 = 0;
                    if (pLVar5 != (Level *)0x0)
                    {
                      iVar3 = (int)pLVar5 + (int)pLVar11;
                    }
                    *(int *)(psVar7 + 10) = iVar3;
                  }
                }
              }
            }
            iVar9 = iVar9 + 1;
            ppsVar2 = ppsVar2 + 1;
          } while (iVar9 < *(short *)(piVar13[1] + 2));
        }
        iVar4 = iVar4 + 1;
        piVar13 = piVar13 + 1;
      } while (iVar4 < *piVar14);
    }
    iVar15 = iVar15 + 1;
    iVar4 = iVar15 * 0x40;
  } while (iVar15 < 0x10);
  pcVar6 = &eventTimerArray;
  do
  {
    if (((*(uint *)pcVar6 & 1) != 0) && ((Level *)((uint *)pcVar6)[4] == oldLevel))
    {
      uVar8 = 0;
      if (((uint *)pcVar6)[1] != 0)
      {
        uVar8 = (int)&pLVar11->terrain + ((uint *)pcVar6)[1];
      }
      uVar10 = 0;
      ((uint *)pcVar6)[1] = uVar8;
      if (((uint *)pcVar6)[2] != 0)
      {
        uVar10 = (int)&pLVar11->terrain + ((uint *)pcVar6)[2];
      }
      uVar8 = 0;
      ((uint *)pcVar6)[2] = uVar10;
      if (((uint *)pcVar6)[3] != 0)
      {
        uVar8 = (int)&pLVar11->terrain + ((uint *)pcVar6)[3];
      }
      ((uint *)pcVar6)[3] = uVar8;
      *(Level **)((uint *)pcVar6 + 4) = newLevel;
    }
    pcVar6 = (char *)((uint *)pcVar6 + 6);
  } while ((int)pcVar6 < -0x7ff2d5ec);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_PrintVars()
// line 7179, offset 0x80068218
/* begin block 1 */
// Start line: 16040
/* end block 1 */
// End Line: 16041

/* begin block 2 */
// Start line: 16069
/* end block 2 */
// End Line: 16070

void EVENT_PrintVars(void)

{
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ EVENT_ExecuteActionCommand(struct StackType *operand1 /*$s0*/, struct StackType *operand2 /*$a1*/, struct _PCodeStack *stack /*$a2*/, short *codeStream /*$a3*/)
// line 7213, offset 0x80068220
/* begin block 1 */
// Start line: 7214
// Start offset: 0x80068220
// Variables:
// 		long error; // stack offset -16
// 		long value; // $a0
// 		short flags; // stack offset -12
/* end block 1 */
// End offset: 0x800683D8
// End Line: 7323

/* begin block 2 */
// Start line: 16108
/* end block 2 */
// End Line: 16109

void EVENT_ExecuteActionCommand(StackType *operand1, StackType *operand2, _PCodeStack *stack, short *codeStream)

{
  long lVar1;
  int local_10;
  short asStack12[2];

  switch (operand1->id)
  {
  case 1:
    EVENT_DoAreaAction((AreaObject *)operand1->data, operand2);
    break;
  case 2:
    EVENT_DoInstanceAction((InstanceObject *)operand1->data, operand2, codeStream);
    break;
  case 3:
    EVENT_DoGameAction((GameObject *)operand1->data, operand2);
    break;
  case 4:
    EVENT_DoIntroAction((IntroObject *)operand1->data, operand2);
    break;
  case 10:
    lVar1 = EVENT_GetScalerValueFromOperand(operand2, &local_10, asStack12);
    if (local_10 == 0)
    {
      **(undefined2 **)operand1->data = (short)lVar1;
    }
    break;
  case 0xb:
    lVar1 = EVENT_GetScalerValueFromOperand(operand2, &local_10, asStack12);
    if (local_10 == 0)
    {
      **(long **)operand1->data = lVar1;
    }
    break;
  case 0xf:
    EVENT_DoSplineAction((InstanceSpline *)operand1->data, operand2);
    break;
  case 0x11:
    EVENT_DoSignalAction((SignalObject *)operand1->data, operand2);
    break;
  case 0x13:
    EVENT_DoAnimateAction((InstanceAnimate *)operand1->data, operand2);
    break;
  case 0x14:
    EVENT_DoInstanceAnimateTextureAction((InstanceAnimateTexture *)operand1->data, operand2);
    break;
  case 0x16:
    EVENT_DoSubListAction((SubListObject *)operand1->data, operand2, stack, codeStream);
    break;
  case 0x17:
    EVENT_DoTGroupAction((TGroupObject *)operand1->data, operand2);
    break;
  case 0x19:
    EVENT_DoCameraAction((CameraObject *)operand1->data, operand2, codeStream);
    break;
  case 0x1a:
    EVENT_DoVMObjectAction((EventVmObject *)operand1->data, operand2);
    break;
  case 0x1b:
    if (*(short *)operand1->data == 1)
    {
      EVENT_DoSoundMarkerAction((SoundObject *)operand1->data, operand2);
    }
    else
    {
      EVENT_DoObjectSoundAction((SoundObject *)operand1->data, operand2);
    }
    break;
  case 0x1c:
    lVar1 = EVENT_GetScalerValueFromOperand(operand2, &local_10, asStack12);
    if (local_10 == 0)
    {
      **(undefined **)operand1->data = (char)lVar1;
    }
  }
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_GetScalerValueFromOperand(struct StackType *operand /*$a0*/, long *error /*$a1*/, short *flags /*$a2*/)
// line 7326, offset 0x800683e8
/* begin block 1 */
// Start line: 7327
// Start offset: 0x800683E8
// Variables:
// 		long value; // $a1
/* end block 1 */
// End offset: 0x80068548
// End Line: 7422

/* begin block 2 */
// Start line: 16334
/* end block 2 */
// End Line: 16335

long EVENT_GetScalerValueFromOperand(StackType *operand, long *error, short *flags)

{
  long lVar1;
  uint uVar2;

  *error = 0;
  *flags = 0;
  uVar2 = 0x7fff;
  switch (operand->id)
  {
  case 1:
    uVar2 = *(uint *)(operand->data + 8);
    break;
  case 2:
    uVar2 = EVENT_GetInstanceValue((InstanceObject *)operand->data);
    break;
  case 3:
    uVar2 = EVENT_GetGameValue((GameObject *)operand->data);
    break;
  case 4:
    uVar2 = EVENT_GetIntroValue((IntroObject *)operand->data);
    break;
  case 7:
    uVar2 = *(uint *)operand->data;
    *flags = *(short *)(operand->data + 8);
    break;
  case 10:
    uVar2 = SEXT24(**(short **)operand->data);
    break;
  case 0xb:
    uVar2 = **(uint **)operand->data;
    break;
  case 0xf:
    uVar2 = EVENT_GetSplineValue((InstanceSpline *)operand->data);
    break;
  case 0x13:
    uVar2 = EVENT_GetAnimateValue((InstanceAnimate *)operand->data);
    break;
  case 0x14:
    uVar2 = EVENT_GetAnimateTextureValue((InstanceAnimateTexture *)operand->data);
    break;
  case 0x17:
    uVar2 = EVENT_GetTGroupValue((TGroupObject *)operand->data);
    break;
  case 0x18:
    uVar2 = (uint)((int)*(short *)(*(int *)operand->data + 0x150) + 1U < 3) ^ 1;
    break;
  case 0x1a:
    uVar2 = EVENT_GetVMObjectValue((EventVmObject *)operand->data);
    break;
  case 0x1b:
    if (*(short *)operand->data != 1)
    {
      lVar1 = EVENT_GetSoundValue((SoundObject *)operand->data);
      return lVar1;
    }
  case 0x15:
    uVar2 = 0;
    break;
  case 0x1c:
    uVar2 = (uint) * *(byte **)operand->data;
  }
  return uVar2;
}

// decompiled code
// original method signature:
// long /*$ra*/ EVENT_TransformOperand(struct StackType *stackObject /*$t0*/, struct _PCodeStack *stack /*$a0*/, long item /*$a2*/, short *codeStream /*$a3*/)
// line 7428, offset 0x80068558
/* begin block 1 */
// Start line: 7429
// Start offset: 0x80068558
// Variables:
// 		long retValue; // $v0
/* end block 1 */
// End offset: 0x800686F0
// End Line: 7522

/* begin block 2 */
// Start line: 16544
/* end block 2 */
// End Line: 16545

long EVENT_TransformOperand(StackType *stackObject, _PCodeStack *stack, long item, short *codeStream)

{
  long lVar1;

  switch (stackObject->id)
  {
  case 1:
    lVar1 = EVENT_TransformAreaAttribute(stack, stackObject, item, codeStream);
    break;
  case 2:
    lVar1 = EVENT_TransformInstanceAttribute(stack, stackObject, item, codeStream);
    break;
  case 3:
    lVar1 = EVENT_TransformGameAttribute(stack, stackObject, item, codeStream);
    break;
  case 4:
    lVar1 = EVENT_TransformIntroAttribute(stack, stackObject, item);
    break;
  default:
    lVar1 = 0;
    break;
  case 6:
    EventAbortLine = 1;
    lVar1 = 1;
    break;
  case 9:
    lVar1 = EVENT_TransformVector3dAttribute(stack, stackObject, item, codeStream);
    break;
  case 0xe:
    lVar1 = EVENT_TransformRotation3dAttribute(stack, stackObject, item, codeStream);
    break;
  case 0xf:
    lVar1 = EVENT_TransformSplineAttribute(stack, stackObject, item, codeStream);
    break;
  case 0x10:
    lVar1 = EVENT_TransformEventAttribute(stack, stackObject, item, codeStream);
    break;
  case 0x11:
    lVar1 = EVENT_TransformSignalAttribute(stack, stackObject, item);
    break;
  case 0x12:
    lVar1 = EVENT_TransformListObjectAttribute(stack, stackObject, item);
    break;
  case 0x13:
    lVar1 = 0;
    if (*(int *)(stackObject->data + 4) == -1)
    {
      *(long *)(stackObject->data + 4) = item;
      lVar1 = 1;
    }
    break;
  case 0x14:
    if (*(int *)(stackObject->data + 8) != -1)
    {
      return 0;
    }
  case 0x1a:
    *(long *)(stackObject->data + 8) = item;
    lVar1 = 1;
    break;
  case 0x15:
    lVar1 = EVENT_TransformSavedEventAttribute(stack, stackObject, item, codeStream);
    break;
  case 0x16:
    lVar1 = EVENT_TransformSubListObjectAttribute(stack, stackObject, item);
    break;
  case 0x17:
    lVar1 = EVENT_TransformTGroupAttribute(stack, stackObject, item, codeStream);
    break;
  case 0x18:
    lVar1 = EVENT_TransformConstrictAttribute(stack, stackObject, item);
    break;
  case 0x19:
    lVar1 = EVENT_TransformCameraObjectAttribute(stack, stackObject, item, codeStream);
    break;
  case 0x1b:
    lVar1 = EVENT_TransformSoundObjectAttribute(stack, (SoundObject *)stackObject->data, item, codeStream);
  }
  return lVar1;
}
