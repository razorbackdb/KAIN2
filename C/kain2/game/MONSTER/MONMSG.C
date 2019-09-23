#include "THISDUST.H"
#include "MONMSG.H"

// decompiled code
// original method signature:
// int /*$ra*/ MON_GroundMoveQueueHandler(struct _Instance *instance /*$s1*/)
// line 32, offset 0x800847b8
/* begin block 1 */
// Start line: 33
// Start offset: 0x800847B8
// Variables:
// 		struct _MonsterVars *mv; // $s3
// 		struct __Event *message; // $a1
// 		int ret; // $s0
/* end block 1 */
// End offset: 0x80084824
// End Line: 52

/* begin block 2 */
// Start line: 64
/* end block 2 */
// End Line: 65

int MON_GroundMoveQueueHandler(_Instance *instance)

{
  __Event *message;
  int iVar1;
  void *pvVar2;

  iVar1 = 0;
  pvVar2 = instance->extraData;
  while (true)
  {
    message = DeMessageQueue((__MessageQueue *)((int)pvVar2 + 8));
    if (message == (__Event *)0x0)
      break;
    if (message->ID == 0x4010080)
    {
      iVar1 = 0x4010080;
    }
    else
    {
      MON_IdleMessageHandler(instance, message);
    }
  }
  return iVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_PupateMessageHandler(struct _Instance *instance /*$s2*/, struct __Event *message /*$a1*/)
// line 60, offset 0x80084840
/* begin block 1 */
// Start line: 61
// Start offset: 0x80084840
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		long id; // $v1

/* begin block 1.1 */
// Start line: 72
// Start offset: 0x800848F4
// Variables:
// 		struct evMonsterAlarmData *data; // $s1
/* end block 1.1 */
// End offset: 0x8008497C
// End Line: 79

/* begin block 1.2 */
// Start line: 86
// Start offset: 0x800849BC
// Variables:
// 		struct evFXHitData data; // stack offset -40
/* end block 1.2 */
// End offset: 0x800849FC
// End Line: 93
/* end block 1 */
// End offset: 0x80084A6C
// End Line: 165

/* begin block 2 */
// Start line: 128
/* end block 2 */
// End Line: 129

/* WARNING: Type propagation algorithm not settling */

void MON_PupateMessageHandler(_Instance *instance, __Event *message)

{
  undefined2 uVar1;
  long lVar2;
  ulong uVar3;
  TDRFuncPtr_MONTABLE_GetDamageEffectFunc pTVar4;
  int iVar5;
  uint *puVar6;
  _Instance *p_Var7;
  undefined4 local_30;
  undefined4 in_stack_ffffffd4;
  evFXHitData eStack40;

  iVar5 = message->ID;
  puVar6 = (uint *)instance->extraData;
  if (iVar5 == 0x80005)
  {
    if ((*(char *)(puVar6[0x55] + 0x39) != '\0') && ((*puVar6 & 0x400) == 0))
    {
      MON_SetFXHitData(instance, &eStack40, 0x20, 1);
      *(undefined2 *)(puVar6 + 0x50) = 0x20;
      pTVar4 = MONTABLE_GetDamageEffectFunc(instance);
      (*pTVar4)(instance, &eStack40);
      MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_ffffffd4, local_30));
      return;
    }
  }
  else
  {
    if (iVar5 < 0x80006)
    {
      if (iVar5 < 0x80001)
      {
        return;
      }
      if (iVar5 < 0x80004)
      {
        return;
      }
      if (*(char *)(puVar6[0x55] + 0x3a) == '\0')
      {
        return;
      }
      MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_ffffffd4, local_30));
      uVar1 = 0x10;
      goto LAB_80084a68;
    }
    if (iVar5 == 0x1000000)
    {
      *puVar6 = *puVar6 & 0xffffff7f;
      return;
    }
    if (0x1000000 < iVar5)
    {
      if (iVar5 != 0x1000011)
      {
        return;
      }
      p_Var7 = (_Instance *)message->Data;
      lVar2 = MATH3D_LengthXYZ((int)*(short *)((int)&p_Var7->node + 4) - (int)(instance->position).x, (int)*(short *)((int)&p_Var7->node + 6) - (int)(instance->position).y,
                               (int)*(short *)&p_Var7->next - (int)(instance->position).z);
      if ((int)*(short *)(*(int *)(puVar6[0x55] + 4) + 0xe) <= lVar2)
      {
        return;
      }
      *puVar6 = *puVar6 & 0xffffff7f;
      if (puVar6[0x31] != 0)
      {
        return;
      }
      if (*(_Instance **)&p_Var7->node == (_Instance *)0x0)
      {
        return;
      }
      uVar3 = INSTANCE_Query(*(_Instance **)&p_Var7->node, 1);
      if ((uVar3 & 0xb) == 0)
      {
        return;
      }
      MONSENSE_SetEnemy(instance, *(_Instance **)&p_Var7->node);
      return;
    }
    if (iVar5 != 0x80006)
    {
      return;
    }
  }
  if (*(char *)(puVar6[0x55] + 0x38) == '\0')
  {
    return;
  }
  MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_ffffffd4, local_30));
  MON_MonsterGlow(instance, 0xffffff, 0x46, 10, 0x14);
  uVar1 = 0x40;
