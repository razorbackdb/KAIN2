#include "THISDUST.H"
#include "FX.H"


// decompiled code
// original method signature: 
// void /*$ra*/ FX_Init(struct _FXTracker *fxTracker /*$s1*/)
 // line 120, offset 0x80042950
	/* begin block 1 */
		// Start line: 121
		// Start offset: 0x80042950
		// Variables:
	// 		struct _FX_MATRIX *fxMatrix; // $s0
	// 		struct _FX_MATRIX *endFXMatrix; // $s2
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct _FX_PRIM *endFXPrim; // $s2
	/* end block 1 */
	// End offset: 0x800429E8
	// End Line: 147

	/* begin block 2 */
		// Start line: 240
	/* end block 2 */
	// End Line: 241

/* File: C:\kain2\game\FX.C */

void FX_Init(_FXTracker *fxTracker)

{
  _FX_MATRIX *p_Var1;
  _FXTracker *node;
  _FX_PRIM *node_00;
  
  (fxTracker->usedMatrixList).next = (NodeType *)0x0;
  (fxTracker->usedMatrixList).prev = (NodeType *)0x0;
  (fxTracker->freeMatrixList).next = (NodeType *)0x0;
  (fxTracker->freeMatrixList).prev = (NodeType *)0x0;
  (fxTracker->usedPrimList).next = (NodeType *)0x0;
  (fxTracker->usedPrimList).prev = (NodeType *)0x0;
  (fxTracker->usedPrimListSprite).next = (NodeType *)0x0;
  (fxTracker->usedPrimListSprite).prev = (NodeType *)0x0;
  (fxTracker->freePrimList).next = (NodeType *)0x0;
  (fxTracker->freePrimList).prev = (NodeType *)0x0;
  node = fxTracker;
  if (fxTracker < (_FXTracker *)&fxTracker->usedMatrixList) {
    do {
      LIST_InsertFunc(&fxTracker->freeMatrixList,(NodeType *)node);
      p_Var1 = node->matrixPool;
      node = (_FXTracker *)(p_Var1 + 1);
    } while ((_FXTracker *)(p_Var1 + 1) < (_FXTracker *)&fxTracker->usedMatrixList);
  }
  node_00 = fxTracker->primPool;
  while (node_00 < (_FX_PRIM *)&fxTracker->usedPrimList) {
    LIST_InsertFunc(&fxTracker->freePrimList,(NodeType *)node_00);
    node_00 = node_00 + 1;
  }
  FX_LastUsedPrim = 0;
  FX_ConstrictPositionPtr = &FX_ConstrictPosition;
  FX_Spiral_Init();
  snow_amount = 0;
  rain_amount = 0;
  FX_reaver_instance = 0;
  FX_Frames = 1;
  FX_TimeCount = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Die(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$s1*/)
 // line 186, offset 0x80042a30
	/* begin block 1 */
		// Start line: 367
	/* end block 1 */
	// End Line: 368

	/* begin block 2 */
		// Start line: 416
	/* end block 2 */
	// End Line: 417

/* File: C:\kain2\game\FX.C */

void FX_Die(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  if ((FX_LastUsedPrim == fxPrim) &&
     (FX_LastUsedPrim = (_FX_PRIM *)(fxPrim->node).prev,
     (FX_LastUsedPrim->node).prev == (NodeType *)0x0)) {
    FX_LastUsedPrim = (_FX_PRIM *)0x0;
  }
  fxPrim->flags = fxPrim->flags | 0x10;
  LIST_DeleteFunc((NodeType *)fxPrim);
  LIST_InsertFunc(&fxTracker->freePrimList,(NodeType *)fxPrim);
  return;
}



// decompiled code
// original method signature: 
// struct _FX_MATRIX * /*$ra*/ FX_GetMatrix(struct _FXTracker *fxTracker /*$s1*/)
 // line 203, offset 0x80042aa0
	/* begin block 1 */
		// Start line: 204
		// Start offset: 0x80042AA0
		// Variables:
	// 		struct _FX_MATRIX *fxMatrix; // $s0
	/* end block 1 */
	// End offset: 0x80042AD8
	// End Line: 213

	/* begin block 2 */
		// Start line: 452
	/* end block 2 */
	// End Line: 453

/* File: C:\kain2\game\FX.C */

_FX_MATRIX * FX_GetMatrix(_FXTracker *fxTracker)

{
  _FX_MATRIX *node;
  
  node = (_FX_MATRIX *)LIST_GetFunc(&fxTracker->freeMatrixList);
  if (node != (_FX_MATRIX *)0x0) {
    *(NodeType **)&node->flags = (NodeType *)0x1;
    LIST_InsertFunc(&fxTracker->usedMatrixList,(NodeType *)node);
  }
  return node;
}



// decompiled code
// original method signature: 
// struct _FX_PRIM * /*$ra*/ FX_GetPrim(struct _FXTracker *fxTracker /*$a0*/)
 // line 217, offset 0x80042af0
	/* begin block 1 */
		// Start line: 218
		// Start offset: 0x80042AF0
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $a0
	/* end block 1 */
	// End offset: 0x80042B50
	// End Line: 239

	/* begin block 2 */
		// Start line: 481
	/* end block 2 */
	// End Line: 482

/* File: C:\kain2\game\FX.C */

_FX_PRIM * FX_GetPrim(_FXTracker *fxTracker)

{
  NodeType *pNVar1;
  _FX_PRIM *p_Var2;
  _FX_PRIM *p_Var3;
  
  p_Var3 = (_FX_PRIM *)LIST_GetFunc(&fxTracker->freePrimList);
  p_Var2 = FX_LastUsedPrim;
  if (p_Var3 == (_FX_PRIM *)0x0) {
    if (FX_LastUsedPrim != (_FX_PRIM *)0x0) {
      FX_LastUsedPrim = (_FX_PRIM *)(FX_LastUsedPrim->node).prev;
      pNVar1 = &FX_LastUsedPrim->node;
      (FX_LastUsedPrim->node).next = (NodeType *)0x0;
      p_Var3 = p_Var2;
      if (pNVar1->prev == (NodeType *)0x0) {
        FX_LastUsedPrim = (_FX_PRIM *)0x0;
      }
    }
    if (p_Var3 == (_FX_PRIM *)0x0) {
      return (_FX_PRIM *)0x0;
    }
  }
  *(NodeType **)&p_Var3->process = (NodeType *)0x0;
  *(NodeType **)&p_Var3->flags = (NodeType *)0x0;
  p_Var3->matrix = (_FX_MATRIX *)0x0;
  return p_Var3;
}



// decompiled code
// original method signature: 
// struct _FXParticle * /*$ra*/ FX_GetParticle(struct _Instance *instance /*$s1*/, short startSegment /*$s0*/)
 // line 242, offset 0x80042b60
	/* begin block 1 */
		// Start line: 243
		// Start offset: 0x80042B60
		// Variables:
	// 		struct _FXParticle *particle; // $v1
	/* end block 1 */
	// End offset: 0x80042BE4
	// End Line: 263

	/* begin block 2 */
		// Start line: 534
	/* end block 2 */
	// End Line: 535

/* File: C:\kain2\game\FX.C */

_FXParticle * FX_GetParticle(_Instance *instance,short startSegment)

{
  _FXParticle *p_Var1;
  
  p_Var1 = (_FXParticle *)MEMPACK_Malloc(0x4c,'\r');
  if (p_Var1 != (_FXParticle *)0x0) {
    p_Var1->effectType = '\x01';
    *(code **)&p_Var1->continue_process = FX_ContinueParticle;
    p_Var1->type = '\0';
    p_Var1->instance = instance;
    p_Var1->startSegment = (char)startSegment;
    p_Var1->texture = (TextureMT3 *)0x0;
    p_Var1->fxprim_process = (void *)0x0;
    p_Var1->fxprim_modify_process = (void *)0x0;
    p_Var1->startScale = 0x1000;
    p_Var1->scaleSpeed = 0;
    (p_Var1->offset).z = 0;
    (p_Var1->offset).y = 0;
    (p_Var1->offset).x = 0;
    (p_Var1->acceleration).z = 0;
    (p_Var1->acceleration).y = 0;
    (p_Var1->acceleration).x = 0;
    p_Var1->flag_bits = 0;
    p_Var1->z_undulate = '\0';
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_AniTexSetup(struct _FX_PRIM *fxPrim /*$a3*/, struct _MFace *mface /*$a1*/, struct _Model *model /*$a2*/, struct _FXTracker *fxTracker /*$a3*/)
 // line 266, offset 0x80042bfc
	/* begin block 1 */
		// Start line: 591
	/* end block 1 */
	// End Line: 592

	/* begin block 2 */
		// Start line: 592
	/* end block 2 */
	// End Line: 593

/* File: C:\kain2\game\FX.C */

void FX_AniTexSetup(_FX_PRIM *fxPrim,_MFace *mface,_Model *model,_FXTracker *fxTracker)

{
  AniTex *pAVar1;
  uint uVar2;
  uint uVar3;
  
  if ((mface->flags & 2) == 0) {
    fxPrim->flags = fxPrim->flags & 0xfffffffa;
    uVar2 = mface->color;
    uVar3 = 0x20000000;
  }
  else {
    fxPrim->flags = fxPrim->flags | 1;
    fxPrim->texture = (TextureMT3 *)mface->color;
    if (model->aniTextures != (AniTex *)0x0) {
      fxPrim->flags = fxPrim->flags | 4;
      (fxPrim->ani).texMem = fxPrim->texture;
      pAVar1 = model->aniTextures;
      (fxPrim->ani).curFrame = 0;
      (fxPrim->ani).aniTextures = pAVar1;
    }
    uVar2 = fxPrim->texture->color;
    uVar3 = 0x24000000;
  }
  fxPrim->color = uVar2 & 0x3ffffff | uVar3;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StandardProcess(struct _FX_PRIM *fxPrim /*$a0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 353, offset 0x80042cb0
	/* begin block 1 */
		// Start line: 771
	/* end block 1 */
	// End Line: 772

/* File: C:\kain2\game\FX.C */

void FX_StandardProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  FX_StandardFXPrimProcess(fxPrim,fxTracker);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ShatterProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$s1*/)
 // line 389, offset 0x80042cd0
	/* begin block 1 */
		// Start line: 390
		// Start offset: 0x80042CD0
		// Variables:
	// 		struct MATRIX matrix; // stack offset -64
	// 		struct _Rotation rotation; // stack offset -32
	// 		struct _Rotation rot_temp; // stack offset -24
	/* end block 1 */
	// End offset: 0x80042F64
	// End Line: 438

	/* begin block 2 */
		// Start line: 843
	/* end block 2 */
	// End Line: 844

/* File: C:\kain2\game\FX.C */

void FX_ShatterProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  short sVar3;
  _FX_MATRIX *p_Var4;
  int iVar5;
  int iVar6;
  int iVar7;
  MATRIX MStack64;
  short local_20;
  short local_1e;
  short local_1c;
  SVECTOR local_18;
  
  memset();
  if (0 < fxPrim->timeToLive) {
    fxPrim->timeToLive = fxPrim->timeToLive + -1;
  }
  if (fxPrim->timeToLive == 0) {
    FX_Die(fxPrim,fxTracker);
  }
  else {
    if ((fxPrim->flags & 2U) == 0) {
      iVar5 = (int)(short)DAT_800d2314;
      sVar1 = *(short *)((int)&fxPrim->duo + 8);
      sVar2 = *(short *)((int)&fxPrim->duo + 10);
      *(short *)&fxPrim->duo =
           *(short *)&fxPrim->duo + (short)(iVar5 * *(short *)((int)&fxPrim->duo + 6) >> 0xc);
      sVar3 = *(short *)&fxPrim->duo;
      *(short *)((int)&fxPrim->duo + 2) =
           *(short *)((int)&fxPrim->duo + 2) + (short)(iVar5 * sVar1 >> 0xc);
      sVar1 = *(short *)((int)&fxPrim->duo + 2);
      *(short *)((int)&fxPrim->duo + 4) =
           *(short *)((int)&fxPrim->duo + 4) + (short)(iVar5 * sVar2 >> 0xc);
      sVar2 = *(short *)((int)&fxPrim->duo + 4);
      (fxPrim->position).x = (fxPrim->position).x + (short)(iVar5 * sVar3 >> 0xc);
      (fxPrim->position).y = (fxPrim->position).y + (short)(iVar5 * sVar1 >> 0xc);
      iVar5 = (uint)(ushort)(fxPrim->position).z + (iVar5 * sVar2 >> 0xc);
      (fxPrim->position).z = (short)iVar5;
      if (iVar5 * 0x10000 >> 0x10 < (int)fxPrim->work0) {
        fxPrim->timeToLive = 6;
        fxPrim->flags = fxPrim->flags | 2;
        (fxPrim->position).z = fxPrim->work0;
      }
      local_20 = fxPrim->work3;
      iVar5 = (int)local_20;
      if (iVar5 != 0) {
        p_Var4 = fxPrim->matrix;
        iVar7 = (int)local_1e;
        iVar6 = (int)local_1c;
        local_18.vx = (short)(iVar5 * (p_Var4->lwTransform).m[0] >> 0xc) +
                      (short)(iVar7 * (p_Var4->lwTransform).m[1] >> 0xc) +
                      (short)(iVar6 * (p_Var4->lwTransform).m[2] >> 0xc);
        p_Var4 = fxPrim->matrix;
        local_18.vy = (short)(iVar5 * (p_Var4->lwTransform).m[3] >> 0xc) +
                      (short)(iVar7 * (p_Var4->lwTransform).m[4] >> 0xc) +
                      (short)(iVar6 * (p_Var4->lwTransform).m[5] >> 0xc);
        p_Var4 = fxPrim->matrix;
        local_18.vz = (short)(iVar5 * (p_Var4->lwTransform).m[6] >> 0xc) +
                      (short)(iVar7 * (p_Var4->lwTransform).m[7] >> 0xc) +
                      (short)(iVar6 * (p_Var4->lwTransform).m[8] >> 0xc);
        RotMatrix(&local_18,&MStack64);
        MulMatrix2(&MStack64,&fxPrim->matrix->lwTransform);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DFacadeProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 576, offset 0x80042f78
	/* begin block 1 */
		// Start line: 577
		// Start offset: 0x80042F78

		/* begin block 1.1 */
			// Start line: 589
			// Start offset: 0x80042FD0
			// Variables:
		// 		struct MATRIX *swTransform; // $v1
		/* end block 1.1 */
		// End offset: 0x80042FD0
		// End Line: 590

		/* begin block 1.2 */
			// Start line: 749
			// Start offset: 0x800430DC
			// Variables:
		// 		struct _Rotation rot; // stack offset -16
		/* end block 1.2 */
		// End offset: 0x8004313C
		// End Line: 757
	/* end block 1 */
	// End offset: 0x8004313C
	// End Line: 766

	/* begin block 2 */
		// Start line: 1114
	/* end block 2 */
	// End Line: 1115

/* File: C:\kain2\game\FX.C */

void FX_DFacadeProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  char cVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  short sVar7;
  
  if (0 < fxPrim->timeToLive) {
    fxPrim->timeToLive = fxPrim->timeToLive + -1;
  }
  if (fxPrim->timeToLive == 0) {
    FX_Die(fxPrim,fxTracker);
  }
  else {
    if ((fxPrim->flags & 0x20U) == 0) {
      if ((fxPrim->flags & 2U) == 0) {
        sVar3 = *(short *)((int)&fxPrim->duo + 8);
        sVar7 = *(short *)((int)&fxPrim->duo + 10);
        *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + *(short *)((int)&fxPrim->duo + 6);
        *(short *)((int)&fxPrim->duo + 2) = *(short *)((int)&fxPrim->duo + 2) + sVar3;
        sVar3 = (fxPrim->position).x;
        sVar4 = *(short *)&fxPrim->duo;
        *(short *)((int)&fxPrim->duo + 4) = *(short *)((int)&fxPrim->duo + 4) + sVar7;
        (fxPrim->position).y = (fxPrim->position).y + *(short *)((int)&fxPrim->duo + 2);
        sVar7 = *(short *)((int)&fxPrim->duo + 4);
        (fxPrim->position).x = sVar3 + sVar4;
        uVar6 = fxPrim->flags;
        sVar7 = (fxPrim->position).z + sVar7;
        (fxPrim->position).z = sVar7;
        if (((uVar6 & 0x100) != 0) && (sVar7 <= fxPrim->work0)) {
          uVar6 = fxPrim->flags;
          (fxPrim->position).z = fxPrim->work0;
          fxPrim->flags = uVar6 | 2;
        }
      }
    }
    else {
      iVar5 = *(int *)(*(int *)&fxPrim->duo + 0x40) + *(int *)((int)&fxPrim->duo + 4) * 0x20;
      (fxPrim->position).x = *(short *)(iVar5 + 0x14);
      (fxPrim->position).y = *(short *)(iVar5 + 0x18);
      (fxPrim->position).z = *(short *)(iVar5 + 0x1c);
    }
    uVar6 = fxPrim->matrix->flags;
    if (((uVar6 & 2) == 0) && (fxPrim->matrix->flags = uVar6 | 2, (fxPrim->flags & 0x80U) != 0)) {
      cVar1 = *(char *)&fxPrim->work3;
      cVar2 = *(char *)((int)&fxPrim->work3 + 1);
      RotMatrixX((int)*(char *)((int)&fxPrim->work2 + 1) << 2,&fxPrim->matrix->lwTransform);
      RotMatrixY((int)(short)((int)cVar1 << 2),&fxPrim->matrix->lwTransform);
      RotMatrixZ((int)(short)((int)cVar2 << 2),&fxPrim->matrix->lwTransform);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// struct _FX_PRIM * /*$ra*/ _FX_BuildSingleFaceWithModel(struct _Model *model /*$a0*/, struct _MFace *mface /*$s6*/, struct SVECTOR *center /*$s7*/, struct SVECTOR *vel /*$fp*/, struct SVECTOR *accl /*stack 16*/, struct _FXTracker *fxTracker /*stack 20*/, TDRFuncPtr__FX_BuildSingleFaceWithModel6fxSetup fxSetup /*stack 24*/, TDRFuncPtr__FX_BuildSingleFaceWithModel7fxProcess fxProcess /*stack 28*/, struct _FX_MATRIX *fxMatrix /*stack 32*/, int timeToLive /*stack 36*/)
 // line 849, offset 0x8004314c
	/* begin block 1 */
		// Start line: 850
		// Start offset: 0x8004314C
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s1
	// 		struct _MVertex *vertexList; // $s3
	/* end block 1 */
	// End offset: 0x80043214
	// End Line: 878

	/* begin block 2 */
		// Start line: 1650
	/* end block 2 */
	// End Line: 1651

/* File: C:\kain2\game\FX.C */

_FX_PRIM *
_FX_BuildSingleFaceWithModel
          (_Model *model,_MFace *mface,undefined center,undefined vel,undefined1 accl,
          _FXTracker *fxTracker,TDRFuncPtr__FX_BuildSingleFaceWithModel6fxSetup fxSetup,
          TDRFuncPtr__FX_BuildSingleFaceWithModel7fxProcess fxProcess,_FX_MATRIX *fxMatrix,
          int timeToLive)

{
  _FX_PRIM *node;
  undefined3 in_register_00000019;
  undefined3 in_register_0000001d;
  _MVertex *p_Var1;
  
  p_Var1 = model->vertexList;
  if ((fxMatrix == (_FX_MATRIX *)0x0) &&
     (fxMatrix = FX_GetMatrix(fxTracker), fxMatrix == (_FX_MATRIX *)0x0)) {
    return (_FX_PRIM *)0x0;
  }
  node = FX_GetPrim(fxTracker);
  if (node != (_FX_PRIM *)0x0) {
    if (fxSetup != (TDRFuncPtr__FX_BuildSingleFaceWithModel6fxSetup)0x0) {
      (*fxSetup)(node,fxProcess,fxMatrix,0,mface,p_Var1,CONCAT31(in_register_00000019,center),
                 CONCAT31(in_register_0000001d,vel),_accl,fxTracker,(int)(short)timeToLive);
    }
    LIST_InsertFunc(&fxTracker->usedPrimList,(NodeType *)node);
  }
  return node;
}



// decompiled code
// original method signature: 
// struct _FX_PRIM * /*$ra*/ FX_BuildSingleFaceWithModel(struct _Model *model /*$a0*/, struct _MFace *mface /*$a1*/, struct SVECTOR *center /*$a2*/, struct SVECTOR *vel /*$a3*/, struct SVECTOR *accl /*stack 16*/, struct _FXTracker *fxTracker /*stack 20*/, TDRFuncPtr_FX_BuildSingleFaceWithModel6fxSetup fxSetup /*stack 24*/, TDRFuncPtr_FX_BuildSingleFaceWithModel7fxProcess fxProcess /*stack 28*/, int timeToLive /*stack 32*/)
 // line 883, offset 0x80043248
	/* begin block 1 */
		// Start line: 1718
	/* end block 1 */
	// End Line: 1719

/* File: C:\kain2\game\FX.C */

_FX_PRIM *
FX_BuildSingleFaceWithModel
          (_Model *model,_MFace *mface,undefined1 center,undefined1 vel,undefined1 accl,
          _FXTracker *fxTracker,TDRFuncPtr_FX_BuildSingleFaceWithModel6fxSetup fxSetup,
          TDRFuncPtr_FX_BuildSingleFaceWithModel7fxProcess fxProcess,int timeToLive)

{
  _FX_PRIM *p_Var1;
  
  p_Var1 = _FX_BuildSingleFaceWithModel
                     (model,mface,center,vel,accl,fxTracker,
                      (TDRFuncPtr__FX_BuildSingleFaceWithModel6fxSetup)fxSetup,
                      (TDRFuncPtr__FX_BuildSingleFaceWithModel7fxProcess)fxProcess,(_FX_MATRIX *)0x0
                      ,(int)(short)timeToLive);
  return p_Var1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _FX_SetupLighting(struct _Instance *instance /*$s0*/)
 // line 910, offset 0x80043298
	/* begin block 1 */
		// Start line: 911
		// Start offset: 0x80043298
		// Variables:
	// 		struct MATRIX lm; // stack offset -40
	/* end block 1 */
	// End offset: 0x80043298
	// End Line: 911

	/* begin block 2 */
		// Start line: 1814
	/* end block 2 */
	// End Line: 1815

/* File: C:\kain2\game\FX.C */

void _FX_SetupLighting(_Instance *instance)

{
  MATRIX MStack40;
  
  LIGHT_PresetInstanceLight(instance,0x800,0xd8);
  MulMatrix0(&MStack40,instance->matrix + instance->lightMatrix,&MStack40);
  SetLightMatrix(&MStack40);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ _FX_DoLighting(struct _MFace *mface /*$a0*/)
 // line 921, offset 0x800432e8
	/* begin block 1 */
		// Start line: 922
		// Start offset: 0x800432E8
		// Variables:
	// 		long modelDQP; // $a2
	// 		long color; // stack offset -8
	// 		struct TextureMT3 *texture; // $a1
	/* end block 1 */
	// End offset: 0x800433F4
	// End Line: 954

	/* begin block 2 */
		// Start line: 1770
	/* end block 2 */
	// End Line: 1771

/* File: C:\kain2\game\FX.C */

long _FX_DoLighting(_MFace *mface)

{
  byte bVar1;
  undefined4 in_zero;
  undefined4 in_at;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint local_8;
  
  bVar1 = mface->flags;
  if ((bVar1 & 2) == 0) {
    if ((bVar1 & 8) == 0) {
      setCopReg(2,in_zero,*(undefined4 *)(gNormalList + mface->normal));
      setCopReg(2,in_at,*(undefined4 *)&gNormalList[mface->normal].z);
      setCopReg(2,0,mface->color);
      setCopReg(2,0x4000,0);
      copFunction(2,0xe80413);
      local_8 = getCopReg(2,0x16);
    }
    else {
      local_8 = mface->color;
    }
    uVar2 = local_8 & 0xffffff | 0x20000000;
    uVar3 = mface->color;
  }
  else {
    iVar4 = mface->color;
    if ((bVar1 & 8) == 0) {
      setCopReg(2,in_zero,*(undefined4 *)(gNormalList + mface->normal));
      setCopReg(2,in_at,*(undefined4 *)&gNormalList[mface->normal].z);
      setCopReg(2,0,*(undefined4 *)(iVar4 + 0xc));
      setCopReg(2,0x4000,0);
      copFunction(2,0xe80413);
      local_8 = getCopReg(2,0x16);
    }
    else {
      local_8 = *(uint *)(iVar4 + 0xc);
    }
    uVar2 = local_8 & 0xffffff | 0x24000000;
    uVar3 = *(uint *)(iVar4 + 0xc);
  }
  return uVar2 | uVar3 & 0x3000000;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _FX_BuildSegmentedSplinters(struct _Instance *instance /*stack 0*/, struct SVECTOR *center /*stack 4*/, struct SVECTOR *vel /*stack 8*/, struct SVECTOR *accl /*stack 12*/, struct FXSplinter *splintDef /*stack 16*/, struct _FXTracker *fxTracker /*stack 20*/, TDRFuncPtr__FX_BuildSegmentedSplinters6fxSetup fxSetup /*stack 24*/, TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess fxProcess /*stack 28*/, int shardFlags /*stack 32*/)
 // line 969, offset 0x80043400
	/* begin block 1 */
		// Start line: 970
		// Start offset: 0x80043400
		// Variables:
	// 		long j; // $s4
	// 		long maxTimeToLive; // stack offset -80
	// 		long faceSkip; // stack offset -76
	// 		long numFaces; // $v0
	// 		struct _MFace *mface; // $s5
	// 		struct _MFace *endMFace; // stack offset -72
	// 		struct _Model *model; // stack offset -68
	// 		struct _MVertex *vertexList; // stack offset -64
	// 		struct _MFace *faceList; // $s0
	// 		struct _FX_MATRIX *fxMatrix; // $s3
	// 		struct _FX_MATRIX (*fxMatList[60]); // stack offset -960
	// 		struct _SVector veloc[60]; // stack offset -720
	// 		struct _SVector *curVel; // $s7
	// 		int lastFxMat; // $fp
	// 		unsigned char matIdx[128]; // stack offset -240
	// 		struct _FX_PRIM *fxPrim; // $s2
	// 		struct _SVector *vertex0; // $s0
	// 		struct _SVector *vertex1; // $s1
	// 		struct _SVector *vertex2; // $s4
	// 		struct _SVector *poolOfVertices; // stack offset -60
	// 		long *vtxSegment; // stack offset -56
	// 		struct _Vector Center; // stack offset -112
	// 		int seg0; // $s6
	// 		int seg1; // $a0
	// 		struct _SVector offset; // stack offset -96

		/* begin block 1.1 */
			// Start line: 1052
			// Start offset: 0x800435F0
			// Variables:
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $a1
		// 		short _y1; // $a3
		// 		short _z1; // $a2
		// 		struct _SVector *_v; // stack offset -48
		// 		struct _Vector *_v1; // $a2
		/* end block 1.1 */
		// End offset: 0x800435F0
		// End Line: 1052

		/* begin block 1.2 */
			// Start line: 1065
			// Start offset: 0x80043684
		/* end block 1.2 */
		// End offset: 0x80043744
		// End Line: 1076

		/* begin block 1.3 */
			// Start line: 1129
			// Start offset: 0x80043A3C
			// Variables:
		// 		short _x0; // $a1
		// 		short _y0; // $v1
		// 		short _z0; // $v0
		// 		short _x1; // $a0
		// 		short _y1; // $a3
		// 		short _z1; // $a2
		// 		struct _Position *_v0; // $v0
		// 		struct _Vector *_v1; // $a2
		/* end block 1.3 */
		// End offset: 0x80043A3C
		// End Line: 1129

		/* begin block 1.4 */
			// Start line: 1158
			// Start offset: 0x80043B78
			// Variables:
		// 		struct TextureMT3 *texture; // $v1
		/* end block 1.4 */
		// End offset: 0x80043B78
		// End Line: 1158

		/* begin block 1.5 */
			// Start line: 1188
			// Start offset: 0x80043C44
		/* end block 1.5 */
		// End offset: 0x80043CA4
		// End Line: 1193

		/* begin block 1.6 */
			// Start line: 1210
			// Start offset: 0x80043D18
		/* end block 1.6 */
		// End offset: 0x80043D60
		// End Line: 1216
	/* end block 1 */
	// End offset: 0x80043E54
	// End Line: 1236

	/* begin block 2 */
		// Start line: 1868
	/* end block 2 */
	// End Line: 1869

	/* begin block 3 */
		// Start line: 1898
	/* end block 3 */
	// End Line: 1899

/* File: C:\kain2\game\FX.C */

void _FX_BuildSegmentedSplinters
               (_Instance *instance,undefined center,undefined vel,undefined accl,
               FXSplinter *splintDef,_FXTracker *fxTracker,
               TDRFuncPtr__FX_BuildSegmentedSplinters6fxSetup fxSetup,
               TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess fxProcess,int shardFlags)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  _FX_MATRIX *p_Var5;
  int iVar6;
  int iVar7;
  _FX_PRIM *fxPrim;
  uint uVar8;
  long lVar9;
  short sVar10;
  int iVar11;
  uint uVar12;
  undefined3 in_register_00000015;
  undefined3 in_register_00000019;
  short *psVar13;
  undefined3 in_register_0000001d;
  _MFace *mface;
  int iVar14;
  _SVector *p_Var15;
  _SVector *p_Var16;
  int iVar17;
  _SVector *p_Var18;
  _MFace *p_Var19;
  undefined2 *puVar20;
  int iVar21;
  byte bVar22;
  _FX_MATRIX *local_3c0 [60];
  undefined auStack720 [480];
  byte abStack240 [128];
  short local_70 [2];
  short local_6c;
  short local_68;
  _Normal local_60;
  ushort local_58;
  int local_50;
  int local_4c;
  _MFace *local_48;
  _Model *local_44;
  _MVertex *local_40;
  _SVector *local_3c;
  _SVector *local_38;
  undefined *local_34;
  _Normal *local_30;
  
  psVar13 = (short *)CONCAT31(in_register_00000019,vel);
  local_3c = DAT_800d2108;
  local_38 = DAT_800d2108 + 0x210;
  local_44 = instance->object->modelList[instance->currentModel];
  local_58 = (ushort)shardFlags;
  local_40 = local_44->vertexList;
  mface = local_44->faceList;
  PIPE3D_TransformVerticesToWorld(instance,DAT_800d2108,(long *)local_38,(_Vector *)local_70);
  if (splintDef == (FXSplinter *)0x0) {
    local_50 = 0x20;
  }
  else {
    local_50 = (int)splintDef->lifetime;
  }
  memset();
  _FX_SetupLighting(instance);
  if (splintDef == (FXSplinter *)0x0) {
    local_4c = 1;
  }
  else {
    local_4c = local_44->numFaces / (int)splintDef->faceLimit + 1;
  }
  iVar21 = 0;
  local_48 = mface + local_44->numFaces;
  if (mface < mface + local_44->numFaces) {
    local_34 = auStack720;
    local_30 = &local_60;
    do {
      iVar11 = *(int *)(&local_38->x + (uint)(mface->face).v2 * 2);
      if (*(int *)(&local_38->x + (uint)(mface->face).v1 * 2) <
          *(int *)(&local_38->x + (uint)(mface->face).v2 * 2)) {
        iVar11 = *(int *)(&local_38->x + (uint)(mface->face).v1 * 2);
      }
      if (*(int *)(&local_38->x + (uint)(mface->face).v0 * 2) < iVar11) {
        iVar11 = *(int *)(&local_38->x + (uint)(mface->face).v0 * 2);
      }
      if (abStack240[iVar11] == 0xff) {
        if (iVar21 < 0x3c) {
          p_Var5 = FX_GetMatrix(fxTracker);
          if (p_Var5 == (_FX_MATRIX *)0x0) {
            if (iVar21 == 0) {
              return;
            }
            goto LAB_80043888;
          }
          local_3c0[iVar21] = p_Var5;
          bVar22 = (byte)iVar21;
          local_60.y = *(short *)(instance->matrix[iVar11].t + 1);
          local_60.z = *(short *)(instance->matrix[iVar11].t + 2);
          local_60.x = *(short *)instance->matrix[iVar11].t - local_70[0];
          local_30->y = local_30->y - local_6c;
          local_30->z = local_30->z - local_68;
          MATH3D_Normalize(local_30);
          if (splintDef == (FXSplinter *)0x0) {
            iVar17 = rand();
            puVar20 = (undefined2 *)(local_34 + iVar21 * 8);
            iVar7 = iVar17;
            if (iVar17 < 0) {
              iVar7 = iVar17 + 7;
            }
            *puVar20 = (short)((int)local_60.x * (iVar17 + (iVar7 >> 3) * -8 + 0x1a) >> 0xc);
            iVar17 = rand();
            iVar7 = iVar17;
            if (iVar17 < 0) {
              iVar7 = iVar17 + 7;
            }
            puVar20[1] = (short)((int)local_60.y * (iVar17 + (iVar7 >> 3) * -8 + 0x1a) >> 0xc);
            iVar17 = rand();
            iVar7 = iVar17;
            if (iVar17 < 0) {
              iVar7 = iVar17 + 7;
            }
            puVar20[2] = (short)((int)local_60.z * (iVar17 + (iVar7 >> 3) * -8 + 0x2e) >> 0xc);
          }
          else {
            iVar7 = (uint)(ushort)splintDef->chunkVelXY - (uint)(ushort)splintDef->chunkVelRng;
            iVar17 = (int)((uint)(ushort)splintDef->chunkVelRng << 0x11) >> 0x10;
            if (iVar17 == 0) {
              iVar7 = iVar7 * 0x10000 >> 0x10;
              puVar20 = (undefined2 *)(local_34 + iVar21 * 8);
              *puVar20 = (short)(local_60.x * iVar7 >> 0xc);
              puVar20[1] = (short)(local_60.y * iVar7 >> 0xc);
              puVar20[2] = (short)((int)local_60.z * (int)splintDef->chunkVelZ >> 0xc);
            }
            else {
              iVar6 = rand();
              iVar14 = iVar7 * 0x10000 >> 0x10;
              puVar20 = (undefined2 *)(local_34 + iVar21 * 8);
              *puVar20 = (short)((int)local_60.x * (iVar14 + iVar6 % iVar17) >> 0xc);
              iVar7 = rand();
              puVar20[1] = (short)((int)local_60.y * (iVar14 + iVar7 % iVar17) >> 0xc);
              uVar1 = splintDef->chunkVelZ;
              uVar2 = splintDef->chunkVelRng;
              iVar7 = rand();
              puVar20[2] = (short)((int)local_60.z *
                                   (((int)(((uint)uVar1 - (uint)uVar2) * 0x10000) >> 0x10) +
                                   iVar7 % iVar17) >> 0xc);
            }
          }
          puVar20 = (undefined2 *)(local_34 + iVar21 * 8);
          if ((int)((uint)(ushort)puVar20[2] << 0x10) < 0) {
            puVar20[2] = 0;
          }
          iVar21 = iVar21 + 1;
        }
        else {
LAB_80043888:
          iVar7 = rand();
          iVar7 = iVar7 % iVar21;
          bVar22 = (byte)iVar7;
          p_Var5 = local_3c0[iVar7];
          puVar20 = (undefined2 *)(local_34 + iVar7 * 8);
        }
        abStack240[iVar11] = bVar22;
      }
      else {
        uVar8 = (uint)abStack240[iVar11];
        puVar20 = (undefined2 *)(local_34 + uVar8 * 8);
        p_Var5 = local_3c0[uVar8];
      }
      (p_Var5->lwTransform).m[0] = identityMatrix[0][0];
      (p_Var5->lwTransform).m[1] = identityMatrix[0][1];
      (p_Var5->lwTransform).m[2] = identityMatrix[0][2];
      (p_Var5->lwTransform).m[3] = identityMatrix[1][0];
      (p_Var5->lwTransform).m[4] = identityMatrix[1][1];
      (p_Var5->lwTransform).m[5] = identityMatrix[1][2];
      (p_Var5->lwTransform).m[6] = identityMatrix[2][0];
      (p_Var5->lwTransform).m[7] = identityMatrix[2][1];
      (p_Var5->lwTransform).m[8] = identityMatrix[2][2];
      (p_Var5->lwTransform).t[0] = instance->matrix[iVar11].t[0];
      (p_Var5->lwTransform).t[1] = instance->matrix[iVar11].t[1];
      (p_Var5->lwTransform).t[2] = instance->matrix[iVar11].t[2];
      p_Var15 = local_3c + (mface->face).v0;
      p_Var16 = local_3c + (mface->face).v1;
      p_Var18 = local_3c + (mface->face).v2;
      fxPrim = FX_GetPrim(fxTracker);
      p_Var19 = local_48;
      if (fxPrim != (_FX_PRIM *)0x0) {
        if (fxSetup == (TDRFuncPtr__FX_BuildSegmentedSplinters6fxSetup)0x0) {
          (fxPrim->position).x = *(short *)(p_Var5->lwTransform).t;
          (fxPrim->position).y = *(short *)((p_Var5->lwTransform).t + 1);
          (fxPrim->position).z = *(short *)((p_Var5->lwTransform).t + 2);
          sVar4 = (fxPrim->position).z;
          local_60.x = (fxPrim->position).x - local_70[0];
          local_30->y = (fxPrim->position).y - local_6c;
          local_30->z = sVar4 - local_68;
          (fxPrim->v0).x = p_Var15->x - local_60.x;
          (fxPrim->v0).y = p_Var15->y - local_60.y;
          (fxPrim->v0).z = p_Var15->z - local_60.z;
          (fxPrim->v1).x = p_Var16->x - local_60.x;
          (fxPrim->v1).y = p_Var16->y - local_60.y;
          (fxPrim->v1).z = p_Var16->z - local_60.z;
          (fxPrim->v2).x = p_Var18->x - local_60.x;
          (fxPrim->v2).y = p_Var18->y - local_60.y;
          sVar4 = p_Var18->z;
          fxPrim->matrix = p_Var5;
          (fxPrim->v2).z = sVar4 - local_60.z;
          FX_AniTexSetup(fxPrim,mface,local_44,fxTracker);
          if ((local_58 & 0x40) == 0) {
            lVar9 = _FX_DoLighting(mface);
            fxPrim->color = lVar9;
          }
          else {
            if ((mface->flags & 2) == 0) {
              uVar12 = mface->color & 0xffffff;
              fxPrim->color = uVar12;
              uVar12 = uVar12 | 0x20000000;
              uVar8 = mface->color;
            }
            else {
              iVar11 = mface->color;
              uVar12 = *(uint *)(iVar11 + 0xc) & 0xffffff;
              fxPrim->color = uVar12;
              uVar12 = uVar12 | 0x24000000;
              uVar8 = *(uint *)(iVar11 + 0xc);
            }
            fxPrim->color = uVar12 | uVar8 & 0x3000000;
          }
          if (fxProcess == (TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess)0x0) {
            *(code **)&fxPrim->process = FX_ShatterProcess;
          }
          else {
            *(TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess *)&fxPrim->process = fxProcess;
          }
          *(undefined2 *)&fxPrim->duo = *puVar20;
          *(undefined2 *)((int)&fxPrim->duo + 2) = puVar20[1];
          *(undefined2 *)((int)&fxPrim->duo + 4) = puVar20[2];
          if (splintDef != (FXSplinter *)0x0) {
            sVar4 = splintDef->triVelRng;
            if ((int)sVar4 != 0) {
              sVar10 = -splintDef->triVelRng;
              iVar11 = rand();
              iVar7 = ((int)sVar4 << 0x11) >> 0x10;
              *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + sVar10 + (short)(iVar11 % iVar7);
              iVar11 = rand();
              *(short *)((int)&fxPrim->duo + 2) =
                   *(short *)((int)&fxPrim->duo + 2) + sVar10 + (short)(iVar11 % iVar7);
              iVar11 = rand();
              *(short *)((int)&fxPrim->duo + 4) =
                   *(short *)((int)&fxPrim->duo + 4) + sVar10 + (short)(iVar11 % iVar7);
            }
          }
          if (psVar13 != (short *)0x0) {
            *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + *psVar13;
            *(short *)((int)&fxPrim->duo + 2) = *(short *)((int)&fxPrim->duo + 2) + psVar13[1];
            *(short *)((int)&fxPrim->duo + 4) = *(short *)((int)&fxPrim->duo + 4) + psVar13[2];
          }
          *(undefined2 *)((int)&fxPrim->duo + 6) = 0;
          *(undefined2 *)((int)&fxPrim->duo + 8) = 0;
          fxPrim->work1 = 0x1000;
          fxPrim->timeToLive = local_50;
          if (splintDef == (FXSplinter *)0x0) {
            *(undefined2 *)((int)&fxPrim->duo + 10) = 0xfff8;
            iVar7 = rand();
            iVar11 = iVar7;
            if (iVar7 < 0) {
              iVar11 = iVar7 + 7;
            }
            fxPrim->work3 = (short)iVar7 + (short)(iVar11 >> 3) * -8 + -4;
          }
          else {
            sVar4 = splintDef->rotRateRng;
            if ((int)sVar4 == 0) {
              fxPrim->work3 = 0;
            }
            else {
              iVar11 = rand();
              fxPrim->work3 = (short)(iVar11 % (((int)sVar4 << 0x11) >> 0x10)) - sVar4;
            }
            *(short *)((int)&fxPrim->duo + 10) = splintDef->gravityZ;
          }
          sVar10 = (instance->shadowPosition).z + -0x32;
          fxPrim->work0 = sVar10;
          sVar4 = -0x7fff;
          if ((local_58 & 0x10) == 0) {
            sVar3 = (fxPrim->position).z;
            sVar4 = sVar3 + -0x32;
            if ((sVar10 <= (fxPrim->position).z) &&
               (sVar4 = sVar3 + -0x32, (instance->object->oflags & 0x200U) != 0)) goto LAB_80043e10;
          }
          fxPrim->work0 = sVar4;
        }
        else {
          (*fxSetup)(fxPrim,fxProcess,p_Var5,instance,mface,local_40,
                     CONCAT31(in_register_00000015,center),psVar13,
                     CONCAT31(in_register_0000001d,accl),fxTracker,0x1e);
        }
LAB_80043e10:
        LIST_InsertFunc(&fxTracker->usedPrimList,(NodeType *)fxPrim);
        p_Var19 = mface;
      }
      mface = p_Var19 + local_4c;
    } while (mface < local_48);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _FX_BuildNonSegmentedSplinters(struct _Instance *instance /*stack 0*/, struct SVECTOR *center /*stack 4*/, struct SVECTOR *vel /*stack 8*/, struct SVECTOR *accl /*stack 12*/, struct FXSplinter *splintDef /*stack 16*/, struct _FXTracker *fxTracker /*stack 20*/, TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup fxSetup /*stack 24*/, TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess fxProcess /*stack 28*/, int shardFlags /*stack 32*/)
 // line 1247, offset 0x80043e84
	/* begin block 1 */
		// Start line: 1248
		// Start offset: 0x80043E84
		// Variables:
	// 		long j; // $s2
	// 		long maxTimeToLive; // stack offset -72
	// 		long faceSkip; // stack offset -68
	// 		long numFaces; // $v0
	// 		struct _MFace *mface; // $s5
	// 		struct _MFace *endMFace; // stack offset -64
	// 		short whichMatrix; // $v0
	// 		struct _Model *model; // stack offset -60
	// 		struct _MVertex *vertexList; // stack offset -56
	// 		struct _MFace *faceList; // $s4
	// 		struct _FX_MATRIX *fxMatrix; // $s0
	// 		struct _FX_MATRIX (*fxMatList[4]); // stack offset -200
	// 		struct _SVector *curVel; // $s6
	// 		struct _FX_PRIM *fxPrim; // $s2
	// 		struct _SVector *vertex0; // $s1
	// 		struct _SVector *vertex1; // $s3
	// 		struct _SVector *vertex2; // $s4
	// 		struct _SVector *poolOfVertices; // $fp
	// 		struct MATRIX *swTransform; // $s1
	// 		struct MATRIX ourM; // stack offset -184
	// 		struct _Vector Center; // stack offset -152
	// 		struct _SVector offset; // stack offset -136
	// 		struct _Normal faceNorm; // stack offset -128
	// 		struct _SVector sv_temp; // stack offset -120
	// 		struct _SVector sv_vels[4]; // stack offset -112

		/* begin block 1.1 */
			// Start line: 1289
			// Start offset: 0x80043F98
			// Variables:
		// 		short start; // $v0
		/* end block 1.1 */
		// End offset: 0x800440C0
		// End Line: 1315

		/* begin block 1.2 */
			// Start line: 1350
			// Start offset: 0x8004427C
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $s3
		// 		struct _SVector *_v1; // $a1
		/* end block 1.2 */
		// End offset: 0x8004427C
		// End Line: 1350

		/* begin block 1.3 */
			// Start line: 1410
			// Start offset: 0x800445E4
			// Variables:
		// 		short _x0; // $a1
		// 		short _y0; // $v1
		// 		short _z0; // $v0
		// 		short _x1; // $a0
		// 		short _y1; // $a3
		// 		short _z1; // $a2
		// 		struct _SVector *_v; // stack offset -48
		// 		struct _Position *_v0; // $v0
		// 		struct _Vector *_v1; // $a2
		/* end block 1.3 */
		// End offset: 0x800445E4
		// End Line: 1410

		/* begin block 1.4 */
			// Start line: 1439
			// Start offset: 0x80044720
			// Variables:
		// 		struct TextureMT3 *texture; // $v1
		/* end block 1.4 */
		// End offset: 0x80044720
		// End Line: 1439

		/* begin block 1.5 */
			// Start line: 1469
			// Start offset: 0x800447DC
		/* end block 1.5 */
		// End offset: 0x800447DC
		// End Line: 1469

		/* begin block 1.6 */
			// Start line: 1495
			// Start offset: 0x80044928
		/* end block 1.6 */
		// End offset: 0x80044970
		// End Line: 1501
	/* end block 1 */
	// End offset: 0x80044A44
	// End Line: 1526

	/* begin block 2 */
		// Start line: 2770
	/* end block 2 */
	// End Line: 2771

/* WARNING: Could not reconcile some variable overlaps */
/* File: C:\kain2\game\FX.C */

void _FX_BuildNonSegmentedSplinters
               (_Instance *instance,undefined center,undefined vel,undefined accl,
               FXSplinter *splintDef,_FXTracker *fxTracker,
               TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup fxSetup,
               TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess fxProcess,int shardFlags)

{
  short sVar1;
  _SVector *p_Var2;
  short sVar3;
  int iVar4;
  _FX_MATRIX *p_Var5;
  uint uVar6;
  _FX_PRIM *fxPrim;
  uint uVar7;
  long lVar8;
  int iVar9;
  uint uVar10;
  undefined3 in_register_00000015;
  undefined4 *puVar11;
  undefined3 in_register_00000019;
  short *psVar12;
  undefined3 in_register_0000001d;
  int iVar13;
  ushort uVar14;
  _SVector *p_Var15;
  int iVar16;
  _SVector *p_Var17;
  _MFace *mface;
  _SVector *p_Var18;
  _MFace *p_Var19;
  _FX_MATRIX *local_c8 [4];
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  long local_a4;
  long local_a0;
  long local_9c;
  long local_98;
  long local_94;
  long local_90;
  short local_88;
  short local_86;
  short local_84;
  undefined2 local_80;
  undefined2 local_7e;
  short local_7c;
  short local_78;
  short local_76;
  short local_74;
  undefined4 local_70;
  undefined *local_6c;
  undefined *local_68;
  undefined *local_64;
  undefined4 local_60;
  undefined *local_5c;
  undefined4 local_58;
  undefined *local_54;
  ushort local_50;
  int local_48;
  int local_44;
  _MFace *local_40;
  _Model *local_3c;
  _MVertex *local_38;
  int local_34;
  short *local_30;
  
  p_Var2 = DAT_800d2108;
  psVar12 = (short *)CONCAT31(in_register_00000019,vel);
  local_3c = instance->object->modelList[instance->currentModel];
  local_38 = local_3c->vertexList;
  mface = local_3c->faceList;
  local_70 = DAT_800cfd8c;
  local_6c = PTR_LAB_800cfd90;
  local_68 = PTR_DAT_800cfd94;
  local_64 = PTR_LAB_800cfd98;
  local_60 = PTR_DAT_800cfd9c;
  local_5c = PTR_LAB_800cfda0;
  local_58 = DAT_800cfda4;
  local_54 = PTR_LAB_800cfda8;
  local_50 = (ushort)shardFlags;
  PIPE3D_TransformVerticesToWorld
            (instance,DAT_800d2108,(long *)(DAT_800d2108 + 0x210),(_Vector *)&local_98);
  if (splintDef == (FXSplinter *)0x0) {
    iVar13 = rand();
    iVar4 = iVar13;
    if (iVar13 < 0) {
      iVar4 = iVar13 + 7;
    }
    local_70 = local_70 & 0xffff0000 |
               (uint)(ushort)((short)local_70 + -4 + (short)iVar13 + (short)(iVar4 >> 3) * -8);
    iVar13 = rand();
    iVar4 = iVar13;
    if (iVar13 < 0) {
      iVar4 = iVar13 + 7;
    }
    local_68 = (undefined *)
               ((uint)local_68 & 0xffff0000 |
               (uint)(ushort)((short)local_68 + -4 + (short)iVar13 + (short)(iVar4 >> 3) * -8));
    iVar13 = rand();
    iVar4 = iVar13;
    if (iVar13 < 0) {
      iVar4 = iVar13 + 7;
    }
    local_60 = (undefined *)
               ((uint)local_60 & 0xffff |
               (uint)(ushort)(local_60._2_2_ + -4 + (short)iVar13 + (short)(iVar4 >> 3) * -8) <<
               0x10);
    iVar13 = rand();
    iVar4 = iVar13;
    if (iVar13 < 0) {
      iVar4 = iVar13 + 7;
    }
    local_58 = local_58 & 0xffff |
               (uint)(ushort)(local_58._2_2_ + -4 + (short)iVar13 + (short)(iVar4 >> 3) * -8) <<
               0x10;
    local_48 = 0x20;
  }
  else {
    sVar3 = splintDef->chunkVelRng;
    uVar14 = splintDef->chunkVelXY - sVar3;
    if ((int)sVar3 == 0) {
      local_70 = local_70 & 0xffff0000 | (uint)uVar14;
      local_68 = (undefined *)((uint)local_68 & 0xffff0000 | (uint)(ushort)-uVar14);
      local_60 = (undefined *)((uint)local_60 & 0xffff | (uint)uVar14 << 0x10);
      local_58 = local_58 & 0xffff | (uint)(ushort)-uVar14 << 0x10;
      uVar14 = splintDef->chunkVelZ;
      local_6c = (undefined *)((uint)local_6c & 0xffff0000 | (uint)uVar14);
      local_64 = (undefined *)((uint)local_64 & 0xffff0000 | (uint)uVar14);
      local_5c = (undefined *)((uint)local_5c & 0xffff0000 | (uint)uVar14);
      local_54 = (undefined *)((uint)local_54 & 0xffff0000 | (uint)uVar14);
    }
    else {
      iVar4 = rand();
      iVar13 = ((int)sVar3 << 0x11) >> 0x10;
      local_70 = local_70 & 0xffff0000 | (uint)(ushort)(uVar14 + (short)(iVar4 % iVar13));
      iVar4 = rand();
      local_68 = (undefined *)
                 ((uint)local_68 & 0xffff0000 | (uint)(ushort)-(uVar14 + (short)(iVar4 % iVar13)));
      iVar4 = rand();
      local_60 = (undefined *)
                 ((uint)local_60 & 0xffff | (uint)(ushort)(uVar14 + (short)(iVar4 % iVar13)) << 0x10
                 );
      iVar4 = rand();
      local_58 = local_58 & 0xffff | (uint)(ushort)-(uVar14 + (short)(iVar4 % iVar13)) << 0x10;
      sVar3 = splintDef->chunkVelZ - splintDef->chunkVelRng;
      iVar4 = rand();
      local_6c = (undefined *)
                 ((uint)local_6c & 0xffff0000 | (uint)(ushort)(sVar3 + (short)(iVar4 % iVar13)));
      iVar4 = rand();
      local_64 = (undefined *)
                 ((uint)local_64 & 0xffff0000 | (uint)(ushort)(sVar3 + (short)(iVar4 % iVar13)));
      iVar4 = rand();
      local_5c = (undefined *)
                 ((uint)local_5c & 0xffff0000 | (uint)(ushort)(sVar3 + (short)(iVar4 % iVar13)));
      iVar4 = rand();
      local_54 = (undefined *)
                 ((uint)local_54 & 0xffff0000 | (uint)(ushort)(sVar3 + (short)(iVar4 % iVar13)));
    }
    local_48 = (int)splintDef->lifetime;
  }
  _FX_SetupLighting(instance);
  local_a8 = CONCAT22(local_a8._2_2_,0x1000);
  local_ac = 0;
  local_b0 = 0x1000;
  local_b4 = 0;
  local_b8 = 0x1000;
  local_a4 = local_98;
  local_a0 = local_94;
  local_9c = local_90;
  iVar4 = 0;
  do {
    p_Var5 = FX_GetMatrix(fxTracker);
    if (p_Var5 == (_FX_MATRIX *)0x0) {
      if (iVar4 == 0) {
        return;
      }
      iVar13 = rand();
      p_Var5 = local_c8[iVar13 % iVar4];
    }
    else {
      local_c8[iVar4] = p_Var5;
      *(undefined4 *)(p_Var5->lwTransform).m = local_b8;
      *(undefined4 *)((p_Var5->lwTransform).m + 2) = local_b4;
      *(undefined4 *)((p_Var5->lwTransform).m + 4) = local_b0;
      *(undefined4 *)((p_Var5->lwTransform).m + 6) = local_ac;
      *(undefined4 *)((p_Var5->lwTransform).m + 8) = local_a8;
      (p_Var5->lwTransform).t[0] = local_a4;
      (p_Var5->lwTransform).t[1] = local_a0;
      (p_Var5->lwTransform).t[2] = local_9c;
    }
    iVar13 = iVar4 * 8;
    puVar11 = &local_70 + iVar4 * 2;
    local_78 = *(short *)puVar11;
    local_76 = *(short *)((int)&local_70 + iVar13 + 2);
    local_74 = *(short *)(&local_6c + iVar4 * 2);
    *(short *)puVar11 =
         (short)((int)local_78 * (int)(short)local_b8 >> 0xc) +
         (short)((int)local_76 * (int)local_b8._2_2_ >> 0xc) +
         (short)((int)local_74 * (int)(short)local_b4 >> 0xc);
    *(short *)((int)&local_70 + iVar13 + 2) =
         (short)((int)local_78 * (int)local_b4._2_2_ >> 0xc) +
         (short)((int)local_76 * (int)(short)local_b0 >> 0xc) +
         (short)((int)local_74 * (int)local_b0._2_2_ >> 0xc);
    iVar16 = iVar4 + 1;
    *(short *)(&local_6c + iVar4 * 2) =
         (short)((int)local_78 * (int)(short)local_ac >> 0xc) +
         (short)((int)local_76 * (int)local_ac._2_2_ >> 0xc) +
         (short)((int)local_74 * (int)(short)local_a8 >> 0xc);
    (p_Var5->lwTransform).t[0] = (p_Var5->lwTransform).t[0] + (int)*(short *)puVar11 * 4;
    (p_Var5->lwTransform).t[1] =
         (p_Var5->lwTransform).t[1] +
         ((int)((uint)*(ushort *)((int)&local_70 + iVar13 + 2) << 0x10) >> 0xe);
    iVar4 = iVar16;
  } while (iVar16 < 4);
  if (splintDef == (FXSplinter *)0x0) {
    local_44 = 1;
  }
  else {
    if ((int)splintDef->faceLimit == 0) {
      local_44 = 1;
    }
    else {
      local_44 = local_3c->numFaces / (int)splintDef->faceLimit + 1;
    }
  }
  local_40 = mface + local_3c->numFaces;
  if (mface < mface + local_3c->numFaces) {
    local_34 = 0x55555556;
    local_30 = &local_88;
    do {
      p_Var15 = p_Var2 + (mface->face).v0;
      p_Var17 = p_Var2 + (mface->face).v1;
      p_Var18 = p_Var2 + (mface->face).v2;
      iVar4 = (int)p_Var15->x + (int)p_Var17->x + (int)p_Var18->x;
      iVar9 = (int)((ulonglong)((longlong)iVar4 * (longlong)local_34) >> 0x20) - (iVar4 >> 0x1f);
      local_80 = (short)iVar9;
      iVar4 = (int)p_Var15->y + (int)p_Var17->y + (int)p_Var18->y;
      iVar4 = (int)((ulonglong)((longlong)iVar4 * (longlong)local_34) >> 0x20) - (iVar4 >> 0x1f);
      local_7e = (short)iVar4;
      iVar13 = (int)p_Var15->z + (int)p_Var17->z + (int)p_Var18->z;
      iVar16 = iVar4 * 0x10000 >> 0x10;
      iVar9 = iVar9 * 0x10000 >> 0x10;
      iVar4 = iVar9;
      if (iVar9 < 0) {
        iVar4 = -iVar9;
      }
      local_7c = (short)((ulonglong)((longlong)iVar13 * (longlong)local_34) >> 0x20) -
                 (short)(iVar13 >> 0x1f);
      iVar13 = iVar16;
      if (iVar16 < 0) {
        iVar13 = -iVar16;
      }
      uVar6 = (uint)(iVar9 < 1);
      if ((iVar4 <= iVar13) && (uVar6 = 3, 0 < iVar16)) {
        uVar6 = 2;
      }
      p_Var5 = local_c8[uVar6];
      fxPrim = FX_GetPrim(fxTracker);
      p_Var19 = local_40;
      if (fxPrim != (_FX_PRIM *)0x0) {
        if (fxSetup == (TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup)0x0) {
          (fxPrim->position).x = *(short *)(p_Var5->lwTransform).t;
          (fxPrim->position).y = *(short *)((p_Var5->lwTransform).t + 1);
          (fxPrim->position).z = *(short *)((p_Var5->lwTransform).t + 2);
          sVar3 = (fxPrim->position).z;
          local_88 = (fxPrim->position).x - (short)local_98;
          local_30[1] = (fxPrim->position).y - (short)local_94;
          local_30[2] = sVar3 - (short)local_90;
          (fxPrim->v0).x = p_Var15->x - local_88;
          (fxPrim->v0).y = p_Var15->y - local_86;
          (fxPrim->v0).z = p_Var15->z - local_84;
          (fxPrim->v1).x = p_Var17->x - local_88;
          (fxPrim->v1).y = p_Var17->y - local_86;
          (fxPrim->v1).z = p_Var17->z - local_84;
          (fxPrim->v2).x = p_Var18->x - local_88;
          (fxPrim->v2).y = p_Var18->y - local_86;
          sVar3 = p_Var18->z;
          fxPrim->matrix = p_Var5;
          (fxPrim->v2).z = sVar3 - local_84;
          FX_AniTexSetup(fxPrim,mface,local_3c,fxTracker);
          if ((local_50 & 0x40) == 0) {
            lVar8 = _FX_DoLighting(mface);
            fxPrim->color = lVar8;
          }
          else {
            if ((mface->flags & 2) == 0) {
              uVar10 = mface->color & 0xffffff;
              fxPrim->color = uVar10;
              uVar10 = uVar10 | 0x20000000;
              uVar7 = mface->color;
            }
            else {
              iVar4 = mface->color;
              uVar10 = *(uint *)(iVar4 + 0xc) & 0xffffff;
              fxPrim->color = uVar10;
              uVar10 = uVar10 | 0x24000000;
              uVar7 = *(uint *)(iVar4 + 0xc);
            }
            fxPrim->color = uVar10 | uVar7 & 0x3000000;
          }
          if (fxProcess == (TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess)0x0) {
            *(code **)&fxPrim->process = FX_ShatterProcess;
          }
          else {
            *(TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess *)&fxPrim->process = fxProcess;
          }
          *(undefined2 *)&fxPrim->duo = *(undefined2 *)(&local_70 + uVar6 * 2);
          *(undefined2 *)((int)&fxPrim->duo + 2) = *(undefined2 *)((int)&local_70 + uVar6 * 8 + 2);
          *(undefined2 *)((int)&fxPrim->duo + 4) = *(undefined2 *)(&local_6c + uVar6 * 2);
          if (splintDef == (FXSplinter *)0x0) {
            iVar13 = rand();
            iVar4 = iVar13;
            if (iVar13 < 0) {
              iVar4 = iVar13 + 7;
            }
            *(short *)&fxPrim->duo =
                 *(short *)&fxPrim->duo + -4 + (short)iVar13 + (short)(iVar4 >> 3) * -8;
            iVar13 = rand();
            iVar4 = iVar13;
            if (iVar13 < 0) {
              iVar4 = iVar13 + 7;
            }
            *(short *)((int)&fxPrim->duo + 2) =
                 *(short *)((int)&fxPrim->duo + 2) + -4 + (short)iVar13 + (short)(iVar4 >> 3) * -8;
            iVar13 = rand();
            iVar4 = iVar13;
            if (iVar13 < 0) {
              iVar4 = iVar13 + 7;
            }
            sVar3 = *(short *)((int)&fxPrim->duo + 4) + -4 +
                    (short)iVar13 + (short)(iVar4 >> 3) * -8;
LAB_800448cc:
            *(short *)((int)&fxPrim->duo + 4) = sVar3;
          }
          else {
            sVar3 = splintDef->triVelRng;
            if ((int)sVar3 != 0) {
              sVar1 = -splintDef->triVelRng;
              iVar4 = rand();
              iVar13 = ((int)sVar3 << 0x11) >> 0x10;
              *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + sVar1 + (short)(iVar4 % iVar13);
              iVar4 = rand();
              *(short *)((int)&fxPrim->duo + 2) =
                   *(short *)((int)&fxPrim->duo + 2) + sVar1 + (short)(iVar4 % iVar13);
              iVar4 = rand();
              sVar3 = *(short *)((int)&fxPrim->duo + 4) + sVar1 + (short)(iVar4 % iVar13);
              goto LAB_800448cc;
            }
          }
          if (psVar12 != (short *)0x0) {
            *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + *psVar12;
            *(short *)((int)&fxPrim->duo + 2) = *(short *)((int)&fxPrim->duo + 2) + psVar12[1];
            *(short *)((int)&fxPrim->duo + 4) = *(short *)((int)&fxPrim->duo + 4) + psVar12[2];
          }
          *(undefined2 *)((int)&fxPrim->duo + 6) = 0;
          *(undefined2 *)((int)&fxPrim->duo + 8) = 0;
          if (splintDef == (FXSplinter *)0x0) {
            *(undefined2 *)((int)&fxPrim->duo + 10) = 0xfff8;
            iVar13 = rand();
            iVar4 = iVar13;
            if (iVar13 < 0) {
              iVar4 = iVar13 + 7;
            }
            fxPrim->work3 = (short)iVar13 + (short)(iVar4 >> 3) * -8 + -4;
          }
          else {
            sVar3 = splintDef->rotRateRng;
            if ((int)sVar3 == 0) {
              fxPrim->work3 = 0;
            }
            else {
              iVar4 = rand();
              fxPrim->work3 = (short)(iVar4 % (((int)sVar3 << 0x11) >> 0x10)) - sVar3;
            }
            *(short *)((int)&fxPrim->duo + 10) = splintDef->gravityZ;
          }
          fxPrim->work1 = 0x1000;
          fxPrim->timeToLive = local_48;
          sVar3 = -0x7fff;
          if ((local_50 & 0x10) == 0) {
            sVar3 = (instance->position).z -
                    instance->object->modelList[instance->currentModel]->maxRad;
          }
          fxPrim->work0 = sVar3;
        }
        else {
          (*fxSetup)(fxPrim,fxProcess,p_Var5,instance,mface,local_38,
                     CONCAT31(in_register_00000015,center),psVar12,
                     CONCAT31(in_register_0000001d,accl),fxTracker,0x1e);
        }
        LIST_InsertFunc(&fxTracker->usedPrimList,(NodeType *)fxPrim);
        p_Var19 = mface;
      }
      mface = p_Var19 + local_44;
    } while (mface < local_40);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _FX_BuildSplinters(struct _Instance *instance /*$s2*/, struct SVECTOR *center /*$s4*/, struct SVECTOR *vel /*$s5*/, struct SVECTOR *accl /*$s6*/, struct FXSplinter *splintDef /*stack 16*/, struct _FXTracker *fxTracker /*stack 20*/, TDRFuncPtr__FX_BuildSplinters6fxSetup fxSetup /*stack 24*/, TDRFuncPtr__FX_BuildSplinters7fxProcess fxProcess /*stack 28*/, int shardFlags /*stack 32*/)
 // line 1537, offset 0x80044a74
	/* begin block 1 */
		// Start line: 3749
	/* end block 1 */
	// End Line: 3750

/* File: C:\kain2\game\FX.C */

void _FX_BuildSplinters(_Instance *instance,undefined1 center,undefined1 vel,undefined1 accl,
                       FXSplinter *splintDef,_FXTracker *fxTracker,
                       TDRFuncPtr__FX_BuildSplinters6fxSetup fxSetup,
                       TDRFuncPtr__FX_BuildSplinters7fxProcess fxProcess,int shardFlags)

{
  long lVar1;
  
  lVar1 = MEMPACK_MemoryValidFunc((char *)instance->object);
  if (lVar1 != 0) {
    if (splintDef != (FXSplinter *)0x0) {
      shardFlags = (uint)(ushort)splintDef->flags | shardFlags;
      if ((int)splintDef->soundFx != 0) {
        SndPlay((int)splintDef->soundFx);
      }
    }
    if ((instance->object->modelList[instance->currentModel]->numSegments < 4) ||
       ((shardFlags & 0x20U) != 0)) {
      _FX_BuildNonSegmentedSplinters
                (instance,center,vel,accl,splintDef,fxTracker,
                 (TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup)fxSetup,
                 (TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess)fxProcess,
                 (int)(short)shardFlags);
    }
    else {
      _FX_BuildSegmentedSplinters
                (instance,center,vel,accl,splintDef,fxTracker,
                 (TDRFuncPtr__FX_BuildSegmentedSplinters6fxSetup)fxSetup,
                 (TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess)fxProcess,(int)(short)shardFlags)
      ;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _FX_Build(struct _Instance *instance /*$s0*/, struct SVECTOR *center /*$s2*/, struct SVECTOR *vel /*$s3*/, struct SVECTOR *accl /*$s4*/, struct _FXTracker *fxTracker /*stack 16*/, TDRFuncPtr__FX_Build5fxSetup fxSetup /*stack 20*/, TDRFuncPtr__FX_Build6fxProcess fxProcess /*stack 24*/, int shardFlags /*stack 28*/)
 // line 1562, offset 0x80044bc8
	/* begin block 1 */
		// Start line: 3800
	/* end block 1 */
	// End Line: 3801

/* File: C:\kain2\game\FX.C */

void _FX_Build(_Instance *instance,undefined1 center,undefined1 vel,undefined1 accl,
              _FXTracker *fxTracker,TDRFuncPtr__FX_Build5fxSetup fxSetup,
              TDRFuncPtr__FX_Build6fxProcess fxProcess,int shardFlags)

{
  long lVar1;
  
  lVar1 = MEMPACK_MemoryValidFunc((char *)instance->object);
  if (lVar1 != 0) {
    if (instance->object->modelList[instance->currentModel]->numSegments < 4) {
      _FX_BuildNonSegmentedSplinters
                (instance,center,vel,accl,(FXSplinter *)0x0,fxTracker,
                 (TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup)fxSetup,
                 (TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess)fxProcess,
                 (int)(short)shardFlags);
    }
    else {
      _FX_BuildSegmentedSplinters
                (instance,center,vel,accl,(FXSplinter *)0x0,fxTracker,
                 (TDRFuncPtr__FX_BuildSegmentedSplinters6fxSetup)fxSetup,
                 (TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess)fxProcess,(int)(short)shardFlags)
      ;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Build(struct _Instance *instance /*$a0*/, struct SVECTOR *center /*$a1*/, struct SVECTOR *vel /*$a2*/, struct SVECTOR *accl /*$a3*/, struct _FXTracker *fxTracker /*stack 16*/, TDRFuncPtr_FX_Build5fxSetup fxSetup /*stack 20*/, TDRFuncPtr_FX_Build6fxProcess fxProcess /*stack 24*/)
 // line 1737, offset 0x80044cdc
	/* begin block 1 */
		// Start line: 4154
	/* end block 1 */
	// End Line: 4155

/* File: C:\kain2\game\FX.C */

void FX_Build(_Instance *instance,undefined1 center,undefined1 vel,undefined1 accl,
             _FXTracker *fxTracker,TDRFuncPtr_FX_Build5fxSetup fxSetup,
             TDRFuncPtr_FX_Build6fxProcess fxProcess)

{
  _FX_Build(instance,center,vel,accl,fxTracker,(TDRFuncPtr__FX_Build5fxSetup)fxSetup,
            (TDRFuncPtr__FX_Build6fxProcess)fxProcess,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdatePos(struct _FX_PRIM *fxPrim /*$t2*/, struct _SVector *offset /*$t3*/, int spriteflag /*$a2*/)
 // line 1743, offset 0x80044d14
	/* begin block 1 */
		// Start line: 1744
		// Start offset: 0x80044D14

		/* begin block 1.1 */
			// Start line: 1744
			// Start offset: 0x80044D14
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a0
		// 		short _x1; // $a3
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a1
		/* end block 1.1 */
		// End offset: 0x80044D14
		// End Line: 1744
	/* end block 1 */
	// End offset: 0x80044E60
	// End Line: 1760

	/* begin block 2 */
		// Start line: 4166
	/* end block 2 */
	// End Line: 4167

/* File: C:\kain2\game\FX.C */

void FX_UpdatePos(_FX_PRIM *fxPrim,_SVector *offset,int spriteflag)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  
  sVar1 = offset->y;
  sVar2 = offset->z;
  (fxPrim->position).x = (fxPrim->position).x + offset->x;
  (fxPrim->position).y = (fxPrim->position).y + sVar1;
  (fxPrim->position).z = (fxPrim->position).z + sVar2;
  if ((spriteflag == 0) && ((fxPrim->flags & 0x10000U) != 0)) {
    (fxPrim->v0).x = (fxPrim->v0).x + offset->x;
    (fxPrim->v0).y = (fxPrim->v0).y + offset->y;
    (fxPrim->v0).z = (fxPrim->v0).z + offset->z;
    (fxPrim->v1).x = (fxPrim->v1).x + offset->x;
    (fxPrim->v1).y = (fxPrim->v1).y + offset->y;
    (fxPrim->v1).z = (fxPrim->v1).z + offset->z;
    (fxPrim->v2).x = (fxPrim->v2).x + offset->x;
    (fxPrim->v2).y = (fxPrim->v2).y + offset->y;
    uVar3 = fxPrim->flags;
    (fxPrim->v2).z = (fxPrim->v2).z + offset->z;
    if ((uVar3 & 8) != 0) {
      (fxPrim->v3).x = (fxPrim->v3).x + offset->x;
      (fxPrim->v3).y = (fxPrim->v3).y + offset->y;
      (fxPrim->v3).z = (fxPrim->v3).z + offset->z;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Relocate(struct _SVector *offset /*$s1*/)
 // line 1763, offset 0x80044e68
	/* begin block 1 */
		// Start line: 1764
		// Start offset: 0x80044E68
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct _FXTracker *fxTracker; // $s2
	// 		struct _FXGeneralEffect *currentEffect; // $a2

		/* begin block 1.1 */
			// Start line: 1792
			// Start offset: 0x80044F2C
			// Variables:
		// 		int i; // $a3
		// 		int end; // $t1
		// 		struct _FXRibbon *currentRibbon; // $t0
		/* end block 1.1 */
		// End offset: 0x80044FA4
		// End Line: 1802

		/* begin block 1.2 */
			// Start line: 1805
			// Start offset: 0x80044FB4
		/* end block 1.2 */
		// End offset: 0x80044FF0
		// End Line: 1809
	/* end block 1 */
	// End offset: 0x80045000
	// End Line: 1813

	/* begin block 2 */
		// Start line: 4207
	/* end block 2 */
	// End Line: 4208

/* File: C:\kain2\game\FX.C */

void FX_Relocate(_SVector *offset)

{
  byte bVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  _FX_PRIM *fxPrim;
  
  iVar5 = gFXT;
  fxPrim = *(_FX_PRIM **)(&DAT_00007994 + gFXT);
  while (fxPrim != (_FX_PRIM *)0x0) {
    FX_UpdatePos(fxPrim,offset,0);
    fxPrim = (_FX_PRIM *)(fxPrim->node).next;
  }
  fxPrim = *(_FX_PRIM **)(&DAT_0000799c + iVar5);
  while (piVar3 = FX_GeneralEffectTracker, fxPrim != (_FX_PRIM *)0x0) {
    FX_UpdatePos(fxPrim,offset,1);
    if ((code *)fxPrim->process == FX_WaterBubbleProcess) {
      fxPrim->timeToLive = fxPrim->timeToLive + (int)offset->z;
    }
    fxPrim = (_FX_PRIM *)(fxPrim->node).next;
  }
  while (piVar3 != (int *)0x0) {
    bVar1 = *(byte *)(piVar3 + 3);
    iVar5 = 0;
    if (bVar1 == 0) {
      sVar2 = *(short *)(piVar3 + 4);
      if ((int)(uint)bVar1 < (int)sVar2) {
        iVar4 = 0;
        do {
          *(short *)(iVar4 + piVar3[5]) = *(short *)(iVar4 + piVar3[5]) + offset->x;
          *(short *)(iVar4 + piVar3[5] + 2) = *(short *)(iVar4 + piVar3[5] + 2) + offset->y;
          iVar5 = iVar5 + 1;
          *(short *)(iVar4 + piVar3[5] + 4) = *(short *)(iVar4 + piVar3[5] + 4) + offset->z;
          iVar4 = iVar5 * 8;
        } while (iVar5 < (int)sVar2);
      }
    }
    else {
      if (bVar1 == 0x84) {
        *(short *)(piVar3 + 4) = *(short *)(piVar3 + 4) + offset->x;
        *(short *)((int)piVar3 + 0x12) = *(short *)((int)piVar3 + 0x12) + offset->y;
        *(short *)(piVar3 + 5) = *(short *)(piVar3 + 5) + offset->z;
      }
    }
    piVar3 = (int *)*piVar3;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdateTexturePointers(struct _FX_PRIM *fxPrim /*$a0*/, struct Object *oldObject /*$a1*/, long sizeOfObject /*$a2*/, long offset /*$a3*/)
 // line 1818, offset 0x80045018
	/* begin block 1 */
		// Start line: 4334
	/* end block 1 */
	// End Line: 4335

	/* begin block 2 */
		// Start line: 4335
	/* end block 2 */
	// End Line: 4336

/* File: C:\kain2\game\FX.C */

void FX_UpdateTexturePointers(_FX_PRIM *fxPrim,Object *oldObject,long sizeOfObject,long offset)

{
  AniTex *pAVar1;
  Object *pOVar2;
  AniTex *pAVar3;
  TextureMT3 *pTVar4;
  TextureMT3 *pTVar5;
  
  if (fxPrim != (_FX_PRIM *)0x0) {
    do {
      if ((fxPrim->flags & 1U) != 0) {
        pOVar2 = (Object *)fxPrim->texture;
        if ((oldObject <= pOVar2) && (pOVar2 <= (Object *)((int)&oldObject->oflags + sizeOfObject)))
        {
          pTVar4 = (TextureMT3 *)0x0;
          if (pOVar2 != (Object *)0x0) {
            pTVar4 = (TextureMT3 *)((int)&pOVar2->oflags + offset);
          }
          fxPrim->texture = pTVar4;
          if ((fxPrim->flags & 4U) != 0) {
            pTVar4 = (fxPrim->ani).texMem;
            pTVar5 = (TextureMT3 *)0x0;
            if (pTVar4 != (TextureMT3 *)0x0) {
              pTVar5 = (TextureMT3 *)(&pTVar4->u0 + offset);
            }
            pAVar3 = (fxPrim->ani).aniTextures;
            pAVar1 = (AniTex *)0x0;
            (fxPrim->ani).texMem = pTVar5;
            if (pAVar3 != (AniTex *)0x0) {
              pAVar1 = (AniTex *)((int)&pAVar3->numAniTextues + offset);
            }
            (fxPrim->ani).aniTextures = pAVar1;
          }
        }
      }
      fxPrim = (_FX_PRIM *)(fxPrim->node).next;
    } while (fxPrim != (_FX_PRIM *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_RelocateFXPointers(struct Object *oldObject /*$s3*/, struct Object *newObject /*$a1*/, long sizeOfObject /*$s2*/)
 // line 1836, offset 0x800450b4
	/* begin block 1 */
		// Start line: 1837
		// Start offset: 0x800450B4
		// Variables:
	// 		struct _FXTracker *fxTracker; // $s0
	// 		struct _FXGeneralEffect *currentEffect; // $a0
	// 		long offset; // $s1

		/* begin block 1.1 */
			// Start line: 1856
			// Start offset: 0x80045128
		/* end block 1.1 */
		// End offset: 0x80045158
		// End Line: 1859
	/* end block 1 */
	// End offset: 0x80045168
	// End Line: 1862

	/* begin block 2 */
		// Start line: 4370
	/* end block 2 */
	// End Line: 4371

/* File: C:\kain2\game\FX.C */

void FX_RelocateFXPointers(Object *oldObject,Object *newObject,long sizeOfObject)

{
  int iVar1;
  Object *pOVar2;
  int *piVar3;
  
  iVar1 = gFXT;
  newObject = (Object *)((int)newObject - (int)oldObject);
  FX_UpdateTexturePointers
            (*(_FX_PRIM **)(&DAT_00007994 + gFXT),oldObject,sizeOfObject,(long)newObject);
  FX_UpdateTexturePointers
            (*(_FX_PRIM **)(&DAT_0000799c + iVar1),oldObject,sizeOfObject,(long)newObject);
  if (FX_GeneralEffectTracker != (int *)0x0) {
    piVar3 = FX_GeneralEffectTracker;
    do {
      if (*(char *)(piVar3 + 3) == '\x01') {
        pOVar2 = (Object *)piVar3[4];
        if (((pOVar2 != (Object *)0x0) && (oldObject <= pOVar2)) &&
           (pOVar2 <= (Object *)((int)&oldObject->oflags + sizeOfObject))) {
          iVar1 = 0;
          if (pOVar2 != (Object *)0x0) {
            iVar1 = (int)pOVar2 + (int)newObject;
          }
          piVar3[4] = iVar1;
        }
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ProcessList(struct _FXTracker *fxTracker /*$s2*/)
 // line 1866, offset 0x80045184
	/* begin block 1 */
		// Start line: 1867
		// Start offset: 0x80045184
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $a0
	// 		struct _FX_PRIM *nextFXPrim; // $s0
	// 		struct _FX_MATRIX *fxMatrix; // $s0
	// 		struct _FX_MATRIX *nextFXMatrix; // $s1

		/* begin block 1.1 */
			// Start line: 1937
			// Start offset: 0x800452F8
			// Variables:
		// 		struct _FXGeneralEffect *currentEffect; // $a0
		// 		struct _FXGeneralEffect *nextEffect; // $s0
		/* end block 1.1 */
		// End offset: 0x8004531C
		// End Line: 1947
	/* end block 1 */
	// End offset: 0x80045360
	// End Line: 1954

	/* begin block 2 */
		// Start line: 4441
	/* end block 2 */
	// End Line: 4442

	/* begin block 3 */
		// Start line: 4454
	/* end block 3 */
	// End Line: 4455

/* File: C:\kain2\game\FX.C */

void FX_ProcessList(_FXTracker *fxTracker)

{
  int **ppiVar1;
  int iVar2;
  NodeType *node;
  NodeType *pNVar3;
  NodeType *pNVar4;
  int **ppiVar5;
  
  iVar2 = (int)(((uint)(ushort)FX_TimeCount + (uint)(ushort)DAT_800d2314) * 0x10000) >> 0x10;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  FX_Frames = (short)(iVar2 >> 0xc);
  pNVar4 = (fxTracker->usedMatrixList).next;
  FX_TimeCount = (short)((uint)(ushort)FX_TimeCount + (uint)(ushort)DAT_800d2314) +
                 FX_Frames * -0x1000;
  while (pNVar4 != (NodeType *)0x0) {
    pNVar3 = pNVar4[1].prev;
    node = (NodeType *)((uint)pNVar3 | 1);
    if (((uint)pNVar3 & 4) == 0) {
      node = (NodeType *)((uint)pNVar3 & 0xfffffffe);
    }
    pNVar4[1].prev = node;
    pNVar4[1].prev = (NodeType *)((uint)pNVar4[1].prev & 0xfffffffd);
    pNVar4 = pNVar4->next;
  }
  pNVar4 = (fxTracker->usedPrimList).next;
  while (node = pNVar4, node != (NodeType *)0x0) {
    pNVar3 = node[3].prev;
    pNVar4 = node->next;
    if (pNVar3 != (NodeType *)0x0) {
      pNVar3[1].prev = (NodeType *)((uint)pNVar3[1].prev | 1);
    }
    if (node[2].next != (NodeType *)0x0) {
      (*(code *)node[2].next)(node,fxTracker);
    }
  }
  pNVar4 = (fxTracker->usedPrimListSprite).next;
  while (node = pNVar4, node != (NodeType *)0x0) {
    pNVar4 = node->next;
    if (node[2].next != (NodeType *)0x0) {
      (*(code *)node[2].next)(node,fxTracker);
    }
  }
  pNVar4 = (fxTracker->usedMatrixList).next;
  while (node = pNVar4, ppiVar5 = (int **)FX_GeneralEffectTracker, node != (NodeType *)0x0) {
    pNVar4 = node->next;
    if (((uint)node[1].prev & 1) == 0) {
      LIST_DeleteFunc(node);
      LIST_InsertFunc(&fxTracker->freeMatrixList,node);
    }
  }
  while (ppiVar1 = ppiVar5, ppiVar1 != (int **)0x0) {
    ppiVar5 = (int **)*ppiVar1;
    if (ppiVar1[1] != (int *)0x0) {
      (*(code *)ppiVar1[1])(ppiVar1,fxTracker);
    }
  }
  if (FX_ConstrictStage == 1) {
    FX_ConstrictStage = 0;
  }
  if (snow_amount != 0) {
    FX_ContinueSnow(fxTracker);
  }
  if (rain_amount != 0) {
    FX_ContinueRain(fxTracker);
  }
  FX_UpdateWind(fxTracker);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawReaver(struct _PrimPool *primPool /*$v0*/, unsigned long **ot /*$s0*/, struct MATRIX *wcTransform /*$a3*/)
 // line 1957, offset 0x80045380
	/* begin block 1 */
		// Start line: 4646
	/* end block 1 */
	// End Line: 4647

/* File: C:\kain2\game\FX.C */

void FX_DrawReaver(_PrimPool *primPool,ulong **ot,undefined1 wcTransform)

{
  if (FX_reaver_instance != (_Instance *)0x0) {
    FX_SoulReaverWinding(FX_reaver_instance,primPool,ot,wcTransform);
    FX_SoulReaverBlade(FX_reaver_instance,ot);
  }
  FX_reaver_instance = (_Instance *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawList(struct _FXTracker *fxTracker /*stack 0*/, struct GameTracker *gameTracker /*$a1*/, unsigned long **ot /*$s5*/, struct MATRIX *wcTransform /*$s7*/)
 // line 1979, offset 0x800453cc
	/* begin block 1 */
		// Start line: 1980
		// Start offset: 0x800453CC
		// Variables:
	// 		struct TextureMT3 *texture; // $a1
	// 		struct _PrimPool *primPool; // $fp
	// 		long *prim; // $s1
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct _FX_PRIM *nextFXPrim; // $s6
	// 		struct SVECTOR sv0; // stack offset -104
	// 		struct SVECTOR sv1; // stack offset -96
	// 		struct SVECTOR sv2; // stack offset -88
	// 		long otz; // stack offset -52
	// 		long sz0; // stack offset -64
	// 		long sz1; // stack offset -60
	// 		long sz2; // stack offset -56
	// 		char whitec[4]; // stack offset -80
	// 		int sizex; // stack offset -48
	// 		int sizey; // $t5
	// 		int matrix_wc; // $t2

		/* begin block 1.1 */
			// Start line: 2001
			// Start offset: 0x80045450
			// Variables:
		// 		long flags; // $s2

			/* begin block 1.1.1 */
				// Start line: 2089
				// Start offset: 0x80045740
				// Variables:
			// 		struct _POLY_NG4 *ng4; // $a2

				/* begin block 1.1.1.1 */
					// Start line: 2091
					// Start offset: 0x80045740
					// Variables:
				// 		int n; // $a0
				// 		long *ptr; // $a1
				/* end block 1.1.1.1 */
				// End offset: 0x80045800
				// End Line: 2116
			/* end block 1.1.1 */
			// End offset: 0x80045800
			// End Line: 2138

			/* begin block 1.1.2 */
				// Start line: 2155
				// Start offset: 0x80045838
			/* end block 1.1.2 */
			// End offset: 0x80045838
			// End Line: 2157

			/* begin block 1.1.3 */
				// Start line: 2245
				// Start offset: 0x800459CC
				// Variables:
			// 		struct POLY_FT4 *ft4; // $a2
			// 		unsigned short uMin; // $t1
			// 		unsigned short uMax; // $t0
			// 		unsigned short vMin; // $a3
			// 		unsigned short vMax; // $v1
			/* end block 1.1.3 */
			// End offset: 0x80045C18
			// End Line: 2276

			/* begin block 1.1.4 */
				// Start line: 2283
				// Start offset: 0x80045C54
				// Variables:
			// 		struct POLY_FT3 *ft3; // $t0

				/* begin block 1.1.4.1 */
					// Start line: 2296
					// Start offset: 0x80045CA0
					// Variables:
				// 		short uMin; // $a3
				// 		short uMax; // $a2
				/* end block 1.1.4.1 */
				// End offset: 0x80045DA4
				// End Line: 2304
			/* end block 1.1.4 */
			// End offset: 0x80045DE0
			// End Line: 2310
		/* end block 1.1 */
		// End offset: 0x80045DE0
		// End Line: 2314

		/* begin block 1.2 */
			// Start line: 2325
			// Start offset: 0x80045E20
			// Variables:
		// 		struct DVECTOR xy_pos; // stack offset -72
		// 		long flags; // $t1

			/* begin block 1.2.1 */
				// Start line: 2390
				// Start offset: 0x8004605C
				// Variables:
			// 		struct _POLY_SG4 *sg4; // $a1

				/* begin block 1.2.1.1 */
					// Start line: 2392
					// Start offset: 0x8004605C
					// Variables:
				// 		int n; // $a3
				// 		long *src; // $t2
				// 		long *dst; // $t1
				// 		long *ptr; // $t3
				/* end block 1.2.1.1 */
				// End offset: 0x80046154
				// End Line: 2423
			/* end block 1.2.1 */
			// End offset: 0x80046154
			// End Line: 2445

			/* begin block 1.2.2 */
				// Start line: 2457
				// Start offset: 0x800461E8
			/* end block 1.2.2 */
			// End offset: 0x800461E8
			// End Line: 2461

			/* begin block 1.2.3 */
				// Start line: 2489
				// Start offset: 0x800462D4
				// Variables:
			// 		unsigned short uMin; // $t3
			// 		unsigned short uMax; // $t2
			// 		unsigned short vMin; // $a3
			// 		unsigned short vMax; // $v1
			// 		struct POLY_FT4 *ft4; // $a2
			/* end block 1.2.3 */
			// End offset: 0x80046540
			// End Line: 2527
		/* end block 1.2 */
		// End offset: 0x800465AC
		// End Line: 2546
	/* end block 1 */
	// End offset: 0x800465B8
	// End Line: 2550

	/* begin block 2 */
		// Start line: 4691
	/* end block 2 */
	// End Line: 4692

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Could not reconcile some variable overlaps */
/* File: C:\kain2\game\FX.C */

void FX_DrawList(_FXTracker *fxTracker,GameTracker *gameTracker,ulong **ot,undefined wcTransform)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  uint *puVar5;
  int iVar6;
  short sVar7;
  GameTracker *pGVar8;
  undefined4 in_zero;
  undefined4 in_at;
  uint uVar9;
  ulong *puVar10;
  char cVar11;
  char cVar12;
  ushort uVar13;
  byte bVar14;
  byte bVar15;
  int iVar16;
  int iVar17;
  NodeType *pNVar18;
  char cVar19;
  undefined3 in_register_0000001d;
  MATRIX *m0;
  ushort uVar20;
  uint *puVar21;
  uint *puVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  int iVar25;
  undefined4 uVar26;
  NodeType *pNVar27;
  uint *puVar28;
  uint *puVar29;
  NodeType *pNVar30;
  NodeType **ppNVar31;
  NodeType *pNVar32;
  _PrimPool *primPool;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  byte local_50;
  byte local_4f;
  byte local_4e;
  undefined4 local_48;
  GameTracker *local_40;
  GameTracker *local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  m0 = (MATRIX *)CONCAT31(in_register_0000001d,wcTransform);
  bVar4 = false;
  primPool = gameTracker->primPool;
  puVar28 = primPool->nextPrim;
  local_4e = 0x1f;
  local_4f = 0x1f;
  local_50 = 0x1f;
  pNVar27 = (fxTracker->usedPrimList).next;
  if (pNVar27 != (NodeType *)0x0) {
    ppNVar31 = (NodeType **)(puVar28 + 1);
    do {
      if (primPool->lastPrim <= puVar28 + 10) break;
      pNVar30 = pNVar27[1].next;
      pNVar32 = pNVar27->next;
      if (((uint)pNVar30 & 0x10) == 0) {
        if (((uint)pNVar30 & 0x10000) == 0) {
          pNVar27[3].prev[4].prev = (NodeType *)(int)*(short *)&pNVar27[5].next;
          pNVar27[3].prev[4].next = (NodeType *)(int)*(short *)((int)&pNVar27[5].next + 2);
          pNVar27[3].prev[5].prev = (NodeType *)(int)*(short *)&pNVar27[6].prev;
          gameTracker = (GameTracker *)&pNVar27[3].prev[1].next;
          CompMatrix(m0,(MATRIX *)gameTracker,(MATRIX *)&DAT_1f800000);
          SetRotMatrix((MATRIX *)&DAT_1f800000);
          SetTransMatrix((MATRIX *)&DAT_1f800000);
          bVar4 = false;
        }
        else {
          if (!bVar4) {
            setCopControlWord(2,0,*(undefined4 *)m0->m);
            setCopControlWord(2,0x800,*(undefined4 *)(m0->m + 2));
            setCopControlWord(2,0x1000,*(undefined4 *)(m0->m + 4));
            setCopControlWord(2,0x1800,*(undefined4 *)(m0->m + 6));
            setCopControlWord(2,0x2000,*(undefined4 *)(m0->m + 8));
            setCopControlWord(2,0x2800,m0->t[0]);
            setCopControlWord(2,0x3000,m0->t[1]);
            setCopControlWord(2,0x3800,m0->t[2]);
            bVar4 = true;
          }
        }
        if (((uint)pNVar30 & 0x2000) == 0) {
          setCopReg(2,in_zero,pNVar27[7].next);
          setCopReg(2,in_at,pNVar27[8].prev);
          setCopReg(2,&pNVar27[9].next,pNVar27[8].next);
          setCopReg(2,&pNVar27[8].next,pNVar27[9].prev);
          setCopReg(2,&pNVar27[7].next,pNVar27[9].next);
          setCopReg(2,gameTracker,pNVar27[10].prev);
        }
        else {
          local_64 = local_64 & 0xffff0000 |
                     (int)*(short *)&pNVar27[8].prev * (int)*(short *)((int)&pNVar27[9].next + 2) >>
                     0xc & 0xffffU;
          local_5c = local_5c & 0xffff0000 |
                     (int)*(short *)&pNVar27[9].prev * (int)*(short *)((int)&pNVar27[9].next + 2) >>
                     0xc & 0xffffU;
          local_68 = (int)*(short *)&pNVar27[7].next * (int)*(short *)((int)&pNVar27[7].next + 2) >>
                     0xc & 0xffff;
          local_60 = (int)*(short *)&pNVar27[8].next * (int)*(short *)((int)&pNVar27[7].next + 2) >>
                     0xc & 0xffff;
          local_58 = (int)*(short *)&pNVar27[9].next * (int)*(short *)((int)&pNVar27[7].next + 2) >>
                     0xc & 0xffff;
          local_54 = local_54 & 0xffff0000 |
                     (int)*(short *)&pNVar27[10].prev * (int)*(short *)((int)&pNVar27[9].next + 2)
                     >> 0xc & 0xffffU;
          setCopReg(2,in_zero,local_68);
          setCopReg(2,in_at,local_64);
          setCopReg(2,&local_68,local_60);
          setCopReg(2,&local_58,local_5c);
          setCopReg(2,&local_60,local_58);
          setCopReg(2,gameTracker,local_54);
        }
        copFunction(2,0x280030);
        if (((uint)pNVar30 & 0x1000000) == 0) {
          if (((uint)pNVar30 & 0x4000) == 0) {
            local_34 = getCopReg(2,0x9800);
            local_34 = local_34 >> 2;
          }
          else {
            gameTracker = (GameTracker *)getCopReg(2,0x11);
            local_3c = (GameTracker *)getCopReg(2,0x12);
            local_38 = getCopReg(2,0x13);
            local_34 = local_38 >> 2;
            pGVar8 = local_3c;
            if ((int)local_3c < (int)gameTracker) {
              pGVar8 = gameTracker;
            }
            local_40 = gameTracker;
            if (local_38 < (int)pGVar8) {
              local_34 = (int)pGVar8 >> 2;
            }
          }
        }
        else {
          local_40 = (GameTracker *)getCopReg(2,0x11);
          local_3c = (GameTracker *)getCopReg(2,0x12);
          local_38 = getCopReg(2,0x13);
          local_34 = (int)local_40 >> 2;
        }
        if (((uint)pNVar30 & 0x8000) != 0) {
          local_34 = local_34 + -0x14;
        }
        if (local_34 - 1U < 0xbff) {
          if (((uint)pNVar30 & 1) == 0) {
            if (((uint)pNVar30 & 8) == 0) {
              if (((uint)pNVar30 & 0x1000000) == 0) {
                *ppNVar31 = pNVar27[3].next;
                uVar9 = getCopReg(2,0xc);
                puVar28[2] = uVar9;
                uVar9 = getCopReg(2,0xd);
                puVar28[3] = uVar9;
                uVar9 = getCopReg(2,0xe);
                puVar28[4] = uVar9;
                ppNVar31 = ppNVar31 + 5;
                *puVar28 = (uint)ot[local_34] & 0xffffff | 0x4000000;
                puVar29 = puVar28 + 5;
              }
              else {
                if (((uint)pNVar30 & 0x80000) == 0) goto LAB_80045de0;
                ppNVar31[1] = pNVar27[3].next;
                pNVar27 = pNVar27[4].next;
                *ppNVar31 = (NodeType *)0xe1000620;
                ppNVar31[3] = pNVar27;
                uVar9 = getCopReg(2,0xc);
                puVar28[5] = uVar9;
                uVar9 = getCopReg(2,0xd);
                puVar28[3] = uVar9;
                *(undefined *)((int)ppNVar31 + 7) = 0x52;
                ppNVar31 = ppNVar31 + 6;
                *puVar28 = (uint)ot[local_34] & 0xffffff | 0x5000000;
                puVar29 = puVar28 + 6;
              }
            }
            else {
              if (((uint)pNVar30 & 0x80000) != 0) {
                uVar9 = getCopReg(2,0xc);
                puVar28[3] = uVar9;
                uVar9 = getCopReg(2,0xd);
                puVar28[5] = uVar9;
                uVar9 = getCopReg(2,0xe);
                puVar28[7] = uVar9;
                setCopReg(2,in_zero,pNVar27[10].next);
                setCopReg(2,in_at,pNVar27[0xb].prev);
                copFunction(2,0x180001);
                *ppNVar31 = (NodeType *)0xe1000620;
                uVar9 = getCopReg(2,0xe);
                puVar28[9] = uVar9;
                gameTracker = (GameTracker *)(puVar28 + 2);
                iVar16 = 0;
                pNVar30 = pNVar27;
                do {
                  setCopReg(2,0x4000,0x1000 - (int)*(short *)&pNVar30[6].next);
                  setCopReg(2,0x4800,(uint)*(byte *)&pNVar27[3].next);
                  setCopReg(2,0x5000,(uint)*(byte *)((int)&pNVar27[3].next + 1));
                  setCopReg(2,0x5800,(uint)*(byte *)((int)&pNVar27[3].next + 2));
                  copFunction(2,0x198003d);
                  uVar23 = getCopReg(2,0x4800);
                  uVar24 = getCopReg(2,0x5000);
                  uVar26 = getCopReg(2,0x5800);
                  *(char *)&(gameTracker->gameData).asmData.drawBackFaces = (char)uVar23;
                  *(undefined *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1) =
                       (char)uVar24;
                  *(undefined *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 2) =
                       (char)uVar26;
                  gameTracker = (GameTracker *)&(gameTracker->gameData).asmData.MorphTime;
                  iVar16 = iVar16 + 1;
                  pNVar30 = (NodeType *)((int)&pNVar30->prev + 2);
                } while (iVar16 < 4);
                *puVar28 = (uint)ot[local_34] & 0xffffff | 0x9000000;
                ot[local_34] = (ulong *)((uint)puVar28 & 0xffffff);
                *(undefined *)((int)puVar28 + 0xb) = 0x3a;
                puVar28 = puVar28 + 10;
                ppNVar31 = ppNVar31 + 10;
                goto LAB_80045de0;
              }
              uVar9 = getCopReg(2,0xc);
              puVar28[2] = uVar9;
              uVar9 = getCopReg(2,0xd);
              puVar28[4] = uVar9;
              uVar9 = getCopReg(2,0xe);
              puVar28[6] = uVar9;
              setCopReg(2,in_zero,pNVar27[10].next);
              setCopReg(2,in_at,pNVar27[0xb].prev);
              copFunction(2,0x180001);
              *ppNVar31 = pNVar27[3].next;
              ppNVar31[2] = pNVar27[3].next;
              ppNVar31[4] = pNVar27[3].next;
              pNVar27 = pNVar27[3].next;
              *(undefined *)((int)ppNVar31 + -1) = 8;
              *(undefined *)((int)ppNVar31 + 3) = 0x38;
              ppNVar31[6] = pNVar27;
              uVar9 = getCopReg(2,0xe);
              puVar28[8] = uVar9;
              ppNVar31 = ppNVar31 + 9;
              *puVar28 = (uint)ot[local_34] & 0xffffff | 0x8000000;
              puVar29 = puVar28 + 9;
            }
          }
          else {
            if (((uint)pNVar30 & 4) == 0) {
              gameTracker = (GameTracker *)pNVar27[1].prev;
            }
            else {
              gameTracker = (GameTracker *)pNVar27[0xd].prev;
            }
            if (((uint)pNVar30 & 8) == 0) {
              uVar9 = getCopReg(2,0xc);
              puVar28[2] = uVar9;
              uVar9 = getCopReg(2,0xd);
              puVar28[4] = uVar9;
              uVar9 = getCopReg(2,0xe);
              puVar28[6] = uVar9;
              ppNVar31[2] = (NodeType *)(gameTracker->gameData).asmData.drawBackFaces;
              ppNVar31[4] = (NodeType *)(gameTracker->gameData).asmData.dispPage;
              ppNVar31[6] = *(NodeType **)&(gameTracker->gameData).asmData.MorphTime;
              if (((uint)pNVar30 & 0x1000) != 0) {
                bVar15 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                bVar14 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
                if (bVar15 < bVar14) {
                  bVar3 = bVar14 < bVar15;
                  if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar15) {
LAB_80045cf8:
                    cVar12 = *(char *)&(gameTracker->gameData).asmData.MorphTime;
                    goto LAB_80045cfc;
                  }
                  cVar12 = *(char *)&(gameTracker->gameData).asmData.drawBackFaces;
                }
                else {
                  if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar14)
                  goto LAB_80045cf8;
                  cVar12 = *(char *)&(gameTracker->gameData).asmData.dispPage;
LAB_80045cfc:
                  bVar15 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                  bVar14 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
                  bVar3 = bVar14 < bVar15;
                }
                if (bVar3) {
                  if (*(byte *)&(gameTracker->gameData).asmData.MorphTime < bVar15) {
                    cVar19 = *(char *)&(gameTracker->gameData).asmData.drawBackFaces;
                  }
                  else {
LAB_80045d54:
                    cVar19 = *(char *)&(gameTracker->gameData).asmData.MorphTime;
                  }
                }
                else {
                  if (bVar14 <= *(byte *)&(gameTracker->gameData).asmData.MorphTime)
                  goto LAB_80045d54;
                  cVar19 = *(char *)&(gameTracker->gameData).asmData.dispPage;
                }
                cVar11 = cVar12;
                if (*(char *)&(gameTracker->gameData).asmData.drawBackFaces == cVar12) {
                  cVar11 = cVar19;
                }
                *(char *)(puVar28 + 3) = cVar11;
                cVar11 = cVar12;
                if (*(char *)&(gameTracker->gameData).asmData.dispPage == cVar12) {
                  cVar11 = cVar19;
                }
                *(char *)(puVar28 + 5) = cVar11;
                if (*(char *)&(gameTracker->gameData).asmData.MorphTime == cVar12) {
                  cVar12 = cVar19;
                }
                *(char *)(puVar28 + 7) = cVar12;
              }
              *ppNVar31 = pNVar27[3].next;
              ppNVar31 = ppNVar31 + 8;
              *puVar28 = (uint)ot[local_34] & 0xffffff | 0x7000000;
              puVar29 = puVar28 + 8;
            }
            else {
              uVar9 = getCopReg(2,0xc);
              puVar28[2] = uVar9;
              uVar9 = getCopReg(2,0xd);
              puVar28[4] = uVar9;
              uVar9 = getCopReg(2,0xe);
              puVar28[6] = uVar9;
              setCopReg(2,in_zero,pNVar27[10].next);
              setCopReg(2,in_at,pNVar27[0xb].prev);
              copFunction(2,0x180001);
              bVar15 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
              bVar14 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
              if (bVar15 < bVar14) {
                bVar3 = bVar14 < bVar15;
                if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar15) {
LAB_80045a54:
                  bVar1 = *(byte *)&(gameTracker->gameData).asmData.MorphTime;
                  goto LAB_80045a58;
                }
                bVar1 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
              }
              else {
                if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar14)
                goto LAB_80045a54;
                bVar1 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
LAB_80045a58:
                bVar15 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                bVar14 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
                bVar3 = bVar14 < bVar15;
              }
              if (bVar3) {
                if (*(byte *)&(gameTracker->gameData).asmData.MorphTime < bVar15) {
                  uVar20 = (ushort)*(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                }
                else {
LAB_80045ab0:
                  uVar20 = (ushort)*(byte *)&(gameTracker->gameData).asmData.MorphTime;
                }
              }
              else {
                if (bVar14 <= *(byte *)&(gameTracker->gameData).asmData.MorphTime)
                goto LAB_80045ab0;
                uVar20 = (ushort)*(byte *)&(gameTracker->gameData).asmData.dispPage;
              }
              bVar15 = *(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1);
              bVar14 = *(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1);
              if (bVar15 < bVar14) {
                if (*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) <= bVar15) {
LAB_80045b0c:
                  bVar2 = *(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1);
                  goto LAB_80045b18;
                }
                bVar2 = *(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1);
              }
              else {
                if (*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) <= bVar14)
                goto LAB_80045b0c;
                bVar2 = *(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1);
LAB_80045b18:
                bVar15 = *(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1);
                bVar14 = *(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1);
              }
              if (bVar14 < bVar15) {
                if (*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) < bVar15) {
                  uVar13 = (ushort)*(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1
                                            ) << 8;
                }
                else {
LAB_80045b70:
                  uVar13 = (ushort)*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) <<
                           8;
                }
              }
              else {
                if (bVar14 <= *(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1))
                goto LAB_80045b70;
                uVar13 = (ushort)*(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1) << 8;
              }
              *(ushort *)(puVar28 + 3) = CONCAT11(bVar2,bVar1);
              *(ushort *)(puVar28 + 5) = uVar20 | (ushort)bVar2 << 8;
              *(ushort *)(puVar28 + 7) = bVar1 | uVar13;
              *(ushort *)(puVar28 + 9) = uVar20 | uVar13;
              *(undefined2 *)((int)puVar28 + 0xe) =
                   *(undefined2 *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 2);
              *(undefined2 *)((int)puVar28 + 0x16) =
                   *(undefined2 *)((int)&(gameTracker->gameData).asmData.dispPage + 2);
              uVar9 = getCopReg(2,0xe);
              puVar28[8] = uVar9;
              if (((uint)pNVar30 & 0x1000) != 0) {
                bVar15 = *(byte *)(puVar28 + 3) ^ *(byte *)(puVar28 + 5);
                *(byte *)(puVar28 + 3) = bVar15;
                bVar15 = bVar15 ^ *(byte *)(puVar28 + 5);
                gameTracker = (GameTracker *)(uint)bVar15;
                bVar14 = *(byte *)(puVar28 + 7) ^ *(byte *)(puVar28 + 9);
                *(byte *)(puVar28 + 7) = bVar14;
                bVar14 = bVar14 ^ *(byte *)(puVar28 + 9);
                *(byte *)(puVar28 + 5) = bVar15;
                *(byte *)(puVar28 + 9) = bVar14;
                *(byte *)(puVar28 + 3) = *(byte *)(puVar28 + 3) ^ bVar15;
                *(byte *)(puVar28 + 7) = *(byte *)(puVar28 + 7) ^ bVar14;
              }
              *ppNVar31 = pNVar27[3].next;
              ppNVar31 = ppNVar31 + 10;
              *puVar28 = (uint)ot[local_34] & 0xffffff | 0x9000000;
              puVar29 = puVar28 + 10;
            }
          }
          ot[local_34] = (ulong *)((uint)puVar28 & 0xffffff);
          puVar28 = puVar29;
        }
      }
LAB_80045de0:
      pNVar27 = pNVar32;
    } while (pNVar32 != (NodeType *)0x0);
  }
  SetRotMatrix(m0);
  SetTransMatrix(m0);
  pNVar27 = (fxTracker->usedPrimListSprite).next;
  puVar29 = puVar28;
joined_r0x80045e0c:
  do {
    do {
      pNVar30 = pNVar27;
      if (pNVar30 == (NodeType *)0x0) {
LAB_800465b8:
        primPool->nextPrim = puVar28;
        FX_DrawAllGeneralEffects(wcTransform,DAT_800d2108,primPool,ot);
        return;
      }
      local_30 = (int)*(short *)&pNVar30[7].next << 1;
      setCopReg(2,in_zero,pNVar30[5].next);
      setCopReg(2,in_at,pNVar30[6].prev);
      setCopControlWord(2,0xe000,0);
      setCopControlWord(2,0xd800,local_30);
      copFunction(2,0x180001);
      pNVar27 = pNVar30->next;
      pNVar32 = pNVar30[1].next;
      if (primPool->lastPrim <= puVar28 + 10) goto LAB_800465b8;
    } while (((uint)pNVar32 & 0x10) != 0);
    local_48 = getCopReg(2,0xe);
    local_30 = getCopReg(2,0x18);
    local_40 = (GameTracker *)getCopReg(2,0x13);
    iVar16 = (int)local_40 >> 2;
    local_34 = iVar16;
    if ((((((uint)pNVar32 & 0x2008000) != 0) &&
         (local_34 = iVar16 + -0x14, ((uint)pNVar32 & 0x8000) == 0)) &&
        (local_34 = iVar16, ((uint)pNVar32 & 0x2000000) != 0)) && (0x14 < iVar16)) {
      local_34 = 0xbff;
    }
    if ((((uint)pNVar32 & 0x800000) != 0) && (0xe7f < (uint)((int)local_40 + 0xfffffe80U))) {
      local_34 = 0;
    }
    if (local_34 - 0x15U < 0xbeb) {
      local_48._2_2_ = (short)((uint)local_48 >> 0x10);
      if ((((uint)pNVar32 & 0x4000000) != 0) ||
         (((-1 < (short)local_48 && (-1 < local_48)) &&
          (((short)local_48 < 0x200 && (local_48._2_2_ < 0xf0)))))) {
        if ((((uint)pNVar32 & 0x2000) == 0) ||
           (iVar16 = (int)*(short *)((int)&pNVar30[7].next + 2), iVar16 == 0x1000)) {
          iVar16 = local_30;
          if ((int)*(short *)&pNVar30[7].next != (int)*(short *)&pNVar30[8].prev) {
            iVar16 = ((int)*(short *)&pNVar30[8].prev * 0x2800000) / (int)local_40;
          }
        }
        else {
          local_30 = (local_30 >> 0xc) * iVar16;
          iVar16 = local_30;
          if ((int)*(short *)&pNVar30[7].next != (int)*(short *)&pNVar30[8].prev) {
            iVar16 = ((int)*(short *)&pNVar30[8].prev *
                     (int)*(short *)((int)&pNVar30[7].next + 2) * 0x280) / (int)local_40 << 4;
          }
        }
        iVar16 = iVar16 + 0xffff;
        iVar25 = iVar16 >> 0x10;
        iVar17 = (local_30 / 0x140) * 0x200 + 0xffff;
        local_30 = iVar17 >> 0x10;
        iVar6 = iVar16 >> 0x1f;
        local_30._0_2_ = (short)((uint)iVar17 >> 0x10);
        sVar7 = (short)((uint)iVar16 >> 0x10);
        if (((uint)pNVar32 & 1) == 0) {
          if (((uint)pNVar32 & 8) != 0) {
            if (((uint)pNVar32 & 0x80000) == 0) {
              local_48._0_2_ = (short)local_48 - (short)(local_30 - (iVar17 >> 0x1f) >> 1);
              *(short *)(puVar29 + 6) = (short)local_48;
              *(short *)(puVar29 + 2) = (short)local_48;
              local_48._2_2_ = local_48._2_2_ - (short)(iVar25 - iVar6 >> 1);
              *(short *)((int)puVar29 + 0x12) = local_48._2_2_;
              *(short *)((int)puVar29 + 10) = local_48._2_2_;
              *(short *)((int)puVar29 + 0x22) = local_48._2_2_ + sVar7;
              *(short *)((int)puVar29 + 0x1a) = local_48._2_2_ + sVar7;
              *(short *)(puVar29 + 8) = *(short *)(puVar29 + 2) + (short)local_30;
              *(short *)(puVar29 + 4) = *(short *)(puVar29 + 2) + (short)local_30;
              *(NodeType **)(puVar29 + 1) = pNVar30[3].next;
              *(NodeType **)(puVar29 + 3) = pNVar30[3].next;
              *(NodeType **)(puVar29 + 5) = pNVar30[3].next;
              pNVar30 = pNVar30[3].next;
              *(undefined *)((int)puVar29 + 3) = 8;
              *(undefined *)((int)puVar29 + 7) = 0x38;
              *(NodeType **)(puVar29 + 7) = pNVar30;
              puVar29 = puVar29 + 9;
              puVar10 = (ulong *)((uint)puVar28 & 0xffffff);
              *puVar28 = (uint)ot[local_34] & 0xffffff | 0x8000000;
              puVar28 = puVar28 + 9;
              ot[local_34] = puVar10;
            }
            else {
              puVar28 = puVar28 + 0x10;
              puVar22 = puVar29 + 3;
              puVar21 = puVar29 + 0xc;
              iVar16 = 0;
              puVar29[10] = 0xe1000640;
              puVar29[1] = 0xe1000620;
              local_48._0_2_ = (short)local_48 - (short)(local_30 - (iVar17 >> 0x1f) >> 1);
              *(short *)(puVar29 + 7) = (short)local_48;
              *(short *)(puVar29 + 3) = (short)local_48;
              local_48._2_2_ = local_48._2_2_ - (short)(iVar25 - iVar6 >> 1);
              *(short *)((int)puVar29 + 0x16) = local_48._2_2_;
              *(short *)((int)puVar29 + 0xe) = local_48._2_2_;
              *(short *)((int)puVar29 + 0x26) = local_48._2_2_ + sVar7;
              *(short *)((int)puVar29 + 0x1e) = local_48._2_2_ + sVar7;
              *(short *)(puVar29 + 9) = *(short *)(puVar29 + 3) + (short)local_30;
              *(short *)(puVar29 + 5) = *(short *)(puVar29 + 3) + (short)local_30;
              puVar5 = puVar29;
              do {
                setCopReg(2,0x4000,0x1000 - (int)*(short *)&pNVar30[6].next);
                setCopReg(2,0x4800,(uint)*(byte *)&pNVar30[3].next);
                setCopReg(2,0x5000,(uint)*(byte *)((int)&pNVar30[3].next + 1));
                setCopReg(2,0x5800,(uint)*(byte *)((int)&pNVar30[3].next + 2));
                copFunction(2,0x198003d);
                uVar9 = *puVar22;
                puVar22 = puVar22 + 2;
                *puVar21 = uVar9;
                puVar21 = puVar21 + 1;
                uVar23 = getCopReg(2,0x4800);
                uVar24 = getCopReg(2,0x5000);
                uVar26 = getCopReg(2,0x5800);
                *(char *)(puVar5 + 2) = (char)uVar23;
                *(undefined *)((int)puVar5 + 9) = (char)uVar24;
                *(undefined *)((int)puVar5 + 10) = (char)uVar26;
                iVar16 = iVar16 + 1;
                puVar5 = puVar5 + 2;
              } while (iVar16 < 4);
              setCopReg(2,0x4000,0x1000 - (int)*(short *)&pNVar30[6].next);
              setCopReg(2,0x4800,(uint)local_50);
              setCopReg(2,0x5000,(uint)local_4f);
              setCopReg(2,0x5800,(uint)local_4e);
              copFunction(2,0x198003d);
              *puVar29 = (uint)ot[local_34] & 0xffffff | 0xf000000;
              ot[local_34] = (ulong *)((uint)puVar29 & 0xffffff);
              uVar23 = getCopReg(2,0x4800);
              uVar24 = getCopReg(2,0x5000);
              uVar26 = getCopReg(2,0x5800);
              *(char *)(puVar29 + 0xb) = (char)uVar23;
              *(undefined *)((int)puVar29 + 0x2d) = (char)uVar24;
              *(undefined *)((int)puVar29 + 0x2e) = (char)uVar26;
              *(undefined *)((int)puVar29 + 0xb) = 0x3a;
              *(undefined *)((int)puVar29 + 0x2f) = 0x2a;
              puVar29 = puVar29 + 0x10;
            }
          }
        }
        else {
          if (((uint)pNVar32 & 4) == 0) {
            pNVar18 = pNVar30[1].prev;
          }
          else {
            pNVar18 = pNVar30[0xd].prev;
          }
          if (((uint)pNVar32 & 8) != 0) {
            bVar15 = *(byte *)&pNVar18->prev;
            bVar14 = *(byte *)&pNVar18->next;
            if (bVar15 < bVar14) {
              bVar4 = bVar14 < bVar15;
              if (*(byte *)&pNVar18[1].prev <= bVar15) {
LAB_8004632c:
                bVar1 = *(byte *)&pNVar18[1].prev;
                goto LAB_80046330;
              }
              bVar1 = *(byte *)&pNVar18->prev;
            }
            else {
              if (*(byte *)&pNVar18[1].prev <= bVar14) goto LAB_8004632c;
              bVar1 = *(byte *)&pNVar18->next;
LAB_80046330:
              bVar15 = *(byte *)&pNVar18->prev;
              bVar14 = *(byte *)&pNVar18->next;
              bVar4 = bVar14 < bVar15;
            }
            if (bVar4) {
              if (*(byte *)&pNVar18[1].prev < bVar15) {
                uVar20 = (ushort)*(byte *)&pNVar18->prev;
              }
              else {
LAB_80046388:
                uVar20 = (ushort)*(byte *)&pNVar18[1].prev;
              }
            }
            else {
              if (bVar14 <= *(byte *)&pNVar18[1].prev) goto LAB_80046388;
              uVar20 = (ushort)*(byte *)&pNVar18->next;
            }
            bVar15 = *(byte *)((int)&pNVar18->prev + 1);
            bVar14 = *(byte *)((int)&pNVar18->next + 1);
            if (bVar15 < bVar14) {
              if (*(byte *)((int)&pNVar18[1].prev + 1) <= bVar15) {
LAB_800463e4:
                bVar2 = *(byte *)((int)&pNVar18[1].prev + 1);
                goto LAB_800463f0;
              }
              bVar2 = *(byte *)((int)&pNVar18->prev + 1);
            }
            else {
              if (*(byte *)((int)&pNVar18[1].prev + 1) <= bVar14) goto LAB_800463e4;
              bVar2 = *(byte *)((int)&pNVar18->next + 1);
LAB_800463f0:
              bVar15 = *(byte *)((int)&pNVar18->prev + 1);
              bVar14 = *(byte *)((int)&pNVar18->next + 1);
            }
            if (bVar14 < bVar15) {
              if (*(byte *)((int)&pNVar18[1].prev + 1) < bVar15) {
                uVar13 = (ushort)*(byte *)((int)&pNVar18->prev + 1) << 8;
              }
              else {
LAB_80046448:
                uVar13 = (ushort)*(byte *)((int)&pNVar18[1].prev + 1) << 8;
              }
            }
            else {
              if (bVar14 <= *(byte *)((int)&pNVar18[1].prev + 1)) goto LAB_80046448;
              uVar13 = (ushort)*(byte *)((int)&pNVar18->next + 1) << 8;
            }
            *(ushort *)(puVar29 + 3) = CONCAT11(bVar2,bVar1);
            *(ushort *)(puVar29 + 5) = uVar20 | (ushort)bVar2 << 8;
            *(ushort *)(puVar29 + 7) = bVar1 | uVar13;
            *(ushort *)(puVar29 + 9) = uVar20 | uVar13;
            *(undefined2 *)((int)puVar29 + 0xe) = *(undefined2 *)((int)&pNVar18->prev + 2);
            *(undefined2 *)((int)puVar29 + 0x16) = *(undefined2 *)((int)&pNVar18->next + 2);
            local_48._0_2_ = (short)local_48 + (short)(local_30 / 2);
            *(short *)(puVar29 + 6) = (short)local_48;
            *(short *)(puVar29 + 2) = (short)local_48;
            local_48._2_2_ = local_48._2_2_ + (short)(iVar25 - iVar6 >> 1);
            *(short *)((int)puVar29 + 0x12) = local_48._2_2_;
            *(short *)((int)puVar29 + 10) = local_48._2_2_;
            *(short *)((int)puVar29 + 0x22) = local_48._2_2_ - sVar7;
            *(short *)((int)puVar29 + 0x1a) = local_48._2_2_ - sVar7;
            *(short *)(puVar29 + 8) = *(short *)(puVar29 + 2) - (short)local_30;
            *(short *)(puVar29 + 4) = *(short *)(puVar29 + 2) - (short)local_30;
            if (((uint)pNVar32 & 0x1000) != 0) {
              bVar14 = *(byte *)(puVar29 + 3) ^ *(byte *)(puVar29 + 5);
              *(byte *)(puVar29 + 3) = bVar14;
              bVar14 = bVar14 ^ *(byte *)(puVar29 + 5);
              bVar15 = *(byte *)(puVar29 + 7) ^ *(byte *)(puVar29 + 9);
              *(byte *)(puVar29 + 7) = bVar15;
              bVar15 = bVar15 ^ *(byte *)(puVar29 + 9);
              *(byte *)(puVar29 + 5) = bVar14;
              *(byte *)(puVar29 + 9) = bVar15;
              *(byte *)(puVar29 + 3) = *(byte *)(puVar29 + 3) ^ bVar14;
              *(byte *)(puVar29 + 7) = *(byte *)(puVar29 + 7) ^ bVar15;
            }
            *(NodeType **)(puVar29 + 1) = pNVar30[3].next;
            puVar29 = puVar29 + 10;
            puVar10 = (ulong *)((uint)puVar28 & 0xffffff);
            *puVar28 = (uint)ot[local_34] & 0xffffff | 0x9000000;
            puVar28 = puVar28 + 10;
            ot[local_34] = puVar10;
          }
        }
        goto joined_r0x80045e0c;
      }
    }
    if (((uint)pNVar32 & 0x400000) == 0) {
      if (((uint)pNVar32 & 0x800000) != 0) {
        *(undefined2 *)((int)&pNVar30[8].prev + 2) = 9999;
      }
    }
    else {
      pNVar30[2].prev = (NodeType *)0x1;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SimpleQuadSetup(struct _FX_PRIM *fxPrim /*$s5*/, TDRFuncPtr_FX_SimpleQuadSetup1fxProcess fxProcess /*stack 4*/, struct _FX_MATRIX *fxMatrix /*stack 8*/, struct _Instance *instance /*$a3*/, struct _MFace *mface /*stack 16*/, struct _MVertex *vertexList /*stack 20*/, struct SVECTOR *center /*stack 24*/, struct SVECTOR *vel /*stack 28*/, struct SVECTOR *accl /*stack 32*/, struct _FXTracker *fxTracker /*stack 36*/, int timeToLive /*stack 40*/)
 // line 2717, offset 0x80046600
	/* begin block 1 */
		// Start line: 2718
		// Start offset: 0x80046600
		// Variables:
	// 		struct _MVertex *vertex1; // $s2
	// 		struct _MVertex *vertex2; // $s3
	// 		struct _MVertex *vertex3; // $s4

		/* begin block 1.1 */
			// Start line: 2718
			// Start offset: 0x80046600
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _Position *_v0; // $v0
		/* end block 1.1 */
		// End offset: 0x80046600
		// End Line: 2718

		/* begin block 1.2 */
			// Start line: 2718
			// Start offset: 0x80046600
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $v0
		/* end block 1.2 */
		// End offset: 0x80046600
		// End Line: 2718

		/* begin block 1.3 */
			// Start line: 2718
			// Start offset: 0x80046600
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $v0
		/* end block 1.3 */
		// End offset: 0x80046600
		// End Line: 2718

		/* begin block 1.4 */
			// Start line: 2718
			// Start offset: 0x80046600
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $v0
		/* end block 1.4 */
		// End offset: 0x80046600
		// End Line: 2718

		/* begin block 1.5 */
			// Start line: 2718
			// Start offset: 0x80046600
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $v0
		/* end block 1.5 */
		// End offset: 0x80046600
		// End Line: 2718
	/* end block 1 */
	// End offset: 0x800467F8
	// End Line: 2783

	/* begin block 2 */
		// Start line: 5416
	/* end block 2 */
	// End Line: 5417

/* File: C:\kain2\game\FX.C */

void FX_SimpleQuadSetup(_FX_PRIM *fxPrim,TDRFuncPtr_FX_SimpleQuadSetup1fxProcess fxProcess,
                       _FX_MATRIX *fxMatrix,_Instance *instance,_MFace *mface,_MVertex *vertexList,
                       undefined1 center,undefined1 vel,undefined1 accl,_FXTracker *fxTracker,
                       int timeToLive)

{
  short sVar1;
  short sVar2;
  TextureMT3 *pTVar3;
  uint uVar4;
  uint uVar5;
  
  MATH3D_SetUnityMatrix((char)fxMatrix + '\f');
  sVar1 = _center[1];
  sVar2 = _center[2];
  (fxPrim->position).x = *_center;
  (fxPrim->position).y = sVar1;
  (fxPrim->position).z = sVar2;
  sVar1 = (vertexList->vertex).y;
  sVar2 = (vertexList->vertex).z;
  (fxPrim->v0).x = (vertexList->vertex).x;
  (fxPrim->v0).y = sVar1;
  (fxPrim->v0).z = sVar2;
  sVar1 = vertexList[1].vertex.y;
  sVar2 = vertexList[1].vertex.z;
  (fxPrim->v1).x = vertexList[1].vertex.x;
  (fxPrim->v1).y = sVar1;
  (fxPrim->v1).z = sVar2;
  sVar1 = vertexList[3].vertex.y;
  sVar2 = vertexList[3].vertex.z;
  (fxPrim->v2).x = vertexList[3].vertex.x;
  (fxPrim->v2).y = sVar1;
  (fxPrim->v2).z = sVar2;
  sVar1 = vertexList[2].vertex.y;
  sVar2 = vertexList[2].vertex.z;
  (fxPrim->v3).x = vertexList[2].vertex.x;
  (fxPrim->v3).y = sVar1;
  (fxPrim->v3).z = sVar2;
  uVar4 = fxPrim->flags;
  fxPrim->flags = uVar4 | 8;
  if ((mface->flags & 2) == 0) {
    fxPrim->flags = uVar4 & 0xfffffffe | 8;
    uVar4 = mface->color;
    uVar5 = 0x28000000;
  }
  else {
    fxPrim->flags = uVar4 | 9;
    pTVar3 = (TextureMT3 *)mface->color;
    fxPrim->texture = pTVar3;
    uVar4 = pTVar3->color;
    uVar5 = 0x2c000000;
  }
  fxPrim->color = uVar4 & 0x3ffffff | uVar5;
  if (fxProcess == (TDRFuncPtr_FX_SimpleQuadSetup1fxProcess)0x0) {
    *(code **)&fxPrim->process = FX_StandardProcess;
  }
  else {
    *(TDRFuncPtr_FX_SimpleQuadSetup1fxProcess *)&fxPrim->process = fxProcess;
  }
  fxPrim->matrix = fxMatrix;
  if (_vel == (undefined2 *)0x0) {
    *(undefined2 *)&fxPrim->duo = 0;
    *(undefined2 *)((int)&fxPrim->duo + 2) = 0;
    *(undefined2 *)((int)&fxPrim->duo + 4) = 0;
  }
  else {
    *(undefined2 *)&fxPrim->duo = *_vel;
    *(undefined2 *)((int)&fxPrim->duo + 2) = _vel[1];
    *(undefined2 *)((int)&fxPrim->duo + 4) = _vel[2];
  }
  if (_accl == (undefined2 *)0x0) {
    *(undefined2 *)((int)&fxPrim->duo + 6) = 0;
    *(undefined2 *)((int)&fxPrim->duo + 8) = 0;
    *(undefined2 *)((int)&fxPrim->duo + 10) = 0;
  }
  else {
    *(undefined2 *)((int)&fxPrim->duo + 6) = *_accl;
    *(undefined2 *)((int)&fxPrim->duo + 8) = _accl[1];
    *(undefined2 *)((int)&fxPrim->duo + 10) = _accl[2];
  }
  fxPrim->timeToLive = (int)(short)timeToLive;
  fxPrim->flags = fxPrim->flags | 0x4000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_WaterRingProcess(struct _FX_PRIM *fxPrim /*$a0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 2786, offset 0x80046844
	/* begin block 1 */
		// Start line: 6896
	/* end block 1 */
	// End Line: 6897

/* File: C:\kain2\game\FX.C */

void FX_WaterRingProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  
  (fxPrim->v0).x = (fxPrim->v0).x + -8;
  sVar1 = (fxPrim->v1).x;
  (fxPrim->v0).y = (fxPrim->v0).y + -8;
  (fxPrim->v1).x = sVar1 + 8;
  sVar1 = (fxPrim->v2).x;
  (fxPrim->v1).y = (fxPrim->v1).y + -8;
  (fxPrim->v2).x = sVar1 + -8;
  sVar1 = (fxPrim->v3).x;
  (fxPrim->v2).y = (fxPrim->v2).y + 8;
  (fxPrim->v3).x = sVar1 + 8;
  (fxPrim->v3).y = (fxPrim->v3).y + 8;
  FX_StandardFXPrimProcess(fxPrim,fxTracker);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_WaterBubbleProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$s1*/)
 // line 2796, offset 0x800468c0
	/* begin block 1 */
		// Start line: 2797
		// Start offset: 0x800468C0
		// Variables:
	// 		struct _FX_PRIM *temp; // $a2

		/* begin block 1.1 */
			// Start line: 2823
			// Start offset: 0x800469A0
			// Variables:
		// 		struct Object *waterfx; // $v1
		// 		struct _Model *wxring; // $a0
		/* end block 1.1 */
		// End offset: 0x80046AB4
		// End Line: 2862
	/* end block 1 */
	// End offset: 0x80046AB4
	// End Line: 2863

	/* begin block 2 */
		// Start line: 6919
	/* end block 2 */
	// End Line: 6920

/* WARNING: Type propagation algorithm not settling */
/* File: C:\kain2\game\FX.C */

void FX_WaterBubbleProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  _FX_PRIM *p_Var5;
  uint uVar6;
  int iVar7;
  _Model *model;
  
  if (*(short *)((int)&fxPrim->duo + 4) < fxPrim->work1) {
    *(short *)((int)&fxPrim->duo + 4) =
         *(short *)((int)&fxPrim->duo + 4) + *(short *)((int)&fxPrim->duo + 10);
  }
  if (fxPrim->work0 < *(short *)((int)&fxPrim->duo + 6)) {
    sVar4 = *(short *)((int)&fxPrim->duo + 2);
    (fxPrim->position).x = (fxPrim->position).x + *(short *)&fxPrim->duo;
    (fxPrim->position).y = (fxPrim->position).y + sVar4;
  }
  uVar1 = fxPrim->work2;
  iVar7 = (uint)(ushort)fxPrim->work0 + 1;
  uVar2 = fxPrim->work3;
  (fxPrim->position).z = (fxPrim->position).z + *(short *)((int)&fxPrim->duo + 4);
  sVar4 = *(short *)((int)&fxPrim->duo + 8);
  fxPrim->work0 = (short)iVar7;
  iVar7 = (uint)uVar2 - iVar7 * (uint)uVar1;
  sVar3 = (short)iVar7;
  (fxPrim->v2).y = sVar3;
  (fxPrim->v0).y = sVar3;
  iVar7 = iVar7 * 0x10000 >> 0x10;
  if (sVar4 <= iVar7) {
    if ((int)(fxPrim->position).z <= fxPrim->timeToLive) {
      return;
    }
    if (((objectAccess[3].object != (void *)0x0) && ((fxPrim->v1).y < iVar7)) &&
       (model = (_Model *)(*(_Model **)((int)objectAccess[3].object + 0xc))->numVertices,
       p_Var5 = FX_BuildSingleFaceWithModel
                          (model,model->faceList,(char)fxPrim + ',',0,0,gFXT,FX_SimpleQuadSetup,
                           FX_WaterRingProcess,0x10), p_Var5 != (_FX_PRIM *)0x0)) {
      sVar4 = (p_Var5->position).x;
      p_Var5->fadeStep = 0x100;
      sVar3 = (p_Var5->position).y;
      sVar4 = sVar4 + -8;
      (p_Var5->v2).x = sVar4;
      (p_Var5->v0).x = sVar4;
      sVar4 = (p_Var5->position).x;
      sVar3 = sVar3 + -8;
      (p_Var5->v1).y = sVar3;
      (p_Var5->v0).y = sVar3;
      sVar3 = (p_Var5->position).z;
      sVar4 = sVar4 + 8;
      (p_Var5->v3).x = sVar4;
      (p_Var5->v1).x = sVar4;
      sVar4 = (p_Var5->position).y;
      p_Var5->endColor = 0;
      p_Var5->fadeValue[0] = 0;
      (p_Var5->v3).z = sVar3;
      (p_Var5->v2).z = sVar3;
      (p_Var5->v1).z = sVar3;
      (p_Var5->v0).z = sVar3;
      uVar6 = p_Var5->flags;
      sVar4 = sVar4 + 8;
      (p_Var5->v3).y = sVar4;
      (p_Var5->v2).y = sVar4;
      p_Var5->flags = uVar6 | 0x50000;
      p_Var5->color = p_Var5->color | 0xffffff;
      p_Var5->startColor = 0xffffff;
    }
  }
  FX_Die(fxPrim,fxTracker);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Sprite_Insert(struct NodeType *list /*$a0*/, struct _FX_PRIM *fxPrim /*$s0*/)
 // line 2866, offset 0x80046ac8
	/* begin block 1 */
		// Start line: 7121
	/* end block 1 */
	// End Line: 7122

/* File: C:\kain2\game\FX.C */

void FX_Sprite_Insert(NodeType *list,_FX_PRIM *fxPrim)

{
  LIST_InsertFunc(list,(NodeType *)fxPrim);
  if (FX_LastUsedPrim == (_FX_PRIM *)0x0) {
    FX_LastUsedPrim = fxPrim;
  }
  return;
}



// decompiled code
// original method signature: 
// struct TextureMT3 * /*$ra*/ FX_GetTextureObject(struct Object *object /*$a0*/, int modelnum /*$a1*/, int texnum /*$a2*/)
 // line 2872, offset 0x80046b00
	/* begin block 1 */
		// Start line: 2874
		// Start offset: 0x80046B00
		// Variables:
	// 		struct _Model *model; // $v0
	// 		struct TextureMT3 *texture; // $v0
	/* end block 1 */
	// End offset: 0x80046B00
	// End Line: 2878

	/* begin block 2 */
		// Start line: 7133
	/* end block 2 */
	// End Line: 7134

	/* begin block 3 */
		// Start line: 7134
	/* end block 3 */
	// End Line: 7135

	/* begin block 4 */
		// Start line: 7138
	/* end block 4 */
	// End Line: 7139

/* File: C:\kain2\game\FX.C */

TextureMT3 * FX_GetTextureObject(Object *object,int modelnum,int texnum)

{
  object->oflags2 = object->oflags2 | 0x20000000;
  return (TextureMT3 *)(object->modelList[modelnum]->faceList[1].color + texnum * 0x10 + 0x10);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeWaterBubble(struct _SVector *position /*$s0*/, struct _SVector *vel /*$s4*/, struct _SVector *accl /*$s5*/, long splashZ /*$s6*/, struct __BubbleParams *BP /*stack 16*/)
 // line 2886, offset 0x80046b3c
	/* begin block 1 */
		// Start line: 2887
		// Start offset: 0x80046B3C
		// Variables:
	// 		struct Object *waterfx; // $s3
	// 		struct _FX_PRIM *fxPrim; // $s1
	/* end block 1 */
	// End offset: 0x80046CC4
	// End Line: 2918

	/* begin block 2 */
		// Start line: 7162
	/* end block 2 */
	// End Line: 7163

/* File: C:\kain2\game\FX.C */

void FX_MakeWaterBubble(_SVector *position,_SVector *vel,_SVector *accl,long splashZ,
                       __BubbleParams *BP)

{
  void *object;
  _FXTracker *p_Var1;
  _FX_PRIM *fxPrim;
  int iVar2;
  TextureMT3 *pTVar3;
  uint uVar4;
  
  object = objectAccess[3].object;
  if ((objectAccess[3].object != (void *)0x0) &&
     (fxPrim = FX_GetPrim(gFXT), fxPrim != (_FX_PRIM *)0x0)) {
    FX_DFacadeParticleSetup
              (fxPrim,(char)position,0xc,0xc,0x2c000000,(char)vel,(char)accl,gFXT,
               (int)(short)splashZ);
    iVar2 = rand();
    pTVar3 = FX_GetTextureObject((Object *)object,2,iVar2 % ((int)BP->UniqueBubbles + -1));
    fxPrim->texture = pTVar3;
    fxPrim->flags = fxPrim->flags | 1;
    uVar4 = pTVar3->color;
    *(code **)&fxPrim->process = FX_WaterBubbleProcess;
    fxPrim->work0 = 0;
    fxPrim->color = uVar4 & 0x3ffffff | 0x2c000000;
    iVar2 = rand();
    fxPrim->work1 = BP->MaxSpeed + (short)(iVar2 % (int)BP->MaxSpeedRange);
    iVar2 = rand();
    fxPrim->work2 = BP->ScaleRate + (short)(iVar2 % (int)BP->ScaleRateRange);
    iVar2 = rand();
    p_Var1 = gFXT;
    fxPrim->work3 = BP->StartScale + (short)(iVar2 % (int)BP->StartScaleRange);
    *(short *)((int)&fxPrim->duo + 6) = BP->DisperseFrames;
    *(short *)((int)&fxPrim->duo + 8) = BP->KillScale;
    (fxPrim->v1).y = BP->MinSplashSize;
    FX_Sprite_Insert(&p_Var1->usedPrimListSprite,fxPrim);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawScreenPoly(int transtype /*$t3*/, unsigned long color /*$t2*/, int zdepth /*$a2*/)
 // line 2976, offset 0x80046cec
	/* begin block 1 */
		// Start line: 2977
		// Start offset: 0x80046CEC
		// Variables:
	// 		unsigned long **drawot; // $t0
	// 		struct _POLY_TF4 *poly; // $a3
	/* end block 1 */
	// End offset: 0x80046D90
	// End Line: 2993

	/* begin block 2 */
		// Start line: 7367
	/* end block 2 */
	// End Line: 7368

/* File: C:\kain2\game\FX.C */

void FX_DrawScreenPoly(int transtype,ulong color,int zdepth)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  
  iVar1 = DAT_800d22a4;
  puVar3 = *(uint **)(DAT_800d210c + 4);
  if (puVar3 + 7 < *(uint **)(DAT_800d210c + 8)) {
    *(undefined2 *)((int)puVar3 + 0x16) = 0xf0;
    *(undefined2 *)((int)puVar3 + 0x1a) = 0xf0;
    puVar3[1] = transtype << 5 | 0xe1000600;
    puVar2 = (uint *)(zdepth * 4 + iVar1);
    *(undefined2 *)(puVar3 + 3) = 0;
    *(undefined2 *)((int)puVar3 + 0xe) = 0;
    *(undefined2 *)(puVar3 + 4) = 0x200;
    *(undefined2 *)((int)puVar3 + 0x12) = 0;
    *(undefined2 *)(puVar3 + 5) = 0;
    *(undefined2 *)(puVar3 + 6) = 0x200;
    puVar3[2] = color;
    *(undefined *)((int)puVar3 + 0xb) = 0x2a;
    *puVar3 = *puVar2 & 0xffffff | 0x6000000;
    *puVar2 = (uint)puVar3 & 0xffffff;
    *(uint **)(DAT_800d210c + 4) = puVar3 + 7;
  }
  return;
}



// decompiled code
// original method signature: 
// struct POLY_GT4 * /*$ra*/ FX_SetupPolyGT4(int x1 /*$a0*/, int y1 /*$a1*/, int x2 /*$a2*/, int y2 /*$a3*/, int otz /*stack 16*/, struct TextureMT3 *texture /*stack 20*/, long color0 /*stack 24*/, long color1 /*stack 28*/, long color2 /*stack 32*/, long color3 /*stack 36*/)
 // line 2996, offset 0x80046d98
	/* begin block 1 */
		// Start line: 2997
		// Start offset: 0x80046D98
		// Variables:
	// 		struct POLY_GT4 *poly; // $t0
	// 		unsigned long **drawot; // $t3
	/* end block 1 */
	// End offset: 0x80046E94
	// End Line: 3028

	/* begin block 2 */
		// Start line: 7423
	/* end block 2 */
	// End Line: 7424

	/* begin block 3 */
		// Start line: 7427
	/* end block 3 */
	// End Line: 7428

/* File: C:\kain2\game\FX.C */

POLY_GT4 *
FX_SetupPolyGT4(int x1,int y1,int x2,int y2,int otz,TextureMT3 *texture,long color0,long color1,
               long color2,long color3)

{
  undefined2 uVar1;
  int iVar2;
  uint *puVar3;
  POLY_GT4 *pPVar4;
  
  iVar2 = DAT_800d22a4;
  pPVar4 = *(POLY_GT4 **)(DAT_800d210c + 4);
  if (*(POLY_GT4 **)(DAT_800d210c + 8) <= pPVar4 + 1) {
    return (POLY_GT4 *)0x0;
  }
  *(undefined2 *)&pPVar4->u0 = *(undefined2 *)&texture->u2;
  *(undefined2 *)&pPVar4->u1 = *(undefined2 *)&texture->u1;
  uVar1 = *(undefined2 *)texture;
  pPVar4->x2 = (short)x1;
  pPVar4->x0 = (short)x1;
  pPVar4->x1 = (short)x2;
  pPVar4->x3 = (short)x2;
  pPVar4->y1 = (short)y1;
  pPVar4->y0 = (short)y1;
  pPVar4->y2 = (short)y2;
  pPVar4->y3 = (short)y2;
  *(undefined2 *)&pPVar4->u2 = uVar1;
  *(uint *)&pPVar4->r0 = color0 | 0x3c000000;
  *(long *)&pPVar4->r1 = color1;
  *(long *)&pPVar4->r2 = color2;
  pPVar4->u3 = pPVar4->u1;
  pPVar4->v3 = pPVar4->v2;
  *(long *)&pPVar4->r3 = color3;
  pPVar4->tpage = texture->tpage;
  pPVar4->clut = texture->clut;
  if (otz < 1) {
    otz = 1;
  }
  puVar3 = (uint *)(otz * 4 + iVar2);
  pPVar4->tag = *puVar3 & 0xffffff | 0xc000000;
  *puVar3 = (uint)pPVar4 & 0xffffff;
  *(POLY_GT4 **)(DAT_800d210c + 4) = pPVar4 + 1;
  return pPVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeWarpArrow(int x /*$s1*/, int y /*$s3*/, int xsize /*$s2*/, int ysize /*$s4*/, int fade /*stack 16*/)
 // line 3057, offset 0x80046e9c
	/* begin block 1 */
		// Start line: 3058
		// Start offset: 0x80046E9C
		// Variables:
	// 		struct Object *particle; // $a0
	// 		long color; // $s0
	// 		struct POLY_GT4 *poly; // $v1
	/* end block 1 */
	// End offset: 0x80046F5C
	// End Line: 3074

	/* begin block 2 */
		// Start line: 6111
	/* end block 2 */
	// End Line: 6112

/* WARNING: Removing unreachable block (ram,0x80046eec) */
/* File: C:\kain2\game\FX.C */

void FX_MakeWarpArrow(int x,int y,int xsize,int ysize,int fade)

{
  TextureMT3 *texture;
  POLY_GT4 *pPVar1;
  uint color0;
  
  if (objectAccess[10].object != (void *)0x0) {
    color0 = fade >> 5;
    if (fade < 0) {
      color0 = 0;
    }
    color0 = color0 | color0 << 8 | color0 << 0x10;
    texture = FX_GetTextureObject((Object *)objectAccess[10].object,0,9);
    pPVar1 = FX_SetupPolyGT4(x + xsize,y,x,y + ysize,3,texture,color0,color0,color0,color0);
    if (pPVar1 != (POLY_GT4 *)0x0) {
      pPVar1->code = pPVar1->code | 2;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeMannaIcon(int x /*$s0*/, int y /*$s2*/, int xsize /*$s1*/, int ysize /*$s3*/)
 // line 3077, offset 0x80046f7c
	/* begin block 1 */
		// Start line: 3078
		// Start offset: 0x80046F7C
		// Variables:
	// 		struct Object *manna; // $a0
	/* end block 1 */
	// End offset: 0x80046FF4
	// End Line: 3088

	/* begin block 2 */
		// Start line: 7594
	/* end block 2 */
	// End Line: 7595

/* File: C:\kain2\game\FX.C */

void FX_MakeMannaIcon(int x,int y,int xsize,int ysize)

{
  TextureMT3 *texture;
  
  if (objectAccess[20].object != (void *)0x0) {
    texture = FX_GetTextureObject((Object *)objectAccess[20].object,0,7);
    FX_SetupPolyGT4(x,y,x + xsize,y + ysize,3,texture,0x808080,0x808080,0x808080,0x808080);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeGlyphIcon(struct _Position *position /*$s4*/, struct Object *glyphObject /*$s3*/, int size /*$s0*/, int glyphnum /*$s1*/, int enabled /*stack 16*/)
 // line 3161, offset 0x80047010
	/* begin block 1 */
		// Start line: 3162
		// Start offset: 0x80047010
		// Variables:
	// 		int sizex; // $t0
	// 		struct POLY_GT4 *poly; // $v1
	// 		struct TextureMT3 *texture; // $s2
	// 		struct DVECTOR xy_pos; // stack offset -40
	// 		int otz; // $t1
	// 		long *color_array; // $v0
	// 		struct _GlyphTuneData *glyphtunedata; // $v1

		/* begin block 1.1 */
			// Start line: 3175
			// Start offset: 0x80047054
			// Variables:
		// 		struct Object *object; // $a0
		/* end block 1.1 */
		// End offset: 0x80047068
		// End Line: 3178
	/* end block 1 */
	// End offset: 0x800471B0
	// End Line: 3214

	/* begin block 2 */
		// Start line: 6293
	/* end block 2 */
	// End Line: 6294

/* File: C:\kain2\game\FX.C */

void FX_MakeGlyphIcon(_Position *position,Object *glyphObject,int size,int glyphnum,int enabled)

{
  short sVar1;
  short sVar2;
  int iVar3;
  TextureMT3 *texture;
  undefined *color3;
  POLY_GT4 *pPVar4;
  undefined4 *puVar5;
  int iVar6;
  int x1;
  int y1;
  undefined *local_38;
  undefined *local_34;
  undefined *local_30;
  
  if (glyphObject != (Object *)0x0) {
    if (glyphnum == 7) {
      if (objectAccess[10].object == (void *)0x0) {
        return;
      }
      texture = FX_GetTextureObject((Object *)objectAccess[10].object,0,0);
      size = size / 2;
    }
    else {
      texture = FX_GetTextureObject(glyphObject,0,glyphnum);
    }
    sVar1 = position->x;
    iVar6 = -size + 0x18;
    sVar2 = position->y;
    iVar3 = (size << 9) / 0x140;
    if (iVar6 < 0) {
      iVar6 = -size + 0x1b;
    }
    if (enabled == 0) {
      color3 = &LAB_00202020;
      x1 = sVar1 - iVar3;
      y1 = sVar2 - size;
      local_38 = &LAB_00202020;
      local_34 = &LAB_00202020;
      local_30 = &LAB_00202020;
    }
    else {
      puVar5 = (undefined4 *)((int)glyphObject->data + glyphnum * 0x10 + 0x1c);
      x1 = sVar1 - iVar3;
      y1 = sVar2 - size;
      local_38 = (undefined *)*puVar5;
      local_34 = (undefined *)puVar5[1];
      local_30 = (undefined *)puVar5[2];
      color3 = (undefined *)puVar5[3];
    }
    pPVar4 = FX_SetupPolyGT4(x1,y1,sVar1 + iVar3 + 1,sVar2 + size + 1,(iVar6 >> 2) + 1,texture,
                             (long)local_38,(long)local_34,(long)local_30,(long)color3);
    if (pPVar4 != (POLY_GT4 *)0x0) {
      pPVar4->code = *(byte *)((int)&texture->color + 3) & 3 | 0x3c;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SoulDustProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 3217, offset 0x800471d4
	/* begin block 1 */
		// Start line: 3218
		// Start offset: 0x800471D4
		// Variables:
	// 		struct MATRIX *swTransform; // $v1
	// 		struct _Position position; // stack offset -24
	// 		long color; // stack offset -16
	// 		long black; // stack offset -12
	// 		int fade; // $a3
	/* end block 1 */
	// End offset: 0x80047378
	// End Line: 3255

	/* begin block 2 */
		// Start line: 7831
	/* end block 2 */
	// End Line: 7832

/* File: C:\kain2\game\FX.C */

void FX_SoulDustProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  int iVar3;
  long p1;
  undefined *local_10;
  undefined4 local_c;
  
  if (fxPrim->work1 < 0x20) {
    FX_Die(fxPrim,fxTracker);
  }
  else {
    sVar2 = fxPrim->work2;
    iVar3 = *(int *)(*(int *)&fxPrim->duo + 0x40) + *(int *)((int)&fxPrim->duo + 4) * 0x20;
    (fxPrim->position).x = *(short *)(iVar3 + 0x14);
    sVar2 = (fxPrim->v1).x + sVar2;
    (fxPrim->position).y = *(short *)(iVar3 + 0x18);
    sVar1 = *(short *)(iVar3 + 0x1c);
    (fxPrim->v1).x = sVar2;
    (fxPrim->position).z = sVar1;
    iVar3 = rcos((int)sVar2);
    iVar3 = iVar3 * fxPrim->work1;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0xfff;
    }
    (fxPrim->position).x = (fxPrim->position).x + (short)(iVar3 >> 0xc);
    iVar3 = rsin((int)(fxPrim->v1).x);
    iVar3 = iVar3 * fxPrim->work1;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0xfff;
    }
    (fxPrim->position).y = (fxPrim->position).y + (short)(iVar3 >> 0xc);
    iVar3 = rcos((int)(fxPrim->v1).y);
    iVar3 = iVar3 * fxPrim->work0;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0xfff;
    }
    local_10 = &DAT_0060ff60;
    local_c = 0;
    sVar2 = (fxPrim->v2).x;
    (fxPrim->v0).y = (fxPrim->v0).y + -0x90;
    p1 = (long)(fxPrim->v0).y;
    (fxPrim->position).z = (fxPrim->position).z + (short)(iVar3 >> 0xc);
    sVar1 = (fxPrim->v1).y;
    fxPrim->work1 = fxPrim->work1 - sVar2;
    (fxPrim->v1).y = sVar1 + 0x40;
    if (p1 < 0) {
      p1 = 0;
    }
    LoadAverageCol((u_char *)&local_10,(u_char *)&local_c,0x1000 - p1,p1,(u_char *)&fxPrim->color);
    fxPrim->color = fxPrim->color & 0xffffffU | 0x2e000000;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeSoulDust(struct _Instance *instance /*$s4*/, short segment /*$a1*/)
 // line 3256, offset 0x80047388
	/* begin block 1 */
		// Start line: 3257
		// Start offset: 0x80047388
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s1
	// 		struct SVECTOR location; // stack offset -32
	// 		struct Object *particle; // $s2
	/* end block 1 */
	// End offset: 0x800475A8
	// End Line: 3308

	/* begin block 2 */
		// Start line: 7959
	/* end block 2 */
	// End Line: 7960

/* File: C:\kain2\game\FX.C */

void FX_MakeSoulDust(_Instance *instance,short segment)

{
  short sVar1;
  void *object;
  _FXTracker *fxTracker;
  uint uVar2;
  _FX_PRIM *fxPrim;
  TextureMT3 *pTVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = rand();
  object = objectAccess[10].object;
  if ((((uVar2 & 0xff) < 0x41) && (objectAccess[10].object != (void *)0x0)) &&
     (fxPrim = FX_GetPrim(gFXT), fxPrim != (_FX_PRIM *)0x0)) {
    rand();
    FX_DFacadeParticleSetup(fxPrim,0xe0,0x19,0x19,0x2e000000,0,0,gFXT,8);
    fxPrim->flags = fxPrim->flags | 0x2001;
    pTVar3 = FX_GetTextureObject((Object *)object,0,0);
    fxPrim->texture = pTVar3;
    (fxPrim->v0).y = 0x1000;
    *(code **)&fxPrim->process = FX_SoulDustProcess;
    fxPrim->color = 0x2e000000;
    (fxPrim->v1).y = 0;
    *(_Instance **)&fxPrim->duo = instance;
    *(int *)((int)&fxPrim->duo + 4) = (int)segment;
    iVar4 = rand();
    fxPrim->work0 = (short)iVar4 + (short)(iVar4 / 0x140) * -0x140 + -0xa0;
    iVar4 = rand();
    fxPrim->work1 = ((ushort)iVar4 & 0x3f) + 0x140;
    iVar4 = rand();
    iVar4 = iVar4 % 0x380 + 0x80;
    iVar5 = iVar4 * 0x10000 >> 0x10;
    (fxPrim->v1).x = (short)iVar4;
    if (iVar5 < 0) {
      iVar5 = iVar5 + 0xf;
    }
    iVar4 = (int)fxPrim->work1;
    fxPrim->work2 = (short)(iVar5 >> 4);
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0xf;
    }
    (fxPrim->v2).x = (short)(iVar4 >> 4);
    uVar2 = rand();
    if ((uVar2 & 1) != 0) {
      sVar1 = fxPrim->work2;
      (fxPrim->v1).x = -(fxPrim->v1).x;
      fxPrim->work2 = -sVar1;
    }
    fxTracker = gFXT;
    (fxPrim->v1).x = (instance->rotation).z - ((fxPrim->v1).x + 0x400);
    FX_SoulDustProcess(fxPrim,fxTracker);
    FX_Sprite_Insert(&gFXT->usedPrimListSprite,fxPrim);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_WaterTrailProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 3331, offset 0x800475c8
	/* begin block 1 */
		// Start line: 6656
	/* end block 1 */
	// End Line: 6657

/* File: C:\kain2\game\FX.C */

void FX_WaterTrailProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  
  FX_StandardProcess(fxPrim,fxTracker);
  (fxPrim->v0).x = (short)((int)(fxPrim->v0).x * 7 >> 3);
  (fxPrim->v0).y = (short)((int)(fxPrim->v0).y * 7 >> 3);
  sVar1 = (fxPrim->v1).x;
  (fxPrim->v0).z = (short)((int)(fxPrim->v0).z * 7 >> 3);
  (fxPrim->v1).x = (short)((int)sVar1 * 7 >> 3);
  (fxPrim->v1).y = (short)((int)(fxPrim->v1).y * 7 >> 3);
  sVar1 = (fxPrim->v2).x;
  (fxPrim->v1).z = (short)((int)(fxPrim->v1).z * 7 >> 3);
  (fxPrim->v2).x = (short)((int)sVar1 * 7 >> 3);
  (fxPrim->v2).y = (short)((int)(fxPrim->v2).y * 7 >> 3);
  sVar1 = (fxPrim->v3).x;
  (fxPrim->v2).z = (short)((int)(fxPrim->v2).z * 7 >> 3);
  (fxPrim->v3).x = (short)((int)sVar1 * 7 >> 3);
  (fxPrim->v3).y = (short)((int)(fxPrim->v3).y * 7 >> 3);
  (fxPrim->v3).z = (short)((int)(fxPrim->v3).z * 7 >> 3);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeWaterTrail(struct _Instance *instance /*$a0*/, int depth /*$a1*/)
 // line 3350, offset 0x800476e0
	/* begin block 1 */
		// Start line: 3351
		// Start offset: 0x800476E0
		// Variables:
	// 		struct Object *waterfx; // $a1
	// 		struct _Model *wxtrail; // $a0
	// 		struct _SVector position; // stack offset -48
	// 		int zvel; // $s0

		/* begin block 1.1 */
			// Start line: 3387
			// Start offset: 0x800477EC
			// Variables:
		// 		int n; // $s2
		// 		int deg; // $s0
		// 		struct _SVector vel; // stack offset -40
		// 		struct _SVector accel; // stack offset -32
		// 		struct _SVector startpos; // stack offset -24

			/* begin block 1.1.1 */
				// Start line: 3395
				// Start offset: 0x80047804
				// Variables:
			// 		int sinVal; // $s1
			// 		int cosVal; // $s0
			// 		int spd; // $v1
			/* end block 1.1.1 */
			// End offset: 0x80047898
			// End Line: 3403
		/* end block 1.1 */
		// End offset: 0x800478FC
		// End Line: 3408
	/* end block 1 */
	// End offset: 0x800478FC
	// End Line: 3409

	/* begin block 2 */
		// Start line: 8152
	/* end block 2 */
	// End Line: 8153

/* File: C:\kain2\game\FX.C */

void FX_MakeWaterTrail(_Instance *instance,int depth)

{
  int *piVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  _Model *model;
  int iVar7;
  int iVar8;
  int iVar9;
  _SVector local_28;
  _SVector local_20;
  _SVector local_18;
  
  if ((((instance->matrix != (MATRIX *)0x0) && (instance->oldMatrix != (MATRIX *)0x0)) &&
      (DAT_800d20d6 != 1)) && (DAT_800d20d4 == 1000)) {
    sVar2 = *(short *)instance->matrix[1].t;
    sVar3 = *(short *)(instance->matrix[1].t + 1);
    local_18.z = (instance->splitPoint).z;
    iVar7 = instance->matrix[1].t[2] - instance->oldMatrix[1].t[2];
    if (objectAccess[3].object != (void *)0x0) {
      piVar1 = (int *)((int)objectAccess[3].object + 0xc);
      *(uint *)((int)objectAccess[3].object + 0x2c) =
           *(uint *)((int)objectAccess[3].object + 0x2c) | 0x20000000;
      model = *(_Model **)(*piVar1 + 4);
      FX_BuildSingleFaceWithModel
                (model,model->faceList,0xd0,0,0,gFXT,FX_SimpleQuadSetup,FX_WaterTrailProcess,8);
    }
    if (iVar7 < 0) {
      iVar7 = -iVar7;
    }
    iVar8 = 0;
    if (0x14 < iVar7) {
      local_20.y = 0;
      local_20.x = 0;
      local_20.z = -2;
      do {
        uVar4 = rand();
        iVar7 = rcos(uVar4 & 0xfff);
        iVar5 = rsin(uVar4 & 0xfff);
        uVar4 = rand();
        iVar6 = (uVar4 & 3) + 0xb;
        iVar9 = iVar7 * iVar6;
        iVar6 = iVar5 * iVar6;
        if (iVar9 < 0) {
          iVar9 = iVar9 + 0xfff;
        }
        local_28.x = (short)(iVar9 >> 0xc);
        if (iVar6 < 0) {
          iVar6 = iVar6 + 0xfff;
        }
        local_28.y = (short)(iVar6 >> 0xc);
        local_28.z = 0x12;
        if (iVar7 < 0) {
          iVar7 = iVar7 + 0x7f;
        }
        local_18.x = sVar2 + (short)(iVar7 >> 7);
        if (iVar5 < 0) {
          iVar5 = iVar5 + 0x7f;
        }
        iVar8 = iVar8 + 1;
        local_18.y = sVar3 + (short)(iVar5 >> 7);
        FX_Dot(&local_18,&local_28,&local_20,0,(long)&DAT_00404040,0x18,0x14,0);
      } while (iVar8 < 8);
      INSTANCE_Post(DAT_800d20f8,0x40024,0);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// struct _FXRibbon * /*$ra*/ FX_StartRibbon(struct _Instance *instance /*$s7*/, short startSegment /*$s3*/, short endSegment /*stack -48*/, short type /*$fp*/, int ribbonLifeTime /*stack 16*/, int faceLifeTime /*stack 20*/, int startFadeValue /*stack 24*/, long startColor /*stack 28*/, long endColor /*stack 32*/)
 // line 3444, offset 0x80047914
	/* begin block 1 */
		// Start line: 3445
		// Start offset: 0x80047914
		// Variables:
	// 		struct MATRIX *swTransform; // $a0
	// 		struct _FXRibbon *ribbon; // $s0
	// 		int i; // $a2
	// 		int number; // $s1
	/* end block 1 */
	// End offset: 0x80047BB4
	// End Line: 3527

	/* begin block 2 */
		// Start line: 6866
	/* end block 2 */
	// End Line: 6867

/* File: C:\kain2\game\FX.C */

_FXRibbon *
FX_StartRibbon(_Instance *instance,short startSegment,short endSegment,short type,int ribbonLifeTime
              ,int faceLifeTime,int startFadeValue,long startColor,long endColor)

{
  short sVar1;
  _FXRibbon *ptr;
  SVECTOR *pSVar2;
  int iVar3;
  MATRIX *pMVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = ((int)endSegment - (int)startSegment) + 1;
  if ((iVar7 < 2) || (ptr = (_FXRibbon *)MEMPACK_Malloc(0x2c,'\r'), ptr == (_FXRibbon *)0x0)) {
    return (_FXRibbon *)0x0;
  }
  *(code **)&ptr->continue_process = FX_ContinueRibbon;
  ptr->effectType = '\0';
  ptr->endIndex = 0;
  if (type == 1) {
    sVar1 = (short)iVar7 * 2;
  }
  else {
    sVar1 = 4;
  }
  ptr->numberVerts = sVar1;
  pSVar2 = (SVECTOR *)MEMPACK_Malloc((int)ptr->numberVerts << 3,'\r');
  ptr->vertexPool = pSVar2;
  if (pSVar2 == (SVECTOR *)0x0) {
    MEMPACK_Free((char *)ptr);
    return (_FXRibbon *)0x0;
  }
  ptr->faceLifeTime = (short)faceLifeTime;
  ptr->startSegment = startSegment;
  ptr->instance = instance;
  ptr->type = (uchar)type;
  ptr->lifeTime = (short)ribbonLifeTime;
  ptr->endSegment = endSegment;
  ptr->startColor = startColor;
  ptr->startFadeValue = (short)startFadeValue;
  ptr->endColor = endColor;
  ptr->colorStepValue = (short)(0x1000 / (int)(short)faceLifeTime);
  sVar1 = (short)((0x1000 - (int)(short)startFadeValue) / (int)ptr->faceLifeTime);
  ptr->fadeStep = sVar1;
  if ((type & 0xffU) == 2) {
    iVar3 = (int)sVar1 * 6;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 7;
    }
    ptr->fadeStep = (short)(iVar3 >> 3);
  }
  pMVar4 = instance->matrix;
  if (pMVar4 == (MATRIX *)0x0) {
    sVar1 = -1;
  }
  else {
    iVar3 = (int)((uint)(ushort)startSegment << 0x10) >> 0xb;
    if (ptr->type == '\x01') {
      if (0 < iVar7) {
        psVar5 = (short *)((int)pMVar4->t + iVar3 + 8);
        iVar3 = 0;
        do {
          iVar6 = iVar3 + 1;
          ptr->vertexPool[iVar3].vx = psVar5[-4];
          ptr->vertexPool[iVar3].vy = psVar5[-2];
          ptr->vertexPool[iVar3].vz = *psVar5;
          ptr->endIndex = ptr->endIndex + 1;
          psVar5 = psVar5 + 0x10;
          iVar3 = iVar6;
        } while (iVar6 < iVar7);
      }
      goto LAB_80047ba8;
    }
    iVar3 = (int)pMVar4->m + iVar3;
    ptr->vertexPool->vx = *(short *)(iVar3 + 0x14);
    ptr->vertexPool->vy = *(short *)(iVar3 + 0x18);
    ptr->vertexPool->vz = *(short *)(iVar3 + 0x1c);
    iVar7 = (int)instance->matrix->m + ((int)((uint)(ushort)endSegment << 0x10) >> 0xb);
    ptr->vertexPool[1].vx = *(short *)(iVar7 + 0x14);
    ptr->vertexPool[1].vy = *(short *)(iVar7 + 0x18);
    ptr->vertexPool[1].vz = *(short *)(iVar7 + 0x1c);
    sVar1 = 2;
  }
  ptr->endIndex = sVar1;
LAB_80047ba8:
  FX_InsertGeneralEffect(ptr);
  return ptr;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_RibbonProcess(struct _FX_PRIM *fxPrim /*$a2*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 3548, offset 0x80047be4
	/* begin block 1 */
		// Start line: 3549
		// Start offset: 0x80047BE4
		// Variables:
	// 		int d; // $a1
	// 		long fade; // $a3
	/* end block 1 */
	// End offset: 0x80047CC8
	// End Line: 3588

	/* begin block 2 */
		// Start line: 7091
	/* end block 2 */
	// End Line: 7092

/* File: C:\kain2\game\FX.C */

void FX_RibbonProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  _FX_PRIM *p_Var2;
  int iVar3;
  
  if (0 < fxPrim->timeToLive) {
    fxPrim->timeToLive = fxPrim->timeToLive + -1;
  }
  if (fxPrim->timeToLive == 0) {
    FX_Die(fxPrim,fxTracker);
  }
  else {
    iVar3 = 0;
    p_Var2 = fxPrim;
    do {
      sVar1 = p_Var2->fadeValue[0] + fxPrim->fadeStep;
      p_Var2->fadeValue[0] = sVar1;
      if (0x1000 < sVar1) {
        p_Var2->fadeValue[0] = 0x1000;
      }
      iVar3 = iVar3 + 1;
      p_Var2 = (_FX_PRIM *)((int)&(p_Var2->node).prev + 2);
    } while (iVar3 < 4);
    if (fxPrim->startColor != fxPrim->endColor) {
      sVar1 = fxPrim->colorFadeValue + fxPrim->colorFadeStep;
      fxPrim->colorFadeValue = sVar1;
      if (0x1000 < sVar1) {
        fxPrim->colorFadeValue = 0x1000;
      }
      LoadAverageCol((u_char *)&fxPrim->startColor,(u_char *)&fxPrim->endColor,
                     0x1000 - (int)fxPrim->colorFadeValue,(int)fxPrim->colorFadeValue,
                     (u_char *)&fxPrim->color);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ConstrictProcess(struct _FX_PRIM *fxPrim /*$s1*/, struct _FXTracker *fxTracker /*$s2*/)
 // line 3591, offset 0x80047cd8
	/* begin block 1 */
		// Start line: 8680
	/* end block 1 */
	// End Line: 8681

/* File: C:\kain2\game\FX.C */

void FX_ConstrictProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  short sVar3;
  long lVar4;
  int iVar5;
  
  if (FX_ConstrictStage == 1) {
    fxPrim->startColor = 0xffffff;
    sVar3 = fxPrim->work2;
    fxPrim->timeToLive = 0x28;
    fxPrim->fadeStep = 0x66;
    fxPrim->fadeValue[3] = 0;
    fxPrim->fadeValue[2] = 0;
    fxPrim->fadeValue[1] = 0;
    fxPrim->fadeValue[0] = 0;
    fxPrim->work1 = 0x380;
    fxPrim->work0 = 0x380;
    fxPrim->work1 = 0;
    if (sVar3 == 0) {
      sVar3 = (fxPrim->v0).y;
      fxPrim->fadeValue[1] = 0;
      fxPrim->fadeValue[0] = 0;
      fxPrim->fadeValue[3] = 0x1000;
      fxPrim->fadeValue[2] = 0x1000;
      lVar4 = ratan2((int)sVar3 - (int)FX_ConstrictPosition.y,
                     (int)(fxPrim->v0).x - (int)FX_ConstrictPosition.x);
      sVar3 = (fxPrim->v1).y;
      fxPrim->work2 = (short)lVar4;
      lVar4 = ratan2((int)sVar3 - (int)FX_ConstrictPosition.y,
                     (int)(fxPrim->v1).x - (int)FX_ConstrictPosition.x);
      sVar3 = (fxPrim->v2).z;
      sVar2 = (fxPrim->v0).z;
      sVar1 = (fxPrim->v0).z;
      fxPrim->work3 = (short)lVar4;
      iVar5 = (int)sVar3 - (int)sVar2;
      if (iVar5 < 0) {
        iVar5 = iVar5 + 3;
      }
      (fxPrim->v2).z = sVar1 + (short)(iVar5 >> 2);
      (fxPrim->v3).z = (fxPrim->v1).z + ((fxPrim->v3).z - (fxPrim->v1).z) * 3;
    }
    else {
      sVar3 = (fxPrim->v2).y;
      fxPrim->fadeValue[1] = 0x1000;
      fxPrim->fadeValue[0] = 0x1000;
      fxPrim->fadeValue[3] = 0;
      fxPrim->fadeValue[2] = 0;
      lVar4 = ratan2((int)sVar3 - (int)FX_ConstrictPosition.y,
                     (int)(fxPrim->v2).x - (int)FX_ConstrictPosition.x);
      sVar3 = (fxPrim->v3).y;
      fxPrim->work2 = (short)lVar4;
      lVar4 = ratan2((int)sVar3 - (int)FX_ConstrictPosition.y,
                     (int)(fxPrim->v3).x - (int)FX_ConstrictPosition.x);
      sVar3 = (fxPrim->v0).z;
      sVar2 = (fxPrim->v2).z;
      sVar1 = (fxPrim->v2).z;
      fxPrim->work3 = (short)lVar4;
      iVar5 = (int)sVar3 - (int)sVar2;
      if (iVar5 < 0) {
        iVar5 = iVar5 + 3;
      }
      (fxPrim->v0).z = sVar1 + (short)(iVar5 >> 2);
      (fxPrim->v1).z = (fxPrim->v3).z + ((fxPrim->v1).z - (fxPrim->v3).z) * 3;
    }
    sVar3 = FX_ConstrictPosition.x;
    (fxPrim->v1).x = FX_ConstrictPosition.x;
    (fxPrim->v3).x = sVar3;
    sVar3 = FX_ConstrictPosition.y;
    (fxPrim->v1).y = FX_ConstrictPosition.y;
    (fxPrim->v3).y = sVar3;
  }
  else {
    if ((0 < fxPrim->work0) || (0 < fxPrim->work1)) {
      fxPrim->work0 = fxPrim->work0 + -0x28;
      sVar3 = fxPrim->work2 + -0x40;
      fxPrim->work2 = sVar3;
      iVar5 = rcos((int)sVar3);
      sVar3 = fxPrim->work2;
      sVar2 = FX_ConstrictPosition.x + (short)(fxPrim->work0 * iVar5 >> 0xc);
      (fxPrim->v0).x = sVar2;
      (fxPrim->v2).x = sVar2;
      iVar5 = rsin((int)sVar3);
      sVar3 = FX_ConstrictPosition.y + (short)(fxPrim->work0 * iVar5 >> 0xc);
      (fxPrim->v0).y = sVar3;
      (fxPrim->v2).y = sVar3;
    }
  }
  FX_RibbonProcess(fxPrim,fxTracker);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartConstrict(struct _Instance *instance /*$a0*/, struct _SVector *constrict_point /*$a1*/, short startSegment /*$a2*/, short endSegment /*$a3*/)
 // line 3657, offset 0x80047f68
	/* begin block 1 */
		// Start line: 8847
	/* end block 1 */
	// End Line: 8848

	/* begin block 2 */
		// Start line: 8848
	/* end block 2 */
	// End Line: 8849

/* File: C:\kain2\game\FX.C */

void FX_StartConstrict(_Instance *instance,_SVector *constrict_point,short startSegment,
                      short endSegment)

{
  if (FX_ConstrictRibbon == (_FXRibbon *)0x0) {
    if (constrict_point != (_SVector *)0x0) {
      FX_ConstrictPosition.x = constrict_point->x;
      FX_ConstrictPosition.y = constrict_point->y;
      FX_ConstrictPosition.z = (instance->position).z + 0x100;
      FX_ConstrictPositionPtr = (_Position *)constrict_point;
    }
    FX_ConstrictRibbon =
         FX_StartRibbon(instance,startSegment,endSegment,2,-1,0x28,0,0xe84040,0xe84040);
    FX_ConstrictStage = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_EndConstrict(int ConstrictEnemyFlag /*$a0*/, struct _Instance *instance /*$a1*/)
 // line 3674, offset 0x80047ff8
	/* begin block 1 */
		// Start line: 3675
		// Start offset: 0x80047FF8

		/* begin block 1.1 */
			// Start line: 3682
			// Start offset: 0x80048018
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x80048018
		// End Line: 3682

		/* begin block 1.2 */
			// Start line: 3686
			// Start offset: 0x80048024
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.2 */
		// End offset: 0x8004804C
		// End Line: 3686
	/* end block 1 */
	// End offset: 0x8004804C
	// End Line: 3690

	/* begin block 2 */
		// Start line: 8885
	/* end block 2 */
	// End Line: 8886

/* File: C:\kain2\game\FX.C */

void FX_EndConstrict(int ConstrictEnemyFlag,_Instance *instance)

{
  _Position *p_Var1;
  
  if (ConstrictEnemyFlag != 0) {
    FX_ConstrictStage = 1;
    if (instance == (_Instance *)0x0) {
      FX_ConstrictPosition.x = FX_ConstrictPositionPtr->x;
      p_Var1 = FX_ConstrictPositionPtr;
    }
    else {
      FX_ConstrictPosition.x = (instance->position).x;
      p_Var1 = (_Position *)&instance->position;
    }
    FX_ConstrictPosition.y = p_Var1->y;
    FX_ConstrictPosition.z = p_Var1->z;
    FX_ConstrictInstance = instance;
  }
  FX_DeleteGeneralEffect(FX_ConstrictRibbon);
  FX_ConstrictRibbon = (_FXGeneralEffect *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SubDividePrim(struct _FX_PRIM *fxPrim1 /*$s0*/, struct _FX_PRIM *fxPrim2 /*$s1*/)
 // line 3694, offset 0x80048068
	/* begin block 1 */
		// Start line: 3695
		// Start offset: 0x80048068
		// Variables:
	// 		struct SVECTOR mp0; // stack offset -32
	// 		struct SVECTOR mp1; // stack offset -24
	/* end block 1 */
	// End offset: 0x80048068
	// End Line: 3695

	/* begin block 2 */
		// Start line: 8926
	/* end block 2 */
	// End Line: 8927

/* File: C:\kain2\game\FX.C */

void FX_SubDividePrim(_FX_PRIM *fxPrim1,_FX_PRIM *fxPrim2)

{
  undefined4 local_20;
  short local_1c;
  undefined4 local_18;
  short local_14;
  
  LoadAverageShort12((SVECTOR *)&fxPrim1->v0,(SVECTOR *)&fxPrim2->v2,0x800,0x800,
                     (SVECTOR *)&local_20);
  LoadAverageShort12((SVECTOR *)&fxPrim1->v1,(SVECTOR *)&fxPrim2->v3,0x800,0x800,
                     (SVECTOR *)&local_18);
  *(undefined4 *)&fxPrim1->v2 = local_20;
  (fxPrim1->v2).z = local_1c;
  *(undefined4 *)&fxPrim1->v3 = local_18;
  (fxPrim1->v3).z = local_14;
  *(undefined4 *)&fxPrim2->v0 = local_20;
  (fxPrim2->v0).z = local_1c;
  *(undefined4 *)&fxPrim2->v1 = local_18;
  (fxPrim2->v1).z = local_14;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueRibbon(struct _FXRibbon *ribbon /*$s2*/, struct _FXTracker *fxTracker /*$fp*/)
 // line 3742, offset 0x8004812c
	/* begin block 1 */
		// Start line: 3743
		// Start offset: 0x8004812C
		// Variables:
	// 		struct MATRIX *swTransform; // $a1
	// 		int i; // $s3
	// 		int i2; // $s7
	// 		int i3; // $v1
	// 		int startIndex; // $a2
	// 		int period; // stack offset -48
	// 		int d; // $s5
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct _FX_PRIM *fxPrim2; // $s1
	// 		struct SVECTOR Quad[4]; // stack offset -80

		/* begin block 1.1 */
			// Start line: 3870
			// Start offset: 0x800485A8
			// Variables:
		// 		int fade; // $v1
		/* end block 1.1 */
		// End offset: 0x8004863C
		// End Line: 3894
	/* end block 1 */
	// End offset: 0x800486C4
	// End Line: 3909

	/* begin block 2 */
		// Start line: 9025
	/* end block 2 */
	// End Line: 9026

/* WARNING: Could not reconcile some variable overlaps */
/* File: C:\kain2\game\FX.C */

void FX_ContinueRibbon(_FXRibbon *ribbon,_FXTracker *fxTracker)

{
  int iVar1;
  undefined4 *puVar2;
  _FX_PRIM *fxPrim1;
  long lVar3;
  code *pcVar4;
  _FX_PRIM *fxPrim2;
  _FX_PRIM *p_Var5;
  short sVar6;
  MATRIX *pMVar7;
  int iVar8;
  _FX_PRIM *p_Var9;
  long *plVar10;
  int iVar11;
  NodeType *pNVar12;
  TextureMT3 *pTVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  undefined4 local_50;
  undefined4 local_4c;
  short local_44;
  short local_3c;
  undefined4 local_38;
  undefined4 local_34;
  
  if ((ribbon != (_FXRibbon *)0x0) && (pMVar7 = ribbon->instance->matrix, pMVar7 != (MATRIX *)0x0))
  {
    iVar11 = (int)ribbon->endIndex;
    pMVar7 = pMVar7 + ribbon->startSegment;
    if (iVar11 == -1) {
      ribbon->endIndex = 0;
    }
    iVar1 = (uint)(ushort)ribbon->numberVerts << 0x10;
    iVar1 = (iVar1 >> 0x10) - (iVar1 >> 0x1f) >> 1;
    if (ribbon->type == '\x01') {
      sVar6 = ribbon->endIndex;
      plVar10 = pMVar7->t + 2;
      iVar20 = (int)sVar6;
      while (iVar20 < (int)sVar6 + iVar1) {
        ribbon->vertexPool[iVar20].vx = *(short *)(plVar10 + -2);
        ribbon->vertexPool[iVar20].vy = *(short *)(plVar10 + -1);
        ribbon->vertexPool[iVar20].vz = *(short *)plVar10;
        ribbon->endIndex = ribbon->endIndex + 1;
        plVar10 = plVar10 + 8;
        iVar20 = iVar20 + 1;
      }
    }
    else {
      iVar20 = (int)ribbon->endIndex;
      iVar19 = iVar20 + 1;
      ribbon->vertexPool[iVar20].vx = *(short *)pMVar7->t;
      ribbon->vertexPool[iVar20].vy = *(short *)(pMVar7->t + 1);
      ribbon->vertexPool[iVar20].vz = *(short *)(pMVar7->t + 2);
      pMVar7 = ribbon->instance->matrix + ribbon->endSegment;
      ribbon->vertexPool[iVar19].vx = *(short *)pMVar7->t;
      ribbon->vertexPool[iVar19].vy = *(short *)(pMVar7->t + 1);
      ribbon->vertexPool[iVar19].vz = *(short *)(pMVar7->t + 2);
      ribbon->endIndex = ribbon->endIndex + 2;
    }
    iVar20 = (int)ribbon->endIndex;
    if (ribbon->numberVerts <= iVar20) {
      ribbon->endIndex = 0;
    }
    if (iVar11 == -1) {
      return;
    }
    if ((((ribbon->instance->flags & 0x800U) == 0) && ((ribbon->instance->flags2 & 0x4000000U) == 0)
        ) && (iVar11 < iVar20 + -1)) {
      iVar19 = iVar11 << 3;
      do {
        iVar8 = iVar11 - iVar1;
        if (iVar8 < 0) {
          iVar8 = iVar8 + ribbon->numberVerts;
        }
        puVar2 = (undefined4 *)((int)&ribbon->vertexPool->vx + iVar19);
        uVar14 = *(undefined4 *)(ribbon->vertexPool + iVar8);
        uVar16 = *(undefined4 *)&ribbon->vertexPool[iVar8].vz;
        iVar18 = 0;
        uVar15 = *(undefined4 *)(ribbon->vertexPool + iVar8 + 1);
        uVar17 = *(undefined4 *)&(ribbon->vertexPool + iVar8)[1].vz;
        iVar8 = (int)&ribbon->vertexPool->vx + iVar19;
        local_50 = *puVar2;
        local_4c = puVar2[1];
        local_38 = *(undefined4 *)(iVar8 + 8);
        local_34 = *(undefined4 *)(iVar8 + 0xc);
        do {
          fxPrim1 = FX_GetPrim(fxTracker);
          if (fxPrim1 != (_FX_PRIM *)0x0) {
            (fxPrim1->position).x = *(short *)((int)&ribbon->vertexPool->vx + iVar19);
            (fxPrim1->position).y = *(short *)((int)&ribbon->vertexPool->vy + iVar19);
            (fxPrim1->position).z = *(short *)((int)&ribbon->vertexPool->vz + iVar19);
            *(undefined4 *)&fxPrim1->v0 = local_50;
            (fxPrim1->v0).z = (short)local_4c;
            local_44 = (short)uVar16;
            *(undefined4 *)&fxPrim1->v1 = uVar14;
            (fxPrim1->v1).z = local_44;
            local_3c = (short)uVar17;
            *(undefined4 *)&fxPrim1->v3 = uVar15;
            (fxPrim1->v3).z = local_3c;
            *(undefined4 *)&fxPrim1->v2 = local_38;
            (fxPrim1->v2).z = (short)local_34;
            fxPrim1->fadeValue[0] = ribbon->startFadeValue;
            fxPrim1->fadeValue[1] = ribbon->startFadeValue;
            fxPrim1->fadeValue[2] = ribbon->startFadeValue + ribbon->fadeStep;
            fxPrim1->fadeValue[3] = ribbon->startFadeValue + ribbon->fadeStep;
            sVar6 = ribbon->fadeStep;
            fxPrim1->flags = fxPrim1->flags & 0xfffffffeU | 0x90008;
            fxPrim1->fadeStep = sVar6;
            fxPrim1->color = ribbon->startColor;
            fxPrim1->startColor = ribbon->startColor;
            lVar3 = ribbon->endColor;
            fxPrim1->colorFadeValue = 0;
            fxPrim1->endColor = lVar3;
            fxPrim1->colorFadeStep = ribbon->colorStepValue;
            if (ribbon->type == '\x02') {
              pcVar4 = FX_ConstrictProcess;
            }
            else {
              pcVar4 = FX_RibbonProcess;
            }
            *(code **)&fxPrim1->process = pcVar4;
            fxPrim1->timeToLive = (int)ribbon->faceLifeTime;
            LIST_InsertFunc(&fxTracker->usedPrimList,(NodeType *)fxPrim1);
            fxPrim2 = FX_GetPrim(fxTracker);
            if (fxPrim2 != (_FX_PRIM *)0x0) {
              p_Var5 = fxPrim1;
              p_Var9 = fxPrim2;
              do {
                pNVar12 = (p_Var5->node).next;
                pTVar13 = p_Var5->texture;
                lVar3 = p_Var5->flags;
                (p_Var9->node).prev = (p_Var5->node).prev;
                (p_Var9->node).next = pNVar12;
                p_Var9->texture = pTVar13;
                p_Var9->flags = lVar3;
                p_Var5 = (_FX_PRIM *)&p_Var5->timeToLive;
                p_Var9 = (_FX_PRIM *)&p_Var9->timeToLive;
              } while (p_Var5 != (_FX_PRIM *)&(fxPrim1->ani).curFrame);
              (p_Var9->node).prev = (p_Var5->node).prev;
              FX_SubDividePrim(fxPrim1,fxPrim2);
              sVar6 = 0x1000;
              if (ribbon->type == '\x02') {
                sVar6 = 0x800;
                fxPrim2->work0 = 0;
                fxPrim1->work0 = 0;
                fxPrim2->work1 = 0;
                fxPrim1->work1 = 0;
                fxPrim1->work2 = 1;
                fxPrim2->work2 = 0;
              }
              fxPrim1->fadeValue[0] = sVar6;
              fxPrim1->fadeValue[1] = sVar6;
              fxPrim2->fadeValue[2] = sVar6;
              fxPrim2->fadeValue[3] = sVar6;
              LIST_InsertFunc(&fxTracker->usedPrimList,(NodeType *)fxPrim2);
            }
          }
          iVar18 = iVar18 + 0x1000;
          local_50 = uVar14;
          local_4c = uVar16;
          local_38 = uVar15;
          local_34 = uVar17;
        } while (iVar18 < 0x1000);
        iVar11 = iVar11 + 1;
        iVar19 = iVar19 + 8;
      } while (iVar11 < iVar20 + -1);
    }
  }
  sVar6 = ribbon->lifeTime;
  if ((0 < ribbon->lifeTime) && (ribbon->lifeTime = sVar6 + -1, sVar6 == 1)) {
    FX_DeleteGeneralEffect((_FXGeneralEffect *)ribbon);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StandardFXPrimProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$a3*/)
 // line 3914, offset 0x800486f4
	/* begin block 1 */
		// Start line: 3915
		// Start offset: 0x800486F4
		// Variables:
	// 		long flags; // $a2

		/* begin block 1.1 */
			// Start line: 3930
			// Start offset: 0x80048740
			// Variables:
		// 		long start; // stack offset -16
		// 		long end; // stack offset -12
		/* end block 1.1 */
		// End offset: 0x80048824
		// End Line: 3945

		/* begin block 1.2 */
			// Start line: 3949
			// Start offset: 0x80048830
			// Variables:
		// 		int current_scale; // $v1
		/* end block 1.2 */
		// End offset: 0x80048860
		// End Line: 3959

		/* begin block 1.3 */
			// Start line: 3964
			// Start offset: 0x80048868
			// Variables:
		// 		struct MATRIX *swTransform; // $v1
		/* end block 1.3 */
		// End offset: 0x80048868
		// End Line: 3965

		/* begin block 1.4 */
			// Start line: 4134
			// Start offset: 0x800489F4
			// Variables:
		// 		struct _Rotation rot; // stack offset -24
		/* end block 1.4 */
		// End offset: 0x80048A54
		// End Line: 4142
	/* end block 1 */
	// End offset: 0x80048A54
	// End Line: 4151

	/* begin block 2 */
		// Start line: 9604
	/* end block 2 */
	// End Line: 9605

/* File: C:\kain2\game\FX.C */

void FX_StandardFXPrimProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  char cVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  _FX_MATRIX *p_Var7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  
  iVar6 = fxPrim->timeToLive;
  if (0 < iVar6) {
    fxPrim->timeToLive = iVar6 + -1;
    iVar6 = fxPrim->timeToLive;
  }
  if (iVar6 == 0) {
LAB_80048848:
    FX_Die(fxPrim,fxTracker);
  }
  else {
    uVar10 = fxPrim->flags;
    if ((uVar10 & 0x40000) != 0) {
      uVar8 = fxPrim->startColor;
      uVar9 = fxPrim->endColor;
      sVar5 = fxPrim->fadeValue[0] + fxPrim->fadeStep;
      fxPrim->fadeValue[0] = sVar5;
      if (0x1000 < sVar5) {
        fxPrim->fadeValue[0] = 0x1000;
      }
      setCopReg(2,0x4000,0x1000 - (int)fxPrim->fadeValue[0]);
      setCopReg(2,0x4800,uVar8 & 0xff);
      setCopReg(2,0x5000,uVar8 >> 8 & 0xff);
      setCopReg(2,0x5800,uVar8 >> 0x10 & 0xff);
      copFunction(2,0x198003d);
      setCopReg(2,0x4000,(uint)(ushort)fxPrim->fadeValue[0]);
      setCopReg(2,0x4800,uVar9 & 0xff);
      setCopReg(2,0x5000,uVar9 >> 8 & 0xff);
      setCopReg(2,0x5800,uVar9 >> 0x10 & 0xff);
      copFunction(2,0x1a8003e);
      uVar11 = getCopReg(2,0x4800);
      uVar12 = getCopReg(2,0x5000);
      uVar13 = getCopReg(2,0x5800);
      *(char *)&fxPrim->color = (char)uVar11;
      *(undefined *)((int)&fxPrim->color + 1) = (char)uVar12;
      *(undefined *)((int)&fxPrim->color + 2) = (char)uVar13;
      if ((uVar10 & 1) != 0) {
        fxPrim->color = fxPrim->color & 0x3ffffffU | 0x2c000000;
      }
    }
    if ((uVar10 & 0x2000) != 0) {
      iVar6 = (int)(fxPrim->v0).y - (int)fxPrim->work3;
      if (iVar6 < 1) goto LAB_80048848;
      (fxPrim->v0).y = (short)iVar6;
    }
    if ((uVar10 & 0x20) == 0) {
      if ((uVar10 & 2) == 0) {
        sVar5 = *(short *)((int)&fxPrim->duo + 8);
        sVar3 = *(short *)((int)&fxPrim->duo + 10);
        *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + *(short *)((int)&fxPrim->duo + 6);
        *(short *)((int)&fxPrim->duo + 2) = *(short *)((int)&fxPrim->duo + 2) + sVar5;
        *(short *)((int)&fxPrim->duo + 4) = *(short *)((int)&fxPrim->duo + 4) + sVar3;
        if ((uVar10 & 0x1000000) == 0) {
          sVar5 = *(short *)((int)&fxPrim->duo + 2);
          sVar3 = *(short *)((int)&fxPrim->duo + 4);
          (fxPrim->position).x = (fxPrim->position).x + *(short *)&fxPrim->duo;
          (fxPrim->position).y = (fxPrim->position).y + sVar5;
          (fxPrim->position).z = (fxPrim->position).z + sVar3;
        }
        else {
          sVar5 = *(short *)&fxPrim->duo;
          (fxPrim->v0).x = (fxPrim->v0).x + sVar5;
          sVar3 = (fxPrim->v0).y;
          sVar4 = *(short *)((int)&fxPrim->duo + 2);
          (fxPrim->v1).x = (fxPrim->v1).x + sVar5;
          (fxPrim->v0).y = sVar3 + sVar4;
          sVar5 = (fxPrim->v0).z;
          sVar3 = *(short *)((int)&fxPrim->duo + 4);
          (fxPrim->v1).y = (fxPrim->v1).y + sVar4;
          (fxPrim->v0).z = sVar5 + sVar3;
          (fxPrim->v1).z = (fxPrim->v1).z + sVar3;
        }
        if (((uVar10 & 0x100) != 0) && ((fxPrim->position).z <= fxPrim->work0)) {
          uVar8 = fxPrim->flags;
          (fxPrim->position).z = fxPrim->work0;
          fxPrim->flags = uVar8 | 2;
        }
      }
    }
    else {
      iVar6 = *(int *)(*(int *)&fxPrim->duo + 0x40) + *(int *)((int)&fxPrim->duo + 4) * 0x20;
      (fxPrim->position).x = *(short *)(iVar6 + 0x14);
      (fxPrim->position).y = *(short *)(iVar6 + 0x18);
      (fxPrim->position).z = *(short *)(iVar6 + 0x1c);
    }
    if (((((uVar10 & 0x8000000) == 0) && (p_Var7 = fxPrim->matrix, p_Var7 != (_FX_MATRIX *)0x0)) &&
        ((p_Var7->flags & 2U) == 0)) && (p_Var7->flags = p_Var7->flags | 2, (uVar10 & 0x80) != 0)) {
      cVar1 = *(char *)&fxPrim->work3;
      cVar2 = *(char *)((int)&fxPrim->work3 + 1);
      RotMatrixX((int)*(char *)((int)&fxPrim->work2 + 1) << 2,&fxPrim->matrix->lwTransform);
      RotMatrixY((int)(short)((int)cVar1 << 2),&fxPrim->matrix->lwTransform);
      RotMatrixZ((int)(short)((int)cVar2 << 2),&fxPrim->matrix->lwTransform);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_AttachedParticlePrimProcess(struct _FX_PRIM *fxPrim /*$a2*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 4153, offset 0x80048a64
	/* begin block 1 */
		// Start line: 4154
		// Start offset: 0x80048A64
		// Variables:
	// 		struct MATRIX *swTransform; // $a3
	// 		struct MATRIX *swTransformOld; // $t0
	// 		struct _Instance *instance; // $v1
	/* end block 1 */
	// End offset: 0x80048AE0
	// End Line: 4168

	/* begin block 2 */
		// Start line: 10102
	/* end block 2 */
	// End Line: 10103

/* File: C:\kain2\game\FX.C */

void FX_AttachedParticlePrimProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = (int)fxPrim->work0 * 0x20;
  iVar3 = *(int *)(fxPrim->matrix[1].lwTransform.m + 4);
  iVar2 = *(int *)(fxPrim->matrix[1].lwTransform.m + 6);
  iVar4 = iVar3 + iVar1;
  iVar1 = iVar2 + iVar1;
  if ((iVar3 != 0) && (iVar2 != 0)) {
    (fxPrim->position).x =
         (fxPrim->position).x + (*(short *)(iVar4 + 0x14) - *(short *)(iVar1 + 0x14));
    (fxPrim->position).y =
         (fxPrim->position).y + (*(short *)(iVar4 + 0x18) - *(short *)(iVar1 + 0x18));
    (fxPrim->position).z =
         (fxPrim->position).z + (*(short *)(iVar4 + 0x1c) - *(short *)(iVar1 + 0x1c));
  }
  FX_StandardFXPrimProcess(fxPrim,fxTracker);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_FlamePrimProcess(struct _FX_PRIM *fxPrim /*$a3*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 4171, offset 0x80048af8
	/* begin block 1 */
		// Start line: 4172
		// Start offset: 0x80048AF8
		// Variables:
	// 		struct MATRIX *swTransform; // $a0
	// 		struct MATRIX *swTransformOld; // $a2
	// 		struct _Instance *instance; // $v0
	// 		struct _SVector movement; // stack offset -16
	// 		int total; // $a0
	/* end block 1 */
	// End offset: 0x80048CBC
	// End Line: 4205

	/* begin block 2 */
		// Start line: 10141
	/* end block 2 */
	// End Line: 10142

/* File: C:\kain2\game\FX.C */

void FX_FlamePrimProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  short sVar6;
  short sVar7;
  
  iVar5 = *(int *)(fxPrim->matrix[1].lwTransform.m + 4);
  if ((iVar5 != 0) && (iVar3 = *(int *)(fxPrim->matrix[1].lwTransform.m + 6), iVar3 != 0)) {
    iVar2 = (int)fxPrim->work0 * 0x20;
    iVar5 = iVar5 + iVar2;
    iVar3 = iVar3 + iVar2;
    iVar2 = (*(int *)(iVar5 + 0x14) - *(int *)(iVar3 + 0x14)) * 0x6e;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 0x7f;
    }
    sVar6 = (short)(iVar2 >> 7);
    iVar2 = (*(int *)(iVar5 + 0x18) - *(int *)(iVar3 + 0x18)) * 0x6e;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 0x7f;
    }
    sVar7 = (short)(iVar2 >> 7);
    iVar5 = (*(int *)(iVar5 + 0x1c) - *(int *)(iVar3 + 0x1c)) * 0x6e;
    if (iVar5 < 0) {
      iVar5 = iVar5 + 0x7f;
    }
    sVar4 = (short)(iVar5 >> 7);
    iVar5 = (int)sVar6;
    if (iVar5 < 0) {
      iVar5 = -iVar5;
    }
    iVar3 = (int)sVar7;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    iVar2 = (int)sVar4;
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    iVar2 = iVar5 + iVar3 + iVar2;
    if (iVar2 != 0) {
      (fxPrim->position).x = (fxPrim->position).x + sVar6;
      (fxPrim->position).y = (fxPrim->position).y + sVar7;
      (fxPrim->position).z = (fxPrim->position).z + sVar4;
    }
    if (iVar2 < 0x29) {
      *(undefined2 *)((int)&fxPrim->duo + 10) = 1;
    }
    else {
      uVar1 = (fxPrim->v0).y;
      *(undefined2 *)((int)&fxPrim->duo + 10) = 0;
      iVar5 = (uint)uVar1 - (iVar2 * 3) / 2;
      (fxPrim->v0).y = (short)iVar5;
      if (iVar5 * 0x10000 < 0) {
        (fxPrim->v0).y = 0;
      }
    }
    FX_StandardFXPrimProcess(fxPrim,fxTracker);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DFacadeParticleSetup(struct _FX_PRIM *fxPrim /*$t1*/, struct SVECTOR *center /*$a1*/, short halveWidth /*$a2*/, short halveHeight /*$a3*/, long color /*stack 16*/, struct SVECTOR *vel /*stack 20*/, struct SVECTOR *accl /*stack 24*/, struct _FXTracker *fxTracker /*stack 28*/, int timeToLive /*stack 32*/)
 // line 4217, offset 0x80048ccc
	/* begin block 1 */
		// Start line: 4218
		// Start offset: 0x80048CCC

		/* begin block 1.1 */
			// Start line: 4218
			// Start offset: 0x80048CCC
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _Position *_v0; // $v0
		/* end block 1.1 */
		// End offset: 0x80048CCC
		// End Line: 4218
	/* end block 1 */
	// End offset: 0x80048DAC
	// End Line: 4259

	/* begin block 2 */
		// Start line: 10234
	/* end block 2 */
	// End Line: 10235

/* File: C:\kain2\game\FX.C */

void FX_DFacadeParticleSetup
               (_FX_PRIM *fxPrim,undefined center,short halveWidth,short halveHeight,long color,
               undefined1 vel,undefined1 accl,_FXTracker *fxTracker,int timeToLive)

{
  short sVar1;
  short sVar2;
  undefined3 in_register_00000015;
  short *psVar3;
  
  psVar3 = (short *)CONCAT31(in_register_00000015,center);
  sVar1 = psVar3[1];
  sVar2 = psVar3[2];
  (fxPrim->position).x = *psVar3;
  (fxPrim->position).y = sVar1;
  (fxPrim->position).z = sVar2;
  (fxPrim->v0).x = halveWidth;
  (fxPrim->v0).y = 0x1000;
  (fxPrim->v0).z = halveHeight;
  fxPrim->color = color & 0x3ffffffU | 0x20000000;
  *(code **)&fxPrim->process = FX_StandardFXPrimProcess;
  fxPrim->flags = fxPrim->flags | 8;
  if (_vel == (undefined2 *)0x0) {
    *(undefined2 *)&fxPrim->duo = 0;
    *(undefined2 *)((int)&fxPrim->duo + 2) = 0;
    *(undefined2 *)((int)&fxPrim->duo + 4) = 0;
  }
  else {
    *(undefined2 *)&fxPrim->duo = *_vel;
    *(undefined2 *)((int)&fxPrim->duo + 2) = _vel[1];
    *(undefined2 *)((int)&fxPrim->duo + 4) = _vel[2];
  }
  if (_accl == (undefined2 *)0x0) {
    *(undefined2 *)((int)&fxPrim->duo + 6) = 0;
    *(undefined2 *)((int)&fxPrim->duo + 8) = 0;
    *(undefined2 *)((int)&fxPrim->duo + 10) = 0;
  }
  else {
    *(undefined2 *)((int)&fxPrim->duo + 6) = *_accl;
    *(undefined2 *)((int)&fxPrim->duo + 8) = _accl[1];
    *(undefined2 *)((int)&fxPrim->duo + 10) = _accl[2];
  }
  fxPrim->timeToLive = (int)(short)timeToLive;
  return;
}



// decompiled code
// original method signature: 
// struct _FX_PRIM * /*$ra*/ FX_Dot(struct _SVector *location /*$s4*/, struct _SVector *vel /*$s6*/, struct _SVector *accel /*$s7*/, int scale_speed /*$fp*/, long color /*stack 16*/, long size /*stack 20*/, int lifetime /*stack 24*/, int texture_num /*stack 28*/)
 // line 4263, offset 0x80048dbc
	/* begin block 1 */
		// Start line: 4264
		// Start offset: 0x80048DBC
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	/* end block 1 */
	// End offset: 0x80048EF4
	// End Line: 4294

	/* begin block 2 */
		// Start line: 10373
	/* end block 2 */
	// End Line: 10374

/* File: C:\kain2\game\FX.C */

_FX_PRIM *
FX_Dot(_SVector *location,_SVector *vel,_SVector *accel,int scale_speed,long color,long size,
      int lifetime,int texture_num)

{
  _FX_PRIM *fxPrim;
  uint uVar1;
  
  fxPrim = FX_GetPrim(gFXT);
  if (fxPrim != (_FX_PRIM *)0x0) {
    if (texture_num < 0) {
      FX_DFacadeParticleSetup
                (fxPrim,(char)location,(short)size,(short)size,color,(char)vel,(char)accel,gFXT,
                 (int)(short)lifetime);
      if (color != 0) {
        fxPrim->flags = fxPrim->flags | 0xc0000;
      }
      fxPrim->startColor = color;
      fxPrim->endColor = 0;
      fxPrim->fadeValue[3] = 0;
      fxPrim->fadeValue[2] = 0;
      fxPrim->fadeValue[1] = 0;
      fxPrim->fadeValue[0] = 0;
      fxPrim->fadeStep = (short)(0x1000 / lifetime);
    }
    else {
      FX_MakeParticleTexFX
                (fxPrim,location,(Object *)0x0,0,texture_num,vel,accel,color,size,lifetime);
    }
    if (scale_speed != 0) {
      uVar1 = fxPrim->flags;
      (fxPrim->v0).y = 0x1000;
      fxPrim->work3 = (short)scale_speed;
      fxPrim->flags = uVar1 | 0x2000;
    }
    FX_Sprite_Insert(&gFXT->usedPrimListSprite,fxPrim);
  }
  return fxPrim;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Blood(struct _SVector *location /*$s4*/, struct _SVector *input_vel /*$s1*/, struct _SVector *accel /*$s5*/, int amount /*$a3*/, long color /*stack 16*/, long size /*stack 20*/)
 // line 4297, offset 0x80048f28
	/* begin block 1 */
		// Start line: 4298
		// Start offset: 0x80048F28
		// Variables:
	// 		int i; // $s0

		/* begin block 1.1 */
			// Start line: 4303
			// Start offset: 0x80048F64
			// Variables:
		// 		struct _SVector vel; // stack offset -40
		/* end block 1.1 */
		// End offset: 0x80048FF0
		// End Line: 4307
	/* end block 1 */
	// End offset: 0x8004903C
	// End Line: 4310

	/* begin block 2 */
		// Start line: 10447
	/* end block 2 */
	// End Line: 10448

/* File: C:\kain2\game\FX.C */

void FX_Blood(_SVector *location,_SVector *input_vel,_SVector *accel,int amount,long color,long size
             )

{
  int iVar1;
  int iVar2;
  _SVector local_28;
  
  if (amount != 0) {
    do {
      iVar1 = rand();
      iVar2 = input_vel->x * amount;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 0x7f;
      }
      local_28.x = (short)(iVar2 >> 7) + ((ushort)iVar1 & 7) + -4;
      iVar1 = rand();
      iVar2 = input_vel->y * amount;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 0x7f;
      }
      local_28.y = (short)(iVar2 >> 7) + ((ushort)iVar1 & 7) + -4;
      iVar1 = rand();
      iVar2 = input_vel->z * amount;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 0x7f;
      }
      local_28.z = (short)(iVar2 >> 7) + ((ushort)iVar1 & 7) + -4;
      FX_Dot(location,&local_28,accel,0,color,size,0x10,-1);
      amount = amount + -1;
    } while (amount != 0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Blood2(struct _SVector *location /*$a0*/, struct _SVector *input_vel /*$a1*/, struct _SVector *accel /*$a2*/, int amount /*$a3*/, long color /*stack 16*/, long dummyCrapShouldRemove /*stack 20*/)
 // line 4312, offset 0x80049060
	/* begin block 1 */
		// Start line: 10484
	/* end block 1 */
	// End Line: 10485

/* File: C:\kain2\game\FX.C */

void FX_Blood2(_SVector *location,_SVector *input_vel,_SVector *accel,int amount,long color,
              long dummyCrapShouldRemove)

{
  FX_Blood(location,input_vel,accel,amount,color,4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Blood_Impale(struct _Instance *locinst /*$a0*/, short locseg /*$a1*/, struct _Instance *instance /*$a2*/, short segment /*$a3*/)
 // line 4344, offset 0x8004908c
	/* begin block 1 */
		// Start line: 4345
		// Start offset: 0x8004908C
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct SVECTOR location; // stack offset -48
	// 		struct SVECTOR accel; // stack offset -40
	// 		struct SVECTOR vel; // stack offset -32
	// 		struct SVECTOR input_vel; // stack offset -24
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x800492A8
	// End Line: 4385

	/* begin block 2 */
		// Start line: 8680
	/* end block 2 */
	// End Line: 8681

/* File: C:\kain2\game\FX.C */

void FX_Blood_Impale(_Instance *locinst,short locseg,_Instance *instance,short segment)

{
  _FXTracker *p_Var1;
  _FX_PRIM *fxPrim;
  uint uVar2;
  int iVar3;
  
  iVar3 = 1;
  do {
    fxPrim = FX_GetPrim(gFXT);
    if (fxPrim != (_FX_PRIM *)0x0) {
      rand();
      rand();
      rand();
      FX_DFacadeParticleSetup(fxPrim,0xd0,8,8,(long)&DAT_001800a0,0xe0,0xd8,gFXT,0x16);
      p_Var1 = gFXT;
      fxPrim->fadeStep = 0xba;
      uVar2 = fxPrim->flags;
      fxPrim->startColor = 0x1800a0;
      fxPrim->endColor = 0;
      fxPrim->fadeValue[3] = 0;
      fxPrim->fadeValue[2] = 0;
      fxPrim->fadeValue[1] = 0;
      fxPrim->fadeValue[0] = 0;
      fxPrim->flags = uVar2 | 0xc0000;
      FX_Sprite_Insert(&p_Var1->usedPrimListSprite,fxPrim);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x40);
  return;
}



// decompiled code
// original method signature: 
// struct _FXParticle * /*$ra*/ FX_BloodCone(struct _Instance *instance /*$a0*/, short startSegment /*$a1*/, long time /*$s1*/)
 // line 4391, offset 0x800492c0
	/* begin block 1 */
		// Start line: 4392
		// Start offset: 0x800492C0
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	/* end block 1 */
	// End offset: 0x80049344
	// End Line: 4414

	/* begin block 2 */
		// Start line: 10668
	/* end block 2 */
	// End Line: 10669

/* File: C:\kain2\game\FX.C */

_FXParticle * FX_BloodCone(_Instance *instance,short startSegment,long time)

{
  _FXParticle *ptr;
  
  ptr = FX_GetParticle(instance,startSegment);
  if (ptr != (_FXParticle *)0x0) {
    ptr->size = 7;
    ptr->birthRadius = 0x14;
    (ptr->direction).x = 0x100;
    (ptr->direction).y = 0x100;
    (ptr->direction).z = 0x100;
    (ptr->acceleration).z = -2;
    ptr->numberBirthParticles = '\n';
    (ptr->acceleration).x = 0;
    (ptr->acceleration).y = 0;
    ptr->startColor = 0x1800a0;
    ptr->endColor = 0;
    ptr->lifeTime = (short)time;
    ptr->primLifeTime = 10;
    FX_InsertGeneralEffect(ptr);
  }
  return ptr;
}



// decompiled code
// original method signature: 
// struct _FXParticle * /*$ra*/ FX_GetTorchParticle(struct _Instance *instance /*$s1*/, short startSegment /*$a1*/, int tex /*$s2*/, int birthRadius /*$s3*/, int num /*stack 16*/)
 // line 4419, offset 0x8004935c
	/* begin block 1 */
		// Start line: 4420
		// Start offset: 0x8004935C
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	/* end block 1 */
	// End offset: 0x80049420
	// End Line: 4444

	/* begin block 2 */
		// Start line: 10747
	/* end block 2 */
	// End Line: 10748

/* File: C:\kain2\game\FX.C */

_FXParticle *
FX_GetTorchParticle(_Instance *instance,short startSegment,int tex,int birthRadius,int num)

{
  ushort uVar1;
  _FXParticle *ptr;
  TextureMT3 *pTVar2;
  
  ptr = FX_GetParticle(instance,startSegment);
  if (ptr != (_FXParticle *)0x0) {
    ptr->type = '\x01';
    *(code **)&ptr->fxprim_process = FX_FlamePrimProcess;
    pTVar2 = FX_GetTextureObject(instance->object,1,tex);
    ptr->startColor = 0x20040f0;
    uVar1 = ptr->flag_bits;
    ptr->texture = pTVar2;
    ptr->primLifeTime = 0x10;
    (ptr->acceleration).z = 1;
    ptr->lifeTime = -1;
    ptr->startFadeValue = 5;
    ptr->fadeStep = 5;
    ptr->size = 0x30;
    ptr->endColor = 0;
    ptr->scaleSpeed = 100;
    ptr->birthRadius = (short)birthRadius;
    ptr->numberBirthParticles = (char)num;
    ptr->flag_bits = uVar1 | 1;
    FX_InsertGeneralEffect(ptr);
  }
  return ptr;
}



// decompiled code
// original method signature: 
// struct _FXParticle * /*$ra*/ FX_TorchFlame(struct _Instance *instance /*$s2*/, short startSegment /*$a1*/)
 // line 4447, offset 0x80049440
	/* begin block 1 */
		// Start line: 4448
		// Start offset: 0x80049440
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	/* end block 1 */
	// End offset: 0x80049548
	// End Line: 4490

	/* begin block 2 */
		// Start line: 10826
	/* end block 2 */
	// End Line: 10827

/* File: C:\kain2\game\FX.C */

_FXParticle * FX_TorchFlame(_Instance *instance,short startSegment)

{
  ushort uVar1;
  _FXParticle *ptr;
  
  ptr = FX_GetTorchParticle(instance,startSegment,0,0x10,-5);
  if (ptr != (_FXParticle *)0x0) {
    (ptr->direction).x = 0x30;
    (ptr->direction).y = 0x20;
    (ptr->direction).z = 0x38;
  }
  ptr = FX_GetTorchParticle(instance,startSegment,1,8,-1);
  if (ptr != (_FXParticle *)0x0) {
    (ptr->direction).x = 0x18;
    (ptr->direction).y = 0x10;
    (ptr->direction).z = 0x10;
  }
  ptr = FX_GetParticle(instance,startSegment);
  if (ptr != (_FXParticle *)0x0) {
    ptr->size = 5;
    ptr->birthRadius = 0x14;
    (ptr->direction).x = 0x80;
    (ptr->direction).y = 0x80;
    (ptr->direction).z = 0x80;
    ptr->startColor = 0x93e4;
    uVar1 = ptr->flag_bits;
    (ptr->acceleration).z = 1;
    ptr->numberBirthParticles = '\x01';
    (ptr->acceleration).x = 0;
    (ptr->acceleration).y = 0;
    ptr->endColor = 0;
    ptr->lifeTime = -1;
    ptr->primLifeTime = 0xf;
    ptr->flag_bits = uVar1 | 1;
    FX_InsertGeneralEffect(ptr);
  }
  return ptr;
}



// decompiled code
// original method signature: 
// int /*$ra*/ FX_GetMorphFadeVal()
 // line 4493, offset 0x80049568
	/* begin block 1 */
		// Start line: 4495
		// Start offset: 0x80049568
		// Variables:
	// 		int fade; // $a0
	/* end block 1 */
	// End offset: 0x800495A0
	// End Line: 4498

	/* begin block 2 */
		// Start line: 10939
	/* end block 2 */
	// End Line: 10940

	/* begin block 3 */
		// Start line: 10940
	/* end block 3 */
	// End Line: 10941

/* File: C:\kain2\game\FX.C */

int FX_GetMorphFadeVal(void)

{
  int iVar1;
  
  iVar1 = ((int)DAT_800d20d4 << 0xc) / 1000;
  if (DAT_800d20d6 == 1) {
    iVar1 = 0x1000 - iVar1;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ConvertCamPersToWorld(struct SVECTOR *campos /*$s0*/, struct SVECTOR *worldpos /*$s1*/)
 // line 4517, offset 0x800495a8
	/* begin block 1 */
		// Start line: 10987
	/* end block 1 */
	// End Line: 10988

/* File: C:\kain2\game\FX.C */

void FX_ConvertCamPersToWorld(undefined campos,undefined worldpos)

{
  undefined4 in_zero;
  undefined4 in_at;
  int iVar1;
  undefined3 in_register_00000011;
  undefined4 *puVar2;
  undefined3 in_register_00000015;
  undefined2 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  puVar3 = (undefined2 *)CONCAT31(in_register_00000015,worldpos);
  puVar2 = (undefined4 *)CONCAT31(in_register_00000011,campos);
  SetRotMatrix(DAT_800d1010);
  SetTransMatrix(DAT_800d1010);
  iVar1 = (int)(short)(*(short *)puVar2 + -0x100) * 0x140;
  *(short *)puVar2 = *(short *)puVar2 + -0x100;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0x1ff;
  }
  *(short *)puVar2 = (short)(iVar1 >> 9);
  *(short *)((int)puVar2 + 2) = *(short *)((int)puVar2 + 2) + -0x78;
  *(short *)puVar2 = (short)(((int)*(short *)puVar2 * (int)*(short *)(puVar2 + 1)) / 0x140);
  *(short *)((int)puVar2 + 2) =
       (short)(((int)*(short *)((int)puVar2 + 2) * (int)*(short *)(puVar2 + 1)) / 0x140);
  setCopReg(2,in_zero,*puVar2);
  setCopReg(2,in_at,puVar2[1]);
  copFunction(2,0x480012);
  uVar4 = getCopReg(2,0x4800);
  uVar5 = getCopReg(2,0x5000);
  uVar6 = getCopReg(2,0x5800);
  *puVar3 = (short)uVar4;
  puVar3[1] = (short)uVar5;
  puVar3[2] = (short)uVar6;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_GetRandomScreenPt(struct SVECTOR *point /*$s0*/)
 // line 4537, offset 0x800496c0
	/* begin block 1 */
		// Start line: 11037
	/* end block 1 */
	// End Line: 11038

/* File: C:\kain2\game\FX.C */

void FX_GetRandomScreenPt(undefined point)

{
  int iVar1;
  int iVar2;
  undefined3 in_register_00000011;
  short *psVar3;
  
  psVar3 = (short *)CONCAT31(in_register_00000011,point);
  iVar1 = rand();
  iVar2 = iVar1;
  if (iVar1 < 0) {
    iVar2 = iVar1 + 0x1ff;
  }
  *psVar3 = (short)iVar1 + (short)(iVar2 >> 9) * -0x200;
  iVar2 = rand();
  psVar3[1] = (short)iVar2 + (short)(iVar2 / 0xf0) * -0xf0;
  iVar2 = rand();
  psVar3[2] = ((ushort)iVar2 & 0xfff) + 0x180;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ProcessSnow(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$s1*/)
 // line 4544, offset 0x8004974c
	/* begin block 1 */
		// Start line: 4545
		// Start offset: 0x8004974C

		/* begin block 1.1 */
			// Start line: 4548
			// Start offset: 0x80049770
			// Variables:
		// 		struct SVECTOR position; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x800497A8
		// End Line: 4563
	/* end block 1 */
	// End offset: 0x8004985C
	// End Line: 4577

	/* begin block 2 */
		// Start line: 11051
	/* end block 2 */
	// End Line: 11052

/* File: C:\kain2\game\FX.C */

void FX_ProcessSnow(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  
  if (fxPrim->work0 == 9999) {
    if ((DAT_800d20d6 == 1) || (DAT_800d20d4 != 1000)) goto LAB_800497d0;
    fxPrim->work0 = 0;
    FX_GetRandomScreenPt(0xe8);
    FX_ConvertCamPersToWorld(0xe8,(char)fxPrim + ',');
  }
  if (0 < fxPrim->timeToLive) {
    fxPrim->timeToLive = fxPrim->timeToLive + -1;
  }
  if (fxPrim->timeToLive != 0) {
    uVar2 = rand();
    iVar3 = (int)windx * ((uVar2 & 0x7ff) + 0x800);
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0xfff;
    }
    (fxPrim->position).x = (fxPrim->position).x + (short)(iVar3 >> 0xc);
    uVar2 = rand();
    iVar3 = (int)windy * ((uVar2 & 0x7ff) + 0x800);
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0xfff;
    }
    sVar1 = *(short *)((int)&fxPrim->duo + 4);
    (fxPrim->position).y = (fxPrim->position).y + (short)(iVar3 >> 0xc);
    (fxPrim->position).z = (fxPrim->position).z + sVar1;
    return;
  }
LAB_800497d0:
  FX_Die(fxPrim,fxTracker);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueSnow(struct _FXTracker *fxTracker /*$s1*/)
 // line 4579, offset 0x80049870
	/* begin block 1 */
		// Start line: 4580
		// Start offset: 0x80049870
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct SVECTOR position; // stack offset -40
	// 		struct SVECTOR vel; // stack offset -32

		/* begin block 1.1 */
			// Start line: 4597
			// Start offset: 0x800498EC
			// Variables:
		// 		struct SVECTOR campos; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x800499B4
		// End Line: 4619
	/* end block 1 */
	// End offset: 0x800499B4
	// End Line: 4621

	/* begin block 2 */
		// Start line: 11123
	/* end block 2 */
	// End Line: 11124

/* File: C:\kain2\game\FX.C */

void FX_ContinueSnow(_FXTracker *fxTracker)

{
  uint uVar1;
  _FX_PRIM *fxPrim;
  
  if (DAT_800d20d4 == 1000) {
    if (DAT_800d20d6 == 1) {
      return;
    }
  }
  else {
    if (DAT_800d20d6 == 0) {
      return;
    }
  }
  uVar1 = rand();
  if (((int)(uVar1 & 0x3ff) <= (int)snow_amount) &&
     (fxPrim = FX_GetPrim(gFXT), fxPrim != (_FX_PRIM *)0x0)) {
    rand();
    rand();
    rand();
    FX_ConvertCamPersToWorld(0xe8,0xd8);
    FX_DFacadeParticleSetup(fxPrim,0xd8,1,1,0xffffff,0xe0,0,fxTracker,0x96);
    *(code **)&fxPrim->process = FX_ProcessSnow;
    fxPrim->work0 = 0;
    fxPrim->flags = fxPrim->flags | 0x800000;
    FX_Sprite_Insert(&fxTracker->usedPrimListSprite,fxPrim);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdateWind(struct _FXTracker *fxTracker /*$a0*/)
 // line 4623, offset 0x800499c8
	/* begin block 1 */
		// Start line: 4624
		// Start offset: 0x800499C8
		// Variables:
	// 		short change; // $s0
	/* end block 1 */
	// End offset: 0x80049B24
	// End Line: 4641

	/* begin block 2 */
		// Start line: 11222
	/* end block 2 */
	// End Line: 11223

/* File: C:\kain2\game\FX.C */

void FX_UpdateWind(_FXTracker *fxTracker)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = rand();
  iVar2 = iVar1;
  if (iVar1 < 0) {
    iVar2 = iVar1 + 3;
  }
  iVar1 = iVar1 + (iVar2 >> 2) * -4;
  uVar3 = rand();
  if ((uVar3 & 1) != 0) {
    iVar1 = -iVar1;
  }
  uVar3 = (uint)(ushort)wind_speed;
  wind_speed = (short)(uVar3 + iVar1);
  if (0x28 < (int)((uVar3 + iVar1) * 0x10000) >> 0x10) {
    wind_speed = 0x28;
  }
  if (wind_speed < 0xf) {
    wind_speed = 0xf;
  }
  iVar1 = rand();
  iVar2 = iVar1;
  if (iVar1 < 0) {
    iVar2 = iVar1 + 7;
  }
  iVar1 = iVar1 + (iVar2 >> 3) * -8;
  uVar3 = rand();
  if ((uVar3 & 1) != 0) {
    iVar1 = -iVar1;
  }
  uVar3 = (uint)(ushort)wind_deg;
  wind_deg = (short)(uVar3 + iVar1);
  if (0x500 < (int)((uVar3 + iVar1) * 0x10000) >> 0x10) {
    wind_deg = 0x500;
  }
  if (wind_deg < 0x300) {
    wind_deg = 0x300;
  }
  iVar1 = rcos((int)wind_deg);
  iVar1 = iVar1 * wind_speed;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xfff;
  }
  windx = (short)(iVar1 >> 0xc);
  iVar1 = rsin((int)wind_deg);
  iVar1 = iVar1 * wind_speed;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xfff;
  }
  windy = (short)(iVar1 >> 0xc);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ProcessRain(struct _FX_PRIM *fxPrim /*$a2*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 4648, offset 0x80049b40
	/* begin block 1 */
		// Start line: 11276
	/* end block 1 */
	// End Line: 11277

/* File: C:\kain2\game\FX.C */

void FX_ProcessRain(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  short sVar3;
  
  if (0 < fxPrim->timeToLive) {
    fxPrim->timeToLive = fxPrim->timeToLive + -1;
  }
  sVar3 = (fxPrim->v1).z + *(short *)((int)&fxPrim->duo + 4);
  (fxPrim->v1).z = sVar3;
  if ((fxPrim->work0 < sVar3) && (fxPrim->timeToLive != 0)) {
    sVar3 = *(short *)&fxPrim->duo;
    sVar1 = *(short *)((int)&fxPrim->duo + 2);
    (fxPrim->v0).x = (fxPrim->v0).x + sVar3;
    sVar2 = (fxPrim->v0).y;
    (fxPrim->v1).x = (fxPrim->v1).x + sVar3;
    (fxPrim->v0).y = sVar2 + sVar1;
    sVar3 = (fxPrim->v0).z;
    sVar2 = *(short *)((int)&fxPrim->duo + 4);
    (fxPrim->v1).y = (fxPrim->v1).y + sVar1;
    (fxPrim->v0).z = sVar3 + sVar2;
  }
  else {
    FX_Die(fxPrim,fxTracker);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueRain(struct _FXTracker *fxTracker /*$s6*/)
 // line 4672, offset 0x80049c0c
	/* begin block 1 */
		// Start line: 4673
		// Start offset: 0x80049C0C
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct SVECTOR campos; // stack offset -48
	// 		int n; // $s3
	// 		int rain_pct; // $s5
	// 		long waterZLevel; // $s2

		/* begin block 1.1 */
			// Start line: 4686
			// Start offset: 0x80049C58
			// Variables:
		// 		int fade; // $v1
		/* end block 1.1 */
		// End offset: 0x80049C80
		// End Line: 4688

		/* begin block 1.2 */
			// Start line: 4697
			// Start offset: 0x80049CB0
			// Variables:
		// 		struct _SVector worldpos; // stack offset -40
		// 		int zvel; // $s1
		/* end block 1.2 */
		// End offset: 0x80049E64
		// End Line: 4743
	/* end block 1 */
	// End offset: 0x80049E74
	// End Line: 4745

	/* begin block 2 */
		// Start line: 11332
	/* end block 2 */
	// End Line: 11333

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* File: C:\kain2\game\FX.C */

void FX_ContinueRain(_FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  Level *pLVar6;
  uint uVar7;
  _FX_PRIM *node;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  short local_28;
  short local_26;
  short local_24;
  
  if (_DAT_800d20d4 != &PTR_000103e8) {
    iVar10 = (int)rain_amount;
    if (DAT_800d20d4 != 1000) {
      iVar5 = FX_GetMorphFadeVal();
      iVar5 = iVar10 * (0x1000 - iVar5);
      iVar10 = iVar5 >> 0xc;
      if (iVar5 < 0) {
        iVar10 = iVar5 + 0xfff >> 0xc;
      }
    }
    iVar9 = 0;
    pLVar6 = STREAM_GetLevelWithID(*(long *)(DAT_800d20f8 + 0x38));
    iVar5 = pLVar6->waterZLevel;
    do {
      uVar7 = rand();
      if ((int)(uVar7 & 0x3ff) <= iVar10) {
        rand();
        rand();
        FX_ConvertCamPersToWorld(0xd0,0xd8);
        uVar7 = rand();
        iVar8 = (-0xe - (uVar7 & 3)) * 8;
        if (local_24 + iVar8 < iVar5) {
          FX_GetRandomScreenPt(0xd0);
          FX_ConvertCamPersToWorld(0xd0,0xd8);
          if (local_24 + iVar8 < iVar5) goto LAB_80049e64;
        }
        node = FX_GetPrim(gFXT);
        if (node != (_FX_PRIM *)0x0) {
          (node->v0).x = local_28;
          (node->v0).y = local_26;
          (node->v0).z = local_24;
          uVar7 = rand();
          iVar11 = (int)windx * ((uVar7 & 0x3ff) + 0xc00);
          if (iVar11 < 0) {
            iVar11 = iVar11 + 0xfff;
          }
          *(short *)&node->duo = (short)(iVar11 >> 0xc);
          uVar7 = rand();
          iVar11 = (int)windy * ((uVar7 & 0x3ff) + 0xc00);
          if (iVar11 < 0) {
            iVar11 = iVar11 + 0xfff;
          }
          *(undefined2 *)((int)&node->duo + 2) = (short)(iVar11 >> 0xc);
          node->timeToLive = 0x14;
          node->flags = 0x1090000;
          node->color = 0x52404040;
          sVar1 = (node->v0).x;
          sVar2 = *(short *)&node->duo;
          *(code **)&node->process = FX_ProcessRain;
          sVar3 = (node->v0).y;
          *(short *)((int)&node->duo + 4) = (short)iVar8;
          sVar4 = *(short *)((int)&node->duo + 2);
          node->work0 = (short)iVar5;
          node->endColor = 0;
          (node->v1).x = sVar1 + sVar2;
          sVar1 = (node->v0).z;
          (node->v1).y = sVar3 + sVar4;
          (node->v1).z = sVar1 + (short)iVar8;
          LIST_InsertFunc(&fxTracker->usedPrimList,(NodeType *)node);
        }
      }
LAB_80049e64:
      iVar9 = iVar9 + 1;
    } while (iVar9 < 3);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeSpark(struct _Instance *instance /*$a0*/, struct _Model *model /*$a1*/, int segment /*$a2*/)
 // line 4750, offset 0x80049e9c
	/* begin block 1 */
		// Start line: 4751
		// Start offset: 0x80049E9C
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	// 		struct Object *particle; // $s1
	/* end block 1 */
	// End offset: 0x80049F44
	// End Line: 4780

	/* begin block 2 */
		// Start line: 11613
	/* end block 2 */
	// End Line: 11614

/* File: C:\kain2\game\FX.C */

void FX_MakeSpark(_Instance *instance,_Model *model,int segment)

{
  void *object;
  _FXParticle *ptr;
  TextureMT3 *pTVar1;
  
  object = objectAccess[10].object;
  if ((objectAccess[10].object != (void *)0x0) &&
     (ptr = FX_GetParticle(instance,(short)segment), ptr != (_FXParticle *)0x0)) {
    ptr->size = 0x30;
    ptr->birthRadius = 0x32;
    (ptr->direction).x = 0x80;
    (ptr->direction).y = 0x80;
    (ptr->direction).z = 0xa0;
    (ptr->acceleration).x = 0;
    (ptr->acceleration).y = 0;
    (ptr->acceleration).z = 1;
    pTVar1 = FX_GetTextureObject((Object *)object,0,0);
    ptr->texture = pTVar1;
    ptr->numberBirthParticles = '\x02';
    ptr->lifeTime = 2;
    ptr->startColor = 0x2004960;
    ptr->endColor = 0;
    ptr->primLifeTime = 4;
    FX_InsertGeneralEffect(ptr);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueParticle(struct _FXParticle *currentParticle /*$s2*/, struct _FXTracker *fxTracker /*stack 4*/)
 // line 4782, offset 0x80049f58
	/* begin block 1 */
		// Start line: 4783
		// Start offset: 0x80049F58
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s1
	// 		struct VECTOR movement; // stack offset -64
	// 		int i; // $fp
	// 		int num; // stack offset -44
	// 		struct MATRIX *swTransform; // $s4
	// 		struct MATRIX *swOldTransform; // $a1
	// 		long birthRadius; // $s5
	// 		struct _Instance *instance; // $s6
	// 		int InstanceFade; // $s3
	// 		unsigned long black; // stack offset -48

		/* begin block 1.1 */
			// Start line: 4903
			// Start offset: 0x8004A4D4
			// Variables:
		// 		int tmp_blue; // $v1
		// 		struct CVECTOR *ptr; // $s0

			/* begin block 1.1.1 */
				// Start line: 4910
				// Start offset: 0x8004A4F8
				// Variables:
			// 		int fade; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8004A51C
			// End Line: 4916
		/* end block 1.1 */
		// End offset: 0x8004A51C
		// End Line: 4917
	/* end block 1 */
	// End offset: 0x8004A768
	// End Line: 4982

	/* begin block 2 */
		// Start line: 11709
	/* end block 2 */
	// End Line: 11710

/* File: C:\kain2\game\FX.C */

void FX_ContinueParticle(_FXParticle *currentParticle,_FXTracker *fxTracker)

{
  undefined uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  int p1;
  _FX_PRIM *fxPrim;
  uint uVar9;
  int p1_00;
  long lVar10;
  code *pcVar11;
  MATRIX *pMVar12;
  TextureMT3 *pTVar13;
  MATRIX *pMVar14;
  MATRIX *pMVar15;
  _Instance *instance;
  int p0;
  int iVar16;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_30;
  uint local_2c;
  
  local_30 = 0;
  local_2c = SEXT14(currentParticle->numberBirthParticles);
  if ((int)local_2c < 0) {
    p1 = rand();
    local_2c = (uint)(p1 % -local_2c == 0);
  }
  instance = currentParticle->instance;
  if ((((((instance->flags & 0x800U) == 0) && ((instance->flags2 & 0x4000000U) == 0)) &&
       ((instance->flags & 0x200U) != 0)) &&
      ((pMVar12 = instance->matrix, pMVar12 != (MATRIX *)0x0 &&
       (instance->oldMatrix != (MATRIX *)0x0)))) && (0 < (int)local_2c)) {
    sVar2 = currentParticle->birthRadius;
    p1 = (int)sVar2;
    pMVar14 = instance->oldMatrix + currentParticle->startSegment;
    pMVar15 = pMVar12 + currentParticle->startSegment;
    if (currentParticle->type == '\x01') {
      p1 = p1 * 0x1000;
      if (p1 < 0) {
        p1 = p1 + 0x7f;
      }
      local_40 = p1 >> 7;
      local_3c = local_40;
      local_38 = local_40;
    }
    else {
      if ((byte)(currentParticle->type - 2) < 2) {
        pMVar14 = pMVar12 + currentParticle->endSegment;
      }
      local_40 = ((pMVar14->t[0] - pMVar15->t[0]) + p1) * 0x1000;
      if (local_40 < 0) {
        local_40 = local_40 + 0x7f;
      }
      local_40 = local_40 >> 7;
      local_3c = ((pMVar14->t[1] - pMVar15->t[1]) + p1) * 0x1000;
      if (local_3c < 0) {
        local_3c = local_3c + 0x7f;
      }
      local_3c = local_3c >> 7;
      local_38 = ((pMVar14->t[2] - pMVar15->t[2]) + p1) * 0x1000;
      if (local_38 < 0) {
        local_38 = local_38 + 0x7f;
      }
      local_38 = local_38 >> 7;
    }
    if (instance == DAT_800d20f8) {
      p1 = 0;
    }
    else {
      if (DAT_800d20d4 == 1000) {
        p1 = (int)instance->fadeValue;
      }
      else {
        p1 = INSTANCE_GetFadeValue(instance);
      }
    }
    sVar2 = sVar2 / 2;
    iVar16 = 0;
    if (0 < (int)local_2c) {
      p0 = 0x1000 - p1;
      do {
        fxPrim = FX_GetPrim(gFXT);
        if (fxPrim != (_FX_PRIM *)0x0) {
          uVar9 = rand();
          (fxPrim->position).x =
               ((currentParticle->offset).x + *(short *)pMVar15->t +
               (short)((int)(local_40 * (uVar9 & 0x7f)) >> 0xc)) - sVar2;
          uVar9 = rand();
          (fxPrim->position).y =
               ((currentParticle->offset).y + *(short *)(pMVar15->t + 1) +
               (short)((int)(local_3c * (uVar9 & 0x7f)) >> 0xc)) - sVar2;
          uVar9 = rand();
          (fxPrim->position).z =
               ((currentParticle->offset).z + *(short *)(pMVar15->t + 2) +
               (short)((int)(local_38 * (uVar9 & 0x7f)) >> 0xc)) - sVar2;
          switch(currentParticle->z_undulate) {
          default:
            goto switchD_8004a25c_caseD_0;
          case '\x01':
            p1_00 = rcos(DAT_800d21f8 << 7);
            p1_00 = p1_00 * 0x28;
            if (p1_00 < 0) {
              p1_00 = p1_00 + 0xfff;
            }
            sVar8 = (fxPrim->position).z + 0x14 + (short)(p1_00 >> 0xc);
            break;
          case '\x02':
            p1_00 = rcos(DAT_800d21f8 << 8);
            p1_00 = p1_00 * 0x14;
            if (p1_00 < 0) {
              p1_00 = p1_00 + 0xfff;
            }
            sVar8 = (fxPrim->position).z + 10 + (short)(p1_00 >> 0xc);
            break;
          case '\x03':
            p1_00 = rcos(DAT_800d21f8 << 8);
            p1_00 = p1_00 * 0xf;
            if (p1_00 < 0) {
              p1_00 = p1_00 + 0xfff;
            }
            sVar8 = (fxPrim->position).z + 8 + (short)(p1_00 >> 0xc);
            break;
          case '\x04':
            p1_00 = rcos(DAT_800d21f8 << 8);
            if (p1_00 < 0) {
              p1_00 = p1_00 + 0x1ff;
            }
            sVar8 = (fxPrim->position).z + 4 + (short)(p1_00 >> 9);
          }
          (fxPrim->position).z = sVar8;
switchD_8004a25c_caseD_0:
          if (currentParticle->type == '\x03') {
            sVar8 = (fxPrim->position).y;
            *(short *)&fxPrim->duo =
                 (short)((pMVar15->t[0] - (int)(fxPrim->position).x) /
                        (int)currentParticle->primLifeTime);
            sVar3 = (fxPrim->position).z;
            *(undefined2 *)((int)&fxPrim->duo + 2) =
                 (short)((pMVar15->t[1] - (int)sVar8) / (int)currentParticle->primLifeTime);
            *(undefined2 *)((int)&fxPrim->duo + 4) =
                 (short)((pMVar15->t[2] - (int)sVar3) / (int)currentParticle->primLifeTime);
          }
          else {
            if ((currentParticle->flag_bits & 2) == 0) {
              uVar9 = rand();
              p1_00 = ((uVar9 & 0x1ff) - 0xff) * (int)(currentParticle->direction).x;
              if (p1_00 < 0) {
                p1_00 = p1_00 + 0xfff;
              }
              *(short *)&fxPrim->duo = (short)(p1_00 >> 0xc);
              uVar9 = rand();
              p1_00 = ((uVar9 & 0x1ff) - 0xff) * (int)(currentParticle->direction).y;
              if (p1_00 < 0) {
                p1_00 = p1_00 + 0xfff;
              }
              *(undefined2 *)((int)&fxPrim->duo + 2) = (short)(p1_00 >> 0xc);
              uVar9 = rand();
              p1_00 = ((uVar9 & 0x1ff) - 0xff) * (int)(currentParticle->direction).z;
              if (p1_00 < 0) {
                p1_00 = p1_00 + 0xfff;
              }
              *(undefined2 *)((int)&fxPrim->duo + 4) = (short)(p1_00 >> 0xc);
            }
            else {
              *(short *)&fxPrim->duo = (currentParticle->direction).x;
              *(short *)((int)&fxPrim->duo + 2) = (currentParticle->direction).y;
              *(short *)((int)&fxPrim->duo + 4) = (currentParticle->direction).z;
            }
          }
          *(short *)((int)&fxPrim->duo + 6) = (currentParticle->acceleration).x;
          *(short *)((int)&fxPrim->duo + 8) = (currentParticle->acceleration).y;
          *(short *)((int)&fxPrim->duo + 10) = (currentParticle->acceleration).z;
          sVar8 = currentParticle->size;
          (fxPrim->v0).y = 0x1000;
          (fxPrim->v0).z = sVar8;
          (fxPrim->v0).x = sVar8;
          sVar8 = currentParticle->primLifeTime;
          fxPrim->flags = 0xc0008;
          fxPrim->timeToLive = (int)sVar8;
          fxPrim->startColor = currentParticle->startColor;
          if (((currentParticle->flag_bits & 1) != 0) &&
             ((DAT_800d20d6 == 1 || (DAT_800d20d4 != 1000)))) {
            uVar1 = *(undefined *)((int)&fxPrim->startColor + 2);
            *(undefined *)((int)&fxPrim->startColor + 2) = *(undefined *)&fxPrim->startColor;
            *(undefined *)&fxPrim->startColor = uVar1;
            if (DAT_800d20d4 != 1000) {
              p1_00 = FX_GetMorphFadeVal();
              LoadAverageCol((u_char *)&currentParticle->startColor,(u_char *)&fxPrim->startColor,
                             0x1000 - p1_00,p1_00,(u_char *)&fxPrim->startColor);
            }
          }
          lVar10 = currentParticle->endColor;
          sVar8 = (short)p1;
          fxPrim->fadeValue[3] = sVar8;
          fxPrim->fadeValue[2] = sVar8;
          fxPrim->fadeValue[1] = sVar8;
          fxPrim->fadeValue[0] = sVar8;
          fxPrim->endColor = lVar10;
          if (p1 == 0) {
            fxPrim->fadeStep = (short)(0x1000 / (int)currentParticle->primLifeTime);
          }
          else {
            fxPrim->fadeStep = (short)(p0 / (int)currentParticle->primLifeTime);
            LoadAverageCol((u_char *)&fxPrim->startColor,(u_char *)&local_30,p0,p1,
                           (u_char *)&fxPrim->startColor);
            LoadAverageCol((u_char *)&fxPrim->endColor,(u_char *)&local_30,p0,p1,
                           (u_char *)&fxPrim->endColor);
          }
          if (currentParticle->texture == (TextureMT3 *)0x0) {
            fxPrim->color = fxPrim->startColor & 0x3ffffffU | 0x20000000;
          }
          else {
            fxPrim->flags = fxPrim->flags | 1;
            pTVar13 = currentParticle->texture;
            fxPrim->color = fxPrim->startColor & 0x3ffffffU | 0x2c000000;
            fxPrim->texture = pTVar13;
          }
          if (currentParticle->scaleSpeed != 0) {
            fxPrim->flags = fxPrim->flags | 0x2000;
            (fxPrim->v0).y = currentParticle->startScale;
            fxPrim->work3 = currentParticle->scaleSpeed;
          }
          if (currentParticle->type == '\x01') {
            *(_Instance **)&fxPrim->matrix = instance;
            fxPrim->work0 = (short)currentParticle->startSegment;
            fxPrim->flags = fxPrim->flags | 0x8000000;
          }
          pcVar11 = (code *)currentParticle->fxprim_process;
          if (pcVar11 == (code *)0x0) {
            pcVar11 = FX_StandardFXPrimProcess;
          }
          *(code **)&fxPrim->process = pcVar11;
          if ((code *)currentParticle->fxprim_modify_process != (code *)0x0) {
            (*(code *)currentParticle->fxprim_modify_process)
                      (fxPrim,instance,currentParticle,fxTracker);
          }
          if (currentParticle->type == '\x03') {
            sVar8 = (fxPrim->position).x;
            sVar3 = (fxPrim->position).y;
            sVar4 = (fxPrim->position).z;
            sVar5 = *(short *)&fxPrim->duo;
            fxPrim->flags = 0x1090000;
            sVar6 = *(short *)((int)&fxPrim->duo + 2);
            (fxPrim->v0).x = sVar8;
            sVar7 = *(short *)((int)&fxPrim->duo + 4);
            (fxPrim->v1).x = sVar8 + sVar5;
            (fxPrim->v0).y = sVar3;
            (fxPrim->v0).z = sVar4;
            (fxPrim->v1).y = sVar3 + sVar6;
            (fxPrim->v1).z = sVar4 + sVar7;
            LIST_InsertFunc(&fxTracker->usedPrimList,(NodeType *)fxPrim);
          }
          else {
            FX_Sprite_Insert(&fxTracker->usedPrimListSprite,fxPrim);
          }
        }
        iVar16 = iVar16 + 1;
      } while (iVar16 < (int)local_2c);
    }
  }
  if ((0 < currentParticle->lifeTime) &&
     (p1 = (uint)(ushort)currentParticle->lifeTime - (uint)(ushort)FX_Frames,
     currentParticle->lifeTime = (short)p1, p1 * 0x10000 < 1)) {
    FX_DeleteGeneralEffect((_FXGeneralEffect *)currentParticle);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdraftPrimModify(struct _FX_PRIM *fxPrim /*$s3*/, struct _Instance *instance /*$a1*/, struct _FXParticle *particle /*$s1*/, struct _FXTracker *fxTracker /*$a3*/)
 // line 4984, offset 0x8004a798
	/* begin block 1 */
		// Start line: 4985
		// Start offset: 0x8004A798
		// Variables:
	// 		int deg; // $s2
	/* end block 1 */
	// End offset: 0x8004A8AC
	// End Line: 4991

	/* begin block 2 */
		// Start line: 12288
	/* end block 2 */
	// End Line: 12289

/* File: C:\kain2\game\FX.C */

void FX_UpdraftPrimModify
               (_FX_PRIM *fxPrim,_Instance *instance,_FXParticle *particle,_FXTracker *fxTracker)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar2 = rand();
  iVar3 = rcos(uVar2 & 0xfff);
  uVar4 = rand();
  iVar3 = iVar3 * (particle->direction).x;
  if (iVar3 < 0) {
    iVar3 = iVar3 + 0xfff;
  }
  iVar3 = (int)((iVar3 >> 0xc) * (uVar4 & 0xfff)) / (int)particle->primLifeTime;
  if (iVar3 < 0) {
    iVar3 = iVar3 + 0xfff;
  }
  *(short *)&fxPrim->duo = (short)(iVar3 >> 0xc);
  iVar3 = rsin(uVar2 & 0xfff);
  uVar2 = rand();
  iVar3 = iVar3 * (particle->direction).x;
  if (iVar3 < 0) {
    iVar3 = iVar3 + 0xfff;
  }
  iVar3 = (int)((iVar3 >> 0xc) * (uVar2 & 0xfff)) / (int)particle->primLifeTime;
  uVar1 = (undefined2)(iVar3 >> 0xc);
  if (iVar3 < 0) {
    uVar1 = (undefined2)(iVar3 + 0xfff >> 0xc);
  }
  *(undefined2 *)((int)&fxPrim->duo + 2) = uVar1;
  iVar5 = rand();
  iVar3 = iVar5;
  if (iVar5 < 0) {
    iVar3 = iVar5 + 7;
  }
  *(short *)((int)&fxPrim->duo + 4) =
       (particle->direction).z / particle->primLifeTime + (short)iVar5 + (short)(iVar3 >> 3) * -8;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeParticleTexFX(struct _FX_PRIM *fxPrim /*$s0*/, struct _SVector *position /*$a1*/, struct Object *object /*$s1*/, int modelnum /*$s4*/, int texnum /*stack 16*/, struct _SVector *vel /*stack 20*/, struct _SVector *accl /*stack 24*/, long color /*stack 28*/, int size /*stack 32*/, int life /*stack 36*/)
 // line 4994, offset 0x8004a8dc
	/* begin block 1 */
		// Start line: 12308
	/* end block 1 */
	// End Line: 12309

/* File: C:\kain2\game\FX.C */

void FX_MakeParticleTexFX
               (_FX_PRIM *fxPrim,_SVector *position,Object *object,int modelnum,int texnum,
               _SVector *vel,_SVector *accl,long color,int size,int life)

{
  TextureMT3 *pTVar1;
  uint uVar2;
  
  if (((object != (Object *)0x0) ||
      (object = (Object *)objectAccess[10].object, objectAccess[10].object != (void *)0x0)) &&
     (fxPrim != (_FX_PRIM *)0x0)) {
    FX_DFacadeParticleSetup
              (fxPrim,(char)position,(short)size,(short)size,color,(char)vel,(char)accl,gFXT,
               (int)(short)life);
    pTVar1 = FX_GetTextureObject(object,modelnum,texnum);
    fxPrim->texture = pTVar1;
    uVar2 = fxPrim->flags;
    fxPrim->fadeValue[3] = 0;
    fxPrim->fadeValue[2] = 0;
    fxPrim->fadeValue[1] = 0;
    fxPrim->fadeValue[0] = 0;
    fxPrim->color = color | 0x2e000000;
    fxPrim->startColor = color;
    fxPrim->endColor = 0;
    fxPrim->flags = uVar2 | 0xc0001;
    fxPrim->fadeStep = (short)(0x1000 / life);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeHitFX(struct _SVector *position /*$s1*/)
 // line 5017, offset 0x8004a9e4
	/* begin block 1 */
		// Start line: 5018
		// Start offset: 0x8004A9E4
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	/* end block 1 */
	// End offset: 0x8004AA64
	// End Line: 5029

	/* begin block 2 */
		// Start line: 12374
	/* end block 2 */
	// End Line: 12375

/* File: C:\kain2\game\FX.C */

void FX_MakeHitFX(_SVector *position)

{
  _FX_PRIM *fxPrim;
  
  fxPrim = FX_GetPrim(gFXT);
  if (fxPrim != (_FX_PRIM *)0x0) {
    FX_MakeParticleTexFX
              (fxPrim,position,(Object *)0x0,0,0,(_SVector *)0x0,(_SVector *)0x0,0xffffff,0x60,8);
    FX_Sprite_Insert(&gFXT->usedPrimListSprite,fxPrim);
    fxPrim->flags = fxPrim->flags | 0x8000;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueLightning(struct _FXLightning *zap /*$a0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 5055, offset 0x8004aa78
	/* begin block 1 */
		// Start line: 12453
	/* end block 1 */
	// End Line: 12454

/* File: C:\kain2\game\FX.C */

void FX_ContinueLightning(_FXLightning *zap,_FXTracker *fxTracker)

{
  int iVar1;
  
  zap->deg = zap->deg + zap->deg_inc;
  if ((0 < zap->lifeTime) &&
     (iVar1 = (uint)(ushort)zap->lifeTime - (uint)(ushort)FX_Frames, zap->lifeTime = (short)iVar1,
     iVar1 * 0x10000 < 1)) {
    FX_DeleteGeneralEffect((_FXGeneralEffect *)zap);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeHitFlame(struct _SVector *startpos /*$s3*/, int zpos /*$s5*/, int angle /*$s0*/, int dist /*$s4*/, int size /*stack 16*/)
 // line 5067, offset 0x8004aad8
	/* begin block 1 */
		// Start line: 5068
		// Start offset: 0x8004AAD8
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s2
	// 		struct _SVector position; // stack offset -40
	/* end block 1 */
	// End offset: 0x8004ABF4
	// End Line: 5082

	/* begin block 2 */
		// Start line: 12477
	/* end block 2 */
	// End Line: 12478

/* File: C:\kain2\game\FX.C */

void FX_MakeHitFlame(_SVector *startpos,int zpos,int angle,int dist,int size)

{
  _FX_PRIM *fxPrim;
  int iVar1;
  int iVar2;
  _SVector local_28;
  
  fxPrim = FX_GetPrim(gFXT);
  if (fxPrim != (_FX_PRIM *)0x0) {
    iVar1 = rcos(angle + -0x400);
    iVar2 = rand();
    iVar1 = iVar1 * dist;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0xfff;
    }
    local_28.x = startpos->x + (short)(iVar1 >> 0xc) + ((ushort)iVar2 & 0xf);
    iVar1 = rsin(angle + -0x400);
    iVar2 = rand();
    iVar1 = iVar1 * dist;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0xfff;
    }
    local_28.y = startpos->y + (short)(iVar1 >> 0xc) + ((ushort)iVar2 & 0xf);
    iVar1 = rand();
    local_28.z = startpos->z + (short)zpos + ((ushort)iVar1 & 0xf);
    FX_MakeParticleTexFX
              (fxPrim,&local_28,(Object *)0x0,0,0,(_SVector *)0x0,(_SVector *)0x0,
               (long)&DAT_000093e4,size,2);
    FX_Sprite_Insert(&gFXT->usedPrimListSprite,fxPrim);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SetReaverInstance(struct _Instance *instance /*$a0*/)
 // line 5084, offset 0x8004ac18
	/* begin block 1 */
		// Start line: 12522
	/* end block 1 */
	// End Line: 12523

	/* begin block 2 */
		// Start line: 12523
	/* end block 2 */
	// End Line: 12524

/* File: C:\kain2\game\FX.C */

void FX_SetReaverInstance(_Instance *instance)

{
  FX_reaver_instance = instance;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SoulReaverBlade(struct _Instance *instance /*$a0*/, unsigned long **drawot /*stack 4*/)
 // line 5092, offset 0x8004ac24
	/* begin block 1 */
		// Start line: 5093
		// Start offset: 0x8004AC24
		// Variables:
	// 		struct SVECTOR location; // stack offset -136
	// 		int i; // $s3
	// 		int size; // $s2
	// 		int reaverScale; // $s7
	// 		struct Object *sreaver; // $s2
	// 		struct __ReaverData *data; // $s1
	// 		short deg; // $s4
	// 		long color; // $fp
	// 		struct TextureMT3 *texture; // $v0
	// 		struct MATRIX mat; // stack offset -128
	// 		struct DVECTOR xy_pos; // stack offset -96
	// 		long sizex; // stack offset -48
	// 		long sizey; // $a0
	// 		long otz; // stack offset -44
	// 		struct POLY_FT4 *poly; // $s5
	// 		struct POLY_FT4 poly2; // stack offset -88

		/* begin block 1.1 */
			// Start line: 5150
			// Start offset: 0x8004AD8C
			// Variables:
		// 		int scale1; // $s0
		/* end block 1.1 */
		// End offset: 0x8004AFB8
		// End Line: 5216
	/* end block 1 */
	// End offset: 0x8004AFE4
	// End Line: 5220

	/* begin block 2 */
		// Start line: 12538
	/* end block 2 */
	// End Line: 12539

/* WARNING: Could not reconcile some variable overlaps */
/* File: C:\kain2\game\FX.C */

void FX_SoulReaverBlade(_Instance *instance,ulong **drawot)

{
  void *object;
  undefined4 in_zero;
  undefined4 in_at;
  short sVar1;
  TextureMT3 *pTVar2;
  int iVar3;
  ulong *puVar4;
  int a;
  int iVar5;
  void *pvVar6;
  short *psVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint local_84;
  MATRIX MStack128;
  undefined4 local_60;
  undefined4 local_4c;
  undefined4 local_44;
  undefined4 local_3c;
  uint local_34;
  int local_30;
  int local_2c;
  
  object = objectAccess[10].object;
  pvVar6 = instance->extraData;
  puVar10 = *(uint **)(DAT_800d210c + 4);
  if ((*(short *)((int)pvVar6 + 2) != 0) && (puVar10 + 400 < *(uint **)(DAT_800d210c + 8))) {
    uVar11 = *(uint *)((int)pvVar6 + 0x10);
    sVar1 = *(short *)((int)pvVar6 + 6);
    if (((objectAccess[10].object != (void *)0x0) &&
        ((((instance->flags & 0x200U) != 0 && ((instance->flags & 0x800U) == 0)) &&
         (instance->matrix != (MATRIX *)0x0)))) && (instance->oldMatrix != (MATRIX *)0x0)) {
      local_84 = local_84 & 0xffff0000;
      CompMatrix(DAT_800d0ffc,instance->matrix + 1,&MStack128);
      SetRotMatrix(&MStack128);
      SetTransMatrix(&MStack128);
      iVar12 = (int)*(short *)((int)pvVar6 + 2) * (int)*(short *)((int)pvVar6 + 0x1c);
      if (iVar12 < 0) {
        iVar12 = iVar12 + 0xfff;
      }
      pTVar2 = FX_GetTextureObject((Object *)object,0,0);
      setCopControlWord(2,0xe000,0);
      iVar9 = 1;
      local_3c = CONCAT22(local_3c._2_2_,*(ushort *)pTVar2);
      psVar7 = (short *)((int)puVar10 + 0x22);
      local_34._0_2_ = *(ushort *)pTVar2 & 0xff00 | *(ushort *)&pTVar2->u1 & 0xff;
      local_34 = local_34 & 0xffff0000 | (uint)(ushort)local_34;
      local_44 = *(undefined4 *)&pTVar2->u1;
      a = (int)sVar1;
      local_4c = CONCAT22(pTVar2->clut,*(undefined2 *)&pTVar2->u2);
      do {
        a = a + 0x100;
        iVar8 = (0x28 - iVar9) * 2;
        iVar5 = ((0x28 - iVar9) * 0x1000) / 0x28;
        iVar13 = iVar8 * (iVar12 >> 0xc);
        if ((iVar12 >> 0xc != 0x1000) && (iVar8 = iVar13 >> 0xc, iVar13 < 0)) {
          iVar8 = iVar13 + 0xfff >> 0xc;
        }
        if (iVar9 < 8) {
          iVar13 = iVar5 * 0x200 * iVar9;
          iVar5 = iVar13 >> 0xc;
          if (iVar13 < 0) {
            iVar5 = iVar13 + 0xfff >> 0xc;
          }
        }
        iVar13 = rcos(a);
        if (iVar13 < 0) {
          iVar13 = iVar13 + 0x7f;
        }
        iVar13 = (iVar13 >> 7) * iVar5;
        if (iVar13 < 0) {
          iVar13 = iVar13 + 0xfff;
        }
        iVar3 = rsin(a);
        if (iVar3 < 0) {
          iVar3 = iVar3 + 0x7f;
        }
        iVar5 = (iVar3 >> 7) * iVar5;
        if (iVar5 < 0) {
          iVar5 = iVar5 + 0xfff;
        }
        setCopReg(2,in_zero,iVar13 >> 0xc & 0xffffU | (iVar5 >> 0xc) << 0x10);
        setCopReg(2,in_at,local_84);
        setCopControlWord(2,0xd800,iVar8);
        copFunction(2,0x180001);
        *(undefined4 *)(psVar7 + -0xb) = local_4c;
        *(undefined4 *)(psVar7 + -7) = local_44;
        *(undefined4 *)(psVar7 + -3) = local_3c;
        *(uint *)(psVar7 + -0xf) = uVar11 | 0x2e000000;
        *(uint *)(psVar7 + 1) = local_34;
        local_60 = getCopReg(2,0xe);
        iVar5 = getCopReg(2,0x18);
        local_2c = getCopReg(2,0x13);
        iVar13 = (iVar5 / 0x140) * 0x200 + 0xffff;
        local_30 = iVar13 >> 0x10;
        iVar5 = iVar5 + 0xffff;
        local_30._0_2_ = (short)((uint)iVar13 >> 0x10);
        psVar7[-9] = (short)local_60 + (short)local_30;
        psVar7[-1] = (short)local_60 + (short)local_30;
        local_60._0_2_ = (short)local_60 - (short)(local_30 - (iVar13 >> 0x1f) >> 1);
        psVar7[-5] = (short)local_60;
        psVar7[-0xd] = (short)local_60;
        local_60._2_2_ = (short)((uint)local_60 >> 0x10);
        sVar1 = local_60._2_2_ - (short)((iVar5 >> 0x10) - (iVar5 >> 0x1f) >> 1);
        psVar7[-8] = sVar1;
        psVar7[-0xc] = sVar1;
        local_2c = local_2c >> 2;
        local_60._2_2_ = local_60._2_2_ + (short)((uint)iVar5 >> 0x10);
        psVar7[-4] = local_60._2_2_;
        *psVar7 = local_60._2_2_;
        if (local_2c - 1U < 0xbff) {
          psVar7 = psVar7 + 0x14;
          puVar4 = (ulong *)((uint)puVar10 & 0xffffff);
          *puVar10 = (uint)drawot[local_2c] & 0xffffff | 0x9000000;
          puVar10 = puVar10 + 10;
          drawot[local_2c] = puVar4;
        }
        if (iVar8 < 0) {
          iVar8 = iVar8 + 3;
        }
        iVar9 = iVar9 + 1;
        local_84 = local_84 & 0xffff0000 | (uint)(ushort)((short)local_84 - (short)(iVar8 >> 2));
      } while (iVar9 < 0x28);
      *(uint **)(DAT_800d210c + 4) = puVar10;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ReaverBladeInit()
 // line 5232, offset 0x8004b014
	/* begin block 1 */
		// Start line: 13089
	/* end block 1 */
	// End Line: 13090

	/* begin block 2 */
		// Start line: 13090
	/* end block 2 */
	// End Line: 13091

/* File: C:\kain2\game\FX.C */

void FX_ReaverBladeInit(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SoulReaverWinding(struct _Instance *instance /*stack 0*/, struct _PrimPool *primPool /*$a1*/, unsigned long **ot /*stack 8*/, struct MATRIX *wcTransform /*stack 12*/)
 // line 5239, offset 0x8004b01c
	/* begin block 1 */
		// Start line: 5240
		// Start offset: 0x8004B01C
		// Variables:
	// 		struct MATRIX mat; // stack offset -96
	// 		struct MATRIX *swTransform; // $a1
	// 		struct _SVector start; // stack offset -64
	// 		struct _SVector end; // stack offset -56
	// 		struct __ReaverData *data; // $s4
	// 		long color; // $s5
	// 		long glow_color; // stack offset -48
	/* end block 1 */
	// End offset: 0x8004B23C
	// End Line: 5314

	/* begin block 2 */
		// Start line: 13103
	/* end block 2 */
	// End Line: 13104

/* File: C:\kain2\game\FX.C */

void FX_SoulReaverWinding(_Instance *instance,_PrimPool *primPool,ulong **ot,undefined wcTransform)

{
  undefined3 in_register_0000001d;
  MATRIX *m0;
  short deg;
  char *pcVar1;
  long color;
  int iVar2;
  MATRIX MStack96;
  _SVector local_40;
  _SVector local_38;
  long local_30;
  
  m0 = (MATRIX *)CONCAT31(in_register_0000001d,wcTransform);
  pcVar1 = (char *)instance->extraData;
  if ((*pcVar1 != '\0') && (pcVar1[1] != '\0')) {
    deg = -*(short *)(pcVar1 + 6);
    CompMatrix(m0,(MATRIX *)(*(int *)(DAT_800d20f8 + 0x40) + 0x500),&MStack96);
    local_40.z = 0;
    local_40.y = 0;
    local_40.x = 0;
    local_38.y = 0;
    local_38.x = 0;
    local_38.z = -0x80;
    color = *(long *)(pcVar1 + 0x14);
    local_30 = *(long *)(pcVar1 + 0x18);
    FX_Lightning(wcTransform,ot,0xa0,deg,&local_40,&local_38,0x1e,10,0x10,0x20,0,color,local_30);
    CompMatrix(m0,(MATRIX *)(*(int *)(DAT_800d20f8 + 0x40) + 0x4e0),&MStack96);
    local_38.z = -0x60;
    FX_Lightning(wcTransform,ot,0xa0,deg,&local_40,&local_38,0x1e,10,0x10,0x20,0,color,local_30);
    iVar2 = (int)*(short *)(pcVar1 + 2) * (int)*(short *)(pcVar1 + 0x1c);
    if (iVar2 < 0) {
      iVar2 = iVar2 + 0xfff;
    }
    iVar2 = (iVar2 >> 0xc) * -0x17c;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 0xfff;
    }
    local_38.z = (short)(iVar2 >> 0xc);
    if (*(short *)(pcVar1 + 4) == 1) {
      color = 0xfcffd3;
    }
    CompMatrix(m0,instance->matrix + 1,&MStack96);
    FX_Lightning(wcTransform,ot,0xa0,deg,&local_40,&local_38,0,0x19,4,8,0,color,local_30);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartInstanceBurrow(struct _Instance *instance /*$s0*/, struct Level *level /*$s2*/, struct _TFace *tface /*$s1*/)
 // line 5319, offset 0x8004b26c
	/* begin block 1 */
		// Start line: 5320
		// Start offset: 0x8004B26C
		// Variables:
	// 		struct _SVector normal; // stack offset -32
	// 		struct _SVector *poPlane; // $a1
	// 		struct _SVector point; // stack offset -24
	// 		struct _Position *globalOffset; // $v1
	/* end block 1 */
	// End offset: 0x8004B26C
	// End Line: 5320

	/* begin block 2 */
		// Start line: 13295
	/* end block 2 */
	// End Line: 13296

/* File: C:\kain2\game\FX.C */

void FX_StartInstanceBurrow(_Instance *instance,Level *level,_TFace *tface)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  BSPTree *pBVar7;
  _TVertex *p_Var8;
  _SVector local_20 [2];
  
  COLLIDE_GetNormal(tface->normal,(short *)level->terrain->normalList,local_20);
  (instance->halvePlane).a = local_20[0].x;
  (instance->halvePlane).b = local_20[0].y;
  (instance->halvePlane).c = local_20[0].z;
  p_Var8 = level->terrain->vertexList + (tface->face).v0;
  sVar1 = (p_Var8->vertex).x;
  pBVar7 = level->terrain->BSPTreeArray + instance->bspTree;
  sVar2 = (pBVar7->globalOffset).x;
  sVar3 = (p_Var8->vertex).y;
  sVar4 = (pBVar7->globalOffset).y;
  sVar5 = (p_Var8->vertex).z;
  sVar6 = (pBVar7->globalOffset).z;
  (instance->halvePlane).flags = 1;
  (instance->halvePlane).d =
       -((int)(instance->halvePlane).a * (int)(short)(sVar1 + sVar2) +
         (int)(instance->halvePlane).b * (int)(short)(sVar3 + sVar4) +
         (int)(instance->halvePlane).c * (int)(short)(sVar5 + sVar6) >> 0xc);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StopInstanceBurrow(struct _Instance *instance /*$a0*/)
 // line 5344, offset 0x8004b3a0
	/* begin block 1 */
		// Start line: 13354
	/* end block 1 */
	// End Line: 13355

	/* begin block 2 */
		// Start line: 13355
	/* end block 2 */
	// End Line: 13356

/* File: C:\kain2\game\FX.C */

void FX_StopInstanceBurrow(_Instance *instance)

{
  (instance->halvePlane).flags = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdateInstanceWaterSplit(struct _Instance *instance /*$s0*/)
 // line 5350, offset 0x8004b3a8
	/* begin block 1 */
		// Start line: 5351
		// Start offset: 0x8004B3A8
		// Variables:
	// 		struct _SVector normal; // stack offset -16
	/* end block 1 */
	// End offset: 0x8004B438
	// End Line: 5378

	/* begin block 2 */
		// Start line: 13366
	/* end block 2 */
	// End Line: 13367

/* File: C:\kain2\game\FX.C */

void FX_UpdateInstanceWaterSplit(_Instance *instance)

{
  _SVector _Stack16;
  
  if ((instance->waterFace == (_TFace *)0x0) || (instance->waterFaceTerrain == (_Terrain *)0x0)) {
    (instance->halvePlane).flags = (instance->halvePlane).flags & 0xfffd;
  }
  else {
    if (((instance->halvePlane).flags & 8U) == 0) {
      COLLIDE_GetNormal(instance->waterFace->normal,(short *)instance->waterFaceTerrain->normalList,
                        &_Stack16);
      (instance->halvePlane).flags = 2;
      FX_GetPlaneEquation(&_Stack16,&instance->splitPoint,&instance->halvePlane);
    }
    FX_MakeWaterTrail(instance,(int)(instance->splitPoint).z);
  }
  instance->oldWaterFace = instance->waterFace;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_GetPlaneEquation(struct _SVector *normal /*$a0*/, struct _SVector *poPlane /*$a1*/, struct _PlaneConstants *plane /*$a2*/)
 // line 5381, offset 0x8004b454
	/* begin block 1 */
		// Start line: 13431
	/* end block 1 */
	// End Line: 13432

	/* begin block 2 */
		// Start line: 13433
	/* end block 2 */
	// End Line: 13434

/* File: C:\kain2\game\FX.C */

void FX_GetPlaneEquation(_SVector *normal,_SVector *poPlane,_PlaneConstants *plane)

{
  short sVar1;
  
  plane->a = normal->x;
  plane->b = normal->y;
  sVar1 = normal->z;
  plane->c = sVar1;
  plane->d = -((int)plane->a * (int)poPlane->x + (int)plane->b * (int)poPlane->y +
               (int)sVar1 * (int)poPlane->z >> 0xc);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DoInstancePowerRing(struct _Instance *instance /*$s4*/, long atuTime /*$s1*/, long *color /*$s3*/, long numColors /*$s2*/, int follow_halveplane /*stack 16*/)
 // line 5424, offset 0x8004b4c8
	/* begin block 1 */
		// Start line: 5425
		// Start offset: 0x8004B4C8
		// Variables:
	// 		struct _FXHalvePlane *ring; // $s0
	// 		struct _SVector normal; // stack offset -40
	// 		struct _SVector point; // stack offset -32
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x8004B628
	// End Line: 5472

	/* begin block 2 */
		// Start line: 10842
	/* end block 2 */
	// End Line: 10843

/* File: C:\kain2\game\FX.C */

void FX_DoInstancePowerRing
               (_Instance *instance,long atuTime,long *color,long numColors,int follow_halveplane)

{
  char *ptr;
  long lVar1;
  int iVar2;
  int iVar3;
  long *plVar4;
  _SVector local_28;
  _SVector local_20;
  
  ptr = MEMPACK_Malloc(numColors * 4 + 0x2c,'\r');
  if (ptr == (char *)0x0) {
    return;
  }
  ptr[0xc] = -0x7e;
  *(undefined4 *)(ptr + 4) = 0x8004b8cc;
  *(undefined4 *)(ptr + 0x10) = 0;
  *(_Instance **)(ptr + 8) = instance;
  *(undefined4 *)(ptr + 0x24) = 0;
  *(undefined2 *)(ptr + 0x2a) = 0;
  *(short *)(ptr + 0x28) = (short)numColors;
  ptr[0xd] = (char)follow_halveplane;
  *(short *)(ptr + 0xe) = (short)((atuTime * 1000) / 0x4b0);
  if (numColors < 2) {
    if (color == (long *)0x0) {
      lVar1 = 0xff8010;
      goto code_r0x8004b5e4;
    }
  }
  else {
    *(char **)(ptr + 0x24) = ptr + 0x2c;
    iVar3 = 0;
    plVar4 = color;
    if (0 < numColors) {
      do {
        iVar2 = iVar3 * 4;
        iVar3 = iVar3 + 1;
        *(long *)(iVar2 + *(int *)(ptr + 0x24)) = *plVar4;
        plVar4 = plVar4 + 1;
      } while (iVar3 < numColors);
    }
    *(short *)(ptr + 0x2a) = (short)((int)*(short *)(ptr + 0xe) / (numColors + -1));
  }
  lVar1 = *color;
code_r0x8004b5e4:
  *(long *)(ptr + 0x20) = lVar1;
  local_28.y = 0;
  local_28.x = 0;
  local_28.z = 0x1000;
  local_20.x = (instance->position).x;
  local_20.y = (instance->position).y;
  local_20.z = (instance->position).z;
  FX_GetPlaneEquation(&local_28,&local_20,(_PlaneConstants *)(ptr + 0x14));
  FX_InsertGeneralEffect(ptr);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdatePowerRing(struct _FXHalvePlane *ring /*$s2*/)
 // line 5476, offset 0x8004b648
	/* begin block 1 */
		// Start line: 5477
		// Start offset: 0x8004B648
		// Variables:
	// 		struct _Instance *instance; // $v1
	// 		struct _PlaneConstants *cPlane; // $s1
	// 		long offset; // $s5
	// 		long offset2; // $s4
	// 		long cutX; // $s6
	// 		long cutY; // $s7
	// 		long cutZ; // $s3
	// 		long colorIndex; // $a2
	// 		long percent; // $a1
	/* end block 1 */
	// End offset: 0x8004B88C
	// End Line: 5536

	/* begin block 2 */
		// Start line: 13610
	/* end block 2 */
	// End Line: 13611

/* File: C:\kain2\game\FX.C */

void FX_UpdatePowerRing(_FXHalvePlane *ring)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  long *plVar5;
  _Instance *p_Var6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint a;
  int iVar11;
  
  iVar7 = (int)ring->lifeTime;
  p_Var6 = ring->instance;
  sVar1 = (p_Var6->position).z;
  sVar2 = (p_Var6->position).x;
  sVar3 = (p_Var6->position).y;
  a = ((DAT_800d2300 % 1000) * 0x1000) / 1000;
  iVar11 = 0x200 - (ring->diffTime << 9) / iVar7;
  if (iVar7 <= ring->diffTime) {
    iVar11 = 0x200;
    ring->diffTime = iVar7;
    ring->lifeTime = 0;
  }
  (ring->ringPlane).flags = 0;
  iVar7 = rsin(200);
  iVar4 = rsin(a);
  (ring->ringPlane).a = (short)(iVar7 * iVar4 >> 0xc);
  iVar7 = rsin(200);
  iVar4 = rcos(a);
  (ring->ringPlane).b = (short)(-iVar7 * iVar4 >> 0xc);
  iVar7 = rcos(200);
  (ring->ringPlane).c = (short)iVar7;
  (ring->ringPlane).d =
       -((int)(ring->ringPlane).a * (int)sVar2 + (int)(ring->ringPlane).b * (int)sVar3 +
         (int)(short)iVar7 * (sVar1 + iVar11) >> 0xc);
  if (ring->colorArray != (long *)0x0) {
    iVar7 = 0;
    if (ring->diffTime != 0) {
      iVar7 = ring->diffTime / (int)ring->colorBlendLife;
    }
    iVar11 = (ring->diffTime % ((int)ring->colorBlendLife + 1) << 0xc) / (int)ring->colorBlendLife;
    if ((int)ring->numColors + -1 <= iVar7) {
      iVar7 = (int)ring->numColors + -2;
      iVar11 = 0x1000;
    }
    setCopReg(2,0x4000,0x1000 - iVar11);
    plVar5 = ring->colorArray + iVar7;
    setCopReg(2,0x4800,(uint)*(byte *)plVar5);
    setCopReg(2,0x5000,(uint)*(byte *)((int)plVar5 + 1));
    setCopReg(2,0x5800,(uint)*(byte *)((int)plVar5 + 2));
    copFunction(2,0x198003d);
    setCopReg(2,0x4000,iVar11);
    plVar5 = ring->colorArray + iVar7 + 1;
    setCopReg(2,0x4800,(uint)*(byte *)plVar5);
    setCopReg(2,0x5000,(uint)*(byte *)((int)plVar5 + 1));
    setCopReg(2,0x5800,(uint)*(byte *)((int)plVar5 + 2));
    copFunction(2,0x1a8003e);
    uVar8 = getCopReg(2,0x4800);
    uVar9 = getCopReg(2,0x5000);
    uVar10 = getCopReg(2,0x5800);
    *(char *)&ring->currentColor = (char)uVar8;
    *(undefined *)((int)&ring->currentColor + 1) = (char)uVar9;
    *(undefined *)((int)&ring->currentColor + 2) = (char)uVar10;
  }
  ring->diffTime = ring->diffTime + DAT_800d2310;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdateInstanceSplitRing(struct _FXHalvePlane *ring /*$s0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 5621, offset 0x8004b8cc
	/* begin block 1 */
		// Start line: 13923
	/* end block 1 */
	// End Line: 13924

/* File: C:\kain2\game\FX.C */

void FX_UpdateInstanceSplitRing(_FXHalvePlane *ring,_FXTracker *fxTracker)

{
  int iVar1;
  
  if (ring->lifeTime != 0) {
    if (ring->type == '\0') {
      FX_UpdatePowerRing(ring);
    }
    else {
      iVar1 = ring->diffTime + DAT_800d2310;
      ring->diffTime = iVar1;
      if ((int)ring->lifeTime <= iVar1) {
        ring->diffTime = (int)ring->lifeTime;
        ring->lifeTime = 0;
      }
    }
    if (ring->lifeTime != 0) {
      return;
    }
  }
  FX_DeleteGeneralEffect((_FXGeneralEffect *)ring);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdateGlowEffect(struct _FXGlowEffect *effect /*$a0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 5644, offset 0x8004b95c
	/* begin block 1 */
		// Start line: 13970
	/* end block 1 */
	// End Line: 13971

/* File: C:\kain2\game\FX.C */

void FX_UpdateGlowEffect(_FXGlowEffect *effect,_FXTracker *fxTracker)

{
  if (effect->lifeTime == 0) {
    FX_DeleteGeneralEffect((_FXGeneralEffect *)effect);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_InsertGeneralEffect(void *ptr /*$a0*/)
 // line 5652, offset 0x8004b98c
	/* begin block 1 */
		// Start line: 5654
		// Start offset: 0x8004B98C
	/* end block 1 */
	// End offset: 0x8004B98C
	// End Line: 5655

	/* begin block 2 */
		// Start line: 13986
	/* end block 2 */
	// End Line: 13987

	/* begin block 3 */
		// Start line: 13987
	/* end block 3 */
	// End Line: 13988

	/* begin block 4 */
		// Start line: 13988
	/* end block 4 */
	// End Line: 13989

/* File: C:\kain2\game\FX.C */

void FX_InsertGeneralEffect(void *ptr)

{
  void *pvVar1;
  
  pvVar1 = ptr;
  *(void **)ptr = FX_GeneralEffectTracker;
  FX_GeneralEffectTracker = pvVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DeleteGeneralEffect(struct _FXGeneralEffect *effect /*$s0*/)
 // line 5660, offset 0x8004b99c
	/* begin block 1 */
		// Start line: 5661
		// Start offset: 0x8004B99C
		// Variables:
	// 		struct _FXGeneralEffect *currentEffect; // $v0
	// 		struct _FXGeneralEffect *previousEffect; // $v1
	/* end block 1 */
	// End offset: 0x8004BA28
	// End Line: 5693

	/* begin block 2 */
		// Start line: 14003
	/* end block 2 */
	// End Line: 14004

/* File: C:\kain2\game\FX.C */

void FX_DeleteGeneralEffect(_FXGeneralEffect *effect)

{
  _FXGeneralEffect *p_Var1;
  _FXGeneralEffect *p_Var2;
  _FXGeneralEffect *p_Var3;
  
  if (effect != (_FXGeneralEffect *)0x0) {
    p_Var1 = FX_GeneralEffectTracker;
    p_Var3 = (_FXGeneralEffect *)0x0;
    if (FX_GeneralEffectTracker != (_FXGeneralEffect *)0x0) {
      do {
        p_Var2 = p_Var1;
        if (p_Var2 == effect) {
          if (p_Var3 == (_FXGeneralEffect *)0x0) {
            FX_GeneralEffectTracker = (_FXGeneralEffect *)effect->next;
          }
          else {
            p_Var3->next = effect->next;
          }
          break;
        }
        p_Var1 = (_FXGeneralEffect *)p_Var2->next;
        p_Var3 = p_Var2;
      } while ((_FXGeneralEffect *)p_Var2->next != (_FXGeneralEffect *)0x0);
    }
    if (effect->effectType == '\0') {
      MEMPACK_Free((char *)effect[1].continue_process);
    }
    MEMPACK_Free((char *)effect);
  }
  return;
}



// decompiled code
// original method signature: 
// struct _FXGlowEffect * /*$ra*/ FX_DoInstanceOneSegmentGlow(struct _Instance *instance /*$s3*/, long segment /*$s4*/, long *color /*$s2*/, long numColors /*$s1*/, long atuColorCycleRate /*stack 16*/, long width /*stack 20*/, long height /*stack 24*/)
 // line 5698, offset 0x8004ba38
	/* begin block 1 */
		// Start line: 5699
		// Start offset: 0x8004BA38
		// Variables:
	// 		struct _FXGlowEffect *glowEffect; // $a2

		/* begin block 1.1 */
			// Start line: 5731
			// Start offset: 0x8004BB00
			// Variables:
		// 		int i; // $a1
		/* end block 1.1 */
		// End offset: 0x8004BB58
		// End Line: 5744
	/* end block 1 */
	// End offset: 0x8004BB64
	// End Line: 5750

	/* begin block 2 */
		// Start line: 14079
	/* end block 2 */
	// End Line: 14080

/* File: C:\kain2\game\FX.C */

_FXGlowEffect *
FX_DoInstanceOneSegmentGlow
          (_Instance *instance,long segment,long *color,long numColors,long atuColorCycleRate,
          long width,long height)

{
  _FXGlowEffect *p_Var1;
  _FXGlowEffect *p_Var2;
  long lVar3;
  int iVar4;
  int iVar5;
  long *plVar6;
  
  p_Var2 = (_FXGlowEffect *)MEMPACK_Malloc(numColors * 4 + 0x2c,'\r');
  if (p_Var2 == (_FXGlowEffect *)0x0) goto LAB_8004bb64;
  p_Var2->effectType = -0x7d;
  *(code **)&p_Var2->continue_process = FX_UpdateGlowEffect;
  p_Var2->colorArray = (long *)0x0;
  p_Var2->numColors = (short)numColors;
  p_Var2->colorBlendCycle = (short)(atuColorCycleRate * 0x21);
  p_Var2->width = (short)width;
  p_Var2->instance = instance;
  p_Var2->segment = (short)segment;
  p_Var2->diffTime = 0;
  p_Var2->fadein_time = 0;
  p_Var2->fadeout_time = 0;
  p_Var2->height = (short)height;
  p_Var2->lifeTime = -1;
  p_Var2->SegmentInc = '\x01';
  p_Var2->numSegments = '\x01';
  if (numColors < 2) {
    if (color != (long *)0x0) goto LAB_8004bb4c;
    lVar3 = 0xff8010;
  }
  else {
    *(_FXGlowEffect **)&p_Var2->colorArray = p_Var2 + 1;
    iVar4 = 0;
    plVar6 = color;
    if (0 < numColors) {
      do {
        iVar5 = iVar4 + 1;
        p_Var2->colorArray[iVar4] = *plVar6;
        iVar4 = iVar5;
        plVar6 = plVar6 + 1;
      } while (iVar5 < numColors);
    }
    p_Var2->colorBlendCycle = (short)((atuColorCycleRate * 0x21) / (numColors + -1));
LAB_8004bb4c:
    lVar3 = *color;
  }
  p_Var2->currentColor = lVar3;
  p_Var1 = p_Var2;
  *(_FXGlowEffect **)&p_Var2->next = FX_GeneralEffectTracker;
  FX_GeneralEffectTracker = p_Var1;
LAB_8004bb64:
  instance->flags2 = instance->flags2 | 0x200;
  return p_Var2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SetGlowFades(struct _FXGlowEffect *glowEffect /*$a0*/, int fadein /*$a1*/, int fadeout /*$a2*/)
 // line 5755, offset 0x8004bb98
	/* begin block 1 */
		// Start line: 14215
	/* end block 1 */
	// End Line: 14216

	/* begin block 2 */
		// Start line: 14216
	/* end block 2 */
	// End Line: 14217

/* File: C:\kain2\game\FX.C */

void FX_SetGlowFades(_FXGlowEffect *glowEffect,int fadein,int fadeout)

{
  glowEffect->fadein_time = (short)fadein * 0x21;
  glowEffect->fadeout_time = (short)fadeout * 0x21;
  return;
}



// decompiled code
// original method signature: 
// struct _FXGlowEffect * /*$ra*/ FX_DoInstanceTwoSegmentGlow(struct _Instance *instance /*$a0*/, long segment /*$a1*/, long segmentEnd /*$a2*/, long *color /*$a3*/, long numColors /*stack 16*/, long atuColorCycleRate /*stack 20*/, long height /*stack 24*/)
 // line 5761, offset 0x8004bbb4
	/* begin block 1 */
		// Start line: 5762
		// Start offset: 0x8004BBB4
		// Variables:
	// 		struct _FXGlowEffect *glowEffect; // $v0
	// 		int inc; // $s0
	/* end block 1 */
	// End offset: 0x8004BBD4
	// End Line: 5770

	/* begin block 2 */
		// Start line: 14227
	/* end block 2 */
	// End Line: 14228

/* File: C:\kain2\game\FX.C */

_FXGlowEffect *
FX_DoInstanceTwoSegmentGlow
          (_Instance *instance,long segment,long segmentEnd,long *color,long numColors,
          long atuColorCycleRate,long height)

{
  _FXGlowEffect *p_Var1;
  uchar uVar2;
  
  uVar2 = (uchar)(segmentEnd - segment);
  if (segmentEnd - segment < 0) {
    uVar2 = -uVar2;
    segment = segmentEnd;
  }
  p_Var1 = FX_DoInstanceOneSegmentGlow
                     (instance,segment,color,numColors,atuColorCycleRate,height,height);
  p_Var1->numSegments = '\x02';
  p_Var1->SegmentInc = uVar2;
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct _FXGlowEffect * /*$ra*/ FX_DoInstanceManySegmentGlow(struct _Instance *instance /*$a0*/, long segment /*$a1*/, long numSegments /*$s0*/, long *color /*$a3*/, long numColors /*stack 16*/, long atuColorCycleRate /*stack 20*/, long height /*stack 24*/)
 // line 5777, offset 0x8004bc0c
	/* begin block 1 */
		// Start line: 5778
		// Start offset: 0x8004BC0C
		// Variables:
	// 		struct _FXGlowEffect *glowEffect; // $v0
	/* end block 1 */
	// End offset: 0x8004BC0C
	// End Line: 5778

	/* begin block 2 */
		// Start line: 14263
	/* end block 2 */
	// End Line: 14264

/* File: C:\kain2\game\FX.C */

_FXGlowEffect *
FX_DoInstanceManySegmentGlow
          (_Instance *instance,long segment,long numSegments,long *color,long numColors,
          long atuColorCycleRate,long height)

{
  _FXGlowEffect *p_Var1;
  
  p_Var1 = FX_DoInstanceOneSegmentGlow
                     (instance,segment,color,numColors,atuColorCycleRate,height,height);
  p_Var1->numSegments = (uchar)numSegments;
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct _FXGlowEffect * /*$ra*/ FX_DoInstanceOneSegmentGlowWithTime(struct _Instance *instance /*$a0*/, long segment /*$a1*/, long *color /*$a2*/, long numColors /*$a3*/, long atuColorCycleRate /*stack 16*/, long width /*stack 20*/, long height /*stack 24*/, long ATULifeTime /*stack 28*/)
 // line 5788, offset 0x8004bc54
	/* begin block 1 */
		// Start line: 5789
		// Start offset: 0x8004BC54
		// Variables:
	// 		struct _FXGlowEffect *glowEffect; // $v0
	/* end block 1 */
	// End offset: 0x8004BC54
	// End Line: 5789

	/* begin block 2 */
		// Start line: 14288
	/* end block 2 */
	// End Line: 14289

/* File: C:\kain2\game\FX.C */

_FXGlowEffect *
FX_DoInstanceOneSegmentGlowWithTime
          (_Instance *instance,long segment,long *color,long numColors,long atuColorCycleRate,
          long width,long height,long ATULifeTime)

{
  _FXGlowEffect *p_Var1;
  
  p_Var1 = FX_DoInstanceOneSegmentGlow
                     (instance,segment,color,numColors,atuColorCycleRate,width,height);
  p_Var1->lifeTime = (short)ATULifeTime * 0x21;
  return p_Var1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StopAllGlowEffects(struct _Instance *instance /*$s3*/, int fadeout_time /*$s0*/)
 // line 5800, offset 0x8004bc9c
	/* begin block 1 */
		// Start line: 5801
		// Start offset: 0x8004BC9C
		// Variables:
	// 		struct _FXGlowEffect *currentEffect; // $a0
	// 		struct _FXGlowEffect *previousEffect; // $s1

		/* begin block 1.1 */
			// Start line: 5816
			// Start offset: 0x8004BCF4
		/* end block 1.1 */
		// End offset: 0x8004BCF4
		// End Line: 5817
	/* end block 1 */
	// End offset: 0x8004BD14
	// End Line: 5825

	/* begin block 2 */
		// Start line: 14312
	/* end block 2 */
	// End Line: 14313

/* File: C:\kain2\game\FX.C */

void FX_StopAllGlowEffects(_Instance *instance,int fadeout_time)

{
  _FXGeneralEffect *effect;
  short sVar1;
  _FXGeneralEffect *p_Var2;
  
  effect = FX_GeneralEffectTracker;
  if (FX_GeneralEffectTracker != (_FXGeneralEffect *)0x0) {
    do {
      p_Var2 = (_FXGeneralEffect *)effect->next;
      if ((effect->effectType == -0x7d) && (effect->instance == instance)) {
        if (fadeout_time * 0x21 == 0) {
          FX_DeleteGeneralEffect(effect);
        }
        else {
          sVar1 = (short)(fadeout_time * 0x21);
          *(short *)((int)&effect[2].instance + 2) = sVar1;
          effect->lifeTime = sVar1;
        }
      }
      effect = p_Var2;
    } while (p_Var2 != (_FXGeneralEffect *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StopGlowEffect(struct _FXGlowEffect *glowEffect /*$s1*/, int fadeout_time /*$a1*/)
 // line 5827, offset 0x8004bd30
	/* begin block 1 */
		// Start line: 5828
		// Start offset: 0x8004BD30

		/* begin block 1.1 */
			// Start line: 5837
			// Start offset: 0x8004BD74
			// Variables:
		// 		struct _FXGeneralEffect *currentEffect; // $a0
		// 		struct _FXGeneralEffect *previousEffect; // $s0
		/* end block 1.1 */
		// End offset: 0x8004BDA0
		// End Line: 5850
	/* end block 1 */
	// End offset: 0x8004BDA0
	// End Line: 5851

	/* begin block 2 */
		// Start line: 14378
	/* end block 2 */
	// End Line: 14379

/* File: C:\kain2\game\FX.C */

void FX_StopGlowEffect(_FXGlowEffect *glowEffect,int fadeout_time)

{
  short sVar1;
  _FXGlowEffect *effect;
  _FXGlowEffect *p_Var2;
  
  if (glowEffect != (_FXGlowEffect *)0x0) {
    if (fadeout_time == 0) {
      effect = FX_GeneralEffectTracker;
      if (FX_GeneralEffectTracker != (_FXGlowEffect *)0x0) {
        do {
          p_Var2 = (_FXGlowEffect *)effect->next;
          if ((effect->effectType == -0x7d) && (effect == glowEffect)) {
            FX_DeleteGeneralEffect((_FXGeneralEffect *)effect);
          }
          effect = p_Var2;
        } while (p_Var2 != (_FXGlowEffect *)0x0);
      }
    }
    else {
      sVar1 = (short)fadeout_time * 0x21;
      glowEffect->fadeout_time = sVar1;
      glowEffect->lifeTime = sVar1;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawLightning(struct _FXLightning *zap /*$s1*/, struct MATRIX *wcTransform /*$s2*/, unsigned long **ot /*$s3*/)
 // line 5853, offset 0x8004bdb8
	/* begin block 1 */
		// Start line: 5854
		// Start offset: 0x8004BDB8
		// Variables:
	// 		struct _SVector start; // stack offset -48
	// 		struct _SVector end; // stack offset -40
	// 		struct _SVector offset; // stack offset -32
	// 		struct MATRIX *swtransform; // $s0
	/* end block 1 */
	// End offset: 0x8004BFB4
	// End Line: 5910

	/* begin block 2 */
		// Start line: 14432
	/* end block 2 */
	// End Line: 14433

/* File: C:\kain2\game\FX.C */

void FX_DrawLightning(_FXLightning *zap,undefined1 wcTransform,ulong **ot)

{
  MATRIX *m;
  char mat;
  _SVector local_30;
  _SVector local_28;
  SVECTOR local_20;
  
  if (zap->type == '\x02') {
    local_30.x = (zap->start_offset).x;
    local_30.y = (zap->start_offset).y;
    local_30.z = (zap->start_offset).z;
  }
  else {
    m = zap->instance->matrix;
    if (m == (MATRIX *)0x0) {
      local_30.x = (zap->instance->position).x;
      local_30.y = (zap->instance->position).y;
      local_30.z = (zap->instance->position).z;
    }
    else {
      m = m + zap->startSeg;
      ApplyMatrixSV(m,(SVECTOR *)&zap->start_offset,&local_20);
      local_30.x = *(short *)m->t + local_20.vx;
      local_30.y = *(short *)(m->t + 1) + local_20.vy;
      local_30.z = *(short *)(m->t + 2) + local_20.vz;
    }
  }
  if ((uint)zap->type - 1 < 2) {
    local_28.x = (zap->end_offset).x;
    local_28.y = (zap->end_offset).y;
    local_28.z = (zap->end_offset).z;
  }
  else {
    m = zap->end_instance->matrix;
    if (m == (MATRIX *)0x0) {
      local_28.x = (zap->instance->position).x;
      local_28.y = (zap->instance->position).y;
      local_28.z = (zap->instance->position).z;
    }
    else {
      m = m + zap->endSeg;
      ApplyMatrixSV(m,(SVECTOR *)&zap->end_offset,&local_20);
      local_28.x = *(short *)m->t + local_20.vx;
      local_28.y = *(short *)(m->t + 1) + local_20.vy;
      local_28.z = *(short *)(m->t + 2) + local_20.vz;
    }
  }
  mat = '\0';
  if (zap->matrixSeg != -1) {
    m = zap->instance->matrix;
    if (m != (MATRIX *)0x0) {
      mat = (char)m + (char)zap->matrixSeg * ' ';
    }
  }
  FX_Lightning(wcTransform,ot,mat,zap->deg,&local_30,&local_28,(int)zap->width,(int)zap->small_width
               ,(int)zap->segs,(int)zap->sine_size,(int)zap->variation,zap->color,zap->glow_color);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawAllGeneralEffects(struct MATRIX *wcTransform /*$s1*/, struct _VertexPool *vertexPool /*$s3*/, struct _PrimPool *primPool /*$s4*/, unsigned long **ot /*$s2*/)
 // line 5917, offset 0x8004c03c
	/* begin block 1 */
		// Start line: 5918
		// Start offset: 0x8004C03C
		// Variables:
	// 		struct _Instance *instance; // $a0
	// 		struct _FXGeneralEffect *currentEffect; // $s0

		/* begin block 1.1 */
			// Start line: 5931
			// Start offset: 0x8004C0C8
			// Variables:
		// 		struct _FXGlowEffect *currentGlow; // $t0
		/* end block 1.1 */
		// End offset: 0x8004C0F8
		// End Line: 5939

		/* begin block 1.2 */
			// Start line: 5943
			// Start offset: 0x8004C120
		/* end block 1.2 */
		// End offset: 0x8004C120
		// End Line: 5944

		/* begin block 1.3 */
			// Start line: 5953
			// Start offset: 0x8004C164
		/* end block 1.3 */
		// End offset: 0x8004C164
		// End Line: 5955

		/* begin block 1.4 */
			// Start line: 5963
			// Start offset: 0x8004C1BC
		/* end block 1.4 */
		// End offset: 0x8004C1BC
		// End Line: 5965
	/* end block 1 */
	// End offset: 0x8004C1F4
	// End Line: 5975

	/* begin block 2 */
		// Start line: 14562
	/* end block 2 */
	// End Line: 14563

/* File: C:\kain2\game\FX.C */

void FX_DrawAllGeneralEffects
               (undefined1 wcTransform,_VertexPool *vertexPool,_PrimPool *primPool,ulong **ot)

{
  byte bVar1;
  int iVar2;
  _Instance *instance;
  _FXBlastringEffect *blast;
  
  blast = FX_GeneralEffectTracker;
  if (FX_GeneralEffectTracker != (_FXBlastringEffect *)0x0) {
    do {
      bVar1 = blast->effectType;
      if (((bVar1 & 0x80) != 0) &&
         ((instance = blast->instance, instance == (_Instance *)0x0 ||
          (((instance->flags & 0x800U) == 0 && ((instance->flags2 & 0x4000000U) == 0)))))) {
        if (bVar1 == 0x83) {
          if ((0 < blast->lifeTime) &&
             (iVar2 = (uint)(ushort)blast->lifeTime - (uint)(ushort)DAT_800d2310,
             blast->lifeTime = (short)iVar2, iVar2 * 0x10000 < 0)) {
            blast->lifeTime = 0;
          }
          PIPE3D_DoGlow(instance,wcTransform,vertexPool,primPool,ot,(_FXGlowEffect *)blast);
        }
        else {
          if (bVar1 == 0x82) {
            PIPE3D_HalvePlaneGetRingPoints
                      (instance,wcTransform,vertexPool,primPool,ot,(_FXHalvePlane *)blast);
          }
          else {
            if (bVar1 == 0x84) {
              FX_DrawBlastring(wcTransform,blast);
            }
            else {
              if (bVar1 == 0x85) {
                FX_LightHouse(wcTransform,ot,blast->instance,(int)(blast->position).x,
                              (int)(blast->position).y,0x20,*(long *)&(blast->position).z);
              }
              else {
                if (bVar1 == 0x86) {
                  FX_DrawFField(wcTransform,(_FXForceFieldEffect *)blast);
                }
                else {
                  if (bVar1 == 0x87) {
                    FX_DrawLightning((_FXLightning *)blast,wcTransform,ot);
                  }
                  else {
                    if (bVar1 == 0x88) {
                      FX_DrawFlash((_FXFlash *)blast);
                    }
                  }
                }
              }
            }
          }
        }
      }
      blast = (_FXBlastringEffect *)blast->next;
    } while (blast != (_FXBlastringEffect *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueBlastRing(struct _FXBlastringEffect *blast /*$s0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 5985, offset 0x8004c214
	/* begin block 1 */
		// Start line: 5986
		// Start offset: 0x8004C214
		// Variables:
	// 		int fade; // $a2
	// 		int tm; // $v0

		/* begin block 1.1 */
			// Start line: 5997
			// Start offset: 0x8004C284
			// Variables:
		// 		int rad; // $v0
		// 		int crad; // $a0
		// 		int endrad; // $v1
		/* end block 1.1 */
		// End offset: 0x8004C340
		// End Line: 6018
	/* end block 1 */
	// End offset: 0x8004C3C0
	// End Line: 6037

	/* begin block 2 */
		// Start line: 14703
	/* end block 2 */
	// End Line: 14704

	/* begin block 3 */
		// Start line: 14708
	/* end block 3 */
	// End Line: 14709

/* File: C:\kain2\game\FX.C */

void FX_ContinueBlastRing(_FXBlastringEffect *blast,_FXTracker *fxTracker)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long p0;
  
  iVar5 = blast->vel * (DAT_800d2314 >> 4);
  if (iVar5 < 0) {
    iVar5 = iVar5 + 0xff;
  }
  iVar2 = (int)FX_Frames;
  iVar4 = blast->colorchange_radius;
  blast->radius = blast->radius + (iVar5 >> 8);
  iVar5 = blast->radius;
  iVar2 = blast->vel + blast->accl * iVar2;
  blast->vel = iVar2;
  if (iVar4 < iVar5) {
    if (iVar5 < 0) {
      iVar5 = iVar5 + 0xfff;
    }
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0xfff;
    }
    iVar3 = blast->endRadius;
    iVar4 = iVar4 >> 0xc;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0xfff;
    }
    if (iVar2 < 0) {
      iVar2 = blast->startRadius;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 0xfff;
      }
      p0 = (((iVar5 >> 0xc) - iVar4) * 0x1000) / ((iVar2 >> 0xc) - iVar4);
    }
    else {
      p0 = (((iVar5 >> 0xc) - iVar4) * 0x1000) / ((iVar3 >> 0xc) - iVar4);
    }
    if (p0 < 0x1001) {
      LoadAverageCol((u_char *)&blast->endColor,(u_char *)&blast->startColor,p0,0x1000 - p0,
                     (u_char *)&blast->color);
      blast->color = blast->color & 0xffffff;
    }
    else {
      blast->color = 0;
    }
  }
  if (((blast->lifeTime != -99) &&
      (((0 < blast->vel && (blast->endRadius < blast->radius)) ||
       ((blast->vel < 0 && (blast->radius < blast->endRadius)))))) ||
     ((uVar1 = blast->lifeTime - 1, -1 < blast->lifeTime &&
      (blast->lifeTime = uVar1, (int)((uint)uVar1 << 0x10) < 1)))) {
    FX_DeleteGeneralEffect((_FXGeneralEffect *)blast);
  }
  return;
}



// decompiled code
// original method signature: 
// struct _FXBlastringEffect * /*$ra*/ FX_DoBlastRing(struct _Instance *instance /*$s2*/, struct _SVector *position /*$s5*/, struct MATRIX *mat /*$s3*/, int segment /*$s6*/, int radius /*stack 16*/, int endRadius /*stack 20*/, int colorChangeRadius /*stack 24*/, int size1 /*stack 28*/, int size2 /*stack 32*/, int vel /*stack 36*/, int accl /*stack 40*/, int height1 /*stack 44*/, int height2 /*stack 48*/, int height3 /*stack 52*/, long startColor /*stack 56*/, long endColor /*stack 60*/, int pred_offset /*stack 64*/, int lifeTime /*stack 68*/, int sortInWorld /*stack 72*/)
 // line 6067, offset 0x8004c3d0
	/* begin block 1 */
		// Start line: 6068
		// Start offset: 0x8004C3D0
		// Variables:
	// 		struct _FXBlastringEffect *blast; // $s0
	/* end block 1 */
	// End offset: 0x8004C570
	// End Line: 6106

	/* begin block 2 */
		// Start line: 14879
	/* end block 2 */
	// End Line: 14880

/* File: C:\kain2\game\FX.C */

_FXBlastringEffect *
FX_DoBlastRing(_Instance *instance,_SVector *position,undefined mat,int segment,int radius,
              int endRadius,int colorChangeRadius,int size1,int size2,int vel,int accl,int height1,
              int height2,int height3,long startColor,long endColor,int pred_offset,int lifeTime,
              int sortInWorld)

{
  _FXBlastringEffect *ptr;
  undefined3 in_register_00000019;
  undefined4 *puVar1;
  undefined4 uVar2;
  long lVar3;
  undefined4 uVar4;
  long lVar5;
  undefined4 uVar6;
  long lVar7;
  
  puVar1 = (undefined4 *)CONCAT31(in_register_00000019,mat);
  ptr = (_FXBlastringEffect *)MEMPACK_Malloc(0x78,'\r');
  if (ptr != (_FXBlastringEffect *)0x0) {
    *(code **)&ptr->continue_process = FX_ContinueBlastRing;
    ptr->instance = instance;
    ptr->effectType = -0x7c;
    if (pred_offset == 0) {
      ptr->type = '\0';
    }
    else {
      ptr->type = '\x01';
    }
    ptr->predator_offset = (short)pred_offset;
    ptr->lifeTime = (short)lifeTime;
    uVar2 = *(undefined4 *)&position->z;
    *(undefined4 *)&ptr->position = *(undefined4 *)position;
    *(undefined4 *)&(ptr->position).z = uVar2;
    if (puVar1 != (undefined4 *)0x0) {
      uVar2 = puVar1[1];
      uVar4 = puVar1[2];
      uVar6 = puVar1[3];
      *(undefined4 *)(ptr->matrix).m = *puVar1;
      *(undefined4 *)((ptr->matrix).m + 2) = uVar2;
      *(undefined4 *)((ptr->matrix).m + 4) = uVar4;
      *(undefined4 *)((ptr->matrix).m + 6) = uVar6;
      lVar3 = puVar1[5];
      lVar5 = puVar1[6];
      lVar7 = puVar1[7];
      *(undefined4 *)((ptr->matrix).m + 8) = puVar1[4];
      (ptr->matrix).t[0] = lVar3;
      (ptr->matrix).t[1] = lVar5;
      (ptr->matrix).t[2] = lVar7;
    }
    ptr->segment = (short)segment;
    ptr->radius = radius << 0xc;
    ptr->startRadius = radius << 0xc;
    ptr->size1 = size1;
    ptr->size2 = size2;
    ptr->endRadius = endRadius << 0xc;
    ptr->colorchange_radius = colorChangeRadius << 0xc;
    ptr->vel = vel;
    ptr->accl = accl;
    ptr->height1 = height1;
    ptr->height2 = height2;
    ptr->color = startColor;
    ptr->startColor = startColor;
    ptr->height3 = height3;
    ptr->endColor = endColor;
    ptr->sortInWorld = (short)sortInWorld;
    FX_InsertGeneralEffect(ptr);
  }
  return ptr;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawBlastring(struct MATRIX *wcTransform /*$s3*/, struct _FXBlastringEffect *blast /*$s1*/)
 // line 6109, offset 0x8004c59c
	/* begin block 1 */
		// Start line: 6110
		// Start offset: 0x8004C59C
		// Variables:
	// 		int radius; // $s2
	// 		struct _SVector position; // stack offset -64
	// 		struct MATRIX mat; // stack offset -56

		/* begin block 1.1 */
			// Start line: 6117
			// Start offset: 0x8004C5DC
			// Variables:
		// 		struct MATRIX *swtransform; // $s0
		/* end block 1.1 */
		// End offset: 0x8004C5F4
		// End Line: 6121
	/* end block 1 */
	// End offset: 0x8004C73C
	// End Line: 6144

	/* begin block 2 */
		// Start line: 14972
	/* end block 2 */
	// End Line: 14973

/* WARNING: Could not reconcile some variable overlaps */
/* File: C:\kain2\game\FX.C */

void FX_DrawBlastring(undefined wcTransform,_FXBlastringEffect *blast)

{
  int radius;
  MATRIX *m1;
  undefined3 in_register_00000011;
  undefined4 local_40;
  undefined4 local_3c;
  MATRIX MStack56;
  
  radius = blast->radius;
  if (radius < 0) {
    radius = radius + 0xfff;
  }
  radius = radius >> 0xc;
  if ((int)blast->segment < 0) {
    CompMatrix((MATRIX *)CONCAT31(in_register_00000011,wcTransform),&blast->matrix,&MStack56);
    local_40 = *(undefined4 *)&blast->position;
    local_3c = *(undefined4 *)&(blast->position).z;
  }
  else {
    m1 = blast->instance->matrix;
    if (m1 == (MATRIX *)0x0) {
      return;
    }
    m1 = m1 + (int)blast->segment;
    CompMatrix((MATRIX *)CONCAT31(in_register_00000011,wcTransform),m1,&MStack56);
    local_40 = CONCAT22(*(undefined2 *)(m1->t + 1),*(undefined2 *)m1->t);
    local_3c = CONCAT22(local_3c._2_2_,*(undefined2 *)(m1->t + 2));
  }
  if (blast->type == '\0') {
    FX_DrawRing(wcTransform,(_SVector *)&local_40,200,radius,radius + blast->size1,
                radius + blast->size2,blast->height1,blast->height2,blast->height3,blast->color,
                (int)blast->sortInWorld);
  }
  else {
    if (blast->type == '\x01') {
      FX_DrawRing2(wcTransform,&blast->position,200,radius,radius + blast->size1,
                   radius + blast->size2,blast->height1,blast->height2,blast->height3,
                   (int)blast->predator_offset,(int)blast->sortInWorld);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueFlash(struct _FXFlash *flash /*$a0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 6147, offset 0x8004c758
	/* begin block 1 */
		// Start line: 15048
	/* end block 1 */
	// End Line: 15049

/* File: C:\kain2\game\FX.C */

void FX_ContinueFlash(_FXFlash *flash,_FXTracker *fxTracker)

{
  int iVar1;
  
  iVar1 = flash->currentTime + DAT_800d2314;
  flash->currentTime = iVar1;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xf;
  }
  if (flash->timeFromColor <= iVar1 >> 4) {
    FX_DeleteGeneralEffect((_FXGeneralEffect *)flash);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawFlash(struct _FXFlash *flash /*$a0*/)
 // line 6157, offset 0x8004c7a8
	/* begin block 1 */
		// Start line: 6158
		// Start offset: 0x8004C7A8
		// Variables:
	// 		int time; // $a1
	// 		int div; // $a2
	// 		int transtype; // $s0
	// 		int interp; // $a3
	// 		unsigned long color; // stack offset -16
	// 		unsigned long black; // stack offset -12
	/* end block 1 */
	// End offset: 0x8004C89C
	// End Line: 6188

	/* begin block 2 */
		// Start line: 15068
	/* end block 2 */
	// End Line: 15069

/* File: C:\kain2\game\FX.C */

void FX_DrawFlash(_FXFlash *flash)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  long p1;
  int transtype;
  long p0;
  ulong local_10;
  undefined4 local_c;
  
  iVar2 = flash->currentTime;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xf;
  }
  iVar2 = iVar2 >> 4;
  local_10 = flash->color;
  local_c = 0;
  transtype = 1;
  if ((local_10 & 0x1000000) != 0) {
    transtype = 2;
  }
  if (iVar2 < flash->timeToColor) {
    p0 = (iVar2 << 0xc) / flash->timeToColor;
    if (0x1000 < p0) {
      p0 = 0x1000;
    }
    p1 = 0x1000 - p0;
  }
  else {
    iVar3 = flash->timeAtColor;
    if (iVar2 <= iVar3) goto LAB_8004c89c;
    iVar4 = flash->timeFromColor - iVar3;
    if (iVar4 == 0) {
      p1 = 0x1000;
      bVar1 = true;
    }
    else {
      p1 = ((iVar2 - iVar3) * 0x1000) / iVar4;
      bVar1 = p1 < 0x1001;
    }
    if (!bVar1) {
      p1 = 0x1000;
    }
    p0 = 0x1000 - p1;
  }
  LoadAverageCol((u_char *)&local_10,(u_char *)&local_c,p0,p1,(u_char *)&local_10);
LAB_8004c89c:
  FX_DrawScreenPoly(transtype,local_10,5);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_RelocateGeneric(struct Object *object /*$a0*/, long offset /*$a1*/)
 // line 6191, offset 0x8004c8bc
	/* begin block 1 */
		// Start line: 6193
		// Start offset: 0x8004C8BC
		// Variables:
	// 		struct GenericFXObject *GFXO; // $v0
	/* end block 1 */
	// End offset: 0x8004C950
	// End Line: 6202

	/* begin block 2 */
		// Start line: 15139
	/* end block 2 */
	// End Line: 15140

	/* begin block 3 */
		// Start line: 15140
	/* end block 3 */
	// End Line: 15141

	/* begin block 4 */
		// Start line: 15142
	/* end block 4 */
	// End Line: 15143

/* File: C:\kain2\game\FX.C */

void FX_RelocateGeneric(Object *object,long offset)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)object->data;
  iVar2 = 0;
  if (*piVar1 != 0) {
    iVar2 = *piVar1 + offset;
  }
  iVar3 = 0;
  *piVar1 = iVar2;
  if (piVar1[1] != 0) {
    iVar3 = piVar1[1] + offset;
  }
  iVar2 = 0;
  piVar1[1] = iVar3;
  if (piVar1[2] != 0) {
    iVar2 = piVar1[2] + offset;
  }
  iVar3 = 0;
  piVar1[2] = iVar2;
  if (piVar1[3] != 0) {
    iVar3 = piVar1[3] + offset;
  }
  iVar2 = 0;
  piVar1[3] = iVar3;
  if (piVar1[4] != 0) {
    iVar2 = piVar1[4] + offset;
  }
  iVar3 = 0;
  piVar1[4] = iVar2;
  if (piVar1[5] != 0) {
    iVar3 = piVar1[5] + offset;
  }
  iVar2 = 0;
  piVar1[5] = iVar3;
  if (piVar1[6] != 0) {
    iVar2 = piVar1[6] + offset;
  }
  piVar1[6] = iVar2;
  return;
}



// decompiled code
// original method signature: 
// struct _FXParticle * /*$ra*/ FX_StartGenericParticle(struct _Instance *instance /*$a0*/, int num /*$a1*/, int segOverride /*$s3*/, int lifeOverride /*$s4*/, int InitFlag /*stack 16*/)
 // line 6205, offset 0x8004c958
	/* begin block 1 */
		// Start line: 6206
		// Start offset: 0x8004C958
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	// 		struct GenericFXObject *GFXO; // $v1
	// 		struct _GenericParticleParams *GPP; // $s1
	// 		struct Object *texture_obj; // $s2
	// 		struct Object *particle; // $a2

		/* begin block 1.1 */
			// Start line: 6271
			// Start offset: 0x8004CBB8
			// Variables:
		// 		struct TextureMT3 *texture; // $v0
		/* end block 1.1 */
		// End offset: 0x8004CBE0
		// End Line: 6275
	/* end block 1 */
	// End offset: 0x8004CC44
	// End Line: 6286

	/* begin block 2 */
		// Start line: 15167
	/* end block 2 */
	// End Line: 15168

/* File: C:\kain2\game\FX.C */

_FXParticle *
FX_StartGenericParticle(_Instance *instance,int num,int segOverride,int lifeOverride,int InitFlag)

{
  short sVar1;
  _FXParticle *ptr;
  TextureMT3 *pTVar2;
  short *psVar3;
  Object *object;
  
  object = (Object *)0x0;
  if ((objectAccess[10].object == (void *)0x0) ||
     ((psVar3 = (short *)(**(int **)((int)objectAccess[10].object + 0x1c) + num * 0x30),
      InitFlag != 0 && (*(char *)(psVar3 + 1) == '\0')))) {
    ptr = (_FXParticle *)0x0;
  }
  else {
    if ((*(char *)((int)psVar3 + 0x1f) != '\0') &&
       (instance = instance->LinkChild, instance == (_Instance *)0x0)) {
      return (_FXParticle *)0x0;
    }
    if (*(char *)((int)psVar3 + 0x1b) != -1) {
      object = (Object *)objectAccess[10].object;
      if (*(char *)((int)psVar3 + 0x13) != '\0') {
        object = instance->object;
      }
      if (object == (Object *)0x0) {
        return (_FXParticle *)0x0;
      }
    }
    ptr = FX_GetParticle(instance,0);
    if (ptr != (_FXParticle *)0x0) {
      ptr->numberBirthParticles = *(char *)(psVar3 + 0x12);
      ptr->size = *psVar3;
      ptr->type = *(uchar *)((int)psVar3 + 3);
      ptr->birthRadius = psVar3[2];
      if (segOverride == 0) {
        ptr->startSegment = *(char *)(psVar3 + 3);
      }
      else {
        ptr->startSegment = (char)segOverride;
      }
      ptr->endSegment = *(char *)((int)psVar3 + 7);
      sVar1 = psVar3[6];
      *(undefined4 *)&ptr->direction = *(undefined4 *)(psVar3 + 4);
      (ptr->direction).z = sVar1;
      (ptr->acceleration).x = (short)*(char *)(psVar3 + 8);
      (ptr->acceleration).y = (short)*(char *)((int)psVar3 + 0x11);
      (ptr->acceleration).z = (short)*(char *)(psVar3 + 9);
      ptr->startColor = *(uint *)(psVar3 + 10) & 0xffffff;
      ptr->endColor = *(uint *)(psVar3 + 0xc) & 0xffffff;
      if (lifeOverride == 0) {
        ptr->lifeTime = psVar3[0xe];
      }
      else {
        ptr->lifeTime = (short)lifeOverride;
      }
      ptr->primLifeTime = (ushort)*(byte *)(psVar3 + 0xf);
      ptr->startFadeValue = psVar3[0x10];
      ptr->startScale = psVar3[0x17];
      ptr->scaleSpeed = psVar3[0x13];
      (ptr->offset).x = psVar3[0x14];
      (ptr->offset).y = psVar3[0x15];
      (ptr->offset).z = psVar3[0x16];
      ptr->z_undulate = *(char *)((int)psVar3 + 0x25);
      if ((psVar3[0x11] == -1) && (*(char *)(psVar3 + 0xf) != '\0')) {
        ptr->fadeStep =
             (short)((0x1000 - (int)ptr->startFadeValue) / (int)(uint)*(byte *)(psVar3 + 0xf));
      }
      else {
        ptr->fadeStep = psVar3[0x11];
      }
      if ((int)*(char *)((int)psVar3 + 0x1b) != -1) {
        pTVar2 = FX_GetTextureObject(object,(int)*(char *)((int)psVar3 + 0x17),
                                     (int)*(char *)((int)psVar3 + 0x1b));
        ptr->texture = pTVar2;
        ptr->startColor = ptr->startColor | pTVar2->color & 0x3000000U;
      }
      if (*(char *)((int)psVar3 + 3) == '\x01') {
        *(code **)&ptr->fxprim_process = FX_AttachedParticlePrimProcess;
      }
      if (*(char *)(psVar3 + 7) != '\0') {
        ptr->flag_bits = ptr->flag_bits | 1;
      }
      if (*(char *)((int)psVar3 + 0xf) != '\0') {
        ptr->flag_bits = ptr->flag_bits | 2;
      }
      FX_InsertGeneralEffect(ptr);
    }
  }
  return ptr;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartGenericRibbon(struct _Instance *instance /*$a0*/, int num /*$a1*/, int segOverride /*$a2*/, int endOverride /*$a3*/, int InitFlag /*stack 16*/)
 // line 6288, offset 0x8004cc64
	/* begin block 1 */
		// Start line: 6289
		// Start offset: 0x8004CC64
		// Variables:
	// 		struct Object *particle; // $v1
	// 		struct GenericFXObject *GFXO; // $v1
	// 		struct _GenericRibbonParams *GRP; // $v1
	/* end block 1 */
	// End offset: 0x8004CD10
	// End Line: 6324

	/* begin block 2 */
		// Start line: 15347
	/* end block 2 */
	// End Line: 15348

/* File: C:\kain2\game\FX.C */

void FX_StartGenericRibbon(_Instance *instance,int num,int segOverride,int endOverride,int InitFlag)

{
  int iVar1;
  
  if (((objectAccess[10].object != (void *)0x0) &&
      ((iVar1 = *(int *)(*(int *)((int)objectAccess[10].object + 0x1c) + 4) + num * 0x14,
       *(char *)(iVar1 + 5) == '\0' ||
       (instance = instance->LinkChild, instance != (_Instance *)0x0)))) &&
     ((InitFlag == 0 || (*(char *)(iVar1 + 1) != '\0')))) {
    FX_StartRibbon(instance,(short)*(char *)(iVar1 + 2),(short)*(char *)(iVar1 + 3),
                   (short)*(char *)(iVar1 + 4),(int)*(short *)(iVar1 + 6),(int)*(short *)(iVar1 + 8)
                   ,(int)*(short *)(iVar1 + 10),*(long *)(iVar1 + 0xc),*(long *)(iVar1 + 0x10));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartGenericGlow(struct _Instance *instance /*$a0*/, int num /*$a1*/, int segOverride /*$t0*/, int seg2Override /*$a3*/, int InitFlag /*stack 16*/)
 // line 6326, offset 0x8004cd20
	/* begin block 1 */
		// Start line: 6327
		// Start offset: 0x8004CD20
		// Variables:
	// 		struct Object *particle; // $v1
	// 		struct GenericFXObject *GFXO; // $t1
	// 		struct _GenericGlowParams *GGP; // $s0
	// 		struct _FXGlowEffect *glowEffect; // $a0
	// 		long *color; // $v1

		/* begin block 1.1 */
			// Start line: 6354
			// Start offset: 0x8004CDAC
			// Variables:
		// 		int seg; // $a1
		/* end block 1.1 */
		// End offset: 0x8004CDB8
		// End Line: 6356

		/* begin block 1.2 */
			// Start line: 6360
			// Start offset: 0x8004CDF0
			// Variables:
		// 		int seg; // $a1
		// 		int segEnd; // $a2
		/* end block 1.2 */
		// End offset: 0x8004CE10
		// End Line: 6371

		/* begin block 1.3 */
			// Start line: 6375
			// Start offset: 0x8004CE40
			// Variables:
		// 		int seg; // $a1
		// 		int numSeg; // $a2
		/* end block 1.3 */
		// End offset: 0x8004CE88
		// End Line: 6394
	/* end block 1 */
	// End offset: 0x8004CEB8
	// End Line: 6401

	/* begin block 2 */
		// Start line: 15430
	/* end block 2 */
	// End Line: 15431

/* File: C:\kain2\game\FX.C */

void FX_StartGenericGlow(_Instance *instance,int num,int segOverride,int seg2Override,int InitFlag)

{
  _FXGlowEffect *glowEffect;
  long *color;
  int iVar1;
  char *pcVar2;
  
  if (objectAccess[10].object != (void *)0x0) {
    pcVar2 = (char *)(*(int *)(*(int *)((int)objectAccess[10].object + 0x1c) + 8) + num * 0x18);
    if (((InitFlag == 0) || (*pcVar2 != '\0')) &&
       ((pcVar2[5] == '\0' || (instance = instance->LinkChild, instance != (_Instance *)0x0)))) {
      iVar1 = (int)pcVar2[3];
      color = (long *)(*(int *)(*(int *)((int)objectAccess[10].object + 0x1c) + 0x18) +
                      (uint)(byte)pcVar2[4] * 4);
      if (iVar1 < 2) {
        if (segOverride == 0) {
          segOverride = ZEXT14((byte)pcVar2[1]);
        }
        glowEffect = FX_DoInstanceOneSegmentGlow
                               (instance,segOverride,color,(uint)(byte)pcVar2[6],
                                *(long *)(pcVar2 + 8),(int)*(short *)(pcVar2 + 0xc),
                                (int)*(short *)(pcVar2 + 0xe));
      }
      else {
        if (iVar1 == 2) {
          if ((segOverride == 0) && (seg2Override == 0)) {
            segOverride = ZEXT14((byte)pcVar2[1]);
            seg2Override = ZEXT14((byte)pcVar2[2]);
          }
          glowEffect = FX_DoInstanceTwoSegmentGlow
                                 (instance,segOverride,seg2Override,color,(uint)(byte)pcVar2[6],
                                  *(long *)(pcVar2 + 8),(int)*(short *)(pcVar2 + 0xc));
        }
        else {
          if ((segOverride == 0) && (seg2Override == 0)) {
            segOverride = ZEXT14((byte)pcVar2[1]);
            seg2Override = iVar1;
          }
          glowEffect = FX_DoInstanceManySegmentGlow
                                 (instance,segOverride,seg2Override,color,(uint)(byte)pcVar2[6],
                                  *(long *)(pcVar2 + 8),(int)*(short *)(pcVar2 + 0xc));
        }
      }
      if ((glowEffect != (_FXGlowEffect *)0x0) && (0 < *(int *)(pcVar2 + 0x10))) {
        glowEffect->lifeTime = (short)*(int *)(pcVar2 + 0x10) * 0x21;
        FX_SetGlowFades(glowEffect,(int)*(short *)(pcVar2 + 0x14),(int)*(short *)(pcVar2 + 0x16));
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// struct _FXLightning * /*$ra*/ FX_CreateLightning(struct _Instance *instance /*$s1*/, int lifeTime /*$s2*/, int deg /*$s3*/, int deg_inc /*$s4*/, int width /*stack 16*/, int small_width /*stack 20*/, int segs /*stack 24*/, int sine_size /*stack 28*/, int variation /*stack 32*/, unsigned long color /*stack 36*/, unsigned long glow_color /*stack 40*/)
 // line 6421, offset 0x8004cec8
	/* begin block 1 */
		// Start line: 6422
		// Start offset: 0x8004CEC8
		// Variables:
	// 		struct _FXLightning *zap; // $s0
	/* end block 1 */
	// End offset: 0x8004CFAC
	// End Line: 6457

	/* begin block 2 */
		// Start line: 15630
	/* end block 2 */
	// End Line: 15631

/* File: C:\kain2\game\FX.C */

_FXLightning *
FX_CreateLightning(_Instance *instance,int lifeTime,int deg,int deg_inc,int width,int small_width,
                  int segs,int sine_size,int variation,ulong color,ulong glow_color)

{
  _FXLightning *ptr;
  
  ptr = (_FXLightning *)MEMPACK_Malloc(0x3c,'\r');
  if (ptr != (_FXLightning *)0x0) {
    *(code **)&ptr->continue_process = FX_ContinueLightning;
    ptr->instance = instance;
    ptr->end_instance = instance;
    ptr->effectType = -0x79;
    ptr->type = '\0';
    ptr->lifeTime = (short)lifeTime;
    ptr->deg = (short)deg;
    ptr->deg_inc = (short)deg_inc;
    ptr->width = (short)width;
    ptr->small_width = (short)small_width;
    ptr->segs = (short)segs;
    ptr->sine_size = (short)sine_size;
    ptr->variation = (short)variation;
    ptr->color = color;
    (ptr->start_offset).x = 0;
    (ptr->start_offset).y = 0;
    (ptr->start_offset).z = 0;
    (ptr->end_offset).x = 0;
    (ptr->end_offset).y = 0;
    (ptr->end_offset).z = 0;
    ptr->glow_color = glow_color;
    ptr->matrixSeg = -1;
    FX_InsertGeneralEffect(ptr);
  }
  return ptr;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SetLightingPos(struct _FXLightning *zap /*$a0*/, struct _Instance *startInstance /*$a1*/, int startSeg /*$a2*/, struct _Position *startOffset /*$a3*/, struct _Instance *endInstance /*stack 16*/, int endSeg /*stack 20*/, struct _Position *endOffset /*stack 24*/, int matrixSeg /*stack 28*/)
 // line 6478, offset 0x8004cfd0
	/* begin block 1 */
		// Start line: 15756
	/* end block 1 */
	// End Line: 15757

/* File: C:\kain2\game\FX.C */

void FX_SetLightingPos(_FXLightning *zap,_Instance *startInstance,int startSeg,
                      _Position *startOffset,_Instance *endInstance,int endSeg,_Position *endOffset,
                      int matrixSeg)

{
  short sVar1;
  
  if (zap == (_FXLightning *)0x0) {
    return;
  }
  if (startInstance != (_Instance *)0x0) {
    if (endInstance == (_Instance *)0x0) {
      zap->type = '\x01';
      zap->instance = startInstance;
    }
    else {
      zap->type = '\0';
      zap->instance = startInstance;
      zap->end_instance = endInstance;
    }
    if (startInstance != (_Instance *)0x0) goto LAB_8004d01c;
  }
  if (endInstance == (_Instance *)0x0) {
    zap->type = '\x02';
  }
LAB_8004d01c:
  if (startOffset != (_Position *)0x0) {
    sVar1 = startOffset->z;
    *(undefined4 *)&zap->start_offset = *(undefined4 *)startOffset;
    (zap->start_offset).z = sVar1;
  }
  if (endOffset != (_Position *)0x0) {
    sVar1 = endOffset->z;
    *(undefined4 *)&zap->end_offset = *(undefined4 *)endOffset;
    (zap->end_offset).z = sVar1;
  }
  zap->startSeg = (short)startSeg;
  zap->endSeg = (short)endSeg;
  zap->matrixSeg = (short)matrixSeg;
  return;
}



// decompiled code
// original method signature: 
// struct _FXLightning * /*$ra*/ FX_StartGenericLightning(struct _Instance *instance /*$s2*/, int num /*$a1*/, int segOverride /*$s3*/, int endSegOverride /*$s4*/)
 // line 6507, offset 0x8004d080
	/* begin block 1 */
		// Start line: 6508
		// Start offset: 0x8004D080
		// Variables:
	// 		struct _FXLightning *zap; // $s1
	// 		struct GenericFXObject *GFXO; // $v1
	// 		struct _GenericLightningParams *GLP; // $s0
	// 		struct Object *particle; // $v1

		/* begin block 1.1 */
			// Start line: 6534
			// Start offset: 0x8004D174
			// Variables:
		// 		int startSeg; // $a2
		// 		int endSeg; // $a3
		/* end block 1.1 */
		// End offset: 0x8004D1BC
		// End Line: 6557
	/* end block 1 */
	// End offset: 0x8004D1C0
	// End Line: 6560

	/* begin block 2 */
		// Start line: 15814
	/* end block 2 */
	// End Line: 15815

	/* begin block 3 */
		// Start line: 15820
	/* end block 3 */
	// End Line: 15821

/* File: C:\kain2\game\FX.C */

_FXLightning *
FX_StartGenericLightning(_Instance *instance,int num,int segOverride,int endSegOverride)

{
  _FXLightning *zap;
  int iVar1;
  
  zap = (_FXLightning *)0x0;
  if (objectAccess[10].object != (void *)0x0) {
    iVar1 = *(int *)(*(int *)((int)objectAccess[10].object + 0x1c) + 0xc) + num * 0x28;
    if ((*(short *)(iVar1 + 2) == 0) ||
       ((*(char *)(iVar1 + 1) != '\0' &&
        (instance = instance->LinkChild, instance == (_Instance *)0x0)))) {
      zap = (_FXLightning *)0x0;
    }
    else {
      zap = FX_CreateLightning(instance,(int)*(short *)(iVar1 + 2),(int)*(short *)(iVar1 + 4),
                               (int)*(short *)(iVar1 + 6),(int)*(short *)(iVar1 + 0x18),
                               (int)*(short *)(iVar1 + 0x1a),(uint)*(byte *)(iVar1 + 0x17),
                               (int)*(short *)(iVar1 + 0x1c),(int)*(short *)(iVar1 + 0x1e),
                               *(ulong *)(iVar1 + 0x20),*(ulong *)(iVar1 + 0x24));
      if (zap != (_FXLightning *)0x0) {
        if (segOverride == 0) {
          segOverride = (int)*(char *)(iVar1 + 0xe);
        }
        if (endSegOverride == 0) {
          endSegOverride = (int)*(char *)(iVar1 + 0xf);
        }
        FX_SetLightingPos(zap,instance,segOverride,(_Position *)(iVar1 + 8),instance,endSegOverride,
                          (_Position *)(iVar1 + 0x10),(int)*(char *)(iVar1 + 0x16));
      }
    }
  }
  return zap;
}



// decompiled code
// original method signature: 
// struct _FXBlastringEffect * /*$ra*/ FX_StartGenericBlastring(struct _Instance *instance /*$s2*/, int num /*$a1*/, int segOverride /*$a2*/, int matrixSegOverride /*$a3*/)
 // line 6563, offset 0x8004d1e0
	/* begin block 1 */
		// Start line: 6564
		// Start offset: 0x8004D1E0
		// Variables:
	// 		struct GenericFXObject *GFXO; // $v1
	// 		struct _GenericBlastringParams *GBP; // $s0
	// 		struct Object *particle; // $v1
	// 		struct _SVector position; // stack offset -64
	// 		int segment; // $s1
	// 		int matrix_segment; // $s4
	// 		struct MATRIX mat; // stack offset -56
	// 		struct MATRIX *swTransform; // $a0
	/* end block 1 */
	// End offset: 0x8004D38C
	// End Line: 6618

	/* begin block 2 */
		// Start line: 15933
	/* end block 2 */
	// End Line: 15934

	/* begin block 3 */
		// Start line: 15944
	/* end block 3 */
	// End Line: 15945

/* File: C:\kain2\game\FX.C */

_FXBlastringEffect *
FX_StartGenericBlastring(_Instance *instance,int num,int segOverride,int matrixSegOverride)

{
  _FXBlastringEffect *p_Var1;
  MATRIX *pMVar2;
  int iVar3;
  _SVector local_40 [5];
  
  if ((objectAccess[10].object != (void *)0x0) &&
     ((iVar3 = *(int *)(*(int *)((int)objectAccess[10].object + 0x1c) + 0x10) + num * 0x30,
      *(char *)(iVar3 + 1) == '\0' || (instance = instance->LinkChild, instance != (_Instance *)0x0)
      ))) {
    if (segOverride == 0) {
      segOverride = (int)*(char *)(iVar3 + 0xc);
    }
    if (matrixSegOverride == 0) {
      matrixSegOverride = (int)*(short *)(iVar3 + 10);
    }
    MATH3D_SetUnityMatrix(200);
    if (instance->matrix != (MATRIX *)0x0) {
      pMVar2 = instance->matrix + segOverride;
      local_40[0].x = *(short *)pMVar2->t + *(short *)(iVar3 + 4);
      local_40[0].y = *(short *)(pMVar2->t + 1) + *(short *)(iVar3 + 6);
      local_40[0].z = *(short *)(pMVar2->t + 2) + *(short *)(iVar3 + 8);
      p_Var1 = FX_DoBlastRing(instance,local_40,200,matrixSegOverride,(int)*(short *)(iVar3 + 0xe),
                              (int)*(short *)(iVar3 + 0x14),(int)*(short *)(iVar3 + 0x16),
                              (int)*(short *)(iVar3 + 0x10),(int)*(short *)(iVar3 + 0x12),
                              *(int *)(iVar3 + 0x18) << 0xc,*(int *)(iVar3 + 0x1c),
                              (int)*(short *)(iVar3 + 0x20),(int)*(short *)(iVar3 + 0x22),
                              (int)*(short *)(iVar3 + 0x24),*(long *)(iVar3 + 0x28),
                              *(long *)(iVar3 + 0x2c),(int)*(short *)(iVar3 + 0x26),
                              (int)*(short *)(iVar3 + 2),(int)*(char *)(iVar3 + 0xd));
      return p_Var1;
    }
  }
  return (_FXBlastringEffect *)0x0;
}



// decompiled code
// original method signature: 
// struct _FXFlash * /*$ra*/ FX_StartGenericFlash(struct _Instance *instance /*$s2*/, int num /*$a1*/)
 // line 6620, offset 0x8004d3ac
	/* begin block 1 */
		// Start line: 6621
		// Start offset: 0x8004D3AC
		// Variables:
	// 		struct GenericFXObject *GFXO; // $v1
	// 		struct _GenericFlashParams *GFP; // $s1
	// 		struct Object *particle; // $v1
	// 		struct _FXFlash *flash; // $s0
	/* end block 1 */
	// End offset: 0x8004D474
	// End Line: 6652

	/* begin block 2 */
		// Start line: 16077
	/* end block 2 */
	// End Line: 16078

	/* begin block 3 */
		// Start line: 16083
	/* end block 3 */
	// End Line: 16084

/* File: C:\kain2\game\FX.C */

_FXFlash * FX_StartGenericFlash(_Instance *instance,int num)

{
  _FXFlash *ptr;
  long lVar1;
  int iVar2;
  int iVar3;
  
  if (objectAccess[10].object == (void *)0x0) {
    ptr = (_FXFlash *)0x0;
  }
  else {
    iVar3 = *(int *)(*(int *)((int)objectAccess[10].object + 0x1c) + 0x14) + num * 0xc;
    ptr = (_FXFlash *)MEMPACK_Malloc(0x24,'\r');
    if (ptr != (_FXFlash *)0x0) {
      *(code **)&ptr->continue_process = FX_ContinueFlash;
      ptr->effectType = -0x78;
      ptr->instance = instance;
      ptr->type = '\0';
      ptr->lifeTime = -1;
      lVar1 = *(long *)(iVar3 + 4);
      ptr->currentTime = 0;
      ptr->color = lVar1;
      iVar2 = (int)*(short *)(iVar3 + 2) * 0x100;
      ptr->timeToColor = iVar2;
      iVar2 = iVar2 + (int)*(short *)(iVar3 + 8) * 0x100;
      ptr->timeAtColor = iVar2;
      ptr->timeFromColor = iVar2 + (int)*(short *)(iVar3 + 10) * 0x100;
      FX_InsertGeneralEffect(ptr);
    }
  }
  return ptr;
}



// decompiled code
// original method signature: 
// long /*$ra*/ FX_GetHealthColor(int currentHealth /*$a0*/)
 // line 6654, offset 0x8004d48c
	/* begin block 1 */
		// Start line: 6675
		// Start offset: 0x8004D48C
		// Variables:
	// 		static long HealthColors[6]; // offset 0x0
	// 		long color; // $v1
	/* end block 1 */
	// End offset: 0x8004D4D0
	// End Line: 6692

	/* begin block 2 */
		// Start line: 16160
	/* end block 2 */
	// End Line: 16161

	/* begin block 3 */
		// Start line: 16180
	/* end block 3 */
	// End Line: 16181

	/* begin block 4 */
		// Start line: 16191
	/* end block 4 */
	// End Line: 16192

/* File: C:\kain2\game\FX.C */

long FX_GetHealthColor(int currentHealth)

{
  undefined *puVar1;
  
  puVar1 = DAT_800c90dc;
  if ((0 < currentHealth) && (puVar1 = PTR_DAT_800c90f0, (uint)currentHealth < 6)) {
    puVar1 = (undefined *)(&DAT_800c90dc)[currentHealth + -1];
  }
  return (uint)puVar1 & 0xfffcfcfc;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Start_Snow(int percent /*$a0*/)
 // line 6696, offset 0x8004d4e0
	/* begin block 1 */
		// Start line: 16244
	/* end block 1 */
	// End Line: 16245

	/* begin block 2 */
		// Start line: 16245
	/* end block 2 */
	// End Line: 16246

/* File: C:\kain2\game\FX.C */

void FX_Start_Snow(int percent)

{
  snow_amount = (short)((percent * 0x300) / 100);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Start_Rain(int percent /*$a0*/)
 // line 6701, offset 0x8004d514
	/* begin block 1 */
		// Start line: 16254
	/* end block 1 */
	// End Line: 16255

	/* begin block 2 */
		// Start line: 16255
	/* end block 2 */
	// End Line: 16256

/* File: C:\kain2\game\FX.C */

void FX_Start_Rain(int percent)

{
  rain_amount = (short)((percent << 10) / 100);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartLightbeam(struct _Instance *instance /*$s1*/, int startSeg /*$s2*/, int endSeg /*$s3*/, int color_num /*$a3*/)
 // line 6707, offset 0x8004d540
	/* begin block 1 */
		// Start line: 6708
		// Start offset: 0x8004D540
		// Variables:
	// 		struct Object *particle; // $v0
	// 		struct _FXLightBeam *beam; // $v0
	// 		struct GenericFXObject *GFXO; // $v0
	// 		long color; // $s0
	/* end block 1 */
	// End offset: 0x8004D5C8
	// End Line: 6732

	/* begin block 2 */
		// Start line: 16266
	/* end block 2 */
	// End Line: 16267

	/* begin block 3 */
		// Start line: 16272
	/* end block 3 */
	// End Line: 16273

/* File: C:\kain2\game\FX.C */

void FX_StartLightbeam(_Instance *instance,int startSeg,int endSeg,int color_num)

{
  char *ptr;
  undefined4 uVar1;
  
  if (objectAccess[10].object != (void *)0x0) {
    uVar1 = *(undefined4 *)
             (color_num * 4 + *(int *)(*(int *)((int)objectAccess[10].object + 0x1c) + 0x18));
    ptr = MEMPACK_Malloc(0x18,'\r');
    if (ptr != (char *)0x0) {
      ptr[0xc] = -0x7b;
      *(_Instance **)(ptr + 8) = instance;
      *(undefined4 *)(ptr + 4) = 0;
      ptr[0xd] = '\0';
      *(undefined2 *)(ptr + 0xe) = 0xffff;
      *(short *)(ptr + 0x10) = (short)startSeg;
      *(short *)(ptr + 0x12) = (short)endSeg;
      *(undefined4 *)(ptr + 0x14) = uVar1;
      FX_InsertGeneralEffect(ptr);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartInstanceEffect(struct _Instance *instance /*$s3*/, struct ObjectEffect *effect /*$s0*/, int InitFlag /*$s2*/)
 // line 6744, offset 0x8004d5e4
	/* begin block 1 */
		// Start line: 6745
		// Start offset: 0x8004D5E4
		// Variables:
	// 		long color; // stack offset -32

		/* begin block 1.1 */
			// Start line: 6778
			// Start offset: 0x8004D6BC
			// Variables:
		// 		long numberOfSegments; // $a2
		/* end block 1.1 */
		// End offset: 0x8004D708
		// End Line: 6798

		/* begin block 1.2 */
			// Start line: 6863
			// Start offset: 0x8004D7CC
			// Variables:
		// 		struct _FXParticle *currentParticle; // $a0
		// 		struct evObjectDraftData *draft; // $s1
		/* end block 1.2 */
		// End offset: 0x8004D804
		// End Line: 6872

		/* begin block 1.3 */
			// Start line: 6899
			// Start offset: 0x8004D8C8
			// Variables:
		// 		struct FXSplinter *splinterData; // $t0
		// 		struct GenericTune *tune; // $v1
		// 		short shardFlags; // $v0
		/* end block 1.3 */
		// End offset: 0x8004D924
		// End Line: 6912
	/* end block 1 */
	// End offset: 0x8004D924
	// End Line: 6918

	/* begin block 2 */
		// Start line: 16353
	/* end block 2 */
	// End Line: 16354

/* File: C:\kain2\game\FX.C */

void FX_StartInstanceEffect(_Instance *instance,ObjectEffect *effect,int InitFlag)

{
  ushort uVar1;
  short sVar2;
  ulong uVar3;
  _FXParticle *p_Var4;
  uint *puVar5;
  uint numSegments;
  FXSplinter *splintDef;
  undefined *local_20 [2];
  
  local_20[0] = &DAT_00004080;
  switch(effect->effectNumber) {
  case '\x01':
    FX_TorchFlame(instance,(ushort)effect->modifierList[0]);
    break;
  case '\x02':
    if ((uint)effect->modifierList[1] - 1 < 5) {
      local_20[0] = (undefined *)FX_ColorArray[effect->modifierList[1]];
    }
    FX_DoInstanceOneSegmentGlow
              (instance,(uint)effect->modifierList[0],(long *)local_20,1,0x400,0x32,100);
    break;
  case '\x03':
    numSegments = (uint)effect->modifierList[1];
    if (effect->modifierList[1] == 0) {
      numSegments = 1;
    }
    if ((uint)effect->modifierList[2] - 1 < 5) {
      local_20[0] = (undefined *)FX_ColorArray[effect->modifierList[2]];
    }
    FX_DoInstanceManySegmentGlow
              (instance,(uint)effect->modifierList[0],numSegments,(long *)local_20,1,0x400,0x41);
    break;
  case '\x05':
    FX_StartGenericParticle
              (instance,(uint)effect->modifierList[0],(uint)effect->modifierList[1],
               (uint)effect->modifierList[2],InitFlag);
    break;
  case '\x06':
    FX_StartGenericRibbon
              (instance,(uint)effect->modifierList[0],(uint)effect->modifierList[1],
               (uint)effect->modifierList[2],InitFlag);
    break;
  case '\a':
    FX_StartGenericGlow(instance,(uint)effect->modifierList[0],(uint)effect->modifierList[1],
                        (uint)effect->modifierList[2],InitFlag);
    break;
  case '\b':
    GlyphTrigger();
    break;
  case '\n':
    FX_Start_Snow((uint)effect->modifierList[0]);
    break;
  case '\v':
    FX_Start_Rain((uint)effect->modifierList[0]);
    break;
  case '\f':
    uVar3 = INSTANCE_Query(instance,0x16);
    if ((uVar3 != 0) &&
       (p_Var4 = FX_StartGenericParticle
                           (instance,(uint)effect->modifierList[0],(uint)effect->modifierList[1],
                            (uint)effect->modifierList[2],InitFlag), p_Var4 != (_FXParticle *)0x0))
    {
      (p_Var4->direction).x = *(short *)(uVar3 + 2);
      (p_Var4->direction).y = *(short *)(uVar3 + 4);
      (p_Var4->direction).z = *(short *)(uVar3 + 6);
      uVar1 = *(ushort *)(uVar3 + 8);
      p_Var4->birthRadius = 0;
      *(code **)&p_Var4->fxprim_modify_process = FX_UpdraftPrimModify;
      p_Var4->primLifeTime = uVar1 >> 3;
    }
    break;
  case '\r':
    FX_StartLightbeam(instance,(uint)effect->modifierList[0],(uint)effect->modifierList[1],
                      (uint)effect->modifierList[2]);
    break;
  case '\x0e':
    FX_StartGenericLightning
              (instance,(uint)effect->modifierList[0],(uint)effect->modifierList[1],
               (uint)effect->modifierList[2]);
    break;
  case '\x0f':
    if (InitFlag == 0) {
      FX_StartGenericBlastring
                (instance,(uint)effect->modifierList[0],(uint)effect->modifierList[1],
                 (uint)effect->modifierList[2]);
    }
    break;
  case '\x10':
    if (InitFlag == 0) {
      FX_StartGenericFlash(instance,(uint)effect->modifierList[0]);
    }
    break;
  case '\x11':
    splintDef = (FXSplinter *)0x0;
    if (InitFlag == 0) {
      puVar5 = (uint *)instance->object->data;
      sVar2 = 0;
      if (puVar5 != (uint *)0x0) {
        splintDef = (FXSplinter *)puVar5[1];
        sVar2 = (short)((*puVar5 & 2) << 3);
      }
      _FX_BuildSplinters(instance,0,0,0,splintDef,gFXT,(TDRFuncPtr__FX_BuildSplinters6fxSetup)0x0,
                         (TDRFuncPtr__FX_BuildSplinters7fxProcess)0x0,(int)sVar2);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_EndInstanceEffects(struct _Instance *instance /*$s1*/)
 // line 6922, offset 0x8004d940
	/* begin block 1 */
		// Start line: 6923
		// Start offset: 0x8004D940
		// Variables:
	// 		struct _FXGeneralEffect *currentEffect; // $a0
	// 		struct _FXGeneralEffect *nextEffect; // $s0
	/* end block 1 */
	// End offset: 0x8004D980
	// End Line: 6936

	/* begin block 2 */
		// Start line: 16729
	/* end block 2 */
	// End Line: 16730

/* File: C:\kain2\game\FX.C */

void FX_EndInstanceEffects(_Instance *instance)

{
  _FXGeneralEffect *effect;
  _FXGeneralEffect *p_Var1;
  
  effect = FX_GeneralEffectTracker;
  if (FX_GeneralEffectTracker != (_FXGeneralEffect *)0x0) {
    do {
      p_Var1 = (_FXGeneralEffect *)effect->next;
      if (effect->instance == instance) {
        FX_DeleteGeneralEffect(effect);
      }
      effect = p_Var1;
    } while (p_Var1 != (_FXGeneralEffect *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_GetSpiralPoint(int radius /*$s1*/, int deg /*$s0*/, int *x /*$s2*/, int *y /*$s3*/)
 // line 6946, offset 0x8004d994
	/* begin block 1 */
		// Start line: 6947
		// Start offset: 0x8004D994
		// Variables:
	// 		int prevx; // $a0
	// 		int prevy; // $v0
	/* end block 1 */
	// End offset: 0x8004DA40
	// End Line: 6961

	/* begin block 2 */
		// Start line: 16781
	/* end block 2 */
	// End Line: 16782

/* File: C:\kain2\game\FX.C */

void FX_GetSpiralPoint(int radius,int deg,int *x,int *y)

{
  int iVar1;
  
  iVar1 = rcos(deg);
  iVar1 = ((-radius * iVar1 >> 0xc) / 0xf0) * 0x200;
  if (iVar1 < 0) {
    iVar1 = iVar1 + -0x800;
  }
  else {
    iVar1 = iVar1 + 0x800;
  }
  *x = (iVar1 >> 0xc) + 0x1b6;
  iVar1 = rsin(deg);
  iVar1 = radius * iVar1 >> 0xc;
  if (iVar1 < 0) {
    iVar1 = iVar1 + -0x800;
  }
  else {
    iVar1 = iVar1 + 0x800;
  }
  *y = (iVar1 >> 0xc) + 0xc9;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_GetLinePoint(int radius /*$a0*/, int next_radius /*$s1*/, int deg /*$a2*/, int next_deg /*$s0*/, int *pntx /*stack 16*/, int *pnty /*stack 20*/, int part /*stack 24*/)
 // line 6990, offset 0x8004da68
	/* begin block 1 */
		// Start line: 6991
		// Start offset: 0x8004DA68
		// Variables:
	// 		int x1; // stack offset -32
	// 		int y1; // stack offset -28
	// 		int x2; // stack offset -24
	// 		int y2; // stack offset -20
	/* end block 1 */
	// End offset: 0x8004DB08
	// End Line: 6998

	/* begin block 2 */
		// Start line: 16873
	/* end block 2 */
	// End Line: 16874

/* File: C:\kain2\game\FX.C */

void FX_GetLinePoint(int radius,int next_radius,int deg,int next_deg,int *pntx,int *pnty,int part)

{
  int iVar1;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  FX_GetSpiralPoint(radius,deg,&local_20,&local_1c);
  FX_GetSpiralPoint(next_radius,next_deg,&local_18,&local_14);
  iVar1 = (local_18 - local_20) * part;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xfff;
  }
  *pntx = local_20 + (iVar1 >> 0xc);
  part = (local_14 - local_1c) * part;
  if (part < 0) {
    part = part + 0xfff;
  }
  *pnty = local_1c + (part >> 0xc);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_CalcSpiral(int degchange /*stack 0*/)
 // line 7002, offset 0x8004db34
	/* begin block 1 */
		// Start line: 7003
		// Start offset: 0x8004DB34
		// Variables:
	// 		int radius; // $s2
	// 		int deg; // $s1
	// 		int n; // $s3
	// 		int pntx; // stack offset -72
	// 		int pnty; // stack offset -68
	// 		int px; // stack offset -64
	// 		int py; // stack offset -60
	// 		int mx; // stack offset -56
	// 		int my; // stack offset -52
	// 		int mod; // $s0
	// 		int next_deg; // $s4
	// 		int next_radius; // $s5
	// 		int minx; // $s7
	// 		int maxx; // $s6
	// 		int miny; // stack offset -48
	// 		int maxy; // $fp
	/* end block 1 */
	// End offset: 0x8004DDD0
	// End Line: 7065

	/* begin block 2 */
		// Start line: 16900
	/* end block 2 */
	// End Line: 16901

/* WARNING: Could not reconcile some variable overlaps */
/* File: C:\kain2\game\FX.C */

void FX_CalcSpiral(int degchange)

{
  int deg;
  int radius;
  int iVar1;
  int part;
  int next_deg;
  int iVar2;
  int next_radius;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  iVar4 = 0x7fff;
  iVar3 = -0x7fff;
  iVar5 = -0x7fff;
  iVar2 = 0x2000;
  deg = 0;
  part = 0;
  local_30 = 0x7fff;
  FX_GetSpiralPoint(0x2000,0,&local_48,&local_44);
  Spiral_Array[64].vx = (short)local_48;
  Spiral_Array[64].vy = (short)local_44;
  next_deg = 0x2000;
  iVar1 = 0;
  do {
    if (Spiral_Number == 0) {
      radius = next_deg;
      next_deg = part;
      next_radius = iVar2;
      if (iVar1 % Spiral_Mod == 0) {
        next_radius = iVar2 + Spiral_Mod * 0x440;
        next_deg = part + degchange * Spiral_Mod;
        deg = part;
        radius = iVar2;
      }
      part = (iVar1 % Spiral_Mod << 0xc) / Spiral_Mod;
      FX_GetLinePoint(radius,next_radius,deg,next_deg,&local_48,&local_44,part);
      FX_GetLinePoint(radius + 0x1c00,next_radius + 0x1c00,deg,next_deg,&local_40,&local_3c,part);
      FX_GetLinePoint(radius + -0x1c00,next_radius + -0x1c00,deg,next_deg,&local_38,&local_34,part);
      part = next_deg;
      iVar2 = next_radius;
    }
    else {
      radius = next_deg + 0x440;
      deg = deg + degchange;
      FX_GetSpiralPoint(radius,deg,&local_48,&local_44);
      FX_GetSpiralPoint(next_deg + 0x2040,deg,&local_40,&local_3c);
      FX_GetSpiralPoint(next_deg + -0x17c0,deg,&local_38,&local_34);
    }
    Spiral_Array[iVar1].vx = (short)local_48;
    Spiral_Array[iVar1].vy = (short)local_44;
    if (iVar1 == 0x3f) {
      local_40 = local_48;
      local_3c = local_44;
      local_38 = local_48;
      local_34 = local_44;
    }
    Spiral_OffsetP[iVar1].vx = (short)local_40;
    Spiral_OffsetP[iVar1].vy = (short)local_3c;
    if (local_40 < iVar4) {
      iVar4 = local_40;
    }
    if (iVar3 < local_40) {
      iVar3 = local_40;
    }
    if (local_3c < local_30) {
      local_30 = local_3c;
    }
    if (iVar5 < local_3c) {
      iVar5 = local_3c;
    }
    next_radius = iVar1 + 1;
    Spiral_OffsetM[iVar1].vx = (short)local_38;
    Spiral_OffsetM[iVar1].vy = (short)local_34;
    next_deg = radius;
    iVar1 = next_radius;
  } while (next_radius < 0x40);
  deg = ((iVar3 - iVar4) / 2) * 0x140;
  if (deg < 0) {
    deg = deg + 0x1ff;
  }
  Spiral_Glow_X = (iVar4 + iVar3) / 2;
  Spiral_Glow_Y = (local_30 + iVar5) / 2;
  Spiral_Glow_Size = (deg >> 9) + 2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Spiral(struct _PrimPool *primPool /*stack 0*/, unsigned long **ot /*stack 4*/)
 // line 7085, offset 0x8004de38
	/* begin block 1 */
		// Start line: 7086
		// Start offset: 0x8004DE38
		// Variables:
	// 		struct _POLY_2G4 *poly; // $s2
	// 		long prev; // $s3
	// 		long offp; // $s7
	// 		long offm; // $s4
	// 		int n; // $s1
	// 		struct DR_TPAGE *drtpage; // $v0
	// 		int health; // $fp
	// 		int health_mod; // $t1
	// 		long no_color; // stack offset -76
	// 		long color; // stack offset -80
	// 		static short cnt; // offset 0x68
	// 		int current_cnt; // stack offset -72
	// 		int max64; // $a0
	// 		long SPIRAL_COLOR; // $t3
	// 		long SPIRAL_COLOR2; // $t2
	// 		long SPIRAL_COLOR3; // stack offset -68
	// 		long SPIRAL_COLOR_END; // $s5
	// 		long SPIRAL_NOCOLOR; // $a2

		/* begin block 1.1 */
			// Start line: 7222
			// Start offset: 0x8004E034
			// Variables:
		// 		int tmp; // $v1
		/* end block 1.1 */
		// End offset: 0x8004E090
		// End Line: 7236

		/* begin block 1.2 */
			// Start line: 7319
			// Start offset: 0x8004E1E0
			// Variables:
		// 		static short deg; // offset 0x6a
		// 		struct _Vector f1; // stack offset -96
		/* end block 1.2 */
		// End offset: 0x8004E234
		// End Line: 7334
	/* end block 1 */
	// End offset: 0x8004E234
	// End Line: 7340

	/* begin block 2 */
		// Start line: 17232
	/* end block 2 */
	// End Line: 17233

/* WARNING: Removing unreachable block (ram,0x8004e04c) */
/* File: C:\kain2\game\FX.C */

void FX_Spiral(_PrimPool *primPool,ulong **ot)

{
  short sVar1;
  uint angle;
  long lVar2;
  int p0;
  DVECTOR *v0;
  DVECTOR DVar3;
  DVECTOR DVar4;
  DVECTOR *pDVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  DVECTOR DVar9;
  DVECTOR DVar10;
  DVECTOR DVar11;
  DVECTOR DVar12;
  int iVar13;
  _Vector local_60;
  DVECTOR local_50;
  DVECTOR local_4c;
  int local_48;
  DVECTOR local_44;
  uint local_40;
  DVECTOR *local_38;
  int local_34;
  DVECTOR local_30;
  DVECTOR local_2c;
  
  if (((DAT_800d20d4 != 1000) && (DAT_800d20d6 == 0)) && (Spiral_Number != 0)) {
    FX_Health_Spiral(1,Spiral_Current,Spiral_Max);
  }
  DVar4 = (DVECTOR)0x3afcffd3;
  DVar3 = (DVECTOR)0x3adce0ba;
  DVar11 = (DVECTOR)0x3a483017;
  local_50 = (DVECTOR)0x3a002a15;
  local_44 = (DVECTOR)0x3abbc09d;
  if (Spiral_Number == 0) {
    if (Spiral_Current == Spiral_Max) {
      DAT_800cfddc = DAT_800cfddc + 1;
      if (0x50 < DAT_800cfddc) {
        DAT_800cfddc = 0;
      }
    }
    else {
      DVar4 = (DVECTOR)0x3a00ff00;
      DVar3 = (DVECTOR)0x3a00e000;
      local_44 = (DVECTOR)0x3a00bf00;
      DVar11 = (DVECTOR)0x3a004500;
    }
    local_50 = (DVECTOR)0x3a00150b;
  }
  else {
    DAT_800cfddc = DAT_800cfddc + 1;
    if (0x50 < DAT_800cfddc) {
      DAT_800cfddc = 0;
    }
  }
  lVar2 = Spiral_Max;
  if (Spiral_Max < 0) {
    lVar2 = Spiral_Max + 0x3f;
  }
  p0 = lVar2 >> 6;
  iVar13 = Spiral_Current / p0;
  puVar7 = primPool->nextPrim;
  p0 = ((Spiral_Current - iVar13 * p0) * 0x1000) / p0;
  if (puVar7 + 0x451 < primPool->lastPrim) {
    iVar6 = 0;
    v0 = &local_50;
    local_40 = (uint)DVar4 & 0xff000000;
    local_48 = (int)DAT_800cfddc;
    pDVar5 = (DVECTOR *)(puVar7 + 0x10);
    DVar9 = Spiral_Array[64];
    DVar10 = Spiral_Array[64];
    DVar12 = Spiral_Array[64];
    local_4c = local_50;
    do {
      puVar8 = puVar7;
      pDVar5[-0xb] = local_50;
      pDVar5[-7] = local_50;
      if (iVar13 < iVar6) {
        local_50 = local_4c;
      }
      else {
        angle = (int)(iVar6 + local_48 & 0xfU) >> 2;
        local_50 = DVar3;
        if (angle != 1) {
          if (angle < 2) {
LAB_8004e078:
            local_50 = DVar4;
          }
          else {
            if (angle == 2) {
              local_50 = local_44;
            }
            else {
              if (angle != 3) goto LAB_8004e078;
            }
          }
        }
      }
      if (iVar6 == iVar13) {
        local_38 = v0;
        local_34 = p0;
        local_30 = DVar3;
        local_2c = DVar4;
        LoadAverageCol((u_char *)v0,(u_char *)&local_4c,p0,0x1000 - p0,(u_char *)v0);
        local_50 = (DVECTOR)((uint)local_50 & 0xffffff | local_40);
        v0 = local_38;
        p0 = local_34;
        DVar3 = local_30;
        DVar4 = local_2c;
      }
      pDVar5[-0xf] = DVar11;
      pDVar5[-0xd] = DVar11;
      pDVar5[-3] = DVar11;
      pDVar5[-1] = DVar11;
      pDVar5[-6] = DVar9;
      pDVar5[-10] = DVar9;
      pDVar5[-0xe] = DVar12;
      pDVar5[-2] = DVar10;
      pDVar5[-9] = local_50;
      pDVar5[-5] = local_50;
      DVar9 = Spiral_Array[iVar6];
      DVar12 = Spiral_OffsetP[iVar6];
      DVar10 = Spiral_OffsetM[iVar6];
      iVar6 = iVar6 + 1;
      pDVar5[-4] = DVar9;
      pDVar5[-8] = DVar9;
      pDVar5[-0xc] = DVar12;
      *pDVar5 = DVar10;
      pDVar5 = pDVar5 + 0x11;
      *puVar8 = (uint)ot[1] & 0xffffff | 0x10000000;
      ot[1] = (ulong *)((uint)puVar8 & 0xffffff);
      puVar7 = puVar8 + 0x11;
    } while (iVar6 < 0x40);
    puVar8[0x12] = 0xe1000620;
    sVar1 = Spiral_Number;
    *puVar7 = (uint)ot[1] & 0xffffff | 0x1000000;
    ot[1] = (ulong *)((uint)puVar7 & 0xffffff);
    primPool->nextPrim = puVar8 + 0x13;
    if ((sVar1 != 0) || (Spiral_Current == Spiral_Max)) {
      local_60.y = Spiral_Glow_Y;
      angle = (uint)DAT_800cfdde - 0x20 & 0xfff;
      local_60.x = Spiral_Glow_X;
      DAT_800cfdde = (ushort)angle;
      DRAW_CreateAGlowingCircle
                (&local_60,0x140,DAT_800d210c,ot,5,0x8000,Spiral_Glow_Size,Spiral_Glow_Size,angle);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Health_Spiral(int number /*$a0*/, int current_health /*$s0*/, int max_health /*$s1*/)
 // line 7342, offset 0x8004e264
	/* begin block 1 */
		// Start line: 7343
		// Start offset: 0x8004E264
		// Variables:
	// 		int degchange; // $v1
	/* end block 1 */
	// End offset: 0x8004E39C
	// End Line: 7390

	/* begin block 2 */
		// Start line: 17969
	/* end block 2 */
	// End Line: 17970

/* File: C:\kain2\game\FX.C */

void FX_Health_Spiral(int number,int current_health,int max_health)

{
  bool bVar1;
  short sVar2;
  
  if (number == 0) {
    if (Spiral_Mod < 6) {
      Spiral_Number = 0;
      Spiral_Mod = Spiral_Mod + 1;
      FX_CalcSpiral(0x80);
      return;
    }
  }
  else {
    if (1 < Spiral_Mod) {
      Spiral_Mod = Spiral_Mod + -1;
      FX_CalcSpiral(0x80);
      return;
    }
  }
  switch(number) {
  default:
    sVar2 = 0x80;
    break;
  case 2:
    sVar2 = 0xa0;
    break;
  case 3:
    sVar2 = 0xc0;
    break;
  case 4:
    sVar2 = 0xe0;
  }
  if ((sVar2 == Spiral_Degrees) && ((int)Spiral_Number == number)) {
    Spiral_Current = current_health;
    Spiral_Max = max_health;
    return;
  }
  Spiral_Number = (short)number;
  if (Spiral_Degrees < sVar2) {
    bVar1 = sVar2 < (short)(Spiral_Degrees + 4);
    Spiral_Degrees = Spiral_Degrees + 4;
  }
  else {
    if (Spiral_Degrees <= sVar2) goto LAB_8004e388;
    bVar1 = (short)(Spiral_Degrees + -4) < sVar2;
    Spiral_Degrees = Spiral_Degrees + -4;
  }
  if (bVar1) {
    Spiral_Degrees = sVar2;
  }
LAB_8004e388:
  FX_CalcSpiral((int)Spiral_Degrees);
  Spiral_Current = current_health;
  Spiral_Max = max_health;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Spiral_Init()
 // line 7392, offset 0x8004e3b0
	/* begin block 1 */
		// Start line: 18069
	/* end block 1 */
	// End Line: 18070

/* File: C:\kain2\game\FX.C */

void FX_Spiral_Init(void)

{
  Spiral_Max = 100000;
  Spiral_Current = 100000;
  Spiral_Number = 1;
  Spiral_Degrees = 0x80;
  FX_CalcSpiral(0x80);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawModel(struct Object *object /*$s6*/, int model_num /*$s7*/, struct _SVector *rotation /*$s0*/, struct _SVector *position /*$s1*/, struct _SVector *offset /*stack 16*/, int transflag /*stack 20*/)
 // line 7421, offset 0x8004e3f0
	/* begin block 1 */
		// Start line: 7422
		// Start offset: 0x8004E3F0
		// Variables:
	// 		struct _Model *model; // $v0
	// 		struct _MFace *mface; // $t0
	// 		struct _MVertex *vertexList; // $t3
	// 		struct TextureMT3 *texture; // $a1
	// 		struct MATRIX matrix; // stack offset -88
	// 		int i; // $a3
	// 		struct POLY_GT3 *poly; // $s4
	// 		unsigned long **drawot; // $s5
	// 		struct _SVector output; // stack offset -56
	// 		long color; // $t1

		/* begin block 1.1 */
			// Start line: 7465
			// Start offset: 0x8004E51C
			// Variables:
		// 		long clip; // stack offset -48
		/* end block 1.1 */
		// End offset: 0x8004E614
		// End Line: 7493
	/* end block 1 */
	// End offset: 0x8004E63C
	// End Line: 7500

	/* begin block 2 */
		// Start line: 18130
	/* end block 2 */
	// End Line: 18131

	/* begin block 3 */
		// Start line: 18142
	/* end block 3 */
	// End Line: 18143

/* File: C:\kain2\game\FX.C */

void FX_DrawModel(Object *object,int model_num,_SVector *rotation,_SVector *position,
                 _SVector *offset,int transflag)

{
  uint uVar1;
  int iVar2;
  undefined4 in_zero;
  undefined4 in_at;
  _Model *p_Var3;
  _MVertex *p_Var4;
  _MVertex *p_Var5;
  _MVertex *p_Var6;
  uint *puVar7;
  ushort *puVar8;
  int iVar9;
  _MFace *p_Var10;
  uint uVar11;
  _MVertex *p_Var12;
  uint *puVar13;
  MATRIX MStack88;
  SVECTOR local_38;
  int local_30;
  
  iVar2 = DAT_800d22a4;
  puVar13 = *(uint **)(DAT_800d210c + 4);
  PushMatrix();
  MATH3D_SetUnityMatrix(0xa8);
  RotMatrixX((int)rotation->x,&MStack88);
  RotMatrixY((int)rotation->y,&MStack88);
  RotMatrixZ((int)rotation->z,&MStack88);
  PIPE3D_AspectAdjustMatrix(0xa8);
  ApplyMatrixSV(&MStack88,(SVECTOR *)offset,&local_38);
  MStack88.t[0] = (int)position->x + (int)local_38.vx;
  MStack88.t[1] = (int)position->y + (int)local_38.vy;
  MStack88.t[2] = (int)position->z + (int)local_38.vz;
  SetRotMatrix(&MStack88);
  SetTransMatrix(&MStack88);
  uVar11 = 0x34808080;
  if (transflag != 0) {
    uVar11 = 0x36404040;
  }
  if (object != (Object *)0x0) {
    p_Var3 = object->modelList[model_num];
    p_Var10 = p_Var3->faceList;
    p_Var12 = p_Var3->vertexList;
    iVar9 = p_Var3->numFaces + -1;
    if (iVar9 != -1) {
      puVar8 = &(p_Var10->face).v2;
      do {
        if (*(uint **)(DAT_800d210c + 8) <= puVar13 + 10) {
          *(uint **)(DAT_800d210c + 4) = puVar13;
          goto LAB_8004e634;
        }
        puVar7 = *(uint **)(puVar8 + 2);
        p_Var6 = p_Var12 + (p_Var10->face).v0;
        p_Var5 = p_Var12 + puVar8[-1];
        p_Var4 = p_Var12 + *puVar8;
        setCopReg(2,in_zero,*(undefined4 *)&p_Var6->vertex);
        setCopReg(2,in_at,*(undefined4 *)&(p_Var6->vertex).z);
        setCopReg(2,p_Var4,*(undefined4 *)&p_Var5->vertex);
        setCopReg(2,p_Var5,*(undefined4 *)&(p_Var5->vertex).z);
        setCopReg(2,p_Var6,*(undefined4 *)&p_Var4->vertex);
        setCopReg(2,puVar7,*(undefined4 *)&(p_Var4->vertex).z);
        copFunction(2,0x280030);
        puVar13[3] = *puVar7;
        puVar13[6] = puVar7[1];
        puVar13[9] = puVar7[2];
        copFunction(2,0x1400006);
        puVar13[7] = uVar11;
        puVar13[4] = uVar11;
        puVar13[1] = uVar11;
        local_30 = getCopReg(2,0x18);
        if (local_30 < 0) {
          uVar1 = getCopReg(2,0xc);
          puVar13[2] = uVar1;
          uVar1 = getCopReg(2,0xd);
          puVar13[5] = uVar1;
          uVar1 = getCopReg(2,0xe);
          puVar13[8] = uVar1;
          *puVar13 = *(uint *)(iVar2 + 4) & 0xffffff | 0x9000000;
          *(uint *)(iVar2 + 4) = (uint)puVar13 & 0xffffff;
          puVar13 = puVar13 + 10;
        }
        puVar8 = puVar8 + 6;
        iVar9 = iVar9 + -1;
        p_Var10 = p_Var10 + 1;
      } while (iVar9 != -1);
    }
  }
  *(uint **)(DAT_800d210c + 4) = puVar13;
LAB_8004e634:
  PopMatrix();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ fx_calc_points(struct _SVector *points /*$s1*/, int degrees /*$s0*/, int radius /*$s3*/, int radius2 /*$s4*/, int radius3 /*stack 16*/)
 // line 7514, offset 0x8004e668
	/* begin block 1 */
		// Start line: 7515
		// Start offset: 0x8004E668
		// Variables:
	// 		int cosval; // $s0
	// 		int sinval; // $v0
	/* end block 1 */
	// End offset: 0x8004E668
	// End Line: 7515

	/* begin block 2 */
		// Start line: 18346
	/* end block 2 */
	// End Line: 18347

/* File: C:\kain2\game\FX.C */

void fx_calc_points(_SVector *points,int degrees,int radius,int radius2,int radius3)

{
  undefined4 in_zero;
  undefined4 in_at;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = rcos(degrees);
  iVar2 = rsin(degrees);
  points->x = (short)(iVar1 * radius >> 0xc);
  points[1].x = (short)(iVar1 * radius2 >> 0xc);
  points->y = (short)(iVar2 * radius >> 0xc);
  points[1].y = (short)(iVar2 * radius2 >> 0xc);
  points[2].x = (short)(iVar1 * radius3 >> 0xc);
  iVar3 = iVar2 * radius3 >> 0xc;
  points[2].y = (short)iVar3;
  setCopReg(2,in_zero,*(undefined4 *)points);
  setCopReg(2,in_at,*(undefined4 *)&points->z);
  setCopReg(2,iVar3,*(undefined4 *)(points + 1));
  setCopReg(2,iVar2 * radius,*(undefined4 *)&points[1].z);
  setCopReg(2,iVar1 * radius2,*(undefined4 *)(points + 2));
  setCopReg(2,iVar2 * radius2,*(undefined4 *)&points[2].z);
  copFunction(2,0x280030);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ fx_get_startz(struct _SVector *position /*$a0*/)
 // line 7532, offset 0x8004e778
	/* begin block 1 */
		// Start line: 7533
		// Start offset: 0x8004E778
		// Variables:
	// 		struct MATRIX tmpmat; // stack offset -40
	/* end block 1 */
	// End offset: 0x8004E7C0
	// End Line: 7541

	/* begin block 2 */
		// Start line: 18389
	/* end block 2 */
	// End Line: 18390

/* File: C:\kain2\game\FX.C */

long fx_get_startz(_SVector *position)

{
  undefined4 in_zero;
  undefined4 in_at;
  MATRIX MStack40;
  
  setCopReg(2,in_zero,*(undefined4 *)position);
  setCopReg(2,in_at,*(undefined4 *)&position->z);
  copFunction(2,0x480012);
  MStack40.t[0] = getCopReg(2,0x19);
  MStack40.t[1] = getCopReg(2,0x1a);
  MStack40.t[2] = getCopReg(2,0x1b);
  SetTransMatrix(&MStack40);
  if (MStack40.t[2] < 0) {
    MStack40.t[2] = MStack40.t[2] + 3;
  }
  return MStack40.t[2] >> 2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawRing(struct MATRIX *wcTransform /*$s0*/, struct _SVector *position /*$s3*/, struct MATRIX *matrix /*$s4*/, int radius /*stack 12*/, int radius2 /*stack 16*/, int radius3 /*stack 20*/, int z1 /*stack 24*/, int z2 /*stack 28*/, int z3 /*stack 32*/, long color /*stack 36*/, int sortInWorld /*stack 40*/)
 // line 7544, offset 0x8004e7d0
	/* begin block 1 */
		// Start line: 7545
		// Start offset: 0x8004E7D0
		// Variables:
	// 		int n; // $s3
	// 		struct _POLY_2G4T *poly; // $s1
	// 		unsigned long **drawot; // stack offset -44
	// 		struct _SVector points[3]; // stack offset -96
	// 		long sxy[3]; // stack offset -72
	// 		long degrees; // $s6
	// 		long color_black; // $s4
	// 		long sz0; // stack offset -56
	// 		long sz1; // stack offset -52
	// 		long sz2; // stack offset -48
	// 		long startz; // $s7
	/* end block 1 */
	// End offset: 0x8004EA4C
	// End Line: 7621

	/* begin block 2 */
		// Start line: 18414
	/* end block 2 */
	// End Line: 18415

	/* begin block 3 */
		// Start line: 18424
	/* end block 3 */
	// End Line: 18425

/* File: C:\kain2\game\FX.C */

void FX_DrawRing(undefined wcTransform,_SVector *position,undefined matrix,int radius,int radius2,
                int radius3,int z1,int z2,int z3,long color,int sortInWorld)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  undefined3 in_register_00000011;
  uint *puVar4;
  undefined3 in_register_00000019;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  int degrees;
  _SVector _Stack96;
  undefined2 local_54;
  undefined2 local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  int local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  
  puVar6 = *(uint **)(DAT_800d210c + 4);
  local_2c = DAT_800d22a4;
  if (puVar6 + 0x240 < *(uint **)(DAT_800d210c + 8)) {
    PushMatrix();
    SetRotMatrix((MATRIX *)CONCAT31(in_register_00000011,wcTransform));
    SetTransMatrix((MATRIX *)CONCAT31(in_register_00000011,wcTransform));
    lVar1 = fx_get_startz(position);
    SetRotMatrix((MATRIX *)CONCAT31(in_register_00000019,matrix));
    _Stack96.z = (short)z1;
    local_54 = (undefined2)z2;
    local_4c = (undefined2)z3;
    fx_calc_points(&_Stack96,0,radius,radius2,radius3);
    uVar7 = color | 0x3a000000;
    local_48 = getCopReg(2,0xc);
    local_44 = getCopReg(2,0xd);
    local_40 = getCopReg(2,0xe);
    iVar8 = 0;
    puVar5 = puVar6 + 0x11;
    degrees = 0x80;
    do {
      fx_calc_points(&_Stack96,degrees,radius,radius2,radius3);
      puVar5[-1] = 0x3a000000;
      puVar5[-3] = 0x3a000000;
      puVar5[-0xd] = 0x3a000000;
      puVar5[-0xf] = 0x3a000000;
      puVar5[-9] = uVar7;
      puVar5[-0xb] = uVar7;
      puVar5[-5] = uVar7;
      puVar5[-7] = uVar7;
      puVar5[-0xe] = local_40;
      puVar5[-10] = local_44;
      puVar5[-6] = local_44;
      puVar5[-0x10] = 0xe1000620;
      puVar5[-2] = local_48;
      local_48 = getCopReg(2,0xc);
      local_44 = getCopReg(2,0xd);
      local_40 = getCopReg(2,0xe);
      local_38 = getCopReg(2,0x11);
      local_34 = getCopReg(2,0x12);
      local_30 = getCopReg(2,0x13);
      puVar5[-0xc] = local_40;
      puVar5[-8] = local_44;
      puVar5[-4] = local_44;
      *puVar5 = local_48;
      if (local_30 < local_38) {
        local_38 = local_30;
      }
      iVar2 = local_38 >> 2;
      if (0 < local_38) {
        local_38 = iVar2;
        if ((sortInWorld == 0) && (local_38 = lVar1 + 0x10, iVar2 <= lVar1)) {
          local_38 = 1;
        }
        if (local_38 - 1U < 0xbff) {
          puVar5 = puVar5 + 0x12;
          puVar4 = (uint *)(local_38 * 4 + local_2c);
          uVar3 = (uint)puVar6 & 0xffffff;
          *puVar6 = *puVar4 & 0xffffff | 0x11000000;
          puVar6 = puVar6 + 0x12;
          *puVar4 = uVar3;
        }
      }
      iVar8 = iVar8 + 1;
      degrees = degrees + 0x80;
    } while (iVar8 < 0x20);
    *(uint **)(DAT_800d210c + 4) = puVar6;
    PopMatrix();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ fx_setTex(struct DVECTOR *x /*$a0*/, unsigned char *uv /*$a1*/, int tx /*$a2*/, int offset /*$a3*/)
 // line 7623, offset 0x8004ea7c
	/* begin block 1 */
		// Start line: 18641
	/* end block 1 */
	// End Line: 18642

	/* begin block 2 */
		// Start line: 18642
	/* end block 2 */
	// End Line: 18643

/* File: C:\kain2\game\FX.C */

void fx_setTex(undefined x,uchar *uv,int tx,int offset)

{
  uchar uVar1;
  undefined3 in_register_00000011;
  char *pcVar2;
  
  pcVar2 = (char *)CONCAT31(in_register_00000011,x);
  *uv = *pcVar2 - (char)tx;
  uVar1 = -1;
  if (*(short *)(pcVar2 + 2) < 0x100) {
    uVar1 = pcVar2[2];
  }
  uv[1] = uVar1;
  *(short *)(pcVar2 + 2) = *(short *)(pcVar2 + 2) + (short)offset;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawRing2(struct MATRIX *wcTransform /*$s0*/, struct _SVector *position /*$s1*/, struct MATRIX *matrix /*$s3*/, int radius /*stack 12*/, int radius2 /*stack 16*/, int radius3 /*stack 20*/, int z1 /*stack 24*/, int z2 /*stack 28*/, int z3 /*stack 32*/, long offset /*stack 36*/, int sortInWorld /*stack 40*/)
 // line 7632, offset 0x8004eac0
	/* begin block 1 */
		// Start line: 7633
		// Start offset: 0x8004EAC0
		// Variables:
	// 		int n; // $s3
	// 		struct POLY_FT4 *poly; // $s2
	// 		unsigned long **drawot; // stack offset -52
	// 		struct _SVector points[3]; // stack offset -104
	// 		long sxy[3]; // stack offset -80
	// 		long degrees; // $s7
	// 		long sz0; // stack offset -64
	// 		long sz1; // stack offset -60
	// 		long sz2; // stack offset -56
	// 		long startz; // $fp
	// 		short tx; // $s0
	// 		long dispYPos; // $s0
	/* end block 1 */
	// End offset: 0x8004EE24
	// End Line: 7719

	/* begin block 2 */
		// Start line: 18659
	/* end block 2 */
	// End Line: 18660

	/* begin block 3 */
		// Start line: 18670
	/* end block 3 */
	// End Line: 18671

/* WARNING: Could not reconcile some variable overlaps */
/* File: C:\kain2\game\FX.C */

void FX_DrawRing2(undefined wcTransform,_SVector *position,undefined matrix,int radius,int radius2,
                 int radius3,int z1,int z2,int z3,long offset,int sortInWorld)

{
  ushort uVar1;
  bool bVar2;
  char cVar3;
  ushort uVar4;
  long lVar5;
  int tx;
  undefined3 in_register_00000011;
  uint *puVar6;
  uint uVar7;
  undefined3 in_register_00000019;
  uint uVar8;
  uint *uv;
  uint *puVar9;
  int iVar10;
  uint uVar11;
  int degrees;
  _SVector _Stack104;
  undefined2 local_5c;
  undefined2 local_54;
  uint local_50;
  undefined4 local_4c;
  uint local_48;
  int local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  uint local_30;
  
  puVar9 = *(uint **)(DAT_800d210c + 4);
  local_34 = DAT_800d22a4;
  if (puVar9 + 0x140 < *(uint **)(DAT_800d210c + 8)) {
    PushMatrix();
    SetRotMatrix((MATRIX *)CONCAT31(in_register_00000011,wcTransform));
    SetTransMatrix((MATRIX *)CONCAT31(in_register_00000011,wcTransform));
    lVar5 = fx_get_startz(position);
    SetRotMatrix((MATRIX *)CONCAT31(in_register_00000019,matrix));
    _Stack104.z = (short)z1;
    local_5c = (undefined2)z2;
    uVar8 = (DAT_800d20d0 ^ 1) << 8;
    local_54 = (undefined2)z3;
    fx_calc_points(&_Stack104,0,radius,radius2,radius3);
    local_50 = getCopReg(2,0xc);
    local_4c = getCopReg(2,0xd);
    local_48 = getCopReg(2,0xe);
    iVar10 = 0;
    uVar11 = (int)(uVar8 & 0x100) >> 4;
    uVar8 = (uVar8 & 0x200) << 2;
    local_30 = uVar11 | 0x100 | uVar8;
    uv = puVar9 + 9;
    degrees = 0x80;
    do {
      fx_calc_points(&_Stack104,degrees,radius,radius2,radius3);
      uv[-8] = 0x2dc0c0c0;
      uv[-7] = local_48;
      uv[-3] = local_50;
      if ((short)(ushort)local_48 < (short)(ushort)local_50) {
        local_50._0_2_ = (ushort)local_48;
      }
      local_50 = getCopReg(2,0xc);
      local_4c = getCopReg(2,0xd);
      local_48 = getCopReg(2,0xe);
      local_40 = getCopReg(2,0x11);
      local_3c = getCopReg(2,0x12);
      local_38 = getCopReg(2,0x13);
      uv[-5] = local_48;
      uv[-1] = local_50;
      uVar1 = (ushort)local_50;
      if ((short)(ushort)local_48 < (short)(ushort)local_50) {
        uVar1 = (ushort)local_48;
      }
      if ((short)(ushort)local_50 < (short)uVar1) {
        uVar1 = (ushort)local_50;
      }
      tx = (int)(short)(uVar1 & 0xffc0);
      if (tx < -0x3f) {
        *(undefined2 *)((int)uv + -0xe) = (undefined2)local_30;
      }
      else {
        if (tx < 0) {
          uVar4 = (ushort)((int)(tx + 0x400U & 0x3ff) >> 6);
        }
        else {
          uVar4 = (ushort)(((uint)uVar1 & 0x3c0) >> 6);
        }
        *(ushort *)((int)uv + -0xe) = (ushort)uVar11 | uVar4 | 0x100 | (ushort)uVar8;
      }
      cVar3 = (char)puVar9;
      tx = (int)(short)(uVar1 & 0xffc0);
      fx_setTex(cVar3 + '\b',(uchar *)(puVar9 + 3),tx,offset);
      fx_setTex(cVar3 + '\x10',(uchar *)(puVar9 + 5),tx,offset);
      fx_setTex(cVar3 + '\x18',(uchar *)(puVar9 + 7),tx,offset);
      fx_setTex(cVar3 + ' ',(uchar *)uv,tx,offset);
      if (local_38 < local_40) {
        local_40 = local_38;
      }
      if (local_40 < 0) {
        local_40 = local_40 + 3;
      }
      local_40 = local_40 >> 2;
      if (0 < local_40) {
        bVar2 = local_40 <= lVar5;
        if ((sortInWorld == 0) && (local_40 = lVar5 + 0x10, bVar2)) {
          local_40 = 1;
        }
        if (local_40 - 1U < 0xbff) {
          uv = uv + 10;
          puVar6 = (uint *)(local_40 * 4 + local_34);
          uVar7 = (uint)puVar9 & 0xffffff;
          *puVar9 = *puVar6 & 0xffffff | 0x9000000;
          puVar9 = puVar9 + 10;
          *puVar6 = uVar7;
        }
      }
      iVar10 = iVar10 + 1;
      degrees = degrees + 0x80;
    } while (iVar10 < 0x20);
    *(uint **)(DAT_800d210c + 4) = puVar9;
    PopMatrix();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawFField(struct MATRIX *wcTransform /*$s2*/, struct _FXForceFieldEffect *field /*$s0*/)
 // line 7743, offset 0x8004ee54
	/* begin block 1 */
		// Start line: 7744
		// Start offset: 0x8004EE54
		// Variables:
	// 		struct _Instance *instance; // $a0
	// 		struct MATRIX tmpmat; // stack offset -64
	// 		struct _SVector position; // stack offset -32
	// 		int size; // $s1
	// 		short fade; // $v0
	// 		long color; // stack offset -20
	// 		long black; // stack offset -24
	/* end block 1 */
	// End offset: 0x8004F00C
	// End Line: 7790

	/* begin block 2 */
		// Start line: 18966
	/* end block 2 */
	// End Line: 18967

/* File: C:\kain2\game\FX.C */

void FX_DrawFField(undefined1 wcTransform,_FXForceFieldEffect *field)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  _Instance *p_Var4;
  int p1;
  MATRIX MStack64;
  _SVector local_20;
  undefined4 local_18;
  uint local_14;
  
  p_Var4 = field->instance;
  local_20.x = (p_Var4->position).x + (field->offset).x;
  local_20.y = (p_Var4->position).y + (field->offset).y;
  local_20.z = (p_Var4->position).z + (field->offset).z;
  local_18 = 0;
  iVar3 = rcos((int)field->deg);
  field->deg = field->deg + field->deg_change & 0xfff;
  iVar3 = (int)field->size_diff + (iVar3 * field->size_change >> 0xc);
  uVar1 = field->start_fade - 0x80;
  if (field->start_fade == 0) {
    p1 = (uint)(ushort)field->end_fade - 0x80;
    if (field->end_fade == 0) {
      sVar2 = 0;
    }
    else {
      sVar2 = (short)p1;
      field->end_fade = sVar2;
      if (p1 * 0x10000 < 1) {
        FX_DeleteGeneralEffect((_FXGeneralEffect *)field);
        return;
      }
      sVar2 = 0x1000 - sVar2;
    }
  }
  else {
    field->start_fade = uVar1;
    if ((int)((uint)uVar1 << 0x10) < 0) {
      field->start_fade = 0;
    }
    sVar2 = field->start_fade;
  }
  p1 = (int)sVar2;
  if (p1 == 0) {
    local_14 = field->color;
  }
  else {
    LoadAverageCol((u_char *)&field->color,(u_char *)&local_18,0x1000 - p1,p1,(u_char *)&local_14);
  }
  local_14 = local_14 & 0xffffff;
  MATH3D_SetUnityMatrix(0xc0);
  RotMatrixZ(0x400,&MStack64);
  RotMatrixX((int)DAT_800d104c,&MStack64);
  FX_DrawRing(wcTransform,&local_20,0xc0,(int)field->size - iVar3,(int)field->size,
              field->size - iVar3,0,0,0,local_14,0);
  return;
}



// decompiled code
// original method signature: 
// struct _FXForceFieldEffect * /*$ra*/ FX_StartFField(struct _Instance *instance /*$s2*/, int size /*$s3*/, struct _Position *offset /*$s1*/, int size_diff /*$s4*/, int size_change /*stack 16*/, int deg_change /*stack 20*/, long color /*stack 24*/)
 // line 7792, offset 0x8004f024
	/* begin block 1 */
		// Start line: 7793
		// Start offset: 0x8004F024
		// Variables:
	// 		struct _FXForceFieldEffect *field; // $s0

		/* begin block 1.1 */
			// Start line: 7798
			// Start offset: 0x8004F068
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a1
		// 		struct _SVector *_v0; // $v0
		/* end block 1.1 */
		// End offset: 0x8004F068
		// End Line: 7798
	/* end block 1 */
	// End offset: 0x8004F0D4
	// End Line: 7816

	/* begin block 2 */
		// Start line: 19075
	/* end block 2 */
	// End Line: 19076

/* File: C:\kain2\game\FX.C */

_FXForceFieldEffect *
FX_StartFField(_Instance *instance,int size,_Position *offset,int size_diff,int size_change,
              int deg_change,long color)

{
  short sVar1;
  short sVar2;
  _FXForceFieldEffect *ptr;
  
  ptr = (_FXForceFieldEffect *)MEMPACK_Malloc(0x2c,'\r');
  if (ptr != (_FXForceFieldEffect *)0x0) {
    ptr->effectType = -0x7a;
    ptr->instance = instance;
    ptr->type = '\0';
    ptr->lifeTime = -1;
    ptr->continue_process = (void *)0x0;
    ptr->size = (short)size;
    sVar1 = offset->y;
    sVar2 = offset->z;
    (ptr->offset).x = offset->x;
    (ptr->offset).y = sVar1;
    (ptr->offset).z = sVar2;
    ptr->size_diff = (short)size_diff;
    ptr->deg = 0;
    ptr->size_change = (short)size_change;
    ptr->end_fade = 0;
    ptr->deg_change = (short)deg_change;
    ptr->start_fade = 0x1000;
    ptr->color = color;
    FX_InsertGeneralEffect(ptr);
  }
  return ptr;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_EndFField(struct _Instance *instance /*$a0*/)
 // line 7819, offset 0x8004f0f8
	/* begin block 1 */
		// Start line: 7821
		// Start offset: 0x8004F0F8
		// Variables:
	// 		struct _FXGeneralEffect *currentEffect; // $v1
	/* end block 1 */
	// End offset: 0x8004F140
	// End Line: 7832

	/* begin block 2 */
		// Start line: 19136
	/* end block 2 */
	// End Line: 19137

	/* begin block 3 */
		// Start line: 19137
	/* end block 3 */
	// End Line: 19138

/* File: C:\kain2\game\FX.C */

void FX_EndFField(_Instance *instance)

{
  int *piVar1;
  
  piVar1 = FX_GeneralEffectTracker;
  if (FX_GeneralEffectTracker != (int *)0x0) {
    do {
      if (((_Instance *)piVar1[2] == instance) && (*(char *)(piVar1 + 3) == -0x7a)) {
        *(undefined2 *)(piVar1 + 9) = 0x1000;
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Draw_Glowing_Line(unsigned long **ot /*$t6*/, long otz /*$a0*/, struct DVECTOR *sxy0 /*$a2*/, struct DVECTOR *sxy1 /*$a3*/, struct DVECTOR *xy0 /*stack 16*/, struct DVECTOR *xy1 /*stack 20*/, long color /*stack 24*/, long color2 /*stack 28*/)
 // line 7834, offset 0x8004f148
	/* begin block 1 */
		// Start line: 7835
		// Start offset: 0x8004F148
		// Variables:
	// 		struct _POLY_2G4T *poly; // $t0
	// 		struct _PrimPool *primPool; // $t2
	// 		int negflag; // $t5
	/* end block 1 */
	// End offset: 0x8004F2DC
	// End Line: 7879

	/* begin block 2 */
		// Start line: 19166
	/* end block 2 */
	// End Line: 19167

/* File: C:\kain2\game\FX.C */

void FX_Draw_Glowing_Line
               (ulong **ot,long otz,undefined sxy0,undefined sxy1,undefined1 xy0,undefined1 xy1,
               long color,long color2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined3 in_register_00000019;
  uint *puVar4;
  undefined3 in_register_0000001d;
  uint *puVar5;
  uint *puVar6;
  
  iVar2 = DAT_800d210c;
  puVar5 = (uint *)CONCAT31(in_register_0000001d,sxy1);
  puVar4 = (uint *)CONCAT31(in_register_00000019,sxy0);
  if ((otz - 1U < 0xbff) &&
     (puVar6 = *(uint **)(DAT_800d210c + 4), puVar6 + 0x12 < *(uint **)(DAT_800d210c + 8))) {
    bVar1 = (color & 0x1000000U) == 0;
    if (!bVar1) {
      color = color & 0xffffff;
    }
    puVar6[6] = color | 0x3a000000U;
    puVar6[10] = color | 0x3a000000U;
    puVar6[2] = 0x3a000000;
    puVar6[4] = 0;
    puVar6[8] = color2;
    puVar6[0xc] = color2;
    puVar6[0xe] = 0;
    puVar6[0x10] = 0;
    uVar3 = *puVar4;
    puVar6[0xb] = uVar3;
    puVar6[7] = uVar3;
    *(short *)(puVar6 + 3) = *(short *)puVar4 + *_xy0;
    *(short *)((int)puVar6 + 0xe) = *(short *)((int)puVar4 + 2) - _xy0[1];
    *(short *)(puVar6 + 0xf) = *(short *)puVar4 - *_xy0;
    *(short *)((int)puVar6 + 0x3e) = *(short *)((int)puVar4 + 2) + _xy0[1];
    uVar3 = *puVar5;
    puVar6[0xd] = uVar3;
    puVar6[9] = uVar3;
    *(short *)(puVar6 + 5) = *(short *)puVar5 + *_xy1;
    *(short *)((int)puVar6 + 0x16) = *(short *)((int)puVar5 + 2) - _xy1[1];
    *(short *)(puVar6 + 0x11) = *(short *)puVar5 - *_xy1;
    *(short *)((int)puVar6 + 0x46) = *(short *)((int)puVar5 + 2) + _xy1[1];
    if (bVar1) {
      uVar3 = 0xe1000620;
    }
    else {
      uVar3 = 0xe1000640;
    }
    puVar6[1] = uVar3;
    *puVar6 = (uint)ot[otz] & 0xffffff | 0x11000000;
    ot[otz] = (ulong *)((uint)puVar6 & 0xffffff);
    *(uint **)(iVar2 + 4) = puVar6 + 0x12;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Lightning(struct MATRIX *wcTransform /*$s0*/, unsigned long **ot /*stack 4*/, struct MATRIX *mat /*stack 8*/, short deg /*$s1*/, struct _SVector *start /*stack 16*/, struct _SVector *end /*stack 20*/, int width /*stack 24*/, int small_width /*stack 28*/, int segs /*stack 32*/, int sine_size /*stack 36*/, int variation /*stack 40*/, long color /*stack 44*/, long glow_color /*stack 48*/)
 // line 7882, offset 0x8004f2e4
	/* begin block 1 */
		// Start line: 7883
		// Start offset: 0x8004F2E4
		// Variables:
	// 		int sz0; // $s5
	// 		int sz1; // stack offset -56
	// 		long otz; // $s1
	// 		int length; // $v1
	// 		struct DVECTOR sxy0; // stack offset -112
	// 		struct DVECTOR sxy1; // stack offset -104
	// 		struct DVECTOR xy0; // stack offset -96
	// 		struct DVECTOR xy1; // stack offset -88
	// 		struct DVECTOR small_xy0; // stack offset -80
	// 		struct DVECTOR small_xy1; // stack offset -72
	// 		int n; // $s3
	// 		int increment; // stack offset -52
	// 		int rsin_nd2; // $s2

		/* begin block 1.1 */
			// Start line: 7917
			// Start offset: 0x8004F398
			// Variables:
		// 		struct SVECTOR point; // stack offset -64

			/* begin block 1.1.1 */
				// Start line: 7925
				// Start offset: 0x8004F3E8
				// Variables:
			// 		int rsin_n4; // $s0
			/* end block 1.1.1 */
			// End offset: 0x8004F4D4
			// End Line: 7929

			/* begin block 1.1.2 */
				// Start line: 7933
				// Start offset: 0x8004F4E4
				// Variables:
			// 		int tmpdeg; // $s1
			/* end block 1.1.2 */
			// End offset: 0x8004F5AC
			// End Line: 7937

			/* begin block 1.1.3 */
				// Start line: 7951
				// Start offset: 0x8004F614
				// Variables:
			// 		int fx; // $s2
			// 		int fy; // $s0
			/* end block 1.1.3 */
			// End offset: 0x8004F65C
			// End Line: 7959
		/* end block 1.1 */
		// End offset: 0x8004F778
		// End Line: 7981
	/* end block 1 */
	// End offset: 0x8004F7A4
	// End Line: 7990

	/* begin block 2 */
		// Start line: 19269
	/* end block 2 */
	// End Line: 19270

/* WARNING: Could not reconcile some variable overlaps */
/* File: C:\kain2\game\FX.C */

void FX_Lightning(undefined wcTransform,ulong **ot,undefined mat,short deg,_SVector *start,
                 _SVector *end,int width,int small_width,int segs,int sine_size,int variation,
                 long color,long glow_color)

{
  undefined4 uVar1;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar2;
  int iVar3;
  int a;
  uint uVar4;
  undefined3 in_register_00000011;
  MATRIX *m;
  undefined3 in_register_00000019;
  MATRIX *m_00;
  int iVar5;
  int p1;
  int otz;
  undefined4 local_70;
  short local_68;
  short sStack102;
  undefined4 local_40;
  uint local_3c;
  int local_38;
  int local_34;
  uint local_30;
  
  m_00 = (MATRIX *)CONCAT31(in_register_00000019,mat);
  m = (MATRIX *)CONCAT31(in_register_00000011,wcTransform);
  local_30 = (uint)(ushort)deg & 0xfff;
  if (m_00 == (MATRIX *)0x0) {
    SetRotMatrix(m);
  }
  else {
    SetRotMatrix(m_00);
    m = m_00;
  }
  otz = 0x7fff;
  SetTransMatrix(m);
  local_34 = 0x1000 / segs;
  p1 = 0;
  if (-1 < segs) {
    do {
      LoadAverageShort12((SVECTOR *)start,(SVECTOR *)end,0x1000 - p1,p1,(SVECTOR *)&local_40);
      iVar2 = rsin(p1 / 2);
      if ((variation == 0) || (segs == 0)) {
LAB_8004f4d4:
        if (m_00 != (MATRIX *)0x0) goto LAB_8004f4e4;
      }
      else {
        if (m_00 == (MATRIX *)0x0) {
          iVar3 = rsin(p1 << 2);
          a = rand();
          iVar5 = variation / 2;
          a = (a % variation - iVar5) * iVar3;
          if (a < 0) {
            a = a + 0xfff;
          }
          local_40 = local_40 & 0xffff0000 | (uint)(ushort)((short)local_40 + (short)(a >> 0xc));
          a = rand();
          iVar3 = (a % variation - iVar5) * iVar3;
          if (iVar3 < 0) {
            iVar3 = iVar3 + 0xfff;
          }
          local_40 = local_40 & 0xffff |
                     (uint)(ushort)(local_40._2_2_ + (short)(iVar3 >> 0xc)) << 0x10;
          iVar3 = rsin(p1 + local_30);
          a = rand();
          iVar3 = iVar3 * sine_size;
          if (iVar3 < 0) {
            iVar3 = iVar3 + 0xfff;
          }
          iVar3 = (iVar3 >> 0xc) * iVar2;
          if (iVar3 < 0) {
            iVar3 = iVar3 + 0xfff;
          }
          local_3c = local_3c & 0xffff0000 |
                     (uint)(ushort)((short)local_3c +
                                   (short)(iVar3 >> 0xc) + ((short)(a % variation) - (short)iVar5));
          goto LAB_8004f4d4;
        }
LAB_8004f4e4:
        a = local_30 + segs * 0x200;
        iVar3 = rcos(a);
        uVar4 = rand();
        iVar3 = iVar3 * sine_size;
        if (iVar3 < 0) {
          iVar3 = iVar3 + 0xfff;
        }
        iVar3 = ((iVar3 >> 0xc) + (uVar4 & 7)) * iVar2;
        if (iVar3 < 0) {
          iVar3 = iVar3 + 0xfff;
        }
        local_40 = local_40 & 0xffff0000 | iVar3 >> 0xc & 0xffffU;
        iVar3 = rsin(a);
        uVar4 = rand();
        iVar3 = iVar3 * sine_size;
        if (iVar3 < 0) {
          iVar3 = iVar3 + 0xfff;
        }
        iVar2 = ((iVar3 >> 0xc) + (uVar4 & 7)) * iVar2;
        if (iVar2 < 0) {
          iVar2 = iVar2 + 0xfff;
        }
        local_40 = local_40 & 0xffff | (iVar2 >> 0xc) << 0x10;
        iVar2 = rand();
        local_3c = local_3c & 0xffff0000 | (uint)(ushort)((short)local_3c + ((ushort)iVar2 & 7));
      }
      setCopReg(2,in_zero,local_40);
      setCopReg(2,in_at,local_3c);
      copFunction(2,0x180001);
      uVar1 = getCopReg(2,0xe);
      local_38 = getCopReg(2,0x13);
      if (otz < local_38) {
        if (otz < 0) {
          otz = otz + 3;
        }
      }
      else {
        otz = local_38;
        if (local_38 < 0) {
          otz = local_38 + 3;
        }
      }
      otz = otz >> 2;
      if ((segs != 0) && (p1 != 0)) {
        local_68 = (short)uVar1;
        sStack102 = (short)((uint)uVar1 >> 0x10);
        MATH3D_veclen2((int)local_68 - (int)(short)local_70,(int)sStack102 - (int)local_70._2_2_);
      }
      if (((p1 != 0) && (0 < otz)) && (otz < 0xc00)) {
        if (width * 0x140 != 0) {
          FX_Draw_Glowing_Line(ot,otz,0x90,0x98,0xa0,0xa8,glow_color,glow_color);
        }
        if ((0 < otz + -5) && (small_width * 0x140 != 0)) {
          FX_Draw_Glowing_Line(ot,otz + -5,0x90,0x98,0xb0,0xb8,color,color);
        }
      }
      segs = segs + -1;
      p1 = p1 + local_34;
      otz = local_38;
      local_70 = uVar1;
    } while (-1 < segs);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_LightHouse(struct MATRIX *wcTransform /*$s0*/, unsigned long **ot /*stack 4*/, struct _Instance *instance /*$a2*/, int startSeg /*$a3*/, int endSeg /*stack 16*/, int segs /*stack 20*/, long beam_color /*stack 24*/)
 // line 7995, offset 0x8004f7d4
	/* begin block 1 */
		// Start line: 7996
		// Start offset: 0x8004F7D4
		// Variables:
	// 		int sz0; // $s4
	// 		int sz1; // stack offset -72
	// 		long otz; // $a1
	// 		int width; // $s0
	// 		struct _SVector start; // stack offset -136
	// 		struct _SVector end; // stack offset -128
	// 		struct DVECTOR sxy0; // stack offset -120
	// 		struct DVECTOR sxy1; // stack offset -112
	// 		struct DVECTOR xy0; // stack offset -104
	// 		struct DVECTOR xy1; // stack offset -96
	// 		int fade; // $a3
	// 		int n; // $s2
	// 		int increment; // $s6
	// 		long black; // stack offset -64
	// 		long color; // stack offset -68
	// 		long color1; // stack offset -56
	// 		long color2; // stack offset -60
	// 		int fx; // stack offset -52
	// 		int fy; // stack offset -48
	// 		int length; // $s7
	// 		int segcnt; // $s3
	// 		int end_width; // stack offset -44
	// 		int flag; // $fp
	// 		struct MATRIX *swTransform; // $v1

		/* begin block 1.1 */
			// Start line: 8055
			// Start offset: 0x8004F91C
			// Variables:
		// 		struct SVECTOR point; // stack offset -88

			/* begin block 1.1.1 */
				// Start line: 8066
				// Start offset: 0x8004F994
				// Variables:
			// 		int newlength; // $v1
			// 		int newfx; // $s1
			// 		int newfy; // $s0
			/* end block 1.1.1 */
			// End offset: 0x8004F9D8
			// End Line: 8080
		/* end block 1.1 */
		// End offset: 0x8004F9F8
		// End Line: 8087

		/* begin block 1.2 */
			// Start line: 8098
			// Start offset: 0x8004FA2C
			// Variables:
		// 		struct SVECTOR point; // stack offset -80

			/* begin block 1.2.1 */
				// Start line: 8120
				// Start offset: 0x8004FB14
				// Variables:
			// 		int x; // $v0
			/* end block 1.2.1 */
			// End offset: 0x8004FBA0
			// End Line: 8132
		/* end block 1.2 */
		// End offset: 0x8004FBF0
		// End Line: 8141
	/* end block 1 */
	// End offset: 0x8004FC20
	// End Line: 8151

	/* begin block 2 */
		// Start line: 19538
	/* end block 2 */
	// End Line: 19539

/* WARNING: Could not reconcile some variable overlaps */
/* File: C:\kain2\game\FX.C */

void FX_LightHouse(undefined wcTransform,ulong **ot,_Instance *instance,int startSeg,int endSeg,
                  int segs,long beam_color)

{
  bool bVar1;
  undefined4 in_zero;
  undefined4 in_at;
  long p1;
  int p1_00;
  int iVar2;
  MATRIX *pMVar3;
  undefined3 in_register_00000011;
  int iVar4;
  int p1_01;
  int iVar5;
  int iVar6;
  SVECTOR local_88;
  SVECTOR local_80;
  undefined4 local_78;
  undefined4 local_70;
  uint local_68;
  uint local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  long local_44;
  undefined4 local_40;
  long local_3c;
  long local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  bVar1 = false;
  if ((instance->flags & 0x800U) == 0) {
    if (instance->matrix != (MATRIX *)0x0) {
      pMVar3 = instance->matrix + startSeg;
      local_88.vx = *(short *)pMVar3->t;
      local_88.vy = *(short *)(pMVar3->t + 1);
      local_88.vz = *(short *)(pMVar3->t + 2);
      pMVar3 = instance->matrix + endSeg;
      local_80.vx = *(short *)pMVar3->t;
      local_80.vy = *(short *)(pMVar3->t + 1);
      local_80.vz = *(short *)(pMVar3->t + 2);
      SetRotMatrix((MATRIX *)CONCAT31(in_register_00000011,wcTransform));
      SetTransMatrix((MATRIX *)CONCAT31(in_register_00000011,wcTransform));
      local_38 = beam_color;
      local_68 = 0;
      local_3c = beam_color;
      local_44 = beam_color;
      local_40 = 0;
      p1 = MATH3D_DistanceBetweenPositions((_Position *)&local_88,(_Position *)&local_80);
      p1_00 = (p1 / 2) * 0x420;
      iVar5 = 0;
      if (p1_00 < 0) {
        p1_00 = p1_00 + 0xfff;
      }
      p1_01 = 0;
      local_2c = (p1_00 >> 0xc) + 0x60;
      local_30 = 0;
      local_34 = 0;
      p1_00 = segs;
      if (segs < 0) {
        p1_00 = segs + 3;
      }
      p1_00 = p1_00 >> 2;
      iVar6 = 0x1000 / p1_00;
      if (-1 < p1_00) {
        do {
          LoadAverageShort12(&local_88,&local_80,0x1000 - p1_01,p1_01,(SVECTOR *)&local_58);
          setCopReg(2,in_zero,local_58);
          setCopReg(2,in_at,local_54);
          copFunction(2,0x180001);
          local_70 = getCopReg(2,0xe);
          local_48 = getCopReg(2,0x13);
          if (bVar1) {
            if (0xf0 < local_48) {
              iVar4 = (int)(short)local_70;
              if ((-0x200 < iVar4) && (iVar4 < 0x200)) {
                local_70._2_2_ = (short)((uint)local_70 >> 0x10);
                iVar2 = MATH3D_veclen2(iVar4 - (short)local_78,
                                       (int)local_70._2_2_ - (int)local_78._2_2_);
                if ((iVar5 < iVar2) && (iVar2 < 0x100)) {
                  iVar5 = iVar2;
                  local_34 = iVar4 - (short)local_78;
                  local_30 = (int)local_70._2_2_ - (int)local_78._2_2_;
                }
              }
              goto LAB_8004f9d8;
            }
          }
          else {
LAB_8004f9d8:
            if (0xf0 < local_48) {
              bVar1 = true;
              local_78 = local_70;
            }
          }
          p1_00 = p1_00 + -1;
          p1_01 = p1_01 + iVar6;
        } while (-1 < p1_00);
      }
      if (iVar5 != 0) {
        p1_01 = 0x1000 / segs;
        p1_00 = 0;
        if (-1 < segs) {
          iVar4 = 0;
          iVar6 = 0x7fff;
          do {
            LoadAverageShort12(&local_88,&local_80,0x1000 - p1_00,p1_00,(SVECTOR *)&local_50);
            iVar2 = (local_2c + -0x60) * p1_00;
            if (iVar2 < 0) {
              iVar2 = iVar2 + 0xfff;
            }
            iVar2 = ((iVar2 >> 0xc) + 0x60) * 0x140;
            p1 = 0x1000 - iVar4;
            if ((0x7ff < p1_00) && (p1 = 0, 0x800 < p1_00)) {
              p1 = iVar4 + -0x1000;
            }
            LoadAverageCol((u_char *)&local_44,(u_char *)&local_40,0x1000 - p1,p1,
                           (u_char *)&local_3c);
            setCopReg(2,in_zero,local_50);
            setCopReg(2,in_at,local_4c);
            copFunction(2,0x180001);
            local_70 = getCopReg(2,0xe);
            local_48 = getCopReg(2,0x13);
            if (iVar6 < local_48) {
              if (iVar6 < 0) {
                iVar6 = iVar6 + 3;
              }
            }
            else {
              iVar6 = local_48;
              if (local_48 < 0) {
                iVar6 = local_48 + 3;
              }
            }
            if (p1_00 != 0) {
              if (local_48 < 1) {
                local_48 = 1;
              }
              local_60 = ((local_30 * iVar2) / (iVar5 * local_48) << 9) / 0x140 & 0xffffU |
                         (local_34 * iVar2) / (iVar5 * local_48) << 0x10;
            }
            if (p1_00 == p1_01) {
              local_68 = local_60;
            }
            if ((p1_00 != 0) && (0 < iVar6 >> 2)) {
              FX_Draw_Glowing_Line(ot,iVar6 >> 2,0x88,0x90,0x98,0xa0,local_38,local_3c);
            }
            iVar4 = iVar4 + p1_01 * 2;
            p1_00 = p1_00 + p1_01;
            local_38 = local_3c;
            local_78 = local_70;
            local_68 = local_60;
            segs = segs + -1;
            iVar6 = local_48;
          } while (-1 < segs);
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartPassthruFX(struct _Instance *instance /*$s0*/, struct _SVector *normal /*$a1*/, struct _SVector *point /*$a2*/)
 // line 8154, offset 0x8004fc50
	/* begin block 1 */
		// Start line: 8155
		// Start offset: 0x8004FC50
		// Variables:
	// 		long color; // stack offset -24
	/* end block 1 */
	// End offset: 0x8004FC50
	// End Line: 8155

	/* begin block 2 */
		// Start line: 19933
	/* end block 2 */
	// End Line: 19934

/* File: C:\kain2\game\FX.C */

void FX_StartPassthruFX(_Instance *instance,_SVector *normal,_SVector *point)

{
  undefined *local_18 [2];
  
  (instance->halvePlane).a = normal->x;
  (instance->halvePlane).b = normal->y;
  (instance->halvePlane).c = normal->z;
  local_18[0] = &DAT_0020ff40;
  (instance->halvePlane).d =
       -((int)normal->x * (int)point->x + (int)normal->y * (int)point->y +
         (int)normal->z * (int)point->z >> 0xc);
  FX_DoInstancePowerRing(instance,(long)&DAT_000020d0,(long *)local_18,0,2);
  FX_DoInstancePowerRing(instance,(long)&DAT_000020d0,(long *)local_18,0,1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_EndPassthruFX(struct _Instance *instance /*$a0*/)
 // line 8172, offset 0x8004fd2c
	/* begin block 1 */
		// Start line: 19985
	/* end block 1 */
	// End Line: 19986

/* File: C:\kain2\game\FX.C */

void FX_EndPassthruFX(_Instance *instance)

{
  FX_EndInstanceEffects(instance);
  return;
}





