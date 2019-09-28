#include "THISDUST.H"
#include "COLLIDE.H"

// decompiled code
// original method signature:
// int /*$ra*/ COLLIDE_PointInTriangle(struct _SVector *v0 /*$a0*/, struct _SVector *v1 /*$a1*/, struct _SVector *v2 /*$a2*/, struct _SVector *point /*$a3*/, struct _SVector *normal /*stack 16*/)
// line 243, offset 0x8001e460
/* begin block 1 */
// Start line: 244
// Start offset: 0x8001E460
// Variables:
// 		struct _Triangle2D *triangle; // $t2
// 		int nx; // $t1
// 		int ny; // $v1
// 		short tx; // $t0
// 		short ty; // $a3

/* begin block 1.1 */
// Start line: 244
// Start offset: 0x8001E59C
// Variables:
// 		struct _Triangle2D *tri; // $t2
// 		short tx; // $t0
// 		short ty; // $a3

/* begin block 1.1.1 */
// Start line: 244
// Start offset: 0x8001E59C
// Variables:
// 		int inside_flag; // $t3
// 		int line_flag; // $t7
// 		struct DVECTOR *vert1; // $t2
// 		struct DVECTOR *vert0; // $t1
// 		int yflag1; // $t5
// 		int yflag0; // $v1
// 		int j; // $t6

/* begin block 1.1.1.1 */
// Start line: 244
// Start offset: 0x8001E614
// Variables:
// 		long ydist; // $v0
// 		long xdist; // $v0
// 		long xdiff; // $v1
// 		long ydiff; // $a1
// 		long ix; // $v1
/* end block 1.1.1.1 */
// End offset: 0x8001E67C
// End Line: 244
/* end block 1.1.1 */
// End offset: 0x8001E6FC
// End Line: 244
/* end block 1.1 */
// End offset: 0x8001E6FC
// End Line: 244
/* end block 1 */
// End offset: 0x8001E6FC
// End Line: 288

/* begin block 2 */
// Start line: 369
/* end block 2 */
// End Line: 370

/* begin block 3 */
// Start line: 486
/* end block 3 */
// End Line: 487

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int COLLIDE_PointInTriangle(_SVector *v0, _SVector *v1, _SVector *v2, _SVector *point, _SVector *normal)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  short sVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  short *psVar14;
  short *psVar15;
  uint uVar16;
  int iVar17;

  iVar7 = (int)normal->x;
  iVar9 = (int)normal->y;
  if (iVar7 < 0)
  {
    iVar7 = -iVar7;
  }
  if (iVar9 < 0)
  {
    iVar9 = -iVar9;
  }
  if (iVar9 < iVar7)
  {
    iVar9 = (int)normal->z;
    if (iVar9 < 0)
    {
      iVar9 = -iVar9;
    }
    if (iVar9 < iVar7)
    {
      sVar2 = point->y;
      uVar3 = point->z;
      _DAT_1f800000 = *(undefined4 *)&v0->y;
      _DAT_1f800004 = *(undefined4 *)&v1->y;
      uVar1 = v2->z;
      sVar4 = v2->y;
      goto LAB_8001e594;
    }
  LAB_8001e558:
    sVar2 = point->x;
    uVar3 = point->y;
    _DAT_1f800000 = *(undefined4 *)v0;
    _DAT_1f800004 = *(undefined4 *)v1;
    uVar1 = v2->y;
  }
  else
  {
    iVar7 = (int)normal->z;
    if (iVar7 < 0)
    {
      iVar7 = -iVar7;
    }
    if (iVar9 <= iVar7)
      goto LAB_8001e558;
    sVar2 = point->x;
    uVar3 = point->z;
    _DAT_1f800000 = CONCAT22(v0->z, v0->x);
    _DAT_1f800004 = CONCAT22(v1->z, v1->x);
    uVar1 = v2->z;
  }
  sVar4 = v2->x;
LAB_8001e594:
  _DAT_1f800008 = CONCAT22(uVar1, sVar4);
  uVar16 = 0;
  bVar5 = false;
  iVar17 = 3;
  iVar9 = (int)((uint)uVar3 << 0x10) >> 0x10;
  iVar7 = (int)sVar2;
  psVar14 = &DAT_1f800008;
  psVar15 = &DAT_1f800000;
  bVar8 = (int)((uint)uVar3 << 0x10) <= (int)((uint)uVar1 << 0x10);
  do
  {
    iVar13 = (int)psVar15[1];
    if (bVar8 == iVar9 <= iVar13)
    {
      bVar6 = bVar5;
      if ((bVar8 != false) && (iVar9 == (int)psVar14[1]))
      {
        if (iVar9 == iVar13)
        {
          iVar10 = (int)*psVar15;
          if ((int)*psVar14 < iVar7 != iVar10 < iVar7)
          {
            return 1;
          }
          if (iVar7 == (int)*psVar14)
          {
            return 1;
          }
        }
        else
        {
          iVar10 = (int)*psVar14;
        }
        if (iVar7 == iVar10)
        {
          return 1;
        }
      }
    }
    else
    {
      iVar10 = (int)*psVar14;
      iVar12 = (int)*psVar15;
      if (iVar7 <= iVar10 == iVar7 <= iVar12)
      {
        if (iVar7 <= iVar10)
        {
          uVar16 = (uint)(uVar16 == 0);
        }
      }
      else
      {
        iVar11 = psVar14[1] - iVar13;
        iVar10 = (iVar12 - iVar7) * iVar11 - (iVar13 - iVar9) * (iVar10 - iVar12);
        if (iVar11 < 0)
        {
          iVar11 = -iVar11;
          iVar10 = -iVar10;
        }
        if (iVar11 / 2 < iVar10)
        {
          uVar16 = (uint)(uVar16 == 0);
        }
        else
        {
          if (-(iVar11 / 2) <= iVar10)
          {
            return 1;
          }
        }
      }
      bVar6 = true;
      if (bVar5)
      {
        return uVar16;
      }
    }
    bVar5 = bVar6;
    iVar17 = iVar17 + -1;
    psVar14 = psVar15;
    psVar15 = psVar15 + 2;
    bVar8 = iVar9 <= iVar13;
    if (iVar17 == 0)
    {
      return uVar16;
    }
  } while (true);
}

// decompiled code
// original method signature:
// int /*$ra*/ COLLIDE_PointInTriangle2DPub(short *v0 /*$a0*/, short *v1 /*$a1*/, short *v2 /*$a2*/, short *point /*$a3*/)
// line 296, offset 0x8001e704
/* begin block 1 */
// Start line: 297
// Start offset: 0x8001E704
// Variables:
// 		struct _SVector normal; // stack offset -16
/* end block 1 */
// End offset: 0x8001E704
// End Line: 297

/* begin block 2 */
// Start line: 485
/* end block 2 */
// End Line: 486

void COLLIDE_PointInTriangle2DPub(_SVector *param_1, _SVector *param_2, _SVector *param_3, _SVector *param_4)

{
  undefined4 local_10;
  undefined *local_c;

  local_10 = DAT_800ce16c;
  local_c = PTR_DAT_800ce170;
  COLLIDE_PointInTriangle(param_1, param_2, param_3, param_4, (_SVector *)&local_10);
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ COLLIDE_GetNormal(short nNum /*$a0*/, short *nrmlArray /*$a1*/, struct _SVector *nrml /*$a2*/)
// line 312, offset 0x8001e750
/* begin block 1 */
// Start line: 314
// Start offset: 0x8001E750
// Variables:
// 		short *sPtr; // $a1
// 		long bitMask; // $v1
/* end block 1 */
// End offset: 0x8001E7E0
// End Line: 339

/* begin block 2 */
// Start line: 518
/* end block 2 */
// End Line: 519

/* begin block 3 */
// Start line: 519
/* end block 3 */
// End Line: 520

/* begin block 4 */
// Start line: 522
/* end block 4 */
// End Line: 523

long COLLIDE_GetNormal(short nNum, short *nrmlArray, _SVector *nrml)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;

  iVar3 = (int)nNum;
  if (iVar3 < 0)
  {
    puVar4 = (ushort *)(nrmlArray + iVar3 * 0x7ffffffd);
    uVar1 = *puVar4;
    nrml->x = -(uVar1 & 0x1fff);
    nrml->y = -puVar4[1];
    uVar2 = -puVar4[2];
  }
  else
  {
    puVar4 = (ushort *)(nrmlArray + iVar3 * 3);
    uVar1 = *puVar4;
    nrml->x = uVar1 & 0x1fff;
    nrml->y = puVar4[1];
    uVar2 = puVar4[2];
  }
  nrml->z = uVar2;
  return (int)((uint)uVar1 << 0x10) >> 0x1d;
}

// decompiled code
// original method signature:
// void /*$ra*/ COLLIDE_MakeNormal(struct _Terrain *terrain /*$a0*/, struct _TFace *tface /*$a1*/, struct _SVector *normal /*$t6*/)
// line 368, offset 0x8001e7e8
/* begin block 1 */
// Start line: 369
// Start offset: 0x8001E7E8
// Variables:
// 		struct _SVector *vertex0; // $v1
// 		struct _SVector *vertex1; // $v0
// 		struct _SVector *vertex2; // $a2
// 		int len; // $a0
// 		struct _Vector *a; // $v0
// 		struct _Vector *b; // $v0
// 		struct _Vector *n; // $t0

/* begin block 1.1 */
// Start line: 369
// Start offset: 0x8001E7E8
// Variables:
// 		long _x0; // $t1
// 		long _y0; // $t2
// 		long _z0; // $t0
// 		long _x1; // $a0
// 		long _y1; // $v0
// 		long _z1; // $a0
/* end block 1.1 */
// End offset: 0x8001E7E8
// End Line: 369

/* begin block 1.2 */
// Start line: 369
// Start offset: 0x8001E7E8
// Variables:
// 		long _x0; // $a0
// 		long _y0; // $a1
// 		long _z0; // $a3
// 		long _x1; // $v0
// 		long _y1; // $v0
// 		long _z1; // $v0
/* end block 1.2 */
// End offset: 0x8001E7E8
// End Line: 369
/* end block 1 */
// End offset: 0x8001E9B8
// End Line: 399

/* begin block 2 */
// Start line: 648
/* end block 2 */
// End Line: 649

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void COLLIDE_MakeNormal(_Terrain *terrain, _TFace *tface, _SVector *normal)

