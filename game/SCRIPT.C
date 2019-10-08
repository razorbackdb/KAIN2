#include "THISDUST.H"
#include "SCRIPT.H"

void SCRIPT_CombineEulerAngles(_Rotation *combinedRotation, _Rotation *inputRotation1, _Rotation *inputRotation2)

{
  _G2Matrix_Type _Stack88;
  u_int auStack56[8];
  _G2EulerAngles_Type local_18;

  RotMatrixY((u_short *)inputRotation1, (u_int *)&_Stack88);
  RotMatrixY((u_short *)inputRotation2, auStack56);
  MulMatrix2(auStack56, (u_int *)&_Stack88);
  G2EulerAngles_FromMatrix(&local_18, &_Stack88, 0x15);
  combinedRotation->x = local_18.x;
  combinedRotation->y = local_18.y;
  combinedRotation->z = local_18.z;
  return;
}

void SCRIPT_InstanceSplineInit(_Instance *instance)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  MultiSpline *multi;
  SplineDef *def;
  SplineDef *def_00;
  SplineDef *def_01;
  _G2Quat_Type *quat;
  _SVector *p_Var5;
  Intro *pIVar6;
  MATRIX *pMVar7;
  Spline *spline;
  Spline *spline_00;
  _G2EulerAngles_Type local_50;
  _Rotation local_48[4];
  u_long local_28;
  u_long local_24;

  multi = SCRIPT_GetMultiSpline(instance, &local_28, &local_24);
  if (multi != (MultiSpline *)0x0)
  {
    def = SCRIPT_GetPosSplineDef(instance, multi, local_28, local_24);
    def_00 = SCRIPT_GetRotSplineDef(instance, multi, local_28, local_24);
    def_01 = SCRIPT_GetScaleSplineDef(instance, multi, local_28, local_24);
    spline = multi->positional;
    spline_00 = multi->scaling;
    if (multi->rotational != (RSpline *)0x0)
    {
      quat = SplineGetFirstRot(multi->rotational, def_00);
      if ((local_28 == 0) && (local_24 == 0))
      {
        pMVar7 = &multi->curRotMatrix;
        G2Quat_ToMatrix_S((short *)quat, (short *)pMVar7);
        if (instance->intro != (Intro *)0x0)
        {
          RotMatrixY((u_short *)&instance->intro->rotation, (u_int *)local_48);
          PopMatrix((u_char *)pMVar7, (u_short *)local_48, (u_int *)pMVar7);
        }
        instance->flags = instance->flags | 1;
      }
      else
      {
        G2Quat_FromEuler_S(quat, &local_50, 0);
        pIVar6 = instance->intro;
        (instance->rotation).x = local_50.x;
        (instance->rotation).y = local_50.y;
        (instance->rotation).z = local_50.z;
        SCRIPT_CombineEulerAngles(local_48, &instance->rotation, &pIVar6->rotation);
        (instance->rotation).x = local_48[0].x;
        (instance->rotation).y = local_48[0].y;
        (instance->rotation).z = local_48[0].z;
      }
    }
    if ((spline != (Spline *)0x0) &&
        (p_Var5 = SplineGetFirstPoint(spline, def), p_Var5 != (_SVector *)0x0))
    {
      if (local_24 == 0)
      {
        (instance->position).x = p_Var5->x;
        (instance->position).y = p_Var5->y;
        (instance->position).z = p_Var5->z;
      }
      else
      {
        sVar1 = (instance->initialPos).y;
        sVar2 = (instance->initialPos).z;
        sVar3 = p_Var5->y;
        sVar4 = p_Var5->z;
        (instance->position).x = (instance->initialPos).x + p_Var5->x;
        (instance->position).y = sVar1 + sVar3;
        (instance->position).z = sVar2 + sVar4;
      }
    }
    if ((spline_00 != (Spline *)0x0) &&
        (p_Var5 = SplineGetFirstPoint(spline_00, def_01), p_Var5 != (_SVector *)0x0))
    {
      (instance->scale).x = p_Var5->x;
      (instance->scale).y = p_Var5->y;
      (instance->scale).z = p_Var5->z;
    }
  }
  return;
}

