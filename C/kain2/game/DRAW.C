#include "THISDUST.H"
#include "DRAW.H"


// decompiled code
// original method signature: 
// void /*$ra*/ fDRAW_SPLIT_INTPL_XYZ(struct _SVector *newVertex /*$a0*/, struct _SVector *pvb /*$a1*/, struct _SVector *pvc /*$a2*/)
 // line 61, offset 0x8002a5b0
	/* begin block 1 */
		// Start line: 122
	/* end block 1 */
	// End Line: 123

	/* begin block 2 */
		// Start line: 123
	/* end block 2 */
	// End Line: 124

void fDRAW_SPLIT_INTPL_XYZ(_SVector *newVertex,_SVector *pvb,_SVector *pvc)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  
  newVertex->x = pvb->x + (short)(((int)pvb->z * ((int)pvc->x - (int)pvb->x)) /
                                 ((int)pvb->z - (int)pvc->z));
  sVar1 = pvc->y;
  sVar2 = pvb->y;
  sVar3 = pvb->z;
  sVar4 = pvc->z;
  sVar5 = pvb->y;
  newVertex->z = 0;
  newVertex->y = sVar5 + (short)(((int)sVar3 * ((int)sVar1 - (int)sVar2)) /
                                ((int)sVar3 - (int)sVar4));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_InitShadow()
 // line 454, offset 0x8002a62c
	/* begin block 1 */
		// Start line: 455
		// Start offset: 0x8002A62C
		// Variables:
	// 		int n; // $s3
	// 		int inc; // $s4
	// 		int deg; // $s2
	/* end block 1 */
	// End offset: 0x8002A6BC
	// End Line: 468

	/* begin block 2 */
		// Start line: 519
	/* end block 2 */
	// End Line: 520

	/* begin block 3 */
		// Start line: 909
	/* end block 3 */
	// End Line: 910

/* WARNING: Removing unreachable block (ram,0x8002a664) */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void DRAW_InitShadow(void)

{
                    /* WARNING: Subroutine does not return */
  rcos(0);
}



// decompiled code
// original method signature: 
// unsigned long * /*$ra*/ DRAW_DrawShadow(struct _PrimPool *primPool /*$t3*/, struct _Model *model /*$a1*/, unsigned long **ot /*$a2*/, long fadeValue /*$a3*/)
 // line 478, offset 0x8002a6f4
	/* begin block 1 */
		// Start line: 479
		// Start offset: 0x8002A6F4
		// Variables:
	// 		struct POLY_G3_SEMITRANS *sg3; // $a1
	// 		struct SVECTOR zero_vertex; // stack offset -24
	// 		long clip; // stack offset -8
	// 		long n; // $t0
	// 		long p; // stack offset -16
	// 		long otz; // stack offset -4
	// 		unsigned long color; // stack offset -12
	/* end block 1 */
	// End offset: 0x8002A8AC
	// End Line: 538

	/* begin block 2 */
		// Start line: 983
	/* end block 2 */
	// End Line: 984

