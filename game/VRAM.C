#include "THISDUST.H"
#include "VRAM.H"

void VRAM_PrintVramBlock(_BlockVramEntry *vblock)

{
  return;
}

void VRAM_PrintInfo(void)

{
  _BlockVramEntry *p_Var1;

  p_Var1 = usedVramBlocks;
  if (usedVramBlocks != (_BlockVramEntry *)0x0)
  {
    do
    {
      p_Var1 = p_Var1->next;
    } while (p_Var1 != (_BlockVramEntry *)0x0);
  }
  p_Var1 = openVramBlocks;
  if (openVramBlocks != (_BlockVramEntry *)0x0)
  {
    do
    {
      p_Var1 = p_Var1->next;
    } while (p_Var1 != (_BlockVramEntry *)0x0);
  }
  return;
}

void VRAM_InitVramBlockCache(void)

{
  _BlockVramEntry *p_Var1;
  int iVar2;

  iVar2 = 0x4a;
  p_Var1 = &_BlockVramEntry_800d4d1c;
  openVramBlocks = (_BlockVramEntry *)0x0;
  usedVramBlocks = (_BlockVramEntry *)0x0;
  numOfBlocksUsed = 0;
  do
  {
    p_Var1->flags = '\0';
    iVar2 = iVar2 + -1;
    p_Var1 = p_Var1 + -1;
  } while (-1 < iVar2);
  VRAM_InsertFreeBlock(0x200, 0x100, 0x200, 0x100, 1);
  VM_UpdateMorph();
  return;
}

void VRAM_EnableTerrainArea(void)

{
  VRAM_InsertFreeBlock(0x200, 0, 0x200, 0x100, 0);
  return;
}

void VRAM_DisableTerrainArea(void)

{
  VRAM_DeleteFreeVram(0x200, 0, 0x200, 0x100);
  return;
}

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
          iVar2 = (u_int)(u_short)curBlock->y << 0x10;
          iVar4 = iVar2 >> 0x10;
          iVar1 = (u_int)(u_short)block->y << 0x10;
          iVar3 = iVar1 >> 0x10;
          if (iVar2 >> 0x18 == iVar1 >> 0x18)
          {
            if (iVar4 + curBlock->h == iVar3)
            {
              curBlock->h = curBlock->h + block->h;
              goto LAB_8007291c;
            }
            if (iVar3 + block->h == iVar4)
            {
              block->h = block->h + curBlock->h;
              goto LAB_80072980;
            }
          }
        }
        if ((curBlock->y == block->y) && (curBlock->h == block->h))
        {
          if (((int)curBlock->x + (int)curBlock->w == (int)block->x) &&
              (((curBlock->x & 0x3fU) == 0 || ((int)curBlock->w + (int)block->w < 0x41))))
          {
            curBlock->w = curBlock->w + block->w;
          LAB_8007291c:
            VRAM_DeleteFreeBlock(block);
            block->flags = '\0';
            return 1;
          }
          if (((int)block->x + (int)block->w == (int)curBlock->x) &&
              (((block->x & 0x3fU) == 0 || ((int)curBlock->w + (int)block->w < 0x41))))
          {
            block->w = block->w + curBlock->w;
          LAB_80072980:
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

void MEMPACK_GarbageCollectFree(void)

{
  int iVar1;

  do
  {
    iVar1 = VRAM_ConcatanateMemory(openVramBlocks);
  } while (iVar1 == 1);
  return;
}

int VRAM_InsertFreeVram(_BlockVramEntry *block)

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
    MEMPACK_GarbageCollectFree();
    iVar1 = 1;
  }
  return iVar1;
}

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

