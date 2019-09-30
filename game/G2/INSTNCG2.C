#include "THISDUST.H"
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

void _G2Instance_RebuildAnimatedTransforms(_Instance *instance)

{
  short sVar1;
  short sVar2;
  int iVar3;
  MultiSpline *pMVar4;
  _G2Bool_Enum _Var5;
  int iVar6;
  int iVar7;
  Object *pOVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  MATRIX *pMVar12;
  undefined4 uVar13;
  long lVar14;
  undefined4 uVar15;
  long lVar16;
  undefined4 uVar17;
  long lVar18;
  int *piVar19;
  _G2Anim_Type *anim;
  int segNumber;
  _Instance *instance_00;
  MATRIX *pMVar20;
  _Model *p_Var21;
  undefined4 local_78;
  undefined4 local_74;
  uint auStack112 [8];
  uint auStack80 [8];
  ushort auStack48 [4];
  
  pMVar20 = instance->matrix;
  if (pMVar20 != (MATRIX *)0x0) {
    p_Var21 = instance->object->modelList[instance->currentModel];
    pMVar12 = pMVar20 + -1;
    if ((instance->object->oflags & 4U) != 0) {
      iVar6 = (int)theCamera.core.position.x;
      sVar1 = (instance->position).x;
      iVar3 = (int)theCamera.core.position.y;
      sVar2 = (instance->position).y;
      (instance->rotation).x = 0;
      (instance->rotation).y = 0;
                    /* WARNING: Subroutine does not return */
      MATH3D_FastAtan2(iVar3 - sVar2,iVar6 - sVar1);
    }
    if (((instance->flags & 1U) == 0) || (instance->intro == (Intro *)0x0)) {
      anim = &instance->anim;
      if (instance->LinkParent == (_Instance *)0x0) {
                    /* WARNING: Subroutine does not return */
        RotMatrix((ushort *)&instance->rotation,(uint *)pMVar12);
      }
      G2Anim_UpdateStoredFrame(anim);
      G2Anim_GetSegChannelValue(anim,1,auStack48,7);
      RotMatrixZYX(auStack48,auStack112);
      G2Anim_GetSegChannelValue(anim,2,auStack48,7);
      RotMatrixZYX(auStack48,auStack80);
                    /* WARNING: Subroutine does not return */
      MulMatrix2((char *)auStack112,(char *)auStack80);
    }
    pMVar4 = instance->intro->multiSpline;
    uVar13 = *(undefined4 *)((pMVar4->curRotMatrix).m + 2);
    uVar15 = *(undefined4 *)((pMVar4->curRotMatrix).m + 4);
    uVar17 = *(undefined4 *)((pMVar4->curRotMatrix).m + 6);
    *(undefined4 *)pMVar12->m = *(undefined4 *)(pMVar4->curRotMatrix).m;
    *(undefined4 *)(pMVar20[-1].m + 2) = uVar13;
    *(undefined4 *)(pMVar20[-1].m + 4) = uVar15;
    *(undefined4 *)(pMVar20[-1].m + 6) = uVar17;
    lVar14 = (pMVar4->curRotMatrix).t[0];
    lVar16 = (pMVar4->curRotMatrix).t[1];
    lVar18 = (pMVar4->curRotMatrix).t[2];
    *(undefined4 *)(pMVar20[-1].m + 8) = *(undefined4 *)((pMVar4->curRotMatrix).m + 8);
    pMVar20[-1].t[0] = lVar14;
    pMVar20[-1].t[1] = lVar16;
    pMVar20[-1].t[2] = lVar18;
    if ((*(int *)&instance->scale != 0x10001000) || ((instance->scale).z != 0x1000)) {
      DAT_1f800020 = (int)(instance->scale).x;
      DAT_1f800024 = (int)(instance->scale).y;
      DAT_1f800028 = (int)(instance->scale).z;
                    /* WARNING: Subroutine does not return */
      ScaleMatrix((int *)pMVar12,&DAT_1f800020);
    }
    pMVar20[-1].t[0] = (int)(instance->position).x;
    pMVar20[-1].t[1] = (int)(instance->position).y;
    pMVar20[-1].t[2] = (int)(instance->position).z;
    (instance->anim).segMatrices = (_G2Matrix_Type *)instance->matrix;
    G2Anim_BuildTransforms(&instance->anim);
    if (instance->LinkParent != (_Instance *)0x0) {
      pMVar12 = instance->matrix;
      segNumber = 0;
      iVar11 = pMVar12->t[0];
      iVar7 = pMVar12[3].t[0];
      iVar9 = pMVar12->t[1];
      iVar3 = pMVar12[3].t[1];
      iVar10 = pMVar12->t[2];
      iVar6 = pMVar12[3].t[2];
      if (0 < p_Var21->numSegments) {
        piVar19 = pMVar12->t + 2;
        do {
          _Var5 = G2Anim_IsControllerActive(&instance->anim,segNumber,0x20);
          if (_Var5 != G2FALSE) break;
          segNumber = segNumber + 1;
          piVar19[-2] = piVar19[-2] + (iVar11 - iVar7);
          *piVar19 = *piVar19 + (iVar10 - iVar6);
          piVar19[-1] = piVar19[-1] + (iVar9 - iVar3);
          piVar19 = piVar19 + 8;
        } while (segNumber < p_Var21->numSegments);
      }
      pMVar12 = instance->matrix;
      lVar14 = pMVar12->t[1];
      lVar16 = pMVar12->t[2];
      pMVar20[-1].t[0] = pMVar12->t[0];
      pMVar20[-1].t[1] = lVar14;
      pMVar20[-1].t[2] = lVar16;
    }
    pOVar8 = instance->object;
    (instance->position).x = *(short *)pMVar20[-1].t;
    (instance->position).y = *(short *)(pMVar20[-1].t + 1);
    (instance->position).z = *(short *)(pMVar20[-1].t + 2);
    if ((pOVar8->oflags & 4U) != 0) {
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
  MATRIX *mat;
  short *psVar8;
  _Segment *p_Var9;
  int iVar10;
  _Model *p_Var11;
  short local_30;
  
  mat = instance->matrix;
  local_30 = 0;
  if (mat != (MATRIX *)0x0) {
    p_Var11 = instance->object->modelList[instance->currentModel];
    p_Var9 = p_Var11->segmentList;
    if ((*(int *)&instance->scale != 0x10001000) || ((instance->scale).z != 0x1000)) {
      DAT_1f800028 = (int)(instance->scale).x;
      DAT_1f80002c = (int)(instance->scale).y;
      _DAT_1f800030 = (int)(instance->scale).z;
      local_30 = 1;
    }
    iVar10 = 0;
    if (0 < p_Var11->numSegments) {
      psVar8 = (short *)&mat->field_0x12;
      do {
        if (p_Var9->lastTri != -1) {
          if ((p_Var9->flags & 3U) != 0) {
                    /* WARNING: Subroutine does not return */
            RotMatrix((ushort *)&instance->rotation,(uint *)&DAT_1f800038);
          }
          if (((instance->flags & 1U) == 0) || (instance->intro == (Intro *)0x0)) {
            if (((instance->rotation).z != 0) || (*(int *)&instance->rotation != 0)) {
                    /* WARNING: Subroutine does not return */
              RotMatrix((ushort *)&instance->rotation,(uint *)mat);
            }
            MATH3D_SetUnityMatrix(mat);
          }
          else {
            pMVar1 = instance->intro->multiSpline;
            uVar6 = *(undefined4 *)((pMVar1->curRotMatrix).m + 2);
            uVar2 = *(undefined4 *)((pMVar1->curRotMatrix).m + 4);
            uVar4 = *(undefined4 *)((pMVar1->curRotMatrix).m + 6);
            *(undefined4 *)mat->m = *(undefined4 *)(pMVar1->curRotMatrix).m;
            *(undefined4 *)(mat->m + 2) = uVar6;
            *(undefined4 *)(mat->m + 4) = uVar2;
            *(undefined4 *)(mat->m + 6) = uVar4;
            lVar7 = (pMVar1->curRotMatrix).t[0];
            lVar3 = (pMVar1->curRotMatrix).t[1];
            lVar5 = (pMVar1->curRotMatrix).t[2];
            *(undefined4 *)(mat->m + 8) = *(undefined4 *)((pMVar1->curRotMatrix).m + 8);
            mat->t[0] = lVar7;
            mat->t[1] = lVar3;
            mat->t[2] = lVar5;
          }
          if (local_30 != 0) {
                    /* WARNING: Subroutine does not return */
            ScaleMatrix((int *)mat,&DAT_1f800028);
          }
          *(int *)(psVar8 + 1) = (int)(instance->position).x;
          *(int *)(psVar8 + 3) = (int)(instance->position).y;
          *(int *)(psVar8 + 5) = (int)(instance->position).z;
        }
        mat = mat + 1;
        p_Var9 = p_Var9 + 1;
        iVar10 = iVar10 + 1;
        *psVar8 = local_30;
        psVar8 = psVar8 + 0x10;
      } while (iVar10 < p_Var11->numSegments);
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

void _G2Instance_BuildDeactivatedTransforms(_Instance *instance)

{
  MATRIX *__dest;
  uint uVar1;
  Object *pOVar2;
  MATRIX *__src;
  _Instance *instance_00;
  int numMatrices;
  
  uVar1 = instance->flags2;
  if (((uVar1 & 0x10000000) == 0) ||
     (((uVar1 & 0x4000000) == 0 &&
      (((uVar1 & 0x20000000) == 0 || ((instance->flags & 0x800U) == 0)))))) {
    pOVar2 = instance->object;
    if ((pOVar2->animList == (_G2AnimKeylist_Type **)0x0) || ((pOVar2->oflags2 & 0x40000000U) != 0))
    {
      numMatrices = pOVar2->modelList[instance->currentModel]->numSegments;
    }
    else {
      numMatrices = pOVar2->modelList[instance->currentModel]->numSegments + 1;
    }
    __dest = GAMELOOP_GetMatrices(numMatrices);
    if (__dest == (MATRIX *)0x0) {
      instance->matrix = (MATRIX *)0x0;
    }
    else {
      instance->oldMatrix = instance->matrix;
      if ((instance->object->animList == (_G2AnimKeylist_Type **)0x0) ||
         (__src = instance->matrix + -1, (instance->object->oflags2 & 0x40000000U) != 0)) {
        __src = instance->oldMatrix;
        instance->matrix = __dest;
      }
      else {
        instance->matrix = __dest + 1;
      }
      if (instance->oldMatrix != (MATRIX *)0x0) {
        memcpy(__dest,__src,numMatrices << 5);
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

void _G2Instance_BuildFacadeTransforms
               (_Instance *instance,_Segment *segment,MATRIX *segMatrix,MATRIX *matrixPool,
               long scale_flag)

{
  if ((segment->pz != 0) || (*(int *)&segment->px != 0)) {
                    /* WARNING: Subroutine does not return */
    ApplyMatrixSV(matrixPool,&segment->px,&DAT_1f800008);
  }
  DAT_1f800008 = (instance->position).x;
  DAT_1f80000a = (instance->position).y;
  DAT_1f80000c = (instance->position).z;
  segMatrix->t[0] = (int)DAT_1f800008;
  segMatrix->t[1] = (int)DAT_1f80000a;
  segMatrix->t[2] = (int)DAT_1f80000c;
  if ((segment->flags & 1U) != 0) {
    DAT_1f800058._0_2_ = matrixPool->m[2];
    DAT_1f800058._2_2_ = matrixPool->m[5];
    DAT_1f80005c._0_2_ = matrixPool->m[8];
                    /* WARNING: Subroutine does not return */
    MATH3D_FastSqrt(0x1000000 - (int)(short)DAT_1f800058 * (int)(short)DAT_1f800058);
  }
  if ((segment->flags & 2U) != 0) {
    DAT_1f800018 = (int)DAT_1f800000 - (int)DAT_1f800008;
    DAT_1f80001c = (int)DAT_1f800002 - (int)DAT_1f80000a;
    DAT_1f800020 = (int)DAT_1f800004 - (int)DAT_1f80000c;
                    /* WARNING: Subroutine does not return */
    MATH3D_LengthXY(DAT_1f800018,DAT_1f80001c);
  }
  return;
}





