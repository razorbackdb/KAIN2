#include "THISDUST.H"
#include "PIPE3D.H"

void PIPE3D_AspectAdjustMatrix(MATRIX *matrix)

{
  short sVar1;
  short sVar2;
  short sVar3;

  sVar1 = matrix->m[0];
  sVar2 = matrix->m[1];
  sVar3 = matrix->m[2];
  matrix->m[3] = matrix->m[3];
  matrix->m[4] = matrix->m[4];
  matrix->m[5] = matrix->m[5];
 0x140);
 0x140);
 0x140);
 return;
}

void PIPE3D_CalculateWCTransform(_CameraCore_Type *cameraCore)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  u_char in_zero;
  u_char in_at;
  MATRIX *matrix;
  MATRIX MStack112;
  undefined2 local_50;
  undefined2 local_4e;
  undefined2 local_4c;
  undefined2 local_4a;
  undefined2 local_48;
  undefined2 local_46;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  u_char local_30;
  u_int local_2c;
  u_char local_28;
  u_char local_24;
  u_char local_20;

  matrix = cameraCore->wcTransform;
  local_30 = CONCAT22(-(cameraCore->position).y, -(cameraCore->position).x);
  local_2c = local_2c & 0xffff0000 | (u_int)(u_short) - (cameraCore->position).z;
  if ((gameTrackerX.debugFlags & 8U) == 0)
  {
    MATH3D_SetUnityMatrix(&MStack112);
    RotMatrixX(-(int)(cameraCore->rotation).z, (u_int *)&MStack112);
    RotMatrixZ(-(int)(cameraCore->rotation).x, (int)&MStack112);
    RotMatrix(-(int)(cameraCore->rotation).y, (u_int *)&MStack112);
    local_30 = CONCAT22(-(cameraCore->position).y, -(cameraCore->position).x);
    local_2c = local_2c & 0xffff0000 | (u_int)(u_short) - (cameraCore->position).z;
  }
  else
  {
    MATH3D_SetUnityMatrix(&MStack112);
    RotMatrixX(-(int)(cameraCore->debugRot).z, (u_int *)&MStack112);
    RotMatrix(-(int)(cameraCore->debugRot).y, (u_int *)&MStack112);
    RotMatrixZ(-(int)(cameraCore->debugRot).x, (int)&MStack112);
    local_30 = CONCAT22(-(cameraCore->debugPos).y, -(cameraCore->debugPos).x);
    local_2c = local_2c & 0xffff0000 | (u_int)(u_short) - (cameraCore->debugPos).z;
    sVar1 = (cameraCore->position).y;
    sVar2 = (cameraCore->position).z;
    sVar3 = (cameraCore->debugPos).x;
    sVar4 = (cameraCore->debugPos).y;
    sVar5 = (cameraCore->debugPos).z;
    (cameraCore->nondebugPos).x = (cameraCore->position).x;
    (cameraCore->nondebugPos).y = sVar1;
    (cameraCore->nondebugPos).z = sVar2;
    (cameraCore->position).x = sVar3;
    (cameraCore->position).y = sVar4;
    (cameraCore->position).z = sVar5;
  }
  local_50 = 0x1000;
  local_4e = 0;
  local_4c = 0;
  local_4a = 0;
  local_48 = 0;
  local_46 = 0xf000;
  local_44 = 0;
  local_42 = 0x1000;
  local_40 = 0;
  PopMatrix((u_char *)&local_50, (u_short *)&MStack112, (u_int *)matrix);
  PopMatrix((u_char *)&local_50, (u_short *)&MStack112, (u_int *)cameraCore->wcTransform2);
  PIPE3D_AspectAdjustMatrix(matrix);
  sVar1 = matrix->m[1];
  matrix->m[0] = (short)((int)matrix->m[0] * (int)(cameraCore->screenScale).x >> 0xc);
  matrix->m[1] = (short)((int)sVar1 * (int)(cameraCore->screenScale).x >> 0xc);
  matrix->m[2] = (short)((int)matrix->m[2] * (int)(cameraCore->screenScale).x >> 0xc);
  matrix->m[3] = (short)((int)matrix->m[3] * (int)(cameraCore->screenScale).y >> 0xc);
  matrix->m[4] = (short)((int)matrix->m[4] * (int)(cameraCore->screenScale).y >> 0xc);
  matrix->m[5] = (short)((int)matrix->m[5] * (int)(cameraCore->screenScale).y >> 0xc);
  matrix->m[6] = (short)((int)matrix->m[6] * (int)(cameraCore->screenScale).z >> 0xc);
  matrix->m[7] = (short)((int)matrix->m[7] * (int)(cameraCore->screenScale).z >> 0xc);
  matrix->m[8] = (short)((int)matrix->m[8] * (int)(cameraCore->screenScale).z >> 0xc);
  setCopControlWord(2, 0, *(u_char *)matrix->m);
  setCopControlWord(2, 0x800, *(u_char *)(matrix->m + 2));
  setCopControlWord(2, 0x1000, *(u_char *)(matrix->m + 4));
  setCopControlWord(2, 0x1800, *(u_char *)(matrix->m + 6));
  setCopControlWord(2, 0x2000, *(u_char *)(matrix->m + 8));
  setCopReg(2, in_zero, local_30);
  setCopReg(2, in_at, local_2c);
  copFunction(2, 0x486012);
  local_28 = getCopReg(2, 0x19);
  local_24 = getCopReg(2, 0x1a);
  local_20 = getCopReg(2, 0x1b);
  SetTransMatrix((int)matrix, &local_28);
  matrix = cameraCore->wcTransform2;
  setCopControlWord(2, 0, *(u_char *)matrix->m);
  setCopControlWord(2, 0x800, *(u_char *)(matrix->m + 2));
  setCopControlWord(2, 0x1000, *(u_char *)(matrix->m + 4));
  setCopControlWord(2, 0x1800, *(u_char *)(matrix->m + 6));
  setCopControlWord(2, 0x2000, *(u_char *)(matrix->m + 8));
  setCopReg(2, in_zero, local_30);
  setCopReg(2, in_at, local_2c);
  copFunction(2, 0x486012);
  local_28 = getCopReg(2, 0x19);
  local_24 = getCopReg(2, 0x1a);
  local_20 = getCopReg(2, 0x1b);
  SetTransMatrix((int)cameraCore->wcTransform2, &local_28);
  return;
}

void PIPE3D_InstanceListTransformAndDraw(MATRIX *target, MATRIX *source)

{
  MATRIX *pMVar1;
  u_int local_40;
  int local_3c;
  int local_38;
  MATRIX MStack48;

  pMVar1 = source;
  if (*(short *)&source->field_0x12 == 1)
  {
    MATH3D_Normalize(&MStack48, source);
    pMVar1 = &MStack48;
  }
  TransposeMatrix((u_char *)pMVar1, (u_char *)target);
  local_40 = -source->t[0];
  local_3c = -source->t[1];
  local_38 = -source->t[2];
  ApplyMatrixLV((u_char *)target, &local_40, target->t);
  return;
}

long PIPE3D_MatrixColumnLength(MATRIX *transform, long column)

{
  short *psVar1;
  u_long square;
  long lVar2;

  psVar1 = transform->m + column;
  square = MATH3D_SquareLength((int)*psVar1, (int)psVar1[3], (int)psVar1[6]);
  lVar2 = MATH3D_FastSqrt0(square);
  return lVar2;
}

void MATH3D_Normalize(MATRIX *target, MATRIX *source)

