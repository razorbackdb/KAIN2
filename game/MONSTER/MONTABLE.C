#include "THISDUST.H"
#include "MONTABLE.H"

void MONTABLE_SetupTablePointer(Object *object)

{
	int iVar1;
	MONTABLE_202fake *pMVar2;
	int iVar3;

	iVar3 = *(int *)((int)object->data + 0x10);
	pMVar2 = &functionChoiceTable;
	iVar1 = 0x42;
	do
	{
		if (iVar3 == iVar1)
		{
			*(_MonsterFunctionTable **)&object->relocModule = pMVar2->table;
		}
		pMVar2 = pMVar2 + 1;
		iVar1 = pMVar2->whatAmI;
	} while (iVar1 != 0);
	return;
}

_MonsterState *MON_DamageEffect(_Instance *instance, int state)

{
	void *pvVar1;
	int iVar2;
	int *piVar3;

	pvVar1 = instance->object->relocModule;
	if (pvVar1 != (void *)0x0)
	{
		piVar3 = *(int **)((int)pvVar1 + 0x14);
		iVar2 = *piVar3;
		while (iVar2 != -1)
		{
			if (state == *piVar3)
			{
				return (_MonsterState *)(piVar3 + 1);
			}
			piVar3 = piVar3 + 3;
			iVar2 = *piVar3;
		}
	}
	return &DefaultStateTable + state;
}

TDRFuncPtr_MONTABLE_GetDamageEffectFunc MONTABLE_GetStateFuncs(_Instance *instance)

{
	void *pvVar1;
	code *pcVar2;

	pvVar1 = instance->object->relocModule;
	if ((pvVar1 == (void *)0x0) ||
		(pcVar2 = *(TDRFuncPtr_MONTABLE_GetDamageEffectFunc *)((int)pvVar1 + 8),
		 pcVar2 == (TDRFuncPtr_MONTABLE_GetDamageEffectFunc)0x0))
	{
		pcVar2 = SLUAGH_DamageEffect;
	}
	return pcVar2;
}

TDRFuncPtr_MONTABLE_GetInitFunc MONTABLE_GetInitFunc(_Instance *instance)

{
	TDRFuncPtr_MONTABLE_GetInitFunc *ppTVar1;
	code *pcVar2;

	ppTVar1 = (TDRFuncPtr_MONTABLE_GetInitFunc *)instance->object->relocModule;
	if ((ppTVar1 == (TDRFuncPtr_MONTABLE_GetInitFunc *)0x0) ||
		(pcVar2 = *ppTVar1, pcVar2 == (TDRFuncPtr_MONTABLE_GetInitFunc)0x0))
	{
		pcVar2 = MON_SetDefaults;
	}
	return pcVar2;
}

TDRFuncPtr_MONTABLE_GetCleanUpFunc MONTABLE_GetDamageEffectFunc(_Instance *instance)

{
	void *pvVar1;
	code *pcVar2;

	pvVar1 = instance->object->relocModule;
	if ((pvVar1 == (void *)0x0) ||
		(pcVar2 = *(TDRFuncPtr_MONTABLE_GetCleanUpFunc *)((int)pvVar1 + 4),
		 pcVar2 == (TDRFuncPtr_MONTABLE_GetCleanUpFunc)0x0))
	{
		pcVar2 = HUMAN_CleanUp;
	}
	return pcVar2;
}

void MONTABLE_SetQueryFunc(_Instance *instance)

{
	void *pvVar1;
	_func_4 *p_Var2;

	pvVar1 = instance->object->relocModule;
	if ((pvVar1 != (void *)0x0) &&
		(p_Var2 = *(_func_4 **)((int)pvVar1 + 0xc), p_Var2 != (_func_4 *)0x0))
	{
		instance->queryFunc = p_Var2;
	}
	return;
}

void MONTABLE_SetMessageFunc(_Instance *instance)

{
	void *pvVar1;
	_func_5 *p_Var2;

	pvVar1 = instance->object->relocModule;
	if ((pvVar1 != (void *)0x0) &&
		(p_Var2 = *(_func_5 **)((int)pvVar1 + 0x10), p_Var2 != (_func_5 *)0x0))
	{
		instance->messageFunc = p_Var2;
	}
	return;
}
