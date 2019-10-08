#include "THISDUST.H"
#include "REAVER.H"

void SoulReaverInit(_Instance *instance, GameTracker *gameTracker)

{
  char *pcVar1;

  if ((instance->flags & 0x20000U) == 0)
  {
    pcVar1 = MEMPACK_Malloc(0x24, '\x1e');
    *(char **)&instance->extraData = pcVar1;
    *(undefined2 *)(pcVar1 + 4) = 2;
    pcVar1[1] = '\x01';
    *(u_char *)(pcVar1 + 8) = 0;
    *(u_char *)(pcVar1 + 0xc) = 0;
    *pcVar1 = '\0';
    *(undefined2 *)(pcVar1 + 2) = 0x1000;
    *(undefined2 *)(pcVar1 + 6) = 0;
    *(undefined2 *)(pcVar1 + 0x1c) = 0x1000;
    *(undefined2 *)(pcVar1 + 0x1e) = 0x1000;
    COLLIDE_SegmentCollisionOn(instance, 0);
  }
  else
  {
    MEMPACK_Init((char *)instance->extraData);
  }
  FX_ReaverBladeInit();
  return;
}

void SoulReaverQuery(_Instance *instance, GameTracker *gameTracker)

{
  short sVar1;
  int Data;
  _CollideInfo *collideInfo;
  int Power;
  _Instance *lastHit;

  collideInfo = (_CollideInfo *)instance->collideInfo;
  if ((((*(u_int *)&collideInfo->flags & 0xffff0000) == 0x1010000) &&
       (*(char *)((int)collideInfo->prim0 + 4) == '\t')) &&
      (*(char *)((int)collideInfo->prim1 + 4) == '\b'))
  {
    lastHit = (_Instance *)collideInfo->inst1;
    COLLIDE_SegmentCollisionOn(instance, 0);
    sVar1 = *(short *)((int)instance->extraData + 4);
    Power = 0;
    if (0 < sVar1)
    {
      if (sVar1 < 3)
      {
        Power = 0x1000;
      }
      else
      {
        if (sVar1 == 6)
        {
          Power = 0x20;
        }
      }
    }
    if (instance->LinkParent != (_Instance *)0x0)
    {
      COLLIDE_SegmentCollisionOn(instance, 0);
      Data = SetMonsterImpaleData(instance->LinkParent, lastHit, Power, 0, 0);
      INSTANCE_Query(gameTrackerX.playerInstance, 0x100001f, Data);
      Power = SetFXHitData(instance, (u_int)(byte)collideInfo->segment, 0x32, Power);
      INSTANCE_Query(lastHit, 0x400000, Power);
    }
  }
  if (collideInfo->type1 == '\x03')
  {
    COLLIDE_GetBSPTreeFlag(collideInfo, 0x800);
  }
  else
  {
    *(u_int *)((int)collideInfo->inst1 + 0x14) = *(u_int *)((int)collideInfo->inst1 + 0x14) | 4;
  }
  return;
}

void SoulReaverImbue(_Instance *instance, GameTracker *gameTracker)

{
  SoulReaverPost(instance);
  return;
}

void CollideReaverProjectile(_Instance *instance, GameTracker *gameTracker)

{
  Level *pLVar1;
  int Power;
  int iVar2;
  _CollideInfo *collideInfo;
  _Instance *Inst;

  collideInfo = (_CollideInfo *)instance->collideInfo;
  Inst = (_Instance *)collideInfo->inst1;
  iVar2 = *(int *)((int)instance->extraData + 4) + -2;
  Power = 0;
  if ((*(u_int *)&collideInfo->flags & 0xffff0000) == 0x1010000)
  {
    if (0 < iVar2)
    {
      if (iVar2 < 3)
      {
        Power = 0x1000;
      }
      else
      {
        if (iVar2 == 6)
        {
          Power = 0x20;
          pLVar1 = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
          if ((pLVar1 != (Level *)0x0) && ((int)(instance->position).z < pLVar1->waterZLevel))
          {
            return;
          }
        }
      }
    }
    if (Power != 0)
    {
      Power = SetMonsterImpaleData(instance, (_Instance *)0x0, Power, 0, 0);
      INSTANCE_Query(Inst, 0x1000021, Power);
      if (iVar2 == 2)
      {
        Power = SetFXHitData(instance, (u_int)(byte)collideInfo->segment, 0x20, 0x100);
        INSTANCE_Query(Inst, 0x400000, Power);
        INSTANCE_Query(Inst, 0x80001, 0);
      }
    }
  }
  if (collideInfo->type1 == '\x03')
  {
    COLLIDE_GetBSPTreeFlag(collideInfo, 0x800);
  }
  else
  {
    *(u_int *)((int)collideInfo->inst1 + 0x14) = *(u_int *)((int)collideInfo->inst1 + 0x14) | 4;
  }
  InitPhysicalObject(instance, gameTracker);
  return;
}

