#include "THISDUST.H"
#include "MENUFACE.H"

// _ButtonTexture * @0x800D5C04, len = 0x00000004
FaceButtons = null;
// int @0x800CFB3C, len = 0x00000004
hack_initialized = 0x0;
// menuface_t[8] @0x800CFABC, len = 0x00000080
MenuFaces =
	{
		// menuface_t @0x800CFABC, len = 0x00000010
		{
			// short @0x800CFABC, len = 0x00000002
			.x = 0xec,
			// short @0x800CFABE, len = 0x00000002
			.y = 0x31,
			// char @0x800CFAC0, len = 0x00000001
			.w = 0x30,
			// char @0x800CFAC1, len = 0x00000001
			.h = 0x30,
			// char @0x800CFAC2, len = 0x00000001
			.frames = 0x02,
			// short @0x800CFAC4, len = 0x00000002
			.curFrame = -0x1,
			// short @0x800CFAC6, len = 0x00000002
			.transitionDir = 0x0,
			// ushort @0x800CFAC8, len = 0x00000002
			.delay = 0x0,
			// ushort @0x800CFACA, len = 0x00000002
			.loaded = 0x0},
		// menuface_t @0x800CFACC, len = 0x00000010
		{
			// short @0x800CFACC, len = 0x00000002
			.x = 0x10c,
			// short @0x800CFACE, len = 0x00000002
			.y = 0x61,
			// char @0x800CFAD0, len = 0x00000001
			.w = 0x30,
			// char @0x800CFAD1, len = 0x00000001
			.h = 0x30,
			// char @0x800CFAD2, len = 0x00000001
			.frames = 0x02,
			// short @0x800CFAD4, len = 0x00000002
			.curFrame = -0x1,
			// short @0x800CFAD6, len = 0x00000002
			.transitionDir = 0x0,
			// ushort @0x800CFAD8, len = 0x00000002
			.delay = 0x0,
			// ushort @0x800CFADA, len = 0x00000002
			.loaded = 0x0},
		// menuface_t @0x800CFADC, len = 0x00000010
		{
			// short @0x800CFADC, len = 0x00000002
			.x = 0x111,
			// short @0x800CFADE, len = 0x00000002
			.y = 0x9c,
			// char @0x800CFAE0, len = 0x00000001
			.w = 0x30,
			// char @0x800CFAE1, len = 0x00000001
			.h = 0x30,
			// char @0x800CFAE2, len = 0x00000001
			.frames = 0x02,
			// short @0x800CFAE4, len = 0x00000002
			.curFrame = -0x1,
			// short @0x800CFAE6, len = 0x00000002
			.transitionDir = 0x0,
			// ushort @0x800CFAE8, len = 0x00000002
			.delay = 0x0,
			// ushort @0x800CFAEA, len = 0x00000002
			.loaded = 0x0},
		// menuface_t @0x800CFAEC, len = 0x00000010
		{
			// short @0x800CFAEC, len = 0x00000002
			.x = 0x146,
			// short @0x800CFAEE, len = 0x00000002
			.y = 0x31,
			// char @0x800CFAF0, len = 0x00000001
			.w = 0x30,
			// char @0x800CFAF1, len = 0x00000001
			.h = 0x30,
			// char @0x800CFAF2, len = 0x00000001
			.frames = 0x02,
			// short @0x800CFAF4, len = 0x00000002
			.curFrame = -0x1,
			// short @0x800CFAF6, len = 0x00000002
			.transitionDir = 0x0,
			// ushort @0x800CFAF8, len = 0x00000002
			.delay = 0x0,
			// ushort @0x800CFAFA, len = 0x00000002
			.loaded = 0x0},
		// menuface_t @0x800CFAFC, len = 0x00000010
		{
			// short @0x800CFAFC, len = 0x00000002
			.x = 0x156,
			// short @0x800CFAFE, len = 0x00000002
			.y = 0x78,
			// char @0x800CFB00, len = 0x00000001
			.w = 0x30,
			// char @0x800CFB01, len = 0x00000001
			.h = 0x30,
			// char @0x800CFB02, len = 0x00000001
			.frames = 0x02,
			// short @0x800CFB04, len = 0x00000002
			.curFrame = -0x1,
			// short @0x800CFB06, len = 0x00000002
			.transitionDir = 0x0,
			// ushort @0x800CFB08, len = 0x00000002
			.delay = 0x0,
			// ushort @0x800CFB0A, len = 0x00000002
			.loaded = 0x0},
		// menuface_t @0x800CFB0C, len = 0x00000010
		{
			// short @0x800CFB0C, len = 0x00000002
			.x = 0x199,
			// short @0x800CFB0E, len = 0x00000002
			.y = 0xe,
			// char @0x800CFB10, len = 0x00000001
			.w = 0x40,
			// char @0x800CFB11, len = 0x00000001
			.h = 0x40,
			// char @0x800CFB12, len = 0x00000001
			.frames = 0x02,
			// short @0x800CFB14, len = 0x00000002
			.curFrame = -0x1,
			// short @0x800CFB16, len = 0x00000002
			.transitionDir = 0x0,
			// ushort @0x800CFB18, len = 0x00000002
			.delay = 0x0,
			// ushort @0x800CFB1A, len = 0x00000002
			.loaded = 0x0},
		// menuface_t @0x800CFB1C, len = 0x00000010
		{
			// short @0x800CFB1C, len = 0x00000002
			.x = 0x17f,
			// short @0x800CFB1E, len = 0x00000002
			.y = 0x4e,
			// char @0x800CFB20, len = 0x00000001
			.w = 0x30,
			// char @0x800CFB21, len = 0x00000001
			.h = 0x30,
			// char @0x800CFB22, len = 0x00000001
			.frames = 0x02,
			// short @0x800CFB24, len = 0x00000002
			.curFrame = -0x1,
			// short @0x800CFB26, len = 0x00000002
			.transitionDir = 0x0,
			// ushort @0x800CFB28, len = 0x00000002
			.delay = 0x0,
			// ushort @0x800CFB2A, len = 0x00000002
			.loaded = 0x0},
		// menuface_t @0x800CFB2C, len = 0x00000010
		{
			// short @0x800CFB2C, len = 0x00000002
			.x = 0x190,
			// short @0x800CFB2E, len = 0x00000002
			.y = 0x96,
			// char @0x800CFB30, len = 0x00000001
			.w = 0x30,
			// char @0x800CFB31, len = 0x00000001
			.h = 0x30,
			// char @0x800CFB32, len = 0x00000001
			.frames = 0x02,
			// short @0x800CFB34, len = 0x00000002
			.curFrame = -0x1,
			// short @0x800CFB36, len = 0x00000002
			.transitionDir = 0x0,
			// ushort @0x800CFB38, len = 0x00000002
			.delay = 0x0,
			// ushort @0x800CFB3A, len = 0x00000002
			.loaded = 0x0}};
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

