#include "THISDUST.H"
#include "SKINNER.H"

int SKINNER_BurrowInEntry(_Instance *instance)

{
  u_short uVar1;
  Level *level;
  int iVar2;
  void *pvVar3;
  void *pvVar4;

  pvVar3 = instance->extraData;
  pvVar4 = instance->data;
  iVar2 = 0;
  if (((instance->tface != (_TFace *)0x0) && (uVar1 = instance->tface->textoff, uVar1 != 0xffff)) &&
      ((*(u_short *)(*(int *)(*(int *)instance->tfaceLevel + 0x34) + (u_int)uVar1 + 10) & 0x100) != 0))
  {
    level = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
    *(u_int *)((int)pvVar3 + 4) = *(u_int *)((int)pvVar3 + 4) | 1;
    MON_TurnOnBodySpheres(instance);
    MON_PlayAnimFromListIfNotPlaying(instance, *(char **)((int)pvVar4 + 8), 0, 1);
    FX_StartInstanceEffect(instance, level, instance->tface);
    iVar2 = 1;
    *(u_short *)((int)pvVar3 + 0x14e) = *(u_short *)((int)pvVar3 + 0x14e) & 0xffef;
  }
  return iVar2;
}

int SKINNER_BurrowIn(_Instance *instance)

{
  bool bVar1;
  void *pvVar2;

  pvVar2 = instance->extraData;
  bVar1 = (instance->flags2 & 0x10U) != 0;
  if (bVar1)
  {
    FX_StopInstanceBurrow(instance);
    *(u_int *)((int)pvVar2 + 4) = *(u_int *)((int)pvVar2 + 4) & 0xfffffffe | 4;
    instance->flags = instance->flags | 0x800;
    MON_TurnOnWeaponSpheres(instance);
  }
  return (u_int)bVar1;
}

int SKINNER_GetBurrowDest(_Instance *instance, _Position *enemyPos)

{
  u_short uVar1;
  int iVar2;
  Level *level;
  long lVar3;
  void *pvVar4;
  int iVar5;
  _TFace *p_Var6;
  long lVar7;
  u_char local_20;
  short local_1c;

  iVar5 = 0;
  p_Var6 = instance->tface;
  lVar7 = instance->bspTree;
  iVar2 = MON_GetRandomPoint(instance, (_Position *)&local_20, enemyPos, 0x80, 0xcc, 0, 0x1000, 0x2aa);
  if (iVar2 != 0)
  {
    uVar1 = instance->tface->textoff;
    iVar5 = 0;
    if ((uVar1 != 0xffff) &&
        (iVar5 = 0,
         (*(u_short *)(*(int *)(*(int *)instance->tfaceLevel + 0x34) + (u_int)uVar1 + 10) & 0x100) != 0))
    {
      level = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
      lVar3 = STREAM_GetLevelWithID(level, instance);
      iVar5 = 0;
      if (0 < local_1c - lVar3)
      {
        pvVar4 = instance->extraData;
        iVar5 = 1;
        *(u_char *)((int)pvVar4 + 0x120) = local_20;
        *(short *)((int)pvVar4 + 0x124) = local_1c;
      }
    }
  }
  instance->tface = p_Var6;
  instance->bspTree = lVar7;
  return iVar5;
}

void SKINNER_CalcBurrowingMove(_Instance *instance, _Position *enemyPos)

{
  short sVar1;
  u_long uVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;

  pvVar5 = instance->extraData;
  uVar2 = MON_GetAnim(instance);
  iVar4 = (int)*(short *)((int)pvVar5 + 0x120) - (int)(instance->position).x;
  if (iVar4 < 0)
  {
    iVar4 = -iVar4;
  }
  iVar3 = (int)*(short *)((int)pvVar5 + 0x122) - (int)(instance->position).y;
  if (iVar3 < 0)
  {
    iVar3 = -iVar3;
  }
  0xa00;
  sVar1 = *(short *)((int)pvVar5 + 0x124);
  *(u_char *)&instance->position = *(u_char *)((int)pvVar5 + 0x120);
  (instance->position).z = sVar1;
  MON_MoveToPosition(instance, enemyPos, 0x1000);
  return;
}

void SKINNER_PupateEntry(_Instance *instance)

{
  void *pvVar1;

  pvVar1 = instance->extraData;
  MON_PursueEntry(instance);
  MON_TurnOnBodySpheres(instance);
  *(u_int *)((int)pvVar1 + 4) = *(u_int *)((int)pvVar1 + 4) | 4;
  return;
}

void MON_Pupate(_Instance *instance)

{
  u_char local_8;
  u_char local_4;

  MON_Pupate(instance);
  if ((instance->flags & 0x800U) == 0)
  {
    MON_OnGround(instance);
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_4, local_8));
  }
  return;
}

void SKINNER_PursueEntry(_Instance *instance)

{
  MON_HideEntry(instance);
  return;
}

void SKINNER_Hide(_Instance *instance)