void VRAM_DeleteUsedBlock(_BlockVramEntry *block)

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
  } while (iVar2 < 0x4b);
  return (_BlockVramEntry *)0x0;
}

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
  local_18[2] = openVramBlocks;
  local_18[3] = usedVramBlocks;
  local_18[0] = openVramBlocks;
  local_18[1] = usedVramBlocks;
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
        if (((((int)x <= (int)p_Var1->x) && ((int)p_Var1->x + (int)p_Var1->w <= (int)x + (int)w)) &&
             ((int)y <= (int)p_Var1->y)) &&
            ((int)p_Var1->y + (int)p_Var1->h <= (int)y + (int)h))
        {
          p_Var1->flags = '\0';
          p_Var4 = p_Var3;
          if (p_Var3 == (_BlockVramEntry *)0x0)
          {
            if (iVar5 == 0)
            {
              iVar6 = iVar6 + 1;
              openVramBlocks = p_Var2;
            }
            else
            {
              iVar6 = iVar6 + 1;
              usedVramBlocks = p_Var2;
            }
          }
          else
          {
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

int VRAM_InsertFreeBlock(short x, short y, short w, short h, int flags)

{
  short sVar1;
  _BlockVramEntry *block;
  u_char uVar2;
  long lVar3;

  uVar2 = (u_char)flags;
  if (((x & 0x3fU) == 0) || ((int)w <= (int)(0x40 - ((u_int)(u_short)x & 0x3f))))
  {
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
  else
  {
    block = VRAM_GetOpenBlock();
    sVar1 = (short)((u_int)(u_short)x & 0x3f);
    block->w = 0x40 - sVar1;
    block->next = (_BlockVramEntry *)0x0;
    block->flags = uVar2;
    block->time = 0;
    block->ID = 0;
    block->x = x;
    block->y = y;
    block->h = h;
    block->area = (int)block->w * (int)h;
    VRAM_InsertFreeVram(block);
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
  VRAM_InsertFreeVram(block);
  return 1;
}

_BlockVramEntry *VRAM_CheckVramSlot(short *x, short *y, short w, short h, int type, int startY)

{
  u_short uVar1;
  bool bVar2;
  u_short x_00;
  u_short y_00;
  int iVar3;
  u_int uVar4;
  int iVar5;
  u_short h_00;
  u_int uVar6;
  int iVar7;
  int iVar8;
  u_int uVar9;
  _BlockVramEntry *block;
  short w_00;
  _BlockVramEntry *p_Var10;
  u_int uVar11;
  u_char local_30;

  uVar6 = (u_int)(u_short)h;
  uVar4 = (u_int)(u_short)w;
  bVar2 = false;
  p_Var10 = (_BlockVramEntry *)0x0;
  _w_00 = 0;
  w_00 = 0;
  block = openVramBlocks;
  if (openVramBlocks != (_BlockVramEntry *)0x0)
  {
    iVar3 = (int)w;
    iVar8 = (int)(short)startY;
    do
    {
      w_00 = (short)_w_00;
      iVar7 = (int)block->w;
      if (((iVar3 <= iVar7) && (h <= block->h)) &&
          ((iVar8 == -1 || ((iVar8 <= (int)block->y && ((int)block->y < iVar8 + 0x100))))))
      {
        x_00 = block->x;
        iVar5 = 0x40 - ((u_int)x_00 & 0x3f);
        if ((x_00 & 0x3f) == 0)
        {
        LAB_80073150:
          bVar2 = false;
          break;
        }
        if (iVar5 < iVar3)
        {
          if ((iVar3 <= (int)(0x40 - ((short)x_00 + iVar5 & 0x3fU))) && (iVar3 <= iVar7 - iVar5))
          {
            bVar2 = true;
            _w_00 = iVar5;
            p_Var10 = block;
          }
        }
        else
        {
          if ((x_00 & 0xf) == 0)
            goto LAB_80073150;
          iVar5 = 0x10 - ((u_int)x_00 & 0xf);
          if ((iVar3 <= (int)(0x40 - ((short)x_00 + iVar5 & 0x3fU))) && (iVar3 <= iVar7 - iVar5))
          {
            VRAM_InsertFreeBlock(x_00, block->y, (short)((u_int)(iVar5 * 0x10000) >> 0x10), block->h,
                                 (u_int)block->flags);
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
    if (block != (_BlockVramEntry *)0x0)
      goto LAB_80073098;
  }
  if ((p_Var10 != (_BlockVramEntry *)0x0) && (bVar2))
  {
    VRAM_InsertFreeBlock(p_Var10->x, p_Var10->y, w_00, p_Var10->h, (u_int)p_Var10->flags);
    bVar2 = false;
    p_Var10->x = p_Var10->x + w_00;
    p_Var10->w = p_Var10->w - w_00;
    block = p_Var10;
  }
  if (block == (_BlockVramEntry *)0x0)
  {
    return (_BlockVramEntry *)0x0;
  }
LAB_80073098:
  if (!bVar2)
  {
    x_00 = block->x;
    y_00 = block->y;
    uVar1 = block->w;
    uVar9 = (u_int)uVar1;
    h_00 = block->h;
    uVar11 = (u_int)h_00;
    VRAM_DeleteFreeBlock(block);
    block->next = (_BlockVramEntry *)0x0;
    block->flags = '\x01';
    local_30 = (u_char)type;
    block->w = w;
    block->h = h;
    block->type = local_30;
    VRAM_DeleteUsedBlock(block);
    *x = block->x;
    *y = block->y;
    _w_00 = (int)(short)uVar1;
    iVar3 = (int)w;
    if (_w_00 == iVar3)
    {
      if (uVar11 << 0x10 == uVar6 << 0x10)
      {
        return block;
      }
      y_00 = (u_short)((y_00 + uVar6) * 0x10000 >> 0x10);
      h_00 = (u_short)((uVar11 - uVar6) * 0x10000 >> 0x10);
    }
    else
    {
      iVar7 = (int)(short)h_00;
      iVar8 = (int)h;
      if (iVar7 == iVar8)
      {
        x_00 = (u_short)((x_00 + uVar4) * 0x10000 >> 0x10);
        w = (short)((uVar9 - uVar4) * 0x10000 >> 0x10);
      }
      else
      {
        iVar5 = (_w_00 - iVar3) * iVar8 - _w_00 * (iVar7 - iVar8);
        if (iVar5 < 0)
        {
          iVar5 = -iVar5;
        }
        _w_00 = (_w_00 - iVar3) * iVar7 - iVar3 * (iVar7 - iVar8);
        if (_w_00 < 0)
        {
          _w_00 = -_w_00;
        }
        iVar3 = x_00 + uVar4;
        if (_w_00 < iVar5)
        {
          VRAM_InsertFreeBlock((short)((u_int)(iVar3 * 0x10000) >> 0x10), y_00,
                               (short)((uVar9 - uVar4) * 0x10000 >> 0x10), h, 1);
          w = uVar1;
        }
        else
        {
          VRAM_InsertFreeBlock((short)((u_int)(iVar3 * 0x10000) >> 0x10), y_00,
                               (short)((uVar9 - uVar4) * 0x10000 >> 0x10), h_00, 1);
        }
        y_00 = (u_short)((y_00 + uVar6) * 0x10000 >> 0x10);
        h_00 = (u_short)((uVar11 - uVar6) * 0x10000 >> 0x10);
      }
    }
    VRAM_InsertFreeBlock(x_00, y_00, w, h_00, 1);
  }
  return block;
}

void VRAM_ClearVramBlock(_BlockVramEntry *block)

{
  if (block != (_BlockVramEntry *)0x0)
  {
    VRAM_DeleteUsedBlock(block);
    VRAM_InsertFreeVram(block);
  }
  return;
}

void AdjustVramCoordsObject(int oldx, int oldy, int newx, int newy, Object *object)

{
  u_short uVar1;
  u_short uVar2;
  char cVar3;
  char cVar4;
  u_int uVar5;
  TextureMT3 *pTVar6;
  u_short *puVar7;
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
          uVar5 = newy + (((u_int)uVar1 & 0x10) * 0x10 - (oldy & 0xffffff00U));
          uVar2 = *puVar7;
          *(char *)((int)puVar7 + -1) = *(char *)((int)puVar7 + -1) + cVar3;
          *(char *)((int)puVar7 + 7) = *(char *)((int)puVar7 + 7) + cVar3;
          *(char *)((int)puVar7 + 3) = *(char *)((int)puVar7 + 3) + cVar3;
          cVar4 = (char)(((int)(((newx & 0x3fU) - (oldx & 0x3fU)) * 0x10000) >> 0x10) << (2 - ((u_int)(uVar1 >> 7) & 3) & 0x1f));
          pTVar6->u0 = pTVar6->u0 + cVar4;
          pTVar6 = pTVar6 + 1;
          puVar7[2] = uVar1 & 0x1e0 |
                      (u_short)((int)(uVar5 & 0x100) >> 4) |
                      (u_short)((int)((newx & 0xffffffc0U) +
                                          (((u_int)uVar1 & 0xf) * 0x40 - (oldx & 0xffffffc0U)) &
                                      0x3ff) >>
                                6) |
                      (u_short)((uVar5 & 0x200) << 2);
          *puVar7 = ((short)newy + ((uVar2 >> 6) - (short)oldy)) * 0x40 |
                    (u_short)((int)((newx & 0xfffffff0U) +
                                    (((u_int)uVar2 & 0x3f) * 0x10 - (oldx & 0xfffffff0U))) >>
                              4) &
                        0x3f;
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

_BlockVramEntry *VRAM_InsertUsedBlock(_BlockVramEntry *rootNode, _BlockVramEntry *newBlock)

{
  _BlockVramEntry *p_Var1;
  _BlockVramEntry *p_Var2;
  _BlockVramEntry *p_Var3;

  p_Var2 = rootNode;
  p_Var3 = (_BlockVramEntry *)0x0;
  if (rootNode != (_BlockVramEntry *)0x0)
  {
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

void VRAM_RearrangeVramsLayer(long whichLayer)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  _BlockVramEntry *newBlock;
  _BlockVramEntry **pp_Var4;
  _BlockVramEntry *block;
  u_char uVar5;
  long lVar6;
  u_char uVar7;
  _BlockVramEntry *rootNode;
  int iVar8;
  short sVar9;
  _BlockVramEntry *local_638[48];
  _BlockVramEntry local_578[48];
  short local_38;
  short local_36;
  short local_34;
  short local_32;
  u_short local_30;
  u_short local_2e[3];

  iVar8 = 0;
  if (usedVramBlocks != (_BlockVramEntry *)0x0)
  {
    newBlock = local_578;
    pp_Var4 = local_638;
    rootNode = usedVramBlocks;
    do
    {
      if (whichLayer == 0)
      {
        if (rootNode->y < 0x100)
        {
          *pp_Var4 = rootNode;
        LAB_800735cc:
          uVar5 = *(u_char *)&rootNode->type;
          lVar6 = rootNode->ID;
          uVar7 = *(u_char *)&rootNode->x;
          newBlock->next = rootNode->next;
          *(u_char *)&newBlock->type = uVar5;
          newBlock->ID = lVar6;
          *(u_char *)&newBlock->x = uVar7;
          lVar6 = rootNode->area;
          uVar5 = rootNode->udata;
          *(u_char *)&newBlock->w = *(u_char *)&rootNode->w;
          newBlock->area = lVar6;
          newBlock->udata = uVar5;
          newBlock = newBlock + 1;
          pp_Var4 = pp_Var4 + 1;
          iVar8 = iVar8 + 1;
        }
      }
      else
      {
        if (0xff < rootNode->y)
        {
          *pp_Var4 = rootNode;
          goto LAB_800735cc;
        }
      }
      rootNode = rootNode->next;
    } while (rootNode != (_BlockVramEntry *)0x0);
  }
  if (0 < iVar8)
  {
    sVar9 = 0x100;
    if (whichLayer == 0)
    {
      sVar9 = 0;
      local_36 = 0;
    }
    else
    {
      local_36 = 0x100;
    }
    local_34 = 0x200;
    local_38 = 0x200;
    local_32 = 0x100;
    do
    {
      do
      {
        iVar3 = CheckVolatile(gameTrackerX.drawTimerReturn);
      } while (iVar3 != 0);
      iVar3 = CheckVolatile(gameTrackerX.reqDisp);
    } while (iVar3 != 0);
    iVar3 = 0;
    rootNode = (_BlockVramEntry *)0x0;
    sVar2 = (short)(gameTrackerX.gameData.asmData.dispPage ^ 1U) * 0x100;
    MoveImage((u_char *)&local_38, 0,
              (int)((gameTrackerX.gameData.asmData.dispPage ^ 1U) << 0x18) >> 0x10);
    DrawSync(0);
    pp_Var4 = local_638;
    if (0 < iVar8)
    {
      newBlock = local_578;
      do
      {
        block = *pp_Var4;
        pp_Var4 = pp_Var4 + 1;
        VRAM_ClearVramBlock(block);
        iVar3 = iVar3 + 1;
        newBlock->next = (_BlockVramEntry *)0x0;
        newBlock->area = (int)newBlock->w * (int)newBlock->h;
        rootNode = VRAM_InsertUsedBlock(rootNode, newBlock);
        newBlock = newBlock + 1;
      } while (iVar3 < iVar8);
    }
    while (rootNode != (_BlockVramEntry *)0x0)
    {
      local_34 = rootNode->w;
      local_32 = rootNode->h;
      local_38 = rootNode->x + -0x200;
      local_36 = sVar2;
      if (whichLayer != 0)
      {
        local_36 = sVar2 + -0x100;
      }
      local_36 = rootNode->y + local_36;
      local_30 = rootNode->x;
      local_2e[0] = rootNode->y;
      newBlock = VRAM_CheckVramSlot((short *)&local_30, (short *)local_2e, local_34, local_32,
                                    (u_int)rootNode->type, (int)sVar9);
      if (newBlock == (_BlockVramEntry *)0x0)
      {
        VRAM_PrintInfo();
        VRAM_PrintVramBlock(rootNode);
      }
      MoveImage((u_char *)&local_38, (int)(short)local_30, (int)(short)local_2e[0]);
      DrawSync(0);
      bVar1 = rootNode->type;
      if (bVar1 == 2)
      {
        AdjustVramCoordsObject((int)rootNode->x, (int)rootNode->y, (int)(short)local_30, (int)(short)local_2e[0],
                               *(Object **)(rootNode->udata + 0x10));
        *(_BlockVramEntry **)(rootNode->udata + 0x18) = newBlock;
        newBlock->udata = rootNode->udata;
      }
      else
      {
        if ((2 < bVar1) && (bVar1 == 3))
        {
          fontTracker.font_tpage =
              (short)(local_2e[0] & 0x100) >> 4 | (u_short)(((u_int)local_30 & 0x3ff) >> 6) |
              (u_short)(((u_int)local_2e[0] & 0x200) << 2);
          fontTracker.font_vramU = (short)(((u_int)local_30 & 0x3f) << 2);
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

void VRAM_TransferBufferToVram(void *dataPtr, long dataSize, short status, void *data1, void *data2)

{
  short sVar1;
  long *plVar2;
  u_char *puVar3;
  int iVar4;
  short sVar5;
  size_t __n;
  int iVar6;
  undefined2 local_28;
  short local_26;
  undefined2 local_24;
  short local_22;

  puVar3 = (u_char *)BreakDraw();
  DrawSync(0);
  plVar2 = gameTrackerX.drawTimerReturn;
  gameTrackerX.drawTimerReturn = (long *)0x0;
  if (data1 != (void *)0x0)
  {
    if ((*(u_int *)data1 & 1) == 0)
    {
      *(u_int *)data1 = *(u_int *)data1 | 1;
      dataPtr = (void *)((int)dataPtr + 0x24);
      dataSize = dataSize - 0x24;
    }
    iVar4 = (int)*(short *)((int)data1 + 0xe);
    if (iVar4 != 0)
    {
      iVar6 = (int)*(short *)((int)data1 + 8) * 2 - (u_int) * (u_short *)((int)data1 + 0xe);
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
        local_28 = *(undefined2 *)((int)data1 + 4);
        *(short *)((int)data1 + 0xe) = *(short *)((int)data1 + 0xe) + (short)iVar6;
        local_26 = *(short *)((int)data1 + 6) + *(short *)((int)data1 + 0xc);
        local_24 = *(undefined2 *)((int)data1 + 8);
        local_22 = 1;
        *(short *)((int)data1 + 0xc) = *(short *)((int)data1 + 0xc) + 1;
        LoadImage((u_char *)&local_28, *(u_char *)((int)data1 + 0x10));
        *(undefined2 *)((int)data1 + 0xe) = 0;
      }
    }
    if (0 < dataSize)
    {
      sVar1 = *(short *)((int)data1 + 8);
      ((int)sVar1 << 1);
      local_28 = *(undefined2 *)((int)data1 + 4);
      local_26 = *(short *)((int)data1 + 6) + *(short *)((int)data1 + 0xc);
      local_24 = *(undefined2 *)((int)data1 + 8);
      sVar5 = (short)iVar4;
      local_22 = sVar5;
      LoadImage((u_char *)&local_28, dataPtr);
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
  }
  DrawSync(0);
  gameTrackerX.drawTimerReturn = plVar2;
  if ((puVar3 != (u_char *)0x0) && (puVar3 != (u_char *)0xffffffff))
  {
    DrawOTag(puVar3);
  }
  return;
}

void VRAM_LoadReturn(void *dataPtr, void *data1, void *data2)

{
  MEMPACK_Init((char *)data1);
  return;
}

long VRAM_GetObjectVramSpace(VramSize *vramSize, _ObjectTracker *objectTracker)

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
  p_Var1 = VRAM_CheckVramSlot(&local_28, &local_26, local_24, local_22, 2, 0x100);
  if (p_Var1 == (_BlockVramEntry *)0x0)
  {
    VRAM_RearrangeVramsLayer(1);
    p_Var1 = VRAM_CheckVramSlot(&local_28, &local_26, local_24, local_22, 2, 0x100);
    if (p_Var1 == (_BlockVramEntry *)0x0)
    {
      lVar2 = 0;
      VRAM_PrintInfo();
    }
  }
  *(_BlockVramEntry **)&objectTracker->vramBlock = p_Var1;
  if (p_Var1 != (_BlockVramEntry *)0x0)
  {
    *(_ObjectTracker **)&p_Var1->udata = objectTracker;
  }
  return lVar2;
}

void VM_UpdateMorph(void)

{
  return;
}

void VRAM_InitMorphPalettes(void)

{
  return;
}

void MORPH_ChangeAreaPalettes(long time)

{
  return;
}
