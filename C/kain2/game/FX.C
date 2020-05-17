#include "THISDUST.H"
#include "FX.H"


// decompiled code
// original method signature: 
// void /*$ra*/ FX_Init(struct _FXTracker *fxTracker /*$s1*/)
 // line 120, offset 0x80042560
	/* begin block 1 */
		// Start line: 121
		// Start offset: 0x80042560
		// Variables:
	// 		struct _FX_MATRIX *fxMatrix; // $s0
	// 		struct _FX_MATRIX *endFXMatrix; // $s2
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct _FX_PRIM *endFXPrim; // $s2
	/* end block 1 */
	// End offset: 0x800425F8
	// End Line: 147

	/* begin block 2 */
		// Start line: 240
	/* end block 2 */
	// End Line: 241

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
  FX_LastUsedPrim = (_FX_PRIM *)0x0;
  FX_ConstrictPositionPtr = &FX_ConstrictPosition;
  FX_Spiral_Init();
  snow_amount = 0;
  rain_amount = 0;
  current_rain_fade = 0;
  FX_reaver_instance = (_Instance *)0x0;
  FX_Frames = 1;
  FX_TimeCount = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Die(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$s1*/)
 // line 191, offset 0x80042640
	/* begin block 1 */
		// Start line: 382
	/* end block 1 */
	// End Line: 383

	/* begin block 2 */
		// Start line: 431
	/* end block 2 */
	// End Line: 432

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
 // line 208, offset 0x800426b0
	/* begin block 1 */
		// Start line: 209
		// Start offset: 0x800426B0
		// Variables:
	// 		struct _FX_MATRIX *fxMatrix; // $s0
	/* end block 1 */
	// End offset: 0x800426E8
	// End Line: 218

	/* begin block 2 */
		// Start line: 467
	/* end block 2 */
	// End Line: 468

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
 // line 222, offset 0x80042700
	/* begin block 1 */
		// Start line: 223
		// Start offset: 0x80042700
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $a0
	/* end block 1 */
	// End offset: 0x80042760
	// End Line: 244

	/* begin block 2 */
		// Start line: 496
	/* end block 2 */
	// End Line: 497

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
  p_Var3->process = (void *)0x0;
  p_Var3->flags = 0;
  p_Var3->matrix = (_FX_MATRIX *)0x0;
  return p_Var3;
}



// decompiled code
// original method signature: 
// struct _FXParticle * /*$ra*/ FX_GetParticle(struct _Instance *instance /*$s1*/, short startSegment /*$s0*/)
 // line 247, offset 0x80042770
	/* begin block 1 */
		// Start line: 248
		// Start offset: 0x80042770
		// Variables:
	// 		struct _FXParticle *particle; // $v1
	/* end block 1 */
	// End offset: 0x800427F4
	// End Line: 268

	/* begin block 2 */
		// Start line: 549
	/* end block 2 */
	// End Line: 550

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
// void /*$ra*/ FX_AniTexSetup(struct _FX_PRIM *fxPrim /*$a2*/, struct _MFace *mface /*$a1*/, struct _Model *model /*$a2*/, struct _FXTracker *fxTracker /*$a3*/)
 // line 271, offset 0x8004280c
	/* begin block 1 */
		// Start line: 606
	/* end block 1 */
	// End Line: 607

	/* begin block 2 */
		// Start line: 607
	/* end block 2 */
	// End Line: 608

void FX_AniTexSetup(_FX_PRIM *fxPrim,_MFace *mface,_Model *model,_FXTracker *fxTracker)

