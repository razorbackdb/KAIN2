#include "KAIN2.H"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

G2AppDataVM appDataVM;

void __main(void)

{
    int __initialised = 0;
    if (__initialised == 0)
    {
        __initialised = 1;
    }
    return;
}

void ClearBss(void)

{
    DebugMenuLine *pDVar1;

    /*pDVar1 = &eventMenu;
    do
    {
        pDVar1->type = DEBUG_LINE_TYPE_BIT;
        pDVar1 = (DebugMenuLine *)&pDVar1->lower;
    } while (pDVar1 < (DebugMenuLine *)&DAT_800dd340);*/
}

G2Bool MainG2_InitEngine(void *appData, unsigned int screenWidth, unsigned int screenHeight, char *filesystemName)

{
    return G2FALSE;
}

void STREAM_InitLoader(char *bigFileName, char *voiceFileName)

{
    LoadQueueEntry *voiceList;
    LoadQueueEntry *LocalStrings;
    int the_language;

    //LOAD_InitCdLoader(bigFileName, voiceFileName);
    the_language = 0x26;
    LocalStrings = 0; //&_LoadQueueEntry_800d26a4;
    voiceList = 0;    //&_LoadQueueEntry_800d26e4;
    loadFree = LoadQueue;
    loadHead = (LoadQueueEntry *)0x0;
    loadTail = (LoadQueueEntry *)0x0;
    numLoads = 0;
    do
    {
        LocalStrings->next = voiceList;
        LocalStrings = LocalStrings + -1;
        the_language = the_language + -1;
        voiceList = voiceList + -1;
    } while (-1 < the_language);
    //_LoadQueueEntry_800d26e4.next = (_LoadQueueEntry *)0x0;
    return;
}

/*void StartTimer(void)

{
    EnterCriticalSection();
    __timerEvent = OpenEvent();
    EnableEvent();
    SetRCnt(0xf2000000, 0xffff, (uint)&DAT_00001001);
    StartRCnt(0xf2000000);
    ExitCriticalSection();
    gTimerEnabled = 1;
    return;
}*/

void localstr_set_language(language_t lang)

{
    LocalizationHeader *voiceList;
    LocalizationHeader *LocalStrings;
    int the_language;

    //voiceList = (LocalizationHeader *)LOAD_ReadFileFromCD("\\LOCALS.TBL;1", 6);
    //LocalStrings = voiceList + 1;
    LocalizationTable = voiceList;
    if (voiceList != (LocalizationHeader *)0x0)
    {
        //voiceList = (XAVoiceListEntry *)((int)&voiceList->language + voiceList->XATableOffset);
        the_language = 0;
        LocalizationTable = voiceList;
        //LocalStrings = (char **)voiceList;
        /*if (0 < voiceList->numStrings)
        {
            do
            {
                the_language = the_language + 1;
                //LocalStrings->language = (int)&voiceList->language + LocalStrings->language;
                //LocalStrings = (LocalizationHeader *)&LocalStrings->numXAfiles;
            } while (the_language < voiceList->numStrings);
        }*/
        //the_language = LocalizationTable->language;
    }
    return;
}

void INSTANCE_InitInstanceList(struct _InstanceList *list, struct _InstancePool *pool)

{
    int iVar1;
    int iVar2;
    long *plVar3;
    int iVar4;
    int iVar5;
    int iVar6;

    pool->numFreeInstances = 0x3e;
    iVar4 = 1;
    iVar6 = 8;
    iVar5 = 0x4d8;
    plVar3 = &pool->instance[0].light_color;
    do
    {
        iVar2 = (int)&pool->nextInstanceID + iVar6;
        iVar6 = iVar6 + 0x268;
        iVar1 = (int)&pool->nextInstanceID + iVar5;
        iVar5 = iVar5 + 0x268;
        plVar3[4] = iVar1;
        plVar3[5] = iVar2;
        iVar4 = iVar4 + 1;
        plVar3 = plVar3 + 0x9a;
    } while (iVar4 < 0x3d);
    iVar4 = 0;
    pool->instance[0].next = pool->instance + 1;
    pool->instance[0].prev = (Instance *)0x0;
    //pool->instance[0x3d].prev = (_Instance *)(&DAT_00009068 + (int)pool);
    pool->instance[0x3d].next = (Instance *)0x0;
    pool->first_free = pool->instance;
    list->pool = pool;
    list->numInstances = 0;
    list->first = (Instance *)0x0;
    do
    {
        list->group[0].next = (NodeType *)0x0;
        list->group[0].prev = (NodeType *)0x0;
        iVar4 = iVar4 + 1;
        list = (InstanceList *)&list->pool;
    } while (iVar4 < 0x20);
    pool->nextInstanceID = 1;
    return;
}

