#include "THISDUST.H"
#include "OBTABLE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_InstanceInit(struct _Instance *instance /*$s0*/)
 // line 88, offset 0x8003e510
	/* begin block 1 */
		// Start line: 89
		// Start offset: 0x8003E510
		// Variables:
	// 		long id; // $a0
	/* end block 1 */
	// End offset: 0x8003E5EC
	// End Line: 126

	/* begin block 2 */
		// Start line: 176
	/* end block 2 */
	// End Line: 177

void OBTABLE_InstanceInit(_Instance *instance)

{
  int iVar1;
  
  iVar1 = (int)instance->object->id;
  if (iVar1 < 0) {
    GenericInit(instance,&gameTrackerX);
  }
  else {
    if ((&objectFunc)[iVar1].initFunc != (_func_24 *)0x0) {
      (*(&objectFunc)[iVar1].initFunc)(instance,&gameTrackerX);
    }
  }
  instance->flags2 = instance->flags2 | 0x200000;
  if ((instance->flags & 0x100000U) == 0) {
    SCRIPT_InstanceSplineInit(instance);
  }
  if ((instance->intro != (Intro *)0x0) && ((instance->intro->flags & 0x20U) != 0)) {
    instance->flags2 = instance->flags2 & 0xfffdfffb;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_GetInstanceCollideFunc(struct _Instance *instance /*$a0*/)
 // line 144, offset 0x8003e5fc
	/* begin block 1 */
		// Start line: 146
		// Start offset: 0x8003E5FC
		// Variables:
	// 		long id; // $a1
	/* end block 1 */
	// End offset: 0x8003E63C
	// End Line: 159

	/* begin block 2 */
		// Start line: 289
	/* end block 2 */
	// End Line: 290

	/* begin block 3 */
		// Start line: 290
	/* end block 3 */
	// End Line: 291

void OBTABLE_GetInstanceCollideFunc(_Instance *instance)

{
  int iVar1;
  
  iVar1 = (int)instance->object->id;
  if (-1 < iVar1) {
    *(_func_26 **)&instance->collideFunc = (&objectFunc)[iVar1].collideFunc;
    return;
  }
  instance->collideFunc = GenericCollide;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_GetInstanceAdditionalCollideFunc(struct _Instance *instance /*$a0*/)
 // line 176, offset 0x8003e644
	/* begin block 1 */
		// Start line: 178
		// Start offset: 0x8003E644
		// Variables:
	// 		long id; // $a1
	/* end block 1 */
	// End offset: 0x8003E67C
	// End Line: 190

	/* begin block 2 */
		// Start line: 353
	/* end block 2 */
	// End Line: 354

	/* begin block 3 */
		// Start line: 354
	/* end block 3 */
	// End Line: 355

void OBTABLE_GetInstanceAdditionalCollideFunc(_Instance *instance)

{
  int iVar1;
  
  iVar1 = (int)instance->object->id;
  if (-1 < iVar1) {
    *(_func_29 **)&instance->additionalCollideFunc = (&objectFunc)[iVar1].additionalCollideFunc;
    return;
  }
  instance->additionalCollideFunc = (_func_3 *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_GetInstanceProcessFunc(struct _Instance *instance /*$a0*/)
 // line 206, offset 0x8003e684
	/* begin block 1 */
		// Start line: 208
		// Start offset: 0x8003E684
		// Variables:
	// 		long id; // $a1
	/* end block 1 */
	// End offset: 0x8003E6C4
	// End Line: 220

	/* begin block 2 */
		// Start line: 413
	/* end block 2 */
	// End Line: 414

	/* begin block 3 */
		// Start line: 414
	/* end block 3 */
	// End Line: 415

void OBTABLE_GetInstanceProcessFunc(_Instance *instance)

{
  int iVar1;
  
  iVar1 = (int)instance->object->id;
  if (-1 < iVar1) {
    *(_func_25 **)&instance->processFunc = (&objectFunc)[iVar1].processFunc;
    return;
  }
  instance->processFunc = _GlyphGenericProcess;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_GetInstanceQueryFunc(struct _Instance *instance /*$a0*/)
 // line 236, offset 0x8003e6cc
	/* begin block 1 */
		// Start line: 238
		// Start offset: 0x8003E6CC
		// Variables:
	// 		long id; // $a1
	/* end block 1 */
	// End offset: 0x8003E70C
	// End Line: 250

	/* begin block 2 */
		// Start line: 473
	/* end block 2 */
	// End Line: 474

	/* begin block 3 */
		// Start line: 474
	/* end block 3 */
	// End Line: 475

void OBTABLE_GetInstanceMessageFunc(_Instance *instance)

{
  int iVar1;
  
  iVar1 = (int)instance->object->id;
  if (-1 < iVar1) {
    *(_func_27 **)&instance->queryFunc = (&objectFunc)[iVar1].queryFunc;
    return;
  }
  instance->queryFunc = GenericQuery;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_GetInstanceMessageFunc(struct _Instance *instance /*$a0*/)
 // line 266, offset 0x8003e714
	/* begin block 1 */
		// Start line: 268
		// Start offset: 0x8003E714
		// Variables:
	// 		long id; // $a1
	/* end block 1 */
	// End offset: 0x8003E754
	// End Line: 280

	/* begin block 2 */
		// Start line: 533
	/* end block 2 */
	// End Line: 534

	/* begin block 3 */
		// Start line: 534
	/* end block 3 */
	// End Line: 535

void OBTABLE_GetInstanceQueryFunc(_Instance *instance)

{
  int iVar1;
  
  iVar1 = (int)instance->object->id;
  if (-1 < iVar1) {
    *(_func_28 **)&instance->messageFunc = (&objectFunc)[iVar1].messageFunc;
    return;
  }
  instance->messageFunc = GenericMessage;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_InitObjectWithID(struct Object *object /*$s2*/)
 // line 283, offset 0x8003e75c
	/* begin block 1 */
		// Start line: 284
		// Start offset: 0x8003E75C
		// Variables:
	// 		long id; // $s1

		/* begin block 1.1 */
			// Start line: 289
			// Start offset: 0x8003E77C
			// Variables:
		// 		struct ObjectAccess *oa; // $a0
		/* end block 1.1 */
		// End offset: 0x8003E918
		// End Line: 349
	/* end block 1 */
	// End offset: 0x8003E918
	// End Line: 350

	/* begin block 2 */
		// Start line: 567
	/* end block 2 */
	// End Line: 568

void OBTABLE_InitObjectWithID(Object *object)

{
  int iVar1;
  ObjectAccess *pOVar2;
  ObjectFunc *pOVar3;
  int iVar4;
  
  if (object == (Object *)0x0) {
    return;
  }
  if ((object->oflags2 & 0x40000U) == 0) {
    if ((object->oflags2 & 0x80000U) == 0) {
      iVar4 = 0;
      pOVar3 = &objectFunc;
      do {
        iVar1 = strcmpi(pOVar3->scriptName,object->script);
        if (iVar1 == 0) break;
        pOVar3 = pOVar3 + 1;
        iVar4 = iVar4 + 1;
      } while (pOVar3->scriptName != (char *)0x0);
LAB_8003e87c:
      if ((&objectFunc)[iVar4].scriptName != (char *)0x0) {
        object->id = (short)iVar4;
        goto LAB_8003e8b8;
      }
    }
    else {
      iVar4 = 0;
      pOVar3 = &objectFunc;
      do {
        iVar1 = strcmpi(pOVar3->scriptName,"monster_");
        if (iVar1 == 0) goto LAB_8003e87c;
        pOVar3 = pOVar3 + 1;
        iVar4 = iVar4 + 1;
      } while (pOVar3->scriptName != (char *)0x0);
    }
  }
  else {
    iVar4 = 0;
    pOVar3 = &objectFunc;
    do {
      iVar1 = strcmpi(pOVar3->scriptName,"physical");
      if (iVar1 == 0) goto LAB_8003e87c;
      pOVar3 = pOVar3 + 1;
      iVar4 = iVar4 + 1;
    } while (pOVar3->scriptName != (char *)0x0);
  }
  object->id = -1;
LAB_8003e8b8:
  pOVar2 = &objectAccess;
  while ((*(int *)pOVar2->objectName != *(int *)object->name ||
         (*(int *)(pOVar2->objectName + 1) != *(int *)(object->name + 1)))) {
    pOVar2 = pOVar2 + 1;
    if (pOVar2->objectName == (char *)0x0) {
      return;
    }
  }
  *(Object **)&pOVar2->object = object;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_ClearObjectReferences()
 // line 372, offset 0x8003e934
	/* begin block 1 */
		// Start line: 374
		// Start offset: 0x8003E934
		// Variables:
	// 		struct ObjectAccess *oa; // $a0
	/* end block 1 */
	// End offset: 0x8003E960
	// End Line: 378

	/* begin block 2 */
		// Start line: 762
	/* end block 2 */
	// End Line: 763

	/* begin block 3 */
		// Start line: 763
	/* end block 3 */
	// End Line: 764

	/* begin block 4 */
		// Start line: 765
	/* end block 4 */
	// End Line: 766

/* WARNING: Unknown calling convention yet parameter storage is locked */

void OBTABLE_ClearObjectReferences(void)

{
  ObjectAccess *pOVar1;
  
  pOVar1 = &objectAccess;
  do {
    pOVar1->object = (void *)0x0;
    pOVar1 = pOVar1 + 1;
  } while (pOVar1->objectName != (char *)0x0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_RemoveObjectEntry(struct Object *object /*$a0*/)
 // line 380, offset 0x8003e968
	/* begin block 1 */
		// Start line: 382
		// Start offset: 0x8003E968
		// Variables:
	// 		struct ObjectAccess *oa; // $a1
	/* end block 1 */
	// End offset: 0x8003E9A8
	// End Line: 392

	/* begin block 2 */
		// Start line: 779
	/* end block 2 */
	// End Line: 780

	/* begin block 3 */
		// Start line: 780
	/* end block 3 */
	// End Line: 781

	/* begin block 4 */
		// Start line: 782
	/* end block 4 */
	// End Line: 783

void OBTABLE_RemoveObjectEntry(Object *object)

{
  Object **ppOVar1;
  ObjectAccess *pOVar2;
  
  pOVar2 = &objectAccess;
  ppOVar1 = (Object **)&objectAccess.object;
  do {
    pOVar2 = pOVar2 + 1;
    if (*ppOVar1 == object) {
      *ppOVar1 = (Object *)0x0;
      return;
    }
    ppOVar1 = ppOVar1 + 2;
  } while (pOVar2->objectName != (char *)0x0);
  return;
}



// decompiled code
// original method signature: 
// struct Object * /*$ra*/ OBTABLE_FindObject(char *objectName /*$s3*/)
 // line 394, offset 0x8003e9b0
	/* begin block 1 */
		// Start line: 395
		// Start offset: 0x8003E9B0
		// Variables:
	// 		struct Object *object; // $s0
	// 		struct _ObjectTracker *otr; // $v0
	// 		int i; // $s2
	/* end block 1 */
	// End offset: 0x8003EA40
	// End Line: 412

	/* begin block 2 */
		// Start line: 812
	/* end block 2 */
	// End Line: 813

	/* begin block 3 */
		// Start line: 817
	/* end block 3 */
	// End Line: 818

Object * OBTABLE_RelocateObjectTune(char *objectName)

{
  long lVar1;
  Object *address;
  Object **ppOVar2;
  int iVar3;
  
  iVar3 = 0x30;
  ppOVar2 = &(gameTrackerX.GlobalObjects)->object;
  do {
    if (*(short *)(ppOVar2 + 1) != 0) {
      address = *ppOVar2;
      lVar1 = MEMPACK_ReportMemory((char *)address);
      if (((lVar1 != 0) && (*(int *)objectName == *(int *)address->name)) &&
         (*(int *)(objectName + 4) == *(int *)(address->name + 1))) {
        return address;
      }
    }
    iVar3 = iVar3 + -1;
    ppOVar2 = ppOVar2 + 9;
    if (iVar3 == 0) {
      return (Object *)0x0;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_ChangeObjectAccessPointers(struct Object *oldObject /*$a0*/, struct Object *newObject /*$a1*/)
 // line 414, offset 0x8003ea5c
	/* begin block 1 */
		// Start line: 416
		// Start offset: 0x8003EA5C
		// Variables:
	// 		struct ObjectAccess *oa; // $a2
	/* end block 1 */
	// End offset: 0x8003EA9C
	// End Line: 426

	/* begin block 2 */
		// Start line: 869
	/* end block 2 */
	// End Line: 870

	/* begin block 3 */
		// Start line: 870
	/* end block 3 */
	// End Line: 871

	/* begin block 4 */
		// Start line: 872
	/* end block 4 */
	// End Line: 873

void OBTABLE_ChangeObjectAccessPointers(Object *oldObject,Object *newObject)

{
  Object **ppOVar1;
  ObjectAccess *pOVar2;
  
  pOVar2 = &objectAccess;
  ppOVar1 = (Object **)&objectAccess.object;
  do {
    pOVar2 = pOVar2 + 1;
    if (*ppOVar1 == oldObject) {
      *ppOVar1 = newObject;
      return;
    }
    ppOVar1 = ppOVar1 + 2;
  } while (pOVar2->objectName != (char *)0x0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_RelocateObjectTune(struct Object *object /*$a0*/, long offset /*$a1*/)
 // line 428, offset 0x8003eaa4
	/* begin block 1 */
		// Start line: 429
		// Start offset: 0x8003EAA4
		// Variables:
	// 		long id; // $a2

		/* begin block 1.1 */
			// Start line: 442
			// Start offset: 0x8003EAF0
		/* end block 1.1 */
		// End offset: 0x8003EAF8
		// End Line: 444
	/* end block 1 */
	// End offset: 0x8003EAF8
	// End Line: 445

	/* begin block 2 */
		// Start line: 902
	/* end block 2 */
	// End Line: 903

void OBTABLE_RelocateObjectTune(Object *object,long offset)

{
  if ((int)object->id < 0) {
    GenericRelocateTune(object,offset);
  }
  else {
    if ((&objectFunc)[(int)object->id].relocateTuneFunc != (_func_30 *)0x0) {
      (*(&objectFunc)[(int)object->id].relocateTuneFunc)();
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_RelocateInstanceObject(struct _Instance *instance /*$a0*/, long offset /*$a1*/)
 // line 447, offset 0x8003eb08
	/* begin block 1 */
		// Start line: 448
		// Start offset: 0x8003EB08
		// Variables:
	// 		long id; // $a2
	/* end block 1 */
	// End offset: 0x8003EB54
	// End Line: 459

	/* begin block 2 */
		// Start line: 940
	/* end block 2 */
	// End Line: 941

void STREAM_RelocateInstance(_Instance *instance,long offset)

{
  int iVar1;
  
  iVar1 = (int)instance->object->id;
  if ((-1 < iVar1) && ((&objectFunc)[iVar1].relocateInstObFunc != (_func_31 *)0x0)) {
    (*(&objectFunc)[iVar1].relocateInstObFunc)();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_InitAnimPointers(struct _ObjectTracker *objectTracker /*$s5*/)
 // line 461, offset 0x8003eb64
	/* begin block 1 */
		// Start line: 462
		// Start offset: 0x8003EB64
		// Variables:
	// 		struct Object *object; // $s3

		/* begin block 1.1 */
			// Start line: 467
			// Start offset: 0x8003EBA4
			// Variables:
		// 		int i; // $s2
		// 		char *earlyOut; // $s4
		// 		struct _G2AnimKeylist_Type **keyPtr; // $s1

			/* begin block 1.1.1 */
				// Start line: 473
				// Start offset: 0x8003EBB4
				// Variables:
			// 		struct _ObjectOwnerInfo *oi; // $s0

				/* begin block 1.1.1.1 */
					// Start line: 477
					// Start offset: 0x8003EBCC
					// Variables:
				// 		struct _ObjectTracker *otr; // $a2
				// 		struct Object *ownerOb; // $a3
				// 		int j; // $a1
				// 		int objectIndex; // $a0
				/* end block 1.1.1.1 */
				// End offset: 0x8003EC9C
				// End Line: 504
			/* end block 1.1.1 */
			// End offset: 0x8003EC9C
			// End Line: 505
		/* end block 1.1 */
		// End offset: 0x8003ECC0
		// End Line: 514
	/* end block 1 */
	// End offset: 0x8003ECDC
	// End Line: 521

	/* begin block 2 */
		// Start line: 968
	/* end block 2 */
	// End Line: 969

void OBTABLE_InitAnimPointers(_ObjectTracker *objectTracker)

{
  _ObjectTracker *p_Var1;
  int iVar2;
  _ObjectTracker *p_Var3;
  int iVar4;
  int iVar5;
  Object *pOVar6;
  _G2AnimKeylist_Type *p_Var7;
  _G2AnimKeylist_Type *p_Var8;
  int iVar9;
  Object *object;
  short *psVar10;
  
  object = objectTracker->object;
  if ((object->oflags2 & 0x10000000U) != 0) {
    iVar9 = (int)object->numAnims;
    p_Var8 = (_G2AnimKeylist_Type *)object->animList;
    psVar10 = (short *)0x0;
    while (iVar9 != 0) {
      p_Var7 = *(_G2AnimKeylist_Type **)p_Var8;
      if ((*(int *)p_Var7 == 0xface0ff) &&
         (p_Var1 = STREAM_GetObjectTracker((char *)&p_Var7->timePerKey),
         p_Var1 != (_ObjectTracker *)0x0)) {
        iVar4 = (int)((int)objectTracker - (int)gameTrackerX.GlobalObjects) * 0x38e38e39 >> 2;
        iVar2 = (int)p_Var1->numObjectsUsing;
        pOVar6 = p_Var1->object;
        iVar5 = 0;
        p_Var3 = p_Var1;
        if (0 < iVar2) {
          do {
            if ((int)p_Var3->objectsUsing[0] == iVar4) break;
            iVar5 = iVar5 + 1;
            p_Var3 = (_ObjectTracker *)(p_Var1->name + iVar5);
          } while (iVar5 < iVar2);
          iVar2 = (int)p_Var1->numObjectsUsing;
        }
        if (iVar5 == iVar2) {
          p_Var1->numObjectsUsing = p_Var1->numObjectsUsing + '\x01';
          p_Var1->objectsUsing[iVar5] = (char)iVar4;
        }
        if (p_Var1->objectStatus == 2) {
          *(_G2AnimKeylist_Type **)p_Var8 = pOVar6->animList[(short)p_Var7->keyCount];
        }
        else {
          psVar10 = &p_Var7->timePerKey;
        }
      }
      iVar9 = iVar9 + -1;
      p_Var8 = (_G2AnimKeylist_Type *)&p_Var8->keyCount;
    }
    if (psVar10 != (short *)0x0) {
      return;
    }
    object->oflags2 = object->oflags2 & 0xefffffff;
  }
  if ((object->oflags2 & 0x80000U) != 0) {
    MonsterTranslateAnim(object);
  }
  return;
}





