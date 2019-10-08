#include "THISDUST.H"
#include "MISSILE.H"

void MISSILE_Process(_Instance *instance, GameTracker *gameTracker)

{
	u_long uVar1;

	PhysicalObjectQuery(instance, gameTracker);
	if ((instance->LinkParent == (_Instance *)0x0) &&
		(uVar1 = MON_GetAnim(instance), (u_int)instance->work2 < uVar1))
	{
		INSTANCE_NewInstance(instance);
	}
	return;
}

void MISSILE_Collide(_Instance *instance, GameTracker *gameTracker)

{
	InitPhysicalObject(instance, gameTracker);
	if (instance->LinkParent == (_Instance *)0x0)
	{
		INSTANCE_NewInstance(instance);
	}
	return;
}

_Instance *MISSILE_Find(_Instance *instance, _MonsterMissile *missiledef)

{
	_Instance *p_Var1;

	p_Var1 = instance->LinkChild;
	if (p_Var1 != (_Instance *)0x0)
	{
		do
		{
			if ((p_Var1->ParentLinkNode == (u_int)missiledef->segment) &&
				(p_Var1->object ==
				 (Object *)(&objectAccess)[(&MISSILE_objectTable)[missiledef->graphic].object].object))
			{
				return p_Var1;
			}
			p_Var1 = p_Var1->LinkSibling;
		} while (p_Var1 != (_Instance *)0x0);
	}
	return (_Instance *)0x0;
}

_Instance *MISSILE_Process(_Instance *instance, _MonsterMissile *missiledef)

{
	_Instance *p_Var1;
	evObjectBirthProjectileData *peVar2;
	MATRIX *pMVar3;

	if ((missiledef->type == '\x03') &&
		(p_Var1 = MISSILE_Find(instance, missiledef), p_Var1 != (_Instance *)0x0))
	{
		p_Var1->processFunc = MISSILE_Process;
		p_Var1->collideFunc = MISSILE_Collide;
	}
	else
	{
		peVar2 = PHYSOB_BirthCollectible(instance, (u_int)missiledef->segment, (u_int)missiledef->graphic);
		p_Var1 = peVar2->birthInstance;
		if (p_Var1 != (_Instance *)0x0)
		{
			p_Var1->processFunc = MISSILE_Process;
			if (instance->matrix != (MATRIX *)0x0)
			{
				pMVar3 = instance->matrix + missiledef->segment;
				(p_Var1->position).x = *(short *)pMVar3->t;
				(p_Var1->position).y = *(short *)(pMVar3->t + 1);
				(p_Var1->position).z = *(short *)(pMVar3->t + 2);
			}
		}
	}
	return p_Var1;
}

_Instance *MISSILE_Fire(_Instance *instance, _MonsterMissile *missiledef, void *target, int type)

{
	_Instance *Inst;
	int Data;
	u_long uVar1;
	u_short spinType;
	_SVector local_20;

	Inst = MISSILE_Process(instance, missiledef);
	if (Inst != (_Instance *)0x0)
	{
		spinType = 1;
		if (missiledef->type == '\x03')
		{
			spinType = 2;
			local_20.x = 0x111;
			local_20.y = 0;
			local_20.z = 0;
		}
		Data = SetObjectData(target, &local_20, (u_short)type, spinType, (u_int)missiledef->speed, 0, 0, 0);
		INSTANCE_Query(Inst, 0x800010, Data);
		uVar1 = MON_GetAnim(Inst);
		*(undefined **)&Inst->work2 = &DAT_00001388 + uVar1;
	}
	return Inst;
}

_Instance *MISSILE_Birth(_Instance *instance, _MonsterMissile *missiledef, _Instance *target)

{
	_Instance *p_Var1;

	p_Var1 = MISSILE_Fire(instance, missiledef, target, 1);
	return p_Var1;
}
