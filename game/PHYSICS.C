#include "THISDUST.H"
#include "PHYSICS.H"


// decompiled code
// original method signature: 
// void /*$ra*/ SetNoPtCollideInFamily(struct _Instance *instance /*$a0*/)
 // line 57, offset 0x80073e14
	/* begin block 1 */
		// Start line: 58
		// Start offset: 0x80073E14
		// Variables:
	// 		struct _Instance *child; // $s0
	/* end block 1 */
	// End offset: 0x80073E4C
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
  while (instance_00 != (_Instance *)0x0) {
    SetNoPtCollideInFamily(instance_00);
    instance_00 = instance_00->LinkSibling;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ResetNoPtCollideInFamily(struct _Instance *instance /*$a0*/)
 // line 67, offset 0x80073e5c
	/* begin block 1 */
		// Start line: 68
		// Start offset: 0x80073E5C
		// Variables:
	// 		struct _Instance *child; // $s0
	/* end block 1 */
	// End offset: 0x80073E98
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
  while (instance_00 != (_Instance *)0x0) {
    ResetNoPtCollideInFamily(instance_00);
    instance_00 = instance_00->LinkSibling;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSICS_CheckLineInWorld(struct _Instance *instance /*$a0*/, struct _PCollideInfo *pcollideInfo /*$a1*/)
 // line 79, offset 0x80073ea8
	/* begin block 1 */
		// Start line: 167
	/* end block 1 */
	// End Line: 168

void PHYSICS_CheckLineInWorld(_Instance *instance,_PCollideInfo *pcollideInfo)

{
  pcollideInfo->collideType = 0x3f;
  PHYSICS_CheckLineInWorldMask(instance,pcollideInfo);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSICS_CheckLineInWorldMask(struct _Instance *instance /*$s2*/, struct _PCollideInfo *pcollideInfo /*$s0*/)
 // line 85, offset 0x80073ecc
	/* begin block 1 */
		// Start line: 86
		// Start offset: 0x80073ECC
		// Variables:
	// 		struct Level *level; // $s1
	/* end block 1 */
	// End offset: 0x80073F28
	// End Line: 113

	/* begin block 2 */
		// Start line: 180
	/* end block 2 */
	// End Line: 181

void PHYSICS_CheckLineInWorldMask(_Instance *instance,_PCollideInfo *pcollideInfo)

{
  Level *level;
  
  level = STREAM_GetLevelWithID(instance->currentStreamUnitID);
  pcollideInfo->inst = (_Instance *)0x0;
  pcollideInfo->instance = instance;
  SetNoPtCollideInFamily(instance);
  if (level == (Level *)0x0) {
    pcollideInfo->type = 0;
  }
  else {
    COLLIDE_PointAndWorld(pcollideInfo,&gameTrackerX,level);
  }
  ResetNoPtCollideInFamily(instance);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsCheckLinkedMove(struct _Instance *instance /*$s2*/, int Data /*$s6*/, short Mode /*stack -72*/)
 // line 124, offset 0x80073f48
	/* begin block 1 */
		// Start line: 125
		// Start offset: 0x80073F48

		/* begin block 1.1 */
			// Start line: 128
			// Start offset: 0x80073F88
			// Variables:
		// 		struct evPhysicsLinkedMoveData *ptr; // $s4
		// 		struct _Instance *on; // $a0
		// 		struct MATRIX work; // stack offset -144
		// 		struct MATRIX *current; // $s3
		// 		struct VECTOR delta; // stack offset -112
		// 		long onx; // stack offset -64
		// 		long ony; // stack offset -60
		// 		long onz; // stack offset -56
		// 		long ix; // $s5
		// 		long iy; // $s7
		// 		long iz; // $fp

			/* begin block 1.1.1 */
				// Start line: 166
				// Start offset: 0x800740C0
				// Variables:
			// 		struct _G2EulerAngles_Type newRot; // stack offset -96
			// 		struct VECTOR newRelPos; // stack offset -88
			// 		long oldPosX; // stack offset -52
			// 		long oldPosY; // stack offset -48
			// 		long oldPosZ; // stack offset -44
			// 		int moved; // $s1
			// 		int rotated; // $s0
			/* end block 1.1.1 */
			// End offset: 0x80074294
			// End Line: 229
		/* end block 1.1 */
		// End offset: 0x800742EC
		// End Line: 239
	/* end block 1 */
	// End offset: 0x800742F4
	// End Line: 245

	/* begin block 2 */
		// Start line: 263
	/* end block 2 */
	// End Line: 264

/* WARNING: Could not reconcile some variable overlaps */

int PhysicsCheckLinkedMove(_Instance *instance,int Data,short Mode)

{
  short sVar1;
  short sVar2;
  short sVar3;
  bool bVar4;
  bool bVar5;
  long lVar6;
  int iVar7;
  uint *puVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  _G2Matrix_Type _Stack144;
  uint local_70;
  int local_6c;
  int local_68;
  _G2EulerAngles_Type local_60;
  short local_58 [2];
  short local_54;
  short local_50;
  ushort local_48;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  if (instance->matrix == (MATRIX *)0x0) {
    instance->attachedID = 0;
    iVar7 = 0;
  }
  else {
    puVar9 = (undefined4 *)(*(int *)(*(int *)Data + 0x40) + *(int *)(Data + 4) * 0x20);
    local_40 = puVar9[5];
    local_3c = puVar9[6];
    local_38 = puVar9[7];
    sVar1 = (instance->position).x;
    iVar10 = (int)sVar1;
    sVar2 = (instance->position).y;
    iVar11 = (int)sVar2;
    iVar7 = *(int *)(*(int *)Data + 0x3c);
    sVar3 = (instance->position).z;
    iVar12 = (int)sVar3;
    local_48 = Mode;
    if ((iVar7 == instance->attachedID) &&
       (bVar4 = false, *(int *)(Data + 4) == instance->attachedSegment)) {
      local_34 = (int)(instance->oldPos).x;
      local_30 = (int)(instance->oldPos).y;
      local_2c = (int)(instance->oldPos).z;
      bVar5 = false;
      if ((*(int *)&instance->rotation != *(int *)&instance->oldRotation) ||
         ((instance->rotation).z != (instance->oldRotation).z)) {
        bVar5 = true;
      }
      if (((iVar10 != local_34) || (iVar11 != local_30)) || (iVar12 != local_2c)) {
        bVar4 = true;
      }
      if ((bVar4) || (bVar5)) {
        TransposeMatrix(puVar9,(undefined4 *)&_Stack144);
        if (bVar5) {
          MulMatrix0((undefined4 *)&_Stack144,(ushort *)instance->matrix,
                     (uint *)&instance->relativeMatrix);
        }
        if (bVar4) {
          local_70 = iVar10 - local_34;
          local_6c = iVar11 - local_30;
          local_68 = iVar12 - local_2c;
          ApplyMatrixLV((undefined4 *)&_Stack144,&local_70,(int *)&local_70);
          (instance->relativeMatrix).t[0] = (instance->relativeMatrix).t[0] + local_70;
          (instance->relativeMatrix).t[1] = (instance->relativeMatrix).t[1] + local_6c;
          (instance->relativeMatrix).t[2] = (instance->relativeMatrix).t[2] + local_68;
        }
      }
      ApplyMatrixLV(puVar9,(uint *)(instance->relativeMatrix).t,(int *)local_58);
      MulMatrix0(puVar9,(ushort *)&instance->relativeMatrix,(uint *)&_Stack144);
      G2EulerAngles_FromMatrix(&local_60,&_Stack144,0x15);
      *(short *)(Data + 8) = (local_58[0] + (short)local_40) - sVar1;
      *(short *)(Data + 10) = (local_54 + (short)local_3c) - sVar2;
      *(short *)(Data + 0xc) = (local_50 + (short)local_38) - sVar3;
      *(short *)(Data + 0x10) = local_60.x - (instance->oldRotation).x;
      *(short *)(Data + 0x12) = local_60.y - (instance->oldRotation).y;
      *(short *)(Data + 0x14) = local_60.z - (instance->oldRotation).z;
    }
    else {
      instance->attachedID = iVar7;
      lVar6 = *(long *)(Data + 4);
      instance->zAccl = 0;
      instance->zVel = 0;
      instance->attachedSegment = lVar6;
      TransposeMatrix(puVar9,(undefined4 *)&_Stack144);
      local_70 = iVar10 - local_40;
      puVar8 = (uint *)(instance->relativeMatrix).t;
      local_6c = iVar11 - local_3c;
      local_68 = iVar12 - local_38;
      ApplyMatrixLV((undefined4 *)&_Stack144,&local_70,(int *)puVar8);
      MulMatrix0((undefined4 *)&_Stack144,(ushort *)instance->matrix,
                 (uint *)&instance->relativeMatrix);
      ApplyMatrixLV(puVar9,puVar8,(int *)&local_70);
      *(undefined2 *)(Data + 0x14) = 0;
      *(undefined2 *)(Data + 0x12) = 0;
      *(undefined2 *)(Data + 0x10) = 0;
      *(short *)(Data + 8) = sVar1 - ((short)local_70 + (short)local_40);
      *(short *)(Data + 10) = sVar2 - ((short)local_6c + (short)local_3c);
      *(short *)(Data + 0xc) = sVar3 - ((short)local_68 + (short)local_38);
    }
    if ((local_48 & 4) != 0) {
      PhysicsDefaultLinkedMoveResponse
                (instance,(evPhysicsLinkedMoveData *)Data,((uint)(local_48 >> 3) ^ 1) & 1);
    }
    if ((local_48 & 2) != 0) {
      INSTANCE_Post(instance,0x4010008,Data);
    }
    iVar7 = 0x10000;
  }
  return iVar7;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PhysicsDefaultLinkedMoveResponse(struct _Instance *instance /*$s0*/, struct evPhysicsLinkedMoveData *Data /*$s1*/, int updateTransforms /*$a2*/)
 // line 251, offset 0x80074324
	/* begin block 1 */
		// Start line: 564
	/* end block 1 */
	// End Line: 565

void PhysicsDefaultLinkedMoveResponse
               (_Instance *instance,evPhysicsLinkedMoveData *Data,int updateTransforms)

{
  (instance->position).x = (instance->position).x + (Data->posDelta).x;
  (instance->position).y = (instance->position).y + (Data->posDelta).y;
  (instance->position).z = (instance->position).z + (Data->posDelta).z;
  if (updateTransforms != 0) {
    COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)&Data->posDelta);
  }
  (instance->rotation).z = (instance->rotation).z + (Data->rotDelta).z;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsCheckGravity(struct _Instance *instance /*$s1*/, int Data /*$s7*/, short Mode /*$s5*/)
 // line 275, offset 0x800743ac
	/* begin block 1 */
		// Start line: 276
		// Start offset: 0x800743AC
		// Variables:
	// 		struct evPhysicsGravityData *Ptr; // $s3
	// 		struct SVECTOR D; // stack offset -120
	// 		struct SVECTOR N; // stack offset -112
	// 		short Dot; // $v0
	// 		int rc; // $s4
	// 		struct _PCollideInfo CInfo; // stack offset -104
	// 		struct SVECTOR Old; // stack offset -56
	// 		struct SVECTOR New; // stack offset -48
	// 		int slide; // $s6

		/* begin block 1.1 */
			// Start line: 305
			// Start offset: 0x8007448C
			// Variables:
		// 		struct Level *level; // $s2
		// 		struct _TFace *tface; // $s0
		/* end block 1.1 */
		// End offset: 0x8007453C
		// End Line: 328
	/* end block 1 */
	// End offset: 0x80074AA4
	// End Line: 510

	/* begin block 2 */
		// Start line: 612
	/* end block 2 */
	// End Line: 613

int PhysicsCheckGravity(_Instance *instance,int Data,short Mode)

{
  bool bVar1;
  short sVar2;
  int Data_00;
  _Instance *p_Var3;
  int iVar4;
  uint uVar5;
  int iVar6;
  NodeType *pNVar7;
  int iVar8;
  _TFace *tface;
  uint uVar9;
  _PCollideInfo local_68;
  SVECTOR local_38;
  SVECTOR local_30;
  
  local_38.vx = (instance->position).x;
  uVar9 = 0;
  local_38.vy = (instance->position).y;
  bVar1 = false;
  uVar5 = (uint)(ushort)(instance->position).z;
  Data_00 = uVar5 + *(ushort *)Data;
  local_38.vz = (short)Data_00;
  iVar6 = uVar5 - *(ushort *)(Data + 2);
  local_30.vz = (short)iVar6;
  local_68.newPoint = &local_30;
  local_68.oldPoint = &local_38;
  local_30.vx = local_38.vx;
  local_30.vy = local_38.vy;
  if (Data_00 * 0x10000 < iVar6 * 0x10000) {
    local_68.type = 0;
    goto LAB_80074574;
  }
  if (instance->cachedTFace == -1) {
    instance->waterFace = (_TFace *)0x0;
    gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x8000;
LAB_80074558:
    PHYSICS_CheckLineInWorld(instance,&local_68);
  }
  else {
    p_Var3 = (_Instance *)STREAM_GetLevelWithID(instance->currentStreamUnitID);
    pNVar7 = (p_Var3->node).prev;
    gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x8000;
    tface = (_TFace *)((int)pNVar7[4].prev + (int)instance->cachedTFace * 0xc);
    Data_00 = COLLIDE_PointAndTfaceFunc
                        ((_Terrain *)(p_Var3->node).prev,
                         (BSPTree *)((int)pNVar7[10].prev + (int)instance->cachedBSPTree * 0x24),
                         (_SVector *)&local_30,(_SVector *)&local_38,tface,0,0);
    if (Data_00 == 0) {
      instance->waterFace = (_TFace *)0x0;
      goto LAB_80074558;
    }
    local_68.type = 3;
    local_68.segment = instance->cachedBSPTree;
    local_68.prim = tface;
    local_68.inst = p_Var3;
    COLLIDE_GetNormal(tface->normal,(short *)(p_Var3->node).prev[4].next,
                      (_SVector *)&local_68.wNormal);
  }
  gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffff7fff;
LAB_80074574:
  if (((((uint)local_68.type - 2 < 2) || (local_68.type == 5)) &&
      (Data_00 = (int)local_68.wNormal.vz, Data_00 < *(short *)(Data + 10))) && (0 < Data_00)) {
    iVar8 = (int)-local_68.wNormal.vz;
    iVar6 = -(local_68.wNormal.vx * iVar8);
    if (0 < local_68.wNormal.vx * iVar8) {
      iVar6 = iVar6 + 0xfff;
    }
    iVar4 = -(local_68.wNormal.vy * iVar8);
    Data_00 = Data_00 * iVar8;
    if (0 < local_68.wNormal.vy * iVar8) {
      iVar4 = iVar4 + 0xfff;
    }
    if (Data_00 < 0) {
      Data_00 = Data_00 + 0xfff;
    }
    if (instance->zVel < -0x30) {
      sVar2 = -*(short *)&instance->zVel;
    }
    else {
      sVar2 = 0x30;
    }
    iVar8 = (int)sVar2;
    iVar6 = (short)(iVar6 >> 0xc) * iVar8;
    if (iVar6 < 0) {
      iVar6 = iVar6 + 0xfff;
    }
    iVar4 = (short)(iVar4 >> 0xc) * iVar8;
    local_38.vx = (local_68.newPoint)->vx + (short)(iVar6 >> 0xc);
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0xfff;
    }
    iVar8 = (short)(-0x1000 - (short)(Data_00 >> 0xc)) * iVar8;
    local_38.vy = (local_68.newPoint)->vy + (short)(iVar4 >> 0xc);
    if (iVar8 < 0) {
      iVar8 = iVar8 + 0xfff;
    }
    local_30.vz = (local_68.newPoint)->vz + (short)(iVar8 >> 0xc);
    local_38.vz = local_30.vz + *(short *)Data;
    local_30.vz = local_30.vz - *(short *)(Data + 2);
    local_30.vx = local_38.vx;
    local_30.vy = local_38.vy;
    PHYSICS_CheckLineInWorld(instance,&local_68);
    if (((uint)local_68.type - 2 < 2) || (local_68.type == 5)) {
      if ((local_68.wNormal.vz < *(short *)(Data + 10)) && (0 < local_68.wNormal.vz)) {
        bVar1 = true;
      }
      else {
        (instance->position).x = (local_68.newPoint)->vx;
        (instance->position).y = (local_68.newPoint)->vy;
      }
    }
  }
  if (local_68.type == 3) {
    instance->cachedBSPTree = local_68.segment;
    sVar2 = (short)((int)((int)local_68.prim - (int)((local_68.inst)->node).prev[4].prev) *
                    -0x55555555 >> 2);
  }
  else {
    sVar2 = -1;
  }
  instance->cachedTFace = sVar2;
  if (((uint)local_68.type - 2 < 2) || (local_68.type == 5)) {
    if ((Mode & 7U) != 0) {
      if (bVar1) {
        *(short *)(Data + 4) = (local_68.newPoint)->vx - (instance->position).x;
        *(short *)(Data + 6) = (local_68.newPoint)->vy - (instance->position).y;
      }
      else {
        *(undefined2 *)(Data + 4) = 0;
        *(undefined2 *)(Data + 6) = 0;
      }
      *(short *)(Data + 8) = (local_68.newPoint)->vz - (instance->position).z;
    }
    if (((Mode & 2U) != 0) && (!bVar1)) {
      INSTANCE_Post(instance,0x4010008,Data);
    }
    if (bVar1) {
      if ((Mode & 2U) != 0) {
        INSTANCE_Post(instance,0x4010200,Data);
      }
      uVar9 = 0x100000;
    }
    if (((Mode & 4U) != 0) &&
       (((Data_00 = CheckPhysOb(instance), Data_00 == 0 ||
         (Data_00 = CheckPhysObFamily(instance,1), Data_00 == 0)) || (instance->attachedID == 0))))
    {
      PhysicsDefaultGravityResponse(instance,(evPhysicsGravityData *)Data);
    }
    if (local_68.type == 1) {
      (instance->wNormal).x = 0;
      (instance->wNormal).y = 0;
      (instance->wNormal).z = 0x1000;
    }
    else {
      (instance->wNormal).x = local_68.wNormal.vx;
      (instance->wNormal).y = local_68.wNormal.vy;
      (instance->wNormal).z = local_68.wNormal.vz;
    }
    if (((local_68.type == 3) || (local_68.inst == (_Instance *)0x0)) ||
       (((local_68.inst)->object->oflags & 0x400U) == 0)) {
      instance->attachedID = 0;
    }
    else {
      Data_00 = SetPhysicsLinkedMoveData
                          (local_68.inst,(int)local_68.segment,(_SVector *)0x0,(_SVector *)0x0);
      uVar5 = PhysicsCheckLinkedMove(instance,Data_00,Mode);
      uVar9 = uVar9 | uVar5;
    }
    if ((instance->flags2 & 0x40U) != 0) {
      sVar2 = (instance->position).z;
      *(undefined4 *)&instance->shadowPosition = *(undefined4 *)&instance->position;
      (instance->shadowPosition).z = sVar2;
      instance->flags = instance->flags | 0x8000000;
    }
    if ((local_68.type == 3) && (instance->tface != local_68.prim)) {
      instance->oldTFace = instance->tface;
      instance->tface = local_68.prim;
      *(_Instance **)&instance->tfaceLevel = local_68.inst;
      instance->bspTree = (int)local_68.segment;
      if (local_68.segment == 0) {
        uVar9 = uVar9 | 0x80000;
      }
    }
    uVar9 = uVar9 | 1;
  }
  else {
    if (instance->tface != (_TFace *)0x0) {
      instance->oldTFace = instance->tface;
      instance->tface = (_TFace *)0x0;
      instance->tfaceLevel = (void *)0x0;
      instance->bspTree = 0;
    }
    instance->attachedID = 0;
    if ((Mode & 2U) != 0) {
      INSTANCE_Post(instance,0x4000001,Data);
    }
  }
  return uVar9;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PhysicsDefaultGravityResponse(struct _Instance *instance /*$a0*/, struct evPhysicsGravityData *Data /*$a1*/)
 // line 516, offset 0x80074ad4
	/* begin block 1 */
		// Start line: 1209
	/* end block 1 */
	// End Line: 1210

	/* begin block 2 */
		// Start line: 1210
	/* end block 2 */
	// End Line: 1211

void PhysicsDefaultGravityResponse(_Instance *instance,evPhysicsGravityData *Data)

{
  (instance->position).x = (instance->position).x + Data->x;
  (instance->position).y = (instance->position).y + Data->y;
  if ((instance == gameTrackerX.playerInstance) && (0x80 < Data->z)) {
    (instance->position).z = (instance->position).z + 0x80;
    return;
  }
  (instance->position).z = (instance->position).z + Data->z;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsCheckEdgeGrabbing(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$a1*/, int Data /*stack 8*/, short Mode /*$s7*/)
 // line 535, offset 0x80074b4c
	/* begin block 1 */
		// Start line: 536
		// Start offset: 0x80074B4C
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
	// End offset: 0x800751AC
	// End Line: 812

	/* begin block 2 */
		// Start line: 1247
	/* end block 2 */
	// End Line: 1248

int PhysicsCheckEdgeGrabbing(_Instance *instance,GameTracker *gameTracker,int Data,short Mode)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  bool bVar4;
  uint uVar5;
  undefined4 in_zero;
  undefined4 in_at;
  ushort uVar6;
  short *psVar7;
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
  if ((Mode & 1U) != 0) {
    *(undefined4 *)(Data + 0x18) = 0;
  }
  local_68.oldPoint = (SVECTOR *)&local_38;
  local_68.newPoint = (SVECTOR *)&local_30;
  psVar7 = (short *)INSTANCE_Query(instance,7);
  if (psVar7 == (short *)0x0) {
    pTempMat_41 = (MATRIX *)instance->matrix;
  }
  else {
    pTempMat_41 = (MATRIX *)&TempMat_40;
    RotMatrix(psVar7,&TempMat_40);
  }
  PHYSICS_GenericLineCheckSetup
            (0,0,(short)(((uint)*(ushort *)Data + (uint)*(ushort *)(Data + 4)) * 0x10000 >> 0x10),
             (SVECTOR *)&local_38);
  PHYSICS_GenericLineCheckSetup
            (0,*(short *)(Data + 2),
             (short)(((uint)*(ushort *)Data + (uint)*(ushort *)(Data + 4)) * 0x10000 >> 0x10),
             (SVECTOR *)&local_30);
  PHYSICS_GenericLineCheck(instance,(MATRIX *)instance->matrix,pTempMat_41,&local_68);
  iVar8 = PHYSICS_CheckFaceStick(&local_68);
  bVar10 = iVar8 != 0;
  if (local_68.type == 0) {
    PHYSICS_GenericLineCheckSetup(0,0,*(short *)(Data + 4),(SVECTOR *)&local_38);
    PHYSICS_GenericLineCheckSetup
              (0,0,(short)(((uint)*(ushort *)Data + (uint)*(ushort *)(Data + 4) + 0x80) * 0x10000 >>
                          0x10),(SVECTOR *)&local_30);
    PHYSICS_GenericLineCheck(instance,(MATRIX *)instance->matrix,pTempMat_41,&local_68);
    if (local_68.type == 0) goto LAB_80074cd8;
  }
  bVar4 = false;
LAB_80074cd8:
  if ((bVar4) || (bVar10)) {
    uVar5 = local_2c & 0xffff0000;
    local_2c = uVar5 | *(ushort *)Data;
    setCopControlWord(2,0,*(undefined4 *)pTempMat_41->m);
    setCopControlWord(2,0x800,*(undefined4 *)(pTempMat_41->m + 2));
    setCopControlWord(2,0x1000,*(undefined4 *)(pTempMat_41->m + 4));
    setCopControlWord(2,0x1800,*(undefined4 *)(pTempMat_41->m + 6));
    setCopControlWord(2,0x2000,*(undefined4 *)(pTempMat_41->m + 8));
    setCopReg(2,in_zero,0);
    setCopReg(2,in_at,local_2c);
    copFunction(2,0x486012);
    uVar1 = getCopReg(2,0x19);
    uVar2 = getCopReg(2,0x1a);
    uVar3 = getCopReg(2,0x1b);
    local_78 = (short)uVar1;
    local_74 = (short)uVar2;
    local_38 = CONCAT22((instance->position).y + local_74,(instance->position).x + local_78);
    local_70 = (short)uVar3;
    local_34 = local_34 & 0xffff0000 | (uint)(ushort)((instance->position).z + local_70);
    local_30 = (uint)*(ushort *)(Data + 2) << 0x10;
    local_2c = uVar5 | *(ushort *)Data;
    setCopControlWord(2,0,*(undefined4 *)pTempMat_41->m);
    setCopControlWord(2,0x800,*(undefined4 *)(pTempMat_41->m + 2));
    setCopControlWord(2,0x1000,*(undefined4 *)(pTempMat_41->m + 4));
    setCopControlWord(2,0x1800,*(undefined4 *)(pTempMat_41->m + 6));
    setCopControlWord(2,0x2000,*(undefined4 *)(pTempMat_41->m + 8));
    setCopReg(2,in_zero,local_30);
    setCopReg(2,in_at,local_2c);
    copFunction(2,0x486012);
    uVar1 = getCopReg(2,0x19);
    uVar2 = getCopReg(2,0x1a);
    uVar3 = getCopReg(2,0x1b);
    local_78 = (short)uVar1;
    local_74 = (short)uVar2;
    local_30 = CONCAT22((instance->position).y + local_74,(instance->position).x + local_78);
    local_70 = (short)uVar3;
    local_2c = uVar5 | (ushort)((instance->position).z + local_70);
    PHYSICS_CheckLineInWorld(instance,&local_68);
    iVar8 = PHYSICS_CheckDontGrabEdge(&local_68);
    if ((iVar8 == 0) && (((local_68.type == 3 || (local_68.type == 5)) || (local_68.type == 2)))) {
      iVar9 = PHYSICS_CheckFaceStick(&local_68);
      uVar5 = local_34;
      if (iVar9 != 0) {
        bVar10 = (bool)(bVar10 + '\x01');
      }
      if ((Mode & 1U) != 0) {
        **(short **)(Data + 0xc) = local_68.wNormal.vx;
        *(short *)(*(int *)(Data + 0xc) + 2) = local_68.wNormal.vy;
        *(short *)(*(int *)(Data + 0xc) + 4) = local_68.wNormal.vz;
        *(short *)(*(int *)(Data + 0x14) + 2) = (local_68.newPoint)->vy - (local_68.oldPoint)->vy;
        **(short **)(Data + 0x14) = (local_68.newPoint)->vx - (local_68.oldPoint)->vx;
        if ((local_68.type == 5) || (local_68.type == 2)) {
          *(_Instance **)(Data + 0x18) = local_68.inst;
        }
      }
      iVar9 = 2;
      local_34 = local_34 & 0xffff0000;
      setCopControlWord(2,0,*(undefined4 *)pTempMat_41->m);
      setCopControlWord(2,0x800,*(undefined4 *)(pTempMat_41->m + 2));
      setCopControlWord(2,0x1000,*(undefined4 *)(pTempMat_41->m + 4));
      setCopControlWord(2,0x1800,*(undefined4 *)(pTempMat_41->m + 6));
      setCopControlWord(2,0x2000,*(undefined4 *)(pTempMat_41->m + 8));
      setCopReg(2,in_zero,0xfff00000);
      setCopReg(2,in_at,local_34);
      copFunction(2,0x486012);
      uVar1 = getCopReg(2,0x19);
      uVar2 = getCopReg(2,0x1a);
      uVar3 = getCopReg(2,0x1b);
      local_78 = (short)uVar1;
      local_78 = (local_68.newPoint)->vx + local_78;
      local_74 = (short)uVar2;
      local_70 = (short)uVar3;
      local_74 = (local_68.newPoint)->vy + local_74;
      local_30 = CONCAT22(local_74,local_78);
      local_38 = CONCAT22(local_74,local_78);
      uVar6 = (local_68.newPoint)->vz + local_70;
      local_2c = local_2c & 0xffff0000 | (uint)uVar6;
      local_34 = uVar5 & 0xffff0000 | (uint)(ushort)(uVar6 + *(short *)(Data + 4));
      PHYSICS_CheckLineInWorld(instance,&local_68);
      iVar8 = PHYSICS_CheckDontGrabEdge(&local_68);
      if ((iVar8 == 0) && (((local_68.type == 3 || (local_68.type == 5)) || (local_68.type == 2))))
      {
        if ((Mode & 1U) != 0) {
          **(short **)(Data + 0x10) = local_68.wNormal.vx;
          *(short *)(*(int *)(Data + 0x10) + 2) = local_68.wNormal.vy;
          *(short *)(*(int *)(Data + 0x10) + 4) = local_68.wNormal.vz;
          *(short *)(*(int *)(Data + 0x14) + 4) = (local_68.newPoint)->vz - (local_68.oldPoint)->vz;
          if ((local_68.type == 5) || (local_68.type == 2)) {
            *(_Instance **)(Data + 0x18) = local_68.inst;
          }
        }
        if (0xb50 < local_68.wNormal.vz) {
          iVar9 = 6;
          if ((Mode & 2U) != 0) {
            INSTANCE_Post(instance,0x4010010,Data);
          }
          if ((Mode & 4U) != 0) {
            PhysicsDefaultEdgeGrabResponse(instance,(evPhysicsEdgeData *)Data,0);
          }
        }
      }
    }
  }
  else {
    if (((local_68.type == 3) || (local_68.type == 5)) || (local_68.type == 2)) {
      if ((Mode & 1U) != 0) {
        **(short **)(Data + 0xc) = local_68.wNormal.vx;
        *(short *)(*(int *)(Data + 0xc) + 2) = local_68.wNormal.vy;
        *(short *)(*(int *)(Data + 0xc) + 4) = local_68.wNormal.vz;
        *(short *)(*(int *)(Data + 0x14) + 2) = (local_68.newPoint)->vy - (local_68.oldPoint)->vy;
        **(short **)(Data + 0x14) = (local_68.newPoint)->vx - (local_68.oldPoint)->vx;
        *(undefined2 *)(*(int *)(Data + 0x14) + 4) = 0;
        if ((local_68.type == 5) || (local_68.type == 2)) {
          *(_Instance **)(Data + 0x18) = local_68.inst;
        }
      }
      iVar9 = 2;
    }
  }
  if (((Mode & 2U) != 0) && (bVar10 == true)) {
    INSTANCE_Post(instance,0x4000011,Data);
  }
  return iVar9;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PhysicsDefaultEdgeGrabResponse(struct _Instance *instance /*$s1*/, struct evPhysicsEdgeData *Data /*$s0*/, int blockFlag /*$a2*/)
 // line 825, offset 0x800751e0
	/* begin block 1 */
		// Start line: 826
		// Start offset: 0x800751E0
		// Variables:
	// 		struct _SVector normal; // stack offset -56
	// 		struct _G2EulerAngles_Type ea1; // stack offset -48
	// 		struct VECTOR OutTrans; // stack offset -40
	// 		static struct MATRIX TempMat; // offset 0x30
	// 		struct SVECTOR New; // stack offset -24

		/* begin block 1.1 */
			// Start line: 904
			// Start offset: 0x80075300
			// Variables:
		// 		long dp; // $v0
		/* end block 1.1 */
		// End offset: 0x80075300
		// End Line: 904
	/* end block 1 */
	// End offset: 0x80075300
	// End Line: 904

	/* begin block 2 */
		// Start line: 1919
	/* end block 2 */
	// End Line: 1920

/* WARNING: Could not reconcile some variable overlaps */

void PhysicsDefaultEdgeGrabResponse(_Instance *instance,evPhysicsEdgeData *Data,int blockFlag)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar5;
  _SVector *p_Var6;
  _SVector local_38;
  _G2EulerAngles_Type local_30;
  short local_28;
  short local_24;
  short local_20;
  undefined4 local_14;
  
  if (blockFlag == 0) {
    local_38.x = Data->Normal1->x;
    local_38.y = Data->Normal1->y;
    local_38.z = 0;
    MATH3D_RotateAxisToVector((MATRIX *)&TempMat_44,(MATRIX *)instance->matrix,&local_38,AXIS_Y);
    G2EulerAngles_FromMatrix(&local_30,(_G2Matrix_Type *)&TempMat_44,0);
    (instance->rotation).x = 0;
  }
  else {
    local_38.z = 0;
    local_38.y = 0;
    local_38.x = 0;
    sVar1 = Data->Normal1->y;
    if (sVar1 < 0x201) {
      if (sVar1 < -0x200) {
        local_38.y = -0x1000;
        local_30.z = -0x800;
      }
    }
    else {
      local_38.y = 0x1000;
      local_30.z = 0;
    }
    sVar1 = Data->Normal1->x;
    if (sVar1 < 0x201) {
      if (sVar1 < -0x200) {
        local_38.x = -0x1000;
        local_30.z = 0x400;
      }
    }
    else {
      local_38.x = 0x1000;
      local_30.z = -0x400;
    }
    local_30.y = 0;
    local_30.x = 0;
    MATH3D_RotateAxisToVector((MATRIX *)&TempMat_44,(MATRIX *)instance->matrix,&local_38,AXIS_Y);
    (instance->rotation).x = 0;
  }
  (instance->rotation).y = 0;
  (instance->rotation).z = local_30.z;
  Data->zRot = (int)local_30.z;
  local_14 = CONCAT22(local_14._2_2_,Data->ZDistance);
  setCopControlWord(2,0,TempMat_44);
  setCopControlWord(2,0x800,DAT_800d4cd4);
  setCopControlWord(2,0x1000,DAT_800d4cd8);
  setCopControlWord(2,0x1800,DAT_800d4cdc);
  setCopControlWord(2,0x2000,DAT_800d4ce0);
  setCopReg(2,in_zero,*(undefined4 *)&Data->XDistance);
  setCopReg(2,in_at,local_14);
  copFunction(2,0x486012);
  uVar2 = getCopReg(2,0x19);
  uVar3 = getCopReg(2,0x1a);
  uVar4 = getCopReg(2,0x1b);
  p_Var6 = Data->Delta;
  iVar5 = (int)p_Var6->x * (int)local_38.x + (int)p_Var6->y * (int)local_38.y +
          (int)p_Var6->z * (int)local_38.z >> 0xc;
  p_Var6->x = (short)(iVar5 * (int)local_38.x >> 0xc);
  Data->Delta->y = (short)(iVar5 * local_38.y >> 0xc);
  local_20 = (short)uVar4;
  (instance->position).z =
       (instance->position).z -
       (local_20 - (Data->Delta->z + Data->UpperOffset + Data->AboveOffset));
  local_28 = (short)uVar2;
  (instance->position).x = (instance->position).x + (Data->Delta->x - local_28);
  local_24 = (short)uVar3;
  (instance->position).y = (instance->position).y - (local_24 - Data->Delta->y);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsCheckSliding(struct _Instance *instance /*$s3*/, int Data /*$a1*/, short Mode /*$s6*/)
 // line 955, offset 0x80075480
	/* begin block 1 */
		// Start line: 956
		// Start offset: 0x80075480
		// Variables:
	// 		struct evPhysicsSlideData *Ptr; // $s0
	// 		int rc; // $s1
	// 		struct VECTOR OutTrans; // stack offset -120
	// 		struct _SVector normal; // stack offset -104
	// 		struct _PCollideInfo CInfo; // stack offset -96
	// 		struct SVECTOR Old; // stack offset -48
	// 		struct SVECTOR New; // stack offset -40
	// 		static struct MATRIX *pTempMat; // offset 0x50

		/* begin block 1.1 */
			// Start line: 987
			// Start offset: 0x80075508
		/* end block 1.1 */
		// End offset: 0x80075508
		// End Line: 989

		/* begin block 1.2 */
			// Start line: 996
			// Start offset: 0x80075544
			// Variables:
		// 		int Temp; // $a3
		/* end block 1.2 */
		// End offset: 0x80075618
		// End Line: 1004
	/* end block 1 */
	// End offset: 0x80075900
	// End Line: 1138

	/* begin block 2 */
		// Start line: 2192
	/* end block 2 */
	// End Line: 2193

int PhysicsCheckSliding(_Instance *instance,int Data,short Mode)

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
  pTempMat_47 = instance->matrix + *(short *)(Data + 0x18);
  local_30.vx = *(short *)pTempMat_47->t;
  local_30.vy = *(short *)(pTempMat_47->t + 1);
  uVar3 = 0;
  local_30.vz = *(short *)(pTempMat_47->t + 2) + *(short *)(Data + 0x1e);
  if (instance->tface == (_TFace *)0x0) {
    local_68.x = 0;
    local_68.y = 0;
    local_68.z = 0x1000;
  }
  else {
    pLVar1 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
    COLLIDE_GetNormal(instance->tface->normal,(short *)pLVar1->terrain->normalList,&local_68);
  }
  iVar2 = (int)*(short *)Data * (int)local_68.x + (int)*(short *)(Data + 2) * (int)local_68.y +
          (int)*(short *)(Data + 4) * (int)local_68.z;
  *(int *)(Data + 0x24) = iVar2;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  *(int *)(Data + 0x24) = iVar2 >> 0xc;
  iVar2 = (iVar2 >> 0xc) * (int)local_68.x;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  local_78 = *(short *)Data - (short)(iVar2 >> 0xc);
  iVar2 = *(int *)(Data + 0x24) * (int)local_68.y;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  local_74 = *(short *)(Data + 2) - (short)(iVar2 >> 0xc);
  iVar2 = *(int *)(Data + 0x24) * (int)local_68.z;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  local_70 = *(short *)(Data + 4) - (short)(iVar2 >> 0xc);
  local_28.vx = local_30.vx + local_78;
  local_28.vy = local_30.vy + local_74;
  local_28.vz = local_30.vz + local_70;
  PHYSICS_CheckLineInWorld(instance,&local_60);
  if ((local_60.type == 3) || (local_60.type == 5)) {
    if ((Mode & 1U) != 0) {
      *(short *)(Data + 8) = local_60.wNormal.vx;
      *(short *)(Data + 10) = local_60.wNormal.vy;
      *(short *)(Data + 0xc) = local_60.wNormal.vz;
      *(short *)Data = local_30.vx - local_28.vx;
      *(short *)(Data + 2) = local_30.vy - local_28.vy;
      *(short *)(Data + 4) = local_30.vz - local_28.vz;
    }
    local_30.vx = *(short *)pTempMat_47->t + local_78;
    local_30.vy = *(short *)(pTempMat_47->t + 1) + local_74;
    local_28.vz = local_70 + *(short *)(pTempMat_47->t + 2) + *(short *)(Data + 0x1e);
    local_30.vz = local_28.vz + *(short *)(Data + 0x1c);
    local_28.vx = local_30.vx;
    local_28.vy = local_30.vy;
    PHYSICS_CheckLineInWorld(instance,&local_60);
    uVar3 = 2;
    if ((local_60.type == 3) || (local_60.type == 5)) {
      if ((Mode & 1U) != 0) {
        *(short *)(Data + 0x10) = local_60.wNormal.vx;
        *(short *)(Data + 0x12) = local_60.wNormal.vy;
        *(short *)(Data + 0x14) = local_60.wNormal.vz;
        *(short *)(Data + 0x1e) = local_30.vz - local_28.vz;
      }
      uVar3 = 6;
    }
    local_60.type = 0;
  }
  else {
    if (local_60.type == 0) {
      local_30.vx = *(short *)pTempMat_47->t + local_78;
      local_30.vy = *(short *)(pTempMat_47->t + 1) + local_74;
      local_30.vz = local_70 + *(short *)(pTempMat_47->t + 2) + *(short *)(Data + 0x1e);
      local_28.vz = local_30.vz - *(short *)(Data + 0x1a);
      local_28.vx = local_30.vx;
      local_28.vy = local_30.vy;
      PHYSICS_CheckLineInWorld(instance,&local_60);
      if ((local_60.type == 3) || (local_60.type == 5)) {
        if ((Mode & 1U) != 0) {
          *(short *)(Data + 0x10) = local_60.wNormal.vx;
          *(short *)(Data + 0x12) = local_60.wNormal.vy;
          *(short *)(Data + 0x14) = local_60.wNormal.vz;
          *(short *)(Data + 0x1e) = local_30.vz - local_28.vz;
        }
        uVar3 = 0x4000;
      }
    }
  }
  local_30.vx = *(short *)pTempMat_47->t;
  local_30.vy = *(short *)(pTempMat_47->t + 1);
  local_30.vz = *(short *)(pTempMat_47->t + 2);
  local_28.vz = local_30.vz + *(short *)(Data + 0x1c);
  local_28.vx = local_30.vx;
  local_28.vy = local_30.vy;
  PHYSICS_CheckLineInWorld(instance,&local_60);
  if (local_60.type != 0) {
    uVar3 = uVar3 | 0x8000;
  }
  if (local_60.type == 5) {
    if ((Mode & 1U) != 0) {
      *(_Instance **)(Data + 0x20) = local_60.inst;
    }
  }
  else {
    *(undefined4 *)(Data + 0x20) = 0;
  }
  return uVar3;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsUpdateTface(struct _Instance *instance /*$s0*/, int Data /*$a1*/)
 // line 1149, offset 0x8007592c
	/* begin block 1 */
		// Start line: 1150
		// Start offset: 0x8007592C
		// Variables:
	// 		struct _PCollideInfo CInfo; // stack offset -72
	// 		struct SVECTOR Old; // stack offset -24
	// 		struct SVECTOR New; // stack offset -16
	/* end block 1 */
	// End offset: 0x80075A18
	// End Line: 1191

	/* begin block 2 */
		// Start line: 2733
	/* end block 2 */
	// End Line: 2734

int PhysicsUpdateTface(_Instance *instance,int Data)

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
  PHYSICS_CheckLineInWorld(instance,&local_48);
  if (local_48.type == 3) {
    if (instance->tface != local_48.prim) {
      instance->oldTFace = instance->tface;
      instance->tface = local_48.prim;
      *(_Instance **)&instance->tfaceLevel = local_48.inst;
      instance->bspTree = (int)local_48.segment;
    }
    iVar1 = 1;
  }
  else {
    if (instance->tface != (_TFace *)0x0) {
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
 // line 1204, offset 0x80075a28
	/* begin block 1 */
		// Start line: 1205
		// Start offset: 0x80075A28
		// Variables:
	// 		struct evPhysicsEdgeData *Ptr; // $s1
	// 		struct VECTOR OutTrans; // stack offset -120
	// 		struct _PCollideInfo CInfo; // stack offset -104
	// 		struct SVECTOR Old; // stack offset -56
	// 		struct SVECTOR New; // stack offset -48
	// 		static struct MATRIX *pTempMat; // offset 0x54

		/* begin block 1.1 */
			// Start line: 1248
			// Start offset: 0x80075AD4
			// Variables:
		// 		struct _TFace *tface; // $s0

			/* begin block 1.1.1 */
				// Start line: 1250
				// Start offset: 0x80075AD4
				// Variables:
			// 		int Dot; // $a0
			// 		struct SVECTOR Force; // stack offset -40
			/* end block 1.1.1 */
			// End offset: 0x80075BB8
			// End Line: 1295

			/* begin block 1.1.2 */
				// Start line: 1318
				// Start offset: 0x80075C88
				// Variables:
			// 		struct _HFace *hface; // stack offset -32
			/* end block 1.1.2 */
			// End offset: 0x80075C88
			// End Line: 1324
		/* end block 1.1 */
		// End offset: 0x80075DBC
		// End Line: 1368
	/* end block 1 */
	// End offset: 0x80075DC0
	// End Line: 1371

	/* begin block 2 */
		// Start line: 2856
	/* end block 2 */
	// End Line: 2857

/* WARNING: Could not reconcile some variable overlaps */

int PhysicsCheckBlockers(_Instance *instance,GameTracker *gameTracker,int Data,short Mode)

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
  PHYSICS_GenericLineCheckSetup(0,0,0,local_68.oldPoint);
  PHYSICS_GenericLineCheckSetup(0,*(short *)(Data + 2),0,&local_30);
  PHYSICS_GenericLineCheck
            (instance,(MATRIX *)instance->matrix + 1,(MATRIX *)instance->matrix,&local_68);
  pTempMat_52 = instance->matrix;
  if (((local_68.type == 3) || (local_68.type == 5)) || (local_68.type == 2)) {
    local_28 = 0;
    local_26 = 0xf000;
    ApplyMatrix(pTempMat_52,&local_28,&local_78);
    iVar2 = local_68.wNormal.vx * local_78 + local_68.wNormal.vy * local_74 +
            local_68.wNormal.vz * local_70;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 0xfff;
    }
    if (((local_68.type == 3) && (*(ushort *)((int)local_68.prim + 10) != 0xffff)) &&
       ((*(ushort *)
          ((int)&((local_68.inst)->node).prev[6].next[1].prev +
          (uint)*(ushort *)((int)local_68.prim + 10) + 2) & 0x1000) != 0)) {
      if (-0xec8 < iVar2 >> 0xc) goto LAB_80075dbc;
    }
    else {
      if (-0xfc1 < iVar2 >> 0xc) goto LAB_80075dbc;
    }
    if ((Mode & 1U) != 0) {
      **(short **)(Data + 0xc) = local_68.wNormal.vx;
      *(short *)(*(int *)(Data + 0xc) + 2) = local_68.wNormal.vy;
      *(short *)(*(int *)(Data + 0xc) + 4) = local_68.wNormal.vz;
      *(short *)(*(int *)(Data + 0x14) + 2) = (local_68.newPoint)->vy - (local_68.oldPoint)->vy;
      **(short **)(Data + 0x14) = (local_68.newPoint)->vx - (local_68.oldPoint)->vx;
    }
    if (((local_68.type == 3) && (*(ushort *)((int)local_68.prim + 10) != 0xffff)) &&
       ((*(ushort *)
          ((int)&((local_68.inst)->node).prev[6].next[1].prev +
          (uint)*(ushort *)((int)local_68.prim + 10) + 2) & 0x1000) != 0)) {
      *(uint *)(Data + 0x20) = *(uint *)(Data + 0x20) | 0x20000;
    }
    pMVar1 = pTempMat_52;
    *(uint *)(Data + 0x20) = *(uint *)(Data + 0x20) | 2;
    local_38.vx = 0;
    local_38.vy = -0x10;
    local_38.vz = 0;
    ApplyMatrix(pMVar1,&local_38,&local_78);
    local_38.vx = (local_68.newPoint)->vx + (short)local_78;
    local_38.vy = (local_68.newPoint)->vy + (short)local_74;
    local_30.vz = (local_68.newPoint)->vz + (short)local_70;
    local_38.vz = local_30.vz + *(short *)(Data + 4);
    local_30.vx = local_38.vx;
    local_30.vy = local_38.vy;
    PHYSICS_CheckLineInWorld(instance,&local_68);
    if ((local_68.type == 3) || (local_68.type == 5)) {
      if ((Mode & 1U) != 0) {
        **(short **)(Data + 0x10) = local_68.wNormal.vx;
        *(short *)(*(int *)(Data + 0x10) + 2) = local_68.wNormal.vy;
        *(short *)(*(int *)(Data + 0x10) + 4) = local_68.wNormal.vz;
        *(short *)(*(int *)(Data + 0x14) + 4) = (local_68.newPoint)->vz - (local_68.oldPoint)->vz;
      }
      if (0xb50 < local_68.wNormal.vz) {
        *(uint *)(Data + 0x20) = *(uint *)(Data + 0x20) | 4;
      }
    }
    if ((Mode & 2U) != 0) {
      INSTANCE_Post(instance,0x4010400,Data);
    }
  }
LAB_80075dbc:
  return *(int *)(Data + 0x20);
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsCheckSwim(struct _Instance *instance /*$s1*/, int Data /*$s3*/, short Mode /*$s5*/)
 // line 1453, offset 0x80075de0
	/* begin block 1 */
		// Start line: 1454
		// Start offset: 0x80075DE0
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
	// End offset: 0x80075FA0
	// End Line: 1543

	/* begin block 2 */
		// Start line: 3467
	/* end block 2 */
	// End Line: 3468

int PhysicsCheckSwim(_Instance *instance,int Data,short Mode)

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
  lVar1 = STREAM_GetWaterZLevel(level,instance);
  sVar4 = (short)instance->matrix[1].t[2] - (short)lVar1;
  if (lVar1 == -0x7fff) {
    sVar4 = 1;
    sVar3 = -0x7fff;
  }
  else {
    sVar3 = -0x7fff;
    if (lVar1 == 0x7fff) {
      sVar4 = -0x7fff;
    }
    else {
      if (*(short *)Data == 0) {
        *(short *)(Data + 0xc) = sVar4;
        sVar3 = (short)instance->matrix->t[2] - (short)lVar1;
        *(short *)(Data + 0xe) = sVar3;
      }
      else {
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
        PHYSICS_CheckLineInWorld(instance,&local_60);
        gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffff7fff;
        if (local_60.type == 0) {
          sVar3 = sVar4 + *(short *)(Data + 4) * -4;
        }
        else {
          sVar3 = (sVar4 + (local_60.newPoint)->vz) - (short)instance->matrix[1].t[2];
        }
      }
    }
  }
  if ((Mode & 3U) != 0) {
    *(short *)(Data + 0xc) = sVar4;
    *(short *)(Data + 0xe) = sVar3;
  }
  *(long *)(Data + 0x14) = lVar1;
  iVar2 = PhysicsDefaultCheckSwimResponse(instance,(evPhysicsSwimData *)Data);
  *(undefined2 *)(Data + 0x10) = (short)iVar2;
  if ((Mode & 2U) != 0) {
    INSTANCE_Post(instance,0x4020000,Data);
  }
  FX_UpdateInstanceWaterSplit(instance);
  return iVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsDefaultCheckSwimResponse(struct _Instance *instance /*$s2*/, struct evPhysicsSwimData *Data /*$s3*/)
 // line 1551, offset 0x80075fd0
	/* begin block 1 */
		// Start line: 1552
		// Start offset: 0x80075FD0
		// Variables:
	// 		int rc; // $s0
	// 		long waterZLevel; // $s1
	/* end block 1 */
	// End offset: 0x800761A8
	// End Line: 1605

	/* begin block 2 */
		// Start line: 3692
	/* end block 2 */
	// End Line: 3693

int PhysicsDefaultCheckSwimResponse(_Instance *instance,evPhysicsSwimData *Data)

{
  uint uVar1;
  int iVar2;
  
  STREAM_GetLevelWithID(instance->currentStreamUnitID);
  iVar2 = Data->WaterLevel;
  uVar1 = (uint)(-(int)Data->WadeDepth < (int)Data->WaterDepth) << 7;
  if ((-(int)Data->TreadDepth < (int)Data->Depth) && ((int)Data->Depth < 0)) {
    uVar1 = uVar1 | 0x40;
  }
  if ((int)Data->Depth < -(int)Data->SwimDepth) {
    uVar1 = uVar1 | 0x10;
  }
  if (0 < (int)Data->Depth) {
    uVar1 = uVar1 | 0x20;
  }
  if ((((instance->position).z < iVar2) && (iVar2 < (instance->oldPos).z)) &&
     (Data->iVelocity->z < 0)) {
    SIGNAL_InWater(instance);
    uVar1 = uVar1 | 0x100;
  }
  if (((instance->matrix != (MATRIX *)0x0) && (instance->oldMatrix != (MATRIX *)0x0)) &&
     ((iVar2 < instance->matrix[1].t[2] && (instance->oldMatrix[1].t[2] < iVar2)))) {
    SIGNAL_OutOfWater(instance);
    uVar1 = uVar1 | 0x200;
  }
  if (((iVar2 < (instance->position).z) && ((instance->oldPos).z < iVar2)) &&
     (0 < Data->iVelocity->z)) {
    uVar1 = uVar1 | 0x400;
  }
  if ((((instance->matrix != (MATRIX *)0x0) && (instance->oldMatrix != (MATRIX *)0x0)) &&
      (iVar2 = iVar2 - Data->SwimDepth, instance->matrix[1].t[2] < iVar2)) &&
     ((iVar2 < instance->oldMatrix[1].t[2] && (Data->iVelocity->z < 0)))) {
    uVar1 = uVar1 | 0x800;
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsCheckPullOutOfWater(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$a1*/, int Data /*$s6*/, short Mode /*$s5*/)
 // line 1615, offset 0x800761c8
	/* begin block 1 */
		// Start line: 1616
		// Start offset: 0x800761C8
		// Variables:
	// 		struct evPhysicsEdgeData *Ptr; // $s1
	// 		int rc; // $s4
	// 		struct _PCollideInfo CInfo; // stack offset -96
	// 		struct SVECTOR Old; // stack offset -48
	// 		struct SVECTOR New; // stack offset -40
	// 		static struct MATRIX *pTempMat; // offset 0x58
	/* end block 1 */
	// End offset: 0x80076454
	// End Line: 1734

	/* begin block 2 */
		// Start line: 3822
	/* end block 2 */
	// End Line: 3823

int PhysicsCheckPullOutOfWater(_Instance *instance,GameTracker *gameTracker,int Data,short Mode)

{
  int iVar1;
  _PCollideInfo local_60;
  SVECTOR SStack48;
  SVECTOR SStack40;
  
  if ((Mode & 1U) != 0) {
    *(undefined4 *)(Data + 0x18) = 0;
  }
  local_60.oldPoint = &SStack48;
  pTempMat_59 = (MATRIX *)instance->matrix;
  local_60.newPoint = &SStack40;
  PHYSICS_GenericLineCheckSetup(0,0,*(short *)Data,local_60.oldPoint);
  PHYSICS_GenericLineCheckSetup(0,*(short *)(Data + 2),*(short *)Data,&SStack40);
  PHYSICS_GenericLineCheck(instance,(MATRIX *)(instance->matrix + 1),pTempMat_59,&local_60);
  if ((local_60.type == 3) || (iVar1 = 0, local_60.type == 5)) {
    if ((Mode & 1U) != 0) {
      **(short **)(Data + 0xc) = local_60.wNormal.vx;
      *(short *)(*(int *)(Data + 0xc) + 2) = local_60.wNormal.vy;
      *(short *)(*(int *)(Data + 0xc) + 4) = local_60.wNormal.vz;
      *(short *)(*(int *)(Data + 0x14) + 2) = (local_60.newPoint)->vy - (local_60.oldPoint)->vy;
      **(short **)(Data + 0x14) = (local_60.newPoint)->vx - (local_60.oldPoint)->vx;
      if ((local_60.type == 5) || (local_60.type == 2)) {
        *(_Instance **)(Data + 0x18) = local_60.inst;
      }
    }
    PHYSICS_GenericLineCheckSetup
              (0,*(short *)(Data + 2),
               (short)(((uint)*(ushort *)Data + (uint)*(ushort *)(Data + 4)) * 0x10000 >> 0x10),
               &SStack48);
    PHYSICS_GenericLineCheckSetup(0,*(short *)(Data + 2),*(short *)Data,&SStack40);
    PHYSICS_GenericLineCheck(instance,(MATRIX *)(instance->matrix + 1),pTempMat_59,&local_60);
    if ((local_60.type == 3) || (iVar1 = 2, local_60.type == 5)) {
      if ((Mode & 1U) != 0) {
        **(short **)(Data + 0x10) = local_60.wNormal.vx;
        *(short *)(*(int *)(Data + 0x10) + 2) = local_60.wNormal.vy;
        *(short *)(*(int *)(Data + 0x10) + 4) = local_60.wNormal.vz;
        *(short *)(*(int *)(Data + 0x14) + 4) =
             ((local_60.newPoint)->vz - (local_60.oldPoint)->vz) +
             (*(short *)(pTempMat_59[1].t + 2) - (instance->position).z);
        if ((local_60.type == 5) || (local_60.type == 2)) {
          *(_Instance **)(Data + 0x18) = local_60.inst;
        }
      }
      iVar1 = 2;
      if (0xb50 < local_60.wNormal.vz) {
        iVar1 = 6;
        if ((Mode & 2U) != 0) {
          INSTANCE_Post(instance,0x4010010,Data);
        }
        if ((Mode & 4U) != 0) {
          PhysicsDefaultPullOutResponse(instance,(evPhysicsEdgeData *)Data);
        }
      }
    }
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PhysicsDefaultPullOutResponse(struct _Instance *instance /*$s1*/, struct evPhysicsEdgeData *Data /*$s2*/)
 // line 1740, offset 0x80076480
	/* begin block 1 */
		// Start line: 1741
		// Start offset: 0x80076480
		// Variables:
	// 		short angle; // $s0
	// 		struct _SVector xprod; // stack offset -72
	// 		struct _SVector normal; // stack offset -64
	// 		struct _SVector oldNormal; // stack offset -56
	// 		struct _G2EulerAngles_Type ea1; // stack offset -48
	// 		struct VECTOR OutTrans; // stack offset -40
	// 		struct SVECTOR *ExtraRot; // $v1
	// 		struct SVECTOR New; // stack offset -24
	// 		static struct MATRIX TempMat; // offset 0x60
	/* end block 1 */
	// End offset: 0x800764EC
	// End Line: 1781

	/* begin block 2 */
		// Start line: 4103
	/* end block 2 */
	// End Line: 4104

/* WARNING: Could not reconcile some variable overlaps */

void PhysicsDefaultPullOutResponse(_Instance *instance,evPhysicsEdgeData *Data)

{
  short angle;
  ulong uVar1;
  _SVector local_48;
  _SVector local_40;
  undefined4 local_38;
  undefined4 local_34;
  _G2EulerAngles_Type local_30;
  short local_28 [2];
  short local_24;
  short local_20;
  short local_18;
  short local_16;
  short local_14;
  
  local_38 = 0x10000000;
  local_34 = 0;
  uVar1 = INSTANCE_Query(instance,8);
  if (uVar1 != 0) {
    (instance->rotation).z = (instance->rotation).z + *(short *)(uVar1 + 4);
  }
  local_40.x = Data->Normal1->x;
  local_40.y = Data->Normal1->y;
  local_40.z = 0;
  angle = MATH3D_AngleBetweenVectors(&local_40,(_SVector *)&local_38);
  local_48.x = -(short)((int)local_40.y * (int)(short)local_34 -
                        (int)local_40.z * (int)local_38._2_2_ >> 0xc);
  local_48.y = (short)((int)local_40.x * (int)(short)local_34 -
                       (int)local_40.z * (int)(short)local_38 >> 0xc);
  local_48.z = -(short)((int)local_40.x * (int)local_38._2_2_ -
                        (int)local_40.y * (int)(short)local_38 >> 0xc);
  MATH3D_SetUnityMatrix((MATRIX *)&TempMat_62);
  MATH3D_RotMatAboutVec(&local_48,(MATRIX *)&TempMat_62,angle);
  G2EulerAngles_FromMatrix(&local_30,(_G2Matrix_Type *)&TempMat_62,0x15);
  (instance->rotation).x = local_30.x;
  (instance->rotation).y = local_30.y;
  (instance->rotation).z = local_30.z;
  local_14 = Data->ZDistance;
  local_18 = Data->XDistance;
  local_16 = Data->YDistance;
  ApplyMatrix(instance->matrix,&local_18,local_28);
  (instance->position).z =
       (instance->position).z -
       (local_20 - (Data->Delta->z + Data->UpperOffset + Data->AboveOffset));
  (instance->position).x = (instance->position).x + (Data->Delta->x - local_28[0]);
  (instance->position).y = (instance->position).y - (local_24 - Data->Delta->y);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PhysicsForceSetWater(struct _Instance *instance /*$s1*/, int *Time /*$t0*/, int Depth /*$a2*/, int rate /*$a3*/, int maxAmplitude /*stack 16*/)
 // line 1822, offset 0x800766bc
	/* begin block 1 */
		// Start line: 1823
		// Start offset: 0x800766BC
		// Variables:
	// 		int Amplitude; // $s0
	/* end block 1 */
	// End offset: 0x80076780
	// End Line: 1840

	/* begin block 2 */
		// Start line: 4286
	/* end block 2 */
	// End Line: 4287

void PhysicsForceSetWater(_Instance *instance,int *Time,int Depth,int rate,int maxAmplitude)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = Depth;
  if (Depth < -0xc00) {
    iVar3 = -0xc00;
  }
  if (0 < iVar3) {
    iVar3 = 0;
  }
  iVar1 = iVar3 * maxAmplitude >> 0x1f;
  iVar2 = *Time + (uint)(rate << 0xc) / gameTrackerX.idleTime;
  *Time = iVar2;
  if (0x1000 < iVar2) {
    *Time = iVar2 + -0x1000;
  }
  if (Depth < 0) {
    iVar2 = rcos(*Time);
    iVar2 = (iVar1 - ((iVar3 * maxAmplitude) / 6 + iVar1 >> 9)) * iVar2;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 0xfff;
    }
    (instance->position).z = (instance->position).z + (short)(iVar2 >> 0xc);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsCheckLOS(struct _Instance *instance /*$a0*/, int Data /*$a1*/, int Mode /*$a2*/)
 // line 1853, offset 0x80076794
	/* begin block 1 */
		// Start line: 1854
		// Start offset: 0x80076794
		// Variables:
	// 		struct _PCollideInfo CInfo; // stack offset -56
	/* end block 1 */
	// End offset: 0x80076794
	// End Line: 1854

	/* begin block 2 */
		// Start line: 4357
	/* end block 2 */
	// End Line: 4358

int PhysicsCheckLOS(_Instance *instance,int Data,int Mode)

{
  _PCollideInfo local_38;
  
  local_38.oldPoint = (SVECTOR *)(Data + 8);
  local_38.newPoint = (SVECTOR *)Data;
  PHYSICS_CheckLineInWorld(instance,&local_38);
  return (uint)(local_38.type == 0);
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsCheckDropHeight(struct _Instance *instance /*$s2*/, int Data /*$a1*/, int Mode /*$s3*/)
 // line 1881, offset 0x800767c4
	/* begin block 1 */
		// Start line: 1882
		// Start offset: 0x800767C4
		// Variables:
	// 		struct evPhysicsDropHeightData *data; // $s0
	// 		struct Level *level; // $v0
	// 		struct SVECTOR newPos; // stack offset -104
	// 		struct SVECTOR oldPos; // stack offset -96
	// 		int rc; // $s1
	// 		int lowZ; // $v1
	// 		struct _PCollideInfo CInfo; // stack offset -88
	// 		static struct MATRIX TempMat; // offset 0x80
	// 		static struct MATRIX *pTempMat; // offset 0xa0

		/* begin block 1.1 */
			// Start line: 1895
			// Start offset: 0x800767F8
			// Variables:
		// 		struct VECTOR outTrans; // stack offset -40
		// 		struct SVECTOR *ExtraRot; // $v0
		/* end block 1.1 */
		// End offset: 0x80076840
		// End Line: 1924

		/* begin block 1.2 */
			// Start line: 1948
			// Start offset: 0x8007690C
			// Variables:
		// 		long waterZLevel; // $a0
		/* end block 1.2 */
		// End offset: 0x80076948
		// End Line: 1966
	/* end block 1 */
	// End offset: 0x80076A38
	// End Line: 2013

	/* begin block 2 */
		// Start line: 4423
	/* end block 2 */
	// End Line: 4424

int PhysicsCheckDropHeight(_Instance *instance,int Data,int Mode)

{
  short *psVar1;
  Level *level;
  int iVar2;
  int iVar3;
  int iVar4;
  SVECTOR local_68;
  SVECTOR local_60;
  _PCollideInfo local_58;
  short local_28 [2];
  short local_24;
  short local_20;
  
  if ((*(ushort *)(Data + 6) & 0x20) == 0) {
    if ((*(ushort *)(Data + 6) & 0x10) == 0) {
      local_60.vx = *(short *)Data;
      local_60.vy = *(short *)(Data + 2);
      local_60.vz = *(short *)(Data + 4);
    }
    else {
      local_60.vx = (instance->position).x + *(short *)Data;
      local_60.vy = (instance->position).y + *(short *)(Data + 2);
      local_60.vz = (instance->position).z + *(short *)(Data + 4);
    }
  }
  else {
    psVar1 = (short *)INSTANCE_Query(instance,8);
    if (psVar1 == (short *)0x0) {
      pTempMat_70 = instance->matrix;
    }
    else {
      pTempMat_70 = (MATRIX *)&TempMat_69;
      RotMatrix(psVar1,(uint *)&TempMat_69);
      MulMatrix2((undefined4 *)instance->matrix,(uint *)pTempMat_70);
    }
    ApplyMatrix(pTempMat_70,Data,local_28);
    local_60.vx = (instance->position).x + local_28[0];
    local_60.vy = (instance->position).y + local_24;
    local_60.vz = (instance->position).z + local_20;
  }
  level = STREAM_GetLevelWithID(instance->currentStreamUnitID);
  if (((*(ushort *)(Data + 6) & 0x40) == 0) ||
     (iVar2 = STREAM_GetWaterZLevel(level,instance), iVar2 == -0x7fff)) {
    iVar4 = 0;
    iVar2 = (int)local_60.vz - (int)*(short *)(Data + 8);
  }
  else {
    iVar3 = (int)local_60.vz - (int)*(short *)(Data + 8);
    iVar4 = 0x10;
    if (iVar2 <= iVar3) {
      iVar4 = 0;
      iVar2 = iVar3;
    }
  }
  if (iVar2 < local_60.vz) {
    local_68.vz = (short)iVar2;
    local_58.oldPoint = &local_60;
    local_58.newPoint = &local_68;
    local_68.vx = local_60.vx;
    local_68.vy = local_60.vy;
    PHYSICS_CheckLineInWorld(instance,&local_58);
    if (((local_58.type != 0) && (0xb50 < local_58.wNormal.vz)) && (iVar4 = 1, Mode == 1)) {
      if (local_58.type == 3) {
        *(NodeType **)(Data + 0xc) =
             (NodeType *)((int)((local_58.inst)->node).prev[10].prev + (int)local_58.segment * 0x24)
        ;
        *(void **)(Data + 0x10) = local_58.prim;
      }
      else {
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
// int /*$ra*/ PhysicsCheckDropOff(struct _Instance *instance /*$s0*/, int Data /*$a1*/, short Mode /*$s2*/)
 // line 2025, offset 0x80076a58
	/* begin block 1 */
		// Start line: 2026
		// Start offset: 0x80076A58
		// Variables:
	// 		struct evPhysicsDropOffData *Ptr; // $s1
	// 		int rc; // $s3
	// 		struct VECTOR OutTrans; // stack offset -104
	// 		struct SVECTOR *ExtraRot; // $v0
	// 		struct _PCollideInfo CInfo; // stack offset -88
	// 		struct SVECTOR New; // stack offset -40
	// 		struct SVECTOR Old; // stack offset -32
	// 		static struct MATRIX TempMat; // offset 0xb0
	// 		static struct MATRIX *pTempMat; // offset 0xd0
	/* end block 1 */
	// End offset: 0x80076C30
	// End Line: 2121

	/* begin block 2 */
		// Start line: 4736
	/* end block 2 */
	// End Line: 4737

int PhysicsCheckDropOff(_Instance *instance,int Data,short Mode)

{
  short *psVar1;
  int iVar2;
  short local_68 [2];
  short local_64;
  short local_60;
  _PCollideInfo local_58;
  SVECTOR local_28;
  SVECTOR local_20;
  
  local_58.oldPoint = &local_20;
  local_58.newPoint = &local_28;
  psVar1 = (short *)INSTANCE_Query(instance,8);
  iVar2 = 0;
  if (instance->matrix != (MATRIX *)0x0) {
    pTempMat_74 = instance->matrix;
    if (psVar1 != (short *)0x0) {
      pTempMat_74 = (MATRIX *)&TempMat_73;
      RotMatrix(psVar1,(uint *)&TempMat_73);
      MulMatrix2((undefined4 *)instance->matrix,(uint *)pTempMat_74);
    }
    local_28.vx = *(short *)Data;
    local_28.vy = *(short *)(Data + 2);
    local_28.vz = 0;
    ApplyMatrix(pTempMat_74,&local_28,local_68);
    local_28.vx = (instance->position).x + local_68[0];
    local_28.vy = (instance->position).y + local_64;
    local_20.vz = (instance->position).z + local_60;
    local_28.vz = local_20.vz - *(short *)(Data + 4);
    local_20.vz = local_20.vz + *(short *)(Data + 4) * 2;
    local_20.vx = local_28.vx;
    local_20.vy = local_28.vy;
    PHYSICS_CheckLineInWorld(instance,&local_58);
    if (((uint)local_58.type - 2 < 2) || (local_58.type == 5)) {
      if ((Mode & 2U) != 0) {
        INSTANCE_Post(instance,0x4010080,1);
      }
      iVar2 = 0;
      if (((local_58.wNormal.vz < *(short *)(Data + 6)) && (0 < local_58.wNormal.vz)) &&
         (iVar2 = 0, (instance->position).z < (local_58.newPoint)->vz)) {
        INSTANCE_Post(instance,0x4010401,0);
        iVar2 = 0;
      }
    }
    else {
      iVar2 = 0;
      if (local_58.type == 0) {
        if ((Mode & 2U) != 0) {
          INSTANCE_Post(instance,0x4010080,0);
        }
        iVar2 = 8;
      }
    }
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsFollowWall(struct _Instance *instance /*$s1*/, struct GameTracker *gameTracker /*$a1*/, int Data /*$s6*/, short Mode /*$s4*/)
 // line 2175, offset 0x80076c4c
	/* begin block 1 */
		// Start line: 2176
		// Start offset: 0x80076C4C
		// Variables:
	// 		struct VECTOR OutTrans; // stack offset -128
	// 		struct evPhysicsWallCrawlData *Ptr; // $s0
	// 		struct _PCollideInfo CInfo; // stack offset -112
	// 		struct SVECTOR New; // stack offset -64
	// 		struct SVECTOR Old; // stack offset -56
	// 		static struct MATRIX *pTempMat; // offset 0xd4

		/* begin block 1.1 */
			// Start line: 2238
			// Start offset: 0x80076D48
			// Variables:
		// 		struct _Position A; // stack offset -48
		// 		struct _Position B; // stack offset -40
		/* end block 1.1 */
		// End offset: 0x80076E34
		// End Line: 2270
	/* end block 1 */
	// End offset: 0x8007708C
	// End Line: 2408

	/* begin block 2 */
		// Start line: 4334
	/* end block 2 */
	// End Line: 4335

int PhysicsFollowWall(_Instance *instance,GameTracker *gameTracker,int Data,short Mode)

{
  MATRIX *pMVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  short local_80 [2];
  short local_7c;
  short local_78;
  _PCollideInfo local_70;
  SVECTOR local_40;
  SVECTOR local_38;
  _Position local_30;
  _Position local_28;
  
  local_70.oldPoint = &local_38;
  *(undefined4 *)(Data + 0x28) = 0;
  pTempMat_79 = (MATRIX *)(instance->matrix + *(short *)Data);
  local_70.newPoint = &local_40;
  PHYSICS_GenericLineCheckSetup(0,0x40,0,local_70.oldPoint);
  PHYSICS_GenericLineCheckSetup(0,*(short *)(Data + 2),0,&local_40);
  PHYSICS_GenericLineCheck(instance,pTempMat_79,pTempMat_79,&local_70);
  if ((local_70.type == 3) || (local_70.type == 5)) {
    *(uint *)(Data + 0x28) = *(uint *)(Data + 0x28) | 8;
    if ((Mode & 7U) != 0) {
      *(short *)(Data + 8) = local_70.wNormal.vx;
      *(short *)(Data + 10) = local_70.wNormal.vy;
      *(short *)(Data + 0xc) = local_70.wNormal.vz;
    }
    pMVar1 = pTempMat_79;
    if ((Mode & 4U) != 0) {
      *(short *)(Data + 0x18) = local_40.vx;
      *(short *)(Data + 0x1a) = local_40.vy;
      *(short *)(Data + 0x1c) = local_40.vz;
      local_40.vx = 0;
      local_40.vz = 0;
      local_40.vy = -*(short *)(Data + 6);
      ApplyMatrix(pMVar1,&local_40,local_80);
      *(short *)(Data + 0x18) = *(short *)(Data + 0x18) + local_80[0];
      *(short *)(Data + 0x1a) = *(short *)(Data + 0x1a) + local_7c;
      *(short *)(Data + 0x1c) = *(short *)(Data + 0x1c) + local_78;
      *(short *)(Data + 0x18) = (instance->position).x - *(short *)(Data + 0x18);
      *(short *)(Data + 0x1a) = (instance->position).y - *(short *)(Data + 0x1a);
      *(short *)(Data + 0x1c) = (instance->position).z - *(short *)(Data + 0x1c);
      local_28.z = 0;
      local_28.y = 0;
      local_28.x = 0;
      local_30.x = *(short *)(Data + 8);
      local_30.y = *(short *)(Data + 10);
      local_30.z = *(short *)(Data + 0xc);
      MATH3D_RotationFromPosToPos(&local_30,&local_28,(_Rotation *)(Data + 0x1e));
    }
    (instance->wNormal).x = local_70.wNormal.vx;
    (instance->wNormal).y = local_70.wNormal.vy;
    uVar3 = instance->flags2;
    (instance->wNormal).z = local_70.wNormal.vz;
    if ((uVar3 & 0x40) != 0) {
      (instance->shadowPosition).x = local_40.vx;
      (instance->shadowPosition).y = local_40.vy;
      instance->flags = instance->flags | 0x8000000;
      (instance->shadowPosition).z = local_40.vz;
    }
    if (instance->tface != local_70.prim) {
      instance->oldTFace = instance->tface;
      instance->tface = local_70.prim;
      *(_Instance **)&instance->tfaceLevel = local_70.inst;
      instance->bspTree = (int)local_70.segment;
    }
  }
  PHYSICS_GenericLineCheckSetup(0,0x40,*(short *)(Data + 4),&local_38);
  iVar4 = (uint)*(ushort *)(Data + 6) << 0x10;
  PHYSICS_GenericLineCheckSetup
            (0,(short)(((uint)*(ushort *)(Data + 2) + ((iVar4 >> 0x10) - (iVar4 >> 0x1f) >> 1)) *
                       0x10000 >> 0x10),*(short *)(Data + 4),&local_40);
  PHYSICS_GenericLineCheck(instance,pTempMat_79,pTempMat_79,&local_70);
  if ((local_70.type == 3) || (local_70.type == 5)) {
    *(uint *)(Data + 0x28) = *(uint *)(Data + 0x28) | 2;
    if ((Mode & 7U) != 0) {
      *(short *)(Data + 0x10) = local_70.wNormal.vx;
      *(short *)(Data + 0x12) = local_70.wNormal.vy;
      *(short *)(Data + 0x14) = local_70.wNormal.vz;
    }
    if ((Mode & 4U) != 0) {
      sVar2 = MATH3D_AngleBetweenVectors((_SVector *)(Data + 8),(_SVector *)(Data + 0x10));
      *(short *)(Data + 0x26) = sVar2;
    }
    local_38.vx = 0;
    local_38.vy = -0x20;
    local_38.vz = 0;
    ApplyMatrix(pTempMat_79,&local_38,local_80);
    local_38.vz = 0x40;
    local_40.vx = local_40.vx + local_80[0];
    local_38.vx = 0;
    local_38.vy = 0;
    local_40.vy = local_40.vy + local_7c;
    local_40.vz = local_40.vz + local_78;
    ApplyMatrix(pTempMat_79,&local_38,local_80);
    local_38.vx = local_40.vx + local_80[0];
    local_38.vy = local_40.vy + local_7c;
    local_38.vz = local_40.vz + local_78;
    PHYSICS_CheckLineInWorld(instance,&local_70);
    if ((local_70.type == 3) || (local_70.type == 5)) {
      *(uint *)(Data + 0x28) = *(uint *)(Data + 0x28) | 4;
    }
  }
  if ((Mode & 2U) != 0) {
    INSTANCE_Post(instance,0x4010011,Data);
  }
  return *(int *)(Data + 0x28);
}



// decompiled code
// original method signature: 
// void /*$ra*/ PhysicsMoveLocalZClamp(struct _Instance *instance /*$s3*/, long segment /*$s0*/, long time /*$s1*/, long clamp /*$s2*/)
 // line 2556, offset 0x800770b8
	/* begin block 1 */
		// Start line: 2557
		// Start offset: 0x800770B8
		// Variables:
	// 		struct _Position pos; // stack offset -48
	// 		struct SVECTOR v; // stack offset -40
	// 		struct SVECTOR dv; // stack offset -32
	/* end block 1 */
	// End offset: 0x80077174
	// End Line: 2576

	/* begin block 2 */
		// Start line: 4994
	/* end block 2 */
	// End Line: 4995

void PhysicsMoveLocalZClamp(_Instance *instance,long segment,long time,long clamp)

{
  _Position local_30;
  short local_28;
  short local_26;
  short local_24;
  short local_20;
  short local_1e;
  short local_1c;
  
  memset(&local_30,0,6);
  PhysicsMove(instance,&local_30,time);
  local_28 = local_30.x;
  local_24 = local_30.z;
  local_26 = -local_30.y;
  ApplyMatrixSV(instance->matrix + segment,&local_28,&local_20);
  (instance->position).x = (instance->position).x + local_20;
  (instance->position).y = (instance->position).y + local_1e;
  if (clamp == 0) {
    (instance->position).z = (instance->position).z + local_1c;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PhysicsMove(struct _Instance *instance /*$a0*/, struct _Position *position /*$a1*/, long time /*$a2*/)
 // line 2582, offset 0x80077190
	/* begin block 1 */
		// Start line: 2584
		// Start offset: 0x80077190
		// Variables:
	// 		long xVel; // $t0
	// 		long yVel; // $t1
	// 		long zVel; // $t2
	// 		long xat; // $t6
	// 		long yat; // $t4
	// 		long zat; // $t5
	/* end block 1 */
	// End offset: 0x8007731C
	// End Line: 2620

	/* begin block 2 */
		// Start line: 5856
	/* end block 2 */
	// End Line: 5857

	/* begin block 3 */
		// Start line: 5857
	/* end block 3 */
	// End Line: 5858

	/* begin block 4 */
		// Start line: 5866
	/* end block 4 */
	// End Line: 5867

void PhysicsMove(_Instance *instance,_Position *position,long time)

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
  if (iVar4 < 0) {
    iVar4 = iVar4 + 0xfff;
  }
  iVar5 = instance->yAccl * time;
  if (iVar5 < 0) {
    iVar5 = iVar5 + 0xfff;
  }
  iVar6 = instance->zAccl * time;
  if (iVar6 < 0) {
    iVar6 = iVar6 + 0xfff;
  }
  iVar7 = iVar1 * time;
  if (iVar7 < 0) {
    iVar7 = iVar7 + 0xfff;
  }
  iVar8 = (iVar4 >> 0xc) * time;
  if (iVar8 < 0) {
    iVar8 = iVar8 + 0x1fff;
  }
  iVar9 = iVar2 * time;
  position->x = position->x + (short)(iVar7 >> 0xc) + (short)(iVar8 >> 0xd);
  if (iVar9 < 0) {
    iVar9 = iVar9 + 0xfff;
  }
  iVar7 = (iVar5 >> 0xc) * time;
  if (iVar7 < 0) {
    iVar7 = iVar7 + 0x1fff;
  }
  iVar8 = iVar3 * time;
  position->y = position->y + (short)(iVar9 >> 0xc) + (short)(iVar7 >> 0xd);
  if (iVar8 < 0) {
    iVar8 = iVar8 + 0xfff;
  }
  iVar7 = (iVar6 >> 0xc) * time;
  if (iVar7 < 0) {
    iVar7 = iVar7 + 0x1fff;
  }
  iVar1 = iVar1 + (iVar4 >> 0xc);
  iVar2 = iVar2 + (iVar5 >> 0xc);
  position->z = position->z + (short)(iVar8 >> 0xc) + (short)(iVar7 >> 0xd);
  iVar4 = instance->maxXVel;
  iVar3 = iVar3 + (iVar6 >> 0xc);
  if ((iVar4 < iVar1) || (iVar4 = -iVar4, iVar1 < iVar4)) {
    iVar1 = iVar4;
  }
  iVar4 = instance->maxYVel;
  if ((iVar4 < iVar2) || (iVar4 = -iVar4, iVar2 < iVar4)) {
    iVar2 = iVar4;
  }
  iVar4 = instance->maxZVel;
  if ((iVar4 < iVar3) || (iVar4 = -iVar4, iVar3 < iVar4)) {
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
 // line 2654, offset 0x8007732c
	/* begin block 1 */
		// Start line: 6009
	/* end block 1 */
	// End Line: 6010

void PhysicsSetVelFromZRot(_Instance *instance,short angle,long magnitude)

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
 // line 2665, offset 0x8007739c
	/* begin block 1 */
		// Start line: 2666
		// Start offset: 0x8007739C
		// Variables:
	// 		struct MATRIX mat; // stack offset -56
	// 		struct SVECTOR flatPt; // stack offset -24
	// 		struct SVECTOR newPt; // stack offset -16
	/* end block 1 */
	// End offset: 0x8007739C
	// End Line: 2666

	/* begin block 2 */
		// Start line: 6035
	/* end block 2 */
	// End Line: 6036

void PhysicsSetVelFromRot(_Instance *instance,_Rotation *rot,long magnitude)

{
  uint auStack56 [8];
  undefined2 local_18;
  short local_16;
  undefined2 local_14;
  short local_10;
  short local_e;
  short local_c;
  
  local_16 = -(short)magnitude;
  local_18 = 0;
  local_14 = 0;
  RotMatrix((short *)&instance->rotation,auStack56);
  ApplyMatrixSV(auStack56,&local_18,&local_10);
  instance->xVel = (int)local_10;
  instance->yVel = (int)local_e;
  instance->zVel = (int)local_c;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSICS_SetVAndAFromRot(struct _Instance *instance /*$s0*/, struct _Rotation *rot /*$a1*/, long v /*$s1*/, long a /*$s2*/)
 // line 2685, offset 0x8007740c
	/* begin block 1 */
		// Start line: 2686
		// Start offset: 0x8007740C
		// Variables:
	// 		struct SVECTOR flatPt; // stack offset -72
	// 		struct MATRIX mat; // stack offset -64

		/* begin block 1.1 */
			// Start line: 2700
			// Start offset: 0x80077454
			// Variables:
		// 		struct SVECTOR newPt; // stack offset -32
		/* end block 1.1 */
		// End offset: 0x80077454
		// End Line: 2702

		/* begin block 1.2 */
			// Start line: 2719
			// Start offset: 0x800774A0
			// Variables:
		// 		struct SVECTOR newPt; // stack offset -24
		/* end block 1.2 */
		// End offset: 0x800774A0
		// End Line: 2721
	/* end block 1 */
	// End offset: 0x800774E4
	// End Line: 2735

	/* begin block 2 */
		// Start line: 6085
	/* end block 2 */
	// End Line: 6086

void PHYSICS_SetVAndAFromRot(_Instance *instance,_Rotation *rot,long v,long a)

{
  undefined2 local_48;
  short local_46;
  undefined2 local_44;
  uint auStack64 [8];
  short local_20;
  short local_1e;
  short local_1c;
  short local_18;
  short local_16;
  short local_14;
  
  if ((v != 0) || (a != 0)) {
    RotMatrix((short *)&instance->rotation,auStack64);
    local_48 = 0;
    local_44 = 0;
  }
  if (v == 0) {
    instance->xVel = 0;
    instance->yVel = 0;
    instance->zVel = 0;
  }
  else {
    local_46 = -(short)v;
    ApplyMatrixSV(auStack64,&local_48,&local_20);
    instance->xVel = (int)local_20;
    instance->yVel = (int)local_1e;
    instance->zVel = (int)local_1c;
  }
  if (a == 0) {
    instance->xAccl = 0;
    instance->yAccl = 0;
    instance->zAccl = 0;
  }
  else {
    local_46 = -(short)a;
    ApplyMatrixSV(auStack64,&local_48,&local_18);
    instance->xAccl = (int)local_18;
    instance->yAccl = (int)local_16;
    instance->zAccl = (int)local_14;
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ PHYSICS_FindAFromDAndT(long d /*$a0*/, long t /*$a1*/)
 // line 2742, offset 0x800774fc
	/* begin block 1 */
		// Start line: 6203
	/* end block 1 */
	// End Line: 6204

	/* begin block 2 */
		// Start line: 6204
	/* end block 2 */
	// End Line: 6205

long PHYSICS_FindAFromDAndT(long d,long t)

{
  int iVar1;
  
  if (t != 0) {
    iVar1 = (d << 0xd) / (t * t);
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0xfff;
    }
    return iVar1 >> 0xc;
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ PHYSICS_FindVFromAAndD(long a /*$a0*/, long d /*$a1*/)
 // line 2755, offset 0x80077538
	/* begin block 1 */
		// Start line: 2756
		// Start offset: 0x80077538
		// Variables:
	// 		long vsq; // $a0
	/* end block 1 */
	// End offset: 0x80077560
	// End Line: 2762

	/* begin block 2 */
		// Start line: 6229
	/* end block 2 */
	// End Line: 6230

	/* begin block 3 */
		// Start line: 6230
	/* end block 3 */
	// End Line: 6231

long PHYSICS_FindVFromAAndD(long a,long d)

{
  long lVar1;
  int square;
  
  square = a * d * 2;
  if (square == 0) {
    lVar1 = 0;
  }
  else {
    lVar1 = MATH3D_FastSqrt0(square);
  }
  return lVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSICS_StopIfCloseToTarget(struct _Instance *instance /*$a0*/, int x /*$a1*/, int y /*$a2*/, int z /*$a3*/)
 // line 2796, offset 0x80077570
	/* begin block 1 */
		// Start line: 6314
	/* end block 1 */
	// End Line: 6315

	/* begin block 2 */
		// Start line: 6316
	/* end block 2 */
	// End Line: 6317

void PHYSICS_StopIfCloseToTarget(_Instance *instance,int x,int y,int z)

{
  if (((instance->xAccl < 0) && (instance->xVel <= x)) ||
     ((0 < instance->xAccl && (x <= instance->xVel)))) {
    instance->xAccl = 0;
    instance->xVel = x;
  }
  if (((instance->yAccl < 0) && (instance->yVel <= y)) ||
     ((0 < instance->yAccl && (y <= instance->yVel)))) {
    instance->yAccl = 0;
    instance->yVel = y;
  }
  if (((instance->zAccl < 0) && (instance->zVel <= z)) ||
     ((0 < instance->zAccl && (z <= instance->zVel)))) {
    instance->zAccl = 0;
    instance->zVel = z;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSICS_CheckForTerrainCollide(struct _Instance *instance /*$a0*/, struct SVECTOR *startVec /*$a1*/, struct SVECTOR *endVec /*$a2*/, int segment /*$a3*/)
 // line 2818, offset 0x80077650
	/* begin block 1 */
		// Start line: 2819
		// Start offset: 0x80077650
		// Variables:
	// 		struct _PCollideInfo CInfo; // stack offset -56
	// 		static struct MATRIX *pTempMat; // offset 0xd8
	/* end block 1 */
	// End offset: 0x80077650
	// End Line: 2819

	/* begin block 2 */
		// Start line: 6358
	/* end block 2 */
	// End Line: 6359

int PHYSICS_CheckForTerrainCollide
              (_Instance *instance,SVECTOR *startVec,SVECTOR *endVec,int segment)

{
  _PCollideInfo local_38;
  
  local_38.collideType = 1;
  pTempMat_100 = (MATRIX *)(instance->matrix + segment);
  local_38.newPoint = endVec;
  local_38.oldPoint = startVec;
  PHYSICS_GenericLineCheckMask(instance,pTempMat_100,pTempMat_100,&local_38);
  return (uint)(local_38.type == 3);
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSICS_CheckForValidMove(struct _Instance *instance /*$a0*/, struct SVECTOR *startVec /*$a1*/, struct SVECTOR *endVec /*$a2*/, int segment /*$a3*/)
 // line 2839, offset 0x8007769c
	/* begin block 1 */
		// Start line: 2840
		// Start offset: 0x8007769C
		// Variables:
	// 		struct _PCollideInfo CInfo; // stack offset -56
	// 		static struct MATRIX *pTempMat; // offset 0xdc
	// 		int rc; // $a0
	/* end block 1 */
	// End offset: 0x800776FC
	// End Line: 2863

	/* begin block 2 */
		// Start line: 6419
	/* end block 2 */
	// End Line: 6420

int PHYSICS_CheckForValidMove(_Instance *instance,SVECTOR *startVec,SVECTOR *endVec,int segment)

{
  int iVar1;
  uint uVar2;
  _PCollideInfo local_38;
  
  pTempMat_103 = (MATRIX *)(instance->matrix + segment);
  local_38.newPoint = endVec;
  local_38.oldPoint = startVec;
  PHYSICS_GenericLineCheck(instance,pTempMat_103,pTempMat_103,&local_38);
  iVar1 = PHYSICS_CheckFaceStick(&local_38);
  uVar2 = (uint)(iVar1 != 0);
  if (((uint)local_38.type - 2 < 2) || (local_38.type == 5)) {
    uVar2 = uVar2 + 2;
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSICS_CheckFaceStick(struct _PCollideInfo *CInfo /*$a0*/)
 // line 2867, offset 0x8007770c
	/* begin block 1 */
		// Start line: 2868
		// Start offset: 0x8007770C
		// Variables:
	// 		int rc; // $a1

		/* begin block 1.1 */
			// Start line: 2874
			// Start offset: 0x80077720
			// Variables:
		// 		struct _TFace *tface; // $a2
		/* end block 1.1 */
		// End offset: 0x80077738
		// End Line: 2876

		/* begin block 1.2 */
			// Start line: 2880
			// Start offset: 0x80077764
			// Variables:
		// 		struct _HFace *hface; // stack offset -8
		/* end block 1.2 */
		// End offset: 0x80077764
		// End Line: 2888
	/* end block 1 */
	// End offset: 0x80077764
	// End Line: 2889

	/* begin block 2 */
		// Start line: 6481
	/* end block 2 */
	// End Line: 6482

int PHYSICS_CheckFaceStick(_PCollideInfo *CInfo)

{
  ushort uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (CInfo->type == 3) {
    uVar1 = *(ushort *)((int)CInfo->prim + 10);
    uVar2 = 0;
    if (uVar1 != 0xffff) {
      uVar2 = (uint)((*(ushort *)((int)&(CInfo->inst->node).prev[6].next[1].prev + (uint)uVar1 + 2)
                     & 0x200) != 0);
    }
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSICS_CheckDontGrabEdge(struct _PCollideInfo *CInfo /*$a0*/)
 // line 2893, offset 0x80077770
	/* begin block 1 */
		// Start line: 2895
		// Start offset: 0x80077770
		// Variables:
	// 		int rc; // $a1

		/* begin block 1.1 */
			// Start line: 2899
			// Start offset: 0x80077780
			// Variables:
		// 		struct _TFace *tface; // $a2
		/* end block 1.1 */
		// End offset: 0x80077798
		// End Line: 2901

		/* begin block 1.2 */
			// Start line: 2907
			// Start offset: 0x800777D4
			// Variables:
		// 		struct _HFace *hface; // $v0
		/* end block 1.2 */
		// End offset: 0x800777F4
		// End Line: 2913
	/* end block 1 */
	// End offset: 0x800777F4
	// End Line: 2914

	/* begin block 2 */
		// Start line: 6533
	/* end block 2 */
	// End Line: 6534

	/* begin block 3 */
		// Start line: 6534
	/* end block 3 */
	// End Line: 6535

	/* begin block 4 */
		// Start line: 6536
	/* end block 4 */
	// End Line: 6537

int PHYSICS_CheckDontGrabEdge(_PCollideInfo *CInfo)

{
  ushort uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (CInfo->type == 3) {
    uVar1 = *(ushort *)((int)CInfo->prim + 10);
    if (uVar1 != 0xffff) {
      uVar2 = (uint)((*(ushort *)((int)&(CInfo->inst->node).prev[6].next[1].prev + (uint)uVar1 + 2)
                     & 0x80) != 0);
    }
  }
  else {
    if ((CInfo->type == 2) && ((*(byte *)((int)CInfo->prim + 6) & 0x80) != 0)) {
      uVar2 = 1;
    }
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSICS_GenericLineCheckSetup(short x /*$a0*/, short y /*$a1*/, short z /*$a2*/, struct SVECTOR *inVec /*$a3*/)
 // line 2919, offset 0x800777fc
	/* begin block 1 */
		// Start line: 6585
	/* end block 1 */
	// End Line: 6586

	/* begin block 2 */
		// Start line: 6589
	/* end block 2 */
	// End Line: 6590

void PHYSICS_GenericLineCheckSetup(short x,short y,short z,SVECTOR *inVec)

{
  inVec->vx = x;
  inVec->vy = y;
  inVec->vz = z;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSICS_GenericLineCheck(struct _Instance *instance /*$a0*/, struct MATRIX *transMat /*$a1*/, struct MATRIX *rotMat /*$a2*/, struct _PCollideInfo *cInfo /*$a3*/)
 // line 2937, offset 0x8007780c
	/* begin block 1 */
		// Start line: 6621
	/* end block 1 */
	// End Line: 6622

void PHYSICS_GenericLineCheck
               (_Instance *instance,MATRIX *transMat,MATRIX *rotMat,_PCollideInfo *cInfo)

{
  cInfo->collideType = 0x3f;
  PHYSICS_GenericLineCheckMask(instance,transMat,rotMat,cInfo);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSICS_GenericLineCheckMask(struct _Instance *instance /*$a0*/, struct MATRIX *transMat /*$a1*/, struct MATRIX *rotMat /*$a2*/, struct _PCollideInfo *cInfo /*$a3*/)
 // line 2941, offset 0x80077830
	/* begin block 1 */
		// Start line: 2942
		// Start offset: 0x80077830
		// Variables:
	// 		struct SVECTOR *startVec; // $t0
	// 		struct SVECTOR *endVec; // $t1
	// 		struct VECTOR outVec; // stack offset -24
	/* end block 1 */
	// End offset: 0x80077830
	// End Line: 2942

	/* begin block 2 */
		// Start line: 6630
	/* end block 2 */
	// End Line: 6631

void PHYSICS_GenericLineCheckMask
               (_Instance *instance,MATRIX *transMat,MATRIX *rotMat,_PCollideInfo *cInfo)

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
  setCopControlWord(2,0,*(undefined4 *)rotMat->m);
  setCopControlWord(2,0x800,*(undefined4 *)(rotMat->m + 2));
  setCopControlWord(2,0x1000,*(undefined4 *)(rotMat->m + 4));
  setCopControlWord(2,0x1800,*(undefined4 *)(rotMat->m + 6));
  setCopControlWord(2,0x2000,*(undefined4 *)(rotMat->m + 8));
  setCopReg(2,in_zero,*(undefined4 *)pSVar4);
  setCopReg(2,in_at,*(undefined4 *)&pSVar4->vz);
  copFunction(2,0x486012);
  uVar1 = getCopReg(2,0x19);
  uVar2 = getCopReg(2,0x1a);
  uVar3 = getCopReg(2,0x1b);
  local_18 = (short)uVar1;
  pSVar4->vx = *(short *)transMat->t + local_18;
  local_14 = (short)uVar2;
  pSVar4->vy = *(short *)(transMat->t + 1) + local_14;
  local_10 = (short)uVar3;
  pSVar4->vz = *(short *)(transMat->t + 2) + local_10;
  setCopControlWord(2,0,*(undefined4 *)rotMat->m);
  setCopControlWord(2,0x800,*(undefined4 *)(rotMat->m + 2));
  setCopControlWord(2,0x1000,*(undefined4 *)(rotMat->m + 4));
  setCopControlWord(2,0x1800,*(undefined4 *)(rotMat->m + 6));
  setCopControlWord(2,0x2000,*(undefined4 *)(rotMat->m + 8));
  setCopReg(2,in_zero,*(undefined4 *)pSVar5);
  setCopReg(2,in_at,*(undefined4 *)&pSVar5->vz);
  copFunction(2,0x486012);
  uVar1 = getCopReg(2,0x19);
  uVar2 = getCopReg(2,0x1a);
  uVar3 = getCopReg(2,0x1b);
  local_18 = (short)uVar1;
  pSVar5->vx = *(short *)transMat->t + local_18;
  local_14 = (short)uVar2;
  pSVar5->vy = *(short *)(transMat->t + 1) + local_14;
  local_10 = (short)uVar3;
  pSVar5->vz = *(short *)(transMat->t + 2) + local_10;
  PHYSICS_CheckLineInWorldMask(instance,cInfo);
  return;
}





