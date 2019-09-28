//#include "THISDUST.H"
#include "MAIN.H"
#include <stdbool.h>

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

/*  void ClearDisplay(void)

{
  PutDrawEnv(&debugRazielFlags2 + theCamera.core.vvNormalWorVecMat[0].m[2]._0_4_ * 0x17);
  *(undefined *)(&ACE_amount + theCamera.core.vvNormalWorVecMat[0].m[2]._0_4_ * 4) = 0;
  *(undefined *)((int)&ACE_amount + theCamera.core.vvNormalWorVecMat[0].m[2]._0_4_ * 0x10 + 1) = 0;
  *(undefined *)((int)&ACE_amount + theCamera.core.vvNormalWorVecMat[0].m[2]._0_4_ * 0x10 + 2) = 0;
  DrawPrim((int)(&hitline_rot + theCamera.core.vvNormalWorVecMat[0].m[2]._0_4_ * 8));
                    /* WARNING: Subroutine does not return */
/* DrawSync(0);
}*/

// decompiled code
// original method signature:
// void /*$ra*/ screen_to_vram(long *screen /*$a0*/, int buffer /*$a1*/)
// line 150, offset 0x80037fb4
/* begin block 1 */
// Start line: 302
/* end block 1 */
// End Line: 303

/* void screen_to_vram(long *screen, int buffer)

{
	LOAD_LoadTIM2(screen, 0, buffer << 8, 0x200, 0x100);
	return;
} */

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

/* void show_screen(char *name)

{
	long *screen;

	screen = LOAD_ReadFile(name, '\v');
	if (screen != (long *)0x0)
	{
		screen_to_vram(screen, (short)theCamera.core.vvNormalWorVecMat[0].m[2]);
		/* WARNING: Subroutine does not return */
/* 		MEMPACK_Free((char *)screen);
	}
	return;
} */

// decompiled code
// original method signature:
// void /*$ra*/ play_movie(char *name /*$s0*/)
// line 214, offset 0x80038028
/* begin block 1 */
// Start line: 435
/* end block 1 */
// End Line: 436

/* void play_movie(char *name)

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
} */

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

/* void InitMainTracker(MainTracker *mainTracker)

{
	mainTracker->mainState = 0;
	mainTracker->previousState = 0;
	mainTracker->done = 0;
	return;
} */

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

/* char *FindTextInLine(char *search_match, char *search_str)

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
} */

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

/* void ExtractWorldName(char *worldName, char *levelName)

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
} */

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

/* void ExtractLevelNum(char *levelNum, char *levelName)

{
	byte bVar1;

	bVar1 = *levelName;
	while (true)
	{
		if (bVar1 == 0x2d)
		{
			LOAD_InitBuffers();
			return;
		}
		if ((uint)bVar1 - 0x30 < 10)
			break;
		levelName = (char *)((byte *)levelName + 1);
		bVar1 = *levelName;
	}
	do
	{
		bVar1 = *levelName;
		levelName = (char *)((byte *)levelName + 1);
		*levelNum = bVar1;
		levelNum = (char *)((byte *)levelNum + 1);
	} while ((uint)(byte)*levelName - 0x30 < 10);
	*levelNum = 0;
	return;
} */

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

/* void ProcessArgs(char *baseAreaName, GameTracker *gameTracker)

{
	long *levelName;
	char *id;
	char acStack88[32];
	char acStack56[32];

	id = "s__kain2_game_psx_kain2_arg_800ce6d4";
	levelName = LOAD_ReadFile(s__kain2_game_psx_kain2_arg_800ce6d4, '\n');
	if (levelName == (long *)0x0)
	{
		LOAD_SetSearchDirectory((long)id);
		return;
	}
	ExtractWorldName(acStack56, (char *)levelName);
	ExtractLevelNum(acStack88, (char *)levelName);
	/* WARNING: Subroutine does not return */
/* 	sprintf(baseAreaName, "&DAT_800ce6f0");
} */

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

/* void InitDisplay(void)

{
	ResetGraph(3);
	SetGraphDebug(0);
	//SetDefDrawEnv((undefined2 *)&debugRazielFlags2, 0, 0, 0x200, 0xf0);
	/* WARNING: Subroutine does not return */
	//SetDefDispEnv((undefined2 *)&debugOrgFogRed, 0, 0, 0x200, 0xf0);
/* } */

// decompiled code
// original method signature:
// void /*$ra*/ StartTimer()
// line 666, offset 0x80038554
/* begin block 1 */
// Start line: 1326
/* end block 1 */
// End Line: 1327

/* WARNING: Unknown calling convention yet parameter storage is locked */

