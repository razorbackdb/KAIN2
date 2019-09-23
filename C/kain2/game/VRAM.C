#include "THISDUST.H"
#include "VRAM.H"

// _BlockVramEntry * @0x800D482C, len = 0x00000004
openVramBlocks = null;
// _BlockVramEntry @0x800D480C, len = 0x0000001C
TerrainVramBlock =
    {
        // _BlockVramEntry * @0x800D480C, len = 0x00000004
        .next = null,
        // uchar @0x800D4810, len = 0x00000001
        .type = 0x00,
        // uchar @0x800D4811, len = 0x00000001
        .flags = 0x00,
        // short @0x800D4812, len = 0x00000002
        .time = null,
        // short @0x800D4814, len = 0x00000002
        .newX = null,
        // short @0x800D4816, len = 0x00000002
        .newY = null,
        // short @0x800D4818, len = 0x00000002
        .x = null,
        // short @0x800D481A, len = 0x00000002
        .y = null,
        // short @0x800D481C, len = 0x00000002
        .w = null,
        // short @0x800D481E, len = 0x00000002
        .h = null,
        // long @0x800D4820, len = 0x00000004
        .area = null,
        // DEBUG_256fake @0x800D4824, len = 0x00000004
        .udata =
            {
                // _StreamUnit * @0x800D4824, len = 0x00000004
                .streamUnit = null,
                // _ObjectTracker * @0x800D4824, len = 0x00000004
                .streamObject = null,
                // _ButtonTexture * @0x800D4824, len = 0x00000004
                .button = null}};
// _BlockVramEntry * @0x800D4828, len = 0x00000004
usedVramBlocks = null;
// _BlockVramEntry @0x800D3E2C, len = 0x0000001C
vramBlockList =
    {
        // _BlockVramEntry * @0x800D3E2C, len = 0x00000004
        .next = null,
        // uchar @0x800D3E30, len = 0x00000001
        .type = 0x00,
        // uchar @0x800D3E31, len = 0x00000001
        .flags = 0x00,
        // short @0x800D3E32, len = 0x00000002
        .time = null,
        // short @0x800D3E34, len = 0x00000002
        .newX = null,
        // short @0x800D3E36, len = 0x00000002
        .newY = null,
        // short @0x800D3E38, len = 0x00000002
        .x = null,
        // short @0x800D3E3A, len = 0x00000002
        .y = null,
        // short @0x800D3E3C, len = 0x00000002
        .w = null,
        // short @0x800D3E3E, len = 0x00000002
        .h = null,
        // long @0x800D3E40, len = 0x00000004
        .area = null,
        // DEBUG_256fake @0x800D3E44, len = 0x00000004
        .udata =
            {
                // _StreamUnit * @0x800D3E44, len = 0x00000004
                .streamUnit = null,
                // _ObjectTracker * @0x800D3E44, len = 0x00000004
                .streamObject = null,
                // _ButtonTexture * @0x800D3E44, len = 0x00000004
                .button = null}};
// decompiled code
// original method signature:
// void /*$ra*/ VRAM_InitVramBlockCache()
// line 153, offset 0x800728d0
/* begin block 1 */
// Start line: 154
// Start offset: 0x800728D0
// Variables:
// 		int i; // $v1
/* end block 1 */
// End offset: 0x800728FC
// End Line: 179

/* begin block 2 */
// Start line: 228
/* end block 2 */
// End Line: 229

/* begin block 3 */
// Start line: 306
/* end block 3 */
// End Line: 307

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_InitVramBlockCache(void)

