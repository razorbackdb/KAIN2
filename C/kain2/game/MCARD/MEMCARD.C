#include "THISDUST.H"
#include "MEMCARD.H"

// decompiled code
// original method signature:
// int /*$ra*/ MEMCARD_IsWrongVersion(struct memcard_t *memcard /*$a0*/)
// line 58, offset 0x800b9924
/* begin block 1 */
// Start line: 60
// Start offset: 0x800B9924
// Variables:
// 		int result; // $v0
/* end block 1 */
// End offset: 0x800B9930
// End Line: 68

/* begin block 2 */
// Start line: 116
/* end block 2 */
// End Line: 117

/* begin block 3 */
// Start line: 117
/* end block 3 */
// End Line: 118

/* begin block 4 */
// Start line: 119
/* end block 4 */
// End Line: 120

int MEMCARD_IsWrongVersion(memcard_t *memcard)

{
	int iVar1;

	iVar1 = 1;
	if (memcard != (memcard_t *)0x0)
	{
		iVar1 = (int)memcard->wrongVerison;
	}
	return iVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ load(struct memcard_t *memcard /*$s1*/)
// line 71, offset 0x800b9938
/* begin block 1 */
// Start line: 72
// Start offset: 0x800B9938
// Variables:
// 		struct Object *object; // $s0
/* end block 1 */
// End offset: 0x800B99F0
// End Line: 115

/* begin block 2 */
// Start line: 142
/* end block 2 */
// End Line: 143

void load(memcard_t *memcard)

{
	if ((DAT_800d10ec & 0x8000000) != 0)
	{
		memcard_load(&gameTrackerX);
		return;
	}
	/* WARNING: Subroutine does not return */
	MEMPACK_Malloc((ulong)&DAT_00009c40, '+');
}

// decompiled code
// original method signature:
// void /*$ra*/ unload(struct memcard_t *memcard /*$s0*/)
// line 117, offset 0x800b9a04
/* begin block 1 */
// Start line: 253
/* end block 1 */
// End Line: 254

void unload(memcard_t *memcard)

{
	Object *address;

	address = memcard->object;
	if (address != (Object *)0x0)
	{
		if (address != (Object *)(DAT_800d0fec + 0xc))
		{
			/* WARNING: Subroutine does not return */
			MEMPACK_Free((char *)address);
		}
		memcard->object = (Object *)0x0;
	}
	memcard->table = (mcmenu_table_t *)0x0;
	return;
}

// decompiled code
// original method signature:
// int /*$ra*/ memcard_data_size()
// line 133, offset 0x800b9a58
/* begin block 1 */
// Start line: 285
/* end block 1 */
// End Line: 286

/* begin block 2 */
// Start line: 286
/* end block 2 */
// End Line: 287

/* WARNING: Unknown calling convention yet parameter storage is locked */

int memcard_data_size(void)

{
	return 0x10;
}

// decompiled code
// original method signature:
// int /*$ra*/ memcard_initialize(struct memcard_t *memcard /*$s0*/, void *gt /*$a1*/, int nblocks /*$s2*/, void *buffer /*$s3*/, int nbytes /*stack 16*/)
// line 148, offset 0x800b9a60
/* begin block 1 */
// Start line: 149
// Start offset: 0x800B9A60
// Variables:
// 		int header_size; // $s1
/* end block 1 */
// End offset: 0x800B9B00
// End Line: 177

/* begin block 2 */
// Start line: 315
/* end block 2 */
// End Line: 316

void memcard_initialize(void *param_1)

{
	/* WARNING: Subroutine does not return */
	memset(param_1, 0, 0x10);
}

// decompiled code
// original method signature:
// void /*$ra*/ memcard_end(struct memcard_t *memcard /*$s0*/)
// line 182, offset 0x800b9b20
/* begin block 1 */
// Start line: 400
/* end block 1 */
// End Line: 401

void memcard_end(memcard_t *memcard)

{
	(*memcard->table->end)(memcard->mcmenu);
	unload(memcard);
	memcard->running = 0;
	return;
}

// decompiled code
// original method signature:
// int /*$ra*/ maybe_start(struct memcard_t *memcard /*$s0*/)
// line 190, offset 0x800b9b64
/* begin block 1 */
// Start line: 416
/* end block 1 */
// End Line: 417

int maybe_start(memcard_t *memcard)

{
	if (memcard->running == 0)
	{
		if (memcard->object == (Object *)0x0)
		{
			load(memcard);
		}
		memcard->running = 1;
		(*memcard->table->begin)(memcard->mcmenu);
	}
	return 1;
}

// decompiled code
// original method signature:
// int /*$ra*/ memcard_main_menu(void *gt /*$a0*/, int index /*$s1*/)
// line 209, offset 0x800b9bd0
/* begin block 1 */
// Start line: 210
// Start offset: 0x800B9BD0
// Variables:
// 		struct memcard_t *memcard; // $s0
/* end block 1 */
// End offset: 0x800B9C10
// End Line: 215

/* begin block 2 */
// Start line: 455
/* end block 2 */
// End Line: 456

int memcard_main_menu(void *gt, int index)

{
	int iVar1;
	int iVar2;
	memcard_t *memcard;

	memcard = *(memcard_t **)((int)gt + 0x24);
	iVar1 = maybe_start(memcard);
	iVar2 = -1;
	if (iVar1 != 0)
	{
		iVar2 = (*memcard->table->main)(memcard->mcmenu, index);
	}
	return iVar2;
}

// decompiled code
// original method signature:
// int /*$ra*/ memcard_pause_menu(void *gt /*$a0*/, int index /*$s1*/)
// line 217, offset 0x800b9c24
/* begin block 1 */
// Start line: 218
// Start offset: 0x800B9C24
// Variables:
// 		struct memcard_t *memcard; // $s0
/* end block 1 */
// End offset: 0x800B9C64
// End Line: 223

/* begin block 2 */
// Start line: 472
/* end block 2 */
// End Line: 473

int memcard_pause_menu(int param_1, undefined4 param_2)

{
	int iVar1;
	int iVar2;
	memcard_t *memcard;

	memcard = *(memcard_t **)(param_1 + 0x24);
	iVar1 = maybe_start(memcard);
	iVar2 = -1;
	if (iVar1 != 0)
	{
		iVar2 = (*memcard->table->pause)(memcard->mcmenu, param_2);
	}
	return iVar2;
}

// decompiled code
// original method signature:
// void * /*$ra*/ gt2mcmenu(void *gt /*$a0*/)
// line 229, offset 0x800b9c78
/* begin block 1 */
// Start line: 231
// Start offset: 0x800B9C78
// Variables:
// 		struct memcard_t *memcard; // $v0
/* end block 1 */
// End offset: 0x800B9C78
// End Line: 231

/* begin block 2 */
// Start line: 497
/* end block 2 */
// End Line: 498

/* begin block 3 */
// Start line: 498
/* end block 3 */
// End Line: 499

void *gt2mcmenu(void *gt)

{
	return *(void **)(*(int *)((int)gt + 0x24) + 8);
}

// decompiled code
// original method signature:
// void /*$ra*/ memcard_pop(void *opaque /*$a0*/)
// line 235, offset 0x800b9c8c
/* begin block 1 */
// Start line: 509
/* end block 1 */
// End Line: 510

void memcard_pop(void *opaque)

{
	menu_pop(DAT_800d0fcc);
	memcard_end(DAT_800d0fd0);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ memcard_start(void *opaque /*$a0*/)
// line 243, offset 0x800b9cc8
/* begin block 1 */
// Start line: 528
/* end block 1 */
// End Line: 529

void memcard_start(void *opaque)

{
	DAT_800d10f0 = DAT_800d10f0 | 0x1000000;
	MAIN_StartGame();
	memcard_end(DAT_800d0fd0);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ memcard_load(void *opaque /*$a0*/)
// line 252, offset 0x800b9d0c
/* begin block 1 */
// Start line: 549
/* end block 1 */
// End Line: 550

void memcard_load(void *opaque)

{
	DAT_800d10f0 = DAT_800d10f0 | 0x200000;
	SAVE_RestoreGame();
	MAIN_StartGame();
	memcard_end(DAT_800d0fd0);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ memcard_save(void *opaque /*$a0*/)
// line 261, offset 0x800b9d58
/* begin block 1 */
// Start line: 569
/* end block 1 */
// End Line: 570

void memcard_save(void *opaque)

{
	SAVE_SaveGame();
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ memcard_item(void *opaque /*$a0*/, TDRFuncPtr_memcard_item1fn fn /*$a1*/, long parameter /*$a2*/, long flags /*$a3*/, char *text /*stack 16*/)
// line 266, offset 0x800b9d78
/* begin block 1 */
// Start line: 579
/* end block 1 */
// End Line: 580

void memcard_item(void *opaque, TDRFuncPtr_memcard_item1fn fn, long parameter, long flags, char *text)

{
	if (flags == 0)
	{
		menu_item(DAT_800d0fcc, (TDRFuncPtr_menu_item1fn)fn, parameter, text);
	}
	else
	{
		menu_item_flags(DAT_800d0fcc, (TDRFuncPtr_menu_item_flags1fn)fn, parameter, flags, text);
	}
	return;
}
