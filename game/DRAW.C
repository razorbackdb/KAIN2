#include "THISDUST.H"
#include "DRAW.H"

void fDRAW_SPLIT_INTPL_XYZ(_SVector *newVertex, _SVector *pvb, _SVector *pvc)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;

                                 ((int)pvb->z - (int)pvc->z));
                                 sVar1 = pvc->y;
                                 sVar2 = pvb->y;
                                 sVar3 = pvb->z;
                                 sVar4 = pvc->z;
                                 sVar5 = pvb->y;
                                 newVertex->z = 0;

                                ((int)sVar3 - (int)sVar4));
                                return;
}

void DRAW_InitShadow(void)

{
  int iVar1;
  undefined *puVar2;
  SVECTOR *pSVar3;
  undefined *puVar4;
  int iVar5;

  puVar4 = (undefined *)0x0;
  iVar5 = 0;
  pSVar3 = &shadow_vertices;
  do
  {
    puVar2 = puVar4;
    if ((int)puVar4 < 0)
    {
      puVar2 = puVar4 + 0xfff;
    }
    iVar1 = rcos((int)puVar2 >> 0xc);
    if (iVar1 < 0)
    {
      iVar1 = iVar1 + 0x1f;
    }
    pSVar3->vx = (short)(iVar1 >> 5);
    iVar1 = rsin((int)puVar2 >> 0xc);
    if (iVar1 < 0)
    {
      iVar1 = iVar1 + 0x1f;
    }
    puVar4 = &UNK_00199999 + (int)puVar4;
    pSVar3->vy = (short)(iVar1 >> 5);
    pSVar3->vz = 0;
    iVar5 = iVar5 + 1;
    pSVar3 = pSVar3 + 1;
  } while (iVar5 < 10);
  SVECTOR_800d14e8.vx = shadow_vertices.vx;
  SVECTOR_800d14e8.vy = shadow_vertices.vy;
  SVECTOR_800d14e8.vz = shadow_vertices.vz;
  return;
}

u_long *DRAW_DrawShadow(_PrimPool *primPool, _Model *model, u_long **ot, long fadeValue)

{
  u_int uVar1;
  int iVar2;
  long lVar3;
  u_long uVar4;
  u_char in_zero;
  u_char in_at;
  u_int uVar5;
  _PrimPool *p_Var6;
  u_long *puVar7;
  u_long *puVar8;
  int iVar9;
  SVECTOR *pSVar10;
  u_int local_14;
  long local_10;

  puVar7 = primPool->nextPrim;
  local_14 = local_14 & 0xffff0000;
  setCopReg(2, in_zero, 0);
  setCopReg(2, in_at, local_14);
  copFunction(2, 0x180001);
  iVar9 = getCopReg(2, 8);
  local_10 = iVar9;
  if ((fadeValue <= iVar9) || (local_10 = fadeValue, fadeValue < 0x1001))
  {
    iVar9 = local_10;
  }
  local_10 = iVar9;
  setCopReg(2, ot, 0x606060);
  setCopReg(2, 0x4000, local_10);
  copFunction(2, 0x780010);
  uVar1 = getCopReg(2, 0x16);
  iVar9 = 0;
  pSVar10 = &shadow_vertices;
  puVar8 = puVar7 + 1;
  uVar5 = uVar1 | 0x32000000;
  p_Var6 = primPool;
  do
  {
    setCopReg(2, uVar5, *(u_char *)pSVar10);
    setCopReg(2, iVar9 * 8, *(u_char *)&pSVar10->vz);
    setCopReg(2, p_Var6, *(u_char *)(&SVECTOR_800d14a0 + iVar9));
    setCopReg(2, puVar7, *(u_char *)&(&SVECTOR_800d14a0)[iVar9].vz);
    copFunction(2, 0x280030);
    if (primPool->lastPrim + -0xc < puVar7)
    {
      return puVar7;
    }
    copFunction(2, 0x1400006);
    iVar2 = getCopReg(2, 0x18);
    if (iVar2 < 0)
    {
      copFunction(2, 0x158002d);
      iVar2 = getCopReg(2, 7);
      p_Var6 = (_PrimPool *)(puVar7 + 3);
      if (iVar2 - 0x40U < 0xbc0)
      {
        lVar3 = getCopReg(2, 0xc);
        p_Var6->numPrims = lVar3;
        uVar4 = getCopReg(2, 0xd);
        puVar7[5] = uVar4;
        uVar4 = getCopReg(2, 0xe);
        puVar7[7] = uVar4;
        puVar8[3] = 0;
        puVar8[5] = 0;
        puVar8[1] = uVar1 | 0x32000000;
        *puVar8 = 0xe1000640;
        puVar8 = puVar8 + 8;
        p_Var6 = (_PrimPool *)(ot + iVar2);
        *puVar7 = p_Var6->numPrims & 0xffffffU | 0x7000000;
        p_Var6->numPrims = (u_int)puVar7 & 0xffffff;
        puVar7 = puVar7 + 8;
        primPool->numPrims = primPool->numPrims + 1;
      }
    }
    iVar9 = iVar9 + 1;
    uVar5 = (u_int)(iVar9 < 10);
    pSVar10 = pSVar10 + 1;
  } while (iVar9 < 10);
  return puVar7;
}

void DRAW_FlatQuad(CVECTOR *color, short x0, short y0, short x1, int y1, int x2, int y2, int x3, int y3,
                   _PrimPool *primPool, u_long **ot)

{
  CVECTOR CVar1;
  u_int *puVar2;

  puVar2 = primPool->nextPrim;
  if (puVar2 < primPool->lastPrim + -0xc)
  {
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
    *puVar2 = (u_int)*ot & 0xffffff | 0x5000000;
    *ot = (u_long *)((u_int)puVar2 & 0xffffff);
    primPool->nextPrim = primPool->nextPrim + 6;
    primPool->numPrims = primPool->numPrims + 1;
  }
  return;
}

void DRAW_TranslucentQuad(short x0, short y0, short x1, short y1, int x2, int y2, int x3, int y3, int r, int g, int b,
                          int abr, _PrimPool *primPool, u_long **ot)

{
  u_int *puVar1;

  puVar1 = primPool->nextPrim;
  if (puVar1 < primPool->lastPrim + -0xc)
  {
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
    *puVar1 = (u_int)*ot & 0xffffff | 0x6000000;
    *ot = (u_long *)((u_int)puVar1 & 0xffffff);
    primPool->nextPrim = primPool->nextPrim + 7;
    primPool->numPrims = primPool->numPrims + 1;
  }
  return;
}

