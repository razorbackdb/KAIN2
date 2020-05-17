#include "THISDUST.H"
#include "MENUDEFS.H"


// decompiled code
// original method signature: 
// void /*$ra*/ do_check_controller(void *gt /*$a0*/)
 // line 161, offset 0x800b85f0
	/* begin block 1 */
		// Start line: 322
	/* end block 1 */
	// End Line: 323

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
 // line 177, offset 0x800b8624
	/* begin block 1 */
		// Start line: 178
		// Start offset: 0x800B8624
	/* end block 1 */
	// End offset: 0x800B864C
	// End Line: 191

	/* begin block 2 */
		// Start line: 354
	/* end block 2 */
	// End Line: 355

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
 // line 193, offset 0x800b865c
	/* begin block 1 */
		// Start line: 395
	/* end block 1 */
	// End Line: 396

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
 // line 204, offset 0x800b8694
	/* begin block 1 */
		// Start line: 414
	/* end block 1 */
	// End Line: 415

	/* begin block 2 */
		// Start line: 420
	/* end block 2 */
	// End Line: 421

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
 // line 218, offset 0x800b86c8
	/* begin block 1 */
		// Start line: 442
	/* end block 1 */
	// End Line: 443

	/* begin block 2 */
		// Start line: 451
	/* end block 2 */
	// End Line: 452

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
 // line 247, offset 0x800b872c
	/* begin block 1 */
		// Start line: 509
	/* end block 1 */
	// End Line: 510

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
 // line 274, offset 0x800b8768
	/* begin block 1 */
		// Start line: 547
	/* end block 1 */
	// End Line: 548

	/* begin block 2 */
		// Start line: 567
	/* end block 2 */
	// End Line: 568

void womp_background(char *tim_path)

