#include "THISDUST.H"
#include "ANMCTRLR.H"

void G2Anim_AttachControllerToSeg(_G2Anim_Type *anim, int segNumber, int type)

{
  _G2AnimController_Type *controller;

  controller = _G2AnimController_GetMatrix(segNumber, type);
  _G2AnimController_InsertIntoList(controller, &anim->controllerList);
  return;
}

void razAttachControllers(_G2Anim_Type *anim, int segNumber, int type)

{
  _G2AnimController_Type *controller;
  u_short *local_20[2];

  local_20[0] = &anim->controllerList;
  controller = _G2AnimController_Create(segNumber, type, local_20);
  if (controller == (_G2AnimController_Type *)0x0)
  {
    local_20[0] = &anim->disabledControllerList;
    controller = _G2AnimController_Create(segNumber, type, local_20);
    if (controller == (_G2AnimController_Type *)0x0)
    {
      return;
    }
  }
  controller = G2Anim_IsControllerActive(controller);
  *local_20[0] = (u_short)((int)((int)controller - (int)_controllerPool.blockPool) * 0x38e38e39 >> 2);

  return;
}

void G2Anim_DisableController(_G2Anim_Type *anim, int segNumber, int type)

{
  _G2AnimController_Type *controller;
  _G2Matrix_Type *p_Var1;

  controller = _G2AnimController_GetVector(segNumber, type, &anim->disabledControllerList);
  if (controller != (_G2AnimController_Type *)0x0)
  {
    controller->duration = 0;
    controller->elapsedTime = 0;
    controller->flags = (u_short) * (byte *)&controller->flags;
    if (controller->type == '\b')
    {
      G2EulerAngles_ToMatrix_S((undefined2 *)(controller->data + 8), (short *)(anim->segMatrices + segNumber));
    }
    else
    {
      if (controller->type == ' ')
      {
        p_Var1 = anim->segMatrices + segNumber;
        *(undefined2 *)controller->data = *(undefined2 *)&(p_Var1->trans).x;
        *(undefined2 *)(controller->data + 2) = *(undefined2 *)&(p_Var1->trans).y;
        *(undefined2 *)(controller->data + 4) = *(undefined2 *)&(p_Var1->trans).z;
      }
      else
      {
        memset(controller->data, 0, 0x10);
      }
    }
    _G2AnimController_InsertIntoList(controller, &anim->controllerList);
  }
  return;
}

void _G2Anim_FindController(_G2Anim_Type *anim, int segNumber, int type)

{
  _G2AnimController_Type *controller;

  controller = _G2AnimController_GetVector(segNumber, type, &anim->controllerList);
  if (controller != (_G2AnimController_Type *)0x0)
  {
    _G2AnimController_InsertIntoList(controller, &anim->disabledControllerList);
  }
  return;
}

void G2Anim_InterpDisableController(_G2Anim_Type *anim, int segNumber, int type, short duration)

{
  _G2AnimController_Type *controller;
  _G2SVector3_Type _Stack48;
  _G2Quat_Type _Stack40;

  memset(&_Stack48, 0, 6);
  if ((duration == 0) || (type == 0x20))
  {
    _G2Anim_FindController(anim, segNumber, type);
  }
  controller = G2Anim_SetInterpController_Quat(segNumber, type, &anim->controllerList);
  if (controller != (_G2AnimController_Type *)0x0)
  {
    if (controller->type == '\b')
    {
      G2Anim_AttachControllerToSeg(controller, anim, &_Stack40);
      G2Anim_IsControllerInterpolating(anim, segNumber, type, &_Stack40, (int)duration);
    }
    else
    {
      G2EmulationSetInterpController_Vector(anim, segNumber, type, &_Stack48, (int)duration);
    }
    controller->flags = controller->flags | 0x8000;
  }
  return;
}

_G2Bool_Enum G2Anim_DetachControllerFromSeg(_G2Anim_Type *anim, int segNumber, int type)

{
  _G2AnimController_Type *p_Var1;
  _G2Bool_Enum _Var2;

  p_Var1 = G2Anim_SetInterpController_Quat(segNumber, type, &anim->controllerList);
  if (p_Var1 == (_G2AnimController_Type *)0x0)
  {
    _Var2 = G2FALSE;
  }
  else
  {
    _Var2 = (_G2Bool_Enum)((p_Var1->flags & 0x8000) == 0);
  }
  return _Var2;
}

_G2Bool_Enum G2Anim_SetControllerAngleOrder(_G2Anim_Type *anim, int segNumber, int type)

{
  _G2AnimController_Type *p_Var1;
  _G2Bool_Enum _Var2;

  p_Var1 = G2Anim_SetInterpController_Quat(segNumber, type, &anim->controllerList);
  if ((p_Var1 == (_G2AnimController_Type *)0x0) || ((p_Var1->flags & 0x4000) == 0))
  {
    _Var2 = G2FALSE;
  }
  else
  {
    _Var2 = (_G2Bool_Enum)((p_Var1->flags & 0x2000) == 0);
  }
  return _Var2;
}

void _G2AnimController_ApplyToSegValue(_G2Anim_Type *anim, int segNumber, int type, _G2SVector3_Type *vector)

