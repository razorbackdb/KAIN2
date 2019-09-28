#include "THISDUST.H"
#include "DEBUG.H"


// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_UpdateHealth(long *var /*$a0*/)
 // line 1261, offset 0x80012ec0
	/* begin block 1 */
		// Start line: 2482
	/* end block 1 */
	// End Line: 2483

	/* begin block 2 */
		// Start line: 2522
	/* end block 2 */
	// End Line: 2523

	/* begin block 3 */
		// Start line: 2483
	/* end block 3 */
	// End Line: 2484

void DEBUG_UpdateHealth(long *var)

{
  RAZIEL_DebugHealthSetScale(debugHealthLevel);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_UpdateMana(long *var /*$a0*/)
 // line 1266, offset 0x80012ee4
	/* begin block 1 */
		// Start line: 2493
	/* end block 1 */
	// End Line: 2494

	/* begin block 2 */
		// Start line: 2494
	/* end block 2 */
	// End Line: 2495

void DEBUG_UpdateMana(long *var)

{
  RAZIEL_DebugManaSetMax(debugManaLevel);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_FillUpHealth(long *var /*$a0*/)
 // line 1275, offset 0x80012f08
	/* begin block 1 */
		// Start line: 1276
		// Start offset: 0x80012F08
	/* end block 1 */
	// End offset: 0x80012F08
	// End Line: 1276

	/* begin block 2 */
		// Start line: 2512
	/* end block 2 */
	// End Line: 2513

void DEBUG_FillUpHealth(long *var)

{
  RAZIEL_DebugHealthFillUp();
  RAZIEL_DebugManaFillUp();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ process_cheat_codes(struct GameTracker *gt /*$a0*/, long *ctrl /*$a1*/)
 // line 1474, offset 0x80012f30
	/* begin block 1 */
		// Start line: 1475
		// Start offset: 0x80012F30
		// Variables:
	// 		int i; // $s0
	// 		struct GameCheat *cheat; // $a0
	// 		unsigned long padPress; // $s2
	// 		unsigned long padOn; // $s1

		/* begin block 1.1 */
			// Start line: 1487
			// Start offset: 0x80012F70
			// Variables:
		// 		int cheatTriggered; // $s3

			/* begin block 1.1.1 */
				// Start line: 1490
				// Start offset: 0x80012F84
				// Variables:
			// 		unsigned long keyMask; // $v1

				/* begin block 1.1.1.1 */
					// Start line: 1510
					// Start offset: 0x80013010
				/* end block 1.1.1.1 */
				// End offset: 0x800131AC
				// End Line: 1584
			/* end block 1.1.1 */
			// End offset: 0x800131AC
			// End Line: 1586
		/* end block 1.1 */
		// End offset: 0x800131D4
		// End Line: 1592
	/* end block 1 */
	// End offset: 0x800131D4
	// End Line: 1594

	/* begin block 2 */
		// Start line: 2948
	/* end block 2 */
	// End Line: 2949

void process_cheat_codes(GameTracker *gt,long *ctrl)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  long *var;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = *ctrl;
  uVar7 = ctrl[1];
  if (cheatCodeLastCommand != 0) {
    cheatCodeLastCommand = uVar7;
    return;
  }
  if (uVar7 == 0) {
    cheatCodeLastCommand = uVar7;
    return;
  }
  bVar2 = false;
  if ((uVar6 & 0x300) == 0) {
    cheatCodeLastCommand = uVar7;
    return;
  }
  iVar5 = 0;
  iVar3 = 0;
LAB_80012f88:
  var = (long *)(GameCheats[0].cheatKeys + iVar3);
  if ((uVar7 & CheatKeyMap
               [*(byte *)((int)var + (int)*(short *)((int)&GameCheats[0].cheatStage + iVar3))]) == 0
     ) {
    DEBUG_FillUpHealth(var);
    return;
  }
  if ((uVar6 & 0xfffffcff &
      ~CheatKeyMap[*(byte *)((int)var + (int)*(short *)((int)&GameCheats[0].cheatStage + iVar3))])
      != 0) {
    DEBUG_FillUpHealth(var);
    return;
  }
  *(short *)((int)&GameCheats[0].cheatStage + iVar3) =
       *(short *)((int)&GameCheats[0].cheatStage + iVar3) + 1;
  if (*(short *)((int)&GameCheats[0].cheatStage + iVar3) !=
      *(short *)((int)&GameCheats[0].cheatLen + iVar3)) goto switchD_80013008_caseD_17;
  *(undefined2 *)((int)&GameCheats[0].cheatStage + iVar3) = 0;
  bVar2 = true;
  switch(iVar5) {
  case 0:
    goto switchD_80013008_caseD_0;
  case 1:
    debugRazielFlags1 = debugRazielFlags1 | 0x5f;
    break;
  case 2:
    debugRazielFlags1 = debugRazielFlags1 | 0x8000;
    break;
  case 3:
    debugRazielFlags2 = debugRazielFlags2 | 0x1000;
    break;
  case 4:
    debugRazielFlags1 = debugRazielFlags1 | 0x20;
  case 9:
    debugRazielFlags1 = debugRazielFlags1 | 0x10;
    goto switchD_80013008_caseD_12;
  case 5:
    debugRazielFlags2 = debugRazielFlags2 | 0x10000;
    break;
  case 6:
    uVar4 = 0x800000;
    goto LAB_8001318c;
  case 7:
    debugManaLevel = 0xd;
    DEBUG_UpdateMana(&debugManaLevel);
    bVar1 = iVar5 + 1 < 0x17;
    goto LAB_800131b4;
  case 8:
    goto switchD_80013008_caseD_8;
  case 10:
    uVar4 = 0x80000;
    goto LAB_8001318c;
  case 0xb:
    uVar4 = 0x100000;
    goto LAB_8001318c;
  case 0xc:
    uVar4 = 0x400000;
    goto LAB_8001318c;
  case 0xd:
    DEBUG_FillUpHealth(&debugHealthLevel);
    bVar1 = iVar5 + 1 < 0x17;
    goto LAB_800131b4;
  case 0xe:
    debugHealthLevel = debugHealthLevel + 1;
    if (4 < debugHealthLevel) goto switchD_80013008_caseD_f;
    goto LAB_80013048;
  case 0xf:
switchD_80013008_caseD_f:
    debugHealthLevel = 4;
LAB_80013048:
    DEBUG_UpdateHealth(&debugHealthLevel);
    bVar1 = iVar5 + 1 < 0x17;
    goto LAB_800131b4;
  case 0x10:
    RAZIEL_DebugManaFillUp();
    bVar1 = iVar5 + 1 < 0x17;
    goto LAB_800131b4;
  case 0x11:
    goto switchD_80013008_caseD_11;
  case 0x12:
    goto switchD_80013008_caseD_12;
  case 0x13:
    RAZIEL_DebugHurtRaziel();
    bVar1 = iVar5 + 1 < 0x17;
    goto LAB_800131b4;
  case 0x14:
    debugRazielFlags2 = debugRazielFlags2 | 0x8000;
    break;
  case 0x15:
    uVar4 = 0x40000;
    goto LAB_8001318c;
  case 0x16:
    uVar4 = 0x200000;
LAB_8001318c:
    debugRazielFlags3 = debugRazielFlags3 | uVar4;
  }
switchD_80013008_caseD_17:
  bVar1 = iVar5 + 1 < 0x17;
LAB_800131b4:
  iVar5 = iVar5 + 1;
  iVar3 = iVar5 * 0x10;
  if (!bVar1) {
    if (bVar2) {
      SndPlayVolPan(0x15,0x50,0x40,0x32);
    }
    cheatCodeLastCommand = uVar7;
    return;
  }
  goto LAB_80012f88;
switchD_80013008_caseD_12:
  debugRazielFlags1 = debugRazielFlags1 | 4;
switchD_80013008_caseD_11:
  debugRazielFlags1 = debugRazielFlags1 | 2;
switchD_80013008_caseD_0:
  debugRazielFlags1 = debugRazielFlags1 | 8;
switchD_80013008_caseD_8:
  debugRazielFlags1 = debugRazielFlags1 | 1;
  goto switchD_80013008_caseD_17;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_Process(struct GameTracker *gameTracker /*$s0*/)
 // line 1601, offset 0x800131f8
	/* begin block 1 */
		// Start line: 1602
		// Start offset: 0x800131F8
		// Variables:
	// 		long *controlCommand; // $s3
	// 		long oldFlags; // $s2
	// 		long oldFlags2; // $s1
	/* end block 1 */
	// End offset: 0x80013388
	// End Line: 1666

	/* begin block 2 */
		// Start line: 3068
	/* end block 2 */
	// End Line: 3069

void DEBUG_Process(GameTracker *gameTracker)

{
  short sVar1;
  GameTracker *line;
  uint uVar2;
  uint uVar3;
  
  uVar3 = gameTracker->debugFlags;
  sVar1 = gameTracker->gameMode;
  uVar2 = gameTracker->debugFlags2;
  line = gameTracker;
  if (sVar1 == 0) {
    if ((uVar3 & 8) != 0) {
      DEBUG_ProcessSecondController(gameTracker);
    }
    if (gameTracker->cheatMode == '\x01') {
      line = gameTracker;
      DEBUG_ProcessCheat(gameTracker);
    }
    goto LAB_80013358;
  }
  if (sVar1 != 4) {
    if (sVar1 == 6) {
      process_cheat_codes(gameTracker,gameTracker->controlCommand);
      DEBUG_Menu(gameTracker);
    }
    else {
      if (sVar1 == 7) {
        DEBUG_ViewVram(gameTracker);
      }
    }
    goto LAB_80013358;
  }
  DEBUG_Menu(gameTracker);
  if ((gameTracker->debugFlags2 & 0x40000U) == 0) {
LAB_800132b0:
    if ((uVar2 & 0x40000) != 0) {
      gameTracker->debugFlags = gameTracker->debugFlags & 0xfffffff7;
    }
  }
  else {
    if ((uVar2 & 0x40000) == 0) {
      gameTracker->debugFlags = gameTracker->debugFlags | 8;
    }
    if ((gameTracker->debugFlags2 & 0x40000U) == 0) goto LAB_800132b0;
  }
  if (((gameTracker->debugFlags & 8U) != 0) && ((uVar3 & 8) == 0)) {
    DAT_800cff54 = theCamera;
    DAT_800cff56 = DAT_800cfe92;
    DAT_800cff58 = DAT_800cfe94;
    DAT_800cff5c = DAT_800cff40;
    DAT_800cff5e = DAT_800cff42;
    DAT_800cff60 = DAT_800cff44;
    line = (GameTracker *)(uint)DAT_800cfe94;
  }
LAB_80013358:
  if ((gameTracker->debugFlags & 0x4000U) == 0) {
    get_last_menu_line((DebugMenuLine *)line);
    return;
  }
  if ((gameTracker->controlCommand[1] & 0x400U) == 0) {
    get_last_menu_line((DebugMenuLine *)line);
    return;
  }
  DEBUG_CaptureScreen(gameTracker);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_Draw(struct GameTracker *gameTracker /*$a0*/, unsigned long **ot /*$a1*/)
 // line 1676, offset 0x800133a4
	/* begin block 1 */
		// Start line: 3352
	/* end block 1 */
	// End Line: 3353

void DEBUG_Draw(GameTracker *gameTracker,ulong **ot)

{
  if (((gameTracker->gameMode == 0) || (gameTracker->cheatMode == '\x01')) ||
     (gameTracker->gameMode == 4)) {
    DEBUG_DisplayStatus(gameTracker);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ DEBUG_MenuCountLength(struct DebugMenuLine *menu /*$a0*/)
 // line 1699, offset 0x800133ec
	/* begin block 1 */
		// Start line: 1701
		// Start offset: 0x800133EC
		// Variables:
	// 		int length; // $v1
	// 		struct DebugMenuLine *curLine; // $a0
	/* end block 1 */
	// End offset: 0x80013410
	// End Line: 1710

	/* begin block 2 */
		// Start line: 3260
	/* end block 2 */
	// End Line: 3261

	/* begin block 3 */
		// Start line: 3261
	/* end block 3 */
	// End Line: 3262

	/* begin block 4 */
		// Start line: 3263
	/* end block 4 */
	// End Line: 3264

long DEBUG_MenuCountLength(DebugMenuLine *menu)

{
  DEBUG_LINE_TYPE *pDVar1;
  int iVar2;
  
  iVar2 = 0;
  if (menu != (DebugMenuLine *)0x0) {
    do {
      pDVar1 = &menu->type;
      menu = menu + 1;
      if (*pDVar1 == DEBUG_LINE_TYPE_ENDLIST) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (menu != (DebugMenuLine *)0x0);
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ExitMenus()
 // line 1713, offset 0x80013418
	/* begin block 1 */
		// Start line: 1714
		// Start offset: 0x80013418
	/* end block 1 */
	// End offset: 0x800134A0
	// End Line: 1743

	/* begin block 2 */
		// Start line: 3288
	/* end block 2 */
	// End Line: 3289

	/* begin block 3 */
		// Start line: 3293
	/* end block 3 */
	// End Line: 3294

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_ExitMenus(void)

{
  long lVar1;
  
  lVar1 = DEBUG_MenuCountLength(currentMenu);
  currentMenu[lVar1].lower = debugMenuChoice;
  if (theCamera.focusSphere.position.z._1_1_ == '\0') {
    SOUND_MusicOff();
    SOUND_ShutdownMusic();
  }
  else {
    SOUND_MusicOn();
  }
  if ((char)theCamera.focusSphere.position.z == '\0') {
    SOUND_SfxOff();
  }
  else {
    SOUND_SfxOn();
  }
  return;
}



// decompiled code
// original method signature: 
// struct DebugMenuLine * /*$ra*/ get_last_menu_line(struct DebugMenuLine *line /*$a0*/)
 // line 1749, offset 0x800134b0
	/* begin block 1 */
		// Start line: 3365
	/* end block 1 */
	// End Line: 3366

	/* begin block 2 */
		// Start line: 3366
	/* end block 2 */
	// End Line: 3367

void handle_line_type_long(GameTracker *gt,DebugMenuLine *line)

{
  int iVar1;
  int *piVar2;
  
  if ((gt->gameData).asmData.drawBackFaces != 5) {
    piVar2 = &(gt->gameData).asmData.lightInstances[0].b;
    do {
      iVar1 = *piVar2;
      piVar2 = piVar2 + 6;
    } while (iVar1 != 5);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ num_menu_items(struct DebugMenuLine *menu /*$a0*/)
 // line 1757, offset 0x800134e0
	/* begin block 1 */
		// Start line: 1759
		// Start offset: 0x800134E0
		// Variables:
	// 		int nitems; // $a1
	/* end block 1 */
	// End offset: 0x80013508
	// End Line: 1763

	/* begin block 2 */
		// Start line: 3381
	/* end block 2 */
	// End Line: 3382

	/* begin block 3 */
		// Start line: 3382
	/* end block 3 */
	// End Line: 3383

	/* begin block 4 */
		// Start line: 3383
	/* end block 4 */
	// End Line: 3384

int num_menu_items(DebugMenuLine *menu)

{
  DEBUG_LINE_TYPE DVar1;
  int iVar2;
  
  DVar1 = menu->type;
  iVar2 = 0;
  while (DVar1 != DEBUG_LINE_TYPE_ENDLIST) {
    menu = menu + 1;
    DVar1 = menu->type;
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ maybe_change_menu_choice(struct GameTracker *gt /*$a0*/, struct DebugMenuLine *menu /*$s2*/)
 // line 1766, offset 0x80013510
	/* begin block 1 */
		// Start line: 1767
		// Start offset: 0x80013510
		// Variables:
	// 		long *command; // $s0
	// 		int choice; // $s1
	// 		int nitems; // $a0
	// 		int incr; // $v1
	/* end block 1 */
	// End offset: 0x800135C0
	// End Line: 1785

	/* begin block 2 */
		// Start line: 3399
	/* end block 2 */
	// End Line: 3400

void maybe_change_menu_choice(GameTracker *gt,DebugMenuLine *menu)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = debugMenuChoice;
  iVar1 = num_menu_items(menu);
  if ((gt->controlCommand[1] & 1U) == 0) {
    uVar2 = (uint)gt->controlCommand[1] >> 1 & 1;
  }
  else {
    uVar2 = 0xffffffff;
  }
  if ((uVar2 != 0) && (-1 < iVar3)) {
    do {
      iVar3 = (int)(iVar3 + iVar1 + uVar2) % iVar1;
      if (iVar3 == debugMenuChoice) {
        return;
      }
    } while (DEBUG_LINE_TYPE_ENDLIST < menu[iVar3].type);
    if (iVar3 != debugMenuChoice) {
      SndPlay(5);
      debugMenuChoice = iVar3;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ handle_line_type_long(struct GameTracker *gt /*$a0*/, struct DebugMenuLine *line /*$a1*/)
 // line 1789, offset 0x800135d8
	/* begin block 1 */
		// Start line: 1790
		// Start offset: 0x800135D8
		// Variables:
	// 		long *command; // $v1

		/* begin block 1.1 */
			// Start line: 1794
			// Start offset: 0x800135F8
			// Variables:
		// 		int incr; // $a2
		/* end block 1.1 */
		// End offset: 0x800136B4
		// End Line: 1811
	/* end block 1 */
	// End offset: 0x800136B4
	// End Line: 1812

	/* begin block 2 */
		// Start line: 3450
	/* end block 2 */
	// End Line: 3451

void handle_line_type_long(GameTracker *gt,DebugMenuLine *line)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  if ((gt->controlCommand[1] & 0xcU) != 0) {
    uVar1 = gt->controlCommand[0];
    iVar3 = 10;
    if ((((uVar1 & 0x400) == 0) && (iVar3 = 100, (uVar1 & 0x800) == 0)) &&
       (iVar3 = 1, (uVar1 & 0x200) != 0)) {
      iVar3 = 1000;
    }
    if ((gt->controlCommand[1] & 4U) != 0) {
      iVar3 = -iVar3;
    }
    *line->var_address = *line->var_address + iVar3;
    piVar2 = line->var_address;
    if (*piVar2 < line->lower) {
      *piVar2 = line->lower;
      piVar2 = line->var_address;
    }
    if (line->upper < *piVar2) {
      *piVar2 = line->upper;
    }
    if ((code *)line->bit_mask != (code *)0x0) {
      (*(code *)line->bit_mask)(line->var_address);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ handle_line_type_bit(struct GameTracker *gt /*$a0*/, struct DebugMenuLine *line /*$a1*/)
 // line 1814, offset 0x800136c4
	/* begin block 1 */
		// Start line: 1816
		// Start offset: 0x800136C4
	/* end block 1 */
	// End offset: 0x80013714
	// End Line: 1823

	/* begin block 2 */
		// Start line: 3501
	/* end block 2 */
	// End Line: 3502

	/* begin block 3 */
		// Start line: 3502
	/* end block 3 */
	// End Line: 3503

	/* begin block 4 */
		// Start line: 3504
	/* end block 4 */
	// End Line: 3505

void handle_line_type_bit(GameTracker *gt,DebugMenuLine *line)

{
  if ((gt->controlCommand[1] & 4U) != 0) {
    *line->var_address = *line->var_address | line->bit_mask;
    return;
  }
  if ((gt->controlCommand[1] & 8U) == 0) {
    process_menu_line(gt,line);
    return;
  }
  *line->var_address = *line->var_address & ~line->bit_mask;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ handle_line_type_action(struct GameTracker *gt /*$a0*/, struct DebugMenuLine *line /*$a1*/)
 // line 1825, offset 0x8001371c
	/* begin block 1 */
		// Start line: 1826
		// Start offset: 0x8001371C
		// Variables:
	// 		int ok; // $v0
	/* end block 1 */
	// End offset: 0x80013748
	// End Line: 1835

	/* begin block 2 */
		// Start line: 3523
	/* end block 2 */
	// End Line: 3524

void handle_line_type_action(GameTracker *gt,DebugMenuLine *line)

{
  if ((gt->controlCommand[1] & 0x80U) != 0) {
    (*(code *)line->var_address)();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ handle_line_type_action_with_line(struct GameTracker *gt /*$a0*/, struct DebugMenuLine *line /*$a1*/)
 // line 1837, offset 0x80013758
	/* begin block 1 */
		// Start line: 1838
		// Start offset: 0x80013758
		// Variables:
	// 		enum option_ctrl_t ctrl; // $a2
	/* end block 1 */
	// End offset: 0x800137AC
	// End Line: 1849

	/* begin block 2 */
		// Start line: 3547
	/* end block 2 */
	// End Line: 3548

void handle_line_type_action_with_line(GameTracker *gt,DebugMenuLine *line)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = gt->controlCommand[1];
  iVar2 = 2;
  if ((((uVar1 & 0x80) == 0) && (iVar2 = 3, (uVar1 & 4) == 0)) && (iVar2 = 1, (uVar1 & 8) != 0)) {
    iVar2 = 4;
  }
  if (iVar2 != 1) {
    (*(code *)line->var_address)();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ handle_line_type_menu(struct GameTracker *gt /*$a0*/, struct DebugMenuLine *line /*$s0*/)
 // line 1853, offset 0x800137bc
	/* begin block 1 */
		// Start line: 1854
		// Start offset: 0x800137BC
		// Variables:
	// 		int ok; // $v0
	/* end block 1 */
	// End offset: 0x8001382C
	// End Line: 1870

	/* begin block 2 */
		// Start line: 3579
	/* end block 2 */
	// End Line: 3580

void handle_line_type_menu(GameTracker *gt,DebugMenuLine *line)

{
  code *pcVar1;
  DebugMenuLine *pDVar2;
  DebugMenuLine *line_00;
  
  if ((gt->controlCommand[1] & 0x80U) != 0) {
    pcVar1 = (code *)line->bit_mask;
    line_00 = line;
    if (pcVar1 != (code *)0x0) {
      pcVar1 = (code *)(*pcVar1)();
    }
    handle_line_type_long((GameTracker *)line,line_00);
    *(long *)(pcVar1 + 4) = debugMenuChoice;
    the_previous_menu = currentMenu;
    pDVar2 = currentMenu;
    currentMenu = (DebugMenuLine *)(GameTracker *)line->var_address;
    handle_line_type_long((GameTracker *)line->var_address,line_00);
    debugMenuChoice = pDVar2->lower;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ process_menu_line(struct GameTracker *gt /*$a0*/, struct DebugMenuLine *menu /*$a1*/)
 // line 1889, offset 0x8001383c
	/* begin block 1 */
		// Start line: 1890
		// Start offset: 0x8001383C
		// Variables:
	// 		struct DebugMenuLine *line; // $a1

		/* begin block 1.1 */
			// Start line: 1893
			// Start offset: 0x8001386C
			// Variables:
		// 		struct debug_dispatch_t *dispatch; // $v1
		/* end block 1.1 */
		// End offset: 0x80013890
		// End Line: 1898
	/* end block 1 */
	// End offset: 0x80013890
	// End Line: 1899

	/* begin block 2 */
		// Start line: 3652
	/* end block 2 */
	// End Line: 3653

	/* begin block 3 */
		// Start line: 3653
	/* end block 3 */
	// End Line: 3654

void process_menu_line(GameTracker *gt,DebugMenuLine *menu)

{
  if ((menu[debugMenuChoice].type < DEBUG_LINE_TYPE_ENDLIST) &&
     ((code *)(&DebugMenuLine_800c84dc.type)[menu[debugMenuChoice].type * 2] != (code *)0x0)) {
    (*(code *)(&DebugMenuLine_800c84dc.type)[menu[debugMenuChoice].type * 2])();
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ pre_process_functions(struct GameTracker *gt /*$a0*/, struct DebugMenuLine *menu /*$a1*/)
 // line 1903, offset 0x800138a0
	/* begin block 1 */
		// Start line: 3681
	/* end block 1 */
	// End Line: 3682

	/* begin block 2 */
		// Start line: 3682
	/* end block 2 */
	// End Line: 3683

int pre_process_functions(GameTracker *gt,DebugMenuLine *menu)

{
  _Instance *p_Var1;
  
  p_Var1 = gt->playerInstance;
  if (p_Var1 != (_Instance *)0x0) {
    p_Var1->flags = p_Var1->flags | 0x100;
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ post_process_functions(struct GameTracker *gt /*$s0*/, struct DebugMenuLine *menu /*$a1*/)
 // line 1911, offset 0x800138c8
	/* begin block 1 */
		// Start line: 3697
	/* end block 1 */
	// End Line: 3698

void post_process_functions(GameTracker *gt,DebugMenuLine *menu)

{
  if (menu == &debugSoundMenu) {
    SOUND_SetMusicVolume(-1);
    SOUND_SetSfxVolume(-1);
    SOUND_SetVoiceVolume(-1);
    if ((gt->debugFlags & 0x80000U) == 0) {
      (gt->sound).gVoiceOn = '\0';
    }
    else {
      (gt->sound).gVoiceOn = '\x01';
    }
    if ((gt->debugFlags2 & 0x1000U) == 0) {
      (gt->sound).gMusicOn = '\0';
    }
    else {
      (gt->sound).gMusicOn = '\x01';
    }
    if ((gt->debugFlags2 & 0x2000U) == 0) {
      (gt->sound).gSfxOn = '\0';
    }
    else {
      (gt->sound).gSfxOn = '\x01';
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ set_debug_leading()
 // line 1966, offset 0x8001396c
	/* begin block 1 */
		// Start line: 3807
	/* end block 1 */
	// End Line: 3808

	/* begin block 2 */
		// Start line: 3808
	/* end block 2 */
	// End Line: 3809

/* WARNING: Unknown calling convention yet parameter storage is locked */

void set_debug_leading(void)

{
  cem_line_leading = 10;
  cem_item_leading = 0xc;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ set_user_leading()
 // line 1972, offset 0x80013984
	/* begin block 1 */
		// Start line: 3819
	/* end block 1 */
	// End Line: 3820

	/* begin block 2 */
		// Start line: 3821
	/* end block 2 */
	// End Line: 3822

/* WARNING: Unknown calling convention yet parameter storage is locked */

void set_user_leading(void)

{
  cem_line_leading = 0xc;
  cem_item_leading = 0x10;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ isdigit(char c /*$a0*/)
 // line 1992, offset 0x8001399c
	/* begin block 1 */
		// Start line: 3859
	/* end block 1 */
	// End Line: 3860

	/* begin block 2 */
		// Start line: 3860
	/* end block 2 */
	// End Line: 3861

int isdigit(char c)

{
  return (uint)((byte)(c - 0x30U) < 10);
}



// decompiled code
// original method signature: 
// void /*$ra*/ adjust_format(char *ctrl /*$s1*/, struct debug_format_t *fmt /*$s4*/)
 // line 1997, offset 0x800139ac
	/* begin block 1 */
		// Start line: 1998
		// Start offset: 0x800139AC

		/* begin block 1.1 */
			// Start line: 2002
			// Start offset: 0x80013A14
			// Variables:
		// 		char *p; // $s0
		// 		int x; // $s2
		// 		int y; // $s3
		/* end block 1.1 */
		// End offset: 0x80013AE0
		// End Line: 2016
	/* end block 1 */
	// End offset: 0x80013B30
	// End Line: 2025

	/* begin block 2 */
		// Start line: 3869
	/* end block 2 */
	// End Line: 3870

void adjust_format(char *ctrl,debug_format_t *fmt)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  
  bVar1 = *ctrl;
  do {
    if (bVar1 == 0) {
      return;
    }
    iVar2 = strncmp(ctrl,s__abs_800cdcfc,5);
    if ((iVar2 == 0) || (iVar2 = strncmp(ctrl,s__rel_800cdd04,5), iVar2 == 0)) {
      pbVar4 = (byte *)ctrl + 5;
      iVar2 = 0;
      iVar5 = 0;
      while (iVar3 = isdigit(*pbVar4), iVar3 != 0) {
        bVar1 = *pbVar4;
        pbVar4 = pbVar4 + 1;
        iVar2 = iVar2 * 10 + (uint)bVar1 + -0x30;
      }
      if (*pbVar4 != 0) {
        pbVar4 = pbVar4 + 1;
      }
      while (iVar3 = isdigit(*pbVar4), iVar3 != 0) {
        bVar1 = *pbVar4;
        pbVar4 = pbVar4 + 1;
        iVar5 = iVar5 * 10 + (uint)bVar1 + -0x30;
      }
      if (*pbVar4 != 0) {
        pbVar4 = pbVar4 + 1;
      }
      iVar3 = strncmp(ctrl,s__abs_800cdcfc,5);
      if (iVar3 == 0) {
        fmt->xpos = iVar2;
        fmt->ypos = iVar5;
      }
      else {
        fmt->xpos = fmt->xpos + iVar2;
        fmt->ypos = fmt->ypos + iVar5;
      }
    }
    else {
      iVar2 = strncmp(ctrl,s__center_800cdd0c,7);
      if (iVar2 != 0) {
        printf(s_unknown_format_control___s_800cdd14);
        return;
      }
      fmt->is_centered = 1;
      pbVar4 = (byte *)ctrl + 7;
    }
    bVar1 = *pbVar4;
    ctrl = (char *)pbVar4;
  } while( true );
}



// decompiled code
// original method signature: 
// char * /*$ra*/ find_eol(char *text /*$v0*/)
 // line 2027, offset 0x80013b54
	/* begin block 1 */
		// Start line: 3956
	/* end block 1 */
	// End Line: 3957

char * find_eol(char *text)

{
  char cVar1;
  
  cVar1 = *text;
  while ((cVar1 != '\0' && (cVar1 != '\n'))) {
    text = text + 1;
    cVar1 = *text;
  }
  return text;
}



// decompiled code
// original method signature: 
// void /*$ra*/ draw_menu_item(struct GameTracker *gt /*$a0*/, struct debug_format_t *fmt /*$s2*/, char *text /*$s0*/)
 // line 2035, offset 0x80013b8c
	/* begin block 1 */
		// Start line: 2037
		// Start offset: 0x80013BAC

		/* begin block 1.1 */
			// Start line: 2038
			// Start offset: 0x80013BAC
			// Variables:
		// 		char *eol; // $s1
		// 		char c; // $s3

			/* begin block 1.1.1 */
				// Start line: 2042
				// Start offset: 0x80013BD0
			/* end block 1.1.1 */
			// End offset: 0x80013BD0
			// End Line: 2042
		/* end block 1.1 */
		// End offset: 0x80013C40
		// End Line: 2058
	/* end block 1 */
	// End offset: 0x80013C5C
	// End Line: 2062

	/* begin block 2 */
		// Start line: 3972
	/* end block 2 */
	// End Line: 3973

void draw_menu_item(GameTracker *gt,debug_format_t *fmt,char *text)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  short x;
  short y;
  
  while( true ) {
    pcVar2 = find_eol(text);
    cVar1 = *pcVar2;
    *pcVar2 = '\0';
    if (fmt->is_centered == 0) {
      x = *(short *)&fmt->xpos;
      y = *(short *)&fmt->ypos;
    }
    else {
      iVar3 = FONT_GetStringWidth(text);
      y = *(short *)&fmt->ypos;
      x = (short)(((uint)*(ushort *)&fmt->xpos - (iVar3 >> 1)) * 0x10000 >> 0x10);
    }
    FONT_SetCursor(x,y);
    if (currentMenu->type != DEBUG_LINE_TYPE_FORMAT) break;
    FONT_Print2(text);
    text = pcVar2 + 1;
    if (cVar1 == '\0') {
      fmt->ypos = fmt->ypos + cem_item_leading;
      return;
    }
    *pcVar2 = cVar1;
    fmt->ypos = fmt->ypos + cem_line_leading;
  }
                    /* WARNING: Subroutine does not return */
  FONT_Print(text);
}



// decompiled code
// original method signature: 
// void /*$ra*/ draw_menu(struct GameTracker *gt /*$s4*/, struct DebugMenuLine *menu /*$s0*/)
 // line 2065, offset 0x80013c8c
	/* begin block 1 */
		// Start line: 2066
		// Start offset: 0x80013C8C
		// Variables:
	// 		struct debug_format_t fmt; // stack offset -56
	// 		int i; // $s3

		/* begin block 1.1 */
			// Start line: 2079
			// Start offset: 0x80013D0C
			// Variables:
		// 		int xpos; // $s2
		// 		int ypos; // $s1
		/* end block 1.1 */
		// End offset: 0x80013E60
		// End Line: 2123
	/* end block 1 */
	// End offset: 0x80013E78
	// End Line: 2124

	/* begin block 2 */
		// Start line: 4055
	/* end block 2 */
	// End Line: 4056

	/* begin block 3 */
		// Start line: 4056
	/* end block 3 */
	// End Line: 4057

void draw_menu(GameTracker *gt,DebugMenuLine *menu)

{
  int iVar1;
  short x;
  short y;
  char *text;
  int iVar2;
  debug_format_t local_38;
  int local_28;
  int local_24;
  undefined4 local_20;
  
  local_20 = 0;
  local_28 = cem_x_base;
  local_24 = cem_y_base;
  local_38.xpos = cem_x_base;
  local_38.ypos = cem_y_base;
  local_38.is_centered = 0;
  if (menu->type == DEBUG_LINE_TYPE_FORMAT) {
    menu->text = the_format_string;
    set_user_leading();
    iVar2 = 0;
  }
  else {
    set_debug_leading();
    iVar2 = 0;
  }
  do {
    iVar1 = local_38.xpos;
    if (menu->type == DEBUG_LINE_TYPE_ENDLIST) {
      return;
    }
    if (menu->type == DEBUG_LINE_TYPE_FORMAT) {
      adjust_format(menu->text,&local_38);
    }
    else {
      y = (short)local_38.ypos;
      if (debugMenuChoice == iVar2) {
        if (local_38.is_centered == 0) {
          x = (short)local_38.xpos - (short)cem_cursor_width;
        }
        else {
          x = ((short)local_38.xpos - (short)(cem_line_width >> 1)) - (short)cem_cursor_width;
        }
        FONT_SetCursor(x,y);
                    /* WARNING: Subroutine does not return */
        FONT_Print(&DAT_800cdd30);
      }
      text = menu->text;
      draw_menu_item(gt,&local_38,text);
      if (local_38.is_centered != 0) {
        draw_menu_item((GameTracker *)(cem_line_width >> 1),(debug_format_t *)(int)y,text);
        return;
      }
      FONT_SetCursor((short)(((cem_line_width & 0xffffU) + iVar1) * 0x10000 >> 0x10),y);
      if (menu->type == DEBUG_LINE_TYPE_BIT) {
        if ((*menu->var_address & menu->bit_mask) != menu->bit_mask) {
                    /* WARNING: Subroutine does not return */
          FONT_Print((char *)&PTR_DAT_800cdd38);
        }
                    /* WARNING: Subroutine does not return */
        FONT_Print(&DAT_800cdd34);
      }
      if (menu->type == DEBUG_LINE_TYPE_LONG) {
                    /* WARNING: Subroutine does not return */
        FONT_Print((char *)&PTR_DAT_800cdd3c);
      }
    }
    menu = menu + 1;
    iVar2 = iVar2 + 1;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_Menu(struct GameTracker *gt /*$s1*/)
 // line 2126, offset 0x80013e98
	/* begin block 1 */
		// Start line: 2127
		// Start offset: 0x80013E98
		// Variables:
	// 		struct DebugMenuLine *menu; // $s0
	// 		int choice; // $s2
	/* end block 1 */
	// End offset: 0x80013F94
	// End Line: 2150

	/* begin block 2 */
		// Start line: 4230
	/* end block 2 */
	// End Line: 4231

void DEBUG_Menu(GameTracker *gt)

{
  DebugMenuLine *menu;
  long lVar1;
  int iVar2;
  DEBUG_LINE_TYPE DVar3;
  
  lVar1 = debugMenuChoice;
  menu = currentMenu;
  if ((currentMenu == (DebugMenuLine *)&mainMenu) || (currentMenu == (DebugMenuLine *)&pauseMenu)) {
    menu_process(gt->menu);
  }
  else {
    iVar2 = pre_process_functions(gt,currentMenu);
    if (iVar2 == 0) {
      DVar3 = menu[debugMenuChoice].type;
      while (DEBUG_LINE_TYPE_ENDLIST < DVar3) {
        debugMenuChoice = debugMenuChoice + 1;
        DVar3 = menu[debugMenuChoice].type;
      }
      draw_menu(gt,menu);
      maybe_change_menu_choice(gt,menu);
      if ((debugMenuChoice == lVar1) && (process_menu_line(gt,menu), currentMenu == menu)) {
        post_process_functions(gt,menu);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_DisplayStatus(struct GameTracker *gameTracker /*$s1*/)
 // line 2165, offset 0x80013fac
	/* begin block 1 */
		// Start line: 2166
		// Start offset: 0x80013FAC

		/* begin block 1.1 */
			// Start line: 2425
			// Start offset: 0x8001414C
			// Variables:
		// 		int deg; // $a0
		/* end block 1.1 */
		// End offset: 0x800141D0
		// End Line: 2438

		/* begin block 1.2 */
			// Start line: 2444
			// Start offset: 0x800141E0
			// Variables:
		// 		long numberInQueue; // stack offset -24
		/* end block 1.2 */
		// End offset: 0x80014200
		// End Line: 2451
	/* end block 1 */
	// End offset: 0x80014200
	// End Line: 2488

	/* begin block 2 */
		// Start line: 4317
	/* end block 2 */
	// End Line: 4318

void DEBUG_DisplayStatus(GameTracker *gameTracker)

{
                    /* WARNING: Subroutine does not return */
  STREAM_GetLevelWithID(gameTracker->playerInstance->currentStreamUnitID);
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_DrawShrinkCels(unsigned long **polyAddr /*$a0*/)
 // line 3564, offset 0x80014214
	/* begin block 1 */
		// Start line: 7128
	/* end block 1 */
	// End Line: 7129

	/* begin block 2 */
		// Start line: 6157
	/* end block 2 */
	// End Line: 6158

void DEBUG_DrawShrinkCels(ulong **polyAddr)

{
  return;
}



// autogenerated function stub: 
// void /*$ra*/ DEBUG_ContinueGame()
void DEBUG_ContinueGame()
{ // line 3736, offset 0x8001421c
	/* begin block 1 */
		// Start line: 7472
	/* end block 1 */
	// End Line: 7473

	/* begin block 2 */
		// Start line: 6331
	/* end block 2 */
	// End Line: 6332

}


// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ExitGame()
 // line 3757, offset 0x80014234
	/* begin block 1 */
		// Start line: 6371
	/* end block 1 */
	// End Line: 6372

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_ExitGame(void)

{
  SOUND_StopAllSound();
  theCamera.positionAccl._0_4_ = theCamera.positionAccl._0_4_ | 1;
  theCamera.maxFocusVel.x = 2;
  theCamera.maxFocusVel.y = 1;
  theCamera.maxFocusVel.pad = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_EndViewVram(struct GameTracker *gameTracker /*$a0*/)
 // line 3940, offset 0x80014270
	/* begin block 1 */
		// Start line: 7880
	/* end block 1 */
	// End Line: 7881

void DEBUG_EndViewVram(GameTracker *gameTracker)

{
                    /* WARNING: Subroutine does not return */
  SetDefDispEnv((undefined2 *)&debugOrgFogRed,0,0,0x200,0xf0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ViewVram(struct GameTracker *gameTracker /*$s1*/)
 // line 3946, offset 0x800142c0
	/* begin block 1 */
		// Start line: 3947
		// Start offset: 0x800142C0
		// Variables:
	// 		long *controlCommand; // $a0
	// 		static int xPos; // offset 0x478
	// 		static int yPos; // offset 0x47c
	/* end block 1 */
	// End offset: 0x80014380
	// End Line: 3973

	/* begin block 2 */
		// Start line: 6577
	/* end block 2 */
	// End Line: 6578

void DEBUG_ViewVram(GameTracker *gameTracker)

{
  if (((gameTracker->controlCommand[1] & 1U) != 0) && (-1 < DAT_800cdf34)) {
    DAT_800cdf34 = DAT_800cdf34 + -0x20;
  }
  if (((gameTracker->controlCommand[1] & 2U) != 0) && (DAT_800cdf34 < 0x110)) {
    DAT_800cdf34 = DAT_800cdf34 + 0x20;
  }
  if (((gameTracker->controlCommand[1] & 4U) != 0) && (-1 < _spu_rev_param)) {
    _spu_rev_param = _spu_rev_param + -0x20;
  }
  if (((gameTracker->controlCommand[1] & 8U) != 0) && (_spu_rev_param < 0x200)) {
    _spu_rev_param = _spu_rev_param + 0x20;
  }
                    /* WARNING: Subroutine does not return */
  SetDefDispEnv((undefined2 *)&debugOrgFogRed,(short)_spu_rev_param,(short)DAT_800cdf34,0x200,0xf0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_CaptureScreen(struct GameTracker *gameTracker /*$a0*/)
 // line 3984, offset 0x800143e0
	/* begin block 1 */
		// Start line: 6656
	/* end block 1 */
	// End Line: 6657

	/* begin block 2 */
		// Start line: 6705
	/* end block 2 */
	// End Line: 6706

void DEBUG_CaptureScreen(GameTracker *gameTracker)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_PageFlip()
 // line 4046, offset 0x800143e8
	/* begin block 1 */
		// Start line: 4047
		// Start offset: 0x800143E8
		// Variables:
	// 		struct POLY_F4 poly; // stack offset -32
	// 		unsigned long **drawot; // $s0
	/* end block 1 */
	// End offset: 0x800143E8
	// End Line: 4047

	/* begin block 2 */
		// Start line: 8086
	/* end block 2 */
	// End Line: 8087

	/* begin block 3 */
		// Start line: 6773
	/* end block 3 */
	// End Line: 6774

void DEBUG_PageFlip(void)

{
                    /* WARNING: Subroutine does not return */
  DrawSync(0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_FatalError(char *fmt /*stack 0*/)
 // line 4090, offset 0x800144f0
	/* begin block 1 */
		// Start line: 4091
		// Start offset: 0x800144F0
		// Variables:
	// 		char msg[256]; // stack offset -264
	/* end block 1 */
	// End offset: 0x800144F0
	// End Line: 4091

	/* begin block 2 */
		// Start line: 8180
	/* end block 2 */
	// End Line: 8181

void DEBUG_FatalError(char *fmt)

{
  undefined local_res4 [12];
  char acStack264 [256];
  
  FONT_Flush();
  vsprintf(acStack264,fmt,local_res4);
                    /* WARNING: Subroutine does not return */
  FONT_Print(acStack264);
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ProcessSecondController(struct GameTracker *gameTracker /*$a0*/)
 // line 4447, offset 0x80014544
	/* begin block 1 */
		// Start line: 7580
	/* end block 1 */
	// End Line: 7581

	/* begin block 2 */
		// Start line: 7666
	/* end block 2 */
	// End Line: 7667

void DEBUG_ProcessSecondController(GameTracker *gameTracker)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ProcessCheat(struct GameTracker *gameTracker /*$s3*/)
 // line 4538, offset 0x8001454c
	/* begin block 1 */
		// Start line: 4539
		// Start offset: 0x8001454C
		// Variables:
	// 		long angleRelCamera; // $s2

		/* begin block 1.1 */
			// Start line: 4565
			// Start offset: 0x80014620
			// Variables:
		// 		struct SVECTOR v; // stack offset -80
		// 		struct VECTOR dv; // stack offset -72
		// 		struct MATRIX rotate_mat; // stack offset -56
		/* end block 1.1 */
		// End offset: 0x800146A4
		// End Line: 4575
	/* end block 1 */
	// End offset: 0x800146A4
	// End Line: 4576

	/* begin block 2 */
		// Start line: 7762
	/* end block 2 */
	// End Line: 7763

void DEBUG_ProcessCheat(GameTracker *gameTracker)

{
  uint uVar1;
  int iVar2;
  undefined auStack80 [56];
  
  uVar1 = gameTracker->controlCommand[0];
  iVar2 = 0;
  if (((uVar1 & 0xa01) != 0xa01) && ((uVar1 & 0xa02) != 0xa02)) {
    if ((uVar1 & 5) == 5) {
      iVar2 = 0xa00;
    }
    else {
      if ((uVar1 & 9) == 9) {
        iVar2 = 0x600;
      }
      else {
        if ((uVar1 & 6) == 6) {
          iVar2 = 0xe00;
        }
        else {
          if ((uVar1 & 10) == 10) {
            iVar2 = 0x200;
          }
          else {
            if ((uVar1 & 2) == 0) {
              if ((uVar1 & 4) == 0) {
                if ((uVar1 & 8) == 0) {
                  if ((uVar1 & 1) != 0) {
                    iVar2 = 0x800;
                  }
                }
                else {
                  iVar2 = 0x400;
                }
              }
              else {
                iVar2 = 0xc00;
              }
            }
            else {
              iVar2 = 0x1000;
            }
          }
        }
      }
    }
  }
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    memset(auStack80,0,8);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_DoAreaProtection()
 // line 4593, offset 0x800146c0
	/* begin block 1 */
		// Start line: 4596
		// Start offset: 0x800146C8
	/* end block 1 */
	// End offset: 0x800146D8
	// End Line: 4603

	/* begin block 2 */
		// Start line: 7873
	/* end block 2 */
	// End Line: 7874

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_DoAreaProtection(void)

{
  uint uVar1;
  
  do {
    uVar1 = checkagain();
  } while (uVar1 != 0);
  return;
}





