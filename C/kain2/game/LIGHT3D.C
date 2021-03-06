#include "THISDUST.H"
#include "LIGHT3D.H"


// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_GetLightMatrix(struct _Instance *instance /*$a0*/, struct Level *level /*$a1*/, struct MATRIX *lightM /*$a2*/, struct MATRIX *colorM /*$a3*/)
 // line 70, offset 0x80035acc
	/* begin block 1 */
		// Start line: 72
		// Start offset: 0x80035ACC
		// Variables:
	// 		struct MATRIX *lightGroup; // $t0
	// 		struct LightList *lightList; // $v1
	// 		int lightGrp; // $t1

		/* begin block 1.1 */
			// Start line: 120
			// Start offset: 0x80035B9C
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
		// End offset: 0x80035D60
		// End Line: 186
	/* end block 1 */
	// End offset: 0x80035E38
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
LAB_80035b50:
      in_v1 = level->lightList;
      pLVar2 = (LightGroup *)0x0;
    }
  }
  else {
    if ((instance != gameTrackerX.playerInstance) ||
       (pLVar2 = level->razielSpectralLightGroup, pLVar2 == (LightGroup *)0x0)) {
      in_v1 = level->spectrallightList;
      if ((in_v1 == (LightList *)0x0) || (in_v1->numLightGroups == 0)) goto LAB_80035b50;
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
       (pLVar3 = level->razielSpectralLightGroup, pLVar3 != (LightGroup *)0x0)) goto LAB_80035c24;
    in_t3 = level->spectrallightList;
    if ((in_t3 != (LightList *)0x0) && (in_t3->numLightGroups != 0)) {
      uVar10 = (uint)instance->spectralLightGroup;
      pLVar3 = (LightGroup *)0x0;
      goto LAB_80035c24;
    }
  }
  else {
    if ((instance == gameTrackerX.playerInstance) &&
       (pLVar3 = level->razielLightGroup, pLVar3 != (LightGroup *)0x0)) goto LAB_80035c24;
  }
  in_t3 = level->lightList;
  pLVar3 = (LightGroup *)0x0;
LAB_80035c24:
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
 // line 200, offset 0x80035e40
	/* begin block 1 */
		// Start line: 201
		// Start offset: 0x80035E40
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
			// Start offset: 0x80035F7C
			// Variables:
		// 		short *todRGB; // $v0

			/* begin block 1.1.1 */
				// Start line: 265
				// Start offset: 0x80035FA0
			/* end block 1.1.1 */
			// End offset: 0x80036010
			// End Line: 271
		/* end block 1.1 */
		// End offset: 0x80036028
		// End Line: 272
	/* end block 1 */
	// End offset: 0x80036028
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
// void /*$ra*/ LIGHT_GetAmbient(struct _ColorType *color /*$a0*/, struct _Instance *instance /*$a1*/)
 // line 284, offset 0x80036050
	/* begin block 1 */
		// Start line: 286
		// Start offset: 0x80036050
		// Variables:
	// 		int lightval; // $v1
	/* end block 1 */
	// End offset: 0x80036070
	// End Line: 327

	/* begin block 2 */
		// Start line: 622
	/* end block 2 */
	// End Line: 623

	/* begin block 3 */
		// Start line: 623
	/* end block 3 */
	// End Line: 624

	/* begin block 4 */
		// Start line: 662
	/* end block 4 */
	// End Line: 663

void LIGHT_GetAmbient(_ColorType *color,_Instance *instance)

