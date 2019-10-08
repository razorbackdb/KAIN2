#include "THISDUST.H"
#include "FX.H"

void FX_Init(_FXTracker *fxTracker)

{
  _FX_MATRIX *p_Var1;
  _FXTracker *node;
  _FX_PRIM *node_00;

  (fxTracker->usedMatrixList).next = (NodeType *)0x0;
  (fxTracker->usedMatrixList).prev = (NodeType *)0x0;
  (fxTracker->freeMatrixList).next = (NodeType *)0x0;
  (fxTracker->freeMatrixList).prev = (NodeType *)0x0;
  (fxTracker->usedPrimList).next = (NodeType *)0x0;
  (fxTracker->usedPrimList).prev = (NodeType *)0x0;
  (fxTracker->usedPrimListSprite).next = (NodeType *)0x0;
  (fxTracker->usedPrimListSprite).prev = (NodeType *)0x0;
  (fxTracker->freePrimList).next = (NodeType *)0x0;
  (fxTracker->freePrimList).prev = (NodeType *)0x0;
  node = fxTracker;
  if (fxTracker < (_FXTracker *)&fxTracker->usedMatrixList)
  {
    do
    {
      LIST_GetFunc(&fxTracker->freeMatrixList, (NodeType *)node);
      p_Var1 = node->matrixPool;
      node = (_FXTracker *)(p_Var1 + 1);
    } while ((_FXTracker *)(p_Var1 + 1) < (_FXTracker *)&fxTracker->usedMatrixList);
  }
  node_00 = fxTracker->primPool;
  while (node_00 < (_FX_PRIM *)&fxTracker->usedPrimList)
  {
    LIST_GetFunc(&fxTracker->freePrimList, (NodeType *)node_00);
    node_00 = node_00 + 1;
  }
  FX_LastUsedPrim = (_FX_PRIM *)0x0;
  FX_ConstrictPositionPtr = &FX_ConstrictPosition;
  FX_Spiral_Init();
  snow_amount = 0;
  rain_amount = 0;
  FX_reaver_instance = (_Instance *)0x0;
  FX_Frames = 1;
  FX_TimeCount = 0;
  return;
}

void FX_Dot(_FX_PRIM *fxPrim, _FXTracker *fxTracker)

{
  if ((FX_LastUsedPrim == fxPrim) &&
      (FX_LastUsedPrim = (_FX_PRIM *)(fxPrim->node).prev,
       (FX_LastUsedPrim->node).prev == (NodeType *)0x0))
  {
    FX_LastUsedPrim = (_FX_PRIM *)0x0;
  }
  fxPrim->flags = fxPrim->flags | 0x10;
  LIST_DeleteFunc((NodeType *)fxPrim);
  LIST_GetFunc(&fxTracker->freePrimList, (NodeType *)fxPrim);
  return;
}

_FX_MATRIX *FX_GetMatrix(_FXTracker *fxTracker)

{
  _FX_MATRIX *node;

  node = (_FX_MATRIX *)LIST_InsertFunc(&fxTracker->freeMatrixList);
  if (node != (_FX_MATRIX *)0x0)
  {
    *(NodeType **)&node->flags = (NodeType *)0x1;
    LIST_GetFunc(&fxTracker->usedMatrixList, (NodeType *)node);
  }
  return node;
}

_FX_PRIM *FX_GetPrim(_FXTracker *fxTracker)

{
  NodeType *pNVar1;
  _FX_PRIM *p_Var2;
  _FX_PRIM *p_Var3;

  p_Var3 = (_FX_PRIM *)LIST_InsertFunc(&fxTracker->freePrimList);
  p_Var2 = FX_LastUsedPrim;
  if (p_Var3 == (_FX_PRIM *)0x0)
  {
    if (FX_LastUsedPrim != (_FX_PRIM *)0x0)
    {
      FX_LastUsedPrim = (_FX_PRIM *)(FX_LastUsedPrim->node).prev;
      pNVar1 = &FX_LastUsedPrim->node;
      (FX_LastUsedPrim->node).next = (NodeType *)0x0;
      p_Var3 = p_Var2;
      if (pNVar1->prev == (NodeType *)0x0)
      {
        FX_LastUsedPrim = (_FX_PRIM *)0x0;
      }
    }
    if (p_Var3 == (_FX_PRIM *)0x0)
    {
      return (_FX_PRIM *)0x0;
    }
  }
  p_Var3->process = (void *)0x0;
  p_Var3->flags = 0;
  p_Var3->matrix = (_FX_MATRIX *)0x0;
  return p_Var3;
}

_FXParticle *FX_GetParticle(_Instance *instance, short startSegment)

{
  _FXParticle *p_Var1;

  p_Var1 = (_FXParticle *)MEMPACK_Malloc(0x4c, '\r');
  if (p_Var1 != (_FXParticle *)0x0)
  {
    p_Var1->effectType = '\x01';
    *(code **)&p_Var1->continue_process = FX_ContinueParticle;
    p_Var1->type = '\0';
    p_Var1->instance = instance;
    p_Var1->startSegment = (char)startSegment;
    p_Var1->texture = (TextureMT3 *)0x0;
    p_Var1->fxprim_process = (void *)0x0;
    p_Var1->fxprim_modify_process = (void *)0x0;
    p_Var1->startScale = 0x1000;
    p_Var1->scaleSpeed = 0;
    (p_Var1->offset).z = 0;
    (p_Var1->offset).y = 0;
    (p_Var1->offset).x = 0;
    (p_Var1->acceleration).z = 0;
    (p_Var1->acceleration).y = 0;
    (p_Var1->acceleration).x = 0;
    p_Var1->flag_bits = 0;
    p_Var1->z_undulate = '\0';
  }
  return p_Var1;
}

void FX_AniTexSetup(_FX_PRIM *fxPrim, _MFace *mface, _Model *model, _FXTracker *fxTracker)

{
  AniTex *pAVar1;
  u_int uVar2;
  u_int uVar3;

  if ((mface->flags & 2) == 0)
  {
    fxPrim->flags = fxPrim->flags & 0xfffffffa;
    uVar2 = mface->color;
    uVar3 = 0x20000000;
  }
  else
  {
    fxPrim->flags = fxPrim->flags | 1;
    fxPrim->texture = (TextureMT3 *)mface->color;
    if (model->aniTextures != (AniTex *)0x0)
    {
      fxPrim->flags = fxPrim->flags | 4;
      (fxPrim->ani).texMem = fxPrim->texture;
      pAVar1 = model->aniTextures;
      (fxPrim->ani).curFrame = 0;
      (fxPrim->ani).aniTextures = pAVar1;
    }
    uVar2 = fxPrim->texture->color;
    uVar3 = 0x24000000;
  }
  fxPrim->color = uVar2 & 0x3ffffff | uVar3;
  return;
}

void FX_StandardProcess(_FX_PRIM *fxPrim, _FXTracker *fxTracker)

{
  FX_StandardFXPrimProcess(fxPrim, fxTracker);
  return;
}

void FX_ShatterProcess(_FX_PRIM *fxPrim, _FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  short sVar3;
  _FX_MATRIX *p_Var4;
  int iVar5;
  int iVar6;
  int iVar7;
  u_int auStack64[8];
  short local_20;
  short local_1e;
  short local_1c;
  u_short local_18;
  short local_16;
  short local_14;

  memset(&local_20, 0, 8);
  if (0 < fxPrim->timeToLive)
  {
    fxPrim->timeToLive = fxPrim->timeToLive + -1;
  }
  if (fxPrim->timeToLive == 0)
  {
    FX_Dot(fxPrim, fxTracker);
  }
  else
  {
    if ((fxPrim->flags & 2U) == 0)
    {
      iVar5 = (int)(short)gameTrackerX.timeMult;
      sVar1 = *(short *)((int)&fxPrim->duo + 8);
      sVar2 = *(short *)((int)&fxPrim->duo + 10);
      *(short *)&fxPrim->duo =
          *(short *)&fxPrim->duo + (short)(iVar5 * *(short *)((int)&fxPrim->duo + 6) >> 0xc);
      sVar3 = *(short *)&fxPrim->duo;
      *(short *)((int)&fxPrim->duo + 2) =
          *(short *)((int)&fxPrim->duo + 2) + (short)(iVar5 * sVar1 >> 0xc);
      sVar1 = *(short *)((int)&fxPrim->duo + 2);
      *(short *)((int)&fxPrim->duo + 4) =
          *(short *)((int)&fxPrim->duo + 4) + (short)(iVar5 * sVar2 >> 0xc);
      sVar2 = *(short *)((int)&fxPrim->duo + 4);
      (fxPrim->position).x = (fxPrim->position).x + (short)(iVar5 * sVar3 >> 0xc);
      (fxPrim->position).y = (fxPrim->position).y + (short)(iVar5 * sVar1 >> 0xc);
      iVar5 = (u_int)(u_short)(fxPrim->position).z + (iVar5 * sVar2 >> 0xc);
      (fxPrim->position).z = (short)iVar5;
      if (iVar5 * 0x10000 >> 0x10 < (int)fxPrim->work0)
      {
        fxPrim->timeToLive = 6;
        fxPrim->flags = fxPrim->flags | 2;
        (fxPrim->position).z = fxPrim->work0;
      }
      local_20 = fxPrim->work3;
      iVar5 = (int)local_20;
      if (iVar5 != 0)
      {
        p_Var4 = fxPrim->matrix;
        iVar7 = (int)local_1e;
        iVar6 = (int)local_1c;
        local_18 = (short)(iVar5 * (p_Var4->lwTransform).m[0] >> 0xc) +
                   (short)(iVar7 * (p_Var4->lwTransform).m[1] >> 0xc) +
                   (short)(iVar6 * (p_Var4->lwTransform).m[2] >> 0xc);
        p_Var4 = fxPrim->matrix;
        local_16 = (short)(iVar5 * (p_Var4->lwTransform).m[3] >> 0xc) +
                   (short)(iVar7 * (p_Var4->lwTransform).m[4] >> 0xc) +
                   (short)(iVar6 * (p_Var4->lwTransform).m[5] >> 0xc);
        p_Var4 = fxPrim->matrix;
        local_14 = (short)(iVar5 * (p_Var4->lwTransform).m[6] >> 0xc) +
                   (short)(iVar7 * (p_Var4->lwTransform).m[7] >> 0xc) +
                   (short)(iVar6 * (p_Var4->lwTransform).m[8] >> 0xc);
        RotMatrixY(&local_18, auStack64);
        MulMatrix2(auStack64, (u_int *)&fxPrim->matrix->lwTransform);
      }
    }
  }
  return;
}

void FX_DFacadeProcess(_FX_PRIM *fxPrim, _FXTracker *fxTracker)

{
  char cVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  u_int uVar6;
  short sVar7;

  if (0 < fxPrim->timeToLive)
  {
    fxPrim->timeToLive = fxPrim->timeToLive + -1;
  }
  if (fxPrim->timeToLive == 0)
  {
    FX_Dot(fxPrim, fxTracker);
  }
  else
  {
    if ((fxPrim->flags & 0x20U) == 0)
    {
      if ((fxPrim->flags & 2U) == 0)
      {
        sVar3 = *(short *)((int)&fxPrim->duo + 8);
        sVar7 = *(short *)((int)&fxPrim->duo + 10);
        *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + *(short *)((int)&fxPrim->duo + 6);
        *(short *)((int)&fxPrim->duo + 2) = *(short *)((int)&fxPrim->duo + 2) + sVar3;
        sVar3 = (fxPrim->position).x;
        sVar4 = *(short *)&fxPrim->duo;
        *(short *)((int)&fxPrim->duo + 4) = *(short *)((int)&fxPrim->duo + 4) + sVar7;
        (fxPrim->position).y = (fxPrim->position).y + *(short *)((int)&fxPrim->duo + 2);
        sVar7 = *(short *)((int)&fxPrim->duo + 4);
        (fxPrim->position).x = sVar3 + sVar4;
        uVar6 = fxPrim->flags;
        sVar7 = (fxPrim->position).z + sVar7;
        (fxPrim->position).z = sVar7;
        if (((uVar6 & 0x100) != 0) && (sVar7 <= fxPrim->work0))
        {
          uVar6 = fxPrim->flags;
          (fxPrim->position).z = fxPrim->work0;
          fxPrim->flags = uVar6 | 2;
        }
      }
    }
    else
    {
      iVar5 = *(int *)(*(int *)&fxPrim->duo + 0x40) + *(int *)((int)&fxPrim->duo + 4) * 0x20;
      (fxPrim->position).x = *(short *)(iVar5 + 0x14);
      (fxPrim->position).y = *(short *)(iVar5 + 0x18);
      (fxPrim->position).z = *(short *)(iVar5 + 0x1c);
    }
    uVar6 = fxPrim->matrix->flags;
    if (((uVar6 & 2) == 0) && (fxPrim->matrix->flags = uVar6 | 2, (fxPrim->flags & 0x80U) != 0))
    {
      cVar1 = *(char *)&fxPrim->work3;
      cVar2 = *(char *)((int)&fxPrim->work3 + 1);
      RotMatrixZ((int)*(char *)((int)&fxPrim->work2 + 1) << 2, (int)&fxPrim->matrix->lwTransform);
      RotMatrix((int)(short)((int)cVar1 << 2), (u_int *)&fxPrim->matrix->lwTransform);
      RotMatrixX((int)(short)((int)cVar2 << 2), (u_int *)&fxPrim->matrix->lwTransform);
    }
  }
  return;
}

_FX_PRIM *
_FX_BuildSingleFaceWithModel(_Model *model, _MFace *mface, SVECTOR *center, SVECTOR *vel, SVECTOR *accl,
                             _FXTracker *fxTracker, TDRFuncPtr__FX_BuildSingleFaceWithModel6fxSetup fxSetup,
                             TDRFuncPtr__FX_BuildSingleFaceWithModel7fxProcess fxProcess, _FX_MATRIX *fxMatrix,
                             int timeToLive)

{
  _FX_PRIM *node;
  _MVertex *p_Var1;

  p_Var1 = model->vertexList;
  if ((fxMatrix == (_FX_MATRIX *)0x0) &&
      (fxMatrix = FX_GetMatrix(fxTracker), fxMatrix == (_FX_MATRIX *)0x0))
  {
    return (_FX_PRIM *)0x0;
  }
  node = FX_GetPrim(fxTracker);
  if (node != (_FX_PRIM *)0x0)
  {
    if (fxSetup != (TDRFuncPtr__FX_BuildSingleFaceWithModel6fxSetup)0x0)
    {
      (*fxSetup)(node, fxProcess, fxMatrix, 0, mface, p_Var1, center, vel, accl, fxTracker,
                 (int)(short)timeToLive);
    }
    LIST_GetFunc(&fxTracker->usedPrimList, (NodeType *)node);
  }
  return node;
}

_FX_PRIM *
FX_BuildSingleFaceWithModel(_Model *model, _MFace *mface, SVECTOR *center, SVECTOR *vel, SVECTOR *accl,
                            _FXTracker *fxTracker, TDRFuncPtr_FX_BuildSingleFaceWithModel6fxSetup fxSetup,
                            TDRFuncPtr_FX_BuildSingleFaceWithModel7fxProcess fxProcess, int timeToLive)

{
  _FX_PRIM *p_Var1;

  p_Var1 = _FX_BuildSingleFaceWithModel(model, mface, center, vel, accl, fxTracker,
                                        (TDRFuncPtr__FX_BuildSingleFaceWithModel6fxSetup)fxSetup,
                                        (TDRFuncPtr__FX_BuildSingleFaceWithModel7fxProcess)fxProcess, (_FX_MATRIX *)0x0, (int)(short)timeToLive);
  return p_Var1;
}

void _FX_SetupLighting(_Instance *instance)

{
  MATRIX MStack40;

  LIGHT_PresetInstanceLight(instance, 0x800, &MStack40);
  PopMatrix((u_char *)&MStack40, (u_short *)(instance->matrix + instance->lightMatrix),
            (u_int *)&MStack40);
  SetLightMatrix((u_char *)&MStack40);
  return;
}

long _FX_DoLighting(_MFace *mface)

{
  byte bVar1;
  u_char in_zero;
  u_char in_at;
  u_int uVar2;
  u_int uVar3;
  int iVar4;
  u_int local_8;

  bVar1 = mface->flags;
  if ((bVar1 & 2) == 0)
  {
    if ((bVar1 & 8) == 0)
    {
      setCopReg(2, in_zero, *(u_char *)(&gNormalList + mface->normal));
      setCopReg(2, in_at, *(u_char *)&(&gNormalList)[mface->normal].z);
      setCopReg(2, 0, mface->color);
      setCopReg(2, 0x4000, 0);
      copFunction(2, 0xe80413);
      local_8 = getCopReg(2, 0x16);
    }
    else
    {
      local_8 = mface->color;
    }
    uVar2 = local_8 & 0xffffff | 0x20000000;
    uVar3 = mface->color;
  }
  else
  {
    iVar4 = mface->color;
    if ((bVar1 & 8) == 0)
    {
      setCopReg(2, in_zero, *(u_char *)(&gNormalList + mface->normal));
      setCopReg(2, in_at, *(u_char *)&(&gNormalList)[mface->normal].z);
      setCopReg(2, 0, *(u_char *)(iVar4 + 0xc));
      setCopReg(2, 0x4000, 0);
      copFunction(2, 0xe80413);
      local_8 = getCopReg(2, 0x16);
    }
    else
    {
      local_8 = *(u_int *)(iVar4 + 0xc);
    }
    uVar2 = local_8 & 0xffffff | 0x24000000;
    uVar3 = *(u_int *)(iVar4 + 0xc);
  }
  return uVar2 | uVar3 & 0x3000000;
}

void _FX_BuildSegmentedSplinters(_Instance *instance, SVECTOR *center, SVECTOR *vel, SVECTOR *accl, FXSplinter *splintDef, _FXTracker *fxTracker, TDRFuncPtr__FX_BuildSegmentedSplinters6fxSetup fxSetup,
                                 TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess fxProcess, int shardFlags)

{
  u_short uVar1;
  u_short uVar2;
  short sVar3;
  short sVar4;
  _FX_MATRIX *p_Var5;
  int iVar6;
  int iVar7;
  _FX_PRIM *fxPrim;
  u_int uVar8;
  long lVar9;
  short sVar10;
  u_int uVar11;
  CVECTOR CVar12;
  _MFace *mface;
  int iVar13;
  _PVertex *p_Var14;
  int iVar15;
  _PVertex *p_Var16;
  _PVertex *p_Var17;
  _MFace *p_Var18;
  undefined2 *puVar19;
  int iVar20;
  byte bVar21;
  _FX_MATRIX *local_3c0[60];
  undefined auStack720[480];
  byte abStack240[128];
  short local_70[2];
  short local_6c;
  short local_68;
  _Normal local_60;
  u_short local_58;
  int local_50;
  int local_4c;
  _MFace *local_48;
  _Model *local_44;
  _MVertex *local_40;
  _VertexPool *local_3c;
  CVECTOR *local_38;
  undefined *local_34;
  _Normal *local_30;

  local_3c = gameTrackerX.vertexPool;
  local_38 = (gameTrackerX.vertexPool)->color;
  local_44 = instance->object->modelList[instance->currentModel];
  local_58 = (u_short)shardFlags;
  local_40 = local_44->vertexList;
  mface = local_44->faceList;
  PIPE3D_TransformVerticesToWorld(instance, (_SVector *)gameTrackerX.vertexPool, (long *)local_38, (_Vector *)local_70);
  if (splintDef == (FXSplinter *)0x0)
  {
    local_50 = 0x20;
  }
  else
  {
    local_50 = (int)splintDef->lifetime;
  }
  memset(abStack240, 0xff, 0x80);
  _FX_SetupLighting(instance);
  if (splintDef == (FXSplinter *)0x0)
  {
    local_4c = 1;
  }
  else
  {
    (int)splintDef->faceLimit + 1;
  }
  iVar20 = 0;
  local_48 = mface + local_44->numFaces;
  if (mface < mface + local_44->numFaces)
  {
    local_34 = auStack720;
    local_30 = &local_60;
    do
    {
      CVar12 = local_38[(mface->face).v2];
      if ((int)local_38[(mface->face).v1] < (int)local_38[(mface->face).v2])
      {
        CVar12 = local_38[(mface->face).v1];
      }
      if ((int)local_38[(mface->face).v0] < (int)CVar12)
      {
        CVar12 = local_38[(mface->face).v0];
      }
      if (abStack240[(int)CVar12] == 0xff)
      {
        if (iVar20 < 0x3c)
        {
          p_Var5 = FX_GetMatrix(fxTracker);
          if (p_Var5 == (_FX_MATRIX *)0x0)
          {
            if (iVar20 == 0)
            {
              return;
            }
            goto LAB_80043888;
          }
          local_3c0[iVar20] = p_Var5;
          bVar21 = (byte)iVar20;
          local_60.y = *(short *)(instance->matrix[(int)CVar12].t + 1);
          local_60.z = *(short *)(instance->matrix[(int)CVar12].t + 2);
          local_60.x = *(short *)instance->matrix[(int)CVar12].t - local_70[0];
          local_30->y = local_30->y - local_6c;
          local_30->z = local_30->z - local_68;
          CAMERA_Initialize(local_30);
          if (splintDef == (FXSplinter *)0x0)
          {
            iVar15 = rand();
            puVar19 = (undefined2 *)(local_34 + iVar20 * 8);
            iVar7 = iVar15;
            if (iVar15 < 0)
            {
              iVar7 = iVar15 + 7;
            }
            *puVar19 = (short)((int)local_60.x * (iVar15 + (iVar7 >> 3) * -8 + 0x1a) >> 0xc);
            iVar15 = rand();
            iVar7 = iVar15;
            if (iVar15 < 0)
            {
              iVar7 = iVar15 + 7;
            }
            puVar19[1] = (short)((int)local_60.y * (iVar15 + (iVar7 >> 3) * -8 + 0x1a) >> 0xc);
            iVar15 = rand();
            iVar7 = iVar15;
            if (iVar15 < 0)
            {
              iVar7 = iVar15 + 7;
            }
            puVar19[2] = (short)((int)local_60.z * (iVar15 + (iVar7 >> 3) * -8 + 0x2e) >> 0xc);
          }
          else
          {
            iVar7 = (u_int)(u_short)splintDef->chunkVelXY - (u_int)(u_short)splintDef->chunkVelRng;
            iVar15 = (int)((u_int)(u_short)splintDef->chunkVelRng << 0x11) >> 0x10;
            if (iVar15 == 0)
            {
              iVar7 = iVar7 * 0x10000 >> 0x10;
              puVar19 = (undefined2 *)(local_34 + iVar20 * 8);
              *puVar19 = (short)(local_60.x * iVar7 >> 0xc);
              puVar19[1] = (short)(local_60.y * iVar7 >> 0xc);
              puVar19[2] = (short)((int)local_60.z * (int)splintDef->chunkVelZ >> 0xc);
            }
            else
            {
              iVar6 = rand();
              iVar13 = iVar7 * 0x10000 >> 0x10;
              puVar19 = (undefined2 *)(local_34 + iVar20 * 8);
              *puVar19 = (short)((int)local_60.x * (iVar13 + iVar6 % iVar15) >> 0xc);
              iVar7 = rand();
              puVar19[1] = (short)((int)local_60.y * (iVar13 + iVar7 % iVar15) >> 0xc);
              uVar1 = splintDef->chunkVelZ;
              uVar2 = splintDef->chunkVelRng;
              iVar7 = rand();
              puVar19[2] = (short)((int)local_60.z *
                                       (((int)(((u_int)uVar1 - (u_int)uVar2) * 0x10000) >> 0x10) +
                                        iVar7 % iVar15) >>
                                   0xc);
            }
          }
          puVar19 = (undefined2 *)(local_34 + iVar20 * 8);
          if ((int)((u_int)(u_short)puVar19[2] << 0x10) < 0)
          {
            puVar19[2] = 0;
          }
          iVar20 = iVar20 + 1;
        }
        else
        {
        LAB_80043888:
          iVar7 = rand();
          iVar7 = iVar7 % iVar20;
          bVar21 = (byte)iVar7;
          p_Var5 = local_3c0[iVar7];
          puVar19 = (undefined2 *)(local_34 + iVar7 * 8);
        }
        abStack240[(int)CVar12] = bVar21;
      }
      else
      {
        uVar8 = (u_int)abStack240[(int)CVar12];
        puVar19 = (undefined2 *)(local_34 + uVar8 * 8);
        p_Var5 = local_3c0[uVar8];
      }
      (p_Var5->lwTransform).m[0] = 0x1000;
      (p_Var5->lwTransform).m[1] = 0;
      (p_Var5->lwTransform).m[2] = 0;
      (p_Var5->lwTransform).m[3] = 0;
      (p_Var5->lwTransform).m[4] = 0x1000;
      (p_Var5->lwTransform).m[5] = 0;
      (p_Var5->lwTransform).m[6] = 0;
      (p_Var5->lwTransform).m[7] = 0;
      (p_Var5->lwTransform).m[8] = 0x1000;
      (p_Var5->lwTransform).t[0] = instance->matrix[(int)CVar12].t[0];
      (p_Var5->lwTransform).t[1] = instance->matrix[(int)CVar12].t[1];
      (p_Var5->lwTransform).t[2] = instance->matrix[(int)CVar12].t[2];
      p_Var14 = local_3c->vertex + (mface->face).v0;
      p_Var16 = local_3c->vertex + (mface->face).v1;
      p_Var17 = local_3c->vertex + (mface->face).v2;
      fxPrim = FX_GetPrim(fxTracker);
      p_Var18 = local_48;
      if (fxPrim != (_FX_PRIM *)0x0)
      {
        if (fxSetup == (TDRFuncPtr__FX_BuildSegmentedSplinters6fxSetup)0x0)
        {
          (fxPrim->position).x = *(short *)(p_Var5->lwTransform).t;
          (fxPrim->position).y = *(short *)((p_Var5->lwTransform).t + 1);
          (fxPrim->position).z = *(short *)((p_Var5->lwTransform).t + 2);
          sVar4 = (fxPrim->position).z;
          local_60.x = (fxPrim->position).x - local_70[0];
          local_30->y = (fxPrim->position).y - local_6c;
          local_30->z = sVar4 - local_68;
          (fxPrim->v0).x = p_Var14->x - local_60.x;
          (fxPrim->v0).y = (&p_Var14->x)[1] - local_60.y;
          (fxPrim->v0).z = (&p_Var14->x)[2] - local_60.z;
          (fxPrim->v1).x = p_Var16->x - local_60.x;
          (fxPrim->v1).y = (&p_Var16->x)[1] - local_60.y;
          (fxPrim->v1).z = (&p_Var16->x)[2] - local_60.z;
          (fxPrim->v2).x = p_Var17->x - local_60.x;
          (fxPrim->v2).y = (&p_Var17->x)[1] - local_60.y;
          sVar4 = (&p_Var17->x)[2];
          fxPrim->matrix = p_Var5;
          (fxPrim->v2).z = sVar4 - local_60.z;
          FX_AniTexSetup(fxPrim, mface, local_44, fxTracker);
          if ((local_58 & 0x40) == 0)
          {
            lVar9 = _FX_DoLighting(mface);
            fxPrim->color = lVar9;
          }
          else
          {
            if ((mface->flags & 2) == 0)
            {
              uVar11 = mface->color & 0xffffff;
              fxPrim->color = uVar11;
              uVar11 = uVar11 | 0x20000000;
              uVar8 = mface->color;
            }
            else
            {
              iVar7 = mface->color;
              uVar11 = *(u_int *)(iVar7 + 0xc) & 0xffffff;
              fxPrim->color = uVar11;
              uVar11 = uVar11 | 0x24000000;
              uVar8 = *(u_int *)(iVar7 + 0xc);
            }
            fxPrim->color = uVar11 | uVar8 & 0x3000000;
          }
          if (fxProcess == (TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess)0x0)
          {
            *(code **)&fxPrim->process = FX_ShatterProcess;
          }
          else
          {
            *(TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess *)&fxPrim->process = fxProcess;
          }
          *(undefined2 *)&fxPrim->duo = *puVar19;
          *(undefined2 *)((int)&fxPrim->duo + 2) = puVar19[1];
          *(undefined2 *)((int)&fxPrim->duo + 4) = puVar19[2];
          if (splintDef != (FXSplinter *)0x0)
          {
            sVar4 = splintDef->triVelRng;
            if ((int)sVar4 != 0)
            {
              sVar10 = -splintDef->triVelRng;
              iVar7 = rand();
              iVar15 = ((int)sVar4 << 0x11) >> 0x10;
              *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + sVar10 + (short)(iVar7 % iVar15);
              iVar7 = rand();
              *(short *)((int)&fxPrim->duo + 2) =
                  *(short *)((int)&fxPrim->duo + 2) + sVar10 + (short)(iVar7 % iVar15);
              iVar7 = rand();
              *(short *)((int)&fxPrim->duo + 4) =
                  *(short *)((int)&fxPrim->duo + 4) + sVar10 + (short)(iVar7 % iVar15);
            }
          }
          if (vel != (SVECTOR *)0x0)
          {
            *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + vel->vx;
            *(short *)((int)&fxPrim->duo + 2) = *(short *)((int)&fxPrim->duo + 2) + vel->vy;
            *(short *)((int)&fxPrim->duo + 4) = *(short *)((int)&fxPrim->duo + 4) + vel->vz;
          }
          *(undefined2 *)((int)&fxPrim->duo + 6) = 0;
          *(undefined2 *)((int)&fxPrim->duo + 8) = 0;
          fxPrim->work1 = 0x1000;
          fxPrim->timeToLive = local_50;
          if (splintDef == (FXSplinter *)0x0)
          {
            *(undefined2 *)((int)&fxPrim->duo + 10) = 0xfff8;
            iVar15 = rand();
            iVar7 = iVar15;
            if (iVar15 < 0)
            {
              iVar7 = iVar15 + 7;
            }
            fxPrim->work3 = (short)iVar15 + (short)(iVar7 >> 3) * -8 + -4;
          }
          else
          {
            sVar4 = splintDef->rotRateRng;
            if ((int)sVar4 == 0)
            {
              fxPrim->work3 = 0;
            }
            else
            {
              iVar7 = rand();
              fxPrim->work3 = (short)(iVar7 % (((int)sVar4 << 0x11) >> 0x10)) - sVar4;
            }
            *(short *)((int)&fxPrim->duo + 10) = splintDef->gravityZ;
          }
          sVar10 = (instance->shadowPosition).z + -0x32;
          fxPrim->work0 = sVar10;
          sVar4 = -0x7fff;
          if ((local_58 & 0x10) == 0)
          {
            sVar3 = (fxPrim->position).z;
            sVar4 = sVar3 + -0x32;
            if ((sVar10 <= (fxPrim->position).z) &&
                (sVar4 = sVar3 + -0x32, (instance->object->oflags & 0x200U) != 0))
              goto LAB_80043e10;
          }
          fxPrim->work0 = sVar4;
        }
        else
        {
          (*fxSetup)(fxPrim, fxProcess, p_Var5, instance, mface, local_40, center, vel, accl, fxTracker, 0x1e);
        }
      LAB_80043e10:
        LIST_GetFunc(&fxTracker->usedPrimList, (NodeType *)fxPrim);
        p_Var18 = mface;
      }
      mface = p_Var18 + local_4c;
    } while (mface < local_48);
  }
  return;
}

void _FX_BuildNonSegmentedSplinters(_Instance *instance, SVECTOR *center, SVECTOR *vel, SVECTOR *accl, FXSplinter *splintDef, _FXTracker *fxTracker, TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup fxSetup,
                                    TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess fxProcess, int shardFlags)

