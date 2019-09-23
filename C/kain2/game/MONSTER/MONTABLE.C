#include "THISDUST.H"
#include "MONTABLE.H"

// _MonsterFunctionTable @0x800CF68C, len = 0x00000020
DefaultFunctionTable =
	{
		// _func_96 * @0x800CF68C, len = 0x00000004
		.initFunc = &MON_DefaultInit,
		// _func_97 * @0x800CF690, len = 0x00000004
		.cleanUpFunc = &MON_CleanUp,
		// _func_98 * @0x800CF694, len = 0x00000004
		.damageEffectFunc = &MON_DamageEffect,
		// _func_99 * @0x800CF698, len = 0x00000004
		.queryFunc = &MonsterQuery,
		// _func_100 * @0x800CF69C, len = 0x00000004
		.messageFunc = &MonsterMessage,
		// _MonsterStateChoice * @0x800CF6A0, len = 0x00000004
		.stateFuncs = 00000000,
		// char * @0x800CF6A4, len = 0x00000004
		.versionID = "Jun 30 1999" /* collapsed from &monVersion */,
		// char * @0x800CF6A8, len = 0x00000004
		.localVersionID = 00000000};
// _MonsterState[31] @0x800CAA20, len = 0x000000F8
DefaultStateTable =
	{
		// _MonsterState @0x800CAA20, len = 0x00000008
		{
			// _func_88 * @0x800CAA20, len = 0x00000004
			.entryFunction = &MON_BirthEntry,
			// _func_89 * @0x800CAA24, len = 0x00000004
			.stateFunction = &MON_Birth},
		// _MonsterState @0x800CAA28, len = 0x00000008
		{
			// _func_88 * @0x800CAA28, len = 0x00000004
			.entryFunction = &MON_PursueEntry,
			// _func_89 * @0x800CAA2C, len = 0x00000004
			.stateFunction = &MON_Pursue},
		// _MonsterState @0x800CAA30, len = 0x00000008
		{
			// _func_88 * @0x800CAA30, len = 0x00000004
			.entryFunction = &MON_IdleEntry,
			// _func_89 * @0x800CAA34, len = 0x00000004
			.stateFunction = &MON_Idle},
		// _MonsterState @0x800CAA38, len = 0x00000008
		{
			// _func_88 * @0x800CAA38, len = 0x00000004
			.entryFunction = &MON_MissileHitEntry,
			// _func_89 * @0x800CAA3C, len = 0x00000004
			.stateFunction = &MON_MissileHit},
		// _MonsterState @0x800CAA40, len = 0x00000008
		{
			// _func_88 * @0x800CAA40, len = 0x00000004
			.entryFunction = &MON_FallEntry,
			// _func_89 * @0x800CAA44, len = 0x00000004
			.stateFunction = &MON_Fall},
		// _MonsterState @0x800CAA48, len = 0x00000008
		{
			// _func_88 * @0x800CAA48, len = 0x00000004
			.entryFunction = &MON_WanderEntry,
			// _func_89 * @0x800CAA4C, len = 0x00000004
			.stateFunction = &MON_Wander},
		// _MonsterState @0x800CAA50, len = 0x00000008
		{
			// _func_88 * @0x800CAA50, len = 0x00000004
			.entryFunction = &MON_AttackEntry,
			// _func_89 * @0x800CAA54, len = 0x00000004
			.stateFunction = &MON_Attack},
		// _MonsterState @0x800CAA58, len = 0x00000008
		{
			// _func_88 * @0x800CAA58, len = 0x00000004
			.entryFunction = &MON_ImpaleDeathEntry,
			// _func_89 * @0x800CAA5C, len = 0x00000004
			.stateFunction = &MON_ImpaleDeath},
		// _MonsterState @0x800CAA60, len = 0x00000008
		{
			// _func_88 * @0x800CAA60, len = 0x00000004
			.entryFunction = &MON_HitEntry,
			// _func_89 * @0x800CAA64, len = 0x00000004
			.stateFunction = &MON_Hit},
		// _MonsterState @0x800CAA68, len = 0x00000008
		{
			// _func_88 * @0x800CAA68, len = 0x00000004
			.entryFunction = &MON_StunnedEntry,
			// _func_89 * @0x800CAA6C, len = 0x00000004
			.stateFunction = &MON_Stunned},
		// _MonsterState @0x800CAA70, len = 0x00000008
		{
			// _func_88 * @0x800CAA70, len = 0x00000004
			.entryFunction = &MON_GrabbedEntry,
			// _func_89 * @0x800CAA74, len = 0x00000004
			.stateFunction = &MON_Grabbed},
		// _MonsterState @0x800CAA78, len = 0x00000008
		{
			// _func_88 * @0x800CAA78, len = 0x00000004
			.entryFunction = &MON_ThrownEntry,
			// _func_89 * @0x800CAA7C, len = 0x00000004
			.stateFunction = &MON_Thrown},
		// _MonsterState @0x800CAA80, len = 0x00000008
		{
			// _func_88 * @0x800CAA80, len = 0x00000004
			.entryFunction = &MON_ImpactEntry,
			// _func_89 * @0x800CAA84, len = 0x00000004
			.stateFunction = &MON_Impact},
		// _MonsterState @0x800CAA88, len = 0x00000008
		{
			// _func_88 * @0x800CAA88, len = 0x00000004
			.entryFunction = &MON_CombatEntry,
			// _func_89 * @0x800CAA8C, len = 0x00000004
			.stateFunction = &MON_Combat},
		// _MonsterState @0x800CAA90, len = 0x00000008
		{
			// _func_88 * @0x800CAA90, len = 0x00000004
			.entryFunction = &MON_BreakHoldEntry,
			// _func_89 * @0x800CAA94, len = 0x00000004
			.stateFunction = &MON_BreakHold},
		// _MonsterState @0x800CAA98, len = 0x00000008
		{
			// _func_88 * @0x800CAA98, len = 0x00000004
			.entryFunction = &MON_LandOnFeetEntry,
			// _func_89 * @0x800CAA9C, len = 0x00000004
			.stateFunction = &MON_LandOnFeet},
		// _MonsterState @0x800CAAA0, len = 0x00000008
		{
			// _func_88 * @0x800CAAA0, len = 0x00000004
			.entryFunction = &MON_GeneralDeathEntry,
			// _func_89 * @0x800CAAA4, len = 0x00000004
			.stateFunction = &MON_GeneralDeath},
		// _MonsterState @0x800CAAA8, len = 0x00000008
		{
			// _func_88 * @0x800CAAA8, len = 0x00000004
			.entryFunction = &MON_EnvironmentDamageEntry,
			// _func_89 * @0x800CAAAC, len = 0x00000004
			.stateFunction = &MON_EnvironmentDamage},
		// _MonsterState @0x800CAAB0, len = 0x00000008
		{
			// _func_88 * @0x800CAAB0, len = 0x00000004
			.entryFunction = &MON_LandInWaterEntry,
			// _func_89 * @0x800CAAB4, len = 0x00000004
			.stateFunction = &MON_LandInWater},
		// _MonsterState @0x800CAAB8, len = 0x00000008
		{
			// _func_88 * @0x800CAAB8, len = 0x00000004
			.entryFunction = &MON_FleeEntry,
			// _func_89 * @0x800CAABC, len = 0x00000004
			.stateFunction = &MON_Flee},
		// _MonsterState @0x800CAAC0, len = 0x00000008
		{
			// _func_88 * @0x800CAAC0, len = 0x00000004
			.entryFunction = &MON_HideEntry,
			// _func_89 * @0x800CAAC4, len = 0x00000004
			.stateFunction = &MON_Hide},
		// _MonsterState @0x800CAAC8, len = 0x00000008
		{
			// _func_88 * @0x800CAAC8, len = 0x00000004
			.entryFunction = &MON_SurpriseAttackEntry,
			// _func_89 * @0x800CAACC, len = 0x00000004
			.stateFunction = &MON_SurpriseAttack},
		// _MonsterState @0x800CAAD0, len = 0x00000008
		{
			// _func_88 * @0x800CAAD0, len = 0x00000004
			.entryFunction = &MON_ParryEntry,
			// _func_89 * @0x800CAAD4, len = 0x00000004
			.stateFunction = &MON_Parry},
		// _MonsterState @0x800CAAD8, len = 0x00000008
		{
			// _func_88 * @0x800CAAD8, len = 0x00000004
			.entryFunction = &MON_DeadEntry,
			// _func_89 * @0x800CAADC, len = 0x00000004
			.stateFunction = &MON_Dead},
		// _MonsterState @0x800CAAE0, len = 0x00000008
		{
			// _func_88 * @0x800CAAE0, len = 0x00000004
			.entryFunction = &MON_SurprisedEntry,
			// _func_89 * @0x800CAAE4, len = 0x00000004
			.stateFunction = &MON_Surprised},
		// _MonsterState @0x800CAAE8, len = 0x00000008
		{
			// _func_88 * @0x800CAAE8, len = 0x00000004
			.entryFunction = &MON_NoticeEntry,
			// _func_89 * @0x800CAAEC, len = 0x00000004
			.stateFunction = &MON_Notice},
		// _MonsterState @0x800CAAF0, len = 0x00000008
		{
			// _func_88 * @0x800CAAF0, len = 0x00000004
			.entryFunction = &MON_PupateEntry,
			// _func_89 * @0x800CAAF4, len = 0x00000004
			.stateFunction = &MON_Pupate},
		// _MonsterState @0x800CAAF8, len = 0x00000008
		{
			// _func_88 * @0x800CAAF8, len = 0x00000004
			.entryFunction = &MON_EmbraceEntry,
			// _func_89 * @0x800CAAFC, len = 0x00000004
			.stateFunction = &MON_Embrace},
		// _MonsterState @0x800CAB00, len = 0x00000008
		{
			// _func_88 * @0x800CAB00, len = 0x00000004
			.entryFunction = &MON_ProjectileEntry,
			// _func_89 * @0x800CAB04, len = 0x00000004
			.stateFunction = &MON_Projectile},
		// _MonsterState @0x800CAB08, len = 0x00000008
		{
			// _func_88 * @0x800CAB08, len = 0x00000004
			.entryFunction = &MON_TerrainImpaleDeathEntry,
			// _func_89 * @0x800CAB0C, len = 0x00000004
			.stateFunction = &MON_TerrainImpaleDeath},
		// _MonsterState @0x800CAB10, len = 0x00000008
		{
			// _func_88 * @0x800CAB10, len = 0x00000004
			.entryFunction = &MON_PetrifiedEntry,
			// _func_89 * @0x800CAB14, len = 0x00000004
			.stateFunction = &MON_Petrified}};
