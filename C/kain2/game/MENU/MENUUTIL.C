#include "THISDUST.H"
#include "MENUUTIL.H"

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

int get_volume(void *gt, sfx_t sfx)

{
	int in_v0;
	char *in_a2;
	int in_a3;

	FONT_SetCursor((short)gt, (short)sfx);
	if (in_a3 != 0)
	{
		FONT_SetColorIndex(in_a3);
	}
	FONT_Print2(in_a2);
	if (in_a3 != 0)
	{
		FONT_SetColorIndex(0);
	}
	return in_v0;
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
	SndPlay(*(uint *)(&SHORT_800cad9c + sound * 4));
	return;
}