{
  u_char uVar1;
  short sVar2;
  _G2AnimController_Type *p_Var3;
  _G2Matrix_Type *p_Var4;
  u_char uVar5;
  u_char uVar6;
  u_char uVar7;

  p_Var3 = G2Anim_EnableController(anim, segNumber, type);
  if (p_Var3->duration == 0)
  {
    uVar1 = p_Var3->type;
    if (uVar1 == '\x12')
    {
      G2Anim_GetSegChannelValue(anim, (u_int)p_Var3->segNumber, (u_short *)vector, 0x70);
    }
    else
    {
      if (uVar1 == '\"')
      {
        G2Anim_GetSegChannelValue(anim, (u_int)p_Var3->segNumber, (u_short *)vector, 0x700);
      }
      else
      {
        if (uVar1 == ' ')
        {
          p_Var4 = anim->segMatrices + p_Var3->segNumber;
          vector->x = *(short *)&(p_Var4->trans).x;
          vector->y = *(short *)&(p_Var4->trans).y;
          vector->z = *(short *)&(p_Var4->trans).z;
        }
      }
    }
  }
  else
  {
    if ((p_Var3->flags & 0x2000) == 0)
    {
      setCopReg(2, 0xc800, (u_int) * (u_short *)p_Var3->data);
      setCopReg(2, 0xd000, (u_int) * (u_short *)(p_Var3->data + 2));
      setCopReg(2, 0xd800, (u_int) * (u_short *)(p_Var3->data + 4));
      setCopReg(2, 0x4800, (u_int) * (u_short *)(p_Var3->data + 6));
      setCopReg(2, 0x5000, (u_int) * (u_short *)(p_Var3->data + 8));
      setCopReg(2, 0x5800, (u_int) * (u_short *)(p_Var3->data + 10));
      setCopReg(2, 0x4000, (int)p_Var3->elapsedTime);
      copFunction(2, 0x1a8003e);
      uVar5 = getCopReg(2, 0xc800);
      uVar6 = getCopReg(2, 0xd000);
      uVar7 = getCopReg(2, 0xd800);
      vector->x = (short)uVar5;
      vector->y = (short)uVar6;
      vector->z = (short)uVar7;
    }
    else
    {
      sVar2 = *(short *)(p_Var3->data + 4);
      *(u_char *)vector = *(u_char *)p_Var3->data;
      vector->z = sVar2;
    }
  }
  return;
}

void G2Anim_SetInterpController_Vector(_G2Anim_Type *anim, int segNumber, int type, void *callbackData)

{
  _G2AnimController_Type *p_Var1;

  p_Var1 = G2Anim_EnableController(anim, segNumber, type);
  p_Var1->callbackData = callbackData;
  return;
}

void _G2Anim_ApplyControllersToStoredFrame(_G2Anim_Type *anim, int segNumber, int type, int order)

{
  _G2AnimController_Type *p_Var1;

  p_Var1 = G2Anim_EnableController(anim, segNumber, type);
  p_Var1->flags = p_Var1->flags & 0xff00 | (u_short)order;
  return;
}

void G2Anim_GetControllerCurrentInterpVector(_G2Anim_Type *anim, int segNumber, int type, _G2SVector3_Type *vector)

{
  short sVar1;
  _G2AnimController_Type *p_Var2;

  p_Var2 = G2Anim_EnableController(anim, segNumber, type);
  sVar1 = vector->z;
  *(u_char *)p_Var2->data = *(u_char *)vector;
  *(short *)(p_Var2->data + 4) = sVar1;
  p_Var2->flags = (u_short) * (byte *)&p_Var2->flags;
  return;
}

void G2EmulationSetInterpController_Vector(_G2Anim_Type *anim, int segNumber, int type, _G2SVector3_Type *vector, int duration)

{
  _G2AnimController_Type *p_Var1;
  short sVar2;
  int iVar3;
  _G2EulerAngles_Type _Stack48;
  _G2Quat_Type _Stack40;

  p_Var1 = G2Anim_EnableController(anim, segNumber, type);
  sVar2 = (short)duration;
  if ((p_Var1->type & 0x38) == 8)
  {
    _G2Anim_CopyVectorWithOrder(vector, &_Stack48, (u_int) * (byte *)&p_Var1->flags);
    G2Quat_ToEuler((int)&_Stack40, (short *)&_Stack48);
    G2Anim_IsControllerInterpolating(anim, segNumber, type, &_Stack40, (int)sVar2);
  }
  else
  {
    _G2AnimController_ApplyToSegValue(anim, segNumber, type, (_G2SVector3_Type *)p_Var1->data);
    iVar3 = (int)sVar2 + 1;
    *(short *)(p_Var1->data + 6) =
 iVar3);
    *(short *)(p_Var1->data + 8) =
 iVar3);
    *(short *)(p_Var1->data + 10) =
 iVar3);
    p_Var1->duration = sVar2;
    p_Var1->elapsedTime = 0;
    p_Var1->flags = (u_short) * (byte *)&p_Var1->flags | 0x4000;
  }
  return;
}

void G2Anim_IsControllerInterpolating(_G2Anim_Type *anim, int segNumber, int type, _G2Quat_Type *quat, int duration)

{
  byte bVar1;
  _G2AnimController_Type *controller;
  u_char uVar2;
  u_char uVar3;

  controller = G2Anim_EnableController(anim, segNumber, type);
  G2EmulationSetInterpController_Vector(controller, anim, (_G2Quat_Type *)controller->data);
  uVar2 = *(u_char *)quat;
  uVar3 = *(u_char *)&quat->z;
  bVar1 = *(byte *)&controller->flags;
  controller->elapsedTime = 0;
  *(u_char *)(controller->data + 8) = uVar2;
  *(u_char *)(controller->data + 0xc) = uVar3;
  controller->flags = (u_short)bVar1 | 0x4000;
  controller->duration = (short)duration;
  return;
}

void _G2Anim_ApplyControllersToStoredFrame(_G2Anim_Type *anim)

{
  int iVar1;
  int iVar2;

  iVar1 = 0;
  if (anim->sectionCount != '\0')
  {
    iVar2 = 0x24;
    do
    {
      _G2AnimSection_ApplyControllersToStoredFrame((_G2AnimSection_Type *)(&anim->sectionCount + iVar2));
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x30;
    } while (iVar1 < (int)(u_int)anim->sectionCount);
  }
  return;
}

void _G2Anim_BuildSegTransformNoControllers(_G2Anim_Type *anim)

