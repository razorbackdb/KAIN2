#include "THISDUST.H"
#include "STREAM.H"


// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_FillOutFileNames(char *baseAreaName /*$s0*/, char *dramName /*$s1*/, char *vramName /*$s2*/, char *sfxName /*$s3*/)
 // line 161, offset 0x80058bd8
	/* begin block 1 */
		// Start line: 162
		// Start offset: 0x80058BD8
		// Variables:
	// 		char text[16]; // stack offset -40
	// 		char *number; // $v0
	/* end block 1 */
	// End offset: 0x80058C7C
	// End Line: 186

	/* begin block 2 */
		// Start line: 322
	/* end block 2 */
	// End Line: 323

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
 // line 191, offset 0x80058c98
	/* begin block 1 */
		// Start line: 192
		// Start offset: 0x80058C98
		// Variables:
	// 		char vramName[80]; // stack offset -88
	/* end block 1 */
	// End offset: 0x80058C98
	// End Line: 192

	/* begin block 2 */
		// Start line: 385
	/* end block 2 */
	// End Line: 386

void STREAM_AbortAreaLoad(char *baseAreaName)

{
  char acStack88 [80];
  
  STREAM_FillOutFileNames(baseAreaName,(char *)0x0,acStack88,(char *)0x0);
  LOAD_AbortFileLoad(acStack88,VRAM_LoadReturn);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_Init()
 // line 239, offset 0x80058cd0
	/* begin block 1 */
		// Start line: 241
		// Start offset: 0x80058CD0
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x80058CEC
	// End Line: 247

	/* begin block 2 */
		// Start line: 484
	/* end block 2 */
	// End Line: 485

	/* begin block 3 */
		// Start line: 485
	/* end block 3 */
	// End Line: 486

	/* begin block 4 */
		// Start line: 487
	/* end block 4 */
	// End Line: 488

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_Init(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0xf;
  iVar1 = -0x7ff2d234;
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
 // line 249, offset 0x80058cf4
	/* begin block 1 */
		// Start line: 250
		// Start offset: 0x80058CF4
		// Variables:
	// 		int i; // $s0
	// 		struct _ObjectTracker *otr; // $s1
	/* end block 1 */
	// End offset: 0x80058D48
	// End Line: 261

	/* begin block 2 */
		// Start line: 506
	/* end block 2 */
	// End Line: 507

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
 // line 263, offset 0x80058d60
	/* begin block 1 */
		// Start line: 265
		// Start offset: 0x80058D60
		// Variables:
	// 		int i; // $a2
	// 		struct _ObjectTracker *otr; // $a1
	/* end block 1 */
	// End offset: 0x80058DA8
	// End Line: 273

	/* begin block 2 */
		// Start line: 544
	/* end block 2 */
	// End Line: 545

	/* begin block 3 */
		// Start line: 545
	/* end block 3 */
	// End Line: 546

	/* begin block 4 */
		// Start line: 548
	/* end block 4 */
	// End Line: 549

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
 // line 291, offset 0x80058db0
	/* begin block 1 */
		// Start line: 293
		// Start offset: 0x80058DB0
		// Variables:
	// 		struct _StreamUnit *ret; // $a2
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x80058DFC
	// End Line: 305

	/* begin block 2 */
		// Start line: 579
	/* end block 2 */
	// End Line: 580

	/* begin block 3 */
		// Start line: 584
	/* end block 3 */
	// End Line: 585

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
 // line 361, offset 0x80058e04
	/* begin block 1 */
		// Start line: 362
		// Start offset: 0x80058E04
		// Variables:
	// 		struct Object *object; // $s0
	// 		struct _ObjectTracker *objectTracker; // $s1

		/* begin block 1.1 */
			// Start line: 400
			// Start offset: 0x80058E90
			// Variables:
		// 		char objDsfxFileName[64]; // stack offset -80
		/* end block 1.1 */
		// End offset: 0x80058EC8
		// End Line: 412
	/* end block 1 */
	// End offset: 0x80058EC8
	// End Line: 413

	/* begin block 2 */
		// Start line: 728
	/* end block 2 */
	// End Line: 729

void STREAM_LoadObjectReturn(void *loadData,void *data,void *data2)

{
  long lVar1;
  int iVar2;
  char acStack80 [64];
  
  GetRCnt(0xf2000000);
  if ((((*(u_int *)loadData & 0x8000000) != 0) && (*(int **)((int)loadData + 0x3c) != (int *)0x0)) &&
     (*(int *)((int)loadData + 0x40) != 0)) {
    RELMOD_InitModulePointers(*(int *)((int)loadData + 0x40),*(int **)((int)loadData + 0x3c));
  }
  STREAM_PackVRAMObject((_ObjectTracker *)data);
  OBTABLE_InitAnimPointers((_ObjectTracker *)data);
  OBTABLE_InitObjectWithID((Object *)loadData);
  if ((*(u_int *)((int)loadData + 0x2c) & 0x800000) != 0) {
    sprintf(acStack80,"\\kain2\\sfx\\object\\%s\\%s.snf");
    *(undefined2 *)((int)loadData + 6) = 0;
    lVar1 = LOAD_DoesFileExist(acStack80);
    if (lVar1 != 0) {
      iVar2 = aadLoadDynamicSfx((char *)data,0,0);
      *(undefined2 *)((int)loadData + 6) = (short)iVar2;
    }
  }
  *(undefined2 *)((int)data + 0x14) = 2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpMonster(struct _ObjectTracker *dumpee /*$s2*/)
 // line 420, offset 0x80058ee4
	/* begin block 1 */
		// Start line: 421
		// Start offset: 0x80058EE4
		// Variables:
	// 		struct Object *object; // $s1
	// 		struct _Instance *instance; // $a1

		/* begin block 1.1 */
			// Start line: 441
			// Start offset: 0x80058F60
			// Variables:
		// 		struct _Instance *next; // $s0
		/* end block 1.1 */
		// End offset: 0x80058F7C
		// End Line: 448
	/* end block 1 */
	// End offset: 0x80058F88
	// End Line: 451

	/* begin block 2 */
		// Start line: 846
	/* end block 2 */
	// End Line: 847

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
 // line 460, offset 0x80058fac
	/* begin block 1 */
		// Start line: 461
		// Start offset: 0x80058FAC
		// Variables:
	// 		char **mon; // $s0
	/* end block 1 */
	// End offset: 0x80059000
	// End Line: 469

	/* begin block 2 */
		// Start line: 941
	/* end block 2 */
	// End Line: 942

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
 // line 471, offset 0x80059014
	/* begin block 1 */
		// Start line: 472
		// Start offset: 0x80059014
		// Variables:
	// 		static char (*mon[6]); // offset 0x0
	/* end block 1 */
	// End offset: 0x80059014
	// End Line: 472

	/* begin block 2 */
		// Start line: 965
	/* end block 2 */
	// End Line: 966

int STREAM_IsSpecialMonster(char *name)

{
  int iVar1;
  
  iVar1 = STREAM_InList(name,&PTR_s_wallcr_800cb098);
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpSomeMonsters()
 // line 479, offset 0x80059038
	/* begin block 1 */
		// Start line: 480
		// Start offset: 0x80059038
		// Variables:
	// 		struct _ObjectTracker *otr; // $s0
	// 		int i; // $s2
	/* end block 1 */
	// End offset: 0x800590C0
	// End Line: 495

	/* begin block 2 */
		// Start line: 985
	/* end block 2 */
	// End Line: 986

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
 // line 496, offset 0x800590e0
	/* begin block 1 */
		// Start line: 1042
	/* end block 1 */
	// End Line: 1043

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
 // line 502, offset 0x80059110
	/* begin block 1 */
		// Start line: 1056
	/* end block 1 */
	// End Line: 1057

	/* begin block 2 */
		// Start line: 1058
	/* end block 2 */
	// End Line: 1059

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_YesMonsters(void)

{
  gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xfbffffff;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_IsMonster(char *name /*$a0*/)
 // line 509, offset 0x8005912c
	/* begin block 1 */
		// Start line: 510
		// Start offset: 0x8005912C
		// Variables:
	// 		static char (*monnames[19]); // offset 0x18
	/* end block 1 */
	// End offset: 0x8005912C
	// End Line: 510

	/* begin block 2 */
		// Start line: 1070
	/* end block 2 */
	// End Line: 1071

int STREAM_IsMonster(char *name)

{
  int iVar1;
  
  iVar1 = STREAM_InList(name,&PTR_s_skinner_800cb0b0);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ InsertGlobalObject(char *name /*$s2*/, struct GameTracker *gameTracker /*$s3*/)
 // line 552, offset 0x80059150
	/* begin block 1 */
		// Start line: 553
		// Start offset: 0x80059150
		// Variables:
	// 		char string[64]; // stack offset -152
	// 		char vramname[64]; // stack offset -88
	// 		int i; // $s1
	// 		struct _ObjectTracker *otr; // $s0
	/* end block 1 */
	// End offset: 0x800592EC
	// End Line: 652

	/* begin block 2 */
		// Start line: 1100
	/* end block 2 */
	// End Line: 1101

int InsertGlobalObject(char *name,GameTracker *gameTracker)

{
  int iVar1;
  int iVar2;
  _ObjectTracker *otr;
  char acStack152 [64];
  char acStack88 [64];
  
  if (((gameTrackerX.gameFlags & 0x4000000U) != 0) &&
     (iVar1 = STREAM_IsSpecialMonster(name), iVar1 != 0)) {
    return -1;
  }
  if (((gameTracker->debugFlags2 & 0x8000U) != 0) && (iVar1 = STREAM_IsMonster(name), iVar1 != 0)) {
    return -1;
  }
  otr = gameTracker->GlobalObjects;
  iVar1 = 0;
  do {
    if ((otr->objectStatus != 0) && (iVar2 = strcmpi((char *)otr,name), iVar2 == 0)) break;
    iVar1 = iVar1 + 1;
    otr = otr + 1;
  } while (iVar1 < 0x30);
  if (iVar1 == 0x30) {
    otr = gameTracker->GlobalObjects;
    iVar1 = 0;
    do {
      if (otr->objectStatus == 0) break;
      iVar1 = iVar1 + 1;
      otr = otr + 1;
    } while (iVar1 < 0x30);
    if (iVar1 == 0x30) {
      otr = gameTracker->GlobalObjects;
      iVar1 = 0;
      do {
        iVar2 = STREAM_TryAndDumpNonResident(otr);
        if (iVar2 != 0) break;
        iVar1 = iVar1 + 1;
        otr = otr + 1;
      } while (iVar1 < 0x30);
      if (iVar1 == 0x30) {
        DEBUG_FatalError("The Object tracker is full MAX_OBJECTS=%d.\n");
        iVar1 = -1;
      }
    }
    sprintf(acStack152,"\\kain2\\object\\%s\\%s.drm");
    sprintf(acStack88,"\\kain2\\object\\%s\\%s.crm");
    strcpy((char *)otr,name);
    otr->objectStatus = 1;
    LOAD_NonBlockingBinaryLoad(acStack152,STREAM_LoadObjectReturn,otr,(void *)0x0,&otr->object,1);
    otr->numInUse = 0;
    otr->numObjectsUsing = '\0';
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// struct _ObjectTracker * /*$ra*/ STREAM_GetObjectTracker(char *name /*$a0*/)
 // line 663, offset 0x8005930c
	/* begin block 1 */
		// Start line: 664
		// Start offset: 0x8005930C
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x8005934C
	// End Line: 669

	/* begin block 2 */
		// Start line: 1323
	/* end block 2 */
	// End Line: 1324

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
 // line 671, offset 0x8005935c
	/* begin block 1 */
		// Start line: 672
		// Start offset: 0x8005935C
		// Variables:
	// 		unsigned char *objlist; // $s0

		/* begin block 1.1 */
			// Start line: 684
			// Start offset: 0x800593B4
			// Variables:
		// 		int i; // $s1
		/* end block 1.1 */
		// End offset: 0x80059430
		// End Line: 702
	/* end block 1 */
	// End offset: 0x80059430
	// End Line: 703

	/* begin block 2 */
		// Start line: 1374
	/* end block 2 */
	// End Line: 1375

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
        *(u_int *)(name + 0x2c) = *(u_int *)(name + 0x2c) | 0x4000;
      }
      else {
        name = level->introList->name + iVar3;
        *(u_int *)(name + 0x2c) = *(u_int *)(name + 0x2c) & 0xffffbfff;
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
 // line 706, offset 0x8005944c
	/* begin block 1 */
		// Start line: 708
		// Start offset: 0x8005944C
		// Variables:
	// 		struct _Instance *instance; // $v1
	// 		struct _Instance *next; // $v1
	// 		long ret; // $a1
	/* end block 1 */
	// End offset: 0x80059484
	// End Line: 724

	/* begin block 2 */
		// Start line: 1459
	/* end block 2 */
	// End Line: 1460

	/* begin block 3 */
		// Start line: 1460
	/* end block 3 */
	// End Line: 1461

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
 // line 727, offset 0x8005948c
	/* begin block 1 */
		// Start line: 728
		// Start offset: 0x8005948C
		// Variables:
	// 		struct _ObjectTracker *objectTracker; // $s0
	/* end block 1 */
	// End offset: 0x800594A8
	// End Line: 732

	/* begin block 2 */
		// Start line: 1503
	/* end block 2 */
	// End Line: 1504

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
 // line 738, offset 0x800594bc
	/* begin block 1 */
		// Start line: 739
		// Start offset: 0x800594BC
		// Variables:
	// 		struct Object *object; // $s0

		/* begin block 1.1 */
			// Start line: 745
			// Start offset: 0x800594E4
			// Variables:
		// 		char dramName[64]; // stack offset -80
		/* end block 1.1 */
		// End offset: 0x80059510
		// End Line: 749
	/* end block 1 */
	// End offset: 0x80059590
	// End Line: 782

	/* begin block 2 */
		// Start line: 1526
	/* end block 2 */
	// End Line: 1527

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
 // line 785, offset 0x800595a4
	/* begin block 1 */
		// Start line: 786
		// Start offset: 0x800595A4
		// Variables:
	// 		int d; // $s1

		/* begin block 1.1 */
			// Start line: 793
			// Start offset: 0x800595F4
			// Variables:
		// 		unsigned char *objlist; // $s0
		/* end block 1.1 */
		// End offset: 0x80059638
		// End Line: 803
	/* end block 1 */
	// End offset: 0x8005964C
	// End Line: 806

	/* begin block 2 */
		// Start line: 1627
	/* end block 2 */
	// End Line: 1628

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
 // line 808, offset 0x80059668
	/* begin block 1 */
		// Start line: 809
		// Start offset: 0x80059668
		// Variables:
	// 		int i; // $s3
	// 		int abort; // $a3
	// 		struct _ObjectTracker *tracker; // $s1
	// 		struct _ObjectTracker *trackerList; // $s4

		/* begin block 1.1 */
			// Start line: 818
			// Start offset: 0x800596B4
			// Variables:
		// 		struct Object *object; // $s2
		/* end block 1.1 */
		// End offset: 0x800596F4
		// End Line: 833

		/* begin block 1.2 */
			// Start line: 841
			// Start offset: 0x80059730
			// Variables:
		// 		int j; // $a0
		/* end block 1.2 */
		// End offset: 0x8005978C
		// End Line: 854

		/* begin block 1.3 */
			// Start line: 862
			// Start offset: 0x800597C0
			// Variables:
		// 		int j; // $t0
		// 		struct _ObjectTracker *otr; // $a3

			/* begin block 1.3.1 */
				// Start line: 866
				// Start offset: 0x800597E0
				// Variables:
			// 		int k; // $a0

				/* begin block 1.3.1.1 */
					// Start line: 873
					// Start offset: 0x80059804
					// Variables:
				// 		int l; // $a1
				/* end block 1.3.1.1 */
				// End offset: 0x80059850
				// End Line: 880
			/* end block 1.3.1 */
			// End offset: 0x80059868
			// End Line: 882
		/* end block 1.3 */
		// End offset: 0x80059884
		// End Line: 885
	/* end block 1 */
	// End offset: 0x800598F0
	// End Line: 903

	/* begin block 2 */
		// Start line: 1690
	/* end block 2 */
	// End Line: 1691

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
        if ((u_int)*(ushort *)(pcVar10 + -8) - 1 < 2) {
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
 // line 906, offset 0x80059918
	/* begin block 1 */
		// Start line: 907
		// Start offset: 0x80059918
		// Variables:
	// 		int i; // $s1
	// 		struct _ObjectTracker *tracker; // $s0
	/* end block 1 */
	// End offset: 0x8005995C
	// End Line: 917

	/* begin block 2 */
		// Start line: 2004
	/* end block 2 */
	// End Line: 2005

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
 // line 922, offset 0x80059970
	/* begin block 1 */
		// Start line: 924
		// Start offset: 0x80059970
		// Variables:
	// 		struct Level *retLevel; // $a2
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x800599C0
	// End Line: 938

	/* begin block 2 */
		// Start line: 2044
	/* end block 2 */
	// End Line: 2045

	/* begin block 3 */
		// Start line: 2045
	/* end block 3 */
	// End Line: 2046

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
 // line 941, offset 0x800599cc
	/* begin block 1 */
		// Start line: 943
		// Start offset: 0x800599CC
		// Variables:
	// 		struct _StreamUnit *retUnit; // $a2
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x80059A18
	// End Line: 955

	/* begin block 2 */
		// Start line: 2089
	/* end block 2 */
	// End Line: 2090

	/* begin block 3 */
		// Start line: 2090
	/* end block 3 */
	// End Line: 2091

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
 // line 958, offset 0x80059a20
	/* begin block 1 */
		// Start line: 959
		// Start offset: 0x80059A20
		// Variables:
	// 		struct _Terrain *terrain; // $t2
	// 		int i; // $t0
	// 		struct _TFace *tface; // $a3
	// 		long waterZLevel; // $t1
	/* end block 1 */
	// End offset: 0x80059B48
	// End Line: 1012

	/* begin block 2 */
		// Start line: 2129
	/* end block 2 */
	// End Line: 2130

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
 // line 1017, offset 0x80059b50
	/* begin block 1 */
		// Start line: 2263
	/* end block 1 */
	// End Line: 2264

	/* begin block 2 */
		// Start line: 2264
	/* end block 2 */
	// End Line: 2265

/* WARNING: Unknown calling convention yet parameter storage is locked */

int STREAM_IsMorphInProgress(void)

{
  return (u_int)(gameTrackerX.gameData.asmData.MorphTime != 1000);
}



// decompiled code
// original method signature: 
// long /*$ra*/ STREAM_GetWaterZLevel(struct Level *level /*$a0*/, struct _Instance *instance /*$a1*/)
 // line 1023, offset 0x80059b64
	/* begin block 1 */
		// Start line: 1025
		// Start offset: 0x80059B64
		// Variables:
	// 		long waterZLevel; // $a1
	/* end block 1 */
	// End offset: 0x80059BDC
	// End Line: 1050

	/* begin block 2 */
		// Start line: 2275
	/* end block 2 */
	// End Line: 2276

	/* begin block 3 */
		// Start line: 2276
	/* end block 3 */
	// End Line: 2277

	/* begin block 4 */
		// Start line: 2278
	/* end block 4 */
	// End Line: 2279

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
 // line 1053, offset 0x80059be4
	/* begin block 1 */
		// Start line: 1055
		// Start offset: 0x80059BE4
		// Variables:
	// 		struct Level *level; // $v1
	/* end block 1 */
	// End offset: 0x80059C24
	// End Line: 1070

	/* begin block 2 */
		// Start line: 2335
	/* end block 2 */
	// End Line: 2336

	/* begin block 3 */
		// Start line: 2336
	/* end block 3 */
	// End Line: 2337

	/* begin block 4 */
		// Start line: 2340
	/* end block 4 */
	// End Line: 2341

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
 // line 1074, offset 0x80059c38
	/* begin block 1 */
		// Start line: 1075
		// Start offset: 0x80059C38
	/* end block 1 */
	// End offset: 0x80059CA8
	// End Line: 1087

	/* begin block 2 */
		// Start line: 2380
	/* end block 2 */
	// End Line: 2381

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
 // line 1131, offset 0x80059cc8
	/* begin block 1 */
		// Start line: 1132
		// Start offset: 0x80059CC8
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
			// Start line: 1156
			// Start offset: 0x80059D44
			// Variables:
		// 		struct _StreamUnit *connectStream; // $s0

			/* begin block 1.1.1 */
				// Start line: 1190
				// Start offset: 0x80059E5C
				// Variables:
			// 		struct _SVector offset; // stack offset -56
			/* end block 1.1.1 */
			// End offset: 0x80059E5C
			// End Line: 1201
		/* end block 1.1 */
		// End offset: 0x80059E68
		// End Line: 1210

		/* begin block 1.2 */
			// Start line: 1215
			// Start offset: 0x80059E7C
			// Variables:
		// 		long d; // stack offset -44
		// 		struct _StreamUnit *connectStream; // $s5

			/* begin block 1.2.1 */
				// Start line: 1230
				// Start offset: 0x80059ED4
				// Variables:
			// 		long hookedUp; // $s0

				/* begin block 1.2.1.1 */
					// Start line: 1270
					// Start offset: 0x80059FF4
					// Variables:
				// 		struct _SVector offset; // stack offset -56
				/* end block 1.2.1.1 */
				// End offset: 0x80059FF4
				// End Line: 1281
			/* end block 1.2.1 */
			// End offset: 0x8005A000
			// End Line: 1290
		/* end block 1.2 */
		// End offset: 0x8005A030
		// End Line: 1290
	/* end block 1 */
	// End offset: 0x8005A0AC
	// End Line: 1304

	/* begin block 2 */
		// Start line: 2504
	/* end block 2 */
	// End Line: 2505

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
LAB_80059f9c:
              bVar1 = true;
            }
            else {
              iVar3 = strcmpi(acStack72,"warpgate");
              if ((iVar3 == 0) && (lVar4 = WARPGATE_IsUnitWarpRoom(streamUnit), lVar4 != 0)) {
                *pp_Var9 = streamUnit;
                goto LAB_80059f9c;
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
          *(u_int *)(pcVar2 + 0x2c) = *(u_int *)(pcVar2 + 0x2c) | 8;
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
 // line 1306, offset 0x8005a0dc
	/* begin block 1 */
		// Start line: 1307
		// Start offset: 0x8005A0DC
		// Variables:
	// 		struct _StreamUnit *streamUnit; // $s0
	/* end block 1 */
	// End offset: 0x8005A0F8
	// End Line: 1311

	/* begin block 2 */
		// Start line: 3091
	/* end block 2 */
	// End Line: 3092

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
 // line 1317, offset 0x8005a110
	/* begin block 1 */
		// Start line: 1318
		// Start offset: 0x8005A110
		// Variables:
	// 		struct Level *level; // $s0
	// 		char sfxName[80]; // stack offset -96
	/* end block 1 */
	// End offset: 0x8005A224
	// End Line: 1380

	/* begin block 2 */
		// Start line: 3114
	/* end block 2 */
	// End Line: 3115

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
 // line 1394, offset 0x8005a25c
	/* begin block 1 */
		// Start line: 1395
		// Start offset: 0x8005A25C
	/* end block 1 */
	// End offset: 0x8005A25C
	// End Line: 1395

	/* begin block 2 */
		// Start line: 3282
	/* end block 2 */
	// End Line: 3283

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
 // line 1429, offset 0x8005a2bc
	/* begin block 1 */
		// Start line: 1430
		// Start offset: 0x8005A2BC
		// Variables:
	// 		struct Level *level; // $s0
	// 		struct _StreamUnit *streamUnit; // $s1
	/* end block 1 */
	// End offset: 0x8005A390
	// End Line: 1526

	/* begin block 2 */
		// Start line: 3353
	/* end block 2 */
	// End Line: 3354

void STREAM_StreamLoadLevelReturn(void *loadData,void *data,void *data2)

{
  short fogNear;
  short fogFar;
  
  GetRCnt(0xf2000000);
  *(undefined4 *)data2 = *(undefined4 *)((int)loadData + 0xf8);
  if (*(short *)((int)data2 + 4) == 3) {
    *(undefined2 *)((int)data2 + 4) = 0;
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
 // line 1553, offset 0x8005a3a4
	/* begin block 1 */
		// Start line: 1554
		// Start offset: 0x8005A3A4
		// Variables:
	// 		long i; // $t0
	// 		long offset; // $t1
	// 		struct GameTracker *gameTracker; // $v0

		/* begin block 1.1 */
			// Start line: 1582
			// Start offset: 0x8005A40C
			// Variables:
		// 		struct _Instance *instance; // $a3
		/* end block 1.1 */
		// End offset: 0x8005A574
		// End Line: 1618
	/* end block 1 */
	// End offset: 0x8005A65C
	// End Line: 1640

	/* begin block 2 */
		// Start line: 3103
	/* end block 2 */
	// End Line: 3104

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
LAB_8005a3f8:
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
      EVENT_UpdateResetSignalArray(oldLevel,newLevel,sizeOfLevel);
      return;
    }
  }
  pSVar6->StreamList[0].level = newLevel;
  goto LAB_8005a3f8;
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ STREAM_WhichUnitPointerIsIn(void *pointer /*$s3*/)
 // line 1645, offset 0x8005a674
	/* begin block 1 */
		// Start line: 1646
		// Start offset: 0x8005A674
		// Variables:
	// 		int i; // $s2
	// 		int size; // $v1
	// 		struct Level *level; // $s0
	/* end block 1 */
	// End offset: 0x8005A704
	// End Line: 1666

	/* begin block 2 */
		// Start line: 3776
	/* end block 2 */
	// End Line: 3777

_StreamUnit * STREAM_WhichUnitPointerIsIn(void *pointer)

{
  u_long uVar1;
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
 // line 1668, offset 0x8005a724
	/* begin block 1 */
		// Start line: 1669
		// Start offset: 0x8005A724
		// Variables:
	// 		long i; // $a3
	// 		long d; // $a1
	// 		struct GameTracker *gameTracker; // $s0
	// 		long offset; // $s1
	// 		struct _ObjectTracker *otr; // $t0

		/* begin block 1.1 */
			// Start line: 1689
			// Start offset: 0x8005A77C
			// Variables:
		// 		int j; // $a1
		// 		struct Object *object; // $a2
		/* end block 1.1 */
		// End offset: 0x8005A808
		// End Line: 1699

		/* begin block 1.2 */
			// Start line: 1717
			// Start offset: 0x8005A864
			// Variables:
		// 		struct _Instance *instance; // $s0
		/* end block 1.2 */
		// End offset: 0x8005A97C
		// End Line: 1746
	/* end block 1 */
	// End offset: 0x8005A9A8
	// End Line: 1754

	/* begin block 2 */
		// Start line: 3844
	/* end block 2 */
	// End Line: 3845

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
    if ((((newObject->oflags & 0x8000000U) != 0) && (newObject->relocList != (u_long *)0x0)) &&
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
 // line 1756, offset 0x8005a9c8
	/* begin block 1 */
		// Start line: 1758
		// Start offset: 0x8005A9C8
		// Variables:
	// 		struct _Instance *instance; // $v1
	/* end block 1 */
	// End offset: 0x8005AA04
	// End Line: 1771

	/* begin block 2 */
		// Start line: 4042
	/* end block 2 */
	// End Line: 4043

	/* begin block 3 */
		// Start line: 4043
	/* end block 3 */
	// End Line: 4044

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
 // line 1811, offset 0x8005aa0c
	/* begin block 1 */
		// Start line: 1812
		// Start offset: 0x8005AA0C
		// Variables:
	// 		char dramName[80]; // stack offset -176
	// 		char vramName[80]; // stack offset -96
	// 		struct VramBuffer *vramBuffer; // $v0
	// 		struct Level *level; // $s0
	/* end block 1 */
	// End offset: 0x8005AA0C
	// End Line: 1812

	/* begin block 2 */
		// Start line: 3617
	/* end block 2 */
	// End Line: 3618

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
 // line 1858, offset 0x8005aac0
	/* begin block 1 */
		// Start line: 4263
	/* end block 1 */
	// End Line: 4264

	/* begin block 2 */
		// Start line: 4264
	/* end block 2 */
	// End Line: 4265

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_MoveIntoNewStreamUnit(void)

{
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
// struct _StreamUnit * /*$ra*/ STREAM_LoadLevel(struct GameTracker *gameTracker /*$s4*/, char *baseAreaName /*$s3*/, struct StreamUnitPortal *streamPortal /*$s5*/, int loadnext /*$a3*/)
 // line 1876, offset 0x8005ab40
	/* begin block 1 */
		// Start line: 1877
		// Start offset: 0x8005AB40
		// Variables:
	// 		int i; // $s2
	// 		long streamID; // $s6
	// 		struct _StreamUnit *streamUnit; // $s1

		/* begin block 1.1 */
			// Start line: 1918
			// Start offset: 0x8005ABDC
		/* end block 1.1 */
		// End offset: 0x8005ABDC
		// End Line: 1921

		/* begin block 1.2 */
			// Start line: 1930
			// Start offset: 0x8005AC08
			// Variables:
		// 		struct Level *level; // $s0
		/* end block 1.2 */
		// End offset: 0x8005AC34
		// End Line: 1940

		/* begin block 1.3 */
			// Start line: 2002
			// Start offset: 0x8005AC90
			// Variables:
		// 		char dramName[80]; // stack offset -112
		/* end block 1.3 */
		// End offset: 0x8005AD28
		// End Line: 2059
	/* end block 1 */
	// End offset: 0x8005AD34
	// End Line: 2062

	/* begin block 2 */
		// Start line: 4301
	/* end block 2 */
	// End Line: 4302

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
LAB_8005ac60:
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
  goto LAB_8005ac60;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RemoveIntroducedLights(struct Level *level /*$s2*/)
 // line 2067, offset 0x8005ad60
	/* begin block 1 */
		// Start line: 2068
		// Start offset: 0x8005AD60
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8005AE2C
	// End Line: 2089

	/* begin block 2 */
		// Start line: 4856
	/* end block 2 */
	// End Line: 4857

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
 // line 2091, offset 0x8005ae44
	/* begin block 1 */
		// Start line: 2092
		// Start offset: 0x8005AE44
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		struct _Instance *next; // $s1
	/* end block 1 */
	// End offset: 0x8005AED0
	// End Line: 2120

	/* begin block 2 */
		// Start line: 4915
	/* end block 2 */
	// End Line: 4916

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
 // line 2122, offset 0x8005aef0
	/* begin block 1 */
		// Start line: 2124
		// Start offset: 0x8005AEF0
		// Variables:
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x8005AF38
	// End Line: 2140

	/* begin block 2 */
		// Start line: 4980
	/* end block 2 */
	// End Line: 4981

	/* begin block 3 */
		// Start line: 4981
	/* end block 3 */
	// End Line: 4982

	/* begin block 4 */
		// Start line: 4984
	/* end block 4 */
	// End Line: 4985

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
 // line 2142, offset 0x8005af40
	/* begin block 1 */
		// Start line: 2143
		// Start offset: 0x8005AF40
		// Variables:
	// 		int i; // $s0
	// 		int j; // $a0
	// 		int numportals; // $a1

		/* begin block 1.1 */
			// Start line: 2172
			// Start offset: 0x8005AFF8
			// Variables:
		// 		char dramName[80]; // stack offset -104
		/* end block 1.1 */
		// End offset: 0x8005B024
		// End Line: 2182

		/* begin block 1.2 */
			// Start line: 2199
			// Start offset: 0x8005B060
			// Variables:
		// 		struct _SFXMkr *sfxMkr; // $a1
		/* end block 1.2 */
		// End offset: 0x8005B060
		// End Line: 2199
	/* end block 1 */
	// End offset: 0x8005B114
	// End Line: 2230

	/* begin block 2 */
		// Start line: 5029
	/* end block 2 */
	// End Line: 5030

void STREAM_DumpUnit(_StreamUnit *streamUnit,long doSave)

{
  int *piVar1;
  long lVar2;
  _StreamUnit **pp_Var3;
  Level *pLVar4;
  int iVar5;
  int iVar6;
  u_char **ppuVar7;
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
        ppuVar7 = (u_char **)((int)&pLVar4->SFXMarkerList->soundData + iVar5);
        SOUND_EndInstanceSounds(*ppuVar7,(SoundInstance *)(ppuVar7 + 2));
        pLVar4 = streamUnit->level;
        iVar9 = iVar9 + 1;
        iVar5 = iVar5 + 0x24;
      } while (iVar9 < pLVar4->NumberOfSFXMarkers);
    }
    if ((int)streamUnit->sfxFileHandle != 0) {
      aadFreeDynamicSfx((int)streamUnit->sfxFileHandle);
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
 // line 2232, offset 0x8005b130
	/* begin block 1 */
		// Start line: 2233
		// Start offset: 0x8005B130
		// Variables:
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x8005B190
	// End Line: 2245

	/* begin block 2 */
		// Start line: 5230
	/* end block 2 */
	// End Line: 5231

void STREAM_DumpAllUnitsNotNeeded(GameTracker *gameTracker)

{
  STracker *streamUnit;
  int iVar1;
  
  iVar1 = 0;
  streamUnit = &StreamTracker;
  do {
    if ((*(short *)streamUnit->StreamList != 0) &&
       (*(u_long *)streamUnit->StreamList != gameTracker->displayFrameCount)) {
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
 // line 2247, offset 0x8005b1a8
	/* begin block 1 */
		// Start line: 2248
		// Start offset: 0x8005B1A8
		// Variables:
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x8005B20C
	// End Line: 2261

	/* begin block 2 */
		// Start line: 5271
	/* end block 2 */
	// End Line: 5272

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
 // line 2264, offset 0x8005b228
	/* begin block 1 */
		// Start line: 5318
	/* end block 1 */
	// End Line: 5319

	/* begin block 2 */
		// Start line: 5319
	/* end block 2 */
	// End Line: 5320

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
 // line 2281, offset 0x8005b2f0
	/* begin block 1 */
		// Start line: 2282
		// Start offset: 0x8005B2F0
		// Variables:
	// 		int i; // $s2
	/* end block 1 */
	// End offset: 0x8005B36C
	// End Line: 2294

	/* begin block 2 */
		// Start line: 5355
	/* end block 2 */
	// End Line: 5356

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
 // line 2297, offset 0x8005b38c
	/* begin block 1 */
		// Start line: 2298
		// Start offset: 0x8005B38C
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8005B3D8
	// End Line: 2310

	/* begin block 2 */
		// Start line: 5402
	/* end block 2 */
	// End Line: 5403

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
 // line 2312, offset 0x8005b3f0
	/* begin block 1 */
		// Start line: 2313
		// Start offset: 0x8005B3F0
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x8005B430
	// End Line: 2321

	/* begin block 2 */
		// Start line: 5440
	/* end block 2 */
	// End Line: 5441

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
 // line 2323, offset 0x8005b440
	/* begin block 1 */
		// Start line: 2324
		// Start offset: 0x8005B440
	/* end block 1 */
	// End offset: 0x8005B460
	// End Line: 2331

	/* begin block 2 */
		// Start line: 5462
	/* end block 2 */
	// End Line: 5463

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
 // line 2334, offset 0x8005b470
	/* begin block 1 */
		// Start line: 5484
	/* end block 1 */
	// End Line: 5485

	/* begin block 2 */
		// Start line: 5488
	/* end block 2 */
	// End Line: 5489

/* WARNING: Unknown calling convention yet parameter storage is locked */

void WARPGATE_Init(void)

{
  CurrentWarpNumber = 0;
  WarpGateLoadInfo.warpgate_in_use = 0;
  WarpGateLoadInfo.loading = '\0';
  WarpGateLoadInfo.blocked = '\0';
  WarpGateLoadInfo.fadeValue = 0x1000;
  WarpGateLoadInfo.curTime = 0;
  WarpGateLoadInfo.maxTime = 0xf000;
  WarpGateLoadInfo.warpFaceInstance = (_Instance *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_StartUsingWarpgate()
 // line 2348, offset 0x8005b4a0
	/* begin block 1 */
		// Start line: 5517
	/* end block 1 */
	// End Line: 5518

	/* begin block 2 */
		// Start line: 5518
	/* end block 2 */
	// End Line: 5519

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
 // line 2355, offset 0x8005b4d8
	/* begin block 1 */
		// Start line: 5532
	/* end block 1 */
	// End Line: 5533

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
 // line 2362, offset 0x8005b510
	/* begin block 1 */
		// Start line: 5546
	/* end block 1 */
	// End Line: 5547

	/* begin block 2 */
		// Start line: 5547
	/* end block 2 */
	// End Line: 5548

/* WARNING: Unknown calling convention yet parameter storage is locked */

int WARPGATE_IsWarpgateInUse(void)

{
  return WarpGateLoadInfo.warpgate_in_use;
}



// decompiled code
// original method signature: 
// int /*$ra*/ WARPGATE_IsWarpgateActive()
 // line 2368, offset 0x8005b51c
	/* begin block 1 */
		// Start line: 5558
	/* end block 1 */
	// End Line: 5559

	/* begin block 2 */
		// Start line: 5559
	/* end block 2 */
	// End Line: 5560

/* WARNING: Unknown calling convention yet parameter storage is locked */

int WARPGATE_IsWarpgateActive(void)

{
  return (u_int)(WarpGateLoadInfo.loading != '\0');
}



// decompiled code
// original method signature: 
// int /*$ra*/ WARPGATE_IsWarpgateUsable()
 // line 2375, offset 0x8005b528
	/* begin block 1 */
		// Start line: 5572
	/* end block 1 */
	// End Line: 5573

	/* begin block 2 */
		// Start line: 5573
	/* end block 2 */
	// End Line: 5574

/* WARNING: Unknown calling convention yet parameter storage is locked */

int WARPGATE_IsWarpgateUsable(void)

{
  return (u_int)(WarpGateLoadInfo._4_2_ == 4);
}



// decompiled code
// original method signature: 
// int /*$ra*/ WARPGATE_IsWarpgateSpectral()
 // line 2382, offset 0x8005b53c
	/* begin block 1 */
		// Start line: 5586
	/* end block 1 */
	// End Line: 5587

/* WARNING: Unknown calling convention yet parameter storage is locked */

int WARPGATE_IsWarpgateSpectral(void)

{
  int iVar1;
  
  iVar1 = strcmpi((char *)(&WarpRoomArray + CurrentWarpNumber),"under3");
  return (u_int)(iVar1 == 0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_IsItActive(struct _StreamUnit *streamUnit /*$a0*/)
 // line 2390, offset 0x8005b57c
	/* begin block 1 */
		// Start line: 2392
		// Start offset: 0x8005B57C
		// Variables:
	// 		struct Level *level; // $t1
	// 		int d; // $a1
	/* end block 1 */
	// End offset: 0x8005B63C
	// End Line: 2414

	/* begin block 2 */
		// Start line: 5603
	/* end block 2 */
	// End Line: 5604

	/* begin block 3 */
		// Start line: 5604
	/* end block 3 */
	// End Line: 5605

	/* begin block 4 */
		// Start line: 5607
	/* end block 4 */
	// End Line: 5608

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
 // line 2416, offset 0x8005b644
	/* begin block 1 */
		// Start line: 2418
		// Start offset: 0x8005B644
		// Variables:
	// 		struct Level *level; // $v0
	// 		long isWarpRoom; // $a1
	// 		struct StreamUnitPortal *streamPortal; // $v1
	// 		long numPortals; // $a2
	// 		long d; // $a0
	/* end block 1 */
	// End offset: 0x8005B694
	// End Line: 2436

	/* begin block 2 */
		// Start line: 5670
	/* end block 2 */
	// End Line: 5671

	/* begin block 3 */
		// Start line: 5671
	/* end block 3 */
	// End Line: 5672

	/* begin block 4 */
		// Start line: 5676
	/* end block 4 */
	// End Line: 5677

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
 // line 2439, offset 0x8005b69c
	/* begin block 1 */
		// Start line: 2440
		// Start offset: 0x8005B69C
	/* end block 1 */
	// End offset: 0x8005B6C0
	// End Line: 2452

	/* begin block 2 */
		// Start line: 5724
	/* end block 2 */
	// End Line: 5725

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
 // line 2455, offset 0x8005b6d0
	/* begin block 1 */
		// Start line: 2457
		// Start offset: 0x8005B6D0
		// Variables:
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x8005B70C
	// End Line: 2466

	/* begin block 2 */
		// Start line: 5756
	/* end block 2 */
	// End Line: 5757

	/* begin block 3 */
		// Start line: 5757
	/* end block 3 */
	// End Line: 5758

	/* begin block 4 */
		// Start line: 5759
	/* end block 4 */
	// End Line: 5760

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
 // line 2471, offset 0x8005b714
	/* begin block 1 */
		// Start line: 2472
		// Start offset: 0x8005B714
		// Variables:
	// 		long result; // $s1
	/* end block 1 */
	// End offset: 0x8005B81C
	// End Line: 2497

	/* begin block 2 */
		// Start line: 5792
	/* end block 2 */
	// End Line: 5793

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
 // line 2500, offset 0x8005b834
	/* begin block 1 */
		// Start line: 5876
	/* end block 1 */
	// End Line: 5877

	/* begin block 2 */
		// Start line: 5877
	/* end block 2 */
	// End Line: 5878

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
 // line 2509, offset 0x8005b8a4
	/* begin block 1 */
		// Start line: 2510
		// Start offset: 0x8005B8A4
		// Variables:
	// 		long result; // $s0
	/* end block 1 */
	// End offset: 0x8005B970
	// End Line: 2537

	/* begin block 2 */
		// Start line: 5895
	/* end block 2 */
	// End Line: 5896

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
// void /*$ra*/ PreloadAllConnectedUnits(struct GameTracker *gameTracker /*$s4*/, struct _StreamUnit *streamUnit /*$s5*/, struct _SVector *offset /*$s6*/)
 // line 2541, offset 0x8005b984
	/* begin block 1 */
		// Start line: 2542
		// Start offset: 0x8005B984
		// Variables:
	// 		int i; // $s1
	// 		char text[16]; // stack offset -48
	// 		int numportals; // $s3
	// 		char *commapos; // $v0
	// 		struct StreamUnitPortal *stream; // $s0
	/* end block 1 */
	// End offset: 0x8005BB24
	// End Line: 2675

	/* begin block 2 */
		// Start line: 5972
	/* end block 2 */
	// End Line: 5973

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
      if (pcVar1 != (char *)0x0) {
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
 // line 2740, offset 0x8005bb4c
	/* begin block 1 */
		// Start line: 2741
		// Start offset: 0x8005BB4C
		// Variables:
	// 		int curTree; // $t2

		/* begin block 1.1 */
			// Start line: 2764
			// Start offset: 0x8005BC44
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $a0
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a3
		/* end block 1.1 */
		// End offset: 0x8005BC44
		// End Line: 2766
	/* end block 1 */
	// End offset: 0x8005BC9C
	// End Line: 2773

	/* begin block 2 */
		// Start line: 5475
	/* end block 2 */
	// End Line: 5476

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
 // line 2775, offset 0x8005bcb0
	/* begin block 1 */
		// Start line: 2777
		// Start offset: 0x8005BCB0
		// Variables:
	// 		int i; // $a3
	/* end block 1 */
	// End offset: 0x8005BD3C
	// End Line: 2789

	/* begin block 2 */
		// Start line: 6457
	/* end block 2 */
	// End Line: 6458

	/* begin block 3 */
		// Start line: 6458
	/* end block 3 */
	// End Line: 6459

	/* begin block 4 */
		// Start line: 6460
	/* end block 4 */
	// End Line: 6461

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
 // line 2791, offset 0x8005bd44
	/* begin block 1 */
		// Start line: 2792
		// Start offset: 0x8005BD44
		// Variables:
	// 		int i; // $t6

		/* begin block 1.1 */
			// Start line: 2802
			// Start offset: 0x8005BD8C
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $v1
		// 		short _y1; // $a1
		// 		short _z1; // $a2
		// 		struct _Position *_v; // $a0
		/* end block 1.1 */
		// End offset: 0x8005BD8C
		// End Line: 2804

		/* begin block 1.2 */
			// Start line: 2804
			// Start offset: 0x8005BD8C
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a3
		/* end block 1.2 */
		// End offset: 0x8005BD8C
		// End Line: 2804

		/* begin block 1.3 */
			// Start line: 2804
			// Start offset: 0x8005BD8C
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a3
		/* end block 1.3 */
		// End offset: 0x8005BD8C
		// End Line: 2804

		/* begin block 1.4 */
			// Start line: 2804
			// Start offset: 0x8005BD8C
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a3
		/* end block 1.4 */
		// End offset: 0x8005BE58
		// End Line: 2813
	/* end block 1 */
	// End offset: 0x8005BE74
	// End Line: 2820

	/* begin block 2 */
		// Start line: 6505
	/* end block 2 */
	// End Line: 6506

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
 // line 2822, offset 0x8005be7c
	/* begin block 1 */
		// Start line: 6590
	/* end block 1 */
	// End Line: 6591

void RelocateLevelWithInstances(Level *level,_SVector *offset)

{
  RelocateLevel(level,offset);
  RelocateInstances(&gameTrackerX,offset,gameTrackerX.StreamUnitID);
  RelocatePlanPool((PlanningNode *)gameTrackerX.planningPool,offset);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateTerrain(struct _Terrain *terrain /*$s2*/, struct _SVector *offset /*$s3*/)
 // line 2833, offset 0x8005bec0
	/* begin block 1 */
		// Start line: 2834
		// Start offset: 0x8005BEC0
		// Variables:
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x8005BF80
	// End Line: 2961

	/* begin block 2 */
		// Start line: 6612
	/* end block 2 */
	// End Line: 6613

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
 // line 2967, offset 0x8005bfb0
	/* begin block 1 */
		// Start line: 2969
		// Start offset: 0x8005BFB0
		// Variables:
	// 		int i; // $a3
	/* end block 1 */
	// End offset: 0x8005C000
	// End Line: 2991

	/* begin block 2 */
		// Start line: 6889
	/* end block 2 */
	// End Line: 6890

	/* begin block 3 */
		// Start line: 6890
	/* end block 3 */
	// End Line: 6891

	/* begin block 4 */
		// Start line: 6893
	/* end block 4 */
	// End Line: 6894

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
 // line 2993, offset 0x8005c008
	/* begin block 1 */
		// Start line: 2995
		// Start offset: 0x8005C008
		// Variables:
	// 		int i; // $a3
	/* end block 1 */
	// End offset: 0x8005C094
	// End Line: 3008

	/* begin block 2 */
		// Start line: 6949
	/* end block 2 */
	// End Line: 6950

	/* begin block 3 */
		// Start line: 6950
	/* end block 3 */
	// End Line: 6951

	/* begin block 4 */
		// Start line: 6952
	/* end block 4 */
	// End Line: 6953

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
 // line 3010, offset 0x8005c09c
	/* begin block 1 */
		// Start line: 3012
		// Start offset: 0x8005C09C
		// Variables:
	// 		int i; // $a3
	/* end block 1 */
	// End offset: 0x8005C0EC
	// End Line: 3020

	/* begin block 2 */
		// Start line: 6999
	/* end block 2 */
	// End Line: 7000

	/* begin block 3 */
		// Start line: 7000
	/* end block 3 */
	// End Line: 7001

	/* begin block 4 */
		// Start line: 7002
	/* end block 4 */
	// End Line: 7003

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
 // line 3022, offset 0x8005c0f4
	/* begin block 1 */
		// Start line: 3023
		// Start offset: 0x8005C0F4
		// Variables:
	// 		int i; // $t1
	// 		int d; // $a3
	/* end block 1 */
	// End offset: 0x8005C190
	// End Line: 3035

	/* begin block 2 */
		// Start line: 7031
	/* end block 2 */
	// End Line: 7032

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
 // line 3037, offset 0x8005c198
	/* begin block 1 */
		// Start line: 3038
		// Start offset: 0x8005C198
		// Variables:
	// 		int i; // $a1
	// 		short ox; // $s1
	// 		short oy; // $s2
	// 		short oz; // $s3
	/* end block 1 */
	// End offset: 0x8005C204
	// End Line: 3053

	/* begin block 2 */
		// Start line: 7067
	/* end block 2 */
	// End Line: 7068

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
 // line 3058, offset 0x8005c24c
	/* begin block 1 */
		// Start line: 3059
		// Start offset: 0x8005C24C
		// Variables:
	// 		int i; // $a1
	// 		short ox; // $t1
	// 		short oy; // $t0
	// 		short oz; // $a2
	/* end block 1 */
	// End offset: 0x8005C298
	// End Line: 3073

	/* begin block 2 */
		// Start line: 7122
	/* end block 2 */
	// End Line: 7123

	/* begin block 3 */
		// Start line: 7126
	/* end block 3 */
	// End Line: 7127

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
 // line 3075, offset 0x8005c2a0
	/* begin block 1 */
		// Start line: 3077
		// Start offset: 0x8005C2A0
		// Variables:
	// 		int i; // $a1
	// 		short ox; // $t0
	// 		short oy; // $a3
	// 		short oz; // $a2
	/* end block 1 */
	// End offset: 0x8005C2E4
	// End Line: 3090

	/* begin block 2 */
		// Start line: 7166
	/* end block 2 */
	// End Line: 7167

	/* begin block 3 */
		// Start line: 7167
	/* end block 3 */
	// End Line: 7168

	/* begin block 4 */
		// Start line: 7170
	/* end block 4 */
	// End Line: 7171

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
 // line 3092, offset 0x8005c2ec
	/* begin block 1 */
		// Start line: 3093
		// Start offset: 0x8005C2EC
		// Variables:
	// 		int i; // $a2
	/* end block 1 */
	// End offset: 0x8005C394
	// End Line: 3114

	/* begin block 2 */
		// Start line: 7206
	/* end block 2 */
	// End Line: 7207

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
 // line 3116, offset 0x8005c39c
	/* begin block 1 */
		// Start line: 7258
	/* end block 1 */
	// End Line: 7259

void STREAM_RelocateInstance(GameTracker *gameTracker,_Instance *instance,_SVector *offset)

{
  STREAM_OffsetInstancePosition(gameTracker,instance,offset,1);
  INSTANCE_Post(instance,(int)&DAT_00100008,(int)offset);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_OffsetInstancePosition(struct GameTracker *gameTracker /*$a0*/, struct _Instance *instance /*$s0*/, struct _SVector *offset /*$s1*/, int streamSignalFlag /*$s2*/)
 // line 3124, offset 0x8005c3e4
	/* begin block 1 */
		// Start line: 7274
	/* end block 1 */
	// End Line: 7275

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
 // line 3151, offset 0x8005c500
	/* begin block 1 */
		// Start line: 3152
		// Start offset: 0x8005C500
		// Variables:
	// 		struct _SVector offset; // stack offset -16
	/* end block 1 */
	// End offset: 0x8005C500
	// End Line: 3152

	/* begin block 2 */
		// Start line: 7344
	/* end block 2 */
	// End Line: 7345

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
 // line 3162, offset 0x8005c558
	/* begin block 1 */
		// Start line: 3163
		// Start offset: 0x8005C558
		// Variables:
	// 		struct _InstanceList *instanceList; // $v0
	// 		struct _Instance *instance; // $s0
	/* end block 1 */
	// End offset: 0x8005C5A8
	// End Line: 3179

	/* begin block 2 */
		// Start line: 7371
	/* end block 2 */
	// End Line: 7372

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
 // line 3182, offset 0x8005c5c8
	/* begin block 1 */
		// Start line: 3184
		// Start offset: 0x8005C5C8
		// Variables:
	// 		int i; // $t1
	// 		int d; // $t0
	/* end block 1 */
	// End offset: 0x8005C6F0
	// End Line: 3209

	/* begin block 2 */
		// Start line: 7413
	/* end block 2 */
	// End Line: 7414

	/* begin block 3 */
		// Start line: 7414
	/* end block 3 */
	// End Line: 7415

	/* begin block 4 */
		// Start line: 7416
	/* end block 4 */
	// End Line: 7417

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
 // line 3219, offset 0x8005c6f8
	/* begin block 1 */
		// Start line: 3220
		// Start offset: 0x8005C6F8
		// Variables:
	// 		struct VramSize *vramSize; // $a0

		/* begin block 1.1 */
			// Start line: 3229
			// Start offset: 0x8005C728
			// Variables:
		// 		struct VramBuffer *vramBuffer; // $v0

			/* begin block 1.1.1 */
				// Start line: 3237
				// Start offset: 0x8005C738
				// Variables:
			// 		char fileName[64]; // stack offset -80
			// 		struct _BlockVramEntry *vramBlock; // $s0
			/* end block 1.1.1 */
			// End offset: 0x8005C760
			// End Line: 3247
		/* end block 1.1 */
		// End offset: 0x8005C7E0
		// End Line: 3266
	/* end block 1 */
	// End offset: 0x8005C7E4
	// End Line: 3274

	/* begin block 2 */
		// Start line: 7524
	/* end block 2 */
	// End Line: 7525

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
 // line 3303, offset 0x8005c7f8
	/* begin block 1 */
		// Start line: 7725
	/* end block 1 */
	// End Line: 7726

void MORPH_SetupInstanceFlags(GameTracker *gameTracker,_Instance *instance)

{
  long lVar1;
  u_int uVar2;
  
  if ((instance->object->oflags & 0x80000U) != 0) {
    return;
  }
  if ((gameTracker->gameData).asmData.MorphType == 0) {
    uVar2 = instance->flags2;
    if ((uVar2 & 0x8000000) == 0) {
      uVar2 = uVar2 & 0xebffffff;
      goto LAB_8005c8fc;
    }
  }
  else {
    uVar2 = instance->flags2;
    if ((uVar2 & 0x8000000) != 0) {
      uVar2 = uVar2 & 0xebffffff;
      goto LAB_8005c8fc;
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
LAB_8005c8fc:
  instance->flags2 = uVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_SetupInstanceListFlags(struct GameTracker *gameTracker /*$s1*/)
 // line 3350, offset 0x8005c910
	/* begin block 1 */
		// Start line: 3351
		// Start offset: 0x8005C910
		// Variables:
	// 		struct _Instance *instance; // $s0
	/* end block 1 */
	// End offset: 0x8005C954
	// End Line: 3362

	/* begin block 2 */
		// Start line: 7822
	/* end block 2 */
	// End Line: 7823

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
 // line 3364, offset 0x8005c968
	/* begin block 1 */
		// Start line: 3366
		// Start offset: 0x8005C968
		// Variables:
	// 		struct _Instance *instance; // $v1
	/* end block 1 */
	// End offset: 0x8005C9C8
	// End Line: 3389

	/* begin block 2 */
		// Start line: 7850
	/* end block 2 */
	// End Line: 7851

	/* begin block 3 */
		// Start line: 7851
	/* end block 3 */
	// End Line: 7852

	/* begin block 4 */
		// Start line: 7855
	/* end block 4 */
	// End Line: 7856

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
 // line 3391, offset 0x8005c9d0
	/* begin block 1 */
		// Start line: 3393
		// Start offset: 0x8005C9D0
		// Variables:
	// 		int fade1; // $a1
	// 		int fade2; // $v0
	/* end block 1 */
	// End offset: 0x8005CA18
	// End Line: 3407

	/* begin block 2 */
		// Start line: 7904
	/* end block 2 */
	// End Line: 7905

	/* begin block 3 */
		// Start line: 7905
	/* end block 3 */
	// End Line: 7906

	/* begin block 4 */
		// Start line: 7907
	/* end block 4 */
	// End Line: 7908

void MORPH_InMorphDoFadeValues(GameTracker *gameTracker)

{
  short sVar1;
  
  sVar1 = (short)(((int)(gameTracker->gameData).asmData.MorphTime << 0xc) / 1000);
  if ((gameTracker->gameData).asmData.MorphType == 0) {
    gameTracker->spectral_fadeValue = sVar1;
    gameTracker->material_fadeValue = 0x1000 - sVar1;
    return;
  }
  gameTracker->spectral_fadeValue = 0x1000 - sVar1;
  gameTracker->material_fadeValue = sVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_UpdateTimeMult()
 // line 3413, offset 0x8005ca20
	/* begin block 1 */
		// Start line: 3416
		// Start offset: 0x8005CA20

		/* begin block 1.1 */
			// Start line: 3419
			// Start offset: 0x8005CA34
			// Variables:
		// 		short ratio; // $v1
		/* end block 1.1 */
		// End offset: 0x8005CB50
		// End Line: 3457
	/* end block 1 */
	// End offset: 0x8005CB8C
	// End Line: 3473

	/* begin block 2 */
		// Start line: 7948
	/* end block 2 */
	// End Line: 7949

	/* begin block 3 */
		// Start line: 7950
	/* end block 3 */
	// End Line: 7951

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MORPH_UpdateTimeMult(void)

{
  int iVar1;
  u_int uVar2;
  
  uVar2 = (u_int)(ushort)gameTrackerX.gameData.asmData.MorphTime;
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
    uVar2 = (u_int)(ushort)gameTrackerX.gameData.asmData.MorphTime;
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
// void /*$ra*/ MORPH_UpdateNormals(struct Level *BaseLevel /*$s0*/)
 // line 3477, offset 0x8005cb94
	/* begin block 1 */
		// Start line: 3478
		// Start offset: 0x8005CB94
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
			// Start line: 3527
			// Start offset: 0x8005CC8C
			// Variables:
		// 		struct _TVertex *endv; // $a2
		/* end block 1.1 */
		// End offset: 0x8005CCFC
		// End Line: 3548

		/* begin block 1.2 */
			// Start line: 3548
			// Start offset: 0x8005CCFC
			// Variables:
		// 		struct _BSPNode *node; // $v1
		// 		struct _BSPLeaf *leaf; // $a0
		// 		struct _Sphere_noSq hsphere; // stack offset -32
		// 		struct _BoundingBox hbox; // stack offset -24
		// 		struct _Terrain *terrain; // $a3
		// 		long curTree; // $t0
		/* end block 1.2 */
		// End offset: 0x8005CF54
		// End Line: 3599

		/* begin block 1.3 */
			// Start line: 3601
			// Start offset: 0x8005CF54
			// Variables:
		// 		struct _Instance *instance; // $s0

			/* begin block 1.3.1 */
				// Start line: 3607
				// Start offset: 0x8005CF7C
				// Variables:
			// 		struct SVECTOR realDiff; // stack offset -32
			// 		struct _Position oldPos; // stack offset -24
			/* end block 1.3.1 */
			// End offset: 0x8005D064
			// End Line: 3631
		/* end block 1.3 */
		// End offset: 0x8005D074
		// End Line: 3634
	/* end block 1 */
	// End offset: 0x8005D074
	// End Line: 3635

	/* begin block 2 */
		// Start line: 8080
	/* end block 2 */
	// End Line: 8081

void MORPH_UpdateNormals(Level *BaseLevel)

{
  short *psVar1;
  short *psVar2;
  short sVar3;
  ushort uVar4;
  short sVar5;
  _Terrain *p_Var6;
  _TVertex *p_Var7;
  u_int *puVar8;
  int iVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  u_int uVar12;
  ushort *puVar13;
  _MorphColor *p_Var14;
  SpotLight *pSVar15;
  undefined4 *puVar16;
  Intro *pIVar17;
  ushort *puVar18;
  long lVar19;
  int iVar20;
  u_int uVar21;
  int iVar22;
  short *psVar23;
  _TVertex *p_Var24;
  PointLight *pPVar25;
  _MorphVertex *p_Var26;
  long lVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  _Instance *instance;
  u_int local_20;
  u_int local_1c;
  u_int local_18;
  u_int local_14;
  undefined4 local_10;
  
  p_Var6 = BaseLevel->terrain;
  puVar18 = (ushort *)p_Var6->morphNormalIdx;
  iVar22 = p_Var6->numFaces;
  if (0 < iVar22) {
    puVar13 = &p_Var6->faceList->normal;
    do {
      uVar4 = *puVar13;
      iVar22 = iVar22 + -1;
      *puVar13 = *puVar18;
      *puVar18 = uVar4;
      puVar18 = puVar18 + 1;
      puVar13 = puVar13 + 6;
    } while (0 < iVar22);
    p_Var6 = BaseLevel->terrain;
  }
  p_Var26 = p_Var6->MorphDiffList;
  if (p_Var26 != (_MorphVertex *)0x0) {
    sVar3 = p_Var26->vindex;
    sVar5 = p_Var26->vindex;
    psVar23 = &p_Var26->vindex;
    while (-1 < sVar3) {
      p_Var7 = BaseLevel->terrain->vertexList + sVar5;
      (p_Var7->vertex).x = psVar23[1] + p_Var26->x;
      (p_Var7->vertex).y = psVar23[2] + psVar23[-2];
      psVar1 = psVar23 + 3;
      psVar2 = psVar23 + -1;
      psVar23 = psVar23 + 7;
      (p_Var7->vertex).z = *psVar1 + *psVar2;
      sVar3 = *psVar23;
      sVar5 = *psVar23;
      p_Var26 = p_Var26 + 1;
    }
  }
  p_Var6 = BaseLevel->terrain;
  p_Var14 = p_Var6->MorphColorList;
  if (p_Var14 != (_MorphColor *)0x0) {
    p_Var7 = p_Var6->vertexList;
    p_Var24 = p_Var7 + p_Var6->numVertices;
    pbVar10 = &p_Var7->b0;
    while (p_Var7 < p_Var24) {
      pbVar10[-2] = (byte)(((u_int)*(byte *)&p_Var14->morphColor15 & 0x1f) << 3);
      p_Var7 = p_Var7 + 1;
      pbVar10[-1] = (byte)((ushort)p_Var14->morphColor15 >> 2) & 0xf8;
      puVar18 = (ushort *)&p_Var14->morphColor15;
      p_Var14 = p_Var14 + 1;
      *pbVar10 = (byte)(*puVar18 >> 7) & 0xf8;
      pbVar10 = pbVar10 + 0xc;
    }
  }
  RemoveIntroducedLights(BaseLevel);
  lVar19 = BaseLevel->numSpotSpecturalLights;
  pSVar15 = BaseLevel->spotSpecturalLightList;
  p_Var6 = BaseLevel->terrain;
  BaseLevel->numSpotSpecturalLights = BaseLevel->numSpotLights;
  lVar27 = BaseLevel->numPointLights;
  BaseLevel->spotSpecturalLightList = BaseLevel->spotLightList;
  pPVar25 = BaseLevel->pointLightList;
  BaseLevel->numSpotLights = lVar19;
  BaseLevel->spotLightList = pSVar15;
  BaseLevel->numPointLights = BaseLevel->numPointSpecturalLights;
  BaseLevel->pointLightList = BaseLevel->pointSpecturalLightList;
  BaseLevel->numPointSpecturalLights = lVar27;
  BaseLevel->pointSpecturalLightList = pPVar25;
  iVar22 = 0;
  if (0 < p_Var6->numBSPTrees) {
    iVar20 = 0;
    do {
      puVar8 = (u_int *)((int)&p_Var6->BSPTreeArray->bspRoot + iVar20);
      puVar16 = (undefined4 *)*puVar8;
      puVar11 = puVar16 + 7;
      if (puVar16 < (undefined4 *)puVar8[1]) {
        do {
          uVar28 = *puVar16;
          local_1c = puVar16[1];
          uVar29 = puVar11[1];
          *puVar16 = *puVar11;
          puVar16[1] = uVar29;
          *puVar11 = uVar28;
          puVar11[1] = local_1c;
          puVar16 = puVar16 + 0xb;
          puVar11 = puVar11 + 0xb;
        } while (puVar16 < *(undefined4 **)((int)&p_Var6->BSPTreeArray->startLeaves + iVar20));
      }
      iVar9 = (int)&p_Var6->BSPTreeArray->bspRoot + iVar20;
      puVar16 = *(undefined4 **)(iVar9 + 4);
      if (puVar16 < *(undefined4 **)(iVar9 + 8)) {
        puVar11 = puVar16 + 7;
        do {
          uVar28 = *puVar16;
          local_1c = puVar16[1];
          uVar29 = puVar11[4];
          *puVar16 = puVar11[3];
          puVar16[1] = uVar29;
          puVar11[3] = uVar28;
          puVar11[4] = local_1c;
          uVar28 = puVar11[-3];
          local_14 = puVar11[-2];
          local_10 = puVar11[-1];
          puVar11[-3] = *puVar11;
          puVar11[-2] = puVar11[1];
          puVar11[-1] = puVar11[2];
          *puVar11 = uVar28;
          puVar11[1] = local_14;
          puVar11[2] = local_10;
          puVar16 = puVar16 + 0xc;
          puVar11 = puVar11 + 0xc;
        } while (puVar16 < *(undefined4 **)((int)&p_Var6->BSPTreeArray->endLeaves + iVar20));
      }
      iVar22 = iVar22 + 1;
      iVar20 = iVar20 + 0x24;
    } while (iVar22 < p_Var6->numBSPTrees);
  }
  instance = (gameTrackerX.instanceList)->first;
  while (instance != (_Instance *)0x0) {
    pIVar17 = instance->intro;
    if ((pIVar17 != (Intro *)0x0) &&
       (((*(int *)&pIVar17->spectralPosition != 0 || ((pIVar17->spectralPosition).z != 0)) &&
        ((instance->flags2 & 8U) == 0)))) {
      local_18 = *(u_int *)&instance->position;
      uVar12 = (u_int)(ushort)(instance->position).z;
      local_14 = local_14 & 0xffff0000 | uVar12;
      (instance->position).x = (pIVar17->position).x + (pIVar17->spectralPosition).x;
      (instance->position).y = (pIVar17->position).y + (pIVar17->spectralPosition).y;
      (instance->position).z = (pIVar17->position).z + (pIVar17->spectralPosition).z;
      uVar21 = (u_int)(ushort)(instance->position).x - (local_18 & 0xffff);
      iVar22 = (u_int)(ushort)(instance->position).y - (local_18 >> 0x10);
      local_20 = uVar21 & 0xffff | iVar22 * 0x10000;
      uVar12 = (ushort)(instance->position).z - uVar12;
      local_1c = local_1c & 0xffff0000 | uVar12 & 0xffff;
      if (((int)(uVar21 * 0x10000) >> 0x10) + (iVar22 * 0x10000 >> 0x10) +
          ((int)(uVar12 * 0x10000) >> 0x10) != 0) {
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
 // line 3637, offset 0x8005d084
	/* begin block 1 */
		// Start line: 3638
		// Start offset: 0x8005D084
		// Variables:
	// 		struct _TFace *face; // $v1
	// 		long faceCount; // $a2
	// 		struct _TVertex *v; // $a1
	// 		struct _MorphVertex *mv; // $a0
	// 		struct _MorphColor *mc; // $v0
	// 		void *hldptr; // $a2
	// 		long hldnum; // $t0
	// 		short h1; // $v1
	// 		short *morphNormals; // $a1

		/* begin block 1.1 */
			// Start line: 3693
			// Start offset: 0x8005D160
			// Variables:
		// 		struct _TVertex *endv; // $a2
		/* end block 1.1 */
		// End offset: 0x8005D1C8
		// End Line: 3704

		/* begin block 1.2 */
			// Start line: 3719
			// Start offset: 0x8005D1C8
			// Variables:
		// 		struct _BSPNode *node; // $v1
		// 		struct _BSPLeaf *leaf; // $a0
		// 		struct _Sphere_noSq hsphere; // stack offset -32
		// 		struct _BoundingBox hbox; // stack offset -24
		// 		struct _Terrain *terrain; // $a3
		// 		long curTree; // $t0
		/* end block 1.2 */
		// End offset: 0x8005D420
		// End Line: 3769

		/* begin block 1.3 */
			// Start line: 3772
			// Start offset: 0x8005D420
			// Variables:
		// 		struct _Instance *instance; // $s0

			/* begin block 1.3.1 */
				// Start line: 3778
				// Start offset: 0x8005D448
				// Variables:
			// 		struct SVECTOR realDiff; // stack offset -32
			// 		struct _Position oldPos; // stack offset -24
			/* end block 1.3.1 */
			// End offset: 0x8005D518
			// End Line: 3802
		/* end block 1.3 */
		// End offset: 0x8005D528
		// End Line: 3805
	/* end block 1 */
	// End offset: 0x8005D528
	// End Line: 3806

	/* begin block 2 */
		// Start line: 8500
	/* end block 2 */
	// End Line: 8501

void MORPH_BringBackNormals(Level *BaseLevel)

{
  short *psVar1;
  short sVar2;
  ushort uVar3;
  short sVar4;
  _Terrain *p_Var5;
  _TVertex *p_Var6;
  u_int *puVar7;
  int iVar8;
  undefined4 *puVar9;
  Intro *pIVar10;
  u_int uVar11;
  ushort *puVar12;
  _MorphVertex *p_Var13;
  byte *pbVar14;
  SpotLight *pSVar15;
  undefined4 *puVar16;
  ushort *puVar17;
  long lVar18;
  int iVar19;
  u_int uVar20;
  int iVar21;
  short *psVar22;
  _TVertex *p_Var23;
  PointLight *pPVar24;
  long lVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  _Instance *instance;
  u_int local_20;
  u_int local_1c;
  u_int local_18;
  u_int local_14;
  undefined4 local_10;
  
  p_Var5 = BaseLevel->terrain;
  puVar17 = (ushort *)p_Var5->morphNormalIdx;
  iVar21 = p_Var5->numFaces;
  puVar12 = &p_Var5->faceList->normal;
  if (0 < iVar21) {
    do {
      uVar3 = *puVar12;
      iVar21 = iVar21 + -1;
      *puVar12 = *puVar17;
      *puVar17 = uVar3;
      puVar17 = puVar17 + 1;
      puVar12 = puVar12 + 6;
    } while (0 < iVar21);
    p_Var5 = BaseLevel->terrain;
  }
  p_Var13 = p_Var5->MorphDiffList;
  if (p_Var13 != (_MorphVertex *)0x0) {
    sVar2 = p_Var13->vindex;
    sVar4 = p_Var13->vindex;
    psVar22 = &p_Var13->vindex;
    while (-1 < sVar2) {
      p_Var6 = BaseLevel->terrain->vertexList + sVar4;
      (p_Var6->vertex).x = psVar22[1];
      (p_Var6->vertex).y = psVar22[2];
      psVar1 = psVar22 + 3;
      psVar22 = psVar22 + 7;
      (p_Var6->vertex).z = *psVar1;
      sVar2 = *psVar22;
      sVar4 = *psVar22;
    }
  }
  p_Var5 = BaseLevel->terrain;
  if (p_Var5->MorphColorList != (_MorphColor *)0x0) {
    p_Var6 = p_Var5->vertexList;
    p_Var23 = p_Var6 + p_Var5->numVertices;
    pbVar14 = &p_Var6->b0;
    while (p_Var6 < p_Var23) {
      p_Var6 = p_Var6 + 1;
      pbVar14[-2] = (byte)(((u_int)pbVar14[-4] & 0x1f) << 3);
      pbVar14[-1] = (byte)(*(ushort *)(pbVar14 + -4) >> 2) & 0xf8;
      *pbVar14 = (byte)(*(ushort *)(pbVar14 + -4) >> 7) & 0xf8;
      pbVar14 = pbVar14 + 0xc;
    }
  }
  RemoveIntroducedLights(BaseLevel);
  lVar18 = BaseLevel->numSpotSpecturalLights;
  pSVar15 = BaseLevel->spotSpecturalLightList;
  p_Var5 = BaseLevel->terrain;
  BaseLevel->numSpotSpecturalLights = BaseLevel->numSpotLights;
  lVar25 = BaseLevel->numPointLights;
  BaseLevel->spotSpecturalLightList = BaseLevel->spotLightList;
  pPVar24 = BaseLevel->pointLightList;
  BaseLevel->numSpotLights = lVar18;
  BaseLevel->spotLightList = pSVar15;
  BaseLevel->numPointLights = BaseLevel->numPointSpecturalLights;
  BaseLevel->pointLightList = BaseLevel->pointSpecturalLightList;
  BaseLevel->numPointSpecturalLights = lVar25;
  BaseLevel->pointSpecturalLightList = pPVar24;
  iVar21 = 0;
  if (0 < p_Var5->numBSPTrees) {
    iVar19 = 0;
    do {
      puVar7 = (u_int *)((int)&p_Var5->BSPTreeArray->bspRoot + iVar19);
      puVar16 = (undefined4 *)*puVar7;
      puVar9 = puVar16 + 7;
      if (puVar16 < (undefined4 *)puVar7[1]) {
        do {
          uVar26 = *puVar16;
          local_1c = puVar16[1];
          uVar27 = puVar9[1];
          *puVar16 = *puVar9;
          puVar16[1] = uVar27;
          *puVar9 = uVar26;
          puVar9[1] = local_1c;
          puVar16 = puVar16 + 0xb;
          puVar9 = puVar9 + 0xb;
        } while (puVar16 < *(undefined4 **)((int)&p_Var5->BSPTreeArray->startLeaves + iVar19));
      }
      iVar8 = (int)&p_Var5->BSPTreeArray->bspRoot + iVar19;
      puVar16 = *(undefined4 **)(iVar8 + 4);
      if (puVar16 < *(undefined4 **)(iVar8 + 8)) {
        puVar9 = puVar16 + 7;
        do {
          uVar26 = *puVar16;
          local_1c = puVar16[1];
          uVar27 = puVar9[4];
          *puVar16 = puVar9[3];
          puVar16[1] = uVar27;
          puVar9[3] = uVar26;
          puVar9[4] = local_1c;
          uVar26 = puVar9[-3];
          local_14 = puVar9[-2];
          local_10 = puVar9[-1];
          puVar9[-3] = *puVar9;
          puVar9[-2] = puVar9[1];
          puVar9[-1] = puVar9[2];
          *puVar9 = uVar26;
          puVar9[1] = local_14;
          puVar9[2] = local_10;
          puVar16 = puVar16 + 0xc;
          puVar9 = puVar9 + 0xc;
        } while (puVar16 < *(undefined4 **)((int)&p_Var5->BSPTreeArray->endLeaves + iVar19));
      }
      iVar21 = iVar21 + 1;
      iVar19 = iVar19 + 0x24;
    } while (iVar21 < p_Var5->numBSPTrees);
  }
  instance = (gameTrackerX.instanceList)->first;
  while (instance != (_Instance *)0x0) {
    pIVar10 = instance->intro;
    if ((pIVar10 != (Intro *)0x0) &&
       (((*(int *)&pIVar10->spectralPosition != 0 || ((pIVar10->spectralPosition).z != 0)) &&
        ((instance->flags2 & 8U) == 0)))) {
      local_18 = *(u_int *)&instance->position;
      uVar11 = (u_int)(ushort)(instance->position).z;
      local_14 = local_14 & 0xffff0000 | uVar11;
      (instance->position).x = (pIVar10->position).x;
      (instance->position).y = (pIVar10->position).y;
      (instance->position).z = (pIVar10->position).z;
      uVar20 = (u_int)(ushort)(instance->position).x - (local_18 & 0xffff);
      iVar21 = (u_int)(ushort)(instance->position).y - (local_18 >> 0x10);
      local_20 = uVar20 & 0xffff | iVar21 * 0x10000;
      uVar11 = (ushort)(instance->position).z - uVar11;
      local_1c = local_1c & 0xffff0000 | uVar11 & 0xffff;
      if (((int)(uVar20 * 0x10000) >> 0x10) + (iVar21 * 0x10000 >> 0x10) +
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
// void /*$ra*/ MORPH_AddOffsets(struct Level *BaseLevel /*$s2*/, int time /*$a1*/)
 // line 3808, offset 0x8005d538
	/* begin block 1 */
		// Start line: 3809
		// Start offset: 0x8005D538
		// Variables:
	// 		struct _TVertex *v; // $a3
	// 		struct _MorphVertex *mv; // $a2
	// 		struct _MorphColor *mc; // $t2
	// 		long m; // $v0
	// 		long fixed_time; // $s1
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 3857
			// Start offset: 0x8005D700
			// Variables:
		// 		struct SVECTOR diff; // stack offset -40
		// 		struct SVECTOR realDiff; // stack offset -32
		// 		struct _Position oldPos; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x8005D7FC
		// End Line: 3876

		/* begin block 1.2 */
			// Start line: 3885
			// Start offset: 0x8005D824
			// Variables:
		// 		long r0; // $a2
		// 		long g0; // $a1
		// 		long b0; // $a0
		// 		long r1; // $v0
		// 		long g1; // $v0
		// 		long b1; // $v1

			/* begin block 1.2.1 */
				// Start line: 3895
				// Start offset: 0x8005D824
				// Variables:
			// 		struct _TVertex *endv; // $t4
			/* end block 1.2.1 */
			// End offset: 0x8005D8EC
			// End Line: 3910
		/* end block 1.2 */
		// End offset: 0x8005D8EC
		// End Line: 3933
	/* end block 1 */
	// End offset: 0x8005D8EC
	// End Line: 3935

	/* begin block 2 */
		// Start line: 8931
	/* end block 2 */
	// End Line: 8932

	/* begin block 3 */
		// Start line: 8937
	/* end block 3 */
	// End Line: 8938

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
  u_int uVar13;
  short *psVar14;
  int iVar15;
  u_int uVar16;
  _MorphVertex *p_Var17;
  u_char *puVar18;
  _MorphColor *p_Var19;
  _TVertex *p_Var20;
  _Instance *instance;
  SVECTOR local_20;
  u_int local_18;
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
      local_18 = *(u_int *)&instance->position;
      local_14 = (instance->position).z;
      (instance->position).x =
           (pIVar10->position).x + (short)((pIVar10->spectralPosition).x * iVar7 >> 0xc);
      (instance->position).y = (pIVar10->position).y + (short)(sVar4 * iVar7 >> 0xc);
      (instance->position).z = (pIVar10->position).z + (short)(sVar3 * iVar7 >> 0xc);
      iVar15 = (u_int)(ushort)(instance->position).x - (local_18 & 0xffff);
      local_20.vx = (short)iVar15;
      iVar11 = (u_int)(ushort)(instance->position).y - (local_18 >> 0x10);
      local_20.vy = (short)iVar11;
      iVar9 = (u_int)(ushort)(instance->position).z - (u_int)local_14;
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
        uVar16 = (u_int)(uVar5 >> 2) & 0xf8;
        iVar9 = (u_int)*puVar6 << 0x10;
        uVar13 = (u_int)(uVar5 >> 7) & 0xf8;
        p_Var8 = p_Var8 + 1;
        p_Var19 = p_Var19 + 1;
        puVar18[-2] = (char)((u_int)uVar5 & 0x1f) * '\b' +
                      (char)((int)((((u_int)*puVar6 & 0x1f) * 8 + ((u_int)uVar5 & 0x1f) * -8) * iVar7)
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
 // line 3937, offset 0x8005d904
	/* begin block 1 */
		// Start line: 3938
		// Start offset: 0x8005D904
		// Variables:
	// 		struct _TVertex *v; // $a3
	// 		struct _MorphVertex *mv; // $a2
	// 		struct _MorphColor *mc; // $t2
	// 		long m; // $v0
	// 		long fixed_time; // $s1
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 3984
			// Start offset: 0x8005DAD4
			// Variables:
		// 		struct SVECTOR diff; // stack offset -40
		// 		struct SVECTOR realDiff; // stack offset -32
		// 		struct _Position oldPos; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x8005DBD0
		// End Line: 4004

		/* begin block 1.2 */
			// Start line: 4013
			// Start offset: 0x8005DBF8
			// Variables:
		// 		long r0; // $a2
		// 		long g0; // $a1
		// 		long b0; // $a0
		// 		long r1; // $v0
		// 		long g1; // $v0
		// 		long b1; // $v1

			/* begin block 1.2.1 */
				// Start line: 4022
				// Start offset: 0x8005DBF8
				// Variables:
			// 		struct _TVertex *endv; // $t4
			/* end block 1.2.1 */
			// End offset: 0x8005DCC0
			// End Line: 4037
		/* end block 1.2 */
		// End offset: 0x8005DCC0
		// End Line: 4060
	/* end block 1 */
	// End offset: 0x8005DCC0
	// End Line: 4062

	/* begin block 2 */
		// Start line: 9273
	/* end block 2 */
	// End Line: 9274

	/* begin block 3 */
		// Start line: 9279
	/* end block 3 */
	// End Line: 9280

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
  u_int uVar13;
  short *psVar14;
  int iVar15;
  u_int uVar16;
  _MorphVertex *p_Var17;
  u_char *puVar18;
  _MorphColor *p_Var19;
  _TVertex *p_Var20;
  _Instance *instance;
  SVECTOR local_20;
  u_int local_18;
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
      local_18 = *(u_int *)&instance->position;
      local_14 = (instance->position).z;
      (instance->position).x =
           (pIVar11->position).x + (short)((pIVar11->spectralPosition).x * iVar7 >> 0xc);
      (instance->position).y = (pIVar11->position).y + (short)(sVar4 * iVar7 >> 0xc);
      (instance->position).z = (pIVar11->position).z + (short)(sVar3 * iVar7 >> 0xc);
      iVar15 = (u_int)(ushort)(instance->position).x - (local_18 & 0xffff);
      local_20.vx = (short)iVar15;
      iVar12 = (u_int)(ushort)(instance->position).y - (local_18 >> 0x10);
      local_20.vy = (short)iVar12;
      iVar9 = (u_int)(ushort)(instance->position).z - (u_int)local_14;
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
        uVar16 = (u_int)(uVar5 >> 2) & 0xf8;
        iVar9 = (u_int)*puVar6 << 0x10;
        uVar13 = (u_int)(uVar5 >> 7) & 0xf8;
        p_Var8 = p_Var8 + 1;
        p_Var19 = p_Var19 + 1;
        puVar18[-2] = (char)((u_int)uVar5 & 0x1f) * '\b' +
                      (char)((int)((((u_int)*puVar6 & 0x1f) * 8 + ((u_int)uVar5 & 0x1f) * -8) * iVar7)
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
 // line 4067, offset 0x8005dcd8
	/* begin block 1 */
		// Start line: 4068
		// Start offset: 0x8005DCD8
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
			// Start line: 4080
			// Start offset: 0x8005DCF8
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
		// End offset: 0x8005DCF8
		// End Line: 4080

		/* begin block 1.2 */
			// Start line: 4096
			// Start offset: 0x8005DDCC
			// Variables:
		// 		int next; // $v1

			/* begin block 1.2.1 */
				// Start line: 4103
				// Start offset: 0x8005DE54
				// Variables:
			// 		int div; // $a0
			/* end block 1.2.1 */
			// End offset: 0x8005DEA0
			// End Line: 4108
		/* end block 1.2 */
		// End offset: 0x8005DEA0
		// End Line: 4109
	/* end block 1 */
	// End offset: 0x8005DFB8
	// End Line: 4135

	/* begin block 2 */
		// Start line: 9614
	/* end block 2 */
	// End Line: 9615

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
      SHORT_800d2a04 = 0;
    }
    else {
      SHORT_800d2a04 = (short)(((local_10 - local_8[0]) * 0x1000) / (local_8[1] - local_8[0]));
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_AveragePoint(struct _SVector *start /*$v1*/, struct _SVector *end /*$a1*/, int interp /*$v0*/, struct _SVector *out /*$a3*/)
 // line 4137, offset 0x8005dfc0
	/* begin block 1 */
		// Start line: 9819
	/* end block 1 */
	// End Line: 9820

void MORPH_AveragePoint(_SVector *start,_SVector *end,int interp,_SVector *out)

{
  _SVector *p_Var1;
  undefined *puVar2;
  
  if (interp < 0) {
    puVar2 = &DAT_0000132a + interp;
    interp = -interp;
    p_Var1 = end;
  }
  else {
    puVar2 = (undefined *)(0x1000 - interp);
    p_Var1 = start;
    start = end;
  }
  LoadAverageShort12((u_int *)p_Var1,(u_int *)start,puVar2,interp,(u_int *)out);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_UpdateTrackingPoint(struct _TFace *face /*$a2*/, struct Level *level /*$s2*/)
 // line 4151, offset 0x8005e014
	/* begin block 1 */
		// Start line: 4152
		// Start offset: 0x8005E014
		// Variables:
	// 		struct _SVector (*v[3]); // stack offset -56
	// 		struct _SVector p1; // stack offset -40
	// 		struct _SVector p2; // stack offset -32
	// 		struct _SVector p3; // stack offset -24
	// 		struct _Position *offset; // $a3
	// 		int next; // $a1
	// 		struct _TVertex *vertexList; // $a0

		/* begin block 1.1 */
			// Start line: 4172
			// Start offset: 0x8005E0E8
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $a0
		// 		short _z0; // $a1
		// 		short _x1; // $v1
		// 		short _y1; // $t0
		// 		short _z1; // $a3
		/* end block 1.1 */
		// End offset: 0x8005E0E8
		// End Line: 4172

		/* begin block 1.2 */
			// Start line: 4172
			// Start offset: 0x8005E0E8
			// Variables:
		// 		struct _Position *_v0; // $a2
		/* end block 1.2 */
		// End offset: 0x8005E0E8
		// End Line: 4172
	/* end block 1 */
	// End offset: 0x8005E194
	// End Line: 4184

	/* begin block 2 */
		// Start line: 9847
	/* end block 2 */
	// End Line: 9848

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
    iVar6 = (int)SHORT_800d2a0a + 1;
    if (2 < iVar6) {
      iVar6 = 0;
    }
    MORPH_AveragePoint((_SVector *)local_38[(int)SHORT_800d2a0a],(_SVector *)local_38[iVar6],
                       (int)SHORT_800d2a02,&_Stack32);
    MORPH_AveragePoint(&_Stack40,&_Stack32,(int)SHORT_800d2a04,&local_18);
    p_Var3 = gameTrackerX.playerInstance;
    pBVar4 = level->terrain->BSPTreeArray + (gameTrackerX.playerInstance)->bspTree;
    sVar1 = (pBVar4->globalOffset).y;
    sVar2 = (pBVar4->globalOffset).z;
    ((gameTrackerX.playerInstance)->position).x = local_18.x + (pBVar4->globalOffset).x;
    (p_Var3->position).y = local_18.y + sVar1;
    (p_Var3->position).z = local_18.z + sVar2;
    (gameTrackerX.playerInstance)->cachedTFace = -1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_ToggleMorph()
 // line 4186, offset 0x8005e1ac
	/* begin block 1 */
		// Start line: 4187
		// Start offset: 0x8005E1AC

		/* begin block 1.1 */
			// Start line: 4205
			// Start offset: 0x8005E218
			// Variables:
		// 		struct Level *level; // $s0
		// 		int i; // $s2
		/* end block 1.1 */
		// End offset: 0x8005E2E4
		// End Line: 4241
	/* end block 1 */
	// End offset: 0x8005E2E4
	// End Line: 4243

	/* begin block 2 */
		// Start line: 9928
	/* end block 2 */
	// End Line: 9929

	/* begin block 3 */
		// Start line: 9930
	/* end block 3 */
	// End Line: 9931

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MORPH_ToggleMorph(void)

{
  _MultiSignal *mSignal;
  Level *pLVar1;
  Level **ppLVar2;
  int iVar3;
  
  SOUND_PlaneShift((u_int)(gameTrackerX.gameData.asmData.MorphType == 0));
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
LAB_8005e2d0:
          EVENT_AddSignalToReset(mSignal);
        }
      }
      else {
        mSignal = pLVar1->spectralSignal;
        if (mSignal != (_MultiSignal *)0x0) {
          mSignal->flags = mSignal->flags | 1;
          SIGNAL_HandleSignal(gameTrackerX.playerInstance,pLVar1->spectralSignal->signalList,0);
          mSignal = pLVar1->spectralSignal;
          goto LAB_8005e2d0;
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
 // line 4245, offset 0x8005e2fc
	/* begin block 1 */
		// Start line: 4246
		// Start offset: 0x8005E2FC
		// Variables:
	// 		struct Level *level; // $s0
	/* end block 1 */
	// End offset: 0x8005E3C8
	// End Line: 4303

	/* begin block 2 */
		// Start line: 10082
	/* end block 2 */
	// End Line: 10083

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
 // line 4305, offset 0x8005e3d8
	/* begin block 1 */
		// Start line: 4306
		// Start offset: 0x8005E3D8
		// Variables:
	// 		long time; // $v1
	// 		struct Level *level; // $a2
	// 		int fogNear; // $a1
	// 		int fogFar; // $v0
	/* end block 1 */
	// End offset: 0x8005E49C
	// End Line: 4328

	/* begin block 2 */
		// Start line: 10205
	/* end block 2 */
	// End Line: 10206

	/* begin block 3 */
		// Start line: 10211
	/* end block 3 */
	// End Line: 10212

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
  iVar4 = ((u_int)pLVar3->holdFogNear - (u_int)pLVar3->spectralFogNear) * iVar2;
  if (iVar4 < 0) {
    iVar4 = iVar4 + 0xfff;
  }
  iVar2 = ((u_int)pLVar3->holdFogFar - (u_int)pLVar3->spectralFogFar) * iVar2;
  iVar4 = (iVar4 >> 0xc) + (u_int)pLVar3->spectralFogNear;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  iVar2 = (iVar2 >> 0xc) + (u_int)pLVar3->spectralFogFar;
  if (mainUnitFlag == 0) {
    STREAM_SetStreamFog(streamUnit,(short)((u_int)(iVar4 * 0x10000) >> 0x10),
                        (short)((u_int)(iVar2 * 0x10000) >> 0x10));
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
 // line 4330, offset 0x8005e4ac
	/* begin block 1 */
		// Start line: 4331
		// Start offset: 0x8005E4AC
		// Variables:
	// 		long time; // $a0
	/* end block 1 */
	// End offset: 0x8005E4EC
	// End Line: 4341

	/* begin block 2 */
		// Start line: 10265
	/* end block 2 */
	// End Line: 10266

	/* begin block 3 */
		// Start line: 10268
	/* end block 3 */
	// End Line: 10269

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
 // line 4345, offset 0x8005e504
	/* begin block 1 */
		// Start line: 4346
		// Start offset: 0x8005E504
		// Variables:
	// 		int i; // $s2
	// 		long mode; // $v0
	/* end block 1 */
	// End offset: 0x8005E678
	// End Line: 4404

	/* begin block 2 */
		// Start line: 10298
	/* end block 2 */
	// End Line: 10299

	/* begin block 3 */
		// Start line: 10303
	/* end block 3 */
	// End Line: 10304

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MORPH_Continue(void)

{
  u_long uVar1;
  _TFace *face;
  Level *level;
  STracker *streamUnit;
  char *baseAreaName;
  int iVar2;
  
  if (gameTrackerX.gameData.asmData.MorphTime == 0) {
    MORPH_InMorphInstanceListFlags(&gameTrackerX);
  }
  iVar2 = 0;
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
    MORPH_SetupInstanceListFlags(&gameTrackerX);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_MORPH_Relocate()
 // line 4405, offset 0x8005e694
	/* begin block 1 */
		// Start line: 10443
	/* end block 1 */
	// End Line: 10444

	/* begin block 2 */
		// Start line: 10444
	/* end block 2 */
	// End Line: 10445

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
 // line 4568, offset 0x8005e6a4
	/* begin block 1 */
		// Start line: 4569
		// Start offset: 0x8005E6A4
		// Variables:
	// 		struct SVECTOR v; // stack offset -8
	// 		int x; // $v0
	// 		int y; // $v1
	// 		int z; // $a1
	// 		int scr_x; // $a0
	// 		int scr_y; // $a1
	/* end block 1 */
	// End offset: 0x8005E828
	// End Line: 4605

	/* begin block 2 */
		// Start line: 10769
	/* end block 2 */
	// End Line: 10770

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
  u_int local_4;
  
  iVar2 = v0->vx;
  if (iVar2 < 0) {
    iVar1 = -0x8000;
LAB_8005e6c8:
    v0->vx = iVar2 + iVar1;
  }
  else {
    iVar1 = 0x8000;
    if (0 < iVar2) goto LAB_8005e6c8;
  }
  iVar1 = v0->vy;
  iVar2 = -0x8000;
  if ((iVar1 < 0) || (iVar2 = 0x8000, 0 < iVar1)) {
    v0->vy = iVar1 + iVar2;
  }
  iVar1 = v0->vz;
  iVar2 = -0x8000;
  if (-1 < iVar1) {
    if (iVar1 < 1) goto LAB_8005e714;
    iVar2 = 0x8000;
  }
  v0->vz = iVar1 + iVar2;
LAB_8005e714:
  local_8 = CONCAT22(*(undefined2 *)((int)&v0->vy + 2),*(undefined2 *)((int)&v0->vx + 2));
  local_4 = local_4 & 0xffff0000 | (u_int)*(ushort *)((int)&v0->vz + 2);
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
 // line 4607, offset 0x8005e830
	/* begin block 1 */
		// Start line: 10852
	/* end block 1 */
	// End Line: 10853

	/* begin block 2 */
		// Start line: 10853
	/* end block 2 */
	// End Line: 10854

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
 // line 4616, offset 0x8005e8c0
	/* begin block 1 */
		// Start line: 4617
		// Start offset: 0x8005E8C0
		// Variables:
	// 		int diff; // $a3
	/* end block 1 */
	// End offset: 0x8005E8C0
	// End Line: 4617

	/* begin block 2 */
		// Start line: 10870
	/* end block 2 */
	// End Line: 10871

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
 // line 4630, offset 0x8005e948
	/* begin block 1 */
		// Start line: 4631
		// Start offset: 0x8005E948
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
			// Start line: 4707
			// Start offset: 0x8005EB80
			// Variables:
		// 		int z; // $v0
		/* end block 1.1 */
		// End offset: 0x8005EBAC
		// End Line: 4711
	/* end block 1 */
	// End offset: 0x8005EBC0
	// End Line: 4713

	/* begin block 2 */
		// Start line: 10898
	/* end block 2 */
	// End Line: 10899

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
  u_int local_3c;
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
    local_3c = (u_int)!bVar2;
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
            goto LAB_8005eb1c;
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
LAB_8005eb1c:
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
      return (u_int)(iVar6 != 0);
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
 // line 4715, offset 0x8005ebf0
	/* begin block 1 */
		// Start line: 4716
		// Start offset: 0x8005EBF0
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
			// Start line: 4804
			// Start offset: 0x8005EEE4
			// Variables:
		// 		int dot; // $v0
		/* end block 1.1 */
		// End offset: 0x8005EF64
		// End Line: 4814
	/* end block 1 */
	// End offset: 0x8005F18C
	// End Line: 4881

	/* begin block 2 */
		// Start line: 11185
	/* end block 2 */
	// End Line: 11186

int STREAM_GetClipRect(StreamUnitPortal *portal,RECT *rect)

{
  short sVar1;
  int iVar2;
  u_int uVar3;
  u_int uVar4;
  u_int uVar5;
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
  u_int local_30;
  int local_2c;
  
  local_2c = 0;
  sVar9 = portal->t1[0].z;
  iVar17 = (int)sVar9;
  iVar11 = (int)portal->t1[1].z;
  local_30 = 0;
  if (iVar17 == iVar11) {
    local_30 = (u_int)(sVar9 == portal->t1[2].z);
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
          uVar3 = (u_int)(0 < rect->h);
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
 // line 4884, offset 0x8005f1bc
	/* begin block 1 */
		// Start line: 4885
		// Start offset: 0x8005F1BC
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
			// Start line: 4897
			// Start offset: 0x8005F1F0
			// Variables:
		// 		int time; // $a2
		/* end block 1.1 */
		// End offset: 0x8005F228
		// End Line: 4903
	/* end block 1 */
	// End offset: 0x8005F4CC
	// End Line: 4991

	/* begin block 2 */
		// Start line: 11694
	/* end block 2 */
	// End Line: 11695

long GetFogColor(StreamUnitPortal *portal,_StreamUnit *mainStreamUnit,Level *mainLevel)

{
  undefined4 in_zero;
  undefined4 in_at;
  u_int uVar1;
  byte *pbVar2;
  Level *pLVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  u_int local_28;
  int local_24;
  int local_20;
  int local_1c;
  u_int local_18;
  u_int local_14;
  
  local_18 = mainStreamUnit->FogColor;
  pLVar3 = portal->toStreamUnit->level;
  if ((int)gameTrackerX.gameData.asmData.MorphTime == 1000) {
    if (gameTrackerX.gameData.asmData.MorphType == 1) {
      local_28 = *(u_int *)&pLVar3->specturalColorR;
    }
    else {
      local_28 = *(u_int *)&pLVar3->backColorR;
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
    if (iVar6 <= iVar4) goto LAB_8005f314;
  }
  iVar4 = iVar6;
LAB_8005f314:
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
  uVar1 = (u_int)mainLevel->fogFar;
  if ((int)(iVar4 + 0x80U) < (int)(u_int)mainLevel->fogFar) {
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
    iVar5 = uVar1 - (u_int)mainLevel->fogNear;
    if (-1 < iVar5) {
      iVar6 = (iVar5 * 0x10000) / (int)((u_int)mainLevel->fogFar - (u_int)mainLevel->fogNear) >> 4;
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
 // line 4993, offset 0x8005f4e0
	/* begin block 1 */
		// Start line: 4994
		// Start offset: 0x8005F4E0
		// Variables:
	// 		struct POLY_G4 *polyg4; // $t0
	/* end block 1 */
	// End offset: 0x8005F5C4
	// End Line: 5035

	/* begin block 2 */
		// Start line: 11924
	/* end block 2 */
	// End Line: 11925

	/* begin block 3 */
		// Start line: 11927
	/* end block 3 */
	// End Line: 11928

void DrawFogRectangle(RECT *cliprect,_PrimPool *primPool,int otzpos,u_long **drawot,long color)

{
  short sVar1;
  short sVar2;
  u_long *puVar3;
  
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
    *puVar3 = (u_int)drawot[otzpos] & 0xffffff | 0x8000000;
    drawot[otzpos] = (u_long *)((u_int)puVar3 & 0xffffff);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_RenderAdjacantUnit(unsigned long **curOT /*$s3*/, struct StreamUnitPortal *curStreamPortal /*$s0*/, struct _StreamUnit *toStreamUnit /*$s1*/, struct _StreamUnit *mainStreamUnit /*$s2*/, struct RECT *cliprect /*stack 16*/)
 // line 5041, offset 0x8005f5cc
	/* begin block 1 */
		// Start line: 5042
		// Start offset: 0x8005F5CC

		/* begin block 1.1 */
			// Start line: 5046
			// Start offset: 0x8005F604
			// Variables:
		// 		long portalFogColor; // $s0
		/* end block 1.1 */
		// End offset: 0x8005F65C
		// End Line: 5058
	/* end block 1 */
	// End offset: 0x8005F65C
	// End Line: 5059

	/* begin block 2 */
		// Start line: 12106
	/* end block 2 */
	// End Line: 12107

void STREAM_RenderAdjacantUnit
               (u_long **curOT,StreamUnitPortal *curStreamPortal,_StreamUnit *toStreamUnit,
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
 // line 5061, offset 0x8005f678
	/* begin block 1 */
		// Start line: 5063
		// Start offset: 0x8005F678
		// Variables:
	// 		struct Level *level; // $v0
	// 		struct _Terrain *terrain; // $v0
	// 		int d; // $a0
	/* end block 1 */
	// End offset: 0x8005F6D0
	// End Line: 5083

	/* begin block 2 */
		// Start line: 12152
	/* end block 2 */
	// End Line: 12153

	/* begin block 3 */
		// Start line: 12153
	/* end block 3 */
	// End Line: 12154

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
 // line 5086, offset 0x8005f6d8
	/* begin block 1 */
		// Start line: 5087
		// Start offset: 0x8005F6D8
		// Variables:
	// 		struct BSPTree *bspTree; // $v1
	/* end block 1 */
	// End offset: 0x8005F738
	// End Line: 5104

	/* begin block 2 */
		// Start line: 12206
	/* end block 2 */
	// End Line: 12207

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
 // line 5107, offset 0x8005f748
	/* begin block 1 */
		// Start line: 5108
		// Start offset: 0x8005F748
		// Variables:
	// 		struct BSPTree *bspTree; // $v1
	/* end block 1 */
	// End offset: 0x8005F790
	// End Line: 5128

	/* begin block 2 */
		// Start line: 12248
	/* end block 2 */
	// End Line: 12249

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
 // line 5130, offset 0x8005f7a0
	/* begin block 1 */
		// Start line: 5132
		// Start offset: 0x8005F7A0
		// Variables:
	// 		struct Object *warpFaceObject; // $a1

		/* begin block 1.1 */
			// Start line: 5138
			// Start offset: 0x8005F7B4
			// Variables:
		// 		struct _Instance *instance; // $v1
		// 		struct _Instance *next; // $a0
		/* end block 1.1 */
		// End offset: 0x8005F7F8
		// End Line: 5153
	/* end block 1 */
	// End offset: 0x8005F7F8
	// End Line: 5155

	/* begin block 2 */
		// Start line: 12294
	/* end block 2 */
	// End Line: 12295

	/* begin block 3 */
		// Start line: 12295
	/* end block 3 */
	// End Line: 12296

	/* begin block 4 */
		// Start line: 12298
	/* end block 4 */
	// End Line: 12299

/* WARNING: Removing unreachable block (ram,0x8005f7b4) */
/* WARNING: Removing unreachable block (ram,0x8005f7cc) */
/* WARNING: Removing unreachable block (ram,0x8005f7dc) */
/* WARNING: Removing unreachable block (ram,0x8005f7ec) */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void WARPGATE_HideAllCloudCovers(void)

{
  return;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ WARPGATE_UnHideCloudCoverInUnit(long streamUnitID /*$a0*/)
 // line 5157, offset 0x8005f800
	/* begin block 1 */
		// Start line: 5159
		// Start offset: 0x8005F800
		// Variables:
	// 		struct Object *warpFaceObject; // $a3
	// 		struct _Instance *result; // $a2

		/* begin block 1.1 */
			// Start line: 5166
			// Start offset: 0x8005F814
			// Variables:
		// 		struct _Instance *instance; // $v1
		// 		struct _Instance *next; // $a1
		/* end block 1.1 */
		// End offset: 0x8005F870
		// End Line: 5184
	/* end block 1 */
	// End offset: 0x8005F870
	// End Line: 5186

	/* begin block 2 */
		// Start line: 12350
	/* end block 2 */
	// End Line: 12351

	/* begin block 3 */
		// Start line: 12351
	/* end block 3 */
	// End Line: 12352

	/* begin block 4 */
		// Start line: 12355
	/* end block 4 */
	// End Line: 12356

/* WARNING: Removing unreachable block (ram,0x8005f814) */
/* WARNING: Removing unreachable block (ram,0x8005f82c) */
/* WARNING: Removing unreachable block (ram,0x8005f83c) */
/* WARNING: Removing unreachable block (ram,0x8005f84c) */
/* WARNING: Removing unreachable block (ram,0x8005f864) */

_Instance * WARPGATE_UnHideCloudCoverInUnit(long streamUnitID)

{
  return (_Instance *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_RenderWarpGate(unsigned long **mainOT /*$s3*/, struct StreamUnitPortal *curStreamPortal /*$s2*/, struct _StreamUnit *mainStreamUnit /*$s1*/, struct RECT *cliprect /*$s4*/)
 // line 5190, offset 0x8005f878
	/* begin block 1 */
		// Start line: 5191
		// Start offset: 0x8005F878
		// Variables:
	// 		struct _StreamUnit *toStreamUnit; // $s0
	/* end block 1 */
	// End offset: 0x8005FBA4
	// End Line: 5300

	/* begin block 2 */
		// Start line: 12421
	/* end block 2 */
	// End Line: 12422

void STREAM_RenderWarpGate
               (u_long **mainOT,StreamUnitPortal *curStreamPortal,_StreamUnit *mainStreamUnit,
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
 // line 5303, offset 0x8005fbc4
	/* begin block 1 */
		// Start line: 5304
		// Start offset: 0x8005FBC4
		// Variables:
	// 		unsigned long **curOT; // $s3
	// 		struct DR_AREA *PortalClip; // $s0
	// 		struct _StreamUnit *toStreamUnit; // $s1

		/* begin block 1.1 */
			// Start line: 5337
			// Start offset: 0x8005FC8C
			// Variables:
		// 		struct RECT PortalRect; // stack offset -48
		// 		long portalFogColor; // $s0

			/* begin block 1.1.1 */
				// Start line: 5406
				// Start offset: 0x8005FED8
				// Variables:
			// 		unsigned long *hld; // $a0
			/* end block 1.1.1 */
			// End offset: 0x8005FF70
			// End Line: 5424
		/* end block 1.1 */
		// End offset: 0x8005FF70
		// End Line: 5425
	/* end block 1 */
	// End offset: 0x8005FF70
	// End Line: 5427

	/* begin block 2 */
		// Start line: 12658
	/* end block 2 */
	// End Line: 12659

/* WARNING: Could not reconcile some variable overlaps */

void WARPGATE_RenderWarpUnit
               (u_long **mainOT,StreamUnitPortal *curStreamPortal,_StreamUnit *mainStreamUnit,
               RECT *cliprect)

{
  int iVar1;
  long color;
  u_long *puVar2;
  _StreamUnit *streamUnit;
  u_long **drawot;
  undefined4 local_30;
  undefined4 local_2c;
  
  streamUnit = curStreamPortal->toStreamUnit;
  if ((gameTrackerX.debugFlags2 & 0x1000000U) != 0) {
    FONT_Print("Looking at warp unit =%s\n");
  }
  WARPGATE_BlockWarpGateEntrance(mainStreamUnit,(u_int)((streamUnit->flags & 8U) != 0));
  WARPGATE_DrawWarpGateRim(streamUnit,1);
  color = MEMPACK_MemoryValidFunc((char *)streamUnit->level);
  if ((color != 0) &&
     (drawot = (u_long **)(gameTrackerX.primPool)->nextPrim,
     drawot < (gameTrackerX.primPool)->lastPrim + -0xc00)) {
    *(u_long ***)&(gameTrackerX.primPool)->nextPrim = drawot + 0xc00;
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
    local_30 = CONCAT22((short)((u_int)*(undefined4 *)cliprect >> 0x10) +
                        (&draw)[gameTrackerX.drawPage].ofs[1],
                        (short)local_30 + (&draw)[gameTrackerX.drawPage].ofs[0]);
    SetDrawArea((int)puVar2,(ushort *)&local_30);
    *puVar2 = (u_int)drawot[0xbfe] & 0xffffff | 0x2000000;
    drawot[0xbfe] = (u_long *)((u_int)puVar2 & 0xffffff);
    if ((streamUnit->flags & 8U) == 0) {
      DRAW_TranslucentQuad
                (cliprect->x,cliprect->y,
                 (short)(((u_int)(ushort)cliprect->x + (u_int)(ushort)cliprect->w) * 0x10000 >> 0x10),
                 cliprect->y,(int)cliprect->x,
                 (int)(((u_int)(ushort)cliprect->y + (u_int)(ushort)cliprect->h) * 0x10000) >> 0x10,
                 (int)(((u_int)(ushort)cliprect->x + (u_int)(ushort)cliprect->w) * 0x10000) >> 0x10,
                 (int)(((u_int)(ushort)cliprect->y + (u_int)(ushort)cliprect->h) * 0x10000) >> 0x10,
                 0x32,0x32,0x32,1,gameTrackerX.primPool,drawot + 1);
      DRAW_TranslucentQuad
                (cliprect->x,cliprect->y,
                 (short)(((u_int)(ushort)cliprect->x + (u_int)(ushort)cliprect->w) * 0x10000 >> 0x10),
                 cliprect->y,(int)cliprect->x,
                 (int)(((u_int)(ushort)cliprect->y + (u_int)(ushort)cliprect->h) * 0x10000) >> 0x10,
                 (int)(((u_int)(ushort)cliprect->x + (u_int)(ushort)cliprect->w) * 0x10000) >> 0x10,
                 (int)(((u_int)(ushort)cliprect->y + (u_int)(ushort)cliprect->h) * 0x10000) >> 0x10,
                 0x32,0x32,0x32,2,gameTrackerX.primPool,drawot + 1);
    }
    puVar2 = (gameTrackerX.primPool)->nextPrim;
    (gameTrackerX.primPool)->nextPrim = puVar2 + 3;
    local_30 = *(undefined4 *)(&draw)[gameTrackerX.drawPage].ofs;
    local_2c = 0xf00200;
    SetDrawArea((int)puVar2,(ushort *)&local_30);
    *puVar2 = (u_int)drawot[1] & 0xffffff | 0x2000000;
    iVar1 = s_zval;
    drawot[1] = (u_long *)((u_int)puVar2 & 0xffffff);
    puVar2 = mainOT[iVar1];
    mainOT[iVar1] = drawot[0xbff];
    *drawot = puVar2;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpNonResidentObjects()
 // line 5485, offset 0x8005ffa0
	/* begin block 1 */
		// Start line: 5486
		// Start offset: 0x8005FFA0
		// Variables:
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 5493
			// Start offset: 0x8005FFCC
			// Variables:
		// 		struct _Instance *next; // $s2
		// 		struct Object *object; // $s1
		/* end block 1.1 */
		// End offset: 0x80060020
		// End Line: 5508
	/* end block 1 */
	// End offset: 0x8006002C
	// End Line: 5511

	/* begin block 2 */
		// Start line: 13065
	/* end block 2 */
	// End Line: 13066

	/* begin block 3 */
		// Start line: 13070
	/* end block 3 */
	// End Line: 13071

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



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_TryAndDumpNonResident(struct _ObjectTracker *otr /*$s2*/)
 // line 5517, offset 0x80060058
	/* begin block 1 */
		// Start line: 5518
		// Start offset: 0x80060058
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		struct _Instance *next; // $s1
	/* end block 1 */
	// End offset: 0x80060180
	// End Line: 5572

	/* begin block 2 */
		// Start line: 13154
	/* end block 2 */
	// End Line: 13155

int STREAM_TryAndDumpNonResident(_ObjectTracker *otr)

{
  _Instance **pp_Var1;
  _Instance *instance;
  u_int uVar2;
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
          if (p_Var4->object == otr->object) {
            if (p_Var4->LinkParent != (_Instance *)0x0) {
              return 0;
            }
            if (p_Var4->LinkChild != (_Instance *)0x0) {
              return 0;
            }
            if (p_Var4->LinkSibling != (_Instance *)0x0) {
              return 0;
            }
          }
          p_Var4 = *pp_Var1;
        } while (*pp_Var1 != (_Instance *)0x0);
        p_Var4 = (gameTrackerX.instanceList)->first;
      }
      while (instance = p_Var4, instance != (_Instance *)0x0) {
        p_Var4 = instance->next;
        if (instance->object == otr->object) {
          SAVE_DeleteInstance(instance);
          INSTANCE_ReallyRemoveInstance(gameTrackerX.instanceList,instance,0);
        }
      }
      STREAM_RemoveAllObjectsNotInUse(&gameTrackerX);
      uVar2 = (u_int)(otr->objectStatus == 0);
    }
  }
  return uVar2;
}