void DRAW_DrawButton(_ButtonTexture *button, short x, short y, u_long **ot)

{
  short sVar1;
  u_short uVar2;
  short sVar3;
  char cVar4;
  _PrimPool *p_Var5;
  short sVar6;
  u_int uVar7;
  short sVar8;
  char cVar9;
  int iVar10;
  char cVar11;
  u_long *puVar12;

  p_Var5 = gameTrackerX.primPool;
  puVar12 = (gameTrackerX.primPool)->nextPrim;
  if (puVar12 <= (gameTrackerX.primPool)->lastPrim + -0xc)
  {
    uVar7 = button->xshift;
    sVar1 = button->textureH;
    iVar10 = (int)button->textureW << (uVar7 & 0x1f);
    uVar2 = button->vramBlock->x;
    cVar11 = *(char *)&button->vramBlock->y;
    SetPolyFT4((int)puVar12);
    sVar8 = x + (short)iVar10;
    cVar4 = (char)(((u_int)uVar2 & 0x3f) << (uVar7 & 0x1f));
    *(byte *)((int)puVar12 + 7) = *(byte *)((int)puVar12 + 7) | 1;
    cVar9 = cVar4 + (char)iVar10 + -1;
    *(short *)((int)puVar12 + 0x16) = button->tpage;
    sVar3 = button->clut;
    sVar6 = y + sVar1;
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
    *puVar12 = (u_int)*ot & 0xffffff | 0x9000000;
    *ot = (u_long *)((u_int)puVar12 & 0xffffff);
    p_Var5->nextPrim = puVar12 + 10;
    p_Var5->numPrims = p_Var5->numPrims + 1;
  }
  return;
}

void DRAW_FreeButton(long *addr, _ButtonTexture *button)

{
  bool bVar1;
  _BlockVramEntry *p_Var2;
  int iVar3;
  long *plVar4;
  short sVar5;
  long *plVar6;
  u_short local_20;
  u_short local_1e;
  short local_1c;
  u_short local_1a;

  plVar4 = addr + 2;
  plVar6 = (long *)0x0;
  sVar5 = 0;
  button->xshift = 0;
  bVar1 = addr[1] == 8;
  if (bVar1)
  {
    button->xshift = 2;
    sVar5 = 0x10;
    plVar6 = addr + 5;
    plVar4 = addr + 0xd;
  }
  button->textureW = *(short *)(plVar4 + 2);
  button->textureH = *(short *)((int)plVar4 + 10);
  local_1c = sVar5;
  if (sVar5 < button->textureW)
  {
    local_1c = button->textureW;
  }
  iVar3 = (u_int)(u_short)button->textureH + (u_int)bVar1;
  local_1a = (u_short)iVar3;
  p_Var2 = VRAM_CheckVramSlot((short *)&local_20, (short *)(&local_20 + 1), local_1c,
                              (short)((u_int)(iVar3 * 0x10000) >> 0x10), 4, 0);
  button->vramBlock = p_Var2;
  button->tpage =
      (u_short)((2 - (u_int) * (u_short *)&button->xshift & 3) << 7) | (short)(local_1e & 0x100) >> 4 |
      (u_short)(((u_int)local_20 & 0x3ff) >> 6) | (u_short)(((u_int)local_1e & 0x200) << 2);
  *(_ButtonTexture **)&button->vramBlock->udata = button;
  local_1c = button->textureW;
  local_1a = button->textureH;
  LoadImage(&local_20, plVar4 + 3);
  if (plVar6 != (long *)0x0)
  {
    local_1a = (u_short)bVar1;
    local_1e = local_1e + button->textureH;
    local_1c = sVar5;
    LoadImage(&local_20, plVar6);
    button->clut = local_1e << 6 | local_20 >> 4 & 0x3f;
  }
  DrawSync(0);
  return;
}

void DRAW_LoadButtonByName(char *name, _ButtonTexture *button)

{
  long *addr;

  addr = LOAD_ReadFileFromCD(name, '\v');
  if (addr != (long *)0x0)
  {
    DRAW_FreeButton(addr, button);
    MEMPACK_Init((char *)addr);
  }
  return;
}

void DRAW_LoadButton(_ButtonTexture *button)

{
  VRAM_ClearVramBlock(button->vramBlock);
  return;
}

void DRAW_RingLine(_PrimPool *primPool, u_long **ot, long color)

{
  int iVar1;
  int iVar2;
  int iVar3;
  u_int uVar4;
  u_long *puVar5;
  u_int *puVar6;
  u_int uVar7;

  puVar6 = primPool->nextPrim;
  if (puVar6 <= primPool->lastPrim + -0xc)
  {
    uVar7 = getCopControlWord(2, 0xf800);
    if ((uVar7 & 0x60000) == 0)
    {
      copFunction(2, 0x1400006);
      getCopReg(2, 0x18);
      iVar1 = getCopReg(2, 0x11);
      iVar2 = getCopReg(2, 0x12);
      iVar3 = getCopReg(2, 0x13);
      if (iVar1 < iVar2)
      {
        iVar2 = iVar1;
      }
      if (iVar2 < iVar3)
      {
        iVar3 = iVar2;
      }
      uVar7 = iVar3 >> 2;
      if (uVar7 < 0xc00)
      {
        if (2 < (int)uVar7)
        {
          uVar7 = uVar7 - 2;
        }
        getCopReg(2, 8);
        puVar6[1] = color | 0x40000000;
        uVar4 = getCopReg(2, 0xc);
        puVar6[2] = uVar4;
        uVar4 = getCopReg(2, 0xd);
        puVar6[3] = uVar4;
        puVar5 = (u_long *)((u_int)puVar6 & 0xffffff);
        *puVar6 = (u_int)ot[uVar7] & 0xffffff | 0x3000000;
        puVar6 = puVar6 + 4;
        ot[uVar7] = puVar5;
      }
    }
    primPool->nextPrim = puVar6;
  }
  return;
}

void DRAW_RingPoint(_PrimPool *primPool, u_long **ot, long color, _SVector *vel, _SVector *acc)

