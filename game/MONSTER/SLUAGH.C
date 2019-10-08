#include "THISDUST.H"
#include "SLUAGH.H"

u_long SLUAGH_Query(_Instance *instance, u_long query)

{
  u_long uVar1;
  void *pvVar2;

  pvVar2 = instance->extraData;
  if (query == 0)
  {
    if ((*(u_int *)((int)pvVar2 + 4) & 1) == 0)
    {
      uVar1 = ((u_int) * (byte *)((int)pvVar2 + 1) & 1) << 0x1d;
    }
    else
    {
      uVar1 = 0x4000000;
    }
  }
  else
  {
    if (query == 1)
    {
      if ((*(u_int *)((int)pvVar2 + 4) & 1) == 0)
      {
        uVar1 = *(u_long *)((int)instance->data + 0x10);
      }
      else
      {
        uVar1 = *(u_int *)((int)instance->data + 0x10) | 4;
      }
    }
    else
    {
      uVar1 = MonsterQuery(instance, query);
    }
  }
  return uVar1;
}

void SLUAGH_DamageEffect(_Instance *instance, evFXHitData *data)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  u_int *puVar4;
  u_int uVar5;
  u_char local_30;
  undefined *local_2c;
  u_char local_28;
  u_char local_20;
  u_int local_18;

  if (data == (evFXHitData *)0x0)
  {
    puVar4 = (u_int *)instance->extraData;
    uVar5 = puVar4[0x37];
    if (uVar5 != 0)
    {
      iVar3 = (int)*(short *)(puVar4 + 0x50);
      if (iVar3 < 0)
      {
        iVar3 = iVar3 + 0xfff;
      }
      local_18 = FX_GetHealthColor(iVar3 >> 0xc);
      if (*(u_int *)(uVar5 + 0x18) != local_18)
      {
        local_28 = *(u_int *)(uVar5 + 0x18);
        bVar1 = (char)local_28 - 4;
        if (((local_18 & 0xff) < (local_28 & 0xff)) ||
            (bVar1 = (char)local_28 + 4, (local_28 & 0xff) < (local_18 & 0xff)))
        {
          local_28 = local_28 & 0xffffff00 | (u_int)bVar1;
        }
        local_20._1_1_ = (byte)(local_18 >> 8);
        cVar2 = local_28._1_1_ - 4;
        if ((local_20._1_1_ < local_28._1_1_) ||
            (cVar2 = local_28._1_1_ + 4, local_28._1_1_ < local_20._1_1_))
        {
          local_28._0_2_ = CONCAT11(cVar2, (char)local_28);
          local_28 = local_28 & 0xffff0000 | (u_int)(u_short)local_28;
        }
        local_20._2_1_ = (byte)(local_18 >> 0x10);
        cVar2 = local_28._2_1_ - 4;
        if ((local_20._2_1_ < local_28._2_1_) ||
            (cVar2 = local_28._2_1_ + 4, local_28._2_1_ < local_20._2_1_))
        {
          local_28._0_3_ = CONCAT12(cVar2, (u_short)local_28);
          local_28 = local_28 & 0xff000000 | (u_int)(u_int3)local_28;
        }
        *(u_int *)(uVar5 + 0x18) = local_28;
        local_20 = local_18;
      }
    }
    if (((puVar4[1] & 1) != 0) && (*(short *)(puVar4 + 0x50) != 0))
    {
      *puVar4 = *puVar4 & 0xffdfffff;
      *(undefined *)((int)puVar4 + 0x156) = *(undefined *)(puVar4 + 0x56);
      puVar4[1] = puVar4[1] & 0xfffffffe;
      MON_StartSpecialFade(instance, 0, 0x14);
    }
  }
  else
  {
    local_30 = 0;
    local_2c = &DAT_0000fffe;
    FX_BloodCone((_SVector *)data, &data->velocity, (_SVector *)&local_30, (int)data->amount, 0x308000, 8);
    FX_MakeSpark((_SVector *)data);
  }
  return;
}

void SLUAGH_Attack(_Instance *instance)

