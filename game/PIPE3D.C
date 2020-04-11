
#include "PIPE3D.H"


// decompiled code
// original method signature: 
// void /*$ra*/ PIPE3D_AspectAdjustMatrix(struct MATRIX *matrix /*$a0*/)
 // line 68, offset 0x8003a740
	/* begin block 1 */
		// Start line: 136
	/* end block 1 */
	// End Line: 137

	/* begin block 2 */
		// Start line: 139
	/* end block 2 */
	// End Line: 140

/* File: C:\kain2\game\PIPE3D.C */

void PIPE3D_AspectAdjustMatrix(undefined matrix)

{
  undefined3 in_register_00000011;
  short *psVar1;
  
  psVar1 = (short *)CONCAT31(in_register_00000011,matrix);
  psVar1[3] = psVar1[3];
  psVar1[4] = psVar1[4];
  psVar1[5] = psVar1[5];
  *psVar1 = (short)(((int)*psVar1 << 9) / 0x140);
  psVar1[1] = (short)(((int)psVar1[1] << 9) / 0x140);
  psVar1[2] = (short)(((int)psVar1[2] << 9) / 0x140);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PIPE3D_CalculateWCTransform(struct _CameraCore_Type *cameraCore /*$s2*/)
 // line 88, offset 0x8003a7c8
	/* begin block 1 */
		// Start line: 89
		// Start offset: 0x8003A7C8
		// Variables:
	// 		struct MATRIX user_rotation; // stack offset -112
	// 		struct MATRIX first; // stack offset -80
	// 		struct MATRIX *cam_wcTrans; // $s3
	// 		struct SVECTOR v0; // stack offset -48
	// 		struct VECTOR v1; // stack offset -40
	/* end block 1 */
	// End offset: 0x8003A91C
	// End Line: 133

	/* begin block 2 */
		// Start line: 195
	/* end block 2 */
	// End Line: 196

	/* begin block 3 */
		// Start line: 201
	/* end block 3 */
	// End Line: 202

/* File: C:\kain2\game\PIPE3D.C */

void PIPE3D_CalculateWCTransform(_CameraCore_Type *cameraCore)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  undefined4 in_zero;
  undefined4 in_at;
  MATRIX *m2;
  MATRIX MStack112;
  MATRIX local_50;
  undefined4 local_30;
  uint local_2c;
  VECTOR local_28;
  
  m2 = cameraCore->wcTransform;
  local_30 = CONCAT22(-(cameraCore->position).y,-(cameraCore->position).x);
  local_2c = local_2c & 0xffff0000 | (uint)(ushort)-(cameraCore->position).z;
  if ((DAT_800d218c & 8) == 0) {
    MATH3D_SetUnityMatrix(0x90);
    RotMatrixZ(-(int)(cameraCore->rotation).z,&MStack112);
    RotMatrixX(-(int)(cameraCore->rotation).x,&MStack112);
    RotMatrixY(-(int)(cameraCore->rotation).y,&MStack112);
    local_30 = CONCAT22(-(cameraCore->position).y,-(cameraCore->position).x);
    local_2c = local_2c & 0xffff0000 | (uint)(ushort)-(cameraCore->position).z;
  }
  else {
    MATH3D_SetUnityMatrix(0x90);
    RotMatrixZ(-(int)(cameraCore->debugRot).z,&MStack112);
    RotMatrixY(-(int)(cameraCore->debugRot).y,&MStack112);
    RotMatrixX(-(int)(cameraCore->debugRot).x,&MStack112);
    local_30 = CONCAT22(-(cameraCore->debugPos).y,-(cameraCore->debugPos).x);
    local_2c = local_2c & 0xffff0000 | (uint)(ushort)-(cameraCore->debugPos).z;
    sVar1 = (cameraCore->position).y;
    sVar2 = (cameraCore->position).z;
    sVar3 = (cameraCore->debugPos).x;
    sVar4 = (cameraCore->debugPos).y;
    sVar5 = (cameraCore->debugPos).z;
    (cameraCore->nondebugPos).x = (cameraCore->position).x;
    (cameraCore->nondebugPos).y = sVar1;
    (cameraCore->nondebugPos).z = sVar2;
    (cameraCore->position).x = sVar3;
    (cameraCore->position).y = sVar4;
    (cameraCore->position).z = sVar5;
  }
  local_50.m[0][0] = 0x1000;
  local_50.m[0][1] = 0;
  local_50.m[0][2] = 0;
  local_50.m[1][0] = 0;
  local_50.m[1][1] = 0;
  local_50.m[1][2] = -0x1000;
  local_50.m[2][0] = 0;
  local_50.m[2][1] = 0x1000;
  local_50.m[2][2] = 0;
  MulMatrix0(&local_50,&MStack112,m2);
  MulMatrix0(&local_50,&MStack112,cameraCore->wcTransform2);
  PIPE3D_AspectAdjustMatrix((char)m2);
  sVar1 = m2->m[1];
  m2->m[0] = (short)((int)m2->m[0] * (int)(cameraCore->screenScale).x >> 0xc);
  m2->m[1] = (short)((int)sVar1 * (int)(cameraCore->screenScale).x >> 0xc);
  m2->m[2] = (short)((int)m2->m[2] * (int)(cameraCore->screenScale).x >> 0xc);
  m2->m[3] = (short)((int)m2->m[3] * (int)(cameraCore->screenScale).y >> 0xc);
  m2->m[4] = (short)((int)m2->m[4] * (int)(cameraCore->screenScale).y >> 0xc);
  m2->m[5] = (short)((int)m2->m[5] * (int)(cameraCore->screenScale).y >> 0xc);
  m2->m[6] = (short)((int)m2->m[6] * (int)(cameraCore->screenScale).z >> 0xc);
  m2->m[7] = (short)((int)m2->m[7] * (int)(cameraCore->screenScale).z >> 0xc);
  m2->m[8] = (short)((int)m2->m[8] * (int)(cameraCore->screenScale).z >> 0xc);
  setCopControlWord(2,0,*(undefined4 *)m2->m);
  setCopControlWord(2,0x800,*(undefined4 *)(m2->m + 2));
  setCopControlWord(2,0x1000,*(undefined4 *)(m2->m + 4));
  setCopControlWord(2,0x1800,*(undefined4 *)(m2->m + 6));
  setCopControlWord(2,0x2000,*(undefined4 *)(m2->m + 8));
  setCopReg(2,in_zero,local_30);
  setCopReg(2,in_at,local_2c);
  copFunction(2,0x486012);
  local_28.vx = getCopReg(2,0x19);
  local_28.vy = getCopReg(2,0x1a);
  local_28.vz = getCopReg(2,0x1b);
  TransMatrix(m2,&local_28);
  m2 = cameraCore->wcTransform2;
  setCopControlWord(2,0,*(undefined4 *)m2->m);
  setCopControlWord(2,0x800,*(undefined4 *)(m2->m + 2));
  setCopControlWord(2,0x1000,*(undefined4 *)(m2->m + 4));
  setCopControlWord(2,0x1800,*(undefined4 *)(m2->m + 6));
  setCopControlWord(2,0x2000,*(undefined4 *)(m2->m + 8));
  setCopReg(2,in_zero,local_30);
  setCopReg(2,in_at,local_2c);
  copFunction(2,0x486012);
  local_28.vx = getCopReg(2,0x19);
  local_28.vy = getCopReg(2,0x1a);
  local_28.vz = getCopReg(2,0x1b);
  TransMatrix(cameraCore->wcTransform2,&local_28);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PIPE3D_InvertTransform(struct MATRIX *target /*$s2*/, struct MATRIX *source /*$s1*/)
 // line 154, offset 0x8003ab44
	/* begin block 1 */
		// Start line: 155
		// Start offset: 0x8003AB44
		// Variables:
	// 		struct VECTOR sourceTrans; // stack offset -64
	// 		struct MATRIX normMat; // stack offset -48
	/* end block 1 */
	// End offset: 0x8003AB8C
	// End Line: 168

	/* begin block 2 */
		// Start line: 359
	/* end block 2 */
	// End Line: 360

/* File: C:\kain2\game\PIPE3D.C */

void PIPE3D_InvertTransform(undefined target,undefined source)

{
  undefined3 in_register_00000011;
  MATRIX *m1;
  MATRIX *m0;
  undefined3 in_register_00000015;
  MATRIX *pMVar1;
  VECTOR local_40;
  MATRIX MStack48;
  
  pMVar1 = (MATRIX *)CONCAT31(in_register_00000015,source);
  m1 = (MATRIX *)CONCAT31(in_register_00000011,target);
  m0 = pMVar1;
  if (*(short *)&pMVar1->field_0x12 == 1) {
    PIPE3D_NormalizeMatrix((char)&MStack48,source);
    m0 = &MStack48;
  }
  TransposeMatrix(m0,m1);
  local_40.vx = -pMVar1->t[0];
  local_40.vy = -pMVar1->t[1];
  local_40.vz = -pMVar1->t[2];
  ApplyMatrixLV(m1,&local_40,(VECTOR *)m1->t);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ PIPE3D_MatrixColumnLength(struct MATRIX *transform /*$a0*/, long column /*$a1*/)
 // line 174, offset 0x8003abd8
	/* begin block 1 */
		// Start line: 175
		// Start offset: 0x8003ABD8
	/* end block 1 */
	// End offset: 0x8003ABD8
	// End Line: 175

	/* begin block 2 */
		// Start line: 405
	/* end block 2 */
	// End Line: 406

/* File: C:\kain2\game\PIPE3D.C */

long PIPE3D_MatrixColumnLength(undefined transform,long column)

{
  short *psVar1;
  ulong square;
  long lVar2;
  undefined3 in_register_00000011;
  
  psVar1 = (short *)(CONCAT31(in_register_00000011,transform) + column * 2);
  square = MATH3D_SquareLength((int)*psVar1,(int)psVar1[3],(int)psVar1[6]);
  lVar2 = MATH3D_FastSqrt0(square);
  return lVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PIPE3D_NormalizeMatrix(struct MATRIX *target /*$s1*/, struct MATRIX *source /*$s0*/)
 // line 183, offset 0x8003ac14
	/* begin block 1 */
		// Start line: 184
		// Start offset: 0x8003AC14
		// Variables:
	// 		struct VECTOR scalevec; // stack offset -32
	// 		long scale; // $v1

		/* begin block 1.1 */
			// Start line: 196
			// Start offset: 0x8003AC9C
			// TypeDefs:
		// 		struct PIPE3D_234fake tmm
		/* end block 1.1 */
		// End offset: 0x8003AC9C
		// End Line: 196

		/* begin block 1.2 */
			// Start line: 196
			// Start offset: 0x8003AC9C
			// TypeDefs:
		// 		struct PIPE3D_235fake cmm
		/* end block 1.2 */
		// End offset: 0x8003AC9C
		// End Line: 196
	/* end block 1 */
	// End offset: 0x8003AC9C
	// End Line: 200

	/* begin block 2 */
		// Start line: 426
	/* end block 2 */
	// End Line: 427

/* File: C:\kain2\game\PIPE3D.C */

void PIPE3D_NormalizeMatrix(undefined target,undefined source)

{
  undefined3 in_register_00000011;
  MATRIX *m;
  undefined3 in_register_00000015;
  undefined4 *puVar1;
  long lVar2;
  undefined4 uVar3;
  long lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  VECTOR local_20;
  
  puVar1 = (undefined4 *)CONCAT31(in_register_00000015,source);
  m = (MATRIX *)CONCAT31(in_register_00000011,target);
  local_20.vx = PIPE3D_MatrixColumnLength(source,0);
  if (local_20.vx != 0) {
    local_20.vx = 0x1000000 / local_20.vx;
  }
  local_20.vy = PIPE3D_MatrixColumnLength(source,1);
  if (local_20.vy != 0) {
    local_20.vy = 0x1000000 / local_20.vy;
  }
  local_20.vz = PIPE3D_MatrixColumnLength(source,2);
  if (local_20.vz != 0) {
    local_20.vz = 0x1000000 / local_20.vz;
  }
  lVar2 = puVar1[6];
  lVar4 = puVar1[7];
  m->t[0] = puVar1[5];
  m->t[1] = lVar2;
  m->t[2] = lVar4;
  uVar3 = puVar1[1];
  uVar5 = puVar1[2];
  uVar6 = puVar1[3];
  *(undefined4 *)m->m = *puVar1;
  *(undefined4 *)(m->m + 2) = uVar3;
  *(undefined4 *)(m->m + 4) = uVar5;
  *(undefined4 *)(m->m + 6) = uVar6;
  *(undefined4 *)(m->m + 8) = puVar1[4];
  ScaleMatrix(m,&local_20);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PIPE3D_TransformVerticesToWorld(struct _Instance *instance /*stack 0*/, struct _SVector *poolVertex /*$s2*/, long *vtxSegment /*$s5*/, struct _Vector *Average /*$fp*/)
 // line 753, offset 0x8003ad00
	/* begin block 1 */
		// Start line: 754
		// Start offset: 0x8003AD00
		// Variables:
	// 		struct MATRIX *segMatrix; // $s1
	// 		struct _Model *model; // $s7
	// 		struct _MVertex *vertexList; // stack offset -48
	// 		long i; // $s3
	// 		struct _Segment *segment; // $v1
	// 		struct _SVector *orgPoolVertex; // stack offset -44
	// 		struct _SVector minV; // stack offset -64
	// 		struct _SVector maxV; // stack offset -56

		/* begin block 1.1 */
			// Start line: 773
			// Start offset: 0x8003ADE0
			// Variables:
		// 		struct _MVertex *firstVertex; // $s0
		// 		struct _MVertex *lastVertex; // $s6
		// 		struct _MVertex *modelVertex; // $s0
		/* end block 1.1 */
		// End offset: 0x8003AF2C
		// End Line: 815
	/* end block 1 */
	// End offset: 0x8003AFFC
	// End Line: 840

	/* begin block 2 */
		// Start line: 1498
	/* end block 2 */
	// End Line: 1499

/* WARNING: Could not reconcile some variable overlaps */
/* File: C:\kain2\game\PIPE3D.C */

void PIPE3D_TransformVerticesToWorld
               (_Instance *instance,_SVector *poolVertex,long *vtxSegment,_Vector *Average)

{
  undefined4 in_zero;
  undefined4 in_at;
  _Segment *p_Var1;
  ushort *puVar2;
  short *psVar3;
  _MVertex *p_Var4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  _MVertex *p_Var8;
  MATRIX *pMVar9;
  _SVector *p_Var10;
  int iVar11;
  _MVertex *p_Var12;
  _Model *p_Var13;
  undefined4 local_40;
  undefined *local_3c;
  undefined4 local_38;
  undefined *local_34;
  
  p_Var13 = instance->object->modelList[instance->currentModel];
  p_Var4 = p_Var13->vertexList;
  p_Var1 = p_Var13->segmentList;
  local_40 = DAT_800cfa78;
  local_3c = PTR_DAT_800cfa7c;
  local_3c._0_2_ = (short)PTR_DAT_800cfa7c;
  local_38 = DAT_800cfa80;
  local_34 = PTR_DAT_800cfa84;
  local_34._0_2_ = (short)PTR_DAT_800cfa84;
  Average->x = 0;
  Average->y = 0;
  Average->z = 0;
  iVar11 = 0;
  if (0 < p_Var13->numSegments) {
    psVar3 = &p_Var1->firstVertex;
    p_Var10 = poolVertex;
    do {
      if ((int)psVar3[1] != -1) {
        pMVar9 = instance->matrix;
        p_Var8 = p_Var4 + *psVar3;
        p_Var12 = p_Var4 + (int)psVar3[1];
        SetRotMatrix(pMVar9 + iVar11);
        SetTransMatrix(pMVar9 + iVar11);
        if (p_Var8 <= p_Var12) {
          puVar2 = (ushort *)&p_Var10->z;
          do {
            setCopReg(2,in_zero,*(undefined4 *)&p_Var8->vertex);
            setCopReg(2,in_at,*(undefined4 *)&(p_Var8->vertex).z);
            copFunction(2,0x480012);
            *vtxSegment = iVar11;
            vtxSegment = vtxSegment + 1;
            p_Var8 = p_Var8 + 1;
            uVar5 = getCopReg(2,0x4800);
            uVar6 = getCopReg(2,0x5000);
            uVar7 = getCopReg(2,0x5800);
            p_Var10->x = (short)uVar5;
            p_Var10->y = (short)uVar6;
            p_Var10->z = (short)uVar7;
            if ((short)local_38 < p_Var10->x) {
              local_38 = local_38 & 0xffff0000 | (uint)(ushort)p_Var10->x;
            }
            if (p_Var10->x < (short)local_40) {
              local_40 = local_40 & 0xffff0000 | (uint)(ushort)p_Var10->x;
            }
            if (local_38._2_2_ < (short)puVar2[-1]) {
              local_38 = local_38 & 0xffff | (uint)puVar2[-1] << 0x10;
            }
            if ((short)puVar2[-1] < local_40._2_2_) {
              local_40 = local_40 & 0xffff | (uint)puVar2[-1] << 0x10;
            }
            if ((short)local_34 < (short)*puVar2) {
              local_34 = (undefined *)(uint)*puVar2;
            }
            if ((short)*puVar2 < (short)local_3c) {
              local_3c = (undefined *)(uint)*puVar2;
            }
            puVar2 = puVar2 + 4;
            p_Var10 = p_Var10 + 1;
          } while (p_Var8 <= p_Var12);
        }
      }
      iVar11 = iVar11 + 1;
      psVar3 = psVar3 + 0xc;
    } while (iVar11 < p_Var13->numSegments);
  }
  if (p_Var13->numVertices != 0) {
    Average->x = (int)(short)local_38 + (int)(short)local_40 >> 1;
    Average->y = (int)local_38._2_2_ + (int)local_40._2_2_ >> 1;
    Average->z = (int)(short)local_34 + (int)(short)local_3c >> 1;
    iVar11 = 0;
    if (0 < p_Var13->numVertices) {
      psVar3 = &poolVertex->z;
      do {
        poolVertex->x = poolVertex->x - *(short *)&Average->x;
        iVar11 = iVar11 + 1;
        psVar3[-1] = psVar3[-1] - *(short *)&Average->y;
        poolVertex = poolVertex + 1;
        *psVar3 = *psVar3 - *(short *)&Average->z;
        psVar3 = psVar3 + 4;
      } while (iVar11 < p_Var13->numVertices);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PIPE3D_InstanceTransformAndDraw(struct _Instance *instance /*$s2*/, struct _CameraCore_Type *cameraCore /*$s1*/, struct _VertexPool *vertexPool /*$s0*/, struct _PrimPool *primPool /*$s7*/, unsigned long **ot /*stack 16*/, struct _Mirror *mirror /*stack 20*/)
 // line 856, offset 0x8003b02c
	/* begin block 1 */
		// Start line: 857
		// Start offset: 0x8003B02C
		// Variables:
	// 		struct Object *object; // $v0
	// 		struct _Model *model; // $s4
	// 		struct MATRIX *matrixPool; // $s3
	// 		struct MATRIX lm; // stack offset -80
	// 		long flags; // $s1

		/* begin block 1.1 */
			// Start line: 893
			// Start offset: 0x8003B084
			// Variables:
		// 		struct _MVertex *vertexList; // $s0
		// 		struct _PVertex *poolVertex; // $s5
		// 		struct CVECTOR *vertexColor; // $s6
		// 		long spadOffset; // $v1
		// 		long spadFree; // $a1
		// 		long allocSize; // $a0

			/* begin block 1.1.1 */
				// Start line: 1036
				// Start offset: 0x8003B1AC
				// Variables:
			// 		long BackColorSave; // stack offset -44
			// 		long BlendStartSave; // $s0
			// 		int pval; // stack offset -48
			/* end block 1.1.1 */
			// End offset: 0x8003B2F8
			// End Line: 1076
		/* end block 1.1 */
		// End offset: 0x8003B2F8
		// End Line: 1081
	/* end block 1 */
	// End offset: 0x8003B2F8
	// End Line: 1082

	/* begin block 2 */
		// Start line: 1344
	/* end block 2 */
	// End Line: 1345

/* File: C:\kain2\game\PIPE3D.C */

void PIPE3D_InstanceTransformAndDraw
               (_Instance *instance,_CameraCore_Type *cameraCore,_VertexPool *vertexPool,
               _PrimPool *primPool,ulong **ot,_Mirror *mirror)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 in_zero;
  undefined4 in_at;
  uint uVar3;
  ulong *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  _MVertex *p_Var8;
  undefined4 uVar9;
  MATRIX *pMVar10;
  _Model *p_Var11;
  CVECTOR *pCVar12;
  MATRIX MStack80;
  int local_30;
  undefined *local_2c;
  
  pMVar10 = instance->matrix;
  p_Var11 = instance->object->modelList[instance->currentModel];
  if (pMVar10 != (MATRIX *)0x0) {
    LIGHT_PresetInstanceLight(instance,0x800,0xb0);
    pCVar12 = vertexPool->color;
    iVar6 = 0xe0;
    iVar7 = p_Var11->numVertices;
    p_Var8 = p_Var11->vertexList;
    iVar5 = 0x20;
    if (iVar7 * 2 < 0xe1) {
      vertexPool = (_VertexPool *)&DAT_1f800080;
      iVar5 = iVar7 * 2 + 0x20;
      iVar6 = iVar7 * -2 + 0xe0;
    }
    if (iVar7 <= iVar6) {
      pCVar12 = (CVECTOR *)(iVar5 * 4 + 0x1f800000);
    }
    modelFadeValue = INSTANCE_GetFadeValue(instance);
    uVar3 = PIPE3D_TransformAnimatedInstanceVertices_S
                      ((int)p_Var8,(undefined4 *)vertexPool,(uint)p_Var11,
                       (undefined4 *)cameraCore->wcTransform,(ushort *)pMVar10,
                       (undefined4 *)&MStack80,(uint *)pCVar12,(uint *)instance->perVertexColor);
    LIGHT_PresetInstanceLight(instance,0x1000,(char)&MStack80);
    MulMatrix0(&MStack80,pMVar10 + instance->lightMatrix,&MStack80);
    SetLightMatrix(&MStack80);
    if ((uVar3 & 0x8000) != 0) {
      uVar3 = uVar3 & 0x7fff6fff;
    }
    if ((((uVar3 & 0xffffefff) == 0) || ((instance->object->oflags2 & 0x2000U) != 0)) &&
       (primPool->nextPrim + p_Var11->numFaces * 0xc < primPool->lastPrim)) {
      local_2c = (undefined *)0x0;
      if ((instance->object->oflags2 & 0x1000U) == 0) {
        SetRotMatrix(DAT_800d0ffc);
        SetTransMatrix(DAT_800d0ffc);
        setCopReg(2,in_zero,*(undefined4 *)&instance->position);
        setCopReg(2,in_at,*(undefined4 *)&(instance->position).z);
        copFunction(2,0x180001);
      }
      puVar2 = depthQBackColor;
      uVar1 = depthQBlendStart;
      local_30 = getCopReg(2,8);
      uVar9 = 0;
      if (instance->petrifyValue != 0) {
        depthQBackColor = &DAT_00707070;
        local_2c = puVar2;
        depthQBlendStart = depthQFogStart;
        LoadAverageCol((u_char *)&local_2c,(u_char *)&depthQBackColor,local_30,0x1000 - local_30,
                       (u_char *)&depthQBackColor);
        uVar9 = uVar1;
        if (instance->petrifyValue < local_30) {
          setCopReg(2,0x4000,local_30);
        }
        else {
          setCopReg(2,0x4000,(uint)(ushort)instance->petrifyValue);
        }
      }
      if ((modelFadeValue < 0xffe) &&
         (((instance->object->oflags2 & 0x1000U) != 0 || (local_30 < 0xffa)))) {
        puVar4 = (ulong *)(*DAT_800d2218)(p_Var11,vertexPool,primPool,ot,pCVar12);
        primPool->nextPrim = puVar4;
      }
      if (instance->petrifyValue != 0) {
        depthQBackColor = local_2c;
        depthQBlendStart = uVar9;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PIPE3D_ExtentsOfPrims(long *firstPrim /*$a0*/, long *lastPrim /*$a1*/, long *pminx /*$a2*/, long *pminy /*$a3*/, long *pmaxx /*stack 16*/, long *pmaxy /*stack 20*/)
 // line 1187, offset 0x8003b324
	/* begin block 1 */
		// Start line: 1188
		// Start offset: 0x8003B324
		// Variables:
	// 		int len; // $t5
	// 		int code; // $v1
	// 		struct POLY_FT3 *polyFT3; // $t4
	// 		struct POLY_GT3 *polyGT3; // $t4
	// 		long *curPrim; // $a0
	// 		int minx; // $t0
	// 		int miny; // $t1
	// 		int maxx; // $t2
	// 		int maxy; // $t3
	/* end block 1 */
	// End offset: 0x8003B514
	// End Line: 1268

	/* begin block 2 */
		// Start line: 2053
	/* end block 2 */
	// End Line: 2054

	/* begin block 3 */
		// Start line: 2059
	/* end block 3 */
	// End Line: 2060

/* File: C:\kain2\game\PIPE3D.C */

void PIPE3D_ExtentsOfPrims
               (long *firstPrim,long *lastPrim,long *pminx,long *pminy,long *pmaxx,long *pmaxy)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = 0x7ff;
  iVar4 = 0x7ff;
  iVar5 = -0x7ff;
  iVar6 = -0x7ff;
  if (firstPrim < lastPrim) {
    do {
      if (*(char *)((int)firstPrim + 7) == '$') {
        iVar2 = (int)*(short *)(firstPrim + 2);
        if (iVar2 < iVar3) {
          iVar3 = iVar2;
        }
        if (iVar5 < iVar2) {
          iVar5 = iVar2;
        }
        iVar2 = (int)*(short *)(firstPrim + 4);
        if (iVar2 < iVar3) {
          iVar3 = iVar2;
        }
        if (iVar5 < iVar2) {
          iVar5 = iVar2;
        }
        iVar2 = (int)*(short *)(firstPrim + 6);
        if (iVar2 < iVar3) {
          iVar3 = iVar2;
        }
        if (iVar5 < iVar2) {
          iVar5 = iVar2;
        }
        iVar2 = (int)*(short *)((int)firstPrim + 10);
        if (iVar2 < iVar4) {
          iVar4 = iVar2;
        }
        if (iVar6 < iVar2) {
          iVar6 = iVar2;
        }
        iVar2 = (int)*(short *)((int)firstPrim + 0x12);
        if (iVar2 < iVar4) {
          iVar4 = iVar2;
        }
        if (iVar6 < iVar2) {
          iVar6 = iVar2;
        }
        iVar2 = (int)*(short *)((int)firstPrim + 0x1a);
        bVar1 = iVar2 < iVar4;
LAB_8003b4e8:
        if (bVar1) {
          iVar4 = iVar2;
        }
        if (iVar6 < iVar2) {
          iVar6 = iVar2;
        }
      }
      else {
        if (*(char *)((int)firstPrim + 7) == '4') {
          iVar2 = (int)*(short *)(firstPrim + 2);
          if (iVar2 < iVar3) {
            iVar3 = iVar2;
          }
          if (iVar5 < iVar2) {
            iVar5 = iVar2;
          }
          iVar2 = (int)*(short *)(firstPrim + 5);
          if (iVar2 < iVar3) {
            iVar3 = iVar2;
          }
          if (iVar5 < iVar2) {
            iVar5 = iVar2;
          }
          iVar2 = (int)*(short *)(firstPrim + 8);
          if (iVar2 < iVar3) {
            iVar3 = iVar2;
          }
          if (iVar5 < iVar2) {
            iVar5 = iVar2;
          }
          iVar2 = (int)*(short *)((int)firstPrim + 10);
          if (iVar2 < iVar4) {
            iVar4 = iVar2;
          }
          if (iVar6 < iVar2) {
            iVar6 = iVar2;
          }
          iVar2 = (int)*(short *)((int)firstPrim + 0x16);
          if (iVar2 < iVar4) {
            iVar4 = iVar2;
          }
          if (iVar6 < iVar2) {
            iVar6 = iVar2;
          }
          iVar2 = (int)*(short *)((int)firstPrim + 0x22);
          bVar1 = iVar2 < iVar4;
          goto LAB_8003b4e8;
        }
      }
      firstPrim = firstPrim + (uint)*(byte *)((int)firstPrim + 3) + 1;
    } while (firstPrim < lastPrim);
  }
  *pminx = iVar3;
  *pminy = iVar4;
  *pmaxx = iVar5;
  *pmaxy = iVar6;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PIPE3D_AddPredatorEffect_Scale(long *firstPrim /*$s1*/, long *lastPrim /*$fp*/)
 // line 1348, offset 0x8003b534
	/* begin block 1 */
		// Start line: 1349
		// Start offset: 0x8003B534
		// Variables:
	// 		int len; // $s7
	// 		int code; // $v1
	// 		struct POLY_FT3 *polyFT3; // $s0
	// 		struct POLY_GT3 *polyGT3; // $s0
	// 		int tx; // $a2
	// 		long xScale; // $s5
	// 		long yScale; // $s4
	// 		long dispYPos; // $s6
	// 		long minx; // stack offset -56
	// 		long miny; // stack offset -52
	// 		long maxx; // stack offset -48
	// 		long maxy; // stack offset -44
	// 		long cx; // $s3
	// 		long cy; // $s2
	/* end block 1 */
	// End offset: 0x8003B8F4
	// End Line: 1447

	/* begin block 2 */
		// Start line: 2685
	/* end block 2 */
	// End Line: 2686

/* File: C:\kain2\game\PIPE3D.C */

void PIPE3D_AddPredatorEffect_Scale(long *firstPrim,long *lastPrim)

{
  byte bVar1;
  ushort uVar2;
  char cVar3;
  short sVar4;
  short sVar5;
  u_short uVar6;
  int iVar7;
  uint x;
  int iVar8;
  int iVar9;
  int y;
  long local_38;
  long local_34;
  long local_30;
  long local_2c;
  
  y = (DAT_800d20d0 ^ 1) << 8;
  PIPE3D_ExtentsOfPrims(firstPrim,lastPrim,&local_38,&local_34,&local_30,&local_2c);
  iVar8 = local_34 + local_2c >> 1;
  iVar9 = local_38 + local_30 >> 1;
  if (firstPrim < lastPrim) {
    do {
      bVar1 = *(byte *)((int)firstPrim + 3);
      sVar4 = (short)iVar9;
      sVar5 = (short)iVar8;
      if (*(char *)((int)firstPrim + 7) == '$') {
        uVar2 = *(ushort *)(firstPrim + 2);
        if (*(short *)(firstPrim + 2) < *(short *)(firstPrim + 4)) {
          iVar7 = (uint)*(ushort *)(firstPrim + 6) << 0x10;
          if (*(short *)(firstPrim + 2) < *(short *)(firstPrim + 6)) {
LAB_8003b638:
            iVar7 = (uint)uVar2 << 0x10;
          }
        }
        else {
          iVar7 = (uint)*(ushort *)(firstPrim + 6) << 0x10;
          uVar2 = *(ushort *)(firstPrim + 4);
          if (*(short *)(firstPrim + 4) < *(short *)(firstPrim + 6)) goto LAB_8003b638;
        }
        x = iVar7 >> 0x10 & 0xffffffc0;
        cVar3 = (char)x;
        *(char *)(firstPrim + 3) = *(char *)(firstPrim + 2) - cVar3;
        *(undefined *)((int)firstPrim + 0xd) = *(undefined *)((int)firstPrim + 10);
        *(char *)(firstPrim + 5) = *(char *)(firstPrim + 4) - cVar3;
        *(undefined *)((int)firstPrim + 0x15) = *(undefined *)((int)firstPrim + 0x12);
        *(char *)(firstPrim + 7) = *(char *)(firstPrim + 6) - cVar3;
        *(undefined *)((int)firstPrim + 0x1d) = *(undefined *)((int)firstPrim + 0x1a);
        uVar6 = GetTPage(2,0,x,y);
        *(u_short *)((int)firstPrim + 0x16) = uVar6;
        *(short *)(firstPrim + 2) =
             (short)((*(short *)(firstPrim + 2) - iVar9) * 0x1200 >> 0xc) + sVar4;
        *(byte *)((int)firstPrim + 7) = *(byte *)((int)firstPrim + 7) | 1;
        *(short *)(firstPrim + 4) =
             (short)((*(short *)(firstPrim + 4) - iVar9) * 0x1200 >> 0xc) + sVar4;
        *(short *)(firstPrim + 6) =
             (short)((*(short *)(firstPrim + 6) - iVar9) * 0x1200 >> 0xc) + sVar4;
        *(short *)((int)firstPrim + 10) =
             (short)((*(short *)((int)firstPrim + 10) - iVar8) * 0x1200 >> 0xc) + sVar5;
        *(short *)((int)firstPrim + 0x12) =
             (short)((*(short *)((int)firstPrim + 0x12) - iVar8) * 0x1200 >> 0xc) + sVar5;
        *(short *)((int)firstPrim + 0x1a) =
             (short)((*(short *)((int)firstPrim + 0x1a) - iVar8) * 0x1200 >> 0xc) + sVar5;
      }
      else {
        if (*(char *)((int)firstPrim + 7) == '4') {
          uVar2 = *(ushort *)(firstPrim + 2);
          if (*(short *)(firstPrim + 2) < *(short *)(firstPrim + 5)) {
            iVar7 = (uint)*(ushort *)(firstPrim + 8) << 0x10;
            if (*(short *)(firstPrim + 2) < *(short *)(firstPrim + 8)) {
LAB_8003b7b4:
              iVar7 = (uint)uVar2 << 0x10;
            }
          }
          else {
            iVar7 = (uint)*(ushort *)(firstPrim + 8) << 0x10;
            uVar2 = *(ushort *)(firstPrim + 5);
            if (*(short *)(firstPrim + 5) < *(short *)(firstPrim + 8)) goto LAB_8003b7b4;
          }
          x = iVar7 >> 0x10 & 0xffffffc0;
          cVar3 = (char)x;
          *(char *)(firstPrim + 3) = *(char *)(firstPrim + 2) - cVar3;
          *(undefined *)((int)firstPrim + 0xd) = *(undefined *)((int)firstPrim + 10);
          *(char *)(firstPrim + 6) = *(char *)(firstPrim + 5) - cVar3;
          *(undefined *)((int)firstPrim + 0x19) = *(undefined *)((int)firstPrim + 0x16);
          *(char *)(firstPrim + 9) = *(char *)(firstPrim + 8) - cVar3;
          *(undefined *)((int)firstPrim + 0x25) = *(undefined *)((int)firstPrim + 0x22);
          uVar6 = GetTPage(2,0,x,y);
          *(u_short *)((int)firstPrim + 0x1a) = uVar6;
          *(short *)(firstPrim + 2) =
               (short)((*(short *)(firstPrim + 2) - iVar9) * 0x1200 >> 0xc) + sVar4;
          *(byte *)((int)firstPrim + 7) = *(byte *)((int)firstPrim + 7) | 1;
          *(short *)(firstPrim + 5) =
               (short)((*(short *)(firstPrim + 5) - iVar9) * 0x1200 >> 0xc) + sVar4;
          *(short *)(firstPrim + 8) =
               (short)((*(short *)(firstPrim + 8) - iVar9) * 0x1200 >> 0xc) + sVar4;
          *(short *)((int)firstPrim + 10) =
               (short)((*(short *)((int)firstPrim + 10) - iVar8) * 0x1200 >> 0xc) + sVar5;
          *(short *)((int)firstPrim + 0x16) =
               (short)((*(short *)((int)firstPrim + 0x16) - iVar8) * 0x1200 >> 0xc) + sVar5;
          *(short *)((int)firstPrim + 0x22) =
               (short)((*(short *)((int)firstPrim + 0x22) - iVar8) * 0x1200 >> 0xc) + sVar5;
        }
      }
      firstPrim = firstPrim + (uint)bVar1 + 1;
    } while (firstPrim < lastPrim);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PIPE3D_InstanceListTransformAndDrawFunc(struct _StreamUnit *unit /*$a0*/, unsigned long **ot /*$s5*/, struct _CameraCore_Type *cameraCore /*$s1*/, struct _Instance *instance /*$s0*/)
 // line 1450, offset 0x8003b924
	/* begin block 1 */
		// Start line: 1451
		// Start offset: 0x8003B924
		// Variables:
	// 		struct _VertexPool *vertexPool; // $s4
	// 		struct _PrimPool *primPool; // $s2
	// 		long *savePrim; // $s3
	// 		struct VECTOR dpv[2]; // stack offset -72
	// 		long maxRad; // $a1
	// 		struct Level *level; // $s3
	// 		struct SVECTOR bsPos; // stack offset -40
	/* end block 1 */
	// End offset: 0x8003BC5C
	// End Line: 1569

	/* begin block 2 */
		// Start line: 2673
	/* end block 2 */
	// End Line: 2674

/* File: C:\kain2\game\PIPE3D.C */

void PIPE3D_InstanceListTransformAndDrawFunc
               (_StreamUnit *unit,ulong **ot,_CameraCore_Type *cameraCore,_Instance *instance)

{
  int iVar1;
  int iVar2;
  int iVar3;
  _VertexPool *vertexPool;
  _PrimPool *primPool;
  undefined4 in_zero;
  undefined4 in_at;
  uint uVar4;
  int iVar5;
  int iVar6;
  Level *level;
  ulong *firstPrim;
  uint local_24;
  
  primPool = DAT_800d210c;
  vertexPool = DAT_800d2108;
  level = unit->level;
  local_24 = local_24 & 0xffff0000 | (uint)(ushort)(instance->position).z;
  iVar6 = (int)instance->object->modelList[instance->currentModel]->maxRad;
  setCopControlWord(2,0,*(undefined4 *)cameraCore->vvNormalWorVecMat[0].m);
  setCopControlWord(2,0x800,*(undefined4 *)(cameraCore->vvNormalWorVecMat[0].m + 2));
  setCopControlWord(2,0x1000,*(undefined4 *)(cameraCore->vvNormalWorVecMat[0].m + 4));
  setCopControlWord(2,0x1800,*(undefined4 *)(cameraCore->vvNormalWorVecMat[0].m + 6));
  setCopControlWord(2,0x2000,*(undefined4 *)(cameraCore->vvNormalWorVecMat[0].m + 8));
  setCopReg(2,in_zero,*(undefined4 *)&instance->position);
  setCopReg(2,in_at,local_24);
  copFunction(2,0x486012);
  iVar5 = getCopReg(2,0x19);
  iVar1 = getCopReg(2,0x1a);
  iVar2 = getCopReg(2,0x1b);
  iVar5 = iVar5 - cameraCore->vvPlaneConsts[0];
  iVar3 = -iVar6;
  if ((((iVar3 < iVar5) && (iVar5 < cameraCore->farPlane + iVar6)) &&
      (iVar3 < iVar1 - cameraCore->vvPlaneConsts[1])) &&
     (iVar3 < iVar2 - cameraCore->vvPlaneConsts[2])) {
    setCopControlWord(2,0,*(undefined4 *)cameraCore->vvNormalWorVecMat[1].m);
    setCopControlWord(2,0x800,*(undefined4 *)(cameraCore->vvNormalWorVecMat[1].m + 2));
    setCopControlWord(2,0x1000,*(undefined4 *)(cameraCore->vvNormalWorVecMat[1].m + 4));
    setCopControlWord(2,0x1800,*(undefined4 *)(cameraCore->vvNormalWorVecMat[1].m + 6));
    setCopControlWord(2,0x2000,*(undefined4 *)(cameraCore->vvNormalWorVecMat[1].m + 8));
    setCopReg(2,in_zero,*(undefined4 *)&instance->position);
    setCopReg(2,in_at,local_24);
    copFunction(2,0x486012);
    iVar5 = getCopReg(2,0x19);
    iVar1 = getCopReg(2,0x1a);
    getCopReg(2,0x1b);
    if ((iVar3 < iVar5 - cameraCore->vvPlaneConsts[3]) &&
       (iVar3 < iVar1 - cameraCore->vvPlaneConsts[4])) {
      if ((instance->flags & 0x80U) == 0) {
        PIPE3D_AnimateTextures
                  (instance->object->modelList[instance->currentModel]->aniTextures,DAT_800d21f8);
        instance->currentTextureAnimFrame = instance->currentTextureAnimFrame + 1;
      }
      else {
        PIPE3D_AnimateTextures
                  (instance->object->modelList[instance->currentModel]->aniTextures,
                   (int)instance->currentTextureAnimFrame);
      }
      LIGHT_SetMatrixForLightGroupInstance(instance,level);
      firstPrim = primPool->nextPrim;
      if ((((instance->halvePlane).flags & 0xbU) == 0) || ((instance->flags2 & 0x800000U) != 0)) {
        PIPE3D_InstanceTransformAndDraw(instance,cameraCore,vertexPool,primPool,ot,(_Mirror *)0x0);
      }
      else {
        PIPE3D_HalvePlaneInstanceTransformAndDraw
                  (instance,(char)cameraCore->wcTransform,vertexPool,primPool,ot,(_Mirror *)0x0);
      }
      uVar4 = instance->flags2;
      if ((int)uVar4 < 0) {
        PIPE3D_AddPredatorEffect_Scale((long *)firstPrim,(long *)primPool->nextPrim);
        uVar4 = instance->flags2;
      }
      if ((uVar4 & 0x40) != 0) {
        LIGHT_DrawShadow((char)cameraCore->wcTransform,instance,primPool,ot);
      }
      if (instance->additionalDrawFunc != (void *)0x0) {
        (*(code *)instance->additionalDrawFunc)
                  (cameraCore->wcTransform,instance,vertexPool,primPool,ot);
      }
      DAT_800d2330 = DAT_800d2330 + 1;
      uVar4 = instance->flags | 0x200;
      goto LAB_8003bc58;
    }
  }
  uVar4 = instance->flags & 0xfffffdff;
LAB_8003bc58:
  instance->flags = uVar4;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PIPE3D_InstanceListTransformAndDraw(struct _StreamUnit *unit /*$s3*/, struct GameTracker *gameTracker /*$a1*/, unsigned long **ot /*$s4*/, struct _CameraCore_Type *cameraCore /*$s5*/)
 // line 1571, offset 0x8003bc80
	/* begin block 1 */
		// Start line: 1572
		// Start offset: 0x8003BC80
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		int id; // $s2
	// 		struct _Instance *player; // $s1
	/* end block 1 */
	// End offset: 0x8003BD50
	// End Line: 1586

	/* begin block 2 */
		// Start line: 2979
	/* end block 2 */
	// End Line: 2980

/* File: C:\kain2\game\PIPE3D.C */

void PIPE3D_InstanceListTransformAndDraw
               (_StreamUnit *unit,GameTracker *gameTracker,ulong **ot,_CameraCore_Type *cameraCore)

{
  _Instance *instance;
  _Instance *instance_00;
  int iVar1;
  
  instance_00 = gameTracker->playerInstance;
  iVar1 = unit->StreamUnitID;
  instance = gameTracker->instanceList->first;
  if ((instance_00->currentStreamUnitID == iVar1) && ((instance_00->flags & 0x800U) == 0)) {
    PIPE3D_InstanceListTransformAndDrawFunc(unit,ot,cameraCore,instance_00);
  }
  while (instance != (_Instance *)0x0) {
    if (((((instance->flags & 0x800U) == 0) && ((instance->flags2 & 0x4000000U) == 0)) &&
        (instance->currentStreamUnitID == iVar1)) && (instance != instance_00)) {
      PIPE3D_InstanceListTransformAndDrawFunc(unit,ot,cameraCore,instance);
    }
    instance = instance->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PIPE3D_TransformFromZAxis(struct MATRIX *transform /*$s0*/, struct _SVector *normal /*$s1*/)
 // line 1589, offset 0x8003bd78
	/* begin block 1 */
		// Start line: 1590
		// Start offset: 0x8003BD78
		// Variables:
	// 		struct _G2EulerAngles_Type ea1; // stack offset -40
	// 		struct _SVector xprod; // stack offset -32
	// 		struct _SVector yprod; // stack offset -24
	/* end block 1 */
	// End offset: 0x8003BF54
	// End Line: 1628

	/* begin block 2 */
		// Start line: 3020
	/* end block 2 */
	// End Line: 3021

/* File: C:\kain2\game\PIPE3D.C */

void PIPE3D_TransformFromZAxis(undefined transform,_SVector *normal)

{
  int iVar1;
  undefined3 in_register_00000011;
  _G2Matrix_Type *matrix;
  SVECTOR SStack40;
  _Normal local_20;
  _Normal local_18;
  
  matrix = (_G2Matrix_Type *)CONCAT31(in_register_00000011,transform);
  iVar1 = (int)normal->x;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if (iVar1 < 5) {
    iVar1 = (int)normal->y;
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    if (iVar1 < 5) {
      if (-1 < normal->z) {
        MATH3D_SetUnityMatrix(transform);
        return;
      }
      matrix->rotScale[0] = 0x1000;
      matrix->rotScale[1] = 0;
      matrix->rotScale[2] = 0;
      matrix->rotScale[3] = 0;
      matrix->rotScale[4] = -0x1000;
      matrix->rotScale[5] = 0;
      matrix->rotScale[6] = 0;
      matrix->rotScale[7] = 0;
      matrix->rotScale[8] = -0x1000;
      return;
    }
  }
  local_20.x = -normal->y;
  local_20.y = normal->x;
  local_20.z = 0;
  MATH3D_Normalize(&local_20);
  local_18.x = (short)((int)normal->y * (int)local_20.z - (int)normal->z * (int)local_20.y >> 0xc);
  local_18.y = -(short)((int)normal->x * (int)local_20.z - (int)normal->z * (int)local_20.x >> 0xc);
  local_18.z = (short)((int)normal->x * (int)local_20.y - (int)normal->y * (int)local_20.x >> 0xc);
  MATH3D_Normalize(&local_18);
  matrix->rotScale[0] = local_20.x;
  matrix->rotScale[1] = local_20.y;
  matrix->rotScale[2] = local_20.z;
  matrix->rotScale[3] = local_18.x;
  matrix->rotScale[4] = local_18.y;
  matrix->rotScale[5] = local_18.z;
  matrix->rotScale[6] = normal->x;
  matrix->rotScale[7] = normal->y;
  matrix->rotScale[8] = normal->z;
  G2EulerAngles_FromMatrix((_G2EulerAngles_Type *)&SStack40,matrix,0x15);
  RotMatrix(&SStack40,(MATRIX *)matrix);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PIPE3D_CalcWorldToSplitPlaneTransform(struct MATRIX *wpTransform /*$s1*/, struct _SVector *normal /*$a1*/, struct _SVector *translation /*$s0*/)
 // line 1632, offset 0x8003bf68
	/* begin block 1 */
		// Start line: 1633
		// Start offset: 0x8003BF68
		// Variables:
	// 		struct _SVector svector; // stack offset -40
	// 		struct _Vector vector; // stack offset -32
	/* end block 1 */
	// End offset: 0x8003BF68
	// End Line: 1633

	/* begin block 2 */
		// Start line: 3115
	/* end block 2 */
	// End Line: 3116

/* File: C:\kain2\game\PIPE3D.C */

void PIPE3D_CalcWorldToSplitPlaneTransform
               (undefined wpTransform,_SVector *normal,_SVector *translation)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 in_zero;
  undefined4 in_at;
  undefined3 in_register_00000011;
  undefined4 *puVar4;
  undefined4 local_28;
  uint local_24;
  
  puVar4 = (undefined4 *)CONCAT31(in_register_00000011,wpTransform);
  PIPE3D_TransformFromZAxis(wpTransform,normal);
  local_28 = CONCAT22(-translation->y,-translation->x);
  local_24 = local_24 & 0xffff0000 | (uint)(ushort)-translation->z;
  setCopControlWord(2,0,*puVar4);
  setCopControlWord(2,0x800,puVar4[1]);
  setCopControlWord(2,0x1000,puVar4[2]);
  setCopControlWord(2,0x1800,puVar4[3]);
  setCopControlWord(2,0x2000,puVar4[4]);
  setCopReg(2,in_zero,local_28);
  setCopReg(2,in_at,local_24);
  copFunction(2,0x486012);
  uVar1 = getCopReg(2,0x19);
  uVar2 = getCopReg(2,0x1a);
  uVar3 = getCopReg(2,0x1b);
  puVar4[5] = uVar1;
  puVar4[6] = uVar2;
  puVar4[7] = uVar3;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ PIPE3D_TransformAnimatedSplitInstanceVertices(struct _MVertex *vertexList /*stack 0*/, struct _PVertex *poolVertex /*$s4*/, struct _Model *model /*stack 8*/, struct MATRIX *wcTransform /*stack 12*/, struct MATRIX *matrixPool /*stack 16*/, struct _Mirror *mirror /*stack 20*/, struct MATRIX *lm /*stack 24*/, struct CVECTOR *vertexColor /*stack 28*/, struct CVECTOR *vertexSrcCol /*stack 32*/)
 // line 1671, offset 0x8003c03c
	/* begin block 1 */
		// Start line: 1672
		// Start offset: 0x8003C03C
		// Variables:
	// 		struct TransformAnimatedInstanceVerticesWork_t *w; // $s7
	// 		struct MATRIX *segMatrix; // $s2
	// 		long i; // stack offset -64
	// 		struct _Segment *segment; // stack offset -60
	// 		struct CVECTOR defaultRGBCD; // stack offset -80

		/* begin block 1.1 */
			// Start line: 1693
			// Start offset: 0x8003C0CC
		/* end block 1.1 */
		// End offset: 0x8003C0D0
		// End Line: 1695

		/* begin block 1.2 */
			// Start line: 1702
			// Start offset: 0x8003C108
			// Variables:
		// 		struct _MVertex *firstVertex; // stack offset -56
		// 		struct _MVertex *lastVertex; // $fp
		// 		struct _MVertex *modelVertex; // $a2
		// 		struct _Normal *n0; // $t1
		// 		struct _Normal *n1; // $t2
		// 		struct _Normal *n2; // $t3
		// 		struct CVECTOR white; // stack offset -72
		// 		struct CVECTOR *c0; // $s1
		// 		struct CVECTOR *c1; // $s6
		// 		struct CVECTOR *c2; // $s5
		// 		long vtxcolflgs; // stack offset -52
		/* end block 1.2 */
		// End offset: 0x8003C5A4
		// End Line: 1862
	/* end block 1 */
	// End offset: 0x8003C5CC
	// End Line: 1866

	/* begin block 2 */
		// Start line: 3328
	/* end block 2 */
	// End Line: 3329

/* File: C:\kain2\game\PIPE3D.C */

long PIPE3D_TransformAnimatedSplitInstanceVertices
               (_MVertex *vertexList,_PVertex *poolVertex,_Model *model,undefined wcTransform,
               undefined1 matrixPool,_Mirror *mirror,undefined1 lm,CVECTOR *vertexColor,
               CVECTOR *vertexSrcCol)

{
  ushort uVar1;
  undefined4 uVar2;
  CVECTOR CVar3;
  undefined4 in_zero;
  undefined4 in_at;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  long *plVar7;
  undefined3 in_register_0000001d;
  CVECTOR *pCVar8;
  _MVertex *p_Var9;
  CVECTOR *pCVar10;
  MATRIX *m1;
  CVECTOR *pCVar11;
  CVECTOR *pCVar12;
  _MVertex *p_Var13;
  CVECTOR local_48 [2];
  int local_40;
  _Segment *local_3c;
  _MVertex *local_38;
  uint local_34;
  undefined4 *local_30;
  
  local_3c = model->segmentList;
  if (vertexColor != (CVECTOR *)0x0) {
    setCopReg(2,model,DAT_800cfa74);
  }
  if (modelFadeValue == 0) {
    setCopReg(2,0x4000,0);
  }
  else {
    setCopReg(2,0x4000,modelFadeValue);
  }
  local_40 = 0;
  if (0 < model->numSegments) {
    local_30 = (undefined4 *)&DAT_1f800060;
    do {
      if ((int)local_3c->lastVertex != -1) {
        pCVar10 = local_48;
        local_34 = 0;
        p_Var13 = vertexList + (int)local_3c->lastVertex;
        local_48[0] = DAT_800cfa74;
        local_38 = vertexList + local_3c->firstVertex;
        m1 = (MATRIX *)(_matrixPool + local_40 * 0x20);
        if (vertexColor != (CVECTOR *)0x0) {
          MulMatrix0(_lm,m1,(MATRIX *)&DAT_1f800040);
          SetLightMatrix((MATRIX *)&DAT_1f800040);
        }
        CompMatrix((MATRIX *)CONCAT31(in_register_0000001d,wcTransform),m1,(MATRIX *)&DAT_1f800000);
        SetRotMatrix((MATRIX *)&DAT_1f800000);
        SetTransMatrix((MATRIX *)&DAT_1f800000);
        if (local_38 <= p_Var13 + -2) {
          p_Var9 = local_38 + 2;
          pCVar8 = vertexColor + 2;
          plVar7 = &poolVertex->otz;
          pCVar11 = pCVar10;
          pCVar12 = pCVar10;
          do {
            setCopReg(2,in_zero,*(undefined4 *)&local_38->vertex);
            setCopReg(2,in_at,*(undefined4 *)&(local_38->vertex).z);
            copFunction(2,0x480012);
            uVar4 = (uint)p_Var9[-2].normal;
            uVar6 = (uint)p_Var9[-1].normal;
            uVar5 = (uint)p_Var9->normal;
            uVar2 = getCopReg(2,0x19);
            *local_30 = uVar2;
            uVar2 = getCopReg(2,0x1a);
            local_30[1] = uVar2;
            uVar2 = getCopReg(2,0x1b);
            local_30[2] = uVar2;
            poolVertex->x = DAT_1f800060;
            *(undefined2 *)((int)plVar7 + -2) = DAT_1f800064;
            *(undefined2 *)plVar7 = DAT_1f800068;
            setCopReg(2,in_zero,*(undefined4 *)&local_38[1].vertex);
            setCopReg(2,in_at,*(undefined4 *)&local_38[1].vertex.z);
            copFunction(2,0x480012);
            uVar2 = getCopReg(2,0x19);
            *local_30 = uVar2;
            uVar2 = getCopReg(2,0x1a);
            local_30[1] = uVar2;
            uVar2 = getCopReg(2,0x1b);
            local_30[2] = uVar2;
            poolVertex[1].x = DAT_1f800060;
            *(undefined2 *)((int)plVar7 + 6) = DAT_1f800064;
            *(undefined2 *)(plVar7 + 2) = DAT_1f800068;
            setCopReg(2,in_zero,*(undefined4 *)&p_Var9->vertex);
            setCopReg(2,in_at,*(undefined4 *)&(p_Var9->vertex).z);
            copFunction(2,0x480012);
            uVar2 = getCopReg(2,0x19);
            *local_30 = uVar2;
            uVar2 = getCopReg(2,0x1a);
            local_30[1] = uVar2;
            uVar2 = getCopReg(2,0x1b);
            local_30[2] = uVar2;
            poolVertex[2].x = DAT_1f800060;
            *(undefined2 *)((int)plVar7 + 0xe) = DAT_1f800064;
            poolVertex = poolVertex + 3;
            *(undefined2 *)(plVar7 + 4) = DAT_1f800068;
            plVar7 = plVar7 + 6;
            if (vertexColor != (CVECTOR *)0x0) {
              if (vertexSrcCol != (CVECTOR *)0x0) {
                pCVar12 = vertexSrcCol + 1;
                pCVar11 = vertexSrcCol + 2;
                local_34 = (uint)*vertexSrcCol & (uint)vertexSrcCol[1] & (uint)vertexSrcCol[2];
                pCVar10 = vertexSrcCol;
                vertexSrcCol = vertexSrcCol + 3;
              }
              if ((local_34 & 0x40000000) == 0) {
                if (modelFadeValue == 0) {
                  setCopReg(2,in_zero,*(undefined4 *)(gNormalList + uVar4));
                  setCopReg(2,in_at,*(undefined4 *)&gNormalList[uVar4].z);
                  setCopReg(2,local_38,*pCVar10);
                  copFunction(2,0x108041b);
                  setCopReg(2,in_zero,*(undefined4 *)(gNormalList + uVar6));
                  setCopReg(2,in_at,*(undefined4 *)&gNormalList[uVar6].z);
                  setCopReg(2,local_38,*pCVar12);
                  copFunction(2,0x108041b);
                  setCopReg(2,in_zero,*(undefined4 *)(gNormalList + uVar5));
                  setCopReg(2,in_at,*(undefined4 *)&gNormalList[uVar5].z);
                  setCopReg(2,local_38,*pCVar11);
                  copFunction(2,0x108041b);
                }
                else {
                  setCopReg(2,in_zero,*(undefined4 *)(gNormalList + uVar4));
                  setCopReg(2,in_at,*(undefined4 *)&gNormalList[uVar4].z);
                  setCopReg(2,local_38,*pCVar10);
                  copFunction(2,0xe80413);
                  setCopReg(2,in_zero,*(undefined4 *)(gNormalList + uVar6));
                  setCopReg(2,in_at,*(undefined4 *)&gNormalList[uVar6].z);
                  setCopReg(2,local_38,*pCVar12);
                  copFunction(2,0xe80413);
                  setCopReg(2,in_zero,*(undefined4 *)(gNormalList + uVar5));
                  setCopReg(2,in_at,*(undefined4 *)&gNormalList[uVar5].z);
                  setCopReg(2,local_38,*pCVar11);
                  copFunction(2,0xe80413);
                }
                CVar3 = (CVECTOR)getCopReg(2,0x14);
                *vertexColor = CVar3;
                CVar3 = (CVECTOR)getCopReg(2,0x15);
                vertexColor[1] = CVar3;
                CVar3 = (CVECTOR)getCopReg(2,0x16);
                *pCVar8 = CVar3;
                if (((uint)*pCVar10 & 0x40000000) != 0) {
                  *vertexColor = *pCVar10;
                }
                if (((uint)*pCVar12 & 0x40000000) != 0) {
                  pCVar8[-1] = *pCVar12;
                }
                if (((uint)*pCVar11 & 0x40000000) != 0) {
                  *pCVar8 = *pCVar11;
                }
              }
              else {
                *vertexColor = *pCVar10;
                pCVar8[-1] = *pCVar12;
                *pCVar8 = *pCVar11;
              }
              pCVar8 = pCVar8 + 3;
              vertexColor = vertexColor + 3;
            }
            local_38 = local_38 + 3;
            p_Var9 = p_Var9 + 3;
          } while (local_38 <= p_Var13 + -2);
        }
        if (local_38 <= p_Var13) {
          plVar7 = &poolVertex->otz;
          do {
            setCopReg(2,in_zero,*(undefined4 *)&local_38->vertex);
            setCopReg(2,in_at,*(undefined4 *)&(local_38->vertex).z);
            copFunction(2,0x480012);
            uVar1 = local_38->normal;
            uVar2 = getCopReg(2,0x19);
            *local_30 = uVar2;
            uVar2 = getCopReg(2,0x1a);
            local_30[1] = uVar2;
            uVar2 = getCopReg(2,0x1b);
            local_30[2] = uVar2;
            poolVertex->x = DAT_1f800060;
            *(undefined2 *)((int)plVar7 + -2) = DAT_1f800064;
            poolVertex = poolVertex + 1;
            *(undefined2 *)plVar7 = DAT_1f800068;
            plVar7 = plVar7 + 2;
            if (vertexColor != (CVECTOR *)0x0) {
              if (vertexSrcCol != (CVECTOR *)0x0) {
                pCVar10 = vertexSrcCol;
                vertexSrcCol = vertexSrcCol + 1;
              }
              if (((uint)*pCVar10 & 0x40000000) == 0) {
                setCopReg(2,local_38,*pCVar10);
                setCopReg(2,in_zero,*(undefined4 *)(gNormalList + uVar1));
                setCopReg(2,in_at,*(undefined4 *)&gNormalList[uVar1].z);
                copFunction(2,0xe80413);
                CVar3 = (CVECTOR)getCopReg(2,0x16);
                *vertexColor = CVar3;
              }
              else {
                *vertexColor = *pCVar10;
              }
              vertexColor = vertexColor + 1;
            }
            local_38 = local_38 + 1;
          } while (local_38 <= p_Var13);
        }
      }
      local_3c = local_3c + 1;
      local_40 = local_40 + 1;
    } while (local_40 < model->numSegments);
  }
  modelDQP = getCopReg(2,8);
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PIPE3D_TransformSplitInstanceVertices(struct _MVertex *vertexList /*stack 0*/, struct _PVertex *pvertex /*$s2*/, struct _Model *model /*stack 8*/, struct MATRIX *wpTransform /*stack 12*/, struct MATRIX *matrixPool /*stack 16*/, struct _Mirror *mirror /*stack 20*/)
 // line 1874, offset 0x8003c60c
	/* begin block 1 */
		// Start line: 1875
		// Start offset: 0x8003C60C
		// Variables:
	// 		struct MATRIX *spTransform; // $fp
	// 		struct _Vector *vector; // $s1
	// 		long i; // $s5
	// 		struct _Segment *segment; // $v1

		/* begin block 1.1 */
			// Start line: 1887
			// Start offset: 0x8003C694
			// Variables:
		// 		struct _MVertex *firstVertex; // $s0
		// 		struct _MVertex *lastVertex; // $s4
		// 		struct _MVertex *modelVertex; // $s0
		/* end block 1.1 */
		// End offset: 0x8003C72C
		// End Line: 1905
	/* end block 1 */
	// End offset: 0x8003C750
	// End Line: 1908

	/* begin block 2 */
		// Start line: 4095
	/* end block 2 */
	// End Line: 4096

/* File: C:\kain2\game\PIPE3D.C */

void PIPE3D_TransformSplitInstanceVertices
               (_MVertex *vertexList,_PVertex *pvertex,_Model *model,undefined wpTransform,
               undefined1 matrixPool,_Mirror *mirror)

{
  short sVar1;
  undefined4 in_zero;
  undefined4 in_at;
  long *plVar2;
  undefined3 in_register_0000001d;
  _MVertex *p_Var3;
  short *psVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  if (0 < model->numSegments) {
    iVar6 = 0;
    psVar4 = &model->segmentList->lastVertex;
    do {
      if (*(short *)((int)&model->segmentList->lastVertex + iVar6) != -1) {
        sVar1 = *psVar4;
        p_Var3 = vertexList + psVar4[-1];
        CompMatrix((MATRIX *)CONCAT31(in_register_0000001d,wpTransform),_matrixPool,
                   (MATRIX *)&DAT_1f800000);
        SetRotMatrix((MATRIX *)&DAT_1f800000);
        SetTransMatrix((MATRIX *)&DAT_1f800000);
        if (p_Var3 <= vertexList + sVar1) {
          plVar2 = &pvertex->otz;
          do {
            setCopReg(2,in_zero,*(undefined4 *)&p_Var3->vertex);
            setCopReg(2,in_at,*(undefined4 *)&(p_Var3->vertex).z);
            copFunction(2,0x480012);
            DAT_1f800020 = getCopReg(2,0x19);
            DAT_1f800024 = getCopReg(2,0x1a);
            DAT_1f800028 = getCopReg(2,0x1b);
            pvertex->x = (short)DAT_1f800020;
            p_Var3 = p_Var3 + 1;
            *(undefined2 *)((int)plVar2 + -2) = (undefined2)DAT_1f800024;
            pvertex = pvertex + 1;
            *(undefined2 *)plVar2 = (undefined2)DAT_1f800028;
            plVar2 = plVar2 + 2;
          } while (p_Var3 <= vertexList + sVar1);
        }
      }
      psVar4 = psVar4 + 0xc;
      _matrixPool = _matrixPool + 1;
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 0x18;
    } while (iVar5 < model->numSegments);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PIPE3D_AnimateTextures(struct AniTex *aniTextures /*$t1*/, long req_frame /*$a1*/)
 // line 1910, offset 0x8003c780
	/* begin block 1 */
		// Start line: 1911
		// Start offset: 0x8003C780
		// Variables:
	// 		struct AniTexInfo *ani_tex_info; // $t0
	// 		struct TextureMT3 *dest; // $a0
	// 		struct TextureMT3 *src; // $v1
	// 		long i; // $a3
	/* end block 1 */
	// End offset: 0x8003C818
	// End Line: 1930

	/* begin block 2 */
		// Start line: 4227
	/* end block 2 */
	// End Line: 4228

/* File: C:\kain2\game\PIPE3D.C */

void PIPE3D_AnimateTextures(AniTex *aniTextures,long req_frame)

{
  TextureMT3 *pTVar1;
  TextureMT3 *pTVar2;
  uint *puVar3;
  int iVar4;
  AniTexInfo *pAVar5;
  
  if (((aniTextures != (AniTex *)0x0) && (pAVar5 = &aniTextures->aniTexInfo, req_frame != -1)) &&
     (iVar4 = 0, 0 < aniTextures->numAniTextues)) {
    puVar3 = (uint *)&(aniTextures->aniTexInfo).numFrames;
    do {
      pTVar2 = pAVar5->texture;
      pTVar1 = pTVar2 + ((uint)req_frame / puVar3[1]) % *puVar3;
      *(undefined4 *)pTVar2 = *(undefined4 *)(pTVar1 + 1);
      *(undefined4 *)&pTVar2->u1 = *(undefined4 *)&pTVar1[1].u1;
      pAVar5 = pAVar5 + 1;
      *(undefined4 *)&pTVar2->u2 = *(undefined4 *)&pTVar1[1].u2;
      iVar4 = iVar4 + 1;
      pTVar2->color = pTVar1[1].color;
      puVar3 = puVar3 + 3;
    } while (iVar4 < aniTextures->numAniTextues);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PIPE3D_AnimateTerrainTextures(struct DrMoveAniTex *aniTextures /*$a0*/, long req_frame /*$a1*/, struct _PrimPool *primPool /*$a2*/, unsigned long **drawot /*$a3*/)
 // line 2003, offset 0x8003c820
	/* begin block 1 */
		// Start line: 2005
		// Start offset: 0x8003C820
		// Variables:
	// 		unsigned long *prim; // $t3
	// 		struct DrMoveAniTexDestInfo *dest; // $t1
	// 		struct DrMoveAniTexSrcInfo *src; // $t2
	// 		long i; // $t5
	// 		unsigned long **otl; // $a3
	/* end block 1 */
	// End offset: 0x8003C9B0
	// End Line: 2059

	/* begin block 2 */
		// Start line: 4431
	/* end block 2 */
	// End Line: 4432

	/* begin block 3 */
		// Start line: 4432
	/* end block 3 */
	// End Line: 4433

/* File: C:\kain2\game\PIPE3D.C */

void PIPE3D_AnimateTerrainTextures
               (DrMoveAniTex *aniTextures,long req_frame,_PrimPool *primPool,ulong **drawot)

{
  uint *puVar1;
  DrMoveAniTexDestInfo *pDVar2;
  DrMoveAniTexSrcInfo *pDVar3;
  uint *puVar4;
  int iVar5;
  DrMoveAniTex *pDVar6;
  
  puVar4 = primPool->nextPrim;
  drawot = drawot + 0xbff;
  if (aniTextures != (DrMoveAniTex *)0x0) {
    if ((puVar4 < primPool->lastPrim + aniTextures->numAniTextues * 0x3fffffe8) &&
       (iVar5 = 0, 0 < aniTextures->numAniTextues)) {
      puVar1 = puVar4 + 5;
      pDVar6 = aniTextures;
      do {
        pDVar2 = pDVar6->aniTexInfo;
        pDVar3 = &pDVar2->frame + ((uint)req_frame / (uint)pDVar2->speed) % pDVar2->numFrames;
        if (*(uint *)pDVar3 != *(uint *)&pDVar2->pixCurrentX) {
          puVar1[-4] = 0x1000000;
          puVar1[-3] = 0x80000000;
          puVar1[-2] = *(uint *)pDVar3;
          puVar1[-1] = *(uint *)pDVar2;
          *puVar1 = *(uint *)&pDVar2->pixW;
          *puVar4 = (uint)*drawot & 0xffffff | 0x5000000;
          *drawot = (ulong *)((uint)puVar4 & 0xffffff);
          puVar1 = puVar1 + 6;
          *(uint *)&pDVar2->pixCurrentX = *(uint *)pDVar3;
          puVar4 = puVar4 + 6;
          primPool->numPrims = primPool->numPrims + 1;
        }
        if (*(int *)&pDVar3->clutSrcX != *(int *)&pDVar2->clutCurrentX) {
          puVar1[-4] = 0x1000000;
          puVar1[-3] = 0x80000000;
          puVar1[-2] = *(uint *)&pDVar3->clutSrcX;
          puVar1[-1] = *(uint *)&pDVar2->clutDstX;
          *puVar1 = *(uint *)&pDVar2->clutW;
          *puVar4 = (uint)*drawot & 0xffffff | 0x5000000;
          *drawot = (ulong *)((uint)puVar4 & 0xffffff);
          puVar1 = puVar1 + 6;
          *(undefined4 *)&pDVar2->clutCurrentX = *(undefined4 *)&pDVar3->clutSrcX;
          puVar4 = puVar4 + 6;
          primPool->numPrims = primPool->numPrims + 1;
        }
        iVar5 = iVar5 + 1;
        pDVar6 = (DrMoveAniTex *)&pDVar6->aniTexInfo;
      } while (iVar5 < aniTextures->numAniTextues);
    }
    primPool->nextPrim = puVar4;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PIPE3D_HalvePlaneInstanceTransformAndDraw(struct _Instance *instance /*$s2*/, struct MATRIX *wcTransform /*$s1*/, struct _VertexPool *vertexPool /*$s6*/, struct _PrimPool *primPool /*$s5*/, unsigned long **ot /*stack 16*/, struct _Mirror *mirror /*stack 20*/)
 // line 2086, offset 0x8003c9b8
	/* begin block 1 */
		// Start line: 2087
		// Start offset: 0x8003C9B8
		// Variables:
	// 		struct Object *object; // $v1
	// 		struct _Model *model; // $s3
	// 		struct MATRIX *matrixPool; // $s4
	// 		struct MATRIX wpTransform; // stack offset -184
	// 		struct MATRIX pwTransform; // stack offset -152
	// 		struct MATRIX pcTransform; // stack offset -120
	// 		struct MATRIX lm; // stack offset -88
	// 		struct _MVertex *vertexList; // $s7
	// 		struct _SVector normalX; // stack offset -56
	// 		struct _SVector *normal; // $a1
	// 		struct _SVector translation; // stack offset -48
	/* end block 1 */
	// End offset: 0x8003CB80
	// End Line: 2155

	/* begin block 2 */
		// Start line: 4642
	/* end block 2 */
	// End Line: 4643

/* File: C:\kain2\game\PIPE3D.C */

void PIPE3D_HalvePlaneInstanceTransformAndDraw
               (_Instance *instance,undefined wcTransform,_VertexPool *vertexPool,
               _PrimPool *primPool,ulong **ot,_Mirror *mirror)

{
  ulong *puVar1;
  undefined3 in_register_00000015;
  _Model *model;
  MATRIX *pMVar2;
  _MVertex *vertexList;
  MATRIX MStack152;
  MATRIX aMStack120 [2];
  _SVector local_38;
  _SVector local_30;
  
  pMVar2 = instance->matrix;
  model = instance->object->modelList[instance->currentModel];
  local_38.x = (instance->halvePlane).a;
  vertexList = model->vertexList;
  local_38.y = (instance->halvePlane).b;
  local_38.z = (instance->halvePlane).c;
  local_30.x = -(short)((int)local_38.x * (instance->halvePlane).d >> 0xc);
  local_30.y = -(short)((int)local_38.y * (instance->halvePlane).d >> 0xc);
  local_30.z = -(short)((int)local_38.z * (instance->halvePlane).d >> 0xc);
  PIPE3D_CalcWorldToSplitPlaneTransform(0x48,&local_38,&local_30);
  PIPE3D_InvertTransform((char)&MStack152,0x48);
  CompMatrix((MATRIX *)CONCAT31(in_register_00000015,wcTransform),&MStack152,aMStack120);
  if (pMVar2 != (MATRIX *)0x0) {
    LIGHT_PresetInstanceLight(instance,0x800,0xa8);
    modelFadeValue = INSTANCE_GetFadeValue(instance);
    PIPE3D_TransformAnimatedSplitInstanceVertices
              (vertexList,(_PVertex *)vertexPool,model,0x48,(char)pMVar2,mirror,0xa8,
               vertexPool->color,instance->perVertexColor);
    if (primPool->nextPrim + model->numFaces * 0xc < primPool->lastPrim) {
      draw_belowSplit = ZEXT14(((instance->halvePlane).flags & 2U) != 0);
      puVar1 = (ulong *)DRAW_SplitModel_S((int)model,instance,(int)vertexPool,
                                          (undefined4 *)aMStack120,(int)primPool);
      primPool->nextPrim = puVar1;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PIPE3D_HalvePlaneGetRingPoints(struct _Instance *instance /*$a0*/, struct MATRIX *wcTransform /*$fp*/, struct _VertexPool *vertexPool /*$s6*/, struct _PrimPool *primPool /*$s7*/, unsigned long **ot /*stack 16*/, struct _FXHalvePlane *ring /*stack 20*/)
 // line 2203, offset 0x8003cbac
	/* begin block 1 */
		// Start line: 2204
		// Start offset: 0x8003CBAC
		// Variables:
	// 		struct Object *object; // $v1
	// 		struct _Model *model; // $s1
	// 		struct MATRIX *matrixPool; // $s3
	// 		struct MATRIX wpTransform; // stack offset -152
	// 		struct MATRIX pwTransform; // stack offset -120
	// 		struct MATRIX pcTransform; // stack offset -88
	// 		struct _MVertex *vertexList; // $s4
	// 		struct _PVertex *poolVertex; // $s5
	// 		struct _SVector normalX; // stack offset -56
	// 		struct _SVector *normal; // $a1
	// 		struct _SVector translation; // stack offset -48
	// 		struct _PlaneConstants *halvePlane; // $a0
	/* end block 1 */
	// End offset: 0x8003CD4C
	// End Line: 2261

	/* begin block 2 */
		// Start line: 4395
	/* end block 2 */
	// End Line: 4396

/* File: C:\kain2\game\PIPE3D.C */

void PIPE3D_HalvePlaneGetRingPoints
               (_Instance *instance,undefined wcTransform,_VertexPool *vertexPool,
               _PrimPool *primPool,ulong **ot,_FXHalvePlane *ring)

{
  ulong *puVar1;
  _PlaneConstants *p_Var2;
  undefined3 in_register_00000015;
  _Model *model;
  MATRIX *pMVar3;
  _MVertex *vertexList;
  MATRIX MStack120;
  MATRIX MStack88;
  _SVector local_38;
  _SVector local_30;
  
  pMVar3 = instance->matrix;
  model = instance->object->modelList[instance->currentModel];
  vertexList = model->vertexList;
  if (ring->type == '\0') {
    p_Var2 = &ring->ringPlane;
  }
  else {
    p_Var2 = &instance->halvePlane;
  }
  local_38.x = p_Var2->a;
  local_38.y = p_Var2->b;
  local_38.z = p_Var2->c;
  local_30.x = -(short)((int)local_38.x * p_Var2->d >> 0xc);
  local_30.y = -(short)((int)local_38.y * p_Var2->d >> 0xc);
  local_30.z = -(short)((int)local_38.z * p_Var2->d >> 0xc);
  PIPE3D_CalcWorldToSplitPlaneTransform(0x68,&local_38,&local_30);
  PIPE3D_InvertTransform((char)&MStack120,0x68);
  if (ring->type == '\x02') {
    PIPE3D_InvertTransform(0xa8,0x68);
  }
  else {
    CompMatrix((MATRIX *)CONCAT31(in_register_00000015,wcTransform),&MStack120,&MStack88);
  }
  if (pMVar3 != (MATRIX *)0x0) {
    PIPE3D_TransformSplitInstanceVertices
              (vertexList,(_PVertex *)vertexPool,model,0x68,(char)pMVar3,(_Mirror *)0x0);
    draw_belowSplit = 0;
    puVar1 = DRAW_DrawRingPoints(model,vertexPool,0xa8,primPool,ot,ring->currentColor,
                                 (uint)ring->type);
    primPool->nextPrim = puVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PIPE3D_DoGlow(struct _Instance *instance /*$s2*/, struct MATRIX *wcTransform /*$a1*/, struct _VertexPool *vertexPool /*$a2*/, struct _PrimPool *primPool /*$s3*/, unsigned long **ot /*stack 16*/, struct _FXGlowEffect *glow /*stack 20*/)
 // line 2277, offset 0x8003cd7c
	/* begin block 1 */
		// Start line: 2278
		// Start offset: 0x8003CD7C
		// Variables:
	// 		long currentColorID; // $a2
	// 		long previousColorID; // $a1
	// 		long value; // $a0
	// 		long fade; // $a3
	// 		long fadeflag; // $s0

		/* begin block 1.1 */
			// Start line: 2308
			// Start offset: 0x8003CF64
			// Variables:
		// 		long color; // stack offset -32

			/* begin block 1.1.1 */
				// Start line: 2353
				// Start offset: 0x8003D0DC
				// Variables:
			// 		long i; // $s0
			/* end block 1.1.1 */
			// End offset: 0x8003D138
			// End Line: 2363
		/* end block 1.1 */
		// End offset: 0x8003D138
		// End Line: 2364
	/* end block 1 */
	// End offset: 0x8003D138
	// End Line: 2365

	/* begin block 2 */
		// Start line: 4542
	/* end block 2 */
	// End Line: 4543

/* File: C:\kain2\game\PIPE3D.C */

void PIPE3D_DoGlow(_Instance *instance,undefined1 wcTransform,_VertexPool *vertexPool,
                  _PrimPool *primPool,ulong **ot,_FXGlowEffect *glow)

{
  bool bVar1;
  long *plVar2;
  int iVar3;
  ulong *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int seg1;
  uint uVar11;
  uint local_20;
  
  uVar7 = 0;
  if ((instance->flags & 0x200U) != 0) {
    uVar6 = SEXT24(glow->numColors);
    uVar5 = (glow->diffTime + DAT_800d2310) % 32000;
    glow->diffTime = uVar5;
    if (1 < (int)uVar6) {
      uVar5 = uVar5 % ((int)glow->colorBlendCycle * uVar6);
      uVar11 = (uVar5 / (uint)(int)glow->colorBlendCycle) % uVar6;
      glow->diffTime = uVar5;
      uVar5 = uVar11;
      if (uVar11 == 0) {
        uVar5 = uVar6;
      }
      uVar6 = (glow->diffTime % ((int)glow->colorBlendCycle + 1U) << 0xc) /
              (uint)(int)glow->colorBlendCycle;
      if (0xfff < (int)uVar6) {
        uVar6 = 0;
      }
      setCopReg(2,0x4000,0x1000 - uVar6);
      plVar2 = glow->colorArray + (uVar5 - 1);
      setCopReg(2,0x4800,(uint)*(byte *)plVar2);
      setCopReg(2,0x5000,(uint)*(byte *)((int)plVar2 + 1));
      setCopReg(2,0x5800,(uint)*(byte *)((int)plVar2 + 2));
      copFunction(2,0x198003d);
      setCopReg(2,0x4000,uVar6);
      plVar2 = glow->colorArray + uVar11;
      setCopReg(2,0x4800,(uint)*(byte *)plVar2);
      setCopReg(2,0x5000,(uint)*(byte *)((int)plVar2 + 1));
      setCopReg(2,0x5800,(uint)*(byte *)((int)plVar2 + 2));
      copFunction(2,0x1a8003e);
      uVar8 = getCopReg(2,0x4800);
      uVar9 = getCopReg(2,0x5000);
      uVar10 = getCopReg(2,0x5800);
      *(char *)&glow->currentColor = (char)uVar8;
      *(undefined *)((int)&glow->currentColor + 1) = (char)uVar9;
      *(undefined *)((int)&glow->currentColor + 2) = (char)uVar10;
      uVar6 = glow->currentColor & 0xffffff;
      glow->currentColor = uVar6;
      glow->currentColor = uVar6 | glow->colorArray[uVar5 - 1] & 0xff000000U;
    }
    if ((instance->matrix != (MATRIX *)0x0) && (instance->oldMatrix != (MATRIX *)0x0)) {
      bVar1 = false;
      if (((int)instance->fadeValue == 0) && (DAT_800d20d4 == 1000)) {
        iVar3 = (int)glow->lifeTime;
        if (-1 < iVar3) {
          if (glow->diffTime < (uint)(int)glow->fadein_time) {
            uVar7 = (glow->diffTime << 0xc) / (uint)(int)glow->fadein_time;
            bVar1 = true;
          }
          else {
            if (iVar3 < (int)glow->fadeout_time) {
              bVar1 = true;
              uVar7 = (iVar3 << 0xc) / (int)glow->fadeout_time;
            }
          }
        }
      }
      else {
        bVar1 = true;
        if (DAT_800d20d4 == 1000) {
          uVar7 = 0x1000 - (int)instance->fadeValue;
        }
        else {
          iVar3 = INSTANCE_GetFadeValue(instance);
          uVar7 = 0x1000 - iVar3;
        }
      }
      if (bVar1) {
        setCopReg(2,0x4000,uVar7);
        setCopReg(2,0x4800,(uint)*(byte *)&glow->currentColor);
        setCopReg(2,0x5000,(uint)*(byte *)((int)&glow->currentColor + 1));
        setCopReg(2,0x5800,(uint)*(byte *)((int)&glow->currentColor + 2));
        copFunction(2,0x198003d);
        uVar8 = getCopReg(2,0x4800);
        uVar9 = getCopReg(2,0x5000);
        uVar10 = getCopReg(2,0x5800);
        local_20 = (uint)CONCAT12((char)uVar10,CONCAT11((char)uVar9,(char)uVar8));
        if ((glow->currentColor & 0x1000000U) != 0) {
          local_20 = local_20 | 0x1000000;
        }
      }
      else {
        local_20 = glow->currentColor;
      }
      if (glow->numSegments == '\x01') {
        puVar4 = DRAW_DrawGlowPoint(instance,(int)glow->segment,primPool,ot,local_20,
                                    (int)glow->width,(int)glow->height);
        primPool->nextPrim = puVar4;
      }
      else {
        seg1 = (int)glow->segment;
        iVar3 = seg1 + (uint)glow->numSegments;
        while (seg1 < iVar3 + -1) {
          puVar4 = DRAW_DrawGlowPoints2
                             (instance,seg1,seg1 + (uint)glow->SegmentInc,primPool,ot,local_20,
                              (int)glow->height);
          primPool->nextPrim = puVar4;
          seg1 = seg1 + 1;
          iVar3 = (int)glow->segment + (uint)glow->numSegments;
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ PIPE3D_Segment2ScreenPt(struct _Instance *instance /*$a0*/, struct MATRIX *wcTransform /*$a1*/, int segIndex /*$a2*/, struct _Position *pos /*$s0*/)
 // line 2371, offset 0x8003d158
	/* begin block 1 */
		// Start line: 2372
		// Start offset: 0x8003D158
		// Variables:
	// 		struct MATRIX scTransform; // stack offset -56
	// 		struct _Position vOrigin; // stack offset -24
	// 		long face_z; // stack offset -16
	/* end block 1 */
	// End offset: 0x8003D158
	// End Line: 2372

	/* begin block 2 */
		// Start line: 5248
	/* end block 2 */
	// End Line: 5249

/* WARNING: Could not reconcile some variable overlaps */
/* File: C:\kain2\game\PIPE3D.C */

long PIPE3D_Segment2ScreenPt(_Instance *instance,undefined wcTransform,int segIndex,_Position *pos)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 in_zero;
  undefined4 in_at;
  undefined3 in_register_00000015;
  MATRIX MStack56;
  undefined4 local_14;
  
  CompMatrix((MATRIX *)CONCAT31(in_register_00000015,wcTransform),instance->matrix + segIndex,
             &MStack56);
  SetRotMatrix(&MStack56);
  SetTransMatrix(&MStack56);
  local_14 = (uint)local_14._2_2_ << 0x10;
  setCopReg(2,in_zero,0);
  setCopReg(2,in_at,local_14);
  copFunction(2,0x180001);
  uVar1 = getCopReg(2,0xe);
  *(undefined4 *)pos = uVar1;
  iVar2 = getCopReg(2,0x13);
  return (iVar2 >> 2) + -0x14;
}