void GAMELOOP_InitGameTracker(void)

{
    int iVar1;
    int iVar2;

    //gameTrackerX.GlobalObjects = GlobalObjects;
    //gameTrackerX.planningPool = planningPool;
    //gameTrackerX.enemyPlanPool = enemyPlanPool;
    //gameTrackerX.vertexPool = gVertexPool;
    //primPool2->lastPrim = primPool2->prim + 0x5db4;
    gameTrackerX.instanceList = instanceList;
    //PTR_800d0c18->lastPrim = PTR_800d0c18->prim + 0x5db4;
    //gameTrackerX.lightInfo = gLightInfo;
    //primPool2->nextPrim = primPool2->prim;
    gameTrackerX.instancePool = instancePool;
    //PTR_800d0c18->nextPrim = PTR_800d0c18->prim;
    iVar2 = 0;
    iVar1 = 0;
    gameTrackerX.multGameTime = 10;
    gameTrackerX.material_fadeValue = 0x1000;
    gameTrackerX.spectral_fadeValue = 0;
    gameTrackerX.decoupleGame = 1;
    gameTrackerX.frameRateLock = 1;
    //gameTrackerX.primPool = primPool2;
    //gameTrackerX.drawOT = gOt2;
    //gameTrackerX.dispOT = PTR_800d0c10;
    gameTrackerX.frameRate24fps = 1;
    do
    {
        iVar2 = iVar2 + 1;
        //*(undefined2 *)((int)&(gameTrackerX.GlobalObjects)->objectStatus + iVar1) = 0;
        iVar1 = iVar1 + 0x24;
    } while (iVar2 < 0x30);
    gameTrackerX.gameData.asmData.MorphTime = 1000;
    //OBTABLE_ClearObjectReferences();
    //EVENT_Init();
    return;
}

void GAMELOOP_SystemInit(GameTracker *gameTracker)

{
    //GAMELOOP_AllocStaticMemory();
    INSTANCE_InitInstanceList(instanceList, instancePool);
    GAMELOOP_InitGameTracker();
    return;
}

void InitMainTracker(MainTracker *mainTracker)

{
    mainTracker->mainState = 0;
    mainTracker->previousState = 0;
    mainTracker->done = 0;
    return;
}

void PSX_GameLoop(GameTracker *gameTracker)

{
    //GAMEPAD_Process(gameTracker);
    //GAMELOOP_Process(gameTracker);
    return;
}

unsigned int GetRCnt(unsigned int param_1)

{
    unsigned int uVar1;

    if ((param_1 & 0xffff) < 3)
    {
        uVar1 = (unsigned int)*(unsigned short *)("TMR_DOTCLOCK_VAL" + (param_1 & 0xffff) * 0x10); //TMR_DOTCLOCK_VAL?
    }
    else
    {
        uVar1 = 0;
    }
    return uVar1;
}

void STREAM_LoadObjectReturn(void *loadData, void *data, void *data2)

{
    int uVar1;
    long lVar2;
    int iVar3;
    char acStack80[64];

    GetRCnt(0xf2000000);
    if (loadData == (void *)0x0)
    {
        //STREAM_DumpObject((_ObjectTracker *)data);
    }
    else
    {
        if ((((*(unsigned int *)loadData & 0x8000000) != 0) && (*(int **)((int)loadData + 0x3c) != (int *)0x0)) && (*(int *)((int)loadData + 0x40) != 0))
        {
            //RELMOD_InitModulePointers(*(int *)((int)loadData + 0x40), *(int **)((int)loadData + 0x3c));
        }
        //STREAM_PackVRAMObject((_ObjectTracker *)data);
        //OBTABLE_InitAnimPointers((_ObjectTracker *)data);
        //OBTABLE_InitObjectWithID((Object *)loadData);
        if ((*(unsigned int *)((int)loadData + 0x2c) & 0x800000) != 0)
        {
            sprintf(acStack80, "\\kain2\\sfx\\object\\%s\\%s.snf");
            *(int *)((int)loadData + 6) = 0;
            //lVar2 = LOAD_DoesFileExist(acStack80);
            if (lVar2 != 0)
            {
                //iVar3 = aadLoadDynamicSfx((char *)data, 0, 0);
                *(int *)((int)loadData + 6) = (short)iVar3;
            }
        }
        uVar1 = 4;
        if (*(int *)((int)data + 0x18) == 0)
        {
            uVar1 = 2;
        }
        *(int *)((int)data + 0x14) = uVar1;
    }
    return;
}