{
  byte bVar1;
  int iVar2;
  _G2Bool_Enum bRootTransUpdated;
  _G2AnimController_Type *controller;
  u_int segIndex;
  u_int *puVar3;
  u_int uVar4;
  u_short *puVar5;
  _G2Matrix_Type *segMatrix;
  int iVar6;
  u_long local_38[4];

  uVar4 = 1;
  segIndex = 0;
  segMatrix = anim->segMatrices;
  local_38[0] = anim->disabledBits[0];
  local_38[1] = anim->disabledBits[1];
  bRootTransUpdated = (_G2Bool_Enum)((anim->section[0].flags & 0x88) == 0x80);
  local_38[2] = anim->disabledBits[2];
  iVar6 = anim->modelData->numSegments;
  controller = _controllerPool.blockPool + anim->controllerList;
  if (0 < iVar6)
  {
    puVar5 = (u_short *)&anim->modelData->segmentList->parent;
    puVar3 = local_38;
    do
    {
      iVar2 = (u_int)*puVar5 << 0x10;
      if ((iVar2 >> 0x10 != -1) && ((local_38[iVar2 >> 0x15] & 1 << (*puVar5 & 0x1f)) != 0))
      {
        *puVar3 = *puVar3 | uVar4;
      }
      if ((*puVar3 & uVar4) == 0)
      {
        if ((u_int)controller->segNumber == segIndex)
        {
          _G2Anim_UpdateControllers(segMatrix, anim->segMatrices + (short)*puVar5, controller, bRootTransUpdated,
                                    segIndex);
          bVar1 = controller->segNumber;
          while ((u_int)bVar1 == segIndex)
          {
            controller = _controllerPool.blockPool + controller->next;
            bVar1 = controller->segNumber;
          }
        }
        else
        {
          _G2Anim_BuildSegTransformWithControllers(segMatrix, anim->segMatrices + (short)*puVar5, bRootTransUpdated, segIndex);
        }
      }
      puVar5 = puVar5 + 0xc;
      bRootTransUpdated = G2FALSE;
      segMatrix = segMatrix + 1;
      uVar4 = uVar4 << 1;
      segIndex = segIndex + 1;
      if (uVar4 == 0)
      {
        puVar3 = puVar3 + 1;
        uVar4 = 1;
      }
    } while ((int)segIndex < iVar6);
  }
  G2Anim_SetControllerCallbackData(anim);
  return;
}

void _G2Anim_UpdateControllers(_G2Matrix_Type *segMatrix, _G2Matrix_Type *parentMatrix,
                               _G2AnimController_Type *controller, _G2Bool_Enum bRootTransUpdated, int segIndex)

{
  byte bVar1;
  u_short uVar2;
  u_short uVar3;
  u_short uVar4;
  long lVar5;
  u_char in_zero;
  u_char in_at;
  u_long uVar6;
  u_char uVar7;
  u_char uVar8;
  u_char uVar9;
  u_char uVar10;
  u_int uVar11;
  int local_30;
  int local_2c;
  int local_28;

  _G2Anim_BuildSegLocalRotMatrix(&_segValues + segIndex, segMatrix);
  bVar1 = controller->segNumber;
  uVar11 = 7;
  while ((u_int)bVar1 == segIndex)
  {

    uVar6 = _G2AnimController_Destroy(controller, &_segValues + segIndex, segMatrix, parentMatrix);
    controller = _controllerPool.blockPool + controller->next;
    bVar1 = controller->segNumber;
    uVar11 = uVar11 & uVar6;
  }

  setCopControlWord(2, 0, *(u_char *)parentMatrix->rotScale);
  setCopControlWord(2, 0x800, *(u_char *)(parentMatrix->rotScale + 2));
  setCopControlWord(2, 0x1000, *(u_char *)(parentMatrix->rotScale + 4));
  setCopControlWord(2, 0x1800, *(u_char *)(parentMatrix->rotScale + 6));
  setCopControlWord(2, 0x2000, *(u_char *)(parentMatrix->rotScale + 8));
  uVar2 = (&_segValues)[segIndex].scale.x;
  local_30 = (int)(short)uVar2;
  uVar3 = (&_segValues)[segIndex].scale.y;
  local_2c = (int)(short)uVar3;
  uVar4 = (&_segValues)[segIndex].scale.z;
  local_28 = (int)(short)uVar4;
  if ((u_short)(uVar2 | uVar3 | uVar4) != 0x1000)
  {
    ScaleMatrix((int *)segMatrix, &local_30);
    segMatrix->scaleFlag = 1;
  }
  if ((uVar11 & 1) != 0)
  {
    setCopReg(2, 0x4800, (u_int)(u_short)segMatrix->rotScale[0]);
    setCopReg(2, 0x5000, (u_int)(u_short)segMatrix->rotScale[3]);
    setCopReg(2, 0x5800, (u_int)(u_short)segMatrix->rotScale[6]);
    copFunction(2, 0x49e012);
    uVar2 = segMatrix->rotScale[2];
    uVar8 = getCopReg(2, 0x4800);
    uVar9 = getCopReg(2, 0x5000);
    uVar10 = getCopReg(2, 0x5800);
    setCopReg(2, 0x4800, (u_int)(u_short)segMatrix->rotScale[1]);
    setCopReg(2, 0x5000, (u_int)(u_short)segMatrix->rotScale[4]);
    setCopReg(2, 0x5800, (u_int)(u_short)segMatrix->rotScale[7]);
    segMatrix->rotScale[0] = (short)uVar8;
    segMatrix->rotScale[3] = (short)uVar9;
    copFunction(2, 0x49e012);
    uVar8 = getCopReg(2, 0x4800);
    uVar9 = getCopReg(2, 0x5000);
    uVar7 = getCopReg(2, 0x5800);
    setCopReg(2, 0x4800, (u_int)uVar2);
    setCopReg(2, 0x5000, (u_int)(u_short)segMatrix->rotScale[5]);
    setCopReg(2, 0x5800, (u_int)(u_short)segMatrix->rotScale[8]);
    segMatrix->rotScale[6] = (short)uVar10;
    segMatrix->rotScale[1] = (short)uVar8;
    copFunction(2, 0x49e012);
    segMatrix->rotScale[4] = (short)uVar9;
    segMatrix->rotScale[7] = (short)uVar7;
    uVar8 = getCopReg(2, 0x4800);
    uVar9 = getCopReg(2, 0x5000);
    uVar7 = getCopReg(2, 0x5800);
    segMatrix->rotScale[2] = (short)uVar8;
    segMatrix->rotScale[5] = (short)uVar9;
    segMatrix->rotScale[8] = (short)uVar7;
  }
  if ((uVar11 & 4) == 0)
  {
    (segMatrix->trans).x = (int)(&_segValues)[segIndex].trans.x;
    (segMatrix->trans).y = (int)(&_segValues)[segIndex].trans.y;
    (segMatrix->trans).z = (int)(&_segValues)[segIndex].trans.z;
  }
  else
  {
    if (segIndex == 0)
    {
      setCopControlWord(2, 0, *(u_char *)segMatrix->rotScale);
      setCopControlWord(2, 0x800, *(u_char *)(segMatrix->rotScale + 2));
      setCopControlWord(2, 0x1000, *(u_char *)(segMatrix->rotScale + 4));
      setCopControlWord(2, 0x1800, *(u_char *)(segMatrix->rotScale + 6));
      setCopControlWord(2, 0x2000, *(u_char *)(segMatrix->rotScale + 8));
    }
    setCopReg(2, in_zero, *(u_char *)&(&_segValues)[segIndex].trans);
    setCopReg(2, in_at, *(u_char *)&(&_segValues)[segIndex].trans.z);
    copFunction(2, 0x486012);
    lVar5 = getCopReg(2, 0x19);
    (segMatrix->trans).x = lVar5;
    lVar5 = getCopReg(2, 0x1a);
    (segMatrix->trans).y = lVar5;
    lVar5 = getCopReg(2, 0x1b);
    (segMatrix->trans).z = lVar5;
  }
  if (bRootTransUpdated != G2FALSE)
  {
    (parentMatrix->trans).x = (parentMatrix->trans).x + (segMatrix->trans).x;
    (parentMatrix->trans).y = (parentMatrix->trans).y + (segMatrix->trans).y;
    (parentMatrix->trans).z = (parentMatrix->trans).z + (segMatrix->trans).z;
    (segMatrix->trans).x = 0;
    (segMatrix->trans).y = 0;
    (segMatrix->trans).z = 0;
  }
  (segMatrix->trans).x = (segMatrix->trans).x + (parentMatrix->trans).x;
  (segMatrix->trans).y = (segMatrix->trans).y + (parentMatrix->trans).y;
  (segMatrix->trans).z = (segMatrix->trans).z + (parentMatrix->trans).z;
  return;
}

