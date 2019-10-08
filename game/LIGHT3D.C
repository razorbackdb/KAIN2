*
#include "LIGHT3D.H"

#include <TYPES.H>

    void
    LIGHT_GetLightMatrix(_Instance *instance, Level *level, MATRIX *lightM, MATRIX *colorM)

{
  u_short uVar1;
  LightGroup *pLVar2;
  LightGroup *pLVar3;
  int iVar4;
  u_short *puVar5;
  LightList *in_v1;
  short *psVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  u_int uVar10;
  int iVar11;
  LightList *in_t3;

  uVar10 = (u_int)instance->lightGroup;
  if (gameTrackerX.gameData.asmData.MorphType == 0)
  {
    if ((instance != gameTrackerX.playerInstance) ||
        (pLVar2 = level->razielLightGroup, pLVar2 == (LightGroup *)0x0))
    {
    LAB_800353f4:
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
        goto LAB_800353f4;
      uVar10 = (u_int)instance->spectralLightGroup;
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
  uVar10 = (u_int)instance->lightGroup;
  if (gameTrackerX.gameData.asmData.MorphType == 0)
  {
    if ((instance == gameTrackerX.playerInstance) &&
        (pLVar3 = level->razielSpectralLightGroup, pLVar3 != (LightGroup *)0x0))
      goto LAB_800354cc;
    in_t3 = level->spectrallightList;
    if ((in_t3 != (LightList *)0x0) && (in_t3->numLightGroups != 0))
    {
      uVar10 = (u_int)instance->spectralLightGroup;
      pLVar3 = (LightGroup *)0x0;
      goto LAB_800354cc;
    }
  }
  else
  {
    if ((instance == gameTrackerX.playerInstance) &&
        (pLVar3 = level->razielLightGroup, pLVar3 != (LightGroup *)0x0))
      goto LAB_800354cc;
  }
  in_t3 = level->lightList;
  pLVar3 = (LightGroup *)0x0;
LAB_800354cc:
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
      puVar5 = (u_short *)((int)(pLVar2->colorMatrix).m + iVar7);
      uVar1 = *(u_short *)((int)(pLVar3->colorMatrix).m + iVar7);
      psVar6 = (short *)((int)colorM->m + iVar7);
      iVar7 = iVar7 + 2;
      iVar8 = iVar8 + 1;
      *psVar6 = uVar1 + (short)(((int)(((u_int)*puVar5 - (u_int)uVar1) * 0x10000) >> 0x10) *
 1000) >> 0xc);
    } while (iVar8 < 3);
    iVar11 = iVar11 + 1;
    iVar9 = iVar9 + 6;
  } while (iVar11 < 3);
  return;
}

void LIGHT_PresetInstanceLight(_Instance *instance, short attenuate, MATRIX *lm)

{
  short sVar1;
  Level *level;
  u_char *puVar2;
  int iVar3;
  short sVar4;
  u_int uVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  void *pvVar13;
  MATRIX local_50;
  int local_30[4];
  u_char local_20;
  undefined2 local_1c;

  pvVar13 = instance->extraLight;
  local_20 = 0x10001000;
  local_1c = 0x1000;
  level = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
  LIGHT_GetLightMatrix(instance, level, lm, &local_50);
  uVar5 = instance->flags & 0x200000;
  local_30[0] = 0x1000;
  if (uVar5 != 0)
  {
    local_30[0] = 0x800;
  }
  if ((int)attenuate != 0x1000)
  {
    local_30[0] = local_30[0] * (int)attenuate >> 0xc;
  }
  if ((instance->extraLight == (void *)0x0) || (uVar5 != 0))
  {
    local_30[1] = local_30[0];
    local_30[2] = local_30[0];
  }
  else
  {
    iVar7 = (0x1000 - (int)instance->extraLightScale) * local_30[0] >> 0xc;
    local_30[0] = iVar7 + ((int)((int)instance->extraLightScale * (u_int) * (byte *)((int)pvVar13 + 8)) >> 6);
    local_30[1] = iVar7 + ((int)((int)instance->extraLightScale * (u_int) * (byte *)((int)pvVar13 + 9)) >> 6);
    local_30[2] = iVar7 + ((int)((int)instance->extraLightScale * (u_int) * (byte *)((int)pvVar13 + 10)) >> 6);
  }
  puVar2 = (u_char *)&level->TODRedScale;
  if (level == (Level *)0x0)
  {
    puVar2 = &local_20;
  }
  iVar12 = 0;
  iVar7 = 0;
  piVar11 = local_30;
  do
  {
    sVar1 = *(short *)puVar2;
    iVar3 = *piVar11;
    iVar10 = 0;
    iVar9 = iVar7;
    do
    {
      psVar8 = (short *)((int)local_50.m + iVar9);
      iVar6 = (int)*psVar8 * (iVar3 * sVar1 * 0x10 >> 0x10) >> 0xc;
      sVar4 = (short)iVar6;
      if (iVar6 < -0x8000)
      {
        sVar4 = -0x8000;
      }
      if (0x7fff < iVar6)
      {
        sVar4 = 0x7fff;
      }
      *psVar8 = sVar4;
      iVar10 = iVar10 + 1;
      iVar9 = iVar9 + 2;
    } while (iVar10 < 3);
    iVar7 = iVar7 + 6;
    piVar11 = piVar11 + 1;
    iVar12 = iVar12 + 1;
    puVar2 = (u_char *)((int)puVar2 + 2);
  } while (iVar12 < 3);
  SetColorMatrix((u_char *)&local_50);
  return;
}

