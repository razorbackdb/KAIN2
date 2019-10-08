#include "THISDUST.H"
#include "PHYSOBS.H"

void PHYSOB_PlayDropSound(_Instance *instance)

{
  short sVar1;
  int sfxToneID;
  void *pvVar2;
  int pitch;
  int maxVolume;
  undefined *local_18;

  pvVar2 = instance->data;
  sVar1 = *(short *)((int)pvVar2 + 2);
  if (sVar1 == 1)
  {
    sfxToneID = (int)*(short *)((int)pvVar2 + 10);
  }
  else
  {
    if (sVar1 == 0)
    {
      sfxToneID = (int)*(char *)((int)pvVar2 + 0x13);
    }
    else
    {
      sfxToneID = 0;
      if ((sVar1 == 3) && (*(int *)((int)pvVar2 + 0x28) != 0))
      {
        sfxToneID = (int)*(char *)(*(int *)((int)pvVar2 + 0x28) + 0xb);
      }
    }
  }
  if (sfxToneID == 2)
  {
    SOUND_Play3dSound(&instance->position, 0x11a, (int)&DAT_fffffe70, 0x5a, (int)&DAT_000036b0);
    sfxToneID = 0x11a;
    pitch = -800;
    maxVolume = 100;
    local_18 = &DAT_000036b0;
  }
  else
  {
    if (sfxToneID < 3)
    {
      if (sfxToneID != 1)
      {
        return;
      }
      sfxToneID = 10;
      pitch = -100;
    }
    else
    {
      if (sfxToneID != 3)
      {
        return;
      }
      sfxToneID = 0xb2;
      pitch = -800;
    }
    local_18 = &DAT_00007530;
    maxVolume = 0x78;
  }
  SOUND_Play3dSound(&instance->position, sfxToneID, pitch, maxVolume, (int)local_18);
  return;
}

_Instance *PHYSOBS_IsAnythingAttached(_Instance *block)

{
  _Instance *instance;
  int iVar1;
  _Instance *p_Var2;

  p_Var2 = (gameTrackerX.instanceList)->first;
  do
  {
    instance = p_Var2;
    if (instance == (_Instance *)0x0)
    {
      return (_Instance *)0x0;
    }
    p_Var2 = instance->next;
  } while ((instance->attachedID != block->introUniqueID) ||
           (iVar1 = CheckPhysOb(instance, 2), iVar1 == 0));
  return instance;
}

_Instance *PHYSOBS_IsAPushBlockAttached(_Instance *block)

{
  _Instance **pp_Var1;
  _Instance *p_Var2;

  if ((gameTrackerX.instanceList)->first != (_Instance *)0x0)
  {
    p_Var2 = (gameTrackerX.instanceList)->first;
    do
    {
      pp_Var1 = &p_Var2->next;
      if (p_Var2->attachedID == block->introUniqueID)
      {
        return p_Var2;
      }
      p_Var2 = *pp_Var1;
    } while (*pp_Var1 != (_Instance *)0x0);
  }
  return (_Instance *)0x0;
}

int CheckPhysObFamily(_Instance *instance)

{
  if (instance->data == (void *)0x0)
  {
    return 0;
  }
  return (u_int)(*(short *)((int)instance->data + 4) == -0x4ff5);
}

int CheckPhysOb(_Instance *instance, u_short ability)

{
  void *pvVar1;

  pvVar1 = instance->data;
  if (pvVar1 != (void *)0x0)
  {
    if (*(short *)((int)pvVar1 + 4) != -0x4ff5)
    {
      return 0;
    }
    if (*(short *)((int)pvVar1 + 2) == 3)
    {
      if ((*(u_short *)((int)instance->extraData + 4) & ability) == 0)
      {
        return 0;
      }
      return 1;
    }
    if ((*(u_short *)((int)pvVar1 + 6) & ability) != 0)
    {
      return 1;
    }
  }
  return 0;
}

int CheckPhysObAbility(_Instance *instance, u_short family)

{
  void *pvVar1;

  pvVar1 = instance->data;
  if (pvVar1 != (void *)0x0)
  {
    if (*(short *)((int)pvVar1 + 4) != -0x4ff5)
    {
      return 0;
    }
    if (*(u_short *)((int)pvVar1 + 2) == family)
    {
      return 1;
    }
  }
  return 0;
}

int GetPhysicalAbility(_Instance *instance)

{
  void *pvVar1;

  pvVar1 = instance->data;
  if ((pvVar1 != (void *)0x0) && (*(short *)((int)pvVar1 + 4) == -0x4ff5))
  {
    if (*(short *)((int)pvVar1 + 2) == 3)
    {
      return (int)*(short *)((int)instance->extraData + 4);
    }
    return (u_int) * (u_short *)((int)pvVar1 + 6);
  }
  return 0;
}

int AnyBlocksInMotion(void)

{
  _Instance *p_Var1;

  p_Var1 = (gameTrackerX.instanceList)->first;
  while (true)
  {
    if (p_Var1 == (_Instance *)0x0)
    {
      return 0;
    }
    if (((((p_Var1->object->oflags2 & 0x40000U) != 0) &&
          ((*(u_short *)((int)p_Var1->data + 6) & 8) != 0)) &&
         (*(short *)((int)p_Var1->data + 4) == -0x4ff5)) &&
        ((*(u_int *)p_Var1->extraData & 0x14e) != 0))
      break;
    p_Var1 = p_Var1->next;
  }
  return 1;
}

void ThrowPhysOb(_Instance *instance, evObjectThrowData *throwData)

{
  short angle;
  int iVar1;
  u_long uVar2;
  MATRIX *pMVar3;
  _Instance *parent;
  int NewAnim;
  int iVar4;
  int iVar5;
  void *pvVar6;
  _Instance *Inst;
  u_int *puVar7;
  int iVar8;
  _PCollideInfo local_60;
  SVECTOR local_30;
  SVECTOR local_28;

  parent = instance->LinkParent;
  if (parent == (_Instance *)0x0)
  {
    return;
  }
  pvVar6 = instance->data;
  instance->flags2 = instance->flags2 | 0x4000;
  INSTANCE_UnlinkFromParent(instance);
  iVar1 = PHYSOB_CheckDirectedLineCollision(instance, parent);
  instance->flags2 = instance->flags2 | 0x80;
  if (throwData == (evObjectThrowData *)0x0)
  {
    throwData = (evObjectThrowData *)
        SetObjectData((void *)0x0, (_SVector *)0x0, 0, 0, 0x180, 0, 0x40, -0x400);
  }
  puVar7 = (u_int *)instance->extraData;
  puVar7[2] = 0;
  *puVar7 = *puVar7 & 0xffffff7e | 0x1010;
  angle = throwData->initialXRot;
  *(_Instance **)(puVar7 + 0x10) = parent;
  *(short *)(puVar7 + 0xe) = angle;
  if ((*(short *)((int)pvVar6 + 2) == 7) &&
      (NewAnim = (int)*(char *)(*(int *)((int)pvVar6 + 0xc) +
                                *(int *)((int)instance->extraData + 4) * 0xc + 2),
       NewAnim != -1))
  {
    G2EmulationInstanceToInstanceSwitchAnimationCharacter(instance, 0, NewAnim, 0, 0);
    G2EmulationInstanceInitSection(instance, 0, 2);
  }
  instance->zAccl = (int)throwData->gravity;
  switch (throwData->type)
  {
  case 0:
    if (parent->LinkParent == (_Instance *)0x0)
    {
      angle = (parent->rotation).z;
    }
    else
    {
      angle = (parent->LinkParent->rotation).z;
    }
    PhysicsSetVelFromZRot(instance, angle, (u_int)throwData->speed);
    instance->zVel = (int)throwData->zVel;
    break;
  case 1:
    Inst = *(_Instance **)&throwData->data;
    *(_Instance **)(puVar7 + 2) = Inst;
    angle = MATH3D_AngleFromPosToPos(&instance->position, &Inst->position);
    PhysicsSetVelFromZRot(instance, angle, (u_int)throwData->speed);
    instance->zVel = 0;
    uVar2 = INSTANCE_Post(Inst, 0xc);
    iVar5 = instance->xVel;
    iVar4 = instance->yVel;
    NewAnim = iVar5;
    if (iVar5 < 0)
    {
      NewAnim = -iVar5;
    }
    iVar8 = iVar4;
    if (iVar4 < 0)
    {
      iVar8 = -iVar4;
    }
    if (iVar8 < NewAnim)
    {
      NewAnim = *(int *)(uVar2 + 0x14) - (int)(instance->position).x;
      if ((iVar5 == 0) || (NewAnim == 0))
        break;
      iVar5;
      iVar5 = (*(int *)(uVar2 + 0x1c) - (int)(instance->position).z) * iVar5;
    }
    else
    {
      NewAnim = *(int *)(uVar2 + 0x18) - (int)(instance->position).y;
      if ((iVar4 == 0) || (NewAnim == 0))
        break;
      iVar4;
      iVar5 = (*(int *)(uVar2 + 0x1c) - (int)(instance->position).z) * iVar4;
    }
    NewAnim - (iVar8 >> 1);
    break;
  case 2:
    angle = MATH3D_AngleFromPosToPos(&instance->position, (_Position *)&throwData->data);
    PhysicsSetVelFromZRot(instance, angle, (u_int)throwData->speed);
    iVar5 = instance->xVel;
    iVar4 = instance->yVel;
    NewAnim = iVar5;
    if (iVar5 < 0)
    {
      NewAnim = -iVar5;
    }
    iVar8 = iVar4;
    if (iVar4 < 0)
    {
      iVar8 = -iVar4;
    }
    instance->zVel = 0;
    if (iVar8 < NewAnim)
    {
      NewAnim = (int)*(short *)&throwData->data - (int)(instance->position).x;
      if ((iVar5 == 0) || (NewAnim == 0))
        break;
      iVar5;
      iVar5 = ((int)*(short *)((int)&throwData->data + 4) - (int)(instance->position).z) * iVar5;
    }
    else
    {
      NewAnim = (int)*(short *)((int)&throwData->data + 2) - (int)(instance->position).y;
      if ((iVar4 == 0) || (NewAnim == 0))
        break;
      iVar4;
      iVar5 = ((int)*(short *)((int)&throwData->data + 4) - (int)(instance->position).z) * iVar4;
    }
    NewAnim - (iVar8 >> 1);
    break;
  case 3:
    PhysicsSetVelFromRot(instance, (_Rotation *)&throwData->data, (u_int)throwData->speed);
    break;
  case 4:
    instance->xVel = (int)*(short *)&throwData->data;
    instance->yVel = (int)*(short *)((int)&throwData->data + 2);
    instance->zVel = (int)*(short *)((int)&throwData->data + 4);
    instance->zAccl = (int)throwData->gravity;
  }
  angle = throwData->spinType;
  if (angle == 1)
  {
    *(u_short *)((int)puVar7 + 0x36) = *(u_short *)((int)puVar7 + 0x36) | 1;
  }
  else
  {
    if (angle < 2)
    {
      if (angle == 0)
      {
        *(undefined2 *)((int)puVar7 + 0x3a) = 0;
        *(undefined2 *)(puVar7 + 0xf) = 0;
        *(undefined2 *)((int)puVar7 + 0x3e) = 0;
        *(u_short *)((int)puVar7 + 0x36) = *(u_short *)((int)puVar7 + 0x36) & 0xfffe;
      }
    }
    else
    {
      if (angle == 2)
      {
        *(short *)((int)puVar7 + 0x3a) = (throwData->angularVel).x;
        *(short *)(puVar7 + 0xf) = (throwData->angularVel).y;
        angle = (throwData->angularVel).z;
        *(u_short *)((int)puVar7 + 0x36) = *(u_short *)((int)puVar7 + 0x36) & 0xfffe;
        *(short *)((int)puVar7 + 0x3e) = angle;
      }
    }
  }
  if (iVar1 != 0)
  {
    instance->xVel = 0;
    instance->yVel = 0;
    instance->zVel = 0;
    NewAnim = CheckPhysOb(instance, 0x200);
    if ((NewAnim == 0) || (iVar1 != 1))
    {
      *puVar7 = *puVar7 & 0xffffefff;
    }
    else
    {
      *puVar7 = *puVar7 | 0x1000;
      instance->flags2 = instance->flags2 & 0xffffff7f;
      *puVar7 = *puVar7 & 0xffffffef;
      pMVar3 = instance->matrix;
      local_28.vx = *(short *)pMVar3[2].t;
      local_28.vy = *(short *)(pMVar3[2].t + 1);
      local_30.vz = *(short *)(pMVar3[2].t + 2);
      local_30.vx = (parent->position).x;
      local_60.newPoint = &local_30;
      local_30.vy = (parent->position).y;
      local_60.oldPoint = &local_28;
      local_28.vz = local_30.vz;
      PHYSICS_CheckLineInWorld(instance, &local_60);
      if (local_60.type == 3)
      {
        local_28.vx = local_30.vx - local_28.vx;
        local_28.vy = local_30.vy - local_28.vy;
        local_28.vz = local_30.vz - local_28.vz;
        (instance->position).x = (instance->position).x + local_28.vx;
        (instance->position).y = (instance->position).y + local_28.vy;
        (instance->position).z = (instance->position).z + local_28.vz;
      }
    }
  }
  if ((*puVar7 & 0x10) != 0)
  {
    if (iVar1 == 0)
    {
      PhysicsDefaultLinkedMoveResponse(instance, &instance->position, gameTrackerX.timeMult);
    }
    TurnOffCollisionPhysOb(instance, 4);
  }
  puVar7[0x11] = 0x96000;
  return;
}

int PushPhysOb(_Instance *instance, short x, short y, short PathNumber, _Instance *Force)

{
  int iVar1;
  u_int *puVar2;
  u_int uVar3;
  short local_20;
  short local_1e[3];

  uVar3 = 0;
  if (((*(u_short *)((int)instance->data + 6) & 8) != 0) &&
      (uVar3 = 0, *(short *)((int)instance->data + 4) == -0x4ff5))
  {
    puVar2 = (u_int *)instance->extraData;
    uVar3 = 0;
    if ((*puVar2 & 0x214a) == 0)
    {
      local_20 = x;
      local_1e[0] = y;
      iVar1 = AnyBlocksInMotion();
      uVar3 = 0;
      if (iVar1 == 0)
      {
        PHYSOB_NormalToAxis(&local_20, local_1e);
        *(_Instance **)(puVar2 + 2) = Force;
        *(short *)(puVar2 + 10) = PathNumber;
        *(short *)(puVar2 + 1) = local_20;
        *(short *)((int)puVar2 + 6) = local_1e[0];
        *puVar2 = *puVar2 & 0xfffffff7;
        instance->zVel = 0;
        instance->yVel = 0;
        instance->xVel = 0;
        instance->zAccl = 0;
        instance->yAccl = 0;
        instance->xAccl = 0;
        uVar3 = PHYSICS_CheckForValidMove(instance);
        if ((uVar3 & 1) != 0)
        {
          if ((*puVar2 & 0x100) == 0)
          {
            *(short *)((int)puVar2 + 0xe) = (instance->position).x;
            *(short *)(puVar2 + 4) = (instance->position).y;
            *(short *)((int)puVar2 + 0x12) = (instance->position).z;
          }
          *puVar2 = *puVar2 | 0x1000;
          instance->flags2 = instance->flags2 | 8;
        }
      }
    }
  }
  return uVar3;
}

void ResetSwitchPhysOb(_Instance *instance)

{
  byte bVar1;
  int iVar2;
  void *pvVar3;

  iVar2 = CheckPhysObAbility(instance, 2);
  if (iVar2 != 0)
  {
    pvVar3 = instance->data;
    *(u_int *)instance->extraData = *(u_int *)instance->extraData | 0x800;
    if (((*(u_short *)((int)instance->extraData + 0x14) & 2) != 0) &&
        (bVar1 = *(byte *)((int)pvVar3 + 0x10), bVar1 != 0))
    {
      G2EmulationInstanceToInstanceSwitchAnimationCharacter(instance, 0, (u_int)bVar1, 0, 0);
      G2EmulationInstanceInitSection(instance, 0, 1);
    }
  }
  return;
}

int SwitchPhysOb(_Instance *instance)

{
  u_short uVar1;
  int iVar2;
  int iVar3;
  u_int uVar4;
  void *pvVar5;
  void *pvVar6;

  pvVar5 = instance->data;
  iVar2 = CheckPhysObAbility(instance, 2);
  iVar3 = 1;
  if (iVar2 != 0)
  {
    *(u_int *)instance->extraData = *(u_int *)instance->extraData | 0x800;
    pvVar6 = instance->extraData;
    uVar1 = *(u_short *)((int)pvVar6 + 0x14);
    if ((uVar1 & 1) == 0)
    {
      if ((uVar1 & 2) == 0)
      {
        if (*(byte *)((int)pvVar5 + 0xe) != 0xff)
        {
          G2EmulationInstanceToInstanceSwitchAnimationCharacter(instance, 0, (u_int) * (byte *)((int)pvVar5 + 0xe), 0, 0);
        }
      }
      else
      {
        *(u_short *)((int)pvVar6 + 0x14) = uVar1 | 5;
        G2EmulationInstanceToInstanceSwitchAnimationCharacter(instance, 0, (u_int) * (byte *)((int)pvVar5 + 0xc), 0, 0);
        if (*(short *)((int)pvVar5 + 10) == 7)
        {
          *(undefined2 *)((int)pvVar6 + 0x16) = 0x400;
        }
        else
        {
          *(undefined2 *)((int)pvVar6 + 0x16) = 0;
        }
        uVar4 = instance->flags;
        (instance->rotation).z = (instance->rotation).z + *(short *)((int)pvVar6 + 0x16);
        instance->flags = uVar4 | 8;
      }
      G2EmulationInstanceInitSection(instance, 0, 1);
    }
    else
    {
      if ((uVar1 & 2) == 0)
      {
        if (*(byte *)((int)pvVar5 + 0xf) != 0xff)
        {
          G2EmulationInstanceToInstanceSwitchAnimationCharacter(instance, 0, (u_int) * (byte *)((int)pvVar5 + 0xf), 0, 0);
          G2EmulationInstanceInitSection(instance, 0, 1);
          *(u_short *)((int)pvVar6 + 0x14) = *(u_short *)((int)pvVar6 + 0x14) | 2;
        }
      }
      else
      {
        *(u_short *)((int)pvVar6 + 0x14) = uVar1 & 0xfffe | 8;
        G2EmulationInstanceToInstanceSwitchAnimationCharacter(instance, 0, (u_int) * (byte *)((int)pvVar5 + 0xd), 0, 0);
        G2EmulationInstanceInitSection(instance, 0, 1);
        (instance->rotation).z = (instance->rotation).z + *(short *)((int)pvVar6 + 0x16);
        if (*(short *)((int)pvVar5 + 10) == 7)
        {
          *(undefined2 *)((int)pvVar6 + 0x16) = 0x400;
        }
        else
        {
          *(undefined2 *)((int)pvVar6 + 0x16) = 0;
        }
        instance->flags = instance->flags | 8;
      }
    }
    iVar3 = 0;
  }
  return iVar3;
}

