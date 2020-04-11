
#include "DRAW.H"


// decompiled code
// original method signature: 
// void /*$ra*/ fDRAW_SPLIT_INTPL_XYZ(struct _SVector *newVertex /*$a0*/, struct _SVector *pvb /*$a1*/, struct _SVector *pvc /*$a2*/)
 // line 61, offset 0x8002a478
	/* begin block 1 */
		// Start line: 122
	/* end block 1 */
	// End Line: 123

	/* begin block 2 */
		// Start line: 123
	/* end block 2 */
	// End Line: 124

/* File: C:\kain2\game\DRAW.C */

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
 // line 454, offset 0x8002a4f4
	/* begin block 1 */
		// Start line: 455
		// Start offset: 0x8002A4F4
		// Variables:
	// 		int n; // $s3
	// 		int inc; // $s4
	// 		int deg; // $s2
	/* end block 1 */
	// End offset: 0x8002A588
	// End Line: 468

	/* begin block 2 */
		// Start line: 519
	/* end block 2 */
	// End Line: 520

	/* begin block 3 */
		// Start line: 909
	/* end block 3 */
	// End Line: 910

/* File: C:\kain2\game\DRAW.C */

void DRAW_InitShadow(void)

{
  int iVar1;
  int iVar2;
  SVECTOR *pSVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  iVar5 = 0;
  pSVar3 = shadow_vertices;
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
  shadow_vertices[10].vx = shadow_vertices[0].vx;
  shadow_vertices[10].vy = shadow_vertices[0].vy;
  shadow_vertices[10].vz = shadow_vertices[0].vz;
  return;
}



// decompiled code
// original method signature: 
// unsigned long * /*$ra*/ DRAW_DrawShadow(struct _PrimPool *primPool /*$t3*/, struct _Model *model /*$a1*/, unsigned long **ot /*$a2*/, long fadeValue /*$a3*/)
 // line 478, offset 0x8002a5c0
	/* begin block 1 */
		// Start line: 479
		// Start offset: 0x8002A5C0
		// Variables:
	// 		struct POLY_G3_SEMITRANS *sg3; // $a1
	// 		struct SVECTOR zero_vertex; // stack offset -24
	// 		long clip; // stack offset -8
	// 		long n; // $t0
	// 		long p; // stack offset -16
	// 		long otz; // stack offset -4
	// 		unsigned long color; // stack offset -12
	/* end block 1 */
	// End offset: 0x8002A780
	// End Line: 538

	/* begin block 2 */
		// Start line: 983
	/* end block 2 */
	// End Line: 984

