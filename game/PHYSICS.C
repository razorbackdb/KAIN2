#include "THISDUST.H"
#include "PHYSICS.H"

void SetCollideInfoData(_Instance *instance)

{
  _Instance *instance_00;

  instance_00 = instance->LinkChild;
  instance->flags = instance->flags | 0x40;
  while (instance_00 != (_Instance *)0x0)
  {
    SetCollideInfoData(instance_00);
    instance_00 = instance_00->LinkSibling;
  }
  return;
}

void SetNoPtCollideInFamily(_Instance *instance)

{
  _Instance *instance_00;

  instance_00 = instance->LinkChild;
  instance->flags = instance->flags & 0xffffffbf;
  while (instance_00 != (_Instance *)0x0)
  {
    SetNoPtCollideInFamily(instance_00);
    instance_00 = instance_00->LinkSibling;
  }
  return;
}

void PHYSICS_CheckLineInWorld(_Instance *instance, _PCollideInfo *pcollideInfo)

{
  pcollideInfo->collideType = 0x3f;
  PHYSICS_CheckLineInWorldMask(instance, pcollideInfo);
  return;
}

void PHYSICS_CheckLineInWorldMask(_Instance *instance, _PCollideInfo *pcollideInfo)

{
  Level *level;

  level = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
  pcollideInfo->inst = (_Instance *)0x0;
  pcollideInfo->instance = instance;
  SetCollideInfoData(instance);
  if (level == (Level *)0x0)
  {
    pcollideInfo->type = 0;
  }
  else
  {
    COLLIDE_PointAndTerrain(pcollideInfo, level);
  }
  SetNoPtCollideInFamily(instance);
  return;
}

int SetPhysicsLinkedMoveData(_Instance *instance, int Data, short Mode)

{
  short sVar1;
  bool bVar2;
  bool bVar3;
  _Instance *p_Var4;
  long lVar5;
  int introUniqueID;
  int iVar6;
  u_int *puVar7;
  u_char *puVar8;
  int iVar9;
  int iVar10;
  _G2Matrix_Type _Stack144;
  u_int local_70;
  int local_6c;
  int local_68;
  _G2EulerAngles_Type local_60;
  short local_58[2];
  short local_54;
  short local_50;
  u_short local_48;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;

  if (instance->matrix == (MATRIX *)0x0)
  {
    instance->attachedID = 0;
    introUniqueID = 0;
  }
  else
  {
    iVar6 = *(int *)Data;
    puVar8 = (u_char *)(*(int *)(iVar6 + 0x40) + *(int *)(Data + 4) * 0x20);
    local_40 = puVar8[5];
    local_3c = puVar8[6];
    local_38 = puVar8[7];
    local_34 = (int)(instance->position).y;
    sVar1 = (instance->position).x;
    iVar9 = (int)sVar1;
    local_30 = (int)(instance->position).z;
    introUniqueID = instance->attachedID;
    local_48 = Mode;
    if ((*(int *)(iVar6 + 0x3c) == introUniqueID) &&
        (bVar2 = false, *(int *)(Data + 4) == instance->attachedSegment))
    {
      introUniqueID = (int)(instance->oldPos).x;
      iVar10 = (int)(instance->oldPos).y;
      iVar6 = (int)(instance->oldPos).z;
      bVar3 = false;
      if ((*(int *)&instance->rotation != *(int *)&instance->oldRotation) ||
          ((instance->rotation).z != (instance->oldRotation).z))
      {
        bVar3 = true;
      }
      if (((iVar9 != introUniqueID) || (local_34 != iVar10)) || (local_30 != iVar6))
      {
        bVar2 = true;
      }
      if ((bVar2) || (bVar3))
      {
        TransposeMatrix(puVar8, (u_char *)&_Stack144);
        if (bVar3)
        {
          PopMatrix((u_char *)&_Stack144, (u_short *)instance->matrix,
                    (u_int *)&instance->relativeMatrix);
        }
        if (bVar2)
        {
          local_70 = iVar9 - introUniqueID;
          local_6c = local_34 - iVar10;
          local_68 = local_30 - iVar6;
          ApplyMatrixLV((u_char *)&_Stack144, &local_70, (int *)&local_70);
          (instance->relativeMatrix).t[0] = (instance->relativeMatrix).t[0] + local_70;
          (instance->relativeMatrix).t[1] = (instance->relativeMatrix).t[1] + local_6c;
          (instance->relativeMatrix).t[2] = (instance->relativeMatrix).t[2] + local_68;
        }
      }
      ApplyMatrixLV(puVar8, (u_int *)(instance->relativeMatrix).t, (int *)local_58);
      PopMatrix(puVar8, (u_short *)&instance->relativeMatrix, (u_int *)&_Stack144);
      G2EulerAngles_FromMatrix(&local_60, &_Stack144, 0x15);
      *(short *)(Data + 8) = (local_58[0] + (short)local_40) - sVar1;
      *(short *)(Data + 10) = (local_54 + (short)local_3c) - (short)local_34;
      *(short *)(Data + 0xc) = (local_50 + (short)local_38) - (short)local_30;
      *(short *)(Data + 0x10) = local_60.x - (instance->oldRotation).x;
      *(short *)(Data + 0x12) = local_60.y - (instance->oldRotation).y;
      *(short *)(Data + 0x14) = local_60.z - (instance->oldRotation).z;
    }
    else
    {
      if ((introUniqueID != *(int *)(iVar6 + 0x3c)) &&
          (p_Var4 = INSTANCE_Deactivate(introUniqueID), p_Var4 != (_Instance *)0x0))
      {
        p_Var4->flags2 = p_Var4->flags2 & 0xffffff7f;
      }
      *(u_int *)(iVar6 + 0x18) = *(u_int *)(iVar6 + 0x18) | 0x80;
      instance->attachedID = *(long *)(iVar6 + 0x3c);
      lVar5 = *(long *)(Data + 4);
      instance->zAccl = 0;
      instance->zVel = 0;
      instance->attachedSegment = lVar5;
      TransposeMatrix(puVar8, (u_char *)&_Stack144);
      local_70 = iVar9 - local_40;
      puVar7 = (u_int *)(instance->relativeMatrix).t;
      local_6c = local_34 - local_3c;
      local_68 = local_30 - local_38;
      ApplyMatrixLV((u_char *)&_Stack144, &local_70, (int *)puVar7);
      PopMatrix((u_char *)&_Stack144, (u_short *)instance->matrix,
                (u_int *)&instance->relativeMatrix);
      ApplyMatrixLV(puVar8, puVar7, (int *)&local_70);
      *(undefined2 *)(Data + 0x14) = 0;
      *(undefined2 *)(Data + 0x12) = 0;
      *(undefined2 *)(Data + 0x10) = 0;
      *(short *)(Data + 8) = sVar1 - ((short)local_70 + (short)local_40);
      *(short *)(Data + 10) = (short)local_34 - ((short)local_6c + (short)local_3c);
      *(short *)(Data + 0xc) = (short)local_30 - ((short)local_68 + (short)local_38);
    }
    if ((local_48 & 4) != 0)
    {
      PhysicsCheckLinkedMove(instance, (evPhysicsLinkedMoveData *)Data, ((u_int)(local_48 >> 3) ^ 1) & 1);
    }
    if ((local_48 & 2) != 0)
    {
      INSTANCE_Query(instance, 0x4010008, Data);
    }
    if (((*(int *)(Data + 8) != 0) || (*(short *)(Data + 0xc) != 0)) ||
        ((*(int *)(Data + 0x10) != 0 || (*(short *)(Data + 0x14) != 0))))
    {
      instance->flags2 = instance->flags2 | 8;
    }
    introUniqueID = 0x10000;
  }
  return introUniqueID;
}

void PhysicsCheckLinkedMove(_Instance *instance, evPhysicsLinkedMoveData *Data, int updateTransforms)

{
  (instance->position).x = (instance->position).x + (Data->posDelta).x;
  (instance->position).y = (instance->position).y + (Data->posDelta).y;
  (instance->position).z = (instance->position).z + (Data->posDelta).z;
  if (updateTransforms != 0)
  {
    COLLIDE_MoveAllTransforms(instance, (SVECTOR *)&Data->posDelta);
  }
  (instance->rotation).z = (instance->rotation).z + (Data->rotDelta).z;
  return;
}

int PhysicsCheckGravity(_Instance *instance, int Data, short Mode)