int InteractPhysOb(_Instance *instance, _Instance *Force, int LinkNode, int Action)

{
  int Mode;
  u_int *puVar1;
  u_int uVar2;
  _PhysObLight *pLight;
  byte bVar3;
  _Model **pp_Var4;
  _Instance *instance_00;
  void *pvVar5;

  pvVar5 = instance->data;
  Mode = CheckPhysObAbility(instance, 3);
  if (Mode == 0)
  {
    return 1;
  }
  puVar1 = (u_int *)instance->extraData;
  if (*(char *)((int)pvVar5 + 0x14) != -1)
  {
    if (Action == 2)
    {
      instance_00 = Force->LinkChild;
      pLight = PhysObGetWeapon(instance_00);
      PHYSOB_StartBurning(instance_00, pLight);
    }
    else
    {
      if (Action < 3)
      {
        if (Action == 1)
        {
          uVar2 = *puVar1;
          *puVar1 = uVar2 & 0xfffffffe | 0x1080;
          if ((uVar2 & 0x10000) != 0)
          {
            instance_00 = Force->LinkChild;
            pLight = PhysObGetWeapon(instance_00);
            FX_StartLightbeam(instance_00, pLight);
          }
          *(undefined2 *)(puVar1 + 1) = *(undefined2 *)((int)pvVar5 + 0x18);
          *(undefined2 *)((int)puVar1 + 6) = *(undefined2 *)((int)pvVar5 + 0x1a);
          INSTANCE_LinkToParent(instance, Force, LinkNode);
        }
      }
      else
      {
        if (Action == 9)
        {
          INSTANCE_Query(instance, 0x40002, 5);
        }
      }
    }
    if (Action == (u_int) * (u_short *)((int)pvVar5 + 0xc))
    {
      instance->flags = instance->flags | 8;
    }
    if (Action == (u_int) * (u_short *)((int)pvVar5 + 0xe))
    {
      instance->flags = instance->flags | 0x10;
    }
  }
  if ((*(byte *)((int)pvVar5 + 0x11) == 0xff) || ((*(u_short *)((int)pvVar5 + 6) & 0x8000) == 0))
    goto LAB_80069d10;
  G2EmulationInstanceToInstanceSwitchAnimationCharacter(instance, 0, (u_int) * (byte *)((int)pvVar5 + 0x11), 0, 0);
  bVar3 = *(byte *)((int)pvVar5 + 0x15) & 0x30;
  if (bVar3 == 0x10)
  {
    Mode = 1;
  LAB_80069d08:
    G2EmulationInstanceInitSection(instance, 0, Mode);
  }
  else
  {
    if (bVar3 < 0x11)
    {
      if ((*(byte *)((int)pvVar5 + 0x15) & 0x30) == 0)
      {
        Mode = 2;
        goto LAB_80069d08;
      }
    }
    else
    {
      if (bVar3 == 0x20)
      {
        Mode = 0;
        goto LAB_80069d08;
      }
    }
  }
LAB_80069d10:
  pp_Var4 = instance->object->modelList;
  if (pp_Var4 != (_Model **)0x0)
  {
    if ((*(byte *)((int)pvVar5 + 0x15) & 0x80) == 0)
    {
      Mode = 0;
      if (0 < (*pp_Var4)->numSegments)
      {
        do
        {
          COLLIDE_SegmentCollisionOff(instance, Mode);
          Mode = Mode + 1;
        } while (Mode < (*instance->object->modelList)->numSegments);
      }
    }
    else
    {
      Mode = 0;
      if (0 < (*pp_Var4)->numSegments)
      {
        do
        {
          COLLIDE_SegmentCollisionOn(instance, Mode);
          Mode = Mode + 1;
        } while (Mode < (*instance->object->modelList)->numSegments);
        puVar1[2] = 0;
        goto LAB_80069de8;
      }
    }
  }
  puVar1[2] = 0;
LAB_80069de8:
  *(undefined2 *)((int)puVar1 + 0x26) = 0;
  *(undefined2 *)(puVar1 + 9) = 0;
  *(undefined2 *)(puVar1 + 1) = *(undefined2 *)((int)pvVar5 + 0x18);
  *(undefined2 *)((int)puVar1 + 6) = *(undefined2 *)((int)pvVar5 + 0x1a);
  instance->xVel = 0;
  instance->yVel = 0;
  instance->zVel = 0;
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = 0;
  return 0;
}

void ResetOrientation(_Instance *instance)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  _G2EulerAngles_Type local_28;
  _G2SVector3_Type local_20;
  u_short local_18;
  u_short local_16;
  u_short local_14;

  _G2Anim_FindController(&instance->anim, 0, 0x4c);
  pvVar5 = instance->extraData;
  iVar4 = (int)(instance->position).x - (int)*(short *)((int)pvVar5 + 0xe);
  if (iVar4 != 0)
  {
    if (iVar4 < 1)
    {
      iVar4 = iVar4 + -0x140;
    }
    else
    {
      iVar4 = iVar4 + 0x140;
    }
 0x280) * 0x280;
  }
  iVar4 = (int)(instance->position).y - (int)*(short *)((int)pvVar5 + 0x10);
  if (iVar4 != 0)
  {
    if (iVar4 < 1)
    {
 0x280);
    }
    else
    {
 0x280);
    }
    (instance->position).y = *(short *)((int)pvVar5 + 0x10) + sVar1 * 0x280;
  }
  iVar4 = (int)(instance->position).z - (int)*(short *)((int)pvVar5 + 0x12);
  if (iVar4 != 0)
  {
    if (iVar4 < 0)
    {
 0xa0);
    }
    else
    {
 0xa0);
    }
    (instance->position).z = *(short *)((int)pvVar5 + 0x12) + sVar1 * 0xa0;
  }
  *(short *)((int)pvVar5 + 0xe) = (instance->position).x;
  *(short *)((int)pvVar5 + 0x10) = (instance->position).y;
  *(short *)((int)pvVar5 + 0x12) = (instance->position).z;
  G2EulerAngles_FromMatrix(&local_28, (_G2Matrix_Type *)(instance->matrix + 2), 0x15);
  iVar4 = (int)(short)local_28.x;
  if (iVar4 < 0)
  {
    local_18 = (u_short)(iVar4 + -0x200) & 0xfc00;
    if (iVar4 + -0x200 < 0)
    {
      sVar1 = 0x1ff;
    LAB_8006a068:
      local_18 = local_28.x + sVar1 & 0xfc00;
    }
  }
  else
  {
    local_18 = (u_short)(iVar4 + 0x200) & 0xfc00;
    if (iVar4 + 0x200 < 0)
    {
      sVar1 = 0x5ff;
      goto LAB_8006a068;
    }
  }
  iVar4 = (int)local_28.y;
  if (iVar4 < 0)
  {
    local_16 = (u_short)(iVar4 + -0x200) & 0xfc00;
    if (iVar4 + -0x200 < 0)
    {
      sVar1 = 0x1ff;
    LAB_8006a0a0:
      local_16 = local_28.y + sVar1 & 0xfc00;
    }
  }
  else
  {
    local_16 = (u_short)(iVar4 + 0x200) & 0xfc00;
    if (iVar4 + 0x200 < 0)
    {
      sVar1 = 0x5ff;
      goto LAB_8006a0a0;
    }
  }
  iVar4 = (int)local_28.z;
  if (iVar4 < 0)
  {
    local_14 = (u_short)(iVar4 + -0x200) & 0xfc00;
    if (-1 < iVar4 + -0x200)
      goto LAB_8006a0dc;
    sVar1 = 0x1ff;
  }
  else
  {
    local_14 = (u_short)(iVar4 + 0x200) & 0xfc00;
    if (-1 < iVar4 + 0x200)
      goto LAB_8006a0dc;
    sVar1 = 0x5ff;
  }
  local_14 = local_28.z + sVar1 & 0xfc00;
LAB_8006a0dc:
  iVar4 = (int)(((u_int)local_28.x - (u_int)local_18) * 0x10000) >> 0x10;
  if (iVar4 < 0)
  {
    iVar4 = iVar4 + -0x96;
  }
  else
  {
    iVar4 = iVar4 + 0x96;
  }
  iVar2 = (int)(short)(local_28.y - local_16);
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + -0x96;
  }
  else
  {
    iVar2 = iVar2 + 0x96;
  }
  iVar3 = (int)(short)(local_28.z - local_14);
  if (iVar3 < 0)
  {
    iVar3 = iVar3 + -0x96;
  }
  else
  {
    iVar3 = iVar3 + 0x96;
  }
 0x12d) * 0x12d + local_18;
 0x12d) * 0x12d + local_16;
 0x12d) * 0x12d + local_14;
 iVar4 = (int)(short)local_20.x - (int)(short)local_28.x;
 iVar2 = (int)(short)local_18 - (int)(short)local_28.x;
 if (iVar4 < 0)
 {
   iVar4 = -iVar4;
 }
 if (iVar2 < 0)
 {
   iVar2 = -iVar2;
 }
 if (iVar2 < iVar4)
 {
   local_20.x = local_18;
 }
 iVar4 = (int)(short)local_20.y - (int)local_28.y;
 iVar2 = (int)(short)local_16 - (int)local_28.y;
 if (iVar4 < 0)
 {
   iVar4 = -iVar4;
 }
 if (iVar2 < 0)
 {
   iVar2 = -iVar2;
 }
 if (iVar2 < iVar4)
 {
   local_20.y = local_16;
 }
 iVar4 = (int)(short)local_20.z - (int)local_28.z;
 iVar2 = (int)(short)local_14 - (int)local_28.z;
 if (iVar4 < 0)
 {
   iVar4 = -iVar4;
 }
 if (iVar2 < 0)
 {
   iVar2 = -iVar2;
 }
 if (iVar2 < iVar4)
 {
   local_20.z = local_14;
 }
 G2Anim_GetControllerCurrentInterpVector(&instance->anim, 2, 0xe, &local_20);
 _G2Instance_BuildNonAnimatedTransforms(instance);
 G2Anim_GetKeylist(&instance->anim, *instance->object->animList, 0);
 return;
}

void FinishPush(_Instance *instance)

{
  ResetOrientation(instance);
  return;
}

void PhysOb_AlignPush(_Instance *instance, int x, int y, int path, PhysObData *Data)

{
  _G2Anim_Type *anim;
  short sVar1;
  _G2SVector3_Type local_60;
  u_int auStack88[6];
  undefined auStack64[24];
  _G2EulerAngles_Type local_28;

  G2Anim_DisableController(&instance->anim, 0, 0x4c);
  G2Anim_DisableController(&instance->anim, 2, 0xe);
  sVar1 = 0x800;
  Data->xForce = (short)x;
  Data->yForce = (short)y;
  Data->PathNumber = (short)path;
  Data->Mode = Data->Mode & 0xffefffff;
  if (((y < 1) && (sVar1 = 0, -1 < y)) && (sVar1 = 0x400, x < 0))
  {
    sVar1 = -0x400;
  }
  anim = &instance->anim;
  local_60.x = 0;
  local_60.y = 0;
  local_60.z = sVar1;
  G2Anim_GetControllerCurrentInterpVector(anim, 0, 0x4c, &local_60);
  local_60.z = -sVar1;
  RotMatrixZYX((u_short *)&local_60, auStack88);
  PopMatrix(auStack88, (u_short *)(instance->matrix + 2), (u_int *)(_G2Matrix_Type *)auStack64);
  G2EulerAngles_FromMatrix(&local_28, (_G2Matrix_Type *)auStack64, 0x15);
  local_60.x = local_28.x;
  local_60.y = local_28.y;
  local_60.z = local_28.z;
  G2Anim_GetControllerCurrentInterpVector(anim, 2, 0xe, &local_60);
  G2Anim_GetKeylist(anim, instance->object->animList[path], path);
  return;
}

int PickUpPhysOb(_Instance *instance, short x, short y, _Instance *Force)

{
  short sVar1;
  _Instance *p_Var2;
  int iVar3;
  u_int *puVar4;
  u_int uVar5;
  short local_20;
  short local_1e[3];

  uVar5 = 0;
  if ((*(u_short *)((int)instance->data + 6) & 2) != 0)
  {
    local_20 = x;
    local_1e[0] = y;
    p_Var2 = PHYSOBS_IsAnythingAttached(instance);
    uVar5 = 0;
    if (p_Var2 == (_Instance *)0x0)
    {
      puVar4 = (u_int *)instance->extraData;
      uVar5 = 0;
      if ((*puVar4 & 0x2000) == 0)
      {
        iVar3 = AnyBlocksInMotion();
        uVar5 = 0;
        if (iVar3 == 0)
        {
          PHYSOB_NormalToAxis(&local_20, local_1e);
          *(undefined2 *)(puVar4 + 10) = 1;
          *(_Instance **)(puVar4 + 2) = Force;
          *puVar4 = *puVar4 | 8;
          *(short *)(puVar4 + 1) = local_20;
          *(short *)((int)puVar4 + 6) = local_1e[0];
          instance->zVel = 0;
          instance->yVel = 0;
          instance->xVel = 0;
          instance->zAccl = 0;
          instance->yAccl = 0;
          instance->xAccl = 0;
          ResetOrientation(instance);
          uVar5 = PHYSICS_CheckForValidMove(instance);
          if ((uVar5 & 1) != 0)
          {
            *(short *)((int)puVar4 + 0xe) = (instance->position).x;
            *(short *)(puVar4 + 4) = (instance->position).y;
            sVar1 = (instance->position).z;
            *puVar4 = *puVar4 | 0x1000;
            *(short *)((int)puVar4 + 0x12) = sVar1;
            instance->flags2 = instance->flags2 | 8;
          }
        }
      }
    }
  }
  return uVar5;
}

int CanBePickedUp(_Instance *instance, _Instance *Force, int LinkNode)

{
  int iVar1;
  long lVar2;
  _PCollideInfo local_50;
  SVECTOR local_20;
  SVECTOR local_18;

  if (Force == (_Instance *)0x0)
  {
    return 0;
  }
  if (((Force->object->oflags2 & 0x80000U) == 0) && (Force->matrix != (MATRIX *)0x0))
  {
    iVar1 = CheckPhysOb(instance, 1);
    if (iVar1 == 0)
    {
      return 0;
    }
    if (instance->matrix != (MATRIX *)0x0)
    {
      local_18.vx = *(short *)instance->matrix[2].t;
      local_18.vy = *(short *)(instance->matrix[2].t + 1);
      local_18.vz = *(short *)(instance->matrix[2].t + 2);
      local_20.vx = *(short *)Force->matrix[LinkNode].t;
      local_20.vy = *(short *)(Force->matrix[LinkNode].t + 1);
      local_20.vz = *(short *)(Force->matrix[LinkNode].t + 2);
      local_50.newPoint = &local_20;
      local_50.oldPoint = &local_18;
      iVar1 = CheckPhysOb(instance, 0x20);
      if ((iVar1 != 0) && (local_20.vz < local_18.vz))
      {
        return 1;
      }
      PHYSICS_CheckLineInWorld(instance, &local_50);
      if (1 < local_50.type)
      {
        lVar2 = MATH3D_LengthXY((int)local_20.vx - (int)local_18.vx,
                                (int)local_20.vy - (int)local_18.vy,
                                (int)local_20.vz - (int)local_18.vz);
        if (0x14 < lVar2)
        {
          return 0;
        }
        return 1;
      }
    }
  }
  return 1;
}

int StopPhysOb(_Instance *instance, short Steps, _Instance *Force, int LinkNode)

{
  int iVar1;
  _PhysObLight *pLight;
  u_int *puVar2;

  puVar2 = (u_int *)instance->extraData;
  if (instance->LinkParent == (_Instance *)0x0)
  {
    if ((*puVar2 & 0x2000000) != 0)
    {
      return 1;
    }
    TurnOnCollisionPhysOb(instance, 7);
    iVar1 = CanBePickedUp(instance, Force, LinkNode);
    if (iVar1 != 0)
    {
      *(short *)(puVar2 + 9) = Steps;
      *(undefined2 *)((int)puVar2 + 0x26) = 0;
      *(_Instance **)(puVar2 + 2) = Force;
      *(short *)(puVar2 + 3) = (short)LinkNode;
      *puVar2 = *puVar2 & 0xff9fffff | 0x4000;
      iVar1 = CheckPhysOb(instance, 0x20);
      if (iVar1 != 0)
      {
        if ((*puVar2 & 0x10000) == 0)
        {
          return 0;
        }
        pLight = PhysObGetWeapon(instance);
        if (pLight != (_PhysObLight *)0x0)
        {
          FX_StartLightbeam(instance, pLight);
        }
      }
      return 0;
    }
  }
  return 1;
}

_Instance *PHYSOB_BirthProjectile(_Instance *parent, int x, int y, int z, int type, int lifeTime)

{
  return (_Instance *)0x0;
}

evObjectBirthProjectileData *PHYSOB_BirthCollectible(_Instance *parent, int joint, int type)

{
  evObjectBirthProjectileData *peVar1;
  _Instance *p_Var2;

  peVar1 = (evObjectBirthProjectileData *)SetObjectBirthProjectileData(parent, joint, type);
  p_Var2 = MON_Projectile(parent, joint, type);
  peVar1->birthInstance = p_Var2;
  return peVar1;
}

_Instance *MON_Projectile(_Instance *instance, int grabJoint, int type)

{
  return (_Instance *)0x0;
}

void PHYSOB_SetLightTable(_PhysObLight *pLight, LightInstance *li, short burnAmplitude)

{
  int iVar1;
  LightTableEntry *pLVar2;
  LightTableEntry *pLVar3;
  u_int uVar4;
  u_int uVar5;

  uVar5 = (int)((u_int)(u_short)gameTrackerX.vblCount * (int)pLight->speed) %
          ((u_int)pLight->length << 0xc);
  pLVar2 = pLight->lightTable;
  uVar4 = uVar5 & 0xfff;
  iVar1 = (int)uVar5 >> 0xc;
  uVar5 = iVar1 + 1;
  pLVar3 = pLVar2 + iVar1;
  if (uVar5 == (u_int)pLight->length)
  {
    uVar5 = 0;
  }
  li->segment = pLight->segment;
  pLVar2 = pLVar2 + uVar5;
  iVar1 = ((int)(((u_int)(u_short)pLVar3->radius +
                  ((int)(((int)pLVar2->radius - (int)pLVar3->radius) * uVar4) >> 0xc)) *
                 0x10000) >>
           0x10) *
              (int)burnAmplitude >>
          0xc;
  li->radius = (short)iVar1;
  if (iVar1 << 0x10 < 1)
  {
    li->radius = 1;
  }

                      (int)li->radius);

                      (int)li->radius);

                      (int)li->radius);
                      return;
}

void PHYSOB_EndLighting(_Instance *instance, _PhysObLight *pLight)

