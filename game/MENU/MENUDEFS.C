#include "THISDUST.H"
#include "MENUDEFS.H"


// decompiled code
// original method signature: 
// int /*$ra*/ do_push_menu(void *gt /*$a0*/, long menuparam /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
 // line 143, offset 0x800b2980
	/* begin block 1 */
		// Start line: 144
		// Start offset: 0x800B2980
	/* end block 1 */
	// End offset: 0x800B29A8
	// End Line: 157

	/* begin block 2 */
		// Start line: 286
	/* end block 2 */
	// End Line: 287

int do_push_menu(void *gt,long menuparam,menu_ctrl_t ctrl)

{
  if (ctrl == menu_ctrl_engage) {
    menu_push(*(menu_t **)((int)gt + 0x20),(TDRFuncPtr_menu_push1fn)menuparam);
  }
  return (uint)(ctrl == menu_ctrl_engage);
}



// decompiled code
// original method signature: 
// int /*$ra*/ do_pop_menu(void *gt /*$a0*/, long param /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
 // line 159, offset 0x800b29b8
	/* begin block 1 */
		// Start line: 327
	/* end block 1 */
	// End Line: 328

int do_pop_menu(void *gt,long param,menu_ctrl_t ctrl)

{
  if (ctrl == menu_ctrl_engage) {
    menu_pop(*(menu_t **)((int)gt + 0x20));
  }
  return (uint)(ctrl == menu_ctrl_engage);
}



// decompiled code
// original method signature: 
// int /*$ra*/ do_function(void *gt /*$a0*/, long fnparam /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
 // line 170, offset 0x800b29f0
	/* begin block 1 */
		// Start line: 346
	/* end block 1 */
	// End Line: 347

	/* begin block 2 */
		// Start line: 352
	/* end block 2 */
	// End Line: 353

int do_function(void *gt,long fnparam,menu_ctrl_t ctrl)

{
  if (ctrl == menu_ctrl_engage) {
    (*(code *)fnparam)();
  }
  return (uint)(ctrl == menu_ctrl_engage);
}



// decompiled code
// original method signature: 
// int /*$ra*/ do_start_game(void *gt /*$s0*/, long parameter /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
 // line 184, offset 0x800b2a24
	/* begin block 1 */
		// Start line: 374
	/* end block 1 */
	// End Line: 375

	/* begin block 2 */
		// Start line: 383
	/* end block 2 */
	// End Line: 384

int do_start_game(void *gt,long parameter,menu_ctrl_t ctrl)