{
  bool bVar1;
  short sVar2;
  int Data_00;
  int iVar3;
  _Instance *p_Var4;
  u_int uVar5;
  int iVar6;
  NodeType *pNVar7;
  int iVar8;
  _TFace *tface;
  u_int uVar9;
  _PCollideInfo local_68;
  SVECTOR local_38;
  SVECTOR local_30;

  local_38.vx = (instance->position).x;
  uVar9 = 0;
  local_38.vy = (instance->position).y;
  bVar1 = false;
  uVar5 = (u_int)(u_short)(instance->position).z;
  Data_00 = uVar5 + *(u_short *)Data;
  local_38.vz = (short)Data_00;
  iVar6 = uVar5 - *(u_short *)(Data + 2);
  local_30.vz = (short)iVar6;
  local_68.newPoint = &local_30;
  local_68.oldPoint = &local_38;
  local_30.vx = local_38.vx;
  local_30.vy = local_38.vy;
  if (Data_00 * 0x10000 < iVar6 * 0x10000)
  {
    local_68.type = 0;
    goto LAB_800748d8;
  }
  if (instance->cachedTFace == -1)
  {
    instance->waterFace = (_TFace *)0x0;
    gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x8000;
  LAB_800748bc:
    PHYSICS_CheckLineInWorld(instance, &local_68);
  }
  else
  {
    p_Var4 = (_Instance *)STREAM_GetWaterZLevel(instance->currentStreamUnitID);
    pNVar7 = (p_Var4->node).prev;
    gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x8000;
    tface = (_TFace *)((int)pNVar7[4].prev + (int)instance->cachedTFace * 0xc);
    Data_00 = COLLIDE_SAndT((_Terrain *)(p_Var4->node).prev,
                            (BSPTree *)((int)pNVar7[9].prev + (int)instance->cachedBSPTree * 0x24),
                            (_SVector *)&local_30, (_SVector *)&local_38, tface, 0, 0);
    if (Data_00 == 0)
    {
      instance->waterFace = (_TFace *)0x0;
      goto LAB_800748bc;
    }
    local_68.type = 3;
    local_68.segment = instance->cachedBSPTree;
    local_68.prim = tface;
    local_68.inst = p_Var4;
    COLLIDE_GetNormal(tface->normal, (short *)(p_Var4->node).prev[4].next,
                      (_SVector *)&local_68.wNormal);
  }
  gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffff7fff;
LAB_800748d8:
  if (((((u_int)local_68.type - 2 < 2) || (local_68.type == 5)) &&
       (Data_00 = (int)local_68.wNormal.vz, Data_00 < *(short *)(Data + 10))) &&
      (0 < Data_00))
  {
    iVar8 = (int)-local_68.wNormal.vz;
    iVar6 = -(local_68.wNormal.vx * iVar8);
    if (0 < local_68.wNormal.vx * iVar8)
    {
      iVar6 = iVar6 + 0xfff;
    }
    iVar3 = -(local_68.wNormal.vy * iVar8);
    Data_00 = Data_00 * iVar8;
    if (0 < local_68.wNormal.vy * iVar8)
    {
      iVar3 = iVar3 + 0xfff;
    }
    if (Data_00 < 0)
    {
      Data_00 = Data_00 + 0xfff;
    }
    if (instance->zVel < -0x30)
    {
      sVar2 = -*(short *)&instance->zVel;
    }
    else
    {
      sVar2 = 0x30;
    }
    iVar8 = (int)sVar2;
    iVar6 = (short)(iVar6 >> 0xc) * iVar8;
    if (iVar6 < 0)
    {
      iVar6 = iVar6 + 0xfff;
    }
    iVar3 = (short)(iVar3 >> 0xc) * iVar8;
    local_38.vx = (local_68.newPoint)->vx + (short)(iVar6 >> 0xc);
    if (iVar3 < 0)
    {
      iVar3 = iVar3 + 0xfff;
    }
    iVar8 = (short)(-0x1000 - (short)(Data_00 >> 0xc)) * iVar8;
    local_38.vy = (local_68.newPoint)->vy + (short)(iVar3 >> 0xc);
    if (iVar8 < 0)
    {
      iVar8 = iVar8 + 0xfff;
    }
    local_30.vz = (local_68.newPoint)->vz + (short)(iVar8 >> 0xc);
    local_38.vz = local_30.vz + *(short *)Data;
    local_30.vz = local_30.vz - *(short *)(Data + 2);
    local_30.vx = local_38.vx;
    local_30.vy = local_38.vy;
    PHYSICS_CheckLineInWorld(instance, &local_68);
    if (((u_int)local_68.type - 2 < 2) || (local_68.type == 5))
    {
      if ((local_68.wNormal.vz < *(short *)(Data + 10)) && (0 < local_68.wNormal.vz))
      {
        bVar1 = true;
      }
      else
      {
        (instance->position).x = (local_68.newPoint)->vx;
        (instance->position).y = (local_68.newPoint)->vy;
      }
    }
  }
  if (local_68.type == 3)
  {
    instance->cachedBSPTree = local_68.segment;
    sVar2 = (short)((int)((int)local_68.prim - (int)((local_68.inst)->node).prev[4].prev) *
                        -0x55555555 >>
                    2);
  }
  else
  {
    sVar2 = -1;
  }
  instance->cachedTFace = sVar2;
  if (((u_int)local_68.type - 2 < 2) || (local_68.type == 5))
  {
    if ((Mode & 7U) != 0)
    {
      if (bVar1)
      {
        *(short *)(Data + 4) = (local_68.newPoint)->vx - (instance->position).x;
        *(short *)(Data + 6) = (local_68.newPoint)->vy - (instance->position).y;
      }
      else
      {
        *(undefined2 *)(Data + 4) = 0;
        *(undefined2 *)(Data + 6) = 0;
      }
      *(short *)(Data + 8) = (local_68.newPoint)->vz - (instance->position).z;
    }
    if (((Mode & 2U) != 0) && (!bVar1))
    {
      INSTANCE_Query(instance, 0x4010008, Data);
    }
    if (bVar1)
    {
      if ((Mode & 2U) != 0)
      {
        INSTANCE_Query(instance, 0x4010200, Data);
      }
      uVar9 = 0x100000;
    }
    if (((Mode & 4U) != 0) &&
        (((Data_00 = CheckPhysObFamily(instance), Data_00 == 0 ||
                                                      (Data_00 = CheckPhysObAbility(instance, 1), Data_00 == 0)) ||
          (instance->attachedID == 0))))
    {
      PhysicsDefaultGravityResponse(instance, (evPhysicsGravityData *)Data);
    }
    if (local_68.type == 1)
    {
      (instance->wNormal).x = 0;
      (instance->wNormal).y = 0;
      (instance->wNormal).z = 0x1000;
    }
    else
    {
      (instance->wNormal).x = local_68.wNormal.vx;
      (instance->wNormal).y = local_68.wNormal.vy;
      (instance->wNormal).z = local_68.wNormal.vz;
    }
    if (((local_68.type == 3) || (local_68.inst == (_Instance *)0x0)) ||
        (((local_68.inst)->object->oflags & 0x400U) == 0))
    {
      if ((instance->attachedID != 0) &&
          (p_Var4 = INSTANCE_Deactivate(instance->attachedID), p_Var4 != (_Instance *)0x0))
      {
        p_Var4->flags2 = p_Var4->flags2 & 0xffffff7f;
      }
      instance->attachedID = 0;
    }
    else
    {
      Data_00 = SetPhysicsSlideData(local_68.inst, (int)local_68.segment, (_SVector *)0x0,
                                    (_SVector *)0x0);
      uVar5 = SetPhysicsLinkedMoveData(instance, Data_00, Mode);
      uVar9 = uVar9 | uVar5;
    }
    if ((instance->flags2 & 0x40U) != 0)
    {
      sVar2 = (instance->position).z;
      *(u_char *)&instance->shadowPosition = *(u_char *)&instance->position;
      (instance->shadowPosition).z = sVar2;
      instance->flags = instance->flags | 0x8000000;
    }
    if (local_68.type == 3)
    {
      if (instance->tface != local_68.prim)
      {
        instance->oldTFace = instance->tface;
        instance->tface = local_68.prim;
        *(_Instance **)&instance->tfaceLevel = local_68.inst;
        instance->bspTree = (int)local_68.segment;
        if (local_68.segment == 0)
        {
          uVar9 = uVar9 | 0x80000;
        }
      }
    }
    else
    {
      if (instance->tface != (_TFace *)0x0)
      {
        instance->oldTFace = instance->tface;
        instance->tface = (_TFace *)0x0;
        instance->tfaceLevel = (void *)0x0;
        instance->bspTree = 0;
      }
    }
    uVar9 = uVar9 | 1;
  }
  else
  {
    if (instance->tface != (_TFace *)0x0)
    {
      instance->oldTFace = instance->tface;
      instance->tface = (_TFace *)0x0;
      instance->tfaceLevel = (void *)0x0;
      instance->bspTree = 0;
    }
    instance->attachedID = 0;
    if ((Mode & 2U) != 0)
    {
      INSTANCE_Query(instance, 0x4000001, Data);
    }
  }
  return uVar9;
}

void PhysicsDefaultGravityResponse(_Instance *instance, evPhysicsGravityData *Data)

{
  (instance->position).x = (instance->position).x + Data->x;
  (instance->position).y = (instance->position).y + Data->y;
  if ((instance == gameTrackerX.playerInstance) && (0x80 < Data->z))
  {
    (instance->position).z = (instance->position).z + 0x80;
    return;
  }
  (instance->position).z = (instance->position).z + Data->z;
  return;
}

int PhysicsCheckEdgeGrabbing(_Instance *instance, GameTracker *gameTracker, int Data, short Mode)