u_long _G2AnimController_Destroy(_G2AnimController_Type *controller, _G2AnimSegValue_Type *segValue,
                                 _G2Matrix_Type *segMatrix, _G2Matrix_Type *parentMatrix)

{
  u_short uVar1;
  u_long uVar2;
  u_char uVar3;
  u_char uVar4;
  u_char uVar5;
  u_char uVar6;
  u_char local_40;
  u_char local_3c;
  u_char local_38;
  u_char local_34;
  u_char local_30;
  u_char local_20;
  short local_1c;

  if ((*(u_int *)controller & 0xff020000) == 0)
  {
    uVar2 = _G2AnimController_ApplyWorldToParentMatrix(controller, parentMatrix);
    return uVar2;
  }
  uVar2 = 7;
  switch (controller->type)
  {
  case '\x01':
    uVar2 = (**(code **)controller->data)(controller, segValue, parentMatrix, segMatrix,
                                          *(u_char *)(controller->data + 4));
    break;
  case '\b':
    uVar2 = 6;
  case '\n':
    FX_GetMatrix(controller, segMatrix);
    break;
  case '\x10':
    uVar2 = 5;
  case '\x12':
    G2Anim_SetController_Vector(controller, (_G2SVector3_Type *)&local_20);
    *(u_char *)&segValue->scale = local_20;
    (segValue->scale).z = local_1c;
    break;
  case '\x16':
    G2Anim_SetController_Vector(controller, (_G2SVector3_Type *)&local_20);
    (segValue->scale).x = (segValue->scale).x + (short)local_20;
    (segValue->scale).y = (segValue->scale).y + local_20._2_2_;
    (segValue->scale).z = (segValue->scale).z + local_1c;
    break;
  case ' ':
    uVar2 = 3;
    G2Anim_SetController_Vector(controller, (_G2SVector3_Type *)&local_20);
    (segValue->trans).x = (short)local_20 - *(short *)&(parentMatrix->trans).x;
    (segValue->trans).y = local_20._2_2_ - *(short *)&(parentMatrix->trans).y;
    local_1c = local_1c - *(short *)&(parentMatrix->trans).z;
    goto LAB_80090d64;
  case '\"':
    G2Anim_SetController_Vector(controller, (_G2SVector3_Type *)&local_20);
    *(u_char *)&segValue->trans = local_20;
    (segValue->trans).z = local_1c;
    break;
  case '&':
    G2Anim_SetController_Vector(controller, (_G2SVector3_Type *)&local_20);
    (segValue->trans).x = (segValue->trans).x + (short)local_20;
    (segValue->trans).y = (segValue->trans).y + local_20._2_2_;
    local_1c = (segValue->trans).z + local_1c;
  LAB_80090d64:
    (segValue->trans).z = local_1c;
    break;
  case 'L':
    uVar2 = 6;
    setCopControlWord(2, 0, *(u_char *)parentMatrix->rotScale);
    setCopControlWord(2, 0x800, *(u_char *)(parentMatrix->rotScale + 2));
    setCopControlWord(2, 0x1000, *(u_char *)(parentMatrix->rotScale + 4));
    setCopControlWord(2, 0x1800, *(u_char *)(parentMatrix->rotScale + 6));
    setCopControlWord(2, 0x2000, *(u_char *)(parentMatrix->rotScale + 8));
    setCopReg(2, 0x4800, (u_int)(u_short)segMatrix->rotScale[0]);
    setCopReg(2, 0x5000, (u_int)(u_short)segMatrix->rotScale[3]);
    setCopReg(2, 0x5800, (u_int)(u_short)segMatrix->rotScale[6]);
    copFunction(2, 0x49e012);
    uVar1 = segMatrix->rotScale[2];
    uVar4 = getCopReg(2, 0x4800);
    uVar5 = getCopReg(2, 0x5000);
    uVar6 = getCopReg(2, 0x5800);
    setCopReg(2, 0x4800, (u_int)(u_short)segMatrix->rotScale[1]);
    setCopReg(2, 0x5000, (u_int)(u_short)segMatrix->rotScale[4]);
    setCopReg(2, 0x5800, (u_int)(u_short)segMatrix->rotScale[7]);
    segMatrix->rotScale[0] = (short)uVar4;
    segMatrix->rotScale[3] = (short)uVar5;
    copFunction(2, 0x49e012);
    uVar4 = getCopReg(2, 0x4800);
    uVar5 = getCopReg(2, 0x5000);
    uVar3 = getCopReg(2, 0x5800);
    setCopReg(2, 0x4800, (u_int)uVar1);
    setCopReg(2, 0x5000, (u_int)(u_short)segMatrix->rotScale[5]);
    setCopReg(2, 0x5800, (u_int)(u_short)segMatrix->rotScale[8]);
    segMatrix->rotScale[6] = (short)uVar6;
    segMatrix->rotScale[1] = (short)uVar4;
    copFunction(2, 0x49e012);
    segMatrix->rotScale[4] = (short)uVar5;
    segMatrix->rotScale[7] = (short)uVar3;
    uVar4 = getCopReg(2, 0x4800);
    uVar5 = getCopReg(2, 0x5000);
    uVar3 = getCopReg(2, 0x5800);
    segMatrix->rotScale[2] = (short)uVar4;
    segMatrix->rotScale[5] = (short)uVar5;
    segMatrix->rotScale[8] = (short)uVar3;
  case '\x0e':
    FX_GetMatrix(controller, (_G2Matrix_Type *)&local_40);
    setCopControlWord(2, 0, local_40);
    setCopControlWord(2, 0x800, local_3c);
    setCopControlWord(2, 0x1000, local_38);
    setCopControlWord(2, 0x1800, local_34);
    setCopControlWord(2, 0x2000, local_30);
    setCopReg(2, 0x4800, (u_int)(u_short)segMatrix->rotScale[0]);
    setCopReg(2, 0x5000, (u_int)(u_short)segMatrix->rotScale[3]);
    setCopReg(2, 0x5800, (u_int)(u_short)segMatrix->rotScale[6]);
    copFunction(2, 0x49e012);
    uVar1 = segMatrix->rotScale[2];
    uVar4 = getCopReg(2, 0x4800);
    uVar5 = getCopReg(2, 0x5000);
    uVar6 = getCopReg(2, 0x5800);
    setCopReg(2, 0x4800, (u_int)(u_short)segMatrix->rotScale[1]);
    setCopReg(2, 0x5000, (u_int)(u_short)segMatrix->rotScale[4]);
    setCopReg(2, 0x5800, (u_int)(u_short)segMatrix->rotScale[7]);
    segMatrix->rotScale[0] = (short)uVar4;
    segMatrix->rotScale[3] = (short)uVar5;
    copFunction(2, 0x49e012);
    uVar4 = getCopReg(2, 0x4800);
    uVar5 = getCopReg(2, 0x5000);
    uVar3 = getCopReg(2, 0x5800);
    setCopReg(2, 0x4800, (u_int)uVar1);
    setCopReg(2, 0x5000, (u_int)(u_short)segMatrix->rotScale[5]);
    setCopReg(2, 0x5800, (u_int)(u_short)segMatrix->rotScale[8]);
    segMatrix->rotScale[6] = (short)uVar6;
    segMatrix->rotScale[1] = (short)uVar4;
    copFunction(2, 0x49e012);
    segMatrix->rotScale[4] = (short)uVar5;
    segMatrix->rotScale[7] = (short)uVar3;
    uVar4 = getCopReg(2, 0x4800);
    uVar5 = getCopReg(2, 0x5000);
    uVar3 = getCopReg(2, 0x5800);
    segMatrix->rotScale[2] = (short)uVar4;
    segMatrix->rotScale[5] = (short)uVar5;
    segMatrix->rotScale[8] = (short)uVar3;
  }
  return uVar2;
}

