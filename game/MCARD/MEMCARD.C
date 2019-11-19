#include "THISDUST.H"
#include "MEMCARD.H"


// decompiled code
// original method signature: 
// int /*$ra*/ MEMCARD_IsWrongVersion(struct memcard_t *memcard /*$a0*/)
 // line 65, offset 0x800b3bc8
	/* begin block 1 */
		// Start line: 67
		// Start offset: 0x800B3BC8
		// Variables:
	// 		int result; // $v0
	/* end block 1 */
	// End offset: 0x800B3BD4
	// End Line: 75

	/* begin block 2 */
		// Start line: 130
	/* end block 2 */
	// End Line: 131

	/* begin block 3 */
		// Start line: 131
	/* end block 3 */
	// End Line: 132

	/* begin block 4 */
		// Start line: 133
	/* end block 4 */
	// End Line: 134

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
 // line 78, offset 0x800b3bdc
	/* begin block 1 */
		// Start line: 79
		// Start offset: 0x800B3BDC
		// Variables:
	// 		struct Object *object; // $s0
	/* end block 1 */
	// End offset: 0x800B3CA4
	// End Line: 120

	/* begin block 2 */
		// Start line: 156
	/* end block 2 */
	// End Line: 157

void load(memcard_t *memcard)

{
  Object *loadAddr;
  
  if ((gameTrackerX.gameFlags & 0x8000000U) == 0) {
    loadAddr = (Object *)MEMPACK_Malloc(40000,'+');
  }
  else {
    loadAddr = (Object *)(gameTrackerX.primPool)->prim;
  }
  LOAD_LoadToAddress("\\kain2\\object\\mcardx\\mcardx.drm",loadAddr,1);
  memcard->table = (mcmenu_table_t *)loadAddr->relocModule;
  RELMOD_InitModulePointers((int)loadAddr->relocModule,(int *)loadAddr->relocList);
  memcard->object = loadAddr;
  if (memcard->table->versionID != "May 12 1999") {
    GXFilePrint(
               "MEMCARD : Version is wrong for relocatable object. %x!=%x\nMEMCARD : Disabling memory card.\n"
               );
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
 // line 122, offset 0x800b3cb8
	/* begin block 1 */
		// Start line: 261
	/* end block 1 */
	// End Line: 262

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
 // line 139, offset 0x800b3d0c
	/* begin block 1 */
		// Start line: 295
	/* end block 1 */
	// End Line: 296

	/* begin block 2 */
		// Start line: 296
	/* end block 2 */
	// End Line: 297

/* WARNING: Unknown calling convention yet parameter storage is locked */

int memcard_data_size(void)

{
  return 0x14;
}



// decompiled code
// original method signature: 
// int /*$ra*/ memcard_initialize(struct memcard_t *memcard /*$s1*/, void *gt /*$s0*/, int nblocks /*$s2*/, void *buffer /*$s3*/, int nbytes /*stack 16*/)
 // line 148, offset 0x800b3d14
	/* begin block 1 */
		// Start line: 149
		// Start offset: 0x800B3D14
		// Variables:
	// 		int header_size; // $s0
	/* end block 1 */
	// End offset: 0x800B3DD8
	// End Line: 176

	/* begin block 2 */
		// Start line: 313
	/* end block 2 */
	// End Line: 314

int memcard_initialize(memcard_t *memcard,void *gt,int nblocks,void *buffer,int nbytes)

{
  ulong allocSize;
  mcmenu_t *pmVar1;
  int iVar2;
  
  memset(memcard,0,0x14);
  memcard[1].object = gt;
  load(memcard);
  memcard->wrongVerison = 0;
  if (memcard->table == (mcmenu_table_t *)0x0) {
    memcard->wrongVerison = 1;
    iVar2 = 0;
  }
  else {
    allocSize = (*memcard->table->data_size)();
    pmVar1 = (mcmenu_t *)MEMPACK_Malloc(allocSize,'+');
    memcard->mcmenu = pmVar1;
    (*memcard->table->initialize)(pmVar1,memcard,nblocks);
    iVar2 = (*memcard->table->set_buffer)(memcard->mcmenu,buffer,nbytes);
    unload(memcard);
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ memcard_end(struct memcard_t *memcard /*$s0*/)
 // line 181, offset 0x800b3df8
	/* begin block 1 */
		// Start line: 396
	/* end block 1 */
	// End Line: 397

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
 // line 189, offset 0x800b3e3c
	/* begin block 1 */
		// Start line: 412
	/* end block 1 */
	// End Line: 413

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
 // line 208, offset 0x800b3ea8
	/* begin block 1 */
		// Start line: 209
		// Start offset: 0x800B3EA8
		// Variables:
	// 		struct memcard_t *memcard; // $s0
	/* end block 1 */
	// End offset: 0x800B3EE8
	// End Line: 214

	/* begin block 2 */
		// Start line: 451
	/* end block 2 */
	// End Line: 452

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
 // line 216, offset 0x800b3efc
	/* begin block 1 */
		// Start line: 217
		// Start offset: 0x800B3EFC
		// Variables:
	// 		struct memcard_t *memcard; // $s0
	/* end block 1 */
	// End offset: 0x800B3F3C
	// End Line: 222

	/* begin block 2 */
		// Start line: 468
	/* end block 2 */
	// End Line: 469

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
 // line 228, offset 0x800b3f50
	/* begin block 1 */
		// Start line: 230
		// Start offset: 0x800B3F50
		// Variables:
	// 		struct memcard_t *memcard; // $v0
	/* end block 1 */
	// End offset: 0x800B3F50
	// End Line: 230

	/* begin block 2 */
		// Start line: 493
	/* end block 2 */
	// End Line: 494

	/* begin block 3 */
		// Start line: 494
	/* end block 3 */
	// End Line: 495

void * gt2mcmenu(void *gt)

{
  return *(void **)(*(int *)((int)gt + 0x24) + 8);
}



// decompiled code
// original method signature: 
// void /*$ra*/ memcard_pop(void *opaque /*$s0*/)
 // line 234, offset 0x800b3f64
	/* begin block 1 */
		// Start line: 235
		// Start offset: 0x800B3F64
	/* end block 1 */
	// End offset: 0x800B3F64
	// End Line: 235

	/* begin block 2 */
		// Start line: 505
	/* end block 2 */
	// End Line: 506

void memcard_pop(void *opaque)

{
  menu_pop(*(menu_t **)(*(int *)((int)opaque + 0x10) + 0x20));
  memcard_end(*(memcard_t **)(*(int *)((int)opaque + 0x10) + 0x24));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ memcard_start(void *opaque /*$s0*/)
 // line 245, offset 0x800b3fac
	/* begin block 1 */
		// Start line: 246
		// Start offset: 0x800B3FAC
	/* end block 1 */
	// End offset: 0x800B3FAC
	// End Line: 246

	/* begin block 2 */
		// Start line: 527
	/* end block 2 */
	// End Line: 528

void memcard_start(void *opaque)

{
  *(uint *)(*(int *)((int)opaque + 0x10) + 0x144) =
       *(uint *)(*(int *)((int)opaque + 0x10) + 0x144) | 0x1000000;
  MAIN_StartGame();
  memcard_end(*(memcard_t **)(*(int *)((int)opaque + 0x10) + 0x24));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ memcard_load(void *opaque /*$s0*/)
 // line 257, offset 0x800b3ffc
	/* begin block 1 */
		// Start line: 258
		// Start offset: 0x800B3FFC
	/* end block 1 */
	// End offset: 0x800B3FFC
	// End Line: 258

	/* begin block 2 */
		// Start line: 551
	/* end block 2 */
	// End Line: 552

void memcard_load(void *opaque)

{
  *(uint *)(*(int *)((int)opaque + 0x10) + 0x144) =
       *(uint *)(*(int *)((int)opaque + 0x10) + 0x144) | 0x200000;
  SAVE_RestoreGame();
  MAIN_StartGame();
  memcard_end(*(memcard_t **)(*(int *)((int)opaque + 0x10) + 0x24));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ memcard_save(void *opaque /*$a0*/)
 // line 270, offset 0x800b4054
	/* begin block 1 */
		// Start line: 577
	/* end block 1 */
	// End Line: 578

void memcard_save(void *opaque)

{
  SAVE_SaveGame();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ memcard_item(void *opaque /*$a0*/, TDRFuncPtr_memcard_item1fn fn /*$a1*/, long parameter /*$a2*/, char *text /*$a3*/)
 // line 275, offset 0x800b4074
	/* begin block 1 */
		// Start line: 276
		// Start offset: 0x800B4074
	/* end block 1 */
	// End offset: 0x800B4074
	// End Line: 276

	/* begin block 2 */
		// Start line: 587
	/* end block 2 */
	// End Line: 588

void memcard_item(void *opaque,TDRFuncPtr_memcard_item1fn fn,long parameter,char *text)

{
  menu_item(*(menu_t **)(*(int *)((int)opaque + 0x10) + 0x20),(TDRFuncPtr_menu_item1fn)fn,parameter,
            text);
  return;
}