{
  u_char uVar1;
  u_char uVar2;
  u_char uVar3;
  bool bVar4;
  u_int uVar5;
  u_char in_zero;
  u_char in_at;
  u_short uVar6;
  u_short *puVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  short local_78;
  short local_74;
  short local_70;
  _PCollideInfo local_68;
  u_char local_38;
  u_int local_34;
  int local_30;
  u_int local_2c;

  iVar9 = 0;
  bVar4 = true;
  if ((Mode & 1U) != 0)
  {
    *(u_char *)(Data + 0x18) = 0;
  }
  local_68.oldPoint = (SVECTOR *)&local_38;
  local_68.newPoint = (SVECTOR *)&local_30;
  puVar7 = (u_short *)INSTANCE_Post(instance, 7);
  if (puVar7 == (u_short *)0x0)
  {
    pTempMat_41 = instance->matrix;
  }
  else
  {
    pTempMat_41 = (MATRIX *)&TempMat_40;
    RotMatrixY(puVar7, &TempMat_40);
  }
  PHYSICS_GenericLineCheckMask(0, 0, (short)(((u_int) * (u_short *)Data + (u_int) * (u_short *)(Data + 4)) * 0x10000 >> 0x10),
                               (SVECTOR *)&local_38);
  PHYSICS_GenericLineCheckMask(0, *(short *)(Data + 2),
                               (short)(((u_int) * (u_short *)Data + (u_int) * (u_short *)(Data + 4)) * 0x10000 >> 0x10),
                               (SVECTOR *)&local_30);
  PHYSICS_GenericLineCheck(instance, instance->matrix, pTempMat_41, &local_68);
  iVar8 = PHYSICS_CheckForObjectCollide(&local_68);
  bVar10 = iVar8 != 0;
  if (local_68.type == 0)
  {
    PHYSICS_GenericLineCheckMask(0, 0, *(short *)(Data + 4), (SVECTOR *)&local_38);
    PHYSICS_GenericLineCheckMask(0, 0, (short)(((u_int) * (u_short *)Data + (u_int) * (u_short *)(Data + 4) + 0x80) * 0x10000 >> 0x10), (SVECTOR *)&local_30);
    PHYSICS_GenericLineCheck(instance, instance->matrix, pTempMat_41, &local_68);
    if (local_68.type == 0)
      goto LAB_80075094;
  }
  bVar4 = false;
LAB_80075094:
  if ((bVar4) || (bVar10))
  {
    uVar5 = local_2c & 0xffff0000;
    local_2c = uVar5 | *(u_short *)Data;
    setCopControlWord(2, 0, *(u_char *)pTempMat_41->m);
    setCopControlWord(2, 0x800, *(u_char *)(pTempMat_41->m + 2));
    setCopControlWord(2, 0x1000, *(u_char *)(pTempMat_41->m + 4));
    setCopControlWord(2, 0x1800, *(u_char *)(pTempMat_41->m + 6));
    setCopControlWord(2, 0x2000, *(u_char *)(pTempMat_41->m + 8));
    setCopReg(2, in_zero, 0);
    setCopReg(2, in_at, local_2c);
    copFunction(2, 0x486012);
    uVar1 = getCopReg(2, 0x19);
    uVar2 = getCopReg(2, 0x1a);
    uVar3 = getCopReg(2, 0x1b);
    local_78 = (short)uVar1;
    local_74 = (short)uVar2;
    local_38 = CONCAT22((instance->position).y + local_74, (instance->position).x + local_78);
    local_70 = (short)uVar3;
    local_34 = local_34 & 0xffff0000 | (u_int)(u_short)((instance->position).z + local_70);
    local_30 = (u_int) * (u_short *)(Data + 2) << 0x10;
    local_2c = uVar5 | *(u_short *)Data;
    setCopControlWord(2, 0, *(u_char *)pTempMat_41->m);
    setCopControlWord(2, 0x800, *(u_char *)(pTempMat_41->m + 2));
    setCopControlWord(2, 0x1000, *(u_char *)(pTempMat_41->m + 4));
    setCopControlWord(2, 0x1800, *(u_char *)(pTempMat_41->m + 6));
    setCopControlWord(2, 0x2000, *(u_char *)(pTempMat_41->m + 8));
    setCopReg(2, in_zero, local_30);
    setCopReg(2, in_at, local_2c);
    copFunction(2, 0x486012);
    uVar1 = getCopReg(2, 0x19);
    uVar2 = getCopReg(2, 0x1a);
    uVar3 = getCopReg(2, 0x1b);
    local_78 = (short)uVar1;
    local_74 = (short)uVar2;
    local_30 = CONCAT22((instance->position).y + local_74, (instance->position).x + local_78);
    local_70 = (short)uVar3;
    local_2c = uVar5 | (u_short)((instance->position).z + local_70);
    PHYSICS_CheckLineInWorld(instance, &local_68);
    iVar8 = PHYSICS_CheckFaceStick(&local_68);
    if ((iVar8 == 0) && (((local_68.type == 3 || (local_68.type == 5)) || (local_68.type == 2))))
    {
      iVar9 = PHYSICS_CheckForObjectCollide(&local_68);
      uVar5 = local_34;
      if (iVar9 != 0)
      {
        bVar10 = (bool)(bVar10 + '\x01');
      }
      if ((Mode & 1U) != 0)
      {
        **(short **)(Data + 0xc) = local_68.wNormal.vx;
        *(short *)(*(int *)(Data + 0xc) + 2) = local_68.wNormal.vy;
        *(short *)(*(int *)(Data + 0xc) + 4) = local_68.wNormal.vz;
        *(short *)(*(int *)(Data + 0x14) + 2) = (local_68.newPoint)->vy - (local_68.oldPoint)->vy;
        **(short **)(Data + 0x14) = (local_68.newPoint)->vx - (local_68.oldPoint)->vx;
        if ((local_68.type == 5) || (local_68.type == 2))
        {
          *(_Instance **)(Data + 0x18) = local_68.inst;
        }
      }
      iVar9 = 2;
      local_34 = local_34 & 0xffff0000;
      setCopControlWord(2, 0, *(u_char *)pTempMat_41->m);
      setCopControlWord(2, 0x800, *(u_char *)(pTempMat_41->m + 2));
      setCopControlWord(2, 0x1000, *(u_char *)(pTempMat_41->m + 4));
      setCopControlWord(2, 0x1800, *(u_char *)(pTempMat_41->m + 6));
      setCopControlWord(2, 0x2000, *(u_char *)(pTempMat_41->m + 8));
      setCopReg(2, in_zero, 0xfff00000);
      setCopReg(2, in_at, local_34);
      copFunction(2, 0x486012);
      uVar1 = getCopReg(2, 0x19);
      uVar2 = getCopReg(2, 0x1a);
      uVar3 = getCopReg(2, 0x1b);
      local_78 = (short)uVar1;
      local_78 = (local_68.newPoint)->vx + local_78;
      local_74 = (short)uVar2;
      local_70 = (short)uVar3;
      local_74 = (local_68.newPoint)->vy + local_74;
      local_30 = CONCAT22(local_74, local_78);
      local_38 = CONCAT22(local_74, local_78);
      uVar6 = (local_68.newPoint)->vz + local_70;
      local_2c = local_2c & 0xffff0000 | (u_int)uVar6;
      local_34 = uVar5 & 0xffff0000 | (u_int)(u_short)(uVar6 + *(short *)(Data + 4));
      PHYSICS_CheckLineInWorld(instance, &local_68);
      iVar8 = PHYSICS_CheckFaceStick(&local_68);
      if ((iVar8 == 0) && (((local_68.type == 3 || (local_68.type == 5)) || (local_68.type == 2))))
      {
        if ((Mode & 1U) != 0)
        {
          **(short **)(Data + 0x10) = local_68.wNormal.vx;
          *(short *)(*(int *)(Data + 0x10) + 2) = local_68.wNormal.vy;
          *(short *)(*(int *)(Data + 0x10) + 4) = local_68.wNormal.vz;
          *(short *)(*(int *)(Data + 0x14) + 4) = (local_68.newPoint)->vz - (local_68.oldPoint)->vz;
          if ((local_68.type == 5) || (local_68.type == 2))
          {
            *(_Instance **)(Data + 0x18) = local_68.inst;
          }
        }
        if (0xb50 < local_68.wNormal.vz)
        {
          iVar9 = 6;
          if ((Mode & 2U) != 0)
          {
            INSTANCE_Query(instance, 0x4010010, Data);
          }
          if ((Mode & 4U) != 0)
          {
            PhysicsDefaultCheckSwimResponse(instance, (evPhysicsEdgeData *)Data, 0);
          }
        }
      }
    }
  }
  else
  {
    if (((local_68.type == 3) || (local_68.type == 5)) || (local_68.type == 2))
    {
      if ((Mode & 1U) != 0)
      {
        **(short **)(Data + 0xc) = local_68.wNormal.vx;
        *(short *)(*(int *)(Data + 0xc) + 2) = local_68.wNormal.vy;
        *(short *)(*(int *)(Data + 0xc) + 4) = local_68.wNormal.vz;
        *(short *)(*(int *)(Data + 0x14) + 2) = (local_68.newPoint)->vy - (local_68.oldPoint)->vy;
        **(short **)(Data + 0x14) = (local_68.newPoint)->vx - (local_68.oldPoint)->vx;
        *(undefined2 *)(*(int *)(Data + 0x14) + 4) = 0;
        if ((local_68.type == 5) || (local_68.type == 2))
        {
          *(_Instance **)(Data + 0x18) = local_68.inst;
        }
      }
      iVar9 = 2;
    }
  }
  if (((Mode & 2U) != 0) && (bVar10 == true))
  {
    INSTANCE_Query(instance, 0x4000011, Data);
  }
  return iVar9;
}