void G2Anim_SetControllerCallbackData(_G2Anim_Type *anim)

{
  u_short uVar1;
  short sVar2;
  short sVar3;
  _G2AnimSection_Type *p_Var4;
  _G2AnimController_Type *controller;

  if (anim->controllerList != 0)
  {
    sVar2 = G2Timer_GetFrameTime();
    controller = _controllerPool.blockPool + anim->controllerList;
    if (_controllerPool.blockPool < controller)
    {
      do
      {
        uVar1 = controller->flags;
        if ((uVar1 & 0x4000) != 0)
        {
          sVar3 = controller->elapsedTime + sVar2;
          if (controller->elapsedTime < controller->duration)
          {
            controller->elapsedTime = sVar3;
            if (controller->duration < sVar3)
            {
              controller->elapsedTime = controller->duration;
            }
          }
          else
          {
            if ((uVar1 & 0x8000) == 0)
            {
              if ((uVar1 & 0x2000) == 0)
              {
                controller->flags = uVar1 | 0x2000;
                p_Var4 = G2Anim_GetSectionWithSeg(anim, (u_int)controller->segNumber);
                if ((p_Var4 != (_G2AnimSection_Type *)0x0) && (p_Var4->callback != (_func_8 *)0x0))
                {
                  (*p_Var4->callback)(anim, (u_int)p_Var4->sectionID, 4, (u_int)controller->type,
                                      (u_int)controller->segNumber, controller->callbackData);
                }
              }
            }
            else
            {
              controller->flags = uVar1 & 0x7fff;
              _G2AnimController_GetVector((u_int)controller->segNumber, (u_int)controller->type, &anim->controllerList);
              _G2AnimController_InsertIntoList(controller, &anim->disabledControllerList);
            }
          }
        }
        controller = _controllerPool.blockPool + controller->next;
      } while (_controllerPool.blockPool < controller);
    }
  }
  return;
}