{
  long lVar1;
  u_char uVar2;
  long lVar3;
  u_char uVar4;
  u_char uVar5;
  long local_20;
  long local_1c;
  long local_18;

  local_20 = PIPE3D_MatrixColumnLength(source, 0);
  if (local_20 != 0)
  {
    local_20;
  }
  local_1c = PIPE3D_MatrixColumnLength(source, 1);
  if (local_1c != 0)
  {
    local_1c;
  }
  local_18 = PIPE3D_MatrixColumnLength(source, 2);
  if (local_18 != 0)
  {
    local_18;
  }
  lVar1 = source->t[1];
  lVar3 = source->t[2];
  target->t[0] = source->t[0];
  target->t[1] = lVar1;
  target->t[2] = lVar3;
  uVar2 = *(u_char *)(source->m + 2);
  uVar4 = *(u_char *)(source->m + 4);
  uVar5 = *(u_char *)(source->m + 6);
  *(u_char *)target->m = *(u_char *)source->m;
  *(u_char *)(target->m + 2) = uVar2;
  *(u_char *)(target->m + 4) = uVar4;
  *(u_char *)(target->m + 6) = uVar5;
  *(u_char *)(target->m + 8) = *(u_char *)(source->m + 8);
  ScaleMatrix((int *)target, &local_20);
  return;
}

void PIPE3D_TransformVerticesToWorld(_Instance *instance, _SVector *poolVertex, long *vtxSegment, _Vector *Average)

{
  u_char in_zero;
  u_char in_at;
  _Segment *p_Var1;
  short *psVar2;
  short *psVar3;
  _MVertex *p_Var4;
  u_char uVar5;
  u_char uVar6;
  u_char uVar7;
  _MVertex *p_Var8;
  MATRIX *pMVar9;
  _SVector *p_Var10;
  int iVar11;
  _MVertex *p_Var12;
  _Model *p_Var13;
  u_char local_40;
  short local_3c;
  u_char local_38;
  short local_34;

  p_Var13 = instance->object->modelList[instance->currentModel];
  p_Var4 = p_Var13->vertexList;
  p_Var1 = p_Var13->segmentList;
  local_40 = 0x7fff7fff;
  local_3c = 0x7fff;
  local_38 = (undefined *)0x80018001;
  local_34 = -0x7fff;
  Average->x = 0;
  Average->y = 0;
  Average->z = 0;
  iVar11 = 0;
  if (0 < p_Var13->numSegments)
  {
    psVar3 = &p_Var1->firstVertex;
    p_Var10 = poolVertex;
    local_34 = -0x7fff;
    local_3c = 0x7fff;
    do
    {
      if ((int)psVar3[1] != -1)
      {
        pMVar9 = instance->matrix;
        p_Var8 = p_Var4 + *psVar3;
        p_Var12 = p_Var4 + (int)psVar3[1];
        SetRotMatrix((u_char *)(pMVar9 + iVar11));
        TransMatrix((int)(pMVar9 + iVar11));
        if (p_Var8 <= p_Var12)
        {
          psVar2 = &p_Var10->z;
          do
          {
            setCopReg(2, in_zero, *(u_char *)&p_Var8->vertex);
            setCopReg(2, in_at, *(u_char *)&(p_Var8->vertex).z);
            copFunction(2, 0x480012);
            *vtxSegment = iVar11;
            vtxSegment = vtxSegment + 1;
            p_Var8 = p_Var8 + 1;
            uVar5 = getCopReg(2, 0x4800);
            uVar6 = getCopReg(2, 0x5000);
            uVar7 = getCopReg(2, 0x5800);
            p_Var10->x = (short)uVar5;
            p_Var10->y = (short)uVar6;
            p_Var10->z = (short)uVar7;
            if ((short)local_38 < p_Var10->x)
            {
              local_38 = (undefined *)((u_int)local_38 & 0xffff0000 | (u_int)(u_short)p_Var10->x);
            }
            if (p_Var10->x < (short)local_40)
            {
              local_40 = local_40 & 0xffff0000 | (u_int)(u_short)p_Var10->x;
            }
            if (local_38._2_2_ < psVar2[-1])
            {
              local_38 = (undefined *)((u_int)local_38 & 0xffff | (u_int)(u_short)psVar2[-1] << 0x10);
            }
            if (psVar2[-1] < local_40._2_2_)
            {
              local_40 = local_40 & 0xffff | (u_int)(u_short)psVar2[-1] << 0x10;
            }
            if (local_34 < *psVar2)
            {
              local_34 = *psVar2;
            }
            if (*psVar2 < local_3c)
            {
              local_3c = *psVar2;
            }
            psVar2 = psVar2 + 4;
            p_Var10 = p_Var10 + 1;
          } while (p_Var8 <= p_Var12);
        }
      }
      iVar11 = iVar11 + 1;
      psVar3 = psVar3 + 0xc;
    } while (iVar11 < p_Var13->numSegments);
  }
  if (p_Var13->numVertices != 0)
  {
    Average->x = (int)(short)local_38 + (int)(short)local_40 >> 1;
    Average->y = (int)local_38._2_2_ + (int)local_40._2_2_ >> 1;
    Average->z = (int)local_34 + (int)local_3c >> 1;
    iVar11 = 0;
    if (0 < p_Var13->numVertices)
    {
      psVar3 = &poolVertex->z;
      do
      {
        poolVertex->x = poolVertex->x - *(short *)&Average->x;
        iVar11 = iVar11 + 1;
        psVar3[-1] = psVar3[-1] - *(short *)&Average->y;
        poolVertex = poolVertex + 1;
        *psVar3 = *psVar3 - *(short *)&Average->z;
        psVar3 = psVar3 + 4;
      } while (iVar11 < p_Var13->numVertices);
    }
  }
  return;
}

void PIPE3D_InstanceListTransformAndDrawFunc(_Instance *instance, _CameraCore_Type *cameraCore, _VertexPool *vertexPool,
                                             _PrimPool *primPool, u_long **ot, _Mirror *mirror)

{
  u_char uVar1;
  u_char uVar2;
  u_char in_zero;
  u_char in_at;
  u_int uVar3;
  u_long *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  _MVertex *p_Var8;
  u_char uVar9;
  MATRIX *pMVar10;
  _Model *p_Var11;
  CVECTOR *pCVar12;
  MATRIX MStack80;
  int local_30;
  u_char local_2c;

  pMVar10 = instance->matrix;
  p_Var11 = instance->object->modelList[instance->currentModel];
  if (pMVar10 != (MATRIX *)0x0)
  {
    LIGHT_PresetInstanceLight(instance, 0x800, &MStack80);
    pCVar12 = vertexPool->color;
    iVar6 = 0xe0;
    iVar7 = p_Var11->numVertices;
    p_Var8 = p_Var11->vertexList;
    iVar5 = 0x20;
    if (iVar7 * 2 < 0xe1)
    {
      vertexPool = (_VertexPool *)&DAT_1f800080;
      iVar5 = iVar7 * 2 + 0x20;
      iVar6 = iVar7 * -2 + 0xe0;
    }
    if (iVar7 <= iVar6)
    {
      pCVar12 = (CVECTOR *)(iVar5 * 4 + 0x1f800000);
    }
    modelFadeValue = INSTANCE_GetFadeValue(instance);
    uVar3 = PIPE3D_TransformAnimatedInstanceVertices_S((int)p_Var8, (u_char *)vertexPool, (u_int)p_Var11,
                                                       (u_char *)cameraCore->wcTransform, (u_short *)pMVar10,
                                                       (u_char *)&MStack80, (u_int *)pCVar12, (u_int *)instance->perVertexColor);
    LIGHT_PresetInstanceLight(instance, 0x1000, &MStack80);
    PopMatrix((u_char *)&MStack80, (u_short *)(pMVar10 + instance->lightMatrix), (u_int *)&MStack80);
    SetLightMatrix((u_char *)&MStack80);
    if ((uVar3 & 0x8000) != 0)
    {
      uVar3 = uVar3 & 0x7fff6fff;
    }
    if ((((uVar3 & 0xffffefff) == 0) || ((instance->object->oflags2 & 0x2000U) != 0)) &&
        (primPool->nextPrim + p_Var11->numFaces * 0xc < primPool->lastPrim))
    {
      local_2c = 0;
      if ((instance->object->oflags2 & 0x1000U) == 0)
      {
        SetRotMatrix((u_char *)theCamera.core.wcTransform);
        TransMatrix((int)theCamera.core.wcTransform);
        setCopReg(2, in_zero, *(u_char *)&instance->position);
        setCopReg(2, in_at, *(u_char *)&(instance->position).z);
        copFunction(2, 0x180001);
      }
      uVar2 = depthQBackColor;
      uVar1 = depthQBlendStart;
      local_30 = getCopReg(2, 8);
      uVar9 = 0;
      if (instance->petrifyValue != 0)
      {
        depthQBackColor = 0x707070;
        local_2c = uVar2;
        depthQBlendStart = depthQFogStart;
        LoadAverageCol((byte *)&local_2c, (byte *)&depthQBackColor, local_30, 0x1000 - local_30,
                       (undefined *)&depthQBackColor);
        uVar9 = uVar1;
        if (instance->petrifyValue < local_30)
        {
          setCopReg(2, 0x4000, local_30);
        }
        else
        {
          setCopReg(2, 0x4000, (u_int)(u_short)instance->petrifyValue);
        }
      }
      if ((modelFadeValue < 0xffe) &&
          (((instance->object->oflags2 & 0x1000U) != 0 || (local_30 < 0xffa))))
      {
        puVar4 = (u_long *)(*(code *)gameTrackerX.drawAnimatedModelFunc)(p_Var11, vertexPool, primPool, ot, pCVar12);
        primPool->nextPrim = puVar4;
      }
      if (instance->petrifyValue != 0)
      {
        depthQBackColor = local_2c;
        depthQBlendStart = uVar9;
      }
    }
  }
  return;
}

