#include "THISDUST.H"
#include "STREAM.H"


// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_FillOutFileNames(char *baseAreaName /*$s0*/, char *dramName /*$s1*/, char *vramName /*$s2*/, char *sfxName /*$s3*/)
 // line 162, offset 0x80058a00
	/* begin block 1 */
		// Start line: 163
		// Start offset: 0x80058A00
		// Variables:
	// 		char text[16]; // stack offset -40
	// 		char *number; // $v0
	/* end block 1 */
	// End offset: 0x80058AA4
	// End Line: 187

	/* begin block 2 */
		// Start line: 324
	/* end block 2 */
	// End Line: 325

void STREAM_FillOutFileNames(char *baseAreaName,char *dramName,char *vramName,char *sfxName)

{
  char *pcVar1;
  char acStack40 [16];
  
  strcpy(acStack40,baseAreaName);
  pcVar1 = strpbrk(acStack40,"0123456789");
  if (pcVar1 != (char *)0x0) {
    *pcVar1 = '\0';
  }
  if (dramName != (char *)0x0) {
    sprintf(dramName,"\\kain2\\area\\%s\\bin\\%s.drm");
  }
  if (vramName != (char *)0x0) {
    sprintf(vramName,"\\kain2\\area\\%s\\bin\\%s.crm");
  }
  if (sfxName != (char *)0x0) {
    sprintf(sfxName,"\\kain2\\area\\%s\\bin\\%s.snf");
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_AbortAreaLoad(char *baseAreaName /*$s0*/)
 // line 192, offset 0x80058ac0
	/* begin block 1 */
		// Start line: 193
		// Start offset: 0x80058AC0
		// Variables:
	// 		char vramName[80]; // stack offset -88
	/* end block 1 */
	// End offset: 0x80058AC0
	// End Line: 193

	/* begin block 2 */
		// Start line: 387
	/* end block 2 */
	// End Line: 388

void STREAM_AbortAreaLoad(char *baseAreaName)

{
  char acStack88 [80];
  
  STREAM_FillOutFileNames(baseAreaName,(char *)0x0,acStack88,(char *)0x0);
  LOAD_AbortDirectoryChange(baseAreaName);
  LOAD_AbortFileLoad(acStack88,VRAM_LoadReturn);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_Init()
 // line 204, offset 0x80058b08
	/* begin block 1 */
		// Start line: 206
		// Start offset: 0x80058B08
		// Variables:
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x80058B2C
	// End Line: 214

	/* begin block 2 */
		// Start line: 414
	/* end block 2 */
	// End Line: 415

	/* begin block 3 */
		// Start line: 415
	/* end block 3 */
	// End Line: 416

	/* begin block 4 */
		// Start line: 417
	/* end block 4 */
	// End Line: 418

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_Init(void)

{
  STracker *pSVar1;
  int iVar2;
  
  iVar2 = 0;
  pSVar1 = &StreamTracker;
  do {
    pSVar1->StreamList[0].used = 0;
    pSVar1->StreamList[0].flags = 0;
    pSVar1->StreamList[0].StreamUnitID = 0;
    iVar2 = iVar2 + 1;
    pSVar1 = (STracker *)(pSVar1->StreamList + 1);
  } while (iVar2 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ FindObjectName(char *name /*$s2*/)
 // line 216, offset 0x80058b34
	/* begin block 1 */
		// Start line: 217
		// Start offset: 0x80058B34
		// Variables:
	// 		int i; // $s0
	// 		struct _ObjectTracker *otr; // $s1
	/* end block 1 */
	// End offset: 0x80058B88
	// End Line: 228

	/* begin block 2 */
		// Start line: 442
	/* end block 2 */
	// End Line: 443

int FindObjectName(char *name)

{
  int iVar1;
  int iVar2;
  _ObjectTracker *s1;
  
  iVar2 = 0;
  s1 = gameTrackerX.GlobalObjects;
  while ((s1->objectStatus == 0 || (iVar1 = strcmpi((char *)s1,name), iVar1 != 0))) {
    iVar2 = iVar2 + 1;
    s1 = s1 + 1;
    if (0x2f < iVar2) {
      return -1;
    }
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// struct _ObjectTracker * /*$ra*/ FindObjectInTracker(struct Object *object /*$a0*/)
 // line 230, offset 0x80058ba0
	/* begin block 1 */
		// Start line: 232
		// Start offset: 0x80058BA0
		// Variables:
	// 		int i; // $a2
	// 		struct _ObjectTracker *otr; // $a1
	/* end block 1 */
	// End offset: 0x80058BE8
	// End Line: 240

	/* begin block 2 */
		// Start line: 480
	/* end block 2 */
	// End Line: 481

	/* begin block 3 */
		// Start line: 481
	/* end block 3 */
	// End Line: 482

	/* begin block 4 */
		// Start line: 484
	/* end block 4 */
	// End Line: 485

_ObjectTracker * FindObjectInTracker(Object *object)

{
  Object **ppOVar1;
  _ObjectTracker *p_Var2;
  int iVar3;
  
  iVar3 = 0;
  ppOVar1 = &(gameTrackerX.GlobalObjects)->object;
  p_Var2 = gameTrackerX.GlobalObjects;
  while ((*(short *)(ppOVar1 + 1) == 0 || (*ppOVar1 != object))) {
    iVar3 = iVar3 + 1;
    ppOVar1 = ppOVar1 + 9;
    p_Var2 = p_Var2 + 1;
    if (0x2f < iVar3) {
      return (_ObjectTracker *)0x0;
    }
  }
  return p_Var2;
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ FindStreamUnitFromLevel(struct Level *level /*$a0*/)
 // line 258, offset 0x80058bf0
	/* begin block 1 */
		// Start line: 260
		// Start offset: 0x80058BF0
		// Variables:
	// 		struct _StreamUnit *ret; // $a2
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x80058C38
	// End Line: 272

	/* begin block 2 */
		// Start line: 516
	/* end block 2 */
	// End Line: 517

	/* begin block 3 */
		// Start line: 520
	/* end block 3 */
	// End Line: 521

_StreamUnit * FindStreamUnitFromLevel(Level *level)

{
  STracker *pSVar1;
  int iVar2;
  
  iVar2 = 0;
  pSVar1 = &StreamTracker;
  while ((*(short *)pSVar1->StreamList != 2 || (*(Level **)pSVar1->StreamList != level))) {
    iVar2 = iVar2 + 1;
    pSVar1 = (STracker *)(pSVar1->StreamList + 1);
    if (0xf < iVar2) {
      return (_StreamUnit *)0x0;
    }
  }
  return (_StreamUnit *)pSVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_LoadObjectReturn(void *loadData /*$s0*/, void *data /*$s1*/, void *data2 /*$a2*/)
 // line 328, offset 0x80058c40
	/* begin block 1 */
		// Start line: 329
		// Start offset: 0x80058C40
		// Variables:
	// 		struct Object *object; // $s0
	// 		struct _ObjectTracker *objectTracker; // $s1

		/* begin block 1.1 */
			// Start line: 367
			// Start offset: 0x80058CCC
			// Variables:
		// 		char objDsfxFileName[64]; // stack offset -80
		/* end block 1.1 */
		// End offset: 0x80058D04
		// End Line: 379
	/* end block 1 */
	// End offset: 0x80058D1C
	// End Line: 390

	/* begin block 2 */
		// Start line: 664
	/* end block 2 */
	// End Line: 665

void STREAM_LoadObjectReturn(void *loadData,void *data,void *data2)

{
  undefined2 uVar1;
  long lVar2;
  int iVar3;
  char acStack80 [64];
  
  GetRCnt(0xf2000000);
  if ((((*(uint *)loadData & 0x8000000) != 0) && (*(int **)((int)loadData + 0x3c) != (int *)0x0)) &&
     (*(int *)((int)loadData + 0x40) != 0)) {
    RELMOD_InitModulePointers(*(int *)((int)loadData + 0x40),*(int **)((int)loadData + 0x3c));
  }
  STREAM_PackVRAMObject((_ObjectTracker *)data);
  OBTABLE_InitAnimPointers((_ObjectTracker *)data);
  OBTABLE_InitObjectWithID((Object *)loadData);
  if ((*(uint *)((int)loadData + 0x2c) & 0x800000) != 0) {
    sprintf(acStack80,"\\kain2\\sfx\\object\\%s\\%s.snf");
    *(undefined2 *)((int)loadData + 6) = 0;
    lVar2 = LOAD_DoesFileExist(acStack80);
    if (lVar2 != 0) {
      iVar3 = aadLoadDynamicSfx((char *)data,0,0);
      *(undefined2 *)((int)loadData + 6) = (short)iVar3;
    }
  }
  uVar1 = 4;
  if (*(int *)((int)data + 0x18) == 0) {
    uVar1 = 2;
  }
  *(undefined2 *)((int)data + 0x14) = uVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpMonster(struct _ObjectTracker *dumpee /*$s2*/)
 // line 392, offset 0x80058d30
	/* begin block 1 */
		// Start line: 393
		// Start offset: 0x80058D30
		// Variables:
	// 		struct Object *object; // $s1
	// 		struct _Instance *instance; // $a1

		/* begin block 1.1 */
			// Start line: 413
			// Start offset: 0x80058DAC
			// Variables:
		// 		struct _Instance *next; // $s0
		/* end block 1.1 */
		// End offset: 0x80058DC8
		// End Line: 420
	/* end block 1 */
	// End offset: 0x80058DD4
	// End Line: 423

	/* begin block 2 */
		// Start line: 792
	/* end block 2 */
	// End Line: 793

void STREAM_DumpMonster(_ObjectTracker *dumpee)

{
  _Instance *instance;
  _Instance *p_Var1;
  Object *object;
  
  object = dumpee->object;
  if ((_BlockVramEntry *)dumpee->vramBlock != (_BlockVramEntry *)0x0) {
    VRAM_ClearVramBlock((_BlockVramEntry *)dumpee->vramBlock);
  }
  OBTABLE_RemoveObjectEntry(object);
  if (((object->oflags2 & 0x800000U) != 0) && ((int)object->sfxFileHandle != 0)) {
    aadFreeDynamicSfx((int)object->sfxFileHandle);
  }
  p_Var1 = (gameTrackerX.instanceList)->first;
  while (instance = p_Var1, instance != (_Instance *)0x0) {
    p_Var1 = instance->next;
    if (object == instance->object) {
      INSTANCE_ReallyRemoveInstance(gameTrackerX.instanceList,instance,0);
    }
  }
  MEMPACK_Free((char *)object);
  dumpee->object = (Object *)0x0;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_InList(char *name /*$s1*/, char **nameList /*$a1*/)
 // line 432, offset 0x80058df8
	/* begin block 1 */
		// Start line: 433
		// Start offset: 0x80058DF8
		// Variables:
	// 		char **mon; // $s0
	/* end block 1 */
	// End offset: 0x80058E4C
	// End Line: 441

	/* begin block 2 */
		// Start line: 887
	/* end block 2 */
	// End Line: 888

int STREAM_InList(char *name,char **nameList)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = *nameList;
  while( true ) {
    if (pcVar1 == (char *)0x0) {
      return 0;
    }
    iVar2 = strcmpi(name,*nameList);
    nameList = nameList + 1;
    if (iVar2 == 0) break;
    pcVar1 = *nameList;
  }
  return 1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_IsSpecialMonster(char *name /*$a0*/)
 // line 443, offset 0x80058e60
	/* begin block 1 */
		// Start line: 444
		// Start offset: 0x80058E60
		// Variables:
	// 		static char (*mon[6]); // offset 0x0
	/* end block 1 */
	// End offset: 0x80058E60
	// End Line: 444

	/* begin block 2 */
		// Start line: 911
	/* end block 2 */
	// End Line: 912

int STREAM_IsSpecialMonster(char *name)

{
  int iVar1;
  
  iVar1 = STREAM_InList(name,&PTR_s_wallcr_800cc3f8);
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpSomeMonsters()
 // line 451, offset 0x80058e84
	/* begin block 1 */
		// Start line: 452
		// Start offset: 0x80058E84
		// Variables:
	// 		struct _ObjectTracker *otr; // $s1
	// 		int i; // $s2
	/* end block 1 */
	// End offset: 0x80058EF8
	// End Line: 467

	/* begin block 2 */
		// Start line: 931
	/* end block 2 */
	// End Line: 932

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_DumpSomeMonsters(void)

{
  int iVar1;
  Object **ppOVar2;
  _ObjectTracker *dumpee;
  int iVar3;
  
  iVar3 = 0;
  ppOVar2 = &(gameTrackerX.GlobalObjects)->object;
  dumpee = gameTrackerX.GlobalObjects;
  do {
    if (((*(short *)(ppOVar2 + 1) == 2) && (*ppOVar2 != (Object *)0x0)) &&
       (iVar1 = STREAM_IsSpecialMonster((char *)dumpee), iVar1 != 0)) {
      STREAM_DumpMonster(dumpee);
    }
    iVar3 = iVar3 + 1;
    ppOVar2 = ppOVar2 + 9;
    dumpee = dumpee + 1;
  } while (iVar3 < 0x30);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_NoMonsters()
 // line 468, offset 0x80058f14
	/* begin block 1 */
		// Start line: 984
	/* end block 1 */
	// End Line: 985

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_NoMonsters(void)

{
  gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x4000000;
  STREAM_DumpSomeMonsters();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_YesMonsters()
 // line 474, offset 0x80058f44
	/* begin block 1 */
		// Start line: 998
	/* end block 1 */
	// End Line: 999

	/* begin block 2 */
		// Start line: 1000
	/* end block 2 */
	// End Line: 1001

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_YesMonsters(void)

{
  gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xfbffffff;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_IsMonster(char *name /*$a0*/)
 // line 481, offset 0x80058f60
	/* begin block 1 */
		// Start line: 482
		// Start offset: 0x80058F60
		// Variables:
	// 		static char (*monnames[19]); // offset 0x18
	/* end block 1 */
	// End offset: 0x80058F60
	// End Line: 482

	/* begin block 2 */
		// Start line: 1012
	/* end block 2 */
	// End Line: 1013

int STREAM_IsMonster(char *name)

{
  int iVar1;
  
  iVar1 = STREAM_InList(name,&PTR_s_skinner_800cc410);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_TryAndDumpANonResidentObject()
 // line 524, offset 0x80058f84
	/* begin block 1 */
		// Start line: 525
		// Start offset: 0x80058F84
		// Variables:
	// 		struct _ObjectTracker *otr; // $s1
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x80058FC0
	// End Line: 538

	/* begin block 2 */
		// Start line: 1048
	/* end block 2 */
	// End Line: 1049

/* WARNING: Unknown calling convention yet parameter storage is locked */

int STREAM_TryAndDumpANonResidentObject(void)

{
  int iVar1;
  int iVar2;
  _ObjectTracker *otr;
  
  iVar2 = 0;
  otr = gameTrackerX.GlobalObjects;
  do {
    iVar1 = STREAM_TryAndDumpNonResident(otr);
    if (iVar1 != 0) {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
    otr = otr + 1;
  } while (iVar2 < 0x30);
  return -1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ InsertGlobalObject(char *name /*$s2*/, struct GameTracker *gameTracker /*$s3*/)
 // line 540, offset 0x80058fd4
	/* begin block 1 */
		// Start line: 541
		// Start offset: 0x80058FD4
		// Variables:
	// 		char string[64]; // stack offset -152
	// 		char vramname[64]; // stack offset -88
	// 		int i; // $s1
	// 		struct _ObjectTracker *otr; // $s0
	/* end block 1 */
	// End offset: 0x80059150
	// End Line: 632

	/* begin block 2 */
		// Start line: 1108
	/* end block 2 */
	// End Line: 1109

int InsertGlobalObject(char *name,GameTracker *gameTracker)

{
  int iVar1;
  int iVar2;
  _ObjectTracker *retData;
  char acStack152 [64];
  char acStack88 [64];
  
  if (((gameTrackerX.gameFlags & 0x4000000U) != 0) &&
     (iVar1 = STREAM_IsSpecialMonster(name), iVar1 != 0)) {
    return -1;
  }
  if (((gameTracker->debugFlags2 & 0x8000U) != 0) && (iVar1 = STREAM_IsMonster(name), iVar1 != 0)) {
    return -1;
  }
  retData = gameTracker->GlobalObjects;
  iVar1 = 0;
  do {
    if ((retData->objectStatus != 0) && (iVar2 = strcmpi((char *)retData,name), iVar2 == 0)) break;
    iVar1 = iVar1 + 1;
    retData = retData + 1;
  } while (iVar1 < 0x30);
  if (iVar1 == 0x30) {
    retData = gameTracker->GlobalObjects;
    iVar1 = 0;
    do {
      if (retData->objectStatus == 0) break;
      iVar1 = iVar1 + 1;
      retData = retData + 1;
    } while (iVar1 < 0x30);
    if ((iVar1 == 0x30) && (iVar1 = STREAM_TryAndDumpANonResidentObject(), iVar1 == -1)) {
      DEBUG_FatalError("The Object tracker is full MAX_OBJECTS=%d.\n");
    }
    sprintf(acStack152,"\\kain2\\object\\%s\\%s.drm");
    sprintf(acStack88,"\\kain2\\object\\%s\\%s.crm");
    strcpy((char *)retData,name);
    retData->objectStatus = 1;
    LOAD_NonBlockingBinaryLoad
              (acStack152,STREAM_LoadObjectReturn,retData,(void *)0x0,&retData->object,1);
    retData->numInUse = 0;
    retData->numObjectsUsing = '\0';
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// struct _ObjectTracker * /*$ra*/ STREAM_GetObjectTracker(char *name /*$a0*/)
 // line 643, offset 0x80059170
	/* begin block 1 */
		// Start line: 644
		// Start offset: 0x80059170
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x800591AC
	// End Line: 649

	/* begin block 2 */
		// Start line: 1286
	/* end block 2 */
	// End Line: 1287

_ObjectTracker * STREAM_GetObjectTracker(char *name)

{
  int iVar1;
  _ObjectTracker *p_Var2;
  
  iVar1 = InsertGlobalObject(name,&gameTrackerX);
  if (iVar1 == -1) {
    p_Var2 = (_ObjectTracker *)0x0;
  }
  else {
    p_Var2 = gameTrackerX.GlobalObjects + iVar1;
  }
  return p_Var2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LoadLevelObjects(struct _StreamUnit *stream /*$s1*/)
 // line 651, offset 0x800591bc
	/* begin block 1 */
		// Start line: 652
		// Start offset: 0x800591BC
		// Variables:
	// 		int objlist_pos; // $s0

		/* begin block 1.1 */
			// Start line: 662
			// Start offset: 0x80059200
			// Variables:
		// 		char name[20]; // stack offset -48
		/* end block 1.1 */
		// End offset: 0x80059200
		// End Line: 664

		/* begin block 1.2 */
			// Start line: 667
			// Start offset: 0x80059240
			// Variables:
		// 		struct Level *level; // $s1
		// 		int i; // $s2
		/* end block 1.2 */
		// End offset: 0x800592C4
		// End Line: 688
	/* end block 1 */
	// End offset: 0x800592C4
	// End Line: 689

	/* begin block 2 */
		// Start line: 1339
	/* end block 2 */
	// End Line: 1340

void LoadLevelObjects(_StreamUnit *stream)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  Level *pLVar4;
  int iVar5;
  int iVar6;
  char acStack48 [24];
  
  STREAM_NextLoadAsNormal();
  pLVar4 = stream->level;
  cVar1 = *(char *)pLVar4->objectNameList;
  iVar5 = 0;
  while (cVar1 != -1) {
    strcpy(acStack48,(char *)((int)pLVar4->objectNameList + iVar5));
    InsertGlobalObject(acStack48,&gameTrackerX);
    pLVar4 = stream->level;
    iVar5 = iVar5 + 0x10;
    cVar1 = *(char *)((int)pLVar4->objectNameList + iVar5);
  }
  pLVar4 = stream->level;
  iVar5 = 0;
  if (0 < pLVar4->numIntros) {
    iVar6 = 0;
    do {
      iVar2 = FindObjectName(pLVar4->introList->name + iVar6);
      if (iVar2 == -1) {
        pcVar3 = pLVar4->introList->name + iVar6;
        *(uint *)(pcVar3 + 0x2c) = *(uint *)(pcVar3 + 0x2c) | 0x4000;
      }
      else {
        pcVar3 = pLVar4->introList->name + iVar6;
        *(uint *)(pcVar3 + 0x2c) = *(uint *)(pcVar3 + 0x2c) & 0xffffbfff;
      }
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 0x4c;
    } while (iVar5 < pLVar4->numIntros);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ STREAM_IsAnInstanceUsingObject(struct Object *object /*$a0*/)
 // line 691, offset 0x800592e0
	/* begin block 1 */
		// Start line: 693
		// Start offset: 0x800592E0
		// Variables:
	// 		struct _Instance *instance; // $v1
	// 		struct _Instance *next; // $v1
	// 		long ret; // $a1
	/* end block 1 */
	// End offset: 0x80059318
	// End Line: 709

	/* begin block 2 */
		// Start line: 1430
	/* end block 2 */
	// End Line: 1431

	/* begin block 3 */
		// Start line: 1431
	/* end block 3 */
	// End Line: 1432

long STREAM_IsAnInstanceUsingObject(Object *object)

{
  Object **ppOVar1;
  _Instance *p_Var2;
  
  p_Var2 = (gameTrackerX.instanceList)->first;
  do {
    if (p_Var2 == (_Instance *)0x0) {
      return 0;
    }
    ppOVar1 = &p_Var2->object;
    p_Var2 = p_Var2->next;
  } while (*ppOVar1 != object);
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_StreamLoadObjectAbort(void *loadData /*$a0*/, void *data /*$a1*/, void *data2 /*$a2*/)
 // line 712, offset 0x80059320
	/* begin block 1 */
		// Start line: 713
		// Start offset: 0x80059320
		// Variables:
	// 		struct _ObjectTracker *objectTracker; // $s0
	/* end block 1 */
	// End offset: 0x8005933C
	// End Line: 717

	/* begin block 2 */
		// Start line: 1474
	/* end block 2 */
	// End Line: 1475

void STREAM_StreamLoadObjectAbort(void *loadData,void *data,void *data2)

{
  if (loadData != (void *)0x0) {
    MEMPACK_Free((char *)loadData);
  }
  *(undefined2 *)((int)data + 0x14) = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpLoadingObjects()
 // line 720, offset 0x80059350
	/* begin block 1 */
		// Start line: 721
		// Start offset: 0x80059350
		// Variables:
	// 		int i; // $s1
	// 		struct _ObjectTracker *tracker; // $s0
	/* end block 1 */
	// End offset: 0x80059398
	// End Line: 730

	/* begin block 2 */
		// Start line: 1491
	/* end block 2 */
	// End Line: 1492

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_DumpLoadingObjects(void)

{
  _ObjectTracker *objectTracker;
  int iVar1;
  
  iVar1 = 0;
  objectTracker = gameTrackerX.GlobalObjects;
  do {
    if (objectTracker->objectStatus == 1) {
      STREAM_DumpObject(objectTracker);
    }
    iVar1 = iVar1 + 1;
    objectTracker = objectTracker + 1;
  } while (iVar1 < 0x30);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpObject(struct _ObjectTracker *objectTracker /*$s1*/)
 // line 735, offset 0x800593b0
	/* begin block 1 */
		// Start line: 736
		// Start offset: 0x800593B0
		// Variables:
	// 		struct Object *object; // $s0

		/* begin block 1.1 */
			// Start line: 742
			// Start offset: 0x800593D8
			// Variables:
		// 		char dramName[64]; // stack offset -80
		/* end block 1.1 */
		// End offset: 0x80059404
		// End Line: 746
	/* end block 1 */
	// End offset: 0x80059484
	// End Line: 779

	/* begin block 2 */
		// Start line: 1536
	/* end block 2 */
	// End Line: 1537

void STREAM_DumpObject(_ObjectTracker *objectTracker)

{
  Object *object;
  char acStack80 [64];
  
  object = objectTracker->object;
  if (objectTracker->objectStatus == 1) {
    sprintf(acStack80,"\\kain2\\object\\%s\\%s.drm");
    LOAD_AbortFileLoad(acStack80,STREAM_StreamLoadObjectAbort);
  }
  else {
    if (object != (Object *)0x0) {
      if ((object->oflags & 0x2000000U) == 0) {
        if ((_BlockVramEntry *)objectTracker->vramBlock != (_BlockVramEntry *)0x0) {
          VRAM_ClearVramBlock((_BlockVramEntry *)objectTracker->vramBlock);
        }
        if (((object->oflags2 & 0x800000U) != 0) && ((int)object->sfxFileHandle != 0)) {
          aadFreeDynamicSfx((int)object->sfxFileHandle);
        }
        OBTABLE_RemoveObjectEntry(object);
        MEMPACK_Free((char *)object);
        objectTracker->objectStatus = 0;
      }
      if (object != (Object *)0x0) {
        return;
      }
    }
    objectTracker->objectStatus = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_IsObjectInAnyUnit(struct _ObjectTracker *tracker /*$s3*/)
 // line 782, offset 0x80059498
	/* begin block 1 */
		// Start line: 783
		// Start offset: 0x80059498
		// Variables:
	// 		int d; // $s1

		/* begin block 1.1 */
			// Start line: 790
			// Start offset: 0x800594E4
			// Variables:
		// 		unsigned char *objlist; // $s0
		/* end block 1.1 */
		// End offset: 0x80059528
		// End Line: 800
	/* end block 1 */
	// End offset: 0x8005953C
	// End Line: 803

	/* begin block 2 */
		// Start line: 1637
	/* end block 2 */
	// End Line: 1638

int STREAM_IsObjectInAnyUnit(_ObjectTracker *tracker)

{
  char cVar1;
  int iVar2;
  char *s2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    if ((*(short *)((int)&StreamTracker.StreamList[0].used + iVar2) == 2) &&
       (iVar2 = *(int *)((int)&StreamTracker.StreamList[0].level + iVar2), iVar2 != 0)) {
      s2 = *(char **)(iVar2 + 0x8c);
      cVar1 = *s2;
      while (cVar1 != -1) {
        iVar2 = strcmpi((char *)tracker,s2);
        s2 = s2 + 0x10;
        if (iVar2 == 0) {
          return 1;
        }
        cVar1 = *s2;
      }
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar3 * 0x40;
  } while (iVar3 < 0x10);
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_RemoveAllObjectsNotInUse()
 // line 805, offset 0x80059558
	/* begin block 1 */
		// Start line: 806
		// Start offset: 0x80059558
		// Variables:
	// 		int i; // $s3
	// 		int abort; // $a3
	// 		struct _ObjectTracker *tracker; // $s1
	// 		struct _ObjectTracker *trackerList; // $s4

		/* begin block 1.1 */
			// Start line: 815
			// Start offset: 0x800595A4
			// Variables:
		// 		struct Object *object; // $s2
		/* end block 1.1 */
		// End offset: 0x800595E4
		// End Line: 830

		/* begin block 1.2 */
			// Start line: 838
			// Start offset: 0x80059620
			// Variables:
		// 		int j; // $a0
		/* end block 1.2 */
		// End offset: 0x8005967C
		// End Line: 851

		/* begin block 1.3 */
			// Start line: 859
			// Start offset: 0x800596B4
			// Variables:
		// 		int j; // $t0
		// 		struct _ObjectTracker *otr; // $a3

			/* begin block 1.3.1 */
				// Start line: 863
				// Start offset: 0x800596E0
				// Variables:
			// 		int k; // $a0

				/* begin block 1.3.1.1 */
					// Start line: 872
					// Start offset: 0x80059704
					// Variables:
				// 		int l; // $a1
				/* end block 1.3.1.1 */
				// End offset: 0x80059750
				// End Line: 879
			/* end block 1.3.1 */
			// End offset: 0x80059768
			// End Line: 881
		/* end block 1.3 */
		// End offset: 0x80059784
		// End Line: 884
	/* end block 1 */
	// End offset: 0x800597F0
	// End Line: 902

	/* begin block 2 */
		// Start line: 1700
	/* end block 2 */
	// End Line: 1701

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_RemoveAllObjectsNotInUse(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  _ObjectTracker *p_Var5;
  _ObjectTracker *p_Var6;
  int iVar7;
  int iVar8;
  short *psVar9;
  char *pcVar10;
  _ObjectTracker *tracker;
  _ObjectTracker *tracker_00;
  Object *object;
  int iVar11;
  
  tracker_00 = gameTrackerX.GlobalObjects;
  iVar11 = 0;
  psVar9 = &(gameTrackerX.GlobalObjects)->objectStatus;
  tracker = gameTrackerX.GlobalObjects;
  do {
    if ((((*psVar9 == 2) && (object = *(Object **)(psVar9 + -2), (object->oflags & 0x2000000U) == 0)
         ) && (iVar3 = STREAM_IsObjectInAnyUnit(tracker), iVar3 == 0)) &&
       (lVar4 = STREAM_IsAnInstanceUsingObject(object), lVar4 == 0)) {
      *psVar9 = 3;
    }
    iVar11 = iVar11 + 1;
    psVar9 = psVar9 + 0x12;
    tracker = tracker + 1;
  } while (iVar11 < 0x30);
  do {
    bVar2 = true;
    iVar11 = 0;
    psVar9 = &tracker_00->objectStatus;
    tracker = tracker_00;
    do {
      if (*psVar9 == 3) {
        iVar3 = 0;
        p_Var5 = tracker;
        if (0 < (int)*(char *)(psVar9 + 4)) {
          do {
            if (tracker_00[p_Var5->objectsUsing[0]].objectStatus != 3) {
              *psVar9 = 2;
              bVar2 = false;
              break;
            }
            iVar3 = iVar3 + 1;
            p_Var5 = (_ObjectTracker *)(tracker->name + iVar3);
          } while (iVar3 < (int)*(char *)(psVar9 + 4));
        }
      }
      iVar11 = iVar11 + 1;
      psVar9 = psVar9 + 0x12;
      tracker = tracker + 1;
    } while (iVar11 < 0x30);
  } while (!bVar2);
  iVar11 = 0;
  tracker = tracker_00;
  do {
    if (tracker->objectStatus == 3) {
      iVar3 = 0;
      pcVar10 = &tracker_00->numObjectsUsing;
      p_Var5 = tracker_00;
      do {
        if (((uint)*(ushort *)(pcVar10 + -8) - 1 < 2) || (*(ushort *)(pcVar10 + -8) == 4)) {
          cVar1 = *pcVar10;
          iVar7 = 0;
          p_Var6 = p_Var5;
          if ('\0' < *pcVar10) {
            do {
              if ((int)p_Var6->objectsUsing[0] == iVar11) {
                *pcVar10 = cVar1 + -1;
                if (iVar7 < (char)(cVar1 + -1)) {
                  do {
                    iVar8 = iVar7 + 1;
                    p_Var5->objectsUsing[iVar7] = p_Var5->objectsUsing[iVar7 + 1];
                    iVar7 = iVar8;
                  } while (iVar8 < *pcVar10);
                }
                break;
              }
              iVar7 = iVar7 + 1;
              cVar1 = *pcVar10;
              p_Var6 = (_ObjectTracker *)(p_Var5->name + iVar7);
            } while (iVar7 < *pcVar10);
          }
        }
        iVar3 = iVar3 + 1;
        pcVar10 = pcVar10 + 0x24;
        p_Var5 = p_Var5 + 1;
      } while (iVar3 < 0x30);
      STREAM_DumpObject(tracker);
    }
    iVar11 = iVar11 + 1;
    tracker = tracker + 1;
    if (0x2f < iVar11) {
      iVar11 = 0;
      pcVar10 = &tracker_00->numObjectsUsing;
      do {
        if (((*(short *)(pcVar10 + -8) == 1) &&
            (iVar3 = STREAM_IsObjectInAnyUnit(tracker_00), iVar3 == 0)) && (*pcVar10 == '\0')) {
          STREAM_DumpObject(tracker_00);
        }
        iVar11 = iVar11 + 1;
        pcVar10 = pcVar10 + 0x24;
        tracker_00 = tracker_00 + 1;
      } while (iVar11 < 0x30);
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ RemoveAllObjects(struct GameTracker *gameTracker /*$a0*/)
 // line 905, offset 0x80059818
	/* begin block 1 */
		// Start line: 906
		// Start offset: 0x80059818
		// Variables:
	// 		int i; // $s1
	// 		struct _ObjectTracker *tracker; // $s0
	/* end block 1 */
	// End offset: 0x8005985C
	// End Line: 916

	/* begin block 2 */
		// Start line: 2030
	/* end block 2 */
	// End Line: 2031

void RemoveAllObjects(GameTracker *gameTracker)

{
  _ObjectTracker *objectTracker;
  int iVar1;
  
  iVar1 = 0;
  objectTracker = gameTracker->GlobalObjects;
  do {
    if (objectTracker->objectStatus != 0) {
      STREAM_DumpObject(objectTracker);
    }
    iVar1 = iVar1 + 1;
    objectTracker = objectTracker + 1;
  } while (iVar1 < 0x30);
  return;
}



// decompiled code
// original method signature: 
// struct Level * /*$ra*/ STREAM_GetLevelWithID(long id /*$a0*/)
 // line 921, offset 0x80059870
	/* begin block 1 */
		// Start line: 923
		// Start offset: 0x80059870
		// Variables:
	// 		struct Level *retLevel; // $a2
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x800598BC
	// End Line: 937

	/* begin block 2 */
		// Start line: 2070
	/* end block 2 */
	// End Line: 2071

	/* begin block 3 */
		// Start line: 2071
	/* end block 3 */
	// End Line: 2072

Level * STREAM_GetLevelWithID(long id)

{
  STracker *pSVar1;
  int iVar2;
  
  iVar2 = 0;
  pSVar1 = &StreamTracker;
  while ((pSVar1->StreamList[0].used != 2 || (pSVar1->StreamList[0].StreamUnitID != id))) {
    iVar2 = iVar2 + 1;
    pSVar1 = (STracker *)(pSVar1->StreamList + 1);
    if (0xf < iVar2) {
      return (Level *)0x0;
    }
  }
  return pSVar1->StreamList[0].level;
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ STREAM_GetStreamUnitWithID(long id /*$a0*/)
 // line 940, offset 0x800598c8
	/* begin block 1 */
		// Start line: 942
		// Start offset: 0x800598C8
		// Variables:
	// 		struct _StreamUnit *retUnit; // $a2
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x80059910
	// End Line: 954

	/* begin block 2 */
		// Start line: 2115
	/* end block 2 */
	// End Line: 2116

	/* begin block 3 */
		// Start line: 2116
	/* end block 3 */
	// End Line: 2117

_StreamUnit * STREAM_GetStreamUnitWithID(long id)

{
  STracker *pSVar1;
  int iVar2;
  
  iVar2 = 0;
  pSVar1 = &StreamTracker;
  while ((*(short *)pSVar1->StreamList != 2 || (pSVar1->StreamList[0].StreamUnitID != id))) {
    iVar2 = iVar2 + 1;
    pSVar1 = (STracker *)(pSVar1->StreamList + 1);
    if (0xf < iVar2) {
      return (_StreamUnit *)0x0;
    }
  }
  return (_StreamUnit *)pSVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_CalculateWaterLevel(struct Level *level /*$t3*/)
 // line 957, offset 0x80059918
	/* begin block 1 */
		// Start line: 958
		// Start offset: 0x80059918
		// Variables:
	// 		struct _Terrain *terrain; // $t2
	// 		int i; // $t0
	// 		struct _TFace *tface; // $a3
	// 		long waterZLevel; // $t1
	/* end block 1 */
	// End offset: 0x80059A40
	// End Line: 1011

	/* begin block 2 */
		// Start line: 2155
	/* end block 2 */
	// End Line: 2156

void STREAM_CalculateWaterLevel(Level *level)

{
  int iVar1;
  _TVertex *p_Var2;
  ushort *puVar3;
  _TFace *p_Var4;
  int iVar5;
  int iVar6;
  int iVar7;
  _Terrain *p_Var8;
  
  if (level->waterZLevel == 0) {
    if ((level->unitFlags & 1U) != 0) {
      level->waterZLevel = 0x7fff;
      return;
    }
    p_Var8 = level->terrain;
    iVar5 = p_Var8->numFaces;
    p_Var4 = p_Var8->faceList;
    iVar7 = -0x7fff;
    if (0 < iVar5) {
      puVar3 = &(p_Var4->face).v2;
      iVar6 = -0x7fff;
      do {
        iVar7 = iVar6;
        if ((*(byte *)(puVar3 + 1) & 8) != 0) {
          p_Var2 = p_Var8->vertexList;
          iVar1 = (int)p_Var2[(p_Var4->face).v0].vertex.z;
          if ((((iVar1 == (int)p_Var2[puVar3[-1]].vertex.z) &&
               (iVar1 == (int)p_Var2[*puVar3].vertex.z)) && (iVar7 = iVar1, iVar6 != -0x7fff)) &&
             (iVar7 = iVar6, iVar6 != iVar1)) break;
        }
        iVar5 = iVar5 + -1;
        puVar3 = puVar3 + 6;
        p_Var4 = p_Var4 + 1;
        iVar6 = iVar7;
      } while (0 < iVar5);
    }
    if (iVar7 == -0x7fff) {
      level->waterZLevel = -0x7fff;
      return;
    }
    level->waterZLevel = iVar7 + (level->terrain->BSPTreeArray->globalOffset).z;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_IsMorphInProgress()
 // line 1016, offset 0x80059a48
	/* begin block 1 */
		// Start line: 2289
	/* end block 1 */
	// End Line: 2290

	/* begin block 2 */
		// Start line: 2290
	/* end block 2 */
	// End Line: 2291

/* WARNING: Unknown calling convention yet parameter storage is locked */

int STREAM_IsMorphInProgress(void)

{
  return (uint)(gameTrackerX.gameData.asmData.MorphTime != 1000);
}



// decompiled code
// original method signature: 
// long /*$ra*/ STREAM_GetWaterZLevel(struct Level *level /*$a0*/, struct _Instance *instance /*$a1*/)
 // line 1022, offset 0x80059a5c
	/* begin block 1 */
		// Start line: 1024
		// Start offset: 0x80059A5C
		// Variables:
	// 		long waterZLevel; // $a1
	/* end block 1 */
	// End offset: 0x80059AD4
	// End Line: 1049

	/* begin block 2 */
		// Start line: 2301
	/* end block 2 */
	// End Line: 2302

	/* begin block 3 */
		// Start line: 2302
	/* end block 3 */
	// End Line: 2303

	/* begin block 4 */
		// Start line: 2304
	/* end block 4 */
	// End Line: 2305

long STREAM_GetWaterZLevel(Level *level,_Instance *instance)

{
  if ((instance->flags2 & 0x8000000U) == 0) {
    if (((instance->object->oflags2 & 0x2000000U) == 0) &&
       (gameTrackerX.gameData.asmData.MorphTime != 1000)) {
      return -0x7fff;
    }
  }
  else {
    if ((instance->object->oflags2 & 0x2000000U) != 0) {
      return -0x7fff;
    }
    if (gameTrackerX.gameData.asmData.MorphTime == 1000) {
      return -0x7fff;
    }
  }
  return level->waterZLevel;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_SetMainFog(struct _StreamUnit *streamUnit /*$a0*/)
 // line 1052, offset 0x80059adc
	/* begin block 1 */
		// Start line: 1054
		// Start offset: 0x80059ADC
		// Variables:
	// 		struct Level *level; // $v1
	/* end block 1 */
	// End offset: 0x80059B1C
	// End Line: 1069

	/* begin block 2 */
		// Start line: 2361
	/* end block 2 */
	// End Line: 2362

	/* begin block 3 */
		// Start line: 2362
	/* end block 3 */
	// End Line: 2363

	/* begin block 4 */
		// Start line: 2366
	/* end block 4 */
	// End Line: 2367

void STREAM_SetMainFog(_StreamUnit *streamUnit)

{
  Level *pLVar1;
  
  pLVar1 = streamUnit->level;
  if (gameTrackerX.gameData.asmData.MorphType == 0) {
    streamUnit->UnitFogNear = pLVar1->holdFogNear;
    streamUnit->UnitFogFar = pLVar1->holdFogFar;
  }
  else {
    streamUnit->UnitFogNear = pLVar1->spectralFogNear;
    streamUnit->UnitFogFar = pLVar1->spectralFogFar;
  }
  streamUnit->TargetFogNear = streamUnit->UnitFogNear;
  streamUnit->TargetFogFar = streamUnit->UnitFogFar;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_SetStreamFog(struct _StreamUnit *streamUnit /*$s1*/, short fogNear /*$a1*/, short fogFar /*$a2*/)
 // line 1073, offset 0x80059b30
	/* begin block 1 */
		// Start line: 1074
		// Start offset: 0x80059B30
	/* end block 1 */
	// End offset: 0x80059BA0
	// End Line: 1086

	/* begin block 2 */
		// Start line: 2406
	/* end block 2 */
	// End Line: 2407

void STREAM_SetStreamFog(_StreamUnit *streamUnit,short fogNear,short fogFar)

{
  _StreamUnit *p_Var1;
  short sVar2;
  short sVar3;
  
  p_Var1 = FindStreamUnitFromLevel(gameTrackerX.level);
  sVar3 = p_Var1->UnitFogFar;
  if (fogFar < p_Var1->UnitFogFar) {
    sVar3 = fogFar;
  }
  streamUnit->TargetFogFar = sVar3;
  streamUnit->UnitFogFar = sVar3;
  sVar2 = (short)((int)sVar3 + -2000);
  if ((int)fogNear < (int)sVar3 + -2000) {
    sVar2 = fogNear;
  }
  streamUnit->TargetFogNear = sVar2;
  streamUnit->UnitFogNear = sVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_ConnectStream(struct _StreamUnit *streamUnit /*$s6*/)
 // line 1130, offset 0x80059bc0
	/* begin block 1 */
		// Start line: 1131
		// Start offset: 0x80059BC0
		// Variables:
	// 		struct _StreamUnit *mainUnit; // stack offset -48
	// 		struct StreamUnitPortal *streamPortal; // $a0
	// 		int numportals; // $v1
	// 		struct StreamUnitPortal *streamPortal2; // $s4
	// 		int numportals2; // $fp
	// 		int i; // $s0
	// 		int j; // $s3
	// 		char text[16]; // stack offset -72
	// 		char *commapos; // $v0
	// 		int signalID; // $s2

		/* begin block 1.1 */
			// Start line: 1155
			// Start offset: 0x80059C3C
			// Variables:
		// 		struct _StreamUnit *connectStream; // $s0

			/* begin block 1.1.1 */
				// Start line: 1189
				// Start offset: 0x80059D54
				// Variables:
			// 		struct _SVector offset; // stack offset -56
			/* end block 1.1.1 */
			// End offset: 0x80059D54
			// End Line: 1200
		/* end block 1.1 */
		// End offset: 0x80059D60
		// End Line: 1209

		/* begin block 1.2 */
			// Start line: 1214
			// Start offset: 0x80059D74
			// Variables:
		// 		long d; // stack offset -44
		// 		struct _StreamUnit *connectStream; // $s5

			/* begin block 1.2.1 */
				// Start line: 1229
				// Start offset: 0x80059DC4
				// Variables:
			// 		long hookedUp; // $s0

				/* begin block 1.2.1.1 */
					// Start line: 1269
					// Start offset: 0x80059EE4
					// Variables:
				// 		struct _SVector offset; // stack offset -56
				/* end block 1.2.1.1 */
				// End offset: 0x80059EE4
				// End Line: 1280
			/* end block 1.2.1 */
			// End offset: 0x80059EF0
			// End Line: 1289
		/* end block 1.2 */
		// End offset: 0x80059F20
		// End Line: 1289
	/* end block 1 */
	// End offset: 0x80059F9C
	// End Line: 1303

	/* begin block 2 */
		// Start line: 2530
	/* end block 2 */
	// End Line: 2531

void STREAM_ConnectStream(_StreamUnit *streamUnit)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  long lVar4;
  Level *pLVar5;
  int *piVar6;
  int iVar7;
  STracker **ppSVar8;
  _StreamUnit **pp_Var9;
  int iVar10;
  int iVar11;
  int *__src;
  STracker *pSVar12;
  Level **ppLVar13;
  int iVar14;
  char acStack72 [16];
  _SVector local_38;
  STracker *local_30;
  int local_2c;
  
  WARPGATE_UpdateAddToArray(streamUnit);
  if (gameTrackerX.StreamUnitID != streamUnit->StreamUnitID) {
    iVar11 = 0;
    local_30 = (STracker *)STREAM_GetStreamUnitWithID(gameTrackerX.StreamUnitID);
    piVar6 = (int *)streamUnit->level->terrain->StreamUnits;
    iVar14 = *piVar6;
    __src = piVar6 + 1;
    if (0 < iVar14) {
      ppSVar8 = (STracker **)(piVar6 + 0xb);
      do {
        strcpy(acStack72,(char *)__src);
        pcVar2 = strchr(acStack72,0x2c);
        iVar10 = 0;
        if (pcVar2 != (char *)0x0) {
          *pcVar2 = '\0';
          iVar10 = atoi(pcVar2 + 1);
        }
        pSVar12 = (STracker *)STREAM_GetStreamUnitWithID((long)ppSVar8[-5]);
        iVar3 = strcmpi(acStack72,"warpgate");
        if ((iVar3 == 0) && (lVar4 = WARPGATE_IsUnitWarpRoom((_StreamUnit *)local_30), lVar4 != 0))
        {
          pSVar12 = local_30;
        }
        *ppSVar8 = pSVar12;
        if ((pSVar12 != (STracker *)0x0) && (pSVar12 == local_30)) {
          piVar6 = (int *)(*(Level **)local_30->StreamList)->terrain->StreamUnits;
          iVar7 = 0;
          iVar3 = *piVar6;
          piVar6 = piVar6 + 1;
          if (0 < iVar3) {
            do {
              iVar7 = iVar7 + 1;
              if (iVar10 == piVar6[4]) {
                local_38.x = *(short *)(piVar6 + 6) - *(short *)(ppSVar8 + -4);
                local_38.y = *(short *)((int)piVar6 + 0x1a) - *(short *)((int)ppSVar8 + -0xe);
                local_38.z = *(short *)(piVar6 + 7) - *(short *)(ppSVar8 + -3);
                RelocateLevel(streamUnit->level,&local_38);
                break;
              }
              piVar6 = piVar6 + 0x17;
            } while (iVar7 < iVar3);
          }
        }
        iVar11 = iVar11 + 1;
        ppSVar8 = ppSVar8 + 0x17;
        __src = __src + 0x17;
      } while (iVar11 < iVar14);
    }
    pSVar12 = &StreamTracker;
    local_2c = 0;
    ppLVar13 = &StreamTracker.StreamList[0].level;
    do {
      if ((*(short *)(ppLVar13 + -1) == 2) && (pSVar12 != (STracker *)streamUnit)) {
        piVar6 = (int *)(*ppLVar13)->terrain->StreamUnits;
        iVar11 = 0;
        iVar14 = *piVar6;
        __src = piVar6 + 1;
        if (0 < iVar14) {
          pp_Var9 = (_StreamUnit **)(piVar6 + 0xb);
          do {
            bVar1 = false;
            strcpy(acStack72,(char *)__src);
            pcVar2 = strchr(acStack72,0x2c);
            iVar10 = 0;
            if (pcVar2 != (char *)0x0) {
              *pcVar2 = '\0';
              iVar10 = atoi(pcVar2 + 1);
            }
            if (pp_Var9[-5] == (_StreamUnit *)streamUnit->StreamUnitID) {
              *pp_Var9 = streamUnit;
LAB_80059e8c:
              bVar1 = true;
            }
            else {
              iVar3 = strcmpi(acStack72,"warpgate");
              if ((iVar3 == 0) && (lVar4 = WARPGATE_IsUnitWarpRoom(streamUnit), lVar4 != 0)) {
                *pp_Var9 = streamUnit;
                goto LAB_80059e8c;
              }
            }
            if ((bVar1) && (pSVar12 == local_30)) {
              piVar6 = (int *)streamUnit->level->terrain->StreamUnits;
              iVar7 = 0;
              iVar3 = *piVar6;
              piVar6 = piVar6 + 1;
              if (0 < iVar3) {
                do {
                  iVar7 = iVar7 + 1;
                  if (iVar10 == piVar6[4]) {
                    local_38.x = *(short *)(pp_Var9 + -4) - *(short *)(piVar6 + 6);
                    local_38.y = *(short *)((int)pp_Var9 + -0xe) - *(short *)((int)piVar6 + 0x1a);
                    local_38.z = *(short *)(pp_Var9 + -3) - *(short *)(piVar6 + 7);
                    RelocateLevel(streamUnit->level,&local_38);
                    break;
                  }
                  piVar6 = piVar6 + 0x17;
                } while (iVar7 < iVar3);
              }
            }
            iVar11 = iVar11 + 1;
            pp_Var9 = pp_Var9 + 0x17;
            __src = __src + 0x17;
          } while (iVar11 < iVar14);
        }
      }
      ppLVar13 = ppLVar13 + 0x10;
      pSVar12 = (STracker *)(pSVar12->StreamList + 1);
      local_2c = local_2c + 1;
    } while (local_2c < 0x10);
    pLVar5 = streamUnit->level;
    iVar11 = 0;
    if (0 < pLVar5->numIntros) {
      iVar14 = 0;
      do {
        iVar10 = strcmpi(pLVar5->introList->name + iVar14,"raziel");
        iVar11 = iVar11 + 1;
        if (iVar10 == 0) {
          pcVar2 = streamUnit->level->introList->name + iVar14;
          *(uint *)(pcVar2 + 0x2c) = *(uint *)(pcVar2 + 0x2c) | 8;
          return;
        }
        pLVar5 = streamUnit->level;
        iVar14 = iVar14 + 0x4c;
      } while (iVar11 < pLVar5->numIntros);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_StreamLoadLevelAbort(void *loadData /*$a0*/, void *data /*$a1*/, void *data2 /*$a2*/)
 // line 1305, offset 0x80059fcc
	/* begin block 1 */
		// Start line: 1306
		// Start offset: 0x80059FCC
		// Variables:
	// 		struct _StreamUnit *streamUnit; // $s0
	/* end block 1 */
	// End offset: 0x80059FE8
	// End Line: 1310

	/* begin block 2 */
		// Start line: 3117
	/* end block 2 */
	// End Line: 3118

void STREAM_StreamLoadLevelAbort(void *loadData,void *data,void *data2)

{
  if (loadData != (void *)0x0) {
    MEMPACK_Free((char *)loadData);
  }
  *(undefined4 *)((int)data2 + 8) = 0;
  *(undefined2 *)((int)data2 + 4) = 0;
  *(undefined2 *)((int)data2 + 6) = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DoObjectLoadAndDump(struct _StreamUnit *streamUnit /*$a0*/)
 // line 1318, offset 0x8005a004
	/* begin block 1 */
		// Start line: 1319
		// Start offset: 0x8005A004
		// Variables:
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x8005A03C
	// End Line: 1336

	/* begin block 2 */
		// Start line: 3144
	/* end block 2 */
	// End Line: 3145

void STREAM_DoObjectLoadAndDump(_StreamUnit *streamUnit)

{
  STracker *pSVar1;
  int iVar2;
  
  iVar2 = 0;
  pSVar1 = &StreamTracker;
  do {
    iVar2 = iVar2 + 1;
    if (pSVar1->StreamList[0].used == 1) {
      return;
    }
    pSVar1 = (STracker *)(pSVar1->StreamList + 1);
  } while (iVar2 < 0x10);
  STREAM_RemoveAllObjectsNotInUse();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_FinishLoad(struct _StreamUnit *streamUnit /*$s1*/)
 // line 1339, offset 0x8005a04c
	/* begin block 1 */
		// Start line: 1340
		// Start offset: 0x8005A04C
		// Variables:
	// 		struct Level *level; // $s0
	// 		char sfxName[80]; // stack offset -96
	/* end block 1 */
	// End offset: 0x8005A160
	// End Line: 1408

	/* begin block 2 */
		// Start line: 3189
	/* end block 2 */
	// End Line: 3190

void STREAM_FinishLoad(_StreamUnit *streamUnit)

{
  long lVar1;
  int iVar2;
  _MultiSignal *p_Var3;
  Level *level;
  char acStack96 [80];
  
  STREAM_FillOutFileNames(streamUnit->baseAreaName,(char *)0x0,(char *)0x0,acStack96);
  level = streamUnit->level;
  level->morphLastStep = -1;
  streamUnit->sfxFileHandle = 0;
  lVar1 = LOAD_DoesFileExist(acStack96);
  if (lVar1 != 0) {
    iVar2 = aadLoadDynamicSfx(streamUnit->baseAreaName,streamUnit->StreamUnitID,1);
    streamUnit->sfxFileHandle = (short)iVar2;
  }
  LoadLevelObjects(streamUnit);
  streamUnit->FogColor = *(long *)&level->backColorR;
  level->fogFar = streamUnit->TargetFogFar;
  level->fogNear = streamUnit->TargetFogNear;
  LIGHT_CalcDQPTable(level);
  STREAM_CalculateWaterLevel(level);
  if (gameTrackerX.gameData.asmData.MorphType == 1) {
    MORPH_UpdateNormals(level);
  }
  STREAM_ConnectStream(streamUnit);
  streamUnit->used = 2;
  STREAM_DoObjectLoadAndDump(streamUnit);
  EVENT_LoadEventsForLevel(streamUnit->StreamUnitID,level);
  PLANAPI_InitPlanMkrList(streamUnit);
  p_Var3 = level->startUnitLoadedSignal;
  if (p_Var3 != (_MultiSignal *)0x0) {
    p_Var3->flags = p_Var3->flags | 1;
    SIGNAL_HandleSignal(gameTrackerX.playerInstance,level->startUnitLoadedSignal->signalList,0);
    EVENT_AddSignalToReset(level->startUnitLoadedSignal);
  }
  SAVE_IntroForStreamID(streamUnit);
  SAVE_UpdateLevelWithSave(streamUnit);
  EVENT_AddStreamToInstanceList(streamUnit);
  WARPGATE_FixUnit(streamUnit);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_LoadLevelReturn(void *loadData /*$s0*/, void *data /*$a1*/, void *data2 /*$s1*/)
 // line 1422, offset 0x8005a198
	/* begin block 1 */
		// Start line: 1423
		// Start offset: 0x8005A198
	/* end block 1 */
	// End offset: 0x8005A198
	// End Line: 1423

	/* begin block 2 */
		// Start line: 3369
	/* end block 2 */
	// End Line: 3370

void STREAM_LoadLevelReturn(void *loadData,void *data,void *data2)

{
  GetRCnt(0xf2000000);
  *(undefined4 *)data2 = *(undefined4 *)((int)loadData + 0xf8);
  gameTrackerX.StreamUnitID = *(long *)((int)loadData + 0xf8);
  gameTrackerX.level = (Level *)loadData;
  STREAM_SetMainFog((_StreamUnit *)data2);
  STREAM_FinishLoad((_StreamUnit *)data2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_StreamLoadLevelReturn(void *loadData /*$s0*/, void *data /*$a1*/, void *data2 /*$s1*/)
 // line 1457, offset 0x8005a1f8
	/* begin block 1 */
		// Start line: 1458
		// Start offset: 0x8005A1F8
		// Variables:
	// 		struct Level *level; // $s0
	// 		struct _StreamUnit *streamUnit; // $s1
	/* end block 1 */
	// End offset: 0x8005A2CC
	// End Line: 1555

	/* begin block 2 */
		// Start line: 3440
	/* end block 2 */
	// End Line: 3441

void STREAM_StreamLoadLevelReturn(void *loadData,void *data,void *data2)

{
  short fogNear;
  short fogFar;
  
  GetRCnt(0xf2000000);
  *(undefined4 *)data2 = *(undefined4 *)((int)loadData + 0xf8);
  if (*(short *)((int)data2 + 4) == 3) {
    *(undefined2 *)((int)data2 + 4) = 0;
    *(undefined2 *)((int)data2 + 6) = 0;
    MEMPACK_Free(*(char **)((int)data2 + 8));
    *(undefined4 *)((int)data2 + 8) = 0;
  }
  else {
    if (gameTrackerX.gameData.asmData.MorphType == 0) {
      fogNear = *(short *)((int)loadData + 0xa6);
      fogFar = *(short *)((int)loadData + 0xa4);
    }
    else {
      fogNear = *(short *)((int)loadData + 0x4a);
      fogFar = *(short *)((int)loadData + 0x48);
    }
    STREAM_SetStreamFog((_StreamUnit *)data2,fogNear,fogFar);
    STREAM_FinishLoad((_StreamUnit *)data2);
    if ((gameTrackerX.playerInstance != (_Instance *)0x0) &&
       (*(int *)((int)loadData + 0xf8) == (gameTrackerX.playerInstance)->currentStreamUnitID)) {
      strcpy(gameTrackerX.baseAreaName,*(char **)((int)loadData + 0x98));
      STREAM_SetMainFog((_StreamUnit *)data2);
      gameTrackerX.StreamUnitID = *(long *)((int)loadData + 0xf8);
      gameTrackerX.level = (Level *)loadData;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_UpdateLevelPointer(struct Level *oldLevel /*$a0*/, struct Level *newLevel /*$a1*/, long sizeOfLevel /*$a2*/)
 // line 1582, offset 0x8005a2e0
	/* begin block 1 */
		// Start line: 1583
		// Start offset: 0x8005A2E0
		// Variables:
	// 		long i; // $t0
	// 		long offset; // $t1
	// 		struct GameTracker *gameTracker; // $v0

		/* begin block 1.1 */
			// Start line: 1611
			// Start offset: 0x8005A344
			// Variables:
		// 		struct _Instance *instance; // $a3
		/* end block 1.1 */
		// End offset: 0x8005A4D4
		// End Line: 1651
	/* end block 1 */
	// End offset: 0x8005A5B8
	// End Line: 1673

	/* begin block 2 */
		// Start line: 3164
	/* end block 2 */
	// End Line: 3165

void STREAM_UpdateLevelPointer(Level *oldLevel,Level *newLevel,long sizeOfLevel)

{
  Intro *pIVar1;
  void *pvVar2;
  _TFace *p_Var3;
  _Terrain *p_Var4;
  MultiSpline *pMVar5;
  STracker *pSVar6;
  Level *pLVar7;
  _Instance *p_Var8;
  Camera *pCVar9;
  int iVar10;
  Level *pLVar11;
  Level *pLVar12;
  
  pLVar12 = (Level *)((int)newLevel - (int)oldLevel);
  iVar10 = 0;
  pSVar6 = &StreamTracker;
  while ((pSVar6->StreamList[0].used != 2 || (pSVar6->StreamList[0].level != oldLevel))) {
    iVar10 = iVar10 + 1;
    pSVar6 = (STracker *)(pSVar6->StreamList + 1);
    if (0xf < iVar10) {
LAB_8005a330:
      if (gameTrackerX.level == oldLevel) {
        gameTrackerX.level = newLevel;
      }
      p_Var8 = (gameTrackerX.instanceList)->first;
      if (p_Var8 != (_Instance *)0x0) {
        pLVar11 = (Level *)((int)&oldLevel->terrain + sizeOfLevel);
        do {
          pLVar7 = (Level *)p_Var8->intro;
          if ((oldLevel <= pLVar7) && (pLVar7 <= pLVar11)) {
            pIVar1 = (Intro *)0x0;
            if (pLVar7 != (Level *)0x0) {
              pIVar1 = (Intro *)((int)pLVar7 + (int)pLVar12);
            }
            p_Var8->intro = pIVar1;
          }
          pLVar7 = (Level *)p_Var8->introData;
          if ((oldLevel <= pLVar7) && (pLVar7 <= pLVar11)) {
            pvVar2 = (void *)0x0;
            if (pLVar7 != (Level *)0x0) {
              pvVar2 = (void *)((int)pLVar7 + (int)pLVar12);
            }
            p_Var8->introData = pvVar2;
          }
          pLVar7 = (Level *)p_Var8->tface;
          if ((oldLevel <= pLVar7) && (pLVar7 <= pLVar11)) {
            p_Var3 = (_TFace *)0x0;
            if (pLVar7 != (Level *)0x0) {
              p_Var3 = (_TFace *)((int)pLVar7 + (int)pLVar12);
            }
            p_Var8->tface = p_Var3;
          }
          pLVar7 = (Level *)p_Var8->waterFace;
          if ((oldLevel <= pLVar7) && (pLVar7 <= pLVar11)) {
            p_Var3 = (_TFace *)0x0;
            if (pLVar7 != (Level *)0x0) {
              p_Var3 = (_TFace *)((int)pLVar7 + (int)pLVar12);
            }
            p_Var8->waterFace = p_Var3;
          }
          pLVar7 = (Level *)p_Var8->waterFaceTerrain;
          if ((oldLevel <= pLVar7) && (pLVar7 <= pLVar11)) {
            p_Var4 = (_Terrain *)0x0;
            if (pLVar7 != (Level *)0x0) {
              p_Var4 = (_Terrain *)((int)pLVar7 + (int)pLVar12);
            }
            p_Var8->waterFaceTerrain = p_Var4;
          }
          pLVar7 = (Level *)p_Var8->oldTFace;
          if ((oldLevel <= pLVar7) && (pLVar7 <= pLVar11)) {
            p_Var3 = (_TFace *)0x0;
            if (pLVar7 != (Level *)0x0) {
              p_Var3 = (_TFace *)((int)pLVar7 + (int)pLVar12);
            }
            p_Var8->oldTFace = p_Var3;
          }
          pLVar7 = (Level *)p_Var8->tfaceLevel;
          if ((oldLevel <= pLVar7) && (pLVar7 <= pLVar11)) {
            pvVar2 = (void *)0x0;
            if (pLVar7 != (Level *)0x0) {
              pvVar2 = (void *)((int)pLVar7 + (int)pLVar12);
            }
            p_Var8->tfaceLevel = pvVar2;
          }
          pLVar7 = (Level *)p_Var8->cachedTFaceLevel;
          if ((oldLevel <= pLVar7) && (pLVar7 <= pLVar11)) {
            pvVar2 = (void *)0x0;
            if (pLVar7 != (Level *)0x0) {
              pvVar2 = (void *)((int)pLVar7 + (int)pLVar12);
            }
            p_Var8->cachedTFaceLevel = pvVar2;
          }
          p_Var8 = p_Var8->next;
        } while (p_Var8 != (_Instance *)0x0);
      }
      pMVar5 = theCamera.data.Cinematic.posSpline;
      if (((oldLevel <= theCamera.data.Cinematic.posSpline) &&
          (theCamera.data.Cinematic.posSpline <=
           (MultiSpline *)((int)&oldLevel->terrain + sizeOfLevel))) &&
         (pMVar5 = (MultiSpline *)0x0, theCamera.data.Cinematic.posSpline != (MultiSpline *)0x0)) {
        pMVar5 = (MultiSpline *)((int)theCamera.data.Cinematic.posSpline + (int)pLVar12);
      }
      theCamera.data.Cinematic.posSpline = pMVar5;
      pMVar5 = theCamera.data.Cinematic.targetSpline;
      if (((oldLevel <= theCamera.data.Cinematic.targetSpline) &&
          (theCamera.data.Cinematic.targetSpline <=
           (MultiSpline *)((int)&oldLevel->terrain + sizeOfLevel))) &&
         (pMVar5 = (MultiSpline *)0x0, theCamera.data.Cinematic.targetSpline != (MultiSpline *)0x0))
      {
        pMVar5 = (MultiSpline *)((int)theCamera.data.Cinematic.targetSpline + (int)pLVar12);
      }
      theCamera.data.Cinematic.targetSpline = pMVar5;
      iVar10 = 0;
      if (-1 < theCamera.stack) {
        pLVar11 = (Level *)((int)&oldLevel->terrain + sizeOfLevel);
        pCVar9 = &theCamera;
        do {
          pLVar7 = (Level *)pCVar9->savedCinematic[0].posSpline;
          if ((oldLevel <= pLVar7) && (pLVar7 <= pLVar11)) {
            pMVar5 = (MultiSpline *)0x0;
            if (pLVar7 != (Level *)0x0) {
              pMVar5 = (MultiSpline *)((int)pLVar7 + (int)pLVar12);
            }
            pCVar9->savedCinematic[0].posSpline = pMVar5;
          }
          pLVar7 = (Level *)pCVar9->savedCinematic[0].targetSpline;
          if ((oldLevel <= pLVar7) && (pLVar7 <= pLVar11)) {
            pMVar5 = (MultiSpline *)0x0;
            if (pLVar7 != (Level *)0x0) {
              pMVar5 = (MultiSpline *)((int)pLVar7 + (int)pLVar12);
            }
            pCVar9->savedCinematic[0].targetSpline = pMVar5;
          }
          iVar10 = iVar10 + 1;
          pCVar9 = (Camera *)&(pCVar9->core).wcTransform2;
        } while (iVar10 <= theCamera.stack);
      }
      EVENT_UpdateResetSignalArrayAndWaterMovement(oldLevel,newLevel,sizeOfLevel);
      return;
    }
  }
  pSVar6->StreamList[0].level = newLevel;
  goto LAB_8005a330;
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ STREAM_WhichUnitPointerIsIn(void *pointer /*$s3*/)
 // line 1678, offset 0x8005a5d0
	/* begin block 1 */
		// Start line: 1679
		// Start offset: 0x8005A5D0
		// Variables:
	// 		int i; // $s2
	// 		int size; // $v1
	// 		struct Level *level; // $s0
	/* end block 1 */
	// End offset: 0x8005A65C
	// End Line: 1699

	/* begin block 2 */
		// Start line: 3875
	/* end block 2 */
	// End Line: 3876

_StreamUnit * STREAM_WhichUnitPointerIsIn(void *pointer)

{
  ulong uVar1;
  Level *address;
  STracker *pSVar2;
  int iVar3;
  
  iVar3 = 0;
  pSVar2 = &StreamTracker;
  do {
    if ((*(short *)pSVar2->StreamList == 2) &&
       (address = *(Level **)pSVar2->StreamList, address != (Level *)0x0)) {
      uVar1 = MEMPACK_Size((char *)address);
      if ((address <= pointer) && (pointer <= (void *)((int)&address->terrain + uVar1))) {
        return (_StreamUnit *)pSVar2;
      }
    }
    iVar3 = iVar3 + 1;
    pSVar2 = (STracker *)(pSVar2->StreamList + 1);
    if (0xf < iVar3) {
      return (_StreamUnit *)0x0;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_UpdateObjectPointer(struct Object *oldObject /*$s2*/, struct Object *newObject /*$s3*/, long sizeOfObject /*$s4*/)
 // line 1701, offset 0x8005a67c
	/* begin block 1 */
		// Start line: 1702
		// Start offset: 0x8005A67C
		// Variables:
	// 		long i; // $a3
	// 		long d; // $a1
	// 		struct GameTracker *gameTracker; // $s0
	// 		long offset; // $s1
	// 		struct _ObjectTracker *otr; // $t0

		/* begin block 1.1 */
			// Start line: 1722
			// Start offset: 0x8005A6D0
			// Variables:
		// 		int j; // $a1
		// 		struct Object *object; // $a2
		/* end block 1.1 */
		// End offset: 0x8005A75C
		// End Line: 1732

		/* begin block 1.2 */
			// Start line: 1750
			// Start offset: 0x8005A7B8
			// Variables:
		// 		struct _Instance *instance; // $s0
		/* end block 1.2 */
		// End offset: 0x8005A8D0
		// End Line: 1779
	/* end block 1 */
	// End offset: 0x8005A8FC
	// End Line: 1787

	/* begin block 2 */
		// Start line: 3943
	/* end block 2 */
	// End Line: 3944

void STREAM_UpdateObjectPointer(Object *oldObject,Object *newObject,long sizeOfObject)

{
  _ObjectTracker *p_Var1;
  _ObjectTracker *p_Var2;
  Object *pOVar3;
  int iVar4;
  void *pvVar5;
  _HModel *p_Var6;
  int iVar7;
  Object *pOVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  Object *pOVar12;
  int iVar13;
  _Instance *instance;
  Object *offset;
  
  offset = (Object *)((int)newObject - (int)oldObject);
  p_Var1 = FindObjectInTracker(oldObject);
  iVar13 = 0;
  if (p_Var1 != (_ObjectTracker *)0x0) {
    p_Var1->object = newObject;
    if ('\0' < p_Var1->numObjectsUsing) {
      p_Var2 = p_Var1;
      do {
        pOVar12 = gameTrackerX.GlobalObjects[p_Var2->objectsUsing[0]].object;
        if ((pOVar12 != (Object *)0x0) && (iVar10 = 0, 0 < pOVar12->numAnims)) {
          do {
            pOVar8 = (Object *)pOVar12->animList[iVar10];
            if ((oldObject <= pOVar8) &&
               (pOVar8 <= (Object *)((int)&oldObject->oflags + sizeOfObject))) {
              pOVar3 = (Object *)0x0;
              if (pOVar8 != (Object *)0x0) {
                pOVar3 = (Object *)((int)pOVar8 + (int)offset);
              }
              *(Object **)(pOVar12->animList + iVar10) = pOVar3;
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 < pOVar12->numAnims);
        }
        iVar13 = iVar13 + 1;
        p_Var2 = (_ObjectTracker *)(p_Var1->name + iVar13);
      } while (iVar13 < p_Var1->numObjectsUsing);
    }
    OBTABLE_ChangeObjectAccessPointers(oldObject,newObject);
    if ((((newObject->oflags & 0x8000000U) != 0) && (newObject->relocList != (ulong *)0x0)) &&
       (newObject->relocModule != (void *)0x0)) {
      RELMOD_RelocModulePointers
                ((int)newObject->relocModule,(int)offset,(int *)newObject->relocList);
    }
    instance = (gameTrackerX.instanceList)->first;
    while (instance != (_Instance *)0x0) {
      if (instance->object == oldObject) {
        instance->object = newObject;
        if ((instance->hModelList != (_HModel *)0x0) && (iVar13 = 0, 0 < newObject->numModels)) {
          iVar10 = 0;
          do {
            p_Var6 = instance->hModelList;
            iVar11 = 0;
            if (0 < *(int *)((int)&p_Var6->numHPrims + iVar10)) {
              do {
                iVar4 = iVar11 * 8 + *(int *)((int)&p_Var6->hPrimList + iVar10);
                iVar9 = *(int *)(iVar4 + 4);
                iVar7 = 0;
                if (iVar9 != 0) {
                  iVar7 = (int)&offset->oflags + iVar9;
                }
                *(int *)(iVar4 + 4) = iVar7;
                p_Var6 = instance->hModelList;
                iVar11 = iVar11 + 1;
              } while (iVar11 < p_Var6[iVar13].numHPrims);
            }
            iVar13 = iVar13 + 1;
            iVar10 = iVar10 + 8;
          } while (iVar13 < instance->object->numModels);
        }
        OBTABLE_RelocateInstanceObject(instance,(long)offset);
      }
      pOVar12 = (Object *)instance->data;
      if ((oldObject <= pOVar12) && (pOVar12 <= (Object *)((int)&oldObject->oflags + sizeOfObject)))
      {
        pvVar5 = (void *)0x0;
        if (pOVar12 != (Object *)0x0) {
          pvVar5 = (void *)((int)pOVar12 + (int)offset);
        }
        instance->data = pvVar5;
      }
      instance = instance->next;
    }
  }
  OBTABLE_RelocateObjectTune(newObject,(long)offset);
  if ((newObject->oflags2 & 0x20000000U) != 0) {
    FX_RelocateFXPointers(oldObject,newObject,sizeOfObject);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_UpdateInstanceCollisionInfo(struct _HModel *oldHModel /*$a0*/, struct _HModel *newHModel /*$a1*/)
 // line 1789, offset 0x8005a91c
	/* begin block 1 */
		// Start line: 1791
		// Start offset: 0x8005A91C
		// Variables:
	// 		struct _Instance *instance; // $v1
	/* end block 1 */
	// End offset: 0x8005A958
	// End Line: 1804

	/* begin block 2 */
		// Start line: 4141
	/* end block 2 */
	// End Line: 4142

	/* begin block 3 */
		// Start line: 4142
	/* end block 3 */
	// End Line: 4143

void STREAM_UpdateInstanceCollisionInfo(_HModel *oldHModel,_HModel *newHModel)

{
  _Instance *p_Var1;
  
  p_Var1 = (gameTrackerX.instanceList)->first;
  while (p_Var1 != (_Instance *)0x0) {
    if (p_Var1->hModelList == oldHModel) {
      p_Var1->hModelList = newHModel;
    }
    p_Var1 = p_Var1->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_LoadMainVram(struct GameTracker *gameTracker /*$a0*/, char *baseAreaName /*$a1*/, struct _StreamUnit *streamUnit /*$a2*/)
 // line 1844, offset 0x8005a960
	/* begin block 1 */
		// Start line: 1845
		// Start offset: 0x8005A960
		// Variables:
	// 		char dramName[80]; // stack offset -176
	// 		char vramName[80]; // stack offset -96
	// 		struct VramBuffer *vramBuffer; // $v0
	// 		struct Level *level; // $s0
	/* end block 1 */
	// End offset: 0x8005A960
	// End Line: 1845

	/* begin block 2 */
		// Start line: 3688
	/* end block 2 */
	// End Line: 3689

void STREAM_LoadMainVram(GameTracker *gameTracker,char *baseAreaName,_StreamUnit *streamUnit)

{
  short sVar1;
  undefined4 *retData;
  Level *pLVar2;
  char acStack176 [80];
  char acStack96 [80];
  
  pLVar2 = streamUnit->level;
  STREAM_FillOutFileNames(gameTracker->baseAreaName,acStack176,acStack96,(char *)0x0);
  retData = (undefined4 *)MEMPACK_Malloc((int)(pLVar2->vramSize).w * 2 + 0x14,'#');
  *(undefined4 **)(retData + 4) = retData + 5;
  *retData = 0;
  *(short *)(retData + 1) = (pLVar2->vramSize).x + 0x200;
  *(short *)((int)retData + 6) = (pLVar2->vramSize).y;
  *(short *)(retData + 2) = (pLVar2->vramSize).w;
  sVar1 = (pLVar2->vramSize).h;
  M_TrackClutUpdate = 0;
  *(undefined2 *)(retData + 3) = 0;
  *(undefined2 *)((int)retData + 0xe) = 0;
  *(short *)((int)retData + 10) = sVar1;
  LOAD_NonBlockingBufferedLoad(acStack96,VRAM_TransferBufferToVram,retData,(void *)0x0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_MoveIntoNewStreamUnit()
 // line 1892, offset 0x8005aa08
	/* begin block 1 */
		// Start line: 4364
	/* end block 1 */
	// End Line: 4365

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_MoveIntoNewStreamUnit(void)

{
  (gameTrackerX.playerInstance)->cachedTFace = -1;
  (gameTrackerX.playerInstance)->cachedTFaceLevel = (void *)0x0;
  (gameTrackerX.playerInstance)->currentStreamUnitID = gameTrackerX.moveRazielToStreamID;
  INSTANCE_UpdateFamilyStreamUnitID(gameTrackerX.playerInstance);
  GAMELOOP_StreamLevelLoadAndInit
            (gameTrackerX.S_baseAreaName,&gameTrackerX,(int)gameTrackerX.toSignal,
             (int)gameTrackerX.fromSignal);
  gameTrackerX.SwitchToNewStreamUnit = 0;
  if (gameTrackerX.SwitchToNewWarpIndex != -1) {
    SndPlayVolPan(0x184,0x7f,0x40,0);
    CurrentWarpNumber = (long)gameTrackerX.SwitchToNewWarpIndex;
  }
  return;
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ STREAM_LoadLevel(char *baseAreaName /*$s3*/, struct StreamUnitPortal *streamPortal /*$s4*/, int loadnext /*$a2*/)
 // line 1912, offset 0x8005aa9c
	/* begin block 1 */
		// Start line: 1913
		// Start offset: 0x8005AA9C
		// Variables:
	// 		int i; // $s2
	// 		long streamID; // $s5
	// 		struct _StreamUnit *streamUnit; // $s1

		/* begin block 1.1 */
			// Start line: 1954
			// Start offset: 0x8005AB2C
		/* end block 1.1 */
		// End offset: 0x8005AB2C
		// End Line: 1957

		/* begin block 1.2 */
			// Start line: 1966
			// Start offset: 0x8005AB60
			// Variables:
		// 		struct Level *level; // $s0
		/* end block 1.2 */
		// End offset: 0x8005AB8C
		// End Line: 1976

		/* begin block 1.3 */
			// Start line: 2038
			// Start offset: 0x8005ABE4
			// Variables:
		// 		char dramName[80]; // stack offset -112
		/* end block 1.3 */
		// End offset: 0x8005AC8C
		// End Line: 2095
	/* end block 1 */
	// End offset: 0x8005AC98
	// End Line: 2098

	/* begin block 2 */
		// Start line: 4406
	/* end block 2 */
	// End Line: 4407

_StreamUnit * STREAM_LoadLevel(char *baseAreaName,StreamUnitPortal *streamPortal,int loadnext)

{
  int iVar1;
  int iVar2;
  _StreamUnit *streamUnit;
  short fogNear;
  short fogFar;
  int iVar3;
  long lVar4;
  char acStack112 [80];
  
  lVar4 = -1;
  if (streamPortal != (StreamUnitPortal *)0x0) {
    lVar4 = streamPortal->streamID;
  }
  iVar3 = 0;
  iVar1 = 0;
  while( true ) {
    streamUnit = (_StreamUnit *)((int)&StreamTracker.StreamList[0].StreamUnitID + iVar1);
    if ((*(short *)((int)&StreamTracker.StreamList[0].used + iVar1) != 0) &&
       (iVar2 = strcmpi(StreamTracker.StreamList[0].baseAreaName + iVar1,baseAreaName), iVar2 == 0))
    break;
    iVar3 = iVar3 + 1;
    iVar1 = iVar3 * 0x40;
    if (0xf < iVar3) {
LAB_8005abb8:
      if (iVar3 == 0x10) {
        iVar3 = 0;
        iVar1 = 0;
        do {
          streamUnit = (_StreamUnit *)((int)&StreamTracker.StreamList[0].StreamUnitID + iVar1);
          iVar3 = iVar3 + 1;
          if (*(short *)((int)&StreamTracker.StreamList[0].used + iVar1) == 0) {
            STREAM_FillOutFileNames(baseAreaName,acStack112,(char *)0x0,(char *)0x0);
            *(undefined2 *)((int)&StreamTracker.StreamList[0].used + iVar1) = 1;
            strcpy(StreamTracker.StreamList[0].baseAreaName + iVar1,baseAreaName);
            streamUnit->StreamUnitID = lVar4;
            *(undefined4 *)((int)&StreamTracker.StreamList[0].FrameCount + iVar1) = 0;
            *(undefined2 *)((int)&StreamTracker.StreamList[0].flags + iVar1) = 0;
            if (streamPortal == (StreamUnitPortal *)0x0) {
              strcpy(gameTrackerX.baseAreaName,baseAreaName);
              gameTrackerX.StreamUnitID = streamUnit->StreamUnitID;
              LOAD_NonBlockingBinaryLoad
                        (acStack112,STREAM_LoadLevelReturn,(void *)0x0,streamUnit,
                         (void **)((int)&StreamTracker.StreamList[0].level + iVar1),2);
              return streamUnit;
            }
            streamPortal->toStreamUnit = (_StreamUnit *)0x0;
            LOAD_NonBlockingBinaryLoad
                      (acStack112,STREAM_StreamLoadLevelReturn,(void *)0x0,streamUnit,
                       (void **)((int)&StreamTracker.StreamList[0].level + iVar1),2);
            return streamUnit;
          }
          iVar1 = iVar3 * 0x40;
        } while (iVar3 < 0x10);
      }
      return streamUnit;
    }
  }
  fogNear = *(short *)((int)&StreamTracker.StreamList[0].used + iVar1);
  if (fogNear == 3) {
    *(undefined2 *)((int)&StreamTracker.StreamList[0].used + iVar1) = 1;
  }
  else {
    if (fogNear != 1) {
      *(undefined4 *)((int)&StreamTracker.StreamList[0].FrameCount + iVar1) = 0;
      if (streamPortal == (StreamUnitPortal *)0x0) {
        strcpy(gameTrackerX.baseAreaName,baseAreaName);
        STREAM_SetMainFog(streamUnit);
        gameTrackerX.StreamUnitID = streamUnit->StreamUnitID;
        gameTrackerX.level = *(Level **)((int)&StreamTracker.StreamList[0].level + iVar1);
      }
      else {
        iVar1 = *(int *)((int)&StreamTracker.StreamList[0].level + iVar1);
        STREAM_ConnectStream(streamUnit);
        if (gameTrackerX.gameData.asmData.MorphType == 0) {
          fogNear = *(short *)(iVar1 + 0xa6);
          fogFar = *(short *)(iVar1 + 0xa4);
        }
        else {
          fogNear = *(short *)(iVar1 + 0x4a);
          fogFar = *(short *)(iVar1 + 0x48);
        }
        STREAM_SetStreamFog(streamUnit,fogNear,fogFar);
      }
    }
  }
  goto LAB_8005abb8;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RemoveIntroducedLights(struct Level *level /*$s2*/)
 // line 2103, offset 0x8005acc0
	/* begin block 1 */
		// Start line: 2104
		// Start offset: 0x8005ACC0
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8005AD8C
	// End Line: 2125

	/* begin block 2 */
		// Start line: 4961
	/* end block 2 */
	// End Line: 4962

void RemoveIntroducedLights(Level *level)

{
  NodeType *node;
  int iVar1;
  int iVar2;
  
  LIGHT_Restore(gameTrackerX.lightInfo);
  (gameTrackerX.lightInfo)->numSavedColors = 0;
  iVar1 = 0;
  if (0 < level->numSpotLights) {
    iVar2 = 0;
    do {
      node = (NodeType *)((int)&(level->spotLightList->node).prev + iVar2);
      if ((*(byte *)((int)&node[1].prev + 3) & 0x10) != 0) {
        LIST_DeleteFunc(node);
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x28;
    } while (iVar1 < level->numSpotLights);
  }
  iVar1 = 0;
  if (0 < level->numPointLights) {
    iVar2 = 0;
    do {
      node = (NodeType *)((int)&(level->pointLightList->node).prev + iVar2);
      if ((*(byte *)((int)&node[1].prev + 3) & 0x10) != 0) {
        LIST_DeleteFunc(node);
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x18;
    } while (iVar1 < level->numPointLights);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_RemoveInstancesWithIDInInstanceList(struct _InstanceList *list /*$s4*/, long id /*$s2*/, struct Level *level /*$s3*/)
 // line 2127, offset 0x8005ada4
	/* begin block 1 */
		// Start line: 2128
		// Start offset: 0x8005ADA4
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		struct _Instance *next; // $s1
	/* end block 1 */
	// End offset: 0x8005AE30
	// End Line: 2156

	/* begin block 2 */
		// Start line: 5020
	/* end block 2 */
	// End Line: 5021

void STREAM_RemoveInstancesWithIDInInstanceList(_InstanceList *list,long id,Level *level)

{
  _Instance *instance;
  _Instance *p_Var1;
  
  p_Var1 = list->first;
  while (instance = p_Var1, instance != (_Instance *)0x0) {
    p_Var1 = instance->next;
    if (instance->currentStreamUnitID == id) {
      SAVE_Instance(instance,level);
      INSTANCE_ReallyRemoveInstance(list,instance,0);
    }
    else {
      if (instance->birthStreamUnitID == id) {
        SAVE_Instance(instance,level);
        instance->intro = (Intro *)0x0;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_MarkUnitNeeded(long streamID /*$a0*/)
 // line 2158, offset 0x8005ae50
	/* begin block 1 */
		// Start line: 2160
		// Start offset: 0x8005AE50
		// Variables:
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x8005AE94
	// End Line: 2176

	/* begin block 2 */
		// Start line: 5085
	/* end block 2 */
	// End Line: 5086

	/* begin block 3 */
		// Start line: 5086
	/* end block 3 */
	// End Line: 5087

	/* begin block 4 */
		// Start line: 5089
	/* end block 4 */
	// End Line: 5090

void STREAM_MarkUnitNeeded(long streamID)

{
  STracker *pSVar1;
  int iVar2;
  
  iVar2 = 0;
  pSVar1 = &StreamTracker;
  while ((pSVar1->StreamList[0].used == 0 || (streamID != pSVar1->StreamList[0].StreamUnitID))) {
    iVar2 = iVar2 + 1;
    pSVar1 = (STracker *)(pSVar1->StreamList + 1);
    if (0xf < iVar2) {
      return;
    }
  }
  pSVar1->StreamList[0].FrameCount = gameTrackerX.displayFrameCount;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpUnit(struct _StreamUnit *streamUnit /*$s2*/, long doSave /*$s3*/)
 // line 2178, offset 0x8005ae9c
	/* begin block 1 */
		// Start line: 2179
		// Start offset: 0x8005AE9C
		// Variables:
	// 		int i; // $s0
	// 		int j; // $a0
	// 		int numportals; // $a1

		/* begin block 1.1 */
			// Start line: 2208
			// Start offset: 0x8005AF50
			// Variables:
		// 		char dramName[80]; // stack offset -104
		/* end block 1.1 */
		// End offset: 0x8005AF7C
		// End Line: 2219

		/* begin block 1.2 */
			// Start line: 2236
			// Start offset: 0x8005AFB8
			// Variables:
		// 		struct _SFXMkr *sfxMkr; // $a1
		/* end block 1.2 */
		// End offset: 0x8005AFB8
		// End Line: 2236
	/* end block 1 */
	// End offset: 0x8005B064
	// End Line: 2268

	/* begin block 2 */
		// Start line: 5134
	/* end block 2 */
	// End Line: 5135

void STREAM_DumpUnit(_StreamUnit *streamUnit,long doSave)

{
  int *piVar1;
  long lVar2;
  _StreamUnit **pp_Var3;
  Level *pLVar4;
  int iVar5;
  int iVar6;
  uchar **ppuVar7;
  STracker *pSVar8;
  int iVar9;
  char acStack104 [80];
  
  iVar9 = 0;
  pSVar8 = &StreamTracker;
  do {
    if (pSVar8->StreamList[0].used == 2) {
      piVar1 = (int *)(pSVar8->StreamList[0].level)->terrain->StreamUnits;
      iVar6 = *piVar1;
      iVar5 = 0;
      if (0 < iVar6) {
        pp_Var3 = (_StreamUnit **)(piVar1 + 0xb);
        do {
          if (*pp_Var3 == streamUnit) {
            *pp_Var3 = (_StreamUnit *)0x0;
          }
          iVar5 = iVar5 + 1;
          pp_Var3 = pp_Var3 + 0x17;
        } while (iVar5 < iVar6);
      }
    }
    iVar9 = iVar9 + 1;
    pSVar8 = (STracker *)(pSVar8->StreamList + 1);
  } while (iVar9 < 0x10);
  if ((streamUnit->used == 1) || (streamUnit->used == 3)) {
    STREAM_FillOutFileNames(streamUnit->baseAreaName,acStack104,(char *)0x0,(char *)0x0);
    LOAD_AbortFileLoad(acStack104,STREAM_StreamLoadLevelAbort);
    streamUnit->used = 0;
  }
  else {
    lVar2 = WARPGATE_IsUnitWarpRoom(streamUnit);
    if (lVar2 != 0) {
      WARPGATE_RemoveFromArray(streamUnit);
    }
    EVENT_RemoveStreamToInstanceList(streamUnit);
    pLVar4 = streamUnit->level;
    iVar9 = 0;
    if (0 < pLVar4->NumberOfSFXMarkers) {
      iVar5 = 0;
      do {
        ppuVar7 = (uchar **)((int)&pLVar4->SFXMarkerList->soundData + iVar5);
        SOUND_EndInstanceSounds(*ppuVar7,(SoundInstance *)(ppuVar7 + 2));
        pLVar4 = streamUnit->level;
        iVar9 = iVar9 + 1;
        iVar5 = iVar5 + 0x24;
      } while (iVar9 < pLVar4->NumberOfSFXMarkers);
    }
    if ((int)streamUnit->sfxFileHandle != 0) {
      aadFreeDynamicSfx((int)streamUnit->sfxFileHandle);
    }
    PLANAPI_DeleteNodeFromPoolByUnit(streamUnit->StreamUnitID);
    STREAM_RemoveInstancesWithIDInInstanceList
              (gameTrackerX.instanceList,streamUnit->StreamUnitID,streamUnit->level);
    if (doSave != 0) {
      EVENT_SaveEventsFromLevel(streamUnit->StreamUnitID,streamUnit->level);
      SAVE_CreatedSavedLevel(streamUnit->StreamUnitID,streamUnit->level);
    }
    MEMPACK_Free((char *)streamUnit->level);
    streamUnit->level = (Level *)0x0;
    streamUnit->used = 0;
  }
  streamUnit->flags = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpAllUnitsNotNeeded()
 // line 2270, offset 0x8005b080
	/* begin block 1 */
		// Start line: 2271
		// Start offset: 0x8005B080
		// Variables:
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x8005B0D4
	// End Line: 2283

	/* begin block 2 */
		// Start line: 5339
	/* end block 2 */
	// End Line: 5340

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_DumpAllUnitsNotNeeded(void)

{
  STracker *streamUnit;
  int iVar1;
  
  iVar1 = 0;
  streamUnit = &StreamTracker;
  do {
    if ((*(short *)streamUnit->StreamList != 0) &&
       (*(ulong *)streamUnit->StreamList != gameTrackerX.displayFrameCount)) {
      STREAM_DumpUnit((_StreamUnit *)streamUnit,1);
    }
    iVar1 = iVar1 + 1;
    streamUnit = (STracker *)(streamUnit->StreamList + 1);
  } while (iVar1 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpAllLevels(long IDNoRemove /*$s2*/, int DoSave /*$s3*/)
 // line 2285, offset 0x8005b0e8
	/* begin block 1 */
		// Start line: 2286
		// Start offset: 0x8005B0E8
		// Variables:
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x8005B148
	// End Line: 2299

	/* begin block 2 */
		// Start line: 5380
	/* end block 2 */
	// End Line: 5381

void STREAM_DumpAllLevels(long IDNoRemove,int DoSave)

{
  STracker *streamUnit;
  int iVar1;
  
  iVar1 = 0;
  streamUnit = &StreamTracker;
  do {
    if ((*(short *)streamUnit->StreamList != 0) &&
       (streamUnit->StreamList[0].StreamUnitID != IDNoRemove)) {
      STREAM_DumpUnit((_StreamUnit *)streamUnit,DoSave);
    }
    iVar1 = iVar1 + 1;
    streamUnit = (STracker *)(streamUnit->StreamList + 1);
  } while (iVar1 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_LoadCurrentWarpRoom(struct StreamUnitPortal *streamPortal /*$s1*/, struct _StreamUnit *mainStreamUnit /*$a1*/)
 // line 2302, offset 0x8005b164
	/* begin block 1 */
		// Start line: 5427
	/* end block 1 */
	// End Line: 5428

	/* begin block 2 */
		// Start line: 5428
	/* end block 2 */
	// End Line: 5429

void STREAM_LoadCurrentWarpRoom(StreamUnitPortal *streamPortal,_StreamUnit *mainStreamUnit)

{
  long lVar1;
  int iVar2;
  _StreamUnit *p_Var3;
  
  iVar2 = strcmpi(mainStreamUnit->level->worldName,(char *)(&WarpRoomArray + CurrentWarpNumber));
  if (iVar2 == 0) {
    WarpGateLoadInfo.loading = '\x03';
    WarpGateLoadInfo.curTime = WarpGateLoadInfo.maxTime;
  }
  p_Var3 = STREAM_LoadLevel((char *)(&WarpRoomArray + CurrentWarpNumber),streamPortal,0);
  lVar1 = CurrentWarpNumber;
  (&WarpRoomArray)[CurrentWarpNumber].streamUnit = p_Var3;
  if (p_Var3 != (_StreamUnit *)0x0) {
    streamPortal->toStreamUnit = p_Var3;
    ((&WarpRoomArray)[lVar1].streamUnit)->flags = ((&WarpRoomArray)[lVar1].streamUnit)->flags | 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_RelocateLoadedWarpRooms(struct _StreamUnit *mainUnit /*$s4*/, struct StreamUnitPortal *streamPortal /*$s5*/)
 // line 2319, offset 0x8005b220
	/* begin block 1 */
		// Start line: 2320
		// Start offset: 0x8005B220
		// Variables:
	// 		int i; // $s2
	/* end block 1 */
	// End offset: 0x8005B2A4
	// End Line: 2333

	/* begin block 2 */
		// Start line: 5464
	/* end block 2 */
	// End Line: 5465

void WARPGATE_RelocateLoadedWarpRooms(_StreamUnit *mainUnit,StreamUnitPortal *streamPortal)

{
  STracker *pSVar1;
  char *baseAreaName;
  int iVar2;
  
  iVar2 = 0;
  baseAreaName = StreamTracker.StreamList[0].baseAreaName;
  pSVar1 = &StreamTracker;
  do {
    if (((*(short *)pSVar1->StreamList == 2) && (pSVar1 != (STracker *)mainUnit)) &&
       ((*(ushort *)pSVar1->StreamList & 1) != 0)) {
      STREAM_LoadLevel(baseAreaName,streamPortal,0);
    }
    baseAreaName = baseAreaName + 0x40;
    iVar2 = iVar2 + 1;
    pSVar1 = (STracker *)(pSVar1->StreamList + 1);
  } while (iVar2 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ WARPGATE_GetWarpRoomIndex(char *name /*$s2*/)
 // line 2336, offset 0x8005b2c8
	/* begin block 1 */
		// Start line: 2337
		// Start offset: 0x8005B2C8
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8005B310
	// End Line: 2349

	/* begin block 2 */
		// Start line: 5517
	/* end block 2 */
	// End Line: 5518

long WARPGATE_GetWarpRoomIndex(char *name)

{
  int iVar1;
  int iVar2;
  WarpRoom *s1;
  
  iVar2 = 0;
  s1 = &WarpRoomArray;
  do {
    iVar1 = strcmpi((char *)s1,name);
    if (iVar1 == 0) {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
    s1 = s1 + 1;
  } while (iVar2 < 0xe);
  return -1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_UpdateAddToArray(struct _StreamUnit *streamUnit /*$s0*/)
 // line 2351, offset 0x8005b328
	/* begin block 1 */
		// Start line: 2352
		// Start offset: 0x8005B328
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x8005B364
	// End Line: 2360

	/* begin block 2 */
		// Start line: 5555
	/* end block 2 */
	// End Line: 5556

void WARPGATE_UpdateAddToArray(_StreamUnit *streamUnit)

{
  long lVar1;
  
  lVar1 = WARPGATE_GetWarpRoomIndex(streamUnit->baseAreaName);
  if (lVar1 != -1) {
    (&WarpRoomArray)[lVar1].streamUnit = streamUnit;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_RemoveFromArray(struct _StreamUnit *streamUnit /*$a0*/)
 // line 2362, offset 0x8005b374
	/* begin block 1 */
		// Start line: 2363
		// Start offset: 0x8005B374
	/* end block 1 */
	// End offset: 0x8005B394
	// End Line: 2370

	/* begin block 2 */
		// Start line: 5577
	/* end block 2 */
	// End Line: 5578

void WARPGATE_RemoveFromArray(_StreamUnit *streamUnit)

{
  long lVar1;
  
  lVar1 = WARPGATE_GetWarpRoomIndex(streamUnit->baseAreaName);
  if (lVar1 == -1) {
    CurrentWarpNumber = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_Init()
 // line 2373, offset 0x8005b3a4
	/* begin block 1 */
		// Start line: 2375
		// Start offset: 0x8005B3A4
		// Variables:
	// 		int n; // $a0
	/* end block 1 */
	// End offset: 0x8005B3E4
	// End Line: 2389

	/* begin block 2 */
		// Start line: 5599
	/* end block 2 */
	// End Line: 5600

	/* begin block 3 */
		// Start line: 5600
	/* end block 3 */
	// End Line: 5601

	/* begin block 4 */
		// Start line: 5612
	/* end block 4 */
	// End Line: 5613

/* WARNING: Unknown calling convention yet parameter storage is locked */

void WARPGATE_Init(void)

{
  WarpRoom *pWVar1;
  int iVar2;
  
  iVar2 = 0xd;
  pWVar1 = &WarpRoom_800d179c;
  WarpGateLoadInfo.fadeValue = 0x1000;
  WarpGateLoadInfo.warpgate_in_use = 0;
  WarpGateLoadInfo.loading = '\0';
  WarpGateLoadInfo.blocked = '\0';
  WarpGateLoadInfo.curTime = 0;
  WarpGateLoadInfo.maxTime = 0xf000;
  WarpGateLoadInfo.warpFaceInstance = (_Instance *)0x0;
  CurrentWarpNumber = 0;
  do {
    pWVar1->streamUnit = (_StreamUnit *)0x0;
    iVar2 = iVar2 + -1;
    pWVar1 = pWVar1 + -1;
  } while (-1 < iVar2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_StartUsingWarpgate()
 // line 2392, offset 0x8005b3ec
	/* begin block 1 */
		// Start line: 5650
	/* end block 1 */
	// End Line: 5651

	/* begin block 2 */
		// Start line: 5651
	/* end block 2 */
	// End Line: 5652

/* WARNING: Unknown calling convention yet parameter storage is locked */

void WARPGATE_StartUsingWarpgate(void)

{
  if (WarpGateLoadInfo.warpgate_in_use == 0) {
    SndPlayVolPan(0x16f,0x7f,0x40,0);
  }
  WarpGateLoadInfo.warpgate_in_use = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_EndUsingWarpgate()
 // line 2399, offset 0x8005b424
	/* begin block 1 */
		// Start line: 5665
	/* end block 1 */
	// End Line: 5666

/* WARNING: Unknown calling convention yet parameter storage is locked */

void WARPGATE_EndUsingWarpgate(void)

{
  if (WarpGateLoadInfo.warpgate_in_use == 1) {
    SndPlayVolPan(0x182,0x7f,0x40,0);
  }
  WarpGateLoadInfo.warpgate_in_use = 0;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ WARPGATE_IsWarpgateInUse()
 // line 2406, offset 0x8005b45c
	/* begin block 1 */
		// Start line: 5679
	/* end block 1 */
	// End Line: 5680

	/* begin block 2 */
		// Start line: 5680
	/* end block 2 */
	// End Line: 5681

/* WARNING: Unknown calling convention yet parameter storage is locked */

int WARPGATE_IsWarpgateInUse(void)

{
  return WarpGateLoadInfo.warpgate_in_use;
}



// decompiled code
// original method signature: 
// int /*$ra*/ WARPGATE_IsWarpgateActive()
 // line 2412, offset 0x8005b468
	/* begin block 1 */
		// Start line: 5691
	/* end block 1 */
	// End Line: 5692

	/* begin block 2 */
		// Start line: 5692
	/* end block 2 */
	// End Line: 5693

/* WARNING: Unknown calling convention yet parameter storage is locked */

int WARPGATE_IsWarpgateActive(void)

{
  return (uint)(WarpGateLoadInfo.loading != '\0');
}



// decompiled code
// original method signature: 
// int /*$ra*/ WARPGATE_IsWarpgateUsable()
 // line 2419, offset 0x8005b474
	/* begin block 1 */
		// Start line: 5705
	/* end block 1 */
	// End Line: 5706

	/* begin block 2 */
		// Start line: 5706
	/* end block 2 */
	// End Line: 5707

/* WARNING: Unknown calling convention yet parameter storage is locked */

int WARPGATE_IsWarpgateUsable(void)

{
  return (uint)(WarpGateLoadInfo._4_2_ == 4);
}



// decompiled code
// original method signature: 
// int /*$ra*/ WARPGATE_IsWarpgateReady()
 // line 2426, offset 0x8005b488
	/* begin block 1 */
		// Start line: 5719
	/* end block 1 */
	// End Line: 5720

	/* begin block 2 */
		// Start line: 5720
	/* end block 2 */
	// End Line: 5721

/* WARNING: Unknown calling convention yet parameter storage is locked */

int WARPGATE_IsWarpgateReady(void)

{
  return (uint)(WarpGateLoadInfo.loading == '\x04');
}



// decompiled code
// original method signature: 
// int /*$ra*/ WARPGATE_IsWarpgateSpectral()
 // line 2433, offset 0x8005b49c
	/* begin block 1 */
		// Start line: 5733
	/* end block 1 */
	// End Line: 5734

/* WARNING: Unknown calling convention yet parameter storage is locked */

int WARPGATE_IsWarpgateSpectral(void)

{
  int iVar1;
  
  iVar1 = strcmpi((char *)(&WarpRoomArray + CurrentWarpNumber),"under3");
  return (uint)(iVar1 == 0);
}



// decompiled code
// original method signature: 
// int /*$ra*/ WARPGATE_IsObjectOnWarpSide(struct _Instance *instance /*$a0*/)
 // line 2440, offset 0x8005b4d8
	/* begin block 1 */
		// Start line: 2442
		// Start offset: 0x8005B4D8
		// Variables:
	// 		int side; // $a0
	/* end block 1 */
	// End offset: 0x8005B534
	// End Line: 2461

	/* begin block 2 */
		// Start line: 5748
	/* end block 2 */
	// End Line: 5749

	/* begin block 3 */
		// Start line: 5749
	/* end block 3 */
	// End Line: 5750

	/* begin block 4 */
		// Start line: 5750
	/* end block 4 */
	// End Line: 5751

int WARPGATE_IsObjectOnWarpSide(_Instance *instance)

{
  int iVar1;
  int iVar2;
  
  if (WarpGateLoadInfo.warpFaceInstance == (_Instance *)0x0) {
    return 0;
  }
  iVar1 = (int)((WarpGateLoadInfo.warpFaceInstance)->position).y;
  iVar2 = iVar1 - theCamera.core.position.y;
  if (iVar1 - (instance->position).y < 0) {
    if (iVar2 < 0) {
      return 0;
    }
  }
  else {
    if (-1 < iVar2) {
      return 0;
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_IsItActive(struct _StreamUnit *streamUnit /*$a0*/)
 // line 2464, offset 0x8005b53c
	/* begin block 1 */
		// Start line: 2466
		// Start offset: 0x8005B53C
		// Variables:
	// 		struct Level *level; // $t1
	// 		int d; // $a1
	/* end block 1 */
	// End offset: 0x8005B5FC
	// End Line: 2488

	/* begin block 2 */
		// Start line: 5796
	/* end block 2 */
	// End Line: 5797

	/* begin block 3 */
		// Start line: 5797
	/* end block 3 */
	// End Line: 5798

	/* begin block 4 */
		// Start line: 5800
	/* end block 4 */
	// End Line: 5801

void WARPGATE_IsItActive(_StreamUnit *streamUnit)

{
  int iVar1;
  short *psVar2;
  Level *pLVar3;
  
  pLVar3 = streamUnit->level;
  streamUnit->flags = streamUnit->flags | 1;
  if ((pLVar3->PuzzleInstances != (EventPointers *)0x0) &&
     (iVar1 = 0, 0 < pLVar3->PuzzleInstances->numPuzzles)) {
    do {
      psVar2 = (short *)pLVar3->PuzzleInstances->eventInstances[iVar1];
      if (*psVar2 == 1) {
        if ((gameTrackerX.streamFlags & 0x400000U) != 0) {
          psVar2[3] = 1;
        }
        if (*(short *)(pLVar3->PuzzleInstances->eventInstances[iVar1] + 6) != 1) {
          return;
        }
        streamUnit->flags = streamUnit->flags | 8;
        return;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < pLVar3->PuzzleInstances->numPuzzles);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ WARPGATE_IsUnitWarpRoom(struct _StreamUnit *streamUnit /*$a0*/)
 // line 2490, offset 0x8005b604
	/* begin block 1 */
		// Start line: 2492
		// Start offset: 0x8005B604
		// Variables:
	// 		struct Level *level; // $v0
	// 		long isWarpRoom; // $a1
	// 		struct StreamUnitPortal *streamPortal; // $v1
	// 		long numPortals; // $a2
	// 		long d; // $a0
	/* end block 1 */
	// End offset: 0x8005B654
	// End Line: 2510

	/* begin block 2 */
		// Start line: 5863
	/* end block 2 */
	// End Line: 5864

	/* begin block 3 */
		// Start line: 5864
	/* end block 3 */
	// End Line: 5865

	/* begin block 4 */
		// Start line: 5869
	/* end block 4 */
	// End Line: 5870

long WARPGATE_IsUnitWarpRoom(_StreamUnit *streamUnit)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  
  iVar2 = 0;
  piVar1 = (int *)streamUnit->level->terrain->StreamUnits;
  lVar3 = 0;
  iVar4 = *piVar1;
  piVar1 = piVar1 + 1;
  if (0 < iVar4) {
    do {
      if ((*(ushort *)((int)piVar1 + 0x1e) & 1) != 0) {
        lVar3 = 1;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0x17;
    } while (iVar2 < iVar4);
  }
  return lVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_FixUnit(struct _StreamUnit *streamUnit /*$s0*/)
 // line 2513, offset 0x8005b65c
	/* begin block 1 */
		// Start line: 2514
		// Start offset: 0x8005B65C
	/* end block 1 */
	// End offset: 0x8005B680
	// End Line: 2526

	/* begin block 2 */
		// Start line: 5917
	/* end block 2 */
	// End Line: 5918

void WARPGATE_FixUnit(_StreamUnit *streamUnit)

{
  long lVar1;
  
  lVar1 = WARPGATE_IsUnitWarpRoom(streamUnit);
  if (lVar1 != 0) {
    WARPGATE_IsItActive(streamUnit);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_MarkWarpUnitsNeeded()
 // line 2529, offset 0x8005b690
	/* begin block 1 */
		// Start line: 2531
		// Start offset: 0x8005B690
		// Variables:
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x8005B6C8
	// End Line: 2540

	/* begin block 2 */
		// Start line: 5949
	/* end block 2 */
	// End Line: 5950

	/* begin block 3 */
		// Start line: 5950
	/* end block 3 */
	// End Line: 5951

	/* begin block 4 */
		// Start line: 5952
	/* end block 4 */
	// End Line: 5953

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_MarkWarpUnitsNeeded(void)

{
  STracker *pSVar1;
  int iVar2;
  
  iVar2 = 0;
  pSVar1 = &StreamTracker;
  do {
    if ((pSVar1->StreamList[0].flags & 1U) != 0) {
      pSVar1->StreamList[0].FrameCount = gameTrackerX.displayFrameCount;
    }
    iVar2 = iVar2 + 1;
    pSVar1 = (STracker *)(pSVar1->StreamList + 1);
  } while (iVar2 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ WARPGATE_IncrementIndex()
 // line 2545, offset 0x8005b6d0
	/* begin block 1 */
		// Start line: 2546
		// Start offset: 0x8005B6D0
		// Variables:
	// 		long result; // $s1
	/* end block 1 */
	// End offset: 0x8005B7D0
	// End Line: 2571

	/* begin block 2 */
		// Start line: 5985
	/* end block 2 */
	// End Line: 5986

/* WARNING: Unknown calling convention yet parameter storage is locked */

long WARPGATE_IncrementIndex(void)

{
  int iVar1;
  
  if (WarpGateLoadInfo.loading == '\x04') {
    SndPlayVolPan(0x183,0x7f,0x40,0);
    WarpGateLoadInfo.loading = '\x01';
    WarpGateLoadInfo.curTime = 0;
    (WarpGateLoadInfo.warpFaceInstance)->fadeValue = 0x1000;
    WarpGateLoadInfo.warpFaceInstance = (_Instance *)0x0;
    (&WarpRoomArray)[CurrentWarpNumber].streamUnit = (_StreamUnit *)0x0;
    CurrentWarpNumber = (CurrentWarpNumber + 1) % 0xe;
    iVar1 = strcmpi(gameTrackerX.baseAreaName,(char *)(&WarpRoomArray + CurrentWarpNumber));
    if (iVar1 == 0) {
      CurrentWarpNumber = (CurrentWarpNumber + 1) % 0xe;
    }
    hud_warp_arrow_flash = -0x2000;
  }
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_CalcWarpFade(int timeInc /*$a0*/)
 // line 2574, offset 0x8005b7e8
	/* begin block 1 */
		// Start line: 6069
	/* end block 1 */
	// End Line: 6070

	/* begin block 2 */
		// Start line: 6070
	/* end block 2 */
	// End Line: 6071

void WARPGATE_CalcWarpFade(int timeInc)

{
  int iVar1;
  
  (WarpGateLoadInfo.warpFaceInstance)->fadeValue = WarpGateLoadInfo.fadeValue;
  iVar1 = 0x1000 - ((WarpGateLoadInfo.curTime + timeInc) * 0x1000) / WarpGateLoadInfo.maxTime;
  WarpGateLoadInfo.fadeValue = (short)iVar1;
  if (0x1000 < iVar1 * 0x10000 >> 0x10) {
    WarpGateLoadInfo.fadeValue = 0x1000;
  }
  if (WarpGateLoadInfo.fadeValue < 0) {
    WarpGateLoadInfo.fadeValue = 0;
  }
  WarpGateLoadInfo.curTime = WarpGateLoadInfo.curTime + timeInc;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ WARPGATE_DecrementIndex()
 // line 2583, offset 0x8005b858
	/* begin block 1 */
		// Start line: 2584
		// Start offset: 0x8005B858
		// Variables:
	// 		long result; // $s0
	/* end block 1 */
	// End offset: 0x8005B91C
	// End Line: 2611

	/* begin block 2 */
		// Start line: 6088
	/* end block 2 */
	// End Line: 6089

/* WARNING: Unknown calling convention yet parameter storage is locked */

long WARPGATE_DecrementIndex(void)

{
  int iVar1;
  
  if (WarpGateLoadInfo.loading == '\x04') {
    SndPlayVolPan(0x183,0x7f,0x40,0);
    WarpGateLoadInfo.loading = '\x01';
    WarpGateLoadInfo.curTime = 0;
    (WarpGateLoadInfo.warpFaceInstance)->fadeValue = 0x1000;
    iVar1 = CurrentWarpNumber + -1;
    WarpGateLoadInfo.warpFaceInstance = (_Instance *)0x0;
    (&WarpRoomArray)[CurrentWarpNumber].streamUnit = (_StreamUnit *)0x0;
    CurrentWarpNumber = iVar1;
    if (iVar1 < 0) {
      CurrentWarpNumber = 0xd;
    }
    iVar1 = strcmpi(gameTrackerX.baseAreaName,(char *)(&WarpRoomArray + CurrentWarpNumber));
    if ((iVar1 == 0) && (CurrentWarpNumber = CurrentWarpNumber + -1, CurrentWarpNumber < 0)) {
      CurrentWarpNumber = 0xd;
    }
    hud_warp_arrow_flash = 0x2000;
  }
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PreloadAllConnectedUnits(struct _StreamUnit *streamUnit /*$s4*/, struct _SVector *offset /*$s5*/)
 // line 2615, offset 0x8005b930
	/* begin block 1 */
		// Start line: 2616
		// Start offset: 0x8005B930
		// Variables:
	// 		int i; // $s1
	// 		char text[16]; // stack offset -48
	// 		int numportals; // $s3
	// 		char *commapos; // $v0
	// 		struct StreamUnitPortal *stream; // $s0
	/* end block 1 */
	// End offset: 0x8005BAD0
	// End Line: 2761

	/* begin block 2 */
		// Start line: 6165
	/* end block 2 */
	// End Line: 6166

	/* begin block 3 */
		// Start line: 6173
	/* end block 3 */
	// End Line: 6174

void PreloadAllConnectedUnits(_StreamUnit *streamUnit,_SVector *offset)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int *__src;
  StreamUnitPortal *streamPortal;
  int iVar4;
  int iVar5;
  char acStack48 [16];
  
  gameTrackerX.displayFrameCount = gameTrackerX.displayFrameCount + 1;
  __src = (int *)streamUnit->level->terrain->StreamUnits;
  iVar4 = 0;
  iVar5 = *__src;
  __src = __src + 1;
  if (0 < iVar5) {
    do {
      strcpy(acStack48,(char *)__src);
      pcVar1 = strchr(acStack48,0x2c);
      if (pcVar1 != (char *)0x0) {
        *pcVar1 = '\0';
      }
      iVar2 = strcmpi(acStack48,"warpgate");
      if (iVar2 == 0) {
        STREAM_MarkWarpUnitsNeeded();
      }
      else {
        STREAM_MarkUnitNeeded(__src[5]);
      }
      iVar4 = iVar4 + 1;
      __src = __src + 0x17;
    } while (iVar4 < iVar5);
  }
  iVar4 = 0;
  STREAM_MarkUnitNeeded(streamUnit->StreamUnitID);
  STREAM_DumpAllUnitsNotNeeded();
  RelocateLevelWithInstances(streamUnit->level,offset);
  MEMPACK_DoGarbageCollection();
  iVar2 = *(int *)streamUnit->level->terrain->StreamUnits;
  iVar5 = 4;
  if (0 < iVar2) {
    do {
      streamPortal = (StreamUnitPortal *)((int)streamUnit->level->terrain->StreamUnits + iVar5);
      strcpy(acStack48,(char *)streamPortal);
      pcVar1 = strchr(acStack48,0x2c);
      if (pcVar1 != (char *)0x0) {
        *pcVar1 = '\0';
        iVar3 = strcmpi(acStack48,"warpgate");
        if (iVar3 == 0) {
          streamPortal->toStreamUnit = (_StreamUnit *)0x0;
          streamPortal->flags = streamPortal->flags | 1;
          WARPGATE_RelocateLoadedWarpRooms(streamUnit,streamPortal);
        }
        else {
          STREAM_LoadLevel(acStack48,streamPortal,1);
        }
      }
      iVar5 = iVar5 + 0x5c;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateLevel(struct Level *level /*$s0*/, struct _SVector *offset /*$s1*/)
 // line 2826, offset 0x8005baf4
	/* begin block 1 */
		// Start line: 2827
		// Start offset: 0x8005BAF4
		// Variables:
	// 		int curTree; // $t2

		/* begin block 1.1 */
			// Start line: 2850
			// Start offset: 0x8005BBC8
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $a0
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a3
		/* end block 1.1 */
		// End offset: 0x8005BBC8
		// End Line: 2852
	/* end block 1 */
	// End offset: 0x8005BC20
	// End Line: 2859

	/* begin block 2 */
		// Start line: 5652
	/* end block 2 */
	// End Line: 5653

void RelocateLevel(Level *level,_SVector *offset)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  _Terrain *p_Var5;
  int iVar6;
  
  RelocateTerrain(level->terrain,offset);
  RelocateVMObjects(level->vmobjectList,level->numVMObjects,offset);
  RelocateBGObjects(level->bgObjectList,level->numBGObjects,offset);
  RelocateCameras((_CameraKey *)level->cameraList,level->numCameras,offset);
  RelocateSavedCameras(&theCamera,level,offset);
  level->deathZ = level->deathZ + (int)offset->z;
  RelocatePlanMarkers(level->PlanMarkerList,level->NumberOfPlanMarkers,offset);
  RelocateSFXMarkers(level->SFXMarkerList,level->NumberOfSFXMarkers,offset);
  iVar4 = level->waterZLevel;
  if ((iVar4 != -0x7fff) && (iVar4 != 0x7fff)) {
    level->waterZLevel = iVar4 + offset->z;
  }
  p_Var5 = level->terrain;
  iVar4 = 0;
  if (0 < p_Var5->numBSPTrees) {
    iVar6 = 0;
    do {
      sVar1 = offset->y;
      sVar2 = offset->z;
      iVar3 = (int)&p_Var5->BSPTreeArray->bspRoot + iVar6;
      *(short *)(iVar3 + 0xc) = *(short *)(iVar3 + 0xc) + offset->x;
      *(short *)(iVar3 + 0xe) = *(short *)(iVar3 + 0xe) + sVar1;
      *(short *)(iVar3 + 0x10) = *(short *)(iVar3 + 0x10) + sVar2;
      p_Var5 = level->terrain;
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + 0x24;
    } while (iVar4 < p_Var5->numBSPTrees);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateCameras(struct _CameraKey *cameraList /*$a0*/, long numCameras /*$a1*/, struct _SVector *offset /*$a2*/)
 // line 2861, offset 0x8005bc34
	/* begin block 1 */
		// Start line: 2863
		// Start offset: 0x8005BC34
		// Variables:
	// 		int i; // $a3
	/* end block 1 */
	// End offset: 0x8005BCC0
	// End Line: 2875

	/* begin block 2 */
		// Start line: 6680
	/* end block 2 */
	// End Line: 6681

	/* begin block 3 */
		// Start line: 6681
	/* end block 3 */
	// End Line: 6682

	/* begin block 4 */
		// Start line: 6683
	/* end block 4 */
	// End Line: 6684

void RelocateCameras(_CameraKey *cameraList,long numCameras,_SVector *offset)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < numCameras) {
    do {
      cameraList->x = cameraList->x + offset->x;
      cameraList->y = cameraList->y + offset->y;
      cameraList->z = cameraList->z + offset->z;
      cameraList->tx = cameraList->tx + offset->x;
      cameraList->ty = cameraList->ty + offset->y;
      iVar1 = iVar1 + 1;
      cameraList->tz = cameraList->tz + offset->z;
      cameraList = cameraList + 1;
    } while (iVar1 < numCameras);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateSavedCameras(struct Camera *camera /*$t7*/, struct Level *level /*$t8*/, struct _SVector *offset /*$t2*/)
 // line 2877, offset 0x8005bcc8
	/* begin block 1 */
		// Start line: 2878
		// Start offset: 0x8005BCC8
		// Variables:
	// 		int i; // $t6

		/* begin block 1.1 */
			// Start line: 2888
			// Start offset: 0x8005BD10
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $v1
		// 		short _y1; // $a1
		// 		short _z1; // $a2
		// 		struct _Position *_v; // $a0
		/* end block 1.1 */
		// End offset: 0x8005BD10
		// End Line: 2890

		/* begin block 1.2 */
			// Start line: 2890
			// Start offset: 0x8005BD10
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a3
		/* end block 1.2 */
		// End offset: 0x8005BD10
		// End Line: 2890

		/* begin block 1.3 */
			// Start line: 2890
			// Start offset: 0x8005BD10
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a3
		/* end block 1.3 */
		// End offset: 0x8005BD10
		// End Line: 2890

		/* begin block 1.4 */
			// Start line: 2890
			// Start offset: 0x8005BD10
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a3
		/* end block 1.4 */
		// End offset: 0x8005BDDC
		// End Line: 2899
	/* end block 1 */
	// End offset: 0x8005BDF8
	// End Line: 2906

	/* begin block 2 */
		// Start line: 6728
	/* end block 2 */
	// End Line: 6729

void RelocateSavedCameras(Camera *camera,Level *level,_SVector *offset)

{
  short sVar1;
  short sVar2;
  short *psVar3;
  Camera *pCVar4;
  Camera *pCVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  if (-1 < camera->stack) {
    iVar6 = 0x2a0;
    pCVar4 = camera;
    pCVar5 = camera;
    do {
      if ((pCVar4->savedMode[0] == 5) &&
         (psVar3 = (short *)((int)&(camera->core).position.x + iVar6),
         pCVar5->savedCinematic[0].level == level)) {
        sVar1 = offset->y;
        sVar2 = offset->z;
        *psVar3 = *psVar3 + offset->x;
        psVar3[1] = psVar3[1] + sVar1;
        psVar3[2] = psVar3[2] + sVar2;
        sVar1 = offset->y;
        sVar2 = offset->z;
        psVar3[3] = psVar3[3] + offset->x;
        psVar3[4] = psVar3[4] + sVar1;
        psVar3[5] = psVar3[5] + sVar2;
        sVar1 = offset->y;
        sVar2 = offset->z;
        psVar3[9] = psVar3[9] + offset->x;
        psVar3[10] = psVar3[10] + sVar1;
        psVar3[0xb] = psVar3[0xb] + sVar2;
        sVar1 = offset->y;
        sVar2 = offset->z;
        psVar3[0xc] = psVar3[0xc] + offset->x;
        psVar3[0xd] = psVar3[0xd] + sVar1;
        psVar3[0xe] = psVar3[0xe] + sVar2;
      }
      iVar6 = iVar6 + 0x70;
      pCVar5 = (Camera *)&(pCVar5->core).wcTransform2;
      iVar7 = iVar7 + 1;
      pCVar4 = (Camera *)&(pCVar4->core).position.z;
    } while (iVar7 <= camera->stack);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateLevelWithInstances(struct Level *level /*$a0*/, struct _SVector *offset /*$s0*/)
 // line 2908, offset 0x8005be00
	/* begin block 1 */
		// Start line: 6813
	/* end block 1 */
	// End Line: 6814

void RelocateLevelWithInstances(Level *level,_SVector *offset)

{
  RelocateLevel(level,offset);
  RelocateInstances(offset);
  RelocatePlanPool((PlanningNode *)gameTrackerX.planningPool,offset);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateTerrain(struct _Terrain *terrain /*$s2*/, struct _SVector *offset /*$s3*/)
 // line 2919, offset 0x8005be38
	/* begin block 1 */
		// Start line: 2920
		// Start offset: 0x8005BE38
		// Variables:
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x8005BEF8
	// End Line: 3047

	/* begin block 2 */
		// Start line: 6835
	/* end block 2 */
	// End Line: 6836

void RelocateTerrain(_Terrain *terrain,_SVector *offset)

{
  char *pcVar1;
  MultiSpline *multi;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < terrain->numIntros) {
    iVar2 = 0;
    do {
      pcVar1 = terrain->introList->name + iVar2;
      *(short *)(pcVar1 + 0x20) = *(short *)(pcVar1 + 0x20) + offset->x;
      pcVar1 = terrain->introList->name + iVar2;
      *(short *)(pcVar1 + 0x22) = *(short *)(pcVar1 + 0x22) + offset->y;
      pcVar1 = terrain->introList->name + iVar2;
      *(short *)(pcVar1 + 0x24) = *(short *)(pcVar1 + 0x24) + offset->z;
      multi = *(MultiSpline **)((int)&terrain->introList->multiSpline + iVar2);
      if (multi != (MultiSpline *)0x0) {
        STREAM_AdjustMultiSpline(multi,offset);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x4c;
    } while (iVar3 < terrain->numIntros);
  }
  RelocateStreamPortals
            ((StreamUnitPortal *)(terrain->StreamUnits + 1),*(int *)terrain->StreamUnits,offset);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateVMObjects(struct _VMObject *vobjectlist /*$a0*/, long numvmobjs /*$a1*/, struct _SVector *offset /*$a2*/)
 // line 3053, offset 0x8005bf28
	/* begin block 1 */
		// Start line: 3055
		// Start offset: 0x8005BF28
		// Variables:
	// 		int i; // $a3
	/* end block 1 */
	// End offset: 0x8005BF78
	// End Line: 3077

	/* begin block 2 */
		// Start line: 7112
	/* end block 2 */
	// End Line: 7113

	/* begin block 3 */
		// Start line: 7113
	/* end block 3 */
	// End Line: 7114

	/* begin block 4 */
		// Start line: 7116
	/* end block 4 */
	// End Line: 7117

void RelocateVMObjects(_VMObject *vobjectlist,long numvmobjs,_SVector *offset)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < numvmobjs) {
    do {
      (vobjectlist->position).x = (vobjectlist->position).x + offset->x;
      (vobjectlist->position).y = (vobjectlist->position).y + offset->y;
      iVar1 = iVar1 + 1;
      (vobjectlist->position).z = (vobjectlist->position).z + offset->z;
      vobjectlist = vobjectlist + 1;
    } while (iVar1 < numvmobjs);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateBGObjects(struct _BGObject *BGObjList /*$a0*/, long numBGObjs /*$t2*/, struct _SVector *offset /*$a2*/)
 // line 3108, offset 0x8005bf80
	/* begin block 1 */
		// Start line: 3109
		// Start offset: 0x8005BF80
		// Variables:
	// 		int i; // $t1
	// 		int d; // $a3
	/* end block 1 */
	// End offset: 0x8005C01C
	// End Line: 3121

	/* begin block 2 */
		// Start line: 6216
	/* end block 2 */
	// End Line: 6217

void RelocateBGObjects(_BGObject *BGObjList,long numBGObjs,_SVector *offset)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  if (0 < numBGObjs) {
    do {
      iVar4 = 0;
      if (0 < BGObjList->numVertices) {
        iVar3 = 0;
        do {
          psVar1 = (short *)((int)&BGObjList->vertexList->x + iVar3);
          *psVar1 = *psVar1 + offset->x;
          iVar2 = (int)&BGObjList->vertexList->x + iVar3;
          *(short *)(iVar2 + 2) = *(short *)(iVar2 + 2) + offset->y;
          iVar3 = (int)&BGObjList->vertexList->x + iVar3;
          *(short *)(iVar3 + 4) = *(short *)(iVar3 + 4) + offset->z;
          iVar4 = iVar4 + 1;
          iVar3 = iVar4 * 8;
        } while (iVar4 < BGObjList->numVertices);
      }
      iVar5 = iVar5 + 1;
      BGObjList = BGObjList + 1;
    } while (iVar5 < numBGObjs);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocatePlanPool(struct PlanningNode *planPool /*$s0*/, struct _SVector *offset /*$a1*/)
 // line 3123, offset 0x8005c024
	/* begin block 1 */
		// Start line: 3124
		// Start offset: 0x8005C024
		// Variables:
	// 		int i; // $a1
	// 		short ox; // $s1
	// 		short oy; // $s2
	// 		short oz; // $s3
	/* end block 1 */
	// End offset: 0x8005C090
	// End Line: 3139

	/* begin block 2 */
		// Start line: 7234
	/* end block 2 */
	// End Line: 7235

void RelocatePlanPool(PlanningNode *planPool,_SVector *offset)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  
  sVar1 = offset->x;
  sVar2 = offset->y;
  sVar3 = offset->z;
  iVar5 = PLANAPI_NumNodesInPool(planPool);
  psVar6 = &(planPool->pos).z;
  iVar4 = poolManagementData;
  while (poolManagementData = iVar4, iVar5 != 0) {
    iVar5 = iVar5 + -1;
    (planPool->pos).x = (planPool->pos).x + sVar1;
    planPool = planPool + 1;
    psVar6[-1] = psVar6[-1] + sVar2;
    *psVar6 = *psVar6 + sVar3;
    psVar6 = psVar6 + 0xe;
    iVar4 = poolManagementData;
  }
  *(short *)(iVar4 + 2) = *(short *)(iVar4 + 2) + sVar1;
  *(short *)(iVar4 + 6) = *(short *)(iVar4 + 6) + sVar3;
  *(short *)(iVar4 + 4) = *(short *)(iVar4 + 4) + sVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocatePlanMarkers(struct _PlanMkr *planMkrList /*$a3*/, int numPlanMkrs /*$a1*/, struct _SVector *offset /*$a2*/)
 // line 3144, offset 0x8005c0d8
	/* begin block 1 */
		// Start line: 3145
		// Start offset: 0x8005C0D8
		// Variables:
	// 		int i; // $a1
	// 		short ox; // $t1
	// 		short oy; // $t0
	// 		short oz; // $a2
	/* end block 1 */
	// End offset: 0x8005C124
	// End Line: 3159

	/* begin block 2 */
		// Start line: 7289
	/* end block 2 */
	// End Line: 7290

	/* begin block 3 */
		// Start line: 7293
	/* end block 3 */
	// End Line: 7294

void RelocatePlanMarkers(_PlanMkr *planMkrList,int numPlanMkrs,_SVector *offset)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short *psVar4;
  
  sVar1 = offset->x;
  sVar2 = offset->y;
  sVar3 = offset->z;
  if (numPlanMkrs != 0) {
    psVar4 = &(planMkrList->pos).z;
    do {
      numPlanMkrs = numPlanMkrs + -1;
      (planMkrList->pos).x = (planMkrList->pos).x + sVar1;
      planMkrList = planMkrList + 1;
      psVar4[-1] = psVar4[-1] + sVar2;
      *psVar4 = *psVar4 + sVar3;
      psVar4 = psVar4 + 4;
    } while (numPlanMkrs != 0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateSFXMarkers(struct _SFXMkr *sfxMkrList /*$a0*/, int numSFXMkrs /*$a1*/, struct _SVector *offset /*$a2*/)
 // line 3161, offset 0x8005c12c
	/* begin block 1 */
		// Start line: 3163
		// Start offset: 0x8005C12C
		// Variables:
	// 		int i; // $a1
	// 		short ox; // $t0
	// 		short oy; // $a3
	// 		short oz; // $a2
	/* end block 1 */
	// End offset: 0x8005C170
	// End Line: 3176

	/* begin block 2 */
		// Start line: 7333
	/* end block 2 */
	// End Line: 7334

	/* begin block 3 */
		// Start line: 7334
	/* end block 3 */
	// End Line: 7335

	/* begin block 4 */
		// Start line: 7337
	/* end block 4 */
	// End Line: 7338

void RelocateSFXMarkers(_SFXMkr *sfxMkrList,int numSFXMkrs,_SVector *offset)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short *psVar4;
  
  sVar1 = offset->x;
  sVar2 = offset->y;
  sVar3 = offset->z;
  psVar4 = &(sfxMkrList->pos).z;
  if (numSFXMkrs != 0) {
    do {
      numSFXMkrs = numSFXMkrs + -1;
      psVar4[-2] = psVar4[-2] + sVar1;
      *psVar4 = *psVar4 + sVar3;
      psVar4[-1] = psVar4[-1] + sVar2;
      psVar4 = psVar4 + 0x12;
    } while (numSFXMkrs != 0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_AdjustMultiSpline(struct MultiSpline *multi /*$a3*/, struct _SVector *offset /*$t0*/)
 // line 3178, offset 0x8005c178
	/* begin block 1 */
		// Start line: 3179
		// Start offset: 0x8005C178
		// Variables:
	// 		int i; // $a2
	/* end block 1 */
	// End offset: 0x8005C220
	// End Line: 3200

	/* begin block 2 */
		// Start line: 7373
	/* end block 2 */
	// End Line: 7374

void STREAM_AdjustMultiSpline(MultiSpline *multi,_SVector *offset)

{
  Spline *pSVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  pSVar1 = multi->positional;
  if ((pSVar1 != (Spline *)0x0) && (iVar4 = 0, 0 < pSVar1->numkeys)) {
    iVar3 = 0;
    do {
      iVar2 = (int)&pSVar1->key->count + iVar3;
      *(short *)(iVar2 + 2) = *(short *)(iVar2 + 2) + offset->x;
      iVar2 = (int)&multi->positional->key->count + iVar3;
      *(short *)(iVar2 + 4) = *(short *)(iVar2 + 4) + offset->y;
      iVar3 = (int)&multi->positional->key->count + iVar3;
      *(short *)(iVar3 + 6) = *(short *)(iVar3 + 6) + offset->z;
      pSVar1 = multi->positional;
      iVar4 = iVar4 + 1;
      iVar3 = iVar4 * 0x20;
    } while (iVar4 < pSVar1->numkeys);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_RelocateInstance(struct _Instance *instance /*$s0*/, struct _SVector *offset /*$s1*/)
 // line 3202, offset 0x8005c228
	/* begin block 1 */
		// Start line: 7425
	/* end block 1 */
	// End Line: 7426

void STREAM_RelocateInstance(_Instance *instance,_SVector *offset)

{
  STREAM_OffsetInstancePosition(instance,offset,1);
  INSTANCE_Post(instance,(int)&DAT_00100008,(int)offset);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_OffsetInstancePosition(struct _Instance *instance /*$s0*/, struct _SVector *offset /*$s1*/, int streamSignalFlag /*$s2*/)
 // line 3210, offset 0x8005c270
	/* begin block 1 */
		// Start line: 7441
	/* end block 1 */
	// End Line: 7442

void STREAM_OffsetInstancePosition(_Instance *instance,_SVector *offset,int streamSignalFlag)

{
  (instance->position).x = (instance->position).x + offset->x;
  (instance->position).y = (instance->position).y + offset->y;
  (instance->position).z = (instance->position).z + offset->z;
  (instance->oldPos).x = (instance->oldPos).x + offset->x;
  (instance->oldPos).y = (instance->oldPos).y + offset->y;
  (instance->oldPos).z = (instance->oldPos).z + offset->z;
  (instance->shadowPosition).x = (instance->shadowPosition).x + offset->x;
  (instance->shadowPosition).y = (instance->shadowPosition).y + offset->y;
  (instance->shadowPosition).z = (instance->shadowPosition).z + offset->z;
  COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)offset);
  COLLIDE_MoveAllTransforms(instance,(_Position *)offset);
  if (instance == theCamera.focusInstance) {
    CAMERA_Relocate(&theCamera,offset,streamSignalFlag);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_SetInstancePosition(struct _Instance *instance /*$a0*/, struct evPositionData *data /*$a1*/)
 // line 3237, offset 0x8005c388
	/* begin block 1 */
		// Start line: 3238
		// Start offset: 0x8005C388
		// Variables:
	// 		struct _SVector offset; // stack offset -16
	/* end block 1 */
	// End offset: 0x8005C388
	// End Line: 3238

	/* begin block 2 */
		// Start line: 7504
	/* end block 2 */
	// End Line: 7505

void STREAM_SetInstancePosition(_Instance *instance,evPositionData *data)

{
  _SVector local_10;
  
  local_10.x = data->x - (instance->position).x;
  local_10.y = data->y - (instance->position).y;
  local_10.z = data->z - (instance->position).z;
  STREAM_OffsetInstancePosition(instance,&local_10,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateInstances(struct _SVector *offset /*$s1*/)
 // line 3248, offset 0x8005c3e0
	/* begin block 1 */
		// Start line: 3249
		// Start offset: 0x8005C3E0
		// Variables:
	// 		struct _Instance *instance; // $s0
	/* end block 1 */
	// End offset: 0x8005C420
	// End Line: 3259

	/* begin block 2 */
		// Start line: 7531
	/* end block 2 */
	// End Line: 7532

	/* begin block 3 */
		// Start line: 7532
	/* end block 3 */
	// End Line: 7533

void RelocateInstances(_SVector *offset)

{
  _Instance *instance;
  
  instance = (gameTrackerX.instanceList)->first;
  while (instance != (_Instance *)0x0) {
    STREAM_RelocateInstance(instance,offset);
    instance = instance->next;
  }
  FX_Relocate(offset);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateStreamPortals(struct StreamUnitPortal *StreamUnitList /*$a0*/, int NumStreamUnits /*$a1*/, struct _SVector *offset /*$a2*/)
 // line 3262, offset 0x8005c43c
	/* begin block 1 */
		// Start line: 3264
		// Start offset: 0x8005C43C
		// Variables:
	// 		int i; // $t1
	// 		int d; // $t0
	/* end block 1 */
	// End offset: 0x8005C564
	// End Line: 3289

	/* begin block 2 */
		// Start line: 7561
	/* end block 2 */
	// End Line: 7562

	/* begin block 3 */
		// Start line: 7562
	/* end block 3 */
	// End Line: 7563

	/* begin block 4 */
		// Start line: 7564
	/* end block 4 */
	// End Line: 7565

void RelocateStreamPortals(StreamUnitPortal *StreamUnitList,int NumStreamUnits,_SVector *offset)

{
  StreamUnitPortal *pSVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < NumStreamUnits) {
    do {
      StreamUnitList->maxx = StreamUnitList->maxx + offset->x;
      StreamUnitList->maxy = StreamUnitList->maxy + offset->y;
      StreamUnitList->maxz = StreamUnitList->maxz + offset->z;
      StreamUnitList->minx = StreamUnitList->minx + offset->x;
      iVar2 = 0;
      StreamUnitList->miny = StreamUnitList->miny + offset->y;
      StreamUnitList->minz = StreamUnitList->minz + offset->z;
      pSVar1 = StreamUnitList;
      do {
        pSVar1->t1[0].x = pSVar1->t1[0].x + offset->x;
        pSVar1->t1[0].y = pSVar1->t1[0].y + offset->y;
        iVar2 = iVar2 + 1;
        pSVar1->t1[0].z = pSVar1->t1[0].z + offset->z;
        pSVar1 = (StreamUnitPortal *)(pSVar1->tolevelname + 8);
      } while (iVar2 < 3);
      iVar2 = 0;
      pSVar1 = StreamUnitList;
      do {
        pSVar1->t2[0].x = pSVar1->t2[0].x + offset->x;
        pSVar1->t2[0].y = pSVar1->t2[0].y + offset->y;
        iVar2 = iVar2 + 1;
        pSVar1->t2[0].z = pSVar1->t2[0].z + offset->z;
        pSVar1 = (StreamUnitPortal *)(pSVar1->tolevelname + 8);
      } while (iVar2 < 3);
      iVar3 = iVar3 + 1;
      StreamUnitList = StreamUnitList + 1;
    } while (iVar3 < NumStreamUnits);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_PackVRAMObject(struct _ObjectTracker *objectTracker /*$s1*/)
 // line 3299, offset 0x8005c56c
	/* begin block 1 */
		// Start line: 3300
		// Start offset: 0x8005C56C
		// Variables:
	// 		struct VramSize *vramSize; // $a0

		/* begin block 1.1 */
			// Start line: 3309
			// Start offset: 0x8005C59C
			// Variables:
		// 		struct VramBuffer *vramBuffer; // $v0

			/* begin block 1.1.1 */
				// Start line: 3317
				// Start offset: 0x8005C5AC
				// Variables:
			// 		char fileName[64]; // stack offset -80
			// 		struct _BlockVramEntry *vramBlock; // $s0
			/* end block 1.1.1 */
			// End offset: 0x8005C5D4
			// End Line: 3327
		/* end block 1.1 */
		// End offset: 0x8005C654
		// End Line: 3346
	/* end block 1 */
	// End offset: 0x8005C658
	// End Line: 3354

	/* begin block 2 */
		// Start line: 7672
	/* end block 2 */
	// End Line: 7673

void STREAM_PackVRAMObject(_ObjectTracker *objectTracker)

{
  undefined2 uVar1;
  long lVar2;
  undefined4 *retData;
  void *pvVar3;
  char acStack80 [64];
  
  if (((objectTracker->object->vramSize).x == -1) ||
     (lVar2 = VRAM_GetObjectVramSpace(&objectTracker->object->vramSize,objectTracker), lVar2 == 0))
  {
    objectTracker->vramBlock = (void *)0x0;
  }
  else {
    pvVar3 = objectTracker->vramBlock;
    if (pvVar3 != (void *)0x0) {
      AdjustVramCoordsObject
                (0x200,0,(int)*(short *)((int)pvVar3 + 0xc),(int)*(short *)((int)pvVar3 + 0xe),
                 objectTracker->object);
    }
    sprintf(acStack80,"\\kain2\\object\\%s\\%s.crm");
    retData = (undefined4 *)MEMPACK_Malloc((int)*(short *)((int)pvVar3 + 0x10) * 2 + 0x14,'#');
    *(undefined4 **)(retData + 4) = retData + 5;
    *retData = 0;
    *(undefined2 *)(retData + 1) = *(undefined2 *)((int)pvVar3 + 0xc);
    *(undefined2 *)((int)retData + 6) = *(undefined2 *)((int)pvVar3 + 0xe);
    *(undefined2 *)(retData + 2) = *(undefined2 *)((int)pvVar3 + 0x10);
    uVar1 = *(undefined2 *)((int)pvVar3 + 0x12);
    *(undefined2 *)(retData + 3) = 0;
    *(undefined2 *)((int)retData + 0xe) = 0;
    *(undefined2 *)((int)retData + 10) = uVar1;
    LOAD_NonBlockingBufferedLoad(acStack80,VRAM_TransferBufferToVram,retData,objectTracker);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_SetupInstanceFlags(struct _Instance *instance /*$s0*/)
 // line 3383, offset 0x8005c66c
	/* begin block 1 */
		// Start line: 7873
	/* end block 1 */
	// End Line: 7874

void MORPH_SetupInstanceFlags(_Instance *instance)

{
  long lVar1;
  uint uVar2;
  
  if ((instance->object->oflags & 0x80000U) != 0) {
    return;
  }
  if (gameTrackerX.gameData.asmData.MorphType == 0) {
    uVar2 = instance->flags2;
    if ((uVar2 & 0x8000000) == 0) {
      uVar2 = uVar2 & 0xebffffff;
      goto LAB_8005c780;
    }
  }
  else {
    uVar2 = instance->flags2;
    if ((uVar2 & 0x8000000) != 0) {
      uVar2 = uVar2 & 0xebffffff;
      goto LAB_8005c780;
    }
  }
  instance->flags2 = uVar2 | 0x10000000;
  lVar1 = MEMPACK_MemoryValidFunc((char *)instance->object);
  if (lVar1 == 0) {
    return;
  }
  if ((instance->object->oflags2 & 0x2000000U) == 0) {
    if (instance->LinkParent == (_Instance *)0x0) {
      return;
    }
    if ((instance->LinkParent->object->oflags2 & 0x2000000U) == 0) {
      return;
    }
  }
  INSTANCE_Post(instance,(int)&DAT_00040026,0);
  uVar2 = instance->flags2 | 0x4000000;
LAB_8005c780:
  instance->flags2 = uVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_SetupInstanceListFlags()
 // line 3432, offset 0x8005c794
	/* begin block 1 */
		// Start line: 3433
		// Start offset: 0x8005C794
		// Variables:
	// 		struct _Instance *instance; // $s0
	/* end block 1 */
	// End offset: 0x8005C7CC
	// End Line: 3444

	/* begin block 2 */
		// Start line: 7974
	/* end block 2 */
	// End Line: 7975

	/* begin block 3 */
		// Start line: 7979
	/* end block 3 */
	// End Line: 7980

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MORPH_SetupInstanceListFlags(void)

{
  _Instance *instance;
  
  instance = (gameTrackerX.instanceList)->first;
  while (instance != (_Instance *)0x0) {
    MORPH_SetupInstanceFlags(instance);
    instance = instance->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_InMorphInstanceListFlags()
 // line 3446, offset 0x8005c7dc
	/* begin block 1 */
		// Start line: 3448
		// Start offset: 0x8005C7DC
		// Variables:
	// 		struct _Instance *instance; // $v1
	/* end block 1 */
	// End offset: 0x8005C83C
	// End Line: 3471

	/* begin block 2 */
		// Start line: 8007
	/* end block 2 */
	// End Line: 8008

	/* begin block 3 */
		// Start line: 8008
	/* end block 3 */
	// End Line: 8009

	/* begin block 4 */
		// Start line: 8012
	/* end block 4 */
	// End Line: 8013

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MORPH_InMorphInstanceListFlags(void)

{
  _Instance *p_Var1;
  
  p_Var1 = (gameTrackerX.instanceList)->first;
  while (p_Var1 != (_Instance *)0x0) {
    if ((p_Var1->flags2 & 0x4000000U) != 0) {
      p_Var1->flags2 = p_Var1->flags2 & 0xefffffff;
    }
    p_Var1->flags2 = p_Var1->flags2 & 0xfbffffff;
    p_Var1 = p_Var1->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_InMorphDoFadeValues()
 // line 3473, offset 0x8005c844
	/* begin block 1 */
		// Start line: 3475
		// Start offset: 0x8005C844
		// Variables:
	// 		int fade1; // $a0
	// 		int fade2; // $v0
	/* end block 1 */
	// End offset: 0x8005C894
	// End Line: 3489

	/* begin block 2 */
		// Start line: 8061
	/* end block 2 */
	// End Line: 8062

	/* begin block 3 */
		// Start line: 8062
	/* end block 3 */
	// End Line: 8063

	/* begin block 4 */
		// Start line: 8064
	/* end block 4 */
	// End Line: 8065

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MORPH_InMorphDoFadeValues(void)

{
  gameTrackerX.material_fadeValue =
       (short)(((int)gameTrackerX.gameData.asmData.MorphTime << 0xc) / 1000);
  if (gameTrackerX.gameData.asmData.MorphType == 0) {
    gameTrackerX.spectral_fadeValue = gameTrackerX.material_fadeValue;
    gameTrackerX.material_fadeValue = 0x1000 - gameTrackerX.material_fadeValue;
    return;
  }
  gameTrackerX.spectral_fadeValue = 0x1000 - gameTrackerX.material_fadeValue;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_UpdateTimeMult()
 // line 3495, offset 0x8005c89c
	/* begin block 1 */
		// Start line: 3498
		// Start offset: 0x8005C89C

		/* begin block 1.1 */
			// Start line: 3501
			// Start offset: 0x8005C8B0
			// Variables:
		// 		short ratio; // $v1
		/* end block 1.1 */
		// End offset: 0x8005C9CC
		// End Line: 3539
	/* end block 1 */
	// End offset: 0x8005CA08
	// End Line: 3555

	/* begin block 2 */
		// Start line: 8105
	/* end block 2 */
	// End Line: 8106

	/* begin block 3 */
		// Start line: 8107
	/* end block 3 */
	// End Line: 8108

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MORPH_UpdateTimeMult(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)(ushort)gameTrackerX.gameData.asmData.MorphTime;
  if (gameTrackerX.gameData.asmData.MorphTime != 1000) {
    iVar1 = uVar2 - 0x2ee;
    if (gameTrackerX.gameData.asmData.MorphType == 0) {
      if (0xfa < gameTrackerX.gameData.asmData.MorphTime) {
        uVar2 = 0xfa;
      }
      iVar1 = 0xfa - uVar2;
    }
    else {
      if (iVar1 * 0x10000 < 0) {
        iVar1 = 0;
      }
    }
    gameTrackerX.materialTimeMult =
         (int)(gameTrackerX.globalTimeMult * ((((iVar1 << 0x10) >> 4) / 0xfa) * 0x10000 >> 0x10) *
              0x10) >> 0x10;
    if (gameTrackerX.materialTimeMult == 0) {
      gameTrackerX.materialTimeMult = 1;
    }
    uVar2 = (uint)(ushort)gameTrackerX.gameData.asmData.MorphTime;
    if (gameTrackerX.gameData.asmData.MorphType == 0) {
      iVar1 = uVar2 - 0x2ee;
      if (iVar1 * 0x10000 < 0) {
        iVar1 = 0;
      }
    }
    else {
      if (0xfa < gameTrackerX.gameData.asmData.MorphTime) {
        uVar2 = 0xfa;
      }
      iVar1 = 0xfa - uVar2;
    }
    gameTrackerX.spectralTimeMult =
         (int)(gameTrackerX.globalTimeMult * ((((iVar1 << 0x10) >> 4) / 0xfa) * 0x10000 >> 0x10) *
              0x10) >> 0x10;
    if (gameTrackerX.spectralTimeMult == 0) {
      gameTrackerX.spectralTimeMult = 1;
    }
    return;
  }
  if (gameTrackerX.gameData.asmData.MorphType == 0) {
    gameTrackerX.spectralTimeMult = 0;
    gameTrackerX.materialTimeMult = gameTrackerX.globalTimeMult;
    return;
  }
  gameTrackerX.spectralTimeMult = gameTrackerX.globalTimeMult;
  gameTrackerX.materialTimeMult = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_UpdateNormals(struct Level *BaseLevel /*$t0*/)
 // line 3559, offset 0x8005ca10
	/* begin block 1 */
		// Start line: 3560
		// Start offset: 0x8005CA10
		// Variables:
	// 		struct _TFace *face; // $v1
	// 		long faceCount; // $a2
	// 		struct _TVertex *v; // $a1
	// 		struct _MorphVertex *mv; // $a3
	// 		struct _MorphColor *mc; // $a0
	// 		short h1; // $v1
	// 		short *morphNormals; // $a1

		/* begin block 1.1 */
			// Start line: 3609
			// Start offset: 0x8005CB0C
			// Variables:
		// 		struct _TVertex *endv; // $a2
		/* end block 1.1 */
		// End offset: 0x8005CB80
		// End Line: 3630

		/* begin block 1.2 */
			// Start line: 3630
			// Start offset: 0x8005CB80
			// Variables:
		// 		struct _BSPNode *node; // $v1
		// 		struct _BSPLeaf *leaf; // $a1
		// 		struct _Sphere_noSq hsphere; // stack offset -32
		// 		struct _BoundingBox hbox; // stack offset -24
		// 		struct _Terrain *terrain; // $a0
		// 		long curTree; // $t0
		/* end block 1.2 */
		// End offset: 0x8005CD94
		// End Line: 3681

		/* begin block 1.3 */
			// Start line: 3683
			// Start offset: 0x8005CD94
			// Variables:
		// 		struct _Instance *instance; // $s0

			/* begin block 1.3.1 */
				// Start line: 3689
				// Start offset: 0x8005CDBC
				// Variables:
			// 		struct SVECTOR realDiff; // stack offset -32
			// 		struct _Position oldPos; // stack offset -24
			/* end block 1.3.1 */
			// End offset: 0x8005CEA4
			// End Line: 3713
		/* end block 1.3 */
		// End offset: 0x8005CEB4
		// End Line: 3716
	/* end block 1 */
	// End offset: 0x8005CEB4
	// End Line: 3717

	/* begin block 2 */
		// Start line: 8237
	/* end block 2 */
	// End Line: 8238

void MORPH_UpdateNormals(Level *BaseLevel)

{
  short *psVar1;
  short *psVar2;
  ushort uVar3;
  short sVar4;
  _Terrain *p_Var5;
  _TVertex *p_Var6;
  uint *puVar7;
  int iVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  uint uVar11;
  ushort *puVar12;
  _MorphColor *p_Var13;
  Intro *pIVar14;
  ushort *puVar15;
  undefined4 *puVar16;
  uint uVar17;
  int iVar18;
  short *psVar19;
  _TVertex *p_Var20;
  int iVar21;
  _MorphVertex *p_Var22;
  undefined4 uVar23;
  undefined4 uVar24;
  _Instance *instance;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  undefined4 local_10;
  
  p_Var5 = BaseLevel->terrain;
  puVar15 = (ushort *)p_Var5->morphNormalIdx;
  iVar18 = p_Var5->numFaces;
  if (0 < iVar18) {
    puVar12 = &p_Var5->faceList->normal;
    do {
      uVar3 = *puVar12;
      iVar18 = iVar18 + -1;
      *puVar12 = *puVar15;
      *puVar15 = uVar3;
      puVar15 = puVar15 + 1;
      puVar12 = puVar12 + 6;
    } while (0 < iVar18);
    p_Var5 = BaseLevel->terrain;
  }
  p_Var22 = p_Var5->MorphDiffList;
  if ((p_Var22 != (_MorphVertex *)0x0) && (sVar4 = p_Var22->vindex, -1 < p_Var22->vindex)) {
    psVar19 = &p_Var22->vindex;
    do {
      p_Var6 = BaseLevel->terrain->vertexList + sVar4;
      (p_Var6->vertex).x = psVar19[1] + p_Var22->x;
      (p_Var6->vertex).y = psVar19[2] + psVar19[-2];
      psVar1 = psVar19 + 3;
      psVar2 = psVar19 + -1;
      psVar19 = psVar19 + 7;
      (p_Var6->vertex).z = *psVar1 + *psVar2;
      sVar4 = *psVar19;
      p_Var22 = p_Var22 + 1;
    } while (-1 < *psVar19);
  }
  p_Var5 = BaseLevel->terrain;
  p_Var13 = p_Var5->MorphColorList;
  if (p_Var13 != (_MorphColor *)0x0) {
    p_Var6 = p_Var5->vertexList;
    p_Var20 = p_Var6 + p_Var5->numVertices;
    if (p_Var6 < p_Var20) {
      pbVar9 = &p_Var6->b0;
      do {
        pbVar9[-2] = (byte)(((uint)*(byte *)&p_Var13->morphColor15 & 0x1f) << 3);
        p_Var6 = p_Var6 + 1;
        pbVar9[-1] = (byte)((ushort)p_Var13->morphColor15 >> 2) & 0xf8;
        puVar15 = (ushort *)&p_Var13->morphColor15;
        p_Var13 = p_Var13 + 1;
        *pbVar9 = (byte)(*puVar15 >> 7) & 0xf8;
        pbVar9 = pbVar9 + 0xc;
      } while (p_Var6 < p_Var20);
    }
  }
  p_Var5 = BaseLevel->terrain;
  iVar18 = 0;
  if (0 < p_Var5->numBSPTrees) {
    iVar21 = 0;
    do {
      puVar7 = (uint *)((int)&p_Var5->BSPTreeArray->bspRoot + iVar21);
      puVar16 = (undefined4 *)*puVar7;
      puVar10 = puVar16 + 7;
      if (puVar16 < (undefined4 *)puVar7[1]) {
        do {
          uVar23 = *puVar16;
          local_1c = puVar16[1];
          uVar24 = puVar10[1];
          *puVar16 = *puVar10;
          puVar16[1] = uVar24;
          *puVar10 = uVar23;
          puVar10[1] = local_1c;
          puVar16 = puVar16 + 0xb;
          puVar10 = puVar10 + 0xb;
        } while (puVar16 < *(undefined4 **)((int)&p_Var5->BSPTreeArray->startLeaves + iVar21));
      }
      iVar8 = (int)&p_Var5->BSPTreeArray->bspRoot + iVar21;
      puVar16 = *(undefined4 **)(iVar8 + 4);
      if (puVar16 < *(undefined4 **)(iVar8 + 8)) {
        puVar10 = puVar16 + 7;
        do {
          uVar23 = *puVar16;
          local_1c = puVar16[1];
          uVar24 = puVar10[4];
          *puVar16 = puVar10[3];
          puVar16[1] = uVar24;
          puVar10[3] = uVar23;
          puVar10[4] = local_1c;
          uVar23 = puVar10[-3];
          local_14 = puVar10[-2];
          local_10 = puVar10[-1];
          puVar10[-3] = *puVar10;
          puVar10[-2] = puVar10[1];
          puVar10[-1] = puVar10[2];
          *puVar10 = uVar23;
          puVar10[1] = local_14;
          puVar10[2] = local_10;
          puVar16 = puVar16 + 0xc;
          puVar10 = puVar10 + 0xc;
        } while (puVar16 < *(undefined4 **)((int)&p_Var5->BSPTreeArray->endLeaves + iVar21));
      }
      iVar18 = iVar18 + 1;
      iVar21 = iVar21 + 0x24;
    } while (iVar18 < p_Var5->numBSPTrees);
  }
  instance = (gameTrackerX.instanceList)->first;
  while (instance != (_Instance *)0x0) {
    pIVar14 = instance->intro;
    if ((pIVar14 != (Intro *)0x0) &&
       (((*(int *)&pIVar14->spectralPosition != 0 || ((pIVar14->spectralPosition).z != 0)) &&
        ((instance->flags2 & 8U) == 0)))) {
      local_18 = *(uint *)&instance->position;
      uVar11 = (uint)(ushort)(instance->position).z;
      local_14 = local_14 & 0xffff0000 | uVar11;
      (instance->position).x = (pIVar14->position).x + (pIVar14->spectralPosition).x;
      (instance->position).y = (pIVar14->position).y + (pIVar14->spectralPosition).y;
      (instance->position).z = (pIVar14->position).z + (pIVar14->spectralPosition).z;
      uVar17 = (uint)(ushort)(instance->position).x - (local_18 & 0xffff);
      iVar18 = (uint)(ushort)(instance->position).y - (local_18 >> 0x10);
      local_20 = uVar17 & 0xffff | iVar18 * 0x10000;
      uVar11 = (ushort)(instance->position).z - uVar11;
      local_1c = local_1c & 0xffff0000 | uVar11 & 0xffff;
      if (((int)(uVar17 * 0x10000) >> 0x10) + (iVar18 * 0x10000 >> 0x10) +
          ((int)(uVar11 * 0x10000) >> 0x10) != 0) {
        COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)&local_20);
      }
    }
    instance = instance->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_BringBackNormals(struct Level *BaseLevel /*$a3*/)
 // line 3719, offset 0x8005cec4
	/* begin block 1 */
		// Start line: 3720
		// Start offset: 0x8005CEC4
		// Variables:
	// 		struct _TFace *face; // $v1
	// 		long faceCount; // $a2
	// 		struct _TVertex *v; // $a1
	// 		struct _MorphVertex *mv; // $a0
	// 		struct _MorphColor *mc; // $v0
	// 		short h1; // $v1
	// 		short *morphNormals; // $a1

		/* begin block 1.1 */
			// Start line: 3775
			// Start offset: 0x8005CFA0
			// Variables:
		// 		struct _TVertex *endv; // $a2
		/* end block 1.1 */
		// End offset: 0x8005D008
		// End Line: 3786

		/* begin block 1.2 */
			// Start line: 3801
			// Start offset: 0x8005D008
			// Variables:
		// 		struct _BSPNode *node; // $v1
		// 		struct _BSPLeaf *leaf; // $a1
		// 		struct _Sphere_noSq hsphere; // stack offset -32
		// 		struct _BoundingBox hbox; // stack offset -24
		// 		struct _Terrain *terrain; // $a0
		// 		long curTree; // $t0
		/* end block 1.2 */
		// End offset: 0x8005D21C
		// End Line: 3851

		/* begin block 1.3 */
			// Start line: 3854
			// Start offset: 0x8005D21C
			// Variables:
		// 		struct _Instance *instance; // $s0

			/* begin block 1.3.1 */
				// Start line: 3860
				// Start offset: 0x8005D244
				// Variables:
			// 		struct SVECTOR realDiff; // stack offset -32
			// 		struct _Position oldPos; // stack offset -24
			/* end block 1.3.1 */
			// End offset: 0x8005D314
			// End Line: 3884
		/* end block 1.3 */
		// End offset: 0x8005D324
		// End Line: 3887
	/* end block 1 */
	// End offset: 0x8005D324
	// End Line: 3888

	/* begin block 2 */
		// Start line: 8629
	/* end block 2 */
	// End Line: 8630

void MORPH_BringBackNormals(Level *BaseLevel)

{
  short *psVar1;
  ushort uVar2;
  short sVar3;
  _Terrain *p_Var4;
  _TVertex *p_Var5;
  uint *puVar6;
  int iVar7;
  undefined4 *puVar8;
  Intro *pIVar9;
  uint uVar10;
  ushort *puVar11;
  _MorphVertex *p_Var12;
  byte *pbVar13;
  ushort *puVar14;
  undefined4 *puVar15;
  uint uVar16;
  int iVar17;
  short *psVar18;
  _TVertex *p_Var19;
  int iVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  _Instance *instance;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  undefined4 local_10;
  
  p_Var4 = BaseLevel->terrain;
  puVar14 = (ushort *)p_Var4->morphNormalIdx;
  iVar17 = p_Var4->numFaces;
  puVar11 = &p_Var4->faceList->normal;
  if (0 < iVar17) {
    do {
      uVar2 = *puVar11;
      iVar17 = iVar17 + -1;
      *puVar11 = *puVar14;
      *puVar14 = uVar2;
      puVar14 = puVar14 + 1;
      puVar11 = puVar11 + 6;
    } while (0 < iVar17);
    p_Var4 = BaseLevel->terrain;
  }
  p_Var12 = p_Var4->MorphDiffList;
  if ((p_Var12 != (_MorphVertex *)0x0) && (sVar3 = p_Var12->vindex, -1 < p_Var12->vindex)) {
    psVar18 = &p_Var12->vindex;
    do {
      p_Var5 = BaseLevel->terrain->vertexList + sVar3;
      (p_Var5->vertex).x = psVar18[1];
      (p_Var5->vertex).y = psVar18[2];
      psVar1 = psVar18 + 3;
      psVar18 = psVar18 + 7;
      (p_Var5->vertex).z = *psVar1;
      sVar3 = *psVar18;
    } while (-1 < *psVar18);
  }
  p_Var4 = BaseLevel->terrain;
  if (p_Var4->MorphColorList != (_MorphColor *)0x0) {
    p_Var5 = p_Var4->vertexList;
    p_Var19 = p_Var5 + p_Var4->numVertices;
    pbVar13 = &p_Var5->b0;
    while (p_Var5 < p_Var19) {
      p_Var5 = p_Var5 + 1;
      pbVar13[-2] = (byte)(((uint)pbVar13[-4] & 0x1f) << 3);
      pbVar13[-1] = (byte)(*(ushort *)(pbVar13 + -4) >> 2) & 0xf8;
      *pbVar13 = (byte)(*(ushort *)(pbVar13 + -4) >> 7) & 0xf8;
      pbVar13 = pbVar13 + 0xc;
    }
  }
  p_Var4 = BaseLevel->terrain;
  iVar17 = 0;
  if (0 < p_Var4->numBSPTrees) {
    iVar20 = 0;
    do {
      puVar6 = (uint *)((int)&p_Var4->BSPTreeArray->bspRoot + iVar20);
      puVar15 = (undefined4 *)*puVar6;
      puVar8 = puVar15 + 7;
      if (puVar15 < (undefined4 *)puVar6[1]) {
        do {
          uVar21 = *puVar15;
          local_1c = puVar15[1];
          uVar22 = puVar8[1];
          *puVar15 = *puVar8;
          puVar15[1] = uVar22;
          *puVar8 = uVar21;
          puVar8[1] = local_1c;
          puVar15 = puVar15 + 0xb;
          puVar8 = puVar8 + 0xb;
        } while (puVar15 < *(undefined4 **)((int)&p_Var4->BSPTreeArray->startLeaves + iVar20));
      }
      iVar7 = (int)&p_Var4->BSPTreeArray->bspRoot + iVar20;
      puVar15 = *(undefined4 **)(iVar7 + 4);
      if (puVar15 < *(undefined4 **)(iVar7 + 8)) {
        puVar8 = puVar15 + 7;
        do {
          uVar21 = *puVar15;
          local_1c = puVar15[1];
          uVar22 = puVar8[4];
          *puVar15 = puVar8[3];
          puVar15[1] = uVar22;
          puVar8[3] = uVar21;
          puVar8[4] = local_1c;
          uVar21 = puVar8[-3];
          local_14 = puVar8[-2];
          local_10 = puVar8[-1];
          puVar8[-3] = *puVar8;
          puVar8[-2] = puVar8[1];
          puVar8[-1] = puVar8[2];
          *puVar8 = uVar21;
          puVar8[1] = local_14;
          puVar8[2] = local_10;
          puVar15 = puVar15 + 0xc;
          puVar8 = puVar8 + 0xc;
        } while (puVar15 < *(undefined4 **)((int)&p_Var4->BSPTreeArray->endLeaves + iVar20));
      }
      iVar17 = iVar17 + 1;
      iVar20 = iVar20 + 0x24;
    } while (iVar17 < p_Var4->numBSPTrees);
  }
  instance = (gameTrackerX.instanceList)->first;
  while (instance != (_Instance *)0x0) {
    pIVar9 = instance->intro;
    if ((pIVar9 != (Intro *)0x0) &&
       (((*(int *)&pIVar9->spectralPosition != 0 || ((pIVar9->spectralPosition).z != 0)) &&
        ((instance->flags2 & 8U) == 0)))) {
      local_18 = *(uint *)&instance->position;
      uVar10 = (uint)(ushort)(instance->position).z;
      local_14 = local_14 & 0xffff0000 | uVar10;
      (instance->position).x = (pIVar9->position).x;
      (instance->position).y = (pIVar9->position).y;
      (instance->position).z = (pIVar9->position).z;
      uVar16 = (uint)(ushort)(instance->position).x - (local_18 & 0xffff);
      iVar17 = (uint)(ushort)(instance->position).y - (local_18 >> 0x10);
      local_20 = uVar16 & 0xffff | iVar17 * 0x10000;
      uVar10 = (ushort)(instance->position).z - uVar10;
      local_1c = local_1c & 0xffff0000 | uVar10 & 0xffff;
      if (((int)(uVar16 * 0x10000) >> 0x10) + (iVar17 * 0x10000 >> 0x10) +
          ((int)(uVar10 * 0x10000) >> 0x10) != 0) {
        COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)&local_20);
      }
    }
    instance = instance->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_AddOffsets(struct Level *BaseLevel /*$s2*/, int time /*$a1*/)
 // line 3890, offset 0x8005d334
	/* begin block 1 */
		// Start line: 3891
		// Start offset: 0x8005D334
		// Variables:
	// 		struct _TVertex *v; // $a3
	// 		struct _MorphVertex *mv; // $a2
	// 		struct _MorphColor *mc; // $t2
	// 		long m; // $v0
	// 		long fixed_time; // $s1
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 3939
			// Start offset: 0x8005D4FC
			// Variables:
		// 		struct SVECTOR diff; // stack offset -40
		// 		struct SVECTOR realDiff; // stack offset -32
		// 		struct _Position oldPos; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x8005D5F8
		// End Line: 3958

		/* begin block 1.2 */
			// Start line: 3967
			// Start offset: 0x8005D620
			// Variables:
		// 		long r0; // $a2
		// 		long g0; // $a1
		// 		long b0; // $a0
		// 		long r1; // $v0
		// 		long g1; // $v0
		// 		long b1; // $v1

			/* begin block 1.2.1 */
				// Start line: 3977
				// Start offset: 0x8005D620
				// Variables:
			// 		struct _TVertex *endv; // $t4
			/* end block 1.2.1 */
			// End offset: 0x8005D6E8
			// End Line: 3992
		/* end block 1.2 */
		// End offset: 0x8005D6E8
		// End Line: 4015
	/* end block 1 */
	// End offset: 0x8005D6E8
	// End Line: 4017

	/* begin block 2 */
		// Start line: 9033
	/* end block 2 */
	// End Line: 9034

	/* begin block 3 */
		// Start line: 9039
	/* end block 3 */
	// End Line: 9040

void MORPH_AddOffsets(Level *BaseLevel,int time)

{
  short *psVar1;
  short *psVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  ushort *puVar6;
  int iVar7;
  _TVertex *p_Var8;
  int iVar9;
  Intro *pIVar10;
  int iVar11;
  _Terrain *p_Var12;
  uint uVar13;
  short *psVar14;
  int iVar15;
  uint uVar16;
  _MorphVertex *p_Var17;
  uchar *puVar18;
  _MorphColor *p_Var19;
  _TVertex *p_Var20;
  _Instance *instance;
  SVECTOR local_20;
  uint local_18;
  ushort local_14;
  
  instance = (gameTrackerX.instanceList)->first;
  if (time < 0x1f5) {
    time = time * 2;
    iVar7 = (time * time * time) / 2000000;
  }
  else {
    iVar7 = (1000 - time) * 2;
    iVar7 = 1000 - (iVar7 * iVar7 * iVar7) / 2000000;
  }
  p_Var17 = BaseLevel->terrain->MorphDiffList;
  iVar7 = (iVar7 << 0xc) / 1000;
  if ((p_Var17 != (_MorphVertex *)0x0) && (sVar4 = p_Var17->vindex, -1 < p_Var17->vindex)) {
    psVar14 = &p_Var17->vindex;
    do {
      p_Var8 = BaseLevel->terrain->vertexList + sVar4;
      (p_Var8->vertex).x = psVar14[1] + (short)(p_Var17->x * iVar7 >> 0xc);
      (p_Var8->vertex).y = psVar14[2] + (short)(psVar14[-2] * iVar7 >> 0xc);
      psVar1 = psVar14 + -1;
      psVar2 = psVar14 + 3;
      psVar14 = psVar14 + 7;
      (p_Var8->vertex).z = *psVar2 + (short)(*psVar1 * iVar7 >> 0xc);
      sVar4 = *psVar14;
      p_Var17 = p_Var17 + 1;
    } while (-1 < *psVar14);
  }
  while (instance != (_Instance *)0x0) {
    pIVar10 = instance->intro;
    if ((pIVar10 != (Intro *)0x0) &&
       (((*(int *)&pIVar10->spectralPosition != 0 || ((pIVar10->spectralPosition).z != 0)) &&
        ((instance->flags2 & 8U) == 0)))) {
      sVar4 = (pIVar10->spectralPosition).y;
      sVar3 = (pIVar10->spectralPosition).z;
      local_18 = *(uint *)&instance->position;
      local_14 = (instance->position).z;
      (instance->position).x =
           (pIVar10->position).x + (short)((pIVar10->spectralPosition).x * iVar7 >> 0xc);
      (instance->position).y = (pIVar10->position).y + (short)(sVar4 * iVar7 >> 0xc);
      (instance->position).z = (pIVar10->position).z + (short)(sVar3 * iVar7 >> 0xc);
      iVar15 = (uint)(ushort)(instance->position).x - (local_18 & 0xffff);
      local_20.vx = (short)iVar15;
      iVar11 = (uint)(ushort)(instance->position).y - (local_18 >> 0x10);
      local_20.vy = (short)iVar11;
      iVar9 = (uint)(ushort)(instance->position).z - (uint)local_14;
      local_20.vz = (short)iVar9;
      if ((iVar15 * 0x10000 >> 0x10) + (iVar11 * 0x10000 >> 0x10) + (iVar9 * 0x10000 >> 0x10) != 0)
      {
        COLLIDE_UpdateAllTransforms(instance,&local_20);
      }
    }
    instance = instance->next;
  }
  p_Var12 = BaseLevel->terrain;
  p_Var19 = p_Var12->MorphColorList;
  if (p_Var19 != (_MorphColor *)0x0) {
    p_Var8 = p_Var12->vertexList;
    p_Var20 = p_Var8 + p_Var12->numVertices;
    if (p_Var8 < p_Var20) {
      puVar18 = &p_Var8->b0;
      do {
        uVar5 = *(ushort *)(puVar18 + -4);
        puVar6 = (ushort *)&p_Var19->morphColor15;
        uVar16 = (uint)(uVar5 >> 2) & 0xf8;
        iVar9 = (uint)*puVar6 << 0x10;
        uVar13 = (uint)(uVar5 >> 7) & 0xf8;
        p_Var8 = p_Var8 + 1;
        p_Var19 = p_Var19 + 1;
        puVar18[-2] = (char)((uint)uVar5 & 0x1f) * '\b' +
                      (char)((int)((((uint)*puVar6 & 0x1f) * 8 + ((uint)uVar5 & 0x1f) * -8) * iVar7)
                            >> 0xc);
        puVar18[-1] = (char)uVar16 +
                      (char)((int)(((iVar9 >> 0x12 & 0xf8U) - uVar16) * iVar7) >> 0xc);
        *puVar18 = (char)uVar13 + (char)((int)(((iVar9 >> 0x17 & 0xf8U) - uVar13) * iVar7) >> 0xc);
        puVar18 = puVar18 + 0xc;
      } while (p_Var8 < p_Var20);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_SubtractOffsets(struct Level *BaseLevel /*$s2*/, int time /*$a1*/)
 // line 4019, offset 0x8005d700
	/* begin block 1 */
		// Start line: 4020
		// Start offset: 0x8005D700
		// Variables:
	// 		struct _TVertex *v; // $a3
	// 		struct _MorphVertex *mv; // $a2
	// 		struct _MorphColor *mc; // $t2
	// 		long m; // $v0
	// 		long fixed_time; // $s1
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 4066
			// Start offset: 0x8005D8D0
			// Variables:
		// 		struct SVECTOR diff; // stack offset -40
		// 		struct SVECTOR realDiff; // stack offset -32
		// 		struct _Position oldPos; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x8005D9CC
		// End Line: 4086

		/* begin block 1.2 */
			// Start line: 4095
			// Start offset: 0x8005D9F4
			// Variables:
		// 		long r0; // $a2
		// 		long g0; // $a1
		// 		long b0; // $a0
		// 		long r1; // $v0
		// 		long g1; // $v0
		// 		long b1; // $v1

			/* begin block 1.2.1 */
				// Start line: 4104
				// Start offset: 0x8005D9F4
				// Variables:
			// 		struct _TVertex *endv; // $t4
			/* end block 1.2.1 */
			// End offset: 0x8005DABC
			// End Line: 4119
		/* end block 1.2 */
		// End offset: 0x8005DABC
		// End Line: 4142
	/* end block 1 */
	// End offset: 0x8005DABC
	// End Line: 4144

	/* begin block 2 */
		// Start line: 9375
	/* end block 2 */
	// End Line: 9376

	/* begin block 3 */
		// Start line: 9381
	/* end block 3 */
	// End Line: 9382

void MORPH_SubtractOffsets(Level *BaseLevel,int time)

{
  short *psVar1;
  short *psVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  ushort *puVar6;
  int iVar7;
  _TVertex *p_Var8;
  int iVar9;
  _Terrain *p_Var10;
  Intro *pIVar11;
  int iVar12;
  uint uVar13;
  short *psVar14;
  int iVar15;
  uint uVar16;
  _MorphVertex *p_Var17;
  uchar *puVar18;
  _MorphColor *p_Var19;
  _TVertex *p_Var20;
  _Instance *instance;
  SVECTOR local_20;
  uint local_18;
  ushort local_14;
  
  instance = (gameTrackerX.instanceList)->first;
  if (time < 0x1f5) {
    time = time * 2;
    iVar7 = (time * time * time) / 2000000;
  }
  else {
    iVar7 = (1000 - time) * 2;
    iVar7 = 1000 - (iVar7 * iVar7 * iVar7) / 2000000;
  }
  p_Var17 = BaseLevel->terrain->MorphDiffList;
  iVar7 = ((1000 - iVar7) * 0x1000) / 1000;
  if ((p_Var17 != (_MorphVertex *)0x0) && (sVar4 = p_Var17->vindex, -1 < p_Var17->vindex)) {
    psVar14 = &p_Var17->vindex;
    do {
      p_Var8 = BaseLevel->terrain->vertexList + sVar4;
      (p_Var8->vertex).x = psVar14[1] + (short)(p_Var17->x * iVar7 >> 0xc);
      (p_Var8->vertex).y = psVar14[2] + (short)(psVar14[-2] * iVar7 >> 0xc);
      psVar1 = psVar14 + -1;
      psVar2 = psVar14 + 3;
      psVar14 = psVar14 + 7;
      (p_Var8->vertex).z = *psVar2 + (short)(*psVar1 * iVar7 >> 0xc);
      sVar4 = *psVar14;
      p_Var17 = p_Var17 + 1;
    } while (-1 < *psVar14);
  }
  while (instance != (_Instance *)0x0) {
    pIVar11 = instance->intro;
    if ((pIVar11 != (Intro *)0x0) &&
       (((*(int *)&pIVar11->spectralPosition != 0 || ((pIVar11->spectralPosition).z != 0)) &&
        ((instance->flags2 & 8U) == 0)))) {
      sVar4 = (pIVar11->spectralPosition).y;
      sVar3 = (pIVar11->spectralPosition).z;
      local_18 = *(uint *)&instance->position;
      local_14 = (instance->position).z;
      (instance->position).x =
           (pIVar11->position).x + (short)((pIVar11->spectralPosition).x * iVar7 >> 0xc);
      (instance->position).y = (pIVar11->position).y + (short)(sVar4 * iVar7 >> 0xc);
      (instance->position).z = (pIVar11->position).z + (short)(sVar3 * iVar7 >> 0xc);
      iVar15 = (uint)(ushort)(instance->position).x - (local_18 & 0xffff);
      local_20.vx = (short)iVar15;
      iVar12 = (uint)(ushort)(instance->position).y - (local_18 >> 0x10);
      local_20.vy = (short)iVar12;
      iVar9 = (uint)(ushort)(instance->position).z - (uint)local_14;
      local_20.vz = (short)iVar9;
      if ((iVar15 * 0x10000 >> 0x10) + (iVar12 * 0x10000 >> 0x10) + (iVar9 * 0x10000 >> 0x10) != 0)
      {
        COLLIDE_UpdateAllTransforms(instance,&local_20);
      }
    }
    instance = instance->next;
  }
  p_Var10 = BaseLevel->terrain;
  p_Var19 = p_Var10->MorphColorList;
  if (p_Var19 != (_MorphColor *)0x0) {
    p_Var8 = p_Var10->vertexList;
    p_Var20 = p_Var8 + p_Var10->numVertices;
    if (p_Var8 < p_Var20) {
      puVar18 = &p_Var8->b0;
      do {
        uVar5 = *(ushort *)(puVar18 + -4);
        puVar6 = (ushort *)&p_Var19->morphColor15;
        uVar16 = (uint)(uVar5 >> 2) & 0xf8;
        iVar9 = (uint)*puVar6 << 0x10;
        uVar13 = (uint)(uVar5 >> 7) & 0xf8;
        p_Var8 = p_Var8 + 1;
        p_Var19 = p_Var19 + 1;
        puVar18[-2] = (char)((uint)uVar5 & 0x1f) * '\b' +
                      (char)((int)((((uint)*puVar6 & 0x1f) * 8 + ((uint)uVar5 & 0x1f) * -8) * iVar7)
                            >> 0xc);
        puVar18[-1] = (char)uVar16 +
                      (char)((int)(((iVar9 >> 0x12 & 0xf8U) - uVar16) * iVar7) >> 0xc);
        *puVar18 = (char)uVar13 + (char)((int)(((iVar9 >> 0x17 & 0xf8U) - uVar13) * iVar7) >> 0xc);
        puVar18 = puVar18 + 0xc;
      } while (p_Var8 < p_Var20);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_GetComponentsForTrackingPoint(struct _TFace *face /*$a2*/, struct Level *level /*$a3*/)
 // line 4149, offset 0x8005dad4
	/* begin block 1 */
		// Start line: 4150
		// Start offset: 0x8005DAD4
		// Variables:
	// 		struct _SVector (*v[3]); // stack offset -32
	// 		struct _Position *offset; // $a2
	// 		struct _Position player; // stack offset -16
	// 		int n; // $a1
	// 		int saved_div; // $t0
	// 		int next; // $a0
	// 		int side; // $t1
	// 		int track; // $t3
	// 		int x[2]; // stack offset -8
	// 		struct _TVertex *vertexList; // $a0

		/* begin block 1.1 */
			// Start line: 4162
			// Start offset: 0x8005DAF4
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $a1
		// 		short _z0; // $a0
		// 		short _x1; // $v1
		// 		short _y1; // $a3
		// 		short _z1; // $a2
		// 		struct _Position *_v; // $v0
		// 		struct _Position *_v0; // $a0
		/* end block 1.1 */
		// End offset: 0x8005DAF4
		// End Line: 4162

		/* begin block 1.2 */
			// Start line: 4178
			// Start offset: 0x8005DBC4
			// Variables:
		// 		int next; // $v1

			/* begin block 1.2.1 */
				// Start line: 4185
				// Start offset: 0x8005DC4C
				// Variables:
			// 		int div; // $a0
			/* end block 1.2.1 */
			// End offset: 0x8005DC98
			// End Line: 4190
		/* end block 1.2 */
		// End offset: 0x8005DC98
		// End Line: 4191
	/* end block 1 */
	// End offset: 0x8005DDAC
	// End Line: 4217

	/* begin block 2 */
		// Start line: 9716
	/* end block 2 */
	// End Line: 9717

void MORPH_GetComponentsForTrackingPoint(_TFace *face,Level *level)

{
  int iVar1;
  int iVar2;
  BSPTree *pBVar3;
  int iVar4;
  _TVertex *p_Var5;
  int iVar6;
  _TVertex **pp_Var7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  short *psVar12;
  _TVertex *local_20 [4];
  short local_10;
  short local_e;
  short local_c;
  int local_8 [2];
  
  MORPH_SavedLevel = level;
  MORPH_SavedFace = face;
  if ((face != (_TFace *)0x0) && (iVar11 = 0, level != (Level *)0x0)) {
    psVar12 = &MORPH_Component;
    p_Var5 = level->terrain->vertexList;
    local_20[0] = p_Var5 + (face->face).v0;
    iVar10 = 0;
    local_20[1] = p_Var5 + (face->face).v1;
    local_20[2] = p_Var5 + (face->face).v2;
    pBVar3 = level->terrain->BSPTreeArray + (gameTrackerX.playerInstance)->bspTree;
    local_10 = ((gameTrackerX.playerInstance)->position).x - (pBVar3->globalOffset).x;
    local_e = ((gameTrackerX.playerInstance)->position).y - (pBVar3->globalOffset).y;
    local_c = ((gameTrackerX.playerInstance)->position).z - (pBVar3->globalOffset).z;
    do {
      iVar8 = 0;
      iVar9 = 0;
      iVar6 = 0;
      pp_Var7 = local_20;
      do {
        iVar4 = iVar6 + 1;
        if (2 < iVar4) {
          iVar4 = 0;
        }
        if ((iVar11 != 1) || (iVar6 != (int)MORPH_Track)) {
          iVar1 = iVar4 * 4;
          if (((*(short *)((int)*pp_Var7 + 2) <= local_e) &&
              (iVar1 = iVar4 << 2, local_e <= (local_20[iVar4]->vertex).y)) ||
             ((*(short *)(*(int *)((int)local_20 + iVar1) + 2) <= local_e &&
              (local_e <= *(short *)((int)*pp_Var7 + 2))))) {
            iVar1 = (int)(local_20[iVar4]->vertex).y - (int)*(short *)((int)*pp_Var7 + 2);
            iVar4 = iVar1;
            if (iVar1 < 0) {
              iVar4 = -iVar1;
            }
            iVar2 = iVar8;
            if (iVar8 < 0) {
              iVar2 = -iVar8;
            }
            if (iVar2 < iVar4) {
              iVar8 = iVar1;
              iVar9 = iVar6;
            }
          }
        }
        iVar6 = iVar6 + 1;
        pp_Var7 = (_TVertex **)((int *)pp_Var7 + 1);
      } while (iVar6 < 3);
      *(undefined2 *)((int)&MORPH_Track + iVar10) = (short)iVar9;
      iVar6 = iVar9 + 1;
      if (2 < iVar6) {
        iVar6 = 0;
      }
      if (iVar8 == 0) {
        *(undefined2 *)((int)&MORPH_Component + iVar10) = 0;
      }
      else {
        *(undefined2 *)((int)&MORPH_Component + iVar10) =
             (short)((((int)local_e - (int)(local_20[iVar9]->vertex).y) * 0x1000) / iVar8);
      }
      iVar9 = (int)(local_20[iVar9]->vertex).x;
      iVar8 = (int)*psVar12 * ((local_20[iVar6]->vertex).x - iVar9);
      if (iVar8 < 0) {
        iVar8 = iVar8 + 0xfff;
      }
      local_8[iVar11] = iVar9 + (iVar8 >> 0xc);
      psVar12 = psVar12 + 1;
      iVar11 = iVar11 + 1;
      iVar10 = iVar10 + 2;
    } while (iVar11 < 2);
    if (local_8[0] == local_8[1]) {
      SHORT_800d3ccc = 0;
    }
    else {
      SHORT_800d3ccc = (short)(((local_10 - local_8[0]) * 0x1000) / (local_8[1] - local_8[0]));
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_AveragePoint(struct _SVector *start /*$t0*/, struct _SVector *end /*$a1*/, int interp /*$v1*/, struct _SVector *out /*$a3*/)
 // line 4219, offset 0x8005ddb4
	/* begin block 1 */
		// Start line: 9921
	/* end block 1 */
	// End Line: 9922

void MORPH_AveragePoint(_SVector *start,_SVector *end,int interp,_SVector *out)

{
  _SVector *p_Var1;
  int iVar2;
  
  if (interp < 0) {
    if (interp < -0x1000) {
      interp = -0x1000;
    }
    iVar2 = -interp;
    p_Var1 = end;
  }
  else {
    if (0x1000 < interp) {
      interp = 0x1000;
    }
    p_Var1 = start;
    start = end;
    iVar2 = interp;
    interp = -interp;
  }
  LoadAverageShort12((uint *)p_Var1,(uint *)start,interp + 0x1000,iVar2,(uint *)out);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_UpdateTrackingPoint(struct _TFace *face /*$a2*/, struct Level *level /*$s2*/)
 // line 4235, offset 0x8005de2c
	/* begin block 1 */
		// Start line: 4236
		// Start offset: 0x8005DE2C
		// Variables:
	// 		struct _SVector (*v[3]); // stack offset -56
	// 		struct _SVector p1; // stack offset -40
	// 		struct _SVector p2; // stack offset -32
	// 		struct _SVector p3; // stack offset -24
	// 		struct _Position *offset; // $a3
	// 		int next; // $a1
	// 		struct _TVertex *vertexList; // $a0

		/* begin block 1.1 */
			// Start line: 4256
			// Start offset: 0x8005DF00
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $a0
		// 		short _z0; // $a1
		// 		short _x1; // $v1
		// 		short _y1; // $t0
		// 		short _z1; // $a3
		/* end block 1.1 */
		// End offset: 0x8005DF00
		// End Line: 4256

		/* begin block 1.2 */
			// Start line: 4256
			// Start offset: 0x8005DF00
			// Variables:
		// 		struct _Position *_v0; // $a2
		/* end block 1.2 */
		// End offset: 0x8005DF00
		// End Line: 4256
	/* end block 1 */
	// End offset: 0x8005DFB8
	// End Line: 4269

	/* begin block 2 */
		// Start line: 9953
	/* end block 2 */
	// End Line: 9954

void MORPH_UpdateTrackingPoint(_TFace *face,Level *level)

{
  short sVar1;
  short sVar2;
  _Instance *p_Var3;
  BSPTree *pBVar4;
  _TVertex *p_Var5;
  int iVar6;
  _TVertex *local_38 [4];
  _SVector _Stack40;
  _SVector _Stack32;
  _SVector local_18;
  
  if ((face != (_TFace *)0x0) && (level != (Level *)0x0)) {
    p_Var5 = level->terrain->vertexList;
    local_38[0] = p_Var5 + (face->face).v0;
    local_38[1] = p_Var5 + (face->face).v1;
    iVar6 = (int)MORPH_Track + 1;
    local_38[2] = p_Var5 + (face->face).v2;
    if (2 < iVar6) {
      iVar6 = 0;
    }
    MORPH_AveragePoint((_SVector *)local_38[(int)MORPH_Track],(_SVector *)local_38[iVar6],
                       (int)MORPH_Component,&_Stack40);
    iVar6 = (int)SHORT_800d3cd2 + 1;
    if (2 < iVar6) {
      iVar6 = 0;
    }
    MORPH_AveragePoint((_SVector *)local_38[(int)SHORT_800d3cd2],(_SVector *)local_38[iVar6],
                       (int)SHORT_800d3cca,&_Stack32);
    MORPH_AveragePoint(&_Stack40,&_Stack32,(int)SHORT_800d3ccc,&local_18);
    p_Var3 = gameTrackerX.playerInstance;
    pBVar4 = level->terrain->BSPTreeArray + (gameTrackerX.playerInstance)->bspTree;
    sVar1 = (pBVar4->globalOffset).y;
    sVar2 = (pBVar4->globalOffset).z;
    ((gameTrackerX.playerInstance)->position).x = local_18.x + (pBVar4->globalOffset).x;
    (p_Var3->position).y = local_18.y + sVar1;
    (p_Var3->position).z = local_18.z + sVar2;
    (gameTrackerX.playerInstance)->cachedTFace = -1;
    (gameTrackerX.playerInstance)->cachedTFaceLevel = (void *)0x0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_ToggleMorph()
 // line 4271, offset 0x8005dfd0
	/* begin block 1 */
		// Start line: 4272
		// Start offset: 0x8005DFD0

		/* begin block 1.1 */
			// Start line: 4290
			// Start offset: 0x8005E03C
			// Variables:
		// 		struct Level *level; // $s0
		// 		int i; // $s2
		/* end block 1.1 */
		// End offset: 0x8005E104
		// End Line: 4326
	/* end block 1 */
	// End offset: 0x8005E104
	// End Line: 4328

	/* begin block 2 */
		// Start line: 10036
	/* end block 2 */
	// End Line: 10037

	/* begin block 3 */
		// Start line: 10038
	/* end block 3 */
	// End Line: 10039

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MORPH_ToggleMorph(void)

{
  _MultiSignal *mSignal;
  Level *pLVar1;
  Level **ppLVar2;
  int iVar3;
  
  SOUND_PlaneShift((uint)(gameTrackerX.gameData.asmData.MorphType == 0));
  INSTANCE_Broadcast((_Instance *)0x0,10,0x1000020,(int)gameTrackerX.gameData.asmData.MorphType);
  iVar3 = 0x10;
  MORPH_GetComponentsForTrackingPoint
            ((gameTrackerX.playerInstance)->tface,(Level *)(gameTrackerX.playerInstance)->tfaceLevel
            );
  MORPH_UpdateTrackingPoint
            ((gameTrackerX.playerInstance)->tface,(Level *)(gameTrackerX.playerInstance)->tfaceLevel
            );
  gameTrackerX.gameData.asmData.MorphTime = 0;
  ppLVar2 = &StreamTracker.StreamList[0].level;
  SOUND_Play3dSound(&(gameTrackerX.playerInstance)->position,0x1a,-0x15e,0x7f,0x7fff);
  do {
    if (*(short *)(ppLVar2 + -1) == 2) {
      pLVar1 = *ppLVar2;
      if (gameTrackerX.gameData.asmData.MorphType == 1) {
        mSignal = pLVar1->materialSignal;
        if (mSignal != (_MultiSignal *)0x0) {
          mSignal->flags = mSignal->flags | 1;
          SIGNAL_HandleSignal(gameTrackerX.playerInstance,pLVar1->materialSignal->signalList,0);
          mSignal = pLVar1->materialSignal;
LAB_8005e0f0:
          EVENT_AddSignalToReset(mSignal);
        }
      }
      else {
        mSignal = pLVar1->spectralSignal;
        if (mSignal != (_MultiSignal *)0x0) {
          mSignal->flags = mSignal->flags | 1;
          SIGNAL_HandleSignal(gameTrackerX.playerInstance,pLVar1->spectralSignal->signalList,0);
          mSignal = pLVar1->spectralSignal;
          goto LAB_8005e0f0;
        }
      }
    }
    iVar3 = iVar3 + -1;
    ppLVar2 = ppLVar2 + 0x10;
    if (iVar3 < 1) {
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_DoStep(struct _StreamUnit *streamUnit /*$s0*/, char *baseAreaName /*$a1*/)
 // line 4330, offset 0x8005e11c
	/* begin block 1 */
		// Start line: 4331
		// Start offset: 0x8005E11C
		// Variables:
	// 		struct Level *level; // $s0
	/* end block 1 */
	// End offset: 0x8005E1E8
	// End Line: 4388

	/* begin block 2 */
		// Start line: 10190
	/* end block 2 */
	// End Line: 10191

void MORPH_DoStep(_StreamUnit *streamUnit,char *baseAreaName)

{
  bool bVar1;
  int time;
  Level *level;
  
  GAMEPAD_Shock1(0x40,0xf000);
  level = streamUnit->level;
  if (level->terrain->MorphDiffList != (_MorphVertex *)0x0) {
    VM_UpdateMorph(level,0);
    time = (int)gameTrackerX.gameData.asmData.MorphTime;
    if (time == 1000) {
      bVar1 = gameTrackerX.gameData.asmData.MorphType == 0;
      gameTrackerX.gameData.asmData.MorphType = gameTrackerX.gameData.asmData.MorphType ^ 1;
      if (bVar1) {
        MORPH_UpdateNormals(level);
      }
      else {
        MORPH_BringBackNormals(level);
      }
      gameTrackerX.gameData.asmData.MorphType = gameTrackerX.gameData.asmData.MorphType ^ 1;
      level->morphLastStep = -1;
    }
    else {
      if (gameTrackerX.gameData.asmData.MorphType == 0) {
        MORPH_AddOffsets(level,time);
      }
      else {
        MORPH_SubtractOffsets(level,time);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_SetFog(struct _StreamUnit *streamUnit /*$a0*/, int mainUnitFlag /*$t0*/)
 // line 4390, offset 0x8005e1f8
	/* begin block 1 */
		// Start line: 4391
		// Start offset: 0x8005E1F8
		// Variables:
	// 		long time; // $v1
	// 		struct Level *level; // $a2
	// 		int fogNear; // $a1
	// 		int fogFar; // $v0
	/* end block 1 */
	// End offset: 0x8005E2BC
	// End Line: 4413

	/* begin block 2 */
		// Start line: 10313
	/* end block 2 */
	// End Line: 10314

	/* begin block 3 */
		// Start line: 10319
	/* end block 3 */
	// End Line: 10320

void MORPH_SetFog(_StreamUnit *streamUnit,int mainUnitFlag)

{
  short sVar1;
  int iVar2;
  Level *pLVar3;
  int iVar4;
  
  iVar2 = ((int)gameTrackerX.gameData.asmData.MorphTime << 0xc) / 1000;
  pLVar3 = streamUnit->level;
  if (gameTrackerX.gameData.asmData.MorphType == 0) {
    iVar2 = 0x1000 - iVar2;
  }
  iVar4 = ((uint)pLVar3->holdFogNear - (uint)pLVar3->spectralFogNear) * iVar2;
  if (iVar4 < 0) {
    iVar4 = iVar4 + 0xfff;
  }
  iVar2 = ((uint)pLVar3->holdFogFar - (uint)pLVar3->spectralFogFar) * iVar2;
  iVar4 = (iVar4 >> 0xc) + (uint)pLVar3->spectralFogNear;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  iVar2 = (iVar2 >> 0xc) + (uint)pLVar3->spectralFogFar;
  if (mainUnitFlag == 0) {
    STREAM_SetStreamFog(streamUnit,(short)((uint)(iVar4 * 0x10000) >> 0x10),
                        (short)((uint)(iVar2 * 0x10000) >> 0x10));
  }
  else {
    sVar1 = (short)iVar4;
    streamUnit->UnitFogNear = sVar1;
    streamUnit->TargetFogNear = sVar1;
    sVar1 = (short)iVar2;
    streamUnit->UnitFogFar = sVar1;
    streamUnit->TargetFogFar = sVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_UpdateTextures()
 // line 4415, offset 0x8005e2cc
	/* begin block 1 */
		// Start line: 4416
		// Start offset: 0x8005E2CC
		// Variables:
	// 		long time; // $a0
	/* end block 1 */
	// End offset: 0x8005E30C
	// End Line: 4426

	/* begin block 2 */
		// Start line: 10373
	/* end block 2 */
	// End Line: 10374

	/* begin block 3 */
		// Start line: 10376
	/* end block 3 */
	// End Line: 10377

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MORPH_UpdateTextures(void)

{
  int time;
  
  time = ((int)gameTrackerX.gameData.asmData.MorphTime << 0xc) / 1000;
  if (gameTrackerX.gameData.asmData.MorphType == 1) {
    time = 0x1000 - time;
  }
  MORPH_ChangeAreaPalettes(time);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_Continue()
 // line 4430, offset 0x8005e324
	/* begin block 1 */
		// Start line: 4431
		// Start offset: 0x8005E324
		// Variables:
	// 		int i; // $s2
	// 		long mode; // $v0
	/* end block 1 */
	// End offset: 0x8005E47C
	// End Line: 4489

	/* begin block 2 */
		// Start line: 10406
	/* end block 2 */
	// End Line: 10407

	/* begin block 3 */
		// Start line: 10411
	/* end block 3 */
	// End Line: 10412

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MORPH_Continue(void)

{
  ulong uVar1;
  _TFace *face;
  Level *level;
  STracker *streamUnit;
  char *baseAreaName;
  int iVar2;
  
  if (gameTrackerX.gameData.asmData.MorphTime == 0) {
    MORPH_InMorphInstanceListFlags();
  }
  iVar2 = 0;
  baseAreaName = StreamTracker.StreamList[0].baseAreaName;
  streamUnit = &StreamTracker;
  gameTrackerX.gameData.asmData.MorphTime = gameTrackerX.gameData.asmData.MorphTime + 0x14;
  MORPH_InMorphDoFadeValues();
  do {
    if (*(short *)streamUnit->StreamList == 2) {
      MORPH_DoStep((_StreamUnit *)streamUnit,baseAreaName);
      MORPH_SetFog((_StreamUnit *)streamUnit,0);
    }
    baseAreaName = baseAreaName + 0x40;
    iVar2 = iVar2 + 1;
    streamUnit = (STracker *)(streamUnit->StreamList + 1);
  } while (iVar2 < 0x10);
  uVar1 = INSTANCE_Query(gameTrackerX.playerInstance,10);
  face = (gameTrackerX.playerInstance)->tface;
  if ((face != (_TFace *)0x0) && (-1 < (int)uVar1)) {
    level = MORPH_SavedLevel;
    if (MORPH_SavedFace != face) {
      MORPH_GetComponentsForTrackingPoint(face,(Level *)(gameTrackerX.playerInstance)->tfaceLevel);
      face = (gameTrackerX.playerInstance)->tface;
      level = (Level *)(gameTrackerX.playerInstance)->tfaceLevel;
    }
    MORPH_UpdateTrackingPoint(face,level);
  }
  MORPH_UpdateTextures();
  if (gameTrackerX.gameData.asmData.MorphTime == 1000) {
    gameTrackerX.gameData.asmData.MorphType = gameTrackerX.gameData.asmData.MorphType ^ 1;
    if (gameTrackerX.gameData.asmData.MorphType == 0) {
      (gameTrackerX.playerInstance)->flags2 = (gameTrackerX.playerInstance)->flags2 & 0xf7ffffff;
    }
    else {
      (gameTrackerX.playerInstance)->flags2 = (gameTrackerX.playerInstance)->flags2 | 0x8000000;
    }
    MORPH_SetupInstanceListFlags();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_MORPH_Relocate()
 // line 4490, offset 0x8005e498
	/* begin block 1 */
		// Start line: 10546
	/* end block 1 */
	// End Line: 10547

	/* begin block 2 */
		// Start line: 10547
	/* end block 2 */
	// End Line: 10548

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_MORPH_Relocate(void)

{
  MORPH_SavedLevel = (Level *)0x0;
  MORPH_SavedFace = (_TFace *)0x0;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ AddVertex(struct VECTOR *v0 /*$a0*/, struct RECT *rect /*$t0*/)
 // line 4653, offset 0x8005e4a8
	/* begin block 1 */
		// Start line: 4654
		// Start offset: 0x8005E4A8
		// Variables:
	// 		struct SVECTOR v; // stack offset -8
	// 		int x; // $v0
	// 		int y; // $v1
	// 		int z; // $a1
	// 		int scr_x; // $a0
	// 		int scr_y; // $a1
	/* end block 1 */
	// End offset: 0x8005E62C
	// End Line: 4690

	/* begin block 2 */
		// Start line: 10872
	/* end block 2 */
	// End Line: 10873

int AddVertex(VECTOR *v0,RECT *rect)

{
  undefined4 in_zero;
  undefined4 in_at;
  int iVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 local_8;
  uint local_4;
  
  iVar2 = v0->vx;
  if (iVar2 < 0) {
    iVar1 = -0x8000;
LAB_8005e4cc:
    v0->vx = iVar2 + iVar1;
  }
  else {
    iVar1 = 0x8000;
    if (0 < iVar2) goto LAB_8005e4cc;
  }
  iVar1 = v0->vy;
  iVar2 = -0x8000;
  if ((iVar1 < 0) || (iVar2 = 0x8000, 0 < iVar1)) {
    v0->vy = iVar1 + iVar2;
  }
  iVar1 = v0->vz;
  iVar2 = -0x8000;
  if (-1 < iVar1) {
    if (iVar1 < 1) goto LAB_8005e518;
    iVar2 = 0x8000;
  }
  v0->vz = iVar1 + iVar2;
LAB_8005e518:
  local_8 = CONCAT22(*(undefined2 *)((int)&v0->vy + 2),*(undefined2 *)((int)&v0->vx + 2));
  local_4 = local_4 & 0xffff0000 | (uint)*(ushort *)((int)&v0->vz + 2);
  setCopReg(2,in_zero,local_8);
  setCopReg(2,in_at,local_4);
  copFunction(2,0x480012);
  uVar5 = getCopReg(2,0x4800);
  uVar6 = getCopReg(2,0x5000);
  uVar7 = getCopReg(2,0x5800);
  iVar1 = (int)(short)uVar7;
  iVar2 = -1;
  if (0 < iVar1) {
    iVar2 = ((int)(short)uVar5 * 0x140) / iVar1 + 0x100;
    iVar3 = ((int)(short)uVar6 * 0x140) / iVar1 + 0x78;
    sVar4 = (short)iVar2;
    if (rect->x < iVar2) {
      sVar4 = rect->x;
    }
    rect->x = sVar4;
    sVar4 = (short)iVar2;
    if (iVar2 < rect->w) {
      sVar4 = rect->w;
    }
    rect->w = sVar4;
    sVar4 = (short)iVar3;
    if (rect->y < iVar3) {
      sVar4 = rect->y;
    }
    rect->y = sVar4;
    sVar4 = (short)iVar3;
    if (iVar3 < rect->h) {
      sVar4 = rect->h;
    }
    rect->h = sVar4;
    iVar2 = iVar1;
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GetPlaneDist(int k /*$a0*/, int j /*$a1*/, int i /*$a2*/, struct VECTOR *v /*$a3*/)
 // line 4692, offset 0x8005e634
	/* begin block 1 */
		// Start line: 10955
	/* end block 1 */
	// End Line: 10956

	/* begin block 2 */
		// Start line: 10956
	/* end block 2 */
	// End Line: 10957

int GetPlaneDist(int k,int j,int i,VECTOR *v)

{
  return ((v->vx >> 0xc) + (int)theCamera.core.position.x * -0x10) *
         (int)theCamera.core.vvNormalWorVecMat[k].m[j * 3] +
         ((v->vy >> 0xc) + (int)theCamera.core.position.y * -0x10) *
         (int)theCamera.core.vvNormalWorVecMat[k].m[j * 3 + 1] +
         ((v->vz >> 0xc) + (int)theCamera.core.position.z * -0x10) *
         (int)theCamera.core.vvNormalWorVecMat[k].m[j * 3 + 2];
}



// decompiled code
// original method signature: 
// void /*$ra*/ CalcVert(struct VECTOR *v /*$a0*/, struct VECTOR *v1 /*$a1*/, struct VECTOR *v2 /*$a2*/, int dist1 /*$a3*/, int dist2 /*stack 16*/, int k /*stack 20*/, int j /*stack 24*/)
 // line 4701, offset 0x8005e6c0
	/* begin block 1 */
		// Start line: 4702
		// Start offset: 0x8005E6C0
		// Variables:
	// 		int diff; // $a3
	/* end block 1 */
	// End offset: 0x8005E6C0
	// End Line: 4702

	/* begin block 2 */
		// Start line: 10973
	/* end block 2 */
	// End Line: 10974

void CalcVert(VECTOR *v,VECTOR *v1,VECTOR *v2,int dist1,int dist2,int k,int j)

{
  dist2 = dist2 / (dist1 - dist2 >> 0xc);
  v->vx = (v2->vx - v1->vx >> 0xc) * dist2 + v2->vx;
  v->vy = (v2->vy - v1->vy >> 0xc) * dist2 + v2->vy;
  v->vz = (v2->vz - v1->vz >> 0xc) * dist2 + v2->vz;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ AddClippedTri(struct SVECTOR *iv /*$a0*/, struct RECT *cliprect /*stack 4*/, int *minz /*stack 8*/)
 // line 4715, offset 0x8005e748
	/* begin block 1 */
		// Start line: 4716
		// Start offset: 0x8005E748
		// Variables:
	// 		int clip0; // $s7
	// 		int clip1; // $s2
	// 		int i; // $s5
	// 		int j; // stack offset -64
	// 		int k; // stack offset -60
	// 		int l; // stack offset -56
	// 		int l_1; // $s6
	// 		int numvert; // $fp
	// 		int newnumvert; // $s3
	// 		struct VECTOR v0[16]; // stack offset -576
	// 		struct VECTOR v1[16]; // stack offset -320
	// 		struct VECTOR *src; // stack offset -52
	// 		struct VECTOR *dst; // stack offset -48
	// 		struct VECTOR *tmp; // $v0

		/* begin block 1.1 */
			// Start line: 4792
			// Start offset: 0x8005E980
			// Variables:
		// 		int z; // $v0
		/* end block 1.1 */
		// End offset: 0x8005E9AC
		// End Line: 4796
	/* end block 1 */
	// End offset: 0x8005E9C0
	// End Line: 4798

	/* begin block 2 */
		// Start line: 11001
	/* end block 2 */
	// End Line: 11002

int AddClippedTri(SVECTOR *iv,RECT *cliprect,int *minz)

{
  short *psVar1;
  bool bVar2;
  int dist1;
  int dist2;
  VECTOR *v1;
  long lVar3;
  long lVar4;
  VECTOR *v;
  long lVar5;
  VECTOR *v_00;
  int iVar6;
  int iVar7;
  int i;
  int iVar8;
  VECTOR local_240 [16];
  VECTOR aVStack320 [16];
  int local_40;
  uint local_3c;
  int local_38;
  VECTOR *local_34;
  VECTOR *local_30;
  
  v = local_240;
  local_30 = aVStack320;
  iVar7 = 0;
  *minz = 0xffff;
  local_34 = v;
  do {
    v->vx = (int)iv->vx << 0x10;
    iVar7 = iVar7 + 1;
    v->vy = (int)iv->vy << 0x10;
    psVar1 = &iv->vz;
    iv = iv + 1;
    v->vz = (int)*psVar1 << 0x10;
    v = v + 1;
  } while (iVar7 < 3);
  i = 0;
  bVar2 = true;
  iVar7 = 3;
  do {
    local_40 = i;
    if (!bVar2) {
      local_40 = i + -3;
    }
    local_3c = (uint)!bVar2;
    dist1 = GetPlaneDist(local_3c,local_40,i,local_34);
    iVar8 = 1;
    iVar6 = 0;
    local_38 = 0;
    v = local_30;
    v1 = local_34;
    if (0 < iVar7) {
      do {
        if (iVar7 <= iVar8) {
          iVar8 = 0;
        }
        v_00 = local_34 + iVar8;
        dist2 = GetPlaneDist(local_3c,local_40,i,v_00);
        if (dist1 < 1) {
          if (0 < dist2) {
            CalcVert(v,v1,v_00,dist1,dist2,local_3c,local_40);
            v = v + 1;
            goto LAB_8005e91c;
          }
        }
        else {
          if (dist2 < 1) {
            lVar4 = v1->vy;
            lVar5 = v1->vz;
            lVar3 = v1->pad;
            v->vx = v1->vx;
            v->vy = lVar4;
            v->vz = lVar5;
            v->pad = lVar3;
            iVar6 = iVar6 + 1;
            CalcVert(v + 1,v_00,v1,dist2,dist1,local_3c,local_40);
            v = v + 2;
          }
          else {
            lVar4 = v1->vy;
            lVar5 = v1->vz;
            lVar3 = v1->pad;
            v->vx = v1->vx;
            v->vy = lVar4;
            v->vz = lVar5;
            v->pad = lVar3;
            v = v + 1;
          }
LAB_8005e91c:
          iVar6 = iVar6 + 1;
        }
        iVar8 = iVar8 + 1;
        local_38 = local_38 + 1;
        v1 = v1 + 1;
        dist1 = dist2;
      } while (local_38 < iVar7);
    }
    v1 = local_30;
    v = local_34;
    local_34 = local_30;
    local_30 = v;
    if (iVar6 < 3) {
      return (uint)(iVar6 != 0);
    }
    i = i + 1;
    bVar2 = i < 3;
    iVar7 = iVar6;
    if (4 < i) {
      iVar7 = 0;
      if (0 < iVar6) {
        do {
          i = AddVertex(v1,cliprect);
          if (i < *minz) {
            *minz = i;
          }
          iVar7 = iVar7 + 1;
          v1 = v1 + 1;
        } while (iVar7 < iVar6);
      }
      return 1;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_GetClipRect(struct StreamUnitPortal *portal /*$s5*/, struct RECT *rect /*$s3*/)
 // line 4800, offset 0x8005e9f0
	/* begin block 1 */
		// Start line: 4801
		// Start offset: 0x8005E9F0
		// Variables:
	// 		int v1x; // $v0
	// 		int v1y; // $t2
	// 		int v1z; // $a3
	// 		int v2x; // $t0
	// 		int v2y; // $v1
	// 		int v2z; // $t1
	// 		int nx; // $s7
	// 		int ny; // $s6
	// 		int nz; // stack offset -56
	// 		int nx2; // $s4
	// 		int ny2; // $s2
	// 		int nz2; // $s1
	// 		int len; // stack offset -52
	// 		int side; // $fp
	// 		int side2; // $s0
	// 		int retval; // $s0
	// 		int horizontal_flag; // stack offset -48
	// 		int fullscreen_flag; // stack offset -44
	// 		int minz; // stack offset -64
	// 		int minz2; // stack offset -60

		/* begin block 1.1 */
			// Start line: 4889
			// Start offset: 0x8005ECE4
			// Variables:
		// 		int dot; // $v0
		/* end block 1.1 */
		// End offset: 0x8005ED64
		// End Line: 4899
	/* end block 1 */
	// End offset: 0x8005EF88
	// End Line: 4966

	/* begin block 2 */
		// Start line: 11288
	/* end block 2 */
	// End Line: 11289

int STREAM_GetClipRect(StreamUnitPortal *portal,RECT *rect)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  MATRIX *pMVar8;
  short sVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int local_40;
  int local_3c;
  int local_38;
  long local_34;
  uint local_30;
  int local_2c;
  
  local_2c = 0;
  sVar9 = portal->t1[0].z;
  iVar17 = (int)sVar9;
  iVar11 = (int)portal->t1[1].z;
  local_30 = 0;
  if (iVar17 == iVar11) {
    local_30 = (uint)(sVar9 == portal->t1[2].z);
  }
  iVar10 = (int)portal->t1[0].y;
  iVar15 = iVar10 - portal->t1[1].y;
  iVar13 = iVar17 - portal->t1[2].z;
  iVar11 = iVar17 - iVar11;
  iVar6 = iVar10 - portal->t1[2].y;
  iVar7 = (int)portal->t1[0].x;
  iVar12 = iVar7 - portal->t1[2].x;
  iVar2 = iVar7 - portal->t1[1].x;
  iVar19 = iVar15 * iVar13 - iVar6 * iVar11 >> 0xc;
  iVar13 = iVar12 * iVar11 - iVar2 * iVar13 >> 0xc;
  local_38 = iVar2 * iVar6 - iVar12 * iVar15 >> 0xc;
  iVar2 = (iVar7 - theCamera.core.position.x) * iVar19 +
          (iVar10 - theCamera.core.position.y) * iVar13 +
          (iVar17 - theCamera.core.position.z) * local_38;
  iVar11 = -iVar2;
  local_34 = MATH3D_FastSqrt(iVar19 * iVar19 + iVar13 * iVar13 + local_38 * local_38);
  iVar17 = iVar11;
  if (0 < iVar2) {
    iVar17 = iVar2;
  }
  if (iVar17 < local_34) {
    iVar7 = (int)portal->t2[0].y;
    iVar10 = (int)portal->t2[0].z;
    iVar16 = iVar7 - portal->t2[1].y;
    iVar14 = iVar10 - portal->t2[2].z;
    iVar12 = iVar10 - portal->t2[1].z;
    iVar2 = iVar7 - portal->t2[2].y;
    iVar6 = (int)portal->t2[0].x;
    iVar15 = iVar6 - portal->t2[2].x;
    iVar17 = iVar6 - portal->t2[1].x;
    iVar18 = iVar16 * iVar14 - iVar2 * iVar12 >> 0xc;
    iVar12 = iVar15 * iVar12 - iVar17 * iVar14 >> 0xc;
    iVar2 = iVar17 * iVar2 - iVar15 * iVar16 >> 0xc;
    iVar17 = -((iVar6 - theCamera.core.position.x) * iVar18 +
               (iVar7 - theCamera.core.position.y) * iVar12 +
              (iVar10 - theCamera.core.position.z) * iVar2);
    MATH3D_FastSqrt(iVar18 * iVar18 + iVar12 * iVar12 + iVar2 * iVar2);
    if (iVar11 < iVar17) {
      iVar13 = iVar12;
      iVar19 = iVar18;
      iVar11 = iVar17;
      local_38 = iVar2;
    }
  }
  iVar17 = memcmp((byte *)portal,(byte *)"warpgate",8);
  if (iVar17 != 0) {
    iVar17 = iVar11;
    if (iVar11 < 0) {
      iVar17 = -iVar11;
    }
    if (((iVar17 < local_34) &&
        (pMVar8 = (theCamera.focusInstance)->matrix,
        (pMVar8[1].t[0] - (int)theCamera.core.position.x) * iVar19 +
        (pMVar8[1].t[1] - (int)theCamera.core.position.y) * iVar13 +
        (pMVar8[1].t[2] - (int)theCamera.core.position.z) * local_38 < 0)) && (local_30 == 0)) {
      local_2c = 1;
    }
  }
  if ((-0x401 < iVar11) || (uVar3 = 0, local_2c != 0)) {
    rect->w = rect->w + rect->x;
    rect->h = rect->h + rect->y;
    setCopControlWord(2,0,*(undefined4 *)(theCamera.core.wcTransform)->m);
    setCopControlWord(2,0x800,*(undefined4 *)((theCamera.core.wcTransform)->m + 2));
    setCopControlWord(2,0x1000,*(undefined4 *)((theCamera.core.wcTransform)->m + 4));
    setCopControlWord(2,0x1800,*(undefined4 *)((theCamera.core.wcTransform)->m + 6));
    setCopControlWord(2,0x2000,*(undefined4 *)((theCamera.core.wcTransform)->m + 8));
    setCopControlWord(2,0x2800,(theCamera.core.wcTransform)->t[0]);
    setCopControlWord(2,0x3000,(theCamera.core.wcTransform)->t[1]);
    setCopControlWord(2,0x3800,(theCamera.core.wcTransform)->t[2]);
    uVar4 = AddClippedTri((SVECTOR *)portal->t1,rect,&local_40);
    uVar5 = AddClippedTri((SVECTOR *)portal->t2,rect,&local_3c);
    uVar3 = 0;
    if ((uVar4 | uVar5) == 0) {
      rect->w = rect->w - rect->x;
      rect->h = rect->h - rect->y;
    }
    else {
      if (local_3c < local_40) {
        local_40 = local_3c;
      }
      if ((local_2c == 0) || (uVar3 = 1, 0x3f < local_40)) {
        if (rect->x < 0) {
          rect->x = 0;
        }
        if (rect->y < 0) {
          rect->y = 0;
        }
        if (0x200 < rect->w) {
          rect->w = 0x200;
        }
        if (0xf0 < rect->h) {
          rect->h = 0xf0;
        }
        sVar9 = rect->h - rect->y;
        rect->w = rect->w - rect->x;
        rect->h = sVar9;
        if (local_30 != 0) {
          if (iVar11 < 0) {
            iVar11 = -iVar11;
          }
          if (iVar11 < local_34) {
            if (local_38 < 1) {
              sVar1 = rect->y;
              rect->y = 0;
              sVar1 = sVar1 + sVar9;
            }
            else {
              sVar1 = 0xf0 - rect->y;
            }
            rect->h = sVar1;
          }
        }
        if (rect->w < 1) {
          uVar3 = 0;
        }
        else {
          uVar3 = (uint)(0 < rect->h);
        }
      }
      else {
        rect->w = 0x200;
        rect->x = 0;
        rect->y = 0;
        rect->h = 0xf0;
      }
    }
  }
  return uVar3;
}



// decompiled code
// original method signature: 
// long /*$ra*/ GetFogColor(struct StreamUnitPortal *portal /*$s0*/, struct _StreamUnit *mainStreamUnit /*$a1*/, struct Level *mainLevel /*$s1*/)
 // line 4969, offset 0x8005efb8
	/* begin block 1 */
		// Start line: 4970
		// Start offset: 0x8005EFB8
		// Variables:
	// 		long z1; // stack offset -36
	// 		long z2; // stack offset -32
	// 		long z3; // stack offset -28
	// 		long zval; // $a1
	// 		long zval2; // $v1
	// 		long interp; // $s0
	// 		long Color; // stack offset -20
	// 		long MainColor; // stack offset -24
	// 		long LevelColor; // stack offset -40
	// 		struct Level *level; // $a1

		/* begin block 1.1 */
			// Start line: 4982
			// Start offset: 0x8005EFEC
			// Variables:
		// 		int time; // $a2
		/* end block 1.1 */
		// End offset: 0x8005F024
		// End Line: 4988
	/* end block 1 */
	// End offset: 0x8005F2C8
	// End Line: 5076

	/* begin block 2 */
		// Start line: 11797
	/* end block 2 */
	// End Line: 11798

long GetFogColor(StreamUnitPortal *portal,_StreamUnit *mainStreamUnit,Level *mainLevel)

{
  undefined4 in_zero;
  undefined4 in_at;
  uint uVar1;
  byte *pbVar2;
  Level *pLVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  
  local_18 = mainStreamUnit->FogColor;
  pLVar3 = portal->toStreamUnit->level;
  if ((int)gameTrackerX.gameData.asmData.MorphTime == 1000) {
    if (gameTrackerX.gameData.asmData.MorphType == 1) {
      local_28 = *(uint *)&pLVar3->specturalColorR;
    }
    else {
      local_28 = *(uint *)&pLVar3->backColorR;
    }
  }
  else {
    iVar5 = ((int)gameTrackerX.gameData.asmData.MorphTime << 0xc) / 1000;
    pbVar2 = &pLVar3->specturalColorR;
    if (gameTrackerX.gameData.asmData.MorphType == 1) {
      iVar5 = 0x1000 - iVar5;
    }
    pLVar3 = (Level *)&pLVar3->backColorR;
    LoadAverageCol(pbVar2,(byte *)pLVar3,iVar5,0x1000 - iVar5,(undefined *)&local_28);
    local_28 = local_28 & 0xffffff;
  }
  setCopReg(2,in_zero,*(undefined4 *)portal->t1);
  setCopReg(2,in_at,*(undefined4 *)&portal->t1[0].z);
  setCopReg(2,portal->t1 + 2,*(undefined4 *)(portal->t1 + 1));
  setCopReg(2,portal->t1 + 1,*(undefined4 *)&portal->t1[1].z);
  setCopReg(2,portal->t1,*(undefined4 *)(portal->t1 + 2));
  setCopReg(2,pLVar3,*(undefined4 *)&portal->t1[2].z);
  copFunction(2,0x280030);
  iVar5 = getCopReg(2,0x11);
  iVar6 = getCopReg(2,0x12);
  iVar4 = getCopReg(2,0x13);
  if (iVar6 < iVar5) {
    iVar6 = iVar4;
    if (iVar4 < iVar5) {
      iVar6 = iVar5;
    }
  }
  else {
    if (iVar6 <= iVar4) goto LAB_8005f110;
  }
  iVar4 = iVar6;
LAB_8005f110:
  setCopReg(2,in_zero,*(undefined4 *)portal->t2);
  setCopReg(2,in_at,*(undefined4 *)&portal->t2[0].z);
  setCopReg(2,portal->t2 + 2,*(undefined4 *)(portal->t2 + 1));
  setCopReg(2,portal->t2 + 1,*(undefined4 *)&portal->t2[1].z);
  setCopReg(2,portal->t2,*(undefined4 *)(portal->t2 + 2));
  setCopReg(2,iVar4,*(undefined4 *)&portal->t2[2].z);
  copFunction(2,0x280030);
  local_24 = getCopReg(2,0x11);
  local_20 = getCopReg(2,0x12);
  local_1c = getCopReg(2,0x13);
  iVar5 = local_20;
  if (local_20 < local_24) {
    iVar5 = local_24;
  }
  iVar6 = local_1c;
  if (local_1c < iVar5) {
    iVar6 = iVar5;
  }
  if (iVar4 < iVar6) {
    iVar4 = iVar6;
  }
  uVar1 = (uint)mainLevel->fogFar;
  if ((int)(iVar4 + 0x80U) < (int)(uint)mainLevel->fogFar) {
    uVar1 = iVar4 + 0x80U;
  }
  s_zval = (int)uVar1 >> 2;
  if (local_18 == local_28) {
    local_28 = local_28 & 0xfff8f8f8;
    if (local_28 != 0) {
      local_28 = local_28 | 0x40404;
    }
  }
  else {
    iVar5 = uVar1 - (uint)mainLevel->fogNear;
    if (-1 < iVar5) {
      iVar6 = (iVar5 * 0x10000) / (int)((uint)mainLevel->fogFar - (uint)mainLevel->fogNear) >> 4;
      iVar5 = iVar6;
      if (iVar6 < 0) {
        iVar5 = 0;
      }
      if (0x1000 < iVar6) {
        iVar5 = 0x1000;
      }
      LoadAverageCol((byte *)&local_18,(byte *)&local_28,iVar5,0x1000 - iVar5,(undefined *)&local_14
                    );
      if ((0xffa < iVar5) && (local_14 = local_14 & 0xfff8f8f8, local_14 != 0)) {
        local_14 = local_14 | 0x40404;
      }
      local_28 = local_14 & 0xffffff;
    }
  }
  return local_28;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DrawFogRectangle(struct RECT *cliprect /*$a0*/, struct _PrimPool *primPool /*$a1*/, int otzpos /*$a2*/, unsigned long **drawot /*$a3*/, long color /*stack 16*/)
 // line 5078, offset 0x8005f2dc
	/* begin block 1 */
		// Start line: 5079
		// Start offset: 0x8005F2DC
		// Variables:
	// 		struct POLY_G4 *polyg4; // $t0
	/* end block 1 */
	// End offset: 0x8005F3C0
	// End Line: 5120

	/* begin block 2 */
		// Start line: 12027
	/* end block 2 */
	// End Line: 12028

	/* begin block 3 */
		// Start line: 12030
	/* end block 3 */
	// End Line: 12031

void DrawFogRectangle(RECT *cliprect,_PrimPool *primPool,int otzpos,ulong **drawot,long color)

{
  short sVar1;
  short sVar2;
  ulong *puVar3;
  
  puVar3 = (gameTrackerX.primPool)->nextPrim;
  if (puVar3 + 9 < (gameTrackerX.primPool)->lastPrim) {
    (gameTrackerX.primPool)->nextPrim = puVar3 + 9;
    *(short *)(puVar3 + 2) = cliprect->x;
    *(short *)((int)puVar3 + 10) = cliprect->y;
    *(short *)(puVar3 + 4) = cliprect->x + cliprect->w;
    *(short *)((int)puVar3 + 0x12) = cliprect->y;
    *(short *)(puVar3 + 6) = cliprect->x;
    *(short *)((int)puVar3 + 0x1a) = cliprect->y + cliprect->h;
    *(short *)(puVar3 + 8) = cliprect->x + cliprect->w;
    sVar1 = cliprect->y;
    sVar2 = cliprect->h;
    *(undefined *)((int)puVar3 + 3) = 8;
    puVar3[1] = color;
    puVar3[3] = color;
    puVar3[5] = color;
    puVar3[7] = color;
    *(undefined *)((int)puVar3 + 7) = 0x38;
    *(short *)((int)puVar3 + 0x22) = sVar1 + sVar2;
    *puVar3 = (uint)drawot[otzpos] & 0xffffff | 0x8000000;
    drawot[otzpos] = (ulong *)((uint)puVar3 & 0xffffff);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_RenderAdjacantUnit(unsigned long **curOT /*$s3*/, struct StreamUnitPortal *curStreamPortal /*$s0*/, struct _StreamUnit *toStreamUnit /*$s1*/, struct _StreamUnit *mainStreamUnit /*$s2*/, struct RECT *cliprect /*stack 16*/)
 // line 5126, offset 0x8005f3c8
	/* begin block 1 */
		// Start line: 5127
		// Start offset: 0x8005F3C8

		/* begin block 1.1 */
			// Start line: 5131
			// Start offset: 0x8005F400
			// Variables:
		// 		long portalFogColor; // $s0
		/* end block 1.1 */
		// End offset: 0x8005F458
		// End Line: 5143
	/* end block 1 */
	// End offset: 0x8005F458
	// End Line: 5144

	/* begin block 2 */
		// Start line: 12209
	/* end block 2 */
	// End Line: 12210

void STREAM_RenderAdjacantUnit
               (ulong **curOT,StreamUnitPortal *curStreamPortal,_StreamUnit *toStreamUnit,
               _StreamUnit *mainStreamUnit,RECT *cliprect)

{
  long color;
  
  color = MEMPACK_MemoryValidFunc((char *)toStreamUnit->level);
  if (color != 0) {
    RENDER_currentStreamUnitID = *(short *)&toStreamUnit->StreamUnitID;
    color = GetFogColor(curStreamPortal,mainStreamUnit,mainStreamUnit->level);
    DrawFogRectangle(cliprect,gameTrackerX.primPool,0xbff,curOT,color);
    PushMatrix();
    StreamRenderLevel(toStreamUnit,mainStreamUnit->level,curOT,color);
    PopMatrix();
  }
  return;
}



// decompiled code
// original method signature: 
// struct BSPTree * /*$ra*/ STREAM_GetBspTree(struct _StreamUnit *streamUnit /*$a0*/, long bspNumber /*$a1*/)
 // line 5146, offset 0x8005f474
	/* begin block 1 */
		// Start line: 5148
		// Start offset: 0x8005F474
		// Variables:
	// 		struct Level *level; // $v0
	// 		struct _Terrain *terrain; // $v0
	// 		int d; // $a0
	/* end block 1 */
	// End offset: 0x8005F4CC
	// End Line: 5168

	/* begin block 2 */
		// Start line: 12255
	/* end block 2 */
	// End Line: 12256

	/* begin block 3 */
		// Start line: 12256
	/* end block 3 */
	// End Line: 12257

BSPTree * STREAM_GetBspTree(_StreamUnit *streamUnit,long bspNumber)

{
  _Terrain *p_Var1;
  int iVar2;
  BSPTree *pBVar3;
  int iVar4;
  
  p_Var1 = streamUnit->level->terrain;
  iVar2 = p_Var1->numBSPTrees;
  if ((iVar2 != 0) && (iVar4 = 0, 0 < iVar2)) {
    pBVar3 = p_Var1->BSPTreeArray;
    do {
      iVar4 = iVar4 + 1;
      if ((int)pBVar3->ID == bspNumber) {
        return pBVar3;
      }
      pBVar3 = pBVar3 + 1;
    } while (iVar4 < iVar2);
  }
  return (BSPTree *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_BlockWarpGateEntrance(struct _StreamUnit *streamUnit /*$a0*/, long collideOn /*$s0*/)
 // line 5171, offset 0x8005f4d4
	/* begin block 1 */
		// Start line: 5172
		// Start offset: 0x8005F4D4
		// Variables:
	// 		struct BSPTree *bspTree; // $v1
	/* end block 1 */
	// End offset: 0x8005F534
	// End Line: 5189

	/* begin block 2 */
		// Start line: 12309
	/* end block 2 */
	// End Line: 12310

void WARPGATE_BlockWarpGateEntrance(_StreamUnit *streamUnit,long collideOn)

{
  BSPTree *pBVar1;
  
  pBVar1 = STREAM_GetBspTree(streamUnit,7);
  if (pBVar1 != (BSPTree *)0x0) {
    if (collideOn == 0) {
      pBVar1->flags = pBVar1->flags & 0xfffd;
      WarpGateLoadInfo.blocked = '\x01';
    }
    else {
      pBVar1->flags = pBVar1->flags | 2;
      WarpGateLoadInfo.blocked = '\0';
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_DrawWarpGateRim(struct _StreamUnit *streamUnit /*$a0*/, long drawOn /*$s0*/)
 // line 5192, offset 0x8005f544
	/* begin block 1 */
		// Start line: 5193
		// Start offset: 0x8005F544
		// Variables:
	// 		struct BSPTree *bspTree; // $v1
	/* end block 1 */
	// End offset: 0x8005F58C
	// End Line: 5213

	/* begin block 2 */
		// Start line: 12351
	/* end block 2 */
	// End Line: 12352

void WARPGATE_DrawWarpGateRim(_StreamUnit *streamUnit,long drawOn)

{
  ushort uVar1;
  ushort uVar2;
  BSPTree *pBVar3;
  
  pBVar3 = STREAM_GetBspTree(streamUnit,3);
  if (pBVar3 != (BSPTree *)0x0) {
    uVar1 = pBVar3->flags;
    uVar2 = uVar1 & 0xfffd;
    pBVar3->flags = uVar2;
    if (drawOn == 0) {
      uVar2 = uVar2 | 1;
    }
    else {
      uVar2 = uVar1 & 0xfffc;
    }
    pBVar3->flags = uVar2;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_HideAllCloudCovers()
 // line 5215, offset 0x8005f59c
	/* begin block 1 */
		// Start line: 5217
		// Start offset: 0x8005F59C
		// Variables:
	// 		struct Object *warpFaceObject; // $a1

		/* begin block 1.1 */
			// Start line: 5223
			// Start offset: 0x8005F5B0
			// Variables:
		// 		struct _Instance *instance; // $v1
		// 		struct _Instance *next; // $a0
		/* end block 1.1 */
		// End offset: 0x8005F5F4
		// End Line: 5238
	/* end block 1 */
	// End offset: 0x8005F5F4
	// End Line: 5240

	/* begin block 2 */
		// Start line: 12397
	/* end block 2 */
	// End Line: 12398

	/* begin block 3 */
		// Start line: 12398
	/* end block 3 */
	// End Line: 12399

	/* begin block 4 */
		// Start line: 12401
	/* end block 4 */
	// End Line: 12402

/* WARNING: Removing unreachable block (ram,0x8005f5b0) */
/* WARNING: Removing unreachable block (ram,0x8005f5c8) */
/* WARNING: Removing unreachable block (ram,0x8005f5d8) */
/* WARNING: Removing unreachable block (ram,0x8005f5e8) */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void WARPGATE_HideAllCloudCovers(void)

{
  return;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ WARPGATE_UnHideCloudCoverInUnit(long streamUnitID /*$a0*/)
 // line 5242, offset 0x8005f5fc
	/* begin block 1 */
		// Start line: 5244
		// Start offset: 0x8005F5FC
		// Variables:
	// 		struct Object *warpFaceObject; // $a3
	// 		struct _Instance *result; // $a2

		/* begin block 1.1 */
			// Start line: 5251
			// Start offset: 0x8005F610
			// Variables:
		// 		struct _Instance *instance; // $v1
		// 		struct _Instance *next; // $a1
		/* end block 1.1 */
		// End offset: 0x8005F66C
		// End Line: 5269
	/* end block 1 */
	// End offset: 0x8005F66C
	// End Line: 5271

	/* begin block 2 */
		// Start line: 12453
	/* end block 2 */
	// End Line: 12454

	/* begin block 3 */
		// Start line: 12454
	/* end block 3 */
	// End Line: 12455

	/* begin block 4 */
		// Start line: 12458
	/* end block 4 */
	// End Line: 12459

/* WARNING: Removing unreachable block (ram,0x8005f610) */
/* WARNING: Removing unreachable block (ram,0x8005f628) */
/* WARNING: Removing unreachable block (ram,0x8005f638) */
/* WARNING: Removing unreachable block (ram,0x8005f648) */
/* WARNING: Removing unreachable block (ram,0x8005f660) */

_Instance * WARPGATE_UnHideCloudCoverInUnit(long streamUnitID)

{
  return (_Instance *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_RenderWarpGate(unsigned long **mainOT /*$s3*/, struct StreamUnitPortal *curStreamPortal /*$s2*/, struct _StreamUnit *mainStreamUnit /*$s1*/, struct RECT *cliprect /*$s4*/)
 // line 5275, offset 0x8005f674
	/* begin block 1 */
		// Start line: 5276
		// Start offset: 0x8005F674
		// Variables:
	// 		struct _StreamUnit *toStreamUnit; // $s0
	/* end block 1 */
	// End offset: 0x8005F98C
	// End Line: 5385

	/* begin block 2 */
		// Start line: 12524
	/* end block 2 */
	// End Line: 12525

void STREAM_RenderWarpGate
               (ulong **mainOT,StreamUnitPortal *curStreamPortal,_StreamUnit *mainStreamUnit,
               RECT *cliprect)

{
  int iVar1;
  _StreamUnit *streamUnit;
  
  WARPGATE_DrawWarpGateRim(mainStreamUnit,1);
  streamUnit = curStreamPortal->toStreamUnit;
  if (WarpGateLoadInfo.loading == '\x01') {
    if (WarpGateLoadInfo.maxTime < WarpGateLoadInfo.curTime) {
      if (streamUnit != (_StreamUnit *)0x0) {
        STREAM_DumpUnit(streamUnit,1);
      }
      WarpGateLoadInfo.loading = '\x02';
      STREAM_LoadCurrentWarpRoom(curStreamPortal,mainStreamUnit);
      (WarpGateLoadInfo.warpFaceInstance)->fadeValue = 0;
      return;
    }
    if (WarpGateLoadInfo.warpFaceInstance == (_Instance *)0x0) {
      WARPGATE_HideAllCloudCovers();
      WarpGateLoadInfo.warpFaceInstance =
           WARPGATE_UnHideCloudCoverInUnit(mainStreamUnit->StreamUnitID);
      WarpGateLoadInfo.fadeValue = 0x1000;
    }
    WARPGATE_CalcWarpFade(gameTrackerX.timeMult);
  }
  else {
    if (WarpGateLoadInfo.loading == '\x02') {
      WarpGateLoadInfo.fadeValue = 0;
      if ((streamUnit != (_StreamUnit *)0x0) && (streamUnit->used == 2)) {
        WarpGateLoadInfo.loading = '\x03';
        WarpGateLoadInfo.curTime = WarpGateLoadInfo.maxTime;
      }
    }
    else {
      if (WarpGateLoadInfo.loading == '\x03') {
        if (WarpGateLoadInfo.curTime < 0) {
          WARPGATE_HideAllCloudCovers();
          iVar1 = WARPGATE_IsWarpgateInUse();
          if ((iVar1 == 0) &&
             (iVar1 = strcmpi(gameTrackerX.baseAreaName,(char *)(&WarpRoomArray + CurrentWarpNumber)
                             ), iVar1 == 0)) {
            WarpGateLoadInfo.loading = '\0';
            CurrentWarpNumber = 0;
          }
          else {
            WarpGateLoadInfo.loading = '\x04';
          }
        }
        else {
          WARPGATE_CalcWarpFade(-gameTrackerX.timeMult);
        }
      }
    }
  }
  if (WarpGateLoadInfo.loading == '\0') {
    iVar1 = WARPGATE_IsWarpgateInUse();
    if (iVar1 == 0) {
      WARPGATE_BlockWarpGateEntrance(mainStreamUnit,1);
    }
    else {
      iVar1 = strcmpi(mainStreamUnit->level->worldName,(char *)(&WarpRoomArray + CurrentWarpNumber))
      ;
      if (iVar1 == 0) {
        CurrentWarpNumber = (CurrentWarpNumber + 1) % 0xe;
      }
      WarpGateLoadInfo.loading = '\x01';
      WarpGateLoadInfo.warpFaceInstance = (_Instance *)0x0;
      WarpGateLoadInfo.curTime = 0;
    }
  }
  else {
    if ((streamUnit != (_StreamUnit *)0x0) && (streamUnit->used == 2)) {
      WARPGATE_RenderWarpUnit(mainOT,curStreamPortal,mainStreamUnit,cliprect);
    }
    if ((WarpGateLoadInfo.loading == '\x04') && (iVar1 = WARPGATE_IsWarpgateInUse(), iVar1 == 0)) {
      WarpGateLoadInfo.loading = '\x01';
      WarpGateLoadInfo.curTime = 0;
      WarpGateLoadInfo.warpFaceInstance = (_Instance *)0x0;
      (&WarpRoomArray)[CurrentWarpNumber].streamUnit = (_StreamUnit *)0x0;
      while (iVar1 = strcmpi(gameTrackerX.baseAreaName,(char *)(&WarpRoomArray + CurrentWarpNumber))
            , iVar1 != 0) {
        CurrentWarpNumber = (CurrentWarpNumber + 1) % 0xe;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_RenderWarpUnit(unsigned long **mainOT /*$fp*/, struct StreamUnitPortal *curStreamPortal /*$s0*/, struct _StreamUnit *mainStreamUnit /*$s4*/, struct RECT *cliprect /*$s2*/)
 // line 5388, offset 0x8005f9ac
	/* begin block 1 */
		// Start line: 5389
		// Start offset: 0x8005F9AC
		// Variables:
	// 		unsigned long **curOT; // $s3
	// 		struct DR_AREA *PortalClip; // $s0
	// 		struct _StreamUnit *toStreamUnit; // $s1

		/* begin block 1.1 */
			// Start line: 5422
			// Start offset: 0x8005FA74
			// Variables:
		// 		struct RECT PortalRect; // stack offset -48
		// 		long portalFogColor; // $s0

			/* begin block 1.1.1 */
				// Start line: 5491
				// Start offset: 0x8005FCBC
				// Variables:
			// 		unsigned long *hld; // $a0
			/* end block 1.1.1 */
			// End offset: 0x8005FD54
			// End Line: 5509
		/* end block 1.1 */
		// End offset: 0x8005FD54
		// End Line: 5510
	/* end block 1 */
	// End offset: 0x8005FD54
	// End Line: 5512

	/* begin block 2 */
		// Start line: 12761
	/* end block 2 */
	// End Line: 12762

/* WARNING: Could not reconcile some variable overlaps */

void WARPGATE_RenderWarpUnit
               (ulong **mainOT,StreamUnitPortal *curStreamPortal,_StreamUnit *mainStreamUnit,
               RECT *cliprect)

{
  int iVar1;
  long color;
  ulong *puVar2;
  _StreamUnit *streamUnit;
  ulong **drawot;
  undefined4 local_30;
  undefined4 local_2c;
  
  streamUnit = curStreamPortal->toStreamUnit;
  if ((gameTrackerX.debugFlags2 & 0x1000000U) != 0) {
    FONT_Print("Looking at warp unit =%s\n");
  }
  WARPGATE_BlockWarpGateEntrance(mainStreamUnit,(uint)((streamUnit->flags & 8U) != 0));
  WARPGATE_DrawWarpGateRim(streamUnit,1);
  color = MEMPACK_MemoryValidFunc((char *)streamUnit->level);
  if ((color != 0) &&
     (drawot = (ulong **)(gameTrackerX.primPool)->nextPrim,
     drawot < (gameTrackerX.primPool)->lastPrim + -0xc00)) {
    *(ulong ***)&(gameTrackerX.primPool)->nextPrim = drawot + 0xc00;
    ClearOTagR(drawot,0xc00);
    RENDER_currentStreamUnitID = *(short *)&streamUnit->StreamUnitID;
    curStreamPortal->toStreamUnit = streamUnit;
    color = GetFogColor(curStreamPortal,mainStreamUnit,mainStreamUnit->level);
    DrawFogRectangle(cliprect,gameTrackerX.primPool,0xbff,drawot,color);
    PushMatrix();
    StreamRenderLevel(streamUnit,mainStreamUnit->level,drawot,color);
    PopMatrix();
    puVar2 = (gameTrackerX.primPool)->nextPrim;
    (gameTrackerX.primPool)->nextPrim = puVar2 + 3;
    local_2c = *(undefined4 *)&cliprect->w;
    local_30._0_2_ = (short)*(undefined4 *)cliprect;
    local_30 = CONCAT22((short)((uint)*(undefined4 *)cliprect >> 0x10) +
                        (&draw)[gameTrackerX.drawPage].ofs[1],
                        (short)local_30 + (&draw)[gameTrackerX.drawPage].ofs[0]);
    SetDrawArea((int)puVar2,(ushort *)&local_30);
    *puVar2 = (uint)drawot[0xbfe] & 0xffffff | 0x2000000;
    drawot[0xbfe] = (ulong *)((uint)puVar2 & 0xffffff);
    if ((streamUnit->flags & 8U) == 0) {
      DRAW_TranslucentQuad
                (cliprect->x,cliprect->y,
                 (short)(((uint)(ushort)cliprect->x + (uint)(ushort)cliprect->w) * 0x10000 >> 0x10),
                 cliprect->y,(int)cliprect->x,
                 (int)(((uint)(ushort)cliprect->y + (uint)(ushort)cliprect->h) * 0x10000) >> 0x10,
                 (int)(((uint)(ushort)cliprect->x + (uint)(ushort)cliprect->w) * 0x10000) >> 0x10,
                 (int)(((uint)(ushort)cliprect->y + (uint)(ushort)cliprect->h) * 0x10000) >> 0x10,
                 0x32,0x32,0x32,1,gameTrackerX.primPool,drawot + 1);
      DRAW_TranslucentQuad
                (cliprect->x,cliprect->y,
                 (short)(((uint)(ushort)cliprect->x + (uint)(ushort)cliprect->w) * 0x10000 >> 0x10),
                 cliprect->y,(int)cliprect->x,
                 (int)(((uint)(ushort)cliprect->y + (uint)(ushort)cliprect->h) * 0x10000) >> 0x10,
                 (int)(((uint)(ushort)cliprect->x + (uint)(ushort)cliprect->w) * 0x10000) >> 0x10,
                 (int)(((uint)(ushort)cliprect->y + (uint)(ushort)cliprect->h) * 0x10000) >> 0x10,
                 0x32,0x32,0x32,2,gameTrackerX.primPool,drawot + 1);
    }
    puVar2 = (gameTrackerX.primPool)->nextPrim;
    (gameTrackerX.primPool)->nextPrim = puVar2 + 3;
    local_30 = *(undefined4 *)(&draw)[gameTrackerX.drawPage].ofs;
    local_2c = 0xf00200;
    SetDrawArea((int)puVar2,(ushort *)&local_30);
    *puVar2 = (uint)drawot[1] & 0xffffff | 0x2000000;
    iVar1 = s_zval;
    drawot[1] = (ulong *)((uint)puVar2 & 0xffffff);
    puVar2 = mainOT[iVar1];
    mainOT[iVar1] = drawot[0xbff];
    *drawot = puVar2;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpNonResidentObjects()
 // line 5570, offset 0x8005fd84
	/* begin block 1 */
		// Start line: 5571
		// Start offset: 0x8005FD84
		// Variables:
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 5578
			// Start offset: 0x8005FDB0
			// Variables:
		// 		struct _Instance *next; // $s2
		// 		struct Object *object; // $s1
		/* end block 1.1 */
		// End offset: 0x8005FE04
		// End Line: 5593
	/* end block 1 */
	// End offset: 0x8005FE10
	// End Line: 5596

	/* begin block 2 */
		// Start line: 13168
	/* end block 2 */
	// End Line: 13169

	/* begin block 3 */
		// Start line: 13173
	/* end block 3 */
	// End Line: 13174

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_DumpNonResidentObjects(void)

{
  _Instance *instance;
  _StreamUnit *p_Var1;
  _ObjectTracker *tracker;
  int iVar2;
  Object *object;
  _Instance *p_Var3;
  
  p_Var3 = (gameTrackerX.instanceList)->first;
  while (instance = p_Var3, instance != (_Instance *)0x0) {
    object = instance->object;
    p_Var3 = instance->next;
    if (((object->oflags & 0x2000000U) == 0) &&
       (p_Var1 = STREAM_GetStreamUnitWithID(instance->birthStreamUnitID),
       p_Var1 == (_StreamUnit *)0x0)) {
      tracker = FindObjectInTracker(object);
      iVar2 = STREAM_IsObjectInAnyUnit(tracker);
      if (iVar2 == 0) {
        INSTANCE_ReallyRemoveInstance(gameTrackerX.instanceList,instance,0);
      }
    }
  }
  STREAM_RemoveAllObjectsNotInUse();
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_TryAndDumpNonResident(struct _ObjectTracker *otr /*$s2*/)
 // line 5602, offset 0x8005fe34
	/* begin block 1 */
		// Start line: 5603
		// Start offset: 0x8005FE34
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		struct _Instance *next; // $s1
	/* end block 1 */
	// End offset: 0x8005FF68
	// End Line: 5663

	/* begin block 2 */
		// Start line: 13257
	/* end block 2 */
	// End Line: 13258

int STREAM_TryAndDumpNonResident(_ObjectTracker *otr)

{
  _Instance **pp_Var1;
  _Instance *instance;
  uint uVar2;
  int iVar3;
  _Instance *p_Var4;
  
  uVar2 = 0;
  if ((otr->objectStatus == 2) && (uVar2 = 0, (otr->object->oflags & 0x2000000U) == 0)) {
    iVar3 = STREAM_IsObjectInAnyUnit(otr);
    uVar2 = 0;
    if (iVar3 == 0) {
      p_Var4 = (gameTrackerX.instanceList)->first;
      if (p_Var4 != (_Instance *)0x0) {
        do {
          pp_Var1 = &p_Var4->next;
          if (((p_Var4->object == otr->object) && (p_Var4->LinkParent != (_Instance *)0x0)) &&
             ((p_Var4->object->oflags2 & 0x80000U) == 0)) {
            return 0;
          }
          p_Var4 = *pp_Var1;
        } while (*pp_Var1 != (_Instance *)0x0);
        p_Var4 = (gameTrackerX.instanceList)->first;
      }
      while (instance = p_Var4, instance != (_Instance *)0x0) {
        p_Var4 = instance->next;
        if (instance->object == otr->object) {
          SAVE_DeleteInstance(instance);
          if (instance->LinkChild != (_Instance *)0x0) {
            INSTANCE_ReallyRemoveAllChildren(instance);
            p_Var4 = instance->next;
          }
          INSTANCE_ReallyRemoveInstance(gameTrackerX.instanceList,instance,0);
        }
      }
      STREAM_RemoveAllObjectsNotInUse();
      uVar2 = (uint)(otr->objectStatus == 0);
    }
  }
  return uVar2;
}