void _G2Anim_CopyVectorWithOrder(_G2SVector3_Type *sourceVector, _G2EulerAngles_Type *destVector, int order)

{
  short sVar1;

  if (order == 1)
  {
    destVector->x = sourceVector->z;
    destVector->y = sourceVector->y;
    sVar1 = sourceVector->x;
    destVector->order = (short)order;
  }
  else
  {
    if (order != 0x15)
    {
      return;
    }
    destVector->x = sourceVector->x;
    destVector->y = sourceVector->y;
    sVar1 = sourceVector->z;
    destVector->order = (short)order;
  }
  destVector->z = sVar1;
  return;
}

void _G2AnimSection_ApplyControllersToStoredFrame(_G2AnimSection_Type *section)

{
  _G2Anim_Type *p_Var1;
  _G2Matrix_Type *p_Var2;
  _G2AnimController_Type *controller;
  _G2AnimSegValue_Type *segValue;
  u_int uVar3;
  u_char *puVar4;
  _Segment *p_Var5;
  u_int uVar6;
  _G2Matrix_Type _Stack152;
  u_char local_78;
  u_char local_74;
  u_char local_70;
  u_char local_6c;
  u_char local_68;
  long local_64;
  long local_60;
  long local_5c;
  u_char auStack88[8];
  u_int local_38;
  u_short local_34;
  u_char local_30;
  u_char local_2c;

  p_Var1 = G2AnimSection_SetUnpaused(section);
  if (p_Var1->controllerList != 0)
  {
    uVar3 = (u_int)section->firstSeg;
    controller = _controllerPool.blockPool + p_Var1->controllerList;
    segValue = &_segValues + uVar3;
    uVar6 = uVar3 + section->segCount;
    p_Var5 = p_Var1->modelData->segmentList;
    if (uVar3 < uVar6)
    {
      puVar4 = (u_char *)((int)&(&_segValues)[uVar3].rotQuat + 4);
      do
      {
        if ((u_int)controller->segNumber == uVar3)
        {
          _G2Anim_BuildSegLocalRotMatrix(segValue, &_Stack152);
          if (p_Var1->segMatrices == (_G2Matrix_Type *)0x0)
          {
            MATH3D_SetUnityMatrix((MATRIX *)&local_78);
          }
          else
          {
            p_Var2 = p_Var1->segMatrices + p_Var5->parent;
            local_78 = *(u_char *)p_Var2->rotScale;
            local_74 = *(u_char *)(p_Var2->rotScale + 2);
            local_70 = *(u_char *)(p_Var2->rotScale + 4);
            local_6c = *(u_char *)(p_Var2->rotScale + 6);
            local_68 = *(u_char *)(p_Var2->rotScale + 8);
            local_64 = (p_Var2->trans).x;
            local_60 = (p_Var2->trans).y;
            local_5c = (p_Var2->trans).z;
          }
          while ((u_int)controller->segNumber == uVar3)
          {
            if ((uVar3 != 0) || ((controller->type & 2) != 0))
            {
              if ((controller->type & 0x38) == 8)
              {
                _G2AnimController_Destroy(controller, segValue, &_Stack152, (_G2Matrix_Type *)&local_78);
                if ((controller->type & 2) == 0)
                {
                  TransposeMatrix((u_char *)(_G2Matrix_Type *)&local_78, auStack88);
                  MulMatrix2(auStack88, (u_int *)&_Stack152);
                }
                if (*(u_short *)((int)puVar4 + 0x12) == 0)
                {
                  G2EulerAngles_FromMatrix((_G2EulerAngles_Type *)&local_38, &_Stack152, 0);
                  *(u_short *)puVar4 = local_34 & 0xfff;
                  *(u_int *)&segValue->rotQuat = local_38 & 0xfff0fff;
                }
                else
                {
                  G2EulerAngles_ToMatrix_S((undefined2 *)&local_30, (short *)&_Stack152);
                  *(u_char *)&segValue->rotQuat = local_30;
                  *puVar4 = local_2c;
                }
              }
              else
              {
                _G2AnimController_Destroy(controller, segValue, &_Stack152, (_G2Matrix_Type *)&local_78);
              }
            }
            controller = _controllerPool.blockPool + controller->next;
          }
        }
        p_Var5 = p_Var5 + 1;
        puVar4 = puVar4 + 6;
        uVar3 = uVar3 + 1;
        segValue = segValue + 1;
      } while ((int)uVar3 < (int)uVar6);
    }
  }
  return;
}

u_long _G2AnimController_ApplyWorldToParentMatrix(_G2AnimController_Type *controller, _G2Matrix_Type *parentMatrix)

