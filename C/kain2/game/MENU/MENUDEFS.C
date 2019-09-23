#include "THISDUST.H"
#include "MENUDEFS.H"

// int @0x800CFA70, len = 0x00000004
hack_attract = 0x0;
// int @0x800CFA74, len = 0x00000004
hack_attract_movie = 0x0;
// int @0x800CFA68, len = 0x00000004
hack_reset_attract = 0x1;
// int @0x800CFA64, len = 0x00000004
ITEMSKIP = 0x2;
// int @0x800CFA60, len = 0x00000004
LINESKIP = 0xe;
// int @0x800CFA54, len = 0x00000004
MAIN_WIDTH = 0xac;
// int @0x800CFA50, len = 0x00000004
MAIN_XPOS = 0x87;
// int @0x800CFA48, len = 0x00000004
MAIN_YPOS = 0x1e;
// int @0x800CFA5C, len = 0x00000004
PAUSE_WIDTH = 0x100;
// int @0x800CFA58, len = 0x00000004
PAUSE_XPOS = 0x100;
// int @0x800CFA4C, len = 0x00000004
PAUSE_YPOS = 0x3c;
// int @0x800CFA6C, len = 0x00000004
StartGameFading = 0x0;
// char * @0x800CADC8, len = 0x00000004
the_attract_movies4 = "\KAINDEM1.STR;1" /* collapsed from &s_KAINDEM1_STR1_800cfa38 */;
// decompiled code
// original method signature:
// void /*$ra*/ do_check_controller(void *gt /*$a0*/)
// line 164, offset 0x800b8938
/* begin block 1 */
// Start line: 328
/* end block 1 */
// End Line: 329

void do_check_controller(void *gt)