u_long SoulReaverProcess(_Instance *instance, u_long query)

{
  u_long uVar1;

  if (query == 4)
  {
    return 0x1000;
  }
  if (query < 5)
  {
    if (query == 1)
    {
      return 0x20000;
    }
  }
  else
  {
    if ((query == 0x28) && (*(char *)((int)instance->extraData + 1) != '\0'))
    {
      uVar1 = 1;
      if (*(short *)((int)instance->extraData + 0x1e) != 0)
      {
        uVar1 = 3;
      }
      return uVar1;
    }
  }
  return 0;
}

void FX_SoulReaverBlade(_Instance *instance, int number)

{
  FX_DoBlastRing(instance, (_SVector *)&instance->position, instance->matrix, 0, 0x140, 0, 0xf0, 0, 0,
                 -0x10000, 0, 0, 0xa0, 0x140, *(long *)((int)instance->data + number * 4 + -4), 0, 0, 0x14, 1);
  return;
}

void SoulReaverCharge(_Instance *instance, __ReaverData *data)

{
  int motor1_speed;
  void *pvVar1;

  pvVar1 = instance->data;
  if (data->ReaverChargeTime != 0)
  {
    data->ReaverChargeTime = data->ReaverChargeTime - gameTrackerX.timeMult;
    if (data->ReaverShockAmount < 0x3c000)
    {
      motor1_speed = data->ReaverShockAmount + gameTrackerX.timeMult;
      data->ReaverShockAmount = motor1_speed;
      0xdb6 + 0x50;
    }
    else
    {
      motor1_speed = 0x96;
    }
    GAMEPAD_HandleDualShock(motor1_speed, (int)&DAT_00005000);
    if (data->ReaverChargeTime < 1)
    {
      data->ReaverChargeTime = data->ReaverChargeTime + 0xf000;
      FX_DoBlastRing(instance, (_SVector *)&instance->position, instance->matrix, 0, 0x168, 0, 0, 0, 0,
                     -0x10000, 0, 0x140, 0x110, 0xe0,
                     *(long *)((int)pvVar1 + (int)data->CurrentReaver * 4 + -4), 0, 0, -1, 1);
    }
  }
  return;
}

void SoulReaverCollide(__ReaverData *data, _Instance *instance)

{
  data->ReaverChargeTime = 0;
  data->ReaverShockAmount = 0;
  GAMEPAD_HandleDualShock(0, 0);
  FX_EndInstanceEffects(instance);
  return;
}

void FX_SoulReaverWinding(_Instance *instance, u_long message, u_long data)

