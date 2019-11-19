#include "THISDUST.H"
#include "DEBUG.H"


// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_SetGameTime(long *var /*$a0*/)
 // line 1190, offset 0x80012c2c
	/* begin block 1 */
		// Start line: 2161
	/* end block 1 */
	// End Line: 2162

	/* begin block 2 */
		// Start line: 2377
	/* end block 2 */
	// End Line: 2378

void DEBUG_SetGameTime(long *var)

{
  GAMELOOP_SetGameTime(*var);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_KeepGameTime(long *var /*$a0*/)
 // line 1195, offset 0x80012c50
	/* begin block 1 */
		// Start line: 1196
		// Start offset: 0x80012C50
		// Variables:
	// 		long curTOD; // stack offset -16
	/* end block 1 */
	// End offset: 0x80012C50
	// End Line: 1196

	/* begin block 2 */
		// Start line: 2171
	/* end block 2 */
	// End Line: 2172

void DEBUG_KeepGameTime(long *var)

{
  long local_10 [2];
  
  local_10[0] = (int)gameTrackerX.currentMaterialTime._2_2_;
  DEBUG_SetGameTime(local_10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_UpdateFog(long *var /*$a0*/)
 // line 1201, offset 0x80012c78
	/* begin block 1 */
		// Start line: 1202
		// Start offset: 0x80012C78
		// Variables:
	// 		struct _StreamUnit *currentUnit; // $v0
	/* end block 1 */
	// End offset: 0x80012C78
	// End Line: 1202

	/* begin block 2 */
		// Start line: 2185
	/* end block 2 */
	// End Line: 2186

	/* begin block 3 */
		// Start line: 2186
	/* end block 3 */
	// End Line: 2187

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
 // line 1216, offset 0x80012d00
	/* begin block 1 */
		// Start line: 1217
		// Start offset: 0x80012D00
	/* end block 1 */
	// End offset: 0x80012D00
	// End Line: 1217

	/* begin block 2 */
		// Start line: 2216
	/* end block 2 */
	// End Line: 2217

	/* begin block 3 */
		// Start line: 2217
	/* end block 3 */
	// End Line: 2218

void DEBUG_UpdateHealth(long *var)

{
  RAZIEL_DebugHealthSetScale(1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_FillUpHealth(long *var /*$a0*/)
 // line 1222, offset 0x80012d24
	/* begin block 1 */
		// Start line: 1223
		// Start offset: 0x80012D24
	/* end block 1 */
	// End offset: 0x80012D24
	// End Line: 1223

	/* begin block 2 */
		// Start line: 2229
	/* end block 2 */
	// End Line: 2230

void DEBUG_FillUpHealth(long *var)

{
  RAZIEL_DebugHealthFillUp();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_FogLoad()
 // line 1228, offset 0x80012d44
	/* begin block 1 */
		// Start line: 1229
		// Start offset: 0x80012D44
		// Variables:
	// 		struct _StreamUnit *currentUnit; // $v0
	/* end block 1 */
	// End offset: 0x80012D44
	// End Line: 1229

	/* begin block 2 */
		// Start line: 2241
	/* end block 2 */
	// End Line: 2242

	/* begin block 3 */
		// Start line: 2242
	/* end block 3 */
	// End Line: 2243

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
 // line 1241, offset 0x80012dac
	/* begin block 1 */
		// Start line: 2275
	/* end block 1 */
	// End Line: 2276

	/* begin block 2 */
		// Start line: 2276
	/* end block 2 */
	// End Line: 2277

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
 // line 1256, offset 0x80012df4
	/* begin block 1 */
		// Start line: 2508
	/* end block 1 */
	// End Line: 2509

	/* begin block 2 */
		// Start line: 2304
	/* end block 2 */
	// End Line: 2305

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_SendCinematicSwitch(void)

{
  gameTrackerX.debugFlags2 = gameTrackerX.debugFlags2 ^ 0x200;
  INSTANCE_Broadcast((_Instance *)0x0,0xe,0x4000e,(uint)((gameTrackerX.debugFlags2 & 0x200U) != 0));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_SendMoveTo()
 // line 1270, offset 0x80012e50
	/* begin block 1 */
		// Start line: 2332
	/* end block 1 */
	// End Line: 2333

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
  INSTANCE_Broadcast((_Instance *)0x0,0xe,0x4000c,Data);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ process_cheat_codes(struct GameTracker *gt /*$a0*/, long *ctrl /*$a1*/)
 // line 1338, offset 0x80012ec4
	/* begin block 1 */
		// Start line: 2645
	/* end block 1 */
	// End Line: 2646

	/* begin block 2 */
		// Start line: 2402
	/* end block 2 */
	// End Line: 2403

void process_cheat_codes(GameTracker *gt,long *ctrl)

{
  uint *puVar1;
  
  if ((cheatCodeLastCommand == 0) && (ctrl[1] != 0)) {
    puVar1 = (uint *)(&cheatCombo + cheatCodeStage);
    cheatCodeStage = cheatCodeStage + 1;
    if ((ctrl[1] & *puVar1) == 0) {
      cheatCodeStage = 0;
    }
    if (cheatCodeStage == 6) {
      cheatCodeStage = 0;
      gt->debugFlags = gt->debugFlags ^ 0x40000;
    }
  }
  cheatCodeLastCommand = ctrl[1];
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_Process(struct GameTracker *gameTracker /*$s0*/)
 // line 1358, offset 0x80012f50
	/* begin block 1 */
		// Start line: 1359
		// Start offset: 0x80012F50
		// Variables:
	// 		long *controlCommand; // $s3
	// 		long oldFlags; // $s2
	// 		long oldFlags2; // $s1
	/* end block 1 */
	// End offset: 0x800130D4
	// End Line: 1418

	/* begin block 2 */
		// Start line: 2442
	/* end block 2 */
	// End Line: 2443

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
    if (*(short *)&gameTracker->plan_collide_override == 1) {
      DEBUG_ProcessCheat(gameTracker);
    }
    goto LAB_800130a4;
  }
  if (sVar1 != 4) {
    if (sVar1 == 6) {
      DEBUG_Menu(gameTracker);
    }
    else {
      if (sVar1 == 7) {
        DEBUG_ViewVram(gameTracker);
      }
    }
    goto LAB_800130a4;
  }
  DEBUG_Menu(gameTracker);
  if ((gameTracker->debugFlags2 & 0x40000U) == 0) {
LAB_80013008:
    if ((uVar2 & 0x40000) != 0) {
      gameTracker->debugFlags = gameTracker->debugFlags & 0xfffffff7;
    }
  }
  else {
    if ((uVar2 & 0x40000) == 0) {
      gameTracker->debugFlags = gameTracker->debugFlags | 8;
    }
    if ((gameTracker->debugFlags2 & 0x40000U) == 0) goto LAB_80013008;
  }
  if (((gameTracker->debugFlags & 8U) != 0) && ((uVar3 & 8) == 0)) {
    theCamera.core.debugPos.x = theCamera.core.position.x;
    theCamera.core.debugPos.y = theCamera.core.position.y;
    theCamera.core.debugPos.z = theCamera.core.position.z;
    theCamera.core.debugRot.x = theCamera.core.rotation.x;
    theCamera.core.debugRot.y = theCamera.core.rotation.y;
    theCamera.core.debugRot.z = theCamera.core.rotation.z;
  }
LAB_800130a4:
  if (((gameTracker->debugFlags & 0x4000U) != 0) && ((gameTracker->controlCommand[1] & 0x400U) != 0)
     ) {
    DEBUG_CaptureScreen(gameTracker);
  }
  process_cheat_codes(gameTracker,gameTracker->controlCommand);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_VoiceTest()
 // line 1422, offset 0x800130fc
	/* begin block 1 */
		// Start line: 2577
	/* end block 1 */
	// End Line: 2578

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_VoiceTest(void)

{
  VOICEXA_Play(0,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_Draw(struct GameTracker *gameTracker /*$a0*/, unsigned long **ot /*$a1*/)
 // line 1429, offset 0x80013120
	/* begin block 1 */
		// Start line: 2592
	/* end block 1 */
	// End Line: 2593

void DEBUG_Draw(GameTracker *gameTracker,ulong **ot)

{
  if (((gameTracker->gameMode == 0) || (*(short *)&gameTracker->plan_collide_override == 1)) ||
     (gameTracker->gameMode == 4)) {
    DEBUG_DisplayStatus(gameTracker);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ DEBUG_MenuCountLength(struct DebugMenuLine *menu /*$a0*/)
 // line 1452, offset 0x80013168
	/* begin block 1 */
		// Start line: 1454
		// Start offset: 0x80013168
		// Variables:
	// 		int length; // $v1
	// 		struct DebugMenuLine *curLine; // $a0
	/* end block 1 */
	// End offset: 0x8001318C
	// End Line: 1463

	/* begin block 2 */
		// Start line: 2638
	/* end block 2 */
	// End Line: 2639

	/* begin block 3 */
		// Start line: 2639
	/* end block 3 */
	// End Line: 2640

	/* begin block 4 */
		// Start line: 2641
	/* end block 4 */
	// End Line: 2642

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
 // line 1466, offset 0x80013194
	/* begin block 1 */
		// Start line: 1467
		// Start offset: 0x80013194
	/* end block 1 */
	// End offset: 0x80013214
	// End Line: 1491

	/* begin block 2 */
		// Start line: 2666
	/* end block 2 */
	// End Line: 2667

	/* begin block 3 */
		// Start line: 2671
	/* end block 3 */
	// End Line: 2672

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_ExitMenus(void)

{
  long lVar1;
  
  lVar1 = DEBUG_MenuCountLength(currentMenu);
  currentMenu[lVar1].lower = debugMenuChoice;
  if (gameTrackerX.sound.gMusicOn == '\0') {
    SOUND_MusicOff();
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
 // line 1497, offset 0x80013224
	/* begin block 1 */
		// Start line: 2733
	/* end block 1 */
	// End Line: 2734

	/* begin block 2 */
		// Start line: 2734
	/* end block 2 */
	// End Line: 2735

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
 // line 1505, offset 0x80013254
	/* begin block 1 */
		// Start line: 1507
		// Start offset: 0x80013254
		// Variables:
	// 		int nitems; // $a1
	/* end block 1 */
	// End offset: 0x8001327C
	// End Line: 1511

	/* begin block 2 */
		// Start line: 2749
	/* end block 2 */
	// End Line: 2750

	/* begin block 3 */
		// Start line: 2750
	/* end block 3 */
	// End Line: 2751

	/* begin block 4 */
		// Start line: 2751
	/* end block 4 */
	// End Line: 2752

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
 // line 1514, offset 0x80013284
	/* begin block 1 */
		// Start line: 1515
		// Start offset: 0x80013284
		// Variables:
	// 		long *command; // $s0
	// 		int choice; // $s1
	// 		int nitems; // $a0
	// 		int incr; // $v1
	/* end block 1 */
	// End offset: 0x80013334
	// End Line: 1533

	/* begin block 2 */
		// Start line: 2767
	/* end block 2 */
	// End Line: 2768

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
      SndPlay(6);
      debugMenuChoice = iVar3;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ handle_line_type_long(struct GameTracker *gt /*$a0*/, struct DebugMenuLine *line /*$a1*/)
 // line 1537, offset 0x8001334c
	/* begin block 1 */
		// Start line: 1538
		// Start offset: 0x8001334C
		// Variables:
	// 		long *command; // $v1

		/* begin block 1.1 */
			// Start line: 1542
			// Start offset: 0x8001336C
			// Variables:
		// 		int incr; // $a2
		/* end block 1.1 */
		// End offset: 0x80013428
		// End Line: 1559
	/* end block 1 */
	// End offset: 0x80013428
	// End Line: 1560

	/* begin block 2 */
		// Start line: 2818
	/* end block 2 */
	// End Line: 2819

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
 // line 1562, offset 0x80013438
	/* begin block 1 */
		// Start line: 1564
		// Start offset: 0x80013438
	/* end block 1 */
	// End offset: 0x80013488
	// End Line: 1571

	/* begin block 2 */
		// Start line: 2869
	/* end block 2 */
	// End Line: 2870

	/* begin block 3 */
		// Start line: 2870
	/* end block 3 */
	// End Line: 2871

	/* begin block 4 */
		// Start line: 2872
	/* end block 4 */
	// End Line: 2873

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
 // line 1573, offset 0x80013490
	/* begin block 1 */
		// Start line: 1574
		// Start offset: 0x80013490
		// Variables:
	// 		int ok; // $v0
	/* end block 1 */
	// End offset: 0x800134BC
	// End Line: 1583

	/* begin block 2 */
		// Start line: 2891
	/* end block 2 */
	// End Line: 2892

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
 // line 1585, offset 0x800134cc
	/* begin block 1 */
		// Start line: 1586
		// Start offset: 0x800134CC
		// Variables:
	// 		enum option_ctrl_t ctrl; // $a2
	/* end block 1 */
	// End offset: 0x80013520
	// End Line: 1597

	/* begin block 2 */
		// Start line: 2915
	/* end block 2 */
	// End Line: 2916

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
 // line 1601, offset 0x80013530
	/* begin block 1 */
		// Start line: 1602
		// Start offset: 0x80013530
		// Variables:
	// 		int ok; // $v0
	/* end block 1 */
	// End offset: 0x800135A0
	// End Line: 1618

	/* begin block 2 */
		// Start line: 2947
	/* end block 2 */
	// End Line: 2948

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
 // line 1637, offset 0x800135b0
	/* begin block 1 */
		// Start line: 1638
		// Start offset: 0x800135B0
		// Variables:
	// 		struct DebugMenuLine *line; // $a1

		/* begin block 1.1 */
			// Start line: 1641
			// Start offset: 0x800135E0
			// Variables:
		// 		struct debug_dispatch_t *dispatch; // $v1
		/* end block 1.1 */
		// End offset: 0x80013604
		// End Line: 1646
	/* end block 1 */
	// End offset: 0x80013604
	// End Line: 1647

	/* begin block 2 */
		// Start line: 3020
	/* end block 2 */
	// End Line: 3021

	/* begin block 3 */
		// Start line: 3021
	/* end block 3 */
	// End Line: 3022

void process_menu_line(GameTracker *gt,DebugMenuLine *menu)

{
  if ((menu[debugMenuChoice].type < DEBUG_LINE_TYPE_ENDLIST) &&
     ((&debug_dispatch_table)[menu[debugMenuChoice].type].fn != (_func_4439 *)0x0)) {
    (*(&debug_dispatch_table)[menu[debugMenuChoice].type].fn)();
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ pre_process_functions(struct GameTracker *gt /*$a0*/, struct DebugMenuLine *menu /*$a1*/)
 // line 1651, offset 0x80013614
	/* begin block 1 */
		// Start line: 3049
	/* end block 1 */
	// End Line: 3050

	/* begin block 2 */
		// Start line: 3050
	/* end block 2 */
	// End Line: 3051

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
 // line 1659, offset 0x8001363c
	/* begin block 1 */
		// Start line: 3065
	/* end block 1 */
	// End Line: 3066

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
 // line 1714, offset 0x800136e0
	/* begin block 1 */
		// Start line: 3175
	/* end block 1 */
	// End Line: 3176

	/* begin block 2 */
		// Start line: 3176
	/* end block 2 */
	// End Line: 3177

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
 // line 1720, offset 0x800136f8
	/* begin block 1 */
		// Start line: 3187
	/* end block 1 */
	// End Line: 3188

	/* begin block 2 */
		// Start line: 3189
	/* end block 2 */
	// End Line: 3190

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
 // line 1740, offset 0x80013710
	/* begin block 1 */
		// Start line: 3227
	/* end block 1 */
	// End Line: 3228

	/* begin block 2 */
		// Start line: 3228
	/* end block 2 */
	// End Line: 3229

int isdigit(char c)

{
  return (uint)((byte)(c - 0x30U) < 10);
}



// decompiled code
// original method signature: 
// void /*$ra*/ adjust_format(char *ctrl /*$s1*/, struct debug_format_t *fmt /*$s4*/)
 // line 1745, offset 0x80013720
	/* begin block 1 */
		// Start line: 1746
		// Start offset: 0x80013720

		/* begin block 1.1 */
			// Start line: 1750
			// Start offset: 0x80013788
			// Variables:
		// 		char *p; // $s0
		// 		int x; // $s2
		// 		int y; // $s3
		/* end block 1.1 */
		// End offset: 0x80013854
		// End Line: 1764
	/* end block 1 */
	// End offset: 0x800138A4
	// End Line: 1773

	/* begin block 2 */
		// Start line: 3237
	/* end block 2 */
	// End Line: 3238

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
 // line 1775, offset 0x800138c8
	/* begin block 1 */
		// Start line: 3324
	/* end block 1 */
	// End Line: 3325

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
 // line 1783, offset 0x80013900
	/* begin block 1 */
		// Start line: 1785
		// Start offset: 0x80013920

		/* begin block 1.1 */
			// Start line: 1786
			// Start offset: 0x80013920
			// Variables:
		// 		char *eol; // $s1
		// 		char c; // $s3

			/* begin block 1.1.1 */
				// Start line: 1790
				// Start offset: 0x80013944
			/* end block 1.1.1 */
			// End offset: 0x80013944
			// End Line: 1790
		/* end block 1.1 */
		// End offset: 0x800139B4
		// End Line: 1806
	/* end block 1 */
	// End offset: 0x800139D0
	// End Line: 1810

	/* begin block 2 */
		// Start line: 3340
	/* end block 2 */
	// End Line: 3341

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
 // line 1813, offset 0x80013a00
	/* begin block 1 */
		// Start line: 1814
		// Start offset: 0x80013A00
		// Variables:
	// 		struct debug_format_t fmt; // stack offset -56
	// 		int i; // $s3

		/* begin block 1.1 */
			// Start line: 1827
			// Start offset: 0x80013A80
			// Variables:
		// 		int xpos; // $s2
		// 		int ypos; // $s1
		/* end block 1.1 */
		// End offset: 0x80013BD4
		// End Line: 1871
	/* end block 1 */
	// End offset: 0x80013BEC
	// End Line: 1872

	/* begin block 2 */
		// Start line: 3423
	/* end block 2 */
	// End Line: 3424

	/* begin block 3 */
		// Start line: 3424
	/* end block 3 */
	// End Line: 3425

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
          FONT_Print("NO");
        }
      }
      else {
        if (menu->type == DEBUG_LINE_TYPE_LONG) {
          FONT_Print("%d");
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
 // line 1874, offset 0x80013c0c
	/* begin block 1 */
		// Start line: 1875
		// Start offset: 0x80013C0C
		// Variables:
	// 		struct DebugMenuLine *menu; // $s0
	// 		int choice; // $s2
	/* end block 1 */
	// End offset: 0x80013D08
	// End Line: 1898

	/* begin block 2 */
		// Start line: 3598
	/* end block 2 */
	// End Line: 3599

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
// void /*$ra*/ DEBUG_DisplayStatus(struct GameTracker *gameTracker /*$s3*/)
 // line 1913, offset 0x80013d20
	/* begin block 1 */
		// Start line: 1914
		// Start offset: 0x80013D20

		/* begin block 1.1 */
			// Start line: 1928
			// Start offset: 0x80013D80
			// Variables:
		// 		short i; // $s1
		/* end block 1.1 */
		// End offset: 0x80013DCC
		// End Line: 1934

		/* begin block 1.2 */
			// Start line: 1937
			// Start offset: 0x80013DE0
			// Variables:
		// 		short i; // $s1
		// 		struct AadSynthVoice *voice; // $s0
		// 		unsigned char spuVoiceStatus[24]; // stack offset -56
		/* end block 1.2 */
		// End offset: 0x800142B4
		// End Line: 2052

		/* begin block 1.3 */
			// Start line: 2165
			// Start offset: 0x80014420
			// Variables:
		// 		int deg; // $a0
		/* end block 1.3 */
		// End offset: 0x800144A4
		// End Line: 2178

		/* begin block 1.4 */
			// Start line: 2184
			// Start offset: 0x800144B4
			// Variables:
		// 		long numberInQueue; // stack offset -32
		/* end block 1.4 */
		// End offset: 0x800144D4
		// End Line: 2191
	/* end block 1 */
	// End offset: 0x800144D4
	// End Line: 2228

	/* begin block 2 */
		// Start line: 3685
	/* end block 2 */
	// End Line: 3686

void DEBUG_DisplayStatus(GameTracker *gameTracker)

{
  AadSynthVoice *pAVar1;
  char *fmt;
  int iVar2;
  int iVar3;
  char acStack32824 [32768];
  char local_38 [8];
  char local_30 [8];
  char local_28 [8];
  long local_20 [2];
  
  STREAM_GetLevelWithID(gameTracker->playerInstance->currentStreamUnitID);
  if ((gameTracker->debugFlags & 0x40000000U) != 0) {
    EVENT_PrintVars();
  }
  if ((gameTracker->debugFlags & 0x10000000U) != 0) {
    FONT_Print("$@QE\n");
    iVar3 = 0;
    iVar2 = 0;
    do {
      aadGetUserVariable(iVar2 >> 0x10);
      FONT_Print("  V%d=%d\n");
      iVar3 = iVar3 + 1;
      iVar2 = iVar3 * 0x10000;
    } while (iVar3 * 0x10000 >> 0x10 < 0x10);
  }
  if ((gameTracker->debugFlags & 0x20000000U) != 0) {
    aadGetVoiceStatus(local_38);
    FONT_Print("$@R]");
    FONT_Print("   id  pri  vol\n");
    iVar3 = 0;
    do {
      pAVar1 = aadGetVoicePointer((int)(short)iVar3);
      if ((local_38[(int)(short)iVar3] == '\0') || (pAVar1->handle == 0)) {
        FONT_Print(" .");
      }
      else {
        FONT_Print(" %d\r");
        FONT_Print("   %d\r");
        FONT_Print("        %d\r");
        FONT_Print("             %d\r");
      }
      FONT_Print("\n");
      iVar3 = iVar3 + 1;
    } while (iVar3 * 0x10000 >> 0x10 < 8);
    FONT_Print("$");
    FONT_Print("\t\t\t\t\t   id  pri  vol\n");
    iVar3 = 8;
    do {
      pAVar1 = aadGetVoicePointer((int)(short)iVar3);
      if ((local_38[(int)(short)iVar3] == '\0') || (pAVar1->handle == 0)) {
        FONT_Print("\t\t\t\t\t .");
      }
      else {
        FONT_Print("\t\t\t\t\t %d\r");
        FONT_Print("\t\t\t\t\t   %d\r");
        FONT_Print("\t\t\t\t\t        %d\r");
        FONT_Print("\t\t\t\t\t             %d\r");
      }
      FONT_Print("\n");
      iVar3 = iVar3 + 1;
    } while (iVar3 * 0x10000 >> 0x10 < 0x10);
    FONT_Print("$");
    FONT_Print("\t\t\t\t\t\t\t\t\t\t   id  pri  vol\n");
    iVar3 = 0x10;
    do {
      pAVar1 = aadGetVoicePointer((int)(short)iVar3);
      if ((local_38[(int)(short)iVar3] == '\0') || (pAVar1->handle == 0)) {
        FONT_Print("\t\t\t\t\t\t\t\t\t\t .");
      }
      else {
        FONT_Print("\t\t\t\t\t\t\t\t\t\t %d\r");
        FONT_Print("\t\t\t\t\t\t\t\t\t\t   %d\r");
        FONT_Print("\t\t\t\t\t\t\t\t\t\t        %d\r");
        FONT_Print("\t\t\t\t\t\t\t\t\t\t             %d\r");
      }
      FONT_Print("\n");
      iVar3 = iVar3 + 1;
    } while (iVar3 * 0x10000 >> 0x10 < 0x18);
    FONT_Print("$\n\n\n\n\n\n\n\n\n");
    FONT_Print("   sl  chn  nte\n");
    iVar3 = 0;
    do {
      pAVar1 = aadGetVoicePointer((int)(short)iVar3);
      if ((local_38[(int)(short)iVar3] == '\0') || (pAVar1->handle != 0)) {
        FONT_Print(" .");
      }
      else {
        FONT_Print(" %d\r");
        FONT_Print("   %x\r");
        FONT_Print("        %d\r");
        FONT_Print("             %d\r");
      }
      FONT_Print("\n");
      iVar3 = iVar3 + 1;
    } while (iVar3 * 0x10000 >> 0x10 < 8);
    FONT_Print("$\n\n\n\n\n\n\n\n\n");
    FONT_Print("\t\t\t\t\t   sl  chn  nte\n");
    iVar3 = 8;
    do {
      pAVar1 = aadGetVoicePointer((int)(short)iVar3);
      if ((local_38[(int)(short)iVar3] == '\0') || (pAVar1->handle != 0)) {
        FONT_Print("\t\t\t\t\t .");
      }
      else {
        FONT_Print("\t\t\t\t\t %d\r");
        FONT_Print("\t\t\t\t\t   %x\r");
        FONT_Print("\t\t\t\t\t        %d\r");
        FONT_Print("\t\t\t\t\t             %d\r");
      }
      FONT_Print("\n");
      iVar3 = iVar3 + 1;
    } while (iVar3 * 0x10000 >> 0x10 < 0x10);
    FONT_Print("$\n\n\n\n\n\n\n\n\n");
    FONT_Print("\t\t\t\t\t\t\t\t\t\t   sl  chn  nte\n");
    iVar3 = 0x10;
    iVar2 = 0x100000;
    do {
      pAVar1 = aadGetVoicePointer(iVar2 >> 0x10);
      if ((local_38[iVar2 >> 0x10] == '\0') || (pAVar1->handle != 0)) {
        FONT_Print("\t\t\t\t\t\t\t\t\t\t .");
      }
      else {
        FONT_Print("\t\t\t\t\t\t\t\t\t\t %d\r");
        FONT_Print("\t\t\t\t\t\t\t\t\t\t   %x\r");
        FONT_Print("\t\t\t\t\t\t\t\t\t\t        %d\r");
        FONT_Print("\t\t\t\t\t\t\t\t\t\t             %d\r");
      }
      FONT_Print("\n");
      iVar3 = iVar3 + 1;
      iVar2 = iVar3 * 0x10000;
    } while (iVar3 * 0x10000 >> 0x10 < 0x18);
  }
  if ((gameTracker->debugFlags & 0x4000004U) != 0) {
    if ((gameTracker->debugFlags & 0x4000000U) == 0) {
      fmt = "$@KG\n FRTE %d\n";
    }
    else {
      FONT_Print("$@EF\n FRTE %d\n");
      fmt = "Military Time %04d\n";
    }
    FONT_Print(fmt);
    FONT_Print(" Focus XYZ(%d,%d,%d)\n");
    if ((gameTracker->debugFlags & 4U) != 0) {
      if (gameTracker[1].gameData.asmData.drawBackFaces == 0) {
        FONT_Print(" IDLE ZERO\n");
      }
      else {
        FONT_Print(" IDLE %d PCT\n");
      }
      FONT_Print(" DRAW %d\n");
      FONT_Print(" INS  %d");
      FONT_Print("/%d\n");
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
  if ((gameTracker->debugFlags < 0) && (iVar3 = STREAM_IsCdBusy(local_20), iVar3 != 0)) {
    FONT_Print("Loading From CD: In Queue(%d)\n");
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_DrawShrinkCels(unsigned long **polyAddr /*$a0*/)
 // line 3304, offset 0x800144f0
	/* begin block 1 */
		// Start line: 6421
	/* end block 1 */
	// End Line: 6422

	/* begin block 2 */
		// Start line: 5595
	/* end block 2 */
	// End Line: 5596

void DEBUG_DrawShrinkCels(ulong **polyAddr)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ContinueGame()
 // line 3476, offset 0x800144f8
	/* begin block 1 */
		// Start line: 6949
	/* end block 1 */
	// End Line: 6950

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_ContinueGame(void)

{
  GAMELOOP_ModeStartRunning();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ExitGame()
 // line 3496, offset 0x80014518
	/* begin block 1 */
		// Start line: 5807
	/* end block 1 */
	// End Line: 5808

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_ExitGame(void)

{
  SOUND_StopAllSound();
  SOUND_DumpAllSound();
  gameTrackerX.levelDone = 3;
  gameTrackerX.levelChange = 1;
  gameTrackerX.gameMode = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ReloadCurrentLevel()
 // line 3508, offset 0x80014550
	/* begin block 1 */
		// Start line: 5834
	/* end block 1 */
	// End Line: 5835

	/* begin block 2 */
		// Start line: 5835
	/* end block 2 */
	// End Line: 5836

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
    gameTrackerX.levelDone = 1;
  }
  gameTrackerX.gameMode = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_LevelSelectNew()
 // line 3528, offset 0x800145b0
	/* begin block 1 */
		// Start line: 3529
		// Start offset: 0x800145B0
		// Variables:
	// 		char *name; // $s3
	// 		short number; // $s2
	// 		char *p; // $s0
	// 		char saveChar; // $s1
	/* end block 1 */
	// End offset: 0x80014688
	// End Line: 3562

	/* begin block 2 */
		// Start line: 5875
	/* end block 2 */
	// End Line: 5876

	/* begin block 3 */
		// Start line: 5882
	/* end block 3 */
	// End Line: 5883

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
LAB_80014644:
      if ((gameTrackerX.streamFlags & 0x200000U) != 0) {
        SAVE_SaveGame();
      }
      GAMELOOP_RequestLevelChange(name,number,&gameTrackerX);
      if (cVar3 != '\0') {
        *pcVar2 = cVar3;
      }
      gameTrackerX.gameMode = 0;
      return;
    }
    if (((cVar1 == ' ') || (cVar1 == '\t')) || (cVar1 == '\n')) {
      cVar3 = *pcVar2;
      *pcVar2 = '\0';
      goto LAB_80014644;
    }
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_MusicSelect()
 // line 3566, offset 0x800146a8
	/* begin block 1 */
		// Start line: 3567
		// Start offset: 0x800146A8
		// Variables:
	// 		char *name; // $s2
	// 		char *p; // $s0
	// 		char saveChar; // $s1
	/* end block 1 */
	// End offset: 0x80014760
	// End Line: 3604

	/* begin block 2 */
		// Start line: 5971
	/* end block 2 */
	// End Line: 5972

	/* begin block 3 */
		// Start line: 5979
	/* end block 3 */
	// End Line: 5980

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_MusicSelect(void)

{
  char cVar1;
  char *newMusicName;
  char *pcVar2;
  char cVar3;
  
  newMusicName = currentMenu[debugMenuChoice].text;
  cVar3 = '\0';
  cVar1 = *newMusicName;
  pcVar2 = newMusicName;
  do {
    if (cVar1 == '\0') {
LAB_80014734:
      aadStopAllSlots();
      aadCancelPauseSound();
      SOUND_FreeDynamicMusic();
      SOUND_LoadDynamicMusic(newMusicName);
      if (cVar3 != '\0') {
        *pcVar2 = cVar3;
      }
      gameTrackerX.gameMode = 0;
      (gameTrackerX.playerInstance)->flags = (gameTrackerX.playerInstance)->flags & 0xfffffeff;
      return;
    }
    if (((cVar1 == ' ') || (cVar1 == '\t')) || (cVar1 == '\n')) {
      cVar3 = *pcVar2;
      *pcVar2 = '\0';
      goto LAB_80014734;
    }
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_PrintSramStatus()
 // line 3648, offset 0x80014790
	/* begin block 1 */
		// Start line: 3649
		// Start offset: 0x80014790
		// Variables:
	// 		struct AadNewSramBlockDesc *sramDescTbl; // $s4
	// 		struct AadNewSramBlockDesc *sramDesc; // $s0
	// 		unsigned short largestFree; // $s1
	// 		unsigned long numWaves; // $s2
	// 		unsigned long totalFree; // $s3
	/* end block 1 */
	// End offset: 0x80014894
	// End Line: 3684

	/* begin block 2 */
		// Start line: 6154
	/* end block 2 */
	// End Line: 6155

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_PrintSramStatus(void)

{
  ushort *puVar1;
  ushort uVar2;
  
  printf("\nSound RAM usage...\n\n");
  puVar1 = (ushort *)((uint)bRam00001b56 * 8 + 0x1754);
  uVar2 = 0;
  while (puVar1 != (ushort *)0x0) {
    if ((*puVar1 & 0x4000) == 0) {
      printf("%05lx-%05lx FREE     Size:%ld\n");
      if (uVar2 < puVar1[2]) {
        uVar2 = puVar1[2];
      }
    }
    else {
      printf("%05lx-%05lx WaveID:%d Size:%ld\n");
    }
    if (*(char *)((int)puVar1 + 7) < '\0') {
      puVar1 = (ushort *)0x0;
    }
    else {
      puVar1 = (ushort *)((uint)*(byte *)((int)puVar1 + 7) * 8 + 0x1754);
    }
  }
  printf("\nTotal Wave Count:%ld  Free Sram:%ld  Largest Free Sram Block:%ld\n");
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_SetViewVram()
 // line 3690, offset 0x800148cc
	/* begin block 1 */
		// Start line: 6252
	/* end block 1 */
	// End Line: 6253

	/* begin block 2 */
		// Start line: 6253
	/* end block 2 */
	// End Line: 6254

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_SetViewVram(void)

{
  gameTrackerX.gameMode = 7;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_EndViewVram(struct GameTracker *gameTracker /*$a0*/)
 // line 3695, offset 0x800148dc
	/* begin block 1 */
		// Start line: 6262
	/* end block 1 */
	// End Line: 6263

void DEBUG_EndViewVram(GameTracker *gameTracker)

{
  SetDefDispEnv((undefined2 *)&disp,0,0,0x200,0xf0);
  SetDefDispEnv((undefined2 *)&DISPENV_800d1e64,0,0x100,0x200,0xf0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ViewVram(struct GameTracker *gameTracker /*$s1*/)
 // line 3701, offset 0x80014934
	/* begin block 1 */
		// Start line: 3702
		// Start offset: 0x80014934
		// Variables:
	// 		long *controlCommand; // $a0
	// 		static int xPos; // offset 0x11f0
	// 		static int yPos; // offset 0x11f4
	/* end block 1 */
	// End offset: 0x800149F4
	// End Line: 3728

	/* begin block 2 */
		// Start line: 6276
	/* end block 2 */
	// End Line: 6277

void DEBUG_ViewVram(GameTracker *gameTracker)

{
  if (((gameTracker->controlCommand[1] & 1U) != 0) && (-1 < DAT_800cdd4c)) {
    DAT_800cdd4c = DAT_800cdd4c + -0x20;
  }
  if (((gameTracker->controlCommand[1] & 2U) != 0) && (DAT_800cdd4c < 0x110)) {
    DAT_800cdd4c = DAT_800cdd4c + 0x20;
  }
  if (((gameTracker->controlCommand[1] & 4U) != 0) && (-1 < DAT_800cdd48)) {
    DAT_800cdd48 = DAT_800cdd48 + -0x20;
  }
  if (((gameTracker->controlCommand[1] & 8U) != 0) && (DAT_800cdd48 < 0x200)) {
    DAT_800cdd48 = DAT_800cdd48 + 0x20;
  }
  SetDefDispEnv((undefined2 *)&disp,(short)DAT_800cdd48,(short)DAT_800cdd4c,0x200,0xf0);
  SetDefDispEnv((undefined2 *)&DISPENV_800d1e64,(short)DAT_800cdd48,(short)DAT_800cdd4c,0x200,0xf0);
  gameTracker->playerInstance->flags = gameTracker->playerInstance->flags | 0x100;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_CaptureScreen(struct GameTracker *gameTracker /*$a0*/)
 // line 3738, offset 0x80014a5c
	/* begin block 1 */
		// Start line: 6353
	/* end block 1 */
	// End Line: 6354

	/* begin block 2 */
		// Start line: 6397
	/* end block 2 */
	// End Line: 6398

void DEBUG_CaptureScreen(GameTracker *gameTracker)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_PageFlip()
 // line 3794, offset 0x80014a64
	/* begin block 1 */
		// Start line: 3796
		// Start offset: 0x80014A70
		// Variables:
	// 		struct POLY_F4 poly; // stack offset -32
	// 		unsigned long **drawot; // $s0
	/* end block 1 */
	// End offset: 0x80014A98
	// End Line: 3804

	/* begin block 2 */
		// Start line: 7581
	/* end block 2 */
	// End Line: 7582

	/* begin block 3 */
		// Start line: 6459
	/* end block 3 */
	// End Line: 6460

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DEBUG_PageFlip(void)

{
  long lVar1;
  int iVar2;
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
  
  do {
    iVar2 = CheckVolatile(gameTrackerX.drawTimerReturn);
  } while (iVar2 != 0);
  do {
    iVar2 = CheckVolatile(gameTrackerX.reqDisp);
  } while (iVar2 != 0);
  DrawSync(0);
  DrawSyncCallback(0);
  VSyncCallback(0);
  ResetPrimPool();
  lVar1 = gameTrackerX.defVVRemoveDist;
  gameTrackerX.drawPage = 0;
  PutDrawEnv((undefined4 *)&draw);
  ClearOTagR((undefined4 *)lVar1,0xc00);
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
  DrawOTag((undefined4 *)lVar1);
  DrawSync(0);
  PutDispEnv((ushort *)gameTrackerX.disp);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_FatalError(char *fmt /*stack 0*/)
 // line 3833, offset 0x80014b70
	/* begin block 1 */
		// Start line: 3834
		// Start offset: 0x80014B70
		// Variables:
	// 		char msg[256]; // stack offset -264
	/* end block 1 */
	// End offset: 0x80014B70
	// End Line: 3834

	/* begin block 2 */
		// Start line: 7662
	/* end block 2 */
	// End Line: 7663

void DEBUG_FatalError(char *fmt)

{
  undefined local_res4 [12];
  char acStack264 [256];
  
  FONT_Flush();
  vsprintf(acStack264,fmt,local_res4);
  GXFilePrint(acStack264);
  FONT_Print(acStack264);
  DEBUG_PageFlip();
  trap(0x407);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ProcessSecondController(struct GameTracker *gameTracker /*$a0*/)
 // line 4190, offset 0x80014bcc
	/* begin block 1 */
		// Start line: 7247
	/* end block 1 */
	// End Line: 7248

	/* begin block 2 */
		// Start line: 7333
	/* end block 2 */
	// End Line: 7334

void DEBUG_ProcessSecondController(GameTracker *gameTracker)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ProcessCheat(struct GameTracker *gameTracker /*$s3*/)
 // line 4281, offset 0x80014bd4
	/* begin block 1 */
		// Start line: 4282
		// Start offset: 0x80014BD4
		// Variables:
	// 		long angleRelCamera; // $s2

		/* begin block 1.1 */
			// Start line: 4308
			// Start offset: 0x80014CA8
			// Variables:
		// 		struct SVECTOR v; // stack offset -80
		// 		struct VECTOR dv; // stack offset -72
		// 		struct MATRIX rotate_mat; // stack offset -56
		/* end block 1.1 */
		// End offset: 0x80014D2C
		// End Line: 4318
	/* end block 1 */
	// End offset: 0x80014D2C
	// End Line: 4319

	/* begin block 2 */
		// Start line: 7429
	/* end block 2 */
	// End Line: 7430

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
    RotMatrixZ(theCamera.core.rotation.z + iVar2,(short *)&MStack56);
    ApplyMatrix(&MStack56,auStack80,local_48);
    (gameTracker->playerInstance->position).x =
         (gameTracker->playerInstance->position).x + local_48[0];
    (gameTracker->playerInstance->position).y = (gameTracker->playerInstance->position).y + local_44
    ;
  }
  return;
}