{
  short sVar1;
  _VertexPool *p_Var2;
  short sVar3;
  int iVar4;
  _FX_MATRIX *p_Var5;
  u_int uVar6;
  _FX_PRIM *fxPrim;
  u_int uVar7;
  long lVar8;
  int iVar9;
  u_int uVar10;
  u_char *puVar11;
  int iVar12;
  u_short uVar13;
  _PVertex *p_Var14;
  int iVar15;
  _PVertex *p_Var16;
  _MFace *mface;
  _PVertex *p_Var17;
  _MFace *p_Var18;
  _FX_MATRIX *local_c8[4];
  u_char local_b8;
  u_char local_b4;
  u_char local_b0;
  u_char local_ac;
  u_char local_a8;
  long local_a4;
  long local_a0;
  long local_9c;
  long local_98;
  long local_94;
  long local_90;
  short local_88;
  short local_86;
  short local_84;
  undefined2 local_80;
  undefined2 local_7e;
  short local_7c;
  short local_78;
  short local_76;
  short local_74;
  u_char local_70;
  undefined *local_6c;
  undefined *local_68;
  undefined *local_64;
  u_char local_60;
  undefined *local_5c;
  u_char local_58;
  undefined *local_54;
  u_short local_50;
  int local_48;
  int local_44;
  _MFace *local_40;
  _Model *local_3c;
  _MVertex *local_38;
  int local_34;
  short *local_30;

  p_Var2 = gameTrackerX.vertexPool;
  local_3c = instance->object->modelList[instance->currentModel];
  local_38 = local_3c->vertexList;
  mface = local_3c->faceList;
  local_70 = 0xf;
  local_6c = (undefined *)0x60064;
  local_68 = &DAT_0000fff1;
  local_64 = (undefined *)0x60064;
  local_60 = &DAT_000f0000;
  local_5c = (undefined *)0x60064;
  local_58 = 0xfff10000;
  local_54 = (undefined *)0x60064;
  local_50 = (u_short)shardFlags;
  PIPE3D_TransformVerticesToWorld(instance, (_SVector *)gameTrackerX.vertexPool, (long *)(gameTrackerX.vertexPool)->color,
                                  (_Vector *)&local_98);
  if (splintDef == (FXSplinter *)0x0)
  {
    iVar12 = rand();
    iVar4 = iVar12;
    if (iVar12 < 0)
    {
      iVar4 = iVar12 + 7;
    }
    local_70 = local_70 & 0xffff0000 |
               (u_int)(u_short)((short)local_70 + -4 + (short)iVar12 + (short)(iVar4 >> 3) * -8);
    iVar12 = rand();
    iVar4 = iVar12;
    if (iVar12 < 0)
    {
      iVar4 = iVar12 + 7;
    }
    local_68 = (undefined *)((u_int)local_68 & 0xffff0000 |
                             (u_int)(u_short)((short)local_68 + -4 + (short)iVar12 + (short)(iVar4 >> 3) * -8));
    iVar12 = rand();
    iVar4 = iVar12;
    if (iVar12 < 0)
    {
      iVar4 = iVar12 + 7;
    }
    local_60 = (undefined *)((u_int)local_60 & 0xffff |
                             (u_int)(u_short)(local_60._2_2_ + -4 + (short)iVar12 + (short)(iVar4 >> 3) * -8) << 0x10);
    iVar12 = rand();
    iVar4 = iVar12;
    if (iVar12 < 0)
    {
      iVar4 = iVar12 + 7;
    }
    local_58 = local_58 & 0xffff |
               (u_int)(u_short)(local_58._2_2_ + -4 + (short)iVar12 + (short)(iVar4 >> 3) * -8) << 0x10;
    local_48 = 0x20;
  }
  else
  {
    sVar3 = splintDef->chunkVelRng;
    uVar13 = splintDef->chunkVelXY - sVar3;
    if ((int)sVar3 == 0)
    {
      local_70 = local_70 & 0xffff0000 | (u_int)uVar13;
      local_68 = (undefined *)((u_int)local_68 & 0xffff0000 | (u_int)(u_short)-uVar13);
      local_60 = (undefined *)((u_int)local_60 & 0xffff | (u_int)uVar13 << 0x10);
      local_58 = local_58 & 0xffff | (u_int)(u_short)-uVar13 << 0x10;
      uVar13 = splintDef->chunkVelZ;
      local_6c = (undefined *)((u_int)local_6c & 0xffff0000 | (u_int)uVar13);
      local_64 = (undefined *)((u_int)local_64 & 0xffff0000 | (u_int)uVar13);
      local_5c = (undefined *)((u_int)local_5c & 0xffff0000 | (u_int)uVar13);
      local_54 = (undefined *)((u_int)local_54 & 0xffff0000 | (u_int)uVar13);
    }
    else
    {
      iVar4 = rand();
      iVar12 = ((int)sVar3 << 0x11) >> 0x10;
      local_70 = local_70 & 0xffff0000 | (u_int)(u_short)(uVar13 + (short)(iVar4 % iVar12));
      iVar4 = rand();
      local_68 = (undefined *)((u_int)local_68 & 0xffff0000 | (u_int)(u_short) - (uVar13 + (short)(iVar4 % iVar12)));
      iVar4 = rand();
      local_60 = (undefined *)((u_int)local_60 & 0xffff | (u_int)(u_short)(uVar13 + (short)(iVar4 % iVar12)) << 0x10);
      iVar4 = rand();
      local_58 = local_58 & 0xffff | (u_int)(u_short) - (uVar13 + (short)(iVar4 % iVar12)) << 0x10;
      sVar3 = splintDef->chunkVelZ - splintDef->chunkVelRng;
      iVar4 = rand();
      local_6c = (undefined *)((u_int)local_6c & 0xffff0000 | (u_int)(u_short)(sVar3 + (short)(iVar4 % iVar12)));
      iVar4 = rand();
      local_64 = (undefined *)((u_int)local_64 & 0xffff0000 | (u_int)(u_short)(sVar3 + (short)(iVar4 % iVar12)));
      iVar4 = rand();
      local_5c = (undefined *)((u_int)local_5c & 0xffff0000 | (u_int)(u_short)(sVar3 + (short)(iVar4 % iVar12)));
      iVar4 = rand();
      local_54 = (undefined *)((u_int)local_54 & 0xffff0000 | (u_int)(u_short)(sVar3 + (short)(iVar4 % iVar12)));
    }
    local_48 = (int)splintDef->lifetime;
  }
  _FX_SetupLighting(instance);
  local_a8 = CONCAT22(local_a8._2_2_, 0x1000);
  local_ac = 0;
  local_b0 = 0x1000;
  local_b4 = 0;
  local_b8 = 0x1000;
  local_a4 = local_98;
  local_a0 = local_94;
  local_9c = local_90;
  iVar4 = 0;
  do
  {
    p_Var5 = FX_GetMatrix(fxTracker);
    if (p_Var5 == (_FX_MATRIX *)0x0)
    {
      if (iVar4 == 0)
      {
        return;
      }
      iVar12 = rand();
      p_Var5 = local_c8[iVar12 % iVar4];
    }
    else
    {
      local_c8[iVar4] = p_Var5;
      *(u_char *)(p_Var5->lwTransform).m = local_b8;
      *(u_char *)((p_Var5->lwTransform).m + 2) = local_b4;
      *(u_char *)((p_Var5->lwTransform).m + 4) = local_b0;
      *(u_char *)((p_Var5->lwTransform).m + 6) = local_ac;
      *(u_char *)((p_Var5->lwTransform).m + 8) = local_a8;
      (p_Var5->lwTransform).t[0] = local_a4;
      (p_Var5->lwTransform).t[1] = local_a0;
      (p_Var5->lwTransform).t[2] = local_9c;
    }
    iVar12 = iVar4 * 8;
    puVar11 = &local_70 + iVar4 * 2;
    local_78 = *(short *)puVar11;
    local_76 = *(short *)((int)&local_70 + iVar12 + 2);
    local_74 = *(short *)(&local_6c + iVar4 * 2);
    *(short *)puVar11 =
        (short)((int)local_78 * (int)(short)local_b8 >> 0xc) +
        (short)((int)local_76 * (int)local_b8._2_2_ >> 0xc) +
        (short)((int)local_74 * (int)(short)local_b4 >> 0xc);
    *(short *)((int)&local_70 + iVar12 + 2) =
        (short)((int)local_78 * (int)local_b4._2_2_ >> 0xc) +
        (short)((int)local_76 * (int)(short)local_b0 >> 0xc) +
        (short)((int)local_74 * (int)local_b0._2_2_ >> 0xc);
    iVar15 = iVar4 + 1;
    *(short *)(&local_6c + iVar4 * 2) =
        (short)((int)local_78 * (int)(short)local_ac >> 0xc) +
        (short)((int)local_76 * (int)local_ac._2_2_ >> 0xc) +
        (short)((int)local_74 * (int)(short)local_a8 >> 0xc);
    (p_Var5->lwTransform).t[0] = (p_Var5->lwTransform).t[0] + (int)*(short *)puVar11 * 4;
    (p_Var5->lwTransform).t[1] =
        (p_Var5->lwTransform).t[1] +
        ((int)((u_int) * (u_short *)((int)&local_70 + iVar12 + 2) << 0x10) >> 0xe);
    iVar4 = iVar15;
  } while (iVar15 < 4);
  if (splintDef == (FXSplinter *)0x0)
  {
    local_44 = 1;
  }
  else
  {
    if ((int)splintDef->faceLimit == 0)
    {
      local_44 = 1;
    }
    else
    {
      (int)splintDef->faceLimit + 1;
    }
  }
  local_40 = mface + local_3c->numFaces;
  if (mface < mface + local_3c->numFaces)
  {
    local_34 = 0x55555556;
    local_30 = &local_88;
    do
    {
      p_Var14 = p_Var2->vertex + (mface->face).v0;
      p_Var16 = p_Var2->vertex + (mface->face).v1;
      p_Var17 = p_Var2->vertex + (mface->face).v2;
      iVar4 = (int)p_Var14->x + (int)p_Var16->x + (int)p_Var17->x;
      iVar9 = (int)((u_longlong)((longlong)iVar4 * (longlong)local_34) >> 0x20) - (iVar4 >> 0x1f);
      local_80 = (short)iVar9;
      iVar4 = (int)(&p_Var14->x)[1] + (int)(&p_Var16->x)[1] + (int)(&p_Var17->x)[1];
      iVar4 = (int)((u_longlong)((longlong)iVar4 * (longlong)local_34) >> 0x20) - (iVar4 >> 0x1f);
      local_7e = (short)iVar4;
      iVar12 = (int)(&p_Var14->x)[2] + (int)(&p_Var16->x)[2] + (int)(&p_Var17->x)[2];
      iVar15 = iVar4 * 0x10000 >> 0x10;
      iVar9 = iVar9 * 0x10000 >> 0x10;
      iVar4 = iVar9;
      if (iVar9 < 0)
      {
        iVar4 = -iVar9;
      }
      local_7c = (short)((u_longlong)((longlong)iVar12 * (longlong)local_34) >> 0x20) -
                 (short)(iVar12 >> 0x1f);
      iVar12 = iVar15;
      if (iVar15 < 0)
      {
        iVar12 = -iVar15;
      }
      uVar6 = (u_int)(iVar9 < 1);
      if ((iVar4 <= iVar12) && (uVar6 = 3, 0 < iVar15))
      {
        uVar6 = 2;
      }
      p_Var5 = local_c8[uVar6];
      fxPrim = FX_GetPrim(fxTracker);
      p_Var18 = local_40;
      if (fxPrim != (_FX_PRIM *)0x0)
      {
        if (fxSetup == (TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup)0x0)
        {
          (fxPrim->position).x = *(short *)(p_Var5->lwTransform).t;
          (fxPrim->position).y = *(short *)((p_Var5->lwTransform).t + 1);
          (fxPrim->position).z = *(short *)((p_Var5->lwTransform).t + 2);
          sVar3 = (fxPrim->position).z;
          local_88 = (fxPrim->position).x - (short)local_98;
          local_30[1] = (fxPrim->position).y - (short)local_94;
          local_30[2] = sVar3 - (short)local_90;
          (fxPrim->v0).x = p_Var14->x - local_88;
          (fxPrim->v0).y = (&p_Var14->x)[1] - local_86;
          (fxPrim->v0).z = (&p_Var14->x)[2] - local_84;
          (fxPrim->v1).x = p_Var16->x - local_88;
          (fxPrim->v1).y = (&p_Var16->x)[1] - local_86;
          (fxPrim->v1).z = (&p_Var16->x)[2] - local_84;
          (fxPrim->v2).x = p_Var17->x - local_88;
          (fxPrim->v2).y = (&p_Var17->x)[1] - local_86;
          sVar3 = (&p_Var17->x)[2];
          fxPrim->matrix = p_Var5;
          (fxPrim->v2).z = sVar3 - local_84;
          FX_AniTexSetup(fxPrim, mface, local_3c, fxTracker);
          if ((local_50 & 0x40) == 0)
          {
            lVar8 = _FX_DoLighting(mface);
            fxPrim->color = lVar8;
          }
          else
          {
            if ((mface->flags & 2) == 0)
            {
              uVar10 = mface->color & 0xffffff;
              fxPrim->color = uVar10;
              uVar10 = uVar10 | 0x20000000;
              uVar7 = mface->color;
            }
            else
            {
              iVar4 = mface->color;
              uVar10 = *(u_int *)(iVar4 + 0xc) & 0xffffff;
              fxPrim->color = uVar10;
              uVar10 = uVar10 | 0x24000000;
              uVar7 = *(u_int *)(iVar4 + 0xc);
            }
            fxPrim->color = uVar10 | uVar7 & 0x3000000;
          }
          if (fxProcess == (TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess)0x0)
          {
            *(code **)&fxPrim->process = FX_ShatterProcess;
          }
          else
          {
            *(TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess *)&fxPrim->process = fxProcess;
          }
          *(undefined2 *)&fxPrim->duo = *(undefined2 *)(&local_70 + uVar6 * 2);
          *(undefined2 *)((int)&fxPrim->duo + 2) = *(undefined2 *)((int)&local_70 + uVar6 * 8 + 2);
          *(undefined2 *)((int)&fxPrim->duo + 4) = *(undefined2 *)(&local_6c + uVar6 * 2);
          if (splintDef == (FXSplinter *)0x0)
          {
            iVar12 = rand();
            iVar4 = iVar12;
            if (iVar12 < 0)
            {
              iVar4 = iVar12 + 7;
            }
            *(short *)&fxPrim->duo =
                *(short *)&fxPrim->duo + -4 + (short)iVar12 + (short)(iVar4 >> 3) * -8;
            iVar12 = rand();
            iVar4 = iVar12;
            if (iVar12 < 0)
            {
              iVar4 = iVar12 + 7;
            }
            *(short *)((int)&fxPrim->duo + 2) =
                *(short *)((int)&fxPrim->duo + 2) + -4 + (short)iVar12 + (short)(iVar4 >> 3) * -8;
            iVar12 = rand();
            iVar4 = iVar12;
            if (iVar12 < 0)
            {
              iVar4 = iVar12 + 7;
            }
            sVar3 = *(short *)((int)&fxPrim->duo + 4) + -4 +
                    (short)iVar12 + (short)(iVar4 >> 3) * -8;
          LAB_800448cc:
            *(short *)((int)&fxPrim->duo + 4) = sVar3;
          }
          else
          {
            sVar3 = splintDef->triVelRng;
            if ((int)sVar3 != 0)
            {
              sVar1 = -splintDef->triVelRng;
              iVar4 = rand();
              iVar12 = ((int)sVar3 << 0x11) >> 0x10;
              *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + sVar1 + (short)(iVar4 % iVar12);
              iVar4 = rand();
              *(short *)((int)&fxPrim->duo + 2) =
                  *(short *)((int)&fxPrim->duo + 2) + sVar1 + (short)(iVar4 % iVar12);
              iVar4 = rand();
              sVar3 = *(short *)((int)&fxPrim->duo + 4) + sVar1 + (short)(iVar4 % iVar12);
              goto LAB_800448cc;
            }
          }
          if (vel != (SVECTOR *)0x0)
          {
            *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + vel->vx;
            *(short *)((int)&fxPrim->duo + 2) = *(short *)((int)&fxPrim->duo + 2) + vel->vy;
            *(short *)((int)&fxPrim->duo + 4) = *(short *)((int)&fxPrim->duo + 4) + vel->vz;
          }
          *(undefined2 *)((int)&fxPrim->duo + 6) = 0;
          *(undefined2 *)((int)&fxPrim->duo + 8) = 0;
          if (splintDef == (FXSplinter *)0x0)
          {
            *(undefined2 *)((int)&fxPrim->duo + 10) = 0xfff8;
            iVar12 = rand();
            iVar4 = iVar12;
            if (iVar12 < 0)
            {
              iVar4 = iVar12 + 7;
            }
            fxPrim->work3 = (short)iVar12 + (short)(iVar4 >> 3) * -8 + -4;
          }
          else
          {
            sVar3 = splintDef->rotRateRng;
            if ((int)sVar3 == 0)
            {
              fxPrim->work3 = 0;
            }
            else
            {
              iVar4 = rand();
              fxPrim->work3 = (short)(iVar4 % (((int)sVar3 << 0x11) >> 0x10)) - sVar3;
            }
            *(short *)((int)&fxPrim->duo + 10) = splintDef->gravityZ;
          }
          fxPrim->work1 = 0x1000;
          fxPrim->timeToLive = local_48;
          sVar3 = -0x7fff;
          if ((local_50 & 0x10) == 0)
          {
            sVar3 = (instance->position).z -
                    instance->object->modelList[instance->currentModel]->maxRad;
          }
          fxPrim->work0 = sVar3;
        }
        else
        {
          (*fxSetup)(fxPrim, fxProcess, p_Var5, instance, mface, local_38, center, vel, accl, fxTracker, 0x1e);
        }
        LIST_GetFunc(&fxTracker->usedPrimList, (NodeType *)fxPrim);
        p_Var18 = mface;
      }
      mface = p_Var18 + local_44;
    } while (mface < local_40);
  }
  return;
}

void _FX_BuildNonSegmentedSplinters(_Instance *instance, SVECTOR *center, SVECTOR *vel, SVECTOR *accl, FXSplinter *splintDef, _FXTracker *fxTracker, TDRFuncPtr__FX_BuildSplinters6fxSetup fxSetup,
                                    TDRFuncPtr__FX_BuildSplinters7fxProcess fxProcess, int shardFlags)

{
  long lVar1;

  lVar1 = MEMPACK_ReportMemory((char *)instance->object);
  if (lVar1 != 0)
  {
    if (splintDef != (FXSplinter *)0x0)
    {
      shardFlags = (u_int)(u_short)splintDef->flags | shardFlags;
      if ((int)splintDef->soundFx != 0)
      {
        SndPlay((int)splintDef->soundFx);
      }
    }
    if ((instance->object->modelList[instance->currentModel]->numSegments < 4) ||
        ((shardFlags & 0x20U) != 0))
    {
      _FX_BuildNonSegmentedSplinters(instance, center, vel, accl, splintDef, fxTracker,
                                     (TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup)fxSetup,
                                     (TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess)fxProcess,
                                     (int)(short)shardFlags);
    }
    else
    {
      _FX_BuildSegmentedSplinters(instance, center, vel, accl, splintDef, fxTracker,
                                  (TDRFuncPtr__FX_BuildSegmentedSplinters6fxSetup)fxSetup,
                                  (TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess)fxProcess, (int)(short)shardFlags);
    }
  }
  return;
}

void _FX_BuildSplinters(_Instance *instance, SVECTOR *center, SVECTOR *vel, SVECTOR *accl,
                        _FXTracker *fxTracker, TDRFuncPtr__FX_Build5fxSetup fxSetup,
                        TDRFuncPtr__FX_Build6fxProcess fxProcess, int shardFlags)

{
  long lVar1;

  lVar1 = MEMPACK_ReportMemory((char *)instance->object);
  if (lVar1 != 0)
  {
    if (instance->object->modelList[instance->currentModel]->numSegments < 4)
    {
      _FX_BuildNonSegmentedSplinters(instance, center, vel, accl, (FXSplinter *)0x0, fxTracker,
                                     (TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup)fxSetup,
                                     (TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess)fxProcess,
                                     (int)(short)shardFlags);
    }
    else
    {
      _FX_BuildSegmentedSplinters(instance, center, vel, accl, (FXSplinter *)0x0, fxTracker,
                                  (TDRFuncPtr__FX_BuildSegmentedSplinters6fxSetup)fxSetup,
                                  (TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess)fxProcess, (int)(short)shardFlags);
    }
  }
  return;
}

void _FX_Build(_Instance *instance, SVECTOR *center, SVECTOR *vel, SVECTOR *accl, _FXTracker *fxTracker,
               TDRFuncPtr_FX_Build5fxSetup fxSetup, TDRFuncPtr_FX_Build6fxProcess fxProcess)

{
  _FX_BuildSplinters(instance, center, vel, accl, fxTracker, (TDRFuncPtr__FX_Build5fxSetup)fxSetup,
                     (TDRFuncPtr__FX_Build6fxProcess)fxProcess, 0);
  return;
}

void FX_UpdatePos(_FX_PRIM *fxPrim, _SVector *offset, int spriteflag)

{
  short sVar1;
  short sVar2;
  u_int uVar3;

  sVar1 = offset->y;
  sVar2 = offset->z;
  (fxPrim->position).x = (fxPrim->position).x + offset->x;
  (fxPrim->position).y = (fxPrim->position).y + sVar1;
  (fxPrim->position).z = (fxPrim->position).z + sVar2;
  if ((spriteflag == 0) && ((fxPrim->flags & 0x10000U) != 0))
  {
    (fxPrim->v0).x = (fxPrim->v0).x + offset->x;
    (fxPrim->v0).y = (fxPrim->v0).y + offset->y;
    (fxPrim->v0).z = (fxPrim->v0).z + offset->z;
    (fxPrim->v1).x = (fxPrim->v1).x + offset->x;
    (fxPrim->v1).y = (fxPrim->v1).y + offset->y;
    (fxPrim->v1).z = (fxPrim->v1).z + offset->z;
    (fxPrim->v2).x = (fxPrim->v2).x + offset->x;
    (fxPrim->v2).y = (fxPrim->v2).y + offset->y;
    uVar3 = fxPrim->flags;
    (fxPrim->v2).z = (fxPrim->v2).z + offset->z;
    if ((uVar3 & 8) != 0)
    {
      (fxPrim->v3).x = (fxPrim->v3).x + offset->x;
      (fxPrim->v3).y = (fxPrim->v3).y + offset->y;
      (fxPrim->v3).z = (fxPrim->v3).z + offset->z;
    }
  }
  return;
}

void CAMERA_Relocate(_SVector *offset)

{
  byte bVar1;
  short sVar2;
  _FXGeneralEffect *p_Var3;
  _FXTracker *p_Var4;
  short *psVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  _FX_PRIM *fxPrim;

  p_Var4 = gFXT;
  fxPrim = (_FX_PRIM *)(gFXT->usedPrimList).next;
  while (fxPrim != (_FX_PRIM *)0x0)
  {
    FX_UpdatePos(fxPrim, offset, 0);
    fxPrim = (_FX_PRIM *)(fxPrim->node).next;
  }
  fxPrim = (_FX_PRIM *)(p_Var4->usedPrimListSprite).next;
  while (p_Var3 = FX_GeneralEffectTracker, fxPrim != (_FX_PRIM *)0x0)
  {
    FX_UpdatePos(fxPrim, offset, 1);
    if ((code *)fxPrim->process == FX_WaterBubbleProcess)
    {
      fxPrim->timeToLive = fxPrim->timeToLive + (int)offset->z;
    }
    fxPrim = (_FX_PRIM *)(fxPrim->node).next;
  }
  while (p_Var3 != (_FXGeneralEffect *)0x0)
  {
    bVar1 = p_Var3->effectType;
    iVar8 = 0;
    if (bVar1 == 0)
    {
      sVar2 = *(short *)&p_Var3[1].next;
      if ((int)(u_int)bVar1 < (int)sVar2)
      {
        iVar7 = 0;
        do
        {
          psVar5 = (short *)(iVar7 + (int)p_Var3[1].continue_process);
          *psVar5 = *psVar5 + offset->x;
          iVar6 = iVar7 + (int)p_Var3[1].continue_process;
          *(short *)(iVar6 + 2) = *(short *)(iVar6 + 2) + offset->y;
          iVar7 = iVar7 + (int)p_Var3[1].continue_process;
          iVar8 = iVar8 + 1;
          *(short *)(iVar7 + 4) = *(short *)(iVar7 + 4) + offset->z;
          iVar7 = iVar8 * 8;
        } while (iVar8 < (int)sVar2);
      }
    }
    else
    {
      if (bVar1 == 0x84)
      {
        *(short *)&p_Var3[1].next = *(short *)&p_Var3[1].next + offset->x;
        *(short *)((int)&p_Var3[1].next + 2) = *(short *)((int)&p_Var3[1].next + 2) + offset->y;
        *(short *)&p_Var3[1].continue_process = *(short *)&p_Var3[1].continue_process + offset->z;
      }
    }
    p_Var3 = (_FXGeneralEffect *)p_Var3->next;
  }
  return;
}

void LOAD_UpdateBigFilePointers(_FX_PRIM *fxPrim, Object *oldObject, long sizeOfObject, long offset)

{
  AniTex *pAVar1;
  Object *pOVar2;
  AniTex *pAVar3;
  TextureMT3 *pTVar4;
  TextureMT3 *pTVar5;

  if (fxPrim != (_FX_PRIM *)0x0)
  {
    do
    {
      if ((fxPrim->flags & 1U) != 0)
      {
        pOVar2 = (Object *)fxPrim->texture;
        if ((oldObject <= pOVar2) && (pOVar2 <= (Object *)((int)&oldObject->oflags + sizeOfObject)))
        {
          pTVar4 = (TextureMT3 *)0x0;
          if (pOVar2 != (Object *)0x0)
          {
            pTVar4 = (TextureMT3 *)((int)&pOVar2->oflags + offset);
          }
          fxPrim->texture = pTVar4;
          if ((fxPrim->flags & 4U) != 0)
          {
            pTVar4 = (fxPrim->ani).texMem;
            pTVar5 = (TextureMT3 *)0x0;
            if (pTVar4 != (TextureMT3 *)0x0)
            {
              pTVar5 = (TextureMT3 *)(&pTVar4->u0 + offset);
            }
            pAVar3 = (fxPrim->ani).aniTextures;
            pAVar1 = (AniTex *)0x0;
            (fxPrim->ani).texMem = pTVar5;
            if (pAVar3 != (AniTex *)0x0)
            {
              pAVar1 = (AniTex *)((int)&pAVar3->numAniTextues + offset);
            }
            (fxPrim->ani).aniTextures = pAVar1;
          }
        }
      }
      fxPrim = (_FX_PRIM *)(fxPrim->node).next;
    } while (fxPrim != (_FX_PRIM *)0x0);
  }
  return;
}

void RelocateSpotLights(Object *oldObject, Object *newObject, long sizeOfObject)

{
  _FXTracker *p_Var1;
  void *pvVar2;
  Object *pOVar3;
  _FXGeneralEffect *p_Var4;

  p_Var1 = gFXT;
  newObject = (Object *)((int)newObject - (int)oldObject);
  LOAD_UpdateBigFilePointers((_FX_PRIM *)(gFXT->usedPrimList).next, oldObject, sizeOfObject, (long)newObject);
  LOAD_UpdateBigFilePointers((_FX_PRIM *)(p_Var1->usedPrimListSprite).next, oldObject, sizeOfObject, (long)newObject);
  if (FX_GeneralEffectTracker != (_FXGeneralEffect *)0x0)
  {
    p_Var4 = FX_GeneralEffectTracker;
    do
    {
      if (p_Var4->effectType == '\x01')
      {
        pOVar3 = (Object *)p_Var4[1].next;
        if (((pOVar3 != (Object *)0x0) && (oldObject <= pOVar3)) &&
            (pOVar3 <= (Object *)((int)&oldObject->oflags + sizeOfObject)))
        {
          pvVar2 = (void *)0x0;
          if (pOVar3 != (Object *)0x0)
          {
            pvVar2 = (void *)((int)pOVar3 + (int)newObject);
          }
          p_Var4[1].next = pvVar2;
        }
      }
      p_Var4 = (_FXGeneralEffect *)p_Var4->next;
    } while (p_Var4 != (_FXGeneralEffect *)0x0);
  }
  return;
}

void FX_ProcessList(_FXTracker *fxTracker)

{
  _FXGeneralEffect *p_Var1;
  int iVar2;
  NodeType *node;
  NodeType *pNVar3;
  NodeType *pNVar4;
  _FXGeneralEffect *p_Var5;

  iVar2 = (int)(((u_int)(u_short)FX_TimeCount + (u_int)(u_short)gameTrackerX.timeMult) * 0x10000) >>
          0x10;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xfff;
  }
  FX_Frames = (short)(iVar2 >> 0xc);
  pNVar4 = (fxTracker->usedMatrixList).next;
  FX_TimeCount = (short)((u_int)(u_short)FX_TimeCount + (u_int)(u_short)gameTrackerX.timeMult) +
                 FX_Frames * -0x1000;
  while (pNVar4 != (NodeType *)0x0)
  {
    pNVar3 = pNVar4[1].prev;
    node = (NodeType *)((u_int)pNVar3 | 1);
    if (((u_int)pNVar3 & 4) == 0)
    {
      node = (NodeType *)((u_int)pNVar3 & 0xfffffffe);
    }
    pNVar4[1].prev = node;
    pNVar4[1].prev = (NodeType *)((u_int)pNVar4[1].prev & 0xfffffffd);
    pNVar4 = pNVar4->next;
  }
  pNVar4 = (fxTracker->usedPrimList).next;
  while (node = pNVar4, node != (NodeType *)0x0)
  {
    pNVar3 = node[3].prev;
    pNVar4 = node->next;
    if (pNVar3 != (NodeType *)0x0)
    {
      pNVar3[1].prev = (NodeType *)((u_int)pNVar3[1].prev | 1);
    }
    if (node[2].next != (NodeType *)0x0)
    {
      (*(code *)node[2].next)(node, fxTracker);
    }
  }
  pNVar4 = (fxTracker->usedPrimListSprite).next;
  while (node = pNVar4, node != (NodeType *)0x0)
  {
    pNVar4 = node->next;
    if (node[2].next != (NodeType *)0x0)
    {
      (*(code *)node[2].next)(node, fxTracker);
    }
  }
  pNVar4 = (fxTracker->usedMatrixList).next;
  while (node = pNVar4, p_Var5 = FX_GeneralEffectTracker, node != (NodeType *)0x0)
  {
    pNVar4 = node->next;
    if (((u_int)node[1].prev & 1) == 0)
    {
      LIST_DeleteFunc(node);
      LIST_GetFunc(&fxTracker->freeMatrixList, node);
    }
  }
  while (p_Var1 = p_Var5, p_Var1 != (_FXGeneralEffect *)0x0)
  {
    p_Var5 = (_FXGeneralEffect *)p_Var1->next;
    if ((code *)p_Var1->continue_process != (code *)0x0)
    {
      (*(code *)p_Var1->continue_process)(p_Var1, fxTracker);
    }
  }
  if (FX_ConstrictStage == 1)
  {
    FX_ConstrictStage = 0;
  }
  if (snow_amount != 0)
  {
    FX_ContinueRain(fxTracker);
  }
  if (rain_amount != 0)
  {
    FX_ContinueLightning(fxTracker);
  }
  FX_UpdateWind(fxTracker);
  return;
}

void FX_DrawReaver(_PrimPool *primPool, u_long **ot, MATRIX *wcTransform)

{
  if (FX_reaver_instance != (_Instance *)0x0)
  {
    StopSoulReaverCharge(FX_reaver_instance, primPool, ot, wcTransform);
    _SoulReaverAnimate(FX_reaver_instance, ot);
  }
  FX_reaver_instance = (_Instance *)0x0;
  return;
}