{
  if ((pLight != (_PhysObLight *)0x0) &&
      (gameTrackerX.gameData.asmData.lightInstances[0].lightInstance == instance))
  {
    gameTrackerX.gameData.asmData.lightInstances[0].lightInstance = (_Instance *)0x0;
  }
  return;
}

void FX_StartLightbeam(_Instance *instance, _PhysObLight *pLight)

{
  u_int *puVar1;

  puVar1 = (u_int *)instance->extraData;
  if (*(short *)(puVar1 + 0xd) < 0)
  {
    *(short *)(puVar1 + 0xd) = -*(short *)(puVar1 + 0xd);
  }
  *puVar1 = *puVar1 | 0x18000;
  if (pLight != (_PhysObLight *)0x0)
  {
    gameTrackerX.gameData.asmData.lightInstances[0].lightInstance = instance;
    PHYSOB_SetLightTable(pLight, gameTrackerX.gameData.asmData.lightInstances, *(short *)(puVar1 + 0xd));
  }
  return;
}

void PHYSOB_StartBurnFX(_Instance *instance)

{
  int iVar1;
  int iVar2;
  Object *pOVar3;

  pOVar3 = instance->object;
  if (((*(short *)((int)instance->extraData + 0x34) == 0) && (pOVar3->numberOfEffects != 0)) &&
      (iVar2 = 0, 0 < pOVar3->numberOfEffects))
  {
    iVar1 = 0;
    do
    {
      FX_StartInstanceEffect(instance, (ObjectEffect *)(&pOVar3->effectList->effectNumber + iVar1), 1);
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 4;
    } while (iVar2 < pOVar3->numberOfEffects);
  }
  return;
}

void PHYSOB_StartBurning(_Instance *instance, _PhysObLight *pLight)

{
  PHYSOB_StartBurnFX(instance);
  FX_StartLightbeam(instance, pLight);
  return;
}

void PHYSOB_StopLighting(_Instance *instance, _PhysObLight *pLight)

{
  u_int *puVar1;

  puVar1 = (u_int *)instance->extraData;
  *(undefined2 *)(puVar1 + 0xd) = 0xf000;
  *puVar1 = *puVar1 | 0x8000;
  return;
}

void PHYSOB_StartLighting(_Instance *instance, _PhysObLight *pLight)

{
  u_int *puVar1;

  puVar1 = (u_int *)instance->extraData;
  *(undefined2 *)(puVar1 + 0xd) = 0xf000;
  *puVar1 = *puVar1 | 0x48000;
  return;
}

void PHYSOB_StopBurning(_Instance *instance, _PhysObLight *pLight)

{
  u_int *puVar1;

  puVar1 = (u_int *)instance->extraData;
  FX_EndInstanceEffects(instance);
  PHYSOB_EndLighting(instance, pLight);
  *(undefined2 *)(puVar1 + 0xd) = 0;
  *puVar1 = *puVar1 & 0xfffeffff;
  return;
}

void DropPhysOb(_Instance *instance)

{
  u_char *puVar1;

  puVar1 = (u_char *)instance->extraData;
  *(undefined2 *)(puVar1 + 9) = 0;
  *(undefined2 *)((int)puVar1 + 0x26) = 0;
  *(undefined2 *)((int)puVar1 + 0x1a) = 1;
  ResetOrientation(instance);
  *puVar1 = 1;
  return;
}

void PhysicalObjectPost(_Instance *instance, GameTracker *gameTracker)

{
  int segment;
  u_int *puVar1;
  u_long uVar2;
  u_int uVar3;
  INICommand *pIVar4;
  _PhysObLight *pLight;
  byte bVar5;
  short sVar6;
  _Model **pp_Var7;
  void *pvVar8;
  _G2Anim_Type *anim;
  void *pvVar9;
  _G2SVector3_Type local_50;
  _G2Matrix_Type _Stack72;
  _G2EulerAngles_Type local_28;

  if ((instance->flags & 0x20000U) != 0)
  {
    if (*(short *)((int)instance->data + 0x1c) == 2)
    {
      segment = SetObjectAbsorbData(0, (_Instance *)0x0);
      INSTANCE_Query(gameTracker->playerInstance, 0x800024, segment);
    }
    segment = CheckPhysOb(instance, 8);
    if (segment != 0)
    {
      razAttachControllers(&instance->anim, 0, 0x4c);
      razAttachControllers(&instance->anim, 2, 0xe);
    }
    MEMPACK_Init((char *)instance->extraData);
    return;
  }
  pvVar9 = instance->data;
  puVar1 = (u_int *)MEMPACK_Malloc(0x48, '\x1a');
  *(u_int **)&instance->extraData = puVar1;
  *puVar1 = 1;
  *(undefined2 *)((int)puVar1 + 0x1a) = 0x1001;
  *(undefined2 *)((int)puVar1 + 0x22) = 0x1002;
  *(undefined2 *)((int)puVar1 + 0x2a) = 0xffff;
  *(undefined2 *)(puVar1 + 0xd) = 0x1000;
  *(undefined2 *)(puVar1 + 1) = 0;
  *(undefined2 *)((int)puVar1 + 6) = 0;
  puVar1[2] = 0;
  *(undefined2 *)((int)puVar1 + 0xe) = 0;
  *(undefined2 *)(puVar1 + 4) = 0;
  *(undefined2 *)((int)puVar1 + 0x12) = 0;
  *(undefined2 *)(puVar1 + 5) = 0;
  *(undefined2 *)((int)puVar1 + 0x16) = 0;
  *(undefined2 *)(puVar1 + 6) = 0;
  *(undefined2 *)(puVar1 + 7) = 0;
  *(undefined2 *)((int)puVar1 + 0x1e) = 0;
  *(undefined2 *)(puVar1 + 8) = 0;
  *(undefined2 *)(puVar1 + 9) = 0;
  *(undefined2 *)((int)puVar1 + 0x26) = 0;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  instance->maxXVel = 0x280;
  instance->maxYVel = 0x280;
  instance->maxZVel = 0x280;
  *(undefined2 *)((int)puVar1 + 0x3a) = 0;
  *(undefined2 *)(puVar1 + 0xf) = 0;
  *(undefined2 *)((int)puVar1 + 0x3e) = 0;
  if ((instance->object != (Object *)0x0) && ((instance->object->oflags & 1U) == 0))
  {
    *puVar1 = *puVar1 | 0x1000;
  }
  if ((*(u_short *)((int)pvVar9 + 6) & 0x40) != 0)
  {
    *(u_short *)((int)pvVar9 + 6) = *(u_short *)((int)pvVar9 + 6) | 0x8000;
    instance->flags2 = instance->flags2 | 4;
  }
  if ((*(u_short *)((int)pvVar9 + 6) & 0x8000) != 0)
  {
    G2EmulationInit(instance, 1);
    G2EmulationInstanceToInstanceSwitchAnimation(instance, 0, 0,
                                                 (short)(((u_int) * (u_short *)&instance->object->modelList[instance->currentModel]->numSegments - 1) * 0x10000 >> 0x10));
    G2EmulationInstanceToInstanceSwitchAnimationCharacter(instance, 0, 0, 0, 0);
    G2EmulationInstanceInitSection(instance, 0, 2);
  }
  if (*(short *)((int)pvVar9 + 2) == 5)
  {
    pvVar8 = instance->data;
    G2EmulationInstanceQueryFrame(instance, 0, PhysobAnimCallback, instance);
    if (*(byte *)((int)pvVar8 + 0x10) != 0xff)
    {
      G2EmulationInstanceToInstanceSwitchAnimationCharacter(instance, 0, (u_int) * (byte *)((int)pvVar8 + 0x10), 0, 0);
      G2EmulationInstanceInitSection(instance, 0, 2);
    }
    sVar6 = *(short *)((int)pvVar8 + 8);
    if ((sVar6 == 2) && (gameTrackerX.playerInstance != (_Instance *)0x0))
    {
      uVar2 = INSTANCE_Post(gameTrackerX.playerInstance, 0x24);
      if ((uVar2 & 0xfc0000) == 0)
      {
        instance->flags = instance->flags | 0x20;
      }
      sVar6 = *(short *)((int)pvVar8 + 8);
    }
    if (sVar6 != 3)
    {
      instance->flags2 = instance->flags2 | 0x20000;
    }
  }
  if ((*(u_short *)((int)pvVar9 + 6) & 0x8d00) != 0)
  {
    *puVar1 = *puVar1 | 0x1000;
  }
  if (*(short *)((int)pvVar9 + 2) != 3)
  {
    segment = CheckPhysOb(instance, 1);
    if (segment == 0)
    {
      segment = CheckPhysOb(instance, 8);
      if (segment == 0)
      {
        segment = CheckPhysOb(instance, 0x40);
        if (segment != 0)
        {
          pvVar8 = instance->data;
          instance->flags2 = instance->flags2 | 4;
          pvVar9 = instance->extraData;
          bVar5 = *(byte *)((int)pvVar8 + 0x18);
          *(undefined2 *)((int)pvVar9 + 0x16) = 0;
          *(u_short *)((int)pvVar9 + 0x14) = (u_short)bVar5;
          if (*(char *)((int)pvVar8 + 0x19) == -1)
          {
            *(undefined *)((int)pvVar8 + 0x19) = 0;
          }
          G2EmulationInstanceToInstanceSwitchAnimationCharacter(instance, 0, (u_int) * (byte *)((int)pvVar8 + 0x19), 0, 0);
          G2EmulationInstanceQueryFrame(instance, 0, PhysobAnimCallback, instance);
        }
        segment = CheckPhysObAbility(instance, 7);
        if (segment != 0)
        {
          G2EmulationInstanceQueryFrame(instance, 0, PhysobAnimCallback, instance);
          instance->flags2 = instance->flags2 | 0x20000;
        }
      }
      else
      {
        instance->object->oflags = instance->object->oflags | 0x40000;
        *(short *)((int)puVar1 + 0xe) = (instance->position).x;
        *(short *)(puVar1 + 4) = (instance->position).y;
        *(short *)((int)puVar1 + 0x12) = (instance->position).z;
        instance->lightMatrix = 2;
        instance->object->oflags = instance->object->oflags | 0x400;
        G2EmulationInstanceQueryFrame(instance, 0, PhysobAnimCallback, instance);
        anim = &instance->anim;
        G2Anim_AttachControllerToSeg(anim, 0, 0x4c);
        G2Anim_AttachControllerToSeg(anim, 2, 0xe);
        _G2Anim_FindController(anim, 0, 0x4c);
        G2Anim_DisableController(anim, 2, 0xe);
        local_50.x = (instance->rotation).x;
        local_50.y = (instance->rotation).y;
        local_50.z = (instance->rotation).z;
        RotMatrixZYX((u_short *)&local_50, (u_int *)&_Stack72);
        G2EulerAngles_FromMatrix(&local_28, &_Stack72, 0x15);
        local_50.x = local_28.x;
        local_50.y = local_28.y;
        local_50.z = local_28.z;
        (instance->rotation).x = 0;
        (instance->rotation).y = 0;
        (instance->rotation).z = 0;
        G2Anim_GetControllerCurrentInterpVector(anim, 2, 0xe, &local_50);
      }
    }
    else
    {
      TurnOnCollisionPhysOb(instance, 7);
    }
    goto LAB_8006b65c;
  }
  pvVar8 = instance->extraData;
  *(u_short *)((int)pvVar8 + 4) = *(u_short *)((int)pvVar9 + 6) | 0x80;
  *(undefined2 *)((int)pvVar8 + 6) = 0;
  pvVar8 = instance->data;
  if ((*(u_short *)((int)pvVar8 + 0x18) & 0x80) == 0)
  {
    if ((*(u_short *)((int)pvVar8 + 0x18) & 1) == 0)
    {
      uVar3 = instance->flags2 | 4;
      goto LAB_8006b290;
    }
  }
  else
  {
    uVar3 = instance->flags2 | 0x20000;
  LAB_8006b290:
    instance->flags2 = uVar3;
  }
  pp_Var7 = instance->object->modelList;
  if (pp_Var7 != (_Model **)0x0)
  {
    if ((*(byte *)((int)pvVar8 + 0x15) & 8) == 0)
    {
      segment = 0;
      if (0 < (*pp_Var7)->numSegments)
      {
        do
        {
          COLLIDE_SegmentCollisionOff(instance, segment);
          segment = segment + 1;
        } while (segment < (*instance->object->modelList)->numSegments);
      }
    }
    else
    {
      segment = 0;
      if (0 < (*pp_Var7)->numSegments)
      {
        do
        {
          COLLIDE_SegmentCollisionOn(instance, segment);
          segment = segment + 1;
        } while (segment < (*instance->object->modelList)->numSegments);
      }
    }
  }
  TurnOnCollisionPhysOb(instance, 7);
  if ((*(u_short *)((int)pvVar9 + 6) & 0x8000) == 0)
    goto switchD_8006ce44_caseD_5;
  bVar5 = *(byte *)((int)pvVar8 + 0x15) & 3;
  if (bVar5 == 1)
  {
    segment = 1;
  switchD_8006ce44_caseD_6:
    G2EmulationInstanceInitSection(instance, 0, segment);
  }
  else
  {
    if (bVar5 < 2)
    {
      if ((*(byte *)((int)pvVar8 + 0x15) & 3) == 0)
      {
        segment = 2;
        goto switchD_8006ce44_caseD_6;
      }
    }
    else
    {
      if (bVar5 == 2)
      {
        segment = 0;
        goto switchD_8006ce44_caseD_6;
      }
    }
  }
switchD_8006ce44_caseD_5:
  if ((*(byte *)((int)pvVar8 + 0x10) != 0xff) && ((*(u_short *)((int)pvVar9 + 6) & 0x8000) != 0))
  {
    G2EmulationInstanceToInstanceSwitchAnimationCharacter(instance, 0, (u_int) * (byte *)((int)pvVar8 + 0x10), 0, 0);
  }
  if (*(short *)((int)pvVar8 + 0x1c) == 2)
  {
    segment = SetObjectAbsorbData(1, instance);
    INSTANCE_Query(gameTracker->playerInstance, 0x800024, segment);
  }
LAB_8006b65c:
  segment = CheckPhysOb(instance, 0x20);
  if (segment != 0)
  {
    pIVar4 = INSTANCE_FindWithID(instance, 0x15);
    pLight = PhysObGetWeapon(instance);
    if ((pLight == (_PhysObLight *)0x0) ||
        ((pIVar4 != (INICommand *)0x0 && (((u_int)pIVar4[1] & 1) != 0))))
    {
      PHYSOB_StopBurning(instance, pLight);
    }
    else
    {
      *(undefined2 *)(puVar1 + 0xd) = 0;
      PHYSOB_StartBurnFX(instance);
      *puVar1 = *puVar1 | 0x10000;
    }
  }
  instance->flags = instance->flags | 0x10000;
  segment = CheckPhysObAbility(instance, 6);
  if (segment != 0)
  {
    instance->flags2 = instance->flags2 | 0x20000;
  }
  segment = CheckPhysObAbility(instance, 0);
  if (segment != 0)
  {
    instance->flags2 = instance->flags2 | 0x100;
  }
  return;
}

void PhysicalObjectQuery(_Instance *instance, GameTracker *gameTracker)