{
  byte bVar1;
  _G2Matrix_Type _Stack64;
  _G2SVector3_Type local_20;
  int local_18;
  int local_14;
  int local_10;

  bVar1 = controller->type;
  if (bVar1 == 0x20)
  {
    G2Anim_SetController_Vector(controller, &local_20);
    (parentMatrix->trans).x = (int)local_20.x;
    (parentMatrix->trans).y = (int)local_20.y;
    (parentMatrix->trans).z = (int)local_20.z;
  }
  else
  {
    if (bVar1 < 0x21)
    {
      if (bVar1 == 8)
      {
        FX_GetMatrix(controller, parentMatrix);
      }
    }
    else
    {
      if (bVar1 == 0x54)
      {
        G2Anim_SetController_Vector(controller, &local_20);
        local_18 = (int)local_20.x;
        local_14 = (int)local_20.y;
        local_10 = (int)local_20.z;
        ScaleMatrix((int *)parentMatrix, &local_18);
      }
      else
      {
        if (bVar1 < 0x55)
        {
          if (bVar1 == 0x4c)
          {
            FX_GetMatrix(controller, &_Stack64);
            MulMatrix2((u_char *)&_Stack64, (u_int *)parentMatrix);
          }
        }
        else
        {
          if (bVar1 == 100)
          {
            G2Anim_SetController_Vector(controller, &local_20);
            (parentMatrix->trans).x = (parentMatrix->trans).x + (int)local_20.x;
            (parentMatrix->trans).y = (parentMatrix->trans).y + (int)local_20.y;
            (parentMatrix->trans).z = (parentMatrix->trans).z + (int)local_20.z;
          }
        }
      }
    }
  }
  return 7;
}

void FX_GetMatrix(_G2AnimController_Type *controller, _G2Matrix_Type *matrix)

{
  u_short uVar1;
  long ratio;
  _G2Quat_Type _Stack24;

  uVar1 = controller->flags;
  if ((uVar1 & 0x4000) == 0)
  {
    if ((uVar1 & 0xff) == 1)
    {
      RotMatrixZYX((u_short *)controller->data, (u_int *)matrix);
    }
    else
    {
      if ((uVar1 & 0xff) == 0x15)
      {
        RotMatrixY((u_short *)controller->data, (u_int *)matrix);
      }
    }
  }
  else
  {
    if ((uVar1 & 0x2000) == 0)
    {
      ratio = _G2AnimAlphaTable_GetValue(controller->alphaTable,
                                         (int)controller->duration);
      G2Quat_Slerp_VM(ratio, (_G2Quat_Type *)controller->data, (_G2Quat_Type *)(controller->data + 8),
                      &_Stack24, 0);
      G2Quat_ToMatrix_S((short *)&_Stack24, (short *)matrix);
    }
    else
    {
      G2Quat_ToMatrix_S((short *)(controller->data + 8), (short *)matrix);
    }
  }
  return;
}

void G2Anim_SetController_Vector(_G2AnimController_Type *controller, _G2SVector3_Type *vector)

{
  short sVar1;
  u_char uVar2;
  u_char uVar3;
  u_char uVar4;

  sVar1 = *(short *)(controller->data + 4);
  *(u_char *)vector = *(u_char *)controller->data;
  vector->z = sVar1;
  if ((controller->flags & 0x4000) != 0)
  {
    setCopReg(2, 0xc800, (u_int)(u_short)vector->x);
    setCopReg(2, 0xd000, (u_int)(u_short)vector->y);
    setCopReg(2, 0xd800, (u_int)(u_short)vector->z);
    setCopReg(2, 0x4800, (u_int) * (u_short *)(controller->data + 6));
    setCopReg(2, 0x5000, (u_int) * (u_short *)(controller->data + 8));
    setCopReg(2, 0x5800, (u_int) * (u_short *)(controller->data + 10));
    setCopReg(2, 0x4000, (int)controller->elapsedTime);
    copFunction(2, 0x1a8003e);
    uVar2 = getCopReg(2, 0xc800);
    uVar3 = getCopReg(2, 0xd000);
    uVar4 = getCopReg(2, 0xd800);
    vector->x = (short)uVar2;
    vector->y = (short)uVar3;
    vector->z = (short)uVar4;
  }
  return;
}

_G2AnimController_Type *G2Anim_EnableController(_G2Anim_Type *anim, int segNumber, int type)

{
  _G2AnimController_Type *p_Var1;

  p_Var1 = G2Anim_SetInterpController_Quat(segNumber, type, &anim->controllerList);
  if (p_Var1 == (_G2AnimController_Type *)0x0)
  {
    p_Var1 = G2Anim_SetInterpController_Quat(segNumber, type, &anim->disabledControllerList);
  }
  return p_Var1;
}

_G2AnimController_Type *_G2AnimController_GetMatrix(int segNumber, int type)

{
  _G2AnimController_Type *__s;

  __s = (_G2AnimController_Type *)G2PoolMem_Allocate(&_controllerPool);
  memset(__s, 0, 0x24);
  __s->next = 0;
  __s->segNumber = (u_char)segNumber;
  __s->type = (u_char)type;
  __s->flags = 0x15;
  return __s;
}

_G2AnimController_Type *G2Anim_IsControllerActive(_G2AnimController_Type *controller)

{
  u_short uVar1;

  do
  {
    uVar1 = controller->next;
    G2PoolMem_InitPool(&_controllerPool, controller);
    controller = _controllerPool.blockPool + uVar1;
    if (controller <= _controllerPool.blockPool)
    {
      return controller;
    }
  } while (controller->type == '\0');
  return controller;
}

void _G2AnimController_InsertIntoList(_G2AnimController_Type *controller, u_short *listPtr)

{
  _G2AnimController_Type *p_Var1;
  _G2AnimController_Type *p_Var2;

  p_Var2 = _controllerPool.blockPool + *listPtr;
  if (_controllerPool.blockPool < p_Var2)
  {
    p_Var1 = p_Var2;
    while (p_Var2 = p_Var1, p_Var1->segNumber <= controller->segNumber)
    {
      if (((p_Var1->segNumber == controller->segNumber) && (controller->type < p_Var1->type)) ||
          (p_Var2 = _controllerPool.blockPool + p_Var1->next, listPtr = (u_short *)p_Var1,
           p_Var1 = p_Var2, p_Var2 <= _controllerPool.blockPool))
        break;
    }
  }
  ((_G2AnimController_Type *)listPtr)->next =
      (u_short)((int)((int)controller - (int)_controllerPool.blockPool) * 0x38e38e39 >> 2);
  do
  {
    p_Var1 = controller;
    controller = _controllerPool.blockPool + p_Var1->next;
  } while (_controllerPool.blockPool < _controllerPool.blockPool + p_Var1->next);
  p_Var1->next = (u_short)((int)((int)p_Var2 - (int)_controllerPool.blockPool) * 0x38e38e39 >> 2);
  return;
}

