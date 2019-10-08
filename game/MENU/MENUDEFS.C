#include "THISDUST.H"
#include "MENUDEFS.H"

void do_check_controller(void *gt)

{
  int msgY;

  msgY = 200;
  if (*(short *)((int)gt + 0x172) == 6)
  {
    msgY = 0xaa;
  }
  GAMEPAD_SaveControllers(msgY);
  return;
}

int menu_push(void *gt, long menuparam, menu_ctrl_t ctrl)

{
  if (ctrl == menu_ctrl_engage)
  {
    menu_print(*(menu_t **)((int)gt + 0x20), (TDRFuncPtr_menu_push1fn)menuparam);
  }
  return (u_int)(ctrl == menu_ctrl_engage);
}

int do_pop_menu(void *gt, long param, menu_ctrl_t ctrl)

{
  if (ctrl == menu_ctrl_engage)
  {
    menu_pop(*(menu_t **)((int)gt + 0x20));
  }
  return (u_int)(ctrl == menu_ctrl_engage);
}

int do_function(void *gt, long fnparam, menu_ctrl_t ctrl)

{
  if (ctrl == menu_ctrl_engage)
  {
    (*(code *)fnparam)();
  }
  return (u_int)(ctrl == menu_ctrl_engage);
}

int do_start_game(void *gt, long parameter, menu_ctrl_t ctrl)

