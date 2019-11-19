#include "THISDUST.H"
#include "VRAM.H"


// decompiled code
// original method signature: 
// void /*$ra*/ VRAM_PrintVramBlock(struct _BlockVramEntry *vblock /*$v1*/)
 // line 75, offset 0x800720d0
	/* begin block 1 */
		// Start line: 150
	/* end block 1 */
	// End Line: 151

void VRAM_PrintVramBlock(_BlockVramEntry *vblock)

{
  char *fmt;
  
  if (vblock->type == '\x02') {
    fmt = "xywh (%d,%d,%d,%d) Object=%s\n";
  }
  else {
    if (vblock->type == '\x01') {
      fmt = "xywh (%d,%d,%d,%d) Level\n";
    }
    else {
      fmt = "xywh (%d,%d,%d,%d)\n";
    }
  }
  GXFilePrint(fmt);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VRAM_PrintInfo()
 // line 110, offset 0x80072174
	/* begin block 1 */
		// Start line: 111
		// Start offset: 0x80072174
		// Variables:
	// 		struct _BlockVramEntry *vblock; // $s0
	/* end block 1 */
	// End offset: 0x800722AC
	// End Line: 148

	/* begin block 2 */
		// Start line: 217
	/* end block 2 */
	// End Line: 218

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_PrintInfo(void)

{
  _BlockVramEntry *p_Var1;
  
  GXFilePrint("Used Vram Blocks\n--------------\n");
  p_Var1 = usedVramBlocks;
  while (p_Var1 != (_BlockVramEntry *)0x0) {
    GXFilePrint("xywh (%4d,%4d,%4d,%4d) %6d bytes");
    if (p_Var1->type == '\x02') {
      GXFilePrint(" Object=%s\n");
    }
    else {
      if (p_Var1->type == '\x01') {
        GXFilePrint(" Level = %s\n");
      }
      else {
        GXFilePrint("\n");
      }
    }
    p_Var1 = p_Var1->next;
  }
  GXFilePrint("\nOpen Vram Blocks\n--------------\n");
  p_Var1 = openVramBlocks;
  while (p_Var1 != (_BlockVramEntry *)0x0) {
    GXFilePrint("xywh (%4d,%4d,%4d,%4d) %6d bytes\n");
    p_Var1 = p_Var1->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VRAM_InitVramBlockCache()
 // line 153, offset 0x800722bc
	/* begin block 1 */
		// Start line: 154
		// Start offset: 0x800722BC
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x800722EC
	// End Line: 179

	/* begin block 2 */
		// Start line: 289
	/* end block 2 */
	// End Line: 290

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_InitVramBlockCache(void)

{
  _BlockVramEntry *p_Var1;
  int iVar2;
  
  iVar2 = 0x4a;
  p_Var1 = &_BlockVramEntry_800d4c58;
  openVramBlocks = (_BlockVramEntry *)0x0;
  usedVramBlocks = (_BlockVramEntry *)0x0;
  numOfBlocksUsed = 0;
  do {
    p_Var1->flags = '\0';
    iVar2 = iVar2 + -1;
    p_Var1 = p_Var1 + -1;
  } while (-1 < iVar2);
  VRAM_InsertFreeVram(0x200,0x100,0x200,0x100,1);
  VRAM_InitMorphPalettes();
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ VRAM_ConcatanateMemory(struct _BlockVramEntry *curBlock /*$s1*/)
 // line 185, offset 0x80072320
	/* begin block 1 */
		// Start line: 186
		// Start offset: 0x80072320
		// Variables:
	// 		struct _BlockVramEntry *nextBlock; // $s0
	/* end block 1 */
	// End offset: 0x800724F4
	// End Line: 251

	/* begin block 2 */
		// Start line: 363
	/* end block 2 */
	// End Line: 364

int VRAM_ConcatanateMemory(_BlockVramEntry *curBlock)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  _BlockVramEntry *block;
  
  if (curBlock != (_BlockVramEntry *)0x0) {
    do {
      block = curBlock->next;
      while (block != (_BlockVramEntry *)0x0) {
        if ((curBlock->x == block->x) && (curBlock->w == block->w)) {
          iVar2 = (uint)(ushort)curBlock->y << 0x10;
          iVar4 = iVar2 >> 0x10;
          iVar1 = (uint)(ushort)block->y << 0x10;
          iVar3 = iVar1 >> 0x10;
          if (iVar2 >> 0x18 == iVar1 >> 0x18) {
            if (iVar4 + curBlock->h == iVar3) {
              curBlock->h = curBlock->h + block->h;
              goto LAB_80072458;
            }
            if (iVar3 + block->h == iVar4) {
              block->h = block->h + curBlock->h;
              goto LAB_800724bc;
            }
          }
        }
        if ((curBlock->y == block->y) && (curBlock->h == block->h)) {
          if (((int)curBlock->x + (int)curBlock->w == (int)block->x) &&
             (((curBlock->x & 0x3fU) == 0 || ((int)curBlock->w + (int)block->w < 0x41)))) {
            curBlock->w = curBlock->w + block->w;
LAB_80072458:
            VRAM_DeleteFreeBlock(block);
            block->flags = '\0';
            return 1;
          }
          if (((int)block->x + (int)block->w == (int)curBlock->x) &&
             (((block->x & 0x3fU) == 0 || ((int)curBlock->w + (int)block->w < 0x41)))) {
            block->w = block->w + curBlock->w;
LAB_800724bc:
            VRAM_DeleteFreeBlock(curBlock);
            curBlock->flags = '\0';
            return 1;
          }
        }
        block = block->next;
      }
      curBlock = curBlock->next;
    } while (curBlock != (_BlockVramEntry *)0x0);
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VRAM_GarbageCollect()
 // line 253, offset 0x80072508
	/* begin block 1 */
		// Start line: 502
	/* end block 1 */
	// End Line: 503

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_GarbageCollect(void)

{
  int iVar1;
  
  do {
    iVar1 = VRAM_ConcatanateMemory(openVramBlocks);
  } while (iVar1 == 1);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ VRAM_InsertFreeBlock(struct _BlockVramEntry *block /*$a0*/)
 // line 260, offset 0x8007253c
	/* begin block 1 */
		// Start line: 261
		// Start offset: 0x8007253C
		// Variables:
	// 		struct _BlockVramEntry *next; // $v1
	// 		struct _BlockVramEntry *prev; // $a1
	/* end block 1 */
	// End offset: 0x800725BC
	// End Line: 291

	/* begin block 2 */
		// Start line: 517
	/* end block 2 */
	// End Line: 518

int VRAM_InsertFreeBlock(_BlockVramEntry *block)

{
  int iVar1;
  _BlockVramEntry *p_Var2;
  _BlockVramEntry *p_Var3;
  _BlockVramEntry *p_Var4;
  
  if (block == (_BlockVramEntry *)0x0) {
    iVar1 = 0;
  }
  else {
    p_Var3 = openVramBlocks;
    p_Var4 = (_BlockVramEntry *)0x0;
    if (openVramBlocks != (_BlockVramEntry *)0x0) {
      do {
        p_Var2 = p_Var3;
        p_Var3 = p_Var2;
        if (block->area <= p_Var2->area) break;
        p_Var3 = p_Var2->next;
        p_Var4 = p_Var2;
      } while (p_Var3 != (_BlockVramEntry *)0x0);
    }
    if (p_Var4 == (_BlockVramEntry *)0x0) {
      p_Var3 = block;
      block->next = openVramBlocks;
      openVramBlocks = p_Var3;
    }
    else {
      block->next = p_Var3;
      p_Var4->next = block;
    }
    VRAM_GarbageCollect();
    iVar1 = 1;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VRAM_DeleteFreeBlock(struct _BlockVramEntry *block /*$a0*/)
 // line 294, offset 0x800725cc
	/* begin block 1 */
		// Start line: 296
		// Start offset: 0x800725CC
		// Variables:
	// 		struct _BlockVramEntry *next; // $v1
	// 		struct _BlockVramEntry *prev; // $a1
	/* end block 1 */
	// End offset: 0x8007262C
	// End Line: 320

	/* begin block 2 */
		// Start line: 586
	/* end block 2 */
	// End Line: 587

	/* begin block 3 */
		// Start line: 587
	/* end block 3 */
	// End Line: 588

	/* begin block 4 */
		// Start line: 588
	/* end block 4 */
	// End Line: 589

void VRAM_DeleteFreeBlock(_BlockVramEntry *block)

{
  _BlockVramEntry *p_Var1;
  _BlockVramEntry *p_Var2;
  _BlockVramEntry *p_Var3;
  
  p_Var3 = (_BlockVramEntry *)0x0;
  if (block != (_BlockVramEntry *)0x0) {
    p_Var2 = openVramBlocks;
    if (block != openVramBlocks) {
      do {
        p_Var1 = p_Var2;
        p_Var2 = p_Var1;
        if (p_Var1 == (_BlockVramEntry *)0x0) break;
        p_Var2 = p_Var1->next;
        p_Var3 = p_Var1;
      } while (block != p_Var2);
      if (block != p_Var2) {
        return;
      }
    }
    if (p_Var3 != (_BlockVramEntry *)0x0) {
      p_Var3->next = block->next;
      return;
    }
    openVramBlocks = block->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VRAM_InsertUsedBlock(struct _BlockVramEntry *block /*$a0*/)
 // line 323, offset 0x80072634
	/* begin block 1 */
		// Start line: 644
	/* end block 1 */
	// End Line: 645

	/* begin block 2 */
		// Start line: 645
	/* end block 2 */
	// End Line: 646

void VRAM_InsertUsedBlock(_BlockVramEntry *block)

{
  if (block != (_BlockVramEntry *)0x0) {
    if (usedVramBlocks == (_BlockVramEntry *)0x0) {
      usedVramBlocks = block;
      return;
    }
    block->next = usedVramBlocks;
    usedVramBlocks = block;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VRAM_DeleteUsedBlock(struct _BlockVramEntry *block /*$a0*/)
 // line 339, offset 0x80072668
	/* begin block 1 */
		// Start line: 341
		// Start offset: 0x80072668
		// Variables:
	// 		struct _BlockVramEntry *next; // $v1
	// 		struct _BlockVramEntry *prev; // $a1
	/* end block 1 */
	// End offset: 0x800726C4
	// End Line: 362

	/* begin block 2 */
		// Start line: 676
	/* end block 2 */
	// End Line: 677

	/* begin block 3 */
		// Start line: 677
	/* end block 3 */
	// End Line: 678

	/* begin block 4 */
		// Start line: 679
	/* end block 4 */
	// End Line: 680

void VRAM_DeleteUsedBlock(_BlockVramEntry *block)

{
  _BlockVramEntry *p_Var1;
  _BlockVramEntry *p_Var2;
  _BlockVramEntry *p_Var3;
  
  p_Var3 = (_BlockVramEntry *)0x0;
  p_Var2 = usedVramBlocks;
  if (block != usedVramBlocks) {
    do {
      p_Var1 = p_Var2;
      p_Var2 = p_Var1;
      if (p_Var1 == (_BlockVramEntry *)0x0) break;
      p_Var2 = p_Var1->next;
      p_Var3 = p_Var1;
    } while (block != p_Var2);
    if (block != p_Var2) {
      return;
    }
  }
  if (p_Var3 != (_BlockVramEntry *)0x0) {
    p_Var3->next = block->next;
    return;
  }
  usedVramBlocks = block->next;
  return;
}



// decompiled code
// original method signature: 
// struct _BlockVramEntry * /*$ra*/ VRAM_GetOpenBlock()
 // line 364, offset 0x800726cc
	/* begin block 1 */
		// Start line: 365
		// Start offset: 0x800726CC
		// Variables:
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x80072718
	// End Line: 379

	/* begin block 2 */
		// Start line: 728
	/* end block 2 */
	// End Line: 729

/* WARNING: Unknown calling convention yet parameter storage is locked */

_BlockVramEntry * VRAM_GetOpenBlock(void)

{
  _BlockVramEntry *p_Var1;
  int iVar2;
  
  iVar2 = 0;
  p_Var1 = &vramBlockList;
  do {
    iVar2 = iVar2 + 1;
    if (p_Var1->flags == '\0') {
      return p_Var1;
    }
    p_Var1 = p_Var1 + 1;
  } while (iVar2 < 0x4b);
  GXFilePrint("Ran out of vram blocks. Need to increase MAX_VRAM_BLOCKS=%d\n");
  return (_BlockVramEntry *)0x0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ VRAM_InsertFreeVram(short x /*stack -48*/, short y /*stack -46*/, short w /*$s7*/, short h /*$fp*/, int flags /*stack 16*/)
 // line 381, offset 0x80072728
	/* begin block 1 */
		// Start line: 382
		// Start offset: 0x80072728
		// Variables:
	// 		struct _BlockVramEntry *useBlock; // $a0
	/* end block 1 */
	// End offset: 0x80072894
	// End Line: 430

	/* begin block 2 */
		// Start line: 766
	/* end block 2 */
	// End Line: 767

int VRAM_InsertFreeVram(short x,short y,short w,short h,int flags)

{
  short sVar1;
  _BlockVramEntry *block;
  uchar uVar2;
  long lVar3;
  
  uVar2 = (uchar)flags;
  if (((x & 0x3fU) == 0) || ((int)w <= (int)(0x40 - ((uint)(ushort)x & 0x3f)))) {
    block = VRAM_GetOpenBlock();
    lVar3 = (int)w * (int)h;
    block->next = (_BlockVramEntry *)0x0;
    block->flags = uVar2;
    block->time = 0;
    block->ID = 0;
    block->x = x;
    block->y = y;
    block->w = w;
    block->h = h;
  }
  else {
    block = VRAM_GetOpenBlock();
    sVar1 = (short)((uint)(ushort)x & 0x3f);
    block->w = 0x40 - sVar1;
    block->next = (_BlockVramEntry *)0x0;
    block->flags = uVar2;
    block->time = 0;
    block->ID = 0;
    block->x = x;
    block->y = y;
    block->h = h;
    block->area = (int)block->w * (int)h;
    VRAM_InsertFreeBlock(block);
    block = VRAM_GetOpenBlock();
    block->w = w + -0x40 + sVar1;
    lVar3 = (int)block->w * (int)h;
    block->next = (_BlockVramEntry *)0x0;
    block->flags = uVar2;
    block->time = 0;
    block->ID = 0;
    block->y = y;
    block->h = h;
    block->x = (x + 0x40) - sVar1;
  }
  block->area = lVar3;
  VRAM_InsertFreeBlock(block);
  return 1;
}



// decompiled code
// original method signature: 
// struct _BlockVramEntry * /*$ra*/ VRAM_CheckVramSlot(short *x /*$fp*/, short *y /*stack 4*/, short w /*$s3*/, short h /*$s4*/, int type /*stack 16*/, int startY /*stack 20*/)
 // line 440, offset 0x800728c8
	/* begin block 1 */
		// Start line: 441
		// Start offset: 0x800728C8
		// Variables:
	// 		struct _BlockVramEntry *vblock; // $s2
	// 		short hldx; // $s1
	// 		short hldy; // $s7
	// 		short hldw; // $s5
	// 		short hldh; // stack offset -48
	// 		long fits; // $s1
	// 		long offset; // $s0
	// 		struct _BlockVramEntry *vblockright; // $s6
	// 		long offsetright; // $s5
	/* end block 1 */
	// End offset: 0x80072E94
	// End Line: 643

	/* begin block 2 */
		// Start line: 929
	/* end block 2 */
	// End Line: 930

_BlockVramEntry * VRAM_CheckVramSlot(short *x,short *y,short w,short h,int type,int startY)

{
  short sVar1;
  bool bVar2;
  uint uVar3;
  ushort x_00;
  ushort x_01;
  int iVar4;
  ushort w_00;
  int iVar5;
  ushort h_00;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  _BlockVramEntry *block;
  short w_01;
  uint uVar10;
  _BlockVramEntry *p_Var11;
  uint uVar12;
  uchar local_38;
  
  uVar6 = (uint)(ushort)h;
  uVar9 = (uint)(ushort)w;
  bVar2 = false;
  p_Var11 = (_BlockVramEntry *)0x0;
  _w_01 = 0;
  w_01 = 0;
  block = openVramBlocks;
  if (openVramBlocks == (_BlockVramEntry *)0x0) {
LAB_80072a48:
    if ((p_Var11 != (_BlockVramEntry *)0x0) && (bVar2)) {
      VRAM_InsertFreeVram(p_Var11->x,p_Var11->y,w_01,p_Var11->h,(uint)p_Var11->flags);
      p_Var11->x = p_Var11->x + w_01;
      p_Var11->w = p_Var11->w - w_01;
      block = p_Var11;
    }
    if (block == (_BlockVramEntry *)0x0) {
      return (_BlockVramEntry *)0x0;
    }
  }
  else {
    iVar7 = (int)w;
    iVar8 = (int)(short)startY;
    do {
      w_01 = (short)_w_01;
      iVar4 = (int)block->w;
      if (((iVar7 <= iVar4) && (h <= block->h)) &&
         ((iVar8 == -1 || ((iVar8 <= (int)block->y && ((int)block->y < iVar8 + 0x100)))))) {
        x_01 = block->x;
        uVar3 = (uint)x_01 & 0x3f;
        if ((x_01 & 0x3f) == 0) {
LAB_80072b44:
          bVar2 = false;
          break;
        }
        iVar5 = 0x40 - uVar3;
        if (iVar5 < iVar7) {
          if ((iVar7 <= (int)uVar3) && (iVar7 <= iVar4 - iVar5)) {
            bVar2 = true;
            _w_01 = iVar5;
            p_Var11 = block;
          }
        }
        else {
          if ((x_01 & 0xf) == 0) goto LAB_80072b44;
          iVar5 = 0x10 - ((uint)x_01 & 0xf);
          if (iVar7 <= iVar4 - iVar5) {
            bVar2 = false;
            VRAM_InsertFreeVram(x_01,block->y,(short)((uint)(iVar5 * 0x10000) >> 0x10),block->h,
                                (uint)block->flags);
            block->x = block->x + (short)iVar5;
            block->w = block->w - (short)iVar5;
            break;
          }
        }
      }
      w_01 = (short)_w_01;
      block = block->next;
    } while (block != (_BlockVramEntry *)0x0);
    if (block == (_BlockVramEntry *)0x0) goto LAB_80072a48;
  }
  local_38 = (uchar)type;
  if (bVar2) {
    x_00 = block->x;
    x_01 = block->y;
    uVar12 = (uint)x_01;
    w_00 = block->w;
    uVar3 = (uint)w_00;
    h_00 = block->h;
    VRAM_DeleteFreeBlock(block);
    block->next = (_BlockVramEntry *)0x0;
    block->flags = '\x01';
    w_01 = block->w;
    block->type = local_38;
    sVar1 = *x;
    block->w = w;
    block->h = h;
    block->x = (sVar1 + w_01) - w;
    VRAM_InsertUsedBlock(block);
    *x = block->x;
    *y = block->y;
    _w_01 = (int)(short)w_00;
    iVar7 = (int)w;
    if (_w_01 == iVar7) {
      uVar9 = (uint)h_00;
      if (uVar9 << 0x10 == uVar6 << 0x10) {
        return block;
      }
      x_01 = (ushort)((uVar12 + uVar6) * 0x10000 >> 0x10);
      w_00 = w;
    }
    else {
      iVar4 = (int)(short)h_00;
      iVar8 = (int)h;
      if (iVar4 == iVar8) {
        w_00 = (ushort)((uVar3 - uVar9) * 0x10000 >> 0x10);
        goto LAB_80072e8c;
      }
      iVar5 = (_w_01 - iVar7) * iVar8 - _w_01 * (iVar4 - iVar8);
      if (iVar5 < 0) {
        iVar5 = -iVar5;
      }
      _w_01 = (_w_01 - iVar7) * iVar4 - iVar7 * (iVar4 - iVar8);
      if (_w_01 < 0) {
        _w_01 = -_w_01;
      }
      if (iVar5 <= _w_01) {
        VRAM_InsertFreeVram(x_00,x_01,(short)((uVar3 - uVar9) * 0x10000 >> 0x10),h_00,1);
        x_00 = (ushort)(((x_00 + uVar3) - uVar9) * 0x10000 >> 0x10);
        goto LAB_80072e7c;
      }
      VRAM_InsertFreeVram(x_00,x_01,(short)((uVar3 - uVar9) * 0x10000 >> 0x10),h,1);
      x_01 = (ushort)((uVar12 + uVar6) * 0x10000 >> 0x10);
      uVar9 = (uint)h_00;
    }
  }
  else {
    x_00 = block->x;
    uVar3 = (uint)x_00;
    x_01 = block->y;
    uVar12 = (uint)x_01;
    w_00 = block->w;
    uVar10 = (uint)w_00;
    h_00 = block->h;
    VRAM_DeleteFreeBlock(block);
    block->next = (_BlockVramEntry *)0x0;
    block->flags = '\x01';
    block->w = w;
    block->h = h;
    block->type = local_38;
    VRAM_InsertUsedBlock(block);
    *x = block->x;
    *y = block->y;
    _w_01 = (int)(short)w_00;
    iVar7 = (int)w;
    if (_w_01 == iVar7) {
      uVar9 = (uint)h_00;
      if (uVar9 << 0x10 == uVar6 << 0x10) {
        return block;
      }
      x_01 = (ushort)((uVar12 + uVar6) * 0x10000 >> 0x10);
      w_00 = w;
    }
    else {
      iVar4 = (int)(short)h_00;
      iVar8 = (int)h;
      if (iVar4 == iVar8) {
        x_00 = (ushort)((uVar3 + uVar9) * 0x10000 >> 0x10);
        w_00 = (ushort)((uVar10 - uVar9) * 0x10000 >> 0x10);
        goto LAB_80072e8c;
      }
      iVar5 = (_w_01 - iVar7) * iVar8 - _w_01 * (iVar4 - iVar8);
      if (iVar5 < 0) {
        iVar5 = -iVar5;
      }
      _w_01 = (_w_01 - iVar7) * iVar4 - iVar7 * (iVar4 - iVar8);
      if (_w_01 < 0) {
        _w_01 = -_w_01;
      }
      if (_w_01 < iVar5) {
        VRAM_InsertFreeVram((short)((uVar3 + uVar9) * 0x10000 >> 0x10),x_01,
                            (short)((uVar10 - uVar9) * 0x10000 >> 0x10),h,1);
        w = w_00;
      }
      else {
        VRAM_InsertFreeVram((short)((uVar3 + uVar9) * 0x10000 >> 0x10),x_01,
                            (short)((uVar10 - uVar9) * 0x10000 >> 0x10),h_00,1);
      }
LAB_80072e7c:
      uVar9 = (uint)h_00;
      x_01 = (ushort)((uVar12 + uVar6) * 0x10000 >> 0x10);
      w_00 = w;
    }
  }
  h_00 = (ushort)((uVar9 - uVar6) * 0x10000 >> 0x10);
LAB_80072e8c:
  VRAM_InsertFreeVram(x_00,x_01,w_00,h_00,1);
  return block;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VRAM_ClearVramBlock(struct _BlockVramEntry *block /*$s0*/)
 // line 647, offset 0x80072ec8
	/* begin block 1 */
		// Start line: 648
		// Start offset: 0x80072EC8
		// Variables:
	// 		struct BLK_FILL clear; // stack offset -24
	/* end block 1 */
	// End offset: 0x80072F44
	// End Line: 673

	/* begin block 2 */
		// Start line: 1486
	/* end block 2 */
	// End Line: 1487

void VRAM_ClearVramBlock(_BlockVramEntry *block)

{
  undefined auStack24 [3];
  undefined local_15;
  undefined local_14;
  undefined local_13;
  undefined local_12;
  undefined local_11;
  short local_10;
  short local_e;
  short local_c;
  short local_a;
  
  if (block != (_BlockVramEntry *)0x0) {
    local_15 = 3;
    local_11 = 2;
    local_10 = block->x;
    local_e = block->y;
    local_c = block->w;
    local_a = block->h;
    local_14 = 0;
    local_13 = 0;
    local_12 = 0;
    DrawPrim((int)auStack24);
    DrawSync(0);
    VRAM_DeleteUsedBlock(block);
    VRAM_InsertFreeBlock(block);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ AdjustVramCoordsObject(int oldx /*$s3*/, int oldy /*$s1*/, int newx /*$a2*/, int newy /*$t7*/, struct Object *object /*stack 16*/)
 // line 727, offset 0x80072f54
	/* begin block 1 */
		// Start line: 728
		// Start offset: 0x80072F54
		// Variables:
	// 		struct TextureMT3 *texture; // $t1
	// 		int oldclutxoffset; // $v0
	// 		int oldclutyoffset; // $a0
	// 		int newclut; // $a0
	// 		int d; // $t4
	// 		int oldtpagexoffset; // $v1
	// 		int oldtpageyoffset; // $v0
	// 		int newtpage; // $a3
	// 		struct _Model *model; // $t3
	// 		short diffy; // $s5
	// 		short diffx; // $s6
	/* end block 1 */
	// End offset: 0x8007311C
	// End Line: 786

	/* begin block 2 */
		// Start line: 1650
	/* end block 2 */
	// End Line: 1651

void AdjustVramCoordsObject(int oldx,int oldy,int newx,int newy,Object *object)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  char cVar4;
  uint uVar5;
  TextureMT3 *pTVar6;
  ushort *puVar7;
  _Model *p_Var8;
  int iVar9;
  
  cVar3 = (char)newy - (char)oldy;
  iVar9 = 0;
  if (0 < object->numModels) {
    do {
      p_Var8 = object->modelList[iVar9];
      pTVar6 = p_Var8->startTextures;
      if ((pTVar6 != (TextureMT3 *)0x0) && (pTVar6 < p_Var8->endTextures)) {
        puVar7 = &pTVar6->clut;
        do {
          uVar1 = puVar7[2];
          uVar5 = newy + (((uint)uVar1 & 0x10) * 0x10 - (oldy & 0xffffff00U));
          uVar2 = *puVar7;
          *(char *)((int)puVar7 + -1) = *(char *)((int)puVar7 + -1) + cVar3;
          *(char *)((int)puVar7 + 7) = *(char *)((int)puVar7 + 7) + cVar3;
          *(char *)((int)puVar7 + 3) = *(char *)((int)puVar7 + 3) + cVar3;
          cVar4 = (char)(((int)(((newx & 0x3fU) - (oldx & 0x3fU)) * 0x10000) >> 0x10) <<
                        (2 - ((uint)(uVar1 >> 7) & 3) & 0x1f));
          pTVar6->u0 = pTVar6->u0 + cVar4;
          pTVar6 = pTVar6 + 1;
          puVar7[2] = uVar1 & 0x1e0 |
                      (ushort)((int)(uVar5 & 0x100) >> 4) |
                      (ushort)((int)((newx & 0xffffffc0U) +
                                     (((uint)uVar1 & 0xf) * 0x40 - (oldx & 0xffffffc0U)) & 0x3ff) >>
                              6) | (ushort)((uVar5 & 0x200) << 2);
          *puVar7 = ((short)newy + ((uVar2 >> 6) - (short)oldy)) * 0x40 |
                    (ushort)((int)((newx & 0xfffffff0U) +
                                  (((uint)uVar2 & 0x3f) * 0x10 - (oldx & 0xfffffff0U))) >> 4) & 0x3f
          ;
          *(char *)(puVar7 + 1) = *(char *)(puVar7 + 1) + cVar4;
          *(char *)(puVar7 + 3) = *(char *)(puVar7 + 3) + cVar4;
          puVar7 = puVar7 + 8;
        } while (pTVar6 < p_Var8->endTextures);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < object->numModels);
  }
  return;
}



// decompiled code
// original method signature: 
// struct _BlockVramEntry * /*$ra*/ VRAM_InsertionSort(struct _BlockVramEntry *rootNode /*$a0*/, struct _BlockVramEntry *newBlock /*$a1*/)
 // line 824, offset 0x80073140
	/* begin block 1 */
		// Start line: 827
		// Start offset: 0x80073140
		// Variables:
	// 		struct _BlockVramEntry *next; // $v1
	// 		struct _BlockVramEntry *prev; // $a2
	/* end block 1 */
	// End offset: 0x80073194
	// End Line: 855

	/* begin block 2 */
		// Start line: 2024
	/* end block 2 */
	// End Line: 2025

	/* begin block 3 */
		// Start line: 2026
	/* end block 3 */
	// End Line: 2027

	/* begin block 4 */
		// Start line: 2028
	/* end block 4 */
	// End Line: 2029

_BlockVramEntry * VRAM_InsertionSort(_BlockVramEntry *rootNode,_BlockVramEntry *newBlock)

{
  _BlockVramEntry *p_Var1;
  _BlockVramEntry *p_Var2;
  _BlockVramEntry *p_Var3;
  
  p_Var2 = rootNode;
  p_Var3 = (_BlockVramEntry *)0x0;
  if (rootNode != (_BlockVramEntry *)0x0) {
    do {
      p_Var1 = p_Var2;
      p_Var2 = p_Var1;
      if (p_Var1->area <= newBlock->area) break;
      p_Var2 = p_Var1->next;
      p_Var3 = p_Var1;
    } while (p_Var2 != (_BlockVramEntry *)0x0);
  }
  if (p_Var3 == (_BlockVramEntry *)0x0) {
    newBlock->next = rootNode;
    rootNode = newBlock;
  }
  else {
    newBlock->next = p_Var2;
    p_Var3->next = newBlock;
  }
  return rootNode;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VRAM_RearrangeVramsLayer(long whichLayer /*$s6*/)
 // line 868, offset 0x8007319c
	/* begin block 1 */
		// Start line: 869
		// Start offset: 0x8007319C
		// Variables:
	// 		struct _BlockVramEntry *vblock; // $s0
	// 		struct _BlockVramEntry *sortedBlocks; // $s2
	// 		struct _BlockVramEntry *curBlock; // $s1
	// 		struct _BlockVramEntry (*savedVramBlocksPTR[48]); // stack offset -1584
	// 		struct _BlockVramEntry savedVramBlocks[48]; // stack offset -1392
	// 		struct RECT vramLoc; // stack offset -48
	// 		long numBlocks; // $s3
	// 		long d; // $s4
	// 		short x; // stack offset -40
	// 		short y; // stack offset -38
	// 		short dispYPos; // $s5
	/* end block 1 */
	// End offset: 0x8007358C
	// End Line: 1023

	/* begin block 2 */
		// Start line: 2112
	/* end block 2 */
	// End Line: 2113

void VRAM_RearrangeVramsLayer(long whichLayer)

{
  byte bVar1;
  bool bVar2;
  short sVar3;
  int iVar4;
  _BlockVramEntry *newBlock;
  _BlockVramEntry *block;
  undefined4 uVar5;
  long lVar6;
  undefined4 uVar7;
  _BlockVramEntry *rootNode;
  _BlockVramEntry **pp_Var8;
  int iVar9;
  _BlockVramEntry *local_630 [48];
  _BlockVramEntry local_570 [48];
  short local_30;
  short local_2e;
  short local_2c;
  short local_2a;
  ushort local_28;
  ushort local_26 [3];
  
  iVar9 = 0;
  if (usedVramBlocks != (_BlockVramEntry *)0x0) {
    newBlock = local_570;
    pp_Var8 = local_630;
    rootNode = usedVramBlocks;
    do {
      if (whichLayer == 0) {
        bVar2 = iVar9 < 0x31;
        if (rootNode->y < 0x100) {
          *pp_Var8 = rootNode;
LAB_80073214:
          uVar5 = *(undefined4 *)&rootNode->type;
          lVar6 = rootNode->ID;
          uVar7 = *(undefined4 *)&rootNode->x;
          newBlock->next = rootNode->next;
          *(undefined4 *)&newBlock->type = uVar5;
          newBlock->ID = lVar6;
          *(undefined4 *)&newBlock->x = uVar7;
          lVar6 = rootNode->area;
          uVar5 = rootNode->udata;
          *(undefined4 *)&newBlock->w = *(undefined4 *)&rootNode->w;
          newBlock->area = lVar6;
          newBlock->udata = uVar5;
          newBlock = newBlock + 1;
          pp_Var8 = pp_Var8 + 1;
          iVar9 = iVar9 + 1;
          bVar2 = iVar9 < 0x31;
        }
      }
      else {
        bVar2 = iVar9 < 0x31;
        if (0xff < rootNode->y) {
          *pp_Var8 = rootNode;
          goto LAB_80073214;
        }
      }
      if (!bVar2) {
        GXFilePrint("Ran out of vram blocks\n");
      }
      rootNode = rootNode->next;
    } while (rootNode != (_BlockVramEntry *)0x0);
  }
  if (0 < iVar9) {
    if (whichLayer == 0) {
      local_2e = 0;
    }
    else {
      local_2e = 0x100;
    }
    local_2c = 0x200;
    local_30 = 0x200;
    local_2a = 0x100;
    do {
      do {
        iVar4 = CheckVolatile(gameTrackerX.drawTimerReturn);
      } while (iVar4 != 0);
      iVar4 = CheckVolatile(gameTrackerX.reqDisp);
    } while (iVar4 != 0);
    iVar4 = 0;
    rootNode = (_BlockVramEntry *)0x0;
    sVar3 = (short)(gameTrackerX.gameData.asmData.dispPage ^ 1U) * 0x100;
    MoveImage((undefined4 *)&local_30,0,
              (int)((gameTrackerX.gameData.asmData.dispPage ^ 1U) << 0x18) >> 0x10);
    DrawSync(0);
    pp_Var8 = local_630;
    if (0 < iVar9) {
      newBlock = local_570;
      do {
        block = *pp_Var8;
        pp_Var8 = pp_Var8 + 1;
        VRAM_ClearVramBlock(block);
        iVar4 = iVar4 + 1;
        newBlock->next = (_BlockVramEntry *)0x0;
        newBlock->area = (int)newBlock->w * (int)newBlock->h;
        rootNode = VRAM_InsertionSort(rootNode,newBlock);
        newBlock = newBlock + 1;
      } while (iVar4 < iVar9);
    }
    while (rootNode != (_BlockVramEntry *)0x0) {
      local_2c = rootNode->w;
      local_2a = rootNode->h;
      local_30 = rootNode->x + -0x200;
      local_2e = sVar3;
      if (whichLayer != 0) {
        local_2e = sVar3 + -0x100;
      }
      local_2e = rootNode->y + local_2e;
      local_28 = rootNode->x;
      local_26[0] = rootNode->y;
      newBlock = VRAM_CheckVramSlot((short *)&local_28,(short *)local_26,local_2c,local_2a,
                                    (uint)rootNode->type,-1);
      if (newBlock == (_BlockVramEntry *)0x0) {
        VRAM_PrintInfo();
        GXFilePrint("Vram didn\'t fit on object relocation. Old info x,y(%d,%d) w,h(%d,%d)\n");
        VRAM_PrintVramBlock(rootNode);
      }
      MoveImage((undefined4 *)&local_30,(int)(short)local_28,(int)(short)local_26[0]);
      DrawSync(0);
      bVar1 = rootNode->type;
      if (bVar1 == 2) {
        AdjustVramCoordsObject
                  ((int)rootNode->x,(int)rootNode->y,(int)(short)local_28,(int)(short)local_26[0],
                   *(Object **)(rootNode->udata + 0x10));
        *(_BlockVramEntry **)(rootNode->udata + 0x18) = newBlock;
LAB_80073570:
        newBlock->udata = rootNode->udata;
      }
      else {
        if (2 < bVar1) {
          if (bVar1 == 3) {
            GXFilePrint("font was at (%d,%d) now is at (%d,%d) ,new offset (%d,%d) w,h(%d,%d)\n");
            fontTracker.font_tpage =
                 (short)(local_26[0] & 0x100) >> 4 | (ushort)(((uint)local_28 & 0x3ff) >> 6) |
                 (ushort)(((uint)local_26[0] & 0x200) << 2);
            fontTracker.font_vramU = (short)(((uint)local_28 & 0x3f) << 2);
            fontTracker.font_vramV = local_26[0] & 0xff;
            fontTracker.font_vramX = local_28;
            SpecialFogClut = local_28 >> 4 & 0x3f;
            fontTracker.font_clut = (local_26[0] + 0x7e) * 0x40 | SpecialFogClut;
            fontTracker.font_vramY = local_26[0];
            SpecialFogClut = (local_26[0] + 0x7f) * 0x40 | SpecialFogClut;
          }
          else {
            if (bVar1 == 4) {
              DRAW_RelocateButtonInVram((_ButtonTexture *)rootNode->udata,newBlock);
              goto LAB_80073570;
            }
          }
        }
      }
      rootNode = rootNode->next;
    }
  }
  DrawSync(0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VRAM_TransferBufferToVram(void *dataPtr /*$s3*/, long dataSize /*$s2*/, short status /*$s6*/, void *data1 /*$s0*/, void *data2 /*stack 16*/)
 // line 1054, offset 0x800735bc
	/* begin block 1 */
		// Start line: 1055
		// Start offset: 0x800735BC
		// Variables:
	// 		struct VramBuffer *vramControl; // $s1
	// 		struct RECT rect; // stack offset -48
	// 		long *nextOTag; // $s5
	// 		long *drawTimerReturn; // $s7

		/* begin block 1.1 */
			// Start line: 1084
			// Start offset: 0x80073648
		/* end block 1.1 */
		// End offset: 0x800736FC
		// End Line: 1113

		/* begin block 1.2 */
			// Start line: 1118
			// Start offset: 0x80073704
		/* end block 1.2 */
		// End offset: 0x800737A8
		// End Line: 1138
	/* end block 1 */
	// End offset: 0x800737E8
	// End Line: 1176

	/* begin block 2 */
		// Start line: 2103
	/* end block 2 */
	// End Line: 2104

void VRAM_TransferBufferToVram(void *dataPtr,long dataSize,short status,void *data1,void *data2)

{
  short sVar1;
  long *plVar2;
  undefined4 *puVar3;
  int iVar4;
  short sVar5;
  size_t __n;
  int iVar6;
  undefined2 local_30;
  short local_2e;
  undefined2 local_2c;
  short local_2a;
  
  puVar3 = (undefined4 *)BreakDraw();
  DrawSync(0);
  plVar2 = gameTrackerX.drawTimerReturn;
  gameTrackerX.drawTimerReturn = (long *)0x0;
  if (data1 != (void *)0x0) {
    if ((*(uint *)data1 & 1) == 0) {
      *(uint *)data1 = *(uint *)data1 | 1;
      dataPtr = (void *)((int)dataPtr + 0x24);
      dataSize = dataSize - 0x24;
    }
    iVar4 = (int)*(short *)((int)data1 + 0xe);
    if (iVar4 != 0) {
      iVar6 = (int)*(short *)((int)data1 + 8) * 2 - (uint)*(ushort *)((int)data1 + 0xe);
      __n = iVar6 * 0x10000 >> 0x10;
      if (dataSize < (int)__n) {
        memcpy((void *)(*(int *)((int)data1 + 0x10) + iVar4),dataPtr,dataSize);
        sVar1 = (short)dataSize;
        dataSize = 0;
        *(short *)((int)data1 + 0xe) = *(short *)((int)data1 + 0xe) + sVar1;
      }
      else {
        memcpy((void *)(*(int *)((int)data1 + 0x10) + iVar4),dataPtr,__n);
        dataPtr = (void *)((int)dataPtr + __n);
        dataSize = dataSize - __n;
        local_30 = *(undefined2 *)((int)data1 + 4);
        *(short *)((int)data1 + 0xe) = *(short *)((int)data1 + 0xe) + (short)iVar6;
        local_2e = *(short *)((int)data1 + 6) + *(short *)((int)data1 + 0xc);
        local_2c = *(undefined2 *)((int)data1 + 8);
        local_2a = 1;
        *(short *)((int)data1 + 0xc) = *(short *)((int)data1 + 0xc) + 1;
        LoadImage((undefined4 *)&local_30,*(undefined4 *)((int)data1 + 0x10));
        *(undefined2 *)((int)data1 + 0xe) = 0;
      }
    }
    if (0 < dataSize) {
      sVar1 = *(short *)((int)data1 + 8);
      iVar4 = dataSize / ((int)sVar1 << 1);
      local_30 = *(undefined2 *)((int)data1 + 4);
      local_2e = *(short *)((int)data1 + 6) + *(short *)((int)data1 + 0xc);
      local_2c = *(undefined2 *)((int)data1 + 8);
      sVar5 = (short)iVar4;
      local_2a = sVar5;
      LoadImage((undefined4 *)&local_30,dataPtr);
      *(short *)((int)data1 + 0xc) = *(short *)((int)data1 + 0xc) + sVar5;
      iVar4 = (int)(short)(sVar1 * (short)((iVar4 << 0x10) >> 0xf));
      __n = dataSize - iVar4;
      if (0 < (int)__n) {
        memcpy((void *)(*(int *)((int)data1 + 0x10) + (int)*(short *)((int)data1 + 0xe)),
               (void *)((int)dataPtr + iVar4),__n);
        *(short *)((int)data1 + 0xe) = *(short *)((int)data1 + 0xe) + (short)__n;
      }
    }
    if (status == 1) {
      MEMPACK_Free((char *)data1);
    }
  }
  DrawSync(0);
  gameTrackerX.drawTimerReturn = plVar2;
  if ((puVar3 != (undefined4 *)0x0) && (puVar3 != (undefined4 *)0xffffffff)) {
    DrawOTag(puVar3);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VRAM_AbortLoad(void *dataPtr /*$a0*/, void *data1 /*$a1*/, void *data2 /*$a2*/)
 // line 1181, offset 0x80073814
	/* begin block 1 */
		// Start line: 1182
		// Start offset: 0x80073814
	/* end block 1 */
	// End offset: 0x80073814
	// End Line: 1182

	/* begin block 2 */
		// Start line: 2801
	/* end block 2 */
	// End Line: 2802

void VRAM_AbortLoad(void *dataPtr,void *data1,void *data2)

{
  MEMPACK_Free((char *)data1);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ VRAM_GetObjectVramSpace(struct VramSize *vramSize /*$v1*/, struct _ObjectTracker *objectTracker /*$s4*/)
 // line 1187, offset 0x80073834
	/* begin block 1 */
		// Start line: 1188
		// Start offset: 0x80073834
		// Variables:
	// 		struct RECT rect; // stack offset -40
	// 		long result; // $s5
	// 		struct _BlockVramEntry *lastVramBlockUsed; // $s0
	/* end block 1 */
	// End offset: 0x8007391C
	// End Line: 1225

	/* begin block 2 */
		// Start line: 2813
	/* end block 2 */
	// End Line: 2814

long VRAM_GetObjectVramSpace(VramSize *vramSize,_ObjectTracker *objectTracker)

{
  _BlockVramEntry *p_Var1;
  long lVar2;
  short local_28;
  short local_26;
  short local_24;
  short local_22;
  
  lVar2 = 1;
  local_28 = vramSize->x + 0x200;
  local_26 = vramSize->y;
  local_24 = vramSize->w;
  local_22 = vramSize->h;
  p_Var1 = VRAM_CheckVramSlot(&local_28,&local_26,local_24,local_22,2,-1);
  if (p_Var1 == (_BlockVramEntry *)0x0) {
    VRAM_RearrangeVramsLayer(1);
    p_Var1 = VRAM_CheckVramSlot(&local_28,&local_26,local_24,local_22,2,-1);
    if (p_Var1 == (_BlockVramEntry *)0x0) {
      lVar2 = 0;
      VRAM_PrintInfo();
      GXFilePrint("couldn\'t fit the object %s in the vram, size (%d,%d)\n");
    }
  }
  *(_BlockVramEntry **)&objectTracker->vramBlock = p_Var1;
  if (p_Var1 != (_BlockVramEntry *)0x0) {
    *(_ObjectTracker **)&p_Var1->udata = objectTracker;
  }
  return lVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VRAM_InitMorphPalettes()
 // line 1231, offset 0x80073944
	/* begin block 1 */
		// Start line: 2952
	/* end block 1 */
	// End Line: 2953

	/* begin block 2 */
		// Start line: 2959
	/* end block 2 */
	// End Line: 2960

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_InitMorphPalettes(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VRAM_UpdateMorphPalettes()
 // line 1265, offset 0x8007394c
	/* begin block 1 */
		// Start line: 3020
	/* end block 1 */
	// End Line: 3021

	/* begin block 2 */
		// Start line: 3121
	/* end block 2 */
	// End Line: 3122

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_UpdateMorphPalettes(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_ChangeAreaPalettes(long time /*$a0*/)
 // line 1423, offset 0x80073954
	/* begin block 1 */
		// Start line: 3336
	/* end block 1 */
	// End Line: 3337

	/* begin block 2 */
		// Start line: 3362
	/* end block 2 */
	// End Line: 3363

void MORPH_ChangeAreaPalettes(long time)

{
  return;
}





