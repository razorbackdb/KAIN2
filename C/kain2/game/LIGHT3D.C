#include "THISDUST.H"
#include "LIGHT3D.H"

// LightGroup @0x800CE460, len = 0x00000040
default_lightgroup =
    {
        // MATRIX @0x800CE460, len = 0x00000020
        .lightMatrix =
            {
                // short[3][3] @0x800CE460, len = 0x00000012
                .m =
                    {
                        // short[3] @0x800CE460, len = 0x00000006
                        {
                            -0x81b,
                            -0x528,
                            0xcca},
                        // short[3] @0x800CE466, len = 0x00000006
                        {
                            0xd23,
                            -0x5c7,
                            0x711},
                        // short[3] @0x800CE46C, len = 0x00000006
                        {
                            0xa13,
                            0xa7b,
                            0x6ad}},
                // long[3] @0x800CE474, len = 0x0000000C
                .t =
                    {
                        0x0,
                        0x0,
                        0x0}},
        // MATRIX @0x800CE480, len = 0x00000020
        .colorMatrix =
            {
                // short[3][3] @0x800CE480, len = 0x00000012
                .m =
                    {
                        // short[3] @0x800CE480, len = 0x00000006
                        {
                            0x808,
                            0x808,
                            0x808},
                        // short[3] @0x800CE486, len = 0x00000006
                        {
                            0x808,
                            0x808,
                            0x808},
                        // short[3] @0x800CE48C, len = 0x00000006
                        {
                            0x808,
                            0x808,
                            0x808}},
                // long[3] @0x800CE494, len = 0x0000000C
                .t =
                    {
                        0x0,
                        0x0,
                        0x0}}};
// LightInfo * @0x800D0D80, len = 0x00000004
light_lightInfo = null;
// _Terrain * @0x800D0D7C, len = 0x00000004
light_terrain = null;
// decompiled code
// original method signature:
// void /*$ra*/ LIGHT_GetLightMatrix(struct _Instance *instance /*$a0*/, struct Level *level /*$a1*/, struct MATRIX *lightM /*$a2*/, struct MATRIX *colorM /*$a3*/)
// line 70, offset 0x80035824
/* begin block 1 */
// Start line: 72
// Start offset: 0x80035824
// Variables:
// 		struct MATRIX *lightGroup; // $t0
// 		struct LightList *lightList; // $v1
// 		int lightGrp; // $t1

/* begin block 1.1 */
// Start line: 120
// Start offset: 0x800358F4
// Variables:
// 		struct MATRIX *tlightGroup; // $t2
// 		struct LightList *tlightList; // $t3
// 		int tlightGrp; // $t1
// 		struct MATRIX *start; // $t4
// 		struct MATRIX *end; // $t3
// 		int i; // $t1
// 		int j; // $a2
// 		long ratio; // $t2
/* end block 1.1 */
// End offset: 0x80035AB8
// End Line: 186
/* end block 1 */
// End offset: 0x80035B90
// End Line: 195

/* begin block 2 */
// Start line: 140
/* end block 2 */
// End Line: 141

/* begin block 3 */
// Start line: 141
/* end block 3 */
// End Line: 142

/* begin block 4 */
// Start line: 145
/* end block 4 */
// End Line: 146

void LIGHT_GetLightMatrix(_Instance *instance, Level *level, MATRIX *lightM, MATRIX *colorM)