{
  u_int uVar1;
  int iVar2;
  u_char uVar3;
  u_char uVar4;
  u_char uVar5;
  _SVector local_18;

  uVar1 = rand();
  if (0xe < (uVar1 & 0x3f))
  {
    iVar2 = rand();
    vel->x = ((u_short)iVar2 & 0x1f) - 0xf;
    iVar2 = rand();
    vel->y = ((u_short)iVar2 & 0x1f) - 0xf;
    iVar2 = rand();
    vel->z = (u_short)iVar2 & 0xf;
    uVar3 = getCopReg(2, 0x4800);
    uVar4 = getCopReg(2, 0x5000);
    uVar5 = getCopReg(2, 0x5800);
    local_18.x = (short)uVar3;
    local_18.y = (short)uVar4;
    local_18.z = (short)uVar5;
    iVar2 = rand();
    local_18.x = local_18.x + -1 + ((u_short)iVar2 & 3);
    iVar2 = rand();
    local_18.y = local_18.y + -1 + ((u_short)iVar2 & 3);
    iVar2 = rand();
    local_18.z = local_18.z + -1 + ((u_short)iVar2 & 3);
    FX_Die(&local_18, vel, acc, 0, color, 4, 8, -1);
  }
  return;
}

u_long *DRAW_DrawRingPoints(_Model *model, _VertexPool *vertexPool, MATRIX *pcTransform,
                            _PrimPool *primPool, u_long **ot, long color, int ring_type)

{
  u_char in_zero;
  u_char in_at;
  int iVar1;
  u_int uVar2;
  int iVar3;
  _SVector *pvc;
  _SVector *pvb;
  _SVector *pvb_00;
  u_short *puVar4;
  _MFace *p_Var5;
  _MFace *p_Var6;
  undefined8 uStack80;
  _SVector local_48;
  _SVector local_40;
  _SVector local_38;
  _SVector local_30;

  p_Var5 = model->faceList;
  p_Var6 = p_Var5 + model->numFaces;
  if (ring_type == 2)
  {
    local_38.z = 0;
    local_38.y = 0;
    local_38.x = 0;
    local_30.y = 0;
    local_30.x = 0;
    local_30.z = -1;
  }
  SetRotMatrix((u_char *)pcTransform);
  TransMatrix((int)pcTransform);
  if (p_Var5 < p_Var6)
  {
    puVar4 = &(p_Var5->face).v2;
    do
    {
      if ((*(byte *)((int)puVar4 + 3) & 0x10) != 0)
        goto switchD_8002b008_caseD_6;
      pvc = (_SVector *)(vertexPool->vertex + (p_Var5->face).v0);
      pvb_00 = (_SVector *)(vertexPool->vertex + puVar4[-1]);
      pvb = (_SVector *)(vertexPool->vertex + *puVar4);
      uVar2 = (u_int) ~(int)(&pvc->x)[2] >> 0x1f;
      if (-1 < (&pvb_00->x)[2])
      {
        uVar2 = uVar2 | 2;
      }
      if (-1 < (&pvb->x)[2])
      {
        uVar2 = uVar2 | 4;
      }
      switch (uVar2)
      {
      case 1:
        fDRAW_SPLIT_INTPL_XYZ(&local_48, pvc, pvb_00);
        fDRAW_SPLIT_INTPL_XYZ(&local_40, pvc, pvb);
        iVar1 = 1;
        iVar3 = 2;
        break;
      case 2:
        fDRAW_SPLIT_INTPL_XYZ((_SVector *)&uStack80, pvb_00, pvc);
        fDRAW_SPLIT_INTPL_XYZ(&local_40, pvb_00, pvb);
        iVar1 = 2;
        iVar3 = 0;
        pvc = pvb_00;
        break;
      case 3:
        fDRAW_SPLIT_INTPL_XYZ(&local_48, pvb_00, pvb);
        fDRAW_SPLIT_INTPL_XYZ((_SVector *)&uStack80, pvc, pvb);
        iVar1 = 1;
        iVar3 = 0;
        break;
      case 4:
        fDRAW_SPLIT_INTPL_XYZ((_SVector *)&uStack80, pvb, pvc);
        fDRAW_SPLIT_INTPL_XYZ(&local_48, pvb, pvb_00);
        iVar1 = 0;
        goto LAB_8002b10c;
      case 5:
        fDRAW_SPLIT_INTPL_XYZ((_SVector *)&uStack80, pvc, pvb_00);
        fDRAW_SPLIT_INTPL_XYZ(&local_40, pvb, pvb_00);
        iVar1 = 0;
        iVar3 = 2;
        pvc = pvb;
        break;
      case 6:
        fDRAW_SPLIT_INTPL_XYZ(&local_40, pvb, pvc);
        fDRAW_SPLIT_INTPL_XYZ(&local_48, pvb_00, pvc);
        iVar1 = 2;
        pvb = pvb_00;
      LAB_8002b10c:
        iVar3 = 1;
        pvc = pvb;
        break;
      default:
        goto switchD_8002b008_caseD_6;
      }
      if (ring_type == 2)
      {
        setCopReg(2, in_zero, *(u_char *)((_SVector *)&uStack80 + iVar1));
        setCopReg(2, in_at, *(u_char *)((int)&uStack80 + iVar1 * 8 + 4));
        copFunction(2, 0x480012);
        DRAW_RingPoint(primPool, ot, color, &local_38, &local_30);
      }
      else
      {
        pvb_00 = (_SVector *)&uStack80 + iVar1;
        pvb = (_SVector *)&uStack80 + iVar3;
        setCopReg(2, in_zero, *(u_char *)pvb_00);
        setCopReg(2, in_at, *(u_char *)((int)&uStack80 + iVar1 * 8 + 4));
        setCopReg(2, pvb, *(u_char *)pvb);
        setCopReg(2, pvb_00, *(u_char *)((int)&uStack80 + iVar3 * 8 + 4));
        setCopReg(2, iVar3, *(u_char *)pvb_00);
        setCopReg(2, pvc, *(u_char *)((int)&uStack80 + iVar1 * 8 + 4));
        copFunction(2, 0x280030);
        DRAW_RingLine(primPool, ot, color);
      }
    switchD_8002b008_caseD_6:
      puVar4 = puVar4 + 6;
      p_Var5 = p_Var5 + 1;
    } while (p_Var5 < p_Var6);
  }
  return primPool->nextPrim;
}

void DRAW_GlowQuad(_PrimPool *primPool, u_long **ot, long otz, long color, _Vector *v0, _Vector *v1,
                   _Vector *v2, _Vector *v3)