{
  MEMPACK_Free((char *)mainMenuScreen);
  mainMenuScreen = MAIN_LoadTim(tim_path);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ play_movie(char *name /*$s0*/)
 // line 288, offset 0x800b87a0
	/* begin block 1 */
		// Start line: 289
		// Start offset: 0x800B87A0
	/* end block 1 */
	// End offset: 0x800B87D8
	// End Line: 308

	/* begin block 2 */
		// Start line: 602
	/* end block 2 */
	// End Line: 603

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
 // line 328, offset 0x800b87e8
	/* begin block 1 */
		// Start line: 682
	/* end block 1 */
	// End Line: 683

	/* begin block 2 */
		// Start line: 683
	/* end block 2 */
	// End Line: 684

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
 // line 333, offset 0x800b880c
	/* begin block 1 */
		// Start line: 692
	/* end block 1 */
	// End Line: 693

	/* begin block 2 */
		// Start line: 694
	/* end block 2 */
	// End Line: 695

/* WARNING: Unknown calling convention yet parameter storage is locked */

void check_hack_attract(void)

{
  if ((0 < hack_attract) && (hack_attract + 2000U < gameTrackerX.vblCount)) {
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
 // line 366, offset 0x800b887c
	/* begin block 1 */
		// Start line: 368
		// Start offset: 0x800B887C
		// Variables:
	// 		int raw; // $a2
	/* end block 1 */
	// End offset: 0x800B88B8
	// End Line: 374

	/* begin block 2 */
		// Start line: 762
	/* end block 2 */
	// End Line: 763

	/* begin block 3 */
		// Start line: 763
	/* end block 3 */
	// End Line: 764

	/* begin block 4 */
		// Start line: 764
	/* end block 4 */
	// End Line: 765

int get_volume(void *gt,sfx_t sfx)

{
  int iVar1;
  
  if (sfx == sfx_sound) {
    iVar1 = *(int *)((int)gt + 0x1b8);
  }
  else {
    if (sfx == sfx_music) {
      iVar1 = *(int *)((int)gt + 0x1b4);
    }
    else {
      iVar1 = 3;
      if (sfx == sfx_voice) {
        iVar1 = *(int *)((int)gt + 0x1bc);
      }
    }
  }
  return (iVar1 * 10) / 0x7f;
}



// decompiled code
// original method signature: 
// void /*$ra*/ set_volume(enum sfx_t sfx /*$a2*/, int cooked /*$a1*/)
 // line 377, offset 0x800b88e8
	/* begin block 1 */
		// Start line: 378
		// Start offset: 0x800B88E8
		// Variables:
	// 		int raw; // $a0
	/* end block 1 */
	// End offset: 0x800B8964
	// End Line: 386

	/* begin block 2 */
		// Start line: 784
	/* end block 2 */
	// End Line: 785

	/* begin block 3 */
		// Start line: 785
	/* end block 3 */
	// End Line: 786

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
 // line 388, offset 0x800b8974
	/* begin block 1 */
		// Start line: 389
		// Start offset: 0x800B8974
		// Variables:
	// 		int volume; // $a1
	/* end block 1 */
	// End offset: 0x800B89DC
	// End Line: 409

	/* begin block 2 */
		// Start line: 807
	/* end block 2 */
	// End Line: 808

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
 // line 411, offset 0x800b89f0
	/* begin block 1 */
		// Start line: 412
		// Start offset: 0x800B89F0
	/* end block 1 */
	// End offset: 0x800B89F0
	// End Line: 412

	/* begin block 2 */
		// Start line: 853
	/* end block 2 */
	// End Line: 854

void sound_item(void *gt,char *text,sfx_t sfx)

{
  get_volume(gt,sfx);
  menu_item(*(menu_t **)((int)gt + 0x20),do_sound_adjust,sfx,"%s %d");
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ menudefs_toggle_dualshock(void *gt /*$a0*/, long param /*$a1*/, enum menu_ctrl_t ctrl /*$a2*/)
 // line 1014, offset 0x800b8a54
	/* begin block 1 */
		// Start line: 2059
	/* end block 1 */
	// End Line: 2060

int menudefs_toggle_dualshock(void *gt,long param,menu_ctrl_t ctrl)

{
  int iVar1;
  
  if (ctrl + ~menu_ctrl_down < 2) {
    iVar1 = GAMEPAD_DualShockEnabled();
    if (iVar1 == 0) {
      GAMEPAD_EnableDualShock();
      GAMEPAD_Shock1(0x80,0x8000);
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
 // line 1032, offset 0x800b8ab8
	/* begin block 1 */
		// Start line: 1033
		// Start offset: 0x800B8AB8
		// Variables:
	// 		static int wasDualShock; // offset 0x0
	// 		int dualShock; // $s0
	/* end block 1 */
	// End offset: 0x800B8BE8
	// End Line: 1094

	/* begin block 2 */
		// Start line: 2095
	/* end block 2 */
	// End Line: 2096

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
 // line 1111, offset 0x800b8c00
	/* begin block 1 */
		// Start line: 2253
	/* end block 1 */
	// End Line: 2254

int main_menu(void *gt,int index)

{
  char *format;
  
  hack_attract = 0;
  menu_format(*(menu_t **)((int)gt + 0x20),1,0x87,0x1e,0xac,0xe,2,0);
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
 // line 1143, offset 0x800b8cc4
	/* begin block 1 */
		// Start line: 2325
	/* end block 1 */
	// End Line: 2326

	/* begin block 2 */
		// Start line: 2326
	/* end block 2 */
	// End Line: 2327

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
 // line 1159, offset 0x800b8d18
	/* begin block 1 */
		// Start line: 1160
		// Start offset: 0x800B8D18

		/* begin block 1.1 */
			// Start line: 1184
			// Start offset: 0x800B8D98
			// Variables:
		// 		static int counter; // offset 0x98
		// 		int intpl; // $a0
		// 		int fcols[2][3]; // stack offset -40
		// 		int r; // $s2
		// 		int g; // $s1
		// 		int b; // $s0
		/* end block 1.1 */
		// End offset: 0x800B8EFC
		// End Line: 1206
	/* end block 1 */
	// End offset: 0x800B8F04
	// End Line: 1209

	/* begin block 2 */
		// Start line: 2361
	/* end block 2 */
	// End Line: 2362

/* WARNING: Unknown calling convention yet parameter storage is locked */

char * flashStart(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
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
      return (char *)0x0;
    }
    goto LAB_800b8efc;
  }
  DAT_800d1fe8 = (DAT_800d1fe8 + 1) % 0x3c;
  if (DAT_800d1fe8 < 10) {
    iVar3 = 0;
  }
  else {
    if (DAT_800d1fe8 < 0x1e) {
      iVar3 = DAT_800d1fe8 + -10;
    }
    else {
      if (DAT_800d1fe8 < 0x28) {
        iVar3 = 0x1000;
        goto LAB_800b8e64;
      }
      iVar3 = 0x3c - DAT_800d1fe8;
    }
    iVar3 = (iVar3 << 0xc) / 0x14;
  }
LAB_800b8e64:
  iVar2 = 0x1000 - iVar3;
  FONT_SetColorIndex(4);
  FONT_SetColorIndexCol
            (4,iVar2 * 0xc0 + iVar3 * 0xc0 >> 0xc,iVar2 * 0xd2 + iVar3 * 0xc0 >> 0xc,
             iVar2 * 0xd2 + iVar3 * 0x40 >> 0xc);
LAB_800b8efc:
  pcVar1 = localstr_get(LOCALSTR_press_start);
  return pcVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ menudefs_main_menu(void *gt /*$s0*/, int index /*$s1*/)
 // line 1211, offset 0x800b8f1c
	/* begin block 1 */
		// Start line: 2480
	/* end block 1 */
	// End Line: 2481

	/* begin block 2 */
		// Start line: 2481
	/* end block 2 */
	// End Line: 2482

int menudefs_main_menu(void *gt,int index)

{
  char *format;
  
  if (hack_reset_attract != 0) {
    hack_reset_attract = 0;
    hack_attract = gameTrackerX.vblCount;
  }
  check_hack_attract();
  menu_format(*(menu_t **)((int)gt + 0x20),1,0x16e,0x90,100,0xe,2,0);
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
 // line 1242, offset 0x800b8fc4
	/* begin block 1 */
		// Start line: 2545
	/* end block 1 */
	// End Line: 2546

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
 // line 1253, offset 0x800b906c
	/* begin block 1 */
		// Start line: 2567
	/* end block 1 */
	// End Line: 2568

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
  if ((gameTrackerX.streamFlags & 4U) == 0) {
    format = localstr_get(LOCALSTR_save_game);
    menu_item(*(menu_t **)((int)gt + 0x20),do_save_menu,0,format);
    format = localstr_get(LOCALSTR_options);
    menu_item(*(menu_t **)((int)gt + 0x20),do_push_menu,(long)options_menu,format);
    format = localstr_get(LOCALSTR_quit_game);
    menu_item(*(menu_t **)((int)gt + 0x20),do_push_menu,(long)menudefs_confirmexit_menu,format);
  }
  if (index < 0) {
    index = 1;
  }
  return index;
}





