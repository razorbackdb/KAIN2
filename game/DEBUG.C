*#include "THISDUST.H"
#include "DEBUG.H"

    void
    DEBUG_SetGameTime(long *var)

{
    GAMELOOP_SetGameTime(*var);
    return;
}

void DEBUG_KeepGameTime(long *var)

{
    int local_10[2];

    local_10[0] = (int)gameTrackerX.timeOfDay;
    DEBUG_SetGameTime(local_10);
    return;
}

void DEBUG_UpdateFog(long *var)

{
    u_short uVar1;
    Level *pLVar2;
    _StreamUnit *p_Var3;
    u_int uVar4;

    p_Var3 = FindStreamUnitFromLevel(gameTrackerX.level);
    pLVar2 = gameTrackerX.level;
    uVar1 = (u_short)debugFogFar;
    (gameTrackerX.level)->fogFar = (u_short)debugFogFar;
    p_Var3->TargetFogFar = uVar1;
    pLVar2->holdFogFar = uVar1;
    pLVar2 = gameTrackerX.level;
    uVar1 = (u_short)debugFogNear;
    (gameTrackerX.level)->fogNear = (u_short)debugFogNear;
    p_Var3->TargetFogNear = uVar1;
    pLVar2->holdFogNear = uVar1;
    pLVar2 = gameTrackerX.level;
    uVar4 = debugFogBlu << 0x10 | debugFogGrn << 8 | debugFogRed;
    p_Var3->FogColor = uVar4;
    *(u_int *)&pLVar2->backColorR = uVar4;
    LIGHT_CalcDQPTable(gameTrackerX.level);
    return;
}

void DEBUG_UpdateHealth(long *var)

{
    RAZIEL_DebugHealthFillUp(1);
    return;
}

void DEBUG_FillUpHealth(long *var)

{
    RAZIEL_DebugManaSetMax();
    RAZIEL_DebugHealthSetScale();
    return;
}

void DEBUG_FogLoad(void)

{
    _StreamUnit *p_Var1;

    p_Var1 = FindStreamUnitFromLevel(gameTrackerX.level);
    debugOrgFogBlu = *(byte *)((int)&p_Var1->FogColor + 2);
    debugOrgFogGrn = *(byte *)((int)&p_Var1->FogColor + 1);
    debugFogFar = (int)p_Var1->TargetFogFar;
    debugFogNear = (int)p_Var1->TargetFogNear;
    debugFogRed = (u_int) * (byte *)&p_Var1->FogColor;
    debugFogGrn = (u_int)debugOrgFogGrn;
    debugFogBlu = (u_int)debugOrgFogBlu;
    debugOrgFogNear = p_Var1->TargetFogNear;
    debugOrgFogRed = *(byte *)&p_Var1->FogColor;
    debugOrgFogFar = p_Var1->TargetFogFar;
    return;
}

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

void DEBUG_SendCinematicSwitch(void)

{
    gameTrackerX.debugFlags2 = gameTrackerX.debugFlags2 ^ 0x200;
    INSTANCE_Broadcast((_Instance *)0x0, 0xe, 0x4000e, (u_int)((gameTrackerX.debugFlags2 & 0x200U) != 0));
    return;
}

void DEBUG_SendMoveTo(void)

{
    short sVar1;
    u_int uVar2;
    u_int uVar3;
    int Data;

    uVar2 = rand();
    sVar1 = ((gameTrackerX.playerInstance)->position).x;
    uVar3 = rand();
    Data = SetPositionData((int)sVar1 + (uVar2 & 0x7ff) + -0x400,
                           (int)((gameTrackerX.playerInstance)->position).y + (uVar3 & 0x7ff) + -0x400, (int)((gameTrackerX.playerInstance)->position).z);
    INSTANCE_Broadcast((_Instance *)0x0, 0xe, 0x4000c, Data);
    return;
}

void process_cheat_codes(GameTracker *gt, long *ctrl)

{
    if ((cheatCodeLastCommand == 0) && (ctrl[1] != 0))
    {
        if (((ctrl[1] & (&cheatCombo)[cheatCodeStage]) == 0) ||
            (cheatCodeStage = cheatCodeStage + 1, (*ctrl & 0x300U) == 0))
        {
            cheatCodeStage = 0;
        }
        if (cheatCodeStage == 4)
        {
            cheatCodeStage = 0;
            gt->debugFlags = gt->debugFlags ^ 0x40000;
        }
    }
    cheatCodeLastCommand = ctrl[1];
    return;
}

