#include "THISDUST.H"
#include "OBTABLE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_InstanceInit(struct _Instance *instance /*$s0*/)
 // line 88, offset 0x8003ef8c
	/* begin block 1 */
		// Start line: 89
		// Start offset: 0x8003EF8C
		// Variables:
	// 		long id; // $a0
	/* end block 1 */
	// End offset: 0x8003F02C
	// End Line: 115

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
    if ((&objectFunc)[iVar1].initFunc != (_func_4494 *)0x0) {
      (*(&objectFunc)[iVar1].initFunc)(instance,&gameTrackerX);
    }
  }
  instance->flags2 = instance->flags2 | 0x200000;
  if ((instance->flags & 0x100000U) == 0) {
    SCRIPT_InstanceSplineInit(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_GetInstanceCollideFunc(struct _Instance *instance /*$a0*/)
 // line 133, offset 0x8003f03c
	/* begin block 1 */
		// Start line: 135
		// Start offset: 0x8003F03C
		// Variables:
	// 		long id; // $a1
	/* end block 1 */
	// End offset: 0x8003F07C
	// End Line: 148

	/* begin block 2 */
		// Start line: 266
	/* end block 2 */
	// End Line: 267

	/* begin block 3 */
		// Start line: 267
	/* end block 3 */
	// End Line: 268

void OBTABLE_GetInstanceCollideFunc(_Instance *instance)

{
  int iVar1;
  
  iVar1 = (int)instance->object->id;
  if (-1 < iVar1) {
    *(_func_4496 **)&instance->collideFunc = (&objectFunc)[iVar1].collideFunc;
    return;
  }
  instance->collideFunc = GenericCollide;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_GetInstanceAdditionalCollideFunc(struct _Instance *instance /*$a0*/)
 // line 165, offset 0x8003f084
	/* begin block 1 */
		// Start line: 167
		// Start offset: 0x8003F084
		// Variables:
	// 		long id; // $a1
	/* end block 1 */
	// End offset: 0x8003F0BC
	// End Line: 179

	/* begin block 2 */
		// Start line: 330
	/* end block 2 */
	// End Line: 331

	/* begin block 3 */
		// Start line: 331
	/* end block 3 */
	// End Line: 332

void OBTABLE_GetInstanceAdditionalCollideFunc(_Instance *instance)

{
  int iVar1;
  
  iVar1 = (int)instance->object->id;
  if (-1 < iVar1) {
    *(_func_4499 **)&instance->additionalCollideFunc = (&objectFunc)[iVar1].additionalCollideFunc;
    return;
  }
  instance->additionalCollideFunc = (_func_4391 *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_GetInstanceProcessFunc(struct _Instance *instance /*$a0*/)
 // line 195, offset 0x8003f0c4
	/* begin block 1 */
		// Start line: 197
		// Start offset: 0x8003F0C4
		// Variables:
	// 		long id; // $a1
	/* end block 1 */
	// End offset: 0x8003F104
	// End Line: 209

	/* begin block 2 */
		// Start line: 390
	/* end block 2 */
	// End Line: 391

	/* begin block 3 */
		// Start line: 391
	/* end block 3 */
	// End Line: 392

void OBTABLE_GetInstanceProcessFunc(_Instance *instance)

{
  int iVar1;
  
  iVar1 = (int)instance->object->id;
  if (-1 < iVar1) {
    *(_func_4495 **)&instance->processFunc = (&objectFunc)[iVar1].processFunc;
    return;
  }
  instance->processFunc = GenericProcess;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_GetInstanceQueryFunc(struct _Instance *instance /*$a0*/)
 // line 225, offset 0x8003f10c
	/* begin block 1 */
		// Start line: 227
		// Start offset: 0x8003F10C
		// Variables:
	// 		long id; // $a1
	/* end block 1 */
	// End offset: 0x8003F14C
	// End Line: 239

	/* begin block 2 */
		// Start line: 450
	/* end block 2 */
	// End Line: 451

	/* begin block 3 */
		// Start line: 451
	/* end block 3 */
	// End Line: 452

void OBTABLE_GetInstanceQueryFunc(_Instance *instance)

{
  int iVar1;
  
  iVar1 = (int)instance->object->id;
  if (-1 < iVar1) {
    *(_func_4497 **)&instance->queryFunc = (&objectFunc)[iVar1].queryFunc;
    return;
  }
  instance->queryFunc = GenericQuery;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_GetInstanceMessageFunc(struct _Instance *instance /*$a0*/)
 // line 255, offset 0x8003f154
	/* begin block 1 */
		// Start line: 257
		// Start offset: 0x8003F154
		// Variables:
	// 		long id; // $a1
	/* end block 1 */
	// End offset: 0x8003F194
	// End Line: 269

	/* begin block 2 */
		// Start line: 510
	/* end block 2 */
	// End Line: 511

	/* begin block 3 */
		// Start line: 511
	/* end block 3 */
	// End Line: 512

void OBTABLE_GetInstanceMessageFunc(_Instance *instance)

{
  int iVar1;
  
  iVar1 = (int)instance->object->id;
  if (-1 < iVar1) {
    *(_func_4498 **)&instance->messageFunc = (&objectFunc)[iVar1].messageFunc;
    return;
  }
  instance->messageFunc = GenericMessage;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_InitObjectWithID(struct Object *object /*$s2*/)
 // line 272, offset 0x8003f19c
	/* begin block 1 */
		// Start line: 273
		// Start offset: 0x8003F19C
		// Variables:
	// 		long id; // $s1

		/* begin block 1.1 */
			// Start line: 278
			// Start offset: 0x8003F1BC
			// Variables:
		// 		struct ObjectAccess *oa; // $a0
		/* end block 1.1 */
		// End offset: 0x8003F358
		// End Line: 338
	/* end block 1 */
	// End offset: 0x8003F358
	// End Line: 339

	/* begin block 2 */
		// Start line: 544
	/* end block 2 */
	// End Line: 545

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
        iVar1 = strcmp(pOVar3->scriptName,object->script);
        if (iVar1 == 0) break;
        pOVar3 = pOVar3 + 1;
        iVar4 = iVar4 + 1;
      } while (pOVar3->scriptName != (char *)0x0);
LAB_8003f2bc:
      if ((&objectFunc)[iVar4].scriptName != (char *)0x0) {
        object->id = (short)iVar4;
        goto LAB_8003f2f8;
      }
    }
    else {
      iVar4 = 0;
      pOVar3 = &objectFunc;
      do {
        iVar1 = strcmp(pOVar3->scriptName,"monster_");
        if (iVar1 == 0) goto LAB_8003f2bc;
        pOVar3 = pOVar3 + 1;
        iVar4 = iVar4 + 1;
      } while (pOVar3->scriptName != (char *)0x0);
    }
  }
  else {
    iVar4 = 0;
    pOVar3 = &objectFunc;
    do {
      iVar1 = strcmp(pOVar3->scriptName,"physical");
      if (iVar1 == 0) goto LAB_8003f2bc;
      pOVar3 = pOVar3 + 1;
      iVar4 = iVar4 + 1;
    } while (pOVar3->scriptName != (char *)0x0);
  }
  object->id = -1;
LAB_8003f2f8:
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
 // line 361, offset 0x8003f374
	/* begin block 1 */
		// Start line: 363
		// Start offset: 0x8003F374
		// Variables:
	// 		struct ObjectAccess *oa; // $a0
	/* end block 1 */
	// End offset: 0x8003F3A0
	// End Line: 367

	/* begin block 2 */
		// Start line: 739
	/* end block 2 */
	// End Line: 740

	/* begin block 3 */
		// Start line: 740
	/* end block 3 */
	// End Line: 741

	/* begin block 4 */
		// Start line: 742
	/* end block 4 */
	// End Line: 743

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
 // line 369, offset 0x8003f3a8
	/* begin block 1 */
		// Start line: 371
		// Start offset: 0x8003F3A8
		// Variables:
	// 		struct ObjectAccess *oa; // $a1
	/* end block 1 */
	// End offset: 0x8003F3E8
	// End Line: 381

	/* begin block 2 */
		// Start line: 756
	/* end block 2 */
	// End Line: 757

	/* begin block 3 */
		// Start line: 757
	/* end block 3 */
	// End Line: 758

	/* begin block 4 */
		// Start line: 759
	/* end block 4 */
	// End Line: 760

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
 // line 383, offset 0x8003f3f0
	/* begin block 1 */
		// Start line: 384
		// Start offset: 0x8003F3F0
		// Variables:
	// 		struct Object *object; // $s0
	// 		struct _ObjectTracker *otr; // $v0
	// 		int i; // $s2
	/* end block 1 */
	// End offset: 0x8003F480
	// End Line: 401

	/* begin block 2 */
		// Start line: 789
	/* end block 2 */
	// End Line: 790

	/* begin block 3 */
		// Start line: 794
	/* end block 3 */
	// End Line: 795

Object * OBTABLE_FindObject(char *objectName)

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
      lVar1 = MEMPACK_MemoryValidFunc((char *)address);
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
 // line 403, offset 0x8003f49c
	/* begin block 1 */
		// Start line: 405
		// Start offset: 0x8003F49C
		// Variables:
	// 		struct ObjectAccess *oa; // $a2
	/* end block 1 */
	// End offset: 0x8003F4DC
	// End Line: 415

	/* begin block 2 */
		// Start line: 846
	/* end block 2 */
	// End Line: 847

	/* begin block 3 */
		// Start line: 847
	/* end block 3 */
	// End Line: 848

	/* begin block 4 */
		// Start line: 849
	/* end block 4 */
	// End Line: 850

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
 // line 417, offset 0x8003f4e4
	/* begin block 1 */
		// Start line: 418
		// Start offset: 0x8003F4E4
		// Variables:
	// 		long id; // $a2
	/* end block 1 */
	// End offset: 0x8003F528
	// End Line: 429

	/* begin block 2 */
		// Start line: 879
	/* end block 2 */
	// End Line: 880

void OBTABLE_RelocateObjectTune(Object *object,long offset)

{
  if ((-1 < (int)object->id) &&
     ((&objectFunc)[(int)object->id].relocateTuneFunc != (_func_4500 *)0x0)) {
    (*(&objectFunc)[(int)object->id].relocateTuneFunc)();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_RelocateInstanceObject(struct _Instance *instance /*$a0*/, long offset /*$a1*/)
 // line 431, offset 0x8003f538
	/* begin block 1 */
		// Start line: 432
		// Start offset: 0x8003F538
		// Variables:
	// 		long id; // $a2
	/* end block 1 */
	// End offset: 0x8003F584
	// End Line: 443

	/* begin block 2 */
		// Start line: 907
	/* end block 2 */
	// End Line: 908

void OBTABLE_RelocateInstanceObject(_Instance *instance,long offset)

{
  int iVar1;
  
  iVar1 = (int)instance->object->id;
  if ((-1 < iVar1) && ((&objectFunc)[iVar1].relocateInstObFunc != (_func_4501 *)0x0)) {
    (*(&objectFunc)[iVar1].relocateInstObFunc)();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OBTABLE_InitAnimPointers(struct _ObjectTracker *objectTracker /*$s5*/)
 // line 445, offset 0x8003f594
	/* begin block 1 */
		// Start line: 446
		// Start offset: 0x8003F594
		// Variables:
	// 		struct Object *object; // $s3

		/* begin block 1.1 */
			// Start line: 451
			// Start offset: 0x8003F5D4
			// Variables:
		// 		int i; // $s2
		// 		char *earlyOut; // $s4
		// 		struct _G2AnimKeylist_Type **keyPtr; // $s1

			/* begin block 1.1.1 */
				// Start line: 457
				// Start offset: 0x8003F5E4
				// Variables:
			// 		struct _ObjectOwnerInfo *oi; // $s0

				/* begin block 1.1.1.1 */
					// Start line: 461
					// Start offset: 0x8003F5FC
					// Variables:
				// 		struct _ObjectTracker *otr; // $a2
				// 		struct Object *ownerOb; // $a3
				// 		int j; // $a1
				// 		int objectIndex; // $a0
				/* end block 1.1.1.1 */
				// End offset: 0x8003F6CC
				// End Line: 488
			/* end block 1.1.1 */
			// End offset: 0x8003F6CC
			// End Line: 489
		/* end block 1.1 */
		// End offset: 0x8003F6F0
		// End Line: 498
	/* end block 1 */
	// End offset: 0x8003F70C
	// End Line: 505

	/* begin block 2 */
		// Start line: 935
	/* end block 2 */
	// End Line: 936

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