void PIPE3D_ExtentsOfPrims(long *firstPrim, long *lastPrim, long *pminx, long *pminy, long *pmaxx, long *pmaxy)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;

  iVar3 = 0x7ff;
  iVar4 = 0x7ff;
  iVar5 = -0x7ff;
  iVar6 = -0x7ff;
  if (firstPrim < lastPrim)
  {
    do
    {
      if (*(char *)((int)firstPrim + 7) == '$')
      {
        iVar2 = (int)*(short *)(firstPrim + 2);
        if (iVar2 < iVar3)
        {
          iVar3 = iVar2;
        }
        if (iVar5 < iVar2)
        {
          iVar5 = iVar2;
        }
        iVar2 = (int)*(short *)(firstPrim + 4);
        if (iVar2 < iVar3)
        {
          iVar3 = iVar2;
        }
        if (iVar5 < iVar2)
        {
          iVar5 = iVar2;
        }
        iVar2 = (int)*(short *)(firstPrim + 6);
        if (iVar2 < iVar3)
        {
          iVar3 = iVar2;
        }
        if (iVar5 < iVar2)
        {
          iVar5 = iVar2;
        }
        iVar2 = (int)*(short *)((int)firstPrim + 10);
        if (iVar2 < iVar4)
        {
          iVar4 = iVar2;
        }
        if (iVar6 < iVar2)
        {
          iVar6 = iVar2;
        }
        iVar2 = (int)*(short *)((int)firstPrim + 0x12);
        if (iVar2 < iVar4)
        {
          iVar4 = iVar2;
        }
        if (iVar6 < iVar2)
        {
          iVar6 = iVar2;
        }
        iVar2 = (int)*(short *)((int)firstPrim + 0x1a);
        bVar1 = iVar2 < iVar4;
      LAB_8003b4e8:
        if (bVar1)
        {
          iVar4 = iVar2;
        }
        if (iVar6 < iVar2)
        {
          iVar6 = iVar2;
        }
      }
      else
      {
        if (*(char *)((int)firstPrim + 7) == '4')
        {
          iVar2 = (int)*(short *)(firstPrim + 2);
          if (iVar2 < iVar3)
          {
            iVar3 = iVar2;
          }
          if (iVar5 < iVar2)
          {
            iVar5 = iVar2;
          }
          iVar2 = (int)*(short *)(firstPrim + 5);
          if (iVar2 < iVar3)
          {
            iVar3 = iVar2;
          }
          if (iVar5 < iVar2)
          {
            iVar5 = iVar2;
          }
          iVar2 = (int)*(short *)(firstPrim + 8);
          if (iVar2 < iVar3)
          {
            iVar3 = iVar2;
          }
          if (iVar5 < iVar2)
          {
            iVar5 = iVar2;
          }
          iVar2 = (int)*(short *)((int)firstPrim + 10);
          if (iVar2 < iVar4)
          {
            iVar4 = iVar2;
          }
          if (iVar6 < iVar2)
          {
            iVar6 = iVar2;
          }
          iVar2 = (int)*(short *)((int)firstPrim + 0x16);
          if (iVar2 < iVar4)
          {
            iVar4 = iVar2;
          }
          if (iVar6 < iVar2)
          {
            iVar6 = iVar2;
          }
          iVar2 = (int)*(short *)((int)firstPrim + 0x22);
          bVar1 = iVar2 < iVar4;
          goto LAB_8003b4e8;
        }
      }
      firstPrim = firstPrim + (u_int) * (byte *)((int)firstPrim + 3) + 1;
    } while (firstPrim < lastPrim);
  }
  *pminx = iVar3;
  *pminy = iVar4;
  *pmaxx = iVar5;
  *pmaxy = iVar6;
  return;
}

void PIPE3D_AddPredatorEffect_Scale(long *firstPrim, long *lastPrim)