{
  bool bVar1;
  u_long uVar2;
  __Event *p_Var3;
  u_int uVar4;
  u_char local_18;
  int iVar5;
  u_char local_14;
  int iVar6;
  void *pvVar7;

  pvVar7 = instance->extraData;
  iVar5 = *(int *)((int)pvVar7 + 0xc4);
  if (iVar5 == 0)
  {
    MON_Pursue(instance);
  }
  else
  {
    uVar4 = *(u_int *)((int)pvVar7 + 4);
    if ((uVar4 & 7) == 0)
    {
      iVar6 = 0;
      if ((((*(char *)((int)pvVar7 + 0x15a) != '\0') && (0x800 < *(short *)(iVar5 + 0x14))) &&
           (*(short *)(iVar5 + 0x14) < 0x2800)) &&
          (iVar5 = SKINNER_GetBurrowDest(instance, (_Position *)(*(int *)(iVar5 + 4) + 0x5c)),
           iVar5 != 0))
      {
        iVar6 = SKINNER_BurrowInEntry(instance);
      }
      if (iVar6 == 0)
      {
        MON_Pursue(instance);
      }
    }
    else
    {
      if ((uVar4 & 1) == 0)
      {
        if (((uVar4 & 4) != 0) &&
            (uVar2 = MON_GetAnim(instance), *(u_int *)((int)pvVar7 + 0x114) < uVar2))
        {
          bVar1 = false;
          if (((undefined *)((u_int) * (u_short *)(iVar5 + 0x14) - 0xcd) < &DAT_00002733) &&
              (iVar6 = SKINNER_GetBurrowDest(instance, (_Position *)(*(int *)(iVar5 + 4) + 0x5c)),
               iVar6 != 0))
          {
            bVar1 = true;
            SKINNER_CalcBurrowingMove(instance, (_Position *)(*(int *)(iVar5 + 4) + 0x5c));
          }
          if (!bVar1)
          {
            MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
          }
        }
      }
      else
      {
        iVar6 = SKINNER_BurrowIn(instance);
        if (iVar6 != 0)
        {
          SKINNER_CalcBurrowingMove(instance, (_Position *)(*(int *)(iVar5 + 4) + 0x5c));
        }
      }
    }
    do
    {
      p_Var3 = PurgeMessageQueue((__MessageQueue *)((int)pvVar7 + 8));
    } while (p_Var3 != (__Event *)0x0);
  }
  return;
}

void MON_HideEntry(_Instance *instance)

{
  if (*(char *)((int)instance->extraData + 0x15a) == '\0')
  {
    MON_Hit(instance);
  }
  else
  {
    SKINNER_BurrowInEntry(instance);
  }
  return;
}

void SKINNER_Pursue(_Instance *instance)

{
  int iVar1;
  u_char local_10;
  u_char local_c;
  void *pvVar2;

  pvVar2 = instance->extraData;
  if (*(char *)((int)pvVar2 + 0x15a) == '\0')
  {
    MON_Hide(instance);
    return;
  }
  if ((*(u_int *)((int)pvVar2 + 4) & 1) != 0)
  {
    SKINNER_BurrowIn(instance);
    goto LAB_8008cdb0;
  }
  if ((*(u_int *)((int)pvVar2 + 4) & 4) != 0)
  {
    iVar1 = MONSENSE_DetectPlayer(instance);
    if (iVar1 == 0)
      goto LAB_8008cdb0;
    if (*(char *)((int)pvVar2 + 0x156) == '\x04')
    {
      MON_ChangeBehavior(instance, (u_int) * (byte *)((int)pvVar2 + 0x158));
      goto LAB_8008cdb0;
    }
    if ((*(char *)((int)pvVar2 + 0x156) != '\b') ||
        (iVar1 = *(int *)((int)pvVar2 + 0xc4),
         MON_MoveToPosition(instance, (_Position *)(*(int *)(iVar1 + 4) + 0x5c),
                            *(short *)(*(int *)((int)pvVar2 + 0x164) + 0x1c)),
         *(short *)((int)pvVar2 + 0x13a) <= *(short *)(iVar1 + 0x14)))
      goto LAB_8008cdb0;
  }
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
LAB_8008cdb0:
  MON_DefaultMessageHandler(instance);
  return;
}

void SKINNER_SurpriseAttackEntry(_Instance *instance)

{
  Level *level;
  u_int uVar1;

  uVar1 = *(u_int *)((int)instance->extraData + 4);
  if ((uVar1 & 7) != 0)
  {
    *(u_int *)((int)instance->extraData + 4) = uVar1 & 0xfffffffb | 2;
    instance->flags = instance->flags & 0xfffff7ff;
    if (instance->tface != (_TFace *)0x0)
    {
      level = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
      FX_StartInstanceEffect(instance, level, instance->tface);
    }
    GAMEPAD_HandleDualShock(0x40, 0x1e000);
  }
  MON_AttackEntry(instance);
  return;
}

void MON_SurpriseAttackEntry(_Instance *instance)

{
  void *pvVar1;

  pvVar1 = instance->extraData;
  MON_SurpriseAttack(instance);
  if (instance->currentMainState != 0x15)
  {
    *(u_int *)((int)pvVar1 + 4) = *(u_int *)((int)pvVar1 + 4) & 0xfffffff8;
    FX_StopInstanceBurrow(instance);
    MON_TurnOnWeaponSphere(instance);
    *(u_short *)((int)pvVar1 + 0x14e) = *(u_short *)((int)pvVar1 + 0x14e) | 0x10;
  }
  return;
}