char *NextTimAddr(char *addr, int w, int h, bdepth bpp)

{
	int iVar1;

	if (bpp == TIM_4BIT)
	{
		iVar1 = (w * h >> 1) + 0x2c;
	}
	else
	{
		if (bpp == TIM_8BIT)
		{
			iVar1 = w * h + 0x20c;
		}
		else
		{
			iVar1 = w * h * 2;
		}
	}
	return addr + iVar1 + 0x14;
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

/* WARNING: Unknown calling convention yet parameter storage is locked */

void menuface_initialize(void)

{
	uint uVar1;
	long *address;
	menuface_t *pmVar2;
	uint uVar3;
	long *addr;
	int iVar4;
	int iVar5;

	if ((hack_initialized == 0) &&
		(address = LOAD_ReadFile(s__kain2_game_psx_frontend_faces_t_800cfb40, '\v'),
		 address != (long *)0x0))
	{
		FaceButtons = (_ButtonTexture *)MEMPACK_Malloc(0x380, '-');
		iVar5 = 0;
		if (FaceButtons == (_ButtonTexture *)0x0)
		{
			MEMPACK_Free((char *)address);
		}
		else
		{
			pmVar2 = MenuFaces;
			iVar4 = 0;
			addr = address;
			do
			{
				uVar3 = 0;
				pmVar2->curFrame = -1;
				pmVar2->transitionDir = 0;
				pmVar2->loaded = 0;
				pmVar2->delay = 0;
				do
				{
					DRAW_LoadButton(addr, FaceButtons + iVar4 + uVar3);
					addr = (long *)NextTimAddr((char *)addr, (uint)(byte)pmVar2->w, (uint)(byte)pmVar2->h,
											   TIM_4BIT);
					uVar1 = uVar3 & 0x1f;
					uVar3 = uVar3 + 1;
					pmVar2->loaded = pmVar2->loaded | (ushort)(1 << uVar1);
				} while ((int)uVar3 < 7);
				pmVar2 = pmVar2 + 1;
				iVar5 = iVar5 + 1;
				iVar4 = iVar4 + 7;
			} while (iVar5 < 8);
			MEMPACK_Free((char *)address);
			hack_initialized = 1;
		}
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
					DRAW_FreeButton(FaceButtons + iVar3 + uVar1);
				}
				uVar1 = uVar1 + 1;
			} while ((int)uVar1 < 7);
			iVar3 = iVar3 + 7;
			iVar4 = iVar4 + 1;
			pmVar2 = pmVar2 + 1;
		} while (iVar4 < 8);
		MEMPACK_Free((char *)FaceButtons);
		hack_initialized = 0;
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
	int iVar3;
	ushort *puVar4;
	menuface_t *pmVar5;

	if (hack_initialized != 0)
	{
		pmVar5 = MenuFaces;
		puVar4 = &MenuFaces[0].delay;
		do
		{
			uVar1 = *puVar4 - 1;
			if (*puVar4 == 0)
			{
				if (puVar4[-1] == 0)
				{
					iVar3 = rand();
					if (iVar3 == (iVar3 / 500) * 500)
					{
						if (puVar4[-2] == 0xffff)
						{
							puVar4[-1] = 1;
						}
						else
						{
							puVar4[-1] = 0xffff;
						}
					}
				}
				else
				{
					uVar2 = puVar4[-2] + puVar4[-1];
					puVar4[-2] = uVar2;
					uVar1 = 200;
					if (((int)(short)uVar2 == (uint) * (byte *)(puVar4 + -3) * 7 + -1) ||
						((int)(short)uVar2 == -1))
					{
						puVar4[-1] = 0;
						goto LAB_800b984c;
					}
				}
			}
			else
			{
			LAB_800b984c:
				*puVar4 = uVar1;
			}
			pmVar5 = pmVar5 + 1;
			puVar4 = puVar4 + 8;
		} while (pmVar5 < &hack_initialized);
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
				DRAW_DrawButton(FaceButtons + iVar2 + (int)psVar1[3] / (int)(uint) * (byte *)(psVar1 + 2),
								pmVar3->x, *psVar1, gameTrackerX.drawOT + 1);
			}
			iVar2 = iVar2 + 7;
			iVar4 = iVar4 + 1;
			psVar1 = psVar1 + 8;
			pmVar3 = pmVar3 + 1;
		} while (iVar4 < 8);
	}
	return;
}
