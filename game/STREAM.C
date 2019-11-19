#include "THISDUST.H"
#include "STREAM.H"


// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_FillOutFileNames(char *baseAreaName /*$s0*/, char *dramName /*$s1*/, char *vramName /*$s2*/, char *sfxName /*$s3*/)
 // line 155, offset 0x80059ad0
	/* begin block 1 */
		// Start line: 156
		// Start offset: 0x80059AD0
		// Variables:
	// 		char text[16]; // stack offset -40
	// 		char *number; // $v0
	/* end block 1 */
	// End offset: 0x80059B74
	// End Line: 180

	/* begin block 2 */
		// Start line: 310
	/* end block 2 */
	// End Line: 311

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
// void /*$ra*/ STREAM_AbortAreaLoad(char *baseAreaName /*$a0*/)
 // line 185, offset 0x80059b90
	/* begin block 1 */
		// Start line: 186
		// Start offset: 0x80059B90
		// Variables:
	// 		char vramName[80]; // stack offset -88
	/* end block 1 */
	// End offset: 0x80059B90
	// End Line: 186

	/* begin block 2 */
		// Start line: 373
	/* end block 2 */
	// End Line: 374

void STREAM_AbortAreaLoad(char *baseAreaName)

{
  char acStack88 [80];
  
  STREAM_FillOutFileNames(baseAreaName,(char *)0x0,acStack88,(char *)0x0);
  LOAD_AbortFileLoad(acStack88,VRAM_AbortLoad);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_Init()
 // line 233, offset 0x80059bc8
	/* begin block 1 */
		// Start line: 235
		// Start offset: 0x80059BC8
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x80059BE4
	// End Line: 241

	/* begin block 2 */
		// Start line: 472
	/* end block 2 */
	// End Line: 473

	/* begin block 3 */
		// Start line: 473
	/* end block 3 */
	// End Line: 474

	/* begin block 4 */
		// Start line: 475
	/* end block 4 */
	// End Line: 476

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_Init(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0xf;
  iVar1 = -0x7ff2d1e8;
  do {
    *(undefined2 *)(iVar1 + 4) = 0;
    iVar2 = iVar2 + -1;
    iVar1 = iVar1 + -0x40;
  } while (-1 < iVar2);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ FindObjectName(char *name /*$s2*/)
 // line 243, offset 0x80059bec
	/* begin block 1 */
		// Start line: 244
		// Start offset: 0x80059BEC
		// Variables:
	// 		int i; // $s0
	// 		struct _ObjectTracker *otr; // $s1
	/* end block 1 */
	// End offset: 0x80059C40
	// End Line: 255

	/* begin block 2 */
		// Start line: 494
	/* end block 2 */
	// End Line: 495

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
 // line 257, offset 0x80059c58
	/* begin block 1 */
		// Start line: 259
		// Start offset: 0x80059C58
		// Variables:
	// 		int i; // $a2
	// 		struct _ObjectTracker *otr; // $a1
	/* end block 1 */
	// End offset: 0x80059CA0
	// End Line: 267

	/* begin block 2 */
		// Start line: 532
	/* end block 2 */
	// End Line: 533

	/* begin block 3 */
		// Start line: 533
	/* end block 3 */
	// End Line: 534

	/* begin block 4 */
		// Start line: 536
	/* end block 4 */
	// End Line: 537

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
 // line 285, offset 0x80059ca8
	/* begin block 1 */
		// Start line: 287
		// Start offset: 0x80059CA8
		// Variables:
	// 		struct _StreamUnit *ret; // $a2
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x80059CF4
	// End Line: 299

	/* begin block 2 */
		// Start line: 567
	/* end block 2 */
	// End Line: 568

	/* begin block 3 */
		// Start line: 572
	/* end block 3 */
	// End Line: 573

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
 // line 355, offset 0x80059cfc
	/* begin block 1 */
		// Start line: 356
		// Start offset: 0x80059CFC
		// Variables:
	// 		struct Object *object; // $s0
	// 		struct _ObjectTracker *objectTracker; // $s1

		/* begin block 1.1 */
			// Start line: 394
			// Start offset: 0x80059D88
			// Variables:
		// 		char objDsfxFileName[64]; // stack offset -80
		/* end block 1.1 */
		// End offset: 0x80059DD8
		// End Line: 406
	/* end block 1 */
	// End offset: 0x80059DD8
	// End Line: 407

	/* begin block 2 */
		// Start line: 716
	/* end block 2 */
	// End Line: 717

void STREAM_LoadObjectReturn(void *loadData,void *data,void *data2)

{
  ushort uVar1;
  long lVar2;
  char acStack80 [64];
  
  GetRCnt(0xf2000000);
  if ((((*(uint *)loadData & 0x8000000) != 0) && (*(int **)((int)loadData + 0x3c) != (int *)0x0)) &&
     (*(int *)((int)loadData + 0x40) != 0)) {
    RELMOD_InitModulePointers(*(int *)((int)loadData + 0x40),*(int **)((int)loadData + 0x3c));
  }
  OBTABLE_InitAnimPointers((_ObjectTracker *)data);
  OBTABLE_InitObjectWithID((Object *)loadData);
  STREAM_PackVRAMObject((_ObjectTracker *)data);
  if ((*(uint *)((int)loadData + 0x2c) & 0x800000) != 0) {
    sprintf(acStack80,"\\kain2\\sfx\\object\\%s\\%s.snf");
    *(undefined2 *)((int)loadData + 6) = 0;
    lVar2 = LOAD_DoesFileExist(acStack80);
    if (lVar2 != 0) {
      uVar1 = aadLoadDynamicSfx(acStack80,0,(TDRFuncPtr_aadLoadDynamicSfx2userReturnProc)0x0);
      *(ushort *)((int)loadData + 6) = uVar1;
      GXFilePrint("Loading object %s sfx. Handle=%x\n");
    }
  }
  *(undefined2 *)((int)data + 0x14) = 2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpMonster(struct _ObjectTracker *dumpee /*$s2*/)
 // line 414, offset 0x80059df4
	/* begin block 1 */
		// Start line: 415
		// Start offset: 0x80059DF4
		// Variables:
	// 		struct Object *object; // $s1
	// 		struct _Instance *instance; // $a1

		/* begin block 1.1 */
			// Start line: 435
			// Start offset: 0x80059E74
			// Variables:
		// 		struct _Instance *next; // $s0
		/* end block 1.1 */
		// End offset: 0x80059E90
		// End Line: 442
	/* end block 1 */
	// End offset: 0x80059E9C
	// End Line: 445

	/* begin block 2 */
		// Start line: 834
	/* end block 2 */
	// End Line: 835

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
  if (((object->oflags2 & 0x800000U) != 0) && (object->sfxFileHandle != 0)) {
    aadFreeDynamicSfx(object->sfxFileHandle);
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
 // line 454, offset 0x80059ec0
	/* begin block 1 */
		// Start line: 455
		// Start offset: 0x80059EC0
		// Variables:
	// 		char **mon; // $s0
	/* end block 1 */
	// End offset: 0x80059F14
	// End Line: 463

	/* begin block 2 */
		// Start line: 929
	/* end block 2 */
	// End Line: 930

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
 // line 465, offset 0x80059f28
	/* begin block 1 */
		// Start line: 466
		// Start offset: 0x80059F28
		// Variables:
	// 		static char (*mon[6]); // offset 0x0
	/* end block 1 */
	// End offset: 0x80059F28
	// End Line: 466

	/* begin block 2 */
		// Start line: 953
	/* end block 2 */
	// End Line: 954

int STREAM_IsSpecialMonster(char *name)

{
  int iVar1;
  
  iVar1 = STREAM_InList(name,&PTR_s_wallcr_800c5950);
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpSomeMonsters()
 // line 473, offset 0x80059f4c
	/* begin block 1 */
		// Start line: 474
		// Start offset: 0x80059F4C
		// Variables:
	// 		struct _ObjectTracker *otr; // $s0
	// 		int i; // $s2
	/* end block 1 */
	// End offset: 0x80059FD4
	// End Line: 489

	/* begin block 2 */
		// Start line: 973
	/* end block 2 */
	// End Line: 974

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_DumpSomeMonsters(void)

{
  int iVar1;
  _ObjectTracker *dumpee;
  Object **ppOVar2;
  int iVar3;
  
  iVar3 = 0;
  ppOVar2 = &(gameTrackerX.GlobalObjects)->object;
  dumpee = gameTrackerX.GlobalObjects;
  do {
    if (((*(short *)(ppOVar2 + 1) == 2) && (*ppOVar2 != (Object *)0x0)) &&
       (iVar1 = STREAM_IsSpecialMonster((char *)dumpee), iVar1 != 0)) {
      printf("NO INTRODUCE MONSTER FLAG: Dumping monster %s\n");
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
 // line 490, offset 0x80059ff4
	/* begin block 1 */
		// Start line: 1030
	/* end block 1 */
	// End Line: 1031

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
 // line 496, offset 0x8005a024
	/* begin block 1 */
		// Start line: 1044
	/* end block 1 */
	// End Line: 1045

	/* begin block 2 */
		// Start line: 1046
	/* end block 2 */
	// End Line: 1047

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_YesMonsters(void)

{
  gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xfbffffff;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_IsMonster(char *name /*$a0*/)
 // line 503, offset 0x8005a040
	/* begin block 1 */
		// Start line: 504
		// Start offset: 0x8005A040
		// Variables:
	// 		static char (*monnames[19]); // offset 0x18
	/* end block 1 */
	// End offset: 0x8005A040
	// End Line: 504

	/* begin block 2 */
		// Start line: 1058
	/* end block 2 */
	// End Line: 1059

int STREAM_IsMonster(char *name)

{
  int iVar1;
  
  iVar1 = STREAM_InList(name,&PTR_s_skinner_800c5968);
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpAMonster(int needed /*$s6*/)
 // line 512, offset 0x8005a064
	/* begin block 1 */
		// Start line: 513
		// Start offset: 0x8005A064

		/* begin block 1.1 */
			// Start line: 516
			// Start offset: 0x8005A0A8
			// Variables:
		// 		struct _ObjectTracker *dumpee; // $s4
		// 		struct _ObjectTracker *otr; // $s1
		// 		int biggest; // $s3
		// 		int i; // $s2
		/* end block 1.1 */
		// End offset: 0x8005A12C
		// End Line: 536
	/* end block 1 */
	// End offset: 0x8005A148
	// End Line: 542

	/* begin block 2 */
		// Start line: 1081
	/* end block 2 */
	// End Line: 1082

void STREAM_DumpAMonster(int needed)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  _ObjectTracker *p_Var4;
  _ObjectTracker *name;
  ulong uVar5;
  _ObjectTracker *dumpee;
  
  while( true ) {
    iVar1 = MEMPACK_AvailableMemory();
    dumpee = (_ObjectTracker *)0x0;
    if (needed + 0x2000 <= iVar1) break;
    uVar5 = 0;
    iVar1 = 0;
    p_Var4 = gameTrackerX.GlobalObjects;
    name = gameTrackerX.GlobalObjects;
    do {
      if ((((p_Var4->objectStatus == 2) && (p_Var4->object != (Object *)0x0)) &&
          (iVar2 = STREAM_IsMonster((char *)name), iVar2 != 0)) &&
         (uVar3 = MEMPACK_Size((char *)p_Var4->object), uVar5 < uVar3)) {
        uVar5 = MEMPACK_Size((char *)p_Var4->object);
        dumpee = p_Var4;
      }
      iVar1 = iVar1 + 1;
      p_Var4 = p_Var4 + 1;
      name = name + 1;
    } while (iVar1 < 0x30);
    if (dumpee == (_ObjectTracker *)0x0) break;
    printf("LOW MEMORY: Dumping monster %s\n");
    STREAM_DumpMonster(dumpee);
  }
  MEMPACK_DoGarbageCollection();
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ InsertGlobalObject(char *name /*$s2*/, struct GameTracker *gameTracker /*$s3*/)
 // line 546, offset 0x8005a178
	/* begin block 1 */
		// Start line: 547
		// Start offset: 0x8005A178
		// Variables:
	// 		char string[64]; // stack offset -152
	// 		char vramname[64]; // stack offset -88
	// 		int i; // $s1
	// 		struct _ObjectTracker *otr; // $s0
	/* end block 1 */
	// End offset: 0x8005A2E0
	// End Line: 627

	/* begin block 2 */
		// Start line: 1158
	/* end block 2 */
	// End Line: 1159

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
    if (iVar1 == 0x30) {
      DEBUG_FatalError("The Object tracker is full MAX_OBJECTS=%d.\n");
      iVar1 = -1;
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
 // line 638, offset 0x8005a300
	/* begin block 1 */
		// Start line: 639
		// Start offset: 0x8005A300
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x8005A340
	// End Line: 644

	/* begin block 2 */
		// Start line: 1273
	/* end block 2 */
	// End Line: 1274

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
// void /*$ra*/ LoadLevelObjects(struct Level *level /*$s2*/, struct GameTracker *gameTracker /*$s3*/)
 // line 646, offset 0x8005a350
	/* begin block 1 */
		// Start line: 647
		// Start offset: 0x8005A350
		// Variables:
	// 		unsigned char *objlist; // $s0

		/* begin block 1.1 */
			// Start line: 659
			// Start offset: 0x8005A3A8
			// Variables:
		// 		int i; // $s1
		/* end block 1.1 */
		// End offset: 0x8005A424
		// End Line: 677
	/* end block 1 */
	// End offset: 0x8005A424
	// End Line: 678

	/* begin block 2 */
		// Start line: 1367
	/* end block 2 */
	// End Line: 1368

void LoadLevelObjects(Level *level,GameTracker *gameTracker)

{
  char cVar1;
  int iVar2;
  char *name;
  int iVar3;
  int iVar4;
  
  name = (char *)level->objectNameList;
  cVar1 = *name;
  while (cVar1 != -1) {
    InsertGlobalObject(name,gameTracker);
    name = name + 0x10;
    cVar1 = *name;
  }
  iVar4 = 0;
  if (0 < level->numIntros) {
    iVar3 = 0;
    do {
      iVar2 = FindObjectName(level->introList->name + iVar3);
      if (iVar2 == -1) {
        name = level->introList->name + iVar3;
        *(uint *)(name + 0x2c) = *(uint *)(name + 0x2c) | 0x4000;
      }
      else {
        name = level->introList->name + iVar3;
        *(uint *)(name + 0x2c) = *(uint *)(name + 0x2c) & 0xffffbfff;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x4c;
    } while (iVar4 < level->numIntros);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ STREAM_IsAnInstanceUsingObject(struct Object *object /*$a0*/)
 // line 681, offset 0x8005a440
	/* begin block 1 */
		// Start line: 683
		// Start offset: 0x8005A440
		// Variables:
	// 		struct _Instance *instance; // $v1
	// 		struct _Instance *next; // $v1
	// 		long ret; // $a1
	/* end block 1 */
	// End offset: 0x8005A478
	// End Line: 699

	/* begin block 2 */
		// Start line: 1452
	/* end block 2 */
	// End Line: 1453

	/* begin block 3 */
		// Start line: 1453
	/* end block 3 */
	// End Line: 1454

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
 // line 702, offset 0x8005a480
	/* begin block 1 */
		// Start line: 703
		// Start offset: 0x8005A480
		// Variables:
	// 		struct _ObjectTracker *objectTracker; // $s0
	/* end block 1 */
	// End offset: 0x8005A49C
	// End Line: 707

	/* begin block 2 */
		// Start line: 1496
	/* end block 2 */
	// End Line: 1497

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
// void /*$ra*/ STREAM_DumpObject(struct _ObjectTracker *objectTracker /*$s1*/)
 // line 713, offset 0x8005a4b0
	/* begin block 1 */
		// Start line: 714
		// Start offset: 0x8005A4B0
		// Variables:
	// 		struct Object *object; // $s0

		/* begin block 1.1 */
			// Start line: 721
			// Start offset: 0x8005A4D8
			// Variables:
		// 		char dramName[64]; // stack offset -80
		/* end block 1.1 */
		// End offset: 0x8005A504
		// End Line: 725
	/* end block 1 */
	// End offset: 0x8005A588
	// End Line: 757

	/* begin block 2 */
		// Start line: 1519
	/* end block 2 */
	// End Line: 1520

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
        if (((object->oflags2 & 0x800000U) != 0) && (object->sfxFileHandle != 0)) {
          aadFreeDynamicSfx(object->sfxFileHandle);
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
 // line 760, offset 0x8005a59c
	/* begin block 1 */
		// Start line: 761
		// Start offset: 0x8005A59C
		// Variables:
	// 		int d; // $s1

		/* begin block 1.1 */
			// Start line: 768
			// Start offset: 0x8005A5EC
			// Variables:
		// 		unsigned char *objlist; // $s0
		/* end block 1.1 */
		// End offset: 0x8005A630
		// End Line: 778
	/* end block 1 */
	// End offset: 0x8005A644
	// End Line: 781

	/* begin block 2 */
		// Start line: 1622
	/* end block 2 */
	// End Line: 1623

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
// void /*$ra*/ STREAM_RemoveAllObjectsNotInUse(struct GameTracker *gameTracker /*$a0*/)
 // line 783, offset 0x8005a660
	/* begin block 1 */
		// Start line: 784
		// Start offset: 0x8005A660
		// Variables:
	// 		int i; // $s3
	// 		int abort; // $a3
	// 		struct _ObjectTracker *tracker; // $s1
	// 		struct _ObjectTracker *trackerList; // $s4

		/* begin block 1.1 */
			// Start line: 793
			// Start offset: 0x8005A6AC
			// Variables:
		// 		struct Object *object; // $s2
		/* end block 1.1 */
		// End offset: 0x8005A6EC
		// End Line: 808

		/* begin block 1.2 */
			// Start line: 816
			// Start offset: 0x8005A728
			// Variables:
		// 		int j; // $a0
		/* end block 1.2 */
		// End offset: 0x8005A784
		// End Line: 829

		/* begin block 1.3 */
			// Start line: 837
			// Start offset: 0x8005A7B8
			// Variables:
		// 		int j; // $t0
		// 		struct _ObjectTracker *otr; // $a3

			/* begin block 1.3.1 */
				// Start line: 841
				// Start offset: 0x8005A7D8
				// Variables:
			// 		int k; // $a0

				/* begin block 1.3.1.1 */
					// Start line: 848
					// Start offset: 0x8005A7FC
					// Variables:
				// 		int l; // $a1
				/* end block 1.3.1.1 */
				// End offset: 0x8005A848
				// End Line: 855
			/* end block 1.3.1 */
			// End offset: 0x8005A860
			// End Line: 857
		/* end block 1.3 */
		// End offset: 0x8005A87C
		// End Line: 860
	/* end block 1 */
	// End offset: 0x8005A8E8
	// End Line: 878

	/* begin block 2 */
		// Start line: 1685
	/* end block 2 */
	// End Line: 1686

void STREAM_RemoveAllObjectsNotInUse(GameTracker *gameTracker)

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
  
  iVar11 = 0;
  tracker = gameTracker->GlobalObjects;
  psVar9 = &tracker->objectStatus;
  tracker_00 = tracker;
  do {
    if ((((*psVar9 == 2) && (object = *(Object **)(psVar9 + -2), (object->oflags & 0x2000000U) == 0)
         ) && (iVar3 = STREAM_IsObjectInAnyUnit(tracker_00), iVar3 == 0)) &&
       (lVar4 = STREAM_IsAnInstanceUsingObject(object), lVar4 == 0)) {
      *psVar9 = 3;
    }
    iVar11 = iVar11 + 1;
    psVar9 = psVar9 + 0x12;
    tracker_00 = tracker_00 + 1;
  } while (iVar11 < 0x30);
  do {
    bVar2 = true;
    iVar11 = 0;
    psVar9 = &tracker->objectStatus;
    tracker_00 = tracker;
    do {
      if (*psVar9 == 3) {
        iVar3 = 0;
        p_Var5 = tracker_00;
        if (0 < (int)*(char *)(psVar9 + 4)) {
          do {
            if (tracker[p_Var5->objectsUsing[0]].objectStatus != 3) {
              *psVar9 = 2;
              bVar2 = false;
              break;
            }
            iVar3 = iVar3 + 1;
            p_Var5 = (_ObjectTracker *)(tracker_00->name + iVar3);
          } while (iVar3 < (int)*(char *)(psVar9 + 4));
        }
      }
      iVar11 = iVar11 + 1;
      psVar9 = psVar9 + 0x12;
      tracker_00 = tracker_00 + 1;
    } while (iVar11 < 0x30);
  } while (!bVar2);
  iVar11 = 0;
  tracker_00 = tracker;
  do {
    if (tracker_00->objectStatus == 3) {
      iVar3 = 0;
      pcVar10 = &tracker->numObjectsUsing;
      p_Var5 = tracker;
      do {
        if ((uint)*(ushort *)(pcVar10 + -8) - 1 < 2) {
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
      STREAM_DumpObject(tracker_00);
    }
    iVar11 = iVar11 + 1;
    tracker_00 = tracker_00 + 1;
    if (0x2f < iVar11) {
      iVar11 = 0;
      pcVar10 = &tracker->numObjectsUsing;
      do {
        if (((*(short *)(pcVar10 + -8) == 1) &&
            (iVar3 = STREAM_IsObjectInAnyUnit(tracker), iVar3 == 0)) && (*pcVar10 == '\0')) {
          STREAM_DumpObject(tracker);
        }
        iVar11 = iVar11 + 1;
        pcVar10 = pcVar10 + 0x24;
        tracker = tracker + 1;
      } while (iVar11 < 0x30);
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ RemoveAllObjects(struct GameTracker *gameTracker /*$a0*/)
 // line 881, offset 0x8005a910
	/* begin block 1 */
		// Start line: 882
		// Start offset: 0x8005A910
		// Variables:
	// 		int i; // $s1
	// 		struct _ObjectTracker *tracker; // $s0
	/* end block 1 */
	// End offset: 0x8005A954
	// End Line: 892

	/* begin block 2 */
		// Start line: 1999
	/* end block 2 */
	// End Line: 2000

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
 // line 897, offset 0x8005a968
	/* begin block 1 */
		// Start line: 899
		// Start offset: 0x8005A968
		// Variables:
	// 		struct Level *retLevel; // $a2
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x8005A9B8
	// End Line: 913

	/* begin block 2 */
		// Start line: 2039
	/* end block 2 */
	// End Line: 2040

	/* begin block 3 */
		// Start line: 2040
	/* end block 3 */
	// End Line: 2041

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
 // line 916, offset 0x8005a9c4
	/* begin block 1 */
		// Start line: 918
		// Start offset: 0x8005A9C4
		// Variables:
	// 		struct _StreamUnit *retUnit; // $a2
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x8005AA10
	// End Line: 930

	/* begin block 2 */
		// Start line: 2084
	/* end block 2 */
	// End Line: 2085

	/* begin block 3 */
		// Start line: 2085
	/* end block 3 */
	// End Line: 2086

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
 // line 933, offset 0x8005aa18
	/* begin block 1 */
		// Start line: 934
		// Start offset: 0x8005AA18
		// Variables:
	// 		struct _Terrain *terrain; // $t2
	// 		int i; // $t0
	// 		struct _TFace *tface; // $a3
	// 		long waterZLevel; // $t1
	/* end block 1 */
	// End offset: 0x8005AB40
	// End Line: 987

	/* begin block 2 */
		// Start line: 2124
	/* end block 2 */
	// End Line: 2125

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
          iVar1 = (int)p_Var2[(p_Var4->face)._2].vertex.z;
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
    level->waterZLevel = iVar7 + *(short *)(level->terrain->signals->signalList[0].data + 4);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_IsMorphInProgress()
 // line 992, offset 0x8005ab48
	/* begin block 1 */
		// Start line: 2258
	/* end block 1 */
	// End Line: 2259

	/* begin block 2 */
		// Start line: 2259
	/* end block 2 */
	// End Line: 2260

/* WARNING: Unknown calling convention yet parameter storage is locked */

int STREAM_IsMorphInProgress(void)

{
  return (uint)(gameTrackerX.gameData.asmData.MorphTime != 1000);
}



// decompiled code
// original method signature: 
// long /*$ra*/ STREAM_GetWaterZLevel(struct Level *level /*$a0*/, struct _Instance *instance /*$a1*/)
 // line 998, offset 0x8005ab5c
	/* begin block 1 */
		// Start line: 1000
		// Start offset: 0x8005AB5C
		// Variables:
	// 		long waterZLevel; // $a1
	/* end block 1 */
	// End offset: 0x8005ABD4
	// End Line: 1025

	/* begin block 2 */
		// Start line: 2270
	/* end block 2 */
	// End Line: 2271

	/* begin block 3 */
		// Start line: 2271
	/* end block 3 */
	// End Line: 2272

	/* begin block 4 */
		// Start line: 2273
	/* end block 4 */
	// End Line: 2274

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
 // line 1028, offset 0x8005abdc
	/* begin block 1 */
		// Start line: 1030
		// Start offset: 0x8005ABDC
		// Variables:
	// 		struct Level *level; // $v1
	/* end block 1 */
	// End offset: 0x8005AC1C
	// End Line: 1045

	/* begin block 2 */
		// Start line: 2330
	/* end block 2 */
	// End Line: 2331

	/* begin block 3 */
		// Start line: 2331
	/* end block 3 */
	// End Line: 2332

	/* begin block 4 */
		// Start line: 2335
	/* end block 4 */
	// End Line: 2336

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
 // line 1049, offset 0x8005ac30
	/* begin block 1 */
		// Start line: 1050
		// Start offset: 0x8005AC30
	/* end block 1 */
	// End offset: 0x8005ACA0
	// End Line: 1062

	/* begin block 2 */
		// Start line: 2375
	/* end block 2 */
	// End Line: 2376

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
// void /*$ra*/ STREAM_ConnectStream(struct _StreamUnit *streamUnit /*$s3*/)
 // line 1106, offset 0x8005acc0
	/* begin block 1 */
		// Start line: 1107
		// Start offset: 0x8005ACC0
		// Variables:
	// 		struct _StreamUnit *mainUnit; // $s7
	// 		struct StreamUnitPortal *streamPortal; // $a0
	// 		int numportals; // $v1
	// 		struct StreamUnitPortal *streamPortal2; // $s5
	// 		int numportals2; // $s6
	// 		int i; // $s0
	// 		int j; // $s4
	// 		int connect_to_main; // $s0
	// 		char text[16]; // stack offset -64
	// 		char *commapos; // $v0
	// 		int signalID; // $s2

		/* begin block 1.1 */
			// Start line: 1172
			// Start offset: 0x8005AE5C
			// Variables:
		// 		struct _SVector offset; // stack offset -48
		/* end block 1.1 */
		// End offset: 0x8005AE5C
		// End Line: 1186
	/* end block 1 */
	// End offset: 0x8005AEF8
	// End Line: 1201

	/* begin block 2 */
		// Start line: 2499
	/* end block 2 */
	// End Line: 2500

void STREAM_ConnectStream(_StreamUnit *streamUnit)

{
  bool bVar1;
  _StreamUnit *p_Var2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  Level *pLVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int *__src;
  int iVar12;
  char acStack64 [16];
  _SVector local_30;
  
  WARPGATE_UpdateAddToArray(streamUnit);
  if (gameTrackerX.StreamUnitID != streamUnit->StreamUnitID) {
    iVar11 = 0;
    p_Var2 = STREAM_GetStreamUnitWithID(gameTrackerX.StreamUnitID);
    piVar10 = (int *)p_Var2->level->terrain->StreamUnits;
    iVar12 = *piVar10;
    __src = piVar10 + 1;
    if (0 < iVar12) {
      piVar10 = piVar10 + 8;
      do {
        bVar1 = false;
        strcpy(acStack64,(char *)__src);
        pcVar3 = strchr(acStack64,0x2c);
        if (pcVar3 == (char *)0x0) {
          GXFilePrint("Couldn\'t find signalnumber.");
          iVar4 = 0;
        }
        else {
          *pcVar3 = '\0';
          iVar4 = atoi(pcVar3 + 1);
        }
        iVar5 = strcmpi(acStack64,streamUnit->baseAreaName);
        if (iVar5 == 0) {
          bVar1 = true;
        }
        else {
          iVar5 = strcmpi(acStack64,"warpgate");
          if ((iVar5 == 0) && (lVar6 = WARPGATE_IsUnitWarpRoom(streamUnit), lVar6 != 0)) {
            bVar1 = true;
          }
        }
        if (bVar1) {
          piVar8 = (int *)streamUnit->level->terrain->StreamUnits;
          iVar9 = 0;
          iVar5 = *piVar8;
          piVar8 = piVar8 + 1;
          if (0 < iVar5) {
            do {
              iVar9 = iVar9 + 1;
              if (iVar4 == piVar8[4]) {
                *(_StreamUnit **)(piVar10 + 3) = streamUnit;
                *(_StreamUnit **)(piVar8 + 10) = p_Var2;
                local_30.x = *(short *)(piVar10 + -1) - *(short *)(piVar8 + 6);
                local_30.y = *(short *)((int)piVar10 + -2) - *(short *)((int)piVar8 + 0x1a);
                local_30.z = *(short *)piVar10 - *(short *)(piVar8 + 7);
                RelocateLevel(streamUnit->level,&local_30);
                break;
              }
              piVar8 = piVar8 + 0x17;
            } while (iVar9 < iVar5);
          }
        }
        piVar10 = piVar10 + 0x17;
        iVar11 = iVar11 + 1;
        __src = __src + 0x17;
      } while (iVar11 < iVar12);
    }
    pLVar7 = streamUnit->level;
    iVar11 = 0;
    if (0 < pLVar7->numIntros) {
      iVar12 = 0;
      do {
        iVar4 = strcmpi(pLVar7->introList->name + iVar12,"raziel");
        iVar11 = iVar11 + 1;
        if (iVar4 == 0) {
          pcVar3 = streamUnit->level->introList->name + iVar12;
          *(uint *)(pcVar3 + 0x2c) = *(uint *)(pcVar3 + 0x2c) | 8;
          return;
        }
        pLVar7 = streamUnit->level;
        iVar12 = iVar12 + 0x4c;
      } while (iVar11 < pLVar7->numIntros);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_StreamLoadLevelAbort(void *loadData /*$a0*/, void *data /*$a1*/, void *data2 /*$a2*/)
 // line 1203, offset 0x8005af24
	/* begin block 1 */
		// Start line: 1204
		// Start offset: 0x8005AF24
		// Variables:
	// 		struct _StreamUnit *streamUnit; // $s0
	/* end block 1 */
	// End offset: 0x8005AF40
	// End Line: 1208

	/* begin block 2 */
		// Start line: 2815
	/* end block 2 */
	// End Line: 2816

void STREAM_StreamLoadLevelAbort(void *loadData,void *data,void *data2)

{
  if (loadData != (void *)0x0) {
    MEMPACK_Free((char *)loadData);
  }
  *(undefined4 *)((int)data2 + 8) = 0;
  *(undefined2 *)((int)data2 + 4) = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_FinishLoad(struct _StreamUnit *streamUnit /*$s1*/)
 // line 1212, offset 0x8005af58
	/* begin block 1 */
		// Start line: 1213
		// Start offset: 0x8005AF58
		// Variables:
	// 		struct Level *level; // $s0
	// 		char sfxName[80]; // stack offset -96
	/* end block 1 */
	// End offset: 0x8005B058
	// End Line: 1275

	/* begin block 2 */
		// Start line: 2834
	/* end block 2 */
	// End Line: 2835

void STREAM_FinishLoad(_StreamUnit *streamUnit)

{
  ushort uVar1;
  long lVar2;
  _MultiSignal *p_Var3;
  Level *level;
  char acStack96 [80];
  
  STREAM_FillOutFileNames(streamUnit->baseAreaName,(char *)0x0,(char *)0x0,acStack96);
  level = streamUnit->level;
  level->morphLastStep = -1;
  streamUnit->sfxFileHandle = 0;
  lVar2 = LOAD_DoesFileExist(acStack96);
  if (lVar2 != 0) {
    uVar1 = aadLoadDynamicSfx(acStack96,streamUnit->StreamUnitID,
                              (TDRFuncPtr_aadLoadDynamicSfx2userReturnProc)0x0);
    streamUnit->sfxFileHandle = uVar1;
  }
  LoadLevelObjects(level,&gameTrackerX);
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
  EVENT_LoadEventsForLevel(streamUnit->StreamUnitID,level);
  PLANAPI_InitPlanMkrList(streamUnit);
  p_Var3 = level->startUnitLoadedSignal;
  if (p_Var3 != (_MultiSignal *)0x0) {
    p_Var3->flags = p_Var3->flags | 1;
    SIGNAL_HandleSignal(gameTrackerX.playerInstance,level->startUnitLoadedSignal->signalList,0);
  }
  SAVE_IntroForStreamID(streamUnit->StreamUnitID,streamUnit->level);
  SAVE_UpdateLevelWithSave(streamUnit);
  EVENT_AddStreamToInstanceList(streamUnit);
  WARPGATE_FixUnit(streamUnit);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_LoadLevelReturn(void *loadData /*$s0*/, void *data /*$a1*/, void *data2 /*$s1*/)
 // line 1289, offset 0x8005b094
	/* begin block 1 */
		// Start line: 1290
		// Start offset: 0x8005B094
	/* end block 1 */
	// End offset: 0x8005B0DC
	// End Line: 1308

	/* begin block 2 */
		// Start line: 3002
	/* end block 2 */
	// End Line: 3003

void STREAM_LoadLevelReturn(void *loadData,void *data,void *data2)

{
  GetRCnt(0xf2000000);
  if (*(int *)((int)loadData + 0xf0) != 0x3c204139) {
    GXFilePrint("Wrong version number %x for level %s.\n");
  }
  *(undefined4 *)data2 = *(undefined4 *)((int)loadData + 0xf8);
  gameTrackerX.StreamUnitID = *(long *)((int)loadData + 0xf8);
  gameTrackerX.level = (Level *)loadData;
  GAMELOOP_InitLevelTimeOfDay((Level *)loadData);
  STREAM_SetMainFog((_StreamUnit *)data2);
  STREAM_FinishLoad((_StreamUnit *)data2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_StreamLoadLevelReturn(void *loadData /*$s0*/, void *data /*$a1*/, void *data2 /*$s1*/)
 // line 1322, offset 0x8005b124
	/* begin block 1 */
		// Start line: 1323
		// Start offset: 0x8005B124
		// Variables:
	// 		struct Level *level; // $s0
	// 		struct _StreamUnit *streamUnit; // $s1
	/* end block 1 */
	// End offset: 0x8005B220
	// End Line: 1417

	/* begin block 2 */
		// Start line: 3077
	/* end block 2 */
	// End Line: 3078

void STREAM_StreamLoadLevelReturn(void *loadData,void *data,void *data2)

{
  short fogNear;
  short fogFar;
  
  GetRCnt(0xf2000000);
  if (*(int *)((int)loadData + 0xf0) != 0x3c204139) {
    GXFilePrint("Wrong version number for level %s.\n");
  }
  *(undefined4 *)data2 = *(undefined4 *)((int)loadData + 0xf8);
  if (*(short *)((int)data2 + 4) == 3) {
    *(undefined2 *)((int)data2 + 4) = 0;
    MEMPACK_Free(*(char **)((int)data2 + 8));
    *(undefined4 *)((int)data2 + 8) = 0;
  }
  else {
    GAMELOOP_InitLevelTimeOfDay((Level *)loadData);
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
 // line 1444, offset 0x8005b234
	/* begin block 1 */
		// Start line: 1446
		// Start offset: 0x8005B234
		// Variables:
	// 		long i; // $a3
	// 		long offset; // $t0
	// 		struct GameTracker *gameTracker; // $v0

		/* begin block 1.1 */
			// Start line: 1473
			// Start offset: 0x8005B294
			// Variables:
		// 		struct _Instance *instance; // $a1
		/* end block 1.1 */
		// End offset: 0x8005B3FC
		// End Line: 1509
	/* end block 1 */
	// End offset: 0x8005B4E4
	// End Line: 1531

	/* begin block 2 */
		// Start line: 2885
	/* end block 2 */
	// End Line: 2886

	/* begin block 3 */
		// Start line: 3303
	/* end block 3 */
	// End Line: 3304

	/* begin block 4 */
		// Start line: 3307
	/* end block 4 */
	// End Line: 3308

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
LAB_8005b280:
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
      return;
    }
  }
  pSVar6->StreamList[0].level = newLevel;
  goto LAB_8005b280;
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ STREAM_WhichUnitPointerIsIn(void *pointer /*$s3*/)
 // line 1534, offset 0x8005b4ec
	/* begin block 1 */
		// Start line: 1535
		// Start offset: 0x8005B4EC
		// Variables:
	// 		int i; // $s2
	// 		int size; // $v1
	// 		struct Level *level; // $s0
	/* end block 1 */
	// End offset: 0x8005B57C
	// End Line: 1555

	/* begin block 2 */
		// Start line: 3497
	/* end block 2 */
	// End Line: 3498

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
 // line 1557, offset 0x8005b59c
	/* begin block 1 */
		// Start line: 1558
		// Start offset: 0x8005B59C
		// Variables:
	// 		long i; // $a3
	// 		long d; // $a1
	// 		struct GameTracker *gameTracker; // $s0
	// 		long offset; // $s1
	// 		struct _ObjectTracker *otr; // $t0

		/* begin block 1.1 */
			// Start line: 1578
			// Start offset: 0x8005B5F4
			// Variables:
		// 		int j; // $a1
		// 		struct Object *object; // $a2
		/* end block 1.1 */
		// End offset: 0x8005B680
		// End Line: 1588

		/* begin block 1.2 */
			// Start line: 1606
			// Start offset: 0x8005B6DC
			// Variables:
		// 		struct _Instance *instance; // $s0
		/* end block 1.2 */
		// End offset: 0x8005B7F4
		// End Line: 1635
	/* end block 1 */
	// End offset: 0x8005B820
	// End Line: 1643

	/* begin block 2 */
		// Start line: 3565
	/* end block 2 */
	// End Line: 3566

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
 // line 1645, offset 0x8005b840
	/* begin block 1 */
		// Start line: 1647
		// Start offset: 0x8005B840
		// Variables:
	// 		struct _Instance *instance; // $v1
	/* end block 1 */
	// End offset: 0x8005B87C
	// End Line: 1660

	/* begin block 2 */
		// Start line: 3763
	/* end block 2 */
	// End Line: 3764

	/* begin block 3 */
		// Start line: 3764
	/* end block 3 */
	// End Line: 3765

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
// void /*$ra*/ STREAM_LoadMainVram(struct GameTracker *gameTracker /*$a0*/, char *baseAreaName /*$a1*/, struct _StreamUnit *streamUnit /*$s2*/)
 // line 1700, offset 0x8005b884
	/* begin block 1 */
		// Start line: 1701
		// Start offset: 0x8005B884
		// Variables:
	// 		char dramName[80]; // stack offset -176
	// 		char vramName[80]; // stack offset -96
	// 		struct VramBuffer *vramBuffer; // $v0
	// 		struct Level *level; // $s0
	/* end block 1 */
	// End offset: 0x8005B884
	// End Line: 1701

	/* begin block 2 */
		// Start line: 3395
	/* end block 2 */
	// End Line: 3396

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
  LOAD_NonBlockingBufferedLoad(acStack96,VRAM_TransferBufferToVram,retData,streamUnit);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_MoveIntoNewStreamUnit()
 // line 1747, offset 0x8005b938
	/* begin block 1 */
		// Start line: 3984
	/* end block 1 */
	// End Line: 3985

	/* begin block 2 */
		// Start line: 3985
	/* end block 2 */
	// End Line: 3986

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_MoveIntoNewStreamUnit(void)

{
  (gameTrackerX.playerInstance)->currentStreamUnitID = gameTrackerX.moveRazielToStreamID;
  INSTANCE_UpdateFamilyStreamUnitID(gameTrackerX.playerInstance);
  GAMELOOP_StreamLevelLoadAndInit
            (gameTrackerX.S_baseAreaName,&gameTrackerX,(int)gameTrackerX.toSignal,
             (int)gameTrackerX.fromSignal);
  if ((int)gameTrackerX.SwitchToNewWarpIndex != -1) {
    CurrentWarpNumber = (int)gameTrackerX.SwitchToNewWarpIndex;
  }
  gameTrackerX.SwitchToNewStreamUnit = 0;
  return;
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ STREAM_LoadLevel(struct GameTracker *gameTracker /*$s4*/, char *baseAreaName /*$s3*/, struct StreamUnitPortal *streamPortal /*$s5*/, int loadnext /*$a3*/)
 // line 1764, offset 0x8005b9a0
	/* begin block 1 */
		// Start line: 1765
		// Start offset: 0x8005B9A0
		// Variables:
	// 		int i; // $s2
	// 		long streamID; // $s6
	// 		struct _StreamUnit *streamUnit; // $s1

		/* begin block 1.1 */
			// Start line: 1806
			// Start offset: 0x8005BA3C
		/* end block 1.1 */
		// End offset: 0x8005BA3C
		// End Line: 1809

		/* begin block 1.2 */
			// Start line: 1818
			// Start offset: 0x8005BA68
			// Variables:
		// 		struct Level *level; // $s0
		/* end block 1.2 */
		// End offset: 0x8005BA94
		// End Line: 1828

		/* begin block 1.3 */
			// Start line: 1890
			// Start offset: 0x8005BAF0
			// Variables:
		// 		char dramName[80]; // stack offset -112
		/* end block 1.3 */
		// End offset: 0x8005BB88
		// End Line: 1947
	/* end block 1 */
	// End offset: 0x8005BB94
	// End Line: 1950

	/* begin block 2 */
		// Start line: 4020
	/* end block 2 */
	// End Line: 4021

_StreamUnit *
STREAM_LoadLevel(GameTracker *gameTracker,char *baseAreaName,StreamUnitPortal *streamPortal,
                int loadnext)

{
  int iVar1;
  int iVar2;
  _StreamUnit *streamUnit;
  short fogNear;
  code *retFunc;
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
LAB_8005bac0:
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
              strcpy(gameTracker->baseAreaName,baseAreaName);
              retFunc = STREAM_LoadLevelReturn;
              gameTracker->StreamUnitID = streamUnit->StreamUnitID;
            }
            else {
              retFunc = STREAM_StreamLoadLevelReturn;
              streamPortal->toStreamUnit = (_StreamUnit *)0x0;
            }
            LOAD_NonBlockingBinaryLoad
                      (acStack112,retFunc,(void *)0x0,streamUnit,
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
        strcpy(gameTracker->baseAreaName,baseAreaName);
        STREAM_SetMainFog(streamUnit);
        gameTracker->StreamUnitID = streamUnit->StreamUnitID;
        gameTracker->level = *(Level **)((int)&StreamTracker.StreamList[0].level + iVar1);
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
  goto LAB_8005bac0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RemoveIntroducedLights(struct Level *level /*$s2*/)
 // line 1955, offset 0x8005bbc0
	/* begin block 1 */
		// Start line: 1956
		// Start offset: 0x8005BBC0
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8005BC8C
	// End Line: 1977

	/* begin block 2 */
		// Start line: 4575
	/* end block 2 */
	// End Line: 4576

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
 // line 1979, offset 0x8005bca4
	/* begin block 1 */
		// Start line: 1980
		// Start offset: 0x8005BCA4
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		struct _Instance *next; // $s1
	/* end block 1 */
	// End offset: 0x8005BD30
	// End Line: 2008

	/* begin block 2 */
		// Start line: 4634
	/* end block 2 */
	// End Line: 4635

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
 // line 2010, offset 0x8005bd50
	/* begin block 1 */
		// Start line: 2012
		// Start offset: 0x8005BD50
		// Variables:
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x8005BD98
	// End Line: 2028

	/* begin block 2 */
		// Start line: 4699
	/* end block 2 */
	// End Line: 4700

	/* begin block 3 */
		// Start line: 4700
	/* end block 3 */
	// End Line: 4701

	/* begin block 4 */
		// Start line: 4703
	/* end block 4 */
	// End Line: 4704

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
 // line 2030, offset 0x8005bda0
	/* begin block 1 */
		// Start line: 2031
		// Start offset: 0x8005BDA0
		// Variables:
	// 		int i; // $s0
	// 		int j; // $a0
	// 		int numportals; // $a1

		/* begin block 1.1 */
			// Start line: 2060
			// Start offset: 0x8005BE58
			// Variables:
		// 		char dramName[80]; // stack offset -104
		/* end block 1.1 */
		// End offset: 0x8005BE84
		// End Line: 2070

		/* begin block 1.2 */
			// Start line: 2087
			// Start offset: 0x8005BEC0
			// Variables:
		// 		struct _SFXMkr *sfxMkr; // $a1
		/* end block 1.2 */
		// End offset: 0x8005BEC0
		// End Line: 2087
	/* end block 1 */
	// End offset: 0x8005BF78
	// End Line: 2118

	/* begin block 2 */
		// Start line: 4748
	/* end block 2 */
	// End Line: 4749

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
    if (streamUnit->sfxFileHandle != 0) {
      aadFreeDynamicSfx(streamUnit->sfxFileHandle);
    }
    RemoveIntroducedLights(streamUnit->level);
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
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpAllUnitsNotNeeded(struct GameTracker *gameTracker /*$s2*/)
 // line 2120, offset 0x8005bf94
	/* begin block 1 */
		// Start line: 2121
		// Start offset: 0x8005BF94
		// Variables:
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x8005BFF4
	// End Line: 2133

	/* begin block 2 */
		// Start line: 4949
	/* end block 2 */
	// End Line: 4950

void STREAM_DumpAllUnitsNotNeeded(GameTracker *gameTracker)

{
  STracker *streamUnit;
  int iVar1;
  
  iVar1 = 0;
  streamUnit = &StreamTracker;
  do {
    if ((*(short *)streamUnit->StreamList != 0) &&
       (*(ulong *)streamUnit->StreamList != gameTracker->displayFrameCount)) {
      STREAM_DumpUnit((_StreamUnit *)streamUnit,1);
    }
    iVar1 = iVar1 + 1;
    streamUnit = (STracker *)(streamUnit->StreamList + 1);
  } while (iVar1 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpAllLevels(long IDNoRemove /*$s2*/)
 // line 2135, offset 0x8005c00c
	/* begin block 1 */
		// Start line: 2136
		// Start offset: 0x8005C00C
		// Variables:
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x8005C068
	// End Line: 2149

	/* begin block 2 */
		// Start line: 4990
	/* end block 2 */
	// End Line: 4991

void STREAM_DumpAllLevels(long IDNoRemove)

{
  STracker *streamUnit;
  int iVar1;
  
  iVar1 = 0;
  streamUnit = &StreamTracker;
  do {
    if ((*(short *)streamUnit->StreamList != 0) &&
       (streamUnit->StreamList[0].StreamUnitID != IDNoRemove)) {
      STREAM_DumpUnit((_StreamUnit *)streamUnit,0);
    }
    iVar1 = iVar1 + 1;
    streamUnit = (STracker *)(streamUnit->StreamList + 1);
  } while (iVar1 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_LoadCurrentWarpRoom(struct StreamUnitPortal *streamPortal /*$s1*/, struct _StreamUnit *mainStreamUnit /*$a1*/)
 // line 2152, offset 0x8005c080
	/* begin block 1 */
		// Start line: 5037
	/* end block 1 */
	// End Line: 5038

	/* begin block 2 */
		// Start line: 5039
	/* end block 2 */
	// End Line: 5040

void STREAM_LoadCurrentWarpRoom(StreamUnitPortal *streamPortal,_StreamUnit *mainStreamUnit)

{
  long lVar1;
  int iVar2;
  _StreamUnit *p_Var3;
  
  iVar2 = strcmpi(mainStreamUnit->level->worldName,(char *)(&WarpRoomArray + CurrentWarpNumber));
  if (iVar2 == 0) {
    CurrentWarpNumber = (CurrentWarpNumber + 1) % 0xe;
  }
  p_Var3 = STREAM_LoadLevel(&gameTrackerX,(char *)(&WarpRoomArray + CurrentWarpNumber),streamPortal,
                            0);
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
// void /*$ra*/ WARPGATE_RelocateLoadedWarpRooms(struct _StreamUnit *mainUnit /*$s3*/, struct StreamUnitPortal *streamPortal /*$s4*/)
 // line 2169, offset 0x8005c174
	/* begin block 1 */
		// Start line: 2170
		// Start offset: 0x8005C174
		// Variables:
	// 		int i; // $s2
	/* end block 1 */
	// End offset: 0x8005C1F0
	// End Line: 2182

	/* begin block 2 */
		// Start line: 5075
	/* end block 2 */
	// End Line: 5076

void WARPGATE_RelocateLoadedWarpRooms(_StreamUnit *mainUnit,StreamUnitPortal *streamPortal)

{
  STracker *pSVar1;
  char *baseAreaName;
  int iVar2;
  
  iVar2 = 0;
  baseAreaName = StreamTracker.StreamList[0].baseAreaName;
  pSVar1 = &StreamTracker;
  do {
    if ((pSVar1 != (STracker *)mainUnit) && ((*(ushort *)pSVar1->StreamList & 1) != 0)) {
      STREAM_LoadLevel(&gameTrackerX,baseAreaName,streamPortal,0);
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
 // line 2185, offset 0x8005c210
	/* begin block 1 */
		// Start line: 2186
		// Start offset: 0x8005C210
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8005C25C
	// End Line: 2198

	/* begin block 2 */
		// Start line: 5122
	/* end block 2 */
	// End Line: 5123

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
 // line 2200, offset 0x8005c274
	/* begin block 1 */
		// Start line: 2201
		// Start offset: 0x8005C274
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x8005C2B4
	// End Line: 2209

	/* begin block 2 */
		// Start line: 5160
	/* end block 2 */
	// End Line: 5161

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
 // line 2211, offset 0x8005c2c4
	/* begin block 1 */
		// Start line: 2212
		// Start offset: 0x8005C2C4
	/* end block 1 */
	// End offset: 0x8005C2E4
	// End Line: 2219

	/* begin block 2 */
		// Start line: 5182
	/* end block 2 */
	// End Line: 5183

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
// void /*$ra*/ WARPGATE_IsItActive(struct _StreamUnit *streamUnit /*$a0*/)
 // line 2222, offset 0x8005c2f4
	/* begin block 1 */
		// Start line: 2224
		// Start offset: 0x8005C2F4
		// Variables:
	// 		struct Level *level; // $t1
	// 		int d; // $a1
	/* end block 1 */
	// End offset: 0x8005C3B4
	// End Line: 2246

	/* begin block 2 */
		// Start line: 5204
	/* end block 2 */
	// End Line: 5205

	/* begin block 3 */
		// Start line: 5205
	/* end block 3 */
	// End Line: 5206

	/* begin block 4 */
		// Start line: 5208
	/* end block 4 */
	// End Line: 5209

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
 // line 2248, offset 0x8005c3bc
	/* begin block 1 */
		// Start line: 2250
		// Start offset: 0x8005C3BC
		// Variables:
	// 		struct Level *level; // $v0
	// 		long isWarpRoom; // $a1
	// 		struct StreamUnitPortal *streamPortal; // $v1
	// 		long numPortals; // $a2
	// 		long d; // $a0
	/* end block 1 */
	// End offset: 0x8005C40C
	// End Line: 2268

	/* begin block 2 */
		// Start line: 5271
	/* end block 2 */
	// End Line: 5272

	/* begin block 3 */
		// Start line: 5272
	/* end block 3 */
	// End Line: 5273

	/* begin block 4 */
		// Start line: 5277
	/* end block 4 */
	// End Line: 5278

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
 // line 2271, offset 0x8005c414
	/* begin block 1 */
		// Start line: 2272
		// Start offset: 0x8005C414
	/* end block 1 */
	// End offset: 0x8005C438
	// End Line: 2284

	/* begin block 2 */
		// Start line: 5325
	/* end block 2 */
	// End Line: 5326

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
 // line 2287, offset 0x8005c448
	/* begin block 1 */
		// Start line: 2289
		// Start offset: 0x8005C448
		// Variables:
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x8005C484
	// End Line: 2298

	/* begin block 2 */
		// Start line: 5357
	/* end block 2 */
	// End Line: 5358

	/* begin block 3 */
		// Start line: 5358
	/* end block 3 */
	// End Line: 5359

	/* begin block 4 */
		// Start line: 5360
	/* end block 4 */
	// End Line: 5361

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
 // line 2303, offset 0x8005c48c
	/* begin block 1 */
		// Start line: 2304
		// Start offset: 0x8005C48C
		// Variables:
	// 		long result; // $s1
	/* end block 1 */
	// End offset: 0x8005C57C
	// End Line: 2328

	/* begin block 2 */
		// Start line: 5393
	/* end block 2 */
	// End Line: 5394

	/* begin block 3 */
		// Start line: 5398
	/* end block 3 */
	// End Line: 5399

/* WARNING: Unknown calling convention yet parameter storage is locked */

long WARPGATE_IncrementIndex(void)

{
  int iVar1;
  
  if (WarpGateLoadInfo.loading == 0) {
    WarpGateLoadInfo.loading = 1;
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
 // line 2331, offset 0x8005c594
	/* begin block 1 */
		// Start line: 5475
	/* end block 1 */
	// End Line: 5476

	/* begin block 2 */
		// Start line: 5476
	/* end block 2 */
	// End Line: 5477

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
 // line 2340, offset 0x8005c604
	/* begin block 1 */
		// Start line: 2341
		// Start offset: 0x8005C604
		// Variables:
	// 		long result; // $s0
	/* end block 1 */
	// End offset: 0x8005C6B8
	// End Line: 2367

	/* begin block 2 */
		// Start line: 5494
	/* end block 2 */
	// End Line: 5495

	/* begin block 3 */
		// Start line: 5499
	/* end block 3 */
	// End Line: 5500

/* WARNING: Unknown calling convention yet parameter storage is locked */

long WARPGATE_DecrementIndex(void)

{
  int iVar1;
  
  if (WarpGateLoadInfo.loading == 0) {
    WarpGateLoadInfo.loading = 1;
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
// void /*$ra*/ PreloadAllConnectedUnits(struct GameTracker *gameTracker /*$s4*/, struct _StreamUnit *streamUnit /*$s5*/, struct _SVector *offset /*$s6*/)
 // line 2371, offset 0x8005c6cc
	/* begin block 1 */
		// Start line: 2372
		// Start offset: 0x8005C6CC
		// Variables:
	// 		int i; // $s1
	// 		char text[16]; // stack offset -48
	// 		int numportals; // $s3
	// 		char *commapos; // $v0
	// 		struct StreamUnitPortal *stream; // $s0
	/* end block 1 */
	// End offset: 0x8005C888
	// End Line: 2505

	/* begin block 2 */
		// Start line: 5570
	/* end block 2 */
	// End Line: 5571

void PreloadAllConnectedUnits(GameTracker *gameTracker,_StreamUnit *streamUnit,_SVector *offset)

{
  char *pcVar1;
  int iVar2;
  int *__src;
  StreamUnitPortal *streamPortal;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  char acStack48 [16];
  
  gameTracker->displayFrameCount = gameTracker->displayFrameCount + 1;
  __src = (int *)streamUnit->level->terrain->StreamUnits;
  iVar3 = 0;
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
      iVar3 = iVar3 + 1;
      __src = __src + 0x17;
    } while (iVar3 < iVar5);
  }
  iVar3 = 0;
  STREAM_MarkUnitNeeded(streamUnit->StreamUnitID);
  STREAM_DumpAllUnitsNotNeeded(gameTracker);
  STREAM_RemoveAllObjectsNotInUse(gameTracker);
  RelocateLevelWithInstances(streamUnit->level,offset);
  MEMPACK_DoGarbageCollection();
  __src = (int *)streamUnit->level->terrain->StreamUnits;
  iVar5 = *__src;
  streamPortal = (StreamUnitPortal *)(__src + 1);
  if (0 < iVar5) {
    puVar4 = (ushort *)((int)__src + 0x22);
    do {
      strcpy(acStack48,(char *)streamPortal);
      pcVar1 = strchr(acStack48,0x2c);
      if (pcVar1 == (char *)0x0) {
        GXFilePrint("i=%d No signal num specified for signal in level %s\n");
      }
      else {
        *pcVar1 = '\0';
        iVar2 = strcmpi(acStack48,"warpgate");
        if (iVar2 == 0) {
          *(undefined4 *)(puVar4 + 5) = 0;
          *puVar4 = *puVar4 | 1;
          WARPGATE_RelocateLoadedWarpRooms(streamUnit,streamPortal);
        }
        else {
          STREAM_LoadLevel(gameTracker,acStack48,streamPortal,1);
        }
      }
      iVar3 = iVar3 + 1;
      puVar4 = puVar4 + 0x2e;
      streamPortal = streamPortal + 1;
    } while (iVar3 < iVar5);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateLevel(struct Level *level /*$s0*/, struct _SVector *offset /*$s1*/)
 // line 2570, offset 0x8005c8b0
	/* begin block 1 */
		// Start line: 2571
		// Start offset: 0x8005C8B0
		// Variables:
	// 		int curTree; // $t2

		/* begin block 1.1 */
			// Start line: 2594
			// Start offset: 0x8005C9A8
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $a0
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a3
		/* end block 1.1 */
		// End offset: 0x8005C9A8
		// End Line: 2596
	/* end block 1 */
	// End offset: 0x8005CA00
	// End Line: 2603

	/* begin block 2 */
		// Start line: 5135
	/* end block 2 */
	// End Line: 5136

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
  RelocateSpotLights(level->spotLightList,level->numSpotLights,offset);
  RelocatePointLights(level->pointLightList,level->numPointLights,offset);
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
  if (0 < (int)p_Var5->morphNormalIdx) {
    iVar6 = 0;
    do {
      sVar1 = offset->y;
      sVar2 = offset->z;
      iVar3 = (int)&p_Var5->signals->numSignals + iVar6;
      *(short *)(iVar3 + 0xc) = *(short *)(iVar3 + 0xc) + offset->x;
      *(short *)(iVar3 + 0xe) = *(short *)(iVar3 + 0xe) + sVar1;
      *(short *)(iVar3 + 0x10) = *(short *)(iVar3 + 0x10) + sVar2;
      p_Var5 = level->terrain;
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + 0x24;
    } while (iVar4 < (int)p_Var5->morphNormalIdx);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateCameras(struct _CameraKey *cameraList /*$a0*/, long numCameras /*$a1*/, struct _SVector *offset /*$a2*/)
 // line 2605, offset 0x8005ca14
	/* begin block 1 */
		// Start line: 2607
		// Start offset: 0x8005CA14
		// Variables:
	// 		int i; // $a3
	/* end block 1 */
	// End offset: 0x8005CAA0
	// End Line: 2619

	/* begin block 2 */
		// Start line: 6060
	/* end block 2 */
	// End Line: 6061

	/* begin block 3 */
		// Start line: 6061
	/* end block 3 */
	// End Line: 6062

	/* begin block 4 */
		// Start line: 6063
	/* end block 4 */
	// End Line: 6064

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
 // line 2621, offset 0x8005caa8
	/* begin block 1 */
		// Start line: 2622
		// Start offset: 0x8005CAA8
		// Variables:
	// 		int i; // $t6

		/* begin block 1.1 */
			// Start line: 2632
			// Start offset: 0x8005CAF0
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $v1
		// 		short _y1; // $a1
		// 		short _z1; // $a2
		// 		struct _Position *_v; // $a0
		/* end block 1.1 */
		// End offset: 0x8005CAF0
		// End Line: 2634

		/* begin block 1.2 */
			// Start line: 2634
			// Start offset: 0x8005CAF0
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a3
		/* end block 1.2 */
		// End offset: 0x8005CAF0
		// End Line: 2634

		/* begin block 1.3 */
			// Start line: 2634
			// Start offset: 0x8005CAF0
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a3
		/* end block 1.3 */
		// End offset: 0x8005CAF0
		// End Line: 2634

		/* begin block 1.4 */
			// Start line: 2634
			// Start offset: 0x8005CAF0
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a3
		/* end block 1.4 */
		// End offset: 0x8005CBBC
		// End Line: 2643
	/* end block 1 */
	// End offset: 0x8005CBD8
	// End Line: 2650

	/* begin block 2 */
		// Start line: 6108
	/* end block 2 */
	// End Line: 6109

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
 // line 2652, offset 0x8005cbe0
	/* begin block 1 */
		// Start line: 6193
	/* end block 1 */
	// End Line: 6194

void RelocateLevelWithInstances(Level *level,_SVector *offset)

{
  RelocateLevel(level,offset);
  RelocateInstances(&gameTrackerX,offset,gameTrackerX.StreamUnitID);
  RelocatePlanPool((PlanningNode *)gameTrackerX.drawTime,offset);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateTerrain(struct _Terrain *terrain /*$s3*/, struct _SVector *offset /*$s2*/)
 // line 2663, offset 0x8005cc24
	/* begin block 1 */
		// Start line: 2664
		// Start offset: 0x8005CC24
		// Variables:
	// 		int i; // $s1
	// 		struct _BSPNode *snode; // $a2
	// 		struct _SBSPLeaf *sleaf; // $a1
	// 		long hx; // $a3
	// 		long hy; // $a1
	// 		long hz; // $v1
	/* end block 1 */
	// End offset: 0x8005CE0C
	// End Line: 2791

	/* begin block 2 */
		// Start line: 6215
	/* end block 2 */
	// End Line: 6216

void RelocateTerrain(_Terrain *terrain,_SVector *offset)

{
  int *piVar1;
  short *psVar2;
  char *pcVar3;
  MultiSpline *multi;
  _MorphVertex *p_Var4;
  int iVar5;
  int iVar6;
  
  p_Var4 = (_MorphVertex *)terrain->pad;
  if (p_Var4 < terrain->MorphDiffList) {
    piVar1 = (int *)&p_Var4[1].y;
    do {
      p_Var4->x = p_Var4->x + offset->x;
      *(short *)((int)piVar1 + -0xe) = *(short *)((int)piVar1 + -0xe) + offset->y;
      *(short *)(piVar1 + -3) = *(short *)(piVar1 + -3) + offset->z;
      p_Var4 = (_MorphVertex *)&p_Var4[3].y;
      *piVar1 = *piVar1 + ((int)*(short *)(piVar1 + -2) * (int)offset->x +
                           (int)*(short *)((int)piVar1 + -6) * (int)offset->y +
                           (int)*(short *)(piVar1 + -1) * (int)offset->z >> 0xc);
      piVar1 = piVar1 + 0xb;
    } while (p_Var4 < terrain->MorphDiffList);
  }
  p_Var4 = terrain->MorphDiffList;
  psVar2 = &p_Var4->z;
  if (p_Var4 < (_MorphVertex *)terrain->MorphColorList) {
    do {
      p_Var4->x = p_Var4->x + offset->x;
      psVar2[-1] = psVar2[-1] + offset->y;
      p_Var4 = (_MorphVertex *)&p_Var4[1].hy;
      *psVar2 = *psVar2 + offset->z;
      psVar2 = psVar2 + 0xc;
    } while (p_Var4 < (_MorphVertex *)terrain->MorphColorList);
  }
  iVar6 = 0;
  if (0 < terrain->numIntros) {
    iVar5 = 0;
    do {
      pcVar3 = terrain->introList->name + iVar5;
      *(short *)(pcVar3 + 0x20) = *(short *)(pcVar3 + 0x20) + offset->x;
      pcVar3 = terrain->introList->name + iVar5;
      *(short *)(pcVar3 + 0x22) = *(short *)(pcVar3 + 0x22) + offset->y;
      pcVar3 = terrain->introList->name + iVar5;
      *(short *)(pcVar3 + 0x24) = *(short *)(pcVar3 + 0x24) + offset->z;
      multi = *(MultiSpline **)((int)&terrain->introList->multiSpline + iVar5);
      if (multi != (MultiSpline *)0x0) {
        STREAM_AdjustMultiSpline(multi,offset);
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 0x4c;
    } while (iVar6 < terrain->numIntros);
  }
  RelocateStreamPortals
            ((StreamUnitPortal *)(terrain->StreamUnits + 1),*(int *)terrain->StreamUnits,offset);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateVMObjects(struct _VMObject *vobjectlist /*$a0*/, long numvmobjs /*$a1*/, struct _SVector *offset /*$a2*/)
 // line 2797, offset 0x8005ce3c
	/* begin block 1 */
		// Start line: 2799
		// Start offset: 0x8005CE3C
		// Variables:
	// 		int i; // $a3
	/* end block 1 */
	// End offset: 0x8005CE8C
	// End Line: 2821

	/* begin block 2 */
		// Start line: 6522
	/* end block 2 */
	// End Line: 6523

	/* begin block 3 */
		// Start line: 6523
	/* end block 3 */
	// End Line: 6524

	/* begin block 4 */
		// Start line: 6526
	/* end block 4 */
	// End Line: 6527

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
// void /*$ra*/ RelocateSpotLights(struct SpotLight *spotLightList /*$a0*/, long numSpotLights /*$a1*/, struct _SVector *offset /*$a2*/)
 // line 2823, offset 0x8005ce94
	/* begin block 1 */
		// Start line: 2825
		// Start offset: 0x8005CE94
		// Variables:
	// 		int i; // $a3
	/* end block 1 */
	// End offset: 0x8005CF20
	// End Line: 2838

	/* begin block 2 */
		// Start line: 6582
	/* end block 2 */
	// End Line: 6583

	/* begin block 3 */
		// Start line: 6583
	/* end block 3 */
	// End Line: 6584

	/* begin block 4 */
		// Start line: 6585
	/* end block 4 */
	// End Line: 6586

void RelocateSpotLights(SpotLight *spotLightList,long numSpotLights,_SVector *offset)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < numSpotLights) {
    do {
      (spotLightList->position).x = (spotLightList->position).x + offset->x;
      (spotLightList->position).y = (spotLightList->position).y + offset->y;
      (spotLightList->position).z = (spotLightList->position).z + offset->z;
      (spotLightList->centroid).x = (spotLightList->centroid).x + offset->x;
      (spotLightList->centroid).y = (spotLightList->centroid).y + offset->y;
      iVar1 = iVar1 + 1;
      (spotLightList->centroid).z = (spotLightList->centroid).z + offset->z;
      spotLightList = spotLightList + 1;
    } while (iVar1 < numSpotLights);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocatePointLights(struct PointLight *PLightList /*$a0*/, long numPLights /*$a1*/, struct _SVector *offset /*$a2*/)
 // line 2840, offset 0x8005cf28
	/* begin block 1 */
		// Start line: 2842
		// Start offset: 0x8005CF28
		// Variables:
	// 		int i; // $a3
	/* end block 1 */
	// End offset: 0x8005CF78
	// End Line: 2850

	/* begin block 2 */
		// Start line: 6632
	/* end block 2 */
	// End Line: 6633

	/* begin block 3 */
		// Start line: 6633
	/* end block 3 */
	// End Line: 6634

	/* begin block 4 */
		// Start line: 6635
	/* end block 4 */
	// End Line: 6636

void RelocatePointLights(PointLight *PLightList,long numPLights,_SVector *offset)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < numPLights) {
    do {
      (PLightList->position).x = (PLightList->position).x + offset->x;
      (PLightList->position).y = (PLightList->position).y + offset->y;
      iVar1 = iVar1 + 1;
      (PLightList->position).z = (PLightList->position).z + offset->z;
      PLightList = PLightList + 1;
    } while (iVar1 < numPLights);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateBGObjects(struct _BGObject *BGObjList /*$a0*/, long numBGObjs /*$t2*/, struct _SVector *offset /*$a2*/)
 // line 2852, offset 0x8005cf80
	/* begin block 1 */
		// Start line: 2853
		// Start offset: 0x8005CF80
		// Variables:
	// 		int i; // $t1
	// 		int d; // $a3
	/* end block 1 */
	// End offset: 0x8005D01C
	// End Line: 2865

	/* begin block 2 */
		// Start line: 6664
	/* end block 2 */
	// End Line: 6665

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
 // line 2867, offset 0x8005d024
	/* begin block 1 */
		// Start line: 2868
		// Start offset: 0x8005D024
		// Variables:
	// 		int i; // $a1
	// 		short ox; // $s1
	// 		short oy; // $s2
	// 		short oz; // $s3
	/* end block 1 */
	// End offset: 0x8005D090
	// End Line: 2883

	/* begin block 2 */
		// Start line: 6700
	/* end block 2 */
	// End Line: 6701

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
 // line 2888, offset 0x8005d0d8
	/* begin block 1 */
		// Start line: 2889
		// Start offset: 0x8005D0D8
		// Variables:
	// 		int i; // $a1
	// 		short ox; // $t1
	// 		short oy; // $t0
	// 		short oz; // $a2
	/* end block 1 */
	// End offset: 0x8005D124
	// End Line: 2903

	/* begin block 2 */
		// Start line: 6755
	/* end block 2 */
	// End Line: 6756

	/* begin block 3 */
		// Start line: 6759
	/* end block 3 */
	// End Line: 6760

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
 // line 2905, offset 0x8005d12c
	/* begin block 1 */
		// Start line: 2907
		// Start offset: 0x8005D12C
		// Variables:
	// 		int i; // $a1
	// 		short ox; // $t0
	// 		short oy; // $a3
	// 		short oz; // $a2
	/* end block 1 */
	// End offset: 0x8005D170
	// End Line: 2920

	/* begin block 2 */
		// Start line: 6799
	/* end block 2 */
	// End Line: 6800

	/* begin block 3 */
		// Start line: 6800
	/* end block 3 */
	// End Line: 6801

	/* begin block 4 */
		// Start line: 6803
	/* end block 4 */
	// End Line: 6804

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
 // line 2922, offset 0x8005d178
	/* begin block 1 */
		// Start line: 2923
		// Start offset: 0x8005D178
		// Variables:
	// 		int i; // $a2
	/* end block 1 */
	// End offset: 0x8005D220
	// End Line: 2944

	/* begin block 2 */
		// Start line: 6839
	/* end block 2 */
	// End Line: 6840

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
// void /*$ra*/ STREAM_RelocateInstance(struct GameTracker *gameTracker /*$a0*/, struct _Instance *instance /*$s0*/, struct _SVector *offset /*$s1*/)
 // line 2946, offset 0x8005d228
	/* begin block 1 */
		// Start line: 6891
	/* end block 1 */
	// End Line: 6892

void STREAM_RelocateInstance(GameTracker *gameTracker,_Instance *instance,_SVector *offset)

{
  STREAM_OffsetInstancePosition(gameTracker,instance,offset,1);
  INSTANCE_Post(instance,0x100008,(int)offset);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_OffsetInstancePosition(struct GameTracker *gameTracker /*$a0*/, struct _Instance *instance /*$s0*/, struct _SVector *offset /*$s1*/, int streamSignalFlag /*$s2*/)
 // line 2954, offset 0x8005d270
	/* begin block 1 */
		// Start line: 6907
	/* end block 1 */
	// End Line: 6908

void STREAM_OffsetInstancePosition
               (GameTracker *gameTracker,_Instance *instance,_SVector *offset,int streamSignalFlag)

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
// void /*$ra*/ STREAM_SetInstancePosition(struct GameTracker *gameTracker /*$a0*/, struct _Instance *instance /*$a1*/, struct evPositionData *data /*$a2*/)
 // line 2981, offset 0x8005d38c
	/* begin block 1 */
		// Start line: 2982
		// Start offset: 0x8005D38C
		// Variables:
	// 		struct _SVector offset; // stack offset -16
	/* end block 1 */
	// End offset: 0x8005D38C
	// End Line: 2982

	/* begin block 2 */
		// Start line: 6977
	/* end block 2 */
	// End Line: 6978

void STREAM_SetInstancePosition(GameTracker *gameTracker,_Instance *instance,evPositionData *data)

{
  _SVector local_10;
  
  local_10.x = data->x - (instance->position).x;
  local_10.y = data->y - (instance->position).y;
  local_10.z = data->z - (instance->position).z;
  STREAM_OffsetInstancePosition(gameTracker,instance,&local_10,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateInstances(struct GameTracker *gameTracker /*$s1*/, struct _SVector *offset /*$s2*/, long StreamUnitID /*$a2*/)
 // line 2992, offset 0x8005d3e4
	/* begin block 1 */
		// Start line: 2993
		// Start offset: 0x8005D3E4
		// Variables:
	// 		struct _InstanceList *instanceList; // $v0
	// 		struct _Instance *instance; // $s0
	/* end block 1 */
	// End offset: 0x8005D434
	// End Line: 3009

	/* begin block 2 */
		// Start line: 7004
	/* end block 2 */
	// End Line: 7005

void RelocateInstances(GameTracker *gameTracker,_SVector *offset,long StreamUnitID)

{
  _Instance *instance;
  
  instance = gameTracker->instanceList->first;
  while (instance != (_Instance *)0x0) {
    STREAM_RelocateInstance(gameTracker,instance,offset);
    instance = instance->next;
  }
  FX_Relocate(offset);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateStreamPortals(struct StreamUnitPortal *StreamUnitList /*$a0*/, int NumStreamUnits /*$a1*/, struct _SVector *offset /*$a2*/)
 // line 3012, offset 0x8005d454
	/* begin block 1 */
		// Start line: 3014
		// Start offset: 0x8005D454
		// Variables:
	// 		int i; // $t1
	// 		int d; // $t0
	/* end block 1 */
	// End offset: 0x8005D57C
	// End Line: 3039

	/* begin block 2 */
		// Start line: 7046
	/* end block 2 */
	// End Line: 7047

	/* begin block 3 */
		// Start line: 7047
	/* end block 3 */
	// End Line: 7048

	/* begin block 4 */
		// Start line: 7049
	/* end block 4 */
	// End Line: 7050

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
        pSVar1->_9[0].x = pSVar1->_9[0].x + offset->x;
        pSVar1->_9[0].y = pSVar1->_9[0].y + offset->y;
        iVar2 = iVar2 + 1;
        pSVar1->_9[0].z = pSVar1->_9[0].z + offset->z;
        pSVar1 = (StreamUnitPortal *)(pSVar1->tolevelname + 8);
      } while (iVar2 < 3);
      iVar2 = 0;
      pSVar1 = StreamUnitList;
      do {
        pSVar1->_10[0].x = pSVar1->_10[0].x + offset->x;
        pSVar1->_10[0].y = pSVar1->_10[0].y + offset->y;
        iVar2 = iVar2 + 1;
        pSVar1->_10[0].z = pSVar1->_10[0].z + offset->z;
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
 // line 3049, offset 0x8005d584
	/* begin block 1 */
		// Start line: 3050
		// Start offset: 0x8005D584
		// Variables:
	// 		struct VramSize *vramSize; // $a0

		/* begin block 1.1 */
			// Start line: 3059
			// Start offset: 0x8005D5B4
			// Variables:
		// 		struct VramBuffer *vramBuffer; // $v0

			/* begin block 1.1.1 */
				// Start line: 3067
				// Start offset: 0x8005D5C4
				// Variables:
			// 		char fileName[64]; // stack offset -80
			// 		struct _BlockVramEntry *vramBlock; // $s0
			/* end block 1.1.1 */
			// End offset: 0x8005D5EC
			// End Line: 3077
		/* end block 1.1 */
		// End offset: 0x8005D66C
		// End Line: 3096
	/* end block 1 */
	// End offset: 0x8005D670
	// End Line: 3104

	/* begin block 2 */
		// Start line: 7157
	/* end block 2 */
	// End Line: 7158

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
    LOAD_NonBlockingBufferedLoad(acStack80,VRAM_TransferBufferToVram,retData,(void *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_SetupInstanceFlags(struct GameTracker *gameTracker /*$a0*/, struct _Instance *instance /*$s0*/)
 // line 3132, offset 0x8005d684
	/* begin block 1 */
		// Start line: 7356
	/* end block 1 */
	// End Line: 7357

void MORPH_SetupInstanceFlags(GameTracker *gameTracker,_Instance *instance)

{
  long lVar1;
  uint uVar2;
  
  if ((instance->object->oflags & 0x80000U) != 0) {
    return;
  }
  if ((gameTracker->gameData).asmData.MorphType == 0) {
    uVar2 = instance->flags2;
    if ((uVar2 & 0x8000000) == 0) {
      uVar2 = uVar2 & 0xebffffff;
      goto LAB_8005d788;
    }
  }
  else {
    uVar2 = instance->flags2;
    if ((uVar2 & 0x8000000) != 0) {
      uVar2 = uVar2 & 0xebffffff;
      goto LAB_8005d788;
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
  uVar2 = instance->flags2 | 0x4000000;
LAB_8005d788:
  instance->flags2 = uVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_SetupInstanceListFlags(struct GameTracker *gameTracker /*$s1*/)
 // line 3179, offset 0x8005d79c
	/* begin block 1 */
		// Start line: 3180
		// Start offset: 0x8005D79C
		// Variables:
	// 		struct _Instance *instance; // $s0
	/* end block 1 */
	// End offset: 0x8005D7E0
	// End Line: 3191

	/* begin block 2 */
		// Start line: 7453
	/* end block 2 */
	// End Line: 7454

void MORPH_SetupInstanceListFlags(GameTracker *gameTracker)

{
  _Instance *instance;
  
  instance = gameTracker->instanceList->first;
  while (instance != (_Instance *)0x0) {
    MORPH_SetupInstanceFlags(gameTracker,instance);
    instance = instance->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_InMorphInstanceListFlags(struct GameTracker *gameTracker /*$a0*/)
 // line 3193, offset 0x8005d7f4
	/* begin block 1 */
		// Start line: 3195
		// Start offset: 0x8005D7F4
		// Variables:
	// 		struct _Instance *instance; // $v1
	/* end block 1 */
	// End offset: 0x8005D854
	// End Line: 3218

	/* begin block 2 */
		// Start line: 7481
	/* end block 2 */
	// End Line: 7482

	/* begin block 3 */
		// Start line: 7482
	/* end block 3 */
	// End Line: 7483

	/* begin block 4 */
		// Start line: 7486
	/* end block 4 */
	// End Line: 7487

void MORPH_InMorphInstanceListFlags(GameTracker *gameTracker)

{
  _Instance *p_Var1;
  
  p_Var1 = gameTracker->instanceList->first;
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
// void /*$ra*/ MORPH_InMorphDoFadeValues(struct GameTracker *gameTracker /*$a0*/)
 // line 3220, offset 0x8005d85c
	/* begin block 1 */
		// Start line: 3222
		// Start offset: 0x8005D85C
		// Variables:
	// 		int fade1; // $a1
	// 		int fade2; // $v0
	/* end block 1 */
	// End offset: 0x8005D8A4
	// End Line: 3236

	/* begin block 2 */
		// Start line: 7535
	/* end block 2 */
	// End Line: 7536

	/* begin block 3 */
		// Start line: 7536
	/* end block 3 */
	// End Line: 7537

	/* begin block 4 */
		// Start line: 7538
	/* end block 4 */
	// End Line: 7539

void MORPH_InMorphDoFadeValues(GameTracker *gameTracker)

{
  short sVar1;
  
  sVar1 = (short)(((int)(gameTracker->gameData).asmData.MorphTime << 0xc) / 1000);
  if ((gameTracker->gameData).asmData.MorphType == 0) {
    *(short *)&gameTracker->lastLoopTime = sVar1;
    *(short *)((int)&gameTracker->lastLoopTime + 2) = 0x1000 - sVar1;
    return;
  }
  *(short *)&gameTracker->lastLoopTime = 0x1000 - sVar1;
  *(short *)((int)&gameTracker->lastLoopTime + 2) = sVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_UpdateTimeMult()
 // line 3242, offset 0x8005d8ac
	/* begin block 1 */
		// Start line: 3245
		// Start offset: 0x8005D8AC

		/* begin block 1.1 */
			// Start line: 3248
			// Start offset: 0x8005D8C0
			// Variables:
		// 		short ratio; // $v1
		/* end block 1.1 */
		// End offset: 0x8005D9DC
		// End Line: 3286
	/* end block 1 */
	// End offset: 0x8005DA18
	// End Line: 3302

	/* begin block 2 */
		// Start line: 7579
	/* end block 2 */
	// End Line: 7580

	/* begin block 3 */
		// Start line: 7581
	/* end block 3 */
	// End Line: 7582

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
    gameTrackerX.timeSinceLastGameFrame =
         gameTrackerX.visibleInstances * ((((iVar1 << 0x10) >> 4) / 0xfa) * 0x10000 >> 0x10) * 0x10
         >> 0x10;
    if (gameTrackerX.timeSinceLastGameFrame == 0) {
      gameTrackerX.timeSinceLastGameFrame = 1;
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
    gameTrackerX.gameFramePassed =
         gameTrackerX.visibleInstances * ((((iVar1 << 0x10) >> 4) / 0xfa) * 0x10000 >> 0x10) * 0x10
         >> 0x10;
    if (gameTrackerX.gameFramePassed == 0) {
      gameTrackerX.gameFramePassed = 1;
    }
    return;
  }
  if (gameTrackerX.gameData.asmData.MorphType == 0) {
    gameTrackerX.gameFramePassed = 0;
    gameTrackerX.timeSinceLastGameFrame = gameTrackerX.visibleInstances;
    return;
  }
  gameTrackerX.gameFramePassed = gameTrackerX.visibleInstances;
  gameTrackerX.timeSinceLastGameFrame = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_UpdateNormals(struct Level *BaseLevel /*$s0*/)
 // line 3306, offset 0x8005da20
	/* begin block 1 */
		// Start line: 3307
		// Start offset: 0x8005DA20
		// Variables:
	// 		struct _TFace *face; // $v1
	// 		long faceCount; // $a2
	// 		struct _TVertex *v; // $a1
	// 		struct _MorphVertex *mv; // $a3
	// 		struct _MorphColor *mc; // $a0
	// 		void *hldptr; // $a2
	// 		long hldnum; // $t0
	// 		short h1; // $v1
	// 		short *morphNormals; // $a1

		/* begin block 1.1 */
			// Start line: 3356
			// Start offset: 0x8005DB18
			// Variables:
		// 		struct _TVertex *endv; // $a2
		/* end block 1.1 */
		// End offset: 0x8005DB88
		// End Line: 3377

		/* begin block 1.2 */
			// Start line: 3377
			// Start offset: 0x8005DB88
			// Variables:
		// 		struct _BSPNode *node; // $v1
		// 		struct _BSPLeaf *leaf; // $a0
		// 		struct _Sphere_noSq hsphere; // stack offset -32
		// 		struct _BoundingBox hbox; // stack offset -24
		// 		struct _Terrain *terrain; // $a3
		// 		long curTree; // $t0
		/* end block 1.2 */
		// End offset: 0x8005DDE0
		// End Line: 3428

		/* begin block 1.3 */
			// Start line: 3430
			// Start offset: 0x8005DDE0
			// Variables:
		// 		struct _Instance *instance; // $s0

			/* begin block 1.3.1 */
				// Start line: 3436
				// Start offset: 0x8005DE08
				// Variables:
			// 		struct SVECTOR realDiff; // stack offset -32
			// 		struct _Position oldPos; // stack offset -24
			/* end block 1.3.1 */
			// End offset: 0x8005DEDC
			// End Line: 3459
		/* end block 1.3 */
		// End offset: 0x8005DEEC
		// End Line: 3462
	/* end block 1 */
	// End offset: 0x8005DEEC
	// End Line: 3463

	/* begin block 2 */
		// Start line: 7711
	/* end block 2 */
	// End Line: 7712

void MORPH_UpdateNormals(Level *BaseLevel)

{
  short *psVar1;
  short *psVar2;
  short sVar3;
  ushort uVar4;
  short sVar5;
  _BSPNode **pp_Var6;
  _Terrain *p_Var7;
  _TVertex *p_Var8;
  uint *puVar9;
  int iVar10;
  byte *pbVar11;
  undefined4 *puVar12;
  uint uVar13;
  ushort *puVar14;
  BSPTree *pBVar15;
  SpotLight *pSVar16;
  undefined4 *puVar17;
  Intro *pIVar18;
  ushort *puVar19;
  long lVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  short *psVar24;
  _TVertex *p_Var25;
  PointLight *pPVar26;
  short *psVar27;
  long lVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  _Instance *instance;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  undefined4 local_10;
  
  p_Var7 = BaseLevel->terrain;
  puVar19 = *(ushort **)(p_Var7 + 1);
  iVar23 = p_Var7->numFaces;
  if (0 < iVar23) {
    puVar14 = &p_Var7->faceList->normal;
    do {
      uVar4 = *puVar14;
      iVar23 = iVar23 + -1;
      *puVar14 = *puVar19;
      *puVar19 = uVar4;
      puVar19 = puVar19 + 1;
      puVar14 = puVar14 + 6;
    } while (0 < iVar23);
    p_Var7 = BaseLevel->terrain;
  }
  psVar27 = (short *)p_Var7->numBSPTrees;
  if (psVar27 != (short *)0x0) {
    sVar3 = psVar27[3];
    sVar5 = psVar27[3];
    psVar24 = psVar27 + 3;
    while (-1 < sVar3) {
      p_Var8 = BaseLevel->terrain->vertexList + sVar5;
      (p_Var8->vertex).x = psVar24[1] + *psVar27;
      (p_Var8->vertex).y = psVar24[2] + psVar24[-2];
      psVar1 = psVar24 + 3;
      psVar2 = psVar24 + -1;
      psVar24 = psVar24 + 7;
      (p_Var8->vertex).z = *psVar1 + *psVar2;
      sVar3 = *psVar24;
      sVar5 = *psVar24;
      psVar27 = psVar27 + 7;
    }
  }
  p_Var7 = BaseLevel->terrain;
  pBVar15 = p_Var7->BSPTreeArray;
  if (pBVar15 != (BSPTree *)0x0) {
    p_Var8 = p_Var7->vertexList;
    p_Var25 = p_Var8 + p_Var7->numVertices;
    pbVar11 = &p_Var8->b0;
    while (p_Var8 < p_Var25) {
      pbVar11[-2] = (byte)(((uint)*(byte *)&pBVar15->bspRoot & 0x1f) << 3);
      p_Var8 = p_Var8 + 1;
      pbVar11[-1] = (byte)(*(ushort *)&pBVar15->bspRoot >> 2) & 0xf8;
      pp_Var6 = &pBVar15->bspRoot;
      pBVar15 = (BSPTree *)((int)&pBVar15->bspRoot + 2);
      *pbVar11 = (byte)(*(ushort *)pp_Var6 >> 7) & 0xf8;
      pbVar11 = pbVar11 + 0xc;
    }
  }
  RemoveIntroducedLights(BaseLevel);
  lVar20 = BaseLevel->numSpotSpecturalLights;
  pSVar16 = BaseLevel->spotSpecturalLightList;
  p_Var7 = BaseLevel->terrain;
  BaseLevel->numSpotSpecturalLights = BaseLevel->numSpotLights;
  lVar28 = BaseLevel->numPointLights;
  BaseLevel->spotSpecturalLightList = BaseLevel->spotLightList;
  pPVar26 = BaseLevel->pointLightList;
  BaseLevel->numSpotLights = lVar20;
  BaseLevel->spotLightList = pSVar16;
  BaseLevel->numPointLights = BaseLevel->numPointSpecturalLights;
  BaseLevel->pointLightList = BaseLevel->pointSpecturalLightList;
  BaseLevel->numPointSpecturalLights = lVar28;
  BaseLevel->pointSpecturalLightList = pPVar26;
  iVar23 = 0;
  if (0 < (int)p_Var7->morphNormalIdx) {
    iVar21 = 0;
    do {
      puVar9 = (uint *)((int)&p_Var7->signals->numSignals + iVar21);
      puVar17 = (undefined4 *)*puVar9;
      puVar12 = puVar17 + 7;
      if (puVar17 < (undefined4 *)puVar9[1]) {
        do {
          uVar29 = *puVar17;
          local_1c = puVar17[1];
          uVar30 = puVar12[1];
          *puVar17 = *puVar12;
          puVar17[1] = uVar30;
          *puVar12 = uVar29;
          puVar12[1] = local_1c;
          puVar17 = puVar17 + 0xb;
          puVar12 = puVar12 + 0xb;
        } while (puVar17 < *(undefined4 **)((int)&p_Var7->signals->signalNum + iVar21));
      }
      iVar10 = (int)&p_Var7->signals->numSignals + iVar21;
      puVar17 = *(undefined4 **)(iVar10 + 4);
      if (puVar17 < *(undefined4 **)(iVar10 + 8)) {
        puVar12 = puVar17 + 7;
        do {
          uVar29 = *puVar17;
          local_1c = puVar17[1];
          uVar30 = puVar12[4];
          *puVar17 = puVar12[3];
          puVar17[1] = uVar30;
          puVar12[3] = uVar29;
          puVar12[4] = local_1c;
          uVar29 = puVar12[-3];
          local_14 = puVar12[-2];
          local_10 = puVar12[-1];
          puVar12[-3] = *puVar12;
          puVar12[-2] = puVar12[1];
          puVar12[-1] = puVar12[2];
          *puVar12 = uVar29;
          puVar12[1] = local_14;
          puVar12[2] = local_10;
          puVar17 = puVar17 + 0xc;
          puVar12 = puVar12 + 0xc;
        } while (puVar17 < *(undefined4 **)((int)&p_Var7->signals->signalList[0].id + iVar21));
      }
      iVar23 = iVar23 + 1;
      iVar21 = iVar21 + 0x24;
    } while (iVar23 < (int)p_Var7->morphNormalIdx);
  }
  instance = (gameTrackerX.instanceList)->first;
  while (instance != (_Instance *)0x0) {
    pIVar18 = instance->intro;
    if ((pIVar18 != (Intro *)0x0) &&
       ((*(int *)&pIVar18->spectralPosition != 0 || ((pIVar18->spectralPosition).z != 0)))) {
      local_18 = *(uint *)&instance->position;
      uVar13 = (uint)(ushort)(instance->position).z;
      local_14 = local_14 & 0xffff0000 | uVar13;
      (instance->position).x = (pIVar18->position).x + (pIVar18->spectralPosition).x;
      (instance->position).y = (pIVar18->position).y + (pIVar18->spectralPosition).y;
      (instance->position).z = (pIVar18->position).z + (pIVar18->spectralPosition).z;
      uVar22 = (uint)(ushort)(instance->position).x - (local_18 & 0xffff);
      iVar23 = (uint)(ushort)(instance->position).y - (local_18 >> 0x10);
      local_20 = uVar22 & 0xffff | iVar23 * 0x10000;
      uVar13 = (ushort)(instance->position).z - uVar13;
      local_1c = local_1c & 0xffff0000 | uVar13 & 0xffff;
      if (((int)(uVar22 * 0x10000) >> 0x10) + (iVar23 * 0x10000 >> 0x10) +
          ((int)(uVar13 * 0x10000) >> 0x10) != 0) {
        COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)&local_20);
      }
    }
    instance = instance->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_BringBackNormals(struct Level *BaseLevel /*$s0*/)
 // line 3465, offset 0x8005defc
	/* begin block 1 */
		// Start line: 3466
		// Start offset: 0x8005DEFC
		// Variables:
	// 		struct _TFace *face; // $v1
	// 		long faceCount; // $a2
	// 		struct _TVertex *v; // $a2
	// 		struct _MorphVertex *mv; // $a0
	// 		struct _MorphColor *mc; // $v0
	// 		void *hldptr; // $a2
	// 		long hldnum; // $t0
	// 		short h1; // $v1
	// 		short *morphNormals; // $a1

		/* begin block 1.1 */
			// Start line: 3513
			// Start offset: 0x8005DFD8
			// Variables:
		// 		short tr; // stack offset -16
		// 		short tg; // stack offset -14
		// 		short tb; // stack offset -12

			/* begin block 1.1.1 */
				// Start line: 3515
				// Start offset: 0x8005DFD8
				// Variables:
			// 		struct _TVertex *endv; // $a1
			/* end block 1.1.1 */
			// End offset: 0x8005E0C4
			// End Line: 3528
		/* end block 1.1 */
		// End offset: 0x8005E0C4
		// End Line: 3543

		/* begin block 1.2 */
			// Start line: 3543
			// Start offset: 0x8005E0C4
			// Variables:
		// 		struct _BSPNode *node; // $v1
		// 		struct _BSPLeaf *leaf; // $a0
		// 		struct _Sphere_noSq hsphere; // stack offset -40
		// 		struct _BoundingBox hbox; // stack offset -32
		// 		struct _Terrain *terrain; // $a3
		// 		long curTree; // $t0
		/* end block 1.2 */
		// End offset: 0x8005E31C
		// End Line: 3593

		/* begin block 1.3 */
			// Start line: 3596
			// Start offset: 0x8005E31C
			// Variables:
		// 		struct _Instance *instance; // $s0

			/* begin block 1.3.1 */
				// Start line: 3602
				// Start offset: 0x8005E344
				// Variables:
			// 		struct SVECTOR realDiff; // stack offset -40
			// 		struct _Position oldPos; // stack offset -32
			/* end block 1.3.1 */
			// End offset: 0x8005E400
			// End Line: 3625
		/* end block 1.3 */
		// End offset: 0x8005E410
		// End Line: 3628
	/* end block 1 */
	// End offset: 0x8005E410
	// End Line: 3629

	/* begin block 2 */
		// Start line: 8129
	/* end block 2 */
	// End Line: 8130

void MORPH_BringBackNormals(Level *BaseLevel)

{
  short *psVar1;
  short sVar2;
  ushort uVar3;
  short sVar4;
  _Terrain *p_Var5;
  uint *puVar6;
  int iVar7;
  _TVertex *p_Var8;
  undefined4 *puVar9;
  Intro *pIVar10;
  uint uVar11;
  ushort *puVar12;
  byte *pbVar13;
  SpotLight *pSVar14;
  undefined4 *puVar15;
  ushort *puVar16;
  short *psVar17;
  _TVertex *p_Var18;
  long lVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  PointLight *pPVar23;
  long lVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  _Instance *instance;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  short local_10;
  short local_e;
  short local_c [2];
  
  p_Var5 = BaseLevel->terrain;
  puVar16 = *(ushort **)(p_Var5 + 1);
  iVar22 = p_Var5->numFaces;
  puVar12 = &p_Var5->faceList->normal;
  if (0 < iVar22) {
    do {
      uVar3 = *puVar12;
      iVar22 = iVar22 + -1;
      *puVar12 = *puVar16;
      *puVar16 = uVar3;
      puVar16 = puVar16 + 1;
      puVar12 = puVar12 + 6;
    } while (0 < iVar22);
    p_Var5 = BaseLevel->terrain;
  }
  iVar22 = p_Var5->numBSPTrees;
  if (iVar22 != 0) {
    sVar2 = *(short *)(iVar22 + 6);
    sVar4 = *(short *)(iVar22 + 6);
    psVar17 = (short *)(iVar22 + 6);
    while (-1 < sVar2) {
      p_Var8 = BaseLevel->terrain->vertexList + sVar4;
      (p_Var8->vertex).x = psVar17[1];
      (p_Var8->vertex).y = psVar17[2];
      psVar1 = psVar17 + 3;
      psVar17 = psVar17 + 7;
      (p_Var8->vertex).z = *psVar1;
      sVar2 = *psVar17;
      sVar4 = *psVar17;
    }
    p_Var5 = BaseLevel->terrain;
  }
  if (p_Var5->BSPTreeArray != (BSPTree *)0x0) {
    GAMELOOP_GetTimeOfDayLighting
              (BaseLevel,&local_10,&local_e,local_c,&BaseLevel->backColorR,&BaseLevel->holdFogNear,
               &BaseLevel->holdFogFar);
    p_Var8 = BaseLevel->terrain->vertexList;
    p_Var18 = p_Var8 + BaseLevel->terrain->numVertices;
    pbVar13 = &p_Var8->b0;
    while (p_Var8 < p_Var18) {
      pbVar13[-2] = (byte)(((uint)pbVar13[-4] & 0x1f) << 3);
      pbVar13[-1] = (byte)(*(ushort *)(pbVar13 + -4) >> 2) & 0xf8;
      *pbVar13 = (byte)(*(ushort *)(pbVar13 + -4) >> 7) & 0xf8;
      pbVar13[-2] = (byte)((int)((int)local_10 * (uint)pbVar13[-2]) >> 0xc);
      pbVar13[-1] = (byte)((int)((int)local_e * (uint)pbVar13[-1]) >> 0xc);
      p_Var8 = p_Var8 + 1;
      *pbVar13 = (byte)((int)((int)local_c[0] * (uint)*pbVar13) >> 0xc);
      pbVar13 = pbVar13 + 0xc;
    }
  }
  RemoveIntroducedLights(BaseLevel);
  lVar19 = BaseLevel->numSpotSpecturalLights;
  pSVar14 = BaseLevel->spotSpecturalLightList;
  p_Var5 = BaseLevel->terrain;
  BaseLevel->numSpotSpecturalLights = BaseLevel->numSpotLights;
  lVar24 = BaseLevel->numPointLights;
  BaseLevel->spotSpecturalLightList = BaseLevel->spotLightList;
  pPVar23 = BaseLevel->pointLightList;
  BaseLevel->numSpotLights = lVar19;
  BaseLevel->spotLightList = pSVar14;
  BaseLevel->numPointLights = BaseLevel->numPointSpecturalLights;
  BaseLevel->pointLightList = BaseLevel->pointSpecturalLightList;
  BaseLevel->numPointSpecturalLights = lVar24;
  BaseLevel->pointSpecturalLightList = pPVar23;
  iVar22 = 0;
  if (0 < (int)p_Var5->morphNormalIdx) {
    iVar20 = 0;
    do {
      puVar6 = (uint *)((int)&p_Var5->signals->numSignals + iVar20);
      puVar15 = (undefined4 *)*puVar6;
      puVar9 = puVar15 + 7;
      if (puVar15 < (undefined4 *)puVar6[1]) {
        do {
          uVar25 = *puVar15;
          local_24 = puVar15[1];
          uVar26 = puVar9[1];
          *puVar15 = *puVar9;
          puVar15[1] = uVar26;
          *puVar9 = uVar25;
          puVar9[1] = local_24;
          puVar15 = puVar15 + 0xb;
          puVar9 = puVar9 + 0xb;
        } while (puVar15 < *(undefined4 **)((int)&p_Var5->signals->signalNum + iVar20));
      }
      iVar7 = (int)&p_Var5->signals->numSignals + iVar20;
      puVar15 = *(undefined4 **)(iVar7 + 4);
      if (puVar15 < *(undefined4 **)(iVar7 + 8)) {
        puVar9 = puVar15 + 7;
        do {
          uVar25 = *puVar15;
          local_24 = puVar15[1];
          uVar26 = puVar9[4];
          *puVar15 = puVar9[3];
          puVar15[1] = uVar26;
          puVar9[3] = uVar25;
          puVar9[4] = local_24;
          uVar25 = puVar9[-3];
          local_1c = puVar9[-2];
          local_18 = puVar9[-1];
          puVar9[-3] = *puVar9;
          puVar9[-2] = puVar9[1];
          puVar9[-1] = puVar9[2];
          *puVar9 = uVar25;
          puVar9[1] = local_1c;
          puVar9[2] = local_18;
          puVar15 = puVar15 + 0xc;
          puVar9 = puVar9 + 0xc;
        } while (puVar15 < *(undefined4 **)((int)&p_Var5->signals->signalList[0].id + iVar20));
      }
      iVar22 = iVar22 + 1;
      iVar20 = iVar20 + 0x24;
    } while (iVar22 < (int)p_Var5->morphNormalIdx);
  }
  instance = (gameTrackerX.instanceList)->first;
  while (instance != (_Instance *)0x0) {
    pIVar10 = instance->intro;
    if ((pIVar10 != (Intro *)0x0) &&
       ((*(int *)&pIVar10->spectralPosition != 0 || ((pIVar10->spectralPosition).z != 0)))) {
      local_20 = *(uint *)&instance->position;
      uVar11 = (uint)(ushort)(instance->position).z;
      local_1c = local_1c & 0xffff0000 | uVar11;
      (instance->position).x = (pIVar10->position).x;
      (instance->position).y = (pIVar10->position).y;
      (instance->position).z = (pIVar10->position).z;
      uVar21 = (uint)(ushort)(instance->position).x - (local_20 & 0xffff);
      iVar22 = (uint)(ushort)(instance->position).y - (local_20 >> 0x10);
      local_28 = uVar21 & 0xffff | iVar22 * 0x10000;
      uVar11 = (ushort)(instance->position).z - uVar11;
      local_24 = local_24 & 0xffff0000 | uVar11 & 0xffff;
      if (((int)(uVar21 * 0x10000) >> 0x10) + (iVar22 * 0x10000 >> 0x10) +
          ((int)(uVar11 * 0x10000) >> 0x10) != 0) {
        COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)&local_28);
      }
    }
    instance = instance->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_AddOffsets(struct Level *BaseLevel /*$s2*/, int time /*$a1*/)
 // line 3631, offset 0x8005e420
	/* begin block 1 */
		// Start line: 3632
		// Start offset: 0x8005E420
		// Variables:
	// 		struct _TVertex *v; // $a3
	// 		struct _MorphVertex *mv; // $a2
	// 		struct _MorphColor *mc; // $s0
	// 		long m; // $v0
	// 		long fixed_time; // $s1
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 3679
			// Start offset: 0x8005E5D4
			// Variables:
		// 		struct SVECTOR diff; // stack offset -48
		// 		struct SVECTOR realDiff; // stack offset -40
		// 		struct _Position oldPos; // stack offset -32
		/* end block 1.1 */
		// End offset: 0x8005E6D0
		// End Line: 3698

		/* begin block 1.2 */
			// Start line: 3707
			// Start offset: 0x8005E6F8
			// Variables:
		// 		long r0; // $a2
		// 		long g0; // $a1
		// 		long b0; // $a0
		// 		long r1; // $v0
		// 		long g1; // $v0
		// 		long b1; // $v1
		// 		short tr; // stack offset -24
		// 		short tg; // stack offset -22
		// 		short tb; // stack offset -20

			/* begin block 1.2.1 */
				// Start line: 3711
				// Start offset: 0x8005E6F8
				// Variables:
			// 		struct _TVertex *endv; // $t3
			/* end block 1.2.1 */
			// End offset: 0x8005E828
			// End Line: 3727
		/* end block 1.2 */
		// End offset: 0x8005E828
		// End Line: 3750
	/* end block 1 */
	// End offset: 0x8005E828
	// End Line: 3752

	/* begin block 2 */
		// Start line: 8558
	/* end block 2 */
	// End Line: 8559

	/* begin block 3 */
		// Start line: 8564
	/* end block 3 */
	// End Line: 8565

void MORPH_AddOffsets(Level *BaseLevel,int time)

{
  short *psVar1;
  short *psVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  _BSPNode **pp_Var6;
  int iVar7;
  int iVar8;
  _TVertex *p_Var9;
  Intro *pIVar10;
  int iVar11;
  int iVar12;
  short *psVar13;
  int iVar14;
  short *psVar15;
  uchar *puVar16;
  _TVertex *p_Var17;
  _Instance *instance;
  BSPTree *pBVar18;
  SVECTOR local_28;
  uint local_20;
  ushort local_1c;
  short local_18;
  short local_16;
  short local_14 [2];
  
  instance = (gameTrackerX.instanceList)->first;
  if (time < 0x1f5) {
    time = time * 2;
    iVar7 = (time * time * time) / 2000000;
  }
  else {
    iVar7 = (1000 - time) * 2;
    iVar7 = 1000 - (iVar7 * iVar7 * iVar7) / 2000000;
  }
  psVar15 = (short *)BaseLevel->terrain->numBSPTrees;
  iVar7 = (iVar7 << 0xc) / 1000;
  if ((psVar15 != (short *)0x0) && (sVar4 = psVar15[3], -1 < psVar15[3])) {
    psVar13 = psVar15 + 3;
    do {
      p_Var9 = BaseLevel->terrain->vertexList + sVar4;
      (p_Var9->vertex).x = psVar13[1] + (short)(*psVar15 * iVar7 >> 0xc);
      (p_Var9->vertex).y = psVar13[2] + (short)(psVar13[-2] * iVar7 >> 0xc);
      psVar1 = psVar13 + -1;
      psVar2 = psVar13 + 3;
      psVar13 = psVar13 + 7;
      (p_Var9->vertex).z = *psVar2 + (short)(*psVar1 * iVar7 >> 0xc);
      sVar4 = *psVar13;
      psVar15 = psVar15 + 7;
    } while (-1 < *psVar13);
  }
  while (instance != (_Instance *)0x0) {
    pIVar10 = instance->intro;
    if ((pIVar10 != (Intro *)0x0) &&
       ((*(int *)&pIVar10->spectralPosition != 0 || ((pIVar10->spectralPosition).z != 0)))) {
      sVar4 = (pIVar10->spectralPosition).y;
      sVar3 = (pIVar10->spectralPosition).z;
      local_20 = *(uint *)&instance->position;
      local_1c = (instance->position).z;
      (instance->position).x =
           (pIVar10->position).x + (short)((pIVar10->spectralPosition).x * iVar7 >> 0xc);
      (instance->position).y = (pIVar10->position).y + (short)(sVar4 * iVar7 >> 0xc);
      (instance->position).z = (pIVar10->position).z + (short)(sVar3 * iVar7 >> 0xc);
      iVar14 = (uint)(ushort)(instance->position).x - (local_20 & 0xffff);
      local_28.vx = (short)iVar14;
      iVar11 = (uint)(ushort)(instance->position).y - (local_20 >> 0x10);
      local_28.vy = (short)iVar11;
      iVar8 = (uint)(ushort)(instance->position).z - (uint)local_1c;
      local_28.vz = (short)iVar8;
      if ((iVar14 * 0x10000 >> 0x10) + (iVar11 * 0x10000 >> 0x10) + (iVar8 * 0x10000 >> 0x10) != 0)
      {
        COLLIDE_UpdateAllTransforms(instance,&local_28);
      }
    }
    instance = instance->next;
  }
  pBVar18 = BaseLevel->terrain->BSPTreeArray;
  if (pBVar18 != (BSPTree *)0x0) {
    GAMELOOP_GetTimeOfDayLighting
              (BaseLevel,&local_18,&local_16,local_14,&BaseLevel->backColorR,&BaseLevel->holdFogNear
               ,&BaseLevel->holdFogFar);
    p_Var9 = BaseLevel->terrain->vertexList;
    p_Var17 = p_Var9 + BaseLevel->terrain->numVertices;
    if (p_Var9 < p_Var17) {
      puVar16 = &p_Var9->b0;
      do {
        uVar5 = *(ushort *)(puVar16 + -4);
        iVar8 = (int)local_18 * ((uint)uVar5 & 0x1f) * 8 * 0x10;
        pp_Var6 = &pBVar18->bspRoot;
        iVar14 = (uint)*(ushort *)pp_Var6 << 0x10;
        iVar11 = (int)local_16 * ((uint)(uVar5 >> 2) & 0xf8) * 0x10;
        iVar12 = (int)((int)local_14[0] * ((uint)(uVar5 >> 7) & 0xf8)) >> 0xc;
        p_Var9 = p_Var9 + 1;
        pBVar18 = (BSPTree *)((int)&pBVar18->bspRoot + 2);
        puVar16[-2] = (char)((uint)iVar8 >> 0x10) +
                      (char)((int)((((uint)*(ushort *)pp_Var6 & 0x1f) * 8 - (iVar8 >> 0x10)) * iVar7
                                  ) >> 0xc);
        puVar16[-1] = (char)((uint)iVar11 >> 0x10) +
                      (char)((int)(((iVar14 >> 0x12 & 0xf8U) - (iVar11 >> 0x10)) * iVar7) >> 0xc);
        *puVar16 = (char)iVar12 + (char)((int)(((iVar14 >> 0x17 & 0xf8U) - iVar12) * iVar7) >> 0xc);
        puVar16 = puVar16 + 0xc;
      } while (p_Var9 < p_Var17);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_SubtractOffsets(struct Level *BaseLevel /*$s2*/, int time /*$a1*/)
 // line 3754, offset 0x8005e840
	/* begin block 1 */
		// Start line: 3755
		// Start offset: 0x8005E840
		// Variables:
	// 		struct _TVertex *v; // $a3
	// 		struct _MorphVertex *mv; // $a2
	// 		struct _MorphColor *mc; // $s0
	// 		long m; // $v0
	// 		long fixed_time; // $s1
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 3800
			// Start offset: 0x8005E9FC
			// Variables:
		// 		struct SVECTOR diff; // stack offset -48
		// 		struct SVECTOR realDiff; // stack offset -40
		// 		struct _Position oldPos; // stack offset -32
		/* end block 1.1 */
		// End offset: 0x8005EAF8
		// End Line: 3820

		/* begin block 1.2 */
			// Start line: 3829
			// Start offset: 0x8005EB20
			// Variables:
		// 		long r0; // $a2
		// 		long g0; // $a1
		// 		long b0; // $a0
		// 		long r1; // $v0
		// 		long g1; // $v0
		// 		long b1; // $v1
		// 		short tr; // stack offset -24
		// 		short tg; // stack offset -22
		// 		short tb; // stack offset -20

			/* begin block 1.2.1 */
				// Start line: 3833
				// Start offset: 0x8005EB20
				// Variables:
			// 		struct _TVertex *endv; // $t3
			/* end block 1.2.1 */
			// End offset: 0x8005EC50
			// End Line: 3850
		/* end block 1.2 */
		// End offset: 0x8005EC50
		// End Line: 3873
	/* end block 1 */
	// End offset: 0x8005EC50
	// End Line: 3875

	/* begin block 2 */
		// Start line: 8884
	/* end block 2 */
	// End Line: 8885

	/* begin block 3 */
		// Start line: 8890
	/* end block 3 */
	// End Line: 8891

void MORPH_SubtractOffsets(Level *BaseLevel,int time)

{
  short *psVar1;
  short *psVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  _BSPNode **pp_Var6;
  int iVar7;
  int iVar8;
  _TVertex *p_Var9;
  Intro *pIVar10;
  int iVar11;
  int iVar12;
  short *psVar13;
  int iVar14;
  short *psVar15;
  uchar *puVar16;
  _TVertex *p_Var17;
  _Instance *instance;
  BSPTree *pBVar18;
  SVECTOR local_28;
  uint local_20;
  ushort local_1c;
  short local_18;
  short local_16;
  short local_14 [2];
  
  instance = (gameTrackerX.instanceList)->first;
  if (time < 0x1f5) {
    time = time * 2;
    iVar7 = (time * time * time) / 2000000;
  }
  else {
    iVar7 = (1000 - time) * 2;
    iVar7 = 1000 - (iVar7 * iVar7 * iVar7) / 2000000;
  }
  psVar15 = (short *)BaseLevel->terrain->numBSPTrees;
  iVar7 = ((1000 - iVar7) * 0x1000) / 1000;
  if ((psVar15 != (short *)0x0) && (sVar4 = psVar15[3], -1 < psVar15[3])) {
    psVar13 = psVar15 + 3;
    do {
      p_Var9 = BaseLevel->terrain->vertexList + sVar4;
      (p_Var9->vertex).x = psVar13[1] + (short)(*psVar15 * iVar7 >> 0xc);
      (p_Var9->vertex).y = psVar13[2] + (short)(psVar13[-2] * iVar7 >> 0xc);
      psVar1 = psVar13 + -1;
      psVar2 = psVar13 + 3;
      psVar13 = psVar13 + 7;
      (p_Var9->vertex).z = *psVar2 + (short)(*psVar1 * iVar7 >> 0xc);
      sVar4 = *psVar13;
      psVar15 = psVar15 + 7;
    } while (-1 < *psVar13);
  }
  while (instance != (_Instance *)0x0) {
    pIVar10 = instance->intro;
    if ((pIVar10 != (Intro *)0x0) &&
       ((*(int *)&pIVar10->spectralPosition != 0 || ((pIVar10->spectralPosition).z != 0)))) {
      sVar4 = (pIVar10->spectralPosition).y;
      sVar3 = (pIVar10->spectralPosition).z;
      local_20 = *(uint *)&instance->position;
      local_1c = (instance->position).z;
      (instance->position).x =
           (pIVar10->position).x + (short)((pIVar10->spectralPosition).x * iVar7 >> 0xc);
      (instance->position).y = (pIVar10->position).y + (short)(sVar4 * iVar7 >> 0xc);
      (instance->position).z = (pIVar10->position).z + (short)(sVar3 * iVar7 >> 0xc);
      iVar14 = (uint)(ushort)(instance->position).x - (local_20 & 0xffff);
      local_28.vx = (short)iVar14;
      iVar11 = (uint)(ushort)(instance->position).y - (local_20 >> 0x10);
      local_28.vy = (short)iVar11;
      iVar8 = (uint)(ushort)(instance->position).z - (uint)local_1c;
      local_28.vz = (short)iVar8;
      if ((iVar14 * 0x10000 >> 0x10) + (iVar11 * 0x10000 >> 0x10) + (iVar8 * 0x10000 >> 0x10) != 0)
      {
        COLLIDE_UpdateAllTransforms(instance,&local_28);
      }
    }
    instance = instance->next;
  }
  pBVar18 = BaseLevel->terrain->BSPTreeArray;
  if (pBVar18 != (BSPTree *)0x0) {
    GAMELOOP_GetTimeOfDayLighting
              (BaseLevel,&local_18,&local_16,local_14,&BaseLevel->backColorR,&BaseLevel->holdFogNear
               ,&BaseLevel->holdFogFar);
    p_Var9 = BaseLevel->terrain->vertexList;
    p_Var17 = p_Var9 + BaseLevel->terrain->numVertices;
    if (p_Var9 < p_Var17) {
      puVar16 = &p_Var9->b0;
      do {
        uVar5 = *(ushort *)(puVar16 + -4);
        iVar8 = (int)local_18 * ((uint)uVar5 & 0x1f) * 8 * 0x10;
        pp_Var6 = &pBVar18->bspRoot;
        iVar14 = (uint)*(ushort *)pp_Var6 << 0x10;
        iVar11 = (int)local_16 * ((uint)(uVar5 >> 2) & 0xf8) * 0x10;
        iVar12 = (int)((int)local_14[0] * ((uint)(uVar5 >> 7) & 0xf8)) >> 0xc;
        p_Var9 = p_Var9 + 1;
        pBVar18 = (BSPTree *)((int)&pBVar18->bspRoot + 2);
        puVar16[-2] = (char)((uint)iVar8 >> 0x10) +
                      (char)((int)((((uint)*(ushort *)pp_Var6 & 0x1f) * 8 - (iVar8 >> 0x10)) * iVar7
                                  ) >> 0xc);
        puVar16[-1] = (char)((uint)iVar11 >> 0x10) +
                      (char)((int)(((iVar14 >> 0x12 & 0xf8U) - (iVar11 >> 0x10)) * iVar7) >> 0xc);
        *puVar16 = (char)iVar12 + (char)((int)(((iVar14 >> 0x17 & 0xf8U) - iVar12) * iVar7) >> 0xc);
        puVar16 = puVar16 + 0xc;
      } while (p_Var9 < p_Var17);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_GetComponentsForTrackingPoint(struct _TFace *face /*$s1*/)
 // line 3880, offset 0x8005ec68
	/* begin block 1 */
		// Start line: 3881
		// Start offset: 0x8005EC68
		// Variables:
	// 		struct _Vector v1; // stack offset -64
	// 		struct _Vector v2; // stack offset -48
	// 		struct _Vector p1; // stack offset -32
	// 		long lv1; // $s2
	// 		long lv2; // $a1
	// 		struct Level *level; // $s0

		/* begin block 1.1 */
			// Start line: 3891
			// Start offset: 0x8005EC8C
			// Variables:
		// 		long _x0; // $a0
		// 		long _y0; // $a3
		// 		long _z0; // $a2
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $v1
		// 		struct _Vector *_v; // $v0
		// 		struct _Vertex *_v0; // $v1
		// 		struct _Vertex *_v1; // $a1
		/* end block 1.1 */
		// End offset: 0x8005EC8C
		// End Line: 3891

		/* begin block 1.2 */
			// Start line: 3891
			// Start offset: 0x8005EC8C
			// Variables:
		// 		long _x0; // $a0
		// 		long _y0; // $t0
		// 		long _z0; // $a3
		// 		long _x1; // $v1
		// 		long _y1; // $v1
		// 		long _z1; // $a1
		// 		struct _Vector *_v; // $v1
		// 		struct _Vertex *_v0; // $a1
		// 		struct _Vertex *_v1; // $a2
		/* end block 1.2 */
		// End offset: 0x8005EC8C
		// End Line: 3891

		/* begin block 1.3 */
			// Start line: 3891
			// Start offset: 0x8005EC8C
			// Variables:
		// 		long _x0; // $t2
		// 		long _y0; // $t0
		// 		long _z0; // $a2
		// 		long _x1; // $v1
		// 		long _y1; // $v1
		// 		long _z1; // $a0
		// 		struct _Vector *_v; // $a3
		// 		struct _Position *_v0; // $a2
		// 		struct _Vertex *_v1; // $a0
		/* end block 1.3 */
		// End offset: 0x8005EC8C
		// End Line: 3891

		/* begin block 1.4 */
			// Start line: 3891
			// Start offset: 0x8005EC8C
			// Variables:
		// 		long _x0; // $t2
		// 		long _y0; // $t0
		// 		long _z0; // $a2
		// 		long _x1; // $v1
		// 		long _y1; // $a1
		// 		long _z1; // $a0
		// 		struct _Position *_v1; // $a0
		/* end block 1.4 */
		// End offset: 0x8005EC8C
		// End Line: 3891
	/* end block 1 */
	// End offset: 0x8005EF1C
	// End Line: 3919

	/* begin block 2 */
		// Start line: 9213
	/* end block 2 */
	// End Line: 9214

void MORPH_GetComponentsForTrackingPoint(_TFace *face)

{
  Level *pLVar1;
  long lVar2;
  long lVar3;
  _TVertex *p_Var4;
  long *plVar5;
  int x;
  int x_00;
  _TVertex *p_Var6;
  int z;
  int iVar7;
  int y;
  int z_00;
  int y_00;
  int iVar8;
  int iVar9;
  
  MORPH_SavedFace = face;
  if (face != (_TFace *)0x0) {
    pLVar1 = STREAM_GetLevelWithID((gameTrackerX.playerInstance)->currentStreamUnitID);
    p_Var6 = pLVar1->terrain->vertexList;
    p_Var4 = p_Var6 + (face->face)._3;
    p_Var6 = p_Var6 + (face->face)._2;
    x = (int)(p_Var4->vertex).x - (int)(p_Var6->vertex).x;
    z = (int)(p_Var4->vertex).z - (int)(p_Var6->vertex).z;
    y = (int)(p_Var4->vertex).y - (int)(p_Var6->vertex).y;
    lVar2 = MATH3D_LengthXYZ(x,y,z);
    p_Var6 = pLVar1->terrain->vertexList;
    p_Var4 = p_Var6 + (face->face).v2;
    p_Var6 = p_Var6 + (face->face)._2;
    x_00 = (int)(p_Var4->vertex).x - (int)(p_Var6->vertex).x;
    z_00 = (int)(p_Var4->vertex).z - (int)(p_Var6->vertex).z;
    y_00 = (int)(p_Var4->vertex).y - (int)(p_Var6->vertex).y;
    lVar3 = MATH3D_LengthXYZ(x_00,y_00,z_00);
    p_Var4 = pLVar1->terrain->vertexList + (face->face)._2;
    plVar5 = &pLVar1->terrain->signals->numSignals + (gameTrackerX.playerInstance)->bspTree * 9;
    iVar9 = ((int)((gameTrackerX.playerInstance)->position).x - (int)(p_Var4->vertex).x) -
            (int)*(short *)(plVar5 + 3);
    iVar8 = ((int)((gameTrackerX.playerInstance)->position).y - (int)(p_Var4->vertex).y) -
            (int)*(short *)((int)plVar5 + 0xe);
    iVar7 = ((int)((gameTrackerX.playerInstance)->position).z - (int)(p_Var4->vertex).z) -
            (int)*(short *)(plVar5 + 4);
    if (lVar2 == 0) {
      MORPH_A_Component = 0;
    }
    else {
      MORPH_A_Component = ((iVar9 * x + iVar8 * y + iVar7 * z) * 0x1000) / (lVar2 * lVar2);
    }
    if (lVar3 == 0) {
      MORPH_B_Component = 0;
    }
    else {
      MORPH_B_Component = ((iVar9 * x_00 + iVar8 * y_00 + iVar7 * z_00) * 0x1000) / (lVar3 * lVar3);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_UpdateTrackingPoint(struct _Vector *point /*$s1*/, struct _TFace *face /*$s0*/)
 // line 3921, offset 0x8005ef34
	/* begin block 1 */
		// Start line: 3922
		// Start offset: 0x8005EF34
		// Variables:
	// 		struct _Vector v1; // stack offset -48
	// 		struct _Vector v2; // stack offset -32
	// 		struct Level *level; // $v0

		/* begin block 1.1 */
			// Start line: 3931
			// Start offset: 0x8005EF50
			// Variables:
		// 		long _x0; // $t0
		// 		long _y0; // $a3
		// 		long _z0; // $a2
		// 		long _x1; // $v1
		// 		long _y1; // $v1
		// 		long _z1; // $a0
		// 		struct _Vector *_v; // $v1
		// 		struct _Vertex *_v0; // $a0
		// 		struct _Vertex *_v1; // $a1
		/* end block 1.1 */
		// End offset: 0x8005EF50
		// End Line: 3931

		/* begin block 1.2 */
			// Start line: 3931
			// Start offset: 0x8005EF50
			// Variables:
		// 		long _x0; // $a2
		// 		long _y0; // $t0
		// 		long _z0; // $a3
		// 		long _x1; // $a0
		// 		long _y1; // $v1
		// 		long _z1; // $a0
		// 		struct _Vector *_v; // $v1
		// 		struct _Vertex *_v0; // $v1
		// 		struct _Vertex *_v1; // $a1
		/* end block 1.2 */
		// End offset: 0x8005EF50
		// End Line: 3931
	/* end block 1 */
	// End offset: 0x8005F130
	// End Line: 3964

	/* begin block 2 */
		// Start line: 9305
	/* end block 2 */
	// End Line: 9306

void MORPH_UpdateTrackingPoint(_Vector *point,_TFace *face)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  long lVar5;
  long lVar6;
  Level *pLVar7;
  _TVertex *p_Var8;
  _TVertex *p_Var9;
  _TVertex *p_Var10;
  _TVertex *p_Var11;
  int iVar12;
  int iVar13;
  
  if (face != (_TFace *)0x0) {
    pLVar7 = STREAM_GetLevelWithID((gameTrackerX.playerInstance)->currentStreamUnitID);
    lVar6 = MORPH_B_Component;
    lVar5 = MORPH_A_Component;
    p_Var10 = pLVar7->terrain->vertexList;
    p_Var9 = p_Var10 + (face->face)._3;
    p_Var10 = p_Var10 + (face->face)._2;
    sVar1 = (p_Var9->vertex).z;
    sVar2 = (p_Var10->vertex).z;
    p_Var11 = pLVar7->terrain->vertexList;
    p_Var8 = p_Var11 + (face->face).v2;
    sVar3 = (p_Var8->vertex).z;
    p_Var11 = p_Var11 + (face->face)._2;
    iVar12 = MORPH_A_Component * ((int)(p_Var9->vertex).y - (int)(p_Var10->vertex).y);
    sVar4 = (p_Var11->vertex).z;
    iVar13 = MORPH_B_Component * ((int)(p_Var8->vertex).y - (int)(p_Var11->vertex).y);
    point->x = (int)pLVar7->terrain->vertexList[(face->face)._2].vertex.x +
               (MORPH_A_Component * ((int)(p_Var9->vertex).x - (int)(p_Var10->vertex).x) * 0x10 >>
               0x10) + (MORPH_B_Component * ((int)(p_Var8->vertex).x - (int)(p_Var11->vertex).x) *
                        0x10 >> 0x10);
    point->y = (int)pLVar7->terrain->vertexList[(face->face)._2].vertex.y + (iVar12 * 0x10 >> 0x10)
               + (iVar13 * 0x10 >> 0x10);
    point->z = (int)pLVar7->terrain->vertexList[(face->face)._2].vertex.z +
               (lVar5 * ((int)sVar1 - (int)sVar2) * 0x10 >> 0x10) +
               (lVar6 * ((int)sVar3 - (int)sVar4) * 0x10 >> 0x10);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_ToggleMorph()
 // line 3966, offset 0x8005f144
	/* begin block 1 */
		// Start line: 3967
		// Start offset: 0x8005F144

		/* begin block 1.1 */
			// Start line: 3983
			// Start offset: 0x8005F1A0
			// Variables:
		// 		struct Level *level; // $a0
		// 		int i; // $s1
		/* end block 1.1 */
		// End offset: 0x8005F250
		// End Line: 4016
	/* end block 1 */
	// End offset: 0x8005F250
	// End Line: 4018

	/* begin block 2 */
		// Start line: 9557
	/* end block 2 */
	// End Line: 9558

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MORPH_ToggleMorph(void)

{
  _MultiSignal *p_Var1;
  Level *pLVar2;
  Level **ppLVar3;
  int iVar4;
  
  INSTANCE_Broadcast((_Instance *)0x0,10,0x1000020,(int)gameTrackerX.gameData.asmData.MorphType);
  iVar4 = 0x10;
  MORPH_GetComponentsForTrackingPoint((gameTrackerX.playerInstance)->tface);
  MORPH_UpdateTrackingPoint(&MORPH_BasePoint,(gameTrackerX.playerInstance)->tface);
  gameTrackerX.gameData.asmData.MorphTime = 0;
  ppLVar3 = &StreamTracker.StreamList[0].level;
  SOUND_Play3dSound(&(gameTrackerX.playerInstance)->position,0x1b,-0x15e,0x7f,0x7fff);
  do {
    if (*(short *)(ppLVar3 + -1) == 2) {
      pLVar2 = *ppLVar3;
      if (gameTrackerX.gameData.asmData.MorphType == 1) {
        p_Var1 = pLVar2->materialSignal;
        if (p_Var1 != (_MultiSignal *)0x0) {
          p_Var1->flags = p_Var1->flags | 1;
          p_Var1 = pLVar2->materialSignal;
LAB_8005f238:
          SIGNAL_HandleSignal(gameTrackerX.playerInstance,p_Var1->signalList,0);
        }
      }
      else {
        p_Var1 = pLVar2->spectralSignal;
        if (p_Var1 != (_MultiSignal *)0x0) {
          p_Var1->flags = p_Var1->flags | 1;
          p_Var1 = pLVar2->spectralSignal;
          goto LAB_8005f238;
        }
      }
    }
    iVar4 = iVar4 + -1;
    ppLVar3 = ppLVar3 + 0x10;
    if (iVar4 < 1) {
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_DoStep(struct _StreamUnit *streamUnit /*$s0*/, char *baseAreaName /*$a1*/)
 // line 4020, offset 0x8005f264
	/* begin block 1 */
		// Start line: 4021
		// Start offset: 0x8005F264
		// Variables:
	// 		struct _Vector vpoint; // stack offset -40
	// 		struct _Vector hpoint; // stack offset -24
	// 		struct Level *level; // $s0

		/* begin block 1.1 */
			// Start line: 4046
			// Start offset: 0x8005F2D8
			// Variables:
		// 		long _x1; // $a0
		// 		long _y1; // $v1
		// 		long _z1; // $a1
		// 		struct _Vector *_v0; // $t2
		// 		struct _Vector *_v1; // $t0
		/* end block 1.1 */
		// End offset: 0x8005F2D8
		// End Line: 4046

		/* begin block 1.2 */
			// Start line: 4046
			// Start offset: 0x8005F2D8
			// Variables:
		// 		long _x0; // $a0
		// 		long _y0; // $v1
		// 		long _z0; // $a1
		// 		long _x1; // $v0
		// 		long _y1; // $a2
		// 		long _z1; // $v0
		// 		struct _Vector *_v1; // $t3
		/* end block 1.2 */
		// End offset: 0x8005F2D8
		// End Line: 4046

		/* begin block 1.3 */
			// Start line: 4046
			// Start offset: 0x8005F2D8
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a0
		// 		short _x1; // $a3
		// 		short _y1; // $t1
		// 		short _z1; // $t0
		// 		struct _Position *_v; // $a1
		/* end block 1.3 */
		// End offset: 0x8005F2D8
		// End Line: 4046

		/* begin block 1.4 */
			// Start line: 4046
			// Start offset: 0x8005F2D8
			// Variables:
		// 		short _x1; // $a0
		// 		short _y1; // $a1
		// 		short _z1; // $v1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v1
		/* end block 1.4 */
		// End offset: 0x8005F2D8
		// End Line: 4046

		/* begin block 1.5 */
			// Start line: 4046
			// Start offset: 0x8005F2D8
			// Variables:
		// 		long _x1; // $v0
		// 		long _y1; // $v1
		// 		long _z1; // $a0
		/* end block 1.5 */
		// End offset: 0x8005F2D8
		// End Line: 4046
	/* end block 1 */
	// End offset: 0x8005F488
	// End Line: 4094

	/* begin block 2 */
		// Start line: 9698
	/* end block 2 */
	// End Line: 9699

/* WARNING: Could not reconcile some variable overlaps */

void MORPH_DoStep(_StreamUnit *streamUnit,char *baseAreaName)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  _Position *p_Var4;
  _Instance *p_Var5;
  int time;
  int iVar6;
  _TFace *face;
  int iVar7;
  Level *level;
  int local_28;
  int local_24;
  int local_20;
  int local_18;
  int local_14;
  int local_10;
  
  GAMEPAD_Shock1(0x40,0xf000);
  level = streamUnit->level;
  if (level->terrain->numBSPTrees != 0) {
    face = (gameTrackerX.playerInstance)->tface;
    if ((face != (_TFace *)0x0) && (level == (Level *)(gameTrackerX.playerInstance)->tfaceLevel)) {
      if (MORPH_SavedFace == face) {
        MORPH_UpdateTrackingPoint((_Vector *)&local_28,face);
        p_Var5 = gameTrackerX.playerInstance;
        local_18 = local_28;
        local_14 = local_24;
        local_10 = local_20;
        iVar6 = local_28 - MORPH_BasePoint.x;
        time = local_24 - MORPH_BasePoint.y;
        local_24._0_2_ = (short)time;
        iVar7 = local_20 - MORPH_BasePoint.z;
        p_Var4 = &(gameTrackerX.playerInstance)->position;
        sVar2 = ((gameTrackerX.playerInstance)->position).z;
        local_28._0_2_ = (short)iVar6;
        local_20._0_2_ = (short)iVar7;
        ((gameTrackerX.playerInstance)->position).x =
             ((gameTrackerX.playerInstance)->position).x + (short)local_28;
        (p_Var5->position).y = p_Var4->y + (short)local_24;
        (p_Var5->position).z = sVar2 + (short)local_20;
        p_Var5 = gameTrackerX.playerInstance;
        sVar2 = ((gameTrackerX.playerInstance)->position).y;
        sVar3 = ((gameTrackerX.playerInstance)->position).z;
        ((gameTrackerX.playerInstance)->oldPos).x = ((gameTrackerX.playerInstance)->position).x;
        (p_Var5->oldPos).y = sVar2;
        (p_Var5->oldPos).z = sVar3;
        MORPH_BasePoint.x = local_28;
        MORPH_BasePoint.y = local_24;
        MORPH_BasePoint.z = local_20;
        local_28 = iVar6;
        local_24 = time;
        local_20 = iVar7;
      }
      else {
        MORPH_GetComponentsForTrackingPoint(face);
        MORPH_UpdateTrackingPoint(&MORPH_BasePoint,(gameTrackerX.playerInstance)->tface);
        MORPH_SavedFace = (gameTrackerX.playerInstance)->tface;
      }
    }
    GAMELOOP_UpdateWorldInstTimeOfDay((int)gameTrackerX.currentMaterialTime._2_2_);
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
      GAMELOOP_UpdateWorldInstTimeOfDay((int)gameTrackerX.currentMaterialTime._2_2_);
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
 // line 4096, offset 0x8005f498
	/* begin block 1 */
		// Start line: 4097
		// Start offset: 0x8005F498
		// Variables:
	// 		long time; // $v1
	// 		struct Level *level; // $a2
	// 		int fogNear; // $a1
	// 		int fogFar; // $v0
	/* end block 1 */
	// End offset: 0x8005F55C
	// End Line: 4119

	/* begin block 2 */
		// Start line: 9856
	/* end block 2 */
	// End Line: 9857

	/* begin block 3 */
		// Start line: 9862
	/* end block 3 */
	// End Line: 9863

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
 // line 4121, offset 0x8005f56c
	/* begin block 1 */
		// Start line: 4122
		// Start offset: 0x8005F56C
		// Variables:
	// 		long time; // $a0
	/* end block 1 */
	// End offset: 0x8005F5AC
	// End Line: 4132

	/* begin block 2 */
		// Start line: 9916
	/* end block 2 */
	// End Line: 9917

	/* begin block 3 */
		// Start line: 9919
	/* end block 3 */
	// End Line: 9920

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
 // line 4136, offset 0x8005f5c4
	/* begin block 1 */
		// Start line: 4137
		// Start offset: 0x8005F5C4
		// Variables:
	// 		int i; // $s2
	/* end block 1 */
	// End offset: 0x8005F6CC
	// End Line: 4179

	/* begin block 2 */
		// Start line: 9949
	/* end block 2 */
	// End Line: 9950

	/* begin block 3 */
		// Start line: 9953
	/* end block 3 */
	// End Line: 9954

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MORPH_Continue(void)

{
  STracker *streamUnit;
  char *baseAreaName;
  int iVar1;
  
  if (gameTrackerX.gameData.asmData.MorphTime == 0) {
    MORPH_InMorphInstanceListFlags(&gameTrackerX);
  }
  iVar1 = 0;
  baseAreaName = StreamTracker.StreamList[0].baseAreaName;
  streamUnit = &StreamTracker;
  gameTrackerX.gameData.asmData.MorphTime = gameTrackerX.gameData.asmData.MorphTime + 0x14;
  MORPH_InMorphDoFadeValues(&gameTrackerX);
  do {
    if (*(short *)streamUnit->StreamList == 2) {
      MORPH_DoStep((_StreamUnit *)streamUnit,baseAreaName);
      MORPH_SetFog((_StreamUnit *)streamUnit,0);
    }
    baseAreaName = baseAreaName + 0x40;
    iVar1 = iVar1 + 1;
    streamUnit = (STracker *)(streamUnit->StreamList + 1);
  } while (iVar1 < 0x10);
  MORPH_UpdateTextures();
  if (gameTrackerX.gameData.asmData.MorphTime == 1000) {
    gameTrackerX.gameData.asmData.MorphType = gameTrackerX.gameData.asmData.MorphType ^ 1;
    if (gameTrackerX.gameData.asmData.MorphType == 0) {
      (gameTrackerX.playerInstance)->flags2 = (gameTrackerX.playerInstance)->flags2 & 0xf7ffffff;
    }
    else {
      (gameTrackerX.playerInstance)->flags2 = (gameTrackerX.playerInstance)->flags2 | 0x8000000;
    }
    MORPH_SetupInstanceListFlags(&gameTrackerX);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_MORPH_Relocate()
 // line 4180, offset 0x8005f6e8
	/* begin block 1 */
		// Start line: 10060
	/* end block 1 */
	// End Line: 10061

	/* begin block 2 */
		// Start line: 10061
	/* end block 2 */
	// End Line: 10062

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_MORPH_Relocate(void)

{
  MORPH_SavedFace = (_TFace *)0x0;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ AddVertex(struct VECTOR *v0 /*$a0*/, struct RECT *rect /*$t0*/)
 // line 4342, offset 0x8005f6f4
	/* begin block 1 */
		// Start line: 4343
		// Start offset: 0x8005F6F4
		// Variables:
	// 		struct SVECTOR v; // stack offset -8
	// 		int x; // $v0
	// 		int y; // $v1
	// 		int z; // $a1
	// 		int scr_x; // $a0
	// 		int scr_y; // $a1
	/* end block 1 */
	// End offset: 0x8005F878
	// End Line: 4379

	/* begin block 2 */
		// Start line: 10384
	/* end block 2 */
	// End Line: 10385

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
LAB_8005f718:
    v0->vx = iVar2 + iVar1;
  }
  else {
    iVar1 = 0x8000;
    if (0 < iVar2) goto LAB_8005f718;
  }
  iVar1 = v0->vy;
  iVar2 = -0x8000;
  if ((iVar1 < 0) || (iVar2 = 0x8000, 0 < iVar1)) {
    v0->vy = iVar1 + iVar2;
  }
  iVar1 = v0->vz;
  iVar2 = -0x8000;
  if (-1 < iVar1) {
    if (iVar1 < 1) goto LAB_8005f764;
    iVar2 = 0x8000;
  }
  v0->vz = iVar1 + iVar2;
LAB_8005f764:
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
 // line 4381, offset 0x8005f880
	/* begin block 1 */
		// Start line: 10467
	/* end block 1 */
	// End Line: 10468

	/* begin block 2 */
		// Start line: 10468
	/* end block 2 */
	// End Line: 10469

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
 // line 4390, offset 0x8005f910
	/* begin block 1 */
		// Start line: 4391
		// Start offset: 0x8005F910
		// Variables:
	// 		int diff; // $a3
	/* end block 1 */
	// End offset: 0x8005F910
	// End Line: 4391

	/* begin block 2 */
		// Start line: 10485
	/* end block 2 */
	// End Line: 10486

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
 // line 4404, offset 0x8005f998
	/* begin block 1 */
		// Start line: 4405
		// Start offset: 0x8005F998
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
			// Start line: 4481
			// Start offset: 0x8005FBD0
			// Variables:
		// 		int z; // $v0
		/* end block 1.1 */
		// End offset: 0x8005FBFC
		// End Line: 4485
	/* end block 1 */
	// End offset: 0x8005FC10
	// End Line: 4487

	/* begin block 2 */
		// Start line: 10513
	/* end block 2 */
	// End Line: 10514

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
            goto LAB_8005fb6c;
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
LAB_8005fb6c:
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
 // line 4489, offset 0x8005fc40
	/* begin block 1 */
		// Start line: 4490
		// Start offset: 0x8005FC40
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
			// Start line: 4578
			// Start offset: 0x8005FF34
			// Variables:
		// 		int dot; // $v0
		/* end block 1.1 */
		// End offset: 0x8005FFB4
		// End Line: 4588
	/* end block 1 */
	// End offset: 0x800601DC
	// End Line: 4655

	/* begin block 2 */
		// Start line: 10800
	/* end block 2 */
	// End Line: 10801

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
  sVar9 = portal->_9[0].z;
  iVar17 = (int)sVar9;
  iVar11 = (int)portal->_9[1].z;
  local_30 = 0;
  if (iVar17 == iVar11) {
    local_30 = (uint)(sVar9 == portal->_9[2].z);
  }
  iVar10 = (int)portal->_9[0].y;
  iVar15 = iVar10 - portal->_9[1].y;
  iVar13 = iVar17 - portal->_9[2].z;
  iVar11 = iVar17 - iVar11;
  iVar6 = iVar10 - portal->_9[2].y;
  iVar7 = (int)portal->_9[0].x;
  iVar12 = iVar7 - portal->_9[2].x;
  iVar2 = iVar7 - portal->_9[1].x;
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
    iVar7 = (int)portal->_10[0].y;
    iVar10 = (int)portal->_10[0].z;
    iVar16 = iVar7 - portal->_10[1].y;
    iVar14 = iVar10 - portal->_10[2].z;
    iVar12 = iVar10 - portal->_10[1].z;
    iVar2 = iVar7 - portal->_10[2].y;
    iVar6 = (int)portal->_10[0].x;
    iVar15 = iVar6 - portal->_10[2].x;
    iVar17 = iVar6 - portal->_10[1].x;
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
    uVar4 = AddClippedTri((SVECTOR *)portal->_9,rect,&local_40);
    uVar5 = AddClippedTri((SVECTOR *)portal->_10,rect,&local_3c);
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
 // line 4658, offset 0x8006020c
	/* begin block 1 */
		// Start line: 4659
		// Start offset: 0x8006020C
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
			// Start line: 4671
			// Start offset: 0x80060240
			// Variables:
		// 		int time; // $a2
		/* end block 1.1 */
		// End offset: 0x80060278
		// End Line: 4677
	/* end block 1 */
	// End offset: 0x8006051C
	// End Line: 4765

	/* begin block 2 */
		// Start line: 11309
	/* end block 2 */
	// End Line: 11310

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
  setCopReg(2,in_zero,*(undefined4 *)portal->_9);
  setCopReg(2,in_at,*(undefined4 *)&portal->_9[0].z);
  setCopReg(2,portal->_9 + 2,*(undefined4 *)(portal->_9 + 1));
  setCopReg(2,portal->_9 + 1,*(undefined4 *)&portal->_9[1].z);
  setCopReg(2,portal->_9,*(undefined4 *)(portal->_9 + 2));
  setCopReg(2,pLVar3,*(undefined4 *)&portal->_9[2].z);
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
    if (iVar6 <= iVar4) goto LAB_80060364;
  }
  iVar4 = iVar6;
LAB_80060364:
  setCopReg(2,in_zero,*(undefined4 *)portal->_10);
  setCopReg(2,in_at,*(undefined4 *)&portal->_10[0].z);
  setCopReg(2,portal->_10 + 2,*(undefined4 *)(portal->_10 + 1));
  setCopReg(2,portal->_10 + 1,*(undefined4 *)&portal->_10[1].z);
  setCopReg(2,portal->_10,*(undefined4 *)(portal->_10 + 2));
  setCopReg(2,iVar4,*(undefined4 *)&portal->_10[2].z);
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
  if ((int)(iVar4 + 0x40U) < (int)(uint)mainLevel->fogFar) {
    uVar1 = iVar4 + 0x40U;
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
 // line 4767, offset 0x80060530
	/* begin block 1 */
		// Start line: 4768
		// Start offset: 0x80060530
		// Variables:
	// 		struct POLY_G4 *polyg4; // $a1
	/* end block 1 */
	// End offset: 0x80060530
	// End Line: 4771

	/* begin block 2 */
		// Start line: 11539
	/* end block 2 */
	// End Line: 11540

	/* begin block 3 */
		// Start line: 11542
	/* end block 3 */
	// End Line: 11543

void DrawFogRectangle(RECT *cliprect,_PrimPool *primPool,int otzpos,ulong **drawot,long color)

{
  short sVar1;
  short sVar2;
  ulong *puVar3;
  
  puVar3 = (gameTrackerX.primPool)->nextPrim;
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
  puVar3[1] = color;
  puVar3[3] = color;
  puVar3[5] = color;
  puVar3[7] = color;
  *(undefined *)((int)puVar3 + 3) = 8;
  *(undefined *)((int)puVar3 + 7) = 0x38;
  *(short *)((int)puVar3 + 0x22) = sVar1 + sVar2;
  *puVar3 = (uint)drawot[otzpos] & 0xffffff | 0x8000000;
  drawot[otzpos] = (ulong *)((uint)puVar3 & 0xffffff);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_RenderAdjacantUnit(unsigned long **curOT /*$s3*/, struct StreamUnitPortal *curStreamPortal /*$s0*/, struct _StreamUnit *toStreamUnit /*$s1*/, struct _StreamUnit *mainStreamUnit /*$s2*/, struct RECT *cliprect /*stack 16*/)
 // line 4811, offset 0x8006060c
	/* begin block 1 */
		// Start line: 4812
		// Start offset: 0x8006060C

		/* begin block 1.1 */
			// Start line: 4816
			// Start offset: 0x80060644
			// Variables:
		// 		long portalFogColor; // $s0
		/* end block 1.1 */
		// End offset: 0x8006069C
		// End Line: 4828
	/* end block 1 */
	// End offset: 0x8006069C
	// End Line: 4829

	/* begin block 2 */
		// Start line: 11744
	/* end block 2 */
	// End Line: 11745

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
 // line 4831, offset 0x800606b8
	/* begin block 1 */
		// Start line: 4833
		// Start offset: 0x800606B8
		// Variables:
	// 		struct Level *level; // $v0
	// 		struct _Terrain *terrain; // $v0
	// 		int d; // $a0
	/* end block 1 */
	// End offset: 0x80060710
	// End Line: 4853

	/* begin block 2 */
		// Start line: 11790
	/* end block 2 */
	// End Line: 11791

	/* begin block 3 */
		// Start line: 11791
	/* end block 3 */
	// End Line: 11792

BSPTree * STREAM_GetBspTree(_StreamUnit *streamUnit,long bspNumber)

{
  _Terrain *p_Var1;
  short *psVar2;
  _MultiSignal *p_Var3;
  int iVar4;
  
  p_Var1 = streamUnit->level->terrain;
  psVar2 = p_Var1->morphNormalIdx;
  if ((psVar2 != (short *)0x0) && (iVar4 = 0, 0 < (int)psVar2)) {
    p_Var3 = p_Var1->signals;
    do {
      iVar4 = iVar4 + 1;
      if ((int)*(short *)p_Var3->signalList == bspNumber) {
        return (BSPTree *)p_Var3;
      }
      p_Var3 = (_MultiSignal *)(p_Var3->signalList + 1);
    } while (iVar4 < (int)psVar2);
  }
  return (BSPTree *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_BlockWarpGateEntrance(struct _StreamUnit *streamUnit /*$a0*/, long collideOn /*$s0*/)
 // line 4856, offset 0x80060718
	/* begin block 1 */
		// Start line: 4857
		// Start offset: 0x80060718
		// Variables:
	// 		struct BSPTree *bspTree; // $v1
	/* end block 1 */
	// End offset: 0x80060760
	// End Line: 4872

	/* begin block 2 */
		// Start line: 11844
	/* end block 2 */
	// End Line: 11845

void WARPGATE_BlockWarpGateEntrance(_StreamUnit *streamUnit,long collideOn)

{
  ushort uVar1;
  BSPTree *pBVar2;
  
  pBVar2 = STREAM_GetBspTree(streamUnit,7);
  if (pBVar2 != (BSPTree *)0x0) {
    if (collideOn == 0) {
      uVar1 = pBVar2->flags & 0xfffd;
    }
    else {
      uVar1 = pBVar2->flags | 2;
    }
    pBVar2->flags = uVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_DrawWarpGateRim(struct _StreamUnit *streamUnit /*$a0*/, long drawOn /*$s0*/)
 // line 4875, offset 0x80060770
	/* begin block 1 */
		// Start line: 4876
		// Start offset: 0x80060770
		// Variables:
	// 		struct BSPTree *bspTree; // $v1
	/* end block 1 */
	// End offset: 0x800607CC
	// End Line: 4896

	/* begin block 2 */
		// Start line: 11882
	/* end block 2 */
	// End Line: 11883

void WARPGATE_DrawWarpGateRim(_StreamUnit *streamUnit,long drawOn)

{
  ushort uVar1;
  ushort uVar2;
  BSPTree *pBVar3;
  
  pBVar3 = STREAM_GetBspTree(streamUnit,3);
  if (pBVar3 == (BSPTree *)0x0) {
    GXFilePrint("Can not found bsptree number %d\n");
  }
  else {
    uVar1 = pBVar3->flags;
    uVar2 = uVar1 & 0xfffd;
    pBVar3->flags = uVar2;
    if (drawOn == 0) {
      pBVar3->flags = uVar2 | 1;
    }
    else {
      pBVar3->flags = uVar1 & 0xfffc;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_HideAllCloudCovers()
 // line 4898, offset 0x800607dc
	/* begin block 1 */
		// Start line: 4900
		// Start offset: 0x800607DC
		// Variables:
	// 		struct Object *warpFaceObject; // $a1

		/* begin block 1.1 */
			// Start line: 4906
			// Start offset: 0x800607F0
			// Variables:
		// 		struct _Instance *instance; // $v1
		// 		struct _Instance *next; // $a0
		/* end block 1.1 */
		// End offset: 0x80060834
		// End Line: 4921
	/* end block 1 */
	// End offset: 0x80060834
	// End Line: 4923

	/* begin block 2 */
		// Start line: 11928
	/* end block 2 */
	// End Line: 11929

	/* begin block 3 */
		// Start line: 11929
	/* end block 3 */
	// End Line: 11930

	/* begin block 4 */
		// Start line: 11932
	/* end block 4 */
	// End Line: 11933

/* WARNING: Removing unreachable block (ram,0x800607f0) */
/* WARNING: Removing unreachable block (ram,0x80060808) */
/* WARNING: Removing unreachable block (ram,0x80060818) */
/* WARNING: Removing unreachable block (ram,0x80060828) */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void WARPGATE_HideAllCloudCovers(void)

{
  return;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ WARPGATE_UnHideCloudCoverInUnit(long streamUnitID /*$a0*/)
 // line 4925, offset 0x8006083c
	/* begin block 1 */
		// Start line: 4927
		// Start offset: 0x8006083C
		// Variables:
	// 		struct Object *warpFaceObject; // $a3
	// 		struct _Instance *result; // $a2

		/* begin block 1.1 */
			// Start line: 4934
			// Start offset: 0x80060850
			// Variables:
		// 		struct _Instance *instance; // $v1
		// 		struct _Instance *next; // $a1
		/* end block 1.1 */
		// End offset: 0x800608AC
		// End Line: 4952
	/* end block 1 */
	// End offset: 0x800608AC
	// End Line: 4954

	/* begin block 2 */
		// Start line: 11984
	/* end block 2 */
	// End Line: 11985

	/* begin block 3 */
		// Start line: 11985
	/* end block 3 */
	// End Line: 11986

	/* begin block 4 */
		// Start line: 11989
	/* end block 4 */
	// End Line: 11990

/* WARNING: Removing unreachable block (ram,0x80060850) */
/* WARNING: Removing unreachable block (ram,0x80060868) */
/* WARNING: Removing unreachable block (ram,0x80060878) */
/* WARNING: Removing unreachable block (ram,0x80060888) */
/* WARNING: Removing unreachable block (ram,0x800608a0) */

_Instance * WARPGATE_UnHideCloudCoverInUnit(long streamUnitID)

{
  return (_Instance *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_RenderWarpGate(unsigned long **mainOT /*$s3*/, struct StreamUnitPortal *curStreamPortal /*$s2*/, struct _StreamUnit *mainStreamUnit /*$s1*/, struct RECT *cliprect /*$s4*/)
 // line 4958, offset 0x800608b4
	/* begin block 1 */
		// Start line: 4959
		// Start offset: 0x800608B4
		// Variables:
	// 		struct _StreamUnit *toStreamUnit; // $s0
	/* end block 1 */
	// End offset: 0x80060A40
	// End Line: 5036

	/* begin block 2 */
		// Start line: 12055
	/* end block 2 */
	// End Line: 12056

void STREAM_RenderWarpGate
               (ulong **mainOT,StreamUnitPortal *curStreamPortal,_StreamUnit *mainStreamUnit,
               RECT *cliprect)

{
  _StreamUnit *streamUnit;
  
  WARPGATE_DrawWarpGateRim(mainStreamUnit,1);
  streamUnit = curStreamPortal->toStreamUnit;
  if (WarpGateLoadInfo.loading == 1) {
    if (WarpGateLoadInfo.maxTime < WarpGateLoadInfo.curTime) {
      if (streamUnit != (_StreamUnit *)0x0) {
        STREAM_DumpUnit(streamUnit,1);
        streamUnit = (_StreamUnit *)0x0;
      }
      WarpGateLoadInfo.loading = 2;
      STREAM_LoadCurrentWarpRoom(curStreamPortal,mainStreamUnit);
      (WarpGateLoadInfo.warpFaceInstance)->fadeValue = 0;
    }
    else {
      if (WarpGateLoadInfo.warpFaceInstance == (_Instance *)0x0) {
        WARPGATE_HideAllCloudCovers();
        WarpGateLoadInfo.warpFaceInstance =
             WARPGATE_UnHideCloudCoverInUnit(mainStreamUnit->StreamUnitID);
      }
      WARPGATE_CalcWarpFade(gameTrackerX.idleTime);
    }
  }
  else {
    if (WarpGateLoadInfo.loading == 2) {
      WarpGateLoadInfo.fadeValue = 0;
      if (streamUnit == (_StreamUnit *)0x0) goto LAB_80060a28;
      if (streamUnit->used == 2) {
        WarpGateLoadInfo.loading = 3;
        WarpGateLoadInfo.curTime = WarpGateLoadInfo.maxTime;
      }
    }
    else {
      if (WarpGateLoadInfo.loading == 3) {
        if (WarpGateLoadInfo.curTime < 0) {
          WARPGATE_HideAllCloudCovers();
          WarpGateLoadInfo.loading = 0;
        }
        else {
          WARPGATE_CalcWarpFade(-gameTrackerX.idleTime);
        }
      }
    }
  }
  if (streamUnit != (_StreamUnit *)0x0) {
    if (streamUnit->used != 2) {
      return;
    }
    WARPGATE_RenderWarpUnit(mainOT,curStreamPortal,mainStreamUnit,cliprect);
    return;
  }
LAB_80060a28:
  if (WarpGateLoadInfo.loading == 0) {
    WarpGateLoadInfo.loading = 1;
    WarpGateLoadInfo.curTime = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_RenderWarpUnit(unsigned long **mainOT /*$fp*/, struct StreamUnitPortal *curStreamPortal /*$s0*/, struct _StreamUnit *mainStreamUnit /*$s4*/, struct RECT *cliprect /*$s3*/)
 // line 5039, offset 0x80060a60
	/* begin block 1 */
		// Start line: 5040
		// Start offset: 0x80060A60
		// Variables:
	// 		unsigned long **curOT; // $s2
	// 		struct DR_AREA *PortalClip; // $s0
	// 		struct _StreamUnit *toStreamUnit; // $s1

		/* begin block 1.1 */
			// Start line: 5073
			// Start offset: 0x80060B28
			// Variables:
		// 		struct RECT PortalRect; // stack offset -48
		// 		long portalFogColor; // $s0

			/* begin block 1.1.1 */
				// Start line: 5127
				// Start offset: 0x80060CEC
				// Variables:
			// 		unsigned long *hld; // $a0
			/* end block 1.1.1 */
			// End offset: 0x80060D84
			// End Line: 5145
		/* end block 1.1 */
		// End offset: 0x80060D84
		// End Line: 5146
	/* end block 1 */
	// End offset: 0x80060D84
	// End Line: 5148

	/* begin block 2 */
		// Start line: 12224
	/* end block 2 */
	// End Line: 12225

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
                 0x28,0x28,0x23,1,gameTrackerX.primPool,drawot + 1);
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
 // line 5206, offset 0x80060db4
	/* begin block 1 */
		// Start line: 5207
		// Start offset: 0x80060DB4
		// Variables:
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 5214
			// Start offset: 0x80060DE0
			// Variables:
		// 		struct _Instance *next; // $s2
		// 		struct Object *object; // $s1
		/* end block 1.1 */
		// End offset: 0x80060E34
		// End Line: 5229
	/* end block 1 */
	// End offset: 0x80060E40
	// End Line: 5232

	/* begin block 2 */
		// Start line: 12601
	/* end block 2 */
	// End Line: 12602

	/* begin block 3 */
		// Start line: 12606
	/* end block 3 */
	// End Line: 12607

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
  STREAM_RemoveAllObjectsNotInUse(&gameTrackerX);
  return;
}