/* File: C:\kain2\game\DRAW.C */

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
  pSVar10 = shadow_vertices;
  puVar8 = puVar7 + 1;
  uVar5 = uVar1 | 0x32000000;
  p_Var6 = primPool;
  do {
    setCopReg(2,uVar5,*(undefined4 *)pSVar10);
    setCopReg(2,iVar9 * 8,*(undefined4 *)&pSVar10->vz);
    setCopReg(2,p_Var6,*(undefined4 *)(shadow_vertices + iVar9 + 1));
    setCopReg(2,puVar7,*(undefined4 *)&shadow_vertices[iVar9 + 1].vz);
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
// void /*$ra*/ DRAW_FlatQuad(struct CVECTOR *color /*$a0*/, short x0 /*$a1*/, short y0 /*$a2*/, short x1 /*$a3*/, int y1 /*stack 16*/, int x2 /*stack 20*/, int y2 /*stack 24*/, int x3 /*stack 28*/, int y3 /*stack 32*/, struct _PrimPool *primPool /*stack 36*/, unsigned long **ot /*stack 40*/)
 // line 3208, offset 0x8002a788
	/* begin block 1 */
		// Start line: 3209
		// Start offset: 0x8002A788
		// Variables:
	// 		unsigned long *prim; // $t0
	/* end block 1 */
	// End offset: 0x8002A828
	// End Line: 3228

	/* begin block 2 */
		// Start line: 6223
	/* end block 2 */
	// End Line: 6224

/* File: C:\kain2\game\DRAW.C */

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
 // line 3245, offset 0x8002a830
	/* begin block 1 */
		// Start line: 3246
		// Start offset: 0x8002A830
		// Variables:
	// 		unsigned long *prim; // $t0
	/* end block 1 */
	// End offset: 0x8002A904
	// End Line: 3272

	/* begin block 2 */
		// Start line: 3914
	/* end block 2 */
	// End Line: 3915

/* File: C:\kain2\game\DRAW.C */

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
 // line 3515, offset 0x8002a914
	/* begin block 1 */
		// Start line: 3516
		// Start offset: 0x8002A914
		// Variables:
	// 		struct _PrimPool *primPool; // $fp
	// 		unsigned long *prim; // $s4
	// 		short w; // $s0
	// 		short h; // $s3
	// 		short offsetx; // $s2
	// 		short offsety; // $s1
	/* end block 1 */
	// End offset: 0x8002AA44
	// End Line: 3567

	/* begin block 2 */
		// Start line: 6940
	/* end block 2 */
	// End Line: 6941

/* File: C:\kain2\game\DRAW.C */

void DRAW_DrawButton(_ButtonTexture *button,short x,short y,ulong **ot)

{
  short sVar1;
  ushort uVar2;
  u_short uVar3;
  u_char uVar4;
  int *piVar5;
  short sVar6;
  uint uVar7;
  short sVar8;
  u_char uVar9;
  int iVar10;
  u_char uVar11;
  POLY_FT4 *p;
  
  piVar5 = DAT_800d210c;
  p = (POLY_FT4 *)DAT_800d210c[1];
  if (p <= (POLY_FT4 *)(DAT_800d210c[2] - 0x30U)) {
    uVar7 = button->xshift;
    sVar1 = button->textureH;
    iVar10 = (int)button->textureW << (uVar7 & 0x1f);
    uVar2 = button->vramBlock->x;
    uVar11 = *(u_char *)&button->vramBlock->y;
    SetPolyFT4(p);
    sVar8 = x + (short)iVar10;
    uVar4 = (u_char)(((uint)uVar2 & 0x3f) << (uVar7 & 0x1f));
    p->code = p->code | 1;
    uVar9 = uVar4 + (char)iVar10 + -1;
    p->tpage = button->tpage;
    uVar3 = button->clut;
    sVar6 = y + sVar1;
    p->v0 = uVar11;
    p->v1 = uVar11;
    uVar11 = uVar11 + (char)sVar1 + -1;
    p->x0 = x;
    p->y0 = y;
    p->u0 = uVar4;
    p->x1 = sVar8;
    p->y1 = y;
    p->u1 = uVar9;
    p->x2 = x;
    p->y2 = sVar6;
    p->u2 = uVar4;
    p->v2 = uVar11;
    p->x3 = sVar8;
    p->y3 = sVar6;
    p->u3 = uVar9;
    p->v3 = uVar11;
    p->clut = uVar3;
    p->tag = (uint)*ot & 0xffffff | 0x9000000;
    *ot = (ulong *)((uint)p & 0xffffff);
    *(POLY_FT4 **)(piVar5 + 1) = p + 1;
    *piVar5 = *piVar5 + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_LoadButton(long *addr /*$s0*/, struct _ButtonTexture *button /*$s1*/)
 // line 3573, offset 0x8002aa74
	/* begin block 1 */
		// Start line: 3574
		// Start offset: 0x8002AA74
		// Variables:
	// 		struct RECT vramRect; // stack offset -32
	// 		long *paletteAddr; // $s3
	// 		short paletteW; // $s2
	// 		short paletteH; // $s4
	/* end block 1 */
	// End offset: 0x8002ABEC
	// End Line: 3620

	/* begin block 2 */
		// Start line: 4460
	/* end block 2 */
	// End Line: 4461

/* File: C:\kain2\game\DRAW.C */

void DRAW_LoadButton(long *addr,_ButtonTexture *button)

{
  bool bVar1;
  _BlockVramEntry *p_Var2;
  int iVar3;
  long *plVar4;
  short sVar5;
  u_long *p;
  RECT local_20;
  
  plVar4 = addr + 2;
  p = (u_long *)0x0;
  sVar5 = 0;
  button->xshift = 0;
  bVar1 = addr[1] == 8;
  if (bVar1) {
    button->xshift = 2;
    sVar5 = 0x10;
    p = (u_long *)(addr + 5);
    plVar4 = addr + 0xd;
  }
  button->textureW = *(short *)(plVar4 + 2);
  button->textureH = *(short *)((int)plVar4 + 10);
  local_20.w = sVar5;
  if (sVar5 < button->textureW) {
    local_20.w = button->textureW;
  }
  iVar3 = (uint)(ushort)button->textureH + (uint)bVar1;
  local_20.h = (ushort)iVar3;
  p_Var2 = VRAM_CheckVramSlot((short *)&local_20,&local_20.y,local_20.w,
                              (short)((uint)(iVar3 * 0x10000) >> 0x10),4,0);
  button->vramBlock = p_Var2;
  button->tpage =
       (ushort)((2 - (uint)*(ushort *)&button->xshift & 3) << 7) | (short)(local_20.y & 0x100) >> 4
       | (ushort)(((uint)local_20.x & 0x3ff) >> 6) | (ushort)(((uint)local_20.y & 0x200) << 2);
  *(_ButtonTexture **)&button->vramBlock->udata = button;
  local_20.w = button->textureW;
  local_20.h = button->textureH;
  LoadImage(&local_20,(u_long *)(plVar4 + 3));
  if (p != (u_long *)0x0) {
    local_20.h = (ushort)bVar1;
    local_20.y = local_20.y + button->textureH;
    local_20.w = sVar5;
    LoadImage(&local_20,p);
    button->clut = local_20.y << 6 | local_20.x >> 4 & 0x3f;
  }
  DrawSync(0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_LoadButtonByName(char *name /*$a0*/, struct _ButtonTexture *button /*$s1*/)
 // line 3623, offset 0x8002ac14
	/* begin block 1 */
		// Start line: 3624
		// Start offset: 0x8002AC14
		// Variables:
	// 		long *addr; // $s0
	/* end block 1 */
	// End offset: 0x8002AC50
	// End Line: 3634

	/* begin block 2 */
		// Start line: 4604
	/* end block 2 */
	// End Line: 4605

/* File: C:\kain2\game\DRAW.C */

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
 // line 3636, offset 0x8002ac64
	/* begin block 1 */
		// Start line: 4633
	/* end block 1 */
	// End Line: 4634

/* File: C:\kain2\game\DRAW.C */

void DRAW_FreeButton(_ButtonTexture *button)

{
  VRAM_ClearVramBlock(button->vramBlock);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_RingLine(struct _PrimPool *primPool /*$t0*/, unsigned long **ot /*$t1*/, long color /*$a2*/)
 // line 3649, offset 0x8002ac88
	/* begin block 1 */
		// Start line: 3650
		// Start offset: 0x8002AC88
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
	// End offset: 0x8002ADB0
	// End Line: 3712

	/* begin block 2 */
		// Start line: 4659
	/* end block 2 */
	// End Line: 4660

/* File: C:\kain2\game\DRAW.C */

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
 // line 3714, offset 0x8002adb8
	/* begin block 1 */
		// Start line: 3715
		// Start offset: 0x8002ADB8
		// Variables:
	// 		struct _SVector outpoint; // stack offset -24
	/* end block 1 */
	// End offset: 0x8002AEB0
	// End Line: 3726

	/* begin block 2 */
		// Start line: 4796
	/* end block 2 */
	// End Line: 4797

/* File: C:\kain2\game\DRAW.C */

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
 // line 3736, offset 0x8002aec8
	/* begin block 1 */
		// Start line: 3737
		// Start offset: 0x8002AEC8
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
	// End offset: 0x8002B1B0
	// End Line: 3837

	/* begin block 2 */
		// Start line: 4848
	/* end block 2 */
	// End Line: 4849

/* File: C:\kain2\game\DRAW.C */

ulong * DRAW_DrawRingPoints(_Model *model,_VertexPool *vertexPool,undefined pcTransform,
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
  undefined3 in_register_00000019;
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
  SetRotMatrix((MATRIX *)CONCAT31(in_register_00000019,pcTransform));
  SetTransMatrix((MATRIX *)CONCAT31(in_register_00000019,pcTransform));
  if (p_Var5 < p_Var6) {
    puVar4 = &(p_Var5->face).v2;
    do {
      if ((*(byte *)((int)puVar4 + 3) & 0x10) != 0) goto switchD_8002b008_caseD_6;
      pvc = (_SVector *)(vertexPool->vertex + (p_Var5->face).v0);
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
        goto LAB_8002b10c;
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
LAB_8002b10c:
        iVar3 = 1;
        pvc = pvb;
        break;
      default:
        goto switchD_8002b008_caseD_6;
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
switchD_8002b008_caseD_6:
      puVar4 = puVar4 + 6;
      p_Var5 = p_Var5 + 1;
    } while (p_Var5 < p_Var6);
  }
  return primPool->nextPrim;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_GlowQuad(struct _PrimPool *primPool /*$t7*/, unsigned long **ot /*$t9*/, long otz /*$a2*/, long color /*stack 12*/, struct _Vector *v0 /*stack 16*/, struct _Vector *v1 /*stack 20*/, struct _Vector *v2 /*stack 24*/, struct _Vector *v3 /*stack 28*/)
 // line 3879, offset 0x8002b1e4
	/* begin block 1 */
		// Start line: 3880
		// Start offset: 0x8002B1E4
		// Variables:
	// 		unsigned long *prim; // $t1
	// 		struct _POLY_NG4 *sg4; // $t0
	/* end block 1 */
	// End offset: 0x8002B440
	// End Line: 3922

	/* begin block 2 */
		// Start line: 7744
	/* end block 2 */
	// End Line: 7745

/* WARNING: Could not reconcile some variable overlaps */
/* File: C:\kain2\game\DRAW.C */

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
 // line 3935, offset 0x8002b448
	/* begin block 1 */
		// Start line: 3936
		// Start offset: 0x8002B448
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
			// Start offset: 0x8002B4AC
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
		// End offset: 0x8002B4AC
		// End Line: 3949

		/* begin block 1.2 */
			// Start line: 3949
			// Start offset: 0x8002B4AC
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $v1
		// 		long _z0; // $t3
		// 		long _y1; // $s4
		// 		long _z1; // $s5
		// 		struct _Vector *_v1; // $s2
		/* end block 1.2 */
		// End offset: 0x8002B4AC
		// End Line: 3949

		/* begin block 1.3 */
			// Start line: 3949
			// Start offset: 0x8002B4AC
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $v1
		// 		long _z0; // $t3
		// 		long _x1; // $a0
		// 		long _y1; // $a0
		// 		long _z1; // $a1
		/* end block 1.3 */
		// End offset: 0x8002B4AC
		// End Line: 3949

		/* begin block 1.4 */
			// Start line: 3949
			// Start offset: 0x8002B4AC
			// Variables:
		// 		long _x0; // $v1
		// 		long _y0; // $a0
		// 		long _z0; // $t2
		// 		struct _Vector *_v; // $t4
		/* end block 1.4 */
		// End offset: 0x8002B4AC
		// End Line: 3949

		/* begin block 1.5 */
			// Start line: 3949
			// Start offset: 0x8002B4AC
			// Variables:
		// 		long _x0; // $v1
		// 		long _y0; // $a0
		// 		long _z0; // $t2
		/* end block 1.5 */
		// End offset: 0x8002B4AC
		// End Line: 3949

		/* begin block 1.6 */
			// Start line: 3949
			// Start offset: 0x8002B4AC
			// Variables:
		// 		long _x0; // $v1
		// 		long _y0; // $a0
		// 		long _z0; // $t2
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $a1
		/* end block 1.6 */
		// End offset: 0x8002B4AC
		// End Line: 3949

		/* begin block 1.7 */
			// Start line: 3949
			// Start offset: 0x8002B4AC
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $v1
		// 		long _z0; // $t0
		// 		long _y1; // $t1
		// 		struct _Vector *_v; // $t3
		/* end block 1.7 */
		// End offset: 0x8002B4AC
		// End Line: 3949

		/* begin block 1.8 */
			// Start line: 3949
			// Start offset: 0x8002B4AC
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $v1
		// 		long _z0; // $t0
		// 		struct _Vector *_v; // $s6
		/* end block 1.8 */
		// End offset: 0x8002B4AC
		// End Line: 3949

		/* begin block 1.9 */
			// Start line: 3949
			// Start offset: 0x8002B4AC
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $v1
		// 		long _z0; // $t0
		// 		long _y1; // $t1
		// 		struct _Vector *_v; // stack offset -52
		/* end block 1.9 */
		// End offset: 0x8002B4AC
		// End Line: 3949

		/* begin block 1.10 */
			// Start line: 3949
			// Start offset: 0x8002B4AC
			// Variables:
		// 		long _x0; // $v0
		// 		long _y0; // $v1
		// 		long _z0; // $t0
		// 		struct _Vector *_v; // $s4
		/* end block 1.10 */
		// End offset: 0x8002B4AC
		// End Line: 3949

		/* begin block 1.11 */
			// Start line: 3949
			// Start offset: 0x8002B4AC
			// Variables:
		// 		long _x0; // $t0
		// 		long _y0; // $t2
		// 		long _z0; // $t1
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $v1
		// 		struct _Vector *_v; // $s5
		/* end block 1.11 */
		// End offset: 0x8002B4AC
		// End Line: 3949

		/* begin block 1.12 */
			// Start line: 3949
			// Start offset: 0x8002B4AC
			// Variables:
		// 		long _x0; // $t0
		// 		long _y0; // $t2
		// 		long _z0; // $t1
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $v1
		// 		struct _Vector *_v; // $s3
		/* end block 1.12 */
		// End offset: 0x8002B4AC
		// End Line: 3949

		/* begin block 1.13 */
			// Start line: 3949
			// Start offset: 0x8002B4AC
			// Variables:
		// 		long _x0; // $t0
		// 		long _y0; // $t2
		// 		long _z0; // $t1
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $v1
		// 		struct _Vector *_v; // $s2
		/* end block 1.13 */
		// End offset: 0x8002B4AC
		// End Line: 3949

		/* begin block 1.14 */
			// Start line: 3949
			// Start offset: 0x8002B4AC
			// Variables:
		// 		long _x0; // $t0
		// 		long _y0; // $t2
		// 		long _z0; // $t1
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $v1
		// 		struct _Vector *_v; // $s1
		/* end block 1.14 */
		// End offset: 0x8002B4AC
		// End Line: 3949
	/* end block 1 */
	// End offset: 0x8002B9C4
	// End Line: 4028

	/* begin block 2 */
		// Start line: 5216
	/* end block 2 */
	// End Line: 5217

/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* File: C:\kain2\game\DRAW.C */

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
 // line 4038, offset 0x8002b9f4
	/* begin block 1 */
		// Start line: 4039
		// Start offset: 0x8002B9F4
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
	// End offset: 0x8002BB40
	// End Line: 4079

	/* begin block 2 */
		// Start line: 5541
	/* end block 2 */
	// End Line: 5542

/* File: C:\kain2\game\DRAW.C */

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
  
  lVar1 = PIPE3D_Segment2ScreenPt(instance,(char)DAT_800d0ffc,seg1,&local_58);
  lVar2 = PIPE3D_Segment2ScreenPt(instance,(char)DAT_800d0ffc,seg2,&local_50);
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
 // line 4089, offset 0x8002bb60
	/* begin block 1 */
		// Start line: 4090
		// Start offset: 0x8002BB60
		// Variables:
	// 		struct _Position glowPoints1; // stack offset -48
	// 		struct _Vector f1; // stack offset -40
	// 		long otz; // $t0
	// 		long z; // $a1
	// 		long angle; // $s2
	/* end block 1 */
	// End offset: 0x8002BC0C
	// End Line: 4115

	/* begin block 2 */
		// Start line: 5689
	/* end block 2 */
	// End Line: 5690

/* File: C:\kain2\game\DRAW.C */

ulong * DRAW_DrawGlowPoint(_Instance *instance,long seg1,_PrimPool *primPool,ulong **ot,long color,
                          int width,int height)

{
  uint uVar1;
  long lVar2;
  int z;
  _Position local_30;
  _Vector local_28;
  
  uVar1 = DAT_800d2300 & 0x7ff;
  lVar2 = PIPE3D_Segment2ScreenPt(instance,(char)DAT_800d0ffc,seg1,&local_30);
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
 // line 4192, offset 0x8002bc30
	/* begin block 1 */
		// Start line: 4193
		// Start offset: 0x8002BC30
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
			// Start offset: 0x8002BDA0
			// Variables:
		// 		int next_point_in_vv; // $v1
		// 		int current_point_in_vv; // $t1
		// 		int next; // $t6

			/* begin block 1.1.1 */
				// Start line: 4246
				// Start offset: 0x8002BDE0
				// Variables:
			// 		long clip_tmp; // $a0
			// 		long zval; // stack offset -48
			// 		struct SVECTOR *tmpptr; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8002BEC4
			// End Line: 4272

			/* begin block 1.1.2 */
				// Start line: 4276
				// Start offset: 0x8002BECC
				// Variables:
			// 		long zn; // $v1
			// 		long znext; // $a0
			// 		long interp1; // $t1
			// 		long interp2; // $a2
			// 		long clip_tmp; // $v1

				/* begin block 1.1.2.1 */
					// Start line: 4280
					// Start offset: 0x8002BECC
					// Variables:
				// 		long x; // $v1
				// 		long y; // $v1
				/* end block 1.1.2.1 */
				// End offset: 0x8002BFB0
				// End Line: 4291
			/* end block 1.1.2 */
			// End offset: 0x8002C0E8
			// End Line: 4305
		/* end block 1.1 */
		// End offset: 0x8002C0E8
		// End Line: 4306

		/* begin block 1.2 */
			// Start line: 4327
			// Start offset: 0x8002C128
			// Variables:
		// 		int next; // $t0
		// 		int flag; // $t3
		/* end block 1.2 */
		// End offset: 0x8002C300
		// End Line: 4358

		/* begin block 1.3 */
			// Start line: 4361
			// Start offset: 0x8002C300
			// Variables:
		// 		long opz; // stack offset -44
		/* end block 1.3 */
		// End offset: 0x8002C354
		// End Line: 4376

		/* begin block 1.4 */
			// Start line: 4387
			// Start offset: 0x8002C3B4
			// Variables:
		// 		long temp1; // $a3
		// 		long temp2; // $t0
		// 		long temp3; // $t1
		/* end block 1.4 */
		// End offset: 0x8002C3BC
		// End Line: 4408
	/* end block 1 */
	// End offset: 0x8002C440
	// End Line: 4409

	/* begin block 2 */
		// Start line: 8368
	/* end block 2 */
	// End Line: 8369

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* File: C:\kain2\game\DRAW.C */

int DRAW_DisplayTFace_zclipped_C
              (undefined vertex0,undefined vertex1,undefined vertex2,UVTYPE *uv0,UVTYPE *uv1,
              UVTYPE *uv2,long color0,long color1,long color2,_PrimPool *primPool,ulong **ot,
              int ndiv)

{
  bool bVar1;
  undefined4 in_zero;
  undefined4 in_at;
  byte bVar2;
  undefined4 *puVar3;
  short sVar4;
  uint uVar5;
  ulong uVar6;
  ulong *puVar7;
  undefined3 in_register_00000011;
  undefined4 *puVar8;
  undefined3 in_register_00000015;
  undefined4 *puVar9;
  int iVar10;
  undefined3 in_register_00000019;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  ulong uVar14;
  uint uVar15;
  undefined4 uVar16;
  undefined4 *puVar17;
  short *psVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  int iVar21;
  undefined4 uVar22;
  int iVar23;
  uint uVar24;
  undefined4 *puVar25;
  int iVar26;
  int iVar27;
  undefined4 *puVar28;
  POLY_GT3 *texture;
  int iVar29;
  int iVar30;
  
  puVar11 = (undefined4 *)CONCAT31(in_register_00000019,vertex2);
  puVar9 = (undefined4 *)CONCAT31(in_register_00000015,vertex1);
  puVar8 = (undefined4 *)CONCAT31(in_register_00000011,vertex0);
  puVar17 = &DAT_1f800200;
  setCopReg(2,in_zero,*puVar8);
  setCopReg(2,in_at,puVar8[1]);
  copFunction(2,0x480012);
  DAT_1f800278 = getCopReg(2,0x19);
  DAT_1f80027c = getCopReg(2,0x1a);
  DAT_1f800280 = getCopReg(2,0x1b);
  setCopReg(2,in_zero,*puVar9);
  setCopReg(2,in_at,puVar9[1]);
  copFunction(2,0x480012);
  DAT_1f800284 = getCopReg(2,0x19);
  _DAT_1f800288 = getCopReg(2,0x1a);
  DAT_1f80028c = getCopReg(2,0x1b);
  setCopReg(2,in_zero,*puVar11);
  setCopReg(2,in_at,puVar11[1]);
  copFunction(2,0x480012);
  DAT_1f800290 = getCopReg(2,0x19);
  DAT_1f800294 = getCopReg(2,0x1a);
  DAT_1f800298 = getCopReg(2,0x1b);
  if (((DAT_1f800280 < 0xa0) && (DAT_1f80028c < 0xa0)) && (DAT_1f800298 < 0xa0)) {
    return 2;
  }
  iVar10 = 0;
  iVar27 = 0xa0;
  texture = (POLY_GT3 *)primPool->nextPrim;
  DAT_1f8002b8 = *uv0;
  uVar24 = 0xffff;
  iVar23 = 0;
  DAT_1f8002bc = *uv1;
  iVar26 = 0;
  DAT_1f8002c0 = *uv2;
  DAT_1f8002a8 = color0;
  puVar28 = (undefined4 *)&texture->r0;
  DAT_1f8002ac = color1;
  psVar18 = &texture->y0;
  DAT_1f8002b0 = color2;
  puVar3 = puVar8;
  puVar12 = puVar11;
  puVar13 = puVar17;
  puVar25 = puVar17;
  do {
    iVar21 = iVar23 + 1;
    if (2 < iVar21) {
      iVar21 = 0;
    }
    uVar15 = (uint)((int)puVar13[0x20] < 0xa0) ^ 1;
    uVar5 = (uint)((int)(&DAT_1f800280)[iVar21 * 3] < 0xa0) ^ 1;
    if (uVar15 != 0) {
      puVar3 = puVar9;
      if (((iVar23 != 1) && (puVar3 = puVar8, 1 < iVar23)) && (iVar23 == 2)) {
        puVar3 = puVar11;
      }
      setCopReg(2,in_zero,*puVar3);
      setCopReg(2,in_at,puVar3[1]);
      copFunction(2,0x180001);
      *(undefined4 *)(psVar18 + 1) = puVar25[0x2e];
      *puVar28 = puVar25[0x2a];
      uVar19 = getCopReg(2,0xe);
      puVar28[1] = uVar19;
      uVar19 = getCopReg(2,0xe);
      (&DAT_1f8002c4)[iVar10] = uVar19;
      iVar29 = getCopReg(2,0x13);
      if (iVar27 < iVar29) {
        iVar27 = iVar29;
      }
      puVar3 = (undefined4 *)((uint)(int)psVar18[-1] >> 0x1f);
      if (*psVar18 < 0) {
        puVar3 = (undefined4 *)((uint)puVar3 | 2);
      }
      if (0x200 < (int)psVar18[-1]) {
        puVar3 = (undefined4 *)((uint)puVar3 | 4);
      }
      if (0xf0 < *psVar18) {
        puVar3 = (undefined4 *)((uint)puVar3 | 8);
      }
      uVar24 = uVar24 & (uint)puVar3;
      iVar10 = iVar10 + 1;
      psVar18 = psVar18 + 6;
      puVar28 = puVar28 + 3;
    }
    if (uVar15 != uVar5) {
      iVar29 = ((puVar13[0x20] + -0xa0) * 0x1000) /
               (int)(puVar13[0x20] - (&DAT_1f800280)[iVar21 * 3]);
      if (iVar29 < 0) {
        iVar29 = -iVar29;
      }
      iVar30 = ((&DAT_1f800278)[iVar21 * 3] - puVar13[0x1e]) * iVar29;
      puVar12 = (undefined4 *)(0x1000 - iVar29);
      if (iVar30 < 0) {
        iVar30 = iVar30 + 0xfff;
      }
      iVar30 = (puVar13[0x1e] + (iVar30 >> 0xc)) * 2 + 0x100;
      sVar4 = (short)iVar30;
      if (0x3ff < iVar30) {
        sVar4 = 0x3ff;
      }
      if (iVar30 < -0x3ff) {
        sVar4 = -0x3ff;
      }
      psVar18[-1] = sVar4;
      iVar30 = ((&DAT_1f80027c)[iVar21 * 3] - puVar13[0x1f]) * iVar29;
      if (iVar30 < 0) {
        iVar30 = iVar30 + 0xfff;
      }
      iVar30 = (puVar13[0x1f] + (iVar30 >> 0xc)) * 2 + 0x78;
      sVar4 = (short)iVar30;
      if (0x3ff < iVar30) {
        sVar4 = 0x3ff;
      }
      if (iVar30 < -0x3ff) {
        sVar4 = -0x3ff;
      }
      *psVar18 = sVar4;
      setCopReg(2,0x4000,puVar12);
      setCopReg(2,0x4800,(uint)*(byte *)((int)&DAT_1f8002b8 + iVar26));
      setCopReg(2,0x5000,(uint)*(byte *)((int)&DAT_1f8002b8 + iVar26 + 1));
      copFunction(2,0x198003d);
      setCopReg(2,0x4000,iVar29);
      iVar30 = iVar21 * 4;
      setCopReg(2,0x4800,(uint)*(byte *)(&DAT_1f8002b8 + iVar21));
      setCopReg(2,0x5000,(uint)*(byte *)((int)&DAT_1f8002b8 + iVar30 + 1));
      copFunction(2,0x1a8003e);
      uVar19 = getCopReg(2,0x4800);
      uVar20 = getCopReg(2,0x5000);
      *(char *)(puVar28 + 2) = (char)uVar19;
      *(undefined *)((int)puVar28 + 9) = (char)uVar20;
      setCopReg(2,0x4000,puVar12);
      setCopReg(2,0x4800,(uint)*(byte *)((int)&DAT_1f8002a8 + iVar26));
      setCopReg(2,0x5000,(uint)*(byte *)((int)&DAT_1f8002a8 + iVar26 + 1));
      setCopReg(2,0x5800,(uint)*(byte *)((int)&DAT_1f8002a8 + iVar26 + 2));
      copFunction(2,0x198003d);
      setCopReg(2,0x4000,iVar29);
      setCopReg(2,0x4800,(uint)*(byte *)(&DAT_1f8002a8 + iVar21));
      setCopReg(2,0x5000,(uint)*(byte *)((int)&DAT_1f8002a8 + iVar30 + 1));
      setCopReg(2,0x5800,(uint)*(byte *)((int)&DAT_1f8002a8 + iVar30 + 2));
      copFunction(2,0x1a8003e);
      uVar19 = getCopReg(2,0x4800);
      uVar20 = getCopReg(2,0x5000);
      uVar22 = getCopReg(2,0x5800);
      *(char *)puVar28 = (char)uVar19;
      *(undefined *)((int)puVar28 + 1) = (char)uVar20;
      *(undefined *)((int)puVar28 + 2) = (char)uVar22;
      (&DAT_1f8002c4)[iVar10] = *(undefined4 *)(psVar18 + -1);
      puVar3 = (undefined4 *)(int)*psVar18;
      uVar5 = (uint)(int)psVar18[-1] >> 0x1f;
      if ((int)puVar3 < 0) {
        uVar5 = uVar5 | 2;
      }
      if (0x200 < (int)psVar18[-1]) {
        uVar5 = uVar5 | 4;
      }
      if (0xf0 < (int)puVar3) {
        uVar5 = uVar5 | 8;
      }
      uVar24 = uVar24 & uVar5;
      iVar10 = iVar10 + 1;
      psVar18 = psVar18 + 6;
      puVar28 = puVar28 + 3;
    }
    iVar26 = iVar26 + 4;
    puVar13 = puVar13 + 3;
    iVar23 = iVar23 + 1;
    puVar25 = puVar25 + 1;
  } while (iVar23 < 3);
  if (uVar24 != 0) {
    return 2;
  }
  iVar27 = iVar27 >> 2;
  uVar24 = (uint)(iVar27 < 0xc00);
  if (iVar27 < 0xc00) {
    if (ndiv == 0) {
      bVar1 = false;
      if (0 < iVar10) {
        iVar26 = 1;
        iVar23 = 0;
        do {
          iVar21 = iVar26 << 2;
          if (iVar10 <= iVar26) {
            iVar26 = 0;
            iVar21 = 0;
          }
          puVar3 = (undefined4 *)(int)*(short *)(puVar17 + 0x31);
          uVar5 = SEXT24(*(short *)((int)&DAT_1f8002c4 + iVar21));
          puVar13 = (undefined4 *)((int)puVar3 - uVar5);
          if ((int)puVar13 < 0) {
            puVar13 = (undefined4 *)(uVar5 - (int)puVar3);
          }
          uVar24 = iVar26 * 4;
          if (0x3ff < (int)puVar13) {
LAB_8002c1b4:
            bVar1 = true;
            break;
          }
          puVar3 = (undefined4 *)(int)*(short *)((int)puVar17 + 0xc6);
          uVar5 = SEXT24(*(short *)((int)&DAT_1f8002c4 + uVar24 + 2));
          puVar13 = (undefined4 *)((int)puVar3 - uVar5);
          if ((int)puVar13 < 0) {
            puVar13 = (undefined4 *)(uVar5 - (int)puVar3);
          }
          uVar24 = (uint)((int)puVar13 < 0x200);
          if ((int)puVar13 >= 0x200) goto LAB_8002c1b4;
          puVar17 = puVar17 + 1;
          iVar21 = iVar23 + 1;
          uVar24 = (uint)(iVar21 < iVar10);
          iVar26 = iVar23 + 2;
          iVar23 = iVar21;
        } while (iVar21 < iVar10);
      }
      if (bVar1) goto LAB_8002c268;
      uVar24 = 4;
      if (iVar10 == 4) {
        puVar3 = (undefined4 *)(int)DAT_1f8002d0;
        uVar5 = SEXT24((short)DAT_1f8002c8);
        puVar17 = (undefined4 *)((int)puVar3 - uVar5);
        if ((int)puVar17 < 0) {
          puVar17 = (undefined4 *)(uVar5 - (int)puVar3);
        }
        uVar24 = (uint)((int)puVar17 < 0x400);
        if ((int)puVar17 < 0x400) {
          puVar3 = (undefined4 *)(int)DAT_1f8002d2;
          uVar5 = SEXT24(DAT_1f8002c8._2_2_);
          puVar17 = (undefined4 *)((int)puVar3 - uVar5);
          if ((int)puVar17 < 0) {
            puVar17 = (undefined4 *)(uVar5 - (int)puVar3);
          }
          uVar24 = (uint)((int)puVar17 < 0x200);
          if ((int)puVar17 < 0x200) goto LAB_8002c260;
        }
        bVar1 = true;
      }
LAB_8002c260:
      if (bVar1) {
LAB_8002c268:
        setCopReg(2,in_zero,*puVar8);
        setCopReg(2,in_at,puVar8[1]);
        setCopReg(2,uVar24,*puVar9);
        setCopReg(2,uVar5,puVar9[1]);
        setCopReg(2,puVar3,*puVar11);
        setCopReg(2,iVar10,puVar11[1]);
        DAT_1f8002b0 = DAT_1f8002a8 & 0xff000000 | DAT_1f8002b0 & 0xffffff;
        setCopReg(2,primPool,DAT_1f8002a8);
        setCopReg(2,puVar11,DAT_1f8002ac);
        setCopReg(2,puVar8,DAT_1f8002b0);
        setCopReg(2,puVar12,DAT_1f8002b0);
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
    iVar23 = getCopReg(2,0x18);
    if (0 < iVar23) {
      return 4;
    }
    bVar2 = (byte)((uint)color0 >> 0x18);
    if (iVar10 == 3) {
      texture->code = bVar2;
      texture->tag = (uint)ot[iVar27] & 0xffffff | 0x9000000;
      ot[iVar27] = (ulong *)((uint)texture & 0xffffff);
      iVar10 = primPool->numPrims;
      puVar7 = primPool->nextPrim + 10;
    }
    else {
      if (iVar10 != 4) goto LAB_8002c3b4;
      uVar14 = *(ulong *)&texture->r2;
      uVar22 = *(undefined4 *)&texture->x2;
      uVar16 = *(undefined4 *)&texture->u2;
      uVar6 = texture[1].tag;
      uVar19 = *(undefined4 *)&texture[1].r0;
      uVar20 = *(undefined4 *)&texture[1].x0;
      texture->code = bVar2 | 8;
      *(ulong *)&texture->r2 = uVar6;
      *(undefined4 *)&texture->x2 = uVar19;
      *(undefined4 *)&texture->u2 = uVar20;
      texture[1].tag = uVar14;
      *(undefined4 *)&texture[1].r0 = uVar22;
      *(undefined4 *)&texture[1].x0 = uVar16;
      texture->tag = (uint)ot[iVar27] & 0xffffff | 0xc000000;
      ot[iVar27] = (ulong *)((uint)texture & 0xffffff);
      iVar10 = primPool->numPrims;
      puVar7 = primPool->nextPrim + 0xd;
    }
    iVar27 = 1;
    primPool->nextPrim = puVar7;
    primPool->numPrims = iVar10 + 1;
  }
  else {
LAB_8002c3b4:
    iVar27 = 2;
  }
  return iVar27;
}



// decompiled code
// original method signature: 
// long * /*$ra*/ DRAW_Zclip_subdiv(struct POLY_GT3 *texture /*$t0*/, unsigned long **ot /*stack 4*/, int ndiv /*stack 8*/)
 // line 4420, offset 0x8002c470
	/* begin block 1 */
		// Start line: 4421
		// Start offset: 0x8002C470
		// Variables:
	// 		struct SP_SUBDIV_STRUCT *sp; // $s7
	// 		struct _PrimPool *primPool; // $fp
	// 		int clip; // $s0
	/* end block 1 */
	// End offset: 0x8002C944
	// End Line: 4556

	/* begin block 2 */
		// Start line: 6524
	/* end block 2 */
	// End Line: 6525

/* File: C:\kain2\game\DRAW.C */

long * DRAW_Zclip_subdiv(POLY_GT3 *texture,ulong **ot,int ndiv)

{
  undefined4 uVar1;
  byte bVar2;
  _PrimPool *primPool;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ulong *puVar7;
  char vertex1;
  char vertex1_00;
  char vertex2;
  UVTYPE *uv1;
  UVTYPE *uv2;
  UVTYPE *uv1_00;
  undefined4 *puVar8;
  
  puVar8 = &DAT_1f800200;
  if (ndiv != 0) {
    puVar8 = &DAT_1f8002d4;
  }
  uVar1 = getCopReg(2,0x14);
  puVar8[0x18] = uVar1;
  uVar1 = getCopReg(2,0x15);
  puVar8[0x19] = uVar1;
  uVar1 = getCopReg(2,0x16);
  puVar8[0x1a] = uVar1;
  uVar1 = getCopReg(2,0);
  *puVar8 = uVar1;
  uVar1 = getCopReg(2,1);
  puVar8[1] = uVar1;
  uVar1 = getCopReg(2,2);
  puVar8[2] = uVar1;
  uVar1 = getCopReg(2,3);
  puVar8[3] = uVar1;
  uVar1 = getCopReg(2,4);
  puVar8[4] = uVar1;
  uVar1 = getCopReg(2,5);
  puVar8[5] = uVar1;
  primPool = DAT_800d210c;
  *(POLY_GT3 **)&DAT_800d210c->nextPrim = texture;
  puVar8[8] = puVar8[2];
  puVar8[7] = puVar8[1];
  puVar8[9] = puVar8[3];
  puVar8[10] = puVar8[4];
  puVar8[0xb] = puVar8[5];
  puVar8[6] = *puVar8;
  *(short *)(puVar8 + 0xc) =
       (short)(((int)*(short *)(puVar8 + 6) + (int)*(short *)(puVar8 + 8)) / 2);
  *(undefined2 *)((int)puVar8 + 0x32) =
       (short)(((int)*(short *)((int)puVar8 + 0x1a) + (int)*(short *)((int)puVar8 + 0x22)) / 2);
  *(short *)(puVar8 + 0xd) =
       (short)(((int)*(short *)(puVar8 + 7) + (int)*(short *)(puVar8 + 9)) / 2);
  *(short *)(puVar8 + 0xe) =
       (short)(((int)*(short *)(puVar8 + 8) + (int)*(short *)(puVar8 + 10)) / 2);
  *(undefined2 *)((int)puVar8 + 0x3a) =
       (short)(((int)*(short *)((int)puVar8 + 0x22) + (int)*(short *)((int)puVar8 + 0x2a)) / 2);
  *(short *)(puVar8 + 0xf) =
       (short)(((int)*(short *)(puVar8 + 9) + (int)*(short *)(puVar8 + 0xb)) / 2);
  *(short *)(puVar8 + 0x10) =
       (short)(((int)*(short *)(puVar8 + 10) + (int)*(short *)(puVar8 + 6)) / 2);
  *(undefined2 *)((int)puVar8 + 0x42) =
       (short)(((int)*(short *)((int)puVar8 + 0x2a) + (int)*(short *)((int)puVar8 + 0x1a)) / 2);
  *(short *)(puVar8 + 0x11) =
       (short)(((int)*(short *)(puVar8 + 0xb) + (int)*(short *)(puVar8 + 7)) / 2);
  uv1_00 = (UVTYPE *)(puVar8 + 0x15);
  puVar8[0x12] = *(undefined4 *)&texture->u0;
  uv2 = (UVTYPE *)(puVar8 + 0x17);
  puVar8[0x13] = *(undefined4 *)&texture->u1;
  bVar2 = (byte)puVar8;
  vertex1 = bVar2 + 0x30;
  puVar8[0x14] = *(undefined4 *)&texture->u2;
  *(char *)(puVar8 + 0x15) =
       (char)((int)((uint)*(byte *)(puVar8 + 0x12) + (uint)*(byte *)(puVar8 + 0x13)) >> 1);
  vertex2 = bVar2 + 0x40;
  *(undefined2 *)((int)puVar8 + 0x5a) = *(undefined2 *)((int)puVar8 + 0x4e);
  *(undefined2 *)((int)puVar8 + 0x56) = *(undefined2 *)((int)puVar8 + 0x4e);
  *(undefined *)((int)puVar8 + 0x55) =
       (char)((int)((uint)*(byte *)((int)puVar8 + 0x49) + (uint)*(byte *)((int)puVar8 + 0x4d)) >> 1)
  ;
  *(char *)(puVar8 + 0x16) =
       (char)((int)((uint)*(byte *)(puVar8 + 0x13) + (uint)*(byte *)(puVar8 + 0x14)) >> 1);
  *(undefined *)((int)puVar8 + 0x59) =
       (char)((int)((uint)*(byte *)((int)puVar8 + 0x4d) + (uint)*(byte *)((int)puVar8 + 0x51)) >> 1)
  ;
  *(char *)(puVar8 + 0x17) =
       (char)((int)((uint)*(byte *)(puVar8 + 0x14) + (uint)*(byte *)(puVar8 + 0x12)) >> 1);
  *(undefined *)((int)puVar8 + 0x5d) =
       (char)((int)((uint)*(byte *)((int)puVar8 + 0x51) + (uint)*(byte *)((int)puVar8 + 0x49)) >> 1)
  ;
  *(undefined2 *)((int)puVar8 + 0x5e) = *(undefined2 *)((int)puVar8 + 0x4a);
  *(char *)(puVar8 + 0x1b) =
       (char)((int)((uint)*(byte *)(puVar8 + 0x18) + (uint)*(byte *)(puVar8 + 0x19)) >> 1);
  *(undefined *)((int)puVar8 + 0x6d) =
       (char)((int)((uint)*(byte *)((int)puVar8 + 0x61) + (uint)*(byte *)((int)puVar8 + 0x65)) >> 1)
  ;
  *(undefined *)((int)puVar8 + 0x6e) =
       (char)((int)((uint)*(byte *)((int)puVar8 + 0x62) + (uint)*(byte *)((int)puVar8 + 0x66)) >> 1)
  ;
  *(char *)(puVar8 + 0x1c) =
       (char)((int)((uint)*(byte *)(puVar8 + 0x19) + (uint)*(byte *)(puVar8 + 0x1a)) >> 1);
  *(undefined *)((int)puVar8 + 0x71) =
       (char)((int)((uint)*(byte *)((int)puVar8 + 0x65) + (uint)*(byte *)((int)puVar8 + 0x69)) >> 1)
  ;
  *(undefined *)((int)puVar8 + 0x72) =
       (char)((int)((uint)*(byte *)((int)puVar8 + 0x66) + (uint)*(byte *)((int)puVar8 + 0x6a)) >> 1)
  ;
  *(char *)(puVar8 + 0x1d) =
       (char)((int)((uint)*(byte *)(puVar8 + 0x1a) + (uint)*(byte *)(puVar8 + 0x18)) >> 1);
  *(undefined *)((int)puVar8 + 0x75) =
       (char)((int)((uint)*(byte *)((int)puVar8 + 0x69) + (uint)*(byte *)((int)puVar8 + 0x61)) >> 1)
  ;
  *(undefined *)((int)puVar8 + 0x76) =
       (char)((int)((uint)*(byte *)((int)puVar8 + 0x6a) + (uint)*(byte *)((int)puVar8 + 0x62)) >> 1)
  ;
  *(undefined *)((int)puVar8 + 0x77) = *(undefined *)((int)puVar8 + 99);
  *(undefined *)((int)puVar8 + 0x6f) = *(undefined *)((int)puVar8 + 99);
  uVar3 = DRAW_DisplayTFace_zclipped_C
                    (bVar2 + 0x18,vertex1,vertex2,(UVTYPE *)(puVar8 + 0x12),uv1_00,uv2,puVar8[0x18],
                     puVar8[0x1b],puVar8[0x1d],primPool,ot,ndiv);
  uv1 = (UVTYPE *)(puVar8 + 0x16);
  vertex1_00 = bVar2 + 0x38;
  uVar4 = DRAW_DisplayTFace_zclipped_C
                    (vertex2,vertex1_00,bVar2 | 0x28,uv2,uv1,(UVTYPE *)(puVar8 + 0x14),puVar8[0x1d],
                     puVar8[0x1c],puVar8[0x1a],primPool,ot,ndiv);
  *(undefined2 *)((int)puVar8 + 0x56) = *(undefined2 *)((int)puVar8 + 0x4a);
  *(undefined2 *)((int)puVar8 + 0x5e) = *(undefined2 *)((int)puVar8 + 0x4e);
  uVar5 = DRAW_DisplayTFace_zclipped_C
                    (vertex1,vertex1_00,vertex2,uv1_00,uv1,uv2,puVar8[0x1b],puVar8[0x1c],
                     puVar8[0x1d],primPool,ot,ndiv);
  uVar6 = DRAW_DisplayTFace_zclipped_C
                    (vertex1,bVar2 | 0x20,vertex1_00,uv1_00,(UVTYPE *)(puVar8 + 0x13),uv1,
                     puVar8[0x1b],puVar8[0x19],puVar8[0x1c],primPool,ot,ndiv);
  puVar7 = (ulong *)0x0;
  if (((uVar3 | uVar4 | uVar5 | uVar6) & 5) != 4) {
    puVar7 = primPool->nextPrim;
  }
  return (long *)puVar7;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DRAW_LoadingMessage()
 // line 4569, offset 0x8002c974
	/* begin block 1 */
		// Start line: 4572
		// Start offset: 0x8002C984
		// Variables:
	// 		unsigned long **drawot; // $s0
	/* end block 1 */
	// End offset: 0x8002C9AC
	// End Line: 4583

	/* begin block 2 */
		// Start line: 7035
	/* end block 2 */
	// End Line: 7036

/* File: C:\kain2\game\DRAW.C */

void DRAW_LoadingMessage(void)

{
  u_long *ot;
  int len;
  char *text;
  
  do {
    len = CheckVolatile(DAT_800d21e8);
  } while (len != 0);
  do {
    len = CheckVolatile(DAT_800d21e4);
  } while (len != 0);
  DrawSyncCallback((func *)0x0);
  VSyncCallback((f *)0x0);
  ot = DAT_800d22a4;
  PutDrawEnv(draw + (DAT_800d20fc ^ 1));
  text = localstr_get(LOCALSTR_Hint52);
  FONT_FontPrintCentered(text,0x96);
  text = localstr_get(LOCALSTR_Hint52);
  len = FONT_GetStringWidth(text);
  DisplayHintBox(len,0x96);
  FONT_Flush();
  DrawOTag((u_long *)ot[0xbff]);
  DrawSync(0);
  ClearOTagR(ot,0xc00);
  PutDrawEnv(draw + DAT_800d20fc);
  VSyncCallback(VblTick);
  DrawSyncCallback(DrawCallback);
  return;
}