{
  _FXGlowEffect *p_Var1;
  int iVar2;
  u_int *puVar3;
  void *pvVar4;
  long local_18[2];

  puVar3 = (u_int *)instance->extraData;
  iVar2 = (int)*(short *)(puVar3 + 0x50);
  pvVar4 = instance->data;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xfff;
  }
  local_18[0] = FX_GetHealthColor(iVar2 >> 0xc);
  p_Var1 = FX_DoInstanceTwoSegmentGlow(instance, (u_int) * (byte *)((int)pvVar4 + 0x19), local_18, 1, 0x4b0, 0x68, 0x70);
  *(_FXGlowEffect **)(puVar3 + 0x37) = p_Var1;
  MON_SetDefaults(instance);
  *(undefined2 *)(puVar3 + 0x51) = 0x2000;
  puVar3[1] = puVar3[1] & 0xfffffffe;
  *puVar3 = *puVar3 | 0x2002000;
  return;
}

void SLUAGH_Death(_Instance *instance)

{
  int iVar1;
  u_char local_10;
  u_int *puVar2;
  u_char local_c;
  u_char local_8;
  u_char in_stack_fffffffc;

  puVar2 = (u_int *)instance->extraData;
  FX_StopAllGlowEffects((_FXGlowEffect *)puVar2[0x37], 0);
  puVar2[0x37] = 0;
  if (puVar2[0x31] != 0)
  {
    iVar1 = MON_SetUpKnockBack(instance, *(_Instance **)(puVar2[0x31] + 4),
                               (evMonsterHitData *)puVar2[0x30]);
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(local_8, CONCAT44(local_c, local_10))),
                 (u_int)(iVar1 == 0));
  }
  *(undefined *)((int)puVar2 + 0x156) = 9;
  if ((puVar2[1] & 1) == 0)
  {
    MON_BirthEntry(instance);
    puVar2[1] = puVar2[1] | 1;
  }
  *puVar2 = *puVar2 | 0x200000;
  MON_StartSpecialFade(instance, 0x800, 0x14);
  return;
}

void SLUAGH_DeathEntry(_Instance *instance)

{
  u_char local_8;
  u_char local_4;
  undefined8 uStackX0;

  if ((instance->flags2 & 0x10U) != 0)
  {
    MON_PlayAnim(instance, (MonsterAnim)CONCAT88(uStackX0, CONCAT44(local_4, local_8)), 0x18);
  }
  if ((instance->flags2 & 2U) != 0)
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_4, local_8));
  }
  MON_DefaultMessageHandler(instance);
  return;
}

void SLUAGH_AttackEntry(_Instance *instance)

{
  u_char unaff_s0;
  void *pvVar1;
  u_char unaff_retaddr;
  undefined8 uStackX0;

  pvVar1 = instance->extraData;
  if ((*(u_short *)(*(int *)((int)pvVar1 + 0xc4) + 0x16) & 8) == 0)
  {
    MON_Attack(instance);
  }
  else
  {
    MON_PlayAnim(instance, (MonsterAnim)CONCAT88(uStackX0, CONCAT44(unaff_retaddr, unaff_s0)), 0x1e);
    *(u_int *)((int)pvVar1 + 4) = *(u_int *)((int)pvVar1 + 4) | 4;
  }
  return;
}

void SLUAGH_Init(_Instance *instance)

{
  __Event *message;
  int Data;
  u_char local_10;
  u_char local_c;
  void *pvVar1;

  pvVar1 = instance->extraData;
  if ((*(u_int *)((int)pvVar1 + 4) & 4) == 0)
  {
    MON_ChooseAttack(instance);
  }
  else
  {
    if ((instance->flags2 & 0x10U) != 0)
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
    }
    while (message = PurgeMessageQueue((__MessageQueue *)((int)pvVar1 + 8)),
           message != (__Event *)0x0)
    {
      if (message->ID == 0x1000009)
      {
        if (*(_Instance **)&((_Instance *)message->Data)->node != gameTrackerX.playerInstance)
        {
          MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
        }
      }
      else
      {
        MON_PupateMessageHandler(instance, message);
      }
    }
    if ((instance->currentMainState == 6) && (*(int *)((int)pvVar1 + 0xc4) != 0))
    {
      Data = SetMonsterHitData(instance, (int)(instance->position).x, (int)(instance->position).y,
                               (int)(instance->position).z);
      INSTANCE_Query(*(_Instance **)(*(int *)((int)pvVar1 + 0xc4) + 4), 0x1000009, Data);
    }
    else
    {
      *(u_int *)((int)pvVar1 + 4) = *(u_int *)((int)pvVar1 + 4) & 0xfffffffb;
    }
  }
  return;
}
