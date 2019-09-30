#include "THISDUST.H"
#include "PHYSICS.H"


// decompiled code
// original method signature: 
// void /*$ra*/ SetNoPtCollideInFamily(struct _Instance *instance /*$a0*/)
 // line 57, offset 0x80074100
	/* begin block 1 */
		// Start line: 58
		// Start offset: 0x80074100
		// Variables:
	// 		struct _Instance *child; // $s0
	/* end block 1 */
	// End offset: 0x80074138
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
 // line 67, offset 0x80074148
	/* begin block 1 */
		// Start line: 68
		// Start offset: 0x80074148
		// Variables:
	// 		struct _Instance *child; // $s0
	/* end block 1 */
	// End offset: 0x80074184
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
 // line 79, offset 0x80074194
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
// void /*$ra*/ PHYSICS_CheckLineInWorldMask(struct _Instance *instance /*$s2*/, struct _PCollideInfo *pcollideInfo /*$s1*/)
 // line 85, offset 0x800741b8
	/* begin block 1 */
		// Start line: 86
		// Start offset: 0x800741B8
		// Variables:
	// 		struct Level *level; // $s0
	/* end block 1 */
	// End offset: 0x8007420C
	// End Line: 113

	/* begin block 2 */
		// Start line: 180
	/* end block 2 */
	// End Line: 181

void PHYSICS_CheckLineInWorldMask(_Instance *instance,_PCollideInfo *pcollideInfo)

{
                    /* WARNING: Subroutine does not return */
  STREAM_GetLevelWithID(instance->currentStreamUnitID);
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsCheckLinkedMove(struct _Instance *instance /*$s2*/, int Data /*stack 4*/, short Mode /*stack -72*/)
 // line 124, offset 0x8007422c
	/* begin block 1 */
		// Start line: 125
		// Start offset: 0x8007422C

		/* begin block 1.1 */
			// Start line: 128
			// Start offset: 0x80074270
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
				// Start offset: 0x800742E8
				// Variables:
			// 		struct _Instance *oldOn; // $a0
			/* end block 1.1.1 */
			// End offset: 0x8007430C
			// End Line: 153

			/* begin block 1.1.2 */
				// Start line: 182
				// Start offset: 0x800743F8
				// Variables:
			// 		struct _G2EulerAngles_Type newRot; // stack offset -96
			// 		struct VECTOR newRelPos; // stack offset -88
			// 		long oldPosX; // $s6
			// 		long oldPosY; // $fp
			// 		long oldPosZ; // $s7
			// 		int moved; // $s1
			// 		int rotated; // $s0
			/* end block 1.1.2 */
			// End offset: 0x800745A8
			// End Line: 245
		/* end block 1.1 */
		// End offset: 0x80074650
		// End Line: 260
	/* end block 1 */
	// End offset: 0x80074658
	// End Line: 266

	/* begin block 2 */
		// Start line: 263
	/* end block 2 */
	// End Line: 264

int PhysicsCheckLinkedMove(_Instance *instance,int Data,short Mode)

{
  bool bVar1;
  bool bVar2;
  _Instance *p_Var3;
  long lVar4;
  int introUniqueID;
  int iVar5;
  undefined4 *puVar6;
  undefined4 auStack144 [14];
  int local_58 [4];
  short local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  
  if (instance->matrix == (MATRIX *)0x0) {
    instance->attachedID = 0;
    return 0;
  }
  iVar5 = *(int *)Data;
  puVar6 = (undefined4 *)(*(int *)(iVar5 + 0x40) + *(int *)(Data + 4) * 0x20);
  local_40 = puVar6[5];
  local_3c = puVar6[6];
  local_38 = puVar6[7];
  local_34 = (int)(instance->position).y;
  local_30 = (int)(instance->position).z;
  introUniqueID = instance->attachedID;
  local_48 = Mode;
  if ((*(int *)(iVar5 + 0x3c) == introUniqueID) &&
     (bVar1 = false, *(int *)(Data + 4) == instance->attachedSegment)) {
    bVar2 = false;
    if ((*(int *)&instance->rotation != *(int *)&instance->oldRotation) ||
       ((instance->rotation).z != (instance->oldRotation).z)) {
      bVar2 = true;
    }
    if ((((instance->position).x != (instance->oldPos).x) || (local_34 != (int)(instance->oldPos).y)
        ) || (local_30 != (int)(instance->oldPos).z)) {
      bVar1 = true;
    }
    if ((!bVar1) && (!bVar2)) {
                    /* WARNING: Subroutine does not return */
      ApplyMatrixLV(puVar6,(uint *)(instance->relativeMatrix).t,local_58);
    }
                    /* WARNING: Subroutine does not return */
    TransposeMatrix(puVar6,auStack144);
  }
  if ((introUniqueID != *(int *)(iVar5 + 0x3c)) &&
     (p_Var3 = INSTANCE_Find(introUniqueID), p_Var3 != (_Instance *)0x0)) {
    p_Var3->flags2 = p_Var3->flags2 & 0xffffff7f;
  }
  *(uint *)(iVar5 + 0x18) = *(uint *)(iVar5 + 0x18) | 0x80;
  instance->attachedID = *(long *)(iVar5 + 0x3c);
  lVar4 = *(long *)(Data + 4);
  instance->zAccl = 0;
  instance->zVel = 0;
                    /* WARNING: Subroutine does not return */
  instance->attachedSegment = lVar4;
  TransposeMatrix(puVar6,auStack144);
}



// decompiled code
// original method signature: 
// void /*$ra*/ PhysicsDefaultLinkedMoveResponse(struct _Instance *instance /*$s0*/, struct evPhysicsLinkedMoveData *Data /*$s1*/, int updateTransforms /*$a2*/)
 // line 272, offset 0x80074688
	/* begin block 1 */
		// Start line: 596
	/* end block 1 */
	// End Line: 597

void PhysicsDefaultLinkedMoveResponse
               (_Instance *instance,evPhysicsLinkedMoveData *Data,int updateTransforms)

{
  (instance->position).x = (instance->position).x + (Data->posDelta).x;
  (instance->position).y = (instance->position).y + (Data->posDelta).y;
  (instance->position).z = (instance->position).z + (Data->posDelta).z;
  if (updateTransforms != 0) {
                    /* WARNING: Subroutine does not return */
    COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)&Data->posDelta);
  }
  (instance->rotation).z = (instance->rotation).z + (Data->rotDelta).z;
  return;
}



