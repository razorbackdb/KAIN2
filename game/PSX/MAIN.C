#include "THISDUST.H"
#include "MAIN.H"


// decompiled code
// original method signature: 
// void /*$ra*/ ClearDisplay()
 // line 131, offset 0x80038ef0
	/* begin block 1 */
		// Start line: 262
	/* end block 1 */
	// End Line: 263

	/* begin block 2 */
		// Start line: 264
	/* end block 2 */
	// End Line: 265

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ClearDisplay(void)

{
  PutDrawEnv((undefined4 *)(&draw + gameTrackerX.gameData.asmData.dispPage));
  DrawPrim((int)(&clearRect + gameTrackerX.gameData.asmData.dispPage));
  DrawSync(0);
  PutDispEnv((ushort *)(&disp + gameTrackerX.gameData.asmData.dispPage));
  SetDispMask(1);
  printf("ClearDisplay()\n");
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ show_screen(char *name /*$a0*/)
 // line 144, offset 0x80038f88
	/* begin block 1 */
		// Start line: 145
		// Start offset: 0x80038F88
		// Variables:
	// 		long *screen; // $s0
	/* end block 1 */
	// End offset: 0x80038FCC
	// End Line: 151

	/* begin block 2 */
		// Start line: 290
	/* end block 2 */
	// End Line: 291

void show_screen(char *name)

{
  long *addr;
  
  addr = LOAD_ReadFile(name,'\v');
  if (addr != (long *)0x0) {
    LOAD_LoadTIM2(addr,0,gameTrackerX.gameData.asmData.dispPage << 8,0x200,0x100);
    MEMPACK_Free((char *)addr);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DoCinematicStuff(struct GameTracker *gameTracker /*$a0*/, struct MainTracker *mainTracker /*$a1*/)
 // line 186, offset 0x80038fdc
	/* begin block 1 */
		// Start line: 375
	/* end block 1 */
	// End Line: 376

void DoCinematicStuff(GameTracker *gameTracker,MainTracker *mainTracker)

{
  int iVar1;
  
  iVar1 = CINE_Load();
  if (iVar1 != 0) {
    CINE_Play("\\PUBLOGO.STR;1",0x4001,2);
    ClearDisplay();
    CINE_Play("\\CRYLOGO.STR;1",0x4001,2);
    ClearDisplay();
    CINE_Unload();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ play_intro_movie()
 // line 214, offset 0x80039040
	/* begin block 1 */
		// Start line: 431
	/* end block 1 */
	// End Line: 432

/* WARNING: Unknown calling convention yet parameter storage is locked */

void play_intro_movie(void)

{
  int iVar1;
  
  iVar1 = CINE_Load();
  if (iVar1 != 0) {
    CINE_Play("\\KAININT.STR;1",0x4001,2);
    ClearDisplay();
    CINE_Unload();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ InitMainTracker(struct MainTracker *mainTracker /*$a0*/)
 // line 238, offset 0x80039088
	/* begin block 1 */
		// Start line: 479
	/* end block 1 */
	// End Line: 480

	/* begin block 2 */
		// Start line: 480
	/* end block 2 */
	// End Line: 481

void InitMainTracker(MainTracker *mainTracker)

{
  mainTracker->mainState = 0;
  mainTracker->previousState = 0;
  mainTracker->done = 0;
  return;
}



// decompiled code
// original method signature: 
// char * /*$ra*/ FindTextInLine(char *search_match /*$a0*/, char *search_str /*$a1*/)
 // line 245, offset 0x80039098
	/* begin block 1 */
		// Start line: 247
		// Start offset: 0x80039098
		// Variables:
	// 		char *match_pos; // $a2
	/* end block 1 */
	// End offset: 0x80039110
	// End Line: 261

	/* begin block 2 */
		// Start line: 493
	/* end block 2 */
	// End Line: 494

	/* begin block 3 */
		// Start line: 494
	/* end block 3 */
	// End Line: 495

	/* begin block 4 */
		// Start line: 496
	/* end block 4 */
	// End Line: 497

char * FindTextInLine(char *search_match,char *search_str)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  bVar1 = *search_str;
  if ((bVar1 != 0) && (pbVar2 = (byte *)search_match, bVar1 != 10)) {
    while (bVar1 != 0xd) {
      search_str = (char *)((byte *)search_str + 1);
      pbVar3 = (byte *)search_match;
      if ((bVar1 | 0x20) == (*pbVar2 | 0x20)) {
        pbVar3 = pbVar2 + 1;
      }
      if (*pbVar3 == 0) {
        return (char *)(byte *)search_str;
      }
      bVar1 = *search_str;
      if (bVar1 == 0) {
        return (char *)0x0;
      }
      pbVar2 = pbVar3;
      if (bVar1 == 10) {
        return (char *)0x0;
      }
    }
  }
  return (char *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ExtractWorldName(char *worldName /*$a0*/, char *levelName /*$a1*/)
 // line 263, offset 0x80039120
	/* begin block 1 */
		// Start line: 529
	/* end block 1 */
	// End Line: 530

	/* begin block 2 */
		// Start line: 530
	/* end block 2 */
	// End Line: 531

void ExtractWorldName(char *worldName,char *levelName)

{
  byte bVar1;
  
  bVar1 = *levelName;
  while ((bVar1 != 0x2d && (((uint)bVar1 - 0x41 < 0x1a || ((uint)bVar1 - 0x61 < 0x1a))))) {
    levelName = (char *)((byte *)levelName + 1);
    *worldName = bVar1;
    bVar1 = *levelName;
    worldName = (char *)((byte *)worldName + 1);
  }
  *worldName = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ExtractLevelNum(char *levelNum /*$a0*/, char *levelName /*$a1*/)
 // line 272, offset 0x8003916c
	/* begin block 1 */
		// Start line: 547
	/* end block 1 */
	// End Line: 548

	/* begin block 2 */
		// Start line: 548
	/* end block 2 */
	// End Line: 549

void ExtractLevelNum(char *levelNum,char *levelName)

{
  byte bVar1;
  
  bVar1 = *levelName;
  while (bVar1 != 0x2d) {
    if ((uint)bVar1 - 0x30 < 10) goto LAB_800391ac;
    levelName = (char *)((byte *)levelName + 1);
    bVar1 = *levelName;
  }
  bVar1 = *levelName;
  while ((uint)bVar1 - 0x30 < 10) {
LAB_800391ac:
    bVar1 = *levelName;
    levelName = (char *)((byte *)levelName + 1);
    *levelNum = bVar1;
    bVar1 = *levelName;
    levelNum = (char *)((byte *)levelNum + 1);
  }
  *levelNum = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessArgs(char *argFileName /*$a0*/, char *baseAreaName /*$s3*/, struct GameTracker *gameTracker /*$s2*/)
 // line 369, offset 0x800391d8
	/* begin block 1 */
		// Start line: 370
		// Start offset: 0x800391D8
		// Variables:
	// 		char levelNum[32]; // stack offset -88
	// 		char worldName[32]; // stack offset -56
	// 		long *argData; // $s1
	/* end block 1 */
	// End offset: 0x80039400
	// End Line: 589

	/* begin block 2 */
		// Start line: 695
	/* end block 2 */
	// End Line: 696

void ProcessArgs(char *argFileName,char *baseAreaName,GameTracker *gameTracker)

{
  long *levelName;
  char *pcVar1;
  char acStack88 [32];
  char acStack56 [32];
  
  levelName = LOAD_ReadFile(argFileName,'\n');
  if (levelName == (long *)0x0) {
    *(undefined4 *)baseAreaName = 0x65646e75;
    baseAreaName[4] = 'r';
    baseAreaName[5] = '1';
    baseAreaName[6] = '\0';
  }
  else {
    ExtractWorldName(acStack56,(char *)levelName);
    ExtractLevelNum(acStack88,(char *)levelName);
    sprintf(baseAreaName,"%s%s");
    pcVar1 = FindTextInLine("-TIMEOUT",(char *)levelName);
    if (pcVar1 != (char *)0x0) {
      gameTracker->debugFlags = gameTracker->debugFlags | 0x20000;
    }
    pcVar1 = FindTextInLine("-DEMO",(char *)levelName);
    if (pcVar1 != (char *)0x0) {
      gameTrackerX.enemyPlanPool._1_1_ = 1;
    }
    pcVar1 = FindTextInLine("-MAINMENU",(char *)levelName);
    if (pcVar1 != (char *)0x0) {
      DoMainMenu = 1;
    }
    pcVar1 = FindTextInLine("-INSPECTRAL",(char *)levelName);
    if (pcVar1 != (char *)0x0) {
      gameTrackerX.gameData.asmData.MorphType = 1;
    }
    pcVar1 = FindTextInLine("-VOICE",(char *)levelName);
    if (pcVar1 != (char *)0x0) {
      gameTracker->debugFlags = gameTracker->debugFlags | 0x80000;
    }
    pcVar1 = FindTextInLine("-DEBUG_CD",(char *)levelName);
    if (pcVar1 != (char *)0x0) {
      gameTracker->debugFlags = gameTracker->debugFlags | 0x80000000;
    }
    pcVar1 = FindTextInLine("-LOADGAME",(char *)levelName);
    if (pcVar1 != (char *)0x0) {
      gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x200000;
    }
    pcVar1 = FindTextInLine("-ALLWARP",(char *)levelName);
    if (pcVar1 != (char *)0x0) {
      gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x400000;
    }
    *(undefined *)((int)&gameTracker->enemyPlanPool + 3) = 1;
    gameTracker->debugFlags = gameTracker->debugFlags | 0x80000;
    MEMPACK_Free((char *)levelName);
  }
  if ((gameTrackerX.streamFlags & 0x200000U) != 0) {
    *(undefined4 *)baseAreaName = 0x65646e75;
    baseAreaName[4] = 'r';
    baseAreaName[5] = '1';
    baseAreaName[6] = '\0';
    gameTrackerX.gameData.asmData.MorphType = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ InitDisplay()
 // line 591, offset 0x8003941c
	/* begin block 1 */
		// Start line: 592
		// Start offset: 0x8003941C
		// Variables:
	// 		int i; // $a1
	// 		struct RECT r; // stack offset -16
	/* end block 1 */
	// End offset: 0x8003956C
	// End Line: 649

	/* begin block 2 */
		// Start line: 1144
	/* end block 2 */
	// End Line: 1145

/* WARNING: Unknown calling convention yet parameter storage is locked */

void InitDisplay(void)

{
  BLK_FILL *pBVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0x200;
  local_c = 0x2000200;
  ResetGraph(3);
  SetGraphDebug('\0');
  SetDefDrawEnv((undefined2 *)&draw,0,0,0x200,0xf0);
  SetDefDispEnv((undefined2 *)&disp,0,0,0x200,0xf0);
  SetDefDrawEnv((undefined2 *)&DRAWENV_800d1ed8,0,0x100,0x200,0xf0);
  SetDefDispEnv((undefined2 *)&DISPENV_800d1e64,0,0x100,0x200,0xf0);
  iVar2 = 0;
  pBVar1 = &clearRect;
                    /* WARNING: Read-only address (ram,0x800d1eee) is written */
  DRAWENV_800d1ed8.dtd = '\x01';
                    /* WARNING: Read-only address (ram,0x800d1e92) is written */
  draw.dtd = '\x01';
                    /* WARNING: Read-only address (ram,0x800d1eef) is written */
  DRAWENV_800d1ed8.dfe = '\x01';
                    /* WARNING: Read-only address (ram,0x800d1e93) is written */
  draw.dfe = '\x01';
                    /* WARNING: Read-only address (ram,0x800d1ef0) is written */
  DRAWENV_800d1ed8.isbg = '\0';
                    /* WARNING: Read-only address (ram,0x800d1e94) is written */
  draw.isbg = '\0';
                    /* WARNING: Read-only address (ram,0x800d1e95) is written */
  draw.r0 = '\0';
                    /* WARNING: Read-only address (ram,0x800d1e96) is written */
  draw.g0 = '\0';
                    /* WARNING: Read-only address (ram,0x800d1e97) is written */
  draw.b0 = '\0';
                    /* WARNING: Read-only address (ram,0x800d1ef1) is written */
  DRAWENV_800d1ed8.r0 = '\0';
                    /* WARNING: Read-only address (ram,0x800d1ef2) is written */
  DRAWENV_800d1ed8.g0 = '\0';
                    /* WARNING: Read-only address (ram,0x800d1ef3) is written */
  DRAWENV_800d1ed8.b0 = '\0';
  do {
    *(undefined *)((int)&pBVar1->tag + 3) = 3;
    pBVar1->code = '\x02';
    pBVar1->x0 = 0;
    pBVar1->y0 = (ushort)(iVar2 << 8);
    pBVar1->w = 0x200;
    pBVar1->h = 0xf0;
    pBVar1->r0 = '\0';
    pBVar1->g0 = '\0';
    pBVar1->b0 = '\0';
    iVar2 = iVar2 + 1;
    pBVar1 = pBVar1 + 1;
  } while (iVar2 < 2);
  ClearDisplay();
  ClearOTagR((undefined4 *)gameTrackerX.defVVRemoveDist,0xc00);
  ClearOTagR((undefined4 *)gameTrackerX.defRemoveDist,0xc00);
  ClearImage(&local_10,0,0xff,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StartTimer()
 // line 660, offset 0x800395b0
	/* begin block 1 */
		// Start line: 1318
	/* end block 1 */
	// End Line: 1319

/* WARNING: Unknown calling convention yet parameter storage is locked */

void StartTimer(void)

{
  EnterCriticalSection();
  __timerEvent = OpenEvent();
  EnableEvent();
  SetRCnt(0xf2000000,0xffff,0x1001);
  StartRCnt(0xf2000000);
  ExitCriticalSection();
  gTimerEnabled = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VblTick()
 // line 734, offset 0x8003961c
	/* begin block 1 */
		// Start line: 1467
	/* end block 1 */
	// End Line: 1468

	/* begin block 2 */
		// Start line: 1469
	/* end block 2 */
	// End Line: 1470

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VblTick(void)

{
  if (devstation != 0) {
    trap(0x400);
  }
  gameTrackerX.vblFrames = gameTrackerX.vblFrames + 1;
  gameTrackerX.vblCount = gameTrackerX.vblCount + 1;
  if ((gameTrackerX.reqDisp != (void *)0x0) && (DAT_800d223c < gameTrackerX.vblFrames)) {
    PutDispEnv((ushort *)gameTrackerX.reqDisp);
    gameTrackerX.reqDisp = (void *)0x0;
    gameTrackerX.vblFrames = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DrawCallback()
 // line 752, offset 0x80039688
	/* begin block 1 */
		// Start line: 1509
	/* end block 1 */
	// End Line: 1510

	/* begin block 2 */
		// Start line: 1510
	/* end block 2 */
	// End Line: 1511

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DrawCallback(void)

{
  ulong uVar1;
  
  if (gameTrackerX.drawTimerReturn != (long *)0x0) {
    uVar1 = TIMER_TimeDiff(gameTrackerX.usecsStartDraw);
    *gameTrackerX.drawTimerReturn = uVar1;
    gameTrackerX.drawTimerReturn = (long *)0x0;
    gameTrackerX.reqDisp =
         (void *)((int)gameTrackerX.disp + gameTrackerX.gameData.asmData.dispPage * 0x14);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FadeOutSayingLoading(struct GameTracker *gameTracker /*$s0*/)
 // line 802, offset 0x800396e0
	/* begin block 1 */
		// Start line: 803
		// Start offset: 0x800396E0
		// Variables:
	// 		struct POLY_F4_SEMITRANS *transPrim; // $s2
	// 		unsigned long **drawot; // $s3
	// 		long fadeTime; // $s1
	/* end block 1 */
	// End offset: 0x80039804
	// End Line: 831

	/* begin block 2 */
		// Start line: 1600
	/* end block 2 */
	// End Line: 1601

void FadeOutSayingLoading(GameTracker *gameTracker)

{
  int iVar1;
  undefined uVar2;
  int iVar3;
  ulong *puVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar5 = gameTracker->defVVRemoveDist;
  puVar4 = gameTracker->primPool->nextPrim;
  DRAW_TranslucentQuad
            (0,0,0x200,0,0,0xf0,0x200,0xf0,0,0,0,2,gameTracker->primPool,(ulong **)(iVar5 + 4));
  FONT_Flush();
  do {
    gameTracker->drawPage = 1 - gameTracker->drawPage;
    uVar2 = (undefined)iVar3;
    *(undefined *)(puVar4 + 2) = uVar2;
    *(undefined *)((int)puVar4 + 9) = uVar2;
    *(undefined *)((int)puVar4 + 10) = uVar2;
    do {
      iVar1 = CheckVolatile(gameTracker->drawTimerReturn);
    } while (iVar1 != 0);
    PutDrawEnv((undefined4 *)(&draw + gameTracker->drawPage));
    do {
      iVar1 = CheckVolatile(gameTracker->reqDisp);
    } while (iVar1 != 0);
    iVar3 = iVar3 + 0x20;
    iVar1 = (gameTracker->gameData).asmData.dispPage;
    *(ulong **)&gameTracker->drawTimerReturn = &gameTracker->timeMult;
    (gameTracker->gameData).asmData.dispPage = 1 - iVar1;
    DrawOTag((undefined4 *)(iVar5 + 0x2ffc));
  } while (iVar3 < 0xff);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CheckForDevStation()
 // line 833, offset 0x80039824
	/* begin block 1 */
		// Start line: 834
		// Start offset: 0x80039824
		// Variables:
	// 		long *a1; // stack offset -16
	// 		long *a2; // stack offset -12
	/* end block 1 */
	// End offset: 0x80039894
	// End Line: 860

	/* begin block 2 */
		// Start line: 1655
	/* end block 2 */
	// End Line: 1656

/* WARNING: Removing unreachable block (ram,0x80039870) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void CheckForDevStation(void)

{
  DAT_80180000 = 0;
  _DAT_80380000 = 0x12345678;
  devstation = 1;
  GXFilePrint("This is a dev station\n");
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MAIN_ShowLoadingScreen()
 // line 862, offset 0x800398a4
	/* begin block 1 */
		// Start line: 863
		// Start offset: 0x800398A4
		// Variables:
	// 		long *loadingScreen; // $s0
	/* end block 1 */
	// End offset: 0x800398F8
	// End Line: 875

	/* begin block 2 */
		// Start line: 1728
	/* end block 2 */
	// End Line: 1729

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_ShowLoadingScreen(void)

{
  long *addr;
  
  VSync(0);
  addr = LOAD_ReadFile("\\kain2\\game\\psx\\loading.tim",'\v');
  if (addr != (long *)0x0) {
    LOAD_LoadTIM2(addr,0,gameTrackerX.gameData.asmData.dispPage << 8,0x200,0x100);
    MEMPACK_Free((char *)addr);
  }
  return;
}



// decompiled code
// original method signature: 
// long * /*$ra*/ MAIN_LoadTim(char *name /*$a0*/)
 // line 877, offset 0x80039908
	/* begin block 1 */
		// Start line: 878
		// Start offset: 0x80039908
	/* end block 1 */
	// End offset: 0x80039908
	// End Line: 878

	/* begin block 2 */
		// Start line: 1761
	/* end block 2 */
	// End Line: 1762

long * MAIN_LoadTim(char *name)

{
  long *plVar1;
  
  plVar1 = LOAD_ReadFile(name,'\v');
  return plVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ init_menus(struct GameTracker *gt /*$s1*/)
 // line 888, offset 0x80039928
	/* begin block 1 */
		// Start line: 889
		// Start offset: 0x80039928
		// Variables:
	// 		struct menu_t *menu; // $s0
	/* end block 1 */
	// End offset: 0x80039928
	// End Line: 889

	/* begin block 2 */
		// Start line: 1783
	/* end block 2 */
	// End Line: 1784

void init_menus(GameTracker *gt)

{
  ulong allocSize;
  menu_t *menu;
  
  allocSize = menu_data_size();
  menu = (menu_t *)MEMPACK_Malloc(allocSize,'-');
  menu_initialize(menu,gt);
  gt->menu = menu;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MAIN_DoMainInit()
 // line 900, offset 0x80039974
	/* begin block 1 */
		// Start line: 1807
	/* end block 1 */
	// End Line: 1808

/* WARNING: Removing unreachable block (ram,0x800399f4) */
/* WARNING: Removing unreachable block (ram,0x80039a14) */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_DoMainInit(void)

{
  InitDisplay();
  InitGeom();
  SetGeomOffset(0x100,0x78);
  SetGeomScreen(0x140);
  VRAM_InitVramBlockCache();
  FONT_Init();
  gameTrackerX.reqDisp = (void *)0x0;
  VSyncCallback(VblTick);
  DrawSyncCallback(DrawCallback);
  GAMEPAD_Init();
  SOUND_Init();
  VOICEXA_Init();
  init_menus(&gameTrackerX);
  SAVE_Init(&gameTrackerX);
  srand(0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MAIN_ShowPalWarningScreen(struct GameTracker *gameTracker /*$s1*/)
 // line 936, offset 0x80039a58
	/* begin block 1 */
		// Start line: 937
		// Start offset: 0x80039A58
		// Variables:
	// 		long *warningScreen; // $s0
	/* end block 1 */
	// End offset: 0x80039AA8
	// End Line: 946

	/* begin block 2 */
		// Start line: 1880
	/* end block 2 */
	// End Line: 1881

void MAIN_ShowPalWarningScreen(GameTracker *gameTracker)

{
  long *addr;
  
  addr = LOAD_ReadFile("\\kain2\\game\\psx\\warning.tim",'\v');
  if (addr != (long *)0x0) {
    LOAD_LoadTIM(addr,0,(gameTracker->gameData).asmData.dispPage << 8,0,0);
    MEMPACK_Free((char *)addr);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MAIN_MainMenuInit()
 // line 1011, offset 0x80039abc
	/* begin block 1 */
		// Start line: 2014
	/* end block 1 */
	// End Line: 2015

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_MainMenuInit(void)

{
  mainMenuMode = 0;
  mainMenuTimeOut = 0;
  mainMenuScreen = MAIN_LoadTim("\\kain2\\game\\psx\\frontend\\title1.tim");
  menuface_initialize();
  currentMenu = &mainMenu;
  gameTrackerX.gameMode = 4;
  menu_set(gameTrackerX.menu,menudefs_main_menu);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MAIN_FreeMainMenuStuff()
 // line 1032, offset 0x80039b18
	/* begin block 1 */
		// Start line: 2017
	/* end block 1 */
	// End Line: 2018

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_FreeMainMenuStuff(void)

{
  menuface_terminate();
  if (mainMenuScreen != (long *)0x0) {
    MEMPACK_Free((char *)mainMenuScreen);
    mainMenuScreen = (long *)0x0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MAIN_StartGame()
 // line 1063, offset 0x80039b54
	/* begin block 1 */
		// Start line: 2079
	/* end block 1 */
	// End Line: 2080

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_StartGame(void)

{
  mainTrackerX.mainState = 2;
  MAIN_FreeMainMenuStuff();
  currentMenu = &standardMenu;
  gEndGameNow = 0;
  gameTrackerX.gameMode = 0;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MAIN_DoMainMenu(struct GameTracker *gameTracker /*$s0*/, struct MainTracker *mainTracker /*$a1*/, long menuPos /*$a2*/)
 // line 1083, offset 0x80039b8c
	/* begin block 1 */
		// Start line: 1084
		// Start offset: 0x80039B8C
		// Variables:
	// 		unsigned long **drawot; // $s1
	/* end block 1 */
	// End offset: 0x80039BEC
	// End Line: 1153

	/* begin block 2 */
		// Start line: 2122
	/* end block 2 */
	// End Line: 2123

long MAIN_DoMainMenu(GameTracker *gameTracker,MainTracker *mainTracker,long menuPos)

{
  ulong **drawot;
  
  drawot = (ulong **)gameTracker->defVVRemoveDist;
  DrawPrim((int)(&clearRect + gameTracker->drawPage));
  GAMEPAD_Process(gameTracker);
  if (mainMenuScreen != (long *)0x0) {
    LOAD_LoadTIM2(mainMenuScreen,0,gameTracker->drawPage << 8,0x200,0x100);
  }
  DEBUG_Process(gameTracker);
  MENUFACE_RefreshFaces();
  FONT_Flush();
  mainMenuTimeOut = mainMenuTimeOut + 1;
  GAMELOOP_FlipScreenAndDraw(gameTracker,drawot);
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MAIN_ShowFeaturesInit()
 // line 1164, offset 0x80039c38
	/* begin block 1 */
		// Start line: 2312
	/* end block 1 */
	// End Line: 2313

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_ShowFeaturesInit(void)

{
  mainMenuMode = 2;
  mainMenuTimeOut = 0;
  mainMenuFadeInTime = 0x1e;
  mainMenuScreen = MAIN_LoadTim("\\kain2\\game\\psx\\mainmenu\\features.tim");
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MainG2(void *appData /*$fp*/)
 // line 1178, offset 0x80039c70
	/* begin block 1 */
		// Start line: 1179
		// Start offset: 0x80039C70
		// Variables:
	// 		struct MainTracker *mainTracker; // $s3
	// 		struct GameTracker *gameTracker; // $s2
	// 		long menuPos; // $s4
		// Labels:
		//		0x00001548	exit

		/* begin block 1.1 */
			// Start line: 1341
			// Start offset: 0x80039E48
			// Variables:
		// 		struct FullScreenItem *item; // $s1
		// 		int timer; // $s0
		/* end block 1.1 */
		// End offset: 0x80039EC4
		// End Line: 1383
	/* end block 1 */
	// End offset: 0x8003A230
	// End Line: 1669

	/* begin block 2 */
		// Start line: 2344
	/* end block 2 */
	// End Line: 2345

int MainG2(void *appData)

{
  bool bVar1;
  _G2Bool_Enum _Var2;
  int iVar3;
  long menuPos;
  
  menuPos = 0;
  GXFilePrint("Starting \"kain2\" built at %s on %s\n");
  CheckForDevStation();
  mainOptionsInit = '\0';
  _Var2 = MainG2_InitEngine(appData,0x200,0xf0,(char *)0x0);
  if (_Var2 != G2FALSE) {
    MEMPACK_Init();
    LOAD_InitCd();
    StartTimer();
    STREAM_InitLoader("\\BIGFILE.DAT;1","");
    localstr_set_language(~language_english);
    GAMELOOP_SystemInit(&gameTrackerX);
    gameTrackerX.dispOT._1_1_ = 0xff;
    gameTrackerX.dispOT._0_1_ = 0xff;
    gameTrackerX.disp = &disp;
    ProcessArgs("\\kain2\\game\\psx\\kain2.arg",gameTrackerX.baseAreaName,&gameTrackerX);
    InitMainTracker(&mainTrackerX);
    MAIN_DoMainInit();
    mainTrackerX.mainState = 6;
    mainTrackerX.movieNum = 0;
    do {
      mainTrackerX.previousState = mainTrackerX.mainState;
      switch(mainTrackerX.mainState) {
      case 1:
        SOUND_UpdateSound();
        if ((gameTrackerX.debugFlags & 0x80000U) != 0) {
          VOICEXA_Tick();
        }
        PSX_GameLoop(&gameTrackerX);
        if (gameTrackerX.levelDone != 0) {
          FadeOutSayingLoading(&gameTrackerX);
          SOUND_StopAllSound();
          SOUND_FreeDynamicMusic();
          STREAM_DumpAllLevels(0);
          RemoveAllObjects(&gameTrackerX);
          while (iVar3 = aadGetNumLoadsQueued(), iVar3 != 0) {
            aadProcessLoadQueue();
          }
          aadFreeLoadBuffer();
          MEMPACK_FreeByType('\x0e');
          MEMPACK_FreeByType('\x16');
          GAMELOOP_ResetGameStates();
          MEMPACK_DoGarbageCollection();
          if (gameTrackerX.levelDone != 2) {
            if ((gameTrackerX.levelDone != 3) && (gameTrackerX.levelDone != 10)) goto LAB_80039f00;
            goto LAB_8003a180;
          }
          mainTrackerX.mainState = 6;
          mainTrackerX.movieNum = 3;
        }
        break;
      case 2:
      case 0xb:
        if ((gameTrackerX.streamFlags & 0x1000000U) != 0) {
          play_intro_movie();
          gameTrackerX.streamFlags = gameTrackerX.streamFlags & 0xfeffffff;
        }
        if ((gameTrackerX.streamFlags & 0x200000U) == 0) {
          SAVE_ClearMemory(&gameTrackerX);
        }
        else {
          gameTrackerX.streamFlags = gameTrackerX.streamFlags & 0xffdfffff;
        }
        aadInitVolume();
        aadStartMasterVolumeFade
                  (gameTrackerX.sound.gMasterVol,0x100,
                   (TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback)0x0);
        gameTrackerX.sound.soundsLoaded = '\x01';
        aadSetNoUpdateMode(0);
        MAIN_ShowLoadingScreen();
        FONT_ReloadFont();
        DrawSync(0);
        gameTrackerX.frameCount = 0;
        STREAM_Init();
        GAMEPAD_LoadDemo();
        GAMELOOP_LevelLoadAndInit(gameTrackerX.baseAreaName,&gameTrackerX);
        if (gameTrackerX.levelDone == 2) {
          gameTrackerX.gameMode = 9;
          gameTrackerX.gameFlags = gameTrackerX.gameFlags | 1;
        }
        gameTrackerX.levelDone = 0;
        mainTrackerX.mainState = 1;
        gameTrackerX.currentLvl = '\0';
        do {
          iVar3 = STREAM_PollLoadQueue();
        } while (iVar3 != 0);
        gameTrackerX.vblFrames = 0;
        break;
      case 3:
        DrawSync(0);
        MAIN_ShowPalWarningScreen(&gameTrackerX);
        gameTrackerX.vblCount = 0;
        mainTrackerX.mainState = 5;
        break;
      case 4:
        while (mainTrackerX.movieNum == 0) {
          show_screen((char *)&FullScreenItems);
          iVar3 = 1;
          do {
            GAMEPAD_Process(&gameTrackerX);
            if ((300 < iVar3) && ((gameTrackerX.controlCommand[0][1] & 0x80U) != 0)) break;
            VSync(0);
            bVar1 = iVar3 < 300;
            iVar3 = iVar3 + 1;
          } while (bVar1);
          mainTrackerX.movieNum = -1;
        }
        FONT_ReloadFont();
        if ((DoMainMenu == 0) || (gameTrackerX.enemyPlanPool._1_1_ != '\0')) {
LAB_80039f00:
          mainTrackerX.mainState = 2;
        }
        else {
LAB_8003a180:
          mainTrackerX.mainState = 8;
        }
        break;
      case 5:
        if (0x1e < gameTrackerX.vblCount) {
          mainTrackerX.mainState = 6;
          mainTrackerX.movieNum = 0;
        }
        break;
      case 6:
        DoCinematicStuff(&gameTrackerX,&mainTrackerX);
        SOUND_StopAllSound();
        mainTrackerX.movieNum = 0;
        mainTrackerX.mainState = 4;
        break;
      case 7:
        mainTrackerX.done = 1;
        break;
      case 8:
        gameTrackerX.gameData.asmData.MorphType = 0;
        ProcessArgs("\\kain2\\game\\psx\\kain2.arg",gameTrackerX.baseAreaName,&gameTrackerX);
        MAIN_MainMenuInit();
        mainTrackerX.mainState = 9;
        FONT_ReloadFont();
        break;
      case 9:
      case 0xd:
        menuPos = MAIN_DoMainMenu(&gameTrackerX,&mainTrackerX,menuPos);
        break;
      case 0xc:
        MAIN_ShowFeaturesInit();
        mainTrackerX.mainState = 0xd;
        break;
      case 0xe:
        if (gameTrackerX.levelDone == 10) {
          mainTrackerX.mainState = 7;
        }
        else {
          mainTrackerX.mainState = 6;
        }
      }
      STREAM_PollLoadQueue();
    } while (mainTrackerX.done == 0);
    SOUND_StopAllSound();
    SOUND_Free();
    SetDispMask(0);
    DrawSync(0);
    VSync(0);
    DrawSyncCallback(0);
    VSyncCallback(0);
    EnterCriticalSection();
    StopRCnt(0xf2000000);
    DisableEvent();
    CloseEvent();
    ExitCriticalSection();
    VSync(5);
    StopCallback();
    StopPAD();
    ResetGraph(3);
  }
  MainG2_ShutDownEngine(appData);
  return 0;
}