short SCRIPTCountFramesInSpline(_Instance *instance)

{
  u_short *puVar1;
  Spline *pSVar2;
  short sVar5;
  RSpline *pRVar3;
  MultiSpline *pMVar4;
  int iVar6;
  SplineKey *pSVar7;
  SplineRotKey *pSVar8;
  int iVar9;
  int iVar10;

  iVar10 = 0;
  iVar9 = 0;
  sVar5 = 0;
  pSVar2 = ScriptGetPosSpline(instance);
  if (pSVar2 == (Spline *)0x0)
  {
    pRVar3 = ScriptGetRotSpline(instance);
    if (pRVar3 == (RSpline *)0x0)
    {
      pMVar4 = SCRIPT_GetMultiSpline(instance, (u_long *)0x0, (u_long *)0x0);
      if (pMVar4 != (MultiSpline *)0x0)
      {
        iVar6 = (int)pMVar4->scaling->numkeys;
        pSVar7 = pMVar4->scaling->key;
        sVar5 = 0;
        if (0 < iVar6)
        {
          do
          {
            iVar10 = iVar10 + 1;
            puVar1 = (u_short *)&pSVar7->count;
            pSVar7 = pSVar7 + 1;
            iVar9 = iVar9 + (u_int)*puVar1;
            sVar5 = (short)iVar9;
          } while (iVar10 * 0x10000 >> 0x10 < iVar6);
        }
      }
    }
    else
    {
      pSVar8 = pRVar3->key;
      sVar5 = 0;
      if (0 < (int)pRVar3->numkeys)
      {
        do
        {
          iVar10 = iVar10 + 1;
          puVar1 = (u_short *)&pSVar8->count;
          pSVar8 = pSVar8 + 1;
          iVar9 = iVar9 + (u_int)*puVar1;
        } while (iVar10 * 0x10000 >> 0x10 < (int)pRVar3->numkeys);
        sVar5 = (short)((u_int)(iVar9 * 0x10000) >> 0x10);
      }
    }
  }
  else
  {
    pSVar7 = pSVar2->key;
    if (0 < (int)pSVar2->numkeys)
    {
      do
      {
        iVar10 = iVar10 + 1;
        puVar1 = (u_short *)&pSVar7->count;
        pSVar7 = pSVar7 + 1;
        iVar9 = iVar9 + (u_int)*puVar1;
      } while (iVar10 * 0x10000 >> 0x10 < (int)pSVar2->numkeys);
      sVar5 = (short)((u_int)(iVar9 * 0x10000) >> 0x10);
    }
  }
  return sVar5;
}

Spline *ScriptGetPosSpline(_Instance *instance)

{
  MultiSpline *pMVar1;
  Spline *pSVar2;

  pMVar1 = SCRIPT_GetMultiSpline(instance, (u_long *)0x0, (u_long *)0x0);
  if (pMVar1 == (MultiSpline *)0x0)
  {
    pSVar2 = (Spline *)0x0;
  }
  else
  {
    pSVar2 = pMVar1->positional;
  }
  return pSVar2;
}

RSpline *ScriptGetRotSpline(_Instance *instance)

{
  MultiSpline *pMVar1;
  RSpline *pRVar2;

  pMVar1 = SCRIPT_GetMultiSpline(instance, (u_long *)0x0, (u_long *)0x0);
  if (pMVar1 == (MultiSpline *)0x0)
  {
    pRVar2 = (RSpline *)0x0;
  }
  else
  {
    pRVar2 = pMVar1->rotational;
  }
  return pRVar2;
}

int EVENT_GetSplineFrameNumber(_Instance *instance, SplineDef *splineDef)