void LIGHT_GetAmbient(_ColorType *color, _Instance *instance)

{
  u_char uVar1;

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
  u_int uVar11;
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
  byte *local_2c;

  if ((((instance->flags & 0x400000U) != 0) || (tface == (_TFace *)0x0)) ||
      (instance->lightMatrix != 0))
  {
    LIGHT_GetAmbient(local_58, instance);
    iVar13 = 0x100;
    goto LAB_80035e48;
  }
  p_Var12 = terrain->vertexList;
  pBVar8 = terrain->BSPTreeArray + instance->bspTree;
  local_40[0] = (instance->position).x - (pBVar8->globalOffset).x;
  p_Var18 = p_Var12 + (tface->face).v0;
  p_Var17 = p_Var12 + (tface->face).v1;
  local_40[1] = (instance->position).y - (pBVar8->globalOffset).y;
  local_40[2] = (instance->shadowPosition).z - (pBVar8->globalOffset).z;
  p_Var12 = p_Var12 + (tface->face).v2;
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
  LAB_80035a9c:
    uVar11 = 1;
  LAB_80035aa0:
    iVar5 = iVar13 * 2;
    if ((local_40[iVar13] <= (&(p_Var17->vertex).x)[iVar13]) ||
        ((&(p_Var12->vertex).x)[iVar13] <= local_40[iVar13]))
      goto LAB_80035ad8;
  LAB_80035b0c:
    uVar11 = uVar11 | 2;
  LAB_80035b10:
    iVar6 = iVar13 * 2;
    if ((local_40[iVar13] <= (&(p_Var12->vertex).x)[iVar13]) ||
        ((&(p_Var18->vertex).x)[iVar13] <= local_40[iVar13]))
      goto LAB_80035b48;
  LAB_80035b7c:
    uVar11 = uVar11 | 4;
  }
  else
  {
    if (sVar2 <= sVar1)
      goto LAB_80035aa0;
    iVar5 = iVar13 << 1;
    if ((&(p_Var17->vertex).x)[iVar13] < sVar1)
      goto LAB_80035a9c;
  LAB_80035ad8:
    if (*(short *)((int)&(p_Var17->vertex).x + iVar5) <= *(short *)((int)local_40 + iVar5))
      goto LAB_80035b10;
    iVar6 = iVar13 << 1;
    if (*(short *)((int)&(p_Var12->vertex).x + iVar5) < *(short *)((int)local_40 + iVar5))
      goto LAB_80035b0c;
  LAB_80035b48:
    if ((*(short *)((int)local_40 + iVar6) < *(short *)((int)&(p_Var12->vertex).x + iVar6)) &&
        (*(short *)((int)&(p_Var18->vertex).x + iVar6) < *(short *)((int)local_40 + iVar6)))
      goto LAB_80035b7c;
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
  if (iVar6 == iVar5)
  {
    return;
  }
  local_30 = local_40;
  iVar7 = (iVar5 - local_40[iVar13]) * 0x1000;
  (iVar6 - iVar5);
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
  (iVar13 - iVar5);
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
  local_2c = abStack80;
  LoadAverageCol(&p_Var18->r0, &p_Var17->r0, 0x1000 - iVar16, iVar16, local_2c);
  LoadAverageCol(&p_Var18->r0, &p_Var12->r0, 0x1000 - iVar13, iVar13, abStack72);
  iVar5 = (int)(&(p_Var18->vertex).x)[iVar19];
  iVar16 = ((&(p_Var17->vertex).x)[iVar19] - iVar5) * iVar16;
  if (iVar16 < 0)
  {
    iVar16 = iVar16 + 0xfff;
  }
  iVar13 = ((&(p_Var12->vertex).x)[iVar19] - iVar5) * iVar13;
  iVar6 = iVar5 + (iVar16 >> 0xc);
  if (iVar13 < 0)
  {
    iVar13 = iVar13 + 0xfff;
  }
  iVar5 = iVar5 + (iVar13 >> 0xc);
  if (iVar6 == iVar5)
  {
    return;
  }
  (iVar6 - iVar5);
  if (iVar13 < 0)
  {
    iVar13 = -iVar13;
  }
  iVar19 = iVar13;
  if (iVar13 < 0)
  {
    iVar19 = 0;
  }
  if (0x1000 < iVar13)
  {
    iVar19 = 0x1000;
  }
  LoadAverageCol(local_2c, abStack72, 0x1000 - iVar19, iVar19, (undefined *)local_58);
  uVar11 = (int)((u_int)local_58[0].r * 0x4c8 + (u_int)local_58[0].g * 0x964 +
                 (u_int)local_58[0].b * 0x1d3) >>
           0xc;
  local_58[0].r = (byte)uVar11;
  iVar13 = 0x400;
  local_58[0].g = local_58[0].r;
  local_58[0].b = local_58[0].r;
  if (0x44 < uVar11)
  {
 2) + 0x44;
 local_58[0].g = local_58[0].r;
 local_58[0].b = local_58[0].r;
  }