void FX_DrawLightning(_FXTracker *fxTracker, GameTracker *gameTracker, u_long **ot, MATRIX *wcTransform)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  u_int *puVar5;
  int iVar6;
  short sVar7;
  GameTracker *pGVar8;
  u_char in_zero;
  u_char in_at;
  u_int uVar9;
  u_long *puVar10;
  char cVar11;
  char cVar12;
  u_short uVar13;
  byte bVar14;
  byte bVar15;
  int iVar16;
  int iVar17;
  NodeType *pNVar18;
  char cVar19;
  u_short uVar20;
  u_int *puVar21;
  u_int *puVar22;
  u_char uVar23;
  u_char uVar24;
  int iVar25;
  u_char uVar26;
  NodeType *pNVar27;
  u_int *puVar28;
  u_int *puVar29;
  NodeType *pNVar30;
  NodeType **ppNVar31;
  NodeType *pNVar32;
  _PrimPool *primPool;
  u_int local_68;
  u_int local_64;
  u_int local_60;
  u_int local_5c;
  u_int local_58;
  u_int local_54;
  byte local_50;
  byte local_4f;
  byte local_4e;
  u_char local_48;
  GameTracker *local_40;
  GameTracker *local_3c;
  int local_38;
  int local_34;
  int local_30;

  bVar4 = false;
  primPool = gameTracker->primPool;
  puVar28 = primPool->nextPrim;
  local_4e = 0x1f;
  local_4f = 0x1f;
  local_50 = 0x1f;
  pNVar27 = (fxTracker->usedPrimList).next;
  if (pNVar27 != (NodeType *)0x0)
  {
    ppNVar31 = (NodeType **)(puVar28 + 1);
    do
    {
      if (primPool->lastPrim <= puVar28 + 10)
        break;
      pNVar30 = pNVar27[1].next;
      pNVar32 = pNVar27->next;
      if (((u_int)pNVar30 & 0x10) == 0)
      {
        if (((u_int)pNVar30 & 0x10000) == 0)
        {
          pNVar27[3].prev[4].prev = (NodeType *)(int)*(short *)&pNVar27[5].next;
          pNVar27[3].prev[4].next = (NodeType *)(int)*(short *)((int)&pNVar27[5].next + 2);
          pNVar27[3].prev[5].prev = (NodeType *)(int)*(short *)&pNVar27[6].prev;
          gameTracker = (GameTracker *)&pNVar27[3].prev[1].next;
          CompMatrix((u_char *)wcTransform, (u_short *)gameTracker, (u_int *)&DAT_1f800000);
          SetRotMatrix((u_char *)&DAT_1f800000);
          TransMatrix(0x1f800000);
          bVar4 = false;
        }
        else
        {
          if (!bVar4)
          {
            setCopControlWord(2, 0, *(u_char *)wcTransform->m);
            setCopControlWord(2, 0x800, *(u_char *)(wcTransform->m + 2));
            setCopControlWord(2, 0x1000, *(u_char *)(wcTransform->m + 4));
            setCopControlWord(2, 0x1800, *(u_char *)(wcTransform->m + 6));
            setCopControlWord(2, 0x2000, *(u_char *)(wcTransform->m + 8));
            setCopControlWord(2, 0x2800, wcTransform->t[0]);
            setCopControlWord(2, 0x3000, wcTransform->t[1]);
            setCopControlWord(2, 0x3800, wcTransform->t[2]);
            bVar4 = true;
          }
        }
        if (((u_int)pNVar30 & 0x2000) == 0)
        {
          setCopReg(2, in_zero, pNVar27[7].next);
          setCopReg(2, in_at, pNVar27[8].prev);
          setCopReg(2, &pNVar27[9].next, pNVar27[8].next);
          setCopReg(2, &pNVar27[8].next, pNVar27[9].prev);
          setCopReg(2, &pNVar27[7].next, pNVar27[9].next);
          setCopReg(2, gameTracker, pNVar27[10].prev);
        }
        else
        {
          local_64 = local_64 & 0xffff0000 |
                     (int)*(short *)&pNVar27[8].prev * (int)*(short *)((int)&pNVar27[9].next + 2) >>
                             0xc &
                         0xffffU;
          local_5c = local_5c & 0xffff0000 |
                     (int)*(short *)&pNVar27[9].prev * (int)*(short *)((int)&pNVar27[9].next + 2) >>
                             0xc &
                         0xffffU;
          local_68 = (int)*(short *)&pNVar27[7].next * (int)*(short *)((int)&pNVar27[7].next + 2) >>
                         0xc &
                     0xffff;
          local_60 = (int)*(short *)&pNVar27[8].next * (int)*(short *)((int)&pNVar27[7].next + 2) >>
                         0xc &
                     0xffff;
          local_58 = (int)*(short *)&pNVar27[9].next * (int)*(short *)((int)&pNVar27[7].next + 2) >>
                         0xc &
                     0xffff;
          local_54 = local_54 & 0xffff0000 |
                     (int)*(short *)&pNVar27[10].prev * (int)*(short *)((int)&pNVar27[9].next + 2) >> 0xc & 0xffffU;
          setCopReg(2, in_zero, local_68);
          setCopReg(2, in_at, local_64);
          setCopReg(2, &local_68, local_60);
          setCopReg(2, &local_58, local_5c);
          setCopReg(2, &local_60, local_58);
          setCopReg(2, gameTracker, local_54);
        }
        copFunction(2, 0x280030);
        if (((u_int)pNVar30 & 0x1000000) == 0)
        {
          if (((u_int)pNVar30 & 0x4000) == 0)
          {
            local_34 = getCopReg(2, 0x9800);
            local_34 = local_34 >> 2;
          }
          else
          {
            gameTracker = (GameTracker *)getCopReg(2, 0x11);
            local_3c = (GameTracker *)getCopReg(2, 0x12);
            local_38 = getCopReg(2, 0x13);
            local_34 = local_38 >> 2;
            pGVar8 = local_3c;
            if ((int)local_3c < (int)gameTracker)
            {
              pGVar8 = gameTracker;
            }
            local_40 = gameTracker;
            if (local_38 < (int)pGVar8)
            {
              local_34 = (int)pGVar8 >> 2;
            }
          }
        }
        else
        {
          local_40 = (GameTracker *)getCopReg(2, 0x11);
          local_3c = (GameTracker *)getCopReg(2, 0x12);
          local_38 = getCopReg(2, 0x13);
          local_34 = (int)local_40 >> 2;
        }
        if (((u_int)pNVar30 & 0x8000) != 0)
        {
          local_34 = local_34 + -0x14;
        }
        if (local_34 - 1U < 0xbff)
        {
          if (((u_int)pNVar30 & 1) == 0)
          {
            if (((u_int)pNVar30 & 8) == 0)
            {
              if (((u_int)pNVar30 & 0x1000000) == 0)
              {
                *ppNVar31 = pNVar27[3].next;
                uVar9 = getCopReg(2, 0xc);
                puVar28[2] = uVar9;
                uVar9 = getCopReg(2, 0xd);
                puVar28[3] = uVar9;
                uVar9 = getCopReg(2, 0xe);
                puVar28[4] = uVar9;
                ppNVar31 = ppNVar31 + 5;
                *puVar28 = (u_int)ot[local_34] & 0xffffff | 0x4000000;
                puVar29 = puVar28 + 5;
              }
              else
              {
                if (((u_int)pNVar30 & 0x80000) == 0)
                  goto LAB_80045de0;
                ppNVar31[1] = pNVar27[3].next;
                pNVar27 = pNVar27[4].next;
                *ppNVar31 = (NodeType *)0xe1000620;
                ppNVar31[3] = pNVar27;
                uVar9 = getCopReg(2, 0xc);
                puVar28[5] = uVar9;
                uVar9 = getCopReg(2, 0xd);
                puVar28[3] = uVar9;
                *(undefined *)((int)ppNVar31 + 7) = 0x52;
                ppNVar31 = ppNVar31 + 6;
                *puVar28 = (u_int)ot[local_34] & 0xffffff | 0x5000000;
                puVar29 = puVar28 + 6;
              }
            }
            else
            {
              if (((u_int)pNVar30 & 0x80000) != 0)
              {
                uVar9 = getCopReg(2, 0xc);
                puVar28[3] = uVar9;
                uVar9 = getCopReg(2, 0xd);
                puVar28[5] = uVar9;
                uVar9 = getCopReg(2, 0xe);
                puVar28[7] = uVar9;
                setCopReg(2, in_zero, pNVar27[10].next);
                setCopReg(2, in_at, pNVar27[0xb].prev);
                copFunction(2, 0x180001);
                *ppNVar31 = (NodeType *)0xe1000620;
                uVar9 = getCopReg(2, 0xe);
                puVar28[9] = uVar9;
                gameTracker = (GameTracker *)(puVar28 + 2);
                iVar16 = 0;
                pNVar30 = pNVar27;
                do
                {
                  setCopReg(2, 0x4000, 0x1000 - (int)*(short *)&pNVar30[6].next);
                  setCopReg(2, 0x4800, (u_int) * (byte *)&pNVar27[3].next);
                  setCopReg(2, 0x5000, (u_int) * (byte *)((int)&pNVar27[3].next + 1));
                  setCopReg(2, 0x5800, (u_int) * (byte *)((int)&pNVar27[3].next + 2));
                  copFunction(2, 0x198003d);
                  uVar23 = getCopReg(2, 0x4800);
                  uVar24 = getCopReg(2, 0x5000);
                  uVar26 = getCopReg(2, 0x5800);
                  *(char *)&(gameTracker->gameData).asmData.drawBackFaces = (char)uVar23;
                  *(undefined *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1) =
                      (char)uVar24;
                  *(undefined *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 2) =
                      (char)uVar26;
                  gameTracker = (GameTracker *)&(gameTracker->gameData).asmData.MorphTime;
                  iVar16 = iVar16 + 1;
                  pNVar30 = (NodeType *)((int)&pNVar30->prev + 2);
                } while (iVar16 < 4);
                *puVar28 = (u_int)ot[local_34] & 0xffffff | 0x9000000;
                ot[local_34] = (u_long *)((u_int)puVar28 & 0xffffff);
                *(undefined *)((int)puVar28 + 0xb) = 0x3a;
                puVar28 = puVar28 + 10;
                ppNVar31 = ppNVar31 + 10;
                goto LAB_80045de0;
              }
              uVar9 = getCopReg(2, 0xc);
              puVar28[2] = uVar9;
              uVar9 = getCopReg(2, 0xd);
              puVar28[4] = uVar9;
              uVar9 = getCopReg(2, 0xe);
              puVar28[6] = uVar9;
              setCopReg(2, in_zero, pNVar27[10].next);
              setCopReg(2, in_at, pNVar27[0xb].prev);
              copFunction(2, 0x180001);
              *ppNVar31 = pNVar27[3].next;
              ppNVar31[2] = pNVar27[3].next;
              ppNVar31[4] = pNVar27[3].next;
              pNVar27 = pNVar27[3].next;
              *(undefined *)((int)ppNVar31 + -1) = 8;
              *(undefined *)((int)ppNVar31 + 3) = 0x38;
              ppNVar31[6] = pNVar27;
              uVar9 = getCopReg(2, 0xe);
              puVar28[8] = uVar9;
              ppNVar31 = ppNVar31 + 9;
              *puVar28 = (u_int)ot[local_34] & 0xffffff | 0x8000000;
              puVar29 = puVar28 + 9;
            }
          }
          else
          {
            if (((u_int)pNVar30 & 4) == 0)
            {
              gameTracker = (GameTracker *)pNVar27[1].prev;
            }
            else
            {
              gameTracker = (GameTracker *)pNVar27[0xd].prev;
            }
            if (((u_int)pNVar30 & 8) == 0)
            {
              uVar9 = getCopReg(2, 0xc);
              puVar28[2] = uVar9;
              uVar9 = getCopReg(2, 0xd);
              puVar28[4] = uVar9;
              uVar9 = getCopReg(2, 0xe);
              puVar28[6] = uVar9;
              ppNVar31[2] = (NodeType *)(gameTracker->gameData).asmData.drawBackFaces;
              ppNVar31[4] = (NodeType *)(gameTracker->gameData).asmData.dispPage;
              ppNVar31[6] = *(NodeType **)&(gameTracker->gameData).asmData.MorphTime;
              if (((u_int)pNVar30 & 0x1000) != 0)
              {
                bVar15 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                bVar14 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
                if (bVar15 < bVar14)
                {
                  bVar3 = bVar14 < bVar15;
                  if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar15)
                  {
                  LAB_80045cf8:
                    cVar12 = *(char *)&(gameTracker->gameData).asmData.MorphTime;
                    goto LAB_80045cfc;
                  }
                  cVar12 = *(char *)&(gameTracker->gameData).asmData.drawBackFaces;
                }
                else
                {
                  if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar14)
                    goto LAB_80045cf8;
                  cVar12 = *(char *)&(gameTracker->gameData).asmData.dispPage;
                LAB_80045cfc:
                  bVar15 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                  bVar14 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
                  bVar3 = bVar14 < bVar15;
                }
                if (bVar3)
                {
                  if (*(byte *)&(gameTracker->gameData).asmData.MorphTime < bVar15)
                  {
                    cVar19 = *(char *)&(gameTracker->gameData).asmData.drawBackFaces;
                  }
                  else
                  {
                  LAB_80045d54:
                    cVar19 = *(char *)&(gameTracker->gameData).asmData.MorphTime;
                  }
                }
                else
                {
                  if (bVar14 <= *(byte *)&(gameTracker->gameData).asmData.MorphTime)
                    goto LAB_80045d54;
                  cVar19 = *(char *)&(gameTracker->gameData).asmData.dispPage;
                }
                cVar11 = cVar12;
                if (*(char *)&(gameTracker->gameData).asmData.drawBackFaces == cVar12)
                {
                  cVar11 = cVar19;
                }
                *(char *)(puVar28 + 3) = cVar11;
                cVar11 = cVar12;
                if (*(char *)&(gameTracker->gameData).asmData.dispPage == cVar12)
                {
                  cVar11 = cVar19;
                }
                *(char *)(puVar28 + 5) = cVar11;
                if (*(char *)&(gameTracker->gameData).asmData.MorphTime == cVar12)
                {
                  cVar12 = cVar19;
                }
                *(char *)(puVar28 + 7) = cVar12;
              }
              *ppNVar31 = pNVar27[3].next;
              ppNVar31 = ppNVar31 + 8;
              *puVar28 = (u_int)ot[local_34] & 0xffffff | 0x7000000;
              puVar29 = puVar28 + 8;
            }
            else
            {
              uVar9 = getCopReg(2, 0xc);
              puVar28[2] = uVar9;
              uVar9 = getCopReg(2, 0xd);
              puVar28[4] = uVar9;
              uVar9 = getCopReg(2, 0xe);
              puVar28[6] = uVar9;
              setCopReg(2, in_zero, pNVar27[10].next);
              setCopReg(2, in_at, pNVar27[0xb].prev);
              copFunction(2, 0x180001);
              bVar15 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
              bVar14 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
              if (bVar15 < bVar14)
              {
                bVar3 = bVar14 < bVar15;
                if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar15)
                {
                LAB_80045a54:
                  bVar1 = *(byte *)&(gameTracker->gameData).asmData.MorphTime;
                  goto LAB_80045a58;
                }
                bVar1 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
              }
              else
              {
                if (*(byte *)&(gameTracker->gameData).asmData.MorphTime <= bVar14)
                  goto LAB_80045a54;
                bVar1 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
              LAB_80045a58:
                bVar15 = *(byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                bVar14 = *(byte *)&(gameTracker->gameData).asmData.dispPage;
                bVar3 = bVar14 < bVar15;
              }
              if (bVar3)
              {
                if (*(byte *)&(gameTracker->gameData).asmData.MorphTime < bVar15)
                {
                  uVar20 = (u_short) * (byte *)&(gameTracker->gameData).asmData.drawBackFaces;
                }
                else
                {
                LAB_80045ab0:
                  uVar20 = (u_short) * (byte *)&(gameTracker->gameData).asmData.MorphTime;
                }
              }
              else
              {
                if (bVar14 <= *(byte *)&(gameTracker->gameData).asmData.MorphTime)
                  goto LAB_80045ab0;
                uVar20 = (u_short) * (byte *)&(gameTracker->gameData).asmData.dispPage;
              }
              bVar15 = *(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1);
              bVar14 = *(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1);
              if (bVar15 < bVar14)
              {
                if (*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) <= bVar15)
                {
                LAB_80045b0c:
                  bVar2 = *(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1);
                  goto LAB_80045b18;
                }
                bVar2 = *(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1);
              }
              else
              {
                if (*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) <= bVar14)
                  goto LAB_80045b0c;
                bVar2 = *(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1);
              LAB_80045b18:
                bVar15 = *(byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1);
                bVar14 = *(byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1);
              }
              if (bVar14 < bVar15)
              {
                if (*(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) < bVar15)
                {
                  uVar13 = (u_short) * (byte *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 1) << 8;
                }
                else
                {
                LAB_80045b70:
                  uVar13 = (u_short) * (byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1) << 8;
                }
              }
              else
              {
                if (bVar14 <= *(byte *)((int)&(gameTracker->gameData).asmData.MorphTime + 1))
                  goto LAB_80045b70;
                uVar13 = (u_short) * (byte *)((int)&(gameTracker->gameData).asmData.dispPage + 1) << 8;
              }
              *(u_short *)(puVar28 + 3) = CONCAT11(bVar2, bVar1);
              *(u_short *)(puVar28 + 5) = uVar20 | (u_short)bVar2 << 8;
              *(u_short *)(puVar28 + 7) = bVar1 | uVar13;
              *(u_short *)(puVar28 + 9) = uVar20 | uVar13;
              *(undefined2 *)((int)puVar28 + 0xe) =
                  *(undefined2 *)((int)&(gameTracker->gameData).asmData.drawBackFaces + 2);
              *(undefined2 *)((int)puVar28 + 0x16) =
                  *(undefined2 *)((int)&(gameTracker->gameData).asmData.dispPage + 2);
              uVar9 = getCopReg(2, 0xe);
              puVar28[8] = uVar9;
              if (((u_int)pNVar30 & 0x1000) != 0)
              {
                bVar15 = *(byte *)(puVar28 + 3) ^ *(byte *)(puVar28 + 5);
                *(byte *)(puVar28 + 3) = bVar15;
                bVar15 = bVar15 ^ *(byte *)(puVar28 + 5);
                gameTracker = (GameTracker *)(u_int)bVar15;
                bVar14 = *(byte *)(puVar28 + 7) ^ *(byte *)(puVar28 + 9);
                *(byte *)(puVar28 + 7) = bVar14;
                bVar14 = bVar14 ^ *(byte *)(puVar28 + 9);
                *(byte *)(puVar28 + 5) = bVar15;
                *(byte *)(puVar28 + 9) = bVar14;
                *(byte *)(puVar28 + 3) = *(byte *)(puVar28 + 3) ^ bVar15;
                *(byte *)(puVar28 + 7) = *(byte *)(puVar28 + 7) ^ bVar14;
              }
              *ppNVar31 = pNVar27[3].next;
              ppNVar31 = ppNVar31 + 10;
              *puVar28 = (u_int)ot[local_34] & 0xffffff | 0x9000000;
              puVar29 = puVar28 + 10;
            }
          }
          ot[local_34] = (u_long *)((u_int)puVar28 & 0xffffff);
          puVar28 = puVar29;
        }
      }
    LAB_80045de0:
      pNVar27 = pNVar32;
    } while (pNVar32 != (NodeType *)0x0);
  }
  SetRotMatrix((u_char *)wcTransform);
  TransMatrix((int)wcTransform);
  pNVar27 = (fxTracker->usedPrimListSprite).next;
  puVar29 = puVar28;
joined_r0x80045e0c:
  do
  {
    do
    {
      pNVar30 = pNVar27;
      if (pNVar30 == (NodeType *)0x0)
      {
      LAB_800465b8:
        primPool->nextPrim = puVar28;
        FX_DrawAllGeneralEffects(wcTransform, gameTrackerX.vertexPool, primPool, ot);
        return;
      }
      local_30 = (int)*(short *)&pNVar30[7].next << 1;
      setCopReg(2, in_zero, pNVar30[5].next);
      setCopReg(2, in_at, pNVar30[6].prev);
      setCopControlWord(2, 0xe000, 0);
      setCopControlWord(2, 0xd800, local_30);
      copFunction(2, 0x180001);
      pNVar27 = pNVar30->next;
      pNVar32 = pNVar30[1].next;
      if (primPool->lastPrim <= puVar28 + 10)
        goto LAB_800465b8;
    } while (((u_int)pNVar32 & 0x10) != 0);
    local_48 = getCopReg(2, 0xe);
    local_30 = getCopReg(2, 0x18);
    local_40 = (GameTracker *)getCopReg(2, 0x13);
    iVar16 = (int)local_40 >> 2;
    local_34 = iVar16;
    if ((((((u_int)pNVar32 & 0x2008000) != 0) &&
          (local_34 = iVar16 + -0x14, ((u_int)pNVar32 & 0x8000) == 0)) &&
         (local_34 = iVar16, ((u_int)pNVar32 & 0x2000000) != 0)) &&
        (0x14 < iVar16))
    {
      local_34 = 0xbff;
    }
    if ((((u_int)pNVar32 & 0x800000) != 0) &&
        (&UNK_00000e7f < (undefined *)((int)local_40 + 0xfffffe80U)))
    {
      local_34 = 0;
    }
    if (local_34 - 0x15U < 0xbeb)
    {
      local_48._2_2_ = (short)((u_int)local_48 >> 0x10);
      if ((((u_int)pNVar32 & 0x4000000) != 0) ||
          (((-1 < (short)local_48 && (-1 < local_48)) &&
            (((short)local_48 < 0x200 && (local_48._2_2_ < 0xf0))))))
      {
        if ((((u_int)pNVar32 & 0x2000) == 0) ||
            (iVar16 = (int)*(short *)((int)&pNVar30[7].next + 2), iVar16 == 0x1000))
        {
          iVar16 = local_30;
          if ((int)*(short *)&pNVar30[7].next != (int)*(short *)&pNVar30[8].prev)
          {
            (int)local_40;
          }
        }
        else
        {
          local_30 = (local_30 >> 0xc) * iVar16;
          iVar16 = local_30;
          if ((int)*(short *)&pNVar30[7].next != (int)*(short *)&pNVar30[8].prev)
          {
            iVar16 = ((int)*(short *)&pNVar30[8].prev *
 (int)local_40 << 4;
          }
        }
        iVar16 = iVar16 + 0xffff;
        iVar25 = iVar16 >> 0x10;
 0x140) * 0x200 + 0xffff;
 local_30 = iVar17 >> 0x10;
 iVar6 = iVar16 >> 0x1f;
 local_30._0_2_ = (short)((u_int)iVar17 >> 0x10);
 sVar7 = (short)((u_int)iVar16 >> 0x10);
 if (((u_int)pNVar32 & 1) == 0)
 {
   if (((u_int)pNVar32 & 8) != 0)
   {
     if (((u_int)pNVar32 & 0x80000) == 0)
     {
       local_48._0_2_ = (short)local_48 - (short)(local_30 - (iVar17 >> 0x1f) >> 1);
       *(short *)(puVar29 + 6) = (short)local_48;
       *(short *)(puVar29 + 2) = (short)local_48;
       local_48._2_2_ = local_48._2_2_ - (short)(iVar25 - iVar6 >> 1);
       *(short *)((int)puVar29 + 0x12) = local_48._2_2_;
       *(short *)((int)puVar29 + 10) = local_48._2_2_;
       *(short *)((int)puVar29 + 0x22) = local_48._2_2_ + sVar7;
       *(short *)((int)puVar29 + 0x1a) = local_48._2_2_ + sVar7;
       *(short *)(puVar29 + 8) = *(short *)(puVar29 + 2) + (short)local_30;
       *(short *)(puVar29 + 4) = *(short *)(puVar29 + 2) + (short)local_30;
       *(NodeType **)(puVar29 + 1) = pNVar30[3].next;
       *(NodeType **)(puVar29 + 3) = pNVar30[3].next;
       *(NodeType **)(puVar29 + 5) = pNVar30[3].next;
       pNVar30 = pNVar30[3].next;
       *(undefined *)((int)puVar29 + 3) = 8;
       *(undefined *)((int)puVar29 + 7) = 0x38;
       *(NodeType **)(puVar29 + 7) = pNVar30;
       puVar29 = puVar29 + 9;
       puVar10 = (u_long *)((u_int)puVar28 & 0xffffff);
       *puVar28 = (u_int)ot[local_34] & 0xffffff | 0x8000000;
       puVar28 = puVar28 + 9;
       ot[local_34] = puVar10;
     }
     else
     {
       puVar28 = puVar28 + 0x10;
       puVar22 = puVar29 + 3;
       puVar21 = puVar29 + 0xc;
       iVar16 = 0;
       puVar29[10] = 0xe1000640;
       puVar29[1] = 0xe1000620;
       local_48._0_2_ = (short)local_48 - (short)(local_30 - (iVar17 >> 0x1f) >> 1);
       *(short *)(puVar29 + 7) = (short)local_48;
       *(short *)(puVar29 + 3) = (short)local_48;
       local_48._2_2_ = local_48._2_2_ - (short)(iVar25 - iVar6 >> 1);
       *(short *)((int)puVar29 + 0x16) = local_48._2_2_;
       *(short *)((int)puVar29 + 0xe) = local_48._2_2_;
       *(short *)((int)puVar29 + 0x26) = local_48._2_2_ + sVar7;
       *(short *)((int)puVar29 + 0x1e) = local_48._2_2_ + sVar7;
       *(short *)(puVar29 + 9) = *(short *)(puVar29 + 3) + (short)local_30;
       *(short *)(puVar29 + 5) = *(short *)(puVar29 + 3) + (short)local_30;
       puVar5 = puVar29;
       do
       {
         setCopReg(2, 0x4000, 0x1000 - (int)*(short *)&pNVar30[6].next);
         setCopReg(2, 0x4800, (u_int) * (byte *)&pNVar30[3].next);
         setCopReg(2, 0x5000, (u_int) * (byte *)((int)&pNVar30[3].next + 1));
         setCopReg(2, 0x5800, (u_int) * (byte *)((int)&pNVar30[3].next + 2));
         copFunction(2, 0x198003d);
         uVar9 = *puVar22;
         puVar22 = puVar22 + 2;
         *puVar21 = uVar9;
         puVar21 = puVar21 + 1;
         uVar23 = getCopReg(2, 0x4800);
         uVar24 = getCopReg(2, 0x5000);
         uVar26 = getCopReg(2, 0x5800);
         *(char *)(puVar5 + 2) = (char)uVar23;
         *(undefined *)((int)puVar5 + 9) = (char)uVar24;
         *(undefined *)((int)puVar5 + 10) = (char)uVar26;
         iVar16 = iVar16 + 1;
         puVar5 = puVar5 + 2;
       } while (iVar16 < 4);
       setCopReg(2, 0x4000, 0x1000 - (int)*(short *)&pNVar30[6].next);
       setCopReg(2, 0x4800, (u_int)local_50);
       setCopReg(2, 0x5000, (u_int)local_4f);
       setCopReg(2, 0x5800, (u_int)local_4e);
       copFunction(2, 0x198003d);
       *puVar29 = (u_int)ot[local_34] & 0xffffff | 0xf000000;
       ot[local_34] = (u_long *)((u_int)puVar29 & 0xffffff);
       uVar23 = getCopReg(2, 0x4800);
       uVar24 = getCopReg(2, 0x5000);
       uVar26 = getCopReg(2, 0x5800);
       *(char *)(puVar29 + 0xb) = (char)uVar23;
       *(undefined *)((int)puVar29 + 0x2d) = (char)uVar24;
       *(undefined *)((int)puVar29 + 0x2e) = (char)uVar26;
       *(undefined *)((int)puVar29 + 0xb) = 0x3a;
       *(undefined *)((int)puVar29 + 0x2f) = 0x2a;
       puVar29 = puVar29 + 0x10;
     }
   }
 }
 else
 {
   if (((u_int)pNVar32 & 4) == 0)
   {
     pNVar18 = pNVar30[1].prev;
   }
   else
   {
     pNVar18 = pNVar30[0xd].prev;
   }
   if (((u_int)pNVar32 & 8) != 0)
   {
     bVar15 = *(byte *)&pNVar18->prev;
     bVar14 = *(byte *)&pNVar18->next;
     if (bVar15 < bVar14)
     {
       bVar4 = bVar14 < bVar15;
       if (*(byte *)&pNVar18[1].prev <= bVar15)
       {
       LAB_8004632c:
         bVar1 = *(byte *)&pNVar18[1].prev;
         goto LAB_80046330;
       }
       bVar1 = *(byte *)&pNVar18->prev;
     }
     else
     {
       if (*(byte *)&pNVar18[1].prev <= bVar14)
         goto LAB_8004632c;
       bVar1 = *(byte *)&pNVar18->next;
     LAB_80046330:
       bVar15 = *(byte *)&pNVar18->prev;
       bVar14 = *(byte *)&pNVar18->next;
       bVar4 = bVar14 < bVar15;
     }
     if (bVar4)
     {
       if (*(byte *)&pNVar18[1].prev < bVar15)
       {
         uVar20 = (u_short) * (byte *)&pNVar18->prev;
       }
       else
       {
       LAB_80046388:
         uVar20 = (u_short) * (byte *)&pNVar18[1].prev;
       }
     }
     else
     {
       if (bVar14 <= *(byte *)&pNVar18[1].prev)
         goto LAB_80046388;
       uVar20 = (u_short) * (byte *)&pNVar18->next;
     }
     bVar15 = *(byte *)((int)&pNVar18->prev + 1);
     bVar14 = *(byte *)((int)&pNVar18->next + 1);
     if (bVar15 < bVar14)
     {
       if (*(byte *)((int)&pNVar18[1].prev + 1) <= bVar15)
       {
       LAB_800463e4:
         bVar2 = *(byte *)((int)&pNVar18[1].prev + 1);
         goto LAB_800463f0;
       }
       bVar2 = *(byte *)((int)&pNVar18->prev + 1);
     }
     else
     {
       if (*(byte *)((int)&pNVar18[1].prev + 1) <= bVar14)
         goto LAB_800463e4;
       bVar2 = *(byte *)((int)&pNVar18->next + 1);
     LAB_800463f0:
       bVar15 = *(byte *)((int)&pNVar18->prev + 1);
       bVar14 = *(byte *)((int)&pNVar18->next + 1);
     }
     if (bVar14 < bVar15)
     {
       if (*(byte *)((int)&pNVar18[1].prev + 1) < bVar15)
       {
         uVar13 = (u_short) * (byte *)((int)&pNVar18->prev + 1) << 8;
       }
       else
       {
       LAB_80046448:
         uVar13 = (u_short) * (byte *)((int)&pNVar18[1].prev + 1) << 8;
       }
     }
     else
     {
       if (bVar14 <= *(byte *)((int)&pNVar18[1].prev + 1))
         goto LAB_80046448;
       uVar13 = (u_short) * (byte *)((int)&pNVar18->next + 1) << 8;
     }
     *(u_short *)(puVar29 + 3) = CONCAT11(bVar2, bVar1);
     *(u_short *)(puVar29 + 5) = uVar20 | (u_short)bVar2 << 8;
     *(u_short *)(puVar29 + 7) = bVar1 | uVar13;
     *(u_short *)(puVar29 + 9) = uVar20 | uVar13;
     *(undefined2 *)((int)puVar29 + 0xe) = *(undefined2 *)((int)&pNVar18->prev + 2);
     *(undefined2 *)((int)puVar29 + 0x16) = *(undefined2 *)((int)&pNVar18->next + 2);
 2);
 *(short *)(puVar29 + 6) = (short)local_48;
 *(short *)(puVar29 + 2) = (short)local_48;
 local_48._2_2_ = local_48._2_2_ + (short)(iVar25 - iVar6 >> 1);
 *(short *)((int)puVar29 + 0x12) = local_48._2_2_;
 *(short *)((int)puVar29 + 10) = local_48._2_2_;
 *(short *)((int)puVar29 + 0x22) = local_48._2_2_ - sVar7;
 *(short *)((int)puVar29 + 0x1a) = local_48._2_2_ - sVar7;
 *(short *)(puVar29 + 8) = *(short *)(puVar29 + 2) - (short)local_30;
 *(short *)(puVar29 + 4) = *(short *)(puVar29 + 2) - (short)local_30;
 if (((u_int)pNVar32 & 0x1000) != 0)
 {
   bVar14 = *(byte *)(puVar29 + 3) ^ *(byte *)(puVar29 + 5);
   *(byte *)(puVar29 + 3) = bVar14;
   bVar14 = bVar14 ^ *(byte *)(puVar29 + 5);
   bVar15 = *(byte *)(puVar29 + 7) ^ *(byte *)(puVar29 + 9);
   *(byte *)(puVar29 + 7) = bVar15;
   bVar15 = bVar15 ^ *(byte *)(puVar29 + 9);
   *(byte *)(puVar29 + 5) = bVar14;
   *(byte *)(puVar29 + 9) = bVar15;
   *(byte *)(puVar29 + 3) = *(byte *)(puVar29 + 3) ^ bVar14;
   *(byte *)(puVar29 + 7) = *(byte *)(puVar29 + 7) ^ bVar15;
 }
 *(NodeType **)(puVar29 + 1) = pNVar30[3].next;
 puVar29 = puVar29 + 10;
 puVar10 = (u_long *)((u_int)puVar28 & 0xffffff);
 *puVar28 = (u_int)ot[local_34] & 0xffffff | 0x9000000;
 puVar28 = puVar28 + 10;
 ot[local_34] = puVar10;
   }
 }
 goto joined_r0x80045e0c;
      }
    }
    if (((u_int)pNVar32 & 0x400000) == 0)
    {
      if (((u_int)pNVar32 & 0x800000) != 0)
      {
        *(undefined2 *)((int)&pNVar30[8].prev + 2) = 9999;
      }
    }
    else
    {
      pNVar30[2].prev = (NodeType *)0x1;
    }
  } while (true);
}

void FX_SimpleQuadSetup(_FX_PRIM *fxPrim, TDRFuncPtr_FX_SimpleQuadSetup1fxProcess fxProcess,
                        _FX_MATRIX *fxMatrix, _Instance *instance, _MFace *mface, _MVertex *vertexList,
                        SVECTOR *center, SVECTOR *vel, SVECTOR *accl, _FXTracker *fxTracker,
                        int timeToLive)

{
  short sVar1;
  short sVar2;
  TextureMT3 *pTVar3;
  u_int uVar4;
  u_int uVar5;

  MATH3D_SetUnityMatrix(&fxMatrix->lwTransform);
  sVar1 = center->vy;
  sVar2 = center->vz;
  (fxPrim->position).x = center->vx;
  (fxPrim->position).y = sVar1;
  (fxPrim->position).z = sVar2;
  sVar1 = (vertexList->vertex).y;
  sVar2 = (vertexList->vertex).z;
  (fxPrim->v0).x = (vertexList->vertex).x;
  (fxPrim->v0).y = sVar1;
  (fxPrim->v0).z = sVar2;
  sVar1 = vertexList[1].vertex.y;
  sVar2 = vertexList[1].vertex.z;
  (fxPrim->v1).x = vertexList[1].vertex.x;
  (fxPrim->v1).y = sVar1;
  (fxPrim->v1).z = sVar2;
  sVar1 = vertexList[3].vertex.y;
  sVar2 = vertexList[3].vertex.z;
  (fxPrim->v2).x = vertexList[3].vertex.x;
  (fxPrim->v2).y = sVar1;
  (fxPrim->v2).z = sVar2;
  sVar1 = vertexList[2].vertex.y;
  sVar2 = vertexList[2].vertex.z;
  (fxPrim->v3).x = vertexList[2].vertex.x;
  (fxPrim->v3).y = sVar1;
  (fxPrim->v3).z = sVar2;
  uVar4 = fxPrim->flags;
  fxPrim->flags = uVar4 | 8;
  if ((mface->flags & 2) == 0)
  {
    fxPrim->flags = uVar4 & 0xfffffffe | 8;
    uVar4 = mface->color;
    uVar5 = 0x28000000;
  }
  else
  {
    fxPrim->flags = uVar4 | 9;
    pTVar3 = (TextureMT3 *)mface->color;
    fxPrim->texture = pTVar3;
    uVar4 = pTVar3->color;
    uVar5 = 0x2c000000;
  }
  fxPrim->color = uVar4 & 0x3ffffff | uVar5;
  if (fxProcess == (TDRFuncPtr_FX_SimpleQuadSetup1fxProcess)0x0)
  {
    *(code **)&fxPrim->process = FX_StandardProcess;
  }
  else
  {
    *(TDRFuncPtr_FX_SimpleQuadSetup1fxProcess *)&fxPrim->process = fxProcess;
  }
  fxPrim->matrix = fxMatrix;
  if (vel == (SVECTOR *)0x0)
  {
    *(undefined2 *)&fxPrim->duo = 0;
    *(undefined2 *)((int)&fxPrim->duo + 2) = 0;
    *(undefined2 *)((int)&fxPrim->duo + 4) = 0;
  }
  else
  {
    *(short *)&fxPrim->duo = vel->vx;
    *(short *)((int)&fxPrim->duo + 2) = vel->vy;
    *(short *)((int)&fxPrim->duo + 4) = vel->vz;
  }
  if (accl == (SVECTOR *)0x0)
  {
    *(undefined2 *)((int)&fxPrim->duo + 6) = 0;
    *(undefined2 *)((int)&fxPrim->duo + 8) = 0;
    *(undefined2 *)((int)&fxPrim->duo + 10) = 0;
  }
  else
  {
    *(short *)((int)&fxPrim->duo + 6) = accl->vx;
    *(short *)((int)&fxPrim->duo + 8) = accl->vy;
    *(short *)((int)&fxPrim->duo + 10) = accl->vz;
  }
  fxPrim->timeToLive = (int)(short)timeToLive;
  fxPrim->flags = fxPrim->flags | 0x4000;
  return;
}

void FX_WaterRingProcess(_FX_PRIM *fxPrim, _FXTracker *fxTracker)

{
  short sVar1;

  (fxPrim->v0).x = (fxPrim->v0).x + -8;
  sVar1 = (fxPrim->v1).x;
  (fxPrim->v0).y = (fxPrim->v0).y + -8;
  (fxPrim->v1).x = sVar1 + 8;
  sVar1 = (fxPrim->v2).x;
  (fxPrim->v1).y = (fxPrim->v1).y + -8;
  (fxPrim->v2).x = sVar1 + -8;
  sVar1 = (fxPrim->v3).x;
  (fxPrim->v2).y = (fxPrim->v2).y + 8;
  (fxPrim->v3).x = sVar1 + 8;
  (fxPrim->v3).y = (fxPrim->v3).y + 8;
  FX_StandardFXPrimProcess(fxPrim, fxTracker);
  return;
}

void FX_WaterBubbleProcess(_FX_PRIM *fxPrim, _FXTracker *fxTracker)

{
  short sVar1;
  u_short uVar2;
  u_short uVar3;
  short sVar4;
  int iVar5;

  if (*(short *)((int)&fxPrim->duo + 4) < fxPrim->work1)
  {
    *(short *)((int)&fxPrim->duo + 4) =
        *(short *)((int)&fxPrim->duo + 4) + *(short *)((int)&fxPrim->duo + 10);
  }
  if (fxPrim->work0 < *(short *)((int)&fxPrim->duo + 6))
  {
    sVar1 = *(short *)((int)&fxPrim->duo + 2);
    (fxPrim->position).x = (fxPrim->position).x + *(short *)&fxPrim->duo;
    (fxPrim->position).y = (fxPrim->position).y + sVar1;
  }
  uVar2 = fxPrim->work2;
  iVar5 = (u_int)(u_short)fxPrim->work0 + 1;
  uVar3 = fxPrim->work3;
  (fxPrim->position).z = (fxPrim->position).z + *(short *)((int)&fxPrim->duo + 4);
  sVar1 = *(short *)((int)&fxPrim->duo + 8);
  fxPrim->work0 = (short)iVar5;
  iVar5 = (u_int)uVar3 - iVar5 * (u_int)uVar2;
  sVar4 = (short)iVar5;
  (fxPrim->v2).y = sVar4;
  (fxPrim->v0).y = sVar4;
  if ((iVar5 * 0x10000 >> 0x10 < (int)sVar1) || (fxPrim->timeToLive < (int)(fxPrim->position).z))
  {
    FX_Dot(fxPrim, fxTracker);
  }
  return;
}