{
  uchar uVar1;
  
  uVar1 = '0';
  if ((instance->object->oflags2 & 0x800U) != 0) {
    uVar1 = '\0';
  }
  color->b = uVar1;
  color->g = uVar1;
  color->r = uVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_CalcLightValue(struct _TFace *tface /*$t2*/, struct _Instance *instance /*$s7*/, struct _Terrain *terrain /*$t3*/)
 // line 330, offset 0x80036080
	/* begin block 1 */
		// Start line: 331
		// Start offset: 0x80036080
		// Variables:
	// 		struct _ColorType color; // stack offset -88
	// 		short fadespeed; // $a2

		/* begin block 1.1 */
			// Start line: 342
			// Start offset: 0x800360E0
			// Variables:
		// 		struct _ColorType color1; // stack offset -80
		// 		struct _ColorType color2; // stack offset -72
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
		// 		short position[3]; // stack offset -64
		// 		struct _SVector normal; // stack offset -56
		// 		struct BSPTree *bsp; // $a1
		// 		int major; // $a3
		// 		int minor; // $s6

			/* begin block 1.1.1 */
				// Start line: 445
				// Start offset: 0x800364D4
				// Variables:
			// 		long r; // $v0
			// 		long g; // $a1
			// 		long b; // $v1
			// 		int lum; // $a0
			/* end block 1.1.1 */
			// End offset: 0x8003657C
			// End Line: 466
		/* end block 1.1 */
		// End offset: 0x8003657C
		// End Line: 466

		/* begin block 1.2 */
			// Start line: 481
			// Start offset: 0x8003659C
			// Variables:
		// 		int i; // $t0
		// 		struct LightInstance *li; // $t4
		// 		long dist; // $t3
		// 		struct LightInstance *tli; // $t2

			/* begin block 1.2.1 */
				// Start line: 488
				// Start offset: 0x800365AC
				// Variables:
			// 		struct _Instance *inst; // $a1

				/* begin block 1.2.1.1 */
					// Start line: 491
					// Start offset: 0x800365D4
					// Variables:
				// 		short tdist; // $a3
				// 		struct _Position pos; // stack offset -64
				// 		struct MATRIX *mat; // $a1
				/* end block 1.2.1.1 */
				// End offset: 0x800366BC
				// End Line: 508
			/* end block 1.2.1 */
			// End offset: 0x800366BC
			// End Line: 509
		/* end block 1.2 */
		// End offset: 0x80036788
		// End Line: 533
	/* end block 1 */
	// End offset: 0x800367A0
	// End Line: 541

	/* begin block 2 */
		// Start line: 714
	/* end block 2 */
	// End Line: 715

/* WARNING: Removing unreachable block (ram,0x80036554) */

void LIGHT_CalcLightValue(_TFace *tface,_Instance *instance,_Terrain *terrain)

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
  _ColorType local_58 [2];
  byte abStack80 [8];
  byte abStack72 [8];
  short local_40 [4];
  _SVector _Stack56;
  short *local_30;
  byte *local_2c;
  
  if ((((instance->flags & 0x400000U) != 0) || (tface == (_TFace *)0x0)) ||
     (instance->lightMatrix != 0)) {
    LIGHT_GetAmbient(local_58,instance);
    iVar13 = 0x100;
    goto LAB_8003659c;
  }
  p_Var12 = terrain->vertexList;
  pBVar8 = terrain->BSPTreeArray + instance->bspTree;
  local_40[0] = (instance->position).x - (pBVar8->globalOffset).x;
  p_Var18 = p_Var12 + (tface->face).v0;
  p_Var17 = p_Var12 + (tface->face).v1;
  local_40[1] = (instance->position).y - (pBVar8->globalOffset).y;
  local_40[2] = (instance->shadowPosition).z - (pBVar8->globalOffset).z;
  p_Var12 = p_Var12 + (tface->face).v2;
  lVar4 = COLLIDE_GetNormal(tface->normal,(short *)terrain->normalList,&_Stack56);
  iVar19 = lVar4 + 1;
  iVar13 = lVar4 + 2;
  if (2 < iVar13) {
    iVar13 = lVar4 + -1;
  }
  if (2 < iVar19) {
    iVar19 = lVar4 + -2;
  }
  sVar1 = local_40[iVar13];
  sVar2 = (&(p_Var18->vertex).x)[iVar13];
  uVar11 = 0;
  if ((sVar2 < sVar1) && (sVar1 < (&(p_Var17->vertex).x)[iVar13])) {
LAB_800361f0:
    uVar11 = 1;
LAB_800361f4:
    iVar5 = iVar13 * 2;
    if ((local_40[iVar13] <= (&(p_Var17->vertex).x)[iVar13]) ||
       ((&(p_Var12->vertex).x)[iVar13] <= local_40[iVar13])) goto LAB_8003622c;
LAB_80036260:
    uVar11 = uVar11 | 2;
LAB_80036264:
    iVar6 = iVar13 * 2;
    if ((local_40[iVar13] <= (&(p_Var12->vertex).x)[iVar13]) ||
       ((&(p_Var18->vertex).x)[iVar13] <= local_40[iVar13])) goto LAB_8003629c;
LAB_800362d0:
    uVar11 = uVar11 | 4;
  }
  else {
    if (sVar2 <= sVar1) goto LAB_800361f4;
    iVar5 = iVar13 << 1;
    if ((&(p_Var17->vertex).x)[iVar13] < sVar1) goto LAB_800361f0;
LAB_8003622c:
    if (*(short *)((int)&(p_Var17->vertex).x + iVar5) <= *(short *)((int)local_40 + iVar5))
    goto LAB_80036264;
    iVar6 = iVar13 << 1;
    if (*(short *)((int)&(p_Var12->vertex).x + iVar5) < *(short *)((int)local_40 + iVar5))
    goto LAB_80036260;
LAB_8003629c:
    if ((*(short *)((int)local_40 + iVar6) < *(short *)((int)&(p_Var12->vertex).x + iVar6)) &&
       (*(short *)((int)&(p_Var18->vertex).x + iVar6) < *(short *)((int)local_40 + iVar6)))
    goto LAB_800362d0;
  }
  if (uVar11 == 3) {
    iVar5 = 1;
  }
  else {
    if (uVar11 == 6) {
      iVar5 = 2;
    }
    else {
      iVar5 = 0;
      if (uVar11 != 5) {
        return;
      }
    }
  }
  iVar6 = 0;
  p_Var3 = p_Var18;
  if (iVar5 != 0) {
    do {
      p_Var18 = p_Var17;
      p_Var17 = p_Var12;
      p_Var12 = p_Var3;
      iVar6 = iVar6 + 1;
      p_Var3 = p_Var18;
    } while (iVar6 < iVar5);
  }
  iVar6 = (int)(&(p_Var17->vertex).x)[iVar13];
  iVar5 = (int)(&(p_Var18->vertex).x)[iVar13];
  if (iVar6 == iVar5) {
    return;
  }
  local_30 = local_40;
  iVar7 = (iVar5 - local_40[iVar13]) * 0x1000;
  iVar6 = iVar7 / (iVar6 - iVar5);
  if (iVar6 < 0) {
    iVar6 = -iVar6;
  }
  iVar16 = iVar6;
  if (iVar6 < 0) {
    iVar16 = 0;
  }
  if (0x1000 < iVar6) {
    iVar16 = 0x1000;
  }
  iVar13 = (int)(&(p_Var12->vertex).x)[iVar13];
  if (iVar13 == iVar5) {
    return;
  }
  iVar7 = iVar7 / (iVar13 - iVar5);
  if (iVar7 < 0) {
    iVar7 = -iVar7;
  }
  iVar13 = iVar7;
  if (iVar7 < 0) {
    iVar13 = 0;
  }
  if (0x1000 < iVar7) {
    iVar13 = 0x1000;
  }
  local_2c = abStack80;
  LoadAverageCol(&p_Var18->r0,&p_Var17->r0,0x1000 - iVar16,iVar16,local_2c);
  LoadAverageCol(&p_Var18->r0,&p_Var12->r0,0x1000 - iVar13,iVar13,abStack72);
  iVar5 = (int)(&(p_Var18->vertex).x)[iVar19];
  iVar16 = ((&(p_Var17->vertex).x)[iVar19] - iVar5) * iVar16;
  if (iVar16 < 0) {
    iVar16 = iVar16 + 0xfff;
  }
  iVar13 = ((&(p_Var12->vertex).x)[iVar19] - iVar5) * iVar13;
  iVar6 = iVar5 + (iVar16 >> 0xc);
  if (iVar13 < 0) {
    iVar13 = iVar13 + 0xfff;
  }
  iVar5 = iVar5 + (iVar13 >> 0xc);
  if (iVar6 == iVar5) {
    return;
  }
  iVar13 = ((iVar6 - local_30[iVar19]) * 0x1000) / (iVar6 - iVar5);
  if (iVar13 < 0) {
    iVar13 = -iVar13;
  }
  iVar19 = iVar13;
  if (iVar13 < 0) {
    iVar19 = 0;
  }
  if (0x1000 < iVar13) {
    iVar19 = 0x1000;
  }
  LoadAverageCol(local_2c,abStack72,0x1000 - iVar19,iVar19,(undefined *)local_58);
  uVar11 = (int)((uint)local_58[0].r * 0x4c8 + (uint)local_58[0].g * 0x964 +
                (uint)local_58[0].b * 0x1d3) >> 0xc;
  local_58[0].r = (byte)uVar11;
  iVar13 = 0x400;
  local_58[0].g = local_58[0].r;
  local_58[0].b = local_58[0].r;
  if (0x44 < uVar11) {
    local_58[0].r = (char)((int)(uVar11 - 0x44) / 2) + 0x44;
    local_58[0].g = local_58[0].r;
    local_58[0].b = local_58[0].r;
  }
LAB_8003659c:
  pLVar15 = (LightInstance *)0x0;
  iVar19 = 0x7fff;
  pLVar14 = gameTrackerX.gameData.asmData.lightInstances;
  iVar5 = 0;
  do {
    p_Var9 = pLVar14->lightInstance;
    if (((p_Var9 != (_Instance *)0x0) && (p_Var9 != instance)) && (p_Var9->matrix != (MATRIX *)0x0))
    {
      pMVar10 = p_Var9->matrix + pLVar14->segment;
      iVar6 = (int)(((uint)*(ushort *)pMVar10->t - (uint)(ushort)(instance->position).x) * 0x10000)
              >> 0x10;
      if (iVar6 < 0) {
        iVar6 = -iVar6;
      }
      local_40[0] = (short)iVar6;
      iVar7 = (int)(((uint)*(ushort *)(pMVar10->t + 1) - (uint)(ushort)(instance->position).y) *
                   0x10000) >> 0x10;
      if (iVar7 < 0) {
        iVar7 = -iVar7;
      }
      local_40[1] = (short)iVar7;
      iVar16 = (int)(((uint)*(ushort *)(pMVar10->t + 2) - (uint)(ushort)(instance->position).z) *
                    0x10000) >> 0x10;
      if (iVar16 < 0) {
        iVar16 = -iVar16;
      }
      local_40[2] = (short)iVar16;
      if (iVar16 << 0x10 < iVar7 << 0x10) {
        iVar16 = iVar7;
      }
      sVar1 = (short)iVar16;
      if (iVar16 << 0x10 < iVar6 << 0x10) {
        sVar1 = local_40[0];
      }
      iVar6 = (int)sVar1;
      if ((iVar6 < pLVar14->radius) && (iVar6 < iVar19)) {
        iVar19 = iVar6;
        pLVar15 = pLVar14;
      }
    }
    iVar5 = iVar5 + 1;
    pLVar14 = pLVar14 + 1;
  } while (iVar5 < 1);
  if (pLVar15 != (LightInstance *)0x0) {
    iVar19 = pLVar15->radius - iVar19;
    iVar5 = (uint)local_58[0].r + (iVar19 * pLVar15->r >> 0xc);
    local_58[0].r = (byte)iVar5;
    if (iVar5 < 0) {
      local_58[0].r = 0;
    }
    if (0xff < iVar5) {
      local_58[0].r = 0xff;
    }
    iVar5 = (uint)local_58[0].g + (iVar19 * pLVar15->g >> 0xc);
    local_58[0].g = (byte)iVar5;
    if (iVar5 < 0) {
      local_58[0].g = 0;
    }
    if (0xff < iVar5) {
      local_58[0].g = 0xff;
    }
    iVar19 = (uint)local_58[0].b + (iVar19 * pLVar15->b >> 0xc);
    local_58[0].b = (byte)iVar19;
    if (iVar19 < 0) {
      local_58[0].b = 0;
    }
    if (0xff < iVar19) {
      local_58[0].b = 0xff;
    }
  }
  LoadAverageCol((byte *)local_58,(byte *)&instance->light_color,iVar13,0x1000 - iVar13,
                 (undefined *)&instance->light_color);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_SetAmbientInstance(struct _Instance *instance /*$v0*/, struct Level *level /*$a1*/)
 // line 543, offset 0x800367d0
	/* begin block 1 */
		// Start line: 544
		// Start offset: 0x800367D0
	/* end block 1 */
	// End offset: 0x800367D0
	// End Line: 544

	/* begin block 2 */
		// Start line: 1209
	/* end block 2 */
	// End Line: 1210

void LIGHT_SetAmbientInstance(_Instance *instance,Level *level)

{
  SetBackColor((uint)*(byte *)&instance->light_color,
               (uint)*(byte *)((int)&instance->light_color + 1),
               (uint)*(byte *)((int)&instance->light_color + 2));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_SetMatrixForLightGroupInstance(struct _Instance *instance /*$s2*/, struct Level *level /*$a1*/)
 // line 557, offset 0x80036800
	/* begin block 1 */
		// Start line: 558
		// Start offset: 0x80036800
		// Variables:
	// 		struct MATRIX *lgt; // $s0
	// 		struct MATRIX lgt_cat; // stack offset -128
	// 		struct MATRIX lm; // stack offset -96
	// 		struct MATRIX cm; // stack offset -64
	// 		struct VECTOR half; // stack offset -32
	// 		struct LightList *lightList; // $s0
	// 		int lightGrp; // $s1

		/* begin block 1.1 */
			// Start line: 660
			// Start offset: 0x80036B60
			// TypeDefs:
		// 		struct LIGHT3D_229fake cmm
		/* end block 1.1 */
		// End offset: 0x80036B60
		// End Line: 660
	/* end block 1 */
	// End offset: 0x80036BB0
	// End Line: 669

	/* begin block 2 */
		// Start line: 1237
	/* end block 2 */
	// End Line: 1238

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
    if ((pLVar2 == (LightList *)0x0) || ((int)uVar4 <= pLVar2->numLightGroups)) goto LAB_800368cc;
    instance->lightGroup = '\0';
  }
  else {
    uVar4 = (uint)instance->spectralLightGroup;
    if ((int)uVar4 <= pLVar2->numLightGroups) goto LAB_800368cc;
    instance->spectralLightGroup = '\0';
  }
  uVar4 = 0;
LAB_800368cc:
  LIGHT_SetAmbientInstance(instance,level);
  if (pLVar2->numLightGroups == 0) {
    pLVar3 = &default_lightgroup;
  }
  else {
    pLVar3 = pLVar2->lightGroupList + uVar4;
  }
  if ((int)instance->lightMatrix == 0) {
    if ((instance->flags & 1U) == 0) {
      RotMatrix((ushort *)&instance->rotation,&local_80);
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
 // line 717, offset 0x80036bc8
	/* begin block 1 */
		// Start line: 718
		// Start offset: 0x80036BC8
		// Variables:
	// 		struct SVECTOR face_orient; // stack offset -112
	// 		struct MATRIX rot; // stack offset -104
	// 		struct MATRIX scTransform; // stack offset -72
	// 		struct _Vector scale; // stack offset -40
	// 		struct _Instance *playerInstance; // $s0
	/* end block 1 */
	// End offset: 0x80036E8C
	// End Line: 791

	/* begin block 2 */
		// Start line: 1434
	/* end block 2 */
	// End Line: 1435

void LIGHT_DrawShadow(MATRIX *wcTransform,_Instance *instance,_PrimPool *primPool,ulong **ot)

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
  
  if ((int)(instance->position).z + -0x500 < (int)(instance->shadowPosition).z) {
    sVar1 = MATH3D_FastAtan2((int)(instance->wNormal).y,(int)(instance->wNormal).z);
    local_70 = -sVar1;
    iVar2 = (int)(instance->wNormal).x;
    x = MATH3D_FastSqrt0(0x1000000 - iVar2 * iVar2);
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
    uVar4 = getCopReg(2,0x4800);
    uVar5 = getCopReg(2,0x5000);
    uVar6 = getCopReg(2,0x5800);
    local_48 = (undefined2)uVar4;
    local_42 = (undefined2)uVar5;
    local_3c = (undefined2)uVar6;
    setCopReg(2,0x4800,(uint)local_66);
    setCopReg(2,0x5000,(uint)local_60);
    setCopReg(2,0x5800,(uint)local_5a);
    copFunction(2,0x49e012);
    uVar4 = getCopReg(2,0x4800);
    uVar5 = getCopReg(2,0x5000);
    uVar6 = getCopReg(2,0x5800);
    local_46 = (undefined2)uVar4;
    local_40 = (undefined2)uVar5;
    local_3a = (undefined2)uVar6;
    setCopReg(2,0x4800,(uint)local_64);
    setCopReg(2,0x5000,(uint)local_5e);
    setCopReg(2,0x5800,(uint)local_58);
    copFunction(2,0x49e012);
    uVar4 = getCopReg(2,0x4800);
    uVar5 = getCopReg(2,0x5000);
    uVar6 = getCopReg(2,0x5800);
    local_44 = (undefined2)uVar4;
    local_3e = (undefined2)uVar5;
    local_38 = (undefined2)uVar6;
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
    puVar3 = DRAW_DrawShadow(primPool,(_Model *)0x0,ot,(int)instance->fadeValue);
    primPool->nextPrim = puVar3;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_CalcShadowPositions(struct GameTracker *gameTracker /*$a0*/)
 // line 793, offset 0x80036eac
	/* begin block 1 */
		// Start line: 794
		// Start offset: 0x80036EAC
		// Variables:
	// 		struct _InstanceList *instanceList; // $v0
	// 		struct _Instance *instance; // $s0
	// 		struct _PCollideInfo pcollideInfo; // stack offset -72
	// 		struct _Position newPos; // stack offset -24
	// 		struct _Position oldPos; // stack offset -16
	// 		struct Level *level; // $v0
	/* end block 1 */
	// End offset: 0x8003719C
	// End Line: 897

	/* begin block 2 */
		// Start line: 1701
	/* end block 2 */
	// End Line: 1702

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
  do {
    if (instance == (_Instance *)0x0) {
      return;
    }
    if ((instance->flags2 & 0x40U) == 0) {
LAB_80037158:
      if ((_Terrain *)instance->tfaceLevel != (_Terrain *)0x0) {
        tface = instance->tface;
        terrain = *(_Terrain **)(_Terrain *)instance->tfaceLevel;
LAB_80037170:
        LIGHT_CalcLightValue(tface,instance,terrain);
      }
    }
    else {
      uVar3 = instance->flags;
      if (((uVar3 & 0xa00) == 0x200) && ((instance->flags2 & 0x4000000U) == 0)) {
        if ((uVar3 & 0x18000000) == 0x8000000) {
          tface = instance->waterFace;
          if (tface == (_TFace *)0x0) goto LAB_80037158;
          terrain = instance->waterFaceTerrain;
          goto LAB_80037170;
        }
        if ((uVar3 & 0x10000000) == 0) {
          local_18 = *(undefined4 *)&instance->position;
          local_14 = (instance->position).z;
          local_10 = *(undefined4 *)&instance->position;
          local_c = (instance->position).z;
        }
        else {
          uVar1 = *(undefined2 *)instance->matrix[1].t;
          uVar2 = *(undefined2 *)(instance->matrix[1].t + 1);
          local_18 = CONCAT22(uVar2,uVar1);
          local_10 = CONCAT22(uVar2,uVar1);
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
        if (level == (Level *)0x0) {
          local_48.type = 0;
        }
        else {
          COLLIDE_PointAndWorld(&local_48,level);
        }
        instance->flags = instance->flags & 0xffffffbf;
        if (local_48.type == 3) {
          terrain = (_Terrain *)((local_48.inst)->node).prev;
          tface = local_48.prim;
LAB_80037044:
          LIGHT_CalcLightValue(tface,instance,terrain);
        }
        else {
          tface = (_TFace *)0x0;
          if (local_48.type != 5) {
            terrain = (_Terrain *)0x0;
            goto LAB_80037044;
          }
        }
        if (local_48.type != 0) {
          if (local_48.type == 1) {
            (instance->wNormal).x = 0;
            (instance->wNormal).y = 0;
            (instance->wNormal).z = 0x1000;
          }
          else {
            if (((local_48.type == 3) && ((local_48.prim)->textoff != 0xffff)) &&
               ((*(ushort *)
                  ((int)&((local_48.inst)->node).prev[6].next[1].prev +
                  (uint)(local_48.prim)->textoff + 2) & 0x4000) != 0)) {
              uVar3 = instance->flags | 0x200000;
            }
            else {
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
      else {
        if ((instance->flags2 & 0x40U) == 0) goto LAB_80037158;
      }
    }
    instance->flags = instance->flags & 0xf7ffffff;
    instance = instance->next;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_Restore(struct LightInfo *lightInfo /*$a0*/)
 // line 1348, offset 0x800371ac
	/* begin block 1 */
		// Start line: 2696
	/* end block 1 */
	// End Line: 2697

	/* begin block 2 */
		// Start line: 2372
	/* end block 2 */
	// End Line: 2373

void LIGHT_Restore(LightInfo *lightInfo)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIGHT_CalcDQPTable(struct Level *level /*$a3*/)
 // line 1586, offset 0x800371b4
	/* begin block 1 */
		// Start line: 1587
		// Start offset: 0x800371B4
		// Variables:
	// 		long dqa; // $a1
	// 		long limit; // $t0

		/* begin block 1.1 */
			// Start line: 1600
			// Start offset: 0x800371FC
		/* end block 1.1 */
		// End offset: 0x80037224
		// End Line: 1607

		/* begin block 1.2 */
			// Start line: 1610
			// Start offset: 0x80037234
		/* end block 1.2 */
		// End offset: 0x80037268
		// End Line: 1617
	/* end block 1 */
	// End offset: 0x800372C0
	// End Line: 1647

	/* begin block 2 */
		// Start line: 3172
	/* end block 2 */
	// End Line: 3173

void LIGHT_CalcDQPTable(Level *level)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  undefined *puVar5;
  
  uVar3 = (uint)level->fogFar;
  uVar2 = (uint)level->fogNear;
  if (uVar3 != uVar2) {
    puVar5 = (undefined *)-((int)(uVar3 * uVar2) / (int)(uVar3 - uVar2));
    if (0x9ffe < (int)puVar5) {
      puVar5 = &DAT_00009ffe;
      uVar4 = (ushort)((int)(uVar3 * 0x9ffe) / (int)(&DAT_00009ffe + -uVar3));
      if ((uint)level->holdFogNear == uVar2) {
        level->holdFogNear = uVar4;
      }
      level->fogNear = uVar4;
    }
    if ((int)puVar5 < -0x9ffe) {
      uVar4 = (ushort)((int)((uint)level->fogFar * -0x9ffe) / (int)(-0x9ffe - (uint)level->fogFar));
      if (level->holdFogNear == level->fogNear) {
        level->holdFogNear = uVar4;
      }
      level->fogNear = uVar4;
      puVar5 = (undefined *)0xffff6002;
    }
    depthQFogStart =
         ((int)puVar5 * -0x1000) /
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





