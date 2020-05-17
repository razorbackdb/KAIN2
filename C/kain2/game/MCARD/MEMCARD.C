#include "THISDUST.H"
#include "MEMCARD.H"


// decompiled code
// original method signature: 
// int /*$ra*/ MEMCARD_IsWrongVersion(struct memcard_t *memcard /*$a0*/)
 // line 58, offset 0x800b959c
	/* begin block 1 */
		// Start line: 60
		// Start offset: 0x800B959C
		// Variables:
	// 		int result; // $v0
	/* end block 1 */
	// End offset: 0x800B95A8
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
 // line 71, offset 0x800b95b0
	/* begin block 1 */
		// Start line: 72
		// Start offset: 0x800B95B0
		// Variables:
	// 		struct Object *object; // $s0
	/* end block 1 */
	// End offset: 0x800B9668
	// End Line: 115

	/* begin block 2 */
		// Start line: 142
	/* end block 2 */
	// End Line: 143

void load(memcard_t *memcard)

{
  Object *loadAddr;
  
  if ((gameTrackerX.gameFlags & 0x8000000U) == 0) {
    loadAddr = (Object *)MEMPACK_Malloc((ulong)&DAT_00009c40,'+');
  }
  else {
    loadAddr = (Object *)(gameTrackerX.primPool)->prim;
  }
  LOAD_LoadToAddress("\\kain2\\object\\mcardx\\mcardx.drm",loadAddr,1);
  memcard->table = (mcmenu_table_t *)loadAddr->relocModule;
  RELMOD_InitModulePointers((int)loadAddr->relocModule,(int *)loadAddr->relocList);
  memcard->object = loadAddr;
  if (memcard->table->versionID != "Jun 30 1999") {
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
 // line 117, offset 0x800b967c
	/* begin block 1 */
		// Start line: 253
	/* end block 1 */
	// End Line: 254

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
 // line 133, offset 0x800b96d0
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
 // line 148, offset 0x800b96d8
	/* begin block 1 */
		// Start line: 149
		// Start offset: 0x800B96D8
		// Variables:
	// 		int header_size; // $s1
	/* end block 1 */
	// End offset: 0x800B9778
	// End Line: 177

	/* begin block 2 */
		// Start line: 315
	/* end block 2 */
	// End Line: 316

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
    *(MEMCARD_216fake **)&memcard->mcmenu = &gMcmenu;
    (*memcard->table->initialize)(&gMcmenu,memcard,nblocks);
    iVar1 = (*memcard->table->set_buffer)(memcard->mcmenu,buffer,nbytes);
    unload(memcard);
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ memcard_end(struct memcard_t *memcard /*$s0*/)
 // line 182, offset 0x800b9798
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
 // line 190, offset 0x800b97dc
	/* begin block 1 */
		// Start line: 416
	/* end block 1 */
	// End Line: 417

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
 // line 209, offset 0x800b9848
	/* begin block 1 */
		// Start line: 210
		// Start offset: 0x800B9848
		// Variables:
	// 		struct memcard_t *memcard; // $s0
	/* end block 1 */
	// End offset: 0x800B9888
	// End Line: 215

	/* begin block 2 */
		// Start line: 455
	/* end block 2 */
	// End Line: 456

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
 // line 217, offset 0x800b989c
	/* begin block 1 */
		// Start line: 218
		// Start offset: 0x800B989C
		// Variables:
	// 		struct memcard_t *memcard; // $s0
	/* end block 1 */
	// End offset: 0x800B98DC
	// End Line: 223

	/* begin block 2 */
		// Start line: 472
	/* end block 2 */
	// End Line: 473

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
 // line 229, offset 0x800b98f0
	/* begin block 1 */
		// Start line: 231
		// Start offset: 0x800B98F0
		// Variables:
	// 		struct memcard_t *memcard; // $v0
	/* end block 1 */
	// End offset: 0x800B98F0
	// End Line: 231

	/* begin block 2 */
		// Start line: 497
	/* end block 2 */
	// End Line: 498

	/* begin block 3 */
		// Start line: 498
	/* end block 3 */
	// End Line: 499

void * gt2mcmenu(void *gt)

{
  return *(void **)(*(int *)((int)gt + 0x24) + 8);
}



// decompiled code
// original method signature: 
// void /*$ra*/ memcard_pop(void *opaque /*$a0*/)
 // line 235, offset 0x800b9904
	/* begin block 1 */
		// Start line: 509
	/* end block 1 */
	// End Line: 510

void memcard_pop(void *opaque)

{
  menu_pop(gameTrackerX.menu);
  memcard_end(gameTrackerX.memcard);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ memcard_start(void *opaque /*$a0*/)
 // line 243, offset 0x800b9940
	/* begin block 1 */
		// Start line: 528
	/* end block 1 */
	// End Line: 529

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
 // line 252, offset 0x800b9984
	/* begin block 1 */
		// Start line: 549
	/* end block 1 */
	// End Line: 550

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
 // line 261, offset 0x800b99d0
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
 // line 266, offset 0x800b99f0
	/* begin block 1 */
		// Start line: 579
	/* end block 1 */
	// End Line: 580

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