{
  byte bVar1;
  u_short uVar2;
  char cVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  u_int uVar7;
  int iVar8;
  int iVar9;
  u_int uVar10;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;

  uVar10 = (gameTrackerX.gameData.asmData.dispPage ^ 1U) << 8;
  PIPE3D_ExtentsOfPrims(firstPrim, lastPrim, &local_38, &local_34, &local_30, &local_2c);
  iVar8 = local_34 + local_2c >> 1;
  iVar9 = local_38 + local_30 >> 1;
  if (firstPrim < lastPrim)
  {
    do
    {
      bVar1 = *(byte *)((int)firstPrim + 3);
      sVar4 = (short)iVar9;
      sVar5 = (short)iVar8;
      if (*(char *)((int)firstPrim + 7) == '$')
      {
        uVar2 = *(u_short *)(firstPrim + 2);
        if (*(short *)(firstPrim + 2) < *(short *)(firstPrim + 4))
        {
          iVar6 = (u_int) * (u_short *)(firstPrim + 6) << 0x10;
          if (*(short *)(firstPrim + 2) < *(short *)(firstPrim + 6))
          {
          LAB_8003b638:
            iVar6 = (u_int)uVar2 << 0x10;
          }
        }
        else
        {
          iVar6 = (u_int) * (u_short *)(firstPrim + 6) << 0x10;
          uVar2 = *(u_short *)(firstPrim + 4);
          if (*(short *)(firstPrim + 4) < *(short *)(firstPrim + 6))
            goto LAB_8003b638;
        }
        uVar7 = iVar6 >> 0x10 & 0xffffffc0;
        cVar3 = (char)uVar7;
        *(char *)(firstPrim + 3) = *(char *)(firstPrim + 2) - cVar3;
        *(undefined *)((int)firstPrim + 0xd) = *(undefined *)((int)firstPrim + 10);
        *(char *)(firstPrim + 5) = *(char *)(firstPrim + 4) - cVar3;
        *(undefined *)((int)firstPrim + 0x15) = *(undefined *)((int)firstPrim + 0x12);
        *(char *)(firstPrim + 7) = *(char *)(firstPrim + 6) - cVar3;
        *(undefined *)((int)firstPrim + 0x1d) = *(undefined *)((int)firstPrim + 0x1a);
        uVar7 = GetTPage(2, 0, uVar7, uVar10);
        *(undefined2 *)((int)firstPrim + 0x16) = (short)uVar7;
        *(short *)(firstPrim + 2) =
            (short)((*(short *)(firstPrim + 2) - iVar9) * 0x1200 >> 0xc) + sVar4;
        *(byte *)((int)firstPrim + 7) = *(byte *)((int)firstPrim + 7) | 1;
        *(short *)(firstPrim + 4) =
            (short)((*(short *)(firstPrim + 4) - iVar9) * 0x1200 >> 0xc) + sVar4;
        *(short *)(firstPrim + 6) =
            (short)((*(short *)(firstPrim + 6) - iVar9) * 0x1200 >> 0xc) + sVar4;
        *(short *)((int)firstPrim + 10) =
            (short)((*(short *)((int)firstPrim + 10) - iVar8) * 0x1200 >> 0xc) + sVar5;
        *(short *)((int)firstPrim + 0x12) =
            (short)((*(short *)((int)firstPrim + 0x12) - iVar8) * 0x1200 >> 0xc) + sVar5;
        *(short *)((int)firstPrim + 0x1a) =
            (short)((*(short *)((int)firstPrim + 0x1a) - iVar8) * 0x1200 >> 0xc) + sVar5;
      }
      else
      {
        if (*(char *)((int)firstPrim + 7) == '4')
        {
          uVar2 = *(u_short *)(firstPrim + 2);
          if (*(short *)(firstPrim + 2) < *(short *)(firstPrim + 5))
          {
            iVar6 = (u_int) * (u_short *)(firstPrim + 8) << 0x10;
            if (*(short *)(firstPrim + 2) < *(short *)(firstPrim + 8))
            {
            LAB_8003b7b4:
              iVar6 = (u_int)uVar2 << 0x10;
            }
          }
          else
          {
            iVar6 = (u_int) * (u_short *)(firstPrim + 8) << 0x10;
            uVar2 = *(u_short *)(firstPrim + 5);
            if (*(short *)(firstPrim + 5) < *(short *)(firstPrim + 8))
              goto LAB_8003b7b4;
          }
          uVar7 = iVar6 >> 0x10 & 0xffffffc0;
          cVar3 = (char)uVar7;
          *(char *)(firstPrim + 3) = *(char *)(firstPrim + 2) - cVar3;
          *(undefined *)((int)firstPrim + 0xd) = *(undefined *)((int)firstPrim + 10);
          *(char *)(firstPrim + 6) = *(char *)(firstPrim + 5) - cVar3;
          *(undefined *)((int)firstPrim + 0x19) = *(undefined *)((int)firstPrim + 0x16);
          *(char *)(firstPrim + 9) = *(char *)(firstPrim + 8) - cVar3;
          *(undefined *)((int)firstPrim + 0x25) = *(undefined *)((int)firstPrim + 0x22);
          uVar7 = GetTPage(2, 0, uVar7, uVar10);
          *(undefined2 *)((int)firstPrim + 0x1a) = (short)uVar7;
          *(short *)(firstPrim + 2) =
              (short)((*(short *)(firstPrim + 2) - iVar9) * 0x1200 >> 0xc) + sVar4;
          *(byte *)((int)firstPrim + 7) = *(byte *)((int)firstPrim + 7) | 1;
          *(short *)(firstPrim + 5) =
              (short)((*(short *)(firstPrim + 5) - iVar9) * 0x1200 >> 0xc) + sVar4;
          *(short *)(firstPrim + 8) =
              (short)((*(short *)(firstPrim + 8) - iVar9) * 0x1200 >> 0xc) + sVar4;
          *(short *)((int)firstPrim + 10) =
              (short)((*(short *)((int)firstPrim + 10) - iVar8) * 0x1200 >> 0xc) + sVar5;
          *(short *)((int)firstPrim + 0x16) =
              (short)((*(short *)((int)firstPrim + 0x16) - iVar8) * 0x1200 >> 0xc) + sVar5;
          *(short *)((int)firstPrim + 0x22) =
              (short)((*(short *)((int)firstPrim + 0x22) - iVar8) * 0x1200 >> 0xc) + sVar5;
        }
      }
      firstPrim = firstPrim + (u_int)bVar1 + 1;
    } while (firstPrim < lastPrim);
  }
  return;
}

void PIPE3D_InvertTransform(_StreamUnit *unit, u_long **ot, _CameraCore_Type *cameraCore, _Instance *instance)

{
  int iVar1;
  int iVar2;
  int iVar3;
  _VertexPool *vertexPool;
  _PrimPool *primPool;
  u_char in_zero;
  u_char in_at;
  u_int uVar4;
  int iVar5;
  int iVar6;
  Level *level;
  u_long *firstPrim;
  u_int local_24;

  primPool = gameTrackerX.primPool;
  vertexPool = gameTrackerX.vertexPool;
  level = unit->level;
  local_24 = local_24 & 0xffff0000 | (u_int)(u_short)(instance->position).z;
  iVar6 = (int)instance->object->modelList[instance->currentModel]->maxRad;
  setCopControlWord(2, 0, *(u_char *)cameraCore->vvNormalWorVecMat[0].m);
  setCopControlWord(2, 0x800, *(u_char *)(cameraCore->vvNormalWorVecMat[0].m + 2));
  setCopControlWord(2, 0x1000, *(u_char *)(cameraCore->vvNormalWorVecMat[0].m + 4));
  setCopControlWord(2, 0x1800, *(u_char *)(cameraCore->vvNormalWorVecMat[0].m + 6));
  setCopControlWord(2, 0x2000, *(u_char *)(cameraCore->vvNormalWorVecMat[0].m + 8));
  setCopReg(2, in_zero, *(u_char *)&instance->position);
  setCopReg(2, in_at, local_24);
  copFunction(2, 0x486012);
  iVar5 = getCopReg(2, 0x19);
  iVar1 = getCopReg(2, 0x1a);
  iVar2 = getCopReg(2, 0x1b);
  iVar5 = iVar5 - cameraCore->vvPlaneConsts[0];
  iVar3 = -iVar6;
  if ((((iVar3 < iVar5) && (iVar5 < cameraCore->farPlane + iVar6)) &&
       (iVar3 < iVar1 - cameraCore->vvPlaneConsts[1])) &&
      (iVar3 < iVar2 - cameraCore->vvPlaneConsts[2]))
  {
    setCopControlWord(2, 0, *(u_char *)cameraCore->vvNormalWorVecMat[1].m);
    setCopControlWord(2, 0x800, *(u_char *)(cameraCore->vvNormalWorVecMat[1].m + 2));
    setCopControlWord(2, 0x1000, *(u_char *)(cameraCore->vvNormalWorVecMat[1].m + 4));
    setCopControlWord(2, 0x1800, *(u_char *)(cameraCore->vvNormalWorVecMat[1].m + 6));
    setCopControlWord(2, 0x2000, *(u_char *)(cameraCore->vvNormalWorVecMat[1].m + 8));
    setCopReg(2, in_zero, *(u_char *)&instance->position);
    setCopReg(2, in_at, local_24);
    copFunction(2, 0x486012);
    iVar5 = getCopReg(2, 0x19);
    iVar1 = getCopReg(2, 0x1a);
    getCopReg(2, 0x1b);
    if ((iVar3 < iVar5 - cameraCore->vvPlaneConsts[3]) &&
        (iVar3 < iVar1 - cameraCore->vvPlaneConsts[4]))
    {
      if ((instance->flags & 0x80U) == 0)
      {
        PIPE3D_AnimateTextures(instance->object->modelList[instance->currentModel]->aniTextures,
                               gameTrackerX.frameCount);
        instance->currentTextureAnimFrame = instance->currentTextureAnimFrame + 1;
      }
      else
      {
        PIPE3D_AnimateTextures(instance->object->modelList[instance->currentModel]->aniTextures,
                               (int)instance->currentTextureAnimFrame);
      }
      LIGHT_SetMatrixForLightGroupInstance(instance, level);
      firstPrim = primPool->nextPrim;
      if ((((instance->halvePlane).flags & 0xbU) == 0) || ((instance->flags2 & 0x800000U) != 0))
      {
        PIPE3D_InstanceListTransformAndDrawFunc(instance, cameraCore, vertexPool, primPool, ot, (_Mirror *)0x0);
      }
      else
      {
        PIPE3D_HalvePlaneInstanceTransformAndDraw(instance, cameraCore->wcTransform, vertexPool, primPool, ot, (_Mirror *)0x0);
      }
      uVar4 = instance->flags2;
      if ((int)uVar4 < 0)
      {
        PIPE3D_AddPredatorEffect_Scale((long *)firstPrim, (long *)primPool->nextPrim);
        uVar4 = instance->flags2;
      }
      if ((uVar4 & 0x40) != 0)
      {
        LIGHT_DrawShadow(cameraCore->wcTransform, instance, primPool, ot);
      }
      if (instance->additionalDrawFunc != (void *)0x0)
      {
        (*(code *)instance->additionalDrawFunc)(cameraCore->wcTransform, instance, vertexPool, primPool, ot);
      }
      gameTrackerX.visibleInstances = gameTrackerX.visibleInstances + 1;
      uVar4 = instance->flags | 0x200;
      goto LAB_8003bc58;
    }
  }
  uVar4 = instance->flags & 0xfffffdff;
LAB_8003bc58:
  instance->flags = uVar4;
  return;
}

