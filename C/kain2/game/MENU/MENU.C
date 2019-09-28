#include "THISDUST.H"
#include "MENU.H"

// decompiled code
// original method signature:
// int /*$ra*/ menu_data_size()
// line 83, offset 0x800b7a40
/* begin block 1 */
// Start line: 85
// Start offset: 0x800B7A40
/* end block 1 */
// End offset: 0x800B7A40
// End Line: 86

/* begin block 2 */
// Start line: 166
/* end block 2 */
// End Line: 167

/* begin block 3 */
// Start line: 167
/* end block 3 */
// End Line: 168

/* begin block 4 */
// Start line: 168
/* end block 4 */
// End Line: 169

/* begin block 5 */
// Start line: 169
/* end block 5 */
// End Line: 170

/* WARNING: Unknown calling convention yet parameter storage is locked */

int menu_data_size(void)

{
	return 0x388;
}

// decompiled code
// original method signature:
// void /*$ra*/ menu_initialize(struct menu_t *menu /*$s0*/, void *opaque /*$s1*/)
// line 89, offset 0x800b7a48
/* begin block 1 */
// Start line: 178
/* end block 1 */
// End Line: 179

void menu_initialize(void *param_1)

{
	/* WARNING: Subroutine does not return */
	memset(param_1, 0, 0x388);
}

// decompiled code
// original method signature:
// void /*$ra*/ menu_format(struct menu_t *menu /*$a0*/, int center /*$a1*/, int xpos /*$a2*/, int ypos /*$a3*/, int width /*stack 16*/, int lineskip /*stack 20*/, int itemskip /*stack 24*/, int border /*stack 28*/)
// line 97, offset 0x800b7a8c
/* begin block 1 */
// Start line: 98
// Start offset: 0x800B7A8C

/* begin block 1.1 */
// Start line: 98
// Start offset: 0x800B7A8C
// Variables:
// 		struct menu_format_t *fmt; // $a0
/* end block 1.1 */
// End offset: 0x800B7A8C
// End Line: 101
/* end block 1 */
// End offset: 0x800B7A8C
// End Line: 101

/* begin block 2 */
// Start line: 196
/* end block 2 */
// End Line: 197

/* begin block 3 */
// Start line: 199
/* end block 3 */
// End Line: 200

void menu_format(menu_t *menu, int center, int xpos, int ypos, int width, int lineskip, int itemskip,
				 int border)