{
  int Data;
  evObjectBirthProjectileData *peVar1;
  _Instance *p_Var2;
  __ReaverData *data_00;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  short local_20;
  short local_1e;
  short local_1c;

  data_00 = (__ReaverData *)instance->extraData;
  if (message == 0x800101)
  {
    data_00->ReaverOn = '\0';
    SoulReaverCollide(data_00, instance);
    instance->flags = instance->flags | 0x800;
  }
  else
  {
    if (message < 0x800102)
    {
      if (message == 0x800002)
      {
        if (instance->LinkParent == (_Instance *)0x0)
        {
          INSTANCE_LinkToParent(instance, (_Instance *)data, 0x29);
        }
        data_00->ReaverOn = '\x01';
        data_00->ReaverPickedUp = '\x01';
      }
      else
      {
        if (message < 0x800003)
        {
          if (message == 0x200002)
          {
            COLLIDE_SegmentCollisionOff(instance, 0);
            return;
          }
          if (message != 0x200003)
          {
            return;
          }
          COLLIDE_SegmentCollisionOn(instance, 0);
          return;
        }
        if (message == 0x800010)
        {
          SoulReaverCollide(data_00, instance);
          local_28 = 0;
          local_26 = 0;
          local_24 = 400;
          ApplyMatrix(instance->matrix, &local_28, &local_20);
          local_20 = local_20 + (instance->position).x;
          local_1e = local_1e + (instance->position).y;
          local_1c = local_1c + (instance->position).z;
          peVar1 = PHYSOB_BirthCollectible(instance->LinkParent, 0,
                                           (int)*(short *)((int)instance->extraData + 4) + 2);
          if (peVar1->birthInstance == (_Instance *)0x0)
          {
            return;
          }
          peVar1->birthInstance->collideFunc = CollideReaverProjectile;
          p_Var2 = peVar1->birthInstance;
          (p_Var2->position).x = local_20;
          (p_Var2->position).y = local_1e;
          (p_Var2->position).z = local_1c;
          INSTANCE_Query(peVar1->birthInstance, 0x800010, data);
          p_Var2 = peVar1->birthInstance;
          (p_Var2->position).x = local_20;
          (p_Var2->position).y = local_1e;
          (p_Var2->position).z = local_1c;
          return;
        }
        if (message != 0x800100)
        {
          return;
        }
        data_00->ReaverOn = '\x01';
      }
      instance->flags = instance->flags & 0xfffff7ff;
    }
    else
    {
      if (message == 0x800105)
      {
        SoulReaverCollide(data_00, instance);
      }
      else
      {
        if (message < 0x800106)
        {
          if (message == 0x800103)
          {
            data_00->CurrentReaver = (short)data;
            FX_SoulReaverBlade(instance, data);
          }
          else
          {
            if (message == 0x800104)
            {
              data_00->ReaverChargeTime = 0xf000;
              Data = SetObjectIdleData(instance, 0, 0x3c);
              INSTANCE_Broadcast(instance, 0x20, 0x800028, Data);
            }
          }
        }
        else
        {
          if (message == 0x800108)
          {
            data_00->ReaverTargetScale = 0x1000;
          }
          else
          {
            if (message < 0x800109)
            {
              if (message == 0x800107)
              {
                data_00->ReaverTargetScale = (short)data;
              }
            }
            else
            {
              if (message == 0x800109)
              {
                SoulReaverCollide(data_00, instance);
                data_00->ReaverTargetScale = 0;
              }
            }
          }
        }
      }
    }
  }
  return;
}

u_long REAVER_GetGlowColor(_Instance *instance)

{
  return *(u_long *)((int)instance->data + (int)*(short *)((int)instance->extraData + 4) * 4 + -4);
}

void SoulReaverPost(_Instance *instance)

{
  int iVar1;
  int iVar2;
  __ReaverData *data;
  void *pvVar3;

  data = (__ReaverData *)instance->extraData;
  pvVar3 = instance->data;
  FX_SetReaverInstance(instance);
  iVar1 = rand();
  data->ReaverDeg = data->ReaverDeg + 0x100 + ((u_short)iVar1 & 0x1f) & 0xfff;
  if (data->ReaverOn == '\x01')
  {
    if (data->ReaverSize < 0x1000)
    {
      data->ReaverSize = data->ReaverSize + 0x100;
    }
  }
  else
  {
    if (0 < data->ReaverSize)
    {
      data->ReaverSize = data->ReaverSize + -0x100;
    }
  }
  if (0 < (int)data->CurrentReaver)
  {
    data->ReaverBladeColor = *(long *)((int)pvVar3 + (int)data->CurrentReaver * 4 + 0x1c);
    data->ReaverBladeGlowColor = *(long *)((int)pvVar3 + (int)data->CurrentReaver * 4 + 0x3c);
    data->ReaverGlowColor = *(long *)((int)pvVar3 + (int)data->CurrentReaver * 4 + -4);
  }
  iVar2 = (int)data->ReaverScale;
  iVar1 = data->ReaverTargetScale - iVar2;
  if (iVar1 < 0)
  {
    if (0x80 < iVar2 - data->ReaverTargetScale)
    {
      iVar2 = (int)data->ReaverScale;
      goto LAB_8007a1cc;
    }
  }
  else
  {
    if (0x80 < iVar1)
    {
    LAB_8007a1cc:
      if (data->ReaverTargetScale < iVar2)
      {
        data->ReaverScale = data->ReaverScale + -0x80;
      }
      if (data->ReaverScale < data->ReaverTargetScale)
      {
        data->ReaverScale = data->ReaverScale + 0x80;
      }
      goto LAB_8007a208;
    }
  }
  data->ReaverScale = data->ReaverTargetScale;
LAB_8007a208:
  SoulReaverCharge(instance, data);
  return;
}
