#include "THISDUST.H"
#include "MAIN.H"

// decompiled code
// original method signature:
// void /*$ra*/ ClearDisplay()
// line 136, offset 0x80037ef8
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
  PutDrawEnv((undefined4 *)(&draw + DAT_800d0fb0));
  clearRect[DAT_800d0fb0].r0 = '\0';
  clearRect[DAT_800d0fb0].g0 = '\0';
  clearRect[DAT_800d0fb0].b0 = '\0';
  DrawPrim((int)(clearRect + DAT_800d0fb0));
  DrawSync(0);
  PutDispEnv((ushort *)(&disp + DAT_800d0fb0));
  SetDispMask(1);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ screen_to_vram(long *screen /*$a0*/, int buffer /*$a1*/)
// line 150, offset 0x80037fb4
/* begin block 1 */
// Start line: 302
/* end block 1 */
// End Line: 303

void screen_to_vram(long *screen, int buffer)

{
  LOAD_LoadTIM2(screen, 0, buffer << 8, 0x200, 0x100);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ show_screen(char *name /*$a0*/)
// line 159, offset 0x80037fe4
/* begin block 1 */
// Start line: 160
// Start offset: 0x80037FE4
// Variables:
// 		long *screen; // $s0
/* end block 1 */
// End offset: 0x80038018
// End Line: 167

/* begin block 2 */
// Start line: 324
/* end block 2 */
// End Line: 325

void show_screen(char *name)

{
  long *screen;

  screen = LOAD_ReadFile(name, '\v');
  if (screen != (long *)0x0)
  {
    screen_to_vram(screen, DAT_800d0fb0);
    /* WARNING: Subroutine does not return */
    MEMPACK_Free((char *)screen);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ play_movie(char *name /*$s0*/)
// line 214, offset 0x80038028
/* begin block 1 */
// Start line: 435
/* end block 1 */
// End Line: 436

void play_movie(char *name)

{
  int iVar1;

  iVar1 = CINE_Load();
  if (iVar1 != 0)
  {
    CINE_Play(name, 0xffff, 2);
    ClearDisplay();
    CINE_Unload();
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ InitMainTracker(struct MainTracker *mainTracker /*$a0*/)
// line 236, offset 0x80038070
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
// line 243, offset 0x80038080
/* begin block 1 */
// Start line: 245
// Start offset: 0x80038080
// Variables:
// 		char *match_pos; // $a2
/* end block 1 */
// End offset: 0x800380F8
// End Line: 259

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

char *FindTextInLine(char *search_match, char *search_str)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;

  bVar1 = *search_str;
  if ((bVar1 != 0) && (pbVar2 = (byte *)search_match, bVar1 != 10))
  {
    while (bVar1 != 0xd)
    {
      search_str = (char *)((byte *)search_str + 1);
      pbVar3 = (byte *)search_match;
      if ((bVar1 | 0x20) == (*pbVar2 | 0x20))
      {
        pbVar3 = pbVar2 + 1;
      }
      if (*pbVar3 == 0)
      {
        return (char *)(byte *)search_str;
      }
      bVar1 = *search_str;
      if (bVar1 == 0)
      {
        return (char *)0x0;
      }
      pbVar2 = pbVar3;
      if (bVar1 == 10)
      {
        return (char *)0x0;
      }
    }
  }
  return (char *)0x0;
}

// decompiled code
// original method signature:
// void /*$ra*/ ExtractWorldName(char *worldName /*$a0*/, char *levelName /*$a1*/)
// line 261, offset 0x80038108
/* begin block 1 */
// Start line: 529
/* end block 1 */
// End Line: 530

/* begin block 2 */
// Start line: 530
/* end block 2 */
// End Line: 531

void ExtractWorldName(char *worldName, char *levelName)

{
  byte bVar1;

  bVar1 = *levelName;
  while ((bVar1 != 0x2d && (((uint)bVar1 - 0x41 < 0x1a || ((uint)bVar1 - 0x61 < 0x1a)))))
  {
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
// line 270, offset 0x80038154
/* begin block 1 */
// Start line: 547
/* end block 1 */
// End Line: 548

/* begin block 2 */
// Start line: 548
/* end block 2 */
// End Line: 549

void ExtractLevelNum(char *levelNum, char *levelName)

{
  byte bVar1;

  bVar1 = *levelName;
  while (bVar1 != 0x2d)
  {
    if ((uint)bVar1 - 0x30 < 10)
      goto LAB_80038194;
    levelName = (char *)((byte *)levelName + 1);
    bVar1 = *levelName;
  }
  bVar1 = *levelName;
  while ((uint)bVar1 - 0x30 < 10)
  {
  LAB_80038194:
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
// line 368, offset 0x800381c0
/* begin block 1 */
// Start line: 369
// Start offset: 0x800381C0
// Variables:
// 		char levelNum[32]; // stack offset -88
// 		char worldName[32]; // stack offset -56
// 		long *argData; // $s1
/* end block 1 */
// End offset: 0x800383BC
// End Line: 586

/* begin block 2 */
// Start line: 736
/* end block 2 */
// End Line: 737

void ProcessArgs(char *baseAreaName, GameTracker *gameTracker)

{
  char cVar1;
  char cVar2;
  long *levelName;
  char acStack88[32];
  char acStack56[32];

  levelName = LOAD_ReadFile(s__kain2_game_psx_kain2_arg_800ce6d4, '\n');
  cVar2 = s_under1_800ce760[5];
  cVar1 = s_under1_800ce760[4];
  if (levelName != (long *)0x0)
  {
    ExtractWorldName(acStack56, (char *)levelName);
    ExtractLevelNum(acStack88, (char *)levelName);
    /* WARNING: Subroutine does not return */
    sprintf(baseAreaName, &DAT_800ce6f0);
  }
  *(undefined4 *)baseAreaName = s_under1_800ce760._0_4_;
  baseAreaName[4] = cVar1;
  baseAreaName[5] = cVar2;
  baseAreaName[6] = s_under1_800ce760[6];
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ InitDisplay()
// line 588, offset 0x800383d8
/* begin block 1 */
// Start line: 589
// Start offset: 0x800383D8
// Variables:
// 		int i; // $a1
// 		struct RECT r; // stack offset -16
/* end block 1 */
// End offset: 0x80038510
// End Line: 650

/* begin block 2 */
// Start line: 1134
/* end block 2 */
// End Line: 1135

/* WARNING: Unknown calling convention yet parameter storage is locked */

void InitDisplay(void)

{
  BLK_FILL *pBVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;

  local_10 = DAT_800ce768;
  local_c = DAT_800ce76c;
  ResetGraph(3);
  SetGraphDebug(0);
  SetDefDrawEnv((undefined2 *)&draw, 0, 0, 0x200, 0xf0);
  SetDefDispEnv((undefined2 *)&disp, 0, 0, 0x200, 0xf0);
  SetDefDrawEnv((undefined2 *)&DAT_800d0ec8, 0, 0x100, 0x200, 0xf0);
  SetDefDispEnv((undefined2 *)&DISPENV_800d0e54, 0, 0x100, 0x200, 0xf0);
  iVar2 = 0;
  pBVar1 = clearRect;
  DAT_800d0ede = 1;
  /* WARNING: Read-only address (ram,0x800d0e82) is written */
  draw.dtd = '\x01';
  DAT_800d0edf = 1;
  /* WARNING: Read-only address (ram,0x800d0e83) is written */
  draw.dfe = '\x01';
  DAT_800d0ee0 = 0;
  /* WARNING: Read-only address (ram,0x800d0e84) is written */
  draw.isbg = '\0';
  /* WARNING: Read-only address (ram,0x800d0e85) is written */
  draw.r0 = '\0';
  /* WARNING: Read-only address (ram,0x800d0e86) is written */
  draw.g0 = '\0';
  /* WARNING: Read-only address (ram,0x800d0e87) is written */
  draw.b0 = '\0';
  DAT_800d0ee1 = 0;
  DAT_800d0ee2 = 0;
  DAT_800d0ee3 = 0;
  do
  {
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
  ClearOTagR(DAT_800d1180, 0xc00);
  ClearOTagR(DAT_800d1184, 0xc00);
  ClearImage((short *)&local_10, 0, 0xff, 0);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ StartTimer()
// line 666, offset 0x80038554
/* begin block 1 */
// Start line: 1326
/* end block 1 */
// End Line: 1327

/* WARNING: Unknown calling convention yet parameter storage is locked */

void StartTimer(void)

{
  /* WARNING: Subroutine does not return */
  EnterCriticalSection();
}

// decompiled code
// original method signature:
// void /*$ra*/ VblTick()
// line 739, offset 0x800385c0
/* begin block 1 */
// Start line: 1473
/* end block 1 */
// End Line: 1474

/* begin block 2 */
// Start line: 1476
/* end block 2 */
// End Line: 1477

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VblTick(void)

{
  if (devstation != 0)
  {
    trap(0x400);
  }
  DAT_800d10e0 = DAT_800d10e0 + 1;
  DAT_800d10e4 = DAT_800d10e4 + 1;
  if ((DAT_800d10c4 != (ushort *)0x0) && (ULONG_800d1214 < DAT_800d10e0))
  {
    PutDispEnv(DAT_800d10c4);
    DAT_800d10c4 = (ushort *)0x0;
    DAT_800d10e0 = 0;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ DrawCallback()
// line 759, offset 0x8003862c
/* begin block 1 */
// Start line: 1520
/* end block 1 */
// End Line: 1521

/* begin block 2 */
// Start line: 1521
/* end block 2 */
// End Line: 1522

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DrawCallback(void)

{
  ulong uVar1;

  if (DAT_800d10c8 != (ulong *)0x0)
  {
    uVar1 = TIMER_TimeDiff(DAT_800d10cc);
    *DAT_800d10c8 = uVar1;
    DAT_800d10c8 = (ulong *)0x0;
    DAT_800d10c4 = DAT_800d10d0 + DAT_800d0fb0 * 0x14;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ FadeOutSayingLoading(struct GameTracker *gameTracker /*$s1*/)
// line 770, offset 0x80038684
/* begin block 1 */
// Start line: 771
// Start offset: 0x80038684
// Variables:
// 		struct POLY_F4_SEMITRANS *transPrim; // $s2
// 		unsigned long **drawot; // $s3
// 		long fadeTime; // $s0
/* end block 1 */
// End offset: 0x800387B4
// End Line: 804

/* begin block 2 */
// Start line: 1544
/* end block 2 */
// End Line: 1545

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
  DRAW_TranslucentQuad(0, 0, 0x200, 0, 0, 0xf0, 0x200, 0xf0, 0, 0, 0, 2, gameTracker->primPool, ot);
  iVar4 = 0x10;
  FONT_Flush();
  do
  {
    if (0xff < iVar4)
    {
      iVar4 = 0xff;
    }
    gameTracker->drawPage = 1 - gameTracker->drawPage;
    uVar3 = (undefined)iVar4;
    *(undefined *)(puVar5 + 2) = uVar3;
    *(undefined *)((int)puVar5 + 9) = uVar3;
    *(undefined *)((int)puVar5 + 10) = uVar3;
    do
    {
      iVar2 = CheckVolatile(gameTracker->drawTimerReturn);
    } while (iVar2 != 0);
    PutDrawEnv((undefined4 *)(&draw + gameTracker->drawPage));
    do
    {
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
// line 806, offset 0x800387d4
/* begin block 1 */
// Start line: 807
// Start offset: 0x800387D4
// Variables:
// 		long *a1; // stack offset -8
// 		long *a2; // stack offset -4
/* end block 1 */
// End offset: 0x8003882C
// End Line: 832

/* begin block 2 */
// Start line: 1638
/* end block 2 */
// End Line: 1639

/* WARNING: Removing unreachable block (ram,0x8003881c) */
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
// line 834, offset 0x80038834
/* begin block 1 */
// Start line: 835
// Start offset: 0x80038834
// Variables:
// 		long *loadingScreen; // $s0
// 		char langChar[5]; // stack offset -88
// 		int lang; // $v0

/* begin block 1.1 */
// Start line: 856
// Start offset: 0x8003887C
// Variables:
// 		char filename[64]; // stack offset -80
/* end block 1.1 */
// End offset: 0x8003887C
// End Line: 857
/* end block 1 */
// End offset: 0x800388D0
// End Line: 877

/* begin block 2 */
// Start line: 1695
/* end block 2 */
// End Line: 1696

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_ShowLoadingScreen(void)

{
  language_t lVar1;
  long *screen;
  char acStack80[64];

  VSync(0);
  lVar1 = localstr_get_language();
  if (lVar1 != language_english)
  {
    /* WARNING: Subroutine does not return */
    sprintf(acStack80, s__kain2_game_psx_loading_c_tim_800ce778);
  }
  screen = LOAD_ReadFile(s__kain2_game_psx_loading_tim_800ce798, '\v');
  if (screen != (long *)0x0)
  {
    screen_to_vram(screen, DAT_800d0fb0);
    /* WARNING: Subroutine does not return */
    MEMPACK_Free((char *)screen);
  }
  return;
}

// decompiled code
// original method signature:
// long * /*$ra*/ MAIN_LoadTim(char *name /*$a0*/)
// line 879, offset 0x800388e4
/* begin block 1 */
// Start line: 880
// Start offset: 0x800388E4
/* end block 1 */
// End offset: 0x800388E4
// End Line: 880

/* begin block 2 */
// Start line: 1804
/* end block 2 */
// End Line: 1805

void MAIN_LoadTim(char *param_1)

{
  LOAD_ReadFile(param_1, '\v');
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ init_menus(struct GameTracker *gt /*$s1*/)
// line 890, offset 0x80038904
/* begin block 1 */
// Start line: 891
// Start offset: 0x80038904
// Variables:
// 		struct menu_t *menu; // $s0
/* end block 1 */
// End offset: 0x80038904
// End Line: 891

/* begin block 2 */
// Start line: 1826
/* end block 2 */
// End Line: 1827

void init_menus(GameTracker *gt)

{
  ulong allocSize;

  allocSize = menu_data_size();
  /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(allocSize, '-');
}

// decompiled code
// original method signature:
// void /*$ra*/ MAIN_DoMainInit()
// line 902, offset 0x80038950
/* begin block 1 */
// Start line: 1850
/* end block 1 */
// End Line: 1851

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_DoMainInit(void)

{
  InitDisplay();
  InitGeom();
  SetGeomOffset(0x100, 0x78);
  SetGeomScreen(0x140);
  VRAM_InitVramBlockCache();
  FONT_Init();
  DAT_800d10c4 = 0;
  VSyncCallback(VblTick);
  DrawSyncCallback(DrawCallback);
  GAMEPAD_Init();
  SOUND_Init();
  VOICEXA_Init();
  if (nosound != 0)
  {
    SOUND_SfxOff();
    ULONG_800d116c._0_1_ = 0;
    ULONG_800d116c._2_1_ = 0;
  }
  if (nomusic != 0)
  {
    SOUND_MusicOff();
    ULONG_800d116c._1_1_ = 0;
  }
  if ((vmRealClock & 0x80000U) == 0)
  {
    ULONG_800d116c._2_1_ = 0;
  }
  init_menus((GameTracker *)&gameTrackerX);
  SAVE_Init((GameTracker *)&gameTrackerX);
  srand(0);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MAIN_InitVolume()
// line 949, offset 0x80038a44
/* begin block 1 */
// Start line: 1898
/* end block 1 */
// End Line: 1899

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_InitVolume(void)

{
  aadInitVolume();
  aadStartMasterVolumeFade(_USHORT_800d115c, 0x100, (TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback)0x0);
  ULONG_800d116c._3_1_ = 1;
  aadSetNoUpdateMode(0);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MAIN_ResetGame()
// line 957, offset 0x80038a84
/* begin block 1 */
// Start line: 1944
/* end block 1 */
// End Line: 1945

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_ResetGame(void)

{
  GAMELOOP_SetScreenWipe(0, 0, -1);
  DAT_800d10ec = DAT_800d10ec & 0xffffff6e;
  RAZIEL_StartNewGame();
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MAIN_MainMenuInit()
// line 967, offset 0x80038ad4
/* begin block 1 */
// Start line: 968
// Start offset: 0x80038AD4

/* begin block 1.1 */
// Start line: 968
// Start offset: 0x80038AD4
// Variables:
// 		char sfxFileName[64]; // stack offset -72
/* end block 1.1 */
// End offset: 0x80038C18
// End Line: 990
/* end block 1 */
// End offset: 0x80038C18
// End Line: 995

/* begin block 2 */
// Start line: 1965
/* end block 2 */
// End Line: 1966

/* WARNING: Removing unreachable block (ram,0x80038b18) */
/* WARNING: Removing unreachable block (ram,0x80038b1c) */
/* WARNING: Removing unreachable block (ram,0x80038b68) */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_MainMenuInit(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 local_48[10];
  undefined auStack32[24];

  mainMenuMode = 0;
  mainMenuTimeOut = 0;
  /* WARNING: Read-only address (ram,0x800d0f8c) is written */
  clearRect[0].r0 = '\0';
  /* WARNING: Read-only address (ram,0x800d0f8d) is written */
  clearRect[0].g0 = '\0';
  /* WARNING: Read-only address (ram,0x800d0f8e) is written */
  clearRect[0].b0 = '\0';
  /* WARNING: Read-only address (ram,0x800d0f9c) is written */
  clearRect[1].r0 = '\0';
  /* WARNING: Read-only address (ram,0x800d0f9d) is written */
  clearRect[1].g0 = '\0';
  /* WARNING: Read-only address (ram,0x800d0f9e) is written */
  clearRect[1].b0 = '\0';
  puVar1 = (undefined4 *)s__kain2_sfx_object_mainmenu_mainm_800ce7d0;
  puVar2 = local_48;
  do
  {
    puVar4 = puVar2;
    puVar3 = puVar1;
    uVar5 = puVar3[1];
    uVar6 = puVar3[2];
    uVar7 = puVar3[3];
    *puVar4 = *puVar3;
    puVar4[1] = uVar5;
    puVar4[2] = uVar6;
    puVar4[3] = uVar7;
    puVar1 = puVar3 + 4;
    puVar2 = puVar4 + 4;
  } while (puVar3 + 4 != (undefined4 *)(s__kain2_sfx_object_mainmenu_mainm_800ce7d0 + 0x20));
  uVar5 = puVar3[5];
  puVar4[4] = s__kain2_sfx_object_mainmenu_mainm_800ce7d0._32_4_;
  /* WARNING: Subroutine does not return */
  puVar4[5] = uVar5;
  memset(auStack32, 0, 0x18);
}

// decompiled code
// original method signature:
// void /*$ra*/ MAIN_FreeMainMenuStuff()
// line 1009, offset 0x80038c6c
/* begin block 1 */
// Start line: 2066
/* end block 1 */
// End Line: 2067

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_FreeMainMenuStuff(void)

{
  int iVar1;

  menuface_terminate();
  VRAM_DisableTerrainArea();
  if (mainMenuScreen != (long *)0x0)
  {
    /* WARNING: Subroutine does not return */
    MEMPACK_Free((char *)mainMenuScreen);
  }
  aadFreeDynamicSfx(mainMenuSfx);
  while (iVar1 = aadGetNumLoadsQueued(), iVar1 != 0)
  {
    aadProcessLoadQueue();
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MAIN_StartGame()
// line 1044, offset 0x80038cdc
/* begin block 1 */
// Start line: 2136
/* end block 1 */
// End Line: 2137

/* begin block 2 */
// Start line: 2137
/* end block 2 */
// End Line: 2138

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_StartGame(void)

{
  if (mainMenuFading == 0)
  {
    DAT_800d111e = 0;
    currentMenu = (DebugMenuLine *)0x0;
    mainMenuFading = 1;
    GAMELOOP_SetScreenWipe(-0x1e, 0x1e, 10);
  }
  else
  {
    _midiDataByteCount = 2;
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
// line 1083, offset 0x80038d48
/* begin block 1 */
// Start line: 1084
// Start offset: 0x80038D48
// Variables:
// 		unsigned long **drawot; // $s1
/* end block 1 */
// End offset: 0x80038E04
// End Line: 1172

/* begin block 2 */
// Start line: 2220
/* end block 2 */
// End Line: 2221

long MAIN_DoMainMenu(GameTracker *gameTracker, MainTracker *mainTracker, long menuPos)

{
  ulong **drawot;

  DAT_800d11ec = 0x1000;
  drawot = gameTracker->drawOT;
  DrawPrim((int)(clearRect + gameTracker->drawPage));
  GAMEPAD_Process(gameTracker);
  DEBUG_Process(gameTracker);
  if (mainMenuScreen != (long *)0x0)
  {
    screen_to_vram(mainMenuScreen, gameTracker->drawPage);
  }
  GAMELOOP_HandleScreenWipes(drawot);
  MENUFACE_RefreshFaces();
  FONT_Flush();
  mainMenuTimeOut = mainMenuTimeOut + 1;
  GAMELOOP_FlipScreenAndDraw(gameTracker, drawot);
  if ((mainMenuFading != 0) && (gameTracker->wipeTime == -1))
  {
    MAIN_StartGame();
  }
  return 0;
}

// decompiled code
// original method signature:
// int /*$ra*/ MainG2(void *appData /*$s7*/)
// line 1187, offset 0x80038e1c
/* begin block 1 */
// Start line: 1188
// Start offset: 0x80038E1C
// Variables:
// 		struct MainTracker *mainTracker; // $s2
// 		struct GameTracker *gameTracker; // $s3
// 		long menuPos; // $s5
// Labels:
//		0x00001718	exit

/* begin block 1.1 */
// Start line: 1381
// Start offset: 0x80039038
// Variables:
// 		struct InterfaceItem *item; // $s1
// 		int timer; // $s0
/* end block 1.1 */
// End offset: 0x800390E8
// End Line: 1445

/* begin block 1.2 */
// Start line: 1625
// Start offset: 0x800392A4
/* end block 1.2 */
// End offset: 0x80039390
// End Line: 1695
/* end block 1 */
// End offset: 0x80039440
// End Line: 1746

/* begin block 2 */
// Start line: 2374
/* end block 2 */
// End Line: 2375

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int MainG2(void *appData)

{
  bool bVar1;
  _G2Bool_Enum _Var2;
  int iVar3;
  uint uVar4;
  long menuPos;

  menuPos = 0;
  CheckForDevStation();
  mainOptionsInit = '\0';
  _Var2 = MainG2_InitEngine(appData, 0x200, 0xf0, (char *)0x0);
  if (_Var2 == G2FALSE)
  {
    MainG2_ShutDownEngine(appData);
    return 0;
  }
  MEMPACK_Init();
  LOAD_InitCd();
  StartTimer();
  STREAM_InitLoader(s__BIGFILE_DAT_1_800ce850, &DAT_800ce860);
  localstr_set_language(~language_english);
  GAMELOOP_SystemInit((GameTracker *)&gameTrackerX);
  gDefragRequest._1_1_ = 0xff;
  gDefragRequest._0_1_ = 0xff;
  DAT_800d10d0 = &disp;
  ProcessArgs(&DAT_800d1108, (GameTracker *)&gameTrackerX);
  InitMainTracker((MainTracker *)&midiDataByteCount);
  MAIN_DoMainInit();
  _midiDataByteCount = 6;
  midiEventFunction = 0;
  do
  {
    _CHAR____800d1220 = _midiDataByteCount;
    switch (_midiDataByteCount)
    {
    case 1:
      SOUND_UpdateSound();
      if ((vmRealClock & 0x80000U) != 0)
      {
        VOICEXA_Tick();
      }
      PSX_GameLoop((GameTracker *)&gameTrackerX);
      if (DAT_800d1118 != 0)
      {
        FadeOutSayingLoading((GameTracker *)&gameTrackerX);
        aadStopAllSfx();
        STREAM_DumpAllLevels(0, 0);
        RemoveAllObjects((GameTracker *)&gameTrackerX);
        while ((iVar3 = aadGetNumLoadsQueued(), iVar3 != 0 || ((aadMem->sramDefragInfo).status != 0)))
        {
          SOUND_UpdateSound();
          STREAM_PollLoadQueue();
        }
        SOUND_ShutdownMusic();
        MEMPACK_FreeByType('\x0e');
        GAMELOOP_ResetGameStates();
        MEMPACK_DoGarbageCollection();
        uVar4 = SEXT24(DAT_800d1118);
        if (uVar4 == 2)
        {
        LAB_8003933c:
          _midiDataByteCount = 8;
        }
        else
        {
          if (uVar4 == 3)
          {
            _midiDataByteCount = 6;
            midiEventFunction = uVar4;
          }
          else
          {
            if (uVar4 == 4)
            {
              _midiDataByteCount = 2;
              if ((DAT_800d10f0 & 0x200000) == 0)
              {
                SAVE_ClearMemory((GameTracker *)&gameTrackerX);
              }
            }
            else
            {
              _midiDataByteCount = 2;
            }
          }
        }
      }
      break;
    case 2:
      if ((DAT_800d10f0 & 0x1000000) != 0)
      {
        play_movie((char *)InterfaceItem_ARRAY_800ce5e0);
        DAT_800d10f0 = DAT_800d10f0 & 0xfeffffff;
      }
      if ((DAT_800d10f0 & 0x200000) != 0)
      {
        DAT_800d10f0 = DAT_800d10f0 & 0xffdfffff;
      }
      if (nosound == 0)
      {
        MAIN_InitVolume();
      }
      MAIN_ShowLoadingScreen();
      FONT_ReloadFont();
      DrawSync(0);
      DAT_800d10d8 = 0;
      STREAM_Init();
      GAMELOOP_LevelLoadAndInit(&DAT_800d1108, (GameTracker *)&gameTrackerX);
      DAT_800d1118 = 0;
      _midiDataByteCount = 1;
      do
      {
        iVar3 = STREAM_PollLoadQueue();
      } while (iVar3 != 0);
      DAT_800d10e0 = 0;
      break;
    case 4:
      LOAD_ChangeDirectory(s_Menustuff_800ce864);
      do
      {
        uVar4 = midiEventFunction;
        if (5 < midiEventFunction)
          goto LAB_800390f0;
        DAT_800d10ec = DAT_800d10ec & 0xfffffffe;
        show_screen((char *)(InterfaceItems + midiEventFunction));
        iVar3 = 1;
        if (InterfaceItems[uVar4].timeout != 0)
        {
          do
          {
            GAMEPAD_Process((GameTracker *)&gameTrackerX);
            if (((int)(uint)InterfaceItems[uVar4].buttonTimeout < iVar3) &&
                ((DAT_800d0ff8 & 0x80) != 0))
              break;
            VSync(0);
            bVar1 = iVar3 < (int)(uint)InterfaceItems[uVar4].timeout;
            iVar3 = iVar3 + 1;
          } while (bVar1);
        }
        midiEventFunction = SEXT24(InterfaceItems[uVar4].nextItem);
      } while (((int)midiEventFunction < 0) || (InterfaceItems[midiEventFunction].itemType == 1));
      _midiDataByteCount = 6;
    LAB_800390f0:
      FONT_ReloadFont();
      if (_midiDataByteCount != 6)
      {
        if (DoMainMenu != 0)
          goto LAB_8003933c;
        MAIN_ResetGame();
        DAT_800d111e = 0;
        mainMenuFading = 1;
        MAIN_StartGame();
      }
      break;
    case 6:
      CINE_Load();
      do
      {
        if ((int)midiEventFunction < 0)
          goto LAB_80038fd0;
        iVar3 = CINE_Loaded();
        if (iVar3 != 0)
        {
          CINE_Play((char *)(InterfaceItems + midiEventFunction), 0xffff, 2);
          ClearDisplay();
        }
        midiEventFunction = SEXT24(InterfaceItems[midiEventFunction].nextItem);
      } while (InterfaceItems[midiEventFunction].itemType == 0);
      _midiDataByteCount = 4;
    LAB_80038fd0:
      CINE_Unload();
      if ((int)midiEventFunction < 0)
      {
        _midiDataByteCount = 8;
      }
      if (nosound == 0)
      {
        SOUND_StopAllSound();
      }
      break;
    case 7:
      DAT_800d1228 = 1;
      break;
    case 8:
      DAT_800d0fb6 = 0;
      ProcessArgs(&DAT_800d1108, (GameTracker *)&gameTrackerX);
      MAIN_ResetGame();
      LOAD_ChangeDirectory(s_Menustuff_800ce864);
      MAIN_MainMenuInit();
      MAIN_InitVolume();
      SAVE_ClearMemory((GameTracker *)&gameTrackerX);
      _midiDataByteCount = 9;
      FONT_ReloadFont();
      break;
    case 9:
      menuPos = MAIN_DoMainMenu((GameTracker *)&gameTrackerX, (MainTracker *)&midiDataByteCount,
                                menuPos);
    }
    STREAM_PollLoadQueue();
    if (DAT_800d1228 != 0)
    {
      SOUND_StopAllSound();
      SOUND_Free();
      SetDispMask(0);
      DrawSync(0);
      VSync(0);
      DrawSyncCallback(0);
      VSyncCallback(0);
      /* WARNING: Subroutine does not return */
      EnterCriticalSection();
    }
  } while (true);
}
