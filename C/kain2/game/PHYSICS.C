#include "THISDUST.H"
#include "PHYSICS.H"

// decompiled code
// original method signature:
// void /*$ra*/ SetNoPtCollideInFamily(struct _Instance *instance /*$a0*/)
// line 57, offset 0x80074628
/* begin block 1 */
// Start line: 58
// Start offset: 0x80074628
// Variables:
// 		struct _Instance *child; // $s0
/* end block 1 */
// End offset: 0x80074660
// End Line: 65

/* begin block 2 */
// Start line: 114
/* end block 2 */
// End Line: 115

void SetNoPtCollideInFamily(_Instance *instance)

{
  _Instance *instance_00;

  instance_00 = instance->LinkChild;
  instance->flags = instance->flags | 0x40;
  while (instance_00 != (_Instance *)0x0)
  {
    SetNoPtCollideInFamily(instance_00);
    instance_00 = instance_00->LinkSibling;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ ResetNoPtCollideInFamily(struct _Instance *instance /*$a0*/)
// line 67, offset 0x80074670
/* begin block 1 */
// Start line: 68
// Start offset: 0x80074670
// Variables:
// 		struct _Instance *child; // $s0
/* end block 1 */
// End offset: 0x800746AC
// End Line: 75

/* begin block 2 */
// Start line: 137
/* end block 2 */
// End Line: 138

void ResetNoPtCollideInFamily(_Instance *instance)

{
  _Instance *instance_00;

  instance_00 = instance->LinkChild;
  instance->flags = instance->flags & 0xffffffbf;
  while (instance_00 != (_Instance *)0x0)
  {
    ResetNoPtCollideInFamily(instance_00);
    instance_00 = instance_00->LinkSibling;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PHYSICS_CheckLineInWorld(struct _Instance *instance /*$a0*/, struct _PCollideInfo *pcollideInfo /*$a1*/)
// line 79, offset 0x800746bc
/* begin block 1 */
// Start line: 167
/* end block 1 */
// End Line: 168

void PHYSICS_CheckLineInWorld(_Instance *instance, _PCollideInfo *pcollideInfo)

{
  pcollideInfo->collideType = 0x3f;
  PHYSICS_CheckLineInWorldMask(instance, pcollideInfo);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PHYSICS_CheckLineInWorldMask(struct _Instance *instance /*$s2*/, struct _PCollideInfo *pcollideInfo /*$s1*/)
// line 85, offset 0x800746e0
/* begin block 1 */
// Start line: 86
// Start offset: 0x800746E0
// Variables:
// 		struct Level *level; // $s0
/* end block 1 */
// End offset: 0x80074734
// End Line: 113

/* begin block 2 */
// Start line: 180
/* end block 2 */
// End Line: 181

void PHYSICS_CheckLineInWorldMask(_Instance *instance, _PCollideInfo *pcollideInfo)

{
  Level *level;

  level = STREAM_GetLevelWithID(instance->currentStreamUnitID);
  pcollideInfo->inst = (_Instance *)0x0;
  pcollideInfo->instance = instance;
  SetNoPtCollideInFamily(instance);
  if (level == (Level *)0x0)
  {
    pcollideInfo->type = 0;
  }
  else
  {
    COLLIDE_PointAndWorld(pcollideInfo, level);
  }
  ResetNoPtCollideInFamily(instance);
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ PhysicsCheckLinkedMove(struct _Instance *instance /*$s2*/, int Data /*stack 4*/, short Mode /*stack -72*/)
// line 124, offset 0x80074754
/* begin block 1 */
// Start line: 125
// Start offset: 0x80074754

/* begin block 1.1 */
// Start line: 128
// Start offset: 0x80074798
// Variables:
// 		struct evPhysicsLinkedMoveData *ptr; // $s3
// 		struct _Instance *on; // $s0
// 		struct MATRIX work; // stack offset -144
// 		struct MATRIX *current; // $s4
// 		struct VECTOR delta; // stack offset -112
// 		long onx; // stack offset -64
// 		long ony; // stack offset -60
// 		long onz; // stack offset -56
// 		long ix; // $s5
// 		long iy; // stack offset -52
// 		long iz; // stack offset -48

/* begin block 1.1.1 */
// Start line: 146
// Start offset: 0x80074810
// Variables:
// 		struct _Instance *oldOn; // $a0
/* end block 1.1.1 */
// End offset: 0x80074834
// End Line: 153

/* begin block 1.1.2 */
// Start line: 182
// Start offset: 0x80074920
// Variables:
// 		struct _G2EulerAngles_Type newRot; // stack offset -96
// 		struct VECTOR newRelPos; // stack offset -88
// 		long oldPosX; // $s6
// 		long oldPosY; // $fp
// 		long oldPosZ; // $s7
// 		int moved; // $s1
// 		int rotated; // $s0
/* end block 1.1.2 */
// End offset: 0x80074AD0
// End Line: 245
/* end block 1.1 */
// End offset: 0x80074B78
// End Line: 260
/* end block 1 */
// End offset: 0x80074B80
// End Line: 266

/* begin block 2 */
// Start line: 263
/* end block 2 */
// End Line: 264

/* WARNING: Could not reconcile some variable overlaps */

int PhysicsCheckLinkedMove(_Instance *instance, int Data, short Mode)

{
  short sVar1;
  bool bVar2;
  bool bVar3;
  _Instance *p_Var4;
  long lVar5;
  int introUniqueID;
  int iVar6;
  uint *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  _G2Matrix_Type _Stack144;
  uint local_70;
  int local_6c;
  int local_68;
  _G2EulerAngles_Type local_60;
  short local_58[2];
  short local_54;
  short local_50;
  ushort local_48;
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
    puVar8 = (undefined4 *)(*(int *)(iVar6 + 0x40) + *(int *)(Data + 4) * 0x20);
    local_40 = puVar8[5];
    local_3c = puVar8[6];
    local_38 = puVar8[7];
    local_34 = (int)(instance->position).y;
    sVar1 = (instance->position).x;
    iVar9 = (int)sVar1;
    local_30 = (int)(instance->position).z;
    introUniqueID = instance->attachedID;
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
      if ((bVar2) || (local_48 = Mode, bVar3))
      {
        local_48 = Mode;
        TransposeMatrix(puVar8, (undefined4 *)&_Stack144);
        if (bVar3)
        {
          MulMatrix0((undefined4 *)&_Stack144, (ushort *)instance->matrix,
                     (uint *)&instance->relativeMatrix);
        }
        if (bVar2)
        {
          local_70 = iVar9 - introUniqueID;
          local_6c = local_34 - iVar10;
          local_68 = local_30 - iVar6;
          ApplyMatrixLV((undefined4 *)&_Stack144, &local_70, (int *)&local_70);
          (instance->relativeMatrix).t[0] = (instance->relativeMatrix).t[0] + local_70;
          (instance->relativeMatrix).t[1] = (instance->relativeMatrix).t[1] + local_6c;
          (instance->relativeMatrix).t[2] = (instance->relativeMatrix).t[2] + local_68;
        }
      }
      ApplyMatrixLV(puVar8, (uint *)(instance->relativeMatrix).t, (int *)local_58);
      MulMatrix0(puVar8, (ushort *)&instance->relativeMatrix, (uint *)&_Stack144);
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
      local_48 = Mode;
      if ((introUniqueID != *(int *)(iVar6 + 0x3c)) &&
          (local_48 = Mode, p_Var4 = INSTANCE_Find(introUniqueID), p_Var4 != (_Instance *)0x0))
      {
        p_Var4->flags2 = p_Var4->flags2 & 0xffffff7f;
      }
      *(uint *)(iVar6 + 0x18) = *(uint *)(iVar6 + 0x18) | 0x80;
      instance->attachedID = *(long *)(iVar6 + 0x3c);
      lVar5 = *(long *)(Data + 4);
      instance->zAccl = 0;
      instance->zVel = 0;
      instance->attachedSegment = lVar5;
      TransposeMatrix(puVar8, (undefined4 *)&_Stack144);
      local_70 = iVar9 - local_40;
      puVar7 = (uint *)(instance->relativeMatrix).t;
      local_6c = local_34 - local_3c;
      local_68 = local_30 - local_38;
      ApplyMatrixLV((undefined4 *)&_Stack144, &local_70, (int *)puVar7);
      MulMatrix0((undefined4 *)&_Stack144, (ushort *)instance->matrix,
                 (uint *)&instance->relativeMatrix);
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
      PhysicsDefaultLinkedMoveResponse(instance, (evPhysicsLinkedMoveData *)Data, ((uint)(local_48 >> 3) ^ 1) & 1);
    }
    if ((local_48 & 2) != 0)
    {
      INSTANCE_Post(instance, 0x4010008, Data);
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

// decompiled code
// original method signature:
// void /*$ra*/ PhysicsDefaultLinkedMoveResponse(struct _Instance *instance /*$s0*/, struct evPhysicsLinkedMoveData *Data /*$s1*/, int updateTransforms /*$a2*/)
// line 272, offset 0x80074bb0
/* begin block 1 */
// Start line: 596
/* end block 1 */
// End Line: 597

void PhysicsDefaultLinkedMoveResponse(_Instance *instance, evPhysicsLinkedMoveData *Data, int updateTransforms)

{
  (instance->position).x = (instance->position).x + (Data->posDelta).x;
  (instance->position).y = (instance->position).y + (Data->posDelta).y;
  (instance->position).z = (instance->position).z + (Data->posDelta).z;
  if (updateTransforms != 0)
  {
    COLLIDE_UpdateAllTransforms(instance, (SVECTOR *)&Data->posDelta);
  }
  (instance->rotation).z = (instance->rotation).z + (Data->rotDelta).z;
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ PhysicsCheckGravity(struct _Instance *instance /*$s0*/, int Data /*stack 4*/, short Mode /*$s7*/)
// line 296, offset 0x80074c38
/* begin block 1 */
// Start line: 297
// Start offset: 0x80074C38
// Variables:
// 		struct evPhysicsGravityData *Ptr; // $s3
// 		struct SVECTOR D; // stack offset -120
// 		struct SVECTOR N; // stack offset -112
// 		short Dot; // $v0
// 		int rc; // $s4
// 		struct _PCollideInfo CInfo; // stack offset -104
// 		struct SVECTOR Old; // stack offset -56
// 		struct SVECTOR New; // stack offset -48
// 		int slide; // $fp

/* begin block 1.1 */
// Start line: 326
// Start offset: 0x80074D30
// Variables:
// 		int stillOnOldTFace; // $v0
// 		struct Level *level; // $s2
// 		struct _TFace *tface; // $s1
/* end block 1.1 */
// End offset: 0x80074DF0
// End Line: 361

/* begin block 1.2 */
// Start line: 504
// Start offset: 0x8007528C
// Variables:
// 		struct _Instance *oldOn; // $a0
/* end block 1.2 */
// End offset: 0x800752B0
// End Line: 511
/* end block 1 */
// End offset: 0x800753BC
// End Line: 564

/* begin block 2 */
// Start line: 644
/* end block 2 */
// End Line: 645

int PhysicsCheckGravity(_Instance *instance, int Data, short Mode)

{
  bool bVar1;
  undefined *puVar2;
  short sVar3;
  int Data_00;
  NodeType *pNVar4;
  int iVar5;
  _Instance *p_Var6;
  uint uVar7;
  int iVar8;
  int iVar9;
  _TFace *tface;
  uint uVar10;
  short local_74;
  _PCollideInfo local_68;
  SVECTOR local_38;
  SVECTOR local_30;

  puVar2 = PTR_DAT_800cf5c0;
  local_38.vx = (instance->position).x;
  uVar10 = 0;
  local_38.vy = (instance->position).y;
  bVar1 = false;
  uVar7 = (uint)(ushort)(instance->position).z;
  Data_00 = uVar7 + (uint) * (ushort *)Data;
  local_38.vz = (short)Data_00;
  iVar8 = uVar7 - (uint) * (ushort *)(Data + 2);
  local_30.vz = (short)iVar8;
  if (Data_00 * 0x10000 < iVar8 * 0x10000)
  {
    local_68.type = 0;
    local_68.newPoint = &local_30;
    local_68.oldPoint = &local_38;
    local_30.vx = local_38.vx;
    local_30.vy = local_38.vy;
    goto LAB_80074e28;
  }
  if ((instance->cachedTFace == -1) || (instance->cachedTFaceLevel == (void *)0x0))
  {
    instance->waterFace = (_TFace *)0x0;
    gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x8000;
    local_68.newPoint = &local_30;
    local_68.oldPoint = &local_38;
    local_30.vx = local_38.vx;
    local_30.vy = local_38.vy;
  LAB_80074e0c:
    PHYSICS_CheckLineInWorld(instance, &local_68);
  }
  else
  {
    tface = (_TFace *)0x0;
    local_68.newPoint = &local_30;
    local_68.oldPoint = &local_38;
    local_30.vx = local_38.vx;
    local_30.vy = local_38.vy;
    p_Var6 = (_Instance *)STREAM_GetLevelWithID(*(long *)((int)instance->cachedTFaceLevel + 0xf8));
    gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x8000;
    if (p_Var6 == (_Instance *)0x0)
    {
      Data_00 = 0;
    }
    else
    {
      pNVar4 = (p_Var6->node).prev;
      tface = (_TFace *)((int)pNVar4[4].prev + (int)instance->cachedTFace * 0xc);
      Data_00 = COLLIDE_PointAndTfaceFunc((_Terrain *)(p_Var6->node).prev,
                                          (BSPTree *)((int)pNVar4[9].prev + (int)instance->cachedBSPTree * 0x24),
                                          (_SVector *)&local_30, (_SVector *)&local_38, tface, 0, 0);
    }
    if (Data_00 == 0)
    {
      instance->waterFace = (_TFace *)0x0;
      goto LAB_80074e0c;
    }
    local_68.type = 3;
    local_68.segment = instance->cachedBSPTree;
    local_68.prim = tface;
    local_68.inst = p_Var6;
    COLLIDE_GetNormal(tface->normal, (short *)(p_Var6->node).prev[4].next,
                      (_SVector *)&local_68.wNormal);
  }
  gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffff7fff;
LAB_80074e28:
  if (((((uint)local_68.type - 2 < 2) || (local_68.type == 5)) &&
       (Data_00 = (int)local_68.wNormal.vz, Data_00 < (int)*(short *)(Data + 10))) &&
      (0 < Data_00))
  {
    iVar9 = (int)-local_68.wNormal.vz;
    iVar8 = -((int)local_68.wNormal.vx * iVar9);
    if (0 < (int)local_68.wNormal.vx * iVar9)
    {
      iVar8 = iVar8 + 0xfff;
    }
    iVar5 = -((int)local_68.wNormal.vy * iVar9);
    Data_00 = Data_00 * iVar9;
    if (0 < (int)local_68.wNormal.vy * iVar9)
    {
      iVar5 = iVar5 + 0xfff;
    }
    if (Data_00 < 0)
    {
      Data_00 = Data_00 + 0xfff;
    }
    local_74 = (short)puVar2;
    if (instance->zVel < -0x30)
    {
      sVar3 = -*(short *)&instance->zVel;
    }
    else
    {
      sVar3 = 0x30;
    }
    iVar9 = (int)sVar3;
    iVar8 = (int)(short)(iVar8 >> 0xc) * iVar9;
    if (iVar8 < 0)
    {
      iVar8 = iVar8 + 0xfff;
    }
    iVar5 = (int)(short)(iVar5 >> 0xc) * iVar9;
    local_38.vx = (local_68.newPoint)->vx + (short)(iVar8 >> 0xc);
    if (iVar5 < 0)
    {
      iVar5 = iVar5 + 0xfff;
    }
    iVar9 = (int)(short)(local_74 - (short)(Data_00 >> 0xc)) * iVar9;
    local_38.vy = (local_68.newPoint)->vy + (short)(iVar5 >> 0xc);
    if (iVar9 < 0)
    {
      iVar9 = iVar9 + 0xfff;
    }
    local_30.vz = (local_68.newPoint)->vz + (short)(iVar9 >> 0xc);
    local_38.vz = local_30.vz + *(short *)Data;
    local_30.vz = local_30.vz - *(short *)(Data + 2);
    local_30.vx = local_38.vx;
    local_30.vy = local_38.vy;
    PHYSICS_CheckLineInWorld(instance, &local_68);
    if (((uint)local_68.type - 2 < 2) || (local_68.type == 5))
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
    instance->cachedTFace =
        (short)((int)((int)local_68.prim - (int)((local_68.inst)->node).prev[4].prev) * -0x55555555 >> 2);
    *(_Instance **)&instance->cachedTFaceLevel = local_68.inst;
  }
  else
  {
    instance->cachedTFace = -1;
    instance->cachedTFaceLevel = (void *)0x0;
  }
  if (((uint)local_68.type - 2 < 2) || (local_68.type == 5))
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
      INSTANCE_Post(instance, 0x4010008, Data);
    }
    if (bVar1)
    {
      if ((Mode & 2U) != 0)
      {
        INSTANCE_Post(instance, 0x4010200, Data);
      }
      uVar10 = 0x100000;
    }
    if (((Mode & 4U) != 0) &&
        (((Data_00 = CheckPhysOb(instance), Data_00 == 0 ||
                                                (Data_00 = CheckPhysObFamily(instance, 1), Data_00 == 0)) ||
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
          (p_Var6 = INSTANCE_Find(instance->attachedID), p_Var6 != (_Instance *)0x0))
      {
        p_Var6->flags2 = p_Var6->flags2 & 0xffffff7f;
      }
      instance->attachedID = 0;
    }
    else
    {
      Data_00 = SetPhysicsLinkedMoveData(local_68.inst, (int)local_68.segment, (_SVector *)0x0, (_SVector *)0x0);
      uVar7 = PhysicsCheckLinkedMove(instance, Data_00, Mode);
      uVar10 = uVar10 | uVar7;
    }
    if ((instance->flags2 & 0x40U) != 0)
    {
      sVar3 = (instance->position).z;
      *(undefined4 *)&instance->shadowPosition = *(undefined4 *)&instance->position;
      (instance->shadowPosition).z = sVar3;
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
          uVar10 = uVar10 | 0x80000;
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
    uVar10 = uVar10 | 1;
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
      INSTANCE_Post(instance, 0x4000001, Data);
    }
  }
  return uVar10;
}

// decompiled code
// original method signature:
// void /*$ra*/ PhysicsDefaultGravityResponse(struct _Instance *instance /*$a0*/, struct evPhysicsGravityData *Data /*$a1*/)
// line 570, offset 0x800753f0
/* begin block 1 */
// Start line: 1307
/* end block 1 */
// End Line: 1308

/* begin block 2 */
// Start line: 1308
/* end block 2 */
// End Line: 1309

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

// decompiled code
// original method signature:
// int /*$ra*/ PhysicsCheckEdgeGrabbing(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$a1*/, int Data /*stack 8*/, short Mode /*$s7*/)
// line 589, offset 0x80075468
/* begin block 1 */
// Start line: 590
// Start offset: 0x80075468
// Variables:
// 		struct evPhysicsEdgeData *Ptr; // $s1
// 		int rc; // $s6
// 		struct VECTOR OutTrans; // stack offset -120
// 		struct SVECTOR *ExtraRot; // $v0
// 		struct _PCollideInfo CInfo; // stack offset -104
// 		struct SVECTOR Old; // stack offset -56
// 		struct SVECTOR New; // stack offset -48
// 		static struct MATRIX TempMat; // offset 0x0
// 		static struct MATRIX *pTempMat; // offset 0x20
// 		int wallCrawl; // $fp
// 		int freeSpot; // $s3
/* end block 1 */
// End offset: 0x80075AEC
// End Line: 873

/* begin block 2 */
// Start line: 1345
/* end block 2 */
// End Line: 1346

int PhysicsCheckEdgeGrabbing(_Instance *instance, GameTracker *gameTracker, int Data, short Mode)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  bool bVar4;
  uint uVar5;
  undefined4 in_zero;
  undefined4 in_at;
  ushort uVar6;
  ushort *puVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  short local_78;
  short local_74;
  short local_70;
  _PCollideInfo local_68;
  undefined4 local_38;
  uint local_34;
  int local_30;
  uint local_2c;

  iVar9 = 0;
  bVar4 = true;
  if ((Mode & 1U) != 0)
  {
    *(undefined4 *)(Data + 0x18) = 0;
  }
  local_68.oldPoint = (SVECTOR *)&local_38;
  local_68.newPoint = (SVECTOR *)&local_30;
  puVar7 = (ushort *)INSTANCE_Query(instance, 7);
  if (puVar7 == (ushort *)0x0)
  {
    pTempMat_41 = instance->matrix;
  }
  else
  {
    pTempMat_41 = (MATRIX *)&TempMat_40;
    RotMatrix(puVar7, &TempMat_40);
  }
  PHYSICS_GenericLineCheckSetup(0, 0, (short)(((uint) * (ushort *)Data + (uint) * (ushort *)(Data + 4)) * 0x10000 >> 0x10),
                                (SVECTOR *)&local_38);
  PHYSICS_GenericLineCheckSetup(0, *(short *)(Data + 2),
                                (short)(((uint) * (ushort *)Data + (uint) * (ushort *)(Data + 4)) * 0x10000 >> 0x10),
                                (SVECTOR *)&local_30);
  PHYSICS_GenericLineCheck(instance, instance->matrix, pTempMat_41, &local_68);
  iVar8 = PHYSICS_CheckFaceStick(&local_68);
  bVar10 = iVar8 != 0;
  if (local_68.type == 0)
  {
    PHYSICS_GenericLineCheckSetup(0, 0, *(short *)(Data + 4), (SVECTOR *)&local_38);
    PHYSICS_GenericLineCheckSetup(0, 0, (short)(((uint) * (ushort *)Data + (uint) * (ushort *)(Data + 4) + 0x80) * 0x10000 >> 0x10), (SVECTOR *)&local_30);
    PHYSICS_GenericLineCheck(instance, instance->matrix, pTempMat_41, &local_68);
    if (local_68.type == 0)
      goto LAB_800755f0;
  }
  bVar4 = false;
LAB_800755f0:
  if ((bVar4) || (bVar10))
  {
    uVar5 = local_2c & 0xffff0000;
    local_2c = uVar5 | (uint) * (ushort *)Data;
    setCopControlWord(2, 0, *(undefined4 *)pTempMat_41->m);
    setCopControlWord(2, 0x800, *(undefined4 *)(pTempMat_41->m + 2));
    setCopControlWord(2, 0x1000, *(undefined4 *)(pTempMat_41->m + 4));
    setCopControlWord(2, 0x1800, *(undefined4 *)(pTempMat_41->m + 6));
    setCopControlWord(2, 0x2000, *(undefined4 *)(pTempMat_41->m + 8));
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
    local_34 = local_34 & 0xffff0000 | (uint)(ushort)((instance->position).z + local_70);
    local_30 = (uint) * (ushort *)(Data + 2) << 0x10;
    local_2c = uVar5 | (uint) * (ushort *)Data;
    setCopControlWord(2, 0, *(undefined4 *)pTempMat_41->m);
    setCopControlWord(2, 0x800, *(undefined4 *)(pTempMat_41->m + 2));
    setCopControlWord(2, 0x1000, *(undefined4 *)(pTempMat_41->m + 4));
    setCopControlWord(2, 0x1800, *(undefined4 *)(pTempMat_41->m + 6));
    setCopControlWord(2, 0x2000, *(undefined4 *)(pTempMat_41->m + 8));
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
    local_2c = uVar5 | (uint)(ushort)((instance->position).z + local_70);
    PHYSICS_CheckLineInWorld(instance, &local_68);
    iVar8 = PHYSICS_CheckDontGrabEdge(&local_68);
    if ((iVar8 == 0) &&
        ((((local_68.type == 3 || (local_68.type == 5)) || (local_68.type == 2)) &&
          (local_68.wNormal.vz < 0x800))))
    {
      iVar9 = PHYSICS_CheckFaceStick(&local_68);
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
      setCopControlWord(2, 0, *(undefined4 *)pTempMat_41->m);
      setCopControlWord(2, 0x800, *(undefined4 *)(pTempMat_41->m + 2));
      setCopControlWord(2, 0x1000, *(undefined4 *)(pTempMat_41->m + 4));
      setCopControlWord(2, 0x1800, *(undefined4 *)(pTempMat_41->m + 6));
      setCopControlWord(2, 0x2000, *(undefined4 *)(pTempMat_41->m + 8));
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
      local_2c = local_2c & 0xffff0000 | (uint)uVar6;
      local_34 = uVar5 & 0xffff0000 | (uint)(ushort)(uVar6 + *(short *)(Data + 4));
      PHYSICS_CheckLineInWorld(instance, &local_68);
      iVar8 = PHYSICS_CheckDontGrabEdge(&local_68);
      if ((iVar8 == 0) &&
          ((((local_68.type == 3 || (local_68.type == 5)) || (local_68.type == 2)) &&
            (0xddb < local_68.wNormal.vz))))
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
            INSTANCE_Post(instance, 0x4010010, Data);
          }
          if ((Mode & 4U) != 0)
          {
            PhysicsDefaultEdgeGrabResponse(instance, (evPhysicsEdgeData *)Data, 0);
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
    INSTANCE_Post(instance, 0x4000011, Data);
  }
  return iVar9;
}

// decompiled code
// original method signature:
// void /*$ra*/ PhysicsDefaultEdgeGrabResponse(struct _Instance *instance /*$s2*/, struct evPhysicsEdgeData *Data /*$s1*/, int blockFlag /*$a2*/)
// line 886, offset 0x80075b20
/* begin block 1 */
// Start line: 887
// Start offset: 0x80075B20
// Variables:
// 		struct _SVector normal; // stack offset -88
// 		struct _G2EulerAngles_Type ea1; // stack offset -80
// 		struct VECTOR OutTrans; // stack offset -72
// 		struct MATRIX TempMat; // stack offset -56
// 		struct SVECTOR New; // stack offset -24

/* begin block 1.1 */
// Start line: 936
// Start offset: 0x80075C3C
// Variables:
// 		long dp; // $v0
/* end block 1.1 */
// End offset: 0x80075C3C
// End Line: 936
/* end block 1 */
// End offset: 0x80075C3C
// End Line: 936

/* begin block 2 */
// Start line: 2031
/* end block 2 */
// End Line: 2032

/* WARNING: Could not reconcile some variable overlaps */

void PhysicsDefaultEdgeGrabResponse(_Instance *instance, evPhysicsEdgeData *Data, int blockFlag)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar5;
  _SVector *p_Var6;
  _SVector local_58;
  _G2EulerAngles_Type local_50;
  short local_48;
  short local_44;
  short local_40;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_18;
  undefined4 local_14;

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
  local_18 = *(undefined4 *)&Data->XDistance;
  RotMatrix((ushort *)&instance->rotation, (uint *)&local_38);
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
  Data->Delta->y = (short)(iVar5 * (int)local_58.y >> 0xc);
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

// decompiled code
// original method signature:
// int /*$ra*/ PhysicsCheckSliding(struct _Instance *instance /*$s3*/, int Data /*$a1*/, short Mode /*$s6*/)
// line 983, offset 0x80075dc4
/* begin block 1 */
// Start line: 984
// Start offset: 0x80075DC4
// Variables:
// 		struct evPhysicsSlideData *Ptr; // $s0
// 		int rc; // $s1
// 		struct VECTOR OutTrans; // stack offset -120
// 		struct _SVector normal; // stack offset -104
// 		struct _PCollideInfo CInfo; // stack offset -96
// 		struct SVECTOR Old; // stack offset -48
// 		struct SVECTOR New; // stack offset -40
// 		static struct MATRIX *pTempMat; // offset 0x24

/* begin block 1.1 */
// Start line: 1015
// Start offset: 0x80075E4C
/* end block 1.1 */
// End offset: 0x80075E4C
// End Line: 1017

/* begin block 1.2 */
// Start line: 1024
// Start offset: 0x80075E88
// Variables:
// 		int Temp; // $a3
/* end block 1.2 */
// End offset: 0x80075F5C
// End Line: 1032
/* end block 1 */
// End offset: 0x80076244
// End Line: 1166

/* begin block 2 */
// Start line: 2245
/* end block 2 */
// End Line: 2246

int PhysicsCheckSliding(_Instance *instance, int Data, short Mode)

{
  Level *pLVar1;
  int iVar2;
  uint uVar3;
  short local_78;
  short local_74;
  short local_70;
  _SVector local_68;
  _PCollideInfo local_60;
  SVECTOR local_30;
  SVECTOR local_28;

  local_60.oldPoint = &local_30;
  local_60.newPoint = &local_28;
  pTempMat_46 = instance->matrix + (int)*(short *)(Data + 0x18);
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
    pLVar1 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
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
    *(undefined4 *)(Data + 0x20) = 0;
  }
  return uVar3;
}

// decompiled code
// original method signature:
// int /*$ra*/ PhysicsUpdateTface(struct _Instance *instance /*$s0*/, int Data /*$a1*/)
// line 1177, offset 0x80076270
/* begin block 1 */
// Start line: 1178
// Start offset: 0x80076270
// Variables:
// 		struct _PCollideInfo CInfo; // stack offset -72
// 		struct SVECTOR Old; // stack offset -24
// 		struct SVECTOR New; // stack offset -16
/* end block 1 */
// End offset: 0x8007635C
// End Line: 1219

/* begin block 2 */
// Start line: 2786
/* end block 2 */
// End Line: 2787

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

// decompiled code
// original method signature:
// int /*$ra*/ PhysicsCheckBlockers(struct _Instance *instance /*$s3*/, struct GameTracker *gameTracker /*$a1*/, int Data /*$s4*/, short Mode /*$s2*/)
// line 1232, offset 0x8007636c
/* begin block 1 */
// Start line: 1233
// Start offset: 0x8007636C
// Variables:
// 		struct evPhysicsEdgeData *Ptr; // $s1
// 		struct VECTOR OutTrans; // stack offset -120
// 		struct _PCollideInfo CInfo; // stack offset -104
// 		struct SVECTOR Old; // stack offset -56
// 		struct SVECTOR New; // stack offset -48
// 		static struct MATRIX *pTempMat; // offset 0x28

/* begin block 1.1 */
// Start line: 1276
// Start offset: 0x80076418
// Variables:
// 		struct _TFace *tface; // $s0

/* begin block 1.1.1 */
// Start line: 1278
// Start offset: 0x80076418
// Variables:
// 		int Dot; // $a0
// 		struct SVECTOR Force; // stack offset -40
/* end block 1.1.1 */
// End offset: 0x800764FC
// End Line: 1323

/* begin block 1.1.2 */
// Start line: 1351
// Start offset: 0x800765D0
// Variables:
// 		struct _HFace *hface; // stack offset -32
/* end block 1.1.2 */
// End offset: 0x800765D0
// End Line: 1357
/* end block 1.1 */
// End offset: 0x800766E8
// End Line: 1401
/* end block 1 */
// End offset: 0x800766EC
// End Line: 1404

/* begin block 2 */
// Start line: 2909
/* end block 2 */
// End Line: 2910

/* WARNING: Could not reconcile some variable overlaps */

int PhysicsCheckBlockers(_Instance *instance, GameTracker *gameTracker, int Data, short Mode)

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
  *(undefined4 *)(Data + 0x20) = 0;
  *(undefined4 *)(Data + 0x18) = 0;
  local_68.newPoint = &local_30;
  PHYSICS_GenericLineCheckSetup(0, 0, 0, local_68.oldPoint);
  PHYSICS_GenericLineCheckSetup(0, *(short *)(Data + 2), 0, &local_30);
  PHYSICS_GenericLineCheck(instance, instance->matrix + 1, instance->matrix, &local_68);
  pTempMat_51 = instance->matrix;
  if (((local_68.type == 3) || (local_68.type == 5)) || (local_68.type == 2))
  {
    local_28 = 0;
    local_26 = 0xf000;
    ApplyMatrix(pTempMat_51, &local_28, &local_78);
    iVar2 = (int)local_68.wNormal.vx * local_78 + (int)local_68.wNormal.vy * local_74 +
            (int)local_68.wNormal.vz * local_70;
    if (iVar2 < 0)
    {
      iVar2 = iVar2 + 0xfff;
    }
    if (((local_68.type == 3) && (*(ushort *)((int)local_68.prim + 10) != 0xffff)) &&
        ((*(ushort *)((int)&((local_68.inst)->node).prev[6].next[1].prev +
                      (uint) * (ushort *)((int)local_68.prim + 10) + 2) &
          0x1000) != 0))
    {
      if (-0xec8 < iVar2 >> 0xc)
        goto LAB_800766e8;
    }
    else
    {
      if (-0xfc1 < iVar2 >> 0xc)
        goto LAB_800766e8;
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
    if (((local_68.type == 3) && (*(ushort *)((int)local_68.prim + 10) != 0xffff)) &&
        ((*(ushort *)((int)&((local_68.inst)->node).prev[6].next[1].prev +
                      (uint) * (ushort *)((int)local_68.prim + 10) + 2) &
          0x1000) != 0))
    {
      *(uint *)(Data + 0x20) = *(uint *)(Data + 0x20) | 0x20000;
    }
    pMVar1 = pTempMat_51;
    *(uint *)(Data + 0x20) = *(uint *)(Data + 0x20) | 2;
    local_38.vx = 0;
    local_38.vy = -0x10;
    local_38.vz = 0;
    ApplyMatrix(pMVar1, &local_38, &local_78);
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
        *(uint *)(Data + 0x20) = *(uint *)(Data + 0x20) | 4;
      }
    }
    if ((Mode & 2U) != 0)
    {
      INSTANCE_Post(instance, 0x4010400, Data);
    }
  }
LAB_800766e8:
  return *(int *)(Data + 0x20);
}

// decompiled code
// original method signature:
// int /*$ra*/ PhysicsCheckSwim(struct _Instance *instance /*$s1*/, int Data /*$s3*/, short Mode /*$s5*/)
// line 1486, offset 0x8007670c
/* begin block 1 */
// Start line: 1487
// Start offset: 0x8007670C
// Variables:
// 		struct evPhysicsSwimData *Ptr; // $s4
// 		int rc; // $s0
// 		int Depth; // $s0
// 		int WaterDepth; // $v1
// 		struct _PCollideInfo CInfo; // stack offset -96
// 		struct SVECTOR Old; // stack offset -48
// 		struct SVECTOR New; // stack offset -40
// 		long waterZLevel; // $s2
/* end block 1 */
// End offset: 0x800768CC
// End Line: 1576

/* begin block 2 */
// Start line: 3530
/* end block 2 */
// End Line: 3531

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

  level = STREAM_GetLevelWithID(instance->currentStreamUnitID);
  lVar1 = STREAM_GetWaterZLevel(level, instance);
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
  iVar2 = PhysicsDefaultCheckSwimResponse(instance, (evPhysicsSwimData *)Data);
  *(undefined2 *)(Data + 0x10) = (short)iVar2;
  if ((Mode & 2U) != 0)
  {
    INSTANCE_Post(instance, 0x4020000, Data);
  }
  FX_UpdateInstanceWaterSplit(instance);
  return iVar2;
}

// decompiled code
// original method signature:
// int /*$ra*/ PhysicsDefaultCheckSwimResponse(struct _Instance *instance /*$s2*/, struct evPhysicsSwimData *Data /*$s3*/)
// line 1584, offset 0x800768fc
/* begin block 1 */
// Start line: 1585
// Start offset: 0x800768FC
// Variables:
// 		int rc; // $s0
// 		long waterZLevel; // $s1
/* end block 1 */
// End offset: 0x80076AD4
// End Line: 1638

/* begin block 2 */
// Start line: 3755
/* end block 2 */
// End Line: 3756

int PhysicsDefaultCheckSwimResponse(_Instance *instance, evPhysicsSwimData *Data)

{
  uint uVar1;
  int iVar2;

  STREAM_GetLevelWithID(instance->currentStreamUnitID);
  iVar2 = Data->WaterLevel;
  uVar1 = (uint)(-(int)Data->WadeDepth < (int)Data->WaterDepth) << 7;
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
  if ((((int)(instance->position).z < iVar2) && (iVar2 < (int)(instance->oldPos).z)) &&
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
  if (((iVar2 < (int)(instance->position).z) && ((int)(instance->oldPos).z < iVar2)) &&
      (0 < Data->iVelocity->z))
  {
    uVar1 = uVar1 | 0x400;
  }
  if ((((instance->matrix != (MATRIX *)0x0) && (instance->oldMatrix != (MATRIX *)0x0)) &&
       (iVar2 = iVar2 - (int)Data->SwimDepth, instance->matrix[1].t[2] < iVar2)) &&
      ((iVar2 < instance->oldMatrix[1].t[2] && (Data->iVelocity->z < 0))))
  {
    uVar1 = uVar1 | 0x800;
  }
  return uVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ PhysicsForceSetWater(struct _Instance *instance /*$s1*/, int *Time /*$t0*/, int Depth /*$a2*/, int rate /*$a3*/, int maxAmplitude /*stack 16*/)
// line 1856, offset 0x80076af4
/* begin block 1 */
// Start line: 1857
// Start offset: 0x80076AF4
// Variables:
// 		int Amplitude; // $s0
/* end block 1 */
// End offset: 0x80076BB8
// End Line: 1874

/* begin block 2 */
// Start line: 4301
/* end block 2 */
// End Line: 4302

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
  iVar2 = *Time + (uint)(rate << 0xc) / gameTrackerX.timeMult;
  *Time = iVar2;
  if (0x1000 < iVar2)
  {
    *Time = iVar2 + -0x1000;
  }
  if (Depth < 0)
  {
    iVar2 = rcos(*Time);
    iVar2 = (iVar1 - ((iVar3 * maxAmplitude) / 6 + iVar1 >> 9)) * iVar2;
    if (iVar2 < 0)
    {
      iVar2 = iVar2 + 0xfff;
    }
    (instance->position).z = (instance->position).z + (short)(iVar2 >> 0xc);
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ PhysicsCheckLOS(struct _Instance *instance /*$a0*/, int Data /*$a1*/, int Mode /*$a2*/)
// line 1887, offset 0x80076bcc
/* begin block 1 */
// Start line: 1888
// Start offset: 0x80076BCC
// Variables:
// 		struct _PCollideInfo CInfo; // stack offset -56
/* end block 1 */
// End offset: 0x80076BCC
// End Line: 1888

/* begin block 2 */
// Start line: 4372
/* end block 2 */
// End Line: 4373

int PhysicsCheckLOS(_Instance *instance, int Data, int Mode)

{
  _PCollideInfo local_38;

  local_38.oldPoint = (SVECTOR *)(Data + 8);
  local_38.newPoint = (SVECTOR *)Data;
  PHYSICS_CheckLineInWorld(instance, &local_38);
  return (uint)(local_38.type == 0);
}

// decompiled code
// original method signature:
// int /*$ra*/ PhysicsCheckDropHeight(struct _Instance *instance /*$s2*/, int Data /*$a1*/, int Mode /*$s3*/)
// line 1915, offset 0x80076bfc
/* begin block 1 */
// Start line: 1916
// Start offset: 0x80076BFC
// Variables:
// 		struct evPhysicsDropHeightData *data; // $s0
// 		struct Level *level; // $v0
// 		struct SVECTOR newPos; // stack offset -104
// 		struct SVECTOR oldPos; // stack offset -96
// 		int rc; // $s1
// 		int lowZ; // $v1
// 		struct _PCollideInfo CInfo; // stack offset -88
// 		static struct MATRIX TempMat; // offset 0x30
// 		static struct MATRIX *pTempMat; // offset 0x50

/* begin block 1.1 */
// Start line: 1929
// Start offset: 0x80076C30
// Variables:
// 		struct VECTOR outTrans; // stack offset -40
// 		struct SVECTOR *ExtraRot; // $v0
/* end block 1.1 */
// End offset: 0x80076C74
// End Line: 1958

/* begin block 1.2 */
// Start line: 1982
// Start offset: 0x80076D40
// Variables:
// 		long waterZLevel; // $a0
/* end block 1.2 */
// End offset: 0x80076D7C
// End Line: 2000
/* end block 1 */
// End offset: 0x80076E6C
// End Line: 2048

/* begin block 2 */
// Start line: 4438
/* end block 2 */
// End Line: 4439

int PhysicsCheckDropHeight(_Instance *instance, int Data, int Mode)

{
  ushort *puVar1;
  Level *level;
  long lVar2;
  int iVar3;
  int iVar4;
  SVECTOR local_68;
  SVECTOR local_60;
  _PCollideInfo local_58;
  short local_28[2];
  short local_24;
  short local_20;

  if ((*(ushort *)(Data + 6) & 0x20) == 0)
  {
    if ((*(ushort *)(Data + 6) & 0x10) == 0)
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
    puVar1 = (ushort *)INSTANCE_Query(instance, 8);
    if (puVar1 == (ushort *)0x0)
    {
      pTempMat_63 = instance->matrix;
    }
    else
    {
      pTempMat_63 = (MATRIX *)&TempMat_62;
      RotMatrix(puVar1, (uint *)&TempMat_62);
      MulMatrix2((undefined4 *)instance->matrix, (uint *)pTempMat_63);
    }
    ApplyMatrix(pTempMat_63, Data, local_28);
    local_60.vx = (instance->position).x + local_28[0];
    local_60.vy = (instance->position).y + local_24;
    local_60.vz = (instance->position).z + local_20;
  }
  level = STREAM_GetLevelWithID(instance->currentStreamUnitID);
  if (((*(ushort *)(Data + 6) & 0x40) == 0) ||
      (lVar2 = STREAM_GetWaterZLevel(level, instance), lVar2 == -0x7fff))
  {
    iVar4 = 0;
    iVar3 = (int)local_60.vz - (int)*(short *)(Data + 8);
  }
  else
  {
    iVar3 = (int)local_60.vz - (int)*(short *)(Data + 8);
    iVar4 = 0x10;
    if (iVar3 < lVar2)
    {
      iVar3 = lVar2 + -1;
    }
    else
    {
      iVar4 = 0;
    }
  }
  if (iVar3 < (int)local_60.vz)
  {
    local_68.vz = (short)iVar3;
    local_58.oldPoint = &local_60;
    local_58.newPoint = &local_68;
    local_68.vx = local_60.vx;
    local_68.vy = local_60.vy;
    PHYSICS_CheckLineInWorld(instance, &local_58);
    if (((local_58.type != 0) && (0xc80 < local_58.wNormal.vz)) && (iVar4 = 1, Mode == 1))
    {
      if (local_58.type == 3)
      {
        *(NodeType **)(Data + 0xc) =
            (NodeType *)((int)((local_58.inst)->node).prev[9].prev + (int)local_58.segment * 0x24);
        *(void **)(Data + 0x10) = local_58.prim;
      }
      else
      {
        *(undefined4 *)(Data + 0xc) = 0;
        *(undefined4 *)(Data + 0x10) = 0;
      }
      *(short *)(Data + 10) = local_60.vz - local_68.vz;
      *(short *)(Data + 4) = local_68.vz;
      iVar4 = 1;
    }
  }
  return iVar4;
}

// decompiled code
// original method signature:
// int /*$ra*/ PhysicsCheckDropOff(struct _Instance *instance /*$s0*/, int Data /*$a1*/, short Mode /*$s3*/)
// line 2060, offset 0x80076e8c
/* begin block 1 */
// Start line: 2061
// Start offset: 0x80076E8C
// Variables:
// 		struct evPhysicsDropOffData *Ptr; // $s1
// 		int rc; // $s2
// 		struct VECTOR OutTrans; // stack offset -104
// 		struct SVECTOR *ExtraRot; // $v0
// 		struct _PCollideInfo CInfo; // stack offset -88
// 		struct SVECTOR New; // stack offset -40
// 		struct SVECTOR Old; // stack offset -32
// 		static struct MATRIX TempMat; // offset 0x60
// 		static struct MATRIX *pTempMat; // offset 0x80
/* end block 1 */
// End offset: 0x80077090
// End Line: 2155

/* begin block 2 */
// Start line: 4753
/* end block 2 */
// End Line: 4754

int PhysicsCheckDropOff(_Instance *instance, int Data, short Mode)

{
  ushort *puVar1;
  int iVar2;
  short local_68[2];
  short local_64;
  short local_60;
  _PCollideInfo local_58;
  SVECTOR local_28;
  SVECTOR local_20;

  local_58.oldPoint = &local_20;
  local_58.newPoint = &local_28;
  puVar1 = (ushort *)INSTANCE_Query(instance, 8);
  iVar2 = 0;
  if (instance->matrix != (MATRIX *)0x0)
  {
    pTempMat_67 = instance->matrix;
    if (puVar1 != (ushort *)0x0)
    {
      pTempMat_67 = (MATRIX *)&TempMat_66;
      RotMatrix(puVar1, (uint *)&TempMat_66);
      MulMatrix2((undefined4 *)instance->matrix, (uint *)pTempMat_67);
    }
    local_28.vx = *(short *)Data;
    local_28.vy = *(short *)(Data + 2);
    local_28.vz = 0;
    ApplyMatrix(pTempMat_67, &local_28, local_68);
    local_28.vx = (instance->position).x + local_68[0];
    local_28.vy = (instance->position).y + local_64;
    local_60 = (instance->position).z + local_60;
    local_28.vz = local_60 - *(short *)(Data + 4);
    local_20.vz = local_60 + *(short *)(Data + 8);
    local_20.vx = local_28.vx;
    local_20.vy = local_28.vy;
    PHYSICS_CheckLineInWorld(instance, &local_58);
    if (((uint)local_58.type - 2 < 2) || (local_58.type == 5))
    {
      if ((Mode & 2U) != 0)
      {
        if (*(short *)(Data + 6) < local_58.wNormal.vz)
        {
          INSTANCE_Post(instance, 0x4010080, 1);
        }
        else
        {
          INSTANCE_Post(instance, 0x4010080, 0);
          iVar2 = 8;
        }
      }
      if (((local_58.wNormal.vz < *(short *)(Data + 6)) && (0 < local_58.wNormal.vz)) &&
          ((instance->position).z < (local_58.newPoint)->vz))
      {
        INSTANCE_Post(instance, 0x4010401, 0);
      }
    }
    else
    {
      iVar2 = 0;
      if (local_58.type == 0)
      {
        if ((Mode & 2U) != 0)
        {
          INSTANCE_Post(instance, 0x4010080, 0);
        }
        iVar2 = 8;
      }
    }
  }
  return iVar2;
}

// decompiled code
// original method signature:
// int /*$ra*/ PhysicsFollowWall(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$a1*/, int Data /*$s7*/, short Mode /*$s5*/)
// line 2209, offset 0x800770ac
/* begin block 1 */
// Start line: 2210
// Start offset: 0x800770AC
// Variables:
// 		struct VECTOR OutTrans; // stack offset -168
// 		struct evPhysicsWallCrawlData *Ptr; // $s1
// 		struct _PCollideInfo CInfo; // stack offset -152
// 		struct SVECTOR New; // stack offset -104
// 		struct SVECTOR Old; // stack offset -96
// 		static struct MATRIX *pTempMat; // offset 0x84

/* begin block 1.1 */
// Start line: 2281
// Start offset: 0x800771E8
// Variables:
// 		struct _Position A; // stack offset -88
// 		struct _Position B; // stack offset -80
// 		struct MATRIX mat; // stack offset -72
/* end block 1.1 */
// End offset: 0x800772E4
// End Line: 2341
/* end block 1 */
// End offset: 0x8007758C
// End Line: 2488

/* begin block 2 */
// Start line: 4418
/* end block 2 */
// End Line: 4419

int PhysicsFollowWall(_Instance *instance, GameTracker *gameTracker, int Data, short Mode)

{
  short sVar1;
  uint uVar2;
  short local_a8[2];
  short local_a4;
  short local_a0;
  _PCollideInfo local_98;
  SVECTOR local_68;
  SVECTOR local_60;
  _Position local_58;
  _Position local_50;
  uint auStack72[8];

  local_98.oldPoint = &local_60;
  *(undefined4 *)(Data + 0x28) = 0;
  pTempMat_72 = instance->matrix + (int)*(short *)Data;
  local_98.newPoint = &local_68;
  PHYSICS_GenericLineCheckSetup(0, 0x40, 0, local_98.oldPoint);
  PHYSICS_GenericLineCheckSetup(0, *(short *)(Data + 2), 0, &local_68);
  PHYSICS_GenericLineCheck(instance, pTempMat_72, pTempMat_72, &local_98);
  if ((local_98.type == 3) || (local_98.type == 5))
  {
    (instance->shadowPosition).x = local_68.vx;
    (instance->shadowPosition).y = local_68.vy;
    uVar2 = instance->flags2;
    (instance->shadowPosition).z = local_68.vz;
    if ((uVar2 & 0x40) != 0)
    {
      instance->flags = instance->flags | 0x8000000;
    }
    *(uint *)(Data + 0x28) = *(uint *)(Data + 0x28) | 8;
    if ((Mode & 7U) != 0)
    {
      *(short *)(Data + 8) = local_98.wNormal.vx;
      *(short *)(Data + 10) = local_98.wNormal.vy;
      *(short *)(Data + 0xc) = local_98.wNormal.vz;
    }
    if ((Mode & 4U) != 0)
    {
      local_50.z = 0;
      local_50.y = 0;
      local_50.x = 0;
      local_58.x = *(short *)(Data + 8);
      local_58.y = *(short *)(Data + 10);
      local_58.z = *(short *)(Data + 0xc);
      MATH3D_RotationFromPosToPos(&local_58, &local_50, (_Rotation *)(Data + 0x1e));
      RotMatrix((ushort *)(_Rotation *)(Data + 0x1e), auStack72);
      *(short *)(Data + 0x18) = local_68.vx;
      *(short *)(Data + 0x1a) = local_68.vy;
      *(short *)(Data + 0x1c) = local_68.vz;
      local_68.vx = 0;
      local_68.vz = 0;
      local_68.vy = -*(short *)(Data + 6);
      ApplyMatrix(auStack72, &local_68, local_a8);
      *(short *)(Data + 0x18) = *(short *)(Data + 0x18) + local_a8[0];
      *(short *)(Data + 0x1a) = *(short *)(Data + 0x1a) + local_a4;
      *(short *)(Data + 0x1c) = *(short *)(Data + 0x1c) + local_a0;
      *(short *)(Data + 0x18) = (instance->position).x - *(short *)(Data + 0x18);
      *(short *)(Data + 0x1a) = (instance->position).y - *(short *)(Data + 0x1a);
      *(short *)(Data + 0x1c) = (instance->position).z - *(short *)(Data + 0x1c);
    }
    (instance->wNormal).x = local_98.wNormal.vx;
    (instance->wNormal).y = local_98.wNormal.vy;
    instance->oldTFace = instance->tface;
    (instance->wNormal).z = local_98.wNormal.vz;
    instance->tface = local_98.prim;
    *(_Instance **)&instance->tfaceLevel = local_98.inst;
    instance->bspTree = (int)local_98.segment;
  }
  PHYSICS_GenericLineCheckSetup(0, 0x40, *(short *)(Data + 4), &local_60);
  uVar2 = (uint) * (ushort *)(Data + 6) << 0x10;
  PHYSICS_GenericLineCheckSetup(0, (short)(((uint) * (ushort *)(Data + 2) + ((int)(((int)uVar2 >> 0x10) + (uVar2 >> 0x1f)) >> 1)) * 0x10000 >> 0x10),
                                *(short *)(Data + 4), &local_68);
  PHYSICS_GenericLineCheck(instance, pTempMat_72, pTempMat_72, &local_98);
  if ((local_98.type == 3) || (local_98.type == 5))
  {
    *(uint *)(Data + 0x28) = *(uint *)(Data + 0x28) | 2;
    if ((Mode & 7U) != 0)
    {
      *(short *)(Data + 0x10) = local_98.wNormal.vx;
      *(short *)(Data + 0x12) = local_98.wNormal.vy;
      *(short *)(Data + 0x14) = local_98.wNormal.vz;
    }
    if ((Mode & 4U) != 0)
    {
      sVar1 = MATH3D_AngleBetweenVectors((_SVector *)(Data + 8), (_SVector *)(Data + 0x10));
      *(short *)(Data + 0x26) = sVar1;
    }
    local_60.vx = 0;
    local_60.vy = -0x20;
    local_60.vz = 0;
    ApplyMatrix(pTempMat_72, &local_60, local_a8);
    local_60.vx = 0;
    local_60.vy = 0;
    local_60.vz = 0x40;
    local_68.vx = local_68.vx + local_a8[0];
    local_68.vy = local_68.vy + local_a4;
    local_68.vz = local_68.vz + local_a0;
    ApplyMatrix(pTempMat_72, &local_60, local_a8);
    local_60.vx = local_68.vx + local_a8[0];
    local_60.vy = local_68.vy + local_a4;
    local_60.vz = local_68.vz + local_a0;
    PHYSICS_CheckLineInWorld(instance, &local_98);
    if ((local_98.type == 3) || (local_98.type == 5))
    {
      local_60.vx = 0;
      local_60.vy = 0;
      local_60.vz = 0x40;
      ApplyMatrix(pTempMat_72, &local_60, local_a8);
      local_68.vx = local_68.vx + local_a8[0];
      local_68.vy = local_68.vy + local_a4;
      local_68.vz = local_68.vz + local_a0;
      local_60.vx = *(short *)pTempMat_72->t + local_a8[0];
      local_60.vy = *(short *)(pTempMat_72->t + 1) + local_a4;
      local_60.vz = *(short *)(pTempMat_72->t + 2) + local_a0;
      PHYSICS_CheckLineInWorld(instance, &local_98);
      if (local_98.type == 0)
      {
        *(uint *)(Data + 0x28) = *(uint *)(Data + 0x28) | 4;
      }
    }
  }
  if ((Mode & 2U) != 0)
  {
    INSTANCE_Post(instance, 0x4010011, Data);
  }
  return *(int *)(Data + 0x28);
}

// decompiled code
// original method signature:
// void /*$ra*/ PhysicsMoveLocalZClamp(struct _Instance *instance /*$s3*/, long segment /*$s0*/, long time /*$s1*/, long clamp /*$s2*/)
// line 2636, offset 0x800775bc
/* begin block 1 */
// Start line: 2637
// Start offset: 0x800775BC
// Variables:
// 		struct _Position pos; // stack offset -48
// 		struct SVECTOR v; // stack offset -40
// 		struct SVECTOR dv; // stack offset -32
/* end block 1 */
// End offset: 0x80077678
// End Line: 2656

/* begin block 2 */
// Start line: 5272
/* end block 2 */
// End Line: 5273

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
  PhysicsMove(instance, &local_30, time);
  local_28 = local_30.x;
  local_24 = local_30.z;
  local_26 = -local_30.y;
  ApplyMatrixSV(instance->matrix + segment, &local_28, &local_20);
  (instance->position).x = (instance->position).x + local_20;
  (instance->position).y = (instance->position).y + local_1e;
  if (clamp == 0)
  {
    (instance->position).z = (instance->position).z + local_1c;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PhysicsMove(struct _Instance *instance /*$a0*/, struct _Position *position /*$a1*/, long time /*$a2*/)
// line 2662, offset 0x80077694
/* begin block 1 */
// Start line: 2664
// Start offset: 0x80077694
// Variables:
// 		long xVel; // $t0
// 		long yVel; // $t1
// 		long zVel; // $t2
// 		long xat; // $t6
// 		long yat; // $t4
// 		long zat; // $t5
/* end block 1 */
// End offset: 0x80077820
// End Line: 2700

/* begin block 2 */
// Start line: 5969
/* end block 2 */
// End Line: 5970

/* begin block 3 */
// Start line: 5970
/* end block 3 */
// End Line: 5971

/* begin block 4 */
// Start line: 5979
/* end block 4 */
// End Line: 5980

void PhysicsMove(_Instance *instance, _Position *position, long time)

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

// decompiled code
// original method signature:
// void /*$ra*/ PhysicsSetVelFromZRot(struct _Instance *instance /*$s2*/, short angle /*$a1*/, long magnitude /*$s1*/)
// line 2734, offset 0x80077830
/* begin block 1 */
// Start line: 6122
/* end block 1 */
// End Line: 6123

void PhysicsSetVelFromZRot(_Instance *instance, short angle, long magnitude)

{
  int iVar1;

  iVar1 = rcos((int)angle - 0x400U);
  instance->xVel = iVar1 * magnitude >> 0xc;
  iVar1 = rsin((int)angle - 0x400U);
  instance->yVel = iVar1 * magnitude >> 0xc;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PhysicsSetVelFromRot(struct _Instance *instance /*$s0*/, struct _Rotation *rot /*$a1*/, long magnitude /*$a2*/)
// line 2745, offset 0x800778a0
/* begin block 1 */
// Start line: 2746
// Start offset: 0x800778A0
// Variables:
// 		struct MATRIX mat; // stack offset -56
// 		struct SVECTOR flatPt; // stack offset -24
// 		struct SVECTOR newPt; // stack offset -16
/* end block 1 */
// End offset: 0x800778A0
// End Line: 2746

/* begin block 2 */
// Start line: 6148
/* end block 2 */
// End Line: 6149

void PhysicsSetVelFromRot(_Instance *instance, _Rotation *rot, long magnitude)

{
  uint auStack56[8];
  undefined2 local_18;
  short local_16;
  undefined2 local_14;
  short local_10;
  short local_e;
  short local_c;

  local_16 = -(short)magnitude;
  local_18 = 0;
  local_14 = 0;
  RotMatrix((ushort *)&instance->rotation, auStack56);
  ApplyMatrixSV(auStack56, &local_18, &local_10);
  instance->xVel = (int)local_10;
  instance->yVel = (int)local_e;
  instance->zVel = (int)local_c;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PHYSICS_SetVAndAFromRot(struct _Instance *instance /*$s0*/, struct _Rotation *rot /*$a1*/, long v /*$s1*/, long a /*$s2*/)
// line 2765, offset 0x80077910
/* begin block 1 */
// Start line: 2766
// Start offset: 0x80077910
// Variables:
// 		struct SVECTOR flatPt; // stack offset -72
// 		struct MATRIX mat; // stack offset -64

/* begin block 1.1 */
// Start line: 2780
// Start offset: 0x80077958
// Variables:
// 		struct SVECTOR newPt; // stack offset -32
/* end block 1.1 */
// End offset: 0x80077958
// End Line: 2782

/* begin block 1.2 */
// Start line: 2799
// Start offset: 0x800779A4
// Variables:
// 		struct SVECTOR newPt; // stack offset -24
/* end block 1.2 */
// End offset: 0x800779A4
// End Line: 2801
/* end block 1 */
// End offset: 0x800779E8
// End Line: 2815

/* begin block 2 */
// Start line: 6198
/* end block 2 */
// End Line: 6199

void PHYSICS_SetVAndAFromRot(_Instance *instance, _Rotation *rot, long v, long a)

{
  undefined2 local_48;
  short local_46;
  undefined2 local_44;
  uint auStack64[8];
  short local_20;
  short local_1e;
  short local_1c;
  short local_18;
  short local_16;
  short local_14;

  if ((v != 0) || (a != 0))
  {
    RotMatrix((ushort *)&instance->rotation, auStack64);
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
    ApplyMatrixSV(auStack64, &local_48, &local_20);
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
    ApplyMatrixSV(auStack64, &local_48, &local_18);
    instance->xAccl = (int)local_18;
    instance->yAccl = (int)local_16;
    instance->zAccl = (int)local_14;
  }
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ PHYSICS_FindAFromDAndT(long d /*$a0*/, long t /*$a1*/)
// line 2822, offset 0x80077a00
/* begin block 1 */
// Start line: 6316
/* end block 1 */
// End Line: 6317

/* begin block 2 */
// Start line: 6317
/* end block 2 */
// End Line: 6318

long PHYSICS_FindAFromDAndT(long d, long t)

{
  int iVar1;

  if (t != 0)
  {
    iVar1 = (d << 0xd) / (t * t);
    if (iVar1 < 0)
    {
      iVar1 = iVar1 + 0xfff;
    }
    return iVar1 >> 0xc;
  }
  return 0;
}

// decompiled code
// original method signature:
// long /*$ra*/ PHYSICS_FindVFromAAndD(long a /*$a0*/, long d /*$a1*/)
// line 2835, offset 0x80077a3c
/* begin block 1 */
// Start line: 2836
// Start offset: 0x80077A3C
// Variables:
// 		long vsq; // $a0
/* end block 1 */
// End offset: 0x80077A64
// End Line: 2842

/* begin block 2 */
// Start line: 6342
/* end block 2 */
// End Line: 6343

/* begin block 3 */
// Start line: 6343
/* end block 3 */
// End Line: 6344

long PHYSICS_FindVFromAAndD(long a, long d)

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

// decompiled code
// original method signature:
// void /*$ra*/ PHYSICS_StopIfCloseToTarget(struct _Instance *instance /*$a0*/, int x /*$a1*/, int y /*$a2*/, int z /*$a3*/)
// line 2876, offset 0x80077a74
/* begin block 1 */
// Start line: 6427
/* end block 1 */
// End Line: 6428

/* begin block 2 */
// Start line: 6429
/* end block 2 */
// End Line: 6430

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

// decompiled code
// original method signature:
// int /*$ra*/ PHYSICS_CheckForTerrainCollide(struct _Instance *instance /*$a0*/, struct SVECTOR *startVec /*$a1*/, struct SVECTOR *endVec /*$a2*/, int segment /*$a3*/)
// line 2898, offset 0x80077b54
/* begin block 1 */
// Start line: 2899
// Start offset: 0x80077B54
// Variables:
// 		struct _PCollideInfo CInfo; // stack offset -56
// 		struct MATRIX *pTempMat; // $a1
/* end block 1 */
// End offset: 0x80077B54
// End Line: 2899

/* begin block 2 */
// Start line: 6471
/* end block 2 */
// End Line: 6472

int PHYSICS_CheckForTerrainCollide(_Instance *instance, SVECTOR *startVec, SVECTOR *endVec, int segment)

{
  _PCollideInfo local_38;

  local_38.collideType = 1;
  local_38.newPoint = endVec;
  local_38.oldPoint = startVec;
  PHYSICS_GenericLineCheckMask(instance, instance->matrix + segment, instance->matrix + segment, &local_38);
  return (uint)(local_38.type == 3);
}

// decompiled code
// original method signature:
// int /*$ra*/ PHYSICS_CheckForObjectCollide(struct _Instance *instance /*$a0*/, struct SVECTOR *startVec /*$a1*/, struct SVECTOR *endVec /*$a2*/, int segment /*$a3*/)
// line 2917, offset 0x80077b9c
/* begin block 1 */
// Start line: 2918
// Start offset: 0x80077B9C
// Variables:
// 		struct _PCollideInfo CInfo; // stack offset -56
// 		struct MATRIX *pTempMat; // $a1
/* end block 1 */
// End offset: 0x80077B9C
// End Line: 2918

/* begin block 2 */
// Start line: 6524
/* end block 2 */
// End Line: 6525

int PHYSICS_CheckForObjectCollide(_Instance *instance, SVECTOR *startVec, SVECTOR *endVec, int segment)

{
  _PCollideInfo local_38;

  local_38.collideType = 0x3e;
  local_38.newPoint = endVec;
  local_38.oldPoint = startVec;
  PHYSICS_GenericLineCheckMask(instance, instance->matrix + segment, instance->matrix + segment, &local_38);
  return (uint)(local_38.type != 0);
}

// decompiled code
// original method signature:
// int /*$ra*/ PHYSICS_CheckForValidMove(struct _Instance *instance /*$a0*/, struct SVECTOR *startVec /*$a1*/, struct SVECTOR *endVec /*$a2*/, int segment /*$a3*/)
// line 2938, offset 0x80077be0
/* begin block 1 */
// Start line: 2939
// Start offset: 0x80077BE0
// Variables:
// 		struct _PCollideInfo CInfo; // stack offset -56
// 		struct MATRIX *pTempMat; // $a1
// 		int rc; // $a0
/* end block 1 */
// End offset: 0x80077C3C
// End Line: 2962

/* begin block 2 */
// Start line: 6581
/* end block 2 */
// End Line: 6582

int PHYSICS_CheckForValidMove(_Instance *instance, SVECTOR *startVec, SVECTOR *endVec, int segment)

{
  int iVar1;
  uint uVar2;
  _PCollideInfo local_38;

  local_38.newPoint = endVec;
  local_38.oldPoint = startVec;
  PHYSICS_GenericLineCheck(instance, instance->matrix + segment, instance->matrix + segment, &local_38);
  iVar1 = PHYSICS_CheckFaceStick(&local_38);
  uVar2 = (uint)(iVar1 != 0);
  if (((uint)local_38.type - 2 < 2) || (local_38.type == 5))
  {
    uVar2 = uVar2 + 2;
  }
  return uVar2;
}

// decompiled code
// original method signature:
// int /*$ra*/ PHYSICS_CheckFaceStick(struct _PCollideInfo *CInfo /*$a0*/)
// line 2966, offset 0x80077c4c
/* begin block 1 */
// Start line: 2967
// Start offset: 0x80077C4C
// Variables:
// 		int rc; // $a1

/* begin block 1.1 */
// Start line: 2973
// Start offset: 0x80077C60
// Variables:
// 		struct _TFace *tface; // $a2
/* end block 1.1 */
// End offset: 0x80077C78
// End Line: 2975

/* begin block 1.2 */
// Start line: 2979
// Start offset: 0x80077CA4
// Variables:
// 		struct _HFace *hface; // stack offset -8
/* end block 1.2 */
// End offset: 0x80077CA4
// End Line: 2987
/* end block 1 */
// End offset: 0x80077CA4
// End Line: 2988

/* begin block 2 */
// Start line: 6640
/* end block 2 */
// End Line: 6641

int PHYSICS_CheckFaceStick(_PCollideInfo *CInfo)

{
  ushort uVar1;
  uint uVar2;

  uVar2 = 0;
  if (CInfo->type == 3)
  {
    uVar1 = *(ushort *)((int)CInfo->prim + 10);
    uVar2 = 0;
    if (uVar1 != 0xffff)
    {
      uVar2 = (uint)((*(ushort *)((int)&(CInfo->inst->node).prev[6].next[1].prev + (uint)uVar1 + 2) & 0x200) != 0);
    }
  }
  return uVar2;
}

// decompiled code
// original method signature:
// int /*$ra*/ PHYSICS_CheckDontGrabEdge(struct _PCollideInfo *CInfo /*$s0*/)
// line 2992, offset 0x80077cb0
/* begin block 1 */
// Start line: 2993
// Start offset: 0x80077CB0
// Variables:
// 		int rc; // $s1

/* begin block 1.1 */
// Start line: 2998
// Start offset: 0x80077CD4
// Variables:
// 		struct _TFace *tface; // $a0
// 		struct BSPTree *bsp; // $v0
/* end block 1.1 */
// End offset: 0x80077D4C
// End Line: 3007

/* begin block 1.2 */
// Start line: 3012
// Start offset: 0x80077D60
// Variables:
// 		struct _HFace *hface; // $v0
/* end block 1.2 */
// End offset: 0x80077D7C
// End Line: 3016

/* begin block 1.3 */
// Start line: 3021
// Start offset: 0x80077D8C
/* end block 1.3 */
// End offset: 0x80077DC0
// End Line: 3029
/* end block 1 */
// End offset: 0x80077DC0
// End Line: 3030

/* begin block 2 */
// Start line: 6692
/* end block 2 */
// End Line: 6693

int PHYSICS_CheckDontGrabEdge(_PCollideInfo *CInfo)

{
  short sVar1;
  ushort uVar2;
  ulong uVar3;
  uint uVar4;

  sVar1 = CInfo->type;
  uVar4 = 0;
  if (sVar1 == 3)
  {
    uVar2 = *(ushort *)((int)CInfo->prim + 10);
    if (uVar2 != 0xffff)
    {
      uVar4 = (uint)((*(ushort *)((int)&(CInfo->inst->node).prev[6].next[1].prev + (uint)uVar2 + 2) & 0x80) != 0);
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
      uVar3 = INSTANCE_Query(CInfo->inst, 1);
      if ((uVar3 & 0x20) == 0)
      {
        return 0;
      }
      uVar3 = INSTANCE_Query(CInfo->inst, 3);
      if ((uVar3 & 1) != 0)
      {
        return 0;
      }
    }
  }
  return 1;
}

// decompiled code
// original method signature:
// void /*$ra*/ PHYSICS_GenericLineCheckSetup(short x /*$a0*/, short y /*$a1*/, short z /*$a2*/, struct SVECTOR *inVec /*$a3*/)
// line 3035, offset 0x80077dd8
/* begin block 1 */
// Start line: 6778
/* end block 1 */
// End Line: 6779

/* begin block 2 */
// Start line: 6782
/* end block 2 */
// End Line: 6783

void PHYSICS_GenericLineCheckSetup(short x, short y, short z, SVECTOR *inVec)

{
  inVec->vx = x;
  inVec->vy = y;
  inVec->vz = z;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PHYSICS_GenericLineCheck(struct _Instance *instance /*$a0*/, struct MATRIX *transMat /*$a1*/, struct MATRIX *rotMat /*$a2*/, struct _PCollideInfo *cInfo /*$a3*/)
// line 3053, offset 0x80077de8
/* begin block 1 */
// Start line: 6814
/* end block 1 */
// End Line: 6815

void PHYSICS_GenericLineCheck(_Instance *instance, MATRIX *transMat, MATRIX *rotMat, _PCollideInfo *cInfo)

{
  cInfo->collideType = 0x3f;
  PHYSICS_GenericLineCheckMask(instance, transMat, rotMat, cInfo);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PHYSICS_GenericLineCheckMask(struct _Instance *instance /*$a0*/, struct MATRIX *transMat /*$a1*/, struct MATRIX *rotMat /*$a2*/, struct _PCollideInfo *cInfo /*$a3*/)
// line 3057, offset 0x80077e0c
/* begin block 1 */
// Start line: 3058
// Start offset: 0x80077E0C
// Variables:
// 		struct SVECTOR *startVec; // $t0
// 		struct SVECTOR *endVec; // $t1
// 		struct VECTOR outVec; // stack offset -24
/* end block 1 */
// End offset: 0x80077E0C
// End Line: 3058

/* begin block 2 */
// Start line: 6823
/* end block 2 */
// End Line: 6824

void PHYSICS_GenericLineCheckMask(_Instance *instance, MATRIX *transMat, MATRIX *rotMat, _PCollideInfo *cInfo)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 in_zero;
  undefined4 in_at;
  SVECTOR *pSVar4;
  SVECTOR *pSVar5;
  short local_18;
  short local_14;
  short local_10;

  pSVar4 = cInfo->oldPoint;
  pSVar5 = cInfo->newPoint;
  setCopControlWord(2, 0, *(undefined4 *)rotMat->m);
  setCopControlWord(2, 0x800, *(undefined4 *)(rotMat->m + 2));
  setCopControlWord(2, 0x1000, *(undefined4 *)(rotMat->m + 4));
  setCopControlWord(2, 0x1800, *(undefined4 *)(rotMat->m + 6));
  setCopControlWord(2, 0x2000, *(undefined4 *)(rotMat->m + 8));
  setCopReg(2, in_zero, *(undefined4 *)pSVar4);
  setCopReg(2, in_at, *(undefined4 *)&pSVar4->vz);
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
  setCopControlWord(2, 0, *(undefined4 *)rotMat->m);
  setCopControlWord(2, 0x800, *(undefined4 *)(rotMat->m + 2));
  setCopControlWord(2, 0x1000, *(undefined4 *)(rotMat->m + 4));
  setCopControlWord(2, 0x1800, *(undefined4 *)(rotMat->m + 6));
  setCopControlWord(2, 0x2000, *(undefined4 *)(rotMat->m + 8));
  setCopReg(2, in_zero, *(undefined4 *)pSVar5);
  setCopReg(2, in_at, *(undefined4 *)&pSVar5->vz);
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
