#include "THISDUST.H"
#include "MEMCARD.H"

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

void load(memcard_t *memcard)

{
	Object *loadAddr;

	if ((gameTrackerX.gameFlags & 0x8000000U) == 0)
	{
		loadAddr = (Object *)MEMPACK_Malloc((u_long)&DAT_00009c40, '+');
	}
	else
	{
		loadAddr = (Object *)(gameTrackerX.primPool)->prim;
	}
	LOAD_LoadTIM("\\kain2\\object\\mcardx\\mcardx.drm", loadAddr, 1);
	memcard->table = (mcmenu_table_t *)loadAddr->relocModule;
	RELMOD_InitModulePointers((int)loadAddr->relocModule, (int *)loadAddr->relocList);
	memcard->object = loadAddr;
	if (memcard->table->versionID != "May 25 1999")
	{
		if ((gameTrackerX.gameFlags & 0x8000000U) == 0)
		{
			MEMPACK_Init((char *)loadAddr);
		}
		memcard->table = (mcmenu_table_t *)0x0;
	}
	return;
}

void unload(memcard_t *memcard)

{
	Object *address;

	address = memcard->object;
	if (address != (Object *)0x0)
	{
		if (address != (Object *)(gameTrackerX.primPool)->prim)
		{
			MEMPACK_Init((char *)address);
		}
		memcard->object = (Object *)0x0;
	}
	memcard->table = (mcmenu_table_t *)0x0;
	return;
}

int menu_data_size(void)

{
	return 0x10;
}

int memcard_item(memcard_t *memcard, void *gt, int nblocks, void *buffer, int nbytes)

{
	int iVar1;

	memset(memcard, 0, 0x10);
	load(memcard);
	memcard->wrongVerison = 0;
	if (memcard->table == (mcmenu_table_t *)0x0)
	{
		memcard->wrongVerison = 1;
		iVar1 = 0;
	}
	else
	{
		*(MEMCARD_211fake **)&memcard->mcmenu = &gMcmenu;
		(*memcard->table->initialize)(&gMcmenu, memcard, nblocks);
		iVar1 = (*memcard->table->set_buffer)(memcard->mcmenu, buffer, nbytes);
		unload(memcard);
	}
	return iVar1;
}

void memcard_data_size(memcard_t *memcard)

{
	(*memcard->table->end)(memcard->mcmenu);
	unload(memcard);
	memcard->running = 0;
	return;
}

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

int do_main_menu(void *gt, int index)

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

int menudefs_pause_menu(void *gt, int index)

{
	int iVar1;
	int iVar2;
	memcard_t *memcard;

	memcard = *(memcard_t **)((int)gt + 0x24);
	iVar1 = maybe_start(memcard);
	iVar2 = -1;
	if (iVar1 != 0)
	{
		iVar2 = (*memcard->table->pause)(memcard->mcmenu, index);
	}
	return iVar2;
}

void *gt2mcmenu(void *gt)

{
	return *(void **)(*(int *)((int)gt + 0x24) + 8);
}

void memcard_end(void *opaque)

{
	menu_pop(gameTrackerX.menu);
	memcard_data_size(gameTrackerX.memcard);
	return;
}

void memcard_main_menu(void *opaque)

{
	gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x1000000;
	MAIN_StartGame();
	memcard_data_size(gameTrackerX.memcard);
	return;
}

void memcard_start(void *opaque)

{
	gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x200000;
	SAVE_RestoreGlobalSaveTracker();
	MAIN_StartGame();
	memcard_data_size(gameTrackerX.memcard);
	return;
}

void memcard_pop(void *opaque)

{
	SAVE_SaveGame();
	return;
}

void memcard_initialize(void *opaque, TDRFuncPtr_memcard_item1fn fn, long parameter, long flags,
						char *text)

{
	if (flags == 0)
	{
		num_menu_items(gameTrackerX.menu, (TDRFuncPtr_menu_item1fn)fn, parameter, text);
	}
	else
	{
		menu_item_flags(gameTrackerX.menu, (TDRFuncPtr_menu_item_flags1fn)fn, parameter, flags, text);
	}
	return;
}
