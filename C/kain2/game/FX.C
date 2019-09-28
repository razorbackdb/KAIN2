#include "THISDUST.H"
#include "FX.H"


// decompiled code
// original method signature: 
// void /*$ra*/ FX_Init(struct _FXTracker *fxTracker /*$s1*/)
 // line 120, offset 0x80041f54
	/* begin block 1 */
		// Start line: 121
		// Start offset: 0x80041F54
		// Variables:
	// 		struct _FX_MATRIX *fxMatrix; // $s0
	// 		struct _FX_MATRIX *endFXMatrix; // $s2
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct _FX_PRIM *endFXPrim; // $s2
	/* end block 1 */
	// End offset: 0x80041FEC
	// End Line: 147

	/* begin block 2 */
		// Start line: 240
	/* end block 2 */
	// End Line: 241

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  _FX_LastUsedPrim = 0;
  _FX_ConstrictPositionPtr = &FX_ConstrictPosition;
  FX_CalcSpiral((int)&fxTracker->freePrimList);
  snow_amount = 0;
  rain_amount = 0;
  current_rain_fade = 0;
  FX_reaver_instance = (_Instance *)0x0;
  _FX_Frames = 1;
  _FX_TimeCount = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Die(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$s1*/)
 // line 191, offset 0x80042034
	/* begin block 1 */
		// Start line: 382
	/* end block 1 */
	// End Line: 383

	/* begin block 2 */
		// Start line: 431
	/* end block 2 */
	// End Line: 432

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FX_Die(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  if ((_FX_LastUsedPrim == fxPrim) &&
     (_FX_LastUsedPrim = (_FX_PRIM *)(fxPrim->node).prev,
     (_FX_LastUsedPrim->node).prev == (NodeType *)0x0)) {
    _FX_LastUsedPrim = (_FX_PRIM *)0x0;
  }
  fxPrim->flags = fxPrim->flags | 0x10;
  LIST_DeleteFunc((NodeType *)fxPrim);
  LIST_InsertFunc(&fxTracker->freePrimList,(NodeType *)fxPrim);
  return;
}



// decompiled code
// original method signature: 
// struct _FX_MATRIX * /*$ra*/ FX_GetMatrix(struct _FXTracker *fxTracker /*$s1*/)
 // line 208, offset 0x800420a4
	/* begin block 1 */
		// Start line: 209
		// Start offset: 0x800420A4
		// Variables:
	// 		struct _FX_MATRIX *fxMatrix; // $s0
	/* end block 1 */
	// End offset: 0x800420DC
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
 // line 222, offset 0x800420f4
	/* begin block 1 */
		// Start line: 223
		// Start offset: 0x800420F4
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $a0
	/* end block 1 */
	// End offset: 0x80042154
	// End Line: 244

	/* begin block 2 */
		// Start line: 496
	/* end block 2 */
	// End Line: 497

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_FX_PRIM * FX_GetPrim(_FXTracker *fxTracker)

