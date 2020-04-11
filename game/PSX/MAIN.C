#include "THISDUST.H"
#include "MAIN.H"


// decompiled code
// original method signature: 
// void /*$ra*/ ClearDisplay()
 // line 136, offset 0x8003840c
	/* begin block 1 */
		// Start line: 272
	/* end block 1 */
	// End Line: 273

	/* begin block 2 */
		// Start line: 274
	/* end block 2 */
	// End Line: 275

/* File: C:\kain2\game\PSX\MAIN.C */

void ClearDisplay(void)

{
  PutDrawEnv(draw + DAT_800d20d0);
  DrawPrim(clearRect + DAT_800d20d0);
  DrawSync(0);
  PutDispEnv(disp + DAT_800d20d0);
  SetDispMask(1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ show_screen(char *name /*$a0*/)
 // line 149, offset 0x80038498
	/* begin block 1 */
		// Start line: 150
		// Start offset: 0x80038498
		// Variables:
	// 		long *screen; // $s0
	/* end block 1 */
	// End offset: 0x800384DC
	// End Line: 156

	/* begin block 2 */
		// Start line: 300
	/* end block 2 */
	// End Line: 301

/* File: C:\kain2\game\PSX\MAIN.C */

void show_screen(char *name)

{
  long *addr;
  
  addr = LOAD_ReadFile(name,'\v');
  if (addr != (long *)0x0) {
    LOAD_LoadTIM2(addr,0,DAT_800d20d0 << 8,0x200,0x100);
    MEMPACK_Free((char *)addr);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ play_movie(char *name /*$s0*/)
 // line 188, offset 0x800384ec
	/* begin block 1 */
		// Start line: 379
	/* end block 1 */
	// End Line: 380

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
 // line 206, offset 0x80038534
	/* begin block 1 */
		// Start line: 415
	/* end block 1 */
	// End Line: 416

	/* begin block 2 */
		// Start line: 416
	/* end block 2 */
	// End Line: 417

/* File: C:\kain2\game\PSX\MAIN.C */

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
 // line 213, offset 0x80038544
	/* begin block 1 */
		// Start line: 215
		// Start offset: 0x80038544
		// Variables:
	// 		char *match_pos; // $a2
	/* end block 1 */
	// End offset: 0x800385BC
	// End Line: 229

	/* begin block 2 */
		// Start line: 429
	/* end block 2 */
	// End Line: 430

	/* begin block 3 */
		// Start line: 430
	/* end block 3 */
	// End Line: 431

	/* begin block 4 */
		// Start line: 432
	/* end block 4 */
	// End Line: 433

/* File: C:\kain2\game\PSX\MAIN.C */

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
 // line 231, offset 0x800385cc
	/* begin block 1 */
		// Start line: 465
	/* end block 1 */
	// End Line: 466

	/* begin block 2 */
		// Start line: 466
	/* end block 2 */
	// End Line: 467

/* File: C:\kain2\game\PSX\MAIN.C */

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
 // line 240, offset 0x80038618
	/* begin block 1 */
		// Start line: 483
	/* end block 1 */
	// End Line: 484

	/* begin block 2 */
		// Start line: 484
	/* end block 2 */
	// End Line: 485

/* File: C:\kain2\game\PSX\MAIN.C */

void ExtractLevelNum(char *levelNum,char *levelName)

{
  byte bVar1;
  
  bVar1 = *levelName;
  while (bVar1 != 0x2d) {
    if ((uint)bVar1 - 0x30 < 10) goto LAB_80038658;
    levelName = (char *)((byte *)levelName + 1);
    bVar1 = *levelName;
  }
  bVar1 = *levelName;
  while ((uint)bVar1 - 0x30 < 10) {
LAB_80038658:
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
 // line 338, offset 0x80038684
	/* begin block 1 */
		// Start line: 339
		// Start offset: 0x80038684
		// Variables:
	// 		char levelNum[32]; // stack offset -88
	// 		char worldName[32]; // stack offset -56
	// 		long *argData; // $s1
	/* end block 1 */
	// End offset: 0x800388A4
	// End Line: 565

	/* begin block 2 */
		// Start line: 632
	/* end block 2 */
	// End Line: 633

/* File: C:\kain2\game\PSX\MAIN.C */

void ProcessArgs(char *baseAreaName,GameTracker *gameTracker)

{
  char cVar1;
  char cVar2;
  long *levelName;
  char *pcVar3;
  char acStack88 [32];
  char acStack56 [32];
  
  levelName = LOAD_ReadFile(s__kain2_game_psx_kain2_arg_800cf8a0,'\n');
  cVar2 = DAT_800cf939;
  cVar1 = DAT_800cf938;
  if (levelName == (long *)0x0) {
    *(undefined4 *)baseAreaName = DAT_800cf934;
    baseAreaName[4] = cVar1;
    baseAreaName[5] = cVar2;
    baseAreaName[6] = DAT_800cf93a;
  }
  else {
    ExtractWorldName(acStack56,(char *)levelName);
    ExtractLevelNum(acStack88,(char *)levelName);
    sprintf(baseAreaName,&LAB_800cf8bc,acStack56,acStack88);
    pcVar3 = FindTextInLine(s__NOSOUND_800cf8c4,(char *)levelName);
    if (pcVar3 != (char *)0x0) {
      nosound = 1;
      nomusic = 1;
    }
    pcVar3 = FindTextInLine(s__NOMUSIC_800cf8d0,(char *)levelName);
    if (pcVar3 != (char *)0x0) {
      nomusic = 1;
    }
    pcVar3 = FindTextInLine(s__TIMEOUT_800cf8dc,(char *)levelName);
    if (pcVar3 != (char *)0x0) {
      gameTracker->debugFlags = gameTracker->debugFlags | 0x20000;
    }
    pcVar3 = FindTextInLine(s__DEMO_800cf8e8,(char *)levelName);
    if (pcVar3 != (char *)0x0) {
      DAT_800d22d1 = 1;
    }
    pcVar3 = FindTextInLine(s__MAINMENU_800cf8f0,(char *)levelName);
    if (pcVar3 != (char *)0x0) {
      DoMainMenu = 1;
    }
    pcVar3 = FindTextInLine(s__INSPECTRAL_800cf8fc,(char *)levelName);
    if (pcVar3 != (char *)0x0) {
      DAT_800d20d6 = 1;
    }
    pcVar3 = FindTextInLine(s__VOICE_800cf908,(char *)levelName);
    if (pcVar3 != (char *)0x0) {
      gameTracker->debugFlags = gameTracker->debugFlags | 0x80000;
    }
    pcVar3 = FindTextInLine(s__DEBUG_CD_800cf910,(char *)levelName);
    if (pcVar3 != (char *)0x0) {
      gameTracker->debugFlags = gameTracker->debugFlags | 0x80000000;
    }
    pcVar3 = FindTextInLine(s__LOADGAME_800cf91c,(char *)levelName);
    if (pcVar3 != (char *)0x0) {
      DAT_800d2210 = DAT_800d2210 | 0x200000;
    }
    pcVar3 = FindTextInLine(s__ALLWARP_800cf928,(char *)levelName);
    if (pcVar3 != (char *)0x0) {
      DAT_800d2210 = DAT_800d2210 | 0x400000;
    }
    gameTracker->demoEnabled = '\x01';
    gameTracker->debugFlags = gameTracker->debugFlags | 0x80000;
    MEMPACK_Free((char *)levelName);
  }
  DAT_800d218c = DAT_800d218c | 0x40000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ InitDisplay()
 // line 569, offset 0x800388d0
	/* begin block 1 */
		// Start line: 570
		// Start offset: 0x800388D0
		// Variables:
	// 		int i; // $a1
	// 		struct RECT r; // stack offset -16
	/* end block 1 */
	// End offset: 0x80038A20
	// End Line: 627

	/* begin block 2 */
		// Start line: 1100
	/* end block 2 */
	// End Line: 1101

/* File: C:\kain2\game\PSX\MAIN.C */

void InitDisplay(void)

{
  BLK_FILL *pBVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = DAT_800cf93c;
  local_c = DAT_800cf940;
  ResetGraph(3);
  SetGraphDebug(0);
  SetDefDrawEnv(draw,0,0,0x200,0xf0);
  SetDefDispEnv(disp,0,0,0x200,0xf0);
  SetDefDrawEnv(draw + 1,0,0x100,0x200,0xf0);
  SetDefDispEnv(disp + 1,0,0x100,0x200,0xf0);
  iVar2 = 0;
  pBVar1 = clearRect;
  draw[1].dtd = '\x01';
  draw[0].dtd = '\x01';
  draw[1].dfe = '\x01';
  draw[0].dfe = '\x01';
  draw[1].isbg = '\0';
  draw[0].isbg = '\0';
  draw[0].r0 = '\0';
  draw[0].g0 = '\0';
  draw[0].b0 = '\0';
  draw[1].r0 = '\0';
  draw[1].g0 = '\0';
  draw[1].b0 = '\0';
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
  ClearOTagR(DAT_800d22a4,0xc00);
  ClearOTagR(DAT_800d22a8,0xc00);
  ClearImage((RECT *)&local_10,'\0',-1,'\0');
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StartTimer()
 // line 638, offset 0x80038a64
	/* begin block 1 */
		// Start line: 1274
	/* end block 1 */
	// End Line: 1275

/* File: C:\kain2\game\PSX\MAIN.C */

void StartTimer(void)

{
  EnterCriticalSection();
  __timerEvent = OpenEvent(0xf2000000,2,0x1000,TimerTick);
  EnableEvent(__timerEvent);
  SetRCnt(0xf2000000,0xffff,(long)&DAT_00001001);
  StartRCnt(0xf2000000);
  ExitCriticalSection();
  gTimerEnabled = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VblTick()
 // line 712, offset 0x80038ad0
	/* begin block 1 */
		// Start line: 1423
	/* end block 1 */
	// End Line: 1424

	/* begin block 2 */
		// Start line: 1425
	/* end block 2 */
	// End Line: 1426

/* File: C:\kain2\game\PSX\MAIN.C */

void VblTick(void)

{
  if (devstation != 0) {
    trap(0x400);
  }
  DAT_800d2200 = DAT_800d2200 + 1;
  DAT_800d2204 = DAT_800d2204 + 1;
  if ((DAT_800d21e4 != (DISPENV *)0x0) && (DAT_800d233c < DAT_800d2200)) {
    PutDispEnv(DAT_800d21e4);
    DAT_800d21e4 = (DISPENV *)0x0;
    DAT_800d2200 = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DrawCallback()
 // line 730, offset 0x80038b3c
	/* begin block 1 */
		// Start line: 1465
	/* end block 1 */
	// End Line: 1466

	/* begin block 2 */
		// Start line: 1466
	/* end block 2 */
	// End Line: 1467

/* File: C:\kain2\game\PSX\MAIN.C */

void DrawCallback(void)

{
  ulong uVar1;
  
  if (DAT_800d21e8 != (ulong *)0x0) {
    uVar1 = TIMER_TimeDiff(DAT_800d21ec);
    *DAT_800d21e8 = uVar1;
    DAT_800d21e8 = (ulong *)0x0;
    DAT_800d21e4 = DAT_800d21f0 + DAT_800d20d0 * 0x14;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FadeOutSayingLoading(struct GameTracker *gameTracker /*$s1*/)
 // line 780, offset 0x80038b94
	/* begin block 1 */
		// Start line: 781
		// Start offset: 0x80038B94
		// Variables:
	// 		struct POLY_F4_SEMITRANS *transPrim; // $s2
	// 		unsigned long **drawot; // $s3
	// 		long fadeTime; // $s0
	/* end block 1 */
	// End offset: 0x80038CC8
	// End Line: 814

	/* begin block 2 */
		// Start line: 1556
	/* end block 2 */
	// End Line: 1557

/* File: C:\kain2\game\PSX\MAIN.C */

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
    PutDrawEnv(draw + gameTracker->drawPage);
    do {
      iVar2 = CheckVolatile(gameTracker->reqDisp);
    } while (iVar2 != 0);
    iVar2 = (gameTracker->gameData).asmData.dispPage;
    *(ulong **)&gameTracker->drawTimerReturn = &gameTracker->drawTime;
    (gameTracker->gameData).asmData.dispPage = 1 - iVar2;
    VSync(0);
    DrawOTag((u_long *)(ot + 0xbff));
    bVar1 = iVar4 != 0xff;
    iVar4 = iVar4 + 0x10;
  } while (bVar1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CheckForDevStation()
 // line 816, offset 0x80038ce8
	/* begin block 1 */
		// Start line: 817
		// Start offset: 0x80038CE8
		// Variables:
	// 		long *a1; // stack offset -8
	// 		long *a2; // stack offset -4
	/* end block 1 */
	// End offset: 0x80038D40
	// End Line: 843

	/* begin block 2 */
		// Start line: 1618
	/* end block 2 */
	// End Line: 1619

/* WARNING: Removing unreachable block (ram,0x80038d30) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* File: C:\kain2\game\PSX\MAIN.C */

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
 // line 845, offset 0x80038d48
	/* begin block 1 */
		// Start line: 846
		// Start offset: 0x80038D48
		// Variables:
	// 		long *loadingScreen; // $s0
	// 		char langChar[5]; // stack offset -88
	// 		int lang; // $v0

		/* begin block 1.1 */
			// Start line: 854
			// Start offset: 0x80038D90
			// Variables:
		// 		char filename[64]; // stack offset -80
		/* end block 1.1 */
		// End offset: 0x80038D90
		// End Line: 855
	/* end block 1 */
	// End offset: 0x80038DF4
	// End Line: 872

	/* begin block 2 */
		// Start line: 1677
	/* end block 2 */
	// End Line: 1678

/* File: C:\kain2\game\PSX\MAIN.C */

void MAIN_ShowLoadingScreen(void)

{
  language_t lVar1;
  long *addr;
  char *buffer;
  byte bStack89;
  undefined4 local_58;
  undefined local_54;
  char acStack80 [64];
  
  local_58 = DAT_800cf944;
  local_54 = DAT_800cf948;
  VSync(0);
  lVar1 = localstr_get_language();
  if (lVar1 == language_english) {
    buffer = s__kain2_game_psx_loading_tim_800cf96c;
  }
  else {
    buffer = acStack80;
    sprintf(buffer,s__kain2_game_psx_loading_c_tim_800cf94c,(uint)(&bStack89)[lVar1]);
  }
  addr = LOAD_ReadFile(buffer,'\v');
  if (addr != (long *)0x0) {
    LOAD_LoadTIM2(addr,0,DAT_800d20d0 << 8,0x200,0x100);
    MEMPACK_Free((char *)addr);
  }
  return;
}



// decompiled code
// original method signature: 
// long * /*$ra*/ MAIN_LoadTim(char *name /*$a0*/)
 // line 874, offset 0x80038e08
	/* begin block 1 */
		// Start line: 875
		// Start offset: 0x80038E08
	/* end block 1 */
	// End offset: 0x80038E08
	// End Line: 875

	/* begin block 2 */
		// Start line: 1741
	/* end block 2 */
	// End Line: 1742

/* File: C:\kain2\game\PSX\MAIN.C */

long * MAIN_LoadTim(char *name)

{
  long *plVar1;
  
  plVar1 = LOAD_ReadFile(name,'\v');
  return plVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ init_menus(struct GameTracker *gt /*$s1*/)
 // line 885, offset 0x80038e28
	/* begin block 1 */
		// Start line: 886
		// Start offset: 0x80038E28
		// Variables:
	// 		struct menu_t *menu; // $s0
	/* end block 1 */
	// End offset: 0x80038E28
	// End Line: 886

	/* begin block 2 */
		// Start line: 1763
	/* end block 2 */
	// End Line: 1764

/* File: C:\kain2\game\PSX\MAIN.C */

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
 // line 897, offset 0x80038e74
	/* begin block 1 */
		// Start line: 1787
	/* end block 1 */
	// End Line: 1788

/* File: C:\kain2\game\PSX\MAIN.C */

void MAIN_DoMainInit(void)

{
  InitDisplay();
  InitGeom();
  SetGeomOffset(0x100,0x78);
  SetGeomScreen(0x140);
  VRAM_InitVramBlockCache();
  FONT_Init();
  DAT_800d21e4 = 0;
  VSyncCallback(VblTick);
  DrawSyncCallback(DrawCallback);
  GAMEPAD_Init();
  SOUND_Init();
  VOICEXA_Init();
  if (nosound != 0) {
    SOUND_SfxOff();
    DAT_800d2290 = 0;
    DAT_800d2292 = 0;
  }
  if (nomusic != 0) {
    SOUND_MusicOff();
    DAT_800d2291 = 0;
  }
  if ((DAT_800d218c & 0x80000) == 0) {
    DAT_800d2292 = 0;
  }
  init_menus((GameTracker *)&gameTrackerX);
  SAVE_Init((GameTracker *)&gameTrackerX);
  srand(0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MAIN_ShowPalWarningScreen(struct GameTracker *gameTracker /*$s1*/)
 // line 932, offset 0x80038f70
	/* begin block 1 */
		// Start line: 933
		// Start offset: 0x80038F70
		// Variables:
	// 		long *warningScreen; // $s0
	/* end block 1 */
	// End offset: 0x80038FC0
	// End Line: 942

	/* begin block 2 */
		// Start line: 1858
	/* end block 2 */
	// End Line: 1859

/* File: C:\kain2\game\PSX\MAIN.C */

void MAIN_ShowPalWarningScreen(GameTracker *gameTracker)

{
  long *addr;
  
  addr = LOAD_ReadFile(s__kain2_game_psx_warning_tim_800cf988,'\v');
  if (addr != (long *)0x0) {
    LOAD_LoadTIM(addr,0,(gameTracker->gameData).asmData.dispPage << 8,0,0);
    MEMPACK_Free((char *)addr);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MAIN_InitVolume()
 // line 956, offset 0x80038fd4
	/* begin block 1 */
		// Start line: 1909
	/* end block 1 */
	// End Line: 1910

/* File: C:\kain2\game\PSX\MAIN.C */

void MAIN_InitVolume(void)

{
  aadInitVolume();
  aadStartMasterVolumeFade
            (DAT_800d2280,0x100,(TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback)0x0);
  DAT_800d2293 = 1;
  aadSetNoUpdateMode(0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MAIN_ResetGame()
 // line 964, offset 0x80039014
	/* begin block 1 */
		// Start line: 1910
	/* end block 1 */
	// End Line: 1911

/* File: C:\kain2\game\PSX\MAIN.C */

void MAIN_ResetGame(void)

{
  GAMELOOP_SetScreenWipe(0,0,-1);
  DAT_800d220c = DAT_800d220c & 0xffffff6e;
  RAZIEL_StartNewGame();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MAIN_MainMenuInit()
 // line 974, offset 0x80039064
	/* begin block 1 */
		// Start line: 975
		// Start offset: 0x80039064

		/* begin block 1.1 */
			// Start line: 975
			// Start offset: 0x80039064
			// Variables:
		// 		char sfxFileName[64]; // stack offset -72
		/* end block 1.1 */
		// End offset: 0x80039188
		// End Line: 995
	/* end block 1 */
	// End offset: 0x80039188
	// End Line: 997

	/* begin block 2 */
		// Start line: 1931
	/* end block 2 */
	// End Line: 1932

/* WARNING: Removing unreachable block (ram,0x80039088) */
/* WARNING: Removing unreachable block (ram,0x8003908c) */
/* WARNING: Removing unreachable block (ram,0x800390d8) */
/* File: C:\kain2\game\PSX\MAIN.C */

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
  undefined4 local_48 [16];
  
  mainMenuMode = 0;
  mainMenuTimeOut = 0;
  puVar1 = &DAT_800cf9c0;
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
  } while (puVar5 + 4 != (undefined4 *)(s_ainmenu_snf_800cf9dc + 4));
  uVar7 = puVar5[5];
  puVar6[4] = s_ainmenu_snf_800cf9dc._4_4_;
  puVar6[5] = uVar7;
  memset();
  mainMenuSfx = 0;
  lVar3 = LOAD_DoesFileExist((char *)local_48);
  if (lVar3 != 0) {
    mainMenuSfx = aadLoadDynamicSfx(s_mainmenu_800cf9e8,0,0);
    while (iVar4 = aadGetNumLoadsQueued(), iVar4 != 0) {
      aadProcessLoadQueue();
    }
  }
  mainMenuScreen = MAIN_LoadTim(s__kain2_game_psx_frontend_title1__800cf9f4);
  VRAM_EnableTerrainArea();
  menuface_initialize();
  currentMenu = mainMenu;
  DAT_800d223e = 4;
  menu_set(DAT_800d20ec,menudefs_main_menu);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MAIN_FreeMainMenuStuff()
 // line 1011, offset 0x800391dc
	/* begin block 1 */
		// Start line: 2020
	/* end block 1 */
	// End Line: 2021

/* File: C:\kain2\game\PSX\MAIN.C */

void MAIN_FreeMainMenuStuff(void)

{
  int iVar1;
  
  menuface_terminate();
  VRAM_DisableTerrainArea();
  if (mainMenuScreen != (char *)0x0) {
    MEMPACK_Free(mainMenuScreen);
    mainMenuScreen = (char *)0x0;
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
 // line 1046, offset 0x8003924c
	/* begin block 1 */
		// Start line: 2090
	/* end block 1 */
	// End Line: 2091

	/* begin block 2 */
		// Start line: 2091
	/* end block 2 */
	// End Line: 2092

/* File: C:\kain2\game\PSX\MAIN.C */

void MAIN_StartGame(void)

{
  if (mainMenuFading == 0) {
    DAT_800d223e = 0;
    currentMenu = (DebugMenuLine *)0x0;
    mainMenuFading = 1;
    GAMELOOP_SetScreenWipe(-0x1e,0x1e,10);
  }
  else {
    mainTrackerX.mainState = 2;
    MAIN_FreeMainMenuStuff();
    gEndGameNow = 0;
    mainMenuFading = 0;
    currentMenu = standardMenu;
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MAIN_DoMainMenu(struct GameTracker *gameTracker /*$s0*/, struct MainTracker *mainTracker /*$a1*/, long menuPos /*$a2*/)
 // line 1076, offset 0x800392b8
	/* begin block 1 */
		// Start line: 1077
		// Start offset: 0x800392B8
		// Variables:
	// 		unsigned long **drawot; // $s1
	/* end block 1 */
	// End offset: 0x8003937C
	// End Line: 1161

	/* begin block 2 */
		// Start line: 2156
	/* end block 2 */
	// End Line: 2157

/* File: C:\kain2\game\PSX\MAIN.C */

long MAIN_DoMainMenu(GameTracker *gameTracker,MainTracker *mainTracker,long menuPos)

{
  ulong **drawot;
  
  drawot = gameTracker->drawOT;
  DrawPrim(clearRect + gameTracker->drawPage);
  GAMEPAD_Process(gameTracker);
  DEBUG_Process(gameTracker);
  if (mainMenuScreen != (long *)0x0) {
    LOAD_LoadTIM2(mainMenuScreen,0,gameTracker->drawPage << 8,0x200,0x100);
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
 // line 1178, offset 0x80039394
	/* begin block 1 */
		// Start line: 1179
		// Start offset: 0x80039394
		// Variables:
	// 		struct MainTracker *mainTracker; // $s2
	// 		struct GameTracker *gameTracker; // $s3
	// 		long menuPos; // $s6
		// Labels:
		//		0x0000175C	exit

		/* begin block 1.1 */
			// Start line: 1365
			// Start offset: 0x800395D8
			// Variables:
		// 		struct InterfaceItem *item; // $s1
		// 		int timer; // $s0
		/* end block 1.1 */
		// End offset: 0x80039660
		// End Line: 1411
	/* end block 1 */
	// End offset: 0x80039990
	// End Line: 1697

	/* begin block 2 */
		// Start line: 2346
	/* end block 2 */
	// End Line: 2347

/* File: C:\kain2\game\PSX\MAIN.C */

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
    STREAM_InitLoader(s__BIGFILE_DAT_1_800cfa40,&LAB_800cfa50);
    localstr_set_language(~language_english);
    GAMELOOP_SystemInit((GameTracker *)&gameTrackerX);
    DAT_800d2299 = 0xff;
    DAT_800d2298 = 0xff;
    DAT_800d21f0 = disp;
    ProcessArgs(&DAT_800d2228,(GameTracker *)&gameTrackerX);
    InitMainTracker((MainTracker *)&mainTrackerX);
    MAIN_DoMainInit();
    mainTrackerX.mainState = 6;
    mainTrackerX.movieNum = 0;
    do {
      mainTrackerX.previousState = mainTrackerX.mainState;
      switch(mainTrackerX.mainState) {
      case 1:
        SOUND_UpdateSound();
        if ((DAT_800d218c & 0x80000) != 0) {
          VOICEXA_Tick();
        }
        PSX_GameLoop((GameTracker *)&gameTrackerX);
        if (DAT_800d2238 != 0) {
          FadeOutSayingLoading((GameTracker *)&gameTrackerX);
          SOUND_StopAllSound();
          SOUND_FreeDynamicMusic();
          STREAM_DumpAllLevels(0,0);
          RemoveAllObjects((GameTracker *)&gameTrackerX);
          while (iVar4 = aadGetNumLoadsQueued(), iVar4 != 0) {
            aadProcessLoadQueue();
          }
          MEMPACK_FreeByType('\x0e');
          GAMELOOP_ResetGameStates();
          MEMPACK_DoGarbageCollection();
          iVar4 = (int)DAT_800d2238;
          if (iVar4 == 2) {
LAB_80039890:
            mainTrackerX.mainState = 8;
          }
          else {
            if (iVar4 == 3) {
              mainTrackerX.mainState = 6;
              mainTrackerX.movieNum = iVar4;
            }
            else {
              if (iVar4 != 4) goto LAB_80039688;
              mainTrackerX.mainState = 2;
              if ((DAT_800d2210 & 0x200000) == 0) {
                SAVE_ClearMemory((GameTracker *)&gameTrackerX);
              }
            }
          }
        }
        break;
      case 2:
      case 0xb:
        if ((DAT_800d2210 & 0x1000000) != 0) {
          play_movie((char *)(InterfaceItems + 2));
          DAT_800d2210 = DAT_800d2210 & 0xfeffffff;
        }
        if ((DAT_800d2210 & 0x200000) != 0) {
          DAT_800d2210 = DAT_800d2210 & 0xffdfffff;
        }
        if (nosound == 0) {
          MAIN_InitVolume();
        }
        MAIN_ShowLoadingScreen();
        FONT_ReloadFont();
        DrawSync(0);
        DAT_800d21f8 = 0;
        STREAM_Init();
        GAMEPAD_LoadDemo();
        GAMELOOP_LevelLoadAndInit(&DAT_800d2228,(GameTracker *)&gameTrackerX);
        DAT_800d2238 = 0;
        mainTrackerX.mainState = 1;
        do {
          iVar4 = STREAM_PollLoadQueue();
        } while (iVar4 != 0);
        DAT_800d2200 = 0;
        break;
      case 3:
        DrawSync(0);
        MAIN_ShowPalWarningScreen((GameTracker *)&gameTrackerX);
        DAT_800d2204 = 0;
        mainTrackerX.mainState = 5;
        break;
      case 4:
        LOAD_ChangeDirectory(s_Menustuff_800cfa54);
        lVar2 = mainTrackerX.movieNum;
        show_screen((char *)(InterfaceItems + mainTrackerX.movieNum));
        iVar4 = 1;
        if (InterfaceItems[lVar2].timeout != 0) {
          do {
            GAMEPAD_Process((GameTracker *)&gameTrackerX);
            if (((int)(uint)InterfaceItems[lVar2].buttonTimeout < iVar4) &&
               ((DAT_800d2118 & 0x80) != 0)) break;
            VSync(0);
            bVar1 = iVar4 < (int)(uint)InterfaceItems[lVar2].timeout;
            iVar4 = iVar4 + 1;
          } while (bVar1);
        }
        FONT_ReloadFont();
        if (DoMainMenu == 0) {
          MAIN_ResetGame();
          mainTrackerX.mainState = 2;
        }
        else {
          if (DAT_800d22d1 == '\0') goto LAB_80039890;
LAB_80039688:
          mainTrackerX.mainState = 2;
        }
        break;
      case 5:
        if (0x1e < DAT_800d2204) {
          mainTrackerX.mainState = 6;
          mainTrackerX.movieNum = 0;
        }
        break;
      case 6:
        CINE_Load();
        do {
          if (mainTrackerX.movieNum < 0) goto LAB_8003959c;
          iVar4 = CINE_Loaded();
          if (iVar4 != 0) {
            CINE_Play((char *)(InterfaceItems + mainTrackerX.movieNum),0xffff,2);
            ClearDisplay();
          }
          mainTrackerX.movieNum = (long)InterfaceItems[mainTrackerX.movieNum].nextItem;
        } while (InterfaceItems[mainTrackerX.movieNum].itemType == 0);
        mainTrackerX.mainState = 4;
LAB_8003959c:
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
        DAT_800d20d6 = 0;
        ProcessArgs(&DAT_800d2228,(GameTracker *)&gameTrackerX);
        MAIN_ResetGame();
        LOAD_ChangeDirectory(s_Menustuff_800cfa54);
        MAIN_MainMenuInit();
        MAIN_InitVolume();
        SAVE_ClearMemory((GameTracker *)&gameTrackerX);
        mainTrackerX.mainState = 9;
        FONT_ReloadFont();
        break;
      case 9:
        menuPos = MAIN_DoMainMenu((GameTracker *)&gameTrackerX,(MainTracker *)&mainTrackerX,menuPos)
        ;
      }
      STREAM_PollLoadQueue();
    } while (mainTrackerX.done == 0);
    SOUND_StopAllSound();
    SOUND_Free();
    SetDispMask(0);
    DrawSync(0);
    VSync(0);
    DrawSyncCallback((func *)0x0);
    VSyncCallback((f *)0x0);
    EnterCriticalSection();
    StopRCnt(0xf2000000);
    DisableEvent(__timerEvent);
    CloseEvent(__timerEvent);
    ExitCriticalSection();
    VSync(5);
    StopCallback();
    StopPAD();
    ResetGraph(3);
  }
  MainG2_ShutDownEngine(appData);
  return 0;
}





