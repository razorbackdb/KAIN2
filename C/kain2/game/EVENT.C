#include "THISDUST.H"
#include "EVENT.H"


// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_UpdateResetSignalArrayAndWaterMovement(struct Level *oldLevel /*$a0*/, struct Level *newLevel /*$a1*/, long sizeOfLevel /*$a2*/)
 // line 151, offset 0x80060b8c
	/* begin block 1 */
		// Start line: 152
		// Start offset: 0x80060B8C
		// Variables:
	// 		long offset; // $a1
	// 		long i; // $t0

		/* begin block 1.1 */
			// Start line: 173
			// Start offset: 0x80060C04
			// Variables:
		// 		struct WaterLevelProcess *curWater; // $t1
		/* end block 1.1 */
		// End offset: 0x80060C60
		// End Line: 186
	/* end block 1 */
	// End offset: 0x80060C60
	// End Line: 188

	/* begin block 2 */
		// Start line: 302
	/* end block 2 */
	// End Line: 303

	/* begin block 3 */
		// Start line: 307
	/* end block 3 */
	// End Line: 308

void EVENT_UpdateResetSignalArrayAndWaterMovement(Level *oldLevel,Level *newLevel,long sizeOfLevel)

{
  _MultiSignal *p_Var1;
  Level *pLVar2;
  _MultiSignal *p_Var3;
  Level *pLVar4;
  SignalResetStruct *pSVar5;
  Level **ppLVar6;
  int iVar7;
  WaterLevelProcess *pWVar8;
  
  if (NumSignalsToReset != 0) {
    iVar7 = 0;
    pSVar5 = &ResetSignalArray;
    do {
      if (0 < pSVar5->timeLeft) {
        p_Var3 = pSVar5->mSignal;
        if ((oldLevel <= p_Var3) &&
           (p_Var3 <= (_MultiSignal *)((int)&oldLevel->terrain + sizeOfLevel))) {
          p_Var1 = (_MultiSignal *)0x0;
          if (p_Var3 != (_MultiSignal *)0x0) {
            p_Var1 = (_MultiSignal *)((int)p_Var3 + (int)(Level *)((int)newLevel - (int)oldLevel));
          }
          pSVar5->mSignal = p_Var1;
        }
      }
      iVar7 = iVar7 + 1;
      pSVar5 = pSVar5 + 1;
    } while (iVar7 < 0x10);
  }
  iVar7 = 5;
  if (WaterInUse != 0) {
    pWVar8 = &WaterLevelArray;
    ppLVar6 = (Level **)&WaterLevelArray.bspTree;
    do {
      if ((pWVar8->flags & 1U) != 0) {
        pLVar4 = *ppLVar6;
        if ((oldLevel <= pLVar4) && (pLVar4 <= (Level *)((int)&oldLevel->terrain + sizeOfLevel))) {
          pLVar2 = (Level *)0x0;
          if (pLVar4 != (Level *)0x0) {
            pLVar2 = (Level *)((int)pLVar4 + (int)(Level *)((int)newLevel - (int)oldLevel));
          }
          *ppLVar6 = pLVar2;
        }
      }
      iVar7 = iVar7 + -1;
      ppLVar6 = ppLVar6 + 7;
      pWVar8 = pWVar8 + 1;
    } while (0 < iVar7);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_ResetAllOneTimeVariables()
 // line 191, offset 0x80060c68
	/* begin block 1 */
		// Start line: 193
		// Start offset: 0x80060C68
		// Variables:
	// 		int i; // $a2
	/* end block 1 */
	// End offset: 0x80060CC8
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
  SignalResetStruct *pSVar2;
  int iVar3;
  
  iVar3 = 0;
  if (NumSignalsToReset != 0) {
    pSVar2 = &ResetSignalArray;
    do {
      iVar1 = pSVar2->timeLeft + -1;
      if ((0 < pSVar2->timeLeft) && (pSVar2->timeLeft = iVar1, iVar1 == 0)) {
        NumSignalsToReset = NumSignalsToReset + -1;
        pSVar2->mSignal->flags = pSVar2->mSignal->flags & 0xfffe;
        pSVar2->timeLeft = 0;
      }
      iVar3 = iVar3 + 1;
      pSVar2 = pSVar2 + 1;
    } while (iVar3 < 0x10);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_AddSignalToReset(struct _MultiSignal *mSignal /*$a0*/)
 // line 215, offset 0x80060cd0
	/* begin block 1 */
		// Start line: 217
		// Start offset: 0x80060CD0
		// Variables:
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x80060D24
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
  SignalResetStruct *pSVar1;
  int iVar2;
  
  iVar2 = 0;
  if (NumSignalsToReset < 0x10) {
    pSVar1 = &ResetSignalArray;
    while (iVar2 = iVar2 + 1, pSVar1->timeLeft != 0) {
      pSVar1 = pSVar1 + 1;
      if (0xf < iVar2) {
        return;
      }
    }
    *(undefined **)&pSVar1->timeLeft = &UNK_00000001;
    pSVar1->mSignal = mSignal;
    NumSignalsToReset = NumSignalsToReset + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HINT_ResetHint()
 // line 266, offset 0x80060d2c
	/* begin block 1 */
		// Start line: 565
	/* end block 1 */
	// End Line: 566

/* WARNING: Unknown calling convention yet parameter storage is locked */

void HINT_ResetHint(void)

{
  memset(&gHintSystem,0,0x10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HINT_StartHint(short hintNumber /*$a0*/)
 // line 271, offset 0x80060d54
	/* begin block 1 */
		// Start line: 273
		// Start offset: 0x80060D54
		// Variables:
	// 		int h; // $a1
	/* end block 1 */
	// End offset: 0x80060D7C
	// End Line: 285

	/* begin block 2 */
		// Start line: 576
	/* end block 2 */
	// End Line: 577

	/* begin block 3 */
		// Start line: 577
	/* end block 3 */
	// End Line: 578

	/* begin block 4 */
		// Start line: 584
	/* end block 4 */
	// End Line: 585

void HINT_StartHint(short hintNumber)

{
  gHintSystem.stringNumber = hintNumber + 0x37;
  if (0x35 < (ushort)hintNumber) {
    gHintSystem.stringNumber = 0x6c;
  }
  gHintSystem.flags = 3;
  gHintSystem.hintNumber = hintNumber;
  gHintSystem.fadeTimer = 0xf000;
  gHintSystem.spawningUnitID = (gameTrackerX.playerInstance)->currentStreamUnitID;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HINT_StopHint()
 // line 294, offset 0x80060da0
	/* begin block 1 */
		// Start line: 637
	/* end block 1 */
	// End Line: 638

	/* begin block 2 */
		// Start line: 642
	/* end block 2 */
	// End Line: 643

/* WARNING: Unknown calling convention yet parameter storage is locked */

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
      gHintSystem.fadeTimer = 0xf000;
      return;
    }
    gHintSystem._0_4_ = uVar1 & 0xfffffffd | 4;
    gHintSystem.fadeTimer = 0xf000 - gHintSystem.fadeTimer;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HINT_KillSpecificHint(short hintNumber /*$a0*/)
 // line 319, offset 0x80060e04
	/* begin block 1 */
		// Start line: 688
	/* end block 1 */
	// End Line: 689

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
 // line 327, offset 0x80060e34
	/* begin block 1 */
		// Start line: 704
	/* end block 1 */
	// End Line: 705

	/* begin block 2 */
		// Start line: 705
	/* end block 2 */
	// End Line: 706

/* WARNING: Unknown calling convention yet parameter storage is locked */

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
 // line 339, offset 0x80060e54
	/* begin block 1 */
		// Start line: 340
		// Start offset: 0x80060E54
		// Variables:
	// 		int i; // $s2
	// 		struct EventTimer *eventTimer; // $s0
	/* end block 1 */
	// End offset: 0x80060F58
	// End Line: 393

	/* begin block 2 */
		// Start line: 728
	/* end block 2 */
	// End Line: 729

	/* begin block 3 */
		// Start line: 738
	/* end block 3 */
	// End Line: 739

/* WARNING: Unknown calling convention yet parameter storage is locked */

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
      timer = (EventTimer *)((int)&eventTimerArray.flags + iVar4);
      uVar2 = timer->flags;
      if ((uVar2 & 1) != 0) {
        if ((uint)((int)uVar2 >> 1) < gameTrackerX.timeMult) {
          timer->flags = uVar2 & 1;
        }
        else {
          timer->flags = uVar2 & 1 | (((int)uVar2 >> 1) - gameTrackerX.timeMult) * 2;
        }
        if (timer->flags >> 1 < 1) {
          iVar3 = *(int *)((int)&eventTimerArray.event + iVar4);
          currentEventInstance = *(Event **)((int)&eventTimerArray.time + iVar4);
          timer->flags = timer->flags & 1;
          *(ushort *)(iVar3 + 2) = *(ushort *)(iVar3 + 2) & 0xfffe;
          EVENT_RemoveTimer(timer);
          CurrentPuzzleLevel = *(Level **)((int)&eventTimerArray.scriptPos + iVar4);
          EventCurrentEventIndex = *(long *)((int)&eventTimerArray.level + iVar4);
          EventAbortLine = 0;
          lVar1 = EVENT_DoAction(*(Event **)((int)&eventTimerArray.time + iVar4),
                                 *(ScriptPCode **)((int)&eventTimerArray.event + iVar4),
                                 *(short **)((int)&eventTimerArray.actionScript + iVar4));
          if ((lVar1 != 0) && (EventCurrentEventIndex != -1)) {
            EVENT_Process(*(Event **)((int)&eventTimerArray.time + iVar4),EventCurrentEventIndex);
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
 // line 394, offset 0x80060f70
	/* begin block 1 */
		// Start line: 395
		// Start offset: 0x80060F70

		/* begin block 1.1 */
			// Start line: 400
			// Start offset: 0x80060F88
			// Variables:
		// 		char string[128]; // stack offset -136
		// 		long y; // $s0
		/* end block 1.1 */
		// End offset: 0x80061120
		// End Line: 467
	/* end block 1 */
	// End offset: 0x80061120
	// End Line: 468

	/* begin block 2 */
		// Start line: 891
	/* end block 2 */
	// End Line: 892

	/* begin block 3 */
		// Start line: 894
	/* end block 3 */
	// End Line: 895

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_ProcessHints(void)

{
  bool bVar1;
  int len;
  long y;
  char acStack136 [128];
  
  if ((gHintSystem.flags & 1U) != 0) {
    localstr_get((int)gHintSystem.stringNumber);
    sprintf(acStack136,(char *)&PTR_DAT_800d1a08);
    if ((gHintSystem.flags & 2U) == 0) {
      y = 200;
      if ((gHintSystem.flags & 4U) != 0) {
        y = 0xfc - (gHintSystem.fadeTimer * 0x34) / 0xf000;
      }
    }
    else {
      y = (gHintSystem.fadeTimer * 0x34) / 0xf000 + 200;
    }
    FONT_FontPrintCentered(acStack136,y);
    FONT_FontPrintCentered("$\n",y);
    len = FONT_GetStringWidth(acStack136);
    DisplayHintBox(len,y);
    if ((gHintSystem.fadeTimer != 0) &&
       (bVar1 = (uint)gHintSystem.fadeTimer <= gameTrackerX.timeMult,
       gHintSystem.fadeTimer = gHintSystem.fadeTimer - gameTrackerX.timeMult, bVar1)) {
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
    if (gHintSystem.spawningUnitID != (gameTrackerX.playerInstance)->currentStreamUnitID) {
      HINT_StopHint();
    }
    if ((gameTrackerX.gameFlags & 0x10U) != 0) {
      HINT_StopHint();
    }
  }
  return;
}



// decompiled code
// original method signature: 
// struct EventTimer * /*$ra*/ EVENT_GetNextTimer()
 // line 470, offset 0x80061130
	/* begin block 1 */
		// Start line: 471
		// Start offset: 0x80061130
		// Variables:
	// 		int i; // $a0

		/* begin block 1.1 */
			// Start line: 476
			// Start offset: 0x80061144
			// Variables:
		// 		struct EventTimer *eventTimer; // $v1
		/* end block 1.1 */
		// End offset: 0x80061190
		// End Line: 488
	/* end block 1 */
	// End offset: 0x80061194
	// End Line: 490

	/* begin block 2 */
		// Start line: 1048
	/* end block 2 */
	// End Line: 1049

	/* begin block 3 */
		// Start line: 1051
	/* end block 3 */
	// End Line: 1052

/* WARNING: Unknown calling convention yet parameter storage is locked */

EventTimer * EVENT_GetNextTimer(void)

{
  EventTimer *pEVar1;
  int iVar2;
  
  if (numActiveEventTimers < 0x18) {
    pEVar1 = &eventTimerArray;
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
 // line 492, offset 0x8006119c
	/* begin block 1 */
		// Start line: 1101
	/* end block 1 */
	// End Line: 1102

	/* begin block 2 */
		// Start line: 1102
	/* end block 2 */
	// End Line: 1103

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
 // line 502, offset 0x800611cc
	/* begin block 1 */
		// Start line: 1121
	/* end block 1 */
	// End Line: 1122

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_InitTimers(void)

{
  numActiveEventTimers = 0;
  memset(&eventTimerArray,0,0x240);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_InitTerrainMovement()
 // line 508, offset 0x800611f8
	/* begin block 1 */
		// Start line: 509
		// Start offset: 0x800611F8
		// Variables:
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x80061230
	// End Line: 516

	/* begin block 2 */
		// Start line: 1135
	/* end block 2 */
	// End Line: 1136

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_InitTerrainMovement(void)

{
  WaterLevelProcess *__s;
  int iVar1;
  
  iVar1 = 0;
  __s = &WaterLevelArray;
  do {
    memset(__s,0x1c,0);
    iVar1 = iVar1 + 1;
    __s = __s + 1;
  } while (iVar1 < 5);
  WaterInUse = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_Init()
 // line 519, offset 0x80061248
	/* begin block 1 */
		// Start line: 1166
	/* end block 1 */
	// End Line: 1167

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_Init(void)

{
  EVENT_InitTerrainMovement();
  EVENT_InitTimers();
  HINT_ResetHint();
  WaitingToLoadSound = 0x96000;
  EventTimer_800d440c.level._0_2_ = 0;
  EventTimer_800d440c.nextEventIndex._0_2_ = 0xffff;
  WaitingToLoadSFX = 0x96000;
  WaitingForVoiceNumber = -1;
                    /* WARNING: Read-only address (ram,0x800d4420) is written */
                    /* WARNING: Read-only address (ram,0x800d4424) is written */
  return;
}



// decompiled code
// original method signature: 
// struct WaterLevelProcess * /*$ra*/ EVENT_GetNextTerrainMove()
 // line 531, offset 0x80061294
	/* begin block 1 */
		// Start line: 533
		// Start offset: 0x80061294
		// Variables:
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x800612C4
	// End Line: 547

	/* begin block 2 */
		// Start line: 1194
	/* end block 2 */
	// End Line: 1195

	/* begin block 3 */
		// Start line: 1195
	/* end block 3 */
	// End Line: 1196

	/* begin block 4 */
		// Start line: 1198
	/* end block 4 */
	// End Line: 1199

/* WARNING: Unknown calling convention yet parameter storage is locked */

WaterLevelProcess * EVENT_GetNextTerrainMove(void)

{
  WaterLevelProcess *pWVar1;
  int iVar2;
  
  iVar2 = 0;
  pWVar1 = &WaterLevelArray;
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
 // line 566, offset 0x800612cc
	/* begin block 1 */
		// Start line: 568
		// Start offset: 0x800612CC
		// Variables:
	// 		long i; // $a3
	// 		long inUse; // $t0

		/* begin block 1.1 */
			// Start line: 573
			// Start offset: 0x800612DC
			// Variables:
		// 		struct WaterLevelProcess *curWater; // $a2
		/* end block 1.1 */
		// End offset: 0x800613E8
		// End Line: 602
	/* end block 1 */
	// End offset: 0x800613F4
	// End Line: 608

	/* begin block 2 */
		// Start line: 1132
	/* end block 2 */
	// End Line: 1133

	/* begin block 3 */
		// Start line: 1251
	/* end block 3 */
	// End Line: 1252

	/* begin block 4 */
		// Start line: 1254
	/* end block 4 */
	// End Line: 1255

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_ProcessMovingWater(void)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  long *plVar4;
  WaterLevelProcess *pWVar5;
  int iVar6;
  
  bVar2 = false;
  if (WaterInUse != 0) {
    pWVar5 = &WaterLevelArray;
    iVar6 = 5;
    plVar4 = &WaterLevelArray.maxSteps;
    do {
      if ((pWVar5->flags & 1U) != 0) {
        iVar3 = plVar4[1] + gameTrackerX.timeMult;
        plVar4[1] = iVar3;
        bVar2 = true;
        if (*plVar4 < iVar3) {
          plVar4[1] = *plVar4;
        }
        iVar3 = (((int)*(short *)((int)plVar4 + -2) - (int)*(short *)(plVar4 + -1)) *
                (plVar4[1] >> 0xc)) / (*plVar4 >> 0xc);
        sVar1 = (short)iVar3;
        *(short *)(plVar4[-4] + 0x10) = *(short *)((int)plVar4 + -6) + sVar1;
        *(short *)(plVar4[-4] + 0x18) = *(short *)(plVar4 + -1) + sVar1;
        if ((pWVar5->flags & 2U) != 0) {
          *(int *)(*(int *)(plVar4[-3] + 8) + 0x38) = *(short *)(plVar4 + -2) + iVar3;
          ***(ushort ***)(plVar4[-3] + 8) = ***(ushort ***)(plVar4[-3] + 8) | 1;
        }
        if (plVar4[1] == *plVar4) {
          pWVar5->flags = 0;
        }
      }
      iVar6 = iVar6 + -1;
      plVar4 = plVar4 + 7;
      pWVar5 = pWVar5 + 1;
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
 // line 611, offset 0x800613fc
	/* begin block 1 */
		// Start line: 1364
	/* end block 1 */
	// End Line: 1365

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_DoProcess(void)

{
  EVENT_ProcessMovingWater();
  EVENT_ProcessTimers();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_BSPProcess(struct _StreamUnit *streamUnit /*$fp*/)
 // line 617, offset 0x80061424
	/* begin block 1 */
		// Start line: 618
		// Start offset: 0x80061424
		// Variables:
	// 		long curTree; // $s5
	// 		struct Level *level; // $v0
	// 		struct _Terrain *terrain; // $s6

		/* begin block 1.1 */
			// Start line: 630
			// Start offset: 0x80061478
			// Variables:
		// 		struct BSPTree *bspTree; // $a3

			/* begin block 1.1.1 */
				// Start line: 638
				// Start offset: 0x80061494
				// Variables:
			// 		struct _Instance *instance; // $s1

				/* begin block 1.1.1.1 */
					// Start line: 642
					// Start offset: 0x800614A4
					// Variables:
				// 		short dx; // $s4
				// 		short dy; // $s3
				// 		short dz; // $s2

					/* begin block 1.1.1.1.1 */
						// Start line: 659
						// Start offset: 0x80061528
						// Variables:
					// 		struct _Instance *attachedInstance; // $s0
					// 		struct SVECTOR offset; // stack offset -48
					/* end block 1.1.1.1.1 */
					// End offset: 0x80061620
					// End Line: 690
				/* end block 1.1.1.1 */
				// End offset: 0x80061620
				// End Line: 693
			/* end block 1.1.1 */
			// End offset: 0x80061620
			// End Line: 694
		/* end block 1.1 */
		// End offset: 0x80061620
		// End Line: 695
	/* end block 1 */
	// End offset: 0x80061634
	// End Line: 697

	/* begin block 2 */
		// Start line: 1376
	/* end block 2 */
	// End Line: 1377

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
          instance = (gameTrackerX.instanceList)->first;
          local_30.vx = sVar8;
          local_30.vy = sVar7;
          local_30.vz = sVar6;
          while (instance != (_Instance *)0x0) {
            if (((*(int *)(iVar5 + 0x8c) == 0) && (instance->tface != (_TFace *)0x0)) &&
               ((instance->currentStreamUnitID == streamUnit->StreamUnitID &&
                (instance->bspTree == iVar9)))) {
              (instance->position).x = (instance->position).x + sVar8;
              (instance->position).z = (instance->position).z + sVar6;
              (instance->position).y = (instance->position).y + sVar7;
              COLLIDE_UpdateAllTransforms(instance,&local_30);
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
 // line 699, offset 0x80061664
	/* begin block 1 */
		// Start line: 700
		// Start offset: 0x80061664
		// Variables:
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x800617AC
	// End Line: 789

	/* begin block 2 */
		// Start line: 1638
	/* end block 2 */
	// End Line: 1639

void EVENT_Process(Event *eventInstance,long startIndex)

{
  long lVar1;
  ScriptPCode **ppSVar2;
  ScriptPCode *actionScript;
  int iVar3;
  
  iVar3 = startIndex << 2;
  currentEventInstance = eventInstance;
  if (startIndex < (int)(uint)eventInstance->numActions) {
    do {
      EventCurrentEventIndex = startIndex + 1;
      if (EventCurrentEventIndex == (uint)eventInstance->numActions) {
        EventCurrentEventIndex = -1;
      }
      if (*(int *)(iVar3 + (int)eventInstance->conditionalList) == 0) {
LAB_8006174c:
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
              if ((int)(uint)eventInstance->numActions <= startIndex) goto LAB_80061798;
              iVar3 = iVar3 + 4;
              startIndex = startIndex + 1;
            } while (*ppSVar2 == (ScriptPCode *)0x0);
          }
          if (startIndex < (int)(uint)eventInstance->numActions) goto LAB_8006174c;
        }
      }
LAB_80061798:
      startIndex = startIndex + 1;
      iVar3 = iVar3 + 4;
    } while (startIndex < (int)(uint)eventInstance->numActions);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_ProcessPuppetShow(struct Event *eventInstance /*$s1*/, long startIndex /*$a1*/)
 // line 791, offset 0x800617c4
	/* begin block 1 */
		// Start line: 792
		// Start offset: 0x800617C4
		// Variables:
	// 		long i; // $s0
	// 		long conditionIsStatisfied; // $s3
	/* end block 1 */
	// End offset: 0x80061980
	// End Line: 855

	/* begin block 2 */
		// Start line: 1880
	/* end block 2 */
	// End Line: 1881

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
    currentEventInstance = eventInstance;
    return;
  }
  EventCurrentEventIndex = startIndex + 1;
  if (EventCurrentEventIndex == (uint)eventInstance->numActions) {
    EventCurrentEventIndex = -1;
  }
  currentEventInstance = eventInstance;
  if (eventInstance->conditionalList[startIndex] == (ScriptPCode *)0x0) {
    if ((eventInstance->actionList[startIndex]->conditionBits & 2) != 0) goto LAB_80061934;
    actionScript = eventInstance->actionList[startIndex];
  }
  else {
    EventAbortLine = 0;
    CurrentEventLine = 0;
    lVar2 = EVENT_IsConditionTrue(eventInstance,eventInstance->conditionalList[startIndex]);
    if (lVar2 == 0) {
      bVar1 = false;
      goto LAB_80061934;
    }
    ppSVar3 = eventInstance->actionList + startIndex;
    if (*ppSVar3 == (ScriptPCode *)0x0) {
      do {
        cVar4 = (char)startIndex;
        ppSVar3 = ppSVar3 + 1;
        if ((int)(uint)eventInstance->numActions <= startIndex) goto LAB_80061934;
        startIndex = startIndex + 1;
      } while (*ppSVar3 == (ScriptPCode *)0x0);
    }
    cVar4 = (char)startIndex;
    if ((int)(uint)eventInstance->numActions <= startIndex) goto LAB_80061934;
    actionScript = eventInstance->actionList[startIndex];
  }
  EventAbortLine = 0;
  EVENT_DoAction(eventInstance,actionScript,actionScript->data);
LAB_80061934:
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
 // line 857, offset 0x8006199c
	/* begin block 1 */
		// Start line: 858
		// Start offset: 0x8006199C
		// Variables:
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x80061A48
	// End Line: 888

	/* begin block 2 */
		// Start line: 2023
	/* end block 2 */
	// End Line: 2024

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
  if ((int)(short)EventTimer_800d440c.nextEventIndex != -1) {
    CINE_PlayIngame((int)(short)EventTimer_800d440c.nextEventIndex);
                    /* WARNING: Read-only address (ram,0x800d4424) is written */
    EventTimer_800d440c.nextEventIndex._0_2_ = -1;
                    /* WARNING: Read-only address (ram,0x800d4420) is written */
    EventTimer_800d440c.level._0_2_ = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoAction(struct Event *eventInstance /*$s4*/, struct ScriptPCode *actionScript /*$s1*/, short *scriptData /*$s0*/)
 // line 890, offset 0x80061a60
	/* begin block 1 */
		// Start line: 891
		// Start offset: 0x80061A60
		// Variables:
	// 		long retValue; // $s3
	// 		long operateOnStack; // stack offset -32
	// 		struct _PCodeStack stack; // stack offset -1192

		/* begin block 1.1 */
			// Start line: 907
			// Start offset: 0x80061AF4
			// Variables:
		// 		struct EventTimer *timer; // $a1
		/* end block 1.1 */
		// End offset: 0x80061B44
		// End Line: 927
	/* end block 1 */
	// End offset: 0x80061BB4
	// End Line: 940

	/* begin block 2 */
		// Start line: 2102
	/* end block 2 */
	// End Line: 2103

long EVENT_DoAction(Event *eventInstance,ScriptPCode *actionScript,short *scriptData)

{
  long lVar1;
  short *psVar2;
  Level *pLVar3;
  EventTimer *pEVar4;
  int iVar5;
  long lVar6;
  _PCodeStack local_4a8;
  long local_20 [2];
  
  local_4a8.topOfStack = 0;
  EventJustRecievedTimer = 0;
  lVar6 = 1;
  currentActionScript = actionScript;
  EventAbortedPosition = scriptData;
  if ((((actionScript->conditionBits & 1) == 0) && (lVar6 = 1, scriptData != (short *)0x0)) &&
     (lVar6 = 1, EventAbortLine == 0)) {
    lVar6 = 1;
    do {
      scriptData = EVENT_ParseOpcode(&local_4a8,scriptData,local_20);
      if (((EventAbortLine != 0) && (EventJustRecievedTimer == 0)) &&
         (pEVar4 = EVENT_GetNextTimer(), psVar2 = EventAbortedPosition,
         lVar1 = EventCurrentEventIndex, pEVar4 != (EventTimer *)0x0)) {
        lVar6 = 0;
        *(Event **)&pEVar4->time = eventInstance;
        *(ScriptPCode **)&pEVar4->event = actionScript;
        pEVar4->flags = pEVar4->flags & 1;
        *(short **)&pEVar4->actionScript = psVar2;
        pLVar3 = CurrentPuzzleLevel;
        actionScript->conditionBits = actionScript->conditionBits | 1;
        *(Level **)&pEVar4->scriptPos = pLVar3;
        *(long *)&pEVar4->level = lVar1;
      }
      if (((local_20[0] != 0) && (EventAbortLine == 0)) &&
         (iVar5 = local_4a8.topOfStack + -1, 0 < local_4a8.topOfStack)) {
        local_4a8.topOfStack = iVar5;
        EVENT_ExecuteActionCommand(local_4a8.stack + iVar5,(StackType *)0x0,&local_4a8,scriptData);
      }
    } while ((scriptData != (short *)0x0) && (EventAbortLine == 0));
  }
  return lVar6;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_IsConditionTrue(struct Event *eventInstance /*$a0*/, struct ScriptPCode *conditionScript /*$a1*/)
 // line 944, offset 0x80061bd8
	/* begin block 1 */
		// Start line: 945
		// Start offset: 0x80061BD8
		// Variables:
	// 		long retValue; // $s0
	// 		long error; // stack offset -28
	// 		long operateOnStack; // stack offset -32
	// 		short flags; // stack offset -24
	// 		struct _PCodeStack stack; // stack offset -1192
	// 		short *scriptData; // $s1
	/* end block 1 */
	// End offset: 0x80061CB0
	// End Line: 1000

	/* begin block 2 */
		// Start line: 2228
	/* end block 2 */
	// End Line: 2229

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
        if ((codeStream == (short *)0x0) || (EventAbortLine != 0)) goto LAB_80061c9c;
        codeStream = EVENT_ParseOpcode(&local_4a8,codeStream,&local_20);
      } while ((local_20 == 0) || (EventAbortLine != 0));
      CurrentEventLine = CurrentEventLine + 1;
      iVar1 = local_4a8.topOfStack + -1;
    } while (local_4a8.topOfStack < 1);
    local_4a8.topOfStack = iVar1;
    lVar2 = EVENT_GetScalerValueFromOperand(local_4a8.stack + iVar1,&local_1c,asStack24);
    if (local_1c != 0) break;
    if (lVar2 == 0) {
LAB_80061c9c:
      if (EventAbortLine == 1) {
        lVar2 = 0;
      }
      return lVar2;
    }
  }
  lVar2 = 0;
  goto LAB_80061c9c;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_WriteEventObject(struct StackType *stackEntry /*$s0*/, long areaID /*$s1*/, struct Event *event /*$a2*/, long number /*$s2*/)
 // line 1003, offset 0x80061cc8
	/* begin block 1 */
		// Start line: 1004
		// Start offset: 0x80061CC8
		// Variables:
	// 		long retValue; // $a0

		/* begin block 1.1 */
			// Start line: 1019
			// Start offset: 0x80061D04
			// Variables:
		// 		struct SavedBasic *savedEvent; // $v1
		/* end block 1.1 */
		// End offset: 0x80061D5C
		// End Line: 1043
	/* end block 1 */
	// End offset: 0x80061D5C
	// End Line: 1046

	/* begin block 2 */
		// Start line: 2367
	/* end block 2 */
	// End Line: 2368

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
 // line 1049, offset 0x80061d78
	/* begin block 1 */
		// Start line: 1050
		// Start offset: 0x80061D78
		// Variables:
	// 		struct _MultiSignal *retValue; // $a2
	// 		struct Level *level; // $a0
	/* end block 1 */
	// End offset: 0x80061E00
	// End Line: 1105

	/* begin block 2 */
		// Start line: 2468
	/* end block 2 */
	// End Line: 2469

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
 // line 1108, offset 0x80061e10
	/* begin block 1 */
		// Start line: 1109
		// Start offset: 0x80061E10
	/* end block 1 */
	// End offset: 0x80061E10
	// End Line: 1109

	/* begin block 2 */
		// Start line: 2587
	/* end block 2 */
	// End Line: 2588

Intro * EVENT_ResolveObjectIntro(EventInstanceObject *instanceObject)

{
  Intro *pIVar1;
  
  pIVar1 = INSTANCE_FindIntro(instanceObject->unitID,instanceObject->introUniqueID);
  return pIVar1;
}



// decompiled code
// original method signature: 
// struct _SFXMkr * /*$ra*/ EVENT_ResolveSFXMarker(struct _StreamUnit *stream /*$a0*/, struct EventInstanceObject *instanceObject /*$a1*/)
 // line 1119, offset 0x80061e3c
	/* begin block 1 */
		// Start line: 1121
		// Start offset: 0x80061E3C
		// Variables:
	// 		int i; // $a0
	// 		struct Level *level; // $t0
	// 		struct _SFXMkr *result; // $a2
	/* end block 1 */
	// End offset: 0x80061E94
	// End Line: 1139

	/* begin block 2 */
		// Start line: 2609
	/* end block 2 */
	// End Line: 2610

	/* begin block 3 */
		// Start line: 2610
	/* end block 3 */
	// End Line: 2611

	/* begin block 4 */
		// Start line: 2614
	/* end block 4 */
	// End Line: 2615

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
 // line 1142, offset 0x80061e9c
	/* begin block 1 */
		// Start line: 1144
		// Start offset: 0x80061E9C

		/* begin block 1.1 */
			// Start line: 1146
			// Start offset: 0x80061EB0
			// Variables:
		// 		struct StackType *stackEntry; // $v0
		/* end block 1.1 */
		// End offset: 0x80061EE0
		// End Line: 1150
	/* end block 1 */
	// End offset: 0x80061EE0
	// End Line: 1156

	/* begin block 2 */
		// Start line: 2665
	/* end block 2 */
	// End Line: 2666

	/* begin block 3 */
		// Start line: 2666
	/* end block 3 */
	// End Line: 2667

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
 // line 1158, offset 0x80061ee8
	/* begin block 1 */
		// Start line: 1159
		// Start offset: 0x80061EE8

		/* begin block 1.1 */
			// Start line: 1162
			// Start offset: 0x80061F00
			// Variables:
		// 		struct StackType *stackEntry; // $v0
		/* end block 1.1 */
		// End offset: 0x80061F38
		// End Line: 1167
	/* end block 1 */
	// End offset: 0x80061F38
	// End Line: 1173

	/* begin block 2 */
		// Start line: 2697
	/* end block 2 */
	// End Line: 2698

void EVENT_AddPlayerObjectToStack(_PCodeStack *stack)

{
  _Instance *p_Var1;
  StackType *pSVar2;
  
  if (stack->topOfStack < 0x20) {
    pSVar2 = stack->stack + stack->topOfStack;
    pSVar2->id = 2;
    p_Var1 = gameTrackerX.playerInstance;
    *(undefined4 *)(pSVar2->data + 4) = 0xffffffff;
    *(_Instance **)pSVar2->data = p_Var1;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_AddObjectToStack(struct _PCodeStack *stack /*$s2*/, long item /*$a1*/)
 // line 1175, offset 0x80061f40
	/* begin block 1 */
		// Start line: 1176
		// Start offset: 0x80061F40
		// Variables:
	// 		struct EventBasicObject *basicObject; // $a0
	// 		int topOfStack; // $s1

		/* begin block 1.1 */
			// Start line: 1188
			// Start offset: 0x80061F6C
			// Variables:
		// 		struct StackType *stackEntry; // $s0

			/* begin block 1.1.1 */
				// Start line: 1194
				// Start offset: 0x80061FC8
			/* end block 1.1.1 */
			// End offset: 0x80061FE8
			// End Line: 1210

			/* begin block 1.1.2 */
				// Start line: 1218
				// Start offset: 0x80061FE8
			/* end block 1.1.2 */
			// End offset: 0x8006201C
			// End Line: 1235

			/* begin block 1.1.3 */
				// Start line: 1250
				// Start offset: 0x80062038
			/* end block 1.1.3 */
			// End offset: 0x80062038
			// End Line: 1252

			/* begin block 1.1.4 */
				// Start line: 1260
				// Start offset: 0x80062054
			/* end block 1.1.4 */
			// End offset: 0x80062054
			// End Line: 1262

			/* begin block 1.1.5 */
				// Start line: 1270
				// Start offset: 0x80062078
			/* end block 1.1.5 */
			// End offset: 0x80062104
			// End Line: 1320

			/* begin block 1.1.6 */
				// Start line: 1332
				// Start offset: 0x80062104
			/* end block 1.1.6 */
			// End offset: 0x80062154
			// End Line: 1354
		/* end block 1.1 */
		// End offset: 0x80062158
		// End Line: 1362
	/* end block 1 */
	// End offset: 0x80062158
	// End Line: 1368

	/* begin block 2 */
		// Start line: 2732
	/* end block 2 */
	// End Line: 2733

void EVENT_AddObjectToStack(_PCodeStack *stack,long item)

{
  long lVar1;
  Level *pLVar2;
  undefined4 uVar3;
  EventBasicObject *pEVar4;
  StackType *stackEntry;
  long lVar5;
  
  lVar1 = CurrentEventLine;
  lVar5 = stack->topOfStack;
  if (0x1f < lVar5) goto LAB_80062158;
  pEVar4 = currentEventInstance->instanceList[item];
  stackEntry = stack->stack + lVar5;
  switch((int)(((uint)(ushort)pEVar4->id - 1) * 0x10000) >> 0x10) {
  case 0:
    if ((pEVar4[1].id & 1U) == 0) {
      if (*(int *)(pEVar4 + 6) == 0) {
        if (*(int *)(pEVar4 + 8) == 0) goto LAB_80062140;
        stackEntry->id = 4;
        uVar3 = *(undefined4 *)(pEVar4 + 8);
      }
      else {
        stackEntry->id = 2;
        uVar3 = *(undefined4 *)(pEVar4 + 6);
      }
LAB_800620f8:
      *(undefined4 *)(stackEntry->data + 4) = 0xffffffff;
      *(undefined4 *)stackEntry->data = uVar3;
    }
    else {
      stackEntry->id = 0x1b;
      *(undefined2 *)stackEntry->data = 1;
      uVar3 = *(undefined4 *)(pEVar4 + 8);
      *(undefined2 *)(stackEntry->data + 2) = 0xffff;
      *(undefined4 *)(stackEntry->data + 4) = 0xffffffff;
      *(undefined4 *)(stackEntry->data + 8) = 0xffffffff;
      *(undefined4 *)(stackEntry->data + 0xc) = 0xffffffff;
      *(undefined4 *)(stackEntry->data + 0x10) = uVar3;
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
              (stackEntry,*(long *)(pEVar4 + 2),*(Event **)(pEVar4 + 4),(int)pEVar4[1].id);
    lVar5 = lVar5 + 1;
    goto LAB_80062158;
  case 3:
    if (*(int *)(pEVar4 + 4) == 0) goto LAB_80062140;
    stackEntry->id = 0x17;
    *(undefined4 *)stackEntry->data = *(undefined4 *)(pEVar4 + 4);
    uVar3 = *(undefined4 *)(pEVar4 + 6);
    *(undefined4 *)(stackEntry->data + 8) = 0xffffffff;
    *(undefined4 *)(stackEntry->data + 4) = uVar3;
    break;
  case 4:
    stackEntry->id = 1;
    uVar3 = *(undefined4 *)(pEVar4 + 4);
    *(undefined4 *)(stackEntry->data + 4) = 0xffffffff;
    *(undefined4 *)stackEntry->data = uVar3;
    *(undefined4 *)(stackEntry->data + 8) = *(undefined4 *)(pEVar4 + 2);
    break;
  case 5:
    if (*(int *)(pEVar4 + 4) != 0) {
      stackEntry->id = 0x11;
      uVar3 = *(undefined4 *)(pEVar4 + 4);
      goto LAB_800620f8;
    }
    goto LAB_80062140;
  case 6:
    if (*(int *)(pEVar4 + 10) != 0) {
      stackEntry->id = 0x1a;
      *(undefined4 *)stackEntry->data = *(undefined4 *)(pEVar4 + 10);
      lVar5 = lVar5 + 1;
      pLVar2 = STREAM_GetLevelWithID(*(long *)(pEVar4 + 2));
      *(Level **)(stackEntry->data + 4) = pLVar2;
      *(undefined4 *)(stackEntry->data + 8) = 0xffffffff;
      goto LAB_80062158;
    }
LAB_80062140:
    stackEntry->id = 6;
    *(long *)stackEntry->data = item;
    *(undefined4 *)(stackEntry->data + 4) = 0xffffffff;
  }
  lVar5 = lVar5 + 1;
LAB_80062158:
  stack->topOfStack = lVar5;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_AddCharPointerToStack(struct _PCodeStack *stack /*$a0*/, char *pointer /*$a1*/)
 // line 1375, offset 0x80062174
	/* begin block 1 */
		// Start line: 1377
		// Start offset: 0x80062174

		/* begin block 1.1 */
			// Start line: 1379
			// Start offset: 0x80062188
			// Variables:
		// 		struct StackType *stackEntry; // $v0
		/* end block 1.1 */
		// End offset: 0x800621B4
		// End Line: 1383
	/* end block 1 */
	// End offset: 0x800621B4
	// End Line: 1389

	/* begin block 2 */
		// Start line: 3147
	/* end block 2 */
	// End Line: 3148

	/* begin block 3 */
		// Start line: 3148
	/* end block 3 */
	// End Line: 3149

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
 // line 1391, offset 0x800621bc
	/* begin block 1 */
		// Start line: 1393
		// Start offset: 0x800621BC

		/* begin block 1.1 */
			// Start line: 1395
			// Start offset: 0x800621D0
			// Variables:
		// 		struct StackType *stackEntry; // $v0
		/* end block 1.1 */
		// End offset: 0x800621FC
		// End Line: 1399
	/* end block 1 */
	// End offset: 0x800621FC
	// End Line: 1405

	/* begin block 2 */
		// Start line: 3179
	/* end block 2 */
	// End Line: 3180

	/* begin block 3 */
		// Start line: 3180
	/* end block 3 */
	// End Line: 3181

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
 // line 1407, offset 0x80062204
	/* begin block 1 */
		// Start line: 1409
		// Start offset: 0x80062204

		/* begin block 1.1 */
			// Start line: 1411
			// Start offset: 0x80062218
			// Variables:
		// 		struct StackType *stackEntry; // $v0
		/* end block 1.1 */
		// End offset: 0x8006224C
		// End Line: 1417
	/* end block 1 */
	// End offset: 0x8006224C
	// End Line: 1423

	/* begin block 2 */
		// Start line: 3211
	/* end block 2 */
	// End Line: 3212

	/* begin block 3 */
		// Start line: 3212
	/* end block 3 */
	// End Line: 3213

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
 // line 1425, offset 0x80062254
	/* begin block 1 */
		// Start line: 3247
	/* end block 1 */
	// End Line: 3248

	/* begin block 2 */
		// Start line: 3248
	/* end block 2 */
	// End Line: 3249

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
 // line 1433, offset 0x8006226c
	/* begin block 1 */
		// Start line: 3263
	/* end block 1 */
	// End Line: 3264

	/* begin block 2 */
		// Start line: 3264
	/* end block 2 */
	// End Line: 3265

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
 // line 1445, offset 0x8006229c
	/* begin block 1 */
		// Start line: 3291
	/* end block 1 */
	// End Line: 3292

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
 // line 1460, offset 0x80062314
	/* begin block 1 */
		// Start line: 3321
	/* end block 1 */
	// End Line: 3322

	/* begin block 2 */
		// Start line: 3322
	/* end block 2 */
	// End Line: 3323

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
 // line 1486, offset 0x8006236c
	/* begin block 1 */
		// Start line: 1488
		// Start offset: 0x8006236C

		/* begin block 1.1 */
			// Start line: 1495
			// Start offset: 0x80062380
			// Variables:
		// 		struct StackType *stackEntry; // $a3
		/* end block 1.1 */
		// End offset: 0x800623F0
		// End Line: 1509
	/* end block 1 */
	// End offset: 0x800623F0
	// End Line: 1515

	/* begin block 2 */
		// Start line: 2972
	/* end block 2 */
	// End Line: 2973

	/* begin block 3 */
		// Start line: 3356
	/* end block 3 */
	// End Line: 3357

	/* begin block 4 */
		// Start line: 3361
	/* end block 4 */
	// End Line: 3362

long EVENT_AddSubListObjectToStack(_PCodeStack *stack,long listNumber)

{
  StackType *pSVar1;
  
  if (stack->topOfStack < 0x20) {
    pSVar1 = stack->stack + stack->topOfStack;
    pSVar1->id = 0x16;
    if (*(int *)(&eventListNumInstances + listNumber * 4) < 1) {
      *(undefined4 *)pSVar1->data = 0;
    }
    else {
      *(_Instance **)pSVar1->data = (_Instance *)(&eventListArray2010 + listNumber * 10);
    }
    *(int *)(pSVar1->data + 4) = *(int *)(&eventListNumInstances + listNumber * 4);
    *(undefined4 *)(pSVar1->data + 8) = 0;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_StackDuplicate(struct _PCodeStack *stack /*$a0*/)
 // line 1565, offset 0x800623f8
	/* begin block 1 */
		// Start line: 3130
	/* end block 1 */
	// End Line: 3131

	/* begin block 2 */
		// Start line: 3465
	/* end block 2 */
	// End Line: 3466

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
 // line 1587, offset 0x80062490
	/* begin block 1 */
		// Start line: 1589
		// Start offset: 0x80062490
		// Variables:
	// 		long retValue; // $a0
	/* end block 1 */
	// End offset: 0x80062518
	// End Line: 1634

	/* begin block 2 */
		// Start line: 3508
	/* end block 2 */
	// End Line: 3509

	/* begin block 3 */
		// Start line: 3509
	/* end block 3 */
	// End Line: 3510

	/* begin block 4 */
		// Start line: 3510
	/* end block 4 */
	// End Line: 3511

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
      goto switchD_800624cc_caseD_5;
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
switchD_800624cc_caseD_5:
  return lVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformConstrictAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a0*/, long item /*$a2*/)
 // line 1637, offset 0x80062520
	/* begin block 1 */
		// Start line: 1638
		// Start offset: 0x80062520
		// Variables:
	// 		long retValue; // $v1
	// 		struct _Instance *instance; // $a1

		/* begin block 1.1 */
			// Start line: 1648
			// Start offset: 0x80062550
		/* end block 1.1 */
		// End offset: 0x80062550
		// End Line: 1651

		/* begin block 1.2 */
			// Start line: 1662
			// Start offset: 0x80062560
		/* end block 1.2 */
		// End offset: 0x8006257C
		// End Line: 1671
	/* end block 1 */
	// End offset: 0x8006257C
	// End Line: 1683

	/* begin block 2 */
		// Start line: 3608
	/* end block 2 */
	// End Line: 3609

long EVENT_TransformConstrictAttribute(_PCodeStack *stack,StackType *stackObject,long item)

{
  uint item_00;
  
  if (item == 0x3a) {
    item_00 = (uint)(*(short *)(*(int *)stackObject->data + 0x170) < -1);
  }
  else {
    if (item != 0x3b) {
      return 0;
    }
    item_00 = (uint)(*(short *)(*(int *)stackObject->data + 0x170) < 2) ^ 1;
  }
  EVENT_ChangeOperandToNumber(stackObject,item_00,0);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformInstanceAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$s1*/, long item /*$a2*/, short *codeStream /*$a3*/)
 // line 1689, offset 0x8006258c
	/* begin block 1 */
		// Start line: 1690
		// Start offset: 0x8006258C
		// Variables:
	// 		long retValue; // $a0
	// 		long x; // $a1
	// 		long y; // $a2
	// 		long z; // $a3
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 1701
			// Start offset: 0x800625D8
			// Variables:
		// 		struct evPositionData *position; // $v0
		/* end block 1.1 */
		// End offset: 0x8006260C
		// End Line: 1716

		/* begin block 1.2 */
			// Start line: 1722
			// Start offset: 0x80062624
			// Variables:
		// 		struct evPositionData *rotation; // $v1
		// 		struct Rotation3d vector; // stack offset -40
		/* end block 1.2 */
		// End offset: 0x80062684
		// End Line: 1741

		/* begin block 1.3 */
			// Start line: 1769
			// Start offset: 0x800626DC
			// Variables:
		// 		int status; // $v1
		/* end block 1.3 */
		// End offset: 0x80062764
		// End Line: 1806

		/* begin block 1.4 */
			// Start line: 1828
			// Start offset: 0x8006278C
		/* end block 1.4 */
		// End offset: 0x8006278C
		// End Line: 1830

		/* begin block 1.5 */
			// Start line: 1841
			// Start offset: 0x800627B0
		/* end block 1.5 */
		// End offset: 0x800627B0
		// End Line: 1841

		/* begin block 1.6 */
			// Start line: 1848
			// Start offset: 0x800627D4
		/* end block 1.6 */
		// End offset: 0x800627D4
		// End Line: 1848

		/* begin block 1.7 */
			// Start line: 1855
			// Start offset: 0x800627F8
		/* end block 1.7 */
		// End offset: 0x800627F8
		// End Line: 1855

		/* begin block 1.8 */
			// Start line: 1862
			// Start offset: 0x8006281C
			// Variables:
		// 		struct _Instance *tmpI; // $s0
		// 		long value; // $a1

			/* begin block 1.8.1 */
				// Start line: 1874
				// Start offset: 0x80062850
			/* end block 1.8.1 */
			// End offset: 0x8006286C
			// End Line: 1883
		/* end block 1.8 */
		// End offset: 0x80062870
		// End Line: 1889

		/* begin block 1.9 */
			// Start line: 1898
			// Start offset: 0x80062884
		/* end block 1.9 */
		// End offset: 0x80062884
		// End Line: 1900

		/* begin block 1.10 */
			// Start line: 1911
			// Start offset: 0x800628AC
		/* end block 1.10 */
		// End offset: 0x800628AC
		// End Line: 1913

		/* begin block 1.11 */
			// Start line: 1922
			// Start offset: 0x800628D4
		/* end block 1.11 */
		// End offset: 0x800628D4
		// End Line: 1924

		/* begin block 1.12 */
			// Start line: 1951
			// Start offset: 0x800628FC
		/* end block 1.12 */
		// End offset: 0x800628FC
		// End Line: 1953

		/* begin block 1.13 */
			// Start line: 1961
			// Start offset: 0x80062920
		/* end block 1.13 */
		// End offset: 0x80062920
		// End Line: 1964

		/* begin block 1.14 */
			// Start line: 1987
			// Start offset: 0x80062998
			// Variables:
		// 		long value; // $s2

			/* begin block 1.14.1 */
				// Start line: 1990
				// Start offset: 0x800629A8
				// Variables:
			// 		struct _StreamUnit *streamUnit; // $v0
			/* end block 1.14.1 */
			// End offset: 0x800629E0
			// End Line: 1997
		/* end block 1.14 */
		// End offset: 0x80062A0C
		// End Line: 2007

		/* begin block 1.15 */
			// Start line: 2031
			// Start offset: 0x80062A8C
			// Variables:
		// 		long value; // $a1
		/* end block 1.15 */
		// End offset: 0x80062AB0
		// End Line: 2038

		/* begin block 1.16 */
			// Start line: 2044
			// Start offset: 0x80062AC4
			// Variables:
		// 		long value; // $a1
		/* end block 1.16 */
		// End offset: 0x80062AE8
		// End Line: 2051

		/* begin block 1.17 */
			// Start line: 2057
			// Start offset: 0x80062AFC
			// Variables:
		// 		long value; // $a1
		/* end block 1.17 */
		// End offset: 0x80062B20
		// End Line: 2065

		/* begin block 1.18 */
			// Start line: 2071
			// Start offset: 0x80062B34
			// Variables:
		// 		long value; // $a1
		/* end block 1.18 */
		// End offset: 0x80062B58
		// End Line: 2079

		/* begin block 1.19 */
			// Start line: 2085
			// Start offset: 0x80062B6C
			// Variables:
		// 		long value; // $a1
		/* end block 1.19 */
		// End offset: 0x80062B94
		// End Line: 2093
	/* end block 1 */
	// End offset: 0x80062BD8
	// End Line: 2163

	/* begin block 2 */
		// Start line: 3719
	/* end block 2 */
	// End Line: 3720

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
    goto LAB_80062a78;
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
LAB_80062a78:
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
      if (0 < (int)(WaitingToLoadSound - gameTrackerX.timeMult)) {
        EventAbortLine = 1;
        WaitingToLoadSound = WaitingToLoadSound - gameTrackerX.timeMult;
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
 // line 2165, offset 0x80062bf0
	/* begin block 1 */
		// Start line: 2166
		// Start offset: 0x80062BF0
		// Variables:
	// 		long retValue; // $v1

		/* begin block 1.1 */
			// Start line: 2174
			// Start offset: 0x80062C44
			// Variables:
		// 		int status; // $v1
		/* end block 1.1 */
		// End offset: 0x80062CB8
		// End Line: 2207
	/* end block 1 */
	// End offset: 0x80062CF8
	// End Line: 2253

	/* begin block 2 */
		// Start line: 4715
	/* end block 2 */
	// End Line: 4716

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
    if (iVar1 == 0) {
      if (0 < (int)(WaitingToLoadSFX - gameTrackerX.timeMult)) {
        EventAbortLine = 1;
        WaitingToLoadSFX = WaitingToLoadSFX - gameTrackerX.timeMult;
        return 1;
      }
    }
    else {
      if (iVar1 == -1) {
        return 1;
      }
    }
    WaitingToLoadSFX = 0x96000;
    lVar2 = 1;
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
 // line 2256, offset 0x80062d08
	/* begin block 1 */
		// Start line: 2257
		// Start offset: 0x80062D08
		// Variables:
	// 		long value; // $v1
	/* end block 1 */
	// End offset: 0x80062D94
	// End Line: 2289

	/* begin block 2 */
		// Start line: 4899
	/* end block 2 */
	// End Line: 4900

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
 // line 2293, offset 0x80062da4
	/* begin block 1 */
		// Start line: 2294
		// Start offset: 0x80062DA4
		// Variables:
	// 		long value; // $s0
	// 		long retValue; // $a0

		/* begin block 1.1 */
			// Start line: 2359
			// Start offset: 0x80062F20
			// Variables:
		// 		struct EventTimer *timer; // $a2
		// 		short time; // $v1
		/* end block 1.1 */
		// End offset: 0x80062F98
		// End Line: 2387

		/* begin block 1.2 */
			// Start line: 2406
			// Start offset: 0x80062FE8
			// Variables:
		// 		long wipeType; // $v1
		// 		long wipeTime; // $a0
		/* end block 1.2 */
		// End offset: 0x80063050
		// End Line: 2428

		/* begin block 1.3 */
			// Start line: 2434
			// Start offset: 0x80063060
			// Variables:
		// 		long motor0Time; // $a1
		// 		long motor0Speed; // $a0
		// 		long motor1Time; // $a3
		// 		long motor1Speed; // $a2
		/* end block 1.3 */
		// End offset: 0x80063098
		// End Line: 2458

		/* begin block 1.4 */
			// Start line: 2473
			// Start offset: 0x800630E8
			// Variables:
		// 		short rand1; // $s1
		// 		short rand2; // $s0
		/* end block 1.4 */
		// End offset: 0x80063130
		// End Line: 2486

		/* begin block 1.5 */
			// Start line: 2491
			// Start offset: 0x80063138
		/* end block 1.5 */
		// End offset: 0x80063138
		// End Line: 2493

		/* begin block 1.6 */
			// Start line: 2501
			// Start offset: 0x80063158
			// Variables:
		// 		int number; // $a1
		/* end block 1.6 */
		// End offset: 0x80063158
		// End Line: 2503

		/* begin block 1.7 */
			// Start line: 2511
			// Start offset: 0x80063178
		/* end block 1.7 */
		// End offset: 0x80063178
		// End Line: 2513

		/* begin block 1.8 */
			// Start line: 2520
			// Start offset: 0x8006319C
		/* end block 1.8 */
		// End offset: 0x8006319C
		// End Line: 2522
	/* end block 1 */
	// End offset: 0x80063208
	// End Line: 2572

	/* begin block 2 */
		// Start line: 4974
	/* end block 2 */
	// End Line: 4975

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
  Level *pLVar8;
  EventTimer *pEVar9;
  ulong item_00;
  int Data;
  long item_01;
  uint item_02;
  
  item_01 = 0;
  switch(item) {
  case 1:
    EVENT_ChangeOperandToNumber(stackObject,(gameTrackerX.currentTime * 0x1e) / 1000,0);
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
    goto LAB_80063204;
  case 0x14:
    item_00 = INSTANCE_Query(gameTrackerX.playerInstance,0xb);
    item_02 = item_00 >> 1 & 1;
    Data = STREAM_IsMorphInProgress();
    if (Data != 0) {
      item_02 = 0;
    }
    EVENT_ChangeOperandToNumber(stackObject,item_02,0);
    item_01 = 1;
    break;
  case 0x15:
    item_00 = INSTANCE_Query(gameTrackerX.playerInstance,0xb);
    item_02 = item_00 & 1;
    Data = STREAM_IsMorphInProgress();
    if (Data != 0) {
      item_02 = 0;
    }
    EVENT_ChangeOperandToNumber(stackObject,item_02,0);
    item_01 = 1;
    break;
  case 0x1b:
    item_02 = gameTrackerX.controlCommand[0][0];
    if ((gameTrackerX.controlCommand[0][0] & 0x90U) == 0x90) {
      item_02 = gameTrackerX.controlCommand[0][0] & 0xffffff6f;
    }
    EVENT_ChangeOperandToNumber(stackObject,item_02,1);
    item_01 = 1;
    break;
  case 0x31:
    pEVar9 = EVENT_GetNextTimer();
    pLVar8 = CurrentPuzzleLevel;
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
    *(Level **)&pEVar9->scriptPos = pLVar8;
    *(long *)&pEVar9->level = item_01;
    goto LAB_80063204;
  case 0x3d:
    EVENT_ChangeOperandToNumber(stackObject,(int)gameTrackerX.timeOfDay,0);
    item_01 = 1;
    break;
  case 0x42:
    item_01 = 1;
    stackObject->id = 0x19;
    *(undefined4 *)stackObject->data = 0x800d2228;
    *(undefined4 *)(stackObject->data + 8) = 0xffffffff;
    break;
  case 0x4a:
    if (codeStream != (short *)0x0) {
      MoveCodeStreamExtra = 2;
      gameTrackerX.wipeTime = codeStream[2];
      gameTrackerX.wipeType = codeStream[1];
      gameTrackerX.maxWipeTime = gameTrackerX.wipeTime;
      if (gameTrackerX.wipeTime < 0) {
        gameTrackerX.maxWipeTime = -gameTrackerX.wipeTime;
      }
      if (gameTrackerX.wipeType == 0xb) {
        if (gameTrackerX.wipeTime < 0) {
          gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x2000000;
        }
        else {
          gameTrackerX.streamFlags = gameTrackerX.streamFlags & 0xfdffffff;
        }
      }
      stack->topOfStack = stack->topOfStack + -1;
    }
    goto LAB_80063204;
  case 0x51:
    item_01 = 10;
    Data = 0;
    goto LAB_800630cc;
  case 0x52:
    item_01 = 0x2a;
    Data = 1;
LAB_800630cc:
    INSTANCE_Broadcast((_Instance *)0x0,item_01,(int)&DAT_0004000e,Data);
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
    goto LAB_80063204;
  case 0x78:
    Data = LOAD_IsXAInQueue();
    EVENT_ChangeOperandToNumber(stackObject,(uint)(Data == 0),0);
    item_01 = 1;
    break;
  case 0x86:
    EVENT_ChangeOperandToNumber(stackObject,(uint)gameTrackerX.streamFlags >> 0x17 & 1,0);
    item_01 = 1;
    break;
  case 0x91:
    stack->topOfStack = stack->topOfStack + -1;
    EVENT_AddShortPointerToStack(stack,&gEndGameNow);
    item_01 = 1;
    break;
  case 0x9a:
    item_00 = INSTANCE_Query(gameTrackerX.playerInstance,0x29);
    EVENT_ChangeOperandToNumber(stackObject,item_00,3);
    item_01 = 1;
    break;
  case 0x9b:
    item_00 = INSTANCE_Query(gameTrackerX.playerInstance,0x2a);
    EVENT_ChangeOperandToNumber(stackObject,item_00,3);
    item_01 = 1;
    break;
  case 0x9d:
    item_01 = HINT_GetCurrentHint();
    EVENT_ChangeOperandToNumber(stackObject,item_01,0);
    item_01 = 1;
    break;
  case 0x9e:
    EVENT_ChangeOperandToNumber(stackObject,gameTrackerX.streamFlags & 0x100000,0);
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
    goto LAB_80063204;
  case 0xa8:
    stack->topOfStack = stack->topOfStack + -1;
    if ((gameTrackerX.debugFlags & 0x80000U) == 0) {
      return 1;
    }
    Data = LOAD_IsXAInQueue();
    if (Data != 0) {
      EventAbortLine = 1;
      return 1;
    }
LAB_80063204:
    item_01 = 1;
  }
  return item_01;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformAreaAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a1*/, long item /*$a2*/, short *codeStream /*$a3*/)
 // line 2576, offset 0x80063224
	/* begin block 1 */
		// Start line: 2577
		// Start offset: 0x80063224
		// Variables:
	// 		long retValue; // $v1
	// 		long offset; // $a1
	// 		struct _StreamUnit *streamUnit; // $t0
	/* end block 1 */
	// End offset: 0x800632F0
	// End Line: 2631

	/* begin block 2 */
		// Start line: 5590
	/* end block 2 */
	// End Line: 5591

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
 // line 2635, offset 0x80063300
	/* begin block 1 */
		// Start line: 2636
		// Start offset: 0x80063300
		// Variables:
	// 		long retValue; // $v1
	// 		long offset; // $a1
	// 		struct Event *event; // $t0
	/* end block 1 */
	// End offset: 0x80063380
	// End Line: 2687

	/* begin block 2 */
		// Start line: 5714
	/* end block 2 */
	// End Line: 5715

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
 // line 2690, offset 0x80063390
	/* begin block 1 */
		// Start line: 2691
		// Start offset: 0x80063390
		// Variables:
	// 		long retValue; // $v1
	// 		long offset; // $a1

		/* begin block 1.1 */
			// Start line: 2709
			// Start offset: 0x800633E8
		/* end block 1.1 */
		// End offset: 0x800633E8
		// End Line: 2711

		/* begin block 1.2 */
			// Start line: 2718
			// Start offset: 0x8006340C
		/* end block 1.2 */
		// End offset: 0x8006340C
		// End Line: 2720
	/* end block 1 */
	// End offset: 0x8006343C
	// End Line: 2749

	/* begin block 2 */
		// Start line: 5835
	/* end block 2 */
	// End Line: 5836

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
 // line 2752, offset 0x8006344c
	/* begin block 1 */
		// Start line: 2754
		// Start offset: 0x8006344C
		// Variables:
	// 		long retValue; // $a0
	/* end block 1 */
	// End offset: 0x80063478
	// End Line: 2773

	/* begin block 2 */
		// Start line: 5962
	/* end block 2 */
	// End Line: 5963

	/* begin block 3 */
		// Start line: 5963
	/* end block 3 */
	// End Line: 5964

	/* begin block 4 */
		// Start line: 5969
	/* end block 4 */
	// End Line: 5970

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
 // line 2776, offset 0x80063480
	/* begin block 1 */
		// Start line: 2778
		// Start offset: 0x80063480
		// Variables:
	// 		long retValue; // $a0
	/* end block 1 */
	// End offset: 0x800634AC
	// End Line: 2797

	/* begin block 2 */
		// Start line: 6011
	/* end block 2 */
	// End Line: 6012

	/* begin block 3 */
		// Start line: 6012
	/* end block 3 */
	// End Line: 6013

	/* begin block 4 */
		// Start line: 6018
	/* end block 4 */
	// End Line: 6019

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
 // line 2800, offset 0x800634b4
	/* begin block 1 */
		// Start line: 2801
		// Start offset: 0x800634B4
		// Variables:
	// 		long retValue; // $v1
	// 		struct Camera *camera; // $t0

		/* begin block 1.1 */
			// Start line: 2812
			// Start offset: 0x8006353C
			// Variables:
		// 		short time; // $a1
		/* end block 1.1 */
		// End offset: 0x80063590
		// End Line: 2826

		/* begin block 1.2 */
			// Start line: 2842
			// Start offset: 0x800635B0
		/* end block 1.2 */
		// End offset: 0x800635B0
		// End Line: 2844
	/* end block 1 */
	// End offset: 0x800635CC
	// End Line: 2873

	/* begin block 2 */
		// Start line: 6060
	/* end block 2 */
	// End Line: 6061

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
 // line 2876, offset 0x800635e0
	/* begin block 1 */
		// Start line: 2877
		// Start offset: 0x800635E0
		// Variables:
	// 		long retValue; // $v1
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 2899
			// Start offset: 0x80063668
			// Variables:
		// 		long maxKeyFrames; // $v0
		/* end block 1.1 */
		// End offset: 0x8006369C
		// End Line: 2910
	/* end block 1 */
	// End offset: 0x800636D0
	// End Line: 2928

	/* begin block 2 */
		// Start line: 6232
	/* end block 2 */
	// End Line: 6233

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
 // line 2931, offset 0x800636e4
	/* begin block 1 */
		// Start line: 2932
		// Start offset: 0x800636E4
		// Variables:
	// 		long retValue; // $v0
	// 		long x; // $s0
	// 		long y; // $s1
	// 		long z; // $s2
	// 		struct Intro *intro; // $a3

		/* begin block 1.1 */
			// Start line: 2943
			// Start offset: 0x80063730
		/* end block 1.1 */
		// End offset: 0x8006377C
		// End Line: 2958

		/* begin block 1.2 */
			// Start line: 2965
			// Start offset: 0x8006377C
			// Variables:
		// 		struct Rotation3d vector; // stack offset -48
		/* end block 1.2 */
		// End offset: 0x8006377C
		// End Line: 2968
	/* end block 1 */
	// End offset: 0x800637E4
	// End Line: 3035

	/* begin block 2 */
		// Start line: 6355
	/* end block 2 */
	// End Line: 6356

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
  case 4:
  case 0x3e:
  case 0x8a:
  case 0x92:
  case 0xa0:
  case 0xa6:
    *(long *)(stackObject->data + 4) = item;
    break;
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
  case 0x3f:
    EVENT_ChangeOperandToNumber(stackObject,0,0);
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_ParseOperand2(struct StackType *operand2 /*$a0*/, long *error /*$s0*/, long *trueValue /*$s1*/)
 // line 3037, offset 0x80063800
	/* begin block 1 */
		// Start line: 3038
		// Start offset: 0x80063800
		// Variables:
	// 		long number; // $v0

		/* begin block 1.1 */
			// Start line: 3043
			// Start offset: 0x80063820
			// Variables:
		// 		short flags; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x80063844
		// End Line: 3051
	/* end block 1 */
	// End offset: 0x80063844
	// End Line: 3053

	/* begin block 2 */
		// Start line: 6608
	/* end block 2 */
	// End Line: 6609

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
 // line 3055, offset 0x80063858
	/* begin block 1 */
		// Start line: 3056
		// Start offset: 0x80063858
		// Variables:
	// 		long result; // $s1
	// 		long trueValue; // stack offset -20
	// 		long number; // $a2
	// 		long error; // stack offset -24
	/* end block 1 */
	// End offset: 0x800639FC
	// End Line: 3130

	/* begin block 2 */
		// Start line: 6645
	/* end block 2 */
	// End Line: 6646

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
 // line 3133, offset 0x80063a18
	/* begin block 1 */
		// Start line: 3135
		// Start offset: 0x80063A18
		// Variables:
	// 		long value; // $a1
	// 		long trueValue; // $a2
	/* end block 1 */
	// End offset: 0x80063AD0
	// End Line: 3163

	/* begin block 2 */
		// Start line: 6803
	/* end block 2 */
	// End Line: 6804

	/* begin block 3 */
		// Start line: 6804
	/* end block 3 */
	// End Line: 6805

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
 // line 3166, offset 0x80063ae0
	/* begin block 1 */
		// Start line: 3167
		// Start offset: 0x80063AE0
		// Variables:
	// 		long error; // stack offset -32
	// 		long number; // $s0
	// 		long trueValue; // stack offset -28
	/* end block 1 */
	// End offset: 0x80063DB4
	// End Line: 3299

	/* begin block 2 */
		// Start line: 6869
	/* end block 2 */
	// End Line: 6870

long EVENT_DoGameAction(GameObject *gameObject,StackType *operand2)

{
  long modifier;
  short hintNumber;
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
          if (local_20 != 0) {
            FX_Start_Rain(100);
            return 1;
          }
          FX_Start_Rain(modifier);
          return 1;
        }
        if (iVar1 < 0x5a) {
          if (iVar1 != 2) {
            if (iVar1 != 0x58) {
              return 1;
            }
            if (local_20 != 0) {
              FX_Start_Snow(100);
              return 1;
            }
            FX_Start_Snow(modifier);
            return 1;
          }
          if (modifier == 2) {
            GAMELOOP_SetGameTime(700);
            return 1;
          }
          if (modifier < 3) {
            if (modifier != 1) {
              return 1;
            }
            GAMELOOP_SetGameTime(600);
            return 1;
          }
          if (modifier == 3) {
            GAMELOOP_SetGameTime(0x708);
            return 1;
          }
          if (modifier != 4) {
            return 1;
          }
          GAMELOOP_SetGameTime(0x76c);
          return 1;
        }
        if (iVar1 != 0x76) {
          if (iVar1 != 0x77) {
            return 1;
          }
          if (0x7e < modifier - 1U) {
            return 1;
          }
          SOUND_SetVoiceVolume(modifier);
          return 1;
        }
        if (modifier < 0) {
          return 1;
        }
        if ((gameTrackerX.debugFlags & 0x80000U) == 0) {
          return 1;
        }
        if (WaitingForVoiceNumber == modifier) {
          iVar1 = VOICEXA_IsPlaying();
          if (iVar1 == 2) {
            WaitingForVoiceNumber = -1;
            return 1;
          }
        }
        else {
          iVar1 = LOAD_IsXAInQueue();
          if (iVar1 == 0) {
            LOAD_PlayXA(modifier);
            EventAbortLine = 1;
            WaitingForVoiceNumber = modifier;
            return 1;
          }
        }
      }
      else {
        if (iVar1 == 0x93) {
          HINT_StopHint();
          return 1;
        }
        hintNumber = (short)modifier;
        if (iVar1 < 0x94) {
          if (iVar1 == 0x88) {
            SOUND_ResetMusicModifier(modifier);
            return 1;
          }
          if (iVar1 != 0x8e) {
            return 1;
          }
          HINT_StartHint(hintNumber);
          return 1;
        }
        if (iVar1 != 0x96) {
          if (iVar1 != 0x9c) {
            return 1;
          }
          HINT_KillSpecificHint(hintNumber);
          return 1;
        }
        EventTimer_800d440c.nextEventIndex._0_2_ = hintNumber;
        if ((short)EventTimer_800d440c.level != 0) {
          EventTimer_800d440c.level._0_2_ = 0;
          EventTimer_800d440c.nextEventIndex._0_2_ = 0xffff;
          return 1;
        }
      }
      EventAbortLine = 1;
    }
  }
                    /* WARNING: Read-only address (ram,0x800d4420) is written */
                    /* WARNING: Read-only address (ram,0x800d4424) is written */
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoSignalAction(struct SignalObject *signalObject /*$s0*/, struct StackType *operand2 /*$a0*/)
 // line 3302, offset 0x80063dd4
	/* begin block 1 */
		// Start line: 3303
		// Start offset: 0x80063DD4
		// Variables:
	// 		long trueValue; // stack offset -12
	// 		long number; // $v1
	// 		long error; // stack offset -16
	/* end block 1 */
	// End offset: 0x80063E3C
	// End Line: 3335

	/* begin block 2 */
		// Start line: 7143
	/* end block 2 */
	// End Line: 7144

long EVENT_DoSignalAction(SignalObject *signalObject,StackType *operand2)

{
  long lStack16;
  long local_c;
  
  local_c = 1;
  if (((signalObject->attribute != -1) &&
      (EVENT_ParseOperand2(operand2,&lStack16,&local_c), signalObject->attribute == 0x1a)) &&
     (local_c != 0)) {
    COLLIDE_HandleSignal
              (gameTrackerX.playerInstance,signalObject->msignal->signalList,
               signalObject->msignal->numSignals,0);
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformSignalAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a0*/, long item /*$a2*/)
 // line 3338, offset 0x80063e50
	/* begin block 1 */
		// Start line: 3339
		// Start offset: 0x80063E50
		// Variables:
	// 		long retValue; // $v1
	// 		struct _MultiSignal *msignal; // $a1
	/* end block 1 */
	// End offset: 0x80063E98
	// End Line: 3367

	/* begin block 2 */
		// Start line: 7220
	/* end block 2 */
	// End Line: 7221

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
 // line 3371, offset 0x80063ea8
	/* begin block 1 */
		// Start line: 3373
		// Start offset: 0x80063EA8
		// Variables:
	// 		long retValue; // $v0
	/* end block 1 */
	// End offset: 0x80063ED8
	// End Line: 3393

	/* begin block 2 */
		// Start line: 7294
	/* end block 2 */
	// End Line: 7295

	/* begin block 3 */
		// Start line: 7295
	/* end block 3 */
	// End Line: 7296

	/* begin block 4 */
		// Start line: 7297
	/* end block 4 */
	// End Line: 7298

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
 // line 3395, offset 0x80063ee0
	/* begin block 1 */
		// Start line: 3396
		// Start offset: 0x80063EE0
		// Variables:
	// 		long retValue; // $a2
	/* end block 1 */
	// End offset: 0x80063FCC
	// End Line: 3448

	/* begin block 2 */
		// Start line: 7342
	/* end block 2 */
	// End Line: 7343

long EVENT_TransformVector3dAttribute
               (_PCodeStack *stack,StackType *stackObject,long item,short *codeStream)

{
  short sVar1;
  long item_00;
  
  switch(item) {
  case 6:
    item_00 = (long)*(short *)stackObject->data;
    goto LAB_80063f34;
  case 7:
    item_00 = (long)*(short *)(stackObject->data + 2);
    goto LAB_80063f34;
  case 8:
    item_00 = (long)*(short *)(stackObject->data + 4);
LAB_80063f34:
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
 // line 3451, offset 0x80063fdc
	/* begin block 1 */
		// Start line: 7471
	/* end block 1 */
	// End Line: 7472

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
 // line 3474, offset 0x8006400c
	/* begin block 1 */
		// Start line: 3475
		// Start offset: 0x8006400C
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $a2
	// 		long result; // $s0
	// 		long error; // stack offset -24
	/* end block 1 */
	// End offset: 0x800640FC
	// End Line: 3528

	/* begin block 2 */
		// Start line: 7517
	/* end block 2 */
	// End Line: 7518

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
 // line 3531, offset 0x80064114
	/* begin block 1 */
		// Start line: 7642
	/* end block 1 */
	// End Line: 7643

	/* begin block 2 */
		// Start line: 7643
	/* end block 2 */
	// End Line: 7644

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
 // line 3539, offset 0x8006419c
	/* begin block 1 */
		// Start line: 7658
	/* end block 1 */
	// End Line: 7659

	/* begin block 2 */
		// Start line: 7659
	/* end block 2 */
	// End Line: 7660

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
 // line 3547, offset 0x80064224
	/* begin block 1 */
		// Start line: 3548
		// Start offset: 0x80064224
		// Variables:
	// 		long trueValue; // stack offset -28
	// 		long number; // $s0
	// 		long result; // $s4
	// 		long error; // stack offset -32

		/* begin block 1.1 */
			// Start line: 3559
			// Start offset: 0x80064268
			// Variables:
		// 		struct _Instance *instance; // $s1
		// 		struct MultiSpline *spline; // $s2

			/* begin block 1.1.1 */
				// Start line: 3611
				// Start offset: 0x80064328
				// Variables:
			// 		long curKeyFrame; // $a0

				/* begin block 1.1.1.1 */
					// Start line: 3619
					// Start offset: 0x80064338
					// Variables:
				// 		long maxKeyFrames; // $v1
				/* end block 1.1.1.1 */
				// End offset: 0x80064358
				// End Line: 3627
			/* end block 1.1.1 */
			// End offset: 0x8006444C
			// End Line: 3671
		/* end block 1.1 */
		// End offset: 0x800645CC
		// End Line: 3711
	/* end block 1 */
	// End offset: 0x800645CC
	// End Line: 3713

	/* begin block 2 */
		// Start line: 7674
	/* end block 2 */
	// End Line: 7675

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
    goto switchD_800642a8_caseD_d;
  case 0xe:
    local_1c = local_1c ^ 1;
switchD_800642a8_caseD_d:
    lVar9 = 1;
    if (local_1c == 0) {
      uVar6 = instance->flags;
      uVar4 = 0xfdffffff;
LAB_80064458:
      instance->flags = uVar6 & uVar4;
    }
    else {
      uVar4 = instance->flags;
      uVar6 = 0x2000000;
LAB_80064440:
      instance->flags = uVar4 | uVar6;
    }
switchD_800642a8_caseD_12:
    return lVar9;
  case 0xf:
  case 0x28:
    if (iVar3 == -1) {
      return 0;
    }
    SCRIPT_InstanceSplineSet
              (instance,(short)iVar3,(SplineDef *)0x0,(SplineDef *)0x0,(SplineDef *)0x0);
    uVar4 = 0xfdff0000;
    goto LAB_80064450;
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
    if (iVar3 < 1) goto LAB_80064438;
LAB_80064450:
    uVar6 = instance->flags;
    uVar4 = uVar4 | 0xffff;
    goto LAB_80064458;
  default:
    goto switchD_800642a8_caseD_12;
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
      goto LAB_80064450;
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
        goto LAB_80064450;
      }
      EVENT_ResetAllSplineFlags(spline);
      EVENT_SetSplineLoop(spline);
      instance->splineFlags = instance->splineFlags | 0x20;
    }
LAB_80064438:
    uVar4 = instance->flags;
    uVar6 = 0x1000000;
    goto LAB_80064440;
  }
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoAnimateAction(struct InstanceAnimate *instanceAnimate /*$s1*/, struct StackType *operand2 /*$s3*/)
 // line 3716, offset 0x800645f0
	/* begin block 1 */
		// Start line: 3717
		// Start offset: 0x800645F0
		// Variables:
	// 		long trueValue; // stack offset -28
	// 		long number; // $a0
	// 		long result; // $s2
	// 		long error; // stack offset -32
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 3782
			// Start offset: 0x800646CC
			// Variables:
		// 		struct _Instance *hostInstance; // $v0
		/* end block 1.1 */
		// End offset: 0x800646CC
		// End Line: 3783
	/* end block 1 */
	// End offset: 0x800648A4
	// End Line: 3937

	/* begin block 2 */
		// Start line: 8035
	/* end block 2 */
	// End Line: 8036

long EVENT_DoAnimateAction(InstanceAnimate *instanceAnimate,StackType *operand2)

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
      Message = (undefined *)0x8000010;
      Data = 0;
    }
    else {
      if ((instance->aliasCommand).hostInstance == (_Instance *)0x0) {
        Data = SetAnimationInstanceSwitchData
                         (instance,(int)(instance->aliasCommand).newanim,
                          (int)(instance->aliasCommand).newframe,
                          (int)(instance->aliasCommand).interpframes,1);
        Message = (undefined *)0x8000008;
      }
      else {
        Data = SetActionPlayHostAnimationData
                         (instance,(instance->aliasCommand).hostInstance,
                          (int)(instance->aliasCommand).newanim,
                          (int)(instance->aliasCommand).newframe,
                          (int)(instance->aliasCommand).interpframes,1);
        Message = &DAT_00040003;
      }
    }
    INSTANCE_Post(instance,(int)Message,Data);
    memset(&instance->aliasCommand,0,0xc);
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
      Message = (undefined *)0x8000008;
    }
    else {
      Data = SetActionPlayHostAnimationData
                       (instance,(instance->aliasCommand).hostInstance,
                        (int)(instance->aliasCommand).newanim,(int)(instance->aliasCommand).newframe
                        ,(int)(instance->aliasCommand).interpframes,2);
      Message = &DAT_00040003;
    }
LAB_80064888:
    INSTANCE_Post(instance,(int)Message,Data);
    goto LAB_80064890;
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
      Message = (undefined *)0x8000008;
    }
    else {
      Data = SetActionPlayHostAnimationData
                       (instance,(instance->aliasCommand).hostInstance,
                        (int)(instance->aliasCommand).newanim,(int)(instance->aliasCommand).newframe
                        ,(int)(instance->aliasCommand).interpframes,0);
      Message = &DAT_00040003;
    }
    INSTANCE_Post(instance,(int)Message,Data);
    Data = (int)(instance->aliasCommand).speed;
    if (0 < Data) {
      Message = &DAT_00040020;
      goto LAB_80064888;
    }
LAB_80064890:
    memset(&instance->aliasCommand,0,0xc);
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
 // line 3941, offset 0x800648c4
	/* begin block 1 */
		// Start line: 3942
		// Start offset: 0x800648C4
		// Variables:
	// 		long trueValue; // stack offset -36
	// 		long number; // $s0
	// 		long error; // stack offset -40
	// 		long result; // $s4
	// 		struct _Instance *instance; // $s1

		/* begin block 1.1 */
			// Start line: 4073
			// Start offset: 0x80064C58
			// Variables:
		// 		int x; // $a0
		// 		int y; // $a1
		/* end block 1.1 */
		// End offset: 0x80064CB8
		// End Line: 4091

		/* begin block 1.2 */
			// Start line: 4098
			// Start offset: 0x80064CD4
			// Variables:
		// 		struct Object *object; // $s2
		// 		int i; // $s0
		/* end block 1.2 */
		// End offset: 0x80064D38
		// End Line: 4117

		/* begin block 1.3 */
			// Start line: 4138
			// Start offset: 0x80064D88
			// Variables:
		// 		struct Intro *intro; // $a0
		/* end block 1.3 */
		// End offset: 0x80064DBC
		// End Line: 4149

		/* begin block 1.4 */
			// Start line: 4181
			// Start offset: 0x80064E44
			// Variables:
		// 		struct Vector3d *vector3d; // $s0
		/* end block 1.4 */
		// End offset: 0x80064E44
		// End Line: 4184

		/* begin block 1.5 */
			// Start line: 4199
			// Start offset: 0x80064E94
		/* end block 1.5 */
		// End offset: 0x80064E94
		// End Line: 4205

		/* begin block 1.6 */
			// Start line: 4211
			// Start offset: 0x80064ED0
		/* end block 1.6 */
		// End offset: 0x80064ED0
		// End Line: 4217

		/* begin block 1.7 */
			// Start line: 4226
			// Start offset: 0x80064F1C
		/* end block 1.7 */
		// End offset: 0x80064F1C
		// End Line: 4231

		/* begin block 1.8 */
			// Start line: 4237
			// Start offset: 0x80064F58
		/* end block 1.8 */
		// End offset: 0x80064F58
		// End Line: 4243

		/* begin block 1.9 */
			// Start line: 4249
			// Start offset: 0x80064F94
		/* end block 1.9 */
		// End offset: 0x80064F94
		// End Line: 4255

		/* begin block 1.10 */
			// Start line: 4277
			// Start offset: 0x8006502C
			// Variables:
		// 		struct EventTimer *timer; // $a2
		/* end block 1.10 */
		// End offset: 0x80065040
		// End Line: 4282

		/* begin block 1.11 */
			// Start line: 4316
			// Start offset: 0x800650F0
		/* end block 1.11 */
		// End offset: 0x800650F0
		// End Line: 4321

		/* begin block 1.12 */
			// Start line: 4369
			// Start offset: 0x800651D0
		/* end block 1.12 */
		// End offset: 0x80065214
		// End Line: 4374
	/* end block 1 */
	// End offset: 0x80065340
	// End Line: 4427

	/* begin block 2 */
		// Start line: 8500
	/* end block 2 */
	// End Line: 8501

long EVENT_DoInstanceAction(InstanceObject *instanceObject,StackType *operand2,short *codeStream)

{
  long lVar1;
  Event *pEVar2;
  ScriptPCode *pSVar3;
  Level *pLVar4;
  uint type;
  ulong uVar5;
  EventTimer *pEVar6;
  int Data;
  Intro *pIVar7;
  undefined *Message;
  uint uVar8;
  int y;
  _Instance *sender;
  Object *pOVar9;
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
      INSTANCE_Post(sender,(int)&DAT_00040017,type - 0x100);
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
    goto switchD_80064948_caseD_a;
  case 0xb:
    local_24 = local_24 ^ 1;
switchD_80064948_caseD_a:
    if (local_24 == 0) {
      type = sender->flags;
      sender->flags2 = sender->flags2 & 0xdfffffff;
      sender->flags = type & 0xfffff7ff;
      sender->flags = type & 0xfffbf7ff;
      if ((sender->object->oflags2 & 0x80000U) != 0) {
        type = sender->flags2 & 0xefffffff;
        goto LAB_80064b8c;
      }
    }
    else {
      sender->flags = sender->flags | 0x800;
      sender->flags2 = sender->flags2 | 0x20000000;
      sender->flags = sender->flags | 0x40000;
      if ((sender->object->oflags2 & 0x80000U) != 0) {
        type = sender->flags2 | 0x10000000;
LAB_80064b8c:
        sender->flags2 = type;
      }
    }
    uVar5 = INSTANCE_Query(sender,1);
    if ((uVar5 & 0xe) == 0) {
      return 1;
    }
    Message = &DAT_00040013;
    type = local_24;
LAB_80064bb4:
    INSTANCE_Post(sender,(int)Message,type);
    return 1;
  case 0x14:
    local_24 = local_24 ^ 1;
  case 0x15:
    if (local_24 == 0) {
      Message = (undefined *)0x10002001;
      type = 0;
    }
    else {
      Message = (undefined *)0x10002002;
      type = 0;
    }
    goto LAB_80064bb4;
  case 0x20:
    if (type == 2) {
      Message = &DAT_00040012;
    }
    else {
      if ((int)type < 3) {
        if (type != 1) {
          return 0;
        }
        Message = (undefined *)0x40000;
      }
      else {
        if (type != 3) {
          if (type != 4) {
            return 0;
          }
          INSTANCE_Post(sender,(int)&DAT_00040005,(int)&DAT_0000a000);
          return 0;
        }
        Message = &DAT_00040014;
      }
    }
    goto LAB_800652ec;
  case 0x24:
    goto switchD_80064948_caseD_24;
  case 0x25:
    local_24 = local_24 ^ 1;
switchD_80064948_caseD_24:
    if (local_24 == 0) {
      uVar5 = INSTANCE_Query(instanceObject->instance,5);
      if ((uVar5 & 1) == 0) {
        return 0;
      }
      Message = (undefined *)0x800020;
    }
    else {
      uVar5 = INSTANCE_Query(instanceObject->instance,5);
      if ((uVar5 & 1) != 0) {
        return 0;
      }
      Message = (undefined *)0x800020;
    }
    goto LAB_800652ec;
  case 0x26:
    local_24 = local_24 ^ 1;
  case 0x27:
    if (local_24 == 0) {
      type = 0x800000;
LAB_800652e8:
      Message = (undefined *)(type | 0x22);
    }
    else {
      Message = (undefined *)0x800021;
    }
    goto LAB_800652ec;
  case 0x33:
    if (type == 0xffffffff) {
      type = 0;
    }
    Message = (undefined *)0x1000017;
    goto LAB_800652d0;
  case 0x34:
    if (local_24 == 0) {
      type = sender->flags & 0xfffff7ff;
    }
    else {
      type = sender->flags | 0x800;
    }
    goto LAB_80064a58;
  case 0x35:
    if (local_24 == 0) {
      sender->flags2 = sender->flags2 & 0xdfffffff;
      sender->flags = sender->flags & 0xfffbffff;
      return 1;
    }
    sender->flags2 = sender->flags2 | 0x20000000;
    type = sender->flags | 0x40000;
LAB_80064a58:
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
      Message = (undefined *)0x800000;
      goto LAB_80065240;
    }
    break;
  case 0x37:
    pOVar9 = sender->object;
    Data = (int)pOVar9->numberOfEffects;
    if (Data != 0) {
      if (type == 0xffffffff) {
        y = 0;
        if (0 < Data) {
          do {
            FX_StartInstanceEffect(sender,pOVar9->effectList + y,0);
            y = y + 1;
          } while (y < pOVar9->numberOfEffects);
          return 0;
        }
      }
      else {
        if ((int)type < Data) {
          FX_StartInstanceEffect(sender,pOVar9->effectList + type,0);
          return 0;
        }
      }
    }
    break;
  case 0x40:
    if (type != 0) {
      type = 1;
    }
    Message = (undefined *)0x100001a;
    goto LAB_800652d0;
  case 0x4b:
    if (operand2 != (StackType *)0x0) {
      if (operand2->id != 9) {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data,(int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      Message = &DAT_00040016;
      goto LAB_80065240;
    }
    break;
  case 0x4c:
    if (operand2 != (StackType *)0x0) {
      if (operand2->id != 9) {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data,(int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      INSTANCE_Post(sender,(int)&DAT_0004000a,Data);
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
      Message = &DAT_0004000b;
      goto LAB_80065240;
    }
    break;
  case 0x4e:
    goto switchD_80064948_caseD_4e;
  case 0x4f:
    local_24 = (uint)(local_24 == 0);
switchD_80064948_caseD_4e:
    if (sender != gameTrackerX.playerInstance) {
      INSTANCE_Post(sender,(int)&DAT_0004000e,local_24);
      return 0;
    }
    INSTANCE_Post(sender,(int)&DAT_0004000e,local_24);
    if (local_24 == 0) {
      gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffffff6f;
      return 0;
    }
    gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x90;
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
      pLVar4 = CurrentPuzzleLevel;
      pSVar3->conditionBits = pSVar3->conditionBits | 1;
      *(Level **)&pEVar6->scriptPos = pLVar4;
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
      Message = &DAT_0004000d;
      goto LAB_80065240;
    }
    break;
  case 0x53:
    if (operand2 != (StackType *)0x0) {
      if (operand2->id != 9) {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data,(int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      Message = &DAT_0004000f;
      goto LAB_80065240;
    }
    break;
  case 0x54:
    if (local_24 != 0) {
      Message = &DAT_00040010;
      goto LAB_800652ec;
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
    goto switchD_80064948_caseD_5e;
  case 0x5f:
    local_24 = 0;
switchD_80064948_caseD_5e:
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
    Message = (undefined *)0x4000005;
LAB_80065240:
    INSTANCE_Post(sender,(int)Message,Data);
    return 0;
  case 0x6d:
    Message = (undefined *)0x4000006;
    goto LAB_800652ec;
  case 0x6e:
    Message = &DAT_00040011;
LAB_800652ec:
    INSTANCE_Post(sender,(int)Message,0);
    return 0;
  case 0x6f:
    INSTANCE_Post(sender,(int)&DAT_00040015,1 << (type & 0x1f));
    return 0;
  case 0x72:
    if (operand2 != (StackType *)0x0) {
      if (operand2->id != 9) {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data,(int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      Message = &DAT_0004000c;
      goto LAB_80065240;
    }
    break;
  case 0x74:
    INSTANCE_Post(sender,(int)&PTR_00040006,type << 0xc);
    return 0;
  case 0x7b:
    if (operand2 != (StackType *)0x0) {
      if (operand2->id != 9) {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data,(int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      Message = &DAT_00040018;
      goto LAB_80065240;
    }
    break;
  case 0x7c:
    type = type << 0xc;
    INSTANCE_Post(sender,(int)&DAT_00040019,type);
  case 0xa3:
    uVar8 = 0x1000000;
LAB_800652cc:
    Message = (undefined *)(uVar8 | 0x22);
LAB_800652d0:
    INSTANCE_Post(sender,(int)Message,type);
    return 0;
  case 0x85:
    Message = &DAT_00040021;
    goto LAB_800652d0;
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
    uVar8 = 0x40000;
    goto LAB_800652cc;
  case 0x8d:
    if (-1 < (int)type) {
      Data = SetMonsterAlarmData(sender,(_Position *)0x0,type);
      INSTANCE_Broadcast((_Instance *)0x0,10,0x1000011,Data);
      return 0;
    }
    break;
  case 0xa4:
    type = 0x1000000;
    goto LAB_800652e8;
  case 0xa5:
    if (sender != gameTrackerX.playerInstance) {
      return 0;
    }
    if (local_24 == 0) {
      gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffffff6f;
    }
    else {
      gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x90;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_GetTGroupValue(struct TGroupObject *terrainGroup /*$a0*/)
 // line 4430, offset 0x80065368
	/* begin block 1 */
		// Start line: 4432
		// Start offset: 0x80065368
		// Variables:
	// 		long value; // $a2
	// 		long trueValue; // $a3
	// 		struct BSPTree *bspTree; // $a1
	/* end block 1 */
	// End offset: 0x800654C8
	// End Line: 4539

	/* begin block 2 */
		// Start line: 9509
	/* end block 2 */
	// End Line: 9510

	/* begin block 3 */
		// Start line: 9510
	/* end block 3 */
	// End Line: 9511

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
        return 0;
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
 // line 4542, offset 0x800654d4
	/* begin block 1 */
		// Start line: 4543
		// Start offset: 0x800654D4
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $v0
	// 		long error; // stack offset -24
	// 		long result; // $s2

		/* begin block 1.1 */
			// Start line: 4554
			// Start offset: 0x80065508
			// Variables:
		// 		struct BSPTree *bspTree; // $s0

			/* begin block 1.1.1 */
				// Start line: 4562
				// Start offset: 0x800655B4
				// Variables:
			// 		struct WaterLevelProcess *curWater; // $a0
			/* end block 1.1.1 */
			// End offset: 0x80065640
			// End Line: 4578

			/* begin block 1.1.2 */
				// Start line: 4586
				// Start offset: 0x80065654
				// Variables:
			// 		long offsetz; // $a0
			/* end block 1.1.2 */
			// End offset: 0x800656D8
			// End Line: 4599
		/* end block 1.1 */
		// End offset: 0x800657C0
		// End Line: 4669
	/* end block 1 */
	// End offset: 0x800657C0
	// End Line: 4671

	/* begin block 2 */
		// Start line: 9737
	/* end block 2 */
	// End Line: 9738

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
  if (iVar4 != 0x2e) {
    if (iVar4 < 0x2f) {
      if (iVar4 == 0xb) {
        local_14 = local_14 ^ 1;
      }
      else {
        if (0xb < iVar4) {
          if (iVar4 != 0x2c) {
            if (iVar4 != 0x2d) {
              return 0;
            }
LAB_80065654:
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
          goto LAB_800655b4;
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
          if (iVar4 == 0x2f) goto LAB_80065654;
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
LAB_800655b4:
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



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoCameraAction(struct CameraObject *cameraObject /*$s2*/, struct StackType *operand2 /*$s0*/, short *codeStream /*$a2*/)
 // line 4674, offset 0x800657dc
	/* begin block 1 */
		// Start line: 4675
		// Start offset: 0x800657DC
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $a1
	// 		long error; // stack offset -24
	// 		struct Camera *camera; // $s1

		/* begin block 1.1 */
			// Start line: 4708
			// Start offset: 0x80065878
			// Variables:
		// 		struct Intro *intro; // $a0
		/* end block 1.1 */
		// End offset: 0x800658E0
		// End Line: 4738

		/* begin block 1.2 */
			// Start line: 4747
			// Start offset: 0x800658FC
			// Variables:
		// 		long angle; // $a1
		/* end block 1.2 */
		// End offset: 0x800659C0
		// End Line: 4768

		/* begin block 1.3 */
			// Start line: 4780
			// Start offset: 0x800659EC
			// Variables:
		// 		long angle; // $v0
		/* end block 1.3 */
		// End offset: 0x80065A3C
		// End Line: 4790

		/* begin block 1.4 */
			// Start line: 4804
			// Start offset: 0x80065A5C
			// Variables:
		// 		long angle; // $v0
		/* end block 1.4 */
		// End offset: 0x80065A9C
		// End Line: 4813

		/* begin block 1.5 */
			// Start line: 4841
			// Start offset: 0x80065B14
		/* end block 1.5 */
		// End offset: 0x80065B14
		// End Line: 4845
	/* end block 1 */
	// End offset: 0x80065B40
	// End Line: 4875

	/* begin block 2 */
		// Start line: 10011
	/* end block 2 */
	// End Line: 10012

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
    goto LAB_80065aa8;
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
LAB_80065aa8:
    CAMERA_Adjust_roll((iVar2 + iVar1 >> 8) - (iVar1 >> 0x1f),frames);
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoObjectSoundAction(struct SoundObject *soundObject /*$s0*/, struct StackType *operand2 /*$a0*/)
 // line 4878, offset 0x80065b5c
	/* begin block 1 */
		// Start line: 4879
		// Start offset: 0x80065B5C
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $v1
	// 		long error; // stack offset -24
	// 		long result; // $s2
	// 		struct _Instance *instance; // $a3

		/* begin block 1.1 */
			// Start line: 4894
			// Start offset: 0x80065B94
			// Variables:
		// 		struct SoundInstance *soundInstance; // $s1
		/* end block 1.1 */
		// End offset: 0x80065C74
		// End Line: 4932
	/* end block 1 */
	// End offset: 0x80065C74
	// End Line: 4933

	/* begin block 2 */
		// Start line: 10427
	/* end block 2 */
	// End Line: 10428

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
 // line 4936, offset 0x80065c90
	/* begin block 1 */
		// Start line: 4937
		// Start offset: 0x80065C90
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $v1
	// 		long error; // stack offset -24
	// 		long result; // $s2
	// 		struct _SFXMkr *sfxMarker; // $a3

		/* begin block 1.1 */
			// Start line: 4952
			// Start offset: 0x80065CC8
			// Variables:
		// 		struct SoundInstance *soundInstance; // $s1
		/* end block 1.1 */
		// End offset: 0x80065DA8
		// End Line: 4990
	/* end block 1 */
	// End offset: 0x80065DA8
	// End Line: 4991

	/* begin block 2 */
		// Start line: 10552
	/* end block 2 */
	// End Line: 10553

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
 // line 4994, offset 0x80065dc4
	/* begin block 1 */
		// Start line: 4996
		// Start offset: 0x80065DC4
	/* end block 1 */
	// End offset: 0x80065DC4
	// End Line: 5028

	/* begin block 2 */
		// Start line: 10677
	/* end block 2 */
	// End Line: 10678

	/* begin block 3 */
		// Start line: 10678
	/* end block 3 */
	// End Line: 10679

	/* begin block 4 */
		// Start line: 10710
	/* end block 4 */
	// End Line: 10711

	/* begin block 5 */
		// Start line: 10711
	/* end block 5 */
	// End Line: 10712

long EVENT_GetSoundValue(SoundObject *soundObject)

{
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoAreaAction(struct AreaObject *areaObject /*$s1*/, struct StackType *operand2 /*$a0*/)
 // line 5031, offset 0x80065dcc
	/* begin block 1 */
		// Start line: 5032
		// Start offset: 0x80065DCC
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $v1
	// 		long error; // stack offset -24
	// 		struct _StreamUnit *streamUnit; // $s0
	/* end block 1 */
	// End offset: 0x80065E60
	// End Line: 5075

	/* begin block 2 */
		// Start line: 10751
	/* end block 2 */
	// End Line: 10752

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
 // line 5078, offset 0x80065e78
	/* begin block 1 */
		// Start line: 5079
		// Start offset: 0x80065E78
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $a2
	// 		long error; // stack offset -24
	// 		long result; // $s2

		/* begin block 1.1 */
			// Start line: 5090
			// Start offset: 0x80065EAC
			// Variables:
		// 		struct Intro *intro; // $s0

			/* begin block 1.1.1 */
				// Start line: 5140
				// Start offset: 0x80065FE0
				// Variables:
			// 		int i; // $a2
			// 		int j; // $v1
			// 		int id; // $a1

				/* begin block 1.1.1.1 */
					// Start line: 5143
					// Start offset: 0x80065FF0

					/* begin block 1.1.1.1.1 */
						// Start line: 5146
						// Start offset: 0x80066000
						// Variables:
					// 		struct Intro *intro1; // $v0
					/* end block 1.1.1.1.1 */
					// End offset: 0x80066038
					// End Line: 5155
				/* end block 1.1.1.1 */
				// End offset: 0x80066038
				// End Line: 5156
			/* end block 1.1.1 */
			// End offset: 0x8006606C
			// End Line: 5159
		/* end block 1.1 */
		// End offset: 0x8006606C
		// End Line: 5166
	/* end block 1 */
	// End offset: 0x8006606C
	// End Line: 5168

	/* begin block 2 */
		// Start line: 10853
	/* end block 2 */
	// End Line: 10854

long EVENT_DoIntroAction(IntroObject *introObject,StackType *operand2)

{
  long lVar1;
  uint uVar2;
  Level *pLVar3;
  Intro *pIVar4;
  _Instance *p_Var5;
  uint uVar6;
  int iVar7;
  int iVar8;
  STracker *pSVar9;
  long lVar10;
  Intro *intro;
  long lVar11;
  long lStack24;
  uint local_14;
  
  lVar11 = 0;
  local_14 = 1;
  lVar10 = lVar11;
  if (introObject->attribute != -1) {
    intro = introObject->intro;
    lVar1 = EVENT_ParseOperand2(operand2,&lStack24,(long *)&local_14);
    iVar8 = introObject->attribute;
    if (iVar8 != 0x14) {
      if (iVar8 < 0x15) {
        if (iVar8 != 10) {
          if (iVar8 < 0xb) {
            if (iVar8 != 4) {
              return 0;
            }
            if (lVar1 != 0) {
              return 0;
            }
            SAVE_SetDeadDeadBit(intro->UniqueID,0);
            return 0;
          }
          if (iVar8 != 0xb) {
            return 0;
          }
          local_14 = local_14 ^ 1;
        }
        uVar6 = 0xfffffff7;
        if (local_14 == 0) {
          uVar2 = intro->flags;
          uVar6 = 0xffffff7f;
        }
        else {
          uVar2 = intro->flags | 0x80;
        }
        intro->flags = uVar2 & uVar6;
        lVar10 = 1;
      }
      else {
        if (iVar8 == 0x3e) {
          lVar10 = 0;
          iVar8 = 0;
          pSVar9 = &StreamTracker;
          do {
            if (pSVar9->StreamList[0].used == 2) {
              pLVar3 = pSVar9->StreamList[0].level;
              iVar7 = pLVar3->numIntros;
              pIVar4 = pLVar3->introList;
              while (iVar7 != 0) {
                if (pIVar4 == intro) {
                  lVar10 = pSVar9->StreamList[0].StreamUnitID;
                  break;
                }
                iVar7 = iVar7 + -1;
                pIVar4 = pIVar4 + 1;
              }
            }
            pSVar9 = (STracker *)(pSVar9->StreamList + 1);
            iVar8 = iVar8 + 1;
          } while (iVar8 < 0x10);
          p_Var5 = INSTANCE_IntroduceInstance(intro,(short)lVar10);
          lVar10 = 0;
          if (p_Var5 == (_Instance *)0x0) {
            EventAbortLine = 1;
            lVar10 = lVar11;
          }
        }
        else {
          lVar10 = 0;
          if ((0x3e < iVar8) && (lVar10 = 0, iVar8 == 0x8a)) {
            if (local_14 == 0) {
              intro->flags = intro->flags & 0xfffffbff;
              lVar10 = lVar11;
            }
            else {
              intro->flags = intro->flags | 0x400;
              lVar10 = lVar11;
            }
          }
        }
      }
    }
  }
  return lVar10;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_DoStackOperationEquals(struct _PCodeStack *stack /*$a2*/, short *codeStream /*$a3*/)
 // line 5185, offset 0x80066088
	/* begin block 1 */
		// Start line: 5186
		// Start offset: 0x80066088
		// Variables:
	// 		struct StackType operand1; // stack offset -88
	// 		struct StackType operand2; // stack offset -48
	/* end block 1 */
	// End offset: 0x8006614C
	// End Line: 5200

	/* begin block 2 */
		// Start line: 10370
	/* end block 2 */
	// End Line: 10371

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
 // line 5205, offset 0x80066174
	/* begin block 1 */
		// Start line: 5207
		// Start offset: 0x80066174
		// Variables:
	// 		long retValue; // $t2

		/* begin block 1.1 */
			// Start line: 5236
			// Start offset: 0x8006622C
			// Variables:
		// 		long dist; // $v0
		/* end block 1.1 */
		// End offset: 0x800662AC
		// End Line: 5246

		/* begin block 1.2 */
			// Start line: 5252
			// Start offset: 0x800662B4
			// Variables:
		// 		long dist; // $v0
		/* end block 1.2 */
		// End offset: 0x80066324
		// End Line: 5262
	/* end block 1 */
	// End offset: 0x80066324
	// End Line: 5266

	/* begin block 2 */
		// Start line: 11126
	/* end block 2 */
	// End Line: 11127

	/* begin block 3 */
		// Start line: 11127
	/* end block 3 */
	// End Line: 11128

	/* begin block 4 */
		// Start line: 11129
	/* end block 4 */
	// End Line: 11130

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
      goto LAB_80066318;
    }
  }
  iVar4 = (int)vector2->vx - (int)vector1->vx;
  iVar3 = (int)vector2->vy - (int)vector1->vy;
  iVar2 = (int)vector2->vz - (int)vector1->vz;
  bVar1 = iVar4 * iVar4 + iVar3 * iVar3 + iVar2 * iVar2 <
          (int)vector1->errorx * (int)vector1->errorx;
LAB_80066318:
  if (bVar1) {
    return 1;
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_CompareRotationVectors(struct Rotation3d *rot1 /*$a0*/, struct Rotation3d *rot2 /*$s1*/, long trueValue /*$s6*/)
 // line 5275, offset 0x80066330
	/* begin block 1 */
		// Start line: 5276
		// Start offset: 0x80066330
		// Variables:
	// 		struct MATRIX matrix1; // stack offset -104
	// 		struct MATRIX matrix2; // stack offset -72
	// 		long result; // $s2
	// 		long c1; // $v1
	// 		long attribute; // $s0
	// 		struct _SVector axis; // stack offset -40
	// 		long doSoft; // $s4
	/* end block 1 */
	// End offset: 0x800664FC
	// End Line: 5373

	/* begin block 2 */
		// Start line: 11272
	/* end block 2 */
	// End Line: 11273

long EVENT_CompareRotationVectors(Rotation3d *rot1,Rotation3d *rot2,long trueValue)

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
  if (iVar3 == -1) {
    iVar3 = rot2->attribute;
  }
  RotMatrixZYX((ushort *)rot1,(uint *)&MStack104);
  RotMatrixZYX((ushort *)rot2,(uint *)&MStack72);
  if (iVar3 == 8) {
LAB_80066490:
    local_28.x = 0;
    local_28.y = 0;
    local_28.z = 0x1000;
    goto LAB_800664a4;
  }
  if (iVar3 < 9) {
    if (iVar3 == 6) {
LAB_80066460:
      local_28.x = 0x1000;
      local_28.y = 0;
      local_28.z = 0;
      goto LAB_800664a4;
    }
    if (iVar3 < 7) {
      if (iVar3 == -1) {
        local_28.x = 0x1000;
        local_28.y = 0;
        local_28.z = 0;
        iVar2 = PHYSOBS_CheckObjectAxisAlignment(&MStack104,&MStack72,&local_28);
        if (iVar2 - 0xf80U < 0x101) {
          local_28.x = 0;
          local_28.y = 0x1000;
          local_28.z = 0;
          iVar2 = PHYSOBS_CheckObjectAxisAlignment(&MStack104,&MStack72,&local_28);
          if (iVar2 - 0xf80U < 0x101) {
            uVar4 = trueValue;
          }
        }
      }
      goto LAB_800664a4;
    }
  }
  else {
    if (iVar3 != 0x61) {
      if (0x61 < iVar3) {
        if (iVar3 != 0x62) goto LAB_800664a4;
        bVar1 = true;
        goto LAB_80066490;
      }
      if (iVar3 != 0x60) goto LAB_800664a4;
      bVar1 = true;
      goto LAB_80066460;
    }
    bVar1 = true;
  }
  local_28.x = 0;
  local_28.y = 0x1000;
  local_28.z = 0;
LAB_800664a4:
  if (iVar3 != -1) {
    iVar3 = PHYSOBS_CheckObjectAxisAlignment(&MStack104,&MStack72,&local_28);
    if (bVar1) {
      uVar4 = trueValue;
      if ((0x100 < iVar3 - 0xf80U) && (&UNK_00000100 < &DAT_00001080 + iVar3)) {
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
 // line 5390, offset 0x80066528
	/* begin block 1 */
		// Start line: 5391
		// Start offset: 0x80066528
		// Variables:
	// 		long retValue; // $s4
	// 		long d; // $s0
	// 		struct StackType operand1; // stack offset -96
	// 		char objectName[16]; // stack offset -56
	// 		char *temp; // $v0
	// 		struct _Instance *instance; // $s2
	// 		long areaID; // $s5
	/* end block 1 */
	// End offset: 0x800666E8
	// End Line: 5456

	/* begin block 2 */
		// Start line: 11506
	/* end block 2 */
	// End Line: 11507

	/* begin block 3 */
		// Start line: 11513
	/* end block 3 */
	// End Line: 11514

long EVENT_CompareListWithOperation
               (_PCodeStack *stack,ListObject *listObject,StackType *operand2,long operation)

{
  char *pcVar1;
  long lVar2;
  int iVar3;
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
    *(undefined4 *)(&eventListNumInstances + CurrentEventLine * 4) = 0;
  }
  strcpy(acStack56,listObject->eventInstance->objectName);
  pcVar1 = strchr(acStack56,0x3f);
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
        if (9 < *(int *)(&eventListNumInstances + CurrentEventLine * 4)) {
          return 0;
        }
        *(int *)(&eventListNumInstances + CurrentEventLine * 4) = 0;
        return 0;
      }
    }
    else {
      iVar4 = CurrentEventLine * 4;
      if (CurrentEventLine < 0x14) {
        iVar3 = *(int *)(&eventListNumInstances + iVar4);
        if (iVar3 < 10) {
          (&eventListArray2010)[CurrentEventLine * 10 + iVar3] = startInstance;
          *(int *)(&eventListNumInstances + iVar4) = iVar3 + 1;
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
 // line 5460, offset 0x8006671c
	/* begin block 1 */
		// Start line: 5461
		// Start offset: 0x8006671C
		// Variables:
	// 		long i; // $s4
	// 		long retValue; // $s5
	// 		long d; // $s0
	// 		struct StackType operand1; // stack offset -80
	/* end block 1 */
	// End offset: 0x80066884
	// End Line: 5494

	/* begin block 2 */
		// Start line: 11657
	/* end block 2 */
	// End Line: 11658

	/* begin block 3 */
		// Start line: 11661
	/* end block 3 */
	// End Line: 11662

long EVENT_CompareSubListWithOperation
               (_PCodeStack *stack,SubListObject *subListObject,StackType *operand2,long operation)

{
  long lVar1;
  int iVar2;
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
    *(undefined4 *)(&eventListNumInstances + CurrentEventLine * 4) = 0;
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
        iVar3 = CurrentEventLine * 4;
        if (CurrentEventLine < 0x14) {
          iVar2 = *(int *)(&eventListNumInstances + iVar3);
          if (iVar2 < 10) {
            (&eventListArray2010)[CurrentEventLine * 10 + iVar2] =
                 *(_Instance **)(iVar5 + (int)subListObject->instanceList);
            *(int *)(&eventListNumInstances + iVar3) = iVar2 + 1;
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
 // line 5497, offset 0x800668b8
	/* begin block 1 */
		// Start line: 5498
		// Start offset: 0x800668B8
		// Variables:
	// 		long number; // $s1
	// 		long number1; // $s0
	// 		long number2; // $a0
	// 		long error; // stack offset -32
	// 		long trueValue; // $s2
	// 		short flags1; // stack offset -28
	// 		short flags2; // stack offset -26
	/* end block 1 */
	// End offset: 0x80066BCC
	// End Line: 5703

	/* begin block 2 */
		// Start line: 11760
	/* end block 2 */
	// End Line: 11761

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
        goto LAB_80066b4c;
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
switchD_80066ad4_caseD_6:
      uVar5 = trueValue;
      trueValue = (uint)((int)uVar2 < (int)uVar1);
      goto LAB_80066b4c;
    case 7:
switchD_80066ad4_caseD_7:
      uVar5 = trueValue;
      trueValue = (uint)((int)uVar1 < (int)uVar2);
      goto LAB_80066b4c;
    case 8:
      trueValue = 0;
      goto switchD_80066ad4_caseD_7;
    case 9:
      trueValue = 0;
      goto switchD_80066ad4_caseD_6;
    case 10:
switchD_80066ad4_caseD_a:
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
      goto switchD_80066ad4_caseD_a;
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
    goto LAB_80066b4c;
  case 0x16:
    trueValue = EVENT_CompareSubListWithOperation
                          (stack,(SubListObject *)operand1->data,operand2,operation);
    uVar5 = 1;
LAB_80066b4c:
    if (trueValue == 0) {
      uVar5 = uVar5 ^ 1;
    }
  }
  return uVar5;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_DoStackMathOperation(struct _PCodeStack *stack /*$s0*/, long operation /*$a3*/)
 // line 5709, offset 0x80066bf0
	/* begin block 1 */
		// Start line: 5710
		// Start offset: 0x80066BF0
		// Variables:
	// 		struct StackType operand1; // stack offset -128
	// 		struct StackType operand2; // stack offset -88

		/* begin block 1.1 */
			// Start line: 5728
			// Start offset: 0x80066CDC
			// Variables:
		// 		struct StackType holdOperand; // stack offset -48
		/* end block 1.1 */
		// End offset: 0x80066DA8
		// End Line: 5733
	/* end block 1 */
	// End offset: 0x80066DA8
	// End Line: 5735

	/* begin block 2 */
		// Start line: 12199
	/* end block 2 */
	// End Line: 12200

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
 // line 5739, offset 0x80066dd8
	/* begin block 1 */
		// Start line: 5740
		// Start offset: 0x80066DD8
		// Variables:
	// 		short pcode; // $v0
	/* end block 1 */
	// End offset: 0x80067034
	// End Line: 5856

	/* begin block 2 */
		// Start line: 12263
	/* end block 2 */
	// End Line: 12264

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
    goto switchD_80066e2c_caseD_2;
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
    goto LAB_80066f6c;
  case 0x11:
    EVENT_StackDuplicate(stack);
    EVENT_AddNumberToStack(stack,1,0);
    operation = 2;
LAB_80066f6c:
    EVENT_DoStackMathOperation(stack,operation);
switchD_80066e2c_caseD_2:
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
 // line 5860, offset 0x80067054
	/* begin block 1 */
		// Start line: 5862
		// Start offset: 0x80067054
		// Variables:
	// 		long value; // $a1
	// 		long trueValue; // $a2
	/* end block 1 */
	// End offset: 0x800670E0
	// End Line: 5939

	/* begin block 2 */
		// Start line: 12511
	/* end block 2 */
	// End Line: 12512

	/* begin block 3 */
		// Start line: 12512
	/* end block 3 */
	// End Line: 12513

	/* begin block 4 */
		// Start line: 12517
	/* end block 4 */
	// End Line: 12518

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
    goto LAB_800670cc;
  case 0x14:
  case 0x15:
    uVar2 = 0xffffffff;
    break;
  case 0x92:
  case 0xa6:
    uVar2 = 1;
    uVar1 = introObject->intro->flags & 8;
LAB_800670cc:
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
 // line 5942, offset 0x800670e8
	/* begin block 1 */
		// Start line: 5943
		// Start offset: 0x800670E8
		// Variables:
	// 		long i; // $s2
	// 		long d; // $s0
	// 		struct StackType operand1; // stack offset -72
	/* end block 1 */
	// End offset: 0x800671B8
	// End Line: 5962

	/* begin block 2 */
		// Start line: 12683
	/* end block 2 */
	// End Line: 12684

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
 // line 5965, offset 0x800671e0
	/* begin block 1 */
		// Start line: 5966
		// Start offset: 0x800671E0
		// Variables:
	// 		long value; // $s0
	// 		struct _Instance *instance; // $a0
	/* end block 1 */
	// End offset: 0x80067340
	// End Line: 6100

	/* begin block 2 */
		// Start line: 12744
	/* end block 2 */
	// End Line: 12745

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
    goto switchD_8006721c_caseD_5;
  case 10:
  case 0x34:
    uVar2 = (ulong)((Inst->flags & 0x800U) != 0);
    break;
  case 0xb:
    uVar2 = (ulong)((Inst->flags & 0x800U) == 0);
    break;
  case 0x10:
    Query = 10;
    goto LAB_8006730c;
  case 0x14:
    uVar2 = INSTANCE_Query(Inst,0xb);
    uVar1 = uVar2 >> 1;
    goto LAB_80067250;
  case 0x15:
    uVar1 = INSTANCE_Query(Inst,0xb);
LAB_80067250:
    uVar2 = uVar1 & 1;
    Query = STREAM_IsMorphInProgress();
    if (Query != 0) {
switchD_8006721c_caseD_5:
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
    goto LAB_8006730c;
  case 0x27:
    Query = 0x1a;
LAB_8006730c:
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
 // line 6103, offset 0x80067358
	/* begin block 1 */
		// Start line: 6104
		// Start offset: 0x80067358
	/* end block 1 */
	// End offset: 0x80067358
	// End Line: 6104

	/* begin block 2 */
		// Start line: 13023
	/* end block 2 */
	// End Line: 13024

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
 // line 6116, offset 0x8006739c
	/* begin block 1 */
		// Start line: 6117
		// Start offset: 0x8006739C
		// Variables:
	// 		long value; // $a1
	// 		struct _Instance *instance; // $a0

		/* begin block 1.1 */
			// Start line: 6166
			// Start offset: 0x80067448
			// Variables:
		// 		struct MultiSpline *spline; // $v0
		/* end block 1.1 */
		// End offset: 0x80067488
		// End Line: 6185
	/* end block 1 */
	// End offset: 0x80067488
	// End Line: 6192

	/* begin block 2 */
		// Start line: 13049
	/* end block 2 */
	// End Line: 13050

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
 // line 6196, offset 0x80067498
	/* begin block 1 */
		// Start line: 6198
		// Start offset: 0x80067498
		// Variables:
	// 		long value; // $a1
	// 		long trueValue; // $a2
	// 		struct _Instance *instance; // $a3

		/* begin block 1.1 */
			// Start line: 6226
			// Start offset: 0x80067504
			// Variables:
		// 		struct AniTexInfo *ani_tex_info; // $a0
		/* end block 1.1 */
		// End offset: 0x80067504
		// End Line: 6227
	/* end block 1 */
	// End offset: 0x8006753C
	// End Line: 6245

	/* begin block 2 */
		// Start line: 13212
	/* end block 2 */
	// End Line: 13213

	/* begin block 3 */
		// Start line: 13213
	/* end block 3 */
	// End Line: 13214

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
 // line 6249, offset 0x80067548
	/* begin block 1 */
		// Start line: 6250
		// Start offset: 0x80067548
		// Variables:
	// 		long value; // $a1
	// 		struct _Instance *instance; // $a0
	/* end block 1 */
	// End offset: 0x800675B0
	// End Line: 6289

	/* begin block 2 */
		// Start line: 13321
	/* end block 2 */
	// End Line: 13322

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
    goto LAB_800675a4;
  case 0x1e:
    Query = 0x11;
LAB_800675a4:
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
 // line 6294, offset 0x800675c0
	/* begin block 1 */
		// Start line: 6295
		// Start offset: 0x800675C0
		// Variables:
	// 		long retValue; // $v0
	/* end block 1 */
	// End offset: 0x80067604
	// End Line: 6310

	/* begin block 2 */
		// Start line: 13415
	/* end block 2 */
	// End Line: 13416

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
 // line 6314, offset 0x80067614
	/* begin block 1 */
		// Start line: 6316
		// Start offset: 0x80067614
		// Variables:
	// 		long d; // $t3
	// 		long d2; // $t1
	// 		struct Event *curEvent; // $a3
	/* end block 1 */
	// End offset: 0x800677E8
	// End Line: 6355

	/* begin block 2 */
		// Start line: 13455
	/* end block 2 */
	// End Line: 13456

	/* begin block 3 */
		// Start line: 13456
	/* end block 3 */
	// End Line: 13457

	/* begin block 4 */
		// Start line: 13459
	/* end block 4 */
	// End Line: 13460

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
 // line 6359, offset 0x800677f0
	/* begin block 1 */
		// Start line: 6360
		// Start offset: 0x800677F0
		// Variables:
	// 		struct EventPointers *eventPointers; // $s4
	// 		struct Event *eventInstance; // $s0
	// 		long i; // $s3
	// 		long d; // $a1
	// 		long saveEvent; // $s1

		/* begin block 1.1 */
			// Start line: 6373
			// Start offset: 0x80067830
			// Variables:
		// 		long useBigSave; // $s2

			/* begin block 1.1.1 */
				// Start line: 6399
				// Start offset: 0x8006789C
				// Variables:
			// 		struct SavedEvent *savedEvent; // $v0
			/* end block 1.1.1 */
			// End offset: 0x800678E4
			// End Line: 6409

			/* begin block 1.1.2 */
				// Start line: 6412
				// Start offset: 0x800678EC
				// Variables:
			// 		struct SavedEventSmallVars *savedEvent; // $a2
			/* end block 1.1.2 */
			// End offset: 0x80067934
			// End Line: 6422
		/* end block 1.1 */
		// End offset: 0x80067934
		// End Line: 6424
	/* end block 1 */
	// End offset: 0x80067948
	// End Line: 6426

	/* begin block 2 */
		// Start line: 13580
	/* end block 2 */
	// End Line: 13581

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
 // line 6429, offset 0x8006796c
	/* begin block 1 */
		// Start line: 6430
		// Start offset: 0x8006796C
		// Variables:
	// 		long d; // $v1
	// 		struct EventPointers *eventPointers; // $s0
	// 		struct Event *eventInstance; // $t0
	// 		struct SavedBasic *savedEvent; // $a1

		/* begin block 1.1 */
			// Start line: 6444
			// Start offset: 0x800679B4
			// Variables:
		// 		long eventNumber; // $t1
		/* end block 1.1 */
		// End offset: 0x80067A7C
		// End Line: 6484
	/* end block 1 */
	// End offset: 0x80067A90
	// End Line: 6492

	/* begin block 2 */
		// Start line: 13805
	/* end block 2 */
	// End Line: 13806

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
 // line 6495, offset 0x80067aa8
	/* begin block 1 */
		// Start line: 6496
		// Start offset: 0x80067AA8
		// Variables:
	// 		struct SavedEventSmallVars *savedEvent; // $a1
	// 		long d; // $a0
	/* end block 1 */
	// End offset: 0x80067AFC
	// End Line: 6518

	/* begin block 2 */
		// Start line: 13961
	/* end block 2 */
	// End Line: 13962

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
 // line 6522, offset 0x80067b14
	/* begin block 1 */
		// Start line: 6524
		// Start offset: 0x80067B14
		// Variables:
	// 		int d; // $t3
	// 		int i; // $t0
	// 		int i2; // $a1
	// 		struct EventPointers *puzzle; // $t2
	// 		struct EventBasicObject **basicEventObject; // $v0
	/* end block 1 */
	// End offset: 0x80067BF4
	// End Line: 6555

	/* begin block 2 */
		// Start line: 14026
	/* end block 2 */
	// End Line: 14027

	/* begin block 3 */
		// Start line: 14027
	/* end block 3 */
	// End Line: 14028

	/* begin block 4 */
		// Start line: 14032
	/* end block 4 */
	// End Line: 14033

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
    if (((*(short *)((int)&StreamTracker.StreamList[0].used + iVar2) == 2) &&
        (piVar6 = *(int **)(*(int *)((int)&StreamTracker.StreamList[0].level + iVar2) + 0xdc),
        piVar6 != (int *)0x0)) && (iVar2 = 0, piVar5 = piVar6, 0 < *piVar6)) {
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
 // line 6558, offset 0x80067bfc
	/* begin block 1 */
		// Start line: 6560
		// Start offset: 0x80067BFC
		// Variables:
	// 		int i; // $t2
	// 		int i2; // $t0
	// 		struct EventBasicObject **basicEventObject; // $v0
	/* end block 1 */
	// End offset: 0x80067C98
	// End Line: 6582

	/* begin block 2 */
		// Start line: 14117
	/* end block 2 */
	// End Line: 14118

	/* begin block 3 */
		// Start line: 14118
	/* end block 3 */
	// End Line: 14119

	/* begin block 4 */
		// Start line: 14122
	/* end block 4 */
	// End Line: 14123

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
 // line 6584, offset 0x80067ca0
	/* begin block 1 */
		// Start line: 6585
		// Start offset: 0x80067CA0
		// Variables:
	// 		int d; // $s1
	// 		int curTree; // $a1
	// 		struct EventPointers *puzzle; // $a0
	// 		struct Level *level; // $s0

		/* begin block 1.1 */
			// Start line: 6604
			// Start offset: 0x80067D14
			// Variables:
		// 		struct BSPTree *bspTree; // $a0
		/* end block 1.1 */
		// End offset: 0x80067D48
		// End Line: 6614
	/* end block 1 */
	// End offset: 0x80067D74
	// End Line: 6617

	/* begin block 2 */
		// Start line: 14183
	/* end block 2 */
	// End Line: 14184

void EVENT_AddInstanceToInstanceList(_Instance *instance)

{
  _Terrain *p_Var1;
  int iVar2;
  int iVar3;
  int iVar4;
  Level *pLVar5;
  int iVar6;
  
  iVar6 = 0;
  do {
    if (StreamTracker.StreamList[iVar6].used == 2) {
      pLVar5 = StreamTracker.StreamList[iVar6].level;
      if (pLVar5->PuzzleInstances != (EventPointers *)0x0) {
        EVENT_UpdatePuzzleWithInstance(pLVar5->PuzzleInstances,instance);
      }
      p_Var1 = pLVar5->terrain;
      iVar3 = 0;
      if (0 < p_Var1->numBSPTrees) {
        iVar4 = 0;
        do {
          iVar2 = (int)&p_Var1->BSPTreeArray->bspRoot + iVar4;
          if ((-1 < *(short *)(iVar2 + 0x1a)) && (*(int *)(iVar2 + 0x1c) == instance->introUniqueID)
             ) {
            *(_Instance **)(iVar2 + 0x20) = instance;
          }
          p_Var1 = pLVar5->terrain;
          iVar3 = iVar3 + 1;
          iVar4 = iVar4 + 0x24;
        } while (iVar3 < p_Var1->numBSPTrees);
      }
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// struct _VMObject * /*$ra*/ EVENT_FindVMObject(struct _StreamUnit *stream /*$a0*/, char *vmoName /*$s4*/)
 // line 6619, offset 0x80067d8c
	/* begin block 1 */
		// Start line: 6620
		// Start offset: 0x80067D8C
		// Variables:
	// 		int i; // $s2
	// 		struct _VMObject *vmObject; // $s3
	// 		struct Level *level; // $s1
	/* end block 1 */
	// End offset: 0x80067E08
	// End Line: 6639

	/* begin block 2 */
		// Start line: 14282
	/* end block 2 */
	// End Line: 14283

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
 // line 6642, offset 0x80067e2c
	/* begin block 1 */
		// Start line: 6643
		// Start offset: 0x80067E2C
		// Variables:
	// 		struct EventPointers *puzzle; // $s5
	// 		struct EventBasicObject **basicEventObject; // $s6
	// 		struct _Instance *instance; // $a1
	// 		struct _Instance *next; // $s0
	// 		int i; // $s4
	// 		int i2; // $s2
	// 		int p; // $a2

		/* begin block 1.1 */
			// Start line: 6670
			// Start offset: 0x80067EDC
			// Variables:
		// 		struct _StreamUnit *newStream; // $v0
		/* end block 1.1 */
		// End offset: 0x80067EF0
		// End Line: 6678

		/* begin block 1.2 */
			// Start line: 6685
			// Start offset: 0x80067F00
			// Variables:
		// 		struct EventEventObject *eventEventObject; // $s1
		// 		struct _StreamUnit *newStream; // $v0

			/* begin block 1.2.1 */
				// Start line: 6692
				// Start offset: 0x80067F14
				// Variables:
			// 		struct EventPointers *puzzleInstances; // $v1
			/* end block 1.2.1 */
			// End offset: 0x80067F6C
			// End Line: 6709
		/* end block 1.2 */
		// End offset: 0x80067F6C
		// End Line: 6710

		/* begin block 1.3 */
			// Start line: 6715
			// Start offset: 0x80067F7C
			// Variables:
		// 		struct EventTGroupObject *tgroupEventObject; // $s1
		// 		struct _StreamUnit *newStream; // $v0

			/* begin block 1.3.1 */
				// Start line: 6720
				// Start offset: 0x80067F90
				// Variables:
			// 		struct _Terrain *terrain; // $v0
			/* end block 1.3.1 */
			// End offset: 0x80067FE0
			// End Line: 6742
		/* end block 1.3 */
		// End offset: 0x80067FE0
		// End Line: 6743

		/* begin block 1.4 */
			// Start line: 6748
			// Start offset: 0x80067FF0
			// Variables:
		// 		struct _StreamUnit *newStream; // $v0
		/* end block 1.4 */
		// End offset: 0x80068004
		// End Line: 6756

		/* begin block 1.5 */
			// Start line: 6765
			// Start offset: 0x80068020
			// Variables:
		// 		void *pointer; // $v1

			/* begin block 1.5.1 */
				// Start line: 6775
				// Start offset: 0x8006803C
				// Variables:
			// 		struct _StreamUnit *stream2; // $v0
			/* end block 1.5.1 */
			// End offset: 0x80068064
			// End Line: 6783
		/* end block 1.5 */
		// End offset: 0x80068064
		// End Line: 6783

		/* begin block 1.6 */
			// Start line: 6793
			// Start offset: 0x80068094
			// Variables:
		// 		struct _StreamUnit *newStream; // $v0
		/* end block 1.6 */
		// End offset: 0x800680B4
		// End Line: 6804
	/* end block 1 */
	// End offset: 0x800680E4
	// End Line: 6813

	/* begin block 2 */
		// Start line: 14333
	/* end block 2 */
	// End Line: 14334

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
  instance = (gameTrackerX.instanceList)->first;
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
 // line 6815, offset 0x80068110
	/* begin block 1 */
		// Start line: 6816
		// Start offset: 0x80068110
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
			// Start line: 6853
			// Start offset: 0x800681F8
			// Variables:
		// 		struct EventPointers *puzzleInstances; // $v1
		/* end block 1.1 */
		// End offset: 0x80068250
		// End Line: 6871

		/* begin block 1.2 */
			// Start line: 6878
			// Start offset: 0x80068274
			// Variables:
		// 		struct _Terrain *terrain; // $v0
		/* end block 1.2 */
		// End offset: 0x800682C4
		// End Line: 6902

		/* begin block 1.3 */
			// Start line: 6908
			// Start offset: 0x800682D4
		/* end block 1.3 */
		// End offset: 0x800682E8
		// End Line: 6913

		/* begin block 1.4 */
			// Start line: 6922
			// Start offset: 0x80068304
			// Variables:
		// 		void *pointer; // $v1
		/* end block 1.4 */
		// End offset: 0x80068334
		// End Line: 6936

		/* begin block 1.5 */
			// Start line: 6945
			// Start offset: 0x80068364
		/* end block 1.5 */
		// End offset: 0x80068384
		// End Line: 6954
	/* end block 1 */
	// End offset: 0x800683C4
	// End Line: 6966

	/* begin block 2 */
		// Start line: 14928
	/* end block 2 */
	// End Line: 14929

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
    if (((*(short *)((int)&StreamTracker.StreamList[0].used + iVar9) == 2) &&
        (piVar15 = *(int **)(*(int *)((int)&StreamTracker.StreamList[0].level + iVar9) + 0xdc),
        piVar15 != (int *)0x0)) && (iVar9 = 0, piVar14 = piVar15, 0 < *piVar15)) {
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
 // line 6970, offset 0x800683f8
	/* begin block 1 */
		// Start line: 6971
		// Start offset: 0x800683F8
		// Variables:
	// 		int d; // $t1
	// 		int i; // $s1
	// 		int i2; // $a1
	// 		struct EventPointers *puzzle; // $t0
	// 		struct EventBasicObject **basicEventObject; // $v0

		/* begin block 1.1 */
			// Start line: 7026
			// Start offset: 0x800684E0
		/* end block 1.1 */
		// End offset: 0x800684F4
		// End Line: 7031

		/* begin block 1.2 */
			// Start line: 7038
			// Start offset: 0x80068504
		/* end block 1.2 */
		// End offset: 0x8006851C
		// End Line: 7047
	/* end block 1 */
	// End offset: 0x800685A4
	// End Line: 7068

	/* begin block 2 */
		// Start line: 15460
	/* end block 2 */
	// End Line: 15461

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
    if ((((*(short *)((int)&StreamTracker.StreamList[0].used + iVar3) == 2) &&
         ((_StreamUnit *)((int)&StreamTracker.StreamList[0].StreamUnitID + iVar3) != stream)) &&
        (piVar7 = *(int **)(*(int *)((int)&StreamTracker.StreamList[0].level + iVar3) + 0xdc),
        piVar7 != (int *)0x0)) && (iVar3 = 0, piVar6 = piVar7, 0 < *piVar7)) {
      do {
        ppsVar2 = *(short ***)(piVar6[1] + 0x10);
        iVar5 = 0;
        if (0 < *(short *)(piVar6[1] + 2)) {
          do {
            psVar4 = *ppsVar2;
            sVar1 = *psVar4;
            if ((sVar1 == 5) || (sVar1 == 3)) {
LAB_800684e0:
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
                if (sVar1 == 6) goto LAB_800684e0;
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
      timer = &eventTimerArray;
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
 // line 7072, offset 0x800685bc
	/* begin block 1 */
		// Start line: 7074
		// Start offset: 0x800685BC
		// Variables:
	// 		int d; // $t6
	// 		int i; // $t4
	// 		int i2; // $a3
	// 		struct EventPointers *puzzle; // $t5
	// 		struct EventBasicObject **basicEventObject; // $v0
	// 		long offset; // $t0

		/* begin block 1.1 */
			// Start line: 7094
			// Start offset: 0x80068648
		/* end block 1.1 */
		// End offset: 0x80068648
		// End Line: 7099

		/* begin block 1.2 */
			// Start line: 7106
			// Start offset: 0x80068650
		/* end block 1.2 */
		// End offset: 0x80068650
		// End Line: 7111

		/* begin block 1.3 */
			// Start line: 7118
			// Start offset: 0x80068658
		/* end block 1.3 */
		// End offset: 0x80068680
		// End Line: 7123

		/* begin block 1.4 */
			// Start line: 7130
			// Start offset: 0x80068690
		/* end block 1.4 */
		// End offset: 0x800686B8
		// End Line: 7136

		/* begin block 1.5 */
			// Start line: 7143
			// Start offset: 0x800686C8
		/* end block 1.5 */
		// End offset: 0x800686F4
		// End Line: 7151
	/* end block 1 */
	// End offset: 0x800687B4
	// End Line: 7173

	/* begin block 2 */
		// Start line: 15746
	/* end block 2 */
	// End Line: 15747

	/* begin block 3 */
		// Start line: 15747
	/* end block 3 */
	// End Line: 15748

	/* begin block 4 */
		// Start line: 15752
	/* end block 4 */
	// End Line: 15753

void EVENT_RelocateInstanceList(Level *oldLevel,Level *newLevel,long sizeOfLevel)

{
  short sVar1;
  short **ppsVar2;
  int iVar3;
  ScriptPCode *pSVar4;
  int iVar5;
  Level *pLVar6;
  EventTimer *pEVar7;
  short *psVar8;
  long lVar9;
  int iVar10;
  Event *pEVar11;
  Level *pLVar12;
  Level *pLVar13;
  int *piVar14;
  int *piVar15;
  int iVar16;
  
  pLVar12 = (Level *)((int)newLevel - (int)oldLevel);
  iVar16 = 0;
  pLVar13 = (Level *)((int)&oldLevel->terrain + sizeOfLevel);
  iVar5 = 0;
  do {
    if (((*(short *)((int)&StreamTracker.StreamList[0].used + iVar5) == 2) &&
        (piVar15 = *(int **)(*(int *)((int)&StreamTracker.StreamList[0].level + iVar5) + 0xdc),
        piVar15 != (int *)0x0)) && (iVar5 = 0, piVar14 = piVar15, 0 < *piVar15)) {
      do {
        ppsVar2 = *(short ***)(piVar14[1] + 0x10);
        iVar10 = 0;
        if (0 < *(short *)(piVar14[1] + 2)) {
          do {
            psVar8 = *ppsVar2;
            sVar1 = *psVar8;
            if (((sVar1 == 3) || (sVar1 == 4)) || (sVar1 == 6)) {
              pLVar6 = *(Level **)(psVar8 + 4);
              if ((oldLevel <= pLVar6) && (pLVar6 <= pLVar13)) {
                iVar3 = 0;
                if (pLVar6 != (Level *)0x0) {
                  iVar3 = (int)pLVar6 + (int)pLVar12;
                }
                *(int *)(psVar8 + 4) = iVar3;
              }
            }
            else {
              if (sVar1 == 1) {
                pLVar6 = *(Level **)(psVar8 + 8);
                if ((oldLevel <= pLVar6) && (pLVar6 <= pLVar13)) {
                  iVar3 = 0;
                  if (pLVar6 != (Level *)0x0) {
                    iVar3 = (int)pLVar6 + (int)pLVar12;
                  }
                  *(int *)(psVar8 + 8) = iVar3;
                }
              }
              else {
                if (sVar1 == 7) {
                  pLVar6 = *(Level **)(psVar8 + 10);
                  if ((oldLevel <= pLVar6) && (pLVar6 <= pLVar13)) {
                    iVar3 = 0;
                    if (pLVar6 != (Level *)0x0) {
                      iVar3 = (int)pLVar6 + (int)pLVar12;
                    }
                    *(int *)(psVar8 + 10) = iVar3;
                  }
                }
              }
            }
            iVar10 = iVar10 + 1;
            ppsVar2 = ppsVar2 + 1;
          } while (iVar10 < *(short *)(piVar14[1] + 2));
        }
        iVar5 = iVar5 + 1;
        piVar14 = piVar14 + 1;
      } while (iVar5 < *piVar15);
    }
    iVar16 = iVar16 + 1;
    iVar5 = iVar16 * 0x40;
  } while (iVar16 < 0x10);
  pEVar7 = &eventTimerArray;
  do {
    if (((pEVar7->flags & 1U) != 0) && ((Level *)pEVar7->scriptPos == oldLevel)) {
      lVar9 = 0;
      if (pEVar7->time != 0) {
        lVar9 = (int)&pLVar12->terrain + pEVar7->time;
      }
      pEVar11 = (Event *)0x0;
      pEVar7->time = lVar9;
      if (pEVar7->event != (Event *)0x0) {
        pEVar11 = (Event *)((int)&pLVar12->terrain + (int)pEVar7->event);
      }
      pSVar4 = (ScriptPCode *)0x0;
      pEVar7->event = pEVar11;
      if (pEVar7->actionScript != (ScriptPCode *)0x0) {
        pSVar4 = (ScriptPCode *)((int)&pLVar12->terrain + (int)pEVar7->actionScript);
      }
      pEVar7->actionScript = pSVar4;
      *(Level **)&pEVar7->scriptPos = newLevel;
    }
    pEVar7 = (EventTimer *)&pEVar7->nextEventIndex;
  } while ((int)pEVar7 < -0x7ff2bc38);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_PrintVars()
 // line 7175, offset 0x800687bc
	/* begin block 1 */
		// Start line: 16032
	/* end block 1 */
	// End Line: 16033

	/* begin block 2 */
		// Start line: 16061
	/* end block 2 */
	// End Line: 16062

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_PrintVars(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_ExecuteActionCommand(struct StackType *operand1 /*$s0*/, struct StackType *operand2 /*$a1*/, struct _PCodeStack *stack /*$a2*/, short *codeStream /*$a3*/)
 // line 7209, offset 0x800687c4
	/* begin block 1 */
		// Start line: 7210
		// Start offset: 0x800687C4
		// Variables:
	// 		long error; // stack offset -16
	// 		long value; // $a0
	// 		short flags; // stack offset -12
	/* end block 1 */
	// End offset: 0x8006897C
	// End Line: 7319

	/* begin block 2 */
		// Start line: 16100
	/* end block 2 */
	// End Line: 16101

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
 // line 7322, offset 0x8006898c
	/* begin block 1 */
		// Start line: 7323
		// Start offset: 0x8006898C
		// Variables:
	// 		long value; // $a1
	/* end block 1 */
	// End offset: 0x80068AEC
	// End Line: 7418

	/* begin block 2 */
		// Start line: 16326
	/* end block 2 */
	// End Line: 16327

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
    uVar2 = (uint)((int)*(short *)(*(int *)operand->data + 0x170) + 1U < 3) ^ 1;
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
 // line 7424, offset 0x80068afc
	/* begin block 1 */
		// Start line: 7425
		// Start offset: 0x80068AFC
		// Variables:
	// 		long retValue; // $v0
	/* end block 1 */
	// End offset: 0x80068C94
	// End Line: 7518

	/* begin block 2 */
		// Start line: 16536
	/* end block 2 */
	// End Line: 16537

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