void DEBUG_ProcessSecondController(GameTracker *gameTracker)

{
    short sVar1;
    u_int uVar2;
    u_int uVar3;

    uVar3 = gameTracker->debugFlags;
    sVar1 = gameTracker->gameMode;
    uVar2 = gameTracker->debugFlags2;
    if (sVar1 == 0)
    {
        if ((uVar3 & 8) != 0)
        {
            DEBUG_ProcessSecondController(gameTracker);
        }
        if (gameTracker->cheatMode == '\x01')
        {
            DEBUG_ProcessCheat(gameTracker);
        }
        goto LAB_80013230;
    }
    if (sVar1 != 4)
    {
        if (sVar1 == 6)
        {
            process_cheat_codes(gameTracker, gameTracker->controlCommand);
            DEBUG_MenuCountLength(gameTracker);
        }
        else
        {
            if (sVar1 == 7)
            {
                DEBUG_EndViewVram(gameTracker);
            }
        }
        goto LAB_80013230;
    }
    DEBUG_MenuCountLength(gameTracker);
    if ((gameTracker->debugFlags2 & 0x40000U) == 0)
    {
    LAB_80013188:
        if ((uVar2 & 0x40000) != 0)
        {
            gameTracker->debugFlags = gameTracker->debugFlags & 0xfffffff7;
        }
    }
    else
    {
        if ((uVar2 & 0x40000) == 0)
        {
            gameTracker->debugFlags = gameTracker->debugFlags | 8;
        }
        if ((gameTracker->debugFlags2 & 0x40000U) == 0)
            goto LAB_80013188;
    }
    if (((gameTracker->debugFlags & 8U) != 0) && ((uVar3 & 8) == 0))
    {
        theCamera.core.debugPos.x = theCamera.core.position.x;
        theCamera.core.debugPos.y = theCamera.core.position.y;
        theCamera.core.debugPos.z = theCamera.core.position.z;
        theCamera.core.debugRot.x = theCamera.core.rotation.x;
        theCamera.core.debugRot.y = theCamera.core.rotation.y;
        theCamera.core.debugRot.z = theCamera.core.rotation.z;
    }
LAB_80013230:
    if (((gameTracker->debugFlags & 0x4000U) != 0) && ((gameTracker->controlCommand[1] & 0x400U) != 0))
    {
        DEBUG_CaptureScreen(gameTracker);
    }
    return;
}

void DEBUG_Draw(GameTracker *gameTracker, u_long **ot)

{
    if (((gameTracker->gameMode == 0) || (gameTracker->cheatMode == '\x01')) ||
        (gameTracker->gameMode == 4))
    {
        DEBUG_DisplayStatus(gameTracker);
    }
    return;
}

long DEBUG_Menu(DebugMenuLine *menu)

{
    DEBUG_LINE_TYPE *pDVar1;
    int iVar2;

    iVar2 = 0;
    if (menu != (DebugMenuLine *)0x0)
    {
        do
        {
            pDVar1 = &menu->type;
            menu = menu + 1;
            if (*pDVar1 == DEBUG_LINE_TYPE_ENDLIST)
            {
                return iVar2;
            }
            iVar2 = iVar2 + 1;
        } while (menu != (DebugMenuLine *)0x0);
    }
    return iVar2;
}

void DEBUG_ExitMenus(void)

{
    long lVar1;

    lVar1 = DEBUG_Menu(currentMenu);
    currentMenu[lVar1].lower = debugMenuChoice;
    if (gameTrackerX.sound.gMusicOn == '\0')
    {
        SOUND_MusicOff();
        SOUND_FreeDynamicMusic();
    }
    else
    {
        SOUND_MusicOn();
    }
    if (gameTrackerX.sound.gSfxOn == '\0')
    {
        SOUND_SfxOff();
    }
    else
    {
        SOUND_SfxOn();
    }
    return;
}

DebugMenuLine *get_last_menu_line(DebugMenuLine *line)

