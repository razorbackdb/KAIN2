#include "THISDUST.H"
#include "FX.H"


// decompiled code
// original method signature: 
// void /*$ra*/ FX_Init(struct _FXTracker *fxTracker /*$s1*/)
 // line 111, offset 0x800434e0
	/* begin block 1 */
		// Start line: 112
		// Start offset: 0x800434E0
		// Variables:
	// 		struct _FX_MATRIX *fxMatrix; // $s0
	// 		struct _FX_MATRIX *endFXMatrix; // $s2
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct _FX_PRIM *endFXPrim; // $s2
	/* end block 1 */
	// End offset: 0x80043578
	// End Line: 138

	/* begin block 2 */
		// Start line: 222
	/* end block 2 */
	// End Line: 223

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
  FX_reaver_instance = (_Instance *)0x0;
  FX_Frames = 1;
  FX_TimeCount = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Die(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$s1*/)
 // line 163, offset 0x800435c0
	/* begin block 1 */
		// Start line: 321
	/* end block 1 */
	// End Line: 322

	/* begin block 2 */
		// Start line: 356
	/* end block 2 */
	// End Line: 357

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
 // line 180, offset 0x80043630
	/* begin block 1 */
		// Start line: 181
		// Start offset: 0x80043630
		// Variables:
	// 		struct _FX_MATRIX *fxMatrix; // $s0
	/* end block 1 */
	// End offset: 0x80043668
	// End Line: 190

	/* begin block 2 */
		// Start line: 392
	/* end block 2 */
	// End Line: 393

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
 // line 194, offset 0x80043680
	/* begin block 1 */
		// Start line: 195
		// Start offset: 0x80043680
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $a0
	/* end block 1 */
	// End offset: 0x800436E0
	// End Line: 216

	/* begin block 2 */
		// Start line: 421
	/* end block 2 */
	// End Line: 422

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
 // line 219, offset 0x800436f0
	/* begin block 1 */
		// Start line: 220
		// Start offset: 0x800436F0
		// Variables:
	// 		struct _FXParticle *particle; // $v1
	/* end block 1 */
	// End offset: 0x80043774
	// End Line: 240

	/* begin block 2 */
		// Start line: 474
	/* end block 2 */
	// End Line: 475

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
 // line 243, offset 0x8004378c
	/* begin block 1 */
		// Start line: 531
	/* end block 1 */
	// End Line: 532

	/* begin block 2 */
		// Start line: 532
	/* end block 2 */
	// End Line: 533

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
// void /*$ra*/ FX_NoAutoAniTexSetup(struct _FX_PRIM *fxPrim /*$a3*/, struct _MFace *mface /*$a1*/, struct _Model *model /*$a2*/, struct _FXTracker *fxTracker /*$a3*/, struct _Instance *instance /*stack 16*/)
 // line 267, offset 0x80043840
	/* begin block 1 */
		// Start line: 268
		// Start offset: 0x80043840

		/* begin block 1.1 */
			// Start line: 274
			// Start offset: 0x80043874
			// Variables:
		// 		struct AniTexInfo *aniTexInfo; // $a0
		/* end block 1.1 */
		// End offset: 0x80043874
		// End Line: 276
	/* end block 1 */
	// End offset: 0x80043908
	// End Line: 292

	/* begin block 2 */
		// Start line: 585
	/* end block 2 */
	// End Line: 586

	/* begin block 3 */
		// Start line: 586
	/* end block 3 */
	// End Line: 587

void FX_NoAutoAniTexSetup
               (_FX_PRIM *fxPrim,_MFace *mface,_Model *model,_FXTracker *fxTracker,
               _Instance *instance)