// MONTABLE_207fake @0x800CA9F0, len = 0x00000008
functionChoiceTable =
	{
		// long @0x800CA9F0, len = 0x00000004
		.whatAmI = 0x4,
		// _MonsterFunctionTable * @0x800CA9F4, len = 0x00000004
		.table = &SOUL_FunctionTable};
// decompiled code
// original method signature:
// void /*$ra*/ MONTABLE_SetupTablePointer(struct Object *object /*$a0*/)
// line 376, offset 0x8008ce88
/* begin block 1 */
// Start line: 378
// Start offset: 0x8008CE88
// Variables:
// 		long whatAmI; // $a1
/* end block 1 */
// End offset: 0x8008CED0
// End Line: 390

/* begin block 2 */
// Start line: 752
/* end block 2 */
// End Line: 753

/* begin block 3 */
// Start line: 753
/* end block 3 */
// End Line: 754

/* begin block 4 */
// Start line: 758
/* end block 4 */
// End Line: 759

void MONTABLE_SetupTablePointer(Object *object)

{
	int iVar1;
	MONTABLE_207fake *pMVar2;
	int iVar3;

	iVar3 = *(int *)((int)object->data + 0x10);
	pMVar2 = &functionChoiceTable;
	iVar1 = functionChoiceTable.whatAmI;
	if (functionChoiceTable.whatAmI != 0)
	{
		do
		{
			if (iVar3 == iVar1)
			{
				*(_MonsterFunctionTable **)&object->relocModule = pMVar2->table;
			}
			pMVar2 = pMVar2 + 1;
			iVar1 = pMVar2->whatAmI;
		} while (pMVar2->whatAmI != 0);
	}
	return;
}