{
  byte bVar1;
  u_short uVar2;
  _PhysObLight *pLight;
  int NewAnim;
  _Instance *p_Var3;
  u_int uVar4;
  u_long uVar5;
  Level *pLVar6;
  int iVar7;
  u_int uVar8;
  short sVar9;
  void *pvVar10;
  short burnAmplitude;
  u_int *puVar11;
  int iVar12;
  _PCollideInfo _Stack96;
  SVECTOR local_30;
  SVECTOR local_28;

  puVar11 = (u_int *)instance->extraData;
  if (((instance == (gameTracker->gameData).asmData.lightInstances[0].lightInstance) &&
       (pLight = PhysObGetWeapon(instance), pLight != (_PhysObLight *)0x0)) &&
      ((gameTracker->gameData).asmData.lightInstances[0].lightInstance == instance))
  {
    burnAmplitude = 0x1000;
    if (((*puVar11 & 0x8000) != 0) && (burnAmplitude = *(short *)(puVar11 + 0xd), burnAmplitude < 0))
    {
      burnAmplitude = -burnAmplitude;
    }
    PHYSOB_SetLightTable(pLight, (gameTracker->gameData).asmData.lightInstances, burnAmplitude);
  }
  NewAnim = CheckPhysOb(instance, 2);
  if (NewAnim != 0)
  {
    p_Var3 = PHYSOBS_IsAPushBlockAttached(instance);
    if (p_Var3 == (_Instance *)0x0)
    {
      uVar4 = instance->flags2 & 0xffffff7f;
    }
    else
    {
      uVar4 = instance->flags2 | 0x80;
    }
    instance->flags2 = uVar4;
  }
  if (((*puVar11 & 0x2000000) != 0) &&
      (NewAnim = (u_int)(u_short)instance->fadeValue + (gameTrackerX.timeMult >> 5),
       instance->fadeValue = (short)NewAnim, 0xfff < NewAnim * 0x10000 >> 0x10))
  {
    instance->flags = instance->flags | 0x20;
  }
  if ((*puVar11 & 0x8000) != 0)
  {
    uVar2 = *(short *)(puVar11 + 0xd) + 0x88;
    if (*(short *)(puVar11 + 0xd) < 0)
    {
      *(u_short *)(puVar11 + 0xd) = uVar2;
      if (-1 < (int)((u_int)uVar2 << 0x10))
      {
        *(undefined2 *)(puVar11 + 0xd) = 0;
        *puVar11 = *puVar11 & 0xffff7fff;
        if ((*(u_short *)((int)instance->data + 6) & 0x20) != 0)
        {
          pLight = PhysObGetWeapon(instance);
          if ((*puVar11 & 0x40000) == 0)
          {
            PHYSOB_EndLighting(instance, pLight);
          }
          else
          {
            PHYSOB_StopBurning(instance, pLight);
          }
          *puVar11 = *puVar11 & 0xfffbffff;
        }
      }
    }
    else
    {
      *(u_short *)(puVar11 + 0xd) = uVar2;
      if (0xfff < (short)uVar2)
      {
        *(undefined2 *)(puVar11 + 0xd) = 0x1000;
        *puVar11 = *puVar11 & 0xffff7fff;
      }
    }
  }
  NewAnim = CheckPhysObAbility(instance, 5);
  if (NewAnim != 0)
  {
    pvVar10 = instance->extraData;
    if (0 < *(int *)((int)pvVar10 + 4))
    {
      NewAnim = *(int *)((int)pvVar10 + 4) - gameTrackerX.timeMult;
      *(int *)((int)pvVar10 + 4) = NewAnim;
      if (NewAnim < 0)
      {
        *(u_char *)((int)pvVar10 + 4) = 0;
        INSTANCE_NewInstance(instance);
      }
      else
      {
        if (NewAnim < 0x1e000)
        {
 0x1e);
        }
        else
        {
          uVar2 = instance->fadeValue - 0x40;
          if ((instance->fadeValue != 0) &&
              (instance->fadeValue = uVar2, (int)((u_int)uVar2 << 0x10) < 0))
          {
            instance->fadeValue = 0;
          }
        }
      }
    }
  }
  NewAnim = CheckPhysObAbility(instance, 6);
  if ((NewAnim != 0) && ((*(u_short *)((int)instance->data + 8) & 1) != 0))
  {
    uVar5 = INSTANCE_Post(gameTrackerX.playerInstance, 0x24);
    if ((uVar5 & 0x10) == 0)
    {
      uVar4 = instance->flags | 0x800;
    }
    else
    {
      uVar4 = instance->flags & 0xfffff7ff;
    }
    instance->flags = uVar4;
  }
  NewAnim = CheckPhysOb(instance, 0x40);
  if (NewAnim != 0)
  {
    if ((*puVar11 & 0x100000) != 0)
    {
      *(u_short *)((int)instance->extraData + 0x14) =
          *(u_short *)((int)instance->extraData + 0x14) & 0xfff3;
      *puVar11 = *puVar11 & 0xffeff7ff;
    }
    if ((*puVar11 & 0x800) == 0)
    {
      return;
    }
    G2EmulationSwitchAnimation(instance);
    return;
  }
  NewAnim = CheckPhysOb(instance, 0x8000);
  if (NewAnim != 0)
  {
    G2EmulationSwitchAnimation(instance);
  }
  uVar4 = *puVar11;
  if ((uVar4 & 1) == 0)
  {
    if ((uVar4 & 8) != 0)
    {
      ExecuteThrow(instance);
      uVar4 = *puVar11;
    }
    if (((uVar4 & 1) == 0) && ((uVar4 & 0x40) != 0))
    {
      ExecuteDrag(instance);
    }
  }
  if ((*puVar11 & 2) != 0)
  {
    ExecuteSlideToStop(instance);
  }
  if ((*puVar11 & 0x4000) != 0)
  {
    ExecuteGravitate(instance);
  }
  if ((*puVar11 & 0x10) != 0)
  {
    ExecuteThrow(instance);
  }
  if ((*puVar11 & 0x20) != 0)
  {
    ExecuteFlip(instance);
  }
  if (((*puVar11 & 0x100000) != 0) && (NewAnim = CheckPhysObAbility(instance, 5), NewAnim != 0))
  {
    bVar1 = *(byte *)((int)instance->data + 0x10);
    if (bVar1 != 0xff)
    {
      G2EmulationInstanceToInstanceSwitchAnimationCharacter(instance, 0, (u_int)bVar1, 0, 0);
      G2EmulationInstanceInitSection(instance, 0, 2);
    }
    *puVar11 = *puVar11 & 0xffefffff;
  }
  if (((((*puVar11 & 0x10000) != 0) &&
        (pLVar6 = STREAM_GetWaterZLevel(instance->currentStreamUnitID), pLVar6 != (Level *)0x0)) &&
       (instance->matrix != (MATRIX *)0x0)) &&
      (pLight = PhysObGetWeapon(instance),
       instance->matrix[pLight->segment].t[2] < pLVar6->waterZLevel))
  {
    PHYSOB_StopBurning(instance, pLight);
  }
  NewAnim = CheckPhysObAbility(instance, 7);
  if (((NewAnim != 0) && (pvVar10 = instance->extraData, *(int *)((int)pvVar10 + 4) == 8)) &&
      ((pLVar6 = STREAM_GetWaterZLevel(instance->currentStreamUnitID), pLVar6 != (Level *)0x0 &&
                                                                           ((int)(instance->position).z < pLVar6->waterZLevel))))
  {
    NewAnim = (int)*(char *)(*(int *)((int)instance->data + 0xc) + *(int *)((int)pvVar10 + 4) * 0xc + 3);
    if (NewAnim == -1)
    {
      INSTANCE_NewInstance(instance);
    }
    else
    {
      if ((*puVar11 & 0x80000) == 0)
      {
        G2EmulationInstanceToInstanceSwitchAnimationCharacter(instance, 0, NewAnim, 0, 0);
        G2EmulationInstanceInitSection(instance, 0, 1);
        *puVar11 = *puVar11 | 0x81001;
      }
    }
  }
  uVar4 = *puVar11;
  if (((uVar4 & 0x1000) != 0) || (instance->matrix == (MATRIX *)0x0))
  {
    instance->tface = (_TFace *)0x0;
    instance->tfaceLevel = (void *)0x0;
    goto LAB_8006c274;
  }
  NewAnim = (int)(instance->oldPos).z - (int)(instance->position).z;
  if (NewAnim < 0xa0)
  {
    NewAnim = 0xa0;
  }
  iVar12 = instance->zAccl * gameTrackerX.timeMult;
  if (iVar12 < 0)
  {
    iVar12 = iVar12 + 0xfff;
  }
  iVar12 = (instance->zVel + ((iVar12 << 4) >> 0x10)) * gameTrackerX.timeMult;
  if (iVar12 < 0)
  {
    iVar12 = iVar12 + 0xfff;
  }
  iVar12 = 0x40 - (iVar12 >> 0xc);
  burnAmplitude = (short)iVar12;
  iVar7 = iVar12 * 0x10000;
  if (iVar12 * 0x10000 >> 0x10 < 0xa0)
  {
    burnAmplitude = 0xa0;
    iVar7 = 0xa00000;
  }
  sVar9 = (short)((u_int)iVar7 >> 0x10);
  if (iVar7 >> 0x10 < NewAnim)
  {
    sVar9 = (short)NewAnim;
    burnAmplitude = (short)NewAnim;
  }
  NewAnim = SetPhysicsDropOffData((int)sVar9, (int)burnAmplitude, 0, 0, 0, 0xb50);
  uVar8 = PhysicsCheckGravity(instance, NewAnim, 5);
  if ((uVar8 & 1) == 0)
  {
  LAB_8006c040:
    iVar12 = instance->attachedID;
  code_r0x8006c048:
    if ((iVar12 == 0) && (instance->oldMatrix != (MATRIX *)0x0))
    {
      if ((uVar8 & 1) != 0)
      {
        (instance->position).x = (instance->position).x + *(short *)(NewAnim + 4);
        (instance->position).y = (instance->position).y + *(short *)(NewAnim + 6);
      }
      if ((instance->zVel == 0) && ((instance->object->oflags & 0x400U) != 0))
      {
        instance->zVel = -0x32;
      }
      instance->zAccl = -10;
      *puVar11 = *puVar11 | 4;
    }
    else
    {
      instance->zAccl = 0;
      instance->zVel = 0;
    }
  }
  else
  {
    iVar12 = instance->attachedID;
    if ((iVar12 != 0) && ((uVar4 & 4) == 0))
      goto code_r0x8006c048;
    if ((instance->wNormal).z < 0xb51)
      goto LAB_8006c040;
    NewAnim = instance->zVel;
    if ((*puVar11 & 0x14) != 0)
    {
      PHYSOB_PlayDropSound(instance);
    }
    uVar4 = *puVar11;
    *puVar11 = uVar4 & 0xfffffffb;
    if ((uVar4 & 0x400000) == 0)
    {
      *puVar11 = uVar4 & 0xff7ffffb;
    }
    else
    {
      *puVar11 = uVar4 & 0xffbfffeb | 0x200000;
      puVar11[0x11] = 10;
      TurnOffCollisionPhysOb(instance, 7);
    }
    if ((*puVar11 & 0x10) != 0)
    {
      instance->flags2 = instance->flags2 & 0xffffff7f;
    }
    uVar4 = *puVar11;
    *puVar11 = uVar4 & 0xffffffef;
    if ((uVar4 & 0x200000) == 0)
    {
      TurnOnCollisionPhysOb(instance, 4);
    }
    if ((uVar8 & 0x80000) == 0)
    {
      instance->zVel = -1;
    }
    else
    {
      *puVar11 = *puVar11 | 0x1000;
      instance->zAccl = 0;
      instance->zVel = 0;
    }
    if ((instance->oldMatrix != (MATRIX *)0x0) && ((*puVar11 & 0x18000) == 0x10000))
    {
      pLight = PhysObGetWeapon(instance);
      PHYSOB_StopLighting(instance, pLight);
    }
    iVar12 = CheckPhysOb(instance, 8);
    if ((iVar12 != 0) && ((*puVar11 & 0x100) == 0))
    {
      if (NewAnim < -0x32)
      {
        instance->zAccl = 0;
        ResetOrientation(instance);
      }
      *(short *)((int)puVar11 + 0x12) = (instance->position).z;
    }
  }
  if (((((instance->object->oflags & 0x80000U) == 0) &&
        (NewAnim = CheckPhysOb(instance, 8), NewAnim != 0)) &&
       (gameTrackerX.gameData.asmData.MorphType == 0)) &&
      ((gameTrackerX.gameData.asmData.MorphTime != 1000 && ((instance->flags2 & 0x8000000U) == 0))))
  {
    _Stack96.newPoint = &local_28;
    local_30.vx = (instance->position).x;
    local_30.vy = (instance->position).y;
    local_30.vz = (instance->position).z;
    local_28.vz = local_30.vz - 0x500;
    _Stack96.oldPoint = &local_30;
    local_28.vx = local_30.vx;
    local_28.vy = local_30.vy;
    PHYSICS_CheckLineInWorld(instance, &_Stack96);
    instance->zAccl = 0;
    burnAmplitude = (short)((u_int)local_30.vz - (u_int)local_28.vz);
    if (0x3bf < (int)(((u_int)local_30.vz - (u_int)local_28.vz) * 0x10000) >> 0x10)
    {
      uVar2 = (instance->position).z;
      burnAmplitude =
           uVar2 - (*(u_short *)((int)puVar11 + 0x12) +
                   ((short)((u_int)((((int)(((u_int)*(u_short *)((int)puVar11 + 0x12) - (u_int)uVar2) *
 0x280) * 0x10000) >> 0x10) + 1) *
                   -0x280);
    }
    instance->zVel =

                               ((1000 - (int)gameTrackerX.gameData.asmData.MorphTime) * 0x32) <<
 gameTrackerX.timeMult);
  }
LAB_8006c274:
  if ((*puVar11 & 0x200000) != 0)
  {
    puVar11[0x11] = puVar11[0x11] - 1;
    NewAnim = PHYSOB_ReAlignFalling(instance, -900);
    if ((NewAnim != 0) || ((int)puVar11[0x11] < 1))
    {
      *puVar11 = *puVar11 & 0xff5fffff;
      TurnOnCollisionPhysOb(instance, 7);
    }
  }
  if ((((instance->object->oflags & 0x80000U) != 0) ||
       (NewAnim = CheckPhysOb(instance, 8), NewAnim != 0)) ||
      (gameTrackerX.gameData.asmData._8_4_ == 1000))
  {
    PhysicsDefaultLinkedMoveResponse(instance, &instance->position, gameTracker->timeMult);
  }
  return;
}

u_long PhysicalObjectQuery(_Instance *instance, u_long Query)

{
  short sVar1;
  int iVar2;
  INICommand *pIVar3;
  MATRIX *pMVar4;
  MATRIX *pMVar5;
  u_short family;
  void *pvVar6;
  _G2EulerAngles_Type local_18;

  pMVar4 = (MATRIX *)instance->extraData;
  pMVar5 = (MATRIX *)&UNK_00000001;
  switch (Query)
  {
  case 1:
    iVar2 = CheckPhysObFamily(instance);
    if (iVar2 != 0)
    {
      iVar2 = CheckPhysObAbility(instance, 6);
      if (iVar2 == 0)
      {
        return (u_long)(MATRIX *)&DAT_00000020;
      }
      if ((*(u_short *)((int)instance->data + 8) & 1) == 0)
      {
        return (u_long)(MATRIX *)&DAT_00000020;
      }
      if ((instance->flags & 0x800U) != 0)
      {
        return (u_long)(MATRIX *)0x0;
      }
      return (u_long)(MATRIX *)&DAT_00000020;
    }
    goto switchD_8006c380_caseD_8;
  case 2:
    pMVar5 = (MATRIX *)GetPhysicalAbility(instance);
    break;
  case 3:
    pMVar5 = *(MATRIX **)pMVar4->m;
    break;
  case 4:
    pvVar6 = instance->data;
    sVar1 = *(short *)((int)pvVar6 + 2);
    if (sVar1 == 3)
    {
      pMVar5 = (MATRIX *)(int)*(short *)((int)instance->extraData + 6);
    }
    else
    {
      if (sVar1 == 0)
      {
        pMVar5 = (MATRIX *)(int)*(char *)((int)pvVar6 + 0x14);
      }
      else
      {
        if (sVar1 == 2)
        {
          pMVar5 = (MATRIX *)(int)*(short *)((int)pvVar6 + 10);
        }
        else
        {
          pMVar5 = (MATRIX *)((u_int)(sVar1 == 7) << 3);
        }
      }
    }
    break;
  case 5:
    pvVar6 = instance->extraData;
    iVar2 = CheckPhysOb(instance, 0x40);
    pMVar5 = (MATRIX *)0x0;
    if (iVar2 != 0)
    {
      pMVar5 = (MATRIX *)(int)*(short *)((int)pvVar6 + 0x14);
    }
    break;
  case 6:
    pMVar5 = (MATRIX *)
        SetPositionData((int)(instance->position).x, (int)(instance->position).y,
                        (int)(instance->position).z);
    break;
  case 7:
    iVar2 = CheckPhysOb(instance, 0x40);
    if (iVar2 == 0)
    {
      iVar2 = CheckPhysObAbility(instance, 1);
      if (iVar2 == 0)
      {
        pMVar5 = (MATRIX *)
            SetPositionData((int)(instance->rotation).x, (int)(instance->rotation).y,
                            (int)(instance->rotation).z);
      }
      else
      {
        if (instance->matrix == (MATRIX *)0x0)
        {
          local_18.x = 0;
          local_18.y = 0;
          local_18.z = 0;
        }
        else
        {
          G2EulerAngles_FromMatrix(&local_18, (_G2Matrix_Type *)(instance->matrix + 2), 0);
        }
        pMVar5 = (MATRIX *)SetPositionData((int)local_18.x, (int)local_18.y, (int)local_18.z);
      }
    }
    else
    {
      pMVar5 = (MATRIX *)
          SetPositionData(0, 0, (int)(((u_int)(u_short)(instance->rotation).z + (u_int) * (u_short *)((int)instance->extraData + 0x16)) * 0x10000) >> 0x10);
    }
    break;
  default:
    goto switchD_8006c380_caseD_8;
  case 0xb:
    pMVar5 = (MATRIX *)&UNK_00000003;
    break;
  case 0xc:
  case 0xd:
    pMVar5 = instance->matrix;
    break;
  case 0xe:
    iVar2 = CheckPhysObAbility(instance, 5);
    if (iVar2 != 0)
    {
      return (u_long)(instance->matrix + *(u_short *)((int)instance->data + 0x12));
    }
    goto switchD_8006c380_caseD_8;
  case 0x15:
    family = 3;
    goto LAB_8006c5a0;
  case 0x16:
    iVar2 = CheckPhysOb(instance, 0x100);
    if (iVar2 != 0)
    {
      pIVar3 = INSTANCE_FindWithID(instance, 0x13);
      if (pIVar3 == (INICommand *)0x0)
      {
        pvVar6 = instance->data;
      }
      else
      {
        pvVar6 = (void *)((int)instance->data + (int)pIVar3[1] * 0x14);
      }
      pMVar5 = (MATRIX *)
          SetObjectDraftData(*(short *)((int)pvVar6 + 8), *(u_short *)((int)pvVar6 + 10),
                             *(u_short *)((int)pvVar6 + 0xc), *(u_short *)((int)pvVar6 + 0x10),
                             (int)*(short *)((int)pvVar6 + 0xe));
      return (u_long)pMVar5;
    }
  switchD_8006c380_caseD_8:
    pMVar5 = (MATRIX *)0x0;
    break;
  case 0x17:
    iVar2 = CheckPhysOb(instance, 0x40);
    if (iVar2 == 0)
    {
      return (u_long)(MATRIX *)0x0;
    }
    goto LAB_8006c7ac;
  case 0x18:
    pMVar5 = (MATRIX *)CIRC_Alloc(0x10);
    *(u_char *)pMVar5->m = 8;
    *(short **)(pMVar5->m + 2) = pMVar5->m + 4;
    *(u_char *)(pMVar5->m + 4) = *(u_char *)((int)instance->extraData + 0x14);
    if (instance->LinkParent == (_Instance *)0x0)
    {
    LAB_8006c70c:
      pMVar4 = *(MATRIX **)pMVar4->m;
    }
    else
    {
      if (((instance->LinkParent->object->oflags2 & 0x80000U) == 0) ||
          (instance->ParentLinkNode == 3))
      {
        if ((instance->LinkParent != (_Instance *)0x0) &&
            (instance->LinkParent == gameTrackerX.playerInstance))
        {
          *(u_int *)(pMVar5->m + 6) = (u_int) * (MATRIX **)pMVar4->m & 0xffffef6f | 0x400004;
          return (u_long)pMVar5;
        }
        goto LAB_8006c70c;
      }
      pMVar4 = (MATRIX *)((u_int) * (MATRIX **)pMVar4->m | 0x2000000);
    }
    *(MATRIX **)(pMVar5->m + 6) = pMVar4;
    break;
  case 0x1a:
    goto switchD_8006c380_caseD_1a;
  case 0x1b:
    pMVar5 = (MATRIX *)0x0;
    goto switchD_8006c380_caseD_1a;
  case 0x1c:
    iVar2 = CheckPhysOb(instance, 0x40);
    goto joined_r0x8006c5d0;
  case 0x1d:
    family = 5;
  LAB_8006c5a0:
    iVar2 = CheckPhysObAbility(instance, family);
  joined_r0x8006c5d0:
    pMVar5 = (MATRIX *)0x0;
    if (iVar2 != 0)
    {
    LAB_8006c7ac:
      pMVar5 = (MATRIX *)instance->data;
    }
  }
  return (u_long)pMVar5;
switchD_8006c380_caseD_1a:
  iVar2 = CheckPhysObAbility(instance, 2);
  if (iVar2 != 0)
  {
    if ((*(u_short *)((int)instance->extraData + 0x14) & 2) != 0)
    {
      return (u_long)pMVar5;
    }
    return (u_long)(MATRIX *)((u_int)pMVar5 ^ 1);
  }
  if (*(short *)((int)instance->data + 10) != 0)
  {
    return (u_long)pMVar5;
  }
  if ((*(u_int *)instance->extraData & 0x2000) == 0)
  {
    return (u_long)pMVar5;
  }
  return (u_long)(MATRIX *)((u_int)pMVar5 ^ 1);
}

void CollidePhysicalObject(_Instance *instance, u_long Message, u_long Data)

