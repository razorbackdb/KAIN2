#include "THISDUST.H"
#include "STREAM.H"


// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_FillOutFileNames(char *baseAreaName /*$s0*/, char *dramName /*$s1*/, char *vramName /*$s2*/, char *sfxName /*$s3*/)
 // line 162, offset 0x800584e4
	/* begin block 1 */
		// Start line: 163
		// Start offset: 0x800584E4
		// Variables:
	// 		char text[16]; // stack offset -40
	// 		char *number; // $v0
	/* end block 1 */
	// End offset: 0x80058588
	// End Line: 187

	/* begin block 2 */
		// Start line: 324
	/* end block 2 */
	// End Line: 325

void STREAM_FillOutFileNames(char *baseAreaName,char *dramName,char *vramName,char *sfxName)

{
  char acStack40 [16];
  
                    /* WARNING: Subroutine does not return */
  strcpy(acStack40,baseAreaName);
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_AbortAreaLoad(char *baseAreaName /*$s0*/)
 // line 192, offset 0x800585a4
	/* begin block 1 */
		// Start line: 193
		// Start offset: 0x800585A4
		// Variables:
	// 		char vramName[80]; // stack offset -88
	/* end block 1 */
	// End offset: 0x800585A4
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
 // line 204, offset 0x800585ec
	/* begin block 1 */
		// Start line: 206
		// Start offset: 0x800585EC
		// Variables:
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x80058610
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

void STREAM_Init(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = (undefined4 *)&gp0xffffbe6c;
  do {
    *(undefined2 *)(puVar1 + 1) = 0;
    *(undefined2 *)((int)puVar1 + 6) = 0;
    *puVar1 = 0;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 0x10;
  } while (iVar2 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ FindObjectName(char *name /*$s2*/)
 // line 216, offset 0x80058618
	/* begin block 1 */
		// Start line: 217
		// Start offset: 0x80058618
		// Variables:
	// 		int i; // $s0
	// 		struct _ObjectTracker *otr; // $s1
	/* end block 1 */
	// End offset: 0x8005866C
	// End Line: 228

	/* begin block 2 */
		// Start line: 442
	/* end block 2 */
	// End Line: 443

int FindObjectName(char *name)

{
  int iVar1;
  char *s1;
  
  iVar1 = 0;
  s1 = (char *)theCamera.core.vvPlaneConsts[3];
  do {
    if (*(short *)(s1 + 0x14) != 0) {
                    /* WARNING: Subroutine does not return */
      strcmpi(s1,name);
    }
    iVar1 = iVar1 + 1;
    s1 = s1 + 0x24;
  } while (iVar1 < 0x30);
  return -1;
}



// decompiled code
// original method signature: 
// struct _ObjectTracker * /*$ra*/ FindObjectInTracker(struct Object *object /*$a0*/)
 // line 230, offset 0x80058684
	/* begin block 1 */
		// Start line: 232
		// Start offset: 0x80058684
		// Variables:
	// 		int i; // $a2
	// 		struct _ObjectTracker *otr; // $a1
	/* end block 1 */
	// End offset: 0x800586CC
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
  ppOVar1 = (Object **)(theCamera.core.vvPlaneConsts[3] + 0x10);
  p_Var2 = (_ObjectTracker *)theCamera.core.vvPlaneConsts[3];
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
 // line 258, offset 0x800586d4
	/* begin block 1 */
		// Start line: 260
		// Start offset: 0x800586D4
		// Variables:
	// 		struct _StreamUnit *ret; // $a2
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x8005871C
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
  _StreamUnit *p_Var1;
  int iVar2;
  
  iVar2 = 0;
  p_Var1 = (_StreamUnit *)(fontTracker.font_buffer + 0x5c);
  while ((p_Var1->used != 2 || (p_Var1->level != level))) {
    iVar2 = iVar2 + 1;
    p_Var1 = p_Var1 + 1;
    if (0xf < iVar2) {
      return (_StreamUnit *)0x0;
    }
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_LoadObjectReturn(void *loadData /*$s0*/, void *data /*$s1*/, void *data2 /*$a2*/)
 // line 328, offset 0x80058724
	/* begin block 1 */
		// Start line: 329
		// Start offset: 0x80058724
		// Variables:
	// 		struct Object *object; // $s0
	// 		struct _ObjectTracker *objectTracker; // $s1

		/* begin block 1.1 */
			// Start line: 374
			// Start offset: 0x800587C8
			// Variables:
		// 		char objDsfxFileName[64]; // stack offset -80
		/* end block 1.1 */
		// End offset: 0x80058800
		// End Line: 386
	/* end block 1 */
	// End offset: 0x80058818
	// End Line: 397

	/* begin block 2 */
		// Start line: 664
	/* end block 2 */
	// End Line: 665

void STREAM_LoadObjectReturn(uint *param_1,_ObjectTracker *param_2)

{
  short sVar1;
  char acStack80 [64];
  
  GetRCnt(0xf2000000);
  if (param_1 == (uint *)0x0) {
    STREAM_DumpObject(param_2);
  }
  else {
    if ((((*param_1 & 0x8000000) != 0) && ((int *)param_1[0xf] != (int *)0x0)) &&
       (param_1[0x10] != 0)) {
      RELMOD_InitModulePointers(param_1[0x10],(int *)param_1[0xf]);
    }
    STREAM_PackVRAMObject((int)param_2);
    OBTABLE_InitAnimPointers(param_2);
    OBTABLE_InitObjectWithID((int)param_1);
    if ((param_1[0xb] & 0x800000) != 0) {
                    /* WARNING: Subroutine does not return */
      sprintf(acStack80,(char *)&draw_belowSplit);
    }
    sVar1 = 4;
    if (param_2->vramBlock == (void *)0x0) {
      sVar1 = 2;
    }
    param_2->objectStatus = sVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpMonster(struct _ObjectTracker *dumpee /*$s2*/)
 // line 399, offset 0x8005882c
	/* begin block 1 */
		// Start line: 400
		// Start offset: 0x8005882C
		// Variables:
	// 		struct Object *object; // $s1
	// 		struct _Instance *instance; // $a1

		/* begin block 1.1 */
			// Start line: 407
			// Start offset: 0x80058858
			// Variables:
		// 		struct _Instance *next; // $s0
		/* end block 1.1 */
		// End offset: 0x80058874
		// End Line: 414
	/* end block 1 */
	// End offset: 0x80058880
	// End Line: 417

	/* begin block 2 */
		// Start line: 806
	/* end block 2 */
	// End Line: 807

	/* begin block 3 */
		// Start line: 811
	/* end block 3 */
	// End Line: 812

void STREAM_DumpMonster(_ObjectTracker *dumpee)

{
  _Instance *instance;
  _Instance *p_Var1;
  Object *pOVar2;
  
  pOVar2 = dumpee->object;
  p_Var1 = *(_Instance **)(theCamera.core.vvNormalWorVecMat[1].t[2] + 4);
  while (instance = p_Var1, instance != (_Instance *)0x0) {
    p_Var1 = instance->next;
    if (pOVar2 == instance->object) {
      INSTANCE_ReallyRemoveInstance
                ((_InstanceList *)theCamera.core.vvNormalWorVecMat[1].t[2],instance,0);
    }
  }
  STREAM_DumpObject(dumpee);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_InList(char *name /*$s1*/, char **nameList /*$a1*/)
 // line 456, offset 0x800588a0
	/* begin block 1 */
		// Start line: 457
		// Start offset: 0x800588A0
		// Variables:
	// 		char **mon; // $s0
	/* end block 1 */
	// End offset: 0x800588F4
	// End Line: 465

	/* begin block 2 */
		// Start line: 940
	/* end block 2 */
	// End Line: 941

int STREAM_InList(char *name,char **nameList)

{
  if (*nameList != (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    strcmpi(name,*nameList);
  }
  return 0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_IsSpecialMonster(char *name /*$a0*/)
 // line 467, offset 0x80058908
	/* begin block 1 */
		// Start line: 468
		// Start offset: 0x80058908
		// Variables:
	// 		static char (*mon[6]); // offset 0x0
	/* end block 1 */
	// End offset: 0x80058908
	// End Line: 468

	/* begin block 2 */
		// Start line: 964
	/* end block 2 */
	// End Line: 965

int STREAM_IsSpecialMonster(char *name)

{
  int iVar1;
  
  iVar1 = STREAM_InList(name,(char **)&SHORT_800ca914);
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpSomeMonsters()
 // line 475, offset 0x8005892c
	/* begin block 1 */
		// Start line: 476
		// Start offset: 0x8005892C
		// Variables:
	// 		struct _ObjectTracker *otr; // $s1
	// 		int i; // $s2
	/* end block 1 */
	// End offset: 0x800589A0
	// End Line: 491

	/* begin block 2 */
		// Start line: 984
	/* end block 2 */
	// End Line: 985

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_DumpSomeMonsters(void)

{
  int iVar1;
  int *piVar2;
  _ObjectTracker *dumpee;
  int iVar3;
  
  iVar3 = 0;
  piVar2 = (int *)(theCamera.core.vvPlaneConsts[3] + 0x10);
  dumpee = (_ObjectTracker *)theCamera.core.vvPlaneConsts[3];
  do {
    if (((*(short *)(piVar2 + 1) == 2) && (*piVar2 != 0)) &&
       (iVar1 = STREAM_IsSpecialMonster((char *)dumpee), iVar1 != 0)) {
      STREAM_DumpMonster(dumpee);
    }
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 9;
    dumpee = dumpee + 1;
  } while (iVar3 < 0x30);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_NoMonsters()
 // line 492, offset 0x800589bc
	/* begin block 1 */
		// Start line: 1037
	/* end block 1 */
	// End Line: 1038

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_NoMonsters(void)

{
  theCamera.positionAccl._0_4_ = theCamera.positionAccl._0_4_ | 0x4000000;
  STREAM_DumpSomeMonsters();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_YesMonsters()
 // line 498, offset 0x800589ec
	/* begin block 1 */
		// Start line: 1051
	/* end block 1 */
	// End Line: 1052

	/* begin block 2 */
		// Start line: 1053
	/* end block 2 */
	// End Line: 1054

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_YesMonsters(void)

{
  theCamera.positionAccl._0_4_ = theCamera.positionAccl._0_4_ & 0xfbffffff;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_IsMonster(char *name /*$a0*/)
 // line 505, offset 0x80058a08
	/* begin block 1 */
		// Start line: 506
		// Start offset: 0x80058A08
		// Variables:
	// 		static char (*monnames[19]); // offset 0x18
	/* end block 1 */
	// End offset: 0x80058A08
	// End Line: 506

	/* begin block 2 */
		// Start line: 1065
	/* end block 2 */
	// End Line: 1066

int STREAM_IsMonster(char *name)

{
  int iVar1;
  
  iVar1 = STREAM_InList(name,(char **)&SHORT_800ca92c);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_TryAndDumpANonResidentObject()
 // line 548, offset 0x80058a2c
	/* begin block 1 */
		// Start line: 549
		// Start offset: 0x80058A2C
		// Variables:
	// 		struct _ObjectTracker *otr; // $s1
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x80058A68
	// End Line: 562

	/* begin block 2 */
		// Start line: 1096
	/* end block 2 */
	// End Line: 1097

/* WARNING: Unknown calling convention yet parameter storage is locked */

int STREAM_TryAndDumpANonResidentObject(void)

{
  int iVar1;
  int iVar2;
  _ObjectTracker *otr;
  
  iVar2 = 0;
  otr = (_ObjectTracker *)theCamera.core.vvPlaneConsts[3];
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
 // line 564, offset 0x80058a7c
	/* begin block 1 */
		// Start line: 565
		// Start offset: 0x80058A7C
		// Variables:
	// 		char string[64]; // stack offset -152
	// 		char vramname[64]; // stack offset -88
	// 		int i; // $s1
	// 		struct _ObjectTracker *otr; // $s0
	/* end block 1 */
	// End offset: 0x80058BF8
	// End Line: 656

	/* begin block 2 */
		// Start line: 1161
	/* end block 2 */
	// End Line: 1162

int InsertGlobalObject(char *name,GameTracker *gameTracker)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  _ObjectTracker *s1;
  char acStack152 [128];
  
  uVar1 = theCamera.positionAccl._0_4_ & 0x4000000;
  if (uVar1 == 0) {
    STREAM_AbortAreaLoad(name);
    return uVar1;
  }
  iVar2 = STREAM_IsSpecialMonster(name);
  iVar3 = -1;
  if (iVar2 == 0) {
    if (((gameTracker->debugFlags2 & 0x8000U) != 0) && (iVar2 = STREAM_IsMonster(name), iVar2 != 0))
    {
      return -1;
    }
    s1 = gameTracker->GlobalObjects;
    iVar3 = 0;
    do {
      if (s1->objectStatus != 0) {
                    /* WARNING: Subroutine does not return */
        strcmpi((char *)s1,name);
      }
      iVar3 = iVar3 + 1;
      s1 = s1 + 1;
    } while (iVar3 < 0x30);
    if (iVar3 == 0x30) {
      s1 = gameTracker->GlobalObjects;
      iVar2 = 0;
      do {
        if (s1->objectStatus == 0) break;
        iVar2 = iVar2 + 1;
        s1 = s1 + 1;
      } while (iVar2 < 0x30);
      if ((iVar2 == 0x30) && (iVar2 = STREAM_TryAndDumpANonResidentObject(), iVar2 == -1)) {
                    /* WARNING: Subroutine does not return */
        DEBUG_FatalError((char *)&fontsObject);
      }
                    /* WARNING: Subroutine does not return */
      sprintf(acStack152,s__kain2_object__s__s_drm_800cf478);
    }
  }
  return iVar3;
}



// decompiled code
// original method signature: 
// struct _ObjectTracker * /*$ra*/ STREAM_GetObjectTracker(char *name /*$a0*/)
 // line 667, offset 0x80058c18
	/* begin block 1 */
		// Start line: 668
		// Start offset: 0x80058C18
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x80058C54
	// End Line: 673

	/* begin block 2 */
		// Start line: 1334
	/* end block 2 */
	// End Line: 1335

_ObjectTracker * STREAM_GetObjectTracker(char *name)

{
  int iVar1;
  _ObjectTracker *p_Var2;
  
  iVar1 = InsertGlobalObject(name,(GameTracker *)(theCamera.core.vvNormalWorVecMat[0].m + 4));
  if (iVar1 == -1) {
    p_Var2 = (_ObjectTracker *)0x0;
  }
  else {
    p_Var2 = (_ObjectTracker *)(theCamera.core.vvPlaneConsts[3] + iVar1 * 0x24);
  }
  return p_Var2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LoadLevelObjects(struct _StreamUnit *stream /*$s1*/)
 // line 675, offset 0x80058c64
	/* begin block 1 */
		// Start line: 676
		// Start offset: 0x80058C64
		// Variables:
	// 		int objlist_pos; // $s0

		/* begin block 1.1 */
			// Start line: 686
			// Start offset: 0x80058CA8
			// Variables:
		// 		char name[20]; // stack offset -48
		/* end block 1.1 */
		// End offset: 0x80058CA8
		// End Line: 688

		/* begin block 1.2 */
			// Start line: 691
			// Start offset: 0x80058CE8
			// Variables:
		// 		struct Level *level; // $s1
		// 		int i; // $s2
		/* end block 1.2 */
		// End offset: 0x80058D6C
		// End Line: 712
	/* end block 1 */
	// End offset: 0x80058D6C
	// End Line: 713

	/* begin block 2 */
		// Start line: 1392
	/* end block 2 */
	// End Line: 1393

void LoadLevelObjects(_StreamUnit *stream)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  Level *pLVar4;
  int iVar5;
  char acStack48 [24];
  
  STREAM_NextLoadAsNormal();
  if (*(char *)stream->level->objectNameList != -1) {
                    /* WARNING: Subroutine does not return */
    strcpy(acStack48,(char *)stream->level->objectNameList);
  }
  pLVar4 = stream->level;
  iVar5 = 0;
  if (0 < pLVar4->numIntros) {
    iVar3 = 0;
    do {
      iVar1 = FindObjectName(pLVar4->introList->name + iVar3);
      if (iVar1 == -1) {
        pcVar2 = pLVar4->introList->name + iVar3;
        *(uint *)(pcVar2 + 0x2c) = *(uint *)(pcVar2 + 0x2c) | 0x4000;
      }
      else {
        pcVar2 = pLVar4->introList->name + iVar3;
        *(uint *)(pcVar2 + 0x2c) = *(uint *)(pcVar2 + 0x2c) & 0xffffbfff;
      }
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 0x4c;
    } while (iVar5 < pLVar4->numIntros);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ STREAM_IsAnInstanceUsingObject(struct Object *object /*$a0*/)
 // line 715, offset 0x80058d88
	/* begin block 1 */
		// Start line: 717
		// Start offset: 0x80058D88
		// Variables:
	// 		struct _Instance *instance; // $v1
	// 		struct _Instance *next; // $v1
	// 		long ret; // $a1
	/* end block 1 */
	// End offset: 0x80058DC0
	// End Line: 733

	/* begin block 2 */
		// Start line: 1483
	/* end block 2 */
	// End Line: 1484

	/* begin block 3 */
		// Start line: 1484
	/* end block 3 */
	// End Line: 1485

long STREAM_IsAnInstanceUsingObject(Object *object)

{
  Object **ppOVar1;
  int iVar2;
  
  iVar2 = *(int *)(theCamera.core.vvNormalWorVecMat[1].t[2] + 4);
  do {
    if (iVar2 == 0) {
      return 0;
    }
    ppOVar1 = (Object **)(iVar2 + 0x1c);
    iVar2 = *(int *)(iVar2 + 8);
  } while (*ppOVar1 != object);
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_StreamLoadObjectAbort(void *loadData /*$a0*/, void *data /*$a1*/, void *data2 /*$a2*/)
 // line 736, offset 0x80058dc8
	/* begin block 1 */
		// Start line: 737
		// Start offset: 0x80058DC8
		// Variables:
	// 		struct _ObjectTracker *objectTracker; // $s0
	/* end block 1 */
	// End offset: 0x80058DE4
	// End Line: 741

	/* begin block 2 */
		// Start line: 1527
	/* end block 2 */
	// End Line: 1528

void STREAM_StreamLoadObjectAbort(char *param_1,int param_2)

{
  if (param_1 != (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    MEMPACK_Free(param_1);
  }
  *(undefined2 *)(param_2 + 0x14) = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpLoadingObjects()
 // line 744, offset 0x80058df8
	/* begin block 1 */
		// Start line: 745
		// Start offset: 0x80058DF8
		// Variables:
	// 		int i; // $s1
	// 		struct _ObjectTracker *tracker; // $s0
	/* end block 1 */
	// End offset: 0x80058E40
	// End Line: 754

	/* begin block 2 */
		// Start line: 1544
	/* end block 2 */
	// End Line: 1545

void STREAM_InList(void)

{
  _ObjectTracker *objectTracker;
  int iVar1;
  
  iVar1 = 0;
  objectTracker = p_Gpffffb53c;
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
 // line 759, offset 0x80058e58
	/* begin block 1 */
		// Start line: 760
		// Start offset: 0x80058E58
		// Variables:
	// 		struct Object *object; // $s0

		/* begin block 1.1 */
			// Start line: 766
			// Start offset: 0x80058E80
			// Variables:
		// 		char dramName[64]; // stack offset -80
		/* end block 1.1 */
		// End offset: 0x80058EAC
		// End Line: 770
	/* end block 1 */
	// End offset: 0x80058F2C
	// End Line: 803

	/* begin block 2 */
		// Start line: 1589
	/* end block 2 */
	// End Line: 1590

void STREAM_DumpObject(_ObjectTracker *objectTracker)

{
  Object *object;
  char acStack80 [64];
  
  object = objectTracker->object;
  if (objectTracker->objectStatus == 1) {
                    /* WARNING: Subroutine does not return */
    sprintf(acStack80,s__kain2_object__s__s_drm_800cf478);
  }
  if (object != (Object *)0x0) {
    if ((object->oflags & 0x2000000U) == 0) {
      if ((_BlockVramEntry *)objectTracker->vramBlock != (_BlockVramEntry *)0x0) {
        VRAM_ClearVramBlock((_BlockVramEntry *)objectTracker->vramBlock);
      }
      if (((object->oflags2 & 0x800000U) != 0) && ((int)object->sfxFileHandle != 0)) {
        aadFreeDynamicSfx((int)object->sfxFileHandle);
      }
      OBTABLE_RemoveObjectEntry(object);
                    /* WARNING: Subroutine does not return */
      MEMPACK_Free((char *)object);
    }
    if (object != (Object *)0x0) {
      return;
    }
  }
  objectTracker->objectStatus = 0;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_IsObjectInAnyUnit(struct _ObjectTracker *tracker /*$s3*/)
 // line 806, offset 0x80058f40
	/* begin block 1 */
		// Start line: 807
		// Start offset: 0x80058F40
		// Variables:
	// 		int d; // $s1

		/* begin block 1.1 */
			// Start line: 814
			// Start offset: 0x80058F8C
			// Variables:
		// 		unsigned char *objlist; // $s0
		/* end block 1.1 */
		// End offset: 0x80058FD0
		// End Line: 824
	/* end block 1 */
	// End offset: 0x80058FE4
	// End Line: 827

	/* begin block 2 */
		// Start line: 1690
	/* end block 2 */
	// End Line: 1691

int STREAM_IsObjectInAnyUnit(_ObjectTracker *tracker)

{
  int iVar1;
  char *s2;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  while (((*(short *)(&fontTracker.font_buffer[0x5c].c + iVar1) != 2 ||
          (iVar1 = *(int *)((int)&fontTracker.font_buffer[0x5d].y + iVar1), iVar1 == 0)) ||
         (s2 = *(char **)(iVar1 + 0x8c), *s2 == -1))) {
    iVar2 = iVar2 + 1;
    iVar1 = iVar2 * 0x40;
    if (0xf < iVar2) {
      return 0;
    }
  }
                    /* WARNING: Subroutine does not return */
  strcmpi((char *)tracker,s2);
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_RemoveAllObjectsNotInUse()
 // line 829, offset 0x80059000
	/* begin block 1 */
		// Start line: 830
		// Start offset: 0x80059000
		// Variables:
	// 		int i; // $s3
	// 		int abort; // $a3
	// 		struct _ObjectTracker *tracker; // $s1
	// 		struct _ObjectTracker *trackerList; // $s4

		/* begin block 1.1 */
			// Start line: 839
			// Start offset: 0x8005904C
			// Variables:
		// 		struct Object *object; // $s2
		/* end block 1.1 */
		// End offset: 0x8005908C
		// End Line: 854

		/* begin block 1.2 */
			// Start line: 862
			// Start offset: 0x800590C8
			// Variables:
		// 		int j; // $a0
		/* end block 1.2 */
		// End offset: 0x80059124
		// End Line: 875

		/* begin block 1.3 */
			// Start line: 883
			// Start offset: 0x8005915C
			// Variables:
		// 		int j; // $t0
		// 		struct _ObjectTracker *otr; // $a3

			/* begin block 1.3.1 */
				// Start line: 887
				// Start offset: 0x80059188
				// Variables:
			// 		int k; // $a0

				/* begin block 1.3.1.1 */
					// Start line: 896
					// Start offset: 0x800591AC
					// Variables:
				// 		int l; // $a1
				/* end block 1.3.1.1 */
				// End offset: 0x800591F8
				// End Line: 903
			/* end block 1.3.1 */
			// End offset: 0x80059210
			// End Line: 905
		/* end block 1.3 */
		// End offset: 0x8005922C
		// End Line: 908
	/* end block 1 */
	// End offset: 0x80059298
	// End Line: 926

	/* begin block 2 */
		// Start line: 1753
	/* end block 2 */
	// End Line: 1754

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_RemoveAllObjectsNotInUse(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  char *pcVar8;
  _ObjectTracker *tracker;
  _ObjectTracker *tracker_00;
  Object *object;
  int iVar9;
  
  tracker_00 = (_ObjectTracker *)theCamera.core.vvPlaneConsts[3];
  iVar9 = 0;
  psVar7 = (short *)(theCamera.core.vvPlaneConsts[3] + 0x14);
  tracker = (_ObjectTracker *)theCamera.core.vvPlaneConsts[3];
  do {
    if ((((*psVar7 == 2) && (object = *(Object **)(psVar7 + -2), (object->oflags & 0x2000000U) == 0)
         ) && (iVar3 = STREAM_IsObjectInAnyUnit(tracker), iVar3 == 0)) &&
       (lVar4 = STREAM_IsAnInstanceUsingObject(object), lVar4 == 0)) {
      *psVar7 = 3;
    }
    iVar9 = iVar9 + 1;
    psVar7 = psVar7 + 0x12;
    tracker = tracker + 1;
  } while (iVar9 < 0x30);
  do {
    bVar2 = true;
    iVar9 = 0;
    psVar7 = (short *)((int)tracker_00 + 0x14);
    lVar4 = (long)tracker_00;
    do {
      if ((*psVar7 == 3) && ('\0' < *(char *)(psVar7 + 4))) {
        if (*(short *)((int)*(char *)(lVar4 + 0x1d) * 0x24 + (int)tracker_00 + 0x14) == 3) {
          if ('\x01' < *(char *)(psVar7 + 4)) {
            STREAM_NoMonsters();
            return;
          }
        }
        else {
          *psVar7 = 2;
          bVar2 = false;
        }
      }
      iVar9 = iVar9 + 1;
      psVar7 = psVar7 + 0x12;
      lVar4 = lVar4 + 0x24;
    } while (iVar9 < 0x30);
  } while (!bVar2);
  iVar9 = 0;
  tracker = tracker_00;
  do {
    if (tracker->objectStatus == 3) {
      iVar3 = 0;
      pcVar8 = (char *)((int)tracker_00 + 0x1c);
      lVar4 = (long)tracker_00;
      do {
        if (((uint)*(ushort *)(pcVar8 + -8) - 1 < 2) || (*(ushort *)(pcVar8 + -8) == 4)) {
          cVar1 = *pcVar8;
          iVar5 = 0;
          iVar6 = lVar4;
          if ('\0' < *pcVar8) {
            do {
              if ((int)*(char *)(iVar6 + 0x1d) == iVar9) {
                *pcVar8 = cVar1 + -1;
                if (iVar5 < (char)(cVar1 + -1)) {
                  do {
                    iVar6 = iVar5 + 1;
                    *(undefined *)(lVar4 + iVar5 + 0x1d) = *(undefined *)(lVar4 + iVar6 + 0x1d);
                    iVar5 = iVar6;
                  } while (iVar6 < *pcVar8);
                }
                break;
              }
              iVar5 = iVar5 + 1;
              cVar1 = *pcVar8;
              iVar6 = lVar4 + iVar5;
            } while (iVar5 < *pcVar8);
          }
        }
        iVar3 = iVar3 + 1;
        pcVar8 = pcVar8 + 0x24;
        lVar4 = lVar4 + 0x24;
      } while (iVar3 < 0x30);
      STREAM_DumpObject(tracker);
    }
    iVar9 = iVar9 + 1;
    tracker = tracker + 1;
    if (0x2f < iVar9) {
      iVar9 = 0;
      pcVar8 = (char *)((int)tracker_00 + 0x1c);
      do {
        if (((*(short *)(pcVar8 + -8) == 1) &&
            (iVar3 = STREAM_IsObjectInAnyUnit(tracker_00), iVar3 == 0)) && (*pcVar8 == '\0')) {
          STREAM_DumpObject(tracker_00);
        }
        iVar9 = iVar9 + 1;
        pcVar8 = pcVar8 + 0x24;
        tracker_00 = tracker_00 + 1;
      } while (iVar9 < 0x30);
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ RemoveAllObjects(struct GameTracker *gameTracker /*$a0*/)
 // line 929, offset 0x800592c0
	/* begin block 1 */
		// Start line: 930
		// Start offset: 0x800592C0
		// Variables:
	// 		int i; // $s1
	// 		struct _ObjectTracker *tracker; // $s0
	/* end block 1 */
	// End offset: 0x80059304
	// End Line: 940

	/* begin block 2 */
		// Start line: 2083
	/* end block 2 */
	// End Line: 2084

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
 // line 945, offset 0x80059318
	/* begin block 1 */
		// Start line: 947
		// Start offset: 0x80059318
		// Variables:
	// 		struct Level *retLevel; // $a2
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x80059364
	// End Line: 961

	/* begin block 2 */
		// Start line: 2123
	/* end block 2 */
	// End Line: 2124

	/* begin block 3 */
		// Start line: 2124
	/* end block 3 */
	// End Line: 2125

Level * STREAM_GetLevelWithID(long id)

{
  FontChar *pFVar1;
  int iVar2;
  
  iVar2 = 0;
  pFVar1 = fontTracker.font_buffer + 0x5c;
  while ((*(short *)&pFVar1->c != 2 || (*(int *)pFVar1 != id))) {
    iVar2 = iVar2 + 1;
    pFVar1 = (FontChar *)&pFVar1[10].c;
    if (0xf < iVar2) {
      return (Level *)0x0;
    }
  }
  return *(Level **)&pFVar1[1].y;
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ STREAM_GetStreamUnitWithID(long id /*$a0*/)
 // line 964, offset 0x80059370
	/* begin block 1 */
		// Start line: 966
		// Start offset: 0x80059370
		// Variables:
	// 		struct _StreamUnit *retUnit; // $a2
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x800593B8
	// End Line: 978

	/* begin block 2 */
		// Start line: 2168
	/* end block 2 */
	// End Line: 2169

	/* begin block 3 */
		// Start line: 2169
	/* end block 3 */
	// End Line: 2170

_StreamUnit * STREAM_GetStreamUnitWithID(long id)

{
  _StreamUnit *p_Var1;
  int iVar2;
  
  iVar2 = 0;
  p_Var1 = (_StreamUnit *)(fontTracker.font_buffer + 0x5c);
  while ((p_Var1->used != 2 || (p_Var1->StreamUnitID != id))) {
    iVar2 = iVar2 + 1;
    p_Var1 = p_Var1 + 1;
    if (0xf < iVar2) {
      return (_StreamUnit *)0x0;
    }
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ STREAM_GetStreamUnitWithName(char *name /*$s4*/)
 // line 981, offset 0x800593c0
	/* begin block 1 */
		// Start line: 982
		// Start offset: 0x800593C0
		// Variables:
	// 		struct _StreamUnit *retUnit; // $s3
	// 		long i; // $s2
	/* end block 1 */
	// End offset: 0x8005942C
	// End Line: 995

	/* begin block 2 */
		// Start line: 2208
	/* end block 2 */
	// End Line: 2209

undefined4 STREAM_GetStreamUnitWithName(char *param_1)

{
  undefined *puVar1;
  char *s2;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = &gp0xffffbe6c;
  s2 = &gp0xffffbe78;
  do {
    if (*(short *)(puVar1 + 4) != 0) {
                    /* WARNING: Subroutine does not return */
      strcmpi(param_1,s2);
    }
    puVar1 = puVar1 + 0x40;
    iVar2 = iVar2 + 1;
    s2 = s2 + 0x40;
  } while (iVar2 < 0x10);
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_CalculateWaterLevel(struct Level *level /*$t3*/)
 // line 998, offset 0x80059450
	/* begin block 1 */
		// Start line: 999
		// Start offset: 0x80059450
		// Variables:
	// 		struct _Terrain *terrain; // $t2
	// 		int i; // $t0
	// 		struct _TFace *tface; // $a3
	// 		long waterZLevel; // $t1
	/* end block 1 */
	// End offset: 0x80059578
	// End Line: 1052

	/* begin block 2 */
		// Start line: 2261
	/* end block 2 */
	// End Line: 2262

void STREAM_CalculateWaterLevel(Level *level)

{
  short sVar1;
  _TVertex *p_Var2;
  ushort *puVar3;
  _TFace *p_Var4;
  int iVar5;
  short sVar6;
  short sVar7;
  _Terrain *p_Var8;
  
  if (level->waterZLevel != 0) {
    return;
  }
  if ((level->unitFlags & 1U) != 0) {
    level->waterZLevel = 0x7fff;
    return;
  }
  p_Var8 = level->terrain;
  iVar5 = p_Var8->numFaces;
  p_Var4 = p_Var8->faceList;
  sVar7 = -0x7fff;
  if (0 < iVar5) {
    puVar3 = &(p_Var4->face).v2;
    sVar6 = -0x7fff;
    do {
      sVar7 = sVar6;
      if ((*(byte *)(puVar3 + 1) & 8) != 0) {
        p_Var2 = p_Var8->vertexList;
        sVar1 = p_Var2[(p_Var4->face).v0].vertex.z;
        if ((((sVar1 == p_Var2[puVar3[-1]].vertex.z) && (sVar1 == p_Var2[*puVar3].vertex.z)) &&
            (sVar7 = sVar1, sVar6 != -0x7fff)) && (sVar7 = sVar6, sVar6 != sVar1)) break;
      }
      iVar5 = iVar5 + -1;
      puVar3 = puVar3 + 6;
      p_Var4 = p_Var4 + 1;
      sVar6 = sVar7;
    } while (0 < iVar5);
  }
  if (sVar7 == -0x7fff) {
    level->waterZLevel = -0x7fff;
    return;
  }
  STREAM_RemoveAllObjectsNotInUse();
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_IsMorphInProgress()
 // line 1057, offset 0x80059580
	/* begin block 1 */
		// Start line: 2395
	/* end block 1 */
	// End Line: 2396

	/* begin block 2 */
		// Start line: 2396
	/* end block 2 */
	// End Line: 2397

/* WARNING: Unknown calling convention yet parameter storage is locked */

int STREAM_IsMorphInProgress(void)

{
  return (uint)(theCamera.core.vvNormalWorVecMat[0].m[2][2] != 1000);
}



// decompiled code
// original method signature: 
// long /*$ra*/ STREAM_GetWaterZLevel(struct Level *level /*$a0*/, struct _Instance *instance /*$a1*/)
 // line 1063, offset 0x80059594
	/* begin block 1 */
		// Start line: 1065
		// Start offset: 0x80059594
		// Variables:
	// 		long waterZLevel; // $a1
	/* end block 1 */
	// End offset: 0x8005960C
	// End Line: 1090

	/* begin block 2 */
		// Start line: 2407
	/* end block 2 */
	// End Line: 2408

	/* begin block 3 */
		// Start line: 2408
	/* end block 3 */
	// End Line: 2409

	/* begin block 4 */
		// Start line: 2410
	/* end block 4 */
	// End Line: 2411

undefined4 STREAM_GetWaterZLevel(int param_1,int param_2)

{
  if ((*(uint *)(param_2 + 0x18) & 0x8000000) == 0) {
    if (((*(uint *)(*(int *)(param_2 + 0x1c) + 0x2c) & 0x2000000) == 0) && (sGpffffb500 != 1000)) {
      return 0xffff8001;
    }
  }
  else {
    if ((*(uint *)(*(int *)(param_2 + 0x1c) + 0x2c) & 0x2000000) != 0) {
      return 0xffff8001;
    }
    if (sGpffffb500 == 1000) {
      return 0xffff8001;
    }
  }
  return *(undefined4 *)(param_1 + 0x38);
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_SetMainFog(struct _StreamUnit *streamUnit /*$a0*/)
 // line 1093, offset 0x80059614
	/* begin block 1 */
		// Start line: 1095
		// Start offset: 0x80059614
		// Variables:
	// 		struct Level *level; // $v1
	/* end block 1 */
	// End offset: 0x80059654
	// End Line: 1110

	/* begin block 2 */
		// Start line: 2467
	/* end block 2 */
	// End Line: 2468

	/* begin block 3 */
		// Start line: 2468
	/* end block 3 */
	// End Line: 2469

	/* begin block 4 */
		// Start line: 2472
	/* end block 4 */
	// End Line: 2473

void STREAM_SetMainFog(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (sGpffffb502 == 0) {
    *(undefined2 *)(param_1 + 0x36) = *(undefined2 *)(iVar1 + 0xa6);
    *(undefined2 *)(param_1 + 0x34) = *(undefined2 *)(iVar1 + 0xa4);
  }
  else {
    *(undefined2 *)(param_1 + 0x36) = *(undefined2 *)(iVar1 + 0x4a);
    *(undefined2 *)(param_1 + 0x34) = *(undefined2 *)(iVar1 + 0x48);
  }
  *(undefined2 *)(param_1 + 0x3a) = *(undefined2 *)(param_1 + 0x36);
  *(undefined2 *)(param_1 + 0x38) = *(undefined2 *)(param_1 + 0x34);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_SetStreamFog(struct _StreamUnit *streamUnit /*$s1*/, short fogNear /*$a1*/, short fogFar /*$a2*/)
 // line 1114, offset 0x80059668
	/* begin block 1 */
		// Start line: 1115
		// Start offset: 0x80059668
	/* end block 1 */
	// End offset: 0x800596D8
	// End Line: 1127

	/* begin block 2 */
		// Start line: 2512
	/* end block 2 */
	// End Line: 2513

void STREAM_RemoveAllObjectsNotInUse(GameTracker *gameTracker)

{
  _StreamUnit *p_Var1;
  short sVar2;
  short sVar3;
  short in_a1;
  short in_a2;
  
  p_Var1 = FindStreamUnitFromLevel(fontTracker.font_buffer[38]._0_4_);
  sVar3 = p_Var1->UnitFogFar;
  if (in_a2 < p_Var1->UnitFogFar) {
    sVar3 = in_a2;
  }
  *(short *)&gameTracker->instancePool = sVar3;
  *(short *)&gameTracker->instanceList = sVar3;
  sVar2 = (short)((int)sVar3 + -2000);
  if ((int)in_a1 < (int)sVar3 + -2000) {
    sVar2 = in_a1;
  }
  *(short *)((int)&gameTracker->instancePool + 2) = sVar2;
  *(short *)((int)&gameTracker->instanceList + 2) = sVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_ConnectStream(struct _StreamUnit *streamUnit /*$s6*/)
 // line 1171, offset 0x800596f8
	/* begin block 1 */
		// Start line: 1172
		// Start offset: 0x800596F8
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
			// Start line: 1196
			// Start offset: 0x80059774
			// Variables:
		// 		struct _StreamUnit *connectStream; // $s0

			/* begin block 1.1.1 */
				// Start line: 1230
				// Start offset: 0x8005988C
				// Variables:
			// 		struct _SVector offset; // stack offset -56
			/* end block 1.1.1 */
			// End offset: 0x8005988C
			// End Line: 1241
		/* end block 1.1 */
		// End offset: 0x80059898
		// End Line: 1250

		/* begin block 1.2 */
			// Start line: 1255
			// Start offset: 0x800598AC
			// Variables:
		// 		long d; // stack offset -44
		// 		struct _StreamUnit *connectStream; // $s5

			/* begin block 1.2.1 */
				// Start line: 1270
				// Start offset: 0x800598FC
				// Variables:
			// 		long hookedUp; // $s0

				/* begin block 1.2.1.1 */
					// Start line: 1310
					// Start offset: 0x80059A1C
					// Variables:
				// 		struct _SVector offset; // stack offset -56
				/* end block 1.2.1.1 */
				// End offset: 0x80059A1C
				// End Line: 1321
			/* end block 1.2.1 */
			// End offset: 0x80059A28
			// End Line: 1330
		/* end block 1.2 */
		// End offset: 0x80059A58
		// End Line: 1330
	/* end block 1 */
	// End offset: 0x80059AD4
	// End Line: 1344

	/* begin block 2 */
		// Start line: 2636
	/* end block 2 */
	// End Line: 2637

void STREAM_ConnectStream(_StreamUnit *streamUnit)

{
  int *piVar1;
  _StreamUnit *p_Var2;
  int **ppiVar3;
  char acStack72 [24];
  _StreamUnit *local_30;
  int local_2c;
  
  WARPGATE_UpdateAddToArray(streamUnit);
  if (theCamera.rotationVel._4_4_ != streamUnit->StreamUnitID) {
    local_30 = STREAM_GetStreamUnitWithID(theCamera.rotationVel._4_4_);
    piVar1 = (int *)streamUnit->level->terrain->StreamUnits;
    if (0 < *piVar1) {
                    /* WARNING: Subroutine does not return */
      strcpy(acStack72,(char *)(piVar1 + 1));
    }
    p_Var2 = (_StreamUnit *)(fontTracker.font_buffer + 0x5c);
    local_2c = 0;
    ppiVar3 = (int **)&fontTracker.font_buffer[0x5d].y;
    do {
      if (((*(short *)(ppiVar3 + -1) == 2) && (p_Var2 != streamUnit)) &&
         (0 < **(int **)(**ppiVar3 + 0x30))) {
                    /* WARNING: Subroutine does not return */
        strcpy(acStack72,(char *)(*(int **)(**ppiVar3 + 0x30) + 1));
      }
      ppiVar3 = ppiVar3 + 0x10;
      p_Var2 = p_Var2 + 1;
      local_2c = local_2c + 1;
    } while (local_2c < 0x10);
    if (0 < streamUnit->level->numIntros) {
                    /* WARNING: Subroutine does not return */
      strcmpi((char *)streamUnit->level->introList,s_raziel_800cf4b4);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_StreamLoadLevelAbort(void *loadData /*$a0*/, void *data /*$a1*/, void *data2 /*$a2*/)
 // line 1346, offset 0x80059b04
	/* begin block 1 */
		// Start line: 1347
		// Start offset: 0x80059B04
		// Variables:
	// 		struct _StreamUnit *streamUnit; // $s0
	/* end block 1 */
	// End offset: 0x80059B20
	// End Line: 1351

	/* begin block 2 */
		// Start line: 3223
	/* end block 2 */
	// End Line: 3224

void STREAM_StreamLoadLevelAbort(void *loadData,void *data,void *data2)

{
  if (loadData != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
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
 // line 1359, offset 0x80059b3c
	/* begin block 1 */
		// Start line: 1360
		// Start offset: 0x80059B3C
		// Variables:
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x80059B74
	// End Line: 1377

	/* begin block 2 */
		// Start line: 3250
	/* end block 2 */
	// End Line: 3251

void STREAM_DoObjectLoadAndDump(_StreamUnit *streamUnit)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = -0x7ff2e6e0;
  do {
    iVar2 = iVar2 + 1;
    if (*(short *)(iVar1 + 4) == 1) {
      return;
    }
    iVar1 = iVar1 + 0x40;
  } while (iVar2 < 0x10);
  STREAM_RemoveAllObjectsNotInUse();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_FinishLoad(struct _StreamUnit *streamUnit /*$s1*/)
 // line 1380, offset 0x80059b84
	/* begin block 1 */
		// Start line: 1381
		// Start offset: 0x80059B84
		// Variables:
	// 		struct Level *level; // $s0
	// 		char sfxName[80]; // stack offset -96
	/* end block 1 */
	// End offset: 0x80059C98
	// End Line: 1449

	/* begin block 2 */
		// Start line: 3295
	/* end block 2 */
	// End Line: 3296

void STREAM_FinishLoad(_StreamUnit *param_1)

{
  long lVar1;
  int iVar2;
  _MultiSignal *p_Var3;
  Level *level;
  char acStack96 [80];
  
  STREAM_FillOutFileNames(param_1->baseAreaName,(char *)0x0,(char *)0x0,acStack96);
  level = param_1->level;
  level->morphLastStep = -1;
  param_1->sfxFileHandle = 0;
  lVar1 = LOAD_DoesFileExist(acStack96);
  if (lVar1 != 0) {
    iVar2 = aadLoadDynamicSfx(param_1->baseAreaName,param_1->StreamUnitID,1);
    param_1->sfxFileHandle = (short)iVar2;
  }
  LoadLevelObjects(param_1);
  param_1->FogColor = *(long *)&level->backColorR;
  level->fogFar = param_1->TargetFogFar;
  level->fogNear = param_1->TargetFogNear;
  LIGHT_CalcDQPTable(level);
  STREAM_CalculateWaterLevel(level);
  if (sGpffffb502 == 1) {
    MORPH_UpdateNormals(level);
  }
  STREAM_ConnectStream(param_1);
  param_1->used = 2;
  STREAM_DoObjectLoadAndDump(param_1);
  EVENT_LoadEventsForLevel(param_1->StreamUnitID,level);
  PLANAPI_InitPlanMkrList(param_1);
  p_Var3 = level->startUnitLoadedSignal;
  if (p_Var3 != (_MultiSignal *)0x0) {
    p_Var3->flags = p_Var3->flags | 1;
    SIGNAL_HandleSignal(p_Gpffffb524,level->startUnitLoadedSignal->signalList,0);
    EVENT_AddSignalToReset(level->startUnitLoadedSignal);
  }
  SAVE_IntroForStreamID(param_1);
  SAVE_UpdateLevelWithSave(param_1);
  EVENT_AddStreamToInstanceList(param_1);
  WARPGATE_FixUnit(param_1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_LoadLevelReturn(void *loadData /*$s0*/, void *data /*$a1*/, void *data2 /*$s1*/)
 // line 1463, offset 0x80059cd0
	/* begin block 1 */
		// Start line: 1464
		// Start offset: 0x80059CD0
	/* end block 1 */
	// End offset: 0x80059CD0
	// End Line: 1464

	/* begin block 2 */
		// Start line: 3475
	/* end block 2 */
	// End Line: 3476

void STREAM_LoadLevelReturn(int param_1,undefined4 param_2,_StreamUnit *param_3)

{
  GetRCnt(0xf2000000);
  param_3->StreamUnitID = *(long *)(param_1 + 0xf8);
  uGpffffb670 = *(undefined4 *)(param_1 + 0xf8);
  iGpffffb520 = param_1;
  STREAM_SetMainFog((int)param_3);
  STREAM_FinishLoad(param_3);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_StreamLoadLevelReturn(void *loadData /*$s0*/, void *data /*$a1*/, void *data2 /*$s1*/)
 // line 1498, offset 0x80059d30
	/* begin block 1 */
		// Start line: 1499
		// Start offset: 0x80059D30
		// Variables:
	// 		struct Level *level; // $s0
	// 		struct _StreamUnit *streamUnit; // $s1
	/* end block 1 */
	// End offset: 0x80059E04
	// End Line: 1596

	/* begin block 2 */
		// Start line: 3546
	/* end block 2 */
	// End Line: 3547

void STREAM_StreamLoadLevelReturn(int param_1,undefined4 param_2,GameTracker *param_3)

{
  short sVar1;
  char *address;
  
  GetRCnt(0xf2000000);
  sVar1 = *(short *)&(param_3->gameData).asmData.dispPage;
  (param_3->gameData).asmData.drawBackFaces = *(long *)(param_1 + 0xf8);
  if (sVar1 == 3) {
    address = *(char **)&(param_3->gameData).asmData.MorphTime;
    *(undefined2 *)&(param_3->gameData).asmData.dispPage = 0;
                    /* WARNING: Subroutine does not return */
    *(undefined2 *)((int)&(param_3->gameData).asmData.dispPage + 2) = 0;
    MEMPACK_Free(address);
  }
  STREAM_RemoveAllObjectsNotInUse(param_3);
  STREAM_FinishLoad((_StreamUnit *)param_3);
  if ((iGpffffb524 != 0) && (*(int *)(param_1 + 0xf8) == *(int *)(iGpffffb524 + 0x38))) {
                    /* WARNING: Subroutine does not return */
    strcpy(&gp0xffffb654,*(char **)(param_1 + 0x98));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_UpdateLevelPointer(struct Level *oldLevel /*$a0*/, struct Level *newLevel /*$a1*/, long sizeOfLevel /*$a2*/)
 // line 1623, offset 0x80059e18
	/* begin block 1 */
		// Start line: 1624
		// Start offset: 0x80059E18
		// Variables:
	// 		long i; // $t0
	// 		long offset; // $t1
	// 		struct GameTracker *gameTracker; // $v0

		/* begin block 1.1 */
			// Start line: 1652
			// Start offset: 0x80059E7C
			// Variables:
		// 		struct _Instance *instance; // $a3
		/* end block 1.1 */
		// End offset: 0x8005A00C
		// End Line: 1692
	/* end block 1 */
	// End offset: 0x8005A0F0
	// End Line: 1714

	/* begin block 2 */
		// Start line: 3246
	/* end block 2 */
	// End Line: 3247

void STREAM_UpdateLevelPointer(Level *oldLevel,Level *newLevel,long sizeOfLevel)

{
  ulong uVar1;
  int iVar2;
  Level *pLVar3;
  undefined2 *puVar4;
  int iVar5;
  Level *pLVar6;
  Level *pLVar7;
  
  pLVar7 = (Level *)((int)newLevel - (int)oldLevel);
  iVar5 = 0;
  iVar2 = -0x7ff2e6e0;
  while ((*(short *)(iVar2 + 4) != 2 || (*(Level **)(iVar2 + 8) != oldLevel))) {
    iVar5 = iVar5 + 1;
    iVar2 = iVar2 + 0x40;
    if (0xf < iVar5) {
LAB_80059e68:
      if (theCamera.core.vvNormalWorVecMat[1]._16_4_ == oldLevel) {
        theCamera.core.vvNormalWorVecMat[1]._16_4_ = newLevel;
      }
      iVar2 = *(int *)(theCamera.core.vvNormalWorVecMat[1].t[2] + 4);
      if (iVar2 != 0) {
        pLVar6 = (Level *)((int)&oldLevel->terrain + sizeOfLevel);
        do {
          pLVar3 = *(Level **)(iVar2 + 0x20);
          if ((oldLevel <= pLVar3) && (pLVar3 <= pLVar6)) {
            iVar5 = 0;
            if (pLVar3 != (Level *)0x0) {
              iVar5 = (int)pLVar3 + (int)pLVar7;
            }
            *(int *)(iVar2 + 0x20) = iVar5;
          }
          pLVar3 = *(Level **)(iVar2 + 0x28);
          if ((oldLevel <= pLVar3) && (pLVar3 <= pLVar6)) {
            iVar5 = 0;
            if (pLVar3 != (Level *)0x0) {
              iVar5 = (int)pLVar3 + (int)pLVar7;
            }
            *(int *)(iVar2 + 0x28) = iVar5;
          }
          pLVar3 = *(Level **)(iVar2 + 0xb4);
          if ((oldLevel <= pLVar3) && (pLVar3 <= pLVar6)) {
            iVar5 = 0;
            if (pLVar3 != (Level *)0x0) {
              iVar5 = (int)pLVar3 + (int)pLVar7;
            }
            *(int *)(iVar2 + 0xb4) = iVar5;
          }
          pLVar3 = *(Level **)(iVar2 + 0x10c);
          if ((oldLevel <= pLVar3) && (pLVar3 <= pLVar6)) {
            iVar5 = 0;
            if (pLVar3 != (Level *)0x0) {
              iVar5 = (int)pLVar3 + (int)pLVar7;
            }
            *(int *)(iVar2 + 0x10c) = iVar5;
          }
          pLVar3 = *(Level **)(iVar2 + 0x114);
          if ((oldLevel <= pLVar3) && (pLVar3 <= pLVar6)) {
            iVar5 = 0;
            if (pLVar3 != (Level *)0x0) {
              iVar5 = (int)pLVar3 + (int)pLVar7;
            }
            *(int *)(iVar2 + 0x114) = iVar5;
          }
          pLVar3 = *(Level **)(iVar2 + 0xb8);
          if ((oldLevel <= pLVar3) && (pLVar3 <= pLVar6)) {
            iVar5 = 0;
            if (pLVar3 != (Level *)0x0) {
              iVar5 = (int)pLVar3 + (int)pLVar7;
            }
            *(int *)(iVar2 + 0xb8) = iVar5;
          }
          pLVar3 = *(Level **)(iVar2 + 0xbc);
          if ((oldLevel <= pLVar3) && (pLVar3 <= pLVar6)) {
            if (pLVar3 == (Level *)0x0) {
              STREAM_StreamLoadLevelAbort(oldLevel,newLevel,(void *)sizeOfLevel);
              return;
            }
            *(int *)(iVar2 + 0xbc) = (int)pLVar3 + (int)pLVar7;
          }
          pLVar3 = *(Level **)(iVar2 + 0xcc);
          if ((oldLevel <= pLVar3) && (pLVar3 <= pLVar6)) {
            iVar5 = 0;
            if (pLVar3 != (Level *)0x0) {
              iVar5 = (int)pLVar3 + (int)pLVar7;
            }
            *(int *)(iVar2 + 0xcc) = iVar5;
          }
          iVar2 = *(int *)(iVar2 + 8);
        } while (iVar2 != 0);
      }
      uVar1 = ULONG_800d02b4;
      if (((oldLevel <= ULONG_800d02b4) &&
          (ULONG_800d02b4 <= (uint)((int)&oldLevel->terrain + sizeOfLevel))) &&
         (uVar1 = 0, ULONG_800d02b4 != 0)) {
        uVar1 = (int)&pLVar7->terrain + ULONG_800d02b4;
      }
      ULONG_800d02b4 = uVar1;
      uVar1 = ULONG_800d02b8;
      if (((oldLevel <= ULONG_800d02b8) &&
          (ULONG_800d02b8 <= (uint)((int)&oldLevel->terrain + sizeOfLevel))) &&
         (uVar1 = 0, ULONG_800d02b8 != 0)) {
        uVar1 = (int)&pLVar7->terrain + ULONG_800d02b8;
      }
      ULONG_800d02b8 = uVar1;
      iVar2 = 0;
      if (-1 < GameCheat_800d0108.cheatKeys._0_2_) {
        pLVar6 = (Level *)((int)&oldLevel->terrain + sizeOfLevel);
        puVar4 = &theCamera;
        do {
          pLVar3 = *(Level **)(puVar4 + 0x182);
          if ((oldLevel <= pLVar3) && (pLVar3 <= pLVar6)) {
            iVar5 = 0;
            if (pLVar3 != (Level *)0x0) {
              iVar5 = (int)pLVar3 + (int)pLVar7;
            }
            *(int *)(puVar4 + 0x182) = iVar5;
          }
          pLVar3 = *(Level **)(puVar4 + 0x184);
          if (pLVar3 < oldLevel) {
            STREAM_StreamLoadLevelAbort(oldLevel,newLevel,(void *)sizeOfLevel);
            return;
          }
          if (pLVar6 < pLVar3) {
            STREAM_StreamLoadLevelAbort(oldLevel,newLevel,(void *)sizeOfLevel);
            return;
          }
          iVar5 = 0;
          if (pLVar3 != (Level *)0x0) {
            iVar5 = (int)pLVar3 + (int)pLVar7;
          }
          *(int *)(puVar4 + 0x184) = iVar5;
          iVar2 = iVar2 + 1;
          puVar4 = puVar4 + 0x38;
        } while (iVar2 <= GameCheat_800d0108.cheatKeys._0_2_);
      }
      EVENT_UpdateResetSignalArrayAndWaterMovement(oldLevel,newLevel,sizeOfLevel);
      return;
    }
  }
  *(Level **)(iVar2 + 8) = newLevel;
  goto LAB_80059e68;
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ STREAM_WhichUnitPointerIsIn(void *pointer /*$s3*/)
 // line 1719, offset 0x8005a108
	/* begin block 1 */
		// Start line: 1720
		// Start offset: 0x8005A108
		// Variables:
	// 		int i; // $s2
	// 		int size; // $v1
	// 		struct Level *level; // $s0
	/* end block 1 */
	// End offset: 0x8005A194
	// End Line: 1740

	/* begin block 2 */
		// Start line: 3981
	/* end block 2 */
	// End Line: 3982

_StreamUnit * STREAM_WhichUnitPointerIsIn(void *pointer)

{
  ulong uVar1;
  Level *address;
  _StreamUnit *p_Var2;
  int iVar3;
  
  iVar3 = 0;
  p_Var2 = (_StreamUnit *)(fontTracker.font_buffer + 0x5c);
  do {
    if ((p_Var2->used == 2) && (address = p_Var2->level, address != (Level *)0x0)) {
      uVar1 = MEMPACK_Size((char *)address);
      if ((address <= pointer) && (pointer <= (void *)((int)&address->terrain + uVar1))) {
        return p_Var2;
      }
    }
    iVar3 = iVar3 + 1;
    p_Var2 = p_Var2 + 1;
    if (0xf < iVar3) {
      return (_StreamUnit *)0x0;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_UpdateObjectPointer(struct Object *oldObject /*$s2*/, struct Object *newObject /*$s3*/, long sizeOfObject /*$s4*/)
 // line 1742, offset 0x8005a1b4
	/* begin block 1 */
		// Start line: 1743
		// Start offset: 0x8005A1B4
		// Variables:
	// 		long i; // $a3
	// 		long d; // $a1
	// 		struct GameTracker *gameTracker; // $s0
	// 		long offset; // $s1
	// 		struct _ObjectTracker *otr; // $t0

		/* begin block 1.1 */
			// Start line: 1763
			// Start offset: 0x8005A208
			// Variables:
		// 		int j; // $a1
		// 		struct Object *object; // $a2
		/* end block 1.1 */
		// End offset: 0x8005A294
		// End Line: 1773

		/* begin block 1.2 */
			// Start line: 1791
			// Start offset: 0x8005A2F0
			// Variables:
		// 		struct _Instance *instance; // $s0
		/* end block 1.2 */
		// End offset: 0x8005A408
		// End Line: 1820
	/* end block 1 */
	// End offset: 0x8005A434
	// End Line: 1828

	/* begin block 2 */
		// Start line: 4049
	/* end block 2 */
	// End Line: 4050

void STREAM_UpdateObjectPointer(Object *oldObject,Object *newObject,long sizeOfObject)

{
  _ObjectTracker *p_Var1;
  _ObjectTracker *p_Var2;
  Object *pOVar3;
  int iVar4;
  void *pvVar5;
  Object **ppOVar6;
  _HModel *p_Var7;
  int iVar8;
  Object *pOVar9;
  int iVar10;
  int iVar11;
  int iVar12;
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
        iVar12 = *(int *)((int)p_Var2->objectsUsing[0] * 0x24 + theCamera.core.vvPlaneConsts[3] +
                         0x10);
        if ((iVar12 != 0) && (iVar11 = 0, 0 < *(short *)(iVar12 + 10))) {
          do {
            ppOVar6 = (Object **)(iVar11 * 4 + *(int *)(iVar12 + 0x10));
            pOVar9 = *ppOVar6;
            if ((oldObject <= pOVar9) &&
               (pOVar9 <= (Object *)((int)&oldObject->oflags + sizeOfObject))) {
              pOVar3 = (Object *)0x0;
              if (pOVar9 != (Object *)0x0) {
                pOVar3 = (Object *)((int)pOVar9 + (int)offset);
              }
              *ppOVar6 = pOVar3;
            }
            iVar11 = iVar11 + 1;
          } while (iVar11 < *(short *)(iVar12 + 10));
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
    instance = *(_Instance **)(theCamera.core.vvNormalWorVecMat[1].t[2] + 4);
    while (instance != (_Instance *)0x0) {
      if (instance->object == oldObject) {
        instance->object = newObject;
        if ((instance->hModelList != (_HModel *)0x0) && (iVar13 = 0, 0 < newObject->numModels)) {
          iVar12 = 0;
          do {
            p_Var7 = instance->hModelList;
            iVar11 = 0;
            if (0 < *(int *)((int)&p_Var7->numHPrims + iVar12)) {
              do {
                iVar4 = iVar11 * 8 + *(int *)((int)&p_Var7->hPrimList + iVar12);
                iVar10 = *(int *)(iVar4 + 4);
                iVar8 = 0;
                if (iVar10 != 0) {
                  iVar8 = (int)&offset->oflags + iVar10;
                }
                *(int *)(iVar4 + 4) = iVar8;
                p_Var7 = instance->hModelList;
                iVar11 = iVar11 + 1;
              } while (iVar11 < p_Var7[iVar13].numHPrims);
            }
            iVar13 = iVar13 + 1;
            iVar12 = iVar12 + 8;
          } while (iVar13 < instance->object->numModels);
        }
        OBTABLE_RelocateInstanceObject(instance,(long)offset);
      }
      pOVar9 = (Object *)instance->data;
      if ((oldObject <= pOVar9) && (pOVar9 <= (Object *)((int)&oldObject->oflags + sizeOfObject))) {
        pvVar5 = (void *)0x0;
        if (pOVar9 != (Object *)0x0) {
          pvVar5 = (void *)((int)pOVar9 + (int)offset);
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
 // line 1830, offset 0x8005a454
	/* begin block 1 */
		// Start line: 1832
		// Start offset: 0x8005A454
		// Variables:
	// 		struct _Instance *instance; // $v1
	/* end block 1 */
	// End offset: 0x8005A490
	// End Line: 1845

	/* begin block 2 */
		// Start line: 4247
	/* end block 2 */
	// End Line: 4248

	/* begin block 3 */
		// Start line: 4248
	/* end block 3 */
	// End Line: 4249

void STREAM_UpdateInstanceCollisionInfo(_HModel *oldHModel,_HModel *newHModel)

{
  int iVar1;
  
  iVar1 = *(int *)(theCamera.core.vvNormalWorVecMat[1].t[2] + 4);
  while (iVar1 != 0) {
    if (*(_HModel **)(iVar1 + 0xe8) == oldHModel) {
      *(_HModel **)(iVar1 + 0xe8) = newHModel;
    }
    iVar1 = *(int *)(iVar1 + 8);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_LoadMainVram(struct GameTracker *gameTracker /*$a0*/, char *baseAreaName /*$a1*/, struct _StreamUnit *streamUnit /*$a2*/)
 // line 1885, offset 0x8005a498
	/* begin block 1 */
		// Start line: 1886
		// Start offset: 0x8005A498
		// Variables:
	// 		char dramName[80]; // stack offset -176
	// 		char vramName[80]; // stack offset -96
	// 		struct VramBuffer *vramBuffer; // $v0
	// 		struct Level *level; // $s0
	/* end block 1 */
	// End offset: 0x8005A498
	// End Line: 1886

	/* begin block 2 */
		// Start line: 3770
	/* end block 2 */
	// End Line: 3771

void STREAM_LoadMainVram(GameTracker *gameTracker,char *baseAreaName,_StreamUnit *streamUnit)

{
  Level *pLVar1;
  char acStack176 [80];
  char acStack96 [80];
  
  pLVar1 = streamUnit->level;
  STREAM_FillOutFileNames(gameTracker->baseAreaName,acStack176,acStack96,(char *)0x0);
                    /* WARNING: Subroutine does not return */
  MEMPACK_Malloc((int)(pLVar1->vramSize).w * 2 + 0x14,'#');
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_MoveIntoNewStreamUnit()
 // line 1933, offset 0x8005a540
	/* begin block 1 */
		// Start line: 4470
	/* end block 1 */
	// End Line: 4471

void STREAM_MoveIntoNewStreamUnit(void)

{
  p_Gpffffb524->cachedTFace = -1;
  p_Gpffffb524->cachedTFaceLevel = (void *)0x0;
  p_Gpffffb524->currentStreamUnitID = lGpffffb698;
  INSTANCE_UpdateFamilyStreamUnitID(p_Gpffffb524);
  GAMELOOP_StreamLevelLoadAndInit(&gp0xffffb678,(GameTracker *)&gp0xffffb4f8);
  uGpffffb674 = 0;
  if (sGpffffb676 != -1) {
    SndPlayVolPan(0x184,0x7f,0x40,0);
    iGpffff9748 = (int)sGpffffb676;
  }
  return;
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ STREAM_LoadLevel(char *baseAreaName /*$s3*/, struct StreamUnitPortal *streamPortal /*$s4*/, int loadnext /*$a2*/)
 // line 1953, offset 0x8005a5d4
	/* begin block 1 */
		// Start line: 1954
		// Start offset: 0x8005A5D4
		// Variables:
	// 		int i; // $s2
	// 		long streamID; // $s5
	// 		struct _StreamUnit *streamUnit; // $s1

		/* begin block 1.1 */
			// Start line: 1995
			// Start offset: 0x8005A664
		/* end block 1.1 */
		// End offset: 0x8005A664
		// End Line: 1998

		/* begin block 1.2 */
			// Start line: 2007
			// Start offset: 0x8005A698
			// Variables:
		// 		struct Level *level; // $s0
		/* end block 1.2 */
		// End offset: 0x8005A6C4
		// End Line: 2017

		/* begin block 1.3 */
			// Start line: 2079
			// Start offset: 0x8005A71C
			// Variables:
		// 		char dramName[80]; // stack offset -112
		/* end block 1.3 */
		// End offset: 0x8005A7C4
		// End Line: 2136
	/* end block 1 */
	// End offset: 0x8005A7D0
	// End Line: 2139

	/* begin block 2 */
		// Start line: 4512
	/* end block 2 */
	// End Line: 4513

_StreamUnit * STREAM_LoadLevel(char *baseAreaName,StreamUnitPortal *streamPortal,int loadnext)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char acStack112 [80];
  
  iVar3 = 0;
  iVar1 = 0;
  do {
    iVar2 = iVar1;
    if (*(short *)(&fontTracker.font_buffer[0x5c].c + iVar2) != 0) {
                    /* WARNING: Subroutine does not return */
      strcmpi((char *)((int)&fontTracker.font_buffer[0x5e].x + iVar2),baseAreaName);
    }
    iVar3 = iVar3 + 1;
    iVar1 = iVar3 * 0x40;
  } while (iVar3 < 0x10);
  if (iVar3 == 0x10) {
    iVar3 = 0;
    iVar1 = 0;
    do {
      iVar2 = iVar1;
      iVar3 = iVar3 + 1;
      if (*(short *)(&fontTracker.font_buffer[0x5c].c + iVar2) == 0) {
        STREAM_FillOutFileNames(baseAreaName,acStack112,(char *)0x0,(char *)0x0);
                    /* WARNING: Subroutine does not return */
        *(undefined2 *)(&fontTracker.font_buffer[0x5c].c + iVar2) = 1;
        strcpy((char *)((int)&fontTracker.font_buffer[0x5e].x + iVar2),baseAreaName);
      }
      iVar1 = iVar3 * 0x40;
    } while (iVar3 < 0x10);
  }
  return (_StreamUnit *)((int)&fontTracker.font_buffer[0x5c].x + iVar2);
}



// decompiled code
// original method signature: 
// void /*$ra*/ RemoveIntroducedLights(struct Level *level /*$s2*/)
 // line 2144, offset 0x8005a7f8
	/* begin block 1 */
		// Start line: 2145
		// Start offset: 0x8005A7F8
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8005A8C4
	// End Line: 2166

	/* begin block 2 */
		// Start line: 5067
	/* end block 2 */
	// End Line: 5068

void RemoveIntroducedLights(Level *level)

{
  NodeType *node;
  int iVar1;
  int iVar2;
  
  LIGHT_Restore(theCamera.newFocusInstanceRot._4_4_);
  (theCamera.newFocusInstanceRot._4_4_)->numSavedColors = 0;
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
 // line 2168, offset 0x8005a8dc
	/* begin block 1 */
		// Start line: 2169
		// Start offset: 0x8005A8DC
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		struct _Instance *next; // $s1
	/* end block 1 */
	// End offset: 0x8005A968
	// End Line: 2197

	/* begin block 2 */
		// Start line: 5126
	/* end block 2 */
	// End Line: 5127

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
 // line 2199, offset 0x8005a988
	/* begin block 1 */
		// Start line: 2201
		// Start offset: 0x8005A988
		// Variables:
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x8005A9CC
	// End Line: 2217

	/* begin block 2 */
		// Start line: 5191
	/* end block 2 */
	// End Line: 5192

	/* begin block 3 */
		// Start line: 5192
	/* end block 3 */
	// End Line: 5193

	/* begin block 4 */
		// Start line: 5195
	/* end block 4 */
	// End Line: 5196

void STREAM_MarkUnitNeeded(long streamID)

{
  FontChar *pFVar1;
  int iVar2;
  
  iVar2 = 0;
  pFVar1 = fontTracker.font_buffer + 0x5c;
  while ((*(short *)&pFVar1->c == 0 || (streamID != *(int *)pFVar1))) {
    iVar2 = iVar2 + 1;
    pFVar1 = (FontChar *)&pFVar1[10].c;
    if (0xf < iVar2) {
      return;
    }
  }
  *(undefined4 *)&pFVar1[5].y = theCamera.focusOffset._2_4_;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpUnit(struct _StreamUnit *streamUnit /*$s2*/, long doSave /*$s3*/)
 // line 2219, offset 0x8005a9d4
	/* begin block 1 */
		// Start line: 2220
		// Start offset: 0x8005A9D4
		// Variables:
	// 		int i; // $s0
	// 		int j; // $a0
	// 		int numportals; // $a1

		/* begin block 1.1 */
			// Start line: 2249
			// Start offset: 0x8005AA88
			// Variables:
		// 		char dramName[80]; // stack offset -104
		/* end block 1.1 */
		// End offset: 0x8005AAB4
		// End Line: 2260

		/* begin block 1.2 */
			// Start line: 2277
			// Start offset: 0x8005AAF0
			// Variables:
		// 		struct _SFXMkr *sfxMkr; // $a1
		/* end block 1.2 */
		// End offset: 0x8005AAF0
		// End Line: 2277
	/* end block 1 */
	// End offset: 0x8005AB9C
	// End Line: 2309

	/* begin block 2 */
		// Start line: 5240
	/* end block 2 */
	// End Line: 5241

void STREAM_DumpUnit(_StreamUnit *streamUnit,long doSave)

{
  int *piVar1;
  long lVar2;
  _StreamUnit **pp_Var3;
  Level *pLVar4;
  int iVar5;
  int iVar6;
  uchar **ppuVar7;
  int iVar8;
  int iVar9;
  char acStack104 [80];
  
  iVar9 = 0;
  iVar8 = -0x7ff2e6e0;
  do {
    if (*(short *)(iVar8 + 4) == 2) {
      piVar1 = *(int **)(**(int **)(iVar8 + 8) + 0x30);
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
    iVar8 = iVar8 + 0x40;
  } while (iVar9 < 0x10);
  if ((streamUnit->used != 1) && (streamUnit->used != 3)) {
    lVar2 = WARPGATE_IsUnitWarpRoom(streamUnit);
    if (lVar2 != 0) {
      WARPGATE_RemoveFromArray(streamUnit);
    }
    EVENT_RemoveStreamToInstanceList(streamUnit);
    pLVar4 = streamUnit->level;
    iVar8 = 0;
    if (0 < pLVar4->NumberOfSFXMarkers) {
      iVar9 = 0;
      do {
        ppuVar7 = (uchar **)((int)&pLVar4->SFXMarkerList->soundData + iVar9);
        SOUND_EndInstanceSounds(*ppuVar7,(SoundInstance *)(ppuVar7 + 2));
        pLVar4 = streamUnit->level;
        iVar8 = iVar8 + 1;
        iVar9 = iVar9 + 0x24;
      } while (iVar8 < pLVar4->NumberOfSFXMarkers);
    }
    if ((int)streamUnit->sfxFileHandle != 0) {
      aadFreeDynamicSfx((int)streamUnit->sfxFileHandle);
    }
    PLANAPI_GetFlags(streamUnit->StreamUnitID);
    STREAM_RemoveInstancesWithIDInInstanceList
              ((_InstanceList *)theCamera.core.vvNormalWorVecMat[1].t[2],streamUnit->StreamUnitID,
               streamUnit->level);
    if (doSave != 0) {
      EVENT_SaveEventsFromLevel(streamUnit->StreamUnitID,streamUnit->level);
      SAVE_CreatedSavedLevel(streamUnit->StreamUnitID,streamUnit->level);
    }
                    /* WARNING: Subroutine does not return */
    MEMPACK_Free((char *)streamUnit->level);
  }
  STREAM_FillOutFileNames(streamUnit->baseAreaName,acStack104,(char *)0x0,(char *)0x0);
  LOAD_AbortFileLoad(acStack104,STREAM_StreamLoadLevelAbort);
  streamUnit->used = 0;
  streamUnit->flags = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpAllUnitsNotNeeded()
 // line 2311, offset 0x8005abb8
	/* begin block 1 */
		// Start line: 2312
		// Start offset: 0x8005ABB8
		// Variables:
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x8005AC0C
	// End Line: 2324

	/* begin block 2 */
		// Start line: 5445
	/* end block 2 */
	// End Line: 5446

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_DumpAllUnitsNotNeeded(void)

{
  _StreamUnit *streamUnit;
  int iVar1;
  
  iVar1 = 0;
  streamUnit = (_StreamUnit *)(fontTracker.font_buffer + 0x5c);
  do {
    if ((streamUnit->used != 0) && (streamUnit->FrameCount != theCamera.focusOffset._2_4_)) {
      STREAM_DumpUnit(streamUnit,1);
    }
    iVar1 = iVar1 + 1;
    streamUnit = streamUnit + 1;
  } while (iVar1 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpAllLevels(long IDNoRemove /*$s2*/, int DoSave /*$s3*/)
 // line 2326, offset 0x8005ac20
	/* begin block 1 */
		// Start line: 2327
		// Start offset: 0x8005AC20
		// Variables:
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x8005AC80
	// End Line: 2340

	/* begin block 2 */
		// Start line: 5486
	/* end block 2 */
	// End Line: 5487

void STREAM_DumpAllLevels(long IDNoRemove,int DoSave)

{
  _StreamUnit *streamUnit;
  int iVar1;
  
  iVar1 = 0;
  streamUnit = (_StreamUnit *)(fontTracker.font_buffer + 0x5c);
  do {
    if ((streamUnit->used != 0) && (streamUnit->StreamUnitID != IDNoRemove)) {
      STREAM_DumpUnit(streamUnit,DoSave);
    }
    iVar1 = iVar1 + 1;
    streamUnit = streamUnit + 1;
  } while (iVar1 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_LoadCurrentWarpRoom(struct StreamUnitPortal *streamPortal /*$s1*/, struct _StreamUnit *mainStreamUnit /*$a1*/)
 // line 2343, offset 0x8005ac9c
	/* begin block 1 */
		// Start line: 5533
	/* end block 1 */
	// End Line: 5534

	/* begin block 2 */
		// Start line: 5534
	/* end block 2 */
	// End Line: 5535

void STREAM_LoadCurrentWarpRoom(undefined4 param_1,int param_2)

{
                    /* WARNING: Subroutine does not return */
  strcmpi(*(char **)(*(int *)(param_2 + 8) + 0x98),&gp0xffff974c + iGpffff9748 * 0x14);
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_RelocateLoadedWarpRooms(struct _StreamUnit *mainUnit /*$s4*/, struct StreamUnitPortal *streamPortal /*$s5*/)
 // line 2360, offset 0x8005ad58
	/* begin block 1 */
		// Start line: 2361
		// Start offset: 0x8005AD58
		// Variables:
	// 		int i; // $s2
	/* end block 1 */
	// End offset: 0x8005ADDC
	// End Line: 2374

	/* begin block 2 */
		// Start line: 5570
	/* end block 2 */
	// End Line: 5571

void WARPGATE_RelocateLoadedWarpRooms(undefined *param_1,StreamUnitPortal *param_2)

{
  undefined *puVar1;
  char *baseAreaName;
  int iVar2;
  
  iVar2 = 0;
  baseAreaName = &gp0xffffbe78;
  puVar1 = &gp0xffffbe6c;
  do {
    if (((*(short *)(puVar1 + 4) == 2) && (puVar1 != param_1)) &&
       ((*(ushort *)(puVar1 + 6) & 1) != 0)) {
      STREAM_LoadLevel(baseAreaName,param_2,0);
    }
    baseAreaName = baseAreaName + 0x40;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 0x40;
  } while (iVar2 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ WARPGATE_GetWarpRoomIndex(char *name /*$s2*/)
 // line 2377, offset 0x8005ae00
	/* begin block 1 */
		// Start line: 2378
		// Start offset: 0x8005AE00
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8005AE48
	// End Line: 2390

	/* begin block 2 */
		// Start line: 5623
	/* end block 2 */
	// End Line: 5624

long WARPGATE_GetWarpRoomIndex(char *name)

{
                    /* WARNING: Subroutine does not return */
  strcmpi((char *)&CurrentWarpNumber.length,name);
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_UpdateAddToArray(struct _StreamUnit *streamUnit /*$s0*/)
 // line 2392, offset 0x8005ae60
	/* begin block 1 */
		// Start line: 2393
		// Start offset: 0x8005AE60
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x8005AE9C
	// End Line: 2401

	/* begin block 2 */
		// Start line: 5661
	/* end block 2 */
	// End Line: 5662

void WARPGATE_UpdateAddToArray(_StreamUnit *streamUnit)

{
  long lVar1;
  _StreamUnit *streamUnit_00;
  long in_a1;
  
  streamUnit_00 = (_StreamUnit *)streamUnit->baseAreaName;
  lVar1 = WARPGATE_GetWarpRoomIndex((char *)streamUnit_00);
  if (lVar1 == -1) {
    STREAM_DumpUnit(streamUnit_00,in_a1);
    return;
  }
  *(_StreamUnit **)((int)&SignalInfo_800cf208 + lVar1 * 0x14 + 8) = streamUnit;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_RemoveFromArray(struct _StreamUnit *streamUnit /*$a0*/)
 // line 2403, offset 0x8005aeac
	/* begin block 1 */
		// Start line: 2404
		// Start offset: 0x8005AEAC
	/* end block 1 */
	// End offset: 0x8005AECC
	// End Line: 2411

	/* begin block 2 */
		// Start line: 5683
	/* end block 2 */
	// End Line: 5684

void WARPGATE_RemoveFromArray(_StreamUnit *streamUnit)

{
  long lVar1;
  
  lVar1 = WARPGATE_GetWarpRoomIndex(streamUnit->baseAreaName);
  if (lVar1 == -1) {
    CurrentWarpNumber.signalHandleFunc = (_func_17 *)0x0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_Init()
 // line 2414, offset 0x8005aedc
	/* begin block 1 */
		// Start line: 2416
		// Start offset: 0x8005AEDC
		// Variables:
	// 		int n; // $a0
	/* end block 1 */
	// End offset: 0x8005AF1C
	// End Line: 2430

	/* begin block 2 */
		// Start line: 5705
	/* end block 2 */
	// End Line: 5706

	/* begin block 3 */
		// Start line: 5706
	/* end block 3 */
	// End Line: 5707

	/* begin block 4 */
		// Start line: 5718
	/* end block 4 */
	// End Line: 5719

/* WARNING: Unknown calling convention yet parameter storage is locked */

void WARPGATE_Init(void)

{
  long *plVar1;
  int iVar2;
  
  iVar2 = 0xd;
  plVar1 = &LONG_800cf304;
                    /* WARNING: Read-only address (ram,0x800d1902) is written */
  fontTracker.font_buffer[87].x = 0x1000;
                    /* WARNING: Read-only address (ram,0x800d18fc) is written */
  fontTracker.font_buffer[86]._0_4_ = 0;
                    /* WARNING: Read-only address (ram,0x800d1900) is written */
  fontTracker.font_buffer[86].c = '\0';
                    /* WARNING: Read-only address (ram,0x800d1901) is written */
  fontTracker.font_buffer[86].color = '\0';
                    /* WARNING: Read-only address (ram,0x800d1904) is written */
  fontTracker.font_buffer[87]._2_4_ = 0;
                    /* WARNING: Read-only address (ram,0x800d1908) is written */
  fontTracker.font_buffer[88]._0_4_ = 0xf000;
                    /* WARNING: Read-only address (ram,0x800d190c) is written */
  fontTracker.font_buffer._532_4_ = 0;
  CurrentWarpNumber.signalHandleFunc = (_func_17 *)0x0;
  do {
    plVar1[4] = 0;
    iVar2 = iVar2 + -1;
    plVar1 = plVar1 + -5;
  } while (-1 < iVar2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_StartUsingWarpgate()
 // line 2433, offset 0x8005af24
	/* begin block 1 */
		// Start line: 5756
	/* end block 1 */
	// End Line: 5757

	/* begin block 2 */
		// Start line: 5757
	/* end block 2 */
	// End Line: 5758

void WARPGATE_StartUsingWarpgate(void)

{
  if (iGpffffbe48 == 0) {
    SndPlayVolPan(0x16f,0x70,0x40,-200);
  }
  iGpffffbe48 = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_EndUsingWarpgate()
 // line 2440, offset 0x8005af5c
	/* begin block 1 */
		// Start line: 5771
	/* end block 1 */
	// End Line: 5772

void WARPGATE_EndUsingWarpgate(void)

{
  if (iGpffffbe48 == 1) {
    SndPlayVolPan(0x182,0x70,0x40,-200);
  }
  iGpffffbe48 = 0;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ WARPGATE_IsWarpgateInUse()
 // line 2447, offset 0x8005af94
	/* begin block 1 */
		// Start line: 5785
	/* end block 1 */
	// End Line: 5786

	/* begin block 2 */
		// Start line: 5786
	/* end block 2 */
	// End Line: 5787

/* WARNING: Unknown calling convention yet parameter storage is locked */

int WARPGATE_IsWarpgateInUse(void)

{
  return fontTracker.font_buffer[86]._0_4_;
}



// decompiled code
// original method signature: 
// int /*$ra*/ WARPGATE_IsWarpgateActive()
 // line 2453, offset 0x8005afa0
	/* begin block 1 */
		// Start line: 5797
	/* end block 1 */
	// End Line: 5798

	/* begin block 2 */
		// Start line: 5798
	/* end block 2 */
	// End Line: 5799

/* WARNING: Unknown calling convention yet parameter storage is locked */

int WARPGATE_IsWarpgateActive(void)

{
  return (uint)(fontTracker.font_buffer[86].c != '\0');
}



// decompiled code
// original method signature: 
// int /*$ra*/ WARPGATE_IsWarpgateUsable()
 // line 2460, offset 0x8005afac
	/* begin block 1 */
		// Start line: 5811
	/* end block 1 */
	// End Line: 5812

	/* begin block 2 */
		// Start line: 5812
	/* end block 2 */
	// End Line: 5813

/* WARNING: Unknown calling convention yet parameter storage is locked */

int WARPGATE_IsWarpgateUsable(void)

{
  return (uint)(fontTracker.font_buffer[86]._4_2_ == 4);
}



// decompiled code
// original method signature: 
// int /*$ra*/ WARPGATE_IsWarpgateReady()
 // line 2467, offset 0x8005afc0
	/* begin block 1 */
		// Start line: 5825
	/* end block 1 */
	// End Line: 5826

	/* begin block 2 */
		// Start line: 5826
	/* end block 2 */
	// End Line: 5827

/* WARNING: Unknown calling convention yet parameter storage is locked */

int WARPGATE_IsWarpgateReady(void)

{
  return (uint)(fontTracker.font_buffer[86].c == '\x04');
}



// decompiled code
// original method signature: 
// int /*$ra*/ WARPGATE_IsWarpgateSpectral()
 // line 2474, offset 0x8005afd4
	/* begin block 1 */
		// Start line: 5839
	/* end block 1 */
	// End Line: 5840

/* WARNING: Unknown calling convention yet parameter storage is locked */

int WARPGATE_IsWarpgateSpectral(void)

{
                    /* WARNING: Subroutine does not return */
  strcmpi((char *)((int)&CurrentWarpNumber + (int)CurrentWarpNumber.signalHandleFunc * 0x14 + 4),
          s_under3_800cf4bc);
}



// decompiled code
// original method signature: 
// int /*$ra*/ WARPGATE_IsObjectOnWarpSide(struct _Instance *instance /*$a0*/)
 // line 2481, offset 0x8005b010
	/* begin block 1 */
		// Start line: 2483
		// Start offset: 0x8005B010
		// Variables:
	// 		int side; // $a0
	/* end block 1 */
	// End offset: 0x8005B06C
	// End Line: 2502

	/* begin block 2 */
		// Start line: 5854
	/* end block 2 */
	// End Line: 5855

	/* begin block 3 */
		// Start line: 5855
	/* end block 3 */
	// End Line: 5856

	/* begin block 4 */
		// Start line: 5856
	/* end block 4 */
	// End Line: 5857

int WARPGATE_IsObjectOnWarpSide(_Instance *instance)

{
  int iVar1;
  
  if (fontTracker.font_buffer._532_4_ == 0) {
    return 0;
  }
  iVar1 = (int)*(short *)(fontTracker.font_buffer._532_4_ + 0x5e) - (int)DAT_800cfe92;
  if ((int)*(short *)(fontTracker.font_buffer._532_4_ + 0x5e) - (int)(instance->position).y < 0) {
    if (iVar1 < 0) {
      return 0;
    }
  }
  else {
    if (-1 < iVar1) {
      return 0;
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_IsItActive(struct _StreamUnit *streamUnit /*$a0*/)
 // line 2505, offset 0x8005b074
	/* begin block 1 */
		// Start line: 2507
		// Start offset: 0x8005B074
		// Variables:
	// 		struct Level *level; // $t1
	// 		int d; // $a1
	/* end block 1 */
	// End offset: 0x8005B134
	// End Line: 2529

	/* begin block 2 */
		// Start line: 5902
	/* end block 2 */
	// End Line: 5903

	/* begin block 3 */
		// Start line: 5903
	/* end block 3 */
	// End Line: 5904

	/* begin block 4 */
		// Start line: 5906
	/* end block 4 */
	// End Line: 5907

void WARPGATE_IsItActive(_StreamUnit *streamUnit)

{
  int DoSave;
  short *psVar1;
  Level *pLVar2;
  
  pLVar2 = streamUnit->level;
  streamUnit->flags = streamUnit->flags | 1;
  if ((pLVar2->PuzzleInstances != (EventPointers *)0x0) &&
     (DoSave = 0, 0 < pLVar2->PuzzleInstances->numPuzzles)) {
    do {
      psVar1 = (short *)pLVar2->PuzzleInstances->eventInstances[DoSave];
      if (*psVar1 == 1) {
        if ((theCamera.positionAccl._4_4_ & 0x400000) == 0) {
          STREAM_DumpAllLevels((long)streamUnit,DoSave);
          return;
        }
        psVar1[3] = 1;
        if (*(short *)(pLVar2->PuzzleInstances->eventInstances[DoSave] + 6) != 1) {
          return;
        }
        streamUnit->flags = streamUnit->flags | 8;
        return;
      }
      DoSave = DoSave + 1;
    } while (DoSave < pLVar2->PuzzleInstances->numPuzzles);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ WARPGATE_IsUnitWarpRoom(struct _StreamUnit *streamUnit /*$a0*/)
 // line 2531, offset 0x8005b13c
	/* begin block 1 */
		// Start line: 2533
		// Start offset: 0x8005B13C
		// Variables:
	// 		struct Level *level; // $v0
	// 		long isWarpRoom; // $a1
	// 		struct StreamUnitPortal *streamPortal; // $v1
	// 		long numPortals; // $a2
	// 		long d; // $a0
	/* end block 1 */
	// End offset: 0x8005B18C
	// End Line: 2551

	/* begin block 2 */
		// Start line: 5969
	/* end block 2 */
	// End Line: 5970

	/* begin block 3 */
		// Start line: 5970
	/* end block 3 */
	// End Line: 5971

	/* begin block 4 */
		// Start line: 5975
	/* end block 4 */
	// End Line: 5976

long WARPGATE_IsUnitWarpRoom(_StreamUnit *streamUnit)

{
  int *piVar1;
  uint uVar2;
  _StreamUnit *mainStreamUnit;
  int iVar3;
  
  piVar1 = (int *)streamUnit->level->terrain->StreamUnits;
  mainStreamUnit = (_StreamUnit *)0x0;
  iVar3 = *piVar1;
  if (0 < iVar3) {
    mainStreamUnit = (_StreamUnit *)(uint)((*(ushort *)((int)piVar1 + 0x22) & 1) != 0);
    uVar2 = (uint)(1 < iVar3);
    if (1 < iVar3) {
      STREAM_LoadCurrentWarpRoom((StreamUnitPortal *)&UNK_00000001,mainStreamUnit);
      return uVar2;
    }
  }
  return (long)mainStreamUnit;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_FixUnit(struct _StreamUnit *streamUnit /*$s0*/)
 // line 2554, offset 0x8005b194
	/* begin block 1 */
		// Start line: 2555
		// Start offset: 0x8005B194
	/* end block 1 */
	// End offset: 0x8005B1B8
	// End Line: 2567

	/* begin block 2 */
		// Start line: 6023
	/* end block 2 */
	// End Line: 6024

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
 // line 2570, offset 0x8005b1c8
	/* begin block 1 */
		// Start line: 2572
		// Start offset: 0x8005B1C8
		// Variables:
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x8005B200
	// End Line: 2581

	/* begin block 2 */
		// Start line: 6055
	/* end block 2 */
	// End Line: 6056

	/* begin block 3 */
		// Start line: 6056
	/* end block 3 */
	// End Line: 6057

	/* begin block 4 */
		// Start line: 6058
	/* end block 4 */
	// End Line: 6059

void STREAM_MarkWarpUnitsNeeded(void)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = &gp0xffffbe6c;
  do {
    if ((*(ushort *)(puVar1 + 6) & 1) != 0) {
      *(undefined4 *)(puVar1 + 0x20) = uGpffffb620;
    }
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 0x40;
  } while (iVar2 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ WARPGATE_IncrementIndex()
 // line 2586, offset 0x8005b208
	/* begin block 1 */
		// Start line: 2587
		// Start offset: 0x8005B208
		// Variables:
	// 		long result; // $s1
	/* end block 1 */
	// End offset: 0x8005B308
	// End Line: 2612

	/* begin block 2 */
		// Start line: 6091
	/* end block 2 */
	// End Line: 6092

/* WARNING: Unknown calling convention yet parameter storage is locked */

long WARPGATE_IncrementIndex(void)

{
  if (fontTracker.font_buffer[86].c == '\x04') {
    SndPlayVolPan(0x183,0x75,0x40,-0xfa);
                    /* WARNING: Read-only address (ram,0x800d1900) is written */
    fontTracker.font_buffer[86].c = '\x01';
                    /* WARNING: Read-only address (ram,0x800d1904) is written */
    fontTracker.font_buffer[87]._2_4_ = 0;
    *(undefined2 *)(fontTracker.font_buffer._532_4_ + 0xec) = 0x1000;
                    /* WARNING: Read-only address (ram,0x800d190c) is written */
    fontTracker.font_buffer._532_4_ = 0;
    *(undefined4 *)((int)&SignalInfo_800cf208 + (int)CurrentWarpNumber.signalHandleFunc * 0x14 + 8)
         = 0;
    CurrentWarpNumber.signalHandleFunc =
         (_func_17 *)((int)(CurrentWarpNumber.signalHandleFunc + 1) % 0xe);
                    /* WARNING: Subroutine does not return */
    strcmpi((char *)&theCamera.focusRotVel,
            (char *)((int)&CurrentWarpNumber + (int)CurrentWarpNumber.signalHandleFunc * 0x14 + 4));
  }
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_CalcWarpFade(int timeInc /*$a0*/)
 // line 2615, offset 0x8005b320
	/* begin block 1 */
		// Start line: 6175
	/* end block 1 */
	// End Line: 6176

	/* begin block 2 */
		// Start line: 6176
	/* end block 2 */
	// End Line: 6177

/* WARNING: Removing unreachable block (ram,0x8005b384) */

void WARPGATE_CalcWarpFade(int param_1)

{
  int iVar1;
  
  *(undefined2 *)(iGpffffbe58 + 0xec) = uGpffffbe4e;
  iGpffffbe50 = iGpffffbe50 + param_1;
  iVar1 = 0x1000 - (iGpffffbe50 * 0x1000) / (int)p_Gpffffbe54;
  uGpffffbe4e = (undefined2)iVar1;
  if (0x1000 < iVar1 * 0x10000 >> 0x10) {
    uGpffffbe4e = 0x1000;
    return;
  }
  WARPGATE_RemoveFromArray(p_Gpffffbe54);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ WARPGATE_DecrementIndex()
 // line 2624, offset 0x8005b390
	/* begin block 1 */
		// Start line: 2625
		// Start offset: 0x8005B390
		// Variables:
	// 		long result; // $s0
	/* end block 1 */
	// End offset: 0x8005B454
	// End Line: 2652

	/* begin block 2 */
		// Start line: 6194
	/* end block 2 */
	// End Line: 6195

/* WARNING: Unknown calling convention yet parameter storage is locked */

long WARPGATE_DecrementIndex(void)

{
  int iVar1;
  
  if (fontTracker.font_buffer[86].c == '\x04') {
    SndPlayVolPan(0x183,0x75,0x40,-0xfa);
                    /* WARNING: Read-only address (ram,0x800d1900) is written */
    fontTracker.font_buffer[86].c = '\x01';
                    /* WARNING: Read-only address (ram,0x800d1904) is written */
    fontTracker.font_buffer[87]._2_4_ = 0;
    *(undefined2 *)(fontTracker.font_buffer._532_4_ + 0xec) = 0x1000;
    iVar1 = (int)CurrentWarpNumber.signalHandleFunc * 0x14;
    CurrentWarpNumber.signalHandleFunc = CurrentWarpNumber.signalHandleFunc + -1;
                    /* WARNING: Read-only address (ram,0x800d190c) is written */
    fontTracker.font_buffer._532_4_ = 0;
    *(undefined4 *)((int)&SignalInfo_800cf208 + iVar1 + 8) = 0;
    if ((int)CurrentWarpNumber.signalHandleFunc < 0) {
      CurrentWarpNumber.signalHandleFunc = (_func_17 *)((int)&DAT_0000000c + 1);
    }
                    /* WARNING: Subroutine does not return */
    strcmpi((char *)&theCamera.focusRotVel,
            (char *)((int)&CurrentWarpNumber + (int)CurrentWarpNumber.signalHandleFunc * 0x14 + 4));
  }
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PreloadAllConnectedUnits(struct _StreamUnit *streamUnit /*$s4*/, struct _SVector *offset /*$s5*/)
 // line 2656, offset 0x8005b468
	/* begin block 1 */
		// Start line: 2657
		// Start offset: 0x8005B468
		// Variables:
	// 		int i; // $s1
	// 		char text[16]; // stack offset -48
	// 		int numportals; // $s3
	// 		char *commapos; // $v0
	// 		struct StreamUnitPortal *stream; // $s0
	/* end block 1 */
	// End offset: 0x8005B608
	// End Line: 2802

	/* begin block 2 */
		// Start line: 6271
	/* end block 2 */
	// End Line: 6272

	/* begin block 3 */
		// Start line: 6279
	/* end block 3 */
	// End Line: 6280

int WARPGATE_IsWarpgateActive(void)

{
  long *in_a0;
  _SVector *in_a1;
  char acStack48 [16];
  
  StreamTracker.StreamList[6].eventVariables._8_4_ =
       StreamTracker.StreamList[6].eventVariables._8_4_ + 1;
                    /* WARNING: Read-only address (ram,0x800d2bb8) is written */
  if (0 < **(int **)(*(int *)in_a0[2] + 0x30)) {
                    /* WARNING: Subroutine does not return */
    strcpy(acStack48,(char *)(*(int **)(*(int *)in_a0[2] + 0x30) + 1));
  }
  STREAM_MarkUnitNeeded(*in_a0);
  STREAM_DumpAllUnitsNotNeeded();
  RelocateLevelWithInstances((Level *)in_a0[2],in_a1);
  MEMPACK_DoGarbageCollection();
  if (0 < **(int **)(*(int *)in_a0[2] + 0x30)) {
                    /* WARNING: Subroutine does not return */
    strcpy(acStack48,(char *)(*(int *)(*(int *)in_a0[2] + 0x30) + 4));
  }
  return (int)*(int **)(*(int *)in_a0[2] + 0x30);
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateLevel(struct Level *level /*$s0*/, struct _SVector *offset /*$s1*/)
 // line 2867, offset 0x8005b62c
	/* begin block 1 */
		// Start line: 2868
		// Start offset: 0x8005B62C
		// Variables:
	// 		int curTree; // $t2

		/* begin block 1.1 */
			// Start line: 2891
			// Start offset: 0x8005B700
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $a0
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a3
		/* end block 1.1 */
		// End offset: 0x8005B700
		// End Line: 2893
	/* end block 1 */
	// End offset: 0x8005B758
	// End Line: 2900

	/* begin block 2 */
		// Start line: 5734
	/* end block 2 */
	// End Line: 5735

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
  RelocateSavedCameras((Camera *)&theCamera,level,offset);
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
 // line 2902, offset 0x8005b76c
	/* begin block 1 */
		// Start line: 2904
		// Start offset: 0x8005B76C
		// Variables:
	// 		int i; // $a3
	/* end block 1 */
	// End offset: 0x8005B7F8
	// End Line: 2916

	/* begin block 2 */
		// Start line: 6786
	/* end block 2 */
	// End Line: 6787

	/* begin block 3 */
		// Start line: 6787
	/* end block 3 */
	// End Line: 6788

	/* begin block 4 */
		// Start line: 6789
	/* end block 4 */
	// End Line: 6790

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
 // line 2918, offset 0x8005b800
	/* begin block 1 */
		// Start line: 2919
		// Start offset: 0x8005B800
		// Variables:
	// 		int i; // $t6

		/* begin block 1.1 */
			// Start line: 2929
			// Start offset: 0x8005B848
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $v1
		// 		short _y1; // $a1
		// 		short _z1; // $a2
		// 		struct _Position *_v; // $a0
		/* end block 1.1 */
		// End offset: 0x8005B848
		// End Line: 2931

		/* begin block 1.2 */
			// Start line: 2931
			// Start offset: 0x8005B848
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a3
		/* end block 1.2 */
		// End offset: 0x8005B848
		// End Line: 2931

		/* begin block 1.3 */
			// Start line: 2931
			// Start offset: 0x8005B848
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a3
		/* end block 1.3 */
		// End offset: 0x8005B848
		// End Line: 2931

		/* begin block 1.4 */
			// Start line: 2931
			// Start offset: 0x8005B848
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a3
		/* end block 1.4 */
		// End offset: 0x8005B914
		// End Line: 2940
	/* end block 1 */
	// End offset: 0x8005B930
	// End Line: 2947

	/* begin block 2 */
		// Start line: 6834
	/* end block 2 */
	// End Line: 6835

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
  if (camera->stack < 0) {
    PreloadAllConnectedUnits((_StreamUnit *)camera,(_SVector *)level);
    return;
  }
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
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateLevelWithInstances(struct Level *level /*$a0*/, struct _SVector *offset /*$s0*/)
 // line 2949, offset 0x8005b938
	/* begin block 1 */
		// Start line: 6919
	/* end block 1 */
	// End Line: 6920

void RelocateLevelWithInstances(Level *level,_SVector *offset)

{
  RelocateLevel(level,offset);
  RelocateInstances(offset);
  RelocatePlanPool((PlanningNode *)theCamera.oppositeError,offset);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateTerrain(struct _Terrain *terrain /*$s2*/, struct _SVector *offset /*$s3*/)
 // line 2960, offset 0x8005b970
	/* begin block 1 */
		// Start line: 2961
		// Start offset: 0x8005B970
		// Variables:
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x8005BA30
	// End Line: 3088

	/* begin block 2 */
		// Start line: 6941
	/* end block 2 */
	// End Line: 6942

void RelocateTerrain(_Terrain *terrain,_SVector *offset)

{
  char *pcVar1;
  _CameraKey *cameraList;
  _SVector *in_a2;
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
      cameraList = *(_CameraKey **)((int)&terrain->introList->multiSpline + iVar2);
      if (cameraList != (_CameraKey *)0x0) {
        RelocateCameras(cameraList,(long)offset,in_a2);
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
 // line 3094, offset 0x8005ba60
	/* begin block 1 */
		// Start line: 3096
		// Start offset: 0x8005BA60
		// Variables:
	// 		int i; // $a3
	/* end block 1 */
	// End offset: 0x8005BAB0
	// End Line: 3118

	/* begin block 2 */
		// Start line: 7218
	/* end block 2 */
	// End Line: 7219

	/* begin block 3 */
		// Start line: 7219
	/* end block 3 */
	// End Line: 7220

	/* begin block 4 */
		// Start line: 7222
	/* end block 4 */
	// End Line: 7223

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
 // line 3149, offset 0x8005bab8
	/* begin block 1 */
		// Start line: 3150
		// Start offset: 0x8005BAB8
		// Variables:
	// 		int i; // $t1
	// 		int d; // $a3
	/* end block 1 */
	// End offset: 0x8005BB54
	// End Line: 3162

	/* begin block 2 */
		// Start line: 6298
	/* end block 2 */
	// End Line: 6299

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
 // line 3164, offset 0x8005bb5c
	/* begin block 1 */
		// Start line: 3165
		// Start offset: 0x8005BB5C
		// Variables:
	// 		int i; // $a1
	// 		short ox; // $s1
	// 		short oy; // $s2
	// 		short oz; // $s3
	/* end block 1 */
	// End offset: 0x8005BBC8
	// End Line: 3180

	/* begin block 2 */
		// Start line: 7340
	/* end block 2 */
	// End Line: 7341

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  iVar4 = _poolManagementData;
  while (_poolManagementData = iVar4, iVar5 != 0) {
    iVar5 = iVar5 + -1;
    (planPool->pos).x = (planPool->pos).x + sVar1;
    planPool = planPool + 1;
    psVar6[-1] = psVar6[-1] + sVar2;
    *psVar6 = *psVar6 + sVar3;
    psVar6 = psVar6 + 0xe;
    iVar4 = _poolManagementData;
  }
  *(short *)(iVar4 + 2) = *(short *)(iVar4 + 2) + sVar1;
  *(short *)(iVar4 + 6) = *(short *)(iVar4 + 6) + sVar3;
  *(short *)(iVar4 + 4) = *(short *)(iVar4 + 4) + sVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocatePlanMarkers(struct _PlanMkr *planMkrList /*$a3*/, int numPlanMkrs /*$a1*/, struct _SVector *offset /*$a2*/)
 // line 3185, offset 0x8005bc10
	/* begin block 1 */
		// Start line: 3186
		// Start offset: 0x8005BC10
		// Variables:
	// 		int i; // $a1
	// 		short ox; // $t1
	// 		short oy; // $t0
	// 		short oz; // $a2
	/* end block 1 */
	// End offset: 0x8005BC5C
	// End Line: 3200

	/* begin block 2 */
		// Start line: 7395
	/* end block 2 */
	// End Line: 7396

	/* begin block 3 */
		// Start line: 7399
	/* end block 3 */
	// End Line: 7400

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
 // line 3202, offset 0x8005bc64
	/* begin block 1 */
		// Start line: 3204
		// Start offset: 0x8005BC64
		// Variables:
	// 		int i; // $a1
	// 		short ox; // $t0
	// 		short oy; // $a3
	// 		short oz; // $a2
	/* end block 1 */
	// End offset: 0x8005BCA8
	// End Line: 3217

	/* begin block 2 */
		// Start line: 7439
	/* end block 2 */
	// End Line: 7440

	/* begin block 3 */
		// Start line: 7440
	/* end block 3 */
	// End Line: 7441

	/* begin block 4 */
		// Start line: 7443
	/* end block 4 */
	// End Line: 7444

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
 // line 3219, offset 0x8005bcb0
	/* begin block 1 */
		// Start line: 3220
		// Start offset: 0x8005BCB0
		// Variables:
	// 		int i; // $a2
	/* end block 1 */
	// End offset: 0x8005BD58
	// End Line: 3241

	/* begin block 2 */
		// Start line: 7479
	/* end block 2 */
	// End Line: 7480

void RelocateCameras(_CameraKey *cameraList,long numCameras,_SVector *offset)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)cameraList;
  if ((piVar1 != (int *)0x0) && (iVar3 = 0, 0 < *(short *)(piVar1 + 1))) {
    iVar2 = 0;
    do {
      *(short *)(iVar2 + *piVar1 + 2) = *(short *)(iVar2 + *piVar1 + 2) + *(short *)numCameras;
      *(short *)(iVar2 + **(int **)cameraList + 4) =
           *(short *)(iVar2 + **(int **)cameraList + 4) + *(short *)(numCameras + 2);
      *(short *)(iVar2 + **(int **)cameraList + 6) =
           *(short *)(iVar2 + **(int **)cameraList + 6) + *(short *)(numCameras + 4);
      piVar1 = *(int **)cameraList;
      iVar3 = iVar3 + 1;
      iVar2 = iVar3 * 0x20;
    } while (iVar3 < *(short *)(piVar1 + 1));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_RelocateInstance(struct _Instance *instance /*$s0*/, struct _SVector *offset /*$s1*/)
 // line 3243, offset 0x8005bd60
	/* begin block 1 */
		// Start line: 7531
	/* end block 1 */
	// End Line: 7532

void STREAM_RelocateInstance(_Instance *instance,_SVector *offset)

{
  STREAM_OffsetInstancePosition(instance,offset,1);
                    /* WARNING: Subroutine does not return */
  INSTANCE_Post(instance,(int)&DAT_00100008,(int)offset);
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_OffsetInstancePosition(struct _Instance *instance /*$s0*/, struct _SVector *offset /*$s1*/, int streamSignalFlag /*$s2*/)
 // line 3251, offset 0x8005bda8
	/* begin block 1 */
		// Start line: 7547
	/* end block 1 */
	// End Line: 7548

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
                    /* WARNING: Subroutine does not return */
  (instance->shadowPosition).z = (instance->shadowPosition).z + offset->z;
  COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)offset);
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_SetInstancePosition(struct _Instance *instance /*$a0*/, struct evPositionData *data /*$a1*/)
 // line 3278, offset 0x8005bec0
	/* begin block 1 */
		// Start line: 3279
		// Start offset: 0x8005BEC0
		// Variables:
	// 		struct _SVector offset; // stack offset -16
	/* end block 1 */
	// End offset: 0x8005BEC0
	// End Line: 3279

	/* begin block 2 */
		// Start line: 7610
	/* end block 2 */
	// End Line: 7611

void RelocateTerrain(_Terrain *terrain,_SVector *offset)

{
  _SVector local_10;
  
  local_10.x = offset->x - *(short *)&terrain[1].numIntros;
  local_10.y = offset->y - *(short *)((int)&terrain[1].numIntros + 2);
  local_10.z = offset->z - *(short *)&terrain[1].introList;
  STREAM_OffsetInstancePosition((_Instance *)terrain,&local_10,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateInstances(struct _SVector *offset /*$s1*/)
 // line 3289, offset 0x8005bf18
	/* begin block 1 */
		// Start line: 3290
		// Start offset: 0x8005BF18
		// Variables:
	// 		struct _Instance *instance; // $s0
	/* end block 1 */
	// End offset: 0x8005BF58
	// End Line: 3300

	/* begin block 2 */
		// Start line: 7637
	/* end block 2 */
	// End Line: 7638

	/* begin block 3 */
		// Start line: 7638
	/* end block 3 */
	// End Line: 7639

void RelocateInstances(_SVector *offset)

{
  _Instance *instance;
  
  instance = *(_Instance **)(theCamera.core.vvNormalWorVecMat[1].t[2] + 4);
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
 // line 3303, offset 0x8005bf74
	/* begin block 1 */
		// Start line: 3305
		// Start offset: 0x8005BF74
		// Variables:
	// 		int i; // $t1
	// 		int d; // $t0
	/* end block 1 */
	// End offset: 0x8005C09C
	// End Line: 3330

	/* begin block 2 */
		// Start line: 7667
	/* end block 2 */
	// End Line: 7668

	/* begin block 3 */
		// Start line: 7668
	/* end block 3 */
	// End Line: 7669

	/* begin block 4 */
		// Start line: 7670
	/* end block 4 */
	// End Line: 7671

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
 // line 3340, offset 0x8005c0a4
	/* begin block 1 */
		// Start line: 3341
		// Start offset: 0x8005C0A4
		// Variables:
	// 		struct VramSize *vramSize; // $a0

		/* begin block 1.1 */
			// Start line: 3350
			// Start offset: 0x8005C0D4
			// Variables:
		// 		struct VramBuffer *vramBuffer; // $v0

			/* begin block 1.1.1 */
				// Start line: 3358
				// Start offset: 0x8005C0E4
				// Variables:
			// 		char fileName[64]; // stack offset -80
			// 		struct _BlockVramEntry *vramBlock; // $s0
			/* end block 1.1.1 */
			// End offset: 0x8005C10C
			// End Line: 3368
		/* end block 1.1 */
		// End offset: 0x8005C18C
		// End Line: 3387
	/* end block 1 */
	// End offset: 0x8005C190
	// End Line: 3395

	/* begin block 2 */
		// Start line: 7778
	/* end block 2 */
	// End Line: 7779

void STREAM_PackVRAMObject(int param_1)

{
  uint uVar1;
  int iVar2;
  char acStack80 [64];
  
  if ((*(short *)(*(int *)(param_1 + 0x10) + 0x44) != -1) &&
     (uVar1 = VRAM_GetObjectVramSpace((short *)(*(int *)(param_1 + 0x10) + 0x44),param_1),
     uVar1 != 0)) {
    iVar2 = *(int *)(param_1 + 0x18);
    if (iVar2 != 0) {
      VRAM_InsertFreeVram(0x200,0,*(short *)(iVar2 + 0xc),*(short *)(iVar2 + 0xe),
                          *(int *)(param_1 + 0x10));
    }
                    /* WARNING: Subroutine does not return */
    sprintf(acStack80,s__kain2_object__s__s_crm_800cf490);
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_SetupInstanceFlags(struct _Instance *instance /*$s0*/)
 // line 3424, offset 0x8005c1a4
	/* begin block 1 */
		// Start line: 7979
	/* end block 1 */
	// End Line: 7980

void MORPH_SetupInstanceFlags(_Instance *instance)

{
  long lVar1;
  uint uVar2;
  
  if ((instance->object->oflags & 0x80000U) != 0) {
    return;
  }
  if (theCamera.core.vvNormalWorVecMat[0]._18_2_ == 0) {
    uVar2 = instance->flags2;
    if ((uVar2 & 0x8000000) != 0) {
LAB_8005c23c:
      instance->flags2 = uVar2 | 0x10000000;
      INSTANCE_ClearTfaces(instance);
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
                    /* WARNING: Subroutine does not return */
      INSTANCE_Post(instance,(int)&PTR_00040026,0);
    }
  }
  else {
    uVar2 = instance->flags2;
    if ((uVar2 & 0x8000000) == 0) goto LAB_8005c23c;
  }
  instance->flags2 = uVar2 & 0xebffffff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_SetupInstanceListFlags()
 // line 3475, offset 0x8005c2d8
	/* begin block 1 */
		// Start line: 3476
		// Start offset: 0x8005C2D8
		// Variables:
	// 		struct _Instance *instance; // $s0
	/* end block 1 */
	// End offset: 0x8005C310
	// End Line: 3487

	/* begin block 2 */
		// Start line: 8084
	/* end block 2 */
	// End Line: 8085

	/* begin block 3 */
		// Start line: 8089
	/* end block 3 */
	// End Line: 8090

void MORPH_SetupInstanceListFlags(void)

{
  _Instance *instance;
  
  instance = *(_Instance **)(iGpffffb52c + 4);
  while (instance != (_Instance *)0x0) {
    MORPH_SetupInstanceFlags(instance);
    instance = instance->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_InMorphInstanceListFlags()
 // line 3489, offset 0x8005c320
	/* begin block 1 */
		// Start line: 3491
		// Start offset: 0x8005C320
		// Variables:
	// 		struct _Instance *instance; // $v1
	/* end block 1 */
	// End offset: 0x8005C380
	// End Line: 3514

	/* begin block 2 */
		// Start line: 8117
	/* end block 2 */
	// End Line: 8118

	/* begin block 3 */
		// Start line: 8118
	/* end block 3 */
	// End Line: 8119

	/* begin block 4 */
		// Start line: 8122
	/* end block 4 */
	// End Line: 8123

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MORPH_InMorphInstanceListFlags(void)

{
  int iVar1;
  
  iVar1 = *(int *)(theCamera.core.vvNormalWorVecMat[1].t[2] + 4);
  while (iVar1 != 0) {
    if ((*(uint *)(iVar1 + 0x18) & 0x4000000) != 0) {
      *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & 0xefffffff;
    }
    *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & 0xfbffffff;
    iVar1 = *(int *)(iVar1 + 8);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_InMorphDoFadeValues()
 // line 3516, offset 0x8005c388
	/* begin block 1 */
		// Start line: 3518
		// Start offset: 0x8005C388
		// Variables:
	// 		int fade1; // $a0
	// 		int fade2; // $v0
	/* end block 1 */
	// End offset: 0x8005C3D8
	// End Line: 3532

	/* begin block 2 */
		// Start line: 8171
	/* end block 2 */
	// End Line: 8172

	/* begin block 3 */
		// Start line: 8172
	/* end block 3 */
	// End Line: 8173

	/* begin block 4 */
		// Start line: 8174
	/* end block 4 */
	// End Line: 8175

void STREAM_SetInstancePosition(_Instance *instance,evPositionData *data)

{
  StreamTracker.StreamList[10].eventVariables[3] =
       (short)(((int)StreamTracker.StreamList[2].baseAreaName._0_2_ << 0xc) / 1000);
  if (StreamTracker.StreamList[2].baseAreaName._2_2_ == 0) {
    StreamTracker.StreamList[10].eventVariables[2] = StreamTracker.StreamList[10].eventVariables[3];
    StreamTracker.StreamList[10].eventVariables[3] =
         0x1000 - StreamTracker.StreamList[10].eventVariables[3];
                    /* WARNING: Read-only address (ram,0x800d2cb4) is written */
                    /* WARNING: Read-only address (ram,0x800d2cb6) is written */
    return;
  }
  StreamTracker.StreamList[10].eventVariables[2] =
       0x1000 - StreamTracker.StreamList[10].eventVariables[3];
                    /* WARNING: Read-only address (ram,0x800d2cb4) is written */
                    /* WARNING: Read-only address (ram,0x800d2cb6) is written */
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_UpdateTimeMult()
 // line 3538, offset 0x8005c3e0
	/* begin block 1 */
		// Start line: 3541
		// Start offset: 0x8005C3E0

		/* begin block 1.1 */
			// Start line: 3544
			// Start offset: 0x8005C3F4
			// Variables:
		// 		short ratio; // $v1
		/* end block 1.1 */
		// End offset: 0x8005C510
		// End Line: 3582
	/* end block 1 */
	// End offset: 0x8005C54C
	// End Line: 3598

	/* begin block 2 */
		// Start line: 8215
	/* end block 2 */
	// End Line: 8216

	/* begin block 3 */
		// Start line: 8217
	/* end block 3 */
	// End Line: 8218

void RelocateInstances(_SVector *offset)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)StreamTracker.StreamList[2].baseAreaName._0_2_;
  if (StreamTracker.StreamList[2].baseAreaName._0_2_ != 1000) {
    iVar1 = uVar2 - 0x2ee;
    if (StreamTracker.StreamList[2].baseAreaName._2_2_ == 0) {
      if (0xfa < (short)StreamTracker.StreamList[2].baseAreaName._0_2_) {
        uVar2 = 0xfa;
      }
      iVar1 = 0xfa - uVar2;
    }
    else {
      if (iVar1 * 0x10000 < 0) {
        iVar1 = 0;
      }
    }
    StreamTracker.StreamList[11].baseAreaName._4_4_ =
         (Level *)((int)StreamTracker.StreamList[11].level *
                   ((((iVar1 << 0x10) >> 4) / 0xfa) * 0x10000 >> 0x10) * 0x10 >> 0x10);
                    /* WARNING: Read-only address (ram,0x800d2cdc) is written */
    if (StreamTracker.StreamList[11].baseAreaName._4_4_ == (Level *)0x0) {
                    /* WARNING: Read-only address (ram,0x800d2cdc) is written */
      StreamTracker.StreamList[11].baseAreaName._4_4_ = (Level *)0x1;
    }
    uVar2 = (uint)StreamTracker.StreamList[2].baseAreaName._0_2_;
    if (StreamTracker.StreamList[2].baseAreaName._2_2_ == 0) {
      iVar1 = uVar2 - 0x2ee;
      if (iVar1 * 0x10000 < 0) {
        iVar1 = 0;
      }
    }
    else {
      if (0xfa < (short)StreamTracker.StreamList[2].baseAreaName._0_2_) {
        uVar2 = 0xfa;
      }
      iVar1 = 0xfa - uVar2;
    }
    StreamTracker.StreamList[11].baseAreaName._0_4_ =
         (Level *)((int)StreamTracker.StreamList[11].level *
                   ((((iVar1 << 0x10) >> 4) / 0xfa) * 0x10000 >> 0x10) * 0x10 >> 0x10);
                    /* WARNING: Read-only address (ram,0x800d2cd8) is written */
    if (StreamTracker.StreamList[11].baseAreaName._0_4_ == (Level *)0x0) {
                    /* WARNING: Read-only address (ram,0x800d2cd8) is written */
      StreamTracker.StreamList[11].baseAreaName._0_4_ = (Level *)0x1;
    }
    return;
  }
  if (StreamTracker.StreamList[2].baseAreaName._2_2_ == 0) {
    StreamTracker.StreamList[11].baseAreaName._0_4_ = (Level *)0x0;
    StreamTracker.StreamList[11].baseAreaName._4_4_ = StreamTracker.StreamList[11].level;
                    /* WARNING: Read-only address (ram,0x800d2cd8) is written */
                    /* WARNING: Read-only address (ram,0x800d2cdc) is written */
    return;
  }
  StreamTracker.StreamList[11].baseAreaName._0_4_ = StreamTracker.StreamList[11].level;
  StreamTracker.StreamList[11].baseAreaName._4_4_ = (Level *)0x0;
                    /* WARNING: Read-only address (ram,0x800d2cdc) is written */
                    /* WARNING: Read-only address (ram,0x800d2cd8) is written */
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_UpdateNormals(struct Level *BaseLevel /*$t0*/)
 // line 3602, offset 0x8005c554
	/* begin block 1 */
		// Start line: 3603
		// Start offset: 0x8005C554
		// Variables:
	// 		struct _TFace *face; // $v1
	// 		long faceCount; // $a2
	// 		struct _TVertex *v; // $a1
	// 		struct _MorphVertex *mv; // $a3
	// 		struct _MorphColor *mc; // $a0
	// 		short h1; // $v1
	// 		short *morphNormals; // $a1

		/* begin block 1.1 */
			// Start line: 3652
			// Start offset: 0x8005C650
			// Variables:
		// 		struct _TVertex *endv; // $a2
		/* end block 1.1 */
		// End offset: 0x8005C6C4
		// End Line: 3673

		/* begin block 1.2 */
			// Start line: 3673
			// Start offset: 0x8005C6C4
			// Variables:
		// 		struct _BSPNode *node; // $v1
		// 		struct _BSPLeaf *leaf; // $a1
		// 		struct _Sphere_noSq hsphere; // stack offset -32
		// 		struct _BoundingBox hbox; // stack offset -24
		// 		struct _Terrain *terrain; // $a0
		// 		long curTree; // $t0
		/* end block 1.2 */
		// End offset: 0x8005C8D8
		// End Line: 3724

		/* begin block 1.3 */
			// Start line: 3726
			// Start offset: 0x8005C8D8
			// Variables:
		// 		struct _Instance *instance; // $s0

			/* begin block 1.3.1 */
				// Start line: 3732
				// Start offset: 0x8005C900
				// Variables:
			// 		struct SVECTOR realDiff; // stack offset -32
			// 		struct _Position oldPos; // stack offset -24
			/* end block 1.3.1 */
			// End offset: 0x8005C9E8
			// End Line: 3756
		/* end block 1.3 */
		// End offset: 0x8005C9F8
		// End Line: 3759
	/* end block 1 */
	// End offset: 0x8005C9F8
	// End Line: 3760

	/* begin block 2 */
		// Start line: 8347
	/* end block 2 */
	// End Line: 8348

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
  instance = *(_Instance **)(theCamera.core.vvNormalWorVecMat[1].t[2] + 4);
  do {
    if (instance == (_Instance *)0x0) {
      return;
    }
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
                    /* WARNING: Subroutine does not return */
        COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)&local_20);
      }
    }
    instance = instance->next;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_BringBackNormals(struct Level *BaseLevel /*$a3*/)
 // line 3762, offset 0x8005ca08
	/* begin block 1 */
		// Start line: 3763
		// Start offset: 0x8005CA08
		// Variables:
	// 		struct _TFace *face; // $v1
	// 		long faceCount; // $a2
	// 		struct _TVertex *v; // $a1
	// 		struct _MorphVertex *mv; // $a0
	// 		struct _MorphColor *mc; // $v0
	// 		short h1; // $v1
	// 		short *morphNormals; // $a1

		/* begin block 1.1 */
			// Start line: 3818
			// Start offset: 0x8005CAE4
			// Variables:
		// 		struct _TVertex *endv; // $a2
		/* end block 1.1 */
		// End offset: 0x8005CB4C
		// End Line: 3829

		/* begin block 1.2 */
			// Start line: 3844
			// Start offset: 0x8005CB4C
			// Variables:
		// 		struct _BSPNode *node; // $v1
		// 		struct _BSPLeaf *leaf; // $a1
		// 		struct _Sphere_noSq hsphere; // stack offset -32
		// 		struct _BoundingBox hbox; // stack offset -24
		// 		struct _Terrain *terrain; // $a0
		// 		long curTree; // $t0
		/* end block 1.2 */
		// End offset: 0x8005CD60
		// End Line: 3894

		/* begin block 1.3 */
			// Start line: 3897
			// Start offset: 0x8005CD60
			// Variables:
		// 		struct _Instance *instance; // $s0

			/* begin block 1.3.1 */
				// Start line: 3903
				// Start offset: 0x8005CD88
				// Variables:
			// 		struct SVECTOR realDiff; // stack offset -32
			// 		struct _Position oldPos; // stack offset -24
			/* end block 1.3.1 */
			// End offset: 0x8005CE58
			// End Line: 3927
		/* end block 1.3 */
		// End offset: 0x8005CE68
		// End Line: 3930
	/* end block 1 */
	// End offset: 0x8005CE68
	// End Line: 3931

	/* begin block 2 */
		// Start line: 8739
	/* end block 2 */
	// End Line: 8740

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
  instance = *(_Instance **)(theCamera.core.vvNormalWorVecMat[1].t[2] + 4);
  do {
    if (instance == (_Instance *)0x0) {
      return;
    }
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
                    /* WARNING: Subroutine does not return */
        COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)&local_20);
      }
    }
    instance = instance->next;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_AddOffsets(struct Level *BaseLevel /*$s2*/, int time /*$a1*/)
 // line 3933, offset 0x8005ce78
	/* begin block 1 */
		// Start line: 3934
		// Start offset: 0x8005CE78
		// Variables:
	// 		struct _TVertex *v; // $a3
	// 		struct _MorphVertex *mv; // $a2
	// 		struct _MorphColor *mc; // $t2
	// 		long m; // $v0
	// 		long fixed_time; // $s1
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 3982
			// Start offset: 0x8005D040
			// Variables:
		// 		struct SVECTOR diff; // stack offset -40
		// 		struct SVECTOR realDiff; // stack offset -32
		// 		struct _Position oldPos; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x8005D13C
		// End Line: 4001

		/* begin block 1.2 */
			// Start line: 4010
			// Start offset: 0x8005D164
			// Variables:
		// 		long r0; // $a2
		// 		long g0; // $a1
		// 		long b0; // $a0
		// 		long r1; // $v0
		// 		long g1; // $v0
		// 		long b1; // $v1

			/* begin block 1.2.1 */
				// Start line: 4020
				// Start offset: 0x8005D164
				// Variables:
			// 		struct _TVertex *endv; // $t4
			/* end block 1.2.1 */
			// End offset: 0x8005D22C
			// End Line: 4035
		/* end block 1.2 */
		// End offset: 0x8005D22C
		// End Line: 4058
	/* end block 1 */
	// End offset: 0x8005D22C
	// End Line: 4060

	/* begin block 2 */
		// Start line: 9143
	/* end block 2 */
	// End Line: 9144

	/* begin block 3 */
		// Start line: 9149
	/* end block 3 */
	// End Line: 9150

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
  
  instance = *(_Instance **)(theCamera.core.vvNormalWorVecMat[1].t[2] + 4);
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
  do {
    if (instance == (_Instance *)0x0) {
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
                          (char)((int)((((uint)*puVar6 & 0x1f) * 8 + ((uint)uVar5 & 0x1f) * -8) *
                                      iVar7) >> 0xc);
            puVar18[-1] = (char)uVar16 +
                          (char)((int)(((iVar9 >> 0x12 & 0xf8U) - uVar16) * iVar7) >> 0xc);
            *puVar18 = (char)uVar13 +
                       (char)((int)(((iVar9 >> 0x17 & 0xf8U) - uVar13) * iVar7) >> 0xc);
            puVar18 = puVar18 + 0xc;
          } while (p_Var8 < p_Var20);
        }
      }
      return;
    }
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
                    /* WARNING: Subroutine does not return */
        COLLIDE_UpdateAllTransforms(instance,&local_20);
      }
    }
    instance = instance->next;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_SubtractOffsets(struct Level *BaseLevel /*$s2*/, int time /*$a1*/)
 // line 4062, offset 0x8005d244
	/* begin block 1 */
		// Start line: 4063
		// Start offset: 0x8005D244
		// Variables:
	// 		struct _TVertex *v; // $a3
	// 		struct _MorphVertex *mv; // $a2
	// 		struct _MorphColor *mc; // $t2
	// 		long m; // $v0
	// 		long fixed_time; // $s1
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 4109
			// Start offset: 0x8005D414
			// Variables:
		// 		struct SVECTOR diff; // stack offset -40
		// 		struct SVECTOR realDiff; // stack offset -32
		// 		struct _Position oldPos; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x8005D510
		// End Line: 4129

		/* begin block 1.2 */
			// Start line: 4138
			// Start offset: 0x8005D538
			// Variables:
		// 		long r0; // $a2
		// 		long g0; // $a1
		// 		long b0; // $a0
		// 		long r1; // $v0
		// 		long g1; // $v0
		// 		long b1; // $v1

			/* begin block 1.2.1 */
				// Start line: 4147
				// Start offset: 0x8005D538
				// Variables:
			// 		struct _TVertex *endv; // $t4
			/* end block 1.2.1 */
			// End offset: 0x8005D600
			// End Line: 4162
		/* end block 1.2 */
		// End offset: 0x8005D600
		// End Line: 4185
	/* end block 1 */
	// End offset: 0x8005D600
	// End Line: 4187

	/* begin block 2 */
		// Start line: 9485
	/* end block 2 */
	// End Line: 9486

	/* begin block 3 */
		// Start line: 9491
	/* end block 3 */
	// End Line: 9492

void MORPH_SubtractOffsets(Level *BaseLevel,int time)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  ushort *puVar4;
  int iVar5;
  _TVertex *p_Var6;
  int iVar7;
  _Terrain *p_Var8;
  Level *BaseLevel_00;
  Intro *pIVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  _MorphVertex *p_Var14;
  NodeType *pNVar15;
  uchar *puVar16;
  _MorphColor *p_Var17;
  _TVertex *p_Var18;
  _Instance *instance;
  SVECTOR local_20;
  uint local_18;
  ushort local_14;
  
  instance = *(_Instance **)(theCamera.core.vvNormalWorVecMat[1].t[2] + 4);
  if (time < 0x1f5) {
    time = time * 2;
    iVar5 = (time * time * time) / 2000000;
  }
  else {
    iVar5 = (1000 - time) * 2;
    iVar5 = 1000 - (iVar5 * iVar5 * iVar5) / 2000000;
  }
  p_Var14 = BaseLevel->terrain->MorphDiffList;
  iVar5 = ((1000 - iVar5) * 0x1000) / 1000;
  if ((p_Var14 != (_MorphVertex *)0x0) && (-1 < p_Var14->vindex)) {
    BaseLevel_00 = (Level *)BaseLevel->terrain;
    pNVar15 = (NodeType *)((int)&BaseLevel_00->pointLightList->node + (int)p_Var14->vindex * 0xc);
    *(short *)&pNVar15->prev = p_Var14->hx + (short)(p_Var14->x * iVar5 >> 0xc);
    *(short *)((int)&pNVar15->prev + 2) = p_Var14->hy + (short)(p_Var14->y * iVar5 >> 0xc);
    *(short *)(&pNVar15->prev + 1) = p_Var14->hz + (short)(p_Var14->z * iVar5 >> 0xc);
    if (-1 < p_Var14[1].vindex) {
      MORPH_AddOffsets(BaseLevel_00,(int)&p_Var14[1].vindex);
      return;
    }
  }
  do {
    if (instance == (_Instance *)0x0) {
      p_Var8 = BaseLevel->terrain;
      p_Var17 = p_Var8->MorphColorList;
      if (p_Var17 != (_MorphColor *)0x0) {
        p_Var6 = p_Var8->vertexList;
        p_Var18 = p_Var6 + p_Var8->numVertices;
        if (p_Var6 < p_Var18) {
          puVar16 = &p_Var6->b0;
          do {
            uVar3 = *(ushort *)(puVar16 + -4);
            puVar4 = (ushort *)&p_Var17->morphColor15;
            uVar13 = (uint)(uVar3 >> 2) & 0xf8;
            iVar7 = (uint)*puVar4 << 0x10;
            uVar11 = (uint)(uVar3 >> 7) & 0xf8;
            p_Var6 = p_Var6 + 1;
            p_Var17 = p_Var17 + 1;
            puVar16[-2] = (char)((uint)uVar3 & 0x1f) * '\b' +
                          (char)((int)((((uint)*puVar4 & 0x1f) * 8 + ((uint)uVar3 & 0x1f) * -8) *
                                      iVar5) >> 0xc);
            puVar16[-1] = (char)uVar13 +
                          (char)((int)(((iVar7 >> 0x12 & 0xf8U) - uVar13) * iVar5) >> 0xc);
            *puVar16 = (char)uVar11 +
                       (char)((int)(((iVar7 >> 0x17 & 0xf8U) - uVar11) * iVar5) >> 0xc);
            puVar16 = puVar16 + 0xc;
          } while (p_Var6 < p_Var18);
        }
      }
      return;
    }
    pIVar9 = instance->intro;
    if ((pIVar9 != (Intro *)0x0) &&
       (((*(int *)&pIVar9->spectralPosition != 0 || ((pIVar9->spectralPosition).z != 0)) &&
        ((instance->flags2 & 8U) == 0)))) {
      sVar1 = (pIVar9->spectralPosition).y;
      sVar2 = (pIVar9->spectralPosition).z;
      local_18 = *(uint *)&instance->position;
      local_14 = (instance->position).z;
      (instance->position).x =
           (pIVar9->position).x + (short)((pIVar9->spectralPosition).x * iVar5 >> 0xc);
      (instance->position).y = (pIVar9->position).y + (short)(sVar1 * iVar5 >> 0xc);
      (instance->position).z = (pIVar9->position).z + (short)(sVar2 * iVar5 >> 0xc);
      iVar12 = (uint)(ushort)(instance->position).x - (local_18 & 0xffff);
      local_20.vx = (short)iVar12;
      iVar10 = (uint)(ushort)(instance->position).y - (local_18 >> 0x10);
      local_20.vy = (short)iVar10;
      iVar7 = (uint)(ushort)(instance->position).z - (uint)local_14;
      local_20.vz = (short)iVar7;
      if ((iVar12 * 0x10000 >> 0x10) + (iVar10 * 0x10000 >> 0x10) + (iVar7 * 0x10000 >> 0x10) != 0)
      {
                    /* WARNING: Subroutine does not return */
        COLLIDE_UpdateAllTransforms(instance,&local_20);
      }
    }
    instance = instance->next;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_GetComponentsForTrackingPoint(struct _TFace *face /*$a2*/, struct Level *level /*$a3*/)
 // line 4192, offset 0x8005d618
	/* begin block 1 */
		// Start line: 4193
		// Start offset: 0x8005D618
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
			// Start line: 4205
			// Start offset: 0x8005D638
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
		// End offset: 0x8005D638
		// End Line: 4205

		/* begin block 1.2 */
			// Start line: 4221
			// Start offset: 0x8005D708
			// Variables:
		// 		int next; // $v1

			/* begin block 1.2.1 */
				// Start line: 4228
				// Start offset: 0x8005D790
				// Variables:
			// 		int div; // $a0
			/* end block 1.2.1 */
			// End offset: 0x8005D7DC
			// End Line: 4233
		/* end block 1.2 */
		// End offset: 0x8005D7DC
		// End Line: 4234
	/* end block 1 */
	// End offset: 0x8005D8F0
	// End Line: 4260

	/* begin block 2 */
		// Start line: 9826
	/* end block 2 */
	// End Line: 9827

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
  FontChar *pFVar12;
  _TVertex *local_20 [4];
  short local_10;
  short local_e;
  short local_c;
  int local_8 [2];
  
                    /* WARNING: Read-only address (ram,0x800d1910) is written */
  fontTracker.font_buffer[89]._2_4_ = level;
  primPool2 = (_PrimPool *)face;
  if ((face != (_TFace *)0x0) && (iVar11 = 0, level != (Level *)0x0)) {
    pFVar12 = fontTracker.font_buffer + 0x5a;
    p_Var5 = level->terrain->vertexList;
    local_20[0] = p_Var5 + (face->face).v0;
    iVar10 = 0;
    local_20[1] = p_Var5 + (face->face).v1;
    local_20[2] = p_Var5 + (face->face).v2;
    pBVar3 = level->terrain->BSPTreeArray +
             *(int *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0xc4);
    local_10 = *(short *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x5c) -
               (pBVar3->globalOffset).x;
    local_e = *(short *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x5e) - (pBVar3->globalOffset).y
    ;
    local_c = *(short *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x60) - (pBVar3->globalOffset).z
    ;
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
        if ((iVar11 != 1) || (iVar6 != (int)fontTracker.font_buffer[91].y)) {
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
      *(undefined2 *)((int)&fontTracker.font_buffer[0x5b].y + iVar10) = (short)iVar9;
      iVar6 = iVar9 + 1;
      if (2 < iVar6) {
        iVar6 = 0;
      }
      if (iVar8 == 0) {
        *(undefined2 *)((int)&fontTracker.font_buffer[0x5a].x + iVar10) = 0;
      }
      else {
        *(undefined2 *)((int)&fontTracker.font_buffer[0x5a].x + iVar10) =
             (short)((((int)local_e - (int)(local_20[iVar9]->vertex).y) * 0x1000) / iVar8);
      }
      iVar9 = (int)(local_20[iVar9]->vertex).x;
      iVar8 = (int)pFVar12->x * ((local_20[iVar6]->vertex).x - iVar9);
      if (iVar8 < 0) {
        iVar8 = iVar8 + 0xfff;
      }
      local_8[iVar11] = iVar9 + (iVar8 >> 0xc);
      pFVar12 = (FontChar *)&pFVar12->y;
      iVar11 = iVar11 + 1;
      iVar10 = iVar10 + 2;
    } while (iVar11 < 2);
    if (local_8[0] == local_8[1]) {
                    /* WARNING: Read-only address (ram,0x800d1918) is written */
      fontTracker.font_buffer[90]._4_2_ = 0;
    }
    else {
                    /* WARNING: Read-only address (ram,0x800d1918) is written */
      fontTracker.font_buffer[90]._4_2_ =
           (undefined2)(((local_10 - local_8[0]) * 0x1000) / (local_8[1] - local_8[0]));
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_AveragePoint(struct _SVector *start /*$t0*/, struct _SVector *end /*$a1*/, int interp /*$v1*/, struct _SVector *out /*$a3*/)
 // line 4262, offset 0x8005d8f8
	/* begin block 1 */
		// Start line: 10031
	/* end block 1 */
	// End Line: 10032

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
 // line 4278, offset 0x8005d970
	/* begin block 1 */
		// Start line: 4279
		// Start offset: 0x8005D970
		// Variables:
	// 		struct _SVector (*v[3]); // stack offset -56
	// 		struct _SVector p1; // stack offset -40
	// 		struct _SVector p2; // stack offset -32
	// 		struct _SVector p3; // stack offset -24
	// 		struct _Position *offset; // $a3
	// 		int next; // $a1
	// 		struct _TVertex *vertexList; // $a0

		/* begin block 1.1 */
			// Start line: 4299
			// Start offset: 0x8005DA44
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $a0
		// 		short _z0; // $a1
		// 		short _x1; // $v1
		// 		short _y1; // $t0
		// 		short _z1; // $a3
		/* end block 1.1 */
		// End offset: 0x8005DA44
		// End Line: 4299

		/* begin block 1.2 */
			// Start line: 4299
			// Start offset: 0x8005DA44
			// Variables:
		// 		struct _Position *_v0; // $a2
		/* end block 1.2 */
		// End offset: 0x8005DA44
		// End Line: 4299
	/* end block 1 */
	// End offset: 0x8005DAFC
	// End Line: 4312

	/* begin block 2 */
		// Start line: 10063
	/* end block 2 */
	// End Line: 10064

void MORPH_UpdateTrackingPoint(_TFace *face,Level *level)

{
  short sVar1;
  short sVar2;
  long lVar3;
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
    iVar6 = (int)fontTracker.font_buffer[91].y + 1;
    local_38[2] = p_Var5 + (face->face).v2;
    if (2 < iVar6) {
      iVar6 = 0;
    }
    MORPH_AveragePoint((_SVector *)local_38[(int)fontTracker.font_buffer[91].y],
                       (_SVector *)local_38[iVar6],(int)fontTracker.font_buffer[90].x,&_Stack40);
    iVar6 = (int)fontTracker.font_buffer[91]._4_2_ + 1;
    if (2 < iVar6) {
      iVar6 = 0;
    }
    MORPH_AveragePoint((_SVector *)local_38[(int)fontTracker.font_buffer[91]._4_2_],
                       (_SVector *)local_38[iVar6],(int)fontTracker.font_buffer[90].y,&_Stack32);
    MORPH_AveragePoint(&_Stack40,&_Stack32,(int)fontTracker.font_buffer[90]._4_2_,&local_18);
    lVar3 = theCamera.core.vvNormalWorVecMat[1].t[0];
    pBVar4 = level->terrain->BSPTreeArray +
             *(int *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0xc4);
    sVar1 = (pBVar4->globalOffset).y;
    sVar2 = (pBVar4->globalOffset).z;
    *(short *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x5c) =
         local_18.x + (pBVar4->globalOffset).x;
    *(short *)(lVar3 + 0x5e) = local_18.y + sVar1;
    *(short *)(lVar3 + 0x60) = local_18.z + sVar2;
    *(undefined2 *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 200) = 0xffff;
    *(undefined4 *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0xcc) = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_ToggleMorph()
 // line 4314, offset 0x8005db14
	/* begin block 1 */
		// Start line: 4315
		// Start offset: 0x8005DB14

		/* begin block 1.1 */
			// Start line: 4333
			// Start offset: 0x8005DB80
			// Variables:
		// 		struct Level *level; // $s0
		// 		int i; // $s2
		/* end block 1.1 */
		// End offset: 0x8005DC48
		// End Line: 4369
	/* end block 1 */
	// End offset: 0x8005DC48
	// End Line: 4371

	/* begin block 2 */
		// Start line: 10146
	/* end block 2 */
	// End Line: 10147

	/* begin block 3 */
		// Start line: 10148
	/* end block 3 */
	// End Line: 10149

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MORPH_ToggleMorph(void)

{
  int iVar1;
  _MultiSignal *mSignal;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  SOUND_PlaneShift((uint)(theCamera.core.vvNormalWorVecMat[0]._18_2_ == 0));
  INSTANCE_Broadcast((_Instance *)0x0,10,0x1000020,(int)theCamera.core.vvNormalWorVecMat[0]._18_2_);
  iVar4 = 0x10;
  MORPH_GetComponentsForTrackingPoint
            (*(_TFace **)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0xb4),
             *(Level **)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0xbc));
  MORPH_UpdateTrackingPoint
            (*(_TFace **)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0xb4),
             *(Level **)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0xbc));
  theCamera.core.vvNormalWorVecMat[0].m[2][2] = 0;
  piVar3 = (int *)&fontTracker.font_buffer[0x5d].y;
  SOUND_Play3dSound((_Position *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x5c),0x1a,-0x15e,0x7f,
                    0x7fff);
  do {
    if (*(short *)(piVar3 + -1) == 2) {
      iVar2 = *piVar3;
      if (theCamera.core.vvNormalWorVecMat[0]._18_2_ == 1) {
        iVar1 = *(int *)(iVar2 + 0xb8);
        if (iVar1 != 0) {
          *(ushort *)(iVar1 + 6) = *(ushort *)(iVar1 + 6) | 1;
          SIGNAL_HandleSignal((_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0],
                              (Signal *)(*(int *)(iVar2 + 0xb8) + 8),0);
          mSignal = *(_MultiSignal **)(iVar2 + 0xb8);
LAB_8005dc34:
          EVENT_AddSignalToReset(mSignal);
        }
      }
      else {
        iVar1 = *(int *)(iVar2 + 0xb4);
        if (iVar1 != 0) {
          *(ushort *)(iVar1 + 6) = *(ushort *)(iVar1 + 6) | 1;
          SIGNAL_HandleSignal((_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0],
                              (Signal *)(*(int *)(iVar2 + 0xb4) + 8),0);
          mSignal = *(_MultiSignal **)(iVar2 + 0xb4);
          goto LAB_8005dc34;
        }
      }
    }
    iVar4 = iVar4 + -1;
    piVar3 = piVar3 + 0x10;
    if (iVar4 < 1) {
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_DoStep(struct _StreamUnit *streamUnit /*$s0*/, char *baseAreaName /*$a1*/)
 // line 4373, offset 0x8005dc60
	/* begin block 1 */
		// Start line: 4374
		// Start offset: 0x8005DC60
		// Variables:
	// 		struct Level *level; // $s0
	/* end block 1 */
	// End offset: 0x8005DD2C
	// End Line: 4431

	/* begin block 2 */
		// Start line: 10300
	/* end block 2 */
	// End Line: 10301

void MORPH_DoStep(_StreamUnit *streamUnit,char *baseAreaName)

{
  bool bVar1;
  int time;
  Level *level;
  
  GAMEPAD_Shock1(0x40,0xf000);
  level = streamUnit->level;
  if (level->terrain->MorphDiffList != (_MorphVertex *)0x0) {
    VM_UpdateMorph(level,0);
    time = (int)theCamera.core.vvNormalWorVecMat[0].m[2][2];
    if (time == 1000) {
      bVar1 = theCamera.core.vvNormalWorVecMat[0]._18_2_ == 0;
      theCamera.core.vvNormalWorVecMat[0]._18_2_ = theCamera.core.vvNormalWorVecMat[0]._18_2_ ^ 1;
      if (bVar1) {
        MORPH_UpdateNormals(level);
      }
      else {
        MORPH_BringBackNormals(level);
      }
      theCamera.core.vvNormalWorVecMat[0]._18_2_ = theCamera.core.vvNormalWorVecMat[0]._18_2_ ^ 1;
      level->morphLastStep = -1;
    }
    else {
      if (theCamera.core.vvNormalWorVecMat[0]._18_2_ == 0) {
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
 // line 4433, offset 0x8005dd3c
	/* begin block 1 */
		// Start line: 4434
		// Start offset: 0x8005DD3C
		// Variables:
	// 		long time; // $v1
	// 		struct Level *level; // $a2
	// 		int fogNear; // $a1
	// 		int fogFar; // $v0
	/* end block 1 */
	// End offset: 0x8005DE00
	// End Line: 4456

	/* begin block 2 */
		// Start line: 10423
	/* end block 2 */
	// End Line: 10424

	/* begin block 3 */
		// Start line: 10429
	/* end block 3 */
	// End Line: 10430

void MORPH_SetFog(_StreamUnit *streamUnit,int mainUnitFlag)

{
  short sVar1;
  int iVar2;
  short sVar3;
  Level *pLVar4;
  int iVar5;
  
  iVar2 = ((int)theCamera.core.vvNormalWorVecMat[0].m[2][2] << 0xc) / 1000;
  pLVar4 = streamUnit->level;
  if (theCamera.core.vvNormalWorVecMat[0]._18_2_ == 0) {
    iVar2 = 0x1000 - iVar2;
  }
  iVar5 = ((uint)pLVar4->holdFogNear - (uint)pLVar4->spectralFogNear) * iVar2;
  if (iVar5 < 0) {
    iVar5 = iVar5 + 0xfff;
  }
  iVar2 = ((uint)pLVar4->holdFogFar - (uint)pLVar4->spectralFogFar) * iVar2;
  sVar3 = (short)(iVar5 >> 0xc) + pLVar4->spectralFogNear;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  sVar1 = (short)(iVar2 >> 0xc) + pLVar4->spectralFogFar;
  if (mainUnitFlag == 0) {
    STREAM_RemoveAllObjectsNotInUse((GameTracker *)streamUnit);
  }
  else {
    streamUnit->UnitFogNear = sVar3;
    streamUnit->TargetFogNear = sVar3;
    streamUnit->UnitFogFar = sVar1;
    streamUnit->TargetFogFar = sVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_UpdateTextures()
 // line 4458, offset 0x8005de10
	/* begin block 1 */
		// Start line: 4459
		// Start offset: 0x8005DE10
		// Variables:
	// 		long time; // $a0
	/* end block 1 */
	// End offset: 0x8005DE50
	// End Line: 4469

	/* begin block 2 */
		// Start line: 10483
	/* end block 2 */
	// End Line: 10484

	/* begin block 3 */
		// Start line: 10486
	/* end block 3 */
	// End Line: 10487

void MORPH_UpdateTextures(void)

{
  int time;
  
  time = ((int)sGpffffb500 << 0xc) / 1000;
  if (sGpffffb502 == 1) {
    time = 0x1000 - time;
  }
  MORPH_ChangeAreaPalettes(time);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_Continue()
 // line 4473, offset 0x8005de68
	/* begin block 1 */
		// Start line: 4474
		// Start offset: 0x8005DE68
		// Variables:
	// 		int i; // $s2
	// 		long mode; // $v0
	/* end block 1 */
	// End offset: 0x8005DFC0
	// End Line: 4532

	/* begin block 2 */
		// Start line: 10516
	/* end block 2 */
	// End Line: 10517

	/* begin block 3 */
		// Start line: 10521
	/* end block 3 */
	// End Line: 10522

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MORPH_Continue(void)

{
  _Instance *in_a0;
  evPositionData *in_a1;
  _StreamUnit *streamUnit;
  FontChar *baseAreaName;
  int iVar1;
  
  if (theCamera.core.vvNormalWorVecMat[0].m[2][2] == 0) {
    MORPH_InMorphInstanceListFlags();
  }
  iVar1 = 0;
  baseAreaName = fontTracker.font_buffer + 0x5e;
  streamUnit = (_StreamUnit *)(fontTracker.font_buffer + 0x5c);
  theCamera.core.vvNormalWorVecMat[0].m[2][2] = theCamera.core.vvNormalWorVecMat[0].m[2][2] + 0x14;
  STREAM_SetInstancePosition(in_a0,in_a1);
  do {
    if (streamUnit->used == 2) {
      MORPH_DoStep(streamUnit,(char *)baseAreaName);
      MORPH_SetFog(streamUnit,0);
    }
    baseAreaName = (FontChar *)&baseAreaName[10].c;
    iVar1 = iVar1 + 1;
    streamUnit = streamUnit + 1;
  } while (iVar1 < 0x10);
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query((_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0],10);
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_MORPH_Relocate()
 // line 4533, offset 0x8005dfdc
	/* begin block 1 */
		// Start line: 10656
	/* end block 1 */
	// End Line: 10657

	/* begin block 2 */
		// Start line: 10657
	/* end block 2 */
	// End Line: 10658

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_MORPH_Relocate(void)

{
  fontTracker.font_buffer[89]._2_4_ = 0;
  primPool2 = (_PrimPool *)0x0;
                    /* WARNING: Read-only address (ram,0x800d1910) is written */
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ AddVertex(struct VECTOR *v0 /*$a0*/, struct RECT *rect /*$t0*/)
 // line 4696, offset 0x8005dfec
	/* begin block 1 */
		// Start line: 4697
		// Start offset: 0x8005DFEC
		// Variables:
	// 		struct SVECTOR v; // stack offset -8
	// 		int x; // $v0
	// 		int y; // $v1
	// 		int z; // $a1
	// 		int scr_x; // $a0
	// 		int scr_y; // $a1
	/* end block 1 */
	// End offset: 0x8005E170
	// End Line: 4733

	/* begin block 2 */
		// Start line: 10982
	/* end block 2 */
	// End Line: 10983

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
LAB_8005e010:
    v0->vx = iVar2 + iVar1;
  }
  else {
    iVar1 = 0x8000;
    if (0 < iVar2) goto LAB_8005e010;
  }
  iVar1 = v0->vy;
  iVar2 = -0x8000;
  if ((iVar1 < 0) || (iVar2 = 0x8000, 0 < iVar1)) {
    v0->vy = iVar1 + iVar2;
  }
  iVar1 = v0->vz;
  iVar2 = -0x8000;
  if (-1 < iVar1) {
    if (iVar1 < 1) goto LAB_8005e05c;
    iVar2 = 0x8000;
  }
  v0->vz = iVar1 + iVar2;
LAB_8005e05c:
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
 // line 4735, offset 0x8005e178
	/* begin block 1 */
		// Start line: 11065
	/* end block 1 */
	// End Line: 11066

	/* begin block 2 */
		// Start line: 11066
	/* end block 2 */
	// End Line: 11067

int GetPlaneDist(int k,int j,int i,VECTOR *v)

{
  int iVar1;
  
  iVar1 = j * 6 + k * 0x20;
  return ((v->vx >> 0xc) + (int)theCamera * -0x10) * (int)*(short *)(&DAT_800cfe98 + iVar1) +
         ((v->vy >> 0xc) + (int)DAT_800cfe92 * -0x10) * (int)*(short *)(&DAT_800cfe9a + iVar1) +
         ((v->vz >> 0xc) + (int)DAT_800cfe94 * -0x10) * (int)*(short *)(&DAT_800cfe9c + iVar1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CalcVert(struct VECTOR *v /*$a0*/, struct VECTOR *v1 /*$a1*/, struct VECTOR *v2 /*$a2*/, int dist1 /*$a3*/, int dist2 /*stack 16*/, int k /*stack 20*/, int j /*stack 24*/)
 // line 4744, offset 0x8005e204
	/* begin block 1 */
		// Start line: 4745
		// Start offset: 0x8005E204
		// Variables:
	// 		int diff; // $a3
	/* end block 1 */
	// End offset: 0x8005E204
	// End Line: 4745

	/* begin block 2 */
		// Start line: 11083
	/* end block 2 */
	// End Line: 11084

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
 // line 4758, offset 0x8005e28c
	/* begin block 1 */
		// Start line: 4759
		// Start offset: 0x8005E28C
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
			// Start line: 4835
			// Start offset: 0x8005E4C4
			// Variables:
		// 		int z; // $v0
		/* end block 1.1 */
		// End offset: 0x8005E4F0
		// End Line: 4839
	/* end block 1 */
	// End offset: 0x8005E504
	// End Line: 4841

	/* begin block 2 */
		// Start line: 11111
	/* end block 2 */
	// End Line: 11112

int AddClippedTri(SVECTOR *iv,RECT *cliprect,int *minz)

{
  short *psVar1;
  bool bVar2;
  int dist1;
  int dist2;
  VECTOR *v1;
  uint uVar3;
  long lVar4;
  long lVar5;
  VECTOR *v;
  long lVar6;
  VECTOR *v_00;
  int iVar7;
  int iVar8;
  int i;
  int iVar9;
  VECTOR local_240 [16];
  VECTOR aVStack320 [16];
  int local_40;
  uint local_3c;
  int local_38;
  VECTOR *local_34;
  VECTOR *local_30;
  
  v = local_240;
  local_30 = aVStack320;
  iVar8 = 0;
  *minz = 0xffff;
  local_34 = v;
  do {
    v->vx = (int)iv->vx << 0x10;
    iVar8 = iVar8 + 1;
    v->vy = (int)iv->vy << 0x10;
    psVar1 = &iv->vz;
    iv = iv + 1;
    v->vz = (int)*psVar1 << 0x10;
    v = v + 1;
  } while (iVar8 < 3);
  i = 0;
  bVar2 = true;
  iVar8 = 3;
  do {
    local_40 = i;
    if (!bVar2) {
      local_40 = i + -3;
    }
    local_3c = (uint)!bVar2;
    dist1 = GetPlaneDist(local_3c,local_40,i,local_34);
    iVar9 = 1;
    iVar7 = 0;
    local_38 = 0;
    v = local_30;
    v1 = local_34;
    if (0 < iVar8) {
      do {
        if (iVar8 <= iVar9) {
          iVar9 = 0;
        }
        v_00 = local_34 + iVar9;
        dist2 = GetPlaneDist(local_3c,local_40,i,v_00);
        if (dist1 < 1) {
          if (0 < dist2) {
            CalcVert(v,v1,v_00,dist1,dist2,local_3c,local_40);
            v = v + 1;
            goto LAB_8005e460;
          }
        }
        else {
          if (dist2 < 1) {
            lVar5 = v1->vy;
            lVar6 = v1->vz;
            lVar4 = v1->pad;
            v->vx = v1->vx;
            v->vy = lVar5;
            v->vz = lVar6;
            v->pad = lVar4;
            iVar7 = iVar7 + 1;
            CalcVert(v + 1,v_00,v1,dist2,dist1,local_3c,local_40);
            v = v + 2;
          }
          else {
            lVar5 = v1->vy;
            lVar6 = v1->vz;
            lVar4 = v1->pad;
            v->vx = v1->vx;
            v->vy = lVar5;
            v->vz = lVar6;
            v->pad = lVar4;
            v = v + 1;
          }
LAB_8005e460:
          iVar7 = iVar7 + 1;
        }
        iVar9 = iVar9 + 1;
        local_38 = local_38 + 1;
        v1 = v1 + 1;
        dist1 = dist2;
      } while (local_38 < iVar8);
    }
    v1 = local_30;
    v = local_34;
    local_34 = local_30;
    local_30 = v;
    if (iVar7 < 3) {
      uVar3 = (uint)(iVar7 != 0);
      MORPH_Continue();
      return uVar3;
    }
    i = i + 1;
    bVar2 = i < 3;
    iVar8 = iVar7;
    if (4 < i) {
      iVar8 = 0;
      if (0 < iVar7) {
        do {
          i = AddVertex(v1,cliprect);
          if (i < *minz) {
            *minz = i;
          }
          iVar8 = iVar8 + 1;
          v1 = v1 + 1;
        } while (iVar8 < iVar7);
      }
      return 1;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_GetClipRect(struct StreamUnitPortal *portal /*$s5*/, struct RECT *rect /*$s3*/)
 // line 4843, offset 0x8005e534
	/* begin block 1 */
		// Start line: 4844
		// Start offset: 0x8005E534
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
			// Start line: 4932
			// Start offset: 0x8005E828
			// Variables:
		// 		int dot; // $v0
		/* end block 1.1 */
		// End offset: 0x8005E8A8
		// End Line: 4942
	/* end block 1 */
	// End offset: 0x8005EACC
	// End Line: 5009

	/* begin block 2 */
		// Start line: 11398
	/* end block 2 */
	// End Line: 11399

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int STREAM_GetClipRect(StreamUnitPortal *portal,RECT *rect)

{
  short sVar1;
  int local_38;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  StreamUnitPortal *v;
  short sVar7;
  int iVar8;
  char *v1;
  RECT *rect_00;
  int iVar9;
  VECTOR *v2;
  int dist1;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int local_40;
  int local_3c;
  long local_34;
  uint local_30;
  int local_2c;
  
  local_2c = 0;
  sVar7 = portal->t1[0].z;
  iVar15 = (int)sVar7;
  iVar9 = (int)portal->t1[1].z;
  local_30 = 0;
  if (iVar15 == iVar9) {
    local_30 = (uint)(sVar7 == portal->t1[2].z);
  }
  iVar8 = (int)portal->t1[0].y;
  iVar13 = iVar8 - portal->t1[1].y;
  iVar11 = iVar15 - portal->t1[2].z;
  iVar9 = iVar15 - iVar9;
  iVar5 = iVar8 - portal->t1[2].y;
  iVar6 = (int)portal->t1[0].x;
  dist1 = iVar6 - portal->t1[2].x;
  local_38 = iVar6 - portal->t1[1].x;
  iVar17 = iVar13 * iVar11 - iVar5 * iVar9 >> 0xc;
  iVar11 = dist1 * iVar9 - local_38 * iVar11 >> 0xc;
  local_38 = local_38 * iVar5 - dist1 * iVar13 >> 0xc;
  dist1 = (iVar15 - DAT_800cfe94) * local_38;
  iVar5 = (iVar6 - theCamera) * iVar17 + (iVar8 - DAT_800cfe92) * iVar11 + dist1;
  iVar9 = -iVar5;
  local_34 = MATH3D_FastSqrt(iVar17 * iVar17 + iVar11 * iVar11 + local_38 * local_38);
  iVar15 = iVar9;
  if (0 < iVar5) {
    iVar15 = iVar5;
  }
  if (iVar15 < local_34) {
    iVar8 = (int)portal->t2[0].y;
    iVar13 = (int)portal->t2[0].z;
    iVar14 = iVar8 - portal->t2[1].y;
    iVar12 = iVar13 - portal->t2[2].z;
    dist1 = iVar13 - portal->t2[1].z;
    iVar5 = iVar8 - portal->t2[2].y;
    iVar6 = (int)portal->t2[0].x;
    iVar10 = iVar6 - portal->t2[2].x;
    iVar15 = iVar6 - portal->t2[1].x;
    iVar16 = iVar14 * iVar12 - iVar5 * dist1 >> 0xc;
    iVar12 = iVar10 * dist1 - iVar15 * iVar12 >> 0xc;
    dist1 = (iVar8 - DAT_800cfe92) * iVar12;
    iVar5 = iVar15 * iVar5 - iVar10 * iVar14 >> 0xc;
    iVar15 = -((iVar6 - theCamera) * iVar16 + dist1 + (iVar13 - DAT_800cfe94) * iVar5);
    MATH3D_FastSqrt(iVar16 * iVar16 + iVar12 * iVar12 + iVar5 * iVar5);
    if (iVar9 < iVar15) {
      iVar11 = iVar12;
      iVar17 = iVar16;
      iVar9 = iVar15;
      local_38 = iVar5;
    }
  }
  v1 = s_warpgate_800cf4a8;
  v2 = (VECTOR *)&DAT_00000008;
  v = portal;
  iVar15 = memcmp((byte *)portal,(byte *)s_warpgate_800cf4a8,8);
  uVar2 = (uint)(iVar9 < -0x400);
  if (iVar15 != 0) {
    iVar15 = iVar9;
    if (iVar9 < 0) {
      iVar15 = -iVar9;
    }
    uVar2 = (uint)(iVar9 < -0x400);
    if (iVar15 < local_34) {
      v = *(StreamUnitPortal **)(_CHAR_00h_800cff98 + 0x40);
      v2 = (VECTOR *)((*(int *)(v->t1 + 1) - (int)theCamera) * iVar17);
      v1 = (char *)((*(int *)&v->t1[1].z - (int)DAT_800cfe92) * iVar11);
      uVar2 = (uint)(iVar9 < -0x400);
      if (((int)&((VECTOR *)v1)->vx + (int)&v2->vx +
           (*(int *)(v->t1 + 2) - (int)DAT_800cfe94) * local_38 < 0) && (local_30 == 0)) {
        local_2c = 1;
      }
    }
  }
  if (uVar2 == 0) {
    CalcVert((VECTOR *)v,(VECTOR *)v1,v2,dist1,local_40,local_3c,local_38);
    return uVar2;
  }
  uVar2 = 0;
  if (local_2c != 0) {
    rect->w = rect->w + rect->x;
    rect->h = rect->h + rect->y;
    setCopControlWord(2,0,*DAT_800cfef0);
    setCopControlWord(2,0x800,DAT_800cfef0[1]);
    setCopControlWord(2,0x1000,DAT_800cfef0[2]);
    setCopControlWord(2,0x1800,DAT_800cfef0[3]);
    setCopControlWord(2,0x2000,DAT_800cfef0[4]);
    setCopControlWord(2,0x2800,DAT_800cfef0[5]);
    setCopControlWord(2,0x3000,DAT_800cfef0[6]);
    setCopControlWord(2,0x3800,DAT_800cfef0[7]);
    uVar3 = AddClippedTri((SVECTOR *)portal->t1,rect,(int *)&stack0xffffffc0);
    portal = (StreamUnitPortal *)portal->t2;
    rect_00 = rect;
    uVar4 = AddClippedTri((SVECTOR *)portal,rect,(int *)&stack0xffffffc4);
    uVar2 = 0;
    if ((uVar3 | uVar4) == 0) {
      rect->w = rect->w - rect->x;
      rect->h = rect->h - rect->y;
    }
    else {
      if (local_3c < local_40) {
        local_40 = local_3c;
      }
      if ((local_2c == 0) || (uVar2 = 1, 0x3f < local_40)) {
        if (-1 < rect->x) {
          iVar9 = STREAM_GetClipRect(portal,rect_00);
          return iVar9;
        }
        rect->x = 0;
        if (rect->y < 0) {
          rect->y = 0;
        }
        if (0x200 < rect->w) {
          rect->w = 0x200;
        }
        if (0xf0 < rect->h) {
          rect->h = 0xf0;
        }
        sVar7 = rect->h - rect->y;
        rect->w = rect->w - rect->x;
        rect->h = sVar7;
        if (local_30 != 0) {
          if (iVar9 < 0) {
            iVar9 = -iVar9;
          }
          if (iVar9 < local_34) {
            if (local_38 < 1) {
              sVar1 = rect->y;
              rect->y = 0;
              sVar1 = sVar1 + sVar7;
            }
            else {
              sVar1 = 0xf0 - rect->y;
            }
            rect->h = sVar1;
          }
        }
        if (rect->w < 1) {
          uVar2 = 0;
        }
        else {
          uVar2 = (uint)(0 < rect->h);
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
  return uVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ GetFogColor(struct StreamUnitPortal *portal /*$s0*/, struct _StreamUnit *mainStreamUnit /*$a1*/, struct Level *mainLevel /*$s1*/)
 // line 5012, offset 0x8005eafc
	/* begin block 1 */
		// Start line: 5013
		// Start offset: 0x8005EAFC
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
			// Start line: 5025
			// Start offset: 0x8005EB30
			// Variables:
		// 		int time; // $a2
		/* end block 1.1 */
		// End offset: 0x8005EB68
		// End Line: 5031
	/* end block 1 */
	// End offset: 0x8005EE0C
	// End Line: 5119

	/* begin block 2 */
		// Start line: 11907
	/* end block 2 */
	// End Line: 11908

long GetFogColor(StreamUnitPortal *portal,_StreamUnit *mainStreamUnit,Level *mainLevel)

{
  undefined4 in_zero;
  undefined4 in_at;
  uint uVar1;
  Level *pLVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  undefined local_14 [4];
  
  local_18 = mainStreamUnit->FogColor;
  pLVar2 = portal->toStreamUnit->level;
  if ((int)theCamera.core.vvNormalWorVecMat[0].m[2][2] != 1000) {
    iVar4 = ((int)theCamera.core.vvNormalWorVecMat[0].m[2][2] << 0xc) / 1000;
    if (theCamera.core.vvNormalWorVecMat[0]._18_2_ == 1) {
      iVar4 = 0x1000 - iVar4;
    }
                    /* WARNING: Subroutine does not return */
    LoadAverageCol(&pLVar2->specturalColorR,&pLVar2->backColorR,iVar4,0x1000 - iVar4,
                   (undefined *)&local_28);
  }
  if (theCamera.core.vvNormalWorVecMat[0]._18_2_ == 1) {
    local_28 = *(uint *)&pLVar2->specturalColorR;
  }
  else {
    local_28 = *(uint *)&pLVar2->backColorR;
  }
  setCopReg(2,in_zero,*(undefined4 *)portal->t1);
  setCopReg(2,in_at,*(undefined4 *)&portal->t1[0].z);
  setCopReg(2,portal->t1 + 2,*(undefined4 *)(portal->t1 + 1));
  setCopReg(2,portal->t1 + 1,*(undefined4 *)&portal->t1[1].z);
  setCopReg(2,portal->t1,*(undefined4 *)(portal->t1 + 2));
  setCopReg(2,pLVar2,*(undefined4 *)&portal->t1[2].z);
  copFunction(2,0x280030);
  iVar4 = getCopReg(2,0x11);
  iVar5 = getCopReg(2,0x12);
  iVar3 = getCopReg(2,0x13);
  if (iVar5 < iVar4) {
    iVar5 = iVar3;
    if (iVar3 < iVar4) {
      iVar5 = iVar4;
    }
  }
  else {
    if (iVar5 <= iVar3) goto LAB_8005ec54;
  }
  iVar3 = iVar5;
LAB_8005ec54:
  setCopReg(2,in_zero,*(undefined4 *)portal->t2);
  setCopReg(2,in_at,*(undefined4 *)&portal->t2[0].z);
  setCopReg(2,portal->t2 + 2,*(undefined4 *)(portal->t2 + 1));
  setCopReg(2,portal->t2 + 1,*(undefined4 *)&portal->t2[1].z);
  setCopReg(2,portal->t2,*(undefined4 *)(portal->t2 + 2));
  setCopReg(2,iVar3,*(undefined4 *)&portal->t2[2].z);
  copFunction(2,0x280030);
  local_24 = getCopReg(2,0x11);
  local_20 = getCopReg(2,0x12);
  local_1c = getCopReg(2,0x13);
  iVar4 = local_20;
  if (local_20 < local_24) {
    iVar4 = local_24;
  }
  iVar5 = local_1c;
  if (local_1c < iVar4) {
    iVar5 = iVar4;
  }
  if (iVar3 < iVar5) {
    iVar3 = iVar5;
  }
  uVar1 = (uint)mainLevel->fogFar;
  if ((int)(iVar3 + 0x80U) < (int)(uint)mainLevel->fogFar) {
    uVar1 = iVar3 + 0x80U;
  }
  fontTracker.font_buffer[85]._2_4_ = (int)uVar1 >> 2;
                    /* WARNING: Read-only address (ram,0x800d18f8) is written */
  if (local_18 == local_28) {
    local_28 = local_28 & 0xfff8f8f8;
    if (local_28 != 0) {
      local_28 = local_28 | 0x40404;
    }
  }
  else {
    iVar4 = uVar1 - (uint)mainLevel->fogNear;
    if (-1 < iVar4) {
      iVar5 = (iVar4 * 0x10000) / (int)((uint)mainLevel->fogFar - (uint)mainLevel->fogNear) >> 4;
      iVar4 = iVar5;
      if (iVar5 < 0) {
        iVar4 = 0;
      }
      if (0x1000 < iVar5) {
        iVar4 = 0x1000;
      }
                    /* WARNING: Subroutine does not return */
      LoadAverageCol((byte *)&local_18,(byte *)&local_28,iVar4,0x1000 - iVar4,local_14);
    }
  }
  return local_28;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DrawFogRectangle(struct RECT *cliprect /*$a0*/, struct _PrimPool *primPool /*$a1*/, int otzpos /*$a2*/, unsigned long **drawot /*$a3*/, long color /*stack 16*/)
 // line 5121, offset 0x8005ee20
	/* begin block 1 */
		// Start line: 5122
		// Start offset: 0x8005EE20
		// Variables:
	// 		struct POLY_G4 *polyg4; // $t0
	/* end block 1 */
	// End offset: 0x8005EF04
	// End Line: 5163

	/* begin block 2 */
		// Start line: 12137
	/* end block 2 */
	// End Line: 12138

	/* begin block 3 */
		// Start line: 12140
	/* end block 3 */
	// End Line: 12141

void DrawFogRectangle(RECT *cliprect,_PrimPool *primPool,int otzpos,ulong **drawot,long color)

{
  short sVar1;
  short sVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(theCamera.core.vvPlaneConsts[2] + 4);
  if (puVar3 + 9 < *(uint **)(theCamera.core.vvPlaneConsts[2] + 8)) {
    *(uint **)(theCamera.core.vvPlaneConsts[2] + 4) = puVar3 + 9;
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
 // line 5169, offset 0x8005ef0c
	/* begin block 1 */
		// Start line: 5170
		// Start offset: 0x8005EF0C

		/* begin block 1.1 */
			// Start line: 5174
			// Start offset: 0x8005EF44
			// Variables:
		// 		long portalFogColor; // $s0
		/* end block 1.1 */
		// End offset: 0x8005EF9C
		// End Line: 5186
	/* end block 1 */
	// End offset: 0x8005EF9C
	// End Line: 5187

	/* begin block 2 */
		// Start line: 12319
	/* end block 2 */
	// End Line: 12320

void STREAM_RenderAdjacantUnit
               (ulong **param_1,StreamUnitPortal *param_2,_StreamUnit *param_3,_StreamUnit *param_4,
               RECT *param_5)

{
  long color;
  
  color = MEMPACK_MemoryValidFunc((char *)param_3->level);
  if (color != 0) {
    uGpffffb198 = *(undefined2 *)&param_3->StreamUnitID;
    color = GetFogColor(param_2,param_4,param_4->level);
    DrawFogRectangle(param_5,p_Gpffffb538,0xbff,param_1,color);
    PushMatrix();
    StreamRenderLevel(param_3,param_4->level,param_1,color);
    PopMatrix();
  }
  return;
}



// decompiled code
// original method signature: 
// struct BSPTree * /*$ra*/ STREAM_GetBspTree(struct _StreamUnit *streamUnit /*$a0*/, long bspNumber /*$a1*/)
 // line 5189, offset 0x8005efb8
	/* begin block 1 */
		// Start line: 5191
		// Start offset: 0x8005EFB8
		// Variables:
	// 		struct Level *level; // $v0
	// 		struct _Terrain *terrain; // $v0
	// 		int d; // $a0
	/* end block 1 */
	// End offset: 0x8005F010
	// End Line: 5211

	/* begin block 2 */
		// Start line: 12365
	/* end block 2 */
	// End Line: 12366

	/* begin block 3 */
		// Start line: 12366
	/* end block 3 */
	// End Line: 12367

long GetFogColor(StreamUnitPortal *portal,_StreamUnit *mainStreamUnit,Level *mainLevel)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(**(int **)(portal->tolevelname + 8) + 0x44);
  if ((iVar1 != 0) && (iVar3 = 0, 0 < iVar1)) {
    iVar2 = *(int *)(**(int **)(portal->tolevelname + 8) + 0x48);
    do {
      iVar3 = iVar3 + 1;
      if ((_StreamUnit *)(int)*(short *)(iVar2 + 0x1a) == mainStreamUnit) {
        return iVar2;
      }
      iVar2 = iVar2 + 0x24;
    } while (iVar3 < iVar1);
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_BlockWarpGateEntrance(struct _StreamUnit *streamUnit /*$a0*/, long collideOn /*$s0*/)
 // line 5214, offset 0x8005f018
	/* begin block 1 */
		// Start line: 5215
		// Start offset: 0x8005F018
		// Variables:
	// 		struct BSPTree *bspTree; // $v1
	/* end block 1 */
	// End offset: 0x8005F078
	// End Line: 5232

	/* begin block 2 */
		// Start line: 12419
	/* end block 2 */
	// End Line: 12420

void WARPGATE_BlockWarpGateEntrance(_StreamUnit *streamUnit,long collideOn)

{
  long lVar1;
  Level *in_a2;
  
  lVar1 = GetFogColor((StreamUnitPortal *)streamUnit,(_StreamUnit *)((int)&mainMenuScreen + 3),in_a2
                     );
  if (lVar1 != 0) {
    if (collideOn == 0) {
      *(ushort *)(lVar1 + 0x12) = *(ushort *)(lVar1 + 0x12) & 0xfffd;
                    /* WARNING: Read-only address (ram,0x800d1901) is written */
      fontTracker.font_buffer[86].color = '\x01';
    }
    else {
      *(ushort *)(lVar1 + 0x12) = *(ushort *)(lVar1 + 0x12) | 2;
                    /* WARNING: Read-only address (ram,0x800d1901) is written */
      fontTracker.font_buffer[86].color = '\0';
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_DrawWarpGateRim(struct _StreamUnit *streamUnit /*$a0*/, long drawOn /*$s0*/)
 // line 5235, offset 0x8005f088
	/* begin block 1 */
		// Start line: 5236
		// Start offset: 0x8005F088
		// Variables:
	// 		struct BSPTree *bspTree; // $v1
	/* end block 1 */
	// End offset: 0x8005F0D0
	// End Line: 5256

	/* begin block 2 */
		// Start line: 12461
	/* end block 2 */
	// End Line: 12462

void WARPGATE_DrawWarpGateRim(_StreamUnit *streamUnit,long drawOn)

{
  ushort uVar1;
  ushort uVar2;
  long lVar3;
  Level *in_a2;
  
  lVar3 = GetFogColor((StreamUnitPortal *)streamUnit,(_StreamUnit *)&UNK_00000003,in_a2);
  if (lVar3 != 0) {
    uVar1 = *(ushort *)(lVar3 + 0x12);
    uVar2 = uVar1 & 0xfffd;
    *(ushort *)(lVar3 + 0x12) = uVar2;
    if (drawOn == 0) {
      uVar2 = uVar2 | 1;
    }
    else {
      uVar2 = uVar1 & 0xfffc;
    }
    *(ushort *)(lVar3 + 0x12) = uVar2;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_HideAllCloudCovers()
 // line 5258, offset 0x8005f0e0
	/* begin block 1 */
		// Start line: 5260
		// Start offset: 0x8005F0E0
		// Variables:
	// 		struct Object *warpFaceObject; // $a1

		/* begin block 1.1 */
			// Start line: 5266
			// Start offset: 0x8005F0F4
			// Variables:
		// 		struct _Instance *instance; // $v1
		// 		struct _Instance *next; // $a0
		/* end block 1.1 */
		// End offset: 0x8005F138
		// End Line: 5281
	/* end block 1 */
	// End offset: 0x8005F138
	// End Line: 5283

	/* begin block 2 */
		// Start line: 12507
	/* end block 2 */
	// End Line: 12508

	/* begin block 3 */
		// Start line: 12508
	/* end block 3 */
	// End Line: 12509

	/* begin block 4 */
		// Start line: 12511
	/* end block 4 */
	// End Line: 12512

void WARPGATE_HideAllCloudCovers(void)

{
  int iVar1;
  long lVar2;
  int iVar3;
  
  lVar2 = DebugMenuLine_800c8824.bit_mask;
  if (DebugMenuLine_800c8824.bit_mask != 0) {
    iVar3 = *(int *)(iGpffffb52c + 4);
    while (iVar1 = iVar3, iVar1 != 0) {
      iVar3 = *(int *)(iVar1 + 8);
      if (*(int *)(iVar1 + 0x1c) == lVar2) {
        *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) | 0x800;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ WARPGATE_UnHideCloudCoverInUnit(long streamUnitID /*$a0*/)
 // line 5285, offset 0x8005f140
	/* begin block 1 */
		// Start line: 5287
		// Start offset: 0x8005F140
		// Variables:
	// 		struct Object *warpFaceObject; // $a3
	// 		struct _Instance *result; // $a2

		/* begin block 1.1 */
			// Start line: 5294
			// Start offset: 0x8005F154
			// Variables:
		// 		struct _Instance *instance; // $v1
		// 		struct _Instance *next; // $a1
		/* end block 1.1 */
		// End offset: 0x8005F1B0
		// End Line: 5312
	/* end block 1 */
	// End offset: 0x8005F1B0
	// End Line: 5314

	/* begin block 2 */
		// Start line: 12563
	/* end block 2 */
	// End Line: 12564

	/* begin block 3 */
		// Start line: 12564
	/* end block 3 */
	// End Line: 12565

	/* begin block 4 */
		// Start line: 12568
	/* end block 4 */
	// End Line: 12569

int WARPGATE_UnHideCloudCoverInUnit(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (DebugMenuLine_800c8824.bit_mask != 0) {
    iVar1 = *(int *)(iGpffffb52c + 4);
    do {
      iVar2 = iVar1;
      if (iVar2 == 0) {
        return 0;
      }
      iVar1 = *(int *)(iVar2 + 8);
    } while ((*(int *)(iVar2 + 0x1c) != DebugMenuLine_800c8824.bit_mask) ||
            (*(int *)(iVar2 + 0x38) != param_1));
    *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xfffff7ff;
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_RenderWarpGate(unsigned long **mainOT /*$s3*/, struct StreamUnitPortal *curStreamPortal /*$s2*/, struct _StreamUnit *mainStreamUnit /*$s1*/, struct RECT *cliprect /*$s4*/)
 // line 5318, offset 0x8005f1b8
	/* begin block 1 */
		// Start line: 5319
		// Start offset: 0x8005F1B8
		// Variables:
	// 		struct _StreamUnit *toStreamUnit; // $s0
	/* end block 1 */
	// End offset: 0x8005F4D0
	// End Line: 5428

	/* begin block 2 */
		// Start line: 12634
	/* end block 2 */
	// End Line: 12635

void STREAM_RenderWarpGate
               (ulong **param_1,StreamUnitPortal *param_2,_StreamUnit *param_3,RECT *param_4)

{
  int iVar1;
  _StreamUnit *streamUnit;
  
  WARPGATE_DrawWarpGateRim(param_3,1);
  streamUnit = param_2->toStreamUnit;
  if (cGpffffbe4c == '\x01') {
    if (iGpffffbe54 < iGpffffbe50) {
      if (streamUnit != (_StreamUnit *)0x0) {
        STREAM_DumpUnit(streamUnit,1);
      }
      cGpffffbe4c = 2;
      STREAM_LoadCurrentWarpRoom(param_2,(int)param_3);
      *(undefined2 *)(iGpffffbe58 + 0xec) = 0;
      return;
    }
    if (iGpffffbe58 == 0) {
      WARPGATE_HideAllCloudCovers();
      iGpffffbe58 = WARPGATE_UnHideCloudCoverInUnit(param_3->StreamUnitID);
      uGpffffbe4e = 0x1000;
    }
    WARPGATE_CalcWarpFade(iGpffffb738);
  }
  else {
    if (cGpffffbe4c == '\x02') {
      uGpffffbe4e = 0;
      if ((streamUnit != (_StreamUnit *)0x0) && (streamUnit->used == 2)) {
        cGpffffbe4c = '\x03';
        iGpffffbe50 = iGpffffbe54;
      }
    }
    else {
      if (cGpffffbe4c == '\x03') {
        if (iGpffffbe50 < 0) {
          WARPGATE_HideAllCloudCovers();
          iVar1 = WARPGATE_IsWarpgateInUse();
          if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
            strcmpi(&gp0xffffb654,&gp0xffff974c + iGpffff9748 * 0x14);
          }
          cGpffffbe4c = '\x04';
        }
        else {
          WARPGATE_CalcWarpFade(-iGpffffb738);
        }
      }
    }
  }
  if (cGpffffbe4c == '\0') {
    iVar1 = WARPGATE_IsWarpgateInUse();
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      strcmpi(param_3->level->worldName,&gp0xffff974c + iGpffff9748 * 0x14);
    }
    WARPGATE_BlockWarpGateEntrance(param_3,1);
  }
  else {
    if ((streamUnit != (_StreamUnit *)0x0) && (streamUnit->used == 2)) {
      WARPGATE_RenderWarpUnit(param_1,param_2,param_3,param_4);
    }
    if ((cGpffffbe4c == '\x04') && (iVar1 = WARPGATE_IsWarpgateInUse(), iVar1 == 0)) {
      cGpffffbe4c = 1;
      iGpffffbe50 = 0;
      iGpffffbe58 = 0;
      *(undefined4 *)(&gp0xffff975c + iGpffff9748 * 0x14) = 0;
                    /* WARNING: Subroutine does not return */
      strcmpi(&gp0xffffb654,&gp0xffff974c + iGpffff9748 * 0x14);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WARPGATE_RenderWarpUnit(unsigned long **mainOT /*$fp*/, struct StreamUnitPortal *curStreamPortal /*$s0*/, struct _StreamUnit *mainStreamUnit /*$s4*/, struct RECT *cliprect /*$s2*/)
 // line 5431, offset 0x8005f4f0
	/* begin block 1 */
		// Start line: 5432
		// Start offset: 0x8005F4F0
		// Variables:
	// 		unsigned long **curOT; // $s3
	// 		struct DR_AREA *PortalClip; // $s0
	// 		struct _StreamUnit *toStreamUnit; // $s1

		/* begin block 1.1 */
			// Start line: 5465
			// Start offset: 0x8005F5B8
			// Variables:
		// 		struct RECT PortalRect; // stack offset -48
		// 		long portalFogColor; // $s0

			/* begin block 1.1.1 */
				// Start line: 5534
				// Start offset: 0x8005F800
				// Variables:
			// 		unsigned long *hld; // $a0
			/* end block 1.1.1 */
			// End offset: 0x8005F898
			// End Line: 5552
		/* end block 1.1 */
		// End offset: 0x8005F898
		// End Line: 5553
	/* end block 1 */
	// End offset: 0x8005F898
	// End Line: 5555

	/* begin block 2 */
		// Start line: 12871
	/* end block 2 */
	// End Line: 12872

void WARPGATE_RenderWarpUnit
               (ulong **mainOT,StreamUnitPortal *curStreamPortal,_StreamUnit *mainStreamUnit,
               RECT *cliprect)

{
  long lVar1;
  _StreamUnit *streamUnit;
  undefined4 *puVar2;
  
  streamUnit = curStreamPortal->toStreamUnit;
  if ((theCamera.core._212_4_ & 0x1000000) != 0) {
                    /* WARNING: Subroutine does not return */
    FONT_Print(s_Looking_at_warp_unit___s_800cf4c4);
  }
  WARPGATE_BlockWarpGateEntrance(mainStreamUnit,(uint)((streamUnit->flags & 8U) != 0));
  WARPGATE_DrawWarpGateRim(streamUnit,1);
  lVar1 = MEMPACK_MemoryValidFunc((char *)streamUnit->level);
  if ((lVar1 != 0) &&
     (puVar2 = *(undefined4 **)(theCamera.core.vvPlaneConsts[2] + 4),
     puVar2 < (undefined4 *)(*(int *)(theCamera.core.vvPlaneConsts[2] + 8) - 0x3000U))) {
                    /* WARNING: Subroutine does not return */
    *(undefined4 **)(theCamera.core.vvPlaneConsts[2] + 4) = puVar2 + 0xc00;
    ClearOTagR(puVar2,0xc00);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_DumpNonResidentObjects()
 // line 5613, offset 0x8005f8c8
	/* begin block 1 */
		// Start line: 5614
		// Start offset: 0x8005F8C8
		// Variables:
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 5621
			// Start offset: 0x8005F8F4
			// Variables:
		// 		struct _Instance *next; // $s2
		// 		struct Object *object; // $s1
		/* end block 1.1 */
		// End offset: 0x8005F948
		// End Line: 5636
	/* end block 1 */
	// End offset: 0x8005F954
	// End Line: 5639

	/* begin block 2 */
		// Start line: 13278
	/* end block 2 */
	// End Line: 13279

	/* begin block 3 */
		// Start line: 13283
	/* end block 3 */
	// End Line: 13284

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_DumpNonResidentObjects(void)

{
  _Instance *instance;
  _StreamUnit *p_Var1;
  _ObjectTracker *tracker;
  int iVar2;
  Object *object;
  _Instance *p_Var3;
  
  p_Var3 = *(_Instance **)(theCamera.core.vvNormalWorVecMat[1].t[2] + 4);
  while (instance = p_Var3, instance != (_Instance *)0x0) {
    object = instance->object;
    p_Var3 = instance->next;
    if (((object->oflags & 0x2000000U) == 0) &&
       (p_Var1 = STREAM_GetStreamUnitWithID(instance->birthStreamUnitID),
       p_Var1 == (_StreamUnit *)0x0)) {
      tracker = FindObjectInTracker(object);
      iVar2 = STREAM_IsObjectInAnyUnit(tracker);
      if (iVar2 == 0) {
        INSTANCE_ReallyRemoveInstance
                  ((_InstanceList *)theCamera.core.vvNormalWorVecMat[1].t[2],instance,0);
      }
    }
  }
  STREAM_RemoveAllObjectsNotInUse();
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_TryAndDumpNonResident(struct _ObjectTracker *otr /*$s2*/)
 // line 5645, offset 0x8005f978
	/* begin block 1 */
		// Start line: 5646
		// Start offset: 0x8005F978
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		struct _Instance *next; // $s1
	/* end block 1 */
	// End offset: 0x8005FAD0
	// End Line: 5713

	/* begin block 2 */
		// Start line: 13367
	/* end block 2 */
	// End Line: 13368

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
      p_Var4 = *(_Instance **)(theCamera.core.vvNormalWorVecMat[1].t[2] + 4);
      if (p_Var4 != (_Instance *)0x0) {
        do {
          pp_Var1 = &p_Var4->next;
          if (((p_Var4->object == otr->object) &&
              (p_Var4->LinkParent != (_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0])) &&
             ((p_Var4->object->oflags2 & 0x80000U) == 0)) {
            return 0;
          }
          p_Var4 = *pp_Var1;
        } while (*pp_Var1 != (_Instance *)0x0);
        p_Var4 = *(_Instance **)(theCamera.core.vvNormalWorVecMat[1].t[2] + 4);
      }
      while (instance = p_Var4, instance != (_Instance *)0x0) {
        p_Var4 = instance->next;
        if (instance->object == otr->object) {
          SAVE_DeleteInstance(instance);
          if (instance->LinkParent != (_Instance *)0x0) {
            INSTANCE_ReallyRemoveInstance
                      ((_InstanceList *)theCamera.core.vvNormalWorVecMat[1].t[2],
                       instance->LinkParent,0);
            p_Var4 = instance->next;
          }
          if (instance->LinkChild != (_Instance *)0x0) {
            INSTANCE_ReallyRemoveAllChildren(instance);
            p_Var4 = instance->next;
          }
          INSTANCE_ReallyRemoveInstance
                    ((_InstanceList *)theCamera.core.vvNormalWorVecMat[1].t[2],instance,0);
        }
      }
      STREAM_RemoveAllObjectsNotInUse();
      uVar2 = (uint)(otr->objectStatus == 0);
    }
  }
  return uVar2;
}