// autogenerated function stub: 
// int /*$ra*/ PhysicsCheckGravity(struct _Instance *instance /*$s1*/, int Data /*$s7*/, short Mode /*$s5*/)
int PhysicsCheckGravity(struct _Instance *instance, int Data, short Mode)
{ // line 296, offset 0x80074710
	/* begin block 1 */
		// Start line: 297
		// Start offset: 0x80074710
		// Variables:
			struct evPhysicsGravityData *Ptr; // $s3
			struct SVECTOR D; // stack offset -120
			struct SVECTOR N; // stack offset -112
			short Dot; // $v0
			int rc; // $s4
			struct _PCollideInfo CInfo; // stack offset -104
			struct SVECTOR Old; // stack offset -56
			struct SVECTOR New; // stack offset -48
			int slide; // $s6

		/* begin block 1.1 */
			// Start line: 326
			// Start offset: 0x800747F0
			// Variables:
				struct Level *level; // $s2
				struct _TFace *tface; // $s0
		/* end block 1.1 */
		// End offset: 0x800748A0
		// End Line: 349

		/* begin block 1.2 */
			// Start line: 490
			// Start offset: 0x80074D30
			// Variables:
				struct _Instance *oldOn; // $a0
		/* end block 1.2 */
		// End offset: 0x80074D54
		// End Line: 497
	/* end block 1 */
	// End offset: 0x80074E60
	// End Line: 550

	/* begin block 2 */
		// Start line: 644
	/* end block 2 */
	// End Line: 645

	return 0;
}


// decompiled code
// original method signature: 
// void /*$ra*/ PhysicsDefaultGravityResponse(struct _Instance *instance /*$a0*/, struct evPhysicsGravityData *Data /*$a1*/)
 // line 556, offset 0x80074e90
	/* begin block 1 */
		// Start line: 1279
	/* end block 1 */
	// End Line: 1280

	/* begin block 2 */
		// Start line: 1280
	/* end block 2 */
	// End Line: 1281

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
 // line 575, offset 0x80074f08
	/* begin block 1 */
		// Start line: 576
		// Start offset: 0x80074F08
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
	// End offset: 0x80075568
	// End Line: 852

	/* begin block 2 */
		// Start line: 1317
	/* end block 2 */
	// End Line: 1318

int PhysicsCheckEdgeGrabbing(_Instance *instance,GameTracker *gameTracker,int Data,short Mode)

{
  if ((Mode & 1U) != 0) {
    *(undefined4 *)(Data + 0x18) = 0;
  }
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(instance,7);
}



// decompiled code
// original method signature: 
// void /*$ra*/ PhysicsDefaultEdgeGrabResponse(struct _Instance *instance /*$s2*/, struct evPhysicsEdgeData *Data /*$s1*/, int blockFlag /*$a2*/)
 // line 865, offset 0x8007559c
	/* begin block 1 */
		// Start line: 866
		// Start offset: 0x8007559C
		// Variables:
	// 		struct _SVector normal; // stack offset -88
	// 		struct _G2EulerAngles_Type ea1; // stack offset -80
	// 		struct VECTOR OutTrans; // stack offset -72
	// 		struct MATRIX TempMat; // stack offset -56
	// 		struct SVECTOR New; // stack offset -24

		/* begin block 1.1 */
			// Start line: 915
			// Start offset: 0x800756B8
			// Variables:
		// 		long dp; // $v0
		/* end block 1.1 */
		// End offset: 0x800756B8
		// End Line: 915
	/* end block 1 */
	// End offset: 0x800756B8
	// End Line: 915

	/* begin block 2 */
		// Start line: 1989
	/* end block 2 */
	// End Line: 1990