{
  u_int *puVar1;
  u_char uVar2;
  u_char uVar3;
  u_char uVar4;
  u_char local_resc;

  puVar1 = primPool->nextPrim;
  if (puVar1 <= primPool->lastPrim + -0xc)
  {
    primPool->numPrims = primPool->numPrims + 1;
    if ((color & 0x1000000U) == 0)
    {
      puVar1[1] = 0xe1000620;
      local_resc = color;
    }
    else
    {
      local_resc = color & 0xffffff;
      puVar1[1] = 0xe1000640;
    }
    setCopReg(2, 0x4000, 0x1000 - (int)*(short *)&v0->z);
    setCopReg(2, 0x4800, local_resc & 0xff);
    setCopReg(2, 0x5000, (u_int)local_resc._1_1_);
    setCopReg(2, 0x5800, (u_int)local_resc._2_1_);
    copFunction(2, 0x198003d);
    *(undefined2 *)(puVar1 + 3) = *(undefined2 *)&v0->x;
    *(undefined2 *)((int)puVar1 + 0xe) = *(undefined2 *)&v0->y;
    uVar2 = getCopReg(2, 0x4800);
    uVar3 = getCopReg(2, 0x5000);
    uVar4 = getCopReg(2, 0x5800);
    *(char *)(puVar1 + 2) = (char)uVar2;
    *(undefined *)((int)puVar1 + 9) = (char)uVar3;
    *(undefined *)((int)puVar1 + 10) = (char)uVar4;
    setCopReg(2, 0x4000, 0x1000 - (int)*(short *)&v1->z);
    setCopReg(2, 0x4800, local_resc & 0xff);
    setCopReg(2, 0x5000, (u_int)local_resc._1_1_);
    setCopReg(2, 0x5800, (u_int)local_resc._2_1_);
    copFunction(2, 0x198003d);
    *(undefined2 *)(puVar1 + 5) = *(undefined2 *)&v1->x;
    *(undefined2 *)((int)puVar1 + 0x16) = *(undefined2 *)&v1->y;
    uVar2 = getCopReg(2, 0x4800);
    uVar3 = getCopReg(2, 0x5000);
    uVar4 = getCopReg(2, 0x5800);
    *(char *)(puVar1 + 4) = (char)uVar2;
    *(undefined *)((int)puVar1 + 0x11) = (char)uVar3;
    *(undefined *)((int)puVar1 + 0x12) = (char)uVar4;
    setCopReg(2, 0x4000, 0x1000 - (int)*(short *)&v2->z);
    setCopReg(2, 0x4800, local_resc & 0xff);
    setCopReg(2, 0x5000, (u_int)local_resc._1_1_);
    setCopReg(2, 0x5800, (u_int)local_resc._2_1_);
    copFunction(2, 0x198003d);
    *(undefined2 *)(puVar1 + 7) = *(undefined2 *)&v2->x;
    *(undefined2 *)((int)puVar1 + 0x1e) = *(undefined2 *)&v2->y;
    uVar2 = getCopReg(2, 0x4800);
    uVar3 = getCopReg(2, 0x5000);
    uVar4 = getCopReg(2, 0x5800);
    *(char *)(puVar1 + 6) = (char)uVar2;
    *(undefined *)((int)puVar1 + 0x19) = (char)uVar3;
    *(undefined *)((int)puVar1 + 0x1a) = (char)uVar4;
    setCopReg(2, 0x4000, 0x1000 - (int)*(short *)&v3->z);
    setCopReg(2, 0x4800, local_resc & 0xff);
    setCopReg(2, 0x5000, (u_int)local_resc._1_1_);
    setCopReg(2, 0x5800, (u_int)local_resc._2_1_);
    copFunction(2, 0x198003d);
    *(undefined2 *)(puVar1 + 9) = *(undefined2 *)&v3->x;
    *(undefined2 *)((int)puVar1 + 0x26) = *(undefined2 *)&v3->y;
    uVar2 = getCopReg(2, 0x4800);
    uVar3 = getCopReg(2, 0x5000);
    uVar4 = getCopReg(2, 0x5800);
    *(char *)(puVar1 + 8) = (char)uVar2;
    *(undefined *)((int)puVar1 + 0x21) = (char)uVar3;
    *(undefined *)((int)puVar1 + 0x22) = (char)uVar4;
    *puVar1 = (u_int)ot[otz] & 0xffffff | 0x9000000;
    ot[otz] = (u_long *)((u_int)puVar1 & 0xffffff);
    *(undefined *)((int)puVar1 + 0xb) = 0x3a;
    primPool->nextPrim = puVar1 + 10;
  }
  return;
}

void DRAW_CreateAGlowingCircle(_Vector *f1, long z, _PrimPool *primPool, u_long **ot, long otz, long color, long w, long h,
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
  if ((0 < z) && (otz < 0xc00))
  {
    local_d8 = 0;
    local_d0 = 0;
 z);
 iVar1 = rcos(angle);
 iVar2 = rsin(angle);
 iVar1 = iVar1 * local_d8;
 iVar2 = iVar2 * local_d4;
 iVar3 = rsin(angle);
 iVar4 = rcos(angle);
 iVar5 = -iVar3 * local_d8;
 z);
 0xf0;
 local_d4 = iVar5 + iVar4 * local_d4 >> 0xc;
 iVar1 = rcos(angle);
 rsin(angle);
 iVar2 = rsin(angle);
 rcos(angle);
 local_30 = &local_d8;
 0xf0;
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
 DRAW_GlowQuad(primPool, ot, otz, color, &local_84, &local_a8, &local_78, &local_9c);
 DRAW_GlowQuad(primPool, ot, otz, color, &local_84, &local_78, &local_60, &local_54);
 DRAW_GlowQuad(primPool, ot, otz, color, &local_9c, local_34, &local_78, &local_6c);
 DRAW_GlowQuad(primPool, ot, otz, color, &local_54, &local_78, &local_48, &local_6c);
  }
  return;
}

u_long *DRAW_DrawGlowPoint(_Instance *instance, long seg1, long seg2, _PrimPool *primPool, u_long **ot,
                           long color, long height)

{
  long lVar1;
  long lVar2;
  int iVar3;
  u_int uVar4;
  int iVar5;
  int iVar6;
  _Position local_58;
  _Position local_50;
  int local_48;
  int local_44;
  int local_38;
  int local_34;
  _Vector local_28;

  lVar1 = PIPE3D_Segment2ScreenPt(instance, theCamera.core.wcTransform, seg1, &local_58);
  lVar2 = PIPE3D_Segment2ScreenPt(instance, theCamera.core.wcTransform, seg2, &local_50);
  iVar5 = lVar2 + 0x14;
  iVar6 = lVar1 + 0x14;
  if (lVar1 + 0x14 < iVar5)
  {
    iVar6 = iVar5;
  }
  if (0 < iVar6)
  {
    local_48 = (int)local_58.x;
    local_38 = (int)local_50.x;
    local_44 = (int)local_58.y;
    local_34 = (int)local_50.y;
    local_28.x = local_38 - local_48;
    local_28.y = local_34 - local_44;
    iVar3 = MATH3D_veclen2(local_28.x, local_28.y);
    uVar4 = ratan2(local_28.y, -local_28.x);
    local_28.z = 0;
    2;
    2;
    if (iVar6 + 10 < 0xc00)
    {
      DRAW_CreateAGlowingCircle
 2 << 2,primPool,ot,iVar6 + 10,color,iVar3 + height,
                 height,uVar4 & 0xfff);
    }
  }
  return primPool->nextPrim;
}