int mytolower(int c)

{
    if (c - 0x41U < 0x1a)
    {
        c = c + 0x20;
    }
    return c;
}

int strcmpi(char *s1, char *s2)

{
    unsigned char bVar1;
    int iVar2;
    int iVar3;

    do
    {
        bVar1 = *s1;
        s1 = (char *)((unsigned char *)s1 + 1);
        iVar2 = mytolower((unsigned int)bVar1);
        bVar1 = *s2;
        s2 = (char *)((unsigned char *)s2 + 1);
        iVar3 = mytolower((unsigned int)bVar1);
        if (iVar2 != iVar3)
        {
            return iVar2 - iVar3;
        }
    } while (iVar2 != 0);
    return 0;
}

int InsertGlobalObject(char *name, GameTracker *gameTracker)

{
    int iVar1;
    int iVar2;
    ObjectTracker *retData;
    char acStack152[64];
    char acStack88[64];

    /*if (((gameTrackerX.gameFlags & 0x4000000U) != 0) &&
        (iVar1 = STREAM_IsSpecialMonster(name), iVar1 != 0))
    {
        return -1;
    }
    if (((gameTracker->debugFlags2 & 0x8000U) != 0) && (iVar1 = STREAM_IsMonster(name), iVar1 != 0))
    {
        return -1;
    }*/
    retData = gameTracker->GlobalObjects;
    iVar1 = 0;
    do
    {
        if ((retData->objectStatus != 0) && (iVar2 = strcmpi((char *)retData, name), iVar2 == 0))
            break;
        iVar1 = iVar1 + 1;
        retData = retData + 1;
    } while (iVar1 < 0x30);
    if (iVar1 == 0x30)
    {
        retData = gameTracker->GlobalObjects;
        iVar1 = 0;
        do
        {
            if (retData->objectStatus == 0)
                break;
            iVar1 = iVar1 + 1;
            retData = retData + 1;
        } while (iVar1 < 0x30);
        /*if ((iVar1 == 0x30) && (iVar1 = STREAM_TryAndDumpANonResidentObject(), iVar1 == -1))
        {
            DEBUG_FatalError(s_The_Object_tracker_is_full_MAX_O_800cf44c);
        }*/
        sprintf(acStack152, "\\kain2\\object\\%s\\%s.drm");
        sprintf(acStack88, "\\kain2\\object\\%s\\%s.crm");
        strcpy((char *)retData, name);
        retData->objectStatus = 1;
        //LOAD_NonBlockingBinaryLoad(acStack152, STREAM_LoadObjectReturn, retData, (void *)0x0, &retData->object, 1);
        retData->numInUse = 0;
        retData->numObjectsUsing = '\0';
    }
    return iVar1;
}

ObjectTracker *STREAM_GetObjectTracker(char *name)

{
    int iVar1;
    ObjectTracker *p_Var2;

    iVar1 = InsertGlobalObject(name, &gameTrackerX);
    if (iVar1 == -1)
    {
        p_Var2 = (ObjectTracker *)0x0;
    }
    else
    {
        p_Var2 = gameTrackerX.GlobalObjects + iVar1;
    }
    return p_Var2;
}

int CINE_Load(void)

{
    bool bVar1;

    the_cine_table = 0;
    the_cine_tracker = STREAM_GetObjectTracker("cinemax");
    do
    {
        //bVar1 = the_cine_table < 400;
        if (the_cine_tracker->objectStatus == 2)
            break;
        //the_cine_table = the_cine_table + 1;
        //STREAM_PollLoadQueue();
        //VSync(0);
        //bVar1 = the_cine_table < 400;
    } while (bVar1);
    if (!bVar1)
    {
        //sprintf("timeout");
    }
    else
    {
        the_cine_table = (cinema_fn_table_t *)the_cine_tracker->object->relocModule;
        the_cine_tracker = the_cine_tracker;
    }
    return (unsigned int)bVar1;
}