{
  u_int *puVar1;
  u_int uVar2;
  int Mode;
  _PhysObLight *pLight;
  u_int uVar3;
  u_int *puVar4;
  void *pvVar5;

  puVar4 = (u_int *)instance->extraData;
  if (Message == 0x800010)
  {
    ThrowPhysOb(instance, (evObjectThrowData *)Data);
    return;
  }
  if (Message < 0x800011)
  {
    if (Message == 0x200005)
    {
      uVar2 = *puVar4;
      uVar3 = 0x1000000;
    LAB_8006ce38:
      uVar2 = uVar2 | uVar3;
    LAB_8006ce3c:
      *puVar4 = uVar2;
      return;
    }
    if (Message < 0x200006)
    {
      if ((undefined *)Message == &DAT_00100007)
      {
        puVar1 = *(u_int **)(Data + 4);
        puVar4[5] = *puVar1;
        uVar2 = puVar1[1];
        *puVar4 = uVar2 & 0xffeff7ff;
        if ((uVar2 & 0x2000000) != 0)
        {
          instance->flags = instance->flags | 0x20;
        }
        Mode = CheckPhysOb(instance, 0x20);
        if (Mode == 0)
        {
          return;
        }
        pLight = PhysObGetWeapon(instance);
        if ((*puVar4 & 0x10000) != 0)
        {
          return;
        }
        PHYSOB_StopBurning(instance, pLight);
        return;
      }
      if (Message <= &DAT_00100007)
      {
        if (Message == 0x40002)
        {
          ScriptKillInstance(instance, Data);
          return;
        }
        if (Message != 0x80005)
        {
          return;
        }
        ScriptKillInstance(instance, 5);
        return;
      }
      if (Message == 0x200002)
      {
        TurnOffCollisionPhysOb(instance, Data);
        return;
      }
      if (0x200002 < Message)
      {
        if (Message != 0x200003)
        {
          return;
        }
        TurnOnCollisionPhysOb(instance, Data);
        return;
      }
      if ((undefined *)Message != &DAT_00100008)
      {
        return;
      }
      if (puVar4 == (u_int *)0x0)
      {
        return;
      }
      *(short *)((int)puVar4 + 0xe) = *(short *)((int)puVar4 + 0xe) + *(short *)Data;
      *(short *)(puVar4 + 4) = *(short *)(puVar4 + 4) + *(short *)(Data + 2);
      *(short *)((int)puVar4 + 0x12) = *(short *)((int)puVar4 + 0x12) + *(short *)(Data + 4);
      return;
    }
    if (Message == 0x800001)
    {
      Mode = STREAM_IsMonster();
      if ((Mode == 0) && (gameTrackerX.gameData.asmData.MorphType != 0))
      {
        return;
      }
      Mode = PickUpPhysOb(instance, *(short *)Data, *(short *)(Data + 2), *(_Instance **)(Data + 8));
      *(int *)(Data + 0xc) = Mode;
      return;
    }
    if (0x800001 < Message)
    {
      if (Message == 0x800004)
      {
        DropPhysOb(instance);
        return;
      }
      if (Message < 0x800005)
      {
        if (Message != 0x800002)
        {
          return;
        }
        Mode = STREAM_IsMonster();
        if (((Mode == 0) && (gameTrackerX.gameData.asmData.MorphType != 0)) &&
            (*(short *)(Data + 4) != 0))
        {
          return;
        }
        Mode = StopPhysOb(instance, *(short *)(Data + 4), *(_Instance **)(Data + 8),
                          (int)*(short *)(Data + 6));
        *(undefined2 *)(Data + 6) = (short)Mode;
        if (*(short *)(Data + 4) != 0)
        {
          return;
        }
        if ((*puVar4 & 0x4000) == 0)
        {
          return;
        }
        ExecuteGravitate(instance);
        return;
      }
      if (Message != 0x800008)
      {
        return;
      }
      FlipPhysOb(instance, Data);
      if ((Data & 1) == 0)
      {
        return;
      }
      uVar2 = *puVar4 | 0x2000000;
      goto LAB_8006ce3c;
    }
    if (Message != 0x200006)
    {
      if (Message != 0x800000)
      {
        return;
      }
      Mode = STREAM_IsMonster();
      if ((Mode == 0) && (gameTrackerX.gameData.asmData.MorphType != 0))
      {
        return;
      }
      Mode = PushPhysOb(instance, *(short *)Data, *(short *)(Data + 2), *(short *)(Data + 4),
                        *(_Instance **)(Data + 8));
      *(int *)(Data + 0xc) = Mode;
      return;
    }
    uVar2 = 0xfeff0000;
  LAB_8006ce48:
    uVar2 = *puVar4 & (uVar2 | 0xffff);
  LAB_8006ce54:
    *puVar4 = uVar2;
    return;
  }
  if (Message == 0x800027)
  {
    if (Data == 0)
    {
      *puVar4 = *puVar4 | 0x1000;
      return;
    }
    uVar2 = *puVar4 & 0xffffefff;
    goto LAB_8006ce54;
  }
  if (0x800027 < Message)
  {
    if (Message == 0x80002b)
    {
      uVar2 = 0xff7f0000;
      goto LAB_8006ce48;
    }
    if (Message < 0x80002c)
    {
      if (Message != 0x800029)
      {
        if (Message != 0x80002a)
        {
          return;
        }
        Mode = CheckPhysObAbility(instance, 2);
        if (Mode == 0)
        {
          return;
        }
        *(undefined2 *)((int)instance->extraData + 0x14) = (short)Data;
        return;
      }
      pLight = PhysObGetWeapon(instance);
      if (pLight == (_PhysObLight *)0x0)
      {
        return;
      }
      if (Data == 1)
      {
        PHYSOB_StartBurning(instance, pLight);
        return;
      }
      if (Data == 0)
      {
        PHYSOB_StartLighting(instance, pLight);
        return;
      }
      if (Data != 2)
      {
        return;
      }
      puVar4 = (u_int *)instance->extraData;
      *(undefined2 *)(puVar4 + 0xd) = 0;
      *puVar4 = *puVar4 & 0xffff7fff;
      PHYSOB_StopBurning(instance, pLight);
      return;
    }
    if (Message == 0x80002d)
    {
      ResetSwitchPhysOb(instance);
      return;
    }
    if (Message < 0x80002d)
    {
      uVar2 = *puVar4;
      uVar3 = 0x800000;
      goto LAB_8006ce38;
    }
    if (Message != 0x8000008)
    {
      return;
    }
    G2EmulationInstanceToInstanceSwitchAnimationCharacter(instance, 0, *(int *)(Data + 4), *(int *)(Data + 8), *(int *)(Data + 0xc));
    Mode = *(int *)(Data + 0x10);
    goto LAB_8006cf40;
  }
  if (Message < 0x800023)
  {
    if (Message < 0x800021)
    {
      if (Message != 0x800020)
      {
        return;
      }
      SwitchPhysOb(instance);
      return;
    }
    Mode = CheckPhysObFamily(instance);
    if (Mode == 0)
    {
      return;
    }
    pvVar5 = instance->data;
    Mode = CheckPhysObAbility(instance, 2);
    if (Mode != 0)
    {
      pvVar5 = instance->extraData;
      if (Message == 0x800021)
      {
        *(u_short *)((int)pvVar5 + 0x14) = *(u_short *)((int)pvVar5 + 0x14) | 2;
        return;
      }
      *(u_short *)((int)pvVar5 + 0x14) = *(u_short *)((int)pvVar5 + 0x14) & 0xfffd;
      return;
    }
    if (*(short *)((int)pvVar5 + 10) != 0)
    {
      return;
    }
    puVar4 = (u_int *)instance->extraData;
    if (Message == 0x800021)
    {
      *puVar4 = *puVar4 & 0xffffdfff;
      return;
    }
    *puVar4 = *puVar4 | 0x2000;
    return;
  }
  if (Message == 0x800025)
  {
    return;
  }
  if (Message < 0x800026)
  {
    if (Message != 0x800023)
    {
      return;
    }
    Mode = STREAM_IsMonster();
    if ((Mode == 0) && (gameTrackerX.gameData.asmData.MorphType != 0))
    {
      return;
    }
    InteractPhysOb(instance, *(_Instance **)Data, (u_int) * (u_short *)(Data + 4),
                   (u_int) * (u_short *)(Data + 0xe));
    return;
  }
  pvVar5 = instance->data;
  switch ((int)(((u_int) * (u_short *)((int)pvVar5 + 8) - 1) * 0x10000) >> 0x10)
  {
  case 0:
    HEALTHU_Pickup(instance);
    break;
  case 1:
  case 4:
    MANNA_Pickup();
  case 2:
  case 3:
    INSTANCE_PlainDeath(instance);
    break;
  case 6:
    MANNA_Pickup();
  case 5:
    if ((*(char *)((int)pvVar5 + 0x11) != -1) &&
        (uVar2 = G2EmulationInstanceSetMode(instance, 0), uVar2 != (u_int) * (byte *)((int)pvVar5 + 0x11)))
    {
      printf("Collect %s\n");
      G2EmulationInstanceToInstanceSwitchAnimationCharacter(instance, 0, (u_int) * (byte *)((int)pvVar5 + 0x11), 0, 0);
      Mode = 1;
    LAB_8006cf40:
      G2EmulationInstanceInitSection(instance, 0, Mode);
    }
  }
  return;
}

long PhysobAnimCallback(_G2Anim_Type *anim, int sectionID, _G2AnimCallbackMsg_Enum message,
                        long messageDataA, long messageDataB, void *data)

{
  u_int uVar1;
  u_int *puVar2;

  if (message == G2ANIM_MSG_DONE)
  {
    puVar2 = *(u_int **)((int)data + 0x168);
    G2AnimSection_SetNotRewinding(anim->section + sectionID);
    uVar1 = *puVar2;
    *puVar2 = uVar1 | 0x100000;
    if ((uVar1 & 0x80000) != 0)
    {
      INSTANCE_NewInstance((_Instance *)data);
    }
  }
  else
  {
    messageDataA = INSTANCE_DefaultAnimCallback(anim, sectionID, message, messageDataA, messageDataB, (_Instance *)data);
  }
  return messageDataA;
}

void InitPhysicalObject(_Instance *instance, GameTracker *gameTracker)

{
  short sVar1;
  u_short uVar2;
  u_short uVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int Data;
  Level *pLVar7;
  long lVar8;
  _CollideInfo *p_Var9;
  PhysObSplinter *pPVar10;
  u_long uVar11;
  int iVar12;
  void **ppvVar13;
  FXSplinter *splintDef;
  u_int uVar14;
  void *pvVar15;
  void *pvVar16;
  SVECTOR *nrml;
  void *pvVar17;
  _CollideInfo *collideInfo;
  u_int *puVar18;
  _Instance *instance_00;
  void *pvVar19;
  short local_78;
  short local_76;
  SVECTOR SStack112;
  short local_68;
  short sStack102;
  short local_64;
  _PCollideInfo local_60;
  SVECTOR local_30;

  bVar6 = false;
  instance_00 = (_Instance *)0x0;
  pvVar19 = (void *)0x0;
  bVar5 = true;
  collideInfo = (_CollideInfo *)instance->collideInfo;
  puVar18 = (u_int *)instance->extraData;
  nrml = &collideInfo->point0;
  Data = CheckPhysObAbility(instance, 7);
  if ((((Data == 0) || (*(int *)((int)instance->extraData + 4) != 8)) ||
       (pLVar7 = STREAM_GetWaterZLevel(instance->currentStreamUnitID), pLVar7 == (Level *)0x0)) ||
      (pLVar7->waterZLevel <= (int)(instance->position).z))
  {
    if (collideInfo->type1 == '\x03')
    {
      pvVar16 = collideInfo->inst1;
      pLVar7 = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
      pvVar19 = collideInfo->prim1;
      if (((*(u_short *)((int)pvVar16 + 0x12) & 1) != 0) || ((*(byte *)((int)pvVar19 + 6) & 4) != 0))
      {
        bVar5 = false;
      }
      nrml = &SStack112;
      COLLIDE_GetNormal(*(short *)((int)pvVar19 + 8), (short *)pLVar7->terrain->normalList,
                        (_SVector *)nrml);
    }
    else
    {
      instance_00 = (_Instance *)collideInfo->inst1;
    }
    GetCollisionType(instance);
    if ((*puVar18 & 0x4000) != 0)
    {
      if ((_Instance *)puVar18[2] == instance_00)
      {
        return;
      }
      if (instance_00 != (_Instance *)0x0)
      {
        if ((*(u_int *)&collideInfo->flags & 0xffff0000) == 0x1010000)
        {
          return;
        }
        if ((instance_00->object->oflags2 & 0x40000U) != 0)
        {
          return;
        }
      }
      if (pvVar19 != (void *)0x0)
      {
        if (*(u_short *)((int)pvVar19 + 10) == 0xffff)
        {
          return;
        }
        if ((*(u_short *)(*(int *)(*(int *)collideInfo->level + 0x34) + (u_int) * (u_short *)((int)pvVar19 + 10) +
                          10) &
             0x1000) == 0)
        {
          return;
        }
      }
      *puVar18 = *puVar18 & 0xffffbfff | 0x10;
      puVar18[0x11] = 0x96000;
      local_68 = (instance->oldPos).x - (instance->position).x;
      sStack102 = (instance->oldPos).y - (instance->position).y;
      local_64 = (instance->oldPos).z - (instance->position).z;
      (instance->position).x = (instance->position).x + local_68;
      (instance->position).y = (instance->position).y + sStack102;
      (instance->position).z = (instance->position).z + local_64;
      COLLIDE_MoveAllTransforms(instance, (SVECTOR *)&local_68);
    }
    uVar14 = *puVar18;
    if ((uVar14 & 0x10) == 0)
    {
      if ((uVar14 & 0x200004) == 0)
      {
        if (((uVar14 & 0x80) != 0) &&
            (ppvVar13 = (void **)&local_68, instance->LinkParent != (_Instance *)0x0))
        {
          p_Var9 = collideInfo;
          do
          {
            pvVar16 = *(void **)&p_Var9->flags;
            pvVar17 = p_Var9->prim0;
            pvVar15 = p_Var9->prim1;
            *ppvVar13 = p_Var9->level;
            ppvVar13[1] = pvVar16;
            ppvVar13[2] = pvVar17;
            ppvVar13[3] = pvVar15;
            p_Var9 = (_CollideInfo *)&p_Var9->inst0;
            ppvVar13 = ppvVar13 + 4;
          } while (p_Var9 != collideInfo + 1);
          local_60.inst = instance->LinkParent;
          Data = SetCollideInfoData((_CollideInfo *)&local_68);
          INSTANCE_Query(instance->LinkParent, 0x200004, Data);
        }
      }
      else
      {
        if ((collideInfo->type1 == '\x01') && ((_Instance *)puVar18[0x10] == instance_00))
        {
          return;
        }
        if (nrml->vz < 0xb50)
        {
          return;
        }
        if ((uVar14 & 0x200000) != 0)
        {
          (collideInfo->offset).z = 0;
        }
        (instance->position).x = (instance->position).x + (collideInfo->offset).x;
        (instance->position).y = (instance->position).y + (collideInfo->offset).y;
        (instance->position).z = (instance->position).z + (collideInfo->offset).z;
        COLLIDE_MoveAllTransforms(instance, (SVECTOR *)&collideInfo->offset);
      }
    }
    else
    {
      if (instance_00 == (_Instance *)puVar18[0x10])
      {
        return;
      }
      Data = CheckPhysObAbility(instance, 7);
      if ((((Data != 0) && (pvVar19 != (void *)0x0)) && (*(u_short *)((int)pvVar19 + 10) != 0xffff)) && ((*(u_short *)(*(int *)(*(int *)collideInfo->level + 0x34) + (u_int) * (u_short *)((int)pvVar19 + 10) +
                                                                                                                       10) &
                                                                                                          0x1000) != 0))
      {
        return;
      }
      sVar1 = *(short *)&instance->xVel;
      uVar2 = *(u_short *)&instance->yVel;
      uVar3 = *(u_short *)&instance->zVel;
      if ((sVar1 == 0) && (uVar2 == 0))
      {
        local_76 = 0;
        local_78 = 0;
      }
      else
      {
        Data = instance->xVel;
        iVar12 = instance->yVel;
        if (Data < 0)
        {
          Data = -Data;
        }
        if (iVar12 < 0)
        {
          iVar12 = -iVar12;
        }
        if (iVar12 < Data)
        {
          if (instance->xVel < 1)
          {
            local_78 = -0x1000;
          }
          else
          {
            local_78 = 0x1000;
          }
          local_76 = 0;
          bVar4 = iVar12<Data>> 1;
        }
        else
        {
          local_76 = 0x1000;
          if (instance->yVel < 1)
          {
            local_76 = -0x1000;
          }
          local_78 = 0;
          bVar4 = Data<iVar12>> 1;
        }
        if (!bVar4)
        {
          bVar6 = true;
        }
      }
      if ((*puVar18 & 0x400000) == 0)
      {
        instance->xVel = 0;
        instance->yVel = 0;
        instance->zVel = 0;
        instance->xAccl = 0;
        instance->yAccl = 0;
        instance->zAccl = 0;
      }
      (instance->position).x = (instance->position).x + (collideInfo->offset).x;
      (instance->position).y = (instance->position).y + (collideInfo->offset).y;
      (instance->position).z = (instance->position).z + (collideInfo->offset).z;
      COLLIDE_MoveAllTransforms(instance, (SVECTOR *)&collideInfo->offset);
      if ((((int)sVar1 != 0) || ((uVar2 | uVar3) != 0)) &&
          (lVar8 = MATH3D_LengthXY((int)sVar1, (int)(short)uVar2, (int)(short)uVar3),
           100 < (short)lVar8))
      {
        instance->flags2 = instance->flags2 | 0x2000;
      }
      bVar4 = false;
      Data = CheckPhysOb(instance, 0x200);
      if ((Data != 0) && ((sVar1 != 0 || ((uVar2 | uVar3) != 0))))
      {
        local_30.vx = (instance->position).x + sVar1 * 4;
        local_30.vy = (instance->position).y + uVar2 * 4;
        local_60.oldPoint = (SVECTOR *)&instance->position;
        local_60.newPoint = &local_30;
        local_30.vz = (instance->position).z + uVar3 * 4;
        PHYSICS_CheckLineInWorld(instance, &local_60);
        bVar4 = local_60.type != 0;
      }
      if ((((bVar4) && (bVar5)) && (instance_00 == (_Instance *)0x0)) && (nrml->vz < 0xb50))
      {
        *puVar18 = *puVar18 | 0x1000;
        instance->flags2 = instance->flags2 & 0xffffff7f;
        *puVar18 = *puVar18 & 0xffffffef;
        TurnOnCollisionPhysOb(instance, 4);
      }
      else
      {
        *puVar18 = *puVar18 & 0xffffefff | 0x400000;
        if ((sVar1 != 0) || (uVar2 != 0))
        {
          memset((SVECTOR *)&local_68, 0, 6);
          local_68 = -sVar1;
          sStack102 = -uVar2;
          local_64 = -uVar3;
          (instance->position).x = (instance->position).x + local_68;
          (instance->position).y = (instance->position).y + sStack102;
          (instance->position).z = (instance->position).z + local_64;
          COLLIDE_MoveAllTransforms(instance, (SVECTOR *)&local_68);
        }
        if (((short)uVar3 < 0) &&
            (lVar8 = MATH3D_LengthXY((int)(collideInfo->offset).x, (int)(collideInfo->offset).y,
                                     (int)(collideInfo->offset).z),
             (int)(collideInfo->offset).z<(int)(short)lVar8 * 0xb500>> 0x10))
        {
          instance->zVel = (int)(short)uVar3;
        }
        FlipPhysOb(instance, 0);
      }
    }
    Data = CheckPhysOb(instance, 0x1000);
    if (((Data != 0) && ((*puVar18 & 0x800000) == 0)) &&
        (gameTrackerX.gameData.asmData._8_4_ == 1000))
    {
      pPVar10 = PhysObGetSplinter(instance);
      splintDef = (FXSplinter *)0x0;
      if (pPVar10 != (PhysObSplinter *)0x0)
      {
        splintDef = (FXSplinter *)pPVar10->splinterData;
      }
      _FX_BuildNonSegmentedSplinters(instance, (SVECTOR *)0x0, (SVECTOR *)0x0, (SVECTOR *)0x0, splintDef, gFXT,
                                     (TDRFuncPtr__FX_BuildSplinters6fxSetup)0x0,
                                     (TDRFuncPtr__FX_BuildSplinters7fxProcess)0x0, 0);
      INSTANCE_PlainDeath(instance);
    }
    Data = CheckPhysObAbility(instance, 7);
    bVar5 = true;
    if (Data != 0)
    {
      pvVar17 = instance->data;
      pvVar16 = instance->extraData;
      COLLIDE_SegmentCollisionOn(instance, 0);
      Data = *(int *)((int)pvVar17 + 0xc) + *(int *)((int)pvVar16 + 4) * 0xc;
      if (*(char *)(Data + 3) != -1)
      {
        *puVar18 = *puVar18 & 0xffbffffb | 0x1001;
        instance->xVel = 0;
        instance->yVel = 0;
        instance->zVel = 0;
        instance->xAccl = 0;
        instance->yAccl = 0;
        instance->zAccl = 0;
        if ((*puVar18 & 0x80000) != 0)
        {
          return;
        }
        bVar5 = false;
        G2EmulationInstanceToInstanceSwitchAnimationCharacter(instance, 0, (int)*(char *)(Data + 3), 0, 0);
        G2EmulationInstanceInitSection(instance, 0, 1);
        *puVar18 = *puVar18 | 0x81001;
      }
      if ((instance->parent != (_Instance *)0x0) &&
          (uVar11 = INSTANCE_Post(instance->parent, 1), (uVar11 & 1) != 0))
      {
        if ((pvVar19 == (void *)0x0) || (gameTrackerX.gameData.asmData.MorphType != 0))
        {
          if ((instance_00 != gameTrackerX.playerInstance) &&
              (gameTrackerX.gameData.asmData.MorphType == 0))
          {
            Data = CheckPhysObFamily(instance_00);
            if ((Data != 0) && (!bVar6))
            {
              Data = SetObjectBreakOffData((int)local_78, (int)local_76, 6, (_Instance *)0x0, 0);
              INSTANCE_Query(instance_00, 0x800000, Data);
            }
            if (*(int *)((int)pvVar16 + 4) == 1)
            {
              instance_00->flags2 = instance_00->flags2 | 0x10000;
            }
            else
            {
              instance_00->flags = instance_00->flags | 0x80000000;
            }
          }
        }
        else
        {
          COLLIDE_GetBSPTreeFlag(collideInfo, 0x400);
        }
      }
      if (bVar5)
      {
        INSTANCE_NewInstance(instance);
      }
    }
  }
  return;
}

