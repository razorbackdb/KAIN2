
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

void ClearDisplay(void)

{
  PutDrawEnv((u_char *)(&draw + gameTrackerX.gameData.asmData.dispPage));
  DrawPrim((int)(&clearRect + gameTrackerX.gameData.asmData.dispPage));
  DrawSync(0);
  PutDispEnv((u_short *)(&disp + gameTrackerX.gameData.asmData.dispPage));
  SetDispMask(1);
  return;
}

void show_screen(char *name)

{
  long *addr;

  addr = LOAD_ReadFileFromCD(name, '\v');
  if (addr != (long *)0x0)
  {
    LOAD_LoadTIM2(addr, 0, gameTrackerX.gameData.asmData.dispPage << 8, 0x200, 0x100);
    MEMPACK_Init((char *)addr);
  }
  return;
}

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

void InitMainTracker(MainTracker *mainTracker)

{
  mainTracker->mainState = 0;
  mainTracker->previousState = 0;
  mainTracker->done = 0;
  return;
}

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

void ExtractWorldName(char *worldName, char *levelName)

{
  byte bVar1;

  bVar1 = *levelName;
  while ((bVar1 != 0x2d && (((u_int)bVar1 - 0x41 < 0x1a || ((u_int)bVar1 - 0x61 < 0x1a)))))
  {
    levelName = (char *)((byte *)levelName + 1);
    *worldName = bVar1;
    bVar1 = *levelName;
    worldName = (char *)((byte *)worldName + 1);
  }
  *worldName = 0;
  return;
}

void ExtractLevelNum(char *levelNum, char *levelName)

