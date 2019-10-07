#include "THISDUST.H"
#include "FONT.H"


// decompiled code
// original method signature: 
// void /*$ra*/ FONT_MakeSpecialFogClut(int x /*$a3*/, int y /*$a1*/)
 // line 58, offset 0x8002ca94
	/* begin block 1 */
		// Start line: 59
		// Start offset: 0x8002CA94
		// Variables:
	// 		int n; // $a0
	// 		unsigned short cl[16]; // stack offset -48
	// 		struct RECT myrect; // stack offset -16
	/* end block 1 */
	// End offset: 0x8002CABC
	// End Line: 69

	/* begin block 2 */
		// Start line: 116
	/* end block 2 */
	// End Line: 117

void FONT_MakeSpecialFogClut(int x,int y)

{
  undefined2 *puVar1;
  int iVar2;
  undefined2 local_30 [15];
  undefined2 local_12;
  undefined4 local_10;
  undefined2 local_c;
  undefined2 local_a;
  
  iVar2 = 0xf;
  puVar1 = &local_12;
  do {
    *puVar1 = 0x4210;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + -1;
  } while (-1 < iVar2);
  local_c = 0x10;
  local_a = 1;
  SpecialFogClut = (ushort)(y << 6) | (ushort)(x >> 4) & 0x3f;
  local_30[0] = 0;
  local_10._0_2_ = (undefined2)x;
  local_10._2_2_ = (undefined2)y;
  DrawSync(0);
  LoadImage(&local_10,local_30);
  DrawSync(0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_Init()
 // line 89, offset 0x8002cb18
	/* begin block 1 */
		// Start line: 90
		// Start offset: 0x8002CB18
		// Variables:
	// 		unsigned long *timAddr; // $s0
	// 		short x; // stack offset -16
	// 		short y; // stack offset -14
	/* end block 1 */
	// End offset: 0x8002CC08
	// End Line: 124

	/* begin block 2 */
		// Start line: 184
	/* end block 2 */
	// End Line: 185

/* WARNING: Unknown calling convention yet parameter storage is locked */

void FONT_Init(void)

{
  long *addr;
  ushort local_10;
  ushort local_e [3];
  
  FONT_vramBlock = VRAM_CheckVramSlot((short *)&local_10,(short *)local_e,0x10,0x80,3,-1);
  if (FONT_vramBlock != (_BlockVramEntry *)0x0) {
    addr = LOAD_ReadFile("\\kain2\\game\\font.tim",'\x05');
    LOAD_LoadTIM(addr,(int)(short)local_10,(int)(short)local_e[0],(int)(short)local_10,
                 (int)(short)local_e[0] + 0x7e);
    MEMPACK_Free((char *)addr);
    fontTracker.sprite_sort_push = 0;
    fontTracker.font_tpage =
         (short)(local_e[0] & 0x100) >> 4 | (ushort)(((u_int)local_10 & 0x3ff) >> 6) |
         (ushort)(((u_int)local_e[0] & 0x200) << 2);
    fontTracker.font_clut = (local_e[0] + 0x7e) * 0x40 | (short)local_10 >> 4 & 0x3fU;
    fontTracker.font_vramX = local_10;
    fontTracker.font_vramY = local_e[0];
    fontTracker.font_vramV = local_e[0] & 0xff;
    fontTracker.font_vramU = (short)(((u_int)local_10 & 0x3f) << 2);
    FONT_MakeSpecialFogClut((int)(short)local_10,(int)(short)local_e[0] + 0x7f);
  }
  fontTracker.font_xpos = 10;
  fontTracker.font_ypos = 0x10;
  fontTracker.font_buffIndex = 0;
  fontTracker.sprite_sort_push = 0;
  fontTracker.color_global = '\0';
  fontTracker.color_local = '\0';
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_ReloadFont()
 // line 135, offset 0x8002cc38
	/* begin block 1 */
		// Start line: 136
		// Start offset: 0x8002CC38
		// Variables:
	// 		unsigned long *timAddr; // $s0
	/* end block 1 */
	// End offset: 0x8002CC38
	// End Line: 136

	/* begin block 2 */
		// Start line: 314
	/* end block 2 */
	// End Line: 315

/* WARNING: Unknown calling convention yet parameter storage is locked */

void FONT_ReloadFont(void)

{
  long *addr;
  
  addr = LOAD_ReadFile("\\kain2\\game\\font.tim",'\x05');
  LOAD_LoadTIM(addr,(int)fontTracker.font_vramX,(int)fontTracker.font_vramY,
               (int)fontTracker.font_vramX,(int)fontTracker.font_vramY + 0x7e);
  MEMPACK_Free((char *)addr);
  FONT_MakeSpecialFogClut((int)fontTracker.font_vramX,(int)fontTracker.font_vramY + 0x7f);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_DrawChar(struct FontChar *fontChar /*$a0*/)
 // line 147, offset 0x8002cc9c
	/* begin block 1 */
		// Start line: 148
		// Start offset: 0x8002CC9C
		// Variables:
	// 		char c; // $v1
	// 		long x; // $a1
	// 		long y; // $a2
	/* end block 1 */
	// End offset: 0x8002CC9C
	// End Line: 148

	/* begin block 2 */
		// Start line: 342
	/* end block 2 */
	// End Line: 343

void FONT_DrawChar(FontChar *fontChar)

{
  fontTracker.color_local = fontChar->color;
  FONT_DrawChar2D(fontChar->c,(int)fontChar->x,(int)fontChar->y);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ FONT_Get2DImageIndex(unsigned char c /*$a0*/)
 // line 469, offset 0x8002ccd0
	/* begin block 1 */
		// Start line: 990
	/* end block 1 */
	// End Line: 991

	/* begin block 2 */
		// Start line: 1055
	/* end block 2 */
	// End Line: 1056

long FONT_Get2DImageIndex(u_char c)

{
  return (u_int)
               "$$$$$$$$$$$$$$$$$VWXYZ[$$$$$$$$$$%($$)$3+,/-2\'$&\x1a\x1b\x1c\x1d\x1e\x1f !\"#*$U.T0$456789:;<=>?@ABCDEFGHIJKLMN$OR$$"
               [c];
}



// decompiled code
// original method signature: 
// void /*$ra*/ drawChar2DPoly(long fpi /*$a0*/, long x /*$s1*/, long y /*$s0*/)
 // line 556, offset 0x8002ccec
	/* begin block 1 */
		// Start line: 557
		// Start offset: 0x8002CCEC
		// Variables:
	// 		unsigned long **drawOT; // $s2
	// 		struct POLY_FT4 *textPoly; // $a3
	// 		long xl; // $t8
	// 		long xr; // $s1
	// 		long yt; // $a2
	// 		long yb; // $s0
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
			// Start line: 604
			// Start offset: 0x8002CDA0
		/* end block 1.1 */
		// End offset: 0x8002CDB0
		// End Line: 613

		/* begin block 1.2 */
			// Start line: 616
			// Start offset: 0x8002CDB8
			// Variables:
		// 		int holdu; // $v0
		// 		int holdv; // $v1
		/* end block 1.2 */
		// End offset: 0x8002CDE8
		// End Line: 625

		/* begin block 1.3 */
			// Start line: 634
			// Start offset: 0x8002CE14
			// Variables:
		// 		struct font_color_t *color; // $v1
		/* end block 1.3 */
		// End offset: 0x8002CE58
		// End Line: 637
	/* end block 1 */
	// End offset: 0x8002CE58
	// End Line: 638

	/* begin block 2 */
		// Start line: 1107
	/* end block 2 */
	// End Line: 1108

void drawChar2DPoly(long fpi,long x,long y)

{
  char cVar1;
  char cVar2;
  short sVar3;
  u_long **ppuVar4;
  u_int uVar5;
  short sVar6;
  u_long *puVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  short sVar13;
  short sVar14;
  
  ppuVar4 = gameTrackerX.drawOT;
  cVar11 = (&fontPos)[fpi].x;
  if (cVar11 < '\0') {
    cVar11 = -cVar11;
  }
  cVar10 = (&fontPos)[fpi].y;
  if (cVar10 < '\0') {
    cVar10 = -cVar10;
  }
  cVar1 = (&fontPos)[fpi].w;
  sVar14 = (short)cVar1;
  cVar2 = (&fontPos)[fpi].h;
  sVar6 = (short)cVar2;
  cVar11 = cVar11 + (char)fontTracker.font_vramU;
  cVar10 = cVar10 + (char)fontTracker.font_vramV;
  if (cVar1 < '\0') {
    sVar14 = -(short)cVar1;
  }
  cVar12 = cVar11 + (char)sVar14;
  if (cVar2 < '\0') {
    sVar6 = -(short)cVar2;
  }
  cVar8 = cVar10 + (char)sVar6;
  sVar3 = (short)x;
  sVar6 = (short)y - (sVar6 + -0xc);
  puVar7 = (gameTrackerX.primPool)->nextPrim;
  sVar13 = (short)y + 0xc;
  cVar9 = cVar10;
  if (cVar2 < '\0') {
    cVar9 = cVar8;
    cVar8 = cVar10;
  }
  cVar10 = cVar11;
  if (cVar1 < '\0') {
    cVar10 = cVar12;
    cVar12 = cVar11;
  }
  *(undefined *)((int)puVar7 + 3) = 9;
  *(undefined *)((int)puVar7 + 7) = 0x2c;
  if (fontTracker.color_local == '\0') {
    *(undefined *)((int)puVar7 + 7) = 0x2d;
  }
  else {
    uVar5 = (u_int)(byte)fontTracker.color_local;
    *(undefined *)((int)puVar7 + 7) = 0x2c;
    *(undefined *)(puVar7 + 1) = *(undefined *)&(&the_font_color_table)[uVar5].r;
    *(undefined *)((int)puVar7 + 5) = *(undefined *)&(&the_font_color_table)[uVar5].g;
    *(undefined *)((int)puVar7 + 6) = *(undefined *)&(&the_font_color_table)[uVar5].b;
  }
  *(char *)(puVar7 + 3) = cVar10;
  *(char *)((int)puVar7 + 0xd) = cVar9;
  *(char *)(puVar7 + 5) = cVar12;
  *(char *)((int)puVar7 + 0x15) = cVar9;
  *(char *)(puVar7 + 7) = cVar10;
  *(char *)((int)puVar7 + 0x1d) = cVar8;
  *(char *)(puVar7 + 9) = cVar12;
  *(char *)((int)puVar7 + 0x25) = cVar8;
  *(short *)(puVar7 + 2) = sVar3;
  *(short *)((int)puVar7 + 10) = sVar6;
  *(short *)(puVar7 + 4) = sVar3 + sVar14;
  *(short *)((int)puVar7 + 0x12) = sVar6;
  *(short *)(puVar7 + 6) = sVar3;
  *(short *)((int)puVar7 + 0x1a) = sVar13;
  *(short *)(puVar7 + 8) = sVar3 + sVar14;
  *(short *)((int)puVar7 + 0x22) = sVar13;
  *(byte *)((int)puVar7 + 7) = *(byte *)((int)puVar7 + 7) & 0xfd;
  *(short *)((int)puVar7 + 0x16) = fontTracker.font_tpage;
  *(short *)((int)puVar7 + 0xe) = fontTracker.font_clut;
  *puVar7 = (u_int)*ppuVar4 & 0xffffff | 0x9000000;
  *ppuVar4 = (u_long *)((u_int)puVar7 & 0xffffff);
  (gameTrackerX.primPool)->nextPrim = puVar7 + 10;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_DrawChar2D(unsigned char c /*$fp*/, long x /*$s7*/, long y /*$s3*/)
 // line 658, offset 0x8002cef8
	/* begin block 1 */
		// Start line: 659
		// Start offset: 0x8002CEF8
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
	// End offset: 0x8002D0FC
	// End Line: 700

	/* begin block 2 */
		// Start line: 1434
	/* end block 2 */
	// End Line: 1435

	/* begin block 3 */
		// Start line: 1439
	/* end block 3 */
	// End Line: 1440

void FONT_DrawChar2D(u_char c,long x,long y)

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
  
  if ((gameTrackerX.primPool)->nextPrim <= (gameTrackerX.primPool)->lastPrim + -0xc) {
    y_00 = FONT_Get2DImageIndex(c);
    fpi_01 = y_00 * 3;
    fpi = (int)""[fpi_01];
    fpi_00 = (int)(&CHAR_FFh_800c8d81)[fpi_01];
    fpi_01 = (int)(&CHAR_FFh_800c8d82)[fpi_01];
    if (fpi < 0) {
      iVar1 = 8;
    }
    else {
      iVar1 = (int)(&fontPos)[fpi].w;
      if (iVar1 < 0) {
        iVar1 = -iVar1;
      }
    }
    iVar2 = iVar1;
    if ((-1 < fpi_00) && (iVar2 = (int)(&fontPos)[fpi_00].w, iVar2 < 0)) {
      iVar2 = -iVar2;
    }
    iVar3 = iVar1;
    if ((-1 < fpi_01) && (iVar3 = (int)(&fontPos)[fpi_01].w, iVar3 < 0)) {
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
      iVar4 = (int)(&fontPos)[fpi].h;
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
      drawChar2DPoly(fpi_01,x + (iVar5 - iVar3) / 2,(y - iVar4) + -1);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ FONT_CharSpacing(char c /*$a0*/, long fontXSize /*$s0*/)
 // line 702, offset 0x8002d12c
	/* begin block 1 */
		// Start line: 703
		// Start offset: 0x8002D12C
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
			// Start line: 715
			// Start offset: 0x8002D160
			// Variables:
		// 		int holdw; // $a0
		// 		int holdw2; // $a0
		/* end block 1.1 */
		// End offset: 0x8002D25C
		// End Line: 739
	/* end block 1 */
	// End offset: 0x8002D260
	// End Line: 744

	/* begin block 2 */
		// Start line: 1527
	/* end block 2 */
	// End Line: 1528

long FONT_CharSpacing(char c,long fontXSize)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if ((c != ' ') && (lVar2 = FONT_Get2DImageIndex(c), lVar2 != -1)) {
    iVar1 = lVar2 * 3;
    iVar3 = (int)""[iVar1];
    iVar5 = (int)(&fontPos)[iVar3].w;
    if (iVar5 < 0) {
      iVar5 = -iVar5;
    }
    if ((&fontPos)[iVar3].x < '\0') {
      iVar5 = (int)(&fontPos)[iVar3].h;
    }
    iVar3 = 8;
    if (-1 < (int)((u_int)(byte)""[iVar1] << 0x18)) {
      iVar3 = iVar5;
    }
    iVar5 = (int)(&fontPos)[(int)(&CHAR_FFh_800c8d81)[iVar1]].w;
    if (iVar5 < 0) {
      iVar5 = -iVar5;
    }
    iVar6 = iVar3;
    if (-1 < (int)(&CHAR_FFh_800c8d81)[iVar1]) {
      iVar6 = iVar5;
    }
    iVar5 = (int)(&fontPos)[(int)(&CHAR_FFh_800c8d82)[iVar1]].w;
    if (iVar5 < 0) {
      iVar5 = -iVar5;
    }
    iVar4 = iVar3;
    if (-1 < (int)(&CHAR_FFh_800c8d82)[iVar1]) {
      iVar4 = iVar5;
    }
    if (iVar6 < iVar3) {
      iVar6 = iVar3;
    }
    fontXSize = iVar4 + 1;
    if (iVar4 < iVar6) {
      fontXSize = iVar6 + 1;
    }
  }
  return fontXSize;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_AddCharToBuffer(char c /*$a3*/, long x /*$a1*/, long y /*$a2*/)
 // line 1057, offset 0x8002d270
	/* begin block 1 */
		// Start line: 1058
		// Start offset: 0x8002D270
		// Variables:
	// 		struct FontChar *fontChar; // $a0
	/* end block 1 */
	// End offset: 0x8002D2D8
	// End Line: 1077

	/* begin block 2 */
		// Start line: 2111
	/* end block 2 */
	// End Line: 2112

void FONT_AddCharToBuffer(char c,long x,long y)

{
  long lVar1;
  
  lVar1 = fontTracker.font_buffIndex;
  if (fontTracker.font_buffIndex < 0xff) {
    if (c == '@') {
      fontTracker.font_buffer[fontTracker.font_buffIndex].x = (ushort)x & 0xff;
      fontTracker.font_buffer[lVar1].y = (ushort)y & 0xff;
    }
    else {
      fontTracker.font_buffer[fontTracker.font_buffIndex].x = (ushort)x;
      fontTracker.font_buffer[lVar1].y = (ushort)y;
    }
    fontTracker.font_buffer[lVar1].c = c;
    fontTracker.font_buffIndex = fontTracker.font_buffIndex + 1;
    fontTracker.font_buffer[lVar1].color = fontTracker.color_global;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_Print(char *fmt /*stack 0*/)
 // line 1094, offset 0x8002d2e0
	/* begin block 1 */
		// Start line: 1095
		// Start offset: 0x8002D2E0
		// Variables:
	// 		char *hold; // $v1
	// 		void *ap; // $s0
	/* end block 1 */
	// End offset: 0x8002D35C
	// End Line: 1109

	/* begin block 2 */
		// Start line: 2003
	/* end block 2 */
	// End Line: 2004

void FONT_Print(char *fmt)

{
  byte bVar1;
  char *pcVar2;
  undefined local_res4 [12];
  
  vsprintf(&fp_str,fmt,local_res4);
  pcVar2 = &fp_str;
  bVar1 = fp_str;
  while (bVar1 != 0) {
    if ((u_int)(byte)*pcVar2 - 0x41 < 0x1a) {
      *pcVar2 = *pcVar2 + 0x20;
    }
    pcVar2 = (char *)((byte *)pcVar2 + 1);
    bVar1 = *pcVar2;
  }
  FONT_VaReallyPrint(&fp_str,local_res4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_Print2(char *fmt /*stack 0*/)
 // line 1113, offset 0x8002d37c
	/* begin block 1 */
		// Start line: 1114
		// Start offset: 0x8002D37C
		// Variables:
	// 		void *ap; // $s0
	/* end block 1 */
	// End offset: 0x8002D37C
	// End Line: 1114

	/* begin block 2 */
		// Start line: 2056
	/* end block 2 */
	// End Line: 2057

void FONT_Print2(char *fmt)

{
  undefined local_res4 [12];
  
  vsprintf(&fp_str,fmt,local_res4);
  FONT_VaReallyPrint(&fp_str,local_res4);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ FONT_GetStringWidth(char *str /*$s3*/)
 // line 1166, offset 0x8002d3d4
	/* begin block 1 */
		// Start line: 1167
		// Start offset: 0x8002D3D4
		// Variables:
	// 		int w; // $s1
	// 		int len; // $s2
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8002D428
	// End Line: 1174

	/* begin block 2 */
		// Start line: 2329
	/* end block 2 */
	// End Line: 2330

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
 // line 1210, offset 0x8002d448
	/* begin block 1 */
		// Start line: 1211
		// Start offset: 0x8002D448
		// Variables:
	// 		long i; // $s1
	// 		struct FontChar *fontChar; // $s0
	/* end block 1 */
	// End offset: 0x8002D4C0
	// End Line: 1237

	/* begin block 2 */
		// Start line: 2416
	/* end block 2 */
	// End Line: 2417

/* WARNING: Unknown calling convention yet parameter storage is locked */

void FONT_Flush(void)

{
  FontTracker *fontChar;
  long lVar1;
  
  fontTracker.font_xpos = 10;
  fontTracker.font_ypos = 0x10;
  if (fontTracker.font_buffIndex != 0) {
    fontChar = &fontTracker;
    lVar1 = fontTracker.font_buffIndex;
    do {
      if ((*(char *)fontChar->font_buffer != ' ') && (*(char *)fontChar->font_buffer != '@')) {
        FONT_DrawChar((FontChar *)fontChar);
      }
      lVar1 = lVar1 + -1;
      fontChar = (FontTracker *)(fontChar->font_buffer + 1);
    } while (lVar1 != 0);
    fontTracker.font_buffIndex = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_SetCursor(short x /*$a0*/, short y /*$a1*/)
 // line 1239, offset 0x8002d4dc
	/* begin block 1 */
		// Start line: 2259
	/* end block 1 */
	// End Line: 2260

	/* begin block 2 */
		// Start line: 2263
	/* end block 2 */
	// End Line: 2264

void FONT_SetCursor(short x,short y)

{
  fontTracker.font_xpos = (int)x;
  fontTracker.font_ypos = (int)y;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_VaReallyPrint(char *fmt /*$a0*/, void *ap /*$a1*/)
 // line 1278, offset 0x8002d4fc
	/* begin block 1 */
		// Start line: 1279
		// Start offset: 0x8002D4FC
		// Variables:
	// 		char *p; // $s2
	// 		long *xpos; // $s3
	// 		long *ypos; // $s4

		/* begin block 1.1 */
			// Start line: 1300
			// Start offset: 0x8002D57C
			// Variables:
		// 		unsigned char w; // $s0
		// 		unsigned char h; // $s1
		/* end block 1.1 */
		// End offset: 0x8002D57C
		// End Line: 1302
	/* end block 1 */
	// End offset: 0x8002D664
	// End Line: 1332

	/* begin block 2 */
		// Start line: 2552
	/* end block 2 */
	// End Line: 2553

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
      fontTracker.font_ypos = fontTracker.font_ypos + 0xc;
      fontTracker.font_xpos = (u_int)bVar1;
LAB_8002d650:
      fmt = (char *)((byte *)fmt + 1);
    }
    else {
      if (bVar1 != 0x40) {
        if (bVar1 == 0x24) {
          fontTracker.font_xpos = 10;
          fontTracker.font_ypos = 0x10;
        }
        else {
          if (bVar1 == 0xd) {
            fontTracker.font_xpos = 10;
          }
          else {
            if (bVar1 == 9) {
              fontTracker.font_xpos = fontTracker.font_xpos + 0x20;
            }
            else {
              if ((bVar1 == 0x20) || (bVar1 == 0x5f)) {
                fontTracker.font_xpos = fontTracker.font_xpos + 8;
              }
              else {
                FONT_AddCharToBuffer(*fmt,fontTracker.font_xpos,fontTracker.font_ypos);
                lVar3 = FONT_CharSpacing(*fmt,8);
                fontTracker.font_xpos = fontTracker.font_xpos + lVar3;
              }
            }
          }
        }
        goto LAB_8002d650;
      }
      bVar1 = ((byte *)fmt)[1];
      bVar2 = ((byte *)fmt)[2];
      FONT_AddCharToBuffer('@',fontTracker.font_xpos,fontTracker.font_ypos);
      FONT_AddCharToBuffer('@',(u_int)bVar2 - 0x40 & 0xff,(u_int)bVar1 - 0x40 & 0xff);
      fmt = (char *)((byte *)fmt + 3);
    }
    bVar1 = *fmt;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_FontPrintCentered(char *text /*$s1*/, long y /*$s0*/)
 // line 1334, offset 0x8002d694
	/* begin block 1 */
		// Start line: 2491
	/* end block 1 */
	// End Line: 2492

void FONT_FontPrintCentered(char *text,long y)

{
  int iVar1;
  
  iVar1 = FONT_GetStringWidth(text);
  FONT_SetCursor((short)((u_int)((0x100 - (iVar1 >> 1)) * 0x10000) >> 0x10),(short)y);
  FONT_Print2(text);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FONT_SetColorIndex(int color /*$a0*/)
 // line 1341, offset 0x8002d6ec
	/* begin block 1 */
		// Start line: 2505
	/* end block 1 */
	// End Line: 2506

	/* begin block 2 */
		// Start line: 2507
	/* end block 2 */
	// End Line: 2508

void FONT_SetColorIndex(int color)

{
  fontTracker.color_global = (char)color;
  return;
}





