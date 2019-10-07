#include "THISDUST.H"
#include "MEMCARD.H"


// decompiled code
// original method signature: 
// int /*$ra*/ MEMCARD_IsWrongVersion(struct memcard_t *memcard /*$a0*/)
 // line 58, offset 0x800b81cc
	/* begin block 1 */
		// Start line: 60
		// Start offset: 0x800B81CC
		// Variables:
	// 		int result; // $v0
	/* end block 1 */
	// End offset: 0x800B81D8
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
  if (memcard != (memcard_t *)0x0) {
    iVar1 = (int)memcard->wrongVerison;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ load(struct memcard_t *memcard /*$s1*/)
 // line 71, offset 0x800b81e0
	/* begin block 1 */
		// Start line: 72
		// Start offset: 0x800B81E0
		// Variables:
	// 		struct Object *object; // $s0
	/* end block 1 */
	// End offset: 0x800B8298
	// End Line: 111

	/* begin block 2 */
		// Start line: 142
	/* end block 2 */
	// End Line: 143

void load(memcard_t *memcard)

{
  Object *loadAddr;
  
  if ((gameTrackerX.gameFlags & 0x8000000U) == 0) {
    loadAddr = (Object *)MEMPACK_Malloc((u_long)&DAT_00009c40,'+');
  }
  else {
    loadAddr = (Object *)(gameTrackerX.primPool)->prim;
  }
  LOAD_LoadToAddress("\\kain2\\object\\mcardx\\mcardx.drm",loadAddr,1);
  memcard->table = (mcmenu_table_t *)loadAddr->relocModule;
  RELMOD_InitModulePointers((int)loadAddr->relocModule,(int *)loadAddr->relocList);
  memcard->object = loadAddr;
  if (memcard->table->versionID != "May 25 1999") {
    if ((gameTrackerX.gameFlags & 0x8000000U) == 0) {
      MEMPACK_Free((char *)loadAddr);
    }
    memcard->table = (mcmenu_table_t *)0x0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ unload(struct memcard_t *memcard /*$s0*/)
 // line 113, offset 0x800b82ac
	/* begin block 1 */
		// Start line: 242
	/* end block 1 */
	// End Line: 243

void unload(memcard_t *memcard)

{
  Object *address;
  
  address = memcard->object;
  if (address != (Object *)0x0) {
    if (address != (Object *)(gameTrackerX.primPool)->prim) {
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
 // line 129, offset 0x800b8300
	/* begin block 1 */
		// Start line: 274
	/* end block 1 */
	// End Line: 275

	/* begin block 2 */
		// Start line: 275
	/* end block 2 */
	// End Line: 276

/* WARNING: Unknown calling convention yet parameter storage is locked */

int memcard_data_size(void)

{
  return 0x10;
}



// decompiled code
// original method signature: 
// int /*$ra*/ memcard_initialize(struct memcard_t *memcard /*$s0*/, void *gt /*$a1*/, int nblocks /*$s2*/, void *buffer /*$s3*/, int nbytes /*stack 16*/)
 // line 144, offset 0x800b8308
	/* begin block 1 */
		// Start line: 145
		// Start offset: 0x800B8308
		// Variables:
	// 		int header_size; // $s1
	/* end block 1 */
	// End offset: 0x800B83A8
	// End Line: 173

	/* begin block 2 */
		// Start line: 304
	/* end block 2 */
	// End Line: 305

int memcard_initialize(memcard_t *memcard,void *gt,int nblocks,void *buffer,int nbytes)

{
  int iVar1;
  
  memset(memcard,0,0x10);
  load(memcard);
  memcard->wrongVerison = 0;
  if (memcard->table == (mcmenu_table_t *)0x0) {
    memcard->wrongVerison = 1;
    iVar1 = 0;
  }
  else {
    *(MEMCARD_211fake **)&memcard->mcmenu = &gMcmenu;
    (*memcard->table->initialize)(&gMcmenu,memcard,nblocks);
    iVar1 = (*memcard->table->set_buffer)(memcard->mcmenu,buffer,nbytes);
    unload(memcard);
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ memcard_end(struct memcard_t *memcard /*$s0*/)
 // line 178, offset 0x800b83c8
	/* begin block 1 */
		// Start line: 389
	/* end block 1 */
	// End Line: 390

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
 // line 186, offset 0x800b840c
	/* begin block 1 */
		// Start line: 405
	/* end block 1 */
	// End Line: 406

int maybe_start(memcard_t *memcard)

{
  if (memcard->running == 0) {
    if (memcard->object == (Object *)0x0) {
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
 // line 205, offset 0x800b8478
	/* begin block 1 */
		// Start line: 206
		// Start offset: 0x800B8478
		// Variables:
	// 		struct memcard_t *memcard; // $s0
	/* end block 1 */
	// End offset: 0x800B84B8
	// End Line: 211

	/* begin block 2 */
		// Start line: 444
	/* end block 2 */
	// End Line: 445

int memcard_main_menu(void *gt,int index)

{
  int iVar1;
  int iVar2;
  memcard_t *memcard;
  
  memcard = *(memcard_t **)((int)gt + 0x24);
  iVar1 = maybe_start(memcard);
  iVar2 = -1;
  if (iVar1 != 0) {
    iVar2 = (*memcard->table->main)(memcard->mcmenu,index);
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ memcard_pause_menu(void *gt /*$a0*/, int index /*$s1*/)
 // line 213, offset 0x800b84cc
	/* begin block 1 */
		// Start line: 214
		// Start offset: 0x800B84CC
		// Variables:
	// 		struct memcard_t *memcard; // $s0
	/* end block 1 */
	// End offset: 0x800B850C
	// End Line: 219

	/* begin block 2 */
		// Start line: 461
	/* end block 2 */
	// End Line: 462

int memcard_pause_menu(void *gt,int index)

{
  int iVar1;
  int iVar2;
  memcard_t *memcard;
  
  memcard = *(memcard_t **)((int)gt + 0x24);
  iVar1 = maybe_start(memcard);
  iVar2 = -1;
  if (iVar1 != 0) {
    iVar2 = (*memcard->table->pause)(memcard->mcmenu,index);
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ gt2mcmenu(void *gt /*$a0*/)
 // line 225, offset 0x800b8520
	/* begin block 1 */
		// Start line: 227
		// Start offset: 0x800B8520
		// Variables:
	// 		struct memcard_t *memcard; // $v0
	/* end block 1 */
	// End offset: 0x800B8520
	// End Line: 227

	/* begin block 2 */
		// Start line: 486
	/* end block 2 */
	// End Line: 487

	/* begin block 3 */
		// Start line: 487
	/* end block 3 */
	// End Line: 488

void * gt2mcmenu(void *gt)

{
  return *(void **)(*(int *)((int)gt + 0x24) + 8);
}



// decompiled code
// original method signature: 
// void /*$ra*/ memcard_pop(void *opaque /*$a0*/)
 // line 231, offset 0x800b8534
	/* begin block 1 */
		// Start line: 498
	/* end block 1 */
	// End Line: 499

void memcard_pop(void *opaque)

{
  menu_pop(gameTrackerX.menu);
  memcard_end(gameTrackerX.memcard);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ memcard_start(void *opaque /*$a0*/)
 // line 239, offset 0x800b8570
	/* begin block 1 */
		// Start line: 517
	/* end block 1 */
	// End Line: 518

void memcard_start(void *opaque)

{
  gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x1000000;
  MAIN_StartGame();
  memcard_end(gameTrackerX.memcard);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ memcard_load(void *opaque /*$a0*/)
 // line 248, offset 0x800b85b4
	/* begin block 1 */
		// Start line: 538
	/* end block 1 */
	// End Line: 539

void memcard_load(void *opaque)

{
  gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x200000;
  SAVE_RestoreGame();
  MAIN_StartGame();
  memcard_end(gameTrackerX.memcard);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ memcard_save(void *opaque /*$a0*/)
 // line 257, offset 0x800b8600
	/* begin block 1 */
		// Start line: 558
	/* end block 1 */
	// End Line: 559

void memcard_save(void *opaque)

{
  SAVE_SaveGame();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ memcard_item(void *opaque /*$a0*/, TDRFuncPtr_memcard_item1fn fn /*$a1*/, long parameter /*$a2*/, long flags /*$a3*/, char *text /*stack 16*/)
 // line 262, offset 0x800b8620
	/* begin block 1 */
		// Start line: 568
	/* end block 1 */
	// End Line: 569

void memcard_item(void *opaque,TDRFuncPtr_memcard_item1fn fn,long parameter,long flags,char *text)

{
  if (flags == 0) {
    menu_item(gameTrackerX.menu,(TDRFuncPtr_menu_item1fn)fn,parameter,text);
  }
  else {
    menu_item_flags(gameTrackerX.menu,(TDRFuncPtr_menu_item_flags1fn)fn,parameter,flags,text);
  }
  return;
}