LAB_80084a68:
  *(undefined2 *)(puVar6 + 0x50) = uVar1;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_IdleMessageHandler(struct _Instance *instance /*$s2*/, struct __Event *message /*$s0*/)
// line 167, offset 0x80084a84
/* begin block 1 */
// Start line: 168
// Start offset: 0x80084A84
// Variables:
// 		struct _MonsterVars *mv; // $s1
// 		long id; // $v1

/* begin block 1.1 */
// Start line: 199
// Start offset: 0x80084B10
// Variables:
// 		struct _MonsterIR *mir; // $v0
/* end block 1.1 */
// End offset: 0x80084B3C
// End Line: 202

/* begin block 1.2 */
// Start line: 208
// Start offset: 0x80084B64
// Variables:
// 		struct _MonsterIR *mir; // $v0
/* end block 1.2 */
// End offset: 0x80084B90
// End Line: 211
/* end block 1 */
// End offset: 0x80084BB0
// End Line: 218

/* begin block 2 */
// Start line: 348
/* end block 2 */
// End Line: 349

void MON_IdleMessageHandler(_Instance *instance, __Event *message)

{
  ulong uVar1;
  undefined4 local_10;
  undefined4 local_c;
  uint *puVar2;

  puVar2 = (uint *)instance->extraData;
  switch (message->ID)
  {
  case 0x1000002:
  case 0x100000a:
  case 0x1000023:
    if (message->Data == 0)
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
    }
  default:
    MON_DefaultMessageHandler(instance, message);
    break;
  case 0x100000e:
    if ((*puVar2 & 4) == 0)
    {
      uVar1 = INSTANCE_Query(*(_Instance **)(message->Data + 4), 1);
      if ((uVar1 & 1) != 0)
      {
        MON_ChangeBehavior(instance, (uint) * (byte *)(puVar2 + 0x52));
      }
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
    }
    break;
  case 0x1000012:
    if ((*puVar2 & 4) == 0)
    {
      uVar1 = INSTANCE_Query(*(_Instance **)(message->Data + 4), 1);
      if ((uVar1 & 1) != 0)
      {
        MON_ChangeBehavior(instance, (uint) * (byte *)(puVar2 + 0x52));
      }
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_DefaultMessageHandler(struct _Instance *instance /*$s2*/, struct __Event *message /*$s3*/)
// line 220, offset 0x80084bc8
/* begin block 1 */
// Start line: 221
// Start offset: 0x80084BC8
// Variables:
// 		struct _MonsterAttributes *ma; // $a1
// 		struct _MonsterVars *mv; // $s1
// 		long id; // $a0

/* begin block 1.1 */
// Start line: 232
// Start offset: 0x80084E94
// Variables:
// 		struct evMonsterHitData *data; // $s5
// 		int fatal; // $s4
// 		int damage; // $s0

/* begin block 1.1.1 */
// Start line: 296
// Start offset: 0x80084EEC
// Variables:
// 		struct _MonsterCombatAttributes *combat; // $s0
/* end block 1.1.1 */
// End offset: 0x80084EEC
// End Line: 296
/* end block 1.1 */
// End offset: 0x80084F7C
// End Line: 329

/* begin block 1.2 */
// Start line: 333
// Start offset: 0x80084FA4
// Variables:
// 		int state; // $a1
// 		struct evMonsterHitData *data; // $s0
/* end block 1.2 */
// End offset: 0x80085048
// End Line: 372

/* begin block 1.3 */
// Start line: 395
// Start offset: 0x800850A4
// Variables:
// 		struct evMonsterSoulSuckData *data; // $v0
/* end block 1.3 */
// End offset: 0x800850DC
// End Line: 399

/* begin block 1.4 */
// Start line: 437
// Start offset: 0x800851C8
// Variables:
// 		int vuln; // $s0
/* end block 1.4 */
// End offset: 0x800852A4
// End Line: 471

/* begin block 1.5 */
// Start line: 486
// Start offset: 0x800852FC
/* end block 1.5 */
// End offset: 0x80085360
// End Line: 490

/* begin block 1.6 */
// Start line: 530
// Start offset: 0x800853F8
// Variables:
// 		struct evMonsterAlarmData *data; // $s0
// 		struct _Instance *enemy; // $s3

/* begin block 1.6.1 */
// Start line: 537
// Start offset: 0x8008543C

/* begin block 1.6.1.1 */
// Start line: 542
// Start offset: 0x80085488
// Variables:
// 		struct _MonsterIR *mir; // $v0
/* end block 1.6.1.1 */
// End offset: 0x800854A0
// End Line: 547
/* end block 1.6.1 */
// End offset: 0x800854A0
// End Line: 548
/* end block 1.6 */
// End offset: 0x800854A0
// End Line: 552

/* begin block 1.7 */
// Start line: 558
// Start offset: 0x800854BC
// Variables:
// 		struct _MonsterIR *mir; // $v0
/* end block 1.7 */
// End offset: 0x800854DC
// End Line: 560

/* begin block 1.8 */
// Start line: 566
// Start offset: 0x80085508
// Variables:
// 		int hp; // $v1
/* end block 1.8 */
// End offset: 0x80085524
// End Line: 569

/* begin block 1.9 */
// Start line: 602
// Start offset: 0x800855B8
// Variables:
// 		struct evFXHitData data; // stack offset -80
/* end block 1.9 */
// End offset: 0x800855F8
// End Line: 609

/* begin block 1.10 */
// Start line: 668
// Start offset: 0x80085720
// Variables:
// 		struct evFXHitData data; // stack offset -56
/* end block 1.10 */
// End offset: 0x80085720
// End Line: 669

/* begin block 1.11 */
// Start line: 683
// Start offset: 0x800857B0
/* end block 1.11 */
// End offset: 0x800857B0
// End Line: 686

/* begin block 1.12 */
// Start line: 701
// Start offset: 0x80085810
// Variables:
// 		struct evPositionData *posData; // $a0
/* end block 1.12 */
// End offset: 0x80085810
// End Line: 701

/* begin block 1.13 */
// Start line: 709
// Start offset: 0x80085830
// Variables:
// 		struct evPositionData *posData; // $v1
/* end block 1.13 */
// End offset: 0x80085830
// End Line: 709

/* begin block 1.14 */
// Start line: 719
// Start offset: 0x80085870
// Variables:
// 		struct evPositionData *posData; // $v1
/* end block 1.14 */
// End offset: 0x80085870
// End Line: 719

/* begin block 1.15 */
// Start line: 732
// Start offset: 0x800858BC
// Variables:
// 		static int deaths[9]; // offset 0x0
/* end block 1.15 */
// End offset: 0x800858BC
// End Line: 743

/* begin block 1.16 */
// Start line: 749
// Start offset: 0x800858E8
// Variables:
// 		struct evMonsterHitData *data; // $s0
/* end block 1.16 */
// End offset: 0x800858E8
// End Line: 749

/* begin block 1.17 */
// Start line: 756
// Start offset: 0x80085924
// Variables:
// 		int i; // $s1
// 		struct evActionPlayHostAnimationData *data; // $s0
/* end block 1.17 */
// End offset: 0x8008597C
// End Line: 760

/* begin block 1.18 */
// Start line: 764
// Start offset: 0x80085984
// Variables:
// 		struct evAnimationInstanceSwitchData *data; // $v0
/* end block 1.18 */
// End offset: 0x8008599C
// End Line: 766
/* end block 1 */
// End offset: 0x8008599C
// End Line: 771

/* begin block 2 */
// Start line: 459
/* end block 2 */
// End Line: 460

/* WARNING: Type propagation algorithm not settling */

void MON_DefaultMessageHandler(_Instance *instance, __Event *message)

{
  ushort uVar1;
  short sVar2;
  bool bVar3;
  short sVar4;
  ulong uVar5;
  long lVar6;
  TDRFuncPtr_MONTABLE_GetDamageEffectFunc pTVar7;
  uint CurrentSection;
  short *psVar8;
  uint uVar9;
  undefined *puVar10;
  _MonsterIR *Data;
  int iVar11;
  byte bVar12;
  _MonsterCombatAttributes *p_Var13;
  _Instance *p_Var14;
  int Data_00;
  _MonsterVars *mv;
  _Instance *Inst;
  undefined4 local_60;
  undefined4 local_5c;
  evFXHitData eStack80;
  evFXHitData eStack56;

  puVar10 = (undefined *)message->ID;
  mv = (_MonsterVars *)instance->extraData;
  if ((int)puVar10 < 0x1000009)
  {
    if (0x1000006 < (int)puVar10)
    {
      return;
    }
    if (puVar10 == (undefined *)0x80001)
    {
      if (instance->zVel != 0)
      {
        return;
      }
      if ((mv->mvFlags & 0x200000) != 0)
      {
        return;
      }
      sVar4 = MATH3D_AngleFromPosToPos(&(gameTrackerX.playerInstance)->position, &instance->position);
      (instance->position).z = (instance->position).z + 0x78;
      (instance->oldPos).z = (instance->oldPos).z + 0x78;
      MON_LaunchMonster(instance, (int)sVar4, 100, 0x46);
      return;
    }
    if ((int)puVar10 < 0x80002)
    {
      if (puVar10 == &DAT_0004000d)
      {
        Data_00 = message->Data;
        mv->auxFlags = mv->auxFlags | 0x10000000;
        (mv->destination).z = *(short *)(Data_00 + 4);
        return;
      }
      if ((int)puVar10 < 0x4000e)
      {
        if (puVar10 == (undefined *)0x40009)
        {
          mv->damageType = 0x2000;
        LAB_80085800:
          MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
          return;
        }
        if ((int)puVar10 < 0x4000a)
        {
          if (puVar10 != &DAT_00040003)
          {
            return;
          }
          CurrentSection = (uint)mv->subAttr->numSections;
          Data_00 = message->Data;
          while (CurrentSection = CurrentSection - 1, -1 < (int)CurrentSection)
          {
            G2EmulationInstanceToInstanceSwitchAnimation(instance, *(_Instance **)(Data_00 + 4), CurrentSection, *(int *)(Data_00 + 8),
                                                         *(int *)(Data_00 + 0xc), *(int *)(Data_00 + 0x10), *(int *)(Data_00 + 0x14));
          }
          return;
        }
        if (puVar10 != &DAT_0004000c)
        {
          return;
        }
      }
      else
      {
        if (puVar10 == &DAT_00040010)
        {
          CurrentSection = mv->mvFlags;
          uVar9 = 0x7fffffff;
        LAB_800858b0:
          mv->mvFlags = CurrentSection & uVar9;
          return;
        }
        if ((int)puVar10 < 0x40011)
        {
          if (puVar10 != &DAT_0004000f)
          {
            return;
          }
          psVar8 = (short *)message->Data;
          mv->mvFlags = mv->mvFlags | 0x80000000;
          (mv->lookAtPosData).x = *psVar8;
          (mv->lookAtPosData).y = psVar8[1];
          (mv->lookAtPosData).z = psVar8[2];
          return;
        }
        if (puVar10 != &DAT_00040016)
        {
          if (puVar10 != &DAT_00040017)
          {
            return;
          }
          mv->damageType = *(ushort *)(&DAT_800ca9c8 + message->Data * 4);
          MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
          return;
        }
      }
      psVar8 = (short *)message->Data;
      (mv->destination).x = *psVar8;
      (mv->destination).y = psVar8[1];
      sVar4 = psVar8[2];
      mv->mvFlags = mv->mvFlags | 0x40000;
      (mv->destination).z = sVar4;
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
      return;
    }
    if (puVar10 == (undefined *)0x80005)
    {
      if (mv->subAttr->fireVuln != '\0')
      {
        MON_SetFXHitData(instance, &eStack80, 0x20, 1);
        mv->damageType = 0x20;
        pTVar7 = MONTABLE_GetDamageEffectFunc(instance);
        (*pTVar7)(instance, &eStack80);
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
        return;
      }
    }
    else
    {
      if ((int)puVar10 < 0x80006)
      {
        if (puVar10 == (undefined *)0x80003)
        {
          if (mv->subAttr->soundVuln != '\0')
          {
            MON_SetFXHitData(instance, &eStack56, 0x200, 0x10);
            mv->damageType = 0x200;
            mv->hitPoints = 0;
            mv->mvFlags = mv->mvFlags | 0x800000;
            pTVar7 = MONTABLE_GetDamageEffectFunc(instance);
            (*pTVar7)(instance, &eStack56);
            goto LAB_80085800;
          }
          Data = (_MonsterIR *)
              SetMonsterAlarmData(gameTrackerX.playerInstance,
                                  &(gameTrackerX.playerInstance)->position, 2);
          Data_00 = 0x1000011;
        }
        else
        {
          if ((int)puVar10 < 0x80004)
          {
            if (instance->petrifyValue != 0)
            {
              return;
            }
            MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
            instance->petrifyValue = 0x1000;
            return;
          }
          if ((mv->subAttr->waterVuln != '\0') && ((*(uint *)((int)instance->data + 0x10) & 8) == 0))
          {
            MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
            MON_MonsterGlow(instance, 0xff0000, 0x46, 10, 0x14);
            mv->damageType = 0x10;
            return;
          }
          Data = (_MonsterIR *)
              SetMonsterAlarmData(gameTrackerX.playerInstance,
                                  &(gameTrackerX.playerInstance)->position, 2);
          Data_00 = 0x1000011;
        }
        goto LAB_80085914;
      }
      if (puVar10 == (undefined *)0x400000)
      {
        pTVar7 = MONTABLE_GetDamageEffectFunc(instance);
        (*pTVar7)(instance, message->Data);
        return;
      }
      if (0x400000 < (int)puVar10)
      {
        if (puVar10 != (undefined *)0x1000000)
        {
          if (puVar10 != (undefined *)0x1000002)
          {
            return;
          }
          if (message->Data == 0)
          {
            Data = mv->enemy;
            if (Data == (_MonsterIR *)0x0)
            {
              return;
            }
            Data->mirConditions = Data->mirConditions | 0x40;
            return;
          }
          MONSENSE_SetEnemy(instance, gameTrackerX.playerInstance);
          MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
          CurrentSection = mv->mvFlags;
          uVar9 = 0xfffffffd;
          goto LAB_800858b0;
        }
        goto LAB_80084f7c;
      }
      if (puVar10 != (undefined *)0x80006)
      {
        return;
      }
    }
    if ((*(uint *)((int)instance->data + 0x10) & 0x10008) == 0)
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
      MON_MonsterGlow(instance, 0xffffff, 0x46, 10, 0x14);
      mv->damageType = 0x40;
      return;
    }
    Data = (_MonsterIR *)
        SetMonsterAlarmData(gameTrackerX.playerInstance, &(gameTrackerX.playerInstance)->position,
                            2);
    Data_00 = 0x1000011;
  }
  else
  {
    if (puVar10 == (undefined *)0x1000016)
    {
      if (mv->subAttr->combatAttributes->hitPoints == '\0')
      {
        return;
      }
      Data_00 = (int)mv->hitPoints + message->Data;
      sVar4 = (short)Data_00;
      if (0x6000 < Data_00)
      {
        sVar4 = 0x6000;
      }
    LAB_80085598:
      mv->hitPoints = sVar4;
      return;
    }
    if (0x1000016 < (int)puVar10)
    {
      if (puVar10 != (undefined *)0x1000021)
      {
        if (0x1000021 < (int)puVar10)
        {
          if (puVar10 != (undefined *)0x2000002)
          {
            if (0x2000002 < (int)puVar10)
            {
              if (puVar10 == (undefined *)0x4010080)
              {
                return;
              }
              if (puVar10 != (undefined *)0x8000008)
              {
                return;
              }
              MON_PlayAnimID(instance, *(int *)(message->Data + 4), *(int *)(message->Data + 0x10));
              return;
            }
            if (puVar10 != (undefined *)0x1000023)
            {
              return;
            }
            if (message->Data == 0)
            {
              return;
            }
            if (message->Data == 0x1000)
            {
              MONSENSE_SetEnemy(instance, gameTrackerX.playerInstance);
              mv->damageType = 0x400;
              instance->flags2 = instance->flags2 | 0x1000;
              MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
              return;
            }
            goto LAB_80085800;
          }
          p_Var14 = (_Instance *)message->Data;
          Data = (_MonsterIR *)
              SetMonsterHitData(instance, (_Instance *)0x0, (int)p_Var14->prev,
                                (int)mv->attackType->knockBackDistance,
                                (int)mv->attackType->knockBackDuration);
          Data_00 = 0x1000000;
          instance = *(_Instance **)&p_Var14->node;
          goto LAB_80085914;
        }
        if (puVar10 == (undefined *)0x100001a)
        {
          if (message->Data != 0)
          {
            if ((mv->mvFlags & 0x20000000) != 0)
            {
              return;
            }
            mv->mvFlags = mv->mvFlags | 0x20000000;
            mv->hitPoints = (short)((int)mv->hitPoints << 1);
            return;
          }
          if ((mv->mvFlags & 0x20000000) == 0)
          {
            return;
          }
          mv->mvFlags = mv->mvFlags & 0xdfffffff;
          CurrentSection = (int)mv->hitPoints + 1;
          sVar4 = (short)((int)(CurrentSection + (CurrentSection >> 0x1f)) >> 1);
          goto LAB_80085598;
        }
        if ((int)puVar10 < 0x100001b)
        {
          if (puVar10 != (undefined *)0x1000019)
          {
            return;
          }
          MONSENSE_SetEnemy(instance, gameTrackerX.playerInstance);
          mv->held = (_Instance *)message->Data;
          MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
          return;
        }
        if (puVar10 == (undefined *)0x100001c)
        {
          mv->terrainImpaleID = message->Data;
          MON_MoveInstanceToImpalePoint(instance);
          MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
          return;
        }
        if (puVar10 != (undefined *)0x100001f)
        {
          return;
        }
      }
      bVar3 = false;
      if ((mv->mvFlags & 0x200040) != 0)
      {
        return;
      }
      iVar11 = message->Data;
      uVar1 = *(ushort *)(iVar11 + 0xc);
      mv->damageType = uVar1;
      Data_00 = 0;
      if (uVar1 == 0x20)
      {
        if ((puVar10 == (undefined *)0x1000021) &&
            (uVar5 = INSTANCE_Query(instance, 0), (uVar5 & 0x10000000) != 0))
        {
          bVar3 = true;
        }
        else
        {
          p_Var13 = mv->subAttr->combatAttributes;
          mv->mvFlags = mv->mvFlags | 0x800110;
          uVar5 = MON_GetTime(instance);
          mv->damageTimer = uVar5 + (int)p_Var13->damageTime;
          uVar5 = MON_GetTime(instance);
          Data_00 = 0x6000;
          mv->stunTimer = uVar5 + (int)p_Var13->stunTime;
        }
      }
      else
      {
        Data_00 = 0x3000;
        if ((instance->flags2 & 0x8000000U) != 0)
        {
          Data_00 = 0x2000;
        }
      }
      if (bVar3)
      {
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
      }
      if (Data_00 == 0)
      {
        mv->mvFlags = mv->mvFlags | 0x40;
        return;
      }
      *(int *)(iVar11 + 0xc) = Data_00;
    LAB_80084f7c:
      if (((mv->mvFlags & 0x200040) == 0) && (instance->currentMainState != 10))
      {
        p_Var14 = (_Instance *)message->Data;
        if (0x2fff < (int)p_Var14->prev)
        {
          instance->constrictAngle = 0;
        }
        mv->mvFlags = mv->mvFlags | 0x40;
        uVar5 = INSTANCE_Query(*(_Instance **)&p_Var14->node, 1);
        Inst = gameTrackerX.playerInstance;
        if (uVar5 != 0x20)
        {
          Inst = *(_Instance **)&p_Var14->node;
        }
        MONSENSE_SetEnemy(instance, Inst);
        Data_00 = MON_TakeDamage(instance, (int)p_Var14->prev, 0x100);
        iVar11 = 8;
        if ((Data_00 != 0) && (iVar11 = 9, (mv->mvFlags & 0x2000) != 0))
        {
          iVar11 = 0x10;
        }
        if (iVar11 != -1)
        {
          MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
        }
        mv->damageType = 0x100;
        *(_Instance **)&mv->messageData = p_Var14;
      }
      return;
    }
    if (puVar10 == (undefined *)0x100000c)
    {
      if (((mv->mvFlags & 1) != 0) && (instance->currentMainState == 0xb))
      {
        return;
      }
      Data_00 = message->Data;
      if (Data_00 == 0x20)
      {
        bVar12 = 0;
        if ((mv->mvFlags & 0x400) == 0)
        {
          bVar12 = mv->subAttr->fireVuln;
        }
      }
      else
      {
        if (Data_00 < 0x21)
        {
          bVar12 = 0;
          if (Data_00 == 0x10)
          {
            bVar12 = mv->subAttr->waterVuln;
          }
        }
        else
        {
          bVar12 = 0;
          if (Data_00 == 0x40)
          {
            bVar12 = mv->subAttr->sunVuln;
          }
        }
      }
      if (bVar12 != 0)
      {
        mv->damageType = *(ushort *)&message->Data;
        Data_00 = SetFXHitData((_Instance *)0x0, 0, 0, message->Data);
        INSTANCE_Post(instance, 0x400000, Data_00);
      }
      if (bVar12 == 1)
      {
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
        return;
      }
      if (bVar12 == 0)
      {
        return;
      }
      if (3 < bVar12)
      {
        return;
      }
      mv->mvFlags = mv->mvFlags | 0x200000;
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
      return;
    }
    if ((int)puVar10 < 0x100000d)
    {
      if (puVar10 == (undefined *)0x100000a)
      {
        p_Var14 = (_Instance *)message->Data;
        if (p_Var14 != (_Instance *)0x0)
        {
          mv->held = *(_Instance **)&p_Var14->node;
          Data_00 = rsin((int)*(short *)&p_Var14->next);
          Data_00 = (int)*(short *)((int)&p_Var14->instanceID + 2) * Data_00;
          if (Data_00 < 0)
          {
            Data_00 = Data_00 + 0xfff;
          }
          sVar4 = *(short *)&p_Var14->prev;
          iVar11 = rcos((int)*(short *)&p_Var14->next);
          iVar11 = (int)*(short *)((int)&p_Var14->instanceID + 2) * iVar11;
          if (iVar11 < 0)
          {
            iVar11 = iVar11 + 0xfff;
          }
          sVar2 = *(short *)((int)&p_Var14->prev + 2);
          (instance->position).x = sVar4 + (short)(Data_00 >> 0xc);
          (instance->position).y = sVar2 - (short)(iVar11 >> 0xc);
          (instance->rotation).z = *(short *)&p_Var14->next + 0x800U & 0xfff;
          MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
          return;
        }
        Data = mv->enemy;
        if (Data == (_MonsterIR *)0x0)
        {
          return;
        }
        Data->mirConditions = Data->mirConditions | 0x80;
        return;
      }
      if (0x100000a < (int)puVar10)
      {
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
        return;
      }
      Data_00 = message->Data;
      lVar6 = MATH3D_LengthXYZ((int)(instance->position).x - (int)*(short *)(Data_00 + 4),
                               (int)(instance->position).y - (int)*(short *)(Data_00 + 6),
                               (int)(instance->position).z - (int)*(short *)(Data_00 + 8));
      if (6999 < lVar6)
      {
        return;
      }
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
      return;
    }
    if (puVar10 != (undefined *)0x1000011)
    {
      if ((int)puVar10 < 0x1000012)
      {
        if (puVar10 != (undefined *)0x100000e)
        {
          return;
        }
      }
      else
      {
        if (puVar10 != (undefined *)0x1000012)
        {
          if (puVar10 != (undefined *)0x1000014)
          {
            return;
          }
          if (message->Data == 0)
          {
            return;
          }
          if (mv->soulJuice < 0x2000)
          {
            mv->soulJuice = 0;
            mv->damageType = 0;
            MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
            return;
          }
          MON_SwitchState(instance, (MonsterState)CONCAT44(local_5c, local_60));
          return;
        }
      }
      if ((mv->mvFlags & 4) != 0)
      {
        return;
      }
      uVar5 = INSTANCE_Query(*(_Instance **)(message->Data + 4), 1);
      if ((uVar5 & 1) == 0)
      {
        return;
      }
      mv->behaviorState = mv->triggeredBehavior;
      return;
    }
    p_Var14 = (_Instance *)message->Data;
    Inst = *(_Instance **)&p_Var14->node;
    if (Inst == (_Instance *)0x0)
    {
      return;
    }
    uVar5 = INSTANCE_Query(Inst, 1);
    if ((uVar5 & 0xb) == 0)
    {
      return;
    }
    Data = MONSENSE_FindIR(mv, Inst);
    if (Data != (_MonsterIR *)0x0)
    {
      return;
    }
    lVar6 = MATH3D_LengthXYZ((int)(instance->position).x - (int)*(short *)((int)&p_Var14->node + 4),
                             (int)(instance->position).y - (int)*(short *)((int)&p_Var14->node + 6),
                             (int)(instance->position).z - (int)*(short *)&p_Var14->next);
    if ((int)mv->subAttr->senses->alarmRadius <= lVar6)
    {
      return;
    }
    Data = MONSENSE_SetEnemy(instance, Inst);
    if (Data == (_MonsterIR *)0x0)
    {
      return;
    }
    Data_00 = 0x1000012;
  }
LAB_80085914:
  INSTANCE_Post(instance, Data_00, (int)Data);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_PupateQueueHandler(struct _Instance *instance /*$s0*/)
// line 773, offset 0x800859c0
/* begin block 1 */
// Start line: 774
// Start offset: 0x800859C0
// Variables:
// 		struct _MonsterVars *mv; // $s1
// 		struct __Event *message; // $v0
/* end block 1 */
// End offset: 0x800859F8
// End Line: 780

/* begin block 2 */
// Start line: 1633
/* end block 2 */
// End Line: 1634

void MON_PupateQueueHandler(_Instance *instance)

{
  __Event *message;
  void *pvVar1;

  pvVar1 = instance->extraData;
  while (message = DeMessageQueue((__MessageQueue *)((int)pvVar1 + 8)), message != (__Event *)0x0)
  {
    MON_PupateMessageHandler(instance, message);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_IdleQueueHandler(struct _Instance *instance /*$s0*/)
// line 782, offset 0x80085a0c
/* begin block 1 */
// Start line: 783
// Start offset: 0x80085A0C
// Variables:
// 		struct _MonsterVars *mv; // $s1
// 		struct __Event *message; // $v0
/* end block 1 */
// End offset: 0x80085A44
// End Line: 789

/* begin block 2 */
// Start line: 1651
/* end block 2 */
// End Line: 1652

void MON_IdleQueueHandler(_Instance *instance)

{
  __Event *message;
  void *pvVar1;

  pvVar1 = instance->extraData;
  while (message = DeMessageQueue((__MessageQueue *)((int)pvVar1 + 8)), message != (__Event *)0x0)
  {
    MON_IdleMessageHandler(instance, message);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_DefaultQueueHandler(struct _Instance *instance /*$s0*/)
// line 791, offset 0x80085a58
/* begin block 1 */
// Start line: 792
// Start offset: 0x80085A58
// Variables:
// 		struct _MonsterVars *mv; // $s1
// 		struct __Event *message; // $v0
/* end block 1 */
// End offset: 0x80085A90
// End Line: 798

/* begin block 2 */
// Start line: 1669
/* end block 2 */
// End Line: 1670

void MON_DefaultQueueHandler(_Instance *instance)

{
  __Event *message;
  void *pvVar1;

  pvVar1 = instance->extraData;
  while (message = DeMessageQueue((__MessageQueue *)((int)pvVar1 + 8)), message != (__Event *)0x0)
  {
    MON_DefaultMessageHandler(instance, message);
  }
  return;
}
