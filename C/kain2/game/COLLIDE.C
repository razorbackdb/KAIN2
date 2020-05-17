#include "THISDUST.H"
#include "COLLIDE.H"


// decompiled code
// original method signature: 
// int /*$ra*/ COLLIDE_PointInTriangle(struct _SVector *v0 /*$a0*/, struct _SVector *v1 /*$a1*/, struct _SVector *v2 /*$a2*/, struct _SVector *point /*$a3*/, struct _SVector *normal /*stack 16*/)
 // line 243, offset 0x8001e818
	/* begin block 1 */
		// Start line: 244
		// Start offset: 0x8001E818
		// Variables:
	// 		struct _Triangle2D *triangle; // $t2
	// 		int nx; // $t1
	// 		int ny; // $v1
	// 		short tx; // $t0
	// 		short ty; // $a3

		/* begin block 1.1 */
			// Start line: 244
			// Start offset: 0x8001E954
			// Variables:
		// 		struct _Triangle2D *tri; // $t2
		// 		short tx; // $t0
		// 		short ty; // $a3

			/* begin block 1.1.1 */
				// Start line: 244
				// Start offset: 0x8001E954
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
					// Start offset: 0x8001E9CC
					// Variables:
				// 		long ydist; // $v0
				// 		long xdist; // $v0
				// 		long xdiff; // $v1
				// 		long ydiff; // $a1
				// 		long ix; // $v1
				/* end block 1.1.1.1 */
				// End offset: 0x8001EA34
				// End Line: 244
			/* end block 1.1.1 */
			// End offset: 0x8001EAB4
			// End Line: 244
		/* end block 1.1 */
		// End offset: 0x8001EAB4
		// End Line: 244
	/* end block 1 */
	// End offset: 0x8001EAB4
	// End Line: 288

	/* begin block 2 */
		// Start line: 369
	/* end block 2 */
	// End Line: 370

	/* begin block 3 */
		// Start line: 486
	/* end block 3 */
	// End Line: 487

int COLLIDE_PointInTriangle(_SVector *v0,_SVector *v1,_SVector *v2,_SVector *point,_SVector *normal)

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
  undefined4 *puVar14;
  undefined4 *puVar15;
  uint uVar16;
  int iVar17;
  
  iVar7 = (int)normal->x;
  iVar9 = (int)normal->y;
  if (iVar7 < 0) {
    iVar7 = -iVar7;
  }
  if (iVar9 < 0) {
    iVar9 = -iVar9;
  }
  if (iVar9 < iVar7) {
    iVar9 = (int)normal->z;
    if (iVar9 < 0) {
      iVar9 = -iVar9;
    }
    if (iVar9 < iVar7) {
      sVar2 = point->y;
      uVar3 = point->z;
      DAT_1f800000 = *(undefined4 *)&v0->y;
      DAT_1f800004 = *(undefined4 *)&v1->y;
      uVar1 = v2->z;
      sVar4 = v2->y;
      goto LAB_8001e94c;
    }
LAB_8001e910:
    sVar2 = point->x;
    uVar3 = point->y;
    DAT_1f800000 = *(undefined4 *)v0;
    DAT_1f800004 = *(undefined4 *)v1;
    uVar1 = v2->y;
  }
  else {
    iVar7 = (int)normal->z;
    if (iVar7 < 0) {
      iVar7 = -iVar7;
    }
    if (iVar9 <= iVar7) goto LAB_8001e910;
    sVar2 = point->x;
    uVar3 = point->z;
    DAT_1f800000 = CONCAT22(v0->z,v0->x);
    DAT_1f800004 = CONCAT22(v1->z,v1->x);
    uVar1 = v2->z;
  }
  sVar4 = v2->x;
