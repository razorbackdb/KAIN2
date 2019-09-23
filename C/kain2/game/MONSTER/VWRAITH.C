#include "THISDUST.H"
#include "VWRAITH.H"

// _MonsterFunctionTable @0x800CF6F4, len = 0x00000020
VWRAITH_FunctionTable =
	{
		// _func_96 * @0x800CF6F4, len = 0x00000004
		.initFunc = &VWRAITH_Init,
		// _func_97 * @0x800CF6F8, len = 0x00000004
		.cleanUpFunc = &SOUL_CleanUp,
		// _func_98 * @0x800CF6FC, len = 0x00000004
		.damageEffectFunc = &SLUAGH_DamageEffect,
		// _func_99 * @0x800CF700, len = 0x00000004
		.queryFunc = &SLUAGH_Query,
		// _func_100 * @0x800CF704, len = 0x00000004
		.messageFunc = 00000000,
		// _MonsterStateChoice * @0x800CF708, len = 0x00000004
		.stateFuncs = &VWRAITH_StateChoiceTable,
		// char * @0x800CF70C, len = 0x00000004
		.versionID = "Jun 30 1999" /* collapsed from &monVersion */,
		// char * @0x800CF710, len = 0x00000004
		.localVersionID = 00000000};
// _MonsterStateChoice[7] @0x800CAB9C, len = 0x00000054
VWRAITH_StateChoiceTable =
	{
		// _MonsterStateChoice @0x800CAB9C, len = 0x0000000C
		{
			// int @0x800CAB9C, len = 0x00000004
			.state = 0x6,
			// _MonsterState @0x800CABA0, len = 0x00000008
			.functions =
				{
					// _func_88 * @0x800CABA0, len = 0x00000004
					.entryFunction = &SLUAGH_AttackEntry,
					// _func_89 * @0x800CABA4, len = 0x00000004
					.stateFunction = &SLUAGH_Attack}},
		// _MonsterStateChoice @0x800CABA8, len = 0x0000000C
		{
			// int @0x800CABA8, len = 0x00000004
			.state = 0xd,
			// _MonsterState @0x800CABAC, len = 0x00000008
			.functions =
				{
					// _func_88 * @0x800CABAC, len = 0x00000004
					.entryFunction = &VWRAITH_CombatEntry,
					// _func_89 * @0x800CABB0, len = 0x00000004
					.stateFunction = &VWRAITH_Combat}},
		// _MonsterStateChoice @0x800CABB4, len = 0x0000000C
		{
			// int @0x800CABB4, len = 0x00000004
			.state = 0x1,
			// _MonsterState @0x800CABB8, len = 0x00000008
			.functions =
				{
					// _func_88 * @0x800CABB8, len = 0x00000004
					.entryFunction = &VWRAITH_PursueEntry,
					// _func_89 * @0x800CABBC, len = 0x00000004
					.stateFunction = &VWRAITH_Pursue}},
		// _MonsterStateChoice @0x800CABC0, len = 0x0000000C
		{
			// int @0x800CABC0, len = 0x00000004
			.state = 0x10,
			// _MonsterState @0x800CABC4, len = 0x00000008
			.functions =
				{
					// _func_88 * @0x800CABC4, len = 0x00000004
					.entryFunction = &SLUAGH_DeathEntry,
					// _func_89 * @0x800CABC8, len = 0x00000004
					.stateFunction = &SLUAGH_Death}},
		// _MonsterStateChoice @0x800CABCC, len = 0x0000000C
		{
			// int @0x800CABCC, len = 0x00000004
			.state = 0xa,
			// _MonsterState @0x800CABD0, len = 0x00000008
			.functions =
				{
					// _func_88 * @0x800CABD0, len = 0x00000004
					.entryFunction = &SOUL_SoulSuckEntry,
					// _func_89 * @0x800CABD4, len = 0x00000004
					.stateFunction = &SOUL_SoulSuck}},
		// _MonsterStateChoice @0x800CABD8, len = 0x0000000C
		{
			// int @0x800CABD8, len = 0x00000004
			.state = 0x1b,
			// _MonsterState @0x800CABDC, len = 0x00000008
			.functions =
				{
					// _func_88 * @0x800CABDC, len = 0x00000004
					.entryFunction = &VWRAITH_EmbraceEntry,
					// _func_89 * @0x800CABE0, len = 0x00000004
					.stateFunction = &VWRAITH_Embrace}},
		// _MonsterStateChoice @0x800CABE4, len = 0x0000000C
		{
			// int @0x800CABE4, len = 0x00000004
			.state = -0x1,
			// _MonsterState @0x800CABE8, len = 0x00000008
			.functions =
				{
					// _func_88 * @0x800CABE8, len = 0x00000004
					.entryFunction = 00000000,
					// _func_89 * @0x800CABEC, len = 0x00000004
					.stateFunction = 00000000}}};