PhysObWeaponAttributes *PhysObGetLight(_Instance *instance)

{
  int iVar1;
  PhysObWeaponAttributes *pPVar2;

  pPVar2 = (PhysObWeaponAttributes *)0x0;
  iVar1 = CheckPhysObAbility(instance, 0);
  if (iVar1 != 0)
  {
    pPVar2 = (PhysObWeaponAttributes *)((int)instance->data + 8);
  }
  iVar1 = CheckPhysObAbility(instance, 3);
  if (iVar1 != 0)
  {
    pPVar2 = *(PhysObWeaponAttributes **)((int)instance->data + 0x28);
  }
  iVar1 = CheckPhysObAbility(instance, 7);
  if (iVar1 != 0)
  {
    pPVar2 = *(PhysObWeaponAttributes **)(*(int *)((int)instance->extraData + 4) * 0xc + *(int *)((int)instance->data + 0xc) +
                                          8);
  }
  return pPVar2;
}

_PhysObLight *PhysObGetWeapon(_Instance *instance)

{
  PhysObWeaponAttributes *pPVar1;
  _PhysObLight *p_Var2;

  p_Var2 = (_PhysObLight *)0x0;
  pPVar1 = PhysObGetLight(instance);
  if (pPVar1 != (PhysObWeaponAttributes *)0x0)
  {
    p_Var2 = pPVar1->Light;
  }
  return p_Var2;
}

PhysObSplinter *PhysObGetSplinter(_Instance *instance)

{
  PhysObWeaponAttributes *pPVar1;
  PhysObSplinter *pPVar2;

  pPVar2 = (PhysObSplinter *)0x0;
  pPVar1 = PhysObGetLight(instance);
  if (pPVar1 != (PhysObWeaponAttributes *)0x0)
  {
    pPVar2 = &pPVar1->splinter;
  }
  return pPVar2;
}

void TurnOffCollisionPhysOb(_Instance *instance, int coll)

{
  PhysObWeaponAttributes *pPVar1;

  *(u_int *)instance->extraData = *(u_int *)instance->extraData & 0xfeffffff;
  pPVar1 = PhysObGetLight(instance);
  if (pPVar1 != (PhysObWeaponAttributes *)0x0)
  {
    if ((coll & 2U) != 0)
    {
      COLLIDE_SegmentCollisionOff(instance, (int)pPVar1->LeftHandSphere);
    }
    if ((coll & 1U) != 0)
    {
      COLLIDE_SegmentCollisionOff(instance, (int)pPVar1->RightHandSphere);
    }
    if ((coll & 4U) != 0)
    {
      COLLIDE_SegmentCollisionOff(instance, (int)pPVar1->ThrowSphere);
    }
  }
  return;
}

void TurnOnCollisionPhysOb(_Instance *instance, int coll)

{
  PhysObWeaponAttributes *pPVar1;

  pPVar1 = PhysObGetLight(instance);
  if (pPVar1 != (PhysObWeaponAttributes *)0x0)
  {
    if ((coll & 2U) != 0)
    {
      COLLIDE_SegmentCollisionOn(instance, (int)pPVar1->LeftHandSphere);
    }
    if ((coll & 1U) != 0)
    {
      COLLIDE_SegmentCollisionOn(instance, (int)pPVar1->RightHandSphere);
    }
    if ((coll & 4U) != 0)
    {
      COLLIDE_SegmentCollisionOn(instance, (int)pPVar1->ThrowSphere);
    }
  }
  return;
}

int GetCollisionType(_Instance *instance)

{
  PhysObWeaponAttributes *pPVar1;
  u_long uVar2;
  int Data;
  _Instance *Inst;
  int Power;
  _Instance *Sender;
  void *pvVar3;
  u_int *puVar4;
  void *pvVar5;

  puVar4 = (u_int *)instance->extraData;
  pvVar5 = instance->collideInfo;
  if ((*puVar4 & 0x1600001) != 0)
  {
    return 0;
  }
  if ((*(u_int *)((int)pvVar5 + 4) & 0xffff0000) != 0x1010000)
  {
    return 0;
  }
  if (*(char *)(*(int *)((int)pvVar5 + 8) + 4) != '\t')
  {
    return 0;
  }
  if (*(char *)(*(int *)((int)pvVar5 + 0xc) + 4) != '\b')
  {
    return 0;
  }
  Sender = *(_Instance **)((int)pvVar5 + 0x14);
  pPVar1 = PhysObGetLight(instance);
  if (pPVar1 == (PhysObWeaponAttributes *)0x0)
  {
    return 0;
  }
  pvVar3 = instance->data;
  TurnOnCollisionPhysOb(instance, 7);
  if (instance->LinkParent == (_Instance *)0x0)
  {
    uVar2 = INSTANCE_Post(Sender, 0);
    if ((uVar2 & 0x10000000) == 0)
    {
    LAB_8006dda8:
      Data = SetMonsterImpaleData(instance, (_Instance *)0x0, pPVar1->Damage, (int)pPVar1->knockBackDistance,
                                  (int)pPVar1->knockBackFrames);
      Power = 0x1000000;
      Inst = Sender;
    LAB_8006ddd0:
      INSTANCE_Query(Inst, Power, Data);
    }
    else
    {
      if ((*(u_short *)((int)pvVar3 + 6) & 0x200) == 0)
      {
        Data = CheckPhysOb(instance, 0x20);
        if ((Data == 0) || ((*puVar4 & 0x10000) == 0))
          goto LAB_8006dda8;
        INSTANCE_Query(Sender, 0x100000c, 0x20);
        Power = 0x800029;
        Data = 0;
        Inst = instance;
        goto LAB_8006ddd0;
      }
      INSTANCE_Query(Sender, 0x1000019, (int)instance);
      *puVar4 = *puVar4 & 0xffffffef;
    }
    Data = CheckPhysObAbility(instance, 7);
    if ((Data == 0) || (instance->parent != gameTrackerX.playerInstance))
      goto LAB_8006de70;
    Power = 0x80001;
    Data = 0;
    Inst = Sender;
  }
  else
  {
    Power = pPVar1->Damage;
    Data = CheckPhysOb(instance, 0x20);
    if ((Data != 0) && ((*puVar4 & 0x10000) == 0))
    {
      Power = pPVar1->AltDamage;
    }
    Data = SetMonsterImpaleData(Sender, (_Instance *)0x0, Power, 0, 0);
    Power = 0x2000002;
    Inst = instance->LinkParent;
  }
  INSTANCE_Query(Inst, Power, Data);
LAB_8006de70:
  Data = CheckPhysOb(instance, 0x20);
  if ((Data == 0) || ((*puVar4 & 0x10000) == 0))
  {
    Data = 0x100;
  }
  else
  {
    Data = 0x20;
  }
  Data = SetFXHitData(instance, (u_int) * (byte *)((int)pvVar5 + 5), pPVar1->Damage >> 7, Data);
  INSTANCE_Query(Sender, 0x400000, Data);
  return 1;
}

void ExecuteThrow(_Instance *instance)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  void *pvVar5;
  _Position _Stack32;
  _Position local_18;

  pvVar5 = instance->extraData;
  if ((*(u_short *)((int)pvVar5 + 0x36) & 1) == 0)
  {
    (instance->rotation).x = (instance->rotation).x + *(short *)((int)pvVar5 + 0x3a);
    (instance->rotation).y = (instance->rotation).y + *(short *)((int)pvVar5 + 0x3c);
    (instance->rotation).z = (instance->rotation).z + *(short *)((int)pvVar5 + 0x3e);
  }
  else
  {
    memset(&_Stack32, 0, 6);
    local_18.x = *(short *)&instance->xVel;
    local_18.y = *(short *)&instance->yVel;
    local_18.z = *(short *)&instance->zVel;
    sVar2 = MATH3D_AngleFromPosToPos(&_Stack32, &local_18);
    sVar3 = MATH3D_ElevationFromPosToPos(&_Stack32, &local_18);
    sVar1 = *(short *)((int)pvVar5 + 0x38);
    (instance->rotation).z = sVar2;
    (instance->rotation).y = 0;
    (instance->rotation).x = sVar1 + sVar3;
    MATH3D_ZYXtoXYZ(&instance->rotation);
  }
  iVar4 = *(int *)((int)pvVar5 + 0x44) - gameTrackerX.timeMult;
  *(int *)((int)pvVar5 + 0x44) = iVar4;
  if (iVar4 < 0)
  {
    INSTANCE_NewInstance(instance);
  }
  return;
}

void ExecuteDrag(_Instance *instance)

{
  short sVar1;
  u_int *puVar2;

  puVar2 = (u_int *)instance->extraData;
  if ((*puVar2 & 2) != 0)
  {
    *puVar2 = *puVar2 & 0xfffffffd;
  }
  if ((*puVar2 & 0x100000) == 0)
  {
    G2EmulationSwitchAnimation(instance);
  }
  else
  {
    puVar2[2] = 0;
    FinishPush(instance);
    *puVar2 = *puVar2 & 0xffeffeb5 | 1;
    sVar1 = (instance->position).z;
    *(u_char *)&instance->initialPos = *(u_char *)&instance->position;
    (instance->initialPos).z = sVar1;
  }
  return;
}

void ExecuteSlideToStop(_Instance *instance)

{
  short sVar1;
  u_int *puVar2;

  puVar2 = (u_int *)instance->extraData;
  if ((*puVar2 & 0x100000) == 0)
  {
    G2EmulationSwitchAnimation(instance);
  }
  else
  {
    puVar2[2] = 0;
    FinishPush(instance);
    *puVar2 = *puVar2 & 0xffefeeb5 | 1;
    sVar1 = (instance->position).z;
    *(u_char *)&instance->initialPos = *(u_char *)&instance->position;
    (instance->initialPos).z = sVar1;
  }
  return;
}

void ExecuteThrow(_Instance *instance)

{
  short sVar1;
  u_int *puVar2;

  puVar2 = (u_int *)instance->extraData;
  if ((*puVar2 & 2) != 0)
  {
    *puVar2 = *puVar2 & 0xfffffffd;
  }
  if ((*puVar2 & 0x100000) == 0)
  {
    G2EmulationSwitchAnimation(instance);
  }
  else
  {
    if (*(short *)(puVar2 + 10) == 0xe)
    {
      instance->zVel = -0x32;
    }
    ResetOrientation(instance);
    puVar2[2] = 0;
    *puVar2 = *puVar2 & 0xffefeeb5 | 1;
    sVar1 = (instance->position).z;
    *(u_char *)&instance->initialPos = *(u_char *)&instance->position;
    (instance->initialPos).z = sVar1;
  }
  return;
}

int CheckSlope(int Znormal, int Slope, int Slop)

{
  u_int uVar1;

  uVar1 = 0;
  if (Slope - Slop < Znormal)
  {
    uVar1 = (u_int)(Znormal < Slope + Slop);
  }
  return uVar1;
}

int CheckBlockSlope(_Instance *instance, int x, int y, int hOff, int vOff, int dH, int dV)

{
  MATRIX *pMVar1;
  _PCollideInfo local_48;
  SVECTOR local_18;
  SVECTOR local_10;

  local_48.oldPoint = &local_18;
  local_48.newPoint = &local_10;
  pMVar1 = instance->matrix;
  local_18.vx = *(short *)pMVar1->t + (short)x * (short)hOff;
  local_18.vy = *(short *)(pMVar1->t + 1) + (short)y * (short)hOff;
  local_18.vz = *(short *)(pMVar1->t + 2) + (short)vOff;
  local_10.vz = local_18.vz + (short)dV;
  local_10.vx = local_18.vx + (short)x * (short)dH;
  local_10.vy = local_18.vy + (short)y * (short)dH;
  PHYSICS_CheckLineInWorld(instance, &local_48);
  return (u_int)(local_48.type == 5);
}

int PHYSOBS_FigureDragForSlope(_Instance *instance, int pathNumber, int *result)

{
  _Instance *p_Var1;
  int iVar2;

  p_Var1 = PHYSOBS_IsAnythingAttached(instance);
  if ((((p_Var1 != (_Instance *)0x0) || (pathNumber == 5)) || (pathNumber == 1)) ||
      (((pathNumber == 7 || (pathNumber == 4)) || ((pathNumber == 2 || (iVar2 = 0, pathNumber == 3))))))
  {
    *result = 0;
    iVar2 = 1;
  }
  return iVar2;
}

int PHYSOB_CheckDirectedLineCollision(_Instance *instance, _Instance *parent)

{
  PhysObWeaponAttributes *pPVar1;
  int iVar2;
  long lVar3;
  MATRIX *pMVar4;
  int iVar5;
  int iVar6;
  _PCollideInfo local_70;
  SVECTOR local_40;
  SVECTOR local_38;
  SVECTOR local_30;
  short local_28;
  short local_26;
  short local_24;
  undefined2 local_20;
  undefined2 local_1e;

  pMVar4 = instance->oldMatrix;
  if (pMVar4 != (MATRIX *)0x0)
  {
    local_38.vx = *(u_short *)pMVar4[2].t;
    local_38.vy = *(u_short *)(pMVar4[2].t + 1);
    local_38.vz = *(short *)(pMVar4[2].t + 2);
    pPVar1 = PhysObGetLight(instance);
    if (pPVar1 != (PhysObWeaponAttributes *)0x0)
    {
      pMVar4 = instance->matrix + pPVar1->ThrowSphere;
      local_40.vx = *(u_short *)pMVar4->t;
      local_40.vy = *(short *)(pMVar4->t + 1);
      local_40.vz = *(short *)(pMVar4->t + 2);
      iVar2 = rsin((int)(parent->rotation).z);
      local_28 = (short)iVar2;
      iVar2 = rcos((int)(parent->rotation).z);
      local_26 = -(short)iVar2;
      local_24 = 0;
      iVar2 = (u_int)(u_short)(parent->position).x - (u_int)local_38.vx;
      local_20 = (undefined2)iVar2;
      iVar5 = (u_int)(u_short)(parent->position).y - (u_int)local_38.vy;
      iVar2 = (iVar2 * 0x10000 >> 0x10) * (int)local_28 + (iVar5 * 0x10000 >> 0x10) * (int)local_26;
      local_1e = (undefined2)iVar5;
      if (0 < iVar2)
      {
        iVar5 = (u_int)local_40.vx - (u_int)local_38.vx;
        local_26 = local_40.vy - local_38.vy;
        local_24 = local_40.vz - local_38.vz;
        local_28 = (short)iVar5;
        lVar3 = MATH3D_LengthXYZ(iVar5 * 0x10000 >> 0x10, (int)local_26);
        lVar3;
        iVar5 = local_28 * iVar2;
        if (iVar5 < 0)
        {
          iVar5 = iVar5 + 0xfff;
        }
        iVar6 = local_26 * iVar2;
        local_28 = (short)(iVar5 >> 0xc);
        if (iVar6 < 0)
        {
          iVar6 = iVar6 + 0xfff;
        }
        iVar2 = local_24 * iVar2;
        local_26 = (short)(iVar6 >> 0xc);
        if (iVar2 < 0)
        {
          iVar2 = iVar2 + 0xfff;
        }
        local_24 = (short)(iVar2 >> 0xc);
        local_38.vx = local_38.vx + local_28;
        local_38.vy = local_38.vy + local_26;
        local_38.vz = local_38.vz + local_24;
      }
      local_70.newPoint = &local_40;
      local_70.oldPoint = &local_38;
      local_30.vx = local_40.vx;
      local_30.vy = local_40.vy;
      local_30.vz = local_40.vz;
      PHYSICS_CheckLineInWorld(instance, &local_70);
      if (local_70.type != 0)
      {
        local_30.vx = local_40.vx - local_30.vx;
        local_30.vy = local_40.vy - local_30.vy;
        local_30.vz = local_40.vz - local_30.vz;
        (instance->position).x = (instance->position).x + local_30.vx;
        (instance->position).y = (instance->position).y + local_30.vy;
        (instance->position).z = (instance->position).z + local_30.vz;
        COLLIDE_MoveAllTransforms(instance, &local_30);
        if (local_70.type == 3)
        {
          return 1;
        }
        return 2;
      }
    }
  }
  return 0;
}

