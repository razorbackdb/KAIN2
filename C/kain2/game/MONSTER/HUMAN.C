#include "THISDUST.H"
#include "HUMAN.H"

// _MonsterFunctionTable @0x800CF5E0, len = 0x00000020
HUMAN_FunctionTable =
    {
        // _func_96 * @0x800CF5E0, len = 0x00000004
        .initFunc = &HUMAN_Init,
        // _func_97 * @0x800CF5E4, len = 0x00000004
        .cleanUpFunc = &HUMAN_CleanUp,
        // _func_98 * @0x800CF5E8, len = 0x00000004
        .damageEffectFunc = 00000000,
        // _func_99 * @0x800CF5EC, len = 0x00000004
        .queryFunc = &HUMAN_Query,
        // _func_100 * @0x800CF5F0, len = 0x00000004
        .messageFunc = 00000000,
        // _MonsterStateChoice * @0x800CF5F4, len = 0x00000004
        .stateFuncs = &HUMAN_StateChoiceTable,
        // char * @0x800CF5F8, len = 0x00000004
        .versionID = "Jun 30 1999" /* collapsed from &monVersion */,
        // char * @0x800CF5FC, len = 0x00000004
        .localVersionID = 00000000};
// _MonsterStateChoice[6] @0x800CA978, len = 0x00000048
HUMAN_StateChoiceTable =
    {
        // _MonsterStateChoice @0x800CA978, len = 0x0000000C
        {
            // int @0x800CA978, len = 0x00000004
            .state = 0x9,
            // _MonsterState @0x800CA97C, len = 0x00000008
            .functions =
                {
                    // _func_88 * @0x800CA97C, len = 0x00000004
                    .entryFunction = &HUMAN_StunnedEntry,
                    // _func_89 * @0x800CA980, len = 0x00000004
                    .stateFunction = &HUMAN_Stunned}},
        // _MonsterStateChoice @0x800CA984, len = 0x0000000C
        {
            // int @0x800CA984, len = 0x00000004
            .state = 0x17,
            // _MonsterState @0x800CA988, len = 0x00000008
            .functions =
                {
                    // _func_88 * @0x800CA988, len = 0x00000004
                    .entryFunction = &HUMAN_DeadEntry,
                    // _func_89 * @0x800CA98C, len = 0x00000004
                    .stateFunction = &HUMAN_Dead}},
        // _MonsterStateChoice @0x800CA990, len = 0x0000000C
        {
            // int @0x800CA990, len = 0x00000004
            .state = 0x1b,
            // _MonsterState @0x800CA994, len = 0x00000008
            .functions =
                {
                    // _func_88 * @0x800CA994, len = 0x00000004
                    .entryFunction = &HUMAN_EmbraceEntry,
                    // _func_89 * @0x800CA998, len = 0x00000004
                    .stateFunction = &HUMAN_Embrace}},
        // _MonsterStateChoice @0x800CA99C, len = 0x0000000C
        {
            // int @0x800CA99C, len = 0x00000004
            .state = 0x2,
            // _MonsterState @0x800CA9A0, len = 0x00000008
            .functions =
                {
                    // _func_88 * @0x800CA9A0, len = 0x00000004
                    .entryFunction = &HUMAN_IdleEntry,
                    // _func_89 * @0x800CA9A4, len = 0x00000004
                    .stateFunction = &HUMAN_Idle}},
        // _MonsterStateChoice @0x800CA9A8, len = 0x0000000C
        {
            // int @0x800CA9A8, len = 0x00000004
            .state = 0x13,
            // _MonsterState @0x800CA9AC, len = 0x00000008
            .functions =
                {
                    // _func_88 * @0x800CA9AC, len = 0x00000004
                    .entryFunction = &MON_FleeEntry,
                    // _func_89 * @0x800CA9B0, len = 0x00000004
                    .stateFunction = &HUMAN_Flee}},
        // _MonsterStateChoice @0x800CA9B4, len = 0x0000000C
        {
            // int @0x800CA9B4, len = 0x00000004
            .state = -0x1,
            // _MonsterState @0x800CA9B8, len = 0x00000008
            .functions =
                {
                    // _func_88 * @0x800CA9B8, len = 0x00000004
                    .entryFunction = 00000000,
                    // _func_89 * @0x800CA9BC, len = 0x00000004
                    .stateFunction = 00000000}}};
