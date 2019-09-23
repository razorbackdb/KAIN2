#include "THISDUST.H"
#include "MENUUTIL.H"

// menu_sound_entry_t[6] @0x800CAD98, len = 0x00000030
the_menu_sounds =
	{
		// menu_sound_entry_t @0x800CAD98, len = 0x00000008
		{
			// menu_sound_t @0x800CAD98, len = 0x00000004
			.sound = 0x0,
			// int @0x800CAD9C, len = 0x00000004
			.sfx = 0x5},
		// menu_sound_entry_t @0x800CADA0, len = 0x00000008
		{
			// menu_sound_t @0x800CADA0, len = 0x00000004
			.sound = 0x1,
			// int @0x800CADA4, len = 0x00000004
			.sfx = 0x5},
		// menu_sound_entry_t @0x800CADA8, len = 0x00000008
		{
			// menu_sound_t @0x800CADA8, len = 0x00000004
			.sound = 0x2,
			// int @0x800CADAC, len = 0x00000004
			.sfx = 0x5},
		// menu_sound_entry_t @0x800CADB0, len = 0x00000008
		{
			// menu_sound_t @0x800CADB0, len = 0x00000004
			.sound = 0x3,
			// int @0x800CADB4, len = 0x00000004
			.sfx = 0x5},
		// menu_sound_entry_t @0x800CADB8, len = 0x00000008
		{
			// menu_sound_t @0x800CADB8, len = 0x00000004
			.sound = 0x4,
			// int @0x800CADBC, len = 0x00000004
			.sfx = 0x5},
		// menu_sound_entry_t @0x800CADC0, len = 0x00000008
		{
			// menu_sound_t @0x800CADC0, len = 0x00000004
			.sound = 0x5,
			// int @0x800CADC4, len = 0x00000004
			.sfx = 0x5}};
// decompiled code
// original method signature:
// enum menu_ctrl_t /*$ra*/ menu_get_ctrl(void *gt /*$a0*/)
// line 18, offset 0x800b87fc
/* begin block 1 */
// Start line: 20
// Start offset: 0x800B87FC
// Variables:
// 		enum menu_ctrl_t ctrl; // $v1
/* end block 1 */
// End offset: 0x800B8874
// End Line: 38

/* begin block 2 */
// Start line: 36
/* end block 2 */
// End Line: 37

/* begin block 3 */
// Start line: 37
/* end block 3 */
// End Line: 38

/* begin block 4 */
// Start line: 38
/* end block 4 */
// End Line: 39

menu_ctrl_t menu_get_ctrl(void *gt)

{
	menu_ctrl_t mVar1;
	uint uVar2;

	uVar2 = *(uint *)((int)gt + 0x4c);
	mVar1 = menu_ctrl_up;
	if (((((uVar2 & 1) == 0) && (mVar1 = menu_ctrl_down, (uVar2 & 2) == 0)) &&
		 (mVar1 = menu_ctrl_left, (uVar2 & 4) == 0)) &&
		(mVar1 = menu_ctrl_right, (uVar2 & 8) == 0))
	{
		if (((uVar2 & 0x80) == 0) || ((*(uint *)((int)gt + 0x48) & 0x300) != 0))
		{
			mVar1 = menu_ctrl_cancel;
			if (((uVar2 & 0x10) == 0) && (mVar1 = menu_ctrl_none, (uVar2 & 0x4000) != 0))
			{
				mVar1 = menu_ctrl_start;
			}
		}
		else
		{
			mVar1 = menu_ctrl_engage;
		}
	}
	return mVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ menu_print(int xpos /*$a0*/, int ypos /*$a1*/, char *text /*$s1*/, int color /*$s0*/)
// line 41, offset 0x800b887c
/* begin block 1 */
// Start line: 82
/* end block 1 */
// End Line: 83

void menu_print(int xpos, int ypos, char *text, int color)

{
	FONT_SetCursor((short)xpos, (short)ypos);
	if (color != 0)
	{
		FONT_SetColorIndex(color);
	}
	FONT_Print2(text);
	if (color != 0)
	{
		FONT_SetColorIndex(0);
	}
	return;
}

// decompiled code
// original method signature:
// int /*$ra*/ menu_text_width(char *text /*$a0*/)
// line 69, offset 0x800b88e4
/* begin block 1 */
// Start line: 158
/* end block 1 */
// End Line: 159

int menu_text_width(char *text)

{
	int iVar1;

	iVar1 = FONT_GetStringWidth(text);
	return iVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ menu_sound(enum menu_sound_t sound /*$a0*/)
// line 92, offset 0x800b8904
/* begin block 1 */
// Start line: 93
// Start offset: 0x800B8904
// Variables:
// 		struct menu_sound_entry_t *entry; // $a0
/* end block 1 */
// End offset: 0x800B8904
// End Line: 93

/* begin block 2 */
// Start line: 204
/* end block 2 */
// End Line: 205

void menu_sound(menu_sound_t sound)

{
	SndPlay(the_menu_sounds[sound].sfx);
	return;
}