{
    DebugMenuLine *pDVar1;

    if (line->type != DEBUG_LINE_TYPE_ENDLIST)
    {
        pDVar1 = line + 1;
        do
        {
            line = pDVar1;
            pDVar1 = line + 1;
        } while (line->type != DEBUG_LINE_TYPE_ENDLIST);
    }
    return line;
}

int menu_item(DebugMenuLine *menu)

{
    DEBUG_LINE_TYPE DVar1;
    int iVar2;

    DVar1 = menu->type;
    iVar2 = 0;
    while (DVar1 != DEBUG_LINE_TYPE_ENDLIST)
    {
        menu = menu + 1;
        DVar1 = menu->type;
        iVar2 = iVar2 + 1;
    }
    return iVar2;
}

void maybe_change_menu_choice(GameTracker *gt, DebugMenuLine *menu)

{
    int iVar1;
    u_int uVar2;
    int iVar3;

    iVar3 = debugMenuChoice;
    iVar1 = menu_item(menu);
    if ((gt->controlCommand[1] & 1U) == 0)
    {
        uVar2 = (u_int)gt->controlCommand[1] >> 1 & 1;
    }
    else
    {
        uVar2 = 0xffffffff;
    }
    if ((uVar2 != 0) && (-1 < iVar3))
    {
        do
        {
            iVar3 = (int)(iVar3 + iVar1 + uVar2) % iVar1;
            if (iVar3 == debugMenuChoice)
            {
                return;
            }
        } while (DEBUG_LINE_TYPE_ENDLIST < menu[iVar3].type);
        if (iVar3 != debugMenuChoice)
        {
            SndPlay(5);
            debugMenuChoice = iVar3;
        }
    }
    return;
}

void handle_line_type_action(GameTracker *gt, DebugMenuLine *line)

{
    u_int uVar1;
    int *piVar2;
    int iVar3;

    if ((gt->controlCommand[1] & 0xcU) != 0)
    {
        uVar1 = gt->controlCommand[0];
        iVar3 = 10;
        if ((((uVar1 & 0x400) == 0) && (iVar3 = 100, (uVar1 & 0x800) == 0)) &&
            (iVar3 = 1, (uVar1 & 0x200) != 0))
        {
            iVar3 = 1000;
        }
        if ((gt->controlCommand[1] & 4U) != 0)
        {
            iVar3 = -iVar3;
        }
        *line->var_address = *line->var_address + iVar3;
        piVar2 = line->var_address;
        if (*piVar2 < line->lower)
        {
            *piVar2 = line->lower;
            piVar2 = line->var_address;
        }
        if (line->upper < *piVar2)
        {
            *piVar2 = line->upper;
        }
        if ((code *)line->bit_mask != (code *)0x0)
        {
            (*(code *)line->bit_mask)(line->var_address);
        }
    }
    return;
}

void handle_line_type_bit(GameTracker *gt, DebugMenuLine *line)

{
    if ((gt->controlCommand[1] & 4U) != 0)
    {
        *line->var_address = *line->var_address | line->bit_mask;
        return;
    }
    if ((gt->controlCommand[1] & 8U) != 0)
    {
        *line->var_address = *line->var_address & ~line->bit_mask;
    }
    return;
}

void handle_line_type_long(GameTracker *gt, DebugMenuLine *line)

{
    if ((gt->controlCommand[1] & 0x80U) != 0)
    {
        (*(code *)line->var_address)();
    }
    return;
}

void handle_line_type_action_with_line(GameTracker *gt, DebugMenuLine *line)

{
    u_int uVar1;
    int iVar2;

    uVar1 = gt->controlCommand[1];
    iVar2 = 2;
    if ((((uVar1 & 0x80) == 0) && (iVar2 = 3, (uVar1 & 4) == 0)) && (iVar2 = 1, (uVar1 & 8) != 0))
    {
        iVar2 = 4;
    }
    if (iVar2 != 1)
    {
        (*(code *)line->var_address)();
    }
    return;
}

void handle_line_type_menu(GameTracker *gt, DebugMenuLine *line)