// decompiled code
// original method signature:
// void /*$ra*/ HUMAN_WaitForWeapon(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
// line 92, offset 0x8007cb40
/* begin block 1 */
// Start line: 184
/* end block 1 */
// End Line: 185

void HUMAN_WaitForWeapon(_Instance *instance, GameTracker *gameTracker)

{
  TDRFuncPtr_MONTABLE_GetInitFunc pTVar1;

  pTVar1 = MONTABLE_GetInitFunc(instance);
  (*pTVar1)(instance);
  if (instance->LinkChild != (_Instance *)0x0)
  {
    instance->processFunc = MonsterProcess;
    instance->flags = instance->flags & 0xfffff7ff;
    instance->flags2 = instance->flags2 & 0xdfffff7f;
  }
  return;
}

// decompiled code
// original method signature:
// struct _Instance * /*$ra*/ HUMAN_CreateWeapon(struct _Instance *instance /*$s1*/, int weaponid /*$a1*/, int segment /*$s2*/)
// line 110, offset 0x8007cbb0
/* begin block 1 */
// Start line: 111
// Start offset: 0x8007CBB0
// Variables:
// 		struct Object *weapon; // $a1

/* begin block 1.1 */
// Start line: 116
// Start offset: 0x8007CBE8
// Variables:
// 		struct _Instance *iweapon; // $s0
/* end block 1.1 */
// End offset: 0x8007CC3C
// End Line: 141
/* end block 1 */
// End offset: 0x8007CC6C
// End Line: 150

/* begin block 2 */
// Start line: 228
/* end block 2 */
// End Line: 229

_Instance *HUMAN_CreateWeapon(_Instance *instance, int weaponid, int segment)

{
  _Instance *Inst;
  int Data;

  if (((Object *)(&objectAccess)[weaponid].object == (Object *)0x0) ||
      (Inst = INSTANCE_BirthObject(instance, (Object *)(&objectAccess)[weaponid].object, 0),
       Inst == (_Instance *)0x0))
  {
    Inst = (_Instance *)0x0;
    instance->processFunc = HUMAN_WaitForWeapon;
    instance->flags = instance->flags | 0x800;
    instance->flags2 = instance->flags2 | 0x20000080;
  }
  else
  {
    Data = SetObjectData(0, 0, 0, instance, segment);
    INSTANCE_Post(Inst, 0x800002, Data);
    Inst->flags2 = Inst->flags2 | 0x20000;
  }
  return Inst;
}

// decompiled code
// original method signature:
// void /*$ra*/ HUMAN_Init(struct _Instance *instance /*$s1*/)
// line 155, offset 0x8007cc84
/* begin block 1 */
// Start line: 156
// Start offset: 0x8007CC84
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct _MonsterAttributes *ma; // $v0

/* begin block 1.1 */
// Start line: 162
// Start offset: 0x8007CCB4
// Variables:
// 		int opinion; // $v0
// 		struct _MonsterAllegiances *allegiances; // $a1
/* end block 1.1 */
// End offset: 0x8007CD20
// End Line: 180
/* end block 1 */
// End offset: 0x8007CD4C
// End Line: 188

/* begin block 2 */
// Start line: 330
/* end block 2 */
// End Line: 331

void HUMAN_Init(_Instance *instance)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;

  puVar3 = (uint *)instance->extraData;
  if ((*(uint *)((int)instance->data + 0x10) & 0x2000) == 0)
  {
    puVar2 = *(uint **)(puVar3[0x55] + 0xc);
    if (GlobalSave->humanOpinionOfRaziel < 1)
    {
      puVar2[3] = puVar2[3] & 0xfffffffe;
      *puVar2 = *puVar2 | 1;
      puVar2[1] = puVar2[1] & 0xfffffffe;
    }
    else
    {
      *puVar2 = *puVar2 & 0xfffffffe;
      puVar2[3] = puVar2[3] | 1;
      puVar2[1] = puVar2[1] | 1;
    }
  }
  iVar1 = strcmpi(instance->object->name, s_vlgrb____800cf600);
  if (iVar1 == 0)
  {
    puVar3[1] = puVar3[1] | 0x20;
  }
  MON_DefaultInit(instance);
  *(undefined2 *)(puVar3 + 0x4d) = 0x4000;
  *puVar3 = *puVar3 | 0x2000;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HUMAN_CleanUp(struct _Instance *instance /*$a0*/)