void PhysicsDefaultEdgeGrabResponse(_Instance *instance,evPhysicsEdgeData *Data,int blockFlag)

{
  short sVar1;
  _SVector local_58;
  _G2EulerAngles_Type local_50 [3];
  _G2Matrix_Type local_38;
  short local_18;
  short sStack22;
  short local_14;
  
  if (blockFlag != 0) {
    local_58.z = 0;
    local_58.y = 0;
    local_58.x = 0;
    sVar1 = Data->Normal1->y;
    if (sVar1 < 0x201) {
      if (sVar1 < -0x200) {
        local_58.y = -0x1000;
        local_50[0].z = -0x800;
      }
    }
    else {
      local_58.y = 0x1000;
      local_50[0].z = 0;
    }
    sVar1 = Data->Normal1->x;
    if (sVar1 < 0x201) {
      if (sVar1 < -0x200) {
        local_58.x = -0x1000;
        local_50[0].z = 0x400;
      }
    }
    else {
      local_58.x = 0x1000;
      local_50[0].z = -0x400;
    }
    local_50[0].y = 0;
    local_50[0].x = 0;
    MATH3D_RotateAxisToVector((MATRIX *)&local_38,instance->matrix,&local_58,AXIS_Y);
    (instance->rotation).x = 0;
    (instance->rotation).y = 0;
    (instance->rotation).z = local_50[0].z;
    local_14 = Data->ZDistance;
    Data->zRot = (int)local_50[0].z;
    local_18 = Data->XDistance;
    sStack22 = Data->YDistance;
                    /* WARNING: Subroutine does not return */
    RotMatrix((ushort *)&instance->rotation,(uint *)&local_38);
  }
  local_58.x = Data->Normal1->x;
  local_58.y = Data->Normal1->y;
  local_58.z = 0;
  MATH3D_RotateAxisToVector((MATRIX *)&local_38,instance->matrix + 1,&local_58,AXIS_Y);
                    /* WARNING: Subroutine does not return */
  G2EulerAngles_FromMatrix(local_50,&local_38,0);
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsCheckSliding(struct _Instance *instance /*$s3*/, int Data /*$a1*/, short Mode /*$s6*/)
 // line 962, offset 0x80075840
	/* begin block 1 */
		// Start line: 963
		// Start offset: 0x80075840
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
			// Start line: 994
			// Start offset: 0x800758C8
		/* end block 1.1 */
		// End offset: 0x800758C8
		// End Line: 996

		/* begin block 1.2 */
			// Start line: 1003
			// Start offset: 0x80075904
			// Variables:
		// 		int Temp; // $a3
		/* end block 1.2 */
		// End offset: 0x800759D8
		// End Line: 1011
	/* end block 1 */
	// End offset: 0x80075CC0
	// End Line: 1145

	/* begin block 2 */
		// Start line: 2203
	/* end block 2 */
	// End Line: 2204

/* WARNING: Removing unreachable block (ram,0x80075974) */
/* WARNING: Removing unreachable block (ram,0x800759a4) */

int PhysicsCheckSliding(_Instance *instance,int Data,short Mode)

{
  int iVar1;
  short local_70;
  _PCollideInfo local_60;
  SVECTOR local_30;
  SVECTOR local_28;
  
  local_60.oldPoint = &local_30;
  local_60.newPoint = &local_28;
  pTempMat_46 = instance->matrix + *(short *)(Data + 0x18);
  local_30.vx = *(short *)pTempMat_46->t;
  local_30.vy = *(short *)(pTempMat_46->t + 1);
  local_30.vz = *(short *)(pTempMat_46->t + 2) + *(short *)(Data + 0x1e);
  if (instance->tface == (_TFace *)0x0) {
    iVar1 = (int)*(short *)(Data + 4) * 0x1000;
    *(int *)(Data + 0x24) = iVar1;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0xfff;
    }
    *(int *)(Data + 0x24) = iVar1 >> 0xc;
    iVar1 = *(int *)(Data + 0x24) * 0x1000;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0xfff;
    }
    local_70 = *(short *)(Data + 4) - (short)(iVar1 >> 0xc);
    local_28.vx = local_30.vx + *(short *)Data;
    local_28.vy = local_30.vy + *(short *)(Data + 2);
    local_28.vz = local_30.vz + local_70;
                    /* WARNING: Subroutine does not return */
    PHYSICS_CheckLineInWorld(instance,&local_60);
  }
                    /* WARNING: Subroutine does not return */
  STREAM_GetLevelWithID(instance->currentStreamUnitID);
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsUpdateTface(struct _Instance *instance /*$s0*/, int Data /*$a1*/)
 // line 1156, offset 0x80075cec
	/* begin block 1 */
		// Start line: 1157
		// Start offset: 0x80075CEC
		// Variables:
	// 		struct _PCollideInfo CInfo; // stack offset -72
	// 		struct SVECTOR Old; // stack offset -24
	// 		struct SVECTOR New; // stack offset -16
	/* end block 1 */
	// End offset: 0x80075DD8
	// End Line: 1198

	/* begin block 2 */
		// Start line: 2744
	/* end block 2 */
	// End Line: 2745