void G2EmulationSetInterpController_Vector(_G2AnimController_Type *controller, _G2Anim_Type *anim, _G2Quat_Type *quat)

{
  u_char uVar1;
  u_short uVar2;
  long ratio;
  u_char uVar3;
  _G2EulerAngles_Type _Stack24;

  uVar2 = controller->flags;
  if ((uVar2 & 0x4000) == 0)
  {
    uVar1 = controller->type;
    if (uVar1 == '\b')
    {
      G2EulerAngles_ToMatrix_S((undefined2 *)quat, (short *)(anim->segMatrices + controller->segNumber));
    }
    else
    {
      if (uVar1 == 'L')
      {
        *(u_char *)quat = 0;
        *(u_char *)&quat->z = 0x10000000;
      }
      else
      {
        if (uVar1 == '\x0e')
        {
          _G2Anim_CopyVectorWithOrder((_G2SVector3_Type *)controller->data, &_Stack24, (u_int)uVar2 & 0xff);
        }
        else
        {
          G2Anim_GetSegChannelValue(anim, (u_int)controller->segNumber, (u_short *)&_Stack24, 7);
          _Stack24.order = 0;
        }
        G2Quat_ToEuler((int)quat, (short *)&_Stack24);
      }
    }
  }
  else
  {
    if ((uVar2 & 0x2000) == 0)
    {
      ratio = _G2AnimAlphaTable_GetValue(controller->alphaTable,
                                         (int)controller->duration);
      G2Quat_Slerp_VM(ratio, (_G2Quat_Type *)controller->data, (_G2Quat_Type *)(controller->data + 8),
                      quat, 0);
    }
    else
    {
      uVar3 = *(u_char *)(controller->data + 0xc);
      *(u_char *)quat = *(u_char *)(controller->data + 8);
      *(u_char *)&quat->z = uVar3;
    }
  }
  return;
}

void G2Anim_AttachControllerToSeg(_G2AnimController_Type *controller, _G2Anim_Type *anim, _G2Quat_Type *quat)

{
  short sVar1;
  _G2Matrix_Type *p_Var2;
  _G2Matrix_Type _Stack48;

  p_Var2 = anim->segMatrices;
  sVar1 = anim->modelData->segmentList[controller->segNumber].parent;
  _G2Anim_BuildSegLocalRotMatrix(&_segValues + controller->segNumber, &_Stack48);
  MulMatrix2((u_char *)(p_Var2 + sVar1), (u_int *)&_Stack48);
  G2EulerAngles_ToMatrix_S((undefined2 *)quat, (short *)&_Stack48);
  return;
}

_G2AnimController_Type *G2Anim_SetInterpController_Quat(int segNumber, int type, u_short *listPtr)

{
  u_short uVar1;
  _G2AnimController_Type *p_Var2;
  _G2AnimController_Type *p_Var3;

  uVar1 = *listPtr;
  while ((p_Var3 = _controllerPool.blockPool + uVar1, _controllerPool.blockPool < p_Var3 &&
                                                          (((u_int)p_Var3->segNumber != segNumber || ((u_int)p_Var3->type != type)))))
  {
    uVar1 = p_Var3->next;
  }
  p_Var2 = (_G2AnimController_Type *)0x0;
  if (p_Var3 != _controllerPool.blockPool)
  {
    p_Var2 = p_Var3;
  }
  return p_Var2;
}

_G2AnimController_Type *_G2AnimController_Create(int segNumber, int type, u_short **listPtrPtr)

{
  _G2AnimController_Type *p_Var1;

  p_Var1 = _controllerPool.blockPool + **listPtrPtr;
  if (_controllerPool.blockPool < p_Var1)
  {
    do
    {
      if (((u_int)p_Var1->segNumber == segNumber) && ((u_int)p_Var1->type == type))
        break;
      *(_G2AnimController_Type **)listPtrPtr = p_Var1;
      p_Var1 = _controllerPool.blockPool + p_Var1->next;
    } while (_controllerPool.blockPool < p_Var1);
  }
  if (p_Var1 == _controllerPool.blockPool)
  {
    *listPtrPtr = (u_short *)0x0;
    return (_G2AnimController_Type *)0x0;
  }
  return p_Var1;
}

_G2AnimController_Type *_G2AnimController_GetVector(int segNumber, int type, u_short *listPtr)

{
  u_short uVar1;
  _G2AnimController_Type *p_Var2;
  _G2AnimController_Type *p_Var3;
  _G2AnimController_Type *p_Var4;

  p_Var3 = _controllerPool.blockPool + *listPtr;
  if (_controllerPool.blockPool < _controllerPool.blockPool + *listPtr)
  {
    do
    {
      if (((u_int)p_Var3->segNumber == segNumber) && (p_Var4 = p_Var3, (u_int)p_Var3->type == type))
        break;
      p_Var4 = _controllerPool.blockPool + p_Var3->next;
      listPtr = (u_short *)p_Var3;
      p_Var3 = p_Var4;
    } while (_controllerPool.blockPool < p_Var4);
    p_Var3 = p_Var4;
    if (_controllerPool.blockPool < p_Var4)
    {
      do
      {
        p_Var2 = p_Var3;
        p_Var3 = _controllerPool.blockPool;
        uVar1 = p_Var2->next;
        ((_G2AnimController_Type *)listPtr)->next = uVar1;
        p_Var3 = p_Var3 + uVar1;
        if (p_Var3 <= _controllerPool.blockPool)
          break;
      } while (p_Var3->type == '\0');
      p_Var2->next = 0;
      return p_Var4;
    }
  }
  return (_G2AnimController_Type *)0x0;
}