// line 199, offset 0x8007cd7c
/* begin block 1 */
// Start line: 431
/* end block 1 */
// End Line: 432

void HUMAN_CleanUp(_Instance *instance)

{
  MON_CleanUp(instance);
  return;
}

// decompiled code
// original method signature:
// unsigned long /*$ra*/ HUMAN_Query(struct _Instance *instance /*$a0*/, unsigned long query /*$a1*/)
// line 207, offset 0x8007cd9c
/* begin block 1 */
// Start line: 208
// Start offset: 0x8007CD9C
// Variables:
// 		struct _MonsterVars *mv; // $a3
// 		struct _MonsterAttributes *ma; // $v1
// 		unsigned long ret; // $a1
/* end block 1 */
// End offset: 0x8007CE7C
// End Line: 261

/* begin block 2 */
// Start line: 447
/* end block 2 */
// End Line: 448

ulong HUMAN_Query(_Instance *instance, ulong query)

{
  ulong uVar1;
  uint uVar2;
  uint *puVar3;

  puVar3 = (uint *)instance->extraData;
  uVar1 = 0;
  if (instance->data != (void *)0x0)
  {
    if (query == 0)
    {
      uVar2 = *puVar3;
      uVar1 = 0x40000000;
      if (((((uVar2 & 0x200) == 0) && (uVar1 = 0x12000000, instance->currentMainState != 0x1e)) &&
           (uVar1 = (uint)((uVar2 & 0x100) != 0) << 0x1d, (uVar2 & 0x200000) == 0)) &&
          ((*(short *)(puVar3 + 0x4c) < 0x1001 || ((puVar3[1] & 3) != 0))))
      {
        uVar1 = uVar1 | 0x8000000;
      }
    }
    else
    {
      if (query == 0x25)
      {
        uVar1 = 0;
        if ((*(uint *)((int)instance->data + 0x10) & 0x8000) == 0)
        {
          uVar1 = **(uint **)(puVar3[0x55] + 0xc) & 1;
        }
      }
      else
      {
        uVar1 = MonsterQuery(instance, query);
      }
    }
  }
  return uVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ HUMAN_DeadEntry(struct _Instance *instance /*$s1*/)
// line 266, offset 0x8007ce8c
/* begin block 1 */
// Start line: 267
// Start offset: 0x8007CE8C
// Variables:
// 		struct _MonsterVars *mv; // $s0
/* end block 1 */
// End offset: 0x8007CED4
// End Line: 274

/* begin block 2 */
// Start line: 566
/* end block 2 */
// End Line: 567

void HUMAN_DeadEntry(_Instance *instance)

{
  int iVar1;
  ulong uVar2;
  void *pvVar3;

  pvVar3 = instance->extraData;
  iVar1 = (int)*(short *)((int)pvVar3 + 0x134);
  if (iVar1 < 0)
  {
    iVar1 = iVar1 + 3;
  }
  *(undefined2 *)((int)pvVar3 + 0x134) = (short)(iVar1 >> 2);
  if (0x1000 < iVar1 >> 2)
  {
    *(undefined2 *)((int)pvVar3 + 0x134) = 0x1000;
  }
  MON_DeadEntry(instance);
  uVar2 = MON_GetTime(instance);
  *(ulong *)((int)pvVar3 + 0xf8) = uVar2;
  MON_BirthMana(instance);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HUMAN_Dead(struct _Instance *instance /*$s1*/)
// line 287, offset 0x8007cf04
/* begin block 1 */
// Start line: 288
// Start offset: 0x8007CF04
// Variables:
// 		struct _MonsterVars *mv; // $s0
/* end block 1 */
// End offset: 0x8007CFD8
// End Line: 316

/* begin block 2 */
// Start line: 608
/* end block 2 */
// End Line: 609

void HUMAN_Dead(_Instance *instance)

{
  ushort uVar1;
  ulong uVar2;
  __Event *p_Var3;
  uint *puVar4;

  puVar4 = (uint *)instance->extraData;
  uVar2 = MON_GetTime(instance);
  uVar1 = *(ushort *)(puVar4 + 0x3e);
  instance->fadeValue = (short)(uVar2 - (uint)uVar1);
  if (*(char *)(puVar4 + 0x51) == '\x06')
  {
    MON_Dead(instance);
  }
  else
  {
    if (0xfff < (int)((uVar2 - (uint)uVar1) * 0x10000) >> 0x10)
    {
      MON_KillMonster(instance);
    }
    if (((*puVar4 & 0x400000) != 0) && (uVar2 = MON_GetTime(instance), puVar4[0x42] < uVar2))
    {
      *puVar4 = *puVar4 & 0xffbfffff;
    }
    if ((*puVar4 & 2) == 0)
    {
      MON_ApplyPhysics(instance);
    }
    do
    {
      p_Var3 = DeMessageQueue((__MessageQueue *)(puVar4 + 2));
    } while (p_Var3 != (__Event *)0x0);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HUMAN_StunnedEntry(struct _Instance *instance /*$s0*/)
// line 321, offset 0x8007cfec
/* begin block 1 */
// Start line: 322
// Start offset: 0x8007CFEC
// Variables:
// 		struct _MonsterVars *mv; // $s1
/* end block 1 */
// End offset: 0x8007D050
// End Line: 333

/* begin block 2 */
// Start line: 676
/* end block 2 */
// End Line: 677

void HUMAN_StunnedEntry(_Instance *instance)

{
  ulong uVar1;
  undefined4 local_10;
  undefined4 local_c;
  void *pvVar2;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;

  pvVar2 = instance->extraData;
  if ((*(uint *)((int)pvVar2 + 4) & 0x10) == 0)
  {
    MON_StunnedEntry(instance);
  }
  else
  {
    uVar1 = MON_GetTime(instance);
    *(undefined **)((int)pvVar2 + 0x100) = &DAT_0000ea60 + uVar1;
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(local_8, CONCAT44(local_c, local_10))),
                 0x1e);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HUMAN_Stunned(struct _Instance *instance /*$s1*/)
// line 335, offset 0x8007d064
/* begin block 1 */
// Start line: 336
// Start offset: 0x8007D064
// Variables:
// 		struct _MonsterVars *mv; // $s0
/* end block 1 */
// End offset: 0x8007D0F8
// End Line: 354

/* begin block 2 */
// Start line: 704
/* end block 2 */
// End Line: 705

void HUMAN_Stunned(_Instance *instance)

{
  ulong uVar1;
  undefined4 unaff_s0;
  void *pvVar2;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  pvVar2 = instance->extraData;
  if ((*(uint *)((int)pvVar2 + 4) & 0x10) == 0)
  {
    MON_Stunned(instance);
  }
  else
  {
    if ((instance->flags2 & 0x10U) != 0)
    {
      MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 5);
    }
    uVar1 = MON_GetTime(instance);
    if (*(uint *)((int)pvVar2 + 0x100) < uVar1)
    {
      *(undefined2 *)((int)pvVar2 + 0x134) = 0x4000;
      *(uint *)((int)pvVar2 + 4) = *(uint *)((int)pvVar2 + 4) & 0xffffffef;
    }
    MON_DefaultQueueHandler(instance);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HUMAN_EmbraceEntry(struct _Instance *instance /*$s0*/)
// line 359, offset 0x8007d10c
/* begin block 1 */
// Start line: 360
// Start offset: 0x8007D10C
// Variables:
// 		struct _MonsterVars *mv; // $s1
/* end block 1 */
// End offset: 0x8007D14C
// End Line: 367

/* begin block 2 */
// Start line: 752
/* end block 2 */
// End Line: 753

void HUMAN_EmbraceEntry(_Instance *instance)

{
  int iVar1;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  void *pvVar2;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  pvVar2 = instance->extraData;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0x25);
  MON_TurnOffBodySpheres(instance);
  iVar1 = (int)*(short *)((int)pvVar2 + 0x134);
  if (iVar1 < 0)
  {
    iVar1 = iVar1 + 0xfff;
  }
  *(int *)((int)pvVar2 + 0x100) = iVar1 >> 0xc;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HUMAN_Embrace(struct _Instance *instance /*$s2*/)
// line 370, offset 0x8007d168
/* begin block 1 */
// Start line: 371
// Start offset: 0x8007D168
// Variables:
// 		struct _MonsterVars *mv; // $s1
// 		struct __Event *message; // $a1
// 		int letgo; // $s3
// 		int juice; // $s0
/* end block 1 */
// End offset: 0x8007D314
// End Line: 426

/* begin block 2 */
// Start line: 777
/* end block 2 */
// End Line: 778

void HUMAN_Embrace(_Instance *instance)

{
  bool bVar1;
  __Event *message;
  uint Data;
  void *pvVar2;
  undefined4 local_20;
  undefined4 in_stack_ffffffe4;

  bVar1 = false;
  pvVar2 = instance->extraData;
  MON_TurnToPosition(instance, &(gameTrackerX.playerInstance)->position, 0x1000);
  while (message = DeMessageQueue((__MessageQueue *)((int)pvVar2 + 8)), message != (__Event *)0x0)
  {
    if (message->ID == 0x1000014)
    {
      bVar1 = true;
    }
    else
    {
      MON_DefaultMessageHandler(instance, message);
    }
  }
  Data = (*(int *)((int)pvVar2 + 0x100) * gameTrackerX.timeMult * 0x21) / 5000;
  INSTANCE_Post(gameTrackerX.playerInstance, 0x1000016, Data);
  if ((int)*(short *)((int)pvVar2 + 0x134) < (int)Data)
  {
    *(undefined2 *)((int)pvVar2 + 0x134) = 0;
  }
  else
  {
    *(short *)((int)pvVar2 + 0x134) = *(short *)((int)pvVar2 + 0x134) - (short)Data;
  }
  GAMEPAD_Shock1(0x80 - (uint)((int)*(short *)((int)pvVar2 + 0x134) << 7) /
                            (uint)(*(int *)((int)pvVar2 + 0x100) << 0xc),
                 0xf000);
  if (*(short *)((int)pvVar2 + 0x134) == 0)
  {
    *(undefined2 *)((int)pvVar2 + 0x140) = 0;
    MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_ffffffe4, local_20));
    INSTANCE_Post(gameTrackerX.playerInstance, 0x1000006, (int)instance);
    *(undefined2 *)((int)pvVar2 + 0x134) = 0;
    SOUND_Play3dSound(&instance->position, 8, -0x1c2, 0x50, 0xdac);
  }
  else
  {
    if (bVar1)
    {
      *(uint *)((int)pvVar2 + 4) = *(uint *)((int)pvVar2 + 4) | 0x10;
      MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_ffffffe4, local_20));
    }
    else
    {
      if (instance->currentMainState == 0x1b)
      {
        return;
      }
      INSTANCE_Post(gameTrackerX.playerInstance, 0x1000006, (int)instance);
    }
    MON_TurnOnBodySpheres(instance);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HUMAN_IdleEntry(struct _Instance *instance /*$a0*/)
// line 431, offset 0x8007d330
/* begin block 1 */
// Start line: 432
// Start offset: 0x8007D330
// Variables:
// 		struct _MonsterVars *mv; // $s0
/* end block 1 */
// End offset: 0x8007D330
// End Line: 432

/* begin block 2 */
// Start line: 917
/* end block 2 */
// End Line: 918

void HUMAN_IdleEntry(_Instance *instance)

{
  void *pvVar1;

  pvVar1 = instance->extraData;
  MON_IdleEntry(instance);
  *(uint *)((int)pvVar1 + 4) = *(uint *)((int)pvVar1 + 4) & 0xfffffff8;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HUMAN_Idle(struct _Instance *instance /*$s1*/)
// line 440, offset 0x8007d378
/* begin block 1 */
// Start line: 441
// Start offset: 0x8007D378
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct _MonsterAttributes *ma; // $a3
// 		struct _MonsterIR *ally; // $v1
// 		struct _MonsterIR *enemy; // $a0
/* end block 1 */
// End offset: 0x8007D51C
// End Line: 491

/* begin block 2 */
// Start line: 935
/* end block 2 */
// End Line: 936

void HUMAN_Idle(_Instance *instance)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char *animList;
  int animtype;
  void *pvVar4;
  int mode;
  uint *puVar5;

  puVar5 = (uint *)instance->extraData;
  pvVar4 = instance->data;
  uVar1 = puVar5[0x33];
  uVar2 = puVar5[0x31];
  if ((((*puVar5 & 4) != 0) || (uVar1 == 0)) || ((*(ushort *)(uVar1 + 0x16) & 4) == 0))
  {
  LAB_8007d514:
    MON_Idle(instance);
    return;
  }
  uVar3 = puVar5[1];
  if ((uVar3 & 2) == 0)
  {
    if ((uVar3 & 1) == 0)
    {
      if ((uVar3 & 4) != 0)
      {
        if ((instance->flags2 & 0x10U) != 0)
        {
          puVar5[1] = uVar3 & 0xfffffffb;
          MON_PlayRandomIdle(instance, 2);
        }
        goto LAB_8007d504;
      }
      if ((1999 < *(short *)(uVar1 + 0x14)) || ((uVar2 != 0 && (*(short *)(uVar2 + 0x14) < 2000))))
        goto LAB_8007d514;
      animtype = 0;
      puVar5[1] = uVar3 | 2;
      animList = *(char **)((int)pvVar4 + 8);
      mode = 2;
    }
    else
    {
      if ((*(short *)(uVar1 + 0x14) < 2000) && ((uVar2 == 0 || (1999 < *(short *)(uVar2 + 0x14)))))
        goto LAB_8007d504;
      animtype = 1;
      puVar5[1] = uVar3 & 0xfffffffe | 4;
      animList = *(char **)((int)pvVar4 + 8);
      mode = 1;
    }
    MON_PlayAnimFromList(instance, animList, animtype, mode);
  }
  else
  {
    MON_TurnToPosition(instance, (_Position *)(*(int *)(uVar1 + 4) + 0x5c),
                       *(short *)(puVar5[0x55] + 0x1c));
    if ((instance->flags2 & 2U) != 0)
    {
      puVar5[1] = puVar5[1] & 0xfffffffd | 1;
    }
  }
LAB_8007d504:
  MON_DefaultQueueHandler(instance);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HUMAN_Flee(struct _Instance *instance /*$s1*/)
// line 496, offset 0x8007d530
/* begin block 1 */
// Start line: 497
// Start offset: 0x8007D530
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct _MonsterIR *enemy; // $s2

/* begin block 1.1 */
// Start line: 505
// Start offset: 0x8007D588
// Variables:
// 		struct _MonsterAttributes *ma; // $v0
/* end block 1.1 */
// End offset: 0x8007D5EC
// End Line: 517
/* end block 1 */
// End offset: 0x8007D670
// End Line: 535

/* begin block 2 */
// Start line: 1053
/* end block 2 */
// End Line: 1054

void HUMAN_Flee(_Instance *instance)

{
  uint uVar1;
  int sfxToneID;
  int pitch;
  int maxVolume;
  uint *puVar2;
  uint uVar3;
  undefined4 local_18;
  undefined4 in_stack_ffffffec;

  puVar2 = (uint *)instance->extraData;
  uVar3 = puVar2[0x31];
  if ((uVar3 == 0) || (0x27f < *(short *)(uVar3 + 0x14)))
  {
    if ((puVar2[1] & 8) == 0)
    {
      MON_Flee(instance);
    }
    else
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_ffffffec, local_18));
    }
  }
  else
  {
    if ((puVar2[1] & 8) == 0)
    {
      MON_PlayAnimFromList(instance, *(char **)((int)instance->data + 8), 2, 2);
      uVar1 = puVar2[1];
      puVar2[1] = uVar1 | 8;
      if ((uVar1 & 0x20) == 0)
      {
        sfxToneID = 0x1ca;
        pitch = -100;
        maxVolume = 0x5c;
      }
      else
      {
        sfxToneID = 0x1cb;
        pitch = 0;
        maxVolume = 0x58;
      }
      SOUND_Play3dSound(&instance->position, sfxToneID, pitch, maxVolume, 0xdac);
    }
    MON_TurnToPosition(instance, (_Position *)(*(int *)(uVar3 + 4) + 0x5c),
                       *(short *)(puVar2[0x55] + 0x1c));
    MON_DefaultQueueHandler(instance);
  }
  if (((puVar2[1] & 8) != 0) && ((*puVar2 & 1) != 0))
  {
    puVar2[1] = puVar2[1] & 0xfffffff7;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ HUMAN_GetAngry()
// line 540, offset 0x8007d688
/* begin block 1 */
// Start line: 541
// Start offset: 0x8007D688
// Variables:
// 		struct _Instance *instance; // $s0

/* begin block 1.1 */
// Start line: 548
// Start offset: 0x8007D6C4
// Variables:
// 		struct _MonsterVars *mv; // $v0
// 		struct _MonsterAllegiances *allegiances; // $a0
// 		struct _MonsterIR *mir; // $v1
/* end block 1.1 */
// End offset: 0x8007D72C
// End Line: 563
/* end block 1 */
// End offset: 0x8007D73C
// End Line: 565

/* begin block 2 */
// Start line: 1141
/* end block 2 */
// End Line: 1142

/* begin block 3 */
// Start line: 1144
/* end block 3 */
// End Line: 1145

/* WARNING: Unknown calling convention yet parameter storage is locked */

void HUMAN_GetAngry(void)

{
  ulong uVar1;
  _MonsterIR *p_Var2;
  uint *puVar3;
  _Instance *Inst;

  Inst = (gameTrackerX.instanceList)->first;
  while (Inst != (_Instance *)0x0)
  {
    uVar1 = INSTANCE_Query(Inst, 1);
    if ((uVar1 & 0xc000) != 0)
    {
      puVar3 = *(uint **)(*(int *)((int)Inst->extraData + 0x154) + 0xc);
      puVar3[3] = puVar3[3] & 0xfffffffe;
      puVar3[1] = puVar3[1] & 0xfffffffe;
      *puVar3 = *puVar3 | 1;
      p_Var2 = MONSENSE_SetEnemy(Inst, gameTrackerX.playerInstance);
      if (p_Var2 != (_MonsterIR *)0x0)
      {
        p_Var2->mirFlags = p_Var2->mirFlags & 0xfff9;
      }
    }
    Inst = Inst->next;
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ HUMAN_TypeOfHuman(struct _Instance *instance /*$s0*/)
// line 567, offset 0x8007d750
/* begin block 1 */
// Start line: 568
// Start offset: 0x8007D750
// Variables:
// 		int type; // $v1
// 		struct _MonsterVars *mv; // $a0
/* end block 1 */
// End offset: 0x8007D7AC
// End Line: 580

/* begin block 2 */
// Start line: 1219
/* end block 2 */
// End Line: 1220

int HUMAN_TypeOfHuman(_Instance *instance)

{
  ulong uVar1;
  int iVar2;

  uVar1 = INSTANCE_Query(instance, 1);
  iVar2 = 1;
  if (((((uVar1 & 0x4000) == 0) && (iVar2 = 4, (uVar1 & 0x2000) == 0)) &&
       (iVar2 = 0, (uVar1 & 0x8000) != 0)) &&
      (iVar2 = 3, (*(uint *)((int)instance->extraData + 4) & 0x20) == 0))
  {
    iVar2 = 2;
  }
  return iVar2;
}