void FX_Sprite_Insert(NodeType *list, _FX_PRIM *fxPrim)

{
  LIST_GetFunc(list, (NodeType *)fxPrim);
  if (FX_LastUsedPrim == (_FX_PRIM *)0x0)
  {
    FX_LastUsedPrim = fxPrim;
  }
  return;
}

TextureMT3 *FX_GetTextureObject(Object *object, int modelnum, int texnum)

{
  object->oflags2 = object->oflags2 | 0x20000000;
  return (TextureMT3 *)(object->modelList[modelnum]->faceList[1].color + texnum * 0x10 + 0x10);
}

void FX_MakeWaterBubble(_SVector *position, _SVector *vel, _SVector *accl, long splashZ,
                        __BubbleParams *BP)

{
  return;
}

void FX_DrawScreenPoly(int transtype, u_long color, int zdepth)

{
  u_long **ppuVar1;
  u_long *puVar2;

  ppuVar1 = gameTrackerX.drawOT;
  puVar2 = (gameTrackerX.primPool)->nextPrim;
  if (puVar2 + 7 < (gameTrackerX.primPool)->lastPrim)
  {
    *(undefined2 *)((int)puVar2 + 0x16) = 0xf0;
    *(undefined2 *)((int)puVar2 + 0x1a) = 0xf0;
    puVar2[1] = transtype << 5 | 0xe1000600;
    *(undefined2 *)(puVar2 + 3) = 0;
    *(undefined2 *)((int)puVar2 + 0xe) = 0;
    *(undefined2 *)(puVar2 + 4) = 0x200;
    *(undefined2 *)((int)puVar2 + 0x12) = 0;
    *(undefined2 *)(puVar2 + 5) = 0;
    *(undefined2 *)(puVar2 + 6) = 0x200;
    puVar2[2] = color;
    *(undefined *)((int)puVar2 + 0xb) = 0x2a;
    *puVar2 = (u_int)ppuVar1[zdepth] & 0xffffff | 0x6000000;
    ppuVar1[zdepth] = (u_long *)((u_int)puVar2 & 0xffffff);
    (gameTrackerX.primPool)->nextPrim = puVar2 + 7;
  }
  return;
}

POLY_GT4 *
FX_SetupPolyGT4(int x1, int y1, int x2, int y2, int otz, TextureMT3 *texture, long color0, long color1,
                long color2, long color3)

{
  undefined2 uVar1;
  u_long **ppuVar2;
  POLY_GT4 *pPVar3;

  ppuVar2 = gameTrackerX.drawOT;
  pPVar3 = (POLY_GT4 *)(gameTrackerX.primPool)->nextPrim;
  if ((POLY_GT4 *)(gameTrackerX.primPool)->lastPrim <= pPVar3 + 1)
  {
    return (POLY_GT4 *)0x0;
  }
  *(undefined2 *)&pPVar3->u0 = *(undefined2 *)&texture->u2;
  *(undefined2 *)&pPVar3->u1 = *(undefined2 *)&texture->u1;
  uVar1 = *(undefined2 *)texture;
  pPVar3->x2 = (short)x1;
  pPVar3->x0 = (short)x1;
  pPVar3->x1 = (short)x2;
  pPVar3->x3 = (short)x2;
  pPVar3->y1 = (short)y1;
  pPVar3->y0 = (short)y1;
  pPVar3->y2 = (short)y2;
  pPVar3->y3 = (short)y2;
  *(undefined2 *)&pPVar3->u2 = uVar1;
  *(u_int *)&pPVar3->r0 = color0 | 0x3c000000;
  *(long *)&pPVar3->r1 = color1;
  *(long *)&pPVar3->r2 = color2;
  pPVar3->u3 = pPVar3->u1;
  pPVar3->v3 = pPVar3->v2;
  *(long *)&pPVar3->r3 = color3;
  pPVar3->tpage = texture->tpage;
  pPVar3->clut = texture->clut;
  if (otz < 1)
  {
    otz = 1;
  }
  pPVar3->tag = (u_int)ppuVar2[otz] & 0xffffff | 0xc000000;
  ppuVar2[otz] = (u_long *)((u_int)pPVar3 & 0xffffff);
  *(POLY_GT4 **)&(gameTrackerX.primPool)->nextPrim = pPVar3 + 1;
  return pPVar3;
}

void FX_MakeWarpArrow(int x, int y, int xsize, int ysize, int fade)

{
  return;
}

void FX_MakeMannaIcon(int x, int y, int xsize, int ysize)

{
  return;
}

void FX_MakeGlyphIcon(_Position *position, Object *glyphObject, int size, int glyphnum, int enabled)

{
  short sVar1;
  short sVar2;
  int iVar3;
  TextureMT3 *texture;
  undefined *color3;
  POLY_GT4 *pPVar4;
  u_char *puVar5;
  int iVar6;
  int x1;
  int y1;
  undefined *local_38;
  undefined *local_34;
  undefined *local_30;

  if ((glyphObject != (Object *)0x0) && (glyphnum != 7))
  {
    texture = FX_GetTextureObject(glyphObject, 0, glyphnum);
    sVar1 = position->x;
    iVar6 = -size + 0x18;
    sVar2 = position->y;
    0x140;
    if (iVar6 < 0)
    {
      iVar6 = -size + 0x1b;
    }
    if (enabled == 0)
    {
      color3 = &LAB_00202020;
      x1 = sVar1 - iVar3;
      y1 = sVar2 - size;
      local_38 = &LAB_00202020;
      local_34 = &LAB_00202020;
      local_30 = &LAB_00202020;
    }
    else
    {
      puVar5 = (u_char *)((int)glyphObject->data + glyphnum * 0x10 + 0x1c);
      x1 = sVar1 - iVar3;
      y1 = sVar2 - size;
      local_38 = (undefined *)*puVar5;
      local_34 = (undefined *)puVar5[1];
      local_30 = (undefined *)puVar5[2];
      color3 = (undefined *)puVar5[3];
    }
    pPVar4 = FX_SetupPolyGT4(x1, y1, sVar1 + iVar3 + 1, sVar2 + size + 1, (iVar6 >> 2) + 1, texture,
                             (long)local_38, (long)local_34, (long)local_30, (long)color3);
    if (pPVar4 != (POLY_GT4 *)0x0)
    {
      pPVar4->code = *(byte *)((int)&texture->color + 3) & 3 | 0x3c;
    }
  }
  return;
}

void FX_SoulDustProcess(_FX_PRIM *fxPrim, _FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  u_char local_10;
  u_char local_c;

  if (fxPrim->work1 < 0x20)
  {
    FX_Dot(fxPrim, fxTracker);
  }
  else
  {
    sVar2 = fxPrim->work2;
    iVar3 = *(int *)(*(int *)&fxPrim->duo + 0x40) + *(int *)((int)&fxPrim->duo + 4) * 0x20;
    (fxPrim->position).x = *(short *)(iVar3 + 0x14);
    sVar2 = (fxPrim->v1).x + sVar2;
    (fxPrim->position).y = *(short *)(iVar3 + 0x18);
    sVar1 = *(short *)(iVar3 + 0x1c);
    (fxPrim->v1).x = sVar2;
    (fxPrim->position).z = sVar1;
    iVar3 = rcos((int)sVar2);
    iVar3 = iVar3 * fxPrim->work1;
    if (iVar3 < 0)
    {
      iVar3 = iVar3 + 0xfff;
    }
    (fxPrim->position).x = (fxPrim->position).x + (short)(iVar3 >> 0xc);
    iVar3 = rsin((int)(fxPrim->v1).x);
    iVar3 = iVar3 * fxPrim->work1;
    if (iVar3 < 0)
    {
      iVar3 = iVar3 + 0xfff;
    }
    (fxPrim->position).y = (fxPrim->position).y + (short)(iVar3 >> 0xc);
    iVar3 = rcos((int)(fxPrim->v1).y);
    iVar3 = iVar3 * fxPrim->work0;
    if (iVar3 < 0)
    {
      iVar3 = iVar3 + 0xfff;
    }
    local_10 = 0x60ff60;
    local_c = 0;
    sVar2 = (fxPrim->v2).x;
    (fxPrim->v0).y = (fxPrim->v0).y + -0x90;
    iVar4 = (int)(fxPrim->v0).y;
    (fxPrim->position).z = (fxPrim->position).z + (short)(iVar3 >> 0xc);
    sVar1 = (fxPrim->v1).y;
    fxPrim->work1 = fxPrim->work1 - sVar2;
    (fxPrim->v1).y = sVar1 + 0x40;
    if (iVar4 < 0)
    {
      iVar4 = 0;
    }
    LoadAverageCol((byte *)&local_10, (byte *)&local_c, 0x1000 - iVar4, iVar4,
                   (undefined *)&fxPrim->color);
    fxPrim->color = fxPrim->color & 0xffffffU | 0x2e000000;
  }
  return;
}

void FX_MakeSoulDust(_Instance *instance, short segment)

{
  rand();
  return;
}

void FX_WaterTrailProcess(_FX_PRIM *fxPrim, _FXTracker *fxTracker)

{
  short sVar1;

  FX_StandardProcess(fxPrim, fxTracker);
  (fxPrim->v0).x = (short)((int)(fxPrim->v0).x * 7 >> 3);
  (fxPrim->v0).y = (short)((int)(fxPrim->v0).y * 7 >> 3);
  sVar1 = (fxPrim->v1).x;
  (fxPrim->v0).z = (short)((int)(fxPrim->v0).z * 7 >> 3);
  (fxPrim->v1).x = (short)((int)sVar1 * 7 >> 3);
  (fxPrim->v1).y = (short)((int)(fxPrim->v1).y * 7 >> 3);
  sVar1 = (fxPrim->v2).x;
  (fxPrim->v1).z = (short)((int)(fxPrim->v1).z * 7 >> 3);
  (fxPrim->v2).x = (short)((int)sVar1 * 7 >> 3);
  (fxPrim->v2).y = (short)((int)(fxPrim->v2).y * 7 >> 3);
  sVar1 = (fxPrim->v3).x;
  (fxPrim->v2).z = (short)((int)(fxPrim->v2).z * 7 >> 3);
  (fxPrim->v3).x = (short)((int)sVar1 * 7 >> 3);
  (fxPrim->v3).y = (short)((int)(fxPrim->v3).y * 7 >> 3);
  (fxPrim->v3).z = (short)((int)(fxPrim->v3).z * 7 >> 3);
  return;
}

void FX_MakeWaterTrail(_Instance *instance, int depth)

{
  short sVar1;
  short sVar2;
  u_int uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  _SVector local_28;
  _SVector local_20;
  _SVector local_18;

  if ((((instance->matrix != (MATRIX *)0x0) && (instance->oldMatrix != (MATRIX *)0x0)) &&
       (gameTrackerX.gameData.asmData.MorphType != 1)) &&
      (gameTrackerX.gameData.asmData.MorphTime == 1000))
  {
    sVar1 = *(short *)instance->matrix[1].t;
    sVar2 = *(short *)(instance->matrix[1].t + 1);
    local_18.z = (instance->splitPoint).z;
    iVar6 = instance->matrix[1].t[2] - instance->oldMatrix[1].t[2];
    if (iVar6 < 0)
    {
      iVar6 = -iVar6;
    }
    iVar7 = 0;
    if (0x14 < iVar6)
    {
      local_20.y = 0;
      local_20.x = 0;
      local_20.z = -2;
      do
      {
        uVar3 = rand();
        iVar6 = rcos(uVar3 & 0xfff);
        iVar4 = rsin(uVar3 & 0xfff);
        uVar3 = rand();
        iVar5 = (uVar3 & 3) + 0xb;
        iVar8 = iVar6 * iVar5;
        iVar5 = iVar4 * iVar5;
        if (iVar8 < 0)
        {
          iVar8 = iVar8 + 0xfff;
        }
        local_28.x = (short)(iVar8 >> 0xc);
        if (iVar5 < 0)
        {
          iVar5 = iVar5 + 0xfff;
        }
        local_28.y = (short)(iVar5 >> 0xc);
        local_28.z = 0x12;
        if (iVar6 < 0)
        {
          iVar6 = iVar6 + 0x7f;
        }
        local_18.x = sVar1 + (short)(iVar6 >> 7);
        if (iVar4 < 0)
        {
          iVar4 = iVar4 + 0x7f;
        }
        iVar7 = iVar7 + 1;
        local_18.y = sVar2 + (short)(iVar4 >> 7);
        FX_Die(&local_18, &local_28, &local_20, 0, 0x404040, 0x18, 0x14, 0);
      } while (iVar7 < 8);
      INSTANCE_Query(gameTrackerX.playerInstance, 0x40024, 0);
    }
  }
  return;
}

_FXRibbon *
FX_StartRibbon(_Instance *instance, short startSegment, short endSegment, short type, int ribbonLifeTime, int faceLifeTime, int startFadeValue, long startColor, long endColor)

{
  short sVar1;
  _FXRibbon *ptr;
  SVECTOR *pSVar2;
  int iVar3;
  MATRIX *pMVar4;
  short *psVar5;
  int iVar6;
  int iVar7;

  iVar7 = ((int)endSegment - (int)startSegment) + 1;
  if ((iVar7 < 2) || (ptr = (_FXRibbon *)MEMPACK_Malloc(0x2c, '\r'), ptr == (_FXRibbon *)0x0))
  {
    return (_FXRibbon *)0x0;
  }
  *(code **)&ptr->continue_process = FX_ContinueSnow;
  ptr->effectType = '\0';
  ptr->endIndex = 0;
  if (type == 1)
  {
    sVar1 = (short)iVar7 * 2;
  }
  else
  {
    sVar1 = 4;
  }
  ptr->numberVerts = sVar1;
  pSVar2 = (SVECTOR *)MEMPACK_Malloc((int)ptr->numberVerts << 3, '\r');
  ptr->vertexPool = pSVar2;
  if (pSVar2 == (SVECTOR *)0x0)
  {
    MEMPACK_Init((char *)ptr);
    return (_FXRibbon *)0x0;
  }
  ptr->faceLifeTime = (short)faceLifeTime;
  ptr->startSegment = startSegment;
  ptr->instance = instance;
  ptr->type = (u_char)type;
  ptr->lifeTime = (short)ribbonLifeTime;
  ptr->endSegment = endSegment;
  ptr->startColor = startColor;
  ptr->startFadeValue = (short)startFadeValue;
  ptr->endColor = endColor;
 (int)(short)faceLifeTime);
 (int)ptr->faceLifeTime);
 ptr->fadeStep = sVar1;
 if ((type & 0xffU) == 2)
 {
   iVar3 = (int)sVar1 * 6;
   if (iVar3 < 0)
   {
     iVar3 = iVar3 + 7;
   }
   ptr->fadeStep = (short)(iVar3 >> 3);
 }
 pMVar4 = instance->matrix;
 if (pMVar4 == (MATRIX *)0x0)
 {
   sVar1 = -1;
 }
 else
 {
   iVar3 = (int)((u_int)(u_short)startSegment << 0x10) >> 0xb;
   if (ptr->type == '\x01')
   {
     if (0 < iVar7)
     {
       psVar5 = (short *)((int)pMVar4->t + iVar3 + 8);
       iVar3 = 0;
       do
       {
         iVar6 = iVar3 + 1;
         ptr->vertexPool[iVar3].vx = psVar5[-4];
         ptr->vertexPool[iVar3].vy = psVar5[-2];
         ptr->vertexPool[iVar3].vz = *psVar5;
         ptr->endIndex = ptr->endIndex + 1;
         psVar5 = psVar5 + 0x10;
         iVar3 = iVar6;
       } while (iVar6 < iVar7);
     }
     goto LAB_80047ba8;
   }
   iVar3 = (int)pMVar4->m + iVar3;
   ptr->vertexPool->vx = *(short *)(iVar3 + 0x14);
   ptr->vertexPool->vy = *(short *)(iVar3 + 0x18);
   ptr->vertexPool->vz = *(short *)(iVar3 + 0x1c);
   iVar7 = (int)instance->matrix->m + ((int)((u_int)(u_short)endSegment << 0x10) >> 0xb);
   ptr->vertexPool[1].vx = *(short *)(iVar7 + 0x14);
   ptr->vertexPool[1].vy = *(short *)(iVar7 + 0x18);
   ptr->vertexPool[1].vz = *(short *)(iVar7 + 0x1c);
   sVar1 = 2;
 }
 ptr->endIndex = sVar1;
LAB_80047ba8:
  FX_InsertGeneralEffect(ptr);
  return ptr;
}

void FX_RibbonProcess(_FX_PRIM *fxPrim, _FXTracker *fxTracker)

{
  short sVar1;
  _FX_PRIM *p_Var2;
  int iVar3;

  if (0 < fxPrim->timeToLive)
  {
    fxPrim->timeToLive = fxPrim->timeToLive + -1;
  }
  if (fxPrim->timeToLive == 0)
  {
    FX_Dot(fxPrim, fxTracker);
  }
  else
  {
    iVar3 = 0;
    p_Var2 = fxPrim;
    do
    {
      sVar1 = p_Var2->fadeValue[0] + fxPrim->fadeStep;
      p_Var2->fadeValue[0] = sVar1;
      if (0x1000 < sVar1)
      {
        p_Var2->fadeValue[0] = 0x1000;
      }
      iVar3 = iVar3 + 1;
      p_Var2 = (_FX_PRIM *)((int)&(p_Var2->node).prev + 2);
    } while (iVar3 < 4);
    if (fxPrim->startColor != fxPrim->endColor)
    {
      sVar1 = fxPrim->colorFadeValue + fxPrim->colorFadeStep;
      fxPrim->colorFadeValue = sVar1;
      if (0x1000 < sVar1)
      {
        fxPrim->colorFadeValue = 0x1000;
      }
      LoadAverageCol((byte *)&fxPrim->startColor, (byte *)&fxPrim->endColor,
                     0x1000 - (int)fxPrim->colorFadeValue, (int)fxPrim->colorFadeValue,
                     (undefined *)&fxPrim->color);
    }
  }
  return;
}

void FX_StartConstrict(_FX_PRIM *fxPrim, _FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;

  if (FX_ConstrictStage == 1)
  {
    fxPrim->startColor = 0xffffff;
    sVar3 = fxPrim->work2;
    fxPrim->timeToLive = 0x28;
    fxPrim->fadeStep = 0x66;
    fxPrim->fadeValue[3] = 0;
    fxPrim->fadeValue[2] = 0;
    fxPrim->fadeValue[1] = 0;
    fxPrim->fadeValue[0] = 0;
    fxPrim->work1 = 0x380;
    fxPrim->work0 = 0x380;
    fxPrim->work1 = 0;
    if (sVar3 == 0)
    {
      sVar3 = (fxPrim->v0).y;
      fxPrim->fadeValue[1] = 0;
      fxPrim->fadeValue[0] = 0;
      fxPrim->fadeValue[3] = 0x1000;
      fxPrim->fadeValue[2] = 0x1000;
      iVar4 = ratan2((int)sVar3 - (int)FX_ConstrictPosition.y,
                     (int)(fxPrim->v0).x - (int)FX_ConstrictPosition.x);
      sVar3 = (fxPrim->v1).y;
      fxPrim->work2 = (short)iVar4;
      iVar4 = ratan2((int)sVar3 - (int)FX_ConstrictPosition.y,
                     (int)(fxPrim->v1).x - (int)FX_ConstrictPosition.x);
      sVar3 = (fxPrim->v2).z;
      sVar2 = (fxPrim->v0).z;
      sVar1 = (fxPrim->v0).z;
      fxPrim->work3 = (short)iVar4;
      iVar4 = (int)sVar3 - (int)sVar2;
      if (iVar4 < 0)
      {
        iVar4 = iVar4 + 3;
      }
      (fxPrim->v2).z = sVar1 + (short)(iVar4 >> 2);
      (fxPrim->v3).z = (fxPrim->v1).z + ((fxPrim->v3).z - (fxPrim->v1).z) * 3;
    }
    else
    {
      sVar3 = (fxPrim->v2).y;
      fxPrim->fadeValue[1] = 0x1000;
      fxPrim->fadeValue[0] = 0x1000;
      fxPrim->fadeValue[3] = 0;
      fxPrim->fadeValue[2] = 0;
      iVar4 = ratan2((int)sVar3 - (int)FX_ConstrictPosition.y,
                     (int)(fxPrim->v2).x - (int)FX_ConstrictPosition.x);
      sVar3 = (fxPrim->v3).y;
      fxPrim->work2 = (short)iVar4;
      iVar4 = ratan2((int)sVar3 - (int)FX_ConstrictPosition.y,
                     (int)(fxPrim->v3).x - (int)FX_ConstrictPosition.x);
      sVar3 = (fxPrim->v0).z;
      sVar2 = (fxPrim->v2).z;
      sVar1 = (fxPrim->v2).z;
      fxPrim->work3 = (short)iVar4;
      iVar4 = (int)sVar3 - (int)sVar2;
      if (iVar4 < 0)
      {
        iVar4 = iVar4 + 3;
      }
      (fxPrim->v0).z = sVar1 + (short)(iVar4 >> 2);
      (fxPrim->v1).z = (fxPrim->v3).z + ((fxPrim->v1).z - (fxPrim->v3).z) * 3;
    }
    sVar3 = FX_ConstrictPosition.x;
    (fxPrim->v1).x = FX_ConstrictPosition.x;
    (fxPrim->v3).x = sVar3;
    sVar3 = FX_ConstrictPosition.y;
    (fxPrim->v1).y = FX_ConstrictPosition.y;
    (fxPrim->v3).y = sVar3;
  }
  else
  {
    if ((0 < fxPrim->work0) || (0 < fxPrim->work1))
    {
      fxPrim->work0 = fxPrim->work0 + -0x28;
      sVar3 = fxPrim->work2 + -0x40;
      fxPrim->work2 = sVar3;
      iVar4 = rcos((int)sVar3);
      sVar3 = fxPrim->work2;
      sVar2 = FX_ConstrictPosition.x + (short)(fxPrim->work0 * iVar4 >> 0xc);
      (fxPrim->v0).x = sVar2;
      (fxPrim->v2).x = sVar2;
      iVar4 = rsin((int)sVar3);
      sVar3 = FX_ConstrictPosition.y + (short)(fxPrim->work0 * iVar4 >> 0xc);
      (fxPrim->v0).y = sVar3;
      (fxPrim->v2).y = sVar3;
    }
  }
  FX_RibbonProcess(fxPrim, fxTracker);
  return;
}

void FX_StartConstrict(_Instance *instance, _SVector *constrict_point, short startSegment,
                       short endSegment)

{
  if (FX_ConstrictRibbon == (_FXRibbon *)0x0)
  {
    if (constrict_point != (_SVector *)0x0)
    {
      FX_ConstrictPosition.x = constrict_point->x;
      FX_ConstrictPosition.y = constrict_point->y;
      FX_ConstrictPosition.z = (instance->position).z + 0x100;
      FX_ConstrictPositionPtr = (_Position *)constrict_point;
    }
    FX_ConstrictRibbon =
        FX_StartRibbon(instance, startSegment, endSegment, 2, -1, 0x28, 0, 0xe84040, 0xe84040);
    FX_ConstrictStage = 0;
  }
  return;
}

void FX_EndConstrict(int ConstrictEnemyFlag, _Instance *instance)

{
  _Position *p_Var1;

  if (ConstrictEnemyFlag != 0)
  {
    FX_ConstrictStage = 1;
    if (instance == (_Instance *)0x0)
    {
      FX_ConstrictPosition.x = FX_ConstrictPositionPtr->x;
      p_Var1 = FX_ConstrictPositionPtr;
    }
    else
    {
      FX_ConstrictPosition.x = (instance->position).x;
      p_Var1 = &instance->position;
    }
    FX_ConstrictPosition.y = p_Var1->y;
    FX_ConstrictPosition.z = p_Var1->z;
    FX_ConstrictInstance = instance;
  }
  FX_DeleteGeneralEffect((_FXGeneralEffect *)FX_ConstrictRibbon);
  FX_ConstrictRibbon = (_FXRibbon *)0x0;
  return;
}

void FX_SubDividePrim(_FX_PRIM *fxPrim1, _FX_PRIM *fxPrim2)

{
  u_int local_20;
  short local_1c;
  u_int local_18;
  short local_14;

  LoadAverageShort12((u_int *)&fxPrim1->v0, (u_int *)&fxPrim2->v2, 0x800, 0x800, &local_20);
  LoadAverageShort12((u_int *)&fxPrim1->v1, (u_int *)&fxPrim2->v3, 0x800, 0x800, &local_18);
  *(u_int *)&fxPrim1->v2 = local_20;
  (fxPrim1->v2).z = local_1c;
  *(u_int *)&fxPrim1->v3 = local_18;
  (fxPrim1->v3).z = local_14;
  *(u_int *)&fxPrim2->v0 = local_20;
  (fxPrim2->v0).z = local_1c;
  *(u_int *)&fxPrim2->v1 = local_18;
  (fxPrim2->v1).z = local_14;
  return;
}

void FX_ContinueSnow(_FXRibbon *ribbon, _FXTracker *fxTracker)

{
  int iVar1;
  u_char *puVar2;
  _FX_PRIM *fxPrim1;
  long lVar3;
  code *pcVar4;
  _FX_PRIM *fxPrim2;
  _FX_PRIM *p_Var5;
  short sVar6;
  MATRIX *pMVar7;
  int iVar8;
  _FX_PRIM *p_Var9;
  long *plVar10;
  int iVar11;
  NodeType *pNVar12;
  TextureMT3 *pTVar13;
  u_char uVar14;
  u_char uVar15;
  u_char uVar16;
  u_char uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  u_char local_50;
  u_char local_4c;
  short local_44;
  short local_3c;
  u_char local_38;
  u_char local_34;

  if ((ribbon != (_FXRibbon *)0x0) && (pMVar7 = ribbon->instance->matrix, pMVar7 != (MATRIX *)0x0))
  {
    iVar11 = (int)ribbon->endIndex;
    pMVar7 = pMVar7 + ribbon->startSegment;
    if (iVar11 == -1)
    {
      ribbon->endIndex = 0;
    }
    iVar1 = (u_int)(u_short)ribbon->numberVerts << 0x10;
    iVar1 = (iVar1 >> 0x10) - (iVar1 >> 0x1f) >> 1;
    if (ribbon->type == '\x01')
    {
      sVar6 = ribbon->endIndex;
      plVar10 = pMVar7->t + 2;
      iVar20 = (int)sVar6;
      while (iVar20 < (int)sVar6 + iVar1)
      {
        ribbon->vertexPool[iVar20].vx = *(short *)(plVar10 + -2);
        ribbon->vertexPool[iVar20].vy = *(short *)(plVar10 + -1);
        ribbon->vertexPool[iVar20].vz = *(short *)plVar10;
        ribbon->endIndex = ribbon->endIndex + 1;
        plVar10 = plVar10 + 8;
        iVar20 = iVar20 + 1;
      }
    }
    else
    {
      iVar20 = (int)ribbon->endIndex;
      iVar19 = iVar20 + 1;
      ribbon->vertexPool[iVar20].vx = *(short *)pMVar7->t;
      ribbon->vertexPool[iVar20].vy = *(short *)(pMVar7->t + 1);
      ribbon->vertexPool[iVar20].vz = *(short *)(pMVar7->t + 2);
      pMVar7 = ribbon->instance->matrix + ribbon->endSegment;
      ribbon->vertexPool[iVar19].vx = *(short *)pMVar7->t;
      ribbon->vertexPool[iVar19].vy = *(short *)(pMVar7->t + 1);
      ribbon->vertexPool[iVar19].vz = *(short *)(pMVar7->t + 2);
      ribbon->endIndex = ribbon->endIndex + 2;
    }
    iVar20 = (int)ribbon->endIndex;
    if (ribbon->numberVerts <= iVar20)
    {
      ribbon->endIndex = 0;
    }
    if (iVar11 == -1)
    {
      return;
    }
    if ((((ribbon->instance->flags & 0x800U) == 0) && ((ribbon->instance->flags2 & 0x4000000U) == 0)) && (iVar11 < iVar20 + -1))
    {
      iVar19 = iVar11 << 3;
      do
      {
        iVar8 = iVar11 - iVar1;
        if (iVar8 < 0)
        {
          iVar8 = iVar8 + ribbon->numberVerts;
        }
        puVar2 = (u_char *)((int)&ribbon->vertexPool->vx + iVar19);
        uVar14 = *(u_char *)(ribbon->vertexPool + iVar8);
        uVar16 = *(u_char *)&ribbon->vertexPool[iVar8].vz;
        iVar18 = 0;
        uVar15 = *(u_char *)(ribbon->vertexPool + iVar8 + 1);
        uVar17 = *(u_char *)&(ribbon->vertexPool + iVar8)[1].vz;
        iVar8 = (int)&ribbon->vertexPool->vx + iVar19;
        local_50 = *puVar2;
        local_4c = puVar2[1];
        local_38 = *(u_char *)(iVar8 + 8);
        local_34 = *(u_char *)(iVar8 + 0xc);
        do
        {
          fxPrim1 = FX_GetPrim(fxTracker);
          if (fxPrim1 != (_FX_PRIM *)0x0)
          {
            (fxPrim1->position).x = *(short *)((int)&ribbon->vertexPool->vx + iVar19);
            (fxPrim1->position).y = *(short *)((int)&ribbon->vertexPool->vy + iVar19);
            (fxPrim1->position).z = *(short *)((int)&ribbon->vertexPool->vz + iVar19);
            *(u_char *)&fxPrim1->v0 = local_50;
            (fxPrim1->v0).z = (short)local_4c;
            local_44 = (short)uVar16;
            *(u_char *)&fxPrim1->v1 = uVar14;
            (fxPrim1->v1).z = local_44;
            local_3c = (short)uVar17;
            *(u_char *)&fxPrim1->v3 = uVar15;
            (fxPrim1->v3).z = local_3c;
            *(u_char *)&fxPrim1->v2 = local_38;
            (fxPrim1->v2).z = (short)local_34;
            fxPrim1->fadeValue[0] = ribbon->startFadeValue;
            fxPrim1->fadeValue[1] = ribbon->startFadeValue;
            fxPrim1->fadeValue[2] = ribbon->startFadeValue + ribbon->fadeStep;
            fxPrim1->fadeValue[3] = ribbon->startFadeValue + ribbon->fadeStep;
            sVar6 = ribbon->fadeStep;
            fxPrim1->flags = fxPrim1->flags & 0xfffffffeU | 0x90008;
            fxPrim1->fadeStep = sVar6;
            fxPrim1->color = ribbon->startColor;
            fxPrim1->startColor = ribbon->startColor;
            lVar3 = ribbon->endColor;
            fxPrim1->colorFadeValue = 0;
            fxPrim1->endColor = lVar3;
            fxPrim1->colorFadeStep = ribbon->colorStepValue;
            if (ribbon->type == '\x02')
            {
              pcVar4 = FX_StartConstrict;
            }
            else
            {
              pcVar4 = FX_RibbonProcess;
            }
            *(code **)&fxPrim1->process = pcVar4;
            fxPrim1->timeToLive = (int)ribbon->faceLifeTime;
            LIST_GetFunc(&fxTracker->usedPrimList, (NodeType *)fxPrim1);
            fxPrim2 = FX_GetPrim(fxTracker);
            if (fxPrim2 != (_FX_PRIM *)0x0)
            {
              p_Var5 = fxPrim1;
              p_Var9 = fxPrim2;
              do
              {
                pNVar12 = (p_Var5->node).next;
                pTVar13 = p_Var5->texture;
                lVar3 = p_Var5->flags;
                (p_Var9->node).prev = (p_Var5->node).prev;
                (p_Var9->node).next = pNVar12;
                p_Var9->texture = pTVar13;
                p_Var9->flags = lVar3;
                p_Var5 = (_FX_PRIM *)&p_Var5->timeToLive;
                p_Var9 = (_FX_PRIM *)&p_Var9->timeToLive;
              } while (p_Var5 != (_FX_PRIM *)&(fxPrim1->ani).curFrame);
              (p_Var9->node).prev = (p_Var5->node).prev;
              FX_SubDividePrim(fxPrim1, fxPrim2);
              sVar6 = 0x1000;
              if (ribbon->type == '\x02')
              {
                sVar6 = 0x800;
                fxPrim2->work0 = 0;
                fxPrim1->work0 = 0;
                fxPrim2->work1 = 0;
                fxPrim1->work1 = 0;
                fxPrim1->work2 = 1;
                fxPrim2->work2 = 0;
              }
              fxPrim1->fadeValue[0] = sVar6;
              fxPrim1->fadeValue[1] = sVar6;
              fxPrim2->fadeValue[2] = sVar6;
              fxPrim2->fadeValue[3] = sVar6;
              LIST_GetFunc(&fxTracker->usedPrimList, (NodeType *)fxPrim2);
            }
          }
          iVar18 = iVar18 + 0x1000;
          local_50 = uVar14;
          local_4c = uVar16;
          local_38 = uVar15;
          local_34 = uVar17;
        } while (iVar18 < 0x1000);
        iVar11 = iVar11 + 1;
        iVar19 = iVar19 + 8;
      } while (iVar11 < iVar20 + -1);
    }
  }
  sVar6 = ribbon->lifeTime;
  if ((0 < ribbon->lifeTime) && (ribbon->lifeTime = sVar6 + -1, sVar6 == 1))
  {
    FX_DeleteGeneralEffect((_FXGeneralEffect *)ribbon);
  }
  return;
}

void FX_StandardFXPrimProcess(_FX_PRIM *fxPrim, _FXTracker *fxTracker)