{
    DebugMenuLine *pDVar1;

    if ((gt->controlCommand[1] & 0x80U) != 0)
    {
        if ((code *)line->bit_mask != (code *)0x0)
        {
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

void menu_process(GameTracker *gt, DebugMenuLine *menu)

{
    if ((menu[debugMenuChoice].type < DEBUG_LINE_TYPE_ENDLIST) &&
        ((&debug_dispatch_table)[menu[debugMenuChoice].type].fn != (_func_16 *)0x0))
    {
        (*(&debug_dispatch_table)[menu[debugMenuChoice].type].fn)();
    }
    return;
}

int pre_process_functions(GameTracker *gt, DebugMenuLine *menu)

{
    _Instance *p_Var1;

    p_Var1 = gt->playerInstance;
    if (p_Var1 != (_Instance *)0x0)
    {
        p_Var1->flags = p_Var1->flags | 0x100;
    }
    return 0;
}

void post_process_functions(GameTracker *gt, DebugMenuLine *menu)

{
    if (menu == &debugSoundMenu)
    {
        SOUND_SetSfxVolume(-1);
        SOUND_SetInstanceSoundVolume(-1);
        SpuSetVoiceVolume(-1);
        if ((gt->debugFlags & 0x80000U) == 0)
        {
            (gt->sound).gVoiceOn = '\0';
        }
        else
        {
            (gt->sound).gVoiceOn = '\x01';
        }
        if ((gt->debugFlags2 & 0x1000U) == 0)
        {
            (gt->sound).gMusicOn = '\0';
        }
        else
        {
            (gt->sound).gMusicOn = '\x01';
        }
        if ((gt->debugFlags2 & 0x2000U) == 0)
        {
            (gt->sound).gSfxOn = '\0';
        }
        else
        {
            (gt->sound).gSfxOn = '\x01';
        }
    }
    return;
}

void set_debug_leading(void)

{
    cem_line_leading = 10;
    cem_item_leading = 0xc;
    return;
}

void set_user_leading(void)

{
    cem_line_leading = 0xc;
    cem_item_leading = 0x10;
    return;
}

int isdigit(char c)

{
    return (u_int)((byte)(c - 0x30U) < 10);
}

void adjust_format(char *ctrl, debug_format_t *fmt)

{
    byte bVar1;
    int iVar2;
    int iVar3;
    byte *pbVar4;
    int iVar5;

    bVar1 = *ctrl;
    do
    {
        if (bVar1 == 0)
        {
            return;
        }
        iVar2 = strncpy(ctrl, "-abs ", 5);
        if ((iVar2 == 0) || (iVar2 = strncpy(ctrl, "-rel ", 5), iVar2 == 0))
        {
            pbVar4 = (byte *)ctrl + 5;
            iVar2 = 0;
            iVar5 = 0;
            while (iVar3 = isdigit(*pbVar4), iVar3 != 0)
            {
                bVar1 = *pbVar4;
                pbVar4 = pbVar4 + 1;
                iVar2 = iVar2 * 10 + (u_int)bVar1 + -0x30;
            }
            if (*pbVar4 != 0)
            {
                pbVar4 = pbVar4 + 1;
            }
            while (iVar3 = isdigit(*pbVar4), iVar3 != 0)
            {
                bVar1 = *pbVar4;
                pbVar4 = pbVar4 + 1;
                iVar5 = iVar5 * 10 + (u_int)bVar1 + -0x30;
            }
            if (*pbVar4 != 0)
            {
                pbVar4 = pbVar4 + 1;
            }
            iVar3 = strncpy(ctrl, "-abs ", 5);
            if (iVar3 == 0)
            {
                fmt->xpos = iVar2;
                fmt->ypos = iVar5;
            }
            else
            {
                fmt->xpos = fmt->xpos + iVar2;
                fmt->ypos = fmt->ypos + iVar5;
            }
        }
        else
        {
            iVar2 = strncpy(ctrl, "-center", 7);
            if (iVar2 != 0)
            {
                printf("unknown format control: %s\n");
                return;
            }
            fmt->is_centered = 1;
            pbVar4 = (byte *)ctrl + 7;
        }
        bVar1 = *pbVar4;
        ctrl = (char *)pbVar4;
    } while (true);
}

char *find_eol(char *text)

{
    char cVar1;

    cVar1 = *text;
    while ((cVar1 != '\0' && (cVar1 != '\n')))
    {
        text = text + 1;
        cVar1 = *text;
    }
    return text;
}

void draw_menu_item(GameTracker *gt, debug_format_t *fmt, char *text)

{
    char cVar1;
    char *pcVar2;
    int iVar3;
    short x;
    short y;

    while (true)
    {
        pcVar2 = find_eol(text);
        cVar1 = *pcVar2;
        *pcVar2 = '\0';
        if (fmt->is_centered == 0)
        {
            x = *(short *)&fmt->xpos;
            y = *(short *)&fmt->ypos;
        }
        else
        {
            iVar3 = FONT_GetStringWidth(text);
            y = *(short *)&fmt->ypos;
            x = (short)(((u_int) * (u_short *)&fmt->xpos - (iVar3 >> 1)) * 0x10000 >> 0x10);
        }
        FONT_SetCursor(x, y);
        if (currentMenu->type == DEBUG_LINE_TYPE_FORMAT)
        {
            FONT_Print2(text);
        }
        else
        {
            FONT_Print(text);
        }
        text = pcVar2 + 1;
        if (cVar1 == '\0')
            break;
        *pcVar2 = cVar1;
        fmt->ypos = fmt->ypos + cem_line_leading;
    }
    fmt->ypos = fmt->ypos + cem_item_leading;
    return;
}

void draw_menu(GameTracker *gt, DebugMenuLine *menu)

{
    short sVar1;
    int iVar2;
    int iVar3;
    short y;
    int iVar4;
    debug_format_t local_38;
    int local_28;
    int local_24;
    u_char local_20;

    local_20 = 0;
    local_28 = 0x28;
    local_24 = 0x14;
    local_38.xpos = 0x28;
    local_38.ypos = 0x14;
    local_38.is_centered = 0;
    if (menu->type == DEBUG_LINE_TYPE_FORMAT)
    {
        menu->text = "-abs 160 40 -center";
        set_user_leading();
        iVar4 = 0;
    }
    else
    {
        set_debug_leading();
        iVar4 = 0;
    }
    while (iVar2 = local_38.xpos, menu->type != DEBUG_LINE_TYPE_ENDLIST)
    {
        if (menu->type == DEBUG_LINE_TYPE_FORMAT)
        {
            adjust_format(menu->text, &local_38);
        }
        else
        {
            y = (short)local_38.ypos;
            if (debugMenuChoice == iVar4)
            {
                sVar1 = (short)local_38.xpos;
                if (local_38.is_centered != 0)
                {
                    sVar1 = sVar1 + -0x78;
                }
                FONT_SetCursor(sVar1 + -0x14, y);
                FONT_Print(">");
            }
            draw_menu_item(gt, &local_38, menu->text);
            if (local_38.is_centered == 0)
            {
                iVar3 = 0xf0;
            }
            else
            {
                iVar3 = 0x78;
            }
            FONT_SetCursor((short)((u_int)((iVar3 + iVar2) * 0x10000) >> 0x10), y);
            if (menu->type == DEBUG_LINE_TYPE_BIT)
            {
                if ((*menu->var_address & menu->bit_mask) == menu->bit_mask)
                {
                    FONT_Print("YES");
                }
                else
                {
                    FONT_Print((char *)&PTR_DAT_800cef10);
                }
            }
            else
            {
                if (menu->type == DEBUG_LINE_TYPE_LONG)
                {
                    FONT_Print((char *)&PTR_DAT_800cef14);
                }
            }
        }
        menu = menu + 1;
        iVar4 = iVar4 + 1;
    }
    return;
}

void DEBUG_MenuCountLength(GameTracker *gt)

{
    DebugMenuLine *menu;
    long lVar1;
    int iVar2;
    DEBUG_LINE_TYPE DVar3;

    lVar1 = debugMenuChoice;
    menu = currentMenu;
    if ((currentMenu == &mainMenu) || (currentMenu == &pauseMenu))
    {
        process_menu_line(gt->menu);
    }
    else
    {
        iVar2 = pre_process_functions(gt, currentMenu);
        if (iVar2 == 0)
        {
            DVar3 = menu[debugMenuChoice].type;
            while (DEBUG_LINE_TYPE_ENDLIST < DVar3)
            {
                debugMenuChoice = debugMenuChoice + 1;
                DVar3 = menu[debugMenuChoice].type;
            }
            draw_menu(gt, menu);
            maybe_change_menu_choice(gt, menu);
            if ((debugMenuChoice == lVar1) && (menu_process(gt, menu), currentMenu == menu))
            {
                post_process_functions(gt, menu);
            }
        }
    }
    return;
}

void DEBUG_DisplayStatus(GameTracker *gameTracker)

{
    int iVar1;
    char *fmt;
    long local_18[2];

    STREAM_GetWaterZLevel(gameTracker->playerInstance->currentStreamUnitID);
    if ((gameTracker->debugFlags & 0x40000000U) != 0)
    {
        EVENT_PrintVars();
    }
    if ((gameTracker->debugFlags & 0x4000004U) != 0)
    {
        if ((gameTracker->debugFlags & 0x4000000U) == 0)
        {
            fmt = "$@KG\n FRTE %d\n";
        }
        else
        {
            fmt = "$@EF\n FRTE %d\n";
        }
        FONT_Print(fmt);
        FONT_Print(" Focus XYZ(%d,%d,%d)\n");
        if ((gameTracker->debugFlags & 4U) != 0)
        {
            if (gameTracker->idleTime == 0)
            {
                FONT_Print(" IDLE ZERO\n");
            }
            else
            {
                FONT_Print(" IDLE %d PCT\n");
            }
            FONT_Print(" DRAW %d\n");
            FONT_Print(" INS  %d");
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
    if ((gameTracker->debugFlags < 0) && (iVar1 = STREAM_IsCdBusy(local_18), iVar1 != 0))
    {
        FONT_Print("Loading From CD: In Queue(%d)\n");
    }
    return;
}

void DEBUG_DrawShrinkCels(u_long **polyAddr)

{
    return;
}

void DEBUG_ContinueGame(void)

{
    gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x40000000;
    return;
}

void DEBUG_ExitGame(void)

{
    SOUND_ResumeAllSound();
    gameTrackerX.gameFlags = gameTrackerX.gameFlags | 1;
    gameTrackerX.levelDone = 2;
    gameTrackerX.levelChange = 1;
    gameTrackerX.gameMode = 0;
    return;
}

void DEBUG_ReloadCurrentLevel(void)

{
    if (gameTrackerX.levelChange == 0)
    {
        if ((gameTrackerX.streamFlags & 0x200000U) != 0)
        {
            SAVE_SaveGame();
        }
        gameTrackerX.gameFlags = gameTrackerX.gameFlags | 1;
        SOUND_StopAllSound();
        gameTrackerX.levelChange = 1;
        gameTrackerX.levelDone = 4;
    }
    gameTrackerX.gameMode = 0;
    return;
}

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
    do
    {
        if (cVar1 == '\0')
        {
        LAB_80014240:
            if ((gameTrackerX.streamFlags & 0x200000U) != 0)
            {
                SAVE_SaveGame();
            }
            GAMELOOP_RequestLevelChange(name, number, &gameTrackerX);
            gameTrackerX.levelDone = 4;
            if (cVar3 != '\0')
            {
                *pcVar2 = cVar3;
            }
            gameTrackerX.gameMode = 0;
            return;
        }
        if (((cVar1 == ' ') || (cVar1 == '\t')) || (cVar1 == '\n'))
        {
            cVar3 = *pcVar2;
            *pcVar2 = '\0';
            goto LAB_80014240;
        }
        pcVar2 = pcVar2 + 1;
        cVar1 = *pcVar2;
    } while (true);
}

void DEBUG_SetViewVram(void)

{
    gameTrackerX.gameMode = 7;
    return;
}

void DEBUG_ViewVram(GameTracker *gameTracker)

{
    SetDefDispEnv((undefined2 *)&disp, 0, 0, 0x200, 0xf0);
    SetDefDispEnv((undefined2 *)&DISPENV_800d1f74, 0, 0x100, 0x200, 0xf0);
    return;
}

void DEBUG_EndViewVram(GameTracker *gameTracker)

{
    if (((gameTracker->controlCommand[1] & 1U) != 0) && (-1 < DAT_800cf10c))
    {
        DAT_800cf10c = DAT_800cf10c + -0x20;
    }
    if (((gameTracker->controlCommand[1] & 2U) != 0) && (DAT_800cf10c < 0x110))
    {
        DAT_800cf10c = DAT_800cf10c + 0x20;
    }
    if (((gameTracker->controlCommand[1] & 4U) != 0) && (-1 < DAT_800cf108))
    {
        DAT_800cf108 = DAT_800cf108 + -0x20;
    }
    if (((gameTracker->controlCommand[1] & 8U) != 0) && (DAT_800cf108 < 0x200))
    {
        DAT_800cf108 = DAT_800cf108 + 0x20;
    }
    SetDefDispEnv((undefined2 *)&disp, (short)DAT_800cf108, (short)DAT_800cf10c, 0x200, 0xf0);
    SetDefDispEnv((undefined2 *)&DISPENV_800d1f74, (short)DAT_800cf108, (short)DAT_800cf10c, 0x200, 0xf0);
    gameTracker->playerInstance->flags = gameTracker->playerInstance->flags | 0x100;
    return;
}

void DEBUG_CaptureScreen(GameTracker *gameTracker)

{
    return;
}

void DEBUG_PageFlip(void)

{
    u_long **ppuVar1;
    int iVar2;
    undefined auStack32[3];
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

    do
    {
        iVar2 = CheckVolatile(gameTrackerX.drawTimerReturn);
    } while (iVar2 != 0);
    do
    {
        iVar2 = CheckVolatile(gameTrackerX.reqDisp);
    } while (iVar2 != 0);
    DrawSync(0);
    DMACallback(0);
    DrawCallback(0);
    ResetPrimPool();
    ppuVar1 = gameTrackerX.drawOT;
    gameTrackerX.drawPage = 0;
    PutDrawEnv((u_char *)&draw);
    ClearOTagR(ppuVar1, 0xc00);
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
    PutDispEnv((u_short *)gameTrackerX.disp);
    return;
}

void DEBUG_FatalError(char *fmt)

{
    undefined local_res4[12];
    char acStack264[256];

    FONT_Flush();
    vsprintf(acStack264, fmt, local_res4);
    FONT_Print(acStack264);
    DEBUG_PageFlip();
    trap(0x407);
    return;
}

void DEBUG_ProcessSecondController(GameTracker *gameTracker)

{
    return;
}

void DEBUG_ProcessCheat(GameTracker *gameTracker)

{
    u_int uVar1;
    int iVar2;
    undefined auStack80[2];
    undefined2 local_4e;
    short local_48[2];
    short local_44;
    MATRIX MStack56;

    uVar1 = gameTracker->controlCommand[0];
    iVar2 = 0;
    if (((uVar1 & 0xa01) != 0xa01) && ((uVar1 & 0xa02) != 0xa02))
    {
        if ((uVar1 & 5) == 5)
        {
            iVar2 = 0xa00;
        }
        else
        {
            if ((uVar1 & 9) == 9)
            {
                iVar2 = 0x600;
            }
            else
            {
                if ((uVar1 & 6) == 6)
                {
                    iVar2 = 0xe00;
                }
                else
                {
                    if ((uVar1 & 10) == 10)
                    {
                        iVar2 = 0x200;
                    }
                    else
                    {
                        if ((uVar1 & 2) == 0)
                        {
                            if ((uVar1 & 4) == 0)
                            {
                                if ((uVar1 & 8) == 0)
                                {
                                    if ((uVar1 & 1) != 0)
                                    {
                                        iVar2 = 0x800;
                                    }
                                }
                                else
                                {
                                    iVar2 = 0x400;
                                }
                            }
                            else
                            {
                                iVar2 = 0xc00;
                            }
                        }
                        else
                        {
                            iVar2 = 0x1000;
                        }
                    }
                }
            }
        }
    }
    if (iVar2 != 0)
    {
        memset(auStack80, 0, 8);
        memset(local_48, 0, 0x10);
        local_4e = 0xff00;
        MATH3D_SetUnityMatrix(&MStack56);
        RotMatrixX(theCamera.core.rotation.z + iVar2, (u_int *)&MStack56);
        ApplyMatrixSV(&MStack56, auStack80, local_48);
        (gameTracker->playerInstance->position).x =
            (gameTracker->playerInstance->position).x + local_48[0];
        (gameTracker->playerInstance->position).y = (gameTracker->playerInstance->position).y + local_44;
    }
    return;
}