void PIPE3D_InstanceTransformAndDraw(_StreamUnit *unit, GameTracker *gameTracker, u_long **ot, _CameraCore_Type *cameraCore)

{
  _Instance *instance;
  _Instance *instance_00;
  int iVar1;

  instance_00 = gameTracker->playerInstance;
  iVar1 = unit->StreamUnitID;
  instance = gameTracker->instanceList->first;
  if ((instance_00->currentStreamUnitID == iVar1) && ((instance_00->flags & 0x800U) == 0))
  {
    PIPE3D_InvertTransform(unit, ot, cameraCore, instance_00);
  }
  while (instance != (_Instance *)0x0)
  {
    if (((((instance->flags & 0x800U) == 0) && ((instance->flags2 & 0x4000000U) == 0)) &&
         (instance->currentStreamUnitID == iVar1)) &&
        (instance != instance_00))
    {
      PIPE3D_InvertTransform(unit, ot, cameraCore, instance);
    }
    instance = instance->next;
  }
  return;
}

void PIPE3D_TransformFromZAxis(MATRIX *transform, _SVector *normal)

{
  int iVar1;
  _G2EulerAngles_Type _Stack40;
  _Normal local_20;
  _Normal local_18;

  iVar1 = (int)normal->x;
  if (iVar1 < 0)
  {
    iVar1 = -iVar1;
  }
  if (iVar1 < 5)
  {
    iVar1 = (int)normal->y;
    if (iVar1 < 0)
    {
      iVar1 = -iVar1;
    }
    if (iVar1 < 5)
    {
      if (-1 < normal->z)
      {
        MATH3D_SetUnityMatrix(transform);
        return;
      }
      transform->m[0] = 0x1000;
      transform->m[1] = 0;
      transform->m[2] = 0;
      transform->m[3] = 0;
      transform->m[4] = -0x1000;
      transform->m[5] = 0;
      transform->m[6] = 0;
      transform->m[7] = 0;
      transform->m[8] = -0x1000;
      return;
    }
  }
  local_20.x = -normal->y;
  local_20.y = normal->x;
  local_20.z = 0;
  CAMERA_Initialize(&local_20);
  local_18.x = (short)((int)normal->y * (int)local_20.z - (int)normal->z * (int)local_20.y >> 0xc);
  local_18.y = -(short)((int)normal->x * (int)local_20.z - (int)normal->z * (int)local_20.x >> 0xc);
  local_18.z = (short)((int)normal->x * (int)local_20.y - (int)normal->y * (int)local_20.x >> 0xc);
  CAMERA_Initialize(&local_18);
  transform->m[0] = local_20.x;
  transform->m[1] = local_20.y;
  transform->m[2] = local_20.z;
  transform->m[3] = local_18.x;
  transform->m[4] = local_18.y;
  transform->m[5] = local_18.z;
  transform->m[6] = normal->x;
  transform->m[7] = normal->y;
  transform->m[8] = normal->z;
  G2EulerAngles_FromMatrix(&_Stack40, (_G2Matrix_Type *)transform, 0x15);
  RotMatrixY((u_short *)&_Stack40, (u_int *)transform);
  return;
}

void PIPE3D_CalcWorldToSplitPlaneTransform(MATRIX *wpTransform, _SVector *normal, _SVector *translation)

{
  long lVar1;
  long lVar2;
  long lVar3;
  u_char in_zero;
  u_char in_at;
  u_char local_28;
  u_int local_24;

  PIPE3D_TransformFromZAxis(wpTransform, normal);
  local_28 = CONCAT22(-translation->y, -translation->x);
  local_24 = local_24 & 0xffff0000 | (u_int)(u_short)-translation->z;
  setCopControlWord(2, 0, *(u_char *)wpTransform->m);
  setCopControlWord(2, 0x800, *(u_char *)(wpTransform->m + 2));
  setCopControlWord(2, 0x1000, *(u_char *)(wpTransform->m + 4));
  setCopControlWord(2, 0x1800, *(u_char *)(wpTransform->m + 6));
  setCopControlWord(2, 0x2000, *(u_char *)(wpTransform->m + 8));
  setCopReg(2, in_zero, local_28);
  setCopReg(2, in_at, local_24);
  copFunction(2, 0x486012);
  lVar1 = getCopReg(2, 0x19);
  lVar2 = getCopReg(2, 0x1a);
  lVar3 = getCopReg(2, 0x1b);
  wpTransform->t[0] = lVar1;
  wpTransform->t[1] = lVar2;
  wpTransform->t[2] = lVar3;
  return;
}

long PIPE3D_TransformSplitInstanceVertices(_MVertex *vertexList, _PVertex *poolVertex, _Model *model, MATRIX *wcTransform,
                                           MATRIX *matrixPool, _Mirror *mirror, MATRIX *lm, CVECTOR *vertexColor,
                                           CVECTOR *vertexSrcCol)