void CINE_Play(char *strfile, unsigned short mask, int buffers)

{
    char monVersion[12];
    if (the_cine_table != (cinema_fn_table_t *)0x0)
    {
        /*if (the_cine_table->versionID == monVersion)
        {
            //(*the_cine_table->play)(strfile, (unsigned int)mask);
            //LOAD_InitCdStreamMode();
        }
        else
        {
            printf("CINEMA_: _Version_number_is_wrong");
        }*/
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
        //ClearDisplay();
        //CINE_Unload();
    }
    return;
}

void MainG2_ShutDownEngine(void *appData)

{
    return;
}

int MainG2(void *appData)

{
    bool bVar1;
    long lVar2;
    G2Bool Var3;
    int iVar4;
    long menuPos;

    menuPos = 0;
    //CheckForDevStation();
    //mainOptionsInit = '\0';
    Var3 = MainG2_InitEngine(appData, 0x200, 0xf0, (char *)0x0);
    if (Var3 != G2FALSE)
    {
        //MEMPACK_Init();
        //LOAD_InitCd();
        //StartTimer();
        STREAM_InitLoader("\\BIGFILE.DAT;1", "\\VOICE");
        localstr_set_language(language_english);
        GAMELOOP_SystemInit(&gameTrackerX);
        gameTrackerX.lastLvl = -1;
        gameTrackerX.currentLvl = -1;
        //gameTrackerX.disp = &disp;
        //ProcessArgs(gameTrackerX.baseAreaName, &gameTrackerX);
        InitMainTracker(&mainTrackerX);
        //MAIN_DoMainInit();
        mainTrackerX.mainState = 6;
        mainTrackerX.movieNum = 0;
        do
        {
            mainTrackerX.previousState = mainTrackerX.mainState;
            if (true)
            {
                switch (mainTrackerX.mainState)
                {
                /*case 1:
                    //SOUND_UpdateSound();
                    if ((gameTrackerX.debugFlags & 0x80000U) != 0)
                    {
                        //VOICEXA_Tick();
                    }
                    PSX_GameLoop(&gameTrackerX);
                    if (gameTrackerX.levelDone != 0)
                    {
                        FadeOutSayingLoading(&gameTrackerX);
                        aadStopAllSfx();
                        STREAM_DumpAllLevels(0, 0);
                        RemoveAllObjects(&gameTrackerX);
                        while ((iVar4 = aadGetNumLoadsQueued(), iVar4 != 0 || ((aadMem->sramDefragInfo).status != 0)))
                        {
                            SOUND_UpdateSound();
                            STREAM_PollLoadQueue();
                        }
                        SOUND_ShutdownMusic();
                        MEMPACK_FreeByType('\x0e');
                        GAMELOOP_ResetGameStates();
                        MEMPACK_DoGarbageCollection();
                        iVar4 = (int)gameTrackerX.levelDone;
                        if (iVar4 == 2)
                        {
                        LAB_8003933c:
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
                                if (iVar4 == 4)
                                {
                                    mainTrackerX.mainState = 2;
                                    if ((gameTrackerX.streamFlags & 0x200000U) == 0)
                                    {
                                        SAVE_ClearMemory(&gameTrackerX);
                                    }
                                }
                                else
                                {
                                    mainTrackerX.mainState = 2;
                                }
                            }
                        }
                    }
                    break;*/
                case 2:
                    if ((gameTrackerX.streamFlags & 0x1000000U) != 0)
                    {
                        play_movie((char *)"\\KAININT.STR;1");
                        gameTrackerX.streamFlags = gameTrackerX.streamFlags & 0xfeffffff;
                    }
                    if ((gameTrackerX.streamFlags & 0x200000U) != 0)
                    {
                        gameTrackerX.streamFlags = gameTrackerX.streamFlags & 0xffdfffff;
                    }
                    int nosound = 1; //Stub
                    if (nosound == 0)
                    {
                        //MAIN_InitVolume();
                    }
                    /*MAIN_ShowLoadingScreen();
                    FONT_ReloadFont();
                    DrawSync(0);
                    gameTrackerX.frameCount = 0;
                    STREAM_Init();
                    GAMELOOP_LevelLoadAndInit(gameTrackerX.baseAreaName, &gameTrackerX);
                    gameTrackerX.levelDone = 0;
                    mainTrackerX.mainState = 1;
                    do
                    {
                        iVar4 = STREAM_PollLoadQueue();
                    } while (iVar4 != 0);
                    gameTrackerX.vblFrames = 0;
                    break;*/
                    /*case 4:
                    LOAD_ChangeDirectory("Menustuff");
                    do
                    {
                        lVar2 = mainTrackerX.movieNum;
                        if (5 < (unsigned int)mainTrackerX.movieNum)
                        {
                            FONT_ReloadFont();
                        }
                        gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xfffffffe;
                        show_screen((char *)(InterfaceItems + mainTrackerX.movieNum));
                        iVar4 = 1;
                        if (InterfaceItems[lVar2].timeout != 0)
                        {
                            do
                            {
                                GAMEPAD_Process(&gameTrackerX);
                                if (((int)(unsigned int)InterfaceItems[lVar2].buttonTimeout < iVar4) &&
                                    ((gameTrackerX.controlCommand[0][1] & 0x80U) != 0))
                                    break;
                                VSync(0);
                                bVar1 = iVar4 < (int)(unsigned int)InterfaceItems[lVar2].timeout;
                                iVar4 = iVar4 + 1;
                            } while (bVar1);
                        }
                        mainTrackerX.movieNum = (long)InterfaceItems[lVar2].nextItem;
                    } while ((mainTrackerX.movieNum < 0) ||
                             (InterfaceItems[mainTrackerX.movieNum].itemType == 1));
                    mainTrackerX.mainState = 6;
                LAB_800390f0:
                    FONT_ReloadFont();
                    if (mainTrackerX.mainState != 6)
                    {
                        if (DoMainMenu != 0)
                            goto LAB_8003933c;
                        MAIN_ResetGame();
                        gameTrackerX.gameMode = 0;
                        mainMenuFading = 1;
                        MAIN_StartGame();
                    }
                    break;
                case 6:
                    CINE_Load();
                    do
                    {
                        if (mainTrackerX.movieNum < 0)
                            goto LAB_80038fd0;
                        iVar4 = CINE_Loaded();
                        if (iVar4 != 0)
                        {
                            CINE_Play((char *)(InterfaceItems + mainTrackerX.movieNum), 0xffff, 2);
                            ClearDisplay();
                        }
                        mainTrackerX.movieNum = (long)InterfaceItems[mainTrackerX.movieNum].nextItem;
                    } while (InterfaceItems[mainTrackerX.movieNum].itemType == 0);
                    mainTrackerX.mainState = 4;
                LAB_80038fd0:
                    CINE_Unload();
                    if (mainTrackerX.movieNum < 0)
                    {
                        mainTrackerX.mainState = 8;
                    }
                    if (nosound == 0)
                    {
                        SOUND_StopAllSound();
                    }
                    break;
                case 7:
                    mainTrackerX.done = 1;
                    break;
                case 8:
                    gameTrackerX.gameData.asmData.MorphType = 0;
                    ProcessArgs(gameTrackerX.baseAreaName, &gameTrackerX);
                    MAIN_ResetGame();
                    LOAD_ChangeDirectory("Menustuff");
                    MAIN_MainMenuInit();
                    MAIN_InitVolume();
                    SAVE_ClearMemory(&gameTrackerX);
                    mainTrackerX.mainState = 9;
                    FONT_ReloadFont();
                    break;
                case 9:
                    menuPos = MAIN_DoMainMenu(&gameTrackerX, &mainTrackerX, menuPos);
                    */
                }
            }
            //STREAM_PollLoadQueue();
        } while (mainTrackerX.done == 0);
        /*SOUND_StopAllSound();
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
        ResetGraph(3);*/
    }
    MainG2_ShutDownEngine(appData);
    return 0;
}

int main(void)

{
    int iVar1;

    __main();
    ClearBss();
    iVar1 = MainG2(&appDataVM);
    return iVar1;
}
