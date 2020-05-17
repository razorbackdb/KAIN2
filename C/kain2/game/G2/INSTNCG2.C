#include "THISDUST.H"
#include "INSTNCG2.H"


// decompiled code
// original method signature: 
// void /*$ra*/ G2Instance_BuildTransformsForList(struct _Instance *listHead /*$s1*/)
 // line 71, offset 0x80094ed0
	/* begin block 1 */
		// Start line: 72
		// Start offset: 0x80094ED0
		// Variables:
	// 		struct _Instance *instance; // $s0
	/* end block 1 */
	// End offset: 0x80095038
	// End Line: 151

	/* begin block 2 */
		// Start line: 142
	/* end block 2 */
	// End Line: 143

void G2Instance_BuildTransformsForList(_Instance *listHead)

{
  _G2Bool_Enum _Var1;
  _Instance *instance;
  
  instance = listHead;
  if (listHead != (_Instance *)0x0) {
    do {
      if (instance->LinkParent == (_Instance *)0x0) {
        if (((instance->flags2 & 1U) == 0) &&
           ((((((instance->flags & 0x100000U) == 0 ||
               (*(int *)&instance->oldPos != *(int *)&instance->position)) ||
              ((instance->oldPos).z != (instance->position).z)) ||
             ((*(int *)&instance->oldRotation != *(int *)&instance->rotation ||
              ((instance->oldRotation).z != (instance->rotation).z)))) ||
            ((instance->matrix == (MATRIX *)0x0 ||
             (((instance->object->animList != (_G2AnimKeylist_Type **)0x0 &&
               ((instance->object->oflags2 & 0x40000000U) == 0)) &&
              (((instance->anim).flags & 1) != 0)))))))) {
          G2Instance_BuildTransforms(instance);
        }
        else {
          _G2Instance_BuildDeactivatedTransforms(instance);
        }
      }
      instance = instance->next;
    } while (instance != (_Instance *)0x0);
  }
  if (listHead != (_Instance *)0x0) {
    do {
      if ((listHead->rebuildCallback != (_func_6 *)0x0) &&
         (_Var1 = (*listHead->rebuildCallback)(listHead), _Var1 != G2FALSE)) {
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
 // line 155, offset 0x8009504c
	/* begin block 1 */
		// Start line: 333
	/* end block 1 */
	// End Line: 334

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
 // line 169, offset 0x800950a8
	/* begin block 1 */
		// Start line: 361
	/* end block 1 */
	// End Line: 362

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
 // line 184, offset 0x80095104
	/* begin block 1 */
		// Start line: 391
	/* end block 1 */
	// End Line: 392

	/* begin block 2 */
		// Start line: 392
	/* end block 2 */
	// End Line: 393

_G2AnimKeylist_Type * G2Instance_GetKeylist(_Instance *instance,int id)

{
  return instance->object->animList[id];
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Instance_RebuildAnimatedTransforms(struct _Instance *instance /*$s3*/)
 // line 196, offset 0x80095124
	/* begin block 1 */
		// Start line: 197
		// Start offset: 0x80095124
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
			// Start line: 220
			// Start offset: 0x80095188
		/* end block 1.1 */
		// End offset: 0x800951D4
		// End Line: 229

		/* begin block 1.2 */
			// Start line: 283
			// Start offset: 0x80095384
			// Variables:
		// 		struct VECTOR *ins_scale; // $v1
		/* end block 1.2 */
		// End offset: 0x800953B8
		// End Line: 291
	/* end block 1 */
	// End offset: 0x8009552C
	// End Line: 346

	/* begin block 2 */
		// Start line: 415
	/* end block 2 */
	// End Line: 416

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
  MATRIX *pMVar14;
  undefined4 uVar15;
  long lVar16;
  undefined4 uVar17;
  long lVar18;
  undefined4 uVar19;
  long lVar20;
  int *piVar21;
  _G2Anim_Type *anim;
  int segNumber;
  _Instance *instance_00;
  MATRIX *pMVar22;
  _Model *p_Var23;
  undefined4 local_78;
  undefined4 local_74;
  uint auStack112 [8];
  uint auStack80 [8];
  ushort auStack48 [4];
  
  pMVar22 = instance->matrix;
  if (pMVar22 != (MATRIX *)0x0) {
    p_Var23 = instance->object->modelList[instance->currentModel];
    pMVar14 = pMVar22 + -1;
    if ((instance->object->oflags & 4U) != 0) {
      iVar6 = (int)theCamera.core.position.x;
      sVar2 = (instance->position).x;
      iVar3 = (int)theCamera.core.position.y;
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
        RotMatrix((ushort *)&instance->rotation,(uint *)pMVar14);
      }
      else {
        G2Anim_UpdateStoredFrame(anim);
        G2Anim_GetSegChannelValue(anim,1,auStack48,7);
        RotMatrixZYX(auStack48,auStack112);
        G2Anim_GetSegChannelValue(anim,2,auStack48,7);
        RotMatrixZYX(auStack48,auStack80);
        MulMatrix2(auStack112,auStack80);
        TransposeMatrix(auStack80,(undefined4 *)pMVar14);
        pMVar10 = instance->matrix;
        pMVar7 = instance->LinkParent->matrix + instance->ParentLinkNode;
        uVar15 = *(undefined4 *)(pMVar7->m + 2);
        uVar17 = *(undefined4 *)(pMVar7->m + 4);
        uVar19 = *(undefined4 *)(pMVar7->m + 6);
        *(undefined4 *)pMVar10->m = *(undefined4 *)pMVar7->m;
        *(undefined4 *)(pMVar10->m + 2) = uVar15;
        *(undefined4 *)(pMVar10->m + 4) = uVar17;
        *(undefined4 *)(pMVar10->m + 6) = uVar19;
        lVar16 = pMVar7->t[0];
        lVar18 = pMVar7->t[1];
        lVar20 = pMVar7->t[2];
        *(undefined4 *)(pMVar10->m + 8) = *(undefined4 *)(pMVar7->m + 8);
        pMVar10->t[0] = lVar16;
        pMVar10->t[1] = lVar18;
        pMVar10->t[2] = lVar20;
        MulMatrix2((undefined4 *)instance->matrix,(uint *)pMVar14);
        pMVar7 = instance->matrix;
        (instance->position).x = *(short *)instance->matrix->t;
        (instance->position).y = *(short *)(pMVar7->t + 1);
        (instance->position).z = *(short *)(pMVar7->t + 2);
      }
    }
    else {
      pMVar4 = instance->intro->multiSpline;
      uVar15 = *(undefined4 *)((pMVar4->curRotMatrix).m + 2);
      uVar17 = *(undefined4 *)((pMVar4->curRotMatrix).m + 4);
      uVar19 = *(undefined4 *)((pMVar4->curRotMatrix).m + 6);
      *(undefined4 *)pMVar14->m = *(undefined4 *)(pMVar4->curRotMatrix).m;
      *(undefined4 *)(pMVar22[-1].m + 2) = uVar15;
      *(undefined4 *)(pMVar22[-1].m + 4) = uVar17;
      *(undefined4 *)(pMVar22[-1].m + 6) = uVar19;
      lVar16 = (pMVar4->curRotMatrix).t[0];
      lVar18 = (pMVar4->curRotMatrix).t[1];
      lVar20 = (pMVar4->curRotMatrix).t[2];
      *(undefined4 *)(pMVar22[-1].m + 8) = *(undefined4 *)((pMVar4->curRotMatrix).m + 8);
      pMVar22[-1].t[0] = lVar16;
      pMVar22[-1].t[1] = lVar18;
      pMVar22[-1].t[2] = lVar20;
    }
    if ((*(int *)&instance->scale != 0x10001000) || ((instance->scale).z != 0x1000)) {
      DAT_1f800020 = (int)(instance->scale).x;
      DAT_1f800024 = (int)(instance->scale).y;
      DAT_1f800028 = (int)(instance->scale).z;
      ScaleMatrix((int *)pMVar14,&DAT_1f800020);
      *(undefined2 *)&pMVar22[-1].field_0x12 = 1;
    }
    pMVar22[-1].t[0] = (int)(instance->position).x;
    pMVar22[-1].t[1] = (int)(instance->position).y;
    pMVar22[-1].t[2] = (int)(instance->position).z;
    (instance->anim).segMatrices = (_G2Matrix_Type *)instance->matrix;
    G2Anim_BuildTransforms(&instance->anim);
    if (instance->LinkParent != (_Instance *)0x0) {
      pMVar14 = instance->matrix;
      segNumber = 0;
      iVar13 = pMVar14->t[0];
      iVar8 = pMVar14[3].t[0];
      iVar11 = pMVar14->t[1];
      iVar3 = pMVar14[3].t[1];
      iVar12 = pMVar14->t[2];
      iVar6 = pMVar14[3].t[2];
      if (0 < p_Var23->numSegments) {
        piVar21 = pMVar14->t + 2;
        do {
          _Var5 = G2Anim_IsControllerActive(&instance->anim,segNumber,0x20);
          if (_Var5 != G2FALSE) break;
          segNumber = segNumber + 1;
          piVar21[-2] = piVar21[-2] + (iVar13 - iVar8);
          *piVar21 = *piVar21 + (iVar12 - iVar6);
          piVar21[-1] = piVar21[-1] + (iVar11 - iVar3);
          piVar21 = piVar21 + 8;
        } while (segNumber < p_Var23->numSegments);
      }
      pMVar14 = instance->matrix;
      lVar16 = pMVar14->t[1];
      lVar18 = pMVar14->t[2];
      pMVar22[-1].t[0] = pMVar14->t[0];
      pMVar22[-1].t[1] = lVar16;
      pMVar22[-1].t[2] = lVar18;
    }
    pOVar9 = instance->object;
    (instance->position).x = *(short *)pMVar22[-1].t;
    (instance->position).y = *(short *)(pMVar22[-1].t + 1);
    (instance->position).z = *(short *)(pMVar22[-1].t + 2);
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
 // line 348, offset 0x80095558
	/* begin block 1 */
		// Start line: 756
	/* end block 1 */
	// End Line: 757

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
 // line 359, offset 0x800955ac
	/* begin block 1 */
		// Start line: 360
		// Start offset: 0x800955AC
		// Variables:
	// 		struct MATRIX *rootMatrix; // $v0
	// 		struct _Model *model; // $v0
	/* end block 1 */
	// End offset: 0x80095658
	// End Line: 388

	/* begin block 2 */
		// Start line: 774
	/* end block 2 */
	// End Line: 775

	/* begin block 3 */
		// Start line: 780
	/* end block 3 */
	// End Line: 781

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
 // line 392, offset 0x80095668
	/* begin block 1 */
		// Start line: 393
		// Start offset: 0x80095668
		// Variables:
	// 		struct VECTOR *scale; // $s5
	// 		struct MATRIX *introTransform; // $s7
	// 		struct MATRIX *segMatrix; // $s1
	// 		struct _Model *model; // $fp
	// 		struct _Segment *segment; // $s3
	// 		short scale_flag; // stack offset -48
	// 		long i; // $s4
	/* end block 1 */
	// End offset: 0x800958C4
	// End Line: 511

	/* begin block 2 */
		// Start line: 847
	/* end block 2 */
	// End Line: 848

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
  ushort *puVar8;
  _Segment *segment;
  int iVar9;
  _Model *p_Var10;
  ushort local_30;
  
  mat = instance->matrix;
  local_30 = 0;
  if (mat != (MATRIX *)0x0) {
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
      puVar8 = (ushort *)&mat->field_0x12;
      do {
        if (segment->lastTri != -1) {
          if ((segment->flags & 3U) == 0) {
            if (((instance->flags & 1U) == 0) || (instance->intro == (Intro *)0x0)) {
              if (((instance->rotation).z == 0) && (*(int *)&instance->rotation == 0)) {
                MATH3D_SetUnityMatrix(mat);
              }
              else {
                RotMatrix((ushort *)&instance->rotation,(uint *)mat);
              }
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
              ScaleMatrix((int *)mat,&DAT_1f800028);
            }
            *(int *)(puVar8 + 1) = (int)(instance->position).x;
            *(int *)(puVar8 + 3) = (int)(instance->position).y;
            *(int *)(puVar8 + 5) = (int)(instance->position).z;
          }
          else {
            RotMatrix((ushort *)&instance->rotation,&DAT_1f800038);
            if (local_30 != 0) {
              ScaleMatrix(&DAT_1f800038,&DAT_1f800028);
            }
            _G2Instance_BuildFacadeTransforms
                      (instance,segment,mat,(MATRIX *)&DAT_1f800038,(uint)local_30);
          }
        }
        mat = mat + 1;
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
 // line 515, offset 0x800958f4
	/* begin block 1 */
		// Start line: 516
		// Start offset: 0x800958F4
		// Variables:
	// 		struct MATRIX *segMatrix; // $a0
	// 		struct MATRIX *startOldMatrix; // $a1
	// 		int numMatrices; // $s1
	// 		struct _Model *model; // $a0
	/* end block 1 */
	// End offset: 0x80095A60
	// End Line: 578

	/* begin block 2 */
		// Start line: 1276
	/* end block 2 */
	// End Line: 1277

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
    if (instance->matrix == (MATRIX *)0x0) {
      G2Instance_BuildTransforms(instance);
    }
    else {
      pOVar2 = instance->object;
      if ((pOVar2->animList == (_G2AnimKeylist_Type **)0x0) ||
         ((pOVar2->oflags2 & 0x40000000U) != 0)) {
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
  }
  else {
    G2Instance_ClearMatrices(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Instance_BuildNonAnimatedTransforms(struct _Instance *instance /*$s0*/)
 // line 583, offset 0x80095a74
	/* begin block 1 */
		// Start line: 584
		// Start offset: 0x80095A74
		// Variables:
	// 		struct MATRIX *segMatrix; // $v1
	// 		struct _Model *model; // $v0
	/* end block 1 */
	// End offset: 0x80095B20
	// End Line: 611

	/* begin block 2 */
		// Start line: 1415
	/* end block 2 */
	// End Line: 1416

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
 // line 619, offset 0x80095b30
	/* begin block 1 */
		// Start line: 620
		// Start offset: 0x80095B30
		// Variables:
	// 		struct _Position *cameraPos; // $s7
	// 		struct SVECTOR *segmentPos; // $s3
	// 		struct SVECTOR *segmentRot; // $s4
	// 		struct VECTOR *scale; // $fp

		/* begin block 1.1 */
			// Start line: 644
			// Start offset: 0x80095C5C
			// Variables:
		// 		struct SVECTOR *zvec; // $s1
		// 		struct SVECTOR *camWorldPos; // $s2
		// 		struct SVECTOR *camLocPos; // $s6
		// 		long sqrt; // $s0
		/* end block 1.1 */
		// End offset: 0x80095D78
		// End Line: 676

		/* begin block 1.2 */
			// Start line: 683
			// Start offset: 0x80095DD8
			// Variables:
		// 		struct VECTOR *xy; // $s0
		/* end block 1.2 */
		// End offset: 0x80095E9C
		// End Line: 702
	/* end block 1 */
	// End offset: 0x80095E9C
	// End Line: 703

	/* begin block 2 */
		// Start line: 1488
	/* end block 2 */
	// End Line: 1489

void _G2Instance_BuildFacadeTransforms
               (_Instance *instance,_Segment *segment,MATRIX *segMatrix,MATRIX *matrixPool,
               long scale_flag)

{
  long y;
  
  if ((segment->pz == 0) && (*(int *)&segment->px == 0)) {
    DAT_1f800008._0_2_ = (instance->position).x;
    DAT_1f800008._2_2_ = (instance->position).y;
    DAT_1f80000c._0_2_ = (instance->position).z;
  }
  else {
    ApplyMatrixSV(matrixPool,&segment->px,&DAT_1f800008);
    DAT_1f800008._0_2_ = (short)DAT_1f800008 + (instance->position).x;
    DAT_1f800008._2_2_ = DAT_1f800008._2_2_ + (instance->position).y;
    DAT_1f80000c._0_2_ = (short)DAT_1f80000c + (instance->position).z;
  }
  segMatrix->t[0] = (int)(short)DAT_1f800008;
  segMatrix->t[1] = (int)DAT_1f800008._2_2_;
  segMatrix->t[2] = (int)(short)DAT_1f80000c;
  if ((segment->flags & 1U) == 0) {
    if ((segment->flags & 2U) != 0) {
      DAT_1f800018 = (int)(short)DAT_1f800000 - (int)(short)DAT_1f800008;
      DAT_1f80001c = (int)DAT_1f800000._2_2_ - (int)DAT_1f800008._2_2_;
      DAT_1f800020 = (int)(short)DAT_1f800004 - (int)(short)DAT_1f80000c;
      y = MATH3D_LengthXY(DAT_1f800018,DAT_1f80001c);
      DAT_1f800010._0_2_ = MATH3D_FastAtan2(y,DAT_1f800020);
      DAT_1f800010._0_2_ = (short)DAT_1f800010 + 0xc00;
      DAT_1f800014._0_2_ = MATH3D_FastAtan2(DAT_1f80001c,DAT_1f800018);
      DAT_1f800014._0_2_ = (short)DAT_1f800014 + 0x400;
      MATH3D_SetUnityMatrix(segMatrix);
      if (scale_flag != 0) {
        ScaleMatrix((int *)segMatrix,&DAT_1f800028);
      }
      RotMatrixX((int)(short)DAT_1f800010,(int)segMatrix);
      RotMatrixZ((int)(short)DAT_1f800014,(uint *)segMatrix);
    }
  }
  else {
    DAT_1f800058._0_2_ = matrixPool->m[2];
    DAT_1f800058._2_2_ = matrixPool->m[5];
    DAT_1f80005c = matrixPool->m[8];
    y = MATH3D_FastSqrt(0x1000000 - (int)(short)DAT_1f800058 * (int)(short)DAT_1f800058);
    DAT_1f800010._0_2_ = MATH3D_FastAtan2((int)DAT_1f800058._2_2_,(int)DAT_1f80005c);
    DAT_1f800010._0_2_ = -(short)DAT_1f800010;
    DAT_1f800010._2_2_ = MATH3D_FastAtan2((int)(short)DAT_1f800058,y >> 0xc);
    DAT_1f800014._0_2_ = 0;
    RotMatrix((ushort *)&DAT_1f800010,&DAT_1f800070);
    TransposeMatrix(&DAT_1f800070,&DAT_1f800038);
    DAT_1f800060 = (short)DAT_1f800000 - (short)DAT_1f800008;
    DAT_1f800062 = DAT_1f800000._2_2_ - DAT_1f800008._2_2_;
    DAT_1f800064 = (short)DAT_1f800004 - (short)DAT_1f80000c;
    ApplyMatrixSV(&DAT_1f800038,&DAT_1f800060,&DAT_1f800068);
    MATH3D_SetUnityMatrix(segMatrix);
    if (scale_flag != 0) {
      ScaleMatrix((int *)segMatrix,&DAT_1f800028);
    }
    DAT_1f800014._0_2_ = MATH3D_FastAtan2((int)DAT_1f80006a,(int)DAT_1f800068);
    DAT_1f800014._0_2_ = (short)DAT_1f800014 + 0x400;
    RotMatrixZ((int)(short)DAT_1f800014,(uint *)segMatrix);
    RotMatrixY((int)DAT_1f800010._2_2_,(uint *)segMatrix);
    RotMatrixX((int)(short)DAT_1f800010,(int)segMatrix);
  }
  return;
}