{
  _BlockVramEntry *p_Var1;
  int iVar2;

  iVar2 = 0x59;
  p_Var1 = &_BlockVramEntry_800d47e8;
  openVramBlocks = (_BlockVramEntry *)0x0;
  usedVramBlocks = (_BlockVramEntry *)0x0;
  numOfBlocksUsed = 0;
  do
  {
    p_Var1->flags = '\0';
    iVar2 = iVar2 + -1;
    p_Var1 = (_BlockVramEntry *)&p_Var1[-1].type;
  } while (-1 < iVar2);
  VRAM_InsertFreeVram(0x200, 0x100, 0x200, 0x100, 1);
  VRAM_InitMorphPalettes();
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_EnableTerrainArea()
// line 184, offset 0x80072930
/* begin block 1 */
// Start line: 300
/* end block 1 */
// End Line: 301

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_EnableTerrainArea(void)

{
  VRAM_InsertFreeVram(0x200, 0, 0x200, 0x100, 0);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_DisableTerrainArea()
// line 189, offset 0x80072960
/* begin block 1 */
// Start line: 311
/* end block 1 */
// End Line: 312

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_DisableTerrainArea(void)

{
  VRAM_DeleteFreeVram(0x200, 0, 0x200, 0x100);
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ VRAM_ConcatanateMemory(struct _BlockVramEntry *curBlock /*$s1*/)
// line 195, offset 0x8007298c
/* begin block 1 */
// Start line: 196
// Start offset: 0x8007298C
// Variables:
// 		struct _BlockVramEntry *nextBlock; // $s0
/* end block 1 */
// End offset: 0x80072B60
// End Line: 261

/* begin block 2 */
// Start line: 324
/* end block 2 */
// End Line: 325

int VRAM_ConcatanateMemory(_BlockVramEntry *curBlock)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  _BlockVramEntry *block;

  if (curBlock != (_BlockVramEntry *)0x0)
  {
    do
    {
      block = curBlock->next;
      while (block != (_BlockVramEntry *)0x0)
      {
        if ((curBlock->x == block->x) && (curBlock->w == block->w))
        {
          iVar2 = (uint)(ushort)curBlock->y << 0x10;
          iVar4 = iVar2 >> 0x10;
          iVar1 = (uint)(ushort)block->y << 0x10;
          iVar3 = iVar1 >> 0x10;
          if (iVar2 >> 0x18 == iVar1 >> 0x18)
          {
            if (iVar4 + (int)curBlock->h == iVar3)
            {
              curBlock->h = curBlock->h + block->h;
              goto LAB_80072ac4;
            }
            if (iVar3 + (int)block->h == iVar4)
            {
              block->h = block->h + curBlock->h;
              goto LAB_80072b28;
            }
          }
        }
        if ((curBlock->y == block->y) && (curBlock->h == block->h))
        {
          if (((int)curBlock->x + (int)curBlock->w == (int)block->x) &&
              (((curBlock->x & 0x3fU) == 0 || ((int)curBlock->w + (int)block->w < 0x41))))
          {
            curBlock->w = curBlock->w + block->w;
          LAB_80072ac4:
            VRAM_DeleteFreeBlock(block);
            block->flags = '\0';
            return 1;
          }
          if (((int)block->x + (int)block->w == (int)curBlock->x) &&
              (((block->x & 0x3fU) == 0 || ((int)curBlock->w + (int)block->w < 0x41))))
          {
            block->w = block->w + curBlock->w;
          LAB_80072b28:
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
// line 263, offset 0x80072b74
/* begin block 1 */
// Start line: 463
/* end block 1 */
// End Line: 464

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_GarbageCollect(void)

{
  int iVar1;

  do
  {
    iVar1 = VRAM_ConcatanateMemory(openVramBlocks);
  } while (iVar1 == 1);
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ VRAM_InsertFreeBlock(struct _BlockVramEntry *block /*$a0*/)
// line 270, offset 0x80072ba8
/* begin block 1 */
// Start line: 271
// Start offset: 0x80072BA8
// Variables:
// 		struct _BlockVramEntry *next; // $v1
// 		struct _BlockVramEntry *prev; // $a1
/* end block 1 */
// End offset: 0x80072C28
// End Line: 301

/* begin block 2 */
// Start line: 478
/* end block 2 */
// End Line: 479

int VRAM_InsertFreeBlock(_BlockVramEntry *block)

{
  int iVar1;
  _BlockVramEntry *p_Var2;
  _BlockVramEntry *p_Var3;
  _BlockVramEntry *p_Var4;

  if (block == (_BlockVramEntry *)0x0)
  {
    iVar1 = 0;
  }
  else
  {
    p_Var3 = openVramBlocks;
    p_Var4 = (_BlockVramEntry *)0x0;
    if (openVramBlocks != (_BlockVramEntry *)0x0)
    {
      p_Var3 = openVramBlocks;
      p_Var4 = (_BlockVramEntry *)0x0;
      do
      {
        p_Var2 = p_Var3;
        p_Var3 = p_Var2;
        if (block->area <= p_Var2->area)
          break;
        p_Var3 = p_Var2->next;
        p_Var4 = p_Var2;
      } while (p_Var3 != (_BlockVramEntry *)0x0);
    }
    if (p_Var4 == (_BlockVramEntry *)0x0)
    {
      p_Var3 = block;
      block->next = openVramBlocks;
      openVramBlocks = p_Var3;
    }
    else
    {
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
// line 304, offset 0x80072c38
/* begin block 1 */
// Start line: 306
// Start offset: 0x80072C38
// Variables:
// 		struct _BlockVramEntry *next; // $v1
// 		struct _BlockVramEntry *prev; // $a1
/* end block 1 */
// End offset: 0x80072C98
// End Line: 330

/* begin block 2 */
// Start line: 547
/* end block 2 */
// End Line: 548

/* begin block 3 */
// Start line: 548
/* end block 3 */
// End Line: 549

/* begin block 4 */
// Start line: 549
/* end block 4 */
// End Line: 550

void VRAM_DeleteFreeBlock(_BlockVramEntry *block)

{
  _BlockVramEntry *p_Var1;
  _BlockVramEntry *p_Var2;
  _BlockVramEntry *p_Var3;

  p_Var3 = (_BlockVramEntry *)0x0;
  if (block != (_BlockVramEntry *)0x0)
  {
    p_Var2 = openVramBlocks;
    if (block != openVramBlocks)
    {
      do
      {
        p_Var1 = p_Var2;
        p_Var2 = p_Var1;
        if (p_Var1 == (_BlockVramEntry *)0x0)
          break;
        p_Var2 = p_Var1->next;
        p_Var3 = p_Var1;
      } while (block != p_Var2);
      if (block != p_Var2)
      {
        return;
      }
    }
    if (p_Var3 != (_BlockVramEntry *)0x0)
    {
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
// line 333, offset 0x80072ca0
/* begin block 1 */
// Start line: 605
/* end block 1 */
// End Line: 606

/* begin block 2 */
// Start line: 606
/* end block 2 */
// End Line: 607

void VRAM_InsertUsedBlock(_BlockVramEntry *block)

{
  if (block != (_BlockVramEntry *)0x0)
  {
    if (usedVramBlocks == (_BlockVramEntry *)0x0)
    {
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
// line 349, offset 0x80072cd4
/* begin block 1 */
// Start line: 351
// Start offset: 0x80072CD4
// Variables:
// 		struct _BlockVramEntry *next; // $v1
// 		struct _BlockVramEntry *prev; // $a1
/* end block 1 */
// End offset: 0x80072D30
// End Line: 372

/* begin block 2 */
// Start line: 637
/* end block 2 */
// End Line: 638

/* begin block 3 */
// Start line: 638
/* end block 3 */
// End Line: 639

/* begin block 4 */
// Start line: 640
/* end block 4 */
// End Line: 641

void VRAM_DeleteUsedBlock(_BlockVramEntry *block)

{
  _BlockVramEntry *p_Var1;
  _BlockVramEntry *p_Var2;
  _BlockVramEntry *p_Var3;

  p_Var3 = (_BlockVramEntry *)0x0;
  p_Var2 = usedVramBlocks;
  if (block != usedVramBlocks)
  {
    do
    {
      p_Var1 = p_Var2;
      p_Var2 = p_Var1;
      if (p_Var1 == (_BlockVramEntry *)0x0)
        break;
      p_Var2 = p_Var1->next;
      p_Var3 = p_Var1;
    } while (block != p_Var2);
    if (block != p_Var2)
    {
      return;
    }
  }
  if (p_Var3 != (_BlockVramEntry *)0x0)
  {
    p_Var3->next = block->next;
    return;
  }
  usedVramBlocks = block->next;
  return;
}

// decompiled code
// original method signature:
// struct _BlockVramEntry * /*$ra*/ VRAM_GetOpenBlock()
// line 374, offset 0x80072d38
/* begin block 1 */
// Start line: 376
// Start offset: 0x80072D38
// Variables:
// 		int i; // $a0
/* end block 1 */
// End offset: 0x80072D64
// End Line: 389

/* begin block 2 */
// Start line: 689
/* end block 2 */
// End Line: 690

/* begin block 3 */
// Start line: 690
/* end block 3 */
// End Line: 691

/* begin block 4 */
// Start line: 692
/* end block 4 */
// End Line: 693

/* WARNING: Unknown calling convention yet parameter storage is locked */

_BlockVramEntry *VRAM_GetOpenBlock(void)

{
  _BlockVramEntry *p_Var1;
  int iVar2;

  iVar2 = 0;
  p_Var1 = &vramBlockList;
  do
  {
    iVar2 = iVar2 + 1;
    if (p_Var1->flags == '\0')
    {
      return p_Var1;
    }
    p_Var1 = p_Var1 + 1;
  } while (iVar2 < 0x5a);
  return (_BlockVramEntry *)0x0;
}

// decompiled code
// original method signature:
// int /*$ra*/ VRAM_DeleteFreeVram(short x /*$a0*/, short y /*$a1*/, short w /*$a2*/, short h /*$a3*/)
// line 391, offset 0x80072d6c
/* begin block 1 */
// Start line: 392
// Start offset: 0x80072D6C
// Variables:
// 		struct _BlockVramEntry *prev; // $t1
// 		struct _BlockVramEntry *vblock; // $a2
// 		struct _BlockVramEntry *nextVBlock; // $t0
// 		struct _BlockVramEntry (*blockLists[2]); // stack offset -24
// 		int i; // $t2
// 		int delCount; // $t3
/* end block 1 */
// End offset: 0x80072E88
// End Line: 427

/* begin block 2 */
// Start line: 727
/* end block 2 */
// End Line: 728

int VRAM_DeleteFreeVram(short x, short y, short w, short h)

{
  _BlockVramEntry *p_Var1;
  _BlockVramEntry *p_Var2;
  _BlockVramEntry *p_Var3;
  _BlockVramEntry *p_Var4;
  int iVar5;
  int iVar6;
  _BlockVramEntry **pp_Var7;
  _BlockVramEntry *local_18[4];

  pp_Var7 = local_18;
  iVar6 = 0;
  iVar5 = 0;
  do
  {
    if (*pp_Var7 != (_BlockVramEntry *)0x0)
    {
      p_Var1 = *pp_Var7;
      p_Var3 = (_BlockVramEntry *)0x0;
      do
      {
        p_Var2 = p_Var1->next;
        p_Var4 = p_Var1;
        if (((((int)x <= (int)p_Var1->x) &&
              (p_Var4 = p_Var1, (int)p_Var1->x + (int)p_Var1->w <= (int)x + (int)w)) &&
             (p_Var4 = p_Var1, (int)y <= (int)p_Var1->y)) &&
            (p_Var4 = p_Var1, (int)p_Var1->y + (int)p_Var1->h <= (int)y + (int)h))
        {
          p_Var1->flags = '\0';
          if (p_Var3 == (_BlockVramEntry *)0x0)
          {
            if (iVar5 == 0)
            {
              iVar6 = iVar6 + 1;
              p_Var4 = p_Var3;
              openVramBlocks = p_Var2;
            }
            else
            {
              iVar6 = iVar6 + 1;
              p_Var4 = p_Var3;
              usedVramBlocks = p_Var2;
            }
          }
          else
          {
            p_Var3->next = p_Var2;
            iVar6 = iVar6 + 1;
            p_Var4 = p_Var3;
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
// line 430, offset 0x80072e9c
/* begin block 1 */
// Start line: 431
// Start offset: 0x80072E9C
// Variables:
// 		struct _BlockVramEntry *useBlock; // $a0
/* end block 1 */
// End offset: 0x80072FFC
// End Line: 476

/* begin block 2 */
// Start line: 841
/* end block 2 */
// End Line: 842

int VRAM_InsertFreeVram(short x, short y, short w, short h, int flags)

{
  short sVar1;
  _BlockVramEntry *block;
  uchar uVar2;
  long lVar3;

  uVar2 = (uchar)flags;
  if (((x & 0x3fU) == 0) || ((int)w <= (int)(0x40 - ((uint)(ushort)x & 0x3f))))
  {
    block = VRAM_GetOpenBlock();
    lVar3 = (int)w * (int)h;
    block->next = (_BlockVramEntry *)0x0;
    block->flags = uVar2;
    block->time = 0;
    block->x = x;
    block->y = y;
    block->w = w;
    block->h = h;
  }
  else
  {
    block = VRAM_GetOpenBlock();
    sVar1 = (short)((uint)(ushort)x & 0x3f);
    block->w = 0x40 - sVar1;
    block->next = (_BlockVramEntry *)0x0;
    block->flags = uVar2;
    block->time = 0;
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
// struct _BlockVramEntry * /*$ra*/ VRAM_CheckVramSlot(short *x /*stack 0*/, short *y /*stack 4*/, short w /*$s7*/, short h /*$s6*/, int type /*stack 16*/, int startY /*stack 20*/)
// line 487, offset 0x80073030
/* begin block 1 */
// Start line: 488
// Start offset: 0x80073030
// Variables:
// 		struct _BlockVramEntry *vblock; // $s1
// 		short hldx; // $s3
// 		short hldy; // $s4
// 		short hldw; // $s0
// 		short hldh; // $s5
// 		long fits; // $s2
// 		long offset; // $s0
// 		int wdiff; // $t1
// 		int hdiff; // $v1
// 		struct _BlockVramEntry *vblockleft; // $t3
// 		long offsetleft; // $t2
// 		struct _BlockVramEntry *vblockright; // $s4
// 		long offsetright; // $s3

/* begin block 1.1 */
// Start line: 546
// Start offset: 0x80073170
// Variables:
// 		int newx; // $v0
/* end block 1.1 */
// End offset: 0x800731AC
// End Line: 553

/* begin block 1.2 */
// Start line: 570
// Start offset: 0x800731C4
/* end block 1.2 */
// End offset: 0x800731F4
// End Line: 590
/* end block 1 */
// End offset: 0x800733F8
// End Line: 741

/* begin block 2 */
// Start line: 997
/* end block 2 */
// End Line: 998

_BlockVramEntry *VRAM_CheckVramSlot(short *x, short *y, short w, short h, int type, int startY)

{
  undefined *puVar1;
  ushort x_00;
  int iVar2;
  ushort y_00;
  undefined *puVar3;
  short w_00;
  uint uVar4;
  int iVar5;
  ushort h_00;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  int iVar10;
  _BlockVramEntry *p_Var11;
  int iVar12;
  uint uVar13;
  _BlockVramEntry *block;
  int iVar14;
  short w_01;
  _BlockVramEntry *p_Var15;
  uint uVar16;

  uVar6 = (uint)(ushort)h;
  uVar4 = (uint)(ushort)w;
  iVar14 = 2;
  p_Var11 = (_BlockVramEntry *)0x0;
  iVar10 = 0;
  p_Var15 = (_BlockVramEntry *)0x0;
  _w_01 = 0;
  w_01 = 0;
  puVar1 = &DAT_0000270f;
  puVar9 = &DAT_0000270f;
  block = openVramBlocks;
  if (openVramBlocks != (_BlockVramEntry *)0x0)
  {
    iVar8 = (int)w;
    iVar7 = (int)h;
    iVar12 = (int)(short)startY;
    block = openVramBlocks;
    do
    {
      if ((int)block->w < iVar8)
      {
      LAB_800731f4:
        w_01 = (short)_w_01;
        if ((puVar9 == (undefined *)0x0) && (puVar1 == (undefined *)0x0))
          break;
      }
      else
      {
        puVar3 = (undefined *)((int)block->w - iVar8);
        if ((((int)block->h < iVar7) || ((int)puVar9 < (int)puVar3)) ||
            ((iVar12 != -1 && (((int)block->y < iVar12 || (iVar12 + 0x100 <= (int)block->y))))))
          goto LAB_800731f4;
        if ((puVar3 != puVar9) || ((int)block->h - iVar7 < (int)puVar1))
        {
          x_00 = block->x;
          iVar5 = 0x40 - ((uint)x_00 & 0x3f);
          if ((x_00 & 0x3f) == 0)
          {
          LAB_80073150:
            iVar14 = 0;
            iVar10 = 0;
            puVar9 = (undefined *)((int)block->w - iVar8);
            puVar1 = (undefined *)((int)block->h - iVar7);
            p_Var11 = block;
          }
          else
          {
            if (iVar5 < iVar8)
            {
              if ((iVar14 != 0) && (iVar2 = (int)block->w, iVar8 <= iVar2 - iVar5))
              {
                iVar14 = 1;
                p_Var15 = block;
              LAB_800731e8:
                puVar9 = (undefined *)(iVar2 - iVar8);
                puVar1 = (undefined *)((int)block->h - iVar7);
                _w_01 = iVar5;
              }
            }
            else
            {
              if ((x_00 & 0xf) == 0)
                goto LAB_80073150;
              iVar5 = 0x10 - ((uint)x_00 & 0xf);
              if ((iVar8 <= (int)(0x40 - ((int)(short)x_00 + iVar5 & 0x3fU))) &&
                  (iVar2 = (int)block->w, iVar8 <= iVar2 - iVar5))
              {
                iVar14 = 0;
                iVar10 = iVar5;
                p_Var11 = block;
                iVar5 = _w_01;
                goto LAB_800731e8;
              }
            }
          }
          goto LAB_800731f4;
        }
      }
      w_01 = (short)_w_01;
      block = block->next;
    } while (block != (_BlockVramEntry *)0x0);
  }
  if ((iVar14 == 0) && (block = p_Var11, iVar10 != 0))
  {
    w_00 = (short)iVar10;
    VRAM_InsertFreeVram(p_Var11->x, p_Var11->y, w_00, p_Var11->h, (uint)p_Var11->flags);
    p_Var11->x = p_Var11->x + w_00;
    p_Var11->w = p_Var11->w - w_00;
    block = p_Var11;
  }
  if (block == (_BlockVramEntry *)0x0)
  {
    if ((p_Var15 != (_BlockVramEntry *)0x0) && (iVar14 == 1))
    {
      iVar14 = 0;
      VRAM_InsertFreeVram(p_Var15->x, p_Var15->y, w_01, p_Var15->h, (uint)p_Var15->flags);
      p_Var15->x = p_Var15->x + w_01;
      p_Var15->w = p_Var15->w - w_01;
      block = p_Var15;
    }
    if (block == (_BlockVramEntry *)0x0)
    {
      return (_BlockVramEntry *)0x0;
    }
  }
  if (iVar14 == 0)
  {
    x_00 = block->x;
    y_00 = block->y;
    uVar13 = (uint)(ushort)block->w;
    h_00 = block->h;
    uVar16 = (uint)h_00;
    VRAM_DeleteFreeBlock(block);
    block->next = (_BlockVramEntry *)0x0;
    block->flags = '\x01';
    block->type = (uchar)type;
    block->w = w;
    block->h = h;
    VRAM_InsertUsedBlock(block);
    *x = block->x;
    *y = block->y;
    if (uVar13 << 0x10 == uVar4 << 0x10)
    {
      if (uVar16 << 0x10 == uVar6 << 0x10)
      {
        return block;
      }
      y_00 = (ushort)(((uint)y_00 + uVar6) * 0x10000 >> 0x10);
      h_00 = (ushort)((uVar16 - uVar6) * 0x10000 >> 0x10);
    }
    else
    {
      if (uVar16 << 0x10 == uVar6 << 0x10)
      {
        x_00 = (ushort)(((uint)x_00 + uVar4) * 0x10000 >> 0x10);
        w = (short)((uVar13 - uVar4) * 0x10000 >> 0x10);
      }
      else
      {
        VRAM_InsertFreeVram((short)(((uint)x_00 + uVar4) * 0x10000 >> 0x10), y_00,
                            (short)((uVar13 - uVar4) * 0x10000 >> 0x10), h_00, 1);
        y_00 = (ushort)(((uint)y_00 + uVar6) * 0x10000 >> 0x10);
        h_00 = (ushort)((uVar16 - uVar6) * 0x10000 >> 0x10);
      }
    }
    VRAM_InsertFreeVram(x_00, y_00, w, h_00, 1);
  }
  return block;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_ClearVramBlock(struct _BlockVramEntry *block /*$s0*/)
// line 745, offset 0x8007342c
/* begin block 1 */
// Start line: 1593
/* end block 1 */
// End Line: 1594

void VRAM_ClearVramBlock(_BlockVramEntry *block)

{
  if (block != (_BlockVramEntry *)0x0)
  {
    VRAM_DeleteUsedBlock(block);
    VRAM_InsertFreeBlock(block);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ AdjustVramCoordsObject(int oldx /*$s3*/, int oldy /*$s1*/, int newx /*$a2*/, int newy /*$t7*/, struct Object *object /*stack 16*/)
// line 825, offset 0x80073460
/* begin block 1 */
// Start line: 826
// Start offset: 0x80073460
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
// End offset: 0x80073628
// End Line: 884

/* begin block 2 */
// Start line: 1753
/* end block 2 */
// End Line: 1754

void AdjustVramCoordsObject(int oldx, int oldy, int newx, int newy, Object *object)

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
  if (0 < object->numModels)
  {
    do
    {
      p_Var8 = object->modelList[iVar9];
      pTVar6 = p_Var8->startTextures;
      if ((pTVar6 != (TextureMT3 *)0x0) && (pTVar6 < p_Var8->endTextures))
      {
        puVar7 = &pTVar6->clut;
        do
        {
          uVar1 = puVar7[2];
          uVar5 = newy + (((uint)uVar1 & 0x10) * 0x10 - (oldy & 0xffffff00U));
          uVar2 = *puVar7;
          *(char *)((int)puVar7 + -1) = *(char *)((int)puVar7 + -1) + cVar3;
          *(char *)((int)puVar7 + 7) = *(char *)((int)puVar7 + 7) + cVar3;
          *(char *)((int)puVar7 + 3) = *(char *)((int)puVar7 + 3) + cVar3;
          cVar4 = (char)(((int)(((newx & 0x3fU) - (oldx & 0x3fU)) * 0x10000) >> 0x10) << (2 - ((uint)(uVar1 >> 7) & 3) & 0x1f));
          pTVar6->u0 = pTVar6->u0 + cVar4;
          pTVar6 = pTVar6 + 1;
          puVar7[2] = uVar1 & 0x1e0 |
                      (ushort)((int)(uVar5 & 0x100) >> 4) |
                      (ushort)((int)((newx & 0xffffffc0U) +
                                         (((uint)uVar1 & 0xf) * 0x40 - (oldx & 0xffffffc0U)) &
                                     0x3ff) >>
                               6) |
                      (ushort)((uVar5 & 0x200) << 2);
          *puVar7 = ((short)newy + ((uVar2 >> 6) - (short)oldy)) * 0x40 |
                    (ushort)((int)((newx & 0xfffffff0U) +
                                   (((uint)uVar2 & 0x3f) * 0x10 - (oldx & 0xfffffff0U))) >>
                             4) &
                        0x3f;
          *(char *)(puVar7 + 1) = *(char *)(puVar7 + 1) + cVar4;
          *(char *)(puVar7 + 3) = *(char *)(puVar7 + 3) + cVar4;
          puVar7 = puVar7 + 8;
        } while (pTVar6 < p_Var8->endTextures);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)object->numModels);
  }
  return;
}

// decompiled code
// original method signature:
// struct _BlockVramEntry * /*$ra*/ VRAM_InsertionSort(struct _BlockVramEntry *rootNode /*$a0*/, struct _BlockVramEntry *newBlock /*$a1*/, int pack_type /*$a2*/)
// line 922, offset 0x8007364c
/* begin block 1 */
// Start line: 925
// Start offset: 0x8007364C
// Variables:
// 		struct _BlockVramEntry *next; // $a3
// 		struct _BlockVramEntry *prev; // $t0
/* end block 1 */
// End offset: 0x800736FC
// End Line: 965

/* begin block 2 */
// Start line: 2127
/* end block 2 */
// End Line: 2128

/* begin block 3 */
// Start line: 2129
/* end block 3 */
// End Line: 2130

/* begin block 4 */
// Start line: 2131
/* end block 4 */
// End Line: 2132

_BlockVramEntry *
VRAM_InsertionSort(_BlockVramEntry *rootNode, _BlockVramEntry *newBlock, int pack_type)

{
  _BlockVramEntry *p_Var1;
  _BlockVramEntry *p_Var2;
  _BlockVramEntry *p_Var3;

  p_Var3 = (_BlockVramEntry *)0x0;
  p_Var1 = rootNode;
  if (pack_type == 0)
  {
    p_Var2 = rootNode;
    if (rootNode != (_BlockVramEntry *)0x0)
    {
      p_Var2 = rootNode;
      do
      {
        p_Var1 = p_Var2;
        p_Var2 = p_Var1;
        if (p_Var1->area <= newBlock->area)
          break;
        p_Var2 = p_Var1->next;
        p_Var3 = p_Var1;
      } while (p_Var2 != (_BlockVramEntry *)0x0);
    }
  }
  else
  {
    while (p_Var2 = p_Var1, p_Var2 != (_BlockVramEntry *)0x0)
    {
      if ((p_Var2->w <= newBlock->w) && ((newBlock->w != p_Var2->w || (p_Var2->h <= newBlock->h))))
        break;
      p_Var1 = p_Var2->next;
      p_Var3 = p_Var2;
    }
  }
  if (p_Var3 == (_BlockVramEntry *)0x0)
  {
    newBlock->next = rootNode;
    rootNode = newBlock;
  }
  else
  {
    newBlock->next = p_Var2;
    p_Var3->next = newBlock;
  }
  return rootNode;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_ClearVram()
// line 970, offset 0x80073704
/* begin block 1 */
// Start line: 971
// Start offset: 0x80073704
// Variables:
// 		struct _BlockVramEntry *vblock; // $a0
// 		struct _BlockVramEntry *next; // $s0
/* end block 1 */
// End offset: 0x80073730
// End Line: 981

/* begin block 2 */
// Start line: 2226
/* end block 2 */
// End Line: 2227

/* begin block 3 */
// Start line: 2229
/* end block 3 */
// End Line: 2230

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_ClearVram(void)

{
  _BlockVramEntry *block;
  _BlockVramEntry *p_Var1;

  block = usedVramBlocks;
  if (usedVramBlocks != (_BlockVramEntry *)0x0)
  {
    do
    {
      p_Var1 = block->next;
      VRAM_ClearVramBlock(block);
      block = p_Var1;
    } while (p_Var1 != (_BlockVramEntry *)0x0);
  }
  return;
}

// decompiled code
// original method signature:
// struct _BlockVramEntry * /*$ra*/ VRAM_RearrangeVramsLayer(long whichLayer /*stack 0*/, short *AddX /*stack 4*/, short *AddY /*stack 8*/, short AddW /*$fp*/, int AddH /*stack 16*/, int AddType /*stack 20*/, int AddStartY /*stack 24*/)
// line 991, offset 0x80073740
/* begin block 1 */
// Start line: 992
// Start offset: 0x80073740
// Variables:
// 		struct _BlockVramEntry *vblock; // $a0
// 		struct _BlockVramEntry *retvblock; // $s5
// 		struct _BlockVramEntry *sortedBlocks; // $s2
// 		struct _BlockVramEntry *curBlock; // $s0
// 		struct _BlockVramEntry (*savedVramBlocksPTR[48]); // stack offset -1624
// 		struct _BlockVramEntry savedVramBlocks[48]; // stack offset -1432
// 		struct RECT vramLoc; // stack offset -88
// 		long numBlocks; // $s3
// 		long d; // $s1
// 		int error_retry; // $s4
// 		int good_pack; // $s7
// 		int pack_type; // $s6
// 		short x; // stack offset -80
// 		short y; // stack offset -78
// 		short dispYPos; // stack offset -56

/* begin block 1.1 */
// Start line: 1052
// Start offset: 0x80073868
// Variables:
// 		int startY; // stack offset -48

/* begin block 1.1.1 */
// Start line: 1117
// Start offset: 0x80073A70
// Variables:
// 		int type; // $t0
/* end block 1.1.1 */
// End offset: 0x80073C08
// End Line: 1217
/* end block 1.1 */
// End offset: 0x80073D8C
// End Line: 1278
/* end block 1 */
// End offset: 0x80073D8C
// End Line: 1281

/* begin block 2 */
// Start line: 2271
/* end block 2 */
// End Line: 2272

/* begin block 3 */
// Start line: 2292
/* end block 3 */
// End Line: 2293

_BlockVramEntry *
VRAM_RearrangeVramsLayer(long whichLayer, short *AddX, short *AddY, short AddW, int AddH, int AddType, int AddStartY)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  _BlockVramEntry **pp_Var8;
  _BlockVramEntry *rootNode;
  _BlockVramEntry **pp_Var9;
  uint type;
  _BlockVramEntry *newBlock;
  _BlockVramEntry *p_Var10;
  undefined4 uVar11;
  long lVar12;
  _BlockVramEntry *p_Var13;
  undefined4 uVar14;
  undefined4 uVar15;
  int iVar16;
  int iVar17;
  _BlockVramEntry *block;
  _BlockVramEntry *local_658[48];
  undefined local_598[4];
  undefined local_594[4];
  undefined local_590[4];
  undefined local_58c[4];
  undefined local_588[8];
  undefined local_580[1320];
  short local_58;
  short local_56;
  short local_54;
  short local_52;
  ushort local_50;
  ushort local_4e[3];
  short local_48;
  short local_40;
  short local_38;
  undefined4 local_30;

  block = (_BlockVramEntry *)0x0;
  iVar16 = 0;
  local_48 = (short)AddType;
  local_40 = (short)AddStartY;
  if ((gameTrackerX.gameFlags & 0x8000000U) != 0)
  {
    GAMELOOP_Set_Pause_Redraw();
  }
  if (usedVramBlocks != (_BlockVramEntry *)0x0)
  {
    pp_Var9 = (_BlockVramEntry **)local_598;
    pp_Var8 = local_658;
    rootNode = usedVramBlocks;
    do
    {
      if (whichLayer == 0)
      {
        if (rootNode->y < 0x100)
        {
          *pp_Var8 = rootNode;
        LAB_8007380c:
          newBlock = *(_BlockVramEntry **)&rootNode->type;
          p_Var10 = *(_BlockVramEntry **)&rootNode->newX;
          p_Var13 = *(_BlockVramEntry **)&rootNode->x;
          *pp_Var9 = rootNode->next;
          pp_Var9[1] = newBlock;
          pp_Var9[2] = p_Var10;
          pp_Var9[3] = p_Var13;
          newBlock = (_BlockVramEntry *)rootNode->area;
          p_Var10 = (_BlockVramEntry *)rootNode->udata;
          pp_Var9[4] = *(_BlockVramEntry **)&rootNode->w;
          pp_Var9[5] = newBlock;
          pp_Var9[6] = p_Var10;
          pp_Var9 = pp_Var9 + 7;
          pp_Var8 = pp_Var8 + 1;
          iVar16 = iVar16 + 1;
        }
      }
      else
      {
        if (0xff < rootNode->y)
        {
          *pp_Var8 = rootNode;
          goto LAB_8007380c;
        }
      }
      rootNode = rootNode->next;
    } while (rootNode != (_BlockVramEntry *)0x0);
  }
  if (0 < iVar16)
  {
    if (whichLayer == 0)
    {
      local_30 = 0;
      local_56 = 0;
    }
    else
    {
      local_30 = 0x100;
      local_56 = 0x100;
    }
    local_54 = 0x200;
    local_58 = 0x200;
    local_52 = 0x100;
    do
    {
      do
      {
        iVar7 = CheckVolatile(gameTrackerX.drawTimerReturn);
      } while (iVar7 != 0);
      iVar7 = CheckVolatile(gameTrackerX.reqDisp);
    } while (iVar7 != 0);
    bVar6 = false;
    iVar7 = 0;
    rootNode = (_BlockVramEntry *)0x0;
    local_38 = (short)((gameTrackerX.gameData.asmData.dispPage ^ 1U) << 8);
    MoveImage((undefined4 *)&local_58, 0,
              (int)((gameTrackerX.gameData.asmData.dispPage ^ 1U) << 0x18) >> 0x10);
    DrawSync(0);
    if (0 < iVar16)
    {
      pp_Var8 = local_658;
      iVar17 = 0;
      do
      {
        block = *pp_Var8;
        pp_Var8 = pp_Var8 + 1;
        VRAM_ClearVramBlock(block);
        sVar2 = *(short *)(local_598 + iVar17 + 0x10);
        sVar3 = *(short *)(local_598 + iVar17 + 0x12);
        iVar7 = iVar7 + 1;
        ((_BlockVramEntry *)(local_598 + iVar17))->next = (_BlockVramEntry *)0x0;
        *(int *)(local_598 + iVar17 + 0x14) = (int)sVar2 * (int)sVar3;
        rootNode = VRAM_InsertionSort(rootNode, (_BlockVramEntry *)(local_598 + iVar17), 0);
        iVar17 = iVar17 + 0x1c;
      } while (iVar7 < iVar16);
    }
    if (AddX != (short *)0x0)
    {
      block = VRAM_CheckVramSlot(AddX, AddY, AddW, (short)AddH, (int)local_48, (int)local_40);
      pp_Var8 = local_658 + iVar16;
      iVar7 = iVar16 * 0x1c;
      newBlock = (_BlockVramEntry *)(local_598 + iVar7);
      *pp_Var8 = block;
      uVar11 = *(undefined4 *)&block->type;
      uVar14 = *(undefined4 *)&block->newX;
      uVar15 = *(undefined4 *)&block->x;
      newBlock->next = block->next;
      *(undefined4 *)(local_598 + iVar7 + 4) = uVar11;
      *(undefined4 *)(local_598 + iVar7 + 8) = uVar14;
      *(undefined4 *)(local_598 + iVar7 + 0xc) = uVar15;
      lVar12 = block->area;
      uVar11 = block->udata;
      *(undefined4 *)(local_598 + iVar7 + 0x10) = *(undefined4 *)&block->w;
      *(long *)(local_598 + iVar7 + 0x14) = lVar12;
      *(undefined4 *)(local_598 + iVar7 + 0x18) = uVar11;
      iVar16 = iVar16 + 1;
      VRAM_ClearVramBlock(*pp_Var8);
      sVar2 = *(short *)(local_598 + iVar7 + 0x10);
      sVar3 = *(short *)(local_598 + iVar7 + 0x12);
      newBlock->next = (_BlockVramEntry *)0x0;
      local_598[iVar7 + 4] = 5;
      *(int *)(local_598 + iVar7 + 0x14) = (int)sVar2 * (int)sVar3;
      rootNode = VRAM_InsertionSort(rootNode, newBlock, 0);
    }
    bVar4 = false;
    do
    {
      block = (_BlockVramEntry *)0x0;
      bVar5 = true;
      newBlock = rootNode;
      while (newBlock != (_BlockVramEntry *)0x0)
      {
        if (newBlock->type == '\x05')
        {
          if (!bVar4)
          {
            type = SEXT24(local_48);
            goto LAB_80073aa0;
          }
        }
        else
        {
          type = (uint)newBlock->type;
        LAB_80073aa0:
          local_50 = newBlock->x;
          local_4e[0] = newBlock->y;
          p_Var10 = VRAM_CheckVramSlot((short *)&local_50, (short *)local_4e, newBlock->w, newBlock->h,
                                       type, (int)(short)local_30);
          if (newBlock->type == '\x05')
          {
            *AddX = local_50;
            *AddY = local_4e[0];
            block = p_Var10;
          }
          if (p_Var10 == (_BlockVramEntry *)0x0)
          {
            bVar5 = false;
            if (!bVar6)
            {
              bVar6 = true;
              VRAM_ClearVram();
              iVar7 = 0;
              rootNode = (_BlockVramEntry *)0x0;
              newBlock = (_BlockVramEntry *)local_598;
              if (0 < iVar16)
              {
                do
                {
                  newBlock->next = (_BlockVramEntry *)0x0;
                  rootNode = VRAM_InsertionSort(rootNode, newBlock, 1);
                  iVar7 = iVar7 + 1;
                  newBlock = newBlock + 1;
                } while (iVar7 < iVar16);
              }
              break;
            }
            if ((AddX != (short *)0x0) && (!bVar4))
            {
              bVar4 = true;
              VRAM_ClearVram();
              bVar6 = false;
              rootNode = (_BlockVramEntry *)0x0;
              iVar7 = 0;
              block = (_BlockVramEntry *)0x0;
              newBlock = (_BlockVramEntry *)local_598;
              if (0 < iVar16)
              {
                do
                {
                  newBlock->next = (_BlockVramEntry *)0x0;
                  rootNode = VRAM_InsertionSort(rootNode, newBlock, 0);
                  iVar7 = iVar7 + 1;
                  newBlock = newBlock + 1;
                } while (iVar7 < iVar16);
              }
              break;
            }
          }
          if (newBlock->type == '\x02')
          {
            *(_BlockVramEntry **)(newBlock->udata + 0x18) = p_Var10;
            p_Var10->udata = newBlock->udata;
          }
          newBlock->newX = local_50;
          newBlock->newY = local_4e[0];
        }
        newBlock = newBlock->next;
      }
    } while (!bVar5);
    while (rootNode != (_BlockVramEntry *)0x0)
    {
      local_54 = rootNode->w;
      local_52 = rootNode->h;
      local_58 = rootNode->x + -0x200;
      local_56 = local_38;
      if (whichLayer != 0)
      {
        local_56 = local_38 + -0x100;
      }
      local_56 = rootNode->y + local_56;
      local_50 = rootNode->newX;
      local_4e[0] = rootNode->newY;
      bVar1 = rootNode->type;
      if (bVar1 != 5)
      {
        MoveImage((undefined4 *)&local_58, (int)(short)local_50, (int)(short)local_4e[0]);
        DrawSync(0);
        bVar1 = rootNode->type;
      }
      if (bVar1 == 2)
      {
        AdjustVramCoordsObject((int)rootNode->x, (int)rootNode->y, (int)(short)local_50, (int)(short)local_4e[0],
                               *(Object **)(rootNode->udata + 0x10));
      }
      else
      {
        if ((2 < bVar1) && (bVar1 == 3))
        {
          fontTracker.font_tpage =
              (short)(local_4e[0] & 0x100) >> 4 | (ushort)(((uint)local_50 & 0x3ff) >> 6) |
              (ushort)(((uint)local_4e[0] & 0x200) << 2);
          fontTracker.font_vramU = (short)(((uint)local_50 & 0x3f) << 2);
          fontTracker.font_vramV = local_4e[0] & 0xff;
          fontTracker.font_vramX = local_50;
          SpecialFogClut = local_50 >> 4 & 0x3f;
          fontTracker.font_clut = (local_4e[0] + 0x7e) * 0x40 | SpecialFogClut;
          fontTracker.font_vramY = local_4e[0];
          SpecialFogClut = (local_4e[0] + 0x7f) * 0x40 | SpecialFogClut;
        }
      }
      rootNode = rootNode->next;
    }
  }
  DrawSync(0);
  return block;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_TransferBufferToVram(void *dataPtr /*$s3*/, long dataSize /*$s2*/, short status /*$s7*/, void *data1 /*$s0*/, void *data2 /*stack 16*/)
// line 1315, offset 0x80073dc8
/* begin block 1 */
// Start line: 1316
// Start offset: 0x80073DC8
// Variables:
// 		struct VramBuffer *vramControl; // $s1
// 		struct RECT rect; // stack offset -48
// 		long *nextOTag; // $s5
// 		long *drawTimerReturn; // $fp

/* begin block 1.1 */
// Start line: 1345
// Start offset: 0x80073E5C
/* end block 1.1 */
// End offset: 0x80073F10
// End Line: 1374

/* begin block 1.2 */
// Start line: 1379
// Start offset: 0x80073F18
/* end block 1.2 */
// End offset: 0x80073FBC
// End Line: 1399

/* begin block 1.3 */
// Start line: 1435
// Start offset: 0x80073FD8
/* end block 1.3 */
// End offset: 0x80073FEC
// End Line: 1438
/* end block 1 */
// End offset: 0x80074010
// End Line: 1450

/* begin block 2 */
// Start line: 2630
/* end block 2 */
// End Line: 2631

void VRAM_TransferBufferToVram(void *dataPtr, long dataSize, short status, void *data1, void *data2)

{
  short sVar1;
  long *plVar2;
  uint uVar3;
  int iVar4;
  short sVar5;
  size_t __n;
  int iVar6;
  short local_30;
  short local_2e;
  undefined2 local_2c;
  short local_2a;

  uVar3 = BreakDraw();
  DrawSync(0);
  plVar2 = gameTrackerX.drawTimerReturn;
  gameTrackerX.drawTimerReturn = (long *)0x0;
  if (data1 != (void *)0x0)
  {
    if ((*(uint *)data1 & 1) == 0)
    {
      *(uint *)data1 = *(uint *)data1 | 1;
      dataPtr = (void *)((int)dataPtr + 0x24);
      dataSize = dataSize - 0x24;
    }
    iVar4 = (int)*(short *)((int)data1 + 0xe);
    if (iVar4 != 0)
    {
      iVar6 = (int)*(short *)((int)data1 + 8) * 2 - (uint) * (ushort *)((int)data1 + 0xe);
      __n = iVar6 * 0x10000 >> 0x10;
      if (dataSize < (int)__n)
      {
        memcpy((void *)(*(int *)((int)data1 + 0x10) + iVar4), dataPtr, dataSize);
        sVar1 = (short)dataSize;
        dataSize = 0;
        *(short *)((int)data1 + 0xe) = *(short *)((int)data1 + 0xe) + sVar1;
      }
      else
      {
        memcpy((void *)(*(int *)((int)data1 + 0x10) + iVar4), dataPtr, __n);
        dataPtr = (void *)((int)dataPtr + __n);
        dataSize = dataSize - __n;
        local_30 = *(short *)((int)data1 + 4);
        *(short *)((int)data1 + 0xe) = *(short *)((int)data1 + 0xe) + (short)iVar6;
        local_2e = *(short *)((int)data1 + 6) + *(short *)((int)data1 + 0xc);
        local_2c = *(undefined2 *)((int)data1 + 8);
        local_2a = 1;
        *(short *)((int)data1 + 0xc) = *(short *)((int)data1 + 0xc) + 1;
        LoadImage(&local_30, *(undefined4 *)((int)data1 + 0x10));
        *(undefined2 *)((int)data1 + 0xe) = 0;
      }
    }
    if (0 < dataSize)
    {
      sVar1 = *(short *)((int)data1 + 8);
      iVar4 = dataSize / ((int)sVar1 << 1);
      local_30 = *(short *)((int)data1 + 4);
      local_2e = *(short *)((int)data1 + 6) + *(short *)((int)data1 + 0xc);
      local_2c = *(undefined2 *)((int)data1 + 8);
      sVar5 = (short)iVar4;
      local_2a = sVar5;
      LoadImage(&local_30, dataPtr);
      *(short *)((int)data1 + 0xc) = *(short *)((int)data1 + 0xc) + sVar5;
      iVar4 = (int)(short)(sVar1 * (short)((iVar4 << 0x10) >> 0xf));
      __n = dataSize - iVar4;
      if (0 < (int)__n)
      {
        memcpy((void *)(*(int *)((int)data1 + 0x10) + (int)*(short *)((int)data1 + 0xe)),
               (void *)((int)dataPtr + iVar4), __n);
        *(short *)((int)data1 + 0xe) = *(short *)((int)data1 + 0xe) + (short)__n;
      }
    }
    if (((status == 1) && (data2 != (void *)0x0)) && (*(short *)((int)data2 + 0x14) == 4))
    {
      *(undefined2 *)((int)data2 + 0x14) = 2;
    }
  }
  DrawSync(0);
  gameTrackerX.drawTimerReturn = plVar2;
  if ((uVar3 != 0) && (gameTrackerX.drawTimerReturn = plVar2, uVar3 != 0xffffffff))
  {
    gameTrackerX.drawTimerReturn = plVar2;
    DrawOTag(uVar3);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_LoadReturn(void *dataPtr /*$a0*/, void *data1 /*$a1*/, void *data2 /*$a2*/)
// line 1455, offset 0x80074040
/* begin block 1 */
// Start line: 1456
// Start offset: 0x80074040
/* end block 1 */
// End offset: 0x80074040
// End Line: 1456

/* begin block 2 */
// Start line: 3339
/* end block 2 */
// End Line: 3340

void VRAM_LoadReturn(void *dataPtr, void *data1, void *data2)

{
  MEMPACK_Free((char *)data1);
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ VRAM_GetObjectVramSpace(struct VramSize *vramSize /*$v1*/, struct _ObjectTracker *objectTracker /*$s4*/)
// line 1461, offset 0x80074060
/* begin block 1 */
// Start line: 1462
// Start offset: 0x80074060
// Variables:
// 		struct RECT rect; // stack offset -32
// 		long result; // $s3
// 		struct _BlockVramEntry *lastVramBlockUsed; // $v0
/* end block 1 */
// End offset: 0x80074134
// End Line: 1505

/* begin block 2 */
// Start line: 3351
/* end block 2 */
// End Line: 3352

long VRAM_GetObjectVramSpace(VramSize *vramSize, _ObjectTracker *objectTracker)

{
  _BlockVramEntry *p_Var1;
  uint uVar2;
  short local_20;
  short local_1e;
  short local_1c;
  short local_1a;

  uVar2 = 1;
  local_20 = vramSize->x + 0x200;
  local_1e = vramSize->y;
  local_1c = vramSize->w;
  local_1a = vramSize->h;
  p_Var1 = VRAM_CheckVramSlot(&local_20, &local_1e, local_1c, local_1a, 2, 0x100);
  if (p_Var1 == (_BlockVramEntry *)0x0)
  {
    p_Var1 = VRAM_RearrangeVramsLayer(1, &local_20, &local_1e, local_1c, (int)local_1a, 2, 0x100);
    if (p_Var1 == (_BlockVramEntry *)0x0)
    {
      p_Var1 = VRAM_CheckVramSlot(&local_20, &local_1e, local_1c, local_1a, 2, 0x100);
      uVar2 = (uint)(p_Var1 != (_BlockVramEntry *)0x0);
    }
  }
  *(_BlockVramEntry **)&objectTracker->vramBlock = p_Var1;
  if (p_Var1 != (_BlockVramEntry *)0x0)
  {
    *(_ObjectTracker **)&p_Var1->udata = objectTracker;
  }
  return uVar2;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_InitMorphPalettes()
// line 1511, offset 0x80074158
/* begin block 1 */
// Start line: 3502
/* end block 1 */
// End Line: 3503

/* begin block 2 */
// Start line: 3509
/* end block 2 */
// End Line: 3510

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_InitMorphPalettes(void)

{
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_UpdateMorphPalettes()
// line 1545, offset 0x80074160
/* begin block 1 */
// Start line: 3570
/* end block 1 */
// End Line: 3571

/* begin block 2 */
// Start line: 3671
/* end block 2 */
// End Line: 3672

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_UpdateMorphPalettes(void)

{
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MORPH_ChangeAreaPalettes(long time /*$a0*/)
// line 1703, offset 0x80074168
/* begin block 1 */
// Start line: 3886
/* end block 1 */
// End Line: 3887

/* begin block 2 */
// Start line: 3912
/* end block 2 */
// End Line: 3913

void MORPH_ChangeAreaPalettes(long time)

{
  return;
}