{
  TextureMT3 *pTVar1;
  uint uVar2;
  uint uVar3;
  AniTex *pAVar4;
  
  if ((mface->flags & 2) == 0) {
    fxPrim->flags = fxPrim->flags & 0xfffffffa;
    uVar2 = mface->color;
    uVar3 = 0x20000000;
  }
  else {
    fxPrim->flags = fxPrim->flags | 1;
    pAVar4 = model->aniTextures;
    if (pAVar4 == (AniTex *)0x0) {
      pTVar1 = (TextureMT3 *)mface->color;
    }
    else {
      pTVar1 = (TextureMT3 *)
               (mface->color +
                (((uint)(int)instance->currentTextureAnimFrame / (uint)(pAVar4->aniTexInfo).speed) %
                (pAVar4->aniTexInfo).numFrames) * 0x10 + 0x10);
    }
    fxPrim->texture = pTVar1;
    uVar2 = fxPrim->texture->color;
    uVar3 = 0x24000000;
  }
  fxPrim->color = uVar2 & 0x3ffffff | uVar3;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_AniTexProcess(struct _FX_PRIM *fxPrim /*$a3*/, struct _FXTracker *fxTracker /*$t1*/)
 // line 294, offset 0x80043910
	/* begin block 1 */
		// Start line: 295
		// Start offset: 0x80043910
		// Variables:
	// 		struct AniTexInfo *aniTexInfo; // $v1
	// 		struct TextureMT3 *baseTex; // $t0
	// 		struct TextureMT3 *src; // $v0
	// 		unsigned long frame; // $a1
	// 		unsigned long lastFrame; // $v0
	/* end block 1 */
	// End offset: 0x800439C0
	// End Line: 324

	/* begin block 2 */
		// Start line: 643
	/* end block 2 */
	// End Line: 644

void FX_AniTexProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  AniTex *pAVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (gameTrackerX.gameMode != 6) {
    pAVar1 = (fxPrim->ani).aniTextures;
    uVar4 = SEXT24((fxPrim->ani).curFrame);
    uVar3 = (pAVar1->aniTexInfo).speed;
    uVar2 = (pAVar1->aniTexInfo).numFrames;
    uVar5 = (uVar4 / uVar3) % uVar2;
    if (((uVar5 == 0) && (uVar3 * uVar2 <= uVar4)) && (fxPrim->timeToLive == -1)) {
      FX_Die(fxPrim,fxTracker);
    }
    else {
      (fxPrim->ani).texMem = fxPrim->texture + uVar5 + 1;
      (fxPrim->ani).curFrame = (fxPrim->ani).curFrame + 1;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StandardProcess(struct _FX_PRIM *fxPrim /*$a0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 326, offset 0x800439d0
	/* begin block 1 */
		// Start line: 715
	/* end block 1 */
	// End Line: 716

void FX_StandardProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  FX_StandardFXPrimProcess(fxPrim,fxTracker);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ShatterProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$s1*/)
 // line 362, offset 0x800439f0
	/* begin block 1 */
		// Start line: 363
		// Start offset: 0x800439F0
		// Variables:
	// 		struct MATRIX matrix; // stack offset -64
	// 		struct _Rotation rotation; // stack offset -32
	// 		struct _Rotation rot_temp; // stack offset -24
	/* end block 1 */
	// End offset: 0x80043CA0
	// End Line: 409

	/* begin block 2 */
		// Start line: 787
	/* end block 2 */
	// End Line: 788

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
  short local_18;
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
      iVar5 = (int)(short)gameTrackerX.idleTime;
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
    if ((fxPrim->flags & 4U) != 0) {
      FX_AniTexProcess(fxPrim,fxTracker);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DFacadeProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$a2*/)
 // line 547, offset 0x80043cb4
	/* begin block 1 */
		// Start line: 548
		// Start offset: 0x80043CB4

		/* begin block 1.1 */
			// Start line: 560
			// Start offset: 0x80043D10
			// Variables:
		// 		struct MATRIX *swTransform; // $v1
		/* end block 1.1 */
		// End offset: 0x80043D10
		// End Line: 561

		/* begin block 1.2 */
			// Start line: 718
			// Start offset: 0x80043E38
			// Variables:
		// 		struct _Rotation rot; // stack offset -16
		/* end block 1.2 */
		// End offset: 0x80043E98
		// End Line: 726
	/* end block 1 */
	// End offset: 0x80043E98
	// End Line: 735

	/* begin block 2 */
		// Start line: 1056
	/* end block 2 */
	// End Line: 1057

void FX_DFacadeProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  char cVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  short sVar7;
  
  iVar5 = fxPrim->timeToLive;
  if (0 < iVar5) {
    fxPrim->timeToLive = iVar5 + -1;
    iVar5 = fxPrim->timeToLive;
  }
  if (iVar5 == 0) {
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
    if ((fxPrim->flags & 4U) != 0) {
      FX_AniTexProcess(fxPrim,fxTracker);
    }
    uVar6 = fxPrim->matrix->flags;
    if (((uVar6 & 2) == 0) && (fxPrim->matrix->flags = uVar6 | 2, (fxPrim->flags & 0x80U) != 0)) {
      cVar1 = *(char *)&fxPrim->work3;
      cVar2 = *(char *)((int)&fxPrim->work3 + 1);
      RotMatrixX((int)*(char *)((int)&fxPrim->work2 + 1) << 2,(int)&fxPrim->matrix->lwTransform);
      RotMatrixY((int)(short)((int)cVar1 << 2),(short *)&fxPrim->matrix->lwTransform);
      RotMatrixZ((int)(short)((int)cVar2 << 2),(short *)&fxPrim->matrix->lwTransform);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// struct _FX_PRIM * /*$ra*/ _FX_BuildSingleFaceWithModel(struct _Model *model /*$a0*/, struct _MFace *mface /*$s6*/, struct SVECTOR *center /*$s7*/, struct SVECTOR *vel /*$fp*/, struct SVECTOR *accl /*stack 16*/, struct _FXTracker *fxTracker /*stack 20*/, TDRFuncPtr__FX_BuildSingleFaceWithModel6fxSetup fxSetup /*stack 24*/, TDRFuncPtr__FX_BuildSingleFaceWithModel7fxProcess fxProcess /*stack 28*/, struct _FX_MATRIX *fxMatrix /*stack 32*/, int timeToLive /*stack 36*/)
 // line 818, offset 0x80043ea8
	/* begin block 1 */
		// Start line: 819
		// Start offset: 0x80043EA8
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s1
	// 		struct _MVertex *vertexList; // $s3
	/* end block 1 */
	// End offset: 0x80043F70
	// End Line: 847

	/* begin block 2 */
		// Start line: 1586
	/* end block 2 */
	// End Line: 1587

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
 // line 852, offset 0x80043fa4
	/* begin block 1 */
		// Start line: 1654
	/* end block 1 */
	// End Line: 1655

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
 // line 879, offset 0x80043ff4
	/* begin block 1 */
		// Start line: 880
		// Start offset: 0x80043FF4
		// Variables:
	// 		struct MATRIX lm; // stack offset -40
	/* end block 1 */
	// End offset: 0x80043FF4
	// End Line: 880

	/* begin block 2 */
		// Start line: 1752
	/* end block 2 */
	// End Line: 1753

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
 // line 890, offset 0x80044044
	/* begin block 1 */
		// Start line: 891
		// Start offset: 0x80044044
		// Variables:
	// 		long modelDQP; // $a2
	// 		long color; // stack offset -8
	// 		struct TextureMT3 *texture; // $a1
	/* end block 1 */
	// End offset: 0x80044150
	// End Line: 923

	/* begin block 2 */
		// Start line: 1706
	/* end block 2 */
	// End Line: 1707

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
 // line 938, offset 0x8004415c
	/* begin block 1 */
		// Start line: 939
		// Start offset: 0x8004415C
		// Variables:
	// 		long j; // $s4
	// 		long maxTimeToLive; // stack offset -80
	// 		long faceSkip; // stack offset -76
	// 		long numFaces; // $v0
	// 		struct _MFace *mface; // $s7
	// 		struct _MFace *endMFace; // stack offset -72
	// 		struct _Model *model; // stack offset -68
	// 		struct _MVertex *vertexList; // stack offset -64
	// 		struct _MFace *faceList; // $s0
	// 		struct _FX_MATRIX *fxMatrix; // $s3
	// 		struct _FX_MATRIX (*fxMatList[60]); // stack offset -960
	// 		struct _SVector veloc[60]; // stack offset -720
	// 		struct _SVector *curVel; // $s6
	// 		int lastFxMat; // $fp
	// 		unsigned char matIdx[128]; // stack offset -240
	// 		struct _FX_PRIM *fxPrim; // $s2
	// 		struct _SVector *vertex0; // $s0
	// 		struct _SVector *vertex1; // $s1
	// 		struct _SVector *vertex2; // $s4
	// 		struct _SVector *poolOfVertices; // stack offset -60
	// 		long *vtxSegment; // stack offset -56
	// 		struct _Vector Center; // stack offset -112
	// 		int seg0; // $s5
	// 		int seg1; // $a0
	// 		struct _SVector offset; // stack offset -96

		/* begin block 1.1 */
			// Start line: 1021
			// Start offset: 0x8004434C
			// Variables:
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $a1
		// 		short _y1; // $a3
		// 		short _z1; // $a2
		// 		struct _SVector *_v; // stack offset -48
		// 		struct _Vector *_v1; // $a2
		/* end block 1.1 */
		// End offset: 0x8004434C
		// End Line: 1021

		/* begin block 1.2 */
			// Start line: 1034
			// Start offset: 0x800443E0
		/* end block 1.2 */
		// End offset: 0x800444A0
		// End Line: 1045

		/* begin block 1.3 */
			// Start line: 1098
			// Start offset: 0x80044798
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
		// End offset: 0x80044798
		// End Line: 1098

		/* begin block 1.4 */
			// Start line: 1141
			// Start offset: 0x8004495C
		/* end block 1.4 */
		// End offset: 0x800449BC
		// End Line: 1146

		/* begin block 1.5 */
			// Start line: 1163
			// Start offset: 0x80044A30
		/* end block 1.5 */
		// End offset: 0x80044A78
		// End Line: 1169
	/* end block 1 */
	// End offset: 0x80044B6C
	// End Line: 1189

	/* begin block 2 */
		// Start line: 1804
	/* end block 2 */
	// End Line: 1805

	/* begin block 3 */
		// Start line: 1834
	/* end block 3 */
	// End Line: 1835

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
  uint uVar8;
  _FX_PRIM *fxPrim;
  long lVar9;
  short sVar10;
  CVECTOR CVar11;
  _MFace *mface;
  int iVar12;
  _PVertex *p_Var13;
  int iVar14;
  _PVertex *p_Var15;
  _PVertex *p_Var16;
  undefined2 *puVar17;
  _MFace *p_Var18;
  int iVar19;
  byte bVar20;
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
  iVar19 = 0;
  local_48 = mface + local_44->numFaces;
  if (mface < mface + local_44->numFaces) {
    local_34 = auStack720;
    local_30 = &local_60;
    do {
      CVar11 = local_38[(mface->face).v2];
      if ((int)local_38[(mface->face)._3] < (int)local_38[(mface->face).v2]) {
        CVar11 = local_38[(mface->face)._3];
      }
      if ((int)local_38[(mface->face)._2] < (int)CVar11) {
        CVar11 = local_38[(mface->face)._2];
      }
      if (abStack240[(int)CVar11] == 0xff) {
        if (iVar19 < 0x3c) {
          p_Var5 = FX_GetMatrix(fxTracker);
          if (p_Var5 == (_FX_MATRIX *)0x0) {
            if (iVar19 == 0) {
              return;
            }
            goto LAB_800445e4;
          }
          local_3c0[iVar19] = p_Var5;
          bVar20 = (byte)iVar19;
          local_60.y = *(short *)(instance->matrix[(int)CVar11].t + 1);
          local_60.z = *(short *)(instance->matrix[(int)CVar11].t + 2);
          local_60.x = *(short *)instance->matrix[(int)CVar11].t - local_70[0];
          local_30->y = local_30->y - local_6c;
          local_30->z = local_30->z - local_68;
          MATH3D_Normalize(local_30);
          if (splintDef == (FXSplinter *)0x0) {
            iVar14 = rand();
            puVar17 = (undefined2 *)(local_34 + iVar19 * 8);
            iVar7 = iVar14;
            if (iVar14 < 0) {
              iVar7 = iVar14 + 7;
            }
            *puVar17 = (short)((int)local_60.x * (iVar14 + (iVar7 >> 3) * -8 + 0x1a) >> 0xc);
            iVar14 = rand();
            iVar7 = iVar14;
            if (iVar14 < 0) {
              iVar7 = iVar14 + 7;
            }
            puVar17[1] = (short)((int)local_60.y * (iVar14 + (iVar7 >> 3) * -8 + 0x1a) >> 0xc);
            iVar14 = rand();
            iVar7 = iVar14;
            if (iVar14 < 0) {
              iVar7 = iVar14 + 7;
            }
            puVar17[2] = (short)((int)local_60.z * (iVar14 + (iVar7 >> 3) * -8 + 0x2e) >> 0xc);
          }
          else {
            iVar7 = (uint)(ushort)splintDef->chunkVelXY - (uint)(ushort)splintDef->chunkVelRng;
            iVar14 = (int)((uint)(ushort)splintDef->chunkVelRng << 0x11) >> 0x10;
            if (iVar14 == 0) {
              iVar7 = iVar7 * 0x10000 >> 0x10;
              puVar17 = (undefined2 *)(local_34 + iVar19 * 8);
              *puVar17 = (short)(local_60.x * iVar7 >> 0xc);
              puVar17[1] = (short)(local_60.y * iVar7 >> 0xc);
              puVar17[2] = (short)((int)local_60.z * (int)splintDef->chunkVelZ >> 0xc);
            }
            else {
              iVar6 = rand();
              iVar12 = iVar7 * 0x10000 >> 0x10;
              puVar17 = (undefined2 *)(local_34 + iVar19 * 8);
              *puVar17 = (short)((int)local_60.x * (iVar12 + iVar6 % iVar14) >> 0xc);
              iVar7 = rand();
              puVar17[1] = (short)((int)local_60.y * (iVar12 + iVar7 % iVar14) >> 0xc);
              uVar1 = splintDef->chunkVelZ;
              uVar2 = splintDef->chunkVelRng;
              iVar7 = rand();
              puVar17[2] = (short)((int)local_60.z *
                                   (((int)(((uint)uVar1 - (uint)uVar2) * 0x10000) >> 0x10) +
                                   iVar7 % iVar14) >> 0xc);
            }
          }
          puVar17 = (undefined2 *)(local_34 + iVar19 * 8);
          if ((int)((uint)(ushort)puVar17[2] << 0x10) < 0) {
            puVar17[2] = 0;
          }
          iVar19 = iVar19 + 1;
        }
        else {
LAB_800445e4:
          iVar7 = rand();
          iVar7 = iVar7 % iVar19;
          bVar20 = (byte)iVar7;
          p_Var5 = local_3c0[iVar7];
          puVar17 = (undefined2 *)(local_34 + iVar7 * 8);
        }
        abStack240[(int)CVar11] = bVar20;
      }
      else {
        uVar8 = (uint)abStack240[(int)CVar11];
        puVar17 = (undefined2 *)(local_34 + uVar8 * 8);
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
      (p_Var5->lwTransform).t[0] = instance->matrix[(int)CVar11].t[0];
      (p_Var5->lwTransform).t[1] = instance->matrix[(int)CVar11].t[1];
      (p_Var5->lwTransform).t[2] = instance->matrix[(int)CVar11].t[2];
      p_Var13 = local_3c->vertex + (mface->face)._2;
      p_Var15 = local_3c->vertex + (mface->face)._3;
      p_Var16 = local_3c->vertex + (mface->face).v2;
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
          (fxPrim->_2).x = p_Var13->x - local_60.x;
          (fxPrim->_2).y = (&p_Var13->x)[1] - local_60.y;
          (fxPrim->_2).z = (&p_Var13->x)[2] - local_60.z;
          (fxPrim->_3).x = p_Var15->x - local_60.x;
          (fxPrim->_3).y = (&p_Var15->x)[1] - local_60.y;
          (fxPrim->_3).z = (&p_Var15->x)[2] - local_60.z;
          (fxPrim->v2).x = p_Var16->x - local_60.x;
          (fxPrim->v2).y = (&p_Var16->x)[1] - local_60.y;
          sVar4 = (&p_Var16->x)[2];
          fxPrim->matrix = p_Var5;
          (fxPrim->v2).z = sVar4 - local_60.z;
          if ((instance->flags & 0x80U) == 0) {
            FX_AniTexSetup(fxPrim,mface,local_44,fxTracker);
          }
          else {
            FX_NoAutoAniTexSetup(fxPrim,mface,local_44,fxTracker,instance);
          }
          lVar9 = _FX_DoLighting(mface);
          fxPrim->color = lVar9;
          if (fxProcess == (TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess)0x0) {
            *(code **)&fxPrim->process = FX_ShatterProcess;
          }
          else {
            *(TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess *)&fxPrim->process = fxProcess;
          }
          *(undefined2 *)&fxPrim->duo = *puVar17;
          *(undefined2 *)((int)&fxPrim->duo + 2) = puVar17[1];
          *(undefined2 *)((int)&fxPrim->duo + 4) = puVar17[2];
          if (splintDef != (FXSplinter *)0x0) {
            sVar4 = splintDef->triVelRng;
            if ((int)sVar4 != 0) {
              sVar10 = -splintDef->triVelRng;
              iVar7 = rand();
              iVar14 = ((int)sVar4 << 0x11) >> 0x10;
              *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + sVar10 + (short)(iVar7 % iVar14);
              iVar7 = rand();
              *(short *)((int)&fxPrim->duo + 2) =
                   *(short *)((int)&fxPrim->duo + 2) + sVar10 + (short)(iVar7 % iVar14);
              iVar7 = rand();
              *(short *)((int)&fxPrim->duo + 4) =
                   *(short *)((int)&fxPrim->duo + 4) + sVar10 + (short)(iVar7 % iVar14);
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
          fxPrim->timeToLive = local_50;
          if (splintDef == (FXSplinter *)0x0) {
            *(undefined2 *)((int)&fxPrim->duo + 10) = 0xfff8;
            iVar14 = rand();
            iVar7 = iVar14;
            if (iVar14 < 0) {
              iVar7 = iVar14 + 7;
            }
            fxPrim->work3 = (short)iVar14 + (short)(iVar7 >> 3) * -8 + -4;
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
               (sVar4 = sVar3 + -0x32, (instance->object->oflags & 0x200U) != 0)) goto LAB_80044b28;
          }
          fxPrim->work0 = sVar4;
        }
        else {
          (*fxSetup)(fxPrim,fxProcess,p_Var5,instance,mface,local_40,center,vel,accl,fxTracker,0x1e)
          ;
        }
LAB_80044b28:
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
// void /*$ra*/ _FX_BuildNonSegmentedSplinters(struct _Instance *instance /*$fp*/, struct SVECTOR *center /*stack 4*/, struct SVECTOR *vel /*stack 8*/, struct SVECTOR *accl /*stack 12*/, struct FXSplinter *splintDef /*stack 16*/, struct _FXTracker *fxTracker /*stack 20*/, TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup fxSetup /*stack 24*/, TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess fxProcess /*stack 28*/, int shardFlags /*stack 32*/)
 // line 1200, offset 0x80044b9c
	/* begin block 1 */
		// Start line: 1201
		// Start offset: 0x80044B9C
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
	// 		struct _SVector *poolOfVertices; // stack offset -52
	// 		struct MATRIX *swTransform; // $s1
	// 		struct MATRIX ourM; // stack offset -184
	// 		struct _Vector Center; // stack offset -152
	// 		struct _SVector offset; // stack offset -136
	// 		struct _Normal faceNorm; // stack offset -128
	// 		struct _SVector sv_temp; // stack offset -120
	// 		struct _SVector sv_vels[4]; // stack offset -112

		/* begin block 1.1 */
			// Start line: 1242
			// Start offset: 0x80044CB4
			// Variables:
		// 		short start; // $v0
		/* end block 1.1 */
		// End offset: 0x80044DDC
		// End Line: 1268

		/* begin block 1.2 */
			// Start line: 1303
			// Start offset: 0x80044F98
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $s3
		// 		struct _SVector *_v1; // $a1
		/* end block 1.2 */
		// End offset: 0x80044F98
		// End Line: 1303

		/* begin block 1.3 */
			// Start line: 1363
			// Start offset: 0x80045304
			// Variables:
		// 		short _x0; // $a1
		// 		short _y0; // $v1
		// 		short _z0; // $v0
		// 		short _x1; // $a0
		// 		short _y1; // $a3
		// 		short _z1; // $a2
		// 		struct _SVector *_v; // stack offset -44
		// 		struct _Position *_v0; // $v0
		// 		struct _Vector *_v1; // $a2
		/* end block 1.3 */
		// End offset: 0x80045304
		// End Line: 1363

		/* begin block 1.4 */
			// Start line: 1406
			// Start offset: 0x800454B0
		/* end block 1.4 */
		// End offset: 0x800454B0
		// End Line: 1406

		/* begin block 1.5 */
			// Start line: 1432
			// Start offset: 0x800455FC
		/* end block 1.5 */
		// End offset: 0x80045644
		// End Line: 1438
	/* end block 1 */
	// End offset: 0x80045710
	// End Line: 1463

	/* begin block 2 */
		// Start line: 2627
	/* end block 2 */
	// End Line: 2628

/* WARNING: Could not reconcile some variable overlaps */

void _FX_BuildNonSegmentedSplinters
               (_Instance *instance,SVECTOR *center,SVECTOR *vel,SVECTOR *accl,FXSplinter *splintDef
               ,_FXTracker *fxTracker,TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup fxSetup,
               TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess fxProcess,int shardFlags)

{
  short sVar1;
  short sVar2;
  int iVar3;
  _FX_MATRIX *p_Var4;
  uint uVar5;
  _FX_PRIM *fxPrim;
  long lVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  ushort uVar10;
  _PVertex *p_Var11;
  int iVar12;
  _PVertex *p_Var13;
  _MFace *mface;
  _PVertex *p_Var14;
  _MFace *p_Var15;
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
  uint local_6c;
  uint local_68;
  uint local_64;
  undefined4 local_60;
  uint local_5c;
  undefined4 local_58;
  uint local_54;
  ushort local_50;
  int local_48;
  int local_44;
  _MFace *local_40;
  _Model *local_3c;
  _MVertex *local_38;
  _VertexPool *local_34;
  int local_30;
  short *local_2c;
  
  local_34 = gameTrackerX.vertexPool;
  local_3c = instance->object->modelList[instance->currentModel];
  local_38 = local_3c->vertexList;
  mface = local_3c->faceList;
  local_70 = 0xf;
  local_6c = 0x60064;
  local_68 = 0xfff1;
  local_64 = 0x60064;
  local_60 = 0xf0000;
  local_5c = 0x60064;
  local_58 = 0xfff10000;
  local_54 = 0x60064;
  local_50 = (ushort)shardFlags;
  PIPE3D_TransformVerticesToWorld
            (instance,(_SVector *)gameTrackerX.vertexPool,(long *)(gameTrackerX.vertexPool)->color,
             (_Vector *)&local_98);
  if (splintDef == (FXSplinter *)0x0) {
    iVar9 = rand();
    iVar3 = iVar9;
    if (iVar9 < 0) {
      iVar3 = iVar9 + 7;
    }
    local_70 = local_70 & 0xffff0000 |
               (uint)(ushort)((short)local_70 + -4 + (short)iVar9 + (short)(iVar3 >> 3) * -8);
    iVar9 = rand();
    iVar3 = iVar9;
    if (iVar9 < 0) {
      iVar3 = iVar9 + 7;
    }
    local_68 = local_68 & 0xffff0000 |
               (uint)(ushort)((short)local_68 + -4 + (short)iVar9 + (short)(iVar3 >> 3) * -8);
    iVar9 = rand();
    iVar3 = iVar9;
    if (iVar9 < 0) {
      iVar3 = iVar9 + 7;
    }
    local_60 = local_60 & 0xffff |
               (uint)(ushort)(local_60._2_2_ + -4 + (short)iVar9 + (short)(iVar3 >> 3) * -8) << 0x10
    ;
    iVar9 = rand();
    iVar3 = iVar9;
    if (iVar9 < 0) {
      iVar3 = iVar9 + 7;
    }
    local_58 = local_58 & 0xffff |
               (uint)(ushort)(local_58._2_2_ + -4 + (short)iVar9 + (short)(iVar3 >> 3) * -8) << 0x10
    ;
    local_48 = 0x20;
  }
  else {
    sVar2 = splintDef->chunkVelRng;
    uVar10 = splintDef->chunkVelXY - sVar2;
    if ((int)sVar2 == 0) {
      local_70 = local_70 & 0xffff0000 | (uint)uVar10;
      local_68 = local_68 & 0xffff0000 | (uint)(ushort)-uVar10;
      local_60 = local_60 & 0xffff | (uint)uVar10 << 0x10;
      local_58 = local_58 & 0xffff | (uint)(ushort)-uVar10 << 0x10;
      uVar10 = splintDef->chunkVelZ;
      local_6c = local_6c & 0xffff0000 | (uint)uVar10;
      local_64 = local_64 & 0xffff0000 | (uint)uVar10;
      local_5c = local_5c & 0xffff0000 | (uint)uVar10;
      local_54 = local_54 & 0xffff0000 | (uint)uVar10;
    }
    else {
      iVar3 = rand();
      iVar9 = ((int)sVar2 << 0x11) >> 0x10;
      local_70 = local_70 & 0xffff0000 | (uint)(ushort)(uVar10 + (short)(iVar3 % iVar9));
      iVar3 = rand();
      local_68 = local_68 & 0xffff0000 | (uint)(ushort)-(uVar10 + (short)(iVar3 % iVar9));
      iVar3 = rand();
      local_60 = local_60 & 0xffff | (uint)(ushort)(uVar10 + (short)(iVar3 % iVar9)) << 0x10;
      iVar3 = rand();
      local_58 = local_58 & 0xffff | (uint)(ushort)-(uVar10 + (short)(iVar3 % iVar9)) << 0x10;
      sVar2 = splintDef->chunkVelZ - splintDef->chunkVelRng;
      iVar3 = rand();
      local_6c = local_6c & 0xffff0000 | (uint)(ushort)(sVar2 + (short)(iVar3 % iVar9));
      iVar3 = rand();
      local_64 = local_64 & 0xffff0000 | (uint)(ushort)(sVar2 + (short)(iVar3 % iVar9));
      iVar3 = rand();
      local_5c = local_5c & 0xffff0000 | (uint)(ushort)(sVar2 + (short)(iVar3 % iVar9));
      iVar3 = rand();
      local_54 = local_54 & 0xffff0000 | (uint)(ushort)(sVar2 + (short)(iVar3 % iVar9));
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
  iVar3 = 0;
  do {
    p_Var4 = FX_GetMatrix(fxTracker);
    if (p_Var4 == (_FX_MATRIX *)0x0) {
      if (iVar3 == 0) {
        return;
      }
      iVar9 = rand();
      p_Var4 = local_c8[iVar9 % iVar3];
    }
    else {
      local_c8[iVar3] = p_Var4;
      *(undefined4 *)(p_Var4->lwTransform).m = local_b8;
      *(undefined4 *)((p_Var4->lwTransform).m + 2) = local_b4;
      *(undefined4 *)((p_Var4->lwTransform).m + 4) = local_b0;
      *(undefined4 *)((p_Var4->lwTransform).m + 6) = local_ac;
      *(undefined4 *)((p_Var4->lwTransform).m + 8) = local_a8;
      (p_Var4->lwTransform).t[0] = local_a4;
      (p_Var4->lwTransform).t[1] = local_a0;
      (p_Var4->lwTransform).t[2] = local_9c;
    }
    iVar9 = iVar3 * 8;
    puVar8 = &local_70 + iVar3 * 2;
    local_78 = *(short *)puVar8;
    local_76 = *(short *)((int)&local_70 + iVar9 + 2);
    local_74 = *(short *)(&local_6c + iVar3 * 2);
    *(short *)puVar8 =
         (short)((int)local_78 * (int)(short)local_b8 >> 0xc) +
         (short)((int)local_76 * (int)local_b8._2_2_ >> 0xc) +
         (short)((int)local_74 * (int)(short)local_b4 >> 0xc);
    *(short *)((int)&local_70 + iVar9 + 2) =
         (short)((int)local_78 * (int)local_b4._2_2_ >> 0xc) +
         (short)((int)local_76 * (int)(short)local_b0 >> 0xc) +
         (short)((int)local_74 * (int)local_b0._2_2_ >> 0xc);
    iVar12 = iVar3 + 1;
    *(short *)(&local_6c + iVar3 * 2) =
         (short)((int)local_78 * (int)(short)local_ac >> 0xc) +
         (short)((int)local_76 * (int)local_ac._2_2_ >> 0xc) +
         (short)((int)local_74 * (int)(short)local_a8 >> 0xc);
    (p_Var4->lwTransform).t[0] = (p_Var4->lwTransform).t[0] + (int)*(short *)puVar8 * 4;
    (p_Var4->lwTransform).t[1] =
         (p_Var4->lwTransform).t[1] +
         ((int)((uint)*(ushort *)((int)&local_70 + iVar9 + 2) << 0x10) >> 0xe);
    iVar3 = iVar12;
  } while (iVar12 < 4);
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
    local_30 = 0x55555556;
    local_2c = &local_88;
    do {
      p_Var11 = local_34->vertex + (mface->face)._2;
      p_Var13 = local_34->vertex + (mface->face)._3;
      p_Var14 = local_34->vertex + (mface->face).v2;
      iVar3 = (int)p_Var11->x + (int)p_Var13->x + (int)p_Var14->x;
      iVar7 = (int)((ulonglong)((longlong)iVar3 * (longlong)local_30) >> 0x20) - (iVar3 >> 0x1f);
      local_80 = (short)iVar7;
      iVar3 = (int)(&p_Var11->x)[1] + (int)(&p_Var13->x)[1] + (int)(&p_Var14->x)[1];
      iVar3 = (int)((ulonglong)((longlong)iVar3 * (longlong)local_30) >> 0x20) - (iVar3 >> 0x1f);
      local_7e = (short)iVar3;
      iVar9 = (int)(&p_Var11->x)[2] + (int)(&p_Var13->x)[2] + (int)(&p_Var14->x)[2];
      iVar12 = iVar3 * 0x10000 >> 0x10;
      iVar7 = iVar7 * 0x10000 >> 0x10;
      iVar3 = iVar7;
      if (iVar7 < 0) {
        iVar3 = -iVar7;
      }
      local_7c = (short)((ulonglong)((longlong)iVar9 * (longlong)local_30) >> 0x20) -
                 (short)(iVar9 >> 0x1f);
      iVar9 = iVar12;
      if (iVar12 < 0) {
        iVar9 = -iVar12;
      }
      uVar5 = (uint)(iVar7 < 1);
      if ((iVar3 <= iVar9) && (uVar5 = 3, 0 < iVar12)) {
        uVar5 = 2;
      }
      p_Var4 = local_c8[uVar5];
      fxPrim = FX_GetPrim(fxTracker);
      p_Var15 = local_40;
      if (fxPrim != (_FX_PRIM *)0x0) {
        if (fxSetup == (TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup)0x0) {
          (fxPrim->position).x = *(short *)(p_Var4->lwTransform).t;
          (fxPrim->position).y = *(short *)((p_Var4->lwTransform).t + 1);
          (fxPrim->position).z = *(short *)((p_Var4->lwTransform).t + 2);
          sVar2 = (fxPrim->position).z;
          local_88 = (fxPrim->position).x - (short)local_98;
          local_2c[1] = (fxPrim->position).y - (short)local_94;
          local_2c[2] = sVar2 - (short)local_90;
          (fxPrim->_2).x = p_Var11->x - local_88;
          (fxPrim->_2).y = (&p_Var11->x)[1] - local_86;
          (fxPrim->_2).z = (&p_Var11->x)[2] - local_84;
          (fxPrim->_3).x = p_Var13->x - local_88;
          (fxPrim->_3).y = (&p_Var13->x)[1] - local_86;
          (fxPrim->_3).z = (&p_Var13->x)[2] - local_84;
          (fxPrim->v2).x = p_Var14->x - local_88;
          (fxPrim->v2).y = (&p_Var14->x)[1] - local_86;
          sVar2 = (&p_Var14->x)[2];
          fxPrim->matrix = p_Var4;
          (fxPrim->v2).z = sVar2 - local_84;
          if ((instance->flags & 0x80U) == 0) {
            FX_AniTexSetup(fxPrim,mface,local_3c,fxTracker);
          }
          else {
            FX_NoAutoAniTexSetup(fxPrim,mface,local_3c,fxTracker,instance);
          }
          lVar6 = _FX_DoLighting(mface);
          fxPrim->color = lVar6;
          if (fxProcess == (TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess)0x0) {
            *(code **)&fxPrim->process = FX_ShatterProcess;
          }
          else {
            *(TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess *)&fxPrim->process = fxProcess;
          }
          *(undefined2 *)&fxPrim->duo = *(undefined2 *)(&local_70 + uVar5 * 2);
          *(undefined2 *)((int)&fxPrim->duo + 2) = *(undefined2 *)((int)&local_70 + uVar5 * 8 + 2);
          *(undefined2 *)((int)&fxPrim->duo + 4) = *(undefined2 *)(&local_6c + uVar5 * 2);
          if (splintDef == (FXSplinter *)0x0) {
            iVar9 = rand();
            iVar3 = iVar9;
            if (iVar9 < 0) {
              iVar3 = iVar9 + 7;
            }
            *(short *)&fxPrim->duo =
                 *(short *)&fxPrim->duo + -4 + (short)iVar9 + (short)(iVar3 >> 3) * -8;
            iVar9 = rand();
            iVar3 = iVar9;
            if (iVar9 < 0) {
              iVar3 = iVar9 + 7;
            }
            *(short *)((int)&fxPrim->duo + 2) =
                 *(short *)((int)&fxPrim->duo + 2) + -4 + (short)iVar9 + (short)(iVar3 >> 3) * -8;
            iVar9 = rand();
            iVar3 = iVar9;
            if (iVar9 < 0) {
              iVar3 = iVar9 + 7;
            }
            sVar2 = *(short *)((int)&fxPrim->duo + 4) + -4 + (short)iVar9 + (short)(iVar3 >> 3) * -8
            ;
LAB_800455a0:
            *(short *)((int)&fxPrim->duo + 4) = sVar2;
          }
          else {
            sVar2 = splintDef->triVelRng;
            if ((int)sVar2 != 0) {
              sVar1 = -splintDef->triVelRng;
              iVar3 = rand();
              iVar9 = ((int)sVar2 << 0x11) >> 0x10;
              *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + sVar1 + (short)(iVar3 % iVar9);
              iVar3 = rand();
              *(short *)((int)&fxPrim->duo + 2) =
                   *(short *)((int)&fxPrim->duo + 2) + sVar1 + (short)(iVar3 % iVar9);
              iVar3 = rand();
              sVar2 = *(short *)((int)&fxPrim->duo + 4) + sVar1 + (short)(iVar3 % iVar9);
              goto LAB_800455a0;
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
            iVar9 = rand();
            iVar3 = iVar9;
            if (iVar9 < 0) {
              iVar3 = iVar9 + 7;
            }
            fxPrim->work3 = (short)iVar9 + (short)(iVar3 >> 3) * -8 + -4;
          }
          else {
            sVar2 = splintDef->rotRateRng;
            if ((int)sVar2 == 0) {
              fxPrim->work3 = 0;
            }
            else {
              iVar3 = rand();
              fxPrim->work3 = (short)(iVar3 % (((int)sVar2 << 0x11) >> 0x10)) - sVar2;
            }
            *(short *)((int)&fxPrim->duo + 10) = splintDef->gravityZ;
          }
          fxPrim->work1 = 0x1000;
          fxPrim->timeToLive = local_48;
          sVar2 = -0x7fff;
          if ((local_50 & 0x10) == 0) {
            sVar2 = (instance->position).z -
                    instance->object->modelList[instance->currentModel]->maxRad;
          }
          fxPrim->work0 = sVar2;
        }
        else {
          (*fxSetup)(fxPrim,fxProcess,p_Var4,instance,mface,local_38,center,vel,accl,fxTracker,0x1e)
          ;
        }
        LIST_InsertFunc(&fxTracker->usedPrimList,(NodeType *)fxPrim);
        p_Var15 = mface;
      }
      mface = p_Var15 + local_44;
    } while (mface < local_40);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _FX_BuildSplinters(struct _Instance *instance /*$s2*/, struct SVECTOR *center /*$s4*/, struct SVECTOR *vel /*$s5*/, struct SVECTOR *accl /*$s6*/, struct FXSplinter *splintDef /*stack 16*/, struct _FXTracker *fxTracker /*stack 20*/, TDRFuncPtr__FX_BuildSplinters6fxSetup fxSetup /*stack 24*/, TDRFuncPtr__FX_BuildSplinters7fxProcess fxProcess /*stack 28*/, int shardFlags /*stack 32*/)
 // line 1474, offset 0x80045740
	/* begin block 1 */
		// Start line: 3558
	/* end block 1 */
	// End Line: 3559

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
 // line 1499, offset 0x80045894
	/* begin block 1 */
		// Start line: 3609
	/* end block 1 */
	// End Line: 3610

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
 // line 1674, offset 0x800459a8
	/* begin block 1 */
		// Start line: 3963
	/* end block 1 */
	// End Line: 3964

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
 // line 1680, offset 0x800459e0
	/* begin block 1 */
		// Start line: 1681
		// Start offset: 0x800459E0

		/* begin block 1.1 */
			// Start line: 1681
			// Start offset: 0x800459E0
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a0
		// 		short _x1; // $a3
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a1
		/* end block 1.1 */
		// End offset: 0x800459E0
		// End Line: 1681
	/* end block 1 */
	// End offset: 0x80045B2C
	// End Line: 1697

	/* begin block 2 */
		// Start line: 3975
	/* end block 2 */
	// End Line: 3976

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
    (fxPrim->_2).x = (fxPrim->_2).x + offset->x;
    (fxPrim->_2).y = (fxPrim->_2).y + offset->y;
    (fxPrim->_2).z = (fxPrim->_2).z + offset->z;
    (fxPrim->_3).x = (fxPrim->_3).x + offset->x;
    (fxPrim->_3).y = (fxPrim->_3).y + offset->y;
    (fxPrim->_3).z = (fxPrim->_3).z + offset->z;
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
 // line 1700, offset 0x80045b34
	/* begin block 1 */
		// Start line: 1701
		// Start offset: 0x80045B34
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct _FXTracker *fxTracker; // $s2
	// 		struct _FXGeneralEffect *currentEffect; // $t0

		/* begin block 1.1 */
			// Start line: 1727
			// Start offset: 0x80045BF4
			// Variables:
		// 		int i; // $a2
		// 		int end; // $t1
		// 		struct _FXRibbon *currentRibbon; // $a3
		/* end block 1.1 */
		// End offset: 0x80045C6C
		// End Line: 1739
	/* end block 1 */
	// End offset: 0x80045C7C
	// End Line: 1742

	/* begin block 2 */
		// Start line: 4016
	/* end block 2 */
	// End Line: 4017

void FX_Relocate(_SVector *offset)

{
  short sVar1;
  _FXGeneralEffect *p_Var2;
  _FXTracker *p_Var3;
  short *psVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  _FX_PRIM *fxPrim;
  
  p_Var3 = gFXT;
  fxPrim = (_FX_PRIM *)(gFXT->usedPrimList).next;
  while (fxPrim != (_FX_PRIM *)0x0) {
    FX_UpdatePos(fxPrim,offset,0);
    fxPrim = (_FX_PRIM *)(fxPrim->node).next;
  }
  fxPrim = (_FX_PRIM *)(p_Var3->usedPrimListSprite).next;
  while (p_Var2 = FX_GeneralEffectTracker, fxPrim != (_FX_PRIM *)0x0) {
    FX_UpdatePos(fxPrim,offset,1);
    if ((code *)fxPrim->process == FX_WaterBubbleProcess) {
      fxPrim->timeToLive = fxPrim->timeToLive + (int)offset->z;
    }
    fxPrim = (_FX_PRIM *)(fxPrim->node).next;
  }
  while (p_Var2 != (_FXGeneralEffect *)0x0) {
    if (p_Var2->effectType == '\0') {
      iVar7 = 0;
      sVar1 = *(short *)&p_Var2[1].next;
      if (0 < (int)sVar1) {
        iVar6 = 0;
        do {
          psVar4 = (short *)(iVar6 + (int)p_Var2[1].continue_process);
          *psVar4 = *psVar4 + offset->x;
          iVar5 = iVar6 + (int)p_Var2[1].continue_process;
          *(short *)(iVar5 + 2) = *(short *)(iVar5 + 2) + offset->y;
          iVar6 = iVar6 + (int)p_Var2[1].continue_process;
          iVar7 = iVar7 + 1;
          *(short *)(iVar6 + 4) = *(short *)(iVar6 + 4) + offset->z;
          iVar6 = iVar7 * 8;
        } while (iVar7 < (int)sVar1);
      }
    }
    p_Var2 = (_FXGeneralEffect *)p_Var2->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdateTexturePointers(struct _FX_PRIM *fxPrim /*$a0*/, struct Object *oldObject /*$a1*/, long sizeOfObject /*$a2*/, long offset /*$a3*/)
 // line 1747, offset 0x80045c94
	/* begin block 1 */
		// Start line: 4128
	/* end block 1 */
	// End Line: 4129

	/* begin block 2 */
		// Start line: 4129
	/* end block 2 */
	// End Line: 4130

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
 // line 1765, offset 0x80045d30
	/* begin block 1 */
		// Start line: 1766
		// Start offset: 0x80045D30
		// Variables:
	// 		struct _FXTracker *fxTracker; // $s0
	// 		struct _FXGeneralEffect *currentEffect; // $a0
	// 		long offset; // $s1

		/* begin block 1.1 */
			// Start line: 1785
			// Start offset: 0x80045DA4
		/* end block 1.1 */
		// End offset: 0x80045DD4
		// End Line: 1788
	/* end block 1 */
	// End offset: 0x80045DE4
	// End Line: 1791

	/* begin block 2 */
		// Start line: 4164
	/* end block 2 */
	// End Line: 4165

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
 // line 1795, offset 0x80045e00
	/* begin block 1 */
		// Start line: 1796
		// Start offset: 0x80045E00
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $a0
	// 		struct _FX_PRIM *nextFXPrim; // $s0
	// 		struct _FX_MATRIX *fxMatrix; // $s0
	// 		struct _FX_MATRIX *nextFXMatrix; // $s1

		/* begin block 1.1 */
			// Start line: 1866
			// Start offset: 0x80045F74
			// Variables:
		// 		struct _FXGeneralEffect *currentEffect; // $a0
		// 		struct _FXGeneralEffect *nextEffect; // $s0
		/* end block 1.1 */
		// End offset: 0x80045F98
		// End Line: 1876
	/* end block 1 */
	// End offset: 0x80045FDC
	// End Line: 1883

	/* begin block 2 */
		// Start line: 4235
	/* end block 2 */
	// End Line: 4236

	/* begin block 3 */
		// Start line: 4248
	/* end block 3 */
	// End Line: 4249

void FX_ProcessList(_FXTracker *fxTracker)

{
  _FXGeneralEffect *p_Var1;
  int iVar2;
  NodeType *node;
  NodeType *pNVar3;
  NodeType *pNVar4;
  _FXGeneralEffect *p_Var5;
  
  iVar2 = (int)(((uint)(ushort)FX_TimeCount + (uint)(ushort)gameTrackerX.idleTime) * 0x10000) >>
          0x10;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  FX_Frames = (short)(iVar2 >> 0xc);
  pNVar4 = (fxTracker->usedMatrixList).next;
  FX_TimeCount = (short)((uint)(ushort)FX_TimeCount + (uint)(ushort)gameTrackerX.idleTime) +
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
// void /*$ra*/ FX_DrawList(struct _FXTracker *fxTracker /*stack 0*/, struct GameTracker *gameTracker /*$a1*/, unsigned long **ot /*$s5*/, struct MATRIX *wcTransform /*$fp*/)
 // line 1900, offset 0x80045ffc
	/* begin block 1 */
		// Start line: 1901
		// Start offset: 0x80045FFC
		// Variables:
	// 		struct TextureMT3 *texture; // $a1
	// 		struct _PrimPool *primPool; // $s6
	// 		long *prim; // $s1
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct _FX_PRIM *nextFXPrim; // $s7
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
			// Start line: 1922
			// Start offset: 0x80046080
			// Variables:
		// 		long flags; // $s2

			/* begin block 1.1.1 */
				// Start line: 2010
				// Start offset: 0x80046370
				// Variables:
			// 		struct _POLY_NG4 *ng4; // $a2

				/* begin block 1.1.1.1 */
					// Start line: 2012
					// Start offset: 0x80046370
					// Variables:
				// 		int n; // $a0
				// 		long *ptr; // $a1
				/* end block 1.1.1.1 */
				// End offset: 0x80046430
				// End Line: 2037
			/* end block 1.1.1 */
			// End offset: 0x80046430
			// End Line: 2059

			/* begin block 1.1.2 */
				// Start line: 2076
				// Start offset: 0x80046468
			/* end block 1.1.2 */
			// End offset: 0x80046468
			// End Line: 2078

			/* begin block 1.1.3 */
				// Start line: 2166
				// Start offset: 0x800465FC
				// Variables:
			// 		struct POLY_FT4 *ft4; // $a2
			// 		unsigned short uMin; // $t1
			// 		unsigned short uMax; // $t0
			// 		unsigned short vMin; // $a3
			// 		unsigned short vMax; // $v1
			/* end block 1.1.3 */
			// End offset: 0x80046848
			// End Line: 2197

			/* begin block 1.1.4 */
				// Start line: 2204
				// Start offset: 0x80046884
				// Variables:
			// 		struct POLY_FT3 *ft3; // $t0

				/* begin block 1.1.4.1 */
					// Start line: 2217
					// Start offset: 0x800468D0
					// Variables:
				// 		short uMin; // $a3
				// 		short uMax; // $a2
				/* end block 1.1.4.1 */
				// End offset: 0x800469D4
				// End Line: 2225
			/* end block 1.1.4 */
			// End offset: 0x80046A10
			// End Line: 2231
		/* end block 1.1 */
		// End offset: 0x80046A10
		// End Line: 2235

		/* begin block 1.2 */
			// Start line: 2246
			// Start offset: 0x80046A50
			// Variables:
		// 		struct DVECTOR xy_pos; // stack offset -72
		// 		long flags; // $t1

			/* begin block 1.2.1 */
				// Start line: 2311
				// Start offset: 0x80046C8C
				// Variables:
			// 		struct _POLY_SG4 *sg4; // $a1

				/* begin block 1.2.1.1 */
					// Start line: 2313
					// Start offset: 0x80046C8C
					// Variables:
				// 		int n; // $a3
				// 		long *src; // $t2
				// 		long *dst; // $t1
				// 		long *ptr; // $t3
				/* end block 1.2.1.1 */
				// End offset: 0x80046D84
				// End Line: 2344
			/* end block 1.2.1 */
			// End offset: 0x80046D84
			// End Line: 2366

			/* begin block 1.2.2 */
				// Start line: 2378
				// Start offset: 0x80046E18
			/* end block 1.2.2 */
			// End offset: 0x80046E18
			// End Line: 2382

			/* begin block 1.2.3 */
				// Start line: 2410
				// Start offset: 0x80046F04
				// Variables:
			// 		unsigned short uMin; // $t3
			// 		unsigned short uMax; // $t2
			// 		unsigned short vMin; // $a3
			// 		unsigned short vMax; // $v1
			// 		struct POLY_FT4 *ft4; // $a2
			/* end block 1.2.3 */
			// End offset: 0x80047170
			// End Line: 2448
		/* end block 1.2 */
		// End offset: 0x800471DC
		// End Line: 2467
	/* end block 1 */
	// End offset: 0x80047234
	// End Line: 2477

	/* begin block 2 */
		// Start line: 4468
	/* end block 2 */
	// End Line: 4469

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
  undefined4 uVar24;
  int iVar25;
  undefined4 uVar26;
  NodeType *pNVar27;
  uint *puVar28;
  uint *puVar29;
  NodeType *pNVar30;
  NodeType **ppNVar31;
  _PrimPool *primPool;
  NodeType *pNVar32;
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
          CompMatrix((undefined4 *)wcTransform,(ushort *)gameTracker,(uint *)&DAT_1f800000);
          SetRotMatrix((undefined4 *)&DAT_1f800000);
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
                if (((uint)pNVar30 & 0x80000) == 0) goto LAB_80046a10;
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
                goto LAB_80046a10;
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
LAB_80046928:
                    cVar12 = *(char *)&(gameTracker->gameData).asmData.MorphTime;
                    goto LAB_8004692c;
                  }
                  cVar12 = *(char *)&(gameTracker->gameData).asmData.drawBackFaces;
                }
                else {
                  if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar14)
                  goto LAB_80046928;
                  cVar12 = *(char *)&(gameTracker->gameData).asmData.dispPage;
LAB_8004692c:
                  bVar15 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                  bVar14 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
                  bVar3 = bVar14 < bVar15;
                }
                if (bVar3) {
                  if (*(byte *)&(gameTracker->gameData).asmData.MorphTime < bVar15) {
                    cVar19 = *(char *)&(gameTracker->gameData).asmData.drawBackFaces;
                  }
                  else {
LAB_80046984:
                    cVar19 = *(char *)&(gameTracker->gameData).asmData.MorphTime;
                  }
                }
                else {
                  if (bVar14 <= *(byte *)&(gameTracker->gameData).asmData.MorphTime)
                  goto LAB_80046984;
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
LAB_80046684:
                  bVar1 = *(byte *)&(gameTracker->gameData).asmData.MorphTime;
                  goto LAB_80046688;
                }
                bVar1 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
              }
              else {
                if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar14)
                goto LAB_80046684;
                bVar1 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
LAB_80046688:
                bVar15 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                bVar14 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
                bVar3 = bVar14 < bVar15;
              }
              if (bVar3) {
                if (*(byte *)&(gameTracker->gameData).asmData.MorphTime < bVar15) {
                  uVar20 = (ushort)*(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                }
                else {
LAB_800466e0:
                  uVar20 = (ushort)*(byte *)&(gameTracker->gameData).asmData.MorphTime;
                }
              }
              else {
                if (bVar14 <= *(byte *)&(gameTracker->gameData).asmData.MorphTime)
                goto LAB_800466e0;
                uVar20 = (ushort)*(byte *)&(gameTracker->gameData).asmData.dispPage;
              }
              bVar15 = *(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1);
              bVar14 = *(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1);
              if (bVar15 < bVar14) {
                if (*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) <= bVar15) {
LAB_8004673c:
                  bVar2 = *(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1);
                  goto LAB_80046748;
                }
                bVar2 = *(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1);
              }
              else {
                if (*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) <= bVar14)
                goto LAB_8004673c;
                bVar2 = *(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1);
LAB_80046748:
                bVar15 = *(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1);
                bVar14 = *(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1);
              }
              if (bVar14 < bVar15) {
                if (*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) < bVar15) {
                  uVar13 = (ushort)*(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1
                                            ) << 8;
                }
                else {
LAB_800467a0:
                  uVar13 = (ushort)*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) <<
                           8;
                }
              }
              else {
                if (bVar14 <= *(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1))
                goto LAB_800467a0;
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
LAB_80046a10:
      pNVar27 = pNVar32;
    } while (pNVar32 != (NodeType *)0x0);
  }
  SetRotMatrix((undefined4 *)wcTransform);
  SetTransMatrix((int)wcTransform);
  pNVar27 = (fxTracker->usedPrimListSprite).next;
  puVar29 = puVar28;
joined_r0x80046a3c:
  do {
    do {
      pNVar30 = pNVar27;
      if (pNVar30 == (NodeType *)0x0) {
LAB_800471e8:
        primPool->nextPrim = puVar28;
        FX_DrawAllGeneralEffects(wcTransform,gameTrackerX.vertexPool,primPool,ot);
        if ((FX_reaver_instance != (_Instance *)0x0) &&
           (FX_SoulReaverWinding(FX_reaver_instance,primPool,ot,wcTransform),
           FX_reaver_instance != (_Instance *)0x0)) {
          FX_SoulReaverBlade(FX_reaver_instance,ot);
        }
        FX_reaver_instance = (_Instance *)0x0;
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
      if (primPool->lastPrim <= puVar28 + 10) goto LAB_800471e8;
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
LAB_80046f5c:
                bVar1 = *(byte *)&pNVar18[1].prev;
                goto LAB_80046f60;
              }
              bVar1 = *(byte *)&pNVar18->prev;
            }
            else {
              if (*(byte *)&pNVar18[1].prev <= bVar14) goto LAB_80046f5c;
              bVar1 = *(byte *)&pNVar18->next;
LAB_80046f60:
              bVar15 = *(byte *)&pNVar18->prev;
              bVar14 = *(byte *)&pNVar18->next;
              bVar4 = bVar14 < bVar15;
            }
            if (bVar4) {
              if (*(byte *)&pNVar18[1].prev < bVar15) {
                uVar20 = (ushort)*(byte *)&pNVar18->prev;
              }
              else {
LAB_80046fb8:
                uVar20 = (ushort)*(byte *)&pNVar18[1].prev;
              }
            }
            else {
              if (bVar14 <= *(byte *)&pNVar18[1].prev) goto LAB_80046fb8;
              uVar20 = (ushort)*(byte *)&pNVar18->next;
            }
            bVar15 = *(byte *)((int)&pNVar18->prev + 1);
            bVar14 = *(byte *)((int)&pNVar18->next + 1);
            if (bVar15 < bVar14) {
              if (*(byte *)((int)&pNVar18[1].prev + 1) <= bVar15) {
LAB_80047014:
                bVar2 = *(byte *)((int)&pNVar18[1].prev + 1);
                goto LAB_80047020;
              }
              bVar2 = *(byte *)((int)&pNVar18->prev + 1);
            }
            else {
              if (*(byte *)((int)&pNVar18[1].prev + 1) <= bVar14) goto LAB_80047014;
              bVar2 = *(byte *)((int)&pNVar18->next + 1);
LAB_80047020:
              bVar15 = *(byte *)((int)&pNVar18->prev + 1);
              bVar14 = *(byte *)((int)&pNVar18->next + 1);
            }
            if (bVar14 < bVar15) {
              if (*(byte *)((int)&pNVar18[1].prev + 1) < bVar15) {
                uVar13 = (ushort)*(byte *)((int)&pNVar18->prev + 1) << 8;
              }
              else {
LAB_80047078:
                uVar13 = (ushort)*(byte *)((int)&pNVar18[1].prev + 1) << 8;
              }
            }
            else {
              if (bVar14 <= *(byte *)((int)&pNVar18[1].prev + 1)) goto LAB_80047078;
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
        goto joined_r0x80046a3c;
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
 // line 2642, offset 0x80047268
	/* begin block 1 */
		// Start line: 2643
		// Start offset: 0x80047268
		// Variables:
	// 		struct _MVertex *vertex1; // $s2
	// 		struct _MVertex *vertex2; // $s3
	// 		struct _MVertex *vertex3; // $s4

		/* begin block 1.1 */
			// Start line: 2643
			// Start offset: 0x80047268
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _Position *_v0; // $v0
		/* end block 1.1 */
		// End offset: 0x80047268
		// End Line: 2643

		/* begin block 1.2 */
			// Start line: 2643
			// Start offset: 0x80047268
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $v0
		/* end block 1.2 */
		// End offset: 0x80047268
		// End Line: 2643

		/* begin block 1.3 */
			// Start line: 2643
			// Start offset: 0x80047268
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $v0
		/* end block 1.3 */
		// End offset: 0x80047268
		// End Line: 2643

		/* begin block 1.4 */
			// Start line: 2643
			// Start offset: 0x80047268
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $v0
		/* end block 1.4 */
		// End offset: 0x80047268
		// End Line: 2643

		/* begin block 1.5 */
			// Start line: 2643
			// Start offset: 0x80047268
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $v0
		/* end block 1.5 */
		// End offset: 0x80047268
		// End Line: 2643
	/* end block 1 */
	// End offset: 0x80047460
	// End Line: 2708

	/* begin block 2 */
		// Start line: 5266
	/* end block 2 */
	// End Line: 5267

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
  
  MATH3D_SetUnityMatrix((MATRIX *)&fxMatrix->lwTransform);
  sVar1 = center->vy;
  sVar2 = center->vz;
  (fxPrim->position).x = center->vx;
  (fxPrim->position).y = sVar1;
  (fxPrim->position).z = sVar2;
  sVar1 = (vertexList->vertex).y;
  sVar2 = (vertexList->vertex).z;
  (fxPrim->_2).x = (vertexList->vertex).x;
  (fxPrim->_2).y = sVar1;
  (fxPrim->_2).z = sVar2;
  sVar1 = vertexList[1].vertex.y;
  sVar2 = vertexList[1].vertex.z;
  (fxPrim->_3).x = vertexList[1].vertex.x;
  (fxPrim->_3).y = sVar1;
  (fxPrim->_3).z = sVar2;
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
  fxPrim->timeToLive = (int)(short)timeToLive;
  fxPrim->flags = fxPrim->flags | 0x4000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_WaterRingProcess(struct _FX_PRIM *fxPrim /*$a0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 2711, offset 0x800474ac
	/* begin block 1 */
		// Start line: 6682
	/* end block 1 */
	// End Line: 6683

void FX_WaterRingProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  
  (fxPrim->_2).x = (fxPrim->_2).x + -8;
  sVar1 = (fxPrim->_3).x;
  (fxPrim->_2).y = (fxPrim->_2).y + -8;
  (fxPrim->_3).x = sVar1 + 8;
  sVar1 = (fxPrim->v2).x;
  (fxPrim->_3).y = (fxPrim->_3).y + -8;
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
 // line 2721, offset 0x80047528
	/* begin block 1 */
		// Start line: 2722
		// Start offset: 0x80047528
		// Variables:
	// 		struct _FX_PRIM *temp; // $a2

		/* begin block 1.1 */
			// Start line: 2748
			// Start offset: 0x80047608
			// Variables:
		// 		struct Object *waterfx; // $v1
		// 		struct _Model *wxring; // $a0
		/* end block 1.1 */
		// End offset: 0x8004771C
		// End Line: 2787
	/* end block 1 */
	// End offset: 0x8004771C
	// End Line: 2788

	/* begin block 2 */
		// Start line: 6705
	/* end block 2 */
	// End Line: 6706

/* WARNING: Removing unreachable block (ram,0x80047618) */
/* WARNING: Removing unreachable block (ram,0x8004762c) */
/* WARNING: Removing unreachable block (ram,0x8004767c) */

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
  (fxPrim->_2).y = sVar4;
  if ((iVar5 * 0x10000 >> 0x10 < (int)sVar1) || (fxPrim->timeToLive < (int)(fxPrim->position).z)) {
    FX_Die(fxPrim,fxTracker);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Sprite_Insert(struct NodeType *list /*$a0*/, struct _FX_PRIM *fxPrim /*$s0*/)
 // line 2791, offset 0x80047730
	/* begin block 1 */
		// Start line: 6907
	/* end block 1 */
	// End Line: 6908

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
 // line 2797, offset 0x80047768
	/* begin block 1 */
		// Start line: 2799
		// Start offset: 0x80047768
		// Variables:
	// 		struct _Model *model; // $v0
	// 		struct TextureMT3 *texture; // $v0
	/* end block 1 */
	// End offset: 0x80047768
	// End Line: 2803

	/* begin block 2 */
		// Start line: 6919
	/* end block 2 */
	// End Line: 6920

	/* begin block 3 */
		// Start line: 6920
	/* end block 3 */
	// End Line: 6921

	/* begin block 4 */
		// Start line: 6924
	/* end block 4 */
	// End Line: 6925

TextureMT3 * FX_GetTextureObject(Object *object,int modelnum,int texnum)

{
  object->oflags2 = object->oflags2 | 0x20000000;
  return (TextureMT3 *)(object->modelList[modelnum]->faceList[1].color + texnum * 0x10 + 0x10);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeWaterBubble(struct _SVector *position /*$s0*/, struct _SVector *vel /*$s4*/, struct _SVector *accl /*$s5*/, long splashZ /*$s6*/, struct __BubbleParams *BP /*stack 16*/)
 // line 2811, offset 0x800477a4
	/* begin block 1 */
		// Start line: 2812
		// Start offset: 0x800477A4
		// Variables:
	// 		struct Object *waterfx; // $s3
	// 		struct _FX_PRIM *fxPrim; // $s1
	/* end block 1 */
	// End offset: 0x8004792C
	// End Line: 2843

	/* begin block 2 */
		// Start line: 6948
	/* end block 2 */
	// End Line: 6949

/* WARNING: Removing unreachable block (ram,0x800477e8) */
/* WARNING: Removing unreachable block (ram,0x80047800) */

void FX_MakeWaterBubble(_SVector *position,_SVector *vel,_SVector *accl,long splashZ,
                       __BubbleParams *BP)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_GenericBubbleProcess(struct _FXParticle *currentParticle /*$s5*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 2845, offset 0x80047954
	/* begin block 1 */
		// Start line: 2846
		// Start offset: 0x80047954
		// Variables:
	// 		struct _SVector position; // stack offset -56
	// 		struct _SVector accl; // stack offset -48
	// 		struct _SVector vel; // stack offset -40
	// 		struct __GenericBubbleParams *GBP; // $s2
	// 		struct __GenericBubbleParams *GBP_array; // $v1
	// 		struct Object *waterfx; // $v1
	// 		int num; // $s4
	// 		int n; // $s3
	// 		int birthradius; // $s1
	// 		int waterZ; // $s6
	/* end block 1 */
	// End offset: 0x80047CAC
	// End Line: 2890

	/* begin block 2 */
		// Start line: 7041
	/* end block 2 */
	// End Line: 7042

void FX_GenericBubbleProcess(_FXParticle *currentParticle,_FXTracker *fxTracker)

{
  short sVar1;
  int iVar2;
  Level *pLVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  __BubbleParams *BP;
  uint uVar7;
  long splashZ;
  _SVector local_38;
  _SVector local_30;
  _SVector local_28;
  
  BP = (__BubbleParams *)(iRam0000001c + (int)currentParticle->startSegment * 0x30);
  uVar7 = SEXT24(BP[1].DisperseFrames);
  if ((int)uVar7 < 0) {
    iVar2 = rand();
    uVar7 = (uint)(iVar2 % -uVar7 == 0);
  }
  iVar2 = 0;
  pLVar3 = STREAM_GetLevelWithID(currentParticle->instance->currentStreamUnitID);
  splashZ = pLVar3->waterZLevel;
  if (0 < (int)uVar7) {
    do {
      local_28.x = BP[1].MinSplashSize;
      local_28.y = BP[1].MaxSpeed;
      local_28.z = BP[1].MaxSpeedRange;
      local_30.x = BP[1].StartScaleRange;
      local_30.y = BP[1].UniqueBubbles;
      local_30.z = BP[2].DisperseFrames;
      if (BP[1].ScaleRate != 0) {
        iVar4 = rand();
        iVar6 = (uint)(ushort)BP[1].ScaleRate << 0x10;
        iVar5 = iVar6 >> 0x10;
        local_28.x = local_28.x + ((short)(iVar5 - (iVar6 >> 0x1f) >> 1) - (short)(iVar4 % iVar5));
      }
      if (BP[1].ScaleRateRange != 0) {
        iVar4 = rand();
        iVar6 = (uint)(ushort)BP[1].ScaleRateRange << 0x10;
        iVar5 = iVar6 >> 0x10;
        local_28.y = local_28.y + ((short)(iVar5 - (iVar6 >> 0x1f) >> 1) - (short)(iVar4 % iVar5));
      }
      if (BP[1].StartScale != 0) {
        iVar4 = rand();
        iVar6 = (uint)(ushort)BP[1].StartScale << 0x10;
        iVar5 = iVar6 >> 0x10;
        local_28.z = local_28.z + ((short)(iVar5 - (iVar6 >> 0x1f) >> 1) - (short)(iVar4 % iVar5));
      }
      if (BP[2].KillScale != 0) {
        iVar4 = rand();
        iVar6 = (uint)(ushort)BP[2].KillScale << 0x10;
        iVar5 = iVar6 >> 0x10;
        local_30.x = local_30.x + ((short)(iVar5 - (iVar6 >> 0x1f) >> 1) - (short)(iVar4 % iVar5));
      }
      if (BP[2].MinSplashSize != 0) {
        iVar4 = rand();
        iVar6 = (uint)(ushort)BP[2].MinSplashSize << 0x10;
        iVar5 = iVar6 >> 0x10;
        local_30.y = local_30.y + ((short)(iVar5 - (iVar6 >> 0x1f) >> 1) - (short)(iVar4 % iVar5));
      }
      if (BP[2].MaxSpeed != 0) {
        iVar4 = rand();
        iVar6 = (uint)(ushort)BP[2].MaxSpeed << 0x10;
        iVar5 = iVar6 >> 0x10;
        local_30.z = local_30.z + ((short)(iVar5 - (iVar6 >> 0x1f) >> 1) - (short)(iVar4 % iVar5));
      }
      iVar4 = (uint)(ushort)BP[1].KillScale << 0x10;
      iVar5 = iVar4 >> 0x10;
      if (iVar5 != 0) {
        iVar6 = rand();
        sVar1 = (short)(iVar5 - (iVar4 >> 0x1f) >> 1);
        local_38.x = (currentParticle->instance->position).x + (sVar1 - (short)(iVar6 % iVar5));
        iVar4 = rand();
        local_38.y = (currentParticle->instance->position).y + (sVar1 - (short)(iVar4 % iVar5));
        iVar4 = rand();
        local_38.z = (currentParticle->instance->position).z + (sVar1 - (short)(iVar4 % iVar5));
      }
      FX_MakeWaterBubble(&local_38,&local_28,&local_30,splashZ,BP);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)uVar7);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawScreenPoly(int transtype /*$t3*/, unsigned long color /*$t2*/, int zdepth /*$a2*/)
 // line 2899, offset 0x80047cd4
	/* begin block 1 */
		// Start line: 2900
		// Start offset: 0x80047CD4
		// Variables:
	// 		unsigned long **drawot; // $t0
	// 		struct _POLY_TF4 *poly; // $a3
	/* end block 1 */
	// End offset: 0x80047D78
	// End Line: 2916

	/* begin block 2 */
		// Start line: 7181
	/* end block 2 */
	// End Line: 7182

void FX_DrawScreenPoly(int transtype,ulong color,int zdepth)

{
  long lVar1;
  uint *puVar2;
  ulong *puVar3;
  
  lVar1 = gameTrackerX.defVVRemoveDist;
  puVar3 = (gameTrackerX.primPool)->nextPrim;
  if (puVar3 + 7 < (gameTrackerX.primPool)->lastPrim) {
    *(undefined2 *)((int)puVar3 + 0x16) = 0xf0;
    *(undefined2 *)((int)puVar3 + 0x1a) = 0xf0;
    puVar3[1] = transtype << 5 | 0xe1000600;
    puVar2 = (uint *)(zdepth * 4 + lVar1);
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
    (gameTrackerX.primPool)->nextPrim = puVar3 + 7;
  }
  return;
}



// decompiled code
// original method signature: 
// struct POLY_GT4 * /*$ra*/ FX_SetupPolyGT4(int x1 /*$a0*/, int y1 /*$a1*/, int x2 /*$a2*/, int y2 /*$a3*/, int otz /*stack 16*/, struct TextureMT3 *texture /*stack 20*/, long color0 /*stack 24*/, long color1 /*stack 28*/, long color2 /*stack 32*/, long color3 /*stack 36*/)
 // line 2924, offset 0x80047d80
	/* begin block 1 */
		// Start line: 2925
		// Start offset: 0x80047D80
		// Variables:
	// 		struct POLY_GT4 *poly; // $t0
	// 		unsigned long **drawot; // $t3
	/* end block 1 */
	// End offset: 0x80047E7C
	// End Line: 2956

	/* begin block 2 */
		// Start line: 7247
	/* end block 2 */
	// End Line: 7248

	/* begin block 3 */
		// Start line: 7251
	/* end block 3 */
	// End Line: 7252

POLY_GT4 *
FX_SetupPolyGT4(int x1,int y1,int x2,int y2,int otz,TextureMT3 *texture,long color0,long color1,
               long color2,long color3)

{
  undefined2 uVar1;
  long lVar2;
  uint *puVar3;
  POLY_GT4 *pPVar4;
  
  lVar2 = gameTrackerX.defVVRemoveDist;
  pPVar4 = (POLY_GT4 *)(gameTrackerX.primPool)->nextPrim;
  if ((POLY_GT4 *)(gameTrackerX.primPool)->lastPrim <= pPVar4 + 1) {
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
  puVar3 = (uint *)(otz * 4 + lVar2);
  pPVar4->tag = *puVar3 & 0xffffff | 0xc000000;
  *puVar3 = (uint)pPVar4 & 0xffffff;
  *(POLY_GT4 **)&(gameTrackerX.primPool)->nextPrim = pPVar4 + 1;
  return pPVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeWarpArrow(int x /*$s1*/, int y /*$s3*/, int xsize /*$s2*/, int ysize /*$s4*/, int fade /*stack 16*/)
 // line 2985, offset 0x80047e84
	/* begin block 1 */
		// Start line: 2986
		// Start offset: 0x80047E84
		// Variables:
	// 		struct Object *particle; // $a0
	// 		long color; // $s0
	// 		struct POLY_GT4 *poly; // $v1
	/* end block 1 */
	// End offset: 0x80047F44
	// End Line: 3002

	/* begin block 2 */
		// Start line: 5967
	/* end block 2 */
	// End Line: 5968

/* WARNING: Removing unreachable block (ram,0x80047ed4) */
/* WARNING: Removing unreachable block (ram,0x80047ec0) */
/* WARNING: Removing unreachable block (ram,0x80047ec8) */
/* WARNING: Removing unreachable block (ram,0x80047edc) */
/* WARNING: Removing unreachable block (ram,0x80047f34) */

void FX_MakeWarpArrow(int x,int y,int xsize,int ysize,int fade)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeMannaIcon(int x /*$s0*/, int y /*$s2*/, int xsize /*$s1*/, int ysize /*$s3*/)
 // line 3005, offset 0x80047f64
	/* begin block 1 */
		// Start line: 3006
		// Start offset: 0x80047F64
		// Variables:
	// 		struct Object *manna; // $a0
	/* end block 1 */
	// End offset: 0x80047FDC
	// End Line: 3016

	/* begin block 2 */
		// Start line: 7418
	/* end block 2 */
	// End Line: 7419

/* WARNING: Removing unreachable block (ram,0x80047f98) */

void FX_MakeMannaIcon(int x,int y,int xsize,int ysize)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawNumber(int x /*$a0*/, int y /*$a1*/, int number /*$s2*/, long color /*$a3*/)
 // line 3049, offset 0x80047ff8
	/* begin block 1 */
		// Start line: 3050
		// Start offset: 0x80047FF8
		// Variables:
	// 		int oldx; // $s0
	// 		int oldy; // $s1
	/* end block 1 */
	// End offset: 0x80047FF8
	// End Line: 3050

	/* begin block 2 */
		// Start line: 7510
	/* end block 2 */
	// End Line: 7511

void FX_DrawNumber(int x,int y,int number,long color)

{
  long lVar1;
  long lVar2;
  
  lVar2 = fontTracker.font_ypos;
  lVar1 = fontTracker.font_xpos;
  FONT_SetCursor((short)x,(short)y);
  FONT_Print("%d");
  FONT_SetCursor((short)lVar1,(short)lVar2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeGlyphIcon(struct _Position *position /*$s4*/, struct Object *glyphObject /*$s3*/, int size /*$s0*/, int glyphnum /*$s1*/, int enabled /*stack 16*/)
 // line 3085, offset 0x80048068
	/* begin block 1 */
		// Start line: 3086
		// Start offset: 0x80048068
		// Variables:
	// 		int sizex; // $t0
	// 		struct POLY_GT4 *poly; // $v1
	// 		struct TextureMT3 *texture; // $s2
	// 		struct DVECTOR xy_pos; // stack offset -40
	// 		int otz; // $t1
	// 		long *color_array; // $v0
	// 		struct _GlyphTuneData *glyphtunedata; // $v1

		/* begin block 1.1 */
			// Start line: 3099
			// Start offset: 0x800480AC
			// Variables:
		// 		struct Object *object; // $a0
		/* end block 1.1 */
		// End offset: 0x800480C0
		// End Line: 3102
	/* end block 1 */
	// End offset: 0x80048208
	// End Line: 3138

	/* begin block 2 */
		// Start line: 7592
	/* end block 2 */
	// End Line: 7593

/* WARNING: Removing unreachable block (ram,0x800480c0) */

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
 // line 3141, offset 0x8004822c
	/* begin block 1 */
		// Start line: 3142
		// Start offset: 0x8004822C
		// Variables:
	// 		struct MATRIX *swTransform; // $v1
	// 		struct _Position position; // stack offset -24
	// 		long color; // stack offset -16
	// 		long black; // stack offset -12
	// 		int fade; // $a3
	/* end block 1 */
	// End offset: 0x800483D0
	// End Line: 3179

	/* begin block 2 */
		// Start line: 7731
	/* end block 2 */
	// End Line: 7732

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
    sVar2 = (fxPrim->_3).x + sVar2;
    (fxPrim->position).y = *(short *)(iVar3 + 0x18);
    sVar1 = *(short *)(iVar3 + 0x1c);
    (fxPrim->_3).x = sVar2;
    (fxPrim->position).z = sVar1;
    iVar3 = rcos((int)sVar2);
    iVar3 = iVar3 * fxPrim->work1;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0xfff;
    }
    (fxPrim->position).x = (fxPrim->position).x + (short)(iVar3 >> 0xc);
    iVar3 = rsin((int)(fxPrim->_3).x);
    iVar3 = iVar3 * fxPrim->work1;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0xfff;
    }
    (fxPrim->position).y = (fxPrim->position).y + (short)(iVar3 >> 0xc);
    iVar3 = rcos((int)(fxPrim->_3).y);
    iVar3 = iVar3 * fxPrim->work0;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0xfff;
    }
    local_10 = 0x60ff60;
    local_c = 0;
    sVar2 = (fxPrim->v2).x;
    (fxPrim->_2).y = (fxPrim->_2).y + -0x90;
    iVar4 = (int)(fxPrim->_2).y;
    (fxPrim->position).z = (fxPrim->position).z + (short)(iVar3 >> 0xc);
    sVar1 = (fxPrim->_3).y;
    fxPrim->work1 = fxPrim->work1 - sVar2;
    (fxPrim->_3).y = sVar1 + 0x40;
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
 // line 3180, offset 0x800483e0
	/* begin block 1 */
		// Start line: 3181
		// Start offset: 0x800483E0
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s1
	// 		struct SVECTOR location; // stack offset -32
	// 		struct Object *particle; // $s2
	/* end block 1 */
	// End offset: 0x80048600
	// End Line: 3232

	/* begin block 2 */
		// Start line: 7859
	/* end block 2 */
	// End Line: 7860

/* WARNING: Removing unreachable block (ram,0x80048428) */
/* WARNING: Removing unreachable block (ram,0x80048440) */
/* WARNING: Removing unreachable block (ram,0x8004845c) */
/* WARNING: Removing unreachable block (ram,0x80048460) */
/* WARNING: Removing unreachable block (ram,0x80048588) */
/* WARNING: Removing unreachable block (ram,0x8004858c) */
/* WARNING: Removing unreachable block (ram,0x8004859c) */
/* WARNING: Removing unreachable block (ram,0x800485a0) */
/* WARNING: Removing unreachable block (ram,0x800485b8) */
/* WARNING: Removing unreachable block (ram,0x800485d0) */

void FX_MakeSoulDust(_Instance *instance,short segment)

{
  rand();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_WaterTrailProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 3255, offset 0x80048620
	/* begin block 1 */
		// Start line: 6504
	/* end block 1 */
	// End Line: 6505

void FX_WaterTrailProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  
  FX_StandardProcess(fxPrim,fxTracker);
  (fxPrim->_2).x = (short)((int)(fxPrim->_2).x * 7 >> 3);
  (fxPrim->_2).y = (short)((int)(fxPrim->_2).y * 7 >> 3);
  sVar1 = (fxPrim->_3).x;
  (fxPrim->_2).z = (short)((int)(fxPrim->_2).z * 7 >> 3);
  (fxPrim->_3).x = (short)((int)sVar1 * 7 >> 3);
  (fxPrim->_3).y = (short)((int)(fxPrim->_3).y * 7 >> 3);
  sVar1 = (fxPrim->v2).x;
  (fxPrim->_3).z = (short)((int)(fxPrim->_3).z * 7 >> 3);
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
 // line 3274, offset 0x80048738
	/* begin block 1 */
		// Start line: 3275
		// Start offset: 0x80048738
		// Variables:
	// 		struct Object *waterfx; // $a1
	// 		struct _Model *wxtrail; // $a0
	// 		struct _SVector position; // stack offset -48
	// 		int zvel; // $s0

		/* begin block 1.1 */
			// Start line: 3311
			// Start offset: 0x80048844
			// Variables:
		// 		int n; // $s2
		// 		int deg; // $s0
		// 		struct _SVector vel; // stack offset -40
		// 		struct _SVector accel; // stack offset -32
		// 		struct _SVector startpos; // stack offset -24

			/* begin block 1.1.1 */
				// Start line: 3319
				// Start offset: 0x8004885C
				// Variables:
			// 		int sinVal; // $s1
			// 		int cosVal; // $s0
			// 		int spd; // $v1
			/* end block 1.1.1 */
			// End offset: 0x800488F0
			// End Line: 3327
		/* end block 1.1 */
		// End offset: 0x80048954
		// End Line: 3332
	/* end block 1 */
	// End offset: 0x80048954
	// End Line: 3333

	/* begin block 2 */
		// Start line: 8052
	/* end block 2 */
	// End Line: 8053

/* WARNING: Removing unreachable block (ram,0x800487d8) */

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
      INSTANCE_Post(gameTrackerX.playerInstance,0x40024,0);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// struct _FXRibbon * /*$ra*/ FX_StartRibbon(struct _Instance *instance /*$s7*/, short startSegment /*$s3*/, short endSegment /*stack -48*/, short type /*$fp*/, int ribbonLifeTime /*stack 16*/, int faceLifeTime /*stack 20*/, int startFadeValue /*stack 24*/, long startColor /*stack 28*/, long endColor /*stack 32*/)
 // line 3368, offset 0x8004896c
	/* begin block 1 */
		// Start line: 3369
		// Start offset: 0x8004896C
		// Variables:
	// 		struct MATRIX *swTransform; // $a0
	// 		struct _FXRibbon *ribbon; // $s0
	// 		int i; // $a2
	// 		int number; // $s1
	/* end block 1 */
	// End offset: 0x80048C0C
	// End Line: 3451

	/* begin block 2 */
		// Start line: 6714
	/* end block 2 */
	// End Line: 6715

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
      goto LAB_80048c00;
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
LAB_80048c00:
  FX_InsertGeneralEffect(ptr);
  return ptr;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_RibbonProcess(struct _FX_PRIM *fxPrim /*$a2*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 3472, offset 0x80048c3c
	/* begin block 1 */
		// Start line: 3473
		// Start offset: 0x80048C3C
		// Variables:
	// 		int d; // $a1
	// 		long fade; // $a3
	/* end block 1 */
	// End offset: 0x80048D20
	// End Line: 3512

	/* begin block 2 */
		// Start line: 6939
	/* end block 2 */
	// End Line: 6940

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
 // line 3515, offset 0x80048d30
	/* begin block 1 */
		// Start line: 8580
	/* end block 1 */
	// End Line: 8581

void FX_ConstrictProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  
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
      sVar3 = (fxPrim->_2).y;
      fxPrim->fadeValue[1] = 0;
      fxPrim->fadeValue[0] = 0;
      fxPrim->fadeValue[3] = 0x1000;
      fxPrim->fadeValue[2] = 0x1000;
      iVar4 = ratan2((int)sVar3 - (int)FX_ConstrictPosition.y,
                     (int)(fxPrim->_2).x - (int)FX_ConstrictPosition.x);
      sVar3 = (fxPrim->_3).y;
      fxPrim->work2 = (short)iVar4;
      iVar4 = ratan2((int)sVar3 - (int)FX_ConstrictPosition.y,
                     (int)(fxPrim->_3).x - (int)FX_ConstrictPosition.x);
      sVar3 = (fxPrim->v2).z;
      sVar2 = (fxPrim->_2).z;
      sVar1 = (fxPrim->_2).z;
      fxPrim->work3 = (short)iVar4;
      iVar4 = (int)sVar3 - (int)sVar2;
      if (iVar4 < 0) {
        iVar4 = iVar4 + 3;
      }
      (fxPrim->v2).z = sVar1 + (short)(iVar4 >> 2);
      (fxPrim->v3).z = (fxPrim->_3).z + ((fxPrim->v3).z - (fxPrim->_3).z) * 3;
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
      sVar3 = (fxPrim->_2).z;
      sVar2 = (fxPrim->v2).z;
      sVar1 = (fxPrim->v2).z;
      fxPrim->work3 = (short)iVar4;
      iVar4 = (int)sVar3 - (int)sVar2;
      if (iVar4 < 0) {
        iVar4 = iVar4 + 3;
      }
      (fxPrim->_2).z = sVar1 + (short)(iVar4 >> 2);
      (fxPrim->_3).z = (fxPrim->v3).z + ((fxPrim->_3).z - (fxPrim->v3).z) * 3;
    }
    sVar3 = FX_ConstrictPosition.x;
    (fxPrim->_3).x = FX_ConstrictPosition.x;
    (fxPrim->v3).x = sVar3;
    sVar3 = FX_ConstrictPosition.y;
    (fxPrim->_3).y = FX_ConstrictPosition.y;
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
      (fxPrim->_2).x = sVar2;
      (fxPrim->v2).x = sVar2;
      iVar4 = rsin((int)sVar3);
      sVar3 = FX_ConstrictPosition.y + (short)(fxPrim->work0 * iVar4 >> 0xc);
      (fxPrim->_2).y = sVar3;
      (fxPrim->v2).y = sVar3;
    }
  }
  FX_RibbonProcess(fxPrim,fxTracker);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartConstrict(struct _Instance *instance /*$a0*/, struct _SVector *constrict_point /*$a1*/, short startSegment /*$a2*/, short endSegment /*$a3*/)
 // line 3581, offset 0x80048fc0
	/* begin block 1 */
		// Start line: 8747
	/* end block 1 */
	// End Line: 8748

	/* begin block 2 */
		// Start line: 8748
	/* end block 2 */
	// End Line: 8749

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
 // line 3598, offset 0x80049050
	/* begin block 1 */
		// Start line: 3599
		// Start offset: 0x80049050

		/* begin block 1.1 */
			// Start line: 3606
			// Start offset: 0x80049070
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x80049070
		// End Line: 3606

		/* begin block 1.2 */
			// Start line: 3610
			// Start offset: 0x8004907C
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.2 */
		// End offset: 0x800490A4
		// End Line: 3610
	/* end block 1 */
	// End offset: 0x800490A4
	// End Line: 3614

	/* begin block 2 */
		// Start line: 8785
	/* end block 2 */
	// End Line: 8786

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
 // line 3618, offset 0x800490c0
	/* begin block 1 */
		// Start line: 3619
		// Start offset: 0x800490C0
		// Variables:
	// 		struct SVECTOR mp0; // stack offset -32
	// 		struct SVECTOR mp1; // stack offset -24
	/* end block 1 */
	// End offset: 0x800490C0
	// End Line: 3619

	/* begin block 2 */
		// Start line: 8826
	/* end block 2 */
	// End Line: 8827

void FX_SubDividePrim(_FX_PRIM *fxPrim1,_FX_PRIM *fxPrim2)

{
  uint local_20;
  short local_1c;
  uint local_18;
  short local_14;
  
  LoadAverageShort12((uint *)&fxPrim1->_2,(uint *)&fxPrim2->v2,0x800,0x800,&local_20);
  LoadAverageShort12((uint *)&fxPrim1->_3,(uint *)&fxPrim2->v3,0x800,0x800,&local_18);
  *(uint *)&fxPrim1->v2 = local_20;
  (fxPrim1->v2).z = local_1c;
  *(uint *)&fxPrim1->v3 = local_18;
  (fxPrim1->v3).z = local_14;
  *(uint *)&fxPrim2->_2 = local_20;
  (fxPrim2->_2).z = local_1c;
  *(uint *)&fxPrim2->_3 = local_18;
  (fxPrim2->_3).z = local_14;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueRibbon(struct _FXRibbon *ribbon /*$s2*/, struct _FXTracker *fxTracker /*$fp*/)
 // line 3666, offset 0x80049184
	/* begin block 1 */
		// Start line: 3667
		// Start offset: 0x80049184
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
			// Start line: 3794
			// Start offset: 0x80049600
			// Variables:
		// 		int fade; // $v1
		/* end block 1.1 */
		// End offset: 0x80049694
		// End Line: 3818
	/* end block 1 */
	// End offset: 0x8004971C
	// End Line: 3833

	/* begin block 2 */
		// Start line: 8925
	/* end block 2 */
	// End Line: 8926

/* WARNING: Could not reconcile some variable overlaps */

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
            *(undefined4 *)&fxPrim1->_2 = local_50;
            (fxPrim1->_2).z = (short)local_4c;
            local_44 = (short)uVar16;
            *(undefined4 *)&fxPrim1->_3 = uVar14;
            (fxPrim1->_3).z = local_44;
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
// void /*$ra*/ FX_StandardFXPrimProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$a2*/)
 // line 3838, offset 0x8004974c
	/* begin block 1 */
		// Start line: 3839
		// Start offset: 0x8004974C
		// Variables:
	// 		long flags; // $s1

		/* begin block 1.1 */
			// Start line: 3854
			// Start offset: 0x8004979C
			// Variables:
		// 		long start; // stack offset -24
		// 		long end; // stack offset -20
		/* end block 1.1 */
		// End offset: 0x80049880
		// End Line: 3869

		/* begin block 1.2 */
			// Start line: 3873
			// Start offset: 0x8004988C
			// Variables:
		// 		int current_scale; // $v1
		/* end block 1.2 */
		// End offset: 0x800498BC
		// End Line: 3883

		/* begin block 1.3 */
			// Start line: 3888
			// Start offset: 0x800498C4
			// Variables:
		// 		struct MATRIX *swTransform; // $v1
		/* end block 1.3 */
		// End offset: 0x800498C4
		// End Line: 3889

		/* begin block 1.4 */
			// Start line: 4056
			// Start offset: 0x80049A64
			// Variables:
		// 		struct _Rotation rot; // stack offset -32
		/* end block 1.4 */
		// End offset: 0x80049AC4
		// End Line: 4064
	/* end block 1 */
	// End offset: 0x80049AC4
	// End Line: 4073

	/* begin block 2 */
		// Start line: 9504
	/* end block 2 */
	// End Line: 9505

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
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  uint uVar13;
  
  iVar6 = fxPrim->timeToLive;
  if (0 < iVar6) {
    fxPrim->timeToLive = iVar6 + -1;
    iVar6 = fxPrim->timeToLive;
  }
  if (iVar6 == 0) {
LAB_800498a4:
    FX_Die(fxPrim,fxTracker);
  }
  else {
    uVar13 = fxPrim->flags;
    if ((uVar13 & 0x40000) != 0) {
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
      uVar10 = getCopReg(2,0x4800);
      uVar11 = getCopReg(2,0x5000);
      uVar12 = getCopReg(2,0x5800);
      *(char *)&fxPrim->color = (char)uVar10;
      *(undefined *)((int)&fxPrim->color + 1) = (char)uVar11;
      *(undefined *)((int)&fxPrim->color + 2) = (char)uVar12;
      if ((uVar13 & 1) != 0) {
        fxPrim->color = fxPrim->color & 0x3ffffffU | 0x2c000000;
      }
    }
    if ((uVar13 & 0x2000) != 0) {
      iVar6 = (int)(fxPrim->_2).y - (int)fxPrim->work3;
      if (iVar6 < 1) goto LAB_800498a4;
      (fxPrim->_2).y = (short)iVar6;
    }
    if ((uVar13 & 0x20) == 0) {
      if ((uVar13 & 2) == 0) {
        sVar5 = *(short *)((int)&fxPrim->duo + 8);
        sVar3 = *(short *)((int)&fxPrim->duo + 10);
        *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + *(short *)((int)&fxPrim->duo + 6);
        *(short *)((int)&fxPrim->duo + 2) = *(short *)((int)&fxPrim->duo + 2) + sVar5;
        *(short *)((int)&fxPrim->duo + 4) = *(short *)((int)&fxPrim->duo + 4) + sVar3;
        if ((uVar13 & 0x1000000) == 0) {
          sVar5 = *(short *)((int)&fxPrim->duo + 2);
          sVar3 = *(short *)((int)&fxPrim->duo + 4);
          (fxPrim->position).x = (fxPrim->position).x + *(short *)&fxPrim->duo;
          (fxPrim->position).y = (fxPrim->position).y + sVar5;
          (fxPrim->position).z = (fxPrim->position).z + sVar3;
        }
        else {
          sVar5 = *(short *)&fxPrim->duo;
          (fxPrim->_2).x = (fxPrim->_2).x + sVar5;
          sVar3 = (fxPrim->_2).y;
          sVar4 = *(short *)((int)&fxPrim->duo + 2);
          (fxPrim->_3).x = (fxPrim->_3).x + sVar5;
          (fxPrim->_2).y = sVar3 + sVar4;
          sVar5 = (fxPrim->_2).z;
          sVar3 = *(short *)((int)&fxPrim->duo + 4);
          (fxPrim->_3).y = (fxPrim->_3).y + sVar4;
          (fxPrim->_2).z = sVar5 + sVar3;
          (fxPrim->_3).z = (fxPrim->_3).z + sVar3;
        }
        if (((uVar13 & 0x100) != 0) && ((fxPrim->position).z <= fxPrim->work0)) {
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
    if ((uVar13 & 4) != 0) {
      FX_AniTexProcess(fxPrim,fxTracker);
    }
    if (((((uVar13 & 0x8000000) == 0) && (p_Var7 = fxPrim->matrix, p_Var7 != (_FX_MATRIX *)0x0)) &&
        ((p_Var7->flags & 2U) == 0)) && (p_Var7->flags = p_Var7->flags | 2, (uVar13 & 0x80) != 0)) {
      cVar1 = *(char *)&fxPrim->work3;
      cVar2 = *(char *)((int)&fxPrim->work3 + 1);
      RotMatrixX((int)*(char *)((int)&fxPrim->work2 + 1) << 2,(int)&fxPrim->matrix->lwTransform);
      RotMatrixY((int)(short)((int)cVar1 << 2),(short *)&fxPrim->matrix->lwTransform);
      RotMatrixZ((int)(short)((int)cVar2 << 2),(short *)&fxPrim->matrix->lwTransform);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_AttachedParticlePrimProcess(struct _FX_PRIM *fxPrim /*$a2*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 4075, offset 0x80049ad8
	/* begin block 1 */
		// Start line: 4076
		// Start offset: 0x80049AD8
		// Variables:
	// 		struct MATRIX *swTransform; // $a3
	// 		struct MATRIX *swTransformOld; // $t0
	// 		struct _Instance *instance; // $v1
	/* end block 1 */
	// End offset: 0x80049B54
	// End Line: 4090

	/* begin block 2 */
		// Start line: 9998
	/* end block 2 */
	// End Line: 9999

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
 // line 4093, offset 0x80049b6c
	/* begin block 1 */
		// Start line: 4094
		// Start offset: 0x80049B6C
		// Variables:
	// 		struct MATRIX *swTransform; // $a0
	// 		struct MATRIX *swTransformOld; // $a2
	// 		struct _Instance *instance; // $v0
	// 		struct _SVector movement; // stack offset -16
	// 		int total; // $a0
	/* end block 1 */
	// End offset: 0x80049D30
	// End Line: 4127

	/* begin block 2 */
		// Start line: 10037
	/* end block 2 */
	// End Line: 10038

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
      uVar1 = (fxPrim->_2).y;
      *(undefined2 *)((int)&fxPrim->duo + 10) = 0;
      iVar5 = (uint)uVar1 - (iVar2 * 3) / 2;
      (fxPrim->_2).y = (short)iVar5;
      if (iVar5 * 0x10000 < 0) {
        (fxPrim->_2).y = 0;
      }
    }
    FX_StandardFXPrimProcess(fxPrim,fxTracker);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DFacadeParticleSetup(struct _FX_PRIM *fxPrim /*$t1*/, struct SVECTOR *center /*$a1*/, short halveWidth /*$a2*/, short halveHeight /*$a3*/, long color /*stack 16*/, struct SVECTOR *vel /*stack 20*/, struct SVECTOR *accl /*stack 24*/, struct _FXTracker *fxTracker /*stack 28*/, int timeToLive /*stack 32*/)
 // line 4139, offset 0x80049d40
	/* begin block 1 */
		// Start line: 4140
		// Start offset: 0x80049D40

		/* begin block 1.1 */
			// Start line: 4140
			// Start offset: 0x80049D40
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _Position *_v0; // $v0
		/* end block 1.1 */
		// End offset: 0x80049D40
		// End Line: 4140
	/* end block 1 */
	// End offset: 0x80049E20
	// End Line: 4181

	/* begin block 2 */
		// Start line: 10130
	/* end block 2 */
	// End Line: 10131

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
  (fxPrim->_2).x = halveWidth;
  (fxPrim->_2).y = 0x1000;
  (fxPrim->_2).z = halveHeight;
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
  fxPrim->timeToLive = (int)(short)timeToLive;
  return;
}



// decompiled code
// original method signature: 
// struct _FX_PRIM * /*$ra*/ FX_Dot(struct _SVector *location /*$s4*/, struct _SVector *vel /*$s6*/, struct _SVector *accel /*$s7*/, int scale_speed /*$fp*/, long color /*stack 16*/, long size /*stack 20*/, int lifetime /*stack 24*/, int texture_num /*stack 28*/)
 // line 4187, offset 0x80049e30
	/* begin block 1 */
		// Start line: 4188
		// Start offset: 0x80049E30
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	/* end block 1 */
	// End offset: 0x80049F68
	// End Line: 4218

	/* begin block 2 */
		// Start line: 10273
	/* end block 2 */
	// End Line: 10274

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
      (fxPrim->_2).y = 0x1000;
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
 // line 4221, offset 0x80049f9c
	/* begin block 1 */
		// Start line: 4222
		// Start offset: 0x80049F9C
		// Variables:
	// 		int i; // $s0

		/* begin block 1.1 */
			// Start line: 4227
			// Start offset: 0x80049FD8
			// Variables:
		// 		struct _SVector vel; // stack offset -40
		/* end block 1.1 */
		// End offset: 0x8004A064
		// End Line: 4231
	/* end block 1 */
	// End offset: 0x8004A0B0
	// End Line: 4234

	/* begin block 2 */
		// Start line: 10347
	/* end block 2 */
	// End Line: 10348

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
 // line 4236, offset 0x8004a0d4
	/* begin block 1 */
		// Start line: 10384
	/* end block 1 */
	// End Line: 10385

void FX_Blood2(_SVector *location,_SVector *input_vel,_SVector *accel,int amount,long color,
              long dummyCrapShouldRemove)

{
  FX_Blood(location,input_vel,accel,amount,color,4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Blood_Impale(struct _Instance *locinst /*$a0*/, short locseg /*$a1*/, struct _Instance *instance /*$a2*/, short segment /*$a3*/)
 // line 4268, offset 0x8004a100
	/* begin block 1 */
		// Start line: 4269
		// Start offset: 0x8004A100
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct SVECTOR location; // stack offset -48
	// 		struct SVECTOR accel; // stack offset -40
	// 		struct SVECTOR vel; // stack offset -32
	// 		struct SVECTOR input_vel; // stack offset -24
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x8004A31C
	// End Line: 4309

	/* begin block 2 */
		// Start line: 8528
	/* end block 2 */
	// End Line: 8529

void FX_Blood_Impale(_Instance *locinst,short locseg,_Instance *instance,short segment)

{
  _FXTracker *p_Var1;
  _FX_PRIM *fxPrim;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  SVECTOR local_30;
  SVECTOR local_28;
  SVECTOR local_20;
  short local_18;
  short local_16;
  short local_14;
  
  iVar3 = (int)((uint)(ushort)segment << 0x10) >> 0xb;
  local_18 = *(short *)((int)instance->matrix->t + iVar3) -
             *(short *)((int)instance->oldMatrix->t + iVar3);
  local_16 = *(short *)((int)instance->matrix->t + iVar3 + 4) -
             *(short *)((int)instance->oldMatrix->t + iVar3 + 4);
  local_14 = *(short *)((int)instance->matrix->t + iVar3 + 8) -
             *(short *)((int)instance->oldMatrix->t + iVar3 + 8);
  iVar3 = (int)((uint)(ushort)locseg << 0x10) >> 0xb;
  local_30.vx = *(short *)((int)locinst->matrix->t + iVar3);
  iVar4 = 1;
  local_30.vy = *(short *)((int)locinst->matrix->t + iVar3 + 4);
  local_30.vz = *(short *)((int)locinst->matrix->t + iVar3 + 8);
  local_28.vx = 0;
  local_28.vy = 0;
  local_28.vz = -2;
  do {
    fxPrim = FX_GetPrim(gFXT);
    if (fxPrim != (_FX_PRIM *)0x0) {
      iVar3 = rand();
      iVar5 = local_18 * iVar4;
      if (iVar5 < 0) {
        iVar5 = iVar5 + 0x3f;
      }
      local_20.vx = (short)(iVar5 >> 6) + ((ushort)iVar3 & 0xf) + -7;
      iVar3 = rand();
      iVar5 = local_16 * iVar4;
      if (iVar5 < 0) {
        iVar5 = iVar5 + 0x3f;
      }
      local_20.vy = (short)(iVar5 >> 6) + ((ushort)iVar3 & 0xf) + -7;
      iVar3 = rand();
      iVar5 = local_14 * iVar4;
      if (iVar5 < 0) {
        iVar5 = iVar5 + 0x3f;
      }
      local_20.vz = (short)(iVar5 >> 6) + ((ushort)iVar3 & 0xf) + -7;
      FX_DFacadeParticleSetup(fxPrim,&local_30,8,8,0x1800a0,&local_20,&local_28,gFXT,0x16);
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
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x40);
  return;
}



// decompiled code
// original method signature: 
// struct _FXParticle * /*$ra*/ FX_BloodCone(struct _Instance *instance /*$a0*/, short startSegment /*$a1*/, long time /*$s1*/)
 // line 4319, offset 0x8004a334
	/* begin block 1 */
		// Start line: 4320
		// Start offset: 0x8004A334
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	/* end block 1 */
	// End offset: 0x8004A3B8
	// End Line: 4342

	/* begin block 2 */
		// Start line: 10576
	/* end block 2 */
	// End Line: 10577

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
 // line 4347, offset 0x8004a3d0
	/* begin block 1 */
		// Start line: 4348
		// Start offset: 0x8004A3D0
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	/* end block 1 */
	// End offset: 0x8004A494
	// End Line: 4372

	/* begin block 2 */
		// Start line: 10655
	/* end block 2 */
	// End Line: 10656

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
 // line 4375, offset 0x8004a4b4
	/* begin block 1 */
		// Start line: 4376
		// Start offset: 0x8004A4B4
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	/* end block 1 */
	// End offset: 0x8004A5BC
	// End Line: 4418

	/* begin block 2 */
		// Start line: 10734
	/* end block 2 */
	// End Line: 10735

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
 // line 4421, offset 0x8004a5dc
	/* begin block 1 */
		// Start line: 4423
		// Start offset: 0x8004A5DC
		// Variables:
	// 		int fade; // $a0
	/* end block 1 */
	// End offset: 0x8004A614
	// End Line: 4426

	/* begin block 2 */
		// Start line: 10847
	/* end block 2 */
	// End Line: 10848

	/* begin block 3 */
		// Start line: 10848
	/* end block 3 */
	// End Line: 10849

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
 // line 4445, offset 0x8004a61c
	/* begin block 1 */
		// Start line: 10895
	/* end block 1 */
	// End Line: 10896

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
 // line 4465, offset 0x8004a734
	/* begin block 1 */
		// Start line: 10945
	/* end block 1 */
	// End Line: 10946

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
 // line 4472, offset 0x8004a7c0
	/* begin block 1 */
		// Start line: 4473
		// Start offset: 0x8004A7C0

		/* begin block 1.1 */
			// Start line: 4476
			// Start offset: 0x8004A7E4
			// Variables:
		// 		struct SVECTOR position; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x8004A81C
		// End Line: 4491
	/* end block 1 */
	// End offset: 0x8004A8D0
	// End Line: 4505

	/* begin block 2 */
		// Start line: 10959
	/* end block 2 */
	// End Line: 10960

void FX_ProcessSnow(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  SVECTOR SStack24;
  
  if (fxPrim->work0 == 9999) {
    if ((gameTrackerX.gameData.asmData.MorphType == 1) ||
       (gameTrackerX.gameData.asmData.MorphTime != 1000)) goto LAB_8004a844;
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
LAB_8004a844:
  FX_Die(fxPrim,fxTracker);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueSnow(struct _FXTracker *fxTracker /*$s1*/)
 // line 4507, offset 0x8004a8e4
	/* begin block 1 */
		// Start line: 4508
		// Start offset: 0x8004A8E4
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct SVECTOR position; // stack offset -40
	// 		struct SVECTOR vel; // stack offset -32

		/* begin block 1.1 */
			// Start line: 4525
			// Start offset: 0x8004A960
			// Variables:
		// 		struct SVECTOR campos; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x8004AA28
		// End Line: 4547
	/* end block 1 */
	// End offset: 0x8004AA28
	// End Line: 4549

	/* begin block 2 */
		// Start line: 11031
	/* end block 2 */
	// End Line: 11032

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
 // line 4551, offset 0x8004aa3c
	/* begin block 1 */
		// Start line: 4552
		// Start offset: 0x8004AA3C
		// Variables:
	// 		short change; // $s0
	/* end block 1 */
	// End offset: 0x8004AB98
	// End Line: 4569

	/* begin block 2 */
		// Start line: 11130
	/* end block 2 */
	// End Line: 11131

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
 // line 4576, offset 0x8004abb4
	/* begin block 1 */
		// Start line: 11184
	/* end block 1 */
	// End Line: 11185

void FX_ProcessRain(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  short sVar3;
  
  if (0 < fxPrim->timeToLive) {
    fxPrim->timeToLive = fxPrim->timeToLive + -1;
  }
  sVar3 = (fxPrim->_3).z + *(short *)((int)&fxPrim->duo + 4);
  (fxPrim->_3).z = sVar3;
  if ((fxPrim->work0 < sVar3) && (fxPrim->timeToLive != 0)) {
    sVar3 = *(short *)&fxPrim->duo;
    sVar1 = *(short *)((int)&fxPrim->duo + 2);
    (fxPrim->_2).x = (fxPrim->_2).x + sVar3;
    sVar2 = (fxPrim->_2).y;
    (fxPrim->_3).x = (fxPrim->_3).x + sVar3;
    (fxPrim->_2).y = sVar2 + sVar1;
    sVar3 = (fxPrim->_2).z;
    sVar2 = *(short *)((int)&fxPrim->duo + 4);
    (fxPrim->_3).y = (fxPrim->_3).y + sVar1;
    (fxPrim->_2).z = sVar3 + sVar2;
  }
  else {
    FX_Die(fxPrim,fxTracker);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueRain(struct _FXTracker *fxTracker /*$s6*/)
 // line 4600, offset 0x8004ac80
	/* begin block 1 */
		// Start line: 4601
		// Start offset: 0x8004AC80
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct SVECTOR campos; // stack offset -48
	// 		int n; // $s3
	// 		int rain_pct; // $s5
	// 		long waterZLevel; // $s2

		/* begin block 1.1 */
			// Start line: 4614
			// Start offset: 0x8004ACCC
			// Variables:
		// 		int fade; // $v1
		/* end block 1.1 */
		// End offset: 0x8004ACF4
		// End Line: 4616

		/* begin block 1.2 */
			// Start line: 4625
			// Start offset: 0x8004AD24
			// Variables:
		// 		struct _SVector worldpos; // stack offset -40
		// 		int zvel; // $s1
		/* end block 1.2 */
		// End offset: 0x8004AED8
		// End Line: 4671
	/* end block 1 */
	// End offset: 0x8004AEE8
	// End Line: 4673

	/* begin block 2 */
		// Start line: 11240
	/* end block 2 */
	// End Line: 11241

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
  int iVar9;
  _FX_PRIM *node;
  int iVar10;
  int iVar11;
  SVECTOR local_30;
  SVECTOR local_28;
  
  if (gameTrackerX.gameData.asmData._8_4_ != 0x103e8) {
    iVar11 = (int)rain_amount;
    if (gameTrackerX.gameData.asmData.MorphTime != 1000) {
      iVar5 = FX_GetMorphFadeVal();
      iVar5 = iVar11 * (0x1000 - iVar5);
      iVar11 = iVar5 >> 0xc;
      if (iVar5 < 0) {
        iVar11 = iVar5 + 0xfff >> 0xc;
      }
    }
    iVar10 = 0;
    pLVar6 = STREAM_GetLevelWithID((gameTrackerX.playerInstance)->currentStreamUnitID);
    iVar5 = pLVar6->waterZLevel;
    do {
      uVar7 = rand();
      if ((int)(uVar7 & 0x3ff) <= iVar11) {
        iVar8 = rand();
        iVar9 = iVar8;
        if (iVar8 < 0) {
          iVar9 = iVar8 + 0x1ff;
        }
        local_30.vx = (short)iVar8 + (short)(iVar9 >> 9) * -0x200;
        local_30.vy = 5;
        iVar9 = rand();
        local_30.vz = ((ushort)iVar9 & 0x7ff) + 0x180;
        FX_ConvertCamPersToWorld(&local_30,&local_28);
        uVar7 = rand();
        iVar9 = (-0xe - (uVar7 & 3)) * 8;
        if (local_28.vz + iVar9 < iVar5) {
          FX_GetRandomScreenPt(&local_30);
          local_30.vz = local_30.vz + ((short)iVar5 - local_28.vz);
          FX_ConvertCamPersToWorld(&local_30,&local_28);
          if (local_28.vz + iVar9 < iVar5) goto LAB_8004aed8;
        }
        node = FX_GetPrim(gFXT);
        if (node != (_FX_PRIM *)0x0) {
          (node->_2).x = local_28.vx;
          (node->_2).y = local_28.vy;
          (node->_2).z = local_28.vz;
          uVar7 = rand();
          iVar8 = (int)windx * ((uVar7 & 0x3ff) + 0xc00);
          if (iVar8 < 0) {
            iVar8 = iVar8 + 0xfff;
          }
          *(short *)&node->duo = (short)(iVar8 >> 0xc);
          uVar7 = rand();
          iVar8 = (int)windy * ((uVar7 & 0x3ff) + 0xc00);
          if (iVar8 < 0) {
            iVar8 = iVar8 + 0xfff;
          }
          *(undefined2 *)((int)&node->duo + 2) = (short)(iVar8 >> 0xc);
          node->timeToLive = 0x14;
          node->flags = 0x1090000;
          node->color = 0x52404040;
          sVar1 = (node->_2).x;
          sVar2 = *(short *)&node->duo;
          *(code **)&node->process = FX_ProcessRain;
          sVar3 = (node->_2).y;
          *(short *)((int)&node->duo + 4) = (short)iVar9;
          sVar4 = *(short *)((int)&node->duo + 2);
          node->work0 = (short)iVar5;
          node->endColor = 0;
          (node->_3).x = sVar1 + sVar2;
          sVar1 = (node->_2).z;
          (node->_3).y = sVar3 + sVar4;
          (node->_3).z = sVar1 + (short)iVar9;
          LIST_InsertFunc(&fxTracker->usedPrimList,(NodeType *)node);
        }
      }
LAB_8004aed8:
      iVar10 = iVar10 + 1;
    } while (iVar10 < 3);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeSpark(struct _Instance *instance /*$a0*/, struct _Model *model /*$a1*/, int segment /*$a2*/)
 // line 4678, offset 0x8004af10
	/* begin block 1 */
		// Start line: 4679
		// Start offset: 0x8004AF10
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	// 		struct Object *particle; // $s1
	/* end block 1 */
	// End offset: 0x8004AFB8
	// End Line: 4708

	/* begin block 2 */
		// Start line: 11521
	/* end block 2 */
	// End Line: 11522

/* WARNING: Removing unreachable block (ram,0x8004af2c) */
/* WARNING: Removing unreachable block (ram,0x8004af44) */

void FX_MakeSpark(_Instance *instance,_Model *model,int segment)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueParticle(struct _FXParticle *currentParticle /*$s2*/, struct _FXTracker *fxTracker /*stack 4*/)
 // line 4710, offset 0x8004afcc
	/* begin block 1 */
		// Start line: 4711
		// Start offset: 0x8004AFCC
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
			// Start line: 4831
			// Start offset: 0x8004B548
			// Variables:
		// 		int tmp_blue; // $v1
		// 		struct CVECTOR *ptr; // $s0

			/* begin block 1.1.1 */
				// Start line: 4838
				// Start offset: 0x8004B56C
				// Variables:
			// 		int fade; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8004B590
			// End Line: 4844
		/* end block 1.1 */
		// End offset: 0x8004B590
		// End Line: 4845
	/* end block 1 */
	// End offset: 0x8004B7DC
	// End Line: 4910

	/* begin block 2 */
		// Start line: 11617
	/* end block 2 */
	// End Line: 11618

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
            goto switchD_8004b2d0_caseD_0;
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
switchD_8004b2d0_caseD_0:
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
          (fxPrim->_2).y = 0x1000;
          (fxPrim->_2).z = sVar8;
          (fxPrim->_2).x = sVar8;
          sVar8 = currentParticle->primLifeTime;
          fxPrim->flags = 0xc0008;
          fxPrim->timeToLive = (int)sVar8;
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
            (fxPrim->_2).y = currentParticle->startScale;
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
            (fxPrim->_2).x = sVar8;
            sVar7 = *(short *)((int)&fxPrim->duo + 4);
            (fxPrim->_3).x = sVar8 + sVar5;
            (fxPrim->_2).y = sVar3;
            (fxPrim->_2).z = sVar4;
            (fxPrim->_3).y = sVar3 + sVar6;
            (fxPrim->_3).z = sVar4 + sVar7;
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
 // line 4912, offset 0x8004b80c
	/* begin block 1 */
		// Start line: 4913
		// Start offset: 0x8004B80C
		// Variables:
	// 		int deg; // $s2
	/* end block 1 */
	// End offset: 0x8004B920
	// End Line: 4919

	/* begin block 2 */
		// Start line: 12196
	/* end block 2 */
	// End Line: 12197

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
 // line 4922, offset 0x8004b950
	/* begin block 1 */
		// Start line: 12216
	/* end block 1 */
	// End Line: 12217

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
 // line 4945, offset 0x8004ba58
	/* begin block 1 */
		// Start line: 4946
		// Start offset: 0x8004BA58
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	/* end block 1 */
	// End offset: 0x8004BAD8
	// End Line: 4957

	/* begin block 2 */
		// Start line: 12282
	/* end block 2 */
	// End Line: 12283

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
 // line 4983, offset 0x8004baec
	/* begin block 1 */
		// Start line: 12361
	/* end block 1 */
	// End Line: 12362

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
 // line 4995, offset 0x8004bb4c
	/* begin block 1 */
		// Start line: 4996
		// Start offset: 0x8004BB4C
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s2
	// 		struct _SVector position; // stack offset -40
	/* end block 1 */
	// End offset: 0x8004BC68
	// End Line: 5010

	/* begin block 2 */
		// Start line: 12385
	/* end block 2 */
	// End Line: 12386

void FX_MakeHitFlame(_SVector *startpos,int zpos,int angle,int dist,int size)

{
  _FX_PRIM *fxPrim;
  int iVar1;
  int iVar2;
  _SVector local_28;
  
  fxPrim = FX_GetPrim(gFXT);
  if (fxPrim != (_FX_PRIM *)0x0) {
    iVar1 = rcos(angle - 0x400U);
    iVar2 = rand();
    iVar1 = iVar1 * dist;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0xfff;
    }
    local_28.x = startpos->x + (short)(iVar1 >> 0xc) + ((ushort)iVar2 & 0xf);
    iVar1 = rsin(angle - 0x400U);
    iVar2 = rand();
    iVar1 = iVar1 * dist;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0xfff;
    }
    local_28.y = startpos->y + (short)(iVar1 >> 0xc) + ((ushort)iVar2 & 0xf);
    iVar1 = rand();
    local_28.z = startpos->z + (short)zpos + ((ushort)iVar1 & 0xf);
    FX_MakeParticleTexFX
              (fxPrim,&local_28,(Object *)0x0,0,0,(_SVector *)0x0,(_SVector *)0x0,0x93e4,size,2);
    FX_Sprite_Insert(&gFXT->usedPrimListSprite,fxPrim);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SetReaverInstance(struct _Instance *instance /*$a0*/)
 // line 5012, offset 0x8004bc8c
	/* begin block 1 */
		// Start line: 12430
	/* end block 1 */
	// End Line: 12431

	/* begin block 2 */
		// Start line: 12431
	/* end block 2 */
	// End Line: 12432

void FX_SetReaverInstance(_Instance *instance)

{
  FX_reaver_instance = instance;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SoulReaverBlade(struct _Instance *instance /*$a0*/, unsigned long **drawot /*stack 4*/)
 // line 5020, offset 0x8004bc98
	/* begin block 1 */
		// Start line: 5021
		// Start offset: 0x8004BC98
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
			// Start line: 5078
			// Start offset: 0x8004BE00
			// Variables:
		// 		int scale1; // $s0
		/* end block 1.1 */
		// End offset: 0x8004C02C
		// End Line: 5144
	/* end block 1 */
	// End offset: 0x8004C058
	// End Line: 5148

	/* begin block 2 */
		// Start line: 12446
	/* end block 2 */
	// End Line: 12447

/* WARNING: Removing unreachable block (ram,0x8004bd08) */
/* WARNING: Removing unreachable block (ram,0x8004bd1c) */
/* WARNING: Removing unreachable block (ram,0x8004bd24) */
/* WARNING: Removing unreachable block (ram,0x8004bd34) */
/* WARNING: Removing unreachable block (ram,0x8004bd44) */
/* WARNING: Removing unreachable block (ram,0x8004bd88) */
/* WARNING: Removing unreachable block (ram,0x8004bd8c) */
/* WARNING: Removing unreachable block (ram,0x8004be00) */
/* WARNING: Removing unreachable block (ram,0x8004be38) */
/* WARNING: Removing unreachable block (ram,0x8004be44) */
/* WARNING: Removing unreachable block (ram,0x8004be4c) */
/* WARNING: Removing unreachable block (ram,0x8004be58) */
/* WARNING: Removing unreachable block (ram,0x8004be68) */
/* WARNING: Removing unreachable block (ram,0x8004be70) */
/* WARNING: Removing unreachable block (ram,0x8004be80) */
/* WARNING: Removing unreachable block (ram,0x8004be84) */
/* WARNING: Removing unreachable block (ram,0x8004be98) */
/* WARNING: Removing unreachable block (ram,0x8004be9c) */
/* WARNING: Removing unreachable block (ram,0x8004beb4) */
/* WARNING: Removing unreachable block (ram,0x8004beb8) */
/* WARNING: Removing unreachable block (ram,0x8004becc) */
/* WARNING: Removing unreachable block (ram,0x8004bed0) */
/* WARNING: Removing unreachable block (ram,0x8004bff0) */
/* WARNING: Removing unreachable block (ram,0x8004c01c) */
/* WARNING: Removing unreachable block (ram,0x8004c028) */
/* WARNING: Removing unreachable block (ram,0x8004c02c) */
/* WARNING: Removing unreachable block (ram,0x8004c04c) */

void FX_SoulReaverBlade(_Instance *instance,ulong **drawot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ReaverBladeInit()
 // line 5160, offset 0x8004c088
	/* begin block 1 */
		// Start line: 12997
	/* end block 1 */
	// End Line: 12998

	/* begin block 2 */
		// Start line: 12998
	/* end block 2 */
	// End Line: 12999

/* WARNING: Unknown calling convention yet parameter storage is locked */

void FX_ReaverBladeInit(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SoulReaverWinding(struct _Instance *instance /*stack 0*/, struct _PrimPool *primPool /*$a1*/, unsigned long **ot /*stack 8*/, struct MATRIX *wcTransform /*stack 12*/)
 // line 5167, offset 0x8004c090
	/* begin block 1 */
		// Start line: 5168
		// Start offset: 0x8004C090
		// Variables:
	// 		struct MATRIX mat; // stack offset -96
	// 		struct MATRIX *swTransform; // $a1
	// 		struct _SVector start; // stack offset -64
	// 		struct _SVector end; // stack offset -56
	// 		struct __ReaverData *data; // $s4
	// 		long color; // $fp
	// 		long glow_color; // stack offset -48
	/* end block 1 */
	// End offset: 0x8004C294
	// End Line: 5241

	/* begin block 2 */
		// Start line: 13011
	/* end block 2 */
	// End Line: 13012

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
    color = *(long *)(pcVar1 + 0x10);
    local_30 = *(long *)(pcVar1 + 0x14);
    FX_Lightning(wcTransform,ot,&MStack96,deg,&local_40,&local_38,0x1e,10,0x10,0x20,0,color,local_30
                );
    CompMatrix((undefined4 *)wcTransform,(ushort *)((gameTrackerX.playerInstance)->matrix + 0x27),
               (uint *)&MStack96);
    local_38.z = -0x60;
    FX_Lightning(wcTransform,ot,&MStack96,deg,&local_40,&local_38,0x1e,10,0x10,0x20,0,color,local_30
                );
    iVar2 = (int)*(short *)(pcVar1 + 2) * (int)*(short *)(pcVar1 + 0x18);
    if (iVar2 < 0) {
      iVar2 = iVar2 + 0xfff;
    }
    iVar2 = (iVar2 >> 0xc) * -0x17c;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 0xfff;
    }
    local_38.z = (short)(iVar2 >> 0xc);
    CompMatrix((undefined4 *)wcTransform,(ushort *)(instance->matrix + 1),(uint *)&MStack96);
    FX_Lightning(wcTransform,ot,&MStack96,deg,&local_40,&local_38,0,0x19,4,8,0,color,local_30);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartInstanceBurrow(struct _Instance *instance /*$s0*/, struct Level *level /*$s2*/, struct _TFace *tface /*$s1*/)
 // line 5246, offset 0x8004c2c4
	/* begin block 1 */
		// Start line: 5247
		// Start offset: 0x8004C2C4
		// Variables:
	// 		struct _SVector normal; // stack offset -32
	// 		struct _SVector *poPlane; // $a1
	// 		struct _SVector point; // stack offset -24
	// 		struct _Position *globalOffset; // $v1
	/* end block 1 */
	// End offset: 0x8004C2C4
	// End Line: 5247

	/* begin block 2 */
		// Start line: 13230
	/* end block 2 */
	// End Line: 13231

void FX_StartInstanceBurrow(_Instance *instance,Level *level,_TFace *tface)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  long *plVar7;
  _TVertex *p_Var8;
  _SVector local_20 [2];
  
  COLLIDE_GetNormal(tface->normal,(short *)level->terrain->normalList,local_20);
  (instance->halvePlane).a = local_20[0].x;
  (instance->halvePlane).b = local_20[0].y;
  (instance->halvePlane).c = local_20[0].z;
  p_Var8 = level->terrain->vertexList + (tface->face)._2;
  sVar1 = (p_Var8->vertex).x;
  plVar7 = &level->terrain->signals->numSignals + instance->bspTree * 9;
  sVar2 = *(short *)(plVar7 + 3);
  sVar3 = (p_Var8->vertex).y;
  sVar4 = *(short *)((int)plVar7 + 0xe);
  sVar5 = (p_Var8->vertex).z;
  sVar6 = *(short *)(plVar7 + 4);
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
 // line 5271, offset 0x8004c3f8
	/* begin block 1 */
		// Start line: 13289
	/* end block 1 */
	// End Line: 13290

	/* begin block 2 */
		// Start line: 13290
	/* end block 2 */
	// End Line: 13291

void FX_StopInstanceBurrow(_Instance *instance)

{
  (instance->halvePlane).flags = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdateInstanceWaterSplit(struct _Instance *instance /*$s0*/)
 // line 5277, offset 0x8004c400
	/* begin block 1 */
		// Start line: 5278
		// Start offset: 0x8004C400
		// Variables:
	// 		struct _SVector normal; // stack offset -16
	/* end block 1 */
	// End offset: 0x8004C47C
	// End Line: 5303

	/* begin block 2 */
		// Start line: 13301
	/* end block 2 */
	// End Line: 13302

void FX_UpdateInstanceWaterSplit(_Instance *instance)

{
  _SVector _Stack16;
  
  if ((instance->waterFace == (_TFace *)0x0) || (instance->waterFaceTerrain == (_Terrain *)0x0)) {
    (instance->halvePlane).flags = (instance->halvePlane).flags & 0xfffd;
  }
  else {
    COLLIDE_GetNormal(instance->waterFace->normal,(short *)instance->waterFaceTerrain->normalList,
                      &_Stack16);
    (instance->halvePlane).flags = 2;
    FX_GetPlaneEquation(&_Stack16,&instance->splitPoint,&instance->halvePlane);
    FX_MakeWaterTrail(instance,(int)(instance->splitPoint).z);
  }
  instance->oldWaterFace = instance->waterFace;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_GetPlaneEquation(struct _SVector *normal /*$a0*/, struct _SVector *poPlane /*$a1*/, struct _PlaneConstants *plane /*$a2*/)
 // line 5306, offset 0x8004c498
	/* begin block 1 */
		// Start line: 13362
	/* end block 1 */
	// End Line: 13363

	/* begin block 2 */
		// Start line: 13364
	/* end block 2 */
	// End Line: 13365

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
 // line 5349, offset 0x8004c50c
	/* begin block 1 */
		// Start line: 5350
		// Start offset: 0x8004C50C
		// Variables:
	// 		struct _FXHalvePlane *ring; // $s0
	// 		struct _SVector normal; // stack offset -40
	// 		struct _SVector point; // stack offset -32
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x8004C67C
	// End Line: 5397

	/* begin block 2 */
		// Start line: 10692
	/* end block 2 */
	// End Line: 10693

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
  *(undefined4 *)(ptr + 4) = 0x8004c920;
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
      goto code_r0x8004c628;
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
code_r0x8004c628:
  *(long *)(ptr + 0x20) = lVar1;
  local_28.y = 0;
  local_28.x = 0;
  local_28.z = 0x1000;
  local_20.x = (instance->position).x;
  local_20.y = (instance->position).y;
  local_20.z = (instance->position).z;
  FX_GetPlaneEquation(&local_28,&local_20,(_PlaneConstants *)(ptr + 0x14));
  instance->flags2 = instance->flags2 | 0x1000000;
  FX_InsertGeneralEffect(ptr);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdatePowerRing(struct _FXHalvePlane *ring /*$s2*/)
 // line 5401, offset 0x8004c69c
	/* begin block 1 */
		// Start line: 5402
		// Start offset: 0x8004C69C
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
	// End offset: 0x8004C8E0
	// End Line: 5461

	/* begin block 2 */
		// Start line: 13543
	/* end block 2 */
	// End Line: 13544

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
  uVar11 = ((gameTrackerX.globalTimeMult % 1000) * 0x1000) / 1000;
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
  ring->diffTime = ring->diffTime + gameTrackerX.totalTime;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdateInstanceSplitRing(struct _FXHalvePlane *ring /*$s0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 5546, offset 0x8004c920
	/* begin block 1 */
		// Start line: 13856
	/* end block 1 */
	// End Line: 13857

void FX_UpdateInstanceSplitRing(_FXHalvePlane *ring,_FXTracker *fxTracker)

{
  if (ring->lifeTime != 0) {
    if (ring->type == '\0') {
      FX_UpdatePowerRing(ring);
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
 // line 5569, offset 0x8004c980
	/* begin block 1 */
		// Start line: 13902
	/* end block 1 */
	// End Line: 13903

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
 // line 5577, offset 0x8004c9b0
	/* begin block 1 */
		// Start line: 5579
		// Start offset: 0x8004C9B0
	/* end block 1 */
	// End offset: 0x8004C9B0
	// End Line: 5580

	/* begin block 2 */
		// Start line: 13918
	/* end block 2 */
	// End Line: 13919

	/* begin block 3 */
		// Start line: 13919
	/* end block 3 */
	// End Line: 13920

	/* begin block 4 */
		// Start line: 13920
	/* end block 4 */
	// End Line: 13921

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
 // line 5585, offset 0x8004c9c0
	/* begin block 1 */
		// Start line: 5586
		// Start offset: 0x8004C9C0
		// Variables:
	// 		struct _FXGeneralEffect *currentEffect; // $v0
	// 		struct _FXGeneralEffect *previousEffect; // $v1
	/* end block 1 */
	// End offset: 0x8004CA4C
	// End Line: 5618

	/* begin block 2 */
		// Start line: 13935
	/* end block 2 */
	// End Line: 13936

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
 // line 5623, offset 0x8004ca5c
	/* begin block 1 */
		// Start line: 5624
		// Start offset: 0x8004CA5C
		// Variables:
	// 		struct _FXGlowEffect *glowEffect; // $a2

		/* begin block 1.1 */
			// Start line: 5656
			// Start offset: 0x8004CB24
			// Variables:
		// 		int i; // $a1
		/* end block 1.1 */
		// End offset: 0x8004CB7C
		// End Line: 5669
	/* end block 1 */
	// End offset: 0x8004CB88
	// End Line: 5675

	/* begin block 2 */
		// Start line: 14011
	/* end block 2 */
	// End Line: 14012

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
  if (p_Var2 == (_FXGlowEffect *)0x0) goto LAB_8004cb88;
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
    if (color != (long *)0x0) goto LAB_8004cb70;
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
LAB_8004cb70:
    p_Var3 = (_Instance *)*color;
  }
  *(_Instance **)&p_Var2->currentColor = p_Var3;
  p_Var1 = p_Var2;
  *(_FXGeneralEffect **)&p_Var2->next = FX_GeneralEffectTracker;
  FX_GeneralEffectTracker = (_FXGeneralEffect *)p_Var1;
LAB_8004cb88:
  instance->flags2 = instance->flags2 | 0x200;
  return p_Var2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SetGlowFades(struct _FXGlowEffect *glowEffect /*$a0*/, int fadein /*$a1*/, int fadeout /*$a2*/)
 // line 5680, offset 0x8004cbbc
	/* begin block 1 */
		// Start line: 14147
	/* end block 1 */
	// End Line: 14148

	/* begin block 2 */
		// Start line: 14148
	/* end block 2 */
	// End Line: 14149

void FX_SetGlowFades(_FXGlowEffect *glowEffect,int fadein,int fadeout)

{
  glowEffect->fadein_time = (short)fadein * 0x21;
  glowEffect->fadeout_time = (short)fadeout * 0x21;
  return;
}



// decompiled code
// original method signature: 
// struct _FXGlowEffect * /*$ra*/ FX_DoInstanceTwoSegmentGlow(struct _Instance *instance /*$a0*/, long segment /*$a1*/, long segmentEnd /*$a2*/, long *color /*$a3*/, long numColors /*stack 16*/, long atuColorCycleRate /*stack 20*/, long height /*stack 24*/)
 // line 5686, offset 0x8004cbd8
	/* begin block 1 */
		// Start line: 5687
		// Start offset: 0x8004CBD8
		// Variables:
	// 		struct _FXGlowEffect *glowEffect; // $v0
	// 		int inc; // $s0
	/* end block 1 */
	// End offset: 0x8004CBF8
	// End Line: 5695

	/* begin block 2 */
		// Start line: 14159
	/* end block 2 */
	// End Line: 14160

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
 // line 5702, offset 0x8004cc30
	/* begin block 1 */
		// Start line: 5703
		// Start offset: 0x8004CC30
		// Variables:
	// 		struct _FXGlowEffect *glowEffect; // $v0
	/* end block 1 */
	// End offset: 0x8004CC30
	// End Line: 5703

	/* begin block 2 */
		// Start line: 14195
	/* end block 2 */
	// End Line: 14196

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
 // line 5713, offset 0x8004cc78
	/* begin block 1 */
		// Start line: 5714
		// Start offset: 0x8004CC78
		// Variables:
	// 		struct _FXGlowEffect *glowEffect; // $v0
	/* end block 1 */
	// End offset: 0x8004CC78
	// End Line: 5714

	/* begin block 2 */
		// Start line: 14220
	/* end block 2 */
	// End Line: 14221

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
 // line 5725, offset 0x8004ccc0
	/* begin block 1 */
		// Start line: 5726
		// Start offset: 0x8004CCC0
		// Variables:
	// 		struct _FXGlowEffect *currentEffect; // $a0
	// 		struct _FXGlowEffect *previousEffect; // $s1

		/* begin block 1.1 */
			// Start line: 5741
			// Start offset: 0x8004CD18
		/* end block 1.1 */
		// End offset: 0x8004CD18
		// End Line: 5742
	/* end block 1 */
	// End offset: 0x8004CD38
	// End Line: 5750

	/* begin block 2 */
		// Start line: 14244
	/* end block 2 */
	// End Line: 14245

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
 // line 5752, offset 0x8004cd54
	/* begin block 1 */
		// Start line: 5753
		// Start offset: 0x8004CD54

		/* begin block 1.1 */
			// Start line: 5762
			// Start offset: 0x8004CD98
			// Variables:
		// 		struct _FXGeneralEffect *currentEffect; // $a0
		// 		struct _FXGeneralEffect *previousEffect; // $s0
		/* end block 1.1 */
		// End offset: 0x8004CDC4
		// End Line: 5775
	/* end block 1 */
	// End offset: 0x8004CDC4
	// End Line: 5776

	/* begin block 2 */
		// Start line: 14310
	/* end block 2 */
	// End Line: 14311

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
 // line 5778, offset 0x8004cddc
	/* begin block 1 */
		// Start line: 5779
		// Start offset: 0x8004CDDC
		// Variables:
	// 		struct _SVector start; // stack offset -48
	// 		struct _SVector end; // stack offset -40
	// 		struct _SVector offset; // stack offset -32
	// 		struct MATRIX *swtransform; // $s0
	/* end block 1 */
	// End offset: 0x8004CF4C
	// End Line: 5817

	/* begin block 2 */
		// Start line: 14364
	/* end block 2 */
	// End Line: 14365

void FX_DrawLightning(_FXLightning *zap,MATRIX *wcTransform,ulong **ot)

{
  MATRIX *pMVar1;
  MATRIX *mat;
  _SVector local_30;
  _SVector local_28;
  short local_20;
  short local_1e;
  short local_1c;
  
  if (zap->type == '\x02') {
    local_30.x = (zap->start_offset).x;
    local_30.y = (zap->start_offset).y;
    local_30.z = (zap->start_offset).z;
  }
  else {
    pMVar1 = zap->instance->matrix + zap->startSeg;
    ApplyMatrixSV(pMVar1,&zap->start_offset,&local_20);
    local_30.x = *(short *)pMVar1->t + local_20;
    local_30.y = *(short *)(pMVar1->t + 1) + local_1e;
    local_30.z = *(short *)(pMVar1->t + 2) + local_1c;
  }
  if ((uint)zap->type - 1 < 2) {
    local_28.x = (zap->end_offset).x;
    local_28.y = (zap->end_offset).y;
    local_28.z = (zap->end_offset).z;
  }
  else {
    pMVar1 = zap->end_instance->matrix + zap->endSeg;
    ApplyMatrixSV(pMVar1,&zap->end_offset,&local_20);
    local_28.x = *(short *)pMVar1->t + local_20;
    local_28.y = *(short *)(pMVar1->t + 1) + local_1e;
    local_28.z = *(short *)(pMVar1->t + 2) + local_1c;
  }
  mat = (MATRIX *)0x0;
  if ((int)zap->matrixSeg != -1) {
    mat = (MATRIX *)(zap->instance->matrix + (int)zap->matrixSeg);
  }
  FX_Lightning(wcTransform,ot,mat,zap->deg,&local_30,&local_28,(int)zap->width,(int)zap->small_width
               ,(int)zap->segs,(int)zap->sine_size,(int)zap->variation,zap->color,zap->glow_color);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawAllGeneralEffects(struct MATRIX *wcTransform /*$s1*/, struct _VertexPool *vertexPool /*$s3*/, struct _PrimPool *primPool /*$s4*/, unsigned long **ot /*$s2*/)
 // line 5824, offset 0x8004cfd4
	/* begin block 1 */
		// Start line: 5825
		// Start offset: 0x8004CFD4
		// Variables:
	// 		struct _Instance *instance; // $a0
	// 		struct _FXGeneralEffect *currentEffect; // $s0

		/* begin block 1.1 */
			// Start line: 5838
			// Start offset: 0x8004D060
			// Variables:
		// 		struct _FXGlowEffect *currentGlow; // $t0
		/* end block 1.1 */
		// End offset: 0x8004D090
		// End Line: 5846

		/* begin block 1.2 */
			// Start line: 5850
			// Start offset: 0x8004D0B8
		/* end block 1.2 */
		// End offset: 0x8004D0B8
		// End Line: 5851

		/* begin block 1.3 */
			// Start line: 5860
			// Start offset: 0x8004D0FC
		/* end block 1.3 */
		// End offset: 0x8004D0FC
		// End Line: 5862

		/* begin block 1.4 */
			// Start line: 5870
			// Start offset: 0x8004D154
		/* end block 1.4 */
		// End offset: 0x8004D154
		// End Line: 5872
	/* end block 1 */
	// End offset: 0x8004D18C
	// End Line: 5882

	/* begin block 2 */
		// Start line: 14458
	/* end block 2 */
	// End Line: 14459

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
             (iVar2 = (uint)(ushort)blast->lifeTime - (uint)(ushort)gameTrackerX.totalTime,
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
 // line 5892, offset 0x8004d1ac
	/* begin block 1 */
		// Start line: 5893
		// Start offset: 0x8004D1AC

		/* begin block 1.1 */
			// Start line: 5901
			// Start offset: 0x8004D1F0
			// Variables:
		// 		int rad; // $v0
		// 		int crad; // $a0
		// 		int endrad; // $v1
		/* end block 1.1 */
		// End offset: 0x8004D284
		// End Line: 5919
	/* end block 1 */
	// End offset: 0x8004D304
	// End Line: 5938

	/* begin block 2 */
		// Start line: 14599
	/* end block 2 */
	// End Line: 14600

void FX_ContinueBlastRing(_FXBlastringEffect *blast,_FXTracker *fxTracker)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = blast->endRadius;
  blast->radius = blast->radius + blast->colorchange_radius;
  iVar3 = blast->radius;
  blast->colorchange_radius = blast->colorchange_radius + blast->vel;
  if (iVar4 < iVar3) {
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0xfff;
    }
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0xfff;
    }
    iVar2 = blast->startRadius;
    iVar4 = iVar4 >> 0xc;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 0xfff;
    }
    iVar2 = iVar2 >> 0xc;
    if (iVar2 == 0) {
      iVar2 = iVar4 + 0x1000;
    }
    iVar3 = (((iVar3 >> 0xc) - iVar4) * 0x1000) / (iVar2 - iVar4);
    if (iVar3 < 0x1001) {
      LoadAverageCol((byte *)&blast->startColor,(byte *)&blast->color,iVar3,0x1000 - iVar3,
                     (undefined *)&blast->predator_offset);
      *(uint *)&blast->predator_offset = *(uint *)&blast->predator_offset & 0xffffff;
    }
    else {
      *(undefined4 *)&blast->predator_offset = 0;
    }
  }
  if (((blast->lifeTime != -99) &&
      (((0 < blast->colorchange_radius && (blast->startRadius < blast->radius)) ||
       ((blast->colorchange_radius < 0 && (blast->radius < blast->startRadius)))))) ||
     ((uVar1 = blast->lifeTime - 1, -1 < blast->lifeTime &&
      (blast->lifeTime = uVar1, (int)((uint)uVar1 << 0x10) < 1)))) {
    FX_DeleteGeneralEffect((_FXGeneralEffect *)blast);
  }
  return;
}



// decompiled code
// original method signature: 
// struct _FXBlastringEffect * /*$ra*/ FX_DoBlastRing(struct _Instance *instance /*$s2*/, struct _SVector *position /*$s5*/, struct MATRIX *mat /*$s3*/, int segment /*$s6*/, int radius /*stack 16*/, int endRadius /*stack 20*/, int colorChangeRadius /*stack 24*/, int size1 /*stack 28*/, int size2 /*stack 32*/, int vel /*stack 36*/, int accl /*stack 40*/, int height1 /*stack 44*/, int height2 /*stack 48*/, int height3 /*stack 52*/, long startColor /*stack 56*/, long endColor /*stack 60*/, int pred_offset /*stack 64*/, int lifeTime /*stack 68*/, int sortInWorld /*stack 72*/)
 // line 5968, offset 0x8004d314
	/* begin block 1 */
		// Start line: 5969
		// Start offset: 0x8004D314
		// Variables:
	// 		struct _FXBlastringEffect *blast; // $s0
	/* end block 1 */
	// End offset: 0x8004D4B0
	// End Line: 6007

	/* begin block 2 */
		// Start line: 14756
	/* end block 2 */
	// End Line: 14757

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
  
  ptr = (_FXBlastringEffect *)MEMPACK_Malloc(0x74,'\r');
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
    *(short *)&ptr->height3 = (short)pred_offset;
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
    ptr->size1 = size1;
    ptr->size2 = size2;
    ptr->startRadius = endRadius << 0xc;
    ptr->endRadius = colorChangeRadius << 0xc;
    ptr->colorchange_radius = vel;
    ptr->vel = accl;
    ptr->accl = height1;
    ptr->height1 = height2;
    *(long *)&ptr->predator_offset = startColor;
    ptr->color = startColor;
    ptr->height2 = height3;
    ptr->startColor = endColor;
    *(undefined2 *)((int)&ptr->height3 + 2) = (short)sortInWorld;
    FX_InsertGeneralEffect(ptr);
  }
  return ptr;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawBlastring(struct MATRIX *wcTransform /*$s3*/, struct _FXBlastringEffect *blast /*$s1*/)
 // line 6010, offset 0x8004d4dc
	/* begin block 1 */
		// Start line: 6011
		// Start offset: 0x8004D4DC
		// Variables:
	// 		int radius; // $s2
	// 		struct _SVector position; // stack offset -64
	// 		struct MATRIX mat; // stack offset -56

		/* begin block 1.1 */
			// Start line: 6018
			// Start offset: 0x8004D51C
			// Variables:
		// 		struct MATRIX *swtransform; // $s0
		/* end block 1.1 */
		// End offset: 0x8004D51C
		// End Line: 6019
	/* end block 1 */
	// End offset: 0x8004D670
	// End Line: 6042

	/* begin block 2 */
		// Start line: 14849
	/* end block 2 */
	// End Line: 14850

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
    local_40 = *(undefined4 *)&blast->position;
    local_3c = *(undefined4 *)&(blast->position).z;
  }
  else {
    pMVar1 = blast->instance->matrix + (int)blast->segment;
    CompMatrix((undefined4 *)wcTransform,(ushort *)pMVar1,(uint *)&MStack56);
    local_40 = CONCAT22(*(undefined2 *)(pMVar1->t + 1),*(undefined2 *)pMVar1->t);
    local_3c = CONCAT22(local_3c._2_2_,*(undefined2 *)(pMVar1->t + 2));
  }
  if (blast->type == '\0') {
    FX_DrawRing(wcTransform,(_SVector *)&local_40,&MStack56,radius,radius + blast->size1,
                radius + blast->size2,blast->accl,blast->height1,blast->height2,
                *(long *)&blast->predator_offset,(int)*(short *)((int)&blast->height3 + 2));
  }
  else {
    if (blast->type == '\x01') {
      FX_DrawRing2(wcTransform,&blast->position,&MStack56,radius,radius + blast->size1,
                   radius + blast->size2,blast->accl,blast->height1,blast->height2,
                   (int)*(short *)&blast->height3,(int)*(short *)((int)&blast->height3 + 2));
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueFlash(struct _FXFlash *flash /*$a0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 6045, offset 0x8004d68c
	/* begin block 1 */
		// Start line: 14921
	/* end block 1 */
	// End Line: 14922

void FX_ContinueFlash(_FXFlash *flash,_FXTracker *fxTracker)

{
  int iVar1;
  
  iVar1 = flash->currentTime + gameTrackerX.idleTime;
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
 // line 6055, offset 0x8004d6dc
	/* begin block 1 */
		// Start line: 6056
		// Start offset: 0x8004D6DC
		// Variables:
	// 		int time; // $a1
	// 		int div; // $a2
	// 		int transtype; // $s0
	// 		int interp; // $a3
	// 		unsigned long color; // stack offset -16
	// 		unsigned long black; // stack offset -12
	/* end block 1 */
	// End offset: 0x8004D7D0
	// End Line: 6086

	/* begin block 2 */
		// Start line: 14941
	/* end block 2 */
	// End Line: 14942

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
    if (iVar2 <= iVar3) goto LAB_8004d7d0;
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
LAB_8004d7d0:
  FX_DrawScreenPoly(transtype,local_10,5);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_RelocateGeneric(struct Object *object /*$a0*/, long offset /*$a1*/)
 // line 6089, offset 0x8004d7f0
	/* begin block 1 */
		// Start line: 6091
		// Start offset: 0x8004D7F0
		// Variables:
	// 		struct GenericFXObject *GFXO; // $v0
	/* end block 1 */
	// End offset: 0x8004D884
	// End Line: 6100

	/* begin block 2 */
		// Start line: 15012
	/* end block 2 */
	// End Line: 15013

	/* begin block 3 */
		// Start line: 15013
	/* end block 3 */
	// End Line: 15014

	/* begin block 4 */
		// Start line: 15015
	/* end block 4 */
	// End Line: 15016

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
 // line 6103, offset 0x8004d88c
	/* begin block 1 */
		// Start line: 6104
		// Start offset: 0x8004D88C
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	// 		struct GenericFXObject *GFXO; // $v1
	// 		struct _GenericParticleParams *GPP; // $s1
	// 		struct Object *texture_obj; // $s2
	// 		struct Object *particle; // $a2

		/* begin block 1.1 */
			// Start line: 6163
			// Start offset: 0x8004DAA8
			// Variables:
		// 		struct TextureMT3 *texture; // $v0
		/* end block 1.1 */
		// End offset: 0x8004DAD0
		// End Line: 6167
	/* end block 1 */
	// End offset: 0x8004DB34
	// End Line: 6178

	/* begin block 2 */
		// Start line: 15040
	/* end block 2 */
	// End Line: 15041

/* WARNING: Removing unreachable block (ram,0x8004d8c4) */
/* WARNING: Removing unreachable block (ram,0x8004d8e0) */
/* WARNING: Removing unreachable block (ram,0x8004d8f0) */
/* WARNING: Removing unreachable block (ram,0x8004d900) */
/* WARNING: Removing unreachable block (ram,0x8004d910) */
/* WARNING: Removing unreachable block (ram,0x8004d918) */
/* WARNING: Removing unreachable block (ram,0x8004d928) */
/* WARNING: Removing unreachable block (ram,0x8004d93c) */
/* WARNING: Removing unreachable block (ram,0x8004d978) */
/* WARNING: Removing unreachable block (ram,0x8004d96c) */
/* WARNING: Removing unreachable block (ram,0x8004d97c) */
/* WARNING: Removing unreachable block (ram,0x8004d9e4) */
/* WARNING: Removing unreachable block (ram,0x8004d9dc) */
/* WARNING: Removing unreachable block (ram,0x8004d9f0) */
/* WARNING: Removing unreachable block (ram,0x8004da60) */
/* WARNING: Removing unreachable block (ram,0x8004da8c) */
/* WARNING: Removing unreachable block (ram,0x8004da70) */
/* WARNING: Removing unreachable block (ram,0x8004da98) */
/* WARNING: Removing unreachable block (ram,0x8004daa8) */
/* WARNING: Removing unreachable block (ram,0x8004dad0) */
/* WARNING: Removing unreachable block (ram,0x8004dae0) */
/* WARNING: Removing unreachable block (ram,0x8004dae8) */
/* WARNING: Removing unreachable block (ram,0x8004daf8) */
/* WARNING: Removing unreachable block (ram,0x8004db08) */
/* WARNING: Removing unreachable block (ram,0x8004db18) */
/* WARNING: Removing unreachable block (ram,0x8004db28) */

_FXParticle *
FX_StartGenericParticle(_Instance *instance,int num,int segOverride,int lifeOverride,int InitFlag)

{
  return (_FXParticle *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartGenericRibbon(struct _Instance *instance /*$a0*/, int num /*$a1*/, int segOverride /*$a2*/, int endOverride /*$a3*/, int InitFlag /*stack 16*/)
 // line 6180, offset 0x8004db54
	/* begin block 1 */
		// Start line: 6181
		// Start offset: 0x8004DB54
		// Variables:
	// 		struct Object *particle; // $v1
	// 		struct GenericFXObject *GFXO; // $v1
	// 		struct _GenericRibbonParams *GRP; // $v1
	/* end block 1 */
	// End offset: 0x8004DBDC
	// End Line: 6210

	/* begin block 2 */
		// Start line: 15207
	/* end block 2 */
	// End Line: 15208

/* WARNING: Removing unreachable block (ram,0x8004db6c) */
/* WARNING: Removing unreachable block (ram,0x8004db88) */
/* WARNING: Removing unreachable block (ram,0x8004db98) */

void FX_StartGenericRibbon(_Instance *instance,int num,int segOverride,int endOverride,int InitFlag)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartGenericGlow(struct _Instance *instance /*$a0*/, int num /*$a1*/, int segOverride /*$t1*/, int seg2Override /*$a3*/, int InitFlag /*stack 16*/)
 // line 6212, offset 0x8004dbec
	/* begin block 1 */
		// Start line: 6213
		// Start offset: 0x8004DBEC
		// Variables:
	// 		struct Object *particle; // $v1
	// 		struct GenericFXObject *GFXO; // $t0
	// 		struct _GenericGlowParams *GGP; // $s0
	// 		struct _FXGlowEffect *glowEffect; // $a0
	// 		long *color; // $v1

		/* begin block 1.1 */
			// Start line: 6234
			// Start offset: 0x8004DC58
			// Variables:
		// 		int seg; // $a1
		/* end block 1.1 */
		// End offset: 0x8004DC64
		// End Line: 6236

		/* begin block 1.2 */
			// Start line: 6240
			// Start offset: 0x8004DC9C
			// Variables:
		// 		int seg; // $a1
		// 		int segEnd; // $a2
		/* end block 1.2 */
		// End offset: 0x8004DCBC
		// End Line: 6251

		/* begin block 1.3 */
			// Start line: 6255
			// Start offset: 0x8004DCEC
			// Variables:
		// 		int seg; // $a1
		// 		int numSeg; // $a2
		/* end block 1.3 */
		// End offset: 0x8004DD34
		// End Line: 6274
	/* end block 1 */
	// End offset: 0x8004DD64
	// End Line: 6281

	/* begin block 2 */
		// Start line: 15278
	/* end block 2 */
	// End Line: 15279

/* WARNING: Removing unreachable block (ram,0x8004dc0c) */
/* WARNING: Removing unreachable block (ram,0x8004dc28) */
/* WARNING: Removing unreachable block (ram,0x8004dc38) */
/* WARNING: Removing unreachable block (ram,0x8004dc94) */
/* WARNING: Removing unreachable block (ram,0x8004dcec) */
/* WARNING: Removing unreachable block (ram,0x8004dcf4) */
/* WARNING: Removing unreachable block (ram,0x8004dcfc) */
/* WARNING: Removing unreachable block (ram,0x8004dd04) */
/* WARNING: Removing unreachable block (ram,0x8004dd08) */
/* WARNING: Removing unreachable block (ram,0x8004dc9c) */
/* WARNING: Removing unreachable block (ram,0x8004dca4) */
/* WARNING: Removing unreachable block (ram,0x8004dcac) */
/* WARNING: Removing unreachable block (ram,0x8004dcb4) */
/* WARNING: Removing unreachable block (ram,0x8004dcbc) */
/* WARNING: Removing unreachable block (ram,0x8004dc58) */
/* WARNING: Removing unreachable block (ram,0x8004dc60) */
/* WARNING: Removing unreachable block (ram,0x8004dc64) */
/* WARNING: Removing unreachable block (ram,0x8004dd34) */
/* WARNING: Removing unreachable block (ram,0x8004dd3c) */
/* WARNING: Removing unreachable block (ram,0x8004dd4c) */

void FX_StartGenericGlow(_Instance *instance,int num,int segOverride,int seg2Override,int InitFlag)

{
  return;
}



// decompiled code
// original method signature: 
// struct _FXLightning * /*$ra*/ FX_CreateLightning(struct _Instance *instance /*$s1*/, int lifeTime /*$s2*/, int deg /*$s3*/, int deg_inc /*$s4*/, int width /*stack 16*/, int small_width /*stack 20*/, int segs /*stack 24*/, int sine_size /*stack 28*/, int variation /*stack 32*/, unsigned long color /*stack 36*/, unsigned long glow_color /*stack 40*/)
 // line 6301, offset 0x8004dd74
	/* begin block 1 */
		// Start line: 6302
		// Start offset: 0x8004DD74
		// Variables:
	// 		struct _FXLightning *zap; // $s0
	/* end block 1 */
	// End offset: 0x8004DE58
	// End Line: 6337

	/* begin block 2 */
		// Start line: 15466
	/* end block 2 */
	// End Line: 15467

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
 // line 6358, offset 0x8004de7c
	/* begin block 1 */
		// Start line: 15592
	/* end block 1 */
	// End Line: 15593

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
    if (startInstance != (_Instance *)0x0) goto LAB_8004dec8;
  }
  if (endInstance == (_Instance *)0x0) {
    zap->type = '\x02';
  }
LAB_8004dec8:
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
// struct _FXLightning * /*$ra*/ FX_StartGenericLightning(struct _Instance *instance /*$s4*/, int num /*$a1*/, int segOverride /*$s2*/, int endSegOverride /*$s3*/)
 // line 6387, offset 0x8004df2c
	/* begin block 1 */
		// Start line: 6388
		// Start offset: 0x8004DF2C
		// Variables:
	// 		struct _FXLightning *zap; // $s1
	// 		struct GenericFXObject *GFXO; // $v1
	// 		struct _GenericLightningParams *GLP; // $s0
	// 		struct Object *particle; // $v1

		/* begin block 1.1 */
			// Start line: 6406
			// Start offset: 0x8004DFF0
			// Variables:
		// 		int startSeg; // $a2
		// 		int endSeg; // $a3
		/* end block 1.1 */
		// End offset: 0x8004E038
		// End Line: 6429
	/* end block 1 */
	// End offset: 0x8004E03C
	// End Line: 6432

	/* begin block 2 */
		// Start line: 15650
	/* end block 2 */
	// End Line: 15651

	/* begin block 3 */
		// Start line: 15656
	/* end block 3 */
	// End Line: 15657

/* WARNING: Removing unreachable block (ram,0x8004df64) */
/* WARNING: Removing unreachable block (ram,0x8004dff0) */
/* WARNING: Removing unreachable block (ram,0x8004dff8) */
/* WARNING: Removing unreachable block (ram,0x8004dffc) */
/* WARNING: Removing unreachable block (ram,0x8004e010) */
/* WARNING: Removing unreachable block (ram,0x8004e004) */
/* WARNING: Removing unreachable block (ram,0x8004e014) */
/* WARNING: Removing unreachable block (ram,0x8004e038) */

_FXLightning *
FX_StartGenericLightning(_Instance *instance,int num,int segOverride,int endSegOverride)

{
  return (_FXLightning *)0x0;
}



// decompiled code
// original method signature: 
// struct _FXBlastringEffect * /*$ra*/ FX_StartGenericBlastring(struct _Instance *instance /*$s4*/, int num /*$a1*/, int segOverride /*$a2*/, int matrixSegOverride /*$a3*/)
 // line 6435, offset 0x8004e05c
	/* begin block 1 */
		// Start line: 6436
		// Start offset: 0x8004E05C
		// Variables:
	// 		struct GenericFXObject *GFXO; // $v1
	// 		struct _GenericBlastringParams *GBP; // $s1
	// 		struct Object *particle; // $v1
	// 		struct _SVector position; // stack offset -64
	// 		int segment; // $s2
	// 		int matrix_segment; // $s3
	// 		struct MATRIX mat; // stack offset -56
	// 		struct MATRIX *swTransform; // $a0
	/* end block 1 */
	// End offset: 0x8004E1E4
	// End Line: 6485

	/* begin block 2 */
		// Start line: 15753
	/* end block 2 */
	// End Line: 15754

	/* begin block 3 */
		// Start line: 15764
	/* end block 3 */
	// End Line: 15765

/* WARNING: Removing unreachable block (ram,0x8004e08c) */
/* WARNING: Removing unreachable block (ram,0x8004e0bc) */
/* WARNING: Removing unreachable block (ram,0x8004e0b0) */
/* WARNING: Removing unreachable block (ram,0x8004e0c0) */
/* WARNING: Removing unreachable block (ram,0x8004e0d4) */
/* WARNING: Removing unreachable block (ram,0x8004e0c8) */
/* WARNING: Removing unreachable block (ram,0x8004e0d8) */

_FXBlastringEffect *
FX_StartGenericBlastring(_Instance *instance,int num,int segOverride,int matrixSegOverride)

{
  return (_FXBlastringEffect *)0x0;
}



// decompiled code
// original method signature: 
// struct _FXFlash * /*$ra*/ FX_StartGenericFlash(struct _Instance *instance /*$s2*/, int num /*$a1*/)
 // line 6487, offset 0x8004e204
	/* begin block 1 */
		// Start line: 6488
		// Start offset: 0x8004E204
		// Variables:
	// 		struct GenericFXObject *GFXO; // $v1
	// 		struct _GenericFlashParams *GFP; // $s1
	// 		struct Object *particle; // $v1
	// 		struct _FXFlash *flash; // $s0
	/* end block 1 */
	// End offset: 0x8004E2CC
	// End Line: 6519

	/* begin block 2 */
		// Start line: 15870
	/* end block 2 */
	// End Line: 15871

	/* begin block 3 */
		// Start line: 15876
	/* end block 3 */
	// End Line: 15877

/* WARNING: Removing unreachable block (ram,0x8004e230) */
/* WARNING: Removing unreachable block (ram,0x8004e260) */
/* WARNING: Removing unreachable block (ram,0x8004e2c8) */

_FXFlash * FX_StartGenericFlash(_Instance *instance,int num)

{
  return (_FXFlash *)0x0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ FX_GetHealthColor(int currentHealth /*$a0*/)
 // line 6521, offset 0x8004e2e4
	/* begin block 1 */
		// Start line: 6542
		// Start offset: 0x8004E2E4
		// Variables:
	// 		static long HealthColors[6]; // offset 0x0
	// 		long color; // $v1
	/* end block 1 */
	// End offset: 0x8004E328
	// End Line: 6559

	/* begin block 2 */
		// Start line: 15953
	/* end block 2 */
	// End Line: 15954

	/* begin block 3 */
		// Start line: 15973
	/* end block 3 */
	// End Line: 15974

	/* begin block 4 */
		// Start line: 15984
	/* end block 4 */
	// End Line: 15985

long FX_GetHealthColor(int currentHealth)

{
  uint uVar1;
  
  if (currentHealth < 1) {
    uVar1 = 0x7f;
  }
  else {
    if ((uint)currentHealth < 6) {
      uVar1 = (&DAT_800c5194)[currentHealth + -1];
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
 // line 6563, offset 0x8004e338
	/* begin block 1 */
		// Start line: 16037
	/* end block 1 */
	// End Line: 16038

	/* begin block 2 */
		// Start line: 16038
	/* end block 2 */
	// End Line: 16039

void FX_Start_Snow(int percent)

{
  snow_amount = (short)((percent * 0x300) / 100);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Start_Rain(int percent /*$a0*/)
 // line 6568, offset 0x8004e36c
	/* begin block 1 */
		// Start line: 16047
	/* end block 1 */
	// End Line: 16048

	/* begin block 2 */
		// Start line: 16048
	/* end block 2 */
	// End Line: 16049

void FX_Start_Rain(int percent)

{
  rain_amount = (short)((percent << 10) / 100);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartLightbeam(struct _Instance *instance /*$s1*/, int startSeg /*$s2*/, int endSeg /*$s3*/, int color_num /*$a3*/)
 // line 6574, offset 0x8004e398
	/* begin block 1 */
		// Start line: 6575
		// Start offset: 0x8004E398
		// Variables:
	// 		struct Object *particle; // $v0
	// 		struct _FXLightBeam *beam; // $v0
	// 		struct GenericFXObject *GFXO; // $v0
	// 		long color; // $s0
	/* end block 1 */
	// End offset: 0x8004E420
	// End Line: 6599

	/* begin block 2 */
		// Start line: 16059
	/* end block 2 */
	// End Line: 16060

	/* begin block 3 */
		// Start line: 16065
	/* end block 3 */
	// End Line: 16066

/* WARNING: Removing unreachable block (ram,0x8004e3c8) */
/* WARNING: Removing unreachable block (ram,0x8004e3f4) */

void FX_StartLightbeam(_Instance *instance,int startSeg,int endSeg,int color_num)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartInstanceEffect(struct _Instance *instance /*$s2*/, struct ObjectEffect *effect /*$s0*/, int InitFlag /*$s3*/)
 // line 6611, offset 0x8004e43c
	/* begin block 1 */
		// Start line: 6612
		// Start offset: 0x8004E43C
		// Variables:
	// 		long color; // stack offset -32

		/* begin block 1.1 */
			// Start line: 6645
			// Start offset: 0x8004E514
			// Variables:
		// 		long numberOfSegments; // $a2
		/* end block 1.1 */
		// End offset: 0x8004E560
		// End Line: 6665

		/* begin block 1.2 */
			// Start line: 6676
			// Start offset: 0x8004E58C
			// Variables:
		// 		struct _FXParticle *currentParticle; // $a0
		/* end block 1.2 */
		// End offset: 0x8004E5A4
		// End Line: 6683

		/* begin block 1.3 */
			// Start line: 6726
			// Start offset: 0x8004E660
			// Variables:
		// 		struct _FXParticle *currentParticle; // $a0
		// 		struct evObjectDraftData *draft; // $s1
		/* end block 1.3 */
		// End offset: 0x8004E698
		// End Line: 6735

		/* begin block 1.4 */
			// Start line: 6762
			// Start offset: 0x8004E75C
			// Variables:
		// 		struct FXSplinter *splinterData; // $t0
		// 		struct GenericTune *tune; // $v1
		// 		short shardFlags; // $v0
		/* end block 1.4 */
		// End offset: 0x8004E7B8
		// End Line: 6775
	/* end block 1 */
	// End offset: 0x8004E7B8
	// End Line: 6781

	/* begin block 2 */
		// Start line: 16146
	/* end block 2 */
	// End Line: 16147

void FX_StartInstanceEffect(_Instance *instance,ObjectEffect *effect,int InitFlag)

{
  ushort uVar1;
  short sVar2;
  ulong uVar3;
  _FXParticle *ptr;
  uint *puVar4;
  uint numSegments;
  FXSplinter *splintDef;
  long local_20 [2];
  
  local_20[0] = 0x4080;
  switch(effect->effectNumber) {
  case '\x01':
    FX_TorchFlame(instance,(ushort)effect->modifierList[0]);
    break;
  case '\x02':
    if ((uint)effect->modifierList[1] - 1 < 5) {
      local_20[0] = (&FX_ColorArray)[effect->modifierList[1]];
    }
    FX_DoInstanceOneSegmentGlow(instance,(uint)effect->modifierList[0],local_20,1,0x400,0x32,100);
    break;
  case '\x03':
    numSegments = (uint)effect->modifierList[1];
    if (effect->modifierList[1] == 0) {
      numSegments = 1;
    }
    if ((uint)effect->modifierList[2] - 1 < 5) {
      local_20[0] = (&FX_ColorArray)[effect->modifierList[2]];
    }
    FX_DoInstanceManySegmentGlow
              (instance,(uint)effect->modifierList[0],numSegments,local_20,1,0x400,0x41);
    break;
  case '\x04':
    ptr = FX_GetParticle(instance,0);
    if (ptr != (_FXParticle *)0x0) {
      *(code **)&ptr->continue_process = FX_GenericBubbleProcess;
      ptr->lifeTime = -1;
      ptr->startSegment = effect->modifierList[0];
      FX_InsertGeneralEffect(ptr);
    }
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
       (ptr = FX_StartGenericParticle
                        (instance,(uint)effect->modifierList[0],(uint)effect->modifierList[1],
                         (uint)effect->modifierList[2],InitFlag), ptr != (_FXParticle *)0x0)) {
      (ptr->direction).x = *(short *)(uVar3 + 2);
      (ptr->direction).y = *(short *)(uVar3 + 4);
      (ptr->direction).z = *(short *)(uVar3 + 6);
      uVar1 = *(ushort *)(uVar3 + 8);
      ptr->birthRadius = 0;
      *(code **)&ptr->fxprim_modify_process = FX_UpdraftPrimModify;
      ptr->primLifeTime = uVar1 >> 3;
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
      puVar4 = (uint *)instance->object->data;
      sVar2 = 0;
      if (puVar4 != (uint *)0x0) {
        splintDef = (FXSplinter *)puVar4[1];
        sVar2 = (short)((*puVar4 & 2) << 3);
      }
      _FX_BuildSplinters(instance,(SVECTOR *)0x0,(SVECTOR *)0x0,(SVECTOR *)0x0,splintDef,gFXT,
                         (TDRFuncPtr__FX_BuildSplinters6fxSetup)0x0,
                         (TDRFuncPtr__FX_BuildSplinters7fxProcess)0x0,(int)sVar2);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_EndInstanceEffects(struct _Instance *instance /*$s1*/)
 // line 6785, offset 0x8004e7d4
	/* begin block 1 */
		// Start line: 6786
		// Start offset: 0x8004E7D4
		// Variables:
	// 		struct _FXGeneralEffect *currentEffect; // $a0
	// 		struct _FXGeneralEffect *nextEffect; // $s0
	/* end block 1 */
	// End offset: 0x8004E814
	// End Line: 6799

	/* begin block 2 */
		// Start line: 16514
	/* end block 2 */
	// End Line: 16515

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
 // line 6808, offset 0x8004e828
	/* begin block 1 */
		// Start line: 6809
		// Start offset: 0x8004E828
		// Variables:
	// 		int prevx; // $a0
	// 		int prevy; // $v0
	/* end block 1 */
	// End offset: 0x8004E8D4
	// End Line: 6823

	/* begin block 2 */
		// Start line: 16564
	/* end block 2 */
	// End Line: 16565

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
  *y = (iVar1 >> 0xc) + 0xcb;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_CalcSpiral(int degchange /*$s4*/)
 // line 6850, offset 0x8004e8fc
	/* begin block 1 */
		// Start line: 6851
		// Start offset: 0x8004E8FC
		// Variables:
	// 		int radius; // $s1
	// 		int deg; // $s0
	// 		int n; // $s3
	// 		int pntx; // stack offset -48
	// 		int pnty; // stack offset -44
	// 		int px; // stack offset -40
	// 		int py; // stack offset -36
	// 		int mx; // stack offset -32
	// 		int my; // stack offset -28
	/* end block 1 */
	// End offset: 0x8004EA44
	// End Line: 6906

	/* begin block 2 */
		// Start line: 16652
	/* end block 2 */
	// End Line: 16653

/* WARNING: Could not reconcile some variable overlaps */

void FX_CalcSpiral(int degchange)

{
  uint deg;
  int radius;
  int iVar1;
  uint uVar2;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  radius = 0x2000;
  deg = 0;
  FX_GetSpiralPoint(0x2000,0,&local_30,&local_2c);
  uVar2 = 0;
  DVECTOR_800d270c.vx = (short)local_30;
  DVECTOR_800d270c.vy = (short)local_2c;
  iVar1 = 0;
  do {
    if (Spiral_Number == 0) {
      if ((uVar2 & 7) == 0) {
        radius = radius + 0x2200;
      }
    }
    else {
      radius = radius + 0x440;
    }
    deg = deg + degchange & 0xfff;
    FX_GetSpiralPoint(radius,deg,&local_30,&local_2c);
    *(undefined2 *)((int)&Spiral_Array.vx + iVar1) = (short)local_30;
    *(undefined2 *)((int)&Spiral_Array.vy + iVar1) = (short)local_2c;
    if ((int)uVar2 < 0x3f) {
      FX_GetSpiralPoint(radius + 0x1c00,deg,&local_28,&local_24);
      FX_GetSpiralPoint(radius + -0x1c00,deg,&local_20,&local_1c);
    }
    else {
      local_28 = local_30;
      local_24 = local_2c;
      local_20 = local_30;
      local_1c = local_2c;
    }
    uVar2 = uVar2 + 1;
    *(undefined2 *)((int)&Spiral_OffsetP.vx + iVar1) = (undefined2)local_28;
    *(undefined2 *)((int)&Spiral_OffsetP.vy + iVar1) = (undefined2)local_24;
    *(undefined2 *)((int)&Spiral_OffsetM.vx + iVar1) = (undefined2)local_20;
    *(undefined2 *)((int)&Spiral_OffsetM.vy + iVar1) = (undefined2)local_1c;
    iVar1 = iVar1 + 4;
  } while ((int)uVar2 < 0x40);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Spiral(struct _PrimPool *primPool /*stack 0*/, unsigned long **ot /*stack 4*/)
 // line 6923, offset 0x8004ea64
	/* begin block 1 */
		// Start line: 6924
		// Start offset: 0x8004EA64
		// Variables:
	// 		struct _POLY_2G4 *poly; // $s2
	// 		long prev; // $s3
	// 		long offp; // $s7
	// 		long offm; // $s5
	// 		int n; // $s1
	// 		struct DR_TPAGE *drtpage; // $v0
	// 		int health; // $s4
	// 		int health_mod; // $t0
	// 		long no_color; // stack offset -56
	// 		long color; // stack offset -60
	// 		static short cnt; // offset 0x68
	// 		int current_cnt; // stack offset -52
	// 		int max64; // $a0
	// 		long SPIRAL_COLOR; // stack offset -80
	// 		long SPIRAL_COLOR2; // stack offset -72
	// 		long SPIRAL_COLOR3; // stack offset -68
	// 		long SPIRAL_COLOR_END; // stack offset -64
	// 		long SPIRAL_NOCOLOR; // $a3

		/* begin block 1.1 */
			// Start line: 6973
			// Start offset: 0x8004EAD8
			// Variables:
		// 		int num; // $s0
		// 		long Spiral_Glow_Color; // stack offset -88
		// 		long Spiral_Glow_Color2; // stack offset -84
		// 		long black; // stack offset -76
		/* end block 1.1 */
		// End offset: 0x8004EBE0
		// End Line: 7003

		/* begin block 1.2 */
			// Start line: 7085
			// Start offset: 0x8004ED60
			// Variables:
		// 		int tmp; // $v1
		/* end block 1.2 */
		// End offset: 0x8004EDC8
		// End Line: 7099

		/* begin block 1.3 */
			// Start line: 7182
			// Start offset: 0x8004EF14
			// Variables:
		// 		static short deg; // offset 0x6a
		// 		struct _Vector f1; // stack offset -104
		/* end block 1.3 */
		// End offset: 0x8004EF68
		// End Line: 7197
	/* end block 1 */
	// End offset: 0x8004EF68
	// End Line: 7203

	/* begin block 2 */
		// Start line: 16973
	/* end block 2 */
	// End Line: 16974

/* WARNING: Removing unreachable block (ram,0x8004ed78) */

void FX_Spiral(_PrimPool *primPool,ulong **ot)

{
  short sVar1;
  uint angle;
  long lVar2;
  int currentHealth;
  DVECTOR *pDVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  DVECTOR DVar7;
  int iVar8;
  DVECTOR DVar9;
  DVECTOR DVar10;
  _Vector local_68;
  int local_58;
  long local_54;
  DVECTOR local_50;
  undefined4 local_4c;
  DVECTOR local_48;
  DVECTOR local_44;
  DVECTOR local_40;
  DVECTOR local_3c;
  DVECTOR local_38;
  int local_34;
  int local_30;
  
  local_3c = (DVECTOR)0x3a002a15;
  local_50 = (DVECTOR)0x3afffcd3;
  local_48 = (DVECTOR)0x3ae0dcba;
  local_44 = (DVECTOR)0x3ac0bb9d;
  local_40 = (DVECTOR)0x3a483017;
  if (Spiral_Number == 0) {
    local_4c = 0;
    currentHealth = Spiral_Current / 0x411a;
    local_58 = FX_GetHealthColor(currentHealth);
    if (currentHealth < 6) {
      iVar8 = ((Spiral_Current + currentHealth * -0x411a) * 0x1000) / 0x411a;
      if (0x1000 < iVar8) {
        iVar8 = 0x1000;
      }
      local_54 = FX_GetHealthColor(currentHealth + 1);
      LoadAverageCol((byte *)&local_58,(byte *)&local_54,0x1000 - iVar8,iVar8,(undefined *)&local_58
                    );
    }
    if (Spiral_Current == Spiral_Max) {
      DAT_800cf178 = DAT_800cf178 + 1;
      if (0x50 < DAT_800cf178) {
        DAT_800cf178 = 0;
      }
      local_50 = (DVECTOR)0x3afffcd3;
    }
    else {
      local_50 = (DVECTOR)(local_58 << 1 | 0x3a000000);
    }
    LoadAverageCol((byte *)&local_50,(byte *)&local_4c,0xe18,0x1e8,(undefined *)&local_48);
    local_48 = (DVECTOR)((uint)local_48 & 0xffffff | 0x3a000000);
    LoadAverageCol((byte *)&local_50,(byte *)&local_4c,0xc00,0x400,(undefined *)&local_44);
    local_44 = (DVECTOR)((uint)local_44 & 0xffffff | 0x3a000000);
    LoadAverageCol((byte *)&local_50,(byte *)&local_4c,0x461,0xb9f,(undefined *)&local_40);
    local_3c = (DVECTOR)0x3a00150b;
    local_40 = (DVECTOR)((uint)local_40 & 0xffffff | 0x3a000000);
  }
  else {
    DAT_800cf178 = DAT_800cf178 + 1;
    if (0x50 < DAT_800cf178) {
      DAT_800cf178 = 0;
    }
  }
  lVar2 = Spiral_Max;
  if (Spiral_Max < 0) {
    lVar2 = Spiral_Max + 0x3f;
  }
  currentHealth = lVar2 >> 6;
  iVar8 = Spiral_Current / currentHealth;
  puVar5 = primPool->nextPrim;
  currentHealth = ((Spiral_Current - iVar8 * currentHealth) * 0x1000) / currentHealth;
  if (puVar5 + 0x451 < primPool->lastPrim) {
    iVar4 = 0;
    local_34 = (int)DAT_800cf178;
    pDVar3 = (DVECTOR *)(puVar5 + 0x10);
    DVar7 = DVECTOR_800d270c;
    DVar9 = DVECTOR_800d270c;
    DVar10 = DVECTOR_800d270c;
    local_38 = local_3c;
    do {
      puVar6 = puVar5;
      pDVar3[-0xb] = local_3c;
      pDVar3[-7] = local_3c;
      if (iVar8 < iVar4) {
        local_3c = local_38;
      }
      else {
        angle = (int)(iVar4 + local_34 & 0xfU) >> 2;
        if (angle == 1) {
LAB_8004edbc:
          local_3c = local_48;
        }
        else {
          if (1 < angle) {
            if (angle == 2) {
              local_3c = local_44;
              goto LAB_8004edc8;
            }
            if (angle == 3) goto LAB_8004edbc;
          }
          local_3c = local_50;
        }
      }
LAB_8004edc8:
      if (iVar4 == iVar8) {
        local_30 = currentHealth;
        LoadAverageCol((byte *)&local_3c,(byte *)&local_38,currentHealth,0x1000 - currentHealth,
                       (undefined *)&local_3c);
        local_3c = (DVECTOR)((uint)local_3c & 0xffffff | (uint)local_50 & 0xff000000);
        currentHealth = local_30;
      }
      pDVar3[-0xf] = local_40;
      pDVar3[-0xd] = local_40;
      pDVar3[-3] = local_40;
      pDVar3[-1] = local_40;
      pDVar3[-6] = DVar7;
      pDVar3[-10] = DVar7;
      pDVar3[-0xe] = DVar10;
      pDVar3[-2] = DVar9;
      pDVar3[-9] = local_3c;
      pDVar3[-5] = local_3c;
      DVar7 = (&Spiral_Array)[iVar4];
      DVar10 = (&Spiral_OffsetP)[iVar4];
      DVar9 = (&Spiral_OffsetM)[iVar4];
      iVar4 = iVar4 + 1;
      pDVar3[-4] = DVar7;
      pDVar3[-8] = DVar7;
      pDVar3[-0xc] = DVar10;
      *pDVar3 = DVar9;
      pDVar3 = pDVar3 + 0x11;
      *puVar6 = (uint)ot[1] & 0xffffff | 0x10000000;
      ot[1] = (ulong *)((uint)puVar6 & 0xffffff);
      puVar5 = puVar6 + 0x11;
    } while (iVar4 < 0x40);
    puVar6[0x12] = 0xe1000620;
    sVar1 = Spiral_Number;
    *puVar5 = (uint)ot[1] & 0xffffff | 0x1000000;
    ot[1] = (ulong *)((uint)puVar5 & 0xffffff);
    primPool->nextPrim = puVar6 + 0x13;
    if ((sVar1 != 0) || (Spiral_Current == Spiral_Max)) {
      local_68.x = 0x1b6;
      local_68.y = 0xcb;
      angle = (uint)DAT_800cf17a - 0x40 & 0xfff;
      DAT_800cf17a = (ushort)angle;
      DRAW_CreateAGlowingCircle(&local_68,0x140,gameTrackerX.primPool,ot,5,0xa00000,0x20,0x20,angle)
      ;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Health_Spiral(int number /*$a0*/, int current_health /*$s0*/, int max_health /*$s1*/)
 // line 7205, offset 0x8004ef98
	/* begin block 1 */
		// Start line: 7206
		// Start offset: 0x8004EF98
		// Variables:
	// 		int degchange; // $v1
	/* end block 1 */
	// End offset: 0x8004F06C
	// End Line: 7237

	/* begin block 2 */
		// Start line: 17841
	/* end block 2 */
	// End Line: 17842

void FX_Health_Spiral(int number,int current_health,int max_health)

{
  bool bVar1;
  short sVar2;
  
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
    if (Spiral_Degrees <= sVar2) goto LAB_8004f060;
    bVar1 = (short)(Spiral_Degrees + -4) < sVar2;
    Spiral_Degrees = Spiral_Degrees + -4;
  }
  if (bVar1) {
    Spiral_Degrees = sVar2;
  }
LAB_8004f060:
  FX_CalcSpiral((int)Spiral_Degrees);
  Spiral_Current = current_health;
  Spiral_Max = max_health;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Spiral_Init()
 // line 7241, offset 0x8004f088
	/* begin block 1 */
		// Start line: 17916
	/* end block 1 */
	// End Line: 17917

/* WARNING: Unknown calling convention yet parameter storage is locked */

void FX_Spiral_Init(void)

{
  Spiral_Max = 100000;
  Spiral_Current = 100000;
  Spiral_Number = 3;
  Spiral_Degrees = 0xe0;
  FX_CalcSpiral(0xe0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawModel(struct Object *object /*$s6*/, int model_num /*$s7*/, struct _SVector *rotation /*$s0*/, struct _SVector *position /*$s1*/, struct _SVector *offset /*stack 16*/, int transflag /*stack 20*/)
 // line 7269, offset 0x8004f0c8
	/* begin block 1 */
		// Start line: 7270
		// Start offset: 0x8004F0C8
		// Variables:
	// 		struct _Model *model; // $v0
	// 		struct _MFace *mface; // $t1
	// 		struct _MVertex *vertexList; // $t3
	// 		struct TextureMT3 *texture; // $a1
	// 		struct MATRIX matrix; // stack offset -88
	// 		int i; // $t0
	// 		struct POLY_GT3 *poly; // $s4
	// 		unsigned long **drawot; // $s5
	// 		struct _SVector output; // stack offset -56
	// 		long color; // $t2

		/* begin block 1.1 */
			// Start line: 7314
			// Start offset: 0x8004F220
			// Variables:
		// 		long clip; // stack offset -48
		/* end block 1.1 */
		// End offset: 0x8004F2EC
		// End Line: 7335
	/* end block 1 */
	// End offset: 0x8004F308
	// End Line: 7342

	/* begin block 2 */
		// Start line: 17978
	/* end block 2 */
	// End Line: 17979

	/* begin block 3 */
		// Start line: 17990
	/* end block 3 */
	// End Line: 17991

void FX_DrawModel(Object *object,int model_num,_SVector *rotation,_SVector *position,
                 _SVector *offset,int transflag)

{
  ulong uVar1;
  long lVar2;
  undefined4 in_zero;
  undefined4 in_at;
  _Model *p_Var3;
  _MVertex *p_Var4;
  uint uVar5;
  _MVertex *p_Var6;
  _MVertex *p_Var7;
  ulong *puVar8;
  ulong *puVar9;
  ushort *puVar10;
  int iVar11;
  _MFace *p_Var12;
  ulong uVar13;
  _MVertex *p_Var14;
  ulong *puVar15;
  MATRIX MStack88;
  short local_38;
  short local_36;
  short local_34;
  int local_30;
  
  lVar2 = gameTrackerX.defVVRemoveDist;
  puVar15 = (gameTrackerX.primPool)->nextPrim;
  PushMatrix();
  MATH3D_SetUnityMatrix(&MStack88);
  RotMatrixX((int)rotation->x,(int)&MStack88);
  RotMatrixY((int)rotation->y,(short *)&MStack88);
  RotMatrixZ((int)rotation->z,(short *)&MStack88);
  PIPE3D_AspectAdjustMatrix(&MStack88);
  ApplyMatrixSV(&MStack88,offset,&local_38);
  MStack88.t[0] = (int)position->x + (int)local_38;
  MStack88.t[1] = (int)position->y + (int)local_36;
  MStack88.t[2] = (int)position->z + (int)local_34;
  SetRotMatrix((undefined4 *)&MStack88);
  SetTransMatrix((int)&MStack88);
  uVar13 = 0x34808080;
  if (transflag != 0) {
    uVar13 = 0x36404040;
  }
  if (object != (Object *)0x0) {
    if ((gameTrackerX.primPool)->lastPrim <= puVar15 + 10) {
      return;
    }
    p_Var3 = object->modelList[model_num];
    p_Var12 = p_Var3->faceList;
    p_Var14 = p_Var3->vertexList;
    iVar11 = p_Var3->numFaces + -1;
    if (iVar11 != -1) {
      puVar10 = &(p_Var12->face).v2;
      puVar9 = puVar15 + 8;
      do {
        puVar8 = *(ulong **)(puVar10 + 2);
        p_Var7 = p_Var14 + (p_Var12->face)._2;
        p_Var6 = p_Var14 + puVar10[-1];
        p_Var4 = p_Var14 + *puVar10;
        setCopReg(2,in_zero,*(undefined4 *)&p_Var7->vertex);
        setCopReg(2,in_at,*(undefined4 *)&(p_Var7->vertex).z);
        setCopReg(2,p_Var4,*(undefined4 *)&p_Var6->vertex);
        setCopReg(2,p_Var6,*(undefined4 *)&(p_Var6->vertex).z);
        setCopReg(2,p_Var7,*(undefined4 *)&p_Var4->vertex);
        setCopReg(2,puVar8,*(undefined4 *)&(p_Var4->vertex).z);
        copFunction(2,0x280030);
        puVar9[-5] = *puVar8;
        puVar9[-2] = puVar8[1];
        puVar9[1] = puVar8[2];
        copFunction(2,0x1400006);
        puVar9[-1] = uVar13;
        puVar9[-4] = uVar13;
        puVar9[-7] = uVar13;
        local_30 = getCopReg(2,0x18);
        if (local_30 < 0) {
          uVar1 = getCopReg(2,0xc);
          puVar15[2] = uVar1;
          uVar1 = getCopReg(2,0xd);
          puVar15[5] = uVar1;
          uVar1 = getCopReg(2,0xe);
          *puVar9 = uVar1;
          puVar9 = puVar9 + 10;
          *puVar15 = *(uint *)(lVar2 + 4) & 0xffffff | 0x9000000;
          uVar5 = (uint)puVar15 & 0xffffff;
          puVar15 = puVar15 + 10;
          *(uint *)(lVar2 + 4) = uVar5;
        }
        puVar10 = puVar10 + 6;
        iVar11 = iVar11 + -1;
        p_Var12 = p_Var12 + 1;
      } while (iVar11 != -1);
    }
  }
  (gameTrackerX.primPool)->nextPrim = puVar15;
  PopMatrix();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ fx_calc_points(struct _SVector *points /*$s1*/, int degrees /*$s0*/, int radius /*$s3*/, int radius2 /*$s4*/, int radius3 /*stack 16*/)
 // line 7356, offset 0x8004f334
	/* begin block 1 */
		// Start line: 7357
		// Start offset: 0x8004F334
		// Variables:
	// 		int cosval; // $s0
	// 		int sinval; // $v0
	/* end block 1 */
	// End offset: 0x8004F334
	// End Line: 7357

	/* begin block 2 */
		// Start line: 18182
	/* end block 2 */
	// End Line: 18183

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
 // line 7374, offset 0x8004f444
	/* begin block 1 */
		// Start line: 7375
		// Start offset: 0x8004F444
		// Variables:
	// 		struct MATRIX tmpmat; // stack offset -40
	/* end block 1 */
	// End offset: 0x8004F48C
	// End Line: 7383

	/* begin block 2 */
		// Start line: 18225
	/* end block 2 */
	// End Line: 18226

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
 // line 7386, offset 0x8004f49c
	/* begin block 1 */
		// Start line: 7387
		// Start offset: 0x8004F49C
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
	// End offset: 0x8004F718
	// End Line: 7463

	/* begin block 2 */
		// Start line: 18250
	/* end block 2 */
	// End Line: 18251

	/* begin block 3 */
		// Start line: 18260
	/* end block 3 */
	// End Line: 18261

void FX_DrawRing(MATRIX *wcTransform,_SVector *position,MATRIX *matrix,int radius,int radius2,
                int radius3,int z1,int z2,int z3,long color,int sortInWorld)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  ulong *puVar5;
  ulong *puVar6;
  uint uVar7;
  int iVar8;
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
  long local_2c;
  
  puVar6 = (gameTrackerX.primPool)->nextPrim;
  local_2c = gameTrackerX.defVVRemoveDist;
  if (puVar6 + 0x240 < (gameTrackerX.primPool)->lastPrim) {
    PushMatrix();
    SetRotMatrix((undefined4 *)wcTransform);
    SetTransMatrix((int)wcTransform);
    lVar1 = fx_get_startz(position);
    SetRotMatrix((undefined4 *)matrix);
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
    (gameTrackerX.primPool)->nextPrim = puVar6;
    PopMatrix();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ fx_setTex(struct DVECTOR *x /*$a0*/, unsigned char *uv /*$a1*/, int tx /*$a2*/, int offset /*$a3*/)
 // line 7465, offset 0x8004f748
	/* begin block 1 */
		// Start line: 18477
	/* end block 1 */
	// End Line: 18478

	/* begin block 2 */
		// Start line: 18478
	/* end block 2 */
	// End Line: 18479

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
 // line 7474, offset 0x8004f78c
	/* begin block 1 */
		// Start line: 7475
		// Start offset: 0x8004F78C
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
	// End offset: 0x8004FAF0
	// End Line: 7561

	/* begin block 2 */
		// Start line: 18495
	/* end block 2 */
	// End Line: 18496

	/* begin block 3 */
		// Start line: 18506
	/* end block 3 */
	// End Line: 18507

/* WARNING: Could not reconcile some variable overlaps */

void FX_DrawRing2(MATRIX *wcTransform,_SVector *position,MATRIX *matrix,int radius,int radius2,
                 int radius3,int z1,int z2,int z3,long offset,int sortInWorld)

{
  ushort uVar1;
  bool bVar2;
  ushort uVar3;
  long lVar4;
  int tx;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  ulong *uv;
  ulong *puVar8;
  int iVar9;
  uint uVar10;
  int degrees;
  _SVector _Stack104;
  undefined2 local_5c;
  undefined2 local_54;
  ulong local_50;
  undefined4 local_4c;
  ulong local_48;
  int local_40;
  undefined4 local_3c;
  int local_38;
  long local_34;
  uint local_30;
  
  puVar8 = (gameTrackerX.primPool)->nextPrim;
  local_34 = gameTrackerX.defVVRemoveDist;
  if (puVar8 + 0x140 < (gameTrackerX.primPool)->lastPrim) {
    PushMatrix();
    SetRotMatrix((undefined4 *)wcTransform);
    SetTransMatrix((int)wcTransform);
    lVar4 = fx_get_startz(position);
    SetRotMatrix((undefined4 *)matrix);
    _Stack104.z = (short)z1;
    local_5c = (undefined2)z2;
    uVar7 = (gameTrackerX.gameData.asmData.dispPage ^ 1U) << 8;
    local_54 = (undefined2)z3;
    fx_calc_points(&_Stack104,0,radius,radius2,radius3);
    local_50 = getCopReg(2,0xc);
    local_4c = getCopReg(2,0xd);
    local_48 = getCopReg(2,0xe);
    iVar9 = 0;
    uVar10 = (int)(uVar7 & 0x100) >> 4;
    uVar7 = (uVar7 & 0x200) << 2;
    local_30 = uVar10 | 0x100 | uVar7;
    uv = puVar8 + 9;
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
          uVar3 = (ushort)((int)(tx + 0x400U & 0x3ff) >> 6);
        }
        else {
          uVar3 = (ushort)(((uint)uVar1 & 0x3c0) >> 6);
        }
        *(ushort *)((int)uv + -0xe) = (ushort)uVar10 | uVar3 | 0x100 | (ushort)uVar7;
      }
      tx = (int)(short)(uVar1 & 0xffc0);
      fx_setTex((DVECTOR *)(puVar8 + 2),(uchar *)(puVar8 + 3),tx,offset);
      fx_setTex((DVECTOR *)(puVar8 + 4),(uchar *)(puVar8 + 5),tx,offset);
      fx_setTex((DVECTOR *)(puVar8 + 6),(uchar *)(puVar8 + 7),tx,offset);
      fx_setTex((DVECTOR *)(puVar8 + 8),(uchar *)uv,tx,offset);
      if (local_38 < local_40) {
        local_40 = local_38;
      }
      if (local_40 < 0) {
        local_40 = local_40 + 3;
      }
      local_40 = local_40 >> 2;
      if (0 < local_40) {
        bVar2 = local_40 <= lVar4;
        if ((sortInWorld == 0) && (local_40 = lVar4 + 0x10, bVar2)) {
          local_40 = 1;
        }
        if (local_40 - 1U < 0xbff) {
          uv = uv + 10;
          puVar5 = (uint *)(local_40 * 4 + local_34);
          uVar6 = (uint)puVar8 & 0xffffff;
          *puVar8 = *puVar5 & 0xffffff | 0x9000000;
          puVar8 = puVar8 + 10;
          *puVar5 = uVar6;
        }
      }
      iVar9 = iVar9 + 1;
      degrees = degrees + 0x80;
    } while (iVar9 < 0x20);
    (gameTrackerX.primPool)->nextPrim = puVar8;
    PopMatrix();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawFField(struct MATRIX *wcTransform /*$s2*/, struct _FXForceFieldEffect *field /*$s0*/)
 // line 7585, offset 0x8004fb20
	/* begin block 1 */
		// Start line: 7586
		// Start offset: 0x8004FB20
		// Variables:
	// 		struct _Instance *instance; // $a0
	// 		struct MATRIX tmpmat; // stack offset -64
	// 		struct _SVector position; // stack offset -32
	// 		int size; // $s1
	// 		short fade; // $v0
	// 		long color; // stack offset -20
	// 		long black; // stack offset -24
	/* end block 1 */
	// End offset: 0x8004FCD8
	// End Line: 7632

	/* begin block 2 */
		// Start line: 18802
	/* end block 2 */
	// End Line: 18803

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
    iVar5 = (uint)(ushort)field->end_fade - 0x80;
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
  RotMatrixZ(0x400,(short *)&MStack64);
  RotMatrixX((int)theCamera.core.rotation.x,(int)&MStack64);
  FX_DrawRing(wcTransform,&local_20,&MStack64,(int)field->size - iVar3,(int)field->size,
              field->size - iVar3,0,0,0,local_14,0);
  return;
}



// decompiled code
// original method signature: 
// struct _FXForceFieldEffect * /*$ra*/ FX_StartFField(struct _Instance *instance /*$s2*/, int size /*$s3*/, struct _Position *offset /*$s1*/, int size_diff /*$s4*/, int size_change /*stack 16*/, int deg_change /*stack 20*/, long color /*stack 24*/)
 // line 7634, offset 0x8004fcf0
	/* begin block 1 */
		// Start line: 7635
		// Start offset: 0x8004FCF0
		// Variables:
	// 		struct _FXForceFieldEffect *field; // $s0

		/* begin block 1.1 */
			// Start line: 7640
			// Start offset: 0x8004FD34
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a1
		// 		struct _SVector *_v0; // $v0
		/* end block 1.1 */
		// End offset: 0x8004FD34
		// End Line: 7640
	/* end block 1 */
	// End offset: 0x8004FDA0
	// End Line: 7658

	/* begin block 2 */
		// Start line: 18911
	/* end block 2 */
	// End Line: 18912

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
 // line 7661, offset 0x8004fdc4
	/* begin block 1 */
		// Start line: 7663
		// Start offset: 0x8004FDC4
		// Variables:
	// 		struct _FXGeneralEffect *currentEffect; // $v1
	/* end block 1 */
	// End offset: 0x8004FE0C
	// End Line: 7674

	/* begin block 2 */
		// Start line: 18972
	/* end block 2 */
	// End Line: 18973

	/* begin block 3 */
		// Start line: 18973
	/* end block 3 */
	// End Line: 18974

void FX_EndFField(_Instance *instance)

{
  _FXGeneralEffect **pp_Var1;
  _FXGeneralEffect *p_Var2;
  
  p_Var2 = FX_GeneralEffectTracker;
  if (FX_GeneralEffectTracker != (_FXGeneralEffect *)0x0) {
    do {
      if ((p_Var2->instance == instance) && (p_Var2->effectType == -0x7a)) {
        *(undefined2 *)&p_Var2[2].continue_process = 0x1000;
      }
      pp_Var1 = (_FXGeneralEffect **)&p_Var2->next;
      p_Var2 = *pp_Var1;
    } while (*pp_Var1 != (_FXGeneralEffect *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Draw_Glowing_Line(unsigned long **ot /*$t6*/, long otz /*$a0*/, struct DVECTOR *sxy0 /*$a2*/, struct DVECTOR *sxy1 /*$a3*/, struct DVECTOR *xy0 /*stack 16*/, struct DVECTOR *xy1 /*stack 20*/, long color /*stack 24*/, long color2 /*stack 28*/)
 // line 7676, offset 0x8004fe14
	/* begin block 1 */
		// Start line: 7677
		// Start offset: 0x8004FE14
		// Variables:
	// 		struct _POLY_2G4T *poly; // $t0
	// 		struct _PrimPool *primPool; // $t2
	// 		int negflag; // $t5
	/* end block 1 */
	// End offset: 0x8004FFA8
	// End Line: 7721

	/* begin block 2 */
		// Start line: 19002
	/* end block 2 */
	// End Line: 19003

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
 // line 7724, offset 0x8004ffb0
	/* begin block 1 */
		// Start line: 7725
		// Start offset: 0x8004FFB0
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
			// Start line: 7759
			// Start offset: 0x80050064
			// Variables:
		// 		struct SVECTOR point; // stack offset -64

			/* begin block 1.1.1 */
				// Start line: 7767
				// Start offset: 0x800500B4
				// Variables:
			// 		int rsin_n4; // $s0
			/* end block 1.1.1 */
			// End offset: 0x800501A0
			// End Line: 7771

			/* begin block 1.1.2 */
				// Start line: 7775
				// Start offset: 0x800501B0
				// Variables:
			// 		int tmpdeg; // $s1
			/* end block 1.1.2 */
			// End offset: 0x80050278
			// End Line: 7779

			/* begin block 1.1.3 */
				// Start line: 7793
				// Start offset: 0x800502E0
				// Variables:
			// 		int fx; // $s2
			// 		int fy; // $s0
			/* end block 1.1.3 */
			// End offset: 0x80050328
			// End Line: 7801
		/* end block 1.1 */
		// End offset: 0x80050444
		// End Line: 7823
	/* end block 1 */
	// End offset: 0x80050470
	// End Line: 7832

	/* begin block 2 */
		// Start line: 19105
	/* end block 2 */
	// End Line: 19106

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
LAB_800501a0:
        if (mat != (MATRIX *)0x0) goto LAB_800501b0;
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
          goto LAB_800501a0;
        }
LAB_800501b0:
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
 // line 7837, offset 0x800504a0
	/* begin block 1 */
		// Start line: 7838
		// Start offset: 0x800504A0
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
			// Start line: 7897
			// Start offset: 0x800505E8
			// Variables:
		// 		struct SVECTOR point; // stack offset -88

			/* begin block 1.1.1 */
				// Start line: 7908
				// Start offset: 0x80050660
				// Variables:
			// 		int newlength; // $v1
			// 		int newfx; // $s1
			// 		int newfy; // $s0
			/* end block 1.1.1 */
			// End offset: 0x800506A4
			// End Line: 7922
		/* end block 1.1 */
		// End offset: 0x800506C4
		// End Line: 7929

		/* begin block 1.2 */
			// Start line: 7940
			// Start offset: 0x800506F8
			// Variables:
		// 		struct SVECTOR point; // stack offset -80

			/* begin block 1.2.1 */
				// Start line: 7962
				// Start offset: 0x800507E0
				// Variables:
			// 		int x; // $v0
			/* end block 1.2.1 */
			// End offset: 0x8005086C
			// End Line: 7974
		/* end block 1.2 */
		// End offset: 0x800508BC
		// End Line: 7983
	/* end block 1 */
	// End offset: 0x800508EC
	// End Line: 7993

	/* begin block 2 */
		// Start line: 19374
	/* end block 2 */
	// End Line: 19375

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
              goto LAB_800506a4;
            }
          }
          else {
LAB_800506a4:
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