/* void StartTimer(void)

{
	/* WARNING: Subroutine does not return */
	/* EnterCriticalSection(); */
/* } */

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

/* void VblTick(void)

{
	if (debugRazielFlags1 != 0)
	{
		trap(0x400);
	}
	theCamera._324_4_ = theCamera._324_4_ + 1;
	theCamera.positionVel._0_4_ = theCamera.positionVel._0_4_ + 1;
	if ((theCamera.focusInstanceVelVec._0_4_ != (ushort *)0x0) &&
		(theCamera._632_4_ < theCamera._324_4_))
	{
		PutDispEnv(theCamera.focusInstanceVelVec._0_4_);
		theCamera.focusInstanceVelVec._0_4_ = (ushort *)0x0;
		theCamera._324_4_ = 0;
	}
	return;
} */

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

/* void DrawCallback(void)

{
	ulong uVar1;

	if (theCamera.focusInstanceVelVec._4_4_ != (ulong *)0x0)
	{
		uVar1 = TIMER_TimeDiff(theCamera.focusLeadPivot._0_4_);
		*theCamera.focusInstanceVelVec._4_4_ = uVar1;
		theCamera.focusInstanceVelVec._4_4_ = (ulong *)0x0;
		theCamera.focusInstanceVelVec._0_4_ =
			theCamera._308_4_ + theCamera.core.vvNormalWorVecMat[0].m[2]._0_4_ * 0x14;
	}
	return;
} */

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

/* void ProcessArgs(char *baseAreaName, GameTracker *gameTracker)

{
	/* WARNING: Subroutine does not return */
/* 	DRAW_TranslucentQuad(0, 0, 0x200, 0, 0, 0xf0, 0x200, 0xf0, 0, 0, 0, 2, *(_PrimPool **)(baseAreaName + 0x40),
						 *(ulong ***)(baseAreaName + 0x1d4));
}  */

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
	//debugRazielFlags1 = 1;
	//DAT_80180000 = 0;
	//_DAT_80380000 = 0x12345678;
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

/* void MAIN_ShowLoadingScreen(void)

{
	language_t lVar1;
	long *screen;
	char acStack80[64];

	VSync(0);
	lVar1 = localstr_get_language();
	if (lVar1 != language_english)
	{
		/* WARNING: Subroutine does not return */
/* 		sprintf(acStack80, s__kain2_game_psx_loading_c_tim_800ce778);
	}
	screen = LOAD_ReadFile(s__kain2_game_psx_loading_tim_800ce798, '\v');
	if (screen == (long *)0x0)
	{
		InitDisplay();
		return;
	}
	screen_to_vram(screen, theCamera.core.vvNormalWorVecMat[0].m[2]._0_4_);
	/* WARNING: Subroutine does not return */
/* 	MEMPACK_Free((char *)screen);
}  */

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

/* void MAIN_LoadTim(char *param_1)

{
	LOAD_ReadFile(param_1, '\v');
	return;
} */

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

/* void init_menus(GameTracker *gt)

{
	ulong allocSize;

	allocSize = menu_data_size();
	/* WARNING: Subroutine does not return */
/* 	MEMPACK_Malloc(allocSize, '-');
} */

// decompiled code
// original method signature:
// void /*$ra*/ MAIN_DoMainInit()
// line 902, offset 0x80038950
/* begin block 1 */
// Start line: 1850
/* end block 1 */
// End Line: 1851

/* WARNING: Unknown calling convention yet parameter storage is locked */

/* void MAIN_DoMainInit(void)

{
	InitDisplay();
	InitGeom();
	SetGeomOffset(0x100, 0x78);
	SetGeomScreen(0x140);
	VRAM_InitVramBlockCache();
	FONT_Init();
	theCamera.focusInstanceVelVec._0_4_ = 0;
	VSyncCallback(VblTick);
	DrawSyncCallback(DrawCallback);
	GAMEPAD_Init();
	SOUND_Init();
	VOICEXA_Init();
	if (nosound != 0)
	{
		SOUND_SfxOff();
		theCamera.focusSphere.position.z._0_1_ = 0;
		theCamera.focusSphere.radius._0_1_ = 0;
	}
	if (nomusic != 0)
	{
		SOUND_MusicOff();
		theCamera.focusSphere.position.z._1_1_ = 0;
	}
	if ((theCamera.core.debugRot._4_4_ & 0x80000) == 0)
	{
		theCamera.focusSphere.radius._0_1_ = 0;
	}
	init_menus((GameTracker *)(theCamera.core.vvNormalWorVecMat[0].m + 4));
	SAVE_Init((GameTracker *)(theCamera.core.vvNormalWorVecMat[0].m + 4));
	srand(0);
	return;
} */