void PhysicsDefaultCheckSwimResponse(_Instance *instance, evPhysicsEdgeData *Data, int blockFlag)

{
  short sVar1;
  u_char uVar2;
  u_char uVar3;
  u_char uVar4;
  u_char in_zero;
  u_char in_at;
  int iVar5;
  _SVector *p_Var6;
  _SVector local_58;
  _G2EulerAngles_Type local_50;
  short local_48;
  short local_44;
  short local_40;
  u_int local_38;
  u_char local_34;
  u_char local_30;
  u_char local_2c;
  u_char local_28;
  u_char local_18;
  u_char local_14;

  if (blockFlag == 0)
  {
    local_58.x = Data->Normal1->x;
    local_58.y = Data->Normal1->y;
    local_58.z = 0;
    MATH3D_RotateAxisToVector((MATRIX *)(_G2Matrix_Type *)&local_38, instance->matrix + 1, &local_58, AXIS_Y);
    G2EulerAngles_FromMatrix(&local_50, (_G2Matrix_Type *)&local_38, 0);
    (instance->rotation).x = 0;
  }
  else
  {
    local_58.z = 0;
    local_58.y = 0;
    local_58.x = 0;
    sVar1 = Data->Normal1->y;
    if (sVar1 < 0x201)
    {
      if (sVar1 < -0x200)
      {
        local_58.y = -0x1000;
        local_50.z = -0x800;
      }
    }
    else
    {
      local_58.y = 0x1000;
      local_50.z = 0;
    }
    sVar1 = Data->Normal1->x;
    if (sVar1 < 0x201)
    {
      if (sVar1 < -0x200)
      {
        local_58.x = -0x1000;
        local_50.z = 0x400;
      }
    }
    else
    {
      local_58.x = 0x1000;
      local_50.z = -0x400;
    }
    local_50.y = 0;
    local_50.x = 0;
    MATH3D_RotateAxisToVector((MATRIX *)&local_38, instance->matrix, &local_58, AXIS_Y);
    (instance->rotation).x = 0;
  }
  (instance->rotation).y = 0;
  (instance->rotation).z = local_50.z;
  Data->zRot = (int)local_50.z;
  local_14 = CONCAT22(local_14._2_2_, Data->ZDistance);
  local_18 = *(u_char *)&Data->XDistance;
  RotMatrixY((u_short *)&instance->rotation, (u_int *)&local_38);
  setCopControlWord(2, 0, local_38);
  setCopControlWord(2, 0x800, local_34);
  setCopControlWord(2, 0x1000, local_30);
  setCopControlWord(2, 0x1800, local_2c);
  setCopControlWord(2, 0x2000, local_28);
  setCopReg(2, in_zero, local_18);
  setCopReg(2, in_at, local_14);
  copFunction(2, 0x486012);
  uVar2 = getCopReg(2, 0x19);
  uVar3 = getCopReg(2, 0x1a);
  uVar4 = getCopReg(2, 0x1b);
  p_Var6 = Data->Delta;
  iVar5 = (int)p_Var6->x * (int)local_58.x + (int)p_Var6->y * (int)local_58.y +
              (int)p_Var6->z * (int)local_58.z >>
          0xc;
  p_Var6->x = (short)(iVar5 * (int)local_58.x >> 0xc);
  Data->Delta->y = (short)(iVar5 * local_58.y >> 0xc);
  local_40 = (short)uVar4;
  (instance->position).z =
      (instance->position).z -
      (local_40 - (Data->Delta->z + Data->UpperOffset + Data->AboveOffset));
  local_48 = (short)uVar2;
  (instance->position).x = (instance->position).x + (Data->Delta->x - local_48);
  local_44 = (short)uVar3;
  (instance->position).y = (instance->position).y - (local_44 - Data->Delta->y);
  return;
}

int PhysicsCheckSliding(_Instance *instance, int Data, short Mode)

{
  Level *pLVar1;
  int iVar2;
  u_int uVar3;
  short local_78;
  short local_74;
  short local_70;
  _SVector local_68;
  _PCollideInfo local_60;
  SVECTOR local_30;
  SVECTOR local_28;

  local_60.oldPoint = &local_30;
  local_60.newPoint = &local_28;
  pTempMat_46 = instance->matrix + *(short *)(Data + 0x18);
  local_30.vx = *(short *)pTempMat_46->t;
  local_30.vy = *(short *)(pTempMat_46->t + 1);
  uVar3 = 0;
  local_30.vz = *(short *)(pTempMat_46->t + 2) + *(short *)(Data + 0x1e);
  if (instance->tface == (_TFace *)0x0)
  {
    local_68.x = 0;
    local_68.y = 0;
    local_68.z = 0x1000;
  }
  else
  {
    pLVar1 = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
    COLLIDE_GetNormal(instance->tface->normal, (short *)pLVar1->terrain->normalList, &local_68);
  }
  iVar2 = (int)*(short *)Data * (int)local_68.x + (int)*(short *)(Data + 2) * (int)local_68.y +
          (int)*(short *)(Data + 4) * (int)local_68.z;
  *(int *)(Data + 0x24) = iVar2;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xfff;
  }
  *(int *)(Data + 0x24) = iVar2 >> 0xc;
  iVar2 = (iVar2 >> 0xc) * (int)local_68.x;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xfff;
  }
  local_78 = *(short *)Data - (short)(iVar2 >> 0xc);
  iVar2 = *(int *)(Data + 0x24) * (int)local_68.y;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xfff;
  }
  local_74 = *(short *)(Data + 2) - (short)(iVar2 >> 0xc);
  iVar2 = *(int *)(Data + 0x24) * (int)local_68.z;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xfff;
  }
  local_70 = *(short *)(Data + 4) - (short)(iVar2 >> 0xc);
  local_28.vx = local_30.vx + local_78;
  local_28.vy = local_30.vy + local_74;
  local_28.vz = local_30.vz + local_70;
  PHYSICS_CheckLineInWorld(instance, &local_60);
  if ((local_60.type == 3) || (local_60.type == 5))
  {
    if ((Mode & 1U) != 0)
    {
      *(short *)(Data + 8) = local_60.wNormal.vx;
      *(short *)(Data + 10) = local_60.wNormal.vy;
      *(short *)(Data + 0xc) = local_60.wNormal.vz;
      *(short *)Data = local_30.vx - local_28.vx;
      *(short *)(Data + 2) = local_30.vy - local_28.vy;
      *(short *)(Data + 4) = local_30.vz - local_28.vz;
    }
    local_30.vx = *(short *)pTempMat_46->t + local_78;
    local_30.vy = *(short *)(pTempMat_46->t + 1) + local_74;
    local_28.vz = local_70 + *(short *)(pTempMat_46->t + 2) + *(short *)(Data + 0x1e);
    local_30.vz = local_28.vz + *(short *)(Data + 0x1c);
    local_28.vx = local_30.vx;
    local_28.vy = local_30.vy;
    PHYSICS_CheckLineInWorld(instance, &local_60);
    uVar3 = 2;
    if ((local_60.type == 3) || (local_60.type == 5))
    {
      if ((Mode & 1U) != 0)
      {
        *(short *)(Data + 0x10) = local_60.wNormal.vx;
        *(short *)(Data + 0x12) = local_60.wNormal.vy;
        *(short *)(Data + 0x14) = local_60.wNormal.vz;
        *(short *)(Data + 0x1e) = local_30.vz - local_28.vz;
      }
      uVar3 = 6;
    }
    local_60.type = 0;
  }
  else
  {
    if (local_60.type == 0)
    {
      local_30.vx = *(short *)pTempMat_46->t + local_78;
      local_30.vy = *(short *)(pTempMat_46->t + 1) + local_74;
      local_30.vz = local_70 + *(short *)(pTempMat_46->t + 2) + *(short *)(Data + 0x1e);
      local_28.vz = local_30.vz - *(short *)(Data + 0x1a);
      local_28.vx = local_30.vx;
      local_28.vy = local_30.vy;
      PHYSICS_CheckLineInWorld(instance, &local_60);
      if ((local_60.type == 3) || (local_60.type == 5))
      {
        if ((Mode & 1U) != 0)
        {
          *(short *)(Data + 0x10) = local_60.wNormal.vx;
          *(short *)(Data + 0x12) = local_60.wNormal.vy;
          *(short *)(Data + 0x14) = local_60.wNormal.vz;
          *(short *)(Data + 0x1e) = local_30.vz - local_28.vz;
        }
        uVar3 = 0x4000;
      }
    }
  }
  local_30.vx = *(short *)pTempMat_46->t;
  local_30.vy = *(short *)(pTempMat_46->t + 1);
  local_30.vz = *(short *)(pTempMat_46->t + 2);
  local_28.vz = local_30.vz + *(short *)(Data + 0x1c);
  local_28.vx = local_30.vx;
  local_28.vy = local_30.vy;
  PHYSICS_CheckLineInWorld(instance, &local_60);
  if (local_60.type != 0)
  {
    uVar3 = uVar3 | 0x8000;
  }
  if (local_60.type == 5)
  {
    if ((Mode & 1U) != 0)
    {
      *(_Instance **)(Data + 0x20) = local_60.inst;
    }
  }
  else
  {
    *(u_char *)(Data + 0x20) = 0;
  }
  return uVar3;
}

