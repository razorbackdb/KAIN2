#include "THISDUST.H"
#include "FONT.H"


// decompiled code
// original method signature: 
// void /*$ra*/ FONT_MakeSpecialFogClut(int x /*$a3*/, int y /*$a1*/)
 // line 58, offset 0x8002cb74
	/* begin block 1 */
		// Start line: 59
		// Start offset: 0x8002CB74
		// Variables:
	// 		int n; // $a0
	// 		unsigned short cl[16]; // stack offset -48
	// 		struct RECT myrect; // stack offset -16
	/* end block 1 */
	// End offset: 0x8002CB9C
	// End Line: 69

	/* begin block 2 */
		// Start line: 116
	/* end block 2 */
	// End Line: 117

void FONT_MakeSpecialFogClut(int param_1,int param_2)

{
  undefined2 *puVar1;
  int iVar2;
  undefined2 local_12 [4];
  undefined2 local_a;
  
  iVar2 = 0xf;
  puVar1 = local_12;
  do {
    *puVar1 = 0x4210;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + -1;
  } while (-1 < iVar2);
  local_12[3] = 0x10;
  local_a = 1;
  uGpffffab34 = (ushort)(param_2 << 6) | (ushort)(param_1 >> 4) & 0x3f;
  local_12[1] = (undefined2)param_1;
  local_12[2] = (undefined2)param_2;
                    /* WARNING: Subroutine does not return */
  DrawSync(0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_Init()
 // line 91, offset 0x8002cbf8
	/* begin block 1 */
		// Start line: 92
		// Start offset: 0x8002CBF8
		// Variables:
	// 		unsigned long *timAddr; // $s0
	// 		short x; // stack offset -16
	// 		short y; // stack offset -14
	/* end block 1 */
	// End offset: 0x8002CCE8
	// End Line: 126

	/* begin block 2 */
		// Start line: 188
	/* end block 2 */
	// End Line: 189

/* WARNING: Unknown calling convention yet parameter storage is locked */

void FONT_Init(void)

{
  long *addr;
  short local_10;
  short local_e [3];
  
  depthQFogStart = VRAM_CheckVramSlot(&local_10,local_e,0x10,0x80,3,-1);
  if (depthQFogStart != (_BlockVramEntry *)0x0) {
    addr = LOAD_ReadFile(padIntFunc,'\x05');
    LOAD_LoadTIM(addr,(int)local_10,(int)local_e[0],(int)local_10,(int)local_e[0] + 0x7e);
                    /* WARNING: Subroutine does not return */
    MEMPACK_Free((char *)addr);
  }
  DAT_800d0bec = 10;
  DAT_800d0bf0 = 0x10;
  DAT_800d0bf4 = 0;
  DAT_800d0c02 = 0;
  DAT_800d0c08 = 0;
  DAT_800d0c09 = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_ReloadFont()
 // line 137, offset 0x8002cd18
	/* begin block 1 */
		// Start line: 138
		// Start offset: 0x8002CD18
		// Variables:
	// 		unsigned long *timAddr; // $s0
	/* end block 1 */
	// End offset: 0x8002CD18
	// End Line: 138

	/* begin block 2 */
		// Start line: 318
	/* end block 2 */
	// End Line: 319

/* WARNING: Unknown calling convention yet parameter storage is locked */

void FONT_ReloadFont(void)

{
  long *addr;
  
  addr = LOAD_ReadFile(padIntFunc,'\x05');
  LOAD_LoadTIM(addr,(int)DAT_800d0c04,(int)DAT_800d0c06,(int)DAT_800d0c04,(int)DAT_800d0c06 + 0x7e);
                    /* WARNING: Subroutine does not return */
  MEMPACK_Free((char *)addr);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_DrawChar(struct FontChar *fontChar /*$a0*/)
 // line 149, offset 0x8002cd7c
	/* begin block 1 */
		// Start line: 150
		// Start offset: 0x8002CD7C
		// Variables:
	// 		char c; // $v1
	// 		long x; // $a1
	// 		long y; // $a2
	/* end block 1 */
	// End offset: 0x8002CD7C
	// End Line: 150

	/* begin block 2 */
		// Start line: 346
	/* end block 2 */
	// End Line: 347

void FONT_DrawChar(FontChar *fontChar)

{
  DAT_800d0c09 = fontChar->color;
  FONT_DrawChar2D(fontChar->c,(int)fontChar->x,(int)fontChar->y);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ FONT_Get2DImageIndex(unsigned char c /*$a0*/)
 // line 471, offset 0x8002cdb0
	/* begin block 1 */
		// Start line: 994
	/* end block 1 */
	// End Line: 995

	/* begin block 2 */
		// Start line: 1059
	/* end block 2 */
	// End Line: 1060

long FONT_Get2DImageIndex(uchar c)

{
  return (uint)_spu_AllocLastNum[c];
}



// decompiled code
// original method signature: 
// void /*$ra*/ drawChar2DPoly(long fpi /*$a0*/, long x /*$s0*/, long y /*$a2*/)
 // line 558, offset 0x8002cdc8
	/* begin block 1 */
		// Start line: 559
		// Start offset: 0x8002CDC8
		// Variables:
	// 		unsigned long **drawOT; // $s1
	// 		struct POLY_FT4 *textPoly; // $a3
	// 		long xl; // $t8
	// 		long xr; // $s0
	// 		long yt; // $a0
	// 		long yb; // $a2
	// 		long w; // $a0
	// 		long h; // $v0
	// 		int u; // $v1
	// 		int v; // $a0
	// 		int u0; // $t3
	// 		int v0; // $t2
	// 		int u1; // $t5
	// 		int v1; // $t1
	// 		int u2; // $t7
	// 		int v2; // $t0
	// 		int u3; // $t6
	// 		int v3; // $t4

		/* begin block 1.1 */
			// Start line: 606
			// Start offset: 0x8002CE78
		/* end block 1.1 */
		// End offset: 0x8002CE88
		// End Line: 615

		/* begin block 1.2 */
			// Start line: 618
			// Start offset: 0x8002CE90
			// Variables:
		// 		int holdu; // $v0
		// 		int holdv; // $v1
		/* end block 1.2 */
		// End offset: 0x8002CEC0
		// End Line: 627

		/* begin block 1.3 */
			// Start line: 636
			// Start offset: 0x8002CEEC
			// Variables:
		// 		struct font_color_t *color; // $v0
		/* end block 1.3 */
		// End offset: 0x8002CF2C
		// End Line: 639
	/* end block 1 */
	// End offset: 0x8002CF2C
	// End Line: 640

	/* begin block 2 */
		// Start line: 1116
	/* end block 2 */
	// End Line: 1117

void drawChar2DPoly(long fpi,long x,long y)

{
  char cVar1;
  char cVar2;
  short sVar3;
  uint *puVar4;
  uint uVar5;
  short sVar6;
  int iVar7;
  short sVar8;
  uint *puVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  short sVar15;
  
  puVar4 = theCamera.posSphere.position._0_4_;
  iVar7 = fpi * 4;
  cVar13 = *(char *)(&DebugMenuLine_800c84f4.text + fpi);
  if (cVar13 < '\0') {
    cVar13 = -cVar13;
  }
  cVar12 = *(char *)((int)&DebugMenuLine_800c84f4.text + iVar7 + 1);
  if (cVar12 < '\0') {
    cVar12 = -cVar12;
  }
  cVar1 = *(char *)((int)&DebugMenuLine_800c84f4.text + iVar7 + 2);
  sVar15 = (short)cVar1;
  cVar2 = *(char *)((int)&DebugMenuLine_800c84f4.text + iVar7 + 3);
  sVar6 = (short)cVar2;
  cVar13 = cVar13 + (char)DAT_800d0bfc;
  cVar12 = cVar12 + (char)DAT_800d0bfe;
  if (cVar1 < '\0') {
    sVar15 = -(short)cVar1;
  }
  cVar14 = cVar13 + (char)sVar15;
  if (cVar2 < '\0') {
    sVar6 = -(short)cVar2;
  }
  cVar10 = cVar12 + (char)sVar6;
  sVar3 = (short)x;
  sVar6 = (short)y - (sVar6 + -0xc);
  puVar9 = *(uint **)(theCamera.core.vvPlaneConsts[2] + 4);
  sVar8 = (short)y + 0xc;
  cVar11 = cVar12;
  if (cVar2 < '\0') {
    cVar11 = cVar10;
    cVar10 = cVar12;
  }
  cVar12 = cVar13;
  if (cVar1 < '\0') {
    cVar12 = cVar14;
    cVar14 = cVar13;
  }
  *(undefined *)((int)puVar9 + 3) = 9;
  *(undefined *)((int)puVar9 + 7) = 0x2c;
  if (DAT_800d0c09 == 0) {
    *(undefined *)((int)puVar9 + 7) = 0x2d;
  }
  else {
    uVar5 = (uint)DAT_800d0c09;
    *(undefined *)((int)puVar9 + 7) = 0x2c;
    *(undefined *)(puVar9 + 1) = *(undefined *)&the_font_color_table[uVar5].r;
    *(undefined *)((int)puVar9 + 5) = *(undefined *)&the_font_color_table[uVar5].g;
    *(undefined *)((int)puVar9 + 6) = *(undefined *)&the_font_color_table[uVar5].b;
  }
  *(char *)(puVar9 + 3) = cVar12;
  *(char *)((int)puVar9 + 0xd) = cVar11;
  *(char *)(puVar9 + 5) = cVar14;
  *(char *)((int)puVar9 + 0x15) = cVar11;
  *(char *)(puVar9 + 7) = cVar12;
  *(char *)((int)puVar9 + 0x1d) = cVar10;
  *(char *)(puVar9 + 9) = cVar14;
  *(char *)((int)puVar9 + 0x25) = cVar10;
  *(short *)(puVar9 + 2) = sVar3;
  *(short *)((int)puVar9 + 10) = sVar6;
  *(short *)(puVar9 + 4) = sVar3 + sVar15;
  *(short *)((int)puVar9 + 0x12) = sVar6;
  *(short *)(puVar9 + 6) = sVar3;
  *(short *)((int)puVar9 + 0x1a) = sVar8;
  *(short *)(puVar9 + 8) = sVar3 + sVar15;
  *(short *)((int)puVar9 + 0x22) = sVar8;
  *(byte *)((int)puVar9 + 7) = *(byte *)((int)puVar9 + 7) & 0xfd;
  *(undefined2 *)((int)puVar9 + 0x16) = DAT_800d0bf8;
  *(undefined2 *)((int)puVar9 + 0xe) = DAT_800d0bfa;
  *puVar9 = *puVar4 & 0xffffff | 0x9000000;
  *puVar4 = (uint)puVar9 & 0xffffff;
  *(uint **)(theCamera.core.vvPlaneConsts[2] + 4) = puVar9 + 10;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_DrawChar2D(unsigned char c /*$fp*/, long x /*$s7*/, long y /*$s3*/)
 // line 660, offset 0x8002cfc8
	/* begin block 1 */
		// Start line: 661
		// Start offset: 0x8002CFC8
		// Variables:
	// 		long w; // $s0
	// 		long h; // $s6
	// 		long w1; // $a1
	// 		long w2; // $s1
	// 		long w3; // $s2
	// 		long xoff; // $a1
	// 		long yoff; // $a2
	// 		int i1; // $a0
	// 		int i2; // $s4
	// 		int i3; // $s5
	/* end block 1 */
	// End offset: 0x8002D1CC
	// End Line: 702

	/* begin block 2 */
		// Start line: 1438
	/* end block 2 */
	// End Line: 1439

	/* begin block 3 */
		// Start line: 1443
	/* end block 3 */
	// End Line: 1444

void FONT_DrawChar2D(uchar c,long x,long y)

{
  long y_00;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int fpi;
  int iVar5;
  int fpi_00;
  int fpi_01;
  
  if (*(uint *)(theCamera.core.vvPlaneConsts[2] + 4) <=
      *(int *)(theCamera.core.vvPlaneConsts[2] + 8) - 0x30U) {
    y_00 = FONT_Get2DImageIndex(c);
    fpi_01 = y_00 * 3;
    fpi = (int)*(char *)((int)&DebugMenuLine_800c8614.text + fpi_01);
    fpi_00 = (int)*(char *)((int)&DebugMenuLine_800c8614.text + fpi_01 + 1);
    fpi_01 = (int)*(char *)((int)&DebugMenuLine_800c8614.text + fpi_01 + 2);
    if (fpi < 0) {
      iVar1 = 8;
    }
    else {
      iVar1 = (int)*(char *)((int)&DebugMenuLine_800c84f4.text + fpi * 4 + 2);
      if (iVar1 < 0) {
        iVar1 = -iVar1;
      }
    }
    iVar2 = iVar1;
    if ((-1 < fpi_00) &&
       (iVar2 = (int)*(char *)((int)&DebugMenuLine_800c84f4.text + fpi_00 * 4 + 2), iVar2 < 0)) {
      iVar2 = -iVar2;
    }
    iVar3 = iVar1;
    if ((-1 < fpi_01) &&
       (iVar3 = (int)*(char *)((int)&DebugMenuLine_800c84f4.text + fpi_01 * 4 + 2), iVar3 < 0)) {
      iVar3 = -iVar3;
    }
    iVar5 = iVar3;
    if (iVar2 < iVar1) {
      if (iVar3 < iVar1) {
        iVar5 = iVar1;
      }
    }
    else {
      if (iVar3 < iVar2) {
        iVar5 = iVar2;
      }
    }
    if (fpi < 0) {
      iVar4 = 0xc;
    }
    else {
      iVar4 = (int)*(char *)((int)&DebugMenuLine_800c84f4.text + fpi * 4 + 3);
      if (iVar4 < 0) {
        iVar4 = -iVar4;
      }
    }
    if (-1 < fpi) {
      drawChar2DPoly(fpi,x + (iVar5 - iVar1) / 2,y);
    }
    y_00 = y;
    if (c == 'A') {
      y_00 = y + 2;
    }
    if (c == '\'') {
      y = y + 3;
    }
    if (-1 < fpi_00) {
      drawChar2DPoly(fpi_00,x + (iVar5 - iVar2) / 2,y_00);
    }
    if (-1 < fpi_01) {
      drawChar2DPoly(fpi_01,x + (iVar5 - iVar3) / 2,(y + 1) - iVar4);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ FONT_CharSpacing(char c /*$a0*/, long fontXSize /*$s0*/)
 // line 704, offset 0x8002d1fc
	/* begin block 1 */
		// Start line: 705
		// Start offset: 0x8002D1FC
		// Variables:
	// 		long index; // $a0
	// 		long w; // $v1
	// 		long w1; // $a2
	// 		long w2; // $a1
	// 		long w3; // $v1
	// 		char i1; // $v1
	// 		char i2; // $a3
	// 		char i3; // $t1

		/* begin block 1.1 */
			// Start line: 717
			// Start offset: 0x8002D230
			// Variables:
		// 		int holdw; // $a0
		// 		int holdw2; // $a0
		/* end block 1.1 */
		// End offset: 0x8002D32C
		// End Line: 741
	/* end block 1 */
	// End offset: 0x8002D330
	// End Line: 746

	/* begin block 2 */
		// Start line: 1531
	/* end block 2 */
	// End Line: 1532

long FONT_CharSpacing(char c,long fontXSize)

{
  char c_00;
  long lVar1;
  int iVar2;
  char **ppcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long in_a2;
  
  if ((c != ' ') && (lVar1 = FONT_Get2DImageIndex(c), lVar1 != -1)) {
    iVar6 = lVar1 * 3;
    ppcVar3 = (char **)((int)&DebugMenuLine_800c8614.text + iVar6);
    iVar2 = (int)(char)*(byte *)ppcVar3;
    lVar1 = iVar2 * 4;
    c_00 = *(char *)((int)&DebugMenuLine_800c84f4.text + lVar1 + 2);
    if (-1 < (int)c_00) {
      FONT_AddCharToBuffer(c_00,(long)(&DebugMenuLine_800c84f4.text + iVar2),in_a2);
      return lVar1;
    }
    iVar5 = -(int)c_00;
    if (*(char *)(&DebugMenuLine_800c84f4.text + iVar2) < '\0') {
      iVar5 = (int)*(char *)((int)&DebugMenuLine_800c84f4.text + lVar1 + 3);
    }
    iVar2 = 8;
    if (-1 < (int)((uint)*(byte *)ppcVar3 << 0x18)) {
      iVar2 = iVar5;
    }
    iVar4 = (int)*(char *)((int)&DebugMenuLine_800c8614.text + iVar6 + 1);
    iVar5 = (int)*(char *)((int)&DebugMenuLine_800c84f4.text + iVar4 * 4 + 2);
    if (iVar5 < 0) {
      iVar5 = -iVar5;
    }
    iVar7 = iVar2;
    if (-1 < iVar4) {
      iVar7 = iVar5;
    }
    iVar5 = (int)*(char *)((int)&DebugMenuLine_800c8614.text + iVar6 + 2);
    iVar6 = (int)*(char *)((int)&DebugMenuLine_800c84f4.text + iVar5 * 4 + 2);
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    iVar4 = iVar2;
    if (-1 < iVar5) {
      iVar4 = iVar6;
    }
    if (iVar7 < iVar2) {
      iVar7 = iVar2;
    }
    fontXSize = iVar4 + 1;
    if (iVar4 < iVar7) {
      fontXSize = iVar7 + 1;
    }
  }
  return fontXSize;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_AddCharToBuffer(char c /*$a3*/, long x /*$a1*/, long y /*$a2*/)
 // line 1059, offset 0x8002d340
	/* begin block 1 */
		// Start line: 1060
		// Start offset: 0x8002D340
		// Variables:
	// 		struct FontChar *fontChar; // $a0
	/* end block 1 */
	// End offset: 0x8002D3A4
	// End Line: 1079

	/* begin block 2 */
		// Start line: 2118
	/* end block 2 */
	// End Line: 2119

void FONT_AddCharToBuffer(char c,long x,long y)

{
  int iVar1;
  
  iVar1 = DAT_800d0bf4 * 6;
  if (DAT_800d0bf4 < 0xff) {
    if (c == '@') {
      *(ushort *)(&depthQBackColor + iVar1) = (ushort)x & 0xff;
      *(ushort *)(&DAT_800d05ee + iVar1) = (ushort)y & 0xff;
    }
    else {
      *(ushort *)(&depthQBackColor + iVar1) = (ushort)x;
      *(ushort *)(&DAT_800d05ee + iVar1) = (ushort)y;
    }
    (&gameTimer)[iVar1] = c;
    DAT_800d0bf4 = DAT_800d0bf4 + 1;
    (&DAT_800d05f1)[iVar1] = DAT_800d0c08;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_Print(char *fmt /*stack 0*/)
 // line 1096, offset 0x8002d3ac
	/* begin block 1 */
		// Start line: 1097
		// Start offset: 0x8002D3AC
		// Variables:
	// 		char *hold; // $v1
	// 		void *ap; // $s0
	/* end block 1 */
	// End offset: 0x8002D420
	// End Line: 1111

	/* begin block 2 */
		// Start line: 2007
	/* end block 2 */
	// End Line: 2008

void FONT_Print(char *fmt)

{
  byte bVar1;
  short *psVar2;
  undefined local_res4 [12];
  
  vsprintf((char *)&roll_target,fmt,local_res4);
  psVar2 = &roll_target;
  bVar1 = (byte)roll_target;
  while (bVar1 != 0) {
    if ((uint)*(byte *)psVar2 - 0x41 < 0x1a) {
      *(byte *)psVar2 = *(byte *)psVar2 + 0x20;
    }
    psVar2 = (short *)((int)psVar2 + 1);
    bVar1 = *(byte *)psVar2;
  }
  FONT_VaReallyPrint((char *)&roll_target,local_res4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_Print2(char *fmt /*stack 0*/)
 // line 1115, offset 0x8002d43c
	/* begin block 1 */
		// Start line: 1116
		// Start offset: 0x8002D43C
		// Variables:
	// 		void *ap; // $s0
	/* end block 1 */
	// End offset: 0x8002D43C
	// End Line: 1116

	/* begin block 2 */
		// Start line: 2060
	/* end block 2 */
	// End Line: 2061

void FONT_Print2(char *fmt)

{
  undefined local_res4 [12];
  
  vsprintf((char *)&roll_target,fmt,local_res4);
  FONT_VaReallyPrint((char *)&roll_target,local_res4);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ FONT_GetStringWidth(char *str /*$s3*/)
 // line 1168, offset 0x8002d48c
	/* begin block 1 */
		// Start line: 1169
		// Start offset: 0x8002D48C
		// Variables:
	// 		int w; // $s1
	// 		int len; // $s2
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8002D4E0
	// End Line: 1176

	/* begin block 2 */
		// Start line: 2336
	/* end block 2 */
	// End Line: 2337

int FONT_GetStringWidth(char *str)

{
  size_t sVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  
  sVar1 = strlen(str);
  iVar4 = 0;
  iVar5 = 0;
  pcVar2 = str;
  if (0 < (int)sVar1) {
    do {
      iVar4 = iVar4 + 1;
      lVar3 = FONT_CharSpacing(*pcVar2,8);
      iVar5 = iVar5 + lVar3;
      pcVar2 = str + iVar4;
    } while (iVar4 < (int)sVar1);
  }
  return iVar5;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_Flush()
 // line 1212, offset 0x8002d500
	/* begin block 1 */
		// Start line: 1213
		// Start offset: 0x8002D500
		// Variables:
	// 		long i; // $s1
	// 		struct FontChar *fontChar; // $s0
	/* end block 1 */
	// End offset: 0x8002D574
	// End Line: 1239

	/* begin block 2 */
		// Start line: 2424
	/* end block 2 */
	// End Line: 2425

/* WARNING: Unknown calling convention yet parameter storage is locked */

void FONT_Flush(void)

{
  FontChar *fontChar;
  int iVar1;
  
  DAT_800d0bec = 10;
  DAT_800d0bf0 = 0x10;
  if (DAT_800d0bf4 != 0) {
    fontChar = (FontChar *)&depthQBackColor;
    iVar1 = DAT_800d0bf4;
    do {
      if ((fontChar->c != ' ') && (fontChar->c != '@')) {
        FONT_DrawChar(fontChar);
      }
      iVar1 = iVar1 + -1;
      fontChar = fontChar + 1;
    } while (iVar1 != 0);
    DAT_800d0bf4 = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_SetCursor(short x /*$a0*/, short y /*$a1*/)
 // line 1241, offset 0x8002d590
	/* begin block 1 */
		// Start line: 2263
	/* end block 1 */
	// End Line: 2264

	/* begin block 2 */
		// Start line: 2267
	/* end block 2 */
	// End Line: 2268

void FONT_SetCursor(short x,short y)

{
  DAT_800d0bec = (int)x;
  DAT_800d0bf0 = (int)y;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_VaReallyPrint(char *fmt /*$a0*/, void *ap /*$a1*/)
 // line 1280, offset 0x8002d5b0
	/* begin block 1 */
		// Start line: 1281
		// Start offset: 0x8002D5B0
		// Variables:
	// 		char *p; // $s2
	// 		long *xpos; // $s3
	// 		long *ypos; // $s4

		/* begin block 1.1 */
			// Start line: 1302
			// Start offset: 0x8002D628
			// Variables:
		// 		unsigned char w; // $s0
		// 		unsigned char h; // $s1
		/* end block 1.1 */
		// End offset: 0x8002D628
		// End Line: 1304
	/* end block 1 */
	// End offset: 0x8002D710
	// End Line: 1334

	/* begin block 2 */
		// Start line: 2560
	/* end block 2 */
	// End Line: 2561

void FONT_VaReallyPrint(char *fmt,void *ap)

{
  byte bVar1;
  byte bVar2;
  long lVar3;
  
  bVar1 = *fmt;
  do {
    if (bVar1 == 0) {
      return;
    }
    if (bVar1 == 10) {
      DAT_800d0bf0 = DAT_800d0bf0 + 0xc;
      DAT_800d0bec = (uint)bVar1;
LAB_8002d6fc:
      fmt = (char *)((byte *)fmt + 1);
    }
    else {
      if (bVar1 != 0x40) {
        if (bVar1 == 0x24) {
          DAT_800d0bec = 10;
          DAT_800d0bf0 = 0x10;
        }
        else {
          if (bVar1 == 0xd) {
            DAT_800d0bec = 10;
          }
          else {
            if (bVar1 == 9) {
              DAT_800d0bec = DAT_800d0bec + 0x20;
            }
            else {
              if ((bVar1 == 0x20) || (bVar1 == 0x5f)) {
                DAT_800d0bec = DAT_800d0bec + 8;
              }
              else {
                FONT_AddCharToBuffer(*fmt,DAT_800d0bec,DAT_800d0bf0);
                lVar3 = FONT_CharSpacing(*fmt,8);
                DAT_800d0bec = DAT_800d0bec + lVar3;
              }
            }
          }
        }
        goto LAB_8002d6fc;
      }
      bVar1 = ((byte *)fmt)[1];
      bVar2 = ((byte *)fmt)[2];
      FONT_AddCharToBuffer('@',DAT_800d0bec,DAT_800d0bf0);
      FONT_AddCharToBuffer('@',(uint)bVar2 - 0x40 & 0xff,(uint)bVar1 - 0x40 & 0xff);
      fmt = (char *)((byte *)fmt + 3);
    }
    bVar1 = *fmt;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_FontPrintCentered(char *text /*$s1*/, long y /*$s0*/)
 // line 1336, offset 0x8002d740
	/* begin block 1 */
		// Start line: 2495
	/* end block 1 */
	// End Line: 2496

void FONT_FontPrintCentered(char *text,long y)

{
  int iVar1;
  
  iVar1 = FONT_GetStringWidth(text);
  FONT_SetCursor((short)((uint)((0x100 - (iVar1 >> 1)) * 0x10000) >> 0x10),(short)y);
  FONT_Print2(text);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_SetColorIndex(int color /*$a0*/)
 // line 1343, offset 0x8002d798
	/* begin block 1 */
		// Start line: 2509
	/* end block 1 */
	// End Line: 2510

	/* begin block 2 */
		// Start line: 2511
	/* end block 2 */
	// End Line: 2512

void FONT_SetColorIndex(int color)

{
  DAT_800d0c08 = (char)color;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_SetColorIndexCol(int color /*$a0*/, int r /*$a1*/, int g /*$a2*/, int b /*$a3*/)
 // line 1349, offset 0x8002d7a4
	/* begin block 1 */
		// Start line: 1351
		// Start offset: 0x8002D7A4
		// Variables:
	// 		struct font_color_t *fcol; // $v0
	/* end block 1 */
	// End offset: 0x8002D7A4
	// End Line: 1354

	/* begin block 2 */
		// Start line: 2521
	/* end block 2 */
	// End Line: 2522

	/* begin block 3 */
		// Start line: 2522
	/* end block 3 */
	// End Line: 2523

	/* begin block 4 */
		// Start line: 2525
	/* end block 4 */
	// End Line: 2526

void FONT_SetColorIndexCol(int color,int r,int g,int b)

{
  the_font_color_table[color].r = r;
  the_font_color_table[color].g = g;
  the_font_color_table[color].b = b;
  return;
}





