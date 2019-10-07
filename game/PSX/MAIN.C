#include "THISDUST.H"
#include "MAIN.H"
#include "TYPES.H"
#include "STRMLOAD.H"
#include "LOAD3D.H"
#include "MEMPACK.H"
#include "CINEPSX.H"
#include "SUPPORT.H"
#include "TIMER.H"
#include "DRAW.H"
#include "FONT.H"
#include "DRAWS.H"
#include "LOCALSTR.H"
#include "MENU.H"
#include "VRAM.H"
#include "GAMEPAD.H"
#include "SOUND.H"
#include "VOICEXA.H"
#include "SAVEINFO.H"
#include "AADLIB.H"
#include "GAMELOOP.H"
#include "RAZLIB.H"
#include "MENUFACE.H"
#include "STREAM.H"
#include "DEBUG.H"
#include "MAING2.H"

#include "LIBETC.H"
#include "LIBGPU.H"
#include "LIBAPI.H"
#include "LIBGPU.H"
#include "STDDEF.H"

typedef enum
{
    FALSE,
    TRUE
} bool;

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

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ClearDisplay(void)

{
/*   PutDrawEnv((u_char *)(&draw + gameTrackerX.gameData.asmData.dispPage));
  //DrawPrim((int)(&clearRect + gameTrackerX.gameData.asmData.dispPage));
  DrawSync(0);
  PutDispEnv((ushort *)(&disp + gameTrackerX.gameData.asmData.dispPage));
  SetDispMask(1); */
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

void ExtractWorldName(char *worldName,char *levelName)

{
  byte bVar1;
  
  bVar1 = *levelName;
  while ((bVar1 != 0x2d && (((u_int)bVar1 - 0x41 < 0x1a || ((u_int)bVar1 - 0x61 < 0x1a))))) {
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

void ExtractLevelNum(char *levelNum,char *levelName)

{
  byte bVar1;
  
  bVar1 = *levelName;
  while (bVar1 != 0x2d) {
    if ((u_int)bVar1 - 0x30 < 10) goto LAB_80038658;
    levelName = (char *)((byte *)levelName + 1);
    bVar1 = *levelName;
  }
  bVar1 = *levelName;
  while ((u_int)bVar1 - 0x30 < 10) {
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

void ProcessArgs(char *baseAreaName,GameTracker *gameTracker)

{
  long *levelName;
  char *pcVar1;
  char acStack88 [32];
  char acStack56 [32];
  
  levelName = LOAD_ReadFile("\\kain2\\game\\psx\\kain2.arg",'\n');
  if (levelName == (long *)0x0) {
    *(u_char *)baseAreaName = 0x65646e75;
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
    pcVar1 = FindTextInLine("-DEMO",(char *)levelName);
    if (pcVar1 != (char *)0x0) {
      gameTrackerX.setDemoMode = '\x01';
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
    gameTracker->demoEnabled = '\x01';
    gameTracker->debugFlags = gameTracker->debugFlags | 0x80000;
    MEMPACK_Free((char *)levelName);
  }
  gameTrackerX.debugFlags = gameTrackerX.debugFlags | 0x40000;
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

/* WARNING: Unknown calling convention yet parameter storage is locked */

void InitDisplay(void)

{
/*   BLK_FILL *pBVar1;
  int iVar2;
  u_char local_10;
  u_char local_c;
  
  local_10 = 0x200;
  local_c = 0x2000200;
  ResetGraph(3);
  SetGraphDebug('\0');
  SetDefDrawEnv((undefined2 *)&draw,0,0,0x200,0xf0);
  SetDefDispEnv((undefined2 *)&disp,0,0,0x200,0xf0);
  SetDefDrawEnv((undefined2 *)&DRAWENV_800d1fe8,0,0x100,0x200,0xf0);
  SetDefDispEnv((undefined2 *)&DISPENV_800d1f74,0,0x100,0x200,0xf0);
  iVar2 = 0;
  pBVar1 = &clearRect;
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
  ClearImage(&local_10,0,0xff,0); */
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

/* WARNING: Unknown calling convention yet parameter storage is locked */

void StartTimer(void)

{
  EnterCriticalSection();
  //__timerEvent = OpenEvent();
  //EnableEvent();
  //SetRCnt(0xf2000000,0xffff,(u_int)&DAT_00001001);
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

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VblTick(void)

{
  if (devstation != 0) {
    //trap(0x400);
  }
  gameTrackerX.vblFrames = gameTrackerX.vblFrames + 1;
  gameTrackerX.vblCount = gameTrackerX.vblCount + 1;
  if ((gameTrackerX.reqDisp != (void *)0x0) &&
     ((u_int)gameTrackerX.frameRateLock < gameTrackerX.vblFrames)) {
    PutDispEnv((ushort *)gameTrackerX.reqDisp);
    gameTrackerX.reqDisp = (void *)0x0;
    gameTrackerX.vblFrames = 0;
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

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DrawCallback(void)

{
  u_long uVar1;
  
  if (gameTrackerX.drawTimerReturn != (long *)0x0) {
    uVar1 = TIMER_TimeDiff(gameTrackerX.usecsStartDraw);
    *gameTrackerX.drawTimerReturn = uVar1;
    gameTrackerX.drawTimerReturn = (long *)0x0;
    gameTrackerX.reqDisp =(void *)(gameTrackerX.disp + gameTrackerX.gameData.asmData.dispPage * 0x14);
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

void FadeOutSayingLoading(GameTracker *gameTracker)

{
  bool bVar1;
  int iVar2;
  //undefined uVar3;
  int iVar4;
  u_long *puVar5;
  u_long **ot;
  
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
/*     uVar3 = (undefined)iVar4;
    *(undefined *)(puVar5 + 2) = uVar3;
    *(undefined *)((int)puVar5 + 9) = uVar3;
    *(undefined *)((int)puVar5 + 10) = uVar3; */
    do {
      //iVar2 = CheckVolatile(gameTracker->drawTimerReturn);
    } while (iVar2 != 0);
    //PutDrawEnv((u_char *)(&draw + gameTracker->drawPage));
    do {
      //iVar2 = CheckVolatile(gameTracker->reqDisp);
    } while (iVar2 != 0);
    iVar2 = (gameTracker->gameData).asmData.dispPage;
    *(u_long **)&gameTracker->drawTimerReturn = &gameTracker->drawTime;
    (gameTracker->gameData).asmData.dispPage = 1 - iVar2;
    VSync(0);
    //DrawOTag(ot + 0xbff);
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
/* WARNING: Unknown calling convention yet parameter storage is locked */

void CheckForDevStation(void)

{
  devstation = 1;
/*   DAT_80180000 = 0;
  _DAT_80380000 = 0x12345678; */
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

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_ShowLoadingScreen(void)

{
  language_t lVar1;
  long *addr;
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
  addr = LOAD_ReadFile(string,'\v');
  if (addr != (long *)0x0) {
    LOAD_LoadTIM2(addr,0,gameTrackerX.gameData.asmData.dispPage << 8,0x200,0x100);
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

void init_menus(GameTracker *gt)

{
  u_long allocSize;
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
/*   VSyncCallback(VblTick);
  DrawSyncCallback(DrawCallback); */
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
// void /*$ra*/ MAIN_InitVolume()
 // line 956, offset 0x80038fd4
	/* begin block 1 */
		// Start line: 1909
	/* end block 1 */
	// End Line: 1910

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_InitVolume(void)

{
  aadInitVolume();
  //aadStartMasterVolumeFade(gameTrackerX.sound.gMasterVol,0x100,(TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback)0x0);
  gameTrackerX.sound.soundsLoaded = '\x01';
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
/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_MainMenuInit(void)

{
  u_char *puVar1;
  u_char *puVar2;
  long lVar3;
  int iVar4;
  u_char *puVar5;
  u_char *puVar6;
  u_char uVar7;
  u_char uVar8;
  u_char uVar9;
  u_char local_48 [10];
  //undefined auStack32 [24];
  
  mainMenuMode = 0;
  mainMenuTimeOut = 0;
  //puVar1 = DAT_800cf9c0;
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
  } while (puVar5 + 4 != (u_char *)0x800cf9e0);
  uVar7 = puVar5[5];
  puVar6[4] = 0x2e756e65;
  puVar6[5] = uVar7;
  //memset(auStack32,0,0x18);
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
  currentMenu = mainMenu;
  gameTrackerX.gameMode = 4;
  //menu_set(gameTrackerX.menu,menudefs_main_menu);
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
 // line 1046, offset 0x8003924c
	/* begin block 1 */
		// Start line: 2090
	/* end block 1 */
	// End Line: 2091

	/* begin block 2 */
		// Start line: 2091
	/* end block 2 */
	// End Line: 2092

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

long MAIN_DoMainMenu(GameTracker *gameTracker,MainTracker *mainTracker,long menuPos)

{
  u_long **drawot;
  
  drawot = gameTracker->drawOT;
  //DrawPrim((int)(clearRect + gameTracker->drawPage));
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

int MainG2(void *appData)

{
  bool bVar1;
  long lVar2;
  bool _Var3;
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
    localstr_set_language(language_english);
    GAMELOOP_SystemInit(&gameTrackerX);
    gameTrackerX.lastLvl = -1;
    gameTrackerX.currentLvl = -1;
    //gameTrackerX.disp = &disp;
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
          SOUND_StopAllSound();
          SOUND_FreeDynamicMusic();
          STREAM_DumpAllLevels(0,0);
          RemoveAllObjects(&gameTrackerX);
          while (iVar4 = aadGetNumLoadsQueued(), iVar4 != 0) {
            aadProcessLoadQueue();
          }
          MEMPACK_FreeByType('\x0e');
          GAMELOOP_ResetGameStates();
          MEMPACK_DoGarbageCollection();
          iVar4 = (int)gameTrackerX.levelDone;
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
              if ((gameTrackerX.streamFlags & 0x200000U) == 0) {
                SAVE_ClearMemory(&gameTrackerX);
              }
            }
          }
        }
        break;
      case 2:
      case 0xb:
        if ((gameTrackerX.streamFlags & 0x1000000U) != 0) {
          play_movie((char *)"\\KAININT.STR;1");
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
        GAMEPAD_LoadDemo();
        GAMELOOP_LevelLoadAndInit(gameTrackerX.baseAreaName,&gameTrackerX);
        gameTrackerX.levelDone = 0;
        mainTrackerX.mainState = 1;
        do {
          iVar4 = STREAM_PollLoadQueue();
        } while (iVar4 != 0);
        gameTrackerX.vblFrames = 0;
        break;
      case 3:
        DrawSync(0);
        MAIN_ShowPalWarningScreen(&gameTrackerX);
        gameTrackerX.vblCount = 0;
        mainTrackerX.mainState = 5;
        break;
      case 4:
        LOAD_ChangeDirectory("Menustuff");
        lVar2 = mainTrackerX.movieNum;
        show_screen((char *)(&InterfaceItems + mainTrackerX.movieNum));
        iVar4 = 1;
        if ((InterfaceItems)[lVar2].timeout != 0) {
          do {
            GAMEPAD_Process(&gameTrackerX);
            if (((int)(u_int)(InterfaceItems)[lVar2].buttonTimeout < iVar4) &&
               ((gameTrackerX.controlCommand[0][1] & 0x80U) != 0)) break;
            VSync(0);
            bVar1 = iVar4 < (int)(u_int)(InterfaceItems)[lVar2].timeout;
            iVar4 = iVar4 + 1;
          } while (bVar1);
        }
        FONT_ReloadFont();
        if (DoMainMenu == 0) {
          MAIN_ResetGame();
          mainTrackerX.mainState = 2;
        }
        else {
          if (gameTrackerX.setDemoMode == '\0') goto LAB_80039890;
LAB_80039688:
          mainTrackerX.mainState = 2;
        }
        break;
      case 5:
        if (0x1e < gameTrackerX.vblCount) {
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
            CINE_Play((char *)(&InterfaceItems + mainTrackerX.movieNum),0xffff,2);
            ClearDisplay();
          }
          mainTrackerX.movieNum = (long)(InterfaceItems)[mainTrackerX.movieNum].nextItem;
        } while ((InterfaceItems)[mainTrackerX.movieNum].itemType == 0);
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
    //DisableEvent();
    //CloseEvent();
    ExitCriticalSection();
    VSync(5);
    StopCallback();
    StopPAD();
    ResetGraph(3);
  }
  MainG2_ShutDownEngine(appData);
  return 0;
}