// decompiled code
// original method signature:
// void /*$ra*/ VWRAITH_MoveVertical(struct _Instance *instance /*$a0*/, long targetZ /*$a1*/, int velocity /*$a2*/)
// line 89, offset 0x8008e8f4
/* begin block 1 */
// Start line: 178
/* end block 1 */
// End Line: 179

/* begin block 2 */
// Start line: 179
/* end block 2 */
// End Line: 180

void VWRAITH_MoveVertical(_Instance *instance, long targetZ, int velocity)

{
	bool bVar1;
	int iVar2;
	uint uVar3;
	int iVar4;

	iVar4 = (int)(instance->position).z;
	uVar3 = (uint)(ushort)(instance->position).z;
	iVar2 = uVar3 + velocity;
	if (iVar4 < targetZ)
	{
		(instance->position).z = (short)iVar2;
		bVar1 = targetZ<iVar2 * 0x10000>> 0x10;
	}
	else
	{
		velocity = uVar3 - velocity;
		if (iVar4 <= targetZ)
		{
			return;
		}
		(instance->position).z = (short)velocity;
		bVar1 = velocity * 0x10000 >> 0x10 < targetZ;
	}
	if (bVar1)
	{
		(instance->position).z = (short)targetZ;
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VWRAITH_Init(struct _Instance *instance /*$s1*/)
// line 108, offset 0x8008e94c
/* begin block 1 */
// Start line: 109
// Start offset: 0x8008E94C
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		long color; // stack offset -24
/* end block 1 */
// End offset: 0x8008E97C
// End Line: 111

/* begin block 2 */
// Start line: 216
/* end block 2 */
// End Line: 217

void VWRAITH_Init(_Instance *instance)

{
	_FXGlowEffect *p_Var1;
	int iVar2;
	uint *puVar3;
	long local_18[2];

	puVar3 = (uint *)instance->extraData;
	iVar2 = (int)*(short *)(puVar3 + 0x4c);
	if (iVar2 < 0)
	{
		iVar2 = iVar2 + 0xfff;
	}
	local_18[0] = FX_GetHealthColor(iVar2 >> 0xc);
	p_Var1 = FX_DoInstanceTwoSegmentGlow(instance, 0x15, 0x17, local_18, 1, 0x4b0, 0x9c);
	*(_FXGlowEffect **)(puVar3 + 0x37) = p_Var1;
	MON_DefaultInit(instance);
	*(undefined2 *)(puVar3 + 0x4d) = 0x3000;
	puVar3[1] = puVar3[1] & 0xfffffffe;
	*puVar3 = *puVar3 | 0x10002800;
	return;
}

// decompiled code
// original method signature:
// int /*$ra*/ VWRAITH_ShouldISwoop(struct _Instance *instance /*$a0*/)
// line 131, offset 0x8008ea00
/* begin block 1 */
// Start line: 132
// Start offset: 0x8008EA00
// Variables:
// 		struct _MonsterAttributes *ma; // $a3
// 		struct _MonsterVars *mv; // $v1

/* begin block 1.1 */
// Start line: 138
// Start offset: 0x8008EA34
// Variables:
// 		struct _Instance *ei; // $a1
/* end block 1.1 */
// End offset: 0x8008EA74
// End Line: 143
/* end block 1 */
// End offset: 0x8008EA74
// End Line: 146

/* begin block 2 */
// Start line: 281
/* end block 2 */
// End Line: 282

int VWRAITH_ShouldISwoop(_Instance *instance)

{
	int iVar1;
	uint uVar2;

	iVar1 = 0;
	if (((*(uint *)instance->extraData & 4) == 0) &&
		(uVar2 = *(uint *)(instance->extraData + 0x31), uVar2 != 0))
	{
		iVar1 = 0;
		if ((((*(_Instance **)(uVar2 + 4))->position).z <= (instance->position).z) &&
			(iVar1 = 0, *(short *)(*(int *)((int)instance->data + 4) + 0xc) < *(short *)(uVar2 + 0x14)))
		{
			iVar1 = MON_ShouldIAttackInstance(instance, *(_Instance **)(uVar2 + 4));
		}
	}
	return iVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ VWRAITH_PursueEntry(struct _Instance *instance /*$s1*/)
// line 151, offset 0x8008ea84
/* begin block 1 */
// Start line: 152
// Start offset: 0x8008EA84
// Variables:
// 		struct _MonsterVars *mv; // $s0

/* begin block 1.1 */
// Start line: 166
// Start offset: 0x8008EAE0
// Variables:
// 		struct _MonsterAttributes *ma; // $v0
/* end block 1.1 */
// End offset: 0x8008EB08
// End Line: 171
/* end block 1 */
// End offset: 0x8008EB08
// End Line: 172

/* begin block 2 */
// Start line: 324
/* end block 2 */
// End Line: 325

void VWRAITH_PursueEntry(_Instance *instance)

{
	int iVar1;
	void *pvVar2;

	pvVar2 = instance->extraData;
	iVar1 = VWRAITH_ShouldISwoop(instance);
	if (iVar1 != 0)
	{
		*(uint *)((int)pvVar2 + 4) = *(uint *)((int)pvVar2 + 4) | 2;
	}
	if ((*(uint *)((int)pvVar2 + 4) & 2) == 0)
	{
		MON_PursueEntry(instance);
	}
	else
	{
		MON_PlayAnimFromList(instance, *(char **)((int)instance->data + 8),
							 (int)*(char *)(*(int *)((int)instance->data + 4) + 0xe), 1);
		*(undefined4 *)((int)pvVar2 + 0xf4) = 4;
		*(undefined2 *)((int)pvVar2 + 0x110) = 0;
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VWRAITH_Pursue(struct _Instance *instance /*$s2*/)
// line 174, offset 0x8008eb1c
/* begin block 1 */
// Start line: 175
// Start offset: 0x8008EB1C
// Variables:
// 		struct _MonsterAttributes *ma; // $s1
// 		struct _MonsterVars *mv; // $s0

/* begin block 1.1 */
// Start line: 195
// Start offset: 0x8008EBBC
// Variables:
// 		struct _MonsterAttributes *ma; // $s1
// 		struct _MonsterAttackAttributes *attack; // $s3
/* end block 1.1 */
// End offset: 0x8008ECAC
// End Line: 218
/* end block 1 */
// End offset: 0x8008ECD0
// End Line: 225

/* begin block 2 */
// Start line: 370
/* end block 2 */
// End Line: 371

void VWRAITH_Pursue(_Instance *instance)

{
	char cVar1;
	int iVar2;
	_MonsterAnim *p_Var3;
	undefined4 local_18;
	void *pvVar4;
	undefined4 local_14;
	void *pvVar5;

	pvVar4 = instance->extraData;
	pvVar5 = instance->data;
	if ((*(uint *)((int)pvVar4 + 4) & 2) == 0)
	{
		iVar2 = VWRAITH_ShouldISwoop(instance);
		if (iVar2 == 0)
		{
			if (*(int *)((int)pvVar4 + 0xc4) != 0)
			{
				VWRAITH_MoveVertical(instance, (int)*(short *)(*(int *)(*(int *)((int)pvVar4 + 0xc4) + 4) + 0x60),
									 (int)*(short *)(*(int *)((int)pvVar5 + 4) + 6));
			}
			MON_Pursue(instance);
		}
		else
		{
			MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
		}
	}
	else
	{
		if (*(int *)((int)pvVar4 + 0xc4) == 0)
		{
			*(uint *)((int)pvVar4 + 4) = *(uint *)((int)pvVar4 + 4) & 0xfffffffd;
		}
		else
		{
			cVar1 = *(char *)(*(int *)((int)pvVar5 + 4) + 0x10);
			iVar2 = *(int *)((int)pvVar5 + 0x38);
			MON_TurnToPosition(instance, (_Position *)(*(int *)(*(int *)((int)pvVar4 + 0xc4) + 4) + 0x5c),
							   *(short *)(*(int *)((int)pvVar4 + 0x154) + 0x20));
			if (*(short *)(*(int *)((int)pvVar4 + 0xc4) + 0x14) <
				*(short *)(*(int *)((int)pvVar5 + 4) + 10))
			{
				*(int *)((int)pvVar4 + 0xb8) = iVar2 + (int)cVar1 * 0x20;
				*(undefined *)((int)pvVar4 + 0x14b) = 0;
				*(undefined2 *)((int)pvVar4 + 0x110) = 0;
				*(uint *)((int)pvVar4 + 4) = *(uint *)((int)pvVar4 + 4) & 0xfffffffd;
				MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
			}
			else
			{
				if ((instance->flags2 & 0x10U) != 0)
				{
					p_Var3 = MON_GetAnim(instance, *(char **)((int)pvVar5 + 8),
										 (int)*(char *)(*(int *)((int)pvVar5 + 4) + 0xf));
					*(ushort *)((int)pvVar4 + 0x110) = p_Var3->velocity;
					MON_PlayAnimFromList(instance, *(char **)((int)pvVar5 + 8),
										 (int)*(char *)(*(int *)((int)pvVar5 + 4) + 0xf), 2);
				}
			}
			VWRAITH_MoveVertical(instance, (int)*(short *)(*(int *)(*(int *)((int)pvVar4 + 0xc4) + 4) + 0x60) + (int)*(short *)(*(int *)((int)pvVar5 + 4) + 2),
								 (int)*(short *)(*(int *)((int)pvVar5 + 4) + 4));
			if (*(short *)((int)pvVar4 + 0x110) != 0)
			{
				MON_MoveForward(instance);
			}
		}
		MON_DefaultQueueHandler(instance);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VWRAITH_VerticalMove(struct _Instance *instance /*$s0*/)
// line 230, offset 0x8008ecec
/* begin block 1 */
// Start line: 231
// Start offset: 0x8008ECEC
// Variables:
// 		struct _MonsterVars *mv; // $v0

/* begin block 1.1 */
// Start line: 236
// Start offset: 0x8008ED18
// Variables:
// 		struct _MonsterAttributes *ma; // $v0
// 		long targetZ; // $s1
/* end block 1.1 */
// End offset: 0x8008ED5C
// End Line: 242
/* end block 1 */
// End offset: 0x8008ED5C
// End Line: 243

/* begin block 2 */
// Start line: 494
/* end block 2 */
// End Line: 495

void VWRAITH_VerticalMove(_Instance *instance)

{
	int targetZ;
	undefined4 local_10;
	undefined4 local_c;

	targetZ = *(int *)((int)instance->extraData + 0xc4);
	if (targetZ != 0)
	{
		targetZ = (int)*(short *)(*(int *)(targetZ + 4) + 0x60);
		VWRAITH_MoveVertical(instance, targetZ, (int)*(short *)(*(int *)((int)instance->data + 4) + 8));
		if ((instance->currentMainState == 6) && ((int)(instance->position).z != targetZ))
		{
			MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
		}
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VWRAITH_CombatEntry(struct _Instance *instance /*$a0*/)
// line 248, offset 0x8008ed70
/* begin block 1 */
// Start line: 531
/* end block 1 */
// End Line: 532

void VWRAITH_CombatEntry(_Instance *instance)

{
	MON_CombatEntry(instance);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VWRAITH_Combat(struct _Instance *instance /*$s0*/)
// line 253, offset 0x8008ed90
/* begin block 1 */
// Start line: 541
/* end block 1 */
// End Line: 542

void VWRAITH_Combat(_Instance *instance)

{
	MON_Combat(instance);
	VWRAITH_VerticalMove(instance);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VWRAITH_EmbraceEntry(struct _Instance *instance /*$a0*/)
// line 263, offset 0x8008edbc
/* begin block 1 */
// Start line: 561
/* end block 1 */
// End Line: 562

void VWRAITH_EmbraceEntry(_Instance *instance)

{
	MON_EmbraceEntry(instance);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VWRAITH_Embrace(struct _Instance *instance /*$s0*/)
// line 268, offset 0x8008eddc
/* begin block 1 */
// Start line: 571
/* end block 1 */
// End Line: 572

void VWRAITH_Embrace(_Instance *instance)

{
	MON_Embrace(instance);
	VWRAITH_VerticalMove(instance);
	return;
}