{
  u_short uVar1;
  u_char uVar2;
  CVECTOR CVar3;
  u_char in_zero;
  u_char in_at;
  u_int uVar4;
  u_int uVar5;
  u_int uVar6;
  long *plVar7;
  CVECTOR *pCVar8;
  _MVertex *p_Var9;
  CVECTOR *pCVar10;
  MATRIX *pMVar11;
  CVECTOR *pCVar12;
  CVECTOR *pCVar13;
  _MVertex *p_Var14;
  CVECTOR local_48[2];
  int local_40;
  _Segment *local_3c;
  _MVertex *local_38;
  u_int local_34;
  u_char *local_30;

  local_3c = model->segmentList;
  if (vertexColor != (CVECTOR *)0x0)
  {
    setCopReg(2, model, 0x34ffffff);
  }
  if (modelFadeValue == 0)
  {
    setCopReg(2, 0x4000, 0);
  }
  else
  {
    setCopReg(2, 0x4000, modelFadeValue);
  }
  local_40 = 0;
  if (0 < model->numSegments)
  {
    local_30 = &DAT_1f800060;
    do
    {
      if ((int)local_3c->lastVertex != -1)
      {
        pCVar10 = local_48;
        local_34 = 0;
        p_Var14 = vertexList + (int)local_3c->lastVertex;
        local_48[0] = (CVECTOR)0x34ffffff;
        local_38 = vertexList + local_3c->firstVertex;
        pMVar11 = matrixPool + local_40;
        if (vertexColor != (CVECTOR *)0x0)
        {
          PopMatrix((u_char *)lm, (u_short *)pMVar11, &DAT_1f800040);
          SetLightMatrix(&DAT_1f800040);
        }
        CompMatrix((u_char *)wcTransform, (u_short *)pMVar11, (u_int *)&DAT_1f800000);
        SetRotMatrix((u_char *)&DAT_1f800000);
        TransMatrix(0x1f800000);
        if (local_38 <= p_Var14 + -2)
        {
          p_Var9 = local_38 + 2;
          pCVar8 = vertexColor + 2;
          plVar7 = &poolVertex->otz;
          pCVar12 = pCVar10;
          pCVar13 = pCVar10;
          do
          {
            setCopReg(2, in_zero, *(u_char *)&local_38->vertex);
            setCopReg(2, in_at, *(u_char *)&(local_38->vertex).z);
            copFunction(2, 0x480012);
            uVar4 = (u_int)p_Var9[-2].normal;
            uVar6 = (u_int)p_Var9[-1].normal;
            uVar5 = (u_int)p_Var9->normal;
            uVar2 = getCopReg(2, 0x19);
            *local_30 = uVar2;
            uVar2 = getCopReg(2, 0x1a);
            local_30[1] = uVar2;
            uVar2 = getCopReg(2, 0x1b);
            local_30[2] = uVar2;
            poolVertex->x = (short)DAT_1f800060;
            *(undefined2 *)((int)plVar7 + -2) = DAT_1f800064;
            *(undefined2 *)plVar7 = DAT_1f800068;
            setCopReg(2, in_zero, *(u_char *)&local_38[1].vertex);
            setCopReg(2, in_at, *(u_char *)&local_38[1].vertex.z);
            copFunction(2, 0x480012);
            uVar2 = getCopReg(2, 0x19);
            *local_30 = uVar2;
            uVar2 = getCopReg(2, 0x1a);
            local_30[1] = uVar2;
            uVar2 = getCopReg(2, 0x1b);
            local_30[2] = uVar2;
            poolVertex[1].x = (short)DAT_1f800060;
            *(undefined2 *)((int)plVar7 + 6) = DAT_1f800064;
            *(undefined2 *)(plVar7 + 2) = DAT_1f800068;
            setCopReg(2, in_zero, *(u_char *)&p_Var9->vertex);
            setCopReg(2, in_at, *(u_char *)&(p_Var9->vertex).z);
            copFunction(2, 0x480012);
            uVar2 = getCopReg(2, 0x19);
            *local_30 = uVar2;
            uVar2 = getCopReg(2, 0x1a);
            local_30[1] = uVar2;
            uVar2 = getCopReg(2, 0x1b);
            local_30[2] = uVar2;
            poolVertex[2].x = (short)DAT_1f800060;
            *(undefined2 *)((int)plVar7 + 0xe) = DAT_1f800064;
            poolVertex = poolVertex + 3;
            *(undefined2 *)(plVar7 + 4) = DAT_1f800068;
            plVar7 = plVar7 + 6;
            if (vertexColor != (CVECTOR *)0x0)
            {
              if (vertexSrcCol != (CVECTOR *)0x0)
              {
                pCVar13 = vertexSrcCol + 1;
                pCVar12 = vertexSrcCol + 2;
                local_34 = (u_int)*vertexSrcCol & (u_int)vertexSrcCol[1] & (u_int)vertexSrcCol[2];
                pCVar10 = vertexSrcCol;
                vertexSrcCol = vertexSrcCol + 3;
              }
              if ((local_34 & 0x40000000) == 0)
              {
                if (modelFadeValue == 0)
                {
                  setCopReg(2, in_zero, *(u_char *)(&gNormalList + uVar4));
                  setCopReg(2, in_at, *(u_char *)&(&gNormalList)[uVar4].z);
                  setCopReg(2, local_38, *pCVar10);
                  copFunction(2, 0x108041b);
                  setCopReg(2, in_zero, *(u_char *)(&gNormalList + uVar6));
                  setCopReg(2, in_at, *(u_char *)&(&gNormalList)[uVar6].z);
                  setCopReg(2, local_38, *pCVar13);
                  copFunction(2, 0x108041b);
                  setCopReg(2, in_zero, *(u_char *)(&gNormalList + uVar5));
                  setCopReg(2, in_at, *(u_char *)&(&gNormalList)[uVar5].z);
                  setCopReg(2, local_38, *pCVar12);
                  copFunction(2, 0x108041b);
                }
                else
                {
                  setCopReg(2, in_zero, *(u_char *)(&gNormalList + uVar4));
                  setCopReg(2, in_at, *(u_char *)&(&gNormalList)[uVar4].z);
                  setCopReg(2, local_38, *pCVar10);
                  copFunction(2, 0xe80413);
                  setCopReg(2, in_zero, *(u_char *)(&gNormalList + uVar6));
                  setCopReg(2, in_at, *(u_char *)&(&gNormalList)[uVar6].z);
                  setCopReg(2, local_38, *pCVar13);
                  copFunction(2, 0xe80413);
                  setCopReg(2, in_zero, *(u_char *)(&gNormalList + uVar5));
                  setCopReg(2, in_at, *(u_char *)&(&gNormalList)[uVar5].z);
                  setCopReg(2, local_38, *pCVar12);
                  copFunction(2, 0xe80413);
                }
                CVar3 = (CVECTOR)getCopReg(2, 0x14);
                *vertexColor = CVar3;
                CVar3 = (CVECTOR)getCopReg(2, 0x15);
                vertexColor[1] = CVar3;
                CVar3 = (CVECTOR)getCopReg(2, 0x16);
                *pCVar8 = CVar3;
                if (((u_int)*pCVar10 & 0x40000000) != 0)
                {
                  *vertexColor = *pCVar10;
                }
                if (((u_int)*pCVar13 & 0x40000000) != 0)
                {
                  pCVar8[-1] = *pCVar13;
                }
                if (((u_int)*pCVar12 & 0x40000000) != 0)
                {
                  *pCVar8 = *pCVar12;
                }
              }
              else
              {
                *vertexColor = *pCVar10;
                pCVar8[-1] = *pCVar13;
                *pCVar8 = *pCVar12;
              }
              pCVar8 = pCVar8 + 3;
              vertexColor = vertexColor + 3;
            }
            local_38 = local_38 + 3;
            p_Var9 = p_Var9 + 3;
          } while (local_38 <= p_Var14 + -2);
        }
        if (local_38 <= p_Var14)
        {
          plVar7 = &poolVertex->otz;
          do
          {
            setCopReg(2, in_zero, *(u_char *)&local_38->vertex);
            setCopReg(2, in_at, *(u_char *)&(local_38->vertex).z);
            copFunction(2, 0x480012);
            uVar1 = local_38->normal;
            uVar2 = getCopReg(2, 0x19);
            *local_30 = uVar2;
            uVar2 = getCopReg(2, 0x1a);
            local_30[1] = uVar2;
            uVar2 = getCopReg(2, 0x1b);
            local_30[2] = uVar2;
            poolVertex->x = (short)DAT_1f800060;
            *(undefined2 *)((int)plVar7 + -2) = DAT_1f800064;
            poolVertex = poolVertex + 1;
            *(undefined2 *)plVar7 = DAT_1f800068;
            plVar7 = plVar7 + 2;
            if (vertexColor != (CVECTOR *)0x0)
            {
              if (vertexSrcCol != (CVECTOR *)0x0)
              {
                pCVar10 = vertexSrcCol;
                vertexSrcCol = vertexSrcCol + 1;
              }
              if (((u_int)*pCVar10 & 0x40000000) == 0)
              {
                setCopReg(2, local_38, *pCVar10);
                setCopReg(2, in_zero, *(u_char *)(&gNormalList + uVar1));
                setCopReg(2, in_at, *(u_char *)&(&gNormalList)[uVar1].z);
                copFunction(2, 0xe80413);
                CVar3 = (CVECTOR)getCopReg(2, 0x16);
                *vertexColor = CVar3;
              }
              else
              {
                *vertexColor = *pCVar10;
              }
              vertexColor = vertexColor + 1;
            }
            local_38 = local_38 + 1;
          } while (local_38 <= p_Var14);
        }
      }
      local_3c = local_3c + 1;
      local_40 = local_40 + 1;
    } while (local_40 < model->numSegments);
  }
  modelDQP = getCopReg(2, 8);
  return 0;
}

void PIPE3D_TransformVerticesToWorld(_MVertex *vertexList, _PVertex *pvertex, _Model *model, MATRIX *wpTransform,
                                     MATRIX *matrixPool, _Mirror *mirror)