{
  byte bVar1;

  bVar1 = *levelName;
  while (bVar1 != 0x2d)
  {
    if ((u_int)bVar1 - 0x30 < 10)
      goto LAB_80038658;
    levelName = (char *)((byte *)levelName + 1);
    bVar1 = *levelName;
  }
  bVar1 = *levelName;
  while ((u_int)bVar1 - 0x30 < 10)
  {
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

void ProcessArgs(char *baseAreaName, GameTracker *gameTracker)

{
  long *levelName;
  char *pcVar1;
  char acStack88[32];
  char acStack56[32];

  levelName = LOAD_ReadFileFromCD("\\kain2\\game\\psx\\kain2.arg", '\n');
  if (levelName == (long *)0x0)
  {
    *(u_char *)baseAreaName = 0x65646e75;
    baseAreaName[4] = 'r';
    baseAreaName[5] = '1';
    baseAreaName[6] = '\0';
  }
  else
  {
    ExtractWorldName(acStack56, (char *)levelName);
    ExtractLevelNum(acStack88, (char *)levelName);
    sprintf(baseAreaName, "%s%s");
    pcVar1 = FindTextInLine("-NOSOUND", (char *)levelName);
    if (pcVar1 != (char *)0x0)
    {
      nosound = 1;
      nomusic = 1;
    }
    pcVar1 = FindTextInLine("-NOMUSIC", (char *)levelName);
    if (pcVar1 != (char *)0x0)
    {
      nomusic = 1;
    }
    pcVar1 = FindTextInLine("-TIMEOUT", (char *)levelName);
    if (pcVar1 != (char *)0x0)
    {
      gameTracker->debugFlags = gameTracker->debugFlags | 0x20000;
    }
    pcVar1 = FindTextInLine("-DEMO", (char *)levelName);
    if (pcVar1 != (char *)0x0)
    {
      gameTrackerX.setDemoMode = '\x01';
    }
    pcVar1 = FindTextInLine("-MAINMENU", (char *)levelName);
    if (pcVar1 != (char *)0x0)
    {
      DoMainMenu = 1;
    }
    pcVar1 = FindTextInLine("-INSPECTRAL", (char *)levelName);
    if (pcVar1 != (char *)0x0)
    {
      gameTrackerX.gameData.asmData.MorphType = 1;
    }
    pcVar1 = FindTextInLine("-VOICE", (char *)levelName);
    if (pcVar1 != (char *)0x0)
    {
      gameTracker->debugFlags = gameTracker->debugFlags | 0x80000;
    }
    pcVar1 = FindTextInLine("-DEBUG_CD", (char *)levelName);
    if (pcVar1 != (char *)0x0)
    {
      gameTracker->debugFlags = gameTracker->debugFlags | 0x80000000;
    }
    pcVar1 = FindTextInLine("-LOADGAME", (char *)levelName);
    if (pcVar1 != (char *)0x0)
    {
      gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x200000;
    }
    pcVar1 = FindTextInLine("-ALLWARP", (char *)levelName);
    if (pcVar1 != (char *)0x0)
    {
      gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x400000;
    }
    gameTracker->demoEnabled = '\x01';
    gameTracker->debugFlags = gameTracker->debugFlags | 0x80000;
    MEMPACK_Init((char *)levelName);
  }
  gameTrackerX.debugFlags = gameTrackerX.debugFlags | 0x40000;
  return;
}

void ClearDisplay(void)

{
  BLK_FILL *pBVar1;
  int iVar2;
  u_char local_10;
  u_char local_c;

  local_10 = 0x200;
  local_c = 0x2000200;
  ResetGraph(3);
  SetGraphDebug('\0');
  SetDrawEnv((undefined2 *)&draw, 0, 0, 0x200, 0xf0);
  SetDefDispEnv((undefined2 *)&disp, 0, 0, 0x200, 0xf0);
  SetDrawEnv((undefined2 *)&DRAWENV_800d1fe8, 0, 0x100, 0x200, 0xf0);
  SetDefDispEnv((undefined2 *)&DISPENV_800d1f74, 0, 0x100, 0x200, 0xf0);
  iVar2 = 0;
  pBVar1 = &clearRect;

  DRAWENV_800d1fe8.dtd = '\x01';

  draw.dtd = '\x01';

  DRAWENV_800d1fe8.dfe = '\x01';

  draw.dfe = '\x01';

  DRAWENV_800d1fe8.isbg = '\0';

  draw.isbg = '\0';

  draw.r0 = '\0';

  draw.g0 = '\0';

  draw.b0 = '\0';

  DRAWENV_800d1fe8.r0 = '\0';

  DRAWENV_800d1fe8.g0 = '\0';

  DRAWENV_800d1fe8.b0 = '\0';
  do
  {
    *(undefined *)((int)&pBVar1->tag + 3) = 3;
    pBVar1->code = '\x02';
    pBVar1->x0 = 0;
    pBVar1->y0 = (u_short)(iVar2 << 8);
    pBVar1->w = 0x200;
    pBVar1->h = 0xf0;
    pBVar1->r0 = '\0';
    pBVar1->g0 = '\0';
    pBVar1->b0 = '\0';
    iVar2 = iVar2 + 1;
    pBVar1 = pBVar1 + 1;
  } while (iVar2 < 2);
  ClearDisplay();
  ClearOTagR(gameTrackerX.drawOT, 0xc00);
  ClearOTagR(gameTrackerX.dispOT, 0xc00);
  ClearImage(&local_10, 0, 0xff, 0);
  return;
}

void StartTimer(void)

{
  ExitCriticalSection();
  __timerEvent = OpenEvent();
  EnableEvent();
  SetRCnt(0xf2000000, 0xffff, (u_int)&DAT_00001001);
  StartRCnt(0xf2000000);
  EnterCriticalSection();
  gTimerEnabled = 1;
  return;
}

void VblTick(void)

{
  if (devstation != 0)
  {
    trap(0x400);
  }
  gameTrackerX.vblFrames = gameTrackerX.vblFrames + 1;
  gameTrackerX.vblCount = gameTrackerX.vblCount + 1;
  if ((gameTrackerX.reqDisp != (void *)0x0) &&
      ((u_int)gameTrackerX.frameRateLock < gameTrackerX.vblFrames))
  {
    PutDispEnv((u_short *)gameTrackerX.reqDisp);
    gameTrackerX.reqDisp = (void *)0x0;
    gameTrackerX.vblFrames = 0;
  }
  return;
}

void VSyncCallbacks(void)

{
  u_long uVar1;

  if (gameTrackerX.drawTimerReturn != (long *)0x0)
  {
    uVar1 = TIMER_TimeDiff(gameTrackerX.usecsStartDraw);
    *gameTrackerX.drawTimerReturn = uVar1;
    gameTrackerX.drawTimerReturn = (long *)0x0;
    gameTrackerX.reqDisp =
        (void *)((int)gameTrackerX.disp + gameTrackerX.gameData.asmData.dispPage * 0x14);
  }
  return;
}

void FadeOutSayingLoading(GameTracker *gameTracker)

{
  bool bVar1;
  int iVar2;
  undefined uVar3;
  int iVar4;
  u_long *puVar5;
  u_long **ot;

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
    PutDrawEnv((u_char *)(&draw + gameTracker->drawPage));
    do
    {
      iVar2 = CheckVolatile(gameTracker->reqDisp);
    } while (iVar2 != 0);
    iVar2 = (gameTracker->gameData).asmData.dispPage;
    *(u_long **)&gameTracker->drawTimerReturn = &gameTracker->drawTime;
    (gameTracker->gameData).asmData.dispPage = 1 - iVar2;
    VSync(0);
    DrawOTag(ot + 0xbff);
    bVar1 = iVar4 != 0xff;
    iVar4 = iVar4 + 0x10;
  } while (bVar1);
  return;
}

void CheckForDevStation(void)

{
  devstation = 1;
  DAT_80180000 = 0;
  _DAT_80380000 = 0x12345678;
  return;
}

void MAIN_ShowLoadingScreen(void)

{
  language_t lVar1;
  long *addr;
  char *string;
  char acStack80[64];

  VSync(0);
  lVar1 = localstr_get_language();
  if (lVar1 == language_english)
  {
    string = "\\kain2\\game\\psx\\loading.tim";
  }
  else
  {
    string = acStack80;
    sprintf(string, "\\kain2\\game\\psx\\loading%c.tim");
  }
  addr = LOAD_ReadFileFromCD(string, '\v');
  if (addr != (long *)0x0)
  {
    LOAD_LoadTIM2(addr, 0, gameTrackerX.gameData.asmData.dispPage << 8, 0x200, 0x100);
    MEMPACK_Init((char *)addr);
  }
  return;
}

long *MAIN_LoadTim(char *name)

{
  long *plVar1;

  plVar1 = LOAD_ReadFileFromCD(name, '\v');
  return plVar1;
}

void init_menus(GameTracker *gt)

{
  u_long allocSize;
  menu_t *menu;

  allocSize = menu_data_size();
  menu = (menu_t *)MEMPACK_Malloc(allocSize, '-');
  menuface_initialize(menu, gt);
  gt->menu = menu;
  return;
}

void MAIN_DoMainMenu(void)

{
  ClearDisplay();
  InitGeom();
  SetGeomOffset(0x100, 0x78);
  SetGeomScreen(0x140);
  VRAM_InitVramBlockCache();
  EVENT_Init();
  gameTrackerX.reqDisp = (void *)0x0;
  DrawCallback(VblTick);
  DMACallback(VSyncCallbacks);
  GAMEPAD_Detect();
  GAMEPAD_Init();
  VOICEXA_Play();
  if (nosound != 0)
  {
    SOUND_SfxOff();
    gameTrackerX.sound.gSfxOn = '\0';
    gameTrackerX.sound.gVoiceOn = '\0';
  }
  if (nomusic != 0)
  {
    SOUND_MusicOff();
    gameTrackerX.sound.gMusicOn = '\0';
  }
  if ((gameTrackerX.debugFlags & 0x80000U) == 0)
  {
    gameTrackerX.sound.gVoiceOn = '\0';
  }
  init_menus(&gameTrackerX);
  HUD_Init(&gameTrackerX);
  GetVideoMode(0);
  return;
}

void MAIN_ShowPalWarningScreen(GameTracker *gameTracker)

{
  long *addr;

  addr = LOAD_ReadFileFromCD("\\kain2\\game\\psx\\warning.tim", '\v');
  if (addr != (long *)0x0)
  {
    LOAD_LoadToAddress(addr, 0, (gameTracker->gameData).asmData.dispPage << 8, 0, 0);
    MEMPACK_Init((char *)addr);
  }
  return;
}

void MAIN_InitVolume(void)

{
  aadInitVolume();
  aadSetSfxMasterVolume(gameTrackerX.sound.gMasterVol, 0x100,
                        (TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback)0x0);
  gameTrackerX.sound.soundsLoaded = '\x01';
  aadSetNoUpdateMode(0);
  return;
}

void MAIN_ResetGame(void)

{
  GAMELOOP_SetScreenWipe(0, 0, -1);
  gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffffff6e;
  RAZIEL_StartNewGame();
  return;
}

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
  u_char local_48[10];
  undefined auStack32[24];

  mainMenuMode = 0;
  mainMenuTimeOut = 0;
  puVar1 = (u_char *)"\\kain2\\sfx\\object\\mainmenu\\mainmenu.snf";
  puVar2 = local_48;
  do
  {
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
  memset(auStack32, 0, 0x18);
  mainMenuSfx = 0;
  lVar3 = LOAD_DoesFileExist((char *)local_48);
  if (lVar3 != 0)
  {
    mainMenuSfx = aadLoadDynamicSoundBankReturn2("mainmenu", 0, 0);
    while (iVar4 = aadGetNumLoadsQueued(), iVar4 != 0)
    {
      aadProcessLoadQueue();
    }
  }
  mainMenuScreen = MAIN_LoadTim("\\kain2\\game\\psx\\frontend\\title1.tim");
  VRAM_EnableTerrainArea();
  menu_initialize();
  currentMenu = &mainMenu;
  gameTrackerX.gameMode = 4;
  menu_sound(gameTrackerX.menu, menudefs_main_menu);
  return;
}

void MAIN_FreeMainMenuStuff(void)

{
  int iVar1;

  menuface_terminate();
  VRAM_DisableTerrainArea();
  if (mainMenuScreen != (long *)0x0)
  {
    MEMPACK_Init((char *)mainMenuScreen);
    mainMenuScreen = (long *)0x0;
  }
  aadFreeDynamicSfx(mainMenuSfx);
  while (iVar1 = aadGetNumLoadsQueued(), iVar1 != 0)
  {
    aadProcessLoadQueue();
  }
  return;
}

void MAIN_StartGame(void)

{
  if (mainMenuFading == 0)
  {
    gameTrackerX.gameMode = 0;
    currentMenu = (DebugMenuLine *)0x0;
    mainMenuFading = 1;
    GAMELOOP_SetScreenWipe(-0x1e, 0x1e, 10);
  }
  else
  {
    mainTrackerX.mainState = 2;
    MAIN_FreeMainMenuStuff();
    gEndGameNow = 0;
    mainMenuFading = 0;
    currentMenu = &standardMenu;
  }
  return;
}

long MAIN_DoMainInit(GameTracker *gameTracker, MainTracker *mainTracker, long menuPos)

{
  u_long **drawot;

  drawot = gameTracker->drawOT;
  DrawPrim((int)(&clearRect + gameTracker->drawPage));
  DEBUG_Process(gameTracker);
  DEBUG_ProcessSecondController(gameTracker);
  if (mainMenuScreen != (long *)0x0)
  {
    LOAD_LoadTIM2(mainMenuScreen, 0, gameTracker->drawPage << 8, 0x200, 0x100);
  }
  SIGNAL_HandleScreenWipe(drawot);
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
  _Var3 = MainG2_InitEngine(appData, 0x200, 0xf0, (char *)0x0);
  if (_Var3 != G2FALSE)
  {
    MEMPACK_Init();
    LOAD_InitCdStreamMode();
    StartTimer();
    STREAM_Init("\\BIGFILE.DAT;1", "");
    localstr_set_language(~language_english);
    GAMELOOP_SystemInit(&gameTrackerX);
    gameTrackerX.lastLvl = -1;
    gameTrackerX.currentLvl = -1;
    gameTrackerX.disp = &disp;
    ProcessArgs(gameTrackerX.baseAreaName, &gameTrackerX);
    InitMainTracker(&mainTrackerX);
    MAIN_DoMainMenu();
    mainTrackerX.mainState = 6;
    mainTrackerX.movieNum = 0;
    do
    {
      mainTrackerX.previousState = mainTrackerX.mainState;
      switch (mainTrackerX.mainState)
      {
      case 1:
        SOUND_Update3dSound();
        if ((gameTrackerX.debugFlags & 0x80000U) != 0)
        {
          VOICEXA_Tick();
        }
        PSX_GameLoop(&gameTrackerX);
        if (gameTrackerX.levelDone != 0)
        {
          FadeOutSayingLoading(&gameTrackerX);
          SOUND_ResumeAllSound();
          SOUND_FreeDynamicMusic();
          STREAM_DumpAllLevels(0, 0);
          RemoveAllObjects(&gameTrackerX);
          while (iVar4 = aadGetNumLoadsQueued(), iVar4 != 0)
          {
            aadProcessLoadQueue();
          }
          MEMPACK_Free('\x0e');
          GAMELOOP_ResetGameStates();
          MEMPACK_DoGarbageCollection();
          iVar4 = (int)gameTrackerX.levelDone;
          if (iVar4 == 2)
          {
          LAB_80039890:
            mainTrackerX.mainState = 8;
          }
          else
          {
            if (iVar4 == 3)
            {
              mainTrackerX.mainState = 6;
              mainTrackerX.movieNum = iVar4;
            }
            else
            {
              if (iVar4 != 4)
                goto LAB_80039688;
              mainTrackerX.mainState = 2;
              if ((gameTrackerX.streamFlags & 0x200000U) == 0)
              {
                SAVE_ClearMemory(&gameTrackerX);
              }
            }
          }
        }
        break;
      case 2:
      case 0xb:
        if ((gameTrackerX.streamFlags & 0x1000000U) != 0)
        {
          play_movie((char *)&InterfaceItem_800cf7e4);
          gameTrackerX.streamFlags = gameTrackerX.streamFlags & 0xfeffffff;
        }
        if ((gameTrackerX.streamFlags & 0x200000U) != 0)
        {
          gameTrackerX.streamFlags = gameTrackerX.streamFlags & 0xffdfffff;
        }
        if (nosound == 0)
        {
          MAIN_InitVolume();
        }
        MAIN_ShowLoadingScreen();
        FONT_ReloadFont();
        DrawSync(0);
        gameTrackerX.frameCount = 0;
        STREAM_InitLoader();
        GAMEPAD_LoadDemo();
        GAMELOOP_StreamLevelLoadAndInit(gameTrackerX.baseAreaName, &gameTrackerX);
        gameTrackerX.levelDone = 0;
        mainTrackerX.mainState = 1;
        do
        {
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
        LOAD_ReadDirectory("Menustuff");
        lVar2 = mainTrackerX.movieNum;
        show_screen((char *)(&InterfaceItems + mainTrackerX.movieNum));
        iVar4 = 1;
        if ((&InterfaceItems)[lVar2].timeout != 0)
        {
          do
          {
            DEBUG_Process(&gameTrackerX);
            if (((int)(u_int)(&InterfaceItems)[lVar2].buttonTimeout < iVar4) &&
                ((gameTrackerX.controlCommand[0][1] & 0x80U) != 0))
              break;
            VSync(0);
            bVar1 = iVar4 < (int)(u_int)(&InterfaceItems)[lVar2].timeout;
            iVar4 = iVar4 + 1;
          } while (bVar1);
        }
        FONT_ReloadFont();
        if (DoMainMenu == 0)
        {
          MAIN_ResetGame();
          mainTrackerX.mainState = 2;
        }
        else
        {
          if (gameTrackerX.setDemoMode == '\0')
            goto LAB_80039890;
        LAB_80039688:
          mainTrackerX.mainState = 2;
        }
        break;
      case 5:
        if (0x1e < gameTrackerX.vblCount)
        {
          mainTrackerX.mainState = 6;
          mainTrackerX.movieNum = 0;
        }
        break;
      case 6:
        CINE_Load();
        do
        {
          if (mainTrackerX.movieNum < 0)
            goto LAB_8003959c;
          iVar4 = CINE_Loaded();
          if (iVar4 != 0)
          {
            CINE_Play((char *)(&InterfaceItems + mainTrackerX.movieNum), 0xffff, 2);
            ClearDisplay();
          }
          mainTrackerX.movieNum = (long)(&InterfaceItems)[mainTrackerX.movieNum].nextItem;
        } while ((&InterfaceItems)[mainTrackerX.movieNum].itemType == 0);
        mainTrackerX.mainState = 4;
      LAB_8003959c:
        CINE_Unload();
        if (mainTrackerX.movieNum < 0)
        {
          mainTrackerX.mainState = 8;
        }
        if (nosound == 0)
        {
          SOUND_ResumeAllSound();
        }
        break;
      case 7:
        mainTrackerX.done = 1;
        break;
      case 8:
        gameTrackerX.gameData.asmData.MorphType = 0;
        ProcessArgs(gameTrackerX.baseAreaName, &gameTrackerX);
        MAIN_ResetGame();
        LOAD_ReadDirectory("Menustuff");
        MAIN_MainMenuInit();
        MAIN_InitVolume();
        SAVE_ClearMemory(&gameTrackerX);
        mainTrackerX.mainState = 9;
        FONT_ReloadFont();
        break;
      case 9:
        menuPos = MAIN_DoMainInit(&gameTrackerX, &mainTrackerX, menuPos);
      }
      STREAM_PollLoadQueue();
    } while (mainTrackerX.done == 0);
    SOUND_ResumeAllSound();
    SOUND_Free();
    SetDispMask(0);
    DrawSync(0);
    VSync(0);
    DMACallback(0);
    DrawCallback(0);
    ExitCriticalSection();
    StopRCnt(0xf2000000);
    DisableEvent();
    CloseEvent();
    EnterCriticalSection();
    VSync(5);
    VOICEXA_CdSyncCallback();
    StopPAD();
    ResetGraph(3);
  }
  MainG2_ShutDownEngine(appData);
  return 0;
}
