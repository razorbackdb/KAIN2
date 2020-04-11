
#include "INSTNCG2.H"


// decompiled code
// original method signature: 
// void /*$ra*/ G2Instance_BuildTransformsForList(struct _Instance *listHead /*$s2*/)
 // line 71, offset 0x800947a8
	/* begin block 1 */
		// Start line: 72
		// Start offset: 0x800947A8
		// Variables:
	// 		struct _Instance *instance; // $s0
	/* end block 1 */
	// End offset: 0x80094954
	// End Line: 155

	/* begin block 2 */
		// Start line: 142
	/* end block 2 */
	// End Line: 143

/* File: C:\kain2\game\G2\INSTNCG2.C */

void G2Instance_BuildTransformsForList(_Instance *listHead)

{
  _Instance **pp_Var1;
  _G2Bool_Enum _Var2;
  Object *pOVar3;
  _Instance *instance;
  
  instance = listHead;
  if (listHead != (_Instance *)0x0) {
    do {
      if (instance->LinkParent == (_Instance *)0x0) {
        if ((instance->flags2 & 1U) == 0) {
          if ((((((instance->flags & 0x100000U) == 0) ||
                (*(int *)&instance->oldPos != *(int *)&instance->position)) ||
               ((instance->oldPos).z != (instance->position).z)) ||
              ((*(int *)&instance->oldRotation != *(int *)&instance->rotation ||
               ((instance->oldRotation).z != (instance->rotation).z)))) ||
             (instance->oldMatrix == (MATRIX *)0x0)) {
            pOVar3 = instance->object;
          }
          else {
            pOVar3 = instance->object;
            if (((pOVar3->animList == (_G2AnimKeylist_Type **)0x0) ||
                ((pOVar3->oflags2 & 0x40000000U) != 0)) || (((instance->anim).flags & 1) == 0))
            goto LAB_800948a4;
          }
          if ((pOVar3->animList == (_G2AnimKeylist_Type **)0x0) ||
             ((pOVar3->oflags2 & 0x40000000U) != 0)) {
            _G2Instance_BuildNonAnimatedTransforms(instance);
          }
          else {
            _G2Instance_BuildAnimatedTransforms(instance);
          }
        }
        else {
LAB_800948a4:
          _G2Instance_BuildDeactivatedTransforms(instance);
        }
      }
      pp_Var1 = &instance->next;
      instance = *pp_Var1;
    } while (*pp_Var1 != (_Instance *)0x0);
  }
  if (listHead != (_Instance *)0x0) {
    do {
      if ((listHead->rebuildCallback != (_func_6 *)0x0) &&
         (_Var2 = (*listHead->rebuildCallback)(listHead), _Var2 != G2FALSE)) {
        G2Anim_UpdateStoredFrame(&listHead->anim);
        G2Instance_RebuildTransforms(listHead);
      }
      listHead = listHead->next;
    } while (listHead != (_Instance *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Instance_BuildTransforms(struct _Instance *instance /*$a0*/)
 // line 159, offset 0x8009496c
	/* begin block 1 */
		// Start line: 391
	/* end block 1 */
	// End Line: 392

/* File: C:\kain2\game\G2\INSTNCG2.C */

void G2Instance_BuildTransforms(_Instance *instance)

{
  if ((instance->object->animList == (_G2AnimKeylist_Type **)0x0) ||
     ((instance->object->oflags2 & 0x40000000U) != 0)) {
    _G2Instance_BuildNonAnimatedTransforms(instance);
  }
  else {
    _G2Instance_BuildAnimatedTransforms(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Instance_RebuildTransforms(struct _Instance *instance /*$a0*/)
 // line 173, offset 0x800949c8
	/* begin block 1 */
		// Start line: 419
	/* end block 1 */
	// End Line: 420

/* File: C:\kain2\game\G2\INSTNCG2.C */

void G2Instance_RebuildTransforms(_Instance *instance)

{
  if ((instance->object->animList == (_G2AnimKeylist_Type **)0x0) ||
     ((instance->object->oflags2 & 0x40000000U) != 0)) {
    _G2Instance_RebuildNonAnimatedTransforms(instance);
  }
  else {
    _G2Instance_RebuildAnimatedTransforms(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// struct _G2AnimKeylist_Type * /*$ra*/ G2Instance_GetKeylist(struct _Instance *instance /*$a0*/, int id /*$a1*/)
 // line 188, offset 0x80094a24
	/* begin block 1 */
		// Start line: 449
	/* end block 1 */
	// End Line: 450

	/* begin block 2 */
		// Start line: 450
	/* end block 2 */
	// End Line: 451

/* File: C:\kain2\game\G2\INSTNCG2.C */

_G2AnimKeylist_Type * G2Instance_GetKeylist(_Instance *instance,int id)

{
  return instance->object->animList[id];
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Instance_RebuildAnimatedTransforms(struct _Instance *instance /*$s3*/)
 // line 200, offset 0x80094a44
	/* begin block 1 */
		// Start line: 201
		// Start offset: 0x80094A44
		// Variables:
	// 		struct _Model *model; // $s7
	// 		struct _G2Matrix_Type *rootMatrix; // $s4
	// 		struct _Rotation pre_facade_rot; // stack offset -120
	// 		struct _G2Matrix_Type *segMatrix; // $a2
	// 		struct _G2Matrix_Type seg1RotMatrix; // stack offset -112
	// 		struct _G2Matrix_Type seg2RotMatrix; // stack offset -80
	// 		struct _G2SVector3_Type rotVector; // stack offset -48
	// 		long otx; // $s6
	// 		long oty; // $s5
	// 		long otz; // $s2
	// 		long segIndex; // $s1

		/* begin block 1.1 */
			// Start line: 224
			// Start offset: 0x80094AA8
		/* end block 1.1 */
		// End offset: 0x80094AF4
		// End Line: 233

		/* begin block 1.2 */
			// Start line: 287
			// Start offset: 0x80094CA4
			// Variables:
		// 		struct VECTOR *ins_scale; // $v1
		/* end block 1.2 */
		// End offset: 0x80094CD8
		// End Line: 295
	/* end block 1 */
	// End offset: 0x80094E4C
	// End Line: 350

	/* begin block 2 */
		// Start line: 473
	/* end block 2 */
	// End Line: 474

/* File: C:\kain2\game\G2\INSTNCG2.C */

void _G2Instance_RebuildAnimatedTransforms(_Instance *instance)

{
  short sVar1;
  short sVar2;
  int iVar3;
  MultiSpline *pMVar4;
  _G2Bool_Enum _Var5;
  int iVar6;
  MATRIX *pMVar7;
  int iVar8;
  Object *pOVar9;
  MATRIX *pMVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  MATRIX *m;
  undefined4 uVar14;
  long lVar15;
  undefined4 uVar16;
  long lVar17;
  undefined4 uVar18;
  long lVar19;
  int *piVar20;
  _G2Anim_Type *anim;
  int segNumber;
  _Instance *instance_00;
  MATRIX *pMVar21;
  _Model *p_Var22;
  undefined4 local_78;
  undefined4 local_74;
  MATRIX MStack112;
  MATRIX MStack80;
  SVECTOR SStack48;
  
  pMVar21 = instance->matrix;
  if (pMVar21 != (MATRIX *)0x0) {
    p_Var22 = instance->object->modelList[instance->currentModel];
    m = pMVar21 + -1;
    if ((instance->object->oflags & 4U) != 0) {
      iVar6 = (int)theCamera;
      sVar2 = (instance->position).x;
      iVar3 = (int)DAT_800d0f9e;
      sVar1 = (instance->position).y;
      local_78 = *(undefined4 *)&instance->rotation;
      local_74 = *(undefined4 *)&(instance->rotation).z;
      (instance->rotation).x = 0;
      (instance->rotation).y = 0;
      sVar2 = MATH3D_FastAtan2(iVar3 - sVar1,iVar6 - sVar2);
      (instance->rotation).z = sVar2 + 0xc00;
    }
    if (((instance->flags & 1U) == 0) || (instance->intro == (Intro *)0x0)) {
      anim = &instance->anim;
      if (instance->LinkParent == (_Instance *)0x0) {
        RotMatrix((SVECTOR *)&instance->rotation,m);
      }
      else {
        G2Anim_UpdateStoredFrame(anim);
        G2Anim_GetSegChannelValue(anim,1,(ushort *)&SStack48,7);
        RotMatrixZYX(&SStack48,&MStack112);
        G2Anim_GetSegChannelValue(anim,2,(ushort *)&SStack48,7);
        RotMatrixZYX(&SStack48,&MStack80);
        MulMatrix2(&MStack112,&MStack80);
        TransposeMatrix(&MStack80,m);
        pMVar10 = instance->matrix;
        pMVar7 = instance->LinkParent->matrix + instance->ParentLinkNode;
        uVar14 = *(undefined4 *)(pMVar7->m + 2);
        uVar16 = *(undefined4 *)(pMVar7->m + 4);
        uVar18 = *(undefined4 *)(pMVar7->m + 6);
        *(undefined4 *)pMVar10->m = *(undefined4 *)pMVar7->m;
        *(undefined4 *)(pMVar10->m + 2) = uVar14;
        *(undefined4 *)(pMVar10->m + 4) = uVar16;
        *(undefined4 *)(pMVar10->m + 6) = uVar18;
        lVar15 = pMVar7->t[0];
        lVar17 = pMVar7->t[1];
        lVar19 = pMVar7->t[2];
        *(undefined4 *)(pMVar10->m + 8) = *(undefined4 *)(pMVar7->m + 8);
        pMVar10->t[0] = lVar15;
        pMVar10->t[1] = lVar17;
        pMVar10->t[2] = lVar19;
        MulMatrix2(instance->matrix,m);
        pMVar7 = instance->matrix;
        (instance->position).x = *(short *)instance->matrix->t;
        (instance->position).y = *(short *)(pMVar7->t + 1);
        (instance->position).z = *(short *)(pMVar7->t + 2);
      }
    }
    else {
      pMVar4 = instance->intro->multiSpline;
      uVar14 = *(undefined4 *)((pMVar4->curRotMatrix).m + 2);
      uVar16 = *(undefined4 *)((pMVar4->curRotMatrix).m + 4);
      uVar18 = *(undefined4 *)((pMVar4->curRotMatrix).m + 6);
      *(undefined4 *)m->m = *(undefined4 *)(pMVar4->curRotMatrix).m;
      *(undefined4 *)(pMVar21[-1].m + 2) = uVar14;
      *(undefined4 *)(pMVar21[-1].m + 4) = uVar16;
      *(undefined4 *)(pMVar21[-1].m + 6) = uVar18;
      lVar15 = (pMVar4->curRotMatrix).t[0];
      lVar17 = (pMVar4->curRotMatrix).t[1];
      lVar19 = (pMVar4->curRotMatrix).t[2];
      *(undefined4 *)(pMVar21[-1].m + 8) = *(undefined4 *)((pMVar4->curRotMatrix).m + 8);
      pMVar21[-1].t[0] = lVar15;
      pMVar21[-1].t[1] = lVar17;
      pMVar21[-1].t[2] = lVar19;
    }
    if ((*(int *)&instance->scale != 0x10001000) || ((instance->scale).z != 0x1000)) {
      DAT_1f800020 = (int)(instance->scale).x;
      DAT_1f800024 = (int)(instance->scale).y;
      DAT_1f800028 = (int)(instance->scale).z;
      ScaleMatrix(m,(VECTOR *)&DAT_1f800020);
      *(undefined2 *)&pMVar21[-1].field_0x12 = 1;
    }
    pMVar21[-1].t[0] = (int)(instance->position).x;
    pMVar21[-1].t[1] = (int)(instance->position).y;
    pMVar21[-1].t[2] = (int)(instance->position).z;
    (instance->anim).segMatrices = (_G2Matrix_Type *)instance->matrix;
    G2Anim_BuildTransforms(&instance->anim);
    if (instance->LinkParent != (_Instance *)0x0) {
      m = instance->matrix;
      segNumber = 0;
      iVar13 = m->t[0];
      iVar8 = m[3].t[0];
      iVar11 = m->t[1];
      iVar3 = m[3].t[1];
      iVar12 = m->t[2];
      iVar6 = m[3].t[2];
      if (0 < p_Var22->numSegments) {
        piVar20 = m->t + 2;
        do {
          _Var5 = G2Anim_IsControllerActive(&instance->anim,segNumber,0x20);
          if (_Var5 != G2FALSE) break;
          segNumber = segNumber + 1;
          piVar20[-2] = piVar20[-2] + (iVar13 - iVar8);
          *piVar20 = *piVar20 + (iVar12 - iVar6);
          piVar20[-1] = piVar20[-1] + (iVar11 - iVar3);
          piVar20 = piVar20 + 8;
        } while (segNumber < p_Var22->numSegments);
      }
      m = instance->matrix;
      lVar15 = m->t[1];
      lVar17 = m->t[2];
      pMVar21[-1].t[0] = m->t[0];
      pMVar21[-1].t[1] = lVar15;
      pMVar21[-1].t[2] = lVar17;
    }
    pOVar9 = instance->object;
    (instance->position).x = *(short *)pMVar21[-1].t;
    (instance->position).y = *(short *)(pMVar21[-1].t + 1);
    (instance->position).z = *(short *)(pMVar21[-1].t + 2);
    if ((pOVar9->oflags & 4U) != 0) {
      *(undefined4 *)&instance->rotation = local_78;
      *(undefined4 *)&(instance->rotation).z = local_74;
    }
    instance_00 = instance->LinkChild;
    while (instance_00 != (_Instance *)0x0) {
      G2Instance_BuildTransforms(instance_00);
      instance_00 = instance_00->LinkSibling;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Instance_ClearMatrices(struct _Instance *instance /*$s0*/)
 // line 352, offset 0x80094e78
	/* begin block 1 */
		// Start line: 814
	/* end block 1 */
	// End Line: 815

/* File: C:\kain2\game\G2\INSTNCG2.C */

void G2Instance_ClearMatrices(_Instance *instance)

{
  MATRIX *pMVar1;
  _Instance *instance_00;
  
  pMVar1 = instance->matrix;
  instance->matrix = (MATRIX *)0x0;
  instance->oldMatrix = pMVar1;
  instance_00 = instance->LinkChild;
  while (instance_00 != (_Instance *)0x0) {
    G2Instance_ClearMatrices(instance_00);
    instance_00 = instance_00->LinkSibling;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Instance_BuildAnimatedTransforms(struct _Instance *instance /*$s0*/)
 // line 363, offset 0x80094ecc
	/* begin block 1 */
		// Start line: 364
		// Start offset: 0x80094ECC
		// Variables:
	// 		struct MATRIX *rootMatrix; // $v0
	// 		struct _Model *model; // $v0
	/* end block 1 */
	// End offset: 0x80094F78
	// End Line: 392

	/* begin block 2 */
		// Start line: 832
	/* end block 2 */
	// End Line: 833

	/* begin block 3 */
		// Start line: 838
	/* end block 3 */
	// End Line: 839

/* File: C:\kain2\game\G2\INSTNCG2.C */

void _G2Instance_BuildAnimatedTransforms(_Instance *instance)

{
  MATRIX *pMVar1;
  uint uVar2;
  MATRIX *pMVar3;
  
  uVar2 = instance->flags2;
  if (((uVar2 & 0x10000000) == 0) ||
     (((uVar2 & 0x4000000) == 0 &&
      (((uVar2 & 0x20000000) == 0 || ((instance->flags & 0x800U) == 0)))))) {
    pMVar1 = GAMELOOP_GetMatrices
                       (instance->object->modelList[instance->currentModel]->numSegments + 1);
    if (pMVar1 == (MATRIX *)0x0) {
      instance->matrix = (MATRIX *)0x0;
    }
    else {
      pMVar3 = instance->matrix;
      instance->matrix = pMVar1 + 1;
      instance->oldMatrix = pMVar3;
      _G2Instance_RebuildAnimatedTransforms(instance);
    }
  }
  else {
    G2Instance_ClearMatrices(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Instance_RebuildNonAnimatedTransforms(struct _Instance *instance /*$s0*/)
 // line 396, offset 0x80094f88
	/* begin block 1 */
		// Start line: 397
		// Start offset: 0x80094F88
		// Variables:
	// 		struct VECTOR *scale; // $s5
	// 		struct MATRIX *introTransform; // $s7
	// 		struct MATRIX *segMatrix; // $s1
	// 		struct _Model *model; // $fp
	// 		struct _Segment *segment; // $s3
	// 		short scale_flag; // stack offset -48
	// 		long i; // $s4
	/* end block 1 */
	// End offset: 0x800951E4
	// End Line: 515

	/* begin block 2 */
		// Start line: 905
	/* end block 2 */
	// End Line: 906

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* File: C:\kain2\game\G2\INSTNCG2.C */

void _G2Instance_RebuildNonAnimatedTransforms(_Instance *instance)

{
  MultiSpline *pMVar1;
  undefined4 uVar2;
  long lVar3;
  undefined4 uVar4;
  long lVar5;
  undefined4 uVar6;
  long lVar7;
  _Instance *instance_00;
  MATRIX *m;
  ushort *puVar8;
  _Segment *segment;
  int iVar9;
  _Model *p_Var10;
  ushort local_30;
  
  m = instance->matrix;
  local_30 = 0;
  if (m != (MATRIX *)0x0) {
    p_Var10 = instance->object->modelList[instance->currentModel];
    segment = p_Var10->segmentList;
    if ((*(int *)&instance->scale != 0x10001000) || ((instance->scale).z != 0x1000)) {
      DAT_1f800028 = (int)(instance->scale).x;
      _DAT_1f80002c = (int)(instance->scale).y;
      _DAT_1f800030 = (int)(instance->scale).z;
      local_30 = 1;
    }
    iVar9 = 0;
    if (0 < p_Var10->numSegments) {
      puVar8 = (ushort *)&m->field_0x12;
      do {
        if (segment->lastTri != -1) {
          if ((segment->flags & 3U) == 0) {
            if (((instance->flags & 1U) == 0) || (instance->intro == (Intro *)0x0)) {
              if (((instance->rotation).z == 0) && (*(int *)&instance->rotation == 0)) {
                MATH3D_SetUnityMatrix((char)m);
              }
              else {
                RotMatrix((SVECTOR *)&instance->rotation,m);
              }
            }
            else {
              pMVar1 = instance->intro->multiSpline;
              uVar6 = *(undefined4 *)((pMVar1->curRotMatrix).m + 2);
              uVar2 = *(undefined4 *)((pMVar1->curRotMatrix).m + 4);
              uVar4 = *(undefined4 *)((pMVar1->curRotMatrix).m + 6);
              *(undefined4 *)m->m = *(undefined4 *)(pMVar1->curRotMatrix).m;
              *(undefined4 *)(m->m + 2) = uVar6;
              *(undefined4 *)(m->m + 4) = uVar2;
              *(undefined4 *)(m->m + 6) = uVar4;
              lVar7 = (pMVar1->curRotMatrix).t[0];
              lVar3 = (pMVar1->curRotMatrix).t[1];
              lVar5 = (pMVar1->curRotMatrix).t[2];
              *(undefined4 *)(m->m + 8) = *(undefined4 *)((pMVar1->curRotMatrix).m + 8);
              m->t[0] = lVar7;
              m->t[1] = lVar3;
              m->t[2] = lVar5;
            }
            if (local_30 != 0) {
              ScaleMatrix(m,(VECTOR *)&DAT_1f800028);
            }
            *(int *)(puVar8 + 1) = (int)(instance->position).x;
            *(int *)(puVar8 + 3) = (int)(instance->position).y;
            *(int *)(puVar8 + 5) = (int)(instance->position).z;
          }
          else {
            RotMatrix((SVECTOR *)&instance->rotation,(MATRIX *)&DAT_1f800038);
            if (local_30 != 0) {
              ScaleMatrix((MATRIX *)&DAT_1f800038,(VECTOR *)&DAT_1f800028);
            }
            _G2Instance_BuildFacadeTransforms(instance,segment,(char)m,0x38,(uint)local_30);
          }
        }
        m = m + 1;
        segment = segment + 1;
        iVar9 = iVar9 + 1;
        *puVar8 = local_30;
        puVar8 = puVar8 + 0x10;
      } while (iVar9 < p_Var10->numSegments);
    }
    instance_00 = instance->LinkChild;
    while (instance_00 != (_Instance *)0x0) {
      G2Instance_BuildTransforms(instance_00);
      instance_00 = instance_00->LinkSibling;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Instance_BuildDeactivatedTransforms(struct _Instance *instance /*$s0*/)
 // line 519, offset 0x80095214
	/* begin block 1 */
		// Start line: 520
		// Start offset: 0x80095214
		// Variables:
	// 		struct MATRIX *segMatrix; // $a0
	// 		struct MATRIX *startOldMatrix; // $a1
	// 		int numMatrices; // $s1
	// 		struct _Model *model; // $a0
	/* end block 1 */
	// End offset: 0x80095360
	// End Line: 577

	/* begin block 2 */
		// Start line: 1334
	/* end block 2 */
	// End Line: 1335

/* File: C:\kain2\game\G2\INSTNCG2.C */

void _G2Instance_BuildDeactivatedTransforms(_Instance *instance)

{
  MATRIX *pMVar1;
  uint uVar2;
  Object *pOVar3;
  _Instance *instance_00;
  int numMatrices;
  
  uVar2 = instance->flags2;
  if (((uVar2 & 0x10000000) == 0) ||
     (((uVar2 & 0x4000000) == 0 &&
      (((uVar2 & 0x20000000) == 0 || ((instance->flags & 0x800U) == 0)))))) {
    pOVar3 = instance->object;
    if ((pOVar3->animList == (_G2AnimKeylist_Type **)0x0) || ((pOVar3->oflags2 & 0x40000000U) != 0))
    {
      numMatrices = pOVar3->modelList[instance->currentModel]->numSegments;
    }
    else {
      numMatrices = pOVar3->modelList[instance->currentModel]->numSegments + 1;
    }
    pMVar1 = GAMELOOP_GetMatrices(numMatrices);
    if (pMVar1 == (MATRIX *)0x0) {
      instance->matrix = (MATRIX *)0x0;
    }
    else {
      instance->oldMatrix = instance->matrix;
      if ((instance->object->animList == (_G2AnimKeylist_Type **)0x0) ||
         ((instance->object->oflags2 & 0x40000000U) != 0)) {
        instance->matrix = pMVar1;
      }
      else {
        instance->matrix = pMVar1 + 1;
      }
      if (instance->oldMatrix != (MATRIX *)0x0) {
        memcpy();
      }
      instance_00 = instance->LinkChild;
      while (instance_00 != (_Instance *)0x0) {
        G2Instance_BuildTransforms(instance_00);
        instance_00 = instance_00->LinkSibling;
      }
    }
  }
  else {
    G2Instance_ClearMatrices(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Instance_BuildNonAnimatedTransforms(struct _Instance *instance /*$s0*/)
 // line 582, offset 0x80095374
	/* begin block 1 */
		// Start line: 583
		// Start offset: 0x80095374
		// Variables:
	// 		struct MATRIX *segMatrix; // $v1
	// 		struct _Model *model; // $v0
	/* end block 1 */
	// End offset: 0x80095420
	// End Line: 610

	/* begin block 2 */
		// Start line: 1463
	/* end block 2 */
	// End Line: 1464

/* File: C:\kain2\game\G2\INSTNCG2.C */

void _G2Instance_BuildNonAnimatedTransforms(_Instance *instance)

{
  MATRIX *pMVar1;
  MATRIX *pMVar2;
  uint uVar3;
  
  uVar3 = instance->flags2;
  if (((uVar3 & 0x10000000) == 0) ||
     (((uVar3 & 0x4000000) == 0 &&
      (((uVar3 & 0x20000000) == 0 || ((instance->flags & 0x800U) == 0)))))) {
    pMVar1 = GAMELOOP_GetMatrices(instance->object->modelList[instance->currentModel]->numSegments);
    if (pMVar1 == (MATRIX *)0x0) {
      instance->matrix = (MATRIX *)0x0;
    }
    else {
      pMVar2 = instance->matrix;
      instance->matrix = pMVar1;
      instance->oldMatrix = pMVar2;
      _G2Instance_RebuildNonAnimatedTransforms(instance);
    }
  }
  else {
    G2Instance_ClearMatrices(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Instance_BuildFacadeTransforms(struct _Instance *instance /*$s0*/, struct _Segment *segment /*$s1*/, struct MATRIX *segMatrix /*$s5*/, struct MATRIX *matrixPool /*$s6*/, long scale_flag /*stack 16*/)
 // line 618, offset 0x80095430
	/* begin block 1 */
		// Start line: 619
		// Start offset: 0x80095430
		// Variables:
	// 		struct _Position *cameraPos; // $s7
	// 		struct SVECTOR *segmentPos; // $s3
	// 		struct SVECTOR *segmentRot; // $s4
	// 		struct VECTOR *scale; // $fp

		/* begin block 1.1 */
			// Start line: 643
			// Start offset: 0x8009555C
			// Variables:
		// 		struct SVECTOR *zvec; // $s1
		// 		struct SVECTOR *camWorldPos; // $s2
		// 		struct SVECTOR *camLocPos; // $s6
		// 		long sqrt; // $s0
		/* end block 1.1 */
		// End offset: 0x80095678
		// End Line: 675

		/* begin block 1.2 */
			// Start line: 682
			// Start offset: 0x800956D8
			// Variables:
		// 		struct VECTOR *xy; // $s0
		/* end block 1.2 */
		// End offset: 0x8009579C
		// End Line: 701
	/* end block 1 */
	// End offset: 0x8009579C
	// End Line: 702

	/* begin block 2 */
		// Start line: 1536
	/* end block 2 */
	// End Line: 1537

/* File: C:\kain2\game\G2\INSTNCG2.C */

void _G2Instance_BuildFacadeTransforms
               (_Instance *instance,_Segment *segment,undefined segMatrix,undefined matrixPool,
               long scale_flag)

{
  long y;
  undefined3 in_register_00000019;
  MATRIX *m;
  undefined3 in_register_0000001d;
  MATRIX *m_00;
  
  m_00 = (MATRIX *)CONCAT31(in_register_0000001d,matrixPool);
  m = (MATRIX *)CONCAT31(in_register_00000019,segMatrix);
  if ((segment->pz == 0) && (*(int *)&segment->px == 0)) {
    DAT_1f800008._0_2_ = (instance->position).x;
    DAT_1f800008._2_2_ = (instance->position).y;
    DAT_1f80000c._0_2_ = (instance->position).z;
  }
  else {
    ApplyMatrixSV(m_00,(SVECTOR *)&segment->px,(SVECTOR *)&DAT_1f800008);
    DAT_1f800008._0_2_ = (short)DAT_1f800008 + (instance->position).x;
    DAT_1f800008._2_2_ = DAT_1f800008._2_2_ + (instance->position).y;
    DAT_1f80000c._0_2_ = (short)DAT_1f80000c + (instance->position).z;
  }
  m->t[0] = (int)(short)DAT_1f800008;
  m->t[1] = (int)DAT_1f800008._2_2_;
  m->t[2] = (int)(short)DAT_1f80000c;
  if ((segment->flags & 1U) == 0) {
    if ((segment->flags & 2U) != 0) {
      DAT_1f800018 = (int)(short)DAT_1f800000 - (int)(short)DAT_1f800008;
      DAT_1f80001c = (int)DAT_1f800000._2_2_ - (int)DAT_1f800008._2_2_;
      DAT_1f800020 = (int)(short)DAT_1f800004 - (int)(short)DAT_1f80000c;
      y = MATH3D_LengthXY(DAT_1f800018,DAT_1f80001c);
      DAT_1f800010 = MATH3D_FastAtan2(y,DAT_1f800020);
      DAT_1f800010 = DAT_1f800010 + 0xc00;
      DAT_1f800014._0_2_ = MATH3D_FastAtan2(DAT_1f80001c,DAT_1f800018);
      DAT_1f800014._0_2_ = (short)DAT_1f800014 + 0x400;
      MATH3D_SetUnityMatrix(segMatrix);
      if (scale_flag != 0) {
        ScaleMatrix(m,(VECTOR *)&DAT_1f800028);
      }
      RotMatrixX((int)DAT_1f800010,m);
      RotMatrixZ((int)(short)DAT_1f800014,m);
    }
  }
  else {
    DAT_1f800058 = m_00->m[2];
    DAT_1f80005a = m_00->m[5];
    DAT_1f80005c._0_2_ = m_00->m[8];
    y = MATH3D_FastSqrt(0x1000000 - (int)DAT_1f800058 * (int)DAT_1f800058);
    DAT_1f800010 = MATH3D_FastAtan2((int)DAT_1f80005a,(int)(short)DAT_1f80005c);
    DAT_1f800010 = -DAT_1f800010;
    DAT_1f800012 = MATH3D_FastAtan2((int)DAT_1f800058,y >> 0xc);
    DAT_1f800014._0_2_ = 0;
    RotMatrix((SVECTOR *)&DAT_1f800010,(MATRIX *)&DAT_1f800070);
    TransposeMatrix((MATRIX *)&DAT_1f800070,(MATRIX *)&DAT_1f800038);
    DAT_1f800060 = (short)DAT_1f800000 - (short)DAT_1f800008;
    DAT_1f800062 = DAT_1f800000._2_2_ - DAT_1f800008._2_2_;
    DAT_1f800064 = (short)DAT_1f800004 - (short)DAT_1f80000c;
    ApplyMatrixSV((MATRIX *)&DAT_1f800038,(SVECTOR *)&DAT_1f800060,(SVECTOR *)&DAT_1f800068);
    MATH3D_SetUnityMatrix(segMatrix);
    if (scale_flag != 0) {
      ScaleMatrix(m,(VECTOR *)&DAT_1f800028);
    }
    DAT_1f800014._0_2_ = MATH3D_FastAtan2((int)DAT_1f80006a,(int)DAT_1f800068);
    DAT_1f800014._0_2_ = (short)DAT_1f800014 + 0x400;
    RotMatrixZ((int)(short)DAT_1f800014,m);
    RotMatrixY((int)DAT_1f800012,m);
    RotMatrixX((int)DAT_1f800010,m);
  }
  return;
}