int PHYSOB_CheckThrownLineCollision(_Instance *instance, _Instance *parent)

{
  bool bVar1;
  short angle;
  int iVar2;
  int iVar3;
  MATRIX *pMVar4;
  int iVar5;
  _PCollideInfo local_c8;
  u_char local_98;
  short local_94;
  u_char local_90;
  short local_8c;
  SVECTOR local_88;
  short local_80;
  short local_7e;
  short local_7c;
  u_char local_78;
  short local_74;
  short local_70;
  short local_6e;
  short local_6c;
  short local_68;
  short local_66;
  short local_64;
  _Normal local_60;
  _SVector local_58;
  _SVector _Stack80;
  u_char local_48;
  u_char local_44;
  u_char local_40;
  u_char local_3c;
  u_char local_38;
  long local_34;
  long local_30;
  long local_2c;
  _G2EulerAngles_Type local_28;

  if (parent != (_Instance *)0x0)
  {
    local_98 = *(u_int *)&parent->position;
    local_94 = (parent->position).z;
    bVar1 = false;
    if (instance->matrix != (MATRIX *)0x0)
    {
      iVar5 = 0;
      pMVar4 = instance->matrix;
      (instance->position).x = *(short *)instance->matrix->t;
      (instance->position).y = *(short *)(pMVar4->t + 1);
      (instance->position).z = *(short *)(pMVar4->t + 2);
      do
      {
        local_88.vy = local_98._2_2_;
        pMVar4 = instance->matrix + iVar5;
        local_88.vx = (short)local_98;
        local_88.vz = *(short *)(pMVar4->t + 2) + 100;
        iVar2 = ((int)(((u_int) * (u_short *)pMVar4->t - (local_98 & 0xffff)) * 0x10000) >> 0x10) * 6000;
        if (iVar2 < 0)
        {
          iVar2 = iVar2 + 0xfff;
        }
        iVar3 = (int)(short)(*(short *)(pMVar4->t + 1) - local_98._2_2_) * 6000;
        local_80 = (short)(iVar2 >> 0xc);
        if (iVar3 < 0)
        {
          iVar3 = iVar3 + 0xfff;
        }
        local_7e = (short)(iVar3 >> 0xc);
        iVar2 = (int)(short)(*(short *)(pMVar4->t + 2) - local_88.vz) * 6000;
        if (iVar2 < 0)
        {
          iVar2 = iVar2 + 0xfff;
        }
        local_7c = (short)(iVar2 >> 0xc);
        local_8c = local_7c + local_88.vz;
        local_90 = CONCAT22(local_7e + local_98._2_2_, local_80 + (short)local_98);
        local_78 = local_90;
        local_c8.newPoint = (SVECTOR *)&local_90;
        local_c8.oldPoint = &local_88;
        local_74 = local_8c;
        SetCollideInfoData(parent);
        PHYSICS_CheckLineInWorld(instance, &local_c8);
        SetNoPtCollideInFamily(parent);
        if ((local_c8.type != 0) && (local_c8.wNormal.vz < 0xed9))
        {
          bVar1 = true;
        }
        iVar5 = iVar5 + 2;
      } while ((iVar5 < 3) && (!bVar1));
      if (bVar1)
      {
        local_70 = *(short *)instance->matrix->t;
        local_6e = *(short *)(instance->matrix->t + 1);
        local_6c = *(short *)(instance->matrix->t + 2);
        local_68 = *(short *)instance->matrix[2].t;
        local_66 = *(short *)(instance->matrix[2].t + 1);
        local_64 = *(short *)(instance->matrix[2].t + 2);
        local_60.x = local_68 - local_70;
        local_60.y = local_66 - local_6e;
        local_60.z = local_64 - local_6c;
        CAMERA_Initialize(&local_60);
        local_58.x = 10;
        local_58.y = 0;
        local_58.z = 0x1000;
        angle = MATH3D_AngleBetweenVectors(&local_58, (_SVector *)&local_60);
        MATH3D_CrossProduct(&_Stack80, (_SVector *)&local_60, &local_58);
        pMVar4 = instance->matrix;
        local_48 = *(u_char *)pMVar4->m;
        local_44 = *(u_char *)(pMVar4->m + 2);
        local_40 = *(u_char *)(pMVar4->m + 4);
        local_3c = *(u_char *)(pMVar4->m + 6);
        local_38 = *(u_char *)(pMVar4->m + 8);
        local_34 = pMVar4->t[0];
        local_30 = pMVar4->t[1];
        local_2c = pMVar4->t[2];
        MATH3D_RotMatAboutVec(&_Stack80, (MATRIX *)(_G2Matrix_Type *)&local_48, angle);
        G2EulerAngles_FromMatrix(&local_28, (_G2Matrix_Type *)&local_48, 0);
        (instance->rotation).x = local_28.x;
        (instance->rotation).y = local_28.y;
        (instance->rotation).z = local_28.z;
        angle = (parent->position).z;
        *(u_char *)&instance->position = *(u_char *)&parent->position;
        (instance->position).z = angle;
      }
      (instance->position).z = (instance->position).z + 0x14;
      return 1;
    }
  }
  return 0;
}

int PHYSOB_CheckDroppedLineCollision(_Instance *instance, int xoffset, int yoffset, int startZOffset)

{
  MATRIX *pMVar1;
  _PCollideInfo local_48;
  SVECTOR local_18;
  SVECTOR local_10;

  pMVar1 = instance->matrix;
  local_10.vx = *(short *)pMVar1[1].t;
  local_18.vx = local_10.vx + (short)xoffset;
  local_10.vy = *(short *)(pMVar1[1].t + 1);
  local_18.vy = local_10.vy + (short)yoffset;
  local_48.newPoint = &local_18;
  local_48.oldPoint = &local_10;
  local_18.vz = *(short *)(pMVar1[1].t + 2) + (short)startZOffset;
  local_10.vz = local_18.vz;
  PHYSICS_CheckLineInWorld(instance, &local_48);
  return (int)local_48.type;
}

long PHYSOBS_CheckForStackedForwardHits(_Instance *block, long xoffset, long yoffset)

{
  int iVar1;

  do
  {
    block = PHYSOBS_IsAnythingAttached(block);
    if (block == (_Instance *)0x0)
    {
      return 0;
    }
    iVar1 = PHYSOB_CheckDroppedLineCollision(block, xoffset, yoffset, 0);
  } while (iVar1 == 0);
  return 1;
}

void PHYSOBS_SetNewAnim(_Instance *instance, PhysObData *Data, u_long modeBits, int path, int resetflg)

{
  Data->PathNumber = (short)path;
  Data->Mode = Data->Mode & 0xfffffffeU | modeBits;
  if (resetflg != 0)
  {
    ResetOrientation(instance);
  }
  PhysOb_AlignPush(instance, (int)Data->xForce, (int)Data->yForce, path, Data);
  return;
}

long PHYSOB_CheckForEnemyInBlkSpot(_Instance *instance, int dx, int dy)

{
  int iVar1;
  u_long uVar2;
  int iVar3;
  _Instance *Inst;

  dy = (instance->position).y + dy;
  Inst = (gameTrackerX.instanceList)->first;
  dx = (instance->position).x + dx;
  iVar1 = (int)(instance->position).z;
  while (true)
  {
    if (Inst == (_Instance *)0x0)
    {
      return 0;
    }
    if (((((((Inst->object->oflags2 & 0x80000U) != 0) && ((Inst->flags2 & 0x8000000U) == 0)) &&
           (uVar2 = INSTANCE_Post(Inst, 0), (uVar2 & 0x40000000) == 0)) &&
          ((iVar3 = (int)(Inst->position).x, dx + -0x140 <= iVar3 && (iVar3 <= dx + 0x140)))) &&
         ((iVar3 = (int)(Inst->position).y, dy + -0x140 <= iVar3 &&
                                                ((iVar3 <= dy + 0x140 && (iVar3 = (int)(Inst->position).z, iVar1 + -0x140 <= iVar3)))))) &&
        (iVar3 <= iVar1 + 0x140))
      break;
    Inst = Inst->next;
  }
  return 1;
}

long PHYSICS_CheckForValidMove(_Instance *instance)

{
  short sVar1;
  u_short uVar2;
  int Data;
  long lVar3;
  u_int uVar4;
  u_int uVar5;
  PhysObData *Data_00;
  evPhysicsSlideData *local_20;
  u_int local_1c;
  evPhysicsSlideData *local_18[2];

  gameTrackerX.block_collide_override = '\x01';
  Data_00 = (PhysObData *)instance->extraData;
  local_1c = 7;
  if ((Data_00->Mode & 1U) == 0)
    goto LAB_8006f1d4;
  Data = SetPhysicsDropOffData(0xa0, 0x280, 0, 0, 0, 0xb50);
  PhysicsUpdateTface(instance, Data);
  lVar3 = PHYSOBS_CheckForStackedForwardHits(instance, (int)Data_00->xForce * 0x2c0, (int)Data_00->yForce * 0x2c0);
  if (lVar3 == 0)
  {
    uVar4 = PHYSOB_CheckSlide(instance, (int)Data_00->xForce, (int)Data_00->yForce, &local_20);
    if ((uVar4 & 2) == 0)
    {
      if ((uVar4 & 0x4000) == 0)
      {
        uVar5 = PHYSOB_CheckDropOnSlope(instance, (int)Data_00->xForce, (int)Data_00->yForce, local_18);
        if (((uVar5 & 0x4000) == 0) || (0xf3c < (local_18[0]->DropNormal).z))
        {
          if (((Data_00->Mode & 8U) != 0) && ((uVar4 & 0x8000) != 0))
          {
            local_1c = 0;
          }
          uVar2 = Data_00->PathNumber;
          if ((1 < (u_int)uVar2 - 2) && (local_1c != 0))
          {
            if ((int)(short)uVar2 == 5)
            {
              local_1c = local_1c & 0xfffffffa;
            }
            else
            {
              if ((Data_00->Mode & 8U) == 0)
              {
                PHYSOBS_SetNewAnim(instance, Data_00, 2, (int)(short)uVar2, 1);
              }
              else
              {
                Data_00->PathNumber = 0xe;
                PHYSOBS_SetNewAnim(instance, Data_00, 2, 0xe, 1);
              }
            }
            goto LAB_8006f1d4;
          }
        }
      }
      else
      {
        if ((Data_00->Mode & 8U) != 0)
        {
          if ((Data_00->Mode & 0x200U) != 0)
          {
            local_1c = 0;
          }
          if (((uVar4 & 0x8000) != 0) ||
              (Data = PHYSOB_CheckDroppedLineCollision(instance, (int)Data_00->xForce * 0x2c0, (int)Data_00->yForce * 0x2c0,
                                                       0x280),
               Data != 0))
          {
            local_1c = 0;
          }
        }
        if (local_1c == 0)
          goto LAB_8006f1d4;
        Data = CheckSlope(local_20->Dot, -0x13a, 4);
        if (((Data == 0) && (Data = CheckSlope(local_20->Dot, 0x13a, 4), Data == 0)) &&
            ((Data_00->Mode & 0x200U) == 0))
        {
          Data = CheckSlope((int)(local_20->DropNormal).z, 0xe4f, 4);
          if (Data == 0)
          {
            lVar3 = PHYSOB_CheckForEnemyInBlkSpot(instance, (int)Data_00->xForce * 0x280, (int)Data_00->yForce * 0x280);
            if (((lVar3 == 0) ||
                 (Data = PHYSOB_CheckDroppedLineCollision(instance, (int)Data_00->xForce * 0x540,
                                                          (int)Data_00->yForce * 0x540, 0),
                  Data == 0)) &&
                (Data = CheckSlope((int)(local_20->DropNormal).z, 0x1000, 4), Data != 0))
            {
              PHYSOBS_SetNewAnim(instance, Data_00, 2, (int)Data_00->PathNumber, 0);
              goto LAB_8006f1d4;
            }
          }
          else
          {
            sVar1 = (local_20->DropNormal).x;
            if ((((((10 < sVar1) && (0 < Data_00->xForce)) ||
                   ((sVar1 < -10 && (Data_00->xForce < 0)))) ||
                  ((sVar1 = (local_20->DropNormal).y, 10 < sVar1 && (0 < Data_00->yForce)))) ||
                 ((sVar1 < -10 && (Data_00->yForce < 0)))) &&
                (Data = CheckBlockSlope(instance, (int)Data_00->xForce, (int)Data_00->yForce, 0x2dc,
                                        -0xad, 0x271, -0x138),
                 Data == 0))
            {
              Data = PHYSOBS_FigureDragForSlope(instance, (int)Data_00->PathNumber, (int *)&local_1c);
              if (Data == 0)
              {
                local_1c = 0;
              }
              goto LAB_8006f1d4;
            }
          }
        }
      }
    }
    else
    {
      Data = CheckSlope((int)(local_20->ForwardNormal).z, 0xe4f, 4);
      if (((((Data == 0) &&
             (Data = CheckSlope((int)(local_20->ForwardNormal).z, 0x1000, 4), Data == 0)) &&
            ((Data_00->Mode & 8U) != 0)) &&
           (((uVar4 & 4) != 0 &&
             (Data = PHYSOB_CheckDroppedLineCollision(instance, (int)Data_00->xForce * 0x2c0, (int)Data_00->yForce * 0x2c0,
                                                      0x280),
              Data == 0)))) &&
          (0xa9U - (int)local_20->Height < 0x13))
      {
        PHYSOBS_SetNewAnim(instance, Data_00, 2, 7, 1);
        local_1c = local_1c & 0xfffffffb | 8;
        goto LAB_8006f1d4;
      }
    }
  }
  local_1c = 0;
LAB_8006f1d4:
  gameTrackerX.block_collide_override = '\0';
  if (local_1c == 0)
  {
    Data_00->Mode = Data_00->Mode & 0xfffffeb5;
  }
  return local_1c;
}

void ExecuteGravitate(_Instance *instance)

{
  int iVar1;
  short sVar2;
  MATRIX *pMVar3;
  u_int *puVar4;
  _G2Matrix_Type *matrix;
  _Model *p_Var5;
  _Instance *parent;
  _G2EulerAngles_Type local_30;
  int local_28;
  int local_24;
  int local_20;

  puVar4 = (u_int *)instance->extraData;
  parent = (_Instance *)puVar4[2];
  p_Var5 = *instance->object->modelList;
  matrix = (_G2Matrix_Type *)(parent->matrix + *(short *)(puVar4 + 3));
  iVar1 = CheckPhysOb(instance, 1);
  if (iVar1 != 0)
  {
    COLLIDE_SegmentCollisionOn(instance, 1);
  }
  if (*(short *)(puVar4 + 9) != 0)
  {
    G2EulerAngles_FromMatrix(&local_30, matrix, 0x15);
    if (*(short *)((int)puVar4 + 0x26) == 0)
    {
      *(short *)(puVar4 + 5) = (instance->rotation).x;
      *(short *)((int)puVar4 + 0x16) = (instance->rotation).y;
      *(short *)(puVar4 + 6) = (instance->rotation).z;
      *(short *)((int)puVar4 + 0xe) = (instance->position).x;
      *(short *)(puVar4 + 4) = (instance->position).y;
      *(short *)((int)puVar4 + 0x12) = (instance->position).z;
    }
    (instance->rotation).x =
         *(short *)(puVar4 + 5) +
         (short)((((int)local_30.x - (int)*(short *)(puVar4 + 5)) *
 (int)*(short *)(puVar4 + 9));
    (instance->rotation).y =
         *(short *)((int)puVar4 + 0x16) +
         (short)((((int)local_30.y - (int)*(short *)((int)puVar4 + 0x16)) *
 (int)*(short *)(puVar4 + 9));
    pMVar3 = instance->matrix;
    (instance->rotation).z =
         *(short *)(puVar4 + 6) +
         (short)((((int)local_30.z - (int)*(short *)(puVar4 + 6)) *
 (int)*(short *)(puVar4 + 9));
    ApplyMatrixSV(pMVar3 + 2,&p_Var5->segmentList[2].px,&local_28);
    local_28 = (matrix->trans).x - local_28;
    local_24 = (matrix->trans).y - local_24;
    local_20 = (matrix->trans).z - local_20;
    (instance->position).x =
         *(short *)((int)puVar4 + 0xe) +
         (short)(((local_28 - *(short *)((int)puVar4 + 0xe)) * (int)*(short *)((int)puVar4 + 0x26))
 (int)*(short *)(puVar4 + 9));
    (instance->position).y =
         *(short *)(puVar4 + 4) +

                (int)*(short *)(puVar4 + 9));
    (instance->position).z =
         *(short *)((int)puVar4 + 0x12) +
         (short)(((local_20 - *(short *)((int)puVar4 + 0x12)) * (int)*(short *)((int)puVar4 + 0x26))
 (int)*(short *)(puVar4 + 9));
    *(short *)((int)puVar4 + 0x26) = *(short *)((int)puVar4 + 0x26) + 1;
  }
  if ((*puVar4 & 0x20000) != 0)
  {
    if ((int)*(short *)(puVar4 + 9) == 0)
    {
      sVar2 = 0x1000;
    }
    else
    {

                              (int)*(short *)(puVar4 + 9));
    }
    (instance->scale).z = sVar2;
    (instance->scale).y = sVar2;
    (instance->scale).x = sVar2;
  }
  if (*(short *)((int)puVar4 + 0x26) == *(short *)(puVar4 + 9))
  {
    if ((*puVar4 & 0x20000) == 0)
    {
      *puVar4 = *puVar4 & 0xfefdbffa | 0x1080;
      TurnOnCollisionPhysOb(instance, 7);
      INSTANCE_LinkToParent(instance, parent, (int)*(short *)(puVar4 + 3));
      puVar4[2] = 0;
      *(undefined2 *)((int)puVar4 + 0x26) = 0;
      *(undefined2 *)(puVar4 + 9) = 0;
      instance->xVel = 0;
      instance->yVel = 0;
      instance->zVel = 0;
      instance->xAccl = 0;
      instance->yAccl = 0;
      instance->zAccl = 0;
    }
    else
    {
      INSTANCE_NewInstance(instance);
    }
  }
  return;
}

void ExecuteFlip(_Instance *instance)

{
  void *pvVar1;
  int iVar2;

  pvVar1 = instance->extraData;
  iVar2 = *(int *)((int)pvVar1 + 8);
  (instance->position).x =
      *(short *)((int)*(short *)((int)pvVar1 + 0x1a) * 0x20 + *(int *)(iVar2 + 0x40) + 0x14) +
      *(short *)((int)pvVar1 + 0xe);
  (instance->position).y =
      *(short *)((int)*(short *)((int)pvVar1 + 0x1a) * 0x20 + *(int *)(iVar2 + 0x40) + 0x18) +
      *(short *)((int)pvVar1 + 0x10);
  return;
}

void PIPE3D_NormalizeMatrix(_SVector *v)

{
  u_long square;
  long lVar1;

  square = MATH3D_SquareLength((int)v->x, (int)v->y, (int)v->z);
  if (square == 0)
  {
    lVar1 = 1;
  }
  else
  {
    lVar1 = MATH3D_FastSqrt0(square);
  }
 lVar1);
 lVar1);
 lVar1);
 return;
}