{
  NodeType *pNVar1;
  _FX_PRIM *p_Var2;
  _FX_PRIM *p_Var3;
  
  p_Var3 = (_FX_PRIM *)LIST_GetFunc(&fxTracker->freePrimList);
  p_Var2 = _FX_LastUsedPrim;
  if (p_Var3 == (_FX_PRIM *)0x0) {
    if (_FX_LastUsedPrim != (_FX_PRIM *)0x0) {
      _FX_LastUsedPrim = (_FX_PRIM *)(_FX_LastUsedPrim->node).prev;
      pNVar1 = &_FX_LastUsedPrim->node;
      (_FX_LastUsedPrim->node).next = (NodeType *)0x0;
      p_Var3 = p_Var2;
      if (pNVar1->prev == (NodeType *)0x0) {
        _FX_LastUsedPrim = (_FX_PRIM *)0x0;
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
 // line 247, offset 0x80042164
	/* begin block 1 */
		// Start line: 248
		// Start offset: 0x80042164
		// Variables:
	// 		struct _FXParticle *particle; // $v1
	/* end block 1 */
	// End offset: 0x800421E8
	// End Line: 268

	/* begin block 2 */
		// Start line: 549
	/* end block 2 */
	// End Line: 550

_FXParticle * FX_GetParticle(_Instance *instance,short startSegment)

{
                    /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(0x4c,'\r');
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_AniTexSetup(struct _FX_PRIM *fxPrim /*$a2*/, struct _MFace *mface /*$a1*/, struct _Model *model /*$a2*/, struct _FXTracker *fxTracker /*$a3*/)
 // line 271, offset 0x80042200
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
 // line 360, offset 0x8004227c
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
 // line 396, offset 0x8004229c
	/* begin block 1 */
		// Start line: 397
		// Start offset: 0x8004229C
		// Variables:
	// 		struct MATRIX matrix; // stack offset -64
	// 		struct _Rotation rotation; // stack offset -32
	// 		struct _Rotation rot_temp; // stack offset -24
	/* end block 1 */
	// End offset: 0x80042530
	// End Line: 445

	/* begin block 2 */
		// Start line: 870
	/* end block 2 */
	// End Line: 871

void FX_ShatterProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  undefined local_20 [16];
  
                    /* WARNING: Subroutine does not return */
  memset(local_20,0,8);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DFacadeProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 583, offset 0x80042544
	/* begin block 1 */
		// Start line: 584
		// Start offset: 0x80042544

		/* begin block 1.1 */
			// Start line: 596
			// Start offset: 0x8004259C
			// Variables:
		// 		struct MATRIX *swTransform; // $v1
		/* end block 1.1 */
		// End offset: 0x8004259C
		// End Line: 597

		/* begin block 1.2 */
			// Start line: 756
			// Start offset: 0x800426A8
			// Variables:
		// 		struct _Rotation rot; // stack offset -16
		/* end block 1.2 */
		// End offset: 0x80042708
		// End Line: 764
	/* end block 1 */
	// End offset: 0x80042708
	// End Line: 773

	/* begin block 2 */
		// Start line: 1166
	/* end block 2 */
	// End Line: 1167

void FX_DFacadeProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  
  if (0 < fxPrim->timeToLive) {
    fxPrim->timeToLive = fxPrim->timeToLive + -1;
  }
  if (fxPrim->timeToLive == 0) {
    FX_Die(fxPrim,fxTracker);
  }
  else {
    if ((fxPrim->flags & 0x20U) == 0) {
      if ((fxPrim->flags & 2U) == 0) {
        sVar1 = *(short *)((int)&fxPrim->duo + 8);
        sVar5 = *(short *)((int)&fxPrim->duo + 10);
        *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + *(short *)((int)&fxPrim->duo + 6);
        *(short *)((int)&fxPrim->duo + 2) = *(short *)((int)&fxPrim->duo + 2) + sVar1;
        sVar1 = (fxPrim->position).x;
        sVar2 = *(short *)&fxPrim->duo;
        *(short *)((int)&fxPrim->duo + 4) = *(short *)((int)&fxPrim->duo + 4) + sVar5;
        (fxPrim->position).y = (fxPrim->position).y + *(short *)((int)&fxPrim->duo + 2);
        sVar5 = *(short *)((int)&fxPrim->duo + 4);
        (fxPrim->position).x = sVar1 + sVar2;
        uVar4 = fxPrim->flags;
        sVar5 = (fxPrim->position).z + sVar5;
        (fxPrim->position).z = sVar5;
        if (((uVar4 & 0x100) != 0) && (sVar5 <= fxPrim->work0)) {
          uVar4 = fxPrim->flags;
          (fxPrim->position).z = fxPrim->work0;
          fxPrim->flags = uVar4 | 2;
        }
      }
    }
    else {
      iVar3 = *(int *)(*(int *)&fxPrim->duo + 0x40) + *(int *)((int)&fxPrim->duo + 4) * 0x20;
      (fxPrim->position).x = *(short *)(iVar3 + 0x14);
      (fxPrim->position).y = *(short *)(iVar3 + 0x18);
      (fxPrim->position).z = *(short *)(iVar3 + 0x1c);
    }
    uVar4 = fxPrim->matrix->flags;
    if (((uVar4 & 2) == 0) && (fxPrim->matrix->flags = uVar4 | 2, (fxPrim->flags & 0x80U) != 0)) {
                    /* WARNING: Subroutine does not return */
      RotMatrixX((int)*(char *)((int)&fxPrim->work2 + 1) << 2,(int)&fxPrim->matrix->lwTransform);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// struct _FX_PRIM * /*$ra*/ _FX_BuildSingleFaceWithModel(struct _Model *model /*$a0*/, struct _MFace *mface /*$s6*/, struct SVECTOR *center /*$s7*/, struct SVECTOR *vel /*$fp*/, struct SVECTOR *accl /*stack 16*/, struct _FXTracker *fxTracker /*stack 20*/, TDRFuncPtr__FX_BuildSingleFaceWithModel6fxSetup fxSetup /*stack 24*/, TDRFuncPtr__FX_BuildSingleFaceWithModel7fxProcess fxProcess /*stack 28*/, struct _FX_MATRIX *fxMatrix /*stack 32*/, int timeToLive /*stack 36*/)
 // line 856, offset 0x80042718
	/* begin block 1 */
		// Start line: 857
		// Start offset: 0x80042718
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s1
	// 		struct _MVertex *vertexList; // $s3
	/* end block 1 */
	// End offset: 0x800427E0
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
 // line 890, offset 0x80042814
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
 // line 917, offset 0x80042864
	/* begin block 1 */
		// Start line: 918
		// Start offset: 0x80042864
		// Variables:
	// 		struct MATRIX lm; // stack offset -40
	/* end block 1 */
	// End offset: 0x80042864
	// End Line: 918

	/* begin block 2 */
		// Start line: 1834
	/* end block 2 */
	// End Line: 1835

void _FX_SetupLighting(_Instance *instance)

{
  MATRIX MStack40;
  
                    /* WARNING: Subroutine does not return */
  LIGHT_PresetInstanceLight(instance,0x800,&MStack40);
}



// decompiled code
// original method signature: 
// long /*$ra*/ _FX_DoLighting(struct _MFace *mface /*$a0*/)
 // line 928, offset 0x800428b4
	/* begin block 1 */
		// Start line: 929
		// Start offset: 0x800428B4
		// Variables:
	// 		long modelDQP; // $a2
	// 		long color; // stack offset -8
	// 		struct TextureMT3 *texture; // $a1
	/* end block 1 */
	// End offset: 0x800429C0
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
      setCopReg(2,in_zero,(&DebugMenuLine_800c895c.bit_mask)[(uint)mface->normal * 2]);
      setCopReg(2,in_at,(&mcardMenu.type)[(uint)mface->normal * 2]);
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
      setCopReg(2,in_zero,(&DebugMenuLine_800c895c.bit_mask)[(uint)mface->normal * 2]);
      setCopReg(2,in_at,(&mcardMenu.type)[(uint)mface->normal * 2]);
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
 // line 976, offset 0x800429cc
	/* begin block 1 */
		// Start line: 977
		// Start offset: 0x800429CC
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
			// Start offset: 0x80042BBC
			// Variables:
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $a1
		// 		short _y1; // $a3
		// 		short _z1; // $a2
		// 		struct _SVector *_v; // stack offset -48
		// 		struct _Vector *_v1; // $a2
		/* end block 1.1 */
		// End offset: 0x80042BBC
		// End Line: 1059

		/* begin block 1.2 */
			// Start line: 1072
			// Start offset: 0x80042C50
		/* end block 1.2 */
		// End offset: 0x80042D10
		// End Line: 1083

		/* begin block 1.3 */
			// Start line: 1136
			// Start offset: 0x80043008
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
		// End offset: 0x80043008
		// End Line: 1136

		/* begin block 1.4 */
			// Start line: 1165
			// Start offset: 0x80043144
			// Variables:
		// 		struct TextureMT3 *texture; // $v1
		/* end block 1.4 */
		// End offset: 0x80043144
		// End Line: 1165

		/* begin block 1.5 */
			// Start line: 1195
			// Start offset: 0x80043210
		/* end block 1.5 */
		// End offset: 0x80043270
		// End Line: 1200

		/* begin block 1.6 */
			// Start line: 1217
			// Start offset: 0x800432E4
		/* end block 1.6 */
		// End offset: 0x8004332C
		// End Line: 1223
	/* end block 1 */
	// End offset: 0x80043420
	// End Line: 1243

	/* begin block 2 */
		// Start line: 1895
	/* end block 2 */
	// End Line: 1896

	/* begin block 3 */
		// Start line: 1925
	/* end block 3 */
	// End Line: 1926

void _FX_BuildSegmentedSplinters
               (_Instance *instance,SVECTOR *center,SVECTOR *vel,SVECTOR *accl,FXSplinter *splintDef
               ,_FXTracker *fxTracker,TDRFuncPtr__FX_BuildSegmentedSplinters6fxSetup fxSetup,
               TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess fxProcess,int shardFlags)

{
  undefined auStack240 [128];
  _Vector local_70 [2];
  undefined2 local_58;
  int local_50;
  _Model *local_44;
  _MVertex *local_40;
  long local_3c;
  long *local_38;
  
  local_3c = theCamera.core.vvPlaneConsts[1];
  local_38 = (long *)(&DAT_00001080 + theCamera.core.vvPlaneConsts[1]);
  local_44 = instance->object->modelList[instance->currentModel];
  local_58 = (undefined2)shardFlags;
  local_40 = local_44->vertexList;
  PIPE3D_TransformVerticesToWorld
            (instance,(_SVector *)theCamera.core.vvPlaneConsts[1],local_38,local_70);
  if (splintDef == (FXSplinter *)0x0) {
    local_50 = 0x20;
  }
  else {
    local_50 = (int)splintDef->lifetime;
  }
                    /* WARNING: Subroutine does not return */
  memset(auStack240,0xff,0x80);
}



// decompiled code
// original method signature: 
// void /*$ra*/ _FX_BuildNonSegmentedSplinters(struct _Instance *instance /*stack 0*/, struct SVECTOR *center /*stack 4*/, struct SVECTOR *vel /*stack 8*/, struct SVECTOR *accl /*stack 12*/, struct FXSplinter *splintDef /*stack 16*/, struct _FXTracker *fxTracker /*stack 20*/, TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup fxSetup /*stack 24*/, TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess fxProcess /*stack 28*/, int shardFlags /*stack 32*/)
 // line 1254, offset 0x80043450
	/* begin block 1 */
		// Start line: 1255
		// Start offset: 0x80043450
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
			// Start offset: 0x80043564
			// Variables:
		// 		short start; // $v0
		/* end block 1.1 */
		// End offset: 0x8004368C
		// End Line: 1322

		/* begin block 1.2 */
			// Start line: 1352
			// Start offset: 0x800437F8
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $s3
		// 		struct _SVector *_v1; // $a1
		/* end block 1.2 */
		// End offset: 0x800437F8
		// End Line: 1352

		/* begin block 1.3 */
			// Start line: 1414
			// Start offset: 0x80043BAC
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
		// End offset: 0x80043BAC
		// End Line: 1414

		/* begin block 1.4 */
			// Start line: 1443
			// Start offset: 0x80043CE8
			// Variables:
		// 		struct TextureMT3 *texture; // $v1
		/* end block 1.4 */
		// End offset: 0x80043CE8
		// End Line: 1443

		/* begin block 1.5 */
			// Start line: 1473
			// Start offset: 0x80043DA4
		/* end block 1.5 */
		// End offset: 0x80043DA4
		// End Line: 1473

		/* begin block 1.6 */
			// Start line: 1499
			// Start offset: 0x80043EF0
		/* end block 1.6 */
		// End offset: 0x80043F38
		// End Line: 1505
	/* end block 1 */
	// End offset: 0x8004400C
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
  long lVar1;
  short sVar2;
  _FX_MATRIX *p_Var3;
  int iVar4;
  uint uVar5;
  _FX_PRIM *fxPrim;
  uint uVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  ushort uVar12;
  short *psVar13;
  int iVar14;
  short *psVar15;
  _MFace *mface;
  short *psVar16;
  _MFace *p_Var17;
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
  undefined *local_6c [4];
  undefined *local_5c;
  uint local_58;
  undefined *local_54;
  ushort local_50;
  int local_48;
  int local_44;
  _MFace *local_40;
  _Model *local_3c;
  _MVertex *local_38;
  int local_34;
  short *local_30;
  
  lVar1 = theCamera.core.vvPlaneConsts[1];
  local_3c = instance->object->modelList[instance->currentModel];
  local_38 = local_3c->vertexList;
  mface = local_3c->faceList;
  local_70 = DAT_800ceb80;
  local_6c[0] = PTR_LAB_800ceb84;
  local_6c[1] = PTR_DAT_800ceb88;
  local_6c[2] = PTR_LAB_800ceb8c;
  local_6c[3] = PTR_DAT_800ceb90;
  local_5c = PTR_LAB_800ceb94;
  local_58 = DAT_800ceb98;
  local_54 = PTR_ARRAY_800ceb9c[0];
  local_50 = (ushort)shardFlags;
  PIPE3D_TransformVerticesToWorld
            (instance,(_SVector *)theCamera.core.vvPlaneConsts[1],
             (long *)(&DAT_00001080 + theCamera.core.vvPlaneConsts[1]),(_Vector *)&local_98);
  if (splintDef == (FXSplinter *)0x0) {
                    /* WARNING: Subroutine does not return */
    rand();
  }
  uVar12 = splintDef->chunkVelXY - splintDef->chunkVelRng;
  if (splintDef->chunkVelRng != 0) {
                    /* WARNING: Subroutine does not return */
    rand();
  }
  local_70 = local_70 & 0xffff0000 | (uint)uVar12;
  local_6c[1] = (undefined *)((uint)local_6c[1] & 0xffff0000 | (uint)(ushort)-uVar12);
  local_6c[3] = (undefined *)((uint)local_6c[3] & 0xffff | (uint)uVar12 << 0x10);
  local_58 = local_58 & 0xffff | (uint)(ushort)-uVar12 << 0x10;
  uVar12 = splintDef->chunkVelZ;
  local_6c[0] = (undefined *)((uint)local_6c[0] & 0xffff0000 | (uint)uVar12);
  local_6c[2] = (undefined *)((uint)local_6c[2] & 0xffff0000 | (uint)uVar12);
  local_5c = (undefined *)((uint)local_5c & 0xffff0000 | (uint)uVar12);
  local_54 = (undefined *)((uint)local_54 & 0xffff0000 | (uint)uVar12);
  local_48 = (int)splintDef->lifetime;
  _FX_SetupLighting(instance);
  local_a8 = CONCAT22(local_a8._2_2_,0x1000);
  local_ac = 0;
  local_b0 = 0x1000;
  local_b4 = 0;
  local_b8 = 0x1000;
  local_a4 = local_98;
  local_a0 = local_94;
  local_9c = local_90;
  iVar8 = 0;
  do {
    p_Var3 = FX_GetMatrix(fxTracker);
    if (p_Var3 == (_FX_MATRIX *)0x0) {
      if (iVar8 == 0) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      rand();
    }
    local_c8[iVar8] = p_Var3;
    iVar4 = iVar8 * 8;
    puVar11 = &local_70 + iVar8 * 2;
    *(undefined4 *)(p_Var3->lwTransform).m = local_b8;
    *(undefined4 *)((p_Var3->lwTransform).m + 2) = local_b4;
    *(undefined4 *)((p_Var3->lwTransform).m + 4) = local_b0;
    *(undefined4 *)((p_Var3->lwTransform).m + 6) = local_ac;
    *(undefined4 *)((p_Var3->lwTransform).m + 8) = local_a8;
    (p_Var3->lwTransform).t[0] = local_a4;
    (p_Var3->lwTransform).t[1] = local_a0;
    (p_Var3->lwTransform).t[2] = local_9c;
    local_78 = *(short *)puVar11;
    local_76 = *(short *)((int)&local_70 + iVar4 + 2);
    local_74 = *(short *)(local_6c + iVar8 * 2);
    *(short *)puVar11 =
         (short)((int)local_78 * (int)(short)local_b8 >> 0xc) +
         (short)((int)local_76 * (int)local_b8._2_2_ >> 0xc) +
         (short)((int)local_74 * (int)(short)local_b4 >> 0xc);
    *(short *)((int)&local_70 + iVar4 + 2) =
         (short)((int)local_78 * (int)local_b4._2_2_ >> 0xc) +
         (short)((int)local_76 * (int)(short)local_b0 >> 0xc) +
         (short)((int)local_74 * (int)local_b0._2_2_ >> 0xc);
    iVar14 = iVar8 + 1;
    *(short *)(local_6c + iVar8 * 2) =
         (short)((int)local_78 * (int)(short)local_ac >> 0xc) +
         (short)((int)local_76 * (int)local_ac._2_2_ >> 0xc) +
         (short)((int)local_74 * (int)(short)local_a8 >> 0xc);
    (p_Var3->lwTransform).t[0] = (p_Var3->lwTransform).t[0] + (int)*(short *)puVar11 * 4;
    (p_Var3->lwTransform).t[1] =
         (p_Var3->lwTransform).t[1] +
         ((int)((uint)*(ushort *)((int)&local_70 + iVar4 + 2) << 0x10) >> 0xe);
    iVar8 = iVar14;
  } while (iVar14 < 4);
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
  if (mface < local_40) {
    local_34 = 0x55555556;
    local_30 = &local_88;
    do {
      psVar13 = (short *)(lVar1 + (uint)(mface->face).v0 * 8);
      psVar15 = (short *)(lVar1 + (uint)(mface->face).v1 * 8);
      psVar16 = (short *)(lVar1 + (uint)(mface->face).v2 * 8);
      iVar8 = (int)*psVar13 + (int)*psVar15 + (int)*psVar16;
      iVar9 = (int)((ulonglong)((longlong)iVar8 * (longlong)local_34) >> 0x20) - (iVar8 >> 0x1f);
      local_80 = (undefined2)iVar9;
      iVar8 = (int)psVar13[1] + (int)psVar15[1] + (int)psVar16[1];
      iVar8 = (int)((ulonglong)((longlong)iVar8 * (longlong)local_34) >> 0x20) - (iVar8 >> 0x1f);
      local_7e = (undefined2)iVar8;
      iVar4 = (int)psVar13[2] + (int)psVar15[2] + (int)psVar16[2];
      iVar14 = iVar8 * 0x10000 >> 0x10;
      iVar9 = iVar9 * 0x10000 >> 0x10;
      iVar8 = iVar9;
      if (iVar9 < 0) {
        iVar8 = -iVar9;
      }
      local_7c = (short)((ulonglong)((longlong)iVar4 * (longlong)local_34) >> 0x20) -
                 (short)(iVar4 >> 0x1f);
      iVar4 = iVar14;
      if (iVar14 < 0) {
        iVar4 = -iVar14;
      }
      uVar5 = (uint)(iVar9 < 1);
      if ((iVar8 <= iVar4) && (uVar5 = 3, 0 < iVar14)) {
        uVar5 = 2;
      }
      p_Var3 = local_c8[uVar5];
      fxPrim = FX_GetPrim(fxTracker);
      p_Var17 = local_40;
      if (fxPrim != (_FX_PRIM *)0x0) {
        if (fxSetup == (TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup)0x0) {
          (fxPrim->position).x = *(short *)(p_Var3->lwTransform).t;
          (fxPrim->position).y = *(short *)((p_Var3->lwTransform).t + 1);
          (fxPrim->position).z = *(short *)((p_Var3->lwTransform).t + 2);
          sVar2 = (fxPrim->position).z;
          local_88 = (fxPrim->position).x - (short)local_98;
          local_30[1] = (fxPrim->position).y - (short)local_94;
          local_30[2] = sVar2 - (short)local_90;
          (fxPrim->v0).x = *psVar13 - local_88;
          (fxPrim->v0).y = psVar13[1] - local_86;
          (fxPrim->v0).z = psVar13[2] - local_84;
          (fxPrim->v1).x = *psVar15 - local_88;
          (fxPrim->v1).y = psVar15[1] - local_86;
          (fxPrim->v1).z = psVar15[2] - local_84;
          (fxPrim->v2).x = *psVar16 - local_88;
          (fxPrim->v2).y = psVar16[1] - local_86;
          sVar2 = psVar16[2];
          fxPrim->matrix = p_Var3;
          (fxPrim->v2).z = sVar2 - local_84;
          FX_AniTexSetup(fxPrim,mface,local_3c,fxTracker);
          if ((local_50 & 0x40) == 0) {
            lVar7 = _FX_DoLighting(mface);
            fxPrim->color = lVar7;
          }
          else {
            if ((mface->flags & 2) == 0) {
              uVar10 = mface->color & 0xffffff;
              fxPrim->color = uVar10;
              uVar10 = uVar10 | 0x20000000;
              uVar6 = mface->color;
            }
            else {
              iVar8 = mface->color;
              uVar10 = *(uint *)(iVar8 + 0xc) & 0xffffff;
              fxPrim->color = uVar10;
              uVar10 = uVar10 | 0x24000000;
              uVar6 = *(uint *)(iVar8 + 0xc);
            }
            fxPrim->color = uVar10 | uVar6 & 0x3000000;
          }
          if (fxProcess == (TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess)0x0) {
            *(code **)&fxPrim->process = FX_ShatterProcess;
          }
          else {
            *(TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess *)&fxPrim->process = fxProcess;
          }
          *(undefined2 *)&fxPrim->duo = *(undefined2 *)(&local_70 + uVar5 * 2);
          *(undefined2 *)((int)&fxPrim->duo + 2) = *(undefined2 *)((int)&local_70 + uVar5 * 8 + 2);
          *(undefined2 *)((int)&fxPrim->duo + 4) = *(undefined2 *)(local_6c + uVar5 * 2);
          if (splintDef == (FXSplinter *)0x0) {
                    /* WARNING: Subroutine does not return */
            rand();
          }
          if (splintDef->triVelRng != 0) {
                    /* WARNING: Subroutine does not return */
            rand();
          }
          if (vel != (SVECTOR *)0x0) {
            *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + vel->vx;
            *(short *)((int)&fxPrim->duo + 2) = *(short *)((int)&fxPrim->duo + 2) + vel->vy;
            *(short *)((int)&fxPrim->duo + 4) = *(short *)((int)&fxPrim->duo + 4) + vel->vz;
          }
          *(undefined2 *)((int)&fxPrim->duo + 6) = 0;
          *(undefined2 *)((int)&fxPrim->duo + 8) = 0;
          if (splintDef == (FXSplinter *)0x0) {
                    /* WARNING: Subroutine does not return */
            *(undefined2 *)((int)&fxPrim->duo + 10) = 0xfff8;
            rand();
          }
          if (splintDef->rotRateRng != 0) {
                    /* WARNING: Subroutine does not return */
            rand();
          }
          fxPrim->work3 = 0;
          *(short *)((int)&fxPrim->duo + 10) = splintDef->gravityZ;
          fxPrim->work1 = 0x1000;
          fxPrim->timeToLive = (short)local_48;
          sVar2 = -0x7fff;
          if ((local_50 & 0x10) == 0) {
            sVar2 = (instance->position).z -
                    instance->object->modelList[instance->currentModel]->maxRad;
          }
          fxPrim->work0 = sVar2;
        }
        else {
          (*fxSetup)(fxPrim,fxProcess,p_Var3,instance,mface,local_38,center,vel,accl,fxTracker,0x1e)
          ;
        }
        LIST_InsertFunc(&fxTracker->usedPrimList,(NodeType *)fxPrim);
        p_Var17 = mface;
      }
      mface = p_Var17 + local_44;
    } while (mface < local_40);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _FX_BuildSplinters(struct _Instance *instance /*$s2*/, struct SVECTOR *center /*$s4*/, struct SVECTOR *vel /*$s5*/, struct SVECTOR *accl /*$s6*/, struct FXSplinter *splintDef /*stack 16*/, struct _FXTracker *fxTracker /*stack 20*/, TDRFuncPtr__FX_BuildSplinters6fxSetup fxSetup /*stack 24*/, TDRFuncPtr__FX_BuildSplinters7fxProcess fxProcess /*stack 28*/, int shardFlags /*stack 32*/)
 // line 1541, offset 0x8004403c
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
 // line 1566, offset 0x80044190
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
 // line 1741, offset 0x800442a4
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
 // line 1747, offset 0x800442dc
	/* begin block 1 */
		// Start line: 1748
		// Start offset: 0x800442DC

		/* begin block 1.1 */
			// Start line: 1748
			// Start offset: 0x800442DC
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a0
		// 		short _x1; // $a3
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _Position *_v; // $a1
		/* end block 1.1 */
		// End offset: 0x800442DC
		// End Line: 1748
	/* end block 1 */
	// End offset: 0x80044428
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
 // line 1767, offset 0x80044430
	/* begin block 1 */
		// Start line: 1768
		// Start offset: 0x80044430
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct _FXTracker *fxTracker; // $s2
	// 		struct _FXGeneralEffect *currentEffect; // $a2

		/* begin block 1.1 */
			// Start line: 1796
			// Start offset: 0x800444F4
			// Variables:
		// 		int i; // $a3
		// 		int end; // $t1
		// 		struct _FXRibbon *currentRibbon; // $t0
		/* end block 1.1 */
		// End offset: 0x8004456C
		// End Line: 1806

		/* begin block 1.2 */
			// Start line: 1809
			// Start offset: 0x8004457C
		/* end block 1.2 */
		// End offset: 0x800445B8
		// End Line: 1813
	/* end block 1 */
	// End offset: 0x800445C8
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
 // line 1822, offset 0x800445e0
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
 // line 1842, offset 0x80044640
	/* begin block 1 */
		// Start line: 1843
		// Start offset: 0x80044640
		// Variables:
	// 		struct _FXTracker *fxTracker; // $s0
	// 		struct _FXGeneralEffect *currentEffect; // $a0
	// 		long offset; // $s1

		/* begin block 1.1 */
			// Start line: 1862
			// Start offset: 0x800446B4
		/* end block 1.1 */
		// End offset: 0x800446E4
		// End Line: 1865
	/* end block 1 */
	// End offset: 0x800446F4
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
 // line 1872, offset 0x80044710
	/* begin block 1 */
		// Start line: 1873
		// Start offset: 0x80044710
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $a0
	// 		struct _FX_PRIM *nextFXPrim; // $s0
	// 		struct _FX_MATRIX *fxMatrix; // $s0
	// 		struct _FX_MATRIX *nextFXMatrix; // $s1

		/* begin block 1.1 */
			// Start line: 1943
			// Start offset: 0x80044884
			// Variables:
		// 		struct _FXGeneralEffect *currentEffect; // $a0
		// 		struct _FXGeneralEffect *nextEffect; // $s0
		/* end block 1.1 */
		// End offset: 0x800448A8
		// End Line: 1953
	/* end block 1 */
	// End offset: 0x800448EC
	// End Line: 1960

	/* begin block 2 */
		// Start line: 4463
	/* end block 2 */
	// End Line: 4464

	/* begin block 3 */
		// Start line: 4476
	/* end block 3 */
	// End Line: 4477

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FX_ProcessList(_FXTracker *fxTracker)

{
  _FXGeneralEffect *p_Var1;
  int iVar2;
  NodeType *node;
  NodeType *pNVar3;
  NodeType *pNVar4;
  _FXGeneralEffect *p_Var5;
  
  iVar2 = (int)(((uint)_FX_TimeCount + (uint)(ushort)theCamera.tiltList[0][0]) * 0x10000) >> 0x10;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  _FX_Frames = (short)(iVar2 >> 0xc);
  pNVar4 = (fxTracker->usedMatrixList).next;
  _FX_TimeCount =
       (short)((uint)_FX_TimeCount + (uint)(ushort)theCamera.tiltList[0][0]) + _FX_Frames * -0x1000;
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
 // line 1963, offset 0x8004490c
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
 // line 1985, offset 0x80044958
	/* begin block 1 */
		// Start line: 1986
		// Start offset: 0x80044958
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
			// Start offset: 0x800449DC
			// Variables:
		// 		long flags; // $s3

			/* begin block 1.1.1 */
				// Start line: 2095
				// Start offset: 0x80044CC8
				// Variables:
			// 		struct _POLY_NG4 *ng4; // $a2

				/* begin block 1.1.1.1 */
					// Start line: 2097
					// Start offset: 0x80044CC8
					// Variables:
				// 		int n; // $a0
				// 		long *ptr; // $a1
				/* end block 1.1.1.1 */
				// End offset: 0x80044D88
				// End Line: 2122
			/* end block 1.1.1 */
			// End offset: 0x80044D88
			// End Line: 2144

			/* begin block 1.1.2 */
				// Start line: 2161
				// Start offset: 0x80044DC0
			/* end block 1.1.2 */
			// End offset: 0x80044DC0
			// End Line: 2163

			/* begin block 1.1.3 */
				// Start line: 2251
				// Start offset: 0x80044F40
				// Variables:
			// 		struct POLY_FT4 *ft4; // $a2
			// 		unsigned short uMin; // $t1
			// 		unsigned short uMax; // $t0
			// 		unsigned short vMin; // $a3
			// 		unsigned short vMax; // $v1
			/* end block 1.1.3 */
			// End offset: 0x8004518C
			// End Line: 2282

			/* begin block 1.1.4 */
				// Start line: 2289
				// Start offset: 0x800451C8
				// Variables:
			// 		struct POLY_FT3 *ft3; // $t0

				/* begin block 1.1.4.1 */
					// Start line: 2302
					// Start offset: 0x80045214
					// Variables:
				// 		short uMin; // $a3
				// 		short uMax; // $a2
				/* end block 1.1.4.1 */
				// End offset: 0x80045318
				// End Line: 2310
			/* end block 1.1.4 */
			// End offset: 0x80045354
			// End Line: 2316
		/* end block 1.1 */
		// End offset: 0x80045354
		// End Line: 2320

		/* begin block 1.2 */
			// Start line: 2331
			// Start offset: 0x80045394
			// Variables:
		// 		struct DVECTOR xy_pos; // stack offset -72
		// 		long flags; // $t2

			/* begin block 1.2.1 */
				// Start line: 2400
				// Start offset: 0x800455D0
				// Variables:
			// 		struct _POLY_SG4 *sg4; // $a1

				/* begin block 1.2.1.1 */
					// Start line: 2402
					// Start offset: 0x800455D0
					// Variables:
				// 		int n; // $a3
				// 		long *src; // $t2
				// 		long *dst; // $t1
				// 		long *ptr; // $t3
				/* end block 1.2.1.1 */
				// End offset: 0x800456C8
				// End Line: 2433
			/* end block 1.2.1 */
			// End offset: 0x800456C8
			// End Line: 2455

			/* begin block 1.2.2 */
				// Start line: 2467
				// Start offset: 0x8004575C
			/* end block 1.2.2 */
			// End offset: 0x8004575C
			// End Line: 2471

			/* begin block 1.2.3 */
				// Start line: 2499
				// Start offset: 0x80045834
				// Variables:
			// 		unsigned short uMin; // $t3
			// 		unsigned short uMax; // $t1
			// 		unsigned short vMin; // $a3
			// 		unsigned short vMax; // $v1
			// 		struct POLY_FT4 *ft4; // $a2
			/* end block 1.2.3 */
			// End offset: 0x80045AA0
			// End Line: 2537
		/* end block 1.2 */
		// End offset: 0x80045B0C
		// End Line: 2556
	/* end block 1 */
	// End offset: 0x80045B18
	// End Line: 2560

	/* begin block 2 */
		// Start line: 4713
	/* end block 2 */
	// End Line: 4714

void FX_DrawList(_FXTracker *fxTracker,GameTracker *gameTracker,ulong **ot,MATRIX *wcTransform)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  bool bVar5;
  GameTracker *pGVar6;
  undefined4 in_zero;
  undefined4 in_at;
  char cVar7;
  char cVar8;
  ushort uVar9;
  byte bVar10;
  byte bVar11;
  int iVar12;
  char cVar13;
  ushort uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  NodeType *pNVar18;
  uint *puVar19;
  uint *puVar20;
  NodeType **ppNVar21;
  NodeType *pNVar22;
  NodeType *pNVar23;
  _PrimPool *p_Var24;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  undefined local_50;
  undefined local_4f;
  undefined local_4e;
  GameTracker *local_40;
  GameTracker *local_3c;
  int local_38;
  int local_34;
  
  bVar5 = false;
  p_Var24 = gameTracker->primPool;
  puVar19 = p_Var24->nextPrim;
  local_4e = 0x1f;
  local_4f = 0x1f;
  local_50 = 0x1f;
  pNVar18 = (fxTracker->usedPrimList).next;
  if (pNVar18 != (NodeType *)0x0) {
    ppNVar21 = (NodeType **)(puVar19 + 1);
    do {
      if (p_Var24->lastPrim <= puVar19 + 10) break;
      pNVar22 = pNVar18[1].next;
      pNVar23 = pNVar18->next;
      if (((uint)pNVar22 & 0x10) == 0) {
        if (((uint)pNVar22 & 0x10000) == 0) {
          pNVar18[3].prev[4].prev = (NodeType *)(int)*(short *)&pNVar18[5].next;
          pNVar18[3].prev[4].next = (NodeType *)(int)*(short *)((int)&pNVar18[5].next + 2);
          pNVar18[3].prev[5].prev = (NodeType *)(int)*(short *)&pNVar18[6].prev;
                    /* WARNING: Subroutine does not return */
          CompMatrix((undefined4 *)wcTransform,(ushort *)&pNVar18[3].prev[1].next,
                     (uint *)&DAT_1f800000);
        }
        if (!bVar5) {
          setCopControlWord(2,0,*(undefined4 *)wcTransform->m);
          setCopControlWord(2,0x800,*(undefined4 *)(wcTransform->m + 2));
          setCopControlWord(2,0x1000,*(undefined4 *)(wcTransform->m + 4));
          setCopControlWord(2,0x1800,*(undefined4 *)(wcTransform->m + 6));
          setCopControlWord(2,0x2000,*(undefined4 *)(wcTransform->m + 8));
          setCopControlWord(2,0x2800,wcTransform->t[0]);
          setCopControlWord(2,0x3000,wcTransform->t[1]);
          setCopControlWord(2,0x3800,wcTransform->t[2]);
          bVar5 = true;
        }
        if (((uint)pNVar22 & 0x2000) == 0) {
          setCopReg(2,in_zero,pNVar18[7].next);
          setCopReg(2,in_at,pNVar18[8].prev);
          setCopReg(2,&pNVar18[9].next,pNVar18[8].next);
          setCopReg(2,&pNVar18[8].next,pNVar18[9].prev);
          setCopReg(2,&pNVar18[7].next,pNVar18[9].next);
          setCopReg(2,gameTracker,pNVar18[10].prev);
        }
        else {
          local_64 = local_64 & 0xffff0000 |
                     (int)*(short *)&pNVar18[8].prev * (int)*(short *)((int)&pNVar18[9].next + 2) >>
                     0xc & 0xffffU;
          local_5c = local_5c & 0xffff0000 |
                     (int)*(short *)&pNVar18[9].prev * (int)*(short *)((int)&pNVar18[9].next + 2) >>
                     0xc & 0xffffU;
          local_68 = (int)*(short *)&pNVar18[7].next * (int)*(short *)((int)&pNVar18[7].next + 2) >>
                     0xc & 0xffff;
          local_60 = (int)*(short *)&pNVar18[8].next * (int)*(short *)((int)&pNVar18[7].next + 2) >>
                     0xc & 0xffff;
          local_58 = (int)*(short *)&pNVar18[9].next * (int)*(short *)((int)&pNVar18[7].next + 2) >>
                     0xc & 0xffff;
          local_54 = local_54 & 0xffff0000 |
                     (int)*(short *)&pNVar18[10].prev * (int)*(short *)((int)&pNVar18[9].next + 2)
                     >> 0xc & 0xffffU;
          setCopReg(2,in_zero,local_68);
          setCopReg(2,in_at,local_64);
          setCopReg(2,&local_68,local_60);
          setCopReg(2,&local_58,local_5c);
          setCopReg(2,&local_60,local_58);
          setCopReg(2,gameTracker,local_54);
        }
        copFunction(2,0x280030);
        if (((uint)pNVar22 & 0x1000000) == 0) {
          if (((uint)pNVar22 & 0x4000) == 0) {
            local_34 = getCopReg(2,0x9800);
            local_34 = local_34 >> 2;
          }
          else {
            gameTracker = (GameTracker *)getCopReg(2,0x11);
            local_3c = (GameTracker *)getCopReg(2,0x12);
            local_38 = getCopReg(2,0x13);
            local_34 = local_38 >> 2;
            pGVar6 = local_3c;
            if ((int)local_3c < (int)gameTracker) {
              pGVar6 = gameTracker;
            }
            local_40 = gameTracker;
            if (local_38 < (int)pGVar6) {
              local_34 = (int)pGVar6 >> 2;
            }
          }
        }
        else {
          local_40 = (GameTracker *)getCopReg(2,0x11);
          local_3c = (GameTracker *)getCopReg(2,0x12);
          local_38 = getCopReg(2,0x13);
          local_34 = (int)local_40 >> 2;
        }
        if (((uint)pNVar22 & 0x8000) != 0) {
          local_34 = local_34 + -0x14;
        }
        if (local_34 - 1U < 0xbff) {
          if (((uint)pNVar22 & 1) == 0) {
            if (((uint)pNVar22 & 8) == 0) {
              if (((uint)pNVar22 & 0x1000000) == 0) {
                *ppNVar21 = pNVar18[3].next;
                uVar4 = getCopReg(2,0xc);
                puVar19[2] = uVar4;
                uVar4 = getCopReg(2,0xd);
                puVar19[3] = uVar4;
                uVar4 = getCopReg(2,0xe);
                puVar19[4] = uVar4;
                ppNVar21 = ppNVar21 + 5;
                *puVar19 = (uint)ot[local_34] & 0xffffff | 0x4000000;
                puVar20 = puVar19 + 5;
              }
              else {
                if (((uint)pNVar22 & 0x80000) == 0) goto LAB_80045354;
                ppNVar21[1] = pNVar18[3].next;
                pNVar18 = pNVar18[4].next;
                *ppNVar21 = (NodeType *)0xe1000620;
                ppNVar21[3] = pNVar18;
                uVar4 = getCopReg(2,0xc);
                puVar19[5] = uVar4;
                uVar4 = getCopReg(2,0xd);
                puVar19[3] = uVar4;
                *(undefined *)((int)ppNVar21 + 7) = 0x52;
                ppNVar21 = ppNVar21 + 6;
                *puVar19 = (uint)ot[local_34] & 0xffffff | 0x5000000;
                puVar20 = puVar19 + 6;
              }
            }
            else {
              if (((uint)pNVar22 & 0x80000) != 0) {
                uVar4 = getCopReg(2,0xc);
                puVar19[3] = uVar4;
                uVar4 = getCopReg(2,0xd);
                puVar19[5] = uVar4;
                uVar4 = getCopReg(2,0xe);
                puVar19[7] = uVar4;
                setCopReg(2,in_zero,pNVar18[10].next);
                setCopReg(2,in_at,pNVar18[0xb].prev);
                copFunction(2,0x180001);
                *ppNVar21 = (NodeType *)0xe1000620;
                uVar4 = getCopReg(2,0xe);
                puVar19[9] = uVar4;
                gameTracker = (GameTracker *)(puVar19 + 2);
                iVar12 = 0;
                pNVar22 = pNVar18;
                do {
                  setCopReg(2,0x4000,0x1000 - (int)*(short *)&pNVar22[6].next);
                  setCopReg(2,0x4800,(uint)*(byte *)&pNVar18[3].next);
                  setCopReg(2,0x5000,(uint)*(byte *)((int)&pNVar18[3].next + 1));
                  setCopReg(2,0x5800,(uint)*(byte *)((int)&pNVar18[3].next + 2));
                  copFunction(2,0x198003d);
                  uVar15 = getCopReg(2,0x4800);
                  uVar16 = getCopReg(2,0x5000);
                  uVar17 = getCopReg(2,0x5800);
                  *(char *)&(gameTracker->gameData).asmData.drawBackFaces = (char)uVar15;
                  *(undefined *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1) =
                       (char)uVar16;
                  *(undefined *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 2) =
                       (char)uVar17;
                  gameTracker = (GameTracker *)&(gameTracker->gameData).asmData.MorphTime;
                  iVar12 = iVar12 + 1;
                  pNVar22 = (NodeType *)((int)&pNVar22->prev + 2);
                } while (iVar12 < 4);
                *puVar19 = (uint)ot[local_34] & 0xffffff | 0x9000000;
                ot[local_34] = (ulong *)((uint)puVar19 & 0xffffff);
                *(undefined *)((int)puVar19 + 0xb) = 0x3a;
                puVar19 = puVar19 + 10;
                ppNVar21 = ppNVar21 + 10;
                goto LAB_80045354;
              }
              uVar4 = getCopReg(2,0xc);
              puVar19[2] = uVar4;
              uVar4 = getCopReg(2,0xd);
              puVar19[4] = uVar4;
              uVar4 = getCopReg(2,0xe);
              puVar19[6] = uVar4;
              setCopReg(2,in_zero,pNVar18[10].next);
              setCopReg(2,in_at,pNVar18[0xb].prev);
              copFunction(2,0x180001);
              *ppNVar21 = pNVar18[3].next;
              ppNVar21[2] = pNVar18[3].next;
              ppNVar21[4] = pNVar18[3].next;
              pNVar18 = pNVar18[3].next;
              *(undefined *)((int)ppNVar21 + -1) = 8;
              *(undefined *)((int)ppNVar21 + 3) = 0x38;
              ppNVar21[6] = pNVar18;
              uVar4 = getCopReg(2,0xe);
              puVar19[8] = uVar4;
              ppNVar21 = ppNVar21 + 9;
              *puVar19 = (uint)ot[local_34] & 0xffffff | 0x8000000;
              puVar20 = puVar19 + 9;
            }
          }
          else {
            gameTracker = (GameTracker *)pNVar18[1].prev;
            if (((uint)pNVar22 & 8) == 0) {
              uVar4 = getCopReg(2,0xc);
              puVar19[2] = uVar4;
              uVar4 = getCopReg(2,0xd);
              puVar19[4] = uVar4;
              uVar4 = getCopReg(2,0xe);
              puVar19[6] = uVar4;
              ppNVar21[2] = (NodeType *)(gameTracker->gameData).asmData.drawBackFaces;
              ppNVar21[4] = (NodeType *)(gameTracker->gameData).asmData.dispPage;
              ppNVar21[6] = *(NodeType **)&(gameTracker->gameData).asmData.MorphTime;
              if (((uint)pNVar22 & 0x1000) != 0) {
                bVar10 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                bVar11 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
                if (bVar10 < bVar11) {
                  bVar3 = bVar11 < bVar10;
                  if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar10) {
LAB_8004526c:
                    cVar8 = *(char *)&(gameTracker->gameData).asmData.MorphTime;
                    goto LAB_80045270;
                  }
                  cVar8 = *(char *)&(gameTracker->gameData).asmData.drawBackFaces;
                }
                else {
                  if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar11)
                  goto LAB_8004526c;
                  cVar8 = *(char *)&(gameTracker->gameData).asmData.dispPage;
LAB_80045270:
                  bVar10 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                  bVar11 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
                  bVar3 = bVar11 < bVar10;
                }
                if (bVar3) {
                  if (*(byte *)&(gameTracker->gameData).asmData.MorphTime < bVar10) {
                    cVar13 = *(char *)&(gameTracker->gameData).asmData.drawBackFaces;
                  }
                  else {
LAB_800452c8:
                    cVar13 = *(char *)&(gameTracker->gameData).asmData.MorphTime;
                  }
                }
                else {
                  if (bVar11 <= *(byte *)&(gameTracker->gameData).asmData.MorphTime)
                  goto LAB_800452c8;
                  cVar13 = *(char *)&(gameTracker->gameData).asmData.dispPage;
                }
                cVar7 = cVar8;
                if (*(char *)&(gameTracker->gameData).asmData.drawBackFaces == cVar8) {
                  cVar7 = cVar13;
                }
                *(char *)(puVar19 + 3) = cVar7;
                cVar7 = cVar8;
                if (*(char *)&(gameTracker->gameData).asmData.dispPage == cVar8) {
                  cVar7 = cVar13;
                }
                *(char *)(puVar19 + 5) = cVar7;
                if (*(char *)&(gameTracker->gameData).asmData.MorphTime == cVar8) {
                  cVar8 = cVar13;
                }
                *(char *)(puVar19 + 7) = cVar8;
              }
              *ppNVar21 = pNVar18[3].next;
              ppNVar21 = ppNVar21 + 8;
              *puVar19 = (uint)ot[local_34] & 0xffffff | 0x7000000;
              puVar20 = puVar19 + 8;
            }
            else {
              uVar4 = getCopReg(2,0xc);
              puVar19[2] = uVar4;
              uVar4 = getCopReg(2,0xd);
              puVar19[4] = uVar4;
              uVar4 = getCopReg(2,0xe);
              puVar19[6] = uVar4;
              setCopReg(2,in_zero,pNVar18[10].next);
              setCopReg(2,in_at,pNVar18[0xb].prev);
              copFunction(2,0x180001);
              bVar10 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
              bVar11 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
              if (bVar10 < bVar11) {
                bVar3 = bVar11 < bVar10;
                if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar10) {
LAB_80044fc8:
                  bVar1 = *(byte *)&(gameTracker->gameData).asmData.MorphTime;
                  goto LAB_80044fcc;
                }
                bVar1 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
              }
              else {
                if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar11)
                goto LAB_80044fc8;
                bVar1 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
LAB_80044fcc:
                bVar10 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                bVar11 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
                bVar3 = bVar11 < bVar10;
              }
              if (bVar3) {
                if (*(byte *)&(gameTracker->gameData).asmData.MorphTime < bVar10) {
                  uVar14 = (ushort)*(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                }
                else {
LAB_80045024:
                  uVar14 = (ushort)*(byte *)&(gameTracker->gameData).asmData.MorphTime;
                }
              }
              else {
                if (bVar11 <= *(byte *)&(gameTracker->gameData).asmData.MorphTime)
                goto LAB_80045024;
                uVar14 = (ushort)*(byte *)&(gameTracker->gameData).asmData.dispPage;
              }
              bVar10 = *(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1);
              bVar11 = *(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1);
              if (bVar10 < bVar11) {
                if (*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) <= bVar10) {
LAB_80045080:
                  bVar2 = *(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1);
                  goto LAB_8004508c;
                }
                bVar2 = *(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1);
              }
              else {
                if (*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) <= bVar11)
                goto LAB_80045080;
                bVar2 = *(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1);
LAB_8004508c:
                bVar10 = *(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1);
                bVar11 = *(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1);
              }
              if (bVar11 < bVar10) {
                if (*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) < bVar10) {
                  uVar9 = (ushort)*(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1)
                          << 8;
                }
                else {
LAB_800450e4:
                  uVar9 = (ushort)*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) <<
                          8;
                }
              }
              else {
                if (bVar11 <= *(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1))
                goto LAB_800450e4;
                uVar9 = (ushort)*(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1) << 8;
              }
              *(ushort *)(puVar19 + 3) = CONCAT11(bVar2,bVar1);
              *(ushort *)(puVar19 + 5) = uVar14 | (ushort)bVar2 << 8;
              *(ushort *)(puVar19 + 7) = bVar1 | uVar9;
              *(ushort *)(puVar19 + 9) = uVar14 | uVar9;
              *(undefined2 *)((int)puVar19 + 0xe) =
                   *(undefined2 *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 2);
              *(undefined2 *)((int)puVar19 + 0x16) =
                   *(undefined2 *)((int)&(gameTracker->gameData).asmData.dispPage + 2);
              uVar4 = getCopReg(2,0xe);
              puVar19[8] = uVar4;
              if (((uint)pNVar22 & 0x1000) != 0) {
                bVar10 = *(byte *)(puVar19 + 3) ^ *(byte *)(puVar19 + 5);
                *(byte *)(puVar19 + 3) = bVar10;
                bVar10 = bVar10 ^ *(byte *)(puVar19 + 5);
                gameTracker = (GameTracker *)(uint)bVar10;
                bVar11 = *(byte *)(puVar19 + 7) ^ *(byte *)(puVar19 + 9);
                *(byte *)(puVar19 + 7) = bVar11;
                bVar11 = bVar11 ^ *(byte *)(puVar19 + 9);
                *(byte *)(puVar19 + 5) = bVar10;
                *(byte *)(puVar19 + 9) = bVar11;
                *(byte *)(puVar19 + 3) = *(byte *)(puVar19 + 3) ^ bVar10;
                *(byte *)(puVar19 + 7) = *(byte *)(puVar19 + 7) ^ bVar11;
              }
              *ppNVar21 = pNVar18[3].next;
              ppNVar21 = ppNVar21 + 10;
              *puVar19 = (uint)ot[local_34] & 0xffffff | 0x9000000;
              puVar20 = puVar19 + 10;
            }
          }
          ot[local_34] = (ulong *)((uint)puVar19 & 0xffffff);
          puVar19 = puVar20;
        }
      }
LAB_80045354:
      pNVar18 = pNVar23;
    } while (pNVar23 != (NodeType *)0x0);
  }
  SetRotMatrix((undefined4 *)wcTransform);
                    /* WARNING: Subroutine does not return */
  SetTransMatrix((int)wcTransform);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SimpleQuadSetup(struct _FX_PRIM *fxPrim /*$s5*/, TDRFuncPtr_FX_SimpleQuadSetup1fxProcess fxProcess /*stack 4*/, struct _FX_MATRIX *fxMatrix /*stack 8*/, struct _Instance *instance /*$a3*/, struct _MFace *mface /*stack 16*/, struct _MVertex *vertexList /*stack 20*/, struct SVECTOR *center /*stack 24*/, struct SVECTOR *vel /*stack 28*/, struct SVECTOR *accl /*stack 32*/, struct _FXTracker *fxTracker /*stack 36*/, int timeToLive /*stack 40*/)
 // line 2727, offset 0x80045b60
	/* begin block 1 */
		// Start line: 2728
		// Start offset: 0x80045B60
		// Variables:
	// 		struct _MVertex *vertex1; // $s2
	// 		struct _MVertex *vertex2; // $s3
	// 		struct _MVertex *vertex3; // $s4

		/* begin block 1.1 */
			// Start line: 2728
			// Start offset: 0x80045B60
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _Position *_v0; // $v0
		/* end block 1.1 */
		// End offset: 0x80045B60
		// End Line: 2728

		/* begin block 1.2 */
			// Start line: 2728
			// Start offset: 0x80045B60
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $v0
		/* end block 1.2 */
		// End offset: 0x80045B60
		// End Line: 2728

		/* begin block 1.3 */
			// Start line: 2728
			// Start offset: 0x80045B60
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $v0
		/* end block 1.3 */
		// End offset: 0x80045B60
		// End Line: 2728

		/* begin block 1.4 */
			// Start line: 2728
			// Start offset: 0x80045B60
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $v0
		/* end block 1.4 */
		// End offset: 0x80045B60
		// End Line: 2728

		/* begin block 1.5 */
			// Start line: 2728
			// Start offset: 0x80045B60
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $v0
		/* end block 1.5 */
		// End offset: 0x80045B60
		// End Line: 2728
	/* end block 1 */
	// End offset: 0x80045D58
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
 // line 2796, offset 0x80045d9c
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
 // line 2806, offset 0x80045e18
	/* begin block 1 */
		// Start line: 2807
		// Start offset: 0x80045E18
		// Variables:
	// 		struct _FX_PRIM *temp; // $a1

		/* begin block 1.1 */
			// Start line: 2833
			// Start offset: 0x80045EFC
			// Variables:
		// 		struct Object *waterfx; // $v1
		// 		struct _Model *wxring; // $s1
		/* end block 1.1 */
		// End offset: 0x80046018
		// End Line: 2863
	/* end block 1 */
	// End offset: 0x80046018
	// End Line: 2864

	/* begin block 2 */
		// Start line: 6952
	/* end block 2 */
	// End Line: 6953

void FX_WaterBubbleProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  _FX_PRIM *node;
  short sVar4;
  int iVar5;
  TextureMT3 *pTVar6;
  
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
  iVar5 = (uint)(ushort)fxPrim->work0 + 1;
  uVar2 = fxPrim->work3;
  (fxPrim->position).z = (fxPrim->position).z + *(short *)((int)&fxPrim->duo + 4);
  sVar4 = *(short *)((int)&fxPrim->duo + 8);
  fxPrim->work0 = (short)iVar5;
  iVar5 = (uint)uVar2 - iVar5 * (uint)uVar1;
  sVar3 = (short)iVar5;
  (fxPrim->v2).y = sVar3;
  (fxPrim->v0).y = sVar3;
  iVar5 = iVar5 * 0x10000 >> 0x10;
  if (sVar4 <= iVar5) {
    if ((fxPrim->position).z <= fxPrim->timeToLive) {
      return;
    }
    if ((DebugMenuLine_800c8794.lower != 0) && ((fxPrim->v1).y < iVar5)) {
      iVar5 = **(int **)(DebugMenuLine_800c8794.lower + 0xc);
      node = FX_GetPrim(gFXT);
      if (node != (_FX_PRIM *)0x0) {
        sVar4 = (fxPrim->position).z;
        *(undefined4 *)&node->position = *(undefined4 *)&fxPrim->position;
        (node->position).z = sVar4;
        sVar4 = (node->position).y;
        sVar3 = (node->position).x + -8;
        (node->v2).x = sVar3;
        (node->v0).x = sVar3;
        sVar3 = (node->position).x;
        sVar4 = sVar4 + -8;
        (node->v1).y = sVar4;
        (node->v0).y = sVar4;
        sVar4 = (node->position).z;
        sVar3 = sVar3 + 8;
        (node->v3).x = sVar3;
        (node->v1).x = sVar3;
        sVar3 = (node->position).y;
        (node->v3).z = sVar4;
        (node->v2).z = sVar4;
        (node->v1).z = sVar4;
        (node->v0).z = sVar4;
        sVar3 = sVar3 + 8;
        (node->v3).y = sVar3;
        (node->v2).y = sVar3;
        pTVar6 = *(TextureMT3 **)(*(int *)(iVar5 + 0x14) + 8);
        *(code **)&node->process = FX_WaterRingProcess;
        node->timeToLive = 0x10;
        node->color = 0x2effffff;
        node->startColor = 0xffffff;
        node->endColor = 0;
        node->fadeValue[0] = 0;
        node->flags = node->flags | 0x50009;
        node->fadeStep = 0x100;
        node->texture = pTVar6;
        LIST_InsertFunc(&fxTracker->usedPrimList,(NodeType *)node);
      }
    }
  }
  FX_Die(fxPrim,fxTracker);
                    /* WARNING: Read-only address (ram,0x800d0c44) is written */
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Sprite_Insert(struct NodeType *list /*$a0*/, struct _FX_PRIM *fxPrim /*$s0*/)
 // line 2867, offset 0x80046030
	/* begin block 1 */
		// Start line: 7148
	/* end block 1 */
	// End Line: 7149

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FX_Sprite_Insert(NodeType *list,_FX_PRIM *fxPrim)

{
  LIST_InsertFunc(list,(NodeType *)fxPrim);
  if (_FX_LastUsedPrim == (_FX_PRIM *)0x0) {
    _FX_LastUsedPrim = fxPrim;
  }
  return;
}



// decompiled code
// original method signature: 
// struct TextureMT3 * /*$ra*/ FX_GetTextureObject(struct Object *object /*$a0*/, int modelnum /*$a1*/, int texnum /*$a2*/)
 // line 2873, offset 0x80046068
	/* begin block 1 */
		// Start line: 2875
		// Start offset: 0x80046068
		// Variables:
	// 		struct _Model *model; // $v0
	// 		struct TextureMT3 *texture; // $v0
	/* end block 1 */
	// End offset: 0x80046068
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
 // line 2887, offset 0x800460a4
	/* begin block 1 */
		// Start line: 2888
		// Start offset: 0x800460A4
		// Variables:
	// 		struct Object *waterfx; // $s3
	// 		struct _FX_PRIM *fxPrim; // $s1
	/* end block 1 */
	// End offset: 0x8004622C
	// End Line: 2919

	/* begin block 2 */
		// Start line: 7189
	/* end block 2 */
	// End Line: 7190

void FX_MakeWaterBubble(_SVector *position,_SVector *vel,_SVector *accl,long splashZ,
                       __BubbleParams *BP)

{
  _FX_PRIM *fxPrim;
  
  if ((DebugMenuLine_800c8794.lower != 0) && (fxPrim = FX_GetPrim(gFXT), fxPrim != (_FX_PRIM *)0x0))
  {
    FX_DFacadeParticleSetup
              (fxPrim,(SVECTOR *)position,0xc,0xc,0x2c000000,(SVECTOR *)vel,(SVECTOR *)accl,gFXT,
               (int)(short)splashZ);
                    /* WARNING: Subroutine does not return */
    rand();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawScreenPoly(int transtype /*$t3*/, unsigned long color /*$t2*/, int zdepth /*$a2*/)
 // line 2977, offset 0x80046254
	/* begin block 1 */
		// Start line: 2978
		// Start offset: 0x80046254
		// Variables:
	// 		unsigned long **drawot; // $t0
	// 		struct _POLY_TF4 *poly; // $a3
	/* end block 1 */
	// End offset: 0x800462F8
	// End Line: 2994

	/* begin block 2 */
		// Start line: 7394
	/* end block 2 */
	// End Line: 7395

void FX_DrawScreenPoly(int transtype,ulong color,int zdepth)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  
  iVar1 = theCamera.posSphere.position._0_4_;
  puVar3 = *(uint **)(theCamera.core.vvPlaneConsts[2] + 4);
  if (puVar3 + 7 < *(uint **)(theCamera.core.vvPlaneConsts[2] + 8)) {
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
    *(uint **)(theCamera.core.vvPlaneConsts[2] + 4) = puVar3 + 7;
  }
  return;
}



// decompiled code
// original method signature: 
// struct POLY_GT4 * /*$ra*/ FX_SetupPolyGT4(int x1 /*$a0*/, int y1 /*$a1*/, int x2 /*$a2*/, int y2 /*$a3*/, int otz /*stack 16*/, struct TextureMT3 *texture /*stack 20*/, long color0 /*stack 24*/, long color1 /*stack 28*/, long color2 /*stack 32*/, long color3 /*stack 36*/)
 // line 2997, offset 0x80046300
	/* begin block 1 */
		// Start line: 2998
		// Start offset: 0x80046300
		// Variables:
	// 		struct POLY_GT4 *poly; // $t0
	// 		unsigned long **drawot; // $t3
	/* end block 1 */
	// End offset: 0x800463FC
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
  int iVar2;
  uint *puVar3;
  POLY_GT4 *pPVar4;
  
  iVar2 = theCamera.posSphere.position._0_4_;
  pPVar4 = *(POLY_GT4 **)(theCamera.core.vvPlaneConsts[2] + 4);
  if (*(POLY_GT4 **)(theCamera.core.vvPlaneConsts[2] + 8) <= pPVar4 + 1) {
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
  *(POLY_GT4 **)(theCamera.core.vvPlaneConsts[2] + 4) = pPVar4 + 1;
  return pPVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeWarpArrow(int x /*$s1*/, int y /*$s3*/, int xsize /*$s2*/, int ysize /*$s4*/, int fade /*stack 16*/)
 // line 3058, offset 0x80046404
	/* begin block 1 */
		// Start line: 3059
		// Start offset: 0x80046404
		// Variables:
	// 		struct Object *particle; // $a0
	// 		long color; // $s0
	// 		struct POLY_GT4 *poly; // $v1
	/* end block 1 */
	// End offset: 0x800464C4
	// End Line: 3075

	/* begin block 2 */
		// Start line: 6116
	/* end block 2 */
	// End Line: 6117

/* WARNING: Removing unreachable block (ram,0x80046454) */

void FX_MakeWarpArrow(void)

{
  if (DebugMenuLine_800c87c4.text == (char *)0x0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FX_GetTextureObject((Object *)DebugMenuLine_800c87c4.text,0,9);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeMannaIcon(int x /*$s2*/, int y /*$s3*/, int xsize /*$s0*/, int ysize /*$s1*/)
 // line 3086, offset 0x800464e4
	/* begin block 1 */
		// Start line: 3087
		// Start offset: 0x800464E4
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
	// End offset: 0x80046670
	// End Line: 3124

	/* begin block 2 */
		// Start line: 7637
	/* end block 2 */
	// End Line: 7638

void FX_MakeMannaIcon(void)

{
  if (levelSelectMenu.bit_mask != 0) {
                    /* WARNING: Subroutine does not return */
    FX_GetTextureObject((Object *)levelSelectMenu.bit_mask,0,7);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeGlyphIcon(struct _Position *position /*$s4*/, struct Object *glyphObject /*$s3*/, int size /*$s0*/, int glyphnum /*$s1*/, int enabled /*stack 16*/)
 // line 3197, offset 0x80046690
	/* begin block 1 */
		// Start line: 3198
		// Start offset: 0x80046690
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
			// Start offset: 0x800466D4
			// Variables:
		// 		struct Object *object; // $a0
		/* end block 1.1 */
		// End offset: 0x800466E8
		// End Line: 3214
	/* end block 1 */
	// End offset: 0x80046830
	// End Line: 3250

	/* begin block 2 */
		// Start line: 6394
	/* end block 2 */
	// End Line: 6395

void FX_MakeGlyphIcon(undefined4 param_1,Object *param_2,undefined4 param_3,int param_4)

{
  if (param_2 != (Object *)0x0) {
    if (param_4 != 7) {
                    /* WARNING: Subroutine does not return */
      FX_GetTextureObject(param_2,0,param_4);
    }
    if (DebugMenuLine_800c87c4.text != (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      FX_GetTextureObject((Object *)DebugMenuLine_800c87c4.text,0,0);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SoulDustProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 3253, offset 0x80046854
	/* begin block 1 */
		// Start line: 3254
		// Start offset: 0x80046854
		// Variables:
	// 		struct MATRIX *swTransform; // $v1
	// 		struct _Position position; // stack offset -24
	// 		long color; // stack offset -16
	// 		long black; // stack offset -12
	// 		int fade; // $a3
	/* end block 1 */
	// End offset: 0x800469F8
	// End Line: 3291

	/* begin block 2 */
		// Start line: 7956
	/* end block 2 */
	// End Line: 7957

void FX_SoulDustProcess(_FX_PRIM *param_1,_FXTracker *param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  
  if (param_1->work1 < 0x20) {
    FX_Die(param_1,param_2);
    return;
  }
  sVar2 = param_1->work2;
  iVar3 = *(int *)(*(int *)&param_1->duo + 0x40) + *(int *)((int)&param_1->duo + 4) * 0x20;
  (param_1->position).x = *(short *)(iVar3 + 0x14);
  sVar2 = (param_1->v1).x + sVar2;
  (param_1->position).y = *(short *)(iVar3 + 0x18);
  sVar1 = *(short *)(iVar3 + 0x1c);
  (param_1->v1).x = sVar2;
                    /* WARNING: Subroutine does not return */
  (param_1->position).z = sVar1;
  rcos((int)sVar2);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeSoulDust(struct _Instance *instance /*$s4*/, short segment /*$a1*/)
 // line 3292, offset 0x80046a08
	/* begin block 1 */
		// Start line: 3293
		// Start offset: 0x80046A08
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s1
	// 		struct SVECTOR location; // stack offset -32
	// 		struct Object *particle; // $s2
	/* end block 1 */
	// End offset: 0x80046C28
	// End Line: 3344

	/* begin block 2 */
		// Start line: 8084
	/* end block 2 */
	// End Line: 8085

void FX_MakeSoulDust(_Instance *instance,short segment)

{
                    /* WARNING: Subroutine does not return */
  rand();
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_WaterTrailProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 3367, offset 0x80046c48
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
 // line 3386, offset 0x80046d60
	/* begin block 1 */
		// Start line: 3387
		// Start offset: 0x80046D60
		// Variables:
	// 		struct Object *waterfx; // $a1
	// 		struct _Model *wxtrail; // $a0
	// 		struct _SVector position; // stack offset -48
	// 		int zvel; // $s0

		/* begin block 1.1 */
			// Start line: 3423
			// Start offset: 0x80046E6C
			// Variables:
		// 		int n; // $s2
		// 		int deg; // $s0
		// 		struct _SVector vel; // stack offset -40
		// 		struct _SVector accel; // stack offset -32
		// 		struct _SVector startpos; // stack offset -24

			/* begin block 1.1.1 */
				// Start line: 3431
				// Start offset: 0x80046E84
				// Variables:
			// 		int sinVal; // $s1
			// 		int cosVal; // $s0
			// 		int spd; // $v1
			/* end block 1.1.1 */
			// End offset: 0x80046F18
			// End Line: 3439
		/* end block 1.1 */
		// End offset: 0x80046F7C
		// End Line: 3444
	/* end block 1 */
	// End offset: 0x80046F7C
	// End Line: 3445

	/* begin block 2 */
		// Start line: 8277
	/* end block 2 */
	// End Line: 8278

void FX_MakeWaterTrail(_Instance *instance,int depth)

{
  int *piVar1;
  _FX_PRIM *fxPrim;
  MATRIX *y;
  _FXTracker *fxTracker;
  SVECTOR *in_a2;
  int in_a3;
  _FX_PRIM *p_Var2;
  SVECTOR local_30 [2];
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  short local_14;
  
  y = instance->matrix;
  if (y == (MATRIX *)0x0) {
    FX_MakeMannaIcon((int)instance,0,(int)in_a2,in_a3);
    return;
  }
  if (instance->oldMatrix == (MATRIX *)0x0) {
    FX_MakeMannaIcon((int)instance,(int)y,(int)in_a2,in_a3);
    return;
  }
  if (theCamera.core.vvNormalWorVecMat[0]._18_2_ == 1) {
    FX_MakeMannaIcon((int)instance,(int)y,(int)in_a2,in_a3);
    return;
  }
  if (theCamera.core.vvNormalWorVecMat[0].m[2][2] != 1000) {
    FX_MakeMannaIcon((int)instance,(int)y,(int)in_a2,in_a3);
    return;
  }
  local_30[0].vx = *(short *)y[1].t;
  local_30[0].vy = *(short *)(instance->matrix[1].t + 1);
  local_30[0].vz = (instance->splitPoint).z;
  fxPrim = (_FX_PRIM *)instance->matrix[1].t[2];
  p_Var2 = (_FX_PRIM *)((int)fxPrim - instance->oldMatrix[1].t[2]);
  fxTracker = (_FXTracker *)DebugMenuLine_800c8794.lower;
  if (DebugMenuLine_800c8794.lower != 0) {
    piVar1 = (int *)(DebugMenuLine_800c8794.lower + 0xc);
    *(uint *)(DebugMenuLine_800c8794.lower + 0x2c) =
         *(uint *)(DebugMenuLine_800c8794.lower + 0x2c) | 0x20000000;
    fxPrim = *(_FX_PRIM **)(*piVar1 + 4);
    in_a2 = local_30;
    fxTracker = (_FXTracker *)fxPrim->process;
    in_a3 = 0;
    FX_BuildSingleFaceWithModel
              ((_Model *)fxPrim,(_MFace *)fxTracker,in_a2,(SVECTOR *)0x0,(SVECTOR *)0x0,gFXT,
               FX_SimpleQuadSetup,FX_WaterTrailProcess,8);
  }
  if (-1 < (int)p_Var2) {
    FX_SoulDustProcess(fxPrim,fxTracker);
    return;
  }
  if (-(int)p_Var2 < 0x15) {
    FX_MakeMannaIcon((int)fxPrim,(int)fxTracker,(int)in_a2,in_a3);
    return;
  }
  local_1e = 0;
  local_20 = 0;
  local_1c = 0xfffe;
  local_14 = local_30[0].vz;
                    /* WARNING: Subroutine does not return */
  rand();
}



// decompiled code
// original method signature: 
// struct _FXRibbon * /*$ra*/ FX_StartRibbon(struct _Instance *instance /*$s7*/, short startSegment /*$s3*/, short endSegment /*stack -48*/, short type /*$fp*/, int ribbonLifeTime /*stack 16*/, int faceLifeTime /*stack 20*/, int startFadeValue /*stack 24*/, long startColor /*stack 28*/, long endColor /*stack 32*/)
 // line 3480, offset 0x80046f94
	/* begin block 1 */
		// Start line: 3481
		// Start offset: 0x80046F94
		// Variables:
	// 		struct MATRIX *swTransform; // $a0
	// 		struct _FXRibbon *ribbon; // $s0
	// 		int i; // $a2
	// 		int number; // $s1
	/* end block 1 */
	// End offset: 0x80047234
	// End Line: 3563

	/* begin block 2 */
		// Start line: 6960
	/* end block 2 */
	// End Line: 6961

_FXRibbon *
FX_StartRibbon(_Instance *instance,short startSegment,short endSegment,short type,int ribbonLifeTime
              ,int faceLifeTime,int startFadeValue,long startColor,long endColor)

{
  if (1 < ((int)endSegment - (int)startSegment) + 1) {
                    /* WARNING: Subroutine does not return */
    MEMPACK_Malloc(0x2c,'\r');
  }
  return (_FXRibbon *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_RibbonProcess(struct _FX_PRIM *fxPrim /*$a2*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 3584, offset 0x80047264
	/* begin block 1 */
		// Start line: 3585
		// Start offset: 0x80047264
		// Variables:
	// 		int d; // $a1
	// 		long fade; // $a3
	/* end block 1 */
	// End offset: 0x80047348
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
                    /* WARNING: Subroutine does not return */
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
 // line 3627, offset 0x80047358
	/* begin block 1 */
		// Start line: 8805
	/* end block 1 */
	// End Line: 8806

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FX_ConstrictProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  
  if (FX_ConstrictStage == 1) {
    theCamera.positionAccl._4_4_ = theCamera.positionAccl._4_4_ | 4;
    fxPrim->startColor = 0xffffff;
    sVar1 = fxPrim->work2;
    fxPrim->timeToLive = 0x28;
    fxPrim->fadeStep = 0x66;
    fxPrim->fadeValue[3] = 0;
    fxPrim->fadeValue[2] = 0;
    fxPrim->fadeValue[1] = 0;
    fxPrim->fadeValue[0] = 0;
    fxPrim->work1 = 0x380;
    fxPrim->work0 = 0x380;
    fxPrim->work1 = 0;
    if (sVar1 != 0) {
      sVar1 = (fxPrim->v2).y;
      fxPrim->fadeValue[1] = 0x1000;
      fxPrim->fadeValue[0] = 0x1000;
      fxPrim->fadeValue[3] = 0;
      fxPrim->fadeValue[2] = 0;
                    /* WARNING: Subroutine does not return */
      ratan2((int)sVar1 - (int)_CHAR____800d1596,(int)(fxPrim->v2).x - (int)_FX_ConstrictPosition);
    }
    sVar1 = (fxPrim->v0).y;
    fxPrim->fadeValue[1] = 0;
    fxPrim->fadeValue[0] = 0;
    fxPrim->fadeValue[3] = 0x1000;
    fxPrim->fadeValue[2] = 0x1000;
                    /* WARNING: Subroutine does not return */
    ratan2((int)sVar1 - (int)_CHAR____800d1596,(int)(fxPrim->v0).x - (int)_FX_ConstrictPosition);
  }
  if ((fxPrim->work0 < 1) && (fxPrim->work1 < 1)) {
    FX_RibbonProcess(fxPrim,fxTracker);
    return;
  }
  fxPrim->work0 = fxPrim->work0 + -0x28;
  sVar1 = fxPrim->work2 + -0x40;
                    /* WARNING: Subroutine does not return */
  fxPrim->work2 = sVar1;
  rcos((int)sVar1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartConstrict(struct _Instance *instance /*$a0*/, struct _SVector *constrict_point /*$a1*/, short startSegment /*$a2*/, short endSegment /*$a3*/)
 // line 3696, offset 0x800475fc
	/* begin block 1 */
		// Start line: 8988
	/* end block 1 */
	// End Line: 8989

	/* begin block 2 */
		// Start line: 8989
	/* end block 2 */
	// End Line: 8990

void FX_StartConstrict(_Instance *param_1,undefined2 *param_2,short param_3,short param_4)

{
  if (p_Gpffff90b4 == (_FXRibbon *)0x0) {
    if (param_2 != (undefined2 *)0x0) {
      uGpffffbae0 = *param_2;
      uGpffffbae2 = param_2[1];
      sGpffffbae4 = (param_1->position).z + 0x100;
      puGpffffbae8 = param_2;
    }
    p_Gpffff90b4 = FX_StartRibbon(param_1,param_3,param_4,2,-1,0x28,0,0xe84040,0xe84040);
    uGpffff90b8 = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_EndConstrict(int ConstrictEnemyFlag /*$a0*/, struct _Instance *instance /*$a1*/)
 // line 3713, offset 0x8004768c
	/* begin block 1 */
		// Start line: 3714
		// Start offset: 0x8004768C

		/* begin block 1.1 */
			// Start line: 3721
			// Start offset: 0x800476AC
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x800476AC
		// End Line: 3721

		/* begin block 1.2 */
			// Start line: 3725
			// Start offset: 0x800476B8
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.2 */
		// End offset: 0x800476DC
		// End Line: 3725
	/* end block 1 */
	// End offset: 0x800476DC
	// End Line: 3729

	/* begin block 2 */
		// Start line: 9026
	/* end block 2 */
	// End Line: 9027

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FX_EndConstrict(int ConstrictEnemyFlag,_Instance *instance)

{
  _Position *p_Var1;
  
  if (ConstrictEnemyFlag != 0) {
    FX_ConstrictStage = 1;
    if (instance == (_Instance *)0x0) {
      _FX_ConstrictPosition = _FX_ConstrictPositionPtr->x;
      p_Var1 = _FX_ConstrictPositionPtr;
    }
    else {
      _FX_ConstrictPosition = (instance->position).x;
      p_Var1 = &instance->position;
    }
    _CHAR____800d1596 = p_Var1->y;
    _CHAR____800d1598 = p_Var1->z;
    FX_ConstrictInstance = instance;
  }
  FX_DeleteGeneralEffect((_FXGeneralEffect *)FX_ConstrictRibbon);
  FX_ConstrictRibbon = (_FXRibbon *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SubDividePrim(struct _FX_PRIM *fxPrim1 /*$s0*/, struct _FX_PRIM *fxPrim2 /*$s1*/)
 // line 3733, offset 0x800476f8
	/* begin block 1 */
		// Start line: 3734
		// Start offset: 0x800476F8
		// Variables:
	// 		struct SVECTOR mp0; // stack offset -32
	// 		struct SVECTOR mp1; // stack offset -24
	/* end block 1 */
	// End offset: 0x800476F8
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
 // line 3781, offset 0x800477bc
	/* begin block 1 */
		// Start line: 3782
		// Start offset: 0x800477BC
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
			// Start offset: 0x80047C38
			// Variables:
		// 		int fade; // $v1
		/* end block 1.1 */
		// End offset: 0x80047CD4
		// End Line: 3933
	/* end block 1 */
	// End offset: 0x80047D5C
	// End Line: 3948

	/* begin block 2 */
		// Start line: 9166
	/* end block 2 */
	// End Line: 9167

/* WARNING: Could not reconcile some variable overlaps */

void FX_ContinueRibbon(_FXGeneralEffect *param_1,_FXTracker *param_2)

{
  _FX_PRIM *p_Var1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  _FX_PRIM *fxPrim1;
  void *pvVar6;
  code *pcVar7;
  _FX_PRIM *fxPrim2;
  _FX_PRIM *p_Var8;
  _FX_PRIM *p_Var9;
  short sVar10;
  MATRIX *pMVar11;
  _FX_PRIM *p_Var12;
  int iVar13;
  long *plVar14;
  int iVar15;
  NodeType *pNVar16;
  TextureMT3 *pTVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  long lVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  int iVar23;
  int iVar24;
  undefined4 uStack80;
  undefined4 uStack76;
  short sStack68;
  short sStack60;
  undefined4 uStack56;
  undefined4 uStack52;
  
  if ((param_1 != (_FXGeneralEffect *)0x0) &&
     (pMVar11 = param_1->instance->matrix, pMVar11 != (MATRIX *)0x0)) {
    iVar15 = (int)*(short *)((int)&param_1[1].next + 2);
    pMVar11 = pMVar11 + *(short *)&param_1[1].instance;
    if (iVar15 == -1) {
      *(undefined2 *)((int)&param_1[1].next + 2) = 0;
    }
    iVar2 = (uint)*(ushort *)&param_1[1].next << 0x10;
    iVar2 = (iVar2 >> 0x10) - (iVar2 >> 0x1f) >> 1;
    if (param_1->type == '\x01') {
      iVar3 = (int)*(short *)((int)&param_1[1].next + 2);
      iVar24 = iVar3 + iVar2;
      plVar14 = pMVar11->t + 2;
      while (iVar3 < iVar24) {
        iVar13 = iVar3 * 8;
        iVar3 = iVar3 + 1;
        *(undefined2 *)(iVar13 + (int)param_1[1].continue_process) = *(undefined2 *)(plVar14 + -2);
        *(undefined2 *)((int)param_1[1].continue_process + iVar13 + 2) =
             *(undefined2 *)(plVar14 + -1);
        *(undefined2 *)((int)param_1[1].continue_process + iVar13 + 4) = *(undefined2 *)plVar14;
        *(short *)((int)&param_1[1].next + 2) = *(short *)((int)&param_1[1].next + 2) + 1;
        plVar14 = plVar14 + 8;
      }
    }
    else {
      iVar24 = (int)*(short *)((int)&param_1[1].next + 2);
      iVar3 = iVar24 * 8;
      *(undefined2 *)(iVar3 + (int)param_1[1].continue_process) = *(undefined2 *)pMVar11->t;
      *(undefined2 *)((int)param_1[1].continue_process + iVar3 + 2) =
           *(undefined2 *)(pMVar11->t + 1);
      *(undefined2 *)((int)param_1[1].continue_process + iVar3 + 4) =
           *(undefined2 *)(pMVar11->t + 2);
      pMVar11 = param_1->instance->matrix + *(short *)((int)&param_1[1].instance + 2);
      iVar3 = (iVar24 + 1) * 8;
      *(undefined2 *)(iVar3 + (int)param_1[1].continue_process) = *(undefined2 *)pMVar11->t;
      *(undefined2 *)((int)param_1[1].continue_process + iVar3 + 2) =
           *(undefined2 *)(pMVar11->t + 1);
      *(undefined2 *)((int)param_1[1].continue_process + iVar3 + 4) =
           *(undefined2 *)(pMVar11->t + 2);
      *(short *)((int)&param_1[1].next + 2) = *(short *)((int)&param_1[1].next + 2) + 2;
    }
    iVar3 = (int)*(short *)((int)&param_1[1].next + 2);
    if (*(short *)&param_1[1].next <= iVar3) {
      *(undefined2 *)((int)&param_1[1].next + 2) = 0;
    }
    if (iVar15 == -1) {
      return;
    }
    if ((((param_1->instance->flags & 0x800U) == 0) &&
        ((param_1->instance->flags2 & 0x4000000U) == 0)) && (iVar15 < iVar3 + -1)) {
      iVar24 = iVar15 << 3;
      do {
        iVar13 = iVar15 - iVar2;
        if (iVar13 < 0) {
          iVar13 = iVar13 + *(short *)&param_1[1].next;
        }
        puVar4 = (undefined4 *)(iVar24 + (int)param_1[1].continue_process);
        puVar5 = (undefined4 *)(iVar13 * 8 + (int)param_1[1].continue_process);
        uVar18 = *puVar5;
        uVar21 = puVar5[1];
        iVar23 = 0;
        pvVar6 = (void *)(iVar13 * 8 + (int)param_1[1].continue_process);
        uVar19 = *(undefined4 *)((int)pvVar6 + 8);
        uVar22 = *(undefined4 *)((int)pvVar6 + 0xc);
        iVar13 = iVar24 + (int)param_1[1].continue_process;
        uStack80 = *puVar4;
        uStack76 = puVar4[1];
        uStack56 = *(undefined4 *)(iVar13 + 8);
        uStack52 = *(undefined4 *)(iVar13 + 0xc);
        do {
          fxPrim1 = FX_GetPrim(param_2);
          if (fxPrim1 != (_FX_PRIM *)0x0) {
            (fxPrim1->position).x = *(short *)(iVar24 + (int)param_1[1].continue_process);
            (fxPrim1->position).y = *(short *)((int)param_1[1].continue_process + iVar24 + 2);
            (fxPrim1->position).z = *(short *)((int)param_1[1].continue_process + iVar24 + 4);
            *(undefined4 *)&fxPrim1->v0 = uStack80;
            (fxPrim1->v0).z = (short)uStack76;
            sStack68 = (short)uVar21;
            *(undefined4 *)&fxPrim1->v1 = uVar18;
            (fxPrim1->v1).z = sStack68;
            sStack60 = (short)uVar22;
            *(undefined4 *)&fxPrim1->v3 = uVar19;
            (fxPrim1->v3).z = sStack60;
            *(undefined4 *)&fxPrim1->v2 = uStack56;
            (fxPrim1->v2).z = (short)uStack52;
            fxPrim1->fadeValue[0] = *(short *)&param_1[2].instance;
            fxPrim1->fadeValue[1] = *(short *)&param_1[2].instance;
            fxPrim1->fadeValue[2] =
                 *(short *)&param_1[2].instance + *(short *)((int)&param_1[2].instance + 2);
            fxPrim1->fadeValue[3] =
                 *(short *)&param_1[2].instance + *(short *)((int)&param_1[2].instance + 2);
            sVar10 = *(short *)((int)&param_1[2].instance + 2);
            fxPrim1->flags = fxPrim1->flags & 0xfffffffeU | 0x90008;
            fxPrim1->fadeStep = sVar10;
            fxPrim1->color = *(long *)&param_1[1].effectType;
            fxPrim1->startColor = *(long *)&param_1[1].effectType;
            pvVar6 = param_1[2].next;
            fxPrim1->colorFadeValue = 0;
            *(void **)&fxPrim1->endColor = pvVar6;
            fxPrim1->colorFadeStep = *(short *)&param_1[2].continue_process;
            if (param_1->type == '\x02') {
              pcVar7 = FX_ConstrictProcess;
            }
            else {
              pcVar7 = FX_RibbonProcess;
            }
            *(code **)&fxPrim1->process = pcVar7;
            fxPrim1->timeToLive = *(short *)((int)&param_1[2].continue_process + 2);
            LIST_InsertFunc(&param_2->usedPrimList,(NodeType *)fxPrim1);
            fxPrim2 = FX_GetPrim(param_2);
            if (fxPrim2 != (_FX_PRIM *)0x0) {
              p_Var9 = fxPrim1;
              p_Var1 = fxPrim2;
              do {
                p_Var12 = p_Var1;
                p_Var8 = p_Var9;
                pNVar16 = (p_Var8->node).next;
                pTVar17 = p_Var8->texture;
                lVar20 = p_Var8->flags;
                (p_Var12->node).prev = (p_Var8->node).prev;
                (p_Var12->node).next = pNVar16;
                p_Var12->texture = pTVar17;
                p_Var12->flags = lVar20;
                p_Var9 = (_FX_PRIM *)&p_Var8->timeToLive;
                p_Var1 = (_FX_PRIM *)&p_Var12->timeToLive;
              } while (p_Var9 != (_FX_PRIM *)((int)&fxPrim1->duo + 4));
              pvVar6 = p_Var8->process;
              (((_FX_PRIM *)&p_Var12->timeToLive)->node).prev = (p_Var9->node).prev;
              p_Var12->process = pvVar6;
              FX_SubDividePrim(fxPrim1,fxPrim2);
              sVar10 = 0x1000;
              if (param_1->type == '\x02') {
                sVar10 = 0x800;
                fxPrim2->work0 = 0;
                fxPrim1->work0 = 0;
                fxPrim2->work1 = 0;
                fxPrim1->work1 = 0;
                fxPrim1->work2 = 1;
                fxPrim2->work2 = 0;
              }
              fxPrim1->fadeValue[0] = sVar10;
              fxPrim1->fadeValue[1] = sVar10;
              fxPrim2->fadeValue[2] = sVar10;
              fxPrim2->fadeValue[3] = sVar10;
              LIST_InsertFunc(&param_2->usedPrimList,(NodeType *)fxPrim2);
            }
          }
          iVar23 = iVar23 + 0x1000;
          uStack80 = uVar18;
          uStack76 = uVar21;
          uStack56 = uVar19;
          uStack52 = uVar22;
        } while (iVar23 < 0x1000);
        iVar15 = iVar15 + 1;
        iVar24 = iVar24 + 8;
      } while (iVar15 < iVar3 + -1);
    }
  }
  sVar10 = param_1->lifeTime;
  if ((0 < param_1->lifeTime) && (param_1->lifeTime = sVar10 + -1, sVar10 == 1)) {
    FX_DeleteGeneralEffect(param_1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StandardFXPrimProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$a3*/)
 // line 3953, offset 0x80047d8c
	/* begin block 1 */
		// Start line: 3954
		// Start offset: 0x80047D8C
		// Variables:
	// 		long flags; // $a2

		/* begin block 1.1 */
			// Start line: 3969
			// Start offset: 0x80047DD8
			// Variables:
		// 		long start; // stack offset -16
		// 		long end; // stack offset -12
		/* end block 1.1 */
		// End offset: 0x80047EBC
		// End Line: 3984

		/* begin block 1.2 */
			// Start line: 3988
			// Start offset: 0x80047EC8
			// Variables:
		// 		int current_scale; // $v1
		/* end block 1.2 */
		// End offset: 0x80047EF8
		// End Line: 3998

		/* begin block 1.3 */
			// Start line: 4003
			// Start offset: 0x80047F00
			// Variables:
		// 		struct MATRIX *swTransform; // $v1
		/* end block 1.3 */
		// End offset: 0x80047F00
		// End Line: 4004

		/* begin block 1.4 */
			// Start line: 4173
			// Start offset: 0x8004808C
			// Variables:
		// 		struct _Rotation rot; // stack offset -24
		/* end block 1.4 */
		// End offset: 0x800480EC
		// End Line: 4181
	/* end block 1 */
	// End offset: 0x800480EC
	// End Line: 4190

	/* begin block 2 */
		// Start line: 9745
	/* end block 2 */
	// End Line: 9746

void FX_StandardFXPrimProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  _FX_MATRIX *p_Var5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  
  sVar3 = fxPrim->timeToLive;
  if (0 < sVar3) {
    fxPrim->timeToLive = fxPrim->timeToLive + -1;
    sVar3 = fxPrim->timeToLive;
  }
  if (sVar3 == 0) {
LAB_80047ee0:
    FX_Die(fxPrim,fxTracker);
  }
  else {
    uVar8 = fxPrim->flags;
    if ((uVar8 & 0x40000) != 0) {
      uVar6 = fxPrim->startColor;
      uVar7 = fxPrim->endColor;
      sVar3 = fxPrim->fadeValue[0] + fxPrim->fadeStep;
      fxPrim->fadeValue[0] = sVar3;
      if (0x1000 < sVar3) {
        fxPrim->fadeValue[0] = 0x1000;
      }
      setCopReg(2,0x4000,0x1000 - (int)fxPrim->fadeValue[0]);
      setCopReg(2,0x4800,uVar6 & 0xff);
      setCopReg(2,0x5000,uVar6 >> 8 & 0xff);
      setCopReg(2,0x5800,uVar6 >> 0x10 & 0xff);
      copFunction(2,0x198003d);
      setCopReg(2,0x4000,(uint)(ushort)fxPrim->fadeValue[0]);
      setCopReg(2,0x4800,uVar7 & 0xff);
      setCopReg(2,0x5000,uVar7 >> 8 & 0xff);
      setCopReg(2,0x5800,uVar7 >> 0x10 & 0xff);
      copFunction(2,0x1a8003e);
      uVar9 = getCopReg(2,0x4800);
      uVar10 = getCopReg(2,0x5000);
      uVar11 = getCopReg(2,0x5800);
      *(char *)&fxPrim->color = (char)uVar9;
      *(undefined *)((int)&fxPrim->color + 1) = (char)uVar10;
      *(undefined *)((int)&fxPrim->color + 2) = (char)uVar11;
      if ((uVar8 & 1) != 0) {
        fxPrim->color = fxPrim->color & 0x3ffffffU | 0x2c000000;
      }
    }
    if ((uVar8 & 0x2000) != 0) {
      iVar4 = (int)(fxPrim->v0).y - (int)fxPrim->work3;
      if (iVar4 < 1) goto LAB_80047ee0;
      (fxPrim->v0).y = (short)iVar4;
    }
    if ((uVar8 & 0x20) == 0) {
      if ((uVar8 & 2) == 0) {
        sVar3 = *(short *)((int)&fxPrim->duo + 8);
        sVar1 = *(short *)((int)&fxPrim->duo + 10);
        *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + *(short *)((int)&fxPrim->duo + 6);
        *(short *)((int)&fxPrim->duo + 2) = *(short *)((int)&fxPrim->duo + 2) + sVar3;
        *(short *)((int)&fxPrim->duo + 4) = *(short *)((int)&fxPrim->duo + 4) + sVar1;
        if ((uVar8 & 0x1000000) == 0) {
          sVar3 = *(short *)((int)&fxPrim->duo + 2);
          sVar1 = *(short *)((int)&fxPrim->duo + 4);
          (fxPrim->position).x = (fxPrim->position).x + *(short *)&fxPrim->duo;
          (fxPrim->position).y = (fxPrim->position).y + sVar3;
          (fxPrim->position).z = (fxPrim->position).z + sVar1;
        }
        else {
          sVar3 = *(short *)&fxPrim->duo;
          (fxPrim->v0).x = (fxPrim->v0).x + sVar3;
          sVar1 = (fxPrim->v0).y;
          sVar2 = *(short *)((int)&fxPrim->duo + 2);
          (fxPrim->v1).x = (fxPrim->v1).x + sVar3;
          (fxPrim->v0).y = sVar1 + sVar2;
          sVar3 = (fxPrim->v0).z;
          sVar1 = *(short *)((int)&fxPrim->duo + 4);
          (fxPrim->v1).y = (fxPrim->v1).y + sVar2;
          (fxPrim->v0).z = sVar3 + sVar1;
          (fxPrim->v1).z = (fxPrim->v1).z + sVar1;
        }
        if (((uVar8 & 0x100) != 0) && ((fxPrim->position).z <= fxPrim->work0)) {
          uVar6 = fxPrim->flags;
          (fxPrim->position).z = fxPrim->work0;
          fxPrim->flags = uVar6 | 2;
        }
      }
    }
    else {
      iVar4 = *(int *)(*(int *)&fxPrim->duo + 0x40) + *(int *)((int)&fxPrim->duo + 4) * 0x20;
      (fxPrim->position).x = *(short *)(iVar4 + 0x14);
      (fxPrim->position).y = *(short *)(iVar4 + 0x18);
      (fxPrim->position).z = *(short *)(iVar4 + 0x1c);
    }
    if (((((uVar8 & 0x8000000) == 0) && (p_Var5 = fxPrim->matrix, p_Var5 != (_FX_MATRIX *)0x0)) &&
        ((p_Var5->flags & 2U) == 0)) && (p_Var5->flags = p_Var5->flags | 2, (uVar8 & 0x80) != 0)) {
                    /* WARNING: Subroutine does not return */
      RotMatrixX((int)*(char *)((int)&fxPrim->work2 + 1) << 2,(int)&fxPrim->matrix->lwTransform);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_AttachedParticlePrimProcess(struct _FX_PRIM *fxPrim /*$a2*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 4192, offset 0x800480fc
	/* begin block 1 */
		// Start line: 4193
		// Start offset: 0x800480FC
		// Variables:
	// 		struct MATRIX *swTransform; // $a3
	// 		struct MATRIX *swTransformOld; // $t0
	// 		struct _Instance *instance; // $v1
	/* end block 1 */
	// End offset: 0x80048178
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
 // line 4210, offset 0x80048190
	/* begin block 1 */
		// Start line: 4211
		// Start offset: 0x80048190
		// Variables:
	// 		struct MATRIX *swTransform; // $a0
	// 		struct MATRIX *swTransformOld; // $a2
	// 		struct _Instance *instance; // $v0
	// 		struct _SVector movement; // stack offset -16
	// 		int total; // $a0
	/* end block 1 */
	// End offset: 0x80048354
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
 // line 4256, offset 0x80048364
	/* begin block 1 */
		// Start line: 4257
		// Start offset: 0x80048364

		/* begin block 1.1 */
			// Start line: 4257
			// Start offset: 0x80048364
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _Position *_v0; // $v0
		/* end block 1.1 */
		// End offset: 0x80048364
		// End Line: 4257
	/* end block 1 */
	// End offset: 0x80048444
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
 // line 4302, offset 0x8004844c
	/* begin block 1 */
		// Start line: 4303
		// Start offset: 0x8004844C
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	/* end block 1 */
	// End offset: 0x80048584
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
 // line 4336, offset 0x800485b8
	/* begin block 1 */
		// Start line: 4337
		// Start offset: 0x800485B8
		// Variables:
	// 		int i; // $s0

		/* begin block 1.1 */
			// Start line: 4342
			// Start offset: 0x800485F4
			// Variables:
		// 		struct _SVector vel; // stack offset -40
		/* end block 1.1 */
		// End offset: 0x80048680
		// End Line: 4346
	/* end block 1 */
	// End offset: 0x800486D0
	// End Line: 4349

	/* begin block 2 */
		// Start line: 10588
	/* end block 2 */
	// End Line: 10589

void FX_Blood(_SVector *location,_SVector *input_vel,_SVector *accel,int amount,long color,long size
             )

{
  if (amount != 0) {
                    /* WARNING: Subroutine does not return */
    rand();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Blood2(struct _SVector *location /*$a0*/, struct _SVector *input_vel /*$a1*/, struct _SVector *accel /*$a2*/, int amount /*$a3*/, long color /*stack 16*/, long dummyCrapShouldRemove /*stack 20*/)
 // line 4351, offset 0x800486f4
	/* begin block 1 */
		// Start line: 10625
	/* end block 1 */
	// End Line: 10626

void FX_StandardFXPrimProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  _SVector *in_a2;
  int in_a3;
  long in_stack_00000010;
  
  FX_Blood((_SVector *)fxPrim,(_SVector *)fxTracker,in_a2,in_a3,in_stack_00000010,4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Blood_Impale(struct _Instance *locinst /*$a0*/, short locseg /*$a1*/, struct _Instance *instance /*$a2*/, short segment /*$a3*/)
 // line 4383, offset 0x80048720
	/* begin block 1 */
		// Start line: 4384
		// Start offset: 0x80048720
		// Variables:
	// 		struct _SVector location; // stack offset -40
	// 		struct _SVector accel; // stack offset -32
	// 		struct _SVector vel; // stack offset -24
	// 		struct _SVector input_vel; // stack offset -16
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x800488DC
	// End Line: 4409

	/* begin block 2 */
		// Start line: 8766
	/* end block 2 */
	// End Line: 8767

void FX_Blood_Impale(_Instance *locinst,short locseg,_Instance *instance,short segment)

{
                    /* WARNING: Subroutine does not return */
  rand();
}



// decompiled code
// original method signature: 
// struct _FXParticle * /*$ra*/ FX_BloodCone(struct _Instance *instance /*$a0*/, short startSegment /*$a1*/, long time /*$s2*/)
 // line 4415, offset 0x800488ec
	/* begin block 1 */
		// Start line: 4416
		// Start offset: 0x800488EC
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	// 		struct Object *particle; // $s1
	/* end block 1 */
	// End offset: 0x800489A0
	// End Line: 4444

	/* begin block 2 */
		// Start line: 10745
	/* end block 2 */
	// End Line: 10746

_FXParticle * FX_BloodCone(_Instance *instance,short startSegment,long time)

{
  char *object;
  _FXParticle *p_Var1;
  
  object = DebugMenuLine_800c87c4.text;
  if (DebugMenuLine_800c87c4.text == (char *)0x0) {
    p_Var1 = (_FXParticle *)0x0;
  }
  else {
    p_Var1 = FX_GetParticle(instance,startSegment);
    if (p_Var1 != (_FXParticle *)0x0) {
                    /* WARNING: Subroutine does not return */
      p_Var1->size = 0xe;
      FX_GetTextureObject((Object *)object,0,1);
    }
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct _FXParticle * /*$ra*/ FX_GetTorchParticle(struct _Instance *instance /*$s1*/, short startSegment /*$a1*/, int tex /*$s2*/, int birthRadius /*$s3*/, int num /*stack 16*/)
 // line 4447, offset 0x800489b8
	/* begin block 1 */
		// Start line: 4448
		// Start offset: 0x800489B8
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	/* end block 1 */
	// End offset: 0x80048A7C
	// End Line: 4472

	/* begin block 2 */
		// Start line: 10838
	/* end block 2 */
	// End Line: 10839

_FXParticle *
FX_GetTorchParticle(_Instance *instance,short startSegment,int tex,int birthRadius,int num)

{
  _FXParticle *p_Var1;
  
  p_Var1 = FX_GetParticle(instance,startSegment);
  if (p_Var1 != (_FXParticle *)0x0) {
    p_Var1->type = '\x01';
    *(code **)&p_Var1->fxprim_process = FX_FlamePrimProcess;
                    /* WARNING: Subroutine does not return */
    FX_GetTextureObject(instance->object,1,tex);
  }
  return (_FXParticle *)0x0;
}



// decompiled code
// original method signature: 
// struct _FXParticle * /*$ra*/ FX_TorchFlame(struct _Instance *instance /*$s2*/, short startSegment /*$a1*/)
 // line 4475, offset 0x80048a9c
	/* begin block 1 */
		// Start line: 4476
		// Start offset: 0x80048A9C
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	// 		struct Object *particle; // $s3
	/* end block 1 */
	// End offset: 0x80048BD8
	// End Line: 4524

	/* begin block 2 */
		// Start line: 10917
	/* end block 2 */
	// End Line: 10918

_FXParticle * FX_TorchFlame(_Instance *instance,short startSegment)

{
  char *object;
  _FXParticle *p_Var1;
  
  object = DebugMenuLine_800c87c4.text;
  p_Var1 = (_FXParticle *)0x0;
  if (DebugMenuLine_800c87c4.text != (char *)0x0) {
    p_Var1 = FX_GetTorchParticle(instance,startSegment,0,0x10,-5);
    if (p_Var1 != (_FXParticle *)0x0) {
      (p_Var1->direction).x = 0x30;
      (p_Var1->direction).y = 0x20;
      (p_Var1->direction).z = 0x38;
    }
    p_Var1 = FX_GetTorchParticle(instance,startSegment,1,8,-1);
    if (p_Var1 != (_FXParticle *)0x0) {
      (p_Var1->direction).x = 0x18;
      (p_Var1->direction).y = 0x10;
      (p_Var1->direction).z = 0x10;
    }
    p_Var1 = FX_GetParticle(instance,startSegment);
    if (p_Var1 != (_FXParticle *)0x0) {
                    /* WARNING: Subroutine does not return */
      p_Var1->size = 10;
      FX_GetTextureObject((Object *)object,0,1);
    }
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ FX_GetMorphFadeVal()
 // line 4526, offset 0x80048bf8
	/* begin block 1 */
		// Start line: 4528
		// Start offset: 0x80048BF8
		// Variables:
	// 		int fade; // $a0
	/* end block 1 */
	// End offset: 0x80048C30
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
  
  iVar1 = ((int)theCamera.core.vvNormalWorVecMat[0].m[2][2] << 0xc) / 1000;
  if (theCamera.core.vvNormalWorVecMat[0]._18_2_ == 1) {
    iVar1 = 0x1000 - iVar1;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ConvertCamPersToWorld(struct SVECTOR *campos /*$s0*/, struct SVECTOR *worldpos /*$s1*/)
 // line 4550, offset 0x80048c38
	/* begin block 1 */
		// Start line: 11098
	/* end block 1 */
	// End Line: 11099

void FX_ConvertCamPersToWorld(void)

{
  SetRotMatrix(puGpffffa450);
                    /* WARNING: Subroutine does not return */
  SetTransMatrix((int)puGpffffa450);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_GetRandomScreenPt(struct SVECTOR *point /*$s0*/)
 // line 4570, offset 0x80048d50
	/* begin block 1 */
		// Start line: 11148
	/* end block 1 */
	// End Line: 11149

void FX_GetRandomScreenPt(void)

{
                    /* WARNING: Subroutine does not return */
  rand();
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ProcessSnow(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$s1*/)
 // line 4577, offset 0x80048ddc
	/* begin block 1 */
		// Start line: 4578
		// Start offset: 0x80048DDC

		/* begin block 1.1 */
			// Start line: 4581
			// Start offset: 0x80048E00
			// Variables:
		// 		struct SVECTOR position; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x80048E48
		// End Line: 4597
	/* end block 1 */
	// End offset: 0x80048EFC
	// End Line: 4611

	/* begin block 2 */
		// Start line: 11162
	/* end block 2 */
	// End Line: 11163

void FX_ProcessSnow(_FX_PRIM *param_1,_FXTracker *param_2)

{
  if (param_1->work0 == 9999) {
    if (((sGpffffb502 == 1) || (sGpffffb500 != 1000)) || (sGpffff90c0 == 0)) goto LAB_80048e70;
    param_1->work0 = 0;
    FX_GetRandomScreenPt();
    FX_ConvertCamPersToWorld();
  }
  if (0 < param_1->timeToLive) {
    param_1->timeToLive = param_1->timeToLive + -1;
  }
  if (param_1->timeToLive != 0) {
                    /* WARNING: Subroutine does not return */
    rand();
  }
LAB_80048e70:
  FX_Die(param_1,param_2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueSnow(struct _FXTracker *fxTracker /*$s1*/)
 // line 4613, offset 0x80048f10
	/* begin block 1 */
		// Start line: 4614
		// Start offset: 0x80048F10
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	// 		struct SVECTOR position; // stack offset -40
	// 		struct SVECTOR vel; // stack offset -32

		/* begin block 1.1 */
			// Start line: 4631
			// Start offset: 0x80048F8C
			// Variables:
		// 		struct SVECTOR campos; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x80049054
		// End Line: 4653
	/* end block 1 */
	// End offset: 0x80049054
	// End Line: 4655

	/* begin block 2 */
		// Start line: 11236
	/* end block 2 */
	// End Line: 11237

void FX_ContinueSnow(_FXTracker *fxTracker)

{
  if (theCamera.core.vvNormalWorVecMat[0].m[2][2] == 1000) {
    if (theCamera.core.vvNormalWorVecMat[0]._18_2_ == 1) {
      return;
    }
  }
  else {
    if (theCamera.core.vvNormalWorVecMat[0]._18_2_ == 0) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  rand();
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdateWind(struct _FXTracker *fxTracker /*$a0*/)
 // line 4657, offset 0x80049068
	/* begin block 1 */
		// Start line: 4658
		// Start offset: 0x80049068
		// Variables:
	// 		short change; // $s0
	/* end block 1 */
	// End offset: 0x800491C4
	// End Line: 4675

	/* begin block 2 */
		// Start line: 11335
	/* end block 2 */
	// End Line: 11336

void FX_UpdateWind(_FXTracker *fxTracker)

{
                    /* WARNING: Subroutine does not return */
  rand();
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ProcessRain(struct _FX_PRIM *fxPrim /*$a2*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 4682, offset 0x800491e0
	/* begin block 1 */
		// Start line: 4683
		// Start offset: 0x800491E0
		// Variables:
	// 		int zvel; // $a3
	/* end block 1 */
	// End offset: 0x800492A0
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
  
  sVar4 = *(short *)((int)&fxPrim->duo + 4) + (short)midiControlFunction;
  if (0 < fxPrim->timeToLive) {
    fxPrim->timeToLive = fxPrim->timeToLive + -1;
  }
  sVar1 = fxPrim->work0;
  sVar3 = (fxPrim->v1).z + sVar4;
  (fxPrim->v1).z = sVar3;
  if (sVar3 <= sVar1) {
    FX_ConvertCamPersToWorld((SVECTOR *)fxPrim,(SVECTOR *)fxTracker);
    return;
  }
  if (fxPrim->timeToLive == 0) {
    FX_Die(fxPrim,fxTracker);
  }
  else {
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
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueRain(struct _FXTracker *fxTracker /*$s7*/)
 // line 4707, offset 0x800492b0
	/* begin block 1 */
		// Start line: 4708
		// Start offset: 0x800492B0
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
			// Start offset: 0x800493F8
			// Variables:
		// 		struct _SVector worldpos; // stack offset -48
		// 		int zvel; // $s3
		/* end block 1.1 */
		// End offset: 0x800495AC
		// End Line: 4796
	/* end block 1 */
	// End offset: 0x800495BC
	// End Line: 4798

	/* begin block 2 */
		// Start line: 11452
	/* end block 2 */
	// End Line: 11453

void FX_ContinueRain(_FXTracker *fxTracker)

{
  int iVar1;
  
  if (theCamera.core.vvNormalWorVecMat[0]._16_4_ == 0x103e8) {
    return;
  }
  if (theCamera.core.vvNormalWorVecMat[0].m[2][2] == 1000) {
    if ((current_rain_fade < 0x1000) &&
       (iVar1 = (uint)(ushort)current_rain_fade + ((uint)theCamera.tiltList[0][0] >> 7),
       current_rain_fade = (short)iVar1, 0x1000 < iVar1 * 0x10000 >> 0x10)) {
      current_rain_fade = 0x1000;
    }
  }
  else {
    FX_GetMorphFadeVal();
  }
                    /* WARNING: Subroutine does not return */
  STREAM_GetLevelWithID(*(long *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x38));
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeSpark(struct _Instance *instance /*$a0*/, struct _Model *model /*$a1*/, int segment /*$a2*/)
 // line 4803, offset 0x800495e8
	/* begin block 1 */
		// Start line: 4804
		// Start offset: 0x800495E8
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	// 		struct Object *particle; // $s1
	/* end block 1 */
	// End offset: 0x80049690
	// End Line: 4833

	/* begin block 2 */
		// Start line: 11768
	/* end block 2 */
	// End Line: 11769

void FX_MakeSpark(_Instance *instance,_Model *model,int segment)

{
  char *object;
  _FXParticle *p_Var1;
  
  object = DebugMenuLine_800c87c4.text;
  if ((DebugMenuLine_800c87c4.text != (char *)0x0) &&
     (p_Var1 = FX_GetParticle(instance,(short)segment), p_Var1 != (_FXParticle *)0x0)) {
    p_Var1->size = 0x30;
    p_Var1->birthRadius = 0x32;
    (p_Var1->direction).x = 0x80;
    (p_Var1->direction).y = 0x80;
    (p_Var1->direction).z = 0xa0;
    (p_Var1->acceleration).x = 0;
    (p_Var1->acceleration).y = 0;
                    /* WARNING: Subroutine does not return */
    (p_Var1->acceleration).z = 1;
    FX_GetTextureObject((Object *)object,0,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueParticle(struct _FXParticle *currentParticle /*$s2*/, struct _FXTracker *fxTracker /*stack 4*/)
 // line 4835, offset 0x800496a4
	/* begin block 1 */
		// Start line: 4836
		// Start offset: 0x800496A4
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
			// Start offset: 0x80049C20
			// Variables:
		// 		int tmp_blue; // $v1
		// 		struct CVECTOR *ptr; // $s0

			/* begin block 1.1.1 */
				// Start line: 4963
				// Start offset: 0x80049C44
				// Variables:
			// 		int fade; // $v0
			/* end block 1.1.1 */
			// End offset: 0x80049C68
			// End Line: 4969
		/* end block 1.1 */
		// End offset: 0x80049C68
		// End Line: 4970
	/* end block 1 */
	// End offset: 0x80049EB4
	// End Line: 5035

	/* begin block 2 */
		// Start line: 11864
	/* end block 2 */
	// End Line: 11865

void FX_ContinueParticle(_FXGeneralEffect *param_1)

{
  _FX_PRIM *p_Var1;
  int iVar2;
  _Instance *instance;
  int iVar3;
  
  iVar2 = (int)*(char *)((int)&param_1[4].continue_process + 2);
  if (iVar2 < 0) {
                    /* WARNING: Subroutine does not return */
    rand();
  }
  instance = param_1->instance;
  if ((((((instance->flags & 0x800U) == 0) && ((instance->flags2 & 0x4000000U) == 0)) &&
       ((instance->flags & 0x200U) != 0)) &&
      ((instance->matrix != (MATRIX *)0x0 && (instance->oldMatrix != (MATRIX *)0x0)))) &&
     (0 < iVar2)) {
    if ((instance != p_Gpffffb524) && (sGpffffb500 != 1000)) {
      INSTANCE_GetFadeValue(instance);
    }
    iVar3 = 0;
    if (0 < iVar2) {
      do {
        p_Var1 = FX_GetPrim(p_Gpffffb190);
        if (p_Var1 != (_FX_PRIM *)0x0) {
                    /* WARNING: Subroutine does not return */
          rand();
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar2);
    }
  }
  if ((0 < param_1->lifeTime) &&
     (iVar2 = (uint)(ushort)param_1->lifeTime - (uint)uGpffffbaf0, param_1->lifeTime = (short)iVar2,
     iVar2 * 0x10000 < 1)) {
    FX_DeleteGeneralEffect(param_1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdraftPrimModify(struct _FX_PRIM *fxPrim /*$s3*/, struct _Instance *instance /*$a1*/, struct _FXParticle *particle /*$s1*/, struct _FXTracker *fxTracker /*$a3*/)
 // line 5037, offset 0x80049ee4
	/* begin block 1 */
		// Start line: 5038
		// Start offset: 0x80049EE4
		// Variables:
	// 		int deg; // $s2
	/* end block 1 */
	// End offset: 0x80049FF8
	// End Line: 5044

	/* begin block 2 */
		// Start line: 12443
	/* end block 2 */
	// End Line: 12444

void FX_UpdraftPrimModify(void)

{
                    /* WARNING: Subroutine does not return */
  rand();
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeParticleTexFX(struct _FX_PRIM *fxPrim /*$s0*/, struct _SVector *position /*$a1*/, struct Object *object /*$s1*/, int modelnum /*$s4*/, int texnum /*stack 16*/, struct _SVector *vel /*stack 20*/, struct _SVector *accl /*stack 24*/, long color /*stack 28*/, int size /*stack 32*/, int life /*stack 36*/)
 // line 5047, offset 0x8004a028
	/* begin block 1 */
		// Start line: 12463
	/* end block 1 */
	// End Line: 12464

void FX_MakeParticleTexFX
               (_FX_PRIM *fxPrim,_SVector *position,Object *object,int modelnum,int texnum,
               _SVector *vel,_SVector *accl,long color,int size,int life)

{
  if (((object != (Object *)0x0) ||
      (object = (Object *)DebugMenuLine_800c87c4.text, DebugMenuLine_800c87c4.text != (char *)0x0))
     && (fxPrim != (_FX_PRIM *)0x0)) {
    FX_DFacadeParticleSetup
              (fxPrim,(SVECTOR *)position,(short)size,(short)size,color,(SVECTOR *)vel,
               (SVECTOR *)accl,gFXT,(int)(short)life);
                    /* WARNING: Subroutine does not return */
    FX_GetTextureObject(object,modelnum,texnum);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeHitFX(struct _SVector *position /*$s1*/)
 // line 5070, offset 0x8004a130
	/* begin block 1 */
		// Start line: 5071
		// Start offset: 0x8004A130
		// Variables:
	// 		struct _FX_PRIM *fxPrim; // $s0
	/* end block 1 */
	// End offset: 0x8004A1B0
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
 // line 5108, offset 0x8004a1c4
	/* begin block 1 */
		// Start line: 12608
	/* end block 1 */
	// End Line: 12609

void FX_ContinueLightning(_FXGeneralEffect *param_1)

{
  int iVar1;
  
  *(short *)&param_1[1].next = *(short *)&param_1[1].next + *(short *)((int)&param_1[1].next + 2);
  if ((0 < param_1->lifeTime) &&
     (iVar1 = (uint)(ushort)param_1->lifeTime - (uint)uGpffffbaf0, param_1->lifeTime = (short)iVar1,
     iVar1 * 0x10000 < 1)) {
    FX_DeleteGeneralEffect(param_1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SetReaverInstance(struct _Instance *instance /*$a0*/)
 // line 5120, offset 0x8004a224
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
 // line 5128, offset 0x8004a230
	/* begin block 1 */
		// Start line: 5129
		// Start offset: 0x8004A230
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
			// Start offset: 0x8004A398
			// Variables:
		// 		int scale1; // $s0
		/* end block 1.1 */
		// End offset: 0x8004A5C4
		// End Line: 5252
	/* end block 1 */
	// End offset: 0x8004A5F0
	// End Line: 5256

	/* begin block 2 */
		// Start line: 12648
	/* end block 2 */
	// End Line: 12649

void FX_SoulReaverBlade(_Instance *instance,ulong **drawot)

{
  uint auStack128 [22];
  
  if ((((*(short *)((int)instance->extraData + 2) != 0) &&
       (*(int *)(theCamera.core.vvPlaneConsts[2] + 4) + 0x640U <
        *(uint *)(theCamera.core.vvPlaneConsts[2] + 8))) &&
      (DebugMenuLine_800c87c4.text != (char *)0x0)) &&
     ((((instance->flags & 0x200U) != 0 && ((instance->flags & 0x800U) == 0)) &&
      ((instance->matrix != (MATRIX *)0x0 && (instance->oldMatrix != (MATRIX *)0x0)))))) {
                    /* WARNING: Subroutine does not return */
    CompMatrix(DAT_800cfef0,(ushort *)(instance->matrix + 1),auStack128);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ReaverBladeInit()
 // line 5268, offset 0x8004a620
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
 // line 5275, offset 0x8004a628
	/* begin block 1 */
		// Start line: 5276
		// Start offset: 0x8004A628
		// Variables:
	// 		struct MATRIX mat; // stack offset -96
	// 		struct MATRIX *swTransform; // $a1
	// 		struct _SVector start; // stack offset -64
	// 		struct _SVector end; // stack offset -56
	// 		struct __ReaverData *data; // $s4
	// 		long color; // $s5
	// 		long glow_color; // stack offset -48
	/* end block 1 */
	// End offset: 0x8004A848
	// End Line: 5350

	/* begin block 2 */
		// Start line: 13213
	/* end block 2 */
	// End Line: 13214

void FX_SoulReaverWinding(_Instance *instance,_PrimPool *primPool,ulong **ot,MATRIX *wcTransform)

{
  uint auStack96 [14];
  
  if ((*(char *)instance->extraData != '\0') && (*(char *)(instance->extraData + 1) != '\0')) {
                    /* WARNING: Subroutine does not return */
    CompMatrix((undefined4 *)wcTransform,
               (ushort *)(*(int *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x40) + 0x500),
               auStack96);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdateInstanceWaterSplit(struct _Instance *instance /*$s0*/)
 // line 5356, offset 0x8004a878
	/* begin block 1 */
		// Start line: 5357
		// Start offset: 0x8004A878
		// Variables:
	// 		struct _SVector normal; // stack offset -16
	/* end block 1 */
	// End offset: 0x8004A938
	// End Line: 5391

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
  if ((instance != (_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0]) ||
     (instance->cachedTFace == -1)) {
    p_Var1 = instance->waterFace;
    instance->waterFace = (_TFace *)0x0;
    instance->waterFaceTerrain = (_Terrain *)0x0;
    instance->oldWaterFace = p_Var1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_GetPlaneEquation(struct _SVector *normal /*$a0*/, struct _SVector *poPlane /*$a1*/, struct _PlaneConstants *plane /*$a2*/)
 // line 5393, offset 0x8004a948
	/* begin block 1 */
		// Start line: 13486
	/* end block 1 */
	// End Line: 13487

	/* begin block 2 */
		// Start line: 13488
	/* end block 2 */
	// End Line: 13489

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
 // line 5436, offset 0x8004a9bc
	/* begin block 1 */
		// Start line: 5437
		// Start offset: 0x8004A9BC
		// Variables:
	// 		struct _FXHalvePlane *ring; // $s0
	// 		struct _SVector normal; // stack offset -40
	// 		struct _SVector point; // stack offset -32
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x8004AB1C
	// End Line: 5484

	/* begin block 2 */
		// Start line: 10872
	/* end block 2 */
	// End Line: 10873

void FX_DoInstancePowerRing
               (_Instance *instance,long atuTime,long *color,long numColors,int follow_halveplane)

{
                    /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(numColors * 4 + 0x2c,'\r');
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdatePowerRing(struct _FXHalvePlane *ring /*$s2*/)
 // line 5488, offset 0x8004ab3c
	/* begin block 1 */
		// Start line: 5489
		// Start offset: 0x8004AB3C
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
	// End offset: 0x8004AD80
	// End Line: 5548

	/* begin block 2 */
		// Start line: 13665
	/* end block 2 */
	// End Line: 13666

void FX_UpdatePowerRing(int param_1)

{
  if ((int)*(short *)(param_1 + 0xe) <= *(int *)(param_1 + 0x10)) {
    *(int *)(param_1 + 0x10) = (int)*(short *)(param_1 + 0xe);
    *(undefined2 *)(param_1 + 0xe) = 0;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined2 *)(param_1 + 0x1a) = 0;
  rsin(200);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdateInstanceSplitRing(struct _FXHalvePlane *ring /*$s0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 5633, offset 0x8004adc0
	/* begin block 1 */
		// Start line: 13978
	/* end block 1 */
	// End Line: 13979

void FX_UpdateInstanceSplitRing(_FXGeneralEffect *param_1)

{
  short sVar1;
  void *pvVar2;
  
  if (param_1->lifeTime != 0) {
    if (param_1->type == '\0') {
      FX_UpdatePowerRing((int)param_1);
    }
    else {
      sVar1 = param_1->lifeTime;
      pvVar2 = (void *)((int)param_1[1].next + iGpffffb734);
      param_1[1].next = pvVar2;
      if ((int)(void *)(int)sVar1 <= (int)pvVar2) {
        param_1[1].next = (void *)(int)sVar1;
        param_1->lifeTime = 0;
      }
    }
    if (param_1->lifeTime != 0) {
      return;
    }
  }
  FX_DeleteGeneralEffect(param_1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdateGlowEffect(struct _FXGlowEffect *effect /*$a0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 5656, offset 0x8004ae50
	/* begin block 1 */
		// Start line: 14025
	/* end block 1 */
	// End Line: 14026

void FX_UpdateGlowEffect(_FXGeneralEffect *param_1)

{
  if (param_1->lifeTime == 0) {
    FX_DeleteGeneralEffect(param_1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_InsertGeneralEffect(void *ptr /*$a0*/)
 // line 5664, offset 0x8004ae80
	/* begin block 1 */
		// Start line: 5666
		// Start offset: 0x8004AE80
	/* end block 1 */
	// End offset: 0x8004AE80
	// End Line: 5667

	/* begin block 2 */
		// Start line: 14041
	/* end block 2 */
	// End Line: 14042

	/* begin block 3 */
		// Start line: 14042
	/* end block 3 */
	// End Line: 14043

	/* begin block 4 */
		// Start line: 14043
	/* end block 4 */
	// End Line: 14044

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
 // line 5672, offset 0x8004ae90
	/* begin block 1 */
		// Start line: 5673
		// Start offset: 0x8004AE90
		// Variables:
	// 		struct _FXGeneralEffect *currentEffect; // $v0
	// 		struct _FXGeneralEffect *previousEffect; // $v1
	/* end block 1 */
	// End offset: 0x8004AF1C
	// End Line: 5705

	/* begin block 2 */
		// Start line: 14058
	/* end block 2 */
	// End Line: 14059

void FX_DeleteGeneralEffect(_FXGeneralEffect *effect)

{
  _FXGeneralEffect *p_Var1;
  _FXGeneralEffect *p_Var2;
  _FXGeneralEffect *p_Var3;
  
  if (effect == (_FXGeneralEffect *)0x0) {
    return;
  }
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
                    /* WARNING: Subroutine does not return */
    MEMPACK_Free((char *)effect[1].continue_process);
  }
                    /* WARNING: Subroutine does not return */
  MEMPACK_Free((char *)effect);
}



// decompiled code
// original method signature: 
// struct _FXGlowEffect * /*$ra*/ FX_DoInstanceOneSegmentGlow(struct _Instance *instance /*$s3*/, long segment /*$s4*/, long *color /*$s2*/, long numColors /*$s1*/, long atuColorCycleRate /*stack 16*/, long width /*stack 20*/, long height /*stack 24*/)
 // line 5710, offset 0x8004af2c
	/* begin block 1 */
		// Start line: 5711
		// Start offset: 0x8004AF2C
		// Variables:
	// 		struct _FXGlowEffect *glowEffect; // $a2

		/* begin block 1.1 */
			// Start line: 5743
			// Start offset: 0x8004AFF4
			// Variables:
		// 		int i; // $a1
		/* end block 1.1 */
		// End offset: 0x8004B04C
		// End Line: 5756
	/* end block 1 */
	// End offset: 0x8004B058
	// End Line: 5762

	/* begin block 2 */
		// Start line: 14134
	/* end block 2 */
	// End Line: 14135

_FXGlowEffect *
FX_DoInstanceOneSegmentGlow
          (_Instance *instance,long segment,long *color,long numColors,long atuColorCycleRate,
          long width,long height)

{
                    /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(numColors * 4 + 0x2c,'\r');
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SetGlowFades(struct _FXGlowEffect *glowEffect /*$a0*/, int fadein /*$a1*/, int fadeout /*$a2*/)
 // line 5767, offset 0x8004b08c
	/* begin block 1 */
		// Start line: 14270
	/* end block 1 */
	// End Line: 14271

	/* begin block 2 */
		// Start line: 14271
	/* end block 2 */
	// End Line: 14272

void FX_SetGlowFades(_FXGlowEffect *glowEffect,int fadein,int fadeout)

{
  glowEffect->fadein_time = (short)fadein * 0x21;
  glowEffect->fadeout_time = (short)fadeout * 0x21;
  return;
}



// decompiled code
// original method signature: 
// struct _FXGlowEffect * /*$ra*/ FX_DoInstanceTwoSegmentGlow(struct _Instance *instance /*$a0*/, long segment /*$a1*/, long segmentEnd /*$a2*/, long *color /*$a3*/, long numColors /*stack 16*/, long atuColorCycleRate /*stack 20*/, long height /*stack 24*/)
 // line 5773, offset 0x8004b0a8
	/* begin block 1 */
		// Start line: 5774
		// Start offset: 0x8004B0A8
		// Variables:
	// 		struct _FXGlowEffect *glowEffect; // $v0
	// 		int inc; // $s0
	/* end block 1 */
	// End offset: 0x8004B0C8
	// End Line: 5782

	/* begin block 2 */
		// Start line: 14282
	/* end block 2 */
	// End Line: 14283

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
 // line 5789, offset 0x8004b100
	/* begin block 1 */
		// Start line: 5790
		// Start offset: 0x8004B100
		// Variables:
	// 		struct _FXGlowEffect *glowEffect; // $v0
	/* end block 1 */
	// End offset: 0x8004B100
	// End Line: 5790

	/* begin block 2 */
		// Start line: 14318
	/* end block 2 */
	// End Line: 14319

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
 // line 5800, offset 0x8004b148
	/* begin block 1 */
		// Start line: 5801
		// Start offset: 0x8004B148
		// Variables:
	// 		struct _FXGlowEffect *glowEffect; // $v0
	/* end block 1 */
	// End offset: 0x8004B148
	// End Line: 5801

	/* begin block 2 */
		// Start line: 14343
	/* end block 2 */
	// End Line: 14344

void FX_DoInstanceOneSegmentGlowWithTime
               (_Instance *param_1,long param_2,long *param_3,long param_4,long param_5,long param_6
               ,long param_7,short param_8)

{
  _FXGlowEffect *p_Var1;
  
  p_Var1 = FX_DoInstanceOneSegmentGlow(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  p_Var1->lifeTime = param_8 * 0x21;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StopAllGlowEffects(struct _Instance *instance /*$s3*/, int fadeout_time /*$s0*/)
 // line 5812, offset 0x8004b190
	/* begin block 1 */
		// Start line: 5813
		// Start offset: 0x8004B190
		// Variables:
	// 		struct _FXGlowEffect *currentEffect; // $a0
	// 		struct _FXGlowEffect *previousEffect; // $s1

		/* begin block 1.1 */
			// Start line: 5828
			// Start offset: 0x8004B1E8
		/* end block 1.1 */
		// End offset: 0x8004B1E8
		// End Line: 5829
	/* end block 1 */
	// End offset: 0x8004B208
	// End Line: 5837

	/* begin block 2 */
		// Start line: 14367
	/* end block 2 */
	// End Line: 14368

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
 // line 5839, offset 0x8004b224
	/* begin block 1 */
		// Start line: 5840
		// Start offset: 0x8004B224

		/* begin block 1.1 */
			// Start line: 5849
			// Start offset: 0x8004B268
			// Variables:
		// 		struct _FXGeneralEffect *currentEffect; // $a0
		// 		struct _FXGeneralEffect *previousEffect; // $s0
		/* end block 1.1 */
		// End offset: 0x8004B294
		// End Line: 5862
	/* end block 1 */
	// End offset: 0x8004B294
	// End Line: 5863

	/* begin block 2 */
		// Start line: 14433
	/* end block 2 */
	// End Line: 14434

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
 // line 5865, offset 0x8004b2ac
	/* begin block 1 */
		// Start line: 5866
		// Start offset: 0x8004B2AC
		// Variables:
	// 		struct _SVector start; // stack offset -80
	// 		struct _SVector end; // stack offset -72
	// 		struct _SVector offset; // stack offset -64
	// 		struct MATRIX *swtransform; // $s0
	// 		struct MATRIX mat; // stack offset -56
	/* end block 1 */
	// End offset: 0x8004B4D8
	// End Line: 5928

	/* begin block 2 */
		// Start line: 14487
	/* end block 2 */
	// End Line: 14488

void FX_DrawLightning(_FXLightning *zap,MATRIX *wcTransform,ulong **ot)

{
  MATRIX *pMVar1;
  _SVector local_50;
  _SVector local_48;
  undefined local_40 [8];
  uint auStack56 [8];
  
  if ((zap->type == '\x02') || (zap->matrixSeg != -1)) {
    local_50.x = (zap->start_offset).x;
    local_50.y = (zap->start_offset).y;
    local_50.z = (zap->start_offset).z;
    FX_UpdateInstanceSplitRing((_FXHalvePlane *)zap,(_FXTracker *)wcTransform);
    return;
  }
  pMVar1 = zap->instance->matrix;
  if (pMVar1 != (MATRIX *)0x0) {
                    /* WARNING: Subroutine does not return */
    ApplyMatrixSV(pMVar1 + zap->startSeg,&zap->start_offset,local_40);
  }
  local_50.x = (zap->instance->position).x;
  local_50.y = (zap->instance->position).y;
  local_50.z = (zap->instance->position).z;
  if (((uint)zap->type - 1 < 2) || (zap->matrixSeg != -1)) {
    local_48.x = (zap->end_offset).x;
    local_48.y = (zap->end_offset).y;
    local_48.z = (zap->end_offset).z;
  }
  else {
    pMVar1 = zap->end_instance->matrix;
    if (pMVar1 != (MATRIX *)0x0) {
                    /* WARNING: Subroutine does not return */
      ApplyMatrixSV(pMVar1 + zap->endSeg,&zap->end_offset,local_40);
    }
    local_48.x = (zap->instance->position).x;
    local_48.y = (zap->instance->position).y;
    local_48.z = (zap->instance->position).z;
  }
  if (((int)zap->matrixSeg != -1) && (pMVar1 = zap->instance->matrix, pMVar1 != (MATRIX *)0x0)) {
                    /* WARNING: Subroutine does not return */
    CompMatrix((undefined4 *)wcTransform,(ushort *)(pMVar1 + (int)zap->matrixSeg),auStack56);
  }
  FX_Lightning(wcTransform,ot,(MATRIX *)0x0,zap->deg,&local_50,&local_48,(int)zap->width,
               (int)zap->small_width,(int)zap->segs,(int)zap->sine_size,(int)zap->variation,
               zap->color,zap->glow_color);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawAllGeneralEffects(struct MATRIX *wcTransform /*$s1*/, struct _VertexPool *vertexPool /*$s3*/, struct _PrimPool *primPool /*$s4*/, unsigned long **ot /*$s2*/)
 // line 5935, offset 0x8004b560
	/* begin block 1 */
		// Start line: 5936
		// Start offset: 0x8004B560
		// Variables:
	// 		struct _Instance *instance; // $a0
	// 		struct _FXGeneralEffect *currentEffect; // $s0

		/* begin block 1.1 */
			// Start line: 5949
			// Start offset: 0x8004B5EC
			// Variables:
		// 		struct _FXGlowEffect *currentGlow; // $t0
		/* end block 1.1 */
		// End offset: 0x8004B61C
		// End Line: 5957

		/* begin block 1.2 */
			// Start line: 5961
			// Start offset: 0x8004B644
		/* end block 1.2 */
		// End offset: 0x8004B644
		// End Line: 5962

		/* begin block 1.3 */
			// Start line: 5971
			// Start offset: 0x8004B688
		/* end block 1.3 */
		// End offset: 0x8004B688
		// End Line: 5973

		/* begin block 1.4 */
			// Start line: 5981
			// Start offset: 0x8004B6E0
		/* end block 1.4 */
		// End offset: 0x8004B6E0
		// End Line: 5983
	/* end block 1 */
	// End offset: 0x8004B718
	// End Line: 5993

	/* begin block 2 */
		// Start line: 14629
	/* end block 2 */
	// End Line: 14630

void FX_DrawAllGeneralEffects
               (MATRIX *param_1,_VertexPool *param_2,_PrimPool *param_3,ulong **param_4)

{
  byte bVar1;
  int iVar2;
  _Instance *instance;
  _FXBlastringEffect *blast;
  
  blast = p_Gpffff90b0;
  if (p_Gpffff90b0 != (_FXBlastringEffect *)0x0) {
    do {
      bVar1 = blast->effectType;
      if (((bVar1 & 0x80) != 0) &&
         ((instance = blast->instance, instance == (_Instance *)0x0 ||
          (((instance->flags & 0x800U) == 0 && ((instance->flags2 & 0x4000000U) == 0)))))) {
        if (bVar1 == 0x83) {
          if ((0 < blast->lifeTime) &&
             (iVar2 = (uint)(ushort)blast->lifeTime - (uint)uGpffffb734,
             blast->lifeTime = (short)iVar2, iVar2 * 0x10000 < 0)) {
            blast->lifeTime = 0;
          }
          PIPE3D_DoGlow(instance,param_1,param_2,param_3,param_4,(_FXGlowEffect *)blast);
        }
        else {
          if (bVar1 == 0x82) {
            PIPE3D_HalvePlaneGetRingPoints
                      (instance,param_1,param_2,param_3,param_4,(_FXHalvePlane *)blast);
          }
          else {
            if (bVar1 == 0x84) {
              FX_DrawBlastring(param_1,blast);
            }
            else {
              if (bVar1 == 0x85) {
                FX_LightHouse(param_1,param_4,blast->instance,(int)(blast->position).x,
                              (int)(blast->position).y,0x20,*(long *)&(blast->position).z);
              }
              else {
                if (bVar1 == 0x86) {
                  FX_DrawFField(param_1,(_FXForceFieldEffect *)blast);
                }
                else {
                  if (bVar1 == 0x87) {
                    FX_DrawLightning((_FXLightning *)blast,param_1,param_4);
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
 // line 6003, offset 0x8004b738
	/* begin block 1 */
		// Start line: 6004
		// Start offset: 0x8004B738
		// Variables:
	// 		int fade; // $a2
	// 		int tm; // $v0

		/* begin block 1.1 */
			// Start line: 6015
			// Start offset: 0x8004B7A8
			// Variables:
		// 		int rad; // $v0
		// 		int crad; // $a0
		// 		int endrad; // $v1
		/* end block 1.1 */
		// End offset: 0x8004B850
		// End Line: 6047

		/* begin block 1.2 */
			// Start line: 6051
			// Start offset: 0x8004B860
			// Variables:
		// 		unsigned long *colorPtr; // $a0
		// 		unsigned long black; // stack offset -16
		// 		int fade; // $a3
		/* end block 1.2 */
		// End offset: 0x8004B8A8
		// End Line: 6059
	/* end block 1 */
	// End offset: 0x8004B93C
	// End Line: 6080

	/* begin block 2 */
		// Start line: 14770
	/* end block 2 */
	// End Line: 14771

	/* begin block 3 */
		// Start line: 14775
	/* end block 3 */
	// End Line: 14776

void FX_ContinueBlastRing(_FXGeneralEffect *param_1)

{
  short sVar1;
  ushort uVar2;
  _Instance *p_Var3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  _FXGeneralEffect *p_Var7;
  void *pvVar8;
  int iVar9;
  undefined4 auStack16 [2];
  
  iVar9 = (int)param_1[5].continue_process * (uGpffffb738 >> 4);
  if (iVar9 < 0) {
    iVar9 = iVar9 + 0xff;
  }
  p_Var3 = param_1[5].instance;
  pvVar5 = param_1[5].next;
  *(int *)&param_1[3].effectType = *(int *)&param_1[3].effectType + (iVar9 >> 8);
  iVar9 = *(int *)&param_1[3].effectType;
  pvVar8 = (void *)((int)param_1[5].continue_process + (int)p_Var3 * (int)sGpffffbaf0);
  param_1[5].continue_process = pvVar8;
  if ((int)pvVar5 < iVar9) {
    if (iVar9 < 0) {
      iVar9 = iVar9 + 0xfff;
    }
    if ((int)pvVar5 < 0) {
      pvVar5 = (void *)((int)pvVar5 + 0xfff);
    }
    iVar4 = *(int *)&param_1[4].effectType;
    iVar6 = (int)pvVar5 >> 0xc;
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0xfff;
    }
    if ((int)pvVar8 < 0) {
      p_Var3 = param_1[4].instance;
      if ((int)p_Var3 < 0) {
        p_Var3 = (_Instance *)((int)&p_Var3[6].work4 + 3);
      }
      iVar9 = (((iVar9 >> 0xc) - iVar6) * 0x1000) / (((int)p_Var3 >> 0xc) - iVar6);
    }
    else {
      iVar9 = (((iVar9 >> 0xc) - iVar6) * 0x1000) / ((iVar4 >> 0xc) - iVar6);
    }
    if (iVar9 < 0x1000) {
                    /* WARNING: Subroutine does not return */
      LoadAverageCol((byte *)&param_1[7].continue_process,(byte *)(param_1 + 7),iVar9,0x1000 - iVar9
                     ,&param_1[6].effectType);
    }
    *(undefined4 *)&param_1[6].effectType = 0;
  }
  if (sGpffffb500 != 1000) {
    auStack16[0] = 0;
    iVar9 = INSTANCE_GetFadeValue(param_1->instance);
    if ((int)param_1[5].next < *(int *)&param_1[3].effectType) {
      p_Var7 = (_FXGeneralEffect *)&param_1[6].effectType;
    }
    else {
      p_Var7 = param_1 + 7;
    }
                    /* WARNING: Subroutine does not return */
    LoadAverageCol((byte *)p_Var7,(byte *)auStack16,0x1000 - iVar9,iVar9,&param_1[6].effectType);
  }
  sVar1 = param_1->lifeTime;
  *(uint *)&param_1[6].effectType = *(uint *)&param_1[6].effectType & 0xffffff;
  if (((sVar1 != -99) &&
      (((0 < (int)param_1[5].continue_process &&
        (*(int *)&param_1[4].effectType < *(int *)&param_1[3].effectType)) ||
       (((int)param_1[5].continue_process < 0 &&
        (*(int *)&param_1[3].effectType < *(int *)&param_1[4].effectType)))))) ||
     ((uVar2 = param_1->lifeTime - 1, -1 < param_1->lifeTime &&
      (param_1->lifeTime = uVar2, (int)((uint)uVar2 << 0x10) < 1)))) {
    FX_DeleteGeneralEffect(param_1);
  }
  return;
}



// decompiled code
// original method signature: 
// struct _FXBlastringEffect * /*$ra*/ FX_DoBlastRing(struct _Instance *instance /*$s2*/, struct _SVector *position /*$s5*/, struct MATRIX *mat /*$s3*/, int segment /*$s6*/, int radius /*stack 16*/, int endRadius /*stack 20*/, int colorChangeRadius /*stack 24*/, int size1 /*stack 28*/, int size2 /*stack 32*/, int vel /*stack 36*/, int accl /*stack 40*/, int height1 /*stack 44*/, int height2 /*stack 48*/, int height3 /*stack 52*/, long startColor /*stack 56*/, long endColor /*stack 60*/, int pred_offset /*stack 64*/, int lifeTime /*stack 68*/, int sortInWorld /*stack 72*/)
 // line 6110, offset 0x8004b94c
	/* begin block 1 */
		// Start line: 6111
		// Start offset: 0x8004B94C
		// Variables:
	// 		struct _FXBlastringEffect *blast; // $s0
	/* end block 1 */
	// End offset: 0x8004BAF4
	// End Line: 6151

	/* begin block 2 */
		// Start line: 14998
	/* end block 2 */
	// End Line: 14999

_FXBlastringEffect *
FX_DoBlastRing(_Instance *instance,_SVector *position,MATRIX *mat,int segment,int radius,
              int endRadius,int colorChangeRadius,int size1,int size2,int vel,int accl,int height1,
              int height2,int height3,long startColor,long endColor,int pred_offset,int lifeTime,
              int sortInWorld)

{
                    /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(0x78,'\r');
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawBlastring(struct MATRIX *wcTransform /*$s3*/, struct _FXBlastringEffect *blast /*$s1*/)
 // line 6154, offset 0x8004bb20
	/* begin block 1 */
		// Start line: 6155
		// Start offset: 0x8004BB20
		// Variables:
	// 		int radius; // $s2
	// 		struct _SVector position; // stack offset -64
	// 		struct MATRIX mat; // stack offset -56

		/* begin block 1.1 */
			// Start line: 6162
			// Start offset: 0x8004BB60
			// Variables:
		// 		struct MATRIX *swtransform; // $s0
		/* end block 1.1 */
		// End offset: 0x8004BB9C
		// End Line: 6175
	/* end block 1 */
	// End offset: 0x8004BCD0
	// End Line: 6197

	/* begin block 2 */
		// Start line: 15098
	/* end block 2 */
	// End Line: 15099

void FX_DrawBlastring(MATRIX *wcTransform,_FXBlastringEffect *blast)

{
  MATRIX *pMVar1;
  uint auStack56 [8];
  
  if ((int)blast->segment < 0) {
                    /* WARNING: Subroutine does not return */
    CompMatrix((undefined4 *)wcTransform,(ushort *)&blast->matrix,auStack56);
  }
  pMVar1 = blast->instance->matrix;
  if (pMVar1 != (MATRIX *)0x0) {
                    /* WARNING: Subroutine does not return */
    CompMatrix((undefined4 *)wcTransform,(ushort *)(pMVar1 + (int)blast->segment),auStack56);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ContinueFlash(struct _FXFlash *flash /*$a0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 6200, offset 0x8004bcec
	/* begin block 1 */
		// Start line: 15190
	/* end block 1 */
	// End Line: 15191

void FX_ContinueFlash(_FXGeneralEffect *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)&param_1[1].effectType + iGpffffb738;
  *(int *)&param_1[1].effectType = iVar1;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xf;
  }
  if ((int)param_1[1].instance <= iVar1 >> 4) {
    FX_DeleteGeneralEffect(param_1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawFlash(struct _FXFlash *flash /*$a0*/)
 // line 6210, offset 0x8004bd3c
	/* begin block 1 */
		// Start line: 6211
		// Start offset: 0x8004BD3C
		// Variables:
	// 		int time; // $a1
	// 		int div; // $a2
	// 		int transtype; // $s0
	// 		int interp; // $a3
	// 		unsigned long color; // stack offset -16
	// 		unsigned long black; // stack offset -12
	/* end block 1 */
	// End offset: 0x8004BE30
	// End Line: 6241

	/* begin block 2 */
		// Start line: 15210
	/* end block 2 */
	// End Line: 15211

void FX_DrawFlash(_FXFlash *flash)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int transtype;
  uint local_10;
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
    transtype = 0x1000 - iVar2;
  }
  else {
    iVar3 = flash->timeAtColor;
    if (iVar2 <= iVar3) {
      FX_DrawScreenPoly(transtype,local_10,5);
      return;
    }
    transtype = flash->timeFromColor - iVar3;
    if (transtype == 0) {
      transtype = 0x1000;
      bVar1 = true;
    }
    else {
      transtype = ((iVar2 - iVar3) * 0x1000) / transtype;
      bVar1 = transtype < 0x1001;
    }
    if (!bVar1) {
      transtype = 0x1000;
    }
    iVar2 = 0x1000 - transtype;
  }
                    /* WARNING: Subroutine does not return */
  LoadAverageCol((byte *)&local_10,(byte *)&local_c,iVar2,transtype,(undefined *)&local_10);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_RelocateGeneric(struct Object *object /*$a0*/, long offset /*$a1*/)
 // line 6244, offset 0x8004be50
	/* begin block 1 */
		// Start line: 6246
		// Start offset: 0x8004BE50
		// Variables:
	// 		struct GenericFXObject *GFXO; // $v0
	/* end block 1 */
	// End offset: 0x8004BEE4
	// End Line: 6255

	/* begin block 2 */
		// Start line: 15281
	/* end block 2 */
	// End Line: 15282

	/* begin block 3 */
		// Start line: 15282
	/* end block 3 */
	// End Line: 15283

	/* begin block 4 */
		// Start line: 15284
	/* end block 4 */
	// End Line: 15285

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
 // line 6258, offset 0x8004beec
	/* begin block 1 */
		// Start line: 6259
		// Start offset: 0x8004BEEC
		// Variables:
	// 		struct _FXParticle *currentParticle; // $s0
	// 		struct GenericFXObject *GFXO; // $v1
	// 		struct _GenericParticleParams *GPP; // $s1
	// 		struct Object *texture_obj; // $s2
	// 		struct Object *particle; // $a2

		/* begin block 1.1 */
			// Start line: 6324
			// Start offset: 0x8004C14C
			// Variables:
		// 		struct TextureMT3 *texture; // $v0
		/* end block 1.1 */
		// End offset: 0x8004C174
		// End Line: 6328

		/* begin block 1.2 */
			// Start line: 6338
			// Start offset: 0x8004C1EC
			// Variables:
		// 		int tmp_blue; // $a0
		// 		struct CVECTOR *ptr; // $v1
		/* end block 1.2 */
		// End offset: 0x8004C210
		// End Line: 6347
	/* end block 1 */
	// End offset: 0x8004C21C
	// End Line: 6352

	/* begin block 2 */
		// Start line: 15309
	/* end block 2 */
	// End Line: 15310

_FXParticle *
FX_StartGenericParticle(_Instance *instance,int num,int segOverride,int lifeOverride,int InitFlag)

{
  undefined uVar1;
  short sVar2;
  _FXParticle *ptr;
  int iVar3;
  short *psVar4;
  Object *object;
  
  object = (Object *)0x0;
  if ((DebugMenuLine_800c87c4.text == (char *)0x0) ||
     ((psVar4 = (short *)(**(int **)(DebugMenuLine_800c87c4.text + 0x1c) + num * 0x30),
      InitFlag != 0 && (*(char *)(psVar4 + 1) == '\0')))) {
    ptr = (_FXParticle *)0x0;
  }
  else {
    if ((*(char *)((int)psVar4 + 0x1f) != '\0') &&
       (instance = instance->LinkChild, instance == (_Instance *)0x0)) {
      return (_FXParticle *)0x0;
    }
    if (*(char *)((int)psVar4 + 0x1b) != -1) {
      object = (Object *)DebugMenuLine_800c87c4.text;
      if (*(char *)((int)psVar4 + 0x13) != '\0') {
        object = instance->object;
      }
      if (object == (Object *)0x0) {
        return (_FXParticle *)0x0;
      }
    }
    ptr = FX_GetParticle(instance,0);
    if (ptr != (_FXParticle *)0x0) {
      ptr->numberBirthParticles = *(char *)(psVar4 + 0x12);
      ptr->size = *psVar4;
      ptr->type = *(uchar *)((int)psVar4 + 3);
      ptr->birthRadius = psVar4[2];
      if (segOverride == 0) {
        ptr->startSegment = *(char *)(psVar4 + 3);
      }
      else {
        ptr->startSegment = (char)segOverride;
      }
      ptr->endSegment = *(char *)((int)psVar4 + 7);
      sVar2 = psVar4[6];
      *(undefined4 *)&ptr->direction = *(undefined4 *)(psVar4 + 4);
      (ptr->direction).z = sVar2;
      (ptr->acceleration).x = (short)*(char *)(psVar4 + 8);
      (ptr->acceleration).y = (short)*(char *)((int)psVar4 + 0x11);
      (ptr->acceleration).z = (short)*(char *)(psVar4 + 9);
      ptr->startColor = *(uint *)(psVar4 + 10) & 0xffffff;
      ptr->endColor = *(uint *)(psVar4 + 0xc) & 0xffffff;
      if (lifeOverride == 0) {
        ptr->lifeTime = psVar4[0xe];
      }
      else {
        ptr->lifeTime = (short)lifeOverride;
      }
      ptr->primLifeTime = (ushort)*(byte *)(psVar4 + 0xf);
      ptr->startFadeValue = psVar4[0x10];
      ptr->startScale = psVar4[0x17];
      ptr->scaleSpeed = psVar4[0x13];
      (ptr->offset).x = psVar4[0x14];
      (ptr->offset).y = psVar4[0x15];
      (ptr->offset).z = psVar4[0x16];
      ptr->z_undulate = *(char *)((int)psVar4 + 0x25);
      if ((psVar4[0x11] == -1) && (*(char *)(psVar4 + 0xf) != '\0')) {
        ptr->fadeStep =
             (short)((0x1000 - (int)ptr->startFadeValue) / (int)(uint)*(byte *)(psVar4 + 0xf));
      }
      else {
        ptr->fadeStep = psVar4[0x11];
      }
      if ((int)*(char *)((int)psVar4 + 0x1b) == -1) {
        if (*(char *)((int)psVar4 + 3) == '\x01') {
          *(code **)&ptr->fxprim_process = FX_AttachedParticlePrimProcess;
        }
        if (*(char *)(psVar4 + 7) == '\x01') {
          ptr->flag_bits = ptr->flag_bits | 1;
        }
        if (*(char *)((int)psVar4 + 0xf) != '\0') {
          ptr->flag_bits = ptr->flag_bits | 2;
        }
        if ((*(char *)(psVar4 + 7) == '\x02') && (iVar3 = SoulReaverFire(), iVar3 != 0)) {
          uVar1 = *(undefined *)((int)&ptr->startColor + 2);
          *(undefined *)((int)&ptr->startColor + 2) = *(undefined *)&ptr->startColor;
          *(undefined *)&ptr->startColor = uVar1;
          uVar1 = *(undefined *)((int)&ptr->endColor + 2);
          *(undefined *)((int)&ptr->endColor + 2) = *(undefined *)&ptr->endColor;
          *(undefined *)&ptr->endColor = uVar1;
        }
                    /* WARNING: Subroutine does not return */
        FX_InsertGeneralEffect(ptr);
      }
                    /* WARNING: Subroutine does not return */
      FX_GetTextureObject(object,(int)*(char *)((int)psVar4 + 0x17),
                          (int)*(char *)((int)psVar4 + 0x1b));
    }
  }
  return ptr;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartGenericRibbon(struct _Instance *instance /*$a0*/, int num /*$a1*/, int segOverride /*$a2*/, int endOverride /*$a3*/, int InitFlag /*stack 16*/)
 // line 6354, offset 0x8004c23c
	/* begin block 1 */
		// Start line: 6355
		// Start offset: 0x8004C23C
		// Variables:
	// 		struct Object *particle; // $v1
	// 		struct GenericFXObject *GFXO; // $v1
	// 		struct _GenericRibbonParams *GRP; // $v1
	/* end block 1 */
	// End offset: 0x8004C2E8
	// End Line: 6390

	/* begin block 2 */
		// Start line: 15519
	/* end block 2 */
	// End Line: 15520

void FX_StartGenericRibbon(_Instance *instance,int num,int segOverride,int endOverride,int InitFlag)

{
  int iVar1;
  
  if (((DebugMenuLine_800c87c4.text != (char *)0x0) &&
      ((iVar1 = *(int *)(*(int *)(DebugMenuLine_800c87c4.text + 0x1c) + 4) + num * 0x14,
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
 // line 6392, offset 0x8004c2f8
	/* begin block 1 */
		// Start line: 6393
		// Start offset: 0x8004C2F8
		// Variables:
	// 		struct Object *particle; // $v1
	// 		struct GenericFXObject *GFXO; // $t1
	// 		struct _GenericGlowParams *GGP; // $s0
	// 		struct _FXGlowEffect *glowEffect; // $a0
	// 		long *color; // $v1

		/* begin block 1.1 */
			// Start line: 6420
			// Start offset: 0x8004C384
			// Variables:
		// 		int seg; // $a1
		/* end block 1.1 */
		// End offset: 0x8004C390
		// End Line: 6422

		/* begin block 1.2 */
			// Start line: 6426
			// Start offset: 0x8004C3C8
			// Variables:
		// 		int seg; // $a1
		// 		int segEnd; // $a2
		/* end block 1.2 */
		// End offset: 0x8004C3E8
		// End Line: 6437

		/* begin block 1.3 */
			// Start line: 6441
			// Start offset: 0x8004C418
			// Variables:
		// 		int seg; // $a1
		// 		int numSeg; // $a2
		/* end block 1.3 */
		// End offset: 0x8004C460
		// End Line: 6460
	/* end block 1 */
	// End offset: 0x8004C490
	// End Line: 6467

	/* begin block 2 */
		// Start line: 15602
	/* end block 2 */
	// End Line: 15603

void FX_StartGenericGlow(_Instance *instance,int num,int segOverride,int seg2Override,int InitFlag)

{
  _FXGlowEffect *glowEffect;
  long *color;
  int iVar1;
  char *pcVar2;
  
  if (DebugMenuLine_800c87c4.text != (char *)0x0) {
    pcVar2 = (char *)(*(int *)(*(int *)(DebugMenuLine_800c87c4.text + 0x1c) + 8) + num * 0x18);
    if (((InitFlag == 0) || (*pcVar2 != '\0')) &&
       ((pcVar2[5] == '\0' || (instance = instance->LinkChild, instance != (_Instance *)0x0)))) {
      iVar1 = (int)pcVar2[3];
      color = (long *)(*(int *)(*(int *)(DebugMenuLine_800c87c4.text + 0x1c) + 0x18) +
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
 // line 6487, offset 0x8004c4a0
	/* begin block 1 */
		// Start line: 6488
		// Start offset: 0x8004C4A0
		// Variables:
	// 		struct _FXLightning *zap; // $s0
	/* end block 1 */
	// End offset: 0x8004C584
	// End Line: 6523

	/* begin block 2 */
		// Start line: 15802
	/* end block 2 */
	// End Line: 15803

_FXLightning *
FX_CreateLightning(_Instance *instance,int lifeTime,int deg,int deg_inc,int width,int small_width,
                  int segs,int sine_size,int variation,ulong color,ulong glow_color)

{
                    /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(0x3c,'\r');
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_SetLightingPos(struct _FXLightning *zap /*$a0*/, struct _Instance *startInstance /*$a1*/, int startSeg /*$a2*/, struct _Position *startOffset /*$a3*/, struct _Instance *endInstance /*stack 16*/, int endSeg /*stack 20*/, struct _Position *endOffset /*stack 24*/, int matrixSeg /*stack 28*/)
 // line 6544, offset 0x8004c5a8
	/* begin block 1 */
		// Start line: 15928
	/* end block 1 */
	// End Line: 15929

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
    if (startInstance != (_Instance *)0x0) goto LAB_8004c5f4;
  }
  if (endInstance == (_Instance *)0x0) {
    zap->type = '\x02';
  }
LAB_8004c5f4:
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
 // line 6573, offset 0x8004c658
	/* begin block 1 */
		// Start line: 6574
		// Start offset: 0x8004C658
		// Variables:
	// 		struct _FXLightning *zap; // $s1
	// 		struct GenericFXObject *GFXO; // $v1
	// 		struct _GenericLightningParams *GLP; // $s0
	// 		struct Object *particle; // $v1

		/* begin block 1.1 */
			// Start line: 6600
			// Start offset: 0x8004C74C
			// Variables:
		// 		int startSeg; // $a2
		// 		int endSeg; // $a3

			/* begin block 1.1.1 */
				// Start line: 6626
				// Start offset: 0x8004C7B4
				// Variables:
			// 		int tmp_blue; // $a0
			// 		struct CVECTOR *ptr; // $v1
			/* end block 1.1.1 */
			// End offset: 0x8004C7D8
			// End Line: 6635
		/* end block 1.1 */
		// End offset: 0x8004C7D8
		// End Line: 6636
	/* end block 1 */
	// End offset: 0x8004C7DC
	// End Line: 6639

	/* begin block 2 */
		// Start line: 15986
	/* end block 2 */
	// End Line: 15987

	/* begin block 3 */
		// Start line: 15992
	/* end block 3 */
	// End Line: 15993

_FXLightning *
FX_StartGenericLightning(_Instance *instance,int num,int segOverride,int endSegOverride)

{
  undefined uVar1;
  _FXLightning *zap;
  int iVar2;
  _Instance *flash;
  _FXTracker *fxTracker;
  char *pcVar3;
  
  zap = (_FXLightning *)0x0;
  if (DebugMenuLine_800c87c4.text != (char *)0x0) {
    pcVar3 = (char *)(*(int *)(*(int *)(DebugMenuLine_800c87c4.text + 0x1c) + 0xc) + num * 0x28);
    if ((*(short *)(pcVar3 + 2) == 0) ||
       ((pcVar3[1] != '\0' && (instance = instance->LinkChild, instance == (_Instance *)0x0)))) {
      zap = (_FXLightning *)0x0;
    }
    else {
      fxTracker = (_FXTracker *)(int)*(short *)(pcVar3 + 2);
      flash = instance;
      zap = FX_CreateLightning(instance,(int)fxTracker,(int)*(short *)(pcVar3 + 4),
                               (int)*(short *)(pcVar3 + 6),(int)*(short *)(pcVar3 + 0x18),
                               (int)*(short *)(pcVar3 + 0x1a),(uint)(byte)pcVar3[0x17],
                               (int)*(short *)(pcVar3 + 0x1c),(int)*(short *)(pcVar3 + 0x1e),
                               *(ulong *)(pcVar3 + 0x20),*(ulong *)(pcVar3 + 0x24));
      if (zap != (_FXLightning *)0x0) {
        if (segOverride != 0) {
          FX_ContinueFlash((_FXFlash *)flash,fxTracker);
          return zap;
        }
        if (endSegOverride == 0) {
          endSegOverride = (int)pcVar3[0xf];
        }
        FX_SetLightingPos(zap,instance,(int)pcVar3[0xe],(_Position *)(pcVar3 + 8),instance,
                          endSegOverride,(_Position *)(pcVar3 + 0x10),(int)pcVar3[0x16]);
        if ((*pcVar3 == '\x01') && (iVar2 = SoulReaverFire(), iVar2 != 0)) {
          uVar1 = *(undefined *)((int)&zap->color + 2);
          *(undefined *)((int)&zap->color + 2) = *(undefined *)&zap->color;
          *(undefined *)&zap->color = uVar1;
          uVar1 = *(undefined *)((int)&zap->glow_color + 2);
          *(undefined *)((int)&zap->glow_color + 2) = *(undefined *)&zap->glow_color;
          *(undefined *)&zap->glow_color = uVar1;
        }
      }
    }
  }
  return zap;
}



// decompiled code
// original method signature: 
// struct _FXBlastringEffect * /*$ra*/ FX_StartGenericBlastring(struct _Instance *instance /*$s1*/, int num /*$a1*/, int segOverride /*$a2*/, int matrixSegOverride /*$a3*/)
 // line 6642, offset 0x8004c7fc
	/* begin block 1 */
		// Start line: 6643
		// Start offset: 0x8004C7FC
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
	// End offset: 0x8004C9E8
	// End Line: 6706

	/* begin block 2 */
		// Start line: 16135
	/* end block 2 */
	// End Line: 16136

	/* begin block 3 */
		// Start line: 16146
	/* end block 3 */
	// End Line: 16147

_FXBlastringEffect *
FX_StartGenericBlastring(_Instance *instance,int num,int segOverride,int matrixSegOverride)

{
  _FXBlastringEffect *p_Var1;
  MATRIX *pMVar2;
  _Instance *instance_00;
  int iVar3;
  int iVar4;
  int segment;
  int local_80;
  _SVector local_40;
  MATRIX MStack56;
  
  p_Var1 = (_FXBlastringEffect *)0x0;
  if (DebugMenuLine_800c87c4.text != (char *)0x0) {
    iVar3 = *(int *)(*(int *)(DebugMenuLine_800c87c4.text + 0x1c) + 0x10) + num * 0x30;
    if ((*(char *)(iVar3 + 1) == '\0') ||
       (instance = instance->LinkChild, instance != (_Instance *)0x0)) {
      iVar4 = segOverride;
      if (segOverride == 0) {
        iVar4 = (int)*(char *)(iVar3 + 0xc);
      }
      segment = matrixSegOverride;
      if (matrixSegOverride == 0) {
        segment = (int)*(short *)(iVar3 + 10);
      }
      instance_00 = (_Instance *)&MStack56;
      MATH3D_SetUnityMatrix((MATRIX *)instance_00);
      if (instance->matrix != (MATRIX *)0x0) {
        pMVar2 = instance->matrix + iVar4;
        local_40.x = *(short *)pMVar2->t;
        local_40.y = *(short *)(pMVar2->t + 1);
        local_40.z = *(ushort *)(pMVar2->t + 2);
        p_Var1 = (_FXBlastringEffect *)(uint)local_40.z;
        FX_StartGenericGlow(instance_00,num,segOverride,matrixSegOverride,local_80);
        return p_Var1;
      }
      local_40.x = (instance->position).x + *(short *)(iVar3 + 4);
      local_40.y = (instance->position).y + *(short *)(iVar3 + 6);
      local_40.z = (instance->position).z + *(short *)(iVar3 + 8);
      p_Var1 = FX_DoBlastRing(instance,&local_40,&MStack56,segment,(int)*(short *)(iVar3 + 0xe),
                              (int)*(short *)(iVar3 + 0x14),(int)*(short *)(iVar3 + 0x16),
                              (int)*(short *)(iVar3 + 0x10),(int)*(short *)(iVar3 + 0x12),
                              *(int *)(iVar3 + 0x18) << 0xc,*(int *)(iVar3 + 0x1c),
                              (int)*(short *)(iVar3 + 0x20),(int)*(short *)(iVar3 + 0x22),
                              (int)*(short *)(iVar3 + 0x24),*(long *)(iVar3 + 0x28),
                              *(long *)(iVar3 + 0x2c),(int)*(char *)(iVar3 + 0x26),
                              (int)*(short *)(iVar3 + 2),(int)*(char *)(iVar3 + 0xd));
      p_Var1->stay_in_place = *(char *)(iVar3 + 0x27);
    }
    else {
      p_Var1 = (_FXBlastringEffect *)0x0;
    }
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct _FXFlash * /*$ra*/ FX_StartGenericFlash(struct _Instance *instance /*$s2*/, int num /*$a1*/)
 // line 6708, offset 0x8004ca04
	/* begin block 1 */
		// Start line: 6709
		// Start offset: 0x8004CA04
		// Variables:
	// 		struct GenericFXObject *GFXO; // $v1
	// 		struct _GenericFlashParams *GFP; // $s1
	// 		struct Object *particle; // $v1
	// 		struct _FXFlash *flash; // $s0
	/* end block 1 */
	// End offset: 0x8004CACC
	// End Line: 6740

	/* begin block 2 */
		// Start line: 16279
	/* end block 2 */
	// End Line: 16280

	/* begin block 3 */
		// Start line: 16285
	/* end block 3 */
	// End Line: 16286

_FXFlash * FX_StartGenericFlash(_Instance *instance,int num)

{
  if (DebugMenuLine_800c87c4.text == (char *)0x0) {
    return (_FXFlash *)0x0;
  }
                    /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(0x24,'\r');
}



// decompiled code
// original method signature: 
// long /*$ra*/ FX_GetHealthColor(int currentHealth /*$a0*/)
 // line 6742, offset 0x8004cae4
	/* begin block 1 */
		// Start line: 6763
		// Start offset: 0x8004CAE4
		// Variables:
	// 		static long HealthColors[6]; // offset 0x0
	// 		long color; // $v1
	/* end block 1 */
	// End offset: 0x8004CB28
	// End Line: 6780

	/* begin block 2 */
		// Start line: 16362
	/* end block 2 */
	// End Line: 16363

	/* begin block 3 */
		// Start line: 16382
	/* end block 3 */
	// End Line: 16383

	/* begin block 4 */
		// Start line: 16393
	/* end block 4 */
	// End Line: 16394

long FX_GetHealthColor(int currentHealth)

{
  long *plVar1;
  
  plVar1 = (long *)DebugMenuLine_800c8944.bit_mask;
  if ((0 < currentHealth) && (plVar1 = DebugMenuLine_800c895c.var_address, (uint)currentHealth < 6))
  {
    plVar1 = (long *)(&DebugMenuLine_800c8944.bit_mask)[currentHealth + -1];
  }
  return (uint)plVar1 & 0xfffcfcfc;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Start_Snow(int percent /*$a0*/)
 // line 6784, offset 0x8004cb38
	/* begin block 1 */
		// Start line: 16446
	/* end block 1 */
	// End Line: 16447

	/* begin block 2 */
		// Start line: 16447
	/* end block 2 */
	// End Line: 16448

void FX_Start_Snow(int percent)

{
  snow_amount = (short)((percent * 0x300) / 100);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Start_Rain(int percent /*$a0*/)
 // line 6789, offset 0x8004cb6c
	/* begin block 1 */
		// Start line: 16456
	/* end block 1 */
	// End Line: 16457

	/* begin block 2 */
		// Start line: 16457
	/* end block 2 */
	// End Line: 16458

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
 // line 6796, offset 0x8004cba8
	/* begin block 1 */
		// Start line: 6797
		// Start offset: 0x8004CBA8
		// Variables:
	// 		struct Object *particle; // $v0
	// 		struct _FXLightBeam *beam; // $v0
	// 		struct GenericFXObject *GFXO; // $v0
	// 		long color; // $s0
	/* end block 1 */
	// End offset: 0x8004CC30
	// End Line: 6821

	/* begin block 2 */
		// Start line: 16470
	/* end block 2 */
	// End Line: 16471

	/* begin block 3 */
		// Start line: 16476
	/* end block 3 */
	// End Line: 16477

void FX_StartLightbeam(_Instance *instance,int startSeg,int endSeg,int color_num)

{
  if (DebugMenuLine_800c87c4.text != (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    MEMPACK_Malloc(0x18,'\r');
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartInstanceEffect(struct _Instance *instance /*$s2*/, struct ObjectEffect *effect /*$s0*/, int InitFlag /*$s3*/)
 // line 6835, offset 0x8004cc4c
	/* begin block 1 */
		// Start line: 6836
		// Start offset: 0x8004CC4C
		// Variables:
	// 		long color; // stack offset -32

		/* begin block 1.1 */
			// Start line: 6869
			// Start offset: 0x8004CD20
			// Variables:
		// 		long numberOfSegments; // $a2
		/* end block 1.1 */
		// End offset: 0x8004CD68
		// End Line: 6889

		/* begin block 1.2 */
			// Start line: 6954
			// Start offset: 0x8004CE2C
			// Variables:
		// 		struct _FXParticle *currentParticle; // $a0
		// 		struct evObjectDraftData *draft; // $s1
		/* end block 1.2 */
		// End offset: 0x8004CE64
		// End Line: 6963

		/* begin block 1.3 */
			// Start line: 6990
			// Start offset: 0x8004CF14
			// Variables:
		// 		struct FXSplinter *splinterData; // $s0
		// 		struct GenericTune *tune; // $a0
		// 		short shardFlags; // $s1

			/* begin block 1.3.1 */
				// Start line: 6996
				// Start offset: 0x8004CF34
				// Variables:
			// 		struct PhysObSplinter *splintDef; // $v0
			/* end block 1.3.1 */
			// End offset: 0x8004CF44
			// End Line: 6999
		/* end block 1.3 */
		// End offset: 0x8004CF70
		// End Line: 7010

		/* begin block 1.4 */
			// Start line: 7024
			// Start offset: 0x8004CFF0
			// Variables:
		// 		int shock; // $a0
		// 		int amt; // $a1
		/* end block 1.4 */
		// End offset: 0x8004D050
		// End Line: 7034
	/* end block 1 */
	// End offset: 0x8004D050
	// End Line: 7040

	/* begin block 2 */
		// Start line: 16561
	/* end block 2 */
	// End Line: 16562

void FX_StartInstanceEffect(_Instance *instance,ObjectEffect *effect,int InitFlag)

{
  byte bVar1;
  int iVar2;
  PhysObSplinter *pPVar3;
  long lVar4;
  uint *puVar5;
  uint motor1_speed;
  uint uVar6;
  FXSplinter *splintDef;
  short sVar7;
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
    motor1_speed = (uint)effect->modifierList[1];
    if (effect->modifierList[1] == 0) {
      motor1_speed = 1;
    }
    if ((uint)effect->modifierList[2] - 1 < 5) {
      local_20[0] = (undefined *)FX_ColorArray[effect->modifierList[2]];
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
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(instance,0x16);
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
      puVar5 = (uint *)instance->object->data;
      sVar7 = 0;
      if ((instance->object->oflags2 & 0x40000U) == 0) {
        if ((puVar5 != (uint *)0x0) && (splintDef = (FXSplinter *)puVar5[1], (*puVar5 & 2) != 0)) {
          sVar7 = 0x10;
        }
      }
      else {
        pPVar3 = PhysObGetSplinter(instance);
        if (pPVar3 != (PhysObSplinter *)0x0) {
          splintDef = (FXSplinter *)pPVar3->splinterData;
          sVar7 = 0;
        }
      }
      _FX_BuildSplinters(instance,(SVECTOR *)0x0,(SVECTOR *)0x0,(SVECTOR *)0x0,splintDef,gFXT,
                         (TDRFuncPtr__FX_BuildSplinters6fxSetup)0x0,
                         (TDRFuncPtr__FX_BuildSplinters7fxProcess)0x0,(int)sVar7);
    }
    break;
  case '\x13':
    GAMEPAD_Shock0((uint)effect->modifierList[0],(uint)effect->modifierList[1] << 0xc);
    break;
  case '\x14':
    bVar1 = effect->modifierList[1];
    motor1_speed = (uint)effect->modifierList[0];
    goto LAB_8004d048;
  case '\x15':
    lVar4 = MATH3D_DistanceBetweenPositions(&instance->position,(_Position *)&theCamera);
    uVar6 = (uint)effect->modifierList[0];
    iVar2 = (int)((int)(&DAT_00001f40 + -lVar4) * uVar6) / 8000;
    motor1_speed = iVar2 + 0x32;
    if (iVar2 < 1) {
      return;
    }
    if ((int)uVar6 < (int)motor1_speed) {
      motor1_speed = uVar6;
    }
    bVar1 = effect->modifierList[1];
LAB_8004d048:
    GAMEPAD_Shock1(motor1_speed,(uint)bVar1 << 0xc);
  }
                    /* WARNING: Read-only address (ram,0x800d0c44) is written */
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_EndInstanceEffects(struct _Instance *instance /*$s1*/)
 // line 7044, offset 0x8004d06c
	/* begin block 1 */
		// Start line: 7045
		// Start offset: 0x8004D06C
		// Variables:
	// 		struct _FXGeneralEffect *currentEffect; // $a0
	// 		struct _FXGeneralEffect *nextEffect; // $s0
	/* end block 1 */
	// End offset: 0x8004D0AC
	// End Line: 7058

	/* begin block 2 */
		// Start line: 17002
	/* end block 2 */
	// End Line: 17003

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
 // line 7061, offset 0x8004d0c0
	/* begin block 1 */
		// Start line: 7062
		// Start offset: 0x8004D0C0
		// Variables:
	// 		struct _FXGeneralEffect *currentEffect; // $a0
	// 		struct _FXGeneralEffect *nextEffect; // $s0
	/* end block 1 */
	// End offset: 0x8004D118
	// End Line: 7075

	/* begin block 2 */
		// Start line: 17040
	/* end block 2 */
	// End Line: 17041

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
 // line 7085, offset 0x8004d130
	/* begin block 1 */
		// Start line: 7086
		// Start offset: 0x8004D130
		// Variables:
	// 		int prevx; // $a0
	// 		int prevy; // $v0
	/* end block 1 */
	// End offset: 0x8004D1DC
	// End Line: 7100

	/* begin block 2 */
		// Start line: 17092
	/* end block 2 */
	// End Line: 17093

void FX_GetSpiralPoint(int radius,int deg,int *x,int *y)

{
                    /* WARNING: Subroutine does not return */
  rcos(deg);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_GetLinePoint(int radius /*$a0*/, int next_radius /*$s1*/, int deg /*$a2*/, int next_deg /*$s0*/, int *pntx /*stack 16*/, int *pnty /*stack 20*/, int part /*stack 24*/)
 // line 7129, offset 0x8004d204
	/* begin block 1 */
		// Start line: 7130
		// Start offset: 0x8004D204
		// Variables:
	// 		int x1; // stack offset -32
	// 		int y1; // stack offset -28
	// 		int x2; // stack offset -24
	// 		int y2; // stack offset -20
	/* end block 1 */
	// End offset: 0x8004D2A4
	// End Line: 7137

	/* begin block 2 */
		// Start line: 17184
	/* end block 2 */
	// End Line: 17185

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
 // line 7141, offset 0x8004d2d0
	/* begin block 1 */
		// Start line: 7142
		// Start offset: 0x8004D2D0
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
	// End offset: 0x8004D560
	// End Line: 7204

	/* begin block 2 */
		// Start line: 17211
	/* end block 2 */
	// End Line: 17212

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  uint uVar5;
  int local_48;
  uint local_44;
  int local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  uint local_30;
  
  iVar3 = -0x7fff;
  iVar2 = 0x2000;
  deg = 0;
  part = 0;
  local_30 = 0x7fff;
  FX_GetSpiralPoint(0x2000,0,&local_48,(int *)&local_44);
  _CHAR____800d16b4 = (undefined2)local_48;
  _CHAR____800d16b6 = (undefined2)local_44;
  next_deg = 0x2000;
  iVar1 = 0;
  iVar4 = 0x7fff;
  uVar5 = 0xffff8001;
  while( true ) {
    if (Spiral_Number == 0) {
      radius = next_deg;
      next_deg = part;
      next_radius = iVar2;
      if (iVar1 % fontTracker.font_buffer._472_4_ == 0) {
        next_radius = iVar2 + fontTracker.font_buffer._472_4_ * 0x440;
        next_deg = part + degchange * fontTracker.font_buffer._472_4_;
        deg = part;
        radius = iVar2;
      }
      part = (iVar1 % fontTracker.font_buffer._472_4_ << 0xc) / fontTracker.font_buffer._472_4_;
      FX_GetLinePoint(radius,next_radius,deg,next_deg,&local_48,(int *)&local_44,part);
      FX_GetLinePoint(radius + 0x1c00,next_radius + 0x1c00,deg,next_deg,&local_40,(int *)&local_3c,
                      part);
      FX_GetLinePoint(radius + -0x1c00,next_radius + -0x1c00,deg,next_deg,&local_38,(int *)&local_34
                      ,part);
      part = next_deg;
      iVar2 = next_radius;
    }
    else {
      radius = next_deg + 0x440;
      deg = deg + degchange;
      FX_GetSpiralPoint(radius,deg,&local_48,(int *)&local_44);
      FX_GetSpiralPoint((int)(&UNK_00002040 + next_deg),deg,&local_40,(int *)&local_3c);
      FX_GetSpiralPoint(next_deg + -0x17c0,deg,&local_38,(int *)&local_34);
    }
    next_deg = iVar1 * 4;
    *(undefined2 *)(&Spiral_Array + next_deg) = (undefined2)local_48;
    *(undefined2 *)(&CHAR____800d15b6 + next_deg) = (undefined2)local_44;
    if (iVar1 == 0x3f) {
      local_40 = local_48;
      local_3c = local_44;
      local_38 = local_48;
      local_34 = local_44;
    }
    *(undefined2 *)(&Spiral_OffsetP + next_deg) = (undefined2)local_40;
    *(undefined2 *)(&CHAR____800d16c6 + next_deg) = (undefined2)local_3c;
    if (iVar4 <= local_40) break;
    if (iVar3 < local_40) {
      iVar3 = local_40;
    }
    if ((int)local_3c < (int)local_30) {
      local_30 = local_3c;
    }
    if ((int)local_3c <= (int)uVar5) {
      FX_Start_Rain(local_3c & 0xffff);
      return;
    }
    next_radius = iVar1 + 1;
    (&fontTracker.font_buffer[0x22].x)[iVar1 * 2] = (short)local_38;
    (&fontTracker.font_buffer[0x22].y)[iVar1 * 2] = (short)local_34;
    next_deg = radius;
    iVar1 = next_radius;
    iVar4 = local_40;
    uVar5 = local_3c;
    if (0x3f < next_radius) {
      deg = ((iVar3 - local_40) / 2) * 0x140;
      if (deg < 0) {
        deg = deg + 0x1ff;
      }
                    /* WARNING: Read-only address (ram,0x800d18cc) is written */
                    /* WARNING: Read-only address (ram,0x800d18c4) is written */
      fontTracker.font_buffer._460_4_ = (local_40 + iVar3) / 2;
      fontTracker.font_buffer[77]._2_4_ = (int)(local_30 + local_3c) / 2;
      fontTracker.font_buffer[78]._0_4_ = (deg >> 9) + 2;
                    /* WARNING: Read-only address (ram,0x800d18c8) is written */
      return;
    }
  }
  FX_Start_Snow(local_3c & 0xffff);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Spiral(struct _PrimPool *primPool /*stack 0*/, unsigned long **ot /*stack 4*/)
 // line 7224, offset 0x8004d5c8
	/* begin block 1 */
		// Start line: 7225
		// Start offset: 0x8004D5C8
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
			// Start line: 7361
			// Start offset: 0x8004D7C4
			// Variables:
		// 		int tmp; // $v1
		/* end block 1.1 */
		// End offset: 0x8004D820
		// End Line: 7375

		/* begin block 1.2 */
			// Start line: 7458
			// Start offset: 0x8004D964
			// Variables:
		// 		static short deg; // offset 0x6e
		// 		struct _Vector f1; // stack offset -96
		/* end block 1.2 */
		// End offset: 0x8004D9B8
		// End Line: 7473
	/* end block 1 */
	// End offset: 0x8004D9B8
	// End Line: 7479

	/* begin block 2 */
		// Start line: 17543
	/* end block 2 */
	// End Line: 17544

/* WARNING: Removing unreachable block (ram,0x8004d7dc) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FX_Spiral(_PrimPool *primPool,ulong **ot)

{
  short sVar1;
  uint uVar2;
  long lVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint angle;
  uint uVar10;
  int iVar11;
  _Vector local_60;
  uint local_50;
  uint local_4c;
  int local_48;
  uint local_44;
  uint local_40;
  uint *local_38;
  int local_34;
  uint local_30;
  uint local_2c;
  
  if (((theCamera.core.vvNormalWorVecMat[0].m[2][2] != 1000) &&
      (theCamera.core.vvNormalWorVecMat[0]._18_2_ == 0)) && (Spiral_Number != 0)) {
    FX_Health_Spiral(1,Spiral_Current,Spiral_Max);
  }
  local_2c = 0x3afcffd3;
  local_30 = 0x3adce0ba;
  angle = 0x3a483017;
  local_4c = 0x3a002a15;
  local_44 = 0x3abbc09d;
  if (Spiral_Number == 0) {
    if (Spiral_Current == Spiral_Max) {
      DAT_800cebd0 = DAT_800cebd0 + 1;
      if (0x50 < DAT_800cebd0) {
        DAT_800cebd0 = 0;
      }
    }
    else {
      local_2c = 0x3a00ff00;
      local_30 = 0x3a00e000;
      local_44 = 0x3a00bf00;
      angle = 0x3a004500;
    }
    local_4c = 0x3a00150b;
  }
  else {
    DAT_800cebd0 = DAT_800cebd0 + 1;
    if (0x50 < DAT_800cebd0) {
      DAT_800cebd0 = 0;
    }
  }
  lVar3 = Spiral_Max;
  if (Spiral_Max < 0) {
    lVar3 = Spiral_Max + 0x3f;
  }
  local_34 = lVar3 >> 6;
  iVar11 = Spiral_Current / local_34;
  puVar6 = primPool->nextPrim;
  local_34 = ((Spiral_Current - iVar11 * local_34) * 0x1000) / local_34;
  if (puVar6 + 0x451 < primPool->lastPrim) {
    iVar5 = 0;
    local_38 = &local_50;
    local_40 = local_2c & 0xff000000;
    local_48 = (int)DAT_800cebd0;
    puVar4 = puVar6 + 0x10;
    uVar8 = _CHAR____800d16b4;
    uVar9 = _CHAR____800d16b4;
    uVar10 = _CHAR____800d16b4;
    local_50 = local_4c;
    do {
      puVar7 = puVar6;
      puVar4[-0xb] = local_50;
      puVar4[-7] = local_50;
      local_50 = local_4c;
      if (iVar5 <= iVar11) {
        uVar2 = (int)(iVar5 + local_48 & 0xfU) >> 2;
        local_50 = local_30;
        if (uVar2 != 1) {
          if (uVar2 < 2) {
LAB_8004d808:
            local_50 = local_2c;
          }
          else {
            if (uVar2 == 2) {
              local_50 = local_44;
            }
            else {
              if (uVar2 != 3) goto LAB_8004d808;
            }
          }
        }
      }
      if (iVar5 == iVar11) {
                    /* WARNING: Subroutine does not return */
        LoadAverageCol((byte *)local_38,(byte *)&local_4c,local_34,0x1000 - local_34,
                       (undefined *)local_38);
      }
      puVar4[-0xf] = angle;
      puVar4[-0xd] = angle;
      puVar4[-3] = angle;
      puVar4[-1] = angle;
      puVar4[-6] = uVar8;
      puVar4[-10] = uVar8;
      puVar4[-0xe] = uVar10;
      puVar4[-2] = uVar9;
      puVar4[-9] = local_50;
      puVar4[-5] = local_50;
      uVar8 = *(uint *)(&Spiral_Array + iVar5 * 4);
      uVar10 = *(uint *)(&Spiral_OffsetP + iVar5 * 4);
      uVar9 = *(uint *)(&fontTracker.font_buffer[0x22].x + iVar5 * 2);
      iVar5 = iVar5 + 1;
      puVar4[-4] = uVar8;
      puVar4[-8] = uVar8;
      puVar4[-0xc] = uVar10;
      *puVar4 = uVar9;
      puVar4 = puVar4 + 0x11;
      *puVar7 = (uint)ot[1] & 0xffffff | 0x10000000;
      ot[1] = (ulong *)((uint)puVar7 & 0xffffff);
      puVar6 = puVar7 + 0x11;
    } while (iVar5 < 0x40);
    puVar7[0x12] = 0xe1000620;
    sVar1 = Spiral_Number;
    *puVar6 = (uint)ot[1] & 0xffffff | 0x1000000;
    ot[1] = (ulong *)((uint)puVar6 & 0xffffff);
    primPool->nextPrim = puVar7 + 0x13;
    if ((sVar1 != 0) || (Spiral_Current == Spiral_Max)) {
      local_60.y = fontTracker.font_buffer[77]._2_4_;
      angle = (uint)DAT_800cebd2 - 0x20 & 0xfff;
      local_60.x = fontTracker.font_buffer._460_4_;
      DAT_800cebd2 = (ushort)angle;
      DRAW_CreateAGlowingCircle
                (&local_60,0x140,(_PrimPool *)theCamera.core.vvPlaneConsts[2],ot,5,0x8000,
                 fontTracker.font_buffer[78]._0_4_,fontTracker.font_buffer[78]._0_4_,angle);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Health_Spiral(int number /*$a0*/, int current_health /*$s0*/, int max_health /*$s1*/)
 // line 7481, offset 0x8004d9e8
	/* begin block 1 */
		// Start line: 7482
		// Start offset: 0x8004D9E8
		// Variables:
	// 		int degchange; // $v1
	/* end block 1 */
	// End offset: 0x8004DB20
	// End Line: 7529

	/* begin block 2 */
		// Start line: 18280
	/* end block 2 */
	// End Line: 18281

void FX_Health_Spiral(int number,int current_health,int max_health)

{
  bool bVar1;
  short sVar2;
  
  if (number == 0) {
    if (fontTracker.font_buffer._472_4_ < 6) {
                    /* WARNING (jumptable): Read-only address (ram,0x800d18d0) is written */
                    /* WARNING: Read-only address (ram,0x800d18d0) is written */
      Spiral_Number = 0;
      fontTracker.font_buffer._472_4_ = fontTracker.font_buffer._472_4_ + 1;
      FX_CalcSpiral(0x80);
      return;
    }
  }
  else {
    if (1 < fontTracker.font_buffer._472_4_) {
      fontTracker.font_buffer._472_4_ = fontTracker.font_buffer._472_4_ + -1;
                    /* WARNING (jumptable): Read-only address (ram,0x800d18d0) is written */
                    /* WARNING: Read-only address (ram,0x800d18d0) is written */
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
    if (Spiral_Degrees <= sVar2) goto LAB_8004db0c;
    bVar1 = (short)(Spiral_Degrees + -4) < sVar2;
    Spiral_Degrees = Spiral_Degrees + -4;
  }
  if (bVar1) {
    Spiral_Degrees = sVar2;
  }
LAB_8004db0c:
  FX_CalcSpiral((int)Spiral_Degrees);
  Spiral_Current = current_health;
  Spiral_Max = max_health;
                    /* WARNING: Read-only address (ram,0x800d18d0) is written */
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Spiral_Init()
 // line 7531, offset 0x8004db34
	/* begin block 1 */
		// Start line: 18380
	/* end block 1 */
	// End Line: 18381

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FX_CalcSpiral(int degchange)

{
  _UCHAR_00h_800cf3d4 = 100000;
  _UCHAR_a_800cf3d0 = 100000;
  _UCHAR_a_800cf3cc = 1;
  _UCHAR_u_800cf3ce = 0x80;
  FX_CalcSpiral(0x80);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawModel(struct Object *object /*$s6*/, int model_num /*$s7*/, struct _SVector *rotation /*$s0*/, struct _SVector *position /*$s1*/, struct _SVector *offset /*stack 16*/, int transflag /*stack 20*/)
 // line 7560, offset 0x8004db74
	/* begin block 1 */
		// Start line: 7561
		// Start offset: 0x8004DB74
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
			// Start line: 7604
			// Start offset: 0x8004DCA0
			// Variables:
		// 		long clip; // stack offset -48
		/* end block 1.1 */
		// End offset: 0x8004DD98
		// End Line: 7632
	/* end block 1 */
	// End offset: 0x8004DDC0
	// End Line: 7639

	/* begin block 2 */
		// Start line: 18441
	/* end block 2 */
	// End Line: 18442

	/* begin block 3 */
		// Start line: 18453
	/* end block 3 */
	// End Line: 18454

void FX_DrawModel(Object *object,int model_num,_SVector *rotation,_SVector *position,
                 _SVector *offset,int transflag)

{
  MATRIX MStack88;
  
  PushMatrix();
  MATH3D_SetUnityMatrix(&MStack88);
                    /* WARNING: Subroutine does not return */
  RotMatrixX((int)rotation->x,(int)&MStack88);
}



// decompiled code
// original method signature: 
// void /*$ra*/ fx_calc_points(struct _SVector *points /*$s1*/, int degrees /*$s0*/, int radius /*$s3*/, int radius2 /*$s4*/, int radius3 /*stack 16*/)
 // line 7653, offset 0x8004ddec
	/* begin block 1 */
		// Start line: 7654
		// Start offset: 0x8004DDEC
		// Variables:
	// 		int cosval; // $s0
	// 		int sinval; // $v0
	/* end block 1 */
	// End offset: 0x8004DDEC
	// End Line: 7654

	/* begin block 2 */
		// Start line: 18657
	/* end block 2 */
	// End Line: 18658

void fx_calc_points(_SVector *points,int degrees,int radius,int radius2,int radius3)

{
                    /* WARNING: Subroutine does not return */
  rcos(degrees);
}



// decompiled code
// original method signature: 
// long /*$ra*/ fx_get_startz(struct _SVector *position /*$a0*/)
 // line 7671, offset 0x8004defc
	/* begin block 1 */
		// Start line: 7672
		// Start offset: 0x8004DEFC
		// Variables:
	// 		struct MATRIX tmpmat; // stack offset -40
	/* end block 1 */
	// End offset: 0x8004DF44
	// End Line: 7680

	/* begin block 2 */
		// Start line: 18700
	/* end block 2 */
	// End Line: 18701

void fx_get_startz(undefined4 *param_1)

{
  undefined4 in_zero;
  undefined4 in_at;
  undefined auStack40 [20];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  setCopReg(2,in_zero,*param_1);
  setCopReg(2,in_at,param_1[1]);
  copFunction(2,0x480012);
  local_14 = getCopReg(2,0x19);
  local_10 = getCopReg(2,0x1a);
  local_c = getCopReg(2,0x1b);
                    /* WARNING: Subroutine does not return */
  SetTransMatrix((int)auStack40);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawRing(struct MATRIX *wcTransform /*$s0*/, struct _SVector *position /*$s3*/, struct MATRIX *matrix /*$s4*/, int radius /*stack 12*/, int radius2 /*stack 16*/, int radius3 /*stack 20*/, int z1 /*stack 24*/, int z2 /*stack 28*/, int z3 /*stack 32*/, long color /*stack 36*/, int sortInWorld /*stack 40*/)
 // line 7705, offset 0x8004df54
	/* begin block 1 */
		// Start line: 7706
		// Start offset: 0x8004DF54
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
	// End offset: 0x8004E1D0
	// End Line: 7782

	/* begin block 2 */
		// Start line: 18769
	/* end block 2 */
	// End Line: 18770

	/* begin block 3 */
		// Start line: 18779
	/* end block 3 */
	// End Line: 18780

void FX_DrawRing(MATRIX *wcTransform,_SVector *position,MATRIX *matrix,int radius,int radius2,
                int radius3,int z1,int z2,int z3,long color,int sortInWorld)

{
  if (*(int *)(theCamera.core.vvPlaneConsts[2] + 4) + 0x900U <
      *(uint *)(theCamera.core.vvPlaneConsts[2] + 8)) {
    PushMatrix();
    SetRotMatrix((undefined4 *)wcTransform);
                    /* WARNING: Subroutine does not return */
    SetTransMatrix((int)wcTransform);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ fx_setTex(struct DVECTOR *x /*$a0*/, unsigned char *uv /*$a1*/, int tx /*$a2*/, int offset /*$a3*/)
 // line 7785, offset 0x8004e200
	/* begin block 1 */
		// Start line: 18998
	/* end block 1 */
	// End Line: 18999

	/* begin block 2 */
		// Start line: 18999
	/* end block 2 */
	// End Line: 19000

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
 // line 7847, offset 0x8004e244
	/* begin block 1 */
		// Start line: 7848
		// Start offset: 0x8004E244
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
	// End offset: 0x8004E5EC
	// End Line: 7939

	/* begin block 2 */
		// Start line: 19122
	/* end block 2 */
	// End Line: 19123

void FX_DrawRing2(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = 0x20;
  if (param_4 < 0x78) {
    iVar1 = 8;
  }
  if ((uint)(*(int *)(iGpffffb538 + 4) + iVar1 * 0x28) < *(uint *)(iGpffffb538 + 8)) {
    PushMatrix();
    SetRotMatrix(param_1);
                    /* WARNING: Subroutine does not return */
    SetTransMatrix((int)param_1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_DrawFField(struct MATRIX *wcTransform /*$s2*/, struct _FXForceFieldEffect *field /*$s0*/)
 // line 7964, offset 0x8004e61c
	/* begin block 1 */
		// Start line: 7965
		// Start offset: 0x8004E61C
		// Variables:
	// 		struct _Instance *instance; // $a0
	// 		struct MATRIX tmpmat; // stack offset -64
	// 		struct _SVector position; // stack offset -32
	// 		int size; // $s1
	// 		short fade; // $v0
	// 		long color; // stack offset -20
	// 		long black; // stack offset -24
	/* end block 1 */
	// End offset: 0x8004E7F8
	// End Line: 8019

	/* begin block 2 */
		// Start line: 19458
	/* end block 2 */
	// End Line: 19459

void FX_DrawFField(MATRIX *wcTransform,_FXForceFieldEffect *field)

{
                    /* WARNING: Subroutine does not return */
  rcos((int)field->deg);
}



// decompiled code
// original method signature: 
// struct _FXForceFieldEffect * /*$ra*/ FX_StartFField(struct _Instance *instance /*$s2*/, int size /*$s3*/, struct _Position *offset /*$s1*/, int size_diff /*$s4*/, int size_change /*stack 16*/, int deg_change /*stack 20*/, long color /*stack 24*/)
 // line 8021, offset 0x8004e810
	/* begin block 1 */
		// Start line: 8022
		// Start offset: 0x8004E810
		// Variables:
	// 		struct _FXForceFieldEffect *field; // $s0

		/* begin block 1.1 */
			// Start line: 8027
			// Start offset: 0x8004E854
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a1
		// 		struct _SVector *_v0; // $v0
		/* end block 1.1 */
		// End offset: 0x8004E854
		// End Line: 8027
	/* end block 1 */
	// End offset: 0x8004E8C0
	// End Line: 8045

	/* begin block 2 */
		// Start line: 19583
	/* end block 2 */
	// End Line: 19584

_FXForceFieldEffect *
FX_StartFField(_Instance *instance,int size,_Position *offset,int size_diff,int size_change,
              int deg_change,long color)

{
                    /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(0x2c,'\r');
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_EndFField(struct _Instance *instance /*$a0*/)
 // line 8048, offset 0x8004e8e4
	/* begin block 1 */
		// Start line: 8050
		// Start offset: 0x8004E8E4
		// Variables:
	// 		struct _FXGeneralEffect *currentEffect; // $v1

		/* begin block 1.1 */
			// Start line: 8054
			// Start offset: 0x8004E91C
		/* end block 1.1 */
		// End offset: 0x8004E94C
		// End Line: 8066
	/* end block 1 */
	// End offset: 0x8004E95C
	// End Line: 8069

	/* begin block 2 */
		// Start line: 19644
	/* end block 2 */
	// End Line: 19645

	/* begin block 3 */
		// Start line: 19645
	/* end block 3 */
	// End Line: 19646

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
 // line 8071, offset 0x8004e964
	/* begin block 1 */
		// Start line: 8072
		// Start offset: 0x8004E964
		// Variables:
	// 		struct _POLY_2G4T *poly; // $t0
	// 		struct _PrimPool *primPool; // $t2
	// 		int negflag; // $t5
	/* end block 1 */
	// End offset: 0x8004EAF8
	// End Line: 8116

	/* begin block 2 */
		// Start line: 19690
	/* end block 2 */
	// End Line: 19691

void FX_Draw_Glowing_Line
               (ulong **ot,long otz,DVECTOR *sxy0,DVECTOR *sxy1,DVECTOR *xy0,DVECTOR *xy1,long color
               ,long color2)

{
  bool bVar1;
  long lVar2;
  DVECTOR DVar3;
  uint uVar4;
  _SVector *position;
  uint *puVar5;
  int in_stack_00000020;
  long in_stack_00000024;
  int in_stack_00000028;
  
  lVar2 = theCamera.core.vvPlaneConsts[2];
  if ((otz - 1U < 0xbff) &&
     (puVar5 = *(uint **)(theCamera.core.vvPlaneConsts[2] + 4),
     puVar5 + 0x12 < *(uint **)(theCamera.core.vvPlaneConsts[2] + 8))) {
    bVar1 = (color & 0x1000000U) != 0;
    uVar4 = color;
    if (bVar1) {
      uVar4 = color & 0xffffff;
    }
    position = (_SVector *)(uVar4 | 0x3a000000);
    *(_SVector **)(puVar5 + 6) = position;
    *(_SVector **)(puVar5 + 10) = position;
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
      FX_DrawRing2((MATRIX *)otz,position,(MATRIX *)sxy0,(int)sxy1,(int)xy0,(int)xy1,color,color2,
                   in_stack_00000020,in_stack_00000024,in_stack_00000028);
      return;
    }
    puVar5[1] = 0xe1000620;
    *puVar5 = (uint)ot[otz] & 0xffffff | 0x11000000;
    ot[otz] = (ulong *)((uint)puVar5 & 0xffffff);
    *(uint **)(lVar2 + 4) = puVar5 + 0x12;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_Lightning(struct MATRIX *wcTransform /*$s0*/, unsigned long **ot /*stack 4*/, struct MATRIX *mat /*stack 8*/, short deg /*$s1*/, struct _SVector *start /*stack 16*/, struct _SVector *end /*stack 20*/, int width /*stack 24*/, int small_width /*stack 28*/, int segs /*stack 32*/, int sine_size /*stack 36*/, int variation /*stack 40*/, long color /*stack 44*/, long glow_color /*stack 48*/)
 // line 8119, offset 0x8004eb00
	/* begin block 1 */
		// Start line: 8120
		// Start offset: 0x8004EB00
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
			// Start line: 8154
			// Start offset: 0x8004EBB4
			// Variables:
		// 		struct SVECTOR point; // stack offset -64

			/* begin block 1.1.1 */
				// Start line: 8162
				// Start offset: 0x8004EC04
				// Variables:
			// 		int rsin_n4; // $s0
			/* end block 1.1.1 */
			// End offset: 0x8004ECF0
			// End Line: 8166

			/* begin block 1.1.2 */
				// Start line: 8170
				// Start offset: 0x8004ED00
				// Variables:
			// 		int tmpdeg; // $s1
			/* end block 1.1.2 */
			// End offset: 0x8004EDC8
			// End Line: 8174

			/* begin block 1.1.3 */
				// Start line: 8188
				// Start offset: 0x8004EE30
				// Variables:
			// 		int fx; // $s2
			// 		int fy; // $s0
			/* end block 1.1.3 */
			// End offset: 0x8004EE78
			// End Line: 8196
		/* end block 1.1 */
		// End offset: 0x8004EF94
		// End Line: 8218
	/* end block 1 */
	// End offset: 0x8004EFC0
	// End Line: 8227

	/* begin block 2 */
		// Start line: 19793
	/* end block 2 */
	// End Line: 19794

void FX_Lightning(MATRIX *wcTransform,ulong **ot,MATRIX *mat,short deg,_SVector *start,_SVector *end
                 ,int width,int small_width,int segs,int sine_size,int variation,long color,
                 long glow_color)

{
  if (mat == (MATRIX *)0x0) {
    SetRotMatrix((undefined4 *)wcTransform);
  }
  else {
    SetRotMatrix((undefined4 *)mat);
    wcTransform = mat;
  }
                    /* WARNING: Subroutine does not return */
  SetTransMatrix((int)wcTransform);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_LightHouse(struct MATRIX *wcTransform /*$s0*/, unsigned long **ot /*stack 4*/, struct _Instance *instance /*$a2*/, int startSeg /*$a3*/, int endSeg /*stack 16*/, int segs /*stack 20*/, long beam_color /*stack 24*/)
 // line 8232, offset 0x8004eff0
	/* begin block 1 */
		// Start line: 8233
		// Start offset: 0x8004EFF0
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
			// Start line: 8292
			// Start offset: 0x8004F138
			// Variables:
		// 		struct SVECTOR point; // stack offset -88

			/* begin block 1.1.1 */
				// Start line: 8303
				// Start offset: 0x8004F1B0
				// Variables:
			// 		int newlength; // $v1
			// 		int newfx; // $s1
			// 		int newfy; // $s0
			/* end block 1.1.1 */
			// End offset: 0x8004F1F4
			// End Line: 8317
		/* end block 1.1 */
		// End offset: 0x8004F214
		// End Line: 8324

		/* begin block 1.2 */
			// Start line: 8335
			// Start offset: 0x8004F248
			// Variables:
		// 		struct SVECTOR point; // stack offset -80

			/* begin block 1.2.1 */
				// Start line: 8357
				// Start offset: 0x8004F330
				// Variables:
			// 		int x; // $v0
			/* end block 1.2.1 */
			// End offset: 0x8004F3BC
			// End Line: 8369
		/* end block 1.2 */
		// End offset: 0x8004F40C
		// End Line: 8378
	/* end block 1 */
	// End offset: 0x8004F43C
	// End Line: 8388

	/* begin block 2 */
		// Start line: 20062
	/* end block 2 */
	// End Line: 20063

void FX_LightHouse(MATRIX *wcTransform,ulong **ot,_Instance *instance,int startSeg,int endSeg,
                  int segs,long beam_color)

{
  if ((instance->flags & 0x800U) == 0) {
    if (instance->matrix != (MATRIX *)0x0) {
      SetRotMatrix((undefined4 *)wcTransform);
                    /* WARNING: Subroutine does not return */
      SetTransMatrix((int)wcTransform);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_StartPassthruFX(struct _Instance *instance /*$s0*/, struct _SVector *normal /*$a1*/, struct _SVector *point /*$a2*/)
 // line 8391, offset 0x8004f46c
	/* begin block 1 */
		// Start line: 8392
		// Start offset: 0x8004F46C
		// Variables:
	// 		long color; // stack offset -24
	/* end block 1 */
	// End offset: 0x8004F46C
	// End Line: 8392

	/* begin block 2 */
		// Start line: 20457
	/* end block 2 */
	// End Line: 20458

void FX_StartPassthruFX(_Instance *param_1,short *param_2,short *param_3)

{
  long local_18 [2];
  
  (param_1->halvePlane).a = *param_2;
  (param_1->halvePlane).b = param_2[1];
  (param_1->halvePlane).c = param_2[2];
  local_18[0] = 0x20ff40;
  (param_1->halvePlane).d =
       -((int)*param_2 * (int)*param_3 + (int)param_2[1] * (int)param_3[1] +
         (int)param_2[2] * (int)param_3[2] >> 0xc);
  FX_DoInstancePowerRing(param_1,(long)&DAT_000020d0,local_18,0,2);
  FX_DoInstancePowerRing(param_1,(long)&DAT_000020d0,local_18,0,1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_EndPassthruFX(struct _Instance *instance /*$a0*/)
 // line 8409, offset 0x8004f548
	/* begin block 1 */
		// Start line: 20509
	/* end block 1 */
	// End Line: 20510

void FX_EndPassthruFX(_Instance *param_1)

{
  FX_EndInstanceEffects(param_1);
  return;
}





