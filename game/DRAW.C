#include "THISDUST.H"
#include "DRAW.H"


// decompiled code
// original method signature: 
// void /*$ra*/ fDRAW_SPLIT_INTPL_XYZ(struct _SVector *newVertex /*$a0*/, struct _SVector *pvb /*$a1*/, struct _SVector *pvc /*$a2*/)
 // line 58, offset 0x8002a874
	/* begin block 1 */
		// Start line: 116
	/* end block 1 */
	// End Line: 117

	/* begin block 2 */
		// Start line: 117
	/* end block 2 */
	// End Line: 118

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
 // line 451, offset 0x8002a8f0
	/* begin block 1 */
		// Start line: 452
		// Start offset: 0x8002A8F0
		// Variables:
	// 		int n; // $s3
	// 		int inc; // $s4
	// 		int deg; // $s2
	/* end block 1 */
	// End offset: 0x8002A984
	// End Line: 465

	/* begin block 2 */
		// Start line: 513
	/* end block 2 */
	// End Line: 514

	/* begin block 3 */
		// Start line: 903
	/* end block 3 */
	// End Line: 904

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DRAW_InitShadow(void)

{
  int iVar1;
  int iVar2;
  SVECTOR *pSVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  iVar5 = 0;
  pSVar3 = &shadow_vertices;
  do {
    iVar2 = iVar4;
    if (iVar4 < 0) {
      iVar2 = iVar4 + 0xfff;
    }
    iVar1 = rcos(iVar2 >> 0xc);
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0x1f;
    }
    pSVar3->vx = (short)(iVar1 >> 5);
    iVar2 = rsin(iVar2 >> 0xc);
    if (iVar2 < 0) {
      iVar2 = iVar2 + 0x1f;
    }
    iVar4 = iVar4 + 0x199999;
    pSVar3->vy = (short)(iVar2 >> 5);
    pSVar3->vz = 0;
    iVar5 = iVar5 + 1;
    pSVar3 = pSVar3 + 1;
  } while (iVar5 < 10);
  SVECTOR_800d143c.vx = shadow_vertices.vx;
  SVECTOR_800d143c.vy = shadow_vertices.vy;
  SVECTOR_800d143c.vz = shadow_vertices.vz;
  return;
}



// decompiled code
// original method signature: 
// unsigned long * /*$ra*/ DRAW_DrawShadow(struct _PrimPool *primPool /*$t3*/, struct _Model *model /*$a1*/, unsigned long **ot /*$a2*/, long fadeValue /*$a3*/)
 // line 475, offset 0x8002a9bc
	/* begin block 1 */
		// Start line: 476
		// Start offset: 0x8002A9BC
		// Variables:
	// 		struct POLY_G3_SEMITRANS *sg3; // $a1
	// 		struct SVECTOR zero_vertex; // stack offset -24
	// 		long clip; // stack offset -8
	// 		long n; // $t0
	// 		long p; // stack offset -16
	// 		long otz; // stack offset -4
	// 		unsigned long color; // stack offset -12
	/* end block 1 */
	// End offset: 0x8002AB7C
	// End Line: 535

	/* begin block 2 */
		// Start line: 977
	/* end block 2 */
	// End Line: 978

ulong * DRAW_DrawShadow(_PrimPool *primPool,_Model *model,ulong **ot,long fadeValue)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  undefined4 in_zero;
  undefined4 in_at;
  uint uVar5;
  _PrimPool *p_Var6;
  ulong *puVar7;
  ulong *puVar8;
  int iVar9;
  SVECTOR *pSVar10;
  uint local_14;
  long local_10;
  
  puVar7 = primPool->nextPrim;
  local_14 = local_14 & 0xffff0000;
  setCopReg(2,in_zero,0);
  setCopReg(2,in_at,local_14);
  copFunction(2,0x180001);
  iVar9 = getCopReg(2,8);
  local_10 = iVar9;
  if ((fadeValue <= iVar9) || (local_10 = fadeValue, fadeValue < 0x1001)) {
    iVar9 = local_10;
  }
  local_10 = iVar9;
  setCopReg(2,ot,0x606060);
  setCopReg(2,0x4000,local_10);
  copFunction(2,0x780010);
  uVar1 = getCopReg(2,0x16);
  iVar9 = 0;
  pSVar10 = &shadow_vertices;
  puVar8 = puVar7 + 1;
  uVar5 = uVar1 | 0x32000000;
  p_Var6 = primPool;
  do {
    setCopReg(2,uVar5,*(undefined4 *)pSVar10);
    setCopReg(2,iVar9 * 8,*(undefined4 *)&pSVar10->vz);
    setCopReg(2,p_Var6,*(undefined4 *)(&SVECTOR_800d13f4 + iVar9));
    setCopReg(2,puVar7,*(undefined4 *)&(&SVECTOR_800d13f4)[iVar9].vz);
    copFunction(2,0x280030);
    if (primPool->lastPrim + -0xc < puVar7) {
      return puVar7;
    }
    copFunction(2,0x1400006);
    iVar2 = getCopReg(2,0x18);
    if (iVar2 < 0) {
      copFunction(2,0x158002d);
      iVar2 = getCopReg(2,7);
      p_Var6 = (_PrimPool *)(puVar7 + 3);
      if (iVar2 - 0x40U < 0xbc0) {
        lVar3 = getCopReg(2,0xc);
        p_Var6->numPrims = lVar3;
        uVar4 = getCopReg(2,0xd);
        puVar7[5] = uVar4;
        uVar4 = getCopReg(2,0xe);
        puVar7[7] = uVar4;
        puVar8[3] = 0;
        puVar8[5] = 0;
        puVar8[1] = uVar1 | 0x32000000;
        *puVar8 = 0xe1000640;
        puVar8 = puVar8 + 8;
        p_Var6 = (_PrimPool *)(ot + iVar2);
        *puVar7 = p_Var6->numPrims & 0xffffffU | 0x7000000;
        p_Var6->numPrims = (uint)puVar7 & 0xffffff;
        puVar7 = puVar7 + 8;
        primPool->numPrims = primPool->numPrims + 1;
      }
    }
    iVar9 = iVar9 + 1;
    uVar5 = (uint)(iVar9 < 10);
    pSVar10 = pSVar10 + 1;
  } while (iVar9 < 10);
  return puVar7;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_CalculateChromeMapping(struct _PolytopeList *polytopeList /*$a0*/, struct _Terrain *terrain /*$a1*/, struct _CameraCore_Type *cameraCore /*$a2*/, struct GameTracker *gameTracker /*$a3*/)
 // line 1943, offset 0x8002ab84
	/* begin block 1 */
		// Start line: 3874
	/* end block 1 */
	// End Line: 3875

	/* begin block 2 */
		// Start line: 2642
	/* end block 2 */
	// End Line: 2643