{
  u_short uVar1;
  Spline *spline;

  spline = ScriptGetPosSpline(instance);
  if (spline == (Spline *)0x0)
  {
    spline = (Spline *)ScriptGetRotSpline(instance);
  }
  else
  {
    spline = ScriptGetPosSpline(instance);
  }
  uVar1 = SCRIPT_GetSplineFrameNumber(spline, splineDef);
  return (u_int)uVar1;
}

MultiSpline *SCRIPT_GetMultiSpline(_Instance *instance, u_long *isParent, u_long *isClass)

{
  MultiSpline *pMVar1;
  _Model *p_Var2;
  MultiSpline *pMVar3;

  pMVar3 = (MultiSpline *)0x0;
  if (isParent != (u_long *)0x0)
  {
    *isParent = 0;
  }
  if (isClass != (u_long *)0x0)
  {
    *isClass = 0;
  }
  if ((((instance != (_Instance *)0x0) && (instance->intro != (Intro *)0x0)) &&
       (pMVar1 = instance->intro->multiSpline, pMVar1 != (MultiSpline *)0x0)) &&
      ((pMVar3 = pMVar1, (instance->flags & 0x100002U) == 2 && (isParent != (u_long *)0x0))))
  {
    *isParent = 1;
  }
  if (((pMVar3 == (MultiSpline *)0x0) &&
       (p_Var2 = *instance->object->modelList, p_Var2 != (_Model *)0x0)) &&
      (pMVar3 = p_Var2->multiSpline, isClass != (u_long *)0x0))
  {
    *isClass = 1;
  }
  return pMVar3;
}

SplineDef *
SCRIPT_GetPosSplineDef(_Instance *instance, MultiSpline *multi, u_long isParent, u_long isClass)

{
  SplineDef *pSVar1;

  if ((isParent == 0) && (isClass == 0))
  {
    pSVar1 = (SplineDef *)0x0;
    if (multi != (MultiSpline *)0x0)
    {
      pSVar1 = &multi->curPositional;
    }
    return pSVar1;
  }
  return (SplineDef *)&instance->work0;
}

SplineDef *
SCRIPT_GetRotSplineDef(_Instance *instance, MultiSpline *multi, u_long isParent, u_long isClass)

{
  SplineDef *pSVar1;

  if ((isParent == 0) && (isClass == 0))
  {
    pSVar1 = (SplineDef *)0x0;
    if (multi != (MultiSpline *)0x0)
    {
      pSVar1 = &multi->curRotational;
    }
    return pSVar1;
  }
  return (SplineDef *)&instance->work2;
}

SplineDef *
SCRIPT_GetScaleSplineDef(_Instance *instance, MultiSpline *multi, u_long isParent, u_long isClass)

{
  SplineDef *pSVar1;

  if ((isParent == 0) && (isClass == 0))
  {
    pSVar1 = (SplineDef *)0x0;
    if (multi != (MultiSpline *)0x0)
    {
      pSVar1 = &multi->curScaling;
    }
    return pSVar1;
  }
  return (SplineDef *)&instance->work4;
}