int PhysicsUpdateTface(_Instance *instance,int Data)

{
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
                    /* WARNING: Subroutine does not return */
  PHYSICS_CheckLineInWorld(instance,&local_48);
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsCheckBlockers(struct _Instance *instance /*$s3*/, struct GameTracker *gameTracker /*$a1*/, int Data /*$s4*/, short Mode /*$s2*/)
 // line 1211, offset 0x80075de8
	/* begin block 1 */
		// Start line: 1212
		// Start offset: 0x80075DE8
		// Variables:
	// 		struct evPhysicsEdgeData *Ptr; // $s1
	// 		struct VECTOR OutTrans; // stack offset -120
	// 		struct _PCollideInfo CInfo; // stack offset -104
	// 		struct SVECTOR Old; // stack offset -56
	// 		struct SVECTOR New; // stack offset -48
	// 		static struct MATRIX *pTempMat; // offset 0x28

		/* begin block 1.1 */
			// Start line: 1255
			// Start offset: 0x80075E94
			// Variables:
		// 		struct _TFace *tface; // $s0

			/* begin block 1.1.1 */
				// Start line: 1257
				// Start offset: 0x80075E94
				// Variables:
			// 		int Dot; // $a0
			// 		struct SVECTOR Force; // stack offset -40
			/* end block 1.1.1 */
			// End offset: 0x80075F78
			// End Line: 1302

			/* begin block 1.1.2 */
				// Start line: 1330
				// Start offset: 0x8007604C
				// Variables:
			// 		struct _HFace *hface; // stack offset -32
			/* end block 1.1.2 */
			// End offset: 0x8007604C
			// End Line: 1336
		/* end block 1.1 */
		// End offset: 0x80076164
		// End Line: 1380
	/* end block 1 */
	// End offset: 0x80076168
	// End Line: 1383

	/* begin block 2 */
		// Start line: 2867
	/* end block 2 */
	// End Line: 2868

int PhysicsCheckBlockers(_Instance *instance,GameTracker *gameTracker,int Data,short Mode)

{
  SVECTOR local_38 [4];
  
  *(undefined4 *)(Data + 0x20) = 0;
  *(undefined4 *)(Data + 0x18) = 0;
                    /* WARNING: Subroutine does not return */
  PHYSICS_GenericLineCheckSetup(0,0,0,local_38);
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsCheckSwim(struct _Instance *instance /*$s1*/, int Data /*$s3*/, short Mode /*$s5*/)
 // line 1465, offset 0x80076188
	/* begin block 1 */
		// Start line: 1466
		// Start offset: 0x80076188
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
	// End offset: 0x80076348
	// End Line: 1555

	/* begin block 2 */
		// Start line: 3488
	/* end block 2 */
	// End Line: 3489

int PhysicsCheckSwim(_Instance *instance,int Data,short Mode)

{
                    /* WARNING: Subroutine does not return */
  STREAM_GetLevelWithID(instance->currentStreamUnitID);
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsDefaultCheckSwimResponse(struct _Instance *instance /*$s2*/, struct evPhysicsSwimData *Data /*$s3*/)
 // line 1563, offset 0x80076378
	/* begin block 1 */
		// Start line: 1564
		// Start offset: 0x80076378
		// Variables:
	// 		int rc; // $s0
	// 		long waterZLevel; // $s1
	/* end block 1 */
	// End offset: 0x80076550
	// End Line: 1617

	/* begin block 2 */
		// Start line: 3713
	/* end block 2 */
	// End Line: 3714

int PhysicsDefaultCheckSwimResponse(_Instance *instance,evPhysicsSwimData *Data)

{
                    /* WARNING: Subroutine does not return */
  STREAM_GetLevelWithID(instance->currentStreamUnitID);
}



// decompiled code
// original method signature: 
// void /*$ra*/ PhysicsForceSetWater(struct _Instance *instance /*$s1*/, int *Time /*$t0*/, int Depth /*$a2*/, int rate /*$a3*/, int maxAmplitude /*stack 16*/)
 // line 1835, offset 0x80076570
	/* begin block 1 */
		// Start line: 1836
		// Start offset: 0x80076570
		// Variables:
	// 		int Amplitude; // $s0
	/* end block 1 */
	// End offset: 0x80076634
	// End Line: 1853

	/* begin block 2 */
		// Start line: 4259
	/* end block 2 */
	// End Line: 4260

void PhysicsForceSetWater(_Instance *instance,int *Time,int Depth,int rate,int maxAmplitude)

{
  int iVar1;
  
  iVar1 = *Time + (uint)(rate << 0xc) / gameTrackerX.timeMult;
  *Time = iVar1;
  if (0x1000 < iVar1) {
    *Time = iVar1 + -0x1000;
  }
  if (Depth < 0) {
                    /* WARNING: Subroutine does not return */
    rcos(*Time);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsCheckLOS(struct _Instance *instance /*$a0*/, int Data /*$a1*/, int Mode /*$a2*/)
 // line 1866, offset 0x80076648
	/* begin block 1 */
		// Start line: 1867
		// Start offset: 0x80076648
		// Variables:
	// 		struct _PCollideInfo CInfo; // stack offset -56
	/* end block 1 */
	// End offset: 0x80076648
	// End Line: 1867

	/* begin block 2 */
		// Start line: 4330
	/* end block 2 */
	// End Line: 4331

int PhysicsCheckLOS(_Instance *instance,int Data,int Mode)

{
  _PCollideInfo local_38;
  
  local_38.oldPoint = (SVECTOR *)(Data + 8);
  local_38.newPoint = (SVECTOR *)Data;
                    /* WARNING: Subroutine does not return */
  PHYSICS_CheckLineInWorld(instance,&local_38);
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsCheckDropHeight(struct _Instance *instance /*$s2*/, int Data /*$a1*/, int Mode /*$s3*/)
 // line 1894, offset 0x80076678
	/* begin block 1 */
		// Start line: 1895
		// Start offset: 0x80076678
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
			// Start line: 1908
			// Start offset: 0x800766AC
			// Variables:
		// 		struct VECTOR outTrans; // stack offset -40
		// 		struct SVECTOR *ExtraRot; // $v0
		/* end block 1.1 */
		// End offset: 0x800766F4
		// End Line: 1937

		/* begin block 1.2 */
			// Start line: 1961
			// Start offset: 0x800767C0
			// Variables:
		// 		long waterZLevel; // $a0
		/* end block 1.2 */
		// End offset: 0x800767FC
		// End Line: 1979
	/* end block 1 */
	// End offset: 0x800768EC
	// End Line: 2026

	/* begin block 2 */
		// Start line: 4396
	/* end block 2 */
	// End Line: 4397

int PhysicsCheckDropHeight(_Instance *instance,int Data,int Mode)

{
  if ((*(ushort *)(Data + 6) & 0x20) != 0) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(instance,8);
  }
                    /* WARNING: Subroutine does not return */
  STREAM_GetLevelWithID(instance->currentStreamUnitID);
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsCheckDropOff(struct _Instance *instance /*$s0*/, int Data /*$a1*/, short Mode /*$s3*/)
 // line 2038, offset 0x8007690c
	/* begin block 1 */
		// Start line: 2039
		// Start offset: 0x8007690C
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
	// End offset: 0x80076B14
	// End Line: 2133

	/* begin block 2 */
		// Start line: 4709
	/* end block 2 */
	// End Line: 4710

int PhysicsCheckDropOff(_Instance *instance,int Data,short Mode)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(instance,8);
}



// decompiled code
// original method signature: 
// int /*$ra*/ PhysicsFollowWall(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$a1*/, int Data /*$s6*/, short Mode /*$s4*/)
 // line 2187, offset 0x80076b30
	/* begin block 1 */
		// Start line: 2188
		// Start offset: 0x80076B30
		// Variables:
	// 		struct VECTOR OutTrans; // stack offset -160
	// 		struct evPhysicsWallCrawlData *Ptr; // $s1
	// 		struct _PCollideInfo CInfo; // stack offset -144
	// 		struct SVECTOR New; // stack offset -96
	// 		struct SVECTOR Old; // stack offset -88
	// 		static struct MATRIX *pTempMat; // offset 0x84

		/* begin block 1.1 */
			// Start line: 2250
			// Start offset: 0x80076C2C
			// Variables:
		// 		struct _Position A; // stack offset -80
		// 		struct _Position B; // stack offset -72
		// 		struct MATRIX mat; // stack offset -64
		/* end block 1.1 */
		// End offset: 0x80076D28
		// End Line: 2310
	/* end block 1 */
	// End offset: 0x80076F78
	// End Line: 2452

	/* begin block 2 */
		// Start line: 4358
	/* end block 2 */
	// End Line: 4359

int PhysicsFollowWall(_Instance *instance,GameTracker *gameTracker,int Data,short Mode)

{
  SVECTOR local_58 [7];
  
  *(undefined4 *)(Data + 0x28) = 0;
  pTempMat_72 = instance->matrix + *(short *)Data;
                    /* WARNING: Subroutine does not return */
  PHYSICS_GenericLineCheckSetup(0,0x40,0,local_58);
}



// decompiled code
// original method signature: 
// void /*$ra*/ PhysicsMoveLocalZClamp(struct _Instance *instance /*$s3*/, long segment /*$s0*/, long time /*$s1*/, long clamp /*$s2*/)
 // line 2600, offset 0x80076fa4
	/* begin block 1 */
		// Start line: 2601
		// Start offset: 0x80076FA4
		// Variables:
	// 		struct _Position pos; // stack offset -48
	// 		struct SVECTOR v; // stack offset -40
	// 		struct SVECTOR dv; // stack offset -32
	/* end block 1 */
	// End offset: 0x80077060
	// End Line: 2620

	/* begin block 2 */
		// Start line: 5082
	/* end block 2 */
	// End Line: 5083

void PhysicsMoveLocalZClamp(_Instance *instance,long segment,long time,long clamp)

{
  undefined local_30 [24];
  
                    /* WARNING: Subroutine does not return */
  memset(local_30,0,6);
}



// decompiled code
// original method signature: 
// void /*$ra*/ PhysicsMove(struct _Instance *instance /*$a0*/, struct _Position *position /*$a1*/, long time /*$a2*/)
 // line 2626, offset 0x8007707c
	/* begin block 1 */
		// Start line: 2628
		// Start offset: 0x8007707C
		// Variables:
	// 		long xVel; // $t0
	// 		long yVel; // $t1
	// 		long zVel; // $t2
	// 		long xat; // $t6
	// 		long yat; // $t4
	// 		long zat; // $t5
	/* end block 1 */
	// End offset: 0x80077208
	// End Line: 2664

	/* begin block 2 */
		// Start line: 5896
	/* end block 2 */
	// End Line: 5897

	/* begin block 3 */
		// Start line: 5897
	/* end block 3 */
	// End Line: 5898

	/* begin block 4 */
		// Start line: 5906
	/* end block 4 */
	// End Line: 5907

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
 // line 2698, offset 0x80077218
	/* begin block 1 */
		// Start line: 6049
	/* end block 1 */
	// End Line: 6050

void PhysicsSetVelFromZRot(_Instance *instance,short angle,long magnitude)

{
                    /* WARNING: Subroutine does not return */
  rcos((int)angle - 0x400);
}



// decompiled code
// original method signature: 
// void /*$ra*/ PhysicsSetVelFromRot(struct _Instance *instance /*$s0*/, struct _Rotation *rot /*$a1*/, long magnitude /*$a2*/)
 // line 2709, offset 0x80077288
	/* begin block 1 */
		// Start line: 2710
		// Start offset: 0x80077288
		// Variables:
	// 		struct MATRIX mat; // stack offset -56
	// 		struct SVECTOR flatPt; // stack offset -24
	// 		struct SVECTOR newPt; // stack offset -16
	/* end block 1 */
	// End offset: 0x80077288
	// End Line: 2710

	/* begin block 2 */
		// Start line: 6075
	/* end block 2 */
	// End Line: 6076

void PhysicsSetVelFromRot(_Instance *instance,_Rotation *rot,long magnitude)

{
  uint auStack56 [8];
  undefined2 local_18;
  short local_16;
  undefined2 local_14;
  
  local_16 = -(short)magnitude;
  local_18 = 0;
                    /* WARNING: Subroutine does not return */
  local_14 = 0;
  RotMatrix((ushort *)&instance->rotation,auStack56);
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSICS_SetVAndAFromRot(struct _Instance *instance /*$s0*/, struct _Rotation *rot /*$a1*/, long v /*$s1*/, long a /*$s2*/)
 // line 2729, offset 0x800772f8
	/* begin block 1 */
		// Start line: 2730
		// Start offset: 0x800772F8
		// Variables:
	// 		struct SVECTOR flatPt; // stack offset -72
	// 		struct MATRIX mat; // stack offset -64

		/* begin block 1.1 */
			// Start line: 2744
			// Start offset: 0x80077340
			// Variables:
		// 		struct SVECTOR newPt; // stack offset -32
		/* end block 1.1 */
		// End offset: 0x80077340
		// End Line: 2746

		/* begin block 1.2 */
			// Start line: 2763
			// Start offset: 0x8007738C
			// Variables:
		// 		struct SVECTOR newPt; // stack offset -24
		/* end block 1.2 */
		// End offset: 0x8007738C
		// End Line: 2765
	/* end block 1 */
	// End offset: 0x800773D0
	// End Line: 2779

	/* begin block 2 */
		// Start line: 6125
	/* end block 2 */
	// End Line: 6126

/* WARNING: Removing unreachable block (ram,0x8007738c) */
/* WARNING: Removing unreachable block (ram,0x80077340) */

void PHYSICS_SetVAndAFromRot(_Instance *instance,_Rotation *rot,long v,long a)

{
  uint auStack64 [12];
  
  if ((v == 0) && (a == 0)) {
    instance->xVel = 0;
    instance->yVel = 0;
    instance->zVel = 0;
    instance->xAccl = 0;
    instance->yAccl = 0;
    instance->zAccl = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  RotMatrix((ushort *)&instance->rotation,auStack64);
}



// decompiled code
// original method signature: 
// long /*$ra*/ PHYSICS_FindAFromDAndT(long d /*$a0*/, long t /*$a1*/)
 // line 2786, offset 0x800773e8
	/* begin block 1 */
		// Start line: 6243
	/* end block 1 */
	// End Line: 6244

	/* begin block 2 */
		// Start line: 6244
	/* end block 2 */
	// End Line: 6245

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
 // line 2799, offset 0x80077424
	/* begin block 1 */
		// Start line: 2800
		// Start offset: 0x80077424
		// Variables:
	// 		long vsq; // $a0
	/* end block 1 */
	// End offset: 0x8007744C
	// End Line: 2806

	/* begin block 2 */
		// Start line: 6269
	/* end block 2 */
	// End Line: 6270

	/* begin block 3 */
		// Start line: 6270
	/* end block 3 */
	// End Line: 6271

long PHYSICS_FindVFromAAndD(long a,long d)

{
  int square;
  
  square = a * d * 2;
  if (square == 0) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  MATH3D_FastSqrt0(square);
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSICS_StopIfCloseToTarget(struct _Instance *instance /*$a0*/, int x /*$a1*/, int y /*$a2*/, int z /*$a3*/)
 // line 2840, offset 0x8007745c
	/* begin block 1 */
		// Start line: 6354
	/* end block 1 */
	// End Line: 6355

	/* begin block 2 */
		// Start line: 6356
	/* end block 2 */
	// End Line: 6357

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
 // line 2862, offset 0x8007753c
	/* begin block 1 */
		// Start line: 2863
		// Start offset: 0x8007753C
		// Variables:
	// 		struct _PCollideInfo CInfo; // stack offset -56
	// 		struct MATRIX *pTempMat; // $a1
	/* end block 1 */
	// End offset: 0x8007753C
	// End Line: 2863

	/* begin block 2 */
		// Start line: 6398
	/* end block 2 */
	// End Line: 6399

int PHYSICS_CheckForTerrainCollide
              (_Instance *instance,SVECTOR *startVec,SVECTOR *endVec,int segment)

{
  _PCollideInfo local_38;
  
  local_38.collideType = 1;
  local_38.newPoint = endVec;
  local_38.oldPoint = startVec;
  PHYSICS_GenericLineCheckMask
            (instance,instance->matrix + segment,instance->matrix + segment,&local_38);
  return (uint)(local_38.type == 3);
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSICS_CheckForObjectCollide(struct _Instance *instance /*$a0*/, struct SVECTOR *startVec /*$a1*/, struct SVECTOR *endVec /*$a2*/, int segment /*$a3*/)
 // line 2881, offset 0x80077584
	/* begin block 1 */
		// Start line: 2882
		// Start offset: 0x80077584
		// Variables:
	// 		struct _PCollideInfo CInfo; // stack offset -56
	// 		struct MATRIX *pTempMat; // $a1
	/* end block 1 */
	// End offset: 0x80077584
	// End Line: 2882

	/* begin block 2 */
		// Start line: 6451
	/* end block 2 */
	// End Line: 6452

int PHYSICS_CheckForObjectCollide(_Instance *instance,SVECTOR *startVec,SVECTOR *endVec,int segment)

{
  _PCollideInfo local_38;
  
  local_38.collideType = 0x3e;
  local_38.newPoint = endVec;
  local_38.oldPoint = startVec;
  PHYSICS_GenericLineCheckMask
            (instance,instance->matrix + segment,instance->matrix + segment,&local_38);
  return (uint)(local_38.type != 0);
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSICS_CheckForValidMove(struct _Instance *instance /*$a0*/, struct SVECTOR *startVec /*$a1*/, struct SVECTOR *endVec /*$a2*/, int segment /*$a3*/)
 // line 2902, offset 0x800775c8
	/* begin block 1 */
		// Start line: 2903
		// Start offset: 0x800775C8
		// Variables:
	// 		struct _PCollideInfo CInfo; // stack offset -56
	// 		struct MATRIX *pTempMat; // $a1
	// 		int rc; // $a0
	/* end block 1 */
	// End offset: 0x80077624
	// End Line: 2926

	/* begin block 2 */
		// Start line: 6508
	/* end block 2 */
	// End Line: 6509

int PHYSICS_CheckForValidMove(_Instance *instance,SVECTOR *startVec,SVECTOR *endVec,int segment)

{
  int iVar1;
  uint uVar2;
  _PCollideInfo local_38;
  
  local_38.newPoint = endVec;
  local_38.oldPoint = startVec;
  PHYSICS_GenericLineCheck(instance,instance->matrix + segment,instance->matrix + segment,&local_38)
  ;
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
 // line 2930, offset 0x80077634
	/* begin block 1 */
		// Start line: 2931
		// Start offset: 0x80077634
		// Variables:
	// 		int rc; // $a1

		/* begin block 1.1 */
			// Start line: 2937
			// Start offset: 0x80077648
			// Variables:
		// 		struct _TFace *tface; // $a2
		/* end block 1.1 */
		// End offset: 0x80077660
		// End Line: 2939

		/* begin block 1.2 */
			// Start line: 2943
			// Start offset: 0x8007768C
			// Variables:
		// 		struct _HFace *hface; // stack offset -8
		/* end block 1.2 */
		// End offset: 0x8007768C
		// End Line: 2951
	/* end block 1 */
	// End offset: 0x8007768C
	// End Line: 2952

	/* begin block 2 */
		// Start line: 6567
	/* end block 2 */
	// End Line: 6568

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
// int /*$ra*/ PHYSICS_CheckDontGrabEdge(struct _PCollideInfo *CInfo /*$s0*/)
 // line 2956, offset 0x80077698
	/* begin block 1 */
		// Start line: 2957
		// Start offset: 0x80077698
		// Variables:
	// 		int rc; // $s1

		/* begin block 1.1 */
			// Start line: 2962
			// Start offset: 0x800776BC
			// Variables:
		// 		struct _TFace *tface; // $a0
		// 		struct BSPTree *bsp; // $v0
		/* end block 1.1 */
		// End offset: 0x80077734
		// End Line: 2971

		/* begin block 1.2 */
			// Start line: 2976
			// Start offset: 0x80077748
			// Variables:
		// 		struct _HFace *hface; // $v0
		/* end block 1.2 */
		// End offset: 0x80077764
		// End Line: 2980

		/* begin block 1.3 */
			// Start line: 2985
			// Start offset: 0x80077774
		/* end block 1.3 */
		// End offset: 0x800777A8
		// End Line: 2993
	/* end block 1 */
	// End offset: 0x800777A8
	// End Line: 2994

	/* begin block 2 */
		// Start line: 6619
	/* end block 2 */
	// End Line: 6620

int PHYSICS_CheckDontGrabEdge(_PCollideInfo *CInfo)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  
  sVar1 = CInfo->type;
  uVar3 = 0;
  if (sVar1 == 3) {
    uVar2 = *(ushort *)((int)CInfo->prim + 10);
    if (uVar2 != 0xffff) {
      uVar3 = (uint)((*(ushort *)((int)&(CInfo->inst->node).prev[6].next[1].prev + (uint)uVar2 + 2)
                     & 0x80) != 0);
    }
    if (((int)*(short *)((int)(CInfo->inst->node).prev[9].prev + (int)CInfo->segment * 0x24 + 0x12)
        & 0x8000U) == 0) {
      return uVar3;
    }
  }
  else {
    if (sVar1 != 2) {
      if (sVar1 != 5) {
        return 0;
      }
                    /* WARNING: Subroutine does not return */
      INSTANCE_Query(CInfo->inst,1);
    }
    if ((*(byte *)((int)CInfo->prim + 6) & 0x80) == 0) {
      return 0;
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSICS_GenericLineCheckSetup(short x /*$a0*/, short y /*$a1*/, short z /*$a2*/, struct SVECTOR *inVec /*$a3*/)
 // line 2999, offset 0x800777c0
	/* begin block 1 */
		// Start line: 6705
	/* end block 1 */
	// End Line: 6706

	/* begin block 2 */
		// Start line: 6709
	/* end block 2 */
	// End Line: 6710

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
 // line 3017, offset 0x800777d0
	/* begin block 1 */
		// Start line: 6741
	/* end block 1 */
	// End Line: 6742

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
 // line 3021, offset 0x800777f4
	/* begin block 1 */
		// Start line: 3022
		// Start offset: 0x800777F4
		// Variables:
	// 		struct SVECTOR *startVec; // $t0
	// 		struct SVECTOR *endVec; // $t1
	// 		struct VECTOR outVec; // stack offset -24
	/* end block 1 */
	// End offset: 0x800777F4
	// End Line: 3022

	/* begin block 2 */
		// Start line: 6750
	/* end block 2 */
	// End Line: 6751

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





