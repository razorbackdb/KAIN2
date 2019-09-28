#include "THISDUST.H"
#include "OBTABLE.H"

// decompiled code
// original method signature:
// void /*$ra*/ OBTABLE_InstanceInit(struct _Instance *instance /*$s0*/)
// line 88, offset 0x8003d9ac
/* begin block 1 */
// Start line: 89
// Start offset: 0x8003D9AC
// Variables:
// 		long id; // $a0
/* end block 1 */
// End offset: 0x8003DA80
// End Line: 126

/* begin block 2 */
// Start line: 176
/* end block 2 */
// End Line: 177

void OBTABLE_InstanceInit(_Instance *instance)

{
	code *pcVar1;
	int iVar2;

	iVar2 = (int)instance->object->id;
	if (iVar2 < 0)
	{
		GenericInit(instance, (GameTracker *)&gameTrackerX);
	}
	else
	{
		pcVar1 = *(code **)((int)&debugGlyphAbilitiesMenu + iVar2 * 0x24 + 8);
		if (pcVar1 != (code *)0x0)
		{
			(*pcVar1)(instance, &gameTrackerX);
		}
	}
	instance->flags2 = instance->flags2 | 0x200000;
	if ((instance->flags & 0x100000U) == 0)
	{
		SCRIPT_InstanceSplineInit(instance);
	}
	if ((instance->intro != (Intro *)0x0) && ((instance->intro->flags & 0x20U) != 0))
	{
		instance->flags2 = instance->flags2 & 0xfffdfffb;
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ OBTABLE_GetInstanceCollideFunc(struct _Instance *instance /*$a0*/)
// line 144, offset 0x8003da90
/* begin block 1 */
// Start line: 146
// Start offset: 0x8003DA90
// Variables:
// 		long id; // $a1
/* end block 1 */
// End offset: 0x8003DAD0
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
	if (-1 < iVar1)
	{
		instance->collideFunc = *(_func_2 **)((int)&debugGlyphAbilitiesMenu + iVar1 * 0x24 + 0x10);
		return;
	}
	instance->collideFunc = GenericCollide;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ OBTABLE_GetInstanceAdditionalCollideFunc(struct _Instance *instance /*$a0*/)
// line 176, offset 0x8003dad8
/* begin block 1 */
// Start line: 178
// Start offset: 0x8003DAD8
// Variables:
// 		long id; // $a1
/* end block 1 */
// End offset: 0x8003DB10
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
	if (-1 < iVar1)
	{
		instance->additionalCollideFunc = *(_func_3 **)((int)&DebugMenuLine_800c8870 + iVar1 * 0x24 + 4);
		return;
	}
	instance->additionalCollideFunc = (_func_3 *)0x0;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ OBTABLE_GetInstanceProcessFunc(struct _Instance *instance /*$a0*/)
// line 206, offset 0x8003db18
/* begin block 1 */
// Start line: 208
// Start offset: 0x8003DB18
// Variables:
// 		long id; // $a1
/* end block 1 */
// End offset: 0x8003DB58
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
	if (-1 < iVar1)
	{
		instance->processFunc = *(_func_1 **)((int)&debugGlyphAbilitiesMenu + iVar1 * 0x24 + 0xc);
		return;
	}
	instance->processFunc = GenericProcess;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ OBTABLE_GetInstanceQueryFunc(struct _Instance *instance /*$a0*/)
// line 236, offset 0x8003db60
/* begin block 1 */
// Start line: 238
// Start offset: 0x8003DB60
// Variables:
// 		long id; // $a1
/* end block 1 */
// End offset: 0x8003DBA0
// End Line: 250

/* begin block 2 */
// Start line: 473
/* end block 2 */
// End Line: 474

/* begin block 3 */
// Start line: 474
/* end block 3 */
// End Line: 475

void OBTABLE_GetInstanceQueryFunc(_Instance *instance)

{
	int iVar1;

	iVar1 = (int)instance->object->id;
	if (-1 < iVar1)
	{
		instance->queryFunc = *(_func_4 **)((int)&debugGlyphAbilitiesMenu + iVar1 * 0x24 + 0x14);
		return;
	}
	instance->queryFunc = GenericQuery;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ OBTABLE_GetInstanceMessageFunc(struct _Instance *instance /*$a0*/)
// line 266, offset 0x8003dba8
/* begin block 1 */
// Start line: 268
// Start offset: 0x8003DBA8
// Variables:
// 		long id; // $a1
/* end block 1 */
// End offset: 0x8003DBE8
// End Line: 280

/* begin block 2 */
// Start line: 533
/* end block 2 */
// End Line: 534

/* begin block 3 */
// Start line: 534
/* end block 3 */
// End Line: 535

void OBTABLE_GetInstanceMessageFunc(_Instance *instance)

{
	int iVar1;

	iVar1 = (int)instance->object->id;
	if (-1 < iVar1)
	{
		instance->messageFunc =
			(_func_5 *)((DebugMenuLine *)((int)&DebugMenuLine_800c8870 + iVar1 * 0x24))->type;
		return;
	}
	instance->messageFunc = GenericMessage;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ OBTABLE_InitObjectWithID(struct Object *object /*$s2*/)
// line 283, offset 0x8003dbf0
/* begin block 1 */
// Start line: 284
// Start offset: 0x8003DBF0
// Variables:
// 		long id; // $s1

/* begin block 1.1 */
// Start line: 289
// Start offset: 0x8003DC10
// Variables:
// 		struct ObjectAccess *oa; // $a0
/* end block 1.1 */
// End offset: 0x8003DDAC
// End Line: 349
/* end block 1 */
// End offset: 0x8003DDAC
// End Line: 350

/* begin block 2 */
// Start line: 567
/* end block 2 */
// End Line: 568

void OBTABLE_InitObjectWithID(int *param_1)

{
	int iVar1;
	int **ppiVar2;
	char **ppcVar3;
	int iVar4;

	if (param_1 == (int *)0x0)
	{
		return;
	}
	if ((param_1[0xb] & 0x40000U) == 0)
	{
		if ((param_1[0xb] & 0x80000U) == 0)
		{
			iVar4 = 0;
			if (debugGlyphAbilitiesMenu.lower != 0)
			{
				ppcVar3 = (char **)&debugGlyphAbilitiesMenu.lower;
				do
				{
					iVar1 = strcmp(*ppcVar3, (char *)param_1[8]);
					if (iVar1 == 0)
						break;
					ppcVar3 = ppcVar3 + 9;
					iVar4 = iVar4 + 1;
				} while (*ppcVar3 != (char *)0x0);
			LAB_8003dd10:
				if (*(int *)((int)&debugGlyphAbilitiesMenu + iVar4 * 0x24 + 4) != 0)
				{
					*(short *)(param_1 + 1) = (short)iVar4;
					goto LAB_8003dd4c;
				}
			}
		}
		else
		{
			iVar4 = 0;
			if (debugGlyphAbilitiesMenu.lower != 0)
			{
				ppcVar3 = (char **)&debugGlyphAbilitiesMenu.lower;
				do
				{
					iVar1 = strcmp(*ppcVar3, CD_intstr);
					if (iVar1 == 0)
						goto LAB_8003dd10;
					ppcVar3 = ppcVar3 + 9;
					iVar4 = iVar4 + 1;
				} while (*ppcVar3 != (char *)0x0);
			}
		}
	}
	else
	{
		iVar4 = 0;
		if (debugGlyphAbilitiesMenu.lower != 0)
		{
			ppcVar3 = (char **)&debugGlyphAbilitiesMenu.lower;
			do
			{
				iVar1 = strcmp(*ppcVar3, s_physical_800cea1c);
				if (iVar1 == 0)
					goto LAB_8003dd10;
				ppcVar3 = ppcVar3 + 9;
				iVar4 = iVar4 + 1;
			} while (*ppcVar3 != (char *)0x0);
		}
	}
	*(undefined2 *)(param_1 + 1) = 0xffff;
LAB_8003dd4c:
	ppiVar2 = (int **)&selectMenuText5.bit_mask;
	if (selectMenuText5.bit_mask != 0)
	{
		do
		{
			if ((**ppiVar2 == *(int *)param_1[9]) && ((*ppiVar2)[1] == ((int *)param_1[9])[1]))
			{
				ppiVar2[1] = param_1;
				return;
			}
			ppiVar2 = ppiVar2 + 2;
		} while (*ppiVar2 != (int *)0x0);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ OBTABLE_ClearObjectReferences()
// line 372, offset 0x8003ddc8
/* begin block 1 */
// Start line: 374
// Start offset: 0x8003DDC8
// Variables:
// 		struct ObjectAccess *oa; // $a0
/* end block 1 */
// End offset: 0x8003DDF4
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
	long *plVar1;

	plVar1 = &selectMenuText5.bit_mask;
	if (selectMenuText5.bit_mask != 0)
	{
		do
		{
			plVar1[1] = 0;
			plVar1 = plVar1 + 2;
		} while (*plVar1 != 0);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ OBTABLE_RemoveObjectEntry(struct Object *object /*$a0*/)
// line 380, offset 0x8003ddfc
/* begin block 1 */
// Start line: 382
// Start offset: 0x8003DDFC
// Variables:
// 		struct ObjectAccess *oa; // $a1
/* end block 1 */
// End offset: 0x8003DE3C
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
	DebugMenuLine *pDVar1;
	long *plVar2;

	plVar2 = &selectMenuText5.bit_mask;
	if (selectMenuText5.bit_mask != 0)
	{
		pDVar1 = &DebugMenuLine_800c8780;
		do
		{
			plVar2 = plVar2 + 2;
			if ((Object *)pDVar1->type == object)
			{
				pDVar1->type = DEBUG_LINE_TYPE_BIT;
				return;
			}
			pDVar1 = (DebugMenuLine *)&pDVar1->upper;
		} while (*plVar2 != 0);
	}
	return;
}

// decompiled code
// original method signature:
// struct Object * /*$ra*/ OBTABLE_FindObject(char *objectName /*$s3*/)
// line 394, offset 0x8003de44
/* begin block 1 */
// Start line: 395
// Start offset: 0x8003DE44
// Variables:
// 		struct Object *object; // $s0
// 		struct _ObjectTracker *otr; // $v0
// 		int i; // $s2
/* end block 1 */
// End offset: 0x8003DED4
// End Line: 412

/* begin block 2 */
// Start line: 812
/* end block 2 */
// End Line: 813

/* begin block 3 */
// Start line: 817
/* end block 3 */
// End Line: 818

Object *OBTABLE_FindObject(char *objectName)

{
	long lVar1;
	Object *address;
	Object **ppOVar2;
	int iVar3;

	iVar3 = 0x30;
	ppOVar2 = (Object **)(DAT_800d0ff0 + 0x10);
	do
	{
		if (*(short *)(ppOVar2 + 1) != 0)
		{
			address = *ppOVar2;
			lVar1 = MEMPACK_MemoryValidFunc((char *)address);
			if (((lVar1 != 0) && (*(int *)objectName == *(int *)address->name)) &&
				(*(int *)(objectName + 4) == *(int *)(address->name + 1)))
			{
				return address;
			}
		}
		iVar3 = iVar3 + -1;
		ppOVar2 = ppOVar2 + 9;
		if (iVar3 == 0)
		{
			return (Object *)0x0;
		}
	} while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ OBTABLE_ChangeObjectAccessPointers(struct Object *oldObject /*$a0*/, struct Object *newObject /*$a1*/)
// line 414, offset 0x8003def0
/* begin block 1 */
// Start line: 416
// Start offset: 0x8003DEF0
// Variables:
// 		struct ObjectAccess *oa; // $a2
/* end block 1 */
// End offset: 0x8003DF30
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

void OBTABLE_ChangeObjectAccessPointers(Object *oldObject, Object *newObject)

{
	DebugMenuLine *pDVar1;
	long *plVar2;

	plVar2 = &selectMenuText5.bit_mask;
	if (selectMenuText5.bit_mask != 0)
	{
		pDVar1 = &DebugMenuLine_800c8780;
		do
		{
			plVar2 = plVar2 + 2;
			if ((Object *)pDVar1->type == oldObject)
			{
				*(Object **)&pDVar1->type = newObject;
				return;
			}
			pDVar1 = (DebugMenuLine *)&pDVar1->upper;
		} while (*plVar2 != 0);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ OBTABLE_RelocateObjectTune(struct Object *object /*$a0*/, long offset /*$a1*/)
// line 428, offset 0x8003df38
/* begin block 1 */
// Start line: 429
// Start offset: 0x8003DF38
// Variables:
// 		long id; // $a2

/* begin block 1.1 */
// Start line: 442
// Start offset: 0x8003DF84
/* end block 1.1 */
// End offset: 0x8003DF8C
// End Line: 444
/* end block 1 */
// End offset: 0x8003DF8C
// End Line: 445

/* begin block 2 */
// Start line: 902
/* end block 2 */
// End Line: 903

void OBTABLE_RelocateObjectTune(Object *object, long offset)

{
	code *pcVar1;

	if ((int)object->id < 0)
	{
		GenericRelocateTune(object, offset);
	}
	else
	{
		pcVar1 = *(code **)((int)&DebugMenuLine_800c8870 + (int)object->id * 0x24 + 8);
		if (pcVar1 != (code *)0x0)
		{
			(*pcVar1)();
		}
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ OBTABLE_RelocateInstanceObject(struct _Instance *instance /*$a0*/, long offset /*$a1*/)
// line 447, offset 0x8003df9c
/* begin block 1 */
// Start line: 448
// Start offset: 0x8003DF9C
// Variables:
// 		long id; // $a2
/* end block 1 */
// End offset: 0x8003DFE8
// End Line: 459

/* begin block 2 */
// Start line: 940
/* end block 2 */
// End Line: 941

void OBTABLE_RelocateInstanceObject(_Instance *instance, long offset)

{
	code *pcVar1;
	int iVar2;

	iVar2 = (int)instance->object->id;
	if ((-1 < iVar2) &&
		(pcVar1 = *(code **)((int)&DebugMenuLine_800c8870 + iVar2 * 0x24 + 0xc), pcVar1 != (code *)0x0))
	{
		(*pcVar1)();
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ OBTABLE_InitAnimPointers(struct _ObjectTracker *objectTracker /*$s5*/)
// line 461, offset 0x8003dff8
/* begin block 1 */
// Start line: 462
// Start offset: 0x8003DFF8
// Variables:
// 		struct Object *object; // $s3

/* begin block 1.1 */
// Start line: 467
// Start offset: 0x8003E038
// Variables:
// 		int i; // $s2
// 		char *earlyOut; // $s4
// 		struct _G2AnimKeylist_Type **keyPtr; // $s1

/* begin block 1.1.1 */
// Start line: 473
// Start offset: 0x8003E048
// Variables:
// 		struct _ObjectOwnerInfo *oi; // $s0

/* begin block 1.1.1.1 */
// Start line: 477
// Start offset: 0x8003E060
// Variables:
// 		struct _ObjectTracker *otr; // $a2
// 		struct Object *ownerOb; // $a3
// 		int j; // $a1
// 		int objectIndex; // $a0
/* end block 1.1.1.1 */
// End offset: 0x8003E130
// End Line: 504
/* end block 1.1.1 */
// End offset: 0x8003E130
// End Line: 505
/* end block 1.1 */
// End offset: 0x8003E154
// End Line: 514
/* end block 1 */
// End offset: 0x8003E170
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
	if ((object->oflags2 & 0x10000000U) != 0)
	{
		iVar9 = (int)object->numAnims;
		p_Var8 = (_G2AnimKeylist_Type *)object->animList;
		psVar10 = (short *)0x0;
		while (iVar9 != 0)
		{
			p_Var7 = *(_G2AnimKeylist_Type **)p_Var8;
			if ((*(int *)p_Var7 == 0xface0ff) &&
				(p_Var1 = STREAM_GetObjectTracker((char *)&p_Var7->timePerKey),
				 p_Var1 != (_ObjectTracker *)0x0))
			{
				iVar4 = (int)((int)objectTracker - DAT_800d0ff0) * 0x38e38e39 >> 2;
				iVar2 = (int)p_Var1->numObjectsUsing;
				pOVar6 = p_Var1->object;
				iVar5 = 0;
				p_Var3 = p_Var1;
				if (0 < iVar2)
				{
					do
					{
						if ((int)p_Var3->objectsUsing[0] == iVar4)
							break;
						iVar5 = iVar5 + 1;
						p_Var3 = (_ObjectTracker *)(p_Var1->name + iVar5);
					} while (iVar5 < iVar2);
					iVar2 = (int)p_Var1->numObjectsUsing;
				}
				if (iVar5 == iVar2)
				{
					p_Var1->numObjectsUsing = p_Var1->numObjectsUsing + '\x01';
					p_Var1->objectsUsing[iVar5] = (char)iVar4;
				}
				if (p_Var1->objectStatus == 2)
				{
					*(_G2AnimKeylist_Type **)p_Var8 = pOVar6->animList[(short)p_Var7->keyCount];
				}
				else
				{
					psVar10 = &p_Var7->timePerKey;
				}
			}
			iVar9 = iVar9 + -1;
			p_Var8 = (_G2AnimKeylist_Type *)&p_Var8->keyCount;
		}
		if (psVar10 != (short *)0x0)
		{
			return;
		}
		object->oflags2 = object->oflags2 & 0xefffffff;
	}
	if ((object->oflags2 & 0x80000U) != 0)
	{
		MonsterTranslateAnim(object);
	}
	return;
}