{
  ushort uVar1;
  LightGroup *pLVar2;
  LightGroup *pLVar3;
  int iVar4;
  ushort *puVar5;
  LightList *in_v1;
  short *psVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  LightList *in_t3;

  uVar10 = (uint)instance->lightGroup;
  if (gameTrackerX.gameData.asmData.MorphType == 0)
  {
    if ((instance != gameTrackerX.playerInstance) ||
        (pLVar2 = level->razielLightGroup, pLVar2 == (LightGroup *)0x0))
    {
    LAB_800358a8:
      in_v1 = level->lightList;
      pLVar2 = (LightGroup *)0x0;
    }
  }
  else
  {
    if ((instance != gameTrackerX.playerInstance) ||
        (pLVar2 = level->razielSpectralLightGroup, pLVar2 == (LightGroup *)0x0))
    {
      in_v1 = level->spectrallightList;
      if ((in_v1 == (LightList *)0x0) || (in_v1->numLightGroups == 0))
        goto LAB_800358a8;
      uVar10 = (uint)instance->spectralLightGroup;
      pLVar2 = (LightGroup *)0x0;
    }
  }
  if (pLVar2 == (LightGroup *)0x0)
  {
    if ((in_v1->numLightGroups == 0) || (in_v1->numLightGroups <= (int)uVar10))
    {
      pLVar2 = &default_lightgroup;
    }
    else
    {
      pLVar2 = in_v1->lightGroupList + uVar10;
    }
  }
  if (gameTrackerX.gameData.asmData.MorphTime == 1000)
  {
    lightM->m[0] = (pLVar2->lightMatrix).m[0];
    lightM->m[1] = (pLVar2->lightMatrix).m[1];
    lightM->m[2] = (pLVar2->lightMatrix).m[2];
    lightM->m[3] = (pLVar2->lightMatrix).m[3];
    lightM->m[4] = (pLVar2->lightMatrix).m[4];
    lightM->m[5] = (pLVar2->lightMatrix).m[5];
    lightM->m[6] = (pLVar2->lightMatrix).m[6];
    lightM->m[7] = (pLVar2->lightMatrix).m[7];
    lightM->m[8] = (pLVar2->lightMatrix).m[8];
    colorM->m[0] = (pLVar2->colorMatrix).m[0];
    colorM->m[1] = (pLVar2->colorMatrix).m[1];
    colorM->m[2] = (pLVar2->colorMatrix).m[2];
    colorM->m[3] = (pLVar2->colorMatrix).m[3];
    colorM->m[4] = (pLVar2->colorMatrix).m[4];
    colorM->m[5] = (pLVar2->colorMatrix).m[5];
    colorM->m[6] = (pLVar2->colorMatrix).m[6];
    colorM->m[7] = (pLVar2->colorMatrix).m[7];
    colorM->m[8] = (pLVar2->colorMatrix).m[8];
    return;
  }
  uVar10 = (uint)instance->lightGroup;
  if (gameTrackerX.gameData.asmData.MorphType == 0)
  {
    if ((instance == gameTrackerX.playerInstance) &&
        (pLVar3 = level->razielSpectralLightGroup, pLVar3 != (LightGroup *)0x0))
      goto LAB_8003597c;
    in_t3 = level->spectrallightList;
    if ((in_t3 != (LightList *)0x0) && (in_t3->numLightGroups != 0))
    {
      uVar10 = (uint)instance->spectralLightGroup;
      pLVar3 = (LightGroup *)0x0;
      goto LAB_8003597c;
    }
  }
  else
  {
    if ((instance == gameTrackerX.playerInstance) &&
        (pLVar3 = level->razielLightGroup, pLVar3 != (LightGroup *)0x0))
      goto LAB_8003597c;
  }
  in_t3 = level->lightList;
  pLVar3 = (LightGroup *)0x0;
LAB_8003597c:
  if (pLVar3 == (LightGroup *)0x0)
  {
    if ((in_t3->numLightGroups == 0) || (in_t3->numLightGroups <= (int)uVar10))
    {
      pLVar3 = &default_lightgroup;
    }
    else
    {
      pLVar3 = in_t3->lightGroupList + uVar10;
    }
  }
  lightM->m[0] = (pLVar2->lightMatrix).m[0];
  lightM->m[1] = (pLVar2->lightMatrix).m[1];
  lightM->m[2] = (pLVar2->lightMatrix).m[2];
  lightM->m[3] = (pLVar2->lightMatrix).m[3];
  lightM->m[4] = (pLVar2->lightMatrix).m[4];
  lightM->m[5] = (pLVar2->lightMatrix).m[5];
  lightM->m[6] = (pLVar2->lightMatrix).m[6];
  lightM->m[7] = (pLVar2->lightMatrix).m[7];
  lightM->m[8] = (pLVar2->lightMatrix).m[8];
  iVar4 = (int)gameTrackerX.gameData.asmData.MorphTime;
  iVar11 = 0;
  iVar9 = 0;
  do
  {
    iVar8 = 0;
    iVar7 = iVar9;
    do
    {
      puVar5 = (ushort *)((int)(pLVar2->colorMatrix).m + iVar7);
      uVar1 = *(ushort *)((int)(pLVar3->colorMatrix).m + iVar7);
      psVar6 = (short *)((int)colorM->m + iVar7);
      iVar7 = iVar7 + 2;
      iVar8 = iVar8 + 1;
      *psVar6 = uVar1 + (short)(((int)(((uint)*puVar5 - (uint)uVar1) * 0x10000) >> 0x10) *
                                    (0x1000 - (iVar4 << 0xc) / 1000) >>
                                0xc);
    } while (iVar8 < 3);
    iVar11 = iVar11 + 1;
    iVar9 = iVar9 + 6;
  } while (iVar11 < 3);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LIGHT_PresetInstanceLight(struct _Instance *instance /*$s0*/, short attenuate /*$a1*/, struct MATRIX *lm /*$s1*/)
// line 200, offset 0x80035b98
/* begin block 1 */
// Start line: 201
// Start offset: 0x80035B98
// Variables:
// 		struct MATRIX cm; // stack offset -80
// 		long scale; // $a0
// 		long scaleRGB[3]; // stack offset -48
// 		int i; // $t3
// 		int j; // $a3
// 		struct Level *level; // $s2
// 		short tempRGB[3]; // stack offset -32

/* begin block 1.1 */
// Start line: 254
// Start offset: 0x80035C34
// Variables:
// 		short *todRGB; // $v0

/* begin block 1.1.1 */
// Start line: 271
// Start offset: 0x80035C68
/* end block 1.1.1 */
// End offset: 0x80035CD8
// End Line: 277
/* end block 1.1 */
// End offset: 0x80035CF0
// End Line: 278
/* end block 1 */
// End offset: 0x80035CF0
// End Line: 281

/* begin block 2 */
// Start line: 428
/* end block 2 */
// End Line: 429

void LIGHT_PresetInstanceLight(_Instance *instance, short attenuate, MATRIX *lm)

{
  short sVar1;
  Level *level;
  undefined4 *puVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  MATRIX local_50;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_20;
  undefined2 local_1c;

  local_20 = DAT_800ce4a0;
  local_1c = PTR_DAT_800ce4a4._0_2_;
  level = STREAM_GetLevelWithID(instance->currentStreamUnitID);
  LIGHT_GetLightMatrix(instance, level, lm, &local_50);
  local_30 = 0x1000;
  puVar2 = &local_20;
  if ((instance->flags & 0x200000U) != 0)
  {
    local_30 = 0x800;
  }
  if ((int)attenuate != 0x1000)
  {
    local_30 = local_30 * (int)attenuate >> 0xc;
  }
  if (level != (Level *)0x0)
  {
    puVar2 = (undefined4 *)&level->TODRedScale;
  }
  iVar11 = 0;
  iVar10 = 0;
  piVar9 = &local_30;
  do
  {
    sVar1 = *(short *)puVar2;
    iVar3 = *piVar9;
    iVar8 = 0;
    iVar7 = iVar10;
    do
    {
      psVar6 = (short *)((int)local_50.m + iVar7);
      iVar5 = (int)*psVar6 * (iVar3 * (int)sVar1 * 0x10 >> 0x10) >> 0xc;
      sVar4 = (short)iVar5;
      if (iVar5 < -0x8000)
      {
        sVar4 = -0x8000;
      }
      if (0x7fff < iVar5)
      {
        sVar4 = 0x7fff;
      }
      *psVar6 = sVar4;
      iVar8 = iVar8 + 1;
      iVar7 = iVar7 + 2;
    } while (iVar8 < 3);
    iVar10 = iVar10 + 6;
    piVar9 = piVar9 + 1;
    iVar11 = iVar11 + 1;
    puVar2 = (undefined4 *)((int)puVar2 + 2);
  } while (iVar11 < 3);
  local_2c = local_30;
  local_28 = local_30;
  SetColorMatrix((undefined4 *)&local_50);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LIGHT_GetAmbient(struct _ColorType *color /*$a0*/, struct _Instance *instance /*$a1*/)
// line 290, offset 0x80035d14
/* begin block 1 */
// Start line: 292
// Start offset: 0x80035D14
// Variables:
// 		int lightval; // $v1
/* end block 1 */
// End offset: 0x80035D34
// End Line: 333

/* begin block 2 */
// Start line: 648
/* end block 2 */
// End Line: 649

/* begin block 3 */
// Start line: 649
/* end block 3 */
// End Line: 650

/* begin block 4 */
// Start line: 688
/* end block 4 */
// End Line: 689

void LIGHT_GetAmbient(_ColorType *color, _Instance *instance)

{
  uchar uVar1;

  uVar1 = '0';
  if ((instance->object->oflags2 & 0x800U) != 0)
  {
    uVar1 = '\0';
  }
  color->b = uVar1;
  color->g = uVar1;
  color->r = uVar1;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LIGHT_CalcLightValue(struct _TFace *tface /*$t2*/, struct _Instance *instance /*$fp*/, struct _Terrain *terrain /*$t3*/)
// line 336, offset 0x80035d44
/* begin block 1 */
// Start line: 337
// Start offset: 0x80035D44
// Variables:
// 		struct _ColorType color; // stack offset -88
// 		short fadespeed; // $a2

/* begin block 1.1 */
// Start line: 348
// Start offset: 0x80035DA4
// Variables:
// 		struct _ColorType color1; // stack offset -80
// 		struct _ColorType color2; // stack offset -72
// 		long n; // $v1
// 		long count; // $a0
// 		long edge; // $a2
// 		int x1; // $v1
// 		int x2; // $a0
// 		int interp1; // $s3
// 		int interp2; // $s2
// 		int interp; // $a3
// 		short *temp; // $v0
// 		short *vertex0; // $s6
// 		short *vertex1; // $s5
// 		short *vertex2; // $s4
// 		short position[3]; // stack offset -64
// 		struct _SVector normal; // stack offset -56
// 		struct BSPTree *bsp; // $a1
// 		int major; // $a3
// 		int minor; // $s7

/* begin block 1.1.1 */
// Start line: 457
// Start offset: 0x80036194
// Variables:
// 		long r; // $v0
// 		long g; // $a1
// 		long b; // $v1
// 		int lum; // $a0
/* end block 1.1.1 */
// End offset: 0x80036244
// End Line: 478
/* end block 1.1 */
// End offset: 0x80036244
// End Line: 478

/* begin block 1.2 */
// Start line: 493
// Start offset: 0x80036264
// Variables:
// 		int i; // $t0
// 		struct LightInstance *li; // $t4
// 		long dist; // $t3
// 		struct LightInstance *tli; // $t2

/* begin block 1.2.1 */
// Start line: 500
// Start offset: 0x80036274
// Variables:
// 		struct _Instance *inst; // $a1

/* begin block 1.2.1.1 */
// Start line: 503
// Start offset: 0x8003629C
// Variables:
// 		short tdist; // $a3
// 		struct _Position pos; // stack offset -64
// 		struct MATRIX *mat; // $a1
/* end block 1.2.1.1 */
// End offset: 0x80036384
// End Line: 520
/* end block 1.2.1 */
// End offset: 0x80036384
// End Line: 521
/* end block 1.2 */
// End offset: 0x80036450
// End Line: 545
/* end block 1 */
// End offset: 0x80036468
// End Line: 553

/* begin block 2 */
// Start line: 740
/* end block 2 */
// End Line: 741

/* WARNING: Removing unreachable block (ram,0x8003621c) */

void LIGHT_CalcLightValue(_TFace *tface, _Instance *instance, _Terrain *terrain)

{
  short sVar1;
  short sVar2;
  _TVertex *p_Var3;
  long lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  BSPTree *pBVar8;
  _Instance *p_Var9;
  MATRIX *pMVar10;
  uint uVar11;
  _TVertex *p_Var12;
  int iVar13;
  LightInstance *pLVar14;
  LightInstance *pLVar15;
  int iVar16;
  _TVertex *p_Var17;
  _TVertex *p_Var18;
  int iVar19;
  _ColorType local_58[2];
  byte abStack80[8];
  byte abStack72[8];
  short local_40[4];
  _SVector _Stack56;
  short *local_30;

  if ((((instance->flags & 0x400000U) != 0) || (tface == (_TFace *)0x0)) ||
      (instance->lightMatrix != 0))
  {
    LIGHT_GetAmbient(local_58, instance);
    iVar13 = 0x100;
    goto LAB_80036264;
  }
  p_Var12 = terrain->vertexList;
  pBVar8 = terrain->BSPTreeArray + instance->bspTree;
  local_40[0] = (instance->position).x - (pBVar8->globalOffset).x;
  p_Var18 = p_Var12 + (uint)(tface->face).v0;
  p_Var17 = p_Var12 + (uint)(tface->face).v1;
  local_40[1] = (instance->position).y - (pBVar8->globalOffset).y;
  local_40[2] = (instance->shadowPosition).z - (pBVar8->globalOffset).z;
  p_Var12 = p_Var12 + (uint)(tface->face).v2;
  lVar4 = COLLIDE_GetNormal(tface->normal, (short *)terrain->normalList, &_Stack56);
  iVar19 = lVar4 + 1;
  iVar13 = lVar4 + 2;
  if (2 < iVar13)
  {
    iVar13 = lVar4 + -1;
  }
  if (2 < iVar19)
  {
    iVar19 = lVar4 + -2;
  }
  sVar1 = local_40[iVar13];
  sVar2 = (&(p_Var18->vertex).x)[iVar13];
  uVar11 = 0;
  if ((sVar2 < sVar1) && (sVar1 < (&(p_Var17->vertex).x)[iVar13]))
  {
  LAB_80035eb4:
    uVar11 = 1;
  LAB_80035eb8:
    iVar5 = iVar13 * 2;
    if ((local_40[iVar13] <= (&(p_Var17->vertex).x)[iVar13]) ||
        ((&(p_Var12->vertex).x)[iVar13] <= local_40[iVar13]))
      goto LAB_80035ef0;
  LAB_80035f24:
    uVar11 = uVar11 | 2;
  LAB_80035f28:
    iVar6 = iVar13 * 2;
    if ((local_40[iVar13] <= (&(p_Var12->vertex).x)[iVar13]) ||
        ((&(p_Var18->vertex).x)[iVar13] <= local_40[iVar13]))
      goto LAB_80035f60;
  LAB_80035f94:
    uVar11 = uVar11 | 4;
  }
  else
  {
    if (sVar2 <= sVar1)
      goto LAB_80035eb8;
    iVar5 = iVar13 << 1;
    if ((&(p_Var17->vertex).x)[iVar13] < sVar1)
      goto LAB_80035eb4;
  LAB_80035ef0:
    if (*(short *)((int)&(p_Var17->vertex).x + iVar5) <= *(short *)((int)local_40 + iVar5))
      goto LAB_80035f28;
    iVar6 = iVar13 << 1;
    if (*(short *)((int)&(p_Var12->vertex).x + iVar5) < *(short *)((int)local_40 + iVar5))
      goto LAB_80035f24;
  LAB_80035f60:
    if ((*(short *)((int)local_40 + iVar6) < *(short *)((int)&(p_Var12->vertex).x + iVar6)) &&
        (*(short *)((int)&(p_Var18->vertex).x + iVar6) < *(short *)((int)local_40 + iVar6)))
      goto LAB_80035f94;
  }
  if (uVar11 == 3)
  {
    iVar5 = 1;
  }
  else
  {
    if (uVar11 == 6)
    {
      iVar5 = 2;
    }
    else
    {
      iVar5 = 0;
      if (uVar11 != 5)
      {
        return;
      }
    }
  }
  iVar6 = 0;
  p_Var3 = p_Var18;
  if (iVar5 != 0)
  {
    do
    {
      p_Var18 = p_Var17;
      p_Var17 = p_Var12;
      p_Var12 = p_Var3;
      iVar6 = iVar6 + 1;
      p_Var3 = p_Var18;
    } while (iVar6 < iVar5);
  }
  iVar6 = (int)(&(p_Var17->vertex).x)[iVar13];
  iVar5 = (int)(&(p_Var18->vertex).x)[iVar13];
  local_30 = local_40;
  if (iVar6 == iVar5)
  {
    return;
  }
  iVar7 = (iVar5 - (int)local_30[iVar13]) * 0x1000;
  iVar6 = iVar7 / (iVar6 - iVar5);
  if (iVar6 < 0)
  {
    iVar6 = -iVar6;
  }
  iVar16 = iVar6;
  if (iVar6 < 0)
  {
    iVar16 = 0;
  }
  if (0x1000 < iVar6)
  {
    iVar16 = 0x1000;
  }
  iVar13 = (int)(&(p_Var12->vertex).x)[iVar13];
  if (iVar13 == iVar5)
  {
    return;
  }
  iVar7 = iVar7 / (iVar13 - iVar5);
  if (iVar7 < 0)
  {
    iVar7 = -iVar7;
  }
  iVar13 = iVar7;
  if (iVar7 < 0)
  {
    iVar13 = 0;
  }
  if (0x1000 < iVar7)
  {
    iVar13 = 0x1000;
  }
  LoadAverageCol(&p_Var18->r0, &p_Var17->r0, 0x1000 - iVar16, iVar16, abStack80);
  LoadAverageCol(&p_Var18->r0, &p_Var12->r0, 0x1000 - iVar13, iVar13, abStack72);
  iVar5 = (int)(&(p_Var18->vertex).x)[iVar19];
  iVar16 = ((int)(&(p_Var17->vertex).x)[iVar19] - iVar5) * iVar16;
  if (iVar16 < 0)
  {
    iVar16 = iVar16 + 0xfff;
  }
  iVar13 = ((int)(&(p_Var12->vertex).x)[iVar19] - iVar5) * iVar13;
  iVar6 = iVar5 + (iVar16 >> 0xc);
  if (iVar13 < 0)
  {
    iVar13 = iVar13 + 0xfff;
  }
  iVar5 = iVar5 + (iVar13 >> 0xc);
  iVar13 = 0;
  if (iVar6 != iVar5)
  {
    iVar19 = ((iVar6 - (int)local_30[iVar19]) * 0x1000) / (iVar6 - iVar5);
    if (iVar19 < 0)
    {
      iVar19 = -iVar19;
    }
    iVar13 = iVar19;
    if (iVar19 < 0)
    {
      iVar13 = 0;
    }
    if (0x1000 < iVar19)
    {
      iVar13 = 0x1000;
    }
  }
  LoadAverageCol(abStack80, abStack72, 0x1000 - iVar13, iVar13, (undefined *)local_58);
  uVar11 = (int)((uint)local_58[0].r * 0x4c8 + (uint)local_58[0].g * 0x964 +
                 (uint)local_58[0].b * 0x1d3) >>
           0xc;
  local_58[0].r = (byte)uVar11;
  iVar13 = 0x400;
  local_58[0].g = local_58[0].r;
  local_58[0].b = local_58[0].r;
  if (0x44 < uVar11)
  {
    local_58[0].r = (char)((int)((uVar11 - 0x44) + (uVar11 - 0x44 >> 0x1f)) >> 1) + 0x44;
    local_58[0].g = local_58[0].r;
    local_58[0].b = local_58[0].r;
  }
LAB_80036264:
  pLVar15 = (LightInstance *)0x0;
  iVar19 = 0x7fff;
  pLVar14 = gameTrackerX.gameData.asmData.lightInstances;
  iVar5 = 0;
  do
  {
    p_Var9 = pLVar14->lightInstance;
    if (((p_Var9 != (_Instance *)0x0) && (p_Var9 != instance)) && (p_Var9->matrix != (MATRIX *)0x0))
    {
      pMVar10 = p_Var9->matrix + (uint)pLVar14->segment;
      iVar6 = (int)(((uint) * (ushort *)pMVar10->t - (uint)(ushort)(instance->position).x) * 0x10000) >> 0x10;
      if (iVar6 < 0)
      {
        iVar6 = -iVar6;
      }
      local_40[0] = (short)iVar6;
      iVar7 = (int)(((uint) * (ushort *)(pMVar10->t + 1) - (uint)(ushort)(instance->position).y) *
                    0x10000) >>
              0x10;
      if (iVar7 < 0)
      {
        iVar7 = -iVar7;
      }
      local_40[1] = (short)iVar7;
      iVar16 = (int)(((uint) * (ushort *)(pMVar10->t + 2) - (uint)(ushort)(instance->position).z) *
                     0x10000) >>
               0x10;
      if (iVar16 < 0)
      {
        iVar16 = -iVar16;
      }
      local_40[2] = (short)iVar16;
      if (iVar16 << 0x10 < iVar7 << 0x10)
      {
        iVar16 = iVar7;
      }
      sVar1 = (short)iVar16;
      if (iVar16 << 0x10 < iVar6 << 0x10)
      {
        sVar1 = local_40[0];
      }
      iVar6 = (int)sVar1;
      if ((iVar6 < (int)pLVar14->radius) && (iVar6 < iVar19))
      {
        iVar19 = iVar6;
        pLVar15 = pLVar14;
      }
    }
    iVar5 = iVar5 + 1;
    pLVar14 = pLVar14 + 1;
  } while (iVar5 < 1);
  if (pLVar15 != (LightInstance *)0x0)
  {
    iVar19 = (int)pLVar15->radius - iVar19;
    iVar5 = (uint)local_58[0].r + (iVar19 * pLVar15->r >> 0xc);
    local_58[0].r = (byte)iVar5;
    if (iVar5 < 0)
    {
      local_58[0].r = 0;
    }
    if (0xff < iVar5)
    {
      local_58[0].r = 0xff;
    }
    iVar5 = (uint)local_58[0].g + (iVar19 * pLVar15->g >> 0xc);
    local_58[0].g = (byte)iVar5;
    if (iVar5 < 0)
    {
      local_58[0].g = 0;
    }
    if (0xff < iVar5)
    {
      local_58[0].g = 0xff;
    }
    iVar19 = (uint)local_58[0].b + (iVar19 * pLVar15->b >> 0xc);
    local_58[0].b = (byte)iVar19;
    if (iVar19 < 0)
    {
      local_58[0].b = 0;
    }
    if (0xff < iVar19)
    {
      local_58[0].b = 0xff;
    }
  }
  LoadAverageCol((byte *)local_58, (byte *)&instance->light_color, iVar13, 0x1000 - iVar13,
                 (undefined *)&instance->light_color);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LIGHT_SetAmbientInstance(struct _Instance *instance /*$v0*/, struct Level *level /*$a1*/)
// line 555, offset 0x80036498
/* begin block 1 */
// Start line: 556
// Start offset: 0x80036498
/* end block 1 */
// End offset: 0x80036498
// End Line: 556

/* begin block 2 */
// Start line: 1247
/* end block 2 */
// End Line: 1248

void LIGHT_SetAmbientInstance(_Instance *instance, Level *level)

{
  SetBackColor((uint) * (byte *)&instance->light_color,
               (uint) * (byte *)((int)&instance->light_color + 1),
               (uint) * (byte *)((int)&instance->light_color + 2));
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LIGHT_SetMatrixForLightGroupInstance(struct _Instance *instance /*$s0*/, struct Level *level /*$a1*/)
// line 569, offset 0x800364c8
/* begin block 1 */
// Start line: 570
// Start offset: 0x800364C8
// Variables:
// 		struct MATRIX lgt_cat; // stack offset -40
// 		struct LightList *lightList; // $v0
// 		int lightGrp; // $v1
/* end block 1 */
// End offset: 0x80036634
// End Line: 682

/* begin block 2 */
// Start line: 1275
/* end block 2 */
// End Line: 1276

void LIGHT_SetMatrixForLightGroupInstance(_Instance *instance, Level *level)

{
  int iVar1;
  uint local_28[8];

  if (instance->matrix != (MATRIX *)0x0)
  {
    if (((gameTrackerX.gameData.asmData.MorphType == 0) ||
         (level->spectrallightList == (LightList *)0x0)) ||
        (iVar1 = level->spectrallightList->numLightGroups, iVar1 == 0))
    {
      if ((level->lightList != (LightList *)0x0) &&
          (level->lightList->numLightGroups < (int)(uint)instance->lightGroup))
      {
        instance->lightGroup = '\0';
      }
    }
    else
    {
      if (iVar1 < (int)(uint)instance->spectralLightGroup)
      {
        instance->spectralLightGroup = '\0';
      }
    }
    LIGHT_SetAmbientInstance(instance, level);
    if ((instance->lightMatrix == 0) && ((instance->flags & 1U) == 0))
    {
      RotMatrix((ushort *)&instance->rotation, local_28);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LIGHT_DrawShadow(struct MATRIX *wcTransform /*$s2*/, struct _Instance *instance /*$s1*/, struct _PrimPool *primPool /*$s3*/, unsigned long **ot /*$s4*/)
// line 730, offset 0x80036644
/* begin block 1 */
// Start line: 731
// Start offset: 0x80036644
// Variables:
// 		struct SVECTOR face_orient; // stack offset -112
// 		struct MATRIX rot; // stack offset -104
// 		struct MATRIX scTransform; // stack offset -72
// 		struct _Vector scale; // stack offset -40
// 		struct _Instance *playerInstance; // $s0
/* end block 1 */
// End offset: 0x80036908
// End Line: 804

/* begin block 2 */
// Start line: 1460
/* end block 2 */
// End Line: 1461

void LIGHT_DrawShadow(MATRIX *wcTransform, _Instance *instance, _PrimPool *primPool, ulong **ot)

{
  undefined4 in_at;
  short sVar1;
  int iVar2;
  long x;
  ulong *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ushort local_70;
  short local_6e;
  short local_6c;
  ushort local_68;
  ushort local_66;
  ushort local_64;
  ushort local_62;
  ushort local_60;
  ushort local_5e;
  ushort local_5c;
  ushort local_5a;
  ushort local_58;
  int local_54;
  int local_50;
  int local_4c;
  undefined2 local_48;
  undefined2 local_46;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined2 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;

  if ((int)(instance->position).z + -0x500 < (int)(instance->shadowPosition).z)
  {
    sVar1 = MATH3D_FastAtan2((int)(instance->wNormal).y, (int)(instance->wNormal).z);
    local_70 = -sVar1;
    iVar2 = (int)(instance->wNormal).x;
    x = MATH3D_FastSqrt0(0x1000000 - iVar2 * iVar2);
    local_6e = MATH3D_FastAtan2((int)(instance->wNormal).x, x);
    local_6c = (instance->rotation).z;
    RotMatrix(&local_70, (uint *)&local_68);
    local_54 = (int)(instance->shadowPosition).x;
    local_50 = (int)(instance->shadowPosition).y;
    local_4c = (int)(instance->shadowPosition).z;
    setCopControlWord(2, 0, *(undefined4 *)wcTransform->m);
    setCopControlWord(2, 0x800, *(undefined4 *)(wcTransform->m + 2));
    setCopControlWord(2, 0x1000, *(undefined4 *)(wcTransform->m + 4));
    setCopControlWord(2, 0x1800, *(undefined4 *)(wcTransform->m + 6));
    setCopControlWord(2, 0x2000, *(undefined4 *)(wcTransform->m + 8));
    setCopReg(2, 0x4800, (uint)local_68);
    setCopReg(2, 0x5000, (uint)local_62);
    setCopReg(2, 0x5800, (uint)local_5c);
    copFunction(2, 0x49e012);
    uVar4 = getCopReg(2, 0x4800);
    uVar5 = getCopReg(2, 0x5000);
    uVar6 = getCopReg(2, 0x5800);
    local_48 = (undefined2)uVar4;
    local_42 = (undefined2)uVar5;
    local_3c = (undefined2)uVar6;
    setCopReg(2, 0x4800, (uint)local_66);
    setCopReg(2, 0x5000, (uint)local_60);
    setCopReg(2, 0x5800, (uint)local_5a);
    copFunction(2, 0x49e012);
    uVar4 = getCopReg(2, 0x4800);
    uVar5 = getCopReg(2, 0x5000);
    uVar6 = getCopReg(2, 0x5800);
    local_46 = (undefined2)uVar4;
    local_40 = (undefined2)uVar5;
    local_3a = (undefined2)uVar6;
    setCopReg(2, 0x4800, (uint)local_64);
    setCopReg(2, 0x5000, (uint)local_5e);
    setCopReg(2, 0x5800, (uint)local_58);
    copFunction(2, 0x49e012);
    uVar4 = getCopReg(2, 0x4800);
    uVar5 = getCopReg(2, 0x5000);
    uVar6 = getCopReg(2, 0x5800);
    local_44 = (undefined2)uVar4;
    local_3e = (undefined2)uVar5;
    local_38 = (undefined2)uVar6;
    setCopControlWord(2, 0x2800, wcTransform->t[0]);
    setCopControlWord(2, 0x3000, wcTransform->t[1]);
    setCopControlWord(2, 0x3800, wcTransform->t[2]);
    setCopReg(2, 0, *(undefined4 *)&instance->shadowPosition);
    setCopReg(2, in_at, local_4c);
    copFunction(2, 0x480012);
    local_34 = getCopReg(2, 0x19);
    local_30 = getCopReg(2, 0x1a);
    local_2c = getCopReg(2, 0x1b);
    local_28 = (((int)instance->object->modelList[(int)instance->currentModel]->maxRad * 0x1000) /
                0x1e0) *
                   (0x1000 - (((int)(instance->position).z - (int)(instance->shadowPosition).z) * 0x1000) / 0x500) >>
               0xc;
    local_24 = local_28;
    local_20 = local_28;
    ScaleMatrix((int *)&local_48, &local_28);
    SetRotMatrix((undefined4 *)&local_48);
    SetTransMatrix((int)&local_48);
    puVar3 = DRAW_DrawShadow(primPool, (_Model *)0x0, ot, (int)instance->fadeValue);
    primPool->nextPrim = puVar3;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LIGHT_CalcShadowPositions(struct GameTracker *gameTracker /*$a0*/)
// line 806, offset 0x80036928
/* begin block 1 */
// Start line: 807
// Start offset: 0x80036928
// Variables:
// 		struct _InstanceList *instanceList; // $v0
// 		struct _Instance *instance; // $s0
// 		struct _PCollideInfo pcollideInfo; // stack offset -72
// 		struct _Position newPos; // stack offset -24
// 		struct _Position oldPos; // stack offset -16
// 		struct Level *level; // $v0
/* end block 1 */
// End offset: 0x80036C18
// End Line: 910

/* begin block 2 */
// Start line: 1734
/* end block 2 */
// End Line: 1735

void LIGHT_CalcShadowPositions(GameTracker *gameTracker)

{
  undefined2 uVar1;
  undefined2 uVar2;
  Level *level;
  uint uVar3;
  _TFace *tface;
  _Terrain *terrain;
  _Instance *instance;
  _PCollideInfo local_48;
  undefined4 local_18;
  short local_14;
  undefined4 local_10;
  short local_c;

  instance = gameTracker->instanceList->first;
  do
  {
    if (instance == (_Instance *)0x0)
    {
      return;
    }
    if ((instance->flags2 & 0x40U) == 0)
    {
    LAB_80036bd4:
      if ((_Terrain *)instance->tfaceLevel != (_Terrain *)0x0)
      {
        tface = instance->tface;
        terrain = *(_Terrain **)(_Terrain *)instance->tfaceLevel;
      LAB_80036bec:
        LIGHT_CalcLightValue(tface, instance, terrain);
      }
    }
    else
    {
      uVar3 = instance->flags;
      if (((uVar3 & 0xa00) == 0x200) && ((instance->flags2 & 0x4000000U) == 0))
      {
        if ((uVar3 & 0x18000000) == 0x8000000)
        {
          tface = instance->waterFace;
          if (tface == (_TFace *)0x0)
            goto LAB_80036bd4;
          terrain = instance->waterFaceTerrain;
          goto LAB_80036bec;
        }
        if ((uVar3 & 0x10000000) == 0)
        {
          local_18 = *(undefined4 *)&instance->position;
          local_14 = (instance->position).z;
          local_10 = *(undefined4 *)&instance->position;
          local_c = (instance->position).z;
        }
        else
        {
          uVar1 = *(undefined2 *)instance->matrix[1].t;
          uVar2 = *(undefined2 *)(instance->matrix[1].t + 1);
          local_18 = CONCAT22(uVar2, uVar1);
          local_10 = CONCAT22(uVar2, uVar1);
          local_14 = *(short *)(instance->matrix[1].t + 2);
          local_c = local_14;
        }
        local_48.collideType = 0x37;
        local_48.newPoint = (SVECTOR *)&local_18;
        local_48.oldPoint = (SVECTOR *)&local_10;
        local_14 = local_14 + -0x500;
        local_c = local_c + 0x100;
        instance->flags = instance->flags | 0x40;
        local_48.instance = instance;
        level = STREAM_GetLevelWithID(instance->currentStreamUnitID);
        if (level == (Level *)0x0)
        {
          local_48.type = 0;
        }
        else
        {
          COLLIDE_PointAndWorld(&local_48, level);
        }
        instance->flags = instance->flags & 0xffffffbf;
        if (local_48.type == 3)
        {
          terrain = (_Terrain *)((local_48.inst)->node).prev;
          tface = local_48.prim;
        LAB_80036ac0:
          LIGHT_CalcLightValue(tface, instance, terrain);
        }
        else
        {
          tface = (_TFace *)0x0;
          if (local_48.type != 5)
          {
            terrain = (_Terrain *)0x0;
            goto LAB_80036ac0;
          }
        }
        if (local_48.type != 0)
        {
          if (local_48.type == 1)
          {
            (instance->wNormal).x = 0;
            (instance->wNormal).y = 0;
            (instance->wNormal).z = 0x1000;
          }
          else
          {
            if (((local_48.type == 3) && ((local_48.prim)->textoff != 0xffff)) &&
                ((*(ushort *)((int)&((local_48.inst)->node).prev[6].next[1].prev +
                              (uint)(local_48.prim)->textoff + 2) &
                  0x4000) != 0))
            {
              uVar3 = instance->flags | 0x200000;
            }
            else
            {
              uVar3 = instance->flags & 0xffdfffff;
            }
            instance->flags = uVar3;
            (instance->wNormal).x = local_48.wNormal.vx;
            (instance->wNormal).y = local_48.wNormal.vy;
            (instance->wNormal).z = local_48.wNormal.vz;
          }
        }
        *(undefined4 *)&instance->shadowPosition = local_18;
        (instance->shadowPosition).z = local_14;
      }
      else
      {
        if ((instance->flags2 & 0x40U) == 0)
          goto LAB_80036bd4;
      }
    }
    instance->flags = instance->flags & 0xf7ffffff;
    instance = instance->next;
  } while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ LIGHT_Restore(struct LightInfo *lightInfo /*$a0*/)
// line 1361, offset 0x80036c28
/* begin block 1 */
// Start line: 2722
/* end block 1 */
// End Line: 2723

/* begin block 2 */
// Start line: 2405
/* end block 2 */
// End Line: 2406

void LIGHT_Restore(LightInfo *lightInfo)

{
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LIGHT_CalcDQPTable(struct Level *level /*$a3*/)
// line 1600, offset 0x80036c30
/* begin block 1 */
// Start line: 1601
// Start offset: 0x80036C30
// Variables:
// 		long dqa; // $a1
// 		long limit; // $t0

/* begin block 1.1 */
// Start line: 1614
// Start offset: 0x80036C78
/* end block 1.1 */
// End offset: 0x80036CA0
// End Line: 1621

/* begin block 1.2 */
// Start line: 1624
// Start offset: 0x80036CB0
/* end block 1.2 */
// End offset: 0x80036CE4
// End Line: 1631
/* end block 1 */
// End offset: 0x80036D3C
// End Line: 1661

/* begin block 2 */
// Start line: 3200
/* end block 2 */
// End Line: 3201

void LIGHT_CalcDQPTable(Level *level)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  undefined *puVar5;

  uVar3 = (uint)level->fogFar;
  uVar2 = (uint)level->fogNear;
  if (uVar3 != uVar2)
  {
    puVar5 = (undefined *)-((int)(uVar3 * uVar2) / (int)(uVar3 - uVar2));
    if (0x9ffe < (int)puVar5)
    {
      puVar5 = &DAT_00009ffe;
      uVar4 = (ushort)((int)(uVar3 * 0x9ffe) / (int)(&DAT_00009ffe + -uVar3));
      if ((uint)level->holdFogNear == uVar2)
      {
        level->holdFogNear = uVar4;
      }
      level->fogNear = uVar4;
    }
    if ((int)puVar5 < -0x9ffe)
    {
      uVar4 = (ushort)((int)((uint)level->fogFar * -0x9ffe) / (int)(-0x9ffe - (uint)level->fogFar));
      if (level->holdFogNear == level->fogNear)
      {
        level->holdFogNear = uVar4;
      }
      level->fogNear = uVar4;
      puVar5 = (undefined *)0xffff6002;
    }
    depthQFogStart =
        ((int)puVar5 * -0x1000) /
        ((int)((uint)level->fogFar << 0xc) / (int)((uint)level->fogFar - (uint)level->fogNear));
    depthQBlendStart = depthQFogStart;
    if (*(short *)&level->backColorR == 0)
    {
      depthQBlendStart = 0xffff;
    }
    lVar1 = depthQBlendStart;
    level->depthQFogStart = depthQFogStart;
    level->depthQBlendStart = lVar1;
  }
  return;
}