{
  char cVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  _FX_MATRIX *p_Var7;
  u_int uVar8;
  u_int uVar9;
  u_int uVar10;
  u_char uVar11;
  u_char uVar12;
  u_char uVar13;

  iVar6 = fxPrim->timeToLive;
  if (0 < iVar6)
  {
    fxPrim->timeToLive = iVar6 + -1;
    iVar6 = fxPrim->timeToLive;
  }
  if (iVar6 == 0)
  {
  LAB_80048848:
    FX_Dot(fxPrim, fxTracker);
  }
  else
  {
    uVar10 = fxPrim->flags;
    if ((uVar10 & 0x40000) != 0)
    {
      uVar8 = fxPrim->startColor;
      uVar9 = fxPrim->endColor;
      sVar5 = fxPrim->fadeValue[0] + fxPrim->fadeStep;
      fxPrim->fadeValue[0] = sVar5;
      if (0x1000 < sVar5)
      {
        fxPrim->fadeValue[0] = 0x1000;
      }
      setCopReg(2, 0x4000, 0x1000 - (int)fxPrim->fadeValue[0]);
      setCopReg(2, 0x4800, uVar8 & 0xff);
      setCopReg(2, 0x5000, uVar8 >> 8 & 0xff);
      setCopReg(2, 0x5800, uVar8 >> 0x10 & 0xff);
      copFunction(2, 0x198003d);
      setCopReg(2, 0x4000, (u_int)(u_short)fxPrim->fadeValue[0]);
      setCopReg(2, 0x4800, uVar9 & 0xff);
      setCopReg(2, 0x5000, uVar9 >> 8 & 0xff);
      setCopReg(2, 0x5800, uVar9 >> 0x10 & 0xff);
      copFunction(2, 0x1a8003e);
      uVar11 = getCopReg(2, 0x4800);
      uVar12 = getCopReg(2, 0x5000);
      uVar13 = getCopReg(2, 0x5800);
      *(char *)&fxPrim->color = (char)uVar11;
      *(undefined *)((int)&fxPrim->color + 1) = (char)uVar12;
      *(undefined *)((int)&fxPrim->color + 2) = (char)uVar13;
      if ((uVar10 & 1) != 0)
      {
        fxPrim->color = fxPrim->color & 0x3ffffffU | 0x2c000000;
      }
    }
    if ((uVar10 & 0x2000) != 0)
    {
      iVar6 = (int)(fxPrim->v0).y - (int)fxPrim->work3;
      if (iVar6 < 1)
        goto LAB_80048848;
      (fxPrim->v0).y = (short)iVar6;
    }
    if ((uVar10 & 0x20) == 0)
    {
      if ((uVar10 & 2) == 0)
      {
        sVar5 = *(short *)((int)&fxPrim->duo + 8);
        sVar3 = *(short *)((int)&fxPrim->duo + 10);
        *(short *)&fxPrim->duo = *(short *)&fxPrim->duo + *(short *)((int)&fxPrim->duo + 6);
        *(short *)((int)&fxPrim->duo + 2) = *(short *)((int)&fxPrim->duo + 2) + sVar5;
        *(short *)((int)&fxPrim->duo + 4) = *(short *)((int)&fxPrim->duo + 4) + sVar3;
        if ((uVar10 & 0x1000000) == 0)
        {
          sVar5 = *(short *)((int)&fxPrim->duo + 2);
          sVar3 = *(short *)((int)&fxPrim->duo + 4);
          (fxPrim->position).x = (fxPrim->position).x + *(short *)&fxPrim->duo;
          (fxPrim->position).y = (fxPrim->position).y + sVar5;
          (fxPrim->position).z = (fxPrim->position).z + sVar3;
        }
        else
        {
          sVar5 = *(short *)&fxPrim->duo;
          (fxPrim->v0).x = (fxPrim->v0).x + sVar5;
          sVar3 = (fxPrim->v0).y;
          sVar4 = *(short *)((int)&fxPrim->duo + 2);
          (fxPrim->v1).x = (fxPrim->v1).x + sVar5;
          (fxPrim->v0).y = sVar3 + sVar4;
          sVar5 = (fxPrim->v0).z;
          sVar3 = *(short *)((int)&fxPrim->duo + 4);
          (fxPrim->v1).y = (fxPrim->v1).y + sVar4;
          (fxPrim->v0).z = sVar5 + sVar3;
          (fxPrim->v1).z = (fxPrim->v1).z + sVar3;
        }
        if (((uVar10 & 0x100) != 0) && ((fxPrim->position).z <= fxPrim->work0))
        {
          uVar8 = fxPrim->flags;
          (fxPrim->position).z = fxPrim->work0;
          fxPrim->flags = uVar8 | 2;
        }
      }
    }
    else
    {
      iVar6 = *(int *)(*(int *)&fxPrim->duo + 0x40) + *(int *)((int)&fxPrim->duo + 4) * 0x20;
      (fxPrim->position).x = *(short *)(iVar6 + 0x14);
      (fxPrim->position).y = *(short *)(iVar6 + 0x18);
      (fxPrim->position).z = *(short *)(iVar6 + 0x1c);
    }
    if (((((uVar10 & 0x8000000) == 0) && (p_Var7 = fxPrim->matrix, p_Var7 != (_FX_MATRIX *)0x0)) &&
         ((p_Var7->flags & 2U) == 0)) &&
        (p_Var7->flags = p_Var7->flags | 2, (uVar10 & 0x80) != 0))
    {
      cVar1 = *(char *)&fxPrim->work3;
      cVar2 = *(char *)((int)&fxPrim->work3 + 1);
      RotMatrixZ((int)*(char *)((int)&fxPrim->work2 + 1) << 2, (int)&fxPrim->matrix->lwTransform);
      RotMatrix((int)(short)((int)cVar1 << 2), (u_int *)&fxPrim->matrix->lwTransform);
      RotMatrixX((int)(short)((int)cVar2 << 2), (u_int *)&fxPrim->matrix->lwTransform);
    }
  }
  return;
}

void FX_AttachedParticlePrimProcess(_FX_PRIM *fxPrim, _FXTracker *fxTracker)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;

  iVar1 = (int)fxPrim->work0 * 0x20;
  iVar3 = *(int *)(fxPrim->matrix[1].lwTransform.m + 4);
  iVar2 = *(int *)(fxPrim->matrix[1].lwTransform.m + 6);
  iVar4 = iVar3 + iVar1;
  iVar1 = iVar2 + iVar1;
  if ((iVar3 != 0) && (iVar2 != 0))
  {
    (fxPrim->position).x =
        (fxPrim->position).x + (*(short *)(iVar4 + 0x14) - *(short *)(iVar1 + 0x14));
    (fxPrim->position).y =
        (fxPrim->position).y + (*(short *)(iVar4 + 0x18) - *(short *)(iVar1 + 0x18));
    (fxPrim->position).z =
        (fxPrim->position).z + (*(short *)(iVar4 + 0x1c) - *(short *)(iVar1 + 0x1c));
  }
  FX_StandardFXPrimProcess(fxPrim, fxTracker);
  return;
}

void FX_FlamePrimProcess(_FX_PRIM *fxPrim, _FXTracker *fxTracker)

{
  u_short uVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  short sVar6;
  short sVar7;

  iVar5 = *(int *)(fxPrim->matrix[1].lwTransform.m + 4);
  if ((iVar5 != 0) && (iVar3 = *(int *)(fxPrim->matrix[1].lwTransform.m + 6), iVar3 != 0))
  {
    iVar2 = (int)fxPrim->work0 * 0x20;
    iVar5 = iVar5 + iVar2;
    iVar3 = iVar3 + iVar2;
    iVar2 = (*(int *)(iVar5 + 0x14) - *(int *)(iVar3 + 0x14)) * 0x6e;
    if (iVar2 < 0)
    {
      iVar2 = iVar2 + 0x7f;
    }
    sVar6 = (short)(iVar2 >> 7);
    iVar2 = (*(int *)(iVar5 + 0x18) - *(int *)(iVar3 + 0x18)) * 0x6e;
    if (iVar2 < 0)
    {
      iVar2 = iVar2 + 0x7f;
    }
    sVar7 = (short)(iVar2 >> 7);
    iVar5 = (*(int *)(iVar5 + 0x1c) - *(int *)(iVar3 + 0x1c)) * 0x6e;
    if (iVar5 < 0)
    {
      iVar5 = iVar5 + 0x7f;
    }
    sVar4 = (short)(iVar5 >> 7);
    iVar5 = (int)sVar6;
    if (iVar5 < 0)
    {
      iVar5 = -iVar5;
    }
    iVar3 = (int)sVar7;
    if (iVar3 < 0)
    {
      iVar3 = -iVar3;
    }
    iVar2 = (int)sVar4;
    if (iVar2 < 0)
    {
      iVar2 = -iVar2;
    }
    iVar2 = iVar5 + iVar3 + iVar2;
    if (iVar2 != 0)
    {
      (fxPrim->position).x = (fxPrim->position).x + sVar6;
      (fxPrim->position).y = (fxPrim->position).y + sVar7;
      (fxPrim->position).z = (fxPrim->position).z + sVar4;
    }
    if (iVar2 < 0x29)
    {
      *(undefined2 *)((int)&fxPrim->duo + 10) = 1;
    }
    else
    {
      uVar1 = (fxPrim->v0).y;
      *(undefined2 *)((int)&fxPrim->duo + 10) = 0;
      2;
      (fxPrim->v0).y = (short)iVar5;
      if (iVar5 * 0x10000 < 0)
      {
        (fxPrim->v0).y = 0;
      }
    }
    FX_StandardFXPrimProcess(fxPrim, fxTracker);
  }
  return;
}

void FX_DFacadeParticleSetup(_FX_PRIM *fxPrim, SVECTOR *center, short halveWidth, short halveHeight, long color,
                             SVECTOR *vel, SVECTOR *accl, _FXTracker *fxTracker, int timeToLive)

{
  short sVar1;
  short sVar2;

  sVar1 = center->vy;
  sVar2 = center->vz;
  (fxPrim->position).x = center->vx;
  (fxPrim->position).y = sVar1;
  (fxPrim->position).z = sVar2;
  (fxPrim->v0).x = halveWidth;
  (fxPrim->v0).y = 0x1000;
  (fxPrim->v0).z = halveHeight;
  fxPrim->color = color & 0x3ffffffU | 0x20000000;
  *(code **)&fxPrim->process = FX_StandardFXPrimProcess;
  fxPrim->flags = fxPrim->flags | 8;
  if (vel == (SVECTOR *)0x0)
  {
    *(undefined2 *)&fxPrim->duo = 0;
    *(undefined2 *)((int)&fxPrim->duo + 2) = 0;
    *(undefined2 *)((int)&fxPrim->duo + 4) = 0;
  }
  else
  {
    *(short *)&fxPrim->duo = vel->vx;
    *(short *)((int)&fxPrim->duo + 2) = vel->vy;
    *(short *)((int)&fxPrim->duo + 4) = vel->vz;
  }
  if (accl == (SVECTOR *)0x0)
  {
    *(undefined2 *)((int)&fxPrim->duo + 6) = 0;
    *(undefined2 *)((int)&fxPrim->duo + 8) = 0;
    *(undefined2 *)((int)&fxPrim->duo + 10) = 0;
  }
  else
  {
    *(short *)((int)&fxPrim->duo + 6) = accl->vx;
    *(short *)((int)&fxPrim->duo + 8) = accl->vy;
    *(short *)((int)&fxPrim->duo + 10) = accl->vz;
  }
  fxPrim->timeToLive = (int)(short)timeToLive;
  return;
}

_FX_PRIM *
FX_Die(_SVector *location, _SVector *vel, _SVector *accel, int scale_speed, long color, long size,
       int lifetime, int texture_num)

{
  _FX_PRIM *fxPrim;
  u_int uVar1;

  fxPrim = FX_GetPrim(gFXT);
  if (fxPrim != (_FX_PRIM *)0x0)
  {
    if (texture_num < 0)
    {
      FX_DFacadeParticleSetup(fxPrim, (SVECTOR *)location, (short)size, (short)size, color, (SVECTOR *)vel,
                              (SVECTOR *)accel, gFXT, (int)(short)lifetime);
      if (color != 0)
      {
        fxPrim->flags = fxPrim->flags | 0xc0000;
      }
      fxPrim->startColor = color;
      fxPrim->endColor = 0;
      fxPrim->fadeValue[3] = 0;
      fxPrim->fadeValue[2] = 0;
      fxPrim->fadeValue[1] = 0;
      fxPrim->fadeValue[0] = 0;
 lifetime);
    }
    else
    {
      FX_MakeParticleTexFX(fxPrim, location, (Object *)0x0, 0, texture_num, vel, accel, color, size, lifetime);
    }
    if (scale_speed != 0)
    {
      uVar1 = fxPrim->flags;
      (fxPrim->v0).y = 0x1000;
      fxPrim->work3 = (short)scale_speed;
      fxPrim->flags = uVar1 | 0x2000;
    }
    FX_Sprite_Insert(&gFXT->usedPrimListSprite, fxPrim);
  }
  return fxPrim;
}

void FX_BloodCone(_SVector *location, _SVector *input_vel, _SVector *accel, int amount, long color,
                  long size)

{
  int iVar1;
  int iVar2;
  _SVector local_28;

  if (amount != 0)
  {
    do
    {
      iVar1 = rand();
      iVar2 = input_vel->x * amount;
      if (iVar2 < 0)
      {
        iVar2 = iVar2 + 0x7f;
      }
      local_28.x = (short)(iVar2 >> 7) + ((u_short)iVar1 & 7) + -4;
      iVar1 = rand();
      iVar2 = input_vel->y * amount;
      if (iVar2 < 0)
      {
        iVar2 = iVar2 + 0x7f;
      }
      local_28.y = (short)(iVar2 >> 7) + ((u_short)iVar1 & 7) + -4;
      iVar1 = rand();
      iVar2 = input_vel->z * amount;
      if (iVar2 < 0)
      {
        iVar2 = iVar2 + 0x7f;
      }
      local_28.z = (short)(iVar2 >> 7) + ((u_short)iVar1 & 7) + -4;
      FX_Die(location, &local_28, accel, 0, color, size, 0x10, -1);
      amount = amount + -1;
    } while (amount != 0);
  }
  return;
}

void FX_Blood2(_SVector *location, _SVector *input_vel, _SVector *accel, int amount, long color,
               long dummyCrapShouldRemove)

{
  FX_BloodCone(location, input_vel, accel, amount, color, 4);
  return;
}

void FX_Blood_Impale(_Instance *locinst, short locseg, _Instance *instance, short segment)

{
  _FXTracker *p_Var1;
  _FX_PRIM *fxPrim;
  u_int uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  SVECTOR local_30;
  SVECTOR local_28;
  SVECTOR local_20;
  short local_18;
  short local_16;
  short local_14;

  iVar3 = (int)((u_int)(u_short)segment << 0x10) >> 0xb;
  local_18 = *(short *)((int)instance->matrix->t + iVar3) -
             *(short *)((int)instance->oldMatrix->t + iVar3);
  local_16 = *(short *)((int)instance->matrix->t + iVar3 + 4) -
             *(short *)((int)instance->oldMatrix->t + iVar3 + 4);
  local_14 = *(short *)((int)instance->matrix->t + iVar3 + 8) -
             *(short *)((int)instance->oldMatrix->t + iVar3 + 8);
  iVar3 = (int)((u_int)(u_short)locseg << 0x10) >> 0xb;
  local_30.vx = *(short *)((int)locinst->matrix->t + iVar3);
  iVar4 = 1;
  local_30.vy = *(short *)((int)locinst->matrix->t + iVar3 + 4);
  local_30.vz = *(short *)((int)locinst->matrix->t + iVar3 + 8);
  local_28.vx = 0;
  local_28.vy = 0;
  local_28.vz = -2;
  do
  {
    fxPrim = FX_GetPrim(gFXT);
    if (fxPrim != (_FX_PRIM *)0x0)
    {
      iVar3 = rand();
      iVar5 = local_18 * iVar4;
      if (iVar5 < 0)
      {
        iVar5 = iVar5 + 0x3f;
      }
      local_20.vx = (short)(iVar5 >> 6) + ((u_short)iVar3 & 0xf) + -7;
      iVar3 = rand();
      iVar5 = local_16 * iVar4;
      if (iVar5 < 0)
      {
        iVar5 = iVar5 + 0x3f;
      }
      local_20.vy = (short)(iVar5 >> 6) + ((u_short)iVar3 & 0xf) + -7;
      iVar3 = rand();
      iVar5 = local_14 * iVar4;
      if (iVar5 < 0)
      {
        iVar5 = iVar5 + 0x3f;
      }
      local_20.vz = (short)(iVar5 >> 6) + ((u_short)iVar3 & 0xf) + -7;
      FX_DFacadeParticleSetup(fxPrim, &local_30, 8, 8, (long)&DAT_001800a0, &local_20, &local_28, gFXT, 0x16);
      p_Var1 = gFXT;
      fxPrim->fadeStep = 0xba;
      uVar2 = fxPrim->flags;
      fxPrim->startColor = 0x1800a0;
      fxPrim->endColor = 0;
      fxPrim->fadeValue[3] = 0;
      fxPrim->fadeValue[2] = 0;
      fxPrim->fadeValue[1] = 0;
      fxPrim->fadeValue[0] = 0;
      fxPrim->flags = uVar2 | 0xc0000;
      FX_Sprite_Insert(&p_Var1->usedPrimListSprite, fxPrim);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x40);
  return;
}

_FXParticle *FX_Blood(_Instance *instance, short startSegment, long time)

{
  _FXParticle *ptr;

  ptr = FX_GetParticle(instance, startSegment);
  if (ptr != (_FXParticle *)0x0)
  {
    ptr->size = 7;
    ptr->birthRadius = 0x14;
    (ptr->direction).x = 0x100;
    (ptr->direction).y = 0x100;
    (ptr->direction).z = 0x100;
    (ptr->acceleration).z = -2;
    ptr->numberBirthParticles = '\n';
    (ptr->acceleration).x = 0;
    (ptr->acceleration).y = 0;
    ptr->startColor = 0x1800a0;
    ptr->endColor = 0;
    ptr->lifeTime = (short)time;
    ptr->primLifeTime = 10;
    FX_InsertGeneralEffect(ptr);
  }
  return ptr;
}

_FXParticle *
FX_GetTorchParticle(_Instance *instance, short startSegment, int tex, int birthRadius, int num)

{
  u_short uVar1;
  _FXParticle *ptr;
  TextureMT3 *pTVar2;

  ptr = FX_GetParticle(instance, startSegment);
  if (ptr != (_FXParticle *)0x0)
  {
    ptr->type = '\x01';
    *(code **)&ptr->fxprim_process = FX_FlamePrimProcess;
    pTVar2 = FX_GetTextureObject(instance->object, 1, tex);
    ptr->startColor = 0x20040f0;
    uVar1 = ptr->flag_bits;
    ptr->texture = pTVar2;
    ptr->primLifeTime = 0x10;
    (ptr->acceleration).z = 1;
    ptr->lifeTime = -1;
    ptr->startFadeValue = 5;
    ptr->fadeStep = 5;
    ptr->size = 0x30;
    ptr->endColor = 0;
    ptr->scaleSpeed = 100;
    ptr->birthRadius = (short)birthRadius;
    ptr->numberBirthParticles = (char)num;
    ptr->flag_bits = uVar1 | 1;
    FX_InsertGeneralEffect(ptr);
  }
  return ptr;
}

_FXParticle *FX_TorchFlame(_Instance *instance, short startSegment)

{
  u_short uVar1;
  _FXParticle *ptr;

  ptr = FX_GetTorchParticle(instance, startSegment, 0, 0x10, -5);
  if (ptr != (_FXParticle *)0x0)
  {
    (ptr->direction).x = 0x30;
    (ptr->direction).y = 0x20;
    (ptr->direction).z = 0x38;
  }
  ptr = FX_GetTorchParticle(instance, startSegment, 1, 8, -1);
  if (ptr != (_FXParticle *)0x0)
  {
    (ptr->direction).x = 0x18;
    (ptr->direction).y = 0x10;
    (ptr->direction).z = 0x10;
  }
  ptr = FX_GetParticle(instance, startSegment);
  if (ptr != (_FXParticle *)0x0)
  {
    ptr->size = 5;
    ptr->birthRadius = 0x14;
    (ptr->direction).x = 0x80;
    (ptr->direction).y = 0x80;
    (ptr->direction).z = 0x80;
    ptr->startColor = 0x93e4;
    uVar1 = ptr->flag_bits;
    (ptr->acceleration).z = 1;
    ptr->numberBirthParticles = '\x01';
    (ptr->acceleration).x = 0;
    (ptr->acceleration).y = 0;
    ptr->endColor = 0;
    ptr->lifeTime = -1;
    ptr->primLifeTime = 0xf;
    ptr->flag_bits = uVar1 | 1;
    FX_InsertGeneralEffect(ptr);
  }
  return ptr;
}

int FX_GetMorphFadeVal(void)

{
  int iVar1;

  1000;
  if (gameTrackerX.gameData.asmData.MorphType == 1)
  {
    iVar1 = 0x1000 - iVar1;
  }
  return iVar1;
}

void FX_ConvertCamPersToWorld(SVECTOR *campos, SVECTOR *worldpos)

{
  u_char in_zero;
  u_char in_at;
  int iVar1;
  short sVar2;
  u_char uVar3;
  u_char uVar4;
  u_char uVar5;

  SetRotMatrix((u_char *)theCamera.core.cwTransform2);
  TransMatrix((int)theCamera.core.cwTransform2);
  sVar2 = campos->vx + -0x100;
  iVar1 = (int)sVar2 * 0x140;
  campos->vx = sVar2;
  if (iVar1 < 0)
  {
    iVar1 = iVar1 + 0x1ff;
  }
  campos->vx = (short)(iVar1 >> 9);
  campos->vy = campos->vy + -0x78;
 0x140);
 0x140);
 setCopReg(2, in_zero, *(u_char *)campos);
 setCopReg(2, in_at, *(u_char *)&campos->vz);
 copFunction(2, 0x480012);
 uVar3 = getCopReg(2, 0x4800);
 uVar4 = getCopReg(2, 0x5000);
 uVar5 = getCopReg(2, 0x5800);
 worldpos->vx = (short)uVar3;
 worldpos->vy = (short)uVar4;
 worldpos->vz = (short)uVar5;
 return;
}

void FX_GetRandomScreenPt(SVECTOR *point)

{
  int iVar1;
  int iVar2;

  iVar1 = rand();
  iVar2 = iVar1;
  if (iVar1 < 0)
  {
    iVar2 = iVar1 + 0x1ff;
  }
  point->vx = (short)iVar1 + (short)(iVar2 >> 9) * -0x200;
  iVar2 = rand();
 0xf0) * -0xf0;
 iVar2 = rand();
 point->vz = ((u_short)iVar2 & 0xfff) + 0x180;
 return;
}

void FX_ProcessSnow(_FX_PRIM *fxPrim, _FXTracker *fxTracker)

{
  short sVar1;
  u_int uVar2;
  int iVar3;
  SVECTOR SStack24;

  if (fxPrim->work0 == 9999)
  {
    if ((gameTrackerX.gameData.asmData.MorphType == 1) ||
        (gameTrackerX.gameData.asmData.MorphTime != 1000))
      goto LAB_800497d0;
    fxPrim->work0 = 0;
    FX_GetRandomScreenPt(&SStack24);
    FX_ConvertCamPersToWorld(&SStack24, (SVECTOR *)&fxPrim->position);
  }
  if (0 < fxPrim->timeToLive)
  {
    fxPrim->timeToLive = fxPrim->timeToLive + -1;
  }
  if (fxPrim->timeToLive != 0)
  {
    uVar2 = rand();
    iVar3 = (int)windx * ((uVar2 & 0x7ff) + 0x800);
    if (iVar3 < 0)
    {
      iVar3 = iVar3 + 0xfff;
    }
    (fxPrim->position).x = (fxPrim->position).x + (short)(iVar3 >> 0xc);
    uVar2 = rand();
    iVar3 = (int)windy * ((uVar2 & 0x7ff) + 0x800);
    if (iVar3 < 0)
    {
      iVar3 = iVar3 + 0xfff;
    }
    sVar1 = *(short *)((int)&fxPrim->duo + 4);
    (fxPrim->position).y = (fxPrim->position).y + (short)(iVar3 >> 0xc);
    (fxPrim->position).z = (fxPrim->position).z + sVar1;
    return;
  }
LAB_800497d0:
  FX_Dot(fxPrim, fxTracker);
  return;
}

void FX_ContinueRain(_FXTracker *fxTracker)

{
  u_int uVar1;
  _FX_PRIM *fxPrim;
  int iVar2;
  int iVar3;
  SVECTOR SStack40;
  SVECTOR local_20;
  SVECTOR local_18;

  if (gameTrackerX.gameData.asmData.MorphTime == 1000)
  {
    if (gameTrackerX.gameData.asmData.MorphType == 1)
    {
      return;
    }
  }
  else
  {
    if (gameTrackerX.gameData.asmData.MorphType == 0)
    {
      return;
    }
  }
  uVar1 = rand();
  if (((int)(uVar1 & 0x3ff) <= (int)snow_amount) &&
      (fxPrim = FX_GetPrim(gFXT), fxPrim != (_FX_PRIM *)0x0))
  {
    local_20.vx = 0;
    local_20.vy = 0;
    iVar2 = rand();
    local_20.vz = -0xd - ((u_short)iVar2 & 3);
    iVar3 = rand();
    iVar2 = iVar3;
    if (iVar3 < 0)
    {
      iVar2 = iVar3 + 0x1ff;
    }
    local_18.vx = (short)iVar3 + (short)(iVar2 >> 9) * -0x200;
    local_18.vy = 5;
    iVar2 = rand();
    local_18.vz = ((u_short)iVar2 & 0xfff) + 0x180;
    FX_ConvertCamPersToWorld(&local_18, &SStack40);
    FX_DFacadeParticleSetup(fxPrim, &SStack40, 1, 1, 0xffffff, &local_20, (SVECTOR *)0x0, fxTracker, 0x96);
    *(code **)&fxPrim->process = FX_ProcessSnow;
    fxPrim->work0 = 0;
    fxPrim->flags = fxPrim->flags | 0x800000;
    FX_Sprite_Insert(&fxTracker->usedPrimListSprite, fxPrim);
  }
  return;
}

void FX_UpdateWind(_FXTracker *fxTracker)

{
  int iVar1;
  int iVar2;
  u_int uVar3;

  iVar1 = rand();
  iVar2 = iVar1;
  if (iVar1 < 0)
  {
    iVar2 = iVar1 + 3;
  }
  iVar1 = iVar1 + (iVar2 >> 2) * -4;
  uVar3 = rand();
  if ((uVar3 & 1) != 0)
  {
    iVar1 = -iVar1;
  }
  uVar3 = (u_int)(u_short)wind_speed;
  wind_speed = (short)(uVar3 + iVar1);
  if (0x28 < (int)((uVar3 + iVar1) * 0x10000) >> 0x10)
  {
    wind_speed = 0x28;
  }
  if (wind_speed < 0xf)
  {
    wind_speed = 0xf;
  }
  iVar1 = rand();
  iVar2 = iVar1;
  if (iVar1 < 0)
  {
    iVar2 = iVar1 + 7;
  }
  iVar1 = iVar1 + (iVar2 >> 3) * -8;
  uVar3 = rand();
  if ((uVar3 & 1) != 0)
  {
    iVar1 = -iVar1;
  }
  uVar3 = (u_int)(u_short)wind_deg;
  wind_deg = (short)(uVar3 + iVar1);
  if (0x500 < (int)((uVar3 + iVar1) * 0x10000) >> 0x10)
  {
    wind_deg = 0x500;
  }
  if (wind_deg < 0x300)
  {
    wind_deg = 0x300;
  }
  iVar1 = rcos((int)wind_deg);
  iVar1 = iVar1 * wind_speed;
  if (iVar1 < 0)
  {
    iVar1 = iVar1 + 0xfff;
  }
  windx = (short)(iVar1 >> 0xc);
  iVar1 = rsin((int)wind_deg);
  iVar1 = iVar1 * wind_speed;
  if (iVar1 < 0)
  {
    iVar1 = iVar1 + 0xfff;
  }
  windy = (short)(iVar1 >> 0xc);
  return;
}

void ProcessRazControl(_FX_PRIM *fxPrim, _FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  short sVar3;

  if (0 < fxPrim->timeToLive)
  {
    fxPrim->timeToLive = fxPrim->timeToLive + -1;
  }
  sVar3 = (fxPrim->v1).z + *(short *)((int)&fxPrim->duo + 4);
  (fxPrim->v1).z = sVar3;
  if ((fxPrim->work0 < sVar3) && (fxPrim->timeToLive != 0))
  {
    sVar3 = *(short *)&fxPrim->duo;
    sVar1 = *(short *)((int)&fxPrim->duo + 2);
    (fxPrim->v0).x = (fxPrim->v0).x + sVar3;
    sVar2 = (fxPrim->v0).y;
    (fxPrim->v1).x = (fxPrim->v1).x + sVar3;
    (fxPrim->v0).y = sVar2 + sVar1;
    sVar3 = (fxPrim->v0).z;
    sVar2 = *(short *)((int)&fxPrim->duo + 4);
    (fxPrim->v1).y = (fxPrim->v1).y + sVar1;
    (fxPrim->v0).z = sVar3 + sVar2;
  }
  else
  {
    FX_Dot(fxPrim, fxTracker);
  }
  return;
}

void FX_ContinueLightning(_FXTracker *fxTracker)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  Level *pLVar6;
  u_int uVar7;
  int iVar8;
  int iVar9;
  _FX_PRIM *node;
  int iVar10;
  int iVar11;
  SVECTOR local_30;
  SVECTOR local_28;

  if (gameTrackerX.gameData.asmData._8_4_ != &PTR_000103e8)
  {
    iVar11 = (int)rain_amount;
    if (gameTrackerX.gameData.asmData.MorphTime != 1000)
    {
      iVar5 = FX_GetMorphFadeVal();
      iVar5 = iVar11 * (0x1000 - iVar5);
      iVar11 = iVar5 >> 0xc;
      if (iVar5 < 0)
      {
        iVar11 = iVar5 + 0xfff >> 0xc;
      }
    }
    iVar10 = 0;
    pLVar6 = STREAM_GetWaterZLevel((gameTrackerX.playerInstance)->currentStreamUnitID);
    iVar5 = pLVar6->waterZLevel;
    do
    {
      uVar7 = rand();
      if ((int)(uVar7 & 0x3ff) <= iVar11)
      {
        iVar8 = rand();
        iVar9 = iVar8;
        if (iVar8 < 0)
        {
          iVar9 = iVar8 + 0x1ff;
        }
        local_30.vx = (short)iVar8 + (short)(iVar9 >> 9) * -0x200;
        local_30.vy = 5;
        iVar9 = rand();
        local_30.vz = ((u_short)iVar9 & 0x7ff) + 0x180;
        FX_ConvertCamPersToWorld(&local_30, &local_28);
        uVar7 = rand();
        iVar9 = (-0xe - (uVar7 & 3)) * 8;
        if (local_28.vz + iVar9 < iVar5)
        {
          FX_GetRandomScreenPt(&local_30);
          local_30.vz = local_30.vz + ((short)iVar5 - local_28.vz);
          FX_ConvertCamPersToWorld(&local_30, &local_28);
          if (local_28.vz + iVar9 < iVar5)
            goto LAB_80049e64;
        }
        node = FX_GetPrim(gFXT);
        if (node != (_FX_PRIM *)0x0)
        {
          (node->v0).x = local_28.vx;
          (node->v0).y = local_28.vy;
          (node->v0).z = local_28.vz;
          uVar7 = rand();
          iVar8 = (int)windx * ((uVar7 & 0x3ff) + 0xc00);
          if (iVar8 < 0)
          {
            iVar8 = iVar8 + 0xfff;
          }
          *(short *)&node->duo = (short)(iVar8 >> 0xc);
          uVar7 = rand();
          iVar8 = (int)windy * ((uVar7 & 0x3ff) + 0xc00);
          if (iVar8 < 0)
          {
            iVar8 = iVar8 + 0xfff;
          }
          *(undefined2 *)((int)&node->duo + 2) = (short)(iVar8 >> 0xc);
          node->timeToLive = 0x14;
          node->flags = 0x1090000;
          node->color = 0x52404040;
          sVar1 = (node->v0).x;
          sVar2 = *(short *)&node->duo;
          *(code **)&node->process = ProcessRazControl;
          sVar3 = (node->v0).y;
          *(short *)((int)&node->duo + 4) = (short)iVar9;
          sVar4 = *(short *)((int)&node->duo + 2);
          node->work0 = (short)iVar5;
          node->endColor = 0;
          (node->v1).x = sVar1 + sVar2;
          sVar1 = (node->v0).z;
          (node->v1).y = sVar3 + sVar4;
          (node->v1).z = sVar1 + (short)iVar9;
          LIST_GetFunc(&fxTracker->usedPrimList, (NodeType *)node);
        }
      }
    LAB_80049e64:
      iVar10 = iVar10 + 1;
    } while (iVar10 < 3);
  }
  return;
}

void FX_MakeSpark(_Instance *instance, _Model *model, int segment)

{
  return;
}

void FX_ContinueParticle(_FXParticle *currentParticle, _FXTracker *fxTracker)

