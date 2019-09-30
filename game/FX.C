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
 // line 186, offset 0x80042a30
	/* begin block 1 */
		// Start line: 367
	/* end block 1 */
	// End Line: 368

	/* begin block 2 */
		// Start line: 416
	/* end block 2 */
	// End Line: 417

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

_FXParticle * FX_GetParticle(_Instance *instance,short startSegment)

{
                    /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(0x4c,'\r');
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

void FX_AniTexSetup(_FX_PRIM *fxPrim,_MFace *mface,_Model *model,_FXTracker *fxTracker)

{
  AniTex *pAVar1;
  
  if ((mface->flags & 2) != 0) {
    fxPrim->flags = fxPrim->flags | 1;
    fxPrim->texture = (TextureMT3 *)mface->color;
    if (model->aniTextures != (AniTex *)0x0) {
      fxPrim->flags = fxPrim->flags | 4;
      (fxPrim->ani).texMem = fxPrim->texture;
      pAVar1 = model->aniTextures;
      (fxPrim->ani).curFrame = 0;
      (fxPrim->ani).aniTextures = pAVar1;
    }
    _FX_DoLighting((char)fxPrim);
    return;
  }
  fxPrim->flags = fxPrim->flags & 0xfffffffa;
  fxPrim->color = mface->color & 0x3ffffffU | 0x20000000;
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

void FX_ShatterProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  undefined local_20 [16];
  
                    /* WARNING: Subroutine does not return */
  memset(local_20,0,8);
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
                    /* WARNING: Subroutine does not return */
      RotMatrixZ((int)(short)((int)cVar2 << 2),(uint *)&fxPrim->matrix->lwTransform);
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
 // line 883, offset 0x80043248
	/* begin block 1 */
		// Start line: 1718
	/* end block 1 */
	// End Line: 1719

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
  _VertexPool *local_3c;
  CVECTOR *local_38;
  
  local_3c = gameTrackerX.vertexPool;
  local_38 = (gameTrackerX.vertexPool)->color;
  local_44 = instance->object->modelList[instance->currentModel];
  local_58 = (undefined2)shardFlags;
  local_40 = local_44->vertexList;
  PIPE3D_TransformVerticesToWorld
            (instance,(_SVector *)gameTrackerX.vertexPool,(long *)local_38,local_70);
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

void _FX_BuildNonSegmentedSplinters
               (_Instance *instance,SVECTOR *center,SVECTOR *vel,SVECTOR *accl,FXSplinter *splintDef
               ,_FXTracker *fxTracker,TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup fxSetup,
               TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess fxProcess,int shardFlags)

{
  _VertexPool *p_Var1;
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
  _PVertex *p_Var13;
  int iVar14;
  _PVertex *p_Var15;
  _MFace *mface;
  _PVertex *p_Var16;
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
  
  p_Var1 = gameTrackerX.vertexPool;
  local_3c = instance->object->modelList[instance->currentModel];
  local_38 = local_3c->vertexList;
  mface = local_3c->faceList;
  local_70 = 0xf;
  local_6c[0] = (undefined *)0x60064;
  local_6c[1] = &DAT_0000fff1;
  local_6c[2] = (undefined *)0x60064;
  local_6c[3] = &DAT_000f0000;
  local_5c = (undefined *)0x60064;
  local_58 = 0xfff10000;
  local_54 = (undefined *)0x60064;
  local_50 = (ushort)shardFlags;
  PIPE3D_TransformVerticesToWorld
            (instance,(_SVector *)gameTrackerX.vertexPool,(long *)(gameTrackerX.vertexPool)->color,
             (_Vector *)&local_98);
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
    *(undefined4 *)(p_Var3->lwTransform).m = local_b8;
    *(undefined4 *)((p_Var3->lwTransform).m + 2) = local_b4;
    *(undefined4 *)((p_Var3->lwTransform).m + 4) = local_b0;
    *(undefined4 *)((p_Var3->lwTransform).m + 6) = local_ac;
    *(undefined4 *)((p_Var3->lwTransform).m + 8) = local_a8;
    (p_Var3->lwTransform).t[0] = local_a4;
    (p_Var3->lwTransform).t[1] = local_a0;
    (p_Var3->lwTransform).t[2] = local_9c;
    iVar4 = iVar8 * 8;
    puVar11 = &local_70 + iVar8 * 2;
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
      p_Var13 = p_Var1->vertex + (mface->face).v0;
      p_Var15 = p_Var1->vertex + (mface->face).v1;
      p_Var16 = p_Var1->vertex + (mface->face).v2;
      iVar8 = (int)p_Var13->x + (int)p_Var15->x + (int)p_Var16->x;
      iVar9 = (int)((ulonglong)((longlong)iVar8 * (longlong)local_34) >> 0x20) - (iVar8 >> 0x1f);
      local_80 = (undefined2)iVar9;
      iVar8 = (int)(&p_Var13->x)[1] + (int)(&p_Var15->x)[1] + (int)(&p_Var16->x)[1];
      iVar8 = (int)((ulonglong)((longlong)iVar8 * (longlong)local_34) >> 0x20) - (iVar8 >> 0x1f);
      local_7e = (undefined2)iVar8;
      iVar4 = (int)(&p_Var13->x)[2] + (int)(&p_Var15->x)[2] + (int)(&p_Var16->x)[2];
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
          (fxPrim->v0).x = p_Var13->x - local_88;
          (fxPrim->v0).y = (&p_Var13->x)[1] - local_86;
          (fxPrim->v0).z = (&p_Var13->x)[2] - local_84;
          (fxPrim->v1).x = p_Var15->x - local_88;
          (fxPrim->v1).y = (&p_Var15->x)[1] - local_86;
          (fxPrim->v1).z = (&p_Var15->x)[2] - local_84;
          (fxPrim->v2).x = p_Var16->x - local_88;
          (fxPrim->v2).y = (&p_Var16->x)[1] - local_86;
          sVar2 = (&p_Var16->x)[2];
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
          fxPrim->timeToLive = local_48;
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
 // line 1537, offset 0x80044a74
	/* begin block 1 */
		// Start line: 3749
	/* end block 1 */
	// End Line: 3750

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
                    /* WARNING: Subroutine does not return */
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

void _FX_Build(_Instance *instance,SVECTOR *center,SVECTOR *vel,SVECTOR *accl,_FXTracker *fxTracker,
              TDRFuncPtr__FX_Build5fxSetup fxSetup,TDRFuncPtr__FX_Build6fxProcess fxProcess,
              int shardFlags)

{
  long lVar1;
  undefined oldObject;
  undefined newObject;
  
  newObject = SUB41(center,0);
  oldObject = SUB41(instance,0);
  lVar1 = MEMPACK_MemoryValidFunc((char *)instance->object);
  if (lVar1 != 0) {
    if (instance->object->modelList[instance->currentModel]->numSegments < 4) {
      _FX_BuildNonSegmentedSplinters
                (instance,center,vel,accl,(FXSplinter *)0x0,fxTracker,
                 (TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup)fxSetup,
                 (TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess)fxProcess,
                 (int)(short)shardFlags);
      FX_RelocateFXPointers(oldObject,newObject,(long)vel);
      return;
    }
    _FX_BuildSegmentedSplinters
              (instance,center,vel,accl,(FXSplinter *)0x0,fxTracker,
               (TDRFuncPtr__FX_BuildSegmentedSplinters6fxSetup)fxSetup,
               (TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess)fxProcess,(int)(short)shardFlags);
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
      fxPrim->timeToLive = fxPrim->timeToLive + (int)offset->z;
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
 // line 1818, offset 0x80045018
	/* begin block 1 */
		// Start line: 4334
	/* end block 1 */
	// End Line: 4335

	/* begin block 2 */
		// Start line: 4335
	/* end block 2 */
	// End Line: 4336

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
 // line 1957, offset 0x80045380
	/* begin block 1 */
		// Start line: 4646
	/* end block 1 */
	// End Line: 4647

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
  NodeType *pNVar21;
  NodeType **ppNVar22;
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
    ppNVar22 = (NodeType **)(puVar19 + 1);
    do {
      if (p_Var24->lastPrim <= puVar19 + 10) break;
      pNVar21 = pNVar18[1].next;
      pNVar23 = pNVar18->next;
      if (((uint)pNVar21 & 0x10) == 0) {
        if (((uint)pNVar21 & 0x10000) == 0) {
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
        if (((uint)pNVar21 & 0x2000) == 0) {
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
        if (((uint)pNVar21 & 0x1000000) == 0) {
          if (((uint)pNVar21 & 0x4000) == 0) {
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
        if (((uint)pNVar21 & 0x8000) != 0) {
          local_34 = local_34 + -0x14;
        }
        if (local_34 - 1U < 0xbff) {
          if (((uint)pNVar21 & 1) == 0) {
            if (((uint)pNVar21 & 8) == 0) {
              if (((uint)pNVar21 & 0x1000000) == 0) {
                *ppNVar22 = pNVar18[3].next;
                uVar4 = getCopReg(2,0xc);
                puVar19[2] = uVar4;
                uVar4 = getCopReg(2,0xd);
                puVar19[3] = uVar4;
                uVar4 = getCopReg(2,0xe);
                puVar19[4] = uVar4;
                ppNVar22 = ppNVar22 + 5;
                *puVar19 = (uint)ot[local_34] & 0xffffff | 0x4000000;
                puVar20 = puVar19 + 5;
              }
              else {
                if (((uint)pNVar21 & 0x80000) == 0) goto LAB_80045de0;
                ppNVar22[1] = pNVar18[3].next;
                pNVar18 = pNVar18[4].next;
                *ppNVar22 = (NodeType *)0xe1000620;
                ppNVar22[3] = pNVar18;
                uVar4 = getCopReg(2,0xc);
                puVar19[5] = uVar4;
                uVar4 = getCopReg(2,0xd);
                puVar19[3] = uVar4;
                *(undefined *)((int)ppNVar22 + 7) = 0x52;
                ppNVar22 = ppNVar22 + 6;
                *puVar19 = (uint)ot[local_34] & 0xffffff | 0x5000000;
                puVar20 = puVar19 + 6;
              }
            }
            else {
              if (((uint)pNVar21 & 0x80000) != 0) {
                uVar4 = getCopReg(2,0xc);
                puVar19[3] = uVar4;
                uVar4 = getCopReg(2,0xd);
                puVar19[5] = uVar4;
                uVar4 = getCopReg(2,0xe);
                puVar19[7] = uVar4;
                setCopReg(2,in_zero,pNVar18[10].next);
                setCopReg(2,in_at,pNVar18[0xb].prev);
                copFunction(2,0x180001);
                *ppNVar22 = (NodeType *)0xe1000620;
                uVar4 = getCopReg(2,0xe);
                puVar19[9] = uVar4;
                gameTracker = (GameTracker *)(puVar19 + 2);
                iVar12 = 0;
                pNVar21 = pNVar18;
                do {
                  setCopReg(2,0x4000,0x1000 - (int)*(short *)&pNVar21[6].next);
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
                  pNVar21 = (NodeType *)((int)&pNVar21->prev + 2);
                } while (iVar12 < 4);
                *puVar19 = (uint)ot[local_34] & 0xffffff | 0x9000000;
                ot[local_34] = (ulong *)((uint)puVar19 & 0xffffff);
                *(undefined *)((int)puVar19 + 0xb) = 0x3a;
                puVar19 = puVar19 + 10;
                ppNVar22 = ppNVar22 + 10;
                goto LAB_80045de0;
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
              *ppNVar22 = pNVar18[3].next;
              ppNVar22[2] = pNVar18[3].next;
              ppNVar22[4] = pNVar18[3].next;
              pNVar18 = pNVar18[3].next;
              *(undefined *)((int)ppNVar22 + -1) = 8;
              *(undefined *)((int)ppNVar22 + 3) = 0x38;
              ppNVar22[6] = pNVar18;
              uVar4 = getCopReg(2,0xe);
              puVar19[8] = uVar4;
              ppNVar22 = ppNVar22 + 9;
              *puVar19 = (uint)ot[local_34] & 0xffffff | 0x8000000;
              puVar20 = puVar19 + 9;
            }
          }
          else {
            if (((uint)pNVar21 & 4) == 0) {
              gameTracker = (GameTracker *)pNVar18[1].prev;
            }
            else {
              gameTracker = (GameTracker *)pNVar18[0xd].prev;
            }
            if (((uint)pNVar21 & 8) == 0) {
              uVar4 = getCopReg(2,0xc);
              puVar19[2] = uVar4;
              uVar4 = getCopReg(2,0xd);
              puVar19[4] = uVar4;
              uVar4 = getCopReg(2,0xe);
              puVar19[6] = uVar4;
              ppNVar22[2] = (NodeType *)(gameTracker->gameData).asmData.drawBackFaces;
              ppNVar22[4] = (NodeType *)(gameTracker->gameData).asmData.dispPage;
              ppNVar22[6] = *(NodeType **)&(gameTracker->gameData).asmData.MorphTime;
              if (((uint)pNVar21 & 0x1000) != 0) {
                bVar10 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                bVar11 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
                if (bVar10 < bVar11) {
                  bVar3 = bVar11 < bVar10;
                  if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar10) {
LAB_80045cf8:
                    cVar8 = *(char *)&(gameTracker->gameData).asmData.MorphTime;
                    goto LAB_80045cfc;
                  }
                  cVar8 = *(char *)&(gameTracker->gameData).asmData.drawBackFaces;
                }
                else {
                  if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar11)
                  goto LAB_80045cf8;
                  cVar8 = *(char *)&(gameTracker->gameData).asmData.dispPage;
LAB_80045cfc:
                  bVar10 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                  bVar11 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
                  bVar3 = bVar11 < bVar10;
                }
                if (bVar3) {
                  if (*(byte *)&(gameTracker->gameData).asmData.MorphTime < bVar10) {
                    cVar13 = *(char *)&(gameTracker->gameData).asmData.drawBackFaces;
                  }
                  else {
LAB_80045d54:
                    cVar13 = *(char *)&(gameTracker->gameData).asmData.MorphTime;
                  }
                }
                else {
                  if (bVar11 <= *(byte *)&(gameTracker->gameData).asmData.MorphTime)
                  goto LAB_80045d54;
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
              *ppNVar22 = pNVar18[3].next;
              ppNVar22 = ppNVar22 + 8;
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
LAB_80045a54:
                  bVar1 = *(byte *)&(gameTracker->gameData).asmData.MorphTime;
                  goto LAB_80045a58;
                }
                bVar1 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
              }
              else {
                if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar11)
                goto LAB_80045a54;
                bVar1 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
LAB_80045a58:
                bVar10 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                bVar11 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
                bVar3 = bVar11 < bVar10;
              }
              if (bVar3) {
                if (*(byte *)&(gameTracker->gameData).asmData.MorphTime < bVar10) {
                  uVar14 = (ushort)*(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                }
                else {
LAB_80045ab0:
                  uVar14 = (ushort)*(byte *)&(gameTracker->gameData).asmData.MorphTime;
                }
              }
              else {
                if (bVar11 <= *(byte *)&(gameTracker->gameData).asmData.MorphTime)
                goto LAB_80045ab0;
                uVar14 = (ushort)*(byte *)&(gameTracker->gameData).asmData.dispPage;
              }
              bVar10 = *(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1);
              bVar11 = *(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1);
              if (bVar10 < bVar11) {
                if (*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) <= bVar10) {
LAB_80045b0c:
                  bVar2 = *(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1);
                  goto LAB_80045b18;
                }
                bVar2 = *(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1);
              }
              else {
                if (*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) <= bVar11)
                goto LAB_80045b0c;
                bVar2 = *(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1);
LAB_80045b18:
                bVar10 = *(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1);
                bVar11 = *(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1);
              }
              if (bVar11 < bVar10) {
                if (*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) < bVar10) {
                  uVar9 = (ushort)*(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1)
                          << 8;
                }
                else {
LAB_80045b70:
                  uVar9 = (ushort)*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) <<
                          8;
                }
              }
              else {
                if (bVar11 <= *(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1))
                goto LAB_80045b70;
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
              if (((uint)pNVar21 & 0x1000) != 0) {
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
              *ppNVar22 = pNVar18[3].next;
              ppNVar22 = ppNVar22 + 10;
              *puVar19 = (uint)ot[local_34] & 0xffffff | 0x9000000;
              puVar20 = puVar19 + 10;
            }
          }
          ot[local_34] = (ulong *)((uint)puVar19 & 0xffffff);
          puVar19 = puVar20;
        }
      }
LAB_80045de0:
      pNVar18 = pNVar23;
    } while (pNVar23 != (NodeType *)0x0);
  }
                    /* WARNING: Subroutine does not return */
  SetRotMatrix((undefined4 *)wcTransform);
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

/* WARNING: Removing unreachable block (ram,0x800469b0) */
/* WARNING: Removing unreachable block (ram,0x800469c4) */
/* WARNING: Removing unreachable block (ram,0x80046a14) */

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
  if ((iVar5 * 0x10000 >> 0x10 < (int)sVar1) || (fxPrim->timeToLive < (int)(fxPrim->position).z)) {
    FX_Die(fxPrim,fxTracker);
  }
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

/* WARNING: Removing unreachable block (ram,0x80046b80) */
/* WARNING: Removing unreachable block (ram,0x80046b98) */

void FX_MakeWaterBubble(_SVector *position,_SVector *vel,_SVector *accl,long splashZ,
                       __BubbleParams *BP)

{
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
/* WARNING: Removing unreachable block (ram,0x80046ed8) */
/* WARNING: Removing unreachable block (ram,0x80046ee0) */
/* WARNING: Removing unreachable block (ram,0x80046ef4) */

void FX_MakeWarpArrow(int x,int y,int xsize,int ysize,int fade)

{
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

/* WARNING: Removing unreachable block (ram,0x80046fb0) */

void FX_MakeMannaIcon(int x,int y,int xsize,int ysize)

{
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

/* WARNING: Removing unreachable block (ram,0x80047068) */

void FX_MakeGlyphIcon(_Position *position,Object *glyphObject,int size,int glyphnum,int enabled)

{
  if ((glyphObject != (Object *)0x0) && (glyphnum != 7)) {
                    /* WARNING: Subroutine does not return */
    FX_GetTextureObject(glyphObject,0,glyphnum);
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

void FX_SoulDustProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  int iVar3;
  
  if (fxPrim->work1 < 0x20) {
    FX_Die(fxPrim,fxTracker);
    return;
  }
  sVar2 = fxPrim->work2;
  iVar3 = *(int *)(*(int *)&fxPrim->duo + 0x40) + *(int *)((int)&fxPrim->duo + 4) * 0x20;
  (fxPrim->position).x = *(short *)(iVar3 + 0x14);
  sVar2 = (fxPrim->v1).x + sVar2;
  (fxPrim->position).y = *(short *)(iVar3 + 0x18);
  sVar1 = *(short *)(iVar3 + 0x1c);
  (fxPrim->v1).x = sVar2;
                    /* WARNING: Subroutine does not return */
  (fxPrim->position).z = sVar1;
  rcos((int)sVar2);
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

void FX_MakeSoulDust(_Instance *instance,short segment)

{
                    /* WARNING: Subroutine does not return */
  rand();
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_WaterTrailProcess(struct _FX_PRIM *fxPrim /*$s0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 3331, offset 0x800475c8
	/* begin block 1 */
		// Start line: 6656
	/* end block 1 */
	// End Line: 6657

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

/* WARNING: Removing unreachable block (ram,0x80047780) */

void FX_MakeWaterTrail(_Instance *instance,int depth)

{
  int iVar1;
  
  if ((((instance->matrix != (MATRIX *)0x0) && (instance->oldMatrix != (MATRIX *)0x0)) &&
      (gameTrackerX.gameData.asmData.MorphType != 1)) &&
     (gameTrackerX.gameData.asmData.MorphTime == 1000)) {
    iVar1 = instance->matrix[1].t[2] - instance->oldMatrix[1].t[2];
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    if (0x14 < iVar1) {
                    /* WARNING: Subroutine does not return */
      rand();
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
 // line 3591, offset 0x80047cd8
	/* begin block 1 */
		// Start line: 8680
	/* end block 1 */
	// End Line: 8681

void FX_ConstrictProcess(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  short sVar1;
  
  if (FX_ConstrictStage == 1) {
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
      ratan2((int)sVar1 - (int)FX_ConstrictPosition.y,
             (int)(fxPrim->v2).x - (int)FX_ConstrictPosition.x);
    }
    sVar1 = (fxPrim->v0).y;
    fxPrim->fadeValue[1] = 0;
    fxPrim->fadeValue[0] = 0;
    fxPrim->fadeValue[3] = 0x1000;
    fxPrim->fadeValue[2] = 0x1000;
                    /* WARNING: Subroutine does not return */
    ratan2((int)sVar1 - (int)FX_ConstrictPosition.y,
           (int)(fxPrim->v0).x - (int)FX_ConstrictPosition.x);
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
 // line 3657, offset 0x80047f68
	/* begin block 1 */
		// Start line: 8847
	/* end block 1 */
	// End Line: 8848

	/* begin block 2 */
		// Start line: 8848
	/* end block 2 */
	// End Line: 8849

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

void FX_SubDividePrim(_FX_PRIM *fxPrim1,_FX_PRIM *fxPrim2)

{
  uint local_20 [4];
  
                    /* WARNING: Subroutine does not return */
  LoadAverageShort12((uint *)&fxPrim1->v0,(uint *)&fxPrim2->v2,0x800,0x800,local_20);
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
  undefined4 uStack80;
  undefined4 uStack76;
  short sStack68;
  short sStack60;
  undefined4 uStack56;
  undefined4 uStack52;
  
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
        uStack80 = *puVar2;
        uStack76 = puVar2[1];
        uStack56 = *(undefined4 *)(iVar8 + 8);
        uStack52 = *(undefined4 *)(iVar8 + 0xc);
        do {
          fxPrim1 = FX_GetPrim(fxTracker);
          if (fxPrim1 != (_FX_PRIM *)0x0) {
            (fxPrim1->position).x = *(short *)((int)&ribbon->vertexPool->vx + iVar19);
            (fxPrim1->position).y = *(short *)((int)&ribbon->vertexPool->vy + iVar19);
            (fxPrim1->position).z = *(short *)((int)&ribbon->vertexPool->vz + iVar19);
            *(undefined4 *)&fxPrim1->v0 = uStack80;
            (fxPrim1->v0).z = (short)uStack76;
            sStack68 = (short)uVar16;
            *(undefined4 *)&fxPrim1->v1 = uVar14;
            (fxPrim1->v1).z = sStack68;
            sStack60 = (short)uVar17;
            *(undefined4 *)&fxPrim1->v3 = uVar15;
            (fxPrim1->v3).z = sStack60;
            *(undefined4 *)&fxPrim1->v2 = uStack56;
            (fxPrim1->v2).z = (short)uStack52;
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
          uStack80 = uVar14;
          uStack76 = uVar16;
          uStack56 = uVar15;
          uStack52 = uVar17;
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
      RotMatrixX((int)*(char *)((int)&fxPrim->work2 + 1) << 2,(int)&fxPrim->matrix->lwTransform);
      RotMatrixY((int)(short)((int)cVar1 << 2),(uint *)&fxPrim->matrix->lwTransform);
                    /* WARNING: Subroutine does not return */
      RotMatrixZ((int)(short)((int)cVar2 << 2),(uint *)&fxPrim->matrix->lwTransform);
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
                    /* WARNING: Subroutine does not return */
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
 // line 4312, offset 0x80049060
	/* begin block 1 */
		// Start line: 10484
	/* end block 1 */
	// End Line: 10485

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

void FX_Blood_Impale(_Instance *locinst,short locseg,_Instance *instance,short segment)

{
  _FX_PRIM *p_Var1;
  int iVar2;
  
  iVar2 = 1;
  do {
    p_Var1 = FX_GetPrim(gFXT);
    if (p_Var1 != (_FX_PRIM *)0x0) {
                    /* WARNING: Subroutine does not return */
      rand();
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x40);
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
                    /* WARNING: Subroutine does not return */
    ptr->primLifeTime = 10;
    FX_InsertGeneralEffect(ptr);
  }
  return (_FXParticle *)0x0;
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
                    /* WARNING: Subroutine does not return */
    ptr->flag_bits = uVar1 | 1;
    FX_InsertGeneralEffect(ptr);
  }
  return (_FXParticle *)0x0;
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
 // line 4517, offset 0x800495a8
	/* begin block 1 */
		// Start line: 10987
	/* end block 1 */
	// End Line: 10988

void FX_ConvertCamPersToWorld(SVECTOR *campos,SVECTOR *worldpos)

{
                    /* WARNING: Subroutine does not return */
  SetRotMatrix((undefined4 *)theCamera.core.cwTransform2);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_GetRandomScreenPt(struct SVECTOR *point /*$s0*/)
 // line 4537, offset 0x800496c0
	/* begin block 1 */
		// Start line: 11037
	/* end block 1 */
	// End Line: 11038

void FX_GetRandomScreenPt(SVECTOR *point)

{
                    /* WARNING: Subroutine does not return */
  rand();
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

void FX_ProcessSnow(_FX_PRIM *fxPrim,_FXTracker *fxTracker)

{
  SVECTOR SStack24;
  
  if (fxPrim->work0 == 9999) {
    if ((gameTrackerX.gameData.asmData.MorphType == 1) ||
       (gameTrackerX.gameData.asmData.MorphTime != 1000)) goto LAB_800497d0;
    fxPrim->work0 = 0;
    FX_GetRandomScreenPt(&SStack24);
    FX_ConvertCamPersToWorld(&SStack24,(SVECTOR *)&fxPrim->position);
  }
  if (0 < fxPrim->timeToLive) {
    fxPrim->timeToLive = fxPrim->timeToLive + -1;
  }
  if (fxPrim->timeToLive != 0) {
                    /* WARNING: Subroutine does not return */
    rand();
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

void FX_ContinueSnow(_FXTracker *fxTracker)

{
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
                    /* WARNING: Subroutine does not return */
  rand();
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

void FX_UpdateWind(_FXTracker *fxTracker)

{
                    /* WARNING: Subroutine does not return */
  rand();
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_ProcessRain(struct _FX_PRIM *fxPrim /*$a2*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 4648, offset 0x80049b40
	/* begin block 1 */
		// Start line: 11276
	/* end block 1 */
	// End Line: 11277

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

void FX_ContinueRain(_FXTracker *fxTracker)

{
  if (gameTrackerX.gameData.asmData._8_4_ == &PTR_000103e8) {
    return;
  }
  if (gameTrackerX.gameData.asmData.MorphTime != 1000) {
    FX_GetMorphFadeVal();
  }
                    /* WARNING: Subroutine does not return */
  STREAM_GetLevelWithID((gameTrackerX.playerInstance)->currentStreamUnitID);
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

/* WARNING: Removing unreachable block (ram,0x80049eb8) */
/* WARNING: Removing unreachable block (ram,0x80049ed0) */

void FX_MakeSpark(_Instance *instance,_Model *model,int segment)

{
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

void FX_ContinueParticle(_FXParticle *currentParticle,_FXTracker *fxTracker)

{
  _FX_PRIM *p_Var1;
  int iVar2;
  _Instance *instance;
  int iVar3;
  
  iVar2 = (int)currentParticle->numberBirthParticles;
  if (iVar2 < 0) {
                    /* WARNING: Subroutine does not return */
    rand();
  }
  instance = currentParticle->instance;
  if ((((((instance->flags & 0x800U) == 0) && ((instance->flags2 & 0x4000000U) == 0)) &&
       ((instance->flags & 0x200U) != 0)) &&
      ((instance->matrix != (MATRIX *)0x0 && (instance->oldMatrix != (MATRIX *)0x0)))) &&
     (0 < iVar2)) {
    if ((instance != gameTrackerX.playerInstance) &&
       (gameTrackerX.gameData.asmData.MorphTime != 1000)) {
      INSTANCE_GetFadeValue(instance);
    }
    iVar3 = 0;
    if (0 < iVar2) {
      do {
        p_Var1 = FX_GetPrim(gFXT);
        if (p_Var1 != (_FX_PRIM *)0x0) {
                    /* WARNING: Subroutine does not return */
          rand();
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar2);
    }
  }
  if ((0 < currentParticle->lifeTime) &&
     (iVar2 = (uint)(ushort)currentParticle->lifeTime - (uint)(ushort)FX_Frames,
     currentParticle->lifeTime = (short)iVar2, iVar2 * 0x10000 < 1)) {
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

void FX_UpdraftPrimModify
               (_FX_PRIM *fxPrim,_Instance *instance,_FXParticle *particle,_FXTracker *fxTracker)

{
                    /* WARNING: Subroutine does not return */
  rand();
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_MakeParticleTexFX(struct _FX_PRIM *fxPrim /*$s0*/, struct _SVector *position /*$a1*/, struct Object *object /*$s1*/, int modelnum /*$s4*/, int texnum /*stack 16*/, struct _SVector *vel /*stack 20*/, struct _SVector *accl /*stack 24*/, long color /*stack 28*/, int size /*stack 32*/, int life /*stack 36*/)
 // line 4994, offset 0x8004a8dc
	/* begin block 1 */
		// Start line: 12308
	/* end block 1 */
	// End Line: 12309

void FX_MakeParticleTexFX
               (_FX_PRIM *fxPrim,_SVector *position,Object *object,int modelnum,int texnum,
               _SVector *vel,_SVector *accl,long color,int size,int life)

{
  if ((object != (Object *)0x0) && (fxPrim != (_FX_PRIM *)0x0)) {
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

void FX_MakeHitFX(_SVector *position)

{
  _FX_PRIM *fxPrim;
  
  fxPrim = FX_GetPrim(gFXT);
  if (fxPrim != (_FX_PRIM *)0x0) {
    FX_MakeParticleTexFX
              (fxPrim,position,(Object *)0x0,0,0,(_SVector *)0x0,(_SVector *)0x0,0xffffff,0x60,8);
                    /* WARNING: Subroutine does not return */
    FX_Sprite_Insert(&gFXT->usedPrimListSprite,fxPrim);
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

void FX_MakeHitFlame(_SVector *startpos,int zpos,int angle,int dist,int size)

{
  _FX_PRIM *p_Var1;
  
  p_Var1 = FX_GetPrim(gFXT);
  if (p_Var1 != (_FX_PRIM *)0x0) {
                    /* WARNING: Subroutine does not return */
    rcos(angle - 0x400);
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

/* WARNING: Removing unreachable block (ram,0x8004ac94) */
/* WARNING: Removing unreachable block (ram,0x8004aca8) */
/* WARNING: Removing unreachable block (ram,0x8004acb0) */
/* WARNING: Removing unreachable block (ram,0x8004acc0) */
/* WARNING: Removing unreachable block (ram,0x8004acd0) */

void FX_SoulReaverBlade(_Instance *instance,ulong **drawot)

{
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

void FX_SoulReaverWinding(_Instance *instance,_PrimPool *primPool,ulong **ot,MATRIX *wcTransform)

{
  uint auStack96 [14];
  
  if ((*(char *)instance->extraData != '\0') && (*(char *)(instance->extraData + 1) != '\0')) {
                    /* WARNING: Subroutine does not return */
    CompMatrix((undefined4 *)wcTransform,(ushort *)((gameTrackerX.playerInstance)->matrix + 0x28),
               auStack96);
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

void FX_StartInstanceBurrow(_Instance *instance,Level *level,_TFace *tface)

{
  _SVector local_20 [2];
  
                    /* WARNING: Subroutine does not return */
  COLLIDE_GetNormal(tface->normal,(short *)level->terrain->normalList,local_20);
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

void FX_UpdateInstanceWaterSplit(_Instance *instance)

{
  undefined glowEffect;
  int depth;
  int in_a2;
  _SVector _Stack16;
  
  glowEffect = SUB41(instance,0);
  if ((instance->waterFace != (_TFace *)0x0) && (instance->waterFaceTerrain != (_Terrain *)0x0)) {
    if (((instance->halvePlane).flags & 8U) == 0) {
                    /* WARNING: Subroutine does not return */
      COLLIDE_GetNormal(instance->waterFace->normal,(short *)instance->waterFaceTerrain->normalList,
                        &_Stack16);
    }
    depth = (int)(instance->splitPoint).z;
    FX_MakeWaterTrail(instance,depth);
    FX_SetGlowFades(glowEffect,depth,in_a2);
    return;
  }
  (instance->halvePlane).flags = (instance->halvePlane).flags & 0xfffd;
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

void FX_DoInstancePowerRing
               (_Instance *instance,long atuTime,long *color,long numColors,int follow_halveplane)

{
                    /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(numColors * 4 + 0x2c,'\r');
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

void FX_UpdatePowerRing(_FXHalvePlane *ring)

{
  if ((int)ring->lifeTime <= ring->diffTime) {
    ring->diffTime = (int)ring->lifeTime;
    ring->lifeTime = 0;
  }
                    /* WARNING: Subroutine does not return */
  (ring->ringPlane).flags = 0;
  rsin(200);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_UpdateInstanceSplitRing(struct _FXHalvePlane *ring /*$s0*/, struct _FXTracker *fxTracker /*$a1*/)
 // line 5621, offset 0x8004b8cc
	/* begin block 1 */
		// Start line: 13923
	/* end block 1 */
	// End Line: 13924

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
 // line 5644, offset 0x8004b95c
	/* begin block 1 */
		// Start line: 13970
	/* end block 1 */
	// End Line: 13971

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
 // line 5755, offset 0x8004bb98
	/* begin block 1 */
		// Start line: 14215
	/* end block 1 */
	// End Line: 14216

	/* begin block 2 */
		// Start line: 14216
	/* end block 2 */
	// End Line: 14217

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

void FX_DrawLightning(_FXLightning *zap,MATRIX *wcTransform,ulong **ot)

{
  MATRIX *pMVar1;
  MATRIX *mat;
  _SVector local_30;
  _SVector local_28;
  undefined local_20 [8];
  
  if (zap->type == '\x02') {
    local_30.x = (zap->start_offset).x;
    local_30.y = (zap->start_offset).y;
    local_30.z = (zap->start_offset).z;
  }
  else {
    mat = zap->instance->matrix;
    if (mat != (MATRIX *)0x0) {
                    /* WARNING: Subroutine does not return */
      ApplyMatrixSV(mat + zap->startSeg,&zap->start_offset,local_20);
    }
    local_30.x = (zap->instance->position).x;
    local_30.y = (zap->instance->position).y;
    local_30.z = (zap->instance->position).z;
  }
  if ((uint)zap->type - 1 < 2) {
    local_28.x = (zap->end_offset).x;
    local_28.y = (zap->end_offset).y;
    local_28.z = (zap->end_offset).z;
  }
  else {
    mat = zap->end_instance->matrix;
    if (mat != (MATRIX *)0x0) {
                    /* WARNING: Subroutine does not return */
      ApplyMatrixSV(mat + zap->endSeg,&zap->end_offset,local_20);
    }
    local_28.x = (zap->instance->position).x;
    local_28.y = (zap->instance->position).y;
    local_28.z = (zap->instance->position).z;
  }
  mat = (MATRIX *)0x0;
  if ((int)zap->matrixSeg != -1) {
    pMVar1 = zap->instance->matrix;
    if (pMVar1 != (MATRIX *)0x0) {
      mat = pMVar1 + (int)zap->matrixSeg;
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

void FX_ContinueBlastRing(_FXBlastringEffect *blast,_FXTracker *fxTracker)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = blast->vel * (gameTrackerX.timeMult >> 4);
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
      iVar5 = (((iVar5 >> 0xc) - iVar4) * 0x1000) / ((iVar2 >> 0xc) - iVar4);
    }
    else {
      iVar5 = (((iVar5 >> 0xc) - iVar4) * 0x1000) / ((iVar3 >> 0xc) - iVar4);
    }
    if (iVar5 < 0x1001) {
                    /* WARNING: Subroutine does not return */
      LoadAverageCol((byte *)&blast->endColor,(byte *)&blast->startColor,iVar5,0x1000 - iVar5,
                     (undefined *)&blast->color);
    }
    blast->color = 0;
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
 // line 6147, offset 0x8004c758
	/* begin block 1 */
		// Start line: 15048
	/* end block 1 */
	// End Line: 15049

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

/* WARNING: Removing unreachable block (ram,0x8004c990) */
/* WARNING: Removing unreachable block (ram,0x8004c9ac) */
/* WARNING: Removing unreachable block (ram,0x8004c9c4) */
/* WARNING: Removing unreachable block (ram,0x8004c9d4) */
/* WARNING: Removing unreachable block (ram,0x8004c9e4) */
/* WARNING: Removing unreachable block (ram,0x8004c9f4) */
/* WARNING: Removing unreachable block (ram,0x8004ca04) */
/* WARNING: Removing unreachable block (ram,0x8004ca0c) */
/* WARNING: Removing unreachable block (ram,0x8004ca14) */
/* WARNING: Removing unreachable block (ram,0x8004ca28) */
/* WARNING: Removing unreachable block (ram,0x8004ca64) */
/* WARNING: Removing unreachable block (ram,0x8004ca58) */
/* WARNING: Removing unreachable block (ram,0x8004ca68) */
/* WARNING: Removing unreachable block (ram,0x8004caf4) */
/* WARNING: Removing unreachable block (ram,0x8004caec) */
/* WARNING: Removing unreachable block (ram,0x8004cb00) */
/* WARNING: Removing unreachable block (ram,0x8004cb70) */
/* WARNING: Removing unreachable block (ram,0x8004cb9c) */
/* WARNING: Removing unreachable block (ram,0x8004cb80) */
/* WARNING: Removing unreachable block (ram,0x8004cba8) */
/* WARNING: Removing unreachable block (ram,0x8004cbb8) */
/* WARNING: Removing unreachable block (ram,0x8004cbe0) */
/* WARNING: Removing unreachable block (ram,0x8004cbf0) */
/* WARNING: Removing unreachable block (ram,0x8004cbf8) */
/* WARNING: Removing unreachable block (ram,0x8004cc08) */
/* WARNING: Removing unreachable block (ram,0x8004cc18) */
/* WARNING: Removing unreachable block (ram,0x8004cc28) */
/* WARNING: Removing unreachable block (ram,0x8004cc38) */
/* WARNING: Removing unreachable block (ram,0x8004cc44) */

_FXParticle *
FX_StartGenericParticle(_Instance *instance,int num,int segOverride,int lifeOverride,int InitFlag)

{
  _FXParticle *p_Var1;
  
  p_Var1 = (_FXParticle *)FX_StartGenericLightning((char)instance,num,(int)(void *)0x0,InitFlag);
  return p_Var1;
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

/* WARNING: Removing unreachable block (ram,0x8004cc7c) */
/* WARNING: Removing unreachable block (ram,0x8004cca4) */
/* WARNING: Removing unreachable block (ram,0x8004ccb4) */
/* WARNING: Removing unreachable block (ram,0x8004ccbc) */
/* WARNING: Removing unreachable block (ram,0x8004cccc) */

void FX_StartGenericRibbon(_Instance *instance,int num,int segOverride,int endOverride,int InitFlag)

{
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

/* WARNING: Removing unreachable block (ram,0x8004cd40) */
/* WARNING: Removing unreachable block (ram,0x8004cd5c) */
/* WARNING: Removing unreachable block (ram,0x8004cd6c) */
/* WARNING: Removing unreachable block (ram,0x8004cd7c) */
/* WARNING: Removing unreachable block (ram,0x8004cd8c) */
/* WARNING: Removing unreachable block (ram,0x8004cde8) */
/* WARNING: Removing unreachable block (ram,0x8004cdf0) */
/* WARNING: Removing unreachable block (ram,0x8004cdf8) */
/* WARNING: Removing unreachable block (ram,0x8004ce00) */
/* WARNING: Removing unreachable block (ram,0x8004ce08) */
/* WARNING: Removing unreachable block (ram,0x8004ce10) */
/* WARNING: Removing unreachable block (ram,0x8004ce40) */
/* WARNING: Removing unreachable block (ram,0x8004ce48) */
/* WARNING: Removing unreachable block (ram,0x8004ce50) */
/* WARNING: Removing unreachable block (ram,0x8004ce58) */
/* WARNING: Removing unreachable block (ram,0x8004ce5c) */
/* WARNING: Removing unreachable block (ram,0x8004cdac) */
/* WARNING: Removing unreachable block (ram,0x8004cdb4) */
/* WARNING: Removing unreachable block (ram,0x8004cdb8) */
/* WARNING: Removing unreachable block (ram,0x8004ce88) */
/* WARNING: Removing unreachable block (ram,0x8004ce90) */
/* WARNING: Removing unreachable block (ram,0x8004cea0) */

void FX_StartGenericGlow(_Instance *instance,int num,int segOverride,int seg2Override,int InitFlag)

{
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
 // line 6478, offset 0x8004cfd0
	/* begin block 1 */
		// Start line: 15756
	/* end block 1 */
	// End Line: 15757

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

/* WARNING: Removing unreachable block (ram,0x8004d0b8) */
/* WARNING: Removing unreachable block (ram,0x8004d0e8) */
/* WARNING: Removing unreachable block (ram,0x8004d0f8) */
/* WARNING: Removing unreachable block (ram,0x8004d0e0) */
/* WARNING: Removing unreachable block (ram,0x8004d108) */
/* WARNING: Removing unreachable block (ram,0x8004d174) */
/* WARNING: Removing unreachable block (ram,0x8004d17c) */
/* WARNING: Removing unreachable block (ram,0x8004d180) */
/* WARNING: Removing unreachable block (ram,0x8004d194) */
/* WARNING: Removing unreachable block (ram,0x8004d188) */
/* WARNING: Removing unreachable block (ram,0x8004d198) */
/* WARNING: Removing unreachable block (ram,0x8004d1bc) */

_FXLightning *
FX_StartGenericLightning(_Instance *instance,int num,int segOverride,int endSegOverride)

{
  return (_FXLightning *)0x0;
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

/* WARNING: Removing unreachable block (ram,0x8004d210) */
/* WARNING: Removing unreachable block (ram,0x8004d238) */
/* WARNING: Removing unreachable block (ram,0x8004d248) */
/* WARNING: Removing unreachable block (ram,0x8004d250) */
/* WARNING: Removing unreachable block (ram,0x8004d254) */
/* WARNING: Removing unreachable block (ram,0x8004d268) */
/* WARNING: Removing unreachable block (ram,0x8004d25c) */
/* WARNING: Removing unreachable block (ram,0x8004d26c) */
/* WARNING: Removing unreachable block (ram,0x8004d284) */
/* WARNING: Removing unreachable block (ram,0x8004d388) */

_FXBlastringEffect *
FX_StartGenericBlastring(_Instance *instance,int num,int segOverride,int matrixSegOverride)

{
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

/* WARNING: Removing unreachable block (ram,0x8004d3d8) */

_FXFlash * FX_StartGenericFlash(_Instance *instance,int num)

{
  return (_FXFlash *)0x0;
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

long FX_GetHealthColor(int currentHealth)

{
  uint uVar1;
  
  if (currentHealth < 1) {
    uVar1 = 0x7f;
  }
  else {
    if ((uint)currentHealth < 6) {
      uVar1 = (&DAT_800c90dc)[currentHealth + -1];
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
 // line 6696, offset 0x8004d4e0
	/* begin block 1 */
		// Start line: 16244
	/* end block 1 */
	// End Line: 16245

	/* begin block 2 */
		// Start line: 16245
	/* end block 2 */
	// End Line: 16246

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

/* WARNING: Removing unreachable block (ram,0x8004d570) */

void FX_StartLightbeam(_Instance *instance,int startSeg,int endSeg,int color_num)

{
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

void FX_StartInstanceEffect(_Instance *instance,ObjectEffect *effect,int InitFlag)

{
  short sVar1;
  uint *puVar2;
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
      local_20[0] = (undefined *)(&FX_ColorArray)[effect->modifierList[1]];
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
      local_20[0] = (undefined *)(&FX_ColorArray)[effect->modifierList[2]];
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
      puVar2 = (uint *)instance->object->data;
      sVar1 = 0;
      if (puVar2 != (uint *)0x0) {
        splintDef = (FXSplinter *)puVar2[1];
        sVar1 = (short)((*puVar2 & 2) << 3);
      }
      _FX_BuildSplinters(instance,(SVECTOR *)0x0,(SVECTOR *)0x0,(SVECTOR *)0x0,splintDef,gFXT,
                         (TDRFuncPtr__FX_BuildSplinters6fxSetup)0x0,
                         (TDRFuncPtr__FX_BuildSplinters7fxProcess)0x0,(int)sVar1);
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

void FX_GetSpiralPoint(int radius,int deg,int *x,int *y)

{
                    /* WARNING: Subroutine does not return */
  rcos(deg);
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
  DVECTOR_800d27a0.vx = (short)local_48;
  DVECTOR_800d27a0.vy = (short)local_44;
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

void FX_Spiral(_PrimPool *primPool,ulong **ot)

{
  short sVar1;
  uint angle;
  long lVar2;
  DVECTOR *pDVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  DVECTOR DVar7;
  DVECTOR DVar8;
  DVECTOR DVar9;
  DVECTOR DVar10;
  int iVar11;
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
  local_2c = (DVECTOR)0x3afcffd3;
  local_30 = (DVECTOR)0x3adce0ba;
  DVar9 = (DVECTOR)0x3a483017;
  local_4c = (DVECTOR)0x3a002a15;
  local_44 = (DVECTOR)0x3abbc09d;
  if (Spiral_Number == 0) {
    if (Spiral_Current == Spiral_Max) {
      DAT_800cfddc = DAT_800cfddc + 1;
      if (0x50 < DAT_800cfddc) {
        DAT_800cfddc = 0;
      }
    }
    else {
      local_2c = (DVECTOR)0x3a00ff00;
      local_30 = (DVECTOR)0x3a00e000;
      local_44 = (DVECTOR)0x3a00bf00;
      DVar9 = (DVECTOR)0x3a004500;
    }
    local_4c = (DVECTOR)0x3a00150b;
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
  local_34 = lVar2 >> 6;
  iVar11 = Spiral_Current / local_34;
  puVar5 = primPool->nextPrim;
  local_34 = ((Spiral_Current - iVar11 * local_34) * 0x1000) / local_34;
  if (puVar5 + 0x451 < primPool->lastPrim) {
    iVar4 = 0;
    local_38 = &local_50;
    local_40 = (uint)local_2c & 0xff000000;
    local_48 = (int)DAT_800cfddc;
    pDVar3 = (DVECTOR *)(puVar5 + 0x10);
    DVar7 = DVECTOR_800d27a0;
    DVar8 = DVECTOR_800d27a0;
    DVar10 = DVECTOR_800d27a0;
    local_50 = local_4c;
    do {
      puVar6 = puVar5;
      pDVar3[-0xb] = local_50;
      pDVar3[-7] = local_50;
      local_50 = local_4c;
      if (iVar4 <= iVar11) {
        angle = (int)(iVar4 + local_48 & 0xfU) >> 2;
        local_50 = local_30;
        if (angle != 1) {
          if (angle < 2) {
LAB_8004e078:
            local_50 = local_2c;
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
      if (iVar4 == iVar11) {
                    /* WARNING: Subroutine does not return */
        LoadAverageCol((byte *)local_38,(byte *)&local_4c,local_34,0x1000 - local_34,
                       (undefined *)local_38);
      }
      pDVar3[-0xf] = DVar9;
      pDVar3[-0xd] = DVar9;
      pDVar3[-3] = DVar9;
      pDVar3[-1] = DVar9;
      pDVar3[-6] = DVar7;
      pDVar3[-10] = DVar7;
      pDVar3[-0xe] = DVar10;
      pDVar3[-2] = DVar8;
      pDVar3[-9] = local_50;
      pDVar3[-5] = local_50;
      DVar7 = (&Spiral_Array)[iVar4];
      DVar10 = (&Spiral_OffsetP)[iVar4];
      DVar8 = (&Spiral_OffsetM)[iVar4];
      iVar4 = iVar4 + 1;
      pDVar3[-4] = DVar7;
      pDVar3[-8] = DVar7;
      pDVar3[-0xc] = DVar10;
      *pDVar3 = DVar8;
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
      local_60.y = Spiral_Glow_Y;
      angle = (uint)DAT_800cfdde - 0x20 & 0xfff;
      local_60.x = Spiral_Glow_X;
      DAT_800cfdde = (ushort)angle;
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

void FX_DrawModel(Object *object,int model_num,_SVector *rotation,_SVector *position,
                 _SVector *offset,int transflag)

{
  MATRIX MStack88;
  
  PushMatrix();
  MATH3D_SetUnityMatrix(&MStack88);
  RotMatrixX((int)rotation->x,(int)&MStack88);
  RotMatrixY((int)rotation->y,(uint *)&MStack88);
                    /* WARNING: Subroutine does not return */
  RotMatrixZ((int)rotation->z,(uint *)&MStack88);
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

void fx_calc_points(_SVector *points,int degrees,int radius,int radius2,int radius3)

{
                    /* WARNING: Subroutine does not return */
  rcos(degrees);
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

long fx_get_startz(_SVector *position)

{
  undefined4 in_zero;
  undefined4 in_at;
  undefined auStack40 [20];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  setCopReg(2,in_zero,*(undefined4 *)position);
  setCopReg(2,in_at,*(undefined4 *)&position->z);
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

void FX_DrawRing(MATRIX *wcTransform,_SVector *position,MATRIX *matrix,int radius,int radius2,
                int radius3,int z1,int z2,int z3,long color,int sortInWorld)

{
  if ((gameTrackerX.primPool)->nextPrim + 0x240 < (gameTrackerX.primPool)->lastPrim) {
    PushMatrix();
                    /* WARNING: Subroutine does not return */
    SetRotMatrix((undefined4 *)wcTransform);
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

void FX_DrawRing2(MATRIX *wcTransform,_SVector *position,MATRIX *matrix,int radius,int radius2,
                 int radius3,int z1,int z2,int z3,long offset,int sortInWorld)

{
  if ((gameTrackerX.primPool)->nextPrim + 0x140 < (gameTrackerX.primPool)->lastPrim) {
    PushMatrix();
                    /* WARNING: Subroutine does not return */
    SetRotMatrix((undefined4 *)wcTransform);
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

void FX_DrawFField(MATRIX *wcTransform,_FXForceFieldEffect *field)

{
                    /* WARNING: Subroutine does not return */
  rcos((int)field->deg);
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

void FX_Lightning(MATRIX *wcTransform,ulong **ot,MATRIX *mat,short deg,_SVector *start,_SVector *end
                 ,int width,int small_width,int segs,int sine_size,int variation,long color,
                 long glow_color)

{
  if (mat != (MATRIX *)0x0) {
                    /* WARNING: Subroutine does not return */
    SetRotMatrix((undefined4 *)mat);
  }
                    /* WARNING: Subroutine does not return */
  SetRotMatrix((undefined4 *)wcTransform);
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

void FX_LightHouse(MATRIX *wcTransform,ulong **ot,_Instance *instance,int startSeg,int endSeg,
                  int segs,long beam_color)

{
  if ((instance->flags & 0x800U) == 0) {
    if (instance->matrix != (MATRIX *)0x0) {
                    /* WARNING: Subroutine does not return */
      SetRotMatrix((undefined4 *)wcTransform);
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

void FX_StartPassthruFX(_Instance *instance,_SVector *normal,_SVector *point)

{
  long alStack24 [2];
  
  (instance->halvePlane).a = normal->x;
  (instance->halvePlane).b = normal->y;
  (instance->halvePlane).c = normal->z;
  alStack24[0] = 0x20ff40;
  (instance->halvePlane).d =
       -((int)normal->x * (int)point->x + (int)normal->y * (int)point->y +
         (int)normal->z * (int)point->z >> 0xc);
                    /* WARNING: Subroutine does not return */
  FX_DoInstancePowerRing(instance,(long)&DAT_000020d0,alStack24,0,2);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FX_EndPassthruFX(struct _Instance *instance /*$a0*/)
 // line 8172, offset 0x8004fd2c
	/* begin block 1 */
		// Start line: 19985
	/* end block 1 */
	// End Line: 19986

void FX_EndPassthruFX(_Instance *instance)

{
  FX_EndInstanceEffects(instance);
  return;
}





