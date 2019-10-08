#include "THISDUST.H"
#include "MONMSG.H"

void MON_SetFXHitData(_Instance *instance, evFXHitData *data, int type, int amount)

{
  short sVar1;

  data->type = (short)type;
  data->amount = (short)amount;
  (data->location).x = (instance->position).x;
  (data->location).y = (instance->position).y;
  sVar1 = (instance->position).z;
  (data->velocity).x = 0;
  (data->velocity).y = 0;
  (data->velocity).z = 0;
  (data->location).z = sVar1 + 0x100;
  return;
}

int SOUL_QueueHandler(_Instance *instance)

{
  __Event *message;
  int iVar1;
  void *pvVar2;

  iVar1 = 0;
  pvVar2 = instance->extraData;
  while (true)
  {
    message = PurgeMessageQueue((__MessageQueue *)((int)pvVar2 + 8));
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

void MON_PupateMessageHandler(_Instance *instance, __Event *message)

{
  short angle;
  long lVar1;
  u_long uVar2;
  int iVar3;
  _Instance *p_Var4;
  u_int *puVar5;
  u_char local_48;
  u_char in_stack_ffffffbc;
  evFXHitData eStack64;
  evFXHitData eStack40;

  iVar3 = message->ID;
  puVar5 = (u_int *)instance->extraData;
  if (iVar3 == 0x80004)
  {
    if (*(char *)(puVar5[0x59] + 0x3a) == '\0')
    {
      return;
    }
    MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_ffffffbc, local_48));
    *(undefined2 *)(puVar5 + 0x54) = 0x10;
    return;
  }
  if (iVar3 < 0x80005)
  {
    if (iVar3 == 0x80002)
    {
      iVar3 = MON_TakeDamage(instance, 0x3000, 0x100);
      if ((iVar3 != 0) && ((*puVar5 & 0x2000) != 0))
      {
        *(undefined2 *)(puVar5 + 0x54) = 0x100;
      }
    }
    else
    {
      if (iVar3 < 0x80003)
      {
        if (iVar3 != 0x80001)
        {
          return;
        }
        if (instance->zVel != 0)
        {
          return;
        }
        angle = MATH3D_AngleFromPosToPos(&(gameTrackerX.playerInstance)->position, &instance->position);
        PhysicsSetVelFromZRot(instance, angle, 100);
        instance->zVel = 0x32;
        (instance->position).z = (instance->position).z + 100;
        (instance->oldPos).z = (instance->oldPos).z + 100;
      }
      else
      {
        if (*(char *)(puVar5[0x59] + 0x3c) == '\0')
        {
          return;
        }
        MON_SetFXHitData(instance, &eStack40, 0x200, 1);
        *(undefined2 *)(puVar5 + 0x54) = 0x200;
        SLUAGH_DamageEffect(instance, &eStack40);
      }
    }
  LAB_8008472c:
    MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_ffffffbc, local_48));
  }
  else
  {
    if (iVar3 != 0x80006)
    {
      if (0x80005 < iVar3)
      {
        if (iVar3 == 0x1000000)
        {
          *puVar5 = *puVar5 & 0xffffff7f;
          return;
        }
        if (iVar3 != 0x1000011)
        {
          return;
        }
        p_Var4 = (_Instance *)message->Data;
        lVar1 = MATH3D_LengthXY((int)*(short *)((int)&p_Var4->node + 4) -
                                    (int)(instance->position).x,
                                (int)*(short *)((int)&p_Var4->node + 6) -
                                    (int)(instance->position).y,
                                (int)*(short *)&p_Var4->next - (int)(instance->position).z);
        if (*(short *)(*(int *)(puVar5[0x59] + 4) + 0xe) <= lVar1)
        {
          return;
        }
        *puVar5 = *puVar5 & 0xffffff7f;
        if (puVar5[0x31] != 0)
        {
          return;
        }
        if (*(_Instance **)&p_Var4->node == (_Instance *)0x0)
        {
          return;
        }
        uVar2 = INSTANCE_Post(*(_Instance **)&p_Var4->node, 1);
        if ((uVar2 & 0xb) == 0)
        {
          return;
        }
        MONSENSE_See(instance, *(_Instance **)&p_Var4->node);
        return;
      }
      if (*(char *)(puVar5[0x59] + 0x39) != '\0')
      {
        MON_SetFXHitData(instance, &eStack64, 0x20, 1);
        *(undefined2 *)(puVar5 + 0x54) = 0x20;
        SLUAGH_DamageEffect(instance, &eStack64);
        goto LAB_8008472c;
      }
    }
    if (*(char *)(puVar5[0x59] + 0x38) != '\0')
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_ffffffbc, local_48));
      MON_LaunchMonster(instance, 0xffffff, 0x46, 10, 0x14);
      *(undefined2 *)(puVar5 + 0x54) = 0x40;
    }
  }
  return;
}