{
  _TVertex *p_Var1;
  int iVar2;
  _TVertex *p_Var3;
  int iVar4;
  _TVertex *p_Var5;

  p_Var5 = terrain->vertexList;
  p_Var1 = p_Var5 + (tface->face).v1;
  p_Var3 = p_Var5 + (tface->face).v0;
  _DAT_1f800000 = (int)(p_Var1->vertex).x - (int)(p_Var3->vertex).x;
  _DAT_1f800004 = (int)(p_Var1->vertex).y - (int)(p_Var3->vertex).y;
  _DAT_1f800008 = (int)(p_Var1->vertex).z - (int)(p_Var3->vertex).z;
  p_Var5 = p_Var5 + (tface->face).v2;
  DAT_1f800018 = (int)(p_Var5->vertex).z - (int)(p_Var3->vertex).z;
  _DAT_1f800014 = (int)(p_Var5->vertex).y - (int)(p_Var3->vertex).y;
  _DAT_1f800010 = (int)(p_Var5->vertex).x - (int)(p_Var3->vertex).x;
  DAT_1f800024 = (int)(short)-(short)(_DAT_1f800000 * DAT_1f800018 - _DAT_1f800008 * _DAT_1f800010 >> 0xc);
  iVar2 = DAT_1f800024;
  if (DAT_1f800024 < 0)
  {
    iVar2 = -DAT_1f800024;
  }
  DAT_1f800020 = (_DAT_1f800004 * DAT_1f800018 - _DAT_1f800008 * _DAT_1f800014) * 0x10 >> 0x10;
  iVar4 = DAT_1f800020;
  if (DAT_1f800020 < 0)
  {
    iVar4 = -DAT_1f800020;
  }
  DAT_1f800028 = (_DAT_1f800000 * _DAT_1f800014 - _DAT_1f800004 * _DAT_1f800010) * 0x10 >> 0x10;
  if (iVar2 < iVar4)
  {
    iVar2 = iVar4;
  }
  iVar4 = DAT_1f800028;
  if (DAT_1f800028 < 0)
  {
    iVar4 = -DAT_1f800028;
  }
  if (iVar2 < iVar4)
  {
    iVar2 = iVar4;
  }
  if (iVar2 != 0)
  {
    normal->x = (short)((DAT_1f800020 << 0xc) / iVar2);
    normal->y = (short)((DAT_1f800024 << 0xc) / iVar2);
    normal->z = (short)((DAT_1f800028 << 0xc) / iVar2);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ COLLIDE_UpdateAllTransforms(struct _Instance *instance /*$a0*/, struct SVECTOR *offset /*$a1*/)
// line 415, offset 0x8001e9c0
/* begin block 1 */
// Start line: 417
// Start offset: 0x8001E9C0
// Variables:
// 		struct MATRIX *swTransform; // $v1

/* begin block 1.1 */
// Start line: 421
// Start offset: 0x8001E9D0
// Variables:
// 		int i; // $a2
// 		long numMatrices; // $v0
// 		long ox; // $t1
// 		long oy; // $t0
// 		long oz; // $a1
/* end block 1.1 */
// End offset: 0x8001EA88
// End Line: 447
/* end block 1 */
// End offset: 0x8001EA88
// End Line: 448

/* begin block 2 */
// Start line: 801
/* end block 2 */
// End Line: 802

/* begin block 3 */
// Start line: 802
/* end block 3 */
// End Line: 803

/* begin block 4 */
// Start line: 804
/* end block 4 */
// End Line: 805

void COLLIDE_UpdateAllTransforms(_Instance *instance, SVECTOR *offset)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  MATRIX *pMVar5;
  int *piVar6;
  Object *pOVar7;

  if (instance->matrix != (MATRIX *)0x0)
  {
    sVar1 = offset->vx;
    pOVar7 = instance->object;
    sVar2 = offset->vy;
    sVar3 = offset->vz;
    if ((pOVar7->animList == (_G2AnimKeylist_Type **)0x0) || ((pOVar7->oflags2 & 0x40000000U) != 0))
    {
      pMVar5 = instance->matrix;
      iVar4 = instance->object->modelList[instance->currentModel]->numSegments;
    }
    else
    {
      pMVar5 = instance->matrix + -1;
      iVar4 = pOVar7->modelList[instance->currentModel]->numSegments + 1;
    }
    piVar6 = pMVar5->t + 2;
    while (iVar4 != 0)
    {
      iVar4 = iVar4 + -1;
      piVar6[-2] = piVar6[-2] + (int)sVar1;
      *piVar6 = *piVar6 + (int)sVar3;
      piVar6[-1] = piVar6[-1] + (int)sVar2;
      piVar6 = piVar6 + 8;
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ COLLIDE_MoveAllTransforms(struct _Instance *instance /*$a0*/, struct _Position *offset /*$a1*/)
// line 450, offset 0x8001ea90
/* begin block 1 */
// Start line: 452
// Start offset: 0x8001EA90
// Variables:
// 		struct MATRIX *swTransform; // $v1

/* begin block 1.1 */
// Start line: 456
// Start offset: 0x8001EAA0
// Variables:
// 		int i; // $a2
// 		long ox; // $t1
// 		long oy; // $t0
// 		long oz; // $a1
// 		long numMatrices; // $v0
/* end block 1.1 */
// End offset: 0x8001EB58
// End Line: 480
/* end block 1 */
// End offset: 0x8001EB58
// End Line: 481

/* begin block 2 */
// Start line: 884
/* end block 2 */
// End Line: 885

/* begin block 3 */
// Start line: 885
/* end block 3 */
// End Line: 886

/* begin block 4 */
// Start line: 887
/* end block 4 */
// End Line: 888

void COLLIDE_MoveAllTransforms(_Instance *instance, _Position *offset)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  MATRIX *pMVar5;
  int *piVar6;
  Object *pOVar7;

  if (instance->oldMatrix != (MATRIX *)0x0)
  {
    sVar1 = offset->x;
    pOVar7 = instance->object;
    sVar2 = offset->y;
    sVar3 = offset->z;
    if ((pOVar7->animList == (_G2AnimKeylist_Type **)0x0) || ((pOVar7->oflags2 & 0x40000000U) != 0))
    {
      pMVar5 = instance->oldMatrix;
      iVar4 = instance->object->modelList[instance->currentModel]->numSegments;
    }
    else
    {
      pMVar5 = instance->oldMatrix + -1;
      iVar4 = pOVar7->modelList[instance->currentModel]->numSegments + 1;
    }
    piVar6 = pMVar5->t + 2;
    while (iVar4 != 0)
    {
      iVar4 = iVar4 + -1;
      piVar6[-2] = piVar6[-2] + (int)sVar1;
      *piVar6 = *piVar6 + (int)sVar3;
      piVar6[-1] = piVar6[-1] + (int)sVar2;
      piVar6 = piVar6 + 8;
    }
  }
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ COLLIDE_WithinYZBounds(struct _SVector *point /*$a0*/, struct _HBox *hbox /*$a1*/)
// line 590, offset 0x8001eb60
/* begin block 1 */
// Start line: 1180
/* end block 1 */
// End Line: 1181

/* begin block 2 */
// Start line: 1070
/* end block 2 */
// End Line: 1071

long COLLIDE_WithinYZBounds(_SVector *point, _HBox *hbox)

{
  uint uVar1;

  uVar1 = 0;
  if (((hbox->minY <= point->y) && (point->y <= hbox->maxY)) && (hbox->minZ <= point->z))
  {
    uVar1 = (uint)(hbox->maxZ < point->z) ^ 1;
  }
  return uVar1;
}

// autogenerated function stub:
// long /*$ra*/ COLLIDE_WithinXZBounds(struct _SVector *point /*$a0*/, struct _HBox *hbox /*$a1*/)
long COLLIDE_WithinXZBounds(struct _SVector *point, struct _HBox *hbox)
{ // line 596, offset 0x8001ebbc
  /* begin block 1 */
  // Start line: 1081
  /* end block 1 */
  // End Line: 1082

  /* begin block 2 */
  // Start line: 1082
  /* end block 2 */
  // End Line: 1083

  return 0;
}

// decompiled code
// original method signature:
// long /*$ra*/ COLLIDE_WithinXYBounds(struct _SVector *point /*$a0*/, struct _HBox *hbox /*$a1*/)
// line 602, offset 0x8001ec18
/* begin block 1 */
// Start line: 1093
/* end block 1 */
// End Line: 1094

/* begin block 2 */
// Start line: 1094
/* end block 2 */
// End Line: 1095

long COLLIDE_WithinXYBounds(_SVector *point, _HBox *hbox)

{
  uint uVar1;

  uVar1 = 0;
  if (((hbox->minX <= point->x) && (point->x <= hbox->maxX)) && (hbox->minY <= point->y))
  {
    uVar1 = (uint)(hbox->maxY < point->y) ^ 1;
  }
  return uVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ COLLIDE_LineWithBoxFace(short startDist /*$a0*/, long lineDist /*$a1*/, short planeDist /*$a2*/, struct _SVector *start /*$a3*/, struct _Vector *line /*stack 16*/, struct _HBox *hbox /*stack 20*/, TDRFuncPtr_COLLIDE_LineWithBoxFace6collideBoundFunc collideBoundFunc /*stack 24*/, struct _SVector *normal /*stack 28*/)
// line 611, offset 0x8001ec74
/* begin block 1 */
// Start line: 612
// Start offset: 0x8001EC74
// Variables:
// 		struct _SVector point; // stack offset -24
// 		long t; // stack offset -16

/* begin block 1.1 */
// Start line: 612
// Start offset: 0x8001ED38
// Variables:
// 		struct _SVector *point; // $t1
// 		struct _SVector *normal; // $s0
// 		struct _SVector *point0; // $a2
// 		struct _SVector *normal0; // $a3
// 		struct _SVector *point1; // $a1
// 		struct _SVector *normal1; // $t0

/* begin block 1.1.1 */
// Start line: 612
// Start offset: 0x8001ED38

/* begin block 1.1.1.1 */
// Start line: 612
// Start offset: 0x8001ED5C
// Variables:
// 		short _z1; // $a0
// 		short _y1; // $v1
// 		short _x1; // $v0
/* end block 1.1.1.1 */
// End offset: 0x8001ED5C
// End Line: 612

/* begin block 1.1.1.2 */
// Start line: 612
// Start offset: 0x8001ED5C
// Variables:
// 		short _z1; // $a0
// 		short _y1; // $v1
// 		short _x1; // $v0
/* end block 1.1.1.2 */
// End offset: 0x8001ED5C
// End Line: 612

/* begin block 1.1.1.3 */
// Start line: 612
// Start offset: 0x8001ED5C
// Variables:
// 		short _z1; // $a0
// 		short _y1; // $v1
// 		short _x1; // $v0
/* end block 1.1.1.3 */
// End offset: 0x8001ED5C
// End Line: 612

/* begin block 1.1.1.4 */
// Start line: 612
// Start offset: 0x8001ED5C
// Variables:
// 		short _z1; // $a0
// 		short _y1; // $v1
// 		short _x1; // $v0
/* end block 1.1.1.4 */
// End offset: 0x8001ED5C
// End Line: 612

/* begin block 1.1.1.5 */
// Start line: 612
// Start offset: 0x8001EDDC
// Variables:
// 		short _z1; // $a0
// 		short _y1; // $v1
// 		short _x1; // $v0
/* end block 1.1.1.5 */
// End offset: 0x8001EDDC
// End Line: 612

/* begin block 1.1.1.6 */
// Start line: 612
// Start offset: 0x8001EDDC
// Variables:
// 		short _z1; // $a0
// 		short _y1; // $v1
// 		short _x1; // $v0
/* end block 1.1.1.6 */
// End offset: 0x8001EDDC
// End Line: 612
/* end block 1.1.1 */
// End offset: 0x8001EE10
// End Line: 612
/* end block 1.1 */
// End offset: 0x8001EE10
// End Line: 612
/* end block 1 */
// End offset: 0x8001EE10
// End Line: 643

/* begin block 2 */
// Start line: 1111
/* end block 2 */
// End Line: 1112

void COLLIDE_LineWithBoxFace(short startDist, long lineDist, short planeDist, _SVector *start, _Vector *line,
                             _HBox *hbox, TDRFuncPtr_COLLIDE_LineWithBoxFace6collideBoundFunc collideBoundFunc,
                             _SVector *normal)

{
  short sVar1;
  short sVar2;
  _SVector *p_Var3;
  _SVector *p_Var4;
  _SVector *p_Var5;
  _SVector *p_Var6;
  long lVar7;
  short local_18;
  short local_16;
  short local_14;
  undefined *local_10;

  if (lineDist != 0)
  {
    local_10 = (undefined *)((((int)startDist - (int)planeDist) * -0x1000) / lineDist);
    if (local_10 < &DAT_00001001)
    {
      local_18 = start->x + (short)(line->x * (int)local_10 >> 0xc);
      local_16 = start->y + (short)(line->y * (int)local_10 >> 0xc);
      local_14 = start->z + (short)(line->z * (int)local_10 >> 0xc);
      lVar7 = (*collideBoundFunc)(&local_18, hbox);
      p_Var6 = collide_normal1;
      p_Var5 = collide_normal0;
      p_Var4 = collide_point1;
      p_Var3 = collide_point0;
      if (lVar7 != 0)
      {
        if ((int)local_10 < collide_t0)
        {
          sVar1 = collide_point0->y;
          sVar2 = collide_point0->z;
          collide_point1->x = collide_point0->x;
          p_Var4->y = sVar1;
          p_Var4->z = sVar2;
          sVar1 = p_Var5->y;
          sVar2 = p_Var5->z;
          p_Var6->x = p_Var5->x;
          p_Var6->y = sVar1;
          p_Var6->z = sVar2;
          p_Var3->x = local_18;
          p_Var3->y = local_16;
          p_Var3->z = local_14;
          sVar1 = normal->y;
          sVar2 = normal->z;
          collide_t1 = collide_t0;
          collide_t0 = (long)local_10;
          p_Var5->x = normal->x;
          p_Var5->y = sVar1;
          p_Var5->z = sVar2;
        }
        else
        {
          if ((int)local_10 < collide_t1)
          {
            collide_point1->x = local_18;
            p_Var4->y = local_16;
            p_Var4->z = local_14;
            sVar1 = normal->y;
            sVar2 = normal->z;
            collide_t1 = (long)local_10;
            p_Var6->x = normal->x;
            p_Var6->y = sVar1;
            p_Var6->z = sVar2;
          }
        }
      }
    }
  }
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ COLLIDE_IntersectLineAndBox(struct _SVector *point0 /*$a0*/, struct _SVector *normal0 /*$a1*/, struct _SVector *point1 /*$a2*/, struct _SVector *normal1 /*$a3*/, struct _SVector *end /*stack 16*/, struct _SVector *start /*stack 20*/, struct _HBox *hbox /*stack 24*/)
// line 650, offset 0x8001ee20
/* begin block 1 */
// Start line: 651
// Start offset: 0x8001EE20
// Variables:
// 		struct _SVector normal; // stack offset -64
// 		struct _Vector line; // stack offset -56

/* begin block 1.1 */
// Start line: 651
// Start offset: 0x8001EE20
// Variables:
// 		long _x0; // $a1
// 		long _y0; // $a2
// 		long _z0; // $a0
// 		long _x1; // $v0
// 		long _y1; // $v0
// 		long _z1; // $v1
// 		struct _Vector *_v; // $s3
/* end block 1.1 */
// End offset: 0x8001EE20
// End Line: 651
/* end block 1 */
// End offset: 0x8001F070
// End Line: 711

/* begin block 2 */
// Start line: 1201
/* end block 2 */
// End Line: 1202

void COLLIDE_IntersectLineAndBox(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4,
                                 short *param_5, _SVector *param_6, _HBox *param_7)

{
  _SVector _Stack64;
  _Vector _Stack56;

  puGpffffa8b4 = &DAT_00001001;
  puGpffffa8b8 = &DAT_00001001;
  _Stack56.x = (int)*param_5 - (int)param_6->x;
  _Stack56.z = (int)param_5[2] - (int)param_6->z;
  _Stack56.y = (int)param_5[1] - (int)param_6->y;
  _Stack64.x = -0x1000;
  _Stack64.y = 0;
  _Stack64.z = 0;
  uGpffffa8ac = param_1;
  uGpffffa8b0 = param_3;
  uGpffffa8c8 = param_2;
  uGpffffa8cc = param_4;
  /* WARNING: Subroutine does not return */
  COLLIDE_LineWithBoxFace(-param_6->x, -_Stack56.x, -param_7->minX, param_6, &_Stack56, param_7, COLLIDE_WithinYZBounds, &_Stack64);
}

// decompiled code
// original method signature:
// struct _TFace * /*$ra*/ COLLIDE_PointAndTerrain(struct _Terrain *terrain /*$a0*/, struct _PCollideInfo *pcollideInfo /*$a1*/, struct _LCollideInfo *lcol /*$a2*/)
// line 770, offset 0x8001f09c
/* begin block 1 */
// Start line: 1519
/* end block 1 */
// End Line: 1520

_TFace *COLLIDE_PointAndTerrain(_Terrain *terrain, _PCollideInfo *pcollideInfo, _LCollideInfo *lcol)

{
  _TFace *p_Var1;

  p_Var1 = COLLIDE_PointAndTerrainFunc(terrain, pcollideInfo, 0, (short *)0x0, 0, 0, lcol);
  return p_Var1;
}

// decompiled code
// original method signature:
// struct _TFace * /*$ra*/ COLLIDE_PointAndTerrainFunc(struct _Terrain *terrain /*$t2*/, struct _PCollideInfo *pCollideInfo /*stack 4*/, int Flags /*$a2*/, short *Backface_Flag /*$a3*/, long ignoreAttr /*stack 16*/, long acceptAttr /*stack 20*/, struct _LCollideInfo *lcolinfo /*stack 24*/)
// line 780, offset 0x8001f0cc
/* begin block 1 */
// Start line: 781
// Start offset: 0x8001F0CC
// Variables:
// 		struct PandTScratch *CSpad; // $s0
// 		void **stack; // $s1
// 		struct _BSPNode *bspNode; // $a1
// 		int curTree; // stack offset -48
// 		struct _SVector *NewPos; // stack offset -80
// 		struct _SVector *OldPos; // $a0
// 		struct _Instance *instance; // $s7

/* begin block 1.1 */
// Start line: 781
// Start offset: 0x8001F0CC
// Variables:
// 		short _x1; // $a3
// 		short _y1; // $t0
// 		short _z1; // $t1
// 		struct _SVector *_v0; // $v1
/* end block 1.1 */
// End offset: 0x8001F0CC
// End Line: 781

/* begin block 1.2 */
// Start line: 781
// Start offset: 0x8001F0CC
// Variables:
// 		short _x1; // $v0
// 		short _y1; // $v1
// 		short _z1; // $a0
// 		struct _SVector *_v0; // $a2
/* end block 1.2 */
// End offset: 0x8001F0CC
// End Line: 781

/* begin block 1.3 */
// Start line: 781
// Start offset: 0x8001F0CC
// Variables:
// 		struct _SVector *_v; // $a1
/* end block 1.3 */
// End offset: 0x8001F0CC
// End Line: 781

/* begin block 1.4 */
// Start line: 837
// Start offset: 0x8001F22C
// Variables:
// 		struct BSPTree *bsp; // $s4

/* begin block 1.4.1 */
// Start line: 865
// Start offset: 0x8001F328
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a0
// 		short _x1; // $a1
// 		short _y1; // $a2
// 		short _z1; // $t0
// 		struct _SVector *_v; // $s6
// 		struct _Position *_v1; // $a3
/* end block 1.4.1 */
// End offset: 0x8001F328
// End Line: 865

/* begin block 1.4.2 */
// Start line: 865
// Start offset: 0x8001F328
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a0
// 		short _x1; // $a1
// 		short _y1; // $a2
// 		short _z1; // $a3
// 		struct _SVector *_v; // $s5
/* end block 1.4.2 */
// End offset: 0x8001F328
// End Line: 865

/* begin block 1.4.3 */
// Start line: 898
// Start offset: 0x8001F558
// Variables:
// 		struct _TFace *tface; // $s3

/* begin block 1.4.3.1 */
// Start line: 905
// Start offset: 0x8001F5A4
// Variables:
// 		struct _SVector *vertex0; // $a0

/* begin block 1.4.3.1.1 */
// Start line: 781
// Start offset: 0x8001F62C
// Variables:
// 		short *nrmlArray; // $a0
// 		struct _SVector *nrml; // $a1

/* begin block 1.4.3.1.1.1 */
// Start line: 781
// Start offset: 0x8001F62C
// Variables:
// 		short *sPtr; // $v1
/* end block 1.4.3.1.1.1 */
// End offset: 0x8001F6BC
// End Line: 781
/* end block 1.4.3.1.1 */
// End offset: 0x8001F6BC
// End Line: 781

/* begin block 1.4.3.1.2 */
// Start line: 781
// Start offset: 0x8001F768
// Variables:
// 		struct _SVector *point; // $t0
// 		struct _SVector *start; // $a3
// 		struct _SVector *line; // $a2

/* begin block 1.4.3.1.2.1 */
// Start line: 781
// Start offset: 0x8001F768
// Variables:
// 		long len; // $v1
// 		long t; // $a1
/* end block 1.4.3.1.2.1 */
// End offset: 0x8001F7A0
// End Line: 781
/* end block 1.4.3.1.2 */
// End offset: 0x8001F7A0
// End Line: 781

/* begin block 1.4.3.1.3 */
// Start line: 950
// Start offset: 0x8001F8CC
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a1
// 		short _x1; // $a0
// 		short _y1; // $a3
// 		short _z1; // $a2
// 		struct _Position *_v1; // $a2
/* end block 1.4.3.1.3 */
// End offset: 0x8001F8CC
// End Line: 950

/* begin block 1.4.3.1.4 */
// Start line: 1015
// Start offset: 0x8001F970
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a1
// 		short _x1; // $a0
// 		short _y1; // $a2
// 		short _z1; // $a3
// 		struct _SVector *_v; // $fp
/* end block 1.4.3.1.4 */
// End offset: 0x8001F970
// End Line: 1015
/* end block 1.4.3.1 */
// End offset: 0x8001F9F4
// End Line: 1036
/* end block 1.4.3 */
// End offset: 0x8001FA34
// End Line: 1049

/* begin block 1.4.4 */
// Start line: 1053
// Start offset: 0x8001FA34
// Variables:
// 		int plane_front_error; // $v1
// 		int plane_back_error; // $a0
/* end block 1.4.4 */
// End offset: 0x8001FB84
// End Line: 1120

/* begin block 1.4.5 */
// Start line: 1124
// Start offset: 0x8001FB94
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a0
// 		short _x1; // $a1
// 		short _y1; // $a2
// 		short _z1; // $t0
// 		struct _Position *_v1; // $a3
/* end block 1.4.5 */
// End offset: 0x8001FB94
// End Line: 1124

/* begin block 1.4.6 */
// Start line: 1124
// Start offset: 0x8001FB94
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a0
// 		short _x1; // $a1
// 		short _y1; // $a2
// 		short _z1; // $a3
/* end block 1.4.6 */
// End offset: 0x8001FBF8
// End Line: 1125
/* end block 1.4 */
// End offset: 0x8001FBF8
// End Line: 1126

/* begin block 1.5 */
// Start line: 1127
// Start offset: 0x8001FC10
// Variables:
// 		short _x1; // $v1
// 		short _y1; // $a0
// 		short _z1; // $v0
// 		struct _SVector *_v1; // $v0
/* end block 1.5 */
// End offset: 0x8001FC10
// End Line: 1127
/* end block 1 */
// End offset: 0x8001FC10
// End Line: 1127

/* begin block 2 */
// Start line: 1540
/* end block 2 */
// End Line: 1541

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

_TFace *COLLIDE_PointAndTerrainFunc(_Terrain *terrain, _PCollideInfo *pCollideInfo, int Flags, short *Backface_Flag,
                                    long ignoreAttr, long acceptAttr, _LCollideInfo *lcolinfo)

{
  char cVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  undefined4 in_zero;
  undefined4 in_at;
  BSPTree *pBVar5;
  _BSPNode *p_Var6;
  int iVar7;
  _Normal *p_Var8;
  ushort uVar9;
  SVECTOR *pSVar10;
  _TVertex *v0;
  int iVar11;
  SVECTOR *pSVar12;
  _BSPNode *p_Var13;
  _BSPNode *p_Var14;
  byte *pbVar15;
  _TFace *tface;
  _Instance *p_Var16;
  int local_30;

  pSVar12 = pCollideInfo->newPoint;
  pSVar10 = pCollideInfo->oldPoint;
  p_Var16 = pCollideInfo->instance;
  DAT_1f800090 = 0;
  DAT_1f80006c = ignoreAttr;
  DAT_1f800070 = acceptAttr;
  DAT_1f800098 = terrain->normalList;
  DAT_1f80009c = terrain->vertexList;
  DAT_1f8000a0 = (_TFace *)0x0;
  _DAT_1f800078 = *(undefined4 *)pSVar12;
  _DAT_1f80007c = _DAT_1f80007c & 0xffff0000 | (uint)(ushort)pSVar12->vz;
  DAT_1f800080 = pSVar10->vx;
  DAT_1f800082 = pSVar10->vy;
  DAT_1f800084 = pSVar10->vz;
  DAT_1f8000a4 = DAT_1f800080 - pSVar12->vx;
  DAT_1f8000a6 = DAT_1f800082 - pSVar12->vy;
  DAT_1f8000a8 = DAT_1f800084 - pSVar12->vz;
  p_Var14 = (_BSPNode *)&DAT_1f8000ac;
  if (DAT_800d0fb4 == 1000)
  {
    DAT_1f800094 = (int)DAT_800d0fb6;
    if (DAT_1f800094 != 1)
    {
      DAT_1f800094 = 0;
    }
  }
  else
  {
    DAT_1f800094 = 2;
    DAT_1f800090 = 0x800;
  }
  DAT_1f800074 = Backface_Flag;
  DAT_1f800088 = Flags;
  if (Backface_Flag != (short *)0x0)
  {
    *Backface_Flag = 0;
  }
  local_30 = 0;
  if (0 < terrain->numBSPTrees)
  {
    do
    {
      pBVar5 = terrain->BSPTreeArray;
      *(_BSPNode **)&(p_Var14->sphere).position = p_Var14;
      pBVar5 = pBVar5 + local_30;
      if ((-1 < pBVar5->ID) &&
          (((uVar9 = pBVar5->flags, (uVar9 & 2) == 0 || ((pCollideInfo->collideType & 0x80U) != 0)) || (((uVar9 & 0x40) != 0 && ((pCollideInfo->collideType & 0x100U) != 0))))))
      {
        cVar1 = aadMem._2_1_;
        if ((uVar9 & 0x4100) == 0x4100)
        {
        code_r0x8001f2e0:
          if (cVar1 != '\0')
          {
          LAB_8001f2e8:
            if ((((pBVar5->flags & 0x1000U) == 0) || ((DAT_1f80006c & 0x10) == 0)) &&
                (((pBVar5->flags & 0x2000U) == 0 || (ULONG_800d1218._2_1_ != '\0'))))
            {
              DAT_1f800078 = DAT_1f800078 - (pBVar5->globalOffset).x;
              DAT_1f80007a = DAT_1f80007a - (pBVar5->globalOffset).y;
              uVar9 = DAT_1f80007c - (pBVar5->globalOffset).z;
              _DAT_1f80007c = _DAT_1f80007c & 0xffff0000 | (uint)uVar9;
              DAT_1f800080 = DAT_1f800080 - (pBVar5->globalOffset).x;
              DAT_1f800082 = DAT_1f800082 - (pBVar5->globalOffset).y;
              DAT_1f800084 = DAT_1f800084 - (pBVar5->globalOffset).z;
              _DAT_1f800030 = CONCAT22(DAT_1f80007a, DAT_1f800078);
              _DAT_1f800034 = CONCAT22(DAT_1f800080, uVar9);
              _DAT_1f800038 = CONCAT22(DAT_1f800084, DAT_1f800082);
              setCopControlWord(2, 0, _DAT_1f800030);
              setCopControlWord(2, 0x800, _DAT_1f800034);
              setCopControlWord(2, 0x1000, _DAT_1f800038);
              setCopControlWord(2, 0x1800, DAT_1f80003c);
              setCopControlWord(2, 0x2000, DAT_1f800040);
              p_Var6 = pBVar5->bspRoot;
              p_Var14 = (_BSPNode *)&(p_Var14->sphere).position.z;
              *(_BSPNode **)&(p_Var14->sphere).position = p_Var6;
              p_Var13 = p_Var14;
              if (p_Var6 != p_Var14)
              {
                do
                {
                  iVar11 = *(int *)&(p_Var13->sphere).position;
                  p_Var14 = (_BSPNode *)&p_Var13[-1].front_material_error;
                  if ((*(ushort *)(iVar11 + 0xe) & 2) == 0)
                  {
                    setCopReg(2, in_zero, *(undefined4 *)(iVar11 + 8));
                    setCopReg(2, in_at, *(undefined4 *)(iVar11 + 0xc));
                    copFunction(2, 0x486012);
                    DAT_1f800058 = getCopReg(2, 0x19);
                    DAT_1f80005c = getCopReg(2, 0x1a);
                    DAT_1f800060 = getCopReg(2, 0x1b);
                    DAT_1f800058 = DAT_1f800058 - *(int *)(iVar11 + 0x10);
                    DAT_1f80005c = DAT_1f80005c - *(int *)(iVar11 + 0x10);
                    if (DAT_1f800094 == 0)
                    {
                      sVar2 = *(short *)(iVar11 + 0x28);
                      sVar3 = *(short *)(iVar11 + 0x2a);
                    }
                    else
                    {
                      sVar2 = *(short *)(iVar11 + 0x24);
                      sVar3 = *(short *)(iVar11 + 0x26);
                    }
                    if (DAT_1f80005c < (int)sVar2 + 5)
                    {
                      if ((int)sVar3 + -5 < DAT_1f80005c)
                      {
                        if (DAT_1f800058 < DAT_1f80005c)
                          goto LAB_8001fb54;
                        if (*(int *)(iVar11 + 0x14) != 0)
                        {
                          *(int *)&(p_Var13->sphere).position = *(int *)(iVar11 + 0x14);
                          p_Var14 = p_Var13;
                        }
                        iVar11 = *(int *)(iVar11 + 0x18);
                      }
                      else
                      {
                        if (((int)sVar3 + -5 <= DAT_1f800058) && (*(int *)(iVar11 + 0x14) != 0))
                        {
                          *(int *)&(p_Var13->sphere).position = *(int *)(iVar11 + 0x14);
                          p_Var14 = p_Var13;
                        }
                        iVar11 = *(int *)(iVar11 + 0x18);
                      }
                    }
                    else
                    {
                      if (DAT_1f800058 <= (int)sVar2 + 5)
                      {
                      LAB_8001fb54:
                        if (*(int *)(iVar11 + 0x18) != 0)
                        {
                          *(int *)&(p_Var13->sphere).position = *(int *)(iVar11 + 0x18);
                          p_Var14 = p_Var13;
                        }
                      }
                      iVar11 = *(int *)(iVar11 + 0x14);
                    }
                    if (iVar11 != 0)
                    {
                      p_Var14 = (_BSPNode *)&(p_Var14->sphere).position.z;
                      *(int *)&(p_Var14->sphere).position = iVar11;
                    }
                  }
                  else
                  {
                    iVar7 = *(short *)(iVar11 + 0x16) + DAT_1f800090;
                    if (((DAT_1f800030 <= iVar7) || (DAT_1f800036 <= iVar7)) &&
                        ((iVar7 = *(short *)(iVar11 + 0x10) - DAT_1f800090, iVar7 <= DAT_1f800030 ||
                                                                                (iVar7 <= DAT_1f800036))))
                    {
                      iVar7 = *(short *)(iVar11 + 0x18) + DAT_1f800090;
                      if (((DAT_1f800032 <= iVar7) || (DAT_1f800038 <= iVar7)) &&
                          ((iVar7 = *(short *)(iVar11 + 0x12) - DAT_1f800090, iVar7 <= DAT_1f800032 || (iVar7 <= DAT_1f800038))))
                      {
                        iVar7 = *(short *)(iVar11 + 0x1a) + DAT_1f800090;
                        if (((DAT_1f800034 <= iVar7) || (DAT_1f80003a <= iVar7)) &&
                            ((iVar7 = *(short *)(iVar11 + 0x14) - DAT_1f800090, iVar7 <= DAT_1f800034 || (iVar7 <= DAT_1f80003a))))
                        {
                          DAT_1f80008c = (int)*(short *)(iVar11 + 0xc);
                          tface = *(_TFace **)(iVar11 + 8);
                          if (DAT_1f80008c != 0)
                          {
                            pbVar15 = &tface->attr;
                            do
                            {
                              if (((*pbVar15 & DAT_1f80006c) == 0) ||
                                  ((*pbVar15 & DAT_1f800070) != 0))
                              {
                                if ((DAT_1f800094 == 2) &&
                                    ((uint) * (ushort *)(pbVar15 + 2) !=
                                     (int)terrain->morphNormalIdx
                                         [(int)((int)tface - (int)terrain->faceList) * -0x55555555 >> 2]))
                                {
                                  COLLIDE_MakeNormal(terrain, tface, (_SVector *)&DAT_1f800050);
                                }
                                else
                                {
                                  iVar11 = (int)*(short *)(pbVar15 + 2);
                                  if (iVar11 < 0)
                                  {
                                    p_Var8 = (_Normal *)((int)DAT_1f800098 + iVar11 * -6);
                                    DAT_1f800050 = CONCAT22(-p_Var8->y, -(p_Var8->x & 0x1fffU));
                                    DAT_1f800054 = DAT_1f800054 & 0xffff0000 |
                                                   (uint)(ushort)-p_Var8->z;
                                  }
                                  else
                                  {
                                    DAT_1f800050 = *(uint *)(&DAT_1f800098->x + iVar11 * 3) &
                                                   0xffff1fff;
                                    DAT_1f800054 = DAT_1f800054 & 0xffff0000 |
                                                   (uint)(ushort)(&DAT_1f800098->x + iVar11 * 3)[1];
                                  }
                                }
                                v0 = DAT_1f80009c + (tface->face).v0;
                                setCopControlWord(2, 0x1800, *(undefined4 *)&v0->vertex);
                                setCopControlWord(2, 0x2000, *(undefined4 *)&(v0->vertex).z);
                                setCopReg(2, in_zero, DAT_1f800050);
                                setCopReg(2, in_at, DAT_1f800054);
                                copFunction(2, 0x486012);
                                DAT_1f800058 = getCopReg(2, 0x19);
                                DAT_1f80005c = getCopReg(2, 0x1a);
                                DAT_1f800060 = getCopReg(2, 0x1b);
                                DAT_1f800058 = DAT_1f800058 - DAT_1f800060;
                                DAT_1f80005c = DAT_1f80005c - DAT_1f800060;
                                if (((DAT_1f800058 < 0) && (-1 < DAT_1f80005c)) ||
                                    (((DAT_1f800088 & 1) != 0 &&
                                      ((0 < DAT_1f800058 && (DAT_1f80005c < 1))))))
                                {
                                  if (DAT_1f800058 - DAT_1f80005c == 0)
                                  {
                                    iVar11 = 0;
                                  }
                                  else
                                  {
                                    iVar11 = (DAT_1f80005c * 0x1000) / (DAT_1f800058 - DAT_1f80005c);
                                  }
                                  _DAT_1f800064 =
                                      CONCAT22(DAT_1f800082 + (short)(DAT_1f8000a6 * iVar11 >> 0xc), DAT_1f800080 +
                                                                                                         (short)(DAT_1f8000a4 * iVar11 >> 0xc));
                                  _DAT_1f800068 =
                                      _DAT_1f800068 & 0xffff0000 |
                                      (uint)(ushort)(DAT_1f800084 +
                                                     (short)(DAT_1f8000a8 * iVar11 >> 0xc));
                                  iVar11 = COLLIDE_PointInTriangle((_SVector *)v0,
                                                                   (_SVector *)(DAT_1f80009c + *(ushort *)(pbVar15 + -4)),
                                                                   (_SVector *)(DAT_1f80009c + *(ushort *)(pbVar15 + -2)),
                                                                   (_SVector *)&DAT_1f800064,
                                                                   (_SVector *)&DAT_1f800050);
                                  if (iVar11 != 0)
                                  {
                                    if ((((DAT_1f800074 != (short *)0x0) &&
                                          ((DAT_1f800088 & 1) != 0)) &&
                                         (0 < DAT_1f800058)) &&
                                        (DAT_1f80005c < 1))
                                    {
                                      *DAT_1f800074 = 1;
                                    }
                                    if ((*pbVar15 & 8) == 0)
                                    {
                                      if (((*(ushort *)(pbVar15 + 4) == 0xffff) ||
                                           ((*(ushort *)((int)&terrain->StartTextureList->attr +
                                                         (uint) * (ushort *)(pbVar15 + 4)) &
                                             0x2000) == 0)) ||
                                          ((*pbVar15 & DAT_1f800070) != 0))
                                      {
                                        _DAT_1f80007c = _DAT_1f800068;
                                        DAT_1f80007c = (short)_DAT_1f800068;
                                        _DAT_1f800078 = _DAT_1f800064;
                                        _DAT_1f800030 = _DAT_1f800064;
                                        DAT_1f800078 = (short)_DAT_1f800064;
                                        _DAT_1f800034 =
                                            _DAT_1f800034 & 0xffff0000 | _DAT_1f800068 & 0xffff;
                                        DAT_1f80007a = (short)((uint)_DAT_1f800064 >> 0x10);
                                        DAT_1f8000a4 = DAT_1f800080 - DAT_1f800078;
                                        DAT_1f8000a6 = DAT_1f800082 - DAT_1f80007a;
                                        DAT_1f8000a8 = DAT_1f800084 - DAT_1f80007c;
                                        DAT_1f8000a0 = tface;
                                        if (lcolinfo != (_LCollideInfo *)0x0)
                                        {
                                          lcolinfo->tface = tface;
                                          lcolinfo->terrain = terrain;
                                          lcolinfo->curTree = local_30;
                                        }
                                      }
                                    }
                                    else
                                    {
                                      if ((DAT_800d10ec & 0x8000) != 0)
                                      {
                                        p_Var16->waterFace = tface;
                                        p_Var16->waterFaceTerrain = terrain;
                                        uVar4 = _DAT_1f800068;
                                        *(undefined4 *)&p_Var16->splitPoint = _DAT_1f800064;
                                        *(uint *)&(p_Var16->splitPoint).z = uVar4;
                                        sVar2 = (pBVar5->globalOffset).y;
                                        sVar3 = (pBVar5->globalOffset).z;
                                        (p_Var16->splitPoint).x =
                                            (p_Var16->splitPoint).x + (pBVar5->globalOffset).x;
                                        (p_Var16->splitPoint).y = (p_Var16->splitPoint).y + sVar2;
                                        (p_Var16->splitPoint).z = (p_Var16->splitPoint).z + sVar3;
                                      }
                                    }
                                    setCopControlWord(2, 0, _DAT_1f800030);
                                    setCopControlWord(2, 0x800, _DAT_1f800034);
                                  }
                                }
                              }
                              pbVar15 = pbVar15 + 0xc;
                              tface = tface + 1;
                              DAT_1f80008c = DAT_1f80008c + -1;
                            } while (DAT_1f80008c != 0);
                          }
                          if ((DAT_1f8000a0 != (_TFace *)0x0) && (DAT_1f800094 == 0))
                          {
                            *(_BSPNode **)&(p_Var14->sphere).position = p_Var14;
                          }
                        }
                      }
                    }
                  }
                  p_Var13 = p_Var14;
                } while (*(_BSPNode **)&(p_Var14->sphere).position != p_Var14);
              }
              _DAT_1f800078 =
                  CONCAT22(DAT_1f80007a + (pBVar5->globalOffset).y,
                           DAT_1f800078 + (pBVar5->globalOffset).x);
              _DAT_1f80007c =
                  _DAT_1f80007c & 0xffff0000 |
                  (uint)(ushort)(DAT_1f80007c + (pBVar5->globalOffset).z);
              DAT_1f800080 = DAT_1f800080 + (pBVar5->globalOffset).x;
              DAT_1f800082 = DAT_1f800082 + (pBVar5->globalOffset).y;
              DAT_1f800084 = DAT_1f800084 + (pBVar5->globalOffset).z;
            }
          }
        }
        else
        {
          if (((uVar9 & 0x100) == 0) || (DAT_800d11c4 != '\0'))
          {
            cVar1 = DAT_800d11c5;
            if ((uVar9 & 0x4000) != 0)
              goto code_r0x8001f2e0;
            goto LAB_8001f2e8;
          }
        }
      }
      local_30 = local_30 + 1;
    } while (local_30 < terrain->numBSPTrees);
  }
  pSVar12->vx = DAT_1f800078;
  pSVar12->vy = DAT_1f80007a;
  pSVar12->vz = DAT_1f80007c;
  return DAT_1f8000a0;
}

// decompiled code
// original method signature:
// int /*$ra*/ COLLIDE_PointAndHFace(struct _SVector *newPos /*$s4*/, struct _SVector *oldPos /*$s6*/, struct _HFace *hface /*$s5*/, struct _Model *model /*$s7*/, struct _SVector *hfNormal /*stack 16*/)
// line 1330, offset 0x8001fc64
/* begin block 1 */
// Start line: 1331
// Start offset: 0x8001FC64
// Variables:
// 		struct MATRIX *posMatrix; // $s1
// 		struct _SVector *normal; // $s3
// 		struct _Vector *dpv; // $s2
// 		struct _SVector *planePoint; // stack offset -48
// 		struct _SVector *vertex0; // $s0
// 		struct _SVector *vertex1; // $s1

/* begin block 1.1 */
// Start line: 1341
// Start offset: 0x8001FCD0
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a1
// 		short _x1; // $a2
// 		short _y1; // $a3
// 		short _z1; // $t0
/* end block 1.1 */
// End offset: 0x8001FCD0
// End Line: 1341

/* begin block 1.2 */
// Start line: 1341
// Start offset: 0x8001FCD0
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a1
// 		short _x1; // $a2
// 		short _y1; // $a3
// 		short _z1; // $t0
// 		struct _SVector *_v; // $t1
/* end block 1.2 */
// End offset: 0x8001FCD0
// End Line: 1341

/* begin block 1.3 */
// Start line: 1341
// Start offset: 0x8001FCD0
// Variables:
// 		short _x1; // $v0
// 		short _y1; // $v1
// 		short _z1; // $a1
// 		struct _SVector *_v0; // $t3
/* end block 1.3 */
// End offset: 0x8001FCD0
// End Line: 1341
/* end block 1 */
// End offset: 0x8001FE7C
// End Line: 1378

/* begin block 2 */
// Start line: 3219
/* end block 2 */
// End Line: 3220

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
COLLIDE_PointAndHFace(undefined4 *param_1, short *param_2, short *param_3, int param_4, undefined2 *param_5)

{
  short sVar1;
  undefined4 in_zero;
  undefined4 in_at;
  undefined4 uVar2;
  int iVar3;
  _SVector *v0;

  COLLIDE_GetNormal(param_3[4], *(short **)(param_4 + 0xc), (_SVector *)&DAT_1f800074);
  iVar3 = *(int *)(param_4 + 4);
  sVar1 = param_3[1];
  v0 = (_SVector *)(iVar3 + (int)*param_3 * 8);
  DAT_1f800040._0_2_ = *(short *)param_1 - v0->x;
  DAT_1f800040._2_2_ = *(short *)((int)param_1 + 2) - v0->y;
  DAT_1f800044 = *(short *)(param_1 + 1) - v0->z;
  DAT_1f800046 = *param_2 - v0->x;
  DAT_1f800048 = param_2[1] - v0->y;
  DAT_1f80004a = param_2[2] - v0->z;
  DAT_1f80004c = v0->x;
  DAT_1f80004e = v0->y;
  DAT_1f800050._0_2_ = v0->z;
  SetRotMatrix(&DAT_1f800040);
  setCopReg(2, in_zero, DAT_1f800074);
  setCopReg(2, in_at, _DAT_1f800078);
  copFunction(2, 0x486012);
  _DAT_1f800080 = getCopReg(2, 0x19);
  _DAT_1f800084 = getCopReg(2, 0x1a);
  DAT_1f800088 = getCopReg(2, 0x1b);
  if (_DAT_1f800080 < 0)
  {
    uVar2 = 0;
    if ((_DAT_1f800080 < _DAT_1f800084) && (-1 < _DAT_1f800084))
    {
      COLLIDE_IntersectLineAndPlane_S(&DAT_1f800090, param_2, param_1, &DAT_1f800074, DAT_1f800088);
      iVar3 = COLLIDE_PointInTriangle(v0, (_SVector *)(iVar3 + (int)sVar1 * 8),
                                      (_SVector *)(*(int *)(param_4 + 4) + (int)param_3[2] * 8),
                                      (_SVector *)&DAT_1f800090, (_SVector *)&DAT_1f800074);
      uVar2 = 0;
      if (iVar3 != 0)
      {
        *param_1 = DAT_1f800090;
        param_1[1] = DAT_1f800094;
        *param_5 = (undefined2)DAT_1f800074;
        param_5[1] = DAT_1f800074._2_2_;
        uVar2 = 1;
        param_5[2] = DAT_1f800078;
      }
    }
  }
  else
  {
    uVar2 = 0;
  }
  return uVar2;
}

// decompiled code
// original method signature:
// void /*$ra*/ COLLIDE_PointAndInstance(struct _PCollideInfo *pcollideInfo /*$s4*/, struct _Instance *instance /*stack 4*/)
// line 1389, offset 0x8001feac
/* begin block 1 */
// Start line: 1390
// Start offset: 0x8001FEAC
// Variables:
// 		struct MATRIX *swTransform; // stack offset -92
// 		struct MATRIX *wsTransform; // stack offset -88
// 		struct MATRIX *swNormMat; // $fp
// 		struct _Vector *oldPosVec; // stack offset -84
// 		struct _Vector *lNormal; // stack offset -80
// 		struct _Vector *wNormal; // stack offset -76
// 		struct _Vector *dv; // $s2
// 		struct _Vector *newPosVec; // $s5
// 		struct _SVector *oldPos; // stack offset -72
// 		struct _SVector *newPos; // $s3
// 		struct _SVector *point; // stack offset -68
// 		long *flag; // stack offset -64
// 		struct _Model *model; // stack offset -60
// 		struct _HModel *hmodel; // $v0
// 		struct _HPrim *hprim; // stack offset -56
// 		int i; // stack offset -52
// 		long collideType; // stack offset -48

/* begin block 1.1 */
// Start line: 1416
// Start offset: 0x8001FFCC
// Variables:
// 		struct _HBox *hbox; // $s0
// 		struct _HFace *hface; // $s1
// 		struct _HSphere *hsphere; // $s0

/* begin block 1.1.1 */
// Start line: 1419
// Start offset: 0x8001FFCC
// TypeDefs:
// 		struct COLLIDE_258fake tmm
/* end block 1.1.1 */
// End offset: 0x8001FFCC
// End Line: 1419

/* begin block 1.1.2 */
// Start line: 1452
// Start offset: 0x80020184
// Variables:
// 		long len; // $t0

/* begin block 1.1.2.1 */
// Start line: 1453
// Start offset: 0x80020184
// Variables:
// 		long a; // stack offset -104
// 		long b; // stack offset -100
// 		long c; // stack offset -96
/* end block 1.1.2.1 */
// End offset: 0x80020184
// End Line: 1453
/* end block 1.1.2 */
// End offset: 0x80020248
// End Line: 1459

/* begin block 1.1.3 */
// Start line: 1488
// Start offset: 0x800203F0
// Variables:
// 		struct _SVector hfNormal; // stack offset -136
/* end block 1.1.3 */
// End offset: 0x80020418
// End Line: 1494

/* begin block 1.1.4 */
// Start line: 1509
// Start offset: 0x80020450
// Variables:
// 		struct _SVector hbNormal; // stack offset -136
// 		struct _SVector point0; // stack offset -128
// 		struct _SVector point1; // stack offset -120
// 		struct _SVector normal1; // stack offset -112

/* begin block 1.1.4.1 */
// Start line: 1551
// Start offset: 0x80020590
// Variables:
// 		short _x1; // $v0
// 		short _y1; // $v1
// 		short _z1; // $a3
/* end block 1.1.4.1 */
// End offset: 0x80020590
// End Line: 1551
/* end block 1.1.4 */
// End offset: 0x800205D8
// End Line: 1561
/* end block 1.1 */
// End offset: 0x80020690
// End Line: 1580
/* end block 1 */
// End offset: 0x800206B0
// End Line: 1582

/* begin block 2 */
// Start line: 3368
/* end block 2 */
// End Line: 3369

void COLLIDE_PointAndInstance(_PCollideInfo *pcollideInfo, _Instance *instance)

{
  byte *pbVar1;
  undefined local_80[36];
  MATRIX *local_5c;
  undefined4 *local_58;
  undefined2 *local_54;
  undefined4 *local_50;
  undefined4 *local_4c;
  undefined2 *local_48;
  undefined2 *local_44;
  undefined2 *local_40;
  _Model *local_3c;
  _HPrim *local_38;
  int local_34;
  long local_30;
  undefined *local_2c;

  local_58 = &DAT_1f8000a0;
  local_54 = &DAT_1f800130;
  local_50 = &DAT_1f800150;
  local_4c = &DAT_1f800160;
  local_48 = &DAT_1f8001a0;
  local_44 = &DAT_1f8001b0;
  local_40 = &DAT_1f8001c0;
  local_34 = instance->hModelList[instance->currentModel].numHPrims;
  local_38 = instance->hModelList[instance->currentModel].hPrimList;
  local_30 = pcollideInfo->collideType;
  local_3c = instance->object->modelList[instance->currentModel];
  if (local_34 != 0)
  {
    local_2c = local_80;
    pbVar1 = &local_38->segment;
    do
    {
      if (((local_38->hpFlags & 1) != 0) && ((local_38->hpFlags & 8) != 0))
      {
        local_5c = instance->matrix + *pbVar1;
        PIPE3D_InvertTransform((MATRIX *)&DAT_1f8000a0, local_5c);
        DAT_1f800114 = local_5c->t[0];
        DAT_1f800118 = local_5c->t[1];
        DAT_1f80011c = local_5c->t[2];
        /* WARNING: Subroutine does not return */
        TransposeMatrix(local_58, (undefined4 *)&DAT_1f800100);
      }
      pbVar1 = pbVar1 + 8;
      local_34 = local_34 + -1;
      local_38 = local_38 + 1;
    } while (local_34 != 0);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ COLLIDE_PointAndInstanceTrivialReject(struct _PCollideInfo *pcollideInfo /*$s3*/, struct _Instance *instance /*$s1*/)
// line 1584, offset 0x800206e0
/* begin block 1 */
// Start line: 1585
// Start offset: 0x800206E0
// Variables:
// 		struct _Vector *dv; // $s2
// 		struct _SVector linePoint; // stack offset -32

/* begin block 1.1 */
// Start line: 1596
// Start offset: 0x80020768
// Variables:
// 		long _x0; // $a2
// 		long _y0; // $v1
// 		long _z0; // $v0
// 		long _x1; // $v0
// 		long _y1; // $v0
// 		long _z1; // $a0
// 		struct _SVector *_v0; // $a0
/* end block 1.1 */
// End offset: 0x80020768
// End Line: 1596
/* end block 1 */
// End offset: 0x80020848
// End Line: 1633

/* begin block 2 */
// Start line: 4060
/* end block 2 */
// End Line: 4061

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void COLLIDE_PointAndInstanceTrivialReject(_PCollideInfo *pcollideInfo, _Instance *instance)

{
  long lVar1;
  short local_20;
  short local_1e;
  short local_1c;

  lVar1 = MEMPACK_MemoryValidFunc((char *)instance->object);
  if ((((lVar1 != 0) && ((instance->flags & 0x40U) == 0)) &&
       (instance->hModelList != (_HModel *)0x0)) &&
      (((pcollideInfo->collideType & 0x40U) == 0 || ((instance->object->oflags2 & 0x40U) == 0))))
  {
    COLLIDE_NearestPointOnLine_S((uint *)&local_20, (uint *)pcollideInfo->oldPoint, (uint *)pcollideInfo->newPoint,
                                 (uint *)&instance->position);
    _DAT_1f800000 = (int)local_20 - (int)(instance->position).x >> 1;
    _DAT_1f800004 = (int)local_1e - (int)(instance->position).y >> 1;
    _DAT_1f800008 = (int)local_1c - (int)(instance->position).z >> 1;
    if ((_DAT_1f800000 * _DAT_1f800000 + _DAT_1f800004 * _DAT_1f800004 +
             _DAT_1f800008 * _DAT_1f800008<
                                 instance->object->modelList[instance->currentModel]->maxRadSq>>
         2) &&
        (instance->matrix != (MATRIX *)0x0))
    {
      COLLIDE_PointAndInstance(pcollideInfo, instance);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ COLLIDE_PointAndWorld(struct _PCollideInfo *pcollideInfo /*$s5*/, struct Level *level /*$s6*/)
// line 1648, offset 0x80020864
/* begin block 1 */
// Start line: 1649
// Start offset: 0x80020864
// Variables:
// 		struct _Instance *instance; // $s0
// 		struct _InstanceList *instanceList; // $s3
// 		struct _LCollideInfo lcol; // stack offset -56
// 		int i; // $s1
// 		int in_warpRoom; // $s7

/* begin block 1.1 */
// Start line: 1660
// Start offset: 0x800208A8
// Variables:
// 		struct _TFace *tface; // $s3
// 		struct _Terrain *terrain; // $s4

/* begin block 1.1.1 */
// Start line: 1690
// Start offset: 0x80020944
/* end block 1.1.1 */
// End offset: 0x80020968
// End Line: 1694

/* begin block 1.1.2 */
// Start line: 1699
// Start offset: 0x80020970

/* begin block 1.1.2.1 */
// Start line: 1704
// Start offset: 0x80020974
// Variables:
// 		struct Level *thislevel; // $s0
/* end block 1.1.2.1 */
// End offset: 0x80020A18
// End Line: 1728
/* end block 1.1.2 */
// End offset: 0x80020A48
// End Line: 1739
/* end block 1.1 */
// End offset: 0x80020A48
// End Line: 1740
/* end block 1 */
// End offset: 0x80020C20
// End Line: 1813

/* begin block 2 */
// Start line: 4207
/* end block 2 */
// End Line: 4208

void COLLIDE_PointAndWorld(_PCollideInfo *pcollideInfo, Level *level)

{
  bool bVar1;
  long lVar2;
  _StreamUnit *p_Var3;
  uint uVar4;
  _Instance *instance;
  int iVar5;
  int iVar6;
  ushort *puVar7;
  long *plVar8;
  _TFace *tface;
  _Terrain *terrain;
  undefined auStack56[8];
  short local_30;

  bVar1 = false;
  pcollideInfo->type = 0;
  if ((pcollideInfo->collideType & 1U) != 0)
  {
    tface = (_TFace *)0x0;
    if ((level != (Level *)0x0) && (lVar2 = MEMPACK_MemoryValidFunc((char *)level), lVar2 != 0))
    {
      terrain = level->terrain;
      tface = COLLIDE_PointAndTerrain(terrain, pcollideInfo, (_LCollideInfo *)auStack56);
      if (tface == (_TFace *)0x0)
      {
        p_Var3 = STREAM_GetStreamUnitWithID(level->streamUnitID);
        if ((p_Var3->flags & 1U) != 0)
        {
          bVar1 = true;
        }
      }
      else
      {
        pcollideInfo->type = 3;
        *(_TFace **)&pcollideInfo->prim = tface;
        *(Level **)&pcollideInfo->inst = level;
        pcollideInfo->segment = local_30;
        if (DAT_800d0fb4 == 1000)
        {
          COLLIDE_GetNormal(tface->normal, (short *)terrain->normalList,
                            (_SVector *)&pcollideInfo->wNormal);
        }
        else
        {
          COLLIDE_MakeNormal(terrain, tface, (_SVector *)&pcollideInfo->wNormal);
        }
      }
    }
    iVar5 = 0;
    if (tface == (_TFace *)0x0)
    {
      puVar7 = &DAT_800d1926;
      do
      {
        instance = *(_Instance **)(puVar7 + 1);
        if ((((puVar7[-1] == 2) && (instance != (_Instance *)level)) &&
             ((!bVar1 || ((*puVar7 & 1) == 0)))) &&
            (lVar2 = MEMPACK_MemoryValidFunc((char *)instance), lVar2 != 0))
        {
          terrain = (_Terrain *)(instance->node).prev;
          tface = COLLIDE_PointAndTerrain(terrain, pcollideInfo, (_LCollideInfo *)auStack56);
          if (tface != (_TFace *)0x0)
          {
            pcollideInfo->type = 3;
            *(_TFace **)&pcollideInfo->prim = tface;
            pcollideInfo->inst = instance;
            pcollideInfo->segment = local_30;
            if (DAT_800d0fb4 == 1000)
            {
              COLLIDE_GetNormal(tface->normal, (short *)terrain->normalList,
                                (_SVector *)&pcollideInfo->wNormal);
            }
            else
            {
              COLLIDE_MakeNormal(terrain, tface, (_SVector *)&pcollideInfo->wNormal);
            }
            break;
          }
        }
        iVar5 = iVar5 + 1;
        puVar7 = puVar7 + 0x20;
      } while (iVar5 < 0x10);
      if (tface == (_TFace *)0x0)
      {
        pcollideInfo->type = 0;
        pcollideInfo->prim = (void *)0x0;
        pcollideInfo->inst = (_Instance *)0x0;
        (pcollideInfo->wNormal).vx = 0;
        (pcollideInfo->wNormal).vy = 0;
        (pcollideInfo->wNormal).vz = 0;
      }
    }
  }
  iVar5 = DAT_800d0fe0;
  uVar4 = pcollideInfo->collideType;
  iVar6 = 0x10;
  if ((uVar4 & 8) == 0)
  {
    if ((uVar4 & 0x10) == 0)
    {
      iVar6 = 0;
      if ((uVar4 & 4) != 0)
      {
        plVar8 = &dyna_cldstat;
        do
        {
          instance = *(_Instance **)(*plVar8 * 8 + iVar5 + 0x10);
          while (instance != (_Instance *)0x0)
          {
            if ((instance->flags2 & 0x24000000U) == 0)
            {
              COLLIDE_PointAndInstanceTrivialReject(pcollideInfo, instance);
            }
            instance = (_Instance *)(instance->node).next;
          }
          iVar6 = iVar6 + 1;
          plVar8 = plVar8 + 1;
        } while (iVar6 < 8);
      }
    }
    else
    {
      iVar6 = 0;
      if ((uVar4 & 2) != 0)
      {
        plVar8 = &stat_clddyna;
        do
        {
          instance = *(_Instance **)(*plVar8 * 8 + iVar5 + 0x10);
          while (instance != (_Instance *)0x0)
          {
            if ((instance->flags2 & 0x24000000U) == 0)
            {
              COLLIDE_PointAndInstanceTrivialReject(pcollideInfo, instance);
            }
            instance = (_Instance *)(instance->node).next;
          }
          iVar6 = iVar6 + 1;
          plVar8 = plVar8 + 1;
        } while (iVar6 < 8);
      }
      iVar6 = 0;
      if ((pcollideInfo->collideType & 4U) != 0)
      {
        plVar8 = &dyna_clddyna;
        do
        {
          instance = *(_Instance **)(*plVar8 * 8 + iVar5 + 0x10);
          while (instance != (_Instance *)0x0)
          {
            if ((instance->flags2 & 0x24000000U) == 0)
            {
              COLLIDE_PointAndInstanceTrivialReject(pcollideInfo, instance);
            }
            instance = (_Instance *)(instance->node).next;
          }
          iVar6 = iVar6 + 1;
          plVar8 = plVar8 + 1;
        } while (iVar6 < 8);
      }
    }
  }
  else
  {
    iVar5 = DAT_800d0fe0 + 0x80;
    do
    {
      instance = *(_Instance **)(iVar5 + 0x10);
      while (instance != (_Instance *)0x0)
      {
        if ((instance->flags2 & 0x24000000U) == 0)
        {
          COLLIDE_PointAndInstanceTrivialReject(pcollideInfo, instance);
        }
        instance = (_Instance *)(instance->node).next;
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 8;
    } while (iVar6 < 0x20);
  }
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ COLLIDE_ClosestPointInBoxToPoint(struct _Position *boxPoint /*$a0*/, struct _HBox *hbox /*$a1*/, struct _SVector *point /*$a2*/)
// line 1893, offset 0x80020c4c
/* begin block 1 */
// Start line: 1895
// Start offset: 0x80020C4C
// Variables:
// 		long inside; // $a3
/* end block 1 */
// End offset: 0x80020D18
// End Line: 1941

/* begin block 2 */
// Start line: 4803
/* end block 2 */
// End Line: 4804

/* begin block 3 */
// Start line: 4804
/* end block 3 */
// End Line: 4805

/* begin block 4 */
// Start line: 4806
/* end block 4 */
// End Line: 4807

undefined4 COLLIDE_ClosestPointInBoxToPoint(short *param_1, int param_2, short *param_3)

{
  short sVar1;
  undefined4 uVar2;

  sVar1 = *(short *)(param_2 + 4);
  uVar2 = 1;
  if ((*param_3 < *(short *)(param_2 + 4)) ||
      (sVar1 = *(short *)(param_2 + 10), *(short *)(param_2 + 10) < *param_3))
  {
    *param_1 = sVar1;
    uVar2 = 0;
  }
  else
  {
    *param_1 = *param_3;
  }
  sVar1 = *(short *)(param_2 + 6);
  if ((param_3[1] < *(short *)(param_2 + 6)) ||
      (sVar1 = *(short *)(param_2 + 0xc), *(short *)(param_2 + 0xc) < param_3[1]))
  {
    param_1[1] = sVar1;
    uVar2 = 0;
  }
  else
  {
    param_1[1] = param_3[1];
  }
  if (param_3[2] < *(short *)(param_2 + 8))
  {
    param_1[2] = *(short *)(param_2 + 8);
    uVar2 = 0;
  }
  else
  {
    if (*(short *)(param_2 + 0xe) < param_3[2])
    {
      param_1[2] = *(short *)(param_2 + 0xe);
      uVar2 = 0;
    }
    else
    {
      param_1[2] = param_3[2];
    }
  }
  return uVar2;
}

// decompiled code
// original method signature:
// long /*$ra*/ COLLIDE_SphereAndPoint(struct _Sphere *sphere /*$s1*/, struct _SVector *point /*$s2*/, struct _SVector *normal /*$s3*/)
// line 1944, offset 0x80020d20
/* begin block 1 */
// Start line: 1945
// Start offset: 0x80020D20
// Variables:
// 		long len; // $a2
// 		struct _Vector *line; // $s0

/* begin block 1.1 */
// Start line: 1945
// Start offset: 0x80020D20
// Variables:
// 		long _x0; // $a2
// 		long _y0; // $a1
// 		long _z0; // $a0
// 		long _x1; // $v0
// 		long _y1; // $v0
// 		long _z1; // $v0
/* end block 1.1 */
// End offset: 0x80020D20
// End Line: 1945

/* begin block 1.2 */
// Start line: 1953
// Start offset: 0x80020DB4
// Variables:
// 		long a; // stack offset -40
// 		long b; // stack offset -36
// 		long c; // stack offset -32
/* end block 1.2 */
// End offset: 0x80020DB4
// End Line: 1953
/* end block 1 */
// End offset: 0x80020F48
// End Line: 1970

/* begin block 2 */
// Start line: 4905
/* end block 2 */
// End Line: 4906

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 COLLIDE_SphereAndPoint(short *param_1, short *param_2, undefined2 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_28;
  int local_24;
  int local_20[2];

  _DAT_1f800000 = (int)*param_1 - (int)*param_2;
  _DAT_1f800004 = (int)param_1[1] - (int)param_2[1];
  _DAT_1f800008 = (int)param_1[2] - (int)param_2[2];
  uVar1 = 0;
  if ((uint)(_DAT_1f800000 * _DAT_1f800000 + _DAT_1f800004 * _DAT_1f800004 +
             _DAT_1f800008 * _DAT_1f800008) < *(uint *)(param_1 + 4))
  {
    local_28 = _DAT_1f800000;
    if (_DAT_1f800000 < 0)
    {
      local_28 = -_DAT_1f800000;
    }
    local_24 = _DAT_1f800004;
    if (_DAT_1f800004 < 0)
    {
      local_24 = -_DAT_1f800004;
    }
    local_20[0] = _DAT_1f800008;
    if (_DAT_1f800008 < 0)
    {
      local_20[0] = -_DAT_1f800008;
    }
    MATH3D_Sort3VectorCoords(&local_28, &local_24, local_20);
    iVar3 = local_20[0] * 0x1e + local_24 * 0xc + local_28 * 9;
    iVar2 = iVar3 >> 5;
    uVar1 = 0;
    if (iVar2 != 0)
    {
      *param_3 = (short)((_DAT_1f800000 << 0xc) / iVar2);
      param_3[1] = (short)((_DAT_1f800004 << 0xc) / iVar2);
      param_3[2] = (short)((_DAT_1f800008 << 0xc) / iVar2);
      _DAT_1f800000 = (int)(_DAT_1f800000 * (uint)(ushort)param_1[3] * 0x20) / iVar3;
      _DAT_1f800004 = (int)(_DAT_1f800004 * (uint)(ushort)param_1[3] * 0x20) / iVar3;
      _DAT_1f800008 = (int)(_DAT_1f800008 * (uint)(ushort)param_1[3] * 0x20) / iVar3;
      *param_1 = *param_2 + DAT_1f800000;
      param_1[1] = param_2[1] + DAT_1f800004;
      uVar1 = 1;
      param_1[2] = param_2[2] + DAT_1f800008;
    }
  }
  return uVar1;
}

// decompiled code
// original method signature:
// long /*$ra*/ COLLIDE_SphereAndHBox(struct _HBox *hbox /*$s4*/, struct _Sphere *sphere /*$s1*/, struct _Position *oldPos /*$s5*/, struct _SVector *normal /*$s3*/)
// line 1975, offset 0x80020f64
/* begin block 1 */
// Start line: 1976
// Start offset: 0x80020F64
// Variables:
// 		struct _SVector point; // stack offset -96
// 		struct _SVector point0; // stack offset -88
// 		struct _SVector point1; // stack offset -80
// 		struct _SVector normal0; // stack offset -72
// 		struct _SVector normal1; // stack offset -64
// 		struct _SVector sphereNormal; // stack offset -56
// 		struct _SVector dv; // stack offset -48
// 		struct _SVector absdv; // stack offset -40

/* begin block 1.1 */
// Start line: 1989
// Start offset: 0x80020FAC
// Variables:
// 		long numIntersects; // $a2

/* begin block 1.1.1 */
// Start line: 1993
// Start offset: 0x80020FDC
// Variables:
// 		short _x1; // $v0
// 		short _y1; // $v1
// 		short _z1; // $a0
/* end block 1.1.1 */
// End offset: 0x80020FDC
// End Line: 1993

/* begin block 1.1.2 */
// Start line: 1993
// Start offset: 0x80020FDC
// Variables:
// 		short _x1; // $a0
// 		short _y1; // $v1
// 		short _z1; // $a1
// 		struct _SVector *_v0; // $v0
/* end block 1.1.2 */
// End offset: 0x80020FDC
// End Line: 1993

/* begin block 1.1.3 */
// Start line: 2000
// Start offset: 0x8002107C
// Variables:
// 		short _y0; // $v0
// 		short _z0; // $v1
// 		short _x1; // $v0
// 		short _y1; // $a2
// 		short _z1; // $a3
// 		struct _SVector *_v; // $a1
// 		struct _SVector *_v0; // $v1
/* end block 1.1.3 */
// End offset: 0x8002107C
// End Line: 2000
/* end block 1.1 */
// End offset: 0x80021290
// End Line: 2076

/* begin block 1.2 */
// Start line: 2080
// Start offset: 0x80021290

/* begin block 1.2.1 */
// Start line: 2087
// Start offset: 0x800212D4
// Variables:
// 		short _x1; // $v0
// 		short _y1; // $v1
// 		short _z1; // $a0
// 		struct _SVector *_v0; // $v0
// 		struct _SVector *_v1; // $v0
/* end block 1.2.1 */
// End offset: 0x800212D4
// End Line: 2087

/* begin block 1.2.2 */
// Start line: 2087
// Start offset: 0x800212D4
// Variables:
// 		short _x1; // $v1
// 		short _y1; // $a0
// 		short _z1; // $a1
/* end block 1.2.2 */
// End offset: 0x800212D4
// End Line: 2087

/* begin block 1.2.3 */
// Start line: 2096
// Start offset: 0x80021318
// Variables:
// 		short _x1; // $v0
// 		short _y1; // $v1
// 		short _z1; // $a0
/* end block 1.2.3 */
// End offset: 0x80021318
// End Line: 2096

/* begin block 1.2.4 */
// Start line: 2096
// Start offset: 0x80021318
// Variables:
// 		short _x1; // $a0
// 		short _y1; // $v1
// 		short _z1; // $a1
// 		struct _SVector *_v0; // $v0
/* end block 1.2.4 */
// End offset: 0x80021318
// End Line: 2096
/* end block 1.2 */
// End offset: 0x800213B8
// End Line: 2106
/* end block 1 */
// End offset: 0x800213B8
// End Line: 2108

/* begin block 2 */
// Start line: 4981
/* end block 2 */
// End Line: 4982

int COLLIDE_SphereAndHBox(_HBox *param_1, ushort *param_2, _SVector *param_3, short *param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  short local_60;
  short local_5e;
  short local_5c;
  short local_58;
  short local_56;
  short local_54;
  undefined auStack80[8];
  short local_48;
  short local_46;
  short local_44;
  undefined auStack64[8];
  short local_38;
  short local_36;
  short local_34;

  iVar2 = COLLIDE_ClosestPointInBoxToPoint(&local_60, (int)param_1, (short *)param_2);
  if (iVar2 == 0)
  {
    iVar2 = COLLIDE_IntersectLineAndBox(&local_58, &local_48, auStack80, auStack64, (short *)param_2, param_3, param_1);
    if (iVar2 == 0)
    {
      iVar6 = COLLIDE_SphereAndPoint((short *)param_2, &local_60, &local_38);
      iVar2 = 0;
      if (iVar6 != 0)
      {
        sGpffffa8bc = local_60;
        sGpffffa8be = local_5e;
        sGpffffa8c0 = local_5c;
        iVar2 = 1;
        *param_4 = local_38;
        param_4[1] = local_36;
        param_4[2] = local_34;
      }
    }
    else
    {
      *param_4 = local_48;
      param_4[1] = local_46;
      param_4[2] = local_44;
      sGpffffa8bc = local_58;
      sGpffffa8be = local_56;
      sGpffffa8c0 = local_54;
      *param_2 = local_58 + (short)((int)((int)*param_4 * (uint)param_2[3]) >> 0xc);
      param_2[1] = local_56 + (short)((int)((int)param_4[1] * (uint)param_2[3]) >> 0xc);
      iVar2 = 1;
      param_2[2] = local_54 + (short)((int)((int)param_4[2] * (uint)param_2[3]) >> 0xc);
    }
  }
  else
  {
    iVar2 = COLLIDE_IntersectLineAndBox(&local_58, &local_48, auStack80, auStack64, (short *)param_2, param_3, param_1);
    if (iVar2 == 0)
    {
      sVar1 = (short)((int)param_1->minY + (int)param_1->maxY >> 1) - param_2[1];
      sVar4 = (short)((int)param_1->minZ + (int)param_1->maxZ >> 1) - param_2[2];
      iVar6 = (int)((((int)param_1->minX + (int)param_1->maxX >> 1) - (uint)*param_2) * 0x10000) >>
              0x10;
      iVar2 = iVar6;
      if (iVar6 < 0)
      {
        iVar2 = -iVar6;
      }
      iVar3 = (int)sVar1;
      if (iVar3 < 0)
      {
        iVar3 = -iVar3;
      }
      sVar5 = sVar4;
      if (sVar4 < 0)
      {
        sVar5 = -sVar4;
      }
      if ((iVar2 * -0x10000 < iVar3 * -0x10000) || (iVar2 * -0x10000 >> 0x10 < (int)-sVar5))
      {
        if (((short)-(short)iVar3 < (short)-(short)iVar2) || ((short)-(short)iVar3 < -sVar5))
        {
          if (sVar4 < 0)
          {
            param_2[2] = param_1->maxZ + param_2[3];
            sVar1 = 0x1000;
          }
          else
          {
            param_2[2] = param_1->minZ - param_2[3];
            sVar1 = -0x1000;
          }
          *param_4 = 0;
          param_4[1] = 0;
          param_4[2] = sVar1;
        }
        else
        {
          if (sVar1 < 0)
          {
            param_2[1] = param_1->maxY + param_2[3];
            sVar1 = 0x1000;
          }
          else
          {
            param_2[1] = param_1->minY - param_2[3];
            sVar1 = -0x1000;
          }
          *param_4 = 0;
          param_4[1] = sVar1;
          param_4[2] = 0;
        }
      }
      else
      {
        if (iVar6 < 0)
        {
          *param_2 = param_1->maxX + param_2[3];
          sVar1 = 0x1000;
        }
        else
        {
          *param_2 = param_1->minX - param_2[3];
          sVar1 = -0x1000;
        }
        *param_4 = sVar1;
        param_4[1] = 0;
        param_4[2] = 0;
      }
      iVar2 = 1;
    }
    else
    {
      *param_4 = local_48;
      param_4[1] = local_46;
      param_4[2] = local_44;
      sGpffffa8bc = local_58;
      sGpffffa8be = local_56;
      sGpffffa8c0 = local_54;
      *param_2 = local_58 + (short)((int)((int)*param_4 * (uint)param_2[3]) >> 0xc);
      param_2[1] = local_56 + (short)((int)((int)param_4[1] * (uint)param_2[3]) >> 0xc);
      param_2[2] = local_54 + (short)((int)((int)param_4[2] * (uint)param_2[3]) >> 0xc);
    }
  }
  return iVar2;
}

// decompiled code
// original method signature:
// void /*$ra*/ COLLIDE_Instance1SpheresToInstance2(struct _Instance *instance1 /*stack 0*/, struct _Instance *instance2 /*$fp*/, long sphereToSphere /*$a2*/)
// line 2419, offset 0x800213dc
/* begin block 1 */
// Start line: 2420
// Start offset: 0x800213DC
// Variables:
// 		struct MATRIX *wsTransform2; // stack offset -132
// 		struct MATRIX *oldWSTransform2; // stack offset -128
// 		struct _Position *spherePos; // stack offset -124
// 		struct _Vector *line; // $s7
// 		struct _Vector *offset; // stack offset -120
// 		struct _Vector *tempVec; // stack offset -116
// 		struct _Vector *sSpherePos1; // stack offset -112
// 		struct _Vector *oldSSpherePos1; // stack offset -108
// 		struct _SVector *svec; // stack offset -104
// 		struct _Sphere *sSphere1; // $s3
// 		struct _Sphere *oldSSphere1; // stack offset -100
// 		struct _Sphere *wSphere1; // stack offset -96
// 		struct _Sphere *wSphere2; // stack offset -92
// 		struct _Sphere *oldWSphere1; // stack offset -88
// 		struct _Sphere *oldWSphere2; // stack offset -84
// 		struct _CollideInfo *collideInfo; // $s2
// 		struct _HFaceInfo *hfaceInfo; // stack offset -80
// 		struct MATRIX *swTransform1; // stack offset -76
// 		struct MATRIX *swTransform2; // stack offset -72
// 		struct MATRIX *oldSWTransform1; // $s0
// 		struct MATRIX *oldSWTransform2; // $s4
// 		struct _HSphere *hsphere1; // $s6
// 		struct _HSphere *hsphere2; // $s0
// 		struct _HFace *hface; // $s0
// 		void (*collideFunc)(); // $a3
// 		long flag; // stack offset -152
// 		long edge; // stack offset -136
// 		struct _HModel *hmodel1; // $a0
// 		struct _HModel *hmodel2; // stack offset -68
// 		struct _HPrim *hprim1; // stack offset -64
// 		struct _HPrim *hprim2; // stack offset -60
// 		int i; // stack offset -56

/* begin block 1.1 */
// Start line: 2478
// Start offset: 0x80021578
// Variables:
// 		int i; // stack offset -52

/* begin block 1.1.1 */
// Start line: 2524
// Start offset: 0x800217F0
// Variables:
// 		long len; // $a3

/* begin block 1.1.1.1 */
// Start line: 2525
// Start offset: 0x800217F0
// Variables:
// 		long a; // stack offset -148
// 		long b; // stack offset -144
// 		long c; // stack offset -140
/* end block 1.1.1.1 */
// End offset: 0x800217F0
// End Line: 2525

/* begin block 1.1.1.2 */
// Start line: 2531
// Start offset: 0x80021888
// Variables:
// 		short _x1; // $v1
// 		short _y1; // $a0
// 		short _z1; // $v0
// 		struct _Position *_v1; // $v0
/* end block 1.1.1.2 */
// End offset: 0x80021888
// End Line: 2531

/* begin block 1.1.1.3 */
// Start line: 2536
// Start offset: 0x800218B0
// Variables:
// 		short _x1; // $v0
// 		short _y1; // $v1
// 		short _z1; // $a0
/* end block 1.1.1.3 */
// End offset: 0x800218B0
// End Line: 2536
/* end block 1.1.1 */
// End offset: 0x800219E4
// End Line: 2561

/* begin block 1.1.2 */
// Start line: 2577
// Start offset: 0x80021A58
// Variables:
// 		struct _Model *model2; // $s1

/* begin block 1.1.2.1 */
// Start line: 2676
// Start offset: 0x80021E58
// Variables:
// 		struct _HBox *hbox; // $s4
/* end block 1.1.2.1 */
// End offset: 0x800220B4
// End Line: 2742
/* end block 1.1.2 */
// End offset: 0x800220B4
// End Line: 2743
/* end block 1.1 */
// End offset: 0x800220D4
// End Line: 2746
/* end block 1 */
// End offset: 0x800220FC
// End Line: 2748

/* begin block 2 */
// Start line: 4838
/* end block 2 */
// End Line: 4839

void COLLIDE_Instance1SpheresToInstance2(_Instance *instance1, _Instance *instance2, long sphereToSphere)

{
  _HModel *p_Var1;
  undefined auStack152[20];
  undefined4 *local_84;
  undefined *local_80;
  undefined2 *local_7c;
  undefined4 *local_78;
  undefined2 *local_74;
  undefined2 *local_70;
  undefined2 *local_6c;
  undefined2 *local_68;
  undefined2 *local_64;
  undefined2 *local_60;
  undefined2 *local_5c;
  undefined2 *local_58;
  undefined2 *local_54;
  undefined4 *local_50;
  MATRIX *local_4c;
  _HModel *local_44;
  _HPrim *local_40;
  int local_38;
  undefined *local_30;
  byte *local_2c;

  local_84 = &DAT_1f8000c8;
  local_80 = &DAT_1f800108;
  local_7c = &DAT_1f800128;
  local_78 = &DAT_1f800158;
  local_74 = &DAT_1f800168;
  local_70 = &DAT_1f800188;
  local_6c = &DAT_1f800198;
  local_68 = &DAT_1f8001a8;
  local_64 = &DAT_1f8001bc;
  local_60 = &DAT_1f8001e0;
  local_5c = &DAT_1f8001ec;
  local_58 = &DAT_1f8001f8;
  local_54 = &DAT_1f800204;
  local_50 = &DAT_1f800240;
  p_Var1 = instance1->hModelList + instance1->currentModel;
  if (((instance1->hModelList != (_HModel *)0x0) && (instance2->hModelList != (_HModel *)0x0)) &&
      (local_44 = instance2->hModelList + instance2->currentModel, local_44->numHPrims != 0))
  {
    local_38 = p_Var1->numHPrims;
    local_40 = p_Var1->hPrimList;
    if (local_38 != 0)
    {
      local_30 = auStack152;
      local_2c = &local_40->segment;
      do
      {
        if (((local_40->hpFlags & 1) != 0) && ((*(uint *)local_40 & 0xff0400) == 0x10400))
        {
          local_4c = instance1->matrix + *local_2c;
          SetRotMatrix((undefined4 *)local_4c);
          /* WARNING: Subroutine does not return */
          SetTransMatrix((int)local_4c);
        }
        local_38 = local_38 + -1;
        local_2c = local_2c + 8;
        local_40 = local_40 + 1;
      } while (local_38 != 0);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ COLLIDE_Instances(struct _Instance *instance1 /*$s1*/, struct _Instance *instance2 /*$s0*/)
// line 2761, offset 0x8002212c
/* begin block 1 */
// Start line: 2762
// Start offset: 0x8002212C
// Variables:
// 		long lx; // $a1
// 		long ly; // $a3
// 		long lz; // $a2
// 		long mrmr; // $v0

/* begin block 1.1 */
// Start line: 2806
// Start offset: 0x80022158
// Variables:
// 		long x; // $a1
// 		long y; // $a3
// 		long z; // $a2
/* end block 1.1 */
// End offset: 0x80022158
// End Line: 2806
/* end block 1 */
// End offset: 0x80022260
// End Line: 2828

/* begin block 2 */
// Start line: 7060
/* end block 2 */
// End Line: 7061

void COLLIDE_Instances(_Instance *instance1, _Instance *instance2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;

  if ((instance1 != instance2) && (iVar1 = INSTANCE_Linked(instance1, instance2), iVar1 == 0))
  {
    iVar1 = (int)instance1->object->modelList[instance1->currentModel]->maxRad +
                (int)instance2->object->modelList[instance2->currentModel]->maxRad >>
            1;
    setCopReg(2, 0x4800, (int)(instance1->position).x - (int)(instance2->position).x >> 1);
    setCopReg(2, 0x5000, (int)(instance1->position).y - (int)(instance2->position).y >> 1);
    setCopReg(2, 0x5800, (int)(instance1->position).z - (int)(instance2->position).z >> 1);
    copFunction(2, 0xa00428);
    iVar2 = getCopReg(2, 0xc800);
    iVar4 = getCopReg(2, 0xd000);
    iVar3 = getCopReg(2, 0xd800);
    if ((((uint)(iVar2 + iVar4 + iVar3) < (uint)(iVar1 * iVar1)) &&
         (((instance1->matrix != (MATRIX *)0x0 && (instance1->oldMatrix != (MATRIX *)0x0)) &&
           (instance2->matrix != (MATRIX *)0x0)))) &&
        (instance2->oldMatrix != (MATRIX *)0x0))
    {
      COLLIDE_Instance1SpheresToInstance2(instance1, instance2, 1);
      COLLIDE_Instance1SpheresToInstance2(instance2, instance1, 0);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ COLLIDE_InstanceList(struct _InstanceList *instanceList /*$s7*/)
// line 2839, offset 0x80022274
/* begin block 1 */
// Start line: 2840
// Start offset: 0x80022274
// Variables:
// 		struct _Instance *instance; // $s1
// 		struct _Instance *instance2; // $s0
// 		struct _Instance *playerInstance; // $s2
// 		long i; // $s4
// 		long j; // $s2
/* end block 1 */
// End offset: 0x800224EC
// End Line: 2926

/* begin block 2 */
// Start line: 7228
/* end block 2 */
// End Line: 7229

/* begin block 3 */
// Start line: 7236
/* end block 3 */
// End Line: 7237

void COLLIDE_InstanceList(_InstanceList *instanceList)

{
  NodeType **ppNVar1;
  _Instance *instance1;
  _Instance *instance2;
  int iVar2;
  long *plVar3;
  int iVar4;
  long *plVar5;

  instance2 = DAT_800d0fd8;
  if (aadMem._3_1_ != '\x01')
  {
    iVar4 = 0x10;
    ppNVar1 = &instanceList->group[0xe].next;
    do
    {
      instance1 = (_Instance *)ppNVar1[4];
      while (instance1 != (_Instance *)0x0)
      {
        /* WARNING: Read-only address (ram,0x800d0fd8) is written */
        /* WARNING: Read-only address (ram,0x800d1173) is written */
        if ((instance1->flags2 & 0x24040000U) == 0)
        {
          COLLIDE_Instances(instance1, instance2);
        }
        instance1 = (_Instance *)(instance1->node).next;
      }
      /* WARNING: Read-only address (ram,0x800d0fd8) is written */
      /* WARNING: Read-only address (ram,0x800d1173) is written */
      iVar4 = iVar4 + 1;
      ppNVar1 = ppNVar1 + 2;
    } while (iVar4 < 0x20);
  }
  iVar4 = 0;
  plVar5 = &dyna_clddyna;
  do
  {
    instance2 = (_Instance *)instanceList->group[*plVar5].next;
    while (instance2 != (_Instance *)0x0)
    {
      /* WARNING: Read-only address (ram,0x800d0fd8) is written */
      /* WARNING: Read-only address (ram,0x800d1173) is written */
      if ((instance2->flags2 & 0x24040000U) == 0)
      {
        instance1 = (_Instance *)(instance2->node).next;
        while (instance1 != (_Instance *)0x0)
        {
          /* WARNING: Read-only address (ram,0x800d0fd8) is written */
          /* WARNING: Read-only address (ram,0x800d1173) is written */
          if ((instance1->flags2 & 0x24040000U) == 0)
          {
            COLLIDE_Instances(instance2, instance1);
          }
          instance1 = (_Instance *)(instance1->node).next;
        }
        /* WARNING: Read-only address (ram,0x800d0fd8) is written */
        /* WARNING: Read-only address (ram,0x800d1173) is written */
        iVar2 = iVar4 + 1;
        if (iVar2 < 8)
        {
          plVar3 = &dyna_clddyna + iVar2;
          do
          {
            instance1 = (_Instance *)instanceList->group[*plVar3].next;
            while (instance1 != (_Instance *)0x0)
            {
              /* WARNING: Read-only address (ram,0x800d0fd8) is written */
              /* WARNING: Read-only address (ram,0x800d1173) is written */
              if ((instance1->flags2 & 0x24040000U) == 0)
              {
                COLLIDE_Instances(instance2, instance1);
              }
              instance1 = (_Instance *)(instance1->node).next;
            }
            /* WARNING: Read-only address (ram,0x800d0fd8) is written */
            /* WARNING: Read-only address (ram,0x800d1173) is written */
            iVar2 = iVar2 + 1;
            plVar3 = plVar3 + 1;
          } while (iVar2 < 8);
        }
      }
      instance2 = (_Instance *)(instance2->node).next;
    }
    /* WARNING: Read-only address (ram,0x800d0fd8) is written */
    /* WARNING: Read-only address (ram,0x800d1173) is written */
    iVar4 = iVar4 + 1;
    plVar5 = plVar5 + 1;
  } while (iVar4 < 8);
  iVar4 = 0;
  do
  {
    instance2 = (_Instance *)instanceList->group[(&dyna_cldstat)[iVar4]].next;
    while (instance2 != (_Instance *)0x0)
    {
      /* WARNING: Read-only address (ram,0x800d0fd8) is written */
      /* WARNING: Read-only address (ram,0x800d1173) is written */
      if ((instance2->flags2 & 0x24040000U) == 0)
      {
        iVar2 = 0;
        plVar5 = &stat_clddyna;
        do
        {
          instance1 = (_Instance *)instanceList->group[*plVar5].next;
          while (instance1 != (_Instance *)0x0)
          {
            /* WARNING: Read-only address (ram,0x800d0fd8) is written */
            /* WARNING: Read-only address (ram,0x800d1173) is written */
            if ((instance1->flags2 & 0x24040000U) == 0)
            {
              COLLIDE_Instances(instance2, instance1);
            }
            instance1 = (_Instance *)(instance1->node).next;
          }
          /* WARNING: Read-only address (ram,0x800d0fd8) is written */
          /* WARNING: Read-only address (ram,0x800d1173) is written */
          iVar2 = iVar2 + 1;
          plVar5 = plVar5 + 1;
        } while (iVar2 < 8);
      }
      instance2 = (_Instance *)(instance2->node).next;
    }
    /* WARNING: Read-only address (ram,0x800d0fd8) is written */
    /* WARNING: Read-only address (ram,0x800d1173) is written */
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ COLLIDE_SphereAndHFace(struct _Sphere *sphere /*$s2*/, struct _Position *oldPos /*$a1*/, struct _HFaceInfo *hfaceInfo /*$s4*/, struct _SVector *intersect /*$s5*/, long *edge /*stack 16*/)
// line 3061, offset 0x8002251c
/* begin block 1 */
// Start line: 3062
// Start offset: 0x8002251C
// Variables:
// 		struct SandHFScratch *CSpad; // $s0
// 		struct _SVector *vertex0; // $a0
// 		long result; // $s6
// 		long behind; // $v0
// 		unsigned long d0sq; // $s1

/* begin block 1.1 */
// Start line: 3126
// Start offset: 0x80022734
// Variables:
// 		struct _Vector dv; // stack offset -64

/* begin block 1.1.1 */
// Start line: 3128
// Start offset: 0x80022734
// Variables:
// 		short _x1; // $v0
// 		short _y1; // $v1
// 		short _z1; // $a0
// 		struct _SVector *_v0; // $v0
/* end block 1.1.1 */
// End offset: 0x80022734
// End Line: 3128
/* end block 1.1 */
// End offset: 0x80022814
// End Line: 3141

/* begin block 1.2 */
// Start line: 3143
// Start offset: 0x80022814
// Variables:
// 		long y; // $v1
// 		long z; // $v0
/* end block 1.2 */
// End offset: 0x80022814
// End Line: 3143

/* begin block 1.3 */
// Start line: 3147
// Start offset: 0x80022884
// Variables:
// 		unsigned long d1sq; // $a0

/* begin block 1.3.1 */
// Start line: 3149
// Start offset: 0x80022884
// Variables:
// 		long y; // $v1
// 		long z; // $v0
/* end block 1.3.1 */
// End offset: 0x80022884
// End Line: 3149

/* begin block 1.3.2 */
// Start line: 3161
// Start offset: 0x80022928
// Variables:
// 		long y; // $v1
// 		long z; // $v0
/* end block 1.3.2 */
// End offset: 0x80022928
// End Line: 3161
/* end block 1.3 */
// End offset: 0x800229B8
// End Line: 3170

/* begin block 1.4 */
// Start line: 3174
// Start offset: 0x800229CC
// Variables:
// 		long len; // $a2
// 		struct _Vector dv; // stack offset -64

/* begin block 1.4.1 */
// Start line: 3176
// Start offset: 0x800229CC
// Variables:
// 		long _x0; // $a3
// 		long _y0; // $t0
// 		long _z0; // $t1
// 		long _x1; // $v1
// 		long _y1; // $v0
// 		long _z1; // $v1
// 		struct _Vector *_v; // $v0
// 		struct _SVector *_v1; // $t2
/* end block 1.4.1 */
// End offset: 0x800229CC
// End Line: 3176

/* begin block 1.4.2 */
// Start line: 3176
// Start offset: 0x800229CC
// Variables:
// 		long a; // stack offset -48
// 		long b; // stack offset -44
// 		long c; // stack offset -40
/* end block 1.4.2 */
// End offset: 0x800229CC
// End Line: 3176
/* end block 1.4 */
// End offset: 0x80022BCC
// End Line: 3198
/* end block 1 */
// End offset: 0x80022BD0
// End Line: 3201

/* begin block 2 */
// Start line: 6122
/* end block 2 */
// End Line: 6123

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long COLLIDE_SphereAndHFace(_Sphere *sphere, _Position *oldPos, _HFaceInfo *hfaceInfo, _SVector *intersect,
                            long *edge)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar3;
  int iVar4;
  _HVertex *p_Var5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  long lVar10;
  short local_40;
  short local_3c;
  short local_38;
  int local_30;
  int local_2c;
  int local_28[2];

  p_Var5 = hfaceInfo->vertex0;
  lVar10 = 0;
  if ((hfaceInfo->hface->attr & 0x40) == 0)
  {
    *edge = 1;
    DAT_1f80005c = CONCAT22((sphere->position).y - p_Var5->y, (sphere->position).x - p_Var5->x);
    DAT_1f800060 = CONCAT22(oldPos->x - p_Var5->x, (sphere->position).z - p_Var5->z);
    _DAT_1f800064 = CONCAT22(oldPos->z - p_Var5->z, oldPos->y - p_Var5->y);
    _DAT_1f800068 = *(undefined4 *)p_Var5;
    DAT_1f80006c = CONCAT22(DAT_1f80006c._2_2_, p_Var5->z);
    DAT_1f800054 = *(undefined4 *)&hfaceInfo->normal;
    DAT_1f800058 = *(undefined4 *)&(hfaceInfo->normal).z;
    setCopControlWord(2, 0, DAT_1f80005c);
    setCopControlWord(2, 0x800, DAT_1f800060);
    setCopControlWord(2, 0x1000, _DAT_1f800064);
    setCopControlWord(2, 0x1800, _DAT_1f800068);
    setCopControlWord(2, 0x2000, DAT_1f80006c);
    setCopReg(2, in_zero, DAT_1f800054);
    setCopReg(2, in_at, DAT_1f800058);
    copFunction(2, 0x486012);
    _DAT_1f80007c = getCopReg(2, 0x19);
    _DAT_1f800080 = getCopReg(2, 0x1a);
    _DAT_1f800084 = getCopReg(2, 0x1b);
    lVar10 = 0;
    if (((_DAT_1f80007c <= _DAT_1f800080) && (lVar10 = 0, _DAT_1f80007c < (int)(uint)sphere->radius)) && (lVar10 = 0, (int)-(uint)sphere->radius <= _DAT_1f800080))
    {
      if (_DAT_1f80007c < 0)
      {
        iVar3 = COLLIDE_IntersectLineAndPlane_S(&DAT_1f800090, oldPos, sphere, &DAT_1f800054, _DAT_1f800084);
        if (iVar3 == 0)
        {
          return 0;
        }
      }
      else
      {
        COLLIDE_NearestPointOnPlane_S((short *)&DAT_1f800090, &DAT_1f800054, _DAT_1f800084, (undefined4 *)sphere);
      }
      iVar3 = COLLIDE_PointInTriangle((_SVector *)hfaceInfo->vertex0, (_SVector *)hfaceInfo->vertex1,
                                      (_SVector *)hfaceInfo->vertex2, (_SVector *)&DAT_1f800090,
                                      (_SVector *)&DAT_1f800054);
      if (iVar3 == 0)
      {
        COLLIDE_NearestPointOnLine_S(&DAT_1f800088, (uint *)hfaceInfo->vertex0, (uint *)hfaceInfo->vertex1,
                                     (uint *)sphere);
        setCopReg(2, 0x4800, (int)(sphere->position).x - (int)(short)DAT_1f800088);
        setCopReg(2, 0x5000, (int)(sphere->position).y - (int)DAT_1f800088._2_2_);
        setCopReg(2, 0x5800, (int)(sphere->position).z - (int)(short)DAT_1f80008c);
        copFunction(2, 0xa00428);
        iVar7 = getCopReg(2, 0xc800);
        iVar4 = getCopReg(2, 0xd000);
        iVar3 = getCopReg(2, 0xd800);
        uVar8 = iVar7 + iVar4 + iVar3;
        if (sphere->radiusSquared <= uVar8)
        {
          COLLIDE_NearestPointOnLine_S(&DAT_1f800090, (uint *)hfaceInfo->vertex1, (uint *)hfaceInfo->vertex2,
                                       (uint *)sphere);
          setCopReg(2, 0x4800, (int)(sphere->position).x - (int)(short)DAT_1f800090);
          setCopReg(2, 0x5000, (int)(sphere->position).y - (int)DAT_1f800090._2_2_);
          setCopReg(2, 0x5800, (int)(sphere->position).z - (int)(short)DAT_1f800094);
          copFunction(2, 0xa00428);
          iVar7 = getCopReg(2, 0xc800);
          iVar4 = getCopReg(2, 0xd000);
          iVar3 = getCopReg(2, 0xd800);
          uVar6 = iVar7 + iVar4 + iVar3;
          if (uVar6 < uVar8)
          {
            DAT_1f800088 = DAT_1f800090;
            DAT_1f80008c = DAT_1f800094;
            uVar8 = uVar6;
          }
          if (sphere->radiusSquared <= uVar8)
          {
            COLLIDE_NearestPointOnLine_S(&DAT_1f800090, (uint *)hfaceInfo->vertex2, (uint *)hfaceInfo->vertex0,
                                         (uint *)sphere);
            setCopReg(2, 0x4800, (int)(sphere->position).x - (int)(short)DAT_1f800090);
            setCopReg(2, 0x5000, (int)(sphere->position).y - (int)DAT_1f800090._2_2_);
            setCopReg(2, 0x5800, (int)(sphere->position).z - (int)(short)DAT_1f800094);
            copFunction(2, 0xa00428);
            iVar7 = getCopReg(2, 0xc800);
            iVar4 = getCopReg(2, 0xd000);
            iVar3 = getCopReg(2, 0xd800);
            uVar6 = iVar7 + iVar4 + iVar3;
            if (uVar6 < uVar8)
            {
              DAT_1f800088 = DAT_1f800090;
              DAT_1f80008c = DAT_1f800094;
              uVar8 = uVar6;
            }
            if (sphere->radiusSquared <= uVar8)
            {
              return 0;
            }
          }
        }
        iVar3 = (int)(sphere->position).x - (int)(short)DAT_1f800088;
        iVar4 = (int)(sphere->position).y - (int)DAT_1f800088._2_2_;
        iVar7 = (int)(sphere->position).z - (int)(short)DAT_1f80008c;
        local_30 = iVar3;
        if (iVar3 < 0)
        {
          local_30 = -iVar3;
        }
        local_2c = iVar4;
        if (iVar4 < 0)
        {
          local_2c = -iVar4;
        }
        local_28[0] = iVar7;
        if (iVar7 < 0)
        {
          local_28[0] = -iVar7;
        }
        MATH3D_Sort3VectorCoords(&local_30, &local_2c, local_28);
        intersect->x = (short)DAT_1f800088;
        intersect->y = DAT_1f800088._2_2_;
        intersect->z = (short)DAT_1f80008c;
        iVar9 = local_28[0] * 0x1e + local_2c * 0xc + local_30 * 9;
        if (iVar9 == 0)
        {
          local_40 = (short)((int)((int)(short)DAT_1f800054 * (uint)sphere->radius) >> 0xc);
          local_3c = (short)((int)((int)DAT_1f800054._2_2_ * (uint)sphere->radius) >> 0xc);
          local_38 = (short)((int)((int)(short)DAT_1f800058 * (uint)sphere->radius) >> 0xc);
        }
        else
        {
          local_3c = (short)((int)(iVar4 * (uint)sphere->radius * 0x20) / iVar9);
          local_38 = (short)((int)(iVar7 * (uint)sphere->radius * 0x20) / iVar9);
          local_40 = (short)((int)(iVar3 * (uint)sphere->radius * 0x20) / iVar9);
        }
        (sphere->position).x = local_40 + (short)DAT_1f800088;
        (sphere->position).y = local_3c + DAT_1f800088._2_2_;
        lVar10 = 1;
        (sphere->position).z = local_38 + (short)DAT_1f80008c;
      }
      else
      {
        DAT_1f800088 = DAT_1f800090;
        DAT_1f80008c = DAT_1f80008c & 0xffff0000 | DAT_1f800094 & 0xffff;
        intersect->x = (short)DAT_1f800090;
        intersect->y = DAT_1f800088._2_2_;
        intersect->z = (short)DAT_1f80008c;
        uVar1 = sphere->radius;
        uVar2 = sphere->radius;
        local_40 = (short)((int)((int)(short)DAT_1f800054 * (uint)sphere->radius) >> 0xc);
        (sphere->position).x = local_40 + (short)DAT_1f800088;
        local_3c = (short)((int)((int)DAT_1f800054._2_2_ * (uint)uVar1) >> 0xc);
        (sphere->position).y = local_3c + DAT_1f800088._2_2_;
        local_38 = (short)((int)((int)(short)DAT_1f800058 * (uint)uVar2) >> 0xc);
        (sphere->position).z = local_38 + (short)DAT_1f80008c;
        *edge = 0;
        lVar10 = -1;
      }
    }
  }
  return lVar10;
}

// decompiled code
// original method signature:
// long /*$ra*/ COLLIDE_SAndT(struct SCollideInfo *scollideInfo /*stack 0*/, struct Level *level /*stack 4*/)
// line 3243, offset 0x80022bf8
/* begin block 1 */
// Start line: 3244
// Start offset: 0x80022BF8
// Variables:
// 		struct SandTScratch *CSpad; // $s0
// 		void **stack; // $s1
// 		struct _BSPNode *bspNode; // $a1
// 		struct _Terrain *terrain; // $s5
// 		long curTree; // stack offset -44

/* begin block 1.1 */
// Start line: 3280
// Start offset: 0x80022C74
// Variables:
// 		short _x1; // $v1
// 		short _y1; // $a0
// 		short _z1; // $v0
// 		struct _SVector *_v0; // $s2
// 		struct _SVector *_v1; // $v0
/* end block 1.1 */
// End offset: 0x80022C74
// End Line: 3280

/* begin block 1.2 */
// Start line: 3280
// Start offset: 0x80022C74
// Variables:
// 		long a; // stack offset -56
// 		long b; // stack offset -52
// 		long c; // stack offset -48
/* end block 1.2 */
// End offset: 0x80022C74
// End Line: 3280

/* begin block 1.3 */
// Start line: 3314
// Start offset: 0x80022E64
// Variables:
// 		struct BSPTree *bsp; // $s4

/* begin block 1.3.1 */
// Start line: 3329
// Start offset: 0x80022EF0
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a0
// 		short _x1; // $a1
// 		short _y1; // $a2
// 		short _z1; // $a3
// 		struct _SVector *_v; // $fp
// 		struct _Position *_v1; // $t0
/* end block 1.3.1 */
// End offset: 0x80022EF0
// End Line: 3329

/* begin block 1.3.2 */
// Start line: 3329
// Start offset: 0x80022EF0
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a0
// 		short _x1; // $a1
// 		short _y1; // $a2
// 		short _z1; // $a3
// 		struct _SVector *_v; // $s7
/* end block 1.3.2 */
// End offset: 0x80022EF0
// End Line: 3329

/* begin block 1.3.3 */
// Start line: 3329
// Start offset: 0x80022EF0
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a0
// 		short _x1; // $a1
// 		short _y1; // $a2
// 		short _z1; // $a3
// 		struct _Position *_v; // $s6
/* end block 1.3.3 */
// End offset: 0x80022EF0
// End Line: 3329

/* begin block 1.3.4 */
// Start line: 3244
// Start offset: 0x80022FF4
// Variables:
// 		struct _SVector *point; // $t0
// 		struct _BoundingBox *box; // $a3
/* end block 1.3.4 */
// End offset: 0x8002308C
// End Line: 3244

/* begin block 1.3.5 */
// Start line: 3365
// Start offset: 0x80023094
// Variables:
// 		struct _TFace *tface; // $s3

/* begin block 1.3.5.1 */
// Start line: 3385
// Start offset: 0x80023138
// Variables:
// 		struct _SVector *vertex0; // $a3

/* begin block 1.3.5.1.1 */
// Start line: 3244
// Start offset: 0x800231B0
// Variables:
// 		short *nrmlArray; // $a0
// 		struct _SVector *nrml; // $a1

/* begin block 1.3.5.1.1.1 */
// Start line: 3244
// Start offset: 0x800231B0
// Variables:
// 		short *sPtr; // $v1
/* end block 1.3.5.1.1.1 */
// End offset: 0x80023240
// End Line: 3244
/* end block 1.3.5.1.1 */
// End offset: 0x80023240
// End Line: 3244

/* begin block 1.3.5.1.2 */
// Start line: 3417
// Start offset: 0x800232D4
/* end block 1.3.5.1.2 */
// End offset: 0x80023434
// End Line: 3469
/* end block 1.3.5.1 */
// End offset: 0x80023434
// End Line: 3470
/* end block 1.3.5 */
// End offset: 0x80023454
// End Line: 3473

/* begin block 1.3.6 */
// Start line: 3484
// Start offset: 0x8002347C
// Variables:
// 		int plane_front_error; // $v0
// 		int plane_back_error; // $a3
/* end block 1.3.6 */
// End offset: 0x800235CC
// End Line: 3547

/* begin block 1.3.7 */
// Start line: 3551
// Start offset: 0x800235DC
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a0
// 		short _x1; // $a1
// 		short _y1; // $a2
// 		short _z1; // $a3
// 		struct _Position *_v1; // $t0
/* end block 1.3.7 */
// End offset: 0x800235DC
// End Line: 3551

/* begin block 1.3.8 */
// Start line: 3551
// Start offset: 0x800235DC
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a0
// 		short _x1; // $a1
// 		short _y1; // $a2
// 		short _z1; // $a3
/* end block 1.3.8 */
// End offset: 0x800235DC
// End Line: 3551

/* begin block 1.3.9 */
// Start line: 3551
// Start offset: 0x800235DC
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a0
// 		short _x1; // $a1
// 		short _y1; // $a2
// 		short _z1; // $a3
/* end block 1.3.9 */
// End offset: 0x80023670
// End Line: 3553
/* end block 1.3 */
// End offset: 0x80023670
// End Line: 3554

/* begin block 1.4 */
// Start line: 3555
// Start offset: 0x80023688
// Variables:
// 		short _x1; // $a0
// 		short _y1; // $a1
// 		short _z1; // $v1
// 		struct _Position *_v0; // $v0
// 		struct _Position *_v1; // $v1
/* end block 1.4 */
// End offset: 0x80023688
// End Line: 3555
/* end block 1 */
// End offset: 0x800236B4
// End Line: 3557

/* begin block 2 */
// Start line: 8066
/* end block 2 */
// End Line: 8067

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int COLLIDE_SAndT(int *param_1, _Terrain **param_2)

{
  byte bVar1;
  short sVar2;
  bool bVar3;
  uint uVar4;
  undefined4 in_zero;
  undefined4 in_at;
  short sVar5;
  undefined4 *puVar6;
  short *psVar7;
  int iVar8;
  _BSPNode *p_Var9;
  long lVar10;
  undefined2 *puVar11;
  _Normal *p_Var12;
  ushort uVar13;
  int iVar14;
  _TVertex *p_Var15;
  _BSPNode *p_Var16;
  _BSPNode *p_Var17;
  ushort *puVar18;
  _TFace *tface;
  BSPTree *pBVar19;
  _Terrain *terrain;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;

  terrain = *param_2;
  p_Var17 = (_BSPNode *)&DAT_1f80029c;
  if (sGpffffb500 == 1000)
  {
    DAT_1f800264 = (int)sGpffffb502;
    if (DAT_1f800264 != 1)
    {
      DAT_1f800264 = 0;
    }
  }
  else
  {
    DAT_1f800264 = 2;
  }
  DAT_1f8001f4 = terrain->normalList;
  DAT_1f800298 = terrain->vertexList;
  DAT_1f800258 = (code *)param_1[2];
  DAT_1f80025c = (_Instance *)param_1[5];
  DAT_1f800270 = param_1[6];
  puVar6 = (undefined4 *)*param_1;
  DAT_1f80027c = *puVar6;
  DAT_1f800280 = puVar6[1];
  DAT_1f800284 = puVar6[2];
  DAT_1f800288 = 0;
  DAT_1f80028c = uGpffff86b0;
  DAT_1f800290 = uGpffff86b4;
  psVar7 = (short *)param_1[1];
  DAT_1f800268 = *psVar7;
  DAT_1f80026a = psVar7[1];
  DAT_1f80026c = psVar7[2];
  DAT_1f80027c._2_2_ = (short)((uint)DAT_1f80027c >> 0x10);
  DAT_1f800250 = (short)DAT_1f80027c;
  DAT_1f800248._0_2_ = (short)DAT_1f80027c - DAT_1f800268;
  DAT_1f800252 = DAT_1f80027c._2_2_;
  DAT_1f800254._0_2_ = (short)DAT_1f800280;
  DAT_1f800248._2_2_ = DAT_1f80027c._2_2_ - DAT_1f80026a;
  local_38 = (int)(short)DAT_1f800248;
  DAT_1f80024c = (short)DAT_1f800280 - DAT_1f80026c;
  if (local_38 < 0)
  {
    local_38 = -local_38;
  }
  local_34 = (int)DAT_1f800248._2_2_;
  local_30 = (int)DAT_1f80024c;
  if (local_34 < 0)
  {
    local_34 = -local_34;
  }
  if (local_30 < 0)
  {
    local_30 = -local_30;
  }
  MATH3D_Sort3VectorCoords(&local_38, &local_34, &local_30);
  DAT_1f800294 = local_30 * 0x1e + local_34 * 0xc + local_38 * 9;
  iVar8 = 0;
  if (DAT_1f800294 != 0)
  {
    DAT_1f800248._0_2_ = (short)((int)DAT_1f800250 + (int)DAT_1f800268 >> 1);
    DAT_1f800248._2_2_ = (short)((int)DAT_1f800252 + (int)DAT_1f80026a >> 1);
    DAT_1f80024c = (short)((int)(short)DAT_1f800254 + (int)DAT_1f80026c >> 1);
    DAT_1f800294 = DAT_1f800294 / 2 + (DAT_1f800280 >> 0x10);
    if (DAT_1f800264 == 2)
    {
      DAT_1f800294 = DAT_1f800294 + 0x800;
    }
    local_2c = 0;
    if (0 < terrain->numBSPTrees)
    {
      do
      {
        pBVar19 = terrain->BSPTreeArray + local_2c;
        if (((-1 < pBVar19->ID) &&
             ((uVar13 = pBVar19->flags, (uVar13 & 0x4000) == 0 || (cGpffffb711 != '\0')))) &&
            (((uVar13 & 0x2000) == 0 || (cGpffffb766 != '\0'))))
        {
          if ((uVar13 & 0x102) == 0)
          {
            DAT_1f800224._2_2_ = pBVar19->ID;
            DAT_1f800268 = DAT_1f800268 - (pBVar19->globalOffset).x;
            DAT_1f8001d0 = DAT_1f80026a - (pBVar19->globalOffset).y;
            DAT_1f8001d2 = DAT_1f80026c - (pBVar19->globalOffset).z;
            DAT_1f800248._0_2_ = (short)DAT_1f800248 - (pBVar19->globalOffset).x;
            DAT_1f800248._2_2_ = DAT_1f800248._2_2_ - (pBVar19->globalOffset).y;
            DAT_1f80024c = DAT_1f80024c - (pBVar19->globalOffset).z;
            DAT_1f80027c._0_2_ = (short)DAT_1f80027c - (pBVar19->globalOffset).x;
            DAT_1f80027c._2_2_ = DAT_1f80027c._2_2_ - (pBVar19->globalOffset).y;
            uVar13 = (short)DAT_1f800280 - (pBVar19->globalOffset).z;
            DAT_1f800280 = DAT_1f800280 & 0xffff0000 | (uint)uVar13;
            _DAT_1f8001c8 = CONCAT22(DAT_1f80027c._2_2_, (short)DAT_1f80027c);
            _DAT_1f8001cc = CONCAT22(DAT_1f800268, uVar13);
            DAT_1f80026a = DAT_1f8001d0;
            DAT_1f80026c = DAT_1f8001d2;
            *(_BSPNode **)&(p_Var17->sphere).position = p_Var17;
            SetRotMatrix((undefined4 *)&DAT_1f8001c8);
            p_Var9 = pBVar19->bspRoot;
            p_Var17 = (_BSPNode *)&(p_Var17->sphere).position.z;
            *(_BSPNode **)&(p_Var17->sphere).position = p_Var9;
            p_Var16 = p_Var17;
            if (p_Var9 != p_Var17)
            {
              do
              {
                iVar8 = *(int *)&(p_Var16->sphere).position;
                p_Var17 = (_BSPNode *)&p_Var16[-1].front_material_error;
                if ((*(ushort *)(iVar8 + 0xe) & 2) == 0)
                {
                  setCopReg(2, in_zero, *(undefined4 *)(iVar8 + 8));
                  setCopReg(2, in_at, *(undefined4 *)(iVar8 + 0xc));
                  copFunction(2, 0x486012);
                  DAT_1f8001e8 = getCopReg(2, 0x19);
                  _DAT_1f8001ec = getCopReg(2, 0x1a);
                  _DAT_1f8001f0 = getCopReg(2, 0x1b);
                  DAT_1f8001e8 = DAT_1f8001e8 - *(int *)(iVar8 + 0x10);
                  _DAT_1f8001ec = _DAT_1f8001ec - *(int *)(iVar8 + 0x10);
                  if (DAT_1f800264 == 0)
                  {
                    sVar5 = *(short *)(iVar8 + 0x28);
                    sVar2 = *(short *)(iVar8 + 0x2a);
                  }
                  else
                  {
                    sVar5 = *(short *)(iVar8 + 0x24);
                    sVar2 = *(short *)(iVar8 + 0x26);
                  }
                  iVar14 = (DAT_1f800280 >> 0x10) + (int)sVar5;
                  if (_DAT_1f8001ec < iVar14)
                  {
                    iVar14 = (int)sVar2 - (DAT_1f800280 >> 0x10);
                    if (iVar14 < _DAT_1f8001ec)
                    {
                      if (DAT_1f8001e8 < _DAT_1f8001ec)
                        goto LAB_8002359c;
                      if (*(int *)(iVar8 + 0x14) != 0)
                      {
                        *(int *)&(p_Var16->sphere).position = *(int *)(iVar8 + 0x14);
                        p_Var17 = p_Var16;
                      }
                      iVar8 = *(int *)(iVar8 + 0x18);
                    }
                    else
                    {
                      if ((iVar14 <= DAT_1f8001e8) && (*(int *)(iVar8 + 0x14) != 0))
                      {
                        *(int *)&(p_Var16->sphere).position = *(int *)(iVar8 + 0x14);
                        p_Var17 = p_Var16;
                      }
                      iVar8 = *(int *)(iVar8 + 0x18);
                    }
                  }
                  else
                  {
                    if (DAT_1f8001e8 <= iVar14)
                    {
                    LAB_8002359c:
                      if (*(int *)(iVar8 + 0x18) != 0)
                      {
                        *(int *)&(p_Var16->sphere).position = *(int *)(iVar8 + 0x18);
                        p_Var17 = p_Var16;
                      }
                    }
                    iVar8 = *(int *)(iVar8 + 0x14);
                  }
                  if (iVar8 != 0)
                  {
                    p_Var17 = (_BSPNode *)&(p_Var17->sphere).position.z;
                    *(int *)&(p_Var17->sphere).position = iVar8;
                  }
                }
                else
                {
                  bVar3 = false;
                  iVar14 = (int)(short)DAT_1f800294;
                  if (((((short)DAT_1f800248 - iVar14 < (int)*(short *)(iVar8 + 0x16)) &&
                        ((int)*(short *)(iVar8 + 0x10) < (short)DAT_1f800248 + iVar14)) &&
                       (DAT_1f800248._2_2_ - iVar14 < (int)*(short *)(iVar8 + 0x18))) &&
                      (((int)*(short *)(iVar8 + 0x12) < DAT_1f800248._2_2_ + iVar14 &&
                        (DAT_1f80024c - iVar14 < (int)*(short *)(iVar8 + 0x1a)))))
                  {
                    bVar3 = (int)*(short *)(iVar8 + 0x14) < DAT_1f80024c + iVar14;
                  }
                  if (bVar3)
                  {
                    _DAT_1f8001c8 = DAT_1f80027c;
                    uVar4 = _DAT_1f8001cc & 0xffff0000;
                    _DAT_1f8001cc = uVar4 | DAT_1f800280 & 0xffff;
                    DAT_1f8001ce = (ushort)(uVar4 >> 0x10);
                    setCopControlWord(2, 0, DAT_1f80027c);
                    setCopControlWord(2, 0x800, _DAT_1f8001cc);
                    DAT_1f80028a = *(short *)(iVar8 + 0xc);
                    tface = *(_TFace **)(iVar8 + 8);
                    puVar18 = &(tface->face).v2;
                    if (DAT_1f80028a != 0)
                    {
                      do
                      {
                        bVar1 = *(byte *)(puVar18 + 1);
                        if (((((bVar1 & DAT_1f80028c) == 0) || ((bVar1 & DAT_1f800290) != 0)) &&
                             ((puVar18[3] == 0xffff ||
                               ((*(ushort *)((int)&terrain->StartTextureList->attr + (uint)puVar18[3]) & 0x2000) == 0)))) &&
                            ((bVar1 & 8) == 0))
                        {
                          if ((DAT_1f800264 == 2) &&
                              ((uint)puVar18[2] !=
                               (int)terrain->morphNormalIdx
                                   [(int)((int)tface - (int)terrain->faceList) * -0x55555555 >> 2]))
                          {
                            COLLIDE_MakeNormal(terrain, tface, (_SVector *)&DAT_1f800274);
                          }
                          else
                          {
                            iVar8 = (int)(short)puVar18[2];
                            if (iVar8 < 0)
                            {
                              p_Var12 = (_Normal *)((int)DAT_1f8001f4 + iVar8 * -6);
                              DAT_1f800274 = CONCAT22(-p_Var12->y, -(p_Var12->x & 0x1fffU));
                              DAT_1f800278 = DAT_1f800278 & 0xffff0000 | (uint)(ushort)-p_Var12->z;
                            }
                            else
                            {
                              DAT_1f800274 = *(uint *)(&DAT_1f8001f4->x + iVar8 * 3) & 0xffff1fff;
                              DAT_1f800278 = DAT_1f800278 & 0xffff0000 |
                                             (uint)(ushort)(&DAT_1f8001f4->x + iVar8 * 3)[1];
                            }
                          }
                          p_Var15 = DAT_1f800298 + (tface->face).v0;
                          setCopControlWord(2, 0x1800, *(undefined4 *)&p_Var15->vertex);
                          setCopControlWord(2, 0x2000, *(undefined4 *)&(p_Var15->vertex).z);
                          setCopReg(2, in_zero, DAT_1f800274);
                          setCopReg(2, in_at, DAT_1f800278);
                          copFunction(2, 0x486012);
                          DAT_1f8001e8 = getCopReg(2, 0x19);
                          _DAT_1f8001ec = getCopReg(2, 0x1a);
                          _DAT_1f8001f0 = getCopReg(2, 0x1b);
                          if (DAT_1f8001e8 <= _DAT_1f8001ec)
                          {
                            if ((DAT_1f8001e8 - _DAT_1f8001f0 < (int)(DAT_1f800280 >> 0x10)) &&
                                ((int)-(DAT_1f800280 >> 0x10) <= _DAT_1f8001ec - _DAT_1f8001f0))
                            {
                              DAT_1f800240 = DAT_1f800298 + (short)puVar18[-1];
                              DAT_1f800244 = DAT_1f800298 + (short)*puVar18;
                              DAT_1f800234 = DAT_1f800274;
                              _DAT_1f800238 = DAT_1f800278;
                              DAT_1f800230 = tface;
                              _DAT_1f80023c = p_Var15;
                              lVar10 = COLLIDE_SphereAndHFace((_Sphere *)&DAT_1f80027c,
                                                              (_Position *)&DAT_1f800268,
                                                              (_HFaceInfo *)&DAT_1f800228,
                                                              (_SVector *)&DAT_1f800218, &DAT_1f800260);
                              if (lVar10 != 0)
                              {
                                if (DAT_1f800260 == 0)
                                {
                                  DAT_1f8001fc._0_1_ = 8;
                                }
                                else
                                {
                                  DAT_1f8001fc._0_1_ = 4;
                                }
                                DAT_1f8001fe = 1;
                                DAT_1f8001ff = 3;
                                _DAT_1f800208 = DAT_1f80025c;
                                DAT_1f8001fc._1_1_ = *(undefined *)(param_1 + 4);
                                DAT_1f800200 = DAT_1f800270;
                                DAT_1f800220._2_2_ = DAT_1f80027c._2_2_ - DAT_1f8001ca;
                                DAT_1f800220._0_2_ = (short)DAT_1f80027c - DAT_1f8001c8;
                                DAT_1f800224._0_2_ = (short)DAT_1f800280 - DAT_1f8001cc;
                                _DAT_1f8001f8 = param_2;
                                _DAT_1f800204 = tface;
                                DAT_1f80020c = pBVar19;
                                if (DAT_1f80025c != (_Instance *)0x0)
                                {
                                  *(undefined2 **)&DAT_1f80025c->collideInfo = &DAT_1f8001f8;
                                  if (DAT_1f800258 != (code *)0x0)
                                  {
                                    (*DAT_1f800258)(DAT_1f80025c, &gp0xffffb4f8);
                                  }
                                }
                                DAT_1f800288 = 1;
                                _DAT_1f8001c8 = DAT_1f80027c;
                                _DAT_1f8001cc = DAT_1f800280 & 0xffff | (uint)DAT_1f8001ce << 0x10;
                              }
                              SetRotMatrix((undefined4 *)&DAT_1f8001c8);
                            }
                          }
                        }
                        puVar18 = puVar18 + 6;
                        sVar5 = DAT_1f80028a + -1;
                        bVar3 = DAT_1f80028a != 1;
                        tface = tface + 1;
                        DAT_1f80028a = sVar5;
                      } while (bVar3);
                    }
                    _DAT_1f8001c8 = DAT_1f80027c;
                    _DAT_1f8001cc = DAT_1f800280 & 0xffff | (uint)DAT_1f8001ce << 0x10;
                    setCopControlWord(2, 0, DAT_1f80027c);
                    setCopControlWord(2, 0x800, _DAT_1f8001cc);
                  }
                }
                p_Var16 = p_Var17;
              } while (*(_BSPNode **)&(p_Var17->sphere).position != p_Var17);
            }
            DAT_1f800268 = DAT_1f800268 + (pBVar19->globalOffset).x;
            DAT_1f80026a = DAT_1f80026a + (pBVar19->globalOffset).y;
            DAT_1f80026c = DAT_1f80026c + (pBVar19->globalOffset).z;
            DAT_1f800248._0_2_ = (short)DAT_1f800248 + (pBVar19->globalOffset).x;
            DAT_1f800248._2_2_ = DAT_1f800248._2_2_ + (pBVar19->globalOffset).y;
            DAT_1f80024c = DAT_1f80024c + (pBVar19->globalOffset).z;
            DAT_1f80027c = CONCAT22(DAT_1f80027c._2_2_ + (pBVar19->globalOffset).y,
                                    (short)DAT_1f80027c + (pBVar19->globalOffset).x);
            DAT_1f800280 = DAT_1f800280 & 0xffff0000 |
                           (uint)(ushort)((short)DAT_1f800280 + (pBVar19->globalOffset).z);
          }
          else
          {
            if ((uVar13 & 0xe0) != 0)
            {
              /* WARNING: Subroutine does not return */
              INSTANCE_Query(DAT_1f80025c, 1);
            }
          }
        }
        local_2c = local_2c + 1;
      } while (local_2c < terrain->numBSPTrees);
    }
    puVar11 = (undefined2 *)*param_1;
    *puVar11 = (short)DAT_1f80027c;
    puVar11[1] = DAT_1f80027c._2_2_;
    puVar11[2] = (short)DAT_1f800280;
    iVar8 = (int)DAT_1f800288;
  }
  return iVar8;
}

// decompiled code
// original method signature:
// long /*$ra*/ COLLIDE_SphereAndTerrain(struct SCollideInfo *scollideInfo /*$s5*/, struct Level *level /*$s4*/)
// line 3770, offset 0x800236e4
/* begin block 1 */
// Start line: 3771
// Start offset: 0x800236E4
// Variables:
// 		int result; // $s3
// 		int d; // $s1

/* begin block 1.1 */
// Start line: 3771
// Start offset: 0x800236E4
// Variables:
// 		int in_warpRoom; // $s2
// 		struct _StreamUnit *stream; // $v0
/* end block 1.1 */
// End offset: 0x800237A4
// End Line: 3800
/* end block 1 */
// End offset: 0x800237A4
// End Line: 3802

/* begin block 2 */
// Start line: 9618
/* end block 2 */
// End Line: 9619

undefined4 COLLIDE_SphereAndTerrain(undefined4 param_1, char *param_2)

{
  undefined4 uVar1;
  _StreamUnit *p_Var2;
  long lVar3;
  undefined *puVar4;
  int iVar5;
  ushort uVar6;

  uVar1 = COLLIDE_SAndT();
  uVar6 = 0;
  p_Var2 = STREAM_GetStreamUnitWithID(*(long *)(param_2 + 0xf8));
  iVar5 = 0;
  if (p_Var2 != (_StreamUnit *)0x0)
  {
    uVar6 = p_Var2->flags & 1;
  }
  puVar4 = &gp0xffffbe6c;
  do
  {
    if ((((*(short *)(puVar4 + 4) == 2) && (*(char **)(puVar4 + 8) != param_2)) &&
         ((uVar6 == 0 || ((*(ushort *)(puVar4 + 6) & 1) == 0)))) &&
        (lVar3 = MEMPACK_MemoryValidFunc(*(char **)(puVar4 + 8)), lVar3 != 0))
    {
      uVar1 = COLLIDE_SAndT(param_1, *(undefined4 *)(puVar4 + 8));
    }
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 0x40;
  } while (iVar5 < 0x10);
  return uVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ COLLIDE_InstanceTerrain(struct _Instance *instance /*stack 0*/, struct Level *level /*stack 4*/)
// line 4238, offset 0x800237cc
/* begin block 1 */
// Start line: 4239
// Start offset: 0x800237CC
// Variables:
// 		struct _Vector *newPosVec; // stack offset -60
// 		struct _Vector *oldPosVec; // stack offset -56
// 		struct _SVector *oldPos; // $fp
// 		struct SCollideInfo scollideInfoX; // stack offset -96
// 		struct SCollideInfo *scollideInfo; // $s3
// 		struct _Sphere *wSphere; // $s5
// 		struct MATRIX *swTransform; // $s0
// 		struct MATRIX *oldSWTransform; // $s1
// 		void (*collideFunc)(); // stack offset -52
// 		struct _HSphere *hsphere; // $s2
// 		long flags; // stack offset -64

/* begin block 1.1 */
// Start line: 4273
// Start offset: 0x80023898
// Variables:
// 		int i; // $s7
// 		struct _HModel *hmodel; // $v0
// 		struct _HPrim *hprim; // $s6
/* end block 1.1 */
// End offset: 0x80023A04
// End Line: 4317
/* end block 1 */
// End offset: 0x80023A08
// End Line: 4321

/* begin block 2 */
// Start line: 10562
/* end block 2 */
// End Line: 10563

void COLLIDE_InstanceTerrain(int param_1)

{
  byte **ppbVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined auStack64[4];
  undefined4 *local_3c;
  undefined4 *local_38;
  int local_34;
  undefined *local_30;

  local_3c = &DAT_1f800148;
  local_38 = &DAT_1f800158;
  if ((*(int *)(param_1 + 0x40) != 0) && (*(int *)(param_1 + 0x44) != 0))
  {
    if ((*(uint *)(*(int *)(param_1 + 0x1c) + 0x2c) & 0x80000) != 0)
    {
      uGpffffb766 = 1;
    }
    local_34 = *(int *)(param_1 + 0xf4);
    if (local_34 != 0)
    {
      ppbVar1 = (byte **)(*(int *)(param_1 + 0xe8) + (int)*(short *)(param_1 + 0x10a) * 8);
      pbVar5 = ppbVar1[1];
      pbVar4 = *ppbVar1;
      local_30 = auStack64;
      if (pbVar5 != (byte *)0x0)
      {
        pbVar3 = pbVar4 + 3;
        do
        {
          if ((((*pbVar4 & 1) != 0) && ((pbVar3[-2] & 2) != 0)) && (pbVar3[-1] == 1))
          {
            puVar2 = (undefined4 *)(*(int *)(param_1 + 0x40) + (uint)*pbVar3 * 0x20);
            SetRotMatrix(puVar2);
            /* WARNING: Subroutine does not return */
            SetTransMatrix((int)puVar2);
          }
          pbVar5 = pbVar5 + -1;
          pbVar3 = pbVar3 + 8;
          pbVar4 = pbVar4 + 8;
        } while (pbVar5 != (byte *)0x0);
      }
    }
    uGpffffb766 = 0;
  }
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ COLLIDE_LineWithSignals(struct _SVector *startPoint /*$a0*/, struct _SVector *endPoint /*$a1*/, struct _MultiSignal **signalList /*stack 8*/, long maxSignals /*stack 12*/, struct Level *level /*stack 16*/)
// line 4331, offset 0x80023a38
/* begin block 1 */
// Start line: 4332
// Start offset: 0x80023A38
// Variables:
// 		struct IandTScratch *CSpad; // $s0
// 		void **stack; // $s2
// 		struct _BSPNode *bspNode; // $a1
// 		struct _TFace *tface; // $s3
// 		struct _Terrain *terrain; // $s4
// 		long curTree; // stack offset -56
// 		long numSignalsCollidedWith; // $fp

/* begin block 1.1 */
// Start line: 4377
// Start offset: 0x80023B20
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a0
// 		short _x1; // $a1
// 		short _y1; // $a2
// 		short _z1; // $a3
// 		struct _SVector *_v; // $v0
// 		struct _SVector *_v0; // $t1
// 		struct _SVector *_v1; // $t0
/* end block 1.1 */
// End offset: 0x80023B20
// End Line: 4377

/* begin block 1.2 */
// Start line: 4390
// Start offset: 0x80023BB8
// Variables:
// 		short _x0; // $v1
// 		short _y0; // $a0
// 		short _z0; // $a1
// 		short _x1; // $v0
// 		short _y1; // $a3
// 		short _z1; // $a2
// 		struct _SVector *_v; // $s7
// 		struct _Position *_v1; // $a2
/* end block 1.2 */
// End offset: 0x80023BB8
// End Line: 4390

/* begin block 1.3 */
// Start line: 4390
// Start offset: 0x80023BB8
// Variables:
// 		short _x0; // $v1
// 		short _y0; // $a0
// 		short _z0; // $a1
// 		short _x1; // $v0
// 		short _y1; // $a3
// 		short _z1; // $a2
// 		struct _SVector *_v; // $s6
// 		struct _Position *_v1; // $a2
/* end block 1.3 */
// End offset: 0x80023BB8
// End Line: 4390

/* begin block 1.4 */
// Start line: 4431
// Start offset: 0x80023DEC
// Variables:
// 		struct _SVector *vertex0; // $a0

/* begin block 1.4.1 */
// Start line: 4332
// Start offset: 0x80023DEC
// Variables:
// 		short *nrmlArray; // $a0
// 		struct _SVector *nrml; // $a1

/* begin block 1.4.1.1 */
// Start line: 4332
// Start offset: 0x80023DEC
// Variables:
// 		short *sPtr; // $v1
/* end block 1.4.1.1 */
// End offset: 0x80023E7C
// End Line: 4332
/* end block 1.4.1 */
// End offset: 0x80023E7C
// End Line: 4332

/* begin block 1.4.2 */
// Start line: 4449
// Start offset: 0x80023EFC

/* begin block 1.4.2.1 */
// Start line: 4332
// Start offset: 0x80023EFC
// Variables:
// 		struct _SVector *point; // $t0
// 		struct _SVector *start; // $a3
// 		struct _SVector *line; // $a2

/* begin block 1.4.2.1.1 */
// Start line: 4332
// Start offset: 0x80023EFC
// Variables:
// 		long len; // $v1
// 		long t; // $a1
/* end block 1.4.2.1.1 */
// End offset: 0x80023F2C
// End Line: 4332
/* end block 1.4.2.1 */
// End offset: 0x80023F2C
// End Line: 4332

/* begin block 1.4.2.2 */
// Start line: 4459
// Start offset: 0x80023FE0
// Variables:
// 		struct _MultiSignal *msignal; // $v1
/* end block 1.4.2.2 */
// End offset: 0x80024010
// End Line: 4470
/* end block 1.4.2 */
// End offset: 0x80024010
// End Line: 4471
/* end block 1.4 */
// End offset: 0x80024010
// End Line: 4472

/* begin block 1.5 */
// Start line: 4479
// Start offset: 0x80024030
// Variables:
// 		int plane_front_error; // $v1
// 		int plane_back_error; // $a0
/* end block 1.5 */
// End offset: 0x80024124
// End Line: 4524

/* begin block 1.6 */
// Start line: 4526
// Start offset: 0x80024134
// Variables:
// 		short _x0; // $v1
// 		short _y0; // $a0
// 		short _z0; // $a1
// 		short _x1; // $v0
// 		short _y1; // $a3
// 		short _z1; // $a2
// 		struct _Position *_v1; // $a2
/* end block 1.6 */
// End offset: 0x80024134
// End Line: 4526

/* begin block 1.7 */
// Start line: 4526
// Start offset: 0x80024134
// Variables:
// 		short _x0; // $v1
// 		short _y0; // $a0
// 		short _z0; // $a1
// 		short _x1; // $v0
// 		short _y1; // $a3
// 		short _z1; // $a2
// 		struct _Position *_v1; // $a2
/* end block 1.7 */
// End offset: 0x800241AC
// End Line: 4527
/* end block 1 */
// End offset: 0x800241C8
// End Line: 4531

/* begin block 2 */
// Start line: 10815
/* end block 2 */
// End Line: 10816

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int COLLIDE_LineWithSignals(undefined4 *param_1, undefined4 *param_2, int param_3, int param_4, int *param_5)

{
  short sVar1;
  short sVar2;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar3;
  uint *puVar4;
  ushort *puVar5;
  _SVector *v0;
  int *piVar6;
  ushort *puVar7;
  int **ppiVar8;
  int **ppiVar9;
  ushort *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iStack56;

  iVar11 = *param_5;
  DAT_1f80009c = *(int *)(iVar11 + 0x24);
  ppiVar9 = (int **)&DAT_1f8000a4;
  DAT_1f8000a0 = *(int *)(iVar11 + 0x1c);
  _DAT_1f800084 = *param_1;
  DAT_1f800088 = param_1[1];
  DAT_1f80008c = *param_2;
  DAT_1f800090 = param_2[1];
  if (sGpffffb500 == 1000)
  {
    DAT_1f800098 = (int)sGpffffb502;
    if (DAT_1f800098 != 1)
    {
      DAT_1f800098 = 0;
    }
  }
  else
  {
    DAT_1f800098 = 2;
  }
  DAT_1f800086 = (short)((uint)_DAT_1f800084 >> 0x10);
  DAT_1f80008c._2_2_ = (short)((uint)DAT_1f80008c >> 0x10);
  DAT_1f800080 = (short)DAT_1f800088 - (short)DAT_1f800090;
  _DAT_1f80007c = CONCAT22(DAT_1f800086 - DAT_1f80008c._2_2_, DAT_1f800084 - (short)DAT_1f80008c);
  if (((_DAT_1f80007c != 0) || (iVar13 = 0, DAT_1f800080 != 0)) &&
      (iStack56 = 0, iVar13 = 0, 0 < *(int *)(iVar11 + 0x44)))
  {
    iVar12 = 0;
    do
    {
      if (*(short *)(iVar12 + *(int *)(iVar11 + 0x48) + 0x1a) == -1)
      {
        *(int ***)ppiVar9 = ppiVar9;
        iVar3 = *(int *)(iVar11 + 0x48) + iVar12;
        DAT_1f80008c._0_2_ = (short)DAT_1f80008c - *(short *)(iVar3 + 0xc);
        DAT_1f80008c._2_2_ = DAT_1f80008c._2_2_ - *(short *)(iVar3 + 0xe);
        DAT_1f800090 = DAT_1f800090 & 0xffff0000 |
                       (uint)(ushort)((short)DAT_1f800090 - *(short *)(iVar3 + 0x10));
        iVar3 = *(int *)(iVar11 + 0x48) + iVar12;
        DAT_1f800084 = DAT_1f800084 - *(short *)(iVar3 + 0xc);
        DAT_1f800086 = DAT_1f800086 - *(short *)(iVar3 + 0xe);
        DAT_1f800088 = DAT_1f800088 & 0xffff0000 |
                       (uint)(ushort)((short)DAT_1f800088 - *(short *)(iVar3 + 0x10));
        ppiVar9 = ppiVar9 + 1;
        *ppiVar9 = *(int **)(iVar12 + *(int *)(iVar11 + 0x48));
        DAT_1f800040._0_2_ = (short)DAT_1f80008c;
        DAT_1f800040._2_2_ = DAT_1f80008c._2_2_;
        DAT_1f800044 = (short)DAT_1f800090;
        DAT_1f800046 = DAT_1f800084;
        DAT_1f800048 = DAT_1f800086;
        DAT_1f80004a = (short)DAT_1f800088;
        SetRotMatrix(&DAT_1f800040);
        ppiVar8 = ppiVar9;
        if ((int **)*ppiVar9 != ppiVar9)
        {
          do
          {
            piVar6 = *ppiVar8;
            ppiVar9 = ppiVar8 + -1;
            if ((*(ushort *)((int)piVar6 + 0xe) & 2) == 0)
            {
              setCopReg(2, in_zero, piVar6[2]);
              setCopReg(2, in_at, piVar6[3]);
              copFunction(2, 0x486012);
              _DAT_1f800068 = getCopReg(2, 0x19);
              DAT_1f80006c = getCopReg(2, 0x1a);
              DAT_1f800070 = getCopReg(2, 0x1b);
              _DAT_1f800068 = _DAT_1f800068 - piVar6[4];
              DAT_1f80006c = DAT_1f80006c - piVar6[4];
              if (DAT_1f800098 == 0)
              {
                sVar1 = *(short *)(piVar6 + 10);
                sVar2 = *(short *)((int)piVar6 + 0x2a);
              }
              else
              {
                sVar1 = *(short *)(piVar6 + 9);
                sVar2 = *(short *)((int)piVar6 + 0x26);
              }
              if ((_DAT_1f800068 < sVar1) || (DAT_1f80006c < sVar1))
              {
                if (((sVar2 < _DAT_1f800068) || (sVar2 < DAT_1f80006c)) &&
                    ((int *)piVar6[5] != (int *)0x0))
                {
                  *ppiVar8 = (int *)piVar6[5];
                  ppiVar9 = ppiVar8;
                }
                piVar6 = (int *)piVar6[6];
              }
              else
              {
                piVar6 = (int *)piVar6[5];
              }
              if (piVar6 != (int *)0x0)
              {
                ppiVar9 = ppiVar9 + 1;
                *ppiVar9 = piVar6;
              }
            }
            else
            {
              if (((((short)DAT_1f80008c <= *(short *)((int)piVar6 + 0x16)) ||
                    (DAT_1f800084 <= *(short *)((int)piVar6 + 0x16))) &&
                   ((*(short *)(piVar6 + 4) <= (short)DAT_1f80008c ||
                     (*(short *)(piVar6 + 4) <= DAT_1f800084)))) &&
                  (((DAT_1f80008c._2_2_ <= *(short *)(piVar6 + 6) ||
                     (DAT_1f800086 <= *(short *)(piVar6 + 6))) &&
                    ((*(short *)((int)piVar6 + 0x12) <= DAT_1f80008c._2_2_ ||
                      (*(short *)((int)piVar6 + 0x12) <= DAT_1f800086))))))
              {
                if ((((short)DAT_1f800090 <= *(short *)((int)piVar6 + 0x1a)) ||
                     ((short)DAT_1f800088 <= *(short *)((int)piVar6 + 0x1a))) &&
                    ((*(short *)(piVar6 + 5) <= (short)DAT_1f800090 ||
                      (*(short *)(piVar6 + 5) <= (short)DAT_1f800088))))
                {
                  DAT_1f800094 = (int)*(short *)(piVar6 + 3);
                  puVar10 = (ushort *)piVar6[2];
                  puVar7 = puVar10 + 5;
                  while (DAT_1f800094 != 0)
                  {
                    if (((puVar7[-2] & 0xc0) != 0) && (*puVar7 != 0xffff))
                    {
                      iVar3 = (int)(short)puVar7[-1];
                      if (iVar3 < 0)
                      {
                        puVar5 = (ushort *)(DAT_1f80009c + iVar3 * -6);
                        DAT_1f800060 = CONCAT22(-puVar5[1], -(*puVar5 & 0x1fff));
                        _DAT_1f800064 = _DAT_1f800064 & 0xffff0000 | (uint)(ushort)-puVar5[2];
                      }
                      else
                      {
                        puVar4 = (uint *)(DAT_1f80009c + iVar3 * 6);
                        DAT_1f800060 = *puVar4 & 0xffff1fff;
                        _DAT_1f800064 = _DAT_1f800064 & 0xffff0000 | (uint) * (ushort *)(puVar4 + 1);
                      }
                      v0 = (_SVector *)(DAT_1f8000a0 + (uint)*puVar10 * 0xc);
                      setCopControlWord(2, 0x1800, *(undefined4 *)v0);
                      setCopControlWord(2, 0x2000, *(undefined4 *)&v0->z);
                      setCopReg(2, in_zero, DAT_1f800060);
                      setCopReg(2, in_at, _DAT_1f800064);
                      copFunction(2, 0x486012);
                      _DAT_1f800068 = getCopReg(2, 0x19);
                      DAT_1f80006c = getCopReg(2, 0x1a);
                      DAT_1f800070 = getCopReg(2, 0x1b);
                      _DAT_1f800068 = _DAT_1f800068 - DAT_1f800070;
                      DAT_1f80006c = DAT_1f80006c - DAT_1f800070;
                      if ((_DAT_1f800068 < 0) && (-1 < DAT_1f80006c))
                      {
                        if (_DAT_1f800068 - DAT_1f80006c == 0)
                        {
                          iVar3 = 0;
                        }
                        else
                        {
                          iVar3 = (DAT_1f80006c * 0x1000) / (_DAT_1f800068 - DAT_1f80006c);
                        }
                        DAT_1f800074._0_2_ = DAT_1f800084 + (short)(DAT_1f80007c * iVar3 >> 0xc);
                        DAT_1f80007e = (short)((uint)_DAT_1f80007c >> 0x10);
                        DAT_1f800074._2_2_ = DAT_1f800086 + (short)(DAT_1f80007e * iVar3 >> 0xc);
                        DAT_1f800078 = (short)DAT_1f800088 + (short)(DAT_1f800080 * iVar3 >> 0xc);
                        iVar3 = COLLIDE_PointInTriangle(v0, (_SVector *)(DAT_1f8000a0 + (uint)puVar7[-4] * 0xc),
                                                        (_SVector *)(DAT_1f8000a0 + (uint)puVar7[-3] * 0xc),
                                                        (_SVector *)&DAT_1f800074, (_SVector *)&DAT_1f800060);
                        if ((iVar3 != 0) && (iVar3 = iVar13 * 4, iVar13 < param_4))
                        {
                          iVar13 = iVar13 + 1;
                          *(int *)(iVar3 + param_3) = *(int *)(iVar11 + 0x50) + (uint)*puVar7;
                        }
                      }
                    }
                    puVar7 = puVar7 + 6;
                    puVar10 = puVar10 + 6;
                    DAT_1f800094 = DAT_1f800094 + -1;
                  }
                }
              }
            }
            ppiVar8 = ppiVar9;
          } while ((int **)*ppiVar9 != ppiVar9);
        }
        iVar3 = *(int *)(iVar11 + 0x48) + iVar12;
        DAT_1f80008c = CONCAT22(DAT_1f80008c._2_2_ + *(short *)(iVar3 + 0xe),
                                (short)DAT_1f80008c + *(short *)(iVar3 + 0xc));
        DAT_1f800090 = DAT_1f800090 & 0xffff0000 |
                       (uint)(ushort)((short)DAT_1f800090 + *(short *)(iVar3 + 0x10));
        iVar3 = *(int *)(iVar11 + 0x48) + iVar12;
        _DAT_1f800084 =
            CONCAT22(DAT_1f800086 + *(short *)(iVar3 + 0xe), DAT_1f800084 + *(short *)(iVar3 + 0xc));
        DAT_1f800088 = DAT_1f800088 & 0xffff0000 |
                       (uint)(ushort)((short)DAT_1f800088 + *(short *)(iVar3 + 0x10));
      }
      iVar12 = iVar12 + 0x24;
      iStack56 = iStack56 + 1;
    } while (iStack56 < *(int *)(iVar11 + 0x44));
  }
  return iVar13;
}

// decompiled code
// original method signature:
// void /*$ra*/ COLLIDE_InstanceTerrainSignal(struct _Instance *instance /*$s3*/, struct Level *level /*$s1*/)
// line 4548, offset 0x800241fc
/* begin block 1 */
// Start line: 4549
// Start offset: 0x800241FC
// Variables:
// 		struct _SVector startPoint; // stack offset -72
// 		struct _SVector endPoint; // stack offset -64
// 		struct _Model *model; // $s0
// 		long numSignals; // $s4
// 		long d; // $s1
// 		struct _MultiSignal (*signalListArray[8]); // stack offset -56

/* begin block 1.1 */
// Start line: 4616
// Start offset: 0x800243DC
// Variables:
// 		struct _MultiSignal *msignal; // $s0
/* end block 1.1 */
// End offset: 0x800243FC
// End Line: 4625
/* end block 1 */
// End offset: 0x80024424
// End Line: 4630

/* begin block 2 */
// Start line: 11519
/* end block 2 */
// End Line: 11520

void COLLIDE_InstanceTerrainSignal(_Instance *param_1, undefined4 param_2)

{
  int iVar1;
  _Model *p_Var2;
  _MultiSignal *mSignal;
  int iVar3;
  _MultiSignal **pp_Var4;
  undefined4 local_48;
  uint local_44;
  undefined4 local_40;
  uint local_3c;
  _MultiSignal *local_38[8];

  p_Var2 = param_1->object->modelList[param_1->currentModel];
  if ((param_1->matrix != (MATRIX *)0x0) && (param_1->oldMatrix != (MATRIX *)0x0))
  {
    if ((param_1->object->oflags2 & 0x80000U) != 0)
    {
      /* WARNING: Subroutine does not return */
      INSTANCE_Query(param_1, 1);
    }
    if ((p_Var2 == (_Model *)0x0) || (p_Var2->numSegments < 2))
    {
      local_48 = *(undefined4 *)&param_1->oldPos;
      local_44 = *(uint *)&(param_1->oldPos).z;
      local_40 = *(undefined4 *)&param_1->position;
      local_3c = *(uint *)&(param_1->position).z;
    }
    else
    {
      local_48 = CONCAT22(*(undefined2 *)(param_1->oldMatrix[1].t + 1),
                          *(undefined2 *)param_1->oldMatrix[1].t);
      local_44 = local_44 & 0xffff0000 | (uint) * (ushort *)(param_1->oldMatrix[1].t + 2);
      local_40 = CONCAT22(*(undefined2 *)(param_1->matrix[1].t + 1),
                          *(undefined2 *)param_1->matrix[1].t);
      local_3c = local_3c & 0xffff0000 | (uint) * (ushort *)(param_1->matrix[1].t + 2);
    }
    pp_Var4 = local_38;
    iVar1 = COLLIDE_LineWithSignals(&local_48, &local_40, pp_Var4, 8, param_2);
    iVar3 = 0;
    if (0 < iVar1)
    {
      do
      {
        mSignal = *pp_Var4;
        if (param_1 == p_Gpffffb524)
        {
          mSignal->flags = mSignal->flags | 1;
        }
        SIGNAL_HandleSignal(param_1, mSignal->signalList, 0);
        EVENT_AddSignalToReset(mSignal);
        iVar3 = iVar3 + 1;
        pp_Var4 = pp_Var4 + 1;
      } while (iVar3 < iVar1);
    }
  }
  return;
}

// decompiled code
// original method signature:
// struct _StreamUnit * /*$ra*/ COLLIDE_CameraWithStreamSignals(struct Camera *camera /*$s1*/)
// line 4634, offset 0x80024444
/* begin block 1 */
// Start line: 4635
// Start offset: 0x80024444
// Variables:
// 		struct _SVector startPoint; // stack offset -112
// 		struct _SVector endPoint; // stack offset -104
// 		struct _Model *model; // $v1
// 		long numSignals; // $s3
// 		long i; // $s1
// 		long numStreamSignals; // $s2
// 		struct _MultiSignal (*signalListArray[8]); // stack offset -96
// 		struct _StreamUnit (*streamSignalUnits[8]); // stack offset -64
// 		struct _StreamUnit *playerStreamUnit; // $s2
// 		struct Level *level; // $v0
// 		long playerStreamUnitID; // $s4
// 		struct _Instance *instance; // $s0
// 		struct _Instance *af_instance; // $v0

/* begin block 1.1 */
// Start line: 4725
// Start offset: 0x800245E0
// Variables:
// 		struct _MultiSignal *msignal; // $v0
// 		long isWarpGateSignal; // stack offset -32

/* begin block 1.1.1 */
// Start line: 4733
// Start offset: 0x80024604
// Variables:
// 		struct _StreamUnit *cameraStreamUnit; // $v1
// 		long cameraStreamID; // $a0

/* begin block 1.1.1.1 */
// Start line: 4742
// Start offset: 0x80024624
// Variables:
// 		int number; // $v1
/* end block 1.1.1.1 */
// End offset: 0x80024638
// End Line: 4746
/* end block 1.1.1 */
// End offset: 0x8002469C
// End Line: 4762
/* end block 1.1 */
// End offset: 0x8002469C
// End Line: 4763
/* end block 1 */
// End offset: 0x8002470C
// End Line: 4794

/* begin block 2 */
// Start line: 11707
/* end block 2 */
// End Line: 11708

_StreamUnit *COLLIDE_CameraWithStreamSignals(Camera *camera)

{
  long id;

  id = camera->focusInstance->currentStreamUnitID;
  if ((camera->focusInstance == DAT_800d0fd8) && (DAT_800d1128 != 0))
  {
    id = DAT_800d114c;
  }
  STREAM_GetStreamUnitWithID(id);
  /* WARNING: Subroutine does not return */
  INSTANCE_Query(camera->focusInstance, 10);
}

// decompiled code
// original method signature:
// void /*$ra*/ COLLIDE_InstanceListWithSignals(struct _InstanceList *instanceList /*$a0*/)
// line 4797, offset 0x8002472c
/* begin block 1 */
// Start line: 4798
// Start offset: 0x8002472C
// Variables:
// 		struct _Instance *instance; // $s0
// 		struct Level *level; // $v0
/* end block 1 */
// End offset: 0x8002478C
// End Line: 4814

/* begin block 2 */
// Start line: 12100
/* end block 2 */
// End Line: 12101

void COLLIDE_InstanceListWithSignals(_InstanceList *instanceList)

{
  _Instance *p_Var1;

  p_Var1 = instanceList->first;
  while (true)
  {
    if (p_Var1 == (_Instance *)0x0)
    {
      return;
    }
    if ((p_Var1->flags2 & 0x24000000U) == 0)
      break;
    p_Var1 = p_Var1->next;
  }
  /* WARNING: Subroutine does not return */
  STREAM_GetLevelWithID(p_Var1->currentStreamUnitID);
}

// decompiled code
// original method signature:
// void /*$ra*/ COLLIDE_InstanceListTerrain(struct _InstanceList *instanceList /*$a0*/)
// line 4816, offset 0x800247a0
/* begin block 1 */
// Start line: 4817
// Start offset: 0x800247A0
// Variables:
// 		long i; // $s2
// 		struct _Instance *instance; // $s0
// 		struct Level *level; // $v0
/* end block 1 */
// End offset: 0x80024834
// End Line: 4856

/* begin block 2 */
// Start line: 12145
/* end block 2 */
// End Line: 12146

void COLLIDE_InstanceListTerrain(_InstanceList *instanceList)

{
  _InstancePool *p_Var1;
  _InstancePool **pp_Var2;
  int iVar3;

  iVar3 = 1;
  pp_Var2 = &instanceList->pool;
  do
  {
    p_Var1 = pp_Var2[4];
    while (p_Var1 != (_InstancePool *)0x0)
    {
      if ((*(int *)&p_Var1->instance[0].offset != 0) &&
          ((p_Var1->instance[0].instanceID & 0x24040000U) == 0))
      {
        /* WARNING: Subroutine does not return */
        STREAM_GetLevelWithID(p_Var1->instance[0].introNum);
      }
      p_Var1 = (_InstancePool *)p_Var1->numFreeInstances;
    }
    iVar3 = iVar3 + 2;
    pp_Var2 = pp_Var2 + 4;
    if (0x1f < iVar3)
    {
      return;
    }
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ COLLIDE_SegmentCollisionOn(struct _Instance *instance /*$a0*/, int segment /*$a1*/)
// line 4947, offset 0x80024850
/* begin block 1 */
// Start line: 4949
// Start offset: 0x80024850

/* begin block 1.1 */
// Start line: 4951
// Start offset: 0x80024860
// Variables:
// 		int i; // $a2
// 		struct _HModel *hmodel; // $v0
// 		struct _HPrim *hprim; // $v1
/* end block 1.1 */
// End offset: 0x800248C0
// End Line: 4962
/* end block 1 */
// End offset: 0x800248C0
// End Line: 4963

/* begin block 2 */
// Start line: 9894
/* end block 2 */
// End Line: 9895

/* begin block 3 */
// Start line: 12376
/* end block 3 */
// End Line: 12377

void COLLIDE_SegmentCollisionOn(_Instance *instance, int segment)

{
  _HModel *p_Var1;
  _HPrim *p_Var2;
  int iVar3;

  if (instance->hModelList != (_HModel *)0x0)
  {
    p_Var1 = instance->hModelList + instance->currentModel;
    iVar3 = p_Var1->numHPrims;
    p_Var2 = p_Var1->hPrimList;
    while (iVar3 != 0)
    {
      if ((uint)p_Var2->segment == segment)
      {
        p_Var2->hpFlags = p_Var2->hpFlags | 1;
      }
      iVar3 = iVar3 + -1;
      p_Var2 = p_Var2 + 1;
    }
    instance->flags2 = instance->flags2 & 0xfffbffff;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ COLLIDE_SegmentCollisionOff(struct _Instance *instance /*$a0*/, int segment /*$a1*/)
// line 4968, offset 0x800248c8
/* begin block 1 */
// Start line: 4970
// Start offset: 0x800248C8

/* begin block 1.1 */
// Start line: 4972
// Start offset: 0x800248D8
// Variables:
// 		int i; // $a2
// 		int enabled; // $a3
// 		struct _HModel *hmodel; // $v0
// 		struct _HPrim *hprim; // $v1
/* end block 1.1 */
// End offset: 0x8002495C
// End Line: 4987
/* end block 1 */
// End offset: 0x8002495C
// End Line: 4988

/* begin block 2 */
// Start line: 12420
/* end block 2 */
// End Line: 12421

/* begin block 3 */
// Start line: 12421
/* end block 3 */
// End Line: 12422

void COLLIDE_SegmentCollisionOff(_Instance *instance, int segment)

{
  bool bVar1;
  _HModel *p_Var2;
  _HPrim *p_Var3;
  int iVar4;

  if (instance->hModelList != (_HModel *)0x0)
  {
    p_Var2 = instance->hModelList + instance->currentModel;
    iVar4 = p_Var2->numHPrims;
    p_Var3 = p_Var2->hPrimList;
    bVar1 = false;
    while (iVar4 != 0)
    {
      if ((uint)p_Var3->segment == segment)
      {
        p_Var3->hpFlags = p_Var3->hpFlags & 0xfe;
      }
      if ((!bVar1) && ((p_Var3->hpFlags & 1) != 0))
      {
        bVar1 = true;
      }
      iVar4 = iVar4 + -1;
      p_Var3 = p_Var3 + 1;
    }
    if (!bVar1)
    {
      instance->flags2 = instance->flags2 | 0x40000;
    }
  }
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ COLLIDE_FindCollisionFaceNormal(struct _CollideInfo *collideInfo /*$a0*/, struct _Normal *normal /*$s2*/)
// line 5015, offset 0x80024964
/* begin block 1 */
// Start line: 5016
// Start offset: 0x80024964
// Variables:
// 		long valid_normal; // $a2

/* begin block 1.1 */
// Start line: 5025
// Start offset: 0x80024998
// Variables:
// 		struct _TFace *tface; // $a1
/* end block 1.1 */
// End offset: 0x800249E0
// End Line: 5029

/* begin block 1.2 */
// Start line: 5036
// Start offset: 0x80024A18

/* begin block 1.2.1 */
// Start line: 5040
// Start offset: 0x80024A18
// Variables:
// 		struct SVECTOR *lNormal; // stack offset -24
// 		struct _Instance *inst1; // $s1
/* end block 1.2.1 */
// End offset: 0x80024A18
// End Line: 5041
/* end block 1.2 */
// End offset: 0x80024A18
// End Line: 5041

/* begin block 1.3 */
// Start line: 5054
// Start offset: 0x80024A6C
// Variables:
// 		struct _Instance *inst1; // $v0
/* end block 1.3 */
// End offset: 0x80024A84
// End Line: 5058
/* end block 1 */
// End offset: 0x80024A84
// End Line: 5060

/* begin block 2 */
// Start line: 10030
/* end block 2 */
// End Line: 10031

undefined4 COLLIDE_FindCollisionFaceNormal(int **param_1, _SVector *param_2)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  _SVector *nrml;
  undefined4 uVar4;
  int *piVar5;
  _SVector _Stack24;

  cVar1 = *(char *)((int)param_1 + 7);
  uVar4 = 0;
  if (cVar1 != '\x01')
  {
    if (cVar1 != '\x03')
    {
      if (cVar1 == '\x02')
      {
        nrml = &_Stack24;
        piVar5 = param_1[5];
        COLLIDE_GetNormal(*(short *)(param_1[3] + 2),
                          *(short **)(*(int *)((int)*(short *)((int)piVar5 + 0x10a) * 4 +
                                               *(int *)(piVar5[7] + 0xc)) +
                                      0xc),
                          nrml);
        iVar3 = piVar5[0x10];
      }
      else
      {
        nrml = (_SVector *)(param_1 + 6);
        if (((uint)param_1[1] & 0xffff0000) != 0x5010000)
        {
          return 0;
        }
        iVar3 = param_1[5][0x10];
      }
      /* WARNING: Subroutine does not return */
      ApplyMatrixSV(iVar3, nrml, param_2);
    }
    uVar2 = *(ushort *)((int)param_1[3] + 10);
    if ((uVar2 == 0xffff) ||
        ((*(ushort *)(*(int *)(**param_1 + 0x34) + (uint)uVar2 + 10) & 0x2000) == 0))
    {
      COLLIDE_GetNormal(*(short *)(param_1[3] + 2), *(short **)(**param_1 + 0x24), param_2);
      uVar4 = 1;
    }
  }
  return uVar4;
}

// decompiled code
// original method signature:
// short * /*$ra*/ COLLIDE_GetBSPTreeFlag(struct _CollideInfo *collideInfo /*$a0*/)
// line 5065, offset 0x80024aa0
/* begin block 1 */
// Start line: 5067
// Start offset: 0x80024AA0
// Variables:
// 		struct Level *level; // $v0
// 		struct _Terrain *terrain; // $v0
// 		struct BSPTree *bspTree; // $v0
/* end block 1 */
// End offset: 0x80024AA0
// End Line: 5079

/* begin block 2 */
// Start line: 12592
/* end block 2 */
// End Line: 12593

/* begin block 3 */
// Start line: 12593
/* end block 3 */
// End Line: 12594

/* begin block 4 */
// Start line: 12605
/* end block 4 */
// End Line: 12606

short *COLLIDE_GetBSPTreeFlag(_CollideInfo *collideInfo)

{
  return (short *)(*(int *)(*(int *)collideInfo->level + 0x48) + (int)collideInfo->bspID * 0x24 +
                   0x12);
}

// decompiled code
// original method signature:
// void /*$ra*/ COLLIDE_SetBSPTreeFlag(struct _CollideInfo *collideInfo /*$a0*/, short flag /*$a1*/)
// line 5089, offset 0x80024ac8
/* begin block 1 */
// Start line: 5090
// Start offset: 0x80024AC8
// Variables:
// 		short *bspTreeFlags; // $v0
/* end block 1 */
// End offset: 0x80024AC8
// End Line: 5090

/* begin block 2 */
// Start line: 12649
/* end block 2 */
// End Line: 12650

void COLLIDE_SetBSPTreeFlag(_CollideInfo *collideInfo, short flag)

{
  ushort *puVar1;

  puVar1 = (ushort *)COLLIDE_GetBSPTreeFlag(collideInfo);
  *puVar1 = *puVar1 | flag;
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ COLLIDE_PointAndTfaceFunc(struct _Terrain *terrain /*$fp*/, struct BSPTree *bsp /*$s6*/, struct _SVector *orgNewPos /*$s7*/, struct _SVector *orgOldPos /*$t4*/, struct _TFace *tface /*stack 16*/, long ignoreAttr /*stack 20*/, long flags /*stack 24*/)
// line 5121, offset 0x80024afc
/* begin block 1 */
// Start line: 5122
// Start offset: 0x80024AFC
// Variables:
// 		struct PandTFScratch *CSpad; // $s0
// 		int result; // stack offset -48

/* begin block 1.1 */
// Start line: 5141
// Start offset: 0x80024B8C
// Variables:
// 		struct _SVector *vertex0; // $s3
// 		struct _SVector *vertex1; // $s4

/* begin block 1.1.1 */
// Start line: 5144
// Start offset: 0x80024B8C
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a1
// 		short _x1; // $a2
// 		short _y1; // $t0
// 		short _z1; // $t2
// 		struct _SVector *_v; // $t1
// 		struct _Position *_v1; // $a3
/* end block 1.1.1 */
// End offset: 0x80024B8C
// End Line: 5144

/* begin block 1.1.2 */
// Start line: 5144
// Start offset: 0x80024B8C
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a1
// 		short _x1; // $a2
// 		short _y1; // $t0
// 		short _z1; // $a3
// 		struct _SVector *_v; // $t3
/* end block 1.1.2 */
// End offset: 0x80024B8C
// End Line: 5144

/* begin block 1.1.3 */
// Start line: 5144
// Start offset: 0x80024B8C
// Variables:
// 		short *nrmlArray; // $a1
// 		struct _SVector *nrml; // $a0

/* begin block 1.1.3.1 */
// Start line: 5144
// Start offset: 0x80024B8C
// Variables:
// 		short *sPtr; // $v1
/* end block 1.1.3.1 */
// End offset: 0x80024CCC
// End Line: 5154
/* end block 1.1.3 */
// End offset: 0x80024CCC
// End Line: 5154

/* begin block 1.1.4 */
// Start line: 5185
// Start offset: 0x80024DE0
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a0
// 		short _x1; // $a1
// 		short _y1; // $a3
// 		short _z1; // $a2
// 		struct _Position *_v1; // $a2
/* end block 1.1.4 */
// End offset: 0x80024DE0
// End Line: 5185
/* end block 1.1 */
// End offset: 0x80024E18
// End Line: 5189
/* end block 1 */
// End offset: 0x80024E1C
// End Line: 5192

/* begin block 2 */
// Start line: 10242
/* end block 2 */
// End Line: 10243

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
COLLIDE_PointAndTfaceFunc(int param_1, int param_2, short *param_3, short *param_4, ushort *param_5, uint param_6,
                          uint param_7)

{
  ushort uVar1;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar2;
  short sVar3;
  int iVar4;
  uint *puVar5;
  ushort *puVar6;
  short sVar7;
  _SVector *v0;
  undefined4 uStack48;

  uStack48 = 0;
  if ((param_5 == (ushort *)0x0) || ((*(ushort *)(param_2 + 0x12) & 2) != 0))
  {
    uStack48 = 0;
  }
  else
  {
    if ((1 << (*(byte *)(param_5 + 3) & 0x1f) & param_6) == 0)
    {
      DAT_1f800040._0_2_ = *param_3 - *(short *)(param_2 + 0xc);
      DAT_1f800040._2_2_ = param_3[1] - *(short *)(param_2 + 0xe);
      DAT_1f800044 = param_3[2] - *(short *)(param_2 + 0x10);
      DAT_1f800046 = *param_4 - *(short *)(param_2 + 0xc);
      DAT_1f800048 = param_4[1] - *(short *)(param_2 + 0xe);
      DAT_1f80004a = param_4[2] - *(short *)(param_2 + 0x10);
      DAT_1f800068 = (short)DAT_1f800040;
      DAT_1f80006a = DAT_1f800040._2_2_;
      DAT_1f80006c._0_2_ = DAT_1f800044;
      DAT_1f800070._0_2_ = DAT_1f800046;
      DAT_1f800070._2_2_ = DAT_1f800048;
      DAT_1f800074._0_2_ = DAT_1f80004a;
      SetRotMatrix(&DAT_1f800040);
      iVar4 = (int)(short)param_5[4];
      if (iVar4 < 0)
      {
        puVar6 = (ushort *)(*(int *)(param_1 + 0x24) + iVar4 * -6);
        _DAT_1f800078 = CONCAT22(-puVar6[1], -(*puVar6 & 0x1fff));
        _DAT_1f80007c = _DAT_1f80007c & 0xffff0000 | (uint)(ushort)-puVar6[2];
      }
      else
      {
        puVar5 = (uint *)(*(int *)(param_1 + 0x24) + iVar4 * 6);
        _DAT_1f800078 = *puVar5 & 0xffff1fff;
        _DAT_1f80007c = _DAT_1f80007c & 0xffff0000 | (uint) * (ushort *)(puVar5 + 1);
      }
      iVar4 = *(int *)(param_1 + 0x1c);
      uVar1 = param_5[1];
      v0 = (_SVector *)(iVar4 + (uint)*param_5 * 0xc);
      setCopControlWord(2, 0x1800, *(undefined4 *)v0);
      setCopControlWord(2, 0x2000, *(undefined4 *)&v0->z);
      setCopReg(2, in_zero, _DAT_1f800078);
      setCopReg(2, in_at, _DAT_1f80007c);
      copFunction(2, 0x486012);
      _DAT_1f800080 = getCopReg(2, 0x19);
      _DAT_1f800084 = getCopReg(2, 0x1a);
      DAT_1f800088 = getCopReg(2, 0x1b);
      _DAT_1f800080 = _DAT_1f800080 - DAT_1f800088;
      _DAT_1f800084 = _DAT_1f800084 - DAT_1f800088;
      if ((((_DAT_1f800080 < 0) && (-1 < _DAT_1f800084)) ||
           (((param_7 & 1) != 0 && ((0 < _DAT_1f800080 && (_DAT_1f800084 < 1)))))) &&
          ((iVar2 = COLLIDE_IntersectLineAndPlane_S(&DAT_1f800060, &DAT_1f800070, &DAT_1f800068, &DAT_1f800078, DAT_1f800088),
            iVar2 != 0 &&
                (iVar4 = COLLIDE_PointInTriangle(v0, (_SVector *)(iVar4 + (uint)uVar1 * 0xc),
                                                 (_SVector *)(*(int *)(param_1 + 0x1c) + (uint)param_5[2] * 0xc),
                                                 (_SVector *)&DAT_1f800060, (_SVector *)&DAT_1f800078),
                 iVar4 != 0))))
      {
        uStack48 = 1;
        sVar3 = DAT_1f800060._2_2_ + *(short *)(param_2 + 0xe);
        sVar7 = DAT_1f800064 + *(short *)(param_2 + 0x10);
        *param_3 = (short)DAT_1f800060 + *(short *)(param_2 + 0xc);
        param_3[1] = sVar3;
        param_3[2] = sVar7;
      }
    }
  }
  return uStack48;
}
