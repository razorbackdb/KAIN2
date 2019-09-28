#include "THISDUST.H"
#include "LIGHT3D.H"


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

void LIGHT_GetLightMatrix(_Instance *param_1,int param_2,undefined2 *param_3,undefined2 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int in_v1;
  short *psVar5;
  int iVar6;
  int iVar7;
  undefined2 *puVar8;
  uint uVar9;
  int iVar10;
  int in_t3;
  
  uVar9 = (uint)param_1->lightGroup;
  if (sGpffffb502 == 0) {
    if ((param_1 != p_Gpffffb524) || (iVar3 = *(int *)(param_2 + 0x180), iVar3 == 0)) {
LAB_800358a8:
      in_v1 = *(int *)(param_2 + 4);
      iVar3 = 0;
    }
  }
  else {
    if ((param_1 != p_Gpffffb524) || (iVar3 = *(int *)(param_2 + 0x184), iVar3 == 0)) {
      in_v1 = *(int *)(param_2 + 0x54);
      if ((in_v1 == 0) || (*(int *)(in_v1 + 4) == 0)) goto LAB_800358a8;
      uVar9 = (uint)param_1->spectralLightGroup;
      iVar3 = 0;
    }
  }
  if (iVar3 != 0) {
    INSTANCE_GetFadeValue(param_1);
    return;
  }
  if ((*(int *)(in_v1 + 4) == 0) || (*(int *)(in_v1 + 4) <= (int)uVar9)) {
    INSTANCE_GetFadeValue(param_1);
    return;
  }
  puVar8 = (undefined2 *)(*(int *)(in_v1 + 8) + uVar9 * 0x40);
  if (sGpffffb500 == 1000) {
    *param_3 = *puVar8;
    param_3[1] = puVar8[1];
    param_3[2] = puVar8[2];
    param_3[3] = puVar8[3];
    param_3[4] = puVar8[4];
    param_3[5] = puVar8[5];
    param_3[6] = puVar8[6];
    param_3[7] = puVar8[7];
    param_3[8] = puVar8[8];
    *param_4 = puVar8[0x10];
    param_4[1] = puVar8[0x11];
    param_4[2] = puVar8[0x12];
    param_4[3] = puVar8[0x13];
    param_4[4] = puVar8[0x14];
    param_4[5] = puVar8[0x15];
    param_4[6] = puVar8[0x16];
    param_4[7] = puVar8[0x17];
    param_4[8] = puVar8[0x18];
    return;
  }
  uVar9 = (uint)param_1->lightGroup;
  if (sGpffffb502 == 0) {
    if ((param_1 == p_Gpffffb524) &&
       (puVar4 = *(undefined **)(param_2 + 0x184), puVar4 != (undefined *)0x0)) goto LAB_8003597c;
    in_t3 = *(int *)(param_2 + 0x54);
    if ((in_t3 != 0) && (*(int *)(in_t3 + 4) != 0)) {
      uVar9 = (uint)param_1->spectralLightGroup;
      puVar4 = (undefined *)0x0;
      goto LAB_8003597c;
    }
  }
  else {
    if ((param_1 == p_Gpffffb524) &&
       (puVar4 = *(undefined **)(param_2 + 0x180), puVar4 != (undefined *)0x0)) goto LAB_8003597c;
  }
  in_t3 = *(int *)(param_2 + 4);
  puVar4 = (undefined *)0x0;
LAB_8003597c:
  if (puVar4 == (undefined *)0x0) {
    if ((*(int *)(in_t3 + 4) == 0) || (*(int *)(in_t3 + 4) <= (int)uVar9)) {
      puVar4 = &gp0xffff89ac;
    }
    else {
      puVar4 = (undefined *)(*(int *)(in_t3 + 8) + uVar9 * 0x40);
    }
  }
  *param_3 = *puVar8;
  param_3[1] = puVar8[1];
  param_3[2] = puVar8[2];
  param_3[3] = puVar8[3];
  param_3[4] = puVar8[4];
  param_3[5] = puVar8[5];
  param_3[6] = puVar8[6];
  param_3[7] = puVar8[7];
  param_3[8] = puVar8[8];
  iVar10 = 0;
  iVar3 = 0;
  do {
    iVar7 = 0;
    iVar6 = iVar3;
    do {
      iVar2 = iVar6 + 0x20;
      iVar1 = iVar6 + 0x20;
      psVar5 = (short *)((int)param_4 + iVar6);
      iVar6 = iVar6 + 2;
      iVar7 = iVar7 + 1;
      *psVar5 = *(ushort *)(puVar4 + iVar1) +
                (short)(((int)(((uint)*(ushort *)((int)puVar8 + iVar2) -
                               (uint)*(ushort *)(puVar4 + iVar1)) * 0x10000) >> 0x10) *
                        (0x1000 - ((int)sGpffffb500 << 0xc) / 1000) >> 0xc);
    } while (iVar7 < 3);
    iVar10 = iVar10 + 1;
    iVar3 = iVar3 + 6;
  } while (iVar10 < 3);
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

void LIGHT_PresetInstanceLight(_Instance *instance,short attenuate,MATRIX *lm)

{
                    /* WARNING: Subroutine does not return */
  STREAM_GetLevelWithID(instance->currentStreamUnitID);
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

/* WARNING: Removing unreachable block (ram,0x80036058) */

void LIGHT_CalcLightValue(_TFace *tface,_Instance *instance,_Terrain *terrain)

{
  short sVar1;
  short sVar2;
  _TVertex *p_Var3;
  long lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  _ColorType *color;
  int iVar8;
  BSPTree *pBVar9;
  _Instance *instance_00;
  MATRIX *pMVar10;
  uint uVar11;
  _TVertex *p_Var12;
  int iVar13;
  _Instance *p_Var14;
  _Instance **pp_Var15;
  _Instance **pp_Var16;
  _TVertex *p_Var17;
  _TVertex *p_Var18;
  _ColorType local_58 [2];
  undefined auStack80 [16];
  short local_40 [4];
  _SVector _Stack56;
  short *local_30;
  
  if ((((instance->flags & 0x400000U) != 0) || (tface == (_TFace *)0x0)) ||
     (instance->lightMatrix != 0)) {
    LIGHT_GetAmbient(local_58,instance);
    pp_Var16 = (_Instance **)0x0;
    iVar13 = 0x7fff;
    pp_Var15 = (_Instance **)theCamera.core.vvNormalWorVecMat[0].t;
    iVar6 = 0;
    do {
      instance_00 = *pp_Var15;
      if (((instance_00 != (_Instance *)0x0) && (instance_00 != instance)) &&
         (instance_00->matrix != (MATRIX *)0x0)) {
        pMVar10 = instance_00->matrix + *(byte *)((int)pp_Var15 + 0x12);
        iVar7 = (int)(((uint)*(ushort *)pMVar10->t - (uint)(ushort)(instance->position).x) * 0x10000
                     ) >> 0x10;
        if (iVar7 < 0) {
          iVar7 = -iVar7;
        }
        local_40[0] = (short)iVar7;
        iVar8 = (int)(((uint)*(ushort *)(pMVar10->t + 1) - (uint)(ushort)(instance->position).y) *
                     0x10000) >> 0x10;
        if (iVar8 < 0) {
          iVar8 = -iVar8;
        }
        local_40[1] = (short)iVar8;
        iVar5 = (int)(((uint)*(ushort *)(pMVar10->t + 2) - (uint)(ushort)(instance->position).z) *
                     0x10000) >> 0x10;
        if (iVar5 < 0) {
          iVar5 = -iVar5;
        }
        local_40[2] = (short)iVar5;
        if (iVar5 << 0x10 < iVar8 << 0x10) {
          iVar5 = iVar8;
        }
        sVar1 = (short)iVar5;
        if (iVar5 << 0x10 < iVar7 << 0x10) {
          sVar1 = local_40[0];
        }
        iVar7 = (int)sVar1;
        if ((iVar7 < *(short *)(pp_Var15 + 4)) && (iVar7 < iVar13)) {
          iVar13 = iVar7;
          pp_Var16 = pp_Var15;
        }
      }
      iVar6 = iVar6 + 1;
      pp_Var15 = pp_Var15 + 5;
    } while (iVar6 < 1);
    if (pp_Var16 != (_Instance **)0x0) {
      iVar13 = *(short *)(pp_Var16 + 4) - iVar13;
      iVar6 = (uint)local_58[0].r + (iVar13 * (int)pp_Var16[1] >> 0xc);
      local_58[0].r = (byte)iVar6;
      if (iVar6 < 0) {
        local_58[0].r = 0;
      }
      if (0xff < iVar6) {
        local_58[0].r = 0xff;
      }
      iVar6 = (uint)local_58[0].g + (iVar13 * (int)pp_Var16[2] >> 0xc);
      local_58[0].g = (byte)iVar6;
      if (iVar6 < 0) {
        local_58[0].g = 0;
      }
      if (0xff < iVar6) {
        local_58[0].g = 0xff;
      }
      iVar13 = (uint)local_58[0].b + (iVar13 * (int)pp_Var16[3] >> 0xc);
      local_58[0].b = (byte)iVar13;
      if (iVar13 < 0) {
        local_58[0].b = 0;
      }
      if (0xff < iVar13) {
        local_58[0].b = 0xff;
      }
    }
                    /* WARNING: Subroutine does not return */
    LoadAverageCol((byte *)local_58,(byte *)&instance->light_color,0x100,0xf00,
                   (undefined *)&instance->light_color);
  }
  p_Var12 = terrain->vertexList;
  pBVar9 = terrain->BSPTreeArray + instance->bspTree;
  local_40[0] = (instance->position).x - (pBVar9->globalOffset).x;
  p_Var18 = p_Var12 + (tface->face).v0;
  p_Var17 = p_Var12 + (tface->face).v1;
  local_40[1] = (instance->position).y - (pBVar9->globalOffset).y;
  local_40[2] = (instance->shadowPosition).z - (pBVar9->globalOffset).z;
  p_Var12 = p_Var12 + (tface->face).v2;
  lVar4 = COLLIDE_GetNormal(tface->normal,(short *)terrain->normalList,&_Stack56);
  iVar13 = lVar4 + 2;
  if (2 < iVar13) {
    iVar13 = lVar4 + -1;
  }
  sVar1 = local_40[iVar13];
  sVar2 = (&(p_Var18->vertex).x)[iVar13];
  uVar11 = 0;
  if ((sVar2 < sVar1) && (sVar1 < (&(p_Var17->vertex).x)[iVar13])) {
LAB_80035eb4:
    uVar11 = 1;
LAB_80035eb8:
    iVar6 = iVar13 * 2;
    if ((local_40[iVar13] <= (&(p_Var17->vertex).x)[iVar13]) ||
       ((&(p_Var12->vertex).x)[iVar13] <= local_40[iVar13])) goto LAB_80035ef0;
LAB_80035f24:
    uVar11 = uVar11 | 2;
LAB_80035f28:
    iVar7 = iVar13 * 2;
    if ((local_40[iVar13] <= (&(p_Var12->vertex).x)[iVar13]) ||
       ((&(p_Var18->vertex).x)[iVar13] <= local_40[iVar13])) goto LAB_80035f60;
  }
  else {
    if (sVar2 <= sVar1) goto LAB_80035eb8;
    iVar6 = iVar13 << 1;
    if ((&(p_Var17->vertex).x)[iVar13] < sVar1) goto LAB_80035eb4;
LAB_80035ef0:
    if (*(short *)((int)&(p_Var17->vertex).x + iVar6) <= *(short *)((int)local_40 + iVar6))
    goto LAB_80035f28;
    iVar7 = iVar13 << 1;
    if (*(short *)((int)&(p_Var12->vertex).x + iVar6) < *(short *)((int)local_40 + iVar6))
    goto LAB_80035f24;
LAB_80035f60:
    if ((*(short *)((int)&(p_Var12->vertex).x + iVar7) <= *(short *)((int)local_40 + iVar7)) ||
       (*(short *)((int)local_40 + iVar7) <= *(short *)((int)&(p_Var18->vertex).x + iVar7)))
    goto LAB_80035f9c;
  }
  uVar11 = uVar11 | 4;
LAB_80035f9c:
  if (uVar11 == 3) {
    iVar6 = 1;
  }
  else {
    if (uVar11 == 6) {
      iVar6 = 2;
    }
    else {
      iVar6 = 0;
      if (uVar11 != 5) {
        return;
      }
    }
  }
  iVar7 = 0;
  p_Var3 = p_Var18;
  if (iVar6 != 0) {
    do {
      p_Var18 = p_Var17;
      p_Var17 = p_Var12;
      p_Var12 = p_Var3;
      iVar7 = iVar7 + 1;
      p_Var3 = p_Var18;
    } while (iVar7 < iVar6);
  }
  p_Var14 = (_Instance *)(int)(&(p_Var17->vertex).x)[iVar13];
  instance_00 = (_Instance *)(int)(&(p_Var18->vertex).x)[iVar13];
  if (p_Var14 != instance_00) {
    local_30 = local_40;
    color = (_ColorType *)((int)((int)instance_00 - (int)local_40[iVar13]) * 0x1000);
    iVar6 = (int)color / (int)((int)p_Var14 - (int)instance_00);
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    if (-1 < iVar6) {
      LIGHT_GetAmbient(color,instance_00);
      return;
    }
    if ((_Instance *)(int)(&(p_Var12->vertex).x)[iVar13] != instance_00) {
                    /* WARNING: Subroutine does not return */
      LoadAverageCol(&p_Var18->r0,&p_Var17->r0,0x1000,0,auStack80);
    }
  }
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

void LIGHT_SetAmbientInstance(_Instance *instance,Level *level)

{
  SetBackColor((uint)*(byte *)&instance->light_color,
               (uint)*(byte *)((int)&instance->light_color + 1),
               (uint)*(byte *)((int)&instance->light_color + 2));
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

void LIGHT_SetMatrixForLightGroupInstance(_Instance *instance,Level *level)

{
  int iVar1;
  uint local_28 [8];
  
  if (instance->matrix != (MATRIX *)0x0) {
    if (((theCamera.core.vvNormalWorVecMat[0]._18_2_ == 0) ||
        (level->spectrallightList == (LightList *)0x0)) ||
       (iVar1 = level->spectrallightList->numLightGroups, iVar1 == 0)) {
      if ((level->lightList != (LightList *)0x0) &&
         (level->lightList->numLightGroups < (int)(uint)instance->lightGroup)) {
        instance->lightGroup = '\0';
      }
    }
    else {
      if (iVar1 < (int)(uint)instance->spectralLightGroup) {
        instance->spectralLightGroup = '\0';
      }
    }
    LIGHT_SetAmbientInstance(instance,level);
    if ((instance->lightMatrix == 0) && ((instance->flags & 1U) == 0)) {
                    /* WARNING: Subroutine does not return */
      RotMatrix((ushort *)&instance->rotation,local_28);
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

void LIGHT_DrawShadow(MATRIX *wcTransform,_Instance *instance,_PrimPool *primPool,ulong **ot)

{
  short sVar1;
  int iVar2;
  long x;
  ushort local_70;
  short local_6e;
  short local_6c;
  uint local_68 [20];
  
  if ((int)(instance->position).z + -0x500 < (int)(instance->shadowPosition).z) {
    sVar1 = MATH3D_FastAtan2((int)(instance->wNormal).y,(int)(instance->wNormal).z);
    local_70 = -sVar1;
    iVar2 = (int)(instance->wNormal).x;
    x = MATH3D_FastSqrt0(0x1000000 - iVar2 * iVar2);
    local_6e = MATH3D_FastAtan2((int)(instance->wNormal).x,x);
    local_6c = (instance->rotation).z;
                    /* WARNING: Subroutine does not return */
    RotMatrix(&local_70,local_68);
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
  _TFace *tface;
  _Terrain *terrain;
  _Instance *instance;
  
  instance = gameTracker->instanceList->first;
  do {
    if (instance == (_Instance *)0x0) {
      return;
    }
    if ((instance->flags2 & 0x40U) == 0) {
LAB_80036bd4:
      if ((_Terrain *)instance->tfaceLevel != (_Terrain *)0x0) {
        tface = instance->tface;
        terrain = *(_Terrain **)(_Terrain *)instance->tfaceLevel;
LAB_80036bec:
        LIGHT_CalcLightValue(tface,instance,terrain);
      }
    }
    else {
      if (((instance->flags & 0xa00U) == 0x200) && ((instance->flags2 & 0x4000000U) == 0)) {
        if ((instance->flags & 0x18000000U) != 0x8000000) {
                    /* WARNING: Subroutine does not return */
          instance->flags = instance->flags | 0x40;
          STREAM_GetLevelWithID(instance->currentStreamUnitID);
        }
        tface = instance->waterFace;
        if (tface == (_TFace *)0x0) goto LAB_80036bd4;
        terrain = instance->waterFaceTerrain;
        goto LAB_80036bec;
      }
      if ((instance->flags2 & 0x40U) == 0) goto LAB_80036bd4;
    }
    instance->flags = instance->flags & 0xf7ffffff;
    instance = instance->next;
  } while( true );
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