{
  undefined uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  int iVar9;
  _FX_PRIM *fxPrim;
  u_int uVar10;
  int iVar11;
  long lVar12;
  code *pcVar13;
  MATRIX *pMVar14;
  TextureMT3 *pTVar15;
  MATRIX *pMVar16;
  MATRIX *pMVar17;
  _Instance *instance;
  int iVar18;
  int iVar19;
  int local_40;
  int local_3c;
  int local_38;
  u_char local_30;
  u_int local_2c;

  local_30 = 0;
  local_2c = SEXT14(currentParticle->numberBirthParticles);
  if ((int)local_2c < 0)
  {
    iVar9 = rand();
    local_2c = (u_int)(iVar9 % -local_2c == 0);
  }
  instance = currentParticle->instance;
  if ((((((instance->flags & 0x800U) == 0) && ((instance->flags2 & 0x4000000U) == 0)) &&
        ((instance->flags & 0x200U) != 0)) &&
       ((pMVar14 = instance->matrix, pMVar14 != (MATRIX *)0x0 &&
                                         (instance->oldMatrix != (MATRIX *)0x0)))) &&
      (0 < (int)local_2c))
  {
    sVar2 = currentParticle->birthRadius;
    iVar9 = (int)sVar2;
    pMVar16 = instance->oldMatrix + currentParticle->startSegment;
    pMVar17 = pMVar14 + currentParticle->startSegment;
    if (currentParticle->type == '\x01')
    {
      iVar9 = iVar9 * 0x1000;
      if (iVar9 < 0)
      {
        iVar9 = iVar9 + 0x7f;
      }
      local_40 = iVar9 >> 7;
      local_3c = local_40;
      local_38 = local_40;
    }
    else
    {
      if ((byte)(currentParticle->type - 2) < 2)
      {
        pMVar16 = pMVar14 + currentParticle->endSegment;
      }
      local_40 = ((pMVar16->t[0] - pMVar17->t[0]) + iVar9) * 0x1000;
      if (local_40 < 0)
      {
        local_40 = local_40 + 0x7f;
      }
      local_40 = local_40 >> 7;
      local_3c = ((pMVar16->t[1] - pMVar17->t[1]) + iVar9) * 0x1000;
      if (local_3c < 0)
      {
        local_3c = local_3c + 0x7f;
      }
      local_3c = local_3c >> 7;
      local_38 = ((pMVar16->t[2] - pMVar17->t[2]) + iVar9) * 0x1000;
      if (local_38 < 0)
      {
        local_38 = local_38 + 0x7f;
      }
      local_38 = local_38 >> 7;
    }
    if (instance == gameTrackerX.playerInstance)
    {
      iVar9 = 0;
    }
    else
    {
      if (gameTrackerX.gameData.asmData.MorphTime == 1000)
      {
        iVar9 = (int)instance->fadeValue;
      }
      else
      {
        iVar9 = INSTANCE_GetFadeValue(instance);
      }
    }
    2;
    iVar19 = 0;
    if (0 < (int)local_2c)
    {
      iVar18 = 0x1000 - iVar9;
      do
      {
        fxPrim = FX_GetPrim(gFXT);
        if (fxPrim != (_FX_PRIM *)0x0)
        {
          uVar10 = rand();
          (fxPrim->position).x =
              ((currentParticle->offset).x + *(short *)pMVar17->t +
               (short)((int)(local_40 * (uVar10 & 0x7f)) >> 0xc)) -
              sVar2;
          uVar10 = rand();
          (fxPrim->position).y =
              ((currentParticle->offset).y + *(short *)(pMVar17->t + 1) +
               (short)((int)(local_3c * (uVar10 & 0x7f)) >> 0xc)) -
              sVar2;
          uVar10 = rand();
          (fxPrim->position).z =
              ((currentParticle->offset).z + *(short *)(pMVar17->t + 2) +
               (short)((int)(local_38 * (uVar10 & 0x7f)) >> 0xc)) -
              sVar2;
          switch (currentParticle->z_undulate)
          {
          default:
            goto switchD_8004a25c_caseD_0;
          case '\x01':
            iVar11 = rcos(gameTrackerX.frameCount << 7);
            iVar11 = iVar11 * 0x28;
            if (iVar11 < 0)
            {
              iVar11 = iVar11 + 0xfff;
            }
            sVar8 = (fxPrim->position).z + 0x14 + (short)(iVar11 >> 0xc);
            break;
          case '\x02':
            iVar11 = rcos(gameTrackerX.frameCount << 8);
            iVar11 = iVar11 * 0x14;
            if (iVar11 < 0)
            {
              iVar11 = iVar11 + 0xfff;
            }
            sVar8 = (fxPrim->position).z + 10 + (short)(iVar11 >> 0xc);
            break;
          case '\x03':
            iVar11 = rcos(gameTrackerX.frameCount << 8);
            iVar11 = iVar11 * 0xf;
            if (iVar11 < 0)
            {
              iVar11 = iVar11 + 0xfff;
            }
            sVar8 = (fxPrim->position).z + 8 + (short)(iVar11 >> 0xc);
            break;
          case '\x04':
            iVar11 = rcos(gameTrackerX.frameCount << 8);
            if (iVar11 < 0)
            {
              iVar11 = iVar11 + 0x1ff;
            }
            sVar8 = (fxPrim->position).z + 4 + (short)(iVar11 >> 9);
          }
          (fxPrim->position).z = sVar8;
        switchD_8004a25c_caseD_0:
          if (currentParticle->type == '\x03')
          {
            sVar8 = (fxPrim->position).y;
            *(short *)&fxPrim->duo =

                        (int)currentParticle->primLifeTime);
            sVar3 = (fxPrim->position).z;
            *(undefined2 *)((int)&fxPrim->duo + 2) =
 (int)currentParticle->primLifeTime);
            *(undefined2 *)((int)&fxPrim->duo + 4) =
 (int)currentParticle->primLifeTime);
          }
          else
          {
            if ((currentParticle->flag_bits & 2) == 0)
            {
              uVar10 = rand();
              iVar11 = ((uVar10 & 0x1ff) - 0xff) * (int)(currentParticle->direction).x;
              if (iVar11 < 0)
              {
                iVar11 = iVar11 + 0xfff;
              }
              *(short *)&fxPrim->duo = (short)(iVar11 >> 0xc);
              uVar10 = rand();
              iVar11 = ((uVar10 & 0x1ff) - 0xff) * (int)(currentParticle->direction).y;
              if (iVar11 < 0)
              {
                iVar11 = iVar11 + 0xfff;
              }
              *(undefined2 *)((int)&fxPrim->duo + 2) = (short)(iVar11 >> 0xc);
              uVar10 = rand();
              iVar11 = ((uVar10 & 0x1ff) - 0xff) * (int)(currentParticle->direction).z;
              if (iVar11 < 0)
              {
                iVar11 = iVar11 + 0xfff;
              }
              *(undefined2 *)((int)&fxPrim->duo + 4) = (short)(iVar11 >> 0xc);
            }
            else
            {
              *(short *)&fxPrim->duo = (currentParticle->direction).x;
              *(short *)((int)&fxPrim->duo + 2) = (currentParticle->direction).y;
              *(short *)((int)&fxPrim->duo + 4) = (currentParticle->direction).z;
            }
          }
          *(short *)((int)&fxPrim->duo + 6) = (currentParticle->acceleration).x;
          *(short *)((int)&fxPrim->duo + 8) = (currentParticle->acceleration).y;
          *(short *)((int)&fxPrim->duo + 10) = (currentParticle->acceleration).z;
          sVar8 = currentParticle->size;
          (fxPrim->v0).y = 0x1000;
          (fxPrim->v0).z = sVar8;
          (fxPrim->v0).x = sVar8;
          sVar8 = currentParticle->primLifeTime;
          fxPrim->flags = 0xc0008;
          fxPrim->timeToLive = (int)sVar8;
          fxPrim->startColor = currentParticle->startColor;
          if (((currentParticle->flag_bits & 1) != 0) &&
              ((gameTrackerX.gameData.asmData.MorphType == 1 ||
                (gameTrackerX.gameData.asmData.MorphTime != 1000))))
          {
            uVar1 = *(undefined *)((int)&fxPrim->startColor + 2);
            *(undefined *)((int)&fxPrim->startColor + 2) = *(undefined *)&fxPrim->startColor;
            *(undefined *)&fxPrim->startColor = uVar1;
            if (gameTrackerX.gameData.asmData.MorphTime != 1000)
            {
              iVar11 = FX_GetMorphFadeVal();
              LoadAverageCol((byte *)&currentParticle->startColor, (byte *)&fxPrim->startColor,
                             0x1000 - iVar11, iVar11, (undefined *)&fxPrim->startColor);
            }
          }
          lVar12 = currentParticle->endColor;
          sVar8 = (short)iVar9;
          fxPrim->fadeValue[3] = sVar8;
          fxPrim->fadeValue[2] = sVar8;
          fxPrim->fadeValue[1] = sVar8;
          fxPrim->fadeValue[0] = sVar8;
          fxPrim->endColor = lVar12;
          if (iVar9 == 0)
          {
 (int)currentParticle->primLifeTime);
          }
          else
          {
 (int)currentParticle->primLifeTime);
 LoadAverageCol((byte *)&fxPrim->startColor, (byte *)&local_30, iVar18, iVar9,
                (undefined *)&fxPrim->startColor);
 LoadAverageCol((byte *)&fxPrim->endColor, (byte *)&local_30, iVar18, iVar9,
                (undefined *)&fxPrim->endColor);
          }
          if (currentParticle->texture == (TextureMT3 *)0x0)
          {
            fxPrim->color = fxPrim->startColor & 0x3ffffffU | 0x20000000;
          }
          else
          {
            fxPrim->flags = fxPrim->flags | 1;
            pTVar15 = currentParticle->texture;
            fxPrim->color = fxPrim->startColor & 0x3ffffffU | 0x2c000000;
            fxPrim->texture = pTVar15;
          }
          if (currentParticle->scaleSpeed != 0)
          {
            fxPrim->flags = fxPrim->flags | 0x2000;
            (fxPrim->v0).y = currentParticle->startScale;
            fxPrim->work3 = currentParticle->scaleSpeed;
          }
          if (currentParticle->type == '\x01')
          {
            *(_Instance **)&fxPrim->matrix = instance;
            fxPrim->work0 = (short)currentParticle->startSegment;
            fxPrim->flags = fxPrim->flags | 0x8000000;
          }
          pcVar13 = (code *)currentParticle->fxprim_process;
          if (pcVar13 == (code *)0x0)
          {
            pcVar13 = FX_StandardFXPrimProcess;
          }
          *(code **)&fxPrim->process = pcVar13;
          if ((code *)currentParticle->fxprim_modify_process != (code *)0x0)
          {
            (*(code *)currentParticle->fxprim_modify_process)(fxPrim, instance, currentParticle, fxTracker);
          }
          if (currentParticle->type == '\x03')
          {
            sVar8 = (fxPrim->position).x;
            sVar3 = (fxPrim->position).y;
            sVar4 = (fxPrim->position).z;
            sVar5 = *(short *)&fxPrim->duo;
            fxPrim->flags = 0x1090000;
            sVar6 = *(short *)((int)&fxPrim->duo + 2);
            (fxPrim->v0).x = sVar8;
            sVar7 = *(short *)((int)&fxPrim->duo + 4);
            (fxPrim->v1).x = sVar8 + sVar5;
            (fxPrim->v0).y = sVar3;
            (fxPrim->v0).z = sVar4;
            (fxPrim->v1).y = sVar3 + sVar6;
            (fxPrim->v1).z = sVar4 + sVar7;
            LIST_GetFunc(&fxTracker->usedPrimList, (NodeType *)fxPrim);
          }
          else
          {
            FX_Sprite_Insert(&fxTracker->usedPrimListSprite, fxPrim);
          }
        }
        iVar19 = iVar19 + 1;
      } while (iVar19 < (int)local_2c);
    }
  }
  if ((0 < currentParticle->lifeTime) &&
      (iVar9 = (u_int)(u_short)currentParticle->lifeTime - (u_int)(u_short)FX_Frames,
       currentParticle->lifeTime = (short)iVar9, iVar9 * 0x10000 < 1))
  {
    FX_DeleteGeneralEffect((_FXGeneralEffect *)currentParticle);
  }
  return;
}

void FX_UpdraftPrimModify(_FX_PRIM *fxPrim, _Instance *instance, _FXParticle *particle, _FXTracker *fxTracker)

{
  undefined2 uVar1;
  u_int uVar2;
  int iVar3;
  u_int uVar4;
  int iVar5;

  uVar2 = rand();
  iVar3 = rcos(uVar2 & 0xfff);
  uVar4 = rand();
  iVar3 = iVar3 * (particle->direction).x;
  if (iVar3 < 0)
  {
    iVar3 = iVar3 + 0xfff;
  }
  (int)particle->primLifeTime;
  if (iVar3 < 0)
  {
    iVar3 = iVar3 + 0xfff;
  }
  *(short *)&fxPrim->duo = (short)(iVar3 >> 0xc);
  iVar3 = rsin(uVar2 & 0xfff);
  uVar2 = rand();
  iVar3 = iVar3 * (particle->direction).x;
  if (iVar3 < 0)
  {
    iVar3 = iVar3 + 0xfff;
  }
  (int)particle->primLifeTime;
  uVar1 = (undefined2)(iVar3 >> 0xc);
  if (iVar3 < 0)
  {
    uVar1 = (undefined2)(iVar3 + 0xfff >> 0xc);
  }
  *(undefined2 *)((int)&fxPrim->duo + 2) = uVar1;
  iVar5 = rand();
  iVar3 = iVar5;
  if (iVar5 < 0)
  {
    iVar3 = iVar5 + 7;
  }
  *(short *)((int)&fxPrim->duo + 4) =
      particle->primLifeTime + (short)iVar5 + (short)(iVar3 >> 3) * -8;
  return;
}

void FX_MakeParticleTexFX(_FX_PRIM *fxPrim, _SVector *position, Object *object, int modelnum, int texnum,
                          _SVector *vel, _SVector *accl, long color, int size, int life)

{
  TextureMT3 *pTVar1;
  u_int uVar2;

  if ((object != (Object *)0x0) && (fxPrim != (_FX_PRIM *)0x0))
  {
    FX_DFacadeParticleSetup(fxPrim, (SVECTOR *)position, (short)size, (short)size, color, (SVECTOR *)vel,
                            (SVECTOR *)accl, gFXT, (int)(short)life);
    pTVar1 = FX_GetTextureObject(object, modelnum, texnum);
    fxPrim->texture = pTVar1;
    uVar2 = fxPrim->flags;
    fxPrim->fadeValue[3] = 0;
    fxPrim->fadeValue[2] = 0;
    fxPrim->fadeValue[1] = 0;
    fxPrim->fadeValue[0] = 0;
    fxPrim->color = color | 0x2e000000;
    fxPrim->startColor = color;
    fxPrim->endColor = 0;
    fxPrim->flags = uVar2 | 0xc0001;
 life);
  }
  return;
}

void FX_MakeSpark(_SVector *position)

{
  _FX_PRIM *fxPrim;

  fxPrim = FX_GetPrim(gFXT);
  if (fxPrim != (_FX_PRIM *)0x0)
  {
    FX_MakeParticleTexFX(fxPrim, position, (Object *)0x0, 0, 0, (_SVector *)0x0, (_SVector *)0x0, 0xffffff, 0x60, 8);
    FX_Sprite_Insert(&gFXT->usedPrimListSprite, fxPrim);
    fxPrim->flags = fxPrim->flags | 0x8000;
  }
  return;
}

void FX_ContinueFlash(_FXLightning *zap, _FXTracker *fxTracker)

{
  int iVar1;

  zap->deg = zap->deg + zap->deg_inc;
  if ((0 < zap->lifeTime) &&
      (iVar1 = (u_int)(u_short)zap->lifeTime - (u_int)(u_short)FX_Frames, zap->lifeTime = (short)iVar1,
       iVar1 * 0x10000 < 1))
  {
    FX_DeleteGeneralEffect((_FXGeneralEffect *)zap);
  }
  return;
}

void FX_MakeHitFX(_SVector *startpos, int zpos, int angle, int dist, int size)

{
  _FX_PRIM *fxPrim;
  int iVar1;
  int iVar2;
  _SVector local_28;

  fxPrim = FX_GetPrim(gFXT);
  if (fxPrim != (_FX_PRIM *)0x0)
  {
    iVar1 = rcos(angle - 0x400U);
    iVar2 = rand();
    iVar1 = iVar1 * dist;
    if (iVar1 < 0)
    {
      iVar1 = iVar1 + 0xfff;
    }
    local_28.x = startpos->x + (short)(iVar1 >> 0xc) + ((u_short)iVar2 & 0xf);
    iVar1 = rsin(angle - 0x400U);
    iVar2 = rand();
    iVar1 = iVar1 * dist;
    if (iVar1 < 0)
    {
      iVar1 = iVar1 + 0xfff;
    }
    local_28.y = startpos->y + (short)(iVar1 >> 0xc) + ((u_short)iVar2 & 0xf);
    iVar1 = rand();
    local_28.z = startpos->z + (short)zpos + ((u_short)iVar1 & 0xf);
    FX_MakeParticleTexFX(fxPrim, &local_28, (Object *)0x0, 0, 0, (_SVector *)0x0, (_SVector *)0x0,
                         (long)&DAT_000093e4, size, 2);
    FX_Sprite_Insert(&gFXT->usedPrimListSprite, fxPrim);
  }
  return;
}

void FX_SetReaverInstance(_Instance *instance)

{
  FX_reaver_instance = instance;
  return;
}

void _SoulReaverAnimate(_Instance *instance, u_long **drawot)

{
  return;
}

void FX_ReaverBladeInit(void)

{
  return;
}

void StopSoulReaverCharge(_Instance *instance, _PrimPool *primPool, u_long **ot, MATRIX *wcTransform)

{
  short deg;
  char *pcVar1;
  long color;
  int iVar2;
  MATRIX MStack96;
  _SVector local_40;
  _SVector local_38;
  long local_30;

  pcVar1 = (char *)instance->extraData;
  if ((*pcVar1 != '\0') && (pcVar1[1] != '\0'))
  {
    deg = -*(short *)(pcVar1 + 6);
    CompMatrix((u_char *)wcTransform, (u_short *)((gameTrackerX.playerInstance)->matrix + 0x28),
               (u_int *)&MStack96);
    local_40.z = 0;
    local_40.y = 0;
    local_40.x = 0;
    local_38.y = 0;
    local_38.x = 0;
    local_38.z = -0x80;
    color = *(long *)(pcVar1 + 0x14);
    local_30 = *(long *)(pcVar1 + 0x18);
    FX_CreateLightning(wcTransform, ot, &MStack96, deg, &local_40, &local_38, 0x1e, 10, 0x10, 0x20, 0, color,
                       local_30);
    CompMatrix((u_char *)wcTransform, (u_short *)((gameTrackerX.playerInstance)->matrix + 0x27),
               (u_int *)&MStack96);
    local_38.z = -0x60;
    FX_CreateLightning(wcTransform, ot, &MStack96, deg, &local_40, &local_38, 0x1e, 10, 0x10, 0x20, 0, color,
                       local_30);
    iVar2 = (int)*(short *)(pcVar1 + 2) * (int)*(short *)(pcVar1 + 0x1c);
    if (iVar2 < 0)
    {
      iVar2 = iVar2 + 0xfff;
    }
    iVar2 = (iVar2 >> 0xc) * -0x17c;
    if (iVar2 < 0)
    {
      iVar2 = iVar2 + 0xfff;
    }
    local_38.z = (short)(iVar2 >> 0xc);
    if (*(short *)(pcVar1 + 4) == 1)
    {
      color = 0xfcffd3;
    }
    CompMatrix((u_char *)wcTransform, (u_short *)(instance->matrix + 1), (u_int *)&MStack96);
    FX_CreateLightning(wcTransform, ot, &MStack96, deg, &local_40, &local_38, 0, 0x19, 4, 8, 0, color, local_30);
  }
  return;
}

void FX_StartInstanceEffect(_Instance *instance, Level *level, _TFace *tface)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  BSPTree *pBVar7;
  _TVertex *p_Var8;
  _SVector local_20[2];

  COLLIDE_GetNormal(tface->normal, (short *)level->terrain->normalList, local_20);
  (instance->halvePlane).a = local_20[0].x;
  (instance->halvePlane).b = local_20[0].y;
  (instance->halvePlane).c = local_20[0].z;
  p_Var8 = level->terrain->vertexList + (tface->face).v0;
  sVar1 = (p_Var8->vertex).x;
  pBVar7 = level->terrain->BSPTreeArray + instance->bspTree;
  sVar2 = (pBVar7->globalOffset).x;
  sVar3 = (p_Var8->vertex).y;
  sVar4 = (pBVar7->globalOffset).y;
  sVar5 = (p_Var8->vertex).z;
  sVar6 = (pBVar7->globalOffset).z;
  (instance->halvePlane).flags = 1;
  (instance->halvePlane).d =
      -((int)(instance->halvePlane).a * (int)(short)(sVar1 + sVar2) +
            (int)(instance->halvePlane).b * (int)(short)(sVar3 + sVar4) +
            (int)(instance->halvePlane).c * (int)(short)(sVar5 + sVar6) >>
        0xc);
  return;
}

void FX_StopInstanceBurrow(_Instance *instance)

{
  (instance->halvePlane).flags = 0;
  return;
}

void FX_UpdateInstanceWaterSplit(_Instance *instance)

{
  _SVector _Stack16;

  if ((instance->waterFace == (_TFace *)0x0) || (instance->waterFaceTerrain == (_Terrain *)0x0))
  {
    (instance->halvePlane).flags = (instance->halvePlane).flags & 0xfffd;
  }
  else
  {
    if (((instance->halvePlane).flags & 8U) == 0)
    {
      COLLIDE_GetNormal(instance->waterFace->normal, (short *)instance->waterFaceTerrain->normalList,
                        &_Stack16);
      (instance->halvePlane).flags = 2;
      FX_GetPlaneEquation(&_Stack16, &instance->splitPoint, &instance->halvePlane);
    }
    FX_MakeWaterTrail(instance, (int)(instance->splitPoint).z);
  }
  instance->oldWaterFace = instance->waterFace;
  return;
}

void FX_GetPlaneEquation(_SVector *normal, _SVector *poPlane, _PlaneConstants *plane)

{
  short sVar1;

  plane->a = normal->x;
  plane->b = normal->y;
  sVar1 = normal->z;
  plane->c = sVar1;
  plane->d = -((int)plane->a * (int)poPlane->x + (int)plane->b * (int)poPlane->y +
                   (int)sVar1 * (int)poPlane->z >>
               0xc);
  return;
}

void FX_DoInstancePowerRing(_Instance *instance, long atuTime, long *color, long numColors, int follow_halveplane)

{
  char *ptr;
  long lVar1;
  int iVar2;
  int iVar3;
  long *plVar4;
  _SVector local_28;
  _SVector local_20;

  ptr = MEMPACK_Malloc(numColors * 4 + 0x2c, '\r');
  if (ptr == (char *)0x0)
  {
    return;
  }
  ptr[0xc] = -0x7e;
  *(u_char *)(ptr + 4) = 0x8004b8cc;
  *(u_char *)(ptr + 0x10) = 0;
  *(_Instance **)(ptr + 8) = instance;
  *(u_char *)(ptr + 0x24) = 0;
  *(undefined2 *)(ptr + 0x2a) = 0;
  *(short *)(ptr + 0x28) = (short)numColors;
  ptr[0xd] = (char)follow_halveplane;
 0x4b0);
 if (numColors < 2)
 {
   if (color == (long *)0x0)
   {
     lVar1 = 0xff8010;
     goto code_r0x8004b5e4;
   }
 }
 else
 {
   *(char **)(ptr + 0x24) = ptr + 0x2c;
   iVar3 = 0;
   plVar4 = color;
   if (0 < numColors)
   {
     do
     {
       iVar2 = iVar3 * 4;
       iVar3 = iVar3 + 1;
       *(long *)(iVar2 + *(int *)(ptr + 0x24)) = *plVar4;
       plVar4 = plVar4 + 1;
     } while (iVar3 < numColors);
   }
 (numColors + -1));
 }
 lVar1 = *color;
code_r0x8004b5e4:
  *(long *)(ptr + 0x20) = lVar1;
  local_28.y = 0;
  local_28.x = 0;
  local_28.z = 0x1000;
  local_20.x = (instance->position).x;
  local_20.y = (instance->position).y;
  local_20.z = (instance->position).z;
  FX_GetPlaneEquation(&local_28, &local_20, (_PlaneConstants *)(ptr + 0x14));
  FX_InsertGeneralEffect(ptr);
  return;
}

void FX_UpdatePowerRing(_FXHalvePlane *ring)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  long *plVar5;
  _Instance *p_Var6;
  int iVar7;
  u_char uVar8;
  u_char uVar9;
  u_char uVar10;
  u_int uVar11;
  int iVar12;

  iVar7 = (int)ring->lifeTime;
  p_Var6 = ring->instance;
  sVar1 = (p_Var6->position).z;
  sVar2 = (p_Var6->position).x;
  sVar3 = (p_Var6->position).y;
  1000;
  iVar7;
  if (iVar7 <= ring->diffTime)
  {
    iVar12 = 0x200;
    ring->diffTime = iVar7;
    ring->lifeTime = 0;
  }
  (ring->ringPlane).flags = 0;
  iVar7 = rsin(200);
  iVar4 = rsin(uVar11);
  (ring->ringPlane).a = (short)(iVar7 * iVar4 >> 0xc);
  iVar7 = rsin(200);
  iVar4 = rcos(uVar11);
  (ring->ringPlane).b = (short)(-iVar7 * iVar4 >> 0xc);
  iVar7 = rcos(200);
  (ring->ringPlane).c = (short)iVar7;
  (ring->ringPlane).d =
      -((int)(ring->ringPlane).a * (int)sVar2 + (int)(ring->ringPlane).b * (int)sVar3 +
            (int)(short)iVar7 * (sVar1 + iVar12) >>
        0xc);
  if (ring->colorArray != (long *)0x0)
  {
    iVar7 = 0;
    if (ring->diffTime != 0)
    {
      (int)ring->colorBlendLife;
    }
    (int)ring->colorBlendLife;
    if ((int)ring->numColors + -1 <= iVar7)
    {
      iVar7 = (int)ring->numColors + -2;
      iVar12 = 0x1000;
    }
    setCopReg(2, 0x4000, 0x1000 - iVar12);
    plVar5 = ring->colorArray + iVar7;
    setCopReg(2, 0x4800, (u_int) * (byte *)plVar5);
    setCopReg(2, 0x5000, (u_int) * (byte *)((int)plVar5 + 1));
    setCopReg(2, 0x5800, (u_int) * (byte *)((int)plVar5 + 2));
    copFunction(2, 0x198003d);
    setCopReg(2, 0x4000, iVar12);
    plVar5 = ring->colorArray + iVar7 + 1;
    setCopReg(2, 0x4800, (u_int) * (byte *)plVar5);
    setCopReg(2, 0x5000, (u_int) * (byte *)((int)plVar5 + 1));
    setCopReg(2, 0x5800, (u_int) * (byte *)((int)plVar5 + 2));
    copFunction(2, 0x1a8003e);
    uVar8 = getCopReg(2, 0x4800);
    uVar9 = getCopReg(2, 0x5000);
    uVar10 = getCopReg(2, 0x5800);
    *(char *)&ring->currentColor = (char)uVar8;
    *(undefined *)((int)&ring->currentColor + 1) = (char)uVar9;
    *(undefined *)((int)&ring->currentColor + 2) = (char)uVar10;
  }
  ring->diffTime = ring->diffTime + gameTrackerX.lastLoopTime;
  return;
}

void FX_UpdateInstanceSplitRing(_FXHalvePlane *ring, _FXTracker *fxTracker)

{
  int iVar1;

  if (ring->lifeTime != 0)
  {
    if (ring->type == '\0')
    {
      FX_UpdatePowerRing(ring);
    }
    else
    {
      iVar1 = ring->diffTime + gameTrackerX.lastLoopTime;
      ring->diffTime = iVar1;
      if ((int)ring->lifeTime <= iVar1)
      {
        ring->diffTime = (int)ring->lifeTime;
        ring->lifeTime = 0;
      }
    }
    if (ring->lifeTime != 0)
    {
      return;
    }
  }
  FX_DeleteGeneralEffect((_FXGeneralEffect *)ring);
  return;
}

void FX_StopGlowEffect(_FXGlowEffect *effect, _FXTracker *fxTracker)

{
  if (effect->lifeTime == 0)
  {
    FX_DeleteGeneralEffect((_FXGeneralEffect *)effect);
  }
  return;
}

void FX_InsertGeneralEffect(void *ptr)

{
  _FXGeneralEffect *p_Var1;

  p_Var1 = (_FXGeneralEffect *)ptr;
  *(_FXGeneralEffect **)ptr = FX_GeneralEffectTracker;
  FX_GeneralEffectTracker = p_Var1;
  return;
}

void FX_DeleteGeneralEffect(_FXGeneralEffect *effect)

{
  _FXGeneralEffect *p_Var1;
  _FXGeneralEffect *p_Var2;
  _FXGeneralEffect *p_Var3;

  if (effect != (_FXGeneralEffect *)0x0)
  {
    p_Var1 = FX_GeneralEffectTracker;
    p_Var3 = (_FXGeneralEffect *)0x0;
    if (FX_GeneralEffectTracker != (_FXGeneralEffect *)0x0)
    {
      do
      {
        p_Var2 = p_Var1;
        if (p_Var2 == effect)
        {
          if (p_Var3 == (_FXGeneralEffect *)0x0)
          {
            FX_GeneralEffectTracker = (_FXGeneralEffect *)effect->next;
          }
          else
          {
            p_Var3->next = effect->next;
          }
          break;
        }
        p_Var1 = (_FXGeneralEffect *)p_Var2->next;
        p_Var3 = p_Var2;
      } while ((_FXGeneralEffect *)p_Var2->next != (_FXGeneralEffect *)0x0);
    }
    if (effect->effectType == '\0')
    {
      MEMPACK_Init((char *)effect[1].continue_process);
    }
    MEMPACK_Init((char *)effect);
  }
  return;
}

_FXGlowEffect *
FX_DoInstanceTwoSegmentGlow(_Instance *instance, long segment, long *color, long numColors, long atuColorCycleRate,
                            long width, long height)

{
  _FXGlowEffect *p_Var1;
  _FXGlowEffect *p_Var2;
  _Instance *p_Var3;
  int iVar4;
  int iVar5;
  long *plVar6;

  p_Var2 = (_FXGlowEffect *)MEMPACK_Malloc(numColors * 4 + 0x2c, '\r');
  if (p_Var2 == (_FXGlowEffect *)0x0)
    goto LAB_8004bb64;
  p_Var2->effectType = -0x7d;
  *(code **)&p_Var2->continue_process = FX_StopGlowEffect;
  p_Var2->colorArray = (long *)0x0;
  p_Var2->numColors = (short)numColors;
  p_Var2->colorBlendCycle = (short)(atuColorCycleRate * 0x21);
  p_Var2->width = (short)width;
  p_Var2->instance = instance;
  p_Var2->segment = (short)segment;
  *(void **)&p_Var2->diffTime = (void *)0x0;
  p_Var2->fadein_time = 0;
  p_Var2->fadeout_time = 0;
  p_Var2->height = (short)height;
  p_Var2->lifeTime = -1;
  p_Var2->SegmentInc = '\x01';
  p_Var2->numSegments = 1;
  if (numColors < 2)
  {
    if (color != (long *)0x0)
      goto LAB_8004bb4c;
    p_Var3 = (_Instance *)0xff8010;
  }
  else
  {
    *(_FXGlowEffect **)&p_Var2->colorArray = p_Var2 + 1;
    iVar4 = 0;
    plVar6 = color;
    if (0 < numColors)
    {
      do
      {
        iVar5 = iVar4 + 1;
        p_Var2->colorArray[iVar4] = *plVar6;
        iVar4 = iVar5;
        plVar6 = plVar6 + 1;
      } while (iVar5 < numColors);
    }
 (numColors + -1));
  LAB_8004bb4c:
    p_Var3 = (_Instance *)*color;
  }
  *(_Instance **)&p_Var2->currentColor = p_Var3;
  p_Var1 = p_Var2;
  *(_FXGeneralEffect **)&p_Var2->next = FX_GeneralEffectTracker;
  FX_GeneralEffectTracker = (_FXGeneralEffect *)p_Var1;
LAB_8004bb64:
  instance->flags2 = instance->flags2 | 0x200;
  return p_Var2;
}

void FX_SetGlowFades(_FXGlowEffect *glowEffect, int fadein, int fadeout)

{
  glowEffect->fadein_time = (short)fadein * 0x21;
  glowEffect->fadeout_time = (short)fadeout * 0x21;
  return;
}

_FXGlowEffect *
FX_DoInstanceManySegmentGlow(_Instance *instance, long segment, long segmentEnd, long *color, long numColors,
                             long atuColorCycleRate, long height)

{
  _FXGlowEffect *p_Var1;
  u_char uVar2;

  uVar2 = (u_char)(segmentEnd - segment);
  if (segmentEnd - segment < 0)
  {
    uVar2 = -uVar2;
    segment = segmentEnd;
  }
  p_Var1 = FX_DoInstanceTwoSegmentGlow(instance, segment, color, numColors, atuColorCycleRate, height, height);
  p_Var1->numSegments = '\x02';
  p_Var1->SegmentInc = uVar2;
  return p_Var1;
}

_FXGlowEffect *
FX_DoInstanceOneSegmentGlow(_Instance *instance, long segment, long numSegments, long *color, long numColors,
                            long atuColorCycleRate, long height)

{
  _FXGlowEffect *p_Var1;

  p_Var1 = FX_DoInstanceTwoSegmentGlow(instance, segment, color, numColors, atuColorCycleRate, height, height);
  p_Var1->numSegments = (u_char)numSegments;
  return p_Var1;
}

_FXGlowEffect *
FX_DoInstanceOneSegmentGlowWithTime(_Instance *instance, long segment, long *color, long numColors, long atuColorCycleRate,
                                    long width, long height, long ATULifeTime)

{
  _FXGlowEffect *p_Var1;

  p_Var1 = FX_DoInstanceTwoSegmentGlow(instance, segment, color, numColors, atuColorCycleRate, width, height);
  p_Var1->lifeTime = (short)ATULifeTime * 0x21;
  return p_Var1;
}

void FX_UpdateGlowEffect(_Instance *instance, int fadeout_time)

{
  _FXGeneralEffect *effect;
  short sVar1;
  _FXGeneralEffect *p_Var2;

  effect = FX_GeneralEffectTracker;
  if (FX_GeneralEffectTracker != (_FXGeneralEffect *)0x0)
  {
    do
    {
      p_Var2 = (_FXGeneralEffect *)effect->next;
      if ((effect->effectType == -0x7d) && (effect->instance == instance))
      {
        if (fadeout_time * 0x21 == 0)
        {
          FX_DeleteGeneralEffect(effect);
        }
        else
        {
          sVar1 = (short)(fadeout_time * 0x21);
          *(short *)((int)&effect[2].instance + 2) = sVar1;
          effect->lifeTime = sVar1;
        }
      }
      effect = p_Var2;
    } while (p_Var2 != (_FXGeneralEffect *)0x0);
  }
  return;
}

void FX_StopAllGlowEffects(_FXGlowEffect *glowEffect, int fadeout_time)

{
  short sVar1;
  _FXGlowEffect *effect;
  _FXGlowEffect *p_Var2;

  if (glowEffect != (_FXGlowEffect *)0x0)
  {
    if (fadeout_time == 0)
    {
      effect = (_FXGlowEffect *)FX_GeneralEffectTracker;
      if (FX_GeneralEffectTracker != (_FXGeneralEffect *)0x0)
      {
        do
        {
          p_Var2 = (_FXGlowEffect *)effect->next;
          if ((effect->effectType == -0x7d) && (effect == glowEffect))
          {
            FX_DeleteGeneralEffect((_FXGeneralEffect *)effect);
          }
          effect = p_Var2;
        } while (p_Var2 != (_FXGlowEffect *)0x0);
      }
    }
    else
    {
      sVar1 = (short)fadeout_time * 0x21;
      glowEffect->fadeout_time = sVar1;
      glowEffect->lifeTime = sVar1;
    }
  }
  return;
}

void FX_DrawList(_FXLightning *zap, MATRIX *wcTransform, u_long **ot)