uint * DRAW_DrawShadow(uint *param_1,undefined4 param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 in_zero;
  undefined4 in_at;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  undefined4 *puVar8;
  uint local_14;
  int local_10;
  
  puVar5 = (uint *)param_1[1];
  local_14 = local_14 & 0xffff0000;
  setCopReg(2,in_zero,0);
  setCopReg(2,in_at,local_14);
  copFunction(2,0x180001);
  iVar7 = getCopReg(2,8);
  local_10 = iVar7;
  if ((param_4 <= iVar7) || (local_10 = param_4, param_4 < 0x1001)) {
    iVar7 = local_10;
  }
  local_10 = iVar7;
  setCopReg(2,param_3,0x606060);
  setCopReg(2,0x4000,local_10);
  copFunction(2,0x780010);
  uVar1 = getCopReg(2,0x16);
  iVar7 = 0;
  puVar8 = (undefined4 *)&gp0xffffa8d8;
  puVar6 = puVar5 + 1;
  uVar2 = uVar1 | 0x32000000;
  puVar4 = param_1;
  do {
    iVar3 = iVar7 * 8;
    setCopReg(2,uVar2,*puVar8);
    setCopReg(2,iVar3,puVar8[1]);
    setCopReg(2,puVar4,*(undefined4 *)(&gp0xffffa8e0 + iVar3));
    setCopReg(2,puVar5,*(undefined4 *)(&gp0xffffa8e4 + iVar3));
    copFunction(2,0x280030);
    if ((uint *)(param_1[2] - 0x30) < puVar5) {
      return puVar5;
    }
    copFunction(2,0x1400006);
    iVar3 = getCopReg(2,0x18);
    if (iVar3 < 0) {
      copFunction(2,0x158002d);
      iVar3 = getCopReg(2,7);
      puVar4 = puVar5 + 3;
      if (iVar3 - 0x40U < 0xbc0) {
        uVar2 = getCopReg(2,0xc);
        *puVar4 = uVar2;
        uVar2 = getCopReg(2,0xd);
        puVar5[5] = uVar2;
        uVar2 = getCopReg(2,0xe);
        puVar5[7] = uVar2;
        puVar6[3] = 0;
        puVar6[5] = 0;
        puVar6[1] = uVar1 | 0x32000000;
        *puVar6 = 0xe1000640;
        puVar6 = puVar6 + 8;
        puVar4 = (uint *)(iVar3 * 4 + param_3);
        *puVar5 = *puVar4 & 0xffffff | 0x7000000;
        *puVar4 = (uint)puVar5 & 0xffffff;
        puVar5 = puVar5 + 8;
        *param_1 = *param_1 + 1;
      }
    }
    iVar7 = iVar7 + 1;
    uVar2 = (uint)(iVar7 < 10);
    puVar8 = puVar8 + 2;
  } while (iVar7 < 10);
  return puVar5;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_FlatQuad(struct CVECTOR *color /*$a0*/, short x0 /*$a1*/, short y0 /*$a2*/, short x1 /*$a3*/, int y1 /*stack 16*/, int x2 /*stack 20*/, int y2 /*stack 24*/, int x3 /*stack 28*/, int y3 /*stack 32*/, struct _PrimPool *primPool /*stack 36*/, unsigned long **ot /*stack 40*/)
 // line 3208, offset 0x8002a8b4
	/* begin block 1 */
		// Start line: 3209
		// Start offset: 0x8002A8B4
		// Variables:
	// 		unsigned long *prim; // $t0
	/* end block 1 */
	// End offset: 0x8002A954
	// End Line: 3228

	/* begin block 2 */
		// Start line: 6416
	/* end block 2 */
	// End Line: 6417

void DRAW_FlatQuad(CVECTOR *color,short x0,short y0,short x1,int y1,int x2,int y2,int x3,int y3,
                  _PrimPool *primPool,ulong **ot)

{
  CVECTOR CVar1;
  uint *puVar2;
  
  puVar2 = primPool->nextPrim;
  if (puVar2 < primPool->lastPrim + -0xc) {
    CVar1 = *color;
    *(short *)(puVar2 + 2) = x0;
    *(short *)((int)puVar2 + 10) = y0;
    *(short *)(puVar2 + 3) = x1;
    *(undefined2 *)((int)puVar2 + 0xe) = (short)y1;
    *(short *)(puVar2 + 4) = (short)x2;
    *(undefined2 *)((int)puVar2 + 0x12) = (short)y2;
    *(short *)(puVar2 + 5) = (short)x3;
    *(undefined2 *)((int)puVar2 + 0x16) = (short)y3;
    *(CVECTOR *)(puVar2 + 1) = CVar1;
    *(undefined *)((int)puVar2 + 7) = 0x28;
    *puVar2 = (uint)*ot & 0xffffff | 0x5000000;
    *ot = (ulong *)((uint)puVar2 & 0xffffff);
    primPool->nextPrim = primPool->nextPrim + 6;
    primPool->numPrims = primPool->numPrims + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_TranslucentQuad(short x0 /*$a0*/, short y0 /*$a1*/, short x1 /*$a2*/, short y1 /*$a3*/, int x2 /*stack 16*/, int y2 /*stack 20*/, int x3 /*stack 24*/, int y3 /*stack 28*/, int r /*stack 32*/, int g /*stack 36*/, int b /*stack 40*/, int abr /*stack 44*/, struct _PrimPool *primPool /*stack 48*/, unsigned long **ot /*stack 52*/)
 // line 3245, offset 0x8002a95c
	/* begin block 1 */
		// Start line: 3246
		// Start offset: 0x8002A95C
		// Variables:
	// 		unsigned long *prim; // $t0
	/* end block 1 */
	// End offset: 0x8002AA30
	// End Line: 3272

	/* begin block 2 */
		// Start line: 3914
	/* end block 2 */
	// End Line: 3915

void DRAW_TranslucentQuad
               (short x0,short y0,short x1,short y1,int x2,int y2,int x3,int y3,int r,int g,int b,
               int abr,_PrimPool *primPool,ulong **ot)

{
  uint *puVar1;
  
  puVar1 = primPool->nextPrim;
  if (puVar1 < primPool->lastPrim + -0xc) {
    puVar1[1] = (abr << 0x10) >> 0xb | 0xe1000208;
    *(undefined *)((int)puVar1 + 0xb) = 0x2a;
    *(char *)(puVar1 + 2) = (char)r;
    *(undefined *)((int)puVar1 + 9) = (char)g;
    *(undefined *)((int)puVar1 + 10) = (char)b;
    *(short *)(puVar1 + 3) = x0;
    *(short *)((int)puVar1 + 0xe) = y0;
    *(short *)(puVar1 + 4) = x1;
    *(short *)((int)puVar1 + 0x12) = y1;
    *(short *)(puVar1 + 5) = (short)x2;
    *(undefined2 *)((int)puVar1 + 0x16) = (short)y2;
    *(short *)(puVar1 + 6) = (short)x3;
    *(undefined2 *)((int)puVar1 + 0x1a) = (short)y3;
    *puVar1 = (uint)*ot & 0xffffff | 0x6000000;
    *ot = (ulong *)((uint)puVar1 & 0xffffff);
    primPool->nextPrim = primPool->nextPrim + 7;
    primPool->numPrims = primPool->numPrims + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_DrawButton(struct _ButtonTexture *button /*$s5*/, short x /*$a1*/, short y /*$a2*/, unsigned long **ot /*stack 12*/)
 // line 3515, offset 0x8002aa40
	/* begin block 1 */
		// Start line: 3516
		// Start offset: 0x8002AA40
		// Variables:
	// 		struct _PrimPool *primPool; // $fp
	// 		unsigned long *prim; // $s4
	// 		short w; // $s0
	// 		short h; // $s3
	// 		short offsetx; // $s2
	// 		short offsety; // $s1
	/* end block 1 */
	// End offset: 0x8002AB78
	// End Line: 3567

	/* begin block 2 */
		// Start line: 7030
	/* end block 2 */
	// End Line: 7031

void DRAW_DrawButton(_ButtonTexture *button,short x,short y,ulong **ot)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  char cVar4;
  long lVar5;
  short sVar6;
  uint uVar7;
  short sVar8;
  char cVar9;
  int iVar10;
  char cVar11;
  uint *puVar12;
  
  lVar5 = theCamera.core.vvPlaneConsts[2];
  puVar12 = *(uint **)(theCamera.core.vvPlaneConsts[2] + 4);
  if (puVar12 <= (uint *)(*(int *)(theCamera.core.vvPlaneConsts[2] + 8) - 0x30U)) {
    uVar7 = button->xshift;
    sVar1 = button->textureH;
    iVar10 = (int)button->textureW << (uVar7 & 0x1f);
    uVar2 = button->vramBlock->x;
    cVar11 = *(char *)&button->vramBlock->y;
    SetPolyFT4((int)puVar12);
    sVar8 = x + (short)iVar10 + -1;
    cVar4 = (char)(((uint)uVar2 & 0x3f) << (uVar7 & 0x1f));
    *(byte *)((int)puVar12 + 7) = *(byte *)((int)puVar12 + 7) | 1;
    cVar9 = cVar4 + (char)iVar10 + -1;
    *(short *)((int)puVar12 + 0x16) = button->tpage;
    sVar3 = button->clut;
    sVar6 = y + sVar1 + -1;
    *(char *)((int)puVar12 + 0xd) = cVar11;
    *(char *)((int)puVar12 + 0x15) = cVar11;
    cVar11 = cVar11 + (char)sVar1 + -1;
    *(short *)(puVar12 + 2) = x;
    *(short *)((int)puVar12 + 10) = y;
    *(char *)(puVar12 + 3) = cVar4;
    *(short *)(puVar12 + 4) = sVar8;
    *(short *)((int)puVar12 + 0x12) = y;
    *(char *)(puVar12 + 5) = cVar9;
    *(short *)(puVar12 + 6) = x;
    *(short *)((int)puVar12 + 0x1a) = sVar6;
    *(char *)(puVar12 + 7) = cVar4;
    *(char *)((int)puVar12 + 0x1d) = cVar11;
    *(short *)(puVar12 + 8) = sVar8;
    *(short *)((int)puVar12 + 0x22) = sVar6;
    *(char *)(puVar12 + 9) = cVar9;
    *(char *)((int)puVar12 + 0x25) = cVar11;
    *(short *)((int)puVar12 + 0xe) = sVar3;
    *puVar12 = (uint)*ot & 0xffffff | 0x9000000;
    *ot = (ulong *)((uint)puVar12 & 0xffffff);
    *(uint **)(lVar5 + 4) = puVar12 + 10;
    *(int *)lVar5 = *(int *)lVar5 + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_LoadButton(long *addr /*$s0*/, struct _ButtonTexture *button /*$s1*/)
 // line 3573, offset 0x8002aba8
	/* begin block 1 */
		// Start line: 3574
		// Start offset: 0x8002ABA8
		// Variables:
	// 		struct RECT vramRect; // stack offset -32
	// 		long *paletteAddr; // $s3
	// 		short paletteW; // $s2
	// 		short paletteH; // $s4
	/* end block 1 */
	// End offset: 0x8002AD20
	// End Line: 3620

	/* begin block 2 */
		// Start line: 4472
	/* end block 2 */
	// End Line: 4473

void DRAW_LoadButton(int param_1,ushort *param_2)

{
  bool bVar1;
  _BlockVramEntry *p_Var2;
  int iVar3;
  ushort uVar4;
  int iVar5;
  ushort uStack32;
  ushort uStack30;
  ushort uStack28;
  ushort uStack26;
  
  iVar3 = param_1 + 8;
  iVar5 = 0;
  uVar4 = 0;
  *(undefined4 *)(param_2 + 6) = 0;
  bVar1 = *(int *)(param_1 + 4) == 8;
  if (bVar1) {
    *(undefined4 *)(param_2 + 6) = 2;
    uVar4 = 0x10;
    iVar5 = param_1 + 0x14;
    iVar3 = param_1 + 0x34;
  }
  param_2[2] = *(ushort *)(iVar3 + 8);
  param_2[3] = *(ushort *)(iVar3 + 10);
  uStack28 = uVar4;
  if ((short)uVar4 < (short)param_2[2]) {
    uStack28 = param_2[2];
  }
  uStack26 = (ushort)((uint)param_2[3] + (uint)bVar1);
  p_Var2 = VRAM_CheckVramSlot((short *)&uStack32,(short *)&uStack30,uStack28,
                              (short)(((uint)param_2[3] + (uint)bVar1) * 0x10000 >> 0x10),4,0);
  *(_BlockVramEntry **)(param_2 + 4) = p_Var2;
  *param_2 = (ushort)((2 - (uint)param_2[6] & 3) << 7) | (short)(uStack30 & 0x100) >> 4 |
             (ushort)(((uint)uStack32 & 0x3ff) >> 6) | (ushort)(((uint)uStack30 & 0x200) << 2);
  *(ushort **)(*(int *)(param_2 + 4) + 0x18) = param_2;
  uStack28 = param_2[2];
  uStack26 = param_2[3];
  LoadImage((short *)&uStack32,iVar3 + 0xc);
  if (iVar5 != 0) {
    uStack26 = (ushort)bVar1;
    uStack30 = uStack30 + param_2[3];
    uStack28 = uVar4;
    LoadImage((short *)&uStack32,iVar5);
    param_2[1] = uStack30 << 6 | uStack32 >> 4 & 0x3f;
  }
                    /* WARNING: Subroutine does not return */
  DrawSync(0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_FreeButton(struct _ButtonTexture *button /*$a0*/)
 // line 3636, offset 0x8002ad48
	/* begin block 1 */
		// Start line: 7272
	/* end block 1 */
	// End Line: 7273

void DRAW_FreeButton(_ButtonTexture *button)

{
  VRAM_ClearVramBlock(button->vramBlock);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_RingLine(struct _PrimPool *primPool /*$t0*/, unsigned long **ot /*$t1*/, long color /*$a2*/)
 // line 3649, offset 0x8002ad6c
	/* begin block 1 */
		// Start line: 3650
		// Start offset: 0x8002AD6C
		// Variables:
	// 		unsigned long *prim; // $a3
	// 		long flag; // stack offset -24
	// 		long clip; // stack offset -20
	// 		long z0; // stack offset -16
	// 		long z1; // stack offset -12
	// 		long z2; // stack offset -8
	// 		long otz; // $a0
	// 		long p; // stack offset -4
	/* end block 1 */
	// End offset: 0x8002AE94
	// End Line: 3712

	/* begin block 2 */
		// Start line: 4652
	/* end block 2 */
	// End Line: 4653

void DRAW_RingLine(_PrimPool *primPool,ulong **ot,long color)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ulong *puVar5;
  uint *puVar6;
  uint uVar7;
  
  puVar6 = primPool->nextPrim;
  if (puVar6 <= primPool->lastPrim + -0xc) {
    uVar7 = getCopControlWord(2,0xf800);
    if ((uVar7 & 0x60000) == 0) {
      copFunction(2,0x1400006);
      getCopReg(2,0x18);
      iVar1 = getCopReg(2,0x11);
      iVar2 = getCopReg(2,0x12);
      iVar3 = getCopReg(2,0x13);
      if (iVar1 < iVar2) {
        iVar2 = iVar1;
      }
      if (iVar2 < iVar3) {
        iVar3 = iVar2;
      }
      uVar7 = iVar3 >> 2;
      if (uVar7 < 0xc00) {
        if (2 < (int)uVar7) {
          uVar7 = uVar7 - 2;
        }
        getCopReg(2,8);
        puVar6[1] = color | 0x40000000;
        uVar4 = getCopReg(2,0xc);
        puVar6[2] = uVar4;
        uVar4 = getCopReg(2,0xd);
        puVar6[3] = uVar4;
        puVar5 = (ulong *)((uint)puVar6 & 0xffffff);
        *puVar6 = (uint)ot[uVar7] & 0xffffff | 0x3000000;
        puVar6 = puVar6 + 4;
        ot[uVar7] = puVar5;
      }
    }
    primPool->nextPrim = puVar6;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_RingPoint(struct _PrimPool *primPool /*$a0*/, unsigned long **ot /*$a1*/, long color /*$s2*/, struct _SVector *vel /*$s1*/, struct _SVector *acc /*stack 16*/)
 // line 3714, offset 0x8002ae9c
	/* begin block 1 */
		// Start line: 3715
		// Start offset: 0x8002AE9C
		// Variables:
	// 		struct _SVector outpoint; // stack offset -24
	/* end block 1 */
	// End offset: 0x8002AF94
	// End Line: 3726

	/* begin block 2 */
		// Start line: 4789
	/* end block 2 */
	// End Line: 4790

void DRAW_RingPoint(_PrimPool *primPool,ulong **ot,long color,_SVector *vel,_SVector *acc)

{
                    /* WARNING: Subroutine does not return */
  rand();
}



// decompiled code
// original method signature: 
// unsigned long * /*$ra*/ DRAW_DrawRingPoints(struct _Model *model /*$a0*/, struct _VertexPool *vertexPool /*$a1*/, struct MATRIX *pcTransform /*$s0*/, struct _PrimPool *primPool /*$s5*/, unsigned long **ot /*stack 16*/, long color /*stack 20*/, int ring_type /*stack 24*/)
 // line 3736, offset 0x8002afac
	/* begin block 1 */
		// Start line: 3737
		// Start offset: 0x8002AFAC
		// Variables:
	// 		struct _MFace *mface; // $s1
	// 		struct _MFace *endMFace; // $s4
	// 		struct _PVertex *pvertexList; // $s3
	// 		struct _SVector (*pvertex[3]); // stack offset -96
	// 		struct _SVector newVertex[3]; // stack offset -80
	// 		long outcode; // $a0
	// 		int first; // $v1
	// 		int second; // $a0
	// 		struct _SVector vel; // stack offset -56
	// 		struct _SVector acc; // stack offset -48
	/* end block 1 */
	// End offset: 0x8002B294
	// End Line: 3837

	/* begin block 2 */
		// Start line: 4841
	/* end block 2 */
	// End Line: 4842

ulong * DRAW_DrawRingPoints(_Model *model,_VertexPool *vertexPool,MATRIX *pcTransform,
                           _PrimPool *primPool,ulong **ot,long color,int ring_type)

{
  SetRotMatrix((undefined4 *)pcTransform);
                    /* WARNING: Subroutine does not return */
  SetTransMatrix((int)pcTransform);
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_GlowQuad(struct _PrimPool *primPool /*$t7*/, unsigned long **ot /*$t9*/, long otz /*$a2*/, long color /*stack 12*/, struct _Vector *v0 /*stack 16*/, struct _Vector *v1 /*stack 20*/, struct _Vector *v2 /*stack 24*/, struct _Vector *v3 /*stack 28*/)
 // line 3879, offset 0x8002b2c8
	/* begin block 1 */
		// Start line: 3880
		// Start offset: 0x8002B2C8
		// Variables:
	// 		unsigned long *prim; // $t1
	// 		struct _POLY_NG4 *sg4; // $t0
	/* end block 1 */
	// End offset: 0x8002B524
	// End Line: 3922

	/* begin block 2 */
		// Start line: 7758
	/* end block 2 */
	// End Line: 7759

/* WARNING: Could not reconcile some variable overlaps */

void DRAW_GlowQuad(_PrimPool *primPool,ulong **ot,long otz,long color,_Vector *v0,_Vector *v1,
                  _Vector *v2,_Vector *v3)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_resc;
  
  puVar1 = primPool->nextPrim;
  if (puVar1 <= primPool->lastPrim + -0xc) {
    primPool->numPrims = primPool->numPrims + 1;
    if ((color & 0x1000000U) == 0) {
      puVar1[1] = 0xe1000620;
      local_resc = color;
    }
    else {
      local_resc = color & 0xffffff;
      puVar1[1] = 0xe1000640;
    }
    setCopReg(2,0x4000,0x1000 - (int)*(short *)&v0->z);
    setCopReg(2,0x4800,local_resc & 0xff);
    setCopReg(2,0x5000,(uint)local_resc._1_1_);
    setCopReg(2,0x5800,(uint)local_resc._2_1_);
    copFunction(2,0x198003d);
    *(undefined2 *)(puVar1 + 3) = *(undefined2 *)&v0->x;
    *(undefined2 *)((int)puVar1 + 0xe) = *(undefined2 *)&v0->y;
    uVar2 = getCopReg(2,0x4800);
    uVar3 = getCopReg(2,0x5000);
    uVar4 = getCopReg(2,0x5800);
    *(char *)(puVar1 + 2) = (char)uVar2;
    *(undefined *)((int)puVar1 + 9) = (char)uVar3;
    *(undefined *)((int)puVar1 + 10) = (char)uVar4;
    setCopReg(2,0x4000,0x1000 - (int)*(short *)&v1->z);
    setCopReg(2,0x4800,local_resc & 0xff);
    setCopReg(2,0x5000,(uint)local_resc._1_1_);
    setCopReg(2,0x5800,(uint)local_resc._2_1_);
    copFunction(2,0x198003d);
    *(undefined2 *)(puVar1 + 5) = *(undefined2 *)&v1->x;
    *(undefined2 *)((int)puVar1 + 0x16) = *(undefined2 *)&v1->y;
    uVar2 = getCopReg(2,0x4800);
    uVar3 = getCopReg(2,0x5000);
    uVar4 = getCopReg(2,0x5800);
    *(char *)(puVar1 + 4) = (char)uVar2;
    *(undefined *)((int)puVar1 + 0x11) = (char)uVar3;
    *(undefined *)((int)puVar1 + 0x12) = (char)uVar4;
    setCopReg(2,0x4000,0x1000 - (int)*(short *)&v2->z);
    setCopReg(2,0x4800,local_resc & 0xff);
    setCopReg(2,0x5000,(uint)local_resc._1_1_);
    setCopReg(2,0x5800,(uint)local_resc._2_1_);
    copFunction(2,0x198003d);
    *(undefined2 *)(puVar1 + 7) = *(undefined2 *)&v2->x;
    *(undefined2 *)((int)puVar1 + 0x1e) = *(undefined2 *)&v2->y;
    uVar2 = getCopReg(2,0x4800);
    uVar3 = getCopReg(2,0x5000);
    uVar4 = getCopReg(2,0x5800);
    *(char *)(puVar1 + 6) = (char)uVar2;
    *(undefined *)((int)puVar1 + 0x19) = (char)uVar3;
    *(undefined *)((int)puVar1 + 0x1a) = (char)uVar4;
    setCopReg(2,0x4000,0x1000 - (int)*(short *)&v3->z);
    setCopReg(2,0x4800,local_resc & 0xff);
    setCopReg(2,0x5000,(uint)local_resc._1_1_);
    setCopReg(2,0x5800,(uint)local_resc._2_1_);
    copFunction(2,0x198003d);
    *(undefined2 *)(puVar1 + 9) = *(undefined2 *)&v3->x;
    *(undefined2 *)((int)puVar1 + 0x26) = *(undefined2 *)&v3->y;
    uVar2 = getCopReg(2,0x4800);
    uVar3 = getCopReg(2,0x5000);
    uVar4 = getCopReg(2,0x5800);
    *(char *)(puVar1 + 8) = (char)uVar2;
    *(undefined *)((int)puVar1 + 0x21) = (char)uVar3;
    *(undefined *)((int)puVar1 + 0x22) = (char)uVar4;
    *puVar1 = (uint)ot[otz] & 0xffffff | 0x9000000;
    ot[otz] = (ulong *)((uint)puVar1 & 0xffffff);
    *(undefined *)((int)puVar1 + 0xb) = 0x3a;
    primPool->nextPrim = puVar1 + 10;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_CreateAGlowingCircle(struct _Vector *f1 /*$fp*/, long z /*$a1*/, struct _PrimPool *primPool /*stack 8*/, unsigned long **ot /*stack 12*/, long otz /*stack 16*/, long color /*stack 20*/, long w /*stack 24*/, long h /*stack 28*/, long angle /*stack 32*/)
 // line 3935, offset 0x8002b52c
	/* begin block 1 */
		// Start line: 3936
		// Start offset: 0x8002B52C
		// Variables:
	// 		long hold; // $t0
	// 		long x; // $s3
	// 		long y; // $v0
	// 		long diagScale; // $a2
	// 		struct _Vector width; // stack offset -232
	// 		struct _Vector height; // stack offset -216
	// 		struct _Vector diag1; // stack offset -200
	// 		struct _Vector diag2; // stack offset -184
	// 		struct _Vector points[9]; // stack offset -168

		/* begin block 1.1 */
			// Start line: 3949
			// Start offset: 0x8002B590
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $v1
		// 		long _z0; // $t3
		// 		long _x1; // $s1
		// 		long _y1; // $s7
		// 		long _z1; // $s0
		// 		struct _Vector *_v; // $t6
		// 		struct _Vector *_v1; // stack offset -48
		/* end block 1.1 */
		// End offset: 0x8002B590
		// End Line: 3949

		/* begin block 1.2 */
			// Start line: 3949
			// Start offset: 0x8002B590
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $v1
		// 		long _z0; // $t3
		// 		long _y1; // $s4
		// 		long _z1; // $s5
		// 		struct _Vector *_v1; // $s2
		/* end block 1.2 */
		// End offset: 0x8002B590
		// End Line: 3949

		/* begin block 1.3 */
			// Start line: 3949
			// Start offset: 0x8002B590
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $v1
		// 		long _z0; // $t3
		// 		long _x1; // $a0
		// 		long _y1; // $a0
		// 		long _z1; // $a1
		/* end block 1.3 */
		// End offset: 0x8002B590
		// End Line: 3949

		/* begin block 1.4 */
			// Start line: 3949
			// Start offset: 0x8002B590
			// Variables:
		// 		long _x0; // $v1
		// 		long _y0; // $a0
		// 		long _z0; // $t2
		// 		struct _Vector *_v; // $t4
		/* end block 1.4 */
		// End offset: 0x8002B590
		// End Line: 3949

		/* begin block 1.5 */
			// Start line: 3949
			// Start offset: 0x8002B590
			// Variables:
		// 		long _x0; // $v1
		// 		long _y0; // $a0
		// 		long _z0; // $t2
		/* end block 1.5 */
		// End offset: 0x8002B590
		// End Line: 3949

		/* begin block 1.6 */
			// Start line: 3949
			// Start offset: 0x8002B590
			// Variables:
		// 		long _x0; // $v1
		// 		long _y0; // $a0
		// 		long _z0; // $t2
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $a1
		/* end block 1.6 */
		// End offset: 0x8002B590
		// End Line: 3949

		/* begin block 1.7 */
			// Start line: 3949
			// Start offset: 0x8002B590
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $v1
		// 		long _z0; // $t0
		// 		long _y1; // $t1
		// 		struct _Vector *_v; // $t3
		/* end block 1.7 */
		// End offset: 0x8002B590
		// End Line: 3949

		/* begin block 1.8 */
			// Start line: 3949
			// Start offset: 0x8002B590
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $v1
		// 		long _z0; // $t0
		// 		struct _Vector *_v; // $s6
		/* end block 1.8 */
		// End offset: 0x8002B590
		// End Line: 3949

		/* begin block 1.9 */
			// Start line: 3949
			// Start offset: 0x8002B590
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $v1
		// 		long _z0; // $t0
		// 		long _y1; // $t1
		// 		struct _Vector *_v; // stack offset -52
		/* end block 1.9 */
		// End offset: 0x8002B590
		// End Line: 3949

		/* begin block 1.10 */
			// Start line: 3949
			// Start offset: 0x8002B590
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $v1
		// 		long _z0; // $t0
		// 		struct _Vector *_v; // $s4
		/* end block 1.10 */
		// End offset: 0x8002B590
		// End Line: 3949

		/* begin block 1.11 */
			// Start line: 3949
			// Start offset: 0x8002B590
			// Variables:
		// 		long _x0; // $t0
		// 		long _y0; // $t2
		// 		long _z0; // $t1
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $v1
		// 		struct _Vector *_v; // $s5
		/* end block 1.11 */
		// End offset: 0x8002B590
		// End Line: 3949

		/* begin block 1.12 */
			// Start line: 3949
			// Start offset: 0x8002B590
			// Variables:
		// 		long _x0; // $t0
		// 		long _y0; // $t2
		// 		long _z0; // $t1
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $v1
		// 		struct _Vector *_v; // $s3
		/* end block 1.12 */
		// End offset: 0x8002B590
		// End Line: 3949

		/* begin block 1.13 */
			// Start line: 3949
			// Start offset: 0x8002B590
			// Variables:
		// 		long _x0; // $t0
		// 		long _y0; // $t2
		// 		long _z0; // $t1
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $v1
		// 		struct _Vector *_v; // $s2
		/* end block 1.13 */
		// End offset: 0x8002B590
		// End Line: 3949

		/* begin block 1.14 */
			// Start line: 3949
			// Start offset: 0x8002B590
			// Variables:
		// 		long _x0; // $t0
		// 		long _y0; // $t2
		// 		long _z0; // $t1
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $v1
		// 		struct _Vector *_v; // $s1
		/* end block 1.14 */
		// End offset: 0x8002B590
		// End Line: 3949
	/* end block 1 */
	// End offset: 0x8002BAA8
	// End Line: 4028

	/* begin block 2 */
		// Start line: 5209
	/* end block 2 */
	// End Line: 5210

void DRAW_CreateAGlowingCircle
               (_Vector *f1,long z,_PrimPool *primPool,ulong **ot,long otz,long color,long w,long h,
               long angle)

{
  f1->z = 0;
  if ((0 < z) && (otz < 0xc00)) {
                    /* WARNING: Subroutine does not return */
    rcos(angle);
  }
  return;
}



// decompiled code
// original method signature: 
// unsigned long * /*$ra*/ DRAW_DrawGlowPoints2(struct _Instance *instance /*$s0*/, long seg1 /*$a1*/, long seg2 /*$s1*/, struct _PrimPool *primPool /*$s3*/, unsigned long **ot /*stack 16*/, long color /*stack 20*/, long height /*stack 24*/)
 // line 4038, offset 0x8002bad8
	/* begin block 1 */
		// Start line: 4039
		// Start offset: 0x8002BAD8
		// Variables:
	// 		struct _Position glowPoints1; // stack offset -88
	// 		struct _Position glowPoints2; // stack offset -80
	// 		struct _Vector f1; // stack offset -72
	// 		struct _Vector f2; // stack offset -56
	// 		struct _Vector f3; // stack offset -40
	// 		long otz; // $s2
	// 		long otz2; // $s0
	// 		long z; // $a1
	// 		long length; // $s1
	// 		long angle; // $v1
	/* end block 1 */
	// End offset: 0x8002BC24
	// End Line: 4079

	/* begin block 2 */
		// Start line: 5534
	/* end block 2 */
	// End Line: 5535

ulong * DRAW_DrawGlowPoints2
                  (_Instance *instance,long seg1,long seg2,_PrimPool *primPool,ulong **ot,long color
                  ,long height)

{
  long lVar1;
  long lVar2;
  int iVar3;
  _Position local_58;
  _Position local_50;
  int local_48;
  int local_44;
  int local_38;
  int local_34;
  int local_28;
  uint local_24;
  
  lVar1 = PIPE3D_Segment2ScreenPt(instance,DAT_800cfef0,seg1,&local_58);
  lVar2 = PIPE3D_Segment2ScreenPt(instance,DAT_800cfef0,seg2,&local_50);
  iVar3 = lVar1 + 0x14;
  if (lVar1 + 0x14 < lVar2 + 0x14) {
    iVar3 = lVar2 + 0x14;
  }
  if (0 < iVar3) {
    local_48 = (int)local_58.x;
    local_38 = (int)local_50.x;
    local_44 = (int)local_58.y;
    local_34 = (int)local_50.y;
    local_28 = local_38 - local_48;
    local_24 = local_34 - local_44;
    MATH3D_veclen2(local_28,local_24);
                    /* WARNING: Subroutine does not return */
    ratan2(local_24,-local_28);
  }
  return primPool->nextPrim;
}



// decompiled code
// original method signature: 
// unsigned long * /*$ra*/ DRAW_DrawGlowPoint(struct _Instance *instance /*$a0*/, long seg1 /*$a1*/, struct _PrimPool *primPool /*$s3*/, unsigned long **ot /*$s4*/, long color /*stack 16*/, int width /*stack 20*/, int height /*stack 24*/)
 // line 4089, offset 0x8002bc44
	/* begin block 1 */
		// Start line: 4090
		// Start offset: 0x8002BC44
		// Variables:
	// 		struct _Position glowPoints1; // stack offset -48
	// 		struct _Vector f1; // stack offset -40
	// 		long otz; // $t0
	// 		long z; // $a1
	// 		long angle; // $s2
	/* end block 1 */
	// End offset: 0x8002BCF0
	// End Line: 4115

	/* begin block 2 */
		// Start line: 5682
	/* end block 2 */
	// End Line: 5683

ulong * DRAW_DrawGlowPoint(_Instance *instance,long seg1,_PrimPool *primPool,ulong **ot,long color,
                          int width,int height)

{
  uint uVar1;
  long lVar2;
  int z;
  _Position local_30;
  _Vector local_28;
  
  uVar1 = theCamera.focusDistanceList[1][1] & 0x7ff;
  lVar2 = PIPE3D_Segment2ScreenPt(instance,DAT_800cfef0,seg1,&local_30);
  z = (lVar2 + 0x14) * 4;
  if (0 < z) {
    local_28.x = (int)local_30.x;
    local_28.y = (int)local_30.y;
    if (lVar2 + 0x1e < 0xc00) {
      DRAW_CreateAGlowingCircle
                (&local_28,z,primPool,ot,lVar2 + 0x1e,color,(int)(short)width,(int)(short)height,
                 uVar1 << 1);
    }
  }
  return primPool->nextPrim;
}



// decompiled code
// original method signature: 
// int /*$ra*/ DRAW_DisplayTFace_zclipped_C(struct SVECTOR *vertex0 /*stack 0*/, struct SVECTOR *vertex1 /*stack 4*/, struct SVECTOR *vertex2 /*stack 8*/, struct UVTYPE *uv0 /*stack 12*/, struct UVTYPE *uv1 /*stack 16*/, struct UVTYPE *uv2 /*stack 20*/, long color0 /*stack 24*/, long color1 /*stack 28*/, long color2 /*stack 32*/, struct _PrimPool *primPool /*stack 36*/, unsigned long **ot /*stack 40*/, int ndiv /*stack 44*/)
 // line 4192, offset 0x8002bd14
	/* begin block 1 */
		// Start line: 4193
		// Start offset: 0x8002BD14
		// Variables:
	// 		struct SP_SUBDIV_STRUCT *sp; // $t2
	// 		int maxz; // $s3
	// 		int point; // $a1
	// 		int n; // $t7
	// 		struct POLY_GT4 *prim; // $t9
	// 		long *ptr; // $t8
	// 		long clip; // $s0

		/* begin block 1.1 */
			// Start line: 4233
			// Start offset: 0x8002BE84
			// Variables:
		// 		int next_point_in_vv; // $v1
		// 		int current_point_in_vv; // $t1
		// 		int next; // $t6

			/* begin block 1.1.1 */
				// Start line: 4246
				// Start offset: 0x8002BEC4
				// Variables:
			// 		long clip_tmp; // $a0
			// 		long zval; // stack offset -48
			// 		struct SVECTOR *tmpptr; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8002BFA8
			// End Line: 4272

			/* begin block 1.1.2 */
				// Start line: 4276
				// Start offset: 0x8002BFB0
				// Variables:
			// 		long zn; // $v1
			// 		long znext; // $a0
			// 		long interp1; // $t1
			// 		long interp2; // $a2
			// 		long clip_tmp; // $v1

				/* begin block 1.1.2.1 */
					// Start line: 4280
					// Start offset: 0x8002BFB0
					// Variables:
				// 		long x; // $v1
				// 		long y; // $v1
				/* end block 1.1.2.1 */
				// End offset: 0x8002C094
				// End Line: 4291
			/* end block 1.1.2 */
			// End offset: 0x8002C1CC
			// End Line: 4305
		/* end block 1.1 */
		// End offset: 0x8002C1CC
		// End Line: 4306

		/* begin block 1.2 */
			// Start line: 4327
			// Start offset: 0x8002C20C
			// Variables:
		// 		int next; // $t0
		// 		int flag; // $t3
		/* end block 1.2 */
		// End offset: 0x8002C3E4
		// End Line: 4358

		/* begin block 1.3 */
			// Start line: 4361
			// Start offset: 0x8002C3E4
			// Variables:
		// 		long opz; // stack offset -44
		/* end block 1.3 */
		// End offset: 0x8002C438
		// End Line: 4376

		/* begin block 1.4 */
			// Start line: 4387
			// Start offset: 0x8002C498
			// Variables:
		// 		long temp1; // $a3
		// 		long temp2; // $t0
		// 		long temp3; // $t1
		/* end block 1.4 */
		// End offset: 0x8002C4A0
		// End Line: 4408
	/* end block 1 */
	// End offset: 0x8002C524
	// End Line: 4409

	/* begin block 2 */
		// Start line: 8384
	/* end block 2 */
	// End Line: 8385

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DRAW_DisplayTFace_zclipped_C
              (SVECTOR *vertex0,SVECTOR *vertex1,SVECTOR *vertex2,UVTYPE *uv0,UVTYPE *uv1,
              UVTYPE *uv2,long color0,long color1,long color2,_PrimPool *primPool,ulong **ot,
              int ndiv)

{
  bool bVar1;
  undefined4 in_zero;
  undefined4 in_at;
  byte bVar2;
  SVECTOR *pSVar3;
  SVECTOR *pSVar4;
  short sVar5;
  uint uVar6;
  ulong uVar7;
  ulong *puVar8;
  int iVar9;
  SVECTOR *pSVar10;
  undefined4 *puVar11;
  ulong uVar12;
  uint uVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  short *psVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int iVar19;
  undefined4 uVar20;
  int iVar21;
  uint uVar22;
  undefined4 *puVar23;
  int iVar24;
  int iVar25;
  undefined4 *puVar26;
  POLY_GT3 *texture;
  int iVar27;
  int iVar28;
  
  puVar15 = &DAT_1f800200;
  setCopReg(2,in_zero,*(undefined4 *)vertex0);
  setCopReg(2,in_at,*(undefined4 *)&vertex0->vz);
  copFunction(2,0x480012);
  DAT_1f800278 = getCopReg(2,0x19);
  DAT_1f80027c = getCopReg(2,0x1a);
  DAT_1f800280 = getCopReg(2,0x1b);
  setCopReg(2,in_zero,*(undefined4 *)vertex1);
  setCopReg(2,in_at,*(undefined4 *)&vertex1->vz);
  copFunction(2,0x480012);
  DAT_1f800284 = getCopReg(2,0x19);
  _DAT_1f800288 = getCopReg(2,0x1a);
  DAT_1f80028c = getCopReg(2,0x1b);
  setCopReg(2,in_zero,*(undefined4 *)vertex2);
  setCopReg(2,in_at,*(undefined4 *)&vertex2->vz);
  copFunction(2,0x480012);
  DAT_1f800290 = getCopReg(2,0x19);
  DAT_1f800294 = getCopReg(2,0x1a);
  DAT_1f800298 = getCopReg(2,0x1b);
  if (((DAT_1f800280 < 0xa0) && (DAT_1f80028c < 0xa0)) && (DAT_1f800298 < 0xa0)) {
    return 2;
  }
  iVar9 = 0;
  iVar25 = 0xa0;
  texture = (POLY_GT3 *)primPool->nextPrim;
  DAT_1f8002b8 = *uv0;
  uVar22 = 0xffff;
  iVar21 = 0;
  DAT_1f8002bc = *uv1;
  iVar24 = 0;
  DAT_1f8002c0 = *uv2;
  _DAT_1f8002a8 = color0;
  puVar26 = (undefined4 *)&texture->r0;
  DAT_1f8002ac = color1;
  psVar16 = &texture->y0;
  DAT_1f8002b0 = color2;
  pSVar3 = vertex0;
  pSVar10 = vertex2;
  puVar11 = puVar15;
  puVar23 = puVar15;
  do {
    iVar19 = iVar21 + 1;
    if (2 < iVar19) {
      iVar19 = 0;
    }
    uVar13 = (uint)((int)puVar11[0x20] < 0xa0) ^ 1;
    uVar6 = (uint)((int)(&DAT_1f800280)[iVar19 * 3] < 0xa0) ^ 1;
    if (uVar13 != 0) {
      pSVar3 = vertex1;
      if (((iVar21 != 1) && (pSVar3 = vertex0, 1 < iVar21)) && (iVar21 == 2)) {
        pSVar3 = vertex2;
      }
      setCopReg(2,in_zero,*(undefined4 *)pSVar3);
      setCopReg(2,in_at,*(undefined4 *)&pSVar3->vz);
      copFunction(2,0x180001);
      *(undefined4 *)(psVar16 + 1) = puVar23[0x2e];
      *puVar26 = puVar23[0x2a];
      uVar17 = getCopReg(2,0xe);
      puVar26[1] = uVar17;
      uVar17 = getCopReg(2,0xe);
      (&DAT_1f8002c4)[iVar9] = uVar17;
      iVar27 = getCopReg(2,0x13);
      if (iVar25 < iVar27) {
        iVar25 = iVar27;
      }
      pSVar3 = (SVECTOR *)((uint)(int)psVar16[-1] >> 0x1f);
      if (*psVar16 < 0) {
        pSVar3 = (SVECTOR *)((uint)pSVar3 | 2);
      }
      if (0x200 < (int)psVar16[-1]) {
        pSVar3 = (SVECTOR *)((uint)pSVar3 | 4);
      }
      if (0xf0 < *psVar16) {
        pSVar3 = (SVECTOR *)((uint)pSVar3 | 8);
      }
      uVar22 = uVar22 & (uint)pSVar3;
      iVar9 = iVar9 + 1;
      psVar16 = psVar16 + 6;
      puVar26 = puVar26 + 3;
    }
    if (uVar13 != uVar6) {
      iVar27 = ((puVar11[0x20] + -0xa0) * 0x1000) /
               (int)(puVar11[0x20] - (&DAT_1f800280)[iVar19 * 3]);
      if (iVar27 < 0) {
        iVar27 = -iVar27;
      }
      iVar28 = ((&DAT_1f800278)[iVar19 * 3] - puVar11[0x1e]) * iVar27;
      pSVar10 = (SVECTOR *)(0x1000 - iVar27);
      if (iVar28 < 0) {
        iVar28 = iVar28 + 0xfff;
      }
      iVar28 = (puVar11[0x1e] + (iVar28 >> 0xc)) * 2 + 0x100;
      sVar5 = (short)iVar28;
      if (0x3ff < iVar28) {
        sVar5 = 0x3ff;
      }
      if (iVar28 < -0x3ff) {
        sVar5 = -0x3ff;
      }
      psVar16[-1] = sVar5;
      iVar28 = ((&DAT_1f80027c)[iVar19 * 3] - puVar11[0x1f]) * iVar27;
      if (iVar28 < 0) {
        iVar28 = iVar28 + 0xfff;
      }
      iVar28 = (puVar11[0x1f] + (iVar28 >> 0xc)) * 2 + 0x78;
      sVar5 = (short)iVar28;
      if (0x3ff < iVar28) {
        sVar5 = 0x3ff;
      }
      if (iVar28 < -0x3ff) {
        sVar5 = -0x3ff;
      }
      *psVar16 = sVar5;
      setCopReg(2,0x4000,pSVar10);
      setCopReg(2,0x4800,(uint)*(byte *)((int)&DAT_1f8002b8 + iVar24));
      setCopReg(2,0x5000,(uint)*(byte *)((int)&DAT_1f8002b8 + iVar24 + 1));
      copFunction(2,0x198003d);
      setCopReg(2,0x4000,iVar27);
      iVar28 = iVar19 * 4;
      setCopReg(2,0x4800,(uint)*(byte *)(&DAT_1f8002b8 + iVar19));
      setCopReg(2,0x5000,(uint)*(byte *)((int)&DAT_1f8002b8 + iVar28 + 1));
      copFunction(2,0x1a8003e);
      uVar17 = getCopReg(2,0x4800);
      uVar18 = getCopReg(2,0x5000);
      *(char *)(puVar26 + 2) = (char)uVar17;
      *(undefined *)((int)puVar26 + 9) = (char)uVar18;
      setCopReg(2,0x4000,pSVar10);
      setCopReg(2,0x4800,(uint)(byte)(&DAT_1f8002a8)[iVar24]);
      setCopReg(2,0x5000,(uint)(byte)(&DAT_1f8002a9)[iVar24]);
      setCopReg(2,0x5800,(uint)*(byte *)((int)&DAT_1f8002aa + iVar24));
      copFunction(2,0x198003d);
      setCopReg(2,0x4000,iVar27);
      setCopReg(2,0x4800,(uint)(byte)(&DAT_1f8002a8)[iVar28]);
      setCopReg(2,0x5000,(uint)(byte)(&DAT_1f8002a9)[iVar28]);
      setCopReg(2,0x5800,(uint)*(byte *)(&DAT_1f8002aa + iVar19 * 2));
      copFunction(2,0x1a8003e);
      uVar17 = getCopReg(2,0x4800);
      uVar18 = getCopReg(2,0x5000);
      uVar20 = getCopReg(2,0x5800);
      *(char *)puVar26 = (char)uVar17;
      *(undefined *)((int)puVar26 + 1) = (char)uVar18;
      *(undefined *)((int)puVar26 + 2) = (char)uVar20;
      (&DAT_1f8002c4)[iVar9] = *(undefined4 *)(psVar16 + -1);
      pSVar3 = (SVECTOR *)(int)*psVar16;
      uVar6 = (uint)(int)psVar16[-1] >> 0x1f;
      if ((int)pSVar3 < 0) {
        uVar6 = uVar6 | 2;
      }
      if (0x200 < (int)psVar16[-1]) {
        uVar6 = uVar6 | 4;
      }
      if (0xf0 < (int)pSVar3) {
        uVar6 = uVar6 | 8;
      }
      uVar22 = uVar22 & uVar6;
      iVar9 = iVar9 + 1;
      psVar16 = psVar16 + 6;
      puVar26 = puVar26 + 3;
    }
    iVar24 = iVar24 + 4;
    puVar11 = puVar11 + 3;
    iVar21 = iVar21 + 1;
    puVar23 = puVar23 + 1;
  } while (iVar21 < 3);
  if (uVar22 != 0) {
    return 2;
  }
  iVar25 = iVar25 >> 2;
  uVar22 = (uint)(iVar25 < 0xc00);
  if (iVar25 < 0xc00) {
    if (ndiv == 0) {
      bVar1 = false;
      if (0 < iVar9) {
        iVar24 = 1;
        iVar21 = 0;
        do {
          iVar19 = iVar24 << 2;
          if (iVar9 <= iVar24) {
            iVar24 = 0;
            iVar19 = 0;
          }
          pSVar3 = (SVECTOR *)(int)*(short *)(puVar15 + 0x31);
          uVar6 = SEXT24(*(short *)((int)&DAT_1f8002c4 + iVar19));
          pSVar4 = (SVECTOR *)((int)pSVar3 - uVar6);
          if ((int)pSVar4 < 0) {
            pSVar4 = (SVECTOR *)(uVar6 - (int)pSVar3);
          }
          uVar22 = iVar24 * 4;
          if (0x3ff < (int)pSVar4) {
LAB_8002c298:
            bVar1 = true;
            break;
          }
          pSVar3 = (SVECTOR *)(int)*(short *)((int)puVar15 + 0xc6);
          uVar6 = SEXT24(*(short *)((int)&DAT_1f8002c4 + uVar22 + 2));
          pSVar4 = (SVECTOR *)((int)pSVar3 - uVar6);
          if ((int)pSVar4 < 0) {
            pSVar4 = (SVECTOR *)(uVar6 - (int)pSVar3);
          }
          uVar22 = (uint)((int)pSVar4 < 0x200);
          if ((int)pSVar4 >= 0x200) goto LAB_8002c298;
          puVar15 = puVar15 + 1;
          iVar19 = iVar21 + 1;
          uVar22 = (uint)(iVar19 < iVar9);
          iVar24 = iVar21 + 2;
          iVar21 = iVar19;
        } while (iVar19 < iVar9);
      }
      if (bVar1) goto LAB_8002c34c;
      uVar22 = 4;
      if (iVar9 == 4) {
        pSVar3 = (SVECTOR *)(int)DAT_1f8002d0;
        uVar6 = SEXT24((short)DAT_1f8002c8);
        pSVar4 = (SVECTOR *)((int)pSVar3 - uVar6);
        if ((int)pSVar4 < 0) {
          pSVar4 = (SVECTOR *)(uVar6 - (int)pSVar3);
        }
        uVar22 = (uint)((int)pSVar4 < 0x400);
        if ((int)pSVar4 < 0x400) {
          pSVar3 = (SVECTOR *)(int)DAT_1f8002d2;
          uVar6 = SEXT24(DAT_1f8002c8._2_2_);
          pSVar4 = (SVECTOR *)((int)pSVar3 - uVar6);
          if ((int)pSVar4 < 0) {
            pSVar4 = (SVECTOR *)(uVar6 - (int)pSVar3);
          }
          uVar22 = (uint)((int)pSVar4 < 0x200);
          if ((int)pSVar4 < 0x200) goto LAB_8002c344;
        }
        bVar1 = true;
      }
LAB_8002c344:
      if (bVar1) {
LAB_8002c34c:
        setCopReg(2,in_zero,*(undefined4 *)vertex0);
        setCopReg(2,in_at,*(undefined4 *)&vertex0->vz);
        setCopReg(2,uVar22,*(undefined4 *)vertex1);
        setCopReg(2,uVar6,*(undefined4 *)&vertex1->vz);
        setCopReg(2,pSVar3,*(undefined4 *)vertex2);
        setCopReg(2,iVar9,*(undefined4 *)&vertex2->vz);
        DAT_1f8002b0 = _DAT_1f8002a8 & 0xff000000 | DAT_1f8002b0 & 0xffffff;
        setCopReg(2,primPool,_DAT_1f8002a8);
        setCopReg(2,vertex2,DAT_1f8002ac);
        setCopReg(2,vertex0,DAT_1f8002b0);
        setCopReg(2,pSVar10,DAT_1f8002b0);
        *(UVTYPE *)&texture->u0 = *uv0;
        *(UVTYPE *)&texture->u1 = *uv1;
        *(UVTYPE *)&texture->u2 = *uv2;
        DRAW_Zclip_subdiv(texture,ot,1);
        return 1;
      }
    }
    setCopReg(2,0x6000,*(undefined4 *)&texture->x0);
    setCopReg(2,0x7000,*(undefined4 *)&texture->x2);
    setCopReg(2,0x6800,*(undefined4 *)&texture->x1);
    copFunction(2,0x1400006);
    texture->clut = DAT_1f8002b8.pad;
    texture->tpage = DAT_1f8002bc.pad;
    iVar21 = getCopReg(2,0x18);
    if (0 < iVar21) {
      return 4;
    }
    bVar2 = (byte)((uint)color0 >> 0x18);
    if (iVar9 == 3) {
      texture->code = bVar2;
      texture->tag = (uint)ot[iVar25] & 0xffffff | 0x9000000;
      ot[iVar25] = (ulong *)((uint)texture & 0xffffff);
      iVar9 = primPool->numPrims;
      puVar8 = primPool->nextPrim + 10;
    }
    else {
      if (iVar9 != 4) goto LAB_8002c498;
      uVar12 = *(ulong *)&texture->r2;
      uVar20 = *(undefined4 *)&texture->x2;
      uVar14 = *(undefined4 *)&texture->u2;
      uVar7 = texture[1].tag;
      uVar17 = *(undefined4 *)&texture[1].r0;
      uVar18 = *(undefined4 *)&texture[1].x0;
      texture->code = bVar2 | 8;
      *(ulong *)&texture->r2 = uVar7;
      *(undefined4 *)&texture->x2 = uVar17;
      *(undefined4 *)&texture->u2 = uVar18;
      texture[1].tag = uVar12;
      *(undefined4 *)&texture[1].r0 = uVar20;
      *(undefined4 *)&texture[1].x0 = uVar14;
      texture->tag = (uint)ot[iVar25] & 0xffffff | 0xc000000;
      ot[iVar25] = (ulong *)((uint)texture & 0xffffff);
      iVar9 = primPool->numPrims;
      puVar8 = primPool->nextPrim + 0xd;
    }
    iVar25 = 1;
    primPool->nextPrim = puVar8;
    primPool->numPrims = iVar9 + 1;
  }
  else {
LAB_8002c498:
    iVar25 = 2;
  }
  return iVar25;
}



// decompiled code
// original method signature: 
// long * /*$ra*/ DRAW_Zclip_subdiv(struct POLY_GT3 *texture /*$t0*/, unsigned long **ot /*stack 4*/, int ndiv /*stack 8*/)
 // line 4420, offset 0x8002c554
	/* begin block 1 */
		// Start line: 4421
		// Start offset: 0x8002C554
		// Variables:
	// 		struct SP_SUBDIV_STRUCT *sp; // $s7
	// 		struct _PrimPool *primPool; // $fp
	// 		int clip; // $s0
	/* end block 1 */
	// End offset: 0x8002CA28
	// End Line: 4556

	/* begin block 2 */
		// Start line: 6517
	/* end block 2 */
	// End Line: 6518

long * DRAW_Zclip_subdiv(POLY_GT3 *texture,ulong **ot,int ndiv)

{
  undefined4 uVar1;
  long primPool;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  long *plVar6;
  SVECTOR *vertex2;
  UVTYPE *uv1;
  UVTYPE *uv2;
  SVECTOR *vertex1;
  SVECTOR *vertex1_00;
  UVTYPE *uv1_00;
  undefined4 *puVar7;
  
  puVar7 = &DAT_1f800200;
  if (ndiv != 0) {
    puVar7 = &DAT_1f8002d4;
  }
  uVar1 = getCopReg(2,0x14);
  puVar7[0x18] = uVar1;
  uVar1 = getCopReg(2,0x15);
  puVar7[0x19] = uVar1;
  uVar1 = getCopReg(2,0x16);
  puVar7[0x1a] = uVar1;
  uVar1 = getCopReg(2,0);
  *puVar7 = uVar1;
  uVar1 = getCopReg(2,1);
  puVar7[1] = uVar1;
  uVar1 = getCopReg(2,2);
  puVar7[2] = uVar1;
  uVar1 = getCopReg(2,3);
  puVar7[3] = uVar1;
  uVar1 = getCopReg(2,4);
  puVar7[4] = uVar1;
  uVar1 = getCopReg(2,5);
  puVar7[5] = uVar1;
  primPool = theCamera.core.vvPlaneConsts[2];
  *(POLY_GT3 **)(theCamera.core.vvPlaneConsts[2] + 4) = texture;
  puVar7[8] = puVar7[2];
  puVar7[7] = puVar7[1];
  puVar7[9] = puVar7[3];
  puVar7[10] = puVar7[4];
  puVar7[0xb] = puVar7[5];
  puVar7[6] = *puVar7;
  *(short *)(puVar7 + 0xc) =
       (short)(((int)*(short *)(puVar7 + 6) + (int)*(short *)(puVar7 + 8)) / 2);
  *(undefined2 *)((int)puVar7 + 0x32) =
       (short)(((int)*(short *)((int)puVar7 + 0x1a) + (int)*(short *)((int)puVar7 + 0x22)) / 2);
  *(short *)(puVar7 + 0xd) =
       (short)(((int)*(short *)(puVar7 + 7) + (int)*(short *)(puVar7 + 9)) / 2);
  *(short *)(puVar7 + 0xe) =
       (short)(((int)*(short *)(puVar7 + 8) + (int)*(short *)(puVar7 + 10)) / 2);
  *(undefined2 *)((int)puVar7 + 0x3a) =
       (short)(((int)*(short *)((int)puVar7 + 0x22) + (int)*(short *)((int)puVar7 + 0x2a)) / 2);
  *(short *)(puVar7 + 0xf) =
       (short)(((int)*(short *)(puVar7 + 9) + (int)*(short *)(puVar7 + 0xb)) / 2);
  *(short *)(puVar7 + 0x10) =
       (short)(((int)*(short *)(puVar7 + 10) + (int)*(short *)(puVar7 + 6)) / 2);
  *(undefined2 *)((int)puVar7 + 0x42) =
       (short)(((int)*(short *)((int)puVar7 + 0x2a) + (int)*(short *)((int)puVar7 + 0x1a)) / 2);
  *(short *)(puVar7 + 0x11) =
       (short)(((int)*(short *)(puVar7 + 0xb) + (int)*(short *)(puVar7 + 7)) / 2);
  uv1_00 = (UVTYPE *)(puVar7 + 0x15);
  puVar7[0x12] = *(undefined4 *)&texture->u0;
  uv2 = (UVTYPE *)(puVar7 + 0x17);
  puVar7[0x13] = *(undefined4 *)&texture->u1;
  vertex1_00 = (SVECTOR *)(puVar7 + 0xc);
  puVar7[0x14] = *(undefined4 *)&texture->u2;
  *(char *)(puVar7 + 0x15) =
       (char)((int)((uint)*(byte *)(puVar7 + 0x12) + (uint)*(byte *)(puVar7 + 0x13)) >> 1);
  vertex2 = (SVECTOR *)(puVar7 + 0x10);
  *(undefined2 *)((int)puVar7 + 0x5a) = *(undefined2 *)((int)puVar7 + 0x4e);
  *(undefined2 *)((int)puVar7 + 0x56) = *(undefined2 *)((int)puVar7 + 0x4e);
  *(undefined *)((int)puVar7 + 0x55) =
       (char)((int)((uint)*(byte *)((int)puVar7 + 0x49) + (uint)*(byte *)((int)puVar7 + 0x4d)) >> 1)
  ;
  *(char *)(puVar7 + 0x16) =
       (char)((int)((uint)*(byte *)(puVar7 + 0x13) + (uint)*(byte *)(puVar7 + 0x14)) >> 1);
  *(undefined *)((int)puVar7 + 0x59) =
       (char)((int)((uint)*(byte *)((int)puVar7 + 0x4d) + (uint)*(byte *)((int)puVar7 + 0x51)) >> 1)
  ;
  *(char *)(puVar7 + 0x17) =
       (char)((int)((uint)*(byte *)(puVar7 + 0x14) + (uint)*(byte *)(puVar7 + 0x12)) >> 1);
  *(undefined *)((int)puVar7 + 0x5d) =
       (char)((int)((uint)*(byte *)((int)puVar7 + 0x51) + (uint)*(byte *)((int)puVar7 + 0x49)) >> 1)
  ;
  *(undefined2 *)((int)puVar7 + 0x5e) = *(undefined2 *)((int)puVar7 + 0x4a);
  *(char *)(puVar7 + 0x1b) =
       (char)((int)((uint)*(byte *)(puVar7 + 0x18) + (uint)*(byte *)(puVar7 + 0x19)) >> 1);
  *(undefined *)((int)puVar7 + 0x6d) =
       (char)((int)((uint)*(byte *)((int)puVar7 + 0x61) + (uint)*(byte *)((int)puVar7 + 0x65)) >> 1)
  ;
  *(undefined *)((int)puVar7 + 0x6e) =
       (char)((int)((uint)*(byte *)((int)puVar7 + 0x62) + (uint)*(byte *)((int)puVar7 + 0x66)) >> 1)
  ;
  *(char *)(puVar7 + 0x1c) =
       (char)((int)((uint)*(byte *)(puVar7 + 0x19) + (uint)*(byte *)(puVar7 + 0x1a)) >> 1);
  *(undefined *)((int)puVar7 + 0x71) =
       (char)((int)((uint)*(byte *)((int)puVar7 + 0x65) + (uint)*(byte *)((int)puVar7 + 0x69)) >> 1)
  ;
  *(undefined *)((int)puVar7 + 0x72) =
       (char)((int)((uint)*(byte *)((int)puVar7 + 0x66) + (uint)*(byte *)((int)puVar7 + 0x6a)) >> 1)
  ;
  *(char *)(puVar7 + 0x1d) =
       (char)((int)((uint)*(byte *)(puVar7 + 0x1a) + (uint)*(byte *)(puVar7 + 0x18)) >> 1);
  *(undefined *)((int)puVar7 + 0x75) =
       (char)((int)((uint)*(byte *)((int)puVar7 + 0x69) + (uint)*(byte *)((int)puVar7 + 0x61)) >> 1)
  ;
  *(undefined *)((int)puVar7 + 0x76) =
       (char)((int)((uint)*(byte *)((int)puVar7 + 0x6a) + (uint)*(byte *)((int)puVar7 + 0x62)) >> 1)
  ;
  *(undefined *)((int)puVar7 + 0x77) = *(undefined *)((int)puVar7 + 99);
  *(undefined *)((int)puVar7 + 0x6f) = *(undefined *)((int)puVar7 + 99);
  uVar2 = DRAW_DisplayTFace_zclipped_C
                    ((SVECTOR *)(puVar7 + 6),vertex1_00,vertex2,(UVTYPE *)(puVar7 + 0x12),uv1_00,uv2
                     ,puVar7[0x18],puVar7[0x1b],puVar7[0x1d],(_PrimPool *)primPool,ot,ndiv);
  uv1 = (UVTYPE *)(puVar7 + 0x16);
  vertex1 = (SVECTOR *)(puVar7 + 0xe);
  uVar3 = DRAW_DisplayTFace_zclipped_C
                    (vertex2,vertex1,(SVECTOR *)((uint)puVar7 | 0x28),uv2,uv1,
                     (UVTYPE *)(puVar7 + 0x14),puVar7[0x1d],puVar7[0x1c],puVar7[0x1a],
                     (_PrimPool *)primPool,ot,ndiv);
  *(undefined2 *)((int)puVar7 + 0x56) = *(undefined2 *)((int)puVar7 + 0x4a);
  *(undefined2 *)((int)puVar7 + 0x5e) = *(undefined2 *)((int)puVar7 + 0x4e);
  uVar4 = DRAW_DisplayTFace_zclipped_C
                    (vertex1_00,vertex1,vertex2,uv1_00,uv1,uv2,puVar7[0x1b],puVar7[0x1c],
                     puVar7[0x1d],(_PrimPool *)primPool,ot,ndiv);
  uVar5 = DRAW_DisplayTFace_zclipped_C
                    (vertex1_00,(SVECTOR *)((uint)puVar7 | 0x20),vertex1,uv1_00,
                     (UVTYPE *)(puVar7 + 0x13),uv1,puVar7[0x1b],puVar7[0x19],puVar7[0x1c],
                     (_PrimPool *)primPool,ot,ndiv);
  plVar6 = (long *)0x0;
  if (((uVar2 | uVar3 | uVar4 | uVar5) & 5) != 4) {
    plVar6 = *(long **)(primPool + 4);
  }
  return plVar6;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_LoadingMessage()
 // line 4569, offset 0x8002ca58
	/* begin block 1 */
		// Start line: 4572
		// Start offset: 0x8002CA68
		// Variables:
	// 		unsigned long **drawot; // $s0
	/* end block 1 */
	// End offset: 0x8002CA90
	// End Line: 4583

	/* begin block 2 */
		// Start line: 7028
	/* end block 2 */
	// End Line: 7029

void DRAW_LoadingMessage(void)

{
  int iVar1;
  char *text;
  int len;
  
  do {
    iVar1 = CheckVolatile(uGpffffb614);
  } while (iVar1 != 0);
  do {
    iVar1 = CheckVolatile(uGpffffb610);
  } while (iVar1 != 0);
  DrawSyncCallback(0);
  VSyncCallback(0);
  iVar1 = iGpffffb6cc;
  PutDrawEnv((undefined4 *)(&gp0xffffb3b8 + (uGpffffb528 ^ 1) * 0x5c));
  text = localstr_get(LOCALSTR_Hint52);
  FONT_FontPrintCentered(text,0x96);
  text = localstr_get(LOCALSTR_Hint52);
  len = FONT_GetStringWidth(text);
  DisplayHintBox(len,0x96);
  FONT_Flush();
  DrawOTag(*(undefined4 *)(&DAT_00002ffc + iVar1));
                    /* WARNING: Subroutine does not return */
  DrawSync(0);
}





