#include "THISDUST.H"
#include "VRAM.H"


// decompiled code
// original method signature: 
// void /*$ra*/ VRAM_PrintVramBlock(struct _BlockVramEntry *vblock /*$a0*/)
 // line 75, offset 0x80072e44
	/* begin block 1 */
		// Start line: 150
	/* end block 1 */
	// End Line: 151

void VRAM_PrintVramBlock(_BlockVramEntry *vblock)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VRAM_PrintInfo()
 // line 110, offset 0x80072e4c
	/* begin block 1 */
		// Start line: 112
		// Start offset: 0x80072E4C
		// Variables:
	// 		struct _BlockVramEntry *vblock; // $v0
	/* end block 1 */
	// End offset: 0x80072E8C
	// End Line: 148

	/* begin block 2 */
		// Start line: 220
	/* end block 2 */
	// End Line: 221

	/* begin block 3 */
		// Start line: 186
	/* end block 3 */
	// End Line: 187

	/* begin block 4 */
		// Start line: 189
	/* end block 4 */
	// End Line: 190

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_PrintInfo(void)

{
  _BlockVramEntry *p_Var1;
  
  p_Var1 = usedVramBlocks;
  if (usedVramBlocks != (_BlockVramEntry *)0x0) {
    do {
      p_Var1 = p_Var1->next;
    } while (p_Var1 != (_BlockVramEntry *)0x0);
  }
  p_Var1 = openVramBlocks;
  if (openVramBlocks != (_BlockVramEntry *)0x0) {
    do {
      p_Var1 = p_Var1->next;
    } while (p_Var1 != (_BlockVramEntry *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VRAM_InitVramBlockCache()
 // line 153, offset 0x80072e94
	/* begin block 1 */
		// Start line: 154
		// Start offset: 0x80072E94
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x80072EC0
	// End Line: 179

	/* begin block 2 */
		// Start line: 271
	/* end block 2 */
	// End Line: 272

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_InitVramBlockCache(void)

{
  _BlockVramEntry *p_Var1;
  int iVar2;
  
  iVar2 = 0x59;
  p_Var1 = &_BlockVramEntry_800d619c;
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
// void /*$ra*/ VRAM_EnableTerrainArea()
 // line 184, offset 0x80072ef4
	/* begin block 1 */
		// Start line: 343
	/* end block 1 */
	// End Line: 344

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_EnableTerrainArea(void)

{
  VRAM_InsertFreeVram(0x200,0,0x200,0x100,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VRAM_DisableTerrainArea()
 // line 189, offset 0x80072f24
	/* begin block 1 */
		// Start line: 354
	/* end block 1 */
	// End Line: 355

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_DisableTerrainArea(void)

{
  VRAM_DeleteFreeVram(0x200,0,0x200,0x100);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ VRAM_ConcatanateMemory(struct _BlockVramEntry *curBlock /*$s1*/)
 // line 195, offset 0x80072f50
	/* begin block 1 */
		// Start line: 196
		// Start offset: 0x80072F50
		// Variables:
	// 		struct _BlockVramEntry *nextBlock; // $s0
	/* end block 1 */
	// End offset: 0x80073124
	// End Line: 261

	/* begin block 2 */
		// Start line: 367
	/* end block 2 */
	// End Line: 368

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
              goto LAB_80073088;
            }
            if (iVar3 + block->h == iVar4) {
              block->h = block->h + curBlock->h;
              goto LAB_800730ec;
            }
          }
        }
        if ((curBlock->y == block->y) && (curBlock->h == block->h)) {
          if (((int)curBlock->x + (int)curBlock->w == (int)block->x) &&
             (((curBlock->x & 0x3fU) == 0 || ((int)curBlock->w + (int)block->w < 0x41)))) {
            curBlock->w = curBlock->w + block->w;
LAB_80073088:
            VRAM_DeleteFreeBlock(block);
            block->flags = '\0';
            return 1;
          }
          if (((int)block->x + (int)block->w == (int)curBlock->x) &&
             (((block->x & 0x3fU) == 0 || ((int)curBlock->w + (int)block->w < 0x41)))) {
            block->w = block->w + curBlock->w;
LAB_800730ec:
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
 // line 263, offset 0x80073138
	/* begin block 1 */
		// Start line: 506
	/* end block 1 */
	// End Line: 507

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
 // line 270, offset 0x8007316c
	/* begin block 1 */
		// Start line: 271
		// Start offset: 0x8007316C
		// Variables:
	// 		struct _BlockVramEntry *next; // $v1
	// 		struct _BlockVramEntry *prev; // $a1
	/* end block 1 */
	// End offset: 0x800731EC
	// End Line: 301

	/* begin block 2 */
		// Start line: 521
	/* end block 2 */
	// End Line: 522

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
 // line 304, offset 0x800731fc
	/* begin block 1 */
		// Start line: 306
		// Start offset: 0x800731FC
		// Variables:
	// 		struct _BlockVramEntry *next; // $v1
	// 		struct _BlockVramEntry *prev; // $a1
	/* end block 1 */
	// End offset: 0x8007325C
	// End Line: 330

	/* begin block 2 */
		// Start line: 590
	/* end block 2 */
	// End Line: 591

	/* begin block 3 */
		// Start line: 591
	/* end block 3 */
	// End Line: 592

	/* begin block 4 */
		// Start line: 592
	/* end block 4 */
	// End Line: 593

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
 // line 333, offset 0x80073264
	/* begin block 1 */
		// Start line: 648
	/* end block 1 */
	// End Line: 649

	/* begin block 2 */
		// Start line: 649
	/* end block 2 */
	// End Line: 650

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
 // line 349, offset 0x80073298
	/* begin block 1 */
		// Start line: 351
		// Start offset: 0x80073298
		// Variables:
	// 		struct _BlockVramEntry *next; // $v1
	// 		struct _BlockVramEntry *prev; // $a1
	/* end block 1 */
	// End offset: 0x800732F4
	// End Line: 372

	/* begin block 2 */
		// Start line: 680
	/* end block 2 */
	// End Line: 681

	/* begin block 3 */
		// Start line: 681
	/* end block 3 */
	// End Line: 682

	/* begin block 4 */
		// Start line: 683
	/* end block 4 */
	// End Line: 684

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
 // line 374, offset 0x800732fc
	/* begin block 1 */
		// Start line: 376
		// Start offset: 0x800732FC
		// Variables:
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x80073328
	// End Line: 389

	/* begin block 2 */
		// Start line: 732
	/* end block 2 */
	// End Line: 733

	/* begin block 3 */
		// Start line: 733
	/* end block 3 */
	// End Line: 734

	/* begin block 4 */
		// Start line: 735
	/* end block 4 */
	// End Line: 736

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
  } while (iVar2 < 0x5a);
  return (_BlockVramEntry *)0x0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ VRAM_DeleteFreeVram(short x /*$a0*/, short y /*$a1*/, short w /*$a2*/, short h /*$a3*/)
 // line 391, offset 0x80073330
	/* begin block 1 */
		// Start line: 392
		// Start offset: 0x80073330
		// Variables:
	// 		struct _BlockVramEntry *prev; // $t1
	// 		struct _BlockVramEntry *vblock; // $a2
	// 		struct _BlockVramEntry *nextVBlock; // $t0
	// 		struct _BlockVramEntry (*blockLists[2]); // stack offset -24
	// 		int i; // $t2
	// 		int delCount; // $t3
	/* end block 1 */
	// End offset: 0x8007344C
	// End Line: 427

	/* begin block 2 */
		// Start line: 770
	/* end block 2 */
	// End Line: 771

int VRAM_DeleteFreeVram(short x,short y,short w,short h)

{
  _BlockVramEntry *p_Var1;
  _BlockVramEntry *p_Var2;
  _BlockVramEntry *p_Var3;
  _BlockVramEntry *p_Var4;
  int iVar5;
  int iVar6;
  _BlockVramEntry **pp_Var7;
  _BlockVramEntry *local_18 [4];
  
  pp_Var7 = local_18;
  iVar6 = 0;
  iVar5 = 0;
  local_18[2] = openVramBlocks;
  local_18[3] = usedVramBlocks;
  local_18[0] = openVramBlocks;
  local_18[1] = usedVramBlocks;
  do {
    if (*pp_Var7 != (_BlockVramEntry *)0x0) {
      p_Var1 = *pp_Var7;
      p_Var3 = (_BlockVramEntry *)0x0;
      do {
        p_Var2 = p_Var1->next;
        p_Var4 = p_Var1;
        if (((((int)x <= (int)p_Var1->x) && ((int)p_Var1->x + (int)p_Var1->w <= (int)x + (int)w)) &&
            ((int)y <= (int)p_Var1->y)) && ((int)p_Var1->y + (int)p_Var1->h <= (int)y + (int)h)) {
          p_Var1->flags = '\0';
          p_Var4 = p_Var3;
          if (p_Var3 == (_BlockVramEntry *)0x0) {
            if (iVar5 == 0) {
              iVar6 = iVar6 + 1;
              openVramBlocks = p_Var2;
            }
            else {
              iVar6 = iVar6 + 1;
              usedVramBlocks = p_Var2;
            }
          }
          else {
            p_Var3->next = p_Var2;
            iVar6 = iVar6 + 1;
          }
        }
        p_Var1 = p_Var2;
        p_Var3 = p_Var4;
      } while (p_Var2 != (_BlockVramEntry *)0x0);
    }
    iVar5 = iVar5 + 1;
    pp_Var7 = pp_Var7 + 1;
  } while (iVar5 < 2);
  return iVar6;
}



// decompiled code
// original method signature: 
// int /*$ra*/ VRAM_InsertFreeVram(short x /*stack -48*/, short y /*stack -46*/, short w /*$s7*/, short h /*$fp*/, int flags /*stack 16*/)
 // line 430, offset 0x80073460
	/* begin block 1 */
		// Start line: 431
		// Start offset: 0x80073460
		// Variables:
	// 		struct _BlockVramEntry *useBlock; // $a0
	/* end block 1 */
	// End offset: 0x800735CC
	// End Line: 479

	/* begin block 2 */
		// Start line: 884
	/* end block 2 */
	// End Line: 885

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
// struct _BlockVramEntry * /*$ra*/ VRAM_CheckVramSlot(short *x /*stack 0*/, short *y /*stack 4*/, short w /*$s6*/, short h /*$s7*/, int type /*stack 16*/, int startY /*stack 20*/)
 // line 489, offset 0x80073600
	/* begin block 1 */
		// Start line: 490
		// Start offset: 0x80073600
		// Variables:
	// 		struct _BlockVramEntry *vblock; // $s1
	// 		short hldx; // $s4
	// 		short hldy; // $s5
	// 		short hldw; // $s0
	// 		short hldh; // $fp
	// 		long fits; // $t1
	// 		long offset; // $s0
	// 		struct _BlockVramEntry *vblockright; // $s3
	// 		long offsetright; // $s2

		/* begin block 1.1 */
			// Start line: 525
			// Start offset: 0x800736F4
			// Variables:
		// 		int newx; // $v0
		/* end block 1.1 */
		// End offset: 0x8007375C
		// End Line: 539

		/* begin block 1.2 */
			// Start line: 544
			// Start offset: 0x8007375C
			// Variables:
		// 		int xval; // $v0
		/* end block 1.2 */
		// End offset: 0x80073794
		// End Line: 560
	/* end block 1 */
	// End offset: 0x80073A08
	// End Line: 706

	/* begin block 2 */
		// Start line: 1047
	/* end block 2 */
	// End Line: 1048

_BlockVramEntry * VRAM_CheckVramSlot(short *x,short *y,short w,short h,int type,int startY)

{
  ushort uVar1;
  bool bVar2;
  ushort x_00;
  ushort y_00;
  int iVar3;
  uint uVar4;
  int iVar5;
  ushort h_00;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  _BlockVramEntry *block;
  short w_00;
  _BlockVramEntry *p_Var10;
  uint uVar11;
  uchar local_30;
  
  uVar6 = (uint)(ushort)h;
  uVar4 = (uint)(ushort)w;
  bVar2 = false;
  p_Var10 = (_BlockVramEntry *)0x0;
  _w_00 = 0;
  w_00 = 0;
  block = openVramBlocks;
  if (openVramBlocks != (_BlockVramEntry *)0x0) {
    iVar3 = (int)w;
    iVar8 = (int)(short)startY;
    do {
      w_00 = (short)_w_00;
      iVar7 = (int)block->w;
      if (((iVar3 <= iVar7) && (h <= block->h)) &&
         ((iVar8 == -1 || ((iVar8 <= (int)block->y && ((int)block->y < iVar8 + 0x100)))))) {
        x_00 = block->x;
        iVar5 = 0x40 - ((uint)x_00 & 0x3f);
        if ((x_00 & 0x3f) == 0) {
LAB_800738b8:
          bVar2 = false;
          break;
        }
        if (iVar5 < iVar3) {
          if ((iVar3 <= (int)(0x40 - ((short)x_00 + iVar5 & 0x3fU))) && (iVar3 <= iVar7 - iVar5)) {
            bVar2 = true;
            _w_00 = iVar5;
            p_Var10 = block;
          }
        }
        else {
          if ((x_00 & 0xf) == 0) goto LAB_800738b8;
          iVar5 = 0x10 - ((uint)x_00 & 0xf);
          if ((iVar3 <= (int)(0x40 - ((short)x_00 + iVar5 & 0x3fU))) && (iVar3 <= iVar7 - iVar5)) {
            VRAM_InsertFreeVram(x_00,block->y,(short)((uint)(iVar5 * 0x10000) >> 0x10),block->h,
                                (uint)block->flags);
            bVar2 = false;
            block->x = block->x + (short)iVar5;
            block->w = block->w - (short)iVar5;
            break;
          }
        }
      }
      w_00 = (short)_w_00;
      block = block->next;
    } while (block != (_BlockVramEntry *)0x0);
    if (block != (_BlockVramEntry *)0x0) goto LAB_80073800;
  }
  if ((p_Var10 != (_BlockVramEntry *)0x0) && (bVar2)) {
    VRAM_InsertFreeVram(p_Var10->x,p_Var10->y,w_00,p_Var10->h,(uint)p_Var10->flags);
    bVar2 = false;
    p_Var10->x = p_Var10->x + w_00;
    p_Var10->w = p_Var10->w - w_00;
    block = p_Var10;
  }
  if (block == (_BlockVramEntry *)0x0) {
    return (_BlockVramEntry *)0x0;
  }
LAB_80073800:
  if (!bVar2) {
    x_00 = block->x;
    y_00 = block->y;
    uVar1 = block->w;
    uVar9 = (uint)uVar1;
    h_00 = block->h;
    uVar11 = (uint)h_00;
    VRAM_DeleteFreeBlock(block);
    block->next = (_BlockVramEntry *)0x0;
    block->flags = '\x01';
    local_30 = (uchar)type;
    block->w = w;
    block->h = h;
    block->type = local_30;
    VRAM_InsertUsedBlock(block);
    *x = block->x;
    *y = block->y;
    _w_00 = (int)(short)uVar1;
    iVar3 = (int)w;
    if (_w_00 == iVar3) {
      if (uVar11 << 0x10 == uVar6 << 0x10) {
        return block;
      }
      y_00 = (ushort)((y_00 + uVar6) * 0x10000 >> 0x10);
      h_00 = (ushort)((uVar11 - uVar6) * 0x10000 >> 0x10);
    }
    else {
      iVar7 = (int)(short)h_00;
      iVar8 = (int)h;
      if (iVar7 == iVar8) {
        x_00 = (ushort)((x_00 + uVar4) * 0x10000 >> 0x10);
        w = (short)((uVar9 - uVar4) * 0x10000 >> 0x10);
      }
      else {
        iVar5 = (_w_00 - iVar3) * iVar8 - _w_00 * (iVar7 - iVar8);
        if (iVar5 < 0) {
          iVar5 = -iVar5;
        }
        _w_00 = (_w_00 - iVar3) * iVar7 - iVar3 * (iVar7 - iVar8);
        if (_w_00 < 0) {
          _w_00 = -_w_00;
        }
        iVar3 = x_00 + uVar4;
        if (_w_00 < iVar5) {
          VRAM_InsertFreeVram((short)((uint)(iVar3 * 0x10000) >> 0x10),y_00,
                              (short)((uVar9 - uVar4) * 0x10000 >> 0x10),h,1);
          w = uVar1;
        }
        else {
          VRAM_InsertFreeVram((short)((uint)(iVar3 * 0x10000) >> 0x10),y_00,
                              (short)((uVar9 - uVar4) * 0x10000 >> 0x10),h_00,1);
        }
        y_00 = (ushort)((y_00 + uVar6) * 0x10000 >> 0x10);
        h_00 = (ushort)((uVar11 - uVar6) * 0x10000 >> 0x10);
      }
    }
    VRAM_InsertFreeVram(x_00,y_00,w,h_00,1);
  }
  return block;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VRAM_ClearVramBlock(struct _BlockVramEntry *block /*$s0*/)
 // line 710, offset 0x80073a3c
	/* begin block 1 */
		// Start line: 1638
	/* end block 1 */
	// End Line: 1639

void VRAM_ClearVramBlock(_BlockVramEntry *block)

{
  if (block != (_BlockVramEntry *)0x0) {
    VRAM_DeleteUsedBlock(block);
    VRAM_InsertFreeBlock(block);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ AdjustVramCoordsObject(int oldx /*$s3*/, int oldy /*$s1*/, int newx /*$a2*/, int newy /*$t7*/, struct Object *object /*stack 16*/)
 // line 790, offset 0x80073a70
	/* begin block 1 */
		// Start line: 791
		// Start offset: 0x80073A70
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
	// End offset: 0x80073C38
	// End Line: 849

	/* begin block 2 */
		// Start line: 1798
	/* end block 2 */
	// End Line: 1799

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
 // line 887, offset 0x80073c5c
	/* begin block 1 */
		// Start line: 890
		// Start offset: 0x80073C5C
		// Variables:
	// 		struct _BlockVramEntry *next; // $v1
	// 		struct _BlockVramEntry *prev; // $a2
	/* end block 1 */
	// End offset: 0x80073CB0
	// End Line: 918

	/* begin block 2 */
		// Start line: 2172
	/* end block 2 */
	// End Line: 2173

	/* begin block 3 */
		// Start line: 2174
	/* end block 3 */
	// End Line: 2175

	/* begin block 4 */
		// Start line: 2176
	/* end block 4 */
	// End Line: 2177

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
// void /*$ra*/ VRAM_RearrangeVramsLayer(long whichLayer /*$s7*/)
 // line 931, offset 0x80073cb8
	/* begin block 1 */
		// Start line: 932
		// Start offset: 0x80073CB8
		// Variables:
	// 		struct _BlockVramEntry *vblock; // $s0
	// 		struct _BlockVramEntry *sortedBlocks; // $s2
	// 		struct _BlockVramEntry *curBlock; // $s1
	// 		struct _BlockVramEntry (*savedVramBlocksPTR[48]); // stack offset -1592
	// 		struct _BlockVramEntry savedVramBlocks[48]; // stack offset -1400
	// 		struct RECT vramLoc; // stack offset -56
	// 		long numBlocks; // $s4
	// 		long d; // $s3
	// 		short x; // stack offset -48
	// 		short y; // stack offset -46
	// 		short dispYPos; // $s5

		/* begin block 1.1 */
			// Start line: 989
			// Start offset: 0x80073DB0
			// Variables:
		// 		int startY; // $s6
		/* end block 1.1 */
		// End offset: 0x8007403C
		// End Line: 1097
	/* end block 1 */
	// End offset: 0x8007403C
	// End Line: 1100

	/* begin block 2 */
		// Start line: 2260
	/* end block 2 */
	// End Line: 2261

void VRAM_RearrangeVramsLayer(long whichLayer)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  _BlockVramEntry *newBlock;
  _BlockVramEntry **pp_Var4;
  _BlockVramEntry *block;
  undefined4 uVar5;
  long lVar6;
  undefined4 uVar7;
  _BlockVramEntry *rootNode;
  int iVar8;
  short sVar9;
  _BlockVramEntry *local_638 [48];
  _BlockVramEntry local_578 [48];
  short local_38;
  short local_36;
  short local_34;
  short local_32;
  ushort local_30;
  ushort local_2e [3];
  
  iVar8 = 0;
  if ((gameTrackerX.gameFlags & 0x8000000U) != 0) {
    GAMELOOP_Set_Pause_Redraw();
  }
  if (usedVramBlocks != (_BlockVramEntry *)0x0) {
    newBlock = local_578;
    pp_Var4 = local_638;
    rootNode = usedVramBlocks;
    do {
      if (whichLayer == 0) {
        if (rootNode->y < 0x100) {
          *pp_Var4 = rootNode;
LAB_80073d54:
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
          pp_Var4 = pp_Var4 + 1;
          iVar8 = iVar8 + 1;
        }
      }
      else {
        if (0xff < rootNode->y) {
          *pp_Var4 = rootNode;
          goto LAB_80073d54;
        }
      }
      rootNode = rootNode->next;
    } while (rootNode != (_BlockVramEntry *)0x0);
  }
  if (0 < iVar8) {
    sVar9 = 0x100;
    if (whichLayer == 0) {
      sVar9 = 0;
      local_36 = 0;
    }
    else {
      local_36 = 0x100;
    }
    local_34 = 0x200;
    local_38 = 0x200;
    local_32 = 0x100;
    do {
      do {
        iVar3 = CheckVolatile(gameTrackerX.drawTimerReturn);
      } while (iVar3 != 0);
      iVar3 = CheckVolatile(gameTrackerX.reqDisp);
    } while (iVar3 != 0);
    iVar3 = 0;
    rootNode = (_BlockVramEntry *)0x0;
    sVar2 = (short)(gameTrackerX.gameData.asmData.dispPage ^ 1U) * 0x100;
    MoveImage((undefined4 *)&local_38,0,
              (int)((gameTrackerX.gameData.asmData.dispPage ^ 1U) << 0x18) >> 0x10);
    DrawSync(0);
    pp_Var4 = local_638;
    if (0 < iVar8) {
      newBlock = local_578;
      do {
        block = *pp_Var4;
        pp_Var4 = pp_Var4 + 1;
        VRAM_ClearVramBlock(block);
        iVar3 = iVar3 + 1;
        newBlock->next = (_BlockVramEntry *)0x0;
        newBlock->area = (int)newBlock->w * (int)newBlock->h;
        rootNode = VRAM_InsertionSort(rootNode,newBlock);
        newBlock = newBlock + 1;
      } while (iVar3 < iVar8);
    }
    while (rootNode != (_BlockVramEntry *)0x0) {
      local_34 = rootNode->w;
      local_32 = rootNode->h;
      local_38 = rootNode->x + -0x200;
      local_36 = sVar2;
      if (whichLayer != 0) {
        local_36 = sVar2 + -0x100;
      }
      local_36 = rootNode->y + local_36;
      local_30 = rootNode->x;
      local_2e[0] = rootNode->y;
      newBlock = VRAM_CheckVramSlot((short *)&local_30,(short *)local_2e,local_34,local_32,
                                    (uint)rootNode->type,(int)sVar9);
      if (newBlock == (_BlockVramEntry *)0x0) {
        VRAM_PrintInfo();
        VRAM_PrintVramBlock(rootNode);
      }
      MoveImage((undefined4 *)&local_38,(int)(short)local_30,(int)(short)local_2e[0]);
      DrawSync(0);
      bVar1 = rootNode->type;
      if (bVar1 == 2) {
        AdjustVramCoordsObject
                  ((int)rootNode->x,(int)rootNode->y,(int)(short)local_30,(int)(short)local_2e[0],
                   *(Object **)(rootNode->udata + 0x10));
        *(_BlockVramEntry **)(rootNode->udata + 0x18) = newBlock;
        newBlock->udata = rootNode->udata;
      }
      else {
        if ((2 < bVar1) && (bVar1 == 3)) {
          fontTracker.font_tpage =
               (short)(local_2e[0] & 0x100) >> 4 | (ushort)(((uint)local_30 & 0x3ff) >> 6) |
               (ushort)(((uint)local_2e[0] & 0x200) << 2);
          fontTracker.font_vramU = (short)(((uint)local_30 & 0x3f) << 2);
          fontTracker.font_vramV = local_2e[0] & 0xff;
          fontTracker.font_vramX = local_30;
          SpecialFogClut = local_30 >> 4 & 0x3f;
          fontTracker.font_clut = (local_2e[0] + 0x7e) * 0x40 | SpecialFogClut;
          fontTracker.font_vramY = local_2e[0];
          SpecialFogClut = (local_2e[0] + 0x7f) * 0x40 | SpecialFogClut;
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
// void /*$ra*/ VRAM_TransferBufferToVram(void *dataPtr /*$s3*/, long dataSize /*$s2*/, short status /*$s7*/, void *data1 /*$s0*/, void *data2 /*stack 16*/)
 // line 1131, offset 0x80074070
	/* begin block 1 */
		// Start line: 1132
		// Start offset: 0x80074070
		// Variables:
	// 		struct VramBuffer *vramControl; // $s1
	// 		struct RECT rect; // stack offset -48
	// 		long *nextOTag; // $s5
	// 		long *drawTimerReturn; // $fp

		/* begin block 1.1 */
			// Start line: 1161
			// Start offset: 0x80074104
		/* end block 1.1 */
		// End offset: 0x800741B8
		// End Line: 1190

		/* begin block 1.2 */
			// Start line: 1195
			// Start offset: 0x800741C0
		/* end block 1.2 */
		// End offset: 0x80074264
		// End Line: 1215

		/* begin block 1.3 */
			// Start line: 1251
			// Start offset: 0x80074280
		/* end block 1.3 */
		// End offset: 0x80074294
		// End Line: 1254
	/* end block 1 */
	// End offset: 0x800742B8
	// End Line: 1266

	/* begin block 2 */
		// Start line: 2262
	/* end block 2 */
	// End Line: 2263

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
    if (((status == 1) && (data2 != (void *)0x0)) && (*(short *)((int)data2 + 0x14) == 4)) {
      *(undefined2 *)((int)data2 + 0x14) = 2;
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
// void /*$ra*/ VRAM_LoadReturn(void *dataPtr /*$a0*/, void *data1 /*$a1*/, void *data2 /*$a2*/)
 // line 1271, offset 0x800742e8
	/* begin block 1 */
		// Start line: 1272
		// Start offset: 0x800742E8
	/* end block 1 */
	// End offset: 0x800742E8
	// End Line: 1272

	/* begin block 2 */
		// Start line: 2998
	/* end block 2 */
	// End Line: 2999

void VRAM_LoadReturn(void *dataPtr,void *data1,void *data2)

{
  MEMPACK_Free((char *)data1);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ VRAM_GetObjectVramSpace(struct VramSize *vramSize /*$v1*/, struct _ObjectTracker *objectTracker /*$s5*/)
 // line 1277, offset 0x80074308
	/* begin block 1 */
		// Start line: 1278
		// Start offset: 0x80074308
		// Variables:
	// 		struct RECT rect; // stack offset -40
	// 		long result; // $s4
	// 		struct _BlockVramEntry *lastVramBlockUsed; // $s0
	/* end block 1 */
	// End offset: 0x800743D8
	// End Line: 1315

	/* begin block 2 */
		// Start line: 3010
	/* end block 2 */
	// End Line: 3011

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
  p_Var1 = VRAM_CheckVramSlot(&local_28,&local_26,local_24,local_22,2,0x100);
  if (p_Var1 == (_BlockVramEntry *)0x0) {
    VRAM_RearrangeVramsLayer(1);
    p_Var1 = VRAM_CheckVramSlot(&local_28,&local_26,local_24,local_22,2,0x100);
    if (p_Var1 == (_BlockVramEntry *)0x0) {
      lVar2 = 0;
      VRAM_PrintInfo();
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
 // line 1321, offset 0x80074400
	/* begin block 1 */
		// Start line: 3149
	/* end block 1 */
	// End Line: 3150

	/* begin block 2 */
		// Start line: 3156
	/* end block 2 */
	// End Line: 3157

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_InitMorphPalettes(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VRAM_UpdateMorphPalettes()
 // line 1355, offset 0x80074408
	/* begin block 1 */
		// Start line: 3217
	/* end block 1 */
	// End Line: 3218

	/* begin block 2 */
		// Start line: 3318
	/* end block 2 */
	// End Line: 3319

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_UpdateMorphPalettes(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MORPH_ChangeAreaPalettes(long time /*$a0*/)
 // line 1513, offset 0x80074410
	/* begin block 1 */
		// Start line: 3533
	/* end block 1 */
	// End Line: 3534

	/* begin block 2 */
		// Start line: 3559
	/* end block 2 */
	// End Line: 3560

void MORPH_ChangeAreaPalettes(long time)

{
  return;
}