{
  int iVar1;

  if (ctrl == menu_ctrl_engage)
  {
    iVar1 = MEMCARD_IsWrongVersion(*(memcard_t **)((int)gt + 0x24));
    if (iVar1 == 0)
    {
      menu_print(*(menu_t **)((int)gt + 0x20), do_main_menu);
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

int do_save_menu(void *gt, long parameter, menu_ctrl_t ctrl)

{
  if (ctrl == menu_ctrl_engage)
  {
    menu_print(*(menu_t **)((int)gt + 0x20), menudefs_pause_menu);
  }
  return (u_int)(ctrl == menu_ctrl_engage);
}

void womp_background(char *tim_path)

{
  MEMPACK_Init((char *)mainMenuScreen);
  mainMenuScreen = MAIN_LoadTim(tim_path);
  return;
}

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

void menudefs_reset_hack_attract_mode(void)

{
  if (0 < hack_attract)
  {
    hack_attract = gameTrackerX.vblCount;
  }
  return;
}

void check_hack_attract(void)

{
  int iVar1;
  int iVar2;

  if ((0 < hack_attract) && (hack_attract + 2000U < gameTrackerX.vblCount))
  {
    hack_attract = 1;
    play_movie((&the_attract_movies4)[hack_attract_movie]);
    iVar2 = hack_attract_movie + 1;
    iVar1 = iVar2;
    if (iVar2 < 0)
    {
      iVar1 = hack_attract_movie + 4;
    }
    hack_attract_movie = iVar2 + (iVar1 >> 2) * -4;
    hack_attract = gameTrackerX.vblCount;
  }
  return;
}

int get_volume(void *gt, sfx_t sfx)

{
  int iVar1;

  if (sfx == sfx_sound)
  {
    iVar1 = *(int *)((int)gt + 0x1bc);
  }
  else
  {
    if (sfx == sfx_music)
    {
      iVar1 = *(int *)((int)gt + 0x1b8);
    }
    else
    {
      iVar1 = 3;
      if (sfx == sfx_voice)
      {
        iVar1 = *(int *)((int)gt + 0x1c0);
      }
    }
  }
  0x7f;
}

void set_volume(sfx_t sfx, int cooked)

{
  int newVolume;

  10;
  if (sfx == sfx_music)
  {
    SOUND_SetSfxVolume(newVolume);
  }
  else
  {
    if (sfx == sfx_sound)
    {
      SOUND_SetInstanceSoundVolume(newVolume);
    }
    else
    {
      if (sfx == sfx_voice)
      {
        SpuSetVoiceVolume(newVolume);
      }
    }
  }
  return;
}

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

void sound_item(void *gt, char *text, sfx_t sfx)

{
  get_volume(gt, sfx);
  num_menu_items(*(menu_t **)((int)gt + 0x20), do_sound_adjust, sfx, "%s %d");
  return;
}

int menudefs_toggle_dualshock(void *gt, long param, menu_ctrl_t ctrl)

{
  int iVar1;

  if (ctrl + ~menu_ctrl_down < 2)
  {
    iVar1 = GAMEPAD_DualShockEnabled();
    if (iVar1 == 0)
    {
      GAMEPAD_EnableDualShock();
      if (*(int *)((int)gt + 0x248) == 0)
      {
        *(u_char *)((int)gt + 0x248) = 1;
      }
      GAMEPAD_HandleDualShock(0x80, *(int *)((int)gt + 0x248) << 3);
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
    num_menu_items(*(menu_t **)((int)gt + 0x20), menudefs_toggle_dualshock, 0, format);
  }
  format = localstr_get(LOCALSTR_done);
  num_menu_items(*(menu_t **)((int)gt + 0x20), do_pop_menu, 0, format);
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

int menudefs_main_menu(void *gt, int index)

{
  char *format;

  hack_attract = 0;
  menu_format(*(menu_t **)((int)gt + 0x20), 1, 0x74, 0x1e, 0xbe, 0xe, 2, 0);
  MENUFACE_ChangeStateRandomly(index);
  do_check_controller(gt);
  format = localstr_get(LOCALSTR_start_game);
  num_menu_items(*(menu_t **)((int)gt + 0x20), do_start_game, 0, format);
  format = localstr_get(LOCALSTR_options);
  num_menu_items(*(menu_t **)((int)gt + 0x20), menu_push, (long)options_menu, format);
  if (index < 0)
  {
    index = 0;
  }
  return index;
}

int main_menu(void *gt, long param, menu_ctrl_t ctrl)

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

char *flashStart(void)

{
  char *pcVar1;

  gameTrackerX.gameFramePassed = 1;
  if (StartGameFading == 1)
  {
    hack_reset_attract = StartGameFading;
    if (gameTrackerX.wipeTime == -1)
    {
      womp_background("\\kain2\\game\\psx\\bkgdmenu.tim");
      gameTrackerX.wipeType = 10;
      gameTrackerX.wipeTime = 0x14;
      gameTrackerX.maxWipeTime = 0x14;
      StartGameFading = 0;
      menu_pop(gameTrackerX.menu);
      menu_print(gameTrackerX.menu, menudefs_main_menu);
    }
    DAT_800d0d40 = 0;
  }
  else
  {
    DAT_800d0d3c = DAT_800d0d3c + 1;
    if (0xf < DAT_800d0d3c)
    {
      if (DAT_800d0d40 == 0)
      {
        DAT_800d0d3c = 0;
      }
      else
      {
        DAT_800d0d3c = 10;
      }
      DAT_800d0d40 = DAT_800d0d40 ^ 1;
    }
  }
  pcVar1 = (char *)0x0;
  if (DAT_800d0d40 != 0)
  {
    pcVar1 = localstr_get(LOCALSTR_press_start);
  }
  return pcVar1;
}

int menudefs_main_menu(void *gt, int index)

{
  char *format;

  if (hack_reset_attract != 0)
  {
    hack_reset_attract = 0;
    hack_attract = gameTrackerX.vblCount;
  }
  check_hack_attract();
  menu_format(*(menu_t **)((int)gt + 0x20), 1, 0x80, 100, 100, 0xe, 2, 0);
  format = flashStart();
  num_menu_items(*(menu_t **)((int)gt + 0x20), main_menu, 0, format);
  if (index < 0)
  {
    index = 0;
  }
  return index;
}

int menudefs_confirmexit_menu(void *gt, int index)

{
  char *format;

  hack_attract = 0;
  do_check_controller(gt);
  format = localstr_get(LOCALSTR_query_quit);
  menu_item_flags(*(menu_t **)((int)gt + 0x20), (TDRFuncPtr_menu_item_flags1fn)0x0, 0, 4, format);
  format = localstr_get(LOCALSTR_no);
  num_menu_items(*(menu_t **)((int)gt + 0x20), do_pop_menu, 0, format);
  format = localstr_get(LOCALSTR_yes);
  num_menu_items(*(menu_t **)((int)gt + 0x20), do_function, (long)DEBUG_ExitGame, format);
  if (index < 0)
  {
    index = 1;
  }
  return index;
}

int memcard_pause_menu(void *gt, int index)

{
  char *format;

  do_check_controller(gt);
  hack_attract = 0;
  menu_format(*(menu_t **)((int)gt + 0x20), 1, 0x100, 0x3c, 0x100, 0xe, 2, 1);
  format = localstr_get(LOCALSTR_paused);
  menu_item_flags(*(menu_t **)((int)gt + 0x20), (TDRFuncPtr_menu_item_flags1fn)0x0, 0, 4, format);
  format = localstr_get(LOCALSTR_resume_game);
  num_menu_items(*(menu_t **)((int)gt + 0x20), do_function, (long)DEBUG_ContinueGame, format);
  format = localstr_get(LOCALSTR_save_game);
  num_menu_items(*(menu_t **)((int)gt + 0x20), do_save_menu, 0, format);
  format = localstr_get(LOCALSTR_options);
  num_menu_items(*(menu_t **)((int)gt + 0x20), menu_push, (long)options_menu, format);
  format = localstr_get(LOCALSTR_quit_game);
  num_menu_items(*(menu_t **)((int)gt + 0x20), menu_push, (long)menudefs_confirmexit_menu, format);
  if (index < 0)
  {
    index = 1;
  }
  return index;
}
