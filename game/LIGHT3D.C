#include "THISDUST.H"
#include "LIGHT3D.H"


// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_GetLightMatrix(struct _Instance *instance /*$a0*/, struct Level *level /*$a1*/, struct MATRIX *lightM /*$a2*/, struct MATRIX *colorM /*$a3*/)
 // line 70, offset 0x80035d80
	/* begin block 1 */
		// Start line: 72
		// Start offset: 0x80035D80
		// Variables:
	// 		struct MATRIX *lightGroup; // $t0
	// 		struct LightList *lightList; // $v1
	// 		int lightGrp; // $t1

		/* begin block 1.1 */
			// Start line: 120
			// Start offset: 0x80035E54
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
		// End offset: 0x8003601C
		// End Line: 186
	/* end block 1 */
	// End offset: 0x800360F4
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

void LIGHT_GetLightMatrix(_Instance *instance,Level *level,MATRIX *lightM,MATRIX *colorM)

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
  if (gameTrackerX.gameData.asmData.MorphType == 0) {
    if ((instance != gameTrackerX.playerInstance) ||
       (pLVar2 = level->razielLightGroup, pLVar2 == (LightGroup *)0x0)) {
LAB_80035e04:
      in_v1 = level->lightList;
      pLVar2 = (LightGroup *)0x0;
    }
  }
  else {
    if ((instance != gameTrackerX.playerInstance) ||
       (pLVar2 = level->razielSpectralLightGroup, pLVar2 == (LightGroup *)0x0)) {
      in_v1 = level->spectrallightList;
      if ((in_v1 == (LightList *)0x0) || (in_v1->numLightGroups == 0)) goto LAB_80035e04;
      uVar10 = (uint)instance->spectralLightGroup;
      pLVar2 = (LightGroup *)0x0;
    }
  }
  if (pLVar2 == (LightGroup *)0x0) {
    if ((in_v1->numLightGroups == 0) || (in_v1->numLightGroups <= (int)uVar10)) {
      pLVar2 = &default_lightgroup;
    }
    else {
      pLVar2 = in_v1->lightGroupList + uVar10;
    }
  }
  if (gameTrackerX.gameData.asmData.MorphTime == 1000) {
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
  if (gameTrackerX.gameData.asmData.MorphType == 0) {
    if ((instance == gameTrackerX.playerInstance) &&
       (pLVar3 = level->razielSpectralLightGroup, pLVar3 != (LightGroup *)0x0)) goto LAB_80035edc;
    in_t3 = level->spectrallightList;
    if ((in_t3 != (LightList *)0x0) && (in_t3->numLightGroups != 0)) {
      uVar10 = (uint)instance->spectralLightGroup;
      pLVar3 = (LightGroup *)0x0;
      goto LAB_80035edc;
    }
  }
  else {
    if ((instance == gameTrackerX.playerInstance) &&
       (pLVar3 = level->razielLightGroup, pLVar3 != (LightGroup *)0x0)) goto LAB_80035edc;
  }
  in_t3 = level->lightList;
  pLVar3 = (LightGroup *)0x0;
LAB_80035edc:
  if (pLVar3 == (LightGroup *)0x0) {
    if ((in_t3->numLightGroups == 0) || (in_t3->numLightGroups <= (int)uVar10)) {
      pLVar3 = &default_lightgroup;
    }
    else {
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
  do {
    iVar8 = 0;
    iVar7 = iVar9;
    do {
      puVar5 = (ushort *)((int)(pLVar2->colorMatrix).m + iVar7);
      uVar1 = *(ushort *)((int)(pLVar3->colorMatrix).m + iVar7);
      psVar6 = (short *)((int)colorM->m + iVar7);
      iVar7 = iVar7 + 2;
      iVar8 = iVar8 + 1;
      *psVar6 = uVar1 + (short)(((int)(((uint)*puVar5 - (uint)uVar1) * 0x10000) >> 0x10) *
                                (0x1000 - (iVar4 << 0xc) / 1000) >> 0xc);
    } while (iVar8 < 3);
    iVar11 = iVar11 + 1;
    iVar9 = iVar9 + 6;
  } while (iVar11 < 3);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_PresetInstanceLight(struct _Instance *instance /*$s1*/, short attenuate /*$a1*/, struct MATRIX *lm /*$s0*/)
 // line 200, offset 0x800360fc
	/* begin block 1 */
		// Start line: 201
		// Start offset: 0x800360FC
		// Variables:
	// 		struct MATRIX cm; // stack offset -80
	// 		long scale; // $a0
	// 		long scaleRGB[3]; // stack offset -48
	// 		int i; // $t3
	// 		int j; // $a3
	// 		struct CDLight *extraLight; // $s2
	// 		struct Level *level; // $s3
	// 		short tempRGB[3]; // stack offset -32

		/* begin block 1.1 */
			// Start line: 254
			// Start offset: 0x80036238
			// Variables:
		// 		short *todRGB; // $v0

			/* begin block 1.1.1 */
				// Start line: 265
				// Start offset: 0x8003625C
			/* end block 1.1.1 */
			// End offset: 0x800362CC
			// End Line: 271
		/* end block 1.1 */
		// End offset: 0x800362E4
		// End Line: 272
	/* end block 1 */
	// End offset: 0x800362E4
	// End Line: 275

	/* begin block 2 */
		// Start line: 428
	/* end block 2 */
	// End Line: 429

void LIGHT_PresetInstanceLight(_Instance *instance,short attenuate,MATRIX *lm)

{
  short sVar1;
  Level *level;
  undefined4 *puVar2;
  int iVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  void *pvVar13;
  MATRIX local_50;
  int local_30 [4];
  undefined4 local_20;
  undefined2 local_1c;
  
  pvVar13 = instance->extraLight;
  local_20 = 0x10001000;
  local_1c = 0x1000;
  level = STREAM_GetLevelWithID(instance->currentStreamUnitID);
  LIGHT_GetLightMatrix(instance,level,lm,&local_50);
  uVar5 = instance->flags & 0x200000;
  local_30[0] = 0x1000;
  if (uVar5 != 0) {
    local_30[0] = 0x800;
  }
  if ((int)attenuate != 0x1000) {
    local_30[0] = local_30[0] * (int)attenuate >> 0xc;
  }
  if ((instance->extraLight == (void *)0x0) || (uVar5 != 0)) {
    local_30[1] = local_30[0];
    local_30[2] = local_30[0];
  }
  else {
    iVar7 = (0x1000 - (int)instance->extraLightScale) * local_30[0] >> 0xc;
    local_30[0] = iVar7 + ((int)((int)instance->extraLightScale * (uint)*(byte *)((int)pvVar13 + 8))
                          >> 6);
    local_30[1] = iVar7 + ((int)((int)instance->extraLightScale * (uint)*(byte *)((int)pvVar13 + 9))
                          >> 6);
    local_30[2] = iVar7 + ((int)((int)instance->extraLightScale * (uint)*(byte *)((int)pvVar13 + 10)
                                ) >> 6);
  }
  puVar2 = (undefined4 *)&level->TODRedScale;
  if (level == (Level *)0x0) {
    puVar2 = &local_20;
  }
  iVar12 = 0;
  iVar7 = 0;
  piVar11 = local_30;
  do {
    sVar1 = *(short *)puVar2;
    iVar3 = *piVar11;
    iVar10 = 0;
    iVar9 = iVar7;
    do {
      psVar8 = (short *)((int)local_50.m + iVar9);
      iVar6 = (int)*psVar8 * (iVar3 * sVar1 * 0x10 >> 0x10) >> 0xc;
      sVar4 = (short)iVar6;
      if (iVar6 < -0x8000) {
        sVar4 = -0x8000;
      }
      if (0x7fff < iVar6) {
        sVar4 = 0x7fff;
      }
      *psVar8 = sVar4;
      iVar10 = iVar10 + 1;
      iVar9 = iVar9 + 2;
    } while (iVar10 < 3);
    iVar7 = iVar7 + 6;
    piVar11 = piVar11 + 1;
    iVar12 = iVar12 + 1;
    puVar2 = (undefined4 *)((int)puVar2 + 2);
  } while (iVar12 < 3);
  SetColorMatrix((undefined4 *)&local_50);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_GetAmbient(struct _ColorType *color /*$s0*/, struct _Instance *instance /*$a1*/)
 // line 284, offset 0x8003630c
	/* begin block 1 */
		// Start line: 285
		// Start offset: 0x8003630C
		// Variables:
	// 		struct Level *level; // $a0
	// 		struct LightList *lightList; // $v1
	/* end block 1 */
	// End offset: 0x800363DC
	// End Line: 320

	/* begin block 2 */
		// Start line: 622
	/* end block 2 */
	// End Line: 623

void LIGHT_GetAmbient(_ColorType *color,_Instance *instance)

{
  byte bVar1;
  Level *pLVar2;
  LightList *pLVar3;
  
  pLVar2 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
  if (((gameTrackerX.gameData.asmData.MorphType == 0) ||
      (pLVar3 = pLVar2->spectrallightList, pLVar3 == (LightList *)0x0)) ||
     (pLVar3->numLightGroups == 0)) {
    pLVar3 = pLVar2->lightList;
  }
  color->r = (pLVar3->ambient).r >> 1;
  color->g = (pLVar3->ambient).g >> 1;
  bVar1 = (pLVar3->ambient).b >> 1;
  color->b = bVar1;
  if (((pLVar3->numLightGroups == 0) && (color->r < 0x40)) && ((color->g < 0x40 && (bVar1 < 0x40))))
  {
    color->r = -0x80;
    color->g = -0x80;
    color->b = -0x80;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_CalcLightValue(struct _TFace *tface /*$t2*/, struct _Instance *instance /*$s7*/, struct _Terrain *terrain /*$t3*/)
 // line 322, offset 0x800363ec
	/* begin block 1 */
		// Start line: 323
		// Start offset: 0x800363EC
		// Variables:
	// 		struct _ColorType color; // stack offset -96
	// 		short fadespeed; // $a2

		/* begin block 1.1 */
			// Start line: 334
			// Start offset: 0x8003644C
			// Variables:
		// 		struct _ColorType color1; // stack offset -88
		// 		struct _ColorType color2; // stack offset -80
		// 		long n; // $v1
		// 		long count; // $a0
		// 		long edge; // $a2
		// 		int x1; // $v1
		// 		int x2; // $a0
		// 		int interp1; // $s2
		// 		int interp2; // $s1
		// 		int interp; // $a3
		// 		short *temp; // $v0
		// 		short *vertex0; // $s5
		// 		short *vertex1; // $s4
		// 		short *vertex2; // $s3
		// 		short position[3]; // stack offset -72
		// 		struct _SVector normal; // stack offset -64
		// 		struct BSPTree *bsp; // $a1
		// 		int major; // $a3
		// 		int minor; // $s6

			/* begin block 1.1.1 */
				// Start line: 437
				// Start offset: 0x80036840
				// Variables:
			// 		long r; // $s0
			// 		long g; // $s1
			// 		long b; // $s2
			// 		struct CVECTOR colorA; // stack offset -56
			/* end block 1.1.1 */
			// End offset: 0x800368B0
			// End Line: 468
		/* end block 1.1 */
		// End offset: 0x800368B0
		// End Line: 468

		/* begin block 1.2 */
			// Start line: 484
			// Start offset: 0x800368D0
			// Variables:
		// 		int i; // $t0
		// 		struct LightInstance *li; // $t4
		// 		long dist; // $t3
		// 		struct LightInstance *tli; // $t2

			/* begin block 1.2.1 */
				// Start line: 491
				// Start offset: 0x800368E4
				// Variables:
			// 		struct _Instance *inst; // $a1

				/* begin block 1.2.1.1 */
					// Start line: 494
					// Start offset: 0x8003690C
					// Variables:
				// 		short tdist; // $a3
				// 		struct _Position pos; // stack offset -72
				// 		struct MATRIX *mat; // $a1
				/* end block 1.2.1.1 */
				// End offset: 0x800369F4
				// End Line: 511
			/* end block 1.2.1 */
			// End offset: 0x800369F4
			// End Line: 512
		/* end block 1.2 */
		// End offset: 0x80036AC0
		// End Line: 536
	/* end block 1 */
	// End offset: 0x80036AD8
	// End Line: 544

	/* begin block 2 */
		// Start line: 698
	/* end block 2 */
	// End Line: 699

void LIGHT_CalcLightValue(_TFace *tface,_Instance *instance,_Terrain *terrain)

{
  short sVar1;
  short sVar2;
  _TVertex *p_Var3;
  long lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long *plVar8;
  _Instance *p_Var9;
  MATRIX *pMVar10;
  NodeType **ppNVar11;
  uint uVar12;
  _TVertex *p_Var13;
  int iVar14;
  LightInstance *pLVar15;
  LightInstance *pLVar16;
  int iVar17;
  _TVertex *p_Var18;
  _TVertex *p_Var19;
  int iVar20;
  _ColorType local_60 [2];
  byte abStack88 [8];
  byte abStack80 [8];
  short local_48 [4];
  _SVector _Stack64;
  _ColorType local_38 [2];
  short *local_30;
  byte *local_2c;
  
  if ((((instance->flags & 0x400000U) != 0) || (tface == (_TFace *)0x0)) ||
     (instance->lightMatrix != 0)) {
    LIGHT_GetAmbient(local_60,instance);
    iVar14 = 0x100;
    goto LAB_800368d0;
  }
  p_Var13 = terrain->vertexList;
  plVar8 = &terrain->signals->numSignals + instance->bspTree * 9;
  local_48[0] = (instance->position).x - *(short *)(plVar8 + 3);
  p_Var19 = p_Var13 + (tface->face)._2;
  p_Var18 = p_Var13 + (tface->face)._3;
  local_48[1] = (instance->position).y - *(short *)((int)plVar8 + 0xe);
  local_48[2] = (instance->shadowPosition).z - *(short *)(plVar8 + 4);
  p_Var13 = p_Var13 + (tface->face).v2;
  lVar4 = COLLIDE_GetNormal(tface->normal,(short *)terrain->normalList,&_Stack64);
  iVar20 = lVar4 + 1;
  iVar14 = lVar4 + 2;
  if (2 < iVar14) {
    iVar14 = lVar4 + -1;
  }
  if (2 < iVar20) {
    iVar20 = lVar4 + -2;
  }
  sVar1 = local_48[iVar14];
  sVar2 = (&(p_Var19->vertex).x)[iVar14];
  uVar12 = 0;
  if ((sVar2 < sVar1) && (sVar1 < (&(p_Var18->vertex).x)[iVar14])) {
LAB_8003655c:
    uVar12 = 1;
LAB_80036560:
    iVar5 = iVar14 * 2;
    if ((local_48[iVar14] <= (&(p_Var18->vertex).x)[iVar14]) ||
       ((&(p_Var13->vertex).x)[iVar14] <= local_48[iVar14])) goto LAB_80036598;
LAB_800365cc:
    uVar12 = uVar12 | 2;
LAB_800365d0:
    iVar6 = iVar14 * 2;
    if ((local_48[iVar14] <= (&(p_Var13->vertex).x)[iVar14]) ||
       ((&(p_Var19->vertex).x)[iVar14] <= local_48[iVar14])) goto LAB_80036608;
LAB_8003663c:
    uVar12 = uVar12 | 4;
  }
  else {
    if (sVar2 <= sVar1) goto LAB_80036560;
    iVar5 = iVar14 << 1;
    if ((&(p_Var18->vertex).x)[iVar14] < sVar1) goto LAB_8003655c;
LAB_80036598:
    if (*(short *)((int)&(p_Var18->vertex).x + iVar5) <= *(short *)((int)local_48 + iVar5))
    goto LAB_800365d0;
    iVar6 = iVar14 << 1;
    if (*(short *)((int)&(p_Var13->vertex).x + iVar5) < *(short *)((int)local_48 + iVar5))
    goto LAB_800365cc;
LAB_80036608:
    if ((*(short *)((int)local_48 + iVar6) < *(short *)((int)&(p_Var13->vertex).x + iVar6)) &&
       (*(short *)((int)&(p_Var19->vertex).x + iVar6) < *(short *)((int)local_48 + iVar6)))
    goto LAB_8003663c;
  }
  if (uVar12 == 3) {
    iVar5 = 1;
  }
  else {
    if (uVar12 == 6) {
      iVar5 = 2;
    }
    else {
      iVar5 = 0;
      if (uVar12 != 5) {
        return;
      }
    }
  }
  iVar6 = 0;
  p_Var3 = p_Var19;
  if (iVar5 != 0) {
    do {
      p_Var19 = p_Var18;
      p_Var18 = p_Var13;
      p_Var13 = p_Var3;
      iVar6 = iVar6 + 1;
      p_Var3 = p_Var19;
    } while (iVar6 < iVar5);
  }
  iVar6 = (int)(&(p_Var18->vertex).x)[iVar14];
  iVar5 = (int)(&(p_Var19->vertex).x)[iVar14];
  if (iVar6 == iVar5) {
    return;
  }
  local_30 = local_48;
  iVar7 = (iVar5 - local_48[iVar14]) * 0x1000;
  iVar6 = iVar7 / (iVar6 - iVar5);
  if (iVar6 < 0) {
    iVar6 = -iVar6;
  }
  iVar17 = iVar6;
  if (iVar6 < 0) {
    iVar17 = 0;
  }
  if (0x1000 < iVar6) {
    iVar17 = 0x1000;
  }
  iVar14 = (int)(&(p_Var13->vertex).x)[iVar14];
  if (iVar14 == iVar5) {
    return;
  }
  iVar7 = iVar7 / (iVar14 - iVar5);
  if (iVar7 < 0) {
    iVar7 = -iVar7;
  }
  iVar14 = iVar7;
  if (iVar7 < 0) {
    iVar14 = 0;
  }
  if (0x1000 < iVar7) {
    iVar14 = 0x1000;
  }
  local_2c = abStack88;
  LoadAverageCol(&p_Var19->r0,&p_Var18->r0,0x1000 - iVar17,iVar17,local_2c);
  LoadAverageCol(&p_Var19->r0,&p_Var13->r0,0x1000 - iVar14,iVar14,abStack80);
  iVar5 = (int)(&(p_Var19->vertex).x)[iVar20];
  iVar17 = ((&(p_Var18->vertex).x)[iVar20] - iVar5) * iVar17;
  if (iVar17 < 0) {
    iVar17 = iVar17 + 0xfff;
  }
  iVar14 = ((&(p_Var13->vertex).x)[iVar20] - iVar5) * iVar14;
  iVar6 = iVar5 + (iVar17 >> 0xc);
  if (iVar14 < 0) {
    iVar14 = iVar14 + 0xfff;
  }
  iVar5 = iVar5 + (iVar14 >> 0xc);
  if (iVar6 == iVar5) {
    return;
  }
  iVar14 = ((iVar6 - local_30[iVar20]) * 0x1000) / (iVar6 - iVar5);
  if (iVar14 < 0) {
    iVar14 = -iVar14;
  }
  iVar20 = iVar14;
  if (iVar14 < 0) {
    iVar20 = 0;
  }
  if (0x1000 < iVar14) {
    iVar20 = 0x1000;
  }
  LoadAverageCol(local_2c,abStack80,0x1000 - iVar20,iVar20,(undefined *)local_60);
  LIGHT_GetAmbient(local_38,instance);
  local_60[0].r = local_38[0].r;
  local_60[0].g = local_38[0].g;
  iVar14 = 0x400;
  local_60[0].b = local_38[0].b;
LAB_800368d0:
  pLVar16 = (LightInstance *)0x0;
  iVar20 = 0x7fff;
  pLVar15 = gameTrackerX.gameData.asmData.lightInstances;
  iVar5 = 0;
  do {
    p_Var9 = pLVar15->lightInstance;
    if (((p_Var9 != (_Instance *)0x0) && (p_Var9 != instance)) && (p_Var9->matrix != (MATRIX *)0x0))
    {
      pMVar10 = p_Var9->matrix + pLVar15->segment;
      iVar6 = (int)(((uint)*(ushort *)pMVar10->t - (uint)(ushort)(instance->position).x) * 0x10000)
              >> 0x10;
      if (iVar6 < 0) {
        iVar6 = -iVar6;
      }
      local_48[0] = (short)iVar6;
      iVar7 = (int)(((uint)*(ushort *)(pMVar10->t + 1) - (uint)(ushort)(instance->position).y) *
                   0x10000) >> 0x10;
      if (iVar7 < 0) {
        iVar7 = -iVar7;
      }
      local_48[1] = (short)iVar7;
      iVar17 = (int)(((uint)*(ushort *)(pMVar10->t + 2) - (uint)(ushort)(instance->position).z) *
                    0x10000) >> 0x10;
      if (iVar17 < 0) {
        iVar17 = -iVar17;
      }
      local_48[2] = (short)iVar17;
      if (iVar17 << 0x10 < iVar7 << 0x10) {
        iVar17 = iVar7;
      }
      sVar1 = (short)iVar17;
      if (iVar17 << 0x10 < iVar6 << 0x10) {
        sVar1 = local_48[0];
      }
      iVar6 = (int)sVar1;
      if ((iVar6 < pLVar15->radius) && (iVar6 < iVar20)) {
        iVar20 = iVar6;
        pLVar16 = pLVar15;
      }
    }
    iVar5 = iVar5 + 1;
    pLVar15 = pLVar15 + 1;
  } while (iVar5 < 1);
  if (pLVar16 != (LightInstance *)0x0) {
    iVar20 = pLVar16->radius - iVar20;
    iVar5 = (uint)local_60[0].r + (iVar20 * pLVar16->r >> 0xc);
    local_60[0].r = (byte)iVar5;
    if (iVar5 < 0) {
      local_60[0].r = 0;
    }
    if (0xff < iVar5) {
      local_60[0].r = 0xff;
    }
    iVar5 = (uint)local_60[0].g + (iVar20 * pLVar16->g >> 0xc);
    local_60[0].g = (byte)iVar5;
    if (iVar5 < 0) {
      local_60[0].g = 0;
    }
    if (0xff < iVar5) {
      local_60[0].g = 0xff;
    }
    iVar20 = (uint)local_60[0].b + (iVar20 * pLVar16->b >> 0xc);
    local_60[0].b = (byte)iVar20;
    if (iVar20 < 0) {
      local_60[0].b = 0;
    }
    if (0xff < iVar20) {
      local_60[0].b = 0xff;
    }
  }
  ppNVar11 = &instance[1].node.next;
  LoadAverageCol((byte *)local_60,(byte *)ppNVar11,iVar14,0x1000 - iVar14,(undefined *)ppNVar11);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_SetAmbientInstance(struct _Instance *instance /*$v0*/, struct Level *level /*$a1*/)
 // line 546, offset 0x80036b08
	/* begin block 1 */
		// Start line: 547
		// Start offset: 0x80036B08
	/* end block 1 */
	// End offset: 0x80036B08
	// End Line: 547

	/* begin block 2 */
		// Start line: 1226
	/* end block 2 */
	// End Line: 1227

void LIGHT_SetAmbientInstance(_Instance *instance,Level *level)

{
  SetBackColor((uint)*(byte *)&instance[1].node.next,
               (uint)*(byte *)((int)&instance[1].node.next + 1),
               (uint)*(byte *)((int)&instance[1].node.next + 2));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_SetMatrixForLightGroupInstance(struct _Instance *instance /*$s2*/, struct Level *level /*$a1*/)
 // line 560, offset 0x80036b38
	/* begin block 1 */
		// Start line: 561
		// Start offset: 0x80036B38
		// Variables:
	// 		struct MATRIX *lgt; // $s0
	// 		struct MATRIX lgt_cat; // stack offset -128
	// 		struct MATRIX lm; // stack offset -96
	// 		struct MATRIX cm; // stack offset -64
	// 		struct VECTOR half; // stack offset -32
	// 		struct LightList *lightList; // $s0
	// 		int lightGrp; // $s1

		/* begin block 1.1 */
			// Start line: 663
			// Start offset: 0x80036E9C
			// TypeDefs:
		// 		struct LIGHT3D_224fake cmm
		/* end block 1.1 */
		// End offset: 0x80036E9C
		// End Line: 663
	/* end block 1 */
	// End offset: 0x80036EEC
	// End Line: 672

	/* begin block 2 */
		// Start line: 1254
	/* end block 2 */
	// End Line: 1255

void LIGHT_SetMatrixForLightGroupInstance(_Instance *instance,Level *level)

{
  MATRIX *pMVar1;
  LightList *pLVar2;
  LightGroup *pLVar3;
  uint uVar4;
  uint local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  long local_6c;
  long local_68;
  long local_64;
  short local_60;
  short local_5e;
  short local_5c;
  short local_5a;
  short local_58;
  short local_56;
  undefined2 local_54;
  undefined2 local_52;
  undefined2 local_50;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_20 = 0x800;
  local_1c = 0x800;
  local_18 = 0x800;
  local_14 = 0;
  uVar4 = (uint)instance->lightGroup;
  if (instance->matrix == (MATRIX *)0x0) {
    return;
  }
  if (((gameTrackerX.gameData.asmData.MorphType == 0) ||
      (pLVar2 = level->spectrallightList, pLVar2 == (LightList *)0x0)) ||
     (pLVar2->numLightGroups == 0)) {
    pLVar2 = level->lightList;
    if ((pLVar2 == (LightList *)0x0) || ((int)uVar4 <= pLVar2->numLightGroups)) goto LAB_80036c04;
    instance->lightGroup = '\0';
  }
  else {
    uVar4 = (uint)instance->spectralLightGroup;
    if ((int)uVar4 <= pLVar2->numLightGroups) goto LAB_80036c04;
    instance->spectralLightGroup = '\0';
  }
  uVar4 = 0;
LAB_80036c04:
  LIGHT_SetAmbientInstance(instance,level);
  if (pLVar2->numLightGroups == 0) {
    pLVar3 = &default_lightgroup;
  }
  else {
    pLVar3 = pLVar2->lightGroupList + uVar4;
  }
  if ((int)instance->lightMatrix == 0) {
    if ((instance->flags & 1U) == 0) {
      RotMatrix((short *)&instance->rotation,&local_80);
    }
    else {
      pMVar1 = instance->matrix;
      local_80 = *(uint *)pMVar1->m;
      local_7c = *(undefined4 *)(pMVar1->m + 2);
      local_78 = *(undefined4 *)(pMVar1->m + 4);
      local_74 = *(undefined4 *)(pMVar1->m + 6);
      local_70 = *(undefined4 *)(pMVar1->m + 8);
      local_6c = pMVar1->t[0];
      local_68 = pMVar1->t[1];
      local_64 = pMVar1->t[2];
    }
  }
  else {
    pMVar1 = instance->matrix + (int)instance->lightMatrix;
    local_80 = *(uint *)pMVar1->m;
    local_7c = *(undefined4 *)(pMVar1->m + 2);
    local_78 = *(undefined4 *)(pMVar1->m + 4);
    local_74 = *(undefined4 *)(pMVar1->m + 6);
    local_70 = *(undefined4 *)(pMVar1->m + 8);
    local_6c = pMVar1->t[0];
    local_68 = pMVar1->t[1];
    local_64 = pMVar1->t[2];
  }
  if (instance->extraLight == (void *)0x0) {
    MulMatrix0((undefined4 *)pLVar3,(ushort *)&local_80,&local_80);
    SetLightMatrix(&local_80);
    if ((instance->flags & 0x200000U) == 0) {
      pMVar1 = &pLVar3->colorMatrix;
    }
    else {
      local_40 = *(int *)(pLVar3->colorMatrix).m;
      local_3c = *(undefined4 *)((pLVar3->colorMatrix).m + 2);
      local_38 = *(undefined4 *)((pLVar3->colorMatrix).m + 4);
      local_34 = *(undefined4 *)((pLVar3->colorMatrix).m + 6);
      local_30 = *(uint *)((pLVar3->colorMatrix).m + 8);
      pMVar1 = (MATRIX *)&local_40;
      ScaleMatrix((int *)pMVar1,&local_20);
    }
  }
  else {
    local_60 = (pLVar3->lightMatrix).m[0];
    local_5e = (pLVar3->lightMatrix).m[1];
    local_5c = (pLVar3->lightMatrix).m[2];
    local_5a = (pLVar3->lightMatrix).m[3];
    local_58 = (pLVar3->lightMatrix).m[4];
    local_56 = (pLVar3->lightMatrix).m[5];
    local_54 = (undefined2)
               ((int)(instance->extraLightDir).x * (int)instance->extraLightScale >> 0xc);
    local_52 = (undefined2)
               ((int)(instance->extraLightDir).y * (int)instance->extraLightScale >> 0xc);
    local_50 = (undefined2)
               ((int)(instance->extraLightDir).z * (int)instance->extraLightScale >> 0xc);
    local_40 = *(int *)(pLVar3->colorMatrix).m;
    local_34 = *(undefined4 *)((pLVar3->colorMatrix).m + 6);
    local_3c = CONCAT22((pLVar3->colorMatrix).m[3],
                        (ushort)*(byte *)((int)instance->extraLight + 8) << 4);
    local_38 = CONCAT22((ushort)*(byte *)((int)instance->extraLight + 9) << 4,
                        (pLVar3->colorMatrix).m[4]);
    local_30 = local_30 & 0xffff0000 | (uint)*(byte *)((int)instance->extraLight + 10) << 4;
    MulMatrix0((undefined4 *)&local_60,(ushort *)&local_80,&local_80);
    SetLightMatrix(&local_80);
    if ((instance->flags & 0x200000U) != 0) {
      ScaleMatrix((int *)&local_40,&local_20);
    }
    pMVar1 = (MATRIX *)&local_40;
  }
  SetColorMatrix((undefined4 *)pMVar1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_DrawShadow(struct MATRIX *wcTransform /*$s2*/, struct _Instance *instance /*$s1*/, struct _PrimPool *primPool /*$s3*/, unsigned long **ot /*$s4*/)
 // line 720, offset 0x80036f04
	/* begin block 1 */
		// Start line: 721
		// Start offset: 0x80036F04
		// Variables:
	// 		struct SVECTOR face_orient; // stack offset -112
	// 		struct MATRIX rot; // stack offset -104
	// 		struct MATRIX scTransform; // stack offset -72
	// 		struct _Vector scale; // stack offset -40
	// 		struct _Instance *playerInstance; // $s0
	/* end block 1 */
	// End offset: 0x800371C8
	// End Line: 794

	/* begin block 2 */
		// Start line: 1434
	/* end block 2 */
	// End Line: 1435

void LIGHT_DrawShadow(MATRIX *wcTransform,_Instance *instance,_PrimPool *primPool,ulong **ot)

{
  undefined4 in_at;
  int iVar1;
  long x;
  ulong *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  short local_70;
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
  
  if ((int)(instance->position).z + -0x500 < (int)(instance->shadowPosition).z) {
    local_70 = MATH3D_FastAtan2((int)(instance->wNormal).y,(int)(instance->wNormal).z);
    local_70 = -local_70;
    iVar1 = (int)(instance->wNormal).x;
    x = MATH3D_FastSqrt0(0x1000000 - iVar1 * iVar1);
    local_6e = MATH3D_FastAtan2((int)(instance->wNormal).x,x);
    local_6c = (instance->rotation).z;
    RotMatrix(&local_70,(uint *)&local_68);
    local_54 = (int)(instance->shadowPosition).x;
    local_50 = (int)(instance->shadowPosition).y;
    local_4c = (int)(instance->shadowPosition).z;
    setCopControlWord(2,0,*(undefined4 *)wcTransform->m);
    setCopControlWord(2,0x800,*(undefined4 *)(wcTransform->m + 2));
    setCopControlWord(2,0x1000,*(undefined4 *)(wcTransform->m + 4));
    setCopControlWord(2,0x1800,*(undefined4 *)(wcTransform->m + 6));
    setCopControlWord(2,0x2000,*(undefined4 *)(wcTransform->m + 8));
    setCopReg(2,0x4800,(uint)local_68);
    setCopReg(2,0x5000,(uint)local_62);
    setCopReg(2,0x5800,(uint)local_5c);
    copFunction(2,0x49e012);
    uVar3 = getCopReg(2,0x4800);
    uVar4 = getCopReg(2,0x5000);
    uVar5 = getCopReg(2,0x5800);
    local_48 = (undefined2)uVar3;
    local_42 = (undefined2)uVar4;
    local_3c = (undefined2)uVar5;
    setCopReg(2,0x4800,(uint)local_66);
    setCopReg(2,0x5000,(uint)local_60);
    setCopReg(2,0x5800,(uint)local_5a);
    copFunction(2,0x49e012);
    uVar3 = getCopReg(2,0x4800);
    uVar4 = getCopReg(2,0x5000);
    uVar5 = getCopReg(2,0x5800);
    local_46 = (undefined2)uVar3;
    local_40 = (undefined2)uVar4;
    local_3a = (undefined2)uVar5;
    setCopReg(2,0x4800,(uint)local_64);
    setCopReg(2,0x5000,(uint)local_5e);
    setCopReg(2,0x5800,(uint)local_58);
    copFunction(2,0x49e012);
    uVar3 = getCopReg(2,0x4800);
    uVar4 = getCopReg(2,0x5000);
    uVar5 = getCopReg(2,0x5800);
    local_44 = (undefined2)uVar3;
    local_3e = (undefined2)uVar4;
    local_38 = (undefined2)uVar5;
    setCopControlWord(2,0x2800,wcTransform->t[0]);
    setCopControlWord(2,0x3000,wcTransform->t[1]);
    setCopControlWord(2,0x3800,wcTransform->t[2]);
    setCopReg(2,0,*(undefined4 *)&instance->shadowPosition);
    setCopReg(2,in_at,local_4c);
    copFunction(2,0x480012);
    local_34 = getCopReg(2,0x19);
    local_30 = getCopReg(2,0x1a);
    local_2c = getCopReg(2,0x1b);
    local_28 = (((int)instance->object->modelList[instance->currentModel]->maxRad * 0x1000) / 0x1e0)
               * (0x1000 - (((int)(instance->position).z - (int)(instance->shadowPosition).z) *
                           0x1000) / 0x500) >> 0xc;
    local_24 = local_28;
    local_20 = local_28;
    ScaleMatrix((int *)&local_48,&local_28);
    SetRotMatrix((undefined4 *)&local_48);
    SetTransMatrix((int)&local_48);
    puVar2 = DRAW_DrawShadow(primPool,(_Model *)0x0,ot,(int)instance->fadeValue);
    primPool->nextPrim = puVar2;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_CalcShadowPositions(struct GameTracker *gameTracker /*$s1*/)
 // line 796, offset 0x800371e8
	/* begin block 1 */
		// Start line: 797
		// Start offset: 0x800371E8
		// Variables:
	// 		struct _InstanceList *instanceList; // $v0
	// 		struct _Instance *instance; // $s0
	// 		struct _PCollideInfo pcollideInfo; // stack offset -80
	// 		struct _Position newPos; // stack offset -32
	// 		struct _Position oldPos; // stack offset -24
	// 		struct Level *level; // $v0
	/* end block 1 */
	// End offset: 0x800374E4
	// End Line: 900

	/* begin block 2 */
		// Start line: 1718
	/* end block 2 */
	// End Line: 1719

void LIGHT_CalcShadowPositions(GameTracker *gameTracker)

{
  undefined2 uVar1;
  undefined2 uVar2;
  Level *level;
  uint uVar3;
  _TFace *tface;
  _Terrain *terrain;
  _Instance *instance;
  _PCollideInfo local_50;
  undefined4 local_20;
  short local_1c;
  undefined4 local_18;
  short local_14;
  
  instance = gameTracker->instanceList->first;
  do {
    if (instance == (_Instance *)0x0) {
      return;
    }
    if ((instance->flags2 & 0x40U) == 0) {
LAB_800374a0:
      if ((_Terrain *)instance->tfaceLevel != (_Terrain *)0x0) {
        tface = instance->tface;
        terrain = *(_Terrain **)(_Terrain *)instance->tfaceLevel;
LAB_800374b8:
        LIGHT_CalcLightValue(tface,instance,terrain);
      }
    }
    else {
      uVar3 = instance->flags;
      if (((uVar3 & 0xa00) == 0x200) && ((instance->flags2 & 0x4000000U) == 0)) {
        if ((uVar3 & 0x18000000) == 0x8000000) {
          tface = instance->waterFace;
          if (tface == (_TFace *)0x0) goto LAB_800374a0;
          terrain = instance->waterFaceTerrain;
          goto LAB_800374b8;
        }
        if ((uVar3 & 0x10000000) == 0) {
          local_20 = *(undefined4 *)&instance->position;
          local_1c = (instance->position).z;
          local_18 = *(undefined4 *)&instance->position;
          local_14 = (instance->position).z;
        }
        else {
          uVar1 = *(undefined2 *)instance->matrix[1].t;
          uVar2 = *(undefined2 *)(instance->matrix[1].t + 1);
          local_20 = CONCAT22(uVar2,uVar1);
          local_18 = CONCAT22(uVar2,uVar1);
          local_1c = *(short *)(instance->matrix[1].t + 2);
          local_14 = local_1c;
        }
        local_50.collideType = 0x37;
        local_50.newPoint = (SVECTOR *)&local_20;
        local_50.oldPoint = (SVECTOR *)&local_18;
        local_1c = local_1c + -0x500;
        local_14 = local_14 + 0x100;
        instance->flags = instance->flags | 0x40;
        local_50.instance = instance;
        level = STREAM_GetLevelWithID(instance->currentStreamUnitID);
        if (level == (Level *)0x0) {
          local_50.type = 0;
        }
        else {
          COLLIDE_PointAndWorld(&local_50,gameTracker,level);
        }
        instance->flags = instance->flags & 0xffffffbf;
        if (local_50.type == 3) {
          terrain = (_Terrain *)((local_50.inst)->node).prev;
          tface = local_50.prim;
LAB_8003738c:
          LIGHT_CalcLightValue(tface,instance,terrain);
        }
        else {
          tface = (_TFace *)0x0;
          if (local_50.type != 5) {
            terrain = (_Terrain *)0x0;
            goto LAB_8003738c;
          }
        }
        if (local_50.type != 0) {
          if (local_50.type == 1) {
            (instance->wNormal).x = 0;
            (instance->wNormal).y = 0;
            (instance->wNormal).z = 0x1000;
          }
          else {
            if (((local_50.type == 3) && ((local_50.prim)->textoff != 0xffff)) &&
               ((*(ushort *)
                  ((int)&((local_50.inst)->node).prev[6].next[1].prev +
                  (uint)(local_50.prim)->textoff + 2) & 0x4000) != 0)) {
              uVar3 = instance->flags | 0x200000;
            }
            else {
              uVar3 = instance->flags & 0xffdfffff;
            }
            instance->flags = uVar3;
            (instance->wNormal).x = local_50.wNormal.vx;
            (instance->wNormal).y = local_50.wNormal.vy;
            (instance->wNormal).z = local_50.wNormal.vz;
          }
        }
        *(undefined4 *)&instance->shadowPosition = local_20;
        (instance->shadowPosition).z = local_1c;
      }
      else {
        if ((instance->flags2 & 0x40U) == 0) goto LAB_800374a0;
      }
    }
    instance->flags = instance->flags & 0xf7ffffff;
    instance = instance->next;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_InitSources(struct LightInfo *lightInfo /*$s1*/)
 // line 920, offset 0x800374f8
	/* begin block 1 */
		// Start line: 921
		// Start offset: 0x800374F8
		// Variables:
	// 		struct PointLight *pointLight; // $s0
	// 		struct PointLight *endPointLight; // $s2
	// 		struct SpotLight *spotLight; // $s0
	// 		struct SpotLight *endSpotLight; // $s2
	/* end block 1 */
	// End offset: 0x80037598
	// End Line: 953

	/* begin block 2 */
		// Start line: 1978
	/* end block 2 */
	// End Line: 1979

void LIGHT_InitSources(LightInfo *lightInfo)

{
  PointLight *node;
  SpotLight *node_00;
  
  node = lightInfo->pointLightPool;
  (lightInfo->usedPointLightList).next = (NodeType *)0x0;
  (lightInfo->usedPointLightList).prev = (NodeType *)0x0;
  (lightInfo->freePointLightList).next = (NodeType *)0x0;
  (lightInfo->freePointLightList).prev = (NodeType *)0x0;
  (lightInfo->activePointLightList).next = (NodeType *)0x0;
  (lightInfo->activePointLightList).prev = (NodeType *)0x0;
  while (node < (PointLight *)&lightInfo->usedPointLightList) {
    LIST_InsertFunc(&lightInfo->freePointLightList,(NodeType *)node);
    node = node + 1;
  }
  node_00 = lightInfo->spotLightPool;
  (lightInfo->usedSpotLightList).next = (NodeType *)0x0;
  (lightInfo->usedSpotLightList).prev = (NodeType *)0x0;
  (lightInfo->freeSpotLightList).next = (NodeType *)0x0;
  (lightInfo->freeSpotLightList).prev = (NodeType *)0x0;
  (lightInfo->activeSpotLightList).next = (NodeType *)0x0;
  (lightInfo->activeSpotLightList).prev = (NodeType *)0x0;
  while (node_00 < (SpotLight *)&lightInfo->usedSpotLightList) {
    LIST_InsertFunc(&lightInfo->freeSpotLightList,(NodeType *)node_00);
    node_00 = node_00 + 1;
  }
  lightInfo->numSavedColors = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_Restore(struct LightInfo *lightInfo /*$a0*/)
 // line 1351, offset 0x800375b4
	/* begin block 1 */
		// Start line: 2879
	/* end block 1 */
	// End Line: 2880

	/* begin block 2 */
		// Start line: 2880
	/* end block 2 */
	// End Line: 2881

void LIGHT_Restore(LightInfo *lightInfo)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_SourcesAndTerrain(struct LightInfo *lightInfo /*$a0*/, struct _Terrain *terrain /*$a1*/)
 // line 1355, offset 0x800375bc
	/* begin block 1 */
		// Start line: 2887
	/* end block 1 */
	// End Line: 2888

	/* begin block 2 */
		// Start line: 2888
	/* end block 2 */
	// End Line: 2889

void LIGHT_SourcesAndTerrain(LightInfo *lightInfo,_Terrain *terrain)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_ActivateSources(struct _CameraCore_Type *cameraCore /*$s2*/, struct Level *level /*$a1*/, struct NodeType *activeLightList /*$s3*/, struct NodeType *usedLightList /*$s4*/)
 // line 1386, offset 0x800375c4
	/* begin block 1 */
		// Start line: 1387
		// Start offset: 0x800375C4
		// Variables:
	// 		struct NodeType lightList; // stack offset -32
	// 		struct CDLight *light; // $s0

		/* begin block 1.1 */
			// Start line: 1395
			// Start offset: 0x8003760C
			// Variables:
		// 		struct CDLight *next; // $s1
		/* end block 1.1 */
		// End offset: 0x8003764C
		// End Line: 1406

		/* begin block 1.2 */
			// Start line: 1413
			// Start offset: 0x80037668
			// Variables:
		// 		struct CDLight *next; // $s1
		/* end block 1.2 */
		// End offset: 0x800376B0
		// End Line: 1423
	/* end block 1 */
	// End offset: 0x800376BC
	// End Line: 1426

	/* begin block 2 */
		// Start line: 2765
	/* end block 2 */
	// End Line: 2766

void LIGHT_ActivateSources
               (_CameraCore_Type *cameraCore,Level *level,NodeType *activeLightList,
               NodeType *usedLightList)

{
  byte bVar1;
  NodeType *node;
  int iVar2;
  NodeType *pNVar3;
  NodeType NStack32;
  
  memset(&NStack32,0,8);
  pNVar3 = activeLightList->next;
  while (node = pNVar3, node != (NodeType *)0x0) {
    pNVar3 = node->next;
    iVar2 = BSP_SphereIntersectsViewVolume_S(&node[1].next,cameraCore);
    if (iVar2 == 0) {
      LIST_DeleteFunc(node);
      bVar1 = *(byte *)((int)&node[1].prev + 3);
      *(byte *)((int)&node[1].prev + 3) = bVar1 & 0xef;
      if ((bVar1 & 0x20) != 0) {
        LIST_InsertFunc(&NStack32,node);
      }
    }
  }
  pNVar3 = usedLightList->next;
  while (node = pNVar3, node != (NodeType *)0x0) {
    pNVar3 = node->next;
    if (((*(byte *)((int)&node[1].prev + 3) & 0x20) != 0) &&
       (iVar2 = BSP_SphereIntersectsViewVolume_S(&node[1].next,cameraCore), iVar2 != 0)) {
      LIST_DeleteFunc(node);
      LIST_InsertFunc(activeLightList,node);
      *(byte *)((int)&node[1].prev + 3) = *(byte *)((int)&node[1].prev + 3) | 0x10;
    }
  }
  LIST_Concatenate(usedLightList,&NStack32);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_RelocatePointerInList(struct Level *oldLevel /*$a0*/, long sizeOfLevel /*$a1*/, long offset /*$a2*/, struct NodeType *currentLightList /*$a3*/)
 // line 1451, offset 0x800376e4
	/* begin block 1 */
		// Start line: 1453
		// Start offset: 0x800376E4
		// Variables:
	// 		struct CDLight *light; // $a3
	/* end block 1 */
	// End offset: 0x8003778C
	// End Line: 1473

	/* begin block 2 */
		// Start line: 3051
	/* end block 2 */
	// End Line: 3052

	/* begin block 3 */
		// Start line: 3052
	/* end block 3 */
	// End Line: 3053

	/* begin block 4 */
		// Start line: 3054
	/* end block 4 */
	// End Line: 3055

void LIGHT_RelocatePointerInList
               (Level *oldLevel,long sizeOfLevel,long offset,NodeType *currentLightList)

{
  NodeType *pNVar1;
  NodeType *pNVar2;
  Level *pLVar3;
  Level *pLVar4;
  
  pLVar3 = (Level *)currentLightList->next;
  if ((oldLevel <= pLVar3) && (pLVar3 <= (Level *)((int)&oldLevel->terrain + sizeOfLevel))) {
    pNVar1 = (NodeType *)0x0;
    if (pLVar3 != (Level *)0x0) {
      pNVar1 = (NodeType *)((int)&pLVar3->terrain + offset);
    }
    currentLightList->next = pNVar1;
  }
  pNVar1 = currentLightList->next;
  pLVar3 = (Level *)((int)&oldLevel->terrain + sizeOfLevel);
  while (pNVar1 != (NodeType *)0x0) {
    pLVar4 = (Level *)pNVar1->prev;
    if ((oldLevel <= pLVar4) && (pLVar4 <= pLVar3)) {
      pNVar2 = (NodeType *)0x0;
      if (pLVar4 != (Level *)0x0) {
        pNVar2 = (NodeType *)((int)&pLVar4->terrain + offset);
      }
      pNVar1->prev = pNVar2;
    }
    pLVar4 = (Level *)pNVar1->next;
    if ((oldLevel <= pLVar4) && (pLVar4 <= pLVar3)) {
      pNVar2 = (NodeType *)0x0;
      if (pLVar4 != (Level *)0x0) {
        pNVar2 = (NodeType *)((int)&pLVar4->terrain + offset);
      }
      pNVar1->next = pNVar2;
    }
    pNVar1 = pNVar1->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_RelocateLights(struct LightInfo *lightInfo /*$s3*/, struct Level *oldLevel /*$s0*/, long sizeOfLevel /*$s1*/, long offset /*$s2*/)
 // line 1475, offset 0x80037794
	/* begin block 1 */
		// Start line: 3099
	/* end block 1 */
	// End Line: 3100

void LIGHT_RelocateLights(LightInfo *lightInfo,Level *oldLevel,long sizeOfLevel,long offset)

{
  LIGHT_RelocatePointerInList(oldLevel,sizeOfLevel,offset,&lightInfo->activeSpotLightList);
  LIGHT_RelocatePointerInList(oldLevel,sizeOfLevel,offset,&lightInfo->usedSpotLightList);
  LIGHT_RelocatePointerInList(oldLevel,sizeOfLevel,offset,&lightInfo->activePointLightList);
  LIGHT_RelocatePointerInList(oldLevel,sizeOfLevel,offset,&lightInfo->usedPointLightList);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_ClassifySources(struct _CameraCore_Type *cameraCore /*$s0*/, struct Level *level /*$s2*/, struct LightInfo *lightInfo /*$s1*/)
 // line 1488, offset 0x80037828
	/* begin block 1 */
		// Start line: 3126
	/* end block 1 */
	// End Line: 3127

void LIGHT_ClassifySources(_CameraCore_Type *cameraCore,Level *level,LightInfo *lightInfo)

{
  LIGHT_ActivateSources
            (cameraCore,level,&lightInfo->activeSpotLightList,&lightInfo->usedSpotLightList);
  LIGHT_ActivateSources
            (cameraCore,level,&lightInfo->activePointLightList,&lightInfo->usedPointLightList);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ LIGHT_CollideInstanceAndSphere(struct _Instance *instance /*$a0*/, struct _Sphere *sphere /*$a1*/)
 // line 1501, offset 0x80037880
	/* begin block 1 */
		// Start line: 1502
		// Start offset: 0x80037880
		// Variables:
	// 		struct _SVector instToSphere; // stack offset -8
	// 		long distanceSq; // $v0
	// 		long radius; // $v0
	// 		long radiusSquared; // $v1
	/* end block 1 */
	// End offset: 0x80037880
	// End Line: 1502

	/* begin block 2 */
		// Start line: 3153
	/* end block 2 */
	// End Line: 3154

	/* begin block 3 */
		// Start line: 3158
	/* end block 3 */
	// End Line: 3159

long LIGHT_CollideInstanceAndSphere(_Instance *instance,_Sphere *sphere)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = (int)(((uint)(ushort)(sphere->position).x - (uint)(ushort)(instance->position).x) *
               0x10000) >> 0x10;
  iVar2 = (int)(((uint)(ushort)(sphere->position).y - (uint)(ushort)(instance->position).y) *
               0x10000) >> 0x10;
  iVar3 = (int)(((uint)(ushort)(sphere->position).z - (uint)(ushort)(instance->position).z) *
               0x10000) >> 0x10;
  iVar4 = (int)instance->object->modelList[instance->currentModel]->maxRad + (uint)sphere->radius;
  return (uint)(iVar1 * iVar1 + iVar2 * iVar2 + iVar3 * iVar3 < iVar4 * iVar4);
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_SourcesAndInstances(struct LightInfo *lightInfo /*$s2*/, struct _InstanceList *instanceList /*$a1*/)
 // line 1524, offset 0x80037934
	/* begin block 1 */
		// Start line: 1525
		// Start offset: 0x80037934
		// Variables:
	// 		long dp; // $a0
	// 		struct _SVector lightToInst; // stack offset -24
	// 		struct SpotLight *spotLight; // $s0
	// 		struct PointLight *pointLight; // $s0
	// 		struct _Instance *instance; // $s1
	/* end block 1 */
	// End offset: 0x80037B38
	// End Line: 1580

	/* begin block 2 */
		// Start line: 3218
	/* end block 2 */
	// End Line: 3219

void LIGHT_SourcesAndInstances(LightInfo *lightInfo,_InstanceList *instanceList)

{
  long lVar1;
  short sVar2;
  int iVar3;
  NodeType *pNVar4;
  _Instance *instance;
  _Normal local_18;
  
  instance = instanceList->first;
  while (instance != (_Instance *)0x0) {
    instance->extraLight = (void *)0x0;
    pNVar4 = (lightInfo->activeSpotLightList).next;
    while (pNVar4 != (NodeType *)0x0) {
      lVar1 = LIGHT_CollideInstanceAndSphere(instance,(_Sphere *)&pNVar4[1].next);
      if (lVar1 != 0) {
        local_18.x = (instance->position).x - *(short *)&pNVar4[3].prev;
        local_18.y = (instance->position).y - *(short *)((int)&pNVar4[3].prev + 2);
        local_18.z = (instance->position).z - *(short *)&pNVar4[3].next;
        MATH3D_Normalize(&local_18);
        iVar3 = (int)local_18.x * (int)*(short *)((int)&pNVar4[3].next + 2) +
                (int)local_18.y * (int)*(short *)&pNVar4[4].prev +
                (int)local_18.z * (int)*(short *)((int)&pNVar4[4].prev + 2) >> 0xc;
        if (*(short *)&pNVar4[4].next <= iVar3) {
          *(NodeType **)&instance->extraLight = pNVar4;
          (instance->extraLightDir).x = -local_18.x;
          (instance->extraLightDir).y = -local_18.y;
          (instance->extraLightDir).z = -local_18.z;
          iVar3 = (iVar3 - *(short *)&pNVar4[4].next) * (int)*(short *)((int)&pNVar4[4].next + 2);
          sVar2 = 0x1000;
          if (iVar3 < 0x1001) {
            sVar2 = (short)iVar3;
          }
          instance->extraLightScale = sVar2;
        }
      }
      pNVar4 = pNVar4->next;
    }
    pNVar4 = (lightInfo->activePointLightList).next;
    while (pNVar4 != (NodeType *)0x0) {
      lVar1 = LIGHT_CollideInstanceAndSphere(instance,(_Sphere *)&pNVar4[1].next);
      if (lVar1 != 0) {
        local_18.x = (instance->position).x - *(short *)&pNVar4[1].next;
        local_18.y = (instance->position).y - *(short *)((int)&pNVar4[1].next + 2);
        local_18.z = (instance->position).z - *(short *)&pNVar4[2].prev;
        MATH3D_Normalize(&local_18);
        *(NodeType **)&instance->extraLight = pNVar4;
        (instance->extraLightDir).x = -local_18.x;
        (instance->extraLightDir).y = -local_18.y;
        instance->extraLightScale = 0x1000;
        (instance->extraLightDir).z = -local_18.z;
      }
      pNVar4 = pNVar4->next;
    }
    instance = instance->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_CalcDQPTable(struct Level *level /*$a3*/)
 // line 1589, offset 0x80037b50
	/* begin block 1 */
		// Start line: 1590
		// Start offset: 0x80037B50
		// Variables:
	// 		long dqa; // $a1
	// 		long limit; // $t0

		/* begin block 1.1 */
			// Start line: 1603
			// Start offset: 0x80037B98
		/* end block 1.1 */
		// End offset: 0x80037BC0
		// End Line: 1610

		/* begin block 1.2 */
			// Start line: 1613
			// Start offset: 0x80037BD0
		/* end block 1.2 */
		// End offset: 0x80037C04
		// End Line: 1620
	/* end block 1 */
	// End offset: 0x80037C5C
	// End Line: 1649

	/* begin block 2 */
		// Start line: 3358
	/* end block 2 */
	// End Line: 3359

void LIGHT_CalcDQPTable(Level *level)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  int iVar5;
  
  uVar3 = (uint)level->fogFar;
  uVar2 = (uint)level->fogNear;
  if (uVar3 != uVar2) {
    iVar5 = -((int)(uVar3 * uVar2) / (int)(uVar3 - uVar2));
    if (0x9ffe < iVar5) {
      iVar5 = 0x9ffe;
      uVar4 = (ushort)((int)(uVar3 * 0x9ffe) / (int)(0x9ffe - uVar3));
      if ((uint)level->holdFogNear == uVar2) {
        level->holdFogNear = uVar4;
      }
      level->fogNear = uVar4;
    }
    if (iVar5 < -0x9ffe) {
      uVar4 = (ushort)((int)((uint)level->fogFar * -0x9ffe) / (int)(-0x9ffe - (uint)level->fogFar));
      if (level->holdFogNear == level->fogNear) {
        level->holdFogNear = uVar4;
      }
      level->fogNear = uVar4;
      iVar5 = -0x9ffe;
    }
    depthQFogStart =
         (iVar5 * -0x1000) /
         ((int)((uint)level->fogFar << 0xc) / (int)((uint)level->fogFar - (uint)level->fogNear));
    depthQBlendStart = depthQFogStart;
    if (*(short *)&level->backColorR == 0) {
      depthQBlendStart = 0xffff;
    }
    lVar1 = depthQBlendStart;
    level->depthQFogStart = depthQFogStart;
    level->depthQBlendStart = lVar1;
  }
  return;
}