{
  MATRIX *pMVar1;
  MATRIX *mat;
  _SVector local_30;
  _SVector local_28;
  short local_20;
  short local_1e;
  short local_1c;

  if (zap->type == '\x02')
  {
    local_30.x = (zap->start_offset).x;
    local_30.y = (zap->start_offset).y;
    local_30.z = (zap->start_offset).z;
  }
  else
  {
    mat = zap->instance->matrix;
    if (mat == (MATRIX *)0x0)
    {
      local_30.x = (zap->instance->position).x;
      local_30.y = (zap->instance->position).y;
      local_30.z = (zap->instance->position).z;
    }
    else
    {
      mat = mat + zap->startSeg;
      ApplyMatrix(mat, &zap->start_offset, &local_20);
      local_30.x = *(short *)mat->t + local_20;
      local_30.y = *(short *)(mat->t + 1) + local_1e;
      local_30.z = *(short *)(mat->t + 2) + local_1c;
    }
  }
  if ((u_int)zap->type - 1 < 2)
  {
    local_28.x = (zap->end_offset).x;
    local_28.y = (zap->end_offset).y;
    local_28.z = (zap->end_offset).z;
  }
  else
  {
    mat = zap->end_instance->matrix;
    if (mat == (MATRIX *)0x0)
    {
      local_28.x = (zap->instance->position).x;
      local_28.y = (zap->instance->position).y;
      local_28.z = (zap->instance->position).z;
    }
    else
    {
      mat = mat + zap->endSeg;
      ApplyMatrix(mat, &zap->end_offset, &local_20);
      local_28.x = *(short *)mat->t + local_20;
      local_28.y = *(short *)(mat->t + 1) + local_1e;
      local_28.z = *(short *)(mat->t + 2) + local_1c;
    }
  }
  mat = (MATRIX *)0x0;
  if ((int)zap->matrixSeg != -1)
  {
    pMVar1 = zap->instance->matrix;
    if (pMVar1 != (MATRIX *)0x0)
    {
      mat = pMVar1 + (int)zap->matrixSeg;
    }
  }
  FX_CreateLightning(wcTransform, ot, mat, zap->deg, &local_30, &local_28, (int)zap->width,
                     (int)zap->small_width, (int)zap->segs, (int)zap->sine_size, (int)zap->variation,
                     zap->color, zap->glow_color);
  return;
}

void FX_DrawAllGeneralEffects(MATRIX *wcTransform, _VertexPool *vertexPool, _PrimPool *primPool, u_long **ot)

{
  byte bVar1;
  int iVar2;
  _Instance *instance;
  _FXBlastringEffect *blast;

  blast = (_FXBlastringEffect *)FX_GeneralEffectTracker;
  if (FX_GeneralEffectTracker != (_FXGeneralEffect *)0x0)
  {
    do
    {
      bVar1 = blast->effectType;
      if (((bVar1 & 0x80) != 0) &&
          ((instance = blast->instance, instance == (_Instance *)0x0 ||
                                            (((instance->flags & 0x800U) == 0 && ((instance->flags2 & 0x4000000U) == 0))))))
      {
        if (bVar1 == 0x83)
        {
          if ((0 < blast->lifeTime) &&
              (iVar2 = (u_int)(u_short)blast->lifeTime - (u_int)(u_short)gameTrackerX.lastLoopTime,
               blast->lifeTime = (short)iVar2, iVar2 * 0x10000 < 0))
          {
            blast->lifeTime = 0;
          }
          PIPE3D_DoGlow(instance, wcTransform, vertexPool, primPool, ot, (_FXGlowEffect *)blast);
        }
        else
        {
          if (bVar1 == 0x82)
          {
            PIPE3D_HalvePlaneGetRingPoints(instance, wcTransform, vertexPool, primPool, ot, (_FXHalvePlane *)blast);
          }
          else
          {
            if (bVar1 == 0x84)
            {
              FX_DrawRing(wcTransform, blast);
            }
            else
            {
              if (bVar1 == 0x85)
              {
                FX_LightHouse(wcTransform, ot, blast->instance, (int)(blast->position).x,
                              (int)(blast->position).y, 0x20, *(long *)&(blast->position).z);
              }
              else
              {
                if (bVar1 == 0x86)
                {
                  FX_DrawFField(wcTransform, (_FXForceFieldEffect *)blast);
                }
                else
                {
                  if (bVar1 == 0x87)
                  {
                    FX_DrawList((_FXLightning *)blast, wcTransform, ot);
                  }
                  else
                  {
                    if (bVar1 == 0x88)
                    {
                      FX_DrawFlash((_FXFlash *)blast);
                    }
                  }
                }
              }
            }
          }
        }
      }
      blast = (_FXBlastringEffect *)blast->next;
    } while (blast != (_FXBlastringEffect *)0x0);
  }
  return;
}

void FX_ContinueBlastRing(_FXBlastringEffect *blast, _FXTracker *fxTracker)

{
  u_short uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;

  iVar5 = blast->vel * (gameTrackerX.timeMult >> 4);
  if (iVar5 < 0)
  {
    iVar5 = iVar5 + 0xff;
  }
  iVar2 = (int)FX_Frames;
  iVar4 = blast->colorchange_radius;
  blast->radius = blast->radius + (iVar5 >> 8);
  iVar5 = blast->radius;
  iVar2 = blast->vel + blast->accl * iVar2;
  blast->vel = iVar2;
  if (iVar4 < iVar5)
  {
    if (iVar5 < 0)
    {
      iVar5 = iVar5 + 0xfff;
    }
    if (iVar4 < 0)
    {
      iVar4 = iVar4 + 0xfff;
    }
    iVar3 = blast->endRadius;
    iVar4 = iVar4 >> 0xc;
    if (iVar3 < 0)
    {
      iVar3 = iVar3 + 0xfff;
    }
    if (iVar2 < 0)
    {
      iVar2 = blast->startRadius;
      if (iVar2 < 0)
      {
        iVar2 = iVar2 + 0xfff;
      }
      ((iVar2 >> 0xc) - iVar4);
    }
    else
    {
      ((iVar3 >> 0xc) - iVar4);
    }
    if (iVar5 < 0x1001)
    {
      LoadAverageCol((byte *)&blast->endColor, (byte *)&blast->startColor, iVar5, 0x1000 - iVar5,
                     (undefined *)&blast->color);
      blast->color = blast->color & 0xffffff;
    }
    else
    {
      blast->color = 0;
    }
  }
  if (((blast->lifeTime != -99) &&
       (((0 < blast->vel && (blast->endRadius < blast->radius)) ||
         ((blast->vel < 0 && (blast->radius < blast->endRadius)))))) ||
      ((uVar1 = blast->lifeTime - 1, -1 < blast->lifeTime &&
                                         (blast->lifeTime = uVar1, (int)((u_int)uVar1 << 0x10) < 1))))
  {
    FX_DeleteGeneralEffect((_FXGeneralEffect *)blast);
  }
  return;
}

_FXBlastringEffect *
FX_DoBlastRing(_Instance *instance, _SVector *position, MATRIX *mat, int segment, int radius,
               int endRadius, int colorChangeRadius, int size1, int size2, int vel, int accl, int height1,
               int height2, int height3, long startColor, long endColor, int pred_offset, int lifeTime,
               int sortInWorld)

{
  _FXBlastringEffect *ptr;
  u_char uVar1;
  long lVar2;
  u_char uVar3;
  long lVar4;
  u_char uVar5;
  long lVar6;

  ptr = (_FXBlastringEffect *)MEMPACK_Malloc(0x78, '\r');
  if (ptr != (_FXBlastringEffect *)0x0)
  {
    *(code **)&ptr->continue_process = FX_ContinueBlastRing;
    ptr->instance = instance;
    ptr->effectType = -0x7c;
    if (pred_offset == 0)
    {
      ptr->type = '\0';
    }
    else
    {
      ptr->type = '\x01';
    }
    ptr->predator_offset = (short)pred_offset;
    ptr->lifeTime = (short)lifeTime;
    uVar1 = *(u_char *)&position->z;
    *(u_char *)&ptr->position = *(u_char *)position;
    *(u_char *)&(ptr->position).z = uVar1;
    if (mat != (MATRIX *)0x0)
    {
      uVar1 = *(u_char *)(mat->m + 2);
      uVar3 = *(u_char *)(mat->m + 4);
      uVar5 = *(u_char *)(mat->m + 6);
      *(u_char *)(ptr->matrix).m = *(u_char *)mat->m;
      *(u_char *)((ptr->matrix).m + 2) = uVar1;
      *(u_char *)((ptr->matrix).m + 4) = uVar3;
      *(u_char *)((ptr->matrix).m + 6) = uVar5;
      lVar2 = mat->t[0];
      lVar4 = mat->t[1];
      lVar6 = mat->t[2];
      *(u_char *)((ptr->matrix).m + 8) = *(u_char *)(mat->m + 8);
      (ptr->matrix).t[0] = lVar2;
      (ptr->matrix).t[1] = lVar4;
      (ptr->matrix).t[2] = lVar6;
    }
    ptr->segment = (short)segment;
    ptr->radius = radius << 0xc;
    ptr->startRadius = radius << 0xc;
    ptr->size1 = size1;
    ptr->size2 = size2;
    ptr->endRadius = endRadius << 0xc;
    ptr->colorchange_radius = colorChangeRadius << 0xc;
    ptr->vel = vel;
    ptr->accl = accl;
    ptr->height1 = height1;
    ptr->height2 = height2;
    ptr->color = startColor;
    ptr->startColor = startColor;
    ptr->height3 = height3;
    ptr->endColor = endColor;
    ptr->sortInWorld = (short)sortInWorld;
    FX_InsertGeneralEffect(ptr);
  }
  return ptr;
}

void FX_DrawRing(MATRIX *wcTransform, _FXBlastringEffect *blast)

{
  int radius;
  MATRIX *pMVar1;
  u_char local_40;
  u_char local_3c;
  MATRIX MStack56;

  radius = blast->radius;
  if (radius < 0)
  {
    radius = radius + 0xfff;
  }
  radius = radius >> 0xc;
  if ((int)blast->segment < 0)
  {
    CompMatrix((u_char *)wcTransform, (u_short *)&blast->matrix, (u_int *)&MStack56);
    local_40 = *(u_char *)&blast->position;
    local_3c = *(u_char *)&(blast->position).z;
  }
  else
  {
    pMVar1 = blast->instance->matrix;
    if (pMVar1 == (MATRIX *)0x0)
    {
      return;
    }
    pMVar1 = pMVar1 + (int)blast->segment;
    CompMatrix((u_char *)wcTransform, (u_short *)pMVar1, (u_int *)&MStack56);
    local_40 = CONCAT22(*(undefined2 *)(pMVar1->t + 1), *(undefined2 *)pMVar1->t);
    local_3c = CONCAT22(local_3c._2_2_, *(undefined2 *)(pMVar1->t + 2));
  }
  if (blast->type == '\0')
  {
    FX_DrawRing2(wcTransform, (_SVector *)&local_40, &MStack56, radius, radius + blast->size1,
                 radius + blast->size2, blast->height1, blast->height2, blast->height3, blast->color,
                 (int)blast->sortInWorld);
  }
  else
  {
    if (blast->type == '\x01')
    {
      FX_DrawBlastring(wcTransform, &blast->position, &MStack56, radius, radius + blast->size1,
                       radius + blast->size2, blast->height1, blast->height2, blast->height3,
                       (int)blast->predator_offset, (int)blast->sortInWorld);
    }
  }
  return;
}

void FX_ContinueRibbon(_FXFlash *flash, _FXTracker *fxTracker)

{
  int iVar1;

  iVar1 = flash->currentTime + gameTrackerX.timeMult;
  flash->currentTime = iVar1;
  if (iVar1 < 0)
  {
    iVar1 = iVar1 + 0xf;
  }
  if (flash->timeFromColor <= iVar1 >> 4)
  {
    FX_DeleteGeneralEffect((_FXGeneralEffect *)flash);
  }
  return;
}

void FX_DrawFlash(_FXFlash *flash)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int transtype;
  u_int local_10;
  u_char local_c;

  iVar2 = flash->currentTime;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xf;
  }
  iVar2 = iVar2 >> 4;
  local_10 = flash->color;
  local_c = 0;
  transtype = 1;
  if ((local_10 & 0x1000000) != 0)
  {
    transtype = 2;
  }
  if (iVar2 < flash->timeToColor)
  {
    flash->timeToColor;
    if (0x1000 < iVar2)
    {
      iVar2 = 0x1000;
    }
    iVar4 = 0x1000 - iVar2;
  }
  else
  {
    iVar3 = flash->timeAtColor;
    if (iVar2 <= iVar3)
      goto LAB_8004c89c;
    iVar4 = flash->timeFromColor - iVar3;
    if (iVar4 == 0)
    {
      iVar4 = 0x1000;
      bVar1 = true;
    }
    else
    {
      iVar4;
      bVar1 = iVar4 < 0x1001;
    }
    if (!bVar1)
    {
      iVar4 = 0x1000;
    }
    iVar2 = 0x1000 - iVar4;
  }
  LoadAverageCol((byte *)&local_10, (byte *)&local_c, iVar2, iVar4, (undefined *)&local_10);
LAB_8004c89c:
  FX_DrawScreenPoly(transtype, local_10, 5);
  return;
}

void FX_RelocateGeneric(Object *object, long offset)

{
  int *piVar1;
  int iVar2;
  int iVar3;

  piVar1 = (int *)object->data;
  iVar2 = 0;
  if (*piVar1 != 0)
  {
    iVar2 = *piVar1 + offset;
  }
  iVar3 = 0;
  *piVar1 = iVar2;
  if (piVar1[1] != 0)
  {
    iVar3 = piVar1[1] + offset;
  }
  iVar2 = 0;
  piVar1[1] = iVar3;
  if (piVar1[2] != 0)
  {
    iVar2 = piVar1[2] + offset;
  }
  iVar3 = 0;
  piVar1[2] = iVar2;
  if (piVar1[3] != 0)
  {
    iVar3 = piVar1[3] + offset;
  }
  iVar2 = 0;
  piVar1[3] = iVar3;
  if (piVar1[4] != 0)
  {
    iVar2 = piVar1[4] + offset;
  }
  iVar3 = 0;
  piVar1[4] = iVar2;
  if (piVar1[5] != 0)
  {
    iVar3 = piVar1[5] + offset;
  }
  iVar2 = 0;
  piVar1[5] = iVar3;
  if (piVar1[6] != 0)
  {
    iVar2 = piVar1[6] + offset;
  }
  piVar1[6] = iVar2;
  return;
}

_FXParticle *
FX_StartGenericParticle(_Instance *instance, int num, int segOverride, int lifeOverride, int InitFlag)

{
  return (_FXParticle *)0x0;
}

void FX_StartGenericGlow(_Instance *instance, int num, int segOverride, int endOverride, int InitFlag)

{
  return;
}

void FX_StartGenericBlastring(_Instance *instance, int num, int segOverride, int seg2Override, int InitFlag)

{
  return;
}

_FXLightning *
FX_CreateLightning(_Instance *instance, int lifeTime, int deg, int deg_inc, int width, int small_width,
                   int segs, int sine_size, int variation, u_long color, u_long glow_color)

{
  _FXLightning *ptr;

  ptr = (_FXLightning *)MEMPACK_Malloc(0x3c, '\r');
  if (ptr != (_FXLightning *)0x0)
  {
    *(code **)&ptr->continue_process = FX_ContinueFlash;
    ptr->instance = instance;
    ptr->end_instance = instance;
    ptr->effectType = -0x79;
    ptr->type = '\0';
    ptr->lifeTime = (short)lifeTime;
    ptr->deg = (short)deg;
    ptr->deg_inc = (short)deg_inc;
    ptr->width = (short)width;
    ptr->small_width = (short)small_width;
    ptr->segs = (short)segs;
    ptr->sine_size = (short)sine_size;
    ptr->variation = (short)variation;
    ptr->color = color;
    (ptr->start_offset).x = 0;
    (ptr->start_offset).y = 0;
    (ptr->start_offset).z = 0;
    (ptr->end_offset).x = 0;
    (ptr->end_offset).y = 0;
    (ptr->end_offset).z = 0;
    ptr->glow_color = glow_color;
    ptr->matrixSeg = -1;
    FX_InsertGeneralEffect(ptr);
  }
  return ptr;
}

void FX_SetLightingPos(_FXLightning *zap, _Instance *startInstance, int startSeg,
                       _Position *startOffset, _Instance *endInstance, int endSeg, _Position *endOffset,
                       int matrixSeg)

{
  short sVar1;

  if (zap == (_FXLightning *)0x0)
  {
    return;
  }
  if (startInstance != (_Instance *)0x0)
  {
    if (endInstance == (_Instance *)0x0)
    {
      zap->type = '\x01';
      zap->instance = startInstance;
    }
    else
    {
      zap->type = '\0';
      zap->instance = startInstance;
      zap->end_instance = endInstance;
    }
    if (startInstance != (_Instance *)0x0)
      goto LAB_8004d01c;
  }
  if (endInstance == (_Instance *)0x0)
  {
    zap->type = '\x02';
  }
LAB_8004d01c:
  if (startOffset != (_Position *)0x0)
  {
    sVar1 = startOffset->z;
    *(u_char *)&zap->start_offset = *(u_char *)startOffset;
    (zap->start_offset).z = sVar1;
  }
  if (endOffset != (_Position *)0x0)
  {
    sVar1 = endOffset->z;
    *(u_char *)&zap->end_offset = *(u_char *)endOffset;
    (zap->end_offset).z = sVar1;
  }
  zap->startSeg = (short)startSeg;
  zap->endSeg = (short)endSeg;
  zap->matrixSeg = (short)matrixSeg;
  return;
}

_FXLightning *FX_StartGenericRibbon(_Instance *instance, int num, int segOverride, int endSegOverride)

{
  return (_FXLightning *)0x0;
}

_FXBlastringEffect *
FX_StartGenericLightning(_Instance *instance, int num, int segOverride, int matrixSegOverride)

{
  return (_FXBlastringEffect *)0x0;
}

_FXFlash *FX_StartGenericFlash(_Instance *instance, int num)

{
  return (_FXFlash *)0x0;
}

long FX_GetHealthColor(int currentHealth)

{
  u_int uVar1;

  if (currentHealth < 1)
  {
    uVar1 = 0x7f;
  }
  else
  {
    if ((u_int)currentHealth < 6)
    {
      uVar1 = (&DAT_800c90dc)[currentHealth + -1];
    }
    else
    {
      uVar1 = 0x7f0000;
    }
  }
  return uVar1 & 0xfffcfcfc;
}

void FX_Start_Snow(int percent)

{
 100);
 return;
}

void FX_Start_Rain(int percent)

{
 100);
 return;
}

void FX_StartLightbeam(_Instance *instance, int startSeg, int endSeg, int color_num)

{
  return;
}

void FX_StartInstanceEffect(_Instance *instance, ObjectEffect *effect, int InitFlag)

{
  u_short uVar1;
  short sVar2;
  u_long uVar3;
  _FXParticle *p_Var4;
  u_int *puVar5;
  u_int numSegments;
  FXSplinter *splintDef;
  undefined *local_20[2];

  local_20[0] = &DAT_00004080;
  switch (effect->effectNumber)
  {
  case '\x01':
    FX_TorchFlame(instance, (u_short)effect->modifierList[0]);
    break;
  case '\x02':
    if ((u_int)effect->modifierList[1] - 1 < 5)
    {
      local_20[0] = (undefined *)(&FX_ColorArray)[effect->modifierList[1]];
    }
    FX_DoInstanceTwoSegmentGlow(instance, (u_int)effect->modifierList[0], (long *)local_20, 1, 0x400, 0x32, 100);
    break;
  case '\x03':
    numSegments = (u_int)effect->modifierList[1];
    if (effect->modifierList[1] == 0)
    {
      numSegments = 1;
    }
    if ((u_int)effect->modifierList[2] - 1 < 5)
    {
      local_20[0] = (undefined *)(&FX_ColorArray)[effect->modifierList[2]];
    }
    FX_DoInstanceOneSegmentGlow(instance, (u_int)effect->modifierList[0], numSegments, (long *)local_20, 1, 0x400, 0x41);
    break;
  case '\x05':
    FX_StartGenericParticle(instance, (u_int)effect->modifierList[0], (u_int)effect->modifierList[1],
                            (u_int)effect->modifierList[2], InitFlag);
    break;
  case '\x06':
    FX_StartGenericGlow(instance, (u_int)effect->modifierList[0], (u_int)effect->modifierList[1],
                        (u_int)effect->modifierList[2], InitFlag);
    break;
  case '\a':
    FX_StartGenericBlastring(instance, (u_int)effect->modifierList[0], (u_int)effect->modifierList[1],
                             (u_int)effect->modifierList[2], InitFlag);
    break;
  case '\b':
    GlyphTrigger();
    break;
  case '\n':
    FX_Start_Snow((u_int)effect->modifierList[0]);
    break;
  case '\v':
    FX_Start_Rain((u_int)effect->modifierList[0]);
    break;
  case '\f':
    uVar3 = INSTANCE_Post(instance, 0x16);
    if ((uVar3 != 0) &&
        (p_Var4 = FX_StartGenericParticle(instance, (u_int)effect->modifierList[0], (u_int)effect->modifierList[1],
                                          (u_int)effect->modifierList[2], InitFlag),
         p_Var4 != (_FXParticle *)0x0))
    {
      (p_Var4->direction).x = *(short *)(uVar3 + 2);
      (p_Var4->direction).y = *(short *)(uVar3 + 4);
      (p_Var4->direction).z = *(short *)(uVar3 + 6);
      uVar1 = *(u_short *)(uVar3 + 8);
      p_Var4->birthRadius = 0;
      *(code **)&p_Var4->fxprim_modify_process = FX_UpdraftPrimModify;
      p_Var4->primLifeTime = uVar1 >> 3;
    }
    break;
  case '\r':
    FX_StartLightbeam(instance, (u_int)effect->modifierList[0], (u_int)effect->modifierList[1],
                      (u_int)effect->modifierList[2]);
    break;
  case '\x0e':
    FX_StartGenericRibbon(instance, (u_int)effect->modifierList[0], (u_int)effect->modifierList[1],
                          (u_int)effect->modifierList[2]);
    break;
  case '\x0f':
    if (InitFlag == 0)
    {
      FX_StartGenericLightning(instance, (u_int)effect->modifierList[0], (u_int)effect->modifierList[1],
                               (u_int)effect->modifierList[2]);
    }
    break;
  case '\x10':
    if (InitFlag == 0)
    {
      FX_StartGenericFlash(instance, (u_int)effect->modifierList[0]);
    }
    break;
  case '\x11':
    splintDef = (FXSplinter *)0x0;
    if (InitFlag == 0)
    {
      puVar5 = (u_int *)instance->object->data;
      sVar2 = 0;
      if (puVar5 != (u_int *)0x0)
      {
        splintDef = (FXSplinter *)puVar5[1];
        sVar2 = (short)((*puVar5 & 2) << 3);
      }
      _FX_BuildNonSegmentedSplinters(instance, (SVECTOR *)0x0, (SVECTOR *)0x0, (SVECTOR *)0x0, splintDef, gFXT,
                                     (TDRFuncPtr__FX_BuildSplinters6fxSetup)0x0,
                                     (TDRFuncPtr__FX_BuildSplinters7fxProcess)0x0, (int)sVar2);
    }
  }
  return;
}

void FX_EndInstanceEffects(_Instance *instance)

{
  _FXGeneralEffect *effect;
  _FXGeneralEffect *p_Var1;

  effect = FX_GeneralEffectTracker;
  if (FX_GeneralEffectTracker != (_FXGeneralEffect *)0x0)
  {
    do
    {
      p_Var1 = (_FXGeneralEffect *)effect->next;
      if (effect->instance == instance)
      {
        FX_DeleteGeneralEffect(effect);
      }
      effect = p_Var1;
    } while (p_Var1 != (_FXGeneralEffect *)0x0);
  }
  return;
}

void FX_GetSpiralPoint(int radius, int deg, int *x, int *y)

{
  int iVar1;

  iVar1 = rcos(deg);
 0xf0) * 0x200;
 if (iVar1 < 0)
 {
   iVar1 = iVar1 + -0x800;
 }
 else
 {
   iVar1 = iVar1 + 0x800;
 }
 *x = (iVar1 >> 0xc) + 0x1b6;
 iVar1 = rsin(deg);
 iVar1 = radius * iVar1 >> 0xc;
 if (iVar1 < 0)
 {
   iVar1 = iVar1 + -0x800;
 }
 else
 {
   iVar1 = iVar1 + 0x800;
 }
 *y = (iVar1 >> 0xc) + 0xc9;
 return;
}

void FX_GetLinePoint(int radius, int next_radius, int deg, int next_deg, int *pntx, int *pnty, int part)

{
  int iVar1;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;

  FX_GetSpiralPoint(radius, deg, &local_20, &local_1c);
  FX_GetSpiralPoint(next_radius, next_deg, &local_18, &local_14);
  iVar1 = (local_18 - local_20) * part;
  if (iVar1 < 0)
  {
    iVar1 = iVar1 + 0xfff;
  }
  *pntx = local_20 + (iVar1 >> 0xc);
  part = (local_14 - local_1c) * part;
  if (part < 0)
  {
    part = part + 0xfff;
  }
  *pnty = local_1c + (part >> 0xc);
  return;
}

void FX_CalcSpiral(int degchange)

{
  int deg;
  int radius;
  int iVar1;
  int part;
  int next_deg;
  int iVar2;
  int next_radius;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;

  iVar4 = 0x7fff;
  iVar3 = -0x7fff;
  iVar5 = -0x7fff;
  iVar2 = 0x2000;
  deg = 0;
  part = 0;
  local_30 = 0x7fff;
  FX_GetSpiralPoint(0x2000, 0, &local_48, &local_44);
  DVECTOR_800d27a0.vx = (short)local_48;
  DVECTOR_800d27a0.vy = (short)local_44;
  next_deg = 0x2000;
  iVar1 = 0;
  do
  {
    if (Spiral_Number == 0)
    {
      radius = next_deg;
      next_deg = part;
      next_radius = iVar2;
      if (iVar1 % Spiral_Mod == 0)
      {
        next_radius = iVar2 + Spiral_Mod * 0x440;
        next_deg = part + degchange * Spiral_Mod;
        deg = part;
        radius = iVar2;
      }
      Spiral_Mod;
      FX_GetLinePoint(radius, next_radius, deg, next_deg, &local_48, &local_44, part);
      FX_GetLinePoint(radius + 0x1c00, next_radius + 0x1c00, deg, next_deg, &local_40, &local_3c, part);
      FX_GetLinePoint(radius + -0x1c00, next_radius + -0x1c00, deg, next_deg, &local_38, &local_34, part);
      part = next_deg;
      iVar2 = next_radius;
    }
    else
    {
      radius = next_deg + 0x440;
      deg = deg + degchange;
      FX_GetSpiralPoint(radius, deg, &local_48, &local_44);
      FX_GetSpiralPoint((int)(&UNK_00002040 + next_deg), deg, &local_40, &local_3c);
      FX_GetSpiralPoint(next_deg + -0x17c0, deg, &local_38, &local_34);
    }
    (&Spiral_Array)[iVar1].vx = (short)local_48;
    (&Spiral_Array)[iVar1].vy = (short)local_44;
    if (iVar1 == 0x3f)
    {
      local_40 = local_48;
      local_3c = local_44;
      local_38 = local_48;
      local_34 = local_44;
    }
    (&Spiral_OffsetP)[iVar1].vx = (short)local_40;
    (&Spiral_OffsetP)[iVar1].vy = (short)local_3c;
    if (local_40 < iVar4)
    {
      iVar4 = local_40;
    }
    if (iVar3 < local_40)
    {
      iVar3 = local_40;
    }
    if (local_3c < local_30)
    {
      local_30 = local_3c;
    }
    if (iVar5 < local_3c)
    {
      iVar5 = local_3c;
    }
    next_radius = iVar1 + 1;
    (&Spiral_OffsetM)[iVar1].vx = (short)local_38;
    (&Spiral_OffsetM)[iVar1].vy = (short)local_34;
    next_deg = radius;
    iVar1 = next_radius;
  } while (next_radius < 0x40);
 2) * 0x140;
 if (deg < 0)
 {
   deg = deg + 0x1ff;
 }
 2;
 2;
 Spiral_Glow_Size = (deg >> 9) + 2;
 return;
}

void FX_Spiral(_PrimPool *primPool, u_long **ot)

{
  short sVar1;
  u_int angle;
  long lVar2;
  int iVar3;
  DVECTOR *pDVar4;
  DVECTOR DVar5;
  DVECTOR DVar6;
  DVECTOR *pDVar7;
  int iVar8;
  u_int *puVar9;
  u_int *puVar10;
  DVECTOR DVar11;
  DVECTOR DVar12;
  DVECTOR DVar13;
  DVECTOR DVar14;
  int iVar15;
  _Vector local_60;
  DVECTOR local_50;
  DVECTOR local_4c;
  int local_48;
  DVECTOR local_44;
  u_int local_40;
  DVECTOR *local_38;
  int local_34;
  DVECTOR local_30;
  DVECTOR local_2c;

  if (((gameTrackerX.gameData.asmData.MorphTime != 1000) &&
       (gameTrackerX.gameData.asmData.MorphType == 0)) &&
      (Spiral_Number != 0))
  {
    FX_Health_Spiral(1, Spiral_Current, Spiral_Max);
  }
  DVar6 = (DVECTOR)0x3afcffd3;
  DVar5 = (DVECTOR)0x3adce0ba;
  DVar13 = (DVECTOR)0x3a483017;
  local_50 = (DVECTOR)0x3a002a15;
  local_44 = (DVECTOR)0x3abbc09d;
  if (Spiral_Number == 0)
  {
    if (Spiral_Current == Spiral_Max)
    {
      DAT_800cfddc = DAT_800cfddc + 1;
      if (0x50 < DAT_800cfddc)
      {
        DAT_800cfddc = 0;
      }
    }
    else
    {
      DVar6 = (DVECTOR)0x3a00ff00;
      DVar5 = (DVECTOR)0x3a00e000;
      local_44 = (DVECTOR)0x3a00bf00;
      DVar13 = (DVECTOR)0x3a004500;
    }
    local_50 = (DVECTOR)0x3a00150b;
  }
  else
  {
    DAT_800cfddc = DAT_800cfddc + 1;
    if (0x50 < DAT_800cfddc)
    {
      DAT_800cfddc = 0;
    }
  }
  lVar2 = Spiral_Max;
  if (Spiral_Max < 0)
  {
    lVar2 = Spiral_Max + 0x3f;
  }
  iVar3 = lVar2 >> 6;
  iVar3;
  puVar9 = primPool->nextPrim;
  iVar3;
  if (puVar9 + 0x451 < primPool->lastPrim)
  {
    iVar8 = 0;
    pDVar4 = &local_50;
    local_40 = (u_int)DVar6 & 0xff000000;
    local_48 = (int)DAT_800cfddc;
    pDVar7 = (DVECTOR *)(puVar9 + 0x10);
    DVar11 = DVECTOR_800d27a0;
    DVar12 = DVECTOR_800d27a0;
    DVar14 = DVECTOR_800d27a0;
    local_4c = local_50;
    do
    {
      puVar10 = puVar9;
      pDVar7[-0xb] = local_50;
      pDVar7[-7] = local_50;
      if (iVar15 < iVar8)
      {
        local_50 = local_4c;
      }
      else
      {
        angle = (int)(iVar8 + local_48 & 0xfU) >> 2;
        local_50 = DVar5;
        if (angle != 1)
        {
          if (angle < 2)
          {
          LAB_8004e078:
            local_50 = DVar6;
          }
          else
          {
            if (angle == 2)
            {
              local_50 = local_44;
            }
            else
            {
              if (angle != 3)
                goto LAB_8004e078;
            }
          }
        }
      }
      if (iVar8 == iVar15)
      {
        local_38 = pDVar4;
        local_34 = iVar3;
        local_30 = DVar5;
        local_2c = DVar6;
        LoadAverageCol((byte *)pDVar4, (byte *)&local_4c, iVar3, 0x1000 - iVar3, (undefined *)pDVar4);
        local_50 = (DVECTOR)((u_int)local_50 & 0xffffff | local_40);
        pDVar4 = local_38;
        iVar3 = local_34;
        DVar5 = local_30;
        DVar6 = local_2c;
      }
      pDVar7[-0xf] = DVar13;
      pDVar7[-0xd] = DVar13;
      pDVar7[-3] = DVar13;
      pDVar7[-1] = DVar13;
      pDVar7[-6] = DVar11;
      pDVar7[-10] = DVar11;
      pDVar7[-0xe] = DVar14;
      pDVar7[-2] = DVar12;
      pDVar7[-9] = local_50;
      pDVar7[-5] = local_50;
      DVar11 = (&Spiral_Array)[iVar8];
      DVar14 = (&Spiral_OffsetP)[iVar8];
      DVar12 = (&Spiral_OffsetM)[iVar8];
      iVar8 = iVar8 + 1;
      pDVar7[-4] = DVar11;
      pDVar7[-8] = DVar11;
      pDVar7[-0xc] = DVar14;
      *pDVar7 = DVar12;
      pDVar7 = pDVar7 + 0x11;
      *puVar10 = (u_int)ot[1] & 0xffffff | 0x10000000;
      ot[1] = (u_long *)((u_int)puVar10 & 0xffffff);
      puVar9 = puVar10 + 0x11;
    } while (iVar8 < 0x40);
    puVar10[0x12] = 0xe1000620;
    sVar1 = Spiral_Number;
    *puVar9 = (u_int)ot[1] & 0xffffff | 0x1000000;
    ot[1] = (u_long *)((u_int)puVar9 & 0xffffff);
    primPool->nextPrim = puVar10 + 0x13;
    if ((sVar1 != 0) || (Spiral_Current == Spiral_Max))
    {
      local_60.y = Spiral_Glow_Y;
      angle = (u_int)DAT_800cfdde - 0x20 & 0xfff;
      local_60.x = Spiral_Glow_X;
      DAT_800cfdde = (u_short)angle;
      DRAW_CreateAGlowingCircle(&local_60, 0x140, gameTrackerX.primPool, ot, 5, 0x8000, Spiral_Glow_Size, Spiral_Glow_Size, angle);
    }
  }
  return;
}

void FX_Health_Spiral(int number, int current_health, int max_health)

