#include "THISDUST.H"
#include "EVENT.H"


// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_ResetAllOneTimeVariables()
 // line 133, offset 0x800619e4
	/* begin block 1 */
		// Start line: 135
		// Start offset: 0x800619E4
		// Variables:
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x80061A24
	// End Line: 142

	/* begin block 2 */
		// Start line: 266
	/* end block 2 */
	// End Line: 267

	/* begin block 3 */
		// Start line: 267
	/* end block 3 */
	// End Line: 268

	/* begin block 4 */
		// Start line: 270
	/* end block 4 */
	// End Line: 271

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_ResetAllOneTimeVariables(void)

{
  int iVar1;
  _MultiSignal **pp_Var2;
  
  iVar1 = 0;
  if (0 < NumSignalsToReset) {
    pp_Var2 = &ResetSignalArray16;
    do {
      iVar1 = iVar1 + 1;
      (*pp_Var2)->flags = (*pp_Var2)->flags & 0xfffe;
      pp_Var2 = pp_Var2 + 1;
    } while (iVar1 < NumSignalsToReset);
  }
  NumSignalsToReset = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_AddSignalToReset(struct _MultiSignal *mSignal /*$a0*/)
 // line 146, offset 0x80061a30
	/* begin block 1 */
		// Start line: 296
	/* end block 1 */
	// End Line: 297

	/* begin block 2 */
		// Start line: 297
	/* end block 2 */
	// End Line: 298

void EVENT_AddSignalToReset(_MultiSignal *mSignal)

{
  if (NumSignalsToReset < 0x10) {
    (&ResetSignalArray16)[NumSignalsToReset] = mSignal;
    NumSignalsToReset = NumSignalsToReset + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HINT_StartHint(short hintNumber /*$a0*/)
 // line 173, offset 0x80061a64
	/* begin block 1 */
		// Start line: 175
		// Start offset: 0x80061A64
		// Variables:
	// 		int h; // $a1
	/* end block 1 */
	// End offset: 0x80061A8C
	// End Line: 190

	/* begin block 2 */
		// Start line: 350
	/* end block 2 */
	// End Line: 351

	/* begin block 3 */
		// Start line: 351
	/* end block 3 */
	// End Line: 352

	/* begin block 4 */
		// Start line: 358
	/* end block 4 */
	// End Line: 359

void HINT_StartHint(short hintNumber)

{
  gHintSystem.stringNumber = hintNumber + 0x36;
  if (0x34 < (ushort)hintNumber) {
    gHintSystem.stringNumber = 0x6a;
  }
  gHintSystem.flags = 3;
  gHintSystem.hintNumber = hintNumber;
  gHintSystem.fadeTimer = 0x1e000;
  gHintSystem.spawningUnitID = (gameTrackerX.playerInstance)->currentStreamUnitID;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HINT_StopHint()
 // line 196, offset 0x80061ab0
	/* begin block 1 */
		// Start line: 411
	/* end block 1 */
	// End Line: 412

	/* begin block 2 */
		// Start line: 415
	/* end block 2 */
	// End Line: 416

/* WARNING: Unknown calling convention yet parameter storage is locked */

void HINT_StopHint(void)

{
  if (((gHintSystem.flags & 1U) != 0) && ((gHintSystem.flags & 4U) == 0)) {
    if ((gHintSystem.flags & 2U) == 0) {
      gHintSystem.flags = gHintSystem.flags | 4;
      gHintSystem.fadeTimer = 0x1e000;
      return;
    }
    gHintSystem.flags = gHintSystem.flags & 0xfffdU | 4;
    gHintSystem.fadeTimer = 0x1e000 - gHintSystem.fadeTimer;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HINT_KillSpecificHint(short hintNumber /*$a0*/)
 // line 219, offset 0x80061b0c
	/* begin block 1 */
		// Start line: 458
	/* end block 1 */
	// End Line: 459

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
 // line 227, offset 0x80061b3c
	/* begin block 1 */
		// Start line: 474
	/* end block 1 */
	// End Line: 475

	/* begin block 2 */
		// Start line: 475
	/* end block 2 */
	// End Line: 476

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
 // line 239, offset 0x80061b5c
	/* begin block 1 */
		// Start line: 240
		// Start offset: 0x80061B5C
		// Variables:
	// 		int i; // $s1
	// 		struct EventTimer *eventTimer; // $s0

		/* begin block 1.1 */
			// Start line: 297
			// Start offset: 0x80061CCC
			// Variables:
		// 		char string[128]; // stack offset -144
		// 		long y; // $s0
		/* end block 1.1 */
		// End offset: 0x80061E4C
		// End Line: 357
	/* end block 1 */
	// End offset: 0x80061E4C
	// End Line: 358

	/* begin block 2 */
		// Start line: 498
	/* end block 2 */
	// End Line: 499

	/* begin block 3 */
		// Start line: 503
	/* end block 3 */
	// End Line: 504

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_ProcessTimers(void)

{
  bool bVar1;
  long y;
  uint uVar2;
  int iVar3;
  EventTimer *timer;
  int len;
  int iVar4;
  char acStack144 [128];
  
  if ((gameTrackerX.debugFlags2 & 0x100U) != 0) {
    FONT_Print("Number of Active Event Timers %d\n");
  }
  if (numActiveEventTimers != 0) {
    len = 0;
    iVar4 = 0;
    do {
      timer = (EventTimer *)((int)&eventTimerArray.flags + iVar4);
      if ((timer->flags & 1U) != 0) {
        if ((gameTrackerX.debugFlags2 & 0x100U) != 0) {
          FONT_Print("Event timer %d unit %d time left=%d\n");
        }
        uVar2 = timer->flags;
        if ((uint)((int)uVar2 >> 1) < gameTrackerX.idleTime) {
          timer->flags = uVar2 & 1;
        }
        else {
          timer->flags = uVar2 & 1 | (((int)uVar2 >> 1) - gameTrackerX.idleTime) * 2;
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
          y = EVENT_DoAction(*(Event **)((int)&eventTimerArray.time + iVar4),
                             *(ScriptPCode **)((int)&eventTimerArray.event + iVar4),
                             *(short **)((int)&eventTimerArray.actionScript + iVar4));
          if ((y != 0) && (EventCurrentEventIndex != -1)) {
            EVENT_Process(*(Event **)((int)&eventTimerArray.time + iVar4),EventCurrentEventIndex);
          }
        }
      }
      len = len + 1;
      iVar4 = iVar4 + 0x18;
    } while (len < 0x10);
  }
  if ((gHintSystem.flags & 1U) != 0) {
    localstr_get((int)gHintSystem.stringNumber);
    sprintf(acStack144,"%s\n");
    if ((gHintSystem.flags & 2U) == 0) {
      y = 200;
      if ((gHintSystem.flags & 4U) != 0) {
        y = 0xfc - (gHintSystem.fadeTimer * 0x34) / 0x1e000;
      }
    }
    else {
      y = (gHintSystem.fadeTimer * 0x34) / 0x1e000 + 200;
    }
    FONT_FontPrintCentered(acStack144,y);
    FONT_FontPrintCentered("$\n",y);
    len = FONT_GetStringWidth(acStack144);
    DisplayHintBox(len,y);
    if ((gHintSystem.fadeTimer != 0) &&
       (bVar1 = (uint)gHintSystem.fadeTimer <= gameTrackerX.idleTime,
       gHintSystem.fadeTimer = gHintSystem.fadeTimer - gameTrackerX.idleTime, bVar1)) {
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
  }
  return;
}



// decompiled code
// original method signature: 
// struct EventTimer * /*$ra*/ EVENT_GetNextTimer()
 // line 360, offset 0x80061e64
	/* begin block 1 */
		// Start line: 361
		// Start offset: 0x80061E64
		// Variables:
	// 		int i; // $a0

		/* begin block 1.1 */
			// Start line: 366
			// Start offset: 0x80061E78
			// Variables:
		// 		struct EventTimer *eventTimer; // $v1
		/* end block 1.1 */
		// End offset: 0x80061EC8
		// End Line: 378
	/* end block 1 */
	// End offset: 0x80061ECC
	// End Line: 380

	/* begin block 2 */
		// Start line: 789
	/* end block 2 */
	// End Line: 790

	/* begin block 3 */
		// Start line: 792
	/* end block 3 */
	// End Line: 793

/* WARNING: Unknown calling convention yet parameter storage is locked */

EventTimer * EVENT_GetNextTimer(void)

{
  EventTimer *pEVar1;
  int iVar2;
  
  if (numActiveEventTimers < 0x10) {
    pEVar1 = &eventTimerArray;
    iVar2 = 0x10;
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
 // line 382, offset 0x80061ed4
	/* begin block 1 */
		// Start line: 842
	/* end block 1 */
	// End Line: 843

	/* begin block 2 */
		// Start line: 843
	/* end block 2 */
	// End Line: 844

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
 // line 392, offset 0x80061f04
	/* begin block 1 */
		// Start line: 862
	/* end block 1 */
	// End Line: 863

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_InitTimers(void)

{
  numActiveEventTimers = 0;
  memset(&eventTimerArray,0,0x180);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_InitTerrainMovement()
 // line 398, offset 0x80061f34
	/* begin block 1 */
		// Start line: 399
		// Start offset: 0x80061F34
		// Variables:
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x80061F70
	// End Line: 406

	/* begin block 2 */
		// Start line: 876
	/* end block 2 */
	// End Line: 877

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
 // line 409, offset 0x80061f88
	/* begin block 1 */
		// Start line: 907
	/* end block 1 */
	// End Line: 908

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_Init(void)

{
  EVENT_InitTerrainMovement();
  EVENT_InitTimers();
  return;
}



// decompiled code
// original method signature: 
// struct WaterLevelProcess * /*$ra*/ EVENT_GetNextTerrainMove()
 // line 415, offset 0x80061fb0
	/* begin block 1 */
		// Start line: 417
		// Start offset: 0x80061FB0
		// Variables:
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x80061FE4
	// End Line: 431

	/* begin block 2 */
		// Start line: 919
	/* end block 2 */
	// End Line: 920

	/* begin block 3 */
		// Start line: 920
	/* end block 3 */
	// End Line: 921

	/* begin block 4 */
		// Start line: 923
	/* end block 4 */
	// End Line: 924

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
 // line 450, offset 0x80061fec
	/* begin block 1 */
		// Start line: 452
		// Start offset: 0x80061FEC
		// Variables:
	// 		long i; // $a3
	// 		long inUse; // $t0

		/* begin block 1.1 */
			// Start line: 457
			// Start offset: 0x80061FFC
			// Variables:
		// 		struct WaterLevelProcess *curWater; // $a2
		/* end block 1.1 */
		// End offset: 0x80062110
		// End Line: 486
	/* end block 1 */
	// End offset: 0x8006211C
	// End Line: 492

	/* begin block 2 */
		// Start line: 896
	/* end block 2 */
	// End Line: 897

	/* begin block 3 */
		// Start line: 976
	/* end block 3 */
	// End Line: 977

	/* begin block 4 */
		// Start line: 979
	/* end block 4 */
	// End Line: 980

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
        iVar3 = plVar4[1] + gameTrackerX.idleTime;
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
 // line 494, offset 0x80062124
	/* begin block 1 */
		// Start line: 1087
	/* end block 1 */
	// End Line: 1088

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_DoProcess(void)

{
  EVENT_ProcessMovingWater();
  EVENT_ProcessTimers();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_BSPProcess(struct Level *level /*$a0*/)
 // line 500, offset 0x8006214c
	/* begin block 1 */
		// Start line: 502
		// Start offset: 0x8006214C
		// Variables:
	// 		long curTree; // $t3
	// 		struct _Terrain *terrain; // $t2

		/* begin block 1.1 */
			// Start line: 508
			// Start offset: 0x80062168
			// Variables:
		// 		struct BSPTree *bspTree; // $t0

			/* begin block 1.1.1 */
				// Start line: 516
				// Start offset: 0x80062184
				// Variables:
			// 		struct _Instance *instance; // $a2

				/* begin block 1.1.1.1 */
					// Start line: 520
					// Start offset: 0x80062194
					// Variables:
				// 		short dx; // $t1
				// 		short dy; // $a1
				// 		short dz; // $a0
				/* end block 1.1.1.1 */
				// End offset: 0x80062270
				// End Line: 545
			/* end block 1.1.1 */
			// End offset: 0x80062270
			// End Line: 546
		/* end block 1.1 */
		// End offset: 0x80062270
		// End Line: 547
	/* end block 1 */
	// End offset: 0x80062284
	// End Line: 549

	/* begin block 2 */
		// Start line: 1099
	/* end block 2 */
	// End Line: 1100

	/* begin block 3 */
		// Start line: 1100
	/* end block 3 */
	// End Line: 1101

	/* begin block 4 */
		// Start line: 1103
	/* end block 4 */
	// End Line: 1104

void EVENT_BSPProcess(Level *level)

{
  short sVar1;
  short sVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  _Terrain *p_Var9;
  int iVar10;
  int iVar11;
  
  p_Var9 = level->terrain;
  iVar10 = 0;
  if (0 < (int)p_Var9->morphNormalIdx) {
    iVar11 = 0;
    do {
      iVar7 = (int)&p_Var9->signals->numSignals + iVar11;
      if ((-1 < *(short *)(iVar7 + 0x1a)) && (iVar5 = *(int *)(iVar7 + 0x20), iVar5 != 0)) {
        iVar3 = *(int *)(iVar5 + 0x40);
        if ((iVar3 == 0) || (iVar6 = *(int *)(iVar5 + 0x44), iVar6 == 0)) {
          sVar2 = *(short *)(iVar5 + 0x60);
          sVar8 = *(short *)(iVar5 + 0x5c) - *(short *)(iVar5 + 100);
          sVar1 = *(short *)(iVar5 + 0x68);
          sVar4 = *(short *)(iVar5 + 0x5e) - *(short *)(iVar5 + 0x66);
        }
        else {
          sVar2 = *(short *)(iVar3 + 0x1c);
          sVar8 = *(short *)(iVar3 + 0x14) - *(short *)(iVar6 + 0x14);
          sVar1 = *(short *)(iVar6 + 0x1c);
          sVar4 = *(short *)(iVar3 + 0x18) - *(short *)(iVar6 + 0x18);
        }
        sVar2 = sVar2 - sVar1;
        if (((sVar8 != 0) || (sVar4 != 0)) || (sVar2 != 0)) {
          *(short *)(iVar7 + 0xc) = *(short *)(iVar7 + 0xc) + sVar8;
          *(short *)(iVar7 + 0xe) = *(short *)(iVar7 + 0xe) + sVar4;
          *(short *)(iVar7 + 0x10) = *(short *)(iVar7 + 0x10) + sVar2;
          *(short *)(iVar7 + 0x14) = *(short *)(iVar7 + 0x14) + sVar8;
          *(short *)(iVar7 + 0x16) = *(short *)(iVar7 + 0x16) + sVar4;
          *(short *)(iVar7 + 0x18) = *(short *)(iVar7 + 0x18) + sVar2;
          p_Var9->UnitChangeFlags = p_Var9->UnitChangeFlags | 2;
        }
      }
      iVar10 = iVar10 + 1;
      iVar11 = iVar11 + 0x24;
    } while (iVar10 < (int)p_Var9->morphNormalIdx);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_Process(struct Event *eventInstance /*$s2*/, long startIndex /*$a1*/)
 // line 551, offset 0x8006228c
	/* begin block 1 */
		// Start line: 552
		// Start offset: 0x8006228C
		// Variables:
	// 		long i; // $s0
	// 		long savei; // $a1
	/* end block 1 */
	// End offset: 0x80062448
	// End Line: 602

	/* begin block 2 */
		// Start line: 1253
	/* end block 2 */
	// End Line: 1254

void EVENT_Process(Event *eventInstance,long startIndex)

{
  long lVar1;
  ScriptPCode **ppSVar2;
  char *fmt;
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
        if ((*(ushort *)(*(int *)(iVar3 + (int)eventInstance->actionList) + 2) & 2) == 0) {
          if ((gameTrackerX.debugFlags2 & 0x100U) != 0) {
            fmt = "NULL Condition(%d) is satisfied for event %d. do Action!!!!!!!\n";
LAB_80062408:
            FONT_Print(fmt);
          }
LAB_80062410:
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
              if ((int)(uint)eventInstance->numActions <= startIndex) goto LAB_80062434;
              iVar3 = iVar3 + 4;
              startIndex = startIndex + 1;
            } while (*ppSVar2 == (ScriptPCode *)0x0);
          }
          if ((startIndex < (int)(uint)eventInstance->numActions) &&
             ((*(ushort *)(*(int *)(iVar3 + (int)eventInstance->actionList) + 2) & 2) == 0)) {
            if ((gameTrackerX.debugFlags2 & 0x100U) != 0) {
              fmt = "Condition(%d) is satisfied for event %d. do Action!!!!!!!\n";
              goto LAB_80062408;
            }
            goto LAB_80062410;
          }
        }
      }
LAB_80062434:
      startIndex = startIndex + 1;
      iVar3 = iVar3 + 4;
    } while (startIndex < (int)(uint)eventInstance->numActions);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_ProcessPuppetShow(struct Event *eventInstance /*$s1*/, long startIndex /*$a1*/)
 // line 604, offset 0x80062460
	/* begin block 1 */
		// Start line: 605
		// Start offset: 0x80062460
		// Variables:
	// 		long i; // $s0
	// 		long savei; // $a1
	// 		long conditionIsStatisfied; // $s3
	/* end block 1 */
	// End offset: 0x80062660
	// End Line: 668

	/* begin block 2 */
		// Start line: 1402
	/* end block 2 */
	// End Line: 1403

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
    if ((eventInstance->actionList[startIndex]->conditionBits & 2) != 0) goto LAB_80062614;
    if ((gameTrackerX.debugFlags2 & 0x100U) != 0) {
      FONT_Print("Condition(%d) is satisfied for event %d. do Action!!!!!!!\n");
    }
    actionScript = eventInstance->actionList[startIndex];
  }
  else {
    EventAbortLine = 0;
    CurrentEventLine = 0;
    lVar2 = EVENT_IsConditionTrue(eventInstance,eventInstance->conditionalList[startIndex]);
    if (lVar2 == 0) {
      bVar1 = false;
      goto LAB_80062614;
    }
    ppSVar3 = eventInstance->actionList + startIndex;
    if (*ppSVar3 == (ScriptPCode *)0x0) {
      do {
        cVar4 = (char)startIndex;
        ppSVar3 = ppSVar3 + 1;
        if ((int)(uint)eventInstance->numActions <= startIndex) goto LAB_80062614;
        startIndex = startIndex + 1;
      } while (*ppSVar3 == (ScriptPCode *)0x0);
    }
    cVar4 = (char)startIndex;
    if ((int)(uint)eventInstance->numActions <= startIndex) goto LAB_80062614;
    if ((gameTrackerX.debugFlags2 & 0x100U) != 0) {
      FONT_Print("Condition(%d) is satisfied for event %d. do Action!!!!!!!\n");
    }
    actionScript = eventInstance->actionList[startIndex];
  }
  EventAbortLine = 0;
  EVENT_DoAction(eventInstance,actionScript,actionScript->data);
LAB_80062614:
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
 // line 670, offset 0x8006267c
	/* begin block 1 */
		// Start line: 671
		// Start offset: 0x8006267C
		// Variables:
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x80062704
	// End Line: 692

	/* begin block 2 */
		// Start line: 1545
	/* end block 2 */
	// End Line: 1546

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
 // line 694, offset 0x8006271c
	/* begin block 1 */
		// Start line: 695
		// Start offset: 0x8006271C
		// Variables:
	// 		long retValue; // $s3
	// 		long operateOnStack; // stack offset -32
	// 		struct _PCodeStack stack; // stack offset -1192

		/* begin block 1.1 */
			// Start line: 711
			// Start offset: 0x800627B0
			// Variables:
		// 		struct EventTimer *timer; // $a1
		/* end block 1.1 */
		// End offset: 0x80062800
		// End Line: 731
	/* end block 1 */
	// End offset: 0x80062870
	// End Line: 744

	/* begin block 2 */
		// Start line: 1605
	/* end block 2 */
	// End Line: 1606

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
 // line 748, offset 0x80062894
	/* begin block 1 */
		// Start line: 749
		// Start offset: 0x80062894
		// Variables:
	// 		long retValue; // $s0
	// 		long error; // stack offset -28
	// 		long operateOnStack; // stack offset -32
	// 		short flags; // stack offset -24
	// 		struct _PCodeStack stack; // stack offset -1192
	// 		short *scriptData; // $s1
	/* end block 1 */
	// End offset: 0x8006296C
	// End Line: 804

	/* begin block 2 */
		// Start line: 1731
	/* end block 2 */
	// End Line: 1732

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
        if ((codeStream == (short *)0x0) || (EventAbortLine != 0)) goto LAB_80062958;
        codeStream = EVENT_ParseOpcode(&local_4a8,codeStream,&local_20);
      } while ((local_20 == 0) || (EventAbortLine != 0));
      CurrentEventLine = CurrentEventLine + 1;
      iVar1 = local_4a8.topOfStack + -1;
    } while (local_4a8.topOfStack < 1);
    local_4a8.topOfStack = iVar1;
    lVar2 = EVENT_GetScalerValueFromOperand(local_4a8.stack + iVar1,&local_1c,asStack24);
    if (local_1c != 0) break;
    if (lVar2 == 0) {
LAB_80062958:
      if (EventAbortLine == 1) {
        lVar2 = 0;
      }
      return lVar2;
    }
  }
  lVar2 = 0;
  goto LAB_80062958;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_WriteEventObject(struct StackType *stackEntry /*$s0*/, long areaID /*$s1*/, struct Event *event /*$a2*/, long number /*$s2*/)
 // line 807, offset 0x80062984
	/* begin block 1 */
		// Start line: 808
		// Start offset: 0x80062984
		// Variables:
	// 		long retValue; // $a0
	// 		struct SavedEvent *savedEvent; // $v1
	/* end block 1 */
	// End offset: 0x80062A18
	// End Line: 849

	/* begin block 2 */
		// Start line: 1870
	/* end block 2 */
	// End Line: 1871

long EVENT_WriteEventObject(StackType *stackEntry,long areaID,Event *event,long number)

{
  SavedEvent *pSVar1;
  long lVar2;
  
  lVar2 = 0;
  if (event == (Event *)0x0) {
    pSVar1 = SAVE_GetSavedEvent(areaID,number);
    if (pSVar1 == (SavedEvent *)0x0) {
      stackEntry->id = 0x15;
      pSVar1 = EVENT_CreateSaveEvent(areaID,number);
      *(SavedEvent **)stackEntry->data = pSVar1;
    }
    else {
      stackEntry->id = 0x15;
      *(SavedEvent **)stackEntry->data = pSVar1;
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
 // line 852, offset 0x80062a34
	/* begin block 1 */
		// Start line: 853
		// Start offset: 0x80062A34
		// Variables:
	// 		struct _MultiSignal *retValue; // $a2
	// 		struct Level *level; // $a0
	/* end block 1 */
	// End offset: 0x80062ABC
	// End Line: 908

	/* begin block 2 */
		// Start line: 1969
	/* end block 2 */
	// End Line: 1970

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
 // line 911, offset 0x80062acc
	/* begin block 1 */
		// Start line: 912
		// Start offset: 0x80062ACC
	/* end block 1 */
	// End offset: 0x80062ACC
	// End Line: 912

	/* begin block 2 */
		// Start line: 2088
	/* end block 2 */
	// End Line: 2089

Intro * EVENT_ResolveObjectIntro(EventInstanceObject *instanceObject)

{
  Intro *pIVar1;
  
  pIVar1 = INSTANCE_FindIntro(instanceObject->unitID,instanceObject->introUniqueID);
  return pIVar1;
}



// decompiled code
// original method signature: 
// struct _SFXMkr * /*$ra*/ EVENT_ResolveSFXMarker(struct _StreamUnit *stream /*$a0*/, struct EventInstanceObject *instanceObject /*$a1*/)
 // line 922, offset 0x80062af8
	/* begin block 1 */
		// Start line: 924
		// Start offset: 0x80062AF8
		// Variables:
	// 		int i; // $a0
	// 		struct Level *level; // $t0
	// 		struct _SFXMkr *result; // $a2
	/* end block 1 */
	// End offset: 0x80062B50
	// End Line: 942

	/* begin block 2 */
		// Start line: 2110
	/* end block 2 */
	// End Line: 2111

	/* begin block 3 */
		// Start line: 2111
	/* end block 3 */
	// End Line: 2112

	/* begin block 4 */
		// Start line: 2115
	/* end block 4 */
	// End Line: 2116

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
 // line 945, offset 0x80062b58
	/* begin block 1 */
		// Start line: 947
		// Start offset: 0x80062B58

		/* begin block 1.1 */
			// Start line: 949
			// Start offset: 0x80062B6C
			// Variables:
		// 		struct StackType *stackEntry; // $v0
		/* end block 1.1 */
		// End offset: 0x80062B9C
		// End Line: 953
	/* end block 1 */
	// End offset: 0x80062B9C
	// End Line: 959

	/* begin block 2 */
		// Start line: 2166
	/* end block 2 */
	// End Line: 2167

	/* begin block 3 */
		// Start line: 2167
	/* end block 3 */
	// End Line: 2168

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
 // line 961, offset 0x80062ba4
	/* begin block 1 */
		// Start line: 962
		// Start offset: 0x80062BA4

		/* begin block 1.1 */
			// Start line: 965
			// Start offset: 0x80062BBC
			// Variables:
		// 		struct StackType *stackEntry; // $v0
		/* end block 1.1 */
		// End offset: 0x80062BF4
		// End Line: 970
	/* end block 1 */
	// End offset: 0x80062BF4
	// End Line: 976

	/* begin block 2 */
		// Start line: 2198
	/* end block 2 */
	// End Line: 2199

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
// void /*$ra*/ EVENT_AddObjectToStack(struct _PCodeStack *stack /*$s3*/, long item /*$s2*/)
 // line 978, offset 0x80062bfc
	/* begin block 1 */
		// Start line: 979
		// Start offset: 0x80062BFC
		// Variables:
	// 		struct EventBasicObject *basicObject; // $a3
	// 		int topOfStack; // $s1

		/* begin block 1.1 */
			// Start line: 991
			// Start offset: 0x80062C2C
			// Variables:
		// 		struct StackType *stackEntry; // $s0

			/* begin block 1.1.1 */
				// Start line: 997
				// Start offset: 0x80062C8C
			/* end block 1.1.1 */
			// End offset: 0x80062CD0
			// End Line: 1013

			/* begin block 1.1.2 */
				// Start line: 1021
				// Start offset: 0x80062CD8
			/* end block 1.1.2 */
			// End offset: 0x80062D30
			// End Line: 1038

			/* begin block 1.1.3 */
				// Start line: 1053
				// Start offset: 0x80062D54
			/* end block 1.1.3 */
			// End offset: 0x80062D54
			// End Line: 1055

			/* begin block 1.1.4 */
				// Start line: 1063
				// Start offset: 0x80062D70
			/* end block 1.1.4 */
			// End offset: 0x80062D70
			// End Line: 1065

			/* begin block 1.1.5 */
				// Start line: 1073
				// Start offset: 0x80062D94
			/* end block 1.1.5 */
			// End offset: 0x80062E20
			// End Line: 1123

			/* begin block 1.1.6 */
				// Start line: 1135
				// Start offset: 0x80062E20
			/* end block 1.1.6 */
			// End offset: 0x80062E90
			// End Line: 1157
		/* end block 1.1 */
		// End offset: 0x80062E94
		// End Line: 1165
	/* end block 1 */
	// End offset: 0x80062E94
	// End Line: 1171

	/* begin block 2 */
		// Start line: 2233
	/* end block 2 */
	// End Line: 2234

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
  if (0x1f < lVar5) goto LAB_80062e94;
  pEVar4 = currentEventInstance->instanceList[item];
  stackEntry = stack->stack + lVar5;
  switch((int)(((uint)(ushort)pEVar4->id - 1) * 0x10000) >> 0x10) {
  case 0:
    if ((pEVar4[1].id & 1U) == 0) {
      if (*(int *)(pEVar4 + 6) == 0) {
        if (*(int *)(pEVar4 + 8) == 0) goto LAB_80062e80;
        stackEntry->id = 4;
        uVar3 = *(undefined4 *)(pEVar4 + 8);
      }
      else {
        stackEntry->id = 2;
        uVar3 = *(undefined4 *)(pEVar4 + 6);
      }
LAB_80062e14:
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
    goto LAB_80062e94;
  case 3:
    if (*(int *)(pEVar4 + 4) == 0) {
      if ((gameTrackerX.debugFlags2 & 0x100U) != 0) {
        FONT_Print("Could not resolve tgroup area %d, tgroup number %d\n");
      }
      goto LAB_80062e80;
    }
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
      goto LAB_80062e14;
    }
    if ((gameTrackerX.debugFlags2 & 0x100U) != 0) {
      FONT_Print("Could not resolve signal %d:signal%d\n");
    }
    goto LAB_80062e80;
  case 6:
    if (*(int *)(pEVar4 + 10) != 0) {
      stackEntry->id = 0x1a;
      *(undefined4 *)stackEntry->data = *(undefined4 *)(pEVar4 + 10);
      lVar5 = lVar5 + 1;
      pLVar2 = STREAM_GetLevelWithID(*(long *)(pEVar4 + 2));
      *(Level **)(stackEntry->data + 4) = pLVar2;
      *(undefined4 *)(stackEntry->data + 8) = 0xffffffff;
      goto LAB_80062e94;
    }
    if ((gameTrackerX.debugFlags2 & 0x100U) != 0) {
      FONT_Print("Could not find VMO object %s\n");
    }
LAB_80062e80:
    stackEntry->id = 6;
    *(long *)stackEntry->data = item;
    *(undefined4 *)(stackEntry->data + 4) = 0xffffffff;
  }
  lVar5 = lVar5 + 1;
LAB_80062e94:
  stack->topOfStack = lVar5;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_AddShortPointerToStack(struct _PCodeStack *stack /*$a0*/, short *pointer /*$a1*/)
 // line 1178, offset 0x80062eb4
	/* begin block 1 */
		// Start line: 1180
		// Start offset: 0x80062EB4

		/* begin block 1.1 */
			// Start line: 1182
			// Start offset: 0x80062EC8
			// Variables:
		// 		struct StackType *stackEntry; // $v0
		/* end block 1.1 */
		// End offset: 0x80062EF4
		// End Line: 1186
	/* end block 1 */
	// End offset: 0x80062EF4
	// End Line: 1192

	/* begin block 2 */
		// Start line: 2650
	/* end block 2 */
	// End Line: 2651

	/* begin block 3 */
		// Start line: 2651
	/* end block 3 */
	// End Line: 2652

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
 // line 1194, offset 0x80062efc
	/* begin block 1 */
		// Start line: 1196
		// Start offset: 0x80062EFC

		/* begin block 1.1 */
			// Start line: 1198
			// Start offset: 0x80062F10
			// Variables:
		// 		struct StackType *stackEntry; // $v0
		/* end block 1.1 */
		// End offset: 0x80062F44
		// End Line: 1204
	/* end block 1 */
	// End offset: 0x80062F44
	// End Line: 1210

	/* begin block 2 */
		// Start line: 2682
	/* end block 2 */
	// End Line: 2683

	/* begin block 3 */
		// Start line: 2683
	/* end block 3 */
	// End Line: 2684

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
 // line 1212, offset 0x80062f4c
	/* begin block 1 */
		// Start line: 2718
	/* end block 1 */
	// End Line: 2719

	/* begin block 2 */
		// Start line: 2719
	/* end block 2 */
	// End Line: 2720

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
// void /*$ra*/ EVENT_ChangeOperandVector3d(struct StackType *operand /*$a0*/, short x /*$a1*/, short y /*$a2*/, short z /*$a3*/)
 // line 1220, offset 0x80062f64
	/* begin block 1 */
		// Start line: 2734
	/* end block 1 */
	// End Line: 2735

	/* begin block 2 */
		// Start line: 2735
	/* end block 2 */
	// End Line: 2736

void EVENT_ChangeOperandVector3d(StackType *operand,short x,short y,short z)

{
  operand->id = 9;
  *(short *)operand->data = x;
  *(short *)(operand->data + 2) = y;
  *(short *)(operand->data + 4) = z;
  *(undefined2 *)(operand->data + 8) = 0xa0;
  *(undefined2 *)(operand->data + 10) = 0xa0;
  *(undefined2 *)(operand->data + 0xc) = 0xa0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_Addvector3dToStack(struct _PCodeStack *stack /*$s0*/, short x /*$a1*/, short y /*$a2*/, short z /*$a3*/)
 // line 1231, offset 0x80062f8c
	/* begin block 1 */
		// Start line: 2759
	/* end block 1 */
	// End Line: 2760

void EVENT_Addvector3dToStack(_PCodeStack *stack,short x,short y,short z)

{
  if (stack->topOfStack < 0x20) {
    EVENT_ChangeOperandVector3d(stack->stack + stack->topOfStack,x,y,z);
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_ChangeOperandRotation3d(struct StackType *operand /*$a0*/, struct Rotation3d *rotation /*$a1*/)
 // line 1246, offset 0x80062ffc
	/* begin block 1 */
		// Start line: 2789
	/* end block 1 */
	// End Line: 2790

	/* begin block 2 */
		// Start line: 2790
	/* end block 2 */
	// End Line: 2791

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
 // line 1272, offset 0x80063054
	/* begin block 1 */
		// Start line: 1274
		// Start offset: 0x80063054

		/* begin block 1.1 */
			// Start line: 1281
			// Start offset: 0x80063068
			// Variables:
		// 		struct StackType *stackEntry; // $a3
		/* end block 1.1 */
		// End offset: 0x800630E0
		// End Line: 1295
	/* end block 1 */
	// End offset: 0x800630E0
	// End Line: 1301

	/* begin block 2 */
		// Start line: 2540
	/* end block 2 */
	// End Line: 2541

	/* begin block 3 */
		// Start line: 2824
	/* end block 3 */
	// End Line: 2825

	/* begin block 4 */
		// Start line: 2829
	/* end block 4 */
	// End Line: 2830

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
 // line 1351, offset 0x800630e8
	/* begin block 1 */
		// Start line: 2698
	/* end block 1 */
	// End Line: 2699

	/* begin block 2 */
		// Start line: 2933
	/* end block 2 */
	// End Line: 2934

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
 // line 1373, offset 0x80063180
	/* begin block 1 */
		// Start line: 1375
		// Start offset: 0x80063180
		// Variables:
	// 		long retValue; // $a0
	/* end block 1 */
	// End offset: 0x80063208
	// End Line: 1420

	/* begin block 2 */
		// Start line: 2976
	/* end block 2 */
	// End Line: 2977

	/* begin block 3 */
		// Start line: 2977
	/* end block 3 */
	// End Line: 2978

	/* begin block 4 */
		// Start line: 2978
	/* end block 4 */
	// End Line: 2979

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
      goto switchD_800631bc_caseD_5;
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
switchD_800631bc_caseD_5:
  return lVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformConstrictAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a0*/, long item /*$a2*/)
 // line 1423, offset 0x80063210
	/* begin block 1 */
		// Start line: 1424
		// Start offset: 0x80063210
		// Variables:
	// 		long retValue; // $v1
	// 		struct _Instance *instance; // $a1

		/* begin block 1.1 */
			// Start line: 1434
			// Start offset: 0x80063240
		/* end block 1.1 */
		// End offset: 0x80063240
		// End Line: 1437

		/* begin block 1.2 */
			// Start line: 1448
			// Start offset: 0x80063250
		/* end block 1.2 */
		// End offset: 0x8006326C
		// End Line: 1457
	/* end block 1 */
	// End offset: 0x8006326C
	// End Line: 1469

	/* begin block 2 */
		// Start line: 3076
	/* end block 2 */
	// End Line: 3077

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
 // line 1475, offset 0x8006327c
	/* begin block 1 */
		// Start line: 1476
		// Start offset: 0x8006327C
		// Variables:
	// 		long retValue; // $a0
	// 		long x; // $a1
	// 		long y; // $a2
	// 		long z; // $a3
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 1487
			// Start offset: 0x800632C4
			// Variables:
		// 		struct evPositionData *position; // $v0
		/* end block 1.1 */
		// End offset: 0x800632F8
		// End Line: 1502

		/* begin block 1.2 */
			// Start line: 1508
			// Start offset: 0x80063308
			// Variables:
		// 		struct evPositionData *rotation; // $v1
		// 		struct Rotation3d vector; // stack offset -40
		/* end block 1.2 */
		// End offset: 0x80063368
		// End Line: 1527

		/* begin block 1.3 */
			// Start line: 1555
			// Start offset: 0x800633C0
		/* end block 1.3 */
		// End offset: 0x800633EC
		// End Line: 1569

		/* begin block 1.4 */
			// Start line: 1600
			// Start offset: 0x80063428
		/* end block 1.4 */
		// End offset: 0x80063428
		// End Line: 1602

		/* begin block 1.5 */
			// Start line: 1613
			// Start offset: 0x8006344C
		/* end block 1.5 */
		// End offset: 0x8006344C
		// End Line: 1613

		/* begin block 1.6 */
			// Start line: 1620
			// Start offset: 0x80063470
			// Variables:
		// 		struct _Instance *tmpI; // $s0
		// 		long value; // $a1

			/* begin block 1.6.1 */
				// Start line: 1632
				// Start offset: 0x800634A4
			/* end block 1.6.1 */
			// End offset: 0x800634C0
			// End Line: 1641
		/* end block 1.6 */
		// End offset: 0x800634C4
		// End Line: 1647

		/* begin block 1.7 */
			// Start line: 1653
			// Start offset: 0x800634D8
		/* end block 1.7 */
		// End offset: 0x800634D8
		// End Line: 1655

		/* begin block 1.8 */
			// Start line: 1664
			// Start offset: 0x80063500
		/* end block 1.8 */
		// End offset: 0x80063500
		// End Line: 1666

		/* begin block 1.9 */
			// Start line: 1693
			// Start offset: 0x80063528
		/* end block 1.9 */
		// End offset: 0x80063528
		// End Line: 1695

		/* begin block 1.10 */
			// Start line: 1703
			// Start offset: 0x8006354C
		/* end block 1.10 */
		// End offset: 0x8006354C
		// End Line: 1706

		/* begin block 1.11 */
			// Start line: 1758
			// Start offset: 0x80063664
			// Variables:
		// 		long value; // $a1
		/* end block 1.11 */
		// End offset: 0x80063688
		// End Line: 1765

		/* begin block 1.12 */
			// Start line: 1771
			// Start offset: 0x8006369C
			// Variables:
		// 		long value; // $a1
		/* end block 1.12 */
		// End offset: 0x800636C0
		// End Line: 1778

		/* begin block 1.13 */
			// Start line: 1784
			// Start offset: 0x800636D4
			// Variables:
		// 		long value; // $a1
		/* end block 1.13 */
		// End offset: 0x800636F8
		// End Line: 1792

		/* begin block 1.14 */
			// Start line: 1798
			// Start offset: 0x8006370C
			// Variables:
		// 		long value; // $a1
		/* end block 1.14 */
		// End offset: 0x80063730
		// End Line: 1806

		/* begin block 1.15 */
			// Start line: 1812
			// Start offset: 0x80063744
			// Variables:
		// 		long value; // $a1
		/* end block 1.15 */
		// End offset: 0x8006376C
		// End Line: 1820
	/* end block 1 */
	// End offset: 0x800637B0
	// End Line: 1889

	/* begin block 2 */
		// Start line: 3187
	/* end block 2 */
	// End Line: 3188

long EVENT_TransformInstanceAttribute
               (_PCodeStack *stack,StackType *stackObject,long item,short *codeStream)

{
  bool bVar1;
  short *psVar2;
  MultiSpline *pMVar3;
  ulong item_00;
  long lVar4;
  AniTex *pAVar5;
  uint uVar6;
  long item_01;
  short x;
  int item_02;
  short y;
  short z;
  _Instance *Inst;
  Rotation3d local_28;
  
  Inst = *(_Instance **)stackObject->data;
  item_01 = 0;
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
    *(long *)(stackObject->data + 4) = item;
    item_01 = 1;
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
    EVENT_ChangeOperandVector3d(stackObject,x,y,z);
    item_01 = 1;
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
    item_01 = 1;
    break;
  case 0xc:
    stackObject->id = 0xf;
    *(_Instance **)stackObject->data = Inst;
    pMVar3 = SCRIPT_GetMultiSpline
                       (Inst,(ulong *)(stackObject->data + 0xc),(ulong *)(stackObject->data + 0x10))
    ;
    item_01 = 1;
    *(MultiSpline **)(stackObject->data + 4) = pMVar3;
    *(undefined4 *)(stackObject->data + 0x14) = 0;
    *(undefined4 *)(stackObject->data + 8) = 0xffffffff;
    break;
  case 0x12:
    item_00 = INSTANCE_Query(Inst,9);
    EVENT_ChangeOperandToNumber(stackObject,item_00,1);
    item_01 = 1;
    break;
  case 0x13:
    item_00 = INSTANCE_Query(Inst,10);
    EVENT_ChangeOperandToNumber(stackObject,item_00,3);
    item_01 = 1;
    break;
  case 0x1d:
    lVar4 = 0x13;
    if (Inst->object->animList == (_G2AnimKeylist_Type **)0x0) {
      return 0;
    }
    goto LAB_80063650;
  case 0x21:
    stackObject->id = 0x14;
    *(_Instance **)stackObject->data = Inst;
    item_01 = 1;
    pAVar5 = Inst->object->modelList[Inst->currentModel]->aniTextures;
    *(undefined4 *)(stackObject->data + 8) = 0xffffffff;
    *(AniTex **)(stackObject->data + 4) = pAVar5;
    break;
  case 0x2b:
    if (Inst->tface == (_TFace *)0x0) {
      item_02 = Inst->attachedID;
    }
    else {
      item_02 = -Inst->bspTree;
    }
    EVENT_ChangeOperandToNumber(stackObject,item_02,0);
    item_01 = 1;
    break;
  case 0x38:
    item_00 = INSTANCE_Query(Inst,0x1e);
    EVENT_ChangeOperandToNumber(stackObject,item_00,0);
    item_01 = 1;
    break;
  case 0x39:
    lVar4 = 0x18;
LAB_80063650:
    item_01 = 1;
    stackObject->id = lVar4;
    *(_Instance **)stackObject->data = Inst;
    *(undefined4 *)(stackObject->data + 4) = 0xffffffff;
    break;
  case 0x3c:
    bVar1 = (Inst->flags & 4U) != 0;
    if (bVar1) {
      Inst->flags = Inst->flags & 0xfffffffb;
    }
    EVENT_ChangeOperandToNumber(stackObject,(uint)bVar1,0);
    item_01 = 1;
    break;
  case 0x3f:
    EVENT_ChangeOperandToNumber(stackObject,1,0);
    item_01 = 1;
    break;
  case 0x6a:
    uVar6 = Inst->flags;
    if ((int)uVar6 < 0) {
      Inst->flags = uVar6 & 0x7fffffff;
    }
    EVENT_ChangeOperandToNumber(stackObject,(uint)((int)uVar6 < 0),0);
    item_01 = 1;
    break;
  case 0x79:
    bVar1 = (Inst->flags & 8U) != 0;
    if (bVar1) {
      Inst->flags = Inst->flags & 0xfffffff7;
    }
    EVENT_ChangeOperandToNumber(stackObject,(uint)bVar1,0);
    item_01 = 1;
    break;
  case 0x7a:
    bVar1 = (Inst->flags & 0x10U) != 0;
    if (bVar1) {
      Inst->flags = Inst->flags & 0xffffffef;
    }
    EVENT_ChangeOperandToNumber(stackObject,(uint)bVar1,0);
    item_01 = 1;
    break;
  case 0x7d:
    bVar1 = (Inst->flags2 & 0x10000U) != 0;
    if (bVar1) {
      Inst->flags2 = Inst->flags2 & 0xfffeffff;
    }
    EVENT_ChangeOperandToNumber(stackObject,(uint)bVar1,0);
    item_01 = 1;
    break;
  case 0x7e:
    stackObject->id = 0x1b;
    *(_Instance **)(stackObject->data + 0x10) = Inst;
    *(undefined2 *)(stackObject->data + 2) = 0xffff;
    if (codeStream != (short *)0x0) {
      MoveCodeStreamExtra = 1;
      *(int *)(stackObject->data + 4) = (int)codeStream[1];
    }
    SOUND_IsInstanceSoundLoaded(Inst->object->soundData,*(long *)(stackObject->data + 4));
    item_01 = 1;
    break;
  case 0x89:
    item_00 = INSTANCE_Query(Inst,2);
    EVENT_ChangeOperandToNumber(stackObject,item_00,3);
    item_01 = 1;
    break;
  case 0x8b:
    item_00 = INSTANCE_Query(Inst,0);
    EVENT_ChangeOperandToNumber(stackObject,item_00 >> 0x1e & 1,0);
    item_01 = 1;
    break;
  case 0x92:
    EVENT_ChangeOperandToNumber(stackObject,0,0);
    item_01 = 1;
    break;
  case 0x97:
    EVENT_ChangeOperandToNumber(stackObject,Inst->currentStreamUnitID,0);
    item_01 = 1;
    break;
  case 0x99:
    EVENT_ChangeOperandToNumber(stackObject,(uint)(Inst->tface != (_TFace *)0x0),0);
    item_01 = 1;
    break;
  case 0x9f:
    item_00 = INSTANCE_Query(Inst,0x2b);
    EVENT_ChangeOperandToNumber(stackObject,item_00,0);
    item_01 = 1;
    break;
  case 0xa0:
    item_00 = INSTANCE_Query(Inst,1);
    EVENT_ChangeOperandToNumber(stackObject,(uint)((item_00 & 4) != 0),0);
    item_01 = 1;
    break;
  case 0xa1:
    Inst = (_Instance *)INSTANCE_Query(Inst,0x2c);
    if (Inst == (_Instance *)0x0) {
      item_01 = 0;
    }
    else {
      item_00 = INSTANCE_Query(Inst,1);
      if ((item_00 & 0x20) != 0) {
        item_00 = INSTANCE_Query(Inst,4);
        if ((item_00 & 3) != 0) {
          return 1;
        }
        return 2;
      }
      item_01 = 3;
    }
    EVENT_ChangeOperandToNumber(stackObject,item_01,0);
    item_01 = 1;
  }
  return item_01;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformSoundObjectAttribute(struct _PCodeStack *stack /*$a0*/, struct SoundObject *soundObject /*$a1*/, long item /*$a2*/, short *codeStream /*$a3*/)
 // line 1891, offset 0x800637c4
	/* begin block 1 */
		// Start line: 1892
		// Start offset: 0x800637C4
		// Variables:
	// 		long retValue; // $v1

		/* begin block 1.1 */
			// Start line: 1900
			// Start offset: 0x80063818
		/* end block 1.1 */
		// End offset: 0x80063854
		// End Line: 1916
	/* end block 1 */
	// End offset: 0x80063894
	// End Line: 1962

	/* begin block 2 */
		// Start line: 4061
	/* end block 2 */
	// End Line: 4062

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
 // line 1965, offset 0x800638a4
	/* begin block 1 */
		// Start line: 1966
		// Start offset: 0x800638A4
		// Variables:
	// 		long value; // $v1
	/* end block 1 */
	// End offset: 0x80063930
	// End Line: 1998

	/* begin block 2 */
		// Start line: 4211
	/* end block 2 */
	// End Line: 4212

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
 // line 2001, offset 0x80063940
	/* begin block 1 */
		// Start line: 2002
		// Start offset: 0x80063940
		// Variables:
	// 		long value; // $s0
	// 		long retValue; // $a0

		/* begin block 1.1 */
			// Start line: 2057
			// Start offset: 0x80063AA4
			// Variables:
		// 		struct EventTimer *timer; // $a2
		// 		short time; // $v1
		/* end block 1.1 */
		// End offset: 0x80063B1C
		// End Line: 2085

		/* begin block 1.2 */
			// Start line: 2104
			// Start offset: 0x80063B74
			// Variables:
		// 		long wipeType; // $v1
		// 		long wipeTime; // $a0
		/* end block 1.2 */
		// End offset: 0x80063BDC
		// End Line: 2126

		/* begin block 1.3 */
			// Start line: 2132
			// Start offset: 0x80063BEC
			// Variables:
		// 		long motor0Time; // $a1
		// 		long motor0Speed; // $a0
		// 		long motor1Time; // $a3
		// 		long motor1Speed; // $a2
		/* end block 1.3 */
		// End offset: 0x80063C24
		// End Line: 2154

		/* begin block 1.4 */
			// Start line: 2169
			// Start offset: 0x80063C74
			// Variables:
		// 		short rand1; // $s1
		// 		short rand2; // $s0
		/* end block 1.4 */
		// End offset: 0x80063CBC
		// End Line: 2182

		/* begin block 1.5 */
			// Start line: 2187
			// Start offset: 0x80063CC4
		/* end block 1.5 */
		// End offset: 0x80063CC4
		// End Line: 2189

		/* begin block 1.6 */
			// Start line: 2197
			// Start offset: 0x80063CE4
			// Variables:
		// 		int number; // $a1
		/* end block 1.6 */
		// End offset: 0x80063CE4
		// End Line: 2199

		/* begin block 1.7 */
			// Start line: 2207
			// Start offset: 0x80063D04
		/* end block 1.7 */
		// End offset: 0x80063D04
		// End Line: 2209

		/* begin block 1.8 */
			// Start line: 2216
			// Start offset: 0x80063D28
		/* end block 1.8 */
		// End offset: 0x80063D28
		// End Line: 2218
	/* end block 1 */
	// End offset: 0x80063D54
	// End Line: 2254

	/* begin block 2 */
		// Start line: 4284
	/* end block 2 */
	// End Line: 4285

long EVENT_TransformGameAttribute
               (_PCodeStack *stack,StackType *stackObject,long item,short *codeStream)

{
  short sVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  Event *pEVar5;
  ScriptPCode *pSVar6;
  Level *pLVar7;
  EventTimer *pEVar8;
  int Data;
  ulong item_00;
  long item_01;
  uint item_02;
  
  item_01 = 0;
  switch(item) {
  case 1:
    EVENT_ChangeOperandToNumber(stackObject,(gameTrackerX.globalTimeMult * 0x1e) / 1000,0);
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
    goto LAB_80063d50;
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
    EVENT_ChangeOperandToNumber(stackObject,gameTrackerX.controlCommand[0][0],1);
    item_01 = 1;
    break;
  case 0x31:
    pEVar8 = EVENT_GetNextTimer();
    pLVar7 = CurrentPuzzleLevel;
    pSVar6 = currentActionScript;
    pEVar5 = currentEventInstance;
    if (pEVar8 == (EventTimer *)0x0) {
      return 1;
    }
    if (codeStream == (short *)0x0) {
      return 1;
    }
    MoveCodeStreamExtra = 1;
    uVar4 = codeStream[1];
    EventAbortLine = 1;
    EventJustRecievedTimer = 1;
    pEVar8->actionScript = (ScriptPCode *)(codeStream + 2);
    pEVar8->flags = pEVar8->flags & 1U | (int)((uint)uVar4 << 0x10) >> 3;
    *(ScriptPCode **)&pEVar8->event = pSVar6;
    *(Event **)&pEVar8->time = pEVar5;
    item_01 = EventCurrentEventIndex;
    pSVar6->conditionBits = pSVar6->conditionBits | 1;
    *(Level **)&pEVar8->scriptPos = pLVar7;
    *(long *)&pEVar8->level = item_01;
    goto LAB_80063d50;
  case 0x3d:
    EVENT_ChangeOperandToNumber(stackObject,(int)gameTrackerX.currentMaterialTime._2_2_,0);
    item_01 = 1;
    break;
  case 0x42:
    item_01 = 1;
    stackObject->id = 0x19;
    *(undefined4 *)stackObject->data = 0x800d0ef0;
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
    goto LAB_80063d50;
  case 0x51:
    Data = 0;
    goto LAB_80063c58;
  case 0x52:
    Data = 1;
LAB_80063c58:
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
    goto LAB_80063d50;
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
      sVar3 = codeStream[3];
      stack->topOfStack = stack->topOfStack + -1;
      GAMEPAD_Shock((int)sVar1,(int)sVar2 << 0xc,(int)sVar3,(int)codeStream[3] << 0xc);
      return 1;
    }
LAB_80063d50:
    item_01 = 1;
  }
  return item_01;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformAreaAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a1*/, long item /*$a2*/, short *codeStream /*$a3*/)
 // line 2258, offset 0x80063d70
	/* begin block 1 */
		// Start line: 2259
		// Start offset: 0x80063D70
		// Variables:
	// 		long retValue; // $v1
	// 		long offset; // $a1
	// 		struct _StreamUnit *streamUnit; // $t0
	/* end block 1 */
	// End offset: 0x80063E3C
	// End Line: 2313

	/* begin block 2 */
		// Start line: 4841
	/* end block 2 */
	// End Line: 4842

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
 // line 2317, offset 0x80063e4c
	/* begin block 1 */
		// Start line: 2318
		// Start offset: 0x80063E4C
		// Variables:
	// 		long retValue; // $v1
	// 		long offset; // $a1
	// 		struct Event *event; // $t0
	/* end block 1 */
	// End offset: 0x80063EE0
	// End Line: 2369

	/* begin block 2 */
		// Start line: 4965
	/* end block 2 */
	// End Line: 4966

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
    if (((item == 0x1a) && (lVar2 = 1, *(char *)(iVar3 + 5) == '\0')) &&
       (lVar2 = 1, (gameTrackerX.debugFlags2 & 0x800000U) == 0)) {
      *(undefined *)(iVar3 + 5) = 1;
    }
  }
  return lVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformSavedEventAttribute(struct _PCodeStack *stack /*$t0*/, struct StackType *stackObject /*$a0*/, long item /*$a2*/, short *codeStream /*$a3*/)
 // line 2372, offset 0x80063ef0
	/* begin block 1 */
		// Start line: 2373
		// Start offset: 0x80063EF0
		// Variables:
	// 		long retValue; // $v1
	// 		long offset; // $a1
	/* end block 1 */
	// End offset: 0x80063F6C
	// End Line: 2427

	/* begin block 2 */
		// Start line: 5086
	/* end block 2 */
	// End Line: 5087

long EVENT_TransformSavedEventAttribute
               (_PCodeStack *stack,StackType *stackObject,long item,short *codeStream)

{
  short sVar1;
  long lVar2;
  int iVar3;
  
  lVar2 = 0;
  if (item == 3) {
    MoveCodeStreamExtra = 1;
    sVar1 = codeStream[1];
    if ((uint)(int)sVar1 < 6) {
      iVar3 = *(int *)stackObject->data;
      if (iVar3 == 0) {
        EVENT_ChangeOperandToNumber(stackObject,0,0);
        lVar2 = 1;
      }
      else {
        stack->topOfStack = stack->topOfStack + -1;
        EVENT_AddShortPointerToStack(stack,(short *)(iVar3 + (int)sVar1 * 2 + 10));
        lVar2 = 1;
      }
    }
  }
  return lVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformSubListObjectAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a1*/, long item /*$a2*/)
 // line 2430, offset 0x80063f7c
	/* begin block 1 */
		// Start line: 2432
		// Start offset: 0x80063F7C
		// Variables:
	// 		long retValue; // $a0
	/* end block 1 */
	// End offset: 0x80063FA8
	// End Line: 2451

	/* begin block 2 */
		// Start line: 5215
	/* end block 2 */
	// End Line: 5216

	/* begin block 3 */
		// Start line: 5216
	/* end block 3 */
	// End Line: 5217

	/* begin block 4 */
		// Start line: 5222
	/* end block 4 */
	// End Line: 5223

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
 // line 2454, offset 0x80063fb0
	/* begin block 1 */
		// Start line: 2456
		// Start offset: 0x80063FB0
		// Variables:
	// 		long retValue; // $a0
	/* end block 1 */
	// End offset: 0x80063FDC
	// End Line: 2475

	/* begin block 2 */
		// Start line: 5264
	/* end block 2 */
	// End Line: 5265

	/* begin block 3 */
		// Start line: 5265
	/* end block 3 */
	// End Line: 5266

	/* begin block 4 */
		// Start line: 5271
	/* end block 4 */
	// End Line: 5272

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
 // line 2478, offset 0x80063fe4
	/* begin block 1 */
		// Start line: 2479
		// Start offset: 0x80063FE4
		// Variables:
	// 		long retValue; // $v1
	// 		struct Camera *camera; // $t0

		/* begin block 1.1 */
			// Start line: 2490
			// Start offset: 0x8006406C
			// Variables:
		// 		short time; // $a1
		/* end block 1.1 */
		// End offset: 0x800640C0
		// End Line: 2504

		/* begin block 1.2 */
			// Start line: 2520
			// Start offset: 0x800640E0
		/* end block 1.2 */
		// End offset: 0x800640E0
		// End Line: 2522
	/* end block 1 */
	// End offset: 0x800640FC
	// End Line: 2551

	/* begin block 2 */
		// Start line: 5313
	/* end block 2 */
	// End Line: 5314

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
 // line 2554, offset 0x80064110
	/* begin block 1 */
		// Start line: 2555
		// Start offset: 0x80064110
		// Variables:
	// 		long retValue; // $v1
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 2577
			// Start offset: 0x80064198
			// Variables:
		// 		long maxKeyFrames; // $v0
		/* end block 1.1 */
		// End offset: 0x800641CC
		// End Line: 2588
	/* end block 1 */
	// End offset: 0x80064200
	// End Line: 2606

	/* begin block 2 */
		// Start line: 5485
	/* end block 2 */
	// End Line: 5486

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
// long /*$ra*/ EVENT_TransformIntroAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a0*/, long item /*$a2*/)
 // line 2609, offset 0x80064214
	/* begin block 1 */
		// Start line: 2610
		// Start offset: 0x80064214
		// Variables:
	// 		long retValue; // $v0

		/* begin block 1.1 */
			// Start line: 2627
			// Start offset: 0x80064270
			// Variables:
		// 		struct Rotation3d vector; // stack offset -32
		/* end block 1.1 */
		// End offset: 0x80064270
		// End Line: 2630
	/* end block 1 */
	// End offset: 0x800642EC
	// End Line: 2693

	/* begin block 2 */
		// Start line: 5608
	/* end block 2 */
	// End Line: 5609

long EVENT_TransformIntroAttribute(_PCodeStack *stack,StackType *stackObject,long item)

{
  int iVar1;
  Rotation3d local_20;
  
  switch(item) {
  case 5:
    iVar1 = *(int *)stackObject->data;
    EVENT_ChangeOperandVector3d
              (stackObject,*(short *)(iVar1 + 0x20),*(short *)(iVar1 + 0x22),
               *(short *)(iVar1 + 0x24));
    break;
  default:
    EventAbortLine = 1;
    break;
  case 9:
    local_20.vx = *(short *)(*(int *)stackObject->data + 0x18);
    local_20.vy = *(short *)(*(int *)stackObject->data + 0x1a);
    local_20.vz = *(short *)(*(int *)stackObject->data + 0x1c);
    local_20.errorx = 0x200;
    local_20.errorz = 0x200;
    local_20.errory = 0x200;
    EVENT_ChangeOperandRotation3d(stackObject,&local_20);
    break;
  case 0x3e:
  case 0x8a:
  case 0x92:
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
 // line 2695, offset 0x800642fc
	/* begin block 1 */
		// Start line: 2696
		// Start offset: 0x800642FC
		// Variables:
	// 		long number; // $v0

		/* begin block 1.1 */
			// Start line: 2701
			// Start offset: 0x8006431C
			// Variables:
		// 		short flags; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x80064340
		// End Line: 2709
	/* end block 1 */
	// End offset: 0x80064340
	// End Line: 2711

	/* begin block 2 */
		// Start line: 5800
	/* end block 2 */
	// End Line: 5801

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
 // line 2713, offset 0x80064354
	/* begin block 1 */
		// Start line: 2714
		// Start offset: 0x80064354
		// Variables:
	// 		long result; // $s1
	// 		long trueValue; // stack offset -20
	// 		long number; // $a2
	// 		long error; // stack offset -24
	/* end block 1 */
	// End offset: 0x800644F8
	// End Line: 2788

	/* begin block 2 */
		// Start line: 5837
	/* end block 2 */
	// End Line: 5838

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
 // line 2791, offset 0x80064514
	/* begin block 1 */
		// Start line: 2793
		// Start offset: 0x80064514
		// Variables:
	// 		long value; // $a1
	// 		long trueValue; // $a2
	/* end block 1 */
	// End offset: 0x800645CC
	// End Line: 2821

	/* begin block 2 */
		// Start line: 5995
	/* end block 2 */
	// End Line: 5996

	/* begin block 3 */
		// Start line: 5996
	/* end block 3 */
	// End Line: 5997

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
// long /*$ra*/ EVENT_DoGameAction(struct GameObject *gameObject /*$s1*/, struct StackType *operand2 /*$a0*/)
 // line 2824, offset 0x800645dc
	/* begin block 1 */
		// Start line: 2825
		// Start offset: 0x800645DC
		// Variables:
	// 		long error; // stack offset -24
	// 		long number; // $a0
	// 		long trueValue; // stack offset -20
	/* end block 1 */
	// End offset: 0x8006480C
	// End Line: 2921

	/* begin block 2 */
		// Start line: 6061
	/* end block 2 */
	// End Line: 6062

long EVENT_DoGameAction(GameObject *gameObject,StackType *operand2)

{
  long modifier;
  int iVar1;
  long local_18;
  long local_14;
  
  local_18 = 1;
  local_14 = 1;
  if (gameObject->attribute != -1) {
    modifier = EVENT_ParseOperand2(operand2,&local_18,&local_14);
    iVar1 = gameObject->attribute;
    if (iVar1 == 0x87) {
      SOUND_SetMusicModifier(modifier);
    }
    else {
      if (iVar1 < 0x88) {
        if (iVar1 == 0x59) {
          if (local_18 != 0) {
            modifier = 100;
          }
          FX_Start_Rain(modifier);
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
                if (local_18 != 0) {
                  modifier = 100;
                }
                FX_Start_Snow(modifier);
              }
            }
          }
          else {
            if (iVar1 == 0x76) {
              if (-1 < modifier) {
                LOAD_PlayXA(modifier);
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
 // line 2924, offset 0x80064824
	/* begin block 1 */
		// Start line: 2925
		// Start offset: 0x80064824
		// Variables:
	// 		long trueValue; // stack offset -12
	// 		long number; // $v1
	// 		long error; // stack offset -16
	/* end block 1 */
	// End offset: 0x8006488C
	// End Line: 2957

	/* begin block 2 */
		// Start line: 6263
	/* end block 2 */
	// End Line: 6264

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
 // line 2960, offset 0x800648a0
	/* begin block 1 */
		// Start line: 2961
		// Start offset: 0x800648A0
		// Variables:
	// 		long retValue; // $s0
	// 		struct _MultiSignal *msignal; // $s1
	/* end block 1 */
	// End offset: 0x80064900
	// End Line: 2989

	/* begin block 2 */
		// Start line: 6340
	/* end block 2 */
	// End Line: 6341

long EVENT_TransformSignalAttribute(_PCodeStack *stack,StackType *stackObject,long item)

{
  _MultiSignal *mSignal;
  
  mSignal = *(_MultiSignal **)stackObject->data;
  if (item == 0x1a) {
    *(undefined4 *)(stackObject->data + 4) = 0x1a;
  }
  else {
    if (item != 0x32) {
      return 0;
    }
    EVENT_ChangeOperandToNumber(stackObject,(uint)(ushort)mSignal->flags & 1,0);
    EVENT_AddSignalToReset(mSignal);
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformRotation3dAttribute(struct _PCodeStack *stack /*$a0*/, struct StackType *stackObject /*$a1*/, long item /*$a2*/, short *codeStream /*$a3*/)
 // line 2993, offset 0x80064918
	/* begin block 1 */
		// Start line: 2995
		// Start offset: 0x80064918
		// Variables:
	// 		long retValue; // $v0
	/* end block 1 */
	// End offset: 0x80064948
	// End Line: 3015

	/* begin block 2 */
		// Start line: 6414
	/* end block 2 */
	// End Line: 6415

	/* begin block 3 */
		// Start line: 6415
	/* end block 3 */
	// End Line: 6416

	/* begin block 4 */
		// Start line: 6417
	/* end block 4 */
	// End Line: 6418

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
 // line 3017, offset 0x80064950
	/* begin block 1 */
		// Start line: 3018
		// Start offset: 0x80064950
		// Variables:
	// 		long retValue; // $a2
	/* end block 1 */
	// End offset: 0x80064A3C
	// End Line: 3070

	/* begin block 2 */
		// Start line: 6462
	/* end block 2 */
	// End Line: 6463

long EVENT_TransformVector3dAttribute
               (_PCodeStack *stack,StackType *stackObject,long item,short *codeStream)

{
  short sVar1;
  long item_00;
  
  switch(item) {
  case 6:
    item_00 = (long)*(short *)stackObject->data;
    goto LAB_800649a4;
  case 7:
    item_00 = (long)*(short *)(stackObject->data + 2);
    goto LAB_800649a4;
  case 8:
    item_00 = (long)*(short *)(stackObject->data + 4);
LAB_800649a4:
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
 // line 3073, offset 0x80064a4c
	/* begin block 1 */
		// Start line: 6591
	/* end block 1 */
	// End Line: 6592

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
 // line 3096, offset 0x80064a7c
	/* begin block 1 */
		// Start line: 3097
		// Start offset: 0x80064A7C
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $a2
	// 		long result; // $s0
	// 		long error; // stack offset -24
	/* end block 1 */
	// End offset: 0x80064B6C
	// End Line: 3150

	/* begin block 2 */
		// Start line: 6637
	/* end block 2 */
	// End Line: 6638

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
 // line 3153, offset 0x80064b84
	/* begin block 1 */
		// Start line: 6762
	/* end block 1 */
	// End Line: 6763

	/* begin block 2 */
		// Start line: 6763
	/* end block 2 */
	// End Line: 6764

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
 // line 3161, offset 0x80064c0c
	/* begin block 1 */
		// Start line: 6778
	/* end block 1 */
	// End Line: 6779

	/* begin block 2 */
		// Start line: 6779
	/* end block 2 */
	// End Line: 6780

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
 // line 3169, offset 0x80064c94
	/* begin block 1 */
		// Start line: 3170
		// Start offset: 0x80064C94
		// Variables:
	// 		long trueValue; // stack offset -28
	// 		long number; // $s0
	// 		long result; // $s4
	// 		long error; // stack offset -32

		/* begin block 1.1 */
			// Start line: 3181
			// Start offset: 0x80064CD8
			// Variables:
		// 		struct _Instance *instance; // $s1
		// 		struct MultiSpline *spline; // $s2

			/* begin block 1.1.1 */
				// Start line: 3233
				// Start offset: 0x80064D98
				// Variables:
			// 		long curKeyFrame; // $a0

				/* begin block 1.1.1.1 */
					// Start line: 3241
					// Start offset: 0x80064DA8
					// Variables:
				// 		long maxKeyFrames; // $v1
				/* end block 1.1.1.1 */
				// End offset: 0x80064DC8
				// End Line: 3249
			/* end block 1.1.1 */
			// End offset: 0x80064EBC
			// End Line: 3293
		/* end block 1.1 */
		// End offset: 0x8006503C
		// End Line: 3333
	/* end block 1 */
	// End offset: 0x8006503C
	// End Line: 3335

	/* begin block 2 */
		// Start line: 6794
	/* end block 2 */
	// End Line: 6795

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
    goto switchD_80064d18_caseD_d;
  case 0xe:
    local_1c = local_1c ^ 1;
switchD_80064d18_caseD_d:
    lVar9 = 1;
    if (local_1c == 0) {
      uVar6 = instance->flags;
      uVar4 = 0xfdffffff;
LAB_80064ec8:
      instance->flags = uVar6 & uVar4;
    }
    else {
      uVar4 = instance->flags;
      uVar6 = 0x2000000;
LAB_80064eb0:
      instance->flags = uVar4 | uVar6;
    }
switchD_80064d18_caseD_12:
    return lVar9;
  case 0xf:
  case 0x28:
    if (iVar3 == -1) {
      return 0;
    }
    SCRIPT_InstanceSplineSet
              (instance,(short)iVar3,(SplineDef *)0x0,(SplineDef *)0x0,(SplineDef *)0x0);
    uVar4 = 0xfdff0000;
    goto LAB_80064ec0;
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
    if (iVar3 < 1) goto LAB_80064ea8;
LAB_80064ec0:
    uVar6 = instance->flags;
    uVar4 = uVar4 | 0xffff;
    goto LAB_80064ec8;
  default:
    goto switchD_80064d18_caseD_12;
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
      goto LAB_80064ec0;
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
        goto LAB_80064ec0;
      }
      EVENT_ResetAllSplineFlags(spline);
      EVENT_SetSplineLoop(spline);
      instance->splineFlags = instance->splineFlags | 0x20;
    }
LAB_80064ea8:
    uVar4 = instance->flags;
    uVar6 = 0x1000000;
    goto LAB_80064eb0;
  }
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoAnimateAction(struct InstanceAnimate *instanceAnimate /*$s1*/, struct StackType *operand2 /*$s3*/)
 // line 3338, offset 0x80065060
	/* begin block 1 */
		// Start line: 3339
		// Start offset: 0x80065060
		// Variables:
	// 		long trueValue; // stack offset -28
	// 		long number; // $a0
	// 		long result; // $s2
	// 		long error; // stack offset -32
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 3404
			// Start offset: 0x8006513C
			// Variables:
		// 		struct _Instance *hostInstance; // $v0
		/* end block 1.1 */
		// End offset: 0x8006513C
		// End Line: 3405
	/* end block 1 */
	// End offset: 0x80065314
	// End Line: 3559

	/* begin block 2 */
		// Start line: 7155
	/* end block 2 */
	// End Line: 7156

long EVENT_DoAnimateAction(InstanceAnimate *instanceAnimate,StackType *operand2)

{
  long lVar1;
  int Data;
  undefined2 uVar2;
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
  uVar2 = (undefined2)lVar1;
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
      if (instance->light_color == 0) {
        Data = SetAnimationInstanceSwitchData
                         (instance,(int)*(short *)&instance->perVertexColor,
                          (int)*(short *)((int)&instance->perVertexColor + 2),
                          (int)*(short *)&instance[1].node.prev,1);
        Message = 0x8000008;
      }
      else {
        Data = SetActionPlayHostAnimationData
                         (instance,(_Instance *)instance->light_color,
                          (int)*(short *)&instance->perVertexColor,
                          (int)*(short *)((int)&instance->perVertexColor + 2),
                          (int)*(short *)&instance[1].node.prev,1);
        Message = 0x40003;
      }
    }
    INSTANCE_Post(instance,Message,Data);
    memset(&instance->light_color,0,0xc);
    lVar3 = 1;
    break;
  case 0xf:
  case 0x28:
    lVar3 = 0;
    if (lVar1 != -1) {
      *(undefined2 *)((int)&instance->perVertexColor + 2) = uVar2;
    }
    break;
  case 0x1e:
    lVar3 = 1;
    if (lVar1 != -1) {
      *(undefined2 *)&instance->perVertexColor = uVar2;
    }
    break;
  case 0x2a:
    if (instance->light_color == 0) {
      Data = SetAnimationInstanceSwitchData
                       (instance,(int)*(short *)&instance->perVertexColor,
                        (int)*(short *)((int)&instance->perVertexColor + 2),
                        (int)*(short *)&instance[1].node.prev,2);
      Message = 0x8000008;
    }
    else {
      Data = SetActionPlayHostAnimationData
                       (instance,(_Instance *)instance->light_color,
                        (int)*(short *)&instance->perVertexColor,
                        (int)*(short *)((int)&instance->perVertexColor + 2),
                        (int)*(short *)&instance[1].node.prev,2);
      Message = 0x40003;
    }
LAB_800652f8:
    INSTANCE_Post(instance,Message,Data);
    goto LAB_80065300;
  case 0x65:
    if (operand2 != (StackType *)0x0) {
      if (operand2->id == 2) {
        instance->light_color = *(long *)operand2->data;
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
      *(undefined2 *)&instance[1].node.prev = uVar2;
    }
    break;
  case 0x6b:
    if (instance->light_color == 0) {
      Data = SetAnimationInstanceSwitchData
                       (instance,(int)*(short *)&instance->perVertexColor,
                        (int)*(short *)((int)&instance->perVertexColor + 2),
                        (int)*(short *)&instance[1].node.prev,0);
      Message = 0x8000008;
    }
    else {
      Data = SetActionPlayHostAnimationData
                       (instance,(_Instance *)instance->light_color,
                        (int)*(short *)&instance->perVertexColor,
                        (int)*(short *)((int)&instance->perVertexColor + 2),
                        (int)*(short *)&instance[1].node.prev,0);
      Message = 0x40003;
    }
    INSTANCE_Post(instance,Message,Data);
    Data = (int)*(short *)((int)&instance[1].node.prev + 2);
    if (0 < Data) {
      Message = 0x40020;
      goto LAB_800652f8;
    }
LAB_80065300:
    memset(&instance->light_color,0,0xc);
    lVar3 = 1;
    break;
  case 0x84:
    *(undefined2 *)((int)&instance[1].node.prev + 2) = uVar2;
  }
  return lVar3;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoInstanceAction(struct InstanceObject *instanceObject /*$s3*/, struct StackType *operand2 /*$s2*/, short *codeStream /*$s5*/)
 // line 3563, offset 0x80065334
	/* begin block 1 */
		// Start line: 3564
		// Start offset: 0x80065334
		// Variables:
	// 		long trueValue; // stack offset -36
	// 		long number; // $s0
	// 		long error; // stack offset -40
	// 		long result; // $s4
	// 		struct _Instance *instance; // $s1

		/* begin block 1.1 */
			// Start line: 3691
			// Start offset: 0x80065680
			// Variables:
		// 		int x; // $a0
		// 		int y; // $a1
		/* end block 1.1 */
		// End offset: 0x800656E0
		// End Line: 3709

		/* begin block 1.2 */
			// Start line: 3716
			// Start offset: 0x80065700
			// Variables:
		// 		struct Object *object; // $s2
		// 		int i; // $s0
		/* end block 1.2 */
		// End offset: 0x80065764
		// End Line: 3735

		/* begin block 1.3 */
			// Start line: 3756
			// Start offset: 0x800657BC
			// Variables:
		// 		struct Intro *intro; // $a0
		/* end block 1.3 */
		// End offset: 0x800657F0
		// End Line: 3767

		/* begin block 1.4 */
			// Start line: 3799
			// Start offset: 0x80065870
		/* end block 1.4 */
		// End offset: 0x80065870
		// End Line: 3805

		/* begin block 1.5 */
			// Start line: 3811
			// Start offset: 0x800658B0
		/* end block 1.5 */
		// End offset: 0x800658B0
		// End Line: 3817

		/* begin block 1.6 */
			// Start line: 3823
			// Start offset: 0x800658F0
		/* end block 1.6 */
		// End offset: 0x800658F0
		// End Line: 3829

		/* begin block 1.7 */
			// Start line: 3838
			// Start offset: 0x80065944
		/* end block 1.7 */
		// End offset: 0x80065944
		// End Line: 3843

		/* begin block 1.8 */
			// Start line: 3849
			// Start offset: 0x80065984
		/* end block 1.8 */
		// End offset: 0x80065984
		// End Line: 3855

		/* begin block 1.9 */
			// Start line: 3861
			// Start offset: 0x800659C4
		/* end block 1.9 */
		// End offset: 0x800659C4
		// End Line: 3867

		/* begin block 1.10 */
			// Start line: 3889
			// Start offset: 0x80065A60
			// Variables:
		// 		struct EventTimer *timer; // $a2
		/* end block 1.10 */
		// End offset: 0x80065A74
		// End Line: 3894

		/* begin block 1.11 */
			// Start line: 3928
			// Start offset: 0x80065B1C
		/* end block 1.11 */
		// End offset: 0x80065B1C
		// End Line: 3933

		/* begin block 1.12 */
			// Start line: 3981
			// Start offset: 0x80065BF8
		/* end block 1.12 */
		// End offset: 0x80065C3C
		// End Line: 3986
	/* end block 1 */
	// End offset: 0x80065D00
	// End Line: 4023

	/* begin block 2 */
		// Start line: 7620
	/* end block 2 */
	// End Line: 7621

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
  uint Message;
  int y;
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
    if ((int)type < 0x100) {
      if (type - 1 < 7) {
        ScriptKillInstance(sender,type);
        return 0;
      }
      if (type != 0) {
        return 0;
      }
      SAVE_UndestroyInstance(sender);
      return 0;
    }
    Message = 0x40017;
    type = type - 0x100;
    break;
  default:
    goto switchD_800653b8_caseD_5;
  case 10:
    goto switchD_800653b8_caseD_a;
  case 0xb:
    local_24 = local_24 ^ 1;
    goto switchD_800653b8_caseD_a;
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
    goto LAB_800655e4;
  case 0x20:
    if (type == 2) {
      Message = 0x40012;
    }
    else {
      if ((int)type < 3) {
        if (type != 1) {
          return 0;
        }
        Message = 0x40000;
      }
      else {
        if (type != 3) {
          if (type != 4) {
            return 0;
          }
          Message = 0x40005;
          type = 0xa000;
          break;
        }
        Message = 0x40014;
      }
    }
    goto LAB_80065cf4;
  case 0x24:
    goto switchD_800653b8_caseD_24;
  case 0x25:
    local_24 = local_24 ^ 1;
    goto switchD_800653b8_caseD_24;
  case 0x26:
    local_24 = local_24 ^ 1;
  case 0x27:
    if (local_24 == 0) {
      Message = 0x800000;
LAB_80065cf0:
      Message = Message | 0x22;
    }
    else {
      Message = 0x800021;
    }
    goto LAB_80065cf4;
  case 0x33:
    if (type == 0xffffffff) {
      type = 0;
    }
    Message = 0x1000017;
    break;
  case 0x34:
    if (local_24 == 0) {
      type = sender->flags & 0xfffff7ff;
    }
    else {
      type = sender->flags | 0x800;
    }
    goto LAB_800654c8;
  case 0x35:
    if (local_24 == 0) {
      sender->flags2 = sender->flags2 & 0xdfffffff;
      sender->flags = sender->flags & 0xfffbffff;
      return 1;
    }
    sender->flags2 = sender->flags2 | 0x20000000;
    type = sender->flags | 0x40000;
LAB_800654c8:
    sender->flags = type;
    return 1;
  case 0x36:
    Data = 0;
    if (3 < type) {
      return 0;
    }
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
    type = SetObjectData(Data,y,6,(_Instance *)0x0,0);
    Message = 0x800000;
    break;
  case 0x37:
    pOVar8 = sender->object;
    Data = (int)pOVar8->numberOfEffects;
    if (Data == 0) {
      return 0;
    }
    if (type == 0xffffffff) {
      y = 0;
      if (Data < 1) {
        return 0;
      }
      do {
        FX_StartInstanceEffect(sender,pOVar8->effectList + y,0);
        y = y + 1;
      } while (y < pOVar8->numberOfEffects);
      return 0;
    }
    if (Data <= (int)type) {
      return 0;
    }
    FX_StartInstanceEffect(sender,pOVar8->effectList + type,0);
    return 0;
  case 0x40:
    if (type != 0) {
      type = 1;
    }
    Message = 0x100001a;
    break;
  case 0x4b:
    if (operand2 == (StackType *)0x0) {
      return 0;
    }
    if (operand2->id != 9) {
      return 0;
    }
    type = SetPositionData((int)*(short *)operand2->data,(int)*(short *)(operand2->data + 2),
                           (int)*(short *)(operand2->data + 4));
    Message = 0x40016;
    break;
  case 0x4c:
    if (operand2 == (StackType *)0x0) {
      return 0;
    }
    if (operand2->id != 9) {
      return 0;
    }
    type = SetPositionData((int)*(short *)operand2->data,(int)*(short *)(operand2->data + 2),
                           (int)*(short *)(operand2->data + 4));
    Message = 0x4000a;
    break;
  case 0x4d:
    if (operand2 == (StackType *)0x0) {
      return 0;
    }
    if (operand2->id != 0xe) {
      return 0;
    }
    type = SetPositionData((int)*(short *)operand2->data,(int)*(short *)(operand2->data + 2),
                           (int)*(short *)(operand2->data + 4));
    Message = 0x4000b;
    break;
  case 0x4e:
    goto switchD_800653b8_caseD_4e;
  case 0x4f:
    local_24 = (uint)(local_24 == 0);
    goto switchD_800653b8_caseD_4e;
  case 0x50:
    if (operand2 == (StackType *)0x0) {
      return 0;
    }
    if (operand2->id != 0xe) {
      return 0;
    }
    type = SetPositionData((int)*(short *)operand2->data,(int)*(short *)(operand2->data + 2),
                           (int)*(short *)(operand2->data + 4));
    Message = 0x4000d;
    break;
  case 0x53:
    if (operand2 == (StackType *)0x0) {
      return 0;
    }
    if (operand2->id != 9) {
      return 0;
    }
    type = SetPositionData((int)*(short *)operand2->data,(int)*(short *)(operand2->data + 2),
                           (int)*(short *)(operand2->data + 4));
    Message = 0x4000f;
    break;
  case 0x54:
    if (local_24 == 0) {
      return 0;
    }
    Message = 0x40010;
    goto LAB_80065cf4;
  case 0x55:
    Message = 0x800027;
    type = local_24;
    break;
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
    goto switchD_800653b8_caseD_5e;
  case 0x5f:
    local_24 = 0;
    goto switchD_800653b8_caseD_5e;
  case 0x67:
    if (local_24 != 0) {
      sender->flags = sender->flags & 0xffbfffff;
      return 0;
    }
    sender->flags = sender->flags | 0x400000;
    return 0;
  case 0x6c:
    Data = (int)type % 0x168;
    if (Data < 0) {
      Data = Data + 0x168;
    }
    type = rcos((Data * 0x1000) / 0x168);
    Message = 0x4000005;
    break;
  case 0x6d:
    Message = 0x4000006;
    goto LAB_80065cf4;
  case 0x6e:
    Message = 0x40011;
LAB_80065cf4:
    type = 0;
    break;
  case 0x6f:
    Message = 0x40015;
    type = 1 << (type & 0x1f);
    break;
  case 0x72:
    if (operand2 == (StackType *)0x0) {
      return 0;
    }
    if (operand2->id != 9) {
      return 0;
    }
    type = SetPositionData((int)*(short *)operand2->data,(int)*(short *)(operand2->data + 2),
                           (int)*(short *)(operand2->data + 4));
    Message = 0x4000c;
    break;
  case 0x74:
    Message = 0x40006;
    type = type << 0xc;
    break;
  case 0x7b:
    if (operand2 == (StackType *)0x0) {
      return 0;
    }
    if (operand2->id != 9) {
      return 0;
    }
    type = SetPositionData((int)*(short *)operand2->data,(int)*(short *)(operand2->data + 2),
                           (int)*(short *)(operand2->data + 4));
    Message = 0x40018;
    break;
  case 0x7c:
    type = type << 0xc;
    INSTANCE_Post(sender,0x40019,type);
  case 0xa3:
    Message = 0x1000022;
    break;
  case 0x85:
    Message = 0x40021;
    break;
  case 0x8a:
    pIVar7 = sender->intro;
    if (pIVar7 == (Intro *)0x0) {
      return 0;
    }
    if (local_24 != 0) {
      pIVar7->flags = pIVar7->flags | 0x400;
      return 0;
    }
    pIVar7->flags = pIVar7->flags & 0xfffffbff;
    return 0;
  case 0x8c:
    Message = 0x40022;
    break;
  case 0x8d:
    if ((int)type < 0) {
      return 0;
    }
    Data = SetMonsterAlarmData(sender,(_Position *)0x0,type);
    INSTANCE_Broadcast((_Instance *)0x0,10,0x1000011,Data);
    return 0;
  case 0xa4:
    Message = 0x1000000;
    goto LAB_80065cf0;
  }
  goto LAB_80065cf8;
switchD_800653b8_caseD_4e:
  if (sender == gameTrackerX.playerInstance) {
    INSTANCE_Post(sender,0x4000e,local_24);
    if (local_24 == 0) {
      gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffffff6f;
      return 0;
    }
    gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x90;
    pEVar6 = EVENT_GetNextTimer();
    pSVar3 = currentActionScript;
    pEVar2 = currentEventInstance;
    lVar1 = EventCurrentEventIndex;
    if (pEVar6 == (EventTimer *)0x0) {
      return 0;
    }
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
    return 0;
  }
  Message = 0x4000e;
  type = local_24;
  goto LAB_80065cf8;
switchD_800653b8_caseD_24:
  if (local_24 == 0) {
    uVar5 = INSTANCE_Query(instanceObject->instance,5);
    if ((uVar5 & 1) == 0) {
      return 0;
    }
    Message = 0x800020;
  }
  else {
    uVar5 = INSTANCE_Query(instanceObject->instance,5);
    if ((uVar5 & 1) != 0) {
      return 0;
    }
    Message = 0x800020;
  }
  goto LAB_80065cf4;
switchD_800653b8_caseD_a:
  if (local_24 == 0) {
    sender->flags = sender->flags & 0xfffff7ff;
    sender->flags2 = sender->flags2 & 0xdfffffff;
    sender->flags = sender->flags & 0xfffbffff;
  }
  else {
    sender->flags = sender->flags | 0x800;
    sender->flags2 = sender->flags2 | 0x20000000;
    sender->flags = sender->flags | 0x40000;
  }
  uVar5 = INSTANCE_Query(sender,1);
  if ((uVar5 & 0xe) == 0) {
    return 1;
  }
  Data = 0x40013;
  type = local_24;
LAB_800655e4:
  INSTANCE_Post(sender,Data,type);
  return 1;
switchD_800653b8_caseD_5e:
  Message = 0x800029;
  type = local_24;
LAB_80065cf8:
  INSTANCE_Post(sender,Message,type);
switchD_800653b8_caseD_5:
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_GetTGroupValue(struct TGroupObject *terrainGroup /*$a0*/)
 // line 4026, offset 0x80065d28
	/* begin block 1 */
		// Start line: 4028
		// Start offset: 0x80065D28
		// Variables:
	// 		long value; // $a1
	// 		long trueValue; // $a2
	// 		struct BSPTree *bspTree; // $a0
	/* end block 1 */
	// End offset: 0x80065E94
	// End Line: 4129

	/* begin block 2 */
		// Start line: 8573
	/* end block 2 */
	// End Line: 8574

	/* begin block 3 */
		// Start line: 8574
	/* end block 3 */
	// End Line: 8575

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
          return -(int)pBVar3->ID;
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
 // line 4132, offset 0x80065ea0
	/* begin block 1 */
		// Start line: 4133
		// Start offset: 0x80065EA0
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $v0
	// 		long error; // stack offset -24
	// 		long result; // $s2

		/* begin block 1.1 */
			// Start line: 4144
			// Start offset: 0x80065ED4
			// Variables:
		// 		struct BSPTree *bspTree; // $s0

			/* begin block 1.1.1 */
				// Start line: 4152
				// Start offset: 0x80065F7C
				// Variables:
			// 		struct WaterLevelProcess *curWater; // $a0
			/* end block 1.1.1 */
			// End offset: 0x80066008
			// End Line: 4168

			/* begin block 1.1.2 */
				// Start line: 4176
				// Start offset: 0x8006601C
				// Variables:
			// 		long offsetz; // $a0
			/* end block 1.1.2 */
			// End offset: 0x800660A0
			// End Line: 4189
		/* end block 1.1 */
		// End offset: 0x80066188
		// End Line: 4259
	/* end block 1 */
	// End offset: 0x80066188
	// End Line: 4261

	/* begin block 2 */
		// Start line: 8789
	/* end block 2 */
	// End Line: 8790

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
 // line 4264, offset 0x800661a4
	/* begin block 1 */
		// Start line: 4265
		// Start offset: 0x800661A4
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $a1
	// 		long error; // stack offset -24
	// 		struct Camera *camera; // $s1

		/* begin block 1.1 */
			// Start line: 4298
			// Start offset: 0x80066240
			// Variables:
		// 		struct Intro *intro; // $a0
		/* end block 1.1 */
		// End offset: 0x800662A8
		// End Line: 4328

		/* begin block 1.2 */
			// Start line: 4337
			// Start offset: 0x800662C4
			// Variables:
		// 		long angle; // $a1
		/* end block 1.2 */
		// End offset: 0x80066388
		// End Line: 4358

		/* begin block 1.3 */
			// Start line: 4370
			// Start offset: 0x800663B4
			// Variables:
		// 		long angle; // $v0
		/* end block 1.3 */
		// End offset: 0x80066404
		// End Line: 4380

		/* begin block 1.4 */
			// Start line: 4394
			// Start offset: 0x80066424
			// Variables:
		// 		long angle; // $v0
		/* end block 1.4 */
		// End offset: 0x80066464
		// End Line: 4403

		/* begin block 1.5 */
			// Start line: 4431
			// Start offset: 0x800664DC
		/* end block 1.5 */
		// End offset: 0x800664DC
		// End Line: 4435
	/* end block 1 */
	// End offset: 0x80066508
	// End Line: 4465

	/* begin block 2 */
		// Start line: 9063
	/* end block 2 */
	// End Line: 9064

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
    goto LAB_80066470;
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
LAB_80066470:
    CAMERA_Adjust_roll((iVar2 + iVar1 >> 8) - (iVar1 >> 0x1f),frames);
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoObjectSoundAction(struct SoundObject *soundObject /*$s0*/, struct StackType *operand2 /*$a0*/)
 // line 4468, offset 0x80066524
	/* begin block 1 */
		// Start line: 4469
		// Start offset: 0x80066524
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $v1
	// 		long error; // stack offset -24
	// 		long result; // $s2
	// 		struct _Instance *instance; // $a3

		/* begin block 1.1 */
			// Start line: 4484
			// Start offset: 0x8006655C
			// Variables:
		// 		struct SoundInstance *soundInstance; // $s1
		/* end block 1.1 */
		// End offset: 0x8006663C
		// End Line: 4522
	/* end block 1 */
	// End offset: 0x8006663C
	// End Line: 4523

	/* begin block 2 */
		// Start line: 9479
	/* end block 2 */
	// End Line: 9480

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
 // line 4526, offset 0x80066658
	/* begin block 1 */
		// Start line: 4527
		// Start offset: 0x80066658
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $v1
	// 		long error; // stack offset -24
	// 		long result; // $s2
	// 		struct _SFXMkr *sfxMarker; // $a3

		/* begin block 1.1 */
			// Start line: 4542
			// Start offset: 0x80066690
			// Variables:
		// 		struct SoundInstance *soundInstance; // $s1
		/* end block 1.1 */
		// End offset: 0x80066770
		// End Line: 4580
	/* end block 1 */
	// End offset: 0x80066770
	// End Line: 4581

	/* begin block 2 */
		// Start line: 9604
	/* end block 2 */
	// End Line: 9605

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
 // line 4584, offset 0x8006678c
	/* begin block 1 */
		// Start line: 4586
		// Start offset: 0x8006678C
	/* end block 1 */
	// End offset: 0x8006678C
	// End Line: 4618

	/* begin block 2 */
		// Start line: 9729
	/* end block 2 */
	// End Line: 9730

	/* begin block 3 */
		// Start line: 9730
	/* end block 3 */
	// End Line: 9731

	/* begin block 4 */
		// Start line: 9762
	/* end block 4 */
	// End Line: 9763

	/* begin block 5 */
		// Start line: 9763
	/* end block 5 */
	// End Line: 9764

long EVENT_GetSoundValue(SoundObject *soundObject)

{
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoAreaAction(struct AreaObject *areaObject /*$s0*/, struct StackType *operand2 /*$a0*/)
 // line 4621, offset 0x80066794
	/* begin block 1 */
		// Start line: 4622
		// Start offset: 0x80066794
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $v1
	// 		long error; // stack offset -24
	// 		struct _StreamUnit *streamUnit; // $s1
	/* end block 1 */
	// End offset: 0x80066818
	// End Line: 4663

	/* begin block 2 */
		// Start line: 9803
	/* end block 2 */
	// End Line: 9804

long EVENT_DoAreaAction(AreaObject *areaObject,StackType *operand2)

{
  long lVar1;
  _StreamUnit *p_Var2;
  long local_18;
  long local_14;
  
  local_14 = 1;
  p_Var2 = areaObject->streamUnit;
  if (areaObject->attribute != -1) {
    lVar1 = EVENT_ParseOperand2(operand2,&local_18,&local_14);
    if (areaObject->attribute == 0x70) {
      if (local_18 == 0) {
        p_Var2->TargetFogFar = (short)lVar1;
      }
    }
    else {
      if ((areaObject->attribute == 0x71) && (local_18 == 0)) {
        p_Var2->TargetFogNear = (short)lVar1;
      }
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_DoIntroAction(struct IntroObject *introObject /*$s1*/, struct StackType *operand2 /*$a0*/)
 // line 4666, offset 0x80066830
	/* begin block 1 */
		// Start line: 4667
		// Start offset: 0x80066830
		// Variables:
	// 		long trueValue; // stack offset -20
	// 		long number; // $v0
	// 		long error; // stack offset -24
	// 		long result; // $s2

		/* begin block 1.1 */
			// Start line: 4678
			// Start offset: 0x80066864
			// Variables:
		// 		struct Intro *intro; // $s0

			/* begin block 1.1.1 */
				// Start line: 4722
				// Start offset: 0x8006695C
				// Variables:
			// 		int i; // $a2
			// 		int j; // $v1
			// 		int id; // $a1

				/* begin block 1.1.1.1 */
					// Start line: 4725
					// Start offset: 0x80066970

					/* begin block 1.1.1.1.1 */
						// Start line: 4728
						// Start offset: 0x80066980
						// Variables:
					// 		struct Intro *intro1; // $v0
					/* end block 1.1.1.1.1 */
					// End offset: 0x800669B8
					// End Line: 4737
				/* end block 1.1.1.1 */
				// End offset: 0x800669B8
				// End Line: 4738
			/* end block 1.1.1 */
			// End offset: 0x800669EC
			// End Line: 4741
		/* end block 1.1 */
		// End offset: 0x800669EC
		// End Line: 4748
	/* end block 1 */
	// End offset: 0x800669EC
	// End Line: 4750

	/* begin block 2 */
		// Start line: 9899
	/* end block 2 */
	// End Line: 9900

long EVENT_DoIntroAction(IntroObject *introObject,StackType *operand2)

{
  uint uVar1;
  Level *pLVar2;
  Intro *pIVar3;
  _Instance *p_Var4;
  uint uVar5;
  int iVar6;
  int iVar7;
  STracker *pSVar8;
  long lVar9;
  Intro *intro;
  long lVar10;
  long lStack24;
  uint local_14;
  
  local_14 = 1;
  lVar10 = 0;
  lVar9 = lVar10;
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
        lVar9 = 1;
      }
      else {
        if (iVar7 == 0x3e) {
          lVar9 = 0;
          iVar7 = 0;
          pSVar8 = &StreamTracker;
          do {
            if (pSVar8->StreamList[0].used == 2) {
              pLVar2 = pSVar8->StreamList[0].level;
              iVar6 = pLVar2->numIntros;
              pIVar3 = pLVar2->introList;
              while (iVar6 != 0) {
                if (pIVar3 == intro) {
                  lVar9 = pSVar8->StreamList[0].StreamUnitID;
                  break;
                }
                iVar6 = iVar6 + -1;
                pIVar3 = pIVar3 + 1;
              }
            }
            pSVar8 = (STracker *)(pSVar8->StreamList + 1);
            iVar7 = iVar7 + 1;
          } while (iVar7 < 0x10);
          p_Var4 = INSTANCE_IntroduceInstance(intro,(short)lVar9);
          lVar9 = 0;
          if (p_Var4 == (_Instance *)0x0) {
            EventAbortLine = 1;
            lVar9 = lVar10;
          }
        }
        else {
          lVar9 = 0;
          if ((0x3e < iVar7) && (lVar9 = 0, iVar7 == 0x8a)) {
            if (local_14 == 0) {
              intro->flags = intro->flags & 0xfffffbff;
              lVar9 = lVar10;
            }
            else {
              intro->flags = intro->flags | 0x400;
              lVar9 = lVar10;
            }
          }
        }
      }
    }
  }
  return lVar9;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_DoStackOperationEquals(struct _PCodeStack *stack /*$a2*/, short *codeStream /*$a3*/)
 // line 4767, offset 0x80066a08
	/* begin block 1 */
		// Start line: 4768
		// Start offset: 0x80066A08
		// Variables:
	// 		struct StackType operand1; // stack offset -88
	// 		struct StackType operand2; // stack offset -48
	/* end block 1 */
	// End offset: 0x80066ACC
	// End Line: 4782

	/* begin block 2 */
		// Start line: 9527
	/* end block 2 */
	// End Line: 9528

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
 // line 4787, offset 0x80066af4
	/* begin block 1 */
		// Start line: 4789
		// Start offset: 0x80066AF4
		// Variables:
	// 		long retValue; // $t2

		/* begin block 1.1 */
			// Start line: 4812
			// Start offset: 0x80066B98
			// Variables:
		// 		long dist; // $v0
		/* end block 1.1 */
		// End offset: 0x80066C18
		// End Line: 4822

		/* begin block 1.2 */
			// Start line: 4828
			// Start offset: 0x80066C20
			// Variables:
		// 		long dist; // $v0
		/* end block 1.2 */
		// End offset: 0x80066C90
		// End Line: 4838
	/* end block 1 */
	// End offset: 0x80066C90
	// End Line: 4841

	/* begin block 2 */
		// Start line: 10155
	/* end block 2 */
	// End Line: 10156

	/* begin block 3 */
		// Start line: 10156
	/* end block 3 */
	// End Line: 10157

	/* begin block 4 */
		// Start line: 10159
	/* end block 4 */
	// End Line: 10160

long EVENT_CompareVector3d(Vector3d *vector1,Vector3d *vector2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
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
      goto LAB_80066c84;
    }
  }
  iVar4 = (int)vector2->vx - (int)vector1->vx;
  iVar3 = (int)vector2->vy - (int)vector1->vy;
  iVar2 = (int)vector2->vz - (int)vector1->vz;
  bVar1 = iVar4 * iVar4 + iVar3 * iVar3 + iVar2 * iVar2 <
          (int)vector1->errorx * (int)vector1->errorx;
LAB_80066c84:
  if (bVar1) {
    return 1;
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_CompareRotationVectors(struct Rotation3d *rot1 /*$a0*/, struct Rotation3d *rot2 /*$s1*/, long trueValue /*$s6*/)
 // line 4850, offset 0x80066c9c
	/* begin block 1 */
		// Start line: 4851
		// Start offset: 0x80066C9C
		// Variables:
	// 		struct MATRIX matrix1; // stack offset -104
	// 		struct MATRIX matrix2; // stack offset -72
	// 		long result; // $s2
	// 		long c1; // $v1
	// 		long attribute; // $s0
	// 		struct _SVector axis; // stack offset -40
	// 		long doSoft; // $s4
	/* end block 1 */
	// End offset: 0x80066E68
	// End Line: 4948

	/* begin block 2 */
		// Start line: 10287
	/* end block 2 */
	// End Line: 10288

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
  RotMatrixZYX((short *)rot1,(uint *)&MStack104);
  RotMatrixZYX((short *)rot2,(uint *)&MStack72);
  if (iVar3 == 8) {
LAB_80066dfc:
    local_28.x = 0;
    local_28.y = 0;
    local_28.z = 0x1000;
    goto LAB_80066e10;
  }
  if (iVar3 < 9) {
    if (iVar3 == 6) {
LAB_80066dcc:
      local_28.x = 0x1000;
      local_28.y = 0;
      local_28.z = 0;
      goto LAB_80066e10;
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
      goto LAB_80066e10;
    }
  }
  else {
    if (iVar3 != 0x61) {
      if (0x61 < iVar3) {
        if (iVar3 != 0x62) goto LAB_80066e10;
        bVar1 = true;
        goto LAB_80066dfc;
      }
      if (iVar3 != 0x60) goto LAB_80066e10;
      bVar1 = true;
      goto LAB_80066dcc;
    }
    bVar1 = true;
  }
  local_28.x = 0;
  local_28.y = 0x1000;
  local_28.z = 0;
LAB_80066e10:
  if (iVar3 != -1) {
    iVar3 = PHYSOBS_CheckObjectAxisAlignment(&MStack104,&MStack72,&local_28);
    if (bVar1) {
      uVar4 = trueValue;
      if ((0x100 < iVar3 - 0xf80U) && (0x100 < iVar3 + 0x1080U)) {
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
 // line 4965, offset 0x80066e94
	/* begin block 1 */
		// Start line: 4966
		// Start offset: 0x80066E94
		// Variables:
	// 		long retValue; // $s4
	// 		long d; // $s0
	// 		struct StackType operand1; // stack offset -96
	// 		char objectName[16]; // stack offset -56
	// 		char *temp; // $v0
	// 		struct _Instance *instance; // $s2
	// 		long areaID; // $s5
	/* end block 1 */
	// End offset: 0x80067060
	// End Line: 5031

	/* begin block 2 */
		// Start line: 10521
	/* end block 2 */
	// End Line: 10522

	/* begin block 3 */
		// Start line: 10528
	/* end block 3 */
	// End Line: 10529

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
 // line 5035, offset 0x80067094
	/* begin block 1 */
		// Start line: 5036
		// Start offset: 0x80067094
		// Variables:
	// 		long i; // $s4
	// 		long retValue; // $s5
	// 		long d; // $s0
	// 		struct StackType operand1; // stack offset -80
	/* end block 1 */
	// End offset: 0x80067208
	// End Line: 5069

	/* begin block 2 */
		// Start line: 10672
	/* end block 2 */
	// End Line: 10673

	/* begin block 3 */
		// Start line: 10676
	/* end block 3 */
	// End Line: 10677

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
// long /*$ra*/ EVENT_CompareOperandsWithOperation(struct _PCodeStack *stack /*$a0*/, struct StackType *operand1 /*$t0*/, struct StackType *operand2 /*$s4*/, long operation /*$s3*/)
 // line 5072, offset 0x8006723c
	/* begin block 1 */
		// Start line: 5073
		// Start offset: 0x8006723C
		// Variables:
	// 		long number; // $s1
	// 		long number1; // $s0
	// 		long number2; // $a0
	// 		long error; // stack offset -32
	// 		long trueValue; // $s2
	// 		short flags1; // stack offset -28
	// 		short flags2; // stack offset -26
	/* end block 1 */
	// End offset: 0x80067548
	// End Line: 5276

	/* begin block 2 */
		// Start line: 10775
	/* end block 2 */
	// End Line: 10776

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
        goto LAB_800674c8;
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
               (short)((uint)(iVar4 * 0x10000) >> 0x10),z);
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
switchD_80067450_caseD_6:
      uVar5 = trueValue;
      trueValue = (uint)((int)uVar2 < (int)uVar1);
      goto LAB_800674c8;
    case 7:
switchD_80067450_caseD_7:
      uVar5 = trueValue;
      trueValue = (uint)((int)uVar1 < (int)uVar2);
      goto LAB_800674c8;
    case 8:
      trueValue = 0;
      goto switchD_80067450_caseD_7;
    case 9:
      trueValue = 0;
      goto switchD_80067450_caseD_6;
    case 10:
switchD_80067450_caseD_a:
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
      goto switchD_80067450_caseD_a;
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
    goto LAB_800674c8;
  case 0x16:
    trueValue = EVENT_CompareSubListWithOperation
                          (stack,(SubListObject *)operand1->data,operand2,operation);
    uVar5 = 1;
LAB_800674c8:
    if (trueValue == 0) {
      uVar5 = uVar5 ^ 1;
    }
  }
  return uVar5;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_DoStackMathOperation(struct _PCodeStack *stack /*$s0*/, long operation /*$a3*/)
 // line 5282, offset 0x8006756c
	/* begin block 1 */
		// Start line: 5283
		// Start offset: 0x8006756C
		// Variables:
	// 		struct StackType operand1; // stack offset -128
	// 		struct StackType operand2; // stack offset -88

		/* begin block 1.1 */
			// Start line: 5301
			// Start offset: 0x80067658
			// Variables:
		// 		struct StackType holdOperand; // stack offset -48
		/* end block 1.1 */
		// End offset: 0x80067724
		// End Line: 5306
	/* end block 1 */
	// End offset: 0x80067724
	// End Line: 5308

	/* begin block 2 */
		// Start line: 11208
	/* end block 2 */
	// End Line: 11209

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
 // line 5312, offset 0x80067754
	/* begin block 1 */
		// Start line: 5313
		// Start offset: 0x80067754
		// Variables:
	// 		short pcode; // $v0
	/* end block 1 */
	// End offset: 0x800679B0
	// End Line: 5429

	/* begin block 2 */
		// Start line: 11272
	/* end block 2 */
	// End Line: 11273

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
    goto switchD_800677a8_caseD_2;
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
    goto LAB_800678e8;
  case 0x11:
    EVENT_StackDuplicate(stack);
    EVENT_AddNumberToStack(stack,1,0);
    operation = 2;
LAB_800678e8:
    EVENT_DoStackMathOperation(stack,operation);
switchD_800677a8_caseD_2:
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
 // line 5433, offset 0x800679d0
	/* begin block 1 */
		// Start line: 5435
		// Start offset: 0x800679D0
		// Variables:
	// 		long value; // $a1
	// 		long trueValue; // $a2
	/* end block 1 */
	// End offset: 0x80067A5C
	// End Line: 5504

	/* begin block 2 */
		// Start line: 11520
	/* end block 2 */
	// End Line: 11521

	/* begin block 3 */
		// Start line: 11521
	/* end block 3 */
	// End Line: 11522

	/* begin block 4 */
		// Start line: 11526
	/* end block 4 */
	// End Line: 11527

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
    uVar2 = 0;
    break;
  case 0xb:
    uVar1 = 0;
  case 10:
    uVar2 = uVar1;
    uVar1 = introObject->intro->flags & 0x80;
    goto LAB_80067a48;
  case 0x14:
  case 0x15:
    uVar2 = 0xffffffff;
    break;
  case 0x92:
    uVar2 = 1;
    uVar1 = introObject->intro->flags & 8;
LAB_80067a48:
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
 // line 5507, offset 0x80067a64
	/* begin block 1 */
		// Start line: 5508
		// Start offset: 0x80067A64
		// Variables:
	// 		long i; // $s2
	// 		long d; // $s0
	// 		struct StackType operand1; // stack offset -72
	/* end block 1 */
	// End offset: 0x80067B34
	// End Line: 5527

	/* begin block 2 */
		// Start line: 11676
	/* end block 2 */
	// End Line: 11677

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
 // line 5530, offset 0x80067b5c
	/* begin block 1 */
		// Start line: 5531
		// Start offset: 0x80067B5C
		// Variables:
	// 		long value; // $s0
	// 		struct _Instance *instance; // $a0
	/* end block 1 */
	// End offset: 0x80067CBC
	// End Line: 5665

	/* begin block 2 */
		// Start line: 11737
	/* end block 2 */
	// End Line: 11738

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
    goto switchD_80067b98_caseD_5;
  case 10:
  case 0x34:
    uVar2 = (ulong)((Inst->flags & 0x800U) != 0);
    break;
  case 0xb:
    uVar2 = (ulong)((Inst->flags & 0x800U) == 0);
    break;
  case 0x10:
    Query = 10;
    goto LAB_80067c88;
  case 0x14:
    uVar2 = INSTANCE_Query(Inst,0xb);
    uVar1 = uVar2 >> 1;
    goto LAB_80067bcc;
  case 0x15:
    uVar1 = INSTANCE_Query(Inst,0xb);
LAB_80067bcc:
    uVar2 = uVar1 & 1;
    Query = STREAM_IsMorphInProgress();
    if (Query != 0) {
switchD_80067b98_caseD_5:
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
    goto LAB_80067c88;
  case 0x27:
    Query = 0x1a;
LAB_80067c88:
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
 // line 5668, offset 0x80067cd4
	/* begin block 1 */
		// Start line: 5669
		// Start offset: 0x80067CD4
	/* end block 1 */
	// End offset: 0x80067CD4
	// End Line: 5669

	/* begin block 2 */
		// Start line: 12016
	/* end block 2 */
	// End Line: 12017

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
 // line 5681, offset 0x80067d18
	/* begin block 1 */
		// Start line: 5682
		// Start offset: 0x80067D18
		// Variables:
	// 		long value; // $a1
	// 		struct _Instance *instance; // $a0

		/* begin block 1.1 */
			// Start line: 5731
			// Start offset: 0x80067DC4
			// Variables:
		// 		struct MultiSpline *spline; // $v0
		/* end block 1.1 */
		// End offset: 0x80067E04
		// End Line: 5750
	/* end block 1 */
	// End offset: 0x80067E04
	// End Line: 5757

	/* begin block 2 */
		// Start line: 12042
	/* end block 2 */
	// End Line: 12043

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
 // line 5761, offset 0x80067e14
	/* begin block 1 */
		// Start line: 5763
		// Start offset: 0x80067E14
		// Variables:
	// 		long value; // $a1
	// 		long trueValue; // $a2
	// 		struct _Instance *instance; // $a3

		/* begin block 1.1 */
			// Start line: 5791
			// Start offset: 0x80067E80
			// Variables:
		// 		struct AniTexInfo *ani_tex_info; // $a0
		/* end block 1.1 */
		// End offset: 0x80067E80
		// End Line: 5792
	/* end block 1 */
	// End offset: 0x80067EB8
	// End Line: 5810

	/* begin block 2 */
		// Start line: 12205
	/* end block 2 */
	// End Line: 12206

	/* begin block 3 */
		// Start line: 12206
	/* end block 3 */
	// End Line: 12207

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
 // line 5814, offset 0x80067ec4
	/* begin block 1 */
		// Start line: 5815
		// Start offset: 0x80067EC4
		// Variables:
	// 		long value; // $a1
	// 		struct _Instance *instance; // $a0
	/* end block 1 */
	// End offset: 0x80067F2C
	// End Line: 5854

	/* begin block 2 */
		// Start line: 12314
	/* end block 2 */
	// End Line: 12315

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
    goto LAB_80067f20;
  case 0x1e:
    Query = 0x11;
LAB_80067f20:
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
 // line 5859, offset 0x80067f3c
	/* begin block 1 */
		// Start line: 5860
		// Start offset: 0x80067F3C
		// Variables:
	// 		long retValue; // $v0
	/* end block 1 */
	// End offset: 0x80067F80
	// End Line: 5875

	/* begin block 2 */
		// Start line: 12408
	/* end block 2 */
	// End Line: 12409

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
 // line 5879, offset 0x80067f90
	/* begin block 1 */
		// Start line: 5881
		// Start offset: 0x80067F90
		// Variables:
	// 		long d; // $t3
	// 		long d2; // $t1
	// 		struct Event *curEvent; // $a3
	/* end block 1 */
	// End offset: 0x80068164
	// End Line: 5920

	/* begin block 2 */
		// Start line: 12448
	/* end block 2 */
	// End Line: 12449

	/* begin block 3 */
		// Start line: 12449
	/* end block 3 */
	// End Line: 12450

	/* begin block 4 */
		// Start line: 12452
	/* end block 4 */
	// End Line: 12453

void EVENT_UpdatePuzzlePointers(EventPointers *events,long offset)

{
  _func_4438 *p_Var1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  EventPointers *pEVar7;
  int iVar8;
  
  if ((events != (EventPointers *)0x0) && (iVar8 = 0, pEVar7 = events, 0 < events->numPuzzles)) {
    do {
      p_Var1 = (_func_4438 *)0x0;
      if (pEVar7->eventInstances[0] != (_func_4438 *)0x0) {
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
      if (p_Var1[4] != (_func_4438)0x0) {
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
// void /*$ra*/ EVENT_SaveEventsFromLevel(long levelID /*$s3*/, struct Level *level /*$a1*/)
 // line 5924, offset 0x8006816c
	/* begin block 1 */
		// Start line: 5925
		// Start offset: 0x8006816C
		// Variables:
	// 		struct EventPointers *eventPointers; // $s2
	// 		struct Event *eventInstance; // $s0
	// 		long i; // $s1
	// 		long d; // $a1
	// 		long saveEvent; // $a0
	// 		struct SavedEvent *savedEvent; // $a0
	/* end block 1 */
	// End offset: 0x80068284
	// End Line: 5980

	/* begin block 2 */
		// Start line: 12573
	/* end block 2 */
	// End Line: 12574

void EVENT_SaveEventsFromLevel(long levelID,Level *level)

{
  bool bVar1;
  SavedEvent *savedBlock;
  short *psVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  EventPointers *pEVar6;
  
  pEVar6 = level->PuzzleInstances;
  if ((pEVar6 != (EventPointers *)0x0) && (iVar5 = 0, 0 < pEVar6->numPuzzles)) {
    do {
      bVar1 = false;
      psVar3 = (short *)pEVar6->eventInstances[iVar5];
      iVar4 = 0;
      psVar2 = psVar3;
      do {
        iVar4 = iVar4 + 1;
        if (psVar2[3] != 0) {
          bVar1 = true;
          break;
        }
        psVar2 = psVar2 + 1;
      } while (iVar4 < 5);
      if (bVar1) {
        savedBlock = SAVE_GetSavedEvent(levelID,(int)*psVar3);
        if (savedBlock == (SavedEvent *)0x0) {
          savedBlock = (SavedEvent *)SAVE_GetSavedBlock(2,0);
        }
        *(undefined2 *)savedBlock = 2;
        *(long *)&savedBlock->eventNumber = levelID;
        iVar4 = 0;
        savedBlock->eventVariables[1] = *psVar3;
        do {
          psVar2 = psVar3 + 3;
          psVar3 = psVar3 + 1;
          iVar4 = iVar4 + 1;
          savedBlock->eventVariables[2] = *psVar2;
          savedBlock = (SavedEvent *)&savedBlock->areaID;
        } while (iVar4 < 5);
      }
      else {
        savedBlock = SAVE_GetSavedEvent(levelID,(int)*psVar3);
        if (savedBlock != (SavedEvent *)0x0) {
          SAVE_DeleteBlock((SavedBasic *)savedBlock);
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < pEVar6->numPuzzles);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_LoadEventsForLevel(long levelID /*$s1*/, struct Level *level /*$a1*/)
 // line 5983, offset 0x800682a0
	/* begin block 1 */
		// Start line: 5984
		// Start offset: 0x800682A0
		// Variables:
	// 		long d; // $a0
	// 		struct EventPointers *eventPointers; // $s0
	// 		struct Event *eventInstance; // $a3
	// 		struct SavedEvent *savedEvent; // $a1
	/* end block 1 */
	// End offset: 0x8006835C
	// End Line: 6028

	/* begin block 2 */
		// Start line: 12767
	/* end block 2 */
	// End Line: 12768

void EVENT_LoadEventsForLevel(long levelID,Level *level)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  SavedEvent *curSave;
  EventPointers *pEVar4;
  SavedEvent *pSVar5;
  EventPointers *pEVar6;
  
  pEVar6 = level->PuzzleInstances;
  if (pEVar6 != (EventPointers *)0x0) {
    curSave = (SavedEvent *)0x0;
    while (curSave = SAVE_GetSavedNextEvent(levelID,(SavedBasic *)curSave),
          curSave != (SavedEvent *)0x0) {
      iVar1 = pEVar6->numPuzzles;
      if (iVar1 != 0) {
        iVar3 = 0;
        psVar2 = (short *)0x0;
        if (0 < iVar1) {
          pEVar4 = pEVar6;
          do {
            psVar2 = (short *)pEVar4->eventInstances[0];
            iVar3 = iVar3 + 1;
            if (*psVar2 == curSave->eventVariables[1]) break;
            pEVar4 = (EventPointers *)pEVar4->eventInstances;
            psVar2 = (short *)0x0;
          } while (iVar3 < iVar1);
        }
        iVar1 = 0;
        pSVar5 = curSave;
        if (psVar2 != (short *)0x0) {
          do {
            iVar1 = iVar1 + 1;
            psVar2[3] = pSVar5->eventVariables[2];
            psVar2 = psVar2 + 1;
            pSVar5 = (SavedEvent *)&pSVar5->areaID;
          } while (iVar1 < 5);
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// struct SavedEvent * /*$ra*/ EVENT_CreateSaveEvent(long levelID /*$s0*/, long eventNumber /*$s1*/)
 // line 6031, offset 0x80068370
	/* begin block 1 */
		// Start line: 6032
		// Start offset: 0x80068370
		// Variables:
	// 		struct SavedEvent *savedEvent; // $a1
	// 		long d; // $a0
	/* end block 1 */
	// End offset: 0x800683C4
	// End Line: 6053

	/* begin block 2 */
		// Start line: 12878
	/* end block 2 */
	// End Line: 12879

SavedEvent * EVENT_CreateSaveEvent(long levelID,long eventNumber)

{
  SavedEvent *pSVar1;
  short *psVar2;
  int iVar3;
  
  pSVar1 = (SavedEvent *)SAVE_GetSavedBlock(2,0);
  if (pSVar1 != (SavedEvent *)0x0) {
    iVar3 = 4;
    psVar2 = pSVar1->eventVariables + 1;
    *(undefined2 *)pSVar1 = 2;
    *(long *)&pSVar1->eventNumber = levelID;
    pSVar1->eventVariables[1] = (short)eventNumber;
    do {
      psVar2[5] = 0;
      iVar3 = iVar3 + -1;
      psVar2 = psVar2 + -1;
    } while (-1 < iVar3);
  }
  return pSVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_RemoveInstanceFromInstanceList(struct _Instance *instance /*$a0*/)
 // line 6057, offset 0x800683dc
	/* begin block 1 */
		// Start line: 6059
		// Start offset: 0x800683DC
		// Variables:
	// 		int d; // $t3
	// 		int i; // $t0
	// 		int i2; // $a1
	// 		struct EventPointers *puzzle; // $t2
	// 		struct EventBasicObject **basicEventObject; // $v0
	/* end block 1 */
	// End offset: 0x800684C0
	// End Line: 6090

	/* begin block 2 */
		// Start line: 12940
	/* end block 2 */
	// End Line: 12941

	/* begin block 3 */
		// Start line: 12941
	/* end block 3 */
	// End Line: 12942

	/* begin block 4 */
		// Start line: 12946
	/* end block 4 */
	// End Line: 12947

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
 // line 6093, offset 0x800684c8
	/* begin block 1 */
		// Start line: 6095
		// Start offset: 0x800684C8
		// Variables:
	// 		int i; // $t2
	// 		int i2; // $t0
	// 		struct EventBasicObject **basicEventObject; // $v0
	/* end block 1 */
	// End offset: 0x80068564
	// End Line: 6117

	/* begin block 2 */
		// Start line: 13031
	/* end block 2 */
	// End Line: 13032

	/* begin block 3 */
		// Start line: 13032
	/* end block 3 */
	// End Line: 13033

	/* begin block 4 */
		// Start line: 13036
	/* end block 4 */
	// End Line: 13037

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
 // line 6119, offset 0x8006856c
	/* begin block 1 */
		// Start line: 6120
		// Start offset: 0x8006856C
		// Variables:
	// 		int d; // $s1
	// 		int curTree; // $a1
	// 		struct EventPointers *puzzle; // $a0
	// 		struct Level *level; // $s0

		/* begin block 1.1 */
			// Start line: 6139
			// Start offset: 0x800685E4
			// Variables:
		// 		struct BSPTree *bspTree; // $a0
		/* end block 1.1 */
		// End offset: 0x80068618
		// End Line: 6149
	/* end block 1 */
	// End offset: 0x80068644
	// End Line: 6152

	/* begin block 2 */
		// Start line: 13097
	/* end block 2 */
	// End Line: 13098

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
      if (0 < (int)p_Var1->morphNormalIdx) {
        iVar4 = 0;
        do {
          iVar2 = (int)&p_Var1->signals->numSignals + iVar4;
          if ((-1 < *(short *)(iVar2 + 0x1a)) && (*(int *)(iVar2 + 0x1c) == instance->introUniqueID)
             ) {
            *(_Instance **)(iVar2 + 0x20) = instance;
          }
          p_Var1 = pLVar5->terrain;
          iVar3 = iVar3 + 1;
          iVar4 = iVar4 + 0x24;
        } while (iVar3 < (int)p_Var1->morphNormalIdx);
      }
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// struct _VMObject * /*$ra*/ EVENT_FindVMObject(struct _StreamUnit *stream /*$a0*/, char *vmoName /*$s4*/)
 // line 6154, offset 0x8006865c
	/* begin block 1 */
		// Start line: 6155
		// Start offset: 0x8006865C
		// Variables:
	// 		int i; // $s2
	// 		struct _VMObject *vmObject; // $s3
	// 		struct Level *level; // $s1
	/* end block 1 */
	// End offset: 0x800686D8
	// End Line: 6174

	/* begin block 2 */
		// Start line: 13196
	/* end block 2 */
	// End Line: 13197

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
 // line 6177, offset 0x800686fc
	/* begin block 1 */
		// Start line: 6178
		// Start offset: 0x800686FC
		// Variables:
	// 		struct EventPointers *puzzle; // $s5
	// 		struct EventBasicObject **basicEventObject; // $s6
	// 		struct _Instance *instance; // $a1
	// 		struct _Instance *next; // $s0
	// 		int i; // $s4
	// 		int i2; // $s2
	// 		int p; // $a2

		/* begin block 1.1 */
			// Start line: 6205
			// Start offset: 0x800687AC
			// Variables:
		// 		struct _StreamUnit *newStream; // $v0
		/* end block 1.1 */
		// End offset: 0x800687C0
		// End Line: 6213

		/* begin block 1.2 */
			// Start line: 6220
			// Start offset: 0x800687D0
			// Variables:
		// 		struct EventEventObject *eventEventObject; // $s1
		// 		struct _StreamUnit *newStream; // $v0

			/* begin block 1.2.1 */
				// Start line: 6227
				// Start offset: 0x800687E4
				// Variables:
			// 		struct EventPointers *puzzleInstances; // $v1
			/* end block 1.2.1 */
			// End offset: 0x8006883C
			// End Line: 6244
		/* end block 1.2 */
		// End offset: 0x8006883C
		// End Line: 6245

		/* begin block 1.3 */
			// Start line: 6250
			// Start offset: 0x8006884C
			// Variables:
		// 		struct EventTGroupObject *tgroupEventObject; // $s1
		// 		struct _StreamUnit *newStream; // $v0

			/* begin block 1.3.1 */
				// Start line: 6255
				// Start offset: 0x80068860
				// Variables:
			// 		struct _Terrain *terrain; // $v0
			/* end block 1.3.1 */
			// End offset: 0x800688B0
			// End Line: 6277
		/* end block 1.3 */
		// End offset: 0x800688B0
		// End Line: 6278

		/* begin block 1.4 */
			// Start line: 6283
			// Start offset: 0x800688C0
			// Variables:
		// 		struct _StreamUnit *newStream; // $v0
		/* end block 1.4 */
		// End offset: 0x800688D4
		// End Line: 6291

		/* begin block 1.5 */
			// Start line: 6300
			// Start offset: 0x800688F0
			// Variables:
		// 		void *pointer; // $v1

			/* begin block 1.5.1 */
				// Start line: 6310
				// Start offset: 0x8006890C
				// Variables:
			// 		struct _StreamUnit *stream2; // $v0
			/* end block 1.5.1 */
			// End offset: 0x80068934
			// End Line: 6318
		/* end block 1.5 */
		// End offset: 0x80068934
		// End Line: 6318

		/* begin block 1.6 */
			// Start line: 6328
			// Start offset: 0x80068964
			// Variables:
		// 		struct _StreamUnit *newStream; // $v0
		/* end block 1.6 */
		// End offset: 0x80068984
		// End Line: 6339
	/* end block 1 */
	// End offset: 0x800689B4
	// End Line: 6348

	/* begin block 2 */
		// Start line: 13247
	/* end block 2 */
	// End Line: 13248

void EVENT_FixPuzzlesForStream(_StreamUnit *stream)

{
  short sVar1;
  long *plVar2;
  int iVar3;
  _StreamUnit *stream_00;
  _Terrain *p_Var4;
  Intro *pIVar5;
  _SFXMkr *p_Var6;
  _VMObject *p_Var7;
  EventPointers *pEVar8;
  short *psVar9;
  _Instance *instance;
  _MultiSignal *p_Var10;
  _Instance *p_Var11;
  EventInstanceObject *instanceObject;
  int iVar12;
  EventPointers *pEVar13;
  int iVar14;
  EventPointers *puzzle;
  int iVar15;
  
  puzzle = stream->level->PuzzleInstances;
  instance = (gameTrackerX.instanceList)->first;
  if (puzzle != (EventPointers *)0x0) {
    while (instance != (_Instance *)0x0) {
      p_Var11 = instance->next;
      EVENT_UpdatePuzzleWithInstance(puzzle,instance);
      instance = p_Var11;
    }
    iVar14 = 0;
    pEVar13 = puzzle;
    if (0 < puzzle->numPuzzles) {
      do {
        iVar15 = *(int *)(pEVar13->eventInstances[0] + 0x10);
        iVar12 = 0;
        if (0 < *(short *)(pEVar13->eventInstances[0] + 2)) {
          iVar3 = 0;
          do {
            instanceObject = *(EventInstanceObject **)(iVar3 + iVar15);
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
                   (pEVar8 = stream_00->level->PuzzleInstances, pEVar8 != (EventPointers *)0x0)) {
                  plVar2 = &pEVar8->numPuzzles;
                  iVar3 = 0;
                  if (0 < *plVar2) {
                    do {
                      iVar3 = iVar3 + 1;
                      if (*(short *)pEVar8->eventInstances[0] == instanceObject->flags) {
                        *(_func_4438 **)&instanceObject->introUniqueID = pEVar8->eventInstances[0];
                        break;
                      }
                      pEVar8 = (EventPointers *)pEVar8->eventInstances;
                    } while (iVar3 < *plVar2);
                  }
                }
              }
              else {
                if (sVar1 == 4) {
                  stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID);
                  if (stream_00 != (_StreamUnit *)0x0) {
                    p_Var4 = stream_00->level->terrain;
                    psVar9 = p_Var4->morphNormalIdx;
                    iVar3 = 0;
                    if (0 < (int)psVar9) {
                      p_Var10 = p_Var4->signals;
                      do {
                        iVar3 = iVar3 + 1;
                        if (*(short *)(p_Var10->signalList[0].data + 0xe) == instanceObject->flags)
                        {
                          *(_MultiSignal **)&instanceObject->introUniqueID = p_Var10;
                          *(_StreamUnit **)&instanceObject->instance = stream;
                          break;
                        }
                        p_Var10 = (_MultiSignal *)(p_Var10->signalList + 1);
                      } while (iVar3 < (int)psVar9);
                    }
                  }
                }
                else {
                  if (sVar1 == 6) {
                    stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID);
                    if (stream_00 != (_StreamUnit *)0x0) {
                      p_Var10 = EVENT_ResolveObjectSignal(stream_00,(int)instanceObject->flags);
                      *(_MultiSignal **)&instanceObject->introUniqueID = p_Var10;
                    }
                  }
                  else {
                    if (sVar1 == 1) {
                      pIVar5 = EVENT_ResolveObjectIntro(instanceObject);
                      if (pIVar5 == (Intro *)0x0) {
                        stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID);
                        if ((stream_00 != (_StreamUnit *)0x0) &&
                           (p_Var6 = EVENT_ResolveSFXMarker(stream_00,instanceObject),
                           p_Var6 != (_SFXMkr *)0x0)) {
                          *(_SFXMkr **)&instanceObject->data = p_Var6;
                          instanceObject->flags = instanceObject->flags | 1;
                        }
                      }
                      else {
                        *(Intro **)&instanceObject->data = pIVar5;
                      }
                    }
                    else {
                      if ((sVar1 == 7) &&
                         (stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID),
                         stream_00 != (_StreamUnit *)0x0)) {
                        p_Var7 = EVENT_FindVMObject(stream_00,(char *)&instanceObject->introUniqueID
                                                   );
                        *(_VMObject **)(instanceObject + 1) = p_Var7;
                      }
                    }
                  }
                }
              }
            }
            iVar12 = iVar12 + 1;
            iVar3 = iVar12 * 4;
          } while (iVar12 < *(short *)(pEVar13->eventInstances[0] + 2));
        }
        iVar14 = iVar14 + 1;
        pEVar13 = (EventPointers *)pEVar13->eventInstances;
      } while (iVar14 < puzzle->numPuzzles);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_AddStreamToInstanceList(struct _StreamUnit *stream /*$s1*/)
 // line 6350, offset 0x800689e0
	/* begin block 1 */
		// Start line: 6351
		// Start offset: 0x800689E0
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
			// Start line: 6388
			// Start offset: 0x80068ACC
			// Variables:
		// 		struct EventPointers *puzzleInstances; // $v1
		/* end block 1.1 */
		// End offset: 0x80068B24
		// End Line: 6406

		/* begin block 1.2 */
			// Start line: 6413
			// Start offset: 0x80068B48
			// Variables:
		// 		struct _Terrain *terrain; // $v0
		/* end block 1.2 */
		// End offset: 0x80068B98
		// End Line: 6437

		/* begin block 1.3 */
			// Start line: 6443
			// Start offset: 0x80068BA8
		/* end block 1.3 */
		// End offset: 0x80068BBC
		// End Line: 6448

		/* begin block 1.4 */
			// Start line: 6457
			// Start offset: 0x80068BD8
			// Variables:
		// 		void *pointer; // $v1
		/* end block 1.4 */
		// End offset: 0x80068C08
		// End Line: 6471

		/* begin block 1.5 */
			// Start line: 6480
			// Start offset: 0x80068C38
		/* end block 1.5 */
		// End offset: 0x80068C58
		// End Line: 6489
	/* end block 1 */
	// End offset: 0x80068C98
	// End Line: 6501

	/* begin block 2 */
		// Start line: 13842
	/* end block 2 */
	// End Line: 13843

void EVENT_AddStreamToInstanceList(_StreamUnit *stream)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  _Terrain *p_Var4;
  Intro *pIVar5;
  _SFXMkr *p_Var6;
  _VMObject *p_Var7;
  int iVar8;
  EventPointers *pEVar9;
  short *psVar10;
  _MultiSignal *p_Var11;
  EventInstanceObject *instanceObject;
  int iVar12;
  int *piVar13;
  int *piVar14;
  int iVar15;
  int iVar16;
  
  iVar15 = 0;
  iVar8 = 0;
  do {
    if (((*(short *)((int)&StreamTracker.StreamList[0].used + iVar8) == 2) &&
        (piVar14 = *(int **)(*(int *)((int)&StreamTracker.StreamList[0].level + iVar8) + 0xdc),
        piVar14 != (int *)0x0)) && (iVar8 = 0, piVar13 = piVar14, 0 < *piVar14)) {
      do {
        iVar16 = *(int *)(piVar13[1] + 0x10);
        iVar12 = 0;
        if (0 < *(short *)(piVar13[1] + 2)) {
          iVar3 = 0;
          do {
            instanceObject = *(EventInstanceObject **)(iVar3 + iVar16);
            sVar1 = instanceObject->id;
            if (sVar1 == 5) {
              if (instanceObject->unitID == stream->StreamUnitID) {
                *(_StreamUnit **)&instanceObject->introUniqueID = stream;
              }
            }
            else {
              if (sVar1 == 3) {
                if ((instanceObject->unitID == stream->StreamUnitID) &&
                   (pEVar9 = stream->level->PuzzleInstances, pEVar9 != (EventPointers *)0x0)) {
                  piVar2 = &pEVar9->numPuzzles;
                  iVar3 = 0;
                  if (0 < *piVar2) {
                    do {
                      iVar3 = iVar3 + 1;
                      if (*(short *)pEVar9->eventInstances[0] == instanceObject->flags) {
                        *(_func_4438 **)&instanceObject->introUniqueID = pEVar9->eventInstances[0];
                        break;
                      }
                      pEVar9 = (EventPointers *)pEVar9->eventInstances;
                    } while (iVar3 < *piVar2);
                  }
                }
              }
              else {
                if (sVar1 == 4) {
                  if (instanceObject->unitID == stream->StreamUnitID) {
                    p_Var4 = stream->level->terrain;
                    psVar10 = p_Var4->morphNormalIdx;
                    iVar3 = 0;
                    if (0 < (int)psVar10) {
                      p_Var11 = p_Var4->signals;
                      do {
                        iVar3 = iVar3 + 1;
                        if (*(short *)(p_Var11->signalList[0].data + 0xe) == instanceObject->flags)
                        {
                          *(_MultiSignal **)&instanceObject->introUniqueID = p_Var11;
                          *(_StreamUnit **)&instanceObject->instance = stream;
                          break;
                        }
                        p_Var11 = (_MultiSignal *)(p_Var11->signalList + 1);
                      } while (iVar3 < (int)psVar10);
                    }
                  }
                }
                else {
                  if (sVar1 == 6) {
                    if (instanceObject->unitID == stream->StreamUnitID) {
                      p_Var11 = EVENT_ResolveObjectSignal(stream,(int)instanceObject->flags);
                      *(_MultiSignal **)&instanceObject->introUniqueID = p_Var11;
                    }
                  }
                  else {
                    if (sVar1 == 1) {
                      pIVar5 = EVENT_ResolveObjectIntro(instanceObject);
                      if (pIVar5 == (Intro *)0x0) {
                        p_Var6 = EVENT_ResolveSFXMarker(stream,instanceObject);
                        if (p_Var6 != (_SFXMkr *)0x0) {
                          *(_SFXMkr **)&instanceObject->data = p_Var6;
                          instanceObject->flags = instanceObject->flags | 1;
                        }
                      }
                      else {
                        *(Intro **)&instanceObject->data = pIVar5;
                      }
                    }
                    else {
                      if ((sVar1 == 7) && (stream->StreamUnitID == instanceObject->unitID)) {
                        p_Var7 = EVENT_FindVMObject(stream,(char *)&instanceObject->introUniqueID);
                        *(_VMObject **)(instanceObject + 1) = p_Var7;
                      }
                    }
                  }
                }
              }
            }
            iVar12 = iVar12 + 1;
            iVar3 = iVar12 * 4;
          } while (iVar12 < *(short *)(piVar13[1] + 2));
        }
        iVar8 = iVar8 + 1;
        piVar13 = piVar13 + 1;
      } while (iVar8 < *piVar14);
    }
    iVar15 = iVar15 + 1;
    iVar8 = iVar15 * 0x40;
    if (0xf < iVar15) {
      EVENT_FixPuzzlesForStream(stream);
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_RemoveStreamToInstanceList(struct _StreamUnit *stream /*$s2*/)
 // line 6505, offset 0x80068ccc
	/* begin block 1 */
		// Start line: 6506
		// Start offset: 0x80068CCC
		// Variables:
	// 		int d; // $t1
	// 		int i; // $s1
	// 		int i2; // $a1
	// 		struct EventPointers *puzzle; // $t0
	// 		struct EventBasicObject **basicEventObject; // $v0

		/* begin block 1.1 */
			// Start line: 6561
			// Start offset: 0x80068DB8
		/* end block 1.1 */
		// End offset: 0x80068DCC
		// End Line: 6566

		/* begin block 1.2 */
			// Start line: 6573
			// Start offset: 0x80068DDC
		/* end block 1.2 */
		// End offset: 0x80068DF4
		// End Line: 6582
	/* end block 1 */
	// End offset: 0x80068E80
	// End Line: 6603

	/* begin block 2 */
		// Start line: 14374
	/* end block 2 */
	// End Line: 14375

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
LAB_80068db8:
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
                if (sVar1 == 6) goto LAB_80068db8;
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
      } while (iVar3 < 0x10);
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_RelocateInstanceList(struct Level *oldLevel /*$a0*/, struct Level *newLevel /*$a1*/, long sizeOfLevel /*$a2*/)
 // line 6607, offset 0x80068e98
	/* begin block 1 */
		// Start line: 6609
		// Start offset: 0x80068E98
		// Variables:
	// 		int d; // $t6
	// 		int i; // $t4
	// 		int i2; // $a3
	// 		struct EventPointers *puzzle; // $t5
	// 		struct EventBasicObject **basicEventObject; // $v0
	// 		long offset; // $t0

		/* begin block 1.1 */
			// Start line: 6629
			// Start offset: 0x80068F28
		/* end block 1.1 */
		// End offset: 0x80068F28
		// End Line: 6634

		/* begin block 1.2 */
			// Start line: 6641
			// Start offset: 0x80068F30
		/* end block 1.2 */
		// End offset: 0x80068F30
		// End Line: 6646

		/* begin block 1.3 */
			// Start line: 6653
			// Start offset: 0x80068F38
		/* end block 1.3 */
		// End offset: 0x80068F60
		// End Line: 6658

		/* begin block 1.4 */
			// Start line: 6665
			// Start offset: 0x80068F70
		/* end block 1.4 */
		// End offset: 0x80068F98
		// End Line: 6671

		/* begin block 1.5 */
			// Start line: 6678
			// Start offset: 0x80068FA8
		/* end block 1.5 */
		// End offset: 0x80068FD4
		// End Line: 6686
	/* end block 1 */
	// End offset: 0x8006909C
	// End Line: 6708

	/* begin block 2 */
		// Start line: 14660
	/* end block 2 */
	// End Line: 14661

	/* begin block 3 */
		// Start line: 14661
	/* end block 3 */
	// End Line: 14662

	/* begin block 4 */
		// Start line: 14666
	/* end block 4 */
	// End Line: 14667

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
  } while ((int)pEVar7 < -0x7ff2cf74);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_PrintVars()
 // line 6710, offset 0x800690a4
	/* begin block 1 */
		// Start line: 6711
		// Start offset: 0x800690A4
		// Variables:
	// 		int d; // $s5
	// 		int i; // $s2
	// 		int i2; // $s1
	// 		struct EventPointers *eventPointers; // $s4
	// 		struct Event *event; // $v0
	/* end block 1 */
	// End offset: 0x800691B0
	// End Line: 6740

	/* begin block 2 */
		// Start line: 14946
	/* end block 2 */
	// End Line: 14947

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EVENT_PrintVars(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  FONT_Print("Event\tvar0\tvar1\t\tvar2\tvar3\tvar4\n");
  iVar4 = 0;
  iVar1 = 0;
  do {
    if ((*(short *)((int)&StreamTracker.StreamList[0].used + iVar1) == 2) &&
       (*(int *)(*(int *)((int)&StreamTracker.StreamList[0].level + iVar1) + 0xdc) != 0)) {
      FONT_Print("level %s\n");
      piVar3 = *(int **)(*(int *)((int)&StreamTracker.StreamList[0].level + iVar1) + 0xdc);
      iVar1 = 0;
      if (0 < *piVar3) {
        do {
          iVar2 = 0;
          FONT_Print("%02d)\t\t");
          do {
            iVar2 = iVar2 + 1;
            FONT_Print("%d\t\t");
          } while (iVar2 < 5);
          FONT_Print("\n");
          iVar1 = iVar1 + 1;
        } while (iVar1 < *piVar3);
      }
    }
    iVar4 = iVar4 + 1;
    iVar1 = iVar4 * 0x40;
  } while (iVar4 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EVENT_ExecuteActionCommand(struct StackType *operand1 /*$s0*/, struct StackType *operand2 /*$a1*/, struct _PCodeStack *stack /*$a2*/, short *codeStream /*$a3*/)
 // line 6744, offset 0x800691d8
	/* begin block 1 */
		// Start line: 6745
		// Start offset: 0x800691D8
		// Variables:
	// 		long error; // stack offset -16
	// 		long value; // $a0
	// 		short flags; // stack offset -12
	/* end block 1 */
	// End offset: 0x80069364
	// End Line: 6842

	/* begin block 2 */
		// Start line: 15042
	/* end block 2 */
	// End Line: 15043

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
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_GetScalerValueFromOperand(struct StackType *operand /*$a0*/, long *error /*$a1*/, short *flags /*$a2*/)
 // line 6845, offset 0x80069374
	/* begin block 1 */
		// Start line: 6846
		// Start offset: 0x80069374
		// Variables:
	// 		long value; // $a1
	/* end block 1 */
	// End offset: 0x800694C0
	// End Line: 6939

	/* begin block 2 */
		// Start line: 15244
	/* end block 2 */
	// End Line: 15245

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
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ EVENT_TransformOperand(struct StackType *stackObject /*$t0*/, struct _PCodeStack *stack /*$a0*/, long item /*$a2*/, short *codeStream /*$a3*/)
 // line 6945, offset 0x800694d0
	/* begin block 1 */
		// Start line: 6946
		// Start offset: 0x800694D0
		// Variables:
	// 		long retValue; // $v0
	/* end block 1 */
	// End offset: 0x80069668
	// End Line: 7038

	/* begin block 2 */
		// Start line: 15451
	/* end block 2 */
	// End Line: 15452

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