void SCRIPT_RelativisticSpline(_Instance *instance, _SVector *point)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  Intro *pIVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  short local_38;
  short local_36;
  short local_34;
  short local_32;
  short local_30;
  short local_2e;
  short local_2c;
  short local_2a;
  short local_28;
  short local_10;
  short local_e;
  short local_c;

  pIVar5 = instance->intro;
  if ((pIVar5 == (Intro *)0x0) || ((*(int *)&pIVar5->rotation == 0 && ((pIVar5->rotation).z == 0))))
  {
    sVar1 = (instance->initialPos).y;
    sVar2 = (instance->initialPos).z;
    sVar3 = point->y;
    sVar4 = point->z;
    (instance->position).x = (instance->initialPos).x + point->x;
    (instance->position).y = sVar1 + sVar3;
    (instance->position).z = sVar2 + sVar4;
  }
  else
  {
    local_10 = point->x;
    local_e = point->y;
    local_c = point->z;
    RotMatrixY((u_short *)&instance->intro->rotation, (u_int *)&local_38);
    iVar7 = (int)local_10;
    iVar6 = (int)local_e;
    iVar8 = (int)local_c;
    sVar1 = (instance->initialPos).y;
    sVar2 = (instance->initialPos).z;
    (instance->position).x =
        (short)(iVar7 * local_38 >> 0xc) + (short)(iVar6 * local_36 >> 0xc) +
        (short)(iVar8 * local_34 >> 0xc) + (instance->initialPos).x;
    (instance->position).y =
        (short)(iVar7 * local_32 >> 0xc) + (short)(iVar6 * local_30 >> 0xc) +
        (short)(iVar8 * local_2e >> 0xc) + sVar1;
    (instance->position).z =
        (short)(iVar7 * local_2c >> 0xc) + (short)(iVar6 * local_2a >> 0xc) +
        (short)(iVar8 * local_28 >> 0xc) + sVar2;
  }
  return;
}

void SCRIPT_InstanceSplineProcess(_Instance *instance, short frameNum, SplineDef *splineDef, SplineDef *rsplineDef,
                                  SplineDef *ssplineDef)

{
  MultiSpline *multi;
  u_long uVar1;
  Intro *pIVar2;
  Spline *spline;
  MATRIX *pMVar3;
  Spline *spline_00;
  Spline *spline_01;
  _SVector local_60;
  short local_58;
  short local_56;
  short local_54;
  _Rotation local_50[4];
  u_long local_30;
  u_long local_2c;

  multi = SCRIPT_GetMultiSpline(instance, &local_30, &local_2c);
  if (multi != (MultiSpline *)0x0)
  {
    if (frameNum == -1)
    {
      frameNum = SCRIPTCountFramesInSpline(instance);
    }
    if (((local_30 != 0) || (local_2c != 0)) ||
        ((splineDef == (SplineDef *)0x0 &&
          ((rsplineDef == (SplineDef *)0x0 && (ssplineDef == (SplineDef *)0x0))))))
    {
      splineDef = SCRIPT_GetPosSplineDef(instance, multi, local_30, local_2c);
      rsplineDef = SCRIPT_GetRotSplineDef(instance, multi, local_30, local_2c);
      ssplineDef = SCRIPT_GetScaleSplineDef(instance, multi, local_30, local_2c);
    }
    spline = multi->positional;
    spline_00 = (Spline *)multi->rotational;
    spline_01 = multi->scaling;
    if ((splineDef != (SplineDef *)0x0) && (spline != (Spline *)0x0))
    {
      SplineSetDef2FrameNumber(spline, splineDef, frameNum);
      SplineGetNext(spline, splineDef, &local_60);
      if (local_2c == 0)
      {
        (instance->position).x = local_60.x;
        (instance->position).y = local_60.y;
        (instance->position).z = local_60.z;
      }
      else
      {
        SCRIPT_RelativisticSpline(instance, &local_60);
      }
    }
    if ((rsplineDef != (SplineDef *)0x0) && (spline_00 != (Spline *)0x0))
    {
      SplineSetDef2FrameNumber(spline_00, rsplineDef, frameNum);
      if ((instance->flags & 1U) == 0)
      {
        uVar1 = SplineGetNext(spline_00, rsplineDef, &local_58);
        if (uVar1 != 0)
        {
          pIVar2 = instance->intro;
          (instance->rotation).x = local_58;
          (instance->rotation).y = local_56;
          (instance->rotation).z = local_54;
          SCRIPT_CombineEulerAngles(local_50, &instance->rotation, &pIVar2->rotation);
          (instance->rotation).x = local_50[0].x;
          (instance->rotation).y = local_50[0].y;
          (instance->rotation).z = local_50[0].z;
        }
      }
      else
      {
        uVar1 = SplineGetQuatData(spline_00, rsplineDef, &local_58);
        if (uVar1 != 0)
        {
          pMVar3 = &multi->curRotMatrix;
          G2Quat_ToMatrix_S(&local_58, (short *)pMVar3);
          if (instance->intro != (Intro *)0x0)
          {
            RotMatrixY((u_short *)&instance->intro->rotation, (u_int *)local_50);
            PopMatrix((u_char *)pMVar3, (u_short *)local_50, (u_int *)pMVar3);
          }
        }
      }
    }
    if ((ssplineDef != (SplineDef *)0x0) && (spline_01 != (Spline *)0x0))
    {
      SplineSetDef2FrameNumber(spline_01, ssplineDef, frameNum);
      SplineGetNext(spline_01, ssplineDef, &local_58);
      (instance->scale).x = local_58;
      (instance->scale).y = local_54;
      (instance->scale).z = local_56;
    }
  }
  return;
}

