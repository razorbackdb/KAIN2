
#include "EVENT.H"


// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_UpdateResetSignalArray(struct Level *oldLevel /*$a0*/, struct Level *newLevel /*$a1*/, long sizeOfLevel /*$a2*/)
 // line 149, offset 0x80060c74
	/* begin block 1 */
		// Start line: 151
		// Start offset: 0x80060C74
		// Variables:
	// 		long offset; // $a1
	// 		long i; // $t0
	/* end block 1 */
	// End offset: 0x80060CE0
	// End Line: 170

	/* begin block 2 */
		// Start line: 298
	/* end block 2 */
	// End Line: 299

	/* begin block 3 */
		// Start line: 299
	/* end block 3 */
	// End Line: 300

	/* begin block 4 */
		// Start line: 301
	/* end block 4 */
	// End Line: 302

/* File: C:\kain2\game\EVENT.C */

void EVENT_UpdateResetSignalArray(Level *oldLevel,Level *newLevel,long sizeOfLevel)

{
  Level *pLVar1;
  Level *pLVar2;
  Level **ppLVar3;
  int iVar4;
  
  if (NumSignalsToReset != 0) {
    iVar4 = 0;
    ppLVar3 = (Level **)&ResetSignalArray;
    do {
      if (0 < (int)ppLVar3[1]) {
        pLVar2 = *ppLVar3;
        if ((oldLevel <= pLVar2) && (pLVar2 <= (Level *)((int)&oldLevel->terrain + sizeOfLevel))) {
          pLVar1 = (Level *)0x0;
          if (pLVar2 != (Level *)0x0) {
            pLVar1 = (Level *)((int)pLVar2 + (int)((int)newLevel - (int)oldLevel));
          }
          *ppLVar3 = pLVar1;
        }
      }
      iVar4 = iVar4 + 1;
      ppLVar3 = ppLVar3 + 2;
    } while (iVar4 < 0x10);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_ResetAllOneTimeVariables()
 // line 173, offset 0x80060ce8
	/* begin block 1 */
		// Start line: 175
		// Start offset: 0x80060CE8
		// Variables:
	// 		int i; // $a2
	/* end block 1 */
	// End offset: 0x80060D4C
	// End Line: 195

	/* begin block 2 */
		// Start line: 353
	/* end block 2 */
	// End Line: 354

	/* begin block 3 */
		// Start line: 354
	/* end block 3 */
	// End Line: 355

	/* begin block 4 */
		// Start line: 357
	/* end block 4 */
	// End Line: 358

/* File: C:\kain2\game\EVENT.C */

void EVENT_ResetAllOneTimeVariables(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  if (NumSignalsToReset != 0) {
    piVar2 = &ResetSignalArray;
    do {
      iVar1 = piVar2[1] + -1;
      if ((0 < piVar2[1]) && (piVar2[1] = iVar1, iVar1 == 0)) {
        NumSignalsToReset = NumSignalsToReset + -1;
        *(ushort *)(*piVar2 + 6) = *(ushort *)(*piVar2 + 6) & 0xfffe;
        piVar2[1] = 0;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 2;
    } while (iVar3 < 0x10);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_AddSignalToReset(struct _MultiSignal *mSignal /*$a0*/)
 // line 197, offset 0x80060d54
	/* begin block 1 */
		// Start line: 199
		// Start offset: 0x80060D54
		// Variables:
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x80060DAC
	// End Line: 222

	/* begin block 2 */
		// Start line: 413
	/* end block 2 */
	// End Line: 414

	/* begin block 3 */
		// Start line: 414
	/* end block 3 */
	// End Line: 415

	/* begin block 4 */
		// Start line: 416
	/* end block 4 */
	// End Line: 417

/* File: C:\kain2\game\EVENT.C */

void EVENT_AddSignalToReset(_MultiSignal *mSignal)

{
  _MultiSignal **pp_Var1;
  int iVar2;
  
  iVar2 = 0;
  if (NumSignalsToReset < 0x10) {
    pp_Var1 = (_MultiSignal **)&ResetSignalArray;
    while (iVar2 = iVar2 + 1, pp_Var1[1] != (_MultiSignal *)0x0) {
      pp_Var1 = pp_Var1 + 2;
      if (0xf < iVar2) {
        return;
      }
    }
    pp_Var1[1] = (_MultiSignal *)0x1;
    *pp_Var1 = mSignal;
    NumSignalsToReset = NumSignalsToReset + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HINT_ResetHint()
 // line 244, offset 0x80060db4
	/* begin block 1 */
		// Start line: 516
	/* end block 1 */
	// End Line: 517

/* File: C:\kain2\game\EVENT.C */

void HINT_ResetHint(void)

{
  memset();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HINT_StartHint(short hintNumber /*$a0*/)
 // line 249, offset 0x80060de0
	/* begin block 1 */
		// Start line: 251
		// Start offset: 0x80060DE0
		// Variables:
	// 		int h; // $a1
	/* end block 1 */
	// End offset: 0x80060E08
	// End Line: 266

	/* begin block 2 */
		// Start line: 527
	/* end block 2 */
	// End Line: 528

	/* begin block 3 */
		// Start line: 528
	/* end block 3 */
	// End Line: 529

	/* begin block 4 */
		// Start line: 535
	/* end block 4 */
	// End Line: 536

/* File: C:\kain2\game\EVENT.C */

void HINT_StartHint(short hintNumber)

{
  gHintSystem.stringNumber = hintNumber + 0x37;
  if (0x35 < (ushort)hintNumber) {
    gHintSystem.stringNumber = 0x6c;
  }
  gHintSystem.flags = 3;
  gHintSystem.hintNumber = hintNumber;
  gHintSystem.fadeTimer = 0x1e000;
  gHintSystem.spawningUnitID = *(long *)(DAT_800d20f8 + 0x38);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HINT_StopHint()
 // line 272, offset 0x80060e2c
	/* begin block 1 */
		// Start line: 588
	/* end block 1 */
	// End Line: 589

	/* begin block 2 */
		// Start line: 593
	/* end block 2 */
	// End Line: 594

/* File: C:\kain2\game\EVENT.C */

void HINT_StopHint(void)

{
  uint uVar1;
  
  uVar1 = gHintSystem._0_4_;
  if ((gHintSystem._0_4_ & 1) == 0) {
    return;
  }
  if ((gHintSystem._0_4_ & 6) == 0) {
    gHintSystem._0_4_ = gHintSystem._0_4_ | 4;
    if ((uVar1 & 2) == 0) {
      gHintSystem.fadeTimer = 0x1e000;
      return;
    }
    gHintSystem._0_4_ = uVar1 & 0xfffffffd | 4;
    gHintSystem.fadeTimer = 0x1e000 - gHintSystem.fadeTimer;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HINT_KillSpecificHint(short hintNumber /*$a0*/)
 // line 297, offset 0x80060e94
	/* begin block 1 */
		// Start line: 639
	/* end block 1 */
	// End Line: 640

/* File: C:\kain2\game\EVENT.C */

void HINT_KillSpecificHint(short hintNumber)

{
  if (gHintSystem.hintNumber == hintNumber) {
    HINT_StopHint();
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ HINT_GetCurrentHint()
 // line 305, offset 0x80060ec4
	/* begin block 1 */
		// Start line: 655
	/* end block 1 */
	// End Line: 656

	/* begin block 2 */
		// Start line: 656
	/* end block 2 */
	// End Line: 657

/* File: C:\kain2\game\EVENT.C */

long HINT_GetCurrentHint(void)

{
  long lVar1;
  
  lVar1 = -1;
  if ((gHintSystem.flags & 1U) != 0) {
    lVar1 = (long)gHintSystem.hintNumber;
  }
  return lVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_ProcessTimers()
 // line 317, offset 0x80060ee4
	/* begin block 1 */
		// Start line: 318
		// Start offset: 0x80060EE4
		// Variables:
	// 		int i; // $s2
	// 		struct EventTimer *eventTimer; // $s0
	/* end block 1 */
	// End offset: 0x80060FEC
	// End Line: 371

	/* begin block 2 */
		// Start line: 679
	/* end block 2 */
	// End Line: 680

	/* begin block 3 */
		// Start line: 689
	/* end block 3 */
	// End Line: 690

/* File: C:\kain2\game\EVENT.C */

void EVENT_ProcessTimers(void)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  EventTimer *timer;
  int iVar4;
  int iVar5;
  
  if (numActiveEventTimers != 0) {
    iVar5 = 0;
    iVar4 = 0;
    do {
      timer = (EventTimer *)((int)&eventTimerArray + iVar4);
      uVar2 = timer->flags;
      if ((uVar2 & 1) != 0) {
        if ((uint)((int)uVar2 >> 1) < DAT_800d2314) {
          timer->flags = uVar2 & 1;
        }
        else {
          timer->flags = uVar2 & 1 | (((int)uVar2 >> 1) - DAT_800d2314) * 2;
        }
        if (timer->flags >> 1 < 1) {
          iVar3 = *(int *)((int)&DAT_800d2ec8 + iVar4);
          currentEventInstance = *(Event **)((int)&DAT_800d2ec4 + iVar4);
          timer->flags = timer->flags & 1;
          *(ushort *)(iVar3 + 2) = *(ushort *)(iVar3 + 2) & 0xfffe;
          EVENT_RemoveTimer(timer);
          CurrentPuzzleLevel = *(undefined4 *)((int)&DAT_800d2ed0 + iVar4);
          EventCurrentEventIndex = *(long *)((int)&DAT_800d2ed4 + iVar4);
          EventAbortLine = 0;
          lVar1 = EVENT_DoAction(*(Event **)((int)&DAT_800d2ec4 + iVar4),
                                 *(ScriptPCode **)((int)&DAT_800d2ec8 + iVar4),
                                 *(short **)((int)&DAT_800d2ecc + iVar4));
          if ((lVar1 != 0) && (EventCurrentEventIndex != -1)) {
            EVENT_Process(*(Event **)((int)&DAT_800d2ec4 + iVar4),EventCurrentEventIndex);
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
 // line 372, offset 0x80061004
	/* begin block 1 */
		// Start line: 373
		// Start offset: 0x80061004

		/* begin block 1.1 */
			// Start line: 378
			// Start offset: 0x8006101C
			// Variables:
		// 		char string[128]; // stack offset -136
		// 		long y; // $s0
		/* end block 1.1 */
		// End offset: 0x800611B8
		// End Line: 445
	/* end block 1 */
	// End offset: 0x800611B8
	// End Line: 446

	/* begin block 2 */
		// Start line: 842
	/* end block 2 */
	// End Line: 843

	/* begin block 3 */
		// Start line: 845
	/* end block 3 */
	// End Line: 846

/* File: C:\kain2\game\EVENT.C */

void EVENT_ProcessHints(void)

{
  bool bVar1;
  char *pcVar2;
  int len;
  long y;
  char acStack136 [128];
  
  if ((gHintSystem.flags & 1U) != 0) {
    pcVar2 = localstr_get((int)gHintSystem.stringNumber);
    sprintf(acStack136,(char *)&PTR_LAB_000a7324_1_800d0794,pcVar2);
    if ((gHintSystem.flags & 2U) == 0) {
      y = 200;
      if ((gHintSystem.flags & 4U) != 0) {
        y = 0xfc - (gHintSystem.fadeTimer * 0x34) / 0x1e000;
      }
    }
    else {
      y = (gHintSystem.fadeTimer * 0x34) / 0x1e000 + 200;
    }
    FONT_FontPrintCentered(acStack136,y);
    FONT_FontPrintCentered(&DAT_800d0798,y);
    len = FONT_GetStringWidth(acStack136);
    DisplayHintBox(len,y);
    if ((gHintSystem.fadeTimer != 0) &&
       (bVar1 = (uint)gHintSystem.fadeTimer <= DAT_800d2314,
       gHintSystem.fadeTimer = gHintSystem.fadeTimer - DAT_800d2314, bVar1)) {
      gHintSystem.fadeTimer = 0;
      if ((gHintSystem.flags & 2U) == 0) {
        if ((gHintSystem.flags & 4U) != 0) {
          gHintSystem.flags = 0;
          gHintSystem.hintNumber = -1;
          gHintSystem.stringNumber = -1;
        }
      }
      else {
        gHintSystem.flags = gHintSystem.flags & 0xfffd;
      }
    }
    if (gHintSystem.spawningUnitID != *(int *)(DAT_800d20f8 + 0x38)) {
      HINT_StopHint();
    }
    if ((DAT_800d220c & 0x10) != 0) {
      HINT_StopHint();
    }
  }
  return;
}



// decompiled code
// original method signature: 
// struct EventTimer * /*$ra*/ EVENT_GetNextTimer()
 // line 448, offset 0x800611c8
	/* begin block 1 */
		// Start line: 449
		// Start offset: 0x800611C8
		// Variables:
	// 		int i; // $a0

		/* begin block 1.1 */
			// Start line: 454
			// Start offset: 0x800611DC
			// Variables:
		// 		struct EventTimer *eventTimer; // $v1
		/* end block 1.1 */
		// End offset: 0x8006122C
		// End Line: 466
	/* end block 1 */
	// End offset: 0x80061230
	// End Line: 468

	/* begin block 2 */
		// Start line: 999
	/* end block 2 */
	// End Line: 1000

	/* begin block 3 */
		// Start line: 1002
	/* end block 3 */
	// End Line: 1003

/* File: C:\kain2\game\EVENT.C */

EventTimer * EVENT_GetNextTimer(void)

{
  EventTimer *pEVar1;
  int iVar2;
  
  if (numActiveEventTimers < 0x18) {
    pEVar1 = (EventTimer *)&eventTimerArray;
    iVar2 = 0x18;
    do {
      iVar2 = iVar2 + -1;
      if ((pEVar1->flags & 1U) == 0) {
        numActiveEventTimers = numActiveEventTimers + 1;
        pEVar1->flags = pEVar1->flags & 0xfffffffeU | 1;
        return pEVar1;
      }
      pEVar1 = (EventTimer *)&pEVar1->nextEventIndex;
    } while (0 < iVar2);
  }
  return (EventTimer *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_RemoveTimer(struct EventTimer *timer /*$a0*/)
 // line 470, offset 0x80061238
	/* begin block 1 */
		// Start line: 1052
	/* end block 1 */
	// End Line: 1053

	/* begin block 2 */
		// Start line: 1053
	/* end block 2 */
	// End Line: 1054

/* File: C:\kain2\game\EVENT.C */

void EVENT_RemoveTimer(EventTimer *timer)

{
  if (timer != (EventTimer *)0x0) {
    numActiveEventTimers = numActiveEventTimers + -1;
    timer->flags = timer->flags & 0xfffffffe;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_InitTimers()
 // line 480, offset 0x80061268
	/* begin block 1 */
		// Start line: 1072
	/* end block 1 */
	// End Line: 1073

/* File: C:\kain2\game\EVENT.C */

void EVENT_InitTimers(void)

{
  numActiveEventTimers = 0;
  memset();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_InitTerrainMovement()
 // line 486, offset 0x80061298
	/* begin block 1 */
		// Start line: 487
		// Start offset: 0x80061298
		// Variables:
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x800612D4
	// End Line: 494

	/* begin block 2 */
		// Start line: 1086
	/* end block 2 */
	// End Line: 1087

/* File: C:\kain2\game\EVENT.C */

void EVENT_InitTerrainMovement(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    memset();
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  WaterInUse = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_Init()
 // line 497, offset 0x800612ec
	/* begin block 1 */
		// Start line: 1117
	/* end block 1 */
	// End Line: 1118

/* File: C:\kain2\game\EVENT.C */

void EVENT_Init(void)

{
  EVENT_InitTerrainMovement();
  EVENT_InitTimers();
  HINT_ResetHint();
  WaitingForVoiceNumber = -1;
  WaitingToLoadSound = 0x96000;
  return;
}



// decompiled code
// original method signature: 
// struct WaterLevelProcess * /*$ra*/ EVENT_GetNextTerrainMove()
 // line 506, offset 0x8006132c
	/* begin block 1 */
		// Start line: 508
		// Start offset: 0x8006132C
		// Variables:
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x80061360
	// End Line: 522

	/* begin block 2 */
		// Start line: 1136
	/* end block 2 */
	// End Line: 1137

	/* begin block 3 */
		// Start line: 1137
	/* end block 3 */
	// End Line: 1138

	/* begin block 4 */
		// Start line: 1140
	/* end block 4 */
	// End Line: 1141

/* File: C:\kain2\game\EVENT.C */

WaterLevelProcess * EVENT_GetNextTerrainMove(void)

{
  WaterLevelProcess *pWVar1;
  int iVar2;
  
  iVar2 = 0;
  pWVar1 = (WaterLevelProcess *)&WaterLevelArray;
  do {
    iVar2 = iVar2 + 1;
    if ((pWVar1->flags & 1U) == 0) {
      return pWVar1;
    }
    pWVar1 = pWVar1 + 1;
  } while (iVar2 < 5);
  return (WaterLevelProcess *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_ProcessMovingWater()
 // line 541, offset 0x80061368
	/* begin block 1 */
		// Start line: 543
		// Start offset: 0x80061368
		// Variables:
	// 		long i; // $a3
	// 		long inUse; // $t0

		/* begin block 1.1 */
			// Start line: 548
			// Start offset: 0x80061378
			// Variables:
		// 		struct WaterLevelProcess *curWater; // $a2
		/* end block 1.1 */
		// End offset: 0x8006148C
		// End Line: 577
	/* end block 1 */
	// End offset: 0x80061498
	// End Line: 583

	/* begin block 2 */
		// Start line: 1078
	/* end block 2 */
	// End Line: 1079

	/* begin block 3 */
		// Start line: 1193
	/* end block 3 */
	// End Line: 1194

	/* begin block 4 */
		// Start line: 1196
	/* end block 4 */
	// End Line: 1197

/* File: C:\kain2\game\EVENT.C */

void EVENT_ProcessMovingWater(void)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  int iVar6;
  
  bVar2 = false;
  if (WaterInUse != 0) {
    puVar5 = &WaterLevelArray;
    iVar6 = 5;
    piVar4 = &DAT_800d2e44;
    do {
      if ((*puVar5 & 1) != 0) {
        iVar3 = piVar4[1] + DAT_800d2314;
        piVar4[1] = iVar3;
        bVar2 = true;
        if (*piVar4 < iVar3) {
          piVar4[1] = *piVar4;
        }
        iVar3 = (((int)*(short *)((int)piVar4 + -2) - (int)*(short *)(piVar4 + -1)) *
                (piVar4[1] >> 0xc)) / (*piVar4 >> 0xc);
        sVar1 = (short)iVar3;
        *(short *)(piVar4[-4] + 0x10) = *(short *)((int)piVar4 + -6) + sVar1;
        *(short *)(piVar4[-4] + 0x18) = *(short *)(piVar4 + -1) + sVar1;
        if ((*puVar5 & 2) != 0) {
          *(int *)(*(int *)(piVar4[-3] + 8) + 0x38) = *(short *)(piVar4 + -2) + iVar3;
          ***(ushort ***)(piVar4[-3] + 8) = ***(ushort ***)(piVar4[-3] + 8) | 1;
        }
        if (piVar4[1] == *piVar4) {
          *puVar5 = 0;
        }
      }
      iVar6 = iVar6 + -1;
      piVar4 = piVar4 + 7;
      puVar5 = puVar5 + 7;
    } while (0 < iVar6);
  }
  if (!bVar2) {
    WaterInUse = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_DoProcess()
 // line 585, offset 0x800614a0
	/* begin block 1 */
		// Start line: 1304
	/* end block 1 */
	// End Line: 1305

/* File: C:\kain2\game\EVENT.C */

void EVENT_DoProcess(void)

{
  EVENT_ProcessMovingWater();
  EVENT_ProcessTimers();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_BSPProcess(struct _StreamUnit *streamUnit /*$fp*/)
 // line 591, offset 0x800614c8
	/* begin block 1 */
		// Start line: 592
		// Start offset: 0x800614C8
		// Variables:
	// 		long curTree; // $s5
	// 		struct Level *level; // $v0
	// 		struct _Terrain *terrain; // $s6

		/* begin block 1.1 */
			// Start line: 604
			// Start offset: 0x8006151C
			// Variables:
		// 		struct BSPTree *bspTree; // $a3

			/* begin block 1.1.1 */
				// Start line: 612
				// Start offset: 0x80061538
				// Variables:
			// 		struct _Instance *instance; // $s1

				/* begin block 1.1.1.1 */
					// Start line: 616
					// Start offset: 0x80061548
					// Variables:
				// 		short dx; // $s4
				// 		short dy; // $s3
				// 		short dz; // $s2

					/* begin block 1.1.1.1.1 */
						// Start line: 633
						// Start offset: 0x800615CC
						// Variables:
					// 		struct _Instance *attachedInstance; // $s0
					// 		struct SVECTOR offset; // stack offset -48
					/* end block 1.1.1.1.1 */
					// End offset: 0x800616B4
					// End Line: 664
				/* end block 1.1.1.1 */
				// End offset: 0x800616B4
				// End Line: 667
			/* end block 1.1.1 */
			// End offset: 0x800616B4
			// End Line: 668
		/* end block 1.1 */
		// End offset: 0x800616B4
		// End Line: 669
	/* end block 1 */
	// End offset: 0x800616C8
	// End Line: 671

	/* begin block 2 */
		// Start line: 1316
	/* end block 2 */
	// End Line: 1317

/* File: C:\kain2\game\EVENT.C */

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
  
  p_Var10 = streamUnit->level->terrain;
  iVar9 = 0;
  if (0 < p_Var10->numBSPTrees) {
    iVar11 = 0;
    do {
      iVar4 = (int)&p_Var10->BSPTreeArray->bspRoot + iVar11;
      if ((-1 < *(short *)(iVar4 + 0x1a)) && (iVar5 = *(int *)(iVar4 + 0x20), iVar5 != 0)) {
        iVar2 = *(int *)(iVar5 + 0x40);
        if ((iVar2 == 0) || (iVar3 = *(int *)(iVar5 + 0x44), iVar3 == 0)) {
          sVar6 = *(short *)(iVar5 + 0x60);
          sVar8 = *(short *)(iVar5 + 0x5c) - *(short *)(iVar5 + 100);
          sVar1 = *(short *)(iVar5 + 0x68);
          sVar7 = *(short *)(iVar5 + 0x5e) - *(short *)(iVar5 + 0x66);
        }
        else {
          sVar6 = *(short *)(iVar2 + 0x1c);
          sVar8 = *(short *)(iVar2 + 0x14) - *(short *)(iVar3 + 0x14);
          sVar1 = *(short *)(iVar3 + 0x1c);
          sVar7 = *(short *)(iVar2 + 0x18) - *(short *)(iVar3 + 0x18);
        }
        sVar6 = sVar6 - sVar1;
        if (((sVar8 != 0) || (sVar7 != 0)) || (sVar6 != 0)) {
          *(short *)(iVar4 + 0xc) = *(short *)(iVar4 + 0xc) + sVar8;
          *(short *)(iVar4 + 0xe) = *(short *)(iVar4 + 0xe) + sVar7;
          *(short *)(iVar4 + 0x10) = *(short *)(iVar4 + 0x10) + sVar6;
          *(short *)(iVar4 + 0x14) = *(short *)(iVar4 + 0x14) + sVar8;
          *(short *)(iVar4 + 0x16) = *(short *)(iVar4 + 0x16) + sVar7;
          *(short *)(iVar4 + 0x18) = *(short *)(iVar4 + 0x18) + sVar6;
          p_Var10->UnitChangeFlags = p_Var10->UnitChangeFlags | 2;
          instance = *(_Instance **)(DAT_800d2100 + 4);
          while (instance != (_Instance *)0x0) {
            if (((*(int *)(iVar5 + 0x8c) == 0) &&
                (instance->currentStreamUnitID == streamUnit->StreamUnitID)) &&
               (instance->bspTree == iVar9)) {
              (instance->position).x = (instance->position).x + sVar8;
              (instance->position).z = (instance->position).z + sVar6;
              (instance->position).y = (instance->position).y + sVar7;
              COLLIDE_UpdateAllTransforms(instance,0xd0);
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
 // line 673, offset 0x800616f8
	/* begin block 1 */
		// Start line: 674
		// Start offset: 0x800616F8
		// Variables:
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x80061840
	// End Line: 763

	/* begin block 2 */
		// Start line: 1578
	/* end block 2 */
	// End Line: 1579

/* File: C:\kain2\game\EVENT.C */

void EVENT_Process(Event *eventInstance,long startIndex)

{
  long lVar1;
  ScriptPCode **ppSVar2;
  ScriptPCode *actionScript;
  int iVar3;
  
  iVar3 = startIndex << 2;
  currentEventInstance = (Event *)eventInstance;
  if (startIndex < (int)(uint)eventInstance->numActions) {
    do {
      EventCurrentEventIndex = startIndex + 1;
      if (EventCurrentEventIndex == (uint)eventInstance->numActions) {
        EventCurrentEventIndex = -1;
      }
      if (*(int *)(iVar3 + (int)eventInstance->conditionalList) == 0) {
LAB_800617e0:
        if ((*(ushort *)(*(int *)(iVar3 + (int)eventInstance->actionList) + 2) & 2) == 0) {
          actionScript = *(ScriptPCode **)(iVar3 + (int)eventInstance->actionList);
          EventAbortLine = 0;
          EVENT_DoAction(eventInstance,actionScript,actionScript->data);
        }
      }
      else {
        EventAbortLine = 0;
        CurrentEventLine = 0;
        lVar1 = EVENT_IsConditionTrue
                          (eventInstance,
                           *(ScriptPCode **)(iVar3 + (int)eventInstance->conditionalList));
        if (lVar1 != 0) {
          if (*(int *)(iVar3 + (int)eventInstance->actionList) == 0) {
            ppSVar2 = eventInstance->actionList + startIndex;
            do {
              ppSVar2 = ppSVar2 + 1;
              if ((int)(uint)eventInstance->numActions <= startIndex) goto LAB_8006182c;
              iVar3 = iVar3 + 4;
              startIndex = startIndex + 1;
            } while (*ppSVar2 == (ScriptPCode *)0x0);
          }
          if (startIndex < (int)(uint)eventInstance->numActions) goto LAB_800617e0;
        }
      }
LAB_8006182c:
      startIndex = startIndex + 1;
      iVar3 = iVar3 + 4;
    } while (startIndex < (int)(uint)eventInstance->numActions);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_ProcessPuppetShow(struct Event *eventInstance /*$s1*/, long startIndex /*$a1*/)
 // line 765, offset 0x80061858
	/* begin block 1 */
		// Start line: 766
		// Start offset: 0x80061858
		// Variables:
	// 		long i; // $s0
	// 		long conditionIsStatisfied; // $s3
	/* end block 1 */
	// End offset: 0x80061A14
	// End Line: 829

	/* begin block 2 */
		// Start line: 1820
	/* end block 2 */
	// End Line: 1821

/* File: C:\kain2\game\EVENT.C */

void EVENT_ProcessPuppetShow(Event *eventInstance,long startIndex)

{
  bool bVar1;
  long lVar2;
  ScriptPCode **ppSVar3;
  ScriptPCode *actionScript;
  char cVar4;
  
  cVar4 = (char)startIndex;
  EventJustRecievedTimer = 0;
  bVar1 = true;
  if ((eventInstance->actionList[startIndex]->conditionBits & 2) != 0) {
    EventJustRecievedTimer = 0;
    currentEventInstance = (Event *)eventInstance;
    return;
  }
  EventCurrentEventIndex = startIndex + 1;
  if (EventCurrentEventIndex == (uint)eventInstance->numActions) {
    EventCurrentEventIndex = -1;
  }
  currentEventInstance = (Event *)eventInstance;
  if (eventInstance->conditionalList[startIndex] == (ScriptPCode *)0x0) {
    if ((eventInstance->actionList[startIndex]->conditionBits & 2) != 0) goto LAB_800619c8;
    actionScript = eventInstance->actionList[startIndex];
  }
  else {
    EventAbortLine = 0;
    CurrentEventLine = 0;
    lVar2 = EVENT_IsConditionTrue(eventInstance,eventInstance->conditionalList[startIndex]);
    if (lVar2 == 0) {
      bVar1 = false;
      goto LAB_800619c8;
    }
    ppSVar3 = eventInstance->actionList + startIndex;
    if (*ppSVar3 == (ScriptPCode *)0x0) {
      do {
        cVar4 = (char)startIndex;
        ppSVar3 = ppSVar3 + 1;
        if ((int)(uint)eventInstance->numActions <= startIndex) goto LAB_800619c8;
        startIndex = startIndex + 1;
      } while (*ppSVar3 == (ScriptPCode *)0x0);
    }
    cVar4 = (char)startIndex;
    if ((int)(uint)eventInstance->numActions <= startIndex) goto LAB_800619c8;
    actionScript = eventInstance->actionList[startIndex];
  }
  EventAbortLine = 0;
  EVENT_DoAction(eventInstance,actionScript,actionScript->data);
LAB_800619c8:
  if ((((EventAbortLine == 0) || (EventJustRecievedTimer == 1)) && (bVar1)) &&
     (eventInstance->processingPuppetShow = cVar4 + '\x02',
     (uint)eventInstance->numActions + 1 <= (uint)eventInstance->processingPuppetShow)) {
    eventInstance->processingPuppetShow = '\0';
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_ProcessEvents(struct EventPointers *eventPointers /*$s2*/, struct Level *level /*$a1*/)
 // line 831, offset 0x80061a30
	/* begin block 1 */
		// Start line: 832
		// Start offset: 0x80061A30
		// Variables:
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x80061AB8
	// End Line: 853

	/* begin block 2 */
		// Start line: 1963
	/* end block 2 */
	// End Line: 1964

/* File: C:\kain2\game\EVENT.C */

void EVENT_ProcessEvents(EventPointers *eventPointers,Level *level)

{
  Event *eventInstance;
  int iVar1;
  EventPointers *pEVar2;
  
  iVar1 = 0;
  pEVar2 = eventPointers;
  CurrentPuzzleLevel = level;
  if (0 < eventPointers->numPuzzles) {
    do {
      eventInstance = (Event *)pEVar2->eventInstances[0];
      if (eventInstance->eventNumber < 0) {
        if (eventInstance->processingPuppetShow != 0) {
          EVENT_ProcessPuppetShow(eventInstance,(uint)eventInstance->processingPuppetShow - 1);
        }
      }
      else {
        EVENT_Process(eventInstance,0);
      }
      iVar1 = iVar1 + 1;
      pEVar2 = (EventPointers *)pEVar2->eventInstances;
    } while (iVar1 < eventPointers->numPuzzles);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoAction(struct Event *eventInstance /*$s4*/, struct ScriptPCode *actionScript /*$s1*/, short *scriptData /*$s0*/)
 // line 855, offset 0x80061ad0
	/* begin block 1 */
		// Start line: 856
		// Start offset: 0x80061AD0
		// Variables:
	// 		long retValue; // $s3
	// 		long operateOnStack; // stack offset -32
	// 		struct _PCodeStack stack; // stack offset -1192

		/* begin block 1.1 */
			// Start line: 872
			// Start offset: 0x80061B64
			// Variables:
		// 		struct EventTimer *timer; // $a1
		/* end block 1.1 */
		// End offset: 0x80061BB4
		// End Line: 892
	/* end block 1 */
	// End offset: 0x80061C24
	// End Line: 905

	/* begin block 2 */
		// Start line: 2023
	/* end block 2 */
	// End Line: 2024

/* File: C:\kain2\game\EVENT.C */

long EVENT_DoAction(Event *eventInstance,ScriptPCode *actionScript,short *scriptData)

{
  long lVar1;
  short *psVar2;
  EventTimer *pEVar3;
  int iVar4;
  long lVar5;
  _PCodeStack local_4a8;
  long local_20 [2];
  
  local_4a8.topOfStack = 0;
  EventJustRecievedTimer = 0;
  lVar5 = 1;
  currentActionScript = (ScriptPCode *)actionScript;
  EventAbortedPosition = scriptData;
  if ((((actionScript->conditionBits & 1) == 0) && (lVar5 = 1, scriptData != (short *)0x0)) &&
     (lVar5 = 1, EventAbortLine == 0)) {
    lVar5 = 1;
    do {
      scriptData = EVENT_ParseOpcode(&local_4a8,scriptData,local_20);
      if (((EventAbortLine != 0) && (EventJustRecievedTimer == 0)) &&
         (pEVar3 = EVENT_GetNextTimer(), psVar2 = EventAbortedPosition,
         lVar1 = EventCurrentEventIndex, pEVar3 != (EventTimer *)0x0)) {
        lVar5 = 0;
        *(Event **)&pEVar3->time = eventInstance;
        *(ScriptPCode **)&pEVar3->event = actionScript;
        pEVar3->flags = pEVar3->flags & 1;
        *(short **)&pEVar3->actionScript = psVar2;
        psVar2 = CurrentPuzzleLevel;
        actionScript->conditionBits = actionScript->conditionBits | 1;
        pEVar3->scriptPos = psVar2;
        *(long *)&pEVar3->level = lVar1;
      }
      if (((local_20[0] != 0) && (EventAbortLine == 0)) &&
         (iVar4 = local_4a8.topOfStack + -1, 0 < local_4a8.topOfStack)) {
        local_4a8.topOfStack = iVar4;
        EVENT_ExecuteActionCommand(local_4a8.stack + iVar4,(StackType *)0x0,&local_4a8,scriptData);
      }
    } while ((scriptData != (short *)0x0) && (EventAbortLine == 0));
  }
  return lVar5;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_IsConditionTrue(struct Event *eventInstance /*$a0*/, struct ScriptPCode *conditionScript /*$a1*/)
 // line 909, offset 0x80061c48
	/* begin block 1 */
		// Start line: 910
		// Start offset: 0x80061C48
		// Variables:
	// 		long retValue; // $s0
	// 		long error; // stack offset -28
	// 		long operateOnStack; // stack offset -32
	// 		short flags; // stack offset -24
	// 		struct _PCodeStack stack; // stack offset -1192
	// 		short *scriptData; // $s1
	/* end block 1 */
	// End offset: 0x80061D20
	// End Line: 965

	/* begin block 2 */
		// Start line: 2149
	/* end block 2 */
	// End Line: 2150

/* File: C:\kain2\game\EVENT.C */

long EVENT_IsConditionTrue(Event *eventInstance,ScriptPCode *conditionScript)

{
  int iVar1;
  long lVar2;
  short *codeStream;
  _PCodeStack local_4a8;
  long local_20;
  long local_1c;
  short asStack24 [4];
  
  local_4a8.topOfStack = 0;
  codeStream = conditionScript->data;
  currentActionScript = (ScriptPCode *)0x0;
  lVar2 = 0;
  while( true ) {
    do {
      do {
        if ((codeStream == (short *)0x0) || (EventAbortLine != 0)) goto LAB_80061d0c;
        codeStream = EVENT_ParseOpcode(&local_4a8,codeStream,&local_20);
      } while ((local_20 == 0) || (EventAbortLine != 0));
      CurrentEventLine = CurrentEventLine + 1;
      iVar1 = local_4a8.topOfStack + -1;
    } while (local_4a8.topOfStack < 1);
    local_4a8.topOfStack = iVar1;
    lVar2 = EVENT_GetScalerValueFromOperand(local_4a8.stack + iVar1,&local_1c,asStack24);
    if (local_1c != 0) break;
    if (lVar2 == 0) {
LAB_80061d0c:
      if (EventAbortLine == 1) {
        lVar2 = 0;
      }
      return lVar2;
    }
  }
  lVar2 = 0;
  goto LAB_80061d0c;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_WriteEventObject(struct StackType *stackEntry /*$s0*/, long areaID /*$s1*/, struct Event *event /*$a2*/, long number /*$s2*/)
 // line 968, offset 0x80061d38
	/* begin block 1 */
		// Start line: 969
		// Start offset: 0x80061D38
		// Variables:
	// 		long retValue; // $a0

		/* begin block 1.1 */
			// Start line: 984
			// Start offset: 0x80061D74
			// Variables:
		// 		struct SavedBasic *savedEvent; // $v1
		/* end block 1.1 */
		// End offset: 0x80061DCC
		// End Line: 1008
	/* end block 1 */
	// End offset: 0x80061DCC
	// End Line: 1011

	/* begin block 2 */
		// Start line: 2288
	/* end block 2 */
	// End Line: 2289

/* File: C:\kain2\game\EVENT.C */

long EVENT_WriteEventObject(StackType *stackEntry,long areaID,Event *event,long number)

{
  SavedBasic *pSVar1;
  long lVar2;
  
  lVar2 = 0;
  if (event == (Event *)0x0) {
    pSVar1 = SAVE_GetSavedEvent(areaID,number);
    if (pSVar1 == (SavedBasic *)0x0) {
      stackEntry->id = 0x15;
      pSVar1 = EVENT_CreateSaveEvent(areaID,number);
      *(SavedBasic **)stackEntry->data = pSVar1;
    }
    else {
      stackEntry->id = 0x15;
      *(SavedBasic **)stackEntry->data = pSVar1;
    }
    lVar2 = 1;
    *(long *)(stackEntry->data + 8) = areaID;
    *(long *)(stackEntry->data + 0xc) = number;
  }
  else {
    stackEntry->id = 0x10;
    *(Event **)stackEntry->data = event;
  }
  *(undefined4 *)(stackEntry->data + 4) = 0xffffffff;
  return lVar2;
}



// decompiled code
// original method signature: 
// struct _MultiSignal * /*$ra*/ EVENT_ResolveObjectSignal(struct _StreamUnit *stream /*$a0*/, long signalNumber /*$a1*/)
 // line 1014, offset 0x80061de8
	/* begin block 1 */
		// Start line: 1015
		// Start offset: 0x80061DE8
		// Variables:
	// 		struct _MultiSignal *retValue; // $a2
	// 		struct Level *level; // $a0
	/* end block 1 */
	// End offset: 0x80061E70
	// End Line: 1070

	/* begin block 2 */
		// Start line: 2389
	/* end block 2 */
	// End Line: 2390

/* File: C:\kain2\game\EVENT.C */

_MultiSignal * EVENT_ResolveObjectSignal(_StreamUnit *stream,long signalNumber)

{
  Level *level;
  _MultiSignal *p_Var1;
  
  level = stream->level;
  p_Var1 = (_MultiSignal *)0x0;
  if (signalNumber < 0) {
    switch(signalNumber) {
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
  else {
    p_Var1 = SIGNAL_FindSignal(level,signalNumber);
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct Intro * /*$ra*/ EVENT_ResolveObjectIntro(struct EventInstanceObject *instanceObject /*$v0*/)
 // line 1073, offset 0x80061e80
	/* begin block 1 */
		// Start line: 1074
		// Start offset: 0x80061E80
	/* end block 1 */
	// End offset: 0x80061E80
	// End Line: 1074

	/* begin block 2 */
		// Start line: 2508
	/* end block 2 */
	// End Line: 2509

/* File: C:\kain2\game\EVENT.C */

Intro * EVENT_ResolveObjectIntro(EventInstanceObject *instanceObject)

{
  Intro *pIVar1;
  
  pIVar1 = INSTANCE_FindIntro(instanceObject->unitID,instanceObject->introUniqueID);
  return pIVar1;
}



// decompiled code
// original method signature: 
// struct _SFXMkr * /*$ra*/ EVENT_ResolveSFXMarker(struct _StreamUnit *stream /*$a0*/, struct EventInstanceObject *instanceObject /*$a1*/)
 // line 1084, offset 0x80061eac
	/* begin block 1 */
		// Start line: 1086
		// Start offset: 0x80061EAC
		// Variables:
	// 		int i; // $a0
	// 		struct Level *level; // $t0
	// 		struct _SFXMkr *result; // $a2
	/* end block 1 */
	// End offset: 0x80061F04
	// End Line: 1104

	/* begin block 2 */
		// Start line: 2530
	/* end block 2 */
	// End Line: 2531

	/* begin block 3 */
		// Start line: 2531
	/* end block 3 */
	// End Line: 2532

	/* begin block 4 */
		// Start line: 2535
	/* end block 4 */
	// End Line: 2536

/* File: C:\kain2\game\EVENT.C */

_SFXMkr * EVENT_ResolveSFXMarker(_StreamUnit *stream,EventInstanceObject *instanceObject)

{
  int iVar1;
  _SFXMkr *p_Var2;
  int iVar3;
  
  iVar1 = stream->level->NumberOfSFXMarkers;
  if ((iVar1 != 0) && (iVar3 = 0, 0 < iVar1)) {
    p_Var2 = stream->level->SFXMarkerList;
    do {
      iVar3 = iVar3 + 1;
      if (instanceObject->introUniqueID == p_Var2->uniqueID) {
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
 // line 1107, offset 0x80061f0c
	/* begin block 1 */
		// Start line: 1109
		// Start offset: 0x80061F0C

		/* begin block 1.1 */
			// Start line: 1111
			// Start offset: 0x80061F20
			// Variables:
		// 		struct StackType *stackEntry; // $v0
		/* end block 1.1 */
		// End offset: 0x80061F50
		// End Line: 1115
	/* end block 1 */
	// End offset: 0x80061F50
	// End Line: 1121

	/* begin block 2 */
		// Start line: 2586
	/* end block 2 */
	// End Line: 2587

	/* begin block 3 */
		// Start line: 2587
	/* end block 3 */
	// End Line: 2588

/* File: C:\kain2\game\EVENT.C */

void EVENT_AddGameObjectToStack(_PCodeStack *stack)

{
  int iVar1;
  
  iVar1 = stack->topOfStack;
  if (iVar1 < 0x20) {
    stack->stack[iVar1].id = 3;
    *(undefined4 *)stack->stack[iVar1].data = 0xffffffff;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_AddPlayerObjectToStack(struct _PCodeStack *stack /*$a1*/)
 // line 1123, offset 0x80061f58
	/* begin block 1 */
		// Start line: 1124
		// Start offset: 0x80061F58

		/* begin block 1.1 */
			// Start line: 1127
			// Start offset: 0x80061F70
			// Variables:
		// 		struct StackType *stackEntry; // $v0
		/* end block 1.1 */
		// End offset: 0x80061FA8
		// End Line: 1132
	/* end block 1 */
	// End offset: 0x80061FA8
	// End Line: 1138

	/* begin block 2 */
		// Start line: 2618
	/* end block 2 */
	// End Line: 2619

/* File: C:\kain2\game\EVENT.C */

void EVENT_AddPlayerObjectToStack(_PCodeStack *stack)

{
  undefined4 uVar1;
  StackType *pSVar2;
  
  if (stack->topOfStack < 0x20) {
    pSVar2 = stack->stack + stack->topOfStack;
    pSVar2->id = 2;
    uVar1 = DAT_800d20f8;
    *(undefined4 *)(pSVar2->data + 4) = 0xffffffff;
    *(undefined4 *)pSVar2->data = uVar1;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_AddObjectToStack(struct _PCodeStack *stack /*$s2*/, long item /*$a1*/)
 // line 1140, offset 0x80061fb0
	/* begin block 1 */
		// Start line: 1141
		// Start offset: 0x80061FB0
		// Variables:
	// 		struct EventBasicObject *basicObject; // $a0
	// 		int topOfStack; // $s1

		/* begin block 1.1 */
			// Start line: 1153
			// Start offset: 0x80061FDC
			// Variables:
		// 		struct StackType *stackEntry; // $s0

			/* begin block 1.1.1 */
				// Start line: 1159
				// Start offset: 0x80062038
			/* end block 1.1.1 */
			// End offset: 0x80062058
			// End Line: 1175

			/* begin block 1.1.2 */
				// Start line: 1183
				// Start offset: 0x80062058
			/* end block 1.1.2 */
			// End offset: 0x8006208C
			// End Line: 1200

			/* begin block 1.1.3 */
				// Start line: 1215
				// Start offset: 0x800620A8
			/* end block 1.1.3 */
			// End offset: 0x800620A8
			// End Line: 1217

			/* begin block 1.1.4 */
				// Start line: 1225
				// Start offset: 0x800620C4
			/* end block 1.1.4 */
			// End offset: 0x800620C4
			// End Line: 1227

			/* begin block 1.1.5 */
				// Start line: 1235
				// Start offset: 0x800620E8
			/* end block 1.1.5 */
			// End offset: 0x80062174
			// End Line: 1285

			/* begin block 1.1.6 */
				// Start line: 1297
				// Start offset: 0x80062174
			/* end block 1.1.6 */
			// End offset: 0x800621C4
			// End Line: 1319
		/* end block 1.1 */
		// End offset: 0x800621C8
		// End Line: 1327
	/* end block 1 */
	// End offset: 0x800621C8
	// End Line: 1333

	/* begin block 2 */
		// Start line: 2653
	/* end block 2 */
	// End Line: 2654

/* File: C:\kain2\game\EVENT.C */

void EVENT_AddObjectToStack(_PCodeStack *stack,long item)

{
  long lVar1;
  Level *pLVar2;
  EventBasicObject EVar3;
  EventBasicObject *pEVar4;
  StackType *stackEntry;
  long lVar5;
  
  lVar1 = CurrentEventLine;
  lVar5 = stack->topOfStack;
  if (0x1f < lVar5) goto LAB_800621c8;
  pEVar4 = currentEventInstance->instanceList[item];
  stackEntry = stack->stack + lVar5;
  switch((int)(((uint)(ushort)pEVar4->id - 1) * 0x10000) >> 0x10) {
  case 0:
    if ((*(ushort *)&pEVar4->field_0x2 & 1) == 0) {
      if (pEVar4[3] == (EventBasicObject)0x0) {
        if (pEVar4[4] == (EventBasicObject)0x0) goto LAB_800621b0;
        stackEntry->id = 4;
        EVar3 = pEVar4[4];
      }
      else {
        stackEntry->id = 2;
        EVar3 = pEVar4[3];
      }
LAB_80062168:
      *(undefined4 *)(stackEntry->data + 4) = 0xffffffff;
      *(EventBasicObject *)stackEntry->data = EVar3;
    }
    else {
      stackEntry->id = 0x1b;
      *(undefined2 *)stackEntry->data = 1;
      EVar3 = pEVar4[4];
      *(undefined2 *)(stackEntry->data + 2) = 0xffff;
      *(undefined4 *)(stackEntry->data + 4) = 0xffffffff;
      *(undefined4 *)(stackEntry->data + 8) = 0xffffffff;
      *(undefined4 *)(stackEntry->data + 0xc) = 0xffffffff;
      *(EventBasicObject *)(stackEntry->data + 0x10) = EVar3;
    }
    break;
  case 1:
    stackEntry->id = 0x12;
    *(EventBasicObject **)stackEntry->data = pEVar4;
    *(undefined4 *)(stackEntry->data + 0x18) = 0;
    *(long *)(stackEntry->data + 0x1c) = lVar1;
    break;
  case 2:
    EVENT_WriteEventObject
              (stackEntry,(long)pEVar4[1],(Event *)pEVar4[2],(int)*(short *)&pEVar4->field_0x2);
    lVar5 = lVar5 + 1;
    goto LAB_800621c8;
  case 3:
    if (pEVar4[2] == (EventBasicObject)0x0) goto LAB_800621b0;
    stackEntry->id = 0x17;
    *(EventBasicObject *)stackEntry->data = pEVar4[2];
    EVar3 = pEVar4[3];
    *(undefined4 *)(stackEntry->data + 8) = 0xffffffff;
    *(EventBasicObject *)(stackEntry->data + 4) = EVar3;
    break;
  case 4:
    stackEntry->id = 1;
    EVar3 = pEVar4[2];
    *(undefined4 *)(stackEntry->data + 4) = 0xffffffff;
    *(EventBasicObject *)stackEntry->data = EVar3;
    *(EventBasicObject *)(stackEntry->data + 8) = pEVar4[1];
    break;
  case 5:
    if (pEVar4[2] != (EventBasicObject)0x0) {
      stackEntry->id = 0x11;
      EVar3 = pEVar4[2];
      goto LAB_80062168;
    }
    goto LAB_800621b0;
  case 6:
    if (pEVar4[5] != (EventBasicObject)0x0) {
      stackEntry->id = 0x1a;
      *(EventBasicObject *)stackEntry->data = pEVar4[5];
      lVar5 = lVar5 + 1;
      pLVar2 = STREAM_GetLevelWithID((long)pEVar4[1]);
      *(Level **)(stackEntry->data + 4) = pLVar2;
      *(undefined4 *)(stackEntry->data + 8) = 0xffffffff;
      goto LAB_800621c8;
    }
LAB_800621b0:
    stackEntry->id = 6;
    *(long *)stackEntry->data = item;
    *(undefined4 *)(stackEntry->data + 4) = 0xffffffff;
  }
  lVar5 = lVar5 + 1;
LAB_800621c8:
  stack->topOfStack = lVar5;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_AddCharPointerToStack(struct _PCodeStack *stack /*$a0*/, char *pointer /*$a1*/)
 // line 1340, offset 0x800621e4
	/* begin block 1 */
		// Start line: 1342
		// Start offset: 0x800621E4

		/* begin block 1.1 */
			// Start line: 1344
			// Start offset: 0x800621F8
			// Variables:
		// 		struct StackType *stackEntry; // $v0
		/* end block 1.1 */
		// End offset: 0x80062224
		// End Line: 1348
	/* end block 1 */
	// End offset: 0x80062224
	// End Line: 1354

	/* begin block 2 */
		// Start line: 3068
	/* end block 2 */
	// End Line: 3069

	/* begin block 3 */
		// Start line: 3069
	/* end block 3 */
	// End Line: 3070

/* File: C:\kain2\game\EVENT.C */

void EVENT_AddCharPointerToStack(_PCodeStack *stack,char *pointer)

{
  int iVar1;
  
  iVar1 = stack->topOfStack;
  if (iVar1 < 0x20) {
    stack->stack[iVar1].id = 0x1c;
    *(char **)stack->stack[iVar1].data = pointer;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_AddShortPointerToStack(struct _PCodeStack *stack /*$a0*/, short *pointer /*$a1*/)
 // line 1356, offset 0x8006222c
	/* begin block 1 */
		// Start line: 1358
		// Start offset: 0x8006222C

		/* begin block 1.1 */
			// Start line: 1360
			// Start offset: 0x80062240
			// Variables:
		// 		struct StackType *stackEntry; // $v0
		/* end block 1.1 */
		// End offset: 0x8006226C
		// End Line: 1364
	/* end block 1 */
	// End offset: 0x8006226C
	// End Line: 1370

	/* begin block 2 */
		// Start line: 3100
	/* end block 2 */
	// End Line: 3101

	/* begin block 3 */
		// Start line: 3101
	/* end block 3 */
	// End Line: 3102

/* File: C:\kain2\game\EVENT.C */

void EVENT_AddShortPointerToStack(_PCodeStack *stack,short *pointer)

{
  int iVar1;
  
  iVar1 = stack->topOfStack;
  if (iVar1 < 0x20) {
    stack->stack[iVar1].id = 10;
    *(short **)stack->stack[iVar1].data = pointer;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_AddNumberToStack(struct _PCodeStack *stack /*$a0*/, long item /*$a1*/, long flags /*$a2*/)
 // line 1372, offset 0x80062274
	/* begin block 1 */
		// Start line: 1374
		// Start offset: 0x80062274

		/* begin block 1.1 */
			// Start line: 1376
			// Start offset: 0x80062288
			// Variables:
		// 		struct StackType *stackEntry; // $v0
		/* end block 1.1 */
		// End offset: 0x800622BC
		// End Line: 1382
	/* end block 1 */
	// End offset: 0x800622BC
	// End Line: 1388

	/* begin block 2 */
		// Start line: 3132
	/* end block 2 */
	// End Line: 3133

	/* begin block 3 */
		// Start line: 3133
	/* end block 3 */
	// End Line: 3134

/* File: C:\kain2\game\EVENT.C */

void EVENT_AddNumberToStack(_PCodeStack *stack,long item,long flags)

{
  StackType *pSVar1;
  
  if (stack->topOfStack < 0x20) {
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
 // line 1390, offset 0x800622c4
	/* begin block 1 */
		// Start line: 3168
	/* end block 1 */
	// End Line: 3169

	/* begin block 2 */
		// Start line: 3169
	/* end block 2 */
	// End Line: 3170

/* File: C:\kain2\game\EVENT.C */

void EVENT_ChangeOperandToNumber(StackType *operand,long item,long flags)

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
 // line 1398, offset 0x800622dc
	/* begin block 1 */
		// Start line: 3184
	/* end block 1 */
	// End Line: 3185

	/* begin block 2 */
		// Start line: 3185
	/* end block 2 */
	// End Line: 3186

/* File: C:\kain2\game\EVENT.C */

void EVENT_ChangeOperandVector3d(StackType *operand,short x,short y,short z,long streamUnitID)

{
  operand->id = 9;
  *(short *)operand->data = x;
  *(short *)(operand->data + 2) = y;
  *(short *)(operand->data + 4) = z;
  *(undefined2 *)(operand->data + 8) = 0xa0;
  *(undefined2 *)(operand->data + 10) = 0xa0;
  *(undefined2 *)(operand->data + 0xc) = 0xa0;
  *(long *)(operand->data + 0x10) = streamUnitID;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_Addvector3dToStack(struct _PCodeStack *stack /*$s0*/, short x /*$a1*/, short y /*$a2*/, short z /*$a3*/, long streamUnitID /*stack 16*/)
 // line 1410, offset 0x8006230c
	/* begin block 1 */
		// Start line: 3212
	/* end block 1 */
	// End Line: 3213

/* File: C:\kain2\game\EVENT.C */

void EVENT_Addvector3dToStack(_PCodeStack *stack,short x,short y,short z,long streamUnitID)

{
  if (stack->topOfStack < 0x20) {
    EVENT_ChangeOperandVector3d(stack->stack + stack->topOfStack,x,y,z,streamUnitID);
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_ChangeOperandRotation3d(struct StackType *operand /*$a0*/, struct Rotation3d *rotation /*$a1*/)
 // line 1425, offset 0x80062384
	/* begin block 1 */
		// Start line: 3242
	/* end block 1 */
	// End Line: 3243

	/* begin block 2 */
		// Start line: 3243
	/* end block 2 */
	// End Line: 3244

/* File: C:\kain2\game\EVENT.C */

void EVENT_ChangeOperandRotation3d(StackType *operand,Rotation3d *rotation)

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
 // line 1451, offset 0x800623dc
	/* begin block 1 */
		// Start line: 1453
		// Start offset: 0x800623DC

		/* begin block 1.1 */
			// Start line: 1460
			// Start offset: 0x800623F0
			// Variables:
		// 		struct StackType *stackEntry; // $a3
		/* end block 1.1 */
		// End offset: 0x80062468
		// End Line: 1474
	/* end block 1 */
	// End offset: 0x80062468
	// End Line: 1480

	/* begin block 2 */
		// Start line: 2898
	/* end block 2 */
	// End Line: 2899

	/* begin block 3 */
		// Start line: 3277
	/* end block 3 */
	// End Line: 3278

	/* begin block 4 */
		// Start line: 3282
	/* end block 4 */
	// End Line: 3283

/* File: C:\kain2\game\EVENT.C */

long EVENT_AddSubListObjectToStack(_PCodeStack *stack,long listNumber)

{
  StackType *pSVar1;
  
  if (stack->topOfStack < 0x20) {
    pSVar1 = stack->stack + stack->topOfStack;
    pSVar1->id = 0x16;
    if (eventListNumInstances[listNumber] < 1) {
      *(undefined4 *)pSVar1->data = 0;
    }
    else {
      *(undefined **)pSVar1->data = &eventListArray + listNumber * 0x28;
    }
    *(long *)(pSVar1->data + 4) = eventListNumInstances[listNumber];
    *(undefined4 *)(pSVar1->data + 8) = 0;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_StackDuplicate(struct _PCodeStack *stack /*$a0*/)
 // line 1530, offset 0x80062470
	/* begin block 1 */
		// Start line: 3056
	/* end block 1 */
	// End Line: 3057

	/* begin block 2 */
		// Start line: 3386
	/* end block 2 */
	// End Line: 3387

/* File: C:\kain2\game\EVENT.C */

void EVENT_StackDuplicate(_PCodeStack *stack)

{
  int iVar1;
  long *plVar2;
  StackType *pSVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  
  iVar1 = stack->topOfStack;
  if ((iVar1 < 0x20) && (iVar1 != 0)) {
    pSVar3 = stack->stack + iVar1;
    plVar2 = &stack->topOfStack + (iVar1 + -1) * 9 + 1;
    do {
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
 // line 1552, offset 0x80062508
	/* begin block 1 */
		// Start line: 1554
		// Start offset: 0x80062508
		// Variables:
	// 		long retValue; // $a0
	/* end block 1 */
	// End offset: 0x80062590
	// End Line: 1599

	/* begin block 2 */
		// Start line: 3429
	/* end block 2 */
	// End Line: 3430

	/* begin block 3 */
		// Start line: 3430
	/* end block 3 */
	// End Line: 3431

	/* begin block 4 */
		// Start line: 3431
	/* end block 4 */
	// End Line: 3432

/* File: C:\kain2\game\EVENT.C */

long EVENT_TransformTGroupAttribute
               (_PCodeStack *stack,StackType *stackObject,long item,short *codeStream)

{
  long lVar1;
  
  lVar1 = 0;
  if (*(int *)(stackObject->data + 8) == -1) {
    *(long *)(stackObject->data + 8) = item;
    lVar1 = 1;
    switch(item) {
    default:
      goto switchD_80062544_caseD_5;
    case 0x2c:
    case 0x2e:
      if (codeStream != (short *)0x0) {
        MoveCodeStreamExtra = 2;
        *(short *)(stackObject->data + 0xc) = codeStream[1];
        *(short *)(stackObject->data + 0xe) = codeStream[2];
      }
      break;
    case 0x2d:
    case 0x2f:
      if (codeStream != (short *)0x0) {
        MoveCodeStreamExtra = 1;
        *(short *)(stackObject->data + 0xc) = codeStream[1];
      }
    }
    lVar1 = 1;
  }
switchD_80062544_caseD_5:
  return lVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformConstrictAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a0*/, long item /*$a2*/)
 // line 1602, offset 0x80062598
	/* begin block 1 */
		// Start line: 1603
		// Start offset: 0x80062598
		// Variables:
	// 		long retValue; // $v1
	// 		struct _Instance *instance; // $a1

		/* begin block 1.1 */
			// Start line: 1613
			// Start offset: 0x800625C8
		/* end block 1.1 */
		// End offset: 0x800625C8
		// End Line: 1616

		/* begin block 1.2 */
			// Start line: 1627
			// Start offset: 0x800625D8
		/* end block 1.2 */
		// End offset: 0x800625F4
		// End Line: 1636
	/* end block 1 */
	// End offset: 0x800625F4
	// End Line: 1648

	/* begin block 2 */
		// Start line: 3529
	/* end block 2 */
	// End Line: 3530

/* File: C:\kain2\game\EVENT.C */

long EVENT_TransformConstrictAttribute(_PCodeStack *stack,StackType *stackObject,long item)

{
  uint item_00;
  
  if (item == 0x3a) {
    item_00 = (uint)(*(short *)(*(int *)stackObject->data + 0x16c) < -1);
  }
  else {
    if (item != 0x3b) {
      return 0;
    }
    item_00 = (uint)(*(short *)(*(int *)stackObject->data + 0x16c) < 2) ^ 1;
  }
  EVENT_ChangeOperandToNumber(stackObject,item_00,0);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformInstanceAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$s1*/, long item /*$a2*/, short *codeStream /*$a3*/)
 // line 1654, offset 0x80062604
	/* begin block 1 */
		// Start line: 1655
		// Start offset: 0x80062604
		// Variables:
	// 		long retValue; // $a0
	// 		long x; // $a1
	// 		long y; // $a2
	// 		long z; // $a3
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 1666
			// Start offset: 0x80062650
			// Variables:
		// 		struct evPositionData *position; // $v0
		/* end block 1.1 */
		// End offset: 0x80062684
		// End Line: 1681

		/* begin block 1.2 */
			// Start line: 1687
			// Start offset: 0x8006269C
			// Variables:
		// 		struct evPositionData *rotation; // $v1
		// 		struct Rotation3d vector; // stack offset -40
		/* end block 1.2 */
		// End offset: 0x800626FC
		// End Line: 1706

		/* begin block 1.3 */
			// Start line: 1734
			// Start offset: 0x80062754
			// Variables:
		// 		int status; // $v1
		/* end block 1.3 */
		// End offset: 0x800627DC
		// End Line: 1771

		/* begin block 1.4 */
			// Start line: 1793
			// Start offset: 0x80062804
		/* end block 1.4 */
		// End offset: 0x80062804
		// End Line: 1795

		/* begin block 1.5 */
			// Start line: 1806
			// Start offset: 0x80062828
		/* end block 1.5 */
		// End offset: 0x80062828
		// End Line: 1806

		/* begin block 1.6 */
			// Start line: 1813
			// Start offset: 0x8006284C
		/* end block 1.6 */
		// End offset: 0x8006284C
		// End Line: 1813

		/* begin block 1.7 */
			// Start line: 1820
			// Start offset: 0x80062870
		/* end block 1.7 */
		// End offset: 0x80062870
		// End Line: 1820

		/* begin block 1.8 */
			// Start line: 1827
			// Start offset: 0x80062894
			// Variables:
		// 		struct _Instance *tmpI; // $s0
		// 		long value; // $a1

			/* begin block 1.8.1 */
				// Start line: 1839
				// Start offset: 0x800628C8
			/* end block 1.8.1 */
			// End offset: 0x800628E4
			// End Line: 1848
		/* end block 1.8 */
		// End offset: 0x800628E8
		// End Line: 1854

		/* begin block 1.9 */
			// Start line: 1863
			// Start offset: 0x800628FC
		/* end block 1.9 */
		// End offset: 0x800628FC
		// End Line: 1865

		/* begin block 1.10 */
			// Start line: 1876
			// Start offset: 0x80062924
		/* end block 1.10 */
		// End offset: 0x80062924
		// End Line: 1878

		/* begin block 1.11 */
			// Start line: 1887
			// Start offset: 0x8006294C
		/* end block 1.11 */
		// End offset: 0x8006294C
		// End Line: 1889

		/* begin block 1.12 */
			// Start line: 1916
			// Start offset: 0x80062974
		/* end block 1.12 */
		// End offset: 0x80062974
		// End Line: 1918

		/* begin block 1.13 */
			// Start line: 1926
			// Start offset: 0x80062998
		/* end block 1.13 */
		// End offset: 0x80062998
		// End Line: 1929

		/* begin block 1.14 */
			// Start line: 1952
			// Start offset: 0x80062A10
			// Variables:
		// 		long value; // $s2

			/* begin block 1.14.1 */
				// Start line: 1955
				// Start offset: 0x80062A20
				// Variables:
			// 		struct _StreamUnit *streamUnit; // $v0
			/* end block 1.14.1 */
			// End offset: 0x80062A58
			// End Line: 1962
		/* end block 1.14 */
		// End offset: 0x80062A84
		// End Line: 1972

		/* begin block 1.15 */
			// Start line: 1996
			// Start offset: 0x80062B04
			// Variables:
		// 		long value; // $a1
		/* end block 1.15 */
		// End offset: 0x80062B28
		// End Line: 2003

		/* begin block 1.16 */
			// Start line: 2009
			// Start offset: 0x80062B3C
			// Variables:
		// 		long value; // $a1
		/* end block 1.16 */
		// End offset: 0x80062B60
		// End Line: 2016

		/* begin block 1.17 */
			// Start line: 2022
			// Start offset: 0x80062B74
			// Variables:
		// 		long value; // $a1
		/* end block 1.17 */
		// End offset: 0x80062B98
		// End Line: 2030

		/* begin block 1.18 */
			// Start line: 2036
			// Start offset: 0x80062BAC
			// Variables:
		// 		long value; // $a1
		/* end block 1.18 */
		// End offset: 0x80062BD0
		// End Line: 2044

		/* begin block 1.19 */
			// Start line: 2050
			// Start offset: 0x80062BE4
			// Variables:
		// 		long value; // $a1
		/* end block 1.19 */
		// End offset: 0x80062C0C
		// End Line: 2058
	/* end block 1 */
	// End offset: 0x80062C50
	// End Line: 2128

	/* begin block 2 */
		// Start line: 3640
	/* end block 2 */
	// End Line: 3641

/* File: C:\kain2\game\EVENT.C */

long EVENT_TransformInstanceAttribute
               (_PCodeStack *stack,StackType *stackObject,long item,short *codeStream)

{
  bool bVar1;
  short *psVar2;
  MultiSpline *pMVar3;
  int item_00;
  ulong item_01;
  _StreamUnit *p_Var4;
  long lVar5;
  AniTex *pAVar6;
  uint uVar7;
  long item_02;
  _Terrain *p_Var8;
  short x;
  short y;
  short z;
  _Instance *Inst;
  Rotation3d local_28;
  
  Inst = *(_Instance **)stackObject->data;
  item_02 = 0;
  switch(item) {
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
    item_02 = 1;
    break;
  case 5:
    psVar2 = (short *)INSTANCE_Query(Inst,6);
    if (psVar2 == (short *)0x0) {
      x = (Inst->position).x;
      y = (Inst->position).y;
      z = (Inst->position).z;
    }
    else {
      x = *psVar2;
      y = psVar2[1];
      z = psVar2[2];
    }
    EVENT_ChangeOperandVector3d(stackObject,x,y,z,Inst->currentStreamUnitID);
    item_02 = 1;
    break;
  case 9:
    psVar2 = (short *)INSTANCE_Query(Inst,7);
    if (psVar2 == (short *)0x0) {
      local_28.vx = (Inst->rotation).x;
      local_28.vy = (Inst->rotation).y;
      local_28.vz = (Inst->rotation).z;
    }
    else {
      local_28.vx = *psVar2;
      local_28.vy = psVar2[1];
      local_28.vz = psVar2[2];
    }
    local_28.errorx = 0x200;
    local_28.errorz = 0x200;
    local_28.errory = 0x200;
    EVENT_ChangeOperandRotation3d(stackObject,&local_28);
    item_02 = 1;
    break;
  case 0xc:
    stackObject->id = 0xf;
    *(_Instance **)stackObject->data = Inst;
    pMVar3 = SCRIPT_GetMultiSpline
                       (Inst,(ulong *)(stackObject->data + 0xc),(ulong *)(stackObject->data + 0x10))
    ;
    item_02 = 1;
    *(MultiSpline **)(stackObject->data + 4) = pMVar3;
    *(undefined4 *)(stackObject->data + 0x14) = 0;
    *(undefined4 *)(stackObject->data + 8) = 0xffffffff;
    break;
  case 0x12:
    item_01 = INSTANCE_Query(Inst,9);
    EVENT_ChangeOperandToNumber(stackObject,item_01,1);
    item_02 = 1;
    break;
  case 0x13:
    item_01 = INSTANCE_Query(Inst,10);
    EVENT_ChangeOperandToNumber(stackObject,item_01,3);
    item_02 = 1;
    break;
  case 0x1d:
    lVar5 = 0x13;
    if (Inst->object->animList == (_G2AnimKeylist_Type **)0x0) {
      return 0;
    }
    goto LAB_80062af0;
  case 0x21:
    stackObject->id = 0x14;
    *(_Instance **)stackObject->data = Inst;
    item_02 = 1;
    pAVar6 = Inst->object->modelList[Inst->currentModel]->aniTextures;
    *(undefined4 *)(stackObject->data + 8) = 0xffffffff;
    *(AniTex **)(stackObject->data + 4) = pAVar6;
    break;
  case 0x2b:
    item_00 = Inst->attachedID;
    if ((item_00 == 0) &&
       (p_Var4 = STREAM_GetStreamUnitWithID(Inst->currentStreamUnitID), item_00 = 0,
       p_Var4 != (_StreamUnit *)0x0)) {
      p_Var8 = p_Var4->level->terrain;
      if (Inst->bspTree < p_Var8->numBSPTrees) {
        item_00 = -(Inst->currentStreamUnitID * 0x100 + (int)p_Var8->BSPTreeArray[Inst->bspTree].ID)
        ;
      }
    }
    EVENT_ChangeOperandToNumber(stackObject,item_00,0);
    item_02 = 1;
    break;
  case 0x38:
    item_01 = INSTANCE_Query(Inst,0x1e);
    EVENT_ChangeOperandToNumber(stackObject,item_01,0);
    item_02 = 1;
    break;
  case 0x39:
    lVar5 = 0x18;
LAB_80062af0:
    item_02 = 1;
    stackObject->id = lVar5;
    *(_Instance **)stackObject->data = Inst;
    *(undefined4 *)(stackObject->data + 4) = 0xffffffff;
    break;
  case 0x3c:
    bVar1 = (Inst->flags & 4U) != 0;
    if (bVar1) {
      Inst->flags = Inst->flags & 0xfffffffb;
    }
    EVENT_ChangeOperandToNumber(stackObject,(uint)bVar1,0);
    item_02 = 1;
    break;
  case 0x3f:
    EVENT_ChangeOperandToNumber(stackObject,1,0);
    item_02 = 1;
    break;
  case 0x6a:
    uVar7 = Inst->flags;
    if ((int)uVar7 < 0) {
      Inst->flags = uVar7 & 0x7fffffff;
    }
    EVENT_ChangeOperandToNumber(stackObject,(uint)((int)uVar7 < 0),0);
    item_02 = 1;
    break;
  case 0x79:
    bVar1 = (Inst->flags & 8U) != 0;
    if (bVar1) {
      Inst->flags = Inst->flags & 0xfffffff7;
    }
    EVENT_ChangeOperandToNumber(stackObject,(uint)bVar1,0);
    item_02 = 1;
    break;
  case 0x7a:
    bVar1 = (Inst->flags & 0x10U) != 0;
    if (bVar1) {
      Inst->flags = Inst->flags & 0xffffffef;
    }
    EVENT_ChangeOperandToNumber(stackObject,(uint)bVar1,0);
    item_02 = 1;
    break;
  case 0x7d:
    bVar1 = (Inst->flags2 & 0x10000U) != 0;
    if (bVar1) {
      Inst->flags2 = Inst->flags2 & 0xfffeffff;
    }
    EVENT_ChangeOperandToNumber(stackObject,(uint)bVar1,0);
    item_02 = 1;
    break;
  case 0x7e:
    stackObject->id = 0x1b;
    *(_Instance **)(stackObject->data + 0x10) = Inst;
    *(undefined2 *)(stackObject->data + 2) = 0xffff;
    if (codeStream != (short *)0x0) {
      MoveCodeStreamExtra = 1;
      *(int *)(stackObject->data + 4) = (int)codeStream[1];
    }
    item_00 = SOUND_IsInstanceSoundLoaded(Inst->object->soundData,*(long *)(stackObject->data + 4));
    if (item_00 == 0) {
      if (0 < WaitingToLoadSound - DAT_800d2314) {
        WaitingToLoadSound = WaitingToLoadSound - DAT_800d2314;
        EventAbortLine = 1;
        return 1;
      }
    }
    else {
      if (item_00 == -1) {
        return 1;
      }
    }
    WaitingToLoadSound = 0x96000;
    item_02 = 1;
    break;
  case 0x89:
    item_01 = INSTANCE_Query(Inst,0x24);
    EVENT_ChangeOperandToNumber(stackObject,item_01,3);
    item_02 = 1;
    break;
  case 0x8b:
  case 0xa6:
    item_01 = INSTANCE_Query(Inst,0);
    EVENT_ChangeOperandToNumber(stackObject,item_01 >> 0x1e & 1,0);
    item_02 = 1;
    break;
  case 0x92:
    EVENT_ChangeOperandToNumber(stackObject,0,0);
    item_02 = 1;
    break;
  case 0x97:
    EVENT_ChangeOperandToNumber(stackObject,Inst->currentStreamUnitID,0);
    item_02 = 1;
    break;
  case 0x99:
    EVENT_ChangeOperandToNumber(stackObject,(uint)(Inst->tface != (_TFace *)0x0),0);
    item_02 = 1;
    break;
  case 0x9f:
    item_01 = INSTANCE_Query(Inst,0x2b);
    EVENT_ChangeOperandToNumber(stackObject,item_01,0);
    item_02 = 1;
    break;
  case 0xa0:
    item_01 = INSTANCE_Query(Inst,1);
    EVENT_ChangeOperandToNumber(stackObject,(uint)((item_01 & 4) != 0),0);
    item_02 = 1;
    break;
  case 0xa1:
    Inst = (_Instance *)INSTANCE_Query(Inst,0x2c);
    if (Inst == (_Instance *)0x0) {
      item_02 = 0;
    }
    else {
      item_01 = INSTANCE_Query(Inst,1);
      if ((item_01 & 0x20) != 0) {
        item_01 = INSTANCE_Query(Inst,4);
        if ((item_01 & 3) != 0) {
          return 1;
        }
        return 2;
      }
      item_02 = 3;
    }
    EVENT_ChangeOperandToNumber(stackObject,item_02,0);
    item_02 = 1;
    break;
  case 0xa7:
    item_01 = INSTANCE_Query(Inst,0);
    EVENT_ChangeOperandToNumber(stackObject,item_01 >> 0x1a & 1,0);
    item_02 = 1;
    break;
  case 0xa9:
    item_01 = INSTANCE_Query(Inst,0x1f);
    EVENT_ChangeOperandToNumber(stackObject,item_01,0);
    item_02 = 1;
    break;
  case 0xaa:
    item_01 = INSTANCE_Query(Inst,0x20);
    EVENT_ChangeOperandToNumber(stackObject,item_01,0);
    item_02 = 1;
  }
  return item_02;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformSoundObjectAttribute(struct _PCodeStack *stack /*$a0*/, struct SoundObject *soundObject /*$a1*/, long item /*$a2*/, short *codeStream /*$a3*/)
 // line 2130, offset 0x80062c68
	/* begin block 1 */
		// Start line: 2131
		// Start offset: 0x80062C68
		// Variables:
	// 		long retValue; // $v1

		/* begin block 1.1 */
			// Start line: 2139
			// Start offset: 0x80062CBC
		/* end block 1.1 */
		// End offset: 0x80062CF8
		// End Line: 2159
	/* end block 1 */
	// End offset: 0x80062D38
	// End Line: 2205

	/* begin block 2 */
		// Start line: 4636
	/* end block 2 */
	// End Line: 4637

/* File: C:\kain2\game\EVENT.C */

long EVENT_TransformSoundObjectAttribute
               (_PCodeStack *stack,SoundObject *soundObject,long item,short *codeStream)

{
  int iVar1;
  long lVar2;
  
  lVar2 = 0;
  if (item == 0x7e) {
    if (codeStream != (short *)0x0) {
      MoveCodeStreamExtra = 1;
      soundObject->soundNumber = (int)codeStream[1];
    }
    iVar1 = SOUND_IsInstanceSoundLoaded(*(uchar **)soundObject->data,soundObject->soundNumber);
    lVar2 = 1;
    if (iVar1 == 0) {
      EventAbortLine = 1;
    }
  }
  else {
    if (item < 0x7f) {
      if ((item < 0xf) && (0xc < item)) {
        soundObject->attribute = (short)item;
        lVar2 = 1;
      }
    }
    else {
      if ((item == 0x7f) || (item == 0x80)) {
        soundObject->attribute = (short)item;
        if (codeStream != (short *)0x0) {
          MoveCodeStreamExtra = 2;
          soundObject->value = (int)codeStream[1];
          soundObject->duration = (int)codeStream[2];
        }
        lVar2 = 1;
      }
    }
  }
  return lVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_GetGameValue(struct GameObject *gameObject /*$a0*/)
 // line 2208, offset 0x80062d48
	/* begin block 1 */
		// Start line: 2209
		// Start offset: 0x80062D48
		// Variables:
	// 		long value; // $v1
	/* end block 1 */
	// End offset: 0x80062DD4
	// End Line: 2241

	/* begin block 2 */
		// Start line: 4794
	/* end block 2 */
	// End Line: 4795

/* File: C:\kain2\game\EVENT.C */

long EVENT_GetGameValue(GameObject *gameObject)

{
  int iVar1;
  
  if (gameObject->attribute != -1) {
    if (gameObject->attribute != 2) {
      return 0;
    }
    iVar1 = GAMELOOP_GetTimeOfDay();
    if (iVar1 == 700) {
      return 2;
    }
    if (700 < iVar1) {
      if (iVar1 == 0x708) {
        return 3;
      }
      if (iVar1 != 0x76c) {
        return iVar1;
      }
      return 4;
    }
    if (iVar1 != 600) {
      return iVar1;
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformGameAttribute(struct _PCodeStack *stack /*$s1*/, struct StackType *stackObject /*$s2*/, long item /*$a2*/, short *codeStream /*$s0*/)
 // line 2245, offset 0x80062de4
	/* begin block 1 */
		// Start line: 2246
		// Start offset: 0x80062DE4
		// Variables:
	// 		long value; // $s0
	// 		long retValue; // $a0

		/* begin block 1.1 */
			// Start line: 2309
			// Start offset: 0x80062F74
			// Variables:
		// 		struct EventTimer *timer; // $a2
		// 		short time; // $v1
		/* end block 1.1 */
		// End offset: 0x80062FEC
		// End Line: 2337

		/* begin block 1.2 */
			// Start line: 2356
			// Start offset: 0x80063044
			// Variables:
		// 		long wipeType; // $v1
		// 		long wipeTime; // $a0
		/* end block 1.2 */
		// End offset: 0x800630AC
		// End Line: 2378

		/* begin block 1.3 */
			// Start line: 2384
			// Start offset: 0x800630BC
			// Variables:
		// 		long motor0Time; // $a1
		// 		long motor0Speed; // $a0
		// 		long motor1Time; // $a3
		// 		long motor1Speed; // $a2
		/* end block 1.3 */
		// End offset: 0x800630F4
		// End Line: 2408

		/* begin block 1.4 */
			// Start line: 2423
			// Start offset: 0x80063144
			// Variables:
		// 		short rand1; // $s1
		// 		short rand2; // $s0
		/* end block 1.4 */
		// End offset: 0x8006318C
		// End Line: 2436

		/* begin block 1.5 */
			// Start line: 2441
			// Start offset: 0x80063194
		/* end block 1.5 */
		// End offset: 0x80063194
		// End Line: 2443

		/* begin block 1.6 */
			// Start line: 2451
			// Start offset: 0x800631B4
			// Variables:
		// 		int number; // $a1
		/* end block 1.6 */
		// End offset: 0x800631B4
		// End Line: 2453

		/* begin block 1.7 */
			// Start line: 2461
			// Start offset: 0x800631D4
		/* end block 1.7 */
		// End offset: 0x800631D4
		// End Line: 2463

		/* begin block 1.8 */
			// Start line: 2470
			// Start offset: 0x800631F8
		/* end block 1.8 */
		// End offset: 0x800631F8
		// End Line: 2472
	/* end block 1 */
	// End offset: 0x8006326C
	// End Line: 2521

	/* begin block 2 */
		// Start line: 4869
	/* end block 2 */
	// End Line: 4870

/* File: C:\kain2\game\EVENT.C */

long EVENT_TransformGameAttribute
               (_PCodeStack *stack,StackType *stackObject,long item,short *codeStream)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  Event *pEVar6;
  ScriptPCode *pSVar7;
  short *psVar8;
  EventTimer *pEVar9;
  ulong item_00;
  int Data;
  long item_01;
  uint item_02;
  
  item_01 = 0;
  switch(item) {
  case 1:
    EVENT_ChangeOperandToNumber(stackObject,(uint)(DAT_800d2300 * 0x1e) / 1000,0);
    item_01 = 1;
    break;
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
    goto LAB_80063268;
  case 0x14:
    item_00 = INSTANCE_Query(DAT_800d20f8,0xb);
    item_02 = item_00 >> 1 & 1;
    Data = STREAM_IsMorphInProgress();
    if (Data != 0) {
      item_02 = 0;
    }
    EVENT_ChangeOperandToNumber(stackObject,item_02,0);
    item_01 = 1;
    break;
  case 0x15:
    item_00 = INSTANCE_Query(DAT_800d20f8,0xb);
    item_02 = item_00 & 1;
    Data = STREAM_IsMorphInProgress();
    if (Data != 0) {
      item_02 = 0;
    }
    EVENT_ChangeOperandToNumber(stackObject,item_02,0);
    item_01 = 1;
    break;
  case 0x1b:
    item_02 = DAT_800d2114;
    if (((DAT_800d218c & 0x40000) != 0) && ((DAT_800d2114 & 0x90) == 0x90)) {
      item_02 = DAT_800d2114 & 0xffffff6f;
    }
    EVENT_ChangeOperandToNumber(stackObject,item_02,1);
    item_01 = 1;
    break;
  case 0x31:
    pEVar9 = EVENT_GetNextTimer();
    psVar8 = CurrentPuzzleLevel;
    pSVar7 = currentActionScript;
    pEVar6 = currentEventInstance;
    if (pEVar9 == (EventTimer *)0x0) {
      return 1;
    }
    if (codeStream == (short *)0x0) {
      return 1;
    }
    MoveCodeStreamExtra = 1;
    uVar5 = codeStream[1];
    EventAbortLine = 1;
    EventJustRecievedTimer = 1;
    pEVar9->actionScript = (ScriptPCode *)(codeStream + 2);
    pEVar9->flags = pEVar9->flags & 1U | (int)((uint)uVar5 << 0x10) >> 3;
    *(ScriptPCode **)&pEVar9->event = pSVar7;
    *(Event **)&pEVar9->time = pEVar6;
    item_01 = EventCurrentEventIndex;
    pSVar7->conditionBits = pSVar7->conditionBits | 1;
    pEVar9->scriptPos = psVar8;
    *(long *)&pEVar9->level = item_01;
    goto LAB_80063268;
  case 0x3d:
    EVENT_ChangeOperandToNumber(stackObject,(int)DAT_800d22ee,0);
    item_01 = 1;
    break;
  case 0x42:
    item_01 = 1;
    stackObject->id = 0x19;
    *(undefined4 *)stackObject->data = 0x800d0f9c;
    *(undefined4 *)(stackObject->data + 8) = 0xffffffff;
    break;
  case 0x4a:
    if (codeStream != (short *)0x0) {
      MoveCodeStreamExtra = 2;
      DAT_800d2198 = codeStream[2];
      LAB_800d219c = codeStream[1];
      DAT_800d219a = DAT_800d2198;
      if (DAT_800d2198 < 0) {
        DAT_800d219a = -DAT_800d2198;
      }
      if (LAB_800d219c == 0xb) {
        if (DAT_800d2198 < 0) {
          DAT_800d2210 = DAT_800d2210 | 0x2000000;
        }
        else {
          DAT_800d2210 = DAT_800d2210 & 0xfdffffff;
        }
      }
      stack->topOfStack = stack->topOfStack + -1;
    }
    goto LAB_80063268;
  case 0x51:
    Data = 0;
    goto LAB_80063128;
  case 0x52:
    Data = 1;
LAB_80063128:
    INSTANCE_Broadcast((_Instance *)0x0,10,0x4000e,Data);
    item_01 = 1;
    stack->topOfStack = stack->topOfStack + -1;
    break;
  case 0x5a:
    if (codeStream != (short *)0x0) {
      MoveCodeStreamExtra = 2;
      sVar1 = codeStream[1];
      sVar2 = codeStream[2];
      Data = rand();
      EVENT_ChangeOperandToNumber(stackObject,Data % ((int)sVar2 - (int)sVar1) + (int)sVar1,0);
      return 1;
    }
    goto LAB_80063268;
  case 0x78:
    Data = LOAD_IsXAInQueue();
    EVENT_ChangeOperandToNumber(stackObject,(uint)(Data == 0),0);
    item_01 = 1;
    break;
  case 0x86:
    EVENT_ChangeOperandToNumber(stackObject,DAT_800d2210 >> 0x17 & 1,0);
    item_01 = 1;
    break;
  case 0x91:
    stack->topOfStack = stack->topOfStack + -1;
    EVENT_AddShortPointerToStack(stack,&gEndGameNow);
    item_01 = 1;
    break;
  case 0x9a:
    item_00 = INSTANCE_Query(DAT_800d20f8,0x29);
    EVENT_ChangeOperandToNumber(stackObject,item_00,3);
    item_01 = 1;
    break;
  case 0x9b:
    item_00 = INSTANCE_Query(DAT_800d20f8,0x2a);
    EVENT_ChangeOperandToNumber(stackObject,item_00,3);
    item_01 = 1;
    break;
  case 0x9d:
    item_01 = HINT_GetCurrentHint();
    EVENT_ChangeOperandToNumber(stackObject,item_01,0);
    item_01 = 1;
    break;
  case 0x9e:
    EVENT_ChangeOperandToNumber(stackObject,DAT_800d2210 & 0x100000,0);
    item_01 = 1;
    break;
  case 0xa2:
    if (codeStream != (short *)0x0) {
      MoveCodeStreamExtra = 4;
      sVar1 = codeStream[1];
      sVar2 = codeStream[2];
      sVar3 = codeStream[4];
      sVar4 = codeStream[3];
      stack->topOfStack = stack->topOfStack + -1;
      GAMEPAD_Shock((int)sVar1,(int)sVar2 << 0xc,(int)sVar4,(int)sVar3 << 0xc);
      return 1;
    }
LAB_80063268:
    item_01 = 1;
    break;
  case 0xa8:
    stack->topOfStack = stack->topOfStack + -1;
    item_01 = 1;
    if ((DAT_800d218c & 0x80000) != 0) {
      Data = VOICEXA_IsPlaying();
      item_01 = 1;
      if (Data == 2) {
        EventAbortLine = 1;
      }
    }
  }
  return item_01;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformAreaAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a1*/, long item /*$a2*/, short *codeStream /*$a3*/)
 // line 2525, offset 0x80063288
	/* begin block 1 */
		// Start line: 2526
		// Start offset: 0x80063288
		// Variables:
	// 		long retValue; // $v1
	// 		long offset; // $a1
	// 		struct _StreamUnit *streamUnit; // $t0
	/* end block 1 */
	// End offset: 0x80063354
	// End Line: 2580

	/* begin block 2 */
		// Start line: 5482
	/* end block 2 */
	// End Line: 5483

/* File: C:\kain2\game\EVENT.C */

long EVENT_TransformAreaAttribute
               (_PCodeStack *stack,StackType *stackObject,long item,short *codeStream)

{
  short sVar1;
  long lVar2;
  int iVar3;
  
  iVar3 = *(int *)stackObject->data;
  lVar2 = 0;
  if (iVar3 == 0) {
    EventAbortLine = 1;
    lVar2 = 1;
  }
  else {
    if (item == 0x41) {
      stack->topOfStack = stack->topOfStack + -1;
      EVENT_AddShortPointerToStack(stack,(short *)(*(int *)(iVar3 + 8) + 0x38));
      lVar2 = 1;
    }
    else {
      if (item < 0x42) {
        if (item == 3) {
          MoveCodeStreamExtra = 1;
          sVar1 = codeStream[1];
          if ((uint)(int)sVar1 < 6) {
            stack->topOfStack = stack->topOfStack + -1;
            EVENT_AddShortPointerToStack(stack,(short *)(iVar3 + (int)sVar1 * 2 + 0x24));
            lVar2 = 1;
          }
        }
      }
      else {
        if ((item < 0x72) && (0x6f < item)) {
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
 // line 2584, offset 0x80063364
	/* begin block 1 */
		// Start line: 2585
		// Start offset: 0x80063364
		// Variables:
	// 		long retValue; // $v1
	// 		long offset; // $a1
	// 		struct Event *event; // $t0
	/* end block 1 */
	// End offset: 0x800633E4
	// End Line: 2636

	/* begin block 2 */
		// Start line: 5606
	/* end block 2 */
	// End Line: 5607

/* File: C:\kain2\game\EVENT.C */

long EVENT_TransformEventAttribute
               (_PCodeStack *stack,StackType *stackObject,long item,short *codeStream)

{
  short sVar1;
  long lVar2;
  int iVar3;
  
  iVar3 = *(int *)stackObject->data;
  lVar2 = 0;
  if (item == 3) {
    MoveCodeStreamExtra = 1;
    sVar1 = codeStream[1];
    if ((uint)(int)sVar1 < 6) {
      stack->topOfStack = stack->topOfStack + -1;
      EVENT_AddShortPointerToStack(stack,(short *)(iVar3 + (int)sVar1 * 2 + 6));
      lVar2 = 1;
    }
  }
  else {
    if ((item == 0x1a) && (lVar2 = 1, *(char *)(iVar3 + 5) == '\0')) {
      *(undefined *)(iVar3 + 5) = 1;
    }
  }
  return lVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformSavedEventAttribute(struct _PCodeStack *stack /*$t0*/, struct StackType *stackObject /*$a0*/, long item /*$a2*/, short *codeStream /*$a3*/)
 // line 2639, offset 0x800633f4
	/* begin block 1 */
		// Start line: 2640
		// Start offset: 0x800633F4
		// Variables:
	// 		long retValue; // $v1
	// 		long offset; // $a1

		/* begin block 1.1 */
			// Start line: 2658
			// Start offset: 0x8006344C
		/* end block 1.1 */
		// End offset: 0x8006344C
		// End Line: 2660

		/* begin block 1.2 */
			// Start line: 2667
			// Start offset: 0x80063470
		/* end block 1.2 */
		// End offset: 0x80063470
		// End Line: 2669
	/* end block 1 */
	// End offset: 0x800634A0
	// End Line: 2698

	/* begin block 2 */
		// Start line: 5727
	/* end block 2 */
	// End Line: 5728

/* File: C:\kain2\game\EVENT.C */

long EVENT_TransformSavedEventAttribute
               (_PCodeStack *stack,StackType *stackObject,long item,short *codeStream)

{
  long lVar1;
  uint uVar2;
  char *pcVar3;
  
  lVar1 = 0;
  if (item == 3) {
    MoveCodeStreamExtra = 1;
    uVar2 = SEXT24(codeStream[1]);
    if (uVar2 < 6) {
      pcVar3 = *(char **)stackObject->data;
      if (pcVar3 == (char *)0x0) {
        EVENT_ChangeOperandToNumber(stackObject,0,0);
        lVar1 = 1;
      }
      else {
        if (*pcVar3 == '\x02') {
          stack->topOfStack = stack->topOfStack + -1;
          EVENT_AddShortPointerToStack(stack,(short *)(pcVar3 + uVar2 * 2 + 6));
          lVar1 = 1;
        }
        else {
          stack->topOfStack = stack->topOfStack + -1;
          EVENT_AddCharPointerToStack(stack,pcVar3 + uVar2 + 5);
          lVar1 = 1;
        }
      }
    }
  }
  return lVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformSubListObjectAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a1*/, long item /*$a2*/)
 // line 2701, offset 0x800634b0
	/* begin block 1 */
		// Start line: 2703
		// Start offset: 0x800634B0
		// Variables:
	// 		long retValue; // $a0
	/* end block 1 */
	// End offset: 0x800634DC
	// End Line: 2722

	/* begin block 2 */
		// Start line: 5854
	/* end block 2 */
	// End Line: 5855

	/* begin block 3 */
		// Start line: 5855
	/* end block 3 */
	// End Line: 5856

	/* begin block 4 */
		// Start line: 5861
	/* end block 4 */
	// End Line: 5862

/* File: C:\kain2\game\EVENT.C */

long EVENT_TransformSubListObjectAttribute(_PCodeStack *stack,StackType *stackObject,long item)

{
  int iVar1;
  
  iVar1 = *(int *)(stackObject->data + 8);
  if (iVar1 < 5) {
    *(long *)(stackObject->data + iVar1 * 4 + 0xc) = item;
    *(int *)(stackObject->data + 8) = iVar1 + 1;
  }
  return (uint)(iVar1 < 5);
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformListObjectAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a1*/, long item /*$a2*/)
 // line 2725, offset 0x800634e4
	/* begin block 1 */
		// Start line: 2727
		// Start offset: 0x800634E4
		// Variables:
	// 		long retValue; // $a0
	/* end block 1 */
	// End offset: 0x80063510
	// End Line: 2746

	/* begin block 2 */
		// Start line: 5903
	/* end block 2 */
	// End Line: 5904

	/* begin block 3 */
		// Start line: 5904
	/* end block 3 */
	// End Line: 5905

	/* begin block 4 */
		// Start line: 5910
	/* end block 4 */
	// End Line: 5911

/* File: C:\kain2\game\EVENT.C */

long EVENT_TransformListObjectAttribute(_PCodeStack *stack,StackType *stackObject,long item)

{
  int iVar1;
  
  iVar1 = *(int *)(stackObject->data + 0x18);
  if (iVar1 < 5) {
    *(long *)(stackObject->data + iVar1 * 4 + 4) = item;
    *(int *)(stackObject->data + 0x18) = iVar1 + 1;
  }
  return (uint)(iVar1 < 5);
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformCameraObjectAttribute(struct _PCodeStack *stack /*$s0*/, struct StackType *stackObject /*$a0*/, long item /*$a2*/, short *codeStream /*$a3*/)
 // line 2749, offset 0x80063518
	/* begin block 1 */
		// Start line: 2750
		// Start offset: 0x80063518
		// Variables:
	// 		long retValue; // $v1
	// 		struct Camera *camera; // $t0

		/* begin block 1.1 */
			// Start line: 2761
			// Start offset: 0x800635A0
			// Variables:
		// 		short time; // $a1
		/* end block 1.1 */
		// End offset: 0x800635F4
		// End Line: 2775

		/* begin block 1.2 */
			// Start line: 2791
			// Start offset: 0x80063614
		/* end block 1.2 */
		// End offset: 0x80063614
		// End Line: 2793
	/* end block 1 */
	// End offset: 0x80063630
	// End Line: 2822

	/* begin block 2 */
		// Start line: 5952
	/* end block 2 */
	// End Line: 5953

/* File: C:\kain2\game\EVENT.C */

long EVENT_TransformCameraObjectAttribute
               (_PCodeStack *stack,StackType *stackObject,long item,short *codeStream)

{
  if (item < 0x4a) {
    if (((item < 0x43) && (item != 9)) && (item != 0x10)) {
      return 0;
    }
  }
  else {
    if (item != 0x68) {
      if (item < 0x69) {
        if (item != 0x5d) {
          return 0;
        }
        if (codeStream == (short *)0x0) {
          return 1;
        }
        MoveCodeStreamExtra = 2;
        CAMERA_SetShake(*(Camera **)stackObject->data,(int)codeStream[1],
                        ((int)codeStream[2] << 0xc) / 100);
        stack->topOfStack = stack->topOfStack + -1;
        return 1;
      }
      if (item != 0x69) {
        if (item == 0x75) {
          EVENT_ChangeOperandToNumber
                    (stackObject,
                     (uint)(((*(Camera **)stackObject->data)->data).Cinematic.cinema_done != 0),0);
          return 1;
        }
        return 0;
      }
      if (codeStream != (short *)0x0) {
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
 // line 2825, offset 0x80063644
	/* begin block 1 */
		// Start line: 2826
		// Start offset: 0x80063644
		// Variables:
	// 		long retValue; // $v1
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 2848
			// Start offset: 0x800636CC
			// Variables:
		// 		long maxKeyFrames; // $v0
		/* end block 1.1 */
		// End offset: 0x80063700
		// End Line: 2859
	/* end block 1 */
	// End offset: 0x80063734
	// End Line: 2877

	/* begin block 2 */
		// Start line: 6124
	/* end block 2 */
	// End Line: 6125

/* File: C:\kain2\game\EVENT.C */

long EVENT_TransformSplineAttribute
               (_PCodeStack *stack,StackType *stackObject,long item,short *codeStream)

{
  ushort uVar1;
  short sVar2;
  _Instance *instance;
  
  instance = *(_Instance **)stackObject->data;
  if (item == 0x22) {
    *(uint *)(stackObject->data + 0x14) = *(uint *)(stackObject->data + 0x14) | 4;
  }
  else {
    if (item < 0x23) {
      if (item == 0x1f) {
        MoveCodeStreamExtra = 2;
        instance->clipBeg = codeStream[1];
        uVar1 = instance->splineFlags;
        instance->clipEnd = codeStream[2];
        instance->splineFlags = uVar1 | 2;
        if (*(int *)&instance->clipBeg == -1) {
          instance->splineFlags = uVar1 & 0xfffd;
        }
        else {
          sVar2 = SCRIPTCountFramesInSpline(instance);
          if (sVar2 <= instance->clipEnd) {
            instance->clipEnd = sVar2;
          }
          if (instance->clipBeg < 0) {
            instance->clipBeg = 0;
          }
        }
      }
      else {
        *(long *)(stackObject->data + 8) = item;
      }
    }
    else {
      if (item == 0x23) {
        *(uint *)(stackObject->data + 0x14) = *(uint *)(stackObject->data + 0x14) | 8;
      }
      else {
        *(long *)(stackObject->data + 8) = item;
      }
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformIntroAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$s3*/, long item /*$a2*/)
 // line 2880, offset 0x80063748
	/* begin block 1 */
		// Start line: 2881
		// Start offset: 0x80063748
		// Variables:
	// 		long retValue; // $v0
	// 		long x; // $s0
	// 		long y; // $s1
	// 		long z; // $s2
	// 		struct Intro *intro; // $a3

		/* begin block 1.1 */
			// Start line: 2892
			// Start offset: 0x80063794
		/* end block 1.1 */
		// End offset: 0x800637E0
		// End Line: 2907

		/* begin block 1.2 */
			// Start line: 2914
			// Start offset: 0x800637E0
			// Variables:
		// 		struct Rotation3d vector; // stack offset -48
		/* end block 1.2 */
		// End offset: 0x800637E0
		// End Line: 2917
	/* end block 1 */
	// End offset: 0x80063848
	// End Line: 2983

	/* begin block 2 */
		// Start line: 6247
	/* end block 2 */
	// End Line: 6248

/* File: C:\kain2\game\EVENT.C */

long EVENT_TransformIntroAttribute(_PCodeStack *stack,StackType *stackObject,long item)

{
  short x;
  short y;
  short z;
  _StreamUnit *p_Var1;
  void *pointer;
  Rotation3d local_30;
  
  pointer = *(void **)stackObject->data;
  switch(item) {
  case 5:
    if ((*(uint *)((int)pointer + 0x2c) & 0x4000) != 0) {
      x = *(short *)((int)pointer + 0x20);
      y = *(short *)((int)pointer + 0x22);
      z = *(short *)((int)pointer + 0x24);
      p_Var1 = STREAM_WhichUnitPointerIsIn(pointer);
      EVENT_ChangeOperandVector3d(stackObject,x,y,z,p_Var1->StreamUnitID);
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
    EVENT_ChangeOperandRotation3d(stackObject,&local_30);
    break;
  case 0x3e:
  case 0x8a:
  case 0x92:
  case 0xa0:
  case 0xa6:
    *(long *)(stackObject->data + 4) = item;
    break;
  case 0x3f:
    EVENT_ChangeOperandToNumber(stackObject,0,0);
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_ParseOperand2(struct StackType *operand2 /*$a0*/, long *error /*$s0*/, long *trueValue /*$s1*/)
 // line 2985, offset 0x80063864
	/* begin block 1 */
		// Start line: 2986
		// Start offset: 0x80063864
		// Variables:
	// 		long number; // $v0

		/* begin block 1.1 */
			// Start line: 2991
			// Start offset: 0x80063884
			// Variables:
		// 		short flags; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x800638A8
		// End Line: 2999
	/* end block 1 */
	// End offset: 0x800638A8
	// End Line: 3001

	/* begin block 2 */
		// Start line: 6498
	/* end block 2 */
	// End Line: 6499

/* File: C:\kain2\game\EVENT.C */

long EVENT_ParseOperand2(StackType *operand2,long *error,long *trueValue)

{
  long lVar1;
  short asStack24 [4];
  
  lVar1 = -1;
  if (((operand2 != (StackType *)0x0) &&
      (lVar1 = EVENT_GetScalerValueFromOperand(operand2,error,asStack24), *error == 0)) &&
     (lVar1 == 0)) {
    *trueValue = 0;
  }
  return lVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoVMObjectAction(struct EventVmObject *vmobject /*$s0*/, struct StackType *operand2 /*$a0*/)
 // line 3003, offset 0x800638bc
	/* begin block 1 */
		// Start line: 3004
		// Start offset: 0x800638BC
		// Variables:
	// 		long result; // $s1
	// 		long trueValue; // stack offset -20
	// 		long number; // $a2
	// 		long error; // stack offset -24
	/* end block 1 */
	// End offset: 0x80063A60
	// End Line: 3078

	/* begin block 2 */
		// Start line: 6535
	/* end block 2 */
	// End Line: 6536

/* File: C:\kain2\game\EVENT.C */

long EVENT_DoVMObjectAction(EventVmObject *vmobject,StackType *operand2)

{
  ushort uVar1;
  long table;
  int iVar2;
  _VMObject *p_Var3;
  long local_18;
  uint local_14;
  
  local_14 = 1;
  local_18 = 1;
  if (vmobject->attribute == -1) {
    return 0;
  }
  table = EVENT_ParseOperand2(operand2,&local_18,(long *)&local_14);
  iVar2 = vmobject->attribute;
  if (iVar2 == 0xe) {
    local_14 = (uint)(local_14 == 0);
  }
  else {
    if (0xe < iVar2) {
      if (iVar2 == 99) {
        if (table == -1) {
          return 0;
        }
        if (table < 0) {
          return 0;
        }
        if (vmobject->vmObjectPtr->numVMOffsetTables <= table) {
          return 0;
        }
        VM_VMObjectSetTable(vmobject->level,vmobject->vmObjectPtr,table);
        if ((vmobject->vmObjectPtr->flags & 2) != 0) {
          if (vmobject->level != (Level *)0x0) {
            VM_ProcessVMObjectSetColor_S();
            return 0;
          }
          return 0;
        }
        return 0;
      }
      if (iVar2 != 100) {
        return 0;
      }
      if (table == -1) {
        return 1;
      }
      vmobject->vmObjectPtr->timer = table;
      if ((vmobject->vmObjectPtr->flags & 2) == 0) {
        return 1;
      }
      if (vmobject->level != (Level *)0x0) {
        VM_ProcessVMObjectSetColor_S();
        return 1;
      }
      return 1;
    }
    if (iVar2 != 0xd) {
      return 0;
    }
  }
  if (local_14 == 0) {
    p_Var3 = vmobject->vmObjectPtr;
    uVar1 = p_Var3->flags | 2;
  }
  else {
    p_Var3 = vmobject->vmObjectPtr;
    uVar1 = p_Var3->flags & 0xfffd;
  }
  p_Var3->flags = uVar1;
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_GetVMObjectValue(struct EventVmObject *vmobject /*$a0*/)
 // line 3081, offset 0x80063a7c
	/* begin block 1 */
		// Start line: 3083
		// Start offset: 0x80063A7C
		// Variables:
	// 		long value; // $a1
	// 		long trueValue; // $a2
	/* end block 1 */
	// End offset: 0x80063B34
	// End Line: 3111

	/* begin block 2 */
		// Start line: 6693
	/* end block 2 */
	// End Line: 6694

	/* begin block 3 */
		// Start line: 6694
	/* end block 3 */
	// End Line: 6695

/* File: C:\kain2\game\EVENT.C */

long EVENT_GetVMObjectValue(EventVmObject *vmobject)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = vmobject->attribute;
  uVar2 = 1;
  if (iVar1 == 0xe) {
    uVar2 = 0;
  }
  else {
    if (0xe < iVar1) {
      if (iVar1 == 99) {
        return (int)vmobject->vmObjectPtr->currentIdx;
      }
      if (iVar1 != 100) {
        return 0;
      }
      return vmobject->vmObjectPtr->timer % vmobject->vmObjectPtr->curVMOffsetTable->numVMOffsets;
    }
    if (iVar1 == -1) {
      return 1;
    }
    if (iVar1 != 0xd) {
      return 0;
    }
  }
  if ((vmobject->vmObjectPtr->flags & 2) != 0) {
    uVar2 = (uint)(uVar2 == 0);
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoGameAction(struct GameObject *gameObject /*$s2*/, struct StackType *operand2 /*$a0*/)
 // line 3114, offset 0x80063b44
	/* begin block 1 */
		// Start line: 3115
		// Start offset: 0x80063B44
		// Variables:
	// 		long error; // stack offset -32
	// 		long number; // $s0
	// 		long trueValue; // stack offset -28
	/* end block 1 */
	// End offset: 0x80063E00
	// End Line: 3239

	/* begin block 2 */
		// Start line: 6759
	/* end block 2 */
	// End Line: 6760

/* File: C:\kain2\game\EVENT.C */

long EVENT_DoGameAction(GameObject *gameObject,StackType *operand2)

{
  long modifier;
  int iVar1;
  long local_20;
  long local_1c;
  
  local_20 = 1;
  local_1c = 1;
  if (gameObject->attribute != -1) {
    modifier = EVENT_ParseOperand2(operand2,&local_20,&local_1c);
    iVar1 = gameObject->attribute;
    if (iVar1 == 0x87) {
      SOUND_SetMusicModifier(modifier);
    }
    else {
      if (iVar1 < 0x88) {
        if (iVar1 == 0x59) {
          if (local_20 == 0) {
            FX_Start_Rain(modifier);
          }
          else {
            FX_Start_Rain(100);
          }
        }
        else {
          if (iVar1 < 0x5a) {
            if (iVar1 == 2) {
              if (modifier == 2) {
                GAMELOOP_SetGameTime(700);
              }
              else {
                if (modifier < 3) {
                  if (modifier == 1) {
                    GAMELOOP_SetGameTime(600);
                  }
                }
                else {
                  if (modifier == 3) {
                    GAMELOOP_SetGameTime(0x708);
                  }
                  else {
                    if (modifier == 4) {
                      GAMELOOP_SetGameTime(0x76c);
                    }
                  }
                }
              }
            }
            else {
              if (iVar1 == 0x58) {
                if (local_20 == 0) {
                  FX_Start_Snow(modifier);
                }
                else {
                  FX_Start_Snow(100);
                }
              }
            }
          }
          else {
            if (iVar1 == 0x76) {
              if ((-1 < modifier) && ((DAT_800d218c & 0x80000) != 0)) {
                if (WaitingForVoiceNumber == modifier) {
                  iVar1 = VOICEXA_IsPlaying();
                  if (iVar1 == 2) {
                    WaitingForVoiceNumber = -1;
                    return 1;
                  }
                }
                else {
                  iVar1 = VOICEXA_IsPlaying();
                  if (iVar1 != 2) {
                    LOAD_PlayXA(modifier);
                    WaitingForVoiceNumber = modifier;
                    EventAbortLine = 1;
                    return 1;
                  }
                }
                EventAbortLine = 1;
              }
            }
            else {
              if ((iVar1 == 0x77) && (modifier - 1U < 0x7f)) {
                SOUND_SetVoiceVolume(modifier);
              }
            }
          }
        }
      }
      else {
        if (iVar1 == 0x93) {
          HINT_StopHint();
        }
        else {
          if (iVar1 < 0x94) {
            if (iVar1 == 0x88) {
              SOUND_ResetMusicModifier(modifier);
            }
            else {
              if (iVar1 == 0x8e) {
                HINT_StartHint((short)modifier);
              }
            }
          }
          else {
            if (iVar1 == 0x96) {
              CINE_PlayIngame(modifier);
            }
            else {
              if (iVar1 == 0x9c) {
                HINT_KillSpecificHint((short)modifier);
              }
            }
          }
        }
      }
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoSignalAction(struct SignalObject *signalObject /*$s0*/, struct StackType *operand2 /*$a0*/)
 // line 3242, offset 0x80063e20
	/* begin block 1 */
		// Start line: 3243
		// Start offset: 0x80063E20
		// Variables:
	// 		long trueValue; // stack offset -12
	// 		long number; // $v1
	// 		long error; // stack offset -16
	/* end block 1 */
	// End offset: 0x80063E88
	// End Line: 3275

	/* begin block 2 */
		// Start line: 7017
	/* end block 2 */
	// End Line: 7018

/* File: C:\kain2\game\EVENT.C */

long EVENT_DoSignalAction(SignalObject *signalObject,StackType *operand2)

{
  long lStack16;
  long local_c;
  
  local_c = 1;
  if (((signalObject->attribute != -1) &&
      (EVENT_ParseOperand2(operand2,&lStack16,&local_c), signalObject->attribute == 0x1a)) &&
     (local_c != 0)) {
    COLLIDE_HandleSignal
              (DAT_800d20f8,signalObject->msignal->signalList,signalObject->msignal->numSignals,0);
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformSignalAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a0*/, long item /*$a2*/)
 // line 3278, offset 0x80063e9c
	/* begin block 1 */
		// Start line: 3279
		// Start offset: 0x80063E9C
		// Variables:
	// 		long retValue; // $v1
	// 		struct _MultiSignal *msignal; // $a1
	/* end block 1 */
	// End offset: 0x80063EE4
	// End Line: 3307

	/* begin block 2 */
		// Start line: 7094
	/* end block 2 */
	// End Line: 7095

/* File: C:\kain2\game\EVENT.C */

long EVENT_TransformSignalAttribute(_PCodeStack *stack,StackType *stackObject,long item)

{
  if (item == 0x1a) {
    *(undefined4 *)(stackObject->data + 4) = 0x1a;
  }
  else {
    if (item != 0x32) {
      return 0;
    }
    EVENT_ChangeOperandToNumber(stackObject,(uint)*(ushort *)(*(int *)stackObject->data + 6) & 1,0);
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformRotation3dAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a1*/, long item /*$a2*/, short *codeStream /*$a3*/)
 // line 3311, offset 0x80063ef4
	/* begin block 1 */
		// Start line: 3313
		// Start offset: 0x80063EF4
		// Variables:
	// 		long retValue; // $v0
	/* end block 1 */
	// End offset: 0x80063F24
	// End Line: 3333

	/* begin block 2 */
		// Start line: 7168
	/* end block 2 */
	// End Line: 7169

	/* begin block 3 */
		// Start line: 7169
	/* end block 3 */
	// End Line: 7170

	/* begin block 4 */
		// Start line: 7171
	/* end block 4 */
	// End Line: 7172

/* File: C:\kain2\game\EVENT.C */

long EVENT_TransformRotation3dAttribute
               (_PCodeStack *stack,StackType *stackObject,long item,short *codeStream)

{
  if ((5 < item) && ((item < 9 || ((item < 99 && (0x5f < item)))))) {
    *(long *)(stackObject->data + 0x10) = item;
    return 1;
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformVector3dAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a0*/, long item /*$a2*/, short *codeStream /*$a3*/)
 // line 3335, offset 0x80063f2c
	/* begin block 1 */
		// Start line: 3336
		// Start offset: 0x80063F2C
		// Variables:
	// 		long retValue; // $a2
	/* end block 1 */
	// End offset: 0x80064018
	// End Line: 3388

	/* begin block 2 */
		// Start line: 7216
	/* end block 2 */
	// End Line: 7217

/* File: C:\kain2\game\EVENT.C */

long EVENT_TransformVector3dAttribute
               (_PCodeStack *stack,StackType *stackObject,long item,short *codeStream)

{
  short sVar1;
  long item_00;
  
  switch(item) {
  case 6:
    item_00 = (long)*(short *)stackObject->data;
    goto LAB_80063f80;
  case 7:
    item_00 = (long)*(short *)(stackObject->data + 2);
    goto LAB_80063f80;
  case 8:
    item_00 = (long)*(short *)(stackObject->data + 4);
LAB_80063f80:
    EVENT_ChangeOperandToNumber(stackObject,item_00,0);
    item_00 = 1;
    break;
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
 // line 3391, offset 0x80064028
	/* begin block 1 */
		// Start line: 7345
	/* end block 1 */
	// End Line: 7346

/* File: C:\kain2\game\EVENT.C */

void EVENT_ModifyObjectToStackWithAttribute(_PCodeStack *stack,long item,short *codeStream)

{
  if (stack->topOfStack != 0) {
    EVENT_TransformObjectOnStack(stack,item,codeStream);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoInstanceAnimateTextureAction(struct InstanceAnimateTexture *instanceAniTexture /*$s1*/, struct StackType *operand2 /*$a0*/)
 // line 3414, offset 0x80064058
	/* begin block 1 */
		// Start line: 3415
		// Start offset: 0x80064058
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $a2
	// 		long result; // $s0
	// 		long error; // stack offset -24
	/* end block 1 */
	// End offset: 0x80064148
	// End Line: 3468

	/* begin block 2 */
		// Start line: 7391
	/* end block 2 */
	// End Line: 7392

/* File: C:\kain2\game\EVENT.C */

long EVENT_DoInstanceAnimateTextureAction
               (InstanceAnimateTexture *instanceAniTexture,StackType *operand2)

{
  long lVar1;
  long lVar2;
  long local_18;
  uint local_14;
  
  local_14 = 1;
  local_18 = 1;
  if (instanceAniTexture->attribute == -1) {
    lVar2 = 1;
  }
  else {
    lVar1 = EVENT_ParseOperand2(operand2,&local_18,(long *)&local_14);
    lVar2 = 0;
    switch(instanceAniTexture->attribute) {
    case 0xe:
      local_14 = local_14 ^ 1;
    case 0xd:
    case 0x29:
      lVar2 = 1;
      if (local_14 == 0) {
        instanceAniTexture->instance->flags = instanceAniTexture->instance->flags | 0x80;
      }
      else {
        instanceAniTexture->instance->flags = instanceAniTexture->instance->flags & 0xffffff7f;
      }
      break;
    case 0xf:
    case 0x28:
      lVar2 = 0;
      if (local_18 == 0) {
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
 // line 3471, offset 0x80064160
	/* begin block 1 */
		// Start line: 7516
	/* end block 1 */
	// End Line: 7517

	/* begin block 2 */
		// Start line: 7517
	/* end block 2 */
	// End Line: 7518

/* File: C:\kain2\game\EVENT.C */

void EVENT_ResetAllSplineFlags(MultiSpline *spline)

{
  Spline *pSVar1;
  RSpline *pRVar2;
  
  pSVar1 = spline->positional;
  if (pSVar1 != (Spline *)0x0) {
    pSVar1->flags = pSVar1->flags & 0xf8;
  }
  pRVar2 = spline->rotational;
  if (pRVar2 != (RSpline *)0x0) {
    pRVar2->flags = pRVar2->flags & 0xf8;
  }
  pSVar1 = spline->scaling;
  if (pSVar1 != (Spline *)0x0) {
    pSVar1->flags = pSVar1->flags & 0xf8;
  }
  pSVar1 = spline->color;
  if (pSVar1 != (Spline *)0x0) {
    pSVar1->flags = pSVar1->flags & 0xf8;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_SetSplineLoop(struct MultiSpline *spline /*$a0*/)
 // line 3479, offset 0x800641e8
	/* begin block 1 */
		// Start line: 7532
	/* end block 1 */
	// End Line: 7533

	/* begin block 2 */
		// Start line: 7533
	/* end block 2 */
	// End Line: 7534

/* File: C:\kain2\game\EVENT.C */

void EVENT_SetSplineLoop(MultiSpline *spline)

{
  Spline *pSVar1;
  RSpline *pRVar2;
  
  pSVar1 = spline->positional;
  if (pSVar1 != (Spline *)0x0) {
    pSVar1->flags = pSVar1->flags | 2;
  }
  pRVar2 = spline->rotational;
  if (pRVar2 != (RSpline *)0x0) {
    pRVar2->flags = pRVar2->flags | 2;
  }
  pSVar1 = spline->scaling;
  if (pSVar1 != (Spline *)0x0) {
    pSVar1->flags = pSVar1->flags | 2;
  }
  pSVar1 = spline->color;
  if (pSVar1 != (Spline *)0x0) {
    pSVar1->flags = pSVar1->flags | 2;
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoSplineAction(struct InstanceSpline *instanceSpline /*$s3*/, struct StackType *operand2 /*$a0*/)
 // line 3487, offset 0x80064270
	/* begin block 1 */
		// Start line: 3488
		// Start offset: 0x80064270
		// Variables:
	// 		long trueValue; // stack offset -28
	// 		long number; // $s0
	// 		long result; // $s4
	// 		long error; // stack offset -32

		/* begin block 1.1 */
			// Start line: 3499
			// Start offset: 0x800642B4
			// Variables:
		// 		struct _Instance *instance; // $s1
		// 		struct MultiSpline *spline; // $s2

			/* begin block 1.1.1 */
				// Start line: 3551
				// Start offset: 0x80064374
				// Variables:
			// 		long curKeyFrame; // $a0

				/* begin block 1.1.1.1 */
					// Start line: 3559
					// Start offset: 0x80064384
					// Variables:
				// 		long maxKeyFrames; // $v1
				/* end block 1.1.1.1 */
				// End offset: 0x800643A4
				// End Line: 3567
			/* end block 1.1.1 */
			// End offset: 0x80064498
			// End Line: 3611
		/* end block 1.1 */
		// End offset: 0x80064618
		// End Line: 3651
	/* end block 1 */
	// End offset: 0x80064618
	// End Line: 3653

	/* begin block 2 */
		// Start line: 7548
	/* end block 2 */
	// End Line: 7549

/* File: C:\kain2\game\EVENT.C */

long EVENT_DoSplineAction(InstanceSpline *instanceSpline,StackType *operand2)

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
  if (instanceSpline->attribute == -1) {
    return 1;
  }
  instance = instanceSpline->instance;
  spline = instanceSpline->spline;
  iVar3 = EVENT_ParseOperand2(operand2,&lStack32,(long *)&local_1c);
  switch(instanceSpline->attribute) {
  case 0xd:
  case 0x29:
    goto switchD_800642f4_caseD_d;
  case 0xe:
    local_1c = local_1c ^ 1;
switchD_800642f4_caseD_d:
    lVar9 = 1;
    if (local_1c == 0) {
      uVar6 = instance->flags;
      uVar4 = 0xfdffffff;
LAB_800644a4:
      instance->flags = uVar6 & uVar4;
    }
    else {
      uVar4 = instance->flags;
      uVar6 = 0x2000000;
LAB_8006448c:
      instance->flags = uVar4 | uVar6;
    }
switchD_800642f4_caseD_12:
    return lVar9;
  case 0xf:
  case 0x28:
    if (iVar3 == -1) {
      return 0;
    }
    SCRIPT_InstanceSplineSet
              (instance,(short)iVar3,(SplineDef *)0x0,(SplineDef *)0x0,(SplineDef *)0x0);
    uVar4 = 0xfdff0000;
    goto LAB_8006449c;
  case 0x10:
    EVENT_ResetAllSplineFlags(spline);
    instance->splineFlags = instance->splineFlags & 0xff8f;
    if (iVar3 == 2) {
      EVENT_SetSplineLoop(spline);
      uVar2 = instance->splineFlags | 0x20;
    }
    else {
      if ((iVar3 < 3) && (iVar3 == 1)) {
        pSVar7 = spline->positional;
        if (pSVar7 != (Spline *)0x0) {
          pSVar7->flags = pSVar7->flags | 1;
        }
        pRVar8 = spline->rotational;
        if (pRVar8 != (RSpline *)0x0) {
          pRVar8->flags = pRVar8->flags | 1;
        }
        pSVar7 = spline->scaling;
        if (pSVar7 != (Spline *)0x0) {
          pSVar7->flags = pSVar7->flags | 1;
        }
        pSVar7 = spline->color;
        if (pSVar7 != (Spline *)0x0) {
          pSVar7->flags = pSVar7->flags | 1;
        }
        uVar2 = instance->splineFlags | 0x10;
      }
      else {
        pSVar7 = spline->positional;
        if (pSVar7 != (Spline *)0x0) {
          pSVar7->flags = pSVar7->flags | 4;
        }
        pRVar8 = spline->rotational;
        if (pRVar8 != (RSpline *)0x0) {
          pRVar8->flags = pRVar8->flags | 4;
        }
        pSVar7 = spline->scaling;
        if (pSVar7 != (Spline *)0x0) {
          pSVar7->flags = pSVar7->flags | 4;
        }
        pSVar7 = spline->color;
        if (pSVar7 != (Spline *)0x0) {
          pSVar7->flags = pSVar7->flags | 4;
        }
        uVar2 = instance->splineFlags | 0x40;
      }
    }
    instance->splineFlags = uVar2;
    return 0;
  case 0x11:
    uVar4 = 0xfeff0000;
    if (iVar3 < 1) goto LAB_80064484;
LAB_8006449c:
    uVar6 = instance->flags;
    uVar4 = uVar4 | 0xffff;
    goto LAB_800644a4;
  default:
    goto switchD_800642f4_caseD_12;
  case 0x1c:
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    else {
      sVar1 = SCRIPTCountFramesInSpline(instance);
      if ((int)sVar1 <= iVar3) {
        iVar3 = (int)sVar1;
      }
    }
    lVar5 = EVENT_GetSplineFrameNumber(instanceSpline);
    if (lVar5 == iVar3) {
      SCRIPT_InstanceSplineSet
                (instance,(short)iVar3,(SplineDef *)0x0,(SplineDef *)0x0,(SplineDef *)0x0);
      uVar4 = 0xfdff0000;
      goto LAB_8006449c;
    }
    instance->splineFlags = instance->splineFlags | 1;
    instance->targetFrame = (short)iVar3;
    instance->flags = instance->flags | 0x2000000;
    if (iVar3 < lVar5) {
      uVar4 = instanceSpline->splineFlags & 4;
      instanceSpline->splineFlags = uVar4;
      if (uVar4 != 0) {
        EVENT_ResetAllSplineFlags(spline);
        EVENT_SetSplineLoop(spline);
        instance->splineFlags = instance->splineFlags | 0x20;
        instance->flags = instance->flags & 0xfeffffff;
        return 0;
      }
    }
    else {
      uVar4 = instanceSpline->splineFlags & 8;
      instanceSpline->splineFlags = uVar4;
      if (uVar4 == 0) {
        uVar4 = 0xfeff0000;
        goto LAB_8006449c;
      }
      EVENT_ResetAllSplineFlags(spline);
      EVENT_SetSplineLoop(spline);
      instance->splineFlags = instance->splineFlags | 0x20;
    }
LAB_80064484:
    uVar4 = instance->flags;
    uVar6 = 0x1000000;
    goto LAB_8006448c;
  }
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoAnimateAction(struct InstanceAnimate *instanceAnimate /*$s1*/, struct StackType *operand2 /*$s3*/)
 // line 3656, offset 0x8006463c
	/* begin block 1 */
		// Start line: 3657
		// Start offset: 0x8006463C
		// Variables:
	// 		long trueValue; // stack offset -28
	// 		long number; // $a0
	// 		long result; // $s2
	// 		long error; // stack offset -32
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 3722
			// Start offset: 0x80064718
			// Variables:
		// 		struct _Instance *hostInstance; // $v0
		/* end block 1.1 */
		// End offset: 0x80064718
		// End Line: 3723
	/* end block 1 */
	// End offset: 0x800648F0
	// End Line: 3877

	/* begin block 2 */
		// Start line: 7909
	/* end block 2 */
	// End Line: 7910

/* File: C:\kain2\game\EVENT.C */

long EVENT_DoAnimateAction(InstanceAnimate *instanceAnimate,StackType *operand2)

{
  long lVar1;
  int Data;
  short sVar2;
  int Message;
  _Instance *instance;
  long lVar3;
  long lStack32;
  uint local_1c;
  
  lVar3 = 0;
  local_1c = 1;
  if (instanceAnimate->attribute == -1) {
    return 0;
  }
  instance = instanceAnimate->instance;
  lVar1 = EVENT_ParseOperand2(operand2,&lStack32,(long *)&local_1c);
  sVar2 = (short)lVar1;
  switch(instanceAnimate->attribute) {
  case 0xe:
    local_1c = local_1c ^ 1;
  case 0xd:
  case 0x29:
    if (local_1c == 0) {
      Message = 0x8000010;
      Data = 0;
    }
    else {
      if ((instance->aliasCommand).hostInstance == (_Instance *)0x0) {
        Data = SetAnimationInstanceSwitchData
                         (instance,(int)(instance->aliasCommand).newanim,
                          (int)(instance->aliasCommand).newframe,
                          (int)(instance->aliasCommand).interpframes,1);
        Message = 0x8000008;
      }
      else {
        Data = SetActionPlayHostAnimationData
                         (instance,(instance->aliasCommand).hostInstance,
                          (int)(instance->aliasCommand).newanim,
                          (int)(instance->aliasCommand).newframe,
                          (int)(instance->aliasCommand).interpframes,1);
        Message = 0x40003;
      }
    }
    INSTANCE_Post(instance,Message,Data);
    memset();
    lVar3 = 1;
    break;
  case 0xf:
  case 0x28:
    lVar3 = 0;
    if (lVar1 != -1) {
      (instance->aliasCommand).newframe = sVar2;
    }
    break;
  case 0x1e:
    lVar3 = 1;
    if (lVar1 != -1) {
      (instance->aliasCommand).newanim = sVar2;
    }
    break;
  case 0x2a:
    if ((instance->aliasCommand).hostInstance == (_Instance *)0x0) {
      Data = SetAnimationInstanceSwitchData
                       (instance,(int)(instance->aliasCommand).newanim,
                        (int)(instance->aliasCommand).newframe,
                        (int)(instance->aliasCommand).interpframes,2);
      Message = 0x8000008;
    }
    else {
      Data = SetActionPlayHostAnimationData
                       (instance,(instance->aliasCommand).hostInstance,
                        (int)(instance->aliasCommand).newanim,(int)(instance->aliasCommand).newframe
                        ,(int)(instance->aliasCommand).interpframes,2);
      Message = 0x40003;
    }
LAB_800648d4:
    INSTANCE_Post(instance,Message,Data);
    goto LAB_800648dc;
  case 0x65:
    if (operand2 != (StackType *)0x0) {
      if (operand2->id == 2) {
        (instance->aliasCommand).hostInstance = *(_Instance **)operand2->data;
      }
      else {
        EventAbortLine = 1;
        lVar3 = 0;
      }
    }
    break;
  case 0x66:
    lVar3 = 0;
    if (lVar1 != -1) {
      (instance->aliasCommand).interpframes = sVar2;
    }
    break;
  case 0x6b:
    if ((instance->aliasCommand).hostInstance == (_Instance *)0x0) {
      Data = SetAnimationInstanceSwitchData
                       (instance,(int)(instance->aliasCommand).newanim,
                        (int)(instance->aliasCommand).newframe,
                        (int)(instance->aliasCommand).interpframes,0);
      Message = 0x8000008;
    }
    else {
      Data = SetActionPlayHostAnimationData
                       (instance,(instance->aliasCommand).hostInstance,
                        (int)(instance->aliasCommand).newanim,(int)(instance->aliasCommand).newframe
                        ,(int)(instance->aliasCommand).interpframes,0);
      Message = 0x40003;
    }
    INSTANCE_Post(instance,Message,Data);
    Data = (int)(instance->aliasCommand).speed;
    if (0 < Data) {
      Message = 0x40020;
      goto LAB_800648d4;
    }
LAB_800648dc:
    memset();
    lVar3 = 1;
    break;
  case 0x84:
    (instance->aliasCommand).speed = sVar2;
  }
  return lVar3;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoInstanceAction(struct InstanceObject *instanceObject /*$s3*/, struct StackType *operand2 /*$s2*/, short *codeStream /*$s5*/)
 // line 3881, offset 0x80064910
	/* begin block 1 */
		// Start line: 3882
		// Start offset: 0x80064910
		// Variables:
	// 		long trueValue; // stack offset -36
	// 		long number; // $s0
	// 		long error; // stack offset -40
	// 		long result; // $s4
	// 		struct _Instance *instance; // $s1

		/* begin block 1.1 */
			// Start line: 4013
			// Start offset: 0x80064CA4
			// Variables:
		// 		int x; // $a0
		// 		int y; // $a1
		/* end block 1.1 */
		// End offset: 0x80064D04
		// End Line: 4031

		/* begin block 1.2 */
			// Start line: 4038
			// Start offset: 0x80064D20
			// Variables:
		// 		struct Object *object; // $s2
		// 		int i; // $s0
		/* end block 1.2 */
		// End offset: 0x80064D84
		// End Line: 4057

		/* begin block 1.3 */
			// Start line: 4078
			// Start offset: 0x80064DD4
			// Variables:
		// 		struct Intro *intro; // $a0
		/* end block 1.3 */
		// End offset: 0x80064E08
		// End Line: 4089

		/* begin block 1.4 */
			// Start line: 4121
			// Start offset: 0x80064E90
			// Variables:
		// 		struct Vector3d *vector3d; // $s0
		/* end block 1.4 */
		// End offset: 0x80064E90
		// End Line: 4124

		/* begin block 1.5 */
			// Start line: 4139
			// Start offset: 0x80064EE0
		/* end block 1.5 */
		// End offset: 0x80064EE0
		// End Line: 4145

		/* begin block 1.6 */
			// Start line: 4151
			// Start offset: 0x80064F1C
		/* end block 1.6 */
		// End offset: 0x80064F1C
		// End Line: 4157

		/* begin block 1.7 */
			// Start line: 4166
			// Start offset: 0x80064F68
		/* end block 1.7 */
		// End offset: 0x80064F68
		// End Line: 4171

		/* begin block 1.8 */
			// Start line: 4177
			// Start offset: 0x80064FA4
		/* end block 1.8 */
		// End offset: 0x80064FA4
		// End Line: 4183

		/* begin block 1.9 */
			// Start line: 4189
			// Start offset: 0x80064FE0
		/* end block 1.9 */
		// End offset: 0x80064FE0
		// End Line: 4195

		/* begin block 1.10 */
			// Start line: 4217
			// Start offset: 0x80065078
			// Variables:
		// 		struct EventTimer *timer; // $a2
		/* end block 1.10 */
		// End offset: 0x8006508C
		// End Line: 4222

		/* begin block 1.11 */
			// Start line: 4256
			// Start offset: 0x8006513C
		/* end block 1.11 */
		// End offset: 0x8006513C
		// End Line: 4261

		/* begin block 1.12 */
			// Start line: 4309
			// Start offset: 0x8006521C
		/* end block 1.12 */
		// End offset: 0x80065260
		// End Line: 4314
	/* end block 1 */
	// End offset: 0x8006538C
	// End Line: 4367

	/* begin block 2 */
		// Start line: 8374
	/* end block 2 */
	// End Line: 8375

/* File: C:\kain2\game\EVENT.C */

long EVENT_DoInstanceAction(InstanceObject *instanceObject,StackType *operand2,short *codeStream)

{
  long lVar1;
  Event *pEVar2;
  ScriptPCode *pSVar3;
  short *psVar4;
  uint type;
  ulong uVar5;
  EventTimer *pEVar6;
  int Data;
  Intro *pIVar7;
  int y;
  uint Message;
  _Instance *sender;
  Object *pOVar8;
  long lStack40;
  uint local_24;
  
  local_24 = 1;
  sender = instanceObject->instance;
  if (instanceObject->attribute == -1) {
    return 0;
  }
  type = EVENT_ParseOperand2(operand2,&lStack40,(long *)&local_24);
  switch(instanceObject->attribute) {
  case 4:
    if (0xff < (int)type) {
      INSTANCE_Post(sender,0x40017,type - 0x100);
      return 0;
    }
    if (type - 1 < 7) {
      ScriptKillInstance(sender,type);
      return 0;
    }
    if (type != 0) {
      return 0;
    }
    SAVE_UndestroyInstance(sender);
    return 0;
  case 10:
    goto switchD_80064994_caseD_a;
  case 0xb:
    local_24 = local_24 ^ 1;
switchD_80064994_caseD_a:
    if (local_24 == 0) {
      type = sender->flags;
      sender->flags2 = sender->flags2 & 0xdfffffff;
      sender->flags = type & 0xfffff7ff;
      sender->flags = type & 0xfffbf7ff;
      if ((sender->object->oflags2 & 0x80000U) != 0) {
        type = sender->flags2 & 0xefffffff;
        goto LAB_80064bd8;
      }
    }
    else {
      sender->flags = sender->flags | 0x800;
      sender->flags2 = sender->flags2 | 0x20000000;
      sender->flags = sender->flags | 0x40000;
      if ((sender->object->oflags2 & 0x80000U) != 0) {
        type = sender->flags2 | 0x10000000;
LAB_80064bd8:
        sender->flags2 = type;
      }
    }
    uVar5 = INSTANCE_Query(sender,1);
    if ((uVar5 & 0xe) == 0) {
      return 1;
    }
    Data = 0x40013;
    type = local_24;
LAB_80064c00:
    INSTANCE_Post(sender,Data,type);
    return 1;
  case 0x14:
    local_24 = local_24 ^ 1;
  case 0x15:
    if (local_24 == 0) {
      Data = 0x10002001;
      type = 0;
    }
    else {
      Data = 0x10002002;
      type = 0;
    }
    goto LAB_80064c00;
  case 0x20:
    if (type == 2) {
      type = 0x40012;
    }
    else {
      if ((int)type < 3) {
        if (type != 1) {
          return 0;
        }
        type = 0x40000;
      }
      else {
        if (type != 3) {
          if (type != 4) {
            return 0;
          }
          INSTANCE_Post(sender,0x40005,(int)&DAT_0000a000);
          return 0;
        }
        type = 0x40014;
      }
    }
    goto LAB_80065338;
  case 0x24:
    goto switchD_80064994_caseD_24;
  case 0x25:
    local_24 = local_24 ^ 1;
switchD_80064994_caseD_24:
    if (local_24 == 0) {
      uVar5 = INSTANCE_Query(instanceObject->instance,5);
      if ((uVar5 & 1) == 0) {
        return 0;
      }
      type = 0x800020;
    }
    else {
      uVar5 = INSTANCE_Query(instanceObject->instance,5);
      if ((uVar5 & 1) != 0) {
        return 0;
      }
      type = 0x800020;
    }
    goto LAB_80065338;
  case 0x26:
    local_24 = local_24 ^ 1;
  case 0x27:
    if (local_24 == 0) {
      type = 0x800000;
LAB_80065334:
      type = type | 0x22;
    }
    else {
      type = 0x800021;
    }
    goto LAB_80065338;
  case 0x33:
    if (type == 0xffffffff) {
      type = 0;
    }
    Message = 0x1000017;
    goto LAB_8006531c;
  case 0x34:
    if (local_24 == 0) {
      type = sender->flags & 0xfffff7ff;
    }
    else {
      type = sender->flags | 0x800;
    }
    goto LAB_80064aa4;
  case 0x35:
    if (local_24 == 0) {
      sender->flags2 = sender->flags2 & 0xdfffffff;
      sender->flags = sender->flags & 0xfffbffff;
      return 1;
    }
    sender->flags2 = sender->flags2 | 0x20000000;
    type = sender->flags | 0x40000;
LAB_80064aa4:
    sender->flags = type;
    return 1;
  case 0x36:
    Data = 0;
    if (type < 4) {
      y = 0;
      if (type == 1) {
        Data = 1;
      }
      else {
        if ((int)type < 2) {
          if (type == 0) {
            y = 1;
          }
        }
        else {
          if (type == 2) {
            Data = 0;
            y = -1;
          }
          else {
            if (type == 3) {
              Data = -1;
            }
          }
        }
      }
      Data = SetObjectData(Data,y,6,(_Instance *)0x0,0);
      y = 0x800000;
      goto LAB_8006528c;
    }
    break;
  case 0x37:
    pOVar8 = sender->object;
    Data = (int)pOVar8->numberOfEffects;
    if (Data != 0) {
      if (type == 0xffffffff) {
        y = 0;
        if (0 < Data) {
          do {
            FX_StartInstanceEffect(sender,pOVar8->effectList + y,0);
            y = y + 1;
          } while (y < pOVar8->numberOfEffects);
          return 0;
        }
      }
      else {
        if ((int)type < Data) {
          FX_StartInstanceEffect(sender,pOVar8->effectList + type,0);
          return 0;
        }
      }
    }
    break;
  case 0x40:
    if (type != 0) {
      type = 1;
    }
    Message = 0x100001a;
    goto LAB_8006531c;
  case 0x4b:
    if (operand2 != (StackType *)0x0) {
      if (operand2->id != 9) {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data,(int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      y = 0x40016;
      goto LAB_8006528c;
    }
    break;
  case 0x4c:
    if (operand2 != (StackType *)0x0) {
      if (operand2->id != 9) {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data,(int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      INSTANCE_Post(sender,0x4000a,Data);
      sender->currentStreamUnitID = *(long *)(operand2->data + 0x10);
    }
    break;
  case 0x4d:
    if (operand2 != (StackType *)0x0) {
      if (operand2->id != 0xe) {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data,(int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      y = 0x4000b;
      goto LAB_8006528c;
    }
    break;
  case 0x4e:
    goto switchD_80064994_caseD_4e;
  case 0x4f:
    local_24 = (uint)(local_24 == 0);
switchD_80064994_caseD_4e:
    if (sender != DAT_800d20f8) {
      INSTANCE_Post(sender,0x4000e,local_24);
      return 0;
    }
    INSTANCE_Post(sender,0x4000e,local_24);
    if (local_24 == 0) {
      DAT_800d220c = DAT_800d220c & 0xffffff6f;
      return 0;
    }
    DAT_800d220c = DAT_800d220c | 0x90;
    pEVar6 = EVENT_GetNextTimer();
    pSVar3 = currentActionScript;
    pEVar2 = currentEventInstance;
    lVar1 = EventCurrentEventIndex;
    if (pEVar6 != (EventTimer *)0x0) {
      EventAbortLine = 1;
      EventJustRecievedTimer = 1;
      *(short **)&pEVar6->actionScript = codeStream;
      pEVar6->flags = pEVar6->flags & 1U | 0x2000;
      *(Event **)&pEVar6->time = pEVar2;
      *(ScriptPCode **)&pEVar6->event = pSVar3;
      psVar4 = CurrentPuzzleLevel;
      pSVar3->conditionBits = pSVar3->conditionBits | 1;
      pEVar6->scriptPos = psVar4;
      *(long *)&pEVar6->level = lVar1;
    }
    break;
  case 0x50:
    if (operand2 != (StackType *)0x0) {
      if (operand2->id != 0xe) {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data,(int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      y = 0x4000d;
      goto LAB_8006528c;
    }
    break;
  case 0x53:
    if (operand2 != (StackType *)0x0) {
      if (operand2->id != 9) {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data,(int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      y = 0x4000f;
      goto LAB_8006528c;
    }
    break;
  case 0x54:
    if (local_24 != 0) {
      type = 0x40010;
      goto LAB_80065338;
    }
    break;
  case 0x55:
    INSTANCE_Post(sender,0x800027,local_24);
    return 0;
  case 0x5b:
    if ((int)type < 0) {
      return 0;
    }
    sender->lightGroup = (uchar)type;
    return 0;
  case 0x5c:
    if ((int)type < 0) {
      return 0;
    }
    sender->spectralLightGroup = (uchar)type;
    return 0;
  case 0x5e:
    goto switchD_80064994_caseD_5e;
  case 0x5f:
    local_24 = 0;
switchD_80064994_caseD_5e:
    INSTANCE_Post(sender,0x800029,local_24);
    return 0;
  case 0x67:
    if (local_24 == 0) {
      sender->flags = sender->flags | 0x400000;
    }
    else {
      sender->flags = sender->flags & 0xffbfffff;
    }
    break;
  case 0x6c:
    Data = (int)type % 0x168;
    if (Data < 0) {
      Data = Data + 0x168;
    }
    Data = rcos((Data * 0x1000) / 0x168);
    y = 0x4000005;
LAB_8006528c:
    INSTANCE_Post(sender,y,Data);
    return 0;
  case 0x6d:
    type = 0x4000006;
    goto LAB_80065338;
  case 0x6e:
    type = 0x40011;
LAB_80065338:
    INSTANCE_Post(sender,type,0);
    return 0;
  case 0x6f:
    INSTANCE_Post(sender,0x40015,1 << (type & 0x1f));
    return 0;
  case 0x72:
    if (operand2 != (StackType *)0x0) {
      if (operand2->id != 9) {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data,(int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      y = 0x4000c;
      goto LAB_8006528c;
    }
    break;
  case 0x74:
    INSTANCE_Post(sender,0x40006,type << 0xc);
    return 0;
  case 0x7b:
    if (operand2 != (StackType *)0x0) {
      if (operand2->id != 9) {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data,(int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      y = 0x40018;
      goto LAB_8006528c;
    }
    break;
  case 0x7c:
    type = type << 0xc;
    INSTANCE_Post(sender,0x40019,type);
  case 0xa3:
    Message = 0x1000000;
LAB_80065318:
    Message = Message | 0x22;
LAB_8006531c:
    INSTANCE_Post(sender,Message,type);
    return 0;
  case 0x85:
    Message = 0x40021;
    goto LAB_8006531c;
  case 0x8a:
    pIVar7 = sender->intro;
    if (pIVar7 == (Intro *)0x0) {
      return 0;
    }
    if (local_24 == 0) {
      pIVar7->flags = pIVar7->flags & 0xfffffbff;
    }
    else {
      pIVar7->flags = pIVar7->flags | 0x400;
    }
    break;
  case 0x8c:
    Message = 0x40000;
    goto LAB_80065318;
  case 0x8d:
    if (-1 < (int)type) {
      Data = SetMonsterAlarmData(sender,(_Position *)0x0,type);
      INSTANCE_Broadcast((_Instance *)0x0,10,0x1000011,Data);
      return 0;
    }
    break;
  case 0xa4:
    type = 0x1000000;
    goto LAB_80065334;
  case 0xa5:
    if (sender != DAT_800d20f8) {
      return 0;
    }
    if (local_24 == 0) {
      DAT_800d220c = DAT_800d220c & 0xffffff6f;
    }
    else {
      DAT_800d220c = DAT_800d220c | 0x90;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_GetTGroupValue(struct TGroupObject *terrainGroup /*$a0*/)
 // line 4370, offset 0x800653b4
	/* begin block 1 */
		// Start line: 4372
		// Start offset: 0x800653B4
		// Variables:
	// 		long value; // $a2
	// 		long trueValue; // $a3
	// 		struct BSPTree *bspTree; // $a1
	/* end block 1 */
	// End offset: 0x80065534
	// End Line: 4473

	/* begin block 2 */
		// Start line: 9383
	/* end block 2 */
	// End Line: 9384

	/* begin block 3 */
		// Start line: 9384
	/* end block 3 */
	// End Line: 9385

/* File: C:\kain2\game\EVENT.C */

long EVENT_GetTGroupValue(TGroupObject *terrainGroup)

{
  ushort uVar1;
  int iVar2;
  BSPTree *pBVar3;
  uint uVar4;
  
  iVar2 = terrainGroup->attribute;
  pBVar3 = terrainGroup->bspTree;
  uVar4 = 1;
  if (iVar2 == 0x35) {
    uVar1 = pBVar3->flags & 2;
  }
  else {
    if (iVar2 < 0x36) {
      if (iVar2 != 10) {
        if (iVar2 < 0xb) {
          if (iVar2 != -1) {
            return 0;
          }
          return -(terrainGroup->streamUnit->StreamUnitID * 0x100 + (int)pBVar3->ID);
        }
        if (iVar2 != 0xb) {
          if (iVar2 != 0x34) {
            return 0;
          }
          return (uint)(ushort)pBVar3->flags & 1;
        }
        uVar4 = 0;
      }
      if ((pBVar3->flags & 3U) == 3) {
        return uVar4;
      }
      return uVar4 ^ 1;
    }
    if (iVar2 == 0x73) {
      uVar1 = pBVar3->flags & 0x40;
    }
    else {
      if (iVar2 < 0x74) {
        if (iVar2 == 0x3c) {
          if ((pBVar3->flags & 0x800U) == 0) {
            return 0;
          }
          pBVar3->flags = pBVar3->flags & 0xf7ff;
          return 1;
        }
        if (iVar2 != 0x6a) {
          return 0;
        }
        if ((pBVar3->flags & 0x400U) == 0) {
          return 0;
        }
        pBVar3->flags = pBVar3->flags & 0xfbff;
        return 1;
      }
      if (iVar2 == 0x7d) {
        if ((pBVar3->flags & 0x2000U) == 0) {
          return 0;
        }
        pBVar3->flags = pBVar3->flags & 0xdfff;
        return 1;
      }
      if (iVar2 != 0x95) {
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
 // line 4476, offset 0x80065540
	/* begin block 1 */
		// Start line: 4477
		// Start offset: 0x80065540
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $v0
	// 		long error; // stack offset -24
	// 		long result; // $s2

		/* begin block 1.1 */
			// Start line: 4488
			// Start offset: 0x80065574
			// Variables:
		// 		struct BSPTree *bspTree; // $s0

			/* begin block 1.1.1 */
				// Start line: 4496
				// Start offset: 0x8006561C
				// Variables:
			// 		struct WaterLevelProcess *curWater; // $a0
			/* end block 1.1.1 */
			// End offset: 0x800656A8
			// End Line: 4512

			/* begin block 1.1.2 */
				// Start line: 4520
				// Start offset: 0x800656BC
				// Variables:
			// 		long offsetz; // $a0
			/* end block 1.1.2 */
			// End offset: 0x80065740
			// End Line: 4533
		/* end block 1.1 */
		// End offset: 0x80065828
		// End Line: 4603
	/* end block 1 */
	// End offset: 0x80065828
	// End Line: 4605

	/* begin block 2 */
		// Start line: 9599
	/* end block 2 */
	// End Line: 9600

/* File: C:\kain2\game\EVENT.C */

long EVENT_DoTGroupAction(TGroupObject *terrainGroup,StackType *operand2)

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
  if (terrainGroup->attribute == -1) {
    return 0;
  }
  pBVar8 = terrainGroup->bspTree;
  EVENT_ParseOperand2(operand2,&lStack24,(long *)&local_14);
  iVar4 = terrainGroup->attribute;
  if (iVar4 < 0x31) {
    if (0x2e < iVar4) {
      iVar4 = (int)(pBVar8->localOffset).z;
      iVar7 = (int)terrainGroup->arg[0] - iVar4;
      if (iVar4 == (int)terrainGroup->arg[0]) {
        return 1;
      }
      (pBVar8->globalOffset).z = (pBVar8->globalOffset).z + (short)iVar7;
      (pBVar8->localOffset).z = terrainGroup->arg[0];
      if (terrainGroup->attribute == 0x2f) {
        pLVar5 = terrainGroup->streamUnit->level;
        pLVar5->waterZLevel = pLVar5->waterZLevel + iVar7;
        p_Var6 = terrainGroup->streamUnit->level->terrain;
        p_Var6->UnitChangeFlags = p_Var6->UnitChangeFlags | 3;
        return 1;
      }
      return 1;
    }
    if (iVar4 == 0xb) {
      local_14 = local_14 ^ 1;
    }
    else {
      if (0xb < iVar4) {
        if ((iVar4 != 0x2c) && (iVar4 != 0x2e)) {
          return 0;
        }
        pWVar3 = EVENT_GetNextTerrainMove();
        if (pWVar3 == (WaterLevelProcess *)0x0) {
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
        if (terrainGroup->attribute == 0x2e) {
          pWVar3->flags = pWVar3->flags | 2;
          return 0;
        }
        return 0;
      }
      if (iVar4 != 10) {
        return 0;
      }
    }
    if (local_14 == 0) {
      uVar2 = pBVar8->flags & 0xfffc;
    }
    else {
      uVar2 = pBVar8->flags | 3;
    }
  }
  else {
    if (iVar4 == 0x35) {
      if (local_14 == 0) {
        uVar2 = pBVar8->flags & 0xfffd;
      }
      else {
        uVar2 = pBVar8->flags | 2;
      }
    }
    else {
      if (iVar4 < 0x36) {
        if (iVar4 != 0x34) {
          return 0;
        }
        if (local_14 == 0) {
          uVar2 = pBVar8->flags & 0xfffe;
        }
        else {
          uVar2 = pBVar8->flags | 1;
        }
      }
      else {
        if (iVar4 == 0x73) {
          if (local_14 == 0) {
            uVar2 = pBVar8->flags & 0xffbf;
          }
          else {
            uVar2 = pBVar8->flags | 0x40;
          }
        }
        else {
          if (iVar4 != 0x95) {
            return 0;
          }
          if (local_14 == 0) {
            uVar2 = pBVar8->flags & 0xffdf;
          }
          else {
            uVar2 = pBVar8->flags | 0x20;
          }
        }
      }
    }
  }
  pBVar8->flags = uVar2;
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoCameraAction(struct CameraObject *cameraObject /*$s2*/, struct StackType *operand2 /*$s0*/, short *codeStream /*$a2*/)
 // line 4608, offset 0x80065844
	/* begin block 1 */
		// Start line: 4609
		// Start offset: 0x80065844
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $a1
	// 		long error; // stack offset -24
	// 		struct Camera *camera; // $s1

		/* begin block 1.1 */
			// Start line: 4642
			// Start offset: 0x800658E0
			// Variables:
		// 		struct Intro *intro; // $a0
		/* end block 1.1 */
		// End offset: 0x80065948
		// End Line: 4672

		/* begin block 1.2 */
			// Start line: 4681
			// Start offset: 0x80065964
			// Variables:
		// 		long angle; // $a1
		/* end block 1.2 */
		// End offset: 0x80065A28
		// End Line: 4702

		/* begin block 1.3 */
			// Start line: 4714
			// Start offset: 0x80065A54
			// Variables:
		// 		long angle; // $v0
		/* end block 1.3 */
		// End offset: 0x80065AA4
		// End Line: 4724

		/* begin block 1.4 */
			// Start line: 4738
			// Start offset: 0x80065AC4
			// Variables:
		// 		long angle; // $v0
		/* end block 1.4 */
		// End offset: 0x80065B04
		// End Line: 4747

		/* begin block 1.5 */
			// Start line: 4775
			// Start offset: 0x80065B7C
		/* end block 1.5 */
		// End offset: 0x80065B7C
		// End Line: 4779
	/* end block 1 */
	// End offset: 0x80065BA8
	// End Line: 4809

	/* begin block 2 */
		// Start line: 9873
	/* end block 2 */
	// End Line: 9874

/* File: C:\kain2\game\EVENT.C */

long EVENT_DoCameraAction(CameraObject *cameraObject,StackType *operand2,short *codeStream)

{
  long dist;
  int iVar1;
  int frames;
  Camera *camera;
  int iVar2;
  long local_18;
  long local_14;
  
  local_14 = 1;
  local_18 = 1;
  camera = cameraObject->camera;
  if (cameraObject->attribute == -1) {
    return 0;
  }
  dist = EVENT_ParseOperand2(operand2,&local_18,&local_14);
  switch(cameraObject->attribute) {
  case 9:
  case 0x46:
    if (local_18 == 0) {
      if (cameraObject->attribute == 0x46) {
        iVar1 = -dist % 0x168;
        if (iVar1 < 0) {
          iVar1 = iVar1 + 0x168;
        }
        CAMERA_Adjust_tilt(cameraObject->camera,(iVar1 * 0x1000) / 0x168);
      }
      else {
        iVar1 = -dist % 0x168;
        if (iVar1 < 0) {
          iVar1 = iVar1 + 0x168;
        }
        CAMERA_Adjust_rotation(cameraObject->camera,(iVar1 * 0x1000) / 0x168);
      }
    }
    break;
  case 0x10:
    if (local_18 == 0) {
      CAMERA_SetMode(camera,dist);
    }
    break;
  case 0x43:
    if (local_18 == 0) {
      CAMERA_SetSmoothValue(camera,dist);
    }
    break;
  case 0x44:
  case 0x45:
    iVar1 = 0;
    if (operand2 != (StackType *)0x0) {
      if (operand2->id == 2) {
        iVar1 = *(int *)(*(int *)operand2->data + 0x20);
      }
      else {
        if (operand2->id == 4) {
          iVar1 = *(int *)operand2->data;
        }
      }
    }
    if (iVar1 != 0) {
      if (cameraObject->attribute == 0x44) {
        camera->Spline00 = *(MultiSpline **)(iVar1 + 0x38);
      }
      else {
        camera->Spline01 = *(MultiSpline **)(iVar1 + 0x38);
      }
    }
    break;
  case 0x47:
    if (local_18 == 0) {
      CAMERA_Adjust_distance(cameraObject->camera,dist);
    }
    break;
  case 0x48:
    CAMERA_RestoreMode(camera);
    break;
  case 0x49:
    if ((operand2 != (StackType *)0x0) && (operand2->id == 2)) {
      CAMERA_SetInstanceFocus(camera,*(_Instance **)operand2->data);
    }
    break;
  case 0x68:
    if (local_18 != 0) {
      return 0;
    }
    iVar1 = dist % 0x168;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0x168;
    }
    iVar1 = iVar1 << 0xc;
    iVar2 = (int)((ulonglong)((longlong)iVar1 * -0x49f49f49) >> 0x20);
    frames = 0;
    goto LAB_80065b10;
  case 0x69:
    if (local_18 != 0) {
      return 0;
    }
    iVar1 = dist % 0x168;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0x168;
    }
    iVar1 = iVar1 << 0xc;
    frames = cameraObject->frames;
    iVar2 = (int)((ulonglong)((longlong)iVar1 * -0x49f49f49) >> 0x20);
LAB_80065b10:
    CAMERA_Adjust_roll((iVar2 + iVar1 >> 8) - (iVar1 >> 0x1f),frames);
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoObjectSoundAction(struct SoundObject *soundObject /*$s0*/, struct StackType *operand2 /*$a0*/)
 // line 4812, offset 0x80065bc4
	/* begin block 1 */
		// Start line: 4813
		// Start offset: 0x80065BC4
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $v1
	// 		long error; // stack offset -24
	// 		long result; // $s2
	// 		struct _Instance *instance; // $a3

		/* begin block 1.1 */
			// Start line: 4828
			// Start offset: 0x80065BFC
			// Variables:
		// 		struct SoundInstance *soundInstance; // $s1
		/* end block 1.1 */
		// End offset: 0x80065CDC
		// End Line: 4866
	/* end block 1 */
	// End offset: 0x80065CDC
	// End Line: 4867

	/* begin block 2 */
		// Start line: 10289
	/* end block 2 */
	// End Line: 10290

/* File: C:\kain2\game\EVENT.C */

long EVENT_DoObjectSoundAction(SoundObject *soundObject,StackType *operand2)

{
  short sVar1;
  SoundInstance *soundInst;
  long lVar2;
  long lStack24;
  uint local_14;
  
  lVar2 = 1;
  local_14 = 1;
  if (soundObject->attribute != -1) {
    soundInst = (SoundInstance *)(soundObject->data + soundObject->soundNumber * 3 + 0x48);
    EVENT_ParseOperand2(operand2,&lStack24,(long *)&local_14);
    sVar1 = soundObject->attribute;
    if (sVar1 == 0x7f) {
      SOUND_SetInstanceSoundVolume(soundInst,soundObject->value,soundObject->duration);
      lVar2 = 1;
    }
    else {
      if (sVar1 < 0x80) {
        if (sVar1 != 0xd) {
          if (sVar1 != 0xe) {
            return 0;
          }
          local_14 = (uint)(local_14 == 0);
        }
        if (local_14 == 0) {
          SOUND_StopInstanceSound(soundInst);
          lVar2 = 1;
        }
        else {
          SOUND_StartInstanceSound(soundInst);
          lVar2 = 1;
        }
      }
      else {
        if (sVar1 == 0x80) {
          SOUND_SetInstanceSoundPitch(soundInst,soundObject->value,soundObject->duration);
          lVar2 = 1;
        }
        else {
          lVar2 = 1;
          if (0x83 < sVar1) {
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
 // line 4870, offset 0x80065cf8
	/* begin block 1 */
		// Start line: 4871
		// Start offset: 0x80065CF8
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $v1
	// 		long error; // stack offset -24
	// 		long result; // $s2
	// 		struct _SFXMkr *sfxMarker; // $a3

		/* begin block 1.1 */
			// Start line: 4886
			// Start offset: 0x80065D30
			// Variables:
		// 		struct SoundInstance *soundInstance; // $s1
		/* end block 1.1 */
		// End offset: 0x80065E10
		// End Line: 4924
	/* end block 1 */
	// End offset: 0x80065E10
	// End Line: 4925

	/* begin block 2 */
		// Start line: 10414
	/* end block 2 */
	// End Line: 10415

/* File: C:\kain2\game\EVENT.C */

long EVENT_DoSoundMarkerAction(SoundObject *soundObject,StackType *operand2)

{
  short sVar1;
  SoundInstance *soundInst;
  long lVar2;
  long lStack24;
  uint local_14;
  
  lVar2 = 1;
  local_14 = 1;
  if (soundObject->attribute != -1) {
    soundInst = (SoundInstance *)(soundObject->data + soundObject->soundNumber * 3 + 8);
    EVENT_ParseOperand2(operand2,&lStack24,(long *)&local_14);
    sVar1 = soundObject->attribute;
    if (sVar1 == 0x7f) {
      SOUND_SetInstanceSoundVolume(soundInst,soundObject->value,soundObject->duration);
      lVar2 = 1;
    }
    else {
      if (sVar1 < 0x80) {
        if (sVar1 != 0xd) {
          if (sVar1 != 0xe) {
            return 0;
          }
          local_14 = (uint)(local_14 == 0);
        }
        if (local_14 == 0) {
          SOUND_StopInstanceSound(soundInst);
          lVar2 = 1;
        }
        else {
          SOUND_StartInstanceSound(soundInst);
          lVar2 = 1;
        }
      }
      else {
        if (sVar1 == 0x80) {
          SOUND_SetInstanceSoundPitch(soundInst,soundObject->value,soundObject->duration);
          lVar2 = 1;
        }
        else {
          lVar2 = 1;
          if (0x83 < sVar1) {
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
 // line 4928, offset 0x80065e2c
	/* begin block 1 */
		// Start line: 4930
		// Start offset: 0x80065E2C
	/* end block 1 */
	// End offset: 0x80065E2C
	// End Line: 4962

	/* begin block 2 */
		// Start line: 10539
	/* end block 2 */
	// End Line: 10540

	/* begin block 3 */
		// Start line: 10540
	/* end block 3 */
	// End Line: 10541

	/* begin block 4 */
		// Start line: 10572
	/* end block 4 */
	// End Line: 10573

	/* begin block 5 */
		// Start line: 10573
	/* end block 5 */
	// End Line: 10574

/* File: C:\kain2\game\EVENT.C */

long EVENT_GetSoundValue(SoundObject *soundObject)

{
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoAreaAction(struct AreaObject *areaObject /*$s1*/, struct StackType *operand2 /*$a0*/)
 // line 4965, offset 0x80065e34
	/* begin block 1 */
		// Start line: 4966
		// Start offset: 0x80065E34
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $v1
	// 		long error; // stack offset -24
	// 		struct _StreamUnit *streamUnit; // $s0
	/* end block 1 */
	// End offset: 0x80065EC8
	// End Line: 5009

	/* begin block 2 */
		// Start line: 10613
	/* end block 2 */
	// End Line: 10614

/* File: C:\kain2\game\EVENT.C */

long EVENT_DoAreaAction(AreaObject *areaObject,StackType *operand2)

{
  long lVar1;
  ushort uVar2;
  _StreamUnit *p_Var3;
  long local_18;
  long local_14;
  
  local_14 = 1;
  p_Var3 = areaObject->streamUnit;
  if (areaObject->attribute != -1) {
    lVar1 = EVENT_ParseOperand2(operand2,&local_18,&local_14);
    uVar2 = (ushort)lVar1;
    if (areaObject->attribute == 0x70) {
      if (local_18 == 0) {
        p_Var3->TargetFogFar = uVar2;
        p_Var3->level->fogFar = uVar2;
      }
    }
    else {
      if ((areaObject->attribute == 0x71) && (local_18 == 0)) {
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
 // line 5012, offset 0x80065ee0
	/* begin block 1 */
		// Start line: 5013
		// Start offset: 0x80065EE0
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $v0
	// 		long error; // stack offset -24
	// 		long result; // $s2

		/* begin block 1.1 */
			// Start line: 5024
			// Start offset: 0x80065F14
			// Variables:
		// 		struct Intro *intro; // $s0

			/* begin block 1.1.1 */
				// Start line: 5068
				// Start offset: 0x8006600C
				// Variables:
			// 		int i; // $a2
			// 		int j; // $v1
			// 		int id; // $a1

				/* begin block 1.1.1.1 */
					// Start line: 5071
					// Start offset: 0x80066020

					/* begin block 1.1.1.1.1 */
						// Start line: 5074
						// Start offset: 0x80066030
						// Variables:
					// 		struct Intro *intro1; // $v0
					/* end block 1.1.1.1.1 */
					// End offset: 0x80066068
					// End Line: 5083
				/* end block 1.1.1.1 */
				// End offset: 0x80066068
				// End Line: 5084
			/* end block 1.1.1 */
			// End offset: 0x8006609C
			// End Line: 5087
		/* end block 1.1 */
		// End offset: 0x8006609C
		// End Line: 5094
	/* end block 1 */
	// End offset: 0x8006609C
	// End Line: 5096

	/* begin block 2 */
		// Start line: 10715
	/* end block 2 */
	// End Line: 10716

/* File: C:\kain2\game\EVENT.C */

long EVENT_DoIntroAction(IntroObject *introObject,StackType *operand2)

{
  uint uVar1;
  Intro *pIVar2;
  _Instance *p_Var3;
  long lVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  Intro *intro;
  long lVar10;
  long lStack24;
  uint local_14;
  
  local_14 = 1;
  lVar10 = 0;
  lVar4 = lVar10;
  if (introObject->attribute != -1) {
    intro = introObject->intro;
    EVENT_ParseOperand2(operand2,&lStack24,(long *)&local_14);
    iVar7 = introObject->attribute;
    if (iVar7 != 0x14) {
      if (iVar7 < 0x15) {
        if (iVar7 != 10) {
          if (iVar7 != 0xb) {
            return 0;
          }
          local_14 = local_14 ^ 1;
        }
        uVar5 = 0xfffffff7;
        if (local_14 == 0) {
          uVar1 = intro->flags;
          uVar5 = 0xffffff7f;
        }
        else {
          uVar1 = intro->flags | 0x80;
        }
        intro->flags = uVar1 & uVar5;
        lVar4 = 1;
      }
      else {
        if (iVar7 == 0x3e) {
          uVar9 = 0;
          iVar7 = 0;
          puVar8 = &StreamTracker;
          do {
            if (*(short *)(puVar8 + 1) == 2) {
              iVar6 = *(int *)(puVar8[2] + 0x78);
              pIVar2 = *(Intro **)(puVar8[2] + 0x7c);
              while (iVar6 != 0) {
                if (pIVar2 == intro) {
                  uVar9 = *puVar8;
                  break;
                }
                iVar6 = iVar6 + -1;
                pIVar2 = pIVar2 + 1;
              }
            }
            puVar8 = puVar8 + 0x10;
            iVar7 = iVar7 + 1;
          } while (iVar7 < 0x10);
          p_Var3 = INSTANCE_IntroduceInstance(intro,(short)uVar9);
          lVar4 = 0;
          if (p_Var3 == (_Instance *)0x0) {
            EventAbortLine = 1;
            lVar4 = lVar10;
          }
        }
        else {
          lVar4 = 0;
          if ((0x3e < iVar7) && (lVar4 = 0, iVar7 == 0x8a)) {
            if (local_14 == 0) {
              intro->flags = intro->flags & 0xfffffbff;
              lVar4 = lVar10;
            }
            else {
              intro->flags = intro->flags | 0x400;
              lVar4 = lVar10;
            }
          }
        }
      }
    }
  }
  return lVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_DoStackOperationEquals(struct _PCodeStack *stack /*$a2*/, short *codeStream /*$a3*/)
 // line 5113, offset 0x800660b8
	/* begin block 1 */
		// Start line: 5114
		// Start offset: 0x800660B8
		// Variables:
	// 		struct StackType operand1; // stack offset -88
	// 		struct StackType operand2; // stack offset -48
	/* end block 1 */
	// End offset: 0x8006617C
	// End Line: 5128

	/* begin block 2 */
		// Start line: 10219
	/* end block 2 */
	// End Line: 10220

/* File: C:\kain2\game\EVENT.C */

void EVENT_DoStackOperationEquals(_PCodeStack *stack,short *codeStream)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long local_58 [10];
  long local_30 [10];
  
  plVar3 = (long *)local_30;
  iVar1 = stack->topOfStack + -1;
  plVar2 = &stack->topOfStack + iVar1 * 9 + 1;
  stack->topOfStack = iVar1;
  do {
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
  do {
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
  EVENT_ExecuteActionCommand((StackType *)local_58,(StackType *)local_30,stack,codeStream);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_CompareVector3d(struct Vector3d *vector1 /*$a0*/, struct Vector3d *vector2 /*$a1*/)
 // line 5133, offset 0x800661a4
	/* begin block 1 */
		// Start line: 5135
		// Start offset: 0x800661A4
		// Variables:
	// 		long retValue; // $t2

		/* begin block 1.1 */
			// Start line: 5164
			// Start offset: 0x8006625C
			// Variables:
		// 		long dist; // $v0
		/* end block 1.1 */
		// End offset: 0x800662DC
		// End Line: 5174

		/* begin block 1.2 */
			// Start line: 5180
			// Start offset: 0x800662E4
			// Variables:
		// 		long dist; // $v0
		/* end block 1.2 */
		// End offset: 0x80066354
		// End Line: 5190
	/* end block 1 */
	// End offset: 0x80066354
	// End Line: 5194

	/* begin block 2 */
		// Start line: 10971
	/* end block 2 */
	// End Line: 10972

	/* begin block 3 */
		// Start line: 10972
	/* end block 3 */
	// End Line: 10973

	/* begin block 4 */
		// Start line: 10974
	/* end block 4 */
	// End Line: 10975

/* File: C:\kain2\game\EVENT.C */

long EVENT_CompareVector3d(Vector3d *vector1,Vector3d *vector2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (vector1->streamUnitID != vector2->streamUnitID) {
    return 0;
  }
  iVar4 = (int)vector1->errory;
  if (iVar4 != -1) {
    iVar3 = (int)vector1->errorz;
    if (iVar3 != -1) {
      if ((int)vector2->vx < (int)vector1->vx - (int)vector1->errorx) {
        return 0;
      }
      if ((int)vector1->vx + (int)vector1->errorx < (int)vector2->vx) {
        return 0;
      }
      if ((int)vector2->vy < vector1->vy - iVar4) {
        return 0;
      }
      if ((int)vector2->vy <= vector1->vy + iVar4) {
        if (vector1->vz - iVar3 <= (int)vector2->vz) {
          return (uint)(vector1->vz + iVar3 < (int)vector2->vz) ^ 1;
        }
        return 0;
      }
      return 0;
    }
    if (iVar4 != -1) {
      iVar3 = (int)vector2->vx - (int)vector1->vx;
      iVar2 = (int)vector2->vy - (int)vector1->vy;
      if ((int)vector1->errorx * (int)vector1->errorx <= iVar3 * iVar3 + iVar2 * iVar2) {
        return 0;
      }
      iVar3 = (int)vector2->vz - (int)vector1->vz;
      if (-1 < iVar3) {
        if (iVar3 < iVar4) {
          return 1;
        }
        return 0;
      }
      bVar1 = (int)vector1->vz - (int)vector2->vz < iVar4;
      goto LAB_80066348;
    }
  }
  iVar4 = (int)vector2->vx - (int)vector1->vx;
  iVar3 = (int)vector2->vy - (int)vector1->vy;
  iVar2 = (int)vector2->vz - (int)vector1->vz;
  bVar1 = iVar4 * iVar4 + iVar3 * iVar3 + iVar2 * iVar2 <
          (int)vector1->errorx * (int)vector1->errorx;
LAB_80066348:
  if (bVar1) {
    return 1;
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_CompareRotationVectors(struct Rotation3d *rot1 /*$a0*/, struct Rotation3d *rot2 /*$s1*/, long trueValue /*$s6*/)
 // line 5203, offset 0x80066360
	/* begin block 1 */
		// Start line: 5204
		// Start offset: 0x80066360
		// Variables:
	// 		struct MATRIX matrix1; // stack offset -104
	// 		struct MATRIX matrix2; // stack offset -72
	// 		long result; // $s2
	// 		long c1; // $v1
	// 		long attribute; // $s0
	// 		struct _SVector axis; // stack offset -40
	// 		long doSoft; // $s4
	/* end block 1 */
	// End offset: 0x8006652C
	// End Line: 5301

	/* begin block 2 */
		// Start line: 11117
	/* end block 2 */
	// End Line: 11118

/* File: C:\kain2\game\EVENT.C */

long EVENT_CompareRotationVectors(Rotation3d *rot1,Rotation3d *rot2,long trueValue)

{
  bool bVar1;
  int iVar2;
  undefined m1;
  int iVar3;
  uint uVar4;
  MATRIX MStack104;
  MATRIX MStack72;
  _SVector local_28;
  
  uVar4 = (uint)(trueValue == 0);
  iVar3 = rot1->attribute;
  bVar1 = false;
  if (iVar3 == -1) {
    iVar3 = rot2->attribute;
  }
  RotMatrixZYX((SVECTOR *)rot1,&MStack104);
  RotMatrixZYX((SVECTOR *)rot2,&MStack72);
  if (iVar3 == 8) {
LAB_800664c0:
    local_28.x = 0;
    local_28.y = 0;
    local_28.z = 0x1000;
    goto LAB_800664d4;
  }
  if (iVar3 < 9) {
    if (iVar3 == 6) {
LAB_80066490:
      local_28.x = 0x1000;
      local_28.y = 0;
      local_28.z = 0;
      goto LAB_800664d4;
    }
    if (iVar3 < 7) {
      if (iVar3 == -1) {
        local_28.x = 0x1000;
        local_28.y = 0;
        local_28.z = 0;
        m1 = SUB41(&MStack72,0);
        iVar2 = PHYSOBS_CheckObjectAxisAlignment(0x98,m1,&local_28);
        if (iVar2 - 0xf80U < 0x101) {
          local_28.x = 0;
          local_28.y = 0x1000;
          local_28.z = 0;
          iVar2 = PHYSOBS_CheckObjectAxisAlignment(0x98,m1,&local_28);
          if (iVar2 - 0xf80U < 0x101) {
            uVar4 = trueValue;
          }
        }
      }
      goto LAB_800664d4;
    }
  }
  else {
    if (iVar3 != 0x61) {
      if (0x61 < iVar3) {
        if (iVar3 != 0x62) goto LAB_800664d4;
        bVar1 = true;
        goto LAB_800664c0;
      }
      if (iVar3 != 0x60) goto LAB_800664d4;
      bVar1 = true;
      goto LAB_80066490;
    }
    bVar1 = true;
  }
  local_28.x = 0;
  local_28.y = 0x1000;
  local_28.z = 0;
LAB_800664d4:
  if (iVar3 != -1) {
    iVar3 = PHYSOBS_CheckObjectAxisAlignment(0x98,0xb8,&local_28);
    if (bVar1) {
      uVar4 = trueValue;
      if ((0x100 < iVar3 - 0xf80U) && (&DAT_00000100 < &DAT_00001080 + iVar3)) {
        uVar4 = (uint)(trueValue == 0);
      }
    }
    else {
      uVar4 = trueValue;
      if (0x100 < iVar3 - 0xf80U) {
        uVar4 = (uint)(trueValue == 0);
      }
    }
  }
  return uVar4;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_CompareListWithOperation(struct _PCodeStack *stack /*$s7*/, struct ListObject *listObject /*$s3*/, struct StackType *operand2 /*stack 8*/, long operation /*$fp*/)
 // line 5318, offset 0x80066558
	/* begin block 1 */
		// Start line: 5319
		// Start offset: 0x80066558
		// Variables:
	// 		long retValue; // $s4
	// 		long d; // $s0
	// 		struct StackType operand1; // stack offset -96
	// 		char objectName[16]; // stack offset -56
	// 		char *temp; // $v0
	// 		struct _Instance *instance; // $s2
	// 		long areaID; // $s5
	/* end block 1 */
	// End offset: 0x80066724
	// End Line: 5384

	/* begin block 2 */
		// Start line: 11351
	/* end block 2 */
	// End Line: 11352

	/* begin block 3 */
		// Start line: 11358
	/* end block 3 */
	// End Line: 11359

/* File: C:\kain2\game\EVENT.C */

long EVENT_CompareListWithOperation
               (_PCodeStack *stack,ListObject *listObject,StackType *operand2,long operation)

{
  char *pcVar1;
  long lVar2;
  long *plVar3;
  int iVar4;
  ListObject *pLVar5;
  _Instance *startInstance;
  long lVar6;
  long areaID;
  long local_60;
  _Instance *local_5c;
  undefined4 local_58;
  char acStack56 [16];
  
  lVar6 = 0;
  if (CurrentEventLine < 0x14) {
    eventListNumInstances[CurrentEventLine] = 0;
  }
  strcpy();
  pcVar1 = strchr(acStack56,'?');
  if (pcVar1 != (char *)0x0) {
    *pcVar1 = '\0';
  }
  areaID = listObject->eventInstance->unitID;
  startInstance = (_Instance *)0x0;
  if (areaID == 0x3f) {
    areaID = 0;
  }
  do {
    startInstance = INSTANCE_FindWithName(areaID,acStack56,startInstance);
    if (startInstance == (_Instance *)0x0) {
      return lVar6;
    }
    local_60 = 2;
    local_58 = 0xffffffff;
    iVar4 = 0;
    pLVar5 = listObject;
    local_5c = startInstance;
    if (0 < listObject->numberOfAttributes) {
      do {
        EVENT_TransformOperand((StackType *)&local_60,stack,pLVar5->attribute[0],(short *)0x0);
        iVar4 = iVar4 + 1;
        pLVar5 = (ListObject *)pLVar5->attribute;
      } while (iVar4 < listObject->numberOfAttributes);
    }
    lVar2 = EVENT_CompareOperandsWithOperation(stack,(StackType *)&local_60,operand2,operation);
    if (lVar2 == 0) {
      if (operation == 0xb) {
        if (9 < eventListNumInstances[CurrentEventLine]) {
          return 0;
        }
        eventListNumInstances[CurrentEventLine] = 0;
        return 0;
      }
    }
    else {
      if (CurrentEventLine < 0x14) {
        plVar3 = eventListNumInstances + CurrentEventLine;
        iVar4 = *plVar3;
        if (iVar4 < 10) {
          *(_Instance **)(&eventListArray + iVar4 * 4 + CurrentEventLine * 0x28) = startInstance;
          *plVar3 = iVar4 + 1;
        }
      }
      lVar6 = 1;
    }
  } while (startInstance != (_Instance *)0x0);
  return lVar6;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_CompareSubListWithOperation(struct _PCodeStack *stack /*$s6*/, struct SubListObject *subListObject /*$s3*/, struct StackType *operand2 /*$s7*/, long operation /*$fp*/)
 // line 5388, offset 0x80066758
	/* begin block 1 */
		// Start line: 5389
		// Start offset: 0x80066758
		// Variables:
	// 		long i; // $s4
	// 		long retValue; // $s5
	// 		long d; // $s0
	// 		struct StackType operand1; // stack offset -80
	/* end block 1 */
	// End offset: 0x800668CC
	// End Line: 5422

	/* begin block 2 */
		// Start line: 11502
	/* end block 2 */
	// End Line: 11503

	/* begin block 3 */
		// Start line: 11506
	/* end block 3 */
	// End Line: 11507

/* File: C:\kain2\game\EVENT.C */

long EVENT_CompareSubListWithOperation
               (_PCodeStack *stack,SubListObject *subListObject,StackType *operand2,long operation)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  SubListObject *pSVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  long local_50;
  undefined4 local_4c;
  undefined4 local_48;
  
  lVar7 = 0;
  if (CurrentEventLine < 0x14) {
    eventListNumInstances[CurrentEventLine] = 0;
  }
  iVar6 = 0;
  if (0 < subListObject->numberOfInstances) {
    iVar5 = 0;
    do {
      local_50 = 2;
      local_4c = *(undefined4 *)(iVar5 + (int)subListObject->instanceList);
      local_48 = 0xffffffff;
      iVar3 = 0;
      pSVar4 = subListObject;
      if (0 < subListObject->numberOfAttributes) {
        do {
          EVENT_TransformOperand((StackType *)&local_50,stack,pSVar4->attribute[0],(short *)0x0);
          iVar3 = iVar3 + 1;
          pSVar4 = (SubListObject *)&pSVar4->numberOfInstances;
        } while (iVar3 < subListObject->numberOfAttributes);
      }
      lVar1 = EVENT_CompareOperandsWithOperation(stack,(StackType *)&local_50,operand2,operation);
      if (lVar1 != 0) {
        if (CurrentEventLine < 0x14) {
          plVar2 = eventListNumInstances + CurrentEventLine;
          iVar3 = *plVar2;
          if (iVar3 < 10) {
            *(undefined4 *)(&eventListArray + iVar3 * 4 + CurrentEventLine * 0x28) =
                 *(undefined4 *)(iVar5 + (int)subListObject->instanceList);
            *plVar2 = iVar3 + 1;
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
 // line 5425, offset 0x80066900
	/* begin block 1 */
		// Start line: 5426
		// Start offset: 0x80066900
		// Variables:
	// 		long number; // $s1
	// 		long number1; // $s0
	// 		long number2; // $a0
	// 		long error; // stack offset -32
	// 		long trueValue; // $s2
	// 		short flags1; // stack offset -28
	// 		short flags2; // stack offset -26
	/* end block 1 */
	// End offset: 0x80066C14
	// End Line: 5631

	/* begin block 2 */
		// Start line: 11605
	/* end block 2 */
	// End Line: 11606

/* File: C:\kain2\game\EVENT.C */

long EVENT_CompareOperandsWithOperation
               (_PCodeStack *stack,StackType *operand1,StackType *operand2,long operation)

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
  switch(operand1->id) {
  case 8:
    break;
  case 9:
    if (operand2->id != 9) {
      return 0;
    }
    if (operation == 2) {
      iVar3 = (uint)*(ushort *)operand1->data - (uint)*(ushort *)operand2->data;
      iVar4 = (uint)*(ushort *)(operand1->data + 2) - (uint)*(ushort *)(operand2->data + 2);
      z = *(short *)(operand1->data + 4) - *(short *)(operand2->data + 4);
    }
    else {
      if (2 < operation) {
        uVar5 = trueValue;
        if (operation != 10) {
          if (operation != 0xb) {
            return 0;
          }
          uVar5 = 0;
        }
        trueValue = EVENT_CompareVector3d((Vector3d *)operand1->data,(Vector3d *)operand2->data);
        goto LAB_80066b94;
      }
      if (operation != 1) {
        return 0;
      }
      iVar3 = (uint)*(ushort *)operand1->data + (uint)*(ushort *)operand2->data;
      iVar4 = (uint)*(ushort *)(operand1->data + 2) + (uint)*(ushort *)(operand2->data + 2);
      z = *(short *)(operand1->data + 4) + *(short *)(operand2->data + 4);
    }
    EVENT_Addvector3dToStack
              (stack,(short)((uint)(iVar3 * 0x10000) >> 0x10),
               (short)((uint)(iVar4 * 0x10000) >> 0x10),z,0);
    uVar5 = 0xffffffff;
    break;
  default:
    uVar1 = EVENT_GetScalerValueFromOperand(operand1,&lStack32,(short *)&local_1c);
    uVar2 = EVENT_GetScalerValueFromOperand(operand2,&lStack32,(short *)&local_1a);
    switch(operation) {
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
      if (uVar2 != 0) {
        uVar5 = (int)uVar1 / (int)uVar2;
      }
      break;
    case 5:
      uVar5 = (int)uVar1 % uVar2;
      if ((int)uVar5 < 0) {
        uVar5 = uVar5 + uVar2;
      }
      break;
    case 6:
switchD_80066b1c_caseD_6:
      uVar5 = trueValue;
      trueValue = (uint)((int)uVar2 < (int)uVar1);
      goto LAB_80066b94;
    case 7:
switchD_80066b1c_caseD_7:
      uVar5 = trueValue;
      trueValue = (uint)((int)uVar1 < (int)uVar2);
      goto LAB_80066b94;
    case 8:
      trueValue = 0;
      goto switchD_80066b1c_caseD_7;
    case 9:
      trueValue = 0;
      goto switchD_80066b1c_caseD_6;
    case 10:
switchD_80066b1c_caseD_a:
      uVar5 = trueValue;
      if (((local_1c & 1) == 0) && ((local_1a & 1) == 0)) {
        if (uVar1 != uVar2) {
          uVar5 = uVar5 ^ 1;
        }
      }
      else {
        if ((local_1c & 2) != 0) {
          uVar2 = 1 << (uVar2 & 0x1f);
        }
        if ((uVar1 & uVar2) != uVar2) {
          uVar5 = uVar5 ^ 1;
        }
      }
      break;
    case 0xb:
      trueValue = 0;
      goto switchD_80066b1c_caseD_a;
    case 0xc:
      uVar5 = (uint)((uVar1 & uVar2) != 0);
    }
    break;
  case 0xe:
    uVar5 = 0;
    if (operand2->id == 0xe) {
      if (operation != 10) {
        if (operation != 0xb) {
          return 0;
        }
        trueValue = 0;
      }
      uVar5 = EVENT_CompareRotationVectors
                        ((Rotation3d *)operand1->data,(Rotation3d *)operand2->data,trueValue);
    }
    break;
  case 0x12:
    trueValue = EVENT_CompareListWithOperation
                          (stack,(ListObject *)operand1->data,operand2,operation);
    uVar5 = 1;
    goto LAB_80066b94;
  case 0x16:
    trueValue = EVENT_CompareSubListWithOperation
                          (stack,(SubListObject *)operand1->data,operand2,operation);
    uVar5 = 1;
LAB_80066b94:
    if (trueValue == 0) {
      uVar5 = uVar5 ^ 1;
    }
  }
  return uVar5;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_DoStackMathOperation(struct _PCodeStack *stack /*$s0*/, long operation /*$a3*/)
 // line 5637, offset 0x80066c38
	/* begin block 1 */
		// Start line: 5638
		// Start offset: 0x80066C38
		// Variables:
	// 		struct StackType operand1; // stack offset -128
	// 		struct StackType operand2; // stack offset -88

		/* begin block 1.1 */
			// Start line: 5656
			// Start offset: 0x80066D24
			// Variables:
		// 		struct StackType holdOperand; // stack offset -48
		/* end block 1.1 */
		// End offset: 0x80066DF0
		// End Line: 5661
	/* end block 1 */
	// End offset: 0x80066DF0
	// End Line: 5663

	/* begin block 2 */
		// Start line: 12044
	/* end block 2 */
	// End Line: 12045

/* File: C:\kain2\game\EVENT.C */

void EVENT_DoStackMathOperation(_PCodeStack *stack,long operation)

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
  long local_80 [8];
  undefined4 auStack96 [2];
  long local_58 [8];
  undefined4 auStack56 [2];
  undefined4 local_30 [8];
  undefined4 auStack16 [2];
  
  plVar5 = (long *)local_58;
  iVar2 = stack->topOfStack + -1;
  plVar4 = &stack->topOfStack + iVar2 * 9 + 1;
  stack->topOfStack = iVar2;
  do {
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
  do {
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
  if ((local_58[0] == 0x12) || (local_58[0] == 0x16)) {
    puVar3 = local_30;
    puVar1 = (undefined4 *)local_80;
    do {
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
    puVar1 = (undefined4 *)local_58;
    do {
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
    puVar3 = (undefined4 *)local_58;
    puVar1 = local_30;
    do {
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
  item = EVENT_CompareOperandsWithOperation
                   (stack,(StackType *)local_80,(StackType *)local_58,operation);
  EVENT_AddNumberToStack(stack,item,0);
  return;
}



// decompiled code
// original method signature: 
// short * /*$ra*/ EVENT_ParseOpcode(struct _PCodeStack *stack /*$s0*/, short *codeStream /*$s1*/, long *operateOnStack /*$a2*/)
 // line 5667, offset 0x80066e20
	/* begin block 1 */
		// Start line: 5668
		// Start offset: 0x80066E20
		// Variables:
	// 		short pcode; // $v0
	/* end block 1 */
	// End offset: 0x8006707C
	// End Line: 5784

	/* begin block 2 */
		// Start line: 12108
	/* end block 2 */
	// End Line: 12109

/* File: C:\kain2\game\EVENT.C */

short * EVENT_ParseOpcode(_PCodeStack *stack,short *codeStream,long *operateOnStack)

{
  ushort uVar1;
  long operation;
  short *codeStream_00;
  
  uVar1 = *codeStream;
  codeStream_00 = codeStream + 1;
  MoveCodeStreamExtra = 0;
  *operateOnStack = 0;
  switch((int)(((uint)uVar1 - 1) * 0x10000) >> 0x10) {
  case 0:
    EVENT_AddObjectToStack(stack,(int)*codeStream_00);
    codeStream_00 = codeStream + 2;
    break;
  case 1:
    EVENT_ModifyObjectToStackWithAttribute(stack,(int)*codeStream_00,codeStream_00);
    codeStream_00 = codeStream + 2;
    break;
  case 2:
    goto switchD_80066e74_caseD_2;
  case 3:
    EVENT_DoStackMathOperation(stack,10);
    break;
  case 4:
    EventAbortedPosition = codeStream_00;
    *operateOnStack = 1;
    break;
  case 6:
  case 8:
  case 9:
    codeStream_00 = (short *)0x0;
    break;
  case 0xb:
    EVENT_AddNumberToStack(stack,(int)*codeStream_00,0);
    codeStream_00 = codeStream + 2;
    break;
  case 0xc:
    EVENT_DoStackMathOperation(stack,1);
    break;
  case 0xd:
    EVENT_DoStackMathOperation(stack,2);
    break;
  case 0xe:
    EVENT_DoStackMathOperation(stack,3);
    break;
  case 0xf:
    EVENT_DoStackMathOperation(stack,4);
    break;
  case 0x10:
    EVENT_StackDuplicate(stack);
    EVENT_AddNumberToStack(stack,1,0);
    operation = 1;
    goto LAB_80066fb4;
  case 0x11:
    EVENT_StackDuplicate(stack);
    EVENT_AddNumberToStack(stack,1,0);
    operation = 2;
LAB_80066fb4:
    EVENT_DoStackMathOperation(stack,operation);
switchD_80066e74_caseD_2:
    EVENT_DoStackOperationEquals(stack,codeStream_00);
    break;
  case 0x12:
    EVENT_DoStackMathOperation(stack,6);
    break;
  case 0x13:
    EVENT_DoStackMathOperation(stack,8);
    break;
  case 0x14:
    EVENT_DoStackMathOperation(stack,7);
    break;
  case 0x15:
    EVENT_DoStackMathOperation(stack,9);
    break;
  case 0x16:
    EVENT_DoStackMathOperation(stack,0xb);
    break;
  case 0x17:
    EVENT_DoStackMathOperation(stack,5);
    break;
  case 0x1b:
    EVENT_AddGameObjectToStack(stack);
    break;
  case 0x1c:
    EVENT_AddPlayerObjectToStack(stack);
    break;
  case 0x1d:
    EVENT_AddSubListObjectToStack(stack,(int)*codeStream_00);
    codeStream_00 = codeStream + 2;
    break;
  case 0x1e:
    if (currentActionScript != (ScriptPCode *)0x0) {
      currentActionScript->conditionBits = currentActionScript->conditionBits | 2;
    }
    break;
  case 0x1f:
    EVENT_DoStackMathOperation(stack,0xc);
  }
  return codeStream_00 + MoveCodeStreamExtra;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_GetIntroValue(struct IntroObject *introObject /*$a0*/)
 // line 5788, offset 0x8006709c
	/* begin block 1 */
		// Start line: 5790
		// Start offset: 0x8006709C
		// Variables:
	// 		long value; // $a1
	// 		long trueValue; // $a2
	/* end block 1 */
	// End offset: 0x80067128
	// End Line: 5867

	/* begin block 2 */
		// Start line: 12356
	/* end block 2 */
	// End Line: 12357

	/* begin block 3 */
		// Start line: 12357
	/* end block 3 */
	// End Line: 12358

	/* begin block 4 */
		// Start line: 12362
	/* end block 4 */
	// End Line: 12363

/* File: C:\kain2\game\EVENT.C */

long EVENT_GetIntroValue(IntroObject *introObject)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  uVar1 = 1;
  switch(introObject->attribute) {
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
    goto LAB_80067114;
  case 0x14:
  case 0x15:
    uVar2 = 0xffffffff;
    break;
  case 0x92:
  case 0xa6:
    uVar2 = 1;
    uVar1 = introObject->intro->flags & 8;
LAB_80067114:
    if (uVar1 == 0) {
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
 // line 5870, offset 0x80067130
	/* begin block 1 */
		// Start line: 5871
		// Start offset: 0x80067130
		// Variables:
	// 		long i; // $s2
	// 		long d; // $s0
	// 		struct StackType operand1; // stack offset -72
	/* end block 1 */
	// End offset: 0x80067200
	// End Line: 5890

	/* begin block 2 */
		// Start line: 12528
	/* end block 2 */
	// End Line: 12529

/* File: C:\kain2\game\EVENT.C */

void EVENT_DoSubListAction
               (SubListObject *subListObject,StackType *operand2,_PCodeStack *stack,
               short *codeStream)

{
  int iVar1;
  SubListObject *pSVar2;
  int iVar3;
  long local_48;
  _Instance *local_44;
  undefined4 local_40;
  
  iVar3 = 0;
  if (0 < subListObject->numberOfInstances) {
    do {
      local_48 = 2;
      local_44 = subListObject->instanceList[iVar3];
      local_40 = 0xffffffff;
      iVar1 = 0;
      pSVar2 = subListObject;
      if (0 < subListObject->numberOfAttributes) {
        do {
          EVENT_TransformOperand((StackType *)&local_48,stack,pSVar2->attribute[0],(short *)0x0);
          iVar1 = iVar1 + 1;
          pSVar2 = (SubListObject *)&pSVar2->numberOfInstances;
        } while (iVar1 < subListObject->numberOfAttributes);
      }
      EVENT_ExecuteActionCommand((StackType *)&local_48,operand2,stack,codeStream);
      iVar3 = iVar3 + 1;
    } while (iVar3 < subListObject->numberOfInstances);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_GetInstanceValue(struct InstanceObject *instanceObject /*$a0*/)
 // line 5893, offset 0x80067228
	/* begin block 1 */
		// Start line: 5894
		// Start offset: 0x80067228
		// Variables:
	// 		long value; // $s0
	// 		struct _Instance *instance; // $a0
	/* end block 1 */
	// End offset: 0x80067388
	// End Line: 6028

	/* begin block 2 */
		// Start line: 12589
	/* end block 2 */
	// End Line: 12590

/* File: C:\kain2\game\EVENT.C */

long EVENT_GetInstanceValue(InstanceObject *instanceObject)

{
  uint uVar1;
  _Instance *Inst;
  int Query;
  ulong uVar2;
  
  Inst = instanceObject->instance;
  uVar2 = 0;
  switch(instanceObject->attribute) {
  case 5:
  case 9:
  case 0xc:
  case 0x20:
  case 0x36:
  case 0x37:
  case 0x5e:
  case 0x5f:
  case 0x7e:
    goto switchD_80067264_caseD_5;
  case 10:
  case 0x34:
    uVar2 = (ulong)((Inst->flags & 0x800U) != 0);
    break;
  case 0xb:
    uVar2 = (ulong)((Inst->flags & 0x800U) == 0);
    break;
  case 0x10:
    Query = 10;
    goto LAB_80067354;
  case 0x14:
    uVar2 = INSTANCE_Query(Inst,0xb);
    uVar1 = uVar2 >> 1;
    goto LAB_80067298;
  case 0x15:
    uVar1 = INSTANCE_Query(Inst,0xb);
LAB_80067298:
    uVar2 = uVar1 & 1;
    Query = STREAM_IsMorphInProgress();
    if (Query != 0) {
switchD_80067264_caseD_5:
      uVar2 = 0;
    }
    break;
  case 0x24:
    uVar2 = INSTANCE_Query(Inst,5);
    uVar2 = (ulong)((uVar2 & 5) == 1);
    break;
  case 0x25:
    uVar2 = INSTANCE_Query(Inst,5);
    uVar2 = (ulong)((uVar2 & 9) == 0);
    break;
  case 0x26:
    Query = 0x1b;
    goto LAB_80067354;
  case 0x27:
    Query = 0x1a;
LAB_80067354:
    uVar2 = INSTANCE_Query(Inst,Query);
    break;
  case 0x35:
    uVar2 = (ulong)((Inst->flags2 & 0x20000000U) != 0);
    break;
  case 0x5b:
    uVar2 = (ulong)Inst->lightGroup;
    break;
  case 0x5c:
    uVar2 = (ulong)Inst->spectralLightGroup;
    break;
  case 0x67:
    uVar2 = (ulong)((Inst->flags & 0x400000U) == 0);
    break;
  case 0x8f:
    uVar2 = INSTANCE_Query(Inst,5);
    uVar2 = uVar2 >> 2 & 1;
    break;
  case 0x90:
    uVar2 = INSTANCE_Query(Inst,5);
    uVar2 = uVar2 >> 3 & 1;
    break;
  case -1:
    uVar2 = Inst->introUniqueID;
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_GetSplineFrameNumber(struct InstanceSpline *instanceSpline /*$s0*/)
 // line 6031, offset 0x800673a0
	/* begin block 1 */
		// Start line: 6032
		// Start offset: 0x800673A0
	/* end block 1 */
	// End offset: 0x800673A0
	// End Line: 6032

	/* begin block 2 */
		// Start line: 12868
	/* end block 2 */
	// End Line: 12869

/* File: C:\kain2\game\EVENT.C */

long EVENT_GetSplineFrameNumber(InstanceSpline *instanceSpline)

{
  SplineDef *splineDef;
  int iVar1;
  
  splineDef = SCRIPT_GetPosSplineDef
                        (instanceSpline->instance,instanceSpline->spline,instanceSpline->isParent,
                         instanceSpline->isClass);
  iVar1 = SCRIPT_GetSplineFrameNumber(instanceSpline->instance,splineDef);
  return iVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_GetSplineValue(struct InstanceSpline *instanceSpline /*$a2*/)
 // line 6044, offset 0x800673e4
	/* begin block 1 */
		// Start line: 6045
		// Start offset: 0x800673E4
		// Variables:
	// 		long value; // $a1
	// 		struct _Instance *instance; // $a0

		/* begin block 1.1 */
			// Start line: 6094
			// Start offset: 0x80067490
			// Variables:
		// 		struct MultiSpline *spline; // $v0
		/* end block 1.1 */
		// End offset: 0x800674D0
		// End Line: 6113
	/* end block 1 */
	// End offset: 0x800674D0
	// End Line: 6120

	/* begin block 2 */
		// Start line: 12894
	/* end block 2 */
	// End Line: 12895

/* File: C:\kain2\game\EVENT.C */

long EVENT_GetSplineValue(InstanceSpline *instanceSpline)

{
  byte bVar1;
  short sVar2;
  Spline *pSVar3;
  _Instance *instance;
  uint uVar4;
  
  instance = instanceSpline->instance;
  uVar4 = 0;
  switch(instanceSpline->attribute) {
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
    if (pSVar3 == (Spline *)0x0) {
      return 0;
    }
    bVar1 = pSVar3->flags;
    uVar4 = (uint)bVar1 & 1;
    if ((bVar1 & 2) != 0) {
      uVar4 = 2;
    }
    if ((bVar1 & 4) == 0) {
      return uVar4;
    }
  case -1:
    uVar4 = 1;
    break;
  case 0x11:
    uVar4 = 1;
    if ((instance->flags & 0x1000000U) != 0) {
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
 // line 6124, offset 0x800674e0
	/* begin block 1 */
		// Start line: 6126
		// Start offset: 0x800674E0
		// Variables:
	// 		long value; // $a1
	// 		long trueValue; // $a2
	// 		struct _Instance *instance; // $a3

		/* begin block 1.1 */
			// Start line: 6154
			// Start offset: 0x8006754C
			// Variables:
		// 		struct AniTexInfo *ani_tex_info; // $a0
		/* end block 1.1 */
		// End offset: 0x8006754C
		// End Line: 6155
	/* end block 1 */
	// End offset: 0x80067584
	// End Line: 6173

	/* begin block 2 */
		// Start line: 13057
	/* end block 2 */
	// End Line: 13058

	/* begin block 3 */
		// Start line: 13058
	/* end block 3 */
	// End Line: 13059

/* File: C:\kain2\game\EVENT.C */

long EVENT_GetAnimateTextureValue(InstanceAnimateTexture *instanceAniTexture)

{
  uint uVar1;
  AniTex *pAVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar1 = 1;
  switch(instanceAniTexture->attribute) {
  case 0xd:
  case 0x29:
    uVar1 = 0;
  case 0xe:
    uVar3 = uVar1;
    if ((instanceAniTexture->instance->flags & 0x80U) == 0) {
      uVar3 = uVar3 ^ 1;
    }
    break;
  case 0xf:
  case 0x28:
    pAVar2 = instanceAniTexture->aniTextures;
    if (pAVar2 != (AniTex *)0x0) {
      return ((int)instanceAniTexture->instance->currentTextureAnimFrame /
             (pAVar2->aniTexInfo).speed) % (pAVar2->aniTexInfo).numFrames;
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
 // line 6177, offset 0x80067590
	/* begin block 1 */
		// Start line: 6178
		// Start offset: 0x80067590
		// Variables:
	// 		long value; // $a1
	// 		struct _Instance *instance; // $a0
	/* end block 1 */
	// End offset: 0x800675F8
	// End Line: 6217

	/* begin block 2 */
		// Start line: 13166
	/* end block 2 */
	// End Line: 13167

/* File: C:\kain2\game\EVENT.C */

long EVENT_GetAnimateValue(InstanceAnimate *instanceAnimate)

{
  ulong uVar1;
  int Query;
  
  uVar1 = 0;
  switch(instanceAnimate->attribute) {
  case 0xd:
  case 0x29:
    uVar1 = 0;
    break;
  case 0xf:
  case 0x28:
    Query = 0x12;
    goto LAB_800675ec;
  case 0x1e:
    Query = 0x11;
LAB_800675ec:
    uVar1 = INSTANCE_Query(instanceAnimate->instance,Query);
    break;
  case -1:
  case 0xe:
    uVar1 = 1;
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformObjectOnStack(struct _PCodeStack *stack /*$t0*/, long item /*$t1*/, short *codeStream /*$a3*/)
 // line 6222, offset 0x80067608
	/* begin block 1 */
		// Start line: 6223
		// Start offset: 0x80067608
		// Variables:
	// 		long retValue; // $v0
	/* end block 1 */
	// End offset: 0x8006764C
	// End Line: 6238

	/* begin block 2 */
		// Start line: 13260
	/* end block 2 */
	// End Line: 13261

/* File: C:\kain2\game\EVENT.C */

long EVENT_TransformObjectOnStack(_PCodeStack *stack,long item,short *codeStream)

{
  long lVar1;
  
  lVar1 = 0;
  if (stack->topOfStack != 0) {
    lVar1 = EVENT_TransformOperand
                      ((StackType *)stack[-1].stack[stack->topOfStack + 0x1f].data,stack,item,
                       codeStream);
  }
  return lVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_UpdatePuzzlePointers(struct EventPointers *events /*$a0*/, long offset /*$a1*/)
 // line 6242, offset 0x8006765c
	/* begin block 1 */
		// Start line: 6244
		// Start offset: 0x8006765C
		// Variables:
	// 		long d; // $t3
	// 		long d2; // $t1
	// 		struct Event *curEvent; // $a3
	/* end block 1 */
	// End offset: 0x80067830
	// End Line: 6283

	/* begin block 2 */
		// Start line: 13300
	/* end block 2 */
	// End Line: 13301

	/* begin block 3 */
		// Start line: 13301
	/* end block 3 */
	// End Line: 13302

	/* begin block 4 */
		// Start line: 13304
	/* end block 4 */
	// End Line: 13305

/* File: C:\kain2\game\EVENT.C */

void EVENT_UpdatePuzzlePointers(EventPointers *events,long offset)

{
  _func_15 *p_Var1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  EventPointers *pEVar7;
  int iVar8;
  
  if ((events != (EventPointers *)0x0) && (iVar8 = 0, pEVar7 = events, 0 < events->numPuzzles)) {
    do {
      p_Var1 = (_func_15 *)0x0;
      if (pEVar7->eventInstances[0] != (_func_15 *)0x0) {
        p_Var1 = pEVar7->eventInstances[0] + offset;
      }
      pEVar7->eventInstances[0] = p_Var1;
      iVar3 = 0;
      if (*(int *)(p_Var1 + 0x10) != 0) {
        iVar3 = *(int *)(p_Var1 + 0x10) + offset;
      }
      iVar5 = 0;
      *(int *)(p_Var1 + 0x10) = iVar3;
      if (*(int *)(p_Var1 + 0x14) != 0) {
        iVar5 = *(int *)(p_Var1 + 0x14) + offset;
      }
      iVar3 = 0;
      *(int *)(p_Var1 + 0x14) = iVar5;
      if (*(int *)(p_Var1 + 0x18) != 0) {
        iVar3 = *(int *)(p_Var1 + 0x18) + offset;
      }
      iVar5 = 0;
      *(int *)(p_Var1 + 0x18) = iVar3;
      if (0 < *(short *)(p_Var1 + 2)) {
        iVar3 = 0;
        do {
          iVar4 = *(int *)(iVar3 + *(int *)(p_Var1 + 0x10));
          iVar2 = 0;
          if (iVar4 != 0) {
            iVar2 = iVar4 + offset;
          }
          *(int *)(iVar3 + *(int *)(p_Var1 + 0x10)) = iVar2;
          psVar6 = *(short **)(iVar3 + *(int *)(p_Var1 + 0x10));
          if (*psVar6 == 2) {
            iVar2 = 0;
            if (*(int *)(psVar6 + 4) != 0) {
              iVar2 = *(int *)(psVar6 + 4) + offset;
            }
            *(int *)(psVar6 + 4) = iVar2;
          }
          iVar5 = iVar5 + 1;
          iVar3 = iVar3 + 4;
        } while (iVar5 < *(short *)(p_Var1 + 2));
      }
      iVar3 = 0;
      if (p_Var1[4] != (_func_15)0x0) {
        iVar5 = 0;
        do {
          iVar2 = *(int *)(iVar5 + *(int *)(p_Var1 + 0x14));
          if (iVar2 != 0) {
            *(int *)(iVar5 + *(int *)(p_Var1 + 0x14)) = iVar2 + offset;
            iVar4 = *(int *)(*(int *)(iVar5 + *(int *)(p_Var1 + 0x14)) + 4);
            iVar2 = 0;
            if (iVar4 != 0) {
              iVar2 = iVar4 + offset;
            }
            *(int *)(*(int *)(iVar5 + *(int *)(p_Var1 + 0x14)) + 4) = iVar2;
          }
          iVar2 = *(int *)(iVar5 + *(int *)(p_Var1 + 0x18));
          if (iVar2 != 0) {
            *(int *)(iVar5 + *(int *)(p_Var1 + 0x18)) = iVar2 + offset;
            iVar4 = *(int *)(*(int *)(iVar5 + *(int *)(p_Var1 + 0x18)) + 4);
            iVar2 = 0;
            if (iVar4 != 0) {
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
 // line 6287, offset 0x80067838
	/* begin block 1 */
		// Start line: 6288
		// Start offset: 0x80067838
		// Variables:
	// 		struct EventPointers *eventPointers; // $s4
	// 		struct Event *eventInstance; // $s0
	// 		long i; // $s3
	// 		long d; // $a1
	// 		long saveEvent; // $s1

		/* begin block 1.1 */
			// Start line: 6301
			// Start offset: 0x80067878
			// Variables:
		// 		long useBigSave; // $s2

			/* begin block 1.1.1 */
				// Start line: 6327
				// Start offset: 0x800678E4
				// Variables:
			// 		struct SavedEvent *savedEvent; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8006792C
			// End Line: 6337

			/* begin block 1.1.2 */
				// Start line: 6340
				// Start offset: 0x80067934
				// Variables:
			// 		struct SavedEventSmallVars *savedEvent; // $a2
			/* end block 1.1.2 */
			// End offset: 0x8006797C
			// End Line: 6350
		/* end block 1.1 */
		// End offset: 0x8006797C
		// End Line: 6352
	/* end block 1 */
	// End offset: 0x80067990
	// End Line: 6354

	/* begin block 2 */
		// Start line: 13425
	/* end block 2 */
	// End Line: 13426

/* File: C:\kain2\game\EVENT.C */

void EVENT_SaveEventsFromLevel(long levelID,Level *level)

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
  if ((pEVar9 != (EventPointers *)0x0) && (iVar8 = 0, 0 < pEVar9->numPuzzles)) {
    do {
      bVar1 = false;
      psVar5 = (short *)pEVar9->eventInstances[iVar8];
      iVar6 = 0;
      psVar3 = psVar5;
      bVar2 = bVar1;
      do {
        if ((psVar3[3] != 0) && (bVar1 = true, 0xfe < (ushort)(psVar3[3] + 0x7fU))) {
          bVar2 = true;
        }
        iVar6 = iVar6 + 1;
        psVar3 = psVar3 + 1;
      } while (iVar6 < 5);
      SAVE_DeleteSavedEvent(levelID,(int)*psVar5);
      if (bVar1) {
        if (bVar2) {
          puVar4 = (undefined *)SAVE_GetSavedBlock(2,0);
          iVar6 = 0;
          *puVar4 = 2;
          *(short *)(puVar4 + 2) = (short)levelID;
          *(short *)(puVar4 + 4) = *psVar5;
          do {
            psVar3 = psVar5 + 3;
            psVar5 = psVar5 + 1;
            iVar6 = iVar6 + 1;
            *(short *)(puVar4 + 6) = *psVar3;
            puVar4 = puVar4 + 2;
          } while (iVar6 < 5);
        }
        else {
          puVar4 = (undefined *)SAVE_GetSavedBlock(9,0);
          *puVar4 = 9;
          *(short *)(puVar4 + 2) = (short)levelID;
          puVar4[4] = *(undefined *)psVar5;
          iVar6 = 0;
          do {
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
 // line 6357, offset 0x800679b4
	/* begin block 1 */
		// Start line: 6358
		// Start offset: 0x800679B4
		// Variables:
	// 		long d; // $v1
	// 		struct EventPointers *eventPointers; // $s0
	// 		struct Event *eventInstance; // $t0
	// 		struct SavedBasic *savedEvent; // $a1

		/* begin block 1.1 */
			// Start line: 6372
			// Start offset: 0x800679FC
			// Variables:
		// 		long eventNumber; // $t1
		/* end block 1.1 */
		// End offset: 0x80067AC4
		// End Line: 6412
	/* end block 1 */
	// End offset: 0x80067AD8
	// End Line: 6420

	/* begin block 2 */
		// Start line: 13650
	/* end block 2 */
	// End Line: 13651

/* File: C:\kain2\game\EVENT.C */

void EVENT_LoadEventsForLevel(long levelID,Level *level)

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
  if (pEVar7 != (EventPointers *)0x0) {
    curSave = SAVE_GetSavedNextEvent(levelID,(SavedBasic *)0x0);
    while (curSave != (SavedBasic *)0x0) {
      if (pEVar7->numPuzzles != 0) {
        if (curSave->savedID == '\x02') {
          uVar6 = SEXT24((short)curSave[2]);
        }
        else {
          uVar6 = (uint)curSave[2].savedID;
        }
        iVar2 = 0;
        pEVar4 = pEVar7;
        psVar3 = (short *)0x0;
        if (0 < pEVar7->numPuzzles) {
          do {
            psVar3 = (short *)pEVar4->eventInstances[0];
            iVar2 = iVar2 + 1;
            if ((int)*psVar3 == uVar6) break;
            pEVar4 = (EventPointers *)pEVar4->eventInstances;
            psVar3 = (short *)0x0;
          } while (iVar2 < pEVar7->numPuzzles);
        }
        if (psVar3 != (short *)0x0) {
          iVar2 = 0;
          pSVar5 = curSave;
          if (curSave->savedID == '\x02') {
            do {
              iVar2 = iVar2 + 1;
              *(SavedBasic *)(psVar3 + 3) = pSVar5[3];
              psVar3 = psVar3 + 1;
              pSVar5 = pSVar5 + 1;
            } while (iVar2 < 5);
          }
          else {
            do {
              pbVar1 = &curSave[2].shiftedSaveSize + iVar2;
              iVar2 = iVar2 + 1;
              psVar3[3] = (ushort)*pbVar1;
              psVar3 = psVar3 + 1;
            } while (iVar2 < 5);
          }
        }
      }
      curSave = SAVE_GetSavedNextEvent(levelID,curSave);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// struct SavedBasic * /*$ra*/ EVENT_CreateSaveEvent(long levelID /*$s0*/, long eventNumber /*$s1*/)
 // line 6423, offset 0x80067af0
	/* begin block 1 */
		// Start line: 6424
		// Start offset: 0x80067AF0
		// Variables:
	// 		struct SavedEventSmallVars *savedEvent; // $a1
	// 		long d; // $a0
	/* end block 1 */
	// End offset: 0x80067B44
	// End Line: 6446

	/* begin block 2 */
		// Start line: 13806
	/* end block 2 */
	// End Line: 13807

/* File: C:\kain2\game\EVENT.C */

SavedBasic * EVENT_CreateSaveEvent(long levelID,long eventNumber)

{
  SavedBasic *pSVar1;
  SavedBasic *pSVar2;
  int iVar3;
  
  pSVar1 = (SavedBasic *)SAVE_GetSavedBlock(9,0);
  if (pSVar1 != (SavedBasic *)0x0) {
    iVar3 = 4;
    pSVar2 = pSVar1 + 2;
    pSVar1->savedID = '\t';
    pSVar1[1] = SUB42(levelID,0);
    pSVar1[2].savedID = (uchar)eventNumber;
    do {
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
 // line 6450, offset 0x80067b5c
	/* begin block 1 */
		// Start line: 6452
		// Start offset: 0x80067B5C
		// Variables:
	// 		int d; // $t3
	// 		int i; // $t0
	// 		int i2; // $a1
	// 		struct EventPointers *puzzle; // $t2
	// 		struct EventBasicObject **basicEventObject; // $v0
	/* end block 1 */
	// End offset: 0x80067C40
	// End Line: 6483

	/* begin block 2 */
		// Start line: 13871
	/* end block 2 */
	// End Line: 13872

	/* begin block 3 */
		// Start line: 13872
	/* end block 3 */
	// End Line: 13873

	/* begin block 4 */
		// Start line: 13877
	/* end block 4 */
	// End Line: 13878

/* File: C:\kain2\game\EVENT.C */

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
  do {
    if (((*(short *)((int)&DAT_800d2a10 + iVar2) == 2) &&
        (piVar6 = *(int **)(*(int *)((int)&DAT_800d2a14 + iVar2) + 0xdc), piVar6 != (int *)0x0)) &&
       (iVar2 = 0, piVar5 = piVar6, 0 < *piVar6)) {
      do {
        ppsVar1 = *(short ***)(piVar5[1] + 0x10);
        iVar4 = 0;
        if (0 < *(short *)(piVar5[1] + 2)) {
          do {
            psVar3 = *ppsVar1;
            if ((*psVar3 == 1) && (*(_Instance **)(psVar3 + 6) == instance)) {
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
    if (0xf < iVar7) {
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_UpdatePuzzleWithInstance(struct EventPointers *puzzle /*$a0*/, struct _Instance *instance /*$a1*/)
 // line 6486, offset 0x80067c48
	/* begin block 1 */
		// Start line: 6488
		// Start offset: 0x80067C48
		// Variables:
	// 		int i; // $t2
	// 		int i2; // $t0
	// 		struct EventBasicObject **basicEventObject; // $v0
	/* end block 1 */
	// End offset: 0x80067CE4
	// End Line: 6510

	/* begin block 2 */
		// Start line: 13962
	/* end block 2 */
	// End Line: 13963

	/* begin block 3 */
		// Start line: 13963
	/* end block 3 */
	// End Line: 13964

	/* begin block 4 */
		// Start line: 13967
	/* end block 4 */
	// End Line: 13968

/* File: C:\kain2\game\EVENT.C */

void EVENT_UpdatePuzzleWithInstance(EventPointers *puzzle,_Instance *instance)

{
  short **ppsVar1;
  short *psVar2;
  int iVar3;
  EventPointers *pEVar4;
  int iVar5;
  
  iVar5 = 0;
  pEVar4 = puzzle;
  if (0 < puzzle->numPuzzles) {
    do {
      ppsVar1 = *(short ***)(pEVar4->eventInstances[0] + 0x10);
      iVar3 = 0;
      if (0 < *(short *)(pEVar4->eventInstances[0] + 2)) {
        do {
          psVar2 = *ppsVar1;
          if ((*psVar2 == 1) && (instance->introUniqueID == *(int *)(psVar2 + 4))) {
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
 // line 6512, offset 0x80067cec
	/* begin block 1 */
		// Start line: 6513
		// Start offset: 0x80067CEC
		// Variables:
	// 		int d; // $s1
	// 		int curTree; // $a1
	// 		struct EventPointers *puzzle; // $a0
	// 		struct Level *level; // $s0

		/* begin block 1.1 */
			// Start line: 6532
			// Start offset: 0x80067D64
			// Variables:
		// 		struct BSPTree *bspTree; // $a0
		/* end block 1.1 */
		// End offset: 0x80067D98
		// End Line: 6542
	/* end block 1 */
	// End offset: 0x80067DC4
	// End Line: 6545

	/* begin block 2 */
		// Start line: 14028
	/* end block 2 */
	// End Line: 14029

/* File: C:\kain2\game\EVENT.C */

void EVENT_AddInstanceToInstanceList(_Instance *instance)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = 0;
  do {
    if ((&DAT_800d2a10)[iVar5 * 0x20] == 2) {
      piVar4 = (int *)(&DAT_800d2a14)[iVar5 * 0x10];
      if ((EventPointers *)piVar4[0x37] != (EventPointers *)0x0) {
        EVENT_UpdatePuzzleWithInstance((EventPointers *)piVar4[0x37],instance);
      }
      iVar1 = *piVar4;
      iVar2 = 0;
      if (0 < *(int *)(iVar1 + 0x44)) {
        iVar3 = 0;
        do {
          iVar1 = *(int *)(iVar1 + 0x48) + iVar3;
          if ((-1 < *(short *)(iVar1 + 0x1a)) && (*(int *)(iVar1 + 0x1c) == instance->introUniqueID)
             ) {
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
 // line 6547, offset 0x80067ddc
	/* begin block 1 */
		// Start line: 6548
		// Start offset: 0x80067DDC
		// Variables:
	// 		int i; // $s2
	// 		struct _VMObject *vmObject; // $s3
	// 		struct Level *level; // $s1
	/* end block 1 */
	// End offset: 0x80067E58
	// End Line: 6567

	/* begin block 2 */
		// Start line: 14127
	/* end block 2 */
	// End Line: 14128

/* File: C:\kain2\game\EVENT.C */

_VMObject * EVENT_FindVMObject(_StreamUnit *stream,char *vmoName)

{
  int iVar1;
  int iVar2;
  Level *pLVar3;
  int iVar4;
  
  pLVar3 = stream->level;
  iVar4 = 0;
  if (0 < pLVar3->numVMObjects) {
    iVar2 = 0;
    do {
      iVar1 = strcmpi(*(char **)((int)&pLVar3->vmobjectList->name + iVar2),vmoName);
      iVar4 = iVar4 + 1;
      if (iVar1 == 0) {
        return (_VMObject *)((int)&pLVar3->vmobjectList->flags + iVar2);
      }
      iVar2 = iVar2 + 0x3c;
    } while (iVar4 < pLVar3->numVMObjects);
  }
  return (_VMObject *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_FixPuzzlesForStream(struct _StreamUnit *stream /*$s7*/)
 // line 6570, offset 0x80067e7c
	/* begin block 1 */
		// Start line: 6571
		// Start offset: 0x80067E7C
		// Variables:
	// 		struct EventPointers *puzzle; // $s5
	// 		struct EventBasicObject **basicEventObject; // $s6
	// 		struct _Instance *instance; // $a1
	// 		struct _Instance *next; // $s0
	// 		int i; // $s4
	// 		int i2; // $s2
	// 		int p; // $a2

		/* begin block 1.1 */
			// Start line: 6598
			// Start offset: 0x80067F2C
			// Variables:
		// 		struct _StreamUnit *newStream; // $v0
		/* end block 1.1 */
		// End offset: 0x80067F40
		// End Line: 6606

		/* begin block 1.2 */
			// Start line: 6613
			// Start offset: 0x80067F50
			// Variables:
		// 		struct EventEventObject *eventEventObject; // $s1
		// 		struct _StreamUnit *newStream; // $v0

			/* begin block 1.2.1 */
				// Start line: 6620
				// Start offset: 0x80067F64
				// Variables:
			// 		struct EventPointers *puzzleInstances; // $v1
			/* end block 1.2.1 */
			// End offset: 0x80067FBC
			// End Line: 6637
		/* end block 1.2 */
		// End offset: 0x80067FBC
		// End Line: 6638

		/* begin block 1.3 */
			// Start line: 6643
			// Start offset: 0x80067FCC
			// Variables:
		// 		struct EventTGroupObject *tgroupEventObject; // $s1
		// 		struct _StreamUnit *newStream; // $v0

			/* begin block 1.3.1 */
				// Start line: 6648
				// Start offset: 0x80067FE0
				// Variables:
			// 		struct _Terrain *terrain; // $v0
			/* end block 1.3.1 */
			// End offset: 0x80068030
			// End Line: 6670
		/* end block 1.3 */
		// End offset: 0x80068030
		// End Line: 6671

		/* begin block 1.4 */
			// Start line: 6676
			// Start offset: 0x80068040
			// Variables:
		// 		struct _StreamUnit *newStream; // $v0
		/* end block 1.4 */
		// End offset: 0x80068054
		// End Line: 6684

		/* begin block 1.5 */
			// Start line: 6693
			// Start offset: 0x80068070
			// Variables:
		// 		void *pointer; // $v1

			/* begin block 1.5.1 */
				// Start line: 6703
				// Start offset: 0x8006808C
				// Variables:
			// 		struct _StreamUnit *stream2; // $v0
			/* end block 1.5.1 */
			// End offset: 0x800680B4
			// End Line: 6711
		/* end block 1.5 */
		// End offset: 0x800680B4
		// End Line: 6711

		/* begin block 1.6 */
			// Start line: 6721
			// Start offset: 0x800680E4
			// Variables:
		// 		struct _StreamUnit *newStream; // $v0
		/* end block 1.6 */
		// End offset: 0x80068104
		// End Line: 6732
	/* end block 1 */
	// End offset: 0x80068134
	// End Line: 6741

	/* begin block 2 */
		// Start line: 14178
	/* end block 2 */
	// End Line: 14179

/* File: C:\kain2\game\EVENT.C */

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
  instance = *(_Instance **)(DAT_800d2100 + 4);
  if (puzzle != (EventPointers *)0x0) {
    while (instance != (_Instance *)0x0) {
      p_Var12 = instance->next;
      EVENT_UpdatePuzzleWithInstance(puzzle,instance);
      instance = p_Var12;
    }
    iVar15 = 0;
    pEVar14 = puzzle;
    if (0 < puzzle->numPuzzles) {
      do {
        iVar16 = *(int *)(pEVar14->eventInstances[0] + 0x10);
        iVar13 = 0;
        if (0 < *(short *)(pEVar14->eventInstances[0] + 2)) {
          iVar3 = 0;
          do {
            instanceObject = *(EventInstanceObject **)(iVar3 + iVar16);
            sVar1 = instanceObject->id;
            if (sVar1 == 5) {
              stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID);
              if (stream_00 != (_StreamUnit *)0x0) {
                *(_StreamUnit **)&instanceObject->introUniqueID = stream_00;
              }
            }
            else {
              if (sVar1 == 3) {
                stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID);
                if ((stream_00 != (_StreamUnit *)0x0) &&
                   (pEVar9 = stream_00->level->PuzzleInstances, pEVar9 != (EventPointers *)0x0)) {
                  plVar2 = &pEVar9->numPuzzles;
                  iVar3 = 0;
                  if (0 < *plVar2) {
                    do {
                      iVar3 = iVar3 + 1;
                      if (*(short *)pEVar9->eventInstances[0] == instanceObject->flags) {
                        *(_func_15 **)&instanceObject->introUniqueID = pEVar9->eventInstances[0];
                        break;
                      }
                      pEVar9 = (EventPointers *)pEVar9->eventInstances;
                    } while (iVar3 < *plVar2);
                  }
                }
              }
              else {
                if (sVar1 == 4) {
                  stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID);
                  if (stream_00 != (_StreamUnit *)0x0) {
                    p_Var4 = stream_00->level->terrain;
                    iVar3 = p_Var4->numBSPTrees;
                    iVar10 = 0;
                    if (0 < iVar3) {
                      pBVar11 = p_Var4->BSPTreeArray;
                      do {
                        iVar10 = iVar10 + 1;
                        if (pBVar11->ID == instanceObject->flags) {
                          *(BSPTree **)&instanceObject->introUniqueID = pBVar11;
                          *(_StreamUnit **)&instanceObject->instance = stream;
                          break;
                        }
                        pBVar11 = pBVar11 + 1;
                      } while (iVar10 < iVar3);
                    }
                  }
                }
                else {
                  if (sVar1 == 6) {
                    stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID);
                    if (stream_00 != (_StreamUnit *)0x0) {
                      p_Var5 = EVENT_ResolveObjectSignal(stream_00,(int)instanceObject->flags);
                      *(_MultiSignal **)&instanceObject->introUniqueID = p_Var5;
                    }
                  }
                  else {
                    if (sVar1 == 1) {
                      pIVar6 = EVENT_ResolveObjectIntro(instanceObject);
                      if (pIVar6 == (Intro *)0x0) {
                        stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID);
                        if ((stream_00 != (_StreamUnit *)0x0) &&
                           (p_Var7 = EVENT_ResolveSFXMarker(stream_00,instanceObject),
                           p_Var7 != (_SFXMkr *)0x0)) {
                          *(_SFXMkr **)&instanceObject->data = p_Var7;
                          instanceObject->flags = instanceObject->flags | 1;
                        }
                      }
                      else {
                        *(Intro **)&instanceObject->data = pIVar6;
                      }
                    }
                    else {
                      if ((sVar1 == 7) &&
                         (stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID),
                         stream_00 != (_StreamUnit *)0x0)) {
                        p_Var8 = EVENT_FindVMObject(stream_00,(char *)&instanceObject->introUniqueID
                                                   );
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
 // line 6743, offset 0x80068160
	/* begin block 1 */
		// Start line: 6744
		// Start offset: 0x80068160
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
			// Start line: 6781
			// Start offset: 0x8006824C
			// Variables:
		// 		struct EventPointers *puzzleInstances; // $v1
		/* end block 1.1 */
		// End offset: 0x800682A4
		// End Line: 6799

		/* begin block 1.2 */
			// Start line: 6806
			// Start offset: 0x800682C8
			// Variables:
		// 		struct _Terrain *terrain; // $v0
		/* end block 1.2 */
		// End offset: 0x80068318
		// End Line: 6830

		/* begin block 1.3 */
			// Start line: 6836
			// Start offset: 0x80068328
		/* end block 1.3 */
		// End offset: 0x8006833C
		// End Line: 6841

		/* begin block 1.4 */
			// Start line: 6850
			// Start offset: 0x80068358
			// Variables:
		// 		void *pointer; // $v1
		/* end block 1.4 */
		// End offset: 0x80068388
		// End Line: 6864

		/* begin block 1.5 */
			// Start line: 6873
			// Start offset: 0x800683B8
		/* end block 1.5 */
		// End offset: 0x800683D8
		// End Line: 6882
	/* end block 1 */
	// End offset: 0x80068418
	// End Line: 6894

	/* begin block 2 */
		// Start line: 14773
	/* end block 2 */
	// End Line: 14774

/* File: C:\kain2\game\EVENT.C */

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
  do {
    if (((*(short *)((int)&DAT_800d2a10 + iVar9) == 2) &&
        (piVar15 = *(int **)(*(int *)((int)&DAT_800d2a14 + iVar9) + 0xdc), piVar15 != (int *)0x0))
       && (iVar9 = 0, piVar14 = piVar15, 0 < *piVar15)) {
      do {
        iVar17 = *(int *)(piVar14[1] + 0x10);
        iVar13 = 0;
        if (0 < *(short *)(piVar14[1] + 2)) {
          iVar3 = 0;
          do {
            instanceObject = *(EventInstanceObject **)(iVar3 + iVar17);
            sVar1 = instanceObject->id;
            if (sVar1 == 5) {
              if (instanceObject->unitID == stream->StreamUnitID) {
                *(_StreamUnit **)&instanceObject->introUniqueID = stream;
              }
            }
            else {
              if (sVar1 == 3) {
                if ((instanceObject->unitID == stream->StreamUnitID) &&
                   (pEVar10 = stream->level->PuzzleInstances, pEVar10 != (EventPointers *)0x0)) {
                  piVar2 = &pEVar10->numPuzzles;
                  iVar3 = 0;
                  if (0 < *piVar2) {
                    do {
                      iVar3 = iVar3 + 1;
                      if (*(short *)pEVar10->eventInstances[0] == instanceObject->flags) {
                        *(_func_15 **)&instanceObject->introUniqueID = pEVar10->eventInstances[0];
                        break;
                      }
                      pEVar10 = (EventPointers *)pEVar10->eventInstances;
                    } while (iVar3 < *piVar2);
                  }
                }
              }
              else {
                if (sVar1 == 4) {
                  if (instanceObject->unitID == stream->StreamUnitID) {
                    p_Var4 = stream->level->terrain;
                    iVar3 = p_Var4->numBSPTrees;
                    iVar11 = 0;
                    if (0 < iVar3) {
                      pBVar12 = p_Var4->BSPTreeArray;
                      do {
                        iVar11 = iVar11 + 1;
                        if (pBVar12->ID == instanceObject->flags) {
                          *(BSPTree **)&instanceObject->introUniqueID = pBVar12;
                          *(_StreamUnit **)&instanceObject->instance = stream;
                          break;
                        }
                        pBVar12 = pBVar12 + 1;
                      } while (iVar11 < iVar3);
                    }
                  }
                }
                else {
                  if (sVar1 == 6) {
                    if (instanceObject->unitID == stream->StreamUnitID) {
                      p_Var5 = EVENT_ResolveObjectSignal(stream,(int)instanceObject->flags);
                      *(_MultiSignal **)&instanceObject->introUniqueID = p_Var5;
                    }
                  }
                  else {
                    if (sVar1 == 1) {
                      pIVar6 = EVENT_ResolveObjectIntro(instanceObject);
                      if (pIVar6 == (Intro *)0x0) {
                        p_Var7 = EVENT_ResolveSFXMarker(stream,instanceObject);
                        if (p_Var7 != (_SFXMkr *)0x0) {
                          *(_SFXMkr **)&instanceObject->data = p_Var7;
                          instanceObject->flags = instanceObject->flags | 1;
                        }
                      }
                      else {
                        *(Intro **)&instanceObject->data = pIVar6;
                      }
                    }
                    else {
                      if ((sVar1 == 7) && (stream->StreamUnitID == instanceObject->unitID)) {
                        p_Var8 = EVENT_FindVMObject(stream,(char *)&instanceObject->introUniqueID);
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
    if (0xf < iVar16) {
      EVENT_FixPuzzlesForStream(stream);
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_RemoveStreamToInstanceList(struct _StreamUnit *stream /*$s2*/)
 // line 6898, offset 0x8006844c
	/* begin block 1 */
		// Start line: 6899
		// Start offset: 0x8006844C
		// Variables:
	// 		int d; // $t1
	// 		int i; // $s1
	// 		int i2; // $a1
	// 		struct EventPointers *puzzle; // $t0
	// 		struct EventBasicObject **basicEventObject; // $v0

		/* begin block 1.1 */
			// Start line: 6954
			// Start offset: 0x80068538
		/* end block 1.1 */
		// End offset: 0x8006854C
		// End Line: 6959

		/* begin block 1.2 */
			// Start line: 6966
			// Start offset: 0x8006855C
		/* end block 1.2 */
		// End offset: 0x80068574
		// End Line: 6975
	/* end block 1 */
	// End offset: 0x80068600
	// End Line: 6996

	/* begin block 2 */
		// Start line: 15305
	/* end block 2 */
	// End Line: 15306

/* File: C:\kain2\game\EVENT.C */

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
  EventTimer *timer;
  
  iVar8 = 0;
  iVar3 = 0;
  do {
    if ((((*(short *)((int)&DAT_800d2a10 + iVar3) == 2) &&
         ((_StreamUnit *)((int)&StreamTracker + iVar3) != stream)) &&
        (piVar7 = *(int **)(*(int *)((int)&DAT_800d2a14 + iVar3) + 0xdc), piVar7 != (int *)0x0)) &&
       (iVar3 = 0, piVar6 = piVar7, 0 < *piVar7)) {
      do {
        ppsVar2 = *(short ***)(piVar6[1] + 0x10);
        iVar5 = 0;
        if (0 < *(short *)(piVar6[1] + 2)) {
          do {
            psVar4 = *ppsVar2;
            sVar1 = *psVar4;
            if ((sVar1 == 5) || (sVar1 == 3)) {
LAB_80068538:
              if (*(int *)(psVar4 + 2) == stream->StreamUnitID) {
                *(undefined4 *)(psVar4 + 4) = 0;
              }
            }
            else {
              if (sVar1 == 4) {
                if (*(int *)(psVar4 + 2) == stream->StreamUnitID) {
                  *(undefined4 *)(psVar4 + 4) = 0;
                  *(undefined4 *)(psVar4 + 6) = 0;
                }
              }
              else {
                if (sVar1 == 6) goto LAB_80068538;
                if ((sVar1 == 1) && (*(int *)(psVar4 + 2) == stream->StreamUnitID)) {
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
    if (0xf < iVar8) {
      iVar3 = 0;
      timer = (EventTimer *)&eventTimerArray;
      do {
        if (((timer->flags & 1U) != 0) && ((Level *)timer->scriptPos == stream->level)) {
          EVENT_RemoveTimer(timer);
        }
        iVar3 = iVar3 + 1;
        timer = (EventTimer *)&timer->nextEventIndex;
      } while (iVar3 < 0x18);
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_RelocateInstanceList(struct Level *oldLevel /*$a0*/, struct Level *newLevel /*$a1*/, long sizeOfLevel /*$a2*/)
 // line 7000, offset 0x80068618
	/* begin block 1 */
		// Start line: 7002
		// Start offset: 0x80068618
		// Variables:
	// 		int d; // $t6
	// 		int i; // $t4
	// 		int i2; // $a3
	// 		struct EventPointers *puzzle; // $t5
	// 		struct EventBasicObject **basicEventObject; // $v0
	// 		long offset; // $t0

		/* begin block 1.1 */
			// Start line: 7022
			// Start offset: 0x800686A8
		/* end block 1.1 */
		// End offset: 0x800686A8
		// End Line: 7027

		/* begin block 1.2 */
			// Start line: 7034
			// Start offset: 0x800686B0
		/* end block 1.2 */
		// End offset: 0x800686B0
		// End Line: 7039

		/* begin block 1.3 */
			// Start line: 7046
			// Start offset: 0x800686B8
		/* end block 1.3 */
		// End offset: 0x800686E0
		// End Line: 7051

		/* begin block 1.4 */
			// Start line: 7058
			// Start offset: 0x800686F0
		/* end block 1.4 */
		// End offset: 0x80068718
		// End Line: 7064

		/* begin block 1.5 */
			// Start line: 7071
			// Start offset: 0x80068728
		/* end block 1.5 */
		// End offset: 0x80068754
		// End Line: 7079
	/* end block 1 */
	// End offset: 0x8006881C
	// End Line: 7101

	/* begin block 2 */
		// Start line: 15591
	/* end block 2 */
	// End Line: 15592

	/* begin block 3 */
		// Start line: 15592
	/* end block 3 */
	// End Line: 15593

	/* begin block 4 */
		// Start line: 15597
	/* end block 4 */
	// End Line: 15598

/* File: C:\kain2\game\EVENT.C */

void EVENT_RelocateInstanceList(Level *oldLevel,Level *newLevel,long sizeOfLevel)

{
  short sVar1;
  short **ppsVar2;
  int iVar3;
  int iVar4;
  Level *pLVar5;
  uint *puVar6;
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
  do {
    if (((*(short *)((int)&DAT_800d2a10 + iVar4) == 2) &&
        (piVar14 = *(int **)(*(int *)((int)&DAT_800d2a14 + iVar4) + 0xdc), piVar14 != (int *)0x0))
       && (iVar4 = 0, piVar13 = piVar14, 0 < *piVar14)) {
      do {
        ppsVar2 = *(short ***)(piVar13[1] + 0x10);
        iVar9 = 0;
        if (0 < *(short *)(piVar13[1] + 2)) {
          do {
            psVar7 = *ppsVar2;
            sVar1 = *psVar7;
            if (((sVar1 == 3) || (sVar1 == 4)) || (sVar1 == 6)) {
              pLVar5 = *(Level **)(psVar7 + 4);
              if ((oldLevel <= pLVar5) && (pLVar5 <= pLVar12)) {
                iVar3 = 0;
                if (pLVar5 != (Level *)0x0) {
                  iVar3 = (int)pLVar5 + (int)pLVar11;
                }
                *(int *)(psVar7 + 4) = iVar3;
              }
            }
            else {
              if (sVar1 == 1) {
                pLVar5 = *(Level **)(psVar7 + 8);
                if ((oldLevel <= pLVar5) && (pLVar5 <= pLVar12)) {
                  iVar3 = 0;
                  if (pLVar5 != (Level *)0x0) {
                    iVar3 = (int)pLVar5 + (int)pLVar11;
                  }
                  *(int *)(psVar7 + 8) = iVar3;
                }
              }
              else {
                if (sVar1 == 7) {
                  pLVar5 = *(Level **)(psVar7 + 10);
                  if ((oldLevel <= pLVar5) && (pLVar5 <= pLVar12)) {
                    iVar3 = 0;
                    if (pLVar5 != (Level *)0x0) {
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
  puVar6 = &eventTimerArray;
  do {
    if (((*puVar6 & 1) != 0) && ((Level *)puVar6[4] == oldLevel)) {
      uVar8 = 0;
      if (puVar6[1] != 0) {
        uVar8 = (int)&pLVar11->terrain + puVar6[1];
      }
      uVar10 = 0;
      puVar6[1] = uVar8;
      if (puVar6[2] != 0) {
        uVar10 = (int)&pLVar11->terrain + puVar6[2];
      }
      uVar8 = 0;
      puVar6[2] = uVar10;
      if (puVar6[3] != 0) {
        uVar8 = (int)&pLVar11->terrain + puVar6[3];
      }
      puVar6[3] = uVar8;
      *(Level **)(puVar6 + 4) = newLevel;
    }
    puVar6 = puVar6 + 6;
  } while ((int)puVar6 < -0x7ff2cf00);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_PrintVars()
 // line 7103, offset 0x80068824
	/* begin block 1 */
		// Start line: 15877
	/* end block 1 */
	// End Line: 15878

	/* begin block 2 */
		// Start line: 15906
	/* end block 2 */
	// End Line: 15907

/* File: C:\kain2\game\EVENT.C */

void EVENT_PrintVars(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_ExecuteActionCommand(struct StackType *operand1 /*$s0*/, struct StackType *operand2 /*$a1*/, struct _PCodeStack *stack /*$a2*/, short *codeStream /*$a3*/)
 // line 7137, offset 0x8006882c
	/* begin block 1 */
		// Start line: 7138
		// Start offset: 0x8006882C
		// Variables:
	// 		long error; // stack offset -16
	// 		long value; // $a0
	// 		short flags; // stack offset -12
	/* end block 1 */
	// End offset: 0x800689E4
	// End Line: 7247

	/* begin block 2 */
		// Start line: 15945
	/* end block 2 */
	// End Line: 15946

/* File: C:\kain2\game\EVENT.C */

void EVENT_ExecuteActionCommand
               (StackType *operand1,StackType *operand2,_PCodeStack *stack,short *codeStream)

{
  long lVar1;
  long local_10;
  short asStack12 [2];
  
  switch(operand1->id) {
  case 1:
    EVENT_DoAreaAction((AreaObject *)operand1->data,operand2);
    break;
  case 2:
    EVENT_DoInstanceAction((InstanceObject *)operand1->data,operand2,codeStream);
    break;
  case 3:
    EVENT_DoGameAction((GameObject *)operand1->data,operand2);
    break;
  case 4:
    EVENT_DoIntroAction((IntroObject *)operand1->data,operand2);
    break;
  case 10:
    lVar1 = EVENT_GetScalerValueFromOperand(operand2,&local_10,asStack12);
    if (local_10 == 0) {
      **(undefined2 **)operand1->data = (short)lVar1;
    }
    break;
  case 0xb:
    lVar1 = EVENT_GetScalerValueFromOperand(operand2,&local_10,asStack12);
    if (local_10 == 0) {
      **(long **)operand1->data = lVar1;
    }
    break;
  case 0xf:
    EVENT_DoSplineAction((InstanceSpline *)operand1->data,operand2);
    break;
  case 0x11:
    EVENT_DoSignalAction((SignalObject *)operand1->data,operand2);
    break;
  case 0x13:
    EVENT_DoAnimateAction((InstanceAnimate *)operand1->data,operand2);
    break;
  case 0x14:
    EVENT_DoInstanceAnimateTextureAction((InstanceAnimateTexture *)operand1->data,operand2);
    break;
  case 0x16:
    EVENT_DoSubListAction((SubListObject *)operand1->data,operand2,stack,codeStream);
    break;
  case 0x17:
    EVENT_DoTGroupAction((TGroupObject *)operand1->data,operand2);
    break;
  case 0x19:
    EVENT_DoCameraAction((CameraObject *)operand1->data,operand2,codeStream);
    break;
  case 0x1a:
    EVENT_DoVMObjectAction((EventVmObject *)operand1->data,operand2);
    break;
  case 0x1b:
    if (*(short *)operand1->data == 1) {
      EVENT_DoSoundMarkerAction((SoundObject *)operand1->data,operand2);
    }
    else {
      EVENT_DoObjectSoundAction((SoundObject *)operand1->data,operand2);
    }
    break;
  case 0x1c:
    lVar1 = EVENT_GetScalerValueFromOperand(operand2,&local_10,asStack12);
    if (local_10 == 0) {
      **(undefined **)operand1->data = (char)lVar1;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_GetScalerValueFromOperand(struct StackType *operand /*$a0*/, long *error /*$a1*/, short *flags /*$a2*/)
 // line 7250, offset 0x800689f4
	/* begin block 1 */
		// Start line: 7251
		// Start offset: 0x800689F4
		// Variables:
	// 		long value; // $a1
	/* end block 1 */
	// End offset: 0x80068B54
	// End Line: 7347

	/* begin block 2 */
		// Start line: 16171
	/* end block 2 */
	// End Line: 16172

/* File: C:\kain2\game\EVENT.C */

long EVENT_GetScalerValueFromOperand(StackType *operand,long *error,short *flags)

{
  long lVar1;
  uint uVar2;
  
  *error = 0;
  *flags = 0;
  uVar2 = 0x7fff;
  switch(operand->id) {
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
    uVar2 = (uint)((int)*(short *)(*(int *)operand->data + 0x16c) + 1U < 3) ^ 1;
    break;
  case 0x1a:
    uVar2 = EVENT_GetVMObjectValue((EventVmObject *)operand->data);
    break;
  case 0x1b:
    if (*(short *)operand->data != 1) {
      lVar1 = EVENT_GetSoundValue((SoundObject *)operand->data);
      return lVar1;
    }
  case 0x15:
    uVar2 = 0;
    break;
  case 0x1c:
    uVar2 = (uint)**(byte **)operand->data;
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformOperand(struct StackType *stackObject /*$t0*/, struct _PCodeStack *stack /*$a0*/, long item /*$a2*/, short *codeStream /*$a3*/)
 // line 7353, offset 0x80068b64
	/* begin block 1 */
		// Start line: 7354
		// Start offset: 0x80068B64
		// Variables:
	// 		long retValue; // $v0
	/* end block 1 */
	// End offset: 0x80068CFC
	// End Line: 7447

	/* begin block 2 */
		// Start line: 16384
	/* end block 2 */
	// End Line: 16385

/* File: C:\kain2\game\EVENT.C */

long EVENT_TransformOperand(StackType *stackObject,_PCodeStack *stack,long item,short *codeStream)

{
  long lVar1;
  
  switch(stackObject->id) {
  case 1:
    lVar1 = EVENT_TransformAreaAttribute(stack,stackObject,item,codeStream);
    break;
  case 2:
    lVar1 = EVENT_TransformInstanceAttribute(stack,stackObject,item,codeStream);
    break;
  case 3:
    lVar1 = EVENT_TransformGameAttribute(stack,stackObject,item,codeStream);
    break;
  case 4:
    lVar1 = EVENT_TransformIntroAttribute(stack,stackObject,item);
    break;
  default:
    lVar1 = 0;
    break;
  case 6:
    EventAbortLine = 1;
    lVar1 = 1;
    break;
  case 9:
    lVar1 = EVENT_TransformVector3dAttribute(stack,stackObject,item,codeStream);
    break;
  case 0xe:
    lVar1 = EVENT_TransformRotation3dAttribute(stack,stackObject,item,codeStream);
    break;
  case 0xf:
    lVar1 = EVENT_TransformSplineAttribute(stack,stackObject,item,codeStream);
    break;
  case 0x10:
    lVar1 = EVENT_TransformEventAttribute(stack,stackObject,item,codeStream);
    break;
  case 0x11:
    lVar1 = EVENT_TransformSignalAttribute(stack,stackObject,item);
    break;
  case 0x12:
    lVar1 = EVENT_TransformListObjectAttribute(stack,stackObject,item);
    break;
  case 0x13:
    lVar1 = 0;
    if (*(int *)(stackObject->data + 4) == -1) {
      *(long *)(stackObject->data + 4) = item;
      lVar1 = 1;
    }
    break;
  case 0x14:
    if (*(int *)(stackObject->data + 8) != -1) {
      return 0;
    }
  case 0x1a:
    *(long *)(stackObject->data + 8) = item;
    lVar1 = 1;
    break;
  case 0x15:
    lVar1 = EVENT_TransformSavedEventAttribute(stack,stackObject,item,codeStream);
    break;
  case 0x16:
    lVar1 = EVENT_TransformSubListObjectAttribute(stack,stackObject,item);
    break;
  case 0x17:
    lVar1 = EVENT_TransformTGroupAttribute(stack,stackObject,item,codeStream);
    break;
  case 0x18:
    lVar1 = EVENT_TransformConstrictAttribute(stack,stackObject,item);
    break;
  case 0x19:
    lVar1 = EVENT_TransformCameraObjectAttribute(stack,stackObject,item,codeStream);
    break;
  case 0x1b:
    lVar1 = EVENT_TransformSoundObjectAttribute
                      (stack,(SoundObject *)stackObject->data,item,codeStream);
  }
  return lVar1;
}





