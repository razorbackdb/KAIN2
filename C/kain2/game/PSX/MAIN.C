#include "THISDUST.H"
#include "MAIN.H"


// decompiled code
// original method signature: 
// void /*$ra*/ ClearDisplay()
 // line 136, offset 0x800384f8
	/* begin block 1 */
		// Start line: 272
	/* end block 1 */
	// End Line: 273

	/* begin block 2 */
		// Start line: 274
	/* end block 2 */
	// End Line: 275

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ClearDisplay(void)

{
  PutDrawEnv((undefined4 *)(&draw + gameTrackerX.gameData.asmData.dispPage));
  (&clearRect)[gameTrackerX.gameData.asmData.dispPage].r0 = '\0';
  (&clearRect)[gameTrackerX.gameData.asmData.dispPage].g0 = '\0';
  (&clearRect)[gameTrackerX.gameData.asmData.dispPage].b0 = '\0';
  DrawPrim((int)(&clearRect + gameTrackerX.gameData.asmData.dispPage));
  DrawSync(0);
  PutDispEnv((ushort *)(&disp + gameTrackerX.gameData.asmData.dispPage));
  SetDispMask(1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ screen_to_vram(long *screen /*$a0*/, int buffer /*$a1*/)
 // line 150, offset 0x800385b4
	/* begin block 1 */
		// Start line: 302
	/* end block 1 */
	// End Line: 303

void screen_to_vram(long *screen,int buffer)

{
  LOAD_LoadTIM2(screen,0,buffer << 8,0x200,0x100);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ show_screen(char *name /*$a0*/)
 // line 159, offset 0x800385e4
	/* begin block 1 */
		// Start line: 160
		// Start offset: 0x800385E4
		// Variables:
	// 		long *screen; // $s0
	/* end block 1 */
	// End offset: 0x80038618
	// End Line: 167

	/* begin block 2 */
		// Start line: 324
	/* end block 2 */
	// End Line: 325

void show_screen(char *name)

{
  long *screen;
  
  screen = LOAD_ReadFile(name,'\v');
  if (screen != (long *)0x0) {
    screen_to_vram(screen,gameTrackerX.gameData.asmData.dispPage);
    MEMPACK_Free((char *)screen);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ play_movie(char *name /*$s0*/)
 // line 213, offset 0x80038628
	/* begin block 1 */
		// Start line: 433
	/* end block 1 */
	// End Line: 434

void play_movie(char *name)

{
  int iVar1;
  
  iVar1 = CINE_Load();
  if (iVar1 != 0) {
    CINE_Play(name,0xffff,2);
    ClearDisplay();
    CINE_Unload();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ InitMainTracker(struct MainTracker *mainTracker /*$a0*/)
 // line 231, offset 0x80038670
	/* begin block 1 */
		// Start line: 469
	/* end block 1 */
	// End Line: 470

	/* begin block 2 */
		// Start line: 470
	/* end block 2 */
	// End Line: 471

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
 // line 238, offset 0x80038680
	/* begin block 1 */
		// Start line: 240
		// Start offset: 0x80038680
		// Variables:
	// 		char *match_pos; // $a2
	/* end block 1 */
	// End offset: 0x800386F8
	// End Line: 254

	/* begin block 2 */
		// Start line: 483
	/* end block 2 */
	// End Line: 484

	/* begin block 3 */
		// Start line: 484
	/* end block 3 */
	// End Line: 485

	/* begin block 4 */
		// Start line: 486
	/* end block 4 */
	// End Line: 487

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
 // line 256, offset 0x80038708
	/* begin block 1 */
		// Start line: 519
	/* end block 1 */
	// End Line: 520

	/* begin block 2 */
		// Start line: 520
	/* end block 2 */
	// End Line: 521

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
 // line 265, offset 0x80038754
	/* begin block 1 */
		// Start line: 537
	/* end block 1 */
	// End Line: 538

	/* begin block 2 */
		// Start line: 538
	/* end block 2 */
	// End Line: 539

void ExtractLevelNum(char *levelNum,char *levelName)

{
  byte bVar1;
  
  bVar1 = *levelName;
  while (bVar1 != 0x2d) {
    if ((uint)bVar1 - 0x30 < 10) goto LAB_80038794;
    levelName = (char *)((byte *)levelName + 1);
    bVar1 = *levelName;
  }
  bVar1 = *levelName;
  while ((uint)bVar1 - 0x30 < 10) {
LAB_80038794:
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
// void /*$ra*/ ProcessArgs(char *baseAreaName /*$s3*/, struct GameTracker *gameTracker /*$s2*/)
 // line 363, offset 0x800387c0
	/* begin block 1 */
		// Start line: 364
		// Start offset: 0x800387C0
		// Variables:
	// 		char levelNum[32]; // stack offset -88
	// 		char worldName[32]; // stack offset -56
	// 		long *argData; // $s1
	/* end block 1 */
	// End offset: 0x800389BC
	// End Line: 581

	/* begin block 2 */
		// Start line: 726
	/* end block 2 */
	// End Line: 727

void ProcessArgs(char *baseAreaName,GameTracker *gameTracker)

{
  long *levelName;
  char *pcVar1;
  char acStack88 [32];
  char acStack56 [32];
  
  levelName = LOAD_ReadFile("\\kain2\\game\\psx\\kain2.arg",'\n');
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
    pcVar1 = FindTextInLine("-NOSOUND",(char *)levelName);
    if (pcVar1 != (char *)0x0) {
      nosound = 1;
      nomusic = 1;
    }
    pcVar1 = FindTextInLine("-NOMUSIC",(char *)levelName);
    if (pcVar1 != (char *)0x0) {
      nomusic = 1;
    }
    pcVar1 = FindTextInLine("-TIMEOUT",(char *)levelName);
    if (pcVar1 != (char *)0x0) {
      gameTracker->debugFlags = gameTracker->debugFlags | 0x20000;
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
    gameTracker->debugFlags = gameTracker->debugFlags | 0x80000;
    MEMPACK_Free((char *)levelName);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ InitDisplay()
 // line 583, offset 0x800389d8
	/* begin block 1 */
		// Start line: 584
		// Start offset: 0x800389D8
		// Variables:
	// 		int i; // $a1
	// 		struct RECT r; // stack offset -16
	/* end block 1 */
	// End offset: 0x80038B10
	// End Line: 645

	/* begin block 2 */
		// Start line: 1124
	/* end block 2 */
	// End Line: 1125

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
  SetDefDrawEnv((undefined2 *)&DRAWENV_800d327c,0,0x100,0x200,0xf0);
  SetDefDispEnv((undefined2 *)&DISPENV_800d3208,0,0x100,0x200,0xf0);
  iVar2 = 0;
  pBVar1 = &clearRect;
                    /* WARNING: Read-only address (ram,0x800d3292) is written */
  DRAWENV_800d327c.dtd = '\x01';
                    /* WARNING: Read-only address (ram,0x800d3236) is written */
  draw.dtd = '\x01';
                    /* WARNING: Read-only address (ram,0x800d3293) is written */
  DRAWENV_800d327c.dfe = '\x01';
                    /* WARNING: Read-only address (ram,0x800d3237) is written */
  draw.dfe = '\x01';
                    /* WARNING: Read-only address (ram,0x800d3294) is written */
  DRAWENV_800d327c.isbg = '\0';
                    /* WARNING: Read-only address (ram,0x800d3238) is written */
  draw.isbg = '\0';
                    /* WARNING: Read-only address (ram,0x800d3239) is written */
  draw.r0 = '\0';
                    /* WARNING: Read-only address (ram,0x800d323a) is written */
  draw.g0 = '\0';
                    /* WARNING: Read-only address (ram,0x800d323b) is written */
  draw.b0 = '\0';
                    /* WARNING: Read-only address (ram,0x800d3295) is written */
  DRAWENV_800d327c.r0 = '\0';
                    /* WARNING: Read-only address (ram,0x800d3296) is written */
  DRAWENV_800d327c.g0 = '\0';
                    /* WARNING: Read-only address (ram,0x800d3297) is written */
  DRAWENV_800d327c.b0 = '\0';
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
  ClearOTagR(gameTrackerX.drawOT,0xc00);
  ClearOTagR(gameTrackerX.dispOT,0xc00);
  ClearImage(&local_10,0,0xff,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StartTimer()
 // line 661, offset 0x80038b54
	/* begin block 1 */
		// Start line: 1316
	/* end block 1 */
	// End Line: 1317

/* WARNING: Unknown calling convention yet parameter storage is locked */

void StartTimer(void)

{
  EnterCriticalSection();
  __timerEvent = OpenEvent();
  EnableEvent();
  SetRCnt(0xf2000000,0xffff,(uint)&DAT_00001001);
  StartRCnt(0xf2000000);
  ExitCriticalSection();
  gTimerEnabled = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VblTick()
 // line 734, offset 0x80038bc0
	/* begin block 1 */
		// Start line: 1463
	/* end block 1 */
	// End Line: 1464

	/* begin block 2 */
		// Start line: 1466
	/* end block 2 */
	// End Line: 1467

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VblTick(void)

{
  if (devstation != 0) {
    trap(0x400);
  }
  gameTrackerX.vblFrames = gameTrackerX.vblFrames + 1;
  gameTrackerX.vblCount = gameTrackerX.vblCount + 1;
  if ((gameTrackerX.reqDisp != (void *)0x0) &&
     ((uint)gameTrackerX.frameRateLock < gameTrackerX.vblFrames)) {
    PutDispEnv((ushort *)gameTrackerX.reqDisp);
    gameTrackerX.reqDisp = (void *)0x0;
    gameTrackerX.vblFrames = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DrawCallback()
 // line 754, offset 0x80038c2c
	/* begin block 1 */
		// Start line: 1510
	/* end block 1 */
	// End Line: 1511

	/* begin block 2 */
		// Start line: 1511
	/* end block 2 */
	// End Line: 1512

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
// void /*$ra*/ FadeOutSayingLoading(struct GameTracker *gameTracker /*$s1*/)
 // line 765, offset 0x80038c84
	/* begin block 1 */
		// Start line: 766
		// Start offset: 0x80038C84
		// Variables:
	// 		struct POLY_F4_SEMITRANS *transPrim; // $s2
	// 		unsigned long **drawot; // $s3
	// 		long fadeTime; // $s0
	/* end block 1 */
	// End offset: 0x80038DB4
	// End Line: 799

	/* begin block 2 */
		// Start line: 1534
	/* end block 2 */
	// End Line: 1535

void FadeOutSayingLoading(GameTracker *gameTracker)

{
  bool bVar1;
  int iVar2;
  undefined uVar3;
  int iVar4;
  ulong *puVar5;
  ulong **ot;
  
  ot = gameTracker->drawOT;
  puVar5 = gameTracker->primPool->nextPrim;
  DRAW_TranslucentQuad(0,0,0x200,0,0,0xf0,0x200,0xf0,0,0,0,2,gameTracker->primPool,ot);
  iVar4 = 0x10;
  FONT_Flush();
  do {
    if (0xff < iVar4) {
      iVar4 = 0xff;
    }
    gameTracker->drawPage = 1 - gameTracker->drawPage;
    uVar3 = (undefined)iVar4;
    *(undefined *)(puVar5 + 2) = uVar3;
    *(undefined *)((int)puVar5 + 9) = uVar3;
    *(undefined *)((int)puVar5 + 10) = uVar3;
    do {
      iVar2 = CheckVolatile(gameTracker->drawTimerReturn);
    } while (iVar2 != 0);
    PutDrawEnv((undefined4 *)(&draw + gameTracker->drawPage));
    do {
      iVar2 = CheckVolatile(gameTracker->reqDisp);
    } while (iVar2 != 0);
    iVar2 = (gameTracker->gameData).asmData.dispPage;
    *(ulong **)&gameTracker->drawTimerReturn = &gameTracker->drawTime;
    (gameTracker->gameData).asmData.dispPage = 1 - iVar2;
    VSync(0);
    DrawOTag(ot + 0xbff);
    bVar1 = iVar4 != 0xff;
    iVar4 = iVar4 + 0x10;
  } while (bVar1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CheckForDevStation()
 // line 801, offset 0x80038dd4
	/* begin block 1 */
		// Start line: 802
		// Start offset: 0x80038DD4
		// Variables:
	// 		long *a1; // stack offset -8
	// 		long *a2; // stack offset -4
	/* end block 1 */
	// End offset: 0x80038E2C
	// End Line: 827

	/* begin block 2 */
		// Start line: 1628
	/* end block 2 */
	// End Line: 1629

/* WARNING: Removing unreachable block (ram,0x80038e1c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void CheckForDevStation(void)

{
  devstation = 1;
  DAT_80180000 = 0;
  _DAT_80380000 = 0x12345678;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MAIN_ShowLoadingScreen()
 // line 829, offset 0x80038e34
	/* begin block 1 */
		// Start line: 830
		// Start offset: 0x80038E34
		// Variables:
	// 		long *loadingScreen; // $s0
	// 		char langChar[5]; // stack offset -88
	// 		int lang; // $v0

		/* begin block 1.1 */
			// Start line: 838
			// Start offset: 0x80038E7C
			// Variables:
		// 		char filename[64]; // stack offset -80
		/* end block 1.1 */
		// End offset: 0x80038E7C
		// End Line: 839
	/* end block 1 */
	// End offset: 0x80038ED0
	// End Line: 856

	/* begin block 2 */
		// Start line: 1685
	/* end block 2 */
	// End Line: 1686

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_ShowLoadingScreen(void)

{
  language_t lVar1;
  long *screen;
  char *string;
  char acStack80 [64];
  
  VSync(0);
  lVar1 = localstr_get_language();
  if (lVar1 == language_english) {
    string = "\\kain2\\game\\psx\\loading.tim";
  }
  else {
    string = acStack80;
    sprintf(string,"\\kain2\\game\\psx\\loading%c.tim");
  }
  screen = LOAD_ReadFile(string,'\v');
  if (screen != (long *)0x0) {
    screen_to_vram(screen,gameTrackerX.gameData.asmData.dispPage);
    MEMPACK_Free((char *)screen);
  }
  return;
}



// decompiled code
// original method signature: 
// long * /*$ra*/ MAIN_LoadTim(char *name /*$a0*/)
 // line 858, offset 0x80038ee4
	/* begin block 1 */
		// Start line: 859
		// Start offset: 0x80038EE4
	/* end block 1 */
	// End offset: 0x80038EE4
	// End Line: 859

	/* begin block 2 */
		// Start line: 1749
	/* end block 2 */
	// End Line: 1750

long * MAIN_LoadTim(char *name)

{
  long *plVar1;
  
  plVar1 = LOAD_ReadFile(name,'\v');
  return plVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ init_menus(struct GameTracker *gt /*$s1*/)
 // line 869, offset 0x80038f04
	/* begin block 1 */
		// Start line: 870
		// Start offset: 0x80038F04
		// Variables:
	// 		struct menu_t *menu; // $s0
	/* end block 1 */
	// End offset: 0x80038F04
	// End Line: 870

	/* begin block 2 */
		// Start line: 1771
	/* end block 2 */
	// End Line: 1772

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
 // line 881, offset 0x80038f50
	/* begin block 1 */
		// Start line: 1795
	/* end block 1 */
	// End Line: 1796

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
  if (nosound != 0) {
    SOUND_SfxOff();
    gameTrackerX.sound.gSfxOn = '\0';
    gameTrackerX.sound.gVoiceOn = '\0';
  }
  if (nomusic != 0) {
    SOUND_MusicOff();
    gameTrackerX.sound.gMusicOn = '\0';
  }
  if ((gameTrackerX.debugFlags & 0x80000U) == 0) {
    gameTrackerX.sound.gVoiceOn = '\0';
  }
  init_menus(&gameTrackerX);
  SAVE_Init(&gameTrackerX);
  srand(0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MAIN_InitVolume()
 // line 928, offset 0x80039044
	/* begin block 1 */
		// Start line: 1856
	/* end block 1 */
	// End Line: 1857

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_InitVolume(void)

{
  aadInitVolume();
  aadStartMasterVolumeFade
            (gameTrackerX.sound.gMasterVol,0x100,
             (TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback)0x0);
  gameTrackerX.sound.soundsLoaded = '\x01';
  aadSetNoUpdateMode(0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MAIN_ResetGame()
 // line 936, offset 0x80039084
	/* begin block 1 */
		// Start line: 1889
	/* end block 1 */
	// End Line: 1890

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_ResetGame(void)

{
  GAMELOOP_SetScreenWipe(0,0,-1);
  gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffffff6e;
  RAZIEL_StartNewGame();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MAIN_MainMenuInit()
 // line 946, offset 0x800390d4
	/* begin block 1 */
		// Start line: 947
		// Start offset: 0x800390D4

		/* begin block 1.1 */
			// Start line: 947
			// Start offset: 0x800390D4
			// Variables:
		// 		char sfxFileName[64]; // stack offset -72
		/* end block 1.1 */
		// End offset: 0x800391F8
		// End Line: 967
	/* end block 1 */
	// End offset: 0x800391F8
	// End Line: 969

	/* begin block 2 */
		// Start line: 1910
	/* end block 2 */
	// End Line: 1911

/* WARNING: Removing unreachable block (ram,0x800390f8) */
/* WARNING: Removing unreachable block (ram,0x800390fc) */
/* WARNING: Removing unreachable block (ram,0x80039148) */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_MainMenuInit(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  long lVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 local_48 [10];
  undefined auStack32 [24];
  
  mainMenuMode = 0;
  mainMenuTimeOut = 0;
  puVar1 = (undefined4 *)"\\kain2\\sfx\\object\\mainmenu\\mainmenu.snf";
  puVar2 = local_48;
  do {
    puVar6 = puVar2;
    puVar5 = puVar1;
    uVar7 = puVar5[1];
    uVar8 = puVar5[2];
    uVar9 = puVar5[3];
    *puVar6 = *puVar5;
    puVar6[1] = uVar7;
    puVar6[2] = uVar8;
    puVar6[3] = uVar9;
    puVar1 = puVar5 + 4;
    puVar2 = puVar6 + 4;
  } while (puVar5 + 4 != (undefined4 *)0x800d0c7c);
  uVar7 = puVar5[5];
  puVar6[4] = 0x2e756e65;
  puVar6[5] = uVar7;
  memset(auStack32,0,0x18);
  mainMenuSfx = 0;
  lVar3 = LOAD_DoesFileExist((char *)local_48);
  if (lVar3 != 0) {
    mainMenuSfx = aadLoadDynamicSfx("mainmenu",0,0);
    while (iVar4 = aadGetNumLoadsQueued(), iVar4 != 0) {
      aadProcessLoadQueue();
    }
  }
  mainMenuScreen = MAIN_LoadTim("\\kain2\\game\\psx\\frontend\\title1.tim");
  VRAM_EnableTerrainArea();
  menuface_initialize();
  currentMenu = &mainMenu;
  gameTrackerX.gameMode = 4;
  menu_set(gameTrackerX.menu,menudefs_main_menu);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MAIN_FreeMainMenuStuff()
 // line 983, offset 0x8003924c
	/* begin block 1 */
		// Start line: 1999
	/* end block 1 */
	// End Line: 2000

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_FreeMainMenuStuff(void)

{
  int iVar1;
  
  menuface_terminate();
  VRAM_DisableTerrainArea();
  if (mainMenuScreen != (long *)0x0) {
    MEMPACK_Free((char *)mainMenuScreen);
    mainMenuScreen = (long *)0x0;
  }
  aadFreeDynamicSfx(mainMenuSfx);
  while (iVar1 = aadGetNumLoadsQueued(), iVar1 != 0) {
    aadProcessLoadQueue();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MAIN_StartGame()
 // line 1018, offset 0x800392bc
	/* begin block 1 */
		// Start line: 2069
	/* end block 1 */
	// End Line: 2070

	/* begin block 2 */
		// Start line: 2070
	/* end block 2 */
	// End Line: 2071

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_StartGame(void)

{
  if (mainMenuFading == 0) {
    gameTrackerX.gameMode = 0;
    currentMenu = (DebugMenuLine *)0x0;
    mainMenuFading = 1;
    GAMELOOP_SetScreenWipe(-0x1e,0x1e,10);
  }
  else {
    mainTrackerX.mainState = 2;
    MAIN_FreeMainMenuStuff();
    gEndGameNow = 0;
    mainMenuFading = 0;
    currentMenu = &standardMenu;
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MAIN_DoMainMenu(struct GameTracker *gameTracker /*$s0*/, struct MainTracker *mainTracker /*$a1*/, long menuPos /*$a2*/)
 // line 1057, offset 0x80039328
	/* begin block 1 */
		// Start line: 1058
		// Start offset: 0x80039328
		// Variables:
	// 		unsigned long **drawot; // $s1
	/* end block 1 */
	// End offset: 0x800393E4
	// End Line: 1146

	/* begin block 2 */
		// Start line: 2153
	/* end block 2 */
	// End Line: 2154

long MAIN_DoMainMenu(GameTracker *gameTracker,MainTracker *mainTracker,long menuPos)

{
  ulong **drawot;
  
  gameTrackerX.timeMult = 0x1000;
  drawot = gameTracker->drawOT;
  DrawPrim((int)(&clearRect + gameTracker->drawPage));
  GAMEPAD_Process(gameTracker);
  DEBUG_Process(gameTracker);
  if (mainMenuScreen != (long *)0x0) {
    screen_to_vram(mainMenuScreen,gameTracker->drawPage);
  }
  GAMELOOP_HandleScreenWipes(drawot);
  MENUFACE_RefreshFaces();
  FONT_Flush();
  mainMenuTimeOut = mainMenuTimeOut + 1;
  GAMELOOP_FlipScreenAndDraw(gameTracker,drawot);
  if ((mainMenuFading != 0) && (gameTracker->wipeTime == -1)) {
    MAIN_StartGame();
  }
  return 0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MainG2(void *appData /*$s7*/)
 // line 1157, offset 0x800393fc
	/* begin block 1 */
		// Start line: 1158
		// Start offset: 0x800393FC
		// Variables:
	// 		struct MainTracker *mainTracker; // $s2
	// 		struct GameTracker *gameTracker; // $s3
	// 		long menuPos; // $s5
		// Labels:
		//		0x000016F8	exit

		/* begin block 1.1 */
			// Start line: 1345
			// Start offset: 0x80039618
			// Variables:
		// 		struct InterfaceItem *item; // $s1
		// 		int timer; // $s0
		/* end block 1.1 */
		// End offset: 0x800396C8
		// End Line: 1405

		/* begin block 1.2 */
			// Start line: 1585
			// Start offset: 0x80039884
		/* end block 1.2 */
		// End offset: 0x80039970
		// End Line: 1655
	/* end block 1 */
	// End offset: 0x80039A20
	// End Line: 1706

	/* begin block 2 */
		// Start line: 2314
	/* end block 2 */
	// End Line: 2315

int MainG2(void *appData)

{
  bool bVar1;
  long lVar2;
  _G2Bool_Enum _Var3;
  int iVar4;
  long menuPos;
  
  menuPos = 0;
  CheckForDevStation();
  mainOptionsInit = '\0';
  _Var3 = MainG2_InitEngine(appData,0x200,0xf0,(char *)0x0);
  if (_Var3 != G2FALSE) {
    MEMPACK_Init();
    LOAD_InitCd();
    StartTimer();
    STREAM_InitLoader("\\BIGFILE.DAT;1","");
    localstr_set_language(~language_english);
    GAMELOOP_SystemInit(&gameTrackerX);
    gameTrackerX.lastLvl = -1;
    gameTrackerX.currentLvl = -1;
    gameTrackerX.disp = &disp;
    ProcessArgs(gameTrackerX.baseAreaName,&gameTrackerX);
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
          aadStopAllSfx();
          STREAM_DumpAllLevels(0,0);
          RemoveAllObjects(&gameTrackerX);
          while ((iVar4 = aadGetNumLoadsQueued(), iVar4 != 0 ||
                 ((aadMem->sramDefragInfo).status != 0))) {
            SOUND_UpdateSound();
            STREAM_PollLoadQueue();
          }
          SOUND_ShutdownMusic();
          MEMPACK_FreeByType('\x0e');
          GAMELOOP_ResetGameStates();
          MEMPACK_DoGarbageCollection();
          iVar4 = (int)gameTrackerX.levelDone;
          if (iVar4 == 2) {
LAB_8003991c:
            mainTrackerX.mainState = 8;
          }
          else {
            if (iVar4 == 3) {
              mainTrackerX.mainState = 6;
              mainTrackerX.movieNum = iVar4;
            }
            else {
              if (iVar4 == 4) {
                mainTrackerX.mainState = 2;
                if ((gameTrackerX.streamFlags & 0x200000U) == 0) {
                  SAVE_ClearMemory(&gameTrackerX);
                }
              }
              else {
                mainTrackerX.mainState = 2;
              }
            }
          }
        }
        break;
      case 2:
        if ((gameTrackerX.streamFlags & 0x1000000U) != 0) {
          play_movie((char *)&InterfaceItem_800d0a6c);
          gameTrackerX.streamFlags = gameTrackerX.streamFlags & 0xfeffffff;
        }
        if ((gameTrackerX.streamFlags & 0x200000U) != 0) {
          gameTrackerX.streamFlags = gameTrackerX.streamFlags & 0xffdfffff;
        }
        if (nosound == 0) {
          MAIN_InitVolume();
        }
        MAIN_ShowLoadingScreen();
        FONT_ReloadFont();
        DrawSync(0);
        gameTrackerX.frameCount = 0;
        STREAM_Init();
        GAMELOOP_LevelLoadAndInit(gameTrackerX.baseAreaName,&gameTrackerX);
        gameTrackerX.levelDone = 0;
        mainTrackerX.mainState = 1;
        do {
          iVar4 = STREAM_PollLoadQueue();
        } while (iVar4 != 0);
        gameTrackerX.vblFrames = 0;
        break;
      case 4:
        LOAD_ChangeDirectory("Menustuff");
        do {
          lVar2 = mainTrackerX.movieNum;
          if (5 < (uint)mainTrackerX.movieNum) goto LAB_800396d0;
          gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xfffffffe;
          show_screen((char *)(&InterfaceItems + mainTrackerX.movieNum));
          iVar4 = 1;
          if ((&InterfaceItems)[lVar2].timeout != 0) {
            do {
              GAMEPAD_Process(&gameTrackerX);
              if (((int)(uint)(&InterfaceItems)[lVar2].buttonTimeout < iVar4) &&
                 ((gameTrackerX.controlCommand[0][1] & 0x80U) != 0)) break;
              VSync(0);
              bVar1 = iVar4 < (int)(uint)(&InterfaceItems)[lVar2].timeout;
              iVar4 = iVar4 + 1;
            } while (bVar1);
          }
          mainTrackerX.movieNum = (long)(&InterfaceItems)[lVar2].nextItem;
        } while ((mainTrackerX.movieNum < 0) ||
                ((&InterfaceItems)[mainTrackerX.movieNum].itemType == 1));
        mainTrackerX.mainState = 6;
LAB_800396d0:
        FONT_ReloadFont();
        if (mainTrackerX.mainState != 6) {
          if (DoMainMenu != 0) goto LAB_8003991c;
          MAIN_ResetGame();
          gameTrackerX.gameMode = 0;
          mainMenuFading = 1;
          MAIN_StartGame();
        }
        break;
      case 6:
        CINE_Load();
        do {
          if (mainTrackerX.movieNum < 0) goto LAB_800395b0;
          iVar4 = CINE_Loaded();
          if (iVar4 != 0) {
            CINE_Play((char *)(&InterfaceItems + mainTrackerX.movieNum),0xffff,2);
            ClearDisplay();
          }
          mainTrackerX.movieNum = (long)(&InterfaceItems)[mainTrackerX.movieNum].nextItem;
        } while ((&InterfaceItems)[mainTrackerX.movieNum].itemType == 0);
        mainTrackerX.mainState = 4;
LAB_800395b0:
        CINE_Unload();
        if (mainTrackerX.movieNum < 0) {
          mainTrackerX.mainState = 8;
        }
        if (nosound == 0) {
          SOUND_StopAllSound();
        }
        break;
      case 7:
        mainTrackerX.done = 1;
        break;
      case 8:
        gameTrackerX.gameData.asmData.MorphType = 0;
        ProcessArgs(gameTrackerX.baseAreaName,&gameTrackerX);
        MAIN_ResetGame();
        LOAD_ChangeDirectory("Menustuff");
        MAIN_MainMenuInit();
        MAIN_InitVolume();
        SAVE_ClearMemory(&gameTrackerX);
        mainTrackerX.mainState = 9;
        FONT_ReloadFont();
        break;
      case 9:
        menuPos = MAIN_DoMainMenu(&gameTrackerX,&mainTrackerX,menuPos);
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
    PadStopCom();
    ResetGraph(3);
  }
  MainG2_ShutDownEngine(appData);
  return 0;
}