{
  short sVar1;
  u_char in_zero;
  u_char in_at;
  long *plVar2;
  _MVertex *p_Var3;
  short *psVar4;
  int iVar5;
  int iVar6;

  iVar5 = 0;
  if (0 < model->numSegments)
  {
    iVar6 = 0;
    psVar4 = &model->segmentList->lastVertex;
    do
    {
      if (*(short *)((int)&model->segmentList->lastVertex + iVar6) != -1)
      {
        sVar1 = *psVar4;
        p_Var3 = vertexList + psVar4[-1];
        CompMatrix((u_char *)wpTransform, (u_short *)matrixPool, (u_int *)&DAT_1f800000);
        SetRotMatrix((u_char *)&DAT_1f800000);
        TransMatrix(0x1f800000);
        if (p_Var3 <= vertexList + sVar1)
        {
          plVar2 = &pvertex->otz;
          do
          {
            setCopReg(2, in_zero, *(u_char *)&p_Var3->vertex);
            setCopReg(2, in_at, *(u_char *)&(p_Var3->vertex).z);
            copFunction(2, 0x480012);
            DAT_1f800020 = getCopReg(2, 0x19);
            DAT_1f800024 = getCopReg(2, 0x1a);
            DAT_1f800028 = getCopReg(2, 0x1b);
            pvertex->x = (short)DAT_1f800020;
            p_Var3 = p_Var3 + 1;
            *(undefined2 *)((int)plVar2 + -2) = (undefined2)DAT_1f800024;
            pvertex = pvertex + 1;
            *(undefined2 *)plVar2 = (undefined2)DAT_1f800028;
            plVar2 = plVar2 + 2;
          } while (p_Var3 <= vertexList + sVar1);
        }
      }
      psVar4 = psVar4 + 0xc;
      matrixPool = matrixPool + 1;
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 0x18;
    } while (iVar5 < model->numSegments);
  }
  return;
}

void PIPE3D_AnimateTextures(AniTex *aniTextures, long req_frame)

{
  TextureMT3 *pTVar1;
  TextureMT3 *pTVar2;
  u_int *puVar3;
  int iVar4;
  AniTexInfo *pAVar5;

  if (((aniTextures != (AniTex *)0x0) && (pAVar5 = &aniTextures->aniTexInfo, req_frame != -1)) &&
      (iVar4 = 0, 0 < aniTextures->numAniTextues))
  {
    puVar3 = (u_int *)&(aniTextures->aniTexInfo).numFrames;
    do
    {
      pTVar2 = pAVar5->texture;
 puVar3[1]) % *puVar3;
 *(u_char *)pTVar2 = *(u_char *)(pTVar1 + 1);
 *(u_char *)&pTVar2->u1 = *(u_char *)&pTVar1[1].u1;
 pAVar5 = pAVar5 + 1;
 *(u_char *)&pTVar2->u2 = *(u_char *)&pTVar1[1].u2;
 iVar4 = iVar4 + 1;
 pTVar2->color = pTVar1[1].color;
 puVar3 = puVar3 + 3;
    } while (iVar4 < aniTextures->numAniTextues);
  }
  return;
}

void PIPE3D_AnimateTerrainTextures(DrMoveAniTex *aniTextures, long req_frame, _PrimPool *primPool, u_long **drawot)

{
  u_int *puVar1;
  DrMoveAniTexDestInfo *pDVar2;
  DrMoveAniTexSrcInfo *pDVar3;
  u_int *puVar4;
  int iVar5;
  DrMoveAniTex *pDVar6;

  puVar4 = primPool->nextPrim;
  drawot = drawot + 0xbff;
  if (aniTextures != (DrMoveAniTex *)0x0)
  {
    if ((puVar4 < primPool->lastPrim + aniTextures->numAniTextues * 0x3fffffe8) &&
        (iVar5 = 0, 0 < aniTextures->numAniTextues))
    {
      puVar1 = puVar4 + 5;
      pDVar6 = aniTextures;
      do
      {
        pDVar2 = pDVar6->aniTexInfo;
 (u_int)pDVar2->speed) % pDVar2->numFrames;
 if (*(u_int *)pDVar3 != *(u_int *)&pDVar2->pixCurrentX)
 {
   puVar1[-4] = 0x1000000;
   puVar1[-3] = 0x80000000;
   puVar1[-2] = *(u_int *)pDVar3;
   puVar1[-1] = *(u_int *)pDVar2;
   *puVar1 = *(u_int *)&pDVar2->pixW;
   *puVar4 = (u_int)*drawot & 0xffffff | 0x5000000;
   *drawot = (u_long *)((u_int)puVar4 & 0xffffff);
   puVar1 = puVar1 + 6;
   *(u_int *)&pDVar2->pixCurrentX = *(u_int *)pDVar3;
   puVar4 = puVar4 + 6;
   primPool->numPrims = primPool->numPrims + 1;
 }
 if (*(int *)&pDVar3->clutSrcX != *(int *)&pDVar2->clutCurrentX)
 {
   puVar1[-4] = 0x1000000;
   puVar1[-3] = 0x80000000;
   puVar1[-2] = *(u_int *)&pDVar3->clutSrcX;
   puVar1[-1] = *(u_int *)&pDVar2->clutDstX;
   *puVar1 = *(u_int *)&pDVar2->clutW;
   *puVar4 = (u_int)*drawot & 0xffffff | 0x5000000;
   *drawot = (u_long *)((u_int)puVar4 & 0xffffff);
   puVar1 = puVar1 + 6;
   *(u_char *)&pDVar2->clutCurrentX = *(u_char *)&pDVar3->clutSrcX;
   puVar4 = puVar4 + 6;
   primPool->numPrims = primPool->numPrims + 1;
 }
 iVar5 = iVar5 + 1;
 pDVar6 = (DrMoveAniTex *)&pDVar6->aniTexInfo;
      } while (iVar5 < aniTextures->numAniTextues);
    }
    primPool->nextPrim = puVar4;
  }
  return;
}

void PIPE3D_HalvePlaneInstanceTransformAndDraw(_Instance *instance, MATRIX *wcTransform, _VertexPool *vertexPool, _PrimPool *primPool,
                                               u_long **ot, _Mirror *mirror)

{
  u_long *puVar1;
  _Model *model;
  MATRIX *matrixPool;
  _MVertex *vertexList;
  MATRIX MStack184;
  MATRIX MStack152;
  u_int auStack120[8];
  MATRIX MStack88;
  _SVector local_38;
  _SVector local_30;

  matrixPool = instance->matrix;
  model = instance->object->modelList[instance->currentModel];
  local_38.x = (instance->halvePlane).a;
  vertexList = model->vertexList;
  local_38.y = (instance->halvePlane).b;
  local_38.z = (instance->halvePlane).c;
  local_30.x = -(short)((int)local_38.x * (instance->halvePlane).d >> 0xc);
  local_30.y = -(short)((int)local_38.y * (instance->halvePlane).d >> 0xc);
  local_30.z = -(short)((int)local_38.z * (instance->halvePlane).d >> 0xc);
  PIPE3D_CalcWorldToSplitPlaneTransform(&MStack184, &local_38, &local_30);
  PIPE3D_InstanceListTransformAndDraw(&MStack152, &MStack184);
  CompMatrix((u_char *)wcTransform, (u_short *)&MStack152, auStack120);
  if (matrixPool != (MATRIX *)0x0)
  {
    LIGHT_PresetInstanceLight(instance, 0x800, &MStack88);
    modelFadeValue = INSTANCE_GetFadeValue(instance);
    PIPE3D_TransformSplitInstanceVertices(vertexList, (_PVertex *)vertexPool, model, &MStack184, matrixPool, mirror, &MStack88,
                                          vertexPool->color, instance->perVertexColor);
    if (primPool->nextPrim + model->numFaces * 0xc < primPool->lastPrim)
    {
      draw_belowSplit = ZEXT14(((instance->halvePlane).flags & 2U) != 0);
      puVar1 = (u_long *)DRAW_SplitModel_S((int)model, instance, (int)vertexPool, auStack120,
                                           (int)primPool);
      primPool->nextPrim = puVar1;
    }
  }
  return;
}

void PIPE3D_HalvePlaneGetRingPoints(_Instance *instance, MATRIX *wcTransform, _VertexPool *vertexPool, _PrimPool *primPool,
                                    u_long **ot, _FXHalvePlane *ring)

