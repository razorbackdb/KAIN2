#include "THISDUST.H"
#include "MENUDEFS.H"


// decompiled code
// original method signature: 
// void /*$ra*/ do_check_controller(void *gt /*$a0*/)
 // line 147, offset 0x800b7274
	/* begin block 1 */
		// Start line: 294
	/* end block 1 */
	// End Line: 295

void do_check_controller(void *gt)

{
  int msgY;
  
  msgY = 200;
  if (*(short *)((int)gt + 0x172) == 6) {
    msgY = 0xaa;
  }
  GAMEPAD_DisplayControllerStatus(msgY);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ do_push_menu(void *gt /*$a0*/, long menuparam /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
 // line 163, offset 0x800b72a8
	/* begin block 1 */
		// Start line: 164
		// Start offset: 0x800B72A8
	/* end block 1 */
	// End offset: 0x800B72D0
	// End Line: 177

	/* begin block 2 */
		// Start line: 326
	/* end block 2 */
	// End Line: 327

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
 // line 179, offset 0x800b72e0
	/* begin block 1 */
		// Start line: 367
	/* end block 1 */
	// End Line: 368

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
 // line 190, offset 0x800b7318
	/* begin block 1 */
		// Start line: 386
	/* end block 1 */
	// End Line: 387

	/* begin block 2 */
		// Start line: 392
	/* end block 2 */
	// End Line: 393

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
 // line 204, offset 0x800b734c
	/* begin block 1 */
		// Start line: 414
	/* end block 1 */
	// End Line: 415

	/* begin block 2 */
		// Start line: 423
	/* end block 2 */
	// End Line: 424

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
 // line 230, offset 0x800b73b0
	/* begin block 1 */
		// Start line: 475
	/* end block 1 */
	// End Line: 476

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
 // line 257, offset 0x800b73ec
	/* begin block 1 */
		// Start line: 513
	/* end block 1 */
	// End Line: 514

	/* begin block 2 */
		// Start line: 533
	/* end block 2 */
	// End Line: 534

void womp_background(char *tim_path)

{
  MEMPACK_Free((char *)mainMenuScreen);
  mainMenuScreen = MAIN_LoadTim(tim_path);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ play_movie(char *name /*$s0*/)
 // line 271, offset 0x800b7424
	/* begin block 1 */
		// Start line: 272
		// Start offset: 0x800B7424
	/* end block 1 */
	// End offset: 0x800B745C
	// End Line: 291

	/* begin block 2 */
		// Start line: 568
	/* end block 2 */
	// End Line: 569

void play_movie(char *name)

{
  int iVar1;
  
  iVar1 = CINE_Load();
  if (iVar1 != 0) {
    CINE_Play(name,0xffff,2);
    CINE_Unload();
    MAIN_InitVolume();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ menudefs_reset_hack_attract_mode()
 // line 311, offset 0x800b746c
	/* begin block 1 */
		// Start line: 648
	/* end block 1 */
	// End Line: 649

	/* begin block 2 */
		// Start line: 649
	/* end block 2 */
	// End Line: 650

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
 // line 316, offset 0x800b7490
	/* begin block 1 */
		// Start line: 658
	/* end block 1 */
	// End Line: 659

	/* begin block 2 */
		// Start line: 660
	/* end block 2 */
	// End Line: 661

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
 // line 341, offset 0x800b7518
	/* begin block 1 */
		// Start line: 343
		// Start offset: 0x800B7518
		// Variables:
	// 		int raw; // $a2
	/* end block 1 */
	// End offset: 0x800B7554
	// End Line: 349

	/* begin block 2 */
		// Start line: 712
	/* end block 2 */
	// End Line: 713

	/* begin block 3 */
		// Start line: 713
	/* end block 3 */
	// End Line: 714

	/* begin block 4 */
		// Start line: 714
	/* end block 4 */
	// End Line: 715

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
 // line 352, offset 0x800b7584
	/* begin block 1 */
		// Start line: 353
		// Start offset: 0x800B7584
		// Variables:
	// 		int raw; // $a0
	/* end block 1 */
	// End offset: 0x800B7600
	// End Line: 361

	/* begin block 2 */
		// Start line: 734
	/* end block 2 */
	// End Line: 735

	/* begin block 3 */
		// Start line: 735
	/* end block 3 */
	// End Line: 736

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
 // line 363, offset 0x800b7610
	/* begin block 1 */
		// Start line: 364
		// Start offset: 0x800B7610
		// Variables:
	// 		int volume; // $a1
	/* end block 1 */
	// End offset: 0x800B7678
	// End Line: 384

	/* begin block 2 */
		// Start line: 757
	/* end block 2 */
	// End Line: 758

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
 // line 386, offset 0x800b768c
	/* begin block 1 */
		// Start line: 387
		// Start offset: 0x800B768C
	/* end block 1 */
	// End offset: 0x800B768C
	// End Line: 387

	/* begin block 2 */
		// Start line: 803
	/* end block 2 */
	// End Line: 804

void sound_item(void *gt,char *text,sfx_t sfx)

{
  get_volume(gt,sfx);
  menu_item(*(menu_t **)((int)gt + 0x20),do_sound_adjust,sfx,"%s %d");
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ menudefs_toggle_dualshock(void *gt /*$s0*/, long param /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
 // line 989, offset 0x800b76f0
	/* begin block 1 */
		// Start line: 2009
	/* end block 1 */
	// End Line: 2010

int menudefs_toggle_dualshock(void *gt,long param,menu_ctrl_t ctrl)

{
  int iVar1;
  
  if (ctrl + ~menu_ctrl_down < 2) {
    iVar1 = GAMEPAD_DualShockEnabled();
    if (iVar1 == 0) {
      GAMEPAD_EnableDualShock();
      if (*(int *)((int)gt + 0x248) == 0) {
        *(undefined4 *)((int)gt + 0x248) = 1;
      }
      GAMEPAD_Shock1(0x80,*(int *)((int)gt + 0x248) << 3);
      iVar1 = 1;
    }
    else {
      GAMEPAD_DisableDualShock();
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
// int /*$ra*/ options_menu(void *gt /*$s1*/, int index /*$s2*/)
 // line 1009, offset 0x800b7774
	/* begin block 1 */
		// Start line: 1010
		// Start offset: 0x800B7774
		// Variables:
	// 		static int wasDualShock; // offset 0x0
	// 		int dualShock; // $s0
	/* end block 1 */
	// End offset: 0x800B78A4
	// End Line: 1068

	/* begin block 2 */
		// Start line: 2049
	/* end block 2 */
	// End Line: 2050

int options_menu(void *gt,int index)

{
  char *format;
  int iVar1;
  int iVar2;
  localstr_t id;
  
  hack_attract = 0;
  MENUFACE_ChangeStateRandomly(index);
  do_check_controller(gt);
  format = localstr_get(LOCALSTR_options);
  menu_item_flags(*(menu_t **)((int)gt + 0x20),(TDRFuncPtr_menu_item_flags1fn)0x0,0,4,format);
  format = localstr_get(LOCALSTR_sound);
  sound_item(gt,format,sfx_sound);
  format = localstr_get(LOCALSTR_music);
  sound_item(gt,format,sfx_music);
  format = localstr_get(LOCALSTR_voice);
  sound_item(gt,format,sfx_voice);
  iVar1 = GAMEPAD_ControllerIsDualShock();
  if (iVar1 != 0) {
    iVar2 = GAMEPAD_DualShockEnabled();
    id = LOCALSTR_vibration_off;
    if (iVar2 != 0) {
      id = LOCALSTR_vibration_on;
    }
    format = localstr_get(id);
    menu_item(*(menu_t **)((int)gt + 0x20),menudefs_toggle_dualshock,0,format);
  }
  format = localstr_get(LOCALSTR_done);
  menu_item(*(menu_t **)((int)gt + 0x20),do_pop_menu,0,format);
  if ((iVar1 != wasDualShock_54) && (3 < index)) {
    index = iVar1 + 4;
  }
  if (index < 0) {
    index = 1;
  }
  wasDualShock_54 = iVar1;
  return index;
}



// decompiled code
// original method signature: 
// int /*$ra*/ main_menu(void *gt /*$s0*/, int index /*$s1*/)
 // line 1085, offset 0x800b78bc
	/* begin block 1 */
		// Start line: 2201
	/* end block 1 */
	// End Line: 2202

int main_menu(void *gt,int index)

{
  char *format;
  
  hack_attract = 0;
  menu_format(*(menu_t **)((int)gt + 0x20),1,0x74,0x1e,0xbe,0xe,2,0);
  MENUFACE_ChangeStateRandomly(index);
  do_check_controller(gt);
  format = localstr_get(LOCALSTR_start_game);
  menu_item(*(menu_t **)((int)gt + 0x20),do_start_game,0,format);
  format = localstr_get(LOCALSTR_options);
  menu_item(*(menu_t **)((int)gt + 0x20),do_push_menu,(long)options_menu,format);
  if (index < 0) {
    index = 0;
  }
  return index;
}



// decompiled code
// original method signature: 
// int /*$ra*/ do_main_menu(void *gt /*$a0*/, long param /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
 // line 1114, offset 0x800b7980
	/* begin block 1 */
		// Start line: 2263
	/* end block 1 */
	// End Line: 2264

	/* begin block 2 */
		// Start line: 2264
	/* end block 2 */
	// End Line: 2265

int do_main_menu(void *gt,long param,menu_ctrl_t ctrl)

{
  if ((StartGameFading == 0) && ((ctrl == menu_ctrl_start || (ctrl == menu_ctrl_engage)))) {
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
 // line 1130, offset 0x800b79d4
	/* begin block 1 */
		// Start line: 1131
		// Start offset: 0x800B79D4
		// Variables:
	// 		static int flashTimer; // offset 0x78
	// 		static int flashOn; // offset 0x7c
	/* end block 1 */
	// End offset: 0x800B7AB0
	// End Line: 1167

	/* begin block 2 */
		// Start line: 2299
	/* end block 2 */
	// End Line: 2300

/* WARNING: Unknown calling convention yet parameter storage is locked */

char * flashStart(void)

{
  char *pcVar1;
  
  gameTrackerX.gameFramePassed = 1;
  if (StartGameFading == 1) {
    hack_reset_attract = StartGameFading;
    if (gameTrackerX.wipeTime == -1) {
      womp_background("\\kain2\\game\\psx\\bkgdmenu.tim");
      gameTrackerX.wipeType = 10;
      gameTrackerX.wipeTime = 0x14;
      gameTrackerX.maxWipeTime = 0x14;
      StartGameFading = 0;
      menu_pop(gameTrackerX.menu);
      menu_push(gameTrackerX.menu,main_menu);
    }
    DAT_800d0d40 = 0;
  }
  else {
    DAT_800d0d3c = DAT_800d0d3c + 1;
    if (0xf < DAT_800d0d3c) {
      if (DAT_800d0d40 == 0) {
        DAT_800d0d3c = 0;
      }
      else {
        DAT_800d0d3c = 10;
      }
      DAT_800d0d40 = DAT_800d0d40 ^ 1;
    }
  }
  pcVar1 = (char *)0x0;
  if (DAT_800d0d40 != 0) {
    pcVar1 = localstr_get(LOCALSTR_press_start);
  }
  return pcVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ menudefs_main_menu(void *gt /*$s0*/, int index /*$s1*/)
 // line 1169, offset 0x800b7ac0
	/* begin block 1 */
		// Start line: 2389
	/* end block 1 */
	// End Line: 2390

	/* begin block 2 */
		// Start line: 2390
	/* end block 2 */
	// End Line: 2391

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
 // line 1193, offset 0x800b7b68
	/* begin block 1 */
		// Start line: 2440
	/* end block 1 */
	// End Line: 2441

int menudefs_confirmexit_menu(void *gt,int index)

{
  char *format;
  
  hack_attract = 0;
  do_check_controller(gt);
  format = localstr_get(LOCALSTR_query_quit);
  menu_item_flags(*(menu_t **)((int)gt + 0x20),(TDRFuncPtr_menu_item_flags1fn)0x0,0,4,format);
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
 // line 1204, offset 0x800b7c10
	/* begin block 1 */
		// Start line: 2462
	/* end block 1 */
	// End Line: 2463

int menudefs_pause_menu(void *gt,int index)

{
  char *format;
  
  do_check_controller(gt);
  hack_attract = 0;
  menu_format(*(menu_t **)((int)gt + 0x20),1,0x100,0x3c,0x100,0xe,2,1);
  format = localstr_get(LOCALSTR_paused);
  menu_item_flags(*(menu_t **)((int)gt + 0x20),(TDRFuncPtr_menu_item_flags1fn)0x0,0,4,format);
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





