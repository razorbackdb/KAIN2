#include "THISDUST.H"
#include "MENUFACE.H"

// decompiled code
// original method signature:
// char * /*$ra*/ NextTimAddr(char *addr /*$a0*/, int w /*$a1*/, int h /*$a2*/, enum bdepth bpp /*$a3*/)
// line 25, offset 0x800b9538
/* begin block 1 */
// Start line: 27
// Start offset: 0x800B9538
// Variables:
// 		long addtl; // $v0
/* end block 1 */
// End offset: 0x800B9574
// End Line: 34

/* begin block 2 */
// Start line: 50
/* end block 2 */
// End Line: 51

/* begin block 3 */
// Start line: 51
/* end block 3 */
// End Line: 52

/* begin block 4 */
// Start line: 52
/* end block 4 */
// End Line: 53

int NextTimAddr(int param_1, int param_2, int param_3, int param_4)

{
	int iVar1;

	if (param_4 == 0)
	{
		iVar1 = (param_2 * param_3 >> 1) + 0x2c;
	}
	else
	{
		if (param_4 == 1)
		{
			iVar1 = param_2 * param_3 + 0x20c;
		}
		else
		{
			iVar1 = param_2 * param_3 * 2;
		}
	}
	return param_1 + iVar1 + 0x14;
}

// decompiled code
// original method signature:
// void /*$ra*/ menuface_initialize()
// line 76, offset 0x800b9580
/* begin block 1 */
// Start line: 77
// Start offset: 0x800B9580
// Variables:
// 		char *addr; // $s6
// 		char *buttonAddr; // $s2
// 		int i; // $s5
// 		int j; // $s1

/* begin block 1.1 */
// Start line: 92
// Start offset: 0x800B95AC
/* end block 1.1 */
// End offset: 0x800B9684
// End Line: 134
/* end block 1 */
// End offset: 0x800B9684
// End Line: 139

/* begin block 2 */
// Start line: 152
/* end block 2 */
// End Line: 153

/* begin block 3 */
// Start line: 161
/* end block 3 */
// End Line: 162

void menuface_initialize(void)

{
	long *plVar1;

	if ((iGpffffa088 == 0) &&
		(plVar1 = LOAD_ReadFile(s__kain2_game_psx_frontend_faces_t_800cfb40, '\v'),
		 plVar1 != (long *)0x0))
	{
		/* WARNING: Subroutine does not return */
		MEMPACK_Malloc(0x380, '-');
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ menuface_terminate()
// line 141, offset 0x800b96ac
/* begin block 1 */
// Start line: 142
// Start offset: 0x800B96AC
// Variables:
// 		int i; // $s3
// 		int j; // $s0
/* end block 1 */
// End offset: 0x800B973C
// End Line: 158

/* begin block 2 */
// Start line: 329
/* end block 2 */
// End Line: 330

/* begin block 3 */
// Start line: 332
/* end block 3 */
// End Line: 333

/* WARNING: Unknown calling convention yet parameter storage is locked */

void menuface_terminate(void)

{
	uint uVar1;
	menuface_t *pmVar2;
	int iVar3;
	int iVar4;

	if (hack_initialized != 0)
	{
		iVar4 = 0;
		iVar3 = 0;
		pmVar2 = MenuFaces;
		do
		{
			uVar1 = 0;
			do
			{
				if (((int)(uint)pmVar2->loaded >> (uVar1 & 0x1f) & 1U) != 0)
				{
					DRAW_FreeButton((_ButtonTexture *)(_BlockVramEntry_800d5bec.udata + (iVar3 + uVar1) * 0x10));
				}
				uVar1 = uVar1 + 1;
			} while ((int)uVar1 < 7);
			iVar3 = iVar3 + 7;
			iVar4 = iVar4 + 1;
			pmVar2 = pmVar2 + 1;
		} while (iVar4 < 8);
		/* WARNING: Subroutine does not return */
		MEMPACK_Free(_BlockVramEntry_800d5bec.udata);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MENUFACE_ChangeStateRandomly(int index /*$a0*/)
// line 163, offset 0x800b9758
/* begin block 1 */
// Start line: 164
// Start offset: 0x800B9758
// Variables:
// 		struct menuface_t *face; // $s1
// 		struct menuface_t *lastFace; // $s3

/* begin block 1.1 */
// Start line: 177
// Start offset: 0x800B97B0
/* end block 1.1 */
// End offset: 0x800B9808
// End Line: 182
/* end block 1 */
// End offset: 0x800B9860
// End Line: 195

/* begin block 2 */
// Start line: 381
/* end block 2 */
// End Line: 382

/* begin block 3 */
// Start line: 384
/* end block 3 */
// End Line: 385

void MENUFACE_ChangeStateRandomly(int index)

{
	ushort uVar1;
	ushort uVar2;
	ushort *puVar3;
	menuface_t *pmVar4;

	if (hack_initialized != 0)
	{
		pmVar4 = MenuFaces;
		puVar3 = &MenuFaces[0].delay;
		do
		{
			uVar1 = *puVar3 - 1;
			if (*puVar3 == 0)
			{
				if (puVar3[-1] == 0)
				{
					/* WARNING: Subroutine does not return */
					rand();
				}
				uVar2 = puVar3[-2] + puVar3[-1];
				puVar3[-2] = uVar2;
				uVar1 = 200;
				if (((int)(short)uVar2 == (uint) * (byte *)(puVar3 + -3) * 7 + -1) ||
					((int)(short)uVar2 == -1))
				{
					puVar3[-1] = 0;
					goto LAB_800b984c;
				}
			}
			else
			{
			LAB_800b984c:
				*puVar3 = uVar1;
			}
			pmVar4 = pmVar4 + 1;
			puVar3 = puVar3 + 8;
		} while (pmVar4 < &hack_initialized);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MENUFACE_RefreshFaces()
// line 198, offset 0x800b987c
/* begin block 1 */
// Start line: 199
// Start offset: 0x800B987C
// Variables:
// 		int i; // $s3
// 		struct menuface_t *face; // $s2
/* end block 1 */
// End offset: 0x800B9908
// End Line: 218

/* begin block 2 */
// Start line: 474
/* end block 2 */
// End Line: 475

/* begin block 3 */
// Start line: 478
/* end block 3 */
// End Line: 479

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MENUFACE_RefreshFaces(void)

{
	short *psVar1;
	int iVar2;
	menuface_t *pmVar3;
	int iVar4;

	if (hack_initialized != 0)
	{
		iVar4 = 0;
		pmVar3 = MenuFaces;
		psVar1 = &MenuFaces[0].y;
		iVar2 = 0;
		do
		{
			if ((int)(uint) * (byte *)(psVar1 + 2) <= (int)psVar1[3])
			{
				DRAW_DrawButton((_ButtonTexture *)(_BlockVramEntry_800d5bec.udata +
												   (iVar2 + (int)psVar1[3] / (int)(uint) * (byte *)(psVar1 + 2)) * 0x10),
								pmVar3->x, *psVar1, (ulong **)(DAT_800d1180 + 4));
			}
			iVar2 = iVar2 + 7;
			iVar4 = iVar4 + 1;
			psVar1 = psVar1 + 8;
			pmVar3 = pmVar3 + 1;
		} while (iVar4 < 8);
	}
	return;
}