// decompiled code
// original method signature:
// void /*$ra*/ MAIN_InitVolume()
// line 949, offset 0x80038a44
/* begin block 1 */
// Start line: 1898
/* end block 1 */
// End Line: 1899

/* WARNING: Unknown calling convention yet parameter storage is locked */

/* void MAIN_InitVolume(void)

{
	aadInitVolume();
	aadStartMasterVolumeFade(theCamera.collisionTargetFocusRotation._4_4_, 0x100,
							 (TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback)0x0);
	theCamera.focusSphere.radius._1_1_ = 1;
	aadSetNoUpdateMode(0);
	return;
} */

// decompiled code
// original method signature:
// void /*$ra*/ MAIN_ResetGame()
// line 957, offset 0x80038a84
/* begin block 1 */
// Start line: 1944
/* end block 1 */
// End Line: 1945

/* WARNING: Unknown calling convention yet parameter storage is locked */

/* void MAIN_ResetGame(void)

{
	GAMELOOP_SetScreenWipe(0, 0, -1);
	theCamera.positionAccl._0_4_ = theCamera.positionAccl._0_4_ & 0xffffff6e;
	RAZIEL_StartNewGame();
	return;
} */

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
/* 	undefined4 *puVar1;
	undefined4 *puVar2;
	undefined4 *puVar3;
	undefined4 *puVar4;
	undefined4 uVar5;
	undefined4 uVar6;
	undefined4 uVar7;
	undefined4 local_48[10];
	undefined auStack32[24];

	mainMenuMode = 0;
	theCamera.core.vvNormalWorVecMat[0].m[0][2] = 0;
	ACE_amount._0_1_ = 0;
	ACE_amount._1_1_ = 0;
	ACE_amount._2_1_ = 0;
	theCamera.core.position.x._0_1_ = 0;
	theCamera.core.position.x._1_1_ = 0;
	theCamera.core.position.y._0_1_ = 0;
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
/* 	puVar4[5] = uVar5;
	memset(auStack32, 0, 0x18); */
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

/* void MAIN_FreeMainMenuStuff(void)

{
	int iVar1;
	void *loadedDataPtr;
	long in_a1;
	short in_a2;
	void *in_a3;
	void *local_8;

	menuface_terminate();
	VRAM_DisableTerrainArea();
	if (mainMenuScreen != (long *)0x0)
	{
		/* WARNING: Subroutine does not return */
/* 		MEMPACK_Free((char *)mainMenuScreen);
	}
	loadedDataPtr = (void *)mainMenuSfx;
	aadFreeDynamicSfx(mainMenuSfx);
	while (iVar1 = aadGetNumLoadsQueued(), iVar1 != 0)
	{
		aadLoadDynamicSoundBankReturn2(loadedDataPtr, in_a1, in_a2, in_a3, local_8);
	}
	return;
} */

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

/* WARNING: Unknown calling convention yet parameter storage is locked */

/* void MAIN_StartGame(void)

{
	if (mainMenuFading == 0)
	{
		theCamera.maxFocusVel.pad = 0;
		currentMenu = (DebugMenuLine *)0x0;
		mainMenuFading = 1;
		GAMELOOP_SetScreenWipe(-0x1e, 0x1e, 10);
	}
	else
	{
		theCamera.savedMode[1] = 2;
		MAIN_FreeMainMenuStuff();
		gEndGameNow = 0;
		mainMenuFading = 0;
		currentMenu = &standardMenu;
	}
	return;
} */

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

/* void MAIN_ShowLoadingScreen(void)

{
	GameTracker *in_a0;
	ulong **drawot;

	/* WARNING: Read-only address (ram,0x800d19f4) is written */
/* 	fontTracker.font_buffer[127]._2_4_ = 0x1000;
	drawot = in_a0->drawOT;
	DrawPrim(in_a0->drawPage * 0x10 + -0x7ff2e870);
	GAMEPAD_Process(in_a0);
	DEBUG_Process(in_a0);
	if (cem_item_leading != 0)
	{
		screen_to_vram((long *)cem_item_leading, in_a0->drawPage);
	}
	GAMELOOP_HandleScreenWipes(drawot);
	MENUFACE_RefreshFaces();
	FONT_Flush();
	fontTracker.font_buffer[30]._4_2_ = fontTracker.font_buffer[30]._4_2_ + 1;
	/* WARNING: Read-only address (ram,0x800d17b0) is written */
/* 	GAMELOOP_FlipScreenAndDraw(in_a0, drawot);
	if ((DAT_800ceeda != 0) && (in_a0->wipeTime == -1))
	{
		MAIN_StartGame();
	}
	return;
} */

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

