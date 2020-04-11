
#include "DEBUG.H"


// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_SetGameTime(long *var /*$a0*/)
 // line 1211, offset 0x80012d90
	/* begin block 1 */
		// Start line: 2203
	/* end block 1 */
	// End Line: 2204

	/* begin block 2 */
		// Start line: 2419
	/* end block 2 */
	// End Line: 2420

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_SetGameTime(long *var)

{
  GAMELOOP_SetGameTime(*var);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_KeepGameTime(long *var /*$a0*/)
 // line 1216, offset 0x80012db4
	/* begin block 1 */
		// Start line: 1217
		// Start offset: 0x80012DB4
		// Variables:
	// 		long curTOD; // stack offset -16
	/* end block 1 */
	// End offset: 0x80012DB4
	// End Line: 1217

	/* begin block 2 */
		// Start line: 2213
	/* end block 2 */
	// End Line: 2214

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_KeepGameTime(long *var)

{
  long local_10 [2];
  
  local_10[0] = (int)DAT_800d22ee;
  DEBUG_SetGameTime(local_10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_UpdateFog(long *var /*$a0*/)
 // line 1222, offset 0x80012ddc
	/* begin block 1 */
		// Start line: 1223
		// Start offset: 0x80012DDC
		// Variables:
	// 		struct _StreamUnit *currentUnit; // $v0
	/* end block 1 */
	// End offset: 0x80012DDC
	// End Line: 1223

	/* begin block 2 */
		// Start line: 2227
	/* end block 2 */
	// End Line: 2228

	/* begin block 3 */
		// Start line: 2228
	/* end block 3 */
	// End Line: 2229

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_UpdateFog(long *var)

{
  ushort uVar1;
  Level *pLVar2;
  _StreamUnit *p_Var3;
  uint uVar4;
  
  p_Var3 = FindStreamUnitFromLevel(DAT_800d20f4);
  pLVar2 = DAT_800d20f4;
  uVar1 = (ushort)debugFogFar;
  DAT_800d20f4->fogFar = (ushort)debugFogFar;
  p_Var3->TargetFogFar = uVar1;
  pLVar2->holdFogFar = uVar1;
  pLVar2 = DAT_800d20f4;
  uVar1 = (ushort)debugFogNear;
  DAT_800d20f4->fogNear = (ushort)debugFogNear;
  p_Var3->TargetFogNear = uVar1;
  pLVar2->holdFogNear = uVar1;
  pLVar2 = DAT_800d20f4;
  uVar4 = debugFogBlu << 0x10 | debugFogGrn << 8 | debugFogRed;
  p_Var3->FogColor = uVar4;
  *(uint *)&pLVar2->backColorR = uVar4;
  LIGHT_CalcDQPTable(DAT_800d20f4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_UpdateHealth(long *var /*$a0*/)
 // line 1237, offset 0x80012e64
	/* begin block 1 */
		// Start line: 1238
		// Start offset: 0x80012E64
	/* end block 1 */
	// End offset: 0x80012E64
	// End Line: 1238

	/* begin block 2 */
		// Start line: 2258
	/* end block 2 */
	// End Line: 2259

	/* begin block 3 */
		// Start line: 2259
	/* end block 3 */
	// End Line: 2260

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_UpdateHealth(long *var)

{
  RAZIEL_DebugHealthSetScale(debugHealthLevel);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_FillUpHealth(long *var /*$a0*/)
 // line 1245, offset 0x80012e88
	/* begin block 1 */
		// Start line: 1246
		// Start offset: 0x80012E88
	/* end block 1 */
	// End offset: 0x80012E88
	// End Line: 1246

	/* begin block 2 */
		// Start line: 2275
	/* end block 2 */
	// End Line: 2276

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_FillUpHealth(long *var)

{
  RAZIEL_DebugHealthFillUp();
  RAZIEL_DebugManaFillUp();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_FogLoad()
 // line 1251, offset 0x80012eb0
	/* begin block 1 */
		// Start line: 1252
		// Start offset: 0x80012EB0
		// Variables:
	// 		struct _StreamUnit *currentUnit; // $v0
	/* end block 1 */
	// End offset: 0x80012EB0
	// End Line: 1252

	/* begin block 2 */
		// Start line: 2287
	/* end block 2 */
	// End Line: 2288

	/* begin block 3 */
		// Start line: 2288
	/* end block 3 */
	// End Line: 2289

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_FogLoad(void)

{
  _StreamUnit *p_Var1;
  
  p_Var1 = FindStreamUnitFromLevel(DAT_800d20f4);
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
 // line 1264, offset 0x80012f18
	/* begin block 1 */
		// Start line: 2321
	/* end block 1 */
	// End Line: 2322

	/* begin block 2 */
		// Start line: 2322
	/* end block 2 */
	// End Line: 2323

/* File: C:\kain2\game\DEBUG.C */

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
 // line 1279, offset 0x80012f60
	/* begin block 1 */
		// Start line: 2554
	/* end block 1 */
	// End Line: 2555

	/* begin block 2 */
		// Start line: 2350
	/* end block 2 */
	// End Line: 2351

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_SendCinematicSwitch(void)

{
  DAT_800d2190 = DAT_800d2190 ^ 0x200;
  INSTANCE_Broadcast((_Instance *)0x0,0xe,0x4000e,(uint)((DAT_800d2190 & 0x200) != 0));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_SendMoveTo()
 // line 1293, offset 0x80012fbc
	/* begin block 1 */
		// Start line: 2378
	/* end block 1 */
	// End Line: 2379

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_SendMoveTo(void)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  int Data;
  
  uVar2 = rand();
  sVar1 = *(short *)(DAT_800d20f8 + 0x5c);
  uVar3 = rand();
  Data = SetPositionData((int)sVar1 + (uVar2 & 0x7ff) + -0x400,
                         (int)*(short *)(DAT_800d20f8 + 0x5e) + (uVar3 & 0x7ff) + -0x400,
                         (int)*(short *)(DAT_800d20f8 + 0x60));
  INSTANCE_Broadcast((_Instance *)0x0,0xe,0x4000c,Data);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ process_cheat_codes(struct GameTracker *gt /*$a0*/, long *ctrl /*$a1*/)
 // line 1376, offset 0x80013030
	/* begin block 1 */
		// Start line: 2706
	/* end block 1 */
	// End Line: 2707

	/* begin block 2 */
		// Start line: 2463
	/* end block 2 */
	// End Line: 2464

/* File: C:\kain2\game\DEBUG.C */

void process_cheat_codes(GameTracker *gt,long *ctrl)

{
  if ((cheatCodeLastCommand == 0) && (ctrl[1] != 0)) {
    if (((ctrl[1] & cheatCombo[cheatCodeStage]) == 0) ||
       (cheatCodeStage = cheatCodeStage + 1, (*ctrl & 0x300U) == 0)) {
      cheatCodeStage = 0;
    }
    if (cheatCodeStage == 4) {
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
 // line 1410, offset 0x800130d0
	/* begin block 1 */
		// Start line: 1411
		// Start offset: 0x800130D0
		// Variables:
	// 		long *controlCommand; // $s3
	// 		long oldFlags; // $s2
	// 		long oldFlags2; // $s1
	/* end block 1 */
	// End offset: 0x80013260
	// End Line: 1473

	/* begin block 2 */
		// Start line: 2531
	/* end block 2 */
	// End Line: 2532

/* File: C:\kain2\game\DEBUG.C */

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
    goto LAB_80013230;
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
    goto LAB_80013230;
  }
  DEBUG_Menu(gameTracker);
  if ((gameTracker->debugFlags2 & 0x40000U) == 0) {
LAB_80013188:
    if ((uVar2 & 0x40000) != 0) {
      gameTracker->debugFlags = gameTracker->debugFlags & 0xfffffff7;
    }
  }
  else {
    if ((uVar2 & 0x40000) == 0) {
      gameTracker->debugFlags = gameTracker->debugFlags | 8;
    }
    if ((gameTracker->debugFlags2 & 0x40000U) == 0) goto LAB_80013188;
  }
  if (((gameTracker->debugFlags & 8U) != 0) && ((uVar3 & 8) == 0)) {
    DAT_800d1060 = theCamera;
    DAT_800d1062 = DAT_800d0f9e;
    DAT_800d1064 = DAT_800d0fa0;
    DAT_800d1068 = DAT_800d104c;
    DAT_800d106a = DAT_800d104e;
    DAT_800d106c = DAT_800d1050;
  }
LAB_80013230:
  if (((gameTracker->debugFlags & 0x4000U) != 0) && ((gameTracker->controlCommand[1] & 0x400U) != 0)
     ) {
    DEBUG_CaptureScreen(gameTracker);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_Draw(struct GameTracker *gameTracker /*$a0*/, unsigned long **ot /*$a1*/)
 // line 1483, offset 0x8001327c
	/* begin block 1 */
		// Start line: 2960
	/* end block 1 */
	// End Line: 2961

/* File: C:\kain2\game\DEBUG.C */

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
 // line 1506, offset 0x800132c4
	/* begin block 1 */
		// Start line: 1508
		// Start offset: 0x800132C4
		// Variables:
	// 		int length; // $v1
	// 		struct DebugMenuLine *curLine; // $a0
	/* end block 1 */
	// End offset: 0x800132E8
	// End Line: 1517

	/* begin block 2 */
		// Start line: 2719
	/* end block 2 */
	// End Line: 2720

	/* begin block 3 */
		// Start line: 2720
	/* end block 3 */
	// End Line: 2721

	/* begin block 4 */
		// Start line: 2722
	/* end block 4 */
	// End Line: 2723

/* File: C:\kain2\game\DEBUG.C */

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
 // line 1520, offset 0x800132f0
	/* begin block 1 */
		// Start line: 1521
		// Start offset: 0x800132F0
	/* end block 1 */
	// End offset: 0x80013378
	// End Line: 1550

	/* begin block 2 */
		// Start line: 2747
	/* end block 2 */
	// End Line: 2748

	/* begin block 3 */
		// Start line: 2752
	/* end block 3 */
	// End Line: 2753

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_ExitMenus(void)

{
  long lVar1;
  
  lVar1 = DEBUG_MenuCountLength(currentMenu);
  currentMenu[lVar1].lower = debugMenuChoice;
  if (DAT_800d2291 == '\0') {
    SOUND_MusicOff();
    SOUND_FreeDynamicMusic();
  }
  else {
    SOUND_MusicOn();
  }
  if (DAT_800d2290 == '\0') {
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
 // line 1556, offset 0x80013388
	/* begin block 1 */
		// Start line: 2824
	/* end block 1 */
	// End Line: 2825

	/* begin block 2 */
		// Start line: 2825
	/* end block 2 */
	// End Line: 2826

/* File: C:\kain2\game\DEBUG.C */

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
 // line 1564, offset 0x800133b8
	/* begin block 1 */
		// Start line: 1566
		// Start offset: 0x800133B8
		// Variables:
	// 		int nitems; // $a1
	/* end block 1 */
	// End offset: 0x800133E0
	// End Line: 1570

	/* begin block 2 */
		// Start line: 2840
	/* end block 2 */
	// End Line: 2841

	/* begin block 3 */
		// Start line: 2841
	/* end block 3 */
	// End Line: 2842

	/* begin block 4 */
		// Start line: 2842
	/* end block 4 */
	// End Line: 2843

/* File: C:\kain2\game\DEBUG.C */

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
 // line 1573, offset 0x800133e8
	/* begin block 1 */
		// Start line: 1574
		// Start offset: 0x800133E8
		// Variables:
	// 		long *command; // $s0
	// 		int choice; // $s1
	// 		int nitems; // $a0
	// 		int incr; // $v1
	/* end block 1 */
	// End offset: 0x80013498
	// End Line: 1592

	/* begin block 2 */
		// Start line: 2858
	/* end block 2 */
	// End Line: 2859

/* File: C:\kain2\game\DEBUG.C */

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
 // line 1596, offset 0x800134b0
	/* begin block 1 */
		// Start line: 1597
		// Start offset: 0x800134B0
		// Variables:
	// 		long *command; // $v1

		/* begin block 1.1 */
			// Start line: 1601
			// Start offset: 0x800134D0
			// Variables:
		// 		int incr; // $a2
		/* end block 1.1 */
		// End offset: 0x8001358C
		// End Line: 1618
	/* end block 1 */
	// End offset: 0x8001358C
	// End Line: 1619

	/* begin block 2 */
		// Start line: 2909
	/* end block 2 */
	// End Line: 2910

/* File: C:\kain2\game\DEBUG.C */

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
 // line 1621, offset 0x8001359c
	/* begin block 1 */
		// Start line: 1623
		// Start offset: 0x8001359C
	/* end block 1 */
	// End offset: 0x800135EC
	// End Line: 1630

	/* begin block 2 */
		// Start line: 2960
	/* end block 2 */
	// End Line: 2961

	/* begin block 3 */
		// Start line: 2961
	/* end block 3 */
	// End Line: 2962

	/* begin block 4 */
		// Start line: 2963
	/* end block 4 */
	// End Line: 2964

/* File: C:\kain2\game\DEBUG.C */

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
 // line 1632, offset 0x800135f4
	/* begin block 1 */
		// Start line: 1633
		// Start offset: 0x800135F4
		// Variables:
	// 		int ok; // $v0
	/* end block 1 */
	// End offset: 0x80013620
	// End Line: 1642

	/* begin block 2 */
		// Start line: 2982
	/* end block 2 */
	// End Line: 2983

/* File: C:\kain2\game\DEBUG.C */

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
 // line 1644, offset 0x80013630
	/* begin block 1 */
		// Start line: 1645
		// Start offset: 0x80013630
		// Variables:
	// 		enum option_ctrl_t ctrl; // $a2
	/* end block 1 */
	// End offset: 0x80013684
	// End Line: 1656

	/* begin block 2 */
		// Start line: 3006
	/* end block 2 */
	// End Line: 3007

/* File: C:\kain2\game\DEBUG.C */

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
 // line 1660, offset 0x80013694
	/* begin block 1 */
		// Start line: 1661
		// Start offset: 0x80013694
		// Variables:
	// 		int ok; // $v0
	/* end block 1 */
	// End offset: 0x80013704
	// End Line: 1677

	/* begin block 2 */
		// Start line: 3038
	/* end block 2 */
	// End Line: 3039

/* File: C:\kain2\game\DEBUG.C */

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
 // line 1696, offset 0x80013714
	/* begin block 1 */
		// Start line: 1697
		// Start offset: 0x80013714
		// Variables:
	// 		struct DebugMenuLine *line; // $a1

		/* begin block 1.1 */
			// Start line: 1700
			// Start offset: 0x80013744
			// Variables:
		// 		struct debug_dispatch_t *dispatch; // $v1
		/* end block 1.1 */
		// End offset: 0x80013768
		// End Line: 1705
	/* end block 1 */
	// End offset: 0x80013768
	// End Line: 1706

	/* begin block 2 */
		// Start line: 3111
	/* end block 2 */
	// End Line: 3112

	/* begin block 3 */
		// Start line: 3112
	/* end block 3 */
	// End Line: 3113

/* File: C:\kain2\game\DEBUG.C */

void process_menu_line(GameTracker *gt,DebugMenuLine *menu)

{
  if ((menu[debugMenuChoice].type < DEBUG_LINE_TYPE_ENDLIST) &&
     (debug_dispatch_table[menu[debugMenuChoice].type].fn != (_func_16 *)0x0)) {
    (*debug_dispatch_table[menu[debugMenuChoice].type].fn)();
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ pre_process_functions(struct GameTracker *gt /*$a0*/, struct DebugMenuLine *menu /*$a1*/)
 // line 1710, offset 0x80013778
	/* begin block 1 */
		// Start line: 3140
	/* end block 1 */
	// End Line: 3141

	/* begin block 2 */
		// Start line: 3141
	/* end block 2 */
	// End Line: 3142

/* File: C:\kain2\game\DEBUG.C */

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
 // line 1718, offset 0x800137a0
	/* begin block 1 */
		// Start line: 3156
	/* end block 1 */
	// End Line: 3157

/* File: C:\kain2\game\DEBUG.C */

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
 // line 1771, offset 0x80013844
	/* begin block 1 */
		// Start line: 3262
	/* end block 1 */
	// End Line: 3263

	/* begin block 2 */
		// Start line: 3263
	/* end block 2 */
	// End Line: 3264

/* File: C:\kain2\game\DEBUG.C */

void set_debug_leading(void)

{
  cem_line_leading = 10;
  cem_item_leading = 0xc;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ set_user_leading()
 // line 1777, offset 0x8001385c
	/* begin block 1 */
		// Start line: 3274
	/* end block 1 */
	// End Line: 3275

	/* begin block 2 */
		// Start line: 3276
	/* end block 2 */
	// End Line: 3277

/* File: C:\kain2\game\DEBUG.C */

void set_user_leading(void)

{
  cem_line_leading = 0xc;
  cem_item_leading = 0x10;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ isdigit(char c /*$a0*/)
 // line 1797, offset 0x80013874
	/* begin block 1 */
		// Start line: 3314
	/* end block 1 */
	// End Line: 3315

	/* begin block 2 */
		// Start line: 3315
	/* end block 2 */
	// End Line: 3316

/* File: C:\kain2\game\DEBUG.C */

int isdigit(char c)

{
  return (uint)((byte)(c - 0x30U) < 10);
}



// decompiled code
// original method signature: 
// void /*$ra*/ adjust_format(char *ctrl /*$s1*/, struct debug_format_t *fmt /*$s4*/)
 // line 1802, offset 0x80013884
	/* begin block 1 */
		// Start line: 1803
		// Start offset: 0x80013884

		/* begin block 1.1 */
			// Start line: 1807
			// Start offset: 0x800138EC
			// Variables:
		// 		char *p; // $s0
		// 		int x; // $s2
		// 		int y; // $s3
		/* end block 1.1 */
		// End offset: 0x800139B8
		// End Line: 1821
	/* end block 1 */
	// End offset: 0x80013A08
	// End Line: 1830

	/* begin block 2 */
		// Start line: 3324
	/* end block 2 */
	// End Line: 3325

/* File: C:\kain2\game\DEBUG.C */

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
    iVar2 = strncmp(ctrl,s__abs_800ceed4,5);
    if ((iVar2 == 0) || (iVar2 = strncmp(ctrl,s__rel_800ceedc,5), iVar2 == 0)) {
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
      iVar3 = strncmp(ctrl,s__abs_800ceed4,5);
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
      iVar2 = strncmp(ctrl,s__center_800ceee4,7);
      if (iVar2 != 0) {
        printf(s_unknown_format_control___s_800ceeec,ctrl);
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
 // line 1832, offset 0x80013a2c
	/* begin block 1 */
		// Start line: 3411
	/* end block 1 */
	// End Line: 3412

/* File: C:\kain2\game\DEBUG.C */

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
 // line 1840, offset 0x80013a64
	/* begin block 1 */
		// Start line: 1842
		// Start offset: 0x80013A84

		/* begin block 1.1 */
			// Start line: 1843
			// Start offset: 0x80013A84
			// Variables:
		// 		char *eol; // $s1
		// 		char c; // $s3

			/* begin block 1.1.1 */
				// Start line: 1847
				// Start offset: 0x80013AA8
			/* end block 1.1.1 */
			// End offset: 0x80013AA8
			// End Line: 1847
		/* end block 1.1 */
		// End offset: 0x80013B18
		// End Line: 1863
	/* end block 1 */
	// End offset: 0x80013B34
	// End Line: 1867

	/* begin block 2 */
		// Start line: 3427
	/* end block 2 */
	// End Line: 3428

/* File: C:\kain2\game\DEBUG.C */

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
 // line 1870, offset 0x80013b64
	/* begin block 1 */
		// Start line: 1871
		// Start offset: 0x80013B64
		// Variables:
	// 		struct debug_format_t fmt; // stack offset -56
	// 		int i; // $s3

		/* begin block 1.1 */
			// Start line: 1884
			// Start offset: 0x80013BE4
			// Variables:
		// 		int xpos; // $s2
		// 		int ypos; // $s1
		/* end block 1.1 */
		// End offset: 0x80013D38
		// End Line: 1928
	/* end block 1 */
	// End offset: 0x80013D50
	// End Line: 1929

	/* begin block 2 */
		// Start line: 3510
	/* end block 2 */
	// End Line: 3511

	/* begin block 3 */
		// Start line: 3511
	/* end block 3 */
	// End Line: 3512

/* File: C:\kain2\game\DEBUG.C */

void draw_menu(GameTracker *gt,DebugMenuLine *menu)

{
  int iVar1;
  short x;
  uint uVar2;
  short y;
  int iVar3;
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
    iVar3 = 0;
  }
  else {
    set_debug_leading();
    iVar3 = 0;
  }
  while (iVar1 = local_38.xpos, menu->type != DEBUG_LINE_TYPE_ENDLIST) {
    if (menu->type == DEBUG_LINE_TYPE_FORMAT) {
      adjust_format(menu->text,&local_38);
    }
    else {
      y = (short)local_38.ypos;
      if (debugMenuChoice == iVar3) {
        if (local_38.is_centered == 0) {
          x = (short)local_38.xpos - (short)cem_cursor_width;
        }
        else {
          x = ((short)local_38.xpos - (short)(cem_line_width >> 1)) - (short)cem_cursor_width;
        }
        FONT_SetCursor(x,y);
        FONT_Print(&DAT_800cef08);
      }
      draw_menu_item(gt,&local_38,menu->text);
      if (local_38.is_centered == 0) {
        uVar2 = cem_line_width & 0xffff;
      }
      else {
        uVar2 = cem_line_width >> 1;
      }
      FONT_SetCursor((short)((uVar2 + iVar1) * 0x10000 >> 0x10),y);
      if (menu->type == DEBUG_LINE_TYPE_BIT) {
        if ((*menu->var_address & menu->bit_mask) == menu->bit_mask) {
          FONT_Print((char *)&PTR_DAT_800cef0c);
        }
        else {
          FONT_Print((char *)&PTR_DAT_800cef10);
        }
      }
      else {
        if (menu->type == DEBUG_LINE_TYPE_LONG) {
          FONT_Print((char *)&PTR_DAT_800cef14);
        }
      }
    }
    menu = menu + 1;
    iVar3 = iVar3 + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_Menu(struct GameTracker *gt /*$s1*/)
 // line 1931, offset 0x80013d70
	/* begin block 1 */
		// Start line: 1932
		// Start offset: 0x80013D70
		// Variables:
	// 		struct DebugMenuLine *menu; // $s0
	// 		int choice; // $s2
	/* end block 1 */
	// End offset: 0x80013E6C
	// End Line: 1955

	/* begin block 2 */
		// Start line: 3685
	/* end block 2 */
	// End Line: 3686

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_Menu(GameTracker *gt)

{
  DebugMenuLine *menu;
  long lVar1;
  int iVar2;
  DEBUG_LINE_TYPE DVar3;
  
  lVar1 = debugMenuChoice;
  menu = currentMenu;
  if ((currentMenu == mainMenu) || (currentMenu == pauseMenu)) {
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
 // line 1970, offset 0x80013e84
	/* begin block 1 */
		// Start line: 1971
		// Start offset: 0x80013E84

		/* begin block 1.1 */
			// Start line: 2224
			// Start offset: 0x80014024
			// Variables:
		// 		int deg; // $a0
		/* end block 1.1 */
		// End offset: 0x800140A8
		// End Line: 2237

		/* begin block 1.2 */
			// Start line: 2243
			// Start offset: 0x800140B8
			// Variables:
		// 		long numberInQueue; // stack offset -24
		/* end block 1.2 */
		// End offset: 0x800140D8
		// End Line: 2250
	/* end block 1 */
	// End offset: 0x800140D8
	// End Line: 2287

	/* begin block 2 */
		// Start line: 3772
	/* end block 2 */
	// End Line: 3773

/* File: C:\kain2\game\DEBUG.C */

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
      fmt = s___KG_FRTE__d_800cef28;
    }
    else {
      fmt = s___EF_FRTE__d_800cef18;
    }
    FONT_Print(fmt);
    FONT_Print(s__Focus_XYZ__d__d__d__800cef38);
    if ((gameTracker->debugFlags & 4U) != 0) {
      if (gameTracker->idleTime == 0) {
        FONT_Print(s__IDLE_ZERO_800cef60);
      }
      else {
        FONT_Print(s__IDLE__d_PCT_800cef50);
      }
      FONT_Print(s__DRAW__d_800cef6c);
      FONT_Print(s__INS__d_800cef78);
      FONT_Print(&LAB_800cef84);
      FONT_Print(s__Far_Plane___d_800cef8c);
      FONT_Print(s__Fog_Near____d_Fog_Far____d_800cef9c);
      FONT_Print(s_Military_Time__04d_800cefbc);
    }
    MEMPACK_ReportFreeMemory();
    SAVE_SizeOfFreeSpace();
    FONT_Print(s__FMEM__d_FreeSaveMem__d_800cefd0);
    FONT_Print(s__AREA_DRM____s_800cefec);
    FONT_Print(s__CAM_TILT__d_DIST__d_800ceffc);
  }
  if ((gameTracker->debugFlags < 0) && (iVar1 = STREAM_IsCdBusy(local_18), iVar1 != 0)) {
    FONT_Print(s_Loading_From_CD__In_Queue__d__800cf014);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_DrawShrinkCels(unsigned long **polyAddr /*$a0*/)
 // line 3363, offset 0x800140ec
	/* begin block 1 */
		// Start line: 6539
	/* end block 1 */
	// End Line: 6540

	/* begin block 2 */
		// Start line: 5600
	/* end block 2 */
	// End Line: 5601

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_DrawShrinkCels(ulong **polyAddr)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ContinueGame()
 // line 3535, offset 0x800140f4
	/* begin block 1 */
		// Start line: 7067
	/* end block 1 */
	// End Line: 7068

	/* begin block 2 */
		// Start line: 5774
	/* end block 2 */
	// End Line: 5775

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_ContinueGame(void)

{
  DAT_800d220c = DAT_800d220c | 0x40000000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ExitGame()
 // line 3556, offset 0x8001410c
	/* begin block 1 */
		// Start line: 5814
	/* end block 1 */
	// End Line: 5815

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_ExitGame(void)

{
  SOUND_StopAllSound();
  DAT_800d220c = DAT_800d220c | 1;
  DAT_800d2238 = 2;
  DAT_800d223a = 1;
  DAT_800d223e = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ReloadCurrentLevel()
 // line 3567, offset 0x80014148
	/* begin block 1 */
		// Start line: 5839
	/* end block 1 */
	// End Line: 5840

	/* begin block 2 */
		// Start line: 5840
	/* end block 2 */
	// End Line: 5841

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_ReloadCurrentLevel(void)

{
  if (DAT_800d223a == 0) {
    if ((DAT_800d2210 & 0x200000) != 0) {
      SAVE_SaveGame();
    }
    DAT_800d220c = DAT_800d220c | 1;
    SOUND_ResetAllSound();
    DAT_800d223a = 1;
    DAT_800d2238 = 4;
  }
  DAT_800d223e = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_LevelSelectNew()
 // line 3587, offset 0x800141ac
	/* begin block 1 */
		// Start line: 3588
		// Start offset: 0x800141AC
		// Variables:
	// 		char *name; // $s3
	// 		short number; // $s2
	// 		char *p; // $s0
	// 		char saveChar; // $s1
	/* end block 1 */
	// End offset: 0x8001428C
	// End Line: 3622

	/* begin block 2 */
		// Start line: 5880
	/* end block 2 */
	// End Line: 5881

	/* begin block 3 */
		// Start line: 5887
	/* end block 3 */
	// End Line: 5888

/* File: C:\kain2\game\DEBUG.C */

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
LAB_80014240:
      if ((DAT_800d2210 & 0x200000) != 0) {
        SAVE_SaveGame();
      }
      GAMELOOP_RequestLevelChange(name,number,(GameTracker *)&gameTrackerX);
      DAT_800d2238 = 4;
      if (cVar3 != '\0') {
        *pcVar2 = cVar3;
      }
      DAT_800d223e = 0;
      return;
    }
    if (((cVar1 == ' ') || (cVar1 == '\t')) || (cVar1 == '\n')) {
      cVar3 = *pcVar2;
      *pcVar2 = '\0';
      goto LAB_80014240;
    }
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_SetViewVram()
 // line 3739, offset 0x800142ac
	/* begin block 1 */
		// Start line: 7473
	/* end block 1 */
	// End Line: 7474

	/* begin block 2 */
		// Start line: 6088
	/* end block 2 */
	// End Line: 6089

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_SetViewVram(void)

{
  DAT_800d223e = 7;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_EndViewVram(struct GameTracker *gameTracker /*$a0*/)
 // line 3744, offset 0x800142bc
	/* begin block 1 */
		// Start line: 6097
	/* end block 1 */
	// End Line: 6098

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_EndViewVram(GameTracker *gameTracker)

{
  SetDefDispEnv(disp,0,0,0x200,0xf0);
  SetDefDispEnv(disp + 1,0,0x100,0x200,0xf0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ViewVram(struct GameTracker *gameTracker /*$s1*/)
 // line 3750, offset 0x80014314
	/* begin block 1 */
		// Start line: 3751
		// Start offset: 0x80014314
		// Variables:
	// 		long *controlCommand; // $a0
	// 		static int xPos; // offset 0xe48
	// 		static int yPos; // offset 0xe4c
	/* end block 1 */
	// End offset: 0x800143D4
	// End Line: 3777

	/* begin block 2 */
		// Start line: 6111
	/* end block 2 */
	// End Line: 6112

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_ViewVram(GameTracker *gameTracker)

{
  if (((gameTracker->controlCommand[1] & 1U) != 0) && (-1 < DAT_800cf10c)) {
    DAT_800cf10c = DAT_800cf10c + -0x20;
  }
  if (((gameTracker->controlCommand[1] & 2U) != 0) && (DAT_800cf10c < 0x110)) {
    DAT_800cf10c = DAT_800cf10c + 0x20;
  }
  if (((gameTracker->controlCommand[1] & 4U) != 0) && (-1 < DAT_800cf108)) {
    DAT_800cf108 = DAT_800cf108 + -0x20;
  }
  if (((gameTracker->controlCommand[1] & 8U) != 0) && (DAT_800cf108 < 0x200)) {
    DAT_800cf108 = DAT_800cf108 + 0x20;
  }
  SetDefDispEnv(disp,DAT_800cf108,DAT_800cf10c,0x200,0xf0);
  SetDefDispEnv(disp + 1,DAT_800cf108,DAT_800cf10c,0x200,0xf0);
  gameTracker->playerInstance->flags = gameTracker->playerInstance->flags | 0x100;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_CaptureScreen(struct GameTracker *gameTracker /*$a0*/)
 // line 3787, offset 0x8001443c
	/* begin block 1 */
		// Start line: 6188
	/* end block 1 */
	// End Line: 6189

	/* begin block 2 */
		// Start line: 6232
	/* end block 2 */
	// End Line: 6233

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_CaptureScreen(GameTracker *gameTracker)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_PageFlip()
 // line 3844, offset 0x80014444
	/* begin block 1 */
		// Start line: 3846
		// Start offset: 0x80014450
		// Variables:
	// 		struct POLY_F4 poly; // stack offset -32
	// 		unsigned long **drawot; // $s0
	/* end block 1 */
	// End offset: 0x80014478
	// End Line: 3854

	/* begin block 2 */
		// Start line: 7681
	/* end block 2 */
	// End Line: 7682

	/* begin block 3 */
		// Start line: 6295
	/* end block 3 */
	// End Line: 6296

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_PageFlip(void)

{
  u_long *ot;
  int iVar1;
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
    iVar1 = CheckVolatile(DAT_800d21e8);
  } while (iVar1 != 0);
  do {
    iVar1 = CheckVolatile(DAT_800d21e4);
  } while (iVar1 != 0);
  DrawSync(0);
  DrawSyncCallback((func *)0x0);
  VSyncCallback((f *)0x0);
  ResetPrimPool();
  ot = DAT_800d22a4;
  DAT_800d20fc = 0;
  PutDrawEnv(draw);
  ClearOTagR(ot,0xc00);
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
  local_e = (short)DAT_800d1cfc + -2;
  local_a = local_e;
  DrawPrim(auStack32);
  FONT_Flush();
  DrawOTag(ot);
  DrawSync(0);
  PutDispEnv(DAT_800d21f0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_FatalError(char *fmt /*stack 0*/)
 // line 3883, offset 0x80014550
	/* begin block 1 */
		// Start line: 3884
		// Start offset: 0x80014550
		// Variables:
	// 		char msg[256]; // stack offset -264
	/* end block 1 */
	// End offset: 0x80014550
	// End Line: 3884

	/* begin block 2 */
		// Start line: 7762
	/* end block 2 */
	// End Line: 7763

/* File: C:\kain2\game\DEBUG.C */

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
 // line 4240, offset 0x800145a4
	/* begin block 1 */
		// Start line: 7083
	/* end block 1 */
	// End Line: 7084

	/* begin block 2 */
		// Start line: 7169
	/* end block 2 */
	// End Line: 7170

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_ProcessSecondController(GameTracker *gameTracker)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DEBUG_ProcessCheat(struct GameTracker *gameTracker /*$s3*/)
 // line 4331, offset 0x800145ac
	/* begin block 1 */
		// Start line: 4332
		// Start offset: 0x800145AC
		// Variables:
	// 		long angleRelCamera; // $s2

		/* begin block 1.1 */
			// Start line: 4358
			// Start offset: 0x80014680
			// Variables:
		// 		struct SVECTOR v; // stack offset -80
		// 		struct VECTOR dv; // stack offset -72
		// 		struct MATRIX rotate_mat; // stack offset -56
		/* end block 1.1 */
		// End offset: 0x80014704
		// End Line: 4368
	/* end block 1 */
	// End offset: 0x80014704
	// End Line: 4369

	/* begin block 2 */
		// Start line: 7265
	/* end block 2 */
	// End Line: 7266

/* File: C:\kain2\game\DEBUG.C */

void DEBUG_ProcessCheat(GameTracker *gameTracker)

{
  uint uVar1;
  int iVar2;
  SVECTOR SStack80;
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
    memset();
    memset();
    SStack80.vy = -0x100;
    MATH3D_SetUnityMatrix((char)&MStack56);
    RotMatrixZ(DAT_800d1050 + iVar2,&MStack56);
    ApplyMatrix(&MStack56,&SStack80,(VECTOR *)local_48);
    (gameTracker->playerInstance->position).x =
         (gameTracker->playerInstance->position).x + local_48[0];
    (gameTracker->playerInstance->position).y = (gameTracker->playerInstance->position).y + local_44
    ;
  }
  return;
}