{
	char *pcVar1;

	pcVar1 = menu[-1].bytes + menu->nmenus * 0x24 + 0x1f0;
	*(int *)(pcVar1 + 8) = xpos;
	*(int *)(pcVar1 + 0xc) = ypos;
	*(int *)(pcVar1 + 0x1c) = center;
	*(int *)(pcVar1 + 0x10) = lineskip;
	*(int *)(pcVar1 + 0x14) = itemskip;
	*(int *)(pcVar1 + 0x18) = width;
	*(int *)(pcVar1 + 0x20) = border;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ menu_set(struct menu_t *menu /*$a0*/, TDRFuncPtr_menu_set1fn fn /*$a1*/)
// line 115, offset 0x800b7adc
/* begin block 1 */
// Start line: 240
/* end block 1 */
// End Line: 241

void menu_set(menu_t *param_1, TDRFuncPtr_menu_push1fn param_2)

{
	param_1->nmenus = 0;
	param_1->drawfn = (_func_63 *)0x0;
	menu_push(param_1, param_2);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ menu_push(struct menu_t *menu /*$a0*/, TDRFuncPtr_menu_push1fn fn /*$a1*/)
// line 123, offset 0x800b7b00
/* begin block 1 */
// Start line: 125
// Start offset: 0x800B7B00

/* begin block 1.1 */
// Start line: 127
// Start offset: 0x800B7B00
// Variables:
// 		struct menu_stack_t *stack; // $a0
/* end block 1.1 */
// End offset: 0x800B7B00
// End Line: 127
/* end block 1 */
// End offset: 0x800B7B00
// End Line: 127

/* begin block 2 */
// Start line: 256
/* end block 2 */
// End Line: 257

/* begin block 3 */
// Start line: 257
/* end block 3 */
// End Line: 258

/* begin block 4 */
// Start line: 259
/* end block 4 */
// End Line: 260

void menu_push(menu_t *menu, TDRFuncPtr_menu_push1fn fn)

{
	int iVar1;
	menu_stack_t *pmVar2;
	int iVar3;
	int iVar4;

	iVar1 = menu->nmenus;
	menu->nmenus = iVar1 + 1;
	pmVar2 = menu->stack + iVar1;
	*(TDRFuncPtr_menu_push1fn *)&pmVar2->fn = fn;
	pmVar2->index = -1;
	iVar1 = pmVar2[-1].format.ypos;
	iVar3 = pmVar2[-1].format.lineskip;
	iVar4 = pmVar2[-1].format.itemskip;
	(pmVar2->format).xpos = pmVar2[-1].format.xpos;
	(pmVar2->format).ypos = iVar1;
	(pmVar2->format).lineskip = iVar3;
	(pmVar2->format).itemskip = iVar4;
	iVar1 = pmVar2[-1].format.center;
	iVar3 = pmVar2[-1].format.border;
	(pmVar2->format).width = pmVar2[-1].format.width;
	(pmVar2->format).center = iVar1;
	(pmVar2->format).border = iVar3;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ menu_pop(struct menu_t *menu /*$a0*/)
// line 134, offset 0x800b7b70
/* begin block 1 */
// Start line: 279
/* end block 1 */
// End Line: 280

/* begin block 2 */
// Start line: 281
/* end block 2 */
// End Line: 282

void menu_pop(menu_t *menu)

{
	menu->nmenus = menu->nmenus + -1;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ menu_item_flags(struct menu_t *menu /*$s2*/, TDRFuncPtr_menu_item_flags1fn fn /*$a1*/, long parameter /*$a2*/, long flags /*$a3*/, char *format /*stack 16*/)
// line 152, offset 0x800b7b84
/* begin block 1 */
// Start line: 153
// Start offset: 0x800B7B84

/* begin block 1.1 */
// Start line: 153
// Start offset: 0x800B7B84
// Variables:
// 		struct menu_item_t *item; // $s1
/* end block 1.1 */
// End offset: 0x800B7B84
// End Line: 153
/* end block 1 */
// End offset: 0x800B7B84
// End Line: 153

/* begin block 2 */
// Start line: 304
/* end block 2 */
// End Line: 305

void menu_item_flags(menu_t *menu, TDRFuncPtr_menu_item_flags1fn fn, long parameter, long flags,
					 char *format)

{
	int iVar1;
	size_t sVar2;
	menu_item_t *pmVar3;

	pmVar3 = menu->items + menu->nitems;
	menu->nitems = menu->nitems + 1;
	*(TDRFuncPtr_menu_item_flags1fn *)&pmVar3->fn = fn;
	pmVar3->parameter = parameter;
	iVar1 = menu->nbytes;
	pmVar3->flags = flags;
	pmVar3->text = menu->bytes + iVar1;
	vsprintf(menu->bytes + iVar1, format, &stack0x00000014);
	iVar1 = menu->nbytes;
	sVar2 = strlen(pmVar3->text);
	menu->nbytes = iVar1 + 1 + sVar2;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ menu_item(struct menu_t *menu /*$s2*/, TDRFuncPtr_menu_item1fn fn /*$a1*/, long parameter /*$a2*/, char *format /*stack 12*/)
// line 170, offset 0x800b7c14
/* begin block 1 */
// Start line: 171
// Start offset: 0x800B7C14

/* begin block 1.1 */
// Start line: 171
// Start offset: 0x800B7C14
// Variables:
// 		struct menu_item_t *item; // $s1

/* begin block 1.1.1 */
// Start line: 181
// Start offset: 0x800B7C74
/* end block 1.1.1 */
// End offset: 0x800B7C74
// End Line: 183
/* end block 1.1 */
// End offset: 0x800B7CA0
// End Line: 192
/* end block 1 */
// End offset: 0x800B7CA0
// End Line: 193

/* begin block 2 */
// Start line: 344
/* end block 2 */
// End Line: 345

void menu_item(menu_t *menu, TDRFuncPtr_menu_item1fn fn, long parameter, char *format)

{
	int iVar1;
	size_t sVar2;
	menu_item_t *pmVar3;

	pmVar3 = menu->items + menu->nitems;
	menu->nitems = menu->nitems + 1;
	*(TDRFuncPtr_menu_item1fn *)&pmVar3->fn = fn;
	pmVar3->parameter = parameter;
	iVar1 = menu->nbytes;
	pmVar3->flags = 0;
	pmVar3->text = menu->bytes + iVar1;
	if (format == (char *)0x0)
	{
		pmVar3->text = (char *)0x0;
	}
	else
	{
		vsprintf(menu->bytes + iVar1, format, &stack0x00000010);
		iVar1 = menu->nbytes;
		sVar2 = strlen(pmVar3->text);
		menu->nbytes = iVar1 + 1 + sVar2;
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ menu_build(struct menu_t *menu /*$a0*/)
// line 195, offset 0x800b7cb8
/* begin block 1 */
// Start line: 196
// Start offset: 0x800B7CB8

/* begin block 1.1 */
// Start line: 196
// Start offset: 0x800B7CB8
// Variables:
// 		struct menu_stack_t *stack; // $s0
/* end block 1.1 */
// End offset: 0x800B7CB8
// End Line: 196
/* end block 1 */
// End offset: 0x800B7CB8
// End Line: 196

/* begin block 2 */
// Start line: 403
/* end block 2 */
// End Line: 404

void menu_build(menu_t *menu)

{
	menu_stack_t *pmVar1;
	int iVar2;

	menu->nitems = 0;
	menu->nbytes = 0;
	pmVar1 = menu->stack + menu->nmenus;
	iVar2 = (*pmVar1[-1].fn)(menu->opaque, pmVar1[-1].index);
	pmVar1[-1].index = iVar2;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ DisplayHintBox(int len /*$a0*/, int y /*$a1*/)
// line 221, offset 0x800b7d10
/* begin block 1 */
// Start line: 222
// Start offset: 0x800B7D10
// Variables:
// 		struct Extents2d ext; // stack offset -24
// 		int i; // $s0

/* begin block 1.1 */
// Start line: 239
// Start offset: 0x800B7D48
/* end block 1.1 */
// End offset: 0x800B7D48
// End Line: 239
/* end block 1 */
// End offset: 0x800B7E2C
// End Line: 255

/* begin block 2 */
// Start line: 458
/* end block 2 */
// End Line: 459

void DisplayHintBox(int len, int y)

{
	short x1;
	int y2;
	int x3;
	int iVar1;

	iVar1 = 0;
	len = len >> 1;
	x3 = len + 0x105;
	y2 = y + -1;
	y = y + 0xd;
	do
	{
		x1 = (short)(0xfb - len);
		DRAW_TranslucentQuad(x1 + -0xe, (short)(y2 + y >> 1), x1, (short)y, 0xfb - len, y2, x3, y, 0, 0, 0, 0, DAT_800d0fec,
							 (ulong **)(DAT_800d1180 + 4));
		iVar1 = iVar1 + 1;
		DRAW_TranslucentQuad(x1, (short)y2, (short)x3, (short)y, x3, y2, len + 0x113, y2 + y >> 1, 0, 0, 0, 0, DAT_800d0fec,
							 (ulong **)(DAT_800d1180 + 4));
	} while (iVar1 < 2);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ DisplayMenuBox(int x0 /*$a0*/, int x1 /*$a1*/, int y0 /*$a2*/, int y1 /*$a3*/)
// line 257, offset 0x800b7e3c
/* begin block 1 */
// Start line: 258
// Start offset: 0x800B7E3C
// Variables:
// 		struct Extents2d ext; // stack offset -56
// 		static int dy[16]; // offset 0x0
// 		int i; // $s3
// 		int j; // $s6
// 		int k; // $s2
// 		int slice0; // $s7
// 		unsigned long **ot; // $s5
// 		struct _PrimPool *primPool; // $s4

/* begin block 1.1 */
// Start line: 276
// Start offset: 0x800B7ED4

/* begin block 1.1.1 */
// Start line: 278
// Start offset: 0x800B7EE4
/* end block 1.1.1 */
// End offset: 0x800B7EE4
// End Line: 278
/* end block 1.1 */
// End offset: 0x800B7FDC
// End Line: 290
/* end block 1 */
// End offset: 0x800B8044
// End Line: 300

/* begin block 2 */
// Start line: 552
/* end block 2 */
// End Line: 553

void DisplayMenuBox(int x0, int x1, int y0, int y1)

{
	short y0_00;
	int iVar1;
	_PrimPool *primPool;
	int y2;
	int *piVar2;
	int iVar3;
	int iVar4;
	int *piVar5;
	int iVar6;
	ulong **ot;
	int iVar7;
	int iVar8;

	primPool = DAT_800d0fec;
	iVar8 = 0;
	iVar3 = x0 + -0xc;
	iVar4 = x1 + 0xc;
	y2 = y0 + -5;
	y0_00 = (short)y1 + 5;
	ot = (ulong **)(DAT_800d1180 + 4);
	if (y1 - y0 < DAT_800cf9b4 << 1)
	{
		piVar2 = &DAT_800cf9b4;
		do
		{
			piVar2 = piVar2 + 1;
			iVar8 = iVar8 + 1;
		} while (y1 - y0 < *piVar2 << 1);
	}
	iVar7 = 0;
	do
	{
		iVar1 = iVar8;
		while (iVar1 < 0xf)
		{
			iVar6 = iVar1 + 1;
			piVar2 = &DAT_800cf9b4 + iVar1;
			piVar5 = &DAT_800cf9b4 + iVar6;
			DRAW_TranslucentQuad((short)(iVar3 + iVar1), y0_00 - (short)*piVar2, (short)iVar3 + (short)iVar6,
								 y0_00 - (short)*piVar5, iVar3 + iVar1, y2 + *piVar2, iVar3 + iVar6, y2 + *piVar5, 0, 0, 0,
								 0, primPool, ot);
			DRAW_TranslucentQuad((short)(iVar4 - iVar1), y0_00 - (short)*piVar2, (short)iVar4 - (short)iVar6,
								 y0_00 - (short)*piVar5, iVar4 - iVar1, y2 + *piVar2, iVar4 - iVar6, y2 + *piVar5, 0, 0, 0,
								 0, primPool, ot);
			iVar1 = iVar6;
		}
		iVar7 = iVar7 + 1;
		DRAW_TranslucentQuad((short)(x0 + 3), y0_00, (short)iVar4 + -0xf, y0_00, x0 + 3, y2, x1 + -3, y2, 0, 0, 0, 0, primPool, ot);
	} while (iVar7 < 2);
	return;
}

// decompiled code
// original method signature:
// int /*$ra*/ menu_draw_item(struct menu_t *menu /*$a0*/, int ypos /*stack 4*/, int xadj /*stack 8*/, int yadj /*$a3*/, char *text /*stack 16*/, int color /*stack 20*/, long flags /*stack 24*/, struct Extents2d *e /*stack 28*/)
// line 311, offset 0x800b8074
/* begin block 1 */
// Start line: 312
// Start offset: 0x800B8074
// Variables:
// 		struct menu_format_t *fmt; // stack offset -64
// 		int numColumns; // $a1
// 		int i; // $v1
// 		int texLen; // $a0
// 		int columnWidth; // $fp
// 		char *columnText; // $a1
// 		char tmpBuff[256]; // stack offset -320
// 		char *lineText; // $s1
// 		int columnYPos; // $s5
// 		int maxColumnYPos; // stack offset -60
// 		int center; // stack offset -56
// 		int leftEdge; // stack offset -52
// 		int xpos; // $s4

/* begin block 1.1 */
// Start line: 403
// Start offset: 0x800B823C
// Variables:
// 		char *eol; // $s6

/* begin block 1.1.1 */
// Start line: 410
// Start offset: 0x800B8260
// Variables:
// 		char *eop; // $s2

/* begin block 1.1.1.1 */
// Start line: 412
// Start offset: 0x800B8278
// Variables:
// 		char *tmp; // $s0
// 		int wd; // $v0
/* end block 1.1.1.1 */
// End offset: 0x800B82B8
// End Line: 427

/* begin block 1.1.1.2 */
// Start line: 434
// Start offset: 0x800B82E0
/* end block 1.1.1.2 */
// End offset: 0x800B8320
// End Line: 440

/* begin block 1.1.1.3 */
// Start line: 443
// Start offset: 0x800B8328
// Variables:
// 		int wd; // $s0
/* end block 1.1.1.3 */
// End offset: 0x800B8378
// End Line: 450
/* end block 1.1.1 */
// End offset: 0x800B838C
// End Line: 453
/* end block 1.1 */
// End offset: 0x800B83A4
// End Line: 457
/* end block 1 */
// End offset: 0x800B8444
// End Line: 478

/* begin block 2 */
// Start line: 733
/* end block 2 */
// End Line: 734

int menu_draw_item(menu_t *menu, int ypos, int xadj, int yadj, char *text, int color, long flags,
				   Extents2d *e)

{
	int *piVar1;
	size_t sVar2;
	char *__src;
	int iVar3;
	char acStack320[256];
	int *local_40;
	int local_3c;
	int local_38;
	int local_34;
	undefined4 local_30;

	local_3c = 0;
	piVar1 = &menu->nmenus + menu->nmenus * 9;
	local_40 = piVar1 + -4;
	local_38 = 1;
	if (((flags & 1U) == 0) && (local_38 = 0, (flags & 2U) == 0))
	{
		local_38 = piVar1[1];
	}
	if (ypos == 0)
	{
		ypos = piVar1[-3];
	}
	sVar2 = strlen(text);
	iVar3 = 0;
	if (0 < (int)sVar2)
	{
		do
		{
			iVar3 = iVar3 + 1;
		} while (iVar3 < (int)sVar2);
	}
	if (local_40[5] == 0)
	{
		local_34 = *local_40 + xadj;
	}
	else
	{
		local_34 = (*local_40 + xadj) - (local_40[4] >> 1);
	}
	__src = strtok(text, &LAB_800cf9f2_2);
	if (__src != (char *)0x0)
	{
		local_30 = 0;
		if (ypos + yadj < e->ymin)
		{
			e->ymin = ypos + yadj;
		}
		/* WARNING: Subroutine does not return */
		strcpy(acStack320, __src);
	}
	if (e->ymax < local_3c)
	{
		e->ymax = local_3c;
	}
	local_3c = local_3c + local_40[3];
	if ((flags & 4U) != 0)
	{
		local_3c = local_3c + (local_40[2] >> 1);
	}
	return local_3c;
}

// decompiled code
// original method signature:
// void /*$ra*/ menu_draw(struct menu_t *menu /*$s2*/)
// line 481, offset 0x800b8478
/* begin block 1 */
// Start line: 482
// Start offset: 0x800B8478

/* begin block 1.1 */
// Start line: 482
// Start offset: 0x800B8478
// Variables:
// 		struct Extents2d ext; // stack offset -48
// 		struct menu_stack_t *stack; // $s6
// 		int index; // $s5
// 		int ypos; // $s3
// 		int i; // $s0

/* begin block 1.1.1 */
// Start line: 496
// Start offset: 0x800B851C
// Variables:
// 		struct menu_item_t *item; // $v1
// 		int color; // $t0
/* end block 1.1.1 */
// End offset: 0x800B8540
// End Line: 504
/* end block 1.1 */
// End offset: 0x800B85B0
// End Line: 517
/* end block 1 */
// End offset: 0x800B85B0
// End Line: 518

/* begin block 2 */
// Start line: 1118
/* end block 2 */
// End Line: 1119

void menu_draw(menu_t *menu)

{
	int iVar1;
	char **ppcVar2;
	uint color;
	int iVar3;
	int iVar4;
	int ypos;
	int iVar5;
	Extents2d local_30;

	local_30.xmin = DAT_800cf9f8;
	local_30.xmax = PTR_DAT_800cf9fc;
	local_30.ymin = DAT_800cfa00;
	local_30.ymax = PTR_DAT_800cfa04;
	iVar1 = menu->nmenus;
	iVar5 = (&menu->nmenus + iVar1 * 9)[-5];
	ypos = 0;
	if (menu->drawfn != (_func_63 *)0x0)
	{
		(*menu->drawfn)(menu->opaque);
	}
	iVar3 = 0;
	if (0 < menu->nitems)
	{
		iVar4 = 0xc0;
		do
		{
			ppcVar2 = (char **)((int)&menu->nmenus + iVar4);
			if ((iVar3 != 0) || (color = 3, ((uint)ppcVar2[3] & 4) == 0))
			{
				color = (uint)(iVar3 != iVar5);
			}
			iVar4 = iVar4 + 0x10;
			iVar3 = iVar3 + 1;
			ypos = menu_draw_item(menu, ypos, 0, 0, *ppcVar2, color, (long)ppcVar2[3], &local_30);
		} while (iVar3 < menu->nitems);
	}
	if ((&menu->nmenus + iVar1 * 9)[2] != 0)
	{
		DisplayMenuBox(local_30.xmin, (int)local_30.xmax, local_30.ymin, (int)local_30.ymax);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ menu_run(struct menu_t *menu /*$s2*/)
// line 524, offset 0x800b85d8
/* begin block 1 */
// Start line: 525
// Start offset: 0x800B85D8
// Variables:
// 		enum menu_ctrl_t ctrl; // $s1
// 		struct menu_stack_t *stack; // $s4
// 		int index; // $s0
// 		struct menu_item_t *item; // $s3

/* begin block 1.1 */
// Start line: 546
// Start offset: 0x800B8640
// Variables:
// 		enum menu_sound_t sound; // $v0
/* end block 1.1 */
// End offset: 0x800B8674
// End Line: 559
/* end block 1 */
// End offset: 0x800B87A8
// End Line: 588

/* begin block 2 */
// Start line: 1239
/* end block 2 */
// End Line: 1240

void menu_run(menu_t *menu)

{
	menu_ctrl_t mVar1;
	menu_sound_t sound;
	_func_65 *p_Var2;
	int iVar3;
	int *piVar4;
	int iVar5;

	mVar1 = menu_get_ctrl(menu->opaque);
	piVar4 = &menu->nmenus + menu->nmenus * 9;
	iVar5 = piVar4[-5];
	if ((-1 < iVar5) && (mVar1 != menu_ctrl_none))
	{
		menudefs_reset_hack_attract_mode();
		sound = (*menu->items[iVar5].fn)(menu->opaque, menu->items[iVar5].parameter, mVar1);
		if (sound == menu_sound_none)
		{
			if (mVar1 == menu_ctrl_down)
			{
				iVar5 = (iVar5 + 1) % menu->nitems;
				p_Var2 = menu->items[iVar5].fn;
				while (p_Var2 == (_func_65 *)0x0)
				{
					iVar5 = (iVar5 + 1) % menu->nitems;
					p_Var2 = menu->items[iVar5].fn;
				}
			}
			else
			{
				if (mVar1 < menu_ctrl_left)
				{
					if (mVar1 == menu_ctrl_up)
					{
						iVar3 = menu->nitems;
						iVar5 = (iVar5 + iVar3 + -1) % iVar3;
						p_Var2 = menu->items[iVar5].fn;
						while (p_Var2 == (_func_65 *)0x0)
						{
							iVar5 = (iVar5 + iVar3 + -1) % iVar3;
							p_Var2 = menu->items[iVar5].fn;
						}
					}
				}
				else
				{
					if ((mVar1 == menu_ctrl_cancel) && (1 < menu->nmenus))
					{
						menu_sound(menu_sound_pop);
						menu_pop(menu);
					}
				}
			}
			if (iVar5 != piVar4[-5])
			{
				menu_sound(menu_sound_select);
			}
			piVar4[-5] = iVar5;
		}
		else
		{
			menu_sound(sound);
		}
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ menu_process(struct menu_t *menu /*$s0*/)
// line 592, offset 0x800b87c8
/* begin block 1 */
// Start line: 1379
/* end block 1 */
// End Line: 1380

void menu_process(menu_t *menu)

{
	menu_build(menu);
	menu_draw(menu);
	menu_run(menu);
	return;
}