LAB_8001e94c:
  DAT_1f800008 = CONCAT22(uVar1,sVar4);
  uVar16 = 0;
  bVar5 = false;
  iVar17 = 3;
  iVar9 = (int)((uint)uVar3 << 0x10) >> 0x10;
  iVar7 = (int)sVar2;
  puVar14 = &DAT_1f800008;
  puVar15 = &DAT_1f800000;
  bVar8 = (int)((uint)uVar3 << 0x10) <= (int)((uint)uVar1 << 0x10);
  do {
    iVar13 = (int)*(short *)((int)puVar15 + 2);
    if (bVar8 == iVar9 <= iVar13) {
      bVar6 = bVar5;
      if ((bVar8 != false) && (iVar9 == (int)*(short *)((int)puVar14 + 2))) {
        if (iVar9 == iVar13) {
          iVar10 = (int)*(short *)puVar15;
          if ((int)*(short *)puVar14 < iVar7 != iVar10 < iVar7) {
            return 1;
          }
          if (iVar7 == (int)*(short *)puVar14) {
            return 1;
          }
        }
        else {
          iVar10 = (int)*(short *)puVar14;
        }
        if (iVar7 == iVar10) {
          return 1;
        }
      }
    }
    else {
      iVar10 = (int)*(short *)puVar14;
      iVar12 = (int)*(short *)puVar15;
      if (iVar7 <= iVar10 == iVar7 <= iVar12) {
        if (iVar7 <= iVar10) {
          uVar16 = (uint)(uVar16 == 0);
        }
      }
      else {
        iVar11 = *(short *)((int)puVar14 + 2) - iVar13;
        iVar10 = (iVar12 - iVar7) * iVar11 - (iVar13 - iVar9) * (iVar10 - iVar12);
        if (iVar11 < 0) {
          iVar11 = -iVar11;
          iVar10 = -iVar10;
        }
        if (iVar11 / 2 < iVar10) {
          uVar16 = (uint)(uVar16 == 0);
        }
        else {
          if (-(iVar11 / 2) <= iVar10) {
            return 1;
          }
        }
      }
      bVar6 = true;
      if (bVar5) {
        return uVar16;
      }
    }
    bVar5 = bVar6;
    iVar17 = iVar17 + -1;
    puVar14 = puVar15;
    puVar15 = puVar15 + 1;
    bVar8 = iVar9 <= iVar13;
    if (iVar17 == 0) {
      return uVar16;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// int /*$ra*/ COLLIDE_PointInTriangle2DPub(short *v0 /*$a0*/, short *v1 /*$a1*/, short *v2 /*$a2*/, short *point /*$a3*/)
 // line 296, offset 0x8001eabc
	/* begin block 1 */
		// Start line: 297
		// Start offset: 0x8001EABC
		// Variables:
	// 		struct _SVector normal; // stack offset -16
	/* end block 1 */
	// End offset: 0x8001EABC
	// End Line: 297

	/* begin block 2 */
		// Start line: 485
	/* end block 2 */
	// End Line: 486

int COLLIDE_PointInTriangle2DPub(short *v0,short *v1,short *v2,short *point)

{
  int iVar1;
  undefined4 local_10;
  undefined *local_c;
  
  local_10 = 0;
  local_c = &DAT_00001000;
  iVar1 = COLLIDE_PointInTriangle
                    ((_SVector *)v0,(_SVector *)v1,(_SVector *)v2,(_SVector *)point,
                     (_SVector *)&local_10);
  return iVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ COLLIDE_GetNormal(short nNum /*$a0*/, short *nrmlArray /*$a1*/, struct _SVector *nrml /*$a2*/)
 // line 312, offset 0x8001eb08
	/* begin block 1 */
		// Start line: 314
		// Start offset: 0x8001EB08
		// Variables:
	// 		short *sPtr; // $a1
	// 		long bitMask; // $v1
	/* end block 1 */
	// End offset: 0x8001EB98
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

long COLLIDE_GetNormal(short nNum,short *nrmlArray,_SVector *nrml)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  
  iVar3 = (int)nNum;
  if (iVar3 < 0) {
    puVar4 = (ushort *)(nrmlArray + iVar3 * 0x7ffffffd);
    uVar1 = *puVar4;
    nrml->x = -(uVar1 & 0x1fff);
    nrml->y = -puVar4[1];
    uVar2 = -puVar4[2];
  }
  else {
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
 // line 368, offset 0x8001eba0
	/* begin block 1 */
		// Start line: 369
		// Start offset: 0x8001EBA0
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
			// Start offset: 0x8001EBA0
			// Variables:
		// 		long _x0; // $t1
		// 		long _y0; // $t2
		// 		long _z0; // $t0
		// 		long _x1; // $a0
		// 		long _y1; // $v0
		// 		long _z1; // $a0
		/* end block 1.1 */
		// End offset: 0x8001EBA0
		// End Line: 369

		/* begin block 1.2 */
			// Start line: 369
			// Start offset: 0x8001EBA0
			// Variables:
		// 		long _x0; // $a0
		// 		long _y0; // $a1
		// 		long _z0; // $a3
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $v0
		/* end block 1.2 */
		// End offset: 0x8001EBA0
		// End Line: 369
	/* end block 1 */
	// End offset: 0x8001ED70
	// End Line: 399

	/* begin block 2 */
		// Start line: 648
	/* end block 2 */
	// End Line: 649

void COLLIDE_MakeNormal(_Terrain *terrain,_TFace *tface,_SVector *normal)

{
  _TVertex *p_Var1;
  int iVar2;
  _TVertex *p_Var3;
  int iVar4;
  _TVertex *p_Var5;
  
  p_Var5 = terrain->vertexList;
  p_Var1 = p_Var5 + (tface->face).v1;
  p_Var3 = p_Var5 + (tface->face).v0;
  DAT_1f800000 = (int)(p_Var1->vertex).x - (int)(p_Var3->vertex).x;
  DAT_1f800004 = (int)(p_Var1->vertex).y - (int)(p_Var3->vertex).y;
  DAT_1f800008 = (int)(p_Var1->vertex).z - (int)(p_Var3->vertex).z;
  p_Var5 = p_Var5 + (tface->face).v2;
  DAT_1f800018 = (int)(p_Var5->vertex).z - (int)(p_Var3->vertex).z;
  DAT_1f800014 = (int)(p_Var5->vertex).y - (int)(p_Var3->vertex).y;
  DAT_1f800010 = (int)(p_Var5->vertex).x - (int)(p_Var3->vertex).x;
  DAT_1f800024 = (int)(short)-(short)(DAT_1f800000 * DAT_1f800018 - DAT_1f800008 * DAT_1f800010 >>
                                     0xc);
  iVar2 = DAT_1f800024;
  if (DAT_1f800024 < 0) {
    iVar2 = -DAT_1f800024;
  }
  DAT_1f800020 = (DAT_1f800004 * DAT_1f800018 - DAT_1f800008 * DAT_1f800014) * 0x10 >> 0x10;
  iVar4 = DAT_1f800020;
  if (DAT_1f800020 < 0) {
    iVar4 = -DAT_1f800020;
  }
  DAT_1f800028 = (DAT_1f800000 * DAT_1f800014 - DAT_1f800004 * DAT_1f800010) * 0x10 >> 0x10;
  if (iVar2 < iVar4) {
    iVar2 = iVar4;
  }
  iVar4 = DAT_1f800028;
  if (DAT_1f800028 < 0) {
    iVar4 = -DAT_1f800028;
  }
  if (iVar2 < iVar4) {
    iVar2 = iVar4;
  }
  if (iVar2 != 0) {
    normal->x = (short)((DAT_1f800020 << 0xc) / iVar2);
    normal->y = (short)((DAT_1f800024 << 0xc) / iVar2);
    normal->z = (short)((DAT_1f800028 << 0xc) / iVar2);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ COLLIDE_UpdateAllTransforms(struct _Instance *instance /*$a0*/, struct SVECTOR *offset /*$a1*/)
 // line 415, offset 0x8001ed78
	/* begin block 1 */
		// Start line: 417
		// Start offset: 0x8001ED78
		// Variables:
	// 		struct MATRIX *swTransform; // $v1

		/* begin block 1.1 */
			// Start line: 421
			// Start offset: 0x8001ED88
			// Variables:
		// 		int i; // $a2
		// 		long numMatrices; // $v0
		// 		long ox; // $t1
		// 		long oy; // $t0
		// 		long oz; // $a1
		/* end block 1.1 */
		// End offset: 0x8001EE40
		// End Line: 447
	/* end block 1 */
	// End offset: 0x8001EE40
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

void COLLIDE_UpdateAllTransforms(_Instance *instance,SVECTOR *offset)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  MATRIX *pMVar5;
  int *piVar6;
  Object *pOVar7;
  
  if (instance->matrix != (MATRIX *)0x0) {
    sVar1 = offset->vx;
    pOVar7 = instance->object;
    sVar2 = offset->vy;
    sVar3 = offset->vz;
    if ((pOVar7->animList == (_G2AnimKeylist_Type **)0x0) || ((pOVar7->oflags2 & 0x40000000U) != 0))
    {
      pMVar5 = instance->matrix;
      iVar4 = instance->object->modelList[instance->currentModel]->numSegments;
    }
    else {
      pMVar5 = instance->matrix + -1;
      iVar4 = pOVar7->modelList[instance->currentModel]->numSegments + 1;
    }
    piVar6 = pMVar5->t + 2;
    while (iVar4 != 0) {
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
 // line 450, offset 0x8001ee48
	/* begin block 1 */
		// Start line: 452
		// Start offset: 0x8001EE48
		// Variables:
	// 		struct MATRIX *swTransform; // $v1

		/* begin block 1.1 */
			// Start line: 456
			// Start offset: 0x8001EE58
			// Variables:
		// 		int i; // $a2
		// 		long ox; // $t1
		// 		long oy; // $t0
		// 		long oz; // $a1
		// 		long numMatrices; // $v0
		/* end block 1.1 */
		// End offset: 0x8001EF10
		// End Line: 480
	/* end block 1 */
	// End offset: 0x8001EF10
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

void COLLIDE_MoveAllTransforms(_Instance *instance,_Position *offset)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  MATRIX *pMVar5;
  int *piVar6;
  Object *pOVar7;
  
  if (instance->oldMatrix != (MATRIX *)0x0) {
    sVar1 = offset->x;
    pOVar7 = instance->object;
    sVar2 = offset->y;
    sVar3 = offset->z;
    if ((pOVar7->animList == (_G2AnimKeylist_Type **)0x0) || ((pOVar7->oflags2 & 0x40000000U) != 0))
    {
      pMVar5 = instance->oldMatrix;
      iVar4 = instance->object->modelList[instance->currentModel]->numSegments;
    }
    else {
      pMVar5 = instance->oldMatrix + -1;
      iVar4 = pOVar7->modelList[instance->currentModel]->numSegments + 1;
    }
    piVar6 = pMVar5->t + 2;
    while (iVar4 != 0) {
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
 // line 590, offset 0x8001ef18
	/* begin block 1 */
		// Start line: 1180
	/* end block 1 */
	// End Line: 1181

	/* begin block 2 */
		// Start line: 1070
	/* end block 2 */
	// End Line: 1071

long COLLIDE_WithinYZBounds(_SVector *point,_HBox *hbox)

{
  uint uVar1;
  
  uVar1 = 0;
  if (((hbox->minY <= point->y) && (point->y <= hbox->maxY)) && (hbox->minZ <= point->z)) {
    uVar1 = (uint)(hbox->maxZ < point->z) ^ 1;
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ COLLIDE_WithinXZBounds(struct _SVector *point /*$a0*/, struct _HBox *hbox /*$a1*/)
 // line 596, offset 0x8001ef74
	/* begin block 1 */
		// Start line: 1081
	/* end block 1 */
	// End Line: 1082

	/* begin block 2 */
		// Start line: 1082
	/* end block 2 */
	// End Line: 1083

long COLLIDE_WithinXZBounds(_SVector *point,_HBox *hbox)

{
  uint uVar1;
  
  uVar1 = 0;
  if (((hbox->minX <= point->x) && (point->x <= hbox->maxX)) && (hbox->minZ <= point->z)) {
    uVar1 = (uint)(hbox->maxZ < point->z) ^ 1;
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ COLLIDE_WithinXYBounds(struct _SVector *point /*$a0*/, struct _HBox *hbox /*$a1*/)
 // line 602, offset 0x8001efd0
	/* begin block 1 */
		// Start line: 1093
	/* end block 1 */
	// End Line: 1094

	/* begin block 2 */
		// Start line: 1094
	/* end block 2 */
	// End Line: 1095

long COLLIDE_WithinXYBounds(_SVector *point,_HBox *hbox)

{
  uint uVar1;
  
  uVar1 = 0;
  if (((hbox->minX <= point->x) && (point->x <= hbox->maxX)) && (hbox->minY <= point->y)) {
    uVar1 = (uint)(hbox->maxY < point->y) ^ 1;
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ COLLIDE_LineWithBoxFace(short startDist /*$a0*/, long lineDist /*$a1*/, short planeDist /*$a2*/, struct _SVector *start /*$a3*/, struct _Vector *line /*stack 16*/, struct _HBox *hbox /*stack 20*/, TDRFuncPtr_COLLIDE_LineWithBoxFace6collideBoundFunc collideBoundFunc /*stack 24*/, struct _SVector *normal /*stack 28*/)
 // line 611, offset 0x8001f02c
	/* begin block 1 */
		// Start line: 612
		// Start offset: 0x8001F02C
		// Variables:
	// 		struct _SVector point; // stack offset -24
	// 		long t; // stack offset -16

		/* begin block 1.1 */
			// Start line: 612
			// Start offset: 0x8001F0F0
			// Variables:
		// 		struct _SVector *point; // $t1
		// 		struct _SVector *normal; // $s0
		// 		struct _SVector *point0; // $a2
		// 		struct _SVector *normal0; // $a3
		// 		struct _SVector *point1; // $a1
		// 		struct _SVector *normal1; // $t0

			/* begin block 1.1.1 */
				// Start line: 612
				// Start offset: 0x8001F0F0

				/* begin block 1.1.1.1 */
					// Start line: 612
					// Start offset: 0x8001F114
					// Variables:
				// 		short _z1; // $a0
				// 		short _y1; // $v1
				// 		short _x1; // $v0
				/* end block 1.1.1.1 */
				// End offset: 0x8001F114
				// End Line: 612

				/* begin block 1.1.1.2 */
					// Start line: 612
					// Start offset: 0x8001F114
					// Variables:
				// 		short _z1; // $a0
				// 		short _y1; // $v1
				// 		short _x1; // $v0
				/* end block 1.1.1.2 */
				// End offset: 0x8001F114
				// End Line: 612

				/* begin block 1.1.1.3 */
					// Start line: 612
					// Start offset: 0x8001F114
					// Variables:
				// 		short _z1; // $a0
				// 		short _y1; // $v1
				// 		short _x1; // $v0
				/* end block 1.1.1.3 */
				// End offset: 0x8001F114
				// End Line: 612

				/* begin block 1.1.1.4 */
					// Start line: 612
					// Start offset: 0x8001F114
					// Variables:
				// 		short _z1; // $a0
				// 		short _y1; // $v1
				// 		short _x1; // $v0
				/* end block 1.1.1.4 */
				// End offset: 0x8001F114
				// End Line: 612

				/* begin block 1.1.1.5 */
					// Start line: 612
					// Start offset: 0x8001F194
					// Variables:
				// 		short _z1; // $a0
				// 		short _y1; // $v1
				// 		short _x1; // $v0
				/* end block 1.1.1.5 */
				// End offset: 0x8001F194
				// End Line: 612

				/* begin block 1.1.1.6 */
					// Start line: 612
					// Start offset: 0x8001F194
					// Variables:
				// 		short _z1; // $a0
				// 		short _y1; // $v1
				// 		short _x1; // $v0
				/* end block 1.1.1.6 */
				// End offset: 0x8001F194
				// End Line: 612
			/* end block 1.1.1 */
			// End offset: 0x8001F1C8
			// End Line: 612
		/* end block 1.1 */
		// End offset: 0x8001F1C8
		// End Line: 612
	/* end block 1 */
	// End offset: 0x8001F1C8
	// End Line: 643

	/* begin block 2 */
		// Start line: 1111
	/* end block 2 */
	// End Line: 1112

void COLLIDE_LineWithBoxFace
               (short startDist,long lineDist,short planeDist,_SVector *start,_Vector *line,
               _HBox *hbox,TDRFuncPtr_COLLIDE_LineWithBoxFace6collideBoundFunc collideBoundFunc,
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
  
  if (lineDist != 0) {
    local_10 = (undefined *)((((int)startDist - (int)planeDist) * -0x1000) / lineDist);
    if (local_10 < &DAT_00001001) {
      local_18 = start->x + (short)(line->x * (int)local_10 >> 0xc);
      local_16 = start->y + (short)(line->y * (int)local_10 >> 0xc);
      local_14 = start->z + (short)(line->z * (int)local_10 >> 0xc);
      lVar7 = (*collideBoundFunc)(&local_18,hbox);
      p_Var6 = collide_normal1;
      p_Var5 = collide_normal0;
      p_Var4 = collide_point1;
      p_Var3 = collide_point0;
      if (lVar7 != 0) {
        if ((int)local_10 < collide_t0) {
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
        else {
          if ((int)local_10 < collide_t1) {
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
 // line 650, offset 0x8001f1d8
	/* begin block 1 */
		// Start line: 651
		// Start offset: 0x8001F1D8
		// Variables:
	// 		struct _SVector normal; // stack offset -64
	// 		struct _Vector line; // stack offset -56

		/* begin block 1.1 */
			// Start line: 651
			// Start offset: 0x8001F1D8
			// Variables:
		// 		long _x0; // $a1
		// 		long _y0; // $a2
		// 		long _z0; // $a0
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $v1
		// 		struct _Vector *_v; // $s3
		/* end block 1.1 */
		// End offset: 0x8001F1D8
		// End Line: 651
	/* end block 1 */
	// End offset: 0x8001F428
	// End Line: 711

	/* begin block 2 */
		// Start line: 1201
	/* end block 2 */
	// End Line: 1202

/* WARNING: Could not reconcile some variable overlaps */

long COLLIDE_IntersectLineAndBox
               (_SVector *point0,_SVector *normal0,_SVector *point1,_SVector *normal1,_SVector *end,
               _SVector *start,_HBox *hbox)

{
  uint uVar1;
  _SVector local_40;
  int local_38;
  int local_34;
  int local_30;
  
  collide_t0 = (long)&DAT_00001001;
  collide_t1 = (long)&DAT_00001001;
  local_38 = (int)end->x - (int)start->x;
  local_30 = (int)end->z - (int)start->z;
  local_34 = (int)end->y - (int)start->y;
  local_40.x = -0x1000;
  local_40.y = 0;
  local_40.z = 0;
  collide_point0 = point0;
  collide_point1 = point1;
  collide_normal0 = normal0;
  collide_normal1 = normal1;
  COLLIDE_LineWithBoxFace
            (-start->x,-local_38,-hbox->minX,start,(_Vector *)&local_38,hbox,COLLIDE_WithinYZBounds,
             &local_40);
  local_40.x = 0x1000;
  local_40.y = 0;
  local_40.z = 0;
  COLLIDE_LineWithBoxFace
            (start->x,local_38,hbox->maxX,start,(_Vector *)&local_38,hbox,COLLIDE_WithinYZBounds,
             &local_40);
  local_40.x = 0;
  local_40.y = -0x1000;
  local_40.z = 0;
  COLLIDE_LineWithBoxFace
            (-start->y,(int)-(short)local_34,-hbox->minY,start,(_Vector *)&local_38,hbox,
             COLLIDE_WithinXZBounds,&local_40);
  local_40.x = 0;
  local_40.y = 0x1000;
  local_40.z = 0;
  COLLIDE_LineWithBoxFace
            (start->y,local_34,hbox->maxY,start,(_Vector *)&local_38,hbox,COLLIDE_WithinXZBounds,
             &local_40);
  local_40.x = 0;
  local_40.y = 0;
  local_40.z = -0x1000;
  COLLIDE_LineWithBoxFace
            (-start->z,(int)-(short)local_30,-hbox->minZ,start,(_Vector *)&local_38,hbox,
             COLLIDE_WithinXYBounds,&local_40);
  local_40.x = 0;
  local_40.y = 0;
  local_40.z = 0x1000;
  COLLIDE_LineWithBoxFace
            (start->z,local_30,hbox->maxZ,start,(_Vector *)&local_38,hbox,COLLIDE_WithinXYBounds,
             &local_40);
  if ((undefined *)collide_t1 == &DAT_00001001) {
    uVar1 = (uint)((undefined *)collide_t0 != &DAT_00001001);
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// struct _TFace * /*$ra*/ COLLIDE_PointAndTerrain(struct _Terrain *terrain /*$a0*/, struct _PCollideInfo *pcollideInfo /*$a1*/, struct _LCollideInfo *lcol /*$a2*/)
 // line 770, offset 0x8001f454
	/* begin block 1 */
		// Start line: 1519
	/* end block 1 */
	// End Line: 1520

_TFace * COLLIDE_PointAndTerrain(_Terrain *terrain,_PCollideInfo *pcollideInfo,_LCollideInfo *lcol)

{
  _TFace *p_Var1;
  
  p_Var1 = COLLIDE_PointAndTerrainFunc(terrain,pcollideInfo,0,(short *)0x0,0,0,lcol);
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct _TFace * /*$ra*/ COLLIDE_PointAndTerrainFunc(struct _Terrain *terrain /*$t2*/, struct _PCollideInfo *pCollideInfo /*stack 4*/, int Flags /*$a2*/, short *Backface_Flag /*$a3*/, long ignoreAttr /*stack 16*/, long acceptAttr /*stack 20*/, struct _LCollideInfo *lcolinfo /*stack 24*/)
 // line 780, offset 0x8001f484
	/* begin block 1 */
		// Start line: 781
		// Start offset: 0x8001F484
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
			// Start offset: 0x8001F484
			// Variables:
		// 		short _x1; // $a3
		// 		short _y1; // $t0
		// 		short _z1; // $t1
		// 		struct _SVector *_v0; // $v1
		/* end block 1.1 */
		// End offset: 0x8001F484
		// End Line: 781

		/* begin block 1.2 */
			// Start line: 781
			// Start offset: 0x8001F484
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _SVector *_v0; // $a2
		/* end block 1.2 */
		// End offset: 0x8001F484
		// End Line: 781

		/* begin block 1.3 */
			// Start line: 781
			// Start offset: 0x8001F484
			// Variables:
		// 		struct _SVector *_v; // $a1
		/* end block 1.3 */
		// End offset: 0x8001F484
		// End Line: 781

		/* begin block 1.4 */
			// Start line: 837
			// Start offset: 0x8001F5E4
			// Variables:
		// 		struct BSPTree *bsp; // $s4

			/* begin block 1.4.1 */
				// Start line: 865
				// Start offset: 0x8001F6E0
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
			// End offset: 0x8001F6E0
			// End Line: 865

			/* begin block 1.4.2 */
				// Start line: 865
				// Start offset: 0x8001F6E0
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a0
			// 		short _x1; // $a1
			// 		short _y1; // $a2
			// 		short _z1; // $a3
			// 		struct _SVector *_v; // $s5
			/* end block 1.4.2 */
			// End offset: 0x8001F6E0
			// End Line: 865

			/* begin block 1.4.3 */
				// Start line: 898
				// Start offset: 0x8001F910
				// Variables:
			// 		struct _TFace *tface; // $s3

				/* begin block 1.4.3.1 */
					// Start line: 905
					// Start offset: 0x8001F95C
					// Variables:
				// 		struct _SVector *vertex0; // $a0

					/* begin block 1.4.3.1.1 */
						// Start line: 781
						// Start offset: 0x8001F9E4
						// Variables:
					// 		short *nrmlArray; // $a0
					// 		struct _SVector *nrml; // $a1

						/* begin block 1.4.3.1.1.1 */
							// Start line: 781
							// Start offset: 0x8001F9E4
							// Variables:
						// 		short *sPtr; // $v1
						/* end block 1.4.3.1.1.1 */
						// End offset: 0x8001FA74
						// End Line: 781
					/* end block 1.4.3.1.1 */
					// End offset: 0x8001FA74
					// End Line: 781

					/* begin block 1.4.3.1.2 */
						// Start line: 781
						// Start offset: 0x8001FB20
						// Variables:
					// 		struct _SVector *point; // $t0
					// 		struct _SVector *start; // $a3
					// 		struct _SVector *line; // $a2

						/* begin block 1.4.3.1.2.1 */
							// Start line: 781
							// Start offset: 0x8001FB20
							// Variables:
						// 		long len; // $v1
						// 		long t; // $a1
						/* end block 1.4.3.1.2.1 */
						// End offset: 0x8001FB58
						// End Line: 781
					/* end block 1.4.3.1.2 */
					// End offset: 0x8001FB58
					// End Line: 781

					/* begin block 1.4.3.1.3 */
						// Start line: 950
						// Start offset: 0x8001FC84
						// Variables:
					// 		short _x0; // $v0
					// 		short _y0; // $v1
					// 		short _z0; // $a1
					// 		short _x1; // $a0
					// 		short _y1; // $a3
					// 		short _z1; // $a2
					// 		struct _Position *_v1; // $a2
					/* end block 1.4.3.1.3 */
					// End offset: 0x8001FC84
					// End Line: 950

					/* begin block 1.4.3.1.4 */
						// Start line: 1015
						// Start offset: 0x8001FD28
						// Variables:
					// 		short _x0; // $v0
					// 		short _y0; // $v1
					// 		short _z0; // $a1
					// 		short _x1; // $a0
					// 		short _y1; // $a2
					// 		short _z1; // $a3
					// 		struct _SVector *_v; // $fp
					/* end block 1.4.3.1.4 */
					// End offset: 0x8001FD28
					// End Line: 1015
				/* end block 1.4.3.1 */
				// End offset: 0x8001FDAC
				// End Line: 1036
			/* end block 1.4.3 */
			// End offset: 0x8001FDEC
			// End Line: 1049

			/* begin block 1.4.4 */
				// Start line: 1053
				// Start offset: 0x8001FDEC
				// Variables:
			// 		int plane_front_error; // $v1
			// 		int plane_back_error; // $a0
			/* end block 1.4.4 */
			// End offset: 0x8001FF3C
			// End Line: 1120

			/* begin block 1.4.5 */
				// Start line: 1124
				// Start offset: 0x8001FF4C
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a0
			// 		short _x1; // $a1
			// 		short _y1; // $a2
			// 		short _z1; // $t0
			// 		struct _Position *_v1; // $a3
			/* end block 1.4.5 */
			// End offset: 0x8001FF4C
			// End Line: 1124

			/* begin block 1.4.6 */
				// Start line: 1124
				// Start offset: 0x8001FF4C
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a0
			// 		short _x1; // $a1
			// 		short _y1; // $a2
			// 		short _z1; // $a3
			/* end block 1.4.6 */
			// End offset: 0x8001FFB0
			// End Line: 1125
		/* end block 1.4 */
		// End offset: 0x8001FFB0
		// End Line: 1126

		/* begin block 1.5 */
			// Start line: 1127
			// Start offset: 0x8001FFC8
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $v0
		// 		struct _SVector *_v1; // $v0
		/* end block 1.5 */
		// End offset: 0x8001FFC8
		// End Line: 1127
	/* end block 1 */
	// End offset: 0x8001FFC8
	// End Line: 1127

	/* begin block 2 */
		// Start line: 1540
	/* end block 2 */
	// End Line: 1541

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

_TFace * COLLIDE_PointAndTerrainFunc
                   (_Terrain *terrain,_PCollideInfo *pCollideInfo,int Flags,short *Backface_Flag,
                   long ignoreAttr,long acceptAttr,_LCollideInfo *lcolinfo)

{
  uchar uVar1;
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
  _DAT_1f80006c = ignoreAttr;
  DAT_1f800070 = acceptAttr;
  DAT_1f800098 = terrain->normalList;
  DAT_1f80009c = terrain->vertexList;
  DAT_1f8000a0 = (_TFace *)0x0;
  DAT_1f800078 = *(undefined4 *)pSVar12;
  DAT_1f80007c = DAT_1f80007c & 0xffff0000 | (uint)(ushort)pSVar12->vz;
  DAT_1f800080._0_2_ = pSVar10->vx;
  DAT_1f800080._2_2_ = pSVar10->vy;
  DAT_1f800084._0_2_ = pSVar10->vz;
  DAT_1f8000a4 = (short)DAT_1f800080 - pSVar12->vx;
  DAT_1f8000a6 = DAT_1f800080._2_2_ - pSVar12->vy;
  DAT_1f8000a8 = (short)DAT_1f800084 - pSVar12->vz;
  p_Var14 = (_BSPNode *)&DAT_1f8000ac;
  if (gameTrackerX.gameData.asmData.MorphTime == 1000) {
    DAT_1f800094 = (int)gameTrackerX.gameData.asmData.MorphType;
    if (DAT_1f800094 != 1) {
      DAT_1f800094 = 0;
    }
  }
  else {
    DAT_1f800094 = 2;
    DAT_1f800090 = 0x800;
  }
  DAT_1f800074 = Backface_Flag;
  DAT_1f800088 = Flags;
  if (Backface_Flag != (short *)0x0) {
    *Backface_Flag = 0;
  }
  local_30 = 0;
  if (0 < terrain->numBSPTrees) {
    do {
      pBVar5 = terrain->BSPTreeArray;
      *(_BSPNode **)&(p_Var14->sphere).position = p_Var14;
      pBVar5 = pBVar5 + local_30;
      if ((-1 < pBVar5->ID) &&
         (((uVar9 = pBVar5->flags, (uVar9 & 2) == 0 || ((pCollideInfo->collideType & 0x80U) != 0))
          || (((uVar9 & 0x40) != 0 && ((pCollideInfo->collideType & 0x100U) != 0)))))) {
        uVar1 = gameTrackerX.plan_collide_override;
        if ((uVar9 & 0x4100) == 0x4100) {
code_r0x8001f698:
          if (uVar1 != '\0') {
LAB_8001f6a0:
            if ((((pBVar5->flags & 0x1000U) == 0) || ((_DAT_1f80006c & 0x10) == 0)) &&
               (((pBVar5->flags & 0x2000U) == 0 || (gameTrackerX.monster_collide_override != '\0')))
               ) {
              DAT_1f800078._0_2_ = (short)DAT_1f800078 - (pBVar5->globalOffset).x;
              DAT_1f800078._2_2_ = DAT_1f800078._2_2_ - (pBVar5->globalOffset).y;
              uVar9 = (short)DAT_1f80007c - (pBVar5->globalOffset).z;
              DAT_1f80007c = DAT_1f80007c & 0xffff0000 | (uint)uVar9;
              DAT_1f800080._0_2_ = (short)DAT_1f800080 - (pBVar5->globalOffset).x;
              DAT_1f800080._2_2_ = DAT_1f800080._2_2_ - (pBVar5->globalOffset).y;
              DAT_1f800084._0_2_ = (short)DAT_1f800084 - (pBVar5->globalOffset).z;
              _DAT_1f800030 = CONCAT22(DAT_1f800078._2_2_,(short)DAT_1f800078);
              DAT_1f800034 = CONCAT22((short)DAT_1f800080,uVar9);
              DAT_1f800038 = CONCAT22((short)DAT_1f800084,DAT_1f800080._2_2_);
              setCopControlWord(2,0,_DAT_1f800030);
              setCopControlWord(2,0x800,DAT_1f800034);
              setCopControlWord(2,0x1000,DAT_1f800038);
              setCopControlWord(2,0x1800,DAT_1f80003c);
              setCopControlWord(2,0x2000,_DAT_1f800040);
              p_Var6 = pBVar5->bspRoot;
              p_Var14 = (_BSPNode *)&(p_Var14->sphere).position.z;
              *(_BSPNode **)&(p_Var14->sphere).position = p_Var6;
              p_Var13 = p_Var14;
              if (p_Var6 != p_Var14) {
                do {
                  iVar11 = *(int *)&(p_Var13->sphere).position;
                  p_Var14 = (_BSPNode *)&p_Var13[-1].front_material_error;
                  if ((*(ushort *)(iVar11 + 0xe) & 2) == 0) {
                    setCopReg(2,in_zero,*(undefined4 *)(iVar11 + 8));
                    setCopReg(2,in_at,*(undefined4 *)(iVar11 + 0xc));
                    copFunction(2,0x486012);
                    DAT_1f800058 = getCopReg(2,0x19);
                    _DAT_1f80005c = getCopReg(2,0x1a);
                    _DAT_1f800060 = getCopReg(2,0x1b);
                    DAT_1f800058 = DAT_1f800058 - *(int *)(iVar11 + 0x10);
                    _DAT_1f80005c = _DAT_1f80005c - *(int *)(iVar11 + 0x10);
                    if (DAT_1f800094 == 0) {
                      sVar2 = *(short *)(iVar11 + 0x28);
                      sVar3 = *(short *)(iVar11 + 0x2a);
                    }
                    else {
                      sVar2 = *(short *)(iVar11 + 0x24);
                      sVar3 = *(short *)(iVar11 + 0x26);
                    }
                    if (_DAT_1f80005c < (int)sVar2 + 5) {
                      if ((int)sVar3 + -5 < _DAT_1f80005c) {
                        if (DAT_1f800058 < _DAT_1f80005c) goto LAB_8001ff0c;
                        if (*(int *)(iVar11 + 0x14) != 0) {
                          *(int *)&(p_Var13->sphere).position = *(int *)(iVar11 + 0x14);
                          p_Var14 = p_Var13;
                        }
                        iVar11 = *(int *)(iVar11 + 0x18);
                      }
                      else {
                        if (((int)sVar3 + -5 <= DAT_1f800058) && (*(int *)(iVar11 + 0x14) != 0)) {
                          *(int *)&(p_Var13->sphere).position = *(int *)(iVar11 + 0x14);
                          p_Var14 = p_Var13;
                        }
                        iVar11 = *(int *)(iVar11 + 0x18);
                      }
                    }
                    else {
                      if (DAT_1f800058 <= (int)sVar2 + 5) {
LAB_8001ff0c:
                        if (*(int *)(iVar11 + 0x18) != 0) {
                          *(int *)&(p_Var13->sphere).position = *(int *)(iVar11 + 0x18);
                          p_Var14 = p_Var13;
                        }
                      }
                      iVar11 = *(int *)(iVar11 + 0x14);
                    }
                    if (iVar11 != 0) {
                      p_Var14 = (_BSPNode *)&(p_Var14->sphere).position.z;
                      *(int *)&(p_Var14->sphere).position = iVar11;
                    }
                  }
                  else {
                    iVar7 = *(short *)(iVar11 + 0x16) + DAT_1f800090;
                    if (((DAT_1f800030 <= iVar7) || (DAT_1f800034._2_2_ <= iVar7)) &&
                       ((iVar7 = *(short *)(iVar11 + 0x10) - DAT_1f800090, iVar7 <= DAT_1f800030 ||
                        (iVar7 <= DAT_1f800034._2_2_)))) {
                      iVar7 = *(short *)(iVar11 + 0x18) + DAT_1f800090;
                      if (((DAT_1f800032 <= iVar7) || ((short)DAT_1f800038 <= iVar7)) &&
                         ((iVar7 = *(short *)(iVar11 + 0x12) - DAT_1f800090, iVar7 <= DAT_1f800032
                          || (iVar7 <= (short)DAT_1f800038)))) {
                        iVar7 = *(short *)(iVar11 + 0x1a) + DAT_1f800090;
                        if ((((short)DAT_1f800034 <= iVar7) || (DAT_1f800038._2_2_ <= iVar7)) &&
                           ((iVar7 = *(short *)(iVar11 + 0x14) - DAT_1f800090,
                            iVar7 <= (short)DAT_1f800034 || (iVar7 <= DAT_1f800038._2_2_)))) {
                          _DAT_1f80008c = (int)*(short *)(iVar11 + 0xc);
                          tface = *(_TFace **)(iVar11 + 8);
                          if (_DAT_1f80008c != 0) {
                            pbVar15 = &tface->attr;
                            do {
                              if (((*pbVar15 & _DAT_1f80006c) == 0) ||
                                 ((*pbVar15 & DAT_1f800070) != 0)) {
                                if ((DAT_1f800094 == 2) &&
                                   ((uint)*(ushort *)(pbVar15 + 2) !=
                                    (int)terrain->morphNormalIdx
                                         [(int)((int)tface - (int)terrain->faceList) * -0x55555555
                                          >> 2])) {
                                  COLLIDE_MakeNormal(terrain,tface,(_SVector *)&DAT_1f800050);
                                }
                                else {
                                  iVar11 = (int)*(short *)(pbVar15 + 2);
                                  if (iVar11 < 0) {
                                    p_Var8 = (_Normal *)((int)DAT_1f800098 + iVar11 * -6);
                                    _DAT_1f800050 = CONCAT22(-p_Var8->y,-(p_Var8->x & 0x1fffU));
                                    DAT_1f800054 = DAT_1f800054 & 0xffff0000 |
                                                   (uint)(ushort)-p_Var8->z;
                                  }
                                  else {
                                    _DAT_1f800050 =
                                         *(uint *)(&DAT_1f800098->x + iVar11 * 3) & 0xffff1fff;
                                    DAT_1f800054 = DAT_1f800054 & 0xffff0000 |
                                                   (uint)(ushort)(&DAT_1f800098->x + iVar11 * 3)[1];
                                  }
                                }
                                v0 = DAT_1f80009c + (tface->face).v0;
                                setCopControlWord(2,0x1800,*(undefined4 *)&v0->vertex);
                                setCopControlWord(2,0x2000,*(undefined4 *)&(v0->vertex).z);
                                setCopReg(2,in_zero,_DAT_1f800050);
                                setCopReg(2,in_at,DAT_1f800054);
                                copFunction(2,0x486012);
                                DAT_1f800058 = getCopReg(2,0x19);
                                _DAT_1f80005c = getCopReg(2,0x1a);
                                _DAT_1f800060 = getCopReg(2,0x1b);
                                DAT_1f800058 = DAT_1f800058 - _DAT_1f800060;
                                _DAT_1f80005c = _DAT_1f80005c - _DAT_1f800060;
                                if (((DAT_1f800058 < 0) && (-1 < _DAT_1f80005c)) ||
                                   (((DAT_1f800088 & 1) != 0 &&
                                    ((0 < DAT_1f800058 && (_DAT_1f80005c < 1)))))) {
                                  if (DAT_1f800058 - _DAT_1f80005c == 0) {
                                    iVar11 = 0;
                                  }
                                  else {
                                    iVar11 = (_DAT_1f80005c * 0x1000) /
                                             (DAT_1f800058 - _DAT_1f80005c);
                                  }
                                  _DAT_1f800064 =
                                       CONCAT22(DAT_1f800080._2_2_ +
                                                (short)(DAT_1f8000a6 * iVar11 >> 0xc),
                                                (short)DAT_1f800080 +
                                                (short)(DAT_1f8000a4 * iVar11 >> 0xc));
                                  _DAT_1f800068 =
                                       _DAT_1f800068 & 0xffff0000 |
                                       (uint)(ushort)((short)DAT_1f800084 +
                                                     (short)(DAT_1f8000a8 * iVar11 >> 0xc));
                                  iVar11 = COLLIDE_PointInTriangle
                                                     ((_SVector *)v0,
                                                      (_SVector *)
                                                      (DAT_1f80009c + *(ushort *)(pbVar15 + -4)),
                                                      (_SVector *)
                                                      (DAT_1f80009c + *(ushort *)(pbVar15 + -2)),
                                                      (_SVector *)&DAT_1f800064,
                                                      (_SVector *)&DAT_1f800050);
                                  if (iVar11 != 0) {
                                    if ((((DAT_1f800074 != (short *)0x0) &&
                                         ((DAT_1f800088 & 1) != 0)) && (0 < DAT_1f800058)) &&
                                       (_DAT_1f80005c < 1)) {
                                      *DAT_1f800074 = 1;
                                    }
                                    if ((*pbVar15 & 8) == 0) {
                                      if (((*(ushort *)(pbVar15 + 4) == 0xffff) ||
                                          ((*(ushort *)
                                             ((int)&terrain->StartTextureList->attr +
                                             (uint)*(ushort *)(pbVar15 + 4)) & 0x2000) == 0)) ||
                                         ((*pbVar15 & DAT_1f800070) != 0)) {
                                        DAT_1f80007c = _DAT_1f800068;
                                        DAT_1f80007c._0_2_ = (short)_DAT_1f800068;
                                        DAT_1f800078 = _DAT_1f800064;
                                        _DAT_1f800030 = _DAT_1f800064;
                                        DAT_1f800078._0_2_ = (short)_DAT_1f800064;
                                        DAT_1f800034 = DAT_1f800034 & 0xffff0000 |
                                                       _DAT_1f800068 & 0xffff;
                                        DAT_1f800078._2_2_ = (short)((uint)_DAT_1f800064 >> 0x10);
                                        DAT_1f8000a4 = (short)DAT_1f800080 - (short)DAT_1f800078;
                                        DAT_1f8000a6 = DAT_1f800080._2_2_ - DAT_1f800078._2_2_;
                                        DAT_1f8000a8 = (short)DAT_1f800084 - (short)DAT_1f80007c;
                                        DAT_1f8000a0 = tface;
                                        if (lcolinfo != (_LCollideInfo *)0x0) {
                                          lcolinfo->tface = tface;
                                          lcolinfo->terrain = terrain;
                                          lcolinfo->curTree = local_30;
                                        }
                                      }
                                    }
                                    else {
                                      if ((gameTrackerX.gameFlags & 0x8000U) != 0) {
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
                                    setCopControlWord(2,0,_DAT_1f800030);
                                    setCopControlWord(2,0x800,DAT_1f800034);
                                  }
                                }
                              }
                              pbVar15 = pbVar15 + 0xc;
                              tface = tface + 1;
                              _DAT_1f80008c = _DAT_1f80008c + -1;
                            } while (_DAT_1f80008c != 0);
                          }
                          if ((DAT_1f8000a0 != (_TFace *)0x0) && (DAT_1f800094 == 0)) {
                            *(_BSPNode **)&(p_Var14->sphere).position = p_Var14;
                          }
                        }
                      }
                    }
                  }
                  p_Var13 = p_Var14;
                } while (*(_BSPNode **)&(p_Var14->sphere).position != p_Var14);
              }
              DAT_1f800078 = CONCAT22(DAT_1f800078._2_2_ + (pBVar5->globalOffset).y,
                                      (short)DAT_1f800078 + (pBVar5->globalOffset).x);
              DAT_1f80007c = DAT_1f80007c & 0xffff0000 |
                             (uint)(ushort)((short)DAT_1f80007c + (pBVar5->globalOffset).z);
              DAT_1f800080._0_2_ = (short)DAT_1f800080 + (pBVar5->globalOffset).x;
              DAT_1f800080._2_2_ = DAT_1f800080._2_2_ + (pBVar5->globalOffset).y;
              DAT_1f800084._0_2_ = (short)DAT_1f800084 + (pBVar5->globalOffset).z;
            }
          }
        }
        else {
          if (((uVar9 & 0x100) == 0) || (gameTrackerX.block_collide_override != '\0')) {
            uVar1 = gameTrackerX.raziel_collide_override;
            if ((uVar9 & 0x4000) != 0) goto code_r0x8001f698;
            goto LAB_8001f6a0;
          }
        }
      }
      local_30 = local_30 + 1;
    } while (local_30 < terrain->numBSPTrees);
  }
  pSVar12->vx = (short)DAT_1f800078;
  pSVar12->vy = DAT_1f800078._2_2_;
  pSVar12->vz = (short)DAT_1f80007c;
  return DAT_1f8000a0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ COLLIDE_PointAndHFace(struct _SVector *newPos /*$s4*/, struct _SVector *oldPos /*$s6*/, struct _HFace *hface /*$s5*/, struct _Model *model /*$s7*/, struct _SVector *hfNormal /*stack 16*/)
 // line 1330, offset 0x8002001c
	/* begin block 1 */
		// Start line: 1331
		// Start offset: 0x8002001C
		// Variables:
	// 		struct MATRIX *posMatrix; // $s1
	// 		struct _SVector *normal; // $s3
	// 		struct _Vector *dpv; // $s2
	// 		struct _SVector *planePoint; // stack offset -48
	// 		struct _SVector *vertex0; // $s0
	// 		struct _SVector *vertex1; // $s1

		/* begin block 1.1 */
			// Start line: 1341
			// Start offset: 0x80020088
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		/* end block 1.1 */
		// End offset: 0x80020088
		// End Line: 1341

		/* begin block 1.2 */
			// Start line: 1341
			// Start offset: 0x80020088
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _SVector *_v; // $t1
		/* end block 1.2 */
		// End offset: 0x80020088
		// End Line: 1341

		/* begin block 1.3 */
			// Start line: 1341
			// Start offset: 0x80020088
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a1
		// 		struct _SVector *_v0; // $t3
		/* end block 1.3 */
		// End offset: 0x80020088
		// End Line: 1341
	/* end block 1 */
	// End offset: 0x80020234
	// End Line: 1378

	/* begin block 2 */
		// Start line: 3219
	/* end block 2 */
	// End Line: 3220

int COLLIDE_PointAndHFace
              (_SVector *newPos,_SVector *oldPos,_HFace *hface,_Model *model,_SVector *hfNormal)

{
  short sVar1;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar2;
  int iVar3;
  _MVertex *p_Var4;
  _SVector *v0;
  
  COLLIDE_GetNormal(hface->normal,(short *)model->normalList,(_SVector *)&DAT_1f800074);
  p_Var4 = model->vertexList;
  sVar1 = hface->v1;
  v0 = (_SVector *)(p_Var4 + hface->v0);
  DAT_1f800040 = newPos->x - v0->x;
  DAT_1f800042 = newPos->y - v0->y;
  DAT_1f800044 = newPos->z - v0->z;
  DAT_1f800046 = oldPos->x - v0->x;
  DAT_1f800048 = oldPos->y - v0->y;
  DAT_1f80004a = oldPos->z - v0->z;
  DAT_1f80004c = v0->x;
  DAT_1f80004e = v0->y;
  DAT_1f800050 = v0->z;
  SetRotMatrix((undefined4 *)&DAT_1f800040);
  setCopReg(2,in_zero,DAT_1f800074);
  setCopReg(2,in_at,DAT_1f800078);
  copFunction(2,0x486012);
  DAT_1f800080 = getCopReg(2,0x19);
  DAT_1f800084 = getCopReg(2,0x1a);
  DAT_1f800088 = getCopReg(2,0x1b);
  if (DAT_1f800080 < 0) {
    iVar2 = 0;
    if ((DAT_1f800080 < DAT_1f800084) && (-1 < DAT_1f800084)) {
      COLLIDE_IntersectLineAndPlane_S(&DAT_1f800090,oldPos,newPos,&DAT_1f800074,DAT_1f800088);
      iVar3 = COLLIDE_PointInTriangle
                        (v0,(_SVector *)(p_Var4 + sVar1),(_SVector *)(model->vertexList + hface->v2)
                         ,(_SVector *)&DAT_1f800090,(_SVector *)&DAT_1f800074);
      iVar2 = 0;
      if (iVar3 != 0) {
        *(undefined4 *)newPos = DAT_1f800090;
        *(undefined4 *)&newPos->z = DAT_1f800094;
        hfNormal->x = (short)DAT_1f800074;
        hfNormal->y = DAT_1f800074._2_2_;
        iVar2 = 1;
        hfNormal->z = (short)DAT_1f800078;
      }
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ COLLIDE_PointAndInstance(struct _PCollideInfo *pcollideInfo /*$s4*/, struct _Instance *instance /*stack 4*/)
 // line 1389, offset 0x80020264
	/* begin block 1 */
		// Start line: 1390
		// Start offset: 0x80020264
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
			// Start offset: 0x80020384
			// Variables:
		// 		struct _HBox *hbox; // $s0
		// 		struct _HFace *hface; // $s1
		// 		struct _HSphere *hsphere; // $s0

			/* begin block 1.1.1 */
				// Start line: 1419
				// Start offset: 0x80020384
				// TypeDefs:
			// 		struct COLLIDE_258fake tmm
			/* end block 1.1.1 */
			// End offset: 0x80020384
			// End Line: 1419

			/* begin block 1.1.2 */
				// Start line: 1452
				// Start offset: 0x8002053C
				// Variables:
			// 		long len; // $t0

				/* begin block 1.1.2.1 */
					// Start line: 1453
					// Start offset: 0x8002053C
					// Variables:
				// 		long a; // stack offset -104
				// 		long b; // stack offset -100
				// 		long c; // stack offset -96
				/* end block 1.1.2.1 */
				// End offset: 0x8002053C
				// End Line: 1453
			/* end block 1.1.2 */
			// End offset: 0x80020600
			// End Line: 1459

			/* begin block 1.1.3 */
				// Start line: 1488
				// Start offset: 0x800207A8
				// Variables:
			// 		struct _SVector hfNormal; // stack offset -136
			/* end block 1.1.3 */
			// End offset: 0x800207D0
			// End Line: 1494

			/* begin block 1.1.4 */
				// Start line: 1509
				// Start offset: 0x80020808
				// Variables:
			// 		struct _SVector hbNormal; // stack offset -136
			// 		struct _SVector point0; // stack offset -128
			// 		struct _SVector point1; // stack offset -120
			// 		struct _SVector normal1; // stack offset -112

				/* begin block 1.1.4.1 */
					// Start line: 1551
					// Start offset: 0x80020948
					// Variables:
				// 		short _x1; // $v0
				// 		short _y1; // $v1
				// 		short _z1; // $a3
				/* end block 1.1.4.1 */
				// End offset: 0x80020948
				// End Line: 1551
			/* end block 1.1.4 */
			// End offset: 0x80020990
			// End Line: 1561
		/* end block 1.1 */
		// End offset: 0x80020A48
		// End Line: 1580
	/* end block 1 */
	// End offset: 0x80020A68
	// End Line: 1582

	/* begin block 2 */
		// Start line: 3368
	/* end block 2 */
	// End Line: 3369

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void COLLIDE_PointAndInstance(_PCollideInfo *pcollideInfo,_Instance *instance)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  _HBox *hbox;
  _HFace *hface;
  byte *pbVar11;
  _SVector _Stack136;
  _SVector local_80;
  _SVector _Stack120;
  _SVector _Stack112;
  long local_68;
  long local_64;
  long local_60;
  MATRIX *local_5c;
  MATRIX *local_58;
  short *local_54;
  uint *local_50;
  int *local_4c;
  _SVector *local_48;
  uint *local_44;
  undefined4 *local_40;
  _Model *local_3c;
  _HPrim *local_38;
  int local_34;
  uint local_30;
  _SVector *local_2c;
  
  local_58 = (MATRIX *)&DAT_1f8000a0;
  local_54 = &DAT_1f800130;
  local_50 = &DAT_1f800150;
  local_4c = (int *)&DAT_1f800160;
  local_48 = (_SVector *)&DAT_1f8001a0;
  local_44 = (uint *)&DAT_1f8001b0;
  local_40 = &DAT_1f8001c0;
  local_34 = instance->hModelList[instance->currentModel].numHPrims;
  local_38 = instance->hModelList[instance->currentModel].hPrimList;
  local_30 = pcollideInfo->collideType;
  local_3c = instance->object->modelList[instance->currentModel];
  if (local_34 != 0) {
    local_2c = &local_80;
    pbVar11 = &local_38->segment;
    do {
      if (((local_38->hpFlags & 1) != 0) && ((local_38->hpFlags & 8) != 0)) {
        local_5c = instance->matrix + *pbVar11;
        PIPE3D_InvertTransform(local_58,local_5c);
        DAT_1f800114 = local_5c->t[0];
        DAT_1f800118 = local_5c->t[1];
        DAT_1f80011c = local_5c->t[2];
        TransposeMatrix((undefined4 *)local_58,(undefined4 *)&DAT_1f800100);
        SetRotMatrix((undefined4 *)local_58);
        SetTransMatrix((int)local_58);
        RotTrans(pcollideInfo->newPoint,&DAT_1f800190,local_40);
        RotTrans(pcollideInfo->oldPoint,local_54,local_40);
        sVar2 = local_54[2];
        sVar3 = local_54[4];
        local_48->x = *local_54;
        local_48->y = sVar2;
        local_48->z = sVar3;
        DAT_1f8001a8 = DAT_1f800190;
        DAT_1f8001aa = DAT_1f800194;
        DAT_1f8001ac = DAT_1f800198;
        bVar1 = pbVar11[-1];
        if (bVar1 == 2) {
          hface = *(_HFace **)(pbVar11 + 1);
          iVar8 = COLLIDE_PointAndHFace
                            ((_SVector *)&DAT_1f8001a8,local_48,hface,local_3c,&_Stack136);
          if (iVar8 != 0) {
            ApplyMatrixSV(&DAT_1f800100,&_Stack136,&pcollideInfo->wNormal);
            pcollideInfo->type = (ushort)bVar1;
            bVar1 = *pbVar11;
            *(_HFace **)&pcollideInfo->prim = hface;
LAB_80020980:
            pcollideInfo->inst = instance;
LAB_8002098c:
            pcollideInfo->segment = (ushort)bVar1;
          }
        }
        else {
          if (bVar1 < 3) {
            if (((bVar1 == 1) && (puVar10 = *(uint **)(pbVar11 + 1), (*puVar10 & 0x2000) != 0)) &&
               ((local_30 & 0x20) == 0)) {
              COLLIDE_NearestPointOnLine_S
                        (local_44,(uint *)local_48,(uint *)&DAT_1f8001a8,puVar10 + 2);
              DAT_1f800180 = (int)*(short *)local_44 - (int)*(short *)(puVar10 + 2);
              DAT_1f800184 = (int)*(short *)((int)local_44 + 2) - (int)*(short *)((int)puVar10 + 10)
              ;
              DAT_1f800188 = (int)*(short *)(local_44 + 1) - (int)*(short *)(puVar10 + 3);
              if ((uint)(DAT_1f800180 * DAT_1f800180 + DAT_1f800184 * DAT_1f800184 +
                        DAT_1f800188 * DAT_1f800188) < puVar10[4]) {
                DAT_1f800180 = (int)DAT_1f8001a8 - (int)*(short *)(puVar10 + 2);
                DAT_1f800184 = (int)DAT_1f8001aa - (int)*(short *)((int)puVar10 + 10);
                local_68 = DAT_1f800180;
                if (DAT_1f800180 < 0) {
                  local_68 = -DAT_1f800180;
                }
                DAT_1f800188 = (int)DAT_1f8001ac - (int)*(short *)(puVar10 + 3);
                local_64 = DAT_1f800184;
                if (DAT_1f800184 < 0) {
                  local_64 = -DAT_1f800184;
                }
                local_60 = DAT_1f800188;
                if (DAT_1f800188 < 0) {
                  local_60 = -DAT_1f800188;
                }
                MATH3D_Sort3VectorCoords(&local_68,&local_64,&local_60);
                iVar9 = local_60 * 0x1e + local_64 * 0xc + local_68 * 9;
                iVar8 = iVar9 >> 5;
                if (iVar9 != 0) {
                  iVar7 = DAT_1f800184 << 0xc;
                  iVar5 = DAT_1f800188 << 0xc;
                  *local_50 = (DAT_1f800180 << 0xc) / iVar8;
                  local_50[1] = iVar7 / iVar8;
                  local_50[2] = iVar5 / iVar8;
                  DAT_1f800180 = (int)(DAT_1f800180 *
                                       ((uint)*(ushort *)((int)puVar10 + 0xe) - iVar8) * 0x20) /
                                 iVar9;
                  DAT_1f800184 = (int)(DAT_1f800184 *
                                       ((uint)*(ushort *)((int)puVar10 + 0xe) - iVar8) * 0x20) /
                                 iVar9;
                  DAT_1f800188 = (int)(DAT_1f800188 *
                                       ((uint)*(ushort *)((int)puVar10 + 0xe) - iVar8) * 0x20) /
                                 iVar9;
                  DAT_1f8001a8 = DAT_1f8001a8 + (short)DAT_1f800180;
                  DAT_1f8001aa = DAT_1f8001aa + (short)DAT_1f800184;
                  DAT_1f8001ac = DAT_1f8001ac + (short)DAT_1f800188;
                  SetRotMatrix((undefined4 *)&DAT_1f800100);
                  SetTransMatrix((int)local_5c);
                  RotTrans(&DAT_1f8001a8,&DAT_1f800190,local_40);
                  ApplyMatrixLV((undefined4 *)&DAT_1f800100,local_50,local_4c);
                  pcollideInfo->newPoint->vx = DAT_1f800190;
                  pcollideInfo->newPoint->vy = DAT_1f800194;
                  pcollideInfo->newPoint->vz = DAT_1f800198;
                  (pcollideInfo->wNormal).vx = *(short *)local_4c;
                  (pcollideInfo->wNormal).vy = *(short *)(local_4c + 1);
                  sVar2 = *(short *)(local_4c + 2);
                  pcollideInfo->type = (ushort)bVar1;
                  (pcollideInfo->wNormal).vz = sVar2;
                  bVar1 = *pbVar11;
                  *(uint **)&pcollideInfo->prim = puVar10;
                  pcollideInfo->inst = instance;
                  goto LAB_8002098c;
                }
              }
            }
          }
          else {
            if ((bVar1 == 5) && (hbox = *(_HBox **)(pbVar11 + 1), (hbox->flags & 0x2000U) != 0)) {
              uVar4 = (instance->scale).x;
              if (uVar4 == 0x1000) {
                hbox->maxX = hbox->refMaxX;
                hbox->minX = hbox->refMinX;
              }
              else {
                hbox->maxX = (short)((int)((int)hbox->refMaxX * (uint)uVar4) >> 0xc);
                hbox->minX = (short)((int)((int)hbox->refMinX * (uint)uVar4) >> 0xc);
              }
              uVar4 = (instance->scale).y;
              if (uVar4 == 0x1000) {
                hbox->maxY = hbox->refMaxY;
                hbox->minY = hbox->refMinY;
              }
              else {
                hbox->maxY = (short)((int)((int)hbox->refMaxY * (uint)uVar4) >> 0xc);
                hbox->minY = (short)((int)((int)hbox->refMinY * (uint)uVar4) >> 0xc);
              }
              uVar4 = (instance->scale).z;
              if (uVar4 == 0x1000) {
                hbox->maxZ = hbox->refMaxZ;
                hbox->minZ = hbox->refMinZ;
              }
              else {
                hbox->maxZ = (short)((int)((int)hbox->refMaxZ * (uint)uVar4) >> 0xc);
                hbox->minZ = (short)((int)((int)hbox->refMinZ * (uint)uVar4) >> 0xc);
              }
              lVar6 = COLLIDE_IntersectLineAndBox
                                (local_2c,&_Stack136,&_Stack120,&_Stack112,(_SVector *)&DAT_1f8001a8
                                 ,local_48,hbox);
              if (lVar6 != 0) {
                DAT_1f8001aa = local_2c->y;
                DAT_1f8001ac = local_2c->z;
                DAT_1f8001a8 = local_80.x;
                ApplyMatrixSV(&DAT_1f800100,&_Stack136,&pcollideInfo->wNormal);
                pcollideInfo->type = 5;
                bVar1 = *pbVar11;
                *(_HBox **)&pcollideInfo->prim = hbox;
                goto LAB_80020980;
              }
            }
          }
        }
        if ((((int)DAT_1f8001a8 != _DAT_1f800190) || ((int)DAT_1f8001aa != _DAT_1f800194)) ||
           ((int)DAT_1f8001ac != _DAT_1f800198)) {
          (pcollideInfo->cldPoint).vx = DAT_1f8001a8;
          (pcollideInfo->cldPoint).vy = DAT_1f8001aa;
          (pcollideInfo->cldPoint).vz = DAT_1f8001ac;
          SetRotMatrix((undefined4 *)&DAT_1f800100);
          SetTransMatrix((int)local_5c);
          RotTrans(&DAT_1f8001a8,&DAT_1f800190,local_40);
          pcollideInfo->newPoint->vx = DAT_1f800190;
          pcollideInfo->newPoint->vy = DAT_1f800194;
          pcollideInfo->newPoint->vz = DAT_1f800198;
        }
      }
      pbVar11 = pbVar11 + 8;
      local_34 = local_34 + -1;
      local_38 = local_38 + 1;
    } while (local_34 != 0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ COLLIDE_PointAndInstanceTrivialReject(struct _PCollideInfo *pcollideInfo /*$s3*/, struct _Instance *instance /*$s1*/)
 // line 1584, offset 0x80020a98
	/* begin block 1 */
		// Start line: 1585
		// Start offset: 0x80020A98
		// Variables:
	// 		struct _Vector *dv; // $s2
	// 		struct _SVector linePoint; // stack offset -32

		/* begin block 1.1 */
			// Start line: 1596
			// Start offset: 0x80020B20
			// Variables:
		// 		long _x0; // $a2
		// 		long _y0; // $v1
		// 		long _z0; // $v0
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $a0
		// 		struct _SVector *_v0; // $a0
		/* end block 1.1 */
		// End offset: 0x80020B20
		// End Line: 1596
	/* end block 1 */
	// End offset: 0x80020C00
	// End Line: 1633

	/* begin block 2 */
		// Start line: 4060
	/* end block 2 */
	// End Line: 4061

void COLLIDE_PointAndInstanceTrivialReject(_PCollideInfo *pcollideInfo,_Instance *instance)

{
  long lVar1;
  short local_20;
  short local_1e;
  short local_1c;
  
  lVar1 = MEMPACK_MemoryValidFunc((char *)instance->object);
  if ((((lVar1 != 0) && ((instance->flags & 0x40U) == 0)) &&
      (instance->hModelList != (_HModel *)0x0)) &&
     (((pcollideInfo->collideType & 0x40U) == 0 || ((instance->object->oflags2 & 0x40U) == 0)))) {
    COLLIDE_NearestPointOnLine_S
              ((uint *)&local_20,(uint *)pcollideInfo->oldPoint,(uint *)pcollideInfo->newPoint,
               (uint *)&instance->position);
    DAT_1f800000 = (int)local_20 - (int)(instance->position).x >> 1;
    DAT_1f800004 = (int)local_1e - (int)(instance->position).y >> 1;
    DAT_1f800008 = (int)local_1c - (int)(instance->position).z >> 1;
    if ((DAT_1f800000 * DAT_1f800000 + DAT_1f800004 * DAT_1f800004 + DAT_1f800008 * DAT_1f800008 <
         instance->object->modelList[instance->currentModel]->maxRadSq >> 2) &&
       (instance->matrix != (MATRIX *)0x0)) {
      COLLIDE_PointAndInstance(pcollideInfo,instance);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ COLLIDE_PointAndWorld(struct _PCollideInfo *pcollideInfo /*$s5*/, struct Level *level /*$s6*/)
 // line 1648, offset 0x80020c1c
	/* begin block 1 */
		// Start line: 1649
		// Start offset: 0x80020C1C
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		struct _InstanceList *instanceList; // $s3
	// 		struct _LCollideInfo lcol; // stack offset -56
	// 		int i; // $s1
	// 		int in_warpRoom; // $s7

		/* begin block 1.1 */
			// Start line: 1660
			// Start offset: 0x80020C60
			// Variables:
		// 		struct _TFace *tface; // $s3
		// 		struct _Terrain *terrain; // $s4

			/* begin block 1.1.1 */
				// Start line: 1690
				// Start offset: 0x80020CFC
			/* end block 1.1.1 */
			// End offset: 0x80020D20
			// End Line: 1694

			/* begin block 1.1.2 */
				// Start line: 1699
				// Start offset: 0x80020D28

				/* begin block 1.1.2.1 */
					// Start line: 1704
					// Start offset: 0x80020D2C
					// Variables:
				// 		struct Level *thislevel; // $s0
				/* end block 1.1.2.1 */
				// End offset: 0x80020DD0
				// End Line: 1728
			/* end block 1.1.2 */
			// End offset: 0x80020E00
			// End Line: 1739
		/* end block 1.1 */
		// End offset: 0x80020E00
		// End Line: 1740
	/* end block 1 */
	// End offset: 0x80020FD8
	// End Line: 1813

	/* begin block 2 */
		// Start line: 4207
	/* end block 2 */
	// End Line: 4208

void COLLIDE_PointAndWorld(_PCollideInfo *pcollideInfo,Level *level)

{
  bool bVar1;
  _InstanceList *p_Var2;
  long lVar3;
  _StreamUnit *p_Var4;
  uint uVar5;
  _Instance *instance;
  int iVar6;
  ushort *puVar7;
  NodeType **ppNVar8;
  long *plVar9;
  _TFace *tface;
  _Terrain *terrain;
  undefined auStack56 [8];
  short local_30;
  
  bVar1 = false;
  pcollideInfo->type = 0;
  if ((pcollideInfo->collideType & 1U) != 0) {
    tface = (_TFace *)0x0;
    if ((level != (Level *)0x0) && (lVar3 = MEMPACK_MemoryValidFunc((char *)level), lVar3 != 0)) {
      terrain = level->terrain;
      tface = COLLIDE_PointAndTerrain(terrain,pcollideInfo,(_LCollideInfo *)auStack56);
      if (tface == (_TFace *)0x0) {
        p_Var4 = STREAM_GetStreamUnitWithID(level->streamUnitID);
        if ((p_Var4->flags & 1U) != 0) {
          bVar1 = true;
        }
      }
      else {
        pcollideInfo->type = 3;
        *(_TFace **)&pcollideInfo->prim = tface;
        *(Level **)&pcollideInfo->inst = level;
        pcollideInfo->segment = local_30;
        if (gameTrackerX.gameData.asmData.MorphTime == 1000) {
          COLLIDE_GetNormal(tface->normal,(short *)terrain->normalList,
                            (_SVector *)&pcollideInfo->wNormal);
        }
        else {
          COLLIDE_MakeNormal(terrain,tface,(_SVector *)&pcollideInfo->wNormal);
        }
      }
    }
    iVar6 = 0;
    if (tface == (_TFace *)0x0) {
      puVar7 = (ushort *)&StreamTracker.StreamList[0].flags;
      do {
        instance = *(_Instance **)(puVar7 + 1);
        if ((((puVar7[-1] == 2) && (instance != (_Instance *)level)) &&
            ((!bVar1 || ((*puVar7 & 1) == 0)))) &&
           (lVar3 = MEMPACK_MemoryValidFunc((char *)instance), lVar3 != 0)) {
          terrain = (_Terrain *)(instance->node).prev;
          tface = COLLIDE_PointAndTerrain(terrain,pcollideInfo,(_LCollideInfo *)auStack56);
          if (tface != (_TFace *)0x0) {
            pcollideInfo->type = 3;
            *(_TFace **)&pcollideInfo->prim = tface;
            pcollideInfo->inst = instance;
            pcollideInfo->segment = local_30;
            if (gameTrackerX.gameData.asmData.MorphTime == 1000) {
              COLLIDE_GetNormal(tface->normal,(short *)terrain->normalList,
                                (_SVector *)&pcollideInfo->wNormal);
            }
            else {
              COLLIDE_MakeNormal(terrain,tface,(_SVector *)&pcollideInfo->wNormal);
            }
            break;
          }
        }
        iVar6 = iVar6 + 1;
        puVar7 = puVar7 + 0x20;
      } while (iVar6 < 0x10);
      if (tface == (_TFace *)0x0) {
        pcollideInfo->type = 0;
        pcollideInfo->prim = (void *)0x0;
        pcollideInfo->inst = (_Instance *)0x0;
        (pcollideInfo->wNormal).vx = 0;
        (pcollideInfo->wNormal).vy = 0;
        (pcollideInfo->wNormal).vz = 0;
      }
    }
  }
  p_Var2 = gameTrackerX.instanceList;
  uVar5 = pcollideInfo->collideType;
  iVar6 = 0x10;
  if ((uVar5 & 8) == 0) {
    if ((uVar5 & 0x10) == 0) {
      iVar6 = 0;
      if ((uVar5 & 4) != 0) {
        plVar9 = &dyna_cldstat;
        do {
          instance = (_Instance *)p_Var2->group[*plVar9].next;
          while (instance != (_Instance *)0x0) {
            if ((instance->flags2 & 0x24000000U) == 0) {
              COLLIDE_PointAndInstanceTrivialReject(pcollideInfo,instance);
            }
            instance = (_Instance *)(instance->node).next;
          }
          iVar6 = iVar6 + 1;
          plVar9 = plVar9 + 1;
        } while (iVar6 < 8);
      }
    }
    else {
      iVar6 = 0;
      if ((uVar5 & 2) != 0) {
        plVar9 = &stat_clddyna;
        do {
          instance = (_Instance *)p_Var2->group[*plVar9].next;
          while (instance != (_Instance *)0x0) {
            if ((instance->flags2 & 0x24000000U) == 0) {
              COLLIDE_PointAndInstanceTrivialReject(pcollideInfo,instance);
            }
            instance = (_Instance *)(instance->node).next;
          }
          iVar6 = iVar6 + 1;
          plVar9 = plVar9 + 1;
        } while (iVar6 < 8);
      }
      iVar6 = 0;
      if ((pcollideInfo->collideType & 4U) != 0) {
        plVar9 = &dyna_clddyna;
        do {
          instance = (_Instance *)p_Var2->group[*plVar9].next;
          while (instance != (_Instance *)0x0) {
            if ((instance->flags2 & 0x24000000U) == 0) {
              COLLIDE_PointAndInstanceTrivialReject(pcollideInfo,instance);
            }
            instance = (_Instance *)(instance->node).next;
          }
          iVar6 = iVar6 + 1;
          plVar9 = plVar9 + 1;
        } while (iVar6 < 8);
      }
    }
  }
  else {
    ppNVar8 = &(gameTrackerX.instanceList)->group[0xe].next;
    do {
      instance = (_Instance *)ppNVar8[4];
      while (instance != (_Instance *)0x0) {
        if ((instance->flags2 & 0x24000000U) == 0) {
          COLLIDE_PointAndInstanceTrivialReject(pcollideInfo,instance);
        }
        instance = (_Instance *)(instance->node).next;
      }
      iVar6 = iVar6 + 1;
      ppNVar8 = ppNVar8 + 2;
    } while (iVar6 < 0x20);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ COLLIDE_ClosestPointInBoxToPoint(struct _Position *boxPoint /*$a0*/, struct _HBox *hbox /*$a1*/, struct _SVector *point /*$a2*/)
 // line 1893, offset 0x80021004
	/* begin block 1 */
		// Start line: 1895
		// Start offset: 0x80021004
		// Variables:
	// 		long inside; // $a3
	/* end block 1 */
	// End offset: 0x800210D0
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

long COLLIDE_ClosestPointInBoxToPoint(_Position *boxPoint,_HBox *hbox,_SVector *point)

{
  short sVar1;
  long lVar2;
  
  sVar1 = hbox->minX;
  lVar2 = 1;
  if ((point->x < hbox->minX) || (sVar1 = hbox->maxX, hbox->maxX < point->x)) {
    boxPoint->x = sVar1;
    lVar2 = 0;
  }
  else {
    boxPoint->x = point->x;
  }
  sVar1 = hbox->minY;
  if ((point->y < hbox->minY) || (sVar1 = hbox->maxY, hbox->maxY < point->y)) {
    boxPoint->y = sVar1;
    lVar2 = 0;
  }
  else {
    boxPoint->y = point->y;
  }
  if (point->z < hbox->minZ) {
    boxPoint->z = hbox->minZ;
    lVar2 = 0;
  }
  else {
    if (hbox->maxZ < point->z) {
      boxPoint->z = hbox->maxZ;
      lVar2 = 0;
    }
    else {
      boxPoint->z = point->z;
    }
  }
  return lVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ COLLIDE_SphereAndPoint(struct _Sphere *sphere /*$s1*/, struct _SVector *point /*$s2*/, struct _SVector *normal /*$s3*/)
 // line 1944, offset 0x800210d8
	/* begin block 1 */
		// Start line: 1945
		// Start offset: 0x800210D8
		// Variables:
	// 		long len; // $a2
	// 		struct _Vector *line; // $s0

		/* begin block 1.1 */
			// Start line: 1945
			// Start offset: 0x800210D8
			// Variables:
		// 		long _x0; // $a2
		// 		long _y0; // $a1
		// 		long _z0; // $a0
		// 		long _x1; // $v0
		// 		long _y1; // $v0
		// 		long _z1; // $v0
		/* end block 1.1 */
		// End offset: 0x800210D8
		// End Line: 1945

		/* begin block 1.2 */
			// Start line: 1953
			// Start offset: 0x8002116C
			// Variables:
		// 		long a; // stack offset -40
		// 		long b; // stack offset -36
		// 		long c; // stack offset -32
		/* end block 1.2 */
		// End offset: 0x8002116C
		// End Line: 1953
	/* end block 1 */
	// End offset: 0x80021300
	// End Line: 1970

	/* begin block 2 */
		// Start line: 4905
	/* end block 2 */
	// End Line: 4906

long COLLIDE_SphereAndPoint(_Sphere *sphere,_SVector *point,_SVector *normal)

{
  long lVar1;
  int iVar2;
  int iVar3;
  long local_28;
  long local_24;
  long local_20 [2];
  
  DAT_1f800000 = (int)(sphere->position).x - (int)point->x;
  DAT_1f800004 = (int)(sphere->position).y - (int)point->y;
  DAT_1f800008 = (int)(sphere->position).z - (int)point->z;
  lVar1 = 0;
  if ((uint)(DAT_1f800000 * DAT_1f800000 + DAT_1f800004 * DAT_1f800004 + DAT_1f800008 * DAT_1f800008
            ) < sphere->radiusSquared) {
    local_28 = DAT_1f800000;
    if (DAT_1f800000 < 0) {
      local_28 = -DAT_1f800000;
    }
    local_24 = DAT_1f800004;
    if (DAT_1f800004 < 0) {
      local_24 = -DAT_1f800004;
    }
    local_20[0] = DAT_1f800008;
    if (DAT_1f800008 < 0) {
      local_20[0] = -DAT_1f800008;
    }
    MATH3D_Sort3VectorCoords(&local_28,&local_24,local_20);
    iVar3 = local_20[0] * 0x1e + local_24 * 0xc + local_28 * 9;
    iVar2 = iVar3 >> 5;
    lVar1 = 0;
    if (iVar2 != 0) {
      normal->x = (short)((DAT_1f800000 << 0xc) / iVar2);
      normal->y = (short)((DAT_1f800004 << 0xc) / iVar2);
      normal->z = (short)((DAT_1f800008 << 0xc) / iVar2);
      DAT_1f800000 = (int)(DAT_1f800000 * (uint)sphere->radius * 0x20) / iVar3;
      DAT_1f800004 = (int)(DAT_1f800004 * (uint)sphere->radius * 0x20) / iVar3;
      DAT_1f800008 = (int)(DAT_1f800008 * (uint)sphere->radius * 0x20) / iVar3;
      (sphere->position).x = point->x + (short)DAT_1f800000;
      (sphere->position).y = point->y + (short)DAT_1f800004;
      lVar1 = 1;
      (sphere->position).z = point->z + (short)DAT_1f800008;
    }
  }
  return lVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ COLLIDE_SphereAndHBox(struct _HBox *hbox /*$s4*/, struct _Sphere *sphere /*$s1*/, struct _Position *oldPos /*$s5*/, struct _SVector *normal /*$s3*/)
 // line 1975, offset 0x8002131c
	/* begin block 1 */
		// Start line: 1976
		// Start offset: 0x8002131C
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
			// Start offset: 0x80021364
			// Variables:
		// 		long numIntersects; // $a2

			/* begin block 1.1.1 */
				// Start line: 1993
				// Start offset: 0x80021394
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			/* end block 1.1.1 */
			// End offset: 0x80021394
			// End Line: 1993

			/* begin block 1.1.2 */
				// Start line: 1993
				// Start offset: 0x80021394
				// Variables:
			// 		short _x1; // $a0
			// 		short _y1; // $v1
			// 		short _z1; // $a1
			// 		struct _SVector *_v0; // $v0
			/* end block 1.1.2 */
			// End offset: 0x80021394
			// End Line: 1993

			/* begin block 1.1.3 */
				// Start line: 2000
				// Start offset: 0x80021434
				// Variables:
			// 		short _y0; // $v0
			// 		short _z0; // $v1
			// 		short _x1; // $v0
			// 		short _y1; // $a2
			// 		short _z1; // $a3
			// 		struct _SVector *_v; // $a1
			// 		struct _SVector *_v0; // $v1
			/* end block 1.1.3 */
			// End offset: 0x80021434
			// End Line: 2000
		/* end block 1.1 */
		// End offset: 0x80021648
		// End Line: 2076

		/* begin block 1.2 */
			// Start line: 2080
			// Start offset: 0x80021648

			/* begin block 1.2.1 */
				// Start line: 2087
				// Start offset: 0x8002168C
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			// 		struct _SVector *_v0; // $v0
			// 		struct _SVector *_v1; // $v0
			/* end block 1.2.1 */
			// End offset: 0x8002168C
			// End Line: 2087

			/* begin block 1.2.2 */
				// Start line: 2087
				// Start offset: 0x8002168C
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $a1
			/* end block 1.2.2 */
			// End offset: 0x8002168C
			// End Line: 2087

			/* begin block 1.2.3 */
				// Start line: 2096
				// Start offset: 0x800216D0
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			/* end block 1.2.3 */
			// End offset: 0x800216D0
			// End Line: 2096

			/* begin block 1.2.4 */
				// Start line: 2096
				// Start offset: 0x800216D0
				// Variables:
			// 		short _x1; // $a0
			// 		short _y1; // $v1
			// 		short _z1; // $a1
			// 		struct _SVector *_v0; // $v0
			/* end block 1.2.4 */
			// End offset: 0x800216D0
			// End Line: 2096
		/* end block 1.2 */
		// End offset: 0x80021770
		// End Line: 2106
	/* end block 1 */
	// End offset: 0x80021770
	// End Line: 2108

	/* begin block 2 */
		// Start line: 4981
	/* end block 2 */
	// End Line: 4982

long COLLIDE_SphereAndHBox(_HBox *hbox,_Sphere *sphere,_Position *oldPos,_SVector *normal)

{
  short sVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  short sVar5;
  int iVar6;
  short sVar7;
  int iVar8;
  _SVector local_60;
  _SVector local_58;
  _SVector _Stack80;
  _SVector local_48;
  _SVector _Stack64;
  _SVector local_38 [3];
  
  lVar2 = COLLIDE_ClosestPointInBoxToPoint((_Position *)&local_60,hbox,(_SVector *)sphere);
  if (lVar2 == 0) {
    lVar2 = COLLIDE_IntersectLineAndBox
                      (&local_58,&local_48,&_Stack80,&_Stack64,(_SVector *)sphere,(_SVector *)oldPos
                       ,hbox);
    if (lVar2 == 0) {
      lVar4 = COLLIDE_SphereAndPoint(sphere,&local_60,local_38);
      lVar2 = 0;
      if (lVar4 != 0) {
        collide_localPoint.x = local_60.x;
        collide_localPoint.y = local_60.y;
        collide_localPoint.z = local_60.z;
        lVar2 = 1;
        normal->x = local_38[0].x;
        normal->y = local_38[0].y;
        normal->z = local_38[0].z;
      }
    }
    else {
      normal->x = local_48.x;
      normal->y = local_48.y;
      normal->z = local_48.z;
      collide_localPoint.x = local_58.x;
      collide_localPoint.y = local_58.y;
      collide_localPoint.z = local_58.z;
      (sphere->position).x =
           local_58.x + (short)((int)((int)normal->x * (uint)sphere->radius) >> 0xc);
      (sphere->position).y =
           local_58.y + (short)((int)((int)normal->y * (uint)sphere->radius) >> 0xc);
      lVar2 = 1;
      (sphere->position).z =
           local_58.z + (short)((int)((int)normal->z * (uint)sphere->radius) >> 0xc);
    }
  }
  else {
    lVar2 = COLLIDE_IntersectLineAndBox
                      (&local_58,&local_48,&_Stack80,&_Stack64,(_SVector *)sphere,(_SVector *)oldPos
                       ,hbox);
    if (lVar2 == 0) {
      sVar1 = (short)((int)hbox->minY + (int)hbox->maxY >> 1) - (sphere->position).y;
      sVar5 = (short)((int)hbox->minZ + (int)hbox->maxZ >> 1) - (sphere->position).z;
      iVar8 = (int)((((int)hbox->minX + (int)hbox->maxX >> 1) - (uint)(ushort)(sphere->position).x)
                   * 0x10000) >> 0x10;
      iVar6 = iVar8;
      if (iVar8 < 0) {
        iVar6 = -iVar8;
      }
      iVar3 = (int)sVar1;
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      sVar7 = sVar5;
      if (sVar5 < 0) {
        sVar7 = -sVar5;
      }
      if ((iVar6 * -0x10000 < iVar3 * -0x10000) || (iVar6 * -0x10000 >> 0x10 < (int)-sVar7)) {
        if (((short)-(short)iVar3 < (short)-(short)iVar6) || ((short)-(short)iVar3 < -sVar7)) {
          if (sVar5 < 0) {
            (sphere->position).z = hbox->maxZ + sphere->radius;
            sVar1 = 0x1000;
          }
          else {
            (sphere->position).z = hbox->minZ - sphere->radius;
            sVar1 = -0x1000;
          }
          normal->x = 0;
          normal->y = 0;
          normal->z = sVar1;
        }
        else {
          if (sVar1 < 0) {
            (sphere->position).y = hbox->maxY + sphere->radius;
            sVar1 = 0x1000;
          }
          else {
            (sphere->position).y = hbox->minY - sphere->radius;
            sVar1 = -0x1000;
          }
          normal->x = 0;
          normal->y = sVar1;
          normal->z = 0;
        }
      }
      else {
        if (iVar8 < 0) {
          (sphere->position).x = hbox->maxX + sphere->radius;
          sVar1 = 0x1000;
        }
        else {
          (sphere->position).x = hbox->minX - sphere->radius;
          sVar1 = -0x1000;
        }
        normal->x = sVar1;
        normal->y = 0;
        normal->z = 0;
      }
      lVar2 = 1;
    }
    else {
      normal->x = local_48.x;
      normal->y = local_48.y;
      normal->z = local_48.z;
      collide_localPoint.x = local_58.x;
      collide_localPoint.y = local_58.y;
      collide_localPoint.z = local_58.z;
      (sphere->position).x =
           local_58.x + (short)((int)((int)normal->x * (uint)sphere->radius) >> 0xc);
      (sphere->position).y =
           local_58.y + (short)((int)((int)normal->y * (uint)sphere->radius) >> 0xc);
      (sphere->position).z =
           local_58.z + (short)((int)((int)normal->z * (uint)sphere->radius) >> 0xc);
    }
  }
  return lVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ COLLIDE_Instance1SpheresToInstance2(struct _Instance *instance1 /*stack 0*/, struct _Instance *instance2 /*$fp*/, long sphereToSphere /*$a2*/)
 // line 2419, offset 0x80021794
	/* begin block 1 */
		// Start line: 2420
		// Start offset: 0x80021794
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
			// Start offset: 0x80021930
			// Variables:
		// 		int i; // stack offset -52

			/* begin block 1.1.1 */
				// Start line: 2524
				// Start offset: 0x80021BA8
				// Variables:
			// 		long len; // $a3

				/* begin block 1.1.1.1 */
					// Start line: 2525
					// Start offset: 0x80021BA8
					// Variables:
				// 		long a; // stack offset -148
				// 		long b; // stack offset -144
				// 		long c; // stack offset -140
				/* end block 1.1.1.1 */
				// End offset: 0x80021BA8
				// End Line: 2525

				/* begin block 1.1.1.2 */
					// Start line: 2531
					// Start offset: 0x80021C40
					// Variables:
				// 		short _x1; // $v1
				// 		short _y1; // $a0
				// 		short _z1; // $v0
				// 		struct _Position *_v1; // $v0
				/* end block 1.1.1.2 */
				// End offset: 0x80021C40
				// End Line: 2531

				/* begin block 1.1.1.3 */
					// Start line: 2536
					// Start offset: 0x80021C68
					// Variables:
				// 		short _x1; // $v0
				// 		short _y1; // $v1
				// 		short _z1; // $a0
				/* end block 1.1.1.3 */
				// End offset: 0x80021C68
				// End Line: 2536
			/* end block 1.1.1 */
			// End offset: 0x80021D9C
			// End Line: 2561

			/* begin block 1.1.2 */
				// Start line: 2577
				// Start offset: 0x80021E10
				// Variables:
			// 		struct _Model *model2; // $s1

				/* begin block 1.1.2.1 */
					// Start line: 2676
					// Start offset: 0x80022210
					// Variables:
				// 		struct _HBox *hbox; // $s4
				/* end block 1.1.2.1 */
				// End offset: 0x8002246C
				// End Line: 2742
			/* end block 1.1.2 */
			// End offset: 0x8002246C
			// End Line: 2743
		/* end block 1.1 */
		// End offset: 0x8002248C
		// End Line: 2746
	/* end block 1 */
	// End offset: 0x800224B4
	// End Line: 2748

	/* begin block 2 */
		// Start line: 4838
	/* end block 2 */
	// End Line: 4839

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void COLLIDE_Instance1SpheresToInstance2
               (_Instance *instance1,_Instance *instance2,long sphereToSphere)

{
  byte bVar1;
  short sVar2;
  undefined4 uVar3;
  short sVar4;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar5;
  int iVar6;
  long lVar7;
  short sVar8;
  _HModel *p_Var9;
  MATRIX *source;
  _HBox *hbox;
  _Model *p_Var10;
  byte *pbVar11;
  _HBox *p_Var12;
  int iVar13;
  undefined auStack152 [4];
  long local_94;
  long local_90;
  long local_8c;
  long local_88;
  MATRIX *local_84;
  MATRIX *local_80;
  short *local_7c;
  undefined4 *local_78;
  short *local_74;
  undefined4 *local_70;
  short *local_6c;
  undefined4 *local_68;
  _Position *local_64;
  short *local_60;
  short *local_5c;
  short *local_58;
  short *local_54;
  _HFaceInfo *local_50;
  MATRIX *local_4c;
  MATRIX *local_48;
  _HModel *local_44;
  _HPrim *local_40;
  _HPrim *local_3c;
  int local_38;
  int local_34;
  undefined *local_30;
  byte *local_2c;
  
  local_84 = (MATRIX *)&DAT_1f8000c8;
  local_80 = (MATRIX *)&DAT_1f800108;
  local_7c = &DAT_1f800128;
  local_78 = &DAT_1f800158;
  local_74 = &DAT_1f800168;
  local_70 = &DAT_1f800188;
  local_6c = &DAT_1f800198;
  local_68 = (undefined4 *)&DAT_1f8001a8;
  local_64 = (_Position *)&DAT_1f8001bc;
  local_60 = &DAT_1f8001e0;
  local_5c = &DAT_1f8001ec;
  local_58 = &DAT_1f8001f8;
  local_54 = &DAT_1f800204;
  local_50 = (_HFaceInfo *)&DAT_1f800240;
  p_Var9 = instance1->hModelList + instance1->currentModel;
  if (((instance1->hModelList != (_HModel *)0x0) && (instance2->hModelList != (_HModel *)0x0)) &&
     (local_44 = instance2->hModelList + instance2->currentModel, local_44->numHPrims != 0)) {
    local_38 = p_Var9->numHPrims;
    local_40 = p_Var9->hPrimList;
    if (local_38 != 0) {
      local_30 = auStack152;
      local_2c = &local_40->segment;
      do {
        if (((local_40->hpFlags & 1) != 0) &&
           ((undefined *)(*(uint *)local_40 & 0xff0400) == &UNK_00010400)) {
          bVar1 = *local_2c;
          local_4c = instance1->matrix + bVar1;
          source = instance1->oldMatrix;
          p_Var12 = *(_HBox **)(local_2c + 1);
          SetRotMatrix((undefined4 *)local_4c);
          SetTransMatrix((int)local_4c);
          RotTrans(&p_Var12->minZ,local_74,local_30);
          sVar8 = local_74[2];
          sVar2 = local_74[4];
          *local_60 = *local_74;
          local_60[1] = sVar8;
          local_60[2] = sVar2;
          SetRotMatrix((undefined4 *)(source + bVar1));
          SetTransMatrix((int)(source + bVar1));
          RotTrans(&p_Var12->minZ,local_74,local_30);
          sVar8 = local_74[2];
          sVar2 = local_74[4];
          *local_58 = *local_74;
          local_58[1] = sVar8;
          local_58[2] = sVar2;
          local_34 = local_44->numHPrims;
          local_3c = local_44->hPrimList;
          if (local_34 != 0) {
            pbVar11 = &local_3c->segment;
            do {
              if (((local_3c->hpFlags & 1) != 0) && ((local_3c->hpFlags & 4) != 0)) {
                local_48 = instance2->matrix + *pbVar11;
                source = instance2->oldMatrix + *pbVar11;
                if ((pbVar11[-1] == 1) &&
                   (((local_2c[-2] & 0x20) != 0 && ((pbVar11[-2] & 0x20) != 0)))) {
                  hbox = *(_HBox **)(pbVar11 + 1);
                  SetRotMatrix((undefined4 *)local_48);
                  SetTransMatrix((int)local_48);
                  RotTrans(&hbox->minZ,local_74,local_30);
                  sVar8 = local_74[2];
                  sVar2 = local_74[4];
                  *local_5c = *local_74;
                  local_5c[1] = sVar8;
                  local_5c[2] = sVar2;
                  SetRotMatrix((undefined4 *)source);
                  SetTransMatrix((int)source);
                  RotTrans(&hbox->minZ,local_74,local_30);
                  iVar5 = (int)*local_60 - (int)*local_5c;
                  _DAT_1f80014c = (int)local_60[1] - (int)local_5c[1];
                  iVar13 = _DAT_1f80014c * _DAT_1f80014c;
                  DAT_1f800150 = (int)local_60[2] - (int)local_5c[2];
                  sVar8 = local_74[4];
                  sVar2 = *local_74;
                  _DAT_1f800148 = iVar5;
                  local_54[1] = local_74[2];
                  local_54[2] = sVar8;
                  *local_54 = sVar2;
                  iVar6 = (uint)(ushort)p_Var12->maxZ + (uint)(ushort)hbox->maxZ;
                  if (iVar5 * iVar5 + iVar13 + DAT_1f800150 * DAT_1f800150 < iVar6 * iVar6) {
                    if (iVar5 < 0) {
                      iVar5 = -iVar5;
                    }
                    local_90 = _DAT_1f80014c;
                    if (_DAT_1f80014c < 0) {
                      local_90 = -_DAT_1f80014c;
                    }
                    local_8c = DAT_1f800150;
                    if (DAT_1f800150 < 0) {
                      local_8c = -DAT_1f800150;
                    }
                    local_94 = iVar5;
                    MATH3D_Sort3VectorCoords(&local_94,&local_90,&local_8c);
                    iVar5 = local_8c * 0x1e + local_90 * 0xc + local_94 * 9;
                    if (iVar5 != 0) {
                      if ((ushort)p_Var12->maxZ < (ushort)hbox->maxZ) {
                        collide_localPoint.y = p_Var12->maxX;
                        collide_localPoint.x = p_Var12->minZ;
                        collide_localPoint.z = p_Var12->maxY;
                        collide_lwTransform = local_4c;
                      }
                      else {
                        collide_localPoint.x = hbox->minZ;
                        collide_localPoint.y = hbox->maxX;
                        collide_localPoint.z = hbox->maxY;
                        collide_lwTransform = local_48;
                      }
                      iVar6 = iVar5 >> 5;
                      _DAT_1f800148 =
                           _DAT_1f800148 *
                           (((uint)(ushort)p_Var12->maxZ + (uint)(ushort)hbox->maxZ) - iVar6);
                      _DAT_1f80014c =
                           _DAT_1f80014c *
                           (((uint)(ushort)p_Var12->maxZ + (uint)(ushort)hbox->maxZ) - iVar6);
                      DAT_1f800150 = DAT_1f800150 *
                                     (((uint)(ushort)p_Var12->maxZ + (uint)(ushort)hbox->maxZ) -
                                     iVar6);
                      DAT_1f800216 = 1;
                      DAT_1f800217 = 1;
                      DAT_1f800238 = (short)((_DAT_1f800148 * 0x20) / iVar5);
                      DAT_1f80023a = (short)((_DAT_1f80014c * 0x20) / iVar5);
                      DAT_1f80023c = (short)((DAT_1f800150 * 0x20) / iVar5);
                      if (instance1->collideFunc != (_func_2 *)0x0) {
                        DAT_1f800215 = *local_2c;
                        DAT_1f800218 = p_Var12;
                        DAT_1f80021c = hbox;
                        DAT_1f800220 = instance1;
                        DAT_1f800224 = instance2;
                        *(undefined4 **)&instance1->collideInfo = &DAT_1f800210;
                        (*instance1->collideFunc)(instance1,&gameTrackerX);
                      }
                      if (instance2->collideFunc != (_func_2 *)0x0) {
                        DAT_1f800238 = -DAT_1f800238;
                        DAT_1f80023c = -DAT_1f80023c;
                        DAT_1f80023a = -DAT_1f80023a;
                        DAT_1f800215 = *pbVar11;
                        DAT_1f800218 = hbox;
                        DAT_1f80021c = p_Var12;
                        DAT_1f800220 = instance2;
                        DAT_1f800224 = instance1;
                        *(undefined4 **)&instance2->collideInfo = &DAT_1f800210;
                        (*instance2->collideFunc)(instance2,&gameTrackerX);
                      }
                    }
                  }
                }
                else {
                  if ((pbVar11[-1] == 2) || (pbVar11[-1] == 5)) {
                    p_Var10 = instance2->object->modelList[instance2->currentModel];
                    local_50->flags = 0;
                    PIPE3D_InvertTransform(local_84,local_48);
                    SetRotMatrix((undefined4 *)local_84);
                    SetTransMatrix((int)local_84);
                    RotTrans(local_60,local_70,local_30);
                    DAT_1f8001b0 = *(short *)local_70;
                    DAT_1f8001b2 = *(short *)(local_70 + 1);
                    DAT_1f8001b4 = *(short *)(local_70 + 2);
                    DAT_1f8001b6 = p_Var12->maxZ;
                    _DAT_1f8001b8 = *(undefined4 *)&p_Var12->refMinX;
                    PIPE3D_InvertTransform(local_80,source);
                    SetRotMatrix((undefined4 *)local_80);
                    SetTransMatrix((int)local_80);
                    RotTrans(local_58,local_6c,local_30);
                    sVar8 = local_6c[2];
                    sVar2 = local_6c[4];
                    local_64->x = *local_6c;
                    local_64->y = sVar8;
                    local_64->z = sVar2;
                    sVar4 = DAT_1f8001b4;
                    sVar2 = DAT_1f8001b2;
                    sVar8 = DAT_1f8001b0;
                    if (((pbVar11[-1] == 2) && ((local_2c[-2] & 0x40) != 0)) &&
                       ((pbVar11[-2] & 0x20) != 0)) {
                      hbox = *(_HBox **)(pbVar11 + 1);
                      local_50->flags = 0;
                      *local_7c = sVar8;
                      local_7c[1] = sVar2;
                      local_7c[2] = sVar4;
                      *(_HBox **)&local_50->hface = hbox;
                      local_50->vertex0 = (_HVertex *)(p_Var10->vertexList + hbox->flags);
                      local_50->vertex1 = (_HVertex *)(p_Var10->vertexList + *(short *)&hbox->id);
                      local_50->vertex2 = (_HVertex *)(p_Var10->vertexList + hbox->minX);
                      COLLIDE_GetNormal(hbox->minZ,(short *)p_Var10->normalList,&local_50->normal);
                      lVar7 = COLLIDE_SphereAndHFace
                                        ((_Sphere *)&DAT_1f8001b0,local_64,local_50,
                                         (_SVector *)&DAT_1f800230,&local_88);
                      if (lVar7 != 0) {
                        *(short *)local_68 = DAT_1f8001b0 - *local_7c;
                        sVar8 = DAT_1f8001b4 - local_7c[2];
                        *(short *)((int)local_68 + 2) = DAT_1f8001b2 - local_7c[1];
                        *(short *)(local_68 + 1) = sVar8;
                        setCopControlWord(2,0,*(undefined4 *)local_48->m);
                        setCopControlWord(2,0x800,*(undefined4 *)(local_48->m + 2));
                        setCopControlWord(2,0x1000,*(undefined4 *)(local_48->m + 4));
                        setCopControlWord(2,0x1800,*(undefined4 *)(local_48->m + 6));
                        setCopControlWord(2,0x2000,*(undefined4 *)(local_48->m + 8));
                        setCopReg(2,in_zero,*local_68);
                        setCopReg(2,in_at,local_68[1]);
                        copFunction(2,0x486012);
                        uVar3 = getCopReg(2,0x19);
                        *local_78 = uVar3;
                        uVar3 = getCopReg(2,0x1a);
                        local_78[1] = uVar3;
                        uVar3 = getCopReg(2,0x1b);
                        local_78[2] = uVar3;
                        DAT_1f800228 = DAT_1f800230;
                        DAT_1f80022c = DAT_1f800234;
                        if (instance2->collideFunc != (_func_2 *)0x0) {
                          if (local_88 == 0) {
                            DAT_1f800214 = 8;
                          }
                          else {
                            DAT_1f800214 = 4;
                          }
                          DAT_1f800216 = 2;
                          DAT_1f800217 = 1;
                          DAT_1f800238 = -*(short *)local_78;
                          DAT_1f80023a = -*(short *)(local_78 + 1);
                          DAT_1f80023c = -*(short *)(local_78 + 2);
                          DAT_1f800215 = *pbVar11;
                          DAT_1f800218 = hbox;
                          DAT_1f80021c = p_Var12;
                          DAT_1f800220 = instance2;
                          DAT_1f800224 = instance1;
                          *(undefined4 **)&instance2->collideInfo = &DAT_1f800210;
                          (*instance2->collideFunc)(instance2,&gameTrackerX);
                        }
                        if (instance1->collideFunc != (_func_2 *)0x0) {
                          if (local_88 == 0) {
                            DAT_1f800214 = 2;
                          }
                          else {
                            DAT_1f800214 = 1;
                          }
                          DAT_1f800238 = *(short *)local_78;
                          DAT_1f80023a = *(short *)(local_78 + 1);
                          DAT_1f80023c = *(short *)(local_78 + 2);
                          DAT_1f800216 = 1;
                          DAT_1f800217 = 2;
                          DAT_1f800215 = *local_2c;
                          DAT_1f800218 = p_Var12;
                          DAT_1f80021c = hbox;
                          DAT_1f800220 = instance1;
                          DAT_1f800224 = instance2;
                          *(undefined4 **)&instance1->collideInfo = &DAT_1f800210;
                          (*instance1->collideFunc)(instance1,&gameTrackerX);
                        }
                        sVar2 = DAT_1f8001b4;
                        sVar8 = DAT_1f8001b2;
                        *local_7c = DAT_1f8001b0;
                        local_7c[1] = sVar8;
                        local_7c[2] = sVar2;
                      }
                    }
                    else {
                      bVar1 = pbVar11[-1];
                      if (((bVar1 == 5) && ((local_2c[-2] & 0x10) != 0)) &&
                         ((pbVar11[-2] & 0x20) != 0)) {
                        hbox = *(_HBox **)(pbVar11 + 1);
                        hbox->maxX = (short)((int)hbox->refMaxX * (int)(instance2->scale).x >> 0xc);
                        hbox->maxY = (short)((int)hbox->refMaxY * (int)(instance2->scale).y >> 0xc);
                        hbox->maxZ = (short)((int)hbox->refMaxZ * (int)(instance2->scale).z >> 0xc);
                        hbox->minX = (short)((int)hbox->refMinX * (int)(instance2->scale).x >> 0xc);
                        hbox->minY = (short)((int)hbox->refMinY * (int)(instance2->scale).y >> 0xc);
                        hbox->minZ = (short)((int)hbox->refMinZ * (int)(instance2->scale).z >> 0xc);
                        sVar2 = DAT_1f8001b4;
                        sVar8 = DAT_1f8001b2;
                        *local_7c = DAT_1f8001b0;
                        local_7c[1] = sVar8;
                        local_7c[2] = sVar2;
                        lVar7 = COLLIDE_SphereAndHBox
                                          (hbox,(_Sphere *)&DAT_1f8001b0,local_64,
                                           (_SVector *)&DAT_1f800228);
                        if (lVar7 != 0) {
                          *(short *)local_68 = DAT_1f8001b0 - *local_7c;
                          sVar8 = DAT_1f8001b4 - local_7c[2];
                          *(short *)((int)local_68 + 2) = DAT_1f8001b2 - local_7c[1];
                          *(short *)(local_68 + 1) = sVar8;
                          setCopControlWord(2,0,*(undefined4 *)local_48->m);
                          setCopControlWord(2,0x800,*(undefined4 *)(local_48->m + 2));
                          setCopControlWord(2,0x1000,*(undefined4 *)(local_48->m + 4));
                          setCopControlWord(2,0x1800,*(undefined4 *)(local_48->m + 6));
                          setCopControlWord(2,0x2000,*(undefined4 *)(local_48->m + 8));
                          setCopReg(2,in_zero,*local_68);
                          setCopReg(2,in_at,local_68[1]);
                          copFunction(2,0x486012);
                          uVar3 = getCopReg(2,0x19);
                          *local_78 = uVar3;
                          uVar3 = getCopReg(2,0x1a);
                          local_78[1] = uVar3;
                          uVar3 = getCopReg(2,0x1b);
                          local_78[2] = uVar3;
                          collide_lwTransform = local_48;
                          if (instance2->collideFunc != (_func_2 *)0x0) {
                            DAT_1f800214 = 2;
                            DAT_1f800217 = 1;
                            DAT_1f800238 = -*(short *)local_78;
                            DAT_1f80023a = -*(short *)(local_78 + 1);
                            DAT_1f80023c = -*(short *)(local_78 + 2);
                            DAT_1f800215 = *pbVar11;
                            DAT_1f800216 = bVar1;
                            DAT_1f800218 = hbox;
                            DAT_1f80021c = p_Var12;
                            DAT_1f800220 = instance2;
                            DAT_1f800224 = instance1;
                            *(undefined4 **)&instance2->collideInfo = &DAT_1f800210;
                            (*instance2->collideFunc)(instance2,&gameTrackerX);
                          }
                          if (instance1->collideFunc != (_func_2 *)0x0) {
                            DAT_1f800216 = 1;
                            DAT_1f800238 = *(short *)local_78;
                            DAT_1f80023a = *(short *)(local_78 + 1);
                            DAT_1f80023c = *(short *)(local_78 + 2);
                            DAT_1f800214 = 8;
                            DAT_1f800215 = *local_2c;
                            DAT_1f800217 = bVar1;
                            DAT_1f800218 = p_Var12;
                            DAT_1f80021c = hbox;
                            DAT_1f800220 = instance1;
                            DAT_1f800224 = instance2;
                            *(undefined4 **)&instance1->collideInfo = &DAT_1f800210;
                            (*instance1->collideFunc)(instance1,&gameTrackerX);
                          }
                        }
                      }
                    }
                  }
                }
              }
              pbVar11 = pbVar11 + 8;
              local_34 = local_34 + -1;
              local_3c = local_3c + 1;
            } while (local_34 != 0);
          }
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
 // line 2761, offset 0x800224e4
	/* begin block 1 */
		// Start line: 2762
		// Start offset: 0x800224E4
		// Variables:
	// 		long lx; // $a1
	// 		long ly; // $a3
	// 		long lz; // $a2
	// 		long mrmr; // $v0

		/* begin block 1.1 */
			// Start line: 2806
			// Start offset: 0x80022510
			// Variables:
		// 		long x; // $a1
		// 		long y; // $a3
		// 		long z; // $a2
		/* end block 1.1 */
		// End offset: 0x80022510
		// End Line: 2806
	/* end block 1 */
	// End offset: 0x80022618
	// End Line: 2828

	/* begin block 2 */
		// Start line: 7060
	/* end block 2 */
	// End Line: 7061

void COLLIDE_Instances(_Instance *instance1,_Instance *instance2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((instance1 != instance2) && (iVar1 = INSTANCE_Linked(instance1,instance2), iVar1 == 0)) {
    iVar1 = (int)instance1->object->modelList[instance1->currentModel]->maxRad +
            (int)instance2->object->modelList[instance2->currentModel]->maxRad >> 1;
    setCopReg(2,0x4800,(int)(instance1->position).x - (int)(instance2->position).x >> 1);
    setCopReg(2,0x5000,(int)(instance1->position).y - (int)(instance2->position).y >> 1);
    setCopReg(2,0x5800,(int)(instance1->position).z - (int)(instance2->position).z >> 1);
    copFunction(2,0xa00428);
    iVar2 = getCopReg(2,0xc800);
    iVar4 = getCopReg(2,0xd000);
    iVar3 = getCopReg(2,0xd800);
    if ((((uint)(iVar2 + iVar4 + iVar3) < (uint)(iVar1 * iVar1)) &&
        (((instance1->matrix != (MATRIX *)0x0 && (instance1->oldMatrix != (MATRIX *)0x0)) &&
         (instance2->matrix != (MATRIX *)0x0)))) && (instance2->oldMatrix != (MATRIX *)0x0)) {
      COLLIDE_Instance1SpheresToInstance2(instance1,instance2,1);
      COLLIDE_Instance1SpheresToInstance2(instance2,instance1,0);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ COLLIDE_InstanceList(struct _InstanceList *instanceList /*$s7*/)
 // line 2839, offset 0x8002262c
	/* begin block 1 */
		// Start line: 2840
		// Start offset: 0x8002262C
		// Variables:
	// 		struct _Instance *instance; // $s1
	// 		struct _Instance *instance2; // $s0
	// 		struct _Instance *playerInstance; // $s2
	// 		long i; // $s4
	// 		long j; // $s2
	/* end block 1 */
	// End offset: 0x800228A4
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
  
  instance2 = gameTrackerX.playerInstance;
  if (gameTrackerX.cheatMode != '\x01') {
    iVar4 = 0x10;
    ppNVar1 = &instanceList->group[0xe].next;
    do {
      instance1 = (_Instance *)ppNVar1[4];
      while (instance1 != (_Instance *)0x0) {
        if ((instance1->flags2 & 0x24040000U) == 0) {
          COLLIDE_Instances(instance1,instance2);
        }
        instance1 = (_Instance *)(instance1->node).next;
      }
      iVar4 = iVar4 + 1;
      ppNVar1 = ppNVar1 + 2;
    } while (iVar4 < 0x20);
  }
  iVar4 = 0;
  plVar5 = &dyna_clddyna;
  do {
    instance2 = (_Instance *)instanceList->group[*plVar5].next;
    while (instance2 != (_Instance *)0x0) {
      if ((instance2->flags2 & 0x24040000U) == 0) {
        instance1 = (_Instance *)(instance2->node).next;
        while (instance1 != (_Instance *)0x0) {
          if ((instance1->flags2 & 0x24040000U) == 0) {
            COLLIDE_Instances(instance2,instance1);
          }
          instance1 = (_Instance *)(instance1->node).next;
        }
        iVar2 = iVar4 + 1;
        if (iVar2 < 8) {
          plVar3 = &dyna_clddyna + iVar2;
          do {
            instance1 = (_Instance *)instanceList->group[*plVar3].next;
            while (instance1 != (_Instance *)0x0) {
              if ((instance1->flags2 & 0x24040000U) == 0) {
                COLLIDE_Instances(instance2,instance1);
              }
              instance1 = (_Instance *)(instance1->node).next;
            }
            iVar2 = iVar2 + 1;
            plVar3 = plVar3 + 1;
          } while (iVar2 < 8);
        }
      }
      instance2 = (_Instance *)(instance2->node).next;
    }
    iVar4 = iVar4 + 1;
    plVar5 = plVar5 + 1;
  } while (iVar4 < 8);
  iVar4 = 0;
  do {
    instance2 = (_Instance *)instanceList->group[(&dyna_cldstat)[iVar4]].next;
    while (instance2 != (_Instance *)0x0) {
      if ((instance2->flags2 & 0x24040000U) == 0) {
        iVar2 = 0;
        plVar5 = &stat_clddyna;
        do {
          instance1 = (_Instance *)instanceList->group[*plVar5].next;
          while (instance1 != (_Instance *)0x0) {
            if ((instance1->flags2 & 0x24040000U) == 0) {
              COLLIDE_Instances(instance2,instance1);
            }
            instance1 = (_Instance *)(instance1->node).next;
          }
          iVar2 = iVar2 + 1;
          plVar5 = plVar5 + 1;
        } while (iVar2 < 8);
      }
      instance2 = (_Instance *)(instance2->node).next;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ COLLIDE_SphereAndHFace(struct _Sphere *sphere /*$s2*/, struct _Position *oldPos /*$a1*/, struct _HFaceInfo *hfaceInfo /*$s4*/, struct _SVector *intersect /*$s5*/, long *edge /*stack 16*/)
 // line 3061, offset 0x800228d4
	/* begin block 1 */
		// Start line: 3062
		// Start offset: 0x800228D4
		// Variables:
	// 		struct SandHFScratch *CSpad; // $s0
	// 		struct _SVector *vertex0; // $a0
	// 		long result; // $s6
	// 		long behind; // $v0
	// 		unsigned long d0sq; // $s1

		/* begin block 1.1 */
			// Start line: 3126
			// Start offset: 0x80022AEC
			// Variables:
		// 		struct _Vector dv; // stack offset -64

			/* begin block 1.1.1 */
				// Start line: 3128
				// Start offset: 0x80022AEC
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			// 		struct _SVector *_v0; // $v0
			/* end block 1.1.1 */
			// End offset: 0x80022AEC
			// End Line: 3128
		/* end block 1.1 */
		// End offset: 0x80022BCC
		// End Line: 3141

		/* begin block 1.2 */
			// Start line: 3143
			// Start offset: 0x80022BCC
			// Variables:
		// 		long y; // $v1
		// 		long z; // $v0
		/* end block 1.2 */
		// End offset: 0x80022BCC
		// End Line: 3143

		/* begin block 1.3 */
			// Start line: 3147
			// Start offset: 0x80022C3C
			// Variables:
		// 		unsigned long d1sq; // $a0

			/* begin block 1.3.1 */
				// Start line: 3149
				// Start offset: 0x80022C3C
				// Variables:
			// 		long y; // $v1
			// 		long z; // $v0
			/* end block 1.3.1 */
			// End offset: 0x80022C3C
			// End Line: 3149

			/* begin block 1.3.2 */
				// Start line: 3161
				// Start offset: 0x80022CE0
				// Variables:
			// 		long y; // $v1
			// 		long z; // $v0
			/* end block 1.3.2 */
			// End offset: 0x80022CE0
			// End Line: 3161
		/* end block 1.3 */
		// End offset: 0x80022D70
		// End Line: 3170

		/* begin block 1.4 */
			// Start line: 3174
			// Start offset: 0x80022D84
			// Variables:
		// 		long len; // $a2
		// 		struct _Vector dv; // stack offset -64

			/* begin block 1.4.1 */
				// Start line: 3176
				// Start offset: 0x80022D84
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
			// End offset: 0x80022D84
			// End Line: 3176

			/* begin block 1.4.2 */
				// Start line: 3176
				// Start offset: 0x80022D84
				// Variables:
			// 		long a; // stack offset -48
			// 		long b; // stack offset -44
			// 		long c; // stack offset -40
			/* end block 1.4.2 */
			// End offset: 0x80022D84
			// End Line: 3176
		/* end block 1.4 */
		// End offset: 0x80022F84
		// End Line: 3198
	/* end block 1 */
	// End offset: 0x80022F88
	// End Line: 3201

	/* begin block 2 */
		// Start line: 6122
	/* end block 2 */
	// End Line: 6123

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long COLLIDE_SphereAndHFace
               (_Sphere *sphere,_Position *oldPos,_HFaceInfo *hfaceInfo,_SVector *intersect,
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
  long local_30;
  long local_2c;
  long local_28 [2];
  
  p_Var5 = hfaceInfo->vertex0;
  lVar10 = 0;
  if ((hfaceInfo->hface->attr & 0x40) == 0) {
    *edge = 1;
    _DAT_1f80005c = CONCAT22((sphere->position).y - p_Var5->y,(sphere->position).x - p_Var5->x);
    _DAT_1f800060 = CONCAT22(oldPos->x - p_Var5->x,(sphere->position).z - p_Var5->z);
    _DAT_1f800064 = CONCAT22(oldPos->z - p_Var5->z,oldPos->y - p_Var5->y);
    _DAT_1f800068 = *(undefined4 *)p_Var5;
    _DAT_1f80006c = CONCAT22(DAT_1f80006e,p_Var5->z);
    DAT_1f800054 = *(undefined4 *)&hfaceInfo->normal;
    DAT_1f800058 = *(undefined4 *)&(hfaceInfo->normal).z;
    setCopControlWord(2,0,_DAT_1f80005c);
    setCopControlWord(2,0x800,_DAT_1f800060);
    setCopControlWord(2,0x1000,_DAT_1f800064);
    setCopControlWord(2,0x1800,_DAT_1f800068);
    setCopControlWord(2,0x2000,_DAT_1f80006c);
    setCopReg(2,in_zero,DAT_1f800054);
    setCopReg(2,in_at,DAT_1f800058);
    copFunction(2,0x486012);
    DAT_1f80007c = getCopReg(2,0x19);
    DAT_1f800080 = getCopReg(2,0x1a);
    DAT_1f800084 = getCopReg(2,0x1b);
    lVar10 = 0;
    if (((DAT_1f80007c <= DAT_1f800080) && (lVar10 = 0, DAT_1f80007c < (int)(uint)sphere->radius))
       && (lVar10 = 0, (int)-(uint)sphere->radius <= DAT_1f800080)) {
      if (DAT_1f80007c < 0) {
        iVar3 = COLLIDE_IntersectLineAndPlane_S
                          (&DAT_1f800090,oldPos,sphere,&DAT_1f800054,DAT_1f800084);
        if (iVar3 == 0) {
          return 0;
        }
      }
      else {
        COLLIDE_NearestPointOnPlane_S
                  ((short *)&DAT_1f800090,&DAT_1f800054,DAT_1f800084,(undefined4 *)sphere);
      }
      iVar3 = COLLIDE_PointInTriangle
                        ((_SVector *)hfaceInfo->vertex0,(_SVector *)hfaceInfo->vertex1,
                         (_SVector *)hfaceInfo->vertex2,(_SVector *)&DAT_1f800090,
                         (_SVector *)&DAT_1f800054);
      if (iVar3 == 0) {
        COLLIDE_NearestPointOnLine_S
                  (&DAT_1f800088,(uint *)hfaceInfo->vertex0,(uint *)hfaceInfo->vertex1,
                   (uint *)sphere);
        setCopReg(2,0x4800,(int)(sphere->position).x - (int)(short)DAT_1f800088);
        setCopReg(2,0x5000,(int)(sphere->position).y - (int)DAT_1f800088._2_2_);
        setCopReg(2,0x5800,(int)(sphere->position).z - (int)DAT_1f80008c);
        copFunction(2,0xa00428);
        iVar7 = getCopReg(2,0xc800);
        iVar4 = getCopReg(2,0xd000);
        iVar3 = getCopReg(2,0xd800);
        uVar8 = iVar7 + iVar4 + iVar3;
        if (sphere->radiusSquared <= uVar8) {
          COLLIDE_NearestPointOnLine_S
                    (&DAT_1f800090,(uint *)hfaceInfo->vertex1,(uint *)hfaceInfo->vertex2,
                     (uint *)sphere);
          setCopReg(2,0x4800,(int)(sphere->position).x - (int)(short)DAT_1f800090);
          setCopReg(2,0x5000,(int)(sphere->position).y - (int)DAT_1f800090._2_2_);
          setCopReg(2,0x5800,(int)(sphere->position).z - (int)(short)DAT_1f800094);
          copFunction(2,0xa00428);
          iVar7 = getCopReg(2,0xc800);
          iVar4 = getCopReg(2,0xd000);
          iVar3 = getCopReg(2,0xd800);
          uVar6 = iVar7 + iVar4 + iVar3;
          if (uVar6 < uVar8) {
            DAT_1f800088 = DAT_1f800090;
            _DAT_1f80008c = DAT_1f800094;
            uVar8 = uVar6;
          }
          if (sphere->radiusSquared <= uVar8) {
            COLLIDE_NearestPointOnLine_S
                      (&DAT_1f800090,(uint *)hfaceInfo->vertex2,(uint *)hfaceInfo->vertex0,
                       (uint *)sphere);
            setCopReg(2,0x4800,(int)(sphere->position).x - (int)(short)DAT_1f800090);
            setCopReg(2,0x5000,(int)(sphere->position).y - (int)DAT_1f800090._2_2_);
            setCopReg(2,0x5800,(int)(sphere->position).z - (int)(short)DAT_1f800094);
            copFunction(2,0xa00428);
            iVar7 = getCopReg(2,0xc800);
            iVar4 = getCopReg(2,0xd000);
            iVar3 = getCopReg(2,0xd800);
            uVar6 = iVar7 + iVar4 + iVar3;
            if (uVar6 < uVar8) {
              DAT_1f800088 = DAT_1f800090;
              _DAT_1f80008c = DAT_1f800094;
              uVar8 = uVar6;
            }
            if (sphere->radiusSquared <= uVar8) {
              return 0;
            }
          }
        }
        iVar3 = (int)(sphere->position).x - (int)(short)DAT_1f800088;
        iVar4 = (int)(sphere->position).y - (int)DAT_1f800088._2_2_;
        iVar7 = (int)(sphere->position).z - (int)DAT_1f80008c;
        local_30 = iVar3;
        if (iVar3 < 0) {
          local_30 = -iVar3;
        }
        local_2c = iVar4;
        if (iVar4 < 0) {
          local_2c = -iVar4;
        }
        local_28[0] = iVar7;
        if (iVar7 < 0) {
          local_28[0] = -iVar7;
        }
        MATH3D_Sort3VectorCoords(&local_30,&local_2c,local_28);
        intersect->x = (short)DAT_1f800088;
        intersect->y = DAT_1f800088._2_2_;
        intersect->z = DAT_1f80008c;
        iVar9 = local_28[0] * 0x1e + local_2c * 0xc + local_30 * 9;
        if (iVar9 == 0) {
          local_40 = (short)((int)((int)(short)DAT_1f800054 * (uint)sphere->radius) >> 0xc);
          local_3c = (short)((int)((int)DAT_1f800054._2_2_ * (uint)sphere->radius) >> 0xc);
          local_38 = (short)((int)((int)(short)DAT_1f800058 * (uint)sphere->radius) >> 0xc);
        }
        else {
          local_3c = (short)((int)(iVar4 * (uint)sphere->radius * 0x20) / iVar9);
          local_38 = (short)((int)(iVar7 * (uint)sphere->radius * 0x20) / iVar9);
          local_40 = (short)((int)(iVar3 * (uint)sphere->radius * 0x20) / iVar9);
        }
        (sphere->position).x = local_40 + (short)DAT_1f800088;
        (sphere->position).y = local_3c + DAT_1f800088._2_2_;
        lVar10 = 1;
        (sphere->position).z = local_38 + DAT_1f80008c;
      }
      else {
        DAT_1f800088 = DAT_1f800090;
        _DAT_1f80008c = _DAT_1f80008c & 0xffff0000 | DAT_1f800094 & 0xffff;
        intersect->x = (short)DAT_1f800090;
        intersect->y = DAT_1f800088._2_2_;
        intersect->z = DAT_1f80008c;
        uVar1 = sphere->radius;
        uVar2 = sphere->radius;
        local_40 = (short)((int)((int)(short)DAT_1f800054 * (uint)sphere->radius) >> 0xc);
        (sphere->position).x = local_40 + (short)DAT_1f800088;
        local_3c = (short)((int)((int)DAT_1f800054._2_2_ * (uint)uVar1) >> 0xc);
        (sphere->position).y = local_3c + DAT_1f800088._2_2_;
        local_38 = (short)((int)((int)(short)DAT_1f800058 * (uint)uVar2) >> 0xc);
        (sphere->position).z = local_38 + DAT_1f80008c;
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
 // line 3243, offset 0x80022fb0
	/* begin block 1 */
		// Start line: 3244
		// Start offset: 0x80022FB0
		// Variables:
	// 		struct SandTScratch *CSpad; // $s0
	// 		void **stack; // $s1
	// 		struct _BSPNode *bspNode; // $a1
	// 		struct _Terrain *terrain; // $s5
	// 		long curTree; // stack offset -44

		/* begin block 1.1 */
			// Start line: 3280
			// Start offset: 0x8002302C
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $v0
		// 		struct _SVector *_v0; // $s2
		// 		struct _SVector *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x8002302C
		// End Line: 3280

		/* begin block 1.2 */
			// Start line: 3280
			// Start offset: 0x8002302C
			// Variables:
		// 		long a; // stack offset -56
		// 		long b; // stack offset -52
		// 		long c; // stack offset -48
		/* end block 1.2 */
		// End offset: 0x8002302C
		// End Line: 3280

		/* begin block 1.3 */
			// Start line: 3314
			// Start offset: 0x8002321C
			// Variables:
		// 		struct BSPTree *bsp; // $s4

			/* begin block 1.3.1 */
				// Start line: 3329
				// Start offset: 0x800232A8
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
			// End offset: 0x800232A8
			// End Line: 3329

			/* begin block 1.3.2 */
				// Start line: 3329
				// Start offset: 0x800232A8
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a0
			// 		short _x1; // $a1
			// 		short _y1; // $a2
			// 		short _z1; // $a3
			// 		struct _SVector *_v; // $s7
			/* end block 1.3.2 */
			// End offset: 0x800232A8
			// End Line: 3329

			/* begin block 1.3.3 */
				// Start line: 3329
				// Start offset: 0x800232A8
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a0
			// 		short _x1; // $a1
			// 		short _y1; // $a2
			// 		short _z1; // $a3
			// 		struct _Position *_v; // $s6
			/* end block 1.3.3 */
			// End offset: 0x800232A8
			// End Line: 3329

			/* begin block 1.3.4 */
				// Start line: 3244
				// Start offset: 0x800233AC
				// Variables:
			// 		struct _SVector *point; // $t0
			// 		struct _BoundingBox *box; // $a3
			/* end block 1.3.4 */
			// End offset: 0x80023444
			// End Line: 3244

			/* begin block 1.3.5 */
				// Start line: 3365
				// Start offset: 0x8002344C
				// Variables:
			// 		struct _TFace *tface; // $s3

				/* begin block 1.3.5.1 */
					// Start line: 3385
					// Start offset: 0x800234F0
					// Variables:
				// 		struct _SVector *vertex0; // $a3

					/* begin block 1.3.5.1.1 */
						// Start line: 3244
						// Start offset: 0x80023568
						// Variables:
					// 		short *nrmlArray; // $a0
					// 		struct _SVector *nrml; // $a1

						/* begin block 1.3.5.1.1.1 */
							// Start line: 3244
							// Start offset: 0x80023568
							// Variables:
						// 		short *sPtr; // $v1
						/* end block 1.3.5.1.1.1 */
						// End offset: 0x800235F8
						// End Line: 3244
					/* end block 1.3.5.1.1 */
					// End offset: 0x800235F8
					// End Line: 3244

					/* begin block 1.3.5.1.2 */
						// Start line: 3417
						// Start offset: 0x8002368C
					/* end block 1.3.5.1.2 */
					// End offset: 0x800237EC
					// End Line: 3469
				/* end block 1.3.5.1 */
				// End offset: 0x800237EC
				// End Line: 3470
			/* end block 1.3.5 */
			// End offset: 0x8002380C
			// End Line: 3473

			/* begin block 1.3.6 */
				// Start line: 3484
				// Start offset: 0x80023834
				// Variables:
			// 		int plane_front_error; // $v0
			// 		int plane_back_error; // $a3
			/* end block 1.3.6 */
			// End offset: 0x80023984
			// End Line: 3547

			/* begin block 1.3.7 */
				// Start line: 3551
				// Start offset: 0x80023994
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a0
			// 		short _x1; // $a1
			// 		short _y1; // $a2
			// 		short _z1; // $a3
			// 		struct _Position *_v1; // $t0
			/* end block 1.3.7 */
			// End offset: 0x80023994
			// End Line: 3551

			/* begin block 1.3.8 */
				// Start line: 3551
				// Start offset: 0x80023994
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a0
			// 		short _x1; // $a1
			// 		short _y1; // $a2
			// 		short _z1; // $a3
			/* end block 1.3.8 */
			// End offset: 0x80023994
			// End Line: 3551

			/* begin block 1.3.9 */
				// Start line: 3551
				// Start offset: 0x80023994
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a0
			// 		short _x1; // $a1
			// 		short _y1; // $a2
			// 		short _z1; // $a3
			/* end block 1.3.9 */
			// End offset: 0x80023A28
			// End Line: 3553
		/* end block 1.3 */
		// End offset: 0x80023A28
		// End Line: 3554

		/* begin block 1.4 */
			// Start line: 3555
			// Start offset: 0x80023A40
			// Variables:
		// 		short _x1; // $a0
		// 		short _y1; // $a1
		// 		short _z1; // $v1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v1
		/* end block 1.4 */
		// End offset: 0x80023A40
		// End Line: 3555
	/* end block 1 */
	// End offset: 0x80023A6C
	// End Line: 3557

	/* begin block 2 */
		// Start line: 8066
	/* end block 2 */
	// End Line: 8067

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long COLLIDE_SAndT(SCollideInfo *scollideInfo,Level *level)

{
  byte bVar1;
  short sVar2;
  bool bVar3;
  uint uVar4;
  undefined4 in_zero;
  undefined4 in_at;
  short sVar5;
  _Sphere *p_Var6;
  SVECTOR *pSVar7;
  long lVar8;
  ulong uVar9;
  _BSPNode *p_Var10;
  _Normal *p_Var11;
  ushort uVar12;
  int iVar13;
  int iVar14;
  _TVertex *p_Var15;
  _BSPNode *p_Var16;
  _BSPNode *p_Var17;
  ushort *puVar18;
  _TFace *tface;
  BSPTree *pBVar19;
  _Terrain *terrain;
  long local_38;
  long local_34;
  long local_30;
  int local_2c;
  
  terrain = level->terrain;
  p_Var17 = (_BSPNode *)&DAT_1f80029c;
  if (gameTrackerX.gameData.asmData.MorphTime == 1000) {
    DAT_1f800264 = (int)gameTrackerX.gameData.asmData.MorphType;
    if (DAT_1f800264 != 1) {
      DAT_1f800264 = 0;
    }
  }
  else {
    DAT_1f800264 = 2;
  }
  DAT_1f8001f4 = terrain->normalList;
  DAT_1f800298 = terrain->vertexList;
  DAT_1f800258 = scollideInfo->collideFunc;
  DAT_1f80025c = scollideInfo->instance;
  DAT_1f800270 = scollideInfo->prim;
  p_Var6 = scollideInfo->sphere;
  DAT_1f80027c = *(undefined4 *)&p_Var6->position;
  DAT_1f800280 = *(uint *)&(p_Var6->position).z;
  DAT_1f800284 = p_Var6->radiusSquared;
  DAT_1f800288 = 0;
  DAT_1f80028c = 0;
  DAT_1f800290 = 0;
  pSVar7 = scollideInfo->oldPos;
  DAT_1f800268 = pSVar7->vx;
  DAT_1f80026a = pSVar7->vy;
  DAT_1f80026c = pSVar7->vz;
  DAT_1f80027c._2_2_ = (short)((uint)DAT_1f80027c >> 0x10);
  DAT_1f800250 = (short)DAT_1f80027c;
  DAT_1f800248._0_2_ = (short)DAT_1f80027c - DAT_1f800268;
  DAT_1f800252 = DAT_1f80027c._2_2_;
  DAT_1f800254._0_2_ = (short)DAT_1f800280;
  DAT_1f800248._2_2_ = DAT_1f80027c._2_2_ - DAT_1f80026a;
  local_38 = (int)(short)DAT_1f800248;
  DAT_1f80024c = (short)DAT_1f800280 - DAT_1f80026c;
  if (local_38 < 0) {
    local_38 = -local_38;
  }
  local_34 = (int)DAT_1f800248._2_2_;
  local_30 = (int)DAT_1f80024c;
  if (local_34 < 0) {
    local_34 = -local_34;
  }
  if (local_30 < 0) {
    local_30 = -local_30;
  }
  MATH3D_Sort3VectorCoords(&local_38,&local_34,&local_30);
  DAT_1f800294 = local_30 * 0x1e + local_34 * 0xc + local_38 * 9;
  lVar8 = 0;
  if (DAT_1f800294 != 0) {
    DAT_1f800248._0_2_ = (short)((int)DAT_1f800250 + (int)DAT_1f800268 >> 1);
    DAT_1f800248._2_2_ = (short)((int)DAT_1f800252 + (int)DAT_1f80026a >> 1);
    DAT_1f80024c = (short)((int)(short)DAT_1f800254 + (int)DAT_1f80026c >> 1);
    DAT_1f800294 = DAT_1f800294 / 2 + (DAT_1f800280 >> 0x10);
    if (DAT_1f800264 == 2) {
      DAT_1f800294 = DAT_1f800294 + 0x800;
    }
    local_2c = 0;
    if (0 < terrain->numBSPTrees) {
      do {
        pBVar19 = terrain->BSPTreeArray + local_2c;
        if ((((-1 < pBVar19->ID) &&
             ((uVar12 = pBVar19->flags, (uVar12 & 0x4000) == 0 ||
              (gameTrackerX.raziel_collide_override != '\0')))) &&
            (((uVar12 & 0x2000) == 0 || (gameTrackerX.monster_collide_override != '\0')))) &&
           (((uVar12 & 0x102) == 0 ||
            (((uVar12 & 0xe0) != 0 && (uVar9 = INSTANCE_Query(DAT_1f80025c,1), (uVar9 & 2) != 0)))))
           ) {
          DAT_1f800224._2_2_ = pBVar19->ID;
          DAT_1f800268 = DAT_1f800268 - (pBVar19->globalOffset).x;
          DAT_1f8001d0 = DAT_1f80026a - (pBVar19->globalOffset).y;
          DAT_1f8001d2 = DAT_1f80026c - (pBVar19->globalOffset).z;
          DAT_1f800248._0_2_ = (short)DAT_1f800248 - (pBVar19->globalOffset).x;
          DAT_1f800248._2_2_ = DAT_1f800248._2_2_ - (pBVar19->globalOffset).y;
          DAT_1f80024c = DAT_1f80024c - (pBVar19->globalOffset).z;
          DAT_1f80027c._0_2_ = (short)DAT_1f80027c - (pBVar19->globalOffset).x;
          DAT_1f80027c._2_2_ = DAT_1f80027c._2_2_ - (pBVar19->globalOffset).y;
          uVar12 = (short)DAT_1f800280 - (pBVar19->globalOffset).z;
          DAT_1f800280 = DAT_1f800280 & 0xffff0000 | (uint)uVar12;
          _DAT_1f8001c8 = CONCAT22(DAT_1f80027c._2_2_,(short)DAT_1f80027c);
          _DAT_1f8001cc = CONCAT22(DAT_1f800268,uVar12);
          DAT_1f80026a = DAT_1f8001d0;
          DAT_1f80026c = DAT_1f8001d2;
          *(_BSPNode **)&(p_Var17->sphere).position = p_Var17;
          SetRotMatrix((undefined4 *)&DAT_1f8001c8);
          p_Var10 = pBVar19->bspRoot;
          p_Var17 = (_BSPNode *)&(p_Var17->sphere).position.z;
          *(_BSPNode **)&(p_Var17->sphere).position = p_Var10;
          p_Var16 = p_Var17;
          if (p_Var10 != p_Var17) {
            do {
              iVar13 = *(int *)&(p_Var16->sphere).position;
              p_Var17 = (_BSPNode *)&p_Var16[-1].front_material_error;
              if ((*(ushort *)(iVar13 + 0xe) & 2) == 0) {
                setCopReg(2,in_zero,*(undefined4 *)(iVar13 + 8));
                setCopReg(2,in_at,*(undefined4 *)(iVar13 + 0xc));
                copFunction(2,0x486012);
                DAT_1f8001e8 = getCopReg(2,0x19);
                _DAT_1f8001ec = getCopReg(2,0x1a);
                _DAT_1f8001f0 = getCopReg(2,0x1b);
                DAT_1f8001e8 = DAT_1f8001e8 - *(int *)(iVar13 + 0x10);
                _DAT_1f8001ec = _DAT_1f8001ec - *(int *)(iVar13 + 0x10);
                if (DAT_1f800264 == 0) {
                  sVar5 = *(short *)(iVar13 + 0x28);
                  sVar2 = *(short *)(iVar13 + 0x2a);
                }
                else {
                  sVar5 = *(short *)(iVar13 + 0x24);
                  sVar2 = *(short *)(iVar13 + 0x26);
                }
                iVar14 = (DAT_1f800280 >> 0x10) + (int)sVar5;
                if (_DAT_1f8001ec < iVar14) {
                  iVar14 = (int)sVar2 - (DAT_1f800280 >> 0x10);
                  if (iVar14 < _DAT_1f8001ec) {
                    if (DAT_1f8001e8 < _DAT_1f8001ec) goto LAB_80023954;
                    if (*(int *)(iVar13 + 0x14) != 0) {
                      *(int *)&(p_Var16->sphere).position = *(int *)(iVar13 + 0x14);
                      p_Var17 = p_Var16;
                    }
                    iVar13 = *(int *)(iVar13 + 0x18);
                  }
                  else {
                    if ((iVar14 <= DAT_1f8001e8) && (*(int *)(iVar13 + 0x14) != 0)) {
                      *(int *)&(p_Var16->sphere).position = *(int *)(iVar13 + 0x14);
                      p_Var17 = p_Var16;
                    }
                    iVar13 = *(int *)(iVar13 + 0x18);
                  }
                }
                else {
                  if (DAT_1f8001e8 <= iVar14) {
LAB_80023954:
                    if (*(int *)(iVar13 + 0x18) != 0) {
                      *(int *)&(p_Var16->sphere).position = *(int *)(iVar13 + 0x18);
                      p_Var17 = p_Var16;
                    }
                  }
                  iVar13 = *(int *)(iVar13 + 0x14);
                }
                if (iVar13 != 0) {
                  p_Var17 = (_BSPNode *)&(p_Var17->sphere).position.z;
                  *(int *)&(p_Var17->sphere).position = iVar13;
                }
              }
              else {
                bVar3 = false;
                iVar14 = (int)(short)DAT_1f800294;
                if (((((short)DAT_1f800248 - iVar14 < (int)*(short *)(iVar13 + 0x16)) &&
                     ((int)*(short *)(iVar13 + 0x10) < (short)DAT_1f800248 + iVar14)) &&
                    (DAT_1f800248._2_2_ - iVar14 < (int)*(short *)(iVar13 + 0x18))) &&
                   (((int)*(short *)(iVar13 + 0x12) < DAT_1f800248._2_2_ + iVar14 &&
                    (DAT_1f80024c - iVar14 < (int)*(short *)(iVar13 + 0x1a))))) {
                  bVar3 = (int)*(short *)(iVar13 + 0x14) < DAT_1f80024c + iVar14;
                }
                if (bVar3) {
                  _DAT_1f8001c8 = DAT_1f80027c;
                  uVar4 = _DAT_1f8001cc & 0xffff0000;
                  _DAT_1f8001cc = uVar4 | DAT_1f800280 & 0xffff;
                  DAT_1f8001ce = (ushort)(uVar4 >> 0x10);
                  setCopControlWord(2,0,DAT_1f80027c);
                  setCopControlWord(2,0x800,_DAT_1f8001cc);
                  DAT_1f80028a = *(short *)(iVar13 + 0xc);
                  tface = *(_TFace **)(iVar13 + 8);
                  puVar18 = &(tface->face).v2;
                  if (DAT_1f80028a != 0) {
                    do {
                      bVar1 = *(byte *)(puVar18 + 1);
                      if (((((bVar1 & DAT_1f80028c) == 0) || ((bVar1 & DAT_1f800290) != 0)) &&
                          ((puVar18[3] == 0xffff ||
                           ((*(ushort *)((int)&terrain->StartTextureList->attr + (uint)puVar18[3]) &
                            0x2000) == 0)))) && ((bVar1 & 8) == 0)) {
                        if ((DAT_1f800264 == 2) &&
                           ((uint)puVar18[2] !=
                            (int)terrain->morphNormalIdx
                                 [(int)((int)tface - (int)terrain->faceList) * -0x55555555 >> 2])) {
                          COLLIDE_MakeNormal(terrain,tface,(_SVector *)&DAT_1f800274);
                        }
                        else {
                          iVar13 = (int)(short)puVar18[2];
                          if (iVar13 < 0) {
                            p_Var11 = (_Normal *)((int)DAT_1f8001f4 + iVar13 * -6);
                            DAT_1f800274 = CONCAT22(-p_Var11->y,-(p_Var11->x & 0x1fffU));
                            DAT_1f800278 = DAT_1f800278 & 0xffff0000 | (uint)(ushort)-p_Var11->z;
                          }
                          else {
                            DAT_1f800274 = *(uint *)(&DAT_1f8001f4->x + iVar13 * 3) & 0xffff1fff;
                            DAT_1f800278 = DAT_1f800278 & 0xffff0000 |
                                           (uint)(ushort)(&DAT_1f8001f4->x + iVar13 * 3)[1];
                          }
                        }
                        p_Var15 = DAT_1f800298 + (tface->face).v0;
                        setCopControlWord(2,0x1800,*(undefined4 *)&p_Var15->vertex);
                        setCopControlWord(2,0x2000,*(undefined4 *)&(p_Var15->vertex).z);
                        setCopReg(2,in_zero,DAT_1f800274);
                        setCopReg(2,in_at,DAT_1f800278);
                        copFunction(2,0x486012);
                        DAT_1f8001e8 = getCopReg(2,0x19);
                        _DAT_1f8001ec = getCopReg(2,0x1a);
                        _DAT_1f8001f0 = getCopReg(2,0x1b);
                        if (DAT_1f8001e8 <= _DAT_1f8001ec) {
                          if ((DAT_1f8001e8 - _DAT_1f8001f0 < (int)(DAT_1f800280 >> 0x10)) &&
                             ((int)-(DAT_1f800280 >> 0x10) <= _DAT_1f8001ec - _DAT_1f8001f0)) {
                            DAT_1f800240 = DAT_1f800298 + (short)puVar18[-1];
                            DAT_1f800244 = DAT_1f800298 + (short)*puVar18;
                            DAT_1f800234 = DAT_1f800274;
                            _DAT_1f800238 = DAT_1f800278;
                            DAT_1f800230 = tface;
                            _DAT_1f80023c = p_Var15;
                            lVar8 = COLLIDE_SphereAndHFace
                                              ((_Sphere *)&DAT_1f80027c,(_Position *)&DAT_1f800268,
                                               (_HFaceInfo *)&DAT_1f800228,(_SVector *)&DAT_1f800218
                                               ,&DAT_1f800260);
                            if (lVar8 != 0) {
                              if (DAT_1f800260 == 0) {
                                DAT_1f8001fc._0_1_ = 8;
                              }
                              else {
                                DAT_1f8001fc._0_1_ = 4;
                              }
                              DAT_1f8001fe = 1;
                              DAT_1f8001ff = 3;
                              _DAT_1f800208 = DAT_1f80025c;
                              DAT_1f8001fc._1_1_ = *(undefined *)&scollideInfo->segment;
                              DAT_1f800200 = DAT_1f800270;
                              DAT_1f800220._2_2_ = DAT_1f80027c._2_2_ - DAT_1f8001ca;
                              DAT_1f800220._0_2_ = (short)DAT_1f80027c - DAT_1f8001c8;
                              DAT_1f800224._0_2_ = (short)DAT_1f800280 - DAT_1f8001cc;
                              _DAT_1f8001f8 = level;
                              _DAT_1f800204 = tface;
                              DAT_1f80020c = pBVar19;
                              if (DAT_1f80025c != (_Instance *)0x0) {
                                *(undefined2 **)&DAT_1f80025c->collideInfo = &DAT_1f8001f8;
                                if (DAT_1f800258 != (_func_22 *)0x0) {
                                  (*DAT_1f800258)(DAT_1f80025c,&gameTrackerX);
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
                  setCopControlWord(2,0,DAT_1f80027c);
                  setCopControlWord(2,0x800,_DAT_1f8001cc);
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
        local_2c = local_2c + 1;
      } while (local_2c < terrain->numBSPTrees);
    }
    p_Var6 = scollideInfo->sphere;
    (p_Var6->position).x = (short)DAT_1f80027c;
    (p_Var6->position).y = DAT_1f80027c._2_2_;
    (p_Var6->position).z = (short)DAT_1f800280;
    lVar8 = (long)DAT_1f800288;
  }
  return lVar8;
}



// decompiled code
// original method signature: 
// long /*$ra*/ COLLIDE_SphereAndTerrain(struct SCollideInfo *scollideInfo /*$s5*/, struct Level *level /*$s4*/)
 // line 3770, offset 0x80023a9c
	/* begin block 1 */
		// Start line: 3771
		// Start offset: 0x80023A9C
		// Variables:
	// 		int result; // $s3
	// 		int d; // $s1

		/* begin block 1.1 */
			// Start line: 3771
			// Start offset: 0x80023A9C
			// Variables:
		// 		int in_warpRoom; // $s2
		// 		struct _StreamUnit *stream; // $v0
		/* end block 1.1 */
		// End offset: 0x80023B5C
		// End Line: 3800
	/* end block 1 */
	// End offset: 0x80023B5C
	// End Line: 3802

	/* begin block 2 */
		// Start line: 9618
	/* end block 2 */
	// End Line: 9619

long COLLIDE_SphereAndTerrain(SCollideInfo *scollideInfo,Level *level)

{
  long lVar1;
  _StreamUnit *p_Var2;
  long lVar3;
  Level *address;
  STracker *pSVar4;
  int iVar5;
  ushort uVar6;
  
  lVar1 = COLLIDE_SAndT(scollideInfo,level);
  uVar6 = 0;
  p_Var2 = STREAM_GetStreamUnitWithID(level->streamUnitID);
  iVar5 = 0;
  if (p_Var2 != (_StreamUnit *)0x0) {
    uVar6 = p_Var2->flags & 1;
  }
  pSVar4 = &StreamTracker;
  do {
    if ((((pSVar4->StreamList[0].used == 2) &&
         (address = pSVar4->StreamList[0].level, address != level)) &&
        ((uVar6 == 0 || ((pSVar4->StreamList[0].flags & 1U) == 0)))) &&
       (lVar3 = MEMPACK_MemoryValidFunc((char *)address), lVar3 != 0)) {
      lVar1 = COLLIDE_SAndT(scollideInfo,pSVar4->StreamList[0].level);
    }
    iVar5 = iVar5 + 1;
    pSVar4 = (STracker *)(pSVar4->StreamList + 1);
  } while (iVar5 < 0x10);
  return lVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ COLLIDE_InstanceTerrain(struct _Instance *instance /*stack 0*/, struct Level *level /*stack 4*/)
 // line 4238, offset 0x80023b84
	/* begin block 1 */
		// Start line: 4239
		// Start offset: 0x80023B84
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
			// Start offset: 0x80023C50
			// Variables:
		// 		int i; // $s7
		// 		struct _HModel *hmodel; // $v0
		// 		struct _HPrim *hprim; // $s6
		/* end block 1.1 */
		// End offset: 0x80023DBC
		// End Line: 4317
	/* end block 1 */
	// End offset: 0x80023DC0
	// End Line: 4321

	/* begin block 2 */
		// Start line: 10562
	/* end block 2 */
	// End Line: 10563

void COLLIDE_InstanceTerrain(_Instance *instance,Level *level)

{
  byte bVar1;
  MATRIX *pMVar2;
  MATRIX *pMVar3;
  void *pvVar4;
  byte *pbVar5;
  _HPrim *p_Var6;
  int iVar7;
  SCollideInfo local_60;
  undefined auStack64 [4];
  undefined2 *local_3c;
  undefined4 *local_38;
  _func_2 *local_34;
  undefined *local_30;
  
  local_3c = &DAT_1f800148;
  local_38 = &DAT_1f800158;
  if ((instance->matrix != (MATRIX *)0x0) && (instance->oldMatrix != (MATRIX *)0x0)) {
    if ((instance->object->oflags2 & 0x80000U) != 0) {
      gameTrackerX.monster_collide_override = '\x01';
    }
    local_34 = instance->collideFunc;
    if (local_34 != (_func_2 *)0x0) {
      iVar7 = instance->hModelList[instance->currentModel].numHPrims;
      p_Var6 = instance->hModelList[instance->currentModel].hPrimList;
      local_30 = auStack64;
      if (iVar7 != 0) {
        pbVar5 = &p_Var6->segment;
        do {
          if ((((p_Var6->hpFlags & 1) != 0) && ((pbVar5[-2] & 2) != 0)) && (pbVar5[-1] == 1)) {
            bVar1 = *pbVar5;
            pvVar4 = *(void **)(pbVar5 + 1);
            pMVar2 = instance->matrix;
            pMVar3 = instance->oldMatrix;
            SetRotMatrix((undefined4 *)(pMVar2 + bVar1));
            SetTransMatrix((int)(pMVar2 + bVar1));
            RotTrans((int)pvVar4 + 8,local_3c,local_30);
            SetRotMatrix((undefined4 *)(pMVar3 + bVar1));
            SetTransMatrix((int)(pMVar3 + bVar1));
            RotTrans((int)pvVar4 + 8,local_38,local_30);
            DAT_1f8001b8 = *local_3c;
            DAT_1f8001ba = local_3c[2];
            DAT_1f8001bc = local_3c[4];
            DAT_1f8001be = *(undefined2 *)((int)pvVar4 + 0xe);
            DAT_1f8001c0 = *(undefined4 *)((int)pvVar4 + 0x10);
            DAT_1f800168 = *(undefined2 *)local_38;
            DAT_1f80016a = *(undefined2 *)(local_38 + 1);
            DAT_1f80016c = *(undefined2 *)(local_38 + 2);
            local_60.sphere = (_Sphere *)&DAT_1f8001b8;
            local_60.oldPos = (SVECTOR *)&DAT_1f800168;
            local_60.collideFunc = local_34;
            local_60.segment = (uint)*pbVar5;
            local_60.id = (uint)*(byte *)((int)pvVar4 + 4);
            local_60.instance = instance;
            local_60.prim = pvVar4;
            COLLIDE_SphereAndTerrain(&local_60,level);
          }
          iVar7 = iVar7 + -1;
          pbVar5 = pbVar5 + 8;
          p_Var6 = p_Var6 + 1;
        } while (iVar7 != 0);
      }
    }
    gameTrackerX.monster_collide_override = '\0';
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ COLLIDE_LineWithSignals(struct _SVector *startPoint /*$a0*/, struct _SVector *endPoint /*$a1*/, struct _MultiSignal **signalList /*stack 8*/, long maxSignals /*stack 12*/, struct Level *level /*stack 16*/)
 // line 4331, offset 0x80023df0
	/* begin block 1 */
		// Start line: 4332
		// Start offset: 0x80023DF0
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
			// Start offset: 0x80023ED8
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
		// End offset: 0x80023ED8
		// End Line: 4377

		/* begin block 1.2 */
			// Start line: 4390
			// Start offset: 0x80023F70
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
		// End offset: 0x80023F70
		// End Line: 4390

		/* begin block 1.3 */
			// Start line: 4390
			// Start offset: 0x80023F70
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
		// End offset: 0x80023F70
		// End Line: 4390

		/* begin block 1.4 */
			// Start line: 4431
			// Start offset: 0x800241A4
			// Variables:
		// 		struct _SVector *vertex0; // $a0

			/* begin block 1.4.1 */
				// Start line: 4332
				// Start offset: 0x800241A4
				// Variables:
			// 		short *nrmlArray; // $a0
			// 		struct _SVector *nrml; // $a1

				/* begin block 1.4.1.1 */
					// Start line: 4332
					// Start offset: 0x800241A4
					// Variables:
				// 		short *sPtr; // $v1
				/* end block 1.4.1.1 */
				// End offset: 0x80024234
				// End Line: 4332
			/* end block 1.4.1 */
			// End offset: 0x80024234
			// End Line: 4332

			/* begin block 1.4.2 */
				// Start line: 4449
				// Start offset: 0x800242B4

				/* begin block 1.4.2.1 */
					// Start line: 4332
					// Start offset: 0x800242B4
					// Variables:
				// 		struct _SVector *point; // $t0
				// 		struct _SVector *start; // $a3
				// 		struct _SVector *line; // $a2

					/* begin block 1.4.2.1.1 */
						// Start line: 4332
						// Start offset: 0x800242B4
						// Variables:
					// 		long len; // $v1
					// 		long t; // $a1
					/* end block 1.4.2.1.1 */
					// End offset: 0x800242E4
					// End Line: 4332
				/* end block 1.4.2.1 */
				// End offset: 0x800242E4
				// End Line: 4332

				/* begin block 1.4.2.2 */
					// Start line: 4459
					// Start offset: 0x80024398
					// Variables:
				// 		struct _MultiSignal *msignal; // $v1
				/* end block 1.4.2.2 */
				// End offset: 0x800243C8
				// End Line: 4470
			/* end block 1.4.2 */
			// End offset: 0x800243C8
			// End Line: 4471
		/* end block 1.4 */
		// End offset: 0x800243C8
		// End Line: 4472

		/* begin block 1.5 */
			// Start line: 4479
			// Start offset: 0x800243E8
			// Variables:
		// 		int plane_front_error; // $v1
		// 		int plane_back_error; // $a0
		/* end block 1.5 */
		// End offset: 0x800244DC
		// End Line: 4524

		/* begin block 1.6 */
			// Start line: 4526
			// Start offset: 0x800244EC
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $a0
		// 		short _z0; // $a1
		// 		short _x1; // $v0
		// 		short _y1; // $a3
		// 		short _z1; // $a2
		// 		struct _Position *_v1; // $a2
		/* end block 1.6 */
		// End offset: 0x800244EC
		// End Line: 4526

		/* begin block 1.7 */
			// Start line: 4526
			// Start offset: 0x800244EC
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $a0
		// 		short _z0; // $a1
		// 		short _x1; // $v0
		// 		short _y1; // $a3
		// 		short _z1; // $a2
		// 		struct _Position *_v1; // $a2
		/* end block 1.7 */
		// End offset: 0x80024564
		// End Line: 4527
	/* end block 1 */
	// End offset: 0x80024580
	// End Line: 4531

	/* begin block 2 */
		// Start line: 10815
	/* end block 2 */
	// End Line: 10816

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

long COLLIDE_LineWithSignals
               (_SVector *startPoint,_SVector *endPoint,_MultiSignal **signalList,long maxSignals,
               Level *level)

{
  short sVar1;
  short sVar2;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar3;
  int iVar4;
  _Normal *p_Var5;
  _TVertex *v0;
  int *piVar6;
  ushort *puVar7;
  int **ppiVar8;
  int **ppiVar9;
  ushort *puVar10;
  _Terrain *p_Var11;
  int iVar12;
  int iVar13;
  int local_38;
  
  p_Var11 = level->terrain;
  DAT_1f80009c = p_Var11->normalList;
  ppiVar9 = (int **)&DAT_1f8000a4;
  DAT_1f8000a0 = p_Var11->vertexList;
  DAT_1f800084 = *(undefined4 *)startPoint;
  DAT_1f800088 = *(uint *)&startPoint->z;
  _DAT_1f80008c = *(undefined4 *)endPoint;
  DAT_1f800090 = *(uint *)&endPoint->z;
  if (gameTrackerX.gameData.asmData.MorphTime == 1000) {
    DAT_1f800098 = (int)gameTrackerX.gameData.asmData.MorphType;
    if (DAT_1f800098 != 1) {
      DAT_1f800098 = 0;
    }
  }
  else {
    DAT_1f800098 = 2;
  }
  DAT_1f800084._2_2_ = (short)((uint)DAT_1f800084 >> 0x10);
  DAT_1f80008e = (short)((uint)_DAT_1f80008c >> 0x10);
  DAT_1f800080._0_2_ = (short)DAT_1f800088 - (short)DAT_1f800090;
  DAT_1f80007c = CONCAT22(DAT_1f800084._2_2_ - DAT_1f80008e,(short)DAT_1f800084 - DAT_1f80008c);
  if (((DAT_1f80007c != 0) || (iVar3 = 0, (short)DAT_1f800080 != 0)) &&
     (local_38 = 0, iVar3 = 0, 0 < p_Var11->numBSPTrees)) {
    iVar12 = 0;
    do {
      if (*(short *)((int)&p_Var11->BSPTreeArray->ID + iVar12) == -1) {
        *(int ***)ppiVar9 = ppiVar9;
        iVar13 = (int)&p_Var11->BSPTreeArray->bspRoot + iVar12;
        DAT_1f80008c = DAT_1f80008c - *(short *)(iVar13 + 0xc);
        DAT_1f80008e = DAT_1f80008e - *(short *)(iVar13 + 0xe);
        DAT_1f800090 = DAT_1f800090 & 0xffff0000 |
                       (uint)(ushort)((short)DAT_1f800090 - *(short *)(iVar13 + 0x10));
        iVar13 = (int)&p_Var11->BSPTreeArray->bspRoot + iVar12;
        DAT_1f800084._0_2_ = (short)DAT_1f800084 - *(short *)(iVar13 + 0xc);
        DAT_1f800084._2_2_ = DAT_1f800084._2_2_ - *(short *)(iVar13 + 0xe);
        DAT_1f800088 = DAT_1f800088 & 0xffff0000 |
                       (uint)(ushort)((short)DAT_1f800088 - *(short *)(iVar13 + 0x10));
        ppiVar9 = ppiVar9 + 1;
        *ppiVar9 = *(int **)((int)&p_Var11->BSPTreeArray->bspRoot + iVar12);
        DAT_1f800040 = DAT_1f80008c;
        DAT_1f800042 = DAT_1f80008e;
        DAT_1f800044 = (short)DAT_1f800090;
        DAT_1f800046 = (short)DAT_1f800084;
        DAT_1f800048 = DAT_1f800084._2_2_;
        DAT_1f80004a = (short)DAT_1f800088;
        SetRotMatrix((undefined4 *)&DAT_1f800040);
        ppiVar8 = ppiVar9;
        if ((int **)*ppiVar9 != ppiVar9) {
          do {
            piVar6 = *ppiVar8;
            ppiVar9 = ppiVar8 + -1;
            if ((*(ushort *)((int)piVar6 + 0xe) & 2) == 0) {
              setCopReg(2,in_zero,piVar6[2]);
              setCopReg(2,in_at,piVar6[3]);
              copFunction(2,0x486012);
              _DAT_1f800068 = getCopReg(2,0x19);
              _DAT_1f80006c = getCopReg(2,0x1a);
              DAT_1f800070 = getCopReg(2,0x1b);
              _DAT_1f800068 = _DAT_1f800068 - piVar6[4];
              _DAT_1f80006c = _DAT_1f80006c - piVar6[4];
              if (DAT_1f800098 == 0) {
                sVar1 = *(short *)(piVar6 + 10);
                sVar2 = *(short *)((int)piVar6 + 0x2a);
              }
              else {
                sVar1 = *(short *)(piVar6 + 9);
                sVar2 = *(short *)((int)piVar6 + 0x26);
              }
              if ((_DAT_1f800068 < sVar1) || (_DAT_1f80006c < sVar1)) {
                if (((sVar2 < _DAT_1f800068) || (sVar2 < _DAT_1f80006c)) &&
                   ((int *)piVar6[5] != (int *)0x0)) {
                  *ppiVar8 = (int *)piVar6[5];
                  ppiVar9 = ppiVar8;
                }
                piVar6 = (int *)piVar6[6];
              }
              else {
                piVar6 = (int *)piVar6[5];
              }
              if (piVar6 != (int *)0x0) {
                ppiVar9 = ppiVar9 + 1;
                *ppiVar9 = piVar6;
              }
            }
            else {
              if ((((DAT_1f80008c <= *(short *)((int)piVar6 + 0x16)) ||
                   ((short)DAT_1f800084 <= *(short *)((int)piVar6 + 0x16))) &&
                  ((*(short *)(piVar6 + 4) <= DAT_1f80008c ||
                   (*(short *)(piVar6 + 4) <= (short)DAT_1f800084)))) &&
                 (((DAT_1f80008e <= *(short *)(piVar6 + 6) ||
                   (DAT_1f800084._2_2_ <= *(short *)(piVar6 + 6))) &&
                  ((*(short *)((int)piVar6 + 0x12) <= DAT_1f80008e ||
                   (*(short *)((int)piVar6 + 0x12) <= DAT_1f800084._2_2_)))))) {
                if ((((short)DAT_1f800090 <= *(short *)((int)piVar6 + 0x1a)) ||
                    ((short)DAT_1f800088 <= *(short *)((int)piVar6 + 0x1a))) &&
                   ((*(short *)(piVar6 + 5) <= (short)DAT_1f800090 ||
                    (*(short *)(piVar6 + 5) <= (short)DAT_1f800088)))) {
                  DAT_1f800094 = (int)*(short *)(piVar6 + 3);
                  puVar10 = (ushort *)piVar6[2];
                  puVar7 = puVar10 + 5;
                  while (DAT_1f800094 != 0) {
                    iVar13 = iVar3;
                    if (((puVar7[-2] & 0xc0) != 0) && (*puVar7 != 0xffff)) {
                      iVar4 = (int)(short)puVar7[-1];
                      if (iVar4 < 0) {
                        p_Var5 = (_Normal *)((int)DAT_1f80009c + iVar4 * -6);
                        _DAT_1f800060 = CONCAT22(-p_Var5->y,-(p_Var5->x & 0x1fffU));
                        _DAT_1f800064 = _DAT_1f800064 & 0xffff0000 | (uint)(ushort)-p_Var5->z;
                      }
                      else {
                        _DAT_1f800060 = *(uint *)(&DAT_1f80009c->x + iVar4 * 3) & 0xffff1fff;
                        _DAT_1f800064 =
                             _DAT_1f800064 & 0xffff0000 |
                             (uint)(ushort)(&DAT_1f80009c->x + iVar4 * 3)[1];
                      }
                      v0 = DAT_1f8000a0 + *puVar10;
                      setCopControlWord(2,0x1800,*(undefined4 *)&v0->vertex);
                      setCopControlWord(2,0x2000,*(undefined4 *)&(v0->vertex).z);
                      setCopReg(2,in_zero,_DAT_1f800060);
                      setCopReg(2,in_at,_DAT_1f800064);
                      copFunction(2,0x486012);
                      _DAT_1f800068 = getCopReg(2,0x19);
                      _DAT_1f80006c = getCopReg(2,0x1a);
                      DAT_1f800070 = getCopReg(2,0x1b);
                      _DAT_1f800068 = _DAT_1f800068 - DAT_1f800070;
                      _DAT_1f80006c = _DAT_1f80006c - DAT_1f800070;
                      if ((_DAT_1f800068 < 0) && (-1 < _DAT_1f80006c)) {
                        if (_DAT_1f800068 - _DAT_1f80006c == 0) {
                          iVar4 = 0;
                        }
                        else {
                          iVar4 = (_DAT_1f80006c * 0x1000) / (_DAT_1f800068 - _DAT_1f80006c);
                        }
                        DAT_1f800074._0_2_ =
                             (short)DAT_1f800084 + (short)((short)DAT_1f80007c * iVar4 >> 0xc);
                        DAT_1f80007c._2_2_ = (short)((uint)DAT_1f80007c >> 0x10);
                        DAT_1f800074._2_2_ =
                             DAT_1f800084._2_2_ + (short)(DAT_1f80007c._2_2_ * iVar4 >> 0xc);
                        DAT_1f800078._0_2_ =
                             (short)DAT_1f800088 + (short)((short)DAT_1f800080 * iVar4 >> 0xc);
                        iVar4 = COLLIDE_PointInTriangle
                                          ((_SVector *)v0,(_SVector *)(DAT_1f8000a0 + puVar7[-4]),
                                           (_SVector *)(DAT_1f8000a0 + puVar7[-3]),
                                           (_SVector *)&DAT_1f800074,(_SVector *)&DAT_1f800060);
                        if ((iVar4 != 0) && (iVar3 < maxSignals)) {
                          iVar13 = iVar3 + 1;
                          signalList[iVar3] =
                               (_MultiSignal *)((int)&p_Var11->signals->numSignals + (uint)*puVar7);
                        }
                      }
                    }
                    puVar7 = puVar7 + 6;
                    puVar10 = puVar10 + 6;
                    DAT_1f800094 = DAT_1f800094 + -1;
                    iVar3 = iVar13;
                  }
                }
              }
            }
            ppiVar8 = ppiVar9;
          } while ((int **)*ppiVar9 != ppiVar9);
        }
        iVar13 = (int)&p_Var11->BSPTreeArray->bspRoot + iVar12;
        _DAT_1f80008c =
             CONCAT22(DAT_1f80008e + *(short *)(iVar13 + 0xe),
                      DAT_1f80008c + *(short *)(iVar13 + 0xc));
        DAT_1f800090 = DAT_1f800090 & 0xffff0000 |
                       (uint)(ushort)((short)DAT_1f800090 + *(short *)(iVar13 + 0x10));
        iVar13 = (int)&p_Var11->BSPTreeArray->bspRoot + iVar12;
        DAT_1f800084 = CONCAT22(DAT_1f800084._2_2_ + *(short *)(iVar13 + 0xe),
                                (short)DAT_1f800084 + *(short *)(iVar13 + 0xc));
        DAT_1f800088 = DAT_1f800088 & 0xffff0000 |
                       (uint)(ushort)((short)DAT_1f800088 + *(short *)(iVar13 + 0x10));
      }
      iVar12 = iVar12 + 0x24;
      local_38 = local_38 + 1;
    } while (local_38 < p_Var11->numBSPTrees);
  }
  return iVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ COLLIDE_InstanceTerrainSignal(struct _Instance *instance /*$s3*/, struct Level *level /*$s1*/)
 // line 4548, offset 0x800245b4
	/* begin block 1 */
		// Start line: 4549
		// Start offset: 0x800245B4
		// Variables:
	// 		struct _SVector startPoint; // stack offset -72
	// 		struct _SVector endPoint; // stack offset -64
	// 		struct _Model *model; // $s0
	// 		long numSignals; // $s4
	// 		long d; // $s1
	// 		struct _MultiSignal (*signalListArray[8]); // stack offset -56

		/* begin block 1.1 */
			// Start line: 4616
			// Start offset: 0x80024794
			// Variables:
		// 		struct _MultiSignal *msignal; // $s0
		/* end block 1.1 */
		// End offset: 0x800247B4
		// End Line: 4625
	/* end block 1 */
	// End offset: 0x800247DC
	// End Line: 4630

	/* begin block 2 */
		// Start line: 11519
	/* end block 2 */
	// End Line: 11520

/* WARNING: Could not reconcile some variable overlaps */

void COLLIDE_InstanceTerrainSignal(_Instance *instance,Level *level)

{
  ulong uVar1;
  long lVar2;
  uint uVar3;
  _Model *p_Var4;
  _MultiSignal *mSignal;
  int iVar5;
  _MultiSignal **signalList;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  _MultiSignal *local_38 [8];
  
  p_Var4 = instance->object->modelList[instance->currentModel];
  if ((instance->matrix != (MATRIX *)0x0) && (instance->oldMatrix != (MATRIX *)0x0)) {
    if (((instance->object->oflags2 & 0x80000U) == 0) ||
       (uVar1 = INSTANCE_Query(instance,1), uVar1 == 0x82)) {
      if ((p_Var4 == (_Model *)0x0) || (p_Var4->numSegments < 2)) {
        local_48 = *(undefined4 *)&instance->oldPos;
        local_44 = *(uint *)&(instance->oldPos).z;
        local_40 = *(undefined4 *)&instance->position;
        local_3c = *(uint *)&(instance->position).z;
      }
      else {
        local_48 = CONCAT22(*(undefined2 *)(instance->oldMatrix[1].t + 1),
                            *(undefined2 *)instance->oldMatrix[1].t);
        local_44 = CONCAT22(local_44._2_2_,*(undefined2 *)(instance->oldMatrix[1].t + 2));
        local_40 = CONCAT22(*(undefined2 *)(instance->matrix[1].t + 1),
                            *(undefined2 *)instance->matrix[1].t);
        local_3c = CONCAT22(local_3c._2_2_,*(undefined2 *)(instance->matrix[1].t + 2));
      }
    }
    else {
      local_48 = *(undefined4 *)&instance->oldPos;
      uVar3 = *(uint *)&(instance->oldPos).z;
      local_44._0_2_ = (short)uVar3;
      local_44 = uVar3 & 0xffff0000 | (uint)(ushort)((short)local_44 + 100);
      local_40 = *(undefined4 *)&instance->position;
      uVar3 = *(uint *)&(instance->position).z;
      local_3c._0_2_ = (short)uVar3;
      local_3c = uVar3 & 0xffff0000 | (uint)(ushort)((short)local_3c + 100);
    }
    signalList = local_38;
    lVar2 = COLLIDE_LineWithSignals((_SVector *)&local_48,(_SVector *)&local_40,signalList,8,level);
    iVar5 = 0;
    if (0 < lVar2) {
      do {
        mSignal = *signalList;
        if (instance == gameTrackerX.playerInstance) {
          mSignal->flags = mSignal->flags | 1;
        }
        SIGNAL_HandleSignal(instance,mSignal->signalList,0);
        EVENT_AddSignalToReset(mSignal);
        iVar5 = iVar5 + 1;
        signalList = signalList + 1;
      } while (iVar5 < lVar2);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ COLLIDE_CameraWithStreamSignals(struct Camera *camera /*$s1*/)
 // line 4634, offset 0x800247fc
	/* begin block 1 */
		// Start line: 4635
		// Start offset: 0x800247FC
		// Variables:
	// 		struct _SVector startPoint; // stack offset -112
	// 		struct _SVector endPoint; // stack offset -104
	// 		struct _Model *model; // $v1
	// 		long numSignals; // $s3
	// 		long i; // $s1
	// 		long numStreamSignals; // $s2
	// 		struct _MultiSignal (*signalListArray[8]); // stack offset -96
	// 		struct _StreamUnit (*streamSignalUnits[8]); // stack offset -64
	// 		struct _StreamUnit *playerStreamUnit; // $a1
	// 		struct Level *level; // $v0
	// 		long playerStreamUnitID; // $s4
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 4737
			// Start offset: 0x80024940
			// Variables:
		// 		struct _MultiSignal *msignal; // $v0
		// 		long isWarpGateSignal; // stack offset -32

			/* begin block 1.1.1 */
				// Start line: 4745
				// Start offset: 0x80024964
				// Variables:
			// 		struct _StreamUnit *cameraStreamUnit; // $v1
			// 		long cameraStreamID; // $a0

				/* begin block 1.1.1.1 */
					// Start line: 4754
					// Start offset: 0x80024984
					// Variables:
				// 		int number; // $v1
				/* end block 1.1.1.1 */
				// End offset: 0x80024998
				// End Line: 4758
			/* end block 1.1.1 */
			// End offset: 0x800249FC
			// End Line: 4774
		/* end block 1.1 */
		// End offset: 0x800249FC
		// End Line: 4775
	/* end block 1 */
	// End offset: 0x80024A6C
	// End Line: 4806

	/* begin block 2 */
		// Start line: 11707
	/* end block 2 */
	// End Line: 11708

/* WARNING: Could not reconcile some variable overlaps */

_StreamUnit * COLLIDE_CameraWithStreamSignals(Camera *camera)

{
  _StreamUnit *p_Var1;
  long lVar2;
  int id;
  long lVar3;
  _Model *p_Var4;
  _StreamUnit **pp_Var5;
  _Instance *p_Var6;
  int iVar7;
  int iVar8;
  long id_00;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  _MultiSignal *local_60 [8];
  _StreamUnit *local_40 [8];
  long local_20 [2];
  
  p_Var6 = camera->focusInstance;
  id_00 = p_Var6->currentStreamUnitID;
  if ((p_Var6 == gameTrackerX.playerInstance) && (gameTrackerX.SwitchToNewStreamUnit != 0)) {
    id_00 = gameTrackerX.moveRazielToStreamID;
  }
  p_Var1 = STREAM_GetStreamUnitWithID(id_00);
  local_68 = *(undefined4 *)&(camera->core).position;
  local_64 = *(undefined4 *)&(camera->core).position.z;
  if (((p_Var6->matrix == (MATRIX *)0x0) ||
      (p_Var4 = p_Var6->object->modelList[p_Var6->currentModel], p_Var4 == (_Model *)0x0)) ||
     (p_Var4->numSegments < 2)) {
    local_70 = *(undefined4 *)&p_Var6->position;
    local_6c = *(undefined4 *)&(p_Var6->position).z;
  }
  else {
    local_70 = CONCAT22(*(undefined2 *)(p_Var6->matrix[1].t + 1),*(undefined2 *)p_Var6->matrix[1].t)
    ;
    local_6c = CONCAT22(local_6c._2_2_,*(undefined2 *)(p_Var6->matrix[1].t + 2));
  }
  iVar8 = 0;
  if (p_Var1->level != (Level *)0x0) {
    lVar2 = COLLIDE_LineWithSignals
                      ((_SVector *)&local_70,(_SVector *)&local_68,local_60,8,p_Var1->level);
    iVar7 = 0;
    if (0 < lVar2) {
      id = 0;
      do {
        id = *(int *)((int)local_60 + id);
        lVar3 = SIGNAL_IsStreamSignal((Signal *)(id + 8),local_20);
        if (lVar3 != 0) {
          if (local_20[0] == 0) {
            id = *(int *)(id + 0x10);
          }
          else {
            id = WARPGATE_IsWarpgateActive();
            if (id == 0) {
              id = 0;
            }
            else {
              id = (int)gameTrackerX.SwitchToNewWarpIndex;
              if ((int)gameTrackerX.SwitchToNewWarpIndex == -1) {
                id = CurrentWarpNumber;
              }
              id = ((&WarpRoomArray)[id].streamUnit)->StreamUnitID;
            }
          }
          p_Var1 = (_StreamUnit *)0x0;
          if (id != 0) {
            p_Var1 = STREAM_GetStreamUnitWithID(id);
          }
          if (p_Var1 != (_StreamUnit *)0x0) {
            local_40[iVar8] = p_Var1;
            iVar8 = iVar8 + 1;
          }
        }
        iVar7 = iVar7 + 1;
        id = iVar7 * 4;
      } while (iVar7 < lVar2);
    }
  }
  if (iVar8 != 0) {
    if (iVar8 == 1) {
      return local_40[0];
    }
    iVar7 = 0;
    if (0 < iVar8) {
      pp_Var5 = local_40;
      do {
        iVar7 = iVar7 + 1;
        if ((*pp_Var5)->StreamUnitID != id_00) {
          return *pp_Var5;
        }
        pp_Var5 = pp_Var5 + 1;
      } while (iVar7 < iVar8);
      return (_StreamUnit *)0x0;
    }
  }
  return (_StreamUnit *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ COLLIDE_InstanceListWithSignals(struct _InstanceList *instanceList /*$a0*/)
 // line 4809, offset 0x80024a8c
	/* begin block 1 */
		// Start line: 4810
		// Start offset: 0x80024A8C
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		struct Level *level; // $v0
	/* end block 1 */
	// End offset: 0x80024AEC
	// End Line: 4826

	/* begin block 2 */
		// Start line: 12135
	/* end block 2 */
	// End Line: 12136

void COLLIDE_InstanceListWithSignals(_InstanceList *instanceList)

{
  Level *level;
  _Instance *instance;
  
  instance = instanceList->first;
  while (instance != (_Instance *)0x0) {
    if (((instance->flags2 & 0x24000000U) == 0) &&
       (level = STREAM_GetLevelWithID(instance->currentStreamUnitID), level != (Level *)0x0)) {
      COLLIDE_InstanceTerrainSignal(instance,level);
    }
    instance = instance->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ COLLIDE_InstanceListTerrain(struct _InstanceList *instanceList /*$a0*/)
 // line 4828, offset 0x80024b00
	/* begin block 1 */
		// Start line: 4829
		// Start offset: 0x80024B00
		// Variables:
	// 		long i; // $s2
	// 		struct _Instance *instance; // $s0
	// 		struct Level *level; // $v0
	/* end block 1 */
	// End offset: 0x80024B94
	// End Line: 4868

	/* begin block 2 */
		// Start line: 12180
	/* end block 2 */
	// End Line: 12181

void COLLIDE_InstanceListTerrain(_InstanceList *instanceList)

{
  Level *level;
  _InstancePool *instance;
  _InstancePool **pp_Var1;
  int iVar2;
  
  iVar2 = 1;
  pp_Var1 = &instanceList->pool;
  do {
    instance = pp_Var1[4];
    while (instance != (_InstancePool *)0x0) {
      if (((*(int *)&instance->instance[0].extraLightDir != 0) &&
          ((instance->instance[0].instanceID & 0x24040000U) == 0)) &&
         (level = STREAM_GetLevelWithID(instance->instance[0].introNum), level != (Level *)0x0)) {
        COLLIDE_InstanceTerrain((_Instance *)instance,level);
      }
      instance = (_InstancePool *)instance->numFreeInstances;
    }
    iVar2 = iVar2 + 2;
    pp_Var1 = pp_Var1 + 4;
  } while (iVar2 < 0x20);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ COLLIDE_SegmentCollisionOn(struct _Instance *instance /*$a0*/, int segment /*$a1*/)
 // line 4959, offset 0x80024bb0
	/* begin block 1 */
		// Start line: 4961
		// Start offset: 0x80024BB0

		/* begin block 1.1 */
			// Start line: 4963
			// Start offset: 0x80024BC0
			// Variables:
		// 		int i; // $a2
		// 		struct _HModel *hmodel; // $v0
		// 		struct _HPrim *hprim; // $v1
		/* end block 1.1 */
		// End offset: 0x80024C20
		// End Line: 4974
	/* end block 1 */
	// End offset: 0x80024C20
	// End Line: 4975

	/* begin block 2 */
		// Start line: 9918
	/* end block 2 */
	// End Line: 9919

	/* begin block 3 */
		// Start line: 12411
	/* end block 3 */
	// End Line: 12412

void COLLIDE_SegmentCollisionOn(_Instance *instance,int segment)

{
  _HModel *p_Var1;
  _HPrim *p_Var2;
  int iVar3;
  
  if (instance->hModelList != (_HModel *)0x0) {
    p_Var1 = instance->hModelList + instance->currentModel;
    iVar3 = p_Var1->numHPrims;
    p_Var2 = p_Var1->hPrimList;
    while (iVar3 != 0) {
      if ((uint)p_Var2->segment == segment) {
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
 // line 4980, offset 0x80024c28
	/* begin block 1 */
		// Start line: 4982
		// Start offset: 0x80024C28

		/* begin block 1.1 */
			// Start line: 4984
			// Start offset: 0x80024C38
			// Variables:
		// 		int i; // $a2
		// 		int enabled; // $a3
		// 		struct _HModel *hmodel; // $v0
		// 		struct _HPrim *hprim; // $v1
		/* end block 1.1 */
		// End offset: 0x80024CBC
		// End Line: 4999
	/* end block 1 */
	// End offset: 0x80024CBC
	// End Line: 5000

	/* begin block 2 */
		// Start line: 12455
	/* end block 2 */
	// End Line: 12456

	/* begin block 3 */
		// Start line: 12456
	/* end block 3 */
	// End Line: 12457

void COLLIDE_SegmentCollisionOff(_Instance *instance,int segment)

{
  bool bVar1;
  _HModel *p_Var2;
  _HPrim *p_Var3;
  int iVar4;
  
  if (instance->hModelList != (_HModel *)0x0) {
    p_Var2 = instance->hModelList + instance->currentModel;
    iVar4 = p_Var2->numHPrims;
    p_Var3 = p_Var2->hPrimList;
    bVar1 = false;
    while (iVar4 != 0) {
      if ((uint)p_Var3->segment == segment) {
        p_Var3->hpFlags = p_Var3->hpFlags & 0xfe;
      }
      if ((!bVar1) && ((p_Var3->hpFlags & 1) != 0)) {
        bVar1 = true;
      }
      iVar4 = iVar4 + -1;
      p_Var3 = p_Var3 + 1;
    }
    if (!bVar1) {
      instance->flags2 = instance->flags2 | 0x40000;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ COLLIDE_FindCollisionFaceNormal(struct _CollideInfo *collideInfo /*$a0*/, struct _Normal *normal /*$s2*/)
 // line 5027, offset 0x80024cc4
	/* begin block 1 */
		// Start line: 5028
		// Start offset: 0x80024CC4
		// Variables:
	// 		long valid_normal; // $a2

		/* begin block 1.1 */
			// Start line: 5037
			// Start offset: 0x80024CF8
			// Variables:
		// 		struct _TFace *tface; // $a1
		/* end block 1.1 */
		// End offset: 0x80024D40
		// End Line: 5041

		/* begin block 1.2 */
			// Start line: 5048
			// Start offset: 0x80024D78

			/* begin block 1.2.1 */
				// Start line: 5052
				// Start offset: 0x80024D78
				// Variables:
			// 		struct SVECTOR *lNormal; // stack offset -24
			// 		struct _Instance *inst1; // $s1
			/* end block 1.2.1 */
			// End offset: 0x80024D78
			// End Line: 5053
		/* end block 1.2 */
		// End offset: 0x80024D78
		// End Line: 5053

		/* begin block 1.3 */
			// Start line: 5066
			// Start offset: 0x80024DCC
			// Variables:
		// 		struct _Instance *inst1; // $v0
		/* end block 1.3 */
		// End offset: 0x80024DE4
		// End Line: 5070
	/* end block 1 */
	// End offset: 0x80024DE4
	// End Line: 5072

	/* begin block 2 */
		// Start line: 10054
	/* end block 2 */
	// End Line: 10055

long COLLIDE_FindCollisionFaceNormal(_CollideInfo *collideInfo,_Normal *normal)

{
  char cVar1;
  ushort uVar2;
  undefined4 uVar3;
  SVECTOR *nrml;
  long lVar4;
  void *pvVar5;
  SVECTOR SStack24;
  
  cVar1 = collideInfo->type1;
  lVar4 = 0;
  if (cVar1 != '\x01') {
    if (cVar1 == '\x03') {
      uVar2 = *(ushort *)((int)collideInfo->prim1 + 10);
      if ((uVar2 == 0xffff) ||
         ((*(ushort *)(*(int *)(*(int *)collideInfo->level + 0x34) + (uint)uVar2 + 10) & 0x2000) ==
          0)) {
        COLLIDE_GetNormal(*(short *)((int)collideInfo->prim1 + 8),
                          *(short **)(*(int *)collideInfo->level + 0x24),(_SVector *)normal);
        lVar4 = 1;
      }
    }
    else {
      if (cVar1 == '\x02') {
        nrml = &SStack24;
        pvVar5 = collideInfo->inst1;
        COLLIDE_GetNormal(*(short *)((int)collideInfo->prim1 + 8),
                          *(short **)
                           (*(int *)((int)*(short *)((int)pvVar5 + 0x126) * 4 +
                                    *(int *)(*(int *)((int)pvVar5 + 0x1c) + 0xc)) + 0xc),
                          (_SVector *)nrml);
        uVar3 = *(undefined4 *)((int)pvVar5 + 0x40);
      }
      else {
        nrml = &collideInfo->point0;
        if ((*(uint *)&collideInfo->flags & 0xffff0000) != 0x5010000) {
          return 0;
        }
        uVar3 = *(undefined4 *)((int)collideInfo->inst1 + 0x40);
      }
      ApplyMatrixSV(uVar3,nrml,normal);
      lVar4 = 1;
    }
  }
  return lVar4;
}



// decompiled code
// original method signature: 
// short * /*$ra*/ COLLIDE_GetBSPTreeFlag(struct _CollideInfo *collideInfo /*$a0*/)
 // line 5077, offset 0x80024e00
	/* begin block 1 */
		// Start line: 5079
		// Start offset: 0x80024E00
		// Variables:
	// 		struct Level *level; // $v0
	// 		struct _Terrain *terrain; // $v0
	// 		struct BSPTree *bspTree; // $v0
	/* end block 1 */
	// End offset: 0x80024E00
	// End Line: 5091

	/* begin block 2 */
		// Start line: 12627
	/* end block 2 */
	// End Line: 12628

	/* begin block 3 */
		// Start line: 12628
	/* end block 3 */
	// End Line: 12629

	/* begin block 4 */
		// Start line: 12640
	/* end block 4 */
	// End Line: 12641

short * COLLIDE_GetBSPTreeFlag(_CollideInfo *collideInfo)

{
  return (short *)(*(int *)(*(int *)collideInfo->level + 0x48) + (int)collideInfo->bspID * 0x24 +
                  0x12);
}



// decompiled code
// original method signature: 
// void /*$ra*/ COLLIDE_SetBSPTreeFlag(struct _CollideInfo *collideInfo /*$a0*/, short flag /*$a1*/)
 // line 5101, offset 0x80024e28
	/* begin block 1 */
		// Start line: 5102
		// Start offset: 0x80024E28
		// Variables:
	// 		short *bspTreeFlags; // $v0
	/* end block 1 */
	// End offset: 0x80024E28
	// End Line: 5102

	/* begin block 2 */
		// Start line: 12684
	/* end block 2 */
	// End Line: 12685

void COLLIDE_SetBSPTreeFlag(_CollideInfo *collideInfo,short flag)

{
  ushort *puVar1;
  
  puVar1 = (ushort *)COLLIDE_GetBSPTreeFlag(collideInfo);
  *puVar1 = *puVar1 | flag;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ COLLIDE_PointAndTfaceFunc(struct _Terrain *terrain /*$fp*/, struct BSPTree *bsp /*$s6*/, struct _SVector *orgNewPos /*$s7*/, struct _SVector *orgOldPos /*$t4*/, struct _TFace *tface /*stack 16*/, long ignoreAttr /*stack 20*/, long flags /*stack 24*/)
 // line 5133, offset 0x80024e5c
	/* begin block 1 */
		// Start line: 5134
		// Start offset: 0x80024E5C
		// Variables:
	// 		struct PandTFScratch *CSpad; // $s0
	// 		int result; // stack offset -48

		/* begin block 1.1 */
			// Start line: 5153
			// Start offset: 0x80024EEC
			// Variables:
		// 		struct _SVector *vertex0; // $s3
		// 		struct _SVector *vertex1; // $s4

			/* begin block 1.1.1 */
				// Start line: 5156
				// Start offset: 0x80024EEC
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
			// End offset: 0x80024EEC
			// End Line: 5156

			/* begin block 1.1.2 */
				// Start line: 5156
				// Start offset: 0x80024EEC
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a1
			// 		short _x1; // $a2
			// 		short _y1; // $t0
			// 		short _z1; // $a3
			// 		struct _SVector *_v; // $t3
			/* end block 1.1.2 */
			// End offset: 0x80024EEC
			// End Line: 5156

			/* begin block 1.1.3 */
				// Start line: 5156
				// Start offset: 0x80024EEC
				// Variables:
			// 		short *nrmlArray; // $a1
			// 		struct _SVector *nrml; // $a0

				/* begin block 1.1.3.1 */
					// Start line: 5156
					// Start offset: 0x80024EEC
					// Variables:
				// 		short *sPtr; // $v1
				/* end block 1.1.3.1 */
				// End offset: 0x8002502C
				// End Line: 5166
			/* end block 1.1.3 */
			// End offset: 0x8002502C
			// End Line: 5166

			/* begin block 1.1.4 */
				// Start line: 5197
				// Start offset: 0x80025140
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a0
			// 		short _x1; // $a1
			// 		short _y1; // $a3
			// 		short _z1; // $a2
			// 		struct _Position *_v1; // $a2
			/* end block 1.1.4 */
			// End offset: 0x80025140
			// End Line: 5197
		/* end block 1.1 */
		// End offset: 0x80025178
		// End Line: 5201
	/* end block 1 */
	// End offset: 0x8002517C
	// End Line: 5204

	/* begin block 2 */
		// Start line: 10266
	/* end block 2 */
	// End Line: 10267

int COLLIDE_PointAndTfaceFunc
              (_Terrain *terrain,BSPTree *bsp,_SVector *orgNewPos,_SVector *orgOldPos,_TFace *tface,
              long ignoreAttr,long flags)

{
  ushort uVar1;
  undefined4 in_zero;
  undefined4 in_at;
  short sVar2;
  int iVar3;
  uint *puVar4;
  _Normal *p_Var5;
  short sVar6;
  _TVertex *p_Var7;
  _TVertex *v0;
  int local_30;
  
  local_30 = 0;
  if ((tface == (_TFace *)0x0) || ((bsp->flags & 2U) != 0)) {
    local_30 = 0;
  }
  else {
    if ((1 << (tface->attr & 0x1f) & ignoreAttr) == 0) {
      DAT_1f800040 = orgNewPos->x - (bsp->globalOffset).x;
      DAT_1f800042 = orgNewPos->y - (bsp->globalOffset).y;
      DAT_1f800044 = orgNewPos->z - (bsp->globalOffset).z;
      DAT_1f800046 = orgOldPos->x - (bsp->globalOffset).x;
      DAT_1f800048 = orgOldPos->y - (bsp->globalOffset).y;
      DAT_1f80004a = orgOldPos->z - (bsp->globalOffset).z;
      DAT_1f800068 = DAT_1f800040;
      DAT_1f80006a = DAT_1f800042;
      DAT_1f80006c = DAT_1f800044;
      DAT_1f800070._0_2_ = DAT_1f800046;
      DAT_1f800070._2_2_ = DAT_1f800048;
      DAT_1f800074._0_2_ = DAT_1f80004a;
      SetRotMatrix((undefined4 *)&DAT_1f800040);
      iVar3 = (int)(short)tface->normal;
      if (iVar3 < 0) {
        p_Var5 = (_Normal *)((int)terrain->normalList + iVar3 * -6);
        DAT_1f800078 = CONCAT22(-p_Var5->y,-(p_Var5->x & 0x1fffU));
        DAT_1f80007c = DAT_1f80007c & 0xffff0000 | (uint)(ushort)-p_Var5->z;
      }
      else {
        puVar4 = (uint *)(&terrain->normalList->x + iVar3 * 3);
        DAT_1f800078 = *puVar4 & 0xffff1fff;
        DAT_1f80007c = DAT_1f80007c & 0xffff0000 | (uint)*(ushort *)(puVar4 + 1);
      }
      p_Var7 = terrain->vertexList;
      uVar1 = (tface->face).v1;
      v0 = p_Var7 + (tface->face).v0;
      setCopControlWord(2,0x1800,*(undefined4 *)&v0->vertex);
      setCopControlWord(2,0x2000,*(undefined4 *)&(v0->vertex).z);
      setCopReg(2,in_zero,DAT_1f800078);
      setCopReg(2,in_at,DAT_1f80007c);
      copFunction(2,0x486012);
      DAT_1f800080 = getCopReg(2,0x19);
      DAT_1f800084 = getCopReg(2,0x1a);
      DAT_1f800088 = getCopReg(2,0x1b);
      DAT_1f800080 = DAT_1f800080 - DAT_1f800088;
      DAT_1f800084 = DAT_1f800084 - DAT_1f800088;
      if ((((DAT_1f800080 < 0) && (-1 < DAT_1f800084)) ||
          (((flags & 1U) != 0 && ((0 < DAT_1f800080 && (DAT_1f800084 < 1)))))) &&
         ((iVar3 = COLLIDE_IntersectLineAndPlane_S
                             (&DAT_1f800060,&DAT_1f800070,&DAT_1f800068,&DAT_1f800078,DAT_1f800088),
          iVar3 != 0 &&
          (iVar3 = COLLIDE_PointInTriangle
                             ((_SVector *)v0,(_SVector *)(p_Var7 + uVar1),
                              (_SVector *)(terrain->vertexList + (tface->face).v2),
                              (_SVector *)&DAT_1f800060,(_SVector *)&DAT_1f800078), iVar3 != 0)))) {
        local_30 = 1;
        sVar2 = DAT_1f800062 + (bsp->globalOffset).y;
        sVar6 = DAT_1f800064 + (bsp->globalOffset).z;
        orgNewPos->x = DAT_1f800060 + (bsp->globalOffset).x;
        orgNewPos->y = sVar2;
        orgNewPos->z = sVar6;
      }
    }
  }
  return local_30;
}