{
  u_long *puVar1;
  _PlaneConstants *p_Var2;
  _Model *model;
  MATRIX *matrixPool;
  _MVertex *vertexList;
  MATRIX MStack152;
  MATRIX MStack120;
  MATRIX MStack88;
  _SVector local_38;
  _SVector local_30;

  matrixPool = instance->matrix;
  model = instance->object->modelList[instance->currentModel];
  vertexList = model->vertexList;
  if (ring->type == '\0')
  {
    p_Var2 = &ring->ringPlane;
  }
  else
  {
    p_Var2 = &instance->halvePlane;
  }
  local_38.x = p_Var2->a;
  local_38.y = p_Var2->b;
  local_38.z = p_Var2->c;
  local_30.x = -(short)((int)local_38.x * p_Var2->d >> 0xc);
  local_30.y = -(short)((int)local_38.y * p_Var2->d >> 0xc);
  local_30.z = -(short)((int)local_38.z * p_Var2->d >> 0xc);
  PIPE3D_CalcWorldToSplitPlaneTransform(&MStack152, &local_38, &local_30);
  PIPE3D_InstanceListTransformAndDraw(&MStack120, &MStack152);
  if (ring->type == '\x02')
  {
    PIPE3D_InstanceListTransformAndDraw(&MStack88, &MStack152);
  }
  else
  {
    CompMatrix((u_char *)wcTransform, (u_short *)&MStack120, (u_int *)&MStack88);
  }
  if (matrixPool != (MATRIX *)0x0)
  {
    PIPE3D_TransformVerticesToWorld(vertexList, (_PVertex *)vertexPool, model, &MStack152, matrixPool, (_Mirror *)0x0);
    draw_belowSplit = 0;
    puVar1 = DRAW_DrawRingPoints(model, vertexPool, &MStack88, primPool, ot, ring->currentColor,
                                 (u_int)ring->type);
    primPool->nextPrim = puVar1;
  }
  return;
}

void PIPE3D_DoGlow(_Instance *instance, MATRIX *wcTransform, _VertexPool *vertexPool,
                   _PrimPool *primPool, u_long **ot, _FXGlowEffect *glow)

{
  bool bVar1;
  long *plVar2;
  int iVar3;
  u_long *puVar4;
  u_int uVar5;
  u_int uVar6;
  u_int uVar7;
  u_char uVar8;
  u_char uVar9;
  u_char uVar10;
  int seg1;
  u_int uVar11;
  u_int local_20;

  uVar7 = 0;
  if ((instance->flags & 0x200U) != 0)
  {
    uVar6 = SEXT24(glow->numColors);
    uVar5 = (glow->diffTime + gameTrackerX.lastLoopTime) % 32000;
    glow->diffTime = uVar5;
    if (1 < (int)uVar6)
    {
      uVar5 = uVar5 % ((int)glow->colorBlendCycle * uVar6);
 (u_int)(int)glow->colorBlendCycle) % uVar6;
 glow->diffTime = uVar5;
 uVar5 = uVar11;
 if (uVar11 == 0)
 {
   uVar5 = uVar6;
 }

 (u_int)(int) glow->colorBlendCycle;
 if (0xfff < (int)uVar6)
 {
   uVar6 = 0;
 }
 setCopReg(2, 0x4000, 0x1000 - uVar6);
 plVar2 = glow->colorArray + (uVar5 - 1);
 setCopReg(2, 0x4800, (u_int) * (byte *)plVar2);
 setCopReg(2, 0x5000, (u_int) * (byte *)((int)plVar2 + 1));
 setCopReg(2, 0x5800, (u_int) * (byte *)((int)plVar2 + 2));
 copFunction(2, 0x198003d);
 setCopReg(2, 0x4000, uVar6);
 plVar2 = glow->colorArray + uVar11;
 setCopReg(2, 0x4800, (u_int) * (byte *)plVar2);
 setCopReg(2, 0x5000, (u_int) * (byte *)((int)plVar2 + 1));
 setCopReg(2, 0x5800, (u_int) * (byte *)((int)plVar2 + 2));
 copFunction(2, 0x1a8003e);
 uVar8 = getCopReg(2, 0x4800);
 uVar9 = getCopReg(2, 0x5000);
 uVar10 = getCopReg(2, 0x5800);
 *(char *)&glow->currentColor = (char)uVar8;
 *(undefined *)((int)&glow->currentColor + 1) = (char)uVar9;
 *(undefined *)((int)&glow->currentColor + 2) = (char)uVar10;
 uVar6 = glow->currentColor & 0xffffff;
 glow->currentColor = uVar6;
 glow->currentColor = uVar6 | glow->colorArray[uVar5 - 1] & 0xff000000U;
    }
    if ((instance->matrix != (MATRIX *)0x0) && (instance->oldMatrix != (MATRIX *)0x0))
    {
      bVar1 = false;
      if (((int)instance->fadeValue == 0) && (gameTrackerX.gameData.asmData.MorphTime == 1000))
      {
        iVar3 = (int)glow->lifeTime;
        if (-1 < iVar3)
        {
          if (glow->diffTime < (u_int)(int)glow->fadein_time)
          {
            (u_int)(int) glow->fadein_time;
            bVar1 = true;
          }
          else
          {
            if (iVar3 < (int)glow->fadeout_time)
            {
              bVar1 = true;
              (int)glow->fadeout_time;
            }
          }
        }
      }
      else
      {
        bVar1 = true;
        if (gameTrackerX.gameData.asmData.MorphTime == 1000)
        {
          uVar7 = 0x1000 - (int)instance->fadeValue;
        }
        else
        {
          iVar3 = INSTANCE_GetFadeValue(instance);
          uVar7 = 0x1000 - iVar3;
        }
      }
      if (bVar1)
      {
        setCopReg(2, 0x4000, uVar7);
        setCopReg(2, 0x4800, (u_int) * (byte *)&glow->currentColor);
        setCopReg(2, 0x5000, (u_int) * (byte *)((int)&glow->currentColor + 1));
        setCopReg(2, 0x5800, (u_int) * (byte *)((int)&glow->currentColor + 2));
        copFunction(2, 0x198003d);
        uVar8 = getCopReg(2, 0x4800);
        uVar9 = getCopReg(2, 0x5000);
        uVar10 = getCopReg(2, 0x5800);
        local_20 = (u_int)CONCAT12((char)uVar10, CONCAT11((char)uVar9, (char)uVar8));
        if ((glow->currentColor & 0x1000000U) != 0)
        {
          local_20 = local_20 | 0x1000000;
        }
      }
      else
      {
        local_20 = glow->currentColor;
      }
      if (glow->numSegments == '\x01')
      {
        puVar4 = DRAW_DrawGlowPoints2(instance, (int)glow->segment, primPool, ot, local_20, (int)glow->width,
                                      (int)glow->height);
        primPool->nextPrim = puVar4;
      }
      else
      {
        seg1 = (int)glow->segment;
        iVar3 = seg1 + (u_int)glow->numSegments;
        while (seg1 < iVar3 + -1)
        {
          puVar4 = DRAW_DrawGlowPoint(instance, seg1, seg1 + (u_int)glow->SegmentInc, primPool, ot,
                                      local_20, (int)glow->height);
          primPool->nextPrim = puVar4;
          seg1 = seg1 + 1;
          iVar3 = (int)glow->segment + (u_int)glow->numSegments;
        }
      }
    }
  }
  return;
}

long PIPE3D_Segment2ScreenPt(_Instance *instance, MATRIX *wcTransform, int segIndex, _Position *pos)

{
  u_char uVar1;
  int iVar2;
  u_char in_zero;
  u_char in_at;
  u_int auStack56[9];
  u_char local_14;

  CompMatrix((u_char *)wcTransform, (u_short *)(instance->matrix + segIndex), auStack56);
  SetRotMatrix(auStack56);
  TransMatrix((int)auStack56);
  local_14 = (u_int)local_14._2_2_ << 0x10;
  setCopReg(2, in_zero, 0);
  setCopReg(2, in_at, local_14);
  copFunction(2, 0x180001);
  uVar1 = getCopReg(2, 0xe);
  *(u_char *)pos = uVar1;
  iVar2 = getCopReg(2, 0x13);
  return (iVar2 >> 2) + -0x14;
}