int PhysicsUpdateTface(_Instance *instance, int Data)

{
  int iVar1;
  _PCollideInfo local_48;
  SVECTOR local_18;
  SVECTOR local_10;

  local_48.oldPoint = &local_18;
  local_48.newPoint = &local_10;
  local_18.vx = (instance->position).x;
  local_18.vy = (instance->position).y;
  local_10.vz = (instance->position).z;
  local_18.vz = local_10.vz + *(short *)Data;
  local_10.vz = local_10.vz - *(short *)(Data + 2);
  local_10.vx = local_18.vx;
  local_10.vy = local_18.vy;
  PHYSICS_CheckLineInWorld(instance, &local_48);
  if (local_48.type == 3)
  {
    if (instance->tface != local_48.prim)
    {
      instance->oldTFace = instance->tface;
      instance->tface = local_48.prim;
      *(_Instance **)&instance->tfaceLevel = local_48.inst;
      instance->bspTree = (int)local_48.segment;
    }
    iVar1 = 1;
  }
  else
  {
    if (instance->tface != (_TFace *)0x0)
    {
      instance->oldTFace = instance->tface;
      instance->tface = (_TFace *)0x0;
      instance->tfaceLevel = (void *)0x0;
      instance->bspTree = 0;
    }
    iVar1 = 0;
  }
  return iVar1;
}

int PhysicsCheckDropOff(_Instance *instance, GameTracker *gameTracker, int Data, short Mode)

{
  MATRIX *pMVar1;
  int iVar2;
  int local_78;
  int local_74;
  int local_70;
  _PCollideInfo local_68;
  SVECTOR local_38;
  SVECTOR local_30;
  undefined2 local_28;
  undefined2 local_26;

  local_68.oldPoint = &local_38;
  *(u_char *)(Data + 0x20) = 0;
  *(u_char *)(Data + 0x18) = 0;
  local_68.newPoint = &local_30;
  PHYSICS_GenericLineCheckMask(0, 0, 0, local_68.oldPoint);
  PHYSICS_GenericLineCheckMask(0, *(short *)(Data + 2), 0, &local_30);
  PHYSICS_GenericLineCheck(instance, instance->matrix + 1, instance->matrix, &local_68);
  pTempMat_51 = instance->matrix;
  if (((local_68.type == 3) || (local_68.type == 5)) || (local_68.type == 2))
  {
    local_28 = 0;
    local_26 = 0xf000;
    ApplyMatrixSV(pTempMat_51, &local_28, &local_78);
    iVar2 = local_68.wNormal.vx * local_78 + local_68.wNormal.vy * local_74 +
            local_68.wNormal.vz * local_70;
    if (iVar2 < 0)
    {
      iVar2 = iVar2 + 0xfff;
    }
    if (((local_68.type == 3) && (*(u_short *)((int)local_68.prim + 10) != 0xffff)) &&
        ((*(u_short *)((int)&((local_68.inst)->node).prev[6].next[1].prev +
                       (u_int) * (u_short *)((int)local_68.prim + 10) + 2) &
          0x1000) != 0))
    {
      if (-0xec8 < iVar2 >> 0xc)
        goto LAB_80076164;
    }
    else
    {
      if (-0xfc1 < iVar2 >> 0xc)
        goto LAB_80076164;
    }
    if ((Mode & 1U) != 0)
    {
      **(short **)(Data + 0xc) = local_68.wNormal.vx;
      *(short *)(*(int *)(Data + 0xc) + 2) = local_68.wNormal.vy;
      *(short *)(*(int *)(Data + 0xc) + 4) = local_68.wNormal.vz;
      *(short *)(*(int *)(Data + 0x14) + 2) = (local_68.newPoint)->vy;
      **(short **)(Data + 0x14) = (local_68.newPoint)->vx;
      *(short *)(*(int *)(Data + 0x14) + 4) = (local_68.newPoint)->vz;
    }
    if (((local_68.type == 3) && (*(u_short *)((int)local_68.prim + 10) != 0xffff)) &&
        ((*(u_short *)((int)&((local_68.inst)->node).prev[6].next[1].prev +
                       (u_int) * (u_short *)((int)local_68.prim + 10) + 2) &
          0x1000) != 0))
    {
      *(u_int *)(Data + 0x20) = *(u_int *)(Data + 0x20) | 0x20000;
    }
    pMVar1 = pTempMat_51;
    *(u_int *)(Data + 0x20) = *(u_int *)(Data + 0x20) | 2;
    local_38.vx = 0;
    local_38.vy = -0x10;
    local_38.vz = 0;
    ApplyMatrixSV(pMVar1, &local_38, &local_78);
    local_38.vx = (local_68.newPoint)->vx + (short)local_78;
    local_38.vy = (local_68.newPoint)->vy + (short)local_74;
    local_30.vz = (local_68.newPoint)->vz + (short)local_70;
    local_38.vz = local_30.vz + *(short *)(Data + 4);
    local_30.vx = local_38.vx;
    local_30.vy = local_38.vy;
    PHYSICS_CheckLineInWorld(instance, &local_68);
    if ((local_68.type == 3) || (local_68.type == 5))
    {
      if ((Mode & 1U) != 0)
      {
        **(short **)(Data + 0x10) = local_68.wNormal.vx;
        *(short *)(*(int *)(Data + 0x10) + 2) = local_68.wNormal.vy;
        *(short *)(*(int *)(Data + 0x10) + 4) = local_68.wNormal.vz;
      }
      if (0xb50 < local_68.wNormal.vz)
      {
        *(u_int *)(Data + 0x20) = *(u_int *)(Data + 0x20) | 4;
      }
    }
    if ((Mode & 2U) != 0)
    {
      INSTANCE_Query(instance, 0x4010400, Data);
    }
  }
LAB_80076164:
  return *(int *)(Data + 0x20);
}

int PhysicsCheckSwim(_Instance *instance, int Data, short Mode)

{
  Level *level;
  long lVar1;
  int iVar2;
  short sVar3;
  short sVar4;
  _PCollideInfo local_60;
  SVECTOR local_30;
  SVECTOR local_28;

  level = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
  lVar1 = STREAM_GetLevelWithID(level, instance);
  sVar4 = (short)instance->matrix[1].t[2] - (short)lVar1;
  if (lVar1 == -0x7fff)
  {
    sVar4 = 1;
    sVar3 = -0x7fff;
  }
  else
  {
    sVar3 = -0x7fff;
    if (lVar1 == 0x7fff)
    {
      sVar4 = -0x7fff;
    }
    else
    {
      if (*(short *)Data == 0)
      {
        *(short *)(Data + 0xc) = sVar4;
        sVar3 = (short)instance->matrix->t[2] - (short)lVar1;
        *(short *)(Data + 0xe) = sVar3;
      }
      else
      {
        local_60.newPoint = &local_28;
        local_30.vx = *(short *)instance->matrix[1].t;
        local_30.vy = *(short *)(instance->matrix[1].t + 1);
        local_30.vz = *(short *)(instance->matrix[1].t + 2);
        local_28.vz = local_30.vz + *(short *)(Data + 4) * -4;
        gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x8000;
        local_30.vz = local_30.vz + *(short *)(Data + 6);
        instance->waterFace = (_TFace *)0x0;
        local_60.oldPoint = &local_30;
        local_28.vx = local_30.vx;
        local_28.vy = local_30.vy;
        PHYSICS_CheckLineInWorld(instance, &local_60);
        gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffff7fff;
        if (local_60.type == 0)
        {
          sVar3 = sVar4 + *(short *)(Data + 4) * -4;
        }
        else
        {
          sVar3 = (sVar4 + (local_60.newPoint)->vz) - (short)instance->matrix[1].t[2];
        }
      }
    }
  }
  if ((Mode & 3U) != 0)
  {
    *(short *)(Data + 0xc) = sVar4;
    *(short *)(Data + 0xe) = sVar3;
  }
  *(long *)(Data + 0x14) = lVar1;
  iVar2 = PhysicsDefaultEdgeGrabResponse(instance, (evPhysicsSwimData *)Data);
  *(undefined2 *)(Data + 0x10) = (short)iVar2;
  if ((Mode & 2U) != 0)
  {
    INSTANCE_Query(instance, 0x4020000, Data);
  }
  FX_UpdateInstanceWaterSplit(instance);
  return iVar2;
}

int PhysicsDefaultEdgeGrabResponse(_Instance *instance, evPhysicsSwimData *Data)