// decompiled code
// original method signature:
// struct _MonsterState * /*$ra*/ MONTABLE_GetStateFuncs(struct _Instance *instance /*$a0*/, int state /*$a1*/)
// line 392, offset 0x8008ced8
/* begin block 1 */
// Start line: 394
// Start offset: 0x8008CED8
// Variables:
// 		struct _MonsterFunctionTable *ft; // $v0

/* begin block 1.1 */
// Start line: 398
// Start offset: 0x8008CEF0
// Variables:
// 		struct _MonsterStateChoice *choice; // $a0
/* end block 1.1 */
// End offset: 0x8008CF2C
// End Line: 403
/* end block 1 */
// End offset: 0x8008CF38
// End Line: 406

/* begin block 2 */
// Start line: 798
/* end block 2 */
// End Line: 799

/* begin block 3 */
// Start line: 799
/* end block 3 */
// End Line: 800

_MonsterState *MONTABLE_GetStateFuncs(_Instance *instance, int state)

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
	return DefaultStateTable + state;
}

// decompiled code
// original method signature:
// TDRFuncPtr_MONTABLE_GetDamageEffectFunc /*$ra*/ MONTABLE_GetDamageEffectFunc(struct _Instance *instance /*$a0*/)
// line 408, offset 0x8008cf48
/* begin block 1 */
// Start line: 410
// Start offset: 0x8008CF48
// Variables:
// 		struct _MonsterFunctionTable *ft; // $v0
/* end block 1 */
// End offset: 0x8008CF74
// End Line: 416

/* begin block 2 */
// Start line: 831
/* end block 2 */
// End Line: 832

/* begin block 3 */
// Start line: 832
/* end block 3 */
// End Line: 833

TDRFuncPtr_MONTABLE_GetDamageEffectFunc MONTABLE_GetDamageEffectFunc(_Instance *instance)

