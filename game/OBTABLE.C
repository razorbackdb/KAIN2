#include "THISDUST.H"
#include "OBTABLE.H"

void OBTABLE_InstanceInit(_Instance *instance)

{
	int iVar1;

	iVar1 = (int)instance->object->id;
	if (iVar1 < 0)
	{
		GenericInit(instance, &gameTrackerX);
	}
	else
	{
		if ((&objectFunc)[iVar1].initFunc != (_func_24 *)0x0)
		{
			(*(&objectFunc)[iVar1].initFunc)(instance, &gameTrackerX);
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

void OBTABLE_GetInstanceCollideFunc(_Instance *instance)

{
	int iVar1;

	iVar1 = (int)instance->object->id;
	if (-1 < iVar1)
	{
		*(_func_26 **)&instance->collideFunc = (&objectFunc)[iVar1].collideFunc;
		return;
	}
	instance->collideFunc = GenericCollide;
	return;
}

void OBTABLE_GetInstanceAdditionalCollideFunc(_Instance *instance)

{
	int iVar1;

	iVar1 = (int)instance->object->id;
	if (-1 < iVar1)
	{
		*(_func_29 **)&instance->additionalCollideFunc = (&objectFunc)[iVar1].additionalCollideFunc;
		return;
	}
	instance->additionalCollideFunc = (_func_3 *)0x0;
	return;
}

void OBTABLE_GetInstanceProcessFunc(_Instance *instance)

{
	int iVar1;

	iVar1 = (int)instance->object->id;
	if (-1 < iVar1)
	{
		*(_func_25 **)&instance->processFunc = (&objectFunc)[iVar1].processFunc;
		return;
	}
	instance->processFunc = _GlyphGenericProcess;
	return;
}

void OBTABLE_GetInstanceMessageFunc(_Instance *instance)

{
	int iVar1;

	iVar1 = (int)instance->object->id;
	if (-1 < iVar1)
	{
		*(_func_27 **)&instance->queryFunc = (&objectFunc)[iVar1].queryFunc;
		return;
	}
	instance->queryFunc = GenericQuery;
	return;
}

void OBTABLE_GetInstanceQueryFunc(_Instance *instance)

{
	int iVar1;

	iVar1 = (int)instance->object->id;
	if (-1 < iVar1)
	{
		*(_func_28 **)&instance->messageFunc = (&objectFunc)[iVar1].messageFunc;
		return;
	}
	instance->messageFunc = GenericMessage;
	return;
}

void OBTABLE_InitObjectWithID(Object *object)

{
	int iVar1;
	ObjectAccess *pOVar2;
	ObjectFunc *pOVar3;
	int iVar4;

	if (object == (Object *)0x0)
	{
		return;
	}
	if ((object->oflags2 & 0x40000U) == 0)
	{
		if ((object->oflags2 & 0x80000U) == 0)
		{
			iVar4 = 0;
			pOVar3 = &objectFunc;
			do
			{
				iVar1 = strcmpi(pOVar3->scriptName, object->script);
				if (iVar1 == 0)
					break;
				pOVar3 = pOVar3 + 1;
				iVar4 = iVar4 + 1;
			} while (pOVar3->scriptName != (char *)0x0);
		LAB_8003e87c:
			if ((&objectFunc)[iVar4].scriptName != (char *)0x0)
			{
				object->id = (short)iVar4;
				goto LAB_8003e8b8;
			}
		}
		else
		{
			iVar4 = 0;
			pOVar3 = &objectFunc;
			do
			{
				iVar1 = strcmpi(pOVar3->scriptName, "monster_");
				if (iVar1 == 0)
					goto LAB_8003e87c;
				pOVar3 = pOVar3 + 1;
				iVar4 = iVar4 + 1;
			} while (pOVar3->scriptName != (char *)0x0);
		}
	}
	else
	{
		iVar4 = 0;
		pOVar3 = &objectFunc;
		do
		{
			iVar1 = strcmpi(pOVar3->scriptName, "physical");
			if (iVar1 == 0)
				goto LAB_8003e87c;
			pOVar3 = pOVar3 + 1;
			iVar4 = iVar4 + 1;
		} while (pOVar3->scriptName != (char *)0x0);
	}
	object->id = -1;
LAB_8003e8b8:
	pOVar2 = &objectAccess;
	while ((*(int *)pOVar2->objectName != *(int *)object->name ||
			(*(int *)(pOVar2->objectName + 1) != *(int *)(object->name + 1))))
	{
		pOVar2 = pOVar2 + 1;
		if (pOVar2->objectName == (char *)0x0)
		{
			return;
		}
	}
	*(Object **)&pOVar2->object = object;
	return;
}

void OBTABLE_ClearObjectReferences(void)

{
	ObjectAccess *pOVar1;

	pOVar1 = &objectAccess;
	do
	{
		pOVar1->object = (void *)0x0;
		pOVar1 = pOVar1 + 1;
	} while (pOVar1->objectName != (char *)0x0);
	return;
}

void OBTABLE_RemoveObjectEntry(Object *object)

{
	Object **ppOVar1;
	ObjectAccess *pOVar2;

	pOVar2 = &objectAccess;
	ppOVar1 = (Object **)&objectAccess.object;
	do
	{
		pOVar2 = pOVar2 + 1;
		if (*ppOVar1 == object)
		{
			*ppOVar1 = (Object *)0x0;
			return;
		}
		ppOVar1 = ppOVar1 + 2;
	} while (pOVar2->objectName != (char *)0x0);
	return;
}

Object *OBTABLE_RelocateObjectTune(char *objectName)

{
	long lVar1;
	Object *address;
	Object **ppOVar2;
	int iVar3;

	iVar3 = 0x30;
	ppOVar2 = &(gameTrackerX.GlobalObjects)->object;
	do
	{
		if (*(short *)(ppOVar2 + 1) != 0)
		{
			address = *ppOVar2;
			lVar1 = MEMPACK_ReportMemory((char *)address);
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

void OBTABLE_ChangeObjectAccessPointers(Object *oldObject, Object *newObject)

{
	Object **ppOVar1;
	ObjectAccess *pOVar2;

	pOVar2 = &objectAccess;
	ppOVar1 = (Object **)&objectAccess.object;
	do
	{
		pOVar2 = pOVar2 + 1;
		if (*ppOVar1 == oldObject)
		{
			*ppOVar1 = newObject;
			return;
		}
		ppOVar1 = ppOVar1 + 2;
	} while (pOVar2->objectName != (char *)0x0);
	return;
}

void OBTABLE_RelocateObjectTune(Object *object, long offset)

{
	if ((int)object->id < 0)
	{
		GenericRelocateTune(object, offset);
	}
	else
	{
		if ((&objectFunc)[(int)object->id].relocateTuneFunc != (_func_30 *)0x0)
		{
			(*(&objectFunc)[(int)object->id].relocateTuneFunc)();
		}
	}
	return;
}

void STREAM_RelocateInstance(_Instance *instance, long offset)

{
	int iVar1;

	iVar1 = (int)instance->object->id;
	if ((-1 < iVar1) && ((&objectFunc)[iVar1].relocateInstObFunc != (_func_31 *)0x0))
	{
		(*(&objectFunc)[iVar1].relocateInstObFunc)();
	}
	return;
}

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
				iVar4 = (int)((int)objectTracker - (int)gameTrackerX.GlobalObjects) * 0x38e38e39 >> 2;
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