{
  u_int uVar1;
  int iVar2;

  STREAM_GetWaterZLevel(instance->currentStreamUnitID);
  iVar2 = Data->WaterLevel;
  uVar1 = (u_int)(-(int)Data->WadeDepth < (int)Data->WaterDepth) << 7;
  if ((-(int)Data->TreadDepth < (int)Data->Depth) && ((int)Data->Depth < 0))
  {
    uVar1 = uVar1 | 0x40;
  }
  if ((int)Data->Depth < -(int)Data->SwimDepth)
  {
    uVar1 = uVar1 | 0x10;
  }
  if (0 < (int)Data->Depth)
  {
    uVar1 = uVar1 | 0x20;
  }
  if ((((instance->position).z < iVar2) && (iVar2 < (instance->oldPos).z)) &&
      (Data->iVelocity->z < 0))
  {
    SIGNAL_InWater(instance);
    uVar1 = uVar1 | 0x100;
  }
  if (((instance->matrix != (MATRIX *)0x0) && (instance->oldMatrix != (MATRIX *)0x0)) &&
      ((iVar2 < instance->matrix[1].t[2] && (instance->oldMatrix[1].t[2] < iVar2))))
  {
    SIGNAL_OutOfWater(instance);
    uVar1 = uVar1 | 0x200;
  }
  if (((iVar2 < (instance->position).z) && ((instance->oldPos).z < iVar2)) &&
      (0 < Data->iVelocity->z))
  {
    uVar1 = uVar1 | 0x400;
  }
  if ((((instance->matrix != (MATRIX *)0x0) && (instance->oldMatrix != (MATRIX *)0x0)) &&
       (iVar2 = iVar2 - Data->SwimDepth, instance->matrix[1].t[2] < iVar2)) &&
      ((iVar2 < instance->oldMatrix[1].t[2] && (Data->iVelocity->z < 0))))
  {
    uVar1 = uVar1 | 0x800;
  }
  return uVar1;
}

void PhysicsForceSetWater(_Instance *instance, int *Time, int Depth, int rate, int maxAmplitude)

{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar3 = Depth;
  if (Depth < -0xc00)
  {
    iVar3 = -0xc00;
  }
  if (0 < iVar3)
  {
    iVar3 = 0;
  }
  iVar1 = iVar3 * maxAmplitude >> 0x1f;
  gameTrackerX.timeMult;
  *Time = iVar2;
  if (0x1000 < iVar2)
  {
    *Time = iVar2 + -0x1000;
  }
  if (Depth < 0)
  {
    iVar2 = rcos(*Time);
 6 + iVar1 >> 9)) * iVar2;
 if (iVar2 < 0)
 {
   iVar2 = iVar2 + 0xfff;
 }
 (instance->position).z = (instance->position).z + (short)(iVar2 >> 0xc);
  }
  return;
}

int PhysicsCheckDropHeight(_Instance *instance, int Data, int Mode)

{
  _PCollideInfo local_38;

  local_38.oldPoint = (SVECTOR *)(Data + 8);
  local_38.newPoint = (SVECTOR *)Data;
  PHYSICS_CheckLineInWorld(instance, &local_38);
  return (u_int)(local_38.type == 0);
}

int PhysicsCheckLOS(_Instance *instance, int Data, int Mode)

{
  u_short *puVar1;
  Level *level;
  int iVar2;
  int iVar3;
  int iVar4;
  SVECTOR local_68;
  SVECTOR local_60;
  _PCollideInfo local_58;
  short local_28[2];
  short local_24;
  short local_20;

  if ((*(u_short *)(Data + 6) & 0x20) == 0)
  {
    if ((*(u_short *)(Data + 6) & 0x10) == 0)
    {
      local_60.vx = *(short *)Data;
      local_60.vy = *(short *)(Data + 2);
      local_60.vz = *(short *)(Data + 4);
    }
    else
    {
      local_60.vx = (instance->position).x + *(short *)Data;
      local_60.vy = (instance->position).y + *(short *)(Data + 2);
      local_60.vz = (instance->position).z + *(short *)(Data + 4);
    }
  }
  else
  {
    puVar1 = (u_short *)INSTANCE_Post(instance, 8);
    if (puVar1 == (u_short *)0x0)
    {
      pTempMat_63 = instance->matrix;
    }
    else
    {
      pTempMat_63 = (MATRIX *)&TempMat_62;
      RotMatrixY(puVar1, &TempMat_62);
      MulMatrix2((u_char *)instance->matrix, (u_int *)pTempMat_63);
    }
    ApplyMatrixSV(pTempMat_63, Data, local_28);
    local_60.vx = (instance->position).x + local_28[0];
    local_60.vy = (instance->position).y + local_24;
    local_60.vz = (instance->position).z + local_20;
  }
  level = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
  if (((*(u_short *)(Data + 6) & 0x40) == 0) ||
      (iVar2 = STREAM_GetLevelWithID(level, instance), iVar2 == -0x7fff))
  {
    iVar4 = 0;
    iVar2 = (int)local_60.vz - (int)*(short *)(Data + 8);
  }
  else
  {
    iVar3 = (int)local_60.vz - (int)*(short *)(Data + 8);
    iVar4 = 0x10;
    if (iVar2 <= iVar3)
    {
      iVar4 = 0;
      iVar2 = iVar3;
    }
  }
  if (iVar2 < local_60.vz)
  {
    local_68.vz = (short)iVar2;
    local_58.oldPoint = &local_60;
    local_58.newPoint = &local_68;
    local_68.vx = local_60.vx;
    local_68.vy = local_60.vy;
    PHYSICS_CheckLineInWorld(instance, &local_58);
    if (((local_58.type != 0) && (0xb50 < local_58.wNormal.vz)) && (iVar4 = 1, Mode == 1))
    {
      if (local_58.type == 3)
      {
        *(NodeType **)(Data + 0xc) =
            (NodeType *)((int)((local_58.inst)->node).prev[9].prev + (int)local_58.segment * 0x24);
        *(void **)(Data + 0x10) = local_58.prim;
      }
      else
      {
        *(u_char *)(Data + 0xc) = 0;
        *(u_char *)(Data + 0x10) = 0;
      }
      *(short *)(Data + 10) = local_60.vz - local_68.vz;
      *(short *)(Data + 4) = local_68.vz;
      iVar4 = 1;
    }
  }
  return iVar4;
}

int PhysicsCheckBlockers(_Instance *instance, int Data, short Mode)

{
  u_short *puVar1;
  int iVar2;
  short local_68[2];
  short local_64;
  short local_60;
  _PCollideInfo local_58;
  SVECTOR local_28;
  SVECTOR local_20;

  local_58.oldPoint = &local_20;
  local_58.newPoint = &local_28;
  puVar1 = (u_short *)INSTANCE_Post(instance, 8);
  iVar2 = 0;
  if (instance->matrix != (MATRIX *)0x0)
  {
    pTempMat_67 = instance->matrix;
    if (puVar1 != (u_short *)0x0)
    {
      pTempMat_67 = (MATRIX *)&TempMat_66;
      RotMatrixY(puVar1, &TempMat_66);
      MulMatrix2((u_char *)instance->matrix, (u_int *)pTempMat_67);
    }
    local_28.vx = *(short *)Data;
    local_28.vy = *(short *)(Data + 2);
    local_28.vz = 0;
    ApplyMatrixSV(pTempMat_67, &local_28, local_68);
    local_28.vx = (instance->position).x + local_68[0];
    local_28.vy = (instance->position).y + local_64;
    local_60 = (instance->position).z + local_60;
    local_28.vz = local_60 - *(short *)(Data + 4);
    local_20.vz = local_60 + *(short *)(Data + 8);
    local_20.vx = local_28.vx;
    local_20.vy = local_28.vy;
    PHYSICS_CheckLineInWorld(instance, &local_58);
    if (((u_int)local_58.type - 2 < 2) || (local_58.type == 5))
    {
      if ((Mode & 2U) != 0)
      {
        if (*(short *)(Data + 6) < local_58.wNormal.vz)
        {
          INSTANCE_Query(instance, 0x4010080, 1);
        }
        else
        {
          INSTANCE_Query(instance, 0x4010080, 0);
          iVar2 = 8;
        }
      }
      if (((local_58.wNormal.vz < *(short *)(Data + 6)) && (0 < local_58.wNormal.vz)) &&
          ((instance->position).z < (local_58.newPoint)->vz))
      {
        INSTANCE_Query(instance, 0x4010401, 0);
      }
    }
    else
    {
      iVar2 = 0;
      if (local_58.type == 0)
      {
        if ((Mode & 2U) != 0)
        {
          INSTANCE_Query(instance, 0x4010080, 0);
        }
        iVar2 = 8;
      }
    }
  }
  return iVar2;
}

int PhysicsFollowWall(_Instance *instance, GameTracker *gameTracker, int Data, short Mode)