u_long *DRAW_DrawGlowPoints2(_Instance *instance, long seg1, _PrimPool *primPool, u_long **ot, long color, int width, int height)

{
  u_int uVar1;
  long lVar2;
  int z;
  _Position local_30;
  _Vector local_28;

  uVar1 = gameTrackerX.currentTime & 0x7ff;
  lVar2 = PIPE3D_Segment2ScreenPt(instance, theCamera.core.wcTransform, seg1, &local_30);
  z = (lVar2 + 0x14) * 4;
  if (0 < z)
  {
    local_28.x = (int)local_30.x;
    local_28.y = (int)local_30.y;
    if (lVar2 + 0x1e < 0xc00)
    {
      DRAW_CreateAGlowingCircle(&local_28, z, primPool, ot, lVar2 + 0x1e, color, (int)(short)width, (int)(short)height,
                                uVar1 << 1);
    }
  }
  return primPool->nextPrim;
}

int DRAW_DisplayTFace_zclipped_C(SVECTOR *vertex0, SVECTOR *vertex1, SVECTOR *vertex2, UVTYPE *uv0, UVTYPE *uv1,
                                 UVTYPE *uv2, long color0, long color1, long color2, _PrimPool *primPool, u_long **ot,
                                 int ndiv)

{
  bool bVar1;
  u_char in_zero;
  u_char in_at;
  byte bVar2;
  SVECTOR *pSVar3;
  SVECTOR *pSVar4;
  short sVar5;
  u_int uVar6;
  u_long uVar7;
  u_long *puVar8;
  int iVar9;
  SVECTOR *pSVar10;
  u_char *puVar11;
  u_long uVar12;
  u_int uVar13;
  u_char uVar14;
  u_char *puVar15;
  short *psVar16;
  u_char uVar17;
  u_char uVar18;
  int iVar19;
  u_char uVar20;
  int iVar21;
  u_int uVar22;
  u_char *puVar23;
  int iVar24;
  int iVar25;
  u_char *puVar26;
  POLY_GT3 *texture;
  int iVar27;
  int iVar28;

  puVar15 = &DAT_1f800200;
  setCopReg(2, in_zero, *(u_char *)vertex0);
  setCopReg(2, in_at, *(u_char *)&vertex0->vz);
  copFunction(2, 0x480012);
  DAT_1f800278 = getCopReg(2, 0x19);
  DAT_1f80027c = getCopReg(2, 0x1a);
  DAT_1f800280 = getCopReg(2, 0x1b);
  setCopReg(2, in_zero, *(u_char *)vertex1);
  setCopReg(2, in_at, *(u_char *)&vertex1->vz);
  copFunction(2, 0x480012);
  DAT_1f800284 = getCopReg(2, 0x19);
  _DAT_1f800288 = getCopReg(2, 0x1a);
  DAT_1f80028c = getCopReg(2, 0x1b);
  setCopReg(2, in_zero, *(u_char *)vertex2);
  setCopReg(2, in_at, *(u_char *)&vertex2->vz);
  copFunction(2, 0x480012);
  DAT_1f800290 = getCopReg(2, 0x19);
  DAT_1f800294 = getCopReg(2, 0x1a);
  DAT_1f800298 = getCopReg(2, 0x1b);
  if (((DAT_1f800280 < 0xa0) && (DAT_1f80028c < 0xa0)) && (DAT_1f800298 < 0xa0))
  {
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
  DAT_1f8002a8 = color0;
  puVar26 = (u_char *)&texture->r0;
  DAT_1f8002ac = color1;
  psVar16 = &texture->y0;
  DAT_1f8002b0 = color2;
  pSVar3 = vertex0;
  pSVar10 = vertex2;
  puVar11 = puVar15;
  puVar23 = puVar15;
  do
  {
    iVar19 = iVar21 + 1;
    if (2 < iVar19)
    {
      iVar19 = 0;
    }
    uVar13 = (u_int)((int)puVar11[0x20] < 0xa0) ^ 1;
    uVar6 = (u_int)((int)(&DAT_1f800280)[iVar19 * 3] < 0xa0) ^ 1;
    if (uVar13 != 0)
    {
      pSVar3 = vertex1;
      if (((iVar21 != 1) && (pSVar3 = vertex0, 1 < iVar21)) && (iVar21 == 2))
      {
        pSVar3 = vertex2;
      }
      setCopReg(2, in_zero, *(u_char *)pSVar3);
      setCopReg(2, in_at, *(u_char *)&pSVar3->vz);
      copFunction(2, 0x180001);
      *(u_char *)(psVar16 + 1) = puVar23[0x2e];
      *puVar26 = puVar23[0x2a];
      uVar17 = getCopReg(2, 0xe);
      puVar26[1] = uVar17;
      uVar17 = getCopReg(2, 0xe);
      (&DAT_1f8002c4)[iVar9] = uVar17;
      iVar27 = getCopReg(2, 0x13);
      if (iVar25 < iVar27)
      {
        iVar25 = iVar27;
      }
      pSVar3 = (SVECTOR *)((u_int)(int)psVar16[-1] >> 0x1f);
      if (*psVar16 < 0)
      {
        pSVar3 = (SVECTOR *)((u_int)pSVar3 | 2);
      }
      if (0x200 < (int)psVar16[-1])
      {
        pSVar3 = (SVECTOR *)((u_int)pSVar3 | 4);
      }
      if (0xf0 < *psVar16)
      {
        pSVar3 = (SVECTOR *)((u_int)pSVar3 | 8);
      }
      uVar22 = uVar22 & (u_int)pSVar3;
      iVar9 = iVar9 + 1;
      psVar16 = psVar16 + 6;
      puVar26 = puVar26 + 3;
    }
    if (uVar13 != uVar6)
    {

      (int)(puVar11[0x20] - (&DAT_1f800280)[iVar19 * 3]);
      if (iVar27 < 0)
      {
        iVar27 = -iVar27;
      }
      iVar28 = ((&DAT_1f800278)[iVar19 * 3] - puVar11[0x1e]) * iVar27;
      pSVar10 = (SVECTOR *)(0x1000 - iVar27);
      if (iVar28 < 0)
      {
        iVar28 = iVar28 + 0xfff;
      }
      iVar28 = (puVar11[0x1e] + (iVar28 >> 0xc)) * 2 + 0x100;
      sVar5 = (short)iVar28;
      if (0x3ff < iVar28)
      {
        sVar5 = 0x3ff;
      }
      if (iVar28 < -0x3ff)
      {
        sVar5 = -0x3ff;
      }
      psVar16[-1] = sVar5;
      iVar28 = ((&DAT_1f80027c)[iVar19 * 3] - puVar11[0x1f]) * iVar27;
      if (iVar28 < 0)
      {
        iVar28 = iVar28 + 0xfff;
      }
      iVar28 = (puVar11[0x1f] + (iVar28 >> 0xc)) * 2 + 0x78;
      sVar5 = (short)iVar28;
      if (0x3ff < iVar28)
      {
        sVar5 = 0x3ff;
      }
      if (iVar28 < -0x3ff)
      {
        sVar5 = -0x3ff;
      }
      *psVar16 = sVar5;
      setCopReg(2, 0x4000, pSVar10);
      setCopReg(2, 0x4800, (u_int) * (byte *)((int)&DAT_1f8002b8 + iVar24));
      setCopReg(2, 0x5000, (u_int) * (byte *)((int)&DAT_1f8002b8 + iVar24 + 1));
      copFunction(2, 0x198003d);
      setCopReg(2, 0x4000, iVar27);
      iVar28 = iVar19 * 4;
      setCopReg(2, 0x4800, (u_int) * (byte *)(&DAT_1f8002b8 + iVar19));
      setCopReg(2, 0x5000, (u_int) * (byte *)((int)&DAT_1f8002b8 + iVar28 + 1));
      copFunction(2, 0x1a8003e);
      uVar17 = getCopReg(2, 0x4800);
      uVar18 = getCopReg(2, 0x5000);
      *(char *)(puVar26 + 2) = (char)uVar17;
      *(undefined *)((int)puVar26 + 9) = (char)uVar18;
      setCopReg(2, 0x4000, pSVar10);
      setCopReg(2, 0x4800, (u_int) * (byte *)((int)&DAT_1f8002a8 + iVar24));
      setCopReg(2, 0x5000, (u_int) * (byte *)((int)&DAT_1f8002a8 + iVar24 + 1));
      setCopReg(2, 0x5800, (u_int) * (byte *)((int)&DAT_1f8002a8 + iVar24 + 2));
      copFunction(2, 0x198003d);
      setCopReg(2, 0x4000, iVar27);
      setCopReg(2, 0x4800, (u_int) * (byte *)(&DAT_1f8002a8 + iVar19));
      setCopReg(2, 0x5000, (u_int) * (byte *)((int)&DAT_1f8002a8 + iVar28 + 1));
      setCopReg(2, 0x5800, (u_int) * (byte *)((int)&DAT_1f8002a8 + iVar28 + 2));
      copFunction(2, 0x1a8003e);
      uVar17 = getCopReg(2, 0x4800);
      uVar18 = getCopReg(2, 0x5000);
      uVar20 = getCopReg(2, 0x5800);
      *(char *)puVar26 = (char)uVar17;
      *(undefined *)((int)puVar26 + 1) = (char)uVar18;
      *(undefined *)((int)puVar26 + 2) = (char)uVar20;
      (&DAT_1f8002c4)[iVar9] = *(u_char *)(psVar16 + -1);
      pSVar3 = (SVECTOR *)(int)*psVar16;
      uVar6 = (u_int)(int)psVar16[-1] >> 0x1f;
      if ((int)pSVar3 < 0)
      {
        uVar6 = uVar6 | 2;
      }
      if (0x200 < (int)psVar16[-1])
      {
        uVar6 = uVar6 | 4;
      }
      if (0xf0 < (int)pSVar3)
      {
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
  if (uVar22 != 0)
  {
    return 2;
  }
  iVar25 = iVar25 >> 2;
  uVar22 = (u_int)(iVar25 < 0xc00);
  if (iVar25 < 0xc00)
  {
    if (ndiv == 0)
    {
      bVar1 = false;
      if (0 < iVar9)
      {
        iVar24 = 1;
        iVar21 = 0;
        do
        {
          iVar19 = iVar24 << 2;
          if (iVar9 <= iVar24)
          {
            iVar24 = 0;
            iVar19 = 0;
          }
          pSVar3 = (SVECTOR *)(int)*(short *)(puVar15 + 0x31);
          uVar6 = SEXT24(*(short *)((int)&DAT_1f8002c4 + iVar19));
          pSVar4 = (SVECTOR *)((int)pSVar3 - uVar6);
          if ((int)pSVar4 < 0)
          {
            pSVar4 = (SVECTOR *)(uVar6 - (int)pSVar3);
          }
          uVar22 = iVar24 * 4;
          if (0x3ff < (int)pSVar4)
          {
          LAB_8002c1b4:
            bVar1 = true;
            break;
          }
          pSVar3 = (SVECTOR *)(int)*(short *)((int)puVar15 + 0xc6);
          uVar6 = SEXT24(*(short *)((int)&DAT_1f8002c4 + uVar22 + 2));
          pSVar4 = (SVECTOR *)((int)pSVar3 - uVar6);
          if ((int)pSVar4 < 0)
          {
            pSVar4 = (SVECTOR *)(uVar6 - (int)pSVar3);
          }
          uVar22 = (u_int)((int)pSVar4 < 0x200);
          if ((int)pSVar4 >= 0x200)
            goto LAB_8002c1b4;
          puVar15 = puVar15 + 1;
          iVar19 = iVar21 + 1;
          uVar22 = (u_int)(iVar19 < iVar9);
          iVar24 = iVar21 + 2;
          iVar21 = iVar19;
        } while (iVar19 < iVar9);
      }
      if (bVar1)
        goto LAB_8002c268;
      uVar22 = 4;
      if (iVar9 == 4)
      {
        pSVar3 = (SVECTOR *)(int)DAT_1f8002d0;
        uVar6 = SEXT24((short)DAT_1f8002c8);
        pSVar4 = (SVECTOR *)((int)pSVar3 - uVar6);
        if ((int)pSVar4 < 0)
        {
          pSVar4 = (SVECTOR *)(uVar6 - (int)pSVar3);
        }
        uVar22 = (u_int)((int)pSVar4 < 0x400);
        if ((int)pSVar4 < 0x400)
        {
          pSVar3 = (SVECTOR *)(int)DAT_1f8002d2;
          uVar6 = SEXT24(DAT_1f8002c8._2_2_);
          pSVar4 = (SVECTOR *)((int)pSVar3 - uVar6);
          if ((int)pSVar4 < 0)
          {
            pSVar4 = (SVECTOR *)(uVar6 - (int)pSVar3);
          }
          uVar22 = (u_int)((int)pSVar4 < 0x200);
          if ((int)pSVar4 < 0x200)
            goto LAB_8002c260;
        }
        bVar1 = true;
      }
    LAB_8002c260:
      if (bVar1)
      {
      LAB_8002c268:
        setCopReg(2, in_zero, *(u_char *)vertex0);
        setCopReg(2, in_at, *(u_char *)&vertex0->vz);
        setCopReg(2, uVar22, *(u_char *)vertex1);
        setCopReg(2, uVar6, *(u_char *)&vertex1->vz);
        setCopReg(2, pSVar3, *(u_char *)vertex2);
        setCopReg(2, iVar9, *(u_char *)&vertex2->vz);
        DAT_1f8002b0 = DAT_1f8002a8 & 0xff000000 | DAT_1f8002b0 & 0xffffff;
        setCopReg(2, primPool, DAT_1f8002a8);
        setCopReg(2, vertex2, DAT_1f8002ac);
        setCopReg(2, vertex0, DAT_1f8002b0);
        setCopReg(2, pSVar10, DAT_1f8002b0);
        *(UVTYPE *)&texture->u0 = *uv0;
        *(UVTYPE *)&texture->u1 = *uv1;
        *(UVTYPE *)&texture->u2 = *uv2;
        DRAW_Zclip_subdiv(texture, ot, 1);
        return 1;
      }
    }
    setCopReg(2, 0x6000, *(u_char *)&texture->x0);
    setCopReg(2, 0x7000, *(u_char *)&texture->x2);
    setCopReg(2, 0x6800, *(u_char *)&texture->x1);
    copFunction(2, 0x1400006);
    texture->clut = DAT_1f8002b8.pad;
    texture->tpage = DAT_1f8002bc.pad;
    iVar21 = getCopReg(2, 0x18);
    if (0 < iVar21)
    {
      return 4;
    }
    bVar2 = (byte)((u_int)color0 >> 0x18);
    if (iVar9 == 3)
    {
      texture->code = bVar2;
      texture->tag = (u_int)ot[iVar25] & 0xffffff | 0x9000000;
      ot[iVar25] = (u_long *)((u_int)texture & 0xffffff);
      iVar9 = primPool->numPrims;
      puVar8 = primPool->nextPrim + 10;
    }
    else
    {
      if (iVar9 != 4)
        goto LAB_8002c3b4;
      uVar12 = *(u_long *)&texture->r2;
      uVar20 = *(u_char *)&texture->x2;
      uVar14 = *(u_char *)&texture->u2;
      uVar7 = texture[1].tag;
      uVar17 = *(u_char *)&texture[1].r0;
      uVar18 = *(u_char *)&texture[1].x0;
      texture->code = bVar2 | 8;
      *(u_long *)&texture->r2 = uVar7;
      *(u_char *)&texture->x2 = uVar17;
      *(u_char *)&texture->u2 = uVar18;
      texture[1].tag = uVar12;
      *(u_char *)&texture[1].r0 = uVar20;
      *(u_char *)&texture[1].x0 = uVar14;
      texture->tag = (u_int)ot[iVar25] & 0xffffff | 0xc000000;
      ot[iVar25] = (u_long *)((u_int)texture & 0xffffff);
      iVar9 = primPool->numPrims;
      puVar8 = primPool->nextPrim + 0xd;
    }
    iVar25 = 1;
    primPool->nextPrim = puVar8;
    primPool->numPrims = iVar9 + 1;
  }
  else
  {
  LAB_8002c3b4:
    iVar25 = 2;
  }
  return iVar25;
}

long *DRAW_Zclip_subdiv(POLY_GT3 *texture, u_long **ot, int ndiv)

{
  u_char uVar1;
  _PrimPool *primPool;
  u_int uVar2;
  u_int uVar3;
  u_int uVar4;
  u_int uVar5;
  u_long *puVar6;
  SVECTOR *vertex2;
  UVTYPE *uv1;
  UVTYPE *uv2;
  SVECTOR *vertex1;
  SVECTOR *vertex1_00;
  UVTYPE *uv1_00;
  u_char *puVar7;

  puVar7 = &DAT_1f800200;
  if (ndiv != 0)
  {
    puVar7 = &DAT_1f8002d4;
  }
  uVar1 = getCopReg(2, 0x14);
  puVar7[0x18] = uVar1;
  uVar1 = getCopReg(2, 0x15);
  puVar7[0x19] = uVar1;
  uVar1 = getCopReg(2, 0x16);
  puVar7[0x1a] = uVar1;
  uVar1 = getCopReg(2, 0);
  *puVar7 = uVar1;
  uVar1 = getCopReg(2, 1);
  puVar7[1] = uVar1;
  uVar1 = getCopReg(2, 2);
  puVar7[2] = uVar1;
  uVar1 = getCopReg(2, 3);
  puVar7[3] = uVar1;
  uVar1 = getCopReg(2, 4);
  puVar7[4] = uVar1;
  uVar1 = getCopReg(2, 5);
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
 2);
  *(undefined2 *)((int)puVar7 + 0x32) =
 2);
  *(short *)(puVar7 + 0xd) =
 2);
  *(short *)(puVar7 + 0xe) =
 2);
  *(undefined2 *)((int)puVar7 + 0x3a) =
 2);
  *(short *)(puVar7 + 0xf) =
 2);
  *(short *)(puVar7 + 0x10) =
 2);
  *(undefined2 *)((int)puVar7 + 0x42) =
 2);
  *(short *)(puVar7 + 0x11) =
 2);
  uv1_00 = (UVTYPE *)(puVar7 + 0x15);
  puVar7[0x12] = *(u_char *)&texture->u0;
  uv2 = (UVTYPE *)(puVar7 + 0x17);
  puVar7[0x13] = *(u_char *)&texture->u1;
  vertex1_00 = (SVECTOR *)(puVar7 + 0xc);
  puVar7[0x14] = *(u_char *)&texture->u2;
  *(char *)(puVar7 + 0x15) =
      (char)((int)((u_int) * (byte *)(puVar7 + 0x12) + (u_int) * (byte *)(puVar7 + 0x13)) >> 1);
  vertex2 = (SVECTOR *)(puVar7 + 0x10);
  *(undefined2 *)((int)puVar7 + 0x5a) = *(undefined2 *)((int)puVar7 + 0x4e);
  *(undefined2 *)((int)puVar7 + 0x56) = *(undefined2 *)((int)puVar7 + 0x4e);
  *(undefined *)((int)puVar7 + 0x55) =
      (char)((int)((u_int) * (byte *)((int)puVar7 + 0x49) + (u_int) * (byte *)((int)puVar7 + 0x4d)) >> 1);
  *(char *)(puVar7 + 0x16) =
      (char)((int)((u_int) * (byte *)(puVar7 + 0x13) + (u_int) * (byte *)(puVar7 + 0x14)) >> 1);
  *(undefined *)((int)puVar7 + 0x59) =
      (char)((int)((u_int) * (byte *)((int)puVar7 + 0x4d) + (u_int) * (byte *)((int)puVar7 + 0x51)) >> 1);
  *(char *)(puVar7 + 0x17) =
      (char)((int)((u_int) * (byte *)(puVar7 + 0x14) + (u_int) * (byte *)(puVar7 + 0x12)) >> 1);
  *(undefined *)((int)puVar7 + 0x5d) =
      (char)((int)((u_int) * (byte *)((int)puVar7 + 0x51) + (u_int) * (byte *)((int)puVar7 + 0x49)) >> 1);
  *(undefined2 *)((int)puVar7 + 0x5e) = *(undefined2 *)((int)puVar7 + 0x4a);
  *(char *)(puVar7 + 0x1b) =
      (char)((int)((u_int) * (byte *)(puVar7 + 0x18) + (u_int) * (byte *)(puVar7 + 0x19)) >> 1);
  *(undefined *)((int)puVar7 + 0x6d) =
      (char)((int)((u_int) * (byte *)((int)puVar7 + 0x61) + (u_int) * (byte *)((int)puVar7 + 0x65)) >> 1);
  *(undefined *)((int)puVar7 + 0x6e) =
      (char)((int)((u_int) * (byte *)((int)puVar7 + 0x62) + (u_int) * (byte *)((int)puVar7 + 0x66)) >> 1);
  *(char *)(puVar7 + 0x1c) =
      (char)((int)((u_int) * (byte *)(puVar7 + 0x19) + (u_int) * (byte *)(puVar7 + 0x1a)) >> 1);
  *(undefined *)((int)puVar7 + 0x71) =
      (char)((int)((u_int) * (byte *)((int)puVar7 + 0x65) + (u_int) * (byte *)((int)puVar7 + 0x69)) >> 1);
  *(undefined *)((int)puVar7 + 0x72) =
      (char)((int)((u_int) * (byte *)((int)puVar7 + 0x66) + (u_int) * (byte *)((int)puVar7 + 0x6a)) >> 1);
  *(char *)(puVar7 + 0x1d) =
      (char)((int)((u_int) * (byte *)(puVar7 + 0x1a) + (u_int) * (byte *)(puVar7 + 0x18)) >> 1);
  *(undefined *)((int)puVar7 + 0x75) =
      (char)((int)((u_int) * (byte *)((int)puVar7 + 0x69) + (u_int) * (byte *)((int)puVar7 + 0x61)) >> 1);
  *(undefined *)((int)puVar7 + 0x76) =
      (char)((int)((u_int) * (byte *)((int)puVar7 + 0x6a) + (u_int) * (byte *)((int)puVar7 + 0x62)) >> 1);
  *(undefined *)((int)puVar7 + 0x77) = *(undefined *)((int)puVar7 + 99);
  *(undefined *)((int)puVar7 + 0x6f) = *(undefined *)((int)puVar7 + 99);
  uVar2 = DRAW_DisplayTFace_zclipped_C((SVECTOR *)(puVar7 + 6), vertex1_00, vertex2, (UVTYPE *)(puVar7 + 0x12), uv1_00, uv2, puVar7[0x18], puVar7[0x1b], puVar7[0x1d], primPool, ot, ndiv);
  uv1 = (UVTYPE *)(puVar7 + 0x16);
  vertex1 = (SVECTOR *)(puVar7 + 0xe);
  uVar3 = DRAW_DisplayTFace_zclipped_C(vertex2, vertex1, (SVECTOR *)((u_int)puVar7 | 0x28), uv2, uv1,
                                       (UVTYPE *)(puVar7 + 0x14), puVar7[0x1d], puVar7[0x1c], puVar7[0x1a], primPool, ot,
                                       ndiv);
  *(undefined2 *)((int)puVar7 + 0x56) = *(undefined2 *)((int)puVar7 + 0x4a);
  *(undefined2 *)((int)puVar7 + 0x5e) = *(undefined2 *)((int)puVar7 + 0x4e);
  uVar4 = DRAW_DisplayTFace_zclipped_C(vertex1_00, vertex1, vertex2, uv1_00, uv1, uv2, puVar7[0x1b], puVar7[0x1c],
                                       puVar7[0x1d], primPool, ot, ndiv);
  uVar5 = DRAW_DisplayTFace_zclipped_C(vertex1_00, (SVECTOR *)((u_int)puVar7 | 0x20), vertex1, uv1_00,
                                       (UVTYPE *)(puVar7 + 0x13), uv1, puVar7[0x1b], puVar7[0x19], puVar7[0x1c], primPool,
                                       ot, ndiv);
  puVar6 = (u_long *)0x0;
  if (((uVar2 | uVar3 | uVar4 | uVar5) & 5) != 4)
  {
    puVar6 = primPool->nextPrim;
  }
  return (long *)puVar6;
}

void DRAW_LoadingMessage(void)

{
  u_long **ppuVar1;
  int len;
  char *text;

  do
  {
    len = CheckVolatile(gameTrackerX.drawTimerReturn);
  } while (len != 0);
  do
  {
    len = CheckVolatile(gameTrackerX.reqDisp);
  } while (len != 0);
  DMACallback(0);
  DrawCallback(0);
  ppuVar1 = gameTrackerX.drawOT;
  PutDrawEnv((u_char *)(&draw + (gameTrackerX.drawPage ^ 1)));
  text = localstr_get(LOCALSTR_Hint52);
  FONT_FontPrintCentered(text, 0x96);
  text = localstr_get(LOCALSTR_Hint52);
  len = FONT_GetStringWidth(text);
  DisplayHintBox(len, 0x96);
  FONT_Flush();
  DrawOTag(ppuVar1[0xbff]);
  DrawSync(0);
  ClearOTagR(ppuVar1, 0xc00);
  PutDrawEnv((u_char *)(&draw + gameTrackerX.drawPage));
  DrawCallback(VblTick);
  DMACallback(VSyncCallbacks);
  return;
}