void DRAW_CalculateChromeMapping
               (_PolytopeList *polytopeList,_Terrain *terrain,_CameraCore_Type *cameraCore,
               GameTracker *gameTracker)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_FlatQuad(struct CVECTOR *color /*$a0*/, short x0 /*$a1*/, short y0 /*$a2*/, short x1 /*$a3*/, int y1 /*stack 16*/, int x2 /*stack 20*/, int y2 /*stack 24*/, int x3 /*stack 28*/, int y3 /*stack 32*/, struct _PrimPool *primPool /*stack 36*/, unsigned long **ot /*stack 40*/)
 // line 3204, offset 0x8002ab8c
	/* begin block 1 */
		// Start line: 3205
		// Start offset: 0x8002AB8C
		// Variables:
	// 		unsigned long *prim; // $t0
	/* end block 1 */
	// End offset: 0x8002AC2C
	// End Line: 3224

	/* begin block 2 */
		// Start line: 6203
	/* end block 2 */
	// End Line: 6204

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
 // line 3241, offset 0x8002ac34
	/* begin block 1 */
		// Start line: 3242
		// Start offset: 0x8002AC34
		// Variables:
	// 		unsigned long *prim; // $t0
	/* end block 1 */
	// End offset: 0x8002AD08
	// End Line: 3268

	/* begin block 2 */
		// Start line: 3997
	/* end block 2 */
	// End Line: 3998

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
// void /*$ra*/ DRAW_DrawButton(struct _ButtonTexture *button /*$s4*/, short x /*$a1*/, short y /*$a2*/, unsigned long **ot /*stack 12*/)
 // line 3515, offset 0x8002ad18
	/* begin block 1 */
		// Start line: 3516
		// Start offset: 0x8002AD18
		// Variables:
	// 		struct _PrimPool *primPool; // $s7
	// 		unsigned long *prim; // $s2
	// 		short w; // stack offset -48
	// 		short h; // $s3
	// 		short offsetx; // $s0
	// 		short offsety; // $s1
	/* end block 1 */
	// End offset: 0x8002AE54
	// End Line: 3570

	/* begin block 2 */
		// Start line: 6936
	/* end block 2 */
	// End Line: 6937

void DRAW_DrawButton(_ButtonTexture *button,short x,short y,ulong **ot)