{
  short sVar1;
  u_int uVar2;
  int iVar3;
  short local_a0[2];
  short local_9c;
  short local_98;
  _PCollideInfo local_90;
  SVECTOR local_60;
  SVECTOR local_58;
  _Position local_50;
  _Position local_48;
  u_int auStack64[8];

  local_90.oldPoint = &local_58;
  *(u_char *)(Data + 0x28) = 0;
  pTempMat_72 = instance->matrix + *(short *)Data;
  local_90.newPoint = &local_60;
  PHYSICS_GenericLineCheckMask(0, 0x40, 0, local_90.oldPoint);
  PHYSICS_GenericLineCheckMask(0, *(short *)(Data + 2), 0, &local_60);
  PHYSICS_GenericLineCheck(instance, pTempMat_72, pTempMat_72, &local_90);
  if ((local_90.type == 3) || (local_90.type == 5))
  {
    *(u_int *)(Data + 0x28) = *(u_int *)(Data + 0x28) | 8;
    if ((Mode & 7U) != 0)
    {
      *(short *)(Data + 8) = local_90.wNormal.vx;
      *(short *)(Data + 10) = local_90.wNormal.vy;
      *(short *)(Data + 0xc) = local_90.wNormal.vz;
    }
    if ((Mode & 4U) != 0)
    {
      local_48.z = 0;
      local_48.y = 0;
      local_48.x = 0;
      local_50.x = *(short *)(Data + 8);
      local_50.y = *(short *)(Data + 10);
      local_50.z = *(short *)(Data + 0xc);
      MATH3D_RotationFromPosToPos(&local_50, &local_48, (_Rotation *)(Data + 0x1e));
      RotMatrixY((u_short *)(_Rotation *)(Data + 0x1e), auStack64);
      *(short *)(Data + 0x18) = local_60.vx;
      *(short *)(Data + 0x1a) = local_60.vy;
      *(short *)(Data + 0x1c) = local_60.vz;
      local_60.vx = 0;
      local_60.vz = 0;
      local_60.vy = -*(short *)(Data + 6);
      ApplyMatrixSV(auStack64, &local_60, local_a0);
      *(short *)(Data + 0x18) = *(short *)(Data + 0x18) + local_a0[0];
      *(short *)(Data + 0x1a) = *(short *)(Data + 0x1a) + local_9c;
      *(short *)(Data + 0x1c) = *(short *)(Data + 0x1c) + local_98;
      *(short *)(Data + 0x18) = (instance->position).x - *(short *)(Data + 0x18);
      *(short *)(Data + 0x1a) = (instance->position).y - *(short *)(Data + 0x1a);
      *(short *)(Data + 0x1c) = (instance->position).z - *(short *)(Data + 0x1c);
    }
    (instance->wNormal).x = local_90.wNormal.vx;
    (instance->wNormal).y = local_90.wNormal.vy;
    uVar2 = instance->flags2;
    (instance->wNormal).z = local_90.wNormal.vz;
    if ((uVar2 & 0x40) != 0)
    {
      (instance->shadowPosition).x = local_60.vx;
      (instance->shadowPosition).y = local_60.vy;
      instance->flags = instance->flags | 0x8000000;
      (instance->shadowPosition).z = local_60.vz;
    }
    instance->oldTFace = instance->tface;
    instance->tface = local_90.prim;
    *(_Instance **)&instance->tfaceLevel = local_90.inst;
    instance->bspTree = (int)local_90.segment;
  }
  PHYSICS_GenericLineCheckMask(0, 0x40, *(short *)(Data + 4), &local_58);
  iVar3 = (u_int) * (u_short *)(Data + 6) << 0x10;
  PHYSICS_GenericLineCheckMask(0, (short)(((u_int) * (u_short *)(Data + 2) + ((iVar3 >> 0x10) - (iVar3 >> 0x1f) >> 1)) * 0x10000 >> 0x10), *(short *)(Data + 4), &local_60);
  PHYSICS_GenericLineCheck(instance, pTempMat_72, pTempMat_72, &local_90);
  if ((local_90.type == 3) || (local_90.type == 5))
  {
    *(u_int *)(Data + 0x28) = *(u_int *)(Data + 0x28) | 2;
    if ((Mode & 7U) != 0)
    {
      *(short *)(Data + 0x10) = local_90.wNormal.vx;
      *(short *)(Data + 0x12) = local_90.wNormal.vy;
      *(short *)(Data + 0x14) = local_90.wNormal.vz;
    }
    if ((Mode & 4U) != 0)
    {
      sVar1 = MATH3D_AngleBetweenVectors((_SVector *)(Data + 8), (_SVector *)(Data + 0x10));
      *(short *)(Data + 0x26) = sVar1;
    }
    local_58.vx = 0;
    local_58.vy = -0x20;
    local_58.vz = 0;
    ApplyMatrixSV(pTempMat_72, &local_58, local_a0);
    local_58.vz = 0x40;
    local_60.vx = local_60.vx + local_a0[0];
    local_58.vx = 0;
    local_58.vy = 0;
    local_60.vy = local_60.vy + local_9c;
    local_60.vz = local_60.vz + local_98;
    ApplyMatrixSV(pTempMat_72, &local_58, local_a0);
    local_58.vx = local_60.vx + local_a0[0];
    local_58.vy = local_60.vy + local_9c;
    local_58.vz = local_60.vz + local_98;
    PHYSICS_CheckLineInWorld(instance, &local_90);
    if ((local_90.type == 3) || (local_90.type == 5))
    {
      *(u_int *)(Data + 0x28) = *(u_int *)(Data + 0x28) | 4;
    }
  }
  if ((Mode & 2U) != 0)
  {
    INSTANCE_Query(instance, 0x4010011, Data);
  }
  return *(int *)(Data + 0x28);
}

void PhysicsMoveLocalZClamp(_Instance *instance, long segment, long time, long clamp)

{
  _Position local_30;
  short local_28;
  short local_26;
  short local_24;
  short local_20;
  short local_1e;
  short local_1c;

  memset(&local_30, 0, 6);
  PhysicsDefaultLinkedMoveResponse(instance, &local_30, time);
  local_28 = local_30.x;
  local_24 = local_30.z;
  local_26 = -local_30.y;
  ApplyMatrix(instance->matrix + segment, &local_28, &local_20);
  (instance->position).x = (instance->position).x + local_20;
  (instance->position).y = (instance->position).y + local_1e;
  if (clamp == 0)
  {
    (instance->position).z = (instance->position).z + local_1c;
  }
  return;
}

void PhysicsDefaultLinkedMoveResponse(_Instance *instance, _Position *position, long time)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;

  iVar4 = instance->xAccl * time;
  iVar1 = instance->xVel;
  iVar2 = instance->yVel;
  iVar3 = instance->zVel;
  if (iVar4 < 0)
  {
    iVar4 = iVar4 + 0xfff;
  }
  iVar5 = instance->yAccl * time;
  if (iVar5 < 0)
  {
    iVar5 = iVar5 + 0xfff;
  }
  iVar6 = instance->zAccl * time;
  if (iVar6 < 0)
  {
    iVar6 = iVar6 + 0xfff;
  }
  iVar7 = iVar1 * time;
  if (iVar7 < 0)
  {
    iVar7 = iVar7 + 0xfff;
  }
  iVar8 = (iVar4 >> 0xc) * time;
  if (iVar8 < 0)
  {
    iVar8 = iVar8 + 0x1fff;
  }
  iVar9 = iVar2 * time;
  position->x = position->x + (short)(iVar7 >> 0xc) + (short)(iVar8 >> 0xd);
  if (iVar9 < 0)
  {
    iVar9 = iVar9 + 0xfff;
  }
  iVar7 = (iVar5 >> 0xc) * time;
  if (iVar7 < 0)
  {
    iVar7 = iVar7 + 0x1fff;
  }
  iVar8 = iVar3 * time;
  position->y = position->y + (short)(iVar9 >> 0xc) + (short)(iVar7 >> 0xd);
  if (iVar8 < 0)
  {
    iVar8 = iVar8 + 0xfff;
  }
  iVar7 = (iVar6 >> 0xc) * time;
  if (iVar7 < 0)
  {
    iVar7 = iVar7 + 0x1fff;
  }
  iVar1 = iVar1 + (iVar4 >> 0xc);
  iVar2 = iVar2 + (iVar5 >> 0xc);
  position->z = position->z + (short)(iVar8 >> 0xc) + (short)(iVar7 >> 0xd);
  iVar4 = instance->maxXVel;
  iVar3 = iVar3 + (iVar6 >> 0xc);
  if ((iVar4 < iVar1) || (iVar4 = -iVar4, iVar1 < iVar4))
  {
    iVar1 = iVar4;
  }
  iVar4 = instance->maxYVel;
  if ((iVar4 < iVar2) || (iVar4 = -iVar4, iVar2 < iVar4))
  {
    iVar2 = iVar4;
  }
  iVar4 = instance->maxZVel;
  if ((iVar4 < iVar3) || (iVar4 = -iVar4, iVar3 < iVar4))
  {
    iVar3 = iVar4;
  }
  instance->xVel = iVar1;
  instance->yVel = iVar2;
  instance->zVel = iVar3;
  return;
}

void PhysicsSetVelFromZRot(_Instance *instance, short angle, long magnitude)

{
  int iVar1;

  iVar1 = rcos((int)angle - 0x400U);
  instance->xVel = iVar1 * magnitude >> 0xc;
  iVar1 = rsin((int)angle - 0x400U);
  instance->yVel = iVar1 * magnitude >> 0xc;
  return;
}

void PhysicsSetVelFromRot(_Instance *instance, _Rotation *rot, long magnitude)

{
  u_int auStack56[8];
  undefined2 local_18;
  short local_16;
  undefined2 local_14;
  short local_10;
  short local_e;
  short local_c;

  local_16 = -(short)magnitude;
  local_18 = 0;
  local_14 = 0;
  RotMatrixY((u_short *)&instance->rotation, auStack56);
  ApplyMatrix(auStack56, &local_18, &local_10);
  instance->xVel = (int)local_10;
  instance->yVel = (int)local_e;
  instance->zVel = (int)local_c;
  return;
}

void PHYSICS_SetVAndAFromRot(_Instance *instance, _Rotation *rot, long v, long a)

