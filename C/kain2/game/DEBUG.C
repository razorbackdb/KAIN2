#include "THISDUST.H"
#include "DEBUG.H"


// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_SetGameTime(long *var /*$a0*/)
 // line 1224, offset 0x80012eb8
	/* begin block 1 */
		// Start line: 2229
	/* end block 1 */
	// End Line: 2230

	/* begin block 2 */
		// Start line: 2448
	/* end block 2 */
	// End Line: 2449

void DEBUG_SetGameTime(long *var)

{
  GAMELOOP_SetGameTime(*var);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_KeepGameTime(long *var /*$a0*/)
 // line 1229, offset 0x80012edc
	/* begin block 1 */
		// Start line: 1230
		// Start offset: 0x80012EDC
		// Variables:
	// 		long curTOD; // stack offset -16
	/* end block 1 */
	// End offset: 0x80012EDC
	// End Line: 1230

	/* begin block 2 */
		// Start line: 2239
	/* end block 2 */
	// End Line: 2240

void DEBUG_KeepGameTime(long *var)

{
  long local_10 [2];
  
  local_10[0] = (int)gameTrackerX.timeOfDay;
  DEBUG_SetGameTime(local_10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_UpdateFog(long *var /*$a0*/)
 // line 1235, offset 0x80012f04
	/* begin block 1 */
		// Start line: 1236
		// Start offset: 0x80012F04
		// Variables:
	// 		struct _StreamUnit *currentUnit; // $v0
	/* end block 1 */
	// End offset: 0x80012F04
	// End Line: 1236

	/* begin block 2 */
		// Start line: 2253
	/* end block 2 */
	// End Line: 2254

	/* begin block 3 */
		// Start line: 2254
	/* end block 3 */
	// End Line: 2255

void DEBUG_UpdateFog(long *var)

{
  ushort uVar1;
  Level *pLVar2;
  _StreamUnit *p_Var3;
  uint uVar4;
  
  p_Var3 = FindStreamUnitFromLevel(gameTrackerX.level);
  pLVar2 = gameTrackerX.level;
  uVar1 = (ushort)debugFogFar;
  (gameTrackerX.level)->fogFar = (ushort)debugFogFar;
  p_Var3->TargetFogFar = uVar1;
  pLVar2->holdFogFar = uVar1;
  pLVar2 = gameTrackerX.level;
  uVar1 = (ushort)debugFogNear;
  (gameTrackerX.level)->fogNear = (ushort)debugFogNear;
  p_Var3->TargetFogNear = uVar1;
  pLVar2->holdFogNear = uVar1;
  pLVar2 = gameTrackerX.level;
  uVar4 = debugFogBlu << 0x10 | debugFogGrn << 8 | debugFogRed;
  p_Var3->FogColor = uVar4;
  *(uint *)&pLVar2->backColorR = uVar4;
  LIGHT_CalcDQPTable(gameTrackerX.level);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_UpdateHealth(long *var /*$a0*/)
 // line 1250, offset 0x80012f8c
	/* begin block 1 */
		// Start line: 2284
	/* end block 1 */
	// End Line: 2285

	/* begin block 2 */
		// Start line: 2285
	/* end block 2 */
	// End Line: 2286

void DEBUG_UpdateHealth(long *var)

{
  RAZIEL_DebugHealthSetScale(debugHealthLevel);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_UpdateMana(long *var /*$a0*/)
 // line 1255, offset 0x80012fb0
	/* begin block 1 */
		// Start line: 2295
	/* end block 1 */
	// End Line: 2296

	/* begin block 2 */
		// Start line: 2296
	/* end block 2 */
	// End Line: 2297

void DEBUG_UpdateMana(long *var)

{
  RAZIEL_DebugManaSetMax(debugManaLevel);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_FillUpHealth(long *var /*$a0*/)
 // line 1264, offset 0x80012fd4
	/* begin block 1 */
		// Start line: 1265
		// Start offset: 0x80012FD4
	/* end block 1 */
	// End offset: 0x80012FD4
	// End Line: 1265

	/* begin block 2 */
		// Start line: 2314
	/* end block 2 */
	// End Line: 2315

void DEBUG_FillUpHealth(long *var)

{
  RAZIEL_DebugHealthFillUp();
  RAZIEL_DebugManaFillUp();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_FogLoad()
 // line 1270, offset 0x80012ffc
	/* begin block 1 */
		// Start line: 1271
		// Start offset: 0x80012FFC
		// Variables:
	// 		struct _StreamUnit *currentUnit; // $v0
	/* end block 1 */
	// End offset: 0x80012FFC
	// End Line: 1271

	/* begin block 2 */
		// Start line: 2326
	/* end block 2 */
	// End Line: 2327

	/* begin block 3 */
		// Start line: 2327
	/* end block 3 */
	// End Line: 2328

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_FogLoad(void)

{
  _StreamUnit *p_Var1;
  
  p_Var1 = FindStreamUnitFromLevel(gameTrackerX.level);
  debugOrgFogBlu = *(byte *)((int)&p_Var1->FogColor + 2);
  debugOrgFogGrn = *(byte *)((int)&p_Var1->FogColor + 1);
  debugFogFar = (int)p_Var1->TargetFogFar;
  debugFogNear = (int)p_Var1->TargetFogNear;
  debugFogRed = (uint)*(byte *)&p_Var1->FogColor;
  debugFogGrn = (uint)debugOrgFogGrn;
  debugFogBlu = (uint)debugOrgFogBlu;
  debugOrgFogNear = p_Var1->TargetFogNear;
  debugOrgFogRed = *(byte *)&p_Var1->FogColor;
  debugOrgFogFar = p_Var1->TargetFogFar;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_FogRestore()
 // line 1283, offset 0x80013064
	/* begin block 1 */
		// Start line: 2360
	/* end block 1 */
	// End Line: 2361

	/* begin block 2 */
		// Start line: 2361
	/* end block 2 */
	// End Line: 2362

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_FogRestore(void)

{
  debugFogFar = (long)debugOrgFogFar;
  debugFogNear = (long)debugOrgFogNear;
  debugFogRed = ZEXT14(debugOrgFogRed);
  debugFogGrn = ZEXT14(debugOrgFogGrn);
  debugFogBlu = ZEXT14(debugOrgFogBlu);
  DEBUG_UpdateFog((long *)0x0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_SendCinematicSwitch()
 // line 1298, offset 0x800130ac
	/* begin block 1 */
		// Start line: 2596
	/* end block 1 */
	// End Line: 2597

	/* begin block 2 */
		// Start line: 2389
	/* end block 2 */
	// End Line: 2390

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_SendCinematicSwitch(void)

{
  gameTrackerX.debugFlags2 = gameTrackerX.debugFlags2 ^ 0x200;
  INSTANCE_Broadcast((_Instance *)0x0,0xe,(int)&DAT_0004000e,
                     (uint)((gameTrackerX.debugFlags2 & 0x200U) != 0));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_SendMoveTo()
 // line 1312, offset 0x80013108
	/* begin block 1 */
		// Start line: 2417
	/* end block 1 */
	// End Line: 2418

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_SendMoveTo(void)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  int Data;
  
  uVar2 = rand();
  sVar1 = ((gameTrackerX.playerInstance)->position).x;
  uVar3 = rand();
  Data = SetPositionData((int)sVar1 + (uVar2 & 0x7ff) + -0x400,
                         (int)((gameTrackerX.playerInstance)->position).y + (uVar3 & 0x7ff) + -0x400
                         ,(int)((gameTrackerX.playerInstance)->position).z);
  INSTANCE_Broadcast((_Instance *)0x0,0xe,(int)&DAT_0004000c,Data);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ process_cheat_codes(struct GameTracker *gt /*$a0*/, long *ctrl /*$a1*/)
 // line 1463, offset 0x8001317c
	/* begin block 1 */
		// Start line: 1464
		// Start offset: 0x8001317C
		// Variables:
	// 		int i; // $s0
	// 		struct GameCheat *cheat; // $a0
	// 		unsigned long padPress; // $s2
	// 		unsigned long padOn; // $s1

		/* begin block 1.1 */
			// Start line: 1476
			// Start offset: 0x800131BC
			// Variables:
		// 		int cheatTriggered; // $s3

			/* begin block 1.1.1 */
				// Start line: 1479
				// Start offset: 0x800131D0
				// Variables:
			// 		unsigned long keyMask; // $v1

				/* begin block 1.1.1.1 */
					// Start line: 1499
					// Start offset: 0x8001325C
				/* end block 1.1.1.1 */
				// End offset: 0x800133F8
				// End Line: 1573
			/* end block 1.1.1 */
			// End offset: 0x800133F8
			// End Line: 1575
		/* end block 1.1 */
		// End offset: 0x80013420
		// End Line: 1581
	/* end block 1 */
	// End offset: 0x80013420
	// End Line: 1583

	/* begin block 2 */
		// Start line: 2926
	/* end block 2 */
	// End Line: 2927

void process_cheat_codes(GameTracker *gt,long *ctrl)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
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
LAB_800131d4:
  if (((uVar7 & (&CheatKeyMap)
                [GameCheats.cheatKeys[*(short *)((int)&GameCheats.cheatStage + iVar3) + iVar3]]) ==
       0) || ((uVar6 & 0xfffffcff &
              ~(&CheatKeyMap)
               [GameCheats.cheatKeys[*(short *)((int)&GameCheats.cheatStage + iVar3) + iVar3]]) != 0
             )) {
    *(undefined2 *)((int)&GameCheats.cheatStage + iVar3) = 0;
  }
  else {
    *(short *)((int)&GameCheats.cheatStage + iVar3) =
         *(short *)((int)&GameCheats.cheatStage + iVar3) + 1;
  }
  if (*(short *)((int)&GameCheats.cheatStage + iVar3) !=
      *(short *)((int)&GameCheats.cheatLen + iVar3)) goto switchD_80013254_caseD_17;
  *(undefined2 *)((int)&GameCheats.cheatStage + iVar3) = 0;
  bVar2 = true;
  switch(iVar5) {
  case 0:
    goto switchD_80013254_caseD_0;
  case 1:
    debugRazielFlags1 = debugRazielFlags1 | 0x5f;
    break;
  case 2:
    debugRazielFlags1 = debugRazielFlags1 | 0x8000;
    break;
  case 3:
    debugRazielFlags2 = debugRazielFlags2 | 0x10000;
    break;
  case 4:
    debugRazielFlags1 = debugRazielFlags1 | 0x20;
  case 9:
    debugRazielFlags1 = debugRazielFlags1 | 0x10;
    goto switchD_80013254_caseD_0;
  case 5:
    debugRazielFlags2 = debugRazielFlags2 | 0x1000;
    break;
  case 6:
    uVar4 = 0x800000;
    goto LAB_800133d8;
  case 7:
    debugManaLevel = 6;
    DEBUG_UpdateMana(&debugManaLevel);
    bVar1 = iVar5 + 1 < 0x17;
    goto LAB_80013400;
  case 8:
    goto switchD_80013254_caseD_8;
  case 10:
    uVar4 = 0x80000;
    goto LAB_800133d8;
  case 0xb:
    uVar4 = 0x100000;
    goto LAB_800133d8;
  case 0xc:
    uVar4 = 0x400000;
    goto LAB_800133d8;
  case 0xd:
    DEBUG_FillUpHealth(&debugHealthLevel);
    bVar1 = iVar5 + 1 < 0x17;
    goto LAB_80013400;
  case 0xe:
    debugHealthLevel = debugHealthLevel + 1;
    if (4 < debugHealthLevel) goto switchD_80013254_caseD_f;
    goto LAB_80013294;
  case 0xf:
switchD_80013254_caseD_f:
    debugHealthLevel = 4;
LAB_80013294:
    DEBUG_UpdateHealth(&debugHealthLevel);
    bVar1 = iVar5 + 1 < 0x17;
    goto LAB_80013400;
  case 0x10:
    RAZIEL_DebugManaFillUp();
    bVar1 = iVar5 + 1 < 0x17;
    goto LAB_80013400;
  case 0x11:
    goto switchD_80013254_caseD_11;
  case 0x12:
    goto switchD_80013254_caseD_12;
  case 0x13:
    RAZIEL_DebugHurtRaziel();
    bVar1 = iVar5 + 1 < 0x17;
    goto LAB_80013400;
  case 0x14:
    debugRazielFlags2 = debugRazielFlags2 | 0x8000;
    break;
  case 0x15:
    uVar4 = 0x40000;
    goto LAB_800133d8;
  case 0x16:
    uVar4 = 0x200000;
LAB_800133d8:
    debugRazielFlags3 = debugRazielFlags3 | uVar4;
  }
switchD_80013254_caseD_17:
  bVar1 = iVar5 + 1 < 0x17;
LAB_80013400:
  iVar5 = iVar5 + 1;
  iVar3 = iVar5 * 0x10;
  if (!bVar1) {
    if (bVar2) {
      SndPlayVolPan(0x15,0x50,0x40,0x32);
    }
    cheatCodeLastCommand = uVar7;
    return;
  }
  goto LAB_800131d4;
switchD_80013254_caseD_0:
  debugRazielFlags1 = debugRazielFlags1 | 8;
switchD_80013254_caseD_12:
  debugRazielFlags1 = debugRazielFlags1 | 4;
switchD_80013254_caseD_11:
  debugRazielFlags1 = debugRazielFlags1 | 2;
switchD_80013254_caseD_8:
  debugRazielFlags1 = debugRazielFlags1 | 1;
  goto switchD_80013254_caseD_17;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_Process(struct GameTracker *gameTracker /*$s0*/)
 // line 1590, offset 0x80013444
	/* begin block 1 */
		// Start line: 1591
		// Start offset: 0x80013444
		// Variables:
	// 		long *controlCommand; // $s3
	// 		long oldFlags; // $s2
	// 		long oldFlags2; // $s1
	/* end block 1 */
	// End offset: 0x800135D4
	// End Line: 1655

	/* begin block 2 */
		// Start line: 2923
	/* end block 2 */
	// End Line: 2924

void DEBUG_Process(GameTracker *gameTracker)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = gameTracker->debugFlags;
  sVar1 = gameTracker->gameMode;
  uVar2 = gameTracker->debugFlags2;
  if (sVar1 == 0) {
    if ((uVar3 & 8) != 0) {
      DEBUG_ProcessSecondController(gameTracker);
    }
    if (gameTracker->cheatMode == '\x01') {
      DEBUG_ProcessCheat(gameTracker);
    }
    goto LAB_800135a4;
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
    goto LAB_800135a4;
  }
  DEBUG_Menu(gameTracker);
  if ((gameTracker->debugFlags2 & 0x40000U) == 0) {
LAB_800134fc:
    if ((uVar2 & 0x40000) != 0) {
      gameTracker->debugFlags = gameTracker->debugFlags & 0xfffffff7;
    }
  }
  else {
    if ((uVar2 & 0x40000) == 0) {
      gameTracker->debugFlags = gameTracker->debugFlags | 8;
    }
    if ((gameTracker->debugFlags2 & 0x40000U) == 0) goto LAB_800134fc;
  }
  if (((gameTracker->debugFlags & 8U) != 0) && ((uVar3 & 8) == 0)) {
    theCamera.core.debugPos.x = theCamera.core.position.x;
    theCamera.core.debugPos.y = theCamera.core.position.y;
    theCamera.core.debugPos.z = theCamera.core.position.z;
    theCamera.core.debugRot.x = theCamera.core.rotation.x;
    theCamera.core.debugRot.y = theCamera.core.rotation.y;
    theCamera.core.debugRot.z = theCamera.core.rotation.z;
  }
LAB_800135a4:
  if (((gameTracker->debugFlags & 0x4000U) != 0) && ((gameTracker->controlCommand[1] & 0x400U) != 0)
     ) {
    DEBUG_CaptureScreen(gameTracker);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_Draw(struct GameTracker *gameTracker /*$a0*/, unsigned long **ot /*$a1*/)
 // line 1665, offset 0x800135f0
	/* begin block 1 */
		// Start line: 3330
	/* end block 1 */
	// End Line: 3331

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
 // line 1688, offset 0x80013638
	/* begin block 1 */
		// Start line: 1690
		// Start offset: 0x80013638
		// Variables:
	// 		int length; // $v1
	// 		struct DebugMenuLine *curLine; // $a0
	/* end block 1 */
	// End offset: 0x8001365C
	// End Line: 1699

	/* begin block 2 */
		// Start line: 3115
	/* end block 2 */
	// End Line: 3116

	/* begin block 3 */
		// Start line: 3116
	/* end block 3 */
	// End Line: 3117

	/* begin block 4 */
		// Start line: 3118
	/* end block 4 */
	// End Line: 3119

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
 // line 1702, offset 0x80013664
	/* begin block 1 */
		// Start line: 1703
		// Start offset: 0x80013664
	/* end block 1 */
	// End offset: 0x800136EC
	// End Line: 1732

	/* begin block 2 */
		// Start line: 3143
	/* end block 2 */
	// End Line: 3144

	/* begin block 3 */
		// Start line: 3148
	/* end block 3 */
	// End Line: 3149

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_ExitMenus(void)

{
  long lVar1;
  
  lVar1 = DEBUG_MenuCountLength(currentMenu);
  currentMenu[lVar1].lower = debugMenuChoice;
  if (gameTrackerX.sound.gMusicOn == '\0') {
    SOUND_MusicOff();
    SOUND_ShutdownMusic();
  }
  else {
    SOUND_MusicOn();
  }
  if (gameTrackerX.sound.gSfxOn == '\0') {
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
 // line 1738, offset 0x800136fc
	/* begin block 1 */
		// Start line: 3220
	/* end block 1 */
	// End Line: 3221

	/* begin block 2 */
		// Start line: 3221
	/* end block 2 */
	// End Line: 3222

DebugMenuLine * get_last_menu_line(DebugMenuLine *line)

{
  DebugMenuLine *pDVar1;
  
  if (line->type != DEBUG_LINE_TYPE_ENDLIST) {
    pDVar1 = line + 1;
    do {
      line = pDVar1;
      pDVar1 = line + 1;
    } while (line->type != DEBUG_LINE_TYPE_ENDLIST);
  }
  return line;
}



// decompiled code
// original method signature: 
// int /*$ra*/ num_menu_items(struct DebugMenuLine *menu /*$a0*/)
 // line 1746, offset 0x8001372c
	/* begin block 1 */
		// Start line: 1748
		// Start offset: 0x8001372C
		// Variables:
	// 		int nitems; // $a1
	/* end block 1 */
	// End offset: 0x80013754
	// End Line: 1752

	/* begin block 2 */
		// Start line: 3236
	/* end block 2 */
	// End Line: 3237

	/* begin block 3 */
		// Start line: 3237
	/* end block 3 */
	// End Line: 3238

	/* begin block 4 */
		// Start line: 3238
	/* end block 4 */
	// End Line: 3239

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
 // line 1755, offset 0x8001375c
	/* begin block 1 */
		// Start line: 1756
		// Start offset: 0x8001375C
		// Variables:
	// 		long *command; // $s0
	// 		int choice; // $s1
	// 		int nitems; // $a0
	// 		int incr; // $v1
	/* end block 1 */
	// End offset: 0x8001380C
	// End Line: 1774

	/* begin block 2 */
		// Start line: 3254
	/* end block 2 */
	// End Line: 3255

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
 // line 1778, offset 0x80013824
	/* begin block 1 */
		// Start line: 1779
		// Start offset: 0x80013824
		// Variables:
	// 		long *command; // $v1

		/* begin block 1.1 */
			// Start line: 1783
			// Start offset: 0x80013844
			// Variables:
		// 		int incr; // $a2
		/* end block 1.1 */
		// End offset: 0x80013900
		// End Line: 1800
	/* end block 1 */
	// End offset: 0x80013900
	// End Line: 1801

	/* begin block 2 */
		// Start line: 3305
	/* end block 2 */
	// End Line: 3306

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
 // line 1803, offset 0x80013910
	/* begin block 1 */
		// Start line: 1805
		// Start offset: 0x80013910
	/* end block 1 */
	// End offset: 0x80013960
	// End Line: 1812

	/* begin block 2 */
		// Start line: 3356
	/* end block 2 */
	// End Line: 3357

	/* begin block 3 */
		// Start line: 3357
	/* end block 3 */
	// End Line: 3358

	/* begin block 4 */
		// Start line: 3359
	/* end block 4 */
	// End Line: 3360

void handle_line_type_bit(GameTracker *gt,DebugMenuLine *line)

{
  if ((gt->controlCommand[1] & 4U) != 0) {
    *line->var_address = *line->var_address | line->bit_mask;
    return;
  }
  if ((gt->controlCommand[1] & 8U) != 0) {
    *line->var_address = *line->var_address & ~line->bit_mask;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ handle_line_type_action(struct GameTracker *gt /*$a0*/, struct DebugMenuLine *line /*$a1*/)
 // line 1814, offset 0x80013968
	/* begin block 1 */
		// Start line: 1815
		// Start offset: 0x80013968
		// Variables:
	// 		int ok; // $v0
	/* end block 1 */
	// End offset: 0x80013994
	// End Line: 1824

	/* begin block 2 */
		// Start line: 3378
	/* end block 2 */
	// End Line: 3379

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
 // line 1826, offset 0x800139a4
	/* begin block 1 */
		// Start line: 1827
		// Start offset: 0x800139A4
		// Variables:
	// 		enum option_ctrl_t ctrl; // $a2
	/* end block 1 */
	// End offset: 0x800139F8
	// End Line: 1838

	/* begin block 2 */
		// Start line: 3402
	/* end block 2 */
	// End Line: 3403

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
 // line 1842, offset 0x80013a08
	/* begin block 1 */
		// Start line: 1843
		// Start offset: 0x80013A08
		// Variables:
	// 		int ok; // $v0
	/* end block 1 */
	// End offset: 0x80013A78
	// End Line: 1859

	/* begin block 2 */
		// Start line: 3434
	/* end block 2 */
	// End Line: 3435

void handle_line_type_menu(GameTracker *gt,DebugMenuLine *line)

{
  DebugMenuLine *pDVar1;
  
  if ((gt->controlCommand[1] & 0x80U) != 0) {
    if ((code *)line->bit_mask != (code *)0x0) {
      (*(code *)line->bit_mask)();
    }
    pDVar1 = get_last_menu_line(line);
    pDVar1->lower = debugMenuChoice;
    the_previous_menu = currentMenu;
    currentMenu = (DebugMenuLine *)line->var_address;
    pDVar1 = get_last_menu_line((DebugMenuLine *)line->var_address);
    debugMenuChoice = pDVar1->lower;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ process_menu_line(struct GameTracker *gt /*$a0*/, struct DebugMenuLine *menu /*$a1*/)
 // line 1878, offset 0x80013a88
	/* begin block 1 */
		// Start line: 1879
		// Start offset: 0x80013A88
		// Variables:
	// 		struct DebugMenuLine *line; // $a1

		/* begin block 1.1 */
			// Start line: 1882
			// Start offset: 0x80013AB8
			// Variables:
		// 		struct debug_dispatch_t *dispatch; // $v1
		/* end block 1.1 */
		// End offset: 0x80013ADC
		// End Line: 1887
	/* end block 1 */
	// End offset: 0x80013ADC
	// End Line: 1888

	/* begin block 2 */
		// Start line: 3507
	/* end block 2 */
	// End Line: 3508

	/* begin block 3 */
		// Start line: 3508
	/* end block 3 */
	// End Line: 3509

void process_menu_line(GameTracker *gt,DebugMenuLine *menu)

{
  if ((menu[debugMenuChoice].type < DEBUG_LINE_TYPE_ENDLIST) &&
     ((&debug_dispatch_table)[menu[debugMenuChoice].type].fn != (_func_16 *)0x0)) {
    (*(&debug_dispatch_table)[menu[debugMenuChoice].type].fn)();
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ pre_process_functions(struct GameTracker *gt /*$a0*/, struct DebugMenuLine *menu /*$a1*/)
 // line 1892, offset 0x80013aec
	/* begin block 1 */
		// Start line: 3536
	/* end block 1 */
	// End Line: 3537

	/* begin block 2 */
		// Start line: 3537
	/* end block 2 */
	// End Line: 3538

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
 // line 1900, offset 0x80013b14
	/* begin block 1 */
		// Start line: 3552
	/* end block 1 */
	// End Line: 3553

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
 // line 1955, offset 0x80013bb8
	/* begin block 1 */
		// Start line: 3662
	/* end block 1 */
	// End Line: 3663

	/* begin block 2 */
		// Start line: 3663
	/* end block 2 */
	// End Line: 3664

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
 // line 1961, offset 0x80013bd0
	/* begin block 1 */
		// Start line: 3674
	/* end block 1 */
	// End Line: 3675

	/* begin block 2 */
		// Start line: 3676
	/* end block 2 */
	// End Line: 3677

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
 // line 1981, offset 0x80013be8
	/* begin block 1 */
		// Start line: 3714
	/* end block 1 */
	// End Line: 3715

	/* begin block 2 */
		// Start line: 3715
	/* end block 2 */
	// End Line: 3716

int isdigit(char c)

{
  return (uint)((byte)(c - 0x30U) < 10);
}



// decompiled code
// original method signature: 
// void /*$ra*/ adjust_format(char *ctrl /*$s1*/, struct debug_format_t *fmt /*$s4*/)
 // line 1986, offset 0x80013bf8
	/* begin block 1 */
		// Start line: 1987
		// Start offset: 0x80013BF8

		/* begin block 1.1 */
			// Start line: 1991
			// Start offset: 0x80013C60
			// Variables:
		// 		char *p; // $s0
		// 		int x; // $s2
		// 		int y; // $s3
		/* end block 1.1 */
		// End offset: 0x80013D2C
		// End Line: 2005
	/* end block 1 */
	// End offset: 0x80013D7C
	// End Line: 2014

	/* begin block 2 */
		// Start line: 3724
	/* end block 2 */
	// End Line: 3725

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
    iVar2 = strncmp(ctrl,"-abs ",5);
    if ((iVar2 == 0) || (iVar2 = strncmp(ctrl,"-rel ",5), iVar2 == 0)) {
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
      iVar3 = strncmp(ctrl,"-abs ",5);
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
      iVar2 = strncmp(ctrl,"-center",7);
      if (iVar2 != 0) {
        printf("unknown format control: %s\n");
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
 // line 2016, offset 0x80013da0
	/* begin block 1 */
		// Start line: 3811
	/* end block 1 */
	// End Line: 3812

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
 // line 2024, offset 0x80013dd8
	/* begin block 1 */
		// Start line: 2026
		// Start offset: 0x80013DF8

		/* begin block 1.1 */
			// Start line: 2027
			// Start offset: 0x80013DF8
			// Variables:
		// 		char *eol; // $s1
		// 		char c; // $s3

			/* begin block 1.1.1 */
				// Start line: 2031
				// Start offset: 0x80013E1C
			/* end block 1.1.1 */
			// End offset: 0x80013E1C
			// End Line: 2031
		/* end block 1.1 */
		// End offset: 0x80013E8C
		// End Line: 2047
	/* end block 1 */
	// End offset: 0x80013EA8
	// End Line: 2051

	/* begin block 2 */
		// Start line: 3827
	/* end block 2 */
	// End Line: 3828

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
    if (currentMenu->type == DEBUG_LINE_TYPE_FORMAT) {
      FONT_Print2(text);
    }
    else {
      FONT_Print(text);
    }
    text = pcVar2 + 1;
    if (cVar1 == '\0') break;
    *pcVar2 = cVar1;
    fmt->ypos = fmt->ypos + cem_line_leading;
  }
  fmt->ypos = fmt->ypos + cem_item_leading;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ draw_menu(struct GameTracker *gt /*$s4*/, struct DebugMenuLine *menu /*$s0*/)
 // line 2054, offset 0x80013ed8
	/* begin block 1 */
		// Start line: 2055
		// Start offset: 0x80013ED8
		// Variables:
	// 		struct debug_format_t fmt; // stack offset -56
	// 		int i; // $s3

		/* begin block 1.1 */
			// Start line: 2068
			// Start offset: 0x80013F58
			// Variables:
		// 		int xpos; // $s2
		// 		int ypos; // $s1
		/* end block 1.1 */
		// End offset: 0x800140AC
		// End Line: 2112
	/* end block 1 */
	// End offset: 0x800140C4
	// End Line: 2113

	/* begin block 2 */
		// Start line: 3910
	/* end block 2 */
	// End Line: 3911

	/* begin block 3 */
		// Start line: 3911
	/* end block 3 */
	// End Line: 3912

void draw_menu(GameTracker *gt,DebugMenuLine *menu)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short y;
  int iVar4;
  debug_format_t local_38;
  int local_28;
  int local_24;
  undefined4 local_20;
  
  local_20 = 0;
  local_28 = 0x28;
  local_24 = 0x14;
  local_38.xpos = 0x28;
  local_38.ypos = 0x14;
  local_38.is_centered = 0;
  if (menu->type == DEBUG_LINE_TYPE_FORMAT) {
    menu->text = "-abs 160 40 -center";
    set_user_leading();
    iVar4 = 0;
  }
  else {
    set_debug_leading();
    iVar4 = 0;
  }
  while (iVar2 = local_38.xpos, menu->type != DEBUG_LINE_TYPE_ENDLIST) {
    if (menu->type == DEBUG_LINE_TYPE_FORMAT) {
      adjust_format(menu->text,&local_38);
    }
    else {
      y = (short)local_38.ypos;
      if (debugMenuChoice == iVar4) {
        sVar1 = (short)local_38.xpos;
        if (local_38.is_centered != 0) {
          sVar1 = sVar1 + -0x78;
        }
        FONT_SetCursor(sVar1 + -0x14,y);
        FONT_Print(">");
      }
      draw_menu_item(gt,&local_38,menu->text);
      if (local_38.is_centered == 0) {
        iVar3 = 0xf0;
      }
      else {
        iVar3 = 0x78;
      }
      FONT_SetCursor((short)((uint)((iVar3 + iVar2) * 0x10000) >> 0x10),y);
      if (menu->type == DEBUG_LINE_TYPE_BIT) {
        if ((*menu->var_address & menu->bit_mask) == menu->bit_mask) {
          FONT_Print("YES");
        }
        else {
          FONT_Print((char *)&PTR_DAT_800d01a0);
        }
      }
      else {
        if (menu->type == DEBUG_LINE_TYPE_LONG) {
          FONT_Print((char *)&PTR_DAT_800d01a4);
        }
      }
    }
    menu = menu + 1;
    iVar4 = iVar4 + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_Menu(struct GameTracker *gt /*$s1*/)
 // line 2115, offset 0x800140e4
	/* begin block 1 */
		// Start line: 2116
		// Start offset: 0x800140E4
		// Variables:
	// 		struct DebugMenuLine *menu; // $s0
	// 		int choice; // $s2
	/* end block 1 */
	// End offset: 0x800141E0
	// End Line: 2139

	/* begin block 2 */
		// Start line: 4085
	/* end block 2 */
	// End Line: 4086

void DEBUG_Menu(GameTracker *gt)

{
  DebugMenuLine *menu;
  long lVar1;
  int iVar2;
  DEBUG_LINE_TYPE DVar3;
  
  lVar1 = debugMenuChoice;
  menu = currentMenu;
  if ((currentMenu == &mainMenu) || (currentMenu == &pauseMenu)) {
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
 // line 2154, offset 0x800141f8
	/* begin block 1 */
		// Start line: 2155
		// Start offset: 0x800141F8

		/* begin block 1.1 */
			// Start line: 2414
			// Start offset: 0x80014398
			// Variables:
		// 		int deg; // $a0
		/* end block 1.1 */
		// End offset: 0x8001441C
		// End Line: 2427

		/* begin block 1.2 */
			// Start line: 2433
			// Start offset: 0x8001442C
			// Variables:
		// 		long numberInQueue; // stack offset -24
		/* end block 1.2 */
		// End offset: 0x8001444C
		// End Line: 2440
	/* end block 1 */
	// End offset: 0x8001444C
	// End Line: 2477

	/* begin block 2 */
		// Start line: 4172
	/* end block 2 */
	// End Line: 4173

void DEBUG_DisplayStatus(GameTracker *gameTracker)

{
  int iVar1;
  char *fmt;
  long local_18 [2];
  
  STREAM_GetLevelWithID(gameTracker->playerInstance->currentStreamUnitID);
  if ((gameTracker->debugFlags & 0x40000000U) != 0) {
    EVENT_PrintVars();
  }
  if ((gameTracker->debugFlags & 0x4000004U) != 0) {
    if ((gameTracker->debugFlags & 0x4000000U) == 0) {
      fmt = "$@KG\n FRTE %d\n";
    }
    else {
      FONT_Print("$@EF\n FRTE %d ");
      FONT_Print(" INS  %d");
      fmt = "/%d\n";
    }
    FONT_Print(fmt);
    FONT_Print(" Focus XYZ(%d,%d,%d)\n");
    if ((gameTracker->debugFlags & 4U) != 0) {
      if (gameTracker->idleTime == 0) {
        FONT_Print(" IDLE ZERO\n");
      }
      else {
        FONT_Print(" IDLE %d PCT\n");
      }
      FONT_Print(" DRAW %d\n");
      FONT_Print(" Far Plane =%d\n");
      FONT_Print(" Fog Near = %d Fog Far = %d\n");
      FONT_Print("Military Time %04d\n");
    }
    MEMPACK_ReportFreeMemory();
    SAVE_SizeOfFreeSpace();
    FONT_Print(" FMEM %d  FreeSaveMem %d\n");
    FONT_Print(" AREA DRM = %s\n");
    FONT_Print(" CAM TILT %d DIST %d\n");
  }
  if ((gameTracker->debugFlags < 0) && (iVar1 = STREAM_IsCdBusy(local_18), iVar1 != 0)) {
    FONT_Print("Loading From CD: In Queue(%d)\n");
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_DrawShrinkCels(unsigned long **polyAddr /*$a0*/)
 // line 3553, offset 0x80014460
	/* begin block 1 */
		// Start line: 7106
	/* end block 1 */
	// End Line: 7107

	/* begin block 2 */
		// Start line: 6012
	/* end block 2 */
	// End Line: 6013

void DEBUG_DrawShrinkCels(ulong **polyAddr)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ContinueGame()
 // line 3725, offset 0x80014468
	/* begin block 1 */
		// Start line: 7450
	/* end block 1 */
	// End Line: 7451

	/* begin block 2 */
		// Start line: 6186
	/* end block 2 */
	// End Line: 6187

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_ContinueGame(void)

{
  gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x40000000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ExitGame()
 // line 3746, offset 0x80014480
	/* begin block 1 */
		// Start line: 6226
	/* end block 1 */
	// End Line: 6227

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_ExitGame(void)

{
  SOUND_StopAllSound();
  gameTrackerX.gameFlags = gameTrackerX.gameFlags | 1;
  gameTrackerX.levelDone = 2;
  gameTrackerX.levelChange = 1;
  gameTrackerX.gameMode = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ReloadCurrentLevel()
 // line 3757, offset 0x800144bc
	/* begin block 1 */
		// Start line: 6251
	/* end block 1 */
	// End Line: 6252

	/* begin block 2 */
		// Start line: 6252
	/* end block 2 */
	// End Line: 6253

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_ReloadCurrentLevel(void)

{
  if (gameTrackerX.levelChange == 0) {
    if ((gameTrackerX.streamFlags & 0x200000U) != 0) {
      SAVE_SaveGame();
    }
    gameTrackerX.gameFlags = gameTrackerX.gameFlags | 1;
    SOUND_ResetAllSound();
    gameTrackerX.levelChange = 1;
    gameTrackerX.levelDone = 4;
  }
  gameTrackerX.gameMode = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_LevelSelectNew()
 // line 3777, offset 0x80014520
	/* begin block 1 */
		// Start line: 3778
		// Start offset: 0x80014520
		// Variables:
	// 		char *name; // $s3
	// 		short number; // $s2
	// 		char *p; // $s0
	// 		char saveChar; // $s1
	/* end block 1 */
	// End offset: 0x800145FC
	// End Line: 3812

	/* begin block 2 */
		// Start line: 6292
	/* end block 2 */
	// End Line: 6293

	/* begin block 3 */
		// Start line: 6299
	/* end block 3 */
	// End Line: 6300

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_LevelSelectNew(void)

{
  char cVar1;
  short number;
  char *name;
  char *pcVar2;
  char cVar3;
  
  cVar3 = '\0';
  name = currentMenu[debugMenuChoice].text;
  number = *(short *)&currentMenu[debugMenuChoice].lower;
  cVar1 = *name;
  pcVar2 = name;
  do {
    if (cVar1 == '\0') {
LAB_800145b4:
      if ((gameTrackerX.streamFlags & 0x200000U) != 0) {
        SAVE_SaveGame();
      }
      GAMELOOP_RequestLevelChange(name,number,&gameTrackerX);
      gameTrackerX.levelDone = 4;
      if (cVar3 != '\0') {
        *pcVar2 = cVar3;
      }
      gameTrackerX.gameMode = 0;
      return;
    }
    if (((cVar1 == ' ') || (cVar1 == '\t')) || (cVar1 == '\n')) {
      cVar3 = *pcVar2;
      *pcVar2 = '\0';
      goto LAB_800145b4;
    }
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_SetViewVram()
 // line 3924, offset 0x8001461c
	/* begin block 1 */
		// Start line: 7848
	/* end block 1 */
	// End Line: 7849

	/* begin block 2 */
		// Start line: 6495
	/* end block 2 */
	// End Line: 6496

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_SetViewVram(void)

{
  gameTrackerX.gameMode = 7;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_EndViewVram(struct GameTracker *gameTracker /*$a0*/)
 // line 3929, offset 0x8001462c
	/* begin block 1 */
		// Start line: 6504
	/* end block 1 */
	// End Line: 6505

void DEBUG_EndViewVram(GameTracker *gameTracker)

{
  SetDefDispEnv((undefined2 *)&disp,0,0,0x200,0xf0);
  SetDefDispEnv((undefined2 *)&DISPENV_800d3208,0,0x100,0x200,0xf0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ViewVram(struct GameTracker *gameTracker /*$s1*/)
 // line 3935, offset 0x8001467c
	/* begin block 1 */
		// Start line: 3936
		// Start offset: 0x8001467C
		// Variables:
	// 		long *controlCommand; // $a0
	// 		static int xPos; // offset 0xdfc
	// 		static int yPos; // offset 0xe00
	/* end block 1 */
	// End offset: 0x8001473C
	// End Line: 3962

	/* begin block 2 */
		// Start line: 6518
	/* end block 2 */
	// End Line: 6519

void DEBUG_ViewVram(GameTracker *gameTracker)

{
  if (((gameTracker->controlCommand[1] & 1U) != 0) && (-1 < DAT_800d039c)) {
    DAT_800d039c = DAT_800d039c + -0x20;
  }
  if (((gameTracker->controlCommand[1] & 2U) != 0) && (DAT_800d039c < 0x110)) {
    DAT_800d039c = DAT_800d039c + 0x20;
  }
  if (((gameTracker->controlCommand[1] & 4U) != 0) && (-1 < DAT_800d0398)) {
    DAT_800d0398 = DAT_800d0398 + -0x20;
  }
  if (((gameTracker->controlCommand[1] & 8U) != 0) && (DAT_800d0398 < 0x200)) {
    DAT_800d0398 = DAT_800d0398 + 0x20;
  }
  SetDefDispEnv((undefined2 *)&disp,(short)DAT_800d0398,(short)DAT_800d039c,0x200,0xf0);
  SetDefDispEnv((undefined2 *)&DISPENV_800d3208,(short)DAT_800d0398,(short)DAT_800d039c,0x200,0xf0);
  gameTracker->playerInstance->flags = gameTracker->playerInstance->flags | 0x100;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_CaptureScreen(struct GameTracker *gameTracker /*$a0*/)
 // line 3973, offset 0x8001479c
	/* begin block 1 */
		// Start line: 6597
	/* end block 1 */
	// End Line: 6598

	/* begin block 2 */
		// Start line: 6646
	/* end block 2 */
	// End Line: 6647

void DEBUG_CaptureScreen(GameTracker *gameTracker)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_PageFlip()
 // line 4035, offset 0x800147a4
	/* begin block 1 */
		// Start line: 4036
		// Start offset: 0x800147A4
		// Variables:
	// 		struct POLY_F4 poly; // stack offset -32
	// 		unsigned long **drawot; // $s0
	/* end block 1 */
	// End offset: 0x800147A4
	// End Line: 4036

	/* begin block 2 */
		// Start line: 8064
	/* end block 2 */
	// End Line: 8065

	/* begin block 3 */
		// Start line: 6714
	/* end block 3 */
	// End Line: 6715

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_PageFlip(void)

{
  ulong **ppuVar1;
  undefined auStack32 [3];
  undefined local_1d;
  undefined local_1c;
  undefined local_1b;
  undefined local_1a;
  undefined local_19;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  undefined2 local_10;
  short local_e;
  undefined2 local_c;
  short local_a;
  
  DrawSync(0);
  VSync(0);
  VSync(0);
  VSync(0);
  VSync(0);
  VSync(0);
  DrawSyncCallback(0);
  VSyncCallback(0);
  ResetPrimPool();
  ppuVar1 = gameTrackerX.drawOT;
  gameTrackerX.drawPage = 0;
  PutDrawEnv((undefined4 *)&draw);
  ClearOTagR(ppuVar1,0xc00);
  DrawSync(0);
  local_1d = 5;
  local_19 = 0x28;
  local_1c = 0x20;
  local_1b = 0x20;
  local_1a = 0x20;
  local_18 = 0;
  local_16 = 0xe;
  local_14 = 0x1ff;
  local_12 = 0xe;
  local_10 = 0;
  local_c = 0x1ff;
  local_e = (short)fontTracker.font_ypos + -2;
  local_a = local_e;
  DrawPrim((int)auStack32);
  FONT_Flush();
  DrawOTag(ppuVar1);
  DrawSync(0);
  PutDispEnv((ushort *)gameTrackerX.disp);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_FatalError(char *fmt /*stack 0*/)
 // line 4079, offset 0x800148ac
	/* begin block 1 */
		// Start line: 4080
		// Start offset: 0x800148AC
		// Variables:
	// 		char msg[256]; // stack offset -264
	/* end block 1 */
	// End offset: 0x800148AC
	// End Line: 4080

	/* begin block 2 */
		// Start line: 8158
	/* end block 2 */
	// End Line: 8159

void DEBUG_FatalError(char *fmt)

{
  undefined local_res4 [12];
  char acStack264 [256];
  
  FONT_Flush();
  vsprintf(acStack264,fmt,local_res4);
  FONT_Print(acStack264);
  DEBUG_PageFlip();
  trap(0x407);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ProcessSecondController(struct GameTracker *gameTracker /*$a0*/)
 // line 4436, offset 0x80014900
	/* begin block 1 */
		// Start line: 7521
	/* end block 1 */
	// End Line: 7522

	/* begin block 2 */
		// Start line: 7607
	/* end block 2 */
	// End Line: 7608

void DEBUG_ProcessSecondController(GameTracker *gameTracker)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ProcessCheat(struct GameTracker *gameTracker /*$s3*/)
 // line 4527, offset 0x80014908
	/* begin block 1 */
		// Start line: 4528
		// Start offset: 0x80014908
		// Variables:
	// 		long angleRelCamera; // $s2

		/* begin block 1.1 */
			// Start line: 4554
			// Start offset: 0x800149DC
			// Variables:
		// 		struct SVECTOR v; // stack offset -80
		// 		struct VECTOR dv; // stack offset -72
		// 		struct MATRIX rotate_mat; // stack offset -56
		/* end block 1.1 */
		// End offset: 0x80014A60
		// End Line: 4564
	/* end block 1 */
	// End offset: 0x80014A60
	// End Line: 4565

	/* begin block 2 */
		// Start line: 7703
	/* end block 2 */
	// End Line: 7704

void DEBUG_ProcessCheat(GameTracker *gameTracker)

{
  uint uVar1;
  int iVar2;
  undefined auStack80 [2];
  undefined2 local_4e;
  short local_48 [2];
  short local_44;
  MATRIX MStack56;
  
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
    memset(auStack80,0,8);
    memset(local_48,0,0x10);
    local_4e = 0xff00;
    MATH3D_SetUnityMatrix(&MStack56);
    RotMatrixZ(theCamera.core.rotation.z + iVar2,(uint *)&MStack56);
    ApplyMatrix(&MStack56,auStack80,local_48);
    (gameTracker->playerInstance->position).x =
         (gameTracker->playerInstance->position).x + local_48[0];
    (gameTracker->playerInstance->position).y = (gameTracker->playerInstance->position).y + local_44
    ;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_DoAreaProtection()
 // line 4582, offset 0x80014a7c
	/* begin block 1 */
		// Start line: 4585
		// Start offset: 0x80014A84
	/* end block 1 */
	// End offset: 0x80014A94
	// End Line: 4596

	/* begin block 2 */
		// Start line: 7814
	/* end block 2 */
	// End Line: 7815

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_DoAreaProtection(void)

{
  uint uVar1;
  
  do {
    uVar1 = checkagain();
  } while (uVar1 != 0);
  return;
}