long CAMERA_SplineProcess(_Instance *instance, MultiSpline *multi, SplineDef *splineDef, SplineDef *rsplineDef,
                          SplineDef *ssplineDef, int direction, int isClass)

{
  u_long uVar1;
  u_long fracOffset;
  Spline *spline;
  Intro *pIVar2;
  Spline *spline_00;
  MATRIX *pMVar3;
  _SVector *point;
  u_int uVar4;
  Spline *spline_01;
  short local_60;
  short local_5e;
  short local_5c;
  _SVector _Stack88;
  _SVector _Stack80;
  _Rotation local_48[4];

  fracOffset = gameTrackerX.timeMult;
  uVar4 = 0xffffffff;
  spline_01 = multi->positional;
  spline = multi->scaling;
  spline_00 = (Spline *)multi->rotational;
  point = (_SVector *)0x0;
  if (spline != (Spline *)0x0)
  {
    if (direction < 1)
    {
      if (direction < 0)
      {
        point = SplineGetOffsetPreviousPoint(spline, ssplineDef);
      }
      else
      {
        uVar1 = SplineGetNext(spline, ssplineDef, &_Stack88);
        if (uVar1 != 0)
        {
          point = &_Stack88;
        }
      }
    }
    else
    {
      point = SplineGetOffsetNextPoint(spline, ssplineDef);
    }
    uVar4 = 0;
    if (point == (_SVector *)0x0)
    {
      uVar4 = 1;
    }
    else
    {
      (instance->scale).x = point->x;
      (instance->scale).y = point->z;
      (instance->scale).z = point->y;
    }
  }
  if (spline_00 != (Spline *)0x0)
  {
    uVar4 = 0;
    if (direction < 1)
    {
      if ((direction < 0) &&
          (uVar1 = SplineGetOffsetNext(spline_00, rsplineDef, fracOffset), uVar1 == 0))
      {
        uVar4 = 1;
      }
    }
    else
    {
      uVar1 = SplineGetOffsetPrev(spline_00, rsplineDef, fracOffset);
      uVar4 = (u_int)(uVar1 == 0);
    }
    if (uVar4 == 0)
    {
      if ((instance->flags & 1U) == 0)
      {
        uVar1 = SplineGetNext(spline_00, rsplineDef, &local_60);
        if (uVar1 != 0)
        {
          pIVar2 = instance->intro;
          (instance->rotation).x = local_60;
          (instance->rotation).y = local_5e;
          (instance->rotation).z = local_5c;
          SCRIPT_CombineEulerAngles(local_48, &instance->rotation, &pIVar2->rotation);
          (instance->rotation).x = local_48[0].x;
          (instance->rotation).y = local_48[0].y;
          (instance->rotation).z = local_48[0].z;
          goto LAB_8003defc;
        }
      }
      else
      {
        uVar1 = SplineGetQuatData(spline_00, rsplineDef, &_Stack80);
        if (uVar1 != 0)
        {
          pMVar3 = &multi->curRotMatrix;
          G2Quat_ToMatrix_S((short *)&_Stack80, (short *)pMVar3);
          if (instance->intro != (Intro *)0x0)
          {
            RotMatrixY((u_short *)&instance->intro->rotation, (u_int *)local_48);
            PopMatrix((u_char *)pMVar3, (u_short *)local_48, (u_int *)pMVar3);
          }
          goto LAB_8003defc;
        }
      }
      uVar4 = 1;
    }
  }
LAB_8003defc:
  if (spline_01 != (Spline *)0x0)
  {
    if (direction < 1)
    {
      if (direction < 0)
      {
        point = SplineGetPrev(spline_01, splineDef, fracOffset);
      }
      else
      {
        fracOffset = SplineGetNext(spline_01, splineDef, &_Stack80);
        if (fracOffset != 0)
        {
          point = &_Stack80;
        }
      }
    }
    else
    {
      point = SplineGetNextPoint(spline_01, splineDef, fracOffset);
    }
    uVar4 = 1;
    if (point != (_SVector *)0x0)
    {
      uVar4 = 0;
      if (isClass == 0)
      {
        (instance->position).x = point->x;
        (instance->position).y = point->y;
        (instance->position).z = point->z;
      }
      else
      {
        SCRIPT_RelativisticSpline(instance, point);
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}

long SCRIPT_InstanceSplineSet(_Instance *instance, SplineDef *splineDef, SplineDef *rsplineDef, SplineDef *ssplineDef, int direction)

{
  MultiSpline *multi;
  long lVar1;
  u_long local_20;
  u_long local_1c;

  multi = SCRIPT_GetMultiSpline(instance, &local_20, &local_1c);
  lVar1 = -1;
  if (multi != (MultiSpline *)0x0)
  {
    if (((local_20 != 0) || (local_1c != 0)) ||
        ((splineDef == (SplineDef *)0x0 &&
          ((rsplineDef == (SplineDef *)0x0 && (ssplineDef == (SplineDef *)0x0))))))
    {
      splineDef = SCRIPT_GetPosSplineDef(instance, multi, local_20, local_1c);
      rsplineDef = SCRIPT_GetRotSplineDef(instance, multi, local_20, local_1c);
      ssplineDef = SCRIPT_GetScaleSplineDef(instance, multi, local_20, local_1c);
    }
    lVar1 = CAMERA_SplineProcess(instance, multi, splineDef, rsplineDef, ssplineDef, direction, local_1c);
  }
  return lVar1;
}

void SCRIPT_SplineProcess(_Instance *instance)

{
  int iVar1;

  iVar1 = (u_int)(u_short)instance->fadeValue + (gameTrackerX.timeMult >> 5);
  instance->fadeValue = (short)iVar1;
  if (0xfff < iVar1 * 0x10000 >> 0x10)
  {
    INSTANCE_PlainDeath(instance);
  }
  return;
}

void ScriptKillInstance(_Instance *instance, int effect)

{
  bool bVar1;
  int iVar2;
  Object *pOVar3;

  pOVar3 = instance->object;
  if ((pOVar3->oflags2 & 4U) != 0)
  {
    SOUND_StopInstanceSound(pOVar3->soundData, instance->soundInstanceTbl);
  }
  if ((((pOVar3->oflags & 0x40000000U) != 0) && ((int *)instance->introData != (int *)0x0)) &&
      (iVar2 = *(int *)instance->introData, iVar2 != 0))
  {
    SIGNAL_HandleFogNear(instance, (Signal *)(iVar2 + 8), 0);
  }
  bVar1 = (u_int)effect < 8;
  if ((effect == 1) && (bVar1 = true, (instance->object->oflags & 0x8000U) != 0))
  {
    effect = 5;
    bVar1 = true;
  }
  if (!bVar1)
  {
    INSTANCE_PlainDeath(instance);
    return;
  }

  (*(code *)(&PTR_LAB_8001015c)[effect])();
  return;
}