int PHYSOB_MoveTowardsAlign(_Instance *instance, _SVector *orgVec, _SVector *endVec)

{
  int iVar1;
  int iVar2;
  u_long square;
  u_int uVar3;
  long lVar4;
  u_int uVar5;
  MATRIX *pMVar6;
  u_char auStack104[8];
  _G2Matrix_Type _Stack72;
  short local_28;
  short local_26;
  short local_24;
  undefined2 local_22;
  _G2EulerAngles_Type local_20;

  iVar1 = gameTrackerX.timeMult * 0x32;
  PIPE3D_NormalizeMatrix(orgVec);
  PIPE3D_NormalizeMatrix(endVec);
  pMVar6 = instance->matrix;
  iVar2 = (int)orgVec->y * (int)endVec->z - (int)orgVec->z * (int)endVec->y;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xfff;
  }
  local_28 = (short)(iVar2 >> 0xc);
  iVar2 = (int)orgVec->z * (int)endVec->x - (int)orgVec->x * (int)endVec->z;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xfff;
  }
  local_26 = (short)(iVar2 >> 0xc);
  iVar2 = (int)orgVec->x * (int)endVec->y - (int)orgVec->y * (int)endVec->x;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xfff;
  }
  local_24 = (short)(iVar2 >> 0xc);
  iVar2 = (int)orgVec->x * (int)endVec->x + (int)orgVec->y * (int)endVec->y +
          (int)orgVec->z * (int)endVec->z;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xfff;
  }
  iVar2 = MATH3D_racos_S(iVar2 >> 0xc);
  uVar5 = ((iVar2 << 0x10) >> 0x10) - ((iVar2 << 0x10) >> 0x1f) >> 1;
  uVar3 = SEXT24((short)(iVar1 >> 0xc));
  if ((int)uVar5 < (int)-uVar3)
  {
    uVar5 = -uVar3;
  }
  if ((int)uVar3 < (int)uVar5)
  {
    uVar5 = uVar3;
  }
  square = MATH3D_SquareLength((int)local_28, (int)local_26, (int)local_24);
  if ((int)square < 1)
  {
    lVar4 = 0x1000;
  }
  else
  {
    lVar4 = MATH3D_FastSqrt0(square);
  }
  iVar1 = rsin(uVar5);
 lVar4);
 lVar4);
 lVar4);
 iVar1 = rcos(uVar5);
 local_22 = (undefined2)iVar1;
 G2Quat_ToMatrix_S(&local_28, (short *)auStack104);
 PopMatrix(auStack104, (u_short *)pMVar6, (u_int *)&_Stack72);
 G2EulerAngles_FromMatrix(&local_20, &_Stack72, 0x15);
 (instance->rotation).x = local_20.x;
 (instance->rotation).y = local_20.y;
 (instance->rotation).z = local_20.z;
 return (u_int)((int)uVar5 < 0x14);
}

int PHYSOB_ReAlignFalling(_Instance *instance, int zEndOff)

{
  u_short uVar1;
  u_short uVar2;
  bool bVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  u_int uVar7;
  short sVar8;
  int iVar9;
  MATRIX *pMVar10;
  u_int uVar11;
  u_char uVar12;
  short sVar13;
  short sVar14;
  int iVar15;
  int iVar16;
  _Model *p_Var17;
  u_int uVar18;
  u_char local_d0;
  u_short local_cc;
  u_char local_c8;
  u_short local_c4;
  u_char local_c0;
  short local_bc;
  u_char local_b8;
  short local_b4;
  _PCollideInfo local_b0;
  u_int local_80;
  u_short local_7c;
  u_int local_78;
  short local_74;
  _PCollideInfo local_70;
  SVECTOR local_40;
  SVECTOR local_38;
  short local_30;
  short local_2e;
  short local_2c;

  uVar18 = 0xffff8300;
  p_Var17 = instance->object->modelList[instance->currentModel];
  iVar15 = 0;
  bVar3 = false;
  if (0 < p_Var17->numSegments)
  {
    iVar16 = 0;
    uVar7 = uVar18;
    do
    {
      sVar14 = 0;
      sVar13 = 0;
      uVar18 = uVar7;
      if ((p_Var17->segmentList[iVar15].hInfo != (_HInfo *)0x0) || (iVar15 == 0))
      {
        iVar5 = (int)instance->matrix->m + iVar16;
        uVar1 = *(u_short *)(iVar5 + 0x14);
        uVar2 = *(u_short *)(iVar5 + 0x18);
        local_78 = CONCAT22(uVar2, uVar1);
        local_80 = CONCAT22(uVar2, uVar1);
        local_7c = *(short *)(iVar5 + 0x1c) + (short)zEndOff;
        local_74 = *(short *)(iVar5 + 0x1c) + 300;
        if (bVar3)
        {
          iVar5 = (u_int)uVar1 - (local_c0 & 0xffff);
          iVar9 = (u_int)uVar2 - (local_c0 >> 0x10);
          iVar6 = iVar5 * 0x10000;
          sVar4 = (short)((u_int)iVar6 >> 0x10);
          if (iVar6 >> 0x10 < 0)
          {
            sVar4 = -sVar4;
          }
          iVar6 = iVar9 * 0x10000;
          sVar8 = (short)((u_int)iVar6 >> 0x10);
          if (iVar6 >> 0x10 < 0)
          {
            sVar8 = -sVar8;
          }
          if ((sVar4 < 100) && (sVar8 < 100))
          {
            if ((sVar4 == 0) && (sVar8 == 0))
            {
              sVar14 = 0x40;
              sVar13 = 0;
            }
            else
            {
              sVar14 = (short)iVar5;
              sVar13 = (short)iVar9;
              if ((sVar4 < 0x14) && (sVar8 < 0x14))
              {
                sVar14 = sVar14 * 0x10;
                sVar13 = sVar13 * 0x10;
              }
              else
              {
                sVar14 = sVar14 * 4;
                sVar13 = sVar13 * 4;
              }
            }
            local_78 = CONCAT22(uVar2 + sVar13, uVar1 + sVar14);
            local_80 = CONCAT22(uVar2 + sVar13, uVar1 + sVar14);
          }
          else
          {
            sVar13 = 0;
            sVar14 = 0;
          }
        }
        local_b0.newPoint = (SVECTOR *)&local_80;
        local_b0.oldPoint = (SVECTOR *)&local_78;
        PHYSICS_CheckLineInWorld(instance, &local_b0);
        if (local_b0.type != 0)
        {
          uVar18 = (u_int)local_7c - (u_int) * (u_short *)((int)instance->matrix->t + iVar16 + 8);
          if ((int)(uVar18 * 0x10000) < (int)(uVar7 << 0x10))
          {
            uVar18 = uVar7;
          }
          if (bVar3)
          {
            local_c8 = local_80;
            local_c4 = local_7c;
            local_b4 = local_74;
            local_b8._0_2_ = (short)local_78;
            local_b8._2_2_ = (short)(local_78 >> 0x10);
            local_b8 = CONCAT22(local_b8._2_2_ - sVar13, (short)local_b8 - sVar14);
          }
          else
          {
            local_d0 = local_80;
            local_cc = local_7c;
            local_c0 = local_78;
            local_bc = local_74;
            local_c8 = local_80;
            local_c4 = local_7c;
            local_b8 = local_78;
            local_b4 = local_74;
            bVar3 = true;
          }
        }
      }
      iVar15 = iVar15 + 1;
      iVar16 = iVar16 + 0x20;
      uVar7 = uVar18;
    } while (iVar15 < p_Var17->numSegments);
  }
  uVar7 = 1;
  if (bVar3)
  {
    instance->zAccl = 0;
    instance->zVel = 0;
    (instance->position).z = *(short *)(instance->matrix->t + 2) + (short)uVar18;
    uVar11 = (local_b8 & 0xffff) - (local_c0 & 0xffff);
    local_b4 = local_b4 - local_bc;
    local_b8 = uVar11 & 0xffff | (u_int)(u_short)(local_b8._2_2_ - local_c0._2_2_) << 0x10;
    uVar7 = (local_c8 & 0xffff) - (local_d0 & 0xffff);
    local_c4 = local_c4 - local_cc;
    local_c8 = uVar7 & 0xffff | (u_int)(u_short)(local_c8._2_2_ - local_d0._2_2_) << 0x10;
    if ((((uVar11 * 0x10000 != uVar7 * 0x10000) ||
          ((short)(local_b8._2_2_ - local_c0._2_2_) != (short)(local_c8._2_2_ - local_d0._2_2_))) ||
         (local_b4 != local_c4)) ||
        (uVar7 = 1, (uVar18 & 0xffff) != 0))
    {
      iVar15 = 0;
      if (0 < p_Var17->numSegments)
      {
        iVar16 = 0;
        do
        {
          if ((*(int *)((int)&p_Var17->segmentList->hInfo + iVar16) != 0) || (iVar15 == 0))
          {
            pMVar10 = instance->matrix + iVar15;
            local_38.vx = *(short *)pMVar10->t;
            local_38.vy = *(short *)(pMVar10->t + 1);
            local_38.vz = *(short *)(pMVar10->t + 2);
            pMVar10 = instance->oldMatrix + iVar15;
            local_30 = (*(short *)pMVar10->t - local_38.vx) * 2;
            local_2e = (*(short *)(pMVar10->t + 1) - local_38.vy) * 2;
            local_2c = (*(short *)(pMVar10->t + 2) - local_38.vz) * 2;
            local_40.vx = local_38.vx + local_30;
            local_40.vy = local_38.vy + local_2e;
            local_40.vz = local_38.vz + local_2c;
            local_70.newPoint = &local_40;
            local_70.oldPoint = &local_38;
            PHYSICS_CheckLineInWorld(instance, &local_70);
            if (local_70.type != 0)
            {
              uVar12 = *(u_char *)&(instance->oldRotation).z;
              *(u_char *)&instance->rotation = *(u_char *)&instance->oldRotation;
              *(u_char *)&(instance->rotation).z = uVar12;
              return 1;
            }
          }
          iVar15 = iVar15 + 1;
          iVar16 = iVar16 + 0x18;
        } while (iVar15 < p_Var17->numSegments);
      }
      iVar15 = PHYSOB_MoveTowardsAlign(instance, (_SVector *)&local_b8, (_SVector *)&local_c8);
      uVar7 = 0;
      if ((uVar18 & 0xffff) == 0)
      {
        uVar7 = (u_int)(iVar15 != 0);
      }
    }
  }
  return uVar7;
}

void FlipPhysOb(_Instance *instance, int flags)

{
  int zEndOff;
  u_int *puVar1;
  _Instance *parent;

  parent = instance->LinkParent;
  puVar1 = (u_int *)instance->extraData;
  if (parent == (_Instance *)0x0)
  {
    *puVar1 = *puVar1 & 0xff7fffff;
  }
  else
  {
    INSTANCE_UnlinkFromParent(instance);
  }
  PHYSOB_CheckThrownLineCollision(instance, parent);
  if ((flags & 2U) == 0)
  {
    if ((flags & 4U) == 0)
    {
      zEndOff = 0;
      if (parent != (_Instance *)0x0)
      {
        zEndOff = -900;
      }
      PHYSOB_ReAlignFalling(instance, zEndOff);
    }
    *(_Instance **)(puVar1 + 0x10) = parent;
    *puVar1 = *puVar1 & 0xffffef6f | 0x400004;
    instance->zAccl = -10;
  }
  else
  {
    *puVar1 = *puVar1 & 0xffffff6f | 0x1000;
    instance->zAccl = 0;
  }
  instance->xVel = 0;
  instance->yVel = 0;
  instance->zVel = 0;
  instance->xAccl = 0;
  instance->yAccl = 0;
  return;
}

void PhysicalRelocateTune(Object *object, long offset)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;

  pvVar6 = object->data;
  if (pvVar6 != (void *)0x0)
  {
    if (*(short *)((int)pvVar6 + 2) == 0)
    {
      iVar2 = 0;
      if (*(int *)((int)pvVar6 + 0x18) != 0)
      {
        iVar2 = *(int *)((int)pvVar6 + 0x18) + offset;
      }
      *(int *)((int)pvVar6 + 0x18) = iVar2;
      if (iVar2 != 0)
      {
        iVar3 = 0;
        if (*(int *)(iVar2 + 4) != 0)
        {
          iVar3 = *(int *)(iVar2 + 4) + offset;
        }
        *(int *)(iVar2 + 4) = iVar3;
      }
      iVar2 = 0;
      if (*(int *)((int)pvVar6 + 0x20) != 0)
      {
        iVar2 = *(int *)((int)pvVar6 + 0x20) + offset;
      }
      *(int *)((int)pvVar6 + 0x20) = iVar2;
    }
    sVar1 = *(short *)((int)pvVar6 + 2);
    if (sVar1 == 3)
    {
      iVar3 = *(int *)((int)object->data + 0x28);
      iVar2 = 0;
      if (iVar3 != 0)
      {
        iVar2 = iVar3 + offset;
      }
      *(int *)((int)object->data + 0x28) = iVar2;
      if (iVar2 != 0)
      {
        iVar3 = 0;
        if (*(int *)(iVar2 + 0x10) != 0)
        {
          iVar3 = *(int *)(iVar2 + 0x10) + offset;
        }
        *(int *)(iVar2 + 0x10) = iVar3;
        if (iVar3 != 0)
        {
          iVar4 = 0;
          if (*(int *)(iVar3 + 4) != 0)
          {
            iVar4 = *(int *)(iVar3 + 4) + offset;
          }
          *(int *)(iVar3 + 4) = iVar4;
        }
        iVar3 = 0;
        if (*(int *)(iVar2 + 0x18) != 0)
        {
          iVar3 = *(int *)(iVar2 + 0x18) + offset;
        }
        *(int *)(iVar2 + 0x18) = iVar3;
      }
      sVar1 = *(short *)((int)pvVar6 + 2);
    }
    if (sVar1 == 7)
    {
      pvVar6 = object->data;
      iVar2 = 0;
      if (*(int *)((int)pvVar6 + 0xc) != 0)
      {
        iVar2 = *(int *)((int)pvVar6 + 0xc) + offset;
      }
      *(int *)((int)pvVar6 + 0xc) = iVar2;
      if ((iVar2 != 0) && (iVar3 = 0, 0 < *(int *)((int)pvVar6 + 8)))
      {
        do
        {
          iVar4 = 0;
          if (*(int *)(iVar2 + 8) != 0)
          {
            iVar4 = *(int *)(iVar2 + 8) + offset;
          }
          *(int *)(iVar2 + 8) = iVar4;
          if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x10), iVar4 != 0))
          {
            iVar5 = 0;
            if (*(int *)(iVar4 + 4) != 0)
            {
              iVar5 = *(int *)(iVar4 + 4) + offset;
            }
            *(int *)(iVar4 + 4) = iVar5;
          }
          iVar3 = iVar3 + 1;
          iVar2 = iVar2 + 0xc;
        } while (iVar3 < *(int *)((int)pvVar6 + 8));
      }
    }
  }
  return;
}

int PHYSOBS_CheckObjectAxisAlignment(MATRIX *m0, MATRIX *m1, _SVector *axis)

{
  short local_40[2];
  short local_3c;
  short local_38;
  short local_30[2];
  short local_2c;
  short local_28;

  ApplyMatrixSV(m0, axis, local_40);
  ApplyMatrixSV(m1, axis, local_30);
  return ((int)local_40[0] * (int)local_30[0] + (int)local_3c * (int)local_2c +
          (int)local_38 * (int)local_28) *
             0x10 >>
         0x10;
}

int PHYSOB_CheckSlide(_Instance *instance, int x, int y, evPhysicsSlideData **data)

{
  evPhysicsSlideData *Data;
  int iVar1;

  Data = (evPhysicsSlideData *)
      SetPhysicsSwimData(1, x * 0x2c00000 >> 0x10, y * 0x2c00000 >> 0x10, 0, 0x280, 0x280, -0xa0);
  *data = Data;
  iVar1 = PhysicsCheckSliding(instance, (int)Data, 1);
  return iVar1;
}

int PHYSOB_CheckSlide2(_Instance *instance, int x, int y, evPhysicsSlideData **data)

{
  evPhysicsSlideData *Data;
  int iVar1;

  Data = (evPhysicsSlideData *)
      SetPhysicsSwimData(1, x * 0x2c00000 >> 0x10, y * 0x2c00000 >> 0x10, 0, 0x280, 0x280, -0x96);
  *data = Data;
  iVar1 = PhysicsCheckSliding(instance, (int)Data, 1);
  return iVar1;
}

int PHYSOB_CheckDropOnSlope(_Instance *instance, int x, int y, evPhysicsSlideData **data)

{
  evPhysicsSlideData *Data;
  int iVar1;

  Data = (evPhysicsSlideData *)
      SetPhysicsSwimData(1, x * 0x2c00000 >> 0x10, y * 0x2c00000 >> 0x10, 0, 0xa00, 0x280, -0xa0);
  *data = Data;
  iVar1 = PhysicsCheckSliding(instance, (int)Data, 1);
  return iVar1;
}

int PHYSOB_CheckSlideNormal(_Instance *instance, int x, int y, evPhysicsSlideData **data)

{
  int iVar1;
  int local_res4;
  int local_res8[2];

  local_res4 = x;
  local_res8[0] = y;
  PHYSOB_NormalToAxis((short *)&local_res4, (short *)local_res8);
  iVar1 = PHYSOB_CheckSlide2(instance, local_res4, local_res8[0], data);
  return iVar1;
}

void PHYSOB_NormalToAxis(short *x, short *y)

{
  short sVar1;

  sVar1 = *y;
  if (*x < 0x401)
  {
    if (*x < -0x400)
    {
      *x = -1;
    }
    else
    {
      *x = 0;
    }
  }
  else
  {
    *x = 1;
  }
  if (0x400 < sVar1)
  {
    *y = 1;
    return;
  }
  if (sVar1 < -0x400)
  {
    *y = -1;
    return;
  }
  *y = 0;
  return;
}