{
	void *pvVar1;
	TDRFuncPtr_MONTABLE_GetDamageEffectFunc pTVar2;

	pvVar1 = instance->object->relocModule;
	if ((pvVar1 == (void *)0x0) ||
		(pTVar2 = *(TDRFuncPtr_MONTABLE_GetDamageEffectFunc *)((int)pvVar1 + 8),
		 pTVar2 == (TDRFuncPtr_MONTABLE_GetDamageEffectFunc)0x0))
	{
		pTVar2 = (TDRFuncPtr_MONTABLE_GetDamageEffectFunc)DefaultFunctionTable.damageEffectFunc;
	}
	return pTVar2;
}

// decompiled code
// original method signature:
// TDRFuncPtr_MONTABLE_GetInitFunc /*$ra*/ MONTABLE_GetInitFunc(struct _Instance *instance /*$a0*/)
// line 418, offset 0x8008cf7c
/* begin block 1 */
// Start line: 420
// Start offset: 0x8008CF7C
// Variables:
// 		struct _MonsterFunctionTable *ft; // $v0
/* end block 1 */
// End offset: 0x8008CFA8
// End Line: 426

/* begin block 2 */
// Start line: 851
/* end block 2 */
// End Line: 852

/* begin block 3 */
// Start line: 852
/* end block 3 */
// End Line: 853

TDRFuncPtr_MONTABLE_GetInitFunc MONTABLE_GetInitFunc(_Instance *instance)

{
	TDRFuncPtr_MONTABLE_GetInitFunc *ppTVar1;
	TDRFuncPtr_MONTABLE_GetInitFunc pTVar2;

	ppTVar1 = (TDRFuncPtr_MONTABLE_GetInitFunc *)instance->object->relocModule;
	if ((ppTVar1 == (TDRFuncPtr_MONTABLE_GetInitFunc *)0x0) ||
		(pTVar2 = *ppTVar1, pTVar2 == (TDRFuncPtr_MONTABLE_GetInitFunc)0x0))
	{
		pTVar2 = (TDRFuncPtr_MONTABLE_GetInitFunc)DefaultFunctionTable.initFunc;
	}
	return pTVar2;
}

// decompiled code
// original method signature:
// TDRFuncPtr_MONTABLE_GetCleanUpFunc /*$ra*/ MONTABLE_GetCleanUpFunc(struct _Instance *instance /*$a0*/)
// line 428, offset 0x8008cfb0
/* begin block 1 */
// Start line: 430
// Start offset: 0x8008CFB0
// Variables:
// 		struct _MonsterFunctionTable *ft; // $v0
/* end block 1 */
// End offset: 0x8008CFDC
// End Line: 436

/* begin block 2 */
// Start line: 871
/* end block 2 */
// End Line: 872

/* begin block 3 */
// Start line: 872
/* end block 3 */
// End Line: 873

TDRFuncPtr_MONTABLE_GetCleanUpFunc MONTABLE_GetCleanUpFunc(_Instance *instance)

{
	void *pvVar1;
	TDRFuncPtr_MONTABLE_GetCleanUpFunc pTVar2;

	pvVar1 = instance->object->relocModule;
	if ((pvVar1 == (void *)0x0) ||
		(pTVar2 = *(TDRFuncPtr_MONTABLE_GetCleanUpFunc *)((int)pvVar1 + 4),
		 pTVar2 == (TDRFuncPtr_MONTABLE_GetCleanUpFunc)0x0))
	{
		pTVar2 = (TDRFuncPtr_MONTABLE_GetCleanUpFunc)DefaultFunctionTable.cleanUpFunc;
	}
	return pTVar2;
}

// decompiled code
// original method signature:
// void /*$ra*/ MONTABLE_SetQueryFunc(struct _Instance *instance /*$a0*/)
// line 438, offset 0x8008cfe4
/* begin block 1 */
// Start line: 440
// Start offset: 0x8008CFE4
// Variables:
// 		struct _MonsterFunctionTable *ft; // $v0
/* end block 1 */
// End offset: 0x8008D010
// End Line: 444

/* begin block 2 */
// Start line: 891
/* end block 2 */
// End Line: 892

/* begin block 3 */
// Start line: 892
/* end block 3 */
// End Line: 893

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

// decompiled code
// original method signature:
// void /*$ra*/ MONTABLE_SetMessageFunc(struct _Instance *instance /*$a0*/)
// line 446, offset 0x8008d018
/* begin block 1 */
// Start line: 448
// Start offset: 0x8008D018
// Variables:
// 		struct _MonsterFunctionTable *ft; // $v0
/* end block 1 */
// End offset: 0x8008D044
// End Line: 452

/* begin block 2 */
// Start line: 907
/* end block 2 */
// End Line: 908

/* begin block 3 */
// Start line: 908
/* end block 3 */
// End Line: 909

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