{
  undefined2 local_48;
  short local_46;
  undefined2 local_44;
  u_int auStack64[8];
  short local_20;
  short local_1e;
  short local_1c;
  short local_18;
  short local_16;
  short local_14;

  if ((v != 0) || (a != 0))
  {
    RotMatrixY((u_short *)&instance->rotation, auStack64);
    local_48 = 0;
    local_44 = 0;
  }
  if (v == 0)
  {
    instance->xVel = 0;
    instance->yVel = 0;
    instance->zVel = 0;
  }
  else
  {
    local_46 = -(short)v;
    ApplyMatrix(auStack64, &local_48, &local_20);
    instance->xVel = (int)local_20;
    instance->yVel = (int)local_1e;
    instance->zVel = (int)local_1c;
  }
  if (a == 0)
  {
    instance->xAccl = 0;
    instance->yAccl = 0;
    instance->zAccl = 0;
  }
  else
  {
    local_46 = -(short)a;
    ApplyMatrix(auStack64, &local_48, &local_18);
    instance->xAccl = (int)local_18;
    instance->yAccl = (int)local_16;
    instance->zAccl = (int)local_14;
  }
  return;
}

long PHYSICS_FindVFromAAndD(long d, long t)

{
  int iVar1;

  if (t != 0)
  {
    (t * t);
    if (iVar1 < 0)
    {
      iVar1 = iVar1 + 0xfff;
    }
    return iVar1 >> 0xc;
  }
  return 0;
}

long PHYSICS_FindAFromDAndT(long a, long d)

{
  long lVar1;
  int square;

  square = a * d * 2;
  if (square == 0)
  {
    lVar1 = 0;
  }
  else
  {
    lVar1 = MATH3D_FastSqrt0(square);
  }
  return lVar1;
}

void PHYSICS_StopIfCloseToTarget(_Instance *instance, int x, int y, int z)

{
  if (((instance->xAccl < 0) && (instance->xVel <= x)) ||
      ((0 < instance->xAccl && (x <= instance->xVel))))
  {
    instance->xAccl = 0;
    instance->xVel = x;
  }
  if (((instance->yAccl < 0) && (instance->yVel <= y)) ||
      ((0 < instance->yAccl && (y <= instance->yVel))))
  {
    instance->yAccl = 0;
    instance->yVel = y;
  }
  if (((instance->zAccl < 0) && (instance->zVel <= z)) ||
      ((0 < instance->zAccl && (z <= instance->zVel))))
  {
    instance->zAccl = 0;
    instance->zVel = z;
  }
  return;
}

int PHYSICS_CheckForTerrainCollide(_Instance *instance, SVECTOR *startVec, SVECTOR *endVec, int segment)

{
  _PCollideInfo local_38;

  local_38.collideType = 1;
  local_38.newPoint = endVec;
  local_38.oldPoint = startVec;
  PHYSICS_GenericLineCheckSetup(instance, instance->matrix + segment, instance->matrix + segment, &local_38);
  return (u_int)(local_38.type == 3);
}

int PHYSICS_CheckForValidMove(_Instance *instance, SVECTOR *startVec, SVECTOR *endVec, int segment)

{
  _PCollideInfo local_38;

  local_38.collideType = 0x3e;
  local_38.newPoint = endVec;
  local_38.oldPoint = startVec;
  PHYSICS_GenericLineCheckSetup(instance, instance->matrix + segment, instance->matrix + segment, &local_38);
  return (u_int)(local_38.type != 0);
}

int PHYSOBS_CheckForValidMove(_Instance *instance, SVECTOR *startVec, SVECTOR *endVec, int segment)

{
  int iVar1;
  u_int uVar2;
  _PCollideInfo local_38;

  local_38.newPoint = endVec;
  local_38.oldPoint = startVec;
  PHYSICS_GenericLineCheck(instance, instance->matrix + segment, instance->matrix + segment, &local_38);
  iVar1 = PHYSICS_CheckForObjectCollide(&local_38);
  uVar2 = (u_int)(iVar1 != 0);
  if (((u_int)local_38.type - 2 < 2) || (local_38.type == 5))
  {
    uVar2 = uVar2 + 2;
  }
  return uVar2;
}

int PHYSICS_CheckForObjectCollide(_PCollideInfo *CInfo)

{
  u_short uVar1;
  u_int uVar2;

  uVar2 = 0;
  if (CInfo->type == 3)
  {
    uVar1 = *(u_short *)((int)CInfo->prim + 10);
    uVar2 = 0;
    if (uVar1 != 0xffff)
    {
      uVar2 = (u_int)((*(u_short *)((int)&(CInfo->inst->node).prev[6].next[1].prev + (u_int)uVar1 + 2) & 0x200) != 0);
    }
  }
  return uVar2;
}

int PHYSICS_CheckFaceStick(_PCollideInfo *CInfo)

{
  short sVar1;
  u_short uVar2;
  u_long uVar3;
  u_int uVar4;

  sVar1 = CInfo->type;
  uVar4 = 0;
  if (sVar1 == 3)
  {
    uVar2 = *(u_short *)((int)CInfo->prim + 10);
    if (uVar2 != 0xffff)
    {
      uVar4 = (u_int)((*(u_short *)((int)&(CInfo->inst->node).prev[6].next[1].prev + (u_int)uVar2 + 2) & 0x80) != 0);
    }
    if (((int)*(short *)((int)(CInfo->inst->node).prev[9].prev + (int)CInfo->segment * 0x24 + 0x12) & 0x8000U) == 0)
    {
      return uVar4;
    }
  }
  else
  {
    if (sVar1 == 2)
    {
      if ((*(byte *)((int)CInfo->prim + 6) & 0x80) == 0)
      {
        return 0;
      }
    }
    else
    {
      if (sVar1 != 5)
      {
        return 0;
      }
      uVar3 = INSTANCE_Post(CInfo->inst, 1);
      if ((uVar3 & 0x20) == 0)
      {
        return 0;
      }
      uVar3 = INSTANCE_Post(CInfo->inst, 3);
      if ((uVar3 & 1) != 0)
      {
        return 0;
      }
    }
  }
  return 1;
}

void PHYSICS_GenericLineCheckMask(short x, short y, short z, SVECTOR *inVec)

{
  inVec->vx = x;
  inVec->vy = y;
  inVec->vz = z;
  return;
}

void PHYSICS_GenericLineCheck(_Instance *instance, MATRIX *transMat, MATRIX *rotMat, _PCollideInfo *cInfo)

{
  cInfo->collideType = 0x3f;
  PHYSICS_GenericLineCheckSetup(instance, transMat, rotMat, cInfo);
  return;
}

void PHYSICS_GenericLineCheckSetup(_Instance *instance, MATRIX *transMat, MATRIX *rotMat, _PCollideInfo *cInfo)

{
  u_char uVar1;
  u_char uVar2;
  u_char uVar3;
  u_char in_zero;
  u_char in_at;
  SVECTOR *pSVar4;
  SVECTOR *pSVar5;
  short local_18;
  short local_14;
  short local_10;

  pSVar4 = cInfo->oldPoint;
  pSVar5 = cInfo->newPoint;
  setCopControlWord(2, 0, *(u_char *)rotMat->m);
  setCopControlWord(2, 0x800, *(u_char *)(rotMat->m + 2));
  setCopControlWord(2, 0x1000, *(u_char *)(rotMat->m + 4));
  setCopControlWord(2, 0x1800, *(u_char *)(rotMat->m + 6));
  setCopControlWord(2, 0x2000, *(u_char *)(rotMat->m + 8));
  setCopReg(2, in_zero, *(u_char *)pSVar4);
  setCopReg(2, in_at, *(u_char *)&pSVar4->vz);
  copFunction(2, 0x486012);
  uVar1 = getCopReg(2, 0x19);
  uVar2 = getCopReg(2, 0x1a);
  uVar3 = getCopReg(2, 0x1b);
  local_18 = (short)uVar1;
  pSVar4->vx = *(short *)transMat->t + local_18;
  local_14 = (short)uVar2;
  pSVar4->vy = *(short *)(transMat->t + 1) + local_14;
  local_10 = (short)uVar3;
  pSVar4->vz = *(short *)(transMat->t + 2) + local_10;
  setCopControlWord(2, 0, *(u_char *)rotMat->m);
  setCopControlWord(2, 0x800, *(u_char *)(rotMat->m + 2));
  setCopControlWord(2, 0x1000, *(u_char *)(rotMat->m + 4));
  setCopControlWord(2, 0x1800, *(u_char *)(rotMat->m + 6));
  setCopControlWord(2, 0x2000, *(u_char *)(rotMat->m + 8));
  setCopReg(2, in_zero, *(u_char *)pSVar5);
  setCopReg(2, in_at, *(u_char *)&pSVar5->vz);
  copFunction(2, 0x486012);
  uVar1 = getCopReg(2, 0x19);
  uVar2 = getCopReg(2, 0x1a);
  uVar3 = getCopReg(2, 0x1b);
  local_18 = (short)uVar1;
  pSVar5->vx = *(short *)transMat->t + local_18;
  local_14 = (short)uVar2;
  pSVar5->vy = *(short *)(transMat->t + 1) + local_14;
  local_10 = (short)uVar3;
  pSVar5->vz = *(short *)(transMat->t + 2) + local_10;
  PHYSICS_CheckLineInWorldMask(instance, cInfo);
  return;
}