{
  bool bVar1;
  short sVar2;

  if (number == 0)
  {
    if (Spiral_Mod < 6)
    {
      Spiral_Number = 0;
      Spiral_Mod = Spiral_Mod + 1;
      FX_CalcSpiral(0x80);
      return;
    }
  }
  else
  {
    if (1 < Spiral_Mod)
    {
      Spiral_Mod = Spiral_Mod + -1;
      FX_CalcSpiral(0x80);
      return;
    }
  }
  switch (number)
  {
  default:
    sVar2 = 0x80;
    break;
  case 2:
    sVar2 = 0xa0;
    break;
  case 3:
    sVar2 = 0xc0;
    break;
  case 4:
    sVar2 = 0xe0;
  }
  if ((sVar2 == Spiral_Degrees) && ((int)Spiral_Number == number))
  {
    Spiral_Current = current_health;
    Spiral_Max = max_health;
    return;
  }
  Spiral_Number = (short)number;
  if (Spiral_Degrees < sVar2)
  {
    bVar1 = sVar2 < (short)(Spiral_Degrees + 4);
    Spiral_Degrees = Spiral_Degrees + 4;
  }
  else
  {
    if (Spiral_Degrees <= sVar2)
      goto LAB_8004e388;
    bVar1 = (short)(Spiral_Degrees + -4) < sVar2;
    Spiral_Degrees = Spiral_Degrees + -4;
  }
  if (bVar1)
  {
    Spiral_Degrees = sVar2;
  }
LAB_8004e388:
  FX_CalcSpiral((int)Spiral_Degrees);
  Spiral_Current = current_health;
  Spiral_Max = max_health;
  return;
}

void FX_Spiral_Init(void)

{
  Spiral_Max = 100000;
  Spiral_Current = 100000;
  Spiral_Number = 1;
  Spiral_Degrees = 0x80;
  FX_CalcSpiral(0x80);
  return;
}

void FX_DrawModel(Object *object, int model_num, _SVector *rotation, _SVector *position,
                  _SVector *offset, int transflag)

{
  u_long uVar1;
  u_long **ppuVar2;
  u_char in_zero;
  u_char in_at;
  _Model *p_Var3;
  _MVertex *p_Var4;
  _MVertex *p_Var5;
  _MVertex *p_Var6;
  u_long *puVar7;
  u_short *puVar8;
  int iVar9;
  _MFace *p_Var10;
  u_long uVar11;
  _MVertex *p_Var12;
  u_long *puVar13;
  MATRIX MStack88;
  short local_38;
  short local_36;
  short local_34;
  int local_30;

  ppuVar2 = gameTrackerX.drawOT;
  puVar13 = (gameTrackerX.primPool)->nextPrim;
  PushMatrix();
  MATH3D_SetUnityMatrix(&MStack88);
  RotMatrixZ((int)rotation->x, (int)&MStack88);
  RotMatrix((int)rotation->y, (u_int *)&MStack88);
  RotMatrixX((int)rotation->z, (u_int *)&MStack88);
  PIPE3D_AspectAdjustMatrix(&MStack88);
  ApplyMatrix(&MStack88, offset, &local_38);
  MStack88.t[0] = (int)position->x + (int)local_38;
  MStack88.t[1] = (int)position->y + (int)local_36;
  MStack88.t[2] = (int)position->z + (int)local_34;
  SetRotMatrix((u_char *)&MStack88);
  TransMatrix((int)&MStack88);
  uVar11 = 0x34808080;
  if (transflag != 0)
  {
    uVar11 = 0x36404040;
  }
  if (object != (Object *)0x0)
  {
    p_Var3 = object->modelList[model_num];
    p_Var10 = p_Var3->faceList;
    p_Var12 = p_Var3->vertexList;
    iVar9 = p_Var3->numFaces + -1;
    if (iVar9 != -1)
    {
      puVar8 = &(p_Var10->face).v2;
      do
      {
        if ((gameTrackerX.primPool)->lastPrim <= puVar13 + 10)
        {
          (gameTrackerX.primPool)->nextPrim = puVar13;
          goto LAB_8004e634;
        }
        puVar7 = *(u_long **)(puVar8 + 2);
        p_Var6 = p_Var12 + (p_Var10->face).v0;
        p_Var5 = p_Var12 + puVar8[-1];
        p_Var4 = p_Var12 + *puVar8;
        setCopReg(2, in_zero, *(u_char *)&p_Var6->vertex);
        setCopReg(2, in_at, *(u_char *)&(p_Var6->vertex).z);
        setCopReg(2, p_Var4, *(u_char *)&p_Var5->vertex);
        setCopReg(2, p_Var5, *(u_char *)&(p_Var5->vertex).z);
        setCopReg(2, p_Var6, *(u_char *)&p_Var4->vertex);
        setCopReg(2, puVar7, *(u_char *)&(p_Var4->vertex).z);
        copFunction(2, 0x280030);
        puVar13[3] = *puVar7;
        puVar13[6] = puVar7[1];
        puVar13[9] = puVar7[2];
        copFunction(2, 0x1400006);
        puVar13[7] = uVar11;
        puVar13[4] = uVar11;
        puVar13[1] = uVar11;
        local_30 = getCopReg(2, 0x18);
        if (local_30 < 0)
        {
          uVar1 = getCopReg(2, 0xc);
          puVar13[2] = uVar1;
          uVar1 = getCopReg(2, 0xd);
          puVar13[5] = uVar1;
          uVar1 = getCopReg(2, 0xe);
          puVar13[8] = uVar1;
          *puVar13 = (u_int)ppuVar2[1] & 0xffffff | 0x9000000;
          ppuVar2[1] = (u_long *)((u_int)puVar13 & 0xffffff);
          puVar13 = puVar13 + 10;
        }
        puVar8 = puVar8 + 6;
        iVar9 = iVar9 + -1;
        p_Var10 = p_Var10 + 1;
      } while (iVar9 != -1);
    }
  }
  (gameTrackerX.primPool)->nextPrim = puVar13;
LAB_8004e634:
  MulMatrix0();
  return;
}

void fx_calc_points(_SVector *points, int degrees, int radius, int radius2, int radius3)

{
  u_char in_zero;
  u_char in_at;
  int iVar1;
  int iVar2;
  int iVar3;

  iVar1 = rcos(degrees);
  iVar2 = rsin(degrees);
  points->x = (short)(iVar1 * radius >> 0xc);
  points[1].x = (short)(iVar1 * radius2 >> 0xc);
  points->y = (short)(iVar2 * radius >> 0xc);
  points[1].y = (short)(iVar2 * radius2 >> 0xc);
  points[2].x = (short)(iVar1 * radius3 >> 0xc);
  iVar3 = iVar2 * radius3 >> 0xc;
  points[2].y = (short)iVar3;
  setCopReg(2, in_zero, *(u_char *)points);
  setCopReg(2, in_at, *(u_char *)&points->z);
  setCopReg(2, iVar3, *(u_char *)(points + 1));
  setCopReg(2, iVar2 * radius, *(u_char *)&points[1].z);
  setCopReg(2, iVar1 * radius2, *(u_char *)(points + 2));
  setCopReg(2, iVar2 * radius2, *(u_char *)&points[2].z);
  copFunction(2, 0x280030);
  return;
}

long fx_get_startz(_SVector *position)

{
  u_char in_zero;
  u_char in_at;
  undefined auStack40[20];
  u_char local_14;
  u_char local_10;
  int local_c;

  setCopReg(2, in_zero, *(u_char *)position);
  setCopReg(2, in_at, *(u_char *)&position->z);
  copFunction(2, 0x480012);
  local_14 = getCopReg(2, 0x19);
  local_10 = getCopReg(2, 0x1a);
  local_c = getCopReg(2, 0x1b);
  TransMatrix((int)auStack40);
  if (local_c < 0)
  {
    local_c = local_c + 3;
  }
  return local_c >> 2;
}

void FX_DrawRing2(MATRIX *wcTransform, _SVector *position, MATRIX *matrix, int radius, int radius2,
                  int radius3, int z1, int z2, int z3, long color, int sortInWorld)

{
  long lVar1;
  int iVar2;
  u_long *puVar3;
  u_long *puVar4;
  u_long *puVar5;
  u_int uVar6;
  int iVar7;
  int degrees;
  _SVector _Stack96;
  undefined2 local_54;
  undefined2 local_4c;
  u_long local_48;
  u_long local_44;
  u_long local_40;
  int local_38;
  u_char local_34;
  int local_30;
  u_long **local_2c;

  puVar5 = (gameTrackerX.primPool)->nextPrim;
  local_2c = gameTrackerX.drawOT;
  if (puVar5 + 0x240 < (gameTrackerX.primPool)->lastPrim)
  {
    PushMatrix();
    SetRotMatrix((u_char *)wcTransform);
    TransMatrix((int)wcTransform);
    lVar1 = fx_get_startz(position);
    SetRotMatrix((u_char *)matrix);
    _Stack96.z = (short)z1;
    local_54 = (undefined2)z2;
    local_4c = (undefined2)z3;
    fx_calc_points(&_Stack96, 0, radius, radius2, radius3);
    uVar6 = color | 0x3a000000;
    local_48 = getCopReg(2, 0xc);
    local_44 = getCopReg(2, 0xd);
    local_40 = getCopReg(2, 0xe);
    iVar7 = 0;
    puVar4 = puVar5 + 0x11;
    degrees = 0x80;
    do
    {
      fx_calc_points(&_Stack96, degrees, radius, radius2, radius3);
      puVar4[-1] = 0x3a000000;
      puVar4[-3] = 0x3a000000;
      puVar4[-0xd] = 0x3a000000;
      puVar4[-0xf] = 0x3a000000;
      puVar4[-9] = uVar6;
      puVar4[-0xb] = uVar6;
      puVar4[-5] = uVar6;
      puVar4[-7] = uVar6;
      puVar4[-0xe] = local_40;
      puVar4[-10] = local_44;
      puVar4[-6] = local_44;
      puVar4[-0x10] = 0xe1000620;
      puVar4[-2] = local_48;
      local_48 = getCopReg(2, 0xc);
      local_44 = getCopReg(2, 0xd);
      local_40 = getCopReg(2, 0xe);
      local_38 = getCopReg(2, 0x11);
      local_34 = getCopReg(2, 0x12);
      local_30 = getCopReg(2, 0x13);
      puVar4[-0xc] = local_40;
      puVar4[-8] = local_44;
      puVar4[-4] = local_44;
      *puVar4 = local_48;
      if (local_30 < local_38)
      {
        local_38 = local_30;
      }
      iVar2 = local_38 >> 2;
      if (0 < local_38)
      {
        local_38 = iVar2;
        if ((sortInWorld == 0) && (local_38 = lVar1 + 0x10, iVar2 <= lVar1))
        {
          local_38 = 1;
        }
        if (local_38 - 1U < 0xbff)
        {
          puVar4 = puVar4 + 0x12;
          puVar3 = (u_long *)((u_int)puVar5 & 0xffffff);
          *puVar5 = (u_int)local_2c[local_38] & 0xffffff | 0x11000000;
          puVar5 = puVar5 + 0x12;
          local_2c[local_38] = puVar3;
        }
      }
      iVar7 = iVar7 + 1;
      degrees = degrees + 0x80;
    } while (iVar7 < 0x20);
    (gameTrackerX.primPool)->nextPrim = puVar5;
    MulMatrix0();
  }
  return;
}

void fx_setTex(DVECTOR *x, u_char *uv, int tx, int offset)

{
  u_char uVar1;

  *uv = *(char *)&x->vx - (char)tx;
  uVar1 = -1;
  if (x->vy < 0x100)
  {
    uVar1 = *(u_char *)&x->vy;
  }
  uv[1] = uVar1;
  x->vy = x->vy + (short)offset;
  return;
}

void FX_DrawBlastring(MATRIX *wcTransform, _SVector *position, MATRIX *matrix, int radius, int radius2,
                      int radius3, int z1, int z2, int z3, long offset, int sortInWorld)

{
  u_short uVar1;
  bool bVar2;
  u_short uVar3;
  long lVar4;
  int tx;
  u_long *puVar5;
  u_int uVar6;
  u_long *uv;
  u_long *puVar7;
  int iVar8;
  u_int uVar9;
  int degrees;
  _SVector _Stack104;
  undefined2 local_5c;
  undefined2 local_54;
  u_long local_50;
  u_char local_4c;
  u_long local_48;
  int local_40;
  u_char local_3c;
  int local_38;
  u_long **local_34;
  u_int local_30;

  puVar7 = (gameTrackerX.primPool)->nextPrim;
  local_34 = gameTrackerX.drawOT;
  if (puVar7 + 0x140 < (gameTrackerX.primPool)->lastPrim)
  {
    PushMatrix();
    SetRotMatrix((u_char *)wcTransform);
    TransMatrix((int)wcTransform);
    lVar4 = fx_get_startz(position);
    SetRotMatrix((u_char *)matrix);
    _Stack104.z = (short)z1;
    local_5c = (undefined2)z2;
    uVar6 = (gameTrackerX.gameData.asmData.dispPage ^ 1U) << 8;
    local_54 = (undefined2)z3;
    fx_calc_points(&_Stack104, 0, radius, radius2, radius3);
    local_50 = getCopReg(2, 0xc);
    local_4c = getCopReg(2, 0xd);
    local_48 = getCopReg(2, 0xe);
    iVar8 = 0;
    uVar9 = (int)(uVar6 & 0x100) >> 4;
    uVar6 = (uVar6 & 0x200) << 2;
    local_30 = uVar9 | 0x100 | uVar6;
    uv = puVar7 + 9;
    degrees = 0x80;
    do
    {
      fx_calc_points(&_Stack104, degrees, radius, radius2, radius3);
      uv[-8] = 0x2dc0c0c0;
      uv[-7] = local_48;
      uv[-3] = local_50;
      if ((short)(u_short)local_48 < (short)(u_short)local_50)
      {
        local_50._0_2_ = (u_short)local_48;
      }
      local_50 = getCopReg(2, 0xc);
      local_4c = getCopReg(2, 0xd);
      local_48 = getCopReg(2, 0xe);
      local_40 = getCopReg(2, 0x11);
      local_3c = getCopReg(2, 0x12);
      local_38 = getCopReg(2, 0x13);
      uv[-5] = local_48;
      uv[-1] = local_50;
      uVar1 = (u_short)local_50;
      if ((short)(u_short)local_48 < (short)(u_short)local_50)
      {
        uVar1 = (u_short)local_48;
      }
      if ((short)(u_short)local_50 < (short)uVar1)
      {
        uVar1 = (u_short)local_50;
      }
      tx = (int)(short)(uVar1 & 0xffc0);
      if (tx < -0x3f)
      {
        *(undefined2 *)((int)uv + -0xe) = (undefined2)local_30;
      }
      else
      {
        if (tx < 0)
        {
          uVar3 = (u_short)((int)(tx + 0x400U & 0x3ff) >> 6);
        }
        else
        {
          uVar3 = (u_short)(((u_int)uVar1 & 0x3c0) >> 6);
        }
        *(u_short *)((int)uv + -0xe) = (u_short)uVar9 | uVar3 | 0x100 | (u_short)uVar6;
      }
      tx = (int)(short)(uVar1 & 0xffc0);
      fx_setTex((DVECTOR *)(puVar7 + 2), (u_char *)(puVar7 + 3), tx, offset);
      fx_setTex((DVECTOR *)(puVar7 + 4), (u_char *)(puVar7 + 5), tx, offset);
      fx_setTex((DVECTOR *)(puVar7 + 6), (u_char *)(puVar7 + 7), tx, offset);
      fx_setTex((DVECTOR *)(puVar7 + 8), (u_char *)uv, tx, offset);
      if (local_38 < local_40)
      {
        local_40 = local_38;
      }
      if (local_40 < 0)
      {
        local_40 = local_40 + 3;
      }
      local_40 = local_40 >> 2;
      if (0 < local_40)
      {
        bVar2 = local_40 <= lVar4;
        if ((sortInWorld == 0) && (local_40 = lVar4 + 0x10, bVar2))
        {
          local_40 = 1;
        }
        if (local_40 - 1U < 0xbff)
        {
          uv = uv + 10;
          puVar5 = (u_long *)((u_int)puVar7 & 0xffffff);
          *puVar7 = (u_int)local_34[local_40] & 0xffffff | 0x9000000;
          puVar7 = puVar7 + 10;
          local_34[local_40] = puVar5;
        }
      }
      iVar8 = iVar8 + 1;
      degrees = degrees + 0x80;
    } while (iVar8 < 0x20);
    (gameTrackerX.primPool)->nextPrim = puVar7;
    MulMatrix0();
  }
  return;
}

void FX_DrawFField(MATRIX *wcTransform, _FXForceFieldEffect *field)

{
  u_short uVar1;
  short sVar2;
  int iVar3;
  _Instance *p_Var4;
  int iVar5;
  MATRIX MStack64;
  _SVector local_20;
  u_char local_18;
  u_int local_14;

  p_Var4 = field->instance;
  local_20.x = (p_Var4->position).x + (field->offset).x;
  local_20.y = (p_Var4->position).y + (field->offset).y;
  local_20.z = (p_Var4->position).z + (field->offset).z;
  local_18 = 0;
  iVar3 = rcos((int)field->deg);
  field->deg = field->deg + field->deg_change & 0xfff;
  iVar3 = (int)field->size_diff + (iVar3 * field->size_change >> 0xc);
  uVar1 = field->start_fade - 0x80;
  if (field->start_fade == 0)
  {
    iVar5 = (u_int)(u_short)field->end_fade - 0x80;
    if (field->end_fade == 0)
    {
      sVar2 = 0;
    }
    else
    {
      sVar2 = (short)iVar5;
      field->end_fade = sVar2;
      if (iVar5 * 0x10000 < 1)
      {
        FX_DeleteGeneralEffect((_FXGeneralEffect *)field);
        return;
      }
      sVar2 = 0x1000 - sVar2;
    }
  }
  else
  {
    field->start_fade = uVar1;
    if ((int)((u_int)uVar1 << 0x10) < 0)
    {
      field->start_fade = 0;
    }
    sVar2 = field->start_fade;
  }
  iVar5 = (int)sVar2;
  if (iVar5 == 0)
  {
    local_14 = field->color;
  }
  else
  {
    LoadAverageCol((byte *)&field->color, (byte *)&local_18, 0x1000 - iVar5, iVar5,
                   (undefined *)&local_14);
  }
  local_14 = local_14 & 0xffffff;
  MATH3D_SetUnityMatrix(&MStack64);
  RotMatrixX(0x400, (u_int *)&MStack64);
  RotMatrixZ((int)theCamera.core.rotation.x, (int)&MStack64);
  FX_DrawRing2(wcTransform, &local_20, &MStack64, (int)field->size - iVar3, (int)field->size,
               field->size - iVar3, 0, 0, 0, local_14, 0);
  return;
}

_FXForceFieldEffect *
FX_StartFField(_Instance *instance, int size, _Position *offset, int size_diff, int size_change,
               int deg_change, long color)

{
  short sVar1;
  short sVar2;
  _FXForceFieldEffect *ptr;

  ptr = (_FXForceFieldEffect *)MEMPACK_Malloc(0x2c, '\r');
  if (ptr != (_FXForceFieldEffect *)0x0)
  {
    ptr->effectType = -0x7a;
    ptr->instance = instance;
    ptr->type = '\0';
    ptr->lifeTime = -1;
    ptr->continue_process = (void *)0x0;
    ptr->size = (short)size;
    sVar1 = offset->y;
    sVar2 = offset->z;
    (ptr->offset).x = offset->x;
    (ptr->offset).y = sVar1;
    (ptr->offset).z = sVar2;
    ptr->size_diff = (short)size_diff;
    ptr->deg = 0;
    ptr->size_change = (short)size_change;
    ptr->end_fade = 0;
    ptr->deg_change = (short)deg_change;
    ptr->start_fade = 0x1000;
    ptr->color = color;
    FX_InsertGeneralEffect(ptr);
  }
  return ptr;
}

void FX_EndFField(_Instance *instance)

{
  _FXGeneralEffect **pp_Var1;
  _FXGeneralEffect *p_Var2;

  p_Var2 = FX_GeneralEffectTracker;
  if (FX_GeneralEffectTracker != (_FXGeneralEffect *)0x0)
  {
    do
    {
      if ((p_Var2->instance == instance) && (p_Var2->effectType == -0x7a))
      {
        *(undefined2 *)&p_Var2[2].continue_process = 0x1000;
      }
      pp_Var1 = (_FXGeneralEffect **)&p_Var2->next;
      p_Var2 = *pp_Var1;
    } while (*pp_Var1 != (_FXGeneralEffect *)0x0);
  }
  return;
}

void FX_Draw_Glowing_Line(u_long **ot, long otz, DVECTOR *sxy0, DVECTOR *sxy1, DVECTOR *xy0, DVECTOR *xy1, long color, long color2)

{
  bool bVar1;
  _PrimPool *p_Var2;
  DVECTOR DVar3;
  u_long uVar4;
  u_long *puVar5;

  p_Var2 = gameTrackerX.primPool;
  if ((otz - 1U < 0xbff) &&
      (puVar5 = (gameTrackerX.primPool)->nextPrim, puVar5 + 0x12 < (gameTrackerX.primPool)->lastPrim))
  {
    bVar1 = (color & 0x1000000U) == 0;
    if (!bVar1)
    {
      color = color & 0xffffff;
    }
    puVar5[6] = color | 0x3a000000U;
    puVar5[10] = color | 0x3a000000U;
    puVar5[2] = 0x3a000000;
    puVar5[4] = 0;
    puVar5[8] = color2;
    puVar5[0xc] = color2;
    puVar5[0xe] = 0;
    puVar5[0x10] = 0;
    DVar3 = *sxy0;
    *(DVECTOR *)(puVar5 + 0xb) = DVar3;
    *(DVECTOR *)(puVar5 + 7) = DVar3;
    *(short *)(puVar5 + 3) = sxy0->vx + xy0->vx;
    *(short *)((int)puVar5 + 0xe) = sxy0->vy - xy0->vy;
    *(short *)(puVar5 + 0xf) = sxy0->vx - xy0->vx;
    *(short *)((int)puVar5 + 0x3e) = sxy0->vy + xy0->vy;
    DVar3 = *sxy1;
    *(DVECTOR *)(puVar5 + 0xd) = DVar3;
    *(DVECTOR *)(puVar5 + 9) = DVar3;
    *(short *)(puVar5 + 5) = sxy1->vx + xy1->vx;
    *(short *)((int)puVar5 + 0x16) = sxy1->vy - xy1->vy;
    *(short *)(puVar5 + 0x11) = sxy1->vx - xy1->vx;
    *(short *)((int)puVar5 + 0x46) = sxy1->vy + xy1->vy;
    if (bVar1)
    {
      uVar4 = 0xe1000620;
    }
    else
    {
      uVar4 = 0xe1000640;
    }
    puVar5[1] = uVar4;
    *puVar5 = (u_int)ot[otz] & 0xffffff | 0x11000000;
    ot[otz] = (u_long *)((u_int)puVar5 & 0xffffff);
    p_Var2->nextPrim = puVar5 + 0x12;
  }
  return;
}

void FX_CreateLightning(MATRIX *wcTransform, u_long **ot, MATRIX *mat, short deg, _SVector *start,
                        _SVector *end, int width, int small_width, int segs, int sine_size, int variation,
                        long color, long glow_color)

{
  u_char in_zero;
  u_char in_at;
  int iVar1;
  int iy;
  int ix;
  u_int uVar2;
  int iVar3;
  u_int uVar4;
  int iVar5;
  int otz;
  DVECTOR local_70[2];
  DVECTOR local_68[2];
  DVECTOR local_60[2];
  DVECTOR local_58[2];
  DVECTOR local_50[2];
  DVECTOR local_48[2];
  u_char local_40;
  u_int local_3c;
  int local_38;
  int local_34;
  u_int local_30;

  local_30 = (u_int)(u_short)deg & 0xfff;
  if (mat == (MATRIX *)0x0)
  {
    SetRotMatrix((u_char *)wcTransform);
  }
  else
  {
    SetRotMatrix((u_char *)mat);
    wcTransform = mat;
  }
  otz = 0x7fff;
  TransMatrix((int)wcTransform);
  width = width * 0x140;
  small_width = small_width * 0x140;
  segs;
  iVar5 = 0;
  local_60[0] = (DVECTOR)0x0;
  local_50[0] = (DVECTOR)0x0;
  if (-1 < segs)
  {
    do
    {
      LoadAverageShort12((u_int *)start, (u_int *)end, 0x1000 - iVar5, iVar5, &local_40);
 2);
 if ((variation == 0) || (segs == 0))
 {
 LAB_8004f4d4:
   if (mat != (MATRIX *)0x0)
     goto LAB_8004f4e4;
 }
 else
 {
   if (mat == (MATRIX *)0x0)
   {
     iy = rsin(iVar5 << 2);
     ix = rand();
     2;
     ix = (ix % variation - iVar3) * iy;
     if (ix < 0)
     {
       ix = ix + 0xfff;
     }
     local_40 = local_40 & 0xffff0000 | (u_int)(u_short)((short)local_40 + (short)(ix >> 0xc));
     ix = rand();
     iy = (ix % variation - iVar3) * iy;
     if (iy < 0)
     {
       iy = iy + 0xfff;
     }
     local_40 = local_40 & 0xffff | (u_int)(u_short)(local_40._2_2_ + (short)(iy >> 0xc)) << 0x10;
     iy = rsin(iVar5 + local_30);
     ix = rand();
     iy = iy * sine_size;
     if (iy < 0)
     {
       iy = iy + 0xfff;
     }
     iy = (iy >> 0xc) * iVar1;
     if (iy < 0)
     {
       iy = iy + 0xfff;
     }
     local_3c = local_3c & 0xffff0000 |
                (u_int)(u_short)((short)local_3c +
                                 (short)(iy >> 0xc) + ((short)(ix % variation) - (short)iVar3));
     goto LAB_8004f4d4;
   }
 LAB_8004f4e4:
   uVar4 = local_30 + segs * 0x200;
   iy = rcos(uVar4);
   uVar2 = rand();
   iy = iy * sine_size;
   if (iy < 0)
   {
     iy = iy + 0xfff;
   }
   iy = ((iy >> 0xc) + (uVar2 & 7)) * iVar1;
   if (iy < 0)
   {
     iy = iy + 0xfff;
   }
   local_40 = local_40 & 0xffff0000 | iy >> 0xc & 0xffffU;
   iy = rsin(uVar4);
   uVar2 = rand();
   iy = iy * sine_size;
   if (iy < 0)
   {
     iy = iy + 0xfff;
   }
   iVar1 = ((iy >> 0xc) + (uVar2 & 7)) * iVar1;
   if (iVar1 < 0)
   {
     iVar1 = iVar1 + 0xfff;
   }
   local_40 = local_40 & 0xffff | (iVar1 >> 0xc) << 0x10;
   iVar1 = rand();
   local_3c = local_3c & 0xffff0000 | (u_int)(u_short)((short)local_3c + ((u_short)iVar1 & 7));
 }
 setCopReg(2, in_zero, local_40);
 setCopReg(2, in_at, local_3c);
 copFunction(2, 0x180001);
 local_68[0] = getCopReg(2, 0xe);
 local_38 = getCopReg(2, 0x13);
 if (otz < local_38)
 {
   if (otz < 0)
   {
     otz = otz + 3;
   }
 }
 else
 {
   otz = local_38;
   if (local_38 < 0)
   {
     otz = local_38 + 3;
   }
 }
 otz = otz >> 2;
 if ((segs == 0) || (iVar5 == 0))
 {
   local_58[0] = (DVECTOR)0x0;
   local_48[0] = (DVECTOR)0x0;
 }
 else
 {
   ix = (int)local_68[0].vx - (int)local_70[0].vx;
   local_68[0].vy = (short)((u_int)local_68[0] >> 0x10);
   iy = (int)local_68[0].vy - (int)local_70[0].vy;
   iVar1 = MATH3D_veclen2(ix, iy);
   iVar1 = iVar1 * local_38;
   if (iVar1 < 1)
   {
     iVar1 = 1;
   }
 iVar1 << 0x10);
 iVar1 & 0xffffU |
 iVar1 << 0x10);
 }
 if (((iVar5 != 0) && (0 < otz)) && (otz < 0xc00))
 {
   if (width != 0)
   {
     FX_Draw_Glowing_Line(ot, otz, local_70, local_68, local_60, local_58, glow_color, glow_color);
   }
   if ((0 < otz + -5) && (small_width != 0))
   {
     FX_Draw_Glowing_Line(ot, otz + -5, local_70, local_68, local_50, local_48, color, color);
   }
 }
 segs = segs + -1;
 local_70[0] = local_68[0];
 local_60[0] = local_58[0];
 local_50[0] = local_48[0];
 iVar5 = iVar5 + local_34;
 otz = local_38;
    } while (-1 < segs);
  }
  return;
}

void FX_LightHouse(MATRIX *wcTransform, u_long **ot, _Instance *instance, int startSeg, int endSeg,
                   int segs, long beam_color)

{
  bool bVar1;
  u_char in_zero;
  u_char in_at;
  long lVar2;
  int iVar3;
  int iVar4;
  MATRIX *pMVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  _Position local_88;
  _Position local_80;
  DVECTOR local_78[2];
  DVECTOR local_70[2];
  DVECTOR local_68[2];
  DVECTOR local_60[2];
  u_int local_58;
  u_char local_54;
  u_int local_50;
  u_char local_4c;
  int local_48;
  long local_44;
  u_char local_40;
  long local_3c;
  long local_38;
  int local_34;
  int local_30;
  int local_2c;

  bVar1 = false;
  if ((instance->flags & 0x800U) == 0)
  {
    if (instance->matrix != (MATRIX *)0x0)
    {
      pMVar5 = instance->matrix + startSeg;
      local_88.x = *(short *)pMVar5->t;
      local_88.y = *(short *)(pMVar5->t + 1);
      local_88.z = *(short *)(pMVar5->t + 2);
      pMVar5 = instance->matrix + endSeg;
      local_80.x = *(short *)pMVar5->t;
      local_80.y = *(short *)(pMVar5->t + 1);
      local_80.z = *(short *)(pMVar5->t + 2);
      SetRotMatrix((u_char *)wcTransform);
      TransMatrix((int)wcTransform);
      local_38 = beam_color;
      local_68[0] = (DVECTOR)0x0;
      local_3c = beam_color;
      local_44 = beam_color;
      local_40 = 0;
      lVar2 = MATH3D_DistanceBetweenPositions(&local_88, &local_80);
 2) * 0x420;
 iVar9 = 0;
 if (iVar3 < 0)
 {
   iVar3 = iVar3 + 0xfff;
 }
 iVar8 = 0;
 local_2c = (iVar3 >> 0xc) + 0x60;
 local_30 = 0;
 local_34 = 0;
 iVar3 = segs;
 if (segs < 0)
 {
   iVar3 = segs + 3;
 }
 iVar3 = iVar3 >> 2;
 iVar3;
 if (-1 < iVar3)
 {
   do
   {
     LoadAverageShort12((u_int *)&local_88, (u_int *)&local_80, 0x1000 - iVar8, iVar8, &local_58);
     setCopReg(2, in_zero, local_58);
     setCopReg(2, in_at, local_54);
     copFunction(2, 0x180001);
     local_70[0] = getCopReg(2, 0xe);
     local_48 = getCopReg(2, 0x13);
     if (bVar1)
     {
       if (0xf0 < local_48)
       {
         iVar6 = (int)local_70[0].vx;
         if ((-0x200 < iVar6) && (iVar6 < 0x200))
         {
           local_70[0].vy = (short)((u_int)local_70[0] >> 0x10);
           iVar4 = MATH3D_veclen2(iVar6 - local_78[0].vx,
                                  (int)local_70[0].vy - (int)local_78[0].vy);
           if ((iVar9 < iVar4) && (iVar4 < 0x100))
           {
             iVar9 = iVar4;
             local_34 = iVar6 - local_78[0].vx;
             local_30 = (int)local_70[0].vy - (int)local_78[0].vy;
           }
         }
         goto LAB_8004f9d8;
       }
     }
     else
     {
     LAB_8004f9d8:
       if (0xf0 < local_48)
       {
         bVar1 = true;
         local_78[0] = local_70[0];
       }
     }
     iVar3 = iVar3 + -1;
     iVar8 = iVar8 + iVar10;
   } while (-1 < iVar3);
 }
 if (iVar9 != 0)
 {
   segs;
   iVar3 = 0;
   if (-1 < segs)
   {
     iVar6 = 0;
     iVar10 = 0x7fff;
     do
     {
       LoadAverageShort12((u_int *)&local_88, (u_int *)&local_80, 0x1000 - iVar3, iVar3, &local_50);
       iVar4 = (local_2c + -0x60) * iVar3;
       if (iVar4 < 0)
       {
         iVar4 = iVar4 + 0xfff;
       }
       iVar7 = ((iVar4 >> 0xc) + 0x60) * 0x140;
       iVar4 = 0x1000 - iVar6;
       if ((0x7ff < iVar3) && (iVar4 = 0, 0x800 < iVar3))
       {
         iVar4 = iVar6 + -0x1000;
       }
       LoadAverageCol((byte *)&local_44, (byte *)&local_40, 0x1000 - iVar4, iVar4,
                      (undefined *)&local_3c);
       setCopReg(2, in_zero, local_50);
       setCopReg(2, in_at, local_4c);
       copFunction(2, 0x180001);
       local_70[0] = getCopReg(2, 0xe);
       local_48 = getCopReg(2, 0x13);
       if (iVar10 < local_48)
       {
         if (iVar10 < 0)
         {
           iVar10 = iVar10 + 3;
         }
       }
       else
       {
         iVar10 = local_48;
         if (local_48 < 0)
         {
           iVar10 = local_48 + 3;
         }
       }
       if (iVar3 != 0)
       {
         if (local_48 < 1)
         {
           local_48 = 1;
         }
 0x140 &
 (iVar9 * local_48) << 0x10);
       }
       if (iVar3 == iVar8)
       {
         local_68[0] = local_60[0];
       }
       if ((iVar3 != 0) && (0 < iVar10 >> 2))
       {
         FX_Draw_Glowing_Line(ot, iVar10 >> 2, local_78, local_70, local_68, local_60, local_38, local_3c);
       }
       iVar6 = iVar6 + iVar8 * 2;
       iVar3 = iVar3 + iVar8;
       local_38 = local_3c;
       local_78[0] = local_70[0];
       local_68[0] = local_60[0];
       segs = segs + -1;
       iVar10 = local_48;
     } while (-1 < segs);
   }
 }
    }
  }
  return;
}

void FX_StartPassthruFX(_Instance *instance, _SVector *normal, _SVector *point)

{
  long local_18[2];

  (instance->halvePlane).a = normal->x;
  (instance->halvePlane).b = normal->y;
  (instance->halvePlane).c = normal->z;
  local_18[0] = 0x20ff40;
  (instance->halvePlane).d =
      -((int)normal->x * (int)point->x + (int)normal->y * (int)point->y +
            (int)normal->z * (int)point->z >>
        0xc);
  FX_DoInstancePowerRing(instance, (long)&DAT_000020d0, local_18, 0, 2);
  FX_DoInstancePowerRing(instance, (long)&DAT_000020d0, local_18, 0, 1);
  return;
}

void FX_EndPassthruFX(_Instance *instance)

{
  FX_EndInstanceEffects(instance);
  return;
}