{
  int iVar1;
  
  if (ctrl == menu_ctrl_engage) {
    iVar1 = MEMCARD_IsWrongVersion(*(memcard_t **)((int)gt + 0x24));
    if (iVar1 == 0) {
      menu_push(*(menu_t **)((int)gt + 0x20),memcard_main_menu);
      iVar1 = 1;
    }
    else {
      MAIN_StartGame();
      iVar1 = 1;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ do_save_menu(void *gt /*$a0*/, long parameter /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
 // line 210, offset 0x800b2a88
	/* begin block 1 */
		// Start line: 435
	/* end block 1 */
	// End Line: 436

int do_save_menu(void *gt,long parameter,menu_ctrl_t ctrl)

{
  if (ctrl == menu_ctrl_engage) {
    menu_push(*(menu_t **)((int)gt + 0x20),memcard_pause_menu);
  }
  return (uint)(ctrl == menu_ctrl_engage);
}



// decompiled code
// original method signature: 
// void /*$ra*/ womp_background(char *tim_path /*$s0*/)
 // line 237, offset 0x800b2ac4
	/* begin block 1 */
		// Start line: 473
	/* end block 1 */
	// End Line: 474

	/* begin block 2 */
		// Start line: 493
	/* end block 2 */
	// End Line: 494

void womp_background(char *tim_path)

{
  MEMPACK_Free((char *)mainMenuScreen);
  mainMenuScreen = MAIN_LoadTim(tim_path);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ play_movie(char *name /*$s0*/)
 // line 245, offset 0x800b2afc
	/* begin block 1 */
		// Start line: 246
		// Start offset: 0x800B2AFC
	/* end block 1 */
	// End offset: 0x800B2B2C
	// End Line: 264

	/* begin block 2 */
		// Start line: 510
	/* end block 2 */
	// End Line: 511

void play_movie(char *name)

{
  int iVar1;
  
  iVar1 = CINE_Load();
  if (iVar1 != 0) {
    CINE_Play(name,0x4001,2);
    CINE_Unload();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ menudefs_reset_hack_attract_mode()
 // line 284, offset 0x800b2b3c
	/* begin block 1 */
		// Start line: 588
	/* end block 1 */
	// End Line: 589

	/* begin block 2 */
		// Start line: 589
	/* end block 2 */
	// End Line: 590

/* WARNING: Unknown calling convention yet parameter storage is locked */

void menudefs_reset_hack_attract_mode(void)

{
  if (0 < hack_attract) {
    hack_attract = gameTrackerX.vblCount;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ check_hack_attract()
 // line 289, offset 0x800b2b60
	/* begin block 1 */
		// Start line: 598
	/* end block 1 */
	// End Line: 599

	/* begin block 2 */
		// Start line: 600
	/* end block 2 */
	// End Line: 601

/* WARNING: Unknown calling convention yet parameter storage is locked */

void check_hack_attract(void)

{
  int iVar1;
  int iVar2;
  
  if ((0 < hack_attract) && (hack_attract + 2000U < gameTrackerX.vblCount)) {
    hack_attract = 1;
    play_movie((&the_attract_movies4)[hack_attract_movie]);
    iVar2 = hack_attract_movie + 1;
    iVar1 = iVar2;
    if (iVar2 < 0) {
      iVar1 = hack_attract_movie + 4;
    }
    hack_attract_movie = iVar2 + (iVar1 >> 2) * -4;
    hack_attract = gameTrackerX.vblCount;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ get_volume(void *gt /*$a0*/, enum sfx_t sfx /*$a1*/)
 // line 314, offset 0x800b2be8
	/* begin block 1 */
		// Start line: 316
		// Start offset: 0x800B2BE8
		// Variables:
	// 		int raw; // $a2
	/* end block 1 */
	// End offset: 0x800B2C24
	// End Line: 322

	/* begin block 2 */
		// Start line: 652
	/* end block 2 */
	// End Line: 653

	/* begin block 3 */
		// Start line: 653
	/* end block 3 */
	// End Line: 654

	/* begin block 4 */
		// Start line: 654
	/* end block 4 */
	// End Line: 655

int get_volume(void *gt,sfx_t sfx)

{
  int iVar1;
  
  if (sfx == sfx_sound) {
    iVar1 = *(int *)((int)gt + 0x1bc);
  }
  else {
    if (sfx == sfx_music) {
      iVar1 = *(int *)((int)gt + 0x1b8);
    }
    else {
      iVar1 = 3;
      if (sfx == sfx_voice) {
        iVar1 = *(int *)((int)gt + 0x1c0);
      }
    }
  }
  return (iVar1 * 10) / 0x7f;
}



// decompiled code
// original method signature: 
// void /*$ra*/ set_volume(enum sfx_t sfx /*$a2*/, int cooked /*$a1*/)
 // line 325, offset 0x800b2c54
	/* begin block 1 */
		// Start line: 326
		// Start offset: 0x800B2C54
		// Variables:
	// 		int raw; // $a0
	/* end block 1 */
	// End offset: 0x800B2CD0
	// End Line: 334

	/* begin block 2 */
		// Start line: 674
	/* end block 2 */
	// End Line: 675

	/* begin block 3 */
		// Start line: 675
	/* end block 3 */
	// End Line: 676

void set_volume(sfx_t sfx,int cooked)

{
  int newVolume;
  
  newVolume = (cooked * 0x7f + 9) / 10;
  if (sfx == sfx_music) {
    SOUND_SetMusicVolume(newVolume);
  }
  else {
    if (sfx == sfx_sound) {
      SOUND_SetSfxVolume(newVolume);
    }
    else {
      if (sfx == sfx_voice) {
        SOUND_SetVoiceVolume(newVolume);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ do_sound_adjust(void *gt /*$a0*/, long sfxparam /*$s0*/, enum menu_ctrl_t ctrl /*$s1*/)
 // line 336, offset 0x800b2ce0
	/* begin block 1 */
		// Start line: 337
		// Start offset: 0x800B2CE0
		// Variables:
	// 		int volume; // $a1
	/* end block 1 */
	// End offset: 0x800B2D48
	// End Line: 357

	/* begin block 2 */
		// Start line: 697
	/* end block 2 */
	// End Line: 698

int do_sound_adjust(void *gt,long sfxparam,menu_ctrl_t ctrl)

{
  int cooked;
  
  cooked = get_volume(gt,sfxparam);
  if (ctrl == menu_ctrl_left) {
    if (cooked < 1) {
      return 1;
    }
    cooked = cooked + -1;
  }
  else {
    if (ctrl != menu_ctrl_right) {
      return 0;
    }
    if (9 < cooked) {
      return 1;
    }
    cooked = cooked + 1;
  }
  set_volume(sfxparam,cooked);
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ sound_item(void *gt /*$s0*/, char *text /*$s2*/, enum sfx_t sfx /*$s1*/)
 // line 359, offset 0x800b2d5c
	/* begin block 1 */
		// Start line: 360
		// Start offset: 0x800B2D5C
	/* end block 1 */
	// End offset: 0x800B2D5C
	// End Line: 360

	/* begin block 2 */
		// Start line: 743
	/* end block 2 */
	// End Line: 744

void sound_item(void *gt,char *text,sfx_t sfx)

{
  get_volume(gt,sfx);
  menu_item(*(menu_t **)((int)gt + 0x20),do_sound_adjust,sfx,"%s %d");
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ maybe_update_flags(long *flagsptr /*$a3*/, long mask /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
 // line 369, offset 0x800b2dc0
	/* begin block 1 */
		// Start line: 763
	/* end block 1 */
	// End Line: 764

	/* begin block 2 */
		// Start line: 764
	/* end block 2 */
	// End Line: 765

int maybe_update_flags(long *flagsptr,long mask,menu_ctrl_t ctrl)

{
  if ((ctrl == menu_ctrl_engage) && (ctrl = menu_ctrl_right, (*flagsptr & mask) == mask)) {
    ctrl = menu_ctrl_left;
  }
  if (ctrl != menu_ctrl_left) {
    if (ctrl != menu_ctrl_right) {
      return 0;
    }
    *flagsptr = *flagsptr | mask;
    return 1;
  }
  *flagsptr = *flagsptr & ~mask;
  return 1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ do_flags(void *gt /*$a0*/, long mask /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
 // line 404, offset 0x800b2e34
	/* begin block 1 */
		// Start line: 833
	/* end block 1 */
	// End Line: 834

int do_flags(void *gt,long mask,menu_ctrl_t ctrl)

{
  int iVar1;
  
  iVar1 = maybe_update_flags((long *)((int)gt + 0x144),mask,ctrl);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ do_debug(void *gt /*$a0*/, long mask /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
 // line 409, offset 0x800b2e54
	/* begin block 1 */
		// Start line: 843
	/* end block 1 */
	// End Line: 844

int do_debug(void *gt,long mask,menu_ctrl_t ctrl)

{
  int iVar1;
  
  iVar1 = maybe_update_flags((long *)((int)gt + 0xc4),mask,ctrl);
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ flags_item(void *gt /*$a0*/, char *text /*$a1*/, long mask /*$a2*/)
 // line 414, offset 0x800b2e74
	/* begin block 1 */
		// Start line: 415
		// Start offset: 0x800B2E74
		// Variables:
	// 		long flags; // $v0
	/* end block 1 */
	// End offset: 0x800B2EB4
	// End Line: 417

	/* begin block 2 */
		// Start line: 853
	/* end block 2 */
	// End Line: 854

void flags_item(void *gt,char *text,long mask)

{
  menu_item(*(menu_t **)((int)gt + 0x20),do_flags,mask,"%s %s");
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ debug_item(void *gt /*$a0*/, char *text /*$a1*/, long mask /*$a2*/)
 // line 421, offset 0x800b2ed0
	/* begin block 1 */
		// Start line: 422
		// Start offset: 0x800B2ED0
		// Variables:
	// 		long flags; // $v0
	/* end block 1 */
	// End offset: 0x800B2F10
	// End Line: 424

	/* begin block 2 */
		// Start line: 867
	/* end block 2 */
	// End Line: 868

void debug_item(void *gt,char *text,long mask)

{
  menu_item(*(menu_t **)((int)gt + 0x20),do_debug,mask,"%s %s");
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ cheats_menu(void *gt /*$s0*/, int index /*$s1*/)
 // line 428, offset 0x800b2f2c
	/* begin block 1 */
		// Start line: 429
		// Start offset: 0x800B2F2C
		// Variables:
	// 		int width; // $v0
	/* end block 1 */
	// End offset: 0x800B3034
	// End Line: 444

	/* begin block 2 */
		// Start line: 881
	/* end block 2 */
	// End Line: 882

int cheats_menu(void *gt,int index)

{
  menu_format(*(menu_t **)((int)gt + 0x20),0,0x15,0x1e,0x1eb,0xe,2,0);
  MENUFACE_ChangeStateRandomly(index);
  menu_item(*(menu_t **)((int)gt + 0x20),(TDRFuncPtr_menu_item1fn)0x0,0,"cheats");
  flags_item(gt,"activate all warpgates   ",0x400000);
  debug_item(gt,"disable monsters loading ",0x8000);
  flags_item(gt,"skip first puppet show   ",0x800000);
  debug_item(gt,"skip all puppet shows    ",0x800000);
  debug_item(gt,"show warp gate info      ",0x1000000);
  menu_item(*(menu_t **)((int)gt + 0x20),do_pop_menu,0,"return to main menu");
  if (index < 0) {
    index = 1;
  }
  return index;
}



// decompiled code
// original method signature: 
// int /*$ra*/ menudefs_toggle_dualshock(void *gt /*$s0*/, int index /*$s1*/)
 // line 903, offset 0x800b3048
	/* begin block 1 */
		// Start line: 1834
	/* end block 1 */
	// End Line: 1835

int menudefs_toggle_dualshock(void *gt,int index)

{
  int iVar1;
  
  iVar1 = GAMEPAD_DualShockEnabled();
  if (iVar1 == 0) {
    GAMEPAD_EnableDualShock();
    if (*(int *)((int)gt + 600) == 0) {
      *(undefined4 *)((int)gt + 600) = 1;
    }
    GAMEPAD_Shock1(0x80,*(int *)((int)gt + 600) << 3);
  }
  else {
    GAMEPAD_DisableDualShock();
  }
  if (index < 0) {
    index = 1;
  }
  return index;
}



// decompiled code
// original method signature: 
// int /*$ra*/ options_menu(void *gt /*$s0*/, int index /*$s1*/)
 // line 919, offset 0x800b30cc
	/* begin block 1 */
		// Start line: 1866
	/* end block 1 */
	// End Line: 1867

int options_menu(void *gt,int index)

{
  char *format;
  int iVar1;
  localstr_t id;
  
  hack_attract = 0;
  MENUFACE_ChangeStateRandomly(index);
  format = localstr_get(LOCALSTR_options);
  menu_item(*(menu_t **)((int)gt + 0x20),(TDRFuncPtr_menu_item1fn)0x0,0,format);
  format = localstr_get(LOCALSTR_sound);
  sound_item(gt,format,sfx_sound);
  format = localstr_get(LOCALSTR_music);
  sound_item(gt,format,sfx_music);
  format = localstr_get(LOCALSTR_voice);
  sound_item(gt,format,sfx_voice);
  iVar1 = GAMEPAD_DualShockEnabled();
  id = LOCALSTR_vibration_off;
  if (iVar1 != 0) {
    id = LOCALSTR_vibration_on;
  }
  format = localstr_get(id);
  menu_item(*(menu_t **)((int)gt + 0x20),do_function,(long)menudefs_toggle_dualshock,format);
  format = localstr_get(LOCALSTR_done);
  menu_item(*(menu_t **)((int)gt + 0x20),do_pop_menu,0,format);
  if (index < 0) {
    index = 1;
  }
  return index;
}



// decompiled code
// original method signature: 
// int /*$ra*/ main_menu(void *gt /*$s1*/, int index /*$s2*/)
 // line 976, offset 0x800b31d0
	/* begin block 1 */
		// Start line: 1980
	/* end block 1 */
	// End Line: 1981

int main_menu(void *gt,int index)

{
  char *format;
  
  hack_attract = 0;
  menu_format(*(menu_t **)((int)gt + 0x20),1,0x74,0x1e,0xbe,0xe,2,0);
  MENUFACE_ChangeStateRandomly(index);
  format = localstr_get(LOCALSTR_start_game);
  menu_item(*(menu_t **)((int)gt + 0x20),do_start_game,0,format);
  format = localstr_get(LOCALSTR_options);
  menu_item(*(menu_t **)((int)gt + 0x20),do_push_menu,(long)options_menu,format);
  menu_item(*(menu_t **)((int)gt + 0x20),do_push_menu,(long)cheats_menu,"cheats");
  if (index < 0) {
    index = 0;
  }
  return index;
}



// decompiled code
// original method signature: 
// int /*$ra*/ do_main_menu(void *gt /*$s0*/, long param /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
 // line 1006, offset 0x800b32b4
	/* begin block 1 */
		// Start line: 2044
	/* end block 1 */
	// End Line: 2045

int do_main_menu(void *gt,long param,menu_ctrl_t ctrl)

{
  int iVar1;
  
  if ((ctrl == menu_ctrl_start) || (iVar1 = 0, ctrl == menu_ctrl_engage)) {
    womp_background("\\kain2\\game\\psx\\bkgdmenu.tim");
    menu_pop(*(menu_t **)((int)gt + 0x20));
    menu_push(*(menu_t **)((int)gt + 0x20),main_menu);
    iVar1 = 1;
    hack_reset_attract = 1;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// char * /*$ra*/ flashStart()
 // line 1020, offset 0x800b331c
	/* begin block 1 */
		// Start line: 1021
		// Start offset: 0x800B331C
		// Variables:
	// 		static int flashTimer; // offset 0x14c
	// 		static int flashOn; // offset 0x150
	/* end block 1 */
	// End offset: 0x800B3384
	// End Line: 1043

	/* begin block 2 */
		// Start line: 2073
	/* end block 2 */
	// End Line: 2074

	/* begin block 3 */
		// Start line: 2079
	/* end block 3 */
	// End Line: 2080

/* WARNING: Unknown calling convention yet parameter storage is locked */

char * flashStart(void)

{
  char *pcVar1;
  
  DAT_800d0c94 = DAT_800d0c94 + 1;
  if (0xf < DAT_800d0c94) {
    if (DAT_800d0c98 == 0) {
      DAT_800d0c94 = 0;
    }
    else {
      DAT_800d0c94 = 10;
    }
    DAT_800d0c98 = DAT_800d0c98 ^ 1;
  }
  pcVar1 = (char *)0x0;
  if (DAT_800d0c98 != 0) {
    pcVar1 = localstr_get(LOCALSTR_start_game);
  }
  return pcVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ menudefs_main_menu(void *gt /*$s0*/, int index /*$s1*/)
 // line 1045, offset 0x800b3394
	/* begin block 1 */
		// Start line: 2129
	/* end block 1 */
	// End Line: 2130

	/* begin block 2 */
		// Start line: 2130
	/* end block 2 */
	// End Line: 2131

int menudefs_main_menu(void *gt,int index)

{
  char *format;
  
  if (hack_reset_attract != 0) {
    hack_reset_attract = 0;
    hack_attract = gameTrackerX.vblCount;
  }
  check_hack_attract();
  menu_format(*(menu_t **)((int)gt + 0x20),1,0x80,100,100,0xe,2,0);
  format = flashStart();
  menu_item(*(menu_t **)((int)gt + 0x20),do_main_menu,0,format);
  if (index < 0) {
    index = 0;
  }
  return index;
}



// decompiled code
// original method signature: 
// int /*$ra*/ menudefs_confirmexit_menu(void *gt /*$s0*/, int index /*$s1*/)
 // line 1069, offset 0x800b343c
	/* begin block 1 */
		// Start line: 2180
	/* end block 1 */
	// End Line: 2181

int menudefs_confirmexit_menu(void *gt,int index)

{
  char *format;
  
  hack_attract = 0;
  format = localstr_get(LOCALSTR_query_quit);
  menu_item(*(menu_t **)((int)gt + 0x20),(TDRFuncPtr_menu_item1fn)0x0,0,format);
  format = localstr_get(LOCALSTR_no);
  menu_item(*(menu_t **)((int)gt + 0x20),do_pop_menu,0,format);
  format = localstr_get(LOCALSTR_yes);
  menu_item(*(menu_t **)((int)gt + 0x20),do_function,(long)DEBUG_ExitGame,format);
  if (index < 0) {
    index = 1;
  }
  return index;
}



// decompiled code
// original method signature: 
// int /*$ra*/ menudefs_pause_menu(void *gt /*$s1*/, int index /*$s2*/)
 // line 1078, offset 0x800b34dc
	/* begin block 1 */
		// Start line: 2198
	/* end block 1 */
	// End Line: 2199

int menudefs_pause_menu(void *gt,int index)

{
  char *format;
  
  hack_attract = 0;
  menu_format(*(menu_t **)((int)gt + 0x20),1,0x100,0x3c,0x100,0xe,2,1);
  format = localstr_get(LOCALSTR_paused);
  menu_item(*(menu_t **)((int)gt + 0x20),(TDRFuncPtr_menu_item1fn)0x0,0,format);
  format = localstr_get(LOCALSTR_resume_game);
  menu_item(*(menu_t **)((int)gt + 0x20),do_function,(long)DEBUG_ContinueGame,format);
  format = localstr_get(LOCALSTR_save_game);
  menu_item(*(menu_t **)((int)gt + 0x20),do_save_menu,0,format);
  format = localstr_get(LOCALSTR_options);
  menu_item(*(menu_t **)((int)gt + 0x20),do_push_menu,(long)options_menu,format);
  format = localstr_get(LOCALSTR_quit_game);
  menu_item(*(menu_t **)((int)gt + 0x20),do_push_menu,(long)menudefs_confirmexit_menu,format);
  if (index < 0) {
    index = 1;
  }
  return index;
}