{
  ushort uVar1;
  short sVar2;
  _PrimPool *p_Var3;
  char cVar4;
  uint uVar5;
  short sVar6;
  char cVar7;
  char cVar8;
  ulong *puVar9;
  short sVar10;
  int iVar11;
  
  p_Var3 = gameTrackerX.primPool;
  puVar9 = (gameTrackerX.primPool)->nextPrim;
  if (puVar9 <= (gameTrackerX.primPool)->lastPrim + -0xc) {
    uVar5 = button->xshift;
    sVar10 = button->textureH;
    iVar11 = (int)button->textureW << (uVar5 & 0x1f);
    if (0 < (int)uVar5) {
      sVar10 = sVar10 + -1;
    }
    uVar1 = button->vramBlock->x;
    cVar8 = *(char *)&button->vramBlock->y;
    SetPolyFT4((int)puVar9);
    *(byte *)((int)puVar9 + 7) = *(byte *)((int)puVar9 + 7) | 1;
    *(short *)((int)puVar9 + 0x16) = button->tpage;
    sVar2 = button->clut;
    sVar6 = x + (short)iVar11;
    *(short *)(puVar9 + 2) = x;
    *(short *)((int)puVar9 + 10) = y;
    cVar7 = (char)(((uint)uVar1 & 0x3f) << (uVar5 & 0x1f));
    *(char *)(puVar9 + 3) = cVar7;
    *(char *)((int)puVar9 + 0xd) = cVar8;
    *(short *)(puVar9 + 4) = sVar6;
    *(short *)((int)puVar9 + 0x12) = y;
    cVar4 = cVar7 + (char)iVar11;
    *(char *)((int)puVar9 + 0x15) = cVar8;
    cVar8 = cVar8 + (char)sVar10;
    *(char *)(puVar9 + 5) = cVar4;
    *(short *)(puVar9 + 6) = x;
    *(short *)((int)puVar9 + 0x1a) = y + sVar10;
    *(char *)(puVar9 + 7) = cVar7;
    *(char *)((int)puVar9 + 0x1d) = cVar8;
    *(short *)(puVar9 + 8) = sVar6;
    *(short *)((int)puVar9 + 0x22) = y + sVar10;
    *(char *)(puVar9 + 9) = cVar4;
    *(char *)((int)puVar9 + 0x25) = cVar8;
    *(short *)((int)puVar9 + 0xe) = sVar2;
    *puVar9 = (uint)*ot & 0xffffff | 0x9000000;
    *ot = (ulong *)((uint)puVar9 & 0xffffff);
    p_Var3->nextPrim = puVar9 + 10;
    p_Var3->numPrims = p_Var3->numPrims + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_LoadButton(long *addr /*$s0*/, struct _ButtonTexture *button /*$s1*/)
 // line 3576, offset 0x8002ae84
	/* begin block 1 */
		// Start line: 3577
		// Start offset: 0x8002AE84
		// Variables:
	// 		struct RECT vramRect; // stack offset -32
	// 		long *paletteAddr; // $s3
	// 		short paletteW; // $s2
	// 		short paletteH; // $s4
	/* end block 1 */
	// End offset: 0x8002B000
	// End Line: 3623

	/* begin block 2 */
		// Start line: 4522
	/* end block 2 */
	// End Line: 4523

/* WARNING: Type propagation algorithm not settling */

void DRAW_LoadButton(long *addr,_ButtonTexture *button)

{
  bool bVar1;
  _BlockVramEntry *p_Var2;
  int iVar3;
  long *plVar4;
  short sVar5;
  long *plVar6;
  ushort local_20;
  ushort local_1e;
  short local_1c;
  ushort local_1a;
  
  plVar4 = addr + 2;
  plVar6 = (long *)0x0;
  sVar5 = 0;
  button->xshift = 0;
  bVar1 = addr[1] == 8;
  if (bVar1) {
    button->xshift = 2;
    sVar5 = 0x10;
    plVar6 = addr + 5;
    plVar4 = addr + 0xd;
  }
  button->textureW = *(short *)(plVar4 + 2);
  button->textureH = *(short *)((int)plVar4 + 10);
  local_1c = sVar5;
  if (sVar5 < button->textureW) {
    local_1c = button->textureW;
  }
  iVar3 = (uint)(ushort)button->textureH + (uint)bVar1;
  local_1a = (ushort)iVar3;
  p_Var2 = VRAM_CheckVramSlot((short *)&local_20,(short *)(&local_20 + 1),local_1c,
                              (short)((uint)(iVar3 * 0x10000) >> 0x10),4,-1);
  button->vramBlock = p_Var2;
  button->tpage =
       (ushort)((2 - (uint)*(ushort *)&button->xshift & 3) << 7) | (short)(local_1e & 0x100) >> 4 |
       (ushort)(((uint)local_20 & 0x3ff) >> 6) | (ushort)(((uint)local_1e & 0x200) << 2);
  *(_ButtonTexture **)&button->vramBlock->udata = button;
  local_1c = button->textureW;
  local_1a = button->textureH;
  LoadImage(&local_20,plVar4 + 3);
  if (plVar6 != (long *)0x0) {
    local_1a = (ushort)bVar1;
    local_1e = local_1e + button->textureH;
    local_1c = sVar5;
    LoadImage(&local_20,plVar6);
    button->clut = local_1e << 6 | local_20 >> 4 & 0x3f;
  }
  DrawSync(0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_LoadButtonByName(char *name /*$a0*/, struct _ButtonTexture *button /*$s1*/)
 // line 3626, offset 0x8002b028
	/* begin block 1 */
		// Start line: 3627
		// Start offset: 0x8002B028
		// Variables:
	// 		long *addr; // $s0
	/* end block 1 */
	// End offset: 0x8002B064
	// End Line: 3637

	/* begin block 2 */
		// Start line: 4666
	/* end block 2 */
	// End Line: 4667

void DRAW_LoadButtonByName(char *name,_ButtonTexture *button)

{
  long *addr;
  
  addr = LOAD_ReadFile(name,'\v');
  if (addr != (long *)0x0) {
    DRAW_LoadButton(addr,button);
    MEMPACK_Free((char *)addr);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_FreeButton(struct _ButtonTexture *button /*$a0*/)
 // line 3639, offset 0x8002b078
	/* begin block 1 */
		// Start line: 4695
	/* end block 1 */
	// End Line: 4696

void DRAW_FreeButton(_ButtonTexture *button)

{
  VRAM_ClearVramBlock(button->vramBlock);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_RelocateButtonInVram(struct _ButtonTexture *button /*$a0*/, struct _BlockVramEntry *newBlock /*$a1*/)
 // line 3647, offset 0x8002b09c
	/* begin block 1 */
		// Start line: 4711
	/* end block 1 */
	// End Line: 4712

	/* begin block 2 */
		// Start line: 4714
	/* end block 2 */
	// End Line: 4715

void DRAW_RelocateButtonInVram(_ButtonTexture *button,_BlockVramEntry *newBlock)

{
  button->vramBlock = newBlock;
  button->tpage =
       (ushort)((2 - (uint)*(ushort *)&button->xshift & 3) << 7) |
       (short)(newBlock->y & 0x100U) >> 4 | (ushort)(((uint)(ushort)newBlock->x & 0x3ff) >> 6) |
       (ushort)(((uint)(ushort)newBlock->y & 0x200) << 2);
  button->clut = (newBlock->y + newBlock->h + -1) * 0x40 | (ushort)newBlock->x >> 4 & 0x3f;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_RingLine(struct _PrimPool *primPool /*$t0*/, unsigned long **ot /*$t1*/, long color /*$a2*/)
 // line 3662, offset 0x8002b118
	/* begin block 1 */
		// Start line: 3663
		// Start offset: 0x8002B118
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
	// End offset: 0x8002B240
	// End Line: 3725

	/* begin block 2 */
		// Start line: 4742
	/* end block 2 */
	// End Line: 4743

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
 // line 3727, offset 0x8002b248
	/* begin block 1 */
		// Start line: 3728
		// Start offset: 0x8002B248
		// Variables:
	// 		struct _SVector outpoint; // stack offset -24
	/* end block 1 */
	// End offset: 0x8002B340
	// End Line: 3739

	/* begin block 2 */
		// Start line: 4879
	/* end block 2 */
	// End Line: 4880

void DRAW_RingPoint(_PrimPool *primPool,ulong **ot,long color,_SVector *vel,_SVector *acc)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  _SVector local_18;
  
  uVar1 = rand();
  if (0xe < (uVar1 & 0x3f)) {
    iVar2 = rand();
    vel->x = ((ushort)iVar2 & 0x1f) - 0xf;
    iVar2 = rand();
    vel->y = ((ushort)iVar2 & 0x1f) - 0xf;
    iVar2 = rand();
    vel->z = (ushort)iVar2 & 0xf;
    uVar3 = getCopReg(2,0x4800);
    uVar4 = getCopReg(2,0x5000);
    uVar5 = getCopReg(2,0x5800);
    local_18.x = (short)uVar3;
    local_18.y = (short)uVar4;
    local_18.z = (short)uVar5;
    iVar2 = rand();
    local_18.x = local_18.x + -1 + ((ushort)iVar2 & 3);
    iVar2 = rand();
    local_18.y = local_18.y + -1 + ((ushort)iVar2 & 3);
    iVar2 = rand();
    local_18.z = local_18.z + -1 + ((ushort)iVar2 & 3);
    FX_Dot(&local_18,vel,acc,0,color,4,8,-1);
  }
  return;
}



// decompiled code
// original method signature: 
// unsigned long * /*$ra*/ DRAW_DrawRingPoints(struct _Model *model /*$a0*/, struct _VertexPool *vertexPool /*$a1*/, struct MATRIX *pcTransform /*$s0*/, struct _PrimPool *primPool /*$s5*/, unsigned long **ot /*stack 16*/, long color /*stack 20*/, int ring_type /*stack 24*/)
 // line 3749, offset 0x8002b358
	/* begin block 1 */
		// Start line: 3750
		// Start offset: 0x8002B358
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
	// End offset: 0x8002B640
	// End Line: 3850

	/* begin block 2 */
		// Start line: 4931
	/* end block 2 */
	// End Line: 4932

ulong * DRAW_DrawRingPoints(_Model *model,_VertexPool *vertexPool,MATRIX *pcTransform,
                           _PrimPool *primPool,ulong **ot,long color,int ring_type)

{
  undefined4 in_zero;
  undefined4 in_at;
  int iVar1;
  uint uVar2;
  int iVar3;
  _SVector *pvc;
  _SVector *pvb;
  _SVector *pvb_00;
  ushort *puVar4;
  _MFace *p_Var5;
  _MFace *p_Var6;
  undefined8 uStack80;
  _SVector local_48;
  _SVector local_40;
  _SVector local_38;
  _SVector local_30;
  
  p_Var5 = model->faceList;
  p_Var6 = p_Var5 + model->numFaces;
  if (ring_type == 2) {
    local_38.z = 0;
    local_38.y = 0;
    local_38.x = 0;
    local_30.y = 0;
    local_30.x = 0;
    local_30.z = -1;
  }
  SetRotMatrix((undefined4 *)pcTransform);
  SetTransMatrix((int)pcTransform);
  if (p_Var5 < p_Var6) {
    puVar4 = &(p_Var5->face).v2;
    do {
      if ((*(byte *)((int)puVar4 + 3) & 0x10) != 0) goto switchD_8002b498_caseD_6;
      pvc = (_SVector *)(vertexPool->vertex + (p_Var5->face)._2);
      pvb_00 = (_SVector *)(vertexPool->vertex + puVar4[-1]);
      pvb = (_SVector *)(vertexPool->vertex + *puVar4);
      uVar2 = (uint)~(int)(&pvc->x)[2] >> 0x1f;
      if (-1 < (&pvb_00->x)[2]) {
        uVar2 = uVar2 | 2;
      }
      if (-1 < (&pvb->x)[2]) {
        uVar2 = uVar2 | 4;
      }
      switch(uVar2) {
      case 1:
        fDRAW_SPLIT_INTPL_XYZ(&local_48,pvc,pvb_00);
        fDRAW_SPLIT_INTPL_XYZ(&local_40,pvc,pvb);
        iVar1 = 1;
        iVar3 = 2;
        break;
      case 2:
        fDRAW_SPLIT_INTPL_XYZ((_SVector *)&uStack80,pvb_00,pvc);
        fDRAW_SPLIT_INTPL_XYZ(&local_40,pvb_00,pvb);
        iVar1 = 2;
        iVar3 = 0;
        pvc = pvb_00;
        break;
      case 3:
        fDRAW_SPLIT_INTPL_XYZ(&local_48,pvb_00,pvb);
        fDRAW_SPLIT_INTPL_XYZ((_SVector *)&uStack80,pvc,pvb);
        iVar1 = 1;
        iVar3 = 0;
        break;
      case 4:
        fDRAW_SPLIT_INTPL_XYZ((_SVector *)&uStack80,pvb,pvc);
        fDRAW_SPLIT_INTPL_XYZ(&local_48,pvb,pvb_00);
        iVar1 = 0;
        goto LAB_8002b59c;
      case 5:
        fDRAW_SPLIT_INTPL_XYZ((_SVector *)&uStack80,pvc,pvb_00);
        fDRAW_SPLIT_INTPL_XYZ(&local_40,pvb,pvb_00);
        iVar1 = 0;
        iVar3 = 2;
        pvc = pvb;
        break;
      case 6:
        fDRAW_SPLIT_INTPL_XYZ(&local_40,pvb,pvc);
        fDRAW_SPLIT_INTPL_XYZ(&local_48,pvb_00,pvc);
        iVar1 = 2;
        pvb = pvb_00;
LAB_8002b59c:
        iVar3 = 1;
        pvc = pvb;
        break;
      default:
        goto switchD_8002b498_caseD_6;
      }
      if (ring_type == 2) {
        setCopReg(2,in_zero,*(undefined4 *)((_SVector *)&uStack80 + iVar1));
        setCopReg(2,in_at,*(undefined4 *)((int)&uStack80 + iVar1 * 8 + 4));
        copFunction(2,0x480012);
        DRAW_RingPoint(primPool,ot,color,&local_38,&local_30);
      }
      else {
        pvb_00 = (_SVector *)&uStack80 + iVar1;
        pvb = (_SVector *)&uStack80 + iVar3;
        setCopReg(2,in_zero,*(undefined4 *)pvb_00);
        setCopReg(2,in_at,*(undefined4 *)((int)&uStack80 + iVar1 * 8 + 4));
        setCopReg(2,pvb,*(undefined4 *)pvb);
        setCopReg(2,pvb_00,*(undefined4 *)((int)&uStack80 + iVar3 * 8 + 4));
        setCopReg(2,iVar3,*(undefined4 *)pvb_00);
        setCopReg(2,pvc,*(undefined4 *)((int)&uStack80 + iVar1 * 8 + 4));
        copFunction(2,0x280030);
        DRAW_RingLine(primPool,ot,color);
      }
switchD_8002b498_caseD_6:
      puVar4 = puVar4 + 6;
      p_Var5 = p_Var5 + 1;
    } while (p_Var5 < p_Var6);
  }
  return primPool->nextPrim;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_GlowQuad(struct _PrimPool *primPool /*$t7*/, unsigned long **ot /*$t9*/, long otz /*$a2*/, long color /*stack 12*/, struct _Vector *v0 /*stack 16*/, struct _Vector *v1 /*stack 20*/, struct _Vector *v2 /*stack 24*/, struct _Vector *v3 /*stack 28*/)
 // line 3892, offset 0x8002b674
	/* begin block 1 */
		// Start line: 3893
		// Start offset: 0x8002B674
		// Variables:
	// 		unsigned long *prim; // $t1
	// 		struct _POLY_NG4 *sg4; // $t0
	/* end block 1 */
	// End offset: 0x8002B8D0
	// End Line: 3935

	/* begin block 2 */
		// Start line: 7770
	/* end block 2 */
	// End Line: 7771

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
 // line 3948, offset 0x8002b8d8
	/* begin block 1 */
		// Start line: 3949
		// Start offset: 0x8002B8D8
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
			// Start line: 3962
			// Start offset: 0x8002B93C
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
		// End offset: 0x8002B93C
		// End Line: 3962

		/* begin block 1.2 */
			// Start line: 3962
			// Start offset: 0x8002B93C
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $v1
		// 		long _z0; // $t3
		// 		long _y1; // $s4
		// 		long _z1; // $s5
		// 		struct _Vector *_v1; // $s2
		/* end block 1.2 */
		// End offset: 0x8002B93C
		// End Line: 3962

		/* begin block 1.3 */
			// Start line: 3962
			// Start offset: 0x8002B93C
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $v1
		// 		long _z0; // $t3
		// 		long _x1; // $a0
		// 		long _y1; // $a0
		// 		long _z1; // $a1
		/* end block 1.3 */
		// End offset: 0x8002B93C
		// End Line: 3962

		/* begin block 1.4 */
			// Start line: 3962
			// Start offset: 0x8002B93C
			// Variables:
		// 		long _x0; // $v1
		// 		long _y0; // $a0
		// 		long _z0; // $t2
		// 		struct _Vector *_v; // $t4
		/* end block 1.4 */
		// End offset: 0x8002B93C
		// End Line: 3962

		/* begin block 1.5 */
			// Start line: 3962
			// Start offset: 0x8002B93C
			// Variables:
		// 		long _x0; // $v1
		// 		long _y0; // $a0
		// 		long _z0; // $t2
		/* end block 1.5 */
		// End offset: 0x8002B93C
		// End Line: 3962

		/* begin block 1.6 */
			// Start line: 3962
			// Start offset: 0x8002B93C
			// Variables:
		// 		long _x0; // $v1
		// 		long _y0; // $a0
		// 		long _z0; // $t2
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $a1
		/* end block 1.6 */
		// End offset: 0x8002B93C
		// End Line: 3962

		/* begin block 1.7 */
			// Start line: 3962
			// Start offset: 0x8002B93C
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $v1
		// 		long _z0; // $t0
		// 		long _y1; // $t1
		// 		struct _Vector *_v; // $t3
		/* end block 1.7 */
		// End offset: 0x8002B93C
		// End Line: 3962

		/* begin block 1.8 */
			// Start line: 3962
			// Start offset: 0x8002B93C
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $v1
		// 		long _z0; // $t0
		// 		struct _Vector *_v; // $s6
		/* end block 1.8 */
		// End offset: 0x8002B93C
		// End Line: 3962

		/* begin block 1.9 */
			// Start line: 3962
			// Start offset: 0x8002B93C
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $v1
		// 		long _z0; // $t0
		// 		long _y1; // $t1
		// 		struct _Vector *_v; // stack offset -52
		/* end block 1.9 */
		// End offset: 0x8002B93C
		// End Line: 3962

		/* begin block 1.10 */
			// Start line: 3962
			// Start offset: 0x8002B93C
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $v1
		// 		long _z0; // $t0
		// 		struct _Vector *_v; // $s4
		/* end block 1.10 */
		// End offset: 0x8002B93C
		// End Line: 3962

		/* begin block 1.11 */
			// Start line: 3962
			// Start offset: 0x8002B93C
			// Variables:
		// 		long _x0; // $t0
		// 		long _y0; // $t2
		// 		long _z0; // $t1
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $v1
		// 		struct _Vector *_v; // $s5
		/* end block 1.11 */
		// End offset: 0x8002B93C
		// End Line: 3962

		/* begin block 1.12 */
			// Start line: 3962
			// Start offset: 0x8002B93C
			// Variables:
		// 		long _x0; // $t0
		// 		long _y0; // $t2
		// 		long _z0; // $t1
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $v1
		// 		struct _Vector *_v; // $s3
		/* end block 1.12 */
		// End offset: 0x8002B93C
		// End Line: 3962

		/* begin block 1.13 */
			// Start line: 3962
			// Start offset: 0x8002B93C
			// Variables:
		// 		long _x0; // $t0
		// 		long _y0; // $t2
		// 		long _z0; // $t1
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $v1
		// 		struct _Vector *_v; // $s2
		/* end block 1.13 */
		// End offset: 0x8002B93C
		// End Line: 3962

		/* begin block 1.14 */
			// Start line: 3962
			// Start offset: 0x8002B93C
			// Variables:
		// 		long _x0; // $t0
		// 		long _y0; // $t2
		// 		long _z0; // $t1
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $v1
		// 		struct _Vector *_v; // $s1
		/* end block 1.14 */
		// End offset: 0x8002B93C
		// End Line: 3962
	/* end block 1 */
	// End offset: 0x8002BE54
	// End Line: 4041

	/* begin block 2 */
		// Start line: 5299
	/* end block 2 */
	// End Line: 5300

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void DRAW_CreateAGlowingCircle
               (_Vector *f1,long z,_PrimPool *primPool,ulong **ot,long otz,long color,long w,long h,
               long angle)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_b8;
  int local_b4;
  int local_b0;
  _Vector local_a8;
  _Vector local_9c;
  _Vector local_90;
  _Vector local_84;
  _Vector local_78;
  _Vector local_6c;
  _Vector local_60;
  _Vector local_54;
  _Vector local_48;
  _Vector *local_34;
  int *local_30;
  
  f1->z = 0;
  if ((0 < z) && (otz < 0xc00)) {
    local_d8 = 0;
    local_d0 = 0;
    local_d4 = -((h * 0x140) / z);
    iVar1 = rcos(angle);
    iVar2 = rsin(angle);
    iVar1 = iVar1 * local_d8;
    iVar2 = iVar2 * local_d4;
    iVar3 = rsin(angle);
    iVar4 = rcos(angle);
    iVar5 = -iVar3 * local_d8;
    iVar3 = -((w * 0x140) / z);
    local_d8 = ((iVar1 + iVar2 >> 0xc) * 0x200) / 0xf0;
    local_d4 = iVar5 + iVar4 * local_d4 >> 0xc;
    iVar1 = rcos(angle);
    rsin(angle);
    iVar2 = rsin(angle);
    rcos(angle);
    local_30 = &local_d8;
    local_6c.x = ((iVar1 * iVar3 >> 0xc) * 0x200) / 0xf0;
    local_6c.y = -iVar2 * iVar3 >> 0xc;
    local_c0 = (f1->z + local_d0) - f1->z;
    local_c8 = ((f1->x + local_d8 + local_6c.x) - f1->x) * 0xc00 >> 0xc;
    local_c4 = ((f1->y + local_d4 + local_6c.y) - f1->y) * 0xc00 >> 0xc;
    local_b0 = (f1->z + local_d0) - f1->z;
    local_b8 = (((f1->x + local_d8) - local_6c.x) - f1->x) * 0xc00 >> 0xc;
    local_34 = &local_90;
    local_b4 = (((f1->y + local_d4) - local_6c.y) - f1->y) * 0xc00 >> 0xc;
    local_a8.x = f1->x + local_c8;
    local_a8.y = f1->y + local_c4;
    local_9c.x = f1->x + local_d8;
    local_9c.y = f1->y + local_d4;
    local_90.x = f1->x + local_b8;
    local_90.y = f1->y + local_b4;
    local_84.x = f1->x + local_6c.x;
    local_84.y = f1->y + local_6c.y;
    local_78.x = f1->x;
    local_78.y = f1->y;
    local_6c.x = f1->x - local_6c.x;
    local_6c.y = f1->y - local_6c.y;
    local_60.x = f1->x - local_b8;
    local_60.y = f1->y - local_b4;
    local_54.x = f1->x - local_d8;
    local_54.y = f1->y - local_d4;
    local_48.x = f1->x - local_c8;
    local_48.y = f1->y - local_c4;
    local_a8.z = 0x1000;
    local_9c.z = 0x1000;
    local_90.z = 0x1000;
    local_84.z = 0x1000;
    local_78.z = 0;
    local_6c.z = 0x1000;
    local_60.z = 0x1000;
    local_54.z = 0x1000;
    local_48.z = 0x1000;
    DRAW_GlowQuad(primPool,ot,otz,color,&local_84,&local_a8,&local_78,&local_9c);
    DRAW_GlowQuad(primPool,ot,otz,color,&local_84,&local_78,&local_60,&local_54);
    DRAW_GlowQuad(primPool,ot,otz,color,&local_9c,local_34,&local_78,&local_6c);
    DRAW_GlowQuad(primPool,ot,otz,color,&local_54,&local_78,&local_48,&local_6c);
  }
  return;
}



// decompiled code
// original method signature: 
// unsigned long * /*$ra*/ DRAW_DrawGlowPoints2(struct _Instance *instance /*$s0*/, long seg1 /*$a1*/, long seg2 /*$s1*/, struct _PrimPool *primPool /*$s3*/, unsigned long **ot /*stack 16*/, long color /*stack 20*/, long height /*stack 24*/)
 // line 4051, offset 0x8002be84
	/* begin block 1 */
		// Start line: 4052
		// Start offset: 0x8002BE84
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
	// End offset: 0x8002BFD0
	// End Line: 4092

	/* begin block 2 */
		// Start line: 5624
	/* end block 2 */
	// End Line: 5625

ulong * DRAW_DrawGlowPoints2
                  (_Instance *instance,long seg1,long seg2,_PrimPool *primPool,ulong **ot,long color
                  ,long height)

{
  long lVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  _Position local_58;
  _Position local_50;
  int local_48;
  int local_44;
  int local_38;
  int local_34;
  _Vector local_28;
  
  lVar1 = PIPE3D_Segment2ScreenPt(instance,(MATRIX *)theCamera.core.wcTransform,seg1,&local_58);
  lVar2 = PIPE3D_Segment2ScreenPt(instance,(MATRIX *)theCamera.core.wcTransform,seg2,&local_50);
  iVar5 = lVar2 + 0x14;
  iVar6 = lVar1 + 0x14;
  if (lVar1 + 0x14 < iVar5) {
    iVar6 = iVar5;
  }
  if (0 < iVar6) {
    local_48 = (int)local_58.x;
    local_38 = (int)local_50.x;
    local_44 = (int)local_58.y;
    local_34 = (int)local_50.y;
    local_28.x = local_38 - local_48;
    local_28.y = local_34 - local_44;
    iVar3 = MATH3D_veclen2(local_28.x,local_28.y);
    uVar4 = ratan2(local_28.y,-local_28.x);
    local_28.z = 0;
    local_28.x = (local_38 + local_48) / 2;
    local_28.y = (local_34 + local_44) / 2;
    if (iVar6 + 10 < 0xc00) {
      DRAW_CreateAGlowingCircle
                (&local_28,(iVar6 + iVar5) / 2 << 2,primPool,ot,iVar6 + 10,color,iVar3 + height,
                 height,uVar4 & 0xfff);
    }
  }
  return primPool->nextPrim;
}



// decompiled code
// original method signature: 
// unsigned long * /*$ra*/ DRAW_DrawGlowPoint(struct _Instance *instance /*$a0*/, long seg1 /*$a1*/, struct _PrimPool *primPool /*$s3*/, unsigned long **ot /*$s4*/, long color /*stack 16*/, int width /*stack 20*/, int height /*stack 24*/)
 // line 4102, offset 0x8002bff0
	/* begin block 1 */
		// Start line: 4103
		// Start offset: 0x8002BFF0
		// Variables:
	// 		struct _Position glowPoints1; // stack offset -48
	// 		struct _Vector f1; // stack offset -40
	// 		long otz; // $t0
	// 		long z; // $a1
	// 		long angle; // $s2
	/* end block 1 */
	// End offset: 0x8002C09C
	// End Line: 4128

	/* begin block 2 */
		// Start line: 5772
	/* end block 2 */
	// End Line: 5773

ulong * DRAW_DrawGlowPoint(_Instance *instance,long seg1,_PrimPool *primPool,ulong **ot,long color,
                          int width,int height)

{
  uint uVar1;
  long lVar2;
  int z;
  _Position local_30;
  _Vector local_28;
  
  uVar1 = gameTrackerX.globalTimeMult & 0x7ff;
  lVar2 = PIPE3D_Segment2ScreenPt(instance,(MATRIX *)theCamera.core.wcTransform,seg1,&local_30);
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
 // line 4205, offset 0x8002c0c0
	/* begin block 1 */
		// Start line: 4206
		// Start offset: 0x8002C0C0
		// Variables:
	// 		struct SP_SUBDIV_STRUCT *sp; // $t2
	// 		int maxz; // $s3
	// 		int point; // $a1
	// 		int n; // $t7
	// 		struct POLY_GT4 *prim; // $t9
	// 		long *ptr; // $t8
	// 		long clip; // $s0

		/* begin block 1.1 */
			// Start line: 4246
			// Start offset: 0x8002C230
			// Variables:
		// 		int next_point_in_vv; // $v1
		// 		int current_point_in_vv; // $t1
		// 		int next; // $t6

			/* begin block 1.1.1 */
				// Start line: 4259
				// Start offset: 0x8002C270
				// Variables:
			// 		long clip_tmp; // $a0
			// 		long zval; // stack offset -48
			// 		struct SVECTOR *tmpptr; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8002C354
			// End Line: 4285

			/* begin block 1.1.2 */
				// Start line: 4289
				// Start offset: 0x8002C35C
				// Variables:
			// 		long zn; // $v1
			// 		long znext; // $a0
			// 		long interp1; // $t1
			// 		long interp2; // $a2
			// 		long clip_tmp; // $v1

				/* begin block 1.1.2.1 */
					// Start line: 4293
					// Start offset: 0x8002C35C
					// Variables:
				// 		long x; // $v1
				// 		long y; // $v1
				/* end block 1.1.2.1 */
				// End offset: 0x8002C440
				// End Line: 4304
			/* end block 1.1.2 */
			// End offset: 0x8002C578
			// End Line: 4318
		/* end block 1.1 */
		// End offset: 0x8002C578
		// End Line: 4319

		/* begin block 1.2 */
			// Start line: 4340
			// Start offset: 0x8002C5B8
			// Variables:
		// 		int next; // $t0
		// 		int flag; // $t3
		/* end block 1.2 */
		// End offset: 0x8002C790
		// End Line: 4371

		/* begin block 1.3 */
			// Start line: 4374
			// Start offset: 0x8002C790
			// Variables:
		// 		long opz; // stack offset -44
		/* end block 1.3 */
		// End offset: 0x8002C7E4
		// End Line: 4389

		/* begin block 1.4 */
			// Start line: 4400
			// Start offset: 0x8002C844
			// Variables:
		// 		long temp1; // $a3
		// 		long temp2; // $t0
		// 		long temp3; // $t1
		/* end block 1.4 */
		// End offset: 0x8002C84C
		// End Line: 4421
	/* end block 1 */
	// End offset: 0x8002C8D0
	// End Line: 4422

	/* begin block 2 */
		// Start line: 8394
	/* end block 2 */
	// End Line: 8395

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
LAB_8002c644:
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
          if ((int)pSVar4 >= 0x200) goto LAB_8002c644;
          puVar15 = puVar15 + 1;
          iVar19 = iVar21 + 1;
          uVar22 = (uint)(iVar19 < iVar9);
          iVar24 = iVar21 + 2;
          iVar21 = iVar19;
        } while (iVar19 < iVar9);
      }
      if (bVar1) goto LAB_8002c6f8;
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
          if ((int)pSVar4 < 0x200) goto LAB_8002c6f0;
        }
        bVar1 = true;
      }
LAB_8002c6f0:
      if (bVar1) {
LAB_8002c6f8:
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
      if (iVar9 != 4) goto LAB_8002c844;
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
LAB_8002c844:
    iVar25 = 2;
  }
  return iVar25;
}



// decompiled code
// original method signature: 
// long * /*$ra*/ DRAW_Zclip_subdiv(struct POLY_GT3 *texture /*$t0*/, unsigned long **ot /*stack 4*/, int ndiv /*stack 8*/)
 // line 4433, offset 0x8002c900
	/* begin block 1 */
		// Start line: 4434
		// Start offset: 0x8002C900
		// Variables:
	// 		struct SP_SUBDIV_STRUCT *sp; // $s7
	// 		struct _PrimPool *primPool; // $fp
	// 		int clip; // $s0
	/* end block 1 */
	// End offset: 0x8002CDD4
	// End Line: 4569

	/* begin block 2 */
		// Start line: 6607
	/* end block 2 */
	// End Line: 6608

long * DRAW_Zclip_subdiv(POLY_GT3 *texture,ulong **ot,int ndiv)

{
  undefined4 uVar1;
  _PrimPool *primPool;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ulong *puVar6;
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
  primPool = gameTrackerX.primPool;
  *(POLY_GT3 **)&(gameTrackerX.primPool)->nextPrim = texture;
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
                     ,puVar7[0x18],puVar7[0x1b],puVar7[0x1d],primPool,ot,ndiv);
  uv1 = (UVTYPE *)(puVar7 + 0x16);
  vertex1 = (SVECTOR *)(puVar7 + 0xe);
  uVar3 = DRAW_DisplayTFace_zclipped_C
                    (vertex2,vertex1,(SVECTOR *)((uint)puVar7 | 0x28),uv2,uv1,
                     (UVTYPE *)(puVar7 + 0x14),puVar7[0x1d],puVar7[0x1c],puVar7[0x1a],primPool,ot,
                     ndiv);
  *(undefined2 *)((int)puVar7 + 0x56) = *(undefined2 *)((int)puVar7 + 0x4a);
  *(undefined2 *)((int)puVar7 + 0x5e) = *(undefined2 *)((int)puVar7 + 0x4e);
  uVar4 = DRAW_DisplayTFace_zclipped_C
                    (vertex1_00,vertex1,vertex2,uv1_00,uv1,uv2,puVar7[0x1b],puVar7[0x1c],
                     puVar7[0x1d],primPool,ot,ndiv);
  uVar5 = DRAW_DisplayTFace_zclipped_C
                    (vertex1_00,(SVECTOR *)((uint)puVar7 | 0x20),vertex1,uv1_00,
                     (UVTYPE *)(puVar7 + 0x13),uv1,puVar7[0x1b],puVar7[0x19],puVar7[0x1c],primPool,
                     ot,ndiv);
  puVar6 = (ulong *)0x0;
  if (((uVar2 | uVar3 | uVar4 | uVar5) & 5) != 4) {
    puVar6 = primPool->nextPrim;
  }
  return (long *)puVar6;
}