void MON_IdleMessageHandler(_Instance *instance, __Event *message)

{
  u_long uVar1;
  u_char local_10;
  u_char local_c;
  u_int *puVar2;

  puVar2 = (u_int *)instance->extraData;
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
    MON_PupateMessageHandler(instance, message);
    break;
  case 0x100000e:
    if ((*puVar2 & 4) == 0)
    {
      uVar1 = INSTANCE_Post(*(_Instance **)(message->Data + 4), 1);
      if ((uVar1 & 1) != 0)
      {
        MON_ChangeBehavior(instance, (u_int) * (byte *)(puVar2 + 0x56));
      }
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
    }
    break;
  case 0x1000012:
    if ((*puVar2 & 4) == 0)
    {
      uVar1 = INSTANCE_Post(*(_Instance **)(message->Data + 4), 1);
      if ((uVar1 & 1) != 0)
      {
        MON_ChangeBehavior(instance, (u_int) * (byte *)(puVar2 + 0x56));
      }
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
    }
  }
  return;
}

void MON_PupateMessageHandler(_Instance *instance, __Event *message)

{
  u_short uVar1;
  short sVar2;
  bool bVar3;
  short angle;
  u_long uVar4;
  long lVar5;
  TDRFuncPtr_MONTABLE_GetDamageEffectFunc pTVar6;
  u_int CurrentSection;
  int Data;
  short *psVar7;
  u_int uVar8;
  _MonsterIR *Data_00;
  int iVar9;
  evFXHitData *data;
  byte bVar10;
  _Instance *p_Var11;
  _MonsterVars *mv;
  _Instance *Inst;
  u_char local_58;
  u_char local_54;
  evFXHitData eStack72;
  evFXHitData eStack48;

  Data = message->ID;
  mv = (_MonsterVars *)instance->extraData;
  if (0x1000008 < Data)
  {
    if (Data == 0x1000016)
    {
      if (mv->subAttr->combatAttributes->hitPoints == '\0')
      {
        return;
      }
      Data = (int)mv->hitPoints + message->Data;
      angle = (short)Data;
      if (0x6000 < Data)
      {
        angle = 0x6000;
      }
    LAB_800851b8:
      mv->hitPoints = angle;
      return;
    }
    if (Data < 0x1000017)
    {
      if (Data == 0x100000c)
      {
        if (((mv->mvFlags & 1) != 0) && (instance->currentMainState == 0xb))
        {
          return;
        }
        Data = message->Data;
        if (Data == 0x20)
        {
          bVar10 = 0;
          if ((mv->mvFlags & 0x400) == 0)
          {
            bVar10 = mv->subAttr->fireVuln;
          }
        }
        else
        {
          if (Data < 0x21)
          {
            bVar10 = 0;
            if (Data == 0x10)
            {
              bVar10 = mv->subAttr->waterVuln;
            }
          }
          else
          {
            bVar10 = 0;
            if (Data == 0x40)
            {
              bVar10 = mv->subAttr->sunVuln;
            }
          }
        }
        if (bVar10 != 0)
        {
          mv->damageType = *(u_short *)&message->Data;
          Data = SetFXHitData((_Instance *)0x0, 0, 0, message->Data);
          INSTANCE_Query(instance, 0x400000, Data);
        }
        if (bVar10 == 1)
        {
          MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
          return;
        }
        if (bVar10 == 0)
        {
          return;
        }
        if (3 < bVar10)
        {
          return;
        }
        mv->mvFlags = mv->mvFlags | 0x200000;
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
        return;
      }
      if (Data < 0x100000d)
      {
        if (Data == 0x100000a)
        {
          p_Var11 = (_Instance *)message->Data;
          if (p_Var11 != (_Instance *)0x0)
          {
            mv->held = *(_Instance **)&p_Var11->node;
            Data = rsin((int)*(short *)&p_Var11->next);
            Data = *(short *)((int)&p_Var11->instanceID + 2) * Data;
            if (Data < 0)
            {
              Data = Data + 0xfff;
            }
            angle = *(short *)&p_Var11->prev;
            iVar9 = rcos((int)*(short *)&p_Var11->next);
            iVar9 = *(short *)((int)&p_Var11->instanceID + 2) * iVar9;
            if (iVar9 < 0)
            {
              iVar9 = iVar9 + 0xfff;
            }
            sVar2 = *(short *)((int)&p_Var11->prev + 2);
            (instance->position).x = angle + (short)(Data >> 0xc);
            (instance->position).y = sVar2 - (short)(iVar9 >> 0xc);
            (instance->rotation).z = *(short *)&p_Var11->next + 0x800U & 0xfff;
            MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
            return;
          }
          Data_00 = mv->enemy;
          if (Data_00 == (_MonsterIR *)0x0)
          {
            return;
          }
          Data_00->mirConditions = Data_00->mirConditions | 0x80;
          return;
        }
        if (0x100000a < Data)
        {
          MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
          return;
        }
        Data = message->Data;
        lVar5 = MATH3D_LengthXY((int)(instance->position).x - (int)*(short *)(Data + 4),
                                (int)(instance->position).y - (int)*(short *)(Data + 6),
                                (int)(instance->position).z - (int)*(short *)(Data + 8));
        if (6999 < lVar5)
        {
          return;
        }
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
        return;
      }
      if (Data != 0x1000011)
      {
        if (Data < 0x1000012)
        {
          if (Data != 0x100000e)
          {
            return;
          }
        }
        else
        {
          if (Data != 0x1000012)
          {
            if (Data != 0x1000014)
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
              MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
              return;
            }
            MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
            return;
          }
        }
        if ((mv->mvFlags & 4) != 0)
        {
          return;
        }
        uVar4 = INSTANCE_Post(*(_Instance **)(message->Data + 4), 1);
        if ((uVar4 & 1) == 0)
        {
          return;
        }
        mv->behaviorState = mv->triggeredBehavior;
        return;
      }
      p_Var11 = (_Instance *)message->Data;
      Inst = *(_Instance **)&p_Var11->node;
      if (Inst == (_Instance *)0x0)
      {
        return;
      }
      uVar4 = INSTANCE_Post(Inst, 1);
      if ((uVar4 & 0xb) == 0)
      {
        return;
      }
      Data_00 = MONSENSE_FindIR(mv, Inst);
      if (Data_00 != (_MonsterIR *)0x0)
      {
        return;
      }
      lVar5 = MATH3D_LengthXY((int)(instance->position).x - (int)*(short *)((int)&p_Var11->node + 4), (int)(instance->position).y - (int)*(short *)((int)&p_Var11->node + 6),
                              (int)(instance->position).z - (int)*(short *)&p_Var11->next);
      if (mv->subAttr->senses->alarmRadius <= lVar5)
      {
        return;
      }
      Data_00 = MONSENSE_See(instance, Inst);
      if (Data_00 == (_MonsterIR *)0x0)
      {
        return;
      }
      Data = 0x1000012;
      goto LAB_80085540;
    }
    if (Data != 0x1000021)
    {
      if (0x1000021 < Data)
      {
        if (Data == 0x2000002)
        {
          p_Var11 = (_Instance *)message->Data;
          Data_00 = (_MonsterIR *)
              SetMonsterImpaleData(instance, (_Instance *)0x0, (int)p_Var11->prev,
                                   (int)mv->attackType->knockBackDistance,
                                   (int)mv->attackType->knockBackDuration);
          Data = 0x1000000;
          instance = *(_Instance **)&p_Var11->node;
          goto LAB_80085540;
        }
        if (0x2000002 < Data)
        {
          if (Data == 0x4010080)
          {
            return;
          }
          if (Data != 0x8000008)
          {
            return;
          }
          MON_PlayAnimID(instance, *(int *)(message->Data + 4), *(int *)(message->Data + 0x10));
          return;
        }
        if (Data != 0x1000023)
        {
          return;
        }
        if (message->Data != 0x1000)
        {
          return;
        }
        mv->damageType = 0x400;
        goto LAB_80085350;
      }
      if (Data == 0x100001a)
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
 2);
 goto LAB_800851b8;
      }
      if (Data < 0x100001b)
      {
        if (Data != 0x1000019)
        {
          return;
        }
        MONSENSE_See(instance, gameTrackerX.playerInstance);
        mv->held = (_Instance *)message->Data;
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
        return;
      }
      if (Data == 0x100001c)
      {
        mv->terrainImpaleID = message->Data;
        MON_MoveInstanceToImpalePoint(instance);
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
        return;
      }
      if (Data != 0x100001f)
      {
        return;
      }
    }
    if ((mv->mvFlags & 0x200040) != 0)
    {
      return;
    }
    bVar3 = false;
    iVar9 = message->Data;
    uVar1 = *(u_short *)(iVar9 + 0xc);
    mv->damageType = uVar1;
    Data = 0;
    if (uVar1 == 0x20)
    {
      bVar3 = true;
    }
    else
    {
      Data = 0x3000;
      if ((instance->flags2 & 0x8000000U) != 0)
      {
        Data = 0x2000;
      }
    }
    if (bVar3)
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
    }
    if (Data == 0)
    {
      mv->mvFlags = mv->mvFlags | 0x40;
      return;
    }
    *(int *)(iVar9 + 0xc) = Data;
  LAB_80084bd0:
    if ((mv->mvFlags & 0x200040) != 0)
    {
      return;
    }
    if (instance->currentMainState == 10)
    {
      return;
    }
    p_Var11 = (_Instance *)message->Data;
    if (0x2fff < (int)p_Var11->prev)
    {
      instance->constrictAngle = 0;
    }
    mv->mvFlags = mv->mvFlags | 0x40;
    uVar4 = INSTANCE_Post(*(_Instance **)&p_Var11->node, 1);
    Inst = gameTrackerX.playerInstance;
    if (uVar4 != 0x20)
    {
      Inst = *(_Instance **)&p_Var11->node;
    }
    MONSENSE_See(instance, Inst);
    Data = MON_TakeDamage(instance, (int)p_Var11->prev, 0x100);
    iVar9 = 8;
    if ((Data != 0) && (iVar9 = 9, (mv->mvFlags & 0x2000) != 0))
    {
      iVar9 = 0x10;
    }
    if (iVar9 != -1)
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
    }
    mv->damageType = 0x100;
    *(_Instance **)&mv->messageData = p_Var11;
    return;
  }
  if (0x1000006 < Data)
  {
    return;
  }
  if (Data == 0x80001)
  {
    if (instance->zVel != 0)
    {
      return;
    }
    if ((mv->mvFlags & 0x200000) != 0)
    {
      return;
    }
    Data_00 = mv->enemy;
    if (Data_00 != (_MonsterIR *)0x0)
    {
      Data_00->mirFlags = Data_00->mirFlags & 0xefff;
    }
    angle = MATH3D_AngleFromPosToPos(&(gameTrackerX.playerInstance)->position, &instance->position);
    PhysicsSetVelFromZRot(instance, angle, 100);
    instance->zVel = 0x46;
    (instance->position).z = (instance->position).z + 0x78;
    (instance->oldPos).z = (instance->oldPos).z + 0x78;
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
    return;
  }
  if (Data < 0x80002)
  {
    if (Data == 0x4000d)
    {
      Data = message->Data;
      mv->auxFlags = mv->auxFlags | 0x10000000;
      (mv->destination).z = *(short *)(Data + 4);
      return;
    }
    if (Data < 0x4000e)
    {
      if (Data == 0x40009)
      {
        mv->damageType = 0x2000;
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
        return;
      }
      if (Data < 0x4000a)
      {
        if (Data != 0x40003)
        {
          return;
        }
        CurrentSection = (u_int)mv->subAttr->numSections;
        Data = message->Data;
        while (CurrentSection = CurrentSection - 1, -1 < (int)CurrentSection)
        {
          G2EmulationInstanceToInstanceSwitchAnimation(instance, *(_Instance **)(Data + 4), CurrentSection, *(int *)(Data + 8),
                                                       *(int *)(Data + 0xc), *(int *)(Data + 0x10), *(int *)(Data + 0x14));
        }
        return;
      }
      if (Data != 0x4000c)
      {
        return;
      }
    }
    else
    {
      if (Data == 0x40010)
      {
        CurrentSection = mv->mvFlags;
        uVar8 = 0x7fffffff;
      LAB_800854dc:
        mv->mvFlags = CurrentSection & uVar8;
        return;
      }
      if (Data < 0x40011)
      {
        if (Data != 0x4000f)
        {
          return;
        }
        psVar7 = (short *)message->Data;
        mv->mvFlags = mv->mvFlags | 0x80000000;
        (mv->lookAtPosData).x = *psVar7;
        (mv->lookAtPosData).y = psVar7[1];
        (mv->lookAtPosData).z = psVar7[2];
        return;
      }
      if (Data != 0x40016)
      {
        if (Data != 0x40017)
        {
          return;
        }
        mv->damageType = *(u_short *)(&LAB_800cb194 + message->Data * 4);
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
        return;
      }
    }
    psVar7 = (short *)message->Data;
    (mv->destination).x = *psVar7;
    (mv->destination).y = psVar7[1];
    angle = psVar7[2];
    mv->mvFlags = mv->mvFlags | 0x40000;
    (mv->destination).z = angle;
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
    return;
  }
  if (Data == 0x80005)
  {
    if (mv->subAttr->fireVuln == '\0')
      goto LAB_80085200;
    MON_SetFXHitData(instance, &eStack72, 0x20, 1);
    mv->damageType = 0x20;
    data = &eStack72;
  }
  else
  {
    if (0x80005 < Data)
    {
      if (Data == 0x400000)
      {
        pTVar6 = MONTABLE_GetStateFuncs(instance);
        (*pTVar6)(instance, message->Data);
        return;
      }
      if (0x400000 < Data)
      {
        if (Data != 0x1000000)
        {
          if (Data != 0x1000002)
          {
            return;
          }
          if (message->Data == 0)
          {
            Data_00 = mv->enemy;
            if (Data_00 == (_MonsterIR *)0x0)
            {
              return;
            }
            Data_00->mirConditions = Data_00->mirConditions | 0x40;
            return;
          }
          MONSENSE_See(instance, gameTrackerX.playerInstance);
          MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
          CurrentSection = mv->mvFlags;
          uVar8 = 0xfffffffd;
          goto LAB_800854dc;
        }
        goto LAB_80084bd0;
      }
      if (Data != 0x80006)
      {
        return;
      }
    LAB_80085200:
      if ((*(u_int *)((int)instance->data + 0x10) & 0x10008) == 0)
      {
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
        MON_LaunchMonster(instance, 0xffffff, 0x46, 10, 0x14);
        mv->damageType = 0x40;
        return;
      }
      Data_00 = (_MonsterIR *)
          SetMonsterAlarmData(gameTrackerX.playerInstance,
                              &(gameTrackerX.playerInstance)->position, 2);
      Data = 0x1000011;
    LAB_80085540:
      INSTANCE_Query(instance, Data, (int)Data_00);
      return;
    }
    if (Data != 0x80003)
    {
      if (Data < 0x80004)
      {
        if (instance->petrifyValue != 0)
        {
          return;
        }
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
        instance->petrifyValue = 0x1000;
        return;
      }
      if ((mv->subAttr->waterVuln != '\0') && ((*(u_int *)((int)instance->data + 0x10) & 8) == 0))
      {
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
        MON_LaunchMonster(instance, 0xff0000, 0x46, 10, 0x14);
        mv->damageType = 0x10;
        return;
      }
      Data_00 = (_MonsterIR *)
          SetMonsterAlarmData(gameTrackerX.playerInstance,
                              &(gameTrackerX.playerInstance)->position, 2);
      Data = 0x1000011;
      goto LAB_80085540;
    }
    if (mv->subAttr->soundVuln == '\0')
    {
      Data_00 = (_MonsterIR *)
          SetMonsterAlarmData(gameTrackerX.playerInstance,
                              &(gameTrackerX.playerInstance)->position, 2);
      Data = 0x1000011;
      goto LAB_80085540;
    }
    data = &eStack48;
    MON_SetFXHitData(instance, data, 0x200, 1);
    mv->damageType = 0x200;
  }
  SLUAGH_DamageEffect(instance, data);
LAB_80085350:
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_54, local_58));
  return;
}

void MON_PupateQueueHandler(_Instance *instance)

{
  __Event *message;
  void *pvVar1;

  pvVar1 = instance->extraData;
  while (message = PurgeMessageQueue((__MessageQueue *)((int)pvVar1 + 8)), message != (__Event *)0x0)
  {
    MON_PupateMessageHandler(instance, message);
  }
  return;
}

void MON_Idle(_Instance *instance)

{
  __Event *message;
  void *pvVar1;

  pvVar1 = instance->extraData;
  while (message = PurgeMessageQueue((__MessageQueue *)((int)pvVar1 + 8)), message != (__Event *)0x0)
  {
    MON_IdleMessageHandler(instance, message);
  }
  return;
}

void MON_DefaultMessageHandler(_Instance *instance)

{
  __Event *message;
  void *pvVar1;

  pvVar1 = instance->extraData;
  while (message = PurgeMessageQueue((__MessageQueue *)((int)pvVar1 + 8)), message != (__Event *)0x0)
  {
    MON_PupateMessageHandler(instance, message);
  }
  return;
}