{
  TextureMT3 *pTVar1;
  uint uVar2;
  uint uVar3;
  
  if ((mface->flags & 2) == 0) {
    fxPrim->flags = fxPrim->flags & 0xfffffffa;
    uVar2 = mface->color;
    uVar3 = 0x20000000;
  }
  else {
    fxPrim->flags = fxPrim->flags | 1;
    pTVar1 = (TextureMT3 *)mface->color;
    fxPrim->texture = pTVar1;
    uVar2 = pTVar1->color;
    uVar3 = 0x24000000;
  }
  fxPrim->color = uVar2 & 0x3ffffff | uVar3;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StandardProcess(struct _FX_PRIM *fxPrim /*$a0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 360, offset 0x80042888
	/* begin block 1 */
		// Start line: 798
	/* end block 1 */
	// End Line: 799

void FX_StandardProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  FX_StandardFXPrimProcess(fxPrim,fxTracker);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ShatterProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$s1*/)
 // line 396, offset 0x800428a8
	/* begin block 1 */
		// Start line: 397
		// Start offset: 0x800428A8
		// Variables:
	// 		struct MATRIX matrix; // stack offset -64
	// 		struct _Rotation rotation; // stack offset -32
	// 		struct _Rotation rot_temp; // stack offset -24
	/* end block 1 */
	// End offset: 0x80042B3C
	// End Line: 445

	/* begin block 2 */
		// Start line: 870
	/* end block 2 */
	// End Line: 871

void FX_ShatterProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  short sVar3;
  _FX_MATRIX *p_Var4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint auStack64 [8];
  short local_20;
  short local_1e;
  short local_1c;
  ushort local_18;
  short local_16;
  short local_14;
  
  memset(&local_20,0,8);
  if (0 < fxPrim->timeToLive) {
    fxPrim->timeToLive = fxPrim->timeToLive + -1;
  }
  if (fxPrim->timeToLive == 0) {
    FX_Die(fxPrim,fxTracker);
  }
  else {
    if ((fxPrim->flags & 2U) == 0) {
      iVar5 = (int)(short)gameTrackerX.timeMult;
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
        local_18 = (short)(iVar5 * (p_Var4->lwTransform).m[0] >> 0xc) +
                   (short)(iVar7 * (p_Var4->lwTransform).m[1] >> 0xc) +
                   (short)(iVar6 * (p_Var4->lwTransform).m[2] >> 0xc);
        p_Var4 = fxPrim->matrix;
        local_16 = (short)(iVar5 * (p_Var4->lwTransform).m[3] >> 0xc) +
                   (short)(iVar7 * (p_Var4->lwTransform).m[4] >> 0xc) +
                   (short)(iVar6 * (p_Var4->lwTransform).m[5] >> 0xc);
        p_Var4 = fxPrim->matrix;
        local_14 = (short)(iVar5 * (p_Var4->lwTransform).m[6] >> 0xc) +
                   (short)(iVar7 * (p_Var4->lwTransform).m[7] >> 0xc) +
                   (short)(iVar6 * (p_Var4->lwTransform).m[8] >> 0xc);
        RotMatrix(&local_18,auStack64);
        MulMatrix2(auStack64,(uint *)&fxPrim->matrix->lwTransform);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DFacadeProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 583, offset 0x80042b50
	/* begin block 1 */
		// Start line: 584
		// Start offset: 0x80042B50

		/* begin block 1.1 */
			// Start line: 596
			// Start offset: 0x80042BA8
			// Variables:
		// 		struct MATRIX *swTransform; // $v1
		/* end block 1.1 */
		// End offset: 0x80042BA8
		// End Line: 597

		/* begin block 1.2 */
			// Start line: 756
			// Start offset: 0x80042CB4
			// Variables:
		// 		struct _Rotation rot; // stack offset -16
		/* end block 1.2 */
		// End offset: 0x80042D14
		// End Line: 764
	/* end block 1 */
	// End offset: 0x80042D14
	// End Line: 773

	/* begin block 2 */
		// Start line: 1166
	/* end block 2 */
	// End Line: 1167

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
      RotMatrixX((int)*(char *)((int)&fxPrim->work2 + 1) << 2,(int)&fxPrim->matrix->lwTransform);
      RotMatrixY((int)(short)((int)cVar1 << 2),(uint *)&fxPrim->matrix->lwTransform);
      RotMatrixZ((int)(short)((int)cVar2 << 2),(uint *)&fxPrim->matrix->lwTransform);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// struct _FX_PRIM * /*$ra*/ _FX_BuildSingleFaceWithModel(struct _Model *model /*$a0*/, struct _MFace *mface /*$s6*/, struct SVECTOR *center /*$s7*/, struct SVECTOR *vel /*$fp*/, struct SVECTOR *accl /*stack 16*/, struct _FXTracker *fxTracker /*stack 20*/, TDRFuncPtr__FX_BuildSingleFaceWithModel6fxSetup fxSetup /*stack 24*/, TDRFuncPtr__FX_BuildSingleFaceWithModel7fxProcess fxProcess /*stack 28*/, struct _FX_MATRIX *fxMatrix /*stack 32*/, int timeToLive /*stack 36*/)
 // line 856, offset 0x80042d24
	/* begin block 1 */
		// Start line: 857
		// Start offset: 0x80042D24
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s1
	// 		struct _MVertex *vertexList; // $s3
	/* end block 1 */
	// End offset: 0x80042DEC
	// End Line: 885

	/* begin block 2 */
		// Start line: 1677
	/* end block 2 */
	// End Line: 1678

_FX_PRIM *
_FX_BuildSingleFaceWithModel
          (_Model *model,_MFace *mface,SVECTOR *center,SVECTOR *vel,SVECTOR *accl,
          _FXTracker *fxTracker,TDRFuncPtr__FX_BuildSingleFaceWithModel6fxSetup fxSetup,
          TDRFuncPtr__FX_BuildSingleFaceWithModel7fxProcess fxProcess,_FX_MATRIX *fxMatrix,
          int timeToLive)

{
  _FX_PRIM *node;
  _MVertex *p_Var1;
  
  p_Var1 = model->vertexList;
  if ((fxMatrix == (_FX_MATRIX *)0x0) &&
     (fxMatrix = FX_GetMatrix(fxTracker), fxMatrix == (_FX_MATRIX *)0x0)) {
    return (_FX_PRIM *)0x0;
  }
  node = FX_GetPrim(fxTracker);
  if (node != (_FX_PRIM *)0x0) {
    if (fxSetup != (TDRFuncPtr__FX_BuildSingleFaceWithModel6fxSetup)0x0) {
      (*fxSetup)(node,fxProcess,fxMatrix,0,mface,p_Var1,center,vel,accl,fxTracker,
                 (int)(short)timeToLive);
    }
    LIST_InsertFunc(&fxTracker->usedPrimList,(NodeType *)node);
  }
  return node;
}



// decompiled code
// original method signature: 
// struct _FX_PRIM * /*$ra*/ FX_BuildSingleFaceWithModel(struct _Model *model /*$a0*/, struct _MFace *mface /*$a1*/, struct SVECTOR *center /*$a2*/, struct SVECTOR *vel /*$a3*/, struct SVECTOR *accl /*stack 16*/, struct _FXTracker *fxTracker /*stack 20*/, TDRFuncPtr_FX_BuildSingleFaceWithModel6fxSetup fxSetup /*stack 24*/, TDRFuncPtr_FX_BuildSingleFaceWithModel7fxProcess fxProcess /*stack 28*/, int timeToLive /*stack 32*/)
 // line 890, offset 0x80042e20
	/* begin block 1 */
		// Start line: 1745
	/* end block 1 */
	// End Line: 1746

_FX_PRIM *
FX_BuildSingleFaceWithModel
          (_Model *model,_MFace *mface,SVECTOR *center,SVECTOR *vel,SVECTOR *accl,
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
 // line 917, offset 0x80042e70
	/* begin block 1 */
		// Start line: 918
		// Start offset: 0x80042E70
		// Variables:
	// 		struct MATRIX lm; // stack offset -40
	/* end block 1 */
	// End offset: 0x80042E70
	// End Line: 918

	/* begin block 2 */
		// Start line: 1834
	/* end block 2 */
	// End Line: 1835

void _FX_SetupLighting(_Instance *instance)

{
  MATRIX MStack40;
  
  LIGHT_PresetInstanceLight(instance,0x800,&MStack40);
  MulMatrix0((undefined4 *)&MStack40,(ushort *)(instance->matrix + instance->lightMatrix),
             (uint *)&MStack40);
  SetLightMatrix((undefined4 *)&MStack40);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ _FX_DoLighting(struct _MFace *mface /*$a0*/)
 // line 928, offset 0x80042ec0
	/* begin block 1 */
		// Start line: 929
		// Start offset: 0x80042EC0
		// Variables:
	// 		long modelDQP; // $a2
	// 		long color; // stack offset -8
	// 		struct TextureMT3 *texture; // $a1
	/* end block 1 */
	// End offset: 0x80042FCC
	// End Line: 961

	/* begin block 2 */
		// Start line: 1797
	/* end block 2 */
	// End Line: 1798

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
      setCopReg(2,in_zero,*(undefined4 *)(&gNormalList + mface->normal));
      setCopReg(2,in_at,*(undefined4 *)&(&gNormalList)[mface->normal].z);
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
      setCopReg(2,in_zero,*(undefined4 *)(&gNormalList + mface->normal));
      setCopReg(2,in_at,*(undefined4 *)&(&gNormalList)[mface->normal].z);
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
 // line 976, offset 0x80042fd8
	/* begin block 1 */
		// Start line: 977
		// Start offset: 0x80042FD8
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
			// Start line: 1059
			// Start offset: 0x800431C8
			// Variables:
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $a1
		// 		short _y1; // $a3
		// 		short _z1; // $a2
		// 		struct _SVector *_v; // stack offset -48
		// 		struct _Vector *_v1; // $a2
		/* end block 1.1 */
		// End offset: 0x800431C8
		// End Line: 1059

		/* begin block 1.2 */
			// Start line: 1072
			// Start offset: 0x8004325C
		/* end block 1.2 */
		// End offset: 0x8004331C
		// End Line: 1083

		/* begin block 1.3 */
			// Start line: 1136
			// Start offset: 0x80043614
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
		// End offset: 0x80043614
		// End Line: 1136

		/* begin block 1.4 */
			// Start line: 1165
			// Start offset: 0x80043750
			// Variables:
		// 		struct TextureMT3 *texture; // $v1
		/* end block 1.4 */
		// End offset: 0x80043750
		// End Line: 1165

		/* begin block 1.5 */
			// Start line: 1195
			// Start offset: 0x8004381C
		/* end block 1.5 */
		// End offset: 0x8004387C
		// End Line: 1200

		/* begin block 1.6 */
			// Start line: 1217
			// Start offset: 0x800438F0
		/* end block 1.6 */
		// End offset: 0x80043938
		// End Line: 1223
	/* end block 1 */
	// End offset: 0x80043A2C
	// End Line: 1243

	/* begin block 2 */
		// Start line: 1895
	/* end block 2 */
	// End Line: 1896

	/* begin block 3 */
		// Start line: 1925
	/* end block 3 */
	// End Line: 1926

/* WARNING: Could not reconcile some variable overlaps */

void _FX_BuildSegmentedSplinters
               (_Instance *instance,SVECTOR *center,SVECTOR *vel,SVECTOR *accl,FXSplinter *splintDef
               ,_FXTracker *fxTracker,TDRFuncPtr__FX_BuildSegmentedSplinters6fxSetup fxSetup,
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
  uint uVar11;
  CVECTOR CVar12;
  _MFace *mface;
  int iVar13;
  _PVertex *p_Var14;
  int iVar15;
  _PVertex *p_Var16;
  _PVertex *p_Var17;
  _MFace *p_Var18;
  undefined2 *puVar19;
  int iVar20;
  byte bVar21;
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
  _VertexPool *local_3c;
  CVECTOR *local_38;
  undefined *local_34;
  _Normal *local_30;
  
  local_3c = gameTrackerX.vertexPool;
  local_38 = (gameTrackerX.vertexPool)->color;
  local_44 = instance->object->modelList[instance->currentModel];
  local_58 = (ushort)shardFlags;
  local_40 = local_44->vertexList;
  mface = local_44->faceList;
  PIPE3D_TransformVerticesToWorld
            (instance,(_SVector *)gameTrackerX.vertexPool,(long *)local_38,(_Vector *)local_70);
  if (splintDef == (FXSplinter *)0x0) {
    local_50 = 0x20;
  }
  else {
    local_50 = (int)splintDef->lifetime;
  }
  memset(abStack240,0xff,0x80);
  _FX_SetupLighting(instance);
  if (splintDef == (FXSplinter *)0x0) {
    local_4c = 1;
  }
  else {
    local_4c = local_44->numFaces / (int)splintDef->faceLimit + 1;
  }
  iVar20 = 0;
  local_48 = mface + local_44->numFaces;
  if (mface < mface + local_44->numFaces) {
    local_34 = auStack720;
    local_30 = &local_60;
    do {
      CVar12 = local_38[(mface->face).v2];
      if ((int)local_38[(mface->face).v1] < (int)local_38[(mface->face).v2]) {
        CVar12 = local_38[(mface->face).v1];
      }
      if ((int)local_38[(mface->face).v0] < (int)CVar12) {
        CVar12 = local_38[(mface->face).v0];
      }
      if (abStack240[(int)CVar12] == 0xff) {
        if (iVar20 < 0x3c) {
          p_Var5 = FX_GetMatrix(fxTracker);
          if (p_Var5 == (_FX_MATRIX *)0x0) {
            if (iVar20 == 0) {
              return;
            }
            goto LAB_80043460;
          }
          local_3c0[iVar20] = p_Var5;
          bVar21 = (byte)iVar20;
          local_60.y = *(short *)(instance->matrix[(int)CVar12].t + 1);
          local_60.z = *(short *)(instance->matrix[(int)CVar12].t + 2);
          local_60.x = *(short *)instance->matrix[(int)CVar12].t - local_70[0];
          local_30->y = local_30->y - local_6c;
          local_30->z = local_30->z - local_68;
          MATH3D_Normalize(local_30);
          if (splintDef == (FXSplinter *)0x0) {
            iVar15 = rand();
            puVar19 = (undefined2 *)(local_34 + iVar20 * 8);
            iVar7 = iVar15;
            if (iVar15 < 0) {
              iVar7 = iVar15 + 7;
            }
            *puVar19 = (short)((int)local_60.x * (iVar15 + (iVar7 >> 3) * -8 + 0x1a) >> 0xc);
            iVar15 = rand();
            iVar7 = iVar15;
            if (iVar15 < 0) {
              iVar7 = iVar15 + 7;
            }
            puVar19[1] = (short)((int)local_60.y * (iVar15 + (iVar7 >> 3) * -8 + 0x1a) >> 0xc);
            iVar15 = rand();
            iVar7 = iVar15;
            if (iVar15 < 0) {
              iVar7 = iVar15 + 7;
            }
            puVar19[2] = (short)((int)local_60.z * (iVar15 + (iVar7 >> 3) * -8 + 0x2e) >> 0xc);
          }
          else {
            iVar7 = (uint)(ushort)splintDef->chunkVelXY - (uint)(ushort)splintDef->chunkVelRng;
            iVar15 = (int)((uint)(ushort)splintDef->chunkVelRng << 0x11) >> 0x10;
            if (iVar15 == 0) {
              iVar7 = iVar7 * 0x10000 >> 0x10;
              puVar19 = (undefined2 *)(local_34 + iVar20 * 8);
              *puVar19 = (short)(local_60.x * iVar7 >> 0xc);
              puVar19[1] = (short)(local_60.y * iVar7 >> 0xc);
              puVar19[2] = (short)((int)local_60.z * (int)splintDef->chunkVelZ >> 0xc);
            }
            else {
              iVar6 = rand();
              iVar13 = iVar7 * 0x10000 >> 0x10;
              puVar19 = (undefined2 *)(local_34 + iVar20 * 8);
              *puVar19 = (short)((int)local_60.x * (iVar13 + iVar6 % iVar15) >> 0xc);
              iVar7 = rand();
              puVar19[1] = (short)((int)local_60.y * (iVar13 + iVar7 % iVar15) >> 0xc);
              uVar1 = splintDef->chunkVelZ;
              uVar2 = splintDef->chunkVelRng;
              iVar7 = rand();
              puVar19[2] = (short)((int)local_60.z *
                                   (((int)(((uint)uVar1 - (uint)uVar2) * 0x10000) >> 0x10) +
                                   iVar7 % iVar15) >> 0xc);
            }
          }
          puVar19 = (undefined2 *)(local_34 + iVar20 * 8);
          if ((int)((uint)(ushort)puVar19[2] << 0x10) < 0) {
            puVar19[2] = 0;
          }
          iVar20 = iVar20 + 1;
        }
        else {
LAB_80043460:
          iVar7 = rand();
          iVar7 = iVar7 % iVar20;
          bVar21 = (byte)iVar7;
          p_Var5 = local_3c0[iVar7];
          puVar19 = (undefined2 *)(local_34 + iVar7 * 8);
        }
        abStack240[(int)CVar12] = bVar21;
      }
      else {
        uVar8 = (uint)abStack240[(int)CVar12];
        puVar19 = (undefined2 *)(local_34 + uVar8 * 8);
        p_Var5 = local_3c0[uVar8];
      }
      (p_Var5->lwTransform).m[0] = 0x1000;
      (p_Var5->lwTransform).m[1] = 0;
      (p_Var5->lwTransform).m[2] = 0;
      (p_Var5->lwTransform).m[3] = 0;
      (p_Var5->lwTransform).m[4] = 0x1000;
      (p_Var5->lwTransform).m[5] = 0;
      (p_Var5->lwTransform).m[6] = 0;
      (p_Var5->lwTransform).m[7] = 0;
      (p_Var5->lwTransform).m[8] = 0x1000;
      (p_Var5->lwTransform).t[0] = instance->matrix[(int)CVar12].t[0];
      (p_Var5->lwTransform).t[1] = instance->matrix[(int)CVar12].t[1];
      (p_Var5->lwTransform).t[2] = instance->matrix[(int)CVar12].t[2];
      p_Var14 = local_3c->vertex + (mface->face).v0;
      p_Var16 = local_3c->vertex + (mface->face).v1;
      p_Var17 = local_3c->vertex + (mface->face).v2;
      fxPrim = FX_GetPrim(fxTracker);
      p_Var18 = local_48;
      if (fxPrim != (_FX_PRIM *)0x0) {
        if (fxSetup == (TDRFuncPtr__FX_BuildSegmentedSplinters6fxSetup)0x0) {
          (fxPrim->position).x = *(short *)(p_Var5->lwTransform).t;
          (fxPrim->position).y = *(short *)((p_Var5->lwTransform).t + 1);
          (fxPrim->position).z = *(short *)((p_Var5->lwTransform).t + 2);
          sVar4 = (fxPrim->position).z;
          local_60.x = (fxPrim->position).x - local_70[0];
          local_30->y = (fxPrim->position).y - local_6c;
          local_30->z = sVar4 - local_68;
          (fxPrim->v0).x = p_Var14->x - local_60.x;
          (fxPrim->v0).y = (&p_Var14->x)[1] - local_60.y;
          (fxPrim->v0).z = (&p_Var14->x)[2] - local_60.z;
          (fxPrim->v1).x = p_Var16->x - local_60.x;
          (fxPrim->v1).y = (&p_Var16->x)[1] - local_60.y;
          (fxPrim->v1).z = (&p_Var16->x)[2] - local_60.z;
          (fxPrim->v2).x = p_Var17->x - local_60.x;
          (fxPrim->v2).y = (&p_Var17->x)[1] - local_60.y;
          sVar4 = (&p_Var17->x)[2];
          fxPrim->matrix = p_Var5;
          (fxPrim->v2).z = sVar4 - local_60.z;
          FX_AniTexSetup(fxPrim,mface,local_44,fxTracker);
          if ((local_58 & 0x40) == 0) {
            lVar9 = _FX_DoLighting(mface);
            fxPrim->color = lVar9;
          }
          else {
            if ((mface->flags & 2) == 0) {
              uVar11 = mface->color & 0xffffff;
              fxPrim->color = uVar11;
              uVar11 = uVar11 | 0x20000000;
              uVar8 = mface->color;
            }
            else {
              iVar7 = mface->color;
              uVar11 = *(uint *)(iVar7 + 0xc) & 0xffffff;
              fxPrim->color = uVar11;
              uVar11 = uVar11 | 0x24000000;
              uVar8 = *(uint *)(iVar7 + 0xc);
            }
            fxPrim->color = uVar11 | uVar8 & 0x3000000;
          }
          if (fxProcess == (TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess)0x0) {
            *(code **)&fxPrim->process = FX_ShatterProcess;
          }
          else {
            *(TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess *)&fxPrim->process = fxProcess;
          }
          *(undefined2 *)&fxPrim->duo = *puVar19;
          *(undefined2 *)((int)&fxPrim->duo + 2) = puVar19[1];
          *(undefined2 *)((int)&fxPrim->duo + 4) = puVar19[2];
          if (splintDef != (FXSplinter *)0x0) {
            sVar4 = splintDef->triVelRng;
            if ((int)sVar4 != 0) {
              sVar10 = -splintDef->triVelRng;
              iVar7 = rand();
              iVar15 = ((int)sVar4 << 0x11) >> 0x10;
              *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + sVar10 + (short)(iVar7 % iVar15);
              iVar7 = rand();
              *(short *)((int)&fxPrim->duo + 2) =
                   *(short *)((int)&fxPrim->duo + 2) + sVar10 + (short)(iVar7 % iVar15);
              iVar7 = rand();
              *(short *)((int)&fxPrim->duo + 4) =
                   *(short *)((int)&fxPrim->duo + 4) + sVar10 + (short)(iVar7 % iVar15);
            }
          }
          if (vel != (SVECTOR *)0x0) {
            *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + vel->vx;
            *(short *)((int)&fxPrim->duo + 2) = *(short *)((int)&fxPrim->duo + 2) + vel->vy;
            *(short *)((int)&fxPrim->duo + 4) = *(short *)((int)&fxPrim->duo + 4) + vel->vz;
          }
          *(undefined2 *)((int)&fxPrim->duo + 6) = 0;
          *(undefined2 *)((int)&fxPrim->duo + 8) = 0;
          fxPrim->work1 = 0x1000;
          fxPrim->timeToLive = (short)local_50;
          if (splintDef == (FXSplinter *)0x0) {
            *(undefined2 *)((int)&fxPrim->duo + 10) = 0xfff8;
            iVar15 = rand();
            iVar7 = iVar15;
            if (iVar15 < 0) {
              iVar7 = iVar15 + 7;
            }
            fxPrim->work3 = (short)iVar15 + (short)(iVar7 >> 3) * -8 + -4;
          }
          else {
            sVar4 = splintDef->rotRateRng;
            if ((int)sVar4 == 0) {
              fxPrim->work3 = 0;
            }
            else {
              iVar7 = rand();
              fxPrim->work3 = (short)(iVar7 % (((int)sVar4 << 0x11) >> 0x10)) - sVar4;
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
               (sVar4 = sVar3 + -0x32, (instance->object->oflags & 0x200U) != 0)) goto LAB_800439e8;
          }
          fxPrim->work0 = sVar4;
        }
        else {
          (*fxSetup)(fxPrim,fxProcess,p_Var5,instance,mface,local_40,center,vel,accl,fxTracker,0x1e)
          ;
        }
LAB_800439e8:
        LIST_InsertFunc(&fxTracker->usedPrimList,(NodeType *)fxPrim);
        p_Var18 = mface;
      }
      mface = p_Var18 + local_4c;
    } while (mface < local_48);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _FX_BuildNonSegmentedSplinters(struct _Instance *instance /*stack 0*/, struct SVECTOR *center /*stack 4*/, struct SVECTOR *vel /*stack 8*/, struct SVECTOR *accl /*stack 12*/, struct FXSplinter *splintDef /*stack 16*/, struct _FXTracker *fxTracker /*stack 20*/, TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup fxSetup /*stack 24*/, TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess fxProcess /*stack 28*/, int shardFlags /*stack 32*/)
 // line 1254, offset 0x80043a5c
	/* begin block 1 */
		// Start line: 1255
		// Start offset: 0x80043A5C
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
			// Start line: 1296
			// Start offset: 0x80043B70
			// Variables:
		// 		short start; // $v0
		/* end block 1.1 */
		// End offset: 0x80043C98
		// End Line: 1322

		/* begin block 1.2 */
			// Start line: 1352
			// Start offset: 0x80043E04
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $s3
		// 		struct _SVector *_v1; // $a1
		/* end block 1.2 */
		// End offset: 0x80043E04
		// End Line: 1352

		/* begin block 1.3 */
			// Start line: 1414
			// Start offset: 0x800441B8
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
		// End offset: 0x800441B8
		// End Line: 1414

		/* begin block 1.4 */
			// Start line: 1443
			// Start offset: 0x800442F4
			// Variables:
		// 		struct TextureMT3 *texture; // $v1
		/* end block 1.4 */
		// End offset: 0x800442F4
		// End Line: 1443

		/* begin block 1.5 */
			// Start line: 1473
			// Start offset: 0x800443B0
		/* end block 1.5 */
		// End offset: 0x800443B0
		// End Line: 1473

		/* begin block 1.6 */
			// Start line: 1499
			// Start offset: 0x800444FC
		/* end block 1.6 */
		// End offset: 0x80044544
		// End Line: 1505
	/* end block 1 */
	// End offset: 0x80044618
	// End Line: 1530

	/* begin block 2 */
		// Start line: 2797
	/* end block 2 */
	// End Line: 2798

/* WARNING: Could not reconcile some variable overlaps */

void _FX_BuildNonSegmentedSplinters
               (_Instance *instance,SVECTOR *center,SVECTOR *vel,SVECTOR *accl,FXSplinter *splintDef
               ,_FXTracker *fxTracker,TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup fxSetup,
               TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess fxProcess,int shardFlags)

{
  short sVar1;
  _VertexPool *p_Var2;
  short sVar3;
  int iVar4;
  _FX_MATRIX *p_Var5;
  uint uVar6;
  _FX_PRIM *fxPrim;
  uint uVar7;
  long lVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  int iVar12;
  ushort uVar13;
  _PVertex *p_Var14;
  int iVar15;
  _PVertex *p_Var16;
  _MFace *mface;
  _PVertex *p_Var17;
  _MFace *p_Var18;
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
  
  p_Var2 = gameTrackerX.vertexPool;
  local_3c = instance->object->modelList[instance->currentModel];
  local_38 = local_3c->vertexList;
  mface = local_3c->faceList;
  local_70 = 0xf;
  local_6c = (undefined *)0x60064;
  local_68 = &DAT_0000fff1;
  local_64 = (undefined *)0x60064;
  local_60 = &DAT_000f0000;
  local_5c = (undefined *)0x60064;
  local_58 = 0xfff10000;
  local_54 = (undefined *)0x60064;
  local_50 = (ushort)shardFlags;
  PIPE3D_TransformVerticesToWorld
            (instance,(_SVector *)gameTrackerX.vertexPool,(long *)(gameTrackerX.vertexPool)->color,
             (_Vector *)&local_98);
  if (splintDef == (FXSplinter *)0x0) {
    iVar12 = rand();
    iVar4 = iVar12;
    if (iVar12 < 0) {
      iVar4 = iVar12 + 7;
    }
    local_70 = local_70 & 0xffff0000 |
               (uint)(ushort)((short)local_70 + -4 + (short)iVar12 + (short)(iVar4 >> 3) * -8);
    iVar12 = rand();
    iVar4 = iVar12;
    if (iVar12 < 0) {
      iVar4 = iVar12 + 7;
    }
    local_68 = (undefined *)
               ((uint)local_68 & 0xffff0000 |
               (uint)(ushort)((short)local_68 + -4 + (short)iVar12 + (short)(iVar4 >> 3) * -8));
    iVar12 = rand();
    iVar4 = iVar12;
    if (iVar12 < 0) {
      iVar4 = iVar12 + 7;
    }
    local_60 = (undefined *)
               ((uint)local_60 & 0xffff |
               (uint)(ushort)(local_60._2_2_ + -4 + (short)iVar12 + (short)(iVar4 >> 3) * -8) <<
               0x10);
    iVar12 = rand();
    iVar4 = iVar12;
    if (iVar12 < 0) {
      iVar4 = iVar12 + 7;
    }
    local_58 = local_58 & 0xffff |
               (uint)(ushort)(local_58._2_2_ + -4 + (short)iVar12 + (short)(iVar4 >> 3) * -8) <<
               0x10;
    local_48 = 0x20;
  }
  else {
    sVar3 = splintDef->chunkVelRng;
    uVar13 = splintDef->chunkVelXY - sVar3;
    if ((int)sVar3 == 0) {
      local_70 = local_70 & 0xffff0000 | (uint)uVar13;
      local_68 = (undefined *)((uint)local_68 & 0xffff0000 | (uint)(ushort)-uVar13);
      local_60 = (undefined *)((uint)local_60 & 0xffff | (uint)uVar13 << 0x10);
      local_58 = local_58 & 0xffff | (uint)(ushort)-uVar13 << 0x10;
      uVar13 = splintDef->chunkVelZ;
      local_6c = (undefined *)((uint)local_6c & 0xffff0000 | (uint)uVar13);
      local_64 = (undefined *)((uint)local_64 & 0xffff0000 | (uint)uVar13);
      local_5c = (undefined *)((uint)local_5c & 0xffff0000 | (uint)uVar13);
      local_54 = (undefined *)((uint)local_54 & 0xffff0000 | (uint)uVar13);
    }
    else {
      iVar4 = rand();
      iVar12 = ((int)sVar3 << 0x11) >> 0x10;
      local_70 = local_70 & 0xffff0000 | (uint)(ushort)(uVar13 + (short)(iVar4 % iVar12));
      iVar4 = rand();
      local_68 = (undefined *)
                 ((uint)local_68 & 0xffff0000 | (uint)(ushort)-(uVar13 + (short)(iVar4 % iVar12)));
      iVar4 = rand();
      local_60 = (undefined *)
                 ((uint)local_60 & 0xffff | (uint)(ushort)(uVar13 + (short)(iVar4 % iVar12)) << 0x10
                 );
      iVar4 = rand();
      local_58 = local_58 & 0xffff | (uint)(ushort)-(uVar13 + (short)(iVar4 % iVar12)) << 0x10;
      sVar3 = splintDef->chunkVelZ - splintDef->chunkVelRng;
      iVar4 = rand();
      local_6c = (undefined *)
                 ((uint)local_6c & 0xffff0000 | (uint)(ushort)(sVar3 + (short)(iVar4 % iVar12)));
      iVar4 = rand();
      local_64 = (undefined *)
                 ((uint)local_64 & 0xffff0000 | (uint)(ushort)(sVar3 + (short)(iVar4 % iVar12)));
      iVar4 = rand();
      local_5c = (undefined *)
                 ((uint)local_5c & 0xffff0000 | (uint)(ushort)(sVar3 + (short)(iVar4 % iVar12)));
      iVar4 = rand();
      local_54 = (undefined *)
                 ((uint)local_54 & 0xffff0000 | (uint)(ushort)(sVar3 + (short)(iVar4 % iVar12)));
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
      iVar12 = rand();
      p_Var5 = local_c8[iVar12 % iVar4];
    }
    local_c8[iVar4] = p_Var5;
    iVar12 = iVar4 * 8;
    puVar11 = &local_70 + iVar4 * 2;
    *(undefined4 *)(p_Var5->lwTransform).m = local_b8;
    *(undefined4 *)((p_Var5->lwTransform).m + 2) = local_b4;
    *(undefined4 *)((p_Var5->lwTransform).m + 4) = local_b0;
    *(undefined4 *)((p_Var5->lwTransform).m + 6) = local_ac;
    *(undefined4 *)((p_Var5->lwTransform).m + 8) = local_a8;
    (p_Var5->lwTransform).t[0] = local_a4;
    (p_Var5->lwTransform).t[1] = local_a0;
    (p_Var5->lwTransform).t[2] = local_9c;
    local_78 = *(short *)puVar11;
    local_76 = *(short *)((int)&local_70 + iVar12 + 2);
    local_74 = *(short *)(&local_6c + iVar4 * 2);
    *(short *)puVar11 =
         (short)((int)local_78 * (int)(short)local_b8 >> 0xc) +
         (short)((int)local_76 * (int)local_b8._2_2_ >> 0xc) +
         (short)((int)local_74 * (int)(short)local_b4 >> 0xc);
    *(short *)((int)&local_70 + iVar12 + 2) =
         (short)((int)local_78 * (int)local_b4._2_2_ >> 0xc) +
         (short)((int)local_76 * (int)(short)local_b0 >> 0xc) +
         (short)((int)local_74 * (int)local_b0._2_2_ >> 0xc);
    iVar15 = iVar4 + 1;
    *(short *)(&local_6c + iVar4 * 2) =
         (short)((int)local_78 * (int)(short)local_ac >> 0xc) +
         (short)((int)local_76 * (int)local_ac._2_2_ >> 0xc) +
         (short)((int)local_74 * (int)(short)local_a8 >> 0xc);
    (p_Var5->lwTransform).t[0] = (p_Var5->lwTransform).t[0] + (int)*(short *)puVar11 * 4;
    (p_Var5->lwTransform).t[1] =
         (p_Var5->lwTransform).t[1] +
         ((int)((uint)*(ushort *)((int)&local_70 + iVar12 + 2) << 0x10) >> 0xe);
    iVar4 = iVar15;
  } while (iVar15 < 4);
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
      p_Var14 = p_Var2->vertex + (mface->face).v0;
      p_Var16 = p_Var2->vertex + (mface->face).v1;
      p_Var17 = p_Var2->vertex + (mface->face).v2;
      iVar4 = (int)p_Var14->x + (int)p_Var16->x + (int)p_Var17->x;
      iVar9 = (int)((ulonglong)((longlong)iVar4 * (longlong)local_34) >> 0x20) - (iVar4 >> 0x1f);
      local_80 = (short)iVar9;
      iVar4 = (int)(&p_Var14->x)[1] + (int)(&p_Var16->x)[1] + (int)(&p_Var17->x)[1];
      iVar4 = (int)((ulonglong)((longlong)iVar4 * (longlong)local_34) >> 0x20) - (iVar4 >> 0x1f);
      local_7e = (short)iVar4;
      iVar12 = (int)(&p_Var14->x)[2] + (int)(&p_Var16->x)[2] + (int)(&p_Var17->x)[2];
      iVar15 = iVar4 * 0x10000 >> 0x10;
      iVar9 = iVar9 * 0x10000 >> 0x10;
      iVar4 = iVar9;
      if (iVar9 < 0) {
        iVar4 = -iVar9;
      }
      local_7c = (short)((ulonglong)((longlong)iVar12 * (longlong)local_34) >> 0x20) -
                 (short)(iVar12 >> 0x1f);
      iVar12 = iVar15;
      if (iVar15 < 0) {
        iVar12 = -iVar15;
      }
      uVar6 = (uint)(iVar9 < 1);
      if ((iVar4 <= iVar12) && (uVar6 = 3, 0 < iVar15)) {
        uVar6 = 2;
      }
      p_Var5 = local_c8[uVar6];
      fxPrim = FX_GetPrim(fxTracker);
      p_Var18 = local_40;
      if (fxPrim != (_FX_PRIM *)0x0) {
        if (fxSetup == (TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup)0x0) {
          (fxPrim->position).x = *(short *)(p_Var5->lwTransform).t;
          (fxPrim->position).y = *(short *)((p_Var5->lwTransform).t + 1);
          (fxPrim->position).z = *(short *)((p_Var5->lwTransform).t + 2);
          sVar3 = (fxPrim->position).z;
          local_88 = (fxPrim->position).x - (short)local_98;
          local_30[1] = (fxPrim->position).y - (short)local_94;
          local_30[2] = sVar3 - (short)local_90;
          (fxPrim->v0).x = p_Var14->x - local_88;
          (fxPrim->v0).y = (&p_Var14->x)[1] - local_86;
          (fxPrim->v0).z = (&p_Var14->x)[2] - local_84;
          (fxPrim->v1).x = p_Var16->x - local_88;
          (fxPrim->v1).y = (&p_Var16->x)[1] - local_86;
          (fxPrim->v1).z = (&p_Var16->x)[2] - local_84;
          (fxPrim->v2).x = p_Var17->x - local_88;
          (fxPrim->v2).y = (&p_Var17->x)[1] - local_86;
          sVar3 = (&p_Var17->x)[2];
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
            iVar12 = rand();
            iVar4 = iVar12;
            if (iVar12 < 0) {
              iVar4 = iVar12 + 7;
            }
            *(short *)&fxPrim->duo =
                 *(short *)&fxPrim->duo + -4 + (short)iVar12 + (short)(iVar4 >> 3) * -8;
            iVar12 = rand();
            iVar4 = iVar12;
            if (iVar12 < 0) {
              iVar4 = iVar12 + 7;
            }
            *(short *)((int)&fxPrim->duo + 2) =
                 *(short *)((int)&fxPrim->duo + 2) + -4 + (short)iVar12 + (short)(iVar4 >> 3) * -8;
            iVar12 = rand();
            iVar4 = iVar12;
            if (iVar12 < 0) {
              iVar4 = iVar12 + 7;
            }
            sVar3 = *(short *)((int)&fxPrim->duo + 4) + -4 +
                    (short)iVar12 + (short)(iVar4 >> 3) * -8;
LAB_800444a0:
            *(short *)((int)&fxPrim->duo + 4) = sVar3;
          }
          else {
            sVar3 = splintDef->triVelRng;
            if ((int)sVar3 != 0) {
              sVar1 = -splintDef->triVelRng;
              iVar4 = rand();
              iVar12 = ((int)sVar3 << 0x11) >> 0x10;
              *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + sVar1 + (short)(iVar4 % iVar12);
              iVar4 = rand();
              *(short *)((int)&fxPrim->duo + 2) =
                   *(short *)((int)&fxPrim->duo + 2) + sVar1 + (short)(iVar4 % iVar12);
              iVar4 = rand();
              sVar3 = *(short *)((int)&fxPrim->duo + 4) + sVar1 + (short)(iVar4 % iVar12);
              goto LAB_800444a0;
            }
          }
          if (vel != (SVECTOR *)0x0) {
            *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + vel->vx;
            *(short *)((int)&fxPrim->duo + 2) = *(short *)((int)&fxPrim->duo + 2) + vel->vy;
            *(short *)((int)&fxPrim->duo + 4) = *(short *)((int)&fxPrim->duo + 4) + vel->vz;
          }
          *(undefined2 *)((int)&fxPrim->duo + 6) = 0;
          *(undefined2 *)((int)&fxPrim->duo + 8) = 0;
          if (splintDef == (FXSplinter *)0x0) {
            *(undefined2 *)((int)&fxPrim->duo + 10) = 0xfff8;
            iVar12 = rand();
            iVar4 = iVar12;
            if (iVar12 < 0) {
              iVar4 = iVar12 + 7;
            }
            fxPrim->work3 = (short)iVar12 + (short)(iVar4 >> 3) * -8 + -4;
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
          fxPrim->timeToLive = (short)local_48;
          sVar3 = -0x7fff;
          if ((local_50 & 0x10) == 0) {
            sVar3 = (instance->position).z -
                    instance->object->modelList[instance->currentModel]->maxRad;
          }
          fxPrim->work0 = sVar3;
        }
        else {
          (*fxSetup)(fxPrim,fxProcess,p_Var5,instance,mface,local_38,center,vel,accl,fxTracker,0x1e)
          ;
        }
        LIST_InsertFunc(&fxTracker->usedPrimList,(NodeType *)fxPrim);
        p_Var18 = mface;
      }
      mface = p_Var18 + local_44;
    } while (mface < local_40);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _FX_BuildSplinters(struct _Instance *instance /*$s2*/, struct SVECTOR *center /*$s4*/, struct SVECTOR *vel /*$s5*/, struct SVECTOR *accl /*$s6*/, struct FXSplinter *splintDef /*stack 16*/, struct _FXTracker *fxTracker /*stack 20*/, TDRFuncPtr__FX_BuildSplinters6fxSetup fxSetup /*stack 24*/, TDRFuncPtr__FX_BuildSplinters7fxProcess fxProcess /*stack 28*/, int shardFlags /*stack 32*/)
 // line 1541, offset 0x80044648
	/* begin block 1 */
		// Start line: 3767
	/* end block 1 */
	// End Line: 3768

void _FX_BuildSplinters(_Instance *instance,SVECTOR *center,SVECTOR *vel,SVECTOR *accl,
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
 // line 1566, offset 0x8004479c
	/* begin block 1 */
		// Start line: 3818
	/* end block 1 */
	// End Line: 3819

void _FX_Build(_Instance *instance,SVECTOR *center,SVECTOR *vel,SVECTOR *accl,_FXTracker *fxTracker,
              TDRFuncPtr__FX_Build5fxSetup fxSetup,TDRFuncPtr__FX_Build6fxProcess fxProcess,
              int shardFlags)

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
 // line 1741, offset 0x800448b0
	/* begin block 1 */
		// Start line: 4172
	/* end block 1 */
	// End Line: 4173

void FX_Build(_Instance *instance,SVECTOR *center,SVECTOR *vel,SVECTOR *accl,_FXTracker *fxTracker,
             TDRFuncPtr_FX_Build5fxSetup fxSetup,TDRFuncPtr_FX_Build6fxProcess fxProcess)

{
  _FX_Build(instance,center,vel,accl,fxTracker,(TDRFuncPtr__FX_Build5fxSetup)fxSetup,
            (TDRFuncPtr__FX_Build6fxProcess)fxProcess,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdatePos(struct _FX_PRIM *fxPrim /*$t2*/, struct _SVector *offset /*$t3*/, int spriteflag /*$a2*/)
 // line 1747, offset 0x800448e8
	/* begin block 1 */
		// Start line: 1748
		// Start offset: 0x800448E8

		/* begin block 1.1 */
			// Start line: 1748
			// Start offset: 0x800448E8
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a0
		// 		short _x1; // $a3
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a1
		/* end block 1.1 */
		// End offset: 0x800448E8
		// End Line: 1748
	/* end block 1 */
	// End offset: 0x80044A34
	// End Line: 1764

	/* begin block 2 */
		// Start line: 4184
	/* end block 2 */
	// End Line: 4185

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
 // line 1767, offset 0x80044a3c
	/* begin block 1 */
		// Start line: 1768
		// Start offset: 0x80044A3C
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct _FXTracker *fxTracker; // $s2
	// 		struct _FXGeneralEffect *currentEffect; // $a2

		/* begin block 1.1 */
			// Start line: 1796
			// Start offset: 0x80044B00
			// Variables:
		// 		int i; // $a3
		// 		int end; // $t1
		// 		struct _FXRibbon *currentRibbon; // $t0
		/* end block 1.1 */
		// End offset: 0x80044B78
		// End Line: 1806

		/* begin block 1.2 */
			// Start line: 1809
			// Start offset: 0x80044B88
		/* end block 1.2 */
		// End offset: 0x80044BC4
		// End Line: 1813
	/* end block 1 */
	// End offset: 0x80044BD4
	// End Line: 1817

	/* begin block 2 */
		// Start line: 4225
	/* end block 2 */
	// End Line: 4226

void FX_Relocate(_SVector *offset)

{
  byte bVar1;
  short sVar2;
  _FXGeneralEffect *p_Var3;
  _FXTracker *p_Var4;
  short *psVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  _FX_PRIM *fxPrim;
  
  p_Var4 = gFXT;
  fxPrim = (_FX_PRIM *)(gFXT->usedPrimList).next;
  while (fxPrim != (_FX_PRIM *)0x0) {
    FX_UpdatePos(fxPrim,offset,0);
    fxPrim = (_FX_PRIM *)(fxPrim->node).next;
  }
  fxPrim = (_FX_PRIM *)(p_Var4->usedPrimListSprite).next;
  while (p_Var3 = FX_GeneralEffectTracker, fxPrim != (_FX_PRIM *)0x0) {
    FX_UpdatePos(fxPrim,offset,1);
    if ((code *)fxPrim->process == FX_WaterBubbleProcess) {
      fxPrim->timeToLive = fxPrim->timeToLive + offset->z;
    }
    fxPrim = (_FX_PRIM *)(fxPrim->node).next;
  }
  while (p_Var3 != (_FXGeneralEffect *)0x0) {
    bVar1 = p_Var3->effectType;
    iVar8 = 0;
    if (bVar1 == 0) {
      sVar2 = *(short *)&p_Var3[1].next;
      if ((int)(uint)bVar1 < (int)sVar2) {
        iVar7 = 0;
        do {
          psVar5 = (short *)(iVar7 + (int)p_Var3[1].continue_process);
          *psVar5 = *psVar5 + offset->x;
          iVar6 = iVar7 + (int)p_Var3[1].continue_process;
          *(short *)(iVar6 + 2) = *(short *)(iVar6 + 2) + offset->y;
          iVar7 = iVar7 + (int)p_Var3[1].continue_process;
          iVar8 = iVar8 + 1;
          *(short *)(iVar7 + 4) = *(short *)(iVar7 + 4) + offset->z;
          iVar7 = iVar8 * 8;
        } while (iVar8 < (int)sVar2);
      }
    }
    else {
      if (bVar1 == 0x84) {
        *(short *)&p_Var3[1].next = *(short *)&p_Var3[1].next + offset->x;
        *(short *)((int)&p_Var3[1].next + 2) = *(short *)((int)&p_Var3[1].next + 2) + offset->y;
        *(short *)&p_Var3[1].continue_process = *(short *)&p_Var3[1].continue_process + offset->z;
      }
    }
    p_Var3 = (_FXGeneralEffect *)p_Var3->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdateTexturePointers(struct _FX_PRIM *fxPrim /*$a0*/, struct Object *oldObject /*$a1*/, long sizeOfObject /*$a2*/, long offset /*$a3*/)
 // line 1822, offset 0x80044bec
	/* begin block 1 */
		// Start line: 4352
	/* end block 1 */
	// End Line: 4353

	/* begin block 2 */
		// Start line: 4353
	/* end block 2 */
	// End Line: 4354

void FX_UpdateTexturePointers(_FX_PRIM *fxPrim,Object *oldObject,long sizeOfObject,long offset)

{
  TextureMT3 *pTVar1;
  Object *pOVar2;
  
  if (fxPrim != (_FX_PRIM *)0x0) {
    do {
      if ((fxPrim->flags & 1U) != 0) {
        pOVar2 = (Object *)fxPrim->texture;
        if ((oldObject <= pOVar2) && (pOVar2 <= (Object *)((int)&oldObject->oflags + sizeOfObject)))
        {
          pTVar1 = (TextureMT3 *)0x0;
          if (pOVar2 != (Object *)0x0) {
            pTVar1 = (TextureMT3 *)((int)&pOVar2->oflags + offset);
          }
          fxPrim->texture = pTVar1;
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
 // line 1842, offset 0x80044c4c
	/* begin block 1 */
		// Start line: 1843
		// Start offset: 0x80044C4C
		// Variables:
	// 		struct _FXTracker *fxTracker; // $s0
	// 		struct _FXGeneralEffect *currentEffect; // $a0
	// 		long offset; // $s1

		/* begin block 1.1 */
			// Start line: 1862
			// Start offset: 0x80044CC0
		/* end block 1.1 */
		// End offset: 0x80044CF0
		// End Line: 1865
	/* end block 1 */
	// End offset: 0x80044D00
	// End Line: 1868

	/* begin block 2 */
		// Start line: 4392
	/* end block 2 */
	// End Line: 4393

void FX_RelocateFXPointers(Object *oldObject,Object *newObject,long sizeOfObject)

{
  _FXTracker *p_Var1;
  void *pvVar2;
  Object *pOVar3;
  _FXGeneralEffect *p_Var4;
  
  p_Var1 = gFXT;
  newObject = (Object *)((int)newObject - (int)oldObject);
  FX_UpdateTexturePointers
            ((_FX_PRIM *)(gFXT->usedPrimList).next,oldObject,sizeOfObject,(long)newObject);
  FX_UpdateTexturePointers
            ((_FX_PRIM *)(p_Var1->usedPrimListSprite).next,oldObject,sizeOfObject,(long)newObject);
  if (FX_GeneralEffectTracker != (_FXGeneralEffect *)0x0) {
    p_Var4 = FX_GeneralEffectTracker;
    do {
      if (p_Var4->effectType == '\x01') {
        pOVar3 = (Object *)p_Var4[1].next;
        if (((pOVar3 != (Object *)0x0) && (oldObject <= pOVar3)) &&
           (pOVar3 <= (Object *)((int)&oldObject->oflags + sizeOfObject))) {
          pvVar2 = (void *)0x0;
          if (pOVar3 != (Object *)0x0) {
            pvVar2 = (void *)((int)pOVar3 + (int)newObject);
          }
          p_Var4[1].next = pvVar2;
        }
      }
      p_Var4 = (_FXGeneralEffect *)p_Var4->next;
    } while (p_Var4 != (_FXGeneralEffect *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ProcessList(struct _FXTracker *fxTracker /*$s2*/)
 // line 1872, offset 0x80044d1c
	/* begin block 1 */
		// Start line: 1873
		// Start offset: 0x80044D1C
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $a0
	// 		struct _FX_PRIM *nextFXPrim; // $s0
	// 		struct _FX_MATRIX *fxMatrix; // $s0
	// 		struct _FX_MATRIX *nextFXMatrix; // $s1

		/* begin block 1.1 */
			// Start line: 1943
			// Start offset: 0x80044E90
			// Variables:
		// 		struct _FXGeneralEffect *currentEffect; // $a0
		// 		struct _FXGeneralEffect *nextEffect; // $s0
		/* end block 1.1 */
		// End offset: 0x80044EB4
		// End Line: 1953
	/* end block 1 */
	// End offset: 0x80044EF8
	// End Line: 1960

	/* begin block 2 */
		// Start line: 4463
	/* end block 2 */
	// End Line: 4464

	/* begin block 3 */
		// Start line: 4476
	/* end block 3 */
	// End Line: 4477

void FX_ProcessList(_FXTracker *fxTracker)

{
  _FXGeneralEffect *p_Var1;
  int iVar2;
  NodeType *node;
  NodeType *pNVar3;
  NodeType *pNVar4;
  _FXGeneralEffect *p_Var5;
  
  iVar2 = (int)(((uint)(ushort)FX_TimeCount + (uint)(ushort)gameTrackerX.timeMult) * 0x10000) >>
          0x10;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  FX_Frames = (short)(iVar2 >> 0xc);
  pNVar4 = (fxTracker->usedMatrixList).next;
  FX_TimeCount = (short)((uint)(ushort)FX_TimeCount + (uint)(ushort)gameTrackerX.timeMult) +
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
  while (node = pNVar4, p_Var5 = FX_GeneralEffectTracker, node != (NodeType *)0x0) {
    pNVar4 = node->next;
    if (((uint)node[1].prev & 1) == 0) {
      LIST_DeleteFunc(node);
      LIST_InsertFunc(&fxTracker->freeMatrixList,node);
    }
  }
  while (p_Var1 = p_Var5, p_Var1 != (_FXGeneralEffect *)0x0) {
    p_Var5 = (_FXGeneralEffect *)p_Var1->next;
    if ((code *)p_Var1->continue_process != (code *)0x0) {
      (*(code *)p_Var1->continue_process)(p_Var1,fxTracker);
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
 // line 1963, offset 0x80044f18
	/* begin block 1 */
		// Start line: 4668
	/* end block 1 */
	// End Line: 4669

void FX_DrawReaver(_PrimPool *primPool,ulong **ot,MATRIX *wcTransform)

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
 // line 1985, offset 0x80044f64
	/* begin block 1 */
		// Start line: 1986
		// Start offset: 0x80044F64
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
	// 		int sizey; // $t4
	// 		int matrix_wc; // $t2

		/* begin block 1.1 */
			// Start line: 2007
			// Start offset: 0x80044FE8
			// Variables:
		// 		long flags; // $s3

			/* begin block 1.1.1 */
				// Start line: 2095
				// Start offset: 0x800452D4
				// Variables:
			// 		struct _POLY_NG4 *ng4; // $a2

				/* begin block 1.1.1.1 */
					// Start line: 2097
					// Start offset: 0x800452D4
					// Variables:
				// 		int n; // $a0
				// 		long *ptr; // $a1
				/* end block 1.1.1.1 */
				// End offset: 0x80045394
				// End Line: 2122
			/* end block 1.1.1 */
			// End offset: 0x80045394
			// End Line: 2144

			/* begin block 1.1.2 */
				// Start line: 2161
				// Start offset: 0x800453CC
			/* end block 1.1.2 */
			// End offset: 0x800453CC
			// End Line: 2163

			/* begin block 1.1.3 */
				// Start line: 2251
				// Start offset: 0x8004554C
				// Variables:
			// 		struct POLY_FT4 *ft4; // $a2
			// 		unsigned short uMin; // $t1
			// 		unsigned short uMax; // $t0
			// 		unsigned short vMin; // $a3
			// 		unsigned short vMax; // $v1
			/* end block 1.1.3 */
			// End offset: 0x80045798
			// End Line: 2282

			/* begin block 1.1.4 */
				// Start line: 2289
				// Start offset: 0x800457D4
				// Variables:
			// 		struct POLY_FT3 *ft3; // $t0

				/* begin block 1.1.4.1 */
					// Start line: 2302
					// Start offset: 0x80045820
					// Variables:
				// 		short uMin; // $a3
				// 		short uMax; // $a2
				/* end block 1.1.4.1 */
				// End offset: 0x80045924
				// End Line: 2310
			/* end block 1.1.4 */
			// End offset: 0x80045960
			// End Line: 2316
		/* end block 1.1 */
		// End offset: 0x80045960
		// End Line: 2320

		/* begin block 1.2 */
			// Start line: 2331
			// Start offset: 0x800459A0
			// Variables:
		// 		struct DVECTOR xy_pos; // stack offset -72
		// 		long flags; // $t2

			/* begin block 1.2.1 */
				// Start line: 2400
				// Start offset: 0x80045BDC
				// Variables:
			// 		struct _POLY_SG4 *sg4; // $a1

				/* begin block 1.2.1.1 */
					// Start line: 2402
					// Start offset: 0x80045BDC
					// Variables:
				// 		int n; // $a3
				// 		long *src; // $t2
				// 		long *dst; // $t1
				// 		long *ptr; // $t3
				/* end block 1.2.1.1 */
				// End offset: 0x80045CD4
				// End Line: 2433
			/* end block 1.2.1 */
			// End offset: 0x80045CD4
			// End Line: 2455

			/* begin block 1.2.2 */
				// Start line: 2467
				// Start offset: 0x80045D68
			/* end block 1.2.2 */
			// End offset: 0x80045D68
			// End Line: 2471

			/* begin block 1.2.3 */
				// Start line: 2499
				// Start offset: 0x80045E40
				// Variables:
			// 		unsigned short uMin; // $t3
			// 		unsigned short uMax; // $t1
			// 		unsigned short vMin; // $a3
			// 		unsigned short vMax; // $v1
			// 		struct POLY_FT4 *ft4; // $a2
			/* end block 1.2.3 */
			// End offset: 0x800460AC
			// End Line: 2537
		/* end block 1.2 */
		// End offset: 0x80046118
		// End Line: 2556
	/* end block 1 */
	// End offset: 0x80046124
	// End Line: 2560

	/* begin block 2 */
		// Start line: 4713
	/* end block 2 */
	// End Line: 4714

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Could not reconcile some variable overlaps */

void FX_DrawList(_FXTracker *fxTracker,GameTracker *gameTracker,ulong **ot,MATRIX *wcTransform)

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
  ushort uVar20;
  uint *puVar21;
  uint *puVar22;
  undefined4 uVar23;
  int iVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  NodeType *pNVar27;
  uint *puVar28;
  uint *puVar29;
  NodeType **ppNVar30;
  NodeType *pNVar31;
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
  
  bVar4 = false;
  primPool = gameTracker->primPool;
  puVar28 = primPool->nextPrim;
  local_4e = 0x1f;
  local_4f = 0x1f;
  local_50 = 0x1f;
  pNVar27 = (fxTracker->usedPrimList).next;
  if (pNVar27 != (NodeType *)0x0) {
    ppNVar30 = (NodeType **)(puVar28 + 1);
    do {
      if (primPool->lastPrim <= puVar28 + 10) break;
      pNVar31 = pNVar27[1].next;
      pNVar32 = pNVar27->next;
      if (((uint)pNVar31 & 0x10) == 0) {
        if (((uint)pNVar31 & 0x10000) == 0) {
          pNVar27[3].prev[4].prev = (NodeType *)(int)*(short *)&pNVar27[5].next;
          pNVar27[3].prev[4].next = (NodeType *)(int)*(short *)((int)&pNVar27[5].next + 2);
          pNVar27[3].prev[5].prev = (NodeType *)(int)*(short *)&pNVar27[6].prev;
          gameTracker = (GameTracker *)&pNVar27[3].prev[1].next;
          CompMatrix((undefined4 *)wcTransform,(ushort *)gameTracker,&DAT_1f800000);
          SetRotMatrix(&DAT_1f800000);
          SetTransMatrix(0x1f800000);
          bVar4 = false;
        }
        else {
          if (!bVar4) {
            setCopControlWord(2,0,*(undefined4 *)wcTransform->m);
            setCopControlWord(2,0x800,*(undefined4 *)(wcTransform->m + 2));
            setCopControlWord(2,0x1000,*(undefined4 *)(wcTransform->m + 4));
            setCopControlWord(2,0x1800,*(undefined4 *)(wcTransform->m + 6));
            setCopControlWord(2,0x2000,*(undefined4 *)(wcTransform->m + 8));
            setCopControlWord(2,0x2800,wcTransform->t[0]);
            setCopControlWord(2,0x3000,wcTransform->t[1]);
            setCopControlWord(2,0x3800,wcTransform->t[2]);
            bVar4 = true;
          }
        }
        if (((uint)pNVar31 & 0x2000) == 0) {
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
        if (((uint)pNVar31 & 0x1000000) == 0) {
          if (((uint)pNVar31 & 0x4000) == 0) {
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
        if (((uint)pNVar31 & 0x8000) != 0) {
          local_34 = local_34 + -0x14;
        }
        if (local_34 - 1U < 0xbff) {
          if (((uint)pNVar31 & 1) == 0) {
            if (((uint)pNVar31 & 8) == 0) {
              if (((uint)pNVar31 & 0x1000000) == 0) {
                *ppNVar30 = pNVar27[3].next;
                uVar9 = getCopReg(2,0xc);
                puVar28[2] = uVar9;
                uVar9 = getCopReg(2,0xd);
                puVar28[3] = uVar9;
                uVar9 = getCopReg(2,0xe);
                puVar28[4] = uVar9;
                ppNVar30 = ppNVar30 + 5;
                *puVar28 = (uint)ot[local_34] & 0xffffff | 0x4000000;
                puVar29 = puVar28 + 5;
              }
              else {
                if (((uint)pNVar31 & 0x80000) == 0) goto LAB_80045960;
                ppNVar30[1] = pNVar27[3].next;
                pNVar27 = pNVar27[4].next;
                *ppNVar30 = (NodeType *)0xe1000620;
                ppNVar30[3] = pNVar27;
                uVar9 = getCopReg(2,0xc);
                puVar28[5] = uVar9;
                uVar9 = getCopReg(2,0xd);
                puVar28[3] = uVar9;
                *(undefined *)((int)ppNVar30 + 7) = 0x52;
                ppNVar30 = ppNVar30 + 6;
                *puVar28 = (uint)ot[local_34] & 0xffffff | 0x5000000;
                puVar29 = puVar28 + 6;
              }
            }
            else {
              if (((uint)pNVar31 & 0x80000) != 0) {
                uVar9 = getCopReg(2,0xc);
                puVar28[3] = uVar9;
                uVar9 = getCopReg(2,0xd);
                puVar28[5] = uVar9;
                uVar9 = getCopReg(2,0xe);
                puVar28[7] = uVar9;
                setCopReg(2,in_zero,pNVar27[10].next);
                setCopReg(2,in_at,pNVar27[0xb].prev);
                copFunction(2,0x180001);
                *ppNVar30 = (NodeType *)0xe1000620;
                uVar9 = getCopReg(2,0xe);
                puVar28[9] = uVar9;
                gameTracker = (GameTracker *)(puVar28 + 2);
                iVar16 = 0;
                pNVar31 = pNVar27;
                do {
                  setCopReg(2,0x4000,0x1000 - (int)*(short *)&pNVar31[6].next);
                  setCopReg(2,0x4800,(uint)*(byte *)&pNVar27[3].next);
                  setCopReg(2,0x5000,(uint)*(byte *)((int)&pNVar27[3].next + 1));
                  setCopReg(2,0x5800,(uint)*(byte *)((int)&pNVar27[3].next + 2));
                  copFunction(2,0x198003d);
                  uVar23 = getCopReg(2,0x4800);
                  uVar25 = getCopReg(2,0x5000);
                  uVar26 = getCopReg(2,0x5800);
                  *(char *)&(gameTracker->gameData).asmData.drawBackFaces = (char)uVar23;
                  *(undefined *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1) =
                       (char)uVar25;
                  *(undefined *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 2) =
                       (char)uVar26;
                  gameTracker = (GameTracker *)&(gameTracker->gameData).asmData.MorphTime;
                  iVar16 = iVar16 + 1;
                  pNVar31 = (NodeType *)((int)&pNVar31->prev + 2);
                } while (iVar16 < 4);
                *puVar28 = (uint)ot[local_34] & 0xffffff | 0x9000000;
                ot[local_34] = (ulong *)((uint)puVar28 & 0xffffff);
                *(undefined *)((int)puVar28 + 0xb) = 0x3a;
                puVar28 = puVar28 + 10;
                ppNVar30 = ppNVar30 + 10;
                goto LAB_80045960;
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
              *ppNVar30 = pNVar27[3].next;
              ppNVar30[2] = pNVar27[3].next;
              ppNVar30[4] = pNVar27[3].next;
              pNVar27 = pNVar27[3].next;
              *(undefined *)((int)ppNVar30 + -1) = 8;
              *(undefined *)((int)ppNVar30 + 3) = 0x38;
              ppNVar30[6] = pNVar27;
              uVar9 = getCopReg(2,0xe);
              puVar28[8] = uVar9;
              ppNVar30 = ppNVar30 + 9;
              *puVar28 = (uint)ot[local_34] & 0xffffff | 0x8000000;
              puVar29 = puVar28 + 9;
            }
          }
          else {
            gameTracker = (GameTracker *)pNVar27[1].prev;
            if (((uint)pNVar31 & 8) == 0) {
              uVar9 = getCopReg(2,0xc);
              puVar28[2] = uVar9;
              uVar9 = getCopReg(2,0xd);
              puVar28[4] = uVar9;
              uVar9 = getCopReg(2,0xe);
              puVar28[6] = uVar9;
              ppNVar30[2] = (NodeType *)(gameTracker->gameData).asmData.drawBackFaces;
              ppNVar30[4] = (NodeType *)(gameTracker->gameData).asmData.dispPage;
              ppNVar30[6] = *(NodeType **)&(gameTracker->gameData).asmData.MorphTime;
              if (((uint)pNVar31 & 0x1000) != 0) {
                bVar15 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                bVar14 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
                if (bVar15 < bVar14) {
                  bVar3 = bVar14 < bVar15;
                  if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar15) {
LAB_80045878:
                    cVar12 = *(char *)&(gameTracker->gameData).asmData.MorphTime;
                    goto LAB_8004587c;
                  }
                  cVar12 = *(char *)&(gameTracker->gameData).asmData.drawBackFaces;
                }
                else {
                  if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar14)
                  goto LAB_80045878;
                  cVar12 = *(char *)&(gameTracker->gameData).asmData.dispPage;
LAB_8004587c:
                  bVar15 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                  bVar14 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
                  bVar3 = bVar14 < bVar15;
                }
                if (bVar3) {
                  if (*(byte *)&(gameTracker->gameData).asmData.MorphTime < bVar15) {
                    cVar19 = *(char *)&(gameTracker->gameData).asmData.drawBackFaces;
                  }
                  else {
LAB_800458d4:
                    cVar19 = *(char *)&(gameTracker->gameData).asmData.MorphTime;
                  }
                }
                else {
                  if (bVar14 <= *(byte *)&(gameTracker->gameData).asmData.MorphTime)
                  goto LAB_800458d4;
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
              *ppNVar30 = pNVar27[3].next;
              ppNVar30 = ppNVar30 + 8;
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
LAB_800455d4:
                  bVar1 = *(byte *)&(gameTracker->gameData).asmData.MorphTime;
                  goto LAB_800455d8;
                }
                bVar1 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
              }
              else {
                if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar14)
                goto LAB_800455d4;
                bVar1 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
LAB_800455d8:
                bVar15 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                bVar14 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
                bVar3 = bVar14 < bVar15;
              }
              if (bVar3) {
                if (*(byte *)&(gameTracker->gameData).asmData.MorphTime < bVar15) {
                  uVar20 = (ushort)*(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                }
                else {
LAB_80045630:
                  uVar20 = (ushort)*(byte *)&(gameTracker->gameData).asmData.MorphTime;
                }
              }
              else {
                if (bVar14 <= *(byte *)&(gameTracker->gameData).asmData.MorphTime)
                goto LAB_80045630;
                uVar20 = (ushort)*(byte *)&(gameTracker->gameData).asmData.dispPage;
              }
              bVar15 = *(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1);
              bVar14 = *(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1);
              if (bVar15 < bVar14) {
                if (*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) <= bVar15) {
LAB_8004568c:
                  bVar2 = *(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1);
                  goto LAB_80045698;
                }
                bVar2 = *(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1);
              }
              else {
                if (*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) <= bVar14)
                goto LAB_8004568c;
                bVar2 = *(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1);
LAB_80045698:
                bVar15 = *(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1);
                bVar14 = *(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1);
              }
              if (bVar14 < bVar15) {
                if (*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) < bVar15) {
                  uVar13 = (ushort)*(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1
                                            ) << 8;
                }
                else {
LAB_800456f0:
                  uVar13 = (ushort)*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) <<
                           8;
                }
              }
              else {
                if (bVar14 <= *(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1))
                goto LAB_800456f0;
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
              if (((uint)pNVar31 & 0x1000) != 0) {
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
              *ppNVar30 = pNVar27[3].next;
              ppNVar30 = ppNVar30 + 10;
              *puVar28 = (uint)ot[local_34] & 0xffffff | 0x9000000;
              puVar29 = puVar28 + 10;
            }
          }
          ot[local_34] = (ulong *)((uint)puVar28 & 0xffffff);
          puVar28 = puVar29;
        }
      }
LAB_80045960:
      pNVar27 = pNVar32;
    } while (pNVar32 != (NodeType *)0x0);
  }
  SetRotMatrix((undefined4 *)wcTransform);
  SetTransMatrix((int)wcTransform);
  pNVar27 = (fxTracker->usedPrimListSprite).next;
  puVar29 = puVar28;
joined_r0x8004598c:
  do {
    do {
      pNVar31 = pNVar27;
      if (pNVar31 == (NodeType *)0x0) {
LAB_80046124:
        primPool->nextPrim = puVar28;
        FX_DrawAllGeneralEffects(wcTransform,gameTrackerX.vertexPool,primPool,ot);
        return;
      }
      local_30 = (int)*(short *)&pNVar31[7].next << 1;
      setCopReg(2,in_zero,pNVar31[5].next);
      setCopReg(2,in_at,pNVar31[6].prev);
      setCopControlWord(2,0xe000,0);
      setCopControlWord(2,0xd800,local_30);
      copFunction(2,0x180001);
      pNVar27 = pNVar31->next;
      pNVar32 = pNVar31[1].next;
      if (primPool->lastPrim <= puVar28 + 10) goto LAB_80046124;
    } while (((uint)pNVar32 & 0x10) != 0);
    local_48 = getCopReg(2,0xe);
    local_30 = getCopReg(2,0x18);
    local_40 = (GameTracker *)getCopReg(2,0x13);
    iVar16 = (int)local_40 >> 2;
    local_34 = iVar16;
    if ((((((uint)pNVar32 & 0x2008000) != 0) &&
         (local_34 = iVar16 + -0x14, ((uint)pNVar32 & 0x8000) == 0)) &&
        (local_34 = iVar16, ((uint)pNVar32 & 0x2000000) != 0)) && (0x32 < iVar16)) {
      local_34 = 0xbff;
    }
    if ((((uint)pNVar32 & 0x800000) != 0) &&
       (&UNK_00000e7f < (undefined *)((int)local_40 + 0xfffffe80U))) {
      local_34 = 0;
    }
    if (local_34 - 0x33U < 0xbcd) {
      local_48._2_2_ = (short)((uint)local_48 >> 0x10);
      if ((((uint)pNVar32 & 0x4000000) != 0) ||
         (((-1 < (short)local_48 && (-1 < local_48)) &&
          (((short)local_48 < 0x200 && (local_48._2_2_ < 0xf0)))))) {
        if ((((uint)pNVar32 & 0x2000) == 0) ||
           (iVar16 = (int)*(short *)((int)&pNVar31[7].next + 2), iVar16 == 0x1000)) {
          iVar16 = local_30;
          if ((int)*(short *)&pNVar31[7].next != (int)*(short *)&pNVar31[8].prev) {
            iVar16 = ((int)*(short *)&pNVar31[8].prev * 0x2800000) / (int)local_40;
          }
        }
        else {
          local_30 = (local_30 >> 0xc) * iVar16;
          iVar16 = local_30;
          if ((int)*(short *)&pNVar31[7].next != (int)*(short *)&pNVar31[8].prev) {
            iVar16 = ((int)*(short *)&pNVar31[8].prev *
                     (int)*(short *)((int)&pNVar31[7].next + 2) * 0x280) / (int)local_40 << 4;
          }
        }
        iVar16 = iVar16 + 0xffff;
        iVar24 = iVar16 >> 0x10;
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
              local_48._2_2_ = local_48._2_2_ - (short)(iVar24 - iVar6 >> 1);
              *(short *)((int)puVar29 + 0x12) = local_48._2_2_;
              *(short *)((int)puVar29 + 10) = local_48._2_2_;
              *(short *)((int)puVar29 + 0x22) = local_48._2_2_ + sVar7;
              *(short *)((int)puVar29 + 0x1a) = local_48._2_2_ + sVar7;
              *(short *)(puVar29 + 8) = *(short *)(puVar29 + 2) + (short)local_30;
              *(short *)(puVar29 + 4) = *(short *)(puVar29 + 2) + (short)local_30;
              *(NodeType **)(puVar29 + 1) = pNVar31[3].next;
              *(NodeType **)(puVar29 + 3) = pNVar31[3].next;
              *(NodeType **)(puVar29 + 5) = pNVar31[3].next;
              pNVar31 = pNVar31[3].next;
              *(undefined *)((int)puVar29 + 3) = 8;
              *(undefined *)((int)puVar29 + 7) = 0x38;
              *(NodeType **)(puVar29 + 7) = pNVar31;
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
              local_48._2_2_ = local_48._2_2_ - (short)(iVar24 - iVar6 >> 1);
              *(short *)((int)puVar29 + 0x16) = local_48._2_2_;
              *(short *)((int)puVar29 + 0xe) = local_48._2_2_;
              *(short *)((int)puVar29 + 0x26) = local_48._2_2_ + sVar7;
              *(short *)((int)puVar29 + 0x1e) = local_48._2_2_ + sVar7;
              *(short *)(puVar29 + 9) = *(short *)(puVar29 + 3) + (short)local_30;
              *(short *)(puVar29 + 5) = *(short *)(puVar29 + 3) + (short)local_30;
              puVar5 = puVar29;
              do {
                setCopReg(2,0x4000,0x1000 - (int)*(short *)&pNVar31[6].next);
                setCopReg(2,0x4800,(uint)*(byte *)&pNVar31[3].next);
                setCopReg(2,0x5000,(uint)*(byte *)((int)&pNVar31[3].next + 1));
                setCopReg(2,0x5800,(uint)*(byte *)((int)&pNVar31[3].next + 2));
                copFunction(2,0x198003d);
                uVar9 = *puVar22;
                puVar22 = puVar22 + 2;
                *puVar21 = uVar9;
                puVar21 = puVar21 + 1;
                uVar23 = getCopReg(2,0x4800);
                uVar25 = getCopReg(2,0x5000);
                uVar26 = getCopReg(2,0x5800);
                *(char *)(puVar5 + 2) = (char)uVar23;
                *(undefined *)((int)puVar5 + 9) = (char)uVar25;
                *(undefined *)((int)puVar5 + 10) = (char)uVar26;
                iVar16 = iVar16 + 1;
                puVar5 = puVar5 + 2;
              } while (iVar16 < 4);
              setCopReg(2,0x4000,0x1000 - (int)*(short *)&pNVar31[6].next);
              setCopReg(2,0x4800,(uint)local_50);
              setCopReg(2,0x5000,(uint)local_4f);
              setCopReg(2,0x5800,(uint)local_4e);
              copFunction(2,0x198003d);
              *puVar29 = (uint)ot[local_34] & 0xffffff | 0xf000000;
              ot[local_34] = (ulong *)((uint)puVar29 & 0xffffff);
              uVar23 = getCopReg(2,0x4800);
              uVar25 = getCopReg(2,0x5000);
              uVar26 = getCopReg(2,0x5800);
              *(char *)(puVar29 + 0xb) = (char)uVar23;
              *(undefined *)((int)puVar29 + 0x2d) = (char)uVar25;
              *(undefined *)((int)puVar29 + 0x2e) = (char)uVar26;
              *(undefined *)((int)puVar29 + 0xb) = 0x3a;
              *(undefined *)((int)puVar29 + 0x2f) = 0x2a;
              puVar29 = puVar29 + 0x10;
            }
          }
        }
        else {
          pNVar18 = pNVar31[1].prev;
          if (((uint)pNVar32 & 8) != 0) {
            bVar15 = *(byte *)&pNVar18->prev;
            bVar14 = *(byte *)&pNVar18->next;
            if (bVar15 < bVar14) {
              bVar4 = bVar14 < bVar15;
              if (*(byte *)&pNVar18[1].prev <= bVar15) {
LAB_80045e98:
                bVar1 = *(byte *)&pNVar18[1].prev;
                goto LAB_80045e9c;
              }
              bVar1 = *(byte *)&pNVar18->prev;
            }
            else {
              if (*(byte *)&pNVar18[1].prev <= bVar14) goto LAB_80045e98;
              bVar1 = *(byte *)&pNVar18->next;
LAB_80045e9c:
              bVar15 = *(byte *)&pNVar18->prev;
              bVar14 = *(byte *)&pNVar18->next;
              bVar4 = bVar14 < bVar15;
            }
            if (bVar4) {
              if (*(byte *)&pNVar18[1].prev < bVar15) {
                uVar20 = (ushort)*(byte *)&pNVar18->prev;
              }
              else {
LAB_80045ef4:
                uVar20 = (ushort)*(byte *)&pNVar18[1].prev;
              }
            }
            else {
              if (bVar14 <= *(byte *)&pNVar18[1].prev) goto LAB_80045ef4;
              uVar20 = (ushort)*(byte *)&pNVar18->next;
            }
            bVar15 = *(byte *)((int)&pNVar18->prev + 1);
            bVar14 = *(byte *)((int)&pNVar18->next + 1);
            if (bVar15 < bVar14) {
              if (*(byte *)((int)&pNVar18[1].prev + 1) <= bVar15) {
LAB_80045f50:
                bVar2 = *(byte *)((int)&pNVar18[1].prev + 1);
                goto LAB_80045f5c;
              }
              bVar2 = *(byte *)((int)&pNVar18->prev + 1);
            }
            else {
              if (*(byte *)((int)&pNVar18[1].prev + 1) <= bVar14) goto LAB_80045f50;
              bVar2 = *(byte *)((int)&pNVar18->next + 1);
LAB_80045f5c:
              bVar15 = *(byte *)((int)&pNVar18->prev + 1);
              bVar14 = *(byte *)((int)&pNVar18->next + 1);
            }
            if (bVar14 < bVar15) {
              if (*(byte *)((int)&pNVar18[1].prev + 1) < bVar15) {
                uVar13 = (ushort)*(byte *)((int)&pNVar18->prev + 1) << 8;
              }
              else {
LAB_80045fb4:
                uVar13 = (ushort)*(byte *)((int)&pNVar18[1].prev + 1) << 8;
              }
            }
            else {
              if (bVar14 <= *(byte *)((int)&pNVar18[1].prev + 1)) goto LAB_80045fb4;
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
            local_48._2_2_ = local_48._2_2_ + (short)(iVar24 - iVar6 >> 1);
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
            *(NodeType **)(puVar29 + 1) = pNVar31[3].next;
            puVar29 = puVar29 + 10;
            puVar10 = (ulong *)((uint)puVar28 & 0xffffff);
            *puVar28 = (uint)ot[local_34] & 0xffffff | 0x9000000;
            puVar28 = puVar28 + 10;
            ot[local_34] = puVar10;
          }
        }
        goto joined_r0x8004598c;
      }
    }
    if (((uint)pNVar32 & 0x400000) == 0) {
      if (((uint)pNVar32 & 0x800000) != 0) {
        *(undefined2 *)((int)&pNVar31[8].prev + 2) = 9999;
      }
    }
    else {
      *(undefined2 *)&pNVar31[2].prev = 1;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SimpleQuadSetup(struct _FX_PRIM *fxPrim /*$s5*/, TDRFuncPtr_FX_SimpleQuadSetup1fxProcess fxProcess /*stack 4*/, struct _FX_MATRIX *fxMatrix /*stack 8*/, struct _Instance *instance /*$a3*/, struct _MFace *mface /*stack 16*/, struct _MVertex *vertexList /*stack 20*/, struct SVECTOR *center /*stack 24*/, struct SVECTOR *vel /*stack 28*/, struct SVECTOR *accl /*stack 32*/, struct _FXTracker *fxTracker /*stack 36*/, int timeToLive /*stack 40*/)
 // line 2727, offset 0x8004616c
	/* begin block 1 */
		// Start line: 2728
		// Start offset: 0x8004616C
		// Variables:
	// 		struct _MVertex *vertex1; // $s2
	// 		struct _MVertex *vertex2; // $s3
	// 		struct _MVertex *vertex3; // $s4

		/* begin block 1.1 */
			// Start line: 2728
			// Start offset: 0x8004616C
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _Position *_v0; // $v0
		/* end block 1.1 */
		// End offset: 0x8004616C
		// End Line: 2728

		/* begin block 1.2 */
			// Start line: 2728
			// Start offset: 0x8004616C
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $v0
		/* end block 1.2 */
		// End offset: 0x8004616C
		// End Line: 2728

		/* begin block 1.3 */
			// Start line: 2728
			// Start offset: 0x8004616C
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $v0
		/* end block 1.3 */
		// End offset: 0x8004616C
		// End Line: 2728

		/* begin block 1.4 */
			// Start line: 2728
			// Start offset: 0x8004616C
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $v0
		/* end block 1.4 */
		// End offset: 0x8004616C
		// End Line: 2728

		/* begin block 1.5 */
			// Start line: 2728
			// Start offset: 0x8004616C
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $v0
		/* end block 1.5 */
		// End offset: 0x8004616C
		// End Line: 2728
	/* end block 1 */
	// End offset: 0x80046364
	// End Line: 2792

	/* begin block 2 */
		// Start line: 5454
	/* end block 2 */
	// End Line: 5455

void FX_SimpleQuadSetup(_FX_PRIM *fxPrim,TDRFuncPtr_FX_SimpleQuadSetup1fxProcess fxProcess,
                       _FX_MATRIX *fxMatrix,_Instance *instance,_MFace *mface,_MVertex *vertexList,
                       SVECTOR *center,SVECTOR *vel,SVECTOR *accl,_FXTracker *fxTracker,
                       int timeToLive)

{
  short sVar1;
  short sVar2;
  TextureMT3 *pTVar3;
  uint uVar4;
  uint uVar5;
  
  MATH3D_SetUnityMatrix(&fxMatrix->lwTransform);
  sVar1 = center->vy;
  sVar2 = center->vz;
  (fxPrim->position).x = center->vx;
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
  if (vel == (SVECTOR *)0x0) {
    *(undefined2 *)&fxPrim->duo = 0;
    *(undefined2 *)((int)&fxPrim->duo + 2) = 0;
    *(undefined2 *)((int)&fxPrim->duo + 4) = 0;
  }
  else {
    *(short *)&fxPrim->duo = vel->vx;
    *(short *)((int)&fxPrim->duo + 2) = vel->vy;
    *(short *)((int)&fxPrim->duo + 4) = vel->vz;
  }
  if (accl == (SVECTOR *)0x0) {
    *(undefined2 *)((int)&fxPrim->duo + 6) = 0;
    *(undefined2 *)((int)&fxPrim->duo + 8) = 0;
    *(undefined2 *)((int)&fxPrim->duo + 10) = 0;
  }
  else {
    *(short *)((int)&fxPrim->duo + 6) = accl->vx;
    *(short *)((int)&fxPrim->duo + 8) = accl->vy;
    *(short *)((int)&fxPrim->duo + 10) = accl->vz;
  }
  fxPrim->timeToLive = (short)timeToLive;
  fxPrim->flags = fxPrim->flags | 0x4000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_WaterRingProcess(struct _FX_PRIM *fxPrim /*$a0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 2796, offset 0x800463a8
	/* begin block 1 */
		// Start line: 6929
	/* end block 1 */
	// End Line: 6930

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
// void /*$ra*/ FX_WaterBubbleProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$s2*/)
 // line 2806, offset 0x80046424
	/* begin block 1 */
		// Start line: 2807
		// Start offset: 0x80046424
		// Variables:
	// 		struct _FX_PRIM *temp; // $a1

		/* begin block 1.1 */
			// Start line: 2833
			// Start offset: 0x80046508
			// Variables:
		// 		struct Object *waterfx; // $v1
		// 		struct _Model *wxring; // $s1
		/* end block 1.1 */
		// End offset: 0x80046624
		// End Line: 2863
	/* end block 1 */
	// End offset: 0x80046624
	// End Line: 2864

	/* begin block 2 */
		// Start line: 6952
	/* end block 2 */
	// End Line: 6953

/* WARNING: Removing unreachable block (ram,0x80046518) */
/* WARNING: Removing unreachable block (ram,0x8004652c) */
/* WARNING: Removing unreachable block (ram,0x8004654c) */

void FX_WaterBubbleProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  
  if (*(short *)((int)&fxPrim->duo + 4) < fxPrim->work1) {
    *(short *)((int)&fxPrim->duo + 4) =
         *(short *)((int)&fxPrim->duo + 4) + *(short *)((int)&fxPrim->duo + 10);
  }
  if (fxPrim->work0 < *(short *)((int)&fxPrim->duo + 6)) {
    sVar1 = *(short *)((int)&fxPrim->duo + 2);
    (fxPrim->position).x = (fxPrim->position).x + *(short *)&fxPrim->duo;
    (fxPrim->position).y = (fxPrim->position).y + sVar1;
  }
  uVar2 = fxPrim->work2;
  iVar5 = (uint)(ushort)fxPrim->work0 + 1;
  uVar3 = fxPrim->work3;
  (fxPrim->position).z = (fxPrim->position).z + *(short *)((int)&fxPrim->duo + 4);
  sVar1 = *(short *)((int)&fxPrim->duo + 8);
  fxPrim->work0 = (short)iVar5;
  iVar5 = (uint)uVar3 - iVar5 * (uint)uVar2;
  sVar4 = (short)iVar5;
  (fxPrim->v2).y = sVar4;
  (fxPrim->v0).y = sVar4;
  if ((iVar5 * 0x10000 >> 0x10 < (int)sVar1) || (fxPrim->timeToLive < (fxPrim->position).z)) {
    FX_Die(fxPrim,fxTracker);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Sprite_Insert(struct NodeType *list /*$a0*/, struct _FX_PRIM *fxPrim /*$s0*/)
 // line 2867, offset 0x8004663c
	/* begin block 1 */
		// Start line: 7148
	/* end block 1 */
	// End Line: 7149

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
 // line 2873, offset 0x80046674
	/* begin block 1 */
		// Start line: 2875
		// Start offset: 0x80046674
		// Variables:
	// 		struct _Model *model; // $v0
	// 		struct TextureMT3 *texture; // $v0
	/* end block 1 */
	// End offset: 0x80046674
	// End Line: 2879

	/* begin block 2 */
		// Start line: 7160
	/* end block 2 */
	// End Line: 7161

	/* begin block 3 */
		// Start line: 7161
	/* end block 3 */
	// End Line: 7162

	/* begin block 4 */
		// Start line: 7165
	/* end block 4 */
	// End Line: 7166

TextureMT3 * FX_GetTextureObject(Object *object,int modelnum,int texnum)

{
  object->oflags2 = object->oflags2 | 0x20000000;
  return (TextureMT3 *)(object->modelList[modelnum]->faceList[1].color + texnum * 0x10 + 0x10);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeWaterBubble(struct _SVector *position /*$s0*/, struct _SVector *vel /*$s4*/, struct _SVector *accl /*$s5*/, long splashZ /*$s6*/, struct __BubbleParams *BP /*stack 16*/)
 // line 2887, offset 0x800466b0
	/* begin block 1 */
		// Start line: 2888
		// Start offset: 0x800466B0
		// Variables:
	// 		struct Object *waterfx; // $s3
	// 		struct _FX_PRIM *fxPrim; // $s1
	/* end block 1 */
	// End offset: 0x80046838
	// End Line: 2919

	/* begin block 2 */
		// Start line: 7189
	/* end block 2 */
	// End Line: 7190

/* WARNING: Removing unreachable block (ram,0x800466f4) */
/* WARNING: Removing unreachable block (ram,0x8004670c) */

void FX_MakeWaterBubble(_SVector *position,_SVector *vel,_SVector *accl,long splashZ,
                       __BubbleParams *BP)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawScreenPoly(int transtype /*$t3*/, unsigned long color /*$t2*/, int zdepth /*$a2*/)
 // line 2977, offset 0x80046860
	/* begin block 1 */
		// Start line: 2978
		// Start offset: 0x80046860
		// Variables:
	// 		unsigned long **drawot; // $t0
	// 		struct _POLY_TF4 *poly; // $a3
	/* end block 1 */
	// End offset: 0x80046904
	// End Line: 2994

	/* begin block 2 */
		// Start line: 7394
	/* end block 2 */
	// End Line: 7395

void FX_DrawScreenPoly(int transtype,ulong color,int zdepth)

{
  ulong **ppuVar1;
  ulong *puVar2;
  
  ppuVar1 = gameTrackerX.drawOT;
  puVar2 = (gameTrackerX.primPool)->nextPrim;
  if (puVar2 + 7 < (gameTrackerX.primPool)->lastPrim) {
    *(undefined2 *)((int)puVar2 + 0x16) = 0xf0;
    *(undefined2 *)((int)puVar2 + 0x1a) = 0xf0;
    puVar2[1] = transtype << 5 | 0xe1000600;
    *(undefined2 *)(puVar2 + 3) = 0;
    *(undefined2 *)((int)puVar2 + 0xe) = 0;
    *(undefined2 *)(puVar2 + 4) = 0x200;
    *(undefined2 *)((int)puVar2 + 0x12) = 0;
    *(undefined2 *)(puVar2 + 5) = 0;
    *(undefined2 *)(puVar2 + 6) = 0x200;
    puVar2[2] = color;
    *(undefined *)((int)puVar2 + 0xb) = 0x2a;
    *puVar2 = (uint)ppuVar1[zdepth] & 0xffffff | 0x6000000;
    ppuVar1[zdepth] = (ulong *)((uint)puVar2 & 0xffffff);
    (gameTrackerX.primPool)->nextPrim = puVar2 + 7;
  }
  return;
}



// decompiled code
// original method signature: 
// struct POLY_GT4 * /*$ra*/ FX_SetupPolyGT4(int x1 /*$a0*/, int y1 /*$a1*/, int x2 /*$a2*/, int y2 /*$a3*/, int otz /*stack 16*/, struct TextureMT3 *texture /*stack 20*/, long color0 /*stack 24*/, long color1 /*stack 28*/, long color2 /*stack 32*/, long color3 /*stack 36*/)
 // line 2997, offset 0x8004690c
	/* begin block 1 */
		// Start line: 2998
		// Start offset: 0x8004690C
		// Variables:
	// 		struct POLY_GT4 *poly; // $t0
	// 		unsigned long **drawot; // $t3
	/* end block 1 */
	// End offset: 0x80046A08
	// End Line: 3029

	/* begin block 2 */
		// Start line: 7450
	/* end block 2 */
	// End Line: 7451

	/* begin block 3 */
		// Start line: 7454
	/* end block 3 */
	// End Line: 7455

POLY_GT4 *
FX_SetupPolyGT4(int x1,int y1,int x2,int y2,int otz,TextureMT3 *texture,long color0,long color1,
               long color2,long color3)

{
  undefined2 uVar1;
  ulong **ppuVar2;
  POLY_GT4 *pPVar3;
  
  ppuVar2 = gameTrackerX.drawOT;
  pPVar3 = (POLY_GT4 *)(gameTrackerX.primPool)->nextPrim;
  if ((POLY_GT4 *)(gameTrackerX.primPool)->lastPrim <= pPVar3 + 1) {
    return (POLY_GT4 *)0x0;
  }
  *(undefined2 *)&pPVar3->u0 = *(undefined2 *)&texture->u2;
  *(undefined2 *)&pPVar3->u1 = *(undefined2 *)&texture->u1;
  uVar1 = *(undefined2 *)texture;
  pPVar3->x2 = (short)x1;
  pPVar3->x0 = (short)x1;
  pPVar3->x1 = (short)x2;
  pPVar3->x3 = (short)x2;
  pPVar3->y1 = (short)y1;
  pPVar3->y0 = (short)y1;
  pPVar3->y2 = (short)y2;
  pPVar3->y3 = (short)y2;
  *(undefined2 *)&pPVar3->u2 = uVar1;
  *(uint *)&pPVar3->r0 = color0 | 0x3c000000;
  *(long *)&pPVar3->r1 = color1;
  *(long *)&pPVar3->r2 = color2;
  pPVar3->u3 = pPVar3->u1;
  pPVar3->v3 = pPVar3->v2;
  *(long *)&pPVar3->r3 = color3;
  pPVar3->tpage = texture->tpage;
  pPVar3->clut = texture->clut;
  if (otz < 1) {
    otz = 1;
  }
  pPVar3->tag = (uint)ppuVar2[otz] & 0xffffff | 0xc000000;
  ppuVar2[otz] = (ulong *)((uint)pPVar3 & 0xffffff);
  *(POLY_GT4 **)&(gameTrackerX.primPool)->nextPrim = pPVar3 + 1;
  return pPVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeWarpArrow(int x /*$s1*/, int y /*$s3*/, int xsize /*$s2*/, int ysize /*$s4*/, int fade /*stack 16*/)
 // line 3058, offset 0x80046a10
	/* begin block 1 */
		// Start line: 3059
		// Start offset: 0x80046A10
		// Variables:
	// 		struct Object *particle; // $a0
	// 		long color; // $s0
	// 		struct POLY_GT4 *poly; // $v1
	/* end block 1 */
	// End offset: 0x80046AD0
	// End Line: 3075

	/* begin block 2 */
		// Start line: 6116
	/* end block 2 */
	// End Line: 6117

/* WARNING: Removing unreachable block (ram,0x80046a60) */
/* WARNING: Removing unreachable block (ram,0x80046a4c) */
/* WARNING: Removing unreachable block (ram,0x80046a54) */
/* WARNING: Removing unreachable block (ram,0x80046a68) */
/* WARNING: Removing unreachable block (ram,0x80046ac0) */

void FX_MakeWarpArrow(int x,int y,int xsize,int ysize,int fade)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeMannaIcon(int x /*$s2*/, int y /*$s3*/, int xsize /*$s0*/, int ysize /*$s1*/)
 // line 3086, offset 0x80046af0
	/* begin block 1 */
		// Start line: 3087
		// Start offset: 0x80046AF0
		// Variables:
	// 		struct Object *manna; // $a0
	// 		struct TextureMT3 *texture; // $s4
	// 		struct POLY_GT4 *poly; // $v1
	// 		int n; // $s0
	// 		int newx; // $a0
	// 		int newy; // $a1
	// 		int sizex; // $a2
	// 		int sizey; // $v0
	// 		unsigned long color; // $v1
	/* end block 1 */
	// End offset: 0x80046C7C
	// End Line: 3124

	/* begin block 2 */
		// Start line: 7637
	/* end block 2 */
	// End Line: 7638

/* WARNING: Removing unreachable block (ram,0x80046b30) */
/* WARNING: Removing unreachable block (ram,0x80046b80) */
/* WARNING: Removing unreachable block (ram,0x80046b90) */
/* WARNING: Removing unreachable block (ram,0x80046ba0) */
/* WARNING: Removing unreachable block (ram,0x80046bb8) */
/* WARNING: Removing unreachable block (ram,0x80046bc4) */
/* WARNING: Removing unreachable block (ram,0x80046bd8) */

void FX_MakeMannaIcon(int x,int y,int xsize,int ysize)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeGlyphIcon(struct _Position *position /*$s4*/, struct Object *glyphObject /*$s3*/, int size /*$s0*/, int glyphnum /*$s1*/, int enabled /*stack 16*/)
 // line 3197, offset 0x80046c9c
	/* begin block 1 */
		// Start line: 3198
		// Start offset: 0x80046C9C
		// Variables:
	// 		int sizex; // $t0
	// 		struct POLY_GT4 *poly; // $v1
	// 		struct TextureMT3 *texture; // $s2
	// 		struct DVECTOR xy_pos; // stack offset -40
	// 		int otz; // $t1
	// 		long *color_array; // $v0
	// 		struct _GlyphTuneData *glyphtunedata; // $v1

		/* begin block 1.1 */
			// Start line: 3211
			// Start offset: 0x80046CE0
			// Variables:
		// 		struct Object *object; // $a0
		/* end block 1.1 */
		// End offset: 0x80046CF4
		// End Line: 3214
	/* end block 1 */
	// End offset: 0x80046E3C
	// End Line: 3250

	/* begin block 2 */
		// Start line: 6394
	/* end block 2 */
	// End Line: 6395

/* WARNING: Removing unreachable block (ram,0x80046cf4) */

void FX_MakeGlyphIcon(_Position *position,Object *glyphObject,int size,int glyphnum,int enabled)

{
  short sVar1;
  short sVar2;
  int iVar3;
  TextureMT3 *texture;
  long local_38;
  long local_34;
  long local_30;
  long color3;
  POLY_GT4 *pPVar4;
  long *plVar5;
  int iVar6;
  int x1;
  int y1;
  
  if ((glyphObject != (Object *)0x0) && (glyphnum != 7)) {
    texture = FX_GetTextureObject(glyphObject,0,glyphnum);
    sVar1 = position->x;
    iVar6 = -size + 0x18;
    sVar2 = position->y;
    iVar3 = (size << 9) / 0x140;
    if (iVar6 < 0) {
      iVar6 = -size + 0x1b;
    }
    if (enabled == 0) {
      color3 = 0x202020;
      x1 = sVar1 - iVar3;
      y1 = sVar2 - size;
      local_38 = 0x202020;
      local_34 = 0x202020;
      local_30 = 0x202020;
    }
    else {
      plVar5 = (long *)((int)glyphObject->data + glyphnum * 0x10 + 0x1c);
      x1 = sVar1 - iVar3;
      y1 = sVar2 - size;
      local_38 = *plVar5;
      local_34 = plVar5[1];
      local_30 = plVar5[2];
      color3 = plVar5[3];
    }
    pPVar4 = FX_SetupPolyGT4(x1,y1,sVar1 + iVar3 + 1,sVar2 + size + 1,(iVar6 >> 2) + 1,texture,
                             local_38,local_34,local_30,color3);
    if (pPVar4 != (POLY_GT4 *)0x0) {
      pPVar4->code = *(byte *)((int)&texture->color + 3) & 3 | 0x3c;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SoulDustProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 3253, offset 0x80046e60
	/* begin block 1 */
		// Start line: 3254
		// Start offset: 0x80046E60
		// Variables:
	// 		struct MATRIX *swTransform; // $v1
	// 		struct _Position position; // stack offset -24
	// 		long color; // stack offset -16
	// 		long black; // stack offset -12
	// 		int fade; // $a3
	/* end block 1 */
	// End offset: 0x80047004
	// End Line: 3291

	/* begin block 2 */
		// Start line: 7956
	/* end block 2 */
	// End Line: 7957

void FX_SoulDustProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  undefined4 local_10;
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
    local_10 = 0x60ff60;
    local_c = 0;
    sVar2 = (fxPrim->v2).x;
    (fxPrim->v0).y = (fxPrim->v0).y + -0x90;
    iVar4 = (int)(fxPrim->v0).y;
    (fxPrim->position).z = (fxPrim->position).z + (short)(iVar3 >> 0xc);
    sVar1 = (fxPrim->v1).y;
    fxPrim->work1 = fxPrim->work1 - sVar2;
    (fxPrim->v1).y = sVar1 + 0x40;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    LoadAverageCol((byte *)&local_10,(byte *)&local_c,0x1000 - iVar4,iVar4,
                   (undefined *)&fxPrim->color);
    fxPrim->color = fxPrim->color & 0xffffffU | 0x2e000000;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeSoulDust(struct _Instance *instance /*$s4*/, short segment /*$a1*/)
 // line 3292, offset 0x80047014
	/* begin block 1 */
		// Start line: 3293
		// Start offset: 0x80047014
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s1
	// 		struct SVECTOR location; // stack offset -32
	// 		struct Object *particle; // $s2
	/* end block 1 */
	// End offset: 0x80047234
	// End Line: 3344

	/* begin block 2 */
		// Start line: 8084
	/* end block 2 */
	// End Line: 8085

/* WARNING: Removing unreachable block (ram,0x8004705c) */
/* WARNING: Removing unreachable block (ram,0x80047074) */
/* WARNING: Removing unreachable block (ram,0x80047090) */
/* WARNING: Removing unreachable block (ram,0x80047094) */
/* WARNING: Removing unreachable block (ram,0x800471bc) */
/* WARNING: Removing unreachable block (ram,0x800471c0) */
/* WARNING: Removing unreachable block (ram,0x800471d0) */
/* WARNING: Removing unreachable block (ram,0x800471d4) */
/* WARNING: Removing unreachable block (ram,0x800471ec) */
/* WARNING: Removing unreachable block (ram,0x80047204) */

void FX_MakeSoulDust(_Instance *instance,short segment)

{
  rand();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_WaterTrailProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 3367, offset 0x80047254
	/* begin block 1 */
		// Start line: 6734
	/* end block 1 */
	// End Line: 6735

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
 // line 3386, offset 0x8004736c
	/* begin block 1 */
		// Start line: 3387
		// Start offset: 0x8004736C
		// Variables:
	// 		struct Object *waterfx; // $a1
	// 		struct _Model *wxtrail; // $a0
	// 		struct _SVector position; // stack offset -48
	// 		int zvel; // $s0

		/* begin block 1.1 */
			// Start line: 3423
			// Start offset: 0x80047478
			// Variables:
		// 		int n; // $s2
		// 		int deg; // $s0
		// 		struct _SVector vel; // stack offset -40
		// 		struct _SVector accel; // stack offset -32
		// 		struct _SVector startpos; // stack offset -24

			/* begin block 1.1.1 */
				// Start line: 3431
				// Start offset: 0x80047490
				// Variables:
			// 		int sinVal; // $s1
			// 		int cosVal; // $s0
			// 		int spd; // $v1
			/* end block 1.1.1 */
			// End offset: 0x80047524
			// End Line: 3439
		/* end block 1.1 */
		// End offset: 0x80047588
		// End Line: 3444
	/* end block 1 */
	// End offset: 0x80047588
	// End Line: 3445

	/* begin block 2 */
		// Start line: 8277
	/* end block 2 */
	// End Line: 8278

/* WARNING: Removing unreachable block (ram,0x8004740c) */

void FX_MakeWaterTrail(_Instance *instance,int depth)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  _SVector local_28;
  _SVector local_20;
  _SVector local_18;
  
  if ((((instance->matrix != (MATRIX *)0x0) && (instance->oldMatrix != (MATRIX *)0x0)) &&
      (gameTrackerX.gameData.asmData.MorphType != 1)) &&
     (gameTrackerX.gameData.asmData.MorphTime == 1000)) {
    sVar1 = *(short *)instance->matrix[1].t;
    sVar2 = *(short *)(instance->matrix[1].t + 1);
    local_18.z = (instance->splitPoint).z;
    iVar6 = instance->matrix[1].t[2] - instance->oldMatrix[1].t[2];
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    iVar7 = 0;
    if (0x14 < iVar6) {
      local_20.y = 0;
      local_20.x = 0;
      local_20.z = -2;
      do {
        uVar3 = rand();
        iVar6 = rcos(uVar3 & 0xfff);
        iVar4 = rsin(uVar3 & 0xfff);
        uVar3 = rand();
        iVar5 = (uVar3 & 3) + 0xb;
        iVar8 = iVar6 * iVar5;
        iVar5 = iVar4 * iVar5;
        if (iVar8 < 0) {
          iVar8 = iVar8 + 0xfff;
        }
        local_28.x = (short)(iVar8 >> 0xc);
        if (iVar5 < 0) {
          iVar5 = iVar5 + 0xfff;
        }
        local_28.y = (short)(iVar5 >> 0xc);
        local_28.z = 0x12;
        if (iVar6 < 0) {
          iVar6 = iVar6 + 0x7f;
        }
        local_18.x = sVar1 + (short)(iVar6 >> 7);
        if (iVar4 < 0) {
          iVar4 = iVar4 + 0x7f;
        }
        iVar7 = iVar7 + 1;
        local_18.y = sVar2 + (short)(iVar4 >> 7);
        FX_Dot(&local_18,&local_28,&local_20,0,0x404040,0x18,0x14,0);
      } while (iVar7 < 8);
      INSTANCE_Post(gameTrackerX.playerInstance,(int)&DAT_00040024,0);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// struct _FXRibbon * /*$ra*/ FX_StartRibbon(struct _Instance *instance /*$s7*/, short startSegment /*$s3*/, short endSegment /*stack -48*/, short type /*$fp*/, int ribbonLifeTime /*stack 16*/, int faceLifeTime /*stack 20*/, int startFadeValue /*stack 24*/, long startColor /*stack 28*/, long endColor /*stack 32*/)
 // line 3480, offset 0x800475a0
	/* begin block 1 */
		// Start line: 3481
		// Start offset: 0x800475A0
		// Variables:
	// 		struct MATRIX *swTransform; // $a0
	// 		struct _FXRibbon *ribbon; // $s0
	// 		int i; // $a2
	// 		int number; // $s1
	/* end block 1 */
	// End offset: 0x80047840
	// End Line: 3563

	/* begin block 2 */
		// Start line: 6960
	/* end block 2 */
	// End Line: 6961

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
      goto LAB_80047834;
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
LAB_80047834:
  FX_InsertGeneralEffect(ptr);
  return ptr;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_RibbonProcess(struct _FX_PRIM *fxPrim /*$a2*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 3584, offset 0x80047870
	/* begin block 1 */
		// Start line: 3585
		// Start offset: 0x80047870
		// Variables:
	// 		int d; // $a1
	// 		long fade; // $a3
	/* end block 1 */
	// End offset: 0x80047954
	// End Line: 3624

	/* begin block 2 */
		// Start line: 7168
	/* end block 2 */
	// End Line: 7169

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
      LoadAverageCol((byte *)&fxPrim->startColor,(byte *)&fxPrim->endColor,
                     0x1000 - (int)fxPrim->colorFadeValue,(int)fxPrim->colorFadeValue,
                     (undefined *)&fxPrim->color);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ConstrictProcess(struct _FX_PRIM *fxPrim /*$s1*/, struct _FXTracker *fxTracker /*$s2*/)
 // line 3627, offset 0x80047964
	/* begin block 1 */
		// Start line: 8805
	/* end block 1 */
	// End Line: 8806

void FX_ConstrictProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  
  if (FX_ConstrictStage == 1) {
    gameTrackerX.streamFlags = gameTrackerX.streamFlags | 4;
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
      iVar4 = ratan2((int)sVar3 - (int)FX_ConstrictPosition.y,
                     (int)(fxPrim->v0).x - (int)FX_ConstrictPosition.x);
      sVar3 = (fxPrim->v1).y;
      fxPrim->work2 = (short)iVar4;
      iVar4 = ratan2((int)sVar3 - (int)FX_ConstrictPosition.y,
                     (int)(fxPrim->v1).x - (int)FX_ConstrictPosition.x);
      sVar3 = (fxPrim->v2).z;
      sVar2 = (fxPrim->v0).z;
      sVar1 = (fxPrim->v0).z;
      fxPrim->work3 = (short)iVar4;
      iVar4 = (int)sVar3 - (int)sVar2;
      if (iVar4 < 0) {
        iVar4 = iVar4 + 3;
      }
      (fxPrim->v2).z = sVar1 + (short)(iVar4 >> 2);
      (fxPrim->v3).z = (fxPrim->v1).z + ((fxPrim->v3).z - (fxPrim->v1).z) * 3;
    }
    else {
      sVar3 = (fxPrim->v2).y;
      fxPrim->fadeValue[1] = 0x1000;
      fxPrim->fadeValue[0] = 0x1000;
      fxPrim->fadeValue[3] = 0;
      fxPrim->fadeValue[2] = 0;
      iVar4 = ratan2((int)sVar3 - (int)FX_ConstrictPosition.y,
                     (int)(fxPrim->v2).x - (int)FX_ConstrictPosition.x);
      sVar3 = (fxPrim->v3).y;
      fxPrim->work2 = (short)iVar4;
      iVar4 = ratan2((int)sVar3 - (int)FX_ConstrictPosition.y,
                     (int)(fxPrim->v3).x - (int)FX_ConstrictPosition.x);
      sVar3 = (fxPrim->v0).z;
      sVar2 = (fxPrim->v2).z;
      sVar1 = (fxPrim->v2).z;
      fxPrim->work3 = (short)iVar4;
      iVar4 = (int)sVar3 - (int)sVar2;
      if (iVar4 < 0) {
        iVar4 = iVar4 + 3;
      }
      (fxPrim->v0).z = sVar1 + (short)(iVar4 >> 2);
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
      iVar4 = rcos((int)sVar3);
      sVar3 = fxPrim->work2;
      sVar2 = FX_ConstrictPosition.x + (short)(fxPrim->work0 * iVar4 >> 0xc);
      (fxPrim->v0).x = sVar2;
      (fxPrim->v2).x = sVar2;
      iVar4 = rsin((int)sVar3);
      sVar3 = FX_ConstrictPosition.y + (short)(fxPrim->work0 * iVar4 >> 0xc);
      (fxPrim->v0).y = sVar3;
      (fxPrim->v2).y = sVar3;
      gameTrackerX.streamFlags = gameTrackerX.streamFlags | 4;
    }
  }
  FX_RibbonProcess(fxPrim,fxTracker);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartConstrict(struct _Instance *instance /*$a0*/, struct _SVector *constrict_point /*$a1*/, short startSegment /*$a2*/, short endSegment /*$a3*/)
 // line 3696, offset 0x80047c08
	/* begin block 1 */
		// Start line: 8988
	/* end block 1 */
	// End Line: 8989

	/* begin block 2 */
		// Start line: 8989
	/* end block 2 */
	// End Line: 8990

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
 // line 3713, offset 0x80047c98
	/* begin block 1 */
		// Start line: 3714
		// Start offset: 0x80047C98

		/* begin block 1.1 */
			// Start line: 3721
			// Start offset: 0x80047CB8
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x80047CB8
		// End Line: 3721

		/* begin block 1.2 */
			// Start line: 3725
			// Start offset: 0x80047CC4
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.2 */
		// End offset: 0x80047CE8
		// End Line: 3725
	/* end block 1 */
	// End offset: 0x80047CE8
	// End Line: 3729

	/* begin block 2 */
		// Start line: 9026
	/* end block 2 */
	// End Line: 9027

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
      p_Var1 = &instance->position;
    }
    FX_ConstrictPosition.y = p_Var1->y;
    FX_ConstrictPosition.z = p_Var1->z;
    FX_ConstrictInstance = instance;
  }
  FX_DeleteGeneralEffect((_FXGeneralEffect *)FX_ConstrictRibbon);
  FX_ConstrictRibbon = (_FXRibbon *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SubDividePrim(struct _FX_PRIM *fxPrim1 /*$s0*/, struct _FX_PRIM *fxPrim2 /*$s1*/)
 // line 3733, offset 0x80047d04
	/* begin block 1 */
		// Start line: 3734
		// Start offset: 0x80047D04
		// Variables:
	// 		struct SVECTOR mp0; // stack offset -32
	// 		struct SVECTOR mp1; // stack offset -24
	/* end block 1 */
	// End offset: 0x80047D04
	// End Line: 3734

	/* begin block 2 */
		// Start line: 9067
	/* end block 2 */
	// End Line: 9068

void FX_SubDividePrim(_FX_PRIM *fxPrim1,_FX_PRIM *fxPrim2)

{
  uint local_20;
  short local_1c;
  uint local_18;
  short local_14;
  
  LoadAverageShort12((uint *)&fxPrim1->v0,(uint *)&fxPrim2->v2,0x800,0x800,&local_20);
  LoadAverageShort12((uint *)&fxPrim1->v1,(uint *)&fxPrim2->v3,0x800,0x800,&local_18);
  *(uint *)&fxPrim1->v2 = local_20;
  (fxPrim1->v2).z = local_1c;
  *(uint *)&fxPrim1->v3 = local_18;
  (fxPrim1->v3).z = local_14;
  *(uint *)&fxPrim2->v0 = local_20;
  (fxPrim2->v0).z = local_1c;
  *(uint *)&fxPrim2->v1 = local_18;
  (fxPrim2->v1).z = local_14;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueRibbon(struct _FXRibbon *ribbon /*$s2*/, struct _FXTracker *fxTracker /*$fp*/)
 // line 3781, offset 0x80047dc8
	/* begin block 1 */
		// Start line: 3782
		// Start offset: 0x80047DC8
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
			// Start line: 3909
			// Start offset: 0x80048244
			// Variables:
		// 		int fade; // $v1
		/* end block 1.1 */
		// End offset: 0x800482E0
		// End Line: 3933
	/* end block 1 */
	// End offset: 0x80048368
	// End Line: 3948

	/* begin block 2 */
		// Start line: 9166
	/* end block 2 */
	// End Line: 9167

/* WARNING: Could not reconcile some variable overlaps */

void FX_ContinueRibbon(_FXRibbon *ribbon,_FXTracker *fxTracker)

{
  _FX_PRIM *p_Var1;
  int iVar2;
  undefined4 *puVar3;
  _FX_PRIM *fxPrim1;
  long lVar4;
  code *pcVar5;
  _FX_PRIM *fxPrim2;
  _FX_PRIM *p_Var6;
  _FX_PRIM *p_Var7;
  short sVar8;
  MATRIX *pMVar9;
  int iVar10;
  _FX_PRIM *p_Var11;
  long *plVar12;
  int iVar13;
  NodeType *pNVar14;
  void *pvVar15;
  TextureMT3 *pTVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  undefined4 local_50;
  undefined4 local_4c;
  short local_44;
  short local_3c;
  undefined4 local_38;
  undefined4 local_34;
  
  if ((ribbon != (_FXRibbon *)0x0) && (pMVar9 = ribbon->instance->matrix, pMVar9 != (MATRIX *)0x0))
  {
    iVar13 = (int)ribbon->endIndex;
    pMVar9 = pMVar9 + ribbon->startSegment;
    if (iVar13 == -1) {
      ribbon->endIndex = 0;
    }
    iVar2 = (uint)(ushort)ribbon->numberVerts << 0x10;
    iVar2 = (iVar2 >> 0x10) - (iVar2 >> 0x1f) >> 1;
    if (ribbon->type == '\x01') {
      sVar8 = ribbon->endIndex;
      plVar12 = pMVar9->t + 2;
      iVar23 = (int)sVar8;
      while (iVar23 < (int)sVar8 + iVar2) {
        ribbon->vertexPool[iVar23].vx = *(short *)(plVar12 + -2);
        ribbon->vertexPool[iVar23].vy = *(short *)(plVar12 + -1);
        ribbon->vertexPool[iVar23].vz = *(short *)plVar12;
        ribbon->endIndex = ribbon->endIndex + 1;
        plVar12 = plVar12 + 8;
        iVar23 = iVar23 + 1;
      }
    }
    else {
      iVar23 = (int)ribbon->endIndex;
      iVar22 = iVar23 + 1;
      ribbon->vertexPool[iVar23].vx = *(short *)pMVar9->t;
      ribbon->vertexPool[iVar23].vy = *(short *)(pMVar9->t + 1);
      ribbon->vertexPool[iVar23].vz = *(short *)(pMVar9->t + 2);
      pMVar9 = ribbon->instance->matrix + ribbon->endSegment;
      ribbon->vertexPool[iVar22].vx = *(short *)pMVar9->t;
      ribbon->vertexPool[iVar22].vy = *(short *)(pMVar9->t + 1);
      ribbon->vertexPool[iVar22].vz = *(short *)(pMVar9->t + 2);
      ribbon->endIndex = ribbon->endIndex + 2;
    }
    iVar23 = (int)ribbon->endIndex;
    if (ribbon->numberVerts <= iVar23) {
      ribbon->endIndex = 0;
    }
    if (iVar13 == -1) {
      return;
    }
    if ((((ribbon->instance->flags & 0x800U) == 0) && ((ribbon->instance->flags2 & 0x4000000U) == 0)
        ) && (iVar13 < iVar23 + -1)) {
      iVar22 = iVar13 << 3;
      do {
        iVar10 = iVar13 - iVar2;
        if (iVar10 < 0) {
          iVar10 = iVar10 + ribbon->numberVerts;
        }
        puVar3 = (undefined4 *)((int)&ribbon->vertexPool->vx + iVar22);
        uVar17 = *(undefined4 *)(ribbon->vertexPool + iVar10);
        uVar19 = *(undefined4 *)&ribbon->vertexPool[iVar10].vz;
        iVar21 = 0;
        uVar18 = *(undefined4 *)(ribbon->vertexPool + iVar10 + 1);
        uVar20 = *(undefined4 *)&(ribbon->vertexPool + iVar10)[1].vz;
        iVar10 = (int)&ribbon->vertexPool->vx + iVar22;
        local_50 = *puVar3;
        local_4c = puVar3[1];
        local_38 = *(undefined4 *)(iVar10 + 8);
        local_34 = *(undefined4 *)(iVar10 + 0xc);
        do {
          fxPrim1 = FX_GetPrim(fxTracker);
          if (fxPrim1 != (_FX_PRIM *)0x0) {
            (fxPrim1->position).x = *(short *)((int)&ribbon->vertexPool->vx + iVar22);
            (fxPrim1->position).y = *(short *)((int)&ribbon->vertexPool->vy + iVar22);
            (fxPrim1->position).z = *(short *)((int)&ribbon->vertexPool->vz + iVar22);
            *(undefined4 *)&fxPrim1->v0 = local_50;
            (fxPrim1->v0).z = (short)local_4c;
            local_44 = (short)uVar19;
            *(undefined4 *)&fxPrim1->v1 = uVar17;
            (fxPrim1->v1).z = local_44;
            local_3c = (short)uVar20;
            *(undefined4 *)&fxPrim1->v3 = uVar18;
            (fxPrim1->v3).z = local_3c;
            *(undefined4 *)&fxPrim1->v2 = local_38;
            (fxPrim1->v2).z = (short)local_34;
            fxPrim1->fadeValue[0] = ribbon->startFadeValue;
            fxPrim1->fadeValue[1] = ribbon->startFadeValue;
            fxPrim1->fadeValue[2] = ribbon->startFadeValue + ribbon->fadeStep;
            fxPrim1->fadeValue[3] = ribbon->startFadeValue + ribbon->fadeStep;
            sVar8 = ribbon->fadeStep;
            fxPrim1->flags = fxPrim1->flags & 0xfffffffeU | 0x90008;
            fxPrim1->fadeStep = sVar8;
            fxPrim1->color = ribbon->startColor;
            fxPrim1->startColor = ribbon->startColor;
            lVar4 = ribbon->endColor;
            fxPrim1->colorFadeValue = 0;
            fxPrim1->endColor = lVar4;
            fxPrim1->colorFadeStep = ribbon->colorStepValue;
            if (ribbon->type == '\x02') {
              pcVar5 = FX_ConstrictProcess;
            }
            else {
              pcVar5 = FX_RibbonProcess;
            }
            *(code **)&fxPrim1->process = pcVar5;
            fxPrim1->timeToLive = ribbon->faceLifeTime;
            LIST_InsertFunc(&fxTracker->usedPrimList,(NodeType *)fxPrim1);
            fxPrim2 = FX_GetPrim(fxTracker);
            if (fxPrim2 != (_FX_PRIM *)0x0) {
              p_Var7 = fxPrim1;
              p_Var1 = fxPrim2;
              do {
                p_Var11 = p_Var1;
                p_Var6 = p_Var7;
                pNVar14 = (p_Var6->node).next;
                pTVar16 = p_Var6->texture;
                lVar4 = p_Var6->flags;
                (p_Var11->node).prev = (p_Var6->node).prev;
                (p_Var11->node).next = pNVar14;
                p_Var11->texture = pTVar16;
                p_Var11->flags = lVar4;
                p_Var7 = (_FX_PRIM *)&p_Var6->timeToLive;
                p_Var1 = (_FX_PRIM *)&p_Var11->timeToLive;
              } while (p_Var7 != (_FX_PRIM *)((int)&fxPrim1->duo + 4));
              pvVar15 = p_Var6->process;
              (((_FX_PRIM *)&p_Var11->timeToLive)->node).prev = (p_Var7->node).prev;
              p_Var11->process = pvVar15;
              FX_SubDividePrim(fxPrim1,fxPrim2);
              sVar8 = 0x1000;
              if (ribbon->type == '\x02') {
                sVar8 = 0x800;
                fxPrim2->work0 = 0;
                fxPrim1->work0 = 0;
                fxPrim2->work1 = 0;
                fxPrim1->work1 = 0;
                fxPrim1->work2 = 1;
                fxPrim2->work2 = 0;
              }
              fxPrim1->fadeValue[0] = sVar8;
              fxPrim1->fadeValue[1] = sVar8;
              fxPrim2->fadeValue[2] = sVar8;
              fxPrim2->fadeValue[3] = sVar8;
              LIST_InsertFunc(&fxTracker->usedPrimList,(NodeType *)fxPrim2);
            }
          }
          iVar21 = iVar21 + 0x1000;
          local_50 = uVar17;
          local_4c = uVar19;
          local_38 = uVar18;
          local_34 = uVar20;
        } while (iVar21 < 0x1000);
        iVar13 = iVar13 + 1;
        iVar22 = iVar22 + 8;
      } while (iVar13 < iVar23 + -1);
    }
  }
  sVar8 = ribbon->lifeTime;
  if ((0 < ribbon->lifeTime) && (ribbon->lifeTime = sVar8 + -1, sVar8 == 1)) {
    FX_DeleteGeneralEffect((_FXGeneralEffect *)ribbon);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StandardFXPrimProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$a3*/)
 // line 3953, offset 0x80048398
	/* begin block 1 */
		// Start line: 3954
		// Start offset: 0x80048398
		// Variables:
	// 		long flags; // $a2

		/* begin block 1.1 */
			// Start line: 3969
			// Start offset: 0x800483E4
			// Variables:
		// 		long start; // stack offset -16
		// 		long end; // stack offset -12
		/* end block 1.1 */
		// End offset: 0x800484C8
		// End Line: 3984

		/* begin block 1.2 */
			// Start line: 3988
			// Start offset: 0x800484D4
			// Variables:
		// 		int current_scale; // $v1
		/* end block 1.2 */
		// End offset: 0x80048504
		// End Line: 3998

		/* begin block 1.3 */
			// Start line: 4003
			// Start offset: 0x8004850C
			// Variables:
		// 		struct MATRIX *swTransform; // $v1
		/* end block 1.3 */
		// End offset: 0x8004850C
		// End Line: 4004

		/* begin block 1.4 */
			// Start line: 4173
			// Start offset: 0x80048698
			// Variables:
		// 		struct _Rotation rot; // stack offset -24
		/* end block 1.4 */
		// End offset: 0x800486F8
		// End Line: 4181
	/* end block 1 */
	// End offset: 0x800486F8
	// End Line: 4190

	/* begin block 2 */
		// Start line: 9745
	/* end block 2 */
	// End Line: 9746

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
  
  sVar5 = fxPrim->timeToLive;
  if (0 < sVar5) {
    fxPrim->timeToLive = fxPrim->timeToLive + -1;
    sVar5 = fxPrim->timeToLive;
  }
  if (sVar5 == 0) {
LAB_800484ec:
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
      if (iVar6 < 1) goto LAB_800484ec;
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
      RotMatrixX((int)*(char *)((int)&fxPrim->work2 + 1) << 2,(int)&fxPrim->matrix->lwTransform);
      RotMatrixY((int)(short)((int)cVar1 << 2),(uint *)&fxPrim->matrix->lwTransform);
      RotMatrixZ((int)(short)((int)cVar2 << 2),(uint *)&fxPrim->matrix->lwTransform);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_AttachedParticlePrimProcess(struct _FX_PRIM *fxPrim /*$a2*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 4192, offset 0x80048708
	/* begin block 1 */
		// Start line: 4193
		// Start offset: 0x80048708
		// Variables:
	// 		struct MATRIX *swTransform; // $a3
	// 		struct MATRIX *swTransformOld; // $t0
	// 		struct _Instance *instance; // $v1
	/* end block 1 */
	// End offset: 0x80048784
	// End Line: 4207

	/* begin block 2 */
		// Start line: 10243
	/* end block 2 */
	// End Line: 10244

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
 // line 4210, offset 0x8004879c
	/* begin block 1 */
		// Start line: 4211
		// Start offset: 0x8004879C
		// Variables:
	// 		struct MATRIX *swTransform; // $a0
	// 		struct MATRIX *swTransformOld; // $a2
	// 		struct _Instance *instance; // $v0
	// 		struct _SVector movement; // stack offset -16
	// 		int total; // $a0
	/* end block 1 */
	// End offset: 0x80048960
	// End Line: 4244

	/* begin block 2 */
		// Start line: 10282
	/* end block 2 */
	// End Line: 10283

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
 // line 4256, offset 0x80048970
	/* begin block 1 */
		// Start line: 4257
		// Start offset: 0x80048970

		/* begin block 1.1 */
			// Start line: 4257
			// Start offset: 0x80048970
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _Position *_v0; // $v0
		/* end block 1.1 */
		// End offset: 0x80048970
		// End Line: 4257
	/* end block 1 */
	// End offset: 0x80048A50
	// End Line: 4298

	/* begin block 2 */
		// Start line: 10375
	/* end block 2 */
	// End Line: 10376

void FX_DFacadeParticleSetup
               (_FX_PRIM *fxPrim,SVECTOR *center,short halveWidth,short halveHeight,long color,
               SVECTOR *vel,SVECTOR *accl,_FXTracker *fxTracker,int timeToLive)

{
  short sVar1;
  short sVar2;
  
  sVar1 = center->vy;
  sVar2 = center->vz;
  (fxPrim->position).x = center->vx;
  (fxPrim->position).y = sVar1;
  (fxPrim->position).z = sVar2;
  (fxPrim->v0).x = halveWidth;
  (fxPrim->v0).y = 0x1000;
  (fxPrim->v0).z = halveHeight;
  fxPrim->color = color & 0x3ffffffU | 0x20000000;
  *(code **)&fxPrim->process = FX_StandardFXPrimProcess;
  fxPrim->flags = fxPrim->flags | 8;
  if (vel == (SVECTOR *)0x0) {
    *(undefined2 *)&fxPrim->duo = 0;
    *(undefined2 *)((int)&fxPrim->duo + 2) = 0;
    *(undefined2 *)((int)&fxPrim->duo + 4) = 0;
  }
  else {
    *(short *)&fxPrim->duo = vel->vx;
    *(short *)((int)&fxPrim->duo + 2) = vel->vy;
    *(short *)((int)&fxPrim->duo + 4) = vel->vz;
  }
  if (accl == (SVECTOR *)0x0) {
    *(undefined2 *)((int)&fxPrim->duo + 6) = 0;
    *(undefined2 *)((int)&fxPrim->duo + 8) = 0;
    *(undefined2 *)((int)&fxPrim->duo + 10) = 0;
  }
  else {
    *(short *)((int)&fxPrim->duo + 6) = accl->vx;
    *(short *)((int)&fxPrim->duo + 8) = accl->vy;
    *(short *)((int)&fxPrim->duo + 10) = accl->vz;
  }
  fxPrim->timeToLive = (short)timeToLive;
  return;
}



// decompiled code
// original method signature: 
// struct _FX_PRIM * /*$ra*/ FX_Dot(struct _SVector *location /*$s4*/, struct _SVector *vel /*$s6*/, struct _SVector *accel /*$s7*/, int scale_speed /*$fp*/, long color /*stack 16*/, long size /*stack 20*/, int lifetime /*stack 24*/, int texture_num /*stack 28*/)
 // line 4302, offset 0x80048a58
	/* begin block 1 */
		// Start line: 4303
		// Start offset: 0x80048A58
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	/* end block 1 */
	// End offset: 0x80048B90
	// End Line: 4333

	/* begin block 2 */
		// Start line: 10514
	/* end block 2 */
	// End Line: 10515

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
                (fxPrim,(SVECTOR *)location,(short)size,(short)size,color,(SVECTOR *)vel,
                 (SVECTOR *)accel,gFXT,(int)(short)lifetime);
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
 // line 4336, offset 0x80048bc4
	/* begin block 1 */
		// Start line: 4337
		// Start offset: 0x80048BC4
		// Variables:
	// 		int i; // $s0

		/* begin block 1.1 */
			// Start line: 4342
			// Start offset: 0x80048C00
			// Variables:
		// 		struct _SVector vel; // stack offset -40
		/* end block 1.1 */
		// End offset: 0x80048C8C
		// End Line: 4346
	/* end block 1 */
	// End offset: 0x80048CDC
	// End Line: 4349

	/* begin block 2 */
		// Start line: 10588
	/* end block 2 */
	// End Line: 10589

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
      FX_Dot(location,&local_28,accel,0,color,size << 1,0x10,1);
      amount = amount + -1;
    } while (amount != 0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Blood2(struct _SVector *location /*$a0*/, struct _SVector *input_vel /*$a1*/, struct _SVector *accel /*$a2*/, int amount /*$a3*/, long color /*stack 16*/, long dummyCrapShouldRemove /*stack 20*/)
 // line 4351, offset 0x80048d00
	/* begin block 1 */
		// Start line: 10625
	/* end block 1 */
	// End Line: 10626

void FX_Blood2(_SVector *location,_SVector *input_vel,_SVector *accel,int amount,long color,
              long dummyCrapShouldRemove)

{
  FX_Blood(location,input_vel,accel,amount,color,4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Blood_Impale(struct _Instance *locinst /*$a0*/, short locseg /*$a1*/, struct _Instance *instance /*$a2*/, short segment /*$a3*/)
 // line 4383, offset 0x80048d2c
	/* begin block 1 */
		// Start line: 4384
		// Start offset: 0x80048D2C
		// Variables:
	// 		struct _SVector location; // stack offset -40
	// 		struct _SVector accel; // stack offset -32
	// 		struct _SVector vel; // stack offset -24
	// 		struct _SVector input_vel; // stack offset -16
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x80048EE8
	// End Line: 4409

	/* begin block 2 */
		// Start line: 8766
	/* end block 2 */
	// End Line: 8767

void FX_Blood_Impale(_Instance *locinst,short locseg,_Instance *instance,short segment)

{
  int iVar1;
  int iVar2;
  int iVar3;
  _SVector local_28;
  _SVector local_20;
  _SVector local_18;
  short local_10;
  short local_e;
  short local_c;
  
  iVar1 = (int)((uint)(ushort)segment << 0x10) >> 0xb;
  local_10 = *(short *)((int)instance->matrix->t + iVar1) -
             *(short *)((int)instance->oldMatrix->t + iVar1);
  local_e = *(short *)((int)instance->matrix->t + iVar1 + 4) -
            *(short *)((int)instance->oldMatrix->t + iVar1 + 4);
  local_c = *(short *)((int)instance->matrix->t + iVar1 + 8) -
            *(short *)((int)instance->oldMatrix->t + iVar1 + 8);
  iVar1 = (int)((uint)(ushort)locseg << 0x10) >> 0xb;
  local_28.x = *(short *)((int)locinst->matrix->t + iVar1);
  local_28.y = *(short *)((int)locinst->matrix->t + iVar1 + 4);
  iVar2 = 1;
  local_28.z = *(short *)((int)locinst->matrix->t + iVar1 + 8);
  local_20.x = 0;
  local_20.y = 0;
  local_20.z = -2;
  do {
    iVar1 = rand();
    iVar3 = local_10 * iVar2;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0x3f;
    }
    local_18.x = (short)(iVar3 >> 6) + ((ushort)iVar1 & 0xf) + -7;
    iVar1 = rand();
    iVar3 = local_e * iVar2;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0x3f;
    }
    local_18.y = (short)(iVar3 >> 6) + ((ushort)iVar1 & 0xf) + -7;
    iVar1 = rand();
    iVar3 = local_c * iVar2;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0x3f;
    }
    local_18.z = (short)(iVar3 >> 6) + ((ushort)iVar1 & 0xf) + -7;
    FX_Dot(&local_28,&local_18,&local_20,0,(long)&DAT_001800ff,0x10,0x16,1);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x40);
  return;
}



// decompiled code
// original method signature: 
// struct _FXParticle * /*$ra*/ FX_BloodCone(struct _Instance *instance /*$a0*/, short startSegment /*$a1*/, long time /*$s2*/)
 // line 4415, offset 0x80048ef8
	/* begin block 1 */
		// Start line: 4416
		// Start offset: 0x80048EF8
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	// 		struct Object *particle; // $s1
	/* end block 1 */
	// End offset: 0x80048FAC
	// End Line: 4444

	/* begin block 2 */
		// Start line: 10745
	/* end block 2 */
	// End Line: 10746

/* WARNING: Removing unreachable block (ram,0x80048f24) */
/* WARNING: Removing unreachable block (ram,0x80048f3c) */
/* WARNING: Removing unreachable block (ram,0x80048fa8) */

_FXParticle * FX_BloodCone(_Instance *instance,short startSegment,long time)

{
  return (_FXParticle *)0x0;
}



// decompiled code
// original method signature: 
// struct _FXParticle * /*$ra*/ FX_GetTorchParticle(struct _Instance *instance /*$s1*/, short startSegment /*$a1*/, int tex /*$s2*/, int birthRadius /*$s3*/, int num /*stack 16*/)
 // line 4447, offset 0x80048fc4
	/* begin block 1 */
		// Start line: 4448
		// Start offset: 0x80048FC4
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	/* end block 1 */
	// End offset: 0x80049088
	// End Line: 4472

	/* begin block 2 */
		// Start line: 10838
	/* end block 2 */
	// End Line: 10839

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
 // line 4475, offset 0x800490a8
	/* begin block 1 */
		// Start line: 4476
		// Start offset: 0x800490A8
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	// 		struct Object *particle; // $s3
	/* end block 1 */
	// End offset: 0x800491E4
	// End Line: 4524

	/* begin block 2 */
		// Start line: 10917
	/* end block 2 */
	// End Line: 10918

/* WARNING: Removing unreachable block (ram,0x800490d8) */
/* WARNING: Removing unreachable block (ram,0x80049108) */
/* WARNING: Removing unreachable block (ram,0x8004911c) */
/* WARNING: Removing unreachable block (ram,0x80049144) */
/* WARNING: Removing unreachable block (ram,0x80049154) */
/* WARNING: Removing unreachable block (ram,0x8004916c) */
/* WARNING: Removing unreachable block (ram,0x800491e0) */

_FXParticle * FX_TorchFlame(_Instance *instance,short startSegment)

{
  return (_FXParticle *)0x0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ FX_GetMorphFadeVal()
 // line 4526, offset 0x80049204
	/* begin block 1 */
		// Start line: 4528
		// Start offset: 0x80049204
		// Variables:
	// 		int fade; // $a0
	/* end block 1 */
	// End offset: 0x8004923C
	// End Line: 4531

	/* begin block 2 */
		// Start line: 11050
	/* end block 2 */
	// End Line: 11051

	/* begin block 3 */
		// Start line: 11051
	/* end block 3 */
	// End Line: 11052

/* WARNING: Unknown calling convention yet parameter storage is locked */

int FX_GetMorphFadeVal(void)

{
  int iVar1;
  
  iVar1 = ((int)gameTrackerX.gameData.asmData.MorphTime << 0xc) / 1000;
  if (gameTrackerX.gameData.asmData.MorphType == 1) {
    iVar1 = 0x1000 - iVar1;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ConvertCamPersToWorld(struct SVECTOR *campos /*$s0*/, struct SVECTOR *worldpos /*$s1*/)
 // line 4550, offset 0x80049244
	/* begin block 1 */
		// Start line: 11098
	/* end block 1 */
	// End Line: 11099

void FX_ConvertCamPersToWorld(SVECTOR *campos,SVECTOR *worldpos)

{
  undefined4 in_zero;
  undefined4 in_at;
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  SetRotMatrix((undefined4 *)theCamera.core.cwTransform2);
  SetTransMatrix((int)theCamera.core.cwTransform2);
  sVar2 = campos->vx + -0x100;
  iVar1 = (int)sVar2 * 0x140;
  campos->vx = sVar2;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0x1ff;
  }
  campos->vx = (short)(iVar1 >> 9);
  campos->vy = campos->vy + -0x78;
  campos->vx = (short)(((int)campos->vx * (int)campos->vz) / 0x140);
  campos->vy = (short)(((int)campos->vy * (int)campos->vz) / 0x140);
  setCopReg(2,in_zero,*(undefined4 *)campos);
  setCopReg(2,in_at,*(undefined4 *)&campos->vz);
  copFunction(2,0x480012);
  uVar3 = getCopReg(2,0x4800);
  uVar4 = getCopReg(2,0x5000);
  uVar5 = getCopReg(2,0x5800);
  worldpos->vx = (short)uVar3;
  worldpos->vy = (short)uVar4;
  worldpos->vz = (short)uVar5;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_GetRandomScreenPt(struct SVECTOR *point /*$s0*/)
 // line 4570, offset 0x8004935c
	/* begin block 1 */
		// Start line: 11148
	/* end block 1 */
	// End Line: 11149

void FX_GetRandomScreenPt(SVECTOR *point)

{
  int iVar1;
  int iVar2;
  
  iVar1 = rand();
  iVar2 = iVar1;
  if (iVar1 < 0) {
    iVar2 = iVar1 + 0x1ff;
  }
  point->vx = (short)iVar1 + (short)(iVar2 >> 9) * -0x200;
  iVar2 = rand();
  point->vy = (short)iVar2 + (short)(iVar2 / 0xf0) * -0xf0;
  iVar2 = rand();
  point->vz = ((ushort)iVar2 & 0xfff) + 0x180;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ProcessSnow(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$s1*/)
 // line 4577, offset 0x800493e8
	/* begin block 1 */
		// Start line: 4578
		// Start offset: 0x800493E8

		/* begin block 1.1 */
			// Start line: 4581
			// Start offset: 0x8004940C
			// Variables:
		// 		struct SVECTOR position; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x80049454
		// End Line: 4597
	/* end block 1 */
	// End offset: 0x80049508
	// End Line: 4611

	/* begin block 2 */
		// Start line: 11162
	/* end block 2 */
	// End Line: 11163

void FX_ProcessSnow(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  SVECTOR SStack24;
  
  if (fxPrim->work0 == 9999) {
    if (((gameTrackerX.gameData.asmData.MorphType == 1) ||
        (gameTrackerX.gameData.asmData.MorphTime != 1000)) || (snow_amount == 0)) goto LAB_8004947c;
    fxPrim->work0 = 0;
    FX_GetRandomScreenPt(&SStack24);
    FX_ConvertCamPersToWorld(&SStack24,(SVECTOR *)&fxPrim->position);
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
LAB_8004947c:
  FX_Die(fxPrim,fxTracker);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueSnow(struct _FXTracker *fxTracker /*$s1*/)
 // line 4613, offset 0x8004951c
	/* begin block 1 */
		// Start line: 4614
		// Start offset: 0x8004951C
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct SVECTOR position; // stack offset -40
	// 		struct SVECTOR vel; // stack offset -32

		/* begin block 1.1 */
			// Start line: 4631
			// Start offset: 0x80049598
			// Variables:
		// 		struct SVECTOR campos; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x80049660
		// End Line: 4653
	/* end block 1 */
	// End offset: 0x80049660
	// End Line: 4655

	/* begin block 2 */
		// Start line: 11236
	/* end block 2 */
	// End Line: 11237

void FX_ContinueSnow(_FXTracker *fxTracker)

{
  uint uVar1;
  _FX_PRIM *fxPrim;
  int iVar2;
  int iVar3;
  SVECTOR SStack40;
  SVECTOR local_20;
  SVECTOR local_18;
  
  if (gameTrackerX.gameData.asmData.MorphTime == 1000) {
    if (gameTrackerX.gameData.asmData.MorphType == 1) {
      return;
    }
  }
  else {
    if (gameTrackerX.gameData.asmData.MorphType == 0) {
      return;
    }
  }
  uVar1 = rand();
  if (((int)(uVar1 & 0x3ff) <= (int)snow_amount) &&
     (fxPrim = FX_GetPrim(gFXT), fxPrim != (_FX_PRIM *)0x0)) {
    local_20.vx = 0;
    local_20.vy = 0;
    iVar2 = rand();
    local_20.vz = -0xd - ((ushort)iVar2 & 3);
    iVar3 = rand();
    iVar2 = iVar3;
    if (iVar3 < 0) {
      iVar2 = iVar3 + 0x1ff;
    }
    local_18.vx = (short)iVar3 + (short)(iVar2 >> 9) * -0x200;
    local_18.vy = 5;
    iVar2 = rand();
    local_18.vz = ((ushort)iVar2 & 0xfff) + 0x180;
    FX_ConvertCamPersToWorld(&local_18,&SStack40);
    FX_DFacadeParticleSetup(fxPrim,&SStack40,1,1,0xffffff,&local_20,(SVECTOR *)0x0,fxTracker,0x96);
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
 // line 4657, offset 0x80049674
	/* begin block 1 */
		// Start line: 4658
		// Start offset: 0x80049674
		// Variables:
	// 		short change; // $s0
	/* end block 1 */
	// End offset: 0x800497D0
	// End Line: 4675

	/* begin block 2 */
		// Start line: 11335
	/* end block 2 */
	// End Line: 11336

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
 // line 4682, offset 0x800497ec
	/* begin block 1 */
		// Start line: 4683
		// Start offset: 0x800497EC
		// Variables:
	// 		int zvel; // $a3
	/* end block 1 */
	// End offset: 0x800498AC
	// End Line: 4705

	/* begin block 2 */
		// Start line: 11389
	/* end block 2 */
	// End Line: 11390

void FX_ProcessRain(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  
  sVar4 = *(short *)((int)&fxPrim->duo + 4) + theCamera.focusInstanceVelVec.z;
  if (0 < fxPrim->timeToLive) {
    fxPrim->timeToLive = fxPrim->timeToLive + -1;
  }
  sVar1 = fxPrim->work0;
  sVar3 = (fxPrim->v1).z + sVar4;
  (fxPrim->v1).z = sVar3;
  if ((sVar1 < sVar3) && (fxPrim->timeToLive != 0)) {
    sVar1 = *(short *)&fxPrim->duo;
    sVar3 = *(short *)((int)&fxPrim->duo + 2);
    (fxPrim->v0).x = (fxPrim->v0).x + sVar1;
    sVar2 = (fxPrim->v0).y;
    (fxPrim->v1).x = (fxPrim->v1).x + sVar1;
    (fxPrim->v0).y = sVar2 + sVar3;
    sVar1 = (fxPrim->v0).z;
    (fxPrim->v1).y = (fxPrim->v1).y + sVar3;
    (fxPrim->v0).z = sVar1 + sVar4;
  }
  else {
    FX_Die(fxPrim,fxTracker);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueRain(struct _FXTracker *fxTracker /*$s7*/)
 // line 4707, offset 0x800498bc
	/* begin block 1 */
		// Start line: 4708
		// Start offset: 0x800498BC
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct SVECTOR campos; // stack offset -56
	// 		int n; // $s4
	// 		int rain_pct; // $s6
	// 		long waterZLevel; // $s2
	// 		int slack; // $s1
	// 		int fade; // $v0

		/* begin block 1.1 */
			// Start line: 4753
			// Start offset: 0x80049A04
			// Variables:
		// 		struct _SVector worldpos; // stack offset -48
		// 		int zvel; // $s3
		/* end block 1.1 */
		// End offset: 0x80049BB8
		// End Line: 4796
	/* end block 1 */
	// End offset: 0x80049BC8
	// End Line: 4798

	/* begin block 2 */
		// Start line: 11452
	/* end block 2 */
	// End Line: 11453

void FX_ContinueRain(_FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  Level *pLVar6;
  uint uVar7;
  int iVar8;
  _FX_PRIM *node;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  SVECTOR local_38;
  SVECTOR local_30;
  
  if (gameTrackerX.gameData.asmData._8_4_ != &UNK_000103e8) {
    iVar10 = (int)rain_amount;
    if (gameTrackerX.gameData.asmData.MorphTime == 1000) {
      if ((current_rain_fade < 0x1000) &&
         (iVar5 = (uint)(ushort)current_rain_fade + (gameTrackerX.timeMult >> 7),
         current_rain_fade = (short)iVar5, 0x1000 < iVar5 * 0x10000 >> 0x10)) {
        current_rain_fade = 0x1000;
      }
      iVar5 = (int)current_rain_fade;
    }
    else {
      iVar5 = FX_GetMorphFadeVal();
      iVar11 = (0x1000 - iVar5) * (int)current_rain_fade;
      iVar5 = iVar11 >> 0xc;
      if (iVar11 < 0) {
        iVar5 = iVar11 + 0xfff >> 0xc;
      }
    }
    iVar10 = iVar10 * iVar5;
    if (iVar10 < 0) {
      iVar10 = iVar10 + 0xfff;
    }
    pLVar6 = STREAM_GetLevelWithID((gameTrackerX.playerInstance)->currentStreamUnitID);
    iVar5 = pLVar6->waterZLevel;
    if (((int)theCamera.core.rotation.x & 0xfffU) < 0xc01) {
      iVar11 = 0;
    }
    else {
      iVar11 = (int)((0x1000 - ((int)theCamera.core.rotation.x & 0xfffU)) * 3) / 2;
    }
    iVar9 = 0;
    do {
      uVar7 = rand();
      if ((int)(uVar7 & 0x3ff) <= iVar10 >> 0xc) {
        iVar8 = rand();
        local_38.vy = 5;
        local_38.vx = (short)(iVar8 % (iVar11 + 0x200)) - (short)(iVar11 / 2);
        iVar8 = rand();
        local_38.vz = (ushort)iVar8 & 0x7ff;
        FX_ConvertCamPersToWorld(&local_38,&local_30);
        uVar7 = rand();
        iVar8 = (-0xe - (uVar7 & 3)) * 8;
        if (local_30.vz + iVar8 < iVar5) {
          FX_GetRandomScreenPt(&local_38);
          local_38.vz = local_38.vz + ((short)iVar5 - local_30.vz);
          FX_ConvertCamPersToWorld(&local_38,&local_30);
          if (local_30.vz + iVar8 < iVar5) goto LAB_80049bb8;
        }
        node = FX_GetPrim(gFXT);
        if (node != (_FX_PRIM *)0x0) {
          (node->v0).x = local_30.vx;
          (node->v0).y = local_30.vy;
          (node->v0).z = local_30.vz;
          uVar7 = rand();
          iVar12 = (int)windx * ((uVar7 & 0x3ff) + 0xc00);
          if (iVar12 < 0) {
            iVar12 = iVar12 + 0xfff;
          }
          *(short *)&node->duo = (short)(iVar12 >> 0xc);
          uVar7 = rand();
          iVar12 = (int)windy * ((uVar7 & 0x3ff) + 0xc00);
          if (iVar12 < 0) {
            iVar12 = iVar12 + 0xfff;
          }
          *(undefined2 *)((int)&node->duo + 2) = (short)(iVar12 >> 0xc);
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
LAB_80049bb8:
      iVar9 = iVar9 + 1;
    } while (iVar9 < 3);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeSpark(struct _Instance *instance /*$a0*/, struct _Model *model /*$a1*/, int segment /*$a2*/)
 // line 4803, offset 0x80049bf4
	/* begin block 1 */
		// Start line: 4804
		// Start offset: 0x80049BF4
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	// 		struct Object *particle; // $s1
	/* end block 1 */
	// End offset: 0x80049C9C
	// End Line: 4833

	/* begin block 2 */
		// Start line: 11768
	/* end block 2 */
	// End Line: 11769

/* WARNING: Removing unreachable block (ram,0x80049c10) */
/* WARNING: Removing unreachable block (ram,0x80049c28) */

void FX_MakeSpark(_Instance *instance,_Model *model,int segment)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueParticle(struct _FXParticle *currentParticle /*$s2*/, struct _FXTracker *fxTracker /*stack 4*/)
 // line 4835, offset 0x80049cb0
	/* begin block 1 */
		// Start line: 4836
		// Start offset: 0x80049CB0
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
			// Start line: 4956
			// Start offset: 0x8004A22C
			// Variables:
		// 		int tmp_blue; // $v1
		// 		struct CVECTOR *ptr; // $s0

			/* begin block 1.1.1 */
				// Start line: 4963
				// Start offset: 0x8004A250
				// Variables:
			// 		int fade; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8004A274
			// End Line: 4969
		/* end block 1.1 */
		// End offset: 0x8004A274
		// End Line: 4970
	/* end block 1 */
	// End offset: 0x8004A4C0
	// End Line: 5035

	/* begin block 2 */
		// Start line: 11864
	/* end block 2 */
	// End Line: 11865

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
  int iVar9;
  _FX_PRIM *fxPrim;
  uint uVar10;
  int iVar11;
  long lVar12;
  code *pcVar13;
  MATRIX *pMVar14;
  TextureMT3 *pTVar15;
  MATRIX *pMVar16;
  MATRIX *pMVar17;
  _Instance *instance;
  int iVar18;
  int iVar19;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_30;
  uint local_2c;
  
  local_30 = 0;
  local_2c = SEXT14(currentParticle->numberBirthParticles);
  if ((int)local_2c < 0) {
    iVar9 = rand();
    local_2c = (uint)(iVar9 % -local_2c == 0);
  }
  instance = currentParticle->instance;
  if ((((((instance->flags & 0x800U) == 0) && ((instance->flags2 & 0x4000000U) == 0)) &&
       ((instance->flags & 0x200U) != 0)) &&
      ((pMVar14 = instance->matrix, pMVar14 != (MATRIX *)0x0 &&
       (instance->oldMatrix != (MATRIX *)0x0)))) && (0 < (int)local_2c)) {
    sVar2 = currentParticle->birthRadius;
    iVar9 = (int)sVar2;
    pMVar16 = instance->oldMatrix + currentParticle->startSegment;
    pMVar17 = pMVar14 + currentParticle->startSegment;
    if (currentParticle->type == '\x01') {
      iVar9 = iVar9 * 0x1000;
      if (iVar9 < 0) {
        iVar9 = iVar9 + 0x7f;
      }
      local_40 = iVar9 >> 7;
      local_3c = local_40;
      local_38 = local_40;
    }
    else {
      if ((byte)(currentParticle->type - 2) < 2) {
        pMVar16 = pMVar14 + currentParticle->endSegment;
      }
      local_40 = ((pMVar16->t[0] - pMVar17->t[0]) + iVar9) * 0x1000;
      if (local_40 < 0) {
        local_40 = local_40 + 0x7f;
      }
      local_40 = local_40 >> 7;
      local_3c = ((pMVar16->t[1] - pMVar17->t[1]) + iVar9) * 0x1000;
      if (local_3c < 0) {
        local_3c = local_3c + 0x7f;
      }
      local_3c = local_3c >> 7;
      local_38 = ((pMVar16->t[2] - pMVar17->t[2]) + iVar9) * 0x1000;
      if (local_38 < 0) {
        local_38 = local_38 + 0x7f;
      }
      local_38 = local_38 >> 7;
    }
    if (instance == gameTrackerX.playerInstance) {
      iVar9 = 0;
    }
    else {
      if (gameTrackerX.gameData.asmData.MorphTime == 1000) {
        iVar9 = (int)instance->fadeValue;
      }
      else {
        iVar9 = INSTANCE_GetFadeValue(instance);
      }
    }
    sVar2 = sVar2 / 2;
    iVar19 = 0;
    if (0 < (int)local_2c) {
      iVar18 = 0x1000 - iVar9;
      do {
        fxPrim = FX_GetPrim(gFXT);
        if (fxPrim != (_FX_PRIM *)0x0) {
          uVar10 = rand();
          (fxPrim->position).x =
               ((currentParticle->offset).x + *(short *)pMVar17->t +
               (short)((int)(local_40 * (uVar10 & 0x7f)) >> 0xc)) - sVar2;
          uVar10 = rand();
          (fxPrim->position).y =
               ((currentParticle->offset).y + *(short *)(pMVar17->t + 1) +
               (short)((int)(local_3c * (uVar10 & 0x7f)) >> 0xc)) - sVar2;
          uVar10 = rand();
          (fxPrim->position).z =
               ((currentParticle->offset).z + *(short *)(pMVar17->t + 2) +
               (short)((int)(local_38 * (uVar10 & 0x7f)) >> 0xc)) - sVar2;
          switch(currentParticle->z_undulate) {
          default:
            goto switchD_80049fb4_caseD_0;
          case '\x01':
            iVar11 = rcos(gameTrackerX.frameCount << 7);
            iVar11 = iVar11 * 0x28;
            if (iVar11 < 0) {
              iVar11 = iVar11 + 0xfff;
            }
            sVar8 = (fxPrim->position).z + 0x14 + (short)(iVar11 >> 0xc);
            break;
          case '\x02':
            iVar11 = rcos(gameTrackerX.frameCount << 8);
            iVar11 = iVar11 * 0x14;
            if (iVar11 < 0) {
              iVar11 = iVar11 + 0xfff;
            }
            sVar8 = (fxPrim->position).z + 10 + (short)(iVar11 >> 0xc);
            break;
          case '\x03':
            iVar11 = rcos(gameTrackerX.frameCount << 8);
            iVar11 = iVar11 * 0xf;
            if (iVar11 < 0) {
              iVar11 = iVar11 + 0xfff;
            }
            sVar8 = (fxPrim->position).z + 8 + (short)(iVar11 >> 0xc);
            break;
          case '\x04':
            iVar11 = rcos(gameTrackerX.frameCount << 8);
            if (iVar11 < 0) {
              iVar11 = iVar11 + 0x1ff;
            }
            sVar8 = (fxPrim->position).z + 4 + (short)(iVar11 >> 9);
          }
          (fxPrim->position).z = sVar8;
switchD_80049fb4_caseD_0:
          if (currentParticle->type == '\x03') {
            sVar8 = (fxPrim->position).y;
            *(short *)&fxPrim->duo =
                 (short)((pMVar17->t[0] - (int)(fxPrim->position).x) /
                        (int)currentParticle->primLifeTime);
            sVar3 = (fxPrim->position).z;
            *(undefined2 *)((int)&fxPrim->duo + 2) =
                 (short)((pMVar17->t[1] - (int)sVar8) / (int)currentParticle->primLifeTime);
            *(undefined2 *)((int)&fxPrim->duo + 4) =
                 (short)((pMVar17->t[2] - (int)sVar3) / (int)currentParticle->primLifeTime);
          }
          else {
            if ((currentParticle->flag_bits & 2) == 0) {
              uVar10 = rand();
              iVar11 = ((uVar10 & 0x1ff) - 0xff) * (int)(currentParticle->direction).x;
              if (iVar11 < 0) {
                iVar11 = iVar11 + 0xfff;
              }
              *(short *)&fxPrim->duo = (short)(iVar11 >> 0xc);
              uVar10 = rand();
              iVar11 = ((uVar10 & 0x1ff) - 0xff) * (int)(currentParticle->direction).y;
              if (iVar11 < 0) {
                iVar11 = iVar11 + 0xfff;
              }
              *(undefined2 *)((int)&fxPrim->duo + 2) = (short)(iVar11 >> 0xc);
              uVar10 = rand();
              iVar11 = ((uVar10 & 0x1ff) - 0xff) * (int)(currentParticle->direction).z;
              if (iVar11 < 0) {
                iVar11 = iVar11 + 0xfff;
              }
              *(undefined2 *)((int)&fxPrim->duo + 4) = (short)(iVar11 >> 0xc);
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
          fxPrim->timeToLive = sVar8;
          fxPrim->startColor = currentParticle->startColor;
          if (((currentParticle->flag_bits & 1) != 0) &&
             ((gameTrackerX.gameData.asmData.MorphType == 1 ||
              (gameTrackerX.gameData.asmData.MorphTime != 1000)))) {
            uVar1 = *(undefined *)((int)&fxPrim->startColor + 2);
            *(undefined *)((int)&fxPrim->startColor + 2) = *(undefined *)&fxPrim->startColor;
            *(undefined *)&fxPrim->startColor = uVar1;
            if (gameTrackerX.gameData.asmData.MorphTime != 1000) {
              iVar11 = FX_GetMorphFadeVal();
              LoadAverageCol((byte *)&currentParticle->startColor,(byte *)&fxPrim->startColor,
                             0x1000 - iVar11,iVar11,(undefined *)&fxPrim->startColor);
            }
          }
          lVar12 = currentParticle->endColor;
          sVar8 = (short)iVar9;
          fxPrim->fadeValue[3] = sVar8;
          fxPrim->fadeValue[2] = sVar8;
          fxPrim->fadeValue[1] = sVar8;
          fxPrim->fadeValue[0] = sVar8;
          fxPrim->endColor = lVar12;
          if (iVar9 == 0) {
            fxPrim->fadeStep = (short)(0x1000 / (int)currentParticle->primLifeTime);
          }
          else {
            fxPrim->fadeStep = (short)(iVar18 / (int)currentParticle->primLifeTime);
            LoadAverageCol((byte *)&fxPrim->startColor,(byte *)&local_30,iVar18,iVar9,
                           (undefined *)&fxPrim->startColor);
            LoadAverageCol((byte *)&fxPrim->endColor,(byte *)&local_30,iVar18,iVar9,
                           (undefined *)&fxPrim->endColor);
          }
          if (currentParticle->texture == (TextureMT3 *)0x0) {
            fxPrim->color = fxPrim->startColor & 0x3ffffffU | 0x20000000;
          }
          else {
            fxPrim->flags = fxPrim->flags | 1;
            pTVar15 = currentParticle->texture;
            fxPrim->color = fxPrim->startColor & 0x3ffffffU | 0x2c000000;
            fxPrim->texture = pTVar15;
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
          pcVar13 = (code *)currentParticle->fxprim_process;
          if (pcVar13 == (code *)0x0) {
            pcVar13 = FX_StandardFXPrimProcess;
          }
          *(code **)&fxPrim->process = pcVar13;
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
        iVar19 = iVar19 + 1;
      } while (iVar19 < (int)local_2c);
    }
  }
  if ((0 < currentParticle->lifeTime) &&
     (iVar9 = (uint)(ushort)currentParticle->lifeTime - (uint)(ushort)FX_Frames,
     currentParticle->lifeTime = (short)iVar9, iVar9 * 0x10000 < 1)) {
    FX_DeleteGeneralEffect((_FXGeneralEffect *)currentParticle);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdraftPrimModify(struct _FX_PRIM *fxPrim /*$s3*/, struct _Instance *instance /*$a1*/, struct _FXParticle *particle /*$s1*/, struct _FXTracker *fxTracker /*$a3*/)
 // line 5037, offset 0x8004a4f0
	/* begin block 1 */
		// Start line: 5038
		// Start offset: 0x8004A4F0
		// Variables:
	// 		int deg; // $s2
	/* end block 1 */
	// End offset: 0x8004A604
	// End Line: 5044

	/* begin block 2 */
		// Start line: 12443
	/* end block 2 */
	// End Line: 12444

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
 // line 5047, offset 0x8004a634
	/* begin block 1 */
		// Start line: 12463
	/* end block 1 */
	// End Line: 12464

void FX_MakeParticleTexFX
               (_FX_PRIM *fxPrim,_SVector *position,Object *object,int modelnum,int texnum,
               _SVector *vel,_SVector *accl,long color,int size,int life)

{
  TextureMT3 *pTVar1;
  uint uVar2;
  
  if ((object != (Object *)0x0) && (fxPrim != (_FX_PRIM *)0x0)) {
    FX_DFacadeParticleSetup
              (fxPrim,(SVECTOR *)position,(short)size,(short)size,color,(SVECTOR *)vel,
               (SVECTOR *)accl,gFXT,(int)(short)life);
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
 // line 5070, offset 0x8004a73c
	/* begin block 1 */
		// Start line: 5071
		// Start offset: 0x8004A73C
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	/* end block 1 */
	// End offset: 0x8004A7BC
	// End Line: 5082

	/* begin block 2 */
		// Start line: 12529
	/* end block 2 */
	// End Line: 12530

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
 // line 5108, offset 0x8004a7d0
	/* begin block 1 */
		// Start line: 12608
	/* end block 1 */
	// End Line: 12609

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
// void /*$ra*/ FX_SetReaverInstance(struct _Instance *instance /*$a0*/)
 // line 5120, offset 0x8004a830
	/* begin block 1 */
		// Start line: 12632
	/* end block 1 */
	// End Line: 12633

	/* begin block 2 */
		// Start line: 12633
	/* end block 2 */
	// End Line: 12634

void FX_SetReaverInstance(_Instance *instance)

{
  FX_reaver_instance = instance;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SoulReaverBlade(struct _Instance *instance /*$a0*/, unsigned long **drawot /*stack 4*/)
 // line 5128, offset 0x8004a83c
	/* begin block 1 */
		// Start line: 5129
		// Start offset: 0x8004A83C
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
			// Start line: 5186
			// Start offset: 0x8004A9A4
			// Variables:
		// 		int scale1; // $s0
		/* end block 1.1 */
		// End offset: 0x8004ABD0
		// End Line: 5252
	/* end block 1 */
	// End offset: 0x8004ABFC
	// End Line: 5256

	/* begin block 2 */
		// Start line: 12648
	/* end block 2 */
	// End Line: 12649

/* WARNING: Removing unreachable block (ram,0x8004a8ac) */
/* WARNING: Removing unreachable block (ram,0x8004a8c0) */
/* WARNING: Removing unreachable block (ram,0x8004a8c8) */
/* WARNING: Removing unreachable block (ram,0x8004a8d8) */
/* WARNING: Removing unreachable block (ram,0x8004a8e8) */
/* WARNING: Removing unreachable block (ram,0x8004a92c) */
/* WARNING: Removing unreachable block (ram,0x8004a930) */
/* WARNING: Removing unreachable block (ram,0x8004a9a4) */
/* WARNING: Removing unreachable block (ram,0x8004a9dc) */
/* WARNING: Removing unreachable block (ram,0x8004a9e8) */
/* WARNING: Removing unreachable block (ram,0x8004a9f0) */
/* WARNING: Removing unreachable block (ram,0x8004a9fc) */
/* WARNING: Removing unreachable block (ram,0x8004aa0c) */
/* WARNING: Removing unreachable block (ram,0x8004aa14) */
/* WARNING: Removing unreachable block (ram,0x8004aa24) */
/* WARNING: Removing unreachable block (ram,0x8004aa28) */
/* WARNING: Removing unreachable block (ram,0x8004aa3c) */
/* WARNING: Removing unreachable block (ram,0x8004aa40) */
/* WARNING: Removing unreachable block (ram,0x8004aa58) */
/* WARNING: Removing unreachable block (ram,0x8004aa5c) */
/* WARNING: Removing unreachable block (ram,0x8004aa70) */
/* WARNING: Removing unreachable block (ram,0x8004aa74) */
/* WARNING: Removing unreachable block (ram,0x8004ab94) */
/* WARNING: Removing unreachable block (ram,0x8004abc0) */
/* WARNING: Removing unreachable block (ram,0x8004abcc) */
/* WARNING: Removing unreachable block (ram,0x8004abd0) */
/* WARNING: Removing unreachable block (ram,0x8004abf0) */

void FX_SoulReaverBlade(_Instance *instance,ulong **drawot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ReaverBladeInit()
 // line 5268, offset 0x8004ac2c
	/* begin block 1 */
		// Start line: 13199
	/* end block 1 */
	// End Line: 13200

	/* begin block 2 */
		// Start line: 13200
	/* end block 2 */
	// End Line: 13201

/* WARNING: Unknown calling convention yet parameter storage is locked */

void FX_ReaverBladeInit(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SoulReaverWinding(struct _Instance *instance /*stack 0*/, struct _PrimPool *primPool /*$a1*/, unsigned long **ot /*stack 8*/, struct MATRIX *wcTransform /*stack 12*/)
 // line 5275, offset 0x8004ac34
	/* begin block 1 */
		// Start line: 5276
		// Start offset: 0x8004AC34
		// Variables:
	// 		struct MATRIX mat; // stack offset -96
	// 		struct MATRIX *swTransform; // $a1
	// 		struct _SVector start; // stack offset -64
	// 		struct _SVector end; // stack offset -56
	// 		struct __ReaverData *data; // $s4
	// 		long color; // $s5
	// 		long glow_color; // stack offset -48
	/* end block 1 */
	// End offset: 0x8004AE54
	// End Line: 5350

	/* begin block 2 */
		// Start line: 13213
	/* end block 2 */
	// End Line: 13214

void FX_SoulReaverWinding(_Instance *instance,_PrimPool *primPool,ulong **ot,MATRIX *wcTransform)

{
  short deg;
  char *pcVar1;
  long color;
  int iVar2;
  MATRIX MStack96;
  _SVector local_40;
  _SVector local_38;
  long local_30;
  
  pcVar1 = (char *)instance->extraData;
  if ((*pcVar1 != '\0') && (pcVar1[1] != '\0')) {
    deg = -*(short *)(pcVar1 + 6);
    CompMatrix((undefined4 *)wcTransform,(ushort *)((gameTrackerX.playerInstance)->matrix + 0x28),
               (uint *)&MStack96);
    local_40.z = 0;
    local_40.y = 0;
    local_40.x = 0;
    local_38.y = 0;
    local_38.x = 0;
    local_38.z = -0x80;
    color = *(long *)(pcVar1 + 0x14);
    local_30 = *(long *)(pcVar1 + 0x18);
    FX_Lightning(wcTransform,ot,&MStack96,deg,&local_40,&local_38,0x1e,10,0x10,0x20,0,color,local_30
                );
    CompMatrix((undefined4 *)wcTransform,(ushort *)((gameTrackerX.playerInstance)->matrix + 0x27),
               (uint *)&MStack96);
    local_38.z = -0x60;
    FX_Lightning(wcTransform,ot,&MStack96,deg,&local_40,&local_38,0x1e,10,0x10,0x20,0,color,local_30
                );
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
    CompMatrix((undefined4 *)wcTransform,(ushort *)(instance->matrix + 1),(uint *)&MStack96);
    FX_Lightning(wcTransform,ot,&MStack96,deg,&local_40,&local_38,0,0x19,4,8,0,color,local_30);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdateInstanceWaterSplit(struct _Instance *instance /*$s0*/)
 // line 5356, offset 0x8004ae84
	/* begin block 1 */
		// Start line: 5357
		// Start offset: 0x8004AE84
		// Variables:
	// 		struct _SVector normal; // stack offset -16
	/* end block 1 */
	// End offset: 0x8004AF14
	// End Line: 5384

	/* begin block 2 */
		// Start line: 13407
	/* end block 2 */
	// End Line: 13408

void FX_UpdateInstanceWaterSplit(_Instance *instance)

{
  _TFace *p_Var1;
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
  p_Var1 = instance->waterFace;
  instance->waterFace = (_TFace *)0x0;
  instance->waterFaceTerrain = (_Terrain *)0x0;
  instance->oldWaterFace = p_Var1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_GetPlaneEquation(struct _SVector *normal /*$a0*/, struct _SVector *poPlane /*$a1*/, struct _PlaneConstants *plane /*$a2*/)
 // line 5389, offset 0x8004af34
	/* begin block 1 */
		// Start line: 13478
	/* end block 1 */
	// End Line: 13479

	/* begin block 2 */
		// Start line: 13480
	/* end block 2 */
	// End Line: 13481

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
 // line 5432, offset 0x8004afa8
	/* begin block 1 */
		// Start line: 5433
		// Start offset: 0x8004AFA8
		// Variables:
	// 		struct _FXHalvePlane *ring; // $s0
	// 		struct _SVector normal; // stack offset -40
	// 		struct _SVector point; // stack offset -32
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x8004B108
	// End Line: 5480

	/* begin block 2 */
		// Start line: 10864
	/* end block 2 */
	// End Line: 10865

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
  *(undefined4 *)(ptr + 4) = 0x8004b3ac;
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
      goto code_r0x8004b0c4;
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
code_r0x8004b0c4:
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
 // line 5484, offset 0x8004b128
	/* begin block 1 */
		// Start line: 5485
		// Start offset: 0x8004B128
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
	// End offset: 0x8004B36C
	// End Line: 5544

	/* begin block 2 */
		// Start line: 13657
	/* end block 2 */
	// End Line: 13658

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
  uint uVar11;
  int iVar12;
  
  iVar7 = (int)ring->lifeTime;
  p_Var6 = ring->instance;
  sVar1 = (p_Var6->position).z;
  sVar2 = (p_Var6->position).x;
  sVar3 = (p_Var6->position).y;
  uVar11 = ((gameTrackerX.currentTime % 1000) * 0x1000) / 1000;
  iVar12 = 0x200 - (ring->diffTime << 9) / iVar7;
  if (iVar7 <= ring->diffTime) {
    iVar12 = 0x200;
    ring->diffTime = iVar7;
    ring->lifeTime = 0;
  }
  (ring->ringPlane).flags = 0;
  iVar7 = rsin(200);
  iVar4 = rsin(uVar11);
  (ring->ringPlane).a = (short)(iVar7 * iVar4 >> 0xc);
  iVar7 = rsin(200);
  iVar4 = rcos(uVar11);
  (ring->ringPlane).b = (short)(-iVar7 * iVar4 >> 0xc);
  iVar7 = rcos(200);
  (ring->ringPlane).c = (short)iVar7;
  (ring->ringPlane).d =
       -((int)(ring->ringPlane).a * (int)sVar2 + (int)(ring->ringPlane).b * (int)sVar3 +
         (int)(short)iVar7 * (sVar1 + iVar12) >> 0xc);
  if (ring->colorArray != (long *)0x0) {
    iVar7 = 0;
    if (ring->diffTime != 0) {
      iVar7 = ring->diffTime / (int)ring->colorBlendLife;
    }
    iVar12 = (ring->diffTime % ((int)ring->colorBlendLife + 1) << 0xc) / (int)ring->colorBlendLife;
    if ((int)ring->numColors + -1 <= iVar7) {
      iVar7 = (int)ring->numColors + -2;
      iVar12 = 0x1000;
    }
    setCopReg(2,0x4000,0x1000 - iVar12);
    plVar5 = ring->colorArray + iVar7;
    setCopReg(2,0x4800,(uint)*(byte *)plVar5);
    setCopReg(2,0x5000,(uint)*(byte *)((int)plVar5 + 1));
    setCopReg(2,0x5800,(uint)*(byte *)((int)plVar5 + 2));
    copFunction(2,0x198003d);
    setCopReg(2,0x4000,iVar12);
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
  ring->diffTime = ring->diffTime + gameTrackerX.lastLoopTime;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdateInstanceSplitRing(struct _FXHalvePlane *ring /*$s0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 5629, offset 0x8004b3ac
	/* begin block 1 */
		// Start line: 13970
	/* end block 1 */
	// End Line: 13971

void FX_UpdateInstanceSplitRing(_FXHalvePlane *ring,_FXTracker *fxTracker)

{
  int iVar1;
  
  if (ring->lifeTime != 0) {
    if (ring->type == '\0') {
      FX_UpdatePowerRing(ring);
    }
    else {
      iVar1 = ring->diffTime + gameTrackerX.lastLoopTime;
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
 // line 5652, offset 0x8004b43c
	/* begin block 1 */
		// Start line: 14017
	/* end block 1 */
	// End Line: 14018

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
 // line 5660, offset 0x8004b46c
	/* begin block 1 */
		// Start line: 5662
		// Start offset: 0x8004B46C
	/* end block 1 */
	// End offset: 0x8004B46C
	// End Line: 5663

	/* begin block 2 */
		// Start line: 14033
	/* end block 2 */
	// End Line: 14034

	/* begin block 3 */
		// Start line: 14034
	/* end block 3 */
	// End Line: 14035

	/* begin block 4 */
		// Start line: 14035
	/* end block 4 */
	// End Line: 14036

void FX_InsertGeneralEffect(void *ptr)

{
  _FXGeneralEffect *p_Var1;
  
  p_Var1 = (_FXGeneralEffect *)ptr;
  *(_FXGeneralEffect **)ptr = FX_GeneralEffectTracker;
  FX_GeneralEffectTracker = p_Var1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DeleteGeneralEffect(struct _FXGeneralEffect *effect /*$s0*/)
 // line 5668, offset 0x8004b47c
	/* begin block 1 */
		// Start line: 5669
		// Start offset: 0x8004B47C
		// Variables:
	// 		struct _FXGeneralEffect *currentEffect; // $v0
	// 		struct _FXGeneralEffect *previousEffect; // $v1
	/* end block 1 */
	// End offset: 0x8004B508
	// End Line: 5701

	/* begin block 2 */
		// Start line: 14050
	/* end block 2 */
	// End Line: 14051

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
 // line 5706, offset 0x8004b518
	/* begin block 1 */
		// Start line: 5707
		// Start offset: 0x8004B518
		// Variables:
	// 		struct _FXGlowEffect *glowEffect; // $a2

		/* begin block 1.1 */
			// Start line: 5739
			// Start offset: 0x8004B5E0
			// Variables:
		// 		int i; // $a1
		/* end block 1.1 */
		// End offset: 0x8004B638
		// End Line: 5752
	/* end block 1 */
	// End offset: 0x8004B644
	// End Line: 5758

	/* begin block 2 */
		// Start line: 14126
	/* end block 2 */
	// End Line: 14127

_FXGlowEffect *
FX_DoInstanceOneSegmentGlow
          (_Instance *instance,long segment,long *color,long numColors,long atuColorCycleRate,
          long width,long height)

{
  _FXGlowEffect *p_Var1;
  _FXGlowEffect *p_Var2;
  _Instance *p_Var3;
  int iVar4;
  int iVar5;
  long *plVar6;
  
  p_Var2 = (_FXGlowEffect *)MEMPACK_Malloc(numColors * 4 + 0x2c,'\r');
  if (p_Var2 == (_FXGlowEffect *)0x0) goto LAB_8004b644;
  p_Var2->effectType = -0x7d;
  *(code **)&p_Var2->continue_process = FX_UpdateGlowEffect;
  p_Var2->colorArray = (long *)0x0;
  p_Var2->numColors = (short)numColors;
  p_Var2->colorBlendCycle = (short)(atuColorCycleRate * 0x21);
  p_Var2->width = (short)width;
  p_Var2->instance = instance;
  p_Var2->segment = (short)segment;
  *(void **)&p_Var2->diffTime = (void *)0x0;
  p_Var2->fadein_time = 0;
  p_Var2->fadeout_time = 0;
  p_Var2->height = (short)height;
  p_Var2->lifeTime = -1;
  p_Var2->SegmentInc = '\x01';
  p_Var2->numSegments = 1;
  if (numColors < 2) {
    if (color != (long *)0x0) goto LAB_8004b62c;
    p_Var3 = (_Instance *)0xff8010;
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
LAB_8004b62c:
    p_Var3 = (_Instance *)*color;
  }
  *(_Instance **)&p_Var2->currentColor = p_Var3;
  p_Var1 = p_Var2;
  *(_FXGeneralEffect **)&p_Var2->next = FX_GeneralEffectTracker;
  FX_GeneralEffectTracker = (_FXGeneralEffect *)p_Var1;
LAB_8004b644:
  instance->flags2 = instance->flags2 | 0x200;
  return p_Var2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SetGlowFades(struct _FXGlowEffect *glowEffect /*$a0*/, int fadein /*$a1*/, int fadeout /*$a2*/)
 // line 5763, offset 0x8004b678
	/* begin block 1 */
		// Start line: 14262
	/* end block 1 */
	// End Line: 14263

	/* begin block 2 */
		// Start line: 14263
	/* end block 2 */
	// End Line: 14264

void FX_SetGlowFades(_FXGlowEffect *glowEffect,int fadein,int fadeout)

{
  glowEffect->fadein_time = (short)fadein * 0x21;
  glowEffect->fadeout_time = (short)fadeout * 0x21;
  return;
}



// decompiled code
// original method signature: 
// struct _FXGlowEffect * /*$ra*/ FX_DoInstanceTwoSegmentGlow(struct _Instance *instance /*$a0*/, long segment /*$a1*/, long segmentEnd /*$a2*/, long *color /*$a3*/, long numColors /*stack 16*/, long atuColorCycleRate /*stack 20*/, long height /*stack 24*/)
 // line 5769, offset 0x8004b694
	/* begin block 1 */
		// Start line: 5770
		// Start offset: 0x8004B694
		// Variables:
	// 		struct _FXGlowEffect *glowEffect; // $v0
	// 		int inc; // $s0
	/* end block 1 */
	// End offset: 0x8004B6B4
	// End Line: 5778

	/* begin block 2 */
		// Start line: 14274
	/* end block 2 */
	// End Line: 14275

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
 // line 5785, offset 0x8004b6ec
	/* begin block 1 */
		// Start line: 5786
		// Start offset: 0x8004B6EC
		// Variables:
	// 		struct _FXGlowEffect *glowEffect; // $v0
	/* end block 1 */
	// End offset: 0x8004B6EC
	// End Line: 5786

	/* begin block 2 */
		// Start line: 14310
	/* end block 2 */
	// End Line: 14311

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
 // line 5796, offset 0x8004b734
	/* begin block 1 */
		// Start line: 5797
		// Start offset: 0x8004B734
		// Variables:
	// 		struct _FXGlowEffect *glowEffect; // $v0
	/* end block 1 */
	// End offset: 0x8004B734
	// End Line: 5797

	/* begin block 2 */
		// Start line: 14335
	/* end block 2 */
	// End Line: 14336

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
 // line 5808, offset 0x8004b77c
	/* begin block 1 */
		// Start line: 5809
		// Start offset: 0x8004B77C
		// Variables:
	// 		struct _FXGlowEffect *currentEffect; // $a0
	// 		struct _FXGlowEffect *previousEffect; // $s1

		/* begin block 1.1 */
			// Start line: 5824
			// Start offset: 0x8004B7D4
		/* end block 1.1 */
		// End offset: 0x8004B7D4
		// End Line: 5825
	/* end block 1 */
	// End offset: 0x8004B7F4
	// End Line: 5833

	/* begin block 2 */
		// Start line: 14359
	/* end block 2 */
	// End Line: 14360

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
 // line 5835, offset 0x8004b810
	/* begin block 1 */
		// Start line: 5836
		// Start offset: 0x8004B810

		/* begin block 1.1 */
			// Start line: 5845
			// Start offset: 0x8004B854
			// Variables:
		// 		struct _FXGeneralEffect *currentEffect; // $a0
		// 		struct _FXGeneralEffect *previousEffect; // $s0
		/* end block 1.1 */
		// End offset: 0x8004B880
		// End Line: 5858
	/* end block 1 */
	// End offset: 0x8004B880
	// End Line: 5859

	/* begin block 2 */
		// Start line: 14425
	/* end block 2 */
	// End Line: 14426

void FX_StopGlowEffect(_FXGlowEffect *glowEffect,int fadeout_time)

{
  short sVar1;
  _FXGlowEffect *effect;
  _FXGlowEffect *p_Var2;
  
  if (glowEffect != (_FXGlowEffect *)0x0) {
    if (fadeout_time == 0) {
      effect = (_FXGlowEffect *)FX_GeneralEffectTracker;
      if (FX_GeneralEffectTracker != (_FXGeneralEffect *)0x0) {
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
 // line 5861, offset 0x8004b898
	/* begin block 1 */
		// Start line: 5862
		// Start offset: 0x8004B898
		// Variables:
	// 		struct _SVector start; // stack offset -80
	// 		struct _SVector end; // stack offset -72
	// 		struct _SVector offset; // stack offset -64
	// 		struct MATRIX *swtransform; // $s0
	// 		struct MATRIX mat; // stack offset -56
	/* end block 1 */
	// End offset: 0x8004BAC4
	// End Line: 5924

	/* begin block 2 */
		// Start line: 14479
	/* end block 2 */
	// End Line: 14480

void FX_DrawLightning(_FXLightning *zap,MATRIX *wcTransform,ulong **ot)

{
  MATRIX *pMVar1;
  MATRIX *mat;
  _SVector local_50;
  _SVector local_48;
  short local_40;
  short local_3e;
  short local_3c;
  MATRIX MStack56;
  
  if ((zap->type == '\x02') || (zap->matrixSeg != -1)) {
    local_50.x = (zap->start_offset).x;
    local_50.y = (zap->start_offset).y;
    local_50.z = (zap->start_offset).z;
  }
  else {
    mat = zap->instance->matrix;
    if (mat == (MATRIX *)0x0) {
      local_50.x = (zap->instance->position).x;
      local_50.y = (zap->instance->position).y;
      local_50.z = (zap->instance->position).z;
    }
    else {
      mat = mat + zap->startSeg;
      ApplyMatrixSV(mat,&zap->start_offset,&local_40);
      local_50.x = *(short *)mat->t + local_40;
      local_50.y = *(short *)(mat->t + 1) + local_3e;
      local_50.z = *(short *)(mat->t + 2) + local_3c;
    }
  }
  if (((uint)zap->type - 1 < 2) || (zap->matrixSeg != -1)) {
    local_48.x = (zap->end_offset).x;
    local_48.y = (zap->end_offset).y;
    local_48.z = (zap->end_offset).z;
  }
  else {
    mat = zap->end_instance->matrix;
    if (mat == (MATRIX *)0x0) {
      local_48.x = (zap->instance->position).x;
      local_48.y = (zap->instance->position).y;
      local_48.z = (zap->instance->position).z;
    }
    else {
      mat = mat + zap->endSeg;
      ApplyMatrixSV(mat,&zap->end_offset,&local_40);
      local_48.x = *(short *)mat->t + local_40;
      local_48.y = *(short *)(mat->t + 1) + local_3e;
      local_48.z = *(short *)(mat->t + 2) + local_3c;
    }
  }
  mat = (MATRIX *)0x0;
  if (((int)zap->matrixSeg != -1) && (pMVar1 = zap->instance->matrix, pMVar1 != (MATRIX *)0x0)) {
    mat = &MStack56;
    CompMatrix((undefined4 *)wcTransform,(ushort *)(pMVar1 + (int)zap->matrixSeg),(uint *)mat);
  }
  FX_Lightning(wcTransform,ot,mat,zap->deg,&local_50,&local_48,(int)zap->width,(int)zap->small_width
               ,(int)zap->segs,(int)zap->sine_size,(int)zap->variation,zap->color,zap->glow_color);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawAllGeneralEffects(struct MATRIX *wcTransform /*$s1*/, struct _VertexPool *vertexPool /*$s3*/, struct _PrimPool *primPool /*$s4*/, unsigned long **ot /*$s2*/)
 // line 5931, offset 0x8004bb4c
	/* begin block 1 */
		// Start line: 5932
		// Start offset: 0x8004BB4C
		// Variables:
	// 		struct _Instance *instance; // $a0
	// 		struct _FXGeneralEffect *currentEffect; // $s0

		/* begin block 1.1 */
			// Start line: 5945
			// Start offset: 0x8004BBD8
			// Variables:
		// 		struct _FXGlowEffect *currentGlow; // $t0
		/* end block 1.1 */
		// End offset: 0x8004BC08
		// End Line: 5953

		/* begin block 1.2 */
			// Start line: 5957
			// Start offset: 0x8004BC30
		/* end block 1.2 */
		// End offset: 0x8004BC30
		// End Line: 5958

		/* begin block 1.3 */
			// Start line: 5967
			// Start offset: 0x8004BC74
		/* end block 1.3 */
		// End offset: 0x8004BC74
		// End Line: 5969

		/* begin block 1.4 */
			// Start line: 5977
			// Start offset: 0x8004BCCC
		/* end block 1.4 */
		// End offset: 0x8004BCCC
		// End Line: 5979
	/* end block 1 */
	// End offset: 0x8004BD04
	// End Line: 5989

	/* begin block 2 */
		// Start line: 14621
	/* end block 2 */
	// End Line: 14622

void FX_DrawAllGeneralEffects
               (MATRIX *wcTransform,_VertexPool *vertexPool,_PrimPool *primPool,ulong **ot)

{
  byte bVar1;
  int iVar2;
  _Instance *instance;
  _FXBlastringEffect *blast;
  
  blast = (_FXBlastringEffect *)FX_GeneralEffectTracker;
  if (FX_GeneralEffectTracker != (_FXGeneralEffect *)0x0) {
    do {
      bVar1 = blast->effectType;
      if (((bVar1 & 0x80) != 0) &&
         ((instance = blast->instance, instance == (_Instance *)0x0 ||
          (((instance->flags & 0x800U) == 0 && ((instance->flags2 & 0x4000000U) == 0)))))) {
        if (bVar1 == 0x83) {
          if ((0 < blast->lifeTime) &&
             (iVar2 = (uint)(ushort)blast->lifeTime - (uint)(ushort)gameTrackerX.lastLoopTime,
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
 // line 5999, offset 0x8004bd24
	/* begin block 1 */
		// Start line: 6000
		// Start offset: 0x8004BD24
		// Variables:
	// 		int fade; // $a2
	// 		int tm; // $v0

		/* begin block 1.1 */
			// Start line: 6011
			// Start offset: 0x8004BD94
			// Variables:
		// 		int rad; // $v0
		// 		int crad; // $a0
		// 		int endrad; // $v1
		/* end block 1.1 */
		// End offset: 0x8004BE3C
		// End Line: 6043

		/* begin block 1.2 */
			// Start line: 6047
			// Start offset: 0x8004BE4C
			// Variables:
		// 		unsigned long *colorPtr; // $a0
		// 		unsigned long black; // stack offset -16
		// 		int fade; // $a3
		/* end block 1.2 */
		// End offset: 0x8004BE94
		// End Line: 6055
	/* end block 1 */
	// End offset: 0x8004BF28
	// End Line: 6076

	/* begin block 2 */
		// Start line: 14762
	/* end block 2 */
	// End Line: 14763

	/* begin block 3 */
		// Start line: 14767
	/* end block 3 */
	// End Line: 14768

void FX_ContinueBlastRing(_FXBlastringEffect *blast,_FXTracker *fxTracker)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  int iVar6;
  undefined4 local_10 [2];
  
  iVar6 = blast->vel * (gameTrackerX.timeMult >> 4);
  if (iVar6 < 0) {
    iVar6 = iVar6 + 0xff;
  }
  iVar2 = (int)FX_Frames;
  iVar4 = blast->colorchange_radius;
  blast->radius = blast->radius + (iVar6 >> 8);
  iVar6 = blast->radius;
  iVar2 = blast->vel + blast->accl * iVar2;
  blast->vel = iVar2;
  if (iVar4 < iVar6) {
    if (iVar6 < 0) {
      iVar6 = iVar6 + 0xfff;
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
      iVar6 = (((iVar6 >> 0xc) - iVar4) * 0x1000) / ((iVar2 >> 0xc) - iVar4);
    }
    else {
      iVar6 = (((iVar6 >> 0xc) - iVar4) * 0x1000) / ((iVar3 >> 0xc) - iVar4);
    }
    if (iVar6 < 0x1000) {
      LoadAverageCol((byte *)&blast->endColor,(byte *)&blast->startColor,iVar6,0x1000 - iVar6,
                     (undefined *)&blast->color);
    }
    else {
      blast->color = 0;
    }
  }
  if (gameTrackerX.gameData.asmData.MorphTime != 1000) {
    local_10[0] = 0;
    iVar6 = INSTANCE_GetFadeValue(blast->instance);
    if (blast->colorchange_radius < blast->radius) {
      plVar5 = &blast->color;
    }
    else {
      plVar5 = &blast->startColor;
    }
    LoadAverageCol((byte *)plVar5,(byte *)local_10,0x1000 - iVar6,iVar6,(undefined *)&blast->color);
  }
  blast->color = blast->color & 0xffffff;
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
 // line 6106, offset 0x8004bf38
	/* begin block 1 */
		// Start line: 6107
		// Start offset: 0x8004BF38
		// Variables:
	// 		struct _FXBlastringEffect *blast; // $s0
	/* end block 1 */
	// End offset: 0x8004C0E0
	// End Line: 6147

	/* begin block 2 */
		// Start line: 14990
	/* end block 2 */
	// End Line: 14991

_FXBlastringEffect *
FX_DoBlastRing(_Instance *instance,_SVector *position,MATRIX *mat,int segment,int radius,
              int endRadius,int colorChangeRadius,int size1,int size2,int vel,int accl,int height1,
              int height2,int height3,long startColor,long endColor,int pred_offset,int lifeTime,
              int sortInWorld)

{
  _FXBlastringEffect *ptr;
  undefined4 uVar1;
  long lVar2;
  undefined4 uVar3;
  long lVar4;
  undefined4 uVar5;
  long lVar6;
  
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
    ptr->predator_offset = (char)pred_offset;
    ptr->predator_offset_orig = (char)pred_offset;
    ptr->lifeTime = (short)lifeTime;
    uVar1 = *(undefined4 *)&position->z;
    *(undefined4 *)&ptr->position = *(undefined4 *)position;
    *(undefined4 *)&(ptr->position).z = uVar1;
    if (mat != (MATRIX *)0x0) {
      uVar1 = *(undefined4 *)(mat->m + 2);
      uVar3 = *(undefined4 *)(mat->m + 4);
      uVar5 = *(undefined4 *)(mat->m + 6);
      *(undefined4 *)(ptr->matrix).m = *(undefined4 *)mat->m;
      *(undefined4 *)((ptr->matrix).m + 2) = uVar1;
      *(undefined4 *)((ptr->matrix).m + 4) = uVar3;
      *(undefined4 *)((ptr->matrix).m + 6) = uVar5;
      lVar2 = mat->t[0];
      lVar4 = mat->t[1];
      lVar6 = mat->t[2];
      *(undefined4 *)((ptr->matrix).m + 8) = *(undefined4 *)(mat->m + 8);
      (ptr->matrix).t[0] = lVar2;
      (ptr->matrix).t[1] = lVar4;
      (ptr->matrix).t[2] = lVar6;
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
    ptr->stay_in_place = '\0';
    ptr->sortInWorld = (char)sortInWorld;
    FX_InsertGeneralEffect(ptr);
  }
  return ptr;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawBlastring(struct MATRIX *wcTransform /*$s3*/, struct _FXBlastringEffect *blast /*$s1*/)
 // line 6150, offset 0x8004c10c
	/* begin block 1 */
		// Start line: 6151
		// Start offset: 0x8004C10C
		// Variables:
	// 		int radius; // $s2
	// 		struct _SVector position; // stack offset -64
	// 		struct MATRIX mat; // stack offset -56

		/* begin block 1.1 */
			// Start line: 6158
			// Start offset: 0x8004C14C
			// Variables:
		// 		struct MATRIX *swtransform; // $s0
		/* end block 1.1 */
		// End offset: 0x8004C188
		// End Line: 6171
	/* end block 1 */
	// End offset: 0x8004C2BC
	// End Line: 6193

	/* begin block 2 */
		// Start line: 15090
	/* end block 2 */
	// End Line: 15091

/* WARNING: Could not reconcile some variable overlaps */

void FX_DrawBlastring(MATRIX *wcTransform,_FXBlastringEffect *blast)

{
  int radius;
  MATRIX *pMVar1;
  undefined4 local_40;
  undefined4 local_3c;
  MATRIX MStack56;
  
  radius = blast->radius;
  if (radius < 0) {
    radius = radius + 0xfff;
  }
  radius = radius >> 0xc;
  if ((int)blast->segment < 0) {
    CompMatrix((undefined4 *)wcTransform,(ushort *)&blast->matrix,(uint *)&MStack56);
  }
  else {
    pMVar1 = blast->instance->matrix;
    if (pMVar1 == (MATRIX *)0x0) {
      return;
    }
    pMVar1 = pMVar1 + (int)blast->segment;
    CompMatrix((undefined4 *)wcTransform,(ushort *)pMVar1,(uint *)&MStack56);
    if (blast->stay_in_place == '\0') {
      local_40 = CONCAT22(*(undefined2 *)(pMVar1->t + 1),*(undefined2 *)pMVar1->t);
      local_3c = CONCAT22(local_3c._2_2_,*(undefined2 *)(pMVar1->t + 2));
      goto LAB_8004c1dc;
    }
  }
  local_40 = *(undefined4 *)&blast->position;
  local_3c = *(undefined4 *)&(blast->position).z;
LAB_8004c1dc:
  if (blast->type == '\0') {
    FX_DrawRing(wcTransform,(_SVector *)&local_40,&MStack56,radius,radius + blast->size1,
                radius + blast->size2,blast->height1,blast->height2,blast->height3,blast->color,
                (int)blast->sortInWorld);
  }
  else {
    if (blast->type == '\x01') {
      FX_DrawRing2(wcTransform,(_SVector *)&local_40,&MStack56,radius,radius + blast->size1,
                   radius + blast->size2,blast->height1,blast->height2,blast->height3,
                   (int)blast->predator_offset,(int)blast->sortInWorld);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueFlash(struct _FXFlash *flash /*$a0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 6196, offset 0x8004c2d8
	/* begin block 1 */
		// Start line: 15182
	/* end block 1 */
	// End Line: 15183

void FX_ContinueFlash(_FXFlash *flash,_FXTracker *fxTracker)

{
  int iVar1;
  
  iVar1 = flash->currentTime + gameTrackerX.timeMult;
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
 // line 6206, offset 0x8004c328
	/* begin block 1 */
		// Start line: 6207
		// Start offset: 0x8004C328
		// Variables:
	// 		int time; // $a1
	// 		int div; // $a2
	// 		int transtype; // $s0
	// 		int interp; // $a3
	// 		unsigned long color; // stack offset -16
	// 		unsigned long black; // stack offset -12
	/* end block 1 */
	// End offset: 0x8004C41C
	// End Line: 6237

	/* begin block 2 */
		// Start line: 15202
	/* end block 2 */
	// End Line: 15203

void FX_DrawFlash(_FXFlash *flash)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int transtype;
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
    iVar2 = (iVar2 << 0xc) / flash->timeToColor;
    if (0x1000 < iVar2) {
      iVar2 = 0x1000;
    }
    iVar4 = 0x1000 - iVar2;
  }
  else {
    iVar3 = flash->timeAtColor;
    if (iVar2 <= iVar3) goto LAB_8004c41c;
    iVar4 = flash->timeFromColor - iVar3;
    if (iVar4 == 0) {
      iVar4 = 0x1000;
      bVar1 = true;
    }
    else {
      iVar4 = ((iVar2 - iVar3) * 0x1000) / iVar4;
      bVar1 = iVar4 < 0x1001;
    }
    if (!bVar1) {
      iVar4 = 0x1000;
    }
    iVar2 = 0x1000 - iVar4;
  }
  LoadAverageCol((byte *)&local_10,(byte *)&local_c,iVar2,iVar4,(undefined *)&local_10);
LAB_8004c41c:
  FX_DrawScreenPoly(transtype,local_10,5);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_RelocateGeneric(struct Object *object /*$a0*/, long offset /*$a1*/)
 // line 6240, offset 0x8004c43c
	/* begin block 1 */
		// Start line: 6242
		// Start offset: 0x8004C43C
		// Variables:
	// 		struct GenericFXObject *GFXO; // $v0
	/* end block 1 */
	// End offset: 0x8004C4D0
	// End Line: 6251

	/* begin block 2 */
		// Start line: 15273
	/* end block 2 */
	// End Line: 15274

	/* begin block 3 */
		// Start line: 15274
	/* end block 3 */
	// End Line: 15275

	/* begin block 4 */
		// Start line: 15276
	/* end block 4 */
	// End Line: 15277

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
 // line 6254, offset 0x8004c4d8
	/* begin block 1 */
		// Start line: 6255
		// Start offset: 0x8004C4D8
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	// 		struct GenericFXObject *GFXO; // $v1
	// 		struct _GenericParticleParams *GPP; // $s1
	// 		struct Object *texture_obj; // $s2
	// 		struct Object *particle; // $a2

		/* begin block 1.1 */
			// Start line: 6320
			// Start offset: 0x8004C738
			// Variables:
		// 		struct TextureMT3 *texture; // $v0
		/* end block 1.1 */
		// End offset: 0x8004C760
		// End Line: 6324

		/* begin block 1.2 */
			// Start line: 6334
			// Start offset: 0x8004C7D8
			// Variables:
		// 		int tmp_blue; // $a0
		// 		struct CVECTOR *ptr; // $v1
		/* end block 1.2 */
		// End offset: 0x8004C7FC
		// End Line: 6343
	/* end block 1 */
	// End offset: 0x8004C808
	// End Line: 6348

	/* begin block 2 */
		// Start line: 15301
	/* end block 2 */
	// End Line: 15302

/* WARNING: Removing unreachable block (ram,0x8004c510) */
/* WARNING: Removing unreachable block (ram,0x8004c52c) */
/* WARNING: Removing unreachable block (ram,0x8004c544) */
/* WARNING: Removing unreachable block (ram,0x8004c554) */
/* WARNING: Removing unreachable block (ram,0x8004c564) */
/* WARNING: Removing unreachable block (ram,0x8004c574) */
/* WARNING: Removing unreachable block (ram,0x8004c584) */
/* WARNING: Removing unreachable block (ram,0x8004c58c) */
/* WARNING: Removing unreachable block (ram,0x8004c594) */
/* WARNING: Removing unreachable block (ram,0x8004c5a8) */
/* WARNING: Removing unreachable block (ram,0x8004c5e4) */
/* WARNING: Removing unreachable block (ram,0x8004c5d8) */
/* WARNING: Removing unreachable block (ram,0x8004c5e8) */
/* WARNING: Removing unreachable block (ram,0x8004c674) */
/* WARNING: Removing unreachable block (ram,0x8004c66c) */
/* WARNING: Removing unreachable block (ram,0x8004c680) */
/* WARNING: Removing unreachable block (ram,0x8004c6f0) */
/* WARNING: Removing unreachable block (ram,0x8004c71c) */
/* WARNING: Removing unreachable block (ram,0x8004c700) */
/* WARNING: Removing unreachable block (ram,0x8004c728) */
/* WARNING: Removing unreachable block (ram,0x8004c738) */
/* WARNING: Removing unreachable block (ram,0x8004c760) */
/* WARNING: Removing unreachable block (ram,0x8004c770) */
/* WARNING: Removing unreachable block (ram,0x8004c778) */
/* WARNING: Removing unreachable block (ram,0x8004c788) */
/* WARNING: Removing unreachable block (ram,0x8004c798) */
/* WARNING: Removing unreachable block (ram,0x8004c7a8) */
/* WARNING: Removing unreachable block (ram,0x8004c7b8) */
/* WARNING: Removing unreachable block (ram,0x8004c7c8) */
/* WARNING: Removing unreachable block (ram,0x8004c7d8) */
/* WARNING: Removing unreachable block (ram,0x8004c7fc) */

_FXParticle *
FX_StartGenericParticle(_Instance *instance,int num,int segOverride,int lifeOverride,int InitFlag)

{
  return (_FXParticle *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartGenericRibbon(struct _Instance *instance /*$a0*/, int num /*$a1*/, int segOverride /*$a2*/, int endOverride /*$a3*/, int InitFlag /*stack 16*/)
 // line 6350, offset 0x8004c828
	/* begin block 1 */
		// Start line: 6351
		// Start offset: 0x8004C828
		// Variables:
	// 		struct Object *particle; // $v1
	// 		struct GenericFXObject *GFXO; // $v1
	// 		struct _GenericRibbonParams *GRP; // $v1
	/* end block 1 */
	// End offset: 0x8004C8D4
	// End Line: 6386

	/* begin block 2 */
		// Start line: 15511
	/* end block 2 */
	// End Line: 15512

/* WARNING: Removing unreachable block (ram,0x8004c840) */
/* WARNING: Removing unreachable block (ram,0x8004c868) */
/* WARNING: Removing unreachable block (ram,0x8004c878) */
/* WARNING: Removing unreachable block (ram,0x8004c880) */
/* WARNING: Removing unreachable block (ram,0x8004c890) */

void FX_StartGenericRibbon(_Instance *instance,int num,int segOverride,int endOverride,int InitFlag)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartGenericGlow(struct _Instance *instance /*$a0*/, int num /*$a1*/, int segOverride /*$t0*/, int seg2Override /*$a3*/, int InitFlag /*stack 16*/)
 // line 6388, offset 0x8004c8e4
	/* begin block 1 */
		// Start line: 6389
		// Start offset: 0x8004C8E4
		// Variables:
	// 		struct Object *particle; // $v1
	// 		struct GenericFXObject *GFXO; // $t1
	// 		struct _GenericGlowParams *GGP; // $s0
	// 		struct _FXGlowEffect *glowEffect; // $a0
	// 		long *color; // $v1

		/* begin block 1.1 */
			// Start line: 6416
			// Start offset: 0x8004C970
			// Variables:
		// 		int seg; // $a1
		/* end block 1.1 */
		// End offset: 0x8004C97C
		// End Line: 6418

		/* begin block 1.2 */
			// Start line: 6422
			// Start offset: 0x8004C9B4
			// Variables:
		// 		int seg; // $a1
		// 		int segEnd; // $a2
		/* end block 1.2 */
		// End offset: 0x8004C9D4
		// End Line: 6433

		/* begin block 1.3 */
			// Start line: 6437
			// Start offset: 0x8004CA04
			// Variables:
		// 		int seg; // $a1
		// 		int numSeg; // $a2
		/* end block 1.3 */
		// End offset: 0x8004CA4C
		// End Line: 6456
	/* end block 1 */
	// End offset: 0x8004CA7C
	// End Line: 6463

	/* begin block 2 */
		// Start line: 15594
	/* end block 2 */
	// End Line: 15595

/* WARNING: Removing unreachable block (ram,0x8004c904) */
/* WARNING: Removing unreachable block (ram,0x8004c920) */
/* WARNING: Removing unreachable block (ram,0x8004c930) */
/* WARNING: Removing unreachable block (ram,0x8004c940) */
/* WARNING: Removing unreachable block (ram,0x8004c950) */
/* WARNING: Removing unreachable block (ram,0x8004c9ac) */
/* WARNING: Removing unreachable block (ram,0x8004ca04) */
/* WARNING: Removing unreachable block (ram,0x8004ca0c) */
/* WARNING: Removing unreachable block (ram,0x8004ca14) */
/* WARNING: Removing unreachable block (ram,0x8004ca1c) */
/* WARNING: Removing unreachable block (ram,0x8004ca20) */
/* WARNING: Removing unreachable block (ram,0x8004c9b4) */
/* WARNING: Removing unreachable block (ram,0x8004c9bc) */
/* WARNING: Removing unreachable block (ram,0x8004c9c4) */
/* WARNING: Removing unreachable block (ram,0x8004c9cc) */
/* WARNING: Removing unreachable block (ram,0x8004c9d4) */
/* WARNING: Removing unreachable block (ram,0x8004c970) */
/* WARNING: Removing unreachable block (ram,0x8004c978) */
/* WARNING: Removing unreachable block (ram,0x8004c97c) */
/* WARNING: Removing unreachable block (ram,0x8004ca4c) */
/* WARNING: Removing unreachable block (ram,0x8004ca54) */
/* WARNING: Removing unreachable block (ram,0x8004ca64) */

void FX_StartGenericGlow(_Instance *instance,int num,int segOverride,int seg2Override,int InitFlag)

{
  return;
}



// decompiled code
// original method signature: 
// struct _FXLightning * /*$ra*/ FX_CreateLightning(struct _Instance *instance /*$s1*/, int lifeTime /*$s2*/, int deg /*$s3*/, int deg_inc /*$s4*/, int width /*stack 16*/, int small_width /*stack 20*/, int segs /*stack 24*/, int sine_size /*stack 28*/, int variation /*stack 32*/, unsigned long color /*stack 36*/, unsigned long glow_color /*stack 40*/)
 // line 6483, offset 0x8004ca8c
	/* begin block 1 */
		// Start line: 6484
		// Start offset: 0x8004CA8C
		// Variables:
	// 		struct _FXLightning *zap; // $s0
	/* end block 1 */
	// End offset: 0x8004CB70
	// End Line: 6519

	/* begin block 2 */
		// Start line: 15794
	/* end block 2 */
	// End Line: 15795

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
 // line 6540, offset 0x8004cb94
	/* begin block 1 */
		// Start line: 15920
	/* end block 1 */
	// End Line: 15921

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
    if (startInstance != (_Instance *)0x0) goto LAB_8004cbe0;
  }
  if (endInstance == (_Instance *)0x0) {
    zap->type = '\x02';
  }
LAB_8004cbe0:
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
 // line 6569, offset 0x8004cc44
	/* begin block 1 */
		// Start line: 6570
		// Start offset: 0x8004CC44
		// Variables:
	// 		struct _FXLightning *zap; // $s1
	// 		struct GenericFXObject *GFXO; // $v1
	// 		struct _GenericLightningParams *GLP; // $s0
	// 		struct Object *particle; // $v1

		/* begin block 1.1 */
			// Start line: 6596
			// Start offset: 0x8004CD38
			// Variables:
		// 		int startSeg; // $a2
		// 		int endSeg; // $a3

			/* begin block 1.1.1 */
				// Start line: 6622
				// Start offset: 0x8004CDA0
				// Variables:
			// 		int tmp_blue; // $a0
			// 		struct CVECTOR *ptr; // $v1
			/* end block 1.1.1 */
			// End offset: 0x8004CDC4
			// End Line: 6631
		/* end block 1.1 */
		// End offset: 0x8004CDC4
		// End Line: 6632
	/* end block 1 */
	// End offset: 0x8004CDC8
	// End Line: 6635

	/* begin block 2 */
		// Start line: 15978
	/* end block 2 */
	// End Line: 15979

	/* begin block 3 */
		// Start line: 15984
	/* end block 3 */
	// End Line: 15985

/* WARNING: Removing unreachable block (ram,0x8004cc7c) */
/* WARNING: Removing unreachable block (ram,0x8004ccac) */
/* WARNING: Removing unreachable block (ram,0x8004ccbc) */
/* WARNING: Removing unreachable block (ram,0x8004cca4) */
/* WARNING: Removing unreachable block (ram,0x8004cccc) */
/* WARNING: Removing unreachable block (ram,0x8004cd38) */
/* WARNING: Removing unreachable block (ram,0x8004cd40) */
/* WARNING: Removing unreachable block (ram,0x8004cd44) */
/* WARNING: Removing unreachable block (ram,0x8004cd58) */
/* WARNING: Removing unreachable block (ram,0x8004cd4c) */
/* WARNING: Removing unreachable block (ram,0x8004cd5c) */
/* WARNING: Removing unreachable block (ram,0x8004cd90) */
/* WARNING: Removing unreachable block (ram,0x8004cda0) */
/* WARNING: Removing unreachable block (ram,0x8004cdc4) */

_FXLightning *
FX_StartGenericLightning(_Instance *instance,int num,int segOverride,int endSegOverride)

{
  return (_FXLightning *)0x0;
}



// decompiled code
// original method signature: 
// struct _FXBlastringEffect * /*$ra*/ FX_StartGenericBlastring(struct _Instance *instance /*$s1*/, int num /*$a1*/, int segOverride /*$a2*/, int matrixSegOverride /*$a3*/)
 // line 6638, offset 0x8004cde8
	/* begin block 1 */
		// Start line: 6639
		// Start offset: 0x8004CDE8
		// Variables:
	// 		struct _FXBlastringEffect *blast; // $v0
	// 		struct GenericFXObject *GFXO; // $v1
	// 		struct _GenericBlastringParams *GBP; // $s0
	// 		struct Object *particle; // $v1
	// 		struct _SVector position; // stack offset -64
	// 		int segment; // $s2
	// 		int matrix_segment; // $s3
	// 		struct MATRIX mat; // stack offset -56
	// 		struct MATRIX *swTransform; // $v0
	/* end block 1 */
	// End offset: 0x8004CFD4
	// End Line: 6702

	/* begin block 2 */
		// Start line: 16127
	/* end block 2 */
	// End Line: 16128

	/* begin block 3 */
		// Start line: 16138
	/* end block 3 */
	// End Line: 16139

/* WARNING: Removing unreachable block (ram,0x8004ce14) */
/* WARNING: Removing unreachable block (ram,0x8004ce3c) */
/* WARNING: Removing unreachable block (ram,0x8004ce54) */
/* WARNING: Removing unreachable block (ram,0x8004ce5c) */
/* WARNING: Removing unreachable block (ram,0x8004ce60) */
/* WARNING: Removing unreachable block (ram,0x8004ce68) */
/* WARNING: Removing unreachable block (ram,0x8004ce6c) */
/* WARNING: Removing unreachable block (ram,0x8004ceac) */
/* WARNING: Removing unreachable block (ram,0x8004ce84) */
/* WARNING: Removing unreachable block (ram,0x8004ced0) */
/* WARNING: Removing unreachable block (ram,0x8004ce4c) */

_FXBlastringEffect *
FX_StartGenericBlastring(_Instance *instance,int num,int segOverride,int matrixSegOverride)

{
  return (_FXBlastringEffect *)0x0;
}



// decompiled code
// original method signature: 
// struct _FXFlash * /*$ra*/ FX_StartGenericFlash(struct _Instance *instance /*$s2*/, int num /*$a1*/)
 // line 6704, offset 0x8004cff0
	/* begin block 1 */
		// Start line: 6705
		// Start offset: 0x8004CFF0
		// Variables:
	// 		struct GenericFXObject *GFXO; // $v1
	// 		struct _GenericFlashParams *GFP; // $s1
	// 		struct Object *particle; // $v1
	// 		struct _FXFlash *flash; // $s0
	/* end block 1 */
	// End offset: 0x8004D0B8
	// End Line: 6736

	/* begin block 2 */
		// Start line: 16271
	/* end block 2 */
	// End Line: 16272

	/* begin block 3 */
		// Start line: 16277
	/* end block 3 */
	// End Line: 16278

/* WARNING: Removing unreachable block (ram,0x8004d01c) */
/* WARNING: Removing unreachable block (ram,0x8004d04c) */
/* WARNING: Removing unreachable block (ram,0x8004d0b4) */

_FXFlash * FX_StartGenericFlash(_Instance *instance,int num)

{
  return (_FXFlash *)0x0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ FX_GetHealthColor(int currentHealth /*$a0*/)
 // line 6738, offset 0x8004d0d0
	/* begin block 1 */
		// Start line: 6759
		// Start offset: 0x8004D0D0
		// Variables:
	// 		static long HealthColors[6]; // offset 0x0
	// 		long color; // $v1
	/* end block 1 */
	// End offset: 0x8004D114
	// End Line: 6776

	/* begin block 2 */
		// Start line: 16354
	/* end block 2 */
	// End Line: 16355

	/* begin block 3 */
		// Start line: 16374
	/* end block 3 */
	// End Line: 16375

	/* begin block 4 */
		// Start line: 16385
	/* end block 4 */
	// End Line: 16386

long FX_GetHealthColor(int currentHealth)

{
  uint uVar1;
  
  if (currentHealth < 1) {
    uVar1 = 0x7f;
  }
  else {
    if ((uint)currentHealth < 6) {
      uVar1 = (&DAT_800ca43c)[currentHealth + -1];
    }
    else {
      uVar1 = 0x7f0000;
    }
  }
  return uVar1 & 0xfffcfcfc;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Start_Snow(int percent /*$a0*/)
 // line 6780, offset 0x8004d124
	/* begin block 1 */
		// Start line: 16438
	/* end block 1 */
	// End Line: 16439

	/* begin block 2 */
		// Start line: 16439
	/* end block 2 */
	// End Line: 16440

void FX_Start_Snow(int percent)

{
  snow_amount = (short)((percent * 0x300) / 100);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Start_Rain(int percent /*$a0*/)
 // line 6785, offset 0x8004d158
	/* begin block 1 */
		// Start line: 16448
	/* end block 1 */
	// End Line: 16449

	/* begin block 2 */
		// Start line: 16449
	/* end block 2 */
	// End Line: 16450

void FX_Start_Rain(int percent)

{
  uint uVar1;
  
  uVar1 = (percent << 10) / 100;
  if ((uVar1 & 0xffff) == 0) {
    current_rain_fade = 0;
  }
  rain_amount = (short)uVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartLightbeam(struct _Instance *instance /*$s1*/, int startSeg /*$s2*/, int endSeg /*$s3*/, int color_num /*$a3*/)
 // line 6792, offset 0x8004d194
	/* begin block 1 */
		// Start line: 6793
		// Start offset: 0x8004D194
		// Variables:
	// 		struct Object *particle; // $v0
	// 		struct _FXLightBeam *beam; // $v0
	// 		struct GenericFXObject *GFXO; // $v0
	// 		long color; // $s0
	/* end block 1 */
	// End offset: 0x8004D21C
	// End Line: 6817

	/* begin block 2 */
		// Start line: 16462
	/* end block 2 */
	// End Line: 16463

	/* begin block 3 */
		// Start line: 16468
	/* end block 3 */
	// End Line: 16469

/* WARNING: Removing unreachable block (ram,0x8004d1c4) */
/* WARNING: Removing unreachable block (ram,0x8004d1f0) */

void FX_StartLightbeam(_Instance *instance,int startSeg,int endSeg,int color_num)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartInstanceEffect(struct _Instance *instance /*$s2*/, struct ObjectEffect *effect /*$s0*/, int InitFlag /*$s3*/)
 // line 6831, offset 0x8004d238
	/* begin block 1 */
		// Start line: 6832
		// Start offset: 0x8004D238
		// Variables:
	// 		long color; // stack offset -32

		/* begin block 1.1 */
			// Start line: 6865
			// Start offset: 0x8004D30C
			// Variables:
		// 		long numberOfSegments; // $a2
		/* end block 1.1 */
		// End offset: 0x8004D354
		// End Line: 6885

		/* begin block 1.2 */
			// Start line: 6950
			// Start offset: 0x8004D418
			// Variables:
		// 		struct _FXParticle *currentParticle; // $a0
		// 		struct evObjectDraftData *draft; // $s1
		/* end block 1.2 */
		// End offset: 0x8004D450
		// End Line: 6959

		/* begin block 1.3 */
			// Start line: 6986
			// Start offset: 0x8004D500
			// Variables:
		// 		struct FXSplinter *splinterData; // $s0
		// 		struct GenericTune *tune; // $a0
		// 		short shardFlags; // $s1

			/* begin block 1.3.1 */
				// Start line: 6992
				// Start offset: 0x8004D520
				// Variables:
			// 		struct PhysObSplinter *splintDef; // $v0
			/* end block 1.3.1 */
			// End offset: 0x8004D530
			// End Line: 6995
		/* end block 1.3 */
		// End offset: 0x8004D55C
		// End Line: 7006

		/* begin block 1.4 */
			// Start line: 7020
			// Start offset: 0x8004D5DC
			// Variables:
		// 		int shock; // $a0
		// 		int amt; // $a1
		/* end block 1.4 */
		// End offset: 0x8004D63C
		// End Line: 7030
	/* end block 1 */
	// End offset: 0x8004D63C
	// End Line: 7036

	/* begin block 2 */
		// Start line: 16553
	/* end block 2 */
	// End Line: 16554

void FX_StartInstanceEffect(_Instance *instance,ObjectEffect *effect,int InitFlag)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  ulong uVar4;
  _FXParticle *p_Var5;
  PhysObSplinter *pPVar6;
  long lVar7;
  uint *puVar8;
  uint motor1_speed;
  uint uVar9;
  FXSplinter *splintDef;
  short sVar10;
  undefined *local_20 [2];
  
  local_20[0] = &DAT_00004080;
  switch(effect->effectNumber) {
  case '\x01':
    FX_TorchFlame(instance,(ushort)effect->modifierList[0]);
    break;
  case '\x02':
    if ((uint)effect->modifierList[1] - 1 < 5) {
      local_20[0] = (undefined *)(&FX_ColorArray)[effect->modifierList[1]];
    }
    FX_DoInstanceOneSegmentGlow
              (instance,(uint)effect->modifierList[0],(long *)local_20,1,0x400,0x32,100);
    break;
  case '\x03':
    motor1_speed = (uint)effect->modifierList[1];
    if (effect->modifierList[1] == 0) {
      motor1_speed = 1;
    }
    if ((uint)effect->modifierList[2] - 1 < 5) {
      local_20[0] = (undefined *)(&FX_ColorArray)[effect->modifierList[2]];
    }
    FX_DoInstanceManySegmentGlow
              (instance,(uint)effect->modifierList[0],motor1_speed,(long *)local_20,1,0x400,0x41);
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
    uVar4 = INSTANCE_Query(instance,0x16);
    if ((uVar4 != 0) &&
       (p_Var5 = FX_StartGenericParticle
                           (instance,(uint)effect->modifierList[0],(uint)effect->modifierList[1],
                            (uint)effect->modifierList[2],InitFlag), p_Var5 != (_FXParticle *)0x0))
    {
      (p_Var5->direction).x = *(short *)(uVar4 + 2);
      (p_Var5->direction).y = *(short *)(uVar4 + 4);
      (p_Var5->direction).z = *(short *)(uVar4 + 6);
      uVar2 = *(ushort *)(uVar4 + 8);
      p_Var5->birthRadius = 0;
      *(code **)&p_Var5->fxprim_modify_process = FX_UpdraftPrimModify;
      p_Var5->primLifeTime = uVar2 >> 3;
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
    if (InitFlag != 0) {
      return;
    }
  case '\x12':
    FX_StartGenericBlastring
              (instance,(uint)effect->modifierList[0],(uint)effect->modifierList[1],
               (uint)effect->modifierList[2]);
    break;
  case '\x10':
    if (InitFlag == 0) {
      FX_StartGenericFlash(instance,(uint)effect->modifierList[0]);
    }
    break;
  case '\x11':
    splintDef = (FXSplinter *)0x0;
    if (InitFlag == 0) {
      puVar8 = (uint *)instance->object->data;
      sVar10 = 0;
      if ((instance->object->oflags2 & 0x40000U) == 0) {
        if ((puVar8 != (uint *)0x0) && (splintDef = (FXSplinter *)puVar8[1], (*puVar8 & 2) != 0)) {
          sVar10 = 0x10;
        }
      }
      else {
        pPVar6 = PhysObGetSplinter(instance);
        if (pPVar6 != (PhysObSplinter *)0x0) {
          splintDef = (FXSplinter *)pPVar6->splinterData;
          sVar10 = 0;
        }
      }
      _FX_BuildSplinters(instance,(SVECTOR *)0x0,(SVECTOR *)0x0,(SVECTOR *)0x0,splintDef,gFXT,
                         (TDRFuncPtr__FX_BuildSplinters6fxSetup)0x0,
                         (TDRFuncPtr__FX_BuildSplinters7fxProcess)0x0,(int)sVar10);
    }
    break;
  case '\x13':
    GAMEPAD_Shock0((uint)effect->modifierList[0],(uint)effect->modifierList[1] << 0xc);
    break;
  case '\x14':
    bVar1 = effect->modifierList[1];
    motor1_speed = (uint)effect->modifierList[0];
    goto LAB_8004d634;
  case '\x15':
    lVar7 = MATH3D_DistanceBetweenPositions(&instance->position,(_Position *)&theCamera);
    uVar9 = (uint)effect->modifierList[0];
    iVar3 = (int)((int)(&DAT_00001f40 + -lVar7) * uVar9) / 8000;
    motor1_speed = iVar3 + 0x32;
    if (iVar3 < 1) {
      return;
    }
    if ((int)uVar9 < (int)motor1_speed) {
      motor1_speed = uVar9;
    }
    bVar1 = effect->modifierList[1];
LAB_8004d634:
    GAMEPAD_Shock1(motor1_speed,(uint)bVar1 << 0xc);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_EndInstanceEffects(struct _Instance *instance /*$s1*/)
 // line 7040, offset 0x8004d658
	/* begin block 1 */
		// Start line: 7041
		// Start offset: 0x8004D658
		// Variables:
	// 		struct _FXGeneralEffect *currentEffect; // $a0
	// 		struct _FXGeneralEffect *nextEffect; // $s0
	/* end block 1 */
	// End offset: 0x8004D698
	// End Line: 7054

	/* begin block 2 */
		// Start line: 16994
	/* end block 2 */
	// End Line: 16995

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
// void /*$ra*/ FX_EndInstanceParticleEffects(struct _Instance *instance /*$s2*/)
 // line 7057, offset 0x8004d6ac
	/* begin block 1 */
		// Start line: 7058
		// Start offset: 0x8004D6AC
		// Variables:
	// 		struct _FXGeneralEffect *currentEffect; // $a0
	// 		struct _FXGeneralEffect *nextEffect; // $s0
	/* end block 1 */
	// End offset: 0x8004D704
	// End Line: 7071

	/* begin block 2 */
		// Start line: 17032
	/* end block 2 */
	// End Line: 17033

void FX_EndInstanceParticleEffects(_Instance *instance)

{
  _FXGeneralEffect *effect;
  _FXGeneralEffect *p_Var1;
  
  effect = FX_GeneralEffectTracker;
  if (FX_GeneralEffectTracker != (_FXGeneralEffect *)0x0) {
    do {
      p_Var1 = (_FXGeneralEffect *)effect->next;
      if ((effect->instance == instance) && (effect->effectType == '\x01')) {
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
 // line 7081, offset 0x8004d71c
	/* begin block 1 */
		// Start line: 7082
		// Start offset: 0x8004D71C
		// Variables:
	// 		int prevx; // $a0
	// 		int prevy; // $v0
	/* end block 1 */
	// End offset: 0x8004D7C8
	// End Line: 7096

	/* begin block 2 */
		// Start line: 17084
	/* end block 2 */
	// End Line: 17085

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
 // line 7125, offset 0x8004d7f0
	/* begin block 1 */
		// Start line: 7126
		// Start offset: 0x8004D7F0
		// Variables:
	// 		int x1; // stack offset -32
	// 		int y1; // stack offset -28
	// 		int x2; // stack offset -24
	// 		int y2; // stack offset -20
	/* end block 1 */
	// End offset: 0x8004D890
	// End Line: 7133

	/* begin block 2 */
		// Start line: 17176
	/* end block 2 */
	// End Line: 17177

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
 // line 7137, offset 0x8004d8bc
	/* begin block 1 */
		// Start line: 7138
		// Start offset: 0x8004D8BC
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
	// End offset: 0x8004DB4C
	// End Line: 7200

	/* begin block 2 */
		// Start line: 17203
	/* end block 2 */
	// End Line: 17204

/* WARNING: Could not reconcile some variable overlaps */

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
  DVECTOR_800d3a68.vx = (short)local_48;
  DVECTOR_800d3a68.vy = (short)local_44;
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
      FX_GetSpiralPoint((int)(&UNK_00002040 + next_deg),deg,&local_40,&local_3c);
      FX_GetSpiralPoint(next_deg + -0x17c0,deg,&local_38,&local_34);
    }
    (&Spiral_Array)[iVar1].vx = (short)local_48;
    (&Spiral_Array)[iVar1].vy = (short)local_44;
    if (iVar1 == 0x3f) {
      local_40 = local_48;
      local_3c = local_44;
      local_38 = local_48;
      local_34 = local_44;
    }
    (&Spiral_OffsetP)[iVar1].vx = (short)local_40;
    (&Spiral_OffsetP)[iVar1].vy = (short)local_3c;
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
    (&Spiral_OffsetM)[iVar1].vx = (short)local_38;
    (&Spiral_OffsetM)[iVar1].vy = (short)local_34;
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
 // line 7220, offset 0x8004dbb4
	/* begin block 1 */
		// Start line: 7221
		// Start offset: 0x8004DBB4
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
	// 		static short cnt; // offset 0x6c
	// 		int current_cnt; // stack offset -72
	// 		int max64; // $a0
	// 		long SPIRAL_COLOR; // $t3
	// 		long SPIRAL_COLOR2; // $t2
	// 		long SPIRAL_COLOR3; // stack offset -68
	// 		long SPIRAL_COLOR_END; // $s5
	// 		long SPIRAL_NOCOLOR; // $a2

		/* begin block 1.1 */
			// Start line: 7357
			// Start offset: 0x8004DDB0
			// Variables:
		// 		int tmp; // $v1
		/* end block 1.1 */
		// End offset: 0x8004DE0C
		// End Line: 7371

		/* begin block 1.2 */
			// Start line: 7454
			// Start offset: 0x8004DF50
			// Variables:
		// 		static short deg; // offset 0x6e
		// 		struct _Vector f1; // stack offset -96
		/* end block 1.2 */
		// End offset: 0x8004DFA4
		// End Line: 7469
	/* end block 1 */
	// End offset: 0x8004DFA4
	// End Line: 7475

	/* begin block 2 */
		// Start line: 17535
	/* end block 2 */
	// End Line: 17536

/* WARNING: Removing unreachable block (ram,0x8004ddc8) */

void FX_Spiral(_PrimPool *primPool,ulong **ot)

{
  short sVar1;
  uint angle;
  long lVar2;
  int iVar3;
  DVECTOR *pDVar4;
  DVECTOR DVar5;
  DVECTOR DVar6;
  DVECTOR *pDVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  DVECTOR DVar11;
  DVECTOR DVar12;
  DVECTOR DVar13;
  DVECTOR DVar14;
  int iVar15;
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
  
  if (((gameTrackerX.gameData.asmData.MorphTime != 1000) &&
      (gameTrackerX.gameData.asmData.MorphType == 0)) && (Spiral_Number != 0)) {
    FX_Health_Spiral(1,Spiral_Current,Spiral_Max);
  }
  DVar6 = (DVECTOR)0x3afcffd3;
  DVar5 = (DVECTOR)0x3adce0ba;
  DVar13 = (DVECTOR)0x3a483017;
  local_50 = (DVECTOR)0x3a002a15;
  local_44 = (DVECTOR)0x3abbc09d;
  if (Spiral_Number == 0) {
    if (Spiral_Current == Spiral_Max) {
      DAT_800d1068 = DAT_800d1068 + 1;
      if (0x50 < DAT_800d1068) {
        DAT_800d1068 = 0;
      }
    }
    else {
      DVar6 = (DVECTOR)0x3a00ff00;
      DVar5 = (DVECTOR)0x3a00e000;
      local_44 = (DVECTOR)0x3a00bf00;
      DVar13 = (DVECTOR)0x3a004500;
    }
    local_50 = (DVECTOR)0x3a00150b;
  }
  else {
    DAT_800d1068 = DAT_800d1068 + 1;
    if (0x50 < DAT_800d1068) {
      DAT_800d1068 = 0;
    }
  }
  lVar2 = Spiral_Max;
  if (Spiral_Max < 0) {
    lVar2 = Spiral_Max + 0x3f;
  }
  iVar3 = lVar2 >> 6;
  iVar15 = Spiral_Current / iVar3;
  puVar9 = primPool->nextPrim;
  iVar3 = ((Spiral_Current - iVar15 * iVar3) * 0x1000) / iVar3;
  if (puVar9 + 0x451 < primPool->lastPrim) {
    iVar8 = 0;
    pDVar4 = &local_50;
    local_40 = (uint)DVar6 & 0xff000000;
    local_48 = (int)DAT_800d1068;
    pDVar7 = (DVECTOR *)(puVar9 + 0x10);
    DVar11 = DVECTOR_800d3a68;
    DVar12 = DVECTOR_800d3a68;
    DVar14 = DVECTOR_800d3a68;
    local_4c = local_50;
    do {
      puVar10 = puVar9;
      pDVar7[-0xb] = local_50;
      pDVar7[-7] = local_50;
      if (iVar15 < iVar8) {
        local_50 = local_4c;
      }
      else {
        angle = (int)(iVar8 + local_48 & 0xfU) >> 2;
        local_50 = DVar5;
        if (angle != 1) {
          if (angle < 2) {
LAB_8004ddf4:
            local_50 = DVar6;
          }
          else {
            if (angle == 2) {
              local_50 = local_44;
            }
            else {
              if (angle != 3) goto LAB_8004ddf4;
            }
          }
        }
      }
      if (iVar8 == iVar15) {
        local_38 = pDVar4;
        local_34 = iVar3;
        local_30 = DVar5;
        local_2c = DVar6;
        LoadAverageCol((byte *)pDVar4,(byte *)&local_4c,iVar3,0x1000 - iVar3,(undefined *)pDVar4);
        local_50 = (DVECTOR)((uint)local_50 & 0xffffff | local_40);
        pDVar4 = local_38;
        iVar3 = local_34;
        DVar5 = local_30;
        DVar6 = local_2c;
      }
      pDVar7[-0xf] = DVar13;
      pDVar7[-0xd] = DVar13;
      pDVar7[-3] = DVar13;
      pDVar7[-1] = DVar13;
      pDVar7[-6] = DVar11;
      pDVar7[-10] = DVar11;
      pDVar7[-0xe] = DVar14;
      pDVar7[-2] = DVar12;
      pDVar7[-9] = local_50;
      pDVar7[-5] = local_50;
      DVar11 = (&Spiral_Array)[iVar8];
      DVar14 = (&Spiral_OffsetP)[iVar8];
      DVar12 = (&Spiral_OffsetM)[iVar8];
      iVar8 = iVar8 + 1;
      pDVar7[-4] = DVar11;
      pDVar7[-8] = DVar11;
      pDVar7[-0xc] = DVar14;
      *pDVar7 = DVar12;
      pDVar7 = pDVar7 + 0x11;
      *puVar10 = (uint)ot[1] & 0xffffff | 0x10000000;
      ot[1] = (ulong *)((uint)puVar10 & 0xffffff);
      puVar9 = puVar10 + 0x11;
    } while (iVar8 < 0x40);
    puVar10[0x12] = 0xe1000620;
    sVar1 = Spiral_Number;
    *puVar9 = (uint)ot[1] & 0xffffff | 0x1000000;
    ot[1] = (ulong *)((uint)puVar9 & 0xffffff);
    primPool->nextPrim = puVar10 + 0x13;
    if ((sVar1 != 0) || (Spiral_Current == Spiral_Max)) {
      local_60.y = Spiral_Glow_Y;
      angle = (uint)DAT_800d106a - 0x20 & 0xfff;
      local_60.x = Spiral_Glow_X;
      DAT_800d106a = (ushort)angle;
      DRAW_CreateAGlowingCircle
                (&local_60,0x140,gameTrackerX.primPool,ot,5,0x8000,Spiral_Glow_Size,Spiral_Glow_Size
                 ,angle);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Health_Spiral(int number /*$a0*/, int current_health /*$s0*/, int max_health /*$s1*/)
 // line 7477, offset 0x8004dfd4
	/* begin block 1 */
		// Start line: 7478
		// Start offset: 0x8004DFD4
		// Variables:
	// 		int degchange; // $v1
	/* end block 1 */
	// End offset: 0x8004E10C
	// End Line: 7525

	/* begin block 2 */
		// Start line: 18272
	/* end block 2 */
	// End Line: 18273

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
    if (Spiral_Degrees <= sVar2) goto LAB_8004e0f8;
    bVar1 = (short)(Spiral_Degrees + -4) < sVar2;
    Spiral_Degrees = Spiral_Degrees + -4;
  }
  if (bVar1) {
    Spiral_Degrees = sVar2;
  }
LAB_8004e0f8:
  FX_CalcSpiral((int)Spiral_Degrees);
  Spiral_Current = current_health;
  Spiral_Max = max_health;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Spiral_Init()
 // line 7527, offset 0x8004e120
	/* begin block 1 */
		// Start line: 18372
	/* end block 1 */
	// End Line: 18373

/* WARNING: Unknown calling convention yet parameter storage is locked */

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
 // line 7556, offset 0x8004e160
	/* begin block 1 */
		// Start line: 7557
		// Start offset: 0x8004E160
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
			// Start line: 7600
			// Start offset: 0x8004E28C
			// Variables:
		// 		long clip; // stack offset -48
		/* end block 1.1 */
		// End offset: 0x8004E384
		// End Line: 7628
	/* end block 1 */
	// End offset: 0x8004E3AC
	// End Line: 7635

	/* begin block 2 */
		// Start line: 18433
	/* end block 2 */
	// End Line: 18434

	/* begin block 3 */
		// Start line: 18445
	/* end block 3 */
	// End Line: 18446

void FX_DrawModel(Object *object,int model_num,_SVector *rotation,_SVector *position,
                 _SVector *offset,int transflag)

{
  ulong uVar1;
  ulong **ppuVar2;
  undefined4 in_zero;
  undefined4 in_at;
  _Model *p_Var3;
  _MVertex *p_Var4;
  _MVertex *p_Var5;
  _MVertex *p_Var6;
  ulong *puVar7;
  ushort *puVar8;
  int iVar9;
  _MFace *p_Var10;
  ulong uVar11;
  _MVertex *p_Var12;
  ulong *puVar13;
  MATRIX MStack88;
  short local_38;
  short local_36;
  short local_34;
  int local_30;
  
  ppuVar2 = gameTrackerX.drawOT;
  puVar13 = (gameTrackerX.primPool)->nextPrim;
  PushMatrix();
  MATH3D_SetUnityMatrix(&MStack88);
  RotMatrixX((int)rotation->x,(int)&MStack88);
  RotMatrixY((int)rotation->y,(uint *)&MStack88);
  RotMatrixZ((int)rotation->z,(uint *)&MStack88);
  PIPE3D_AspectAdjustMatrix(&MStack88);
  ApplyMatrixSV(&MStack88,offset,&local_38);
  MStack88.t[0] = (int)position->x + (int)local_38;
  MStack88.t[1] = (int)position->y + (int)local_36;
  MStack88.t[2] = (int)position->z + (int)local_34;
  SetRotMatrix((undefined4 *)&MStack88);
  SetTransMatrix((int)&MStack88);
  uVar11 = 0x34808080;
  if (transflag != 0) {
    uVar11 = 0x36909090;
  }
  if (object != (Object *)0x0) {
    p_Var3 = object->modelList[model_num];
    p_Var10 = p_Var3->faceList;
    p_Var12 = p_Var3->vertexList;
    iVar9 = p_Var3->numFaces + -1;
    if (iVar9 != -1) {
      puVar8 = &(p_Var10->face).v2;
      do {
        if ((gameTrackerX.primPool)->lastPrim <= puVar13 + 10) {
          (gameTrackerX.primPool)->nextPrim = puVar13;
          goto LAB_8004e3a4;
        }
        puVar7 = *(ulong **)(puVar8 + 2);
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
          *puVar13 = (uint)ppuVar2[1] & 0xffffff | 0x9000000;
          ppuVar2[1] = (ulong *)((uint)puVar13 & 0xffffff);
          puVar13 = puVar13 + 10;
        }
        puVar8 = puVar8 + 6;
        iVar9 = iVar9 + -1;
        p_Var10 = p_Var10 + 1;
      } while (iVar9 != -1);
    }
  }
  (gameTrackerX.primPool)->nextPrim = puVar13;
LAB_8004e3a4:
  PopMatrix();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ fx_calc_points(struct _SVector *points /*$s1*/, int degrees /*$s0*/, int radius /*$s3*/, int radius2 /*$s4*/, int radius3 /*stack 16*/)
 // line 7649, offset 0x8004e3d8
	/* begin block 1 */
		// Start line: 7650
		// Start offset: 0x8004E3D8
		// Variables:
	// 		int cosval; // $s0
	// 		int sinval; // $v0
	/* end block 1 */
	// End offset: 0x8004E3D8
	// End Line: 7650

	/* begin block 2 */
		// Start line: 18649
	/* end block 2 */
	// End Line: 18650

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
 // line 7667, offset 0x8004e4e8
	/* begin block 1 */
		// Start line: 7668
		// Start offset: 0x8004E4E8
		// Variables:
	// 		struct MATRIX tmpmat; // stack offset -40
	/* end block 1 */
	// End offset: 0x8004E530
	// End Line: 7676

	/* begin block 2 */
		// Start line: 18692
	/* end block 2 */
	// End Line: 18693

long fx_get_startz(_SVector *position)

{
  undefined4 in_zero;
  undefined4 in_at;
  undefined auStack40 [20];
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  setCopReg(2,in_zero,*(undefined4 *)position);
  setCopReg(2,in_at,*(undefined4 *)&position->z);
  copFunction(2,0x480012);
  local_14 = getCopReg(2,0x19);
  local_10 = getCopReg(2,0x1a);
  local_c = getCopReg(2,0x1b);
  SetTransMatrix((int)auStack40);
  if (local_c < 0) {
    local_c = local_c + 3;
  }
  return local_c >> 2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawRing(struct MATRIX *wcTransform /*$s0*/, struct _SVector *position /*$s3*/, struct MATRIX *matrix /*$s4*/, int radius /*stack 12*/, int radius2 /*stack 16*/, int radius3 /*stack 20*/, int z1 /*stack 24*/, int z2 /*stack 28*/, int z3 /*stack 32*/, long color /*stack 36*/, int sortInWorld /*stack 40*/)
 // line 7701, offset 0x8004e540
	/* begin block 1 */
		// Start line: 7702
		// Start offset: 0x8004E540
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
	// End offset: 0x8004E7BC
	// End Line: 7778

	/* begin block 2 */
		// Start line: 18761
	/* end block 2 */
	// End Line: 18762

	/* begin block 3 */
		// Start line: 18771
	/* end block 3 */
	// End Line: 18772

void FX_DrawRing(MATRIX *wcTransform,_SVector *position,MATRIX *matrix,int radius,int radius2,
                int radius3,int z1,int z2,int z3,long color,int sortInWorld)

{
  long lVar1;
  int iVar2;
  ulong *puVar3;
  ulong *puVar4;
  ulong *puVar5;
  uint uVar6;
  int iVar7;
  int degrees;
  _SVector _Stack96;
  undefined2 local_54;
  undefined2 local_4c;
  ulong local_48;
  ulong local_44;
  ulong local_40;
  int local_38;
  undefined4 local_34;
  int local_30;
  ulong **local_2c;
  
  puVar5 = (gameTrackerX.primPool)->nextPrim;
  local_2c = gameTrackerX.drawOT;
  if (puVar5 + 0x240 < (gameTrackerX.primPool)->lastPrim) {
    PushMatrix();
    SetRotMatrix((undefined4 *)wcTransform);
    SetTransMatrix((int)wcTransform);
    lVar1 = fx_get_startz(position);
    SetRotMatrix((undefined4 *)matrix);
    _Stack96.z = (short)z1;
    local_54 = (undefined2)z2;
    local_4c = (undefined2)z3;
    fx_calc_points(&_Stack96,0,radius,radius2,radius3);
    uVar6 = color | 0x3a000000;
    local_48 = getCopReg(2,0xc);
    local_44 = getCopReg(2,0xd);
    local_40 = getCopReg(2,0xe);
    iVar7 = 0;
    puVar4 = puVar5 + 0x11;
    degrees = 0x80;
    do {
      fx_calc_points(&_Stack96,degrees,radius,radius2,radius3);
      puVar4[-1] = 0x3a000000;
      puVar4[-3] = 0x3a000000;
      puVar4[-0xd] = 0x3a000000;
      puVar4[-0xf] = 0x3a000000;
      puVar4[-9] = uVar6;
      puVar4[-0xb] = uVar6;
      puVar4[-5] = uVar6;
      puVar4[-7] = uVar6;
      puVar4[-0xe] = local_40;
      puVar4[-10] = local_44;
      puVar4[-6] = local_44;
      puVar4[-0x10] = 0xe1000620;
      puVar4[-2] = local_48;
      local_48 = getCopReg(2,0xc);
      local_44 = getCopReg(2,0xd);
      local_40 = getCopReg(2,0xe);
      local_38 = getCopReg(2,0x11);
      local_34 = getCopReg(2,0x12);
      local_30 = getCopReg(2,0x13);
      puVar4[-0xc] = local_40;
      puVar4[-8] = local_44;
      puVar4[-4] = local_44;
      *puVar4 = local_48;
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
          puVar4 = puVar4 + 0x12;
          puVar3 = (ulong *)((uint)puVar5 & 0xffffff);
          *puVar5 = (uint)local_2c[local_38] & 0xffffff | 0x11000000;
          puVar5 = puVar5 + 0x12;
          local_2c[local_38] = puVar3;
        }
      }
      iVar7 = iVar7 + 1;
      degrees = degrees + 0x80;
    } while (iVar7 < 0x20);
    (gameTrackerX.primPool)->nextPrim = puVar5;
    PopMatrix();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ fx_setTex(struct DVECTOR *x /*$a0*/, unsigned char *uv /*$a1*/, int tx /*$a2*/, int offset /*$a3*/)
 // line 7781, offset 0x8004e7ec
	/* begin block 1 */
		// Start line: 18990
	/* end block 1 */
	// End Line: 18991

	/* begin block 2 */
		// Start line: 18991
	/* end block 2 */
	// End Line: 18992

void fx_setTex(DVECTOR *x,uchar *uv,int tx,int offset)

{
  uchar uVar1;
  
  *uv = *(char *)&x->vx - (char)tx;
  uVar1 = -1;
  if (x->vy < 0x100) {
    uVar1 = *(uchar *)&x->vy;
  }
  uv[1] = uVar1;
  x->vy = x->vy + (short)offset;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawRing2(struct MATRIX *wcTransform /*$s0*/, struct _SVector *position /*$s1*/, struct MATRIX *matrix /*$s3*/, int radius /*stack 12*/, int radius2 /*stack 16*/, int radius3 /*stack 20*/, int z1 /*stack 24*/, int z2 /*stack 28*/, int z3 /*stack 32*/, long offset /*stack 36*/, int sortInWorld /*stack 40*/)
 // line 7843, offset 0x8004e830
	/* begin block 1 */
		// Start line: 7844
		// Start offset: 0x8004E830
		// Variables:
	// 		int n; // $s3
	// 		struct POLY_FT4 *poly; // $s2
	// 		unsigned long **drawot; // stack offset -60
	// 		struct _SVector points[3]; // stack offset -112
	// 		long sxy[3]; // stack offset -88
	// 		long degrees; // $fp
	// 		long sz0; // stack offset -72
	// 		long sz1; // stack offset -68
	// 		long sz2; // stack offset -64
	// 		long startz; // stack offset -56
	// 		short tx; // $s0
	// 		long dispYPos; // $s0
	// 		int num_faces; // $s4
	// 		int deg_change; // stack offset -52
	/* end block 1 */
	// End offset: 0x8004EBD8
	// End Line: 7935

	/* begin block 2 */
		// Start line: 19114
	/* end block 2 */
	// End Line: 19115

/* WARNING: Could not reconcile some variable overlaps */

void FX_DrawRing2(MATRIX *wcTransform,_SVector *position,MATRIX *matrix,int radius,int radius2,
                 int radius3,int z1,int z2,int z3,long offset,int sortInWorld)

{
  ushort uVar1;
  bool bVar2;
  ushort uVar3;
  int tx;
  ulong *puVar4;
  uint uVar5;
  ulong *uv;
  ulong *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int degrees;
  _SVector _Stack112;
  undefined2 local_64;
  undefined2 local_5c;
  ulong local_58;
  undefined4 local_54;
  ulong local_50;
  int local_48;
  undefined4 local_44;
  int local_40;
  ulong **local_3c;
  long local_38;
  int local_34;
  uint local_30;
  
  degrees = 0;
  iVar8 = 0x20;
  local_3c = gameTrackerX.drawOT;
  if (radius < 0x78) {
    iVar8 = 8;
  }
  puVar6 = (gameTrackerX.primPool)->nextPrim;
  if (puVar6 + iVar8 * 10 < (gameTrackerX.primPool)->lastPrim) {
    PushMatrix();
    SetRotMatrix((undefined4 *)wcTransform);
    SetTransMatrix((int)wcTransform);
    local_38 = fx_get_startz(position);
    SetRotMatrix((undefined4 *)matrix);
    _Stack112.z = (short)z1;
    local_64 = (undefined2)z2;
    uVar5 = (gameTrackerX.gameData.asmData.dispPage ^ 1U) << 8;
    local_5c = (undefined2)z3;
    fx_calc_points(&_Stack112,0,radius,radius2,radius3);
    local_58 = getCopReg(2,0xc);
    local_54 = getCopReg(2,0xd);
    local_50 = getCopReg(2,0xe);
    local_34 = 0x1000 / iVar8;
    iVar7 = 0;
    if (iVar8 != 0) {
      uVar9 = (int)(uVar5 & 0x100) >> 4;
      uVar5 = (uVar5 & 0x200) << 2;
      local_30 = uVar9 | 0x100 | uVar5;
      uv = puVar6 + 9;
      do {
        degrees = degrees + local_34;
        fx_calc_points(&_Stack112,degrees,radius,radius2,radius3);
        uv[-8] = 0x2dc0c0c0;
        uv[-7] = local_50;
        uv[-3] = local_58;
        if ((short)(ushort)local_50 < (short)(ushort)local_58) {
          local_58._0_2_ = (ushort)local_50;
        }
        local_58 = getCopReg(2,0xc);
        local_54 = getCopReg(2,0xd);
        local_50 = getCopReg(2,0xe);
        local_48 = getCopReg(2,0x11);
        local_44 = getCopReg(2,0x12);
        local_40 = getCopReg(2,0x13);
        uv[-5] = local_50;
        uv[-1] = local_58;
        uVar1 = (ushort)local_58;
        if ((short)(ushort)local_50 < (short)(ushort)local_58) {
          uVar1 = (ushort)local_50;
        }
        if ((short)(ushort)local_58 < (short)uVar1) {
          uVar1 = (ushort)local_58;
        }
        tx = (int)(short)(uVar1 & 0xffc0);
        if (tx < -0x3f) {
          *(undefined2 *)((int)uv + -0xe) = (undefined2)local_30;
        }
        else {
          if (tx < 0) {
            uVar3 = (ushort)((int)(tx + 0x400U & 0x3ff) >> 6);
          }
          else {
            uVar3 = (ushort)(((uint)uVar1 & 0x3c0) >> 6);
          }
          *(ushort *)((int)uv + -0xe) = (ushort)uVar9 | uVar3 | 0x100 | (ushort)uVar5;
        }
        tx = (int)(short)(uVar1 & 0xffc0);
        fx_setTex((DVECTOR *)(puVar6 + 2),(uchar *)(puVar6 + 3),tx,offset);
        fx_setTex((DVECTOR *)(puVar6 + 4),(uchar *)(puVar6 + 5),tx,offset);
        fx_setTex((DVECTOR *)(puVar6 + 6),(uchar *)(puVar6 + 7),tx,offset);
        fx_setTex((DVECTOR *)(puVar6 + 8),(uchar *)uv,tx,offset);
        if (local_40 < local_48) {
          local_48 = local_40;
        }
        if (local_48 < 0) {
          local_48 = local_48 + 3;
        }
        local_48 = local_48 >> 2;
        if (0 < local_48) {
          if ((sortInWorld == 0) &&
             (bVar2 = local_48 <= local_38, local_48 = local_38 + 0x10, bVar2)) {
            local_48 = 1;
          }
          if (local_48 - 1U < 0xbff) {
            uv = uv + 10;
            puVar4 = (ulong *)((uint)puVar6 & 0xffffff);
            *puVar6 = (uint)local_3c[local_48] & 0xffffff | 0x9000000;
            puVar6 = puVar6 + 10;
            local_3c[local_48] = puVar4;
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar8);
    }
    (gameTrackerX.primPool)->nextPrim = puVar6;
    PopMatrix();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawFField(struct MATRIX *wcTransform /*$s2*/, struct _FXForceFieldEffect *field /*$s0*/)
 // line 7960, offset 0x8004ec08
	/* begin block 1 */
		// Start line: 7961
		// Start offset: 0x8004EC08
		// Variables:
	// 		struct _Instance *instance; // $a0
	// 		struct MATRIX tmpmat; // stack offset -64
	// 		struct _SVector position; // stack offset -32
	// 		int size; // $s1
	// 		short fade; // $v0
	// 		long color; // stack offset -20
	// 		long black; // stack offset -24
	/* end block 1 */
	// End offset: 0x8004EDE4
	// End Line: 8015

	/* begin block 2 */
		// Start line: 19450
	/* end block 2 */
	// End Line: 19451

void FX_DrawFField(MATRIX *wcTransform,_FXForceFieldEffect *field)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  _Instance *p_Var4;
  int iVar5;
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
    iVar5 = (uint)(ushort)field->end_fade - 0x200;
    if (field->end_fade == 0) {
      sVar2 = 0;
    }
    else {
      sVar2 = (short)iVar5;
      field->end_fade = sVar2;
      if (iVar5 * 0x10000 < 1) {
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
  iVar5 = (int)sVar2;
  if (iVar5 == 0) {
    local_14 = field->color;
  }
  else {
    LoadAverageCol((byte *)&field->color,(byte *)&local_18,0x1000 - iVar5,iVar5,
                   (undefined *)&local_14);
  }
  local_14 = local_14 & 0xffffff;
  MATH3D_SetUnityMatrix(&MStack64);
  RotMatrixZ(0x400,(uint *)&MStack64);
  if (field->type == '\x01') {
    PIPE3D_AspectAdjustMatrix(&MStack64);
  }
  else {
    RotMatrixX((int)theCamera.core.rotation.x,(int)&MStack64);
  }
  FX_DrawRing(wcTransform,&local_20,&MStack64,(int)field->size - iVar3,(int)field->size,
              field->size - iVar3,0,0,0,local_14,1);
  return;
}



// decompiled code
// original method signature: 
// struct _FXForceFieldEffect * /*$ra*/ FX_StartFField(struct _Instance *instance /*$s2*/, int size /*$s3*/, struct _Position *offset /*$s1*/, int size_diff /*$s4*/, int size_change /*stack 16*/, int deg_change /*stack 20*/, long color /*stack 24*/)
 // line 8017, offset 0x8004edfc
	/* begin block 1 */
		// Start line: 8018
		// Start offset: 0x8004EDFC
		// Variables:
	// 		struct _FXForceFieldEffect *field; // $s0

		/* begin block 1.1 */
			// Start line: 8023
			// Start offset: 0x8004EE40
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a1
		// 		struct _SVector *_v0; // $v0
		/* end block 1.1 */
		// End offset: 0x8004EE40
		// End Line: 8023
	/* end block 1 */
	// End offset: 0x8004EEAC
	// End Line: 8041

	/* begin block 2 */
		// Start line: 19575
	/* end block 2 */
	// End Line: 19576

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
 // line 8044, offset 0x8004eed0
	/* begin block 1 */
		// Start line: 8046
		// Start offset: 0x8004EED0
		// Variables:
	// 		struct _FXGeneralEffect *currentEffect; // $v1

		/* begin block 1.1 */
			// Start line: 8050
			// Start offset: 0x8004EF08
		/* end block 1.1 */
		// End offset: 0x8004EF38
		// End Line: 8062
	/* end block 1 */
	// End offset: 0x8004EF48
	// End Line: 8065

	/* begin block 2 */
		// Start line: 19636
	/* end block 2 */
	// End Line: 19637

	/* begin block 3 */
		// Start line: 19637
	/* end block 3 */
	// End Line: 19638

void FX_EndFField(_Instance *instance)

{
  short sVar1;
  _FXGeneralEffect **pp_Var2;
  _FXGeneralEffect *p_Var3;
  
  p_Var3 = FX_GeneralEffectTracker;
  if (FX_GeneralEffectTracker != (_FXGeneralEffect *)0x0) {
    do {
      if ((p_Var3->instance == instance) && (p_Var3->effectType == -0x7a)) {
        if (*(short *)((int)&p_Var3[2].next + 2) == 0) {
          *(undefined2 *)&p_Var3[2].continue_process = 0x1000;
        }
        else {
          *(short *)&p_Var3[2].continue_process = 0x1000 - *(short *)((int)&p_Var3[2].next + 2);
          sVar1 = *(short *)&p_Var3[2].continue_process;
          *(undefined2 *)((int)&p_Var3[2].next + 2) = 0;
          if (sVar1 == 0) {
            *(undefined2 *)&p_Var3[2].continue_process = 1;
          }
        }
      }
      pp_Var2 = (_FXGeneralEffect **)&p_Var3->next;
      p_Var3 = *pp_Var2;
    } while (*pp_Var2 != (_FXGeneralEffect *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Draw_Glowing_Line(unsigned long **ot /*$t6*/, long otz /*$a0*/, struct DVECTOR *sxy0 /*$a2*/, struct DVECTOR *sxy1 /*$a3*/, struct DVECTOR *xy0 /*stack 16*/, struct DVECTOR *xy1 /*stack 20*/, long color /*stack 24*/, long color2 /*stack 28*/)
 // line 8067, offset 0x8004ef50
	/* begin block 1 */
		// Start line: 8068
		// Start offset: 0x8004EF50
		// Variables:
	// 		struct _POLY_2G4T *poly; // $t0
	// 		struct _PrimPool *primPool; // $t2
	// 		int negflag; // $t5
	/* end block 1 */
	// End offset: 0x8004F0E4
	// End Line: 8112

	/* begin block 2 */
		// Start line: 19682
	/* end block 2 */
	// End Line: 19683

void FX_Draw_Glowing_Line
               (ulong **ot,long otz,DVECTOR *sxy0,DVECTOR *sxy1,DVECTOR *xy0,DVECTOR *xy1,long color
               ,long color2)

{
  bool bVar1;
  _PrimPool *p_Var2;
  DVECTOR DVar3;
  ulong uVar4;
  ulong *puVar5;
  
  p_Var2 = gameTrackerX.primPool;
  if ((otz - 1U < 0xbff) &&
     (puVar5 = (gameTrackerX.primPool)->nextPrim, puVar5 + 0x12 < (gameTrackerX.primPool)->lastPrim)
     ) {
    bVar1 = (color & 0x1000000U) == 0;
    if (!bVar1) {
      color = color & 0xffffff;
    }
    puVar5[6] = color | 0x3a000000U;
    puVar5[10] = color | 0x3a000000U;
    puVar5[2] = 0x3a000000;
    puVar5[4] = 0;
    puVar5[8] = color2;
    puVar5[0xc] = color2;
    puVar5[0xe] = 0;
    puVar5[0x10] = 0;
    DVar3 = *sxy0;
    *(DVECTOR *)(puVar5 + 0xb) = DVar3;
    *(DVECTOR *)(puVar5 + 7) = DVar3;
    *(short *)(puVar5 + 3) = sxy0->vx + xy0->vx;
    *(short *)((int)puVar5 + 0xe) = sxy0->vy - xy0->vy;
    *(short *)(puVar5 + 0xf) = sxy0->vx - xy0->vx;
    *(short *)((int)puVar5 + 0x3e) = sxy0->vy + xy0->vy;
    DVar3 = *sxy1;
    *(DVECTOR *)(puVar5 + 0xd) = DVar3;
    *(DVECTOR *)(puVar5 + 9) = DVar3;
    *(short *)(puVar5 + 5) = sxy1->vx + xy1->vx;
    *(short *)((int)puVar5 + 0x16) = sxy1->vy - xy1->vy;
    *(short *)(puVar5 + 0x11) = sxy1->vx - xy1->vx;
    *(short *)((int)puVar5 + 0x46) = sxy1->vy + xy1->vy;
    if (bVar1) {
      uVar4 = 0xe1000620;
    }
    else {
      uVar4 = 0xe1000640;
    }
    puVar5[1] = uVar4;
    *puVar5 = (uint)ot[otz] & 0xffffff | 0x11000000;
    ot[otz] = (ulong *)((uint)puVar5 & 0xffffff);
    p_Var2->nextPrim = puVar5 + 0x12;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Lightning(struct MATRIX *wcTransform /*$s0*/, unsigned long **ot /*stack 4*/, struct MATRIX *mat /*stack 8*/, short deg /*$s1*/, struct _SVector *start /*stack 16*/, struct _SVector *end /*stack 20*/, int width /*stack 24*/, int small_width /*stack 28*/, int segs /*stack 32*/, int sine_size /*stack 36*/, int variation /*stack 40*/, long color /*stack 44*/, long glow_color /*stack 48*/)
 // line 8115, offset 0x8004f0ec
	/* begin block 1 */
		// Start line: 8116
		// Start offset: 0x8004F0EC
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
			// Start line: 8150
			// Start offset: 0x8004F1A0
			// Variables:
		// 		struct SVECTOR point; // stack offset -64

			/* begin block 1.1.1 */
				// Start line: 8158
				// Start offset: 0x8004F1F0
				// Variables:
			// 		int rsin_n4; // $s0
			/* end block 1.1.1 */
			// End offset: 0x8004F2DC
			// End Line: 8162

			/* begin block 1.1.2 */
				// Start line: 8166
				// Start offset: 0x8004F2EC
				// Variables:
			// 		int tmpdeg; // $s1
			/* end block 1.1.2 */
			// End offset: 0x8004F3B4
			// End Line: 8170

			/* begin block 1.1.3 */
				// Start line: 8184
				// Start offset: 0x8004F41C
				// Variables:
			// 		int fx; // $s2
			// 		int fy; // $s0
			/* end block 1.1.3 */
			// End offset: 0x8004F464
			// End Line: 8192
		/* end block 1.1 */
		// End offset: 0x8004F580
		// End Line: 8214
	/* end block 1 */
	// End offset: 0x8004F5AC
	// End Line: 8223

	/* begin block 2 */
		// Start line: 19785
	/* end block 2 */
	// End Line: 19786

/* WARNING: Could not reconcile some variable overlaps */

void FX_Lightning(MATRIX *wcTransform,ulong **ot,MATRIX *mat,short deg,_SVector *start,_SVector *end
                 ,int width,int small_width,int segs,int sine_size,int variation,long color,
                 long glow_color)

{
  undefined4 in_zero;
  undefined4 in_at;
  int iVar1;
  int iy;
  int ix;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int otz;
  DVECTOR local_70 [2];
  DVECTOR local_68 [2];
  DVECTOR local_60 [2];
  DVECTOR local_58 [2];
  DVECTOR local_50 [2];
  DVECTOR local_48 [2];
  undefined4 local_40;
  uint local_3c;
  int local_38;
  int local_34;
  uint local_30;
  
  local_30 = (uint)(ushort)deg & 0xfff;
  if (mat == (MATRIX *)0x0) {
    SetRotMatrix((undefined4 *)wcTransform);
  }
  else {
    SetRotMatrix((undefined4 *)mat);
    wcTransform = mat;
  }
  otz = 0x7fff;
  SetTransMatrix((int)wcTransform);
  width = width * 0x140;
  small_width = small_width * 0x140;
  local_34 = 0x1000 / segs;
  iVar5 = 0;
  local_60[0] = (DVECTOR)0x0;
  local_50[0] = (DVECTOR)0x0;
  if (-1 < segs) {
    do {
      LoadAverageShort12((uint *)start,(uint *)end,0x1000 - iVar5,iVar5,&local_40);
      iVar1 = rsin(iVar5 / 2);
      if ((variation == 0) || (segs == 0)) {
LAB_8004f2dc:
        if (mat != (MATRIX *)0x0) goto LAB_8004f2ec;
      }
      else {
        if (mat == (MATRIX *)0x0) {
          iy = rsin(iVar5 << 2);
          ix = rand();
          iVar3 = variation / 2;
          ix = (ix % variation - iVar3) * iy;
          if (ix < 0) {
            ix = ix + 0xfff;
          }
          local_40 = local_40 & 0xffff0000 | (uint)(ushort)((short)local_40 + (short)(ix >> 0xc));
          ix = rand();
          iy = (ix % variation - iVar3) * iy;
          if (iy < 0) {
            iy = iy + 0xfff;
          }
          local_40 = local_40 & 0xffff | (uint)(ushort)(local_40._2_2_ + (short)(iy >> 0xc)) << 0x10
          ;
          iy = rsin(iVar5 + local_30);
          ix = rand();
          iy = iy * sine_size;
          if (iy < 0) {
            iy = iy + 0xfff;
          }
          iy = (iy >> 0xc) * iVar1;
          if (iy < 0) {
            iy = iy + 0xfff;
          }
          local_3c = local_3c & 0xffff0000 |
                     (uint)(ushort)((short)local_3c +
                                   (short)(iy >> 0xc) + ((short)(ix % variation) - (short)iVar3));
          goto LAB_8004f2dc;
        }
LAB_8004f2ec:
        uVar4 = local_30 + segs * 0x200;
        iy = rcos(uVar4);
        uVar2 = rand();
        iy = iy * sine_size;
        if (iy < 0) {
          iy = iy + 0xfff;
        }
        iy = ((iy >> 0xc) + (uVar2 & 7)) * iVar1;
        if (iy < 0) {
          iy = iy + 0xfff;
        }
        local_40 = local_40 & 0xffff0000 | iy >> 0xc & 0xffffU;
        iy = rsin(uVar4);
        uVar2 = rand();
        iy = iy * sine_size;
        if (iy < 0) {
          iy = iy + 0xfff;
        }
        iVar1 = ((iy >> 0xc) + (uVar2 & 7)) * iVar1;
        if (iVar1 < 0) {
          iVar1 = iVar1 + 0xfff;
        }
        local_40 = local_40 & 0xffff | (iVar1 >> 0xc) << 0x10;
        iVar1 = rand();
        local_3c = local_3c & 0xffff0000 | (uint)(ushort)((short)local_3c + ((ushort)iVar1 & 7));
      }
      setCopReg(2,in_zero,local_40);
      setCopReg(2,in_at,local_3c);
      copFunction(2,0x180001);
      local_68[0] = getCopReg(2,0xe);
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
      if ((segs == 0) || (iVar5 == 0)) {
        local_58[0] = (DVECTOR)0x0;
        local_48[0] = (DVECTOR)0x0;
      }
      else {
        ix = (int)local_68[0].vx - (int)local_70[0].vx;
        local_68[0].vy = (short)((uint)local_68[0] >> 0x10);
        iy = (int)local_68[0].vy - (int)local_70[0].vy;
        iVar1 = MATH3D_veclen2(ix,iy);
        iVar1 = iVar1 * local_38;
        if (iVar1 < 1) {
          iVar1 = 1;
        }
        local_58[0] = (DVECTOR)((iy * width) / iVar1 & 0xffffU | (ix * width) / iVar1 << 0x10);
        local_48[0] = (DVECTOR)((iy * small_width) / iVar1 & 0xffffU |
                               (ix * small_width) / iVar1 << 0x10);
      }
      if (((iVar5 != 0) && (0 < otz)) && (otz < 0xc00)) {
        if (width != 0) {
          FX_Draw_Glowing_Line(ot,otz,local_70,local_68,local_60,local_58,glow_color,glow_color);
        }
        if ((0 < otz + -5) && (small_width != 0)) {
          FX_Draw_Glowing_Line(ot,otz + -5,local_70,local_68,local_50,local_48,color,color);
        }
      }
      segs = segs + -1;
      local_70[0] = local_68[0];
      local_60[0] = local_58[0];
      local_50[0] = local_48[0];
      iVar5 = iVar5 + local_34;
      otz = local_38;
    } while (-1 < segs);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_LightHouse(struct MATRIX *wcTransform /*$s0*/, unsigned long **ot /*stack 4*/, struct _Instance *instance /*$a2*/, int startSeg /*$a3*/, int endSeg /*stack 16*/, int segs /*stack 20*/, long beam_color /*stack 24*/)
 // line 8228, offset 0x8004f5dc
	/* begin block 1 */
		// Start line: 8229
		// Start offset: 0x8004F5DC
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
			// Start line: 8288
			// Start offset: 0x8004F724
			// Variables:
		// 		struct SVECTOR point; // stack offset -88

			/* begin block 1.1.1 */
				// Start line: 8299
				// Start offset: 0x8004F79C
				// Variables:
			// 		int newlength; // $v1
			// 		int newfx; // $s1
			// 		int newfy; // $s0
			/* end block 1.1.1 */
			// End offset: 0x8004F7E0
			// End Line: 8313
		/* end block 1.1 */
		// End offset: 0x8004F800
		// End Line: 8320

		/* begin block 1.2 */
			// Start line: 8331
			// Start offset: 0x8004F834
			// Variables:
		// 		struct SVECTOR point; // stack offset -80

			/* begin block 1.2.1 */
				// Start line: 8353
				// Start offset: 0x8004F91C
				// Variables:
			// 		int x; // $v0
			/* end block 1.2.1 */
			// End offset: 0x8004F9A8
			// End Line: 8365
		/* end block 1.2 */
		// End offset: 0x8004F9F8
		// End Line: 8374
	/* end block 1 */
	// End offset: 0x8004FA28
	// End Line: 8384

	/* begin block 2 */
		// Start line: 20054
	/* end block 2 */
	// End Line: 20055

void FX_LightHouse(MATRIX *wcTransform,ulong **ot,_Instance *instance,int startSeg,int endSeg,
                  int segs,long beam_color)

{
  bool bVar1;
  undefined4 in_zero;
  undefined4 in_at;
  long lVar2;
  int iVar3;
  int iVar4;
  MATRIX *pMVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  _Position local_88;
  _Position local_80;
  DVECTOR local_78 [2];
  DVECTOR local_70 [2];
  DVECTOR local_68 [2];
  DVECTOR local_60 [2];
  uint local_58;
  undefined4 local_54;
  uint local_50;
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
      pMVar5 = instance->matrix + startSeg;
      local_88.x = *(short *)pMVar5->t;
      local_88.y = *(short *)(pMVar5->t + 1);
      local_88.z = *(short *)(pMVar5->t + 2);
      pMVar5 = instance->matrix + endSeg;
      local_80.x = *(short *)pMVar5->t;
      local_80.y = *(short *)(pMVar5->t + 1);
      local_80.z = *(short *)(pMVar5->t + 2);
      SetRotMatrix((undefined4 *)wcTransform);
      SetTransMatrix((int)wcTransform);
      local_38 = beam_color;
      local_68[0] = (DVECTOR)0x0;
      local_3c = beam_color;
      local_44 = beam_color;
      local_40 = 0;
      lVar2 = MATH3D_DistanceBetweenPositions(&local_88,&local_80);
      iVar3 = (lVar2 / 2) * 0x420;
      iVar9 = 0;
      if (iVar3 < 0) {
        iVar3 = iVar3 + 0xfff;
      }
      iVar8 = 0;
      local_2c = (iVar3 >> 0xc) + 0x60;
      local_30 = 0;
      local_34 = 0;
      iVar3 = segs;
      if (segs < 0) {
        iVar3 = segs + 3;
      }
      iVar3 = iVar3 >> 2;
      iVar10 = 0x1000 / iVar3;
      if (-1 < iVar3) {
        do {
          LoadAverageShort12((uint *)&local_88,(uint *)&local_80,0x1000 - iVar8,iVar8,&local_58);
          setCopReg(2,in_zero,local_58);
          setCopReg(2,in_at,local_54);
          copFunction(2,0x180001);
          local_70[0] = getCopReg(2,0xe);
          local_48 = getCopReg(2,0x13);
          if (bVar1) {
            if (0xf0 < local_48) {
              iVar6 = (int)local_70[0].vx;
              if ((-0x200 < iVar6) && (iVar6 < 0x200)) {
                local_70[0].vy = (short)((uint)local_70[0] >> 0x10);
                iVar4 = MATH3D_veclen2(iVar6 - local_78[0].vx,
                                       (int)local_70[0].vy - (int)local_78[0].vy);
                if ((iVar9 < iVar4) && (iVar4 < 0x100)) {
                  iVar9 = iVar4;
                  local_34 = iVar6 - local_78[0].vx;
                  local_30 = (int)local_70[0].vy - (int)local_78[0].vy;
                }
              }
              goto LAB_8004f7e0;
            }
          }
          else {
LAB_8004f7e0:
            if (0xf0 < local_48) {
              bVar1 = true;
              local_78[0] = local_70[0];
            }
          }
          iVar3 = iVar3 + -1;
          iVar8 = iVar8 + iVar10;
        } while (-1 < iVar3);
      }
      if (iVar9 != 0) {
        iVar8 = 0x1000 / segs;
        iVar3 = 0;
        if (-1 < segs) {
          iVar6 = 0;
          iVar10 = 0x7fff;
          do {
            LoadAverageShort12((uint *)&local_88,(uint *)&local_80,0x1000 - iVar3,iVar3,&local_50);
            iVar4 = (local_2c + -0x60) * iVar3;
            if (iVar4 < 0) {
              iVar4 = iVar4 + 0xfff;
            }
            iVar7 = ((iVar4 >> 0xc) + 0x60) * 0x140;
            iVar4 = 0x1000 - iVar6;
            if ((0x7ff < iVar3) && (iVar4 = 0, 0x800 < iVar3)) {
              iVar4 = iVar6 + -0x1000;
            }
            LoadAverageCol((byte *)&local_44,(byte *)&local_40,0x1000 - iVar4,iVar4,
                           (undefined *)&local_3c);
            setCopReg(2,in_zero,local_50);
            setCopReg(2,in_at,local_4c);
            copFunction(2,0x180001);
            local_70[0] = getCopReg(2,0xe);
            local_48 = getCopReg(2,0x13);
            if (iVar10 < local_48) {
              if (iVar10 < 0) {
                iVar10 = iVar10 + 3;
              }
            }
            else {
              iVar10 = local_48;
              if (local_48 < 0) {
                iVar10 = local_48 + 3;
              }
            }
            if (iVar3 != 0) {
              if (local_48 < 1) {
                local_48 = 1;
              }
              local_60[0] = (DVECTOR)(((local_30 * iVar7) / (iVar9 * local_48) << 9) / 0x140 &
                                      0xffffU | (local_34 * iVar7) / (iVar9 * local_48) << 0x10);
            }
            if (iVar3 == iVar8) {
              local_68[0] = local_60[0];
            }
            if ((iVar3 != 0) && (0 < iVar10 >> 2)) {
              FX_Draw_Glowing_Line
                        (ot,iVar10 >> 2,local_78,local_70,local_68,local_60,local_38,local_3c);
            }
            iVar6 = iVar6 + iVar8 * 2;
            iVar3 = iVar3 + iVar8;
            local_38 = local_3c;
            local_78[0] = local_70[0];
            local_68[0] = local_60[0];
            segs = segs + -1;
            iVar10 = local_48;
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
 // line 8387, offset 0x8004fa58
	/* begin block 1 */
		// Start line: 8388
		// Start offset: 0x8004FA58
		// Variables:
	// 		long color; // stack offset -24
	/* end block 1 */
	// End offset: 0x8004FA58
	// End Line: 8388

	/* begin block 2 */
		// Start line: 20449
	/* end block 2 */
	// End Line: 20450

void FX_StartPassthruFX(_Instance *instance,_SVector *normal,_SVector *point)

{
  long local_18 [2];
  
  (instance->halvePlane).a = normal->x;
  (instance->halvePlane).b = normal->y;
  (instance->halvePlane).c = normal->z;
  local_18[0] = 0x20ff40;
  (instance->halvePlane).d =
       -((int)normal->x * (int)point->x + (int)normal->y * (int)point->y +
         (int)normal->z * (int)point->z >> 0xc);
  FX_DoInstancePowerRing(instance,(long)&DAT_000020d0,local_18,0,2);
  FX_DoInstancePowerRing(instance,(long)&DAT_000020d0,local_18,0,1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_EndPassthruFX(struct _Instance *instance /*$a0*/)
 // line 8405, offset 0x8004fb34
	/* begin block 1 */
		// Start line: 20501
	/* end block 1 */
	// End Line: 20502

void FX_EndPassthruFX(_Instance *instance)

{
  FX_EndInstanceEffects(instance);
  return;
}