{
  int msgY;

  msgY = 200;
  if (*(short *)((int)gt + 0x172) == 6)
  {
    msgY = 0xaa;
  }
  GAMEPAD_DisplayControllerStatus(msgY);
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ do_push_menu(void *gt /*$a0*/, long menuparam /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
// line 180, offset 0x800b896c
/* begin block 1 */
// Start line: 181
// Start offset: 0x800B896C
/* end block 1 */
// End offset: 0x800B8994
// End Line: 194

/* begin block 2 */
// Start line: 360
/* end block 2 */
// End Line: 361

int do_push_menu(void *gt, long menuparam, menu_ctrl_t ctrl)

{
  if (ctrl == menu_ctrl_engage)
  {
    menu_push(*(menu_t **)((int)gt + 0x20), (TDRFuncPtr_menu_push1fn)menuparam);
  }
  return (uint)(ctrl == menu_ctrl_engage);
}

// decompiled code
// original method signature:
// int /*$ra*/ do_pop_menu(void *gt /*$a0*/, long param /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
// line 196, offset 0x800b89a4
/* begin block 1 */
// Start line: 401
/* end block 1 */
// End Line: 402

int do_pop_menu(void *gt, long param, menu_ctrl_t ctrl)

{
  if (ctrl == menu_ctrl_engage)
  {
    menu_pop(*(menu_t **)((int)gt + 0x20));
  }
  return (uint)(ctrl == menu_ctrl_engage);
}

// decompiled code
// original method signature:
// int /*$ra*/ do_function(void *gt /*$a0*/, long fnparam /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
// line 207, offset 0x800b89dc
/* begin block 1 */
// Start line: 420
/* end block 1 */
// End Line: 421

/* begin block 2 */
// Start line: 426
/* end block 2 */
// End Line: 427

int do_function(void *gt, long fnparam, menu_ctrl_t ctrl)

{
  if (ctrl == menu_ctrl_engage)
  {
    (*(code *)fnparam)();
  }
  return (uint)(ctrl == menu_ctrl_engage);
}

// decompiled code
// original method signature:
// int /*$ra*/ do_start_game(void *gt /*$s0*/, long parameter /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
// line 221, offset 0x800b8a10
/* begin block 1 */
// Start line: 448
/* end block 1 */
// End Line: 449

/* begin block 2 */
// Start line: 457
/* end block 2 */
// End Line: 458

int do_start_game(void *gt, long parameter, menu_ctrl_t ctrl)

{
  int iVar1;

  if (ctrl == menu_ctrl_engage)
  {
    iVar1 = MEMCARD_IsWrongVersion(*(memcard_t **)((int)gt + 0x24));
    if (iVar1 == 0)
    {
      menu_push(*(menu_t **)((int)gt + 0x20), memcard_main_menu);
      iVar1 = 1;
    }
    else
    {
      MAIN_StartGame();
      iVar1 = 1;
    }
  }
  else
  {
    iVar1 = 0;
  }
  return iVar1;
}

// decompiled code
// original method signature:
// int /*$ra*/ do_save_menu(void *gt /*$a0*/, long parameter /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
// line 250, offset 0x800b8a74
/* begin block 1 */
// Start line: 515
/* end block 1 */
// End Line: 516

int do_save_menu(void *gt, long parameter, menu_ctrl_t ctrl)

{
  if (ctrl == menu_ctrl_engage)
  {
    menu_push(*(menu_t **)((int)gt + 0x20), memcard_pause_menu);
  }
  return (uint)(ctrl == menu_ctrl_engage);
}

// decompiled code
// original method signature:
// void /*$ra*/ womp_background(char *tim_path /*$s0*/)
// line 277, offset 0x800b8ab0
/* begin block 1 */
// Start line: 553
/* end block 1 */
// End Line: 554

/* begin block 2 */
// Start line: 573
/* end block 2 */
// End Line: 574

void womp_background(char *tim_path)

{
  MEMPACK_Free((char *)mainMenuScreen);
  mainMenuScreen = MAIN_LoadTim(tim_path);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ play_movie(char *name /*$s0*/)
// line 291, offset 0x800b8ae8
/* begin block 1 */
// Start line: 292
// Start offset: 0x800B8AE8
/* end block 1 */
// End offset: 0x800B8B20
// End Line: 311

/* begin block 2 */
// Start line: 608
/* end block 2 */
// End Line: 609

void play_movie(char *name)

{
  int iVar1;

  iVar1 = CINE_Load();
  if (iVar1 != 0)
  {
    CINE_Play(name, 0xffff, 2);
    CINE_Unload();
    MAIN_InitVolume();
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ menudefs_reset_hack_attract_mode()
// line 331, offset 0x800b8b30
/* begin block 1 */
// Start line: 688
/* end block 1 */
// End Line: 689

/* begin block 2 */
// Start line: 689
/* end block 2 */
// End Line: 690

/* WARNING: Unknown calling convention yet parameter storage is locked */

void menudefs_reset_hack_attract_mode(void)

{
  if (0 < hack_attract)
  {
    hack_attract = gameTrackerX.vblCount;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ check_hack_attract()
// line 336, offset 0x800b8b54
/* begin block 1 */
// Start line: 698
/* end block 1 */
// End Line: 699

/* begin block 2 */
// Start line: 700
/* end block 2 */
// End Line: 701

/* WARNING: Unknown calling convention yet parameter storage is locked */

void check_hack_attract(void)

{
  if ((0 < hack_attract) && (hack_attract + 2000U < gameTrackerX.vblCount))
  {
    hack_attract = 1;
    play_movie((&the_attract_movies4)[hack_attract_movie]);
    hack_attract_movie = hack_attract_movie + 1U & 3;
    hack_attract = gameTrackerX.vblCount;
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ get_volume(void *gt /*$a0*/, enum sfx_t sfx /*$a1*/)
// line 377, offset 0x800b8bc4
/* begin block 1 */
// Start line: 379
// Start offset: 0x800B8BC4
// Variables:
// 		int raw; // $a2
/* end block 1 */
// End offset: 0x800B8C00
// End Line: 385

/* begin block 2 */
// Start line: 784
/* end block 2 */
// End Line: 785

/* begin block 3 */
// Start line: 785
/* end block 3 */
// End Line: 786

/* begin block 4 */
// Start line: 786
/* end block 4 */
// End Line: 787

int get_volume(void *gt, sfx_t sfx)

{
  int iVar1;

  if (sfx == sfx_sound)
  {
    iVar1 = *(int *)((int)gt + 0x1b8);
  }
  else
  {
    if (sfx == sfx_music)
    {
      iVar1 = *(int *)((int)gt + 0x1b4);
    }
    else
    {
      iVar1 = 3;
      if (sfx == sfx_voice)
      {
        iVar1 = *(int *)((int)gt + 0x1bc);
      }
    }
  }
  return (iVar1 * 10) / 0x7f;
}

// decompiled code
// original method signature:
// void /*$ra*/ set_volume(enum sfx_t sfx /*$a2*/, int cooked /*$a1*/)
// line 388, offset 0x800b8c30
/* begin block 1 */
// Start line: 389
// Start offset: 0x800B8C30
// Variables:
// 		int raw; // $a0
/* end block 1 */
// End offset: 0x800B8CAC
// End Line: 397

/* begin block 2 */
// Start line: 806
/* end block 2 */
// End Line: 807

/* begin block 3 */
// Start line: 807
/* end block 3 */
// End Line: 808

void set_volume(sfx_t sfx, int cooked)

{
  int newVolume;

  newVolume = (cooked * 0x7f + 9) / 10;
  if (sfx == sfx_music)
  {
    SOUND_SetMusicVolume(newVolume);
  }
  else
  {
    if (sfx == sfx_sound)
    {
      SOUND_SetSfxVolume(newVolume);
    }
    else
    {
      if (sfx == sfx_voice)
      {
        SOUND_SetVoiceVolume(newVolume);
      }
    }
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ do_sound_adjust(void *gt /*$a0*/, long sfxparam /*$s0*/, enum menu_ctrl_t ctrl /*$s1*/)
// line 399, offset 0x800b8cbc
/* begin block 1 */
// Start line: 400
// Start offset: 0x800B8CBC
// Variables:
// 		int volume; // $a1
/* end block 1 */
// End offset: 0x800B8D24
// End Line: 420

/* begin block 2 */
// Start line: 829
/* end block 2 */
// End Line: 830

int do_sound_adjust(void *gt, long sfxparam, menu_ctrl_t ctrl)

{
  int cooked;

  cooked = get_volume(gt, sfxparam);
  if (ctrl == menu_ctrl_left)
  {
    if (cooked < 1)
    {
      return 1;
    }
    cooked = cooked + -1;
  }
  else
  {
    if (ctrl != menu_ctrl_right)
    {
      return 0;
    }
    if (9 < cooked)
    {
      return 1;
    }
    cooked = cooked + 1;
  }
  set_volume(sfxparam, cooked);
  return 1;
}

// decompiled code
// original method signature:
// void /*$ra*/ sound_item(void *gt /*$s0*/, char *text /*$s2*/, enum sfx_t sfx /*$s1*/)
// line 422, offset 0x800b8d38
/* begin block 1 */
// Start line: 423
// Start offset: 0x800B8D38
/* end block 1 */
// End offset: 0x800B8D38
// End Line: 423

/* begin block 2 */
// Start line: 875
/* end block 2 */
// End Line: 876

void sound_item(void *gt, char *text, sfx_t sfx)

{
  get_volume(gt, sfx);
  menu_item(*(menu_t **)((int)gt + 0x20), do_sound_adjust, sfx, s__s__d_800cfa78);
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ menudefs_toggle_dualshock(void *gt /*$a0*/, long param /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
// line 1048, offset 0x800b8d9c
/* begin block 1 */
// Start line: 2127
/* end block 1 */
// End Line: 2128

int menudefs_toggle_dualshock(void *gt, long param, menu_ctrl_t ctrl)

{
  int iVar1;

  if (ctrl + ~menu_ctrl_down < 2)
  {
    iVar1 = GAMEPAD_DualShockEnabled();
    if (iVar1 == 0)
    {
      GAMEPAD_EnableDualShock();
      GAMEPAD_Shock1(0x80, 0x8000);
      iVar1 = 1;
    }
    else
    {
      GAMEPAD_DisableDualShock();
      iVar1 = 1;
    }
  }
  else
  {
    iVar1 = 0;
  }
  return iVar1;
}

// decompiled code
// original method signature:
// int /*$ra*/ options_menu(void *gt /*$s1*/, int index /*$s2*/)
// line 1066, offset 0x800b8e00
/* begin block 1 */
// Start line: 1067
// Start offset: 0x800B8E00
// Variables:
// 		static int wasDualShock; // offset 0x0
// 		int dualShock; // $s0
/* end block 1 */
// End offset: 0x800B8F30
// End Line: 1128

/* begin block 2 */
// Start line: 2163
/* end block 2 */
// End Line: 2164

int options_menu(void *gt, int index)

{
  char *format;
  int iVar1;
  int iVar2;
  localstr_t id;

  hack_attract = 0;
  MENUFACE_ChangeStateRandomly(index);
  do_check_controller(gt);
  format = localstr_get(LOCALSTR_options);
  menu_item_flags(*(menu_t **)((int)gt + 0x20), (TDRFuncPtr_menu_item_flags1fn)0x0, 0, 4, format);
  format = localstr_get(LOCALSTR_sound);
  sound_item(gt, format, sfx_sound);
  format = localstr_get(LOCALSTR_music);
  sound_item(gt, format, sfx_music);
  format = localstr_get(LOCALSTR_voice);
  sound_item(gt, format, sfx_voice);
  iVar1 = GAMEPAD_ControllerIsDualShock();
  if (iVar1 != 0)
  {
    iVar2 = GAMEPAD_DualShockEnabled();
    id = LOCALSTR_vibration_off;
    if (iVar2 != 0)
    {
      id = LOCALSTR_vibration_on;
    }
    format = localstr_get(id);
    menu_item(*(menu_t **)((int)gt + 0x20), menudefs_toggle_dualshock, 0, format);
  }
  format = localstr_get(LOCALSTR_done);
  menu_item(*(menu_t **)((int)gt + 0x20), do_pop_menu, 0, format);
  if ((iVar1 != wasDualShock_54) && (3 < index))
  {
    index = iVar1 + 4;
  }
  if (index < 0)
  {
    index = 1;
  }
  wasDualShock_54 = iVar1;
  return index;
}

// decompiled code
// original method signature:
// int /*$ra*/ main_menu(void *gt /*$s0*/, int index /*$s1*/)
// line 1145, offset 0x800b8f48
/* begin block 1 */
// Start line: 2321
/* end block 1 */
// End Line: 2322

int main_menu(void *gt, int index)

{
  language_t lVar1;
  char *format;
  menu_t *menu;
  int ypos;

  hack_attract = 0;
  lVar1 = localstr_get_language();
  if (lVar1 == language_spanish)
  {
    menu = *(menu_t **)((int)gt + 0x20);
    ypos = MAIN_YPOS + -2;
  }
  else
  {
    menu = *(menu_t **)((int)gt + 0x20);
    ypos = MAIN_YPOS;
  }
  menu_format(menu, 1, MAIN_XPOS, ypos, MAIN_WIDTH, LINESKIP, ITEMSKIP, 0);
  MENUFACE_ChangeStateRandomly(index);
  do_check_controller(gt);
  format = localstr_get(LOCALSTR_start_game);
  menu_item(*(menu_t **)((int)gt + 0x20), do_start_game, 0, format);
  format = localstr_get(LOCALSTR_options);
  menu_item(*(menu_t **)((int)gt + 0x20), do_push_menu, (long)options_menu, format);
  if (index < 0)
  {
    index = 0;
  }
  return index;
}

// decompiled code
// original method signature:
// int /*$ra*/ do_main_menu(void *gt /*$a0*/, long param /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
// line 1180, offset 0x800b904c
/* begin block 1 */
// Start line: 2391
/* end block 1 */
// End Line: 2392

/* begin block 2 */
// Start line: 2392
/* end block 2 */
// End Line: 2393

int do_main_menu(void *gt, long param, menu_ctrl_t ctrl)

{
  if ((StartGameFading == 0) && ((ctrl == menu_ctrl_start || (ctrl == menu_ctrl_engage))))
  {
    *(undefined2 *)((int)gt + 0xd0) = 10;
    *(undefined2 *)((int)gt + 0xcc) = 0xffec;
    *(undefined2 *)((int)gt + 0xce) = 0x14;
    StartGameFading = 1;
    return 1;
  }
  return 0;
}

// decompiled code
// original method signature:
// char * /*$ra*/ flashStart()
// line 1196, offset 0x800b90a0
/* begin block 1 */
// Start line: 1197
// Start offset: 0x800B90A0

/* begin block 1.1 */
// Start line: 1225
// Start offset: 0x800B9120
// Variables:
// 		static int counter; // offset 0x98
// 		int intpl; // $a0
// 		int fcols[2][3]; // stack offset -40
// 		int r; // $s2
// 		int g; // $s1
// 		int b; // $s0
/* end block 1.1 */
// End offset: 0x800B9284
// End Line: 1247
/* end block 1 */
// End offset: 0x800B928C
// End Line: 1250

/* begin block 2 */
// Start line: 2427
/* end block 2 */
// End Line: 2428

/* WARNING: Unknown calling convention yet parameter storage is locked */

char *flashStart(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;

  gameTrackerX.gameFramePassed = 1;
  if (StartGameFading == 1)
  {
    hack_reset_attract = StartGameFading;
    if (gameTrackerX.wipeTime == -1)
    {
      womp_background(s__kain2_game_psx_bkgdmenu_tim_800cfa80);
      gameTrackerX.wipeType = 10;
      gameTrackerX.wipeTime = 0x14;
      gameTrackerX.maxWipeTime = 0x14;
      StartGameFading = 0;
      menu_pop(gameTrackerX.menu);
      menu_push(gameTrackerX.menu, main_menu);
      return (char *)0x0;
    }
    goto LAB_800b9284;
  }
  DAT_800cfaa0 = (DAT_800cfaa0 + 1) % 0x3c;
  if (DAT_800cfaa0 < 10)
  {
    iVar3 = 0;
  }
  else
  {
    if (DAT_800cfaa0 < 0x1e)
    {
      iVar3 = DAT_800cfaa0 + -10;
    }
    else
    {
      if (DAT_800cfaa0 < 0x28)
      {
        iVar3 = 0x1000;
        goto LAB_800b91ec;
      }
      iVar3 = 0x3c - DAT_800cfaa0;
    }
    iVar3 = (iVar3 << 0xc) / 0x14;
  }
LAB_800b91ec:
  iVar2 = 0x1000 - iVar3;
  iVar4 = DAT_800cfaa4 * iVar2;
  iVar5 = DAT_800cfab0 * iVar3;
  iVar6 = DAT_800cfaa8 * iVar2;
  iVar7 = DAT_800cfab4 * iVar3;
  iVar2 = DAT_800cfaac * iVar2;
  iVar3 = DAT_800cfab8 * iVar3;
  FONT_SetColorIndex(4);
  FONT_SetColorIndexCol(4, iVar4 + iVar5 >> 0xc, iVar6 + iVar7 >> 0xc, iVar2 + iVar3 >> 0xc);
LAB_800b9284:
  pcVar1 = localstr_get(LOCALSTR_press_start);
  return pcVar1;
}

// decompiled code
// original method signature:
// int /*$ra*/ menudefs_main_menu(void *gt /*$s0*/, int index /*$s1*/)
// line 1252, offset 0x800b92a4
/* begin block 1 */
// Start line: 2554
/* end block 1 */
// End Line: 2555

/* begin block 2 */
// Start line: 2555
/* end block 2 */
// End Line: 2556

int menudefs_main_menu(void *gt, int index)

{
  char *format;

  if (hack_reset_attract != 0)
  {
    hack_reset_attract = 0;
    hack_attract = gameTrackerX.vblCount;
  }
  check_hack_attract();
  menu_format(*(menu_t **)((int)gt + 0x20), 1, 0x16e, 0x90, 100, LINESKIP, ITEMSKIP, 0);
  format = flashStart();
  menu_item(*(menu_t **)((int)gt + 0x20), do_main_menu, 0, format);
  if (index < 0)
  {
    index = 0;
  }
  return index;
}

// decompiled code
// original method signature:
// int /*$ra*/ menudefs_confirmexit_menu(void *gt /*$s0*/, int index /*$s1*/)
// line 1283, offset 0x800b934c
/* begin block 1 */
// Start line: 2619
/* end block 1 */
// End Line: 2620

int menudefs_confirmexit_menu(void *gt, int index)

{
  char *format;

  hack_attract = 0;
  do_check_controller(gt);
  format = localstr_get(LOCALSTR_query_quit);
  menu_item_flags(*(menu_t **)((int)gt + 0x20), (TDRFuncPtr_menu_item_flags1fn)0x0, 0, 4, format);
  format = localstr_get(LOCALSTR_no);
  menu_item(*(menu_t **)((int)gt + 0x20), do_pop_menu, 0, format);
  format = localstr_get(LOCALSTR_yes);
  menu_item(*(menu_t **)((int)gt + 0x20), do_function, (long)DEBUG_ExitGame, format);
  if (index < 0)
  {
    index = 1;
  }
  return index;
}

// decompiled code
// original method signature:
// int /*$ra*/ menudefs_pause_menu(void *gt /*$s1*/, int index /*$s2*/)
// line 1294, offset 0x800b93f4
/* begin block 1 */
// Start line: 2641
/* end block 1 */
// End Line: 2642

int menudefs_pause_menu(void *gt, int index)

{
  char *format;

  do_check_controller(gt);
  hack_attract = 0;
  menu_format(*(menu_t **)((int)gt + 0x20), 1, PAUSE_XPOS, PAUSE_YPOS, PAUSE_WIDTH, LINESKIP, ITEMSKIP, 1);
  format = localstr_get(LOCALSTR_paused);
  menu_item_flags(*(menu_t **)((int)gt + 0x20), (TDRFuncPtr_menu_item_flags1fn)0x0, 0, 4, format);
  format = localstr_get(LOCALSTR_resume_game);
  menu_item(*(menu_t **)((int)gt + 0x20), do_function, (long)DEBUG_ContinueGame, format);
  if ((gameTrackerX.streamFlags & 4U) == 0)
  {
    format = localstr_get(LOCALSTR_save_game);
    menu_item(*(menu_t **)((int)gt + 0x20), do_save_menu, 0, format);
    format = localstr_get(LOCALSTR_options);
    menu_item(*(menu_t **)((int)gt + 0x20), do_push_menu, (long)options_menu, format);
    format = localstr_get(LOCALSTR_quit_game);
    menu_item(*(menu_t **)((int)gt + 0x20), do_push_menu, (long)menudefs_confirmexit_menu, format);
  }
  if (index < 0)
  {
    index = 1;
  }
  return index;
}