LAB_80035e48:
  pLVar15 = (LightInstance *)0x0;
  iVar19 = 0x7fff;
  pLVar14 = gameTrackerX.gameData.asmData.lightInstances;
  iVar5 = 0;
  do
  {
    p_Var9 = pLVar14->lightInstance;
    if (((p_Var9 != (_Instance *)0x0) && (p_Var9 != instance)) && (p_Var9->matrix != (MATRIX *)0x0))
    {
      pMVar10 = p_Var9->matrix + pLVar14->segment;
      iVar6 = (int)(((u_int) * (u_short *)pMVar10->t - (u_int)(u_short)(instance->position).x) * 0x10000) >> 0x10;
      if (iVar6 < 0)
      {
        iVar6 = -iVar6;
      }
      local_40[0] = (short)iVar6;
      iVar7 = (int)(((u_int) * (u_short *)(pMVar10->t + 1) - (u_int)(u_short)(instance->position).y) *
                    0x10000) >>
              0x10;
      if (iVar7 < 0)
      {
        iVar7 = -iVar7;
      }
      local_40[1] = (short)iVar7;
      iVar16 = (int)(((u_int) * (u_short *)(pMVar10->t + 2) - (u_int)(u_short)(instance->position).z) *
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
      if ((iVar6 < pLVar14->radius) && (iVar6 < iVar19))
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
    iVar19 = pLVar15->radius - iVar19;
    iVar5 = (u_int)local_58[0].r + (iVar19 * pLVar15->r >> 0xc);
    local_58[0].r = (byte)iVar5;
    if (iVar5 < 0)
    {
      local_58[0].r = 0;
    }
    if (0xff < iVar5)
    {
      local_58[0].r = 0xff;
    }
    iVar5 = (u_int)local_58[0].g + (iVar19 * pLVar15->g >> 0xc);
    local_58[0].g = (byte)iVar5;
    if (iVar5 < 0)
    {
      local_58[0].g = 0;
    }
    if (0xff < iVar5)
    {
      local_58[0].g = 0xff;
    }
    iVar19 = (u_int)local_58[0].b + (iVar19 * pLVar15->b >> 0xc);
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

void LIGHT_SetAmbientInstance(_Instance *instance, Level *level)

{
  SetBackColor((u_int) * (byte *)&instance->light_color,
               (u_int) * (byte *)((int)&instance->light_color + 1),
               (u_int) * (byte *)((int)&instance->light_color + 2));
  return;
}

void LIGHT_SetMatrixForLightGroupInstance(_Instance *instance, Level *level)

{
  MATRIX *pMVar1;
  LightList *pLVar2;
  LightGroup *pLVar3;
  u_int uVar4;
  u_int local_80;
  u_char local_7c;
  u_char local_78;
  u_char local_74;
  u_char local_70;
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
  u_char local_3c;
  u_char local_38;
  u_char local_34;
  u_int local_30;
  u_char local_20;
  u_char local_1c;
  u_char local_18;
  u_char local_14;

  local_20 = 0x800;
  local_1c = 0x800;
  local_18 = 0x800;
  local_14 = 0;
  uVar4 = (u_int)instance->lightGroup;
  if (instance->matrix == (MATRIX *)0x0)
  {
    return;
  }
  if (((gameTrackerX.gameData.asmData.MorphType == 0) ||
       (pLVar2 = level->spectrallightList, pLVar2 == (LightList *)0x0)) ||
      (pLVar2->numLightGroups == 0))
  {
    pLVar2 = level->lightList;
    if ((pLVar2 == (LightList *)0x0) || ((int)uVar4 <= pLVar2->numLightGroups))
      goto LAB_8003617c;
    instance->lightGroup = '\0';
  }
  else
  {
    uVar4 = (u_int)instance->spectralLightGroup;
    if ((int)uVar4 <= pLVar2->numLightGroups)
      goto LAB_8003617c;
    instance->spectralLightGroup = '\0';
  }
  uVar4 = 0;
LAB_8003617c:
  LIGHT_SetAmbientInstance(instance, level);
  if (pLVar2->numLightGroups == 0)
  {
    pLVar3 = &default_lightgroup;
  }
  else
  {
    pLVar3 = pLVar2->lightGroupList + uVar4;
  }
  if ((int)instance->lightMatrix == 0)
  {
    if ((instance->flags & 1U) == 0)
    {
      RotMatrixY((u_short *)&instance->rotation, &local_80);
    }
    else
    {
      pMVar1 = instance->matrix;
      local_80 = *(u_int *)pMVar1->m;
      local_7c = *(u_char *)(pMVar1->m + 2);
      local_78 = *(u_char *)(pMVar1->m + 4);
      local_74 = *(u_char *)(pMVar1->m + 6);
      local_70 = *(u_char *)(pMVar1->m + 8);
      local_6c = pMVar1->t[0];
      local_68 = pMVar1->t[1];
      local_64 = pMVar1->t[2];
    }
  }
  else
  {
    pMVar1 = instance->matrix + (int)instance->lightMatrix;
    local_80 = *(u_int *)pMVar1->m;
    local_7c = *(u_char *)(pMVar1->m + 2);
    local_78 = *(u_char *)(pMVar1->m + 4);
    local_74 = *(u_char *)(pMVar1->m + 6);
    local_70 = *(u_char *)(pMVar1->m + 8);
    local_6c = pMVar1->t[0];
    local_68 = pMVar1->t[1];
    local_64 = pMVar1->t[2];
  }
  if (instance->extraLight == (void *)0x0)
  {
    PopMatrix((u_char *)pLVar3, (u_short *)&local_80, &local_80);
    SetLightMatrix(&local_80);
    if ((instance->flags & 0x200000U) == 0)
    {
      pMVar1 = &pLVar3->colorMatrix;
    }
    else
    {
      local_40 = *(int *)(pLVar3->colorMatrix).m;
      local_3c = *(u_char *)((pLVar3->colorMatrix).m + 2);
      local_38 = *(u_char *)((pLVar3->colorMatrix).m + 4);
      local_34 = *(u_char *)((pLVar3->colorMatrix).m + 6);
      local_30 = *(u_int *)((pLVar3->colorMatrix).m + 8);
      pMVar1 = (MATRIX *)&local_40;
      ScaleMatrix((int *)pMVar1, &local_20);
    }
  }
  else
  {
    local_60 = (pLVar3->lightMatrix).m[0];
    local_5e = (pLVar3->lightMatrix).m[1];
    local_5c = (pLVar3->lightMatrix).m[2];
    local_5a = (pLVar3->lightMatrix).m[3];
    local_58 = (pLVar3->lightMatrix).m[4];
    local_56 = (pLVar3->lightMatrix).m[5];
    local_54 = (undefined2)((int)(instance->extraLightDir).x * (int)instance->extraLightScale >> 0xc);
    local_52 = (undefined2)((int)(instance->extraLightDir).y * (int)instance->extraLightScale >> 0xc);
    local_50 = (undefined2)((int)(instance->extraLightDir).z * (int)instance->extraLightScale >> 0xc);
    local_40 = *(int *)(pLVar3->colorMatrix).m;
    local_34 = *(u_char *)((pLVar3->colorMatrix).m + 6);
    local_3c = CONCAT22((pLVar3->colorMatrix).m[3],
                        (u_short) * (byte *)((int)instance->extraLight + 8) << 4);
    local_38 = CONCAT22((u_short) * (byte *)((int)instance->extraLight + 9) << 4,
                        (pLVar3->colorMatrix).m[4]);
    local_30 = local_30 & 0xffff0000 | (u_int) * (byte *)((int)instance->extraLight + 10) << 4;
    PopMatrix((u_char *)&local_60, (u_short *)&local_80, &local_80);
    SetLightMatrix(&local_80);
    if ((instance->flags & 0x200000U) != 0)
    {
      ScaleMatrix((int *)&local_40, &local_20);
    }
    pMVar1 = (MATRIX *)&local_40;
  }
  SetColorMatrix((u_char *)pMVar1);
  return;
}

void LIGHT_DrawShadow(MATRIX *wcTransform, _Instance *instance, _PrimPool *primPool, u_long **ot)

{
  u_char in_at;
  short sVar1;
  int iVar2;
  long x;
  u_long *puVar3;
  u_char uVar4;
  u_char uVar5;
  u_char uVar6;
  u_short local_70;
  short local_6e;
  short local_6c;
  u_short local_68;
  u_short local_66;
  u_short local_64;
  u_short local_62;
  u_short local_60;
  u_short local_5e;
  u_short local_5c;
  u_short local_5a;
  u_short local_58;
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
  u_char local_34;
  u_char local_30;
  u_char local_2c;
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
    RotMatrixY(&local_70, (u_int *)&local_68);
    local_54 = (int)(instance->shadowPosition).x;
    local_50 = (int)(instance->shadowPosition).y;
    local_4c = (int)(instance->shadowPosition).z;
    setCopControlWord(2, 0, *(u_char *)wcTransform->m);
    setCopControlWord(2, 0x800, *(u_char *)(wcTransform->m + 2));
    setCopControlWord(2, 0x1000, *(u_char *)(wcTransform->m + 4));
    setCopControlWord(2, 0x1800, *(u_char *)(wcTransform->m + 6));
    setCopControlWord(2, 0x2000, *(u_char *)(wcTransform->m + 8));
    setCopReg(2, 0x4800, (u_int)local_68);
    setCopReg(2, 0x5000, (u_int)local_62);
    setCopReg(2, 0x5800, (u_int)local_5c);
    copFunction(2, 0x49e012);
    uVar4 = getCopReg(2, 0x4800);
    uVar5 = getCopReg(2, 0x5000);
    uVar6 = getCopReg(2, 0x5800);
    local_48 = (undefined2)uVar4;
    local_42 = (undefined2)uVar5;
    local_3c = (undefined2)uVar6;
    setCopReg(2, 0x4800, (u_int)local_66);
    setCopReg(2, 0x5000, (u_int)local_60);
    setCopReg(2, 0x5800, (u_int)local_5a);
    copFunction(2, 0x49e012);
    uVar4 = getCopReg(2, 0x4800);
    uVar5 = getCopReg(2, 0x5000);
    uVar6 = getCopReg(2, 0x5800);
    local_46 = (undefined2)uVar4;
    local_40 = (undefined2)uVar5;
    local_3a = (undefined2)uVar6;
    setCopReg(2, 0x4800, (u_int)local_64);
    setCopReg(2, 0x5000, (u_int)local_5e);
    setCopReg(2, 0x5800, (u_int)local_58);
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
    setCopReg(2, 0, *(u_char *)&instance->shadowPosition);
    setCopReg(2, in_at, local_4c);
    copFunction(2, 0x480012);
    local_34 = getCopReg(2, 0x19);
    local_30 = getCopReg(2, 0x1a);
    local_2c = getCopReg(2, 0x1b);
 0x1e0)
               * (0x1000 - (((int)(instance->position).z - (int)(instance->shadowPosition).z) *
 0x500) >> 0xc;
    local_24 = local_28;
    local_20 = local_28;
    ScaleMatrix((int *)&local_48,&local_28);
    SetRotMatrix((u_char *)&local_48);
    TransMatrix((int)&local_48);
    puVar3 = DRAW_DrawShadow(primPool,(_Model *)0x0,ot,(int)instance->fadeValue);
    primPool->nextPrim = puVar3;
  }
  return;
}

void LIGHT_CalcShadowPositions(GameTracker *gameTracker)

{
  undefined2 uVar1;
  undefined2 uVar2;
  Level *level;
  u_int uVar3;
  _TFace *tface;
  _Terrain *terrain;
  _Instance *instance;
  _PCollideInfo local_48;
  u_char local_18;
  short local_14;
  u_char local_10;
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
    LAB_80036a0c:
      if ((_Terrain *)instance->tfaceLevel != (_Terrain *)0x0)
      {
        tface = instance->tface;
        terrain = *(_Terrain **)(_Terrain *)instance->tfaceLevel;
      LAB_80036a24:
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
            goto LAB_80036a0c;
          terrain = instance->waterFaceTerrain;
          goto LAB_80036a24;
        }
        if ((uVar3 & 0x10000000) == 0)
        {
          local_18 = *(u_char *)&instance->position;
          local_14 = (instance->position).z;
          local_10 = *(u_char *)&instance->position;
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
        level = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
        if (level == (Level *)0x0)
        {
          local_48.type = 0;
        }
        else
        {
          COLLIDE_PointAndTerrain(&local_48, level);
        }
        instance->flags = instance->flags & 0xffffffbf;
        if (local_48.type == 3)
        {
          terrain = (_Terrain *)((local_48.inst)->node).prev;
          tface = local_48.prim;
        LAB_800368f8:
          LIGHT_CalcLightValue(tface, instance, terrain);
        }
        else
        {
          tface = (_TFace *)0x0;
          if (local_48.type != 5)
          {
            terrain = (_Terrain *)0x0;
            goto LAB_800368f8;
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
                ((*(u_short *)((int)&((local_48.inst)->node).prev[6].next[1].prev +
                               (u_int)(local_48.prim)->textoff + 2) &
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
        *(u_char *)&instance->shadowPosition = local_18;
        (instance->shadowPosition).z = local_14;
      }
      else
      {
        if ((instance->flags2 & 0x40U) == 0)
          goto LAB_80036a0c;
      }
    }
    instance->flags = instance->flags & 0xf7ffffff;
    instance = instance->next;
  } while (true);
}

void LIGHT_ActivateSources(LightInfo *lightInfo)

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
  while (node < (PointLight *)&lightInfo->usedPointLightList)
  {
    LIST_GetFunc(&lightInfo->freePointLightList, (NodeType *)node);
    node = node + 1;
  }
  node_00 = lightInfo->spotLightPool;
  (lightInfo->usedSpotLightList).next = (NodeType *)0x0;
  (lightInfo->usedSpotLightList).prev = (NodeType *)0x0;
  (lightInfo->freeSpotLightList).next = (NodeType *)0x0;
  (lightInfo->freeSpotLightList).prev = (NodeType *)0x0;
  (lightInfo->activeSpotLightList).next = (NodeType *)0x0;
  (lightInfo->activeSpotLightList).prev = (NodeType *)0x0;
  while (node_00 < (SpotLight *)&lightInfo->usedSpotLightList)
  {
    LIST_GetFunc(&lightInfo->freeSpotLightList, (NodeType *)node_00);
    node_00 = node_00 + 1;
  }
  lightInfo->numSavedColors = 0;
  return;
}

void LIGHT_Restore(LightInfo *lightInfo)

{
  return;
}

void LIGHT_SourcesAndTerrain(LightInfo *lightInfo, _Terrain *terrain)

{
  return;
}

void LIGHT_ActivateSources(_CameraCore_Type *cameraCore, Level *level, NodeType *activeLightList,
                           NodeType *usedLightList)

{
  byte bVar1;
  NodeType *node;
  int iVar2;
  NodeType *pNVar3;
  NodeType NStack32;

  memset(&NStack32, 0, 8);
  pNVar3 = activeLightList->next;
  while (node = pNVar3, node != (NodeType *)0x0)
  {
    pNVar3 = node->next;
    iVar2 = BSP_SphereIntersectsViewVolume_S(&node[1].next, cameraCore);
    if (iVar2 == 0)
    {
      LIST_DeleteFunc(node);
      bVar1 = *(byte *)((int)&node[1].prev + 3);
      *(byte *)((int)&node[1].prev + 3) = bVar1 & 0xef;
      if ((bVar1 & 0x20) != 0)
      {
        LIST_GetFunc(&NStack32, node);
      }
    }
  }
  pNVar3 = usedLightList->next;
  while (node = pNVar3, node != (NodeType *)0x0)
  {
    pNVar3 = node->next;
    if (((*(byte *)((int)&node[1].prev + 3) & 0x20) != 0) &&
        (iVar2 = BSP_SphereIntersectsViewVolume_S(&node[1].next, cameraCore), iVar2 != 0))
    {
      LIST_DeleteFunc(node);
      LIST_GetFunc(activeLightList, node);
      *(byte *)((int)&node[1].prev + 3) = *(byte *)((int)&node[1].prev + 3) | 0x10;
    }
  }
  LIST_Concatenate(usedLightList, &NStack32);
  return;
}

void LIGHT_RelocateLights(Level *oldLevel, long sizeOfLevel, long offset, NodeType *currentLightList)

{
  NodeType *pNVar1;
  NodeType *pNVar2;
  Level *pLVar3;
  Level *pLVar4;

  pLVar3 = (Level *)currentLightList->next;
  if ((oldLevel <= pLVar3) && (pLVar3 <= (Level *)((int)&oldLevel->terrain + sizeOfLevel)))
  {
    pNVar1 = (NodeType *)0x0;
    if (pLVar3 != (Level *)0x0)
    {
      pNVar1 = (NodeType *)((int)&pLVar3->terrain + offset);
    }
    currentLightList->next = pNVar1;
  }
  pNVar1 = currentLightList->next;
  pLVar3 = (Level *)((int)&oldLevel->terrain + sizeOfLevel);
  while (pNVar1 != (NodeType *)0x0)
  {
    pLVar4 = (Level *)pNVar1->prev;
    if ((oldLevel <= pLVar4) && (pLVar4 <= pLVar3))
    {
      pNVar2 = (NodeType *)0x0;
      if (pLVar4 != (Level *)0x0)
      {
        pNVar2 = (NodeType *)((int)&pLVar4->terrain + offset);
      }
      pNVar1->prev = pNVar2;
    }
    pLVar4 = (Level *)pNVar1->next;
    if ((oldLevel <= pLVar4) && (pLVar4 <= pLVar3))
    {
      pNVar2 = (NodeType *)0x0;
      if (pLVar4 != (Level *)0x0)
      {
        pNVar2 = (NodeType *)((int)&pLVar4->terrain + offset);
      }
      pNVar1->next = pNVar2;
    }
    pNVar1 = pNVar1->next;
  }
  return;
}

void LIGHT_RelocatePointerInList(LightInfo *lightInfo, Level *oldLevel, long sizeOfLevel, long offset)

{
  LIGHT_RelocateLights(oldLevel, sizeOfLevel, offset, &lightInfo->activeSpotLightList);
  LIGHT_RelocateLights(oldLevel, sizeOfLevel, offset, &lightInfo->usedSpotLightList);
  LIGHT_RelocateLights(oldLevel, sizeOfLevel, offset, &lightInfo->activePointLightList);
  LIGHT_RelocateLights(oldLevel, sizeOfLevel, offset, &lightInfo->usedPointLightList);
  return;
}

void LIGHT_InitSources(_CameraCore_Type *cameraCore, Level *level, LightInfo *lightInfo)

{
  LIGHT_ActivateSources(cameraCore, level, &lightInfo->activeSpotLightList, &lightInfo->usedSpotLightList);
  LIGHT_ActivateSources(cameraCore, level, &lightInfo->activePointLightList, &lightInfo->usedPointLightList);
  return;
}

long LIGHT_CollideInstanceAndSphere(_Instance *instance, _Sphere *sphere)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;

  iVar1 = (int)(((u_int)(u_short)(sphere->position).x - (u_int)(u_short)(instance->position).x) *
                0x10000) >>
          0x10;
  iVar2 = (int)(((u_int)(u_short)(sphere->position).y - (u_int)(u_short)(instance->position).y) *
                0x10000) >>
          0x10;
  iVar3 = (int)(((u_int)(u_short)(sphere->position).z - (u_int)(u_short)(instance->position).z) *
                0x10000) >>
          0x10;
  iVar4 = (int)instance->object->modelList[instance->currentModel]->maxRad + (u_int)sphere->radius;
  return (u_int)(iVar1 * iVar1 + iVar2 * iVar2 + iVar3 * iVar3 < iVar4 * iVar4);
}

void LIGHT_SourcesAndInstances(LightInfo *lightInfo, _InstanceList *instanceList)

{
  long lVar1;
  short sVar2;
  int iVar3;
  NodeType *pNVar4;
  _Instance *instance;
  _Normal local_18;

  instance = instanceList->first;
  while (instance != (_Instance *)0x0)
  {
    instance->extraLight = (void *)0x0;
    pNVar4 = (lightInfo->activeSpotLightList).next;
    while (pNVar4 != (NodeType *)0x0)
    {
      lVar1 = LIGHT_CollideInstanceAndSphere(instance, (_Sphere *)&pNVar4[1].next);
      if (lVar1 != 0)
      {
        local_18.x = (instance->position).x - *(short *)&pNVar4[3].prev;
        local_18.y = (instance->position).y - *(short *)((int)&pNVar4[3].prev + 2);
        local_18.z = (instance->position).z - *(short *)&pNVar4[3].next;
        CAMERA_Initialize(&local_18);
        iVar3 = (int)local_18.x * (int)*(short *)((int)&pNVar4[3].next + 2) +
                    (int)local_18.y * (int)*(short *)&pNVar4[4].prev +
                    (int)local_18.z * (int)*(short *)((int)&pNVar4[4].prev + 2) >>
                0xc;
        if (*(short *)&pNVar4[4].next <= iVar3)
        {
          *(NodeType **)&instance->extraLight = pNVar4;
          (instance->extraLightDir).x = -local_18.x;
          (instance->extraLightDir).y = -local_18.y;
          (instance->extraLightDir).z = -local_18.z;
          iVar3 = (iVar3 - *(short *)&pNVar4[4].next) * (int)*(short *)((int)&pNVar4[4].next + 2);
          sVar2 = 0x1000;
          if (iVar3 < 0x1001)
          {
            sVar2 = (short)iVar3;
          }
          instance->extraLightScale = sVar2;
        }
      }
      pNVar4 = pNVar4->next;
    }
    pNVar4 = (lightInfo->activePointLightList).next;
    while (pNVar4 != (NodeType *)0x0)
    {
      lVar1 = LIGHT_CollideInstanceAndSphere(instance, (_Sphere *)&pNVar4[1].next);
      if (lVar1 != 0)
      {
        local_18.x = (instance->position).x - *(short *)&pNVar4[1].next;
        local_18.y = (instance->position).y - *(short *)((int)&pNVar4[1].next + 2);
        local_18.z = (instance->position).z - *(short *)&pNVar4[2].prev;
        CAMERA_Initialize(&local_18);
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

void LIGHT_CalcDQPTable(Level *level)

{
  long lVar1;
  u_int uVar2;
  u_int uVar3;
  u_short uVar4;
  undefined *puVar5;

  uVar3 = (u_int)level->fogFar;
  uVar2 = (u_int)level->fogNear;
  if (uVar3 != uVar2)
  {
 (int)(uVar3 - uVar2));
 if (0x9ffe < (int)puVar5)
 {
   puVar5 = &DAT_00009ffe;
 (int)(&DAT_00009ffe + -uVar3));
 if ((u_int)level->holdFogNear == uVar2)
 {
   level->holdFogNear = uVar4;
 }
 level->fogNear = uVar4;
 }
 if ((int)puVar5 < -0x9ffe)
 {
 (int)(-0x9ffe - (u_int)level->fogFar));
 if (level->holdFogNear == level->fogNear)
 {
   level->holdFogNear = uVar4;
 }
 level->fogNear = uVar4;
 puVar5 = (undefined *)0xffff6002;
 }
    depthQFogStart =

 (int)((u_int)level->fogFar - (u_int)level->fogNear));
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