int MainG2(void *appData)

{
	bool bVar1;
	long lVar2;
	G2Bool _Var3;
	int iVar4;
	uint uVar5;
	GameTracker *gameTracker;
	GameTracker *pGVar6;

	CheckForDevStation();
	pGVar6 = (GameTracker *)(theCamera.core.vvNormalWorVecMat[0].m + 4);
	char mainOptionsInit = '\0';
	_Var3 = MainG2_InitEngine(appData, 0x200, 0xf0, (char *)0x0);
	if (_Var3 == G2FALSE)
	{
		MainG2_ShutDownEngine(appData);
		return 0;
	}
	//MEMPACK_Init();
	//LOAD_InitCd();
	StartTimer();
	//STREAM_InitLoader("\\BIGFILE.DAT;1", "\\VOICE;1");
	//localstr_set_language(~language_english);
	GAMELOOP_SystemInit((GameTracker *)(theCamera.core.vvNormalWorVecMat[0].m + 4));
	theCamera.smallBaseSphere.position.x = 0xff;
	theCamera.smallBaseSphere.position.x = 0xff;
	//theCamera = &debugOrgFogRed;
	gameTracker = pGVar6;
	ProcessArgs((char *)&theCamera.focusRotVel,
				(GameTracker *)(theCamera.core.vvNormalWorVecMat[0].m + 4));
	InitMainTracker((MainTracker *)(theCamera.savedMode + 1));
	MAIN_DoMainInit();
	theCamera.savedMode[1] = 6;
	theCamera.savedTargetFocusDistance[0] = 0;
/* 	do
	{
		theCamera.savedMode[2] = theCamera.savedMode[1];
		switch (theCamera.savedMode[1])
		{
		case 1:
			SOUND_UpdateSound();
			if ((theCamera.core.debugRot._4_4_ & 0x80000) != 0)
			{
				VOICEXA_Tick();
			}
			PSX_GameLoop((GameTracker *)(theCamera.core.vvNormalWorVecMat[0].m + 4));
			if (theCamera.maxFocusVel.x != 0)
			{
				ProcessArgs((char *)(theCamera.core.vvNormalWorVecMat[0].m + 4), gameTracker);
				aadStopAllSfx();
				gameTracker = (GameTracker *)0x0;
				STREAM_DumpAllLevels(0, 0);
				RemoveAllObjects((GameTracker *)(theCamera.core.vvNormalWorVecMat[0].m + 4));
				while ((iVar4 = aadGetNumLoadsQueued(), iVar4 != 0 || ((aadMem->sramDefragInfo).status != 0)))
				{
					SOUND_UpdateSound();
					STREAM_PollLoadQueue();
				}
				SOUND_ShutdownMusic();
				MEMPACK_FreeByType('\x0e');
				GAMELOOP_ResetGameStates();
				MEMPACK_DoGarbageCollection();
				iVar4 = (int)theCamera.maxFocusVel.x;
				if (iVar4 == 2)
				{
				LAB_8003933c:
					theCamera.savedMode[1] = 8;
				}
				else
				{
					if (iVar4 == 3)
					{
						theCamera.savedMode[1] = 6;
						theCamera.savedTargetFocusDistance[0] = iVar4;
					}
					else
					{
						if (iVar4 == 4)
						{
							theCamera.savedMode[1] = 2;
							if ((theCamera.positionAccl._4_4_ & 0x200000) == 0)
							{
								SAVE_ClearMemory((GameTracker *)(theCamera.core.vvNormalWorVecMat[0].m + 4));
							}
						}
						else
						{
							theCamera.savedMode[1] = 2;
						}
					}
				}
			}
			break;
		case 2:
			uVar5 = theCamera.positionAccl._4_4_ & 0x1000000;
			if (uVar5 == 0)
			{
				MAIN_FreeMainMenuStuff();
				return uVar5;
			}
			play_movie((char *)InterfaceItem_ARRAY_800ce5e0);
			uVar5 = theCamera.positionAccl._4_4_ & 0xfeffffff;
			if ((theCamera.positionAccl._4_4_ & 0x200000) != 0)
			{
				uVar5 = theCamera.positionAccl._4_4_ & 0xfedfffff;
			}
			theCamera.positionAccl._4_4_ = uVar5;
			if (nosound == 0)
			{
				MAIN_InitVolume();
			}
			MAIN_ShowLoadingScreen();
			FONT_ReloadFont(); */
			/* WARNING: Subroutine does not return */
/* 			DrawSync(0);
		case 4:
			LOAD_ChangeDirectory(s_Menustuff_800ce864);
			do
			{
				lVar2 = theCamera.savedTargetFocusDistance[0];
				if (5 < (uint)theCamera.savedTargetFocusDistance[0])
					goto LAB_800390f0;
				theCamera.positionAccl._0_4_ = theCamera.positionAccl._0_4_ & 0xfffffffe;
				show_screen((char *)(InterfaceItems + theCamera.savedTargetFocusDistance[0]));
				iVar4 = 1;
				if (InterfaceItems[lVar2].timeout != 0)
				{
					do
					{
						GAMEPAD_Process((GameTracker *)(theCamera.core.vvNormalWorVecMat[0].m + 4));
						if (((int)(uint)InterfaceItems[lVar2].buttonTimeout < iVar4) &&
							((theCamera.core.vvPlaneConsts[5] & 0x80U) != 0))
							break;
						VSync(0);
						bVar1 = iVar4 < (int)(uint)InterfaceItems[lVar2].timeout;
						iVar4 = iVar4 + 1;
					} while (bVar1);
				}
				theCamera.savedTargetFocusDistance[0] = (long)InterfaceItems[lVar2].nextItem;
			} while ((theCamera.savedTargetFocusDistance[0] < 0) ||
					 (InterfaceItems[theCamera.savedTargetFocusDistance[0]].itemType == 1));
			theCamera.savedMode[1] = 6;
		LAB_800390f0:
			FONT_ReloadFont();
			if (theCamera.savedMode[1] != 6)
			{
				if (DoMainMenu != 0)
					goto LAB_8003933c;
				MAIN_ResetGame();
				theCamera.maxFocusVel.pad = 0;
				mainMenuFading = 1;
				MAIN_StartGame();
			}
			break;
		case 6:
			CINE_Load();
			if (-1 < theCamera.savedTargetFocusDistance[0])
			{
				iVar4 = CINE_Loaded();
				gameTracker = (GameTracker *)&DAT_0000ffff;
				if (iVar4 != 0)
				{
					CINE_Play((char *)(InterfaceItems + theCamera.savedTargetFocusDistance[0]), 0xffff, 2);
					ClearDisplay();
				}
				theCamera.savedTargetFocusDistance[0] =
					(long)InterfaceItems[theCamera.savedTargetFocusDistance[0]].nextItem;
				iVar4 = 4;
				if (InterfaceItems[theCamera.savedTargetFocusDistance[0]].itemType == 0)
				{
					if (-1 < theCamera.savedTargetFocusDistance[0])
					{
						MAIN_DoMainInit();
						return iVar4;
					}
				}
				else
				{
					theCamera.savedMode[1] = 4;
				}
			}
			CINE_Unload();
			if (theCamera.savedTargetFocusDistance[0] < 0)
			{
				theCamera.savedMode[1] = 8;
			}
			if (nosound == 0)
			{
				SOUND_StopAllSound();
			}
			break;
		case 7:
			theCamera.savedTargetFocusDistance[1] = 1;
			break;
		case 8:
			theCamera.core.vvNormalWorVecMat[0]._18_2_ = 0;
			gameTracker = pGVar6;
			ProcessArgs((char *)&theCamera.focusRotVel,
						(GameTracker *)(theCamera.core.vvNormalWorVecMat[0].m + 4));
			MAIN_ResetGame();
			LOAD_ChangeDirectory(s_Menustuff_800ce864);
			MAIN_MainMenuInit();
			MAIN_InitVolume();
			SAVE_ClearMemory((GameTracker *)(theCamera.core.vvNormalWorVecMat[0].m + 4));
			theCamera.savedMode[1] = 9;
			FONT_ReloadFont();
			break;
		case 9:
			gameTracker = (GameTracker *)(theCamera.savedMode + 1);
			MAIN_ShowLoadingScreen();
		}
		STREAM_PollLoadQueue();
		if (theCamera.savedTargetFocusDistance[1] != 0)
		{
			SOUND_StopAllSound();
			SOUND_Free();
			SetDispMask(0);
			/* WARNING: Subroutine does not return */
/* 			DrawSync(0);
		}
	} while (true); */
}

int main(void)

{
  int iVar1;
  _Terrain *in_a0;
  BSPTree *in_a1;
  _SVector *in_a2;
  _SVector *in_a3;
  _TFace *local_8;
  long in_stack_00000000;
  long in_stack_fffffffc;
  
  //ClearBss(in_a0,in_a1,in_a2,in_a3,local_8,in_stack_fffffffc,in_stack_00000000);
  iVar1 = MainG2(&_appDataVM);
  return iVar1;
}