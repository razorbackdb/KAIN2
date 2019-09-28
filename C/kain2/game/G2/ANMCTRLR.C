#include "THISDUST.H"
#include "ANMCTRLR.H"

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_AttachControllerToSeg(struct _G2Anim_Type *anim /*$s0*/, int segNumber /*$a1*/, int type /*$a2*/)
// line 235, offset 0x80090318
/* begin block 1 */
// Start line: 236
// Start offset: 0x80090318
/* end block 1 */
// End offset: 0x80090318
// End Line: 236

/* begin block 2 */
// Start line: 470
/* end block 2 */
// End Line: 471

void G2Anim_AttachControllerToSeg(_G2Anim_Type *anim, int segNumber, int type)

{
  _G2AnimController_Type *controller;

  controller = _G2AnimController_Create(segNumber, type);
  _G2AnimController_InsertIntoList(controller, &anim->controllerList);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_DetachControllerFromSeg(struct _G2Anim_Type *anim /*$s1*/, int segNumber /*$s2*/, int type /*$s3*/)
// line 260, offset 0x80090350
/* begin block 1 */
// Start line: 261
// Start offset: 0x80090350
// Variables:
// 		struct _G2AnimController_Type *controller; // $v0
// 		unsigned short *controllerNextPtr; // stack offset -32
/* end block 1 */
// End offset: 0x800903FC
// End Line: 291

/* begin block 2 */
// Start line: 530
/* end block 2 */
// End Line: 531

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void G2Anim_DetachControllerFromSeg(_G2Anim_Type *anim, int segNumber, int type)

{
  _G2AnimController_Type *controller;
  ushort *local_20[2];

  local_20[0] = &anim->controllerList;
  controller = _G2AnimControllerST_FindPtrInList(segNumber, type, local_20);
  if (controller == (_G2AnimController_Type *)0x0)
  {
    local_20[0] = &anim->disabledControllerList;
    controller = _G2AnimControllerST_FindPtrInList(segNumber, type, local_20);
    if (controller == (_G2AnimController_Type *)0x0)
    {
      return;
    }
  }
  controller = _G2AnimController_Destroy(controller);
  *local_20[0] = (ushort)((int)((int)controller - _CHAR____800d5168) * 0x38e38e39 >> 2);
  /* WARNING: Read-only address (ram,0x800d5168) is written */
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_EnableController(struct _G2Anim_Type *anim /*$s2*/, int segNumber /*$s1*/, int type /*$a2*/)
// line 342, offset 0x80090418
/* begin block 1 */
// Start line: 343
// Start offset: 0x80090418
// Variables:
// 		struct _G2AnimController_Type *controller; // $s0
// 		struct _G2Matrix_Type *segMatrix; // $v1
/* end block 1 */
// End offset: 0x800904DC
// End Line: 378

/* begin block 2 */
// Start line: 684
/* end block 2 */
// End Line: 685

void G2Anim_EnableController(_G2Anim_Type *anim, int segNumber, int type)

{
  _G2AnimController_Type *controller;
  _G2Matrix_Type *p_Var1;

  controller = _G2AnimControllerST_RemoveFromList(segNumber, type, &anim->disabledControllerList);
  if (controller != (_G2AnimController_Type *)0x0)
  {
    controller->duration = 0;
    controller->elapsedTime = 0;
    controller->flags = (ushort) * (byte *)&controller->flags;
    if (controller->type == '\b')
    {
      G2EulerAngles_ToMatrix_S((undefined2 *)(controller->data + 8), (short *)(anim->segMatrices + segNumber));
    }
    else
    {
      if (controller->type != ' ')
      {
        /* WARNING: Subroutine does not return */
        memset(controller->data, 0, 0x10);
      }
      p_Var1 = anim->segMatrices + segNumber;
      *(undefined2 *)controller->data = *(undefined2 *)&(p_Var1->trans).x;
      *(undefined2 *)(controller->data + 2) = *(undefined2 *)&(p_Var1->trans).y;
      *(undefined2 *)(controller->data + 4) = *(undefined2 *)&(p_Var1->trans).z;
    }
    _G2AnimController_InsertIntoList(controller, &anim->controllerList);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_DisableController(struct _G2Anim_Type *anim /*$s0*/, int segNumber /*$a1*/, int type /*$a2*/)
// line 397, offset 0x800904f4
/* begin block 1 */
// Start line: 398
// Start offset: 0x800904F4
// Variables:
// 		struct _G2AnimController_Type *controller; // $v0
/* end block 1 */
// End offset: 0x80090524
// End Line: 411

/* begin block 2 */
// Start line: 794
/* end block 2 */
// End Line: 795

void G2Anim_DisableController(_G2Anim_Type *anim, int segNumber, int type)

{
  _G2AnimController_Type *controller;

  controller = _G2AnimControllerST_RemoveFromList(segNumber, type, &anim->controllerList);
  if (controller != (_G2AnimController_Type *)0x0)
  {
    _G2AnimController_InsertIntoList(controller, &anim->disabledControllerList);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_InterpDisableController(struct _G2Anim_Type *anim /*$s2*/, int segNumber /*$s4*/, int type /*$s3*/, short duration /*$s5*/)
// line 430, offset 0x80090534
/* begin block 1 */
// Start line: 431
// Start offset: 0x80090534
// Variables:
// 		struct _G2AnimController_Type *controller; // $s1
// 		struct _G2SVector3_Type zeroVector; // stack offset -48
// 		struct _G2Quat_Type targetQuat; // stack offset -40
/* end block 1 */
// End offset: 0x80090630
// End Line: 475

/* begin block 2 */
// Start line: 860
/* end block 2 */
// End Line: 861

void G2Anim_InterpDisableController(_G2Anim_Type *anim, int segNumber, int type, short duration)

{
  undefined auStack48[16];

  /* WARNING: Subroutine does not return */
  memset(auStack48, 0, 6);
}

// decompiled code
// original method signature:
// enum _G2Bool_Enum /*$ra*/ G2Anim_IsControllerActive(struct _G2Anim_Type *anim /*$a0*/, int segNumber /*$a1*/, int type /*$a2*/)
// line 496, offset 0x80090654
/* begin block 1 */
// Start line: 497
// Start offset: 0x80090654
// Variables:
// 		struct _G2AnimController_Type *controller; // $v0
/* end block 1 */
// End offset: 0x80090690
// End Line: 513

/* begin block 2 */
// Start line: 992
/* end block 2 */
// End Line: 993

_G2Bool_Enum G2Anim_IsControllerActive(_G2Anim_Type *anim, int segNumber, int type)

{
  _G2AnimController_Type *p_Var1;
  _G2Bool_Enum _Var2;

  p_Var1 = _G2AnimControllerST_FindInList(segNumber, type, &anim->controllerList);
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

// decompiled code
// original method signature:
// enum _G2Bool_Enum /*$ra*/ G2Anim_IsControllerInterpolating(struct _G2Anim_Type *anim /*$a0*/, int segNumber /*$a1*/, int type /*$a2*/)
// line 519, offset 0x800906a0
/* begin block 1 */
// Start line: 520
// Start offset: 0x800906A0
// Variables:
// 		struct _G2AnimController_Type *controller; // $v0
/* end block 1 */
// End offset: 0x800906E4
// End Line: 540

/* begin block 2 */
// Start line: 987
/* end block 2 */
// End Line: 988

_G2Bool_Enum G2Anim_IsControllerInterpolating(_G2Anim_Type *anim, int segNumber, int type)

{
  _G2AnimController_Type *p_Var1;
  _G2Bool_Enum _Var2;

  p_Var1 = _G2AnimControllerST_FindInList(segNumber, type, &anim->controllerList);
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

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_GetControllerCurrentInterpVector(struct _G2Anim_Type *anim /*$s1*/, int segNumber /*$a1*/, int type /*$a2*/, struct _G2SVector3_Type *vector /*$s0*/)
// line 558, offset 0x800906f4
/* begin block 1 */
// Start line: 559
// Start offset: 0x800906F4
// Variables:
// 		struct _G2AnimController_Type *controller; // $v1
// 		struct _G2SVector3_Type *base; // $a0
// 		struct _G2SVector3_Type *offset; // $a1
// 		struct _G2Matrix_Type *segMatrix; // $v1

/* begin block 1.1 */
// Start line: 579
// Start offset: 0x80090738
// Variables:
// 		struct _G2SVector3_Type *source; // $a0
// 		struct _G2SVector3_Type *dest; // $s0

/* begin block 1.1.1 */
// Start line: 579
// Start offset: 0x80090738
// Variables:
// 		unsigned short z; // $v1
// 		unsigned long xy; // $v0
/* end block 1.1.1 */
// End offset: 0x80090738
// End Line: 579
/* end block 1.1 */
// End offset: 0x80090738
// End Line: 579

/* begin block 1.2 */
// Start line: 580
// Start offset: 0x8009074C
// Variables:
// 		struct _G2SVector3_Type *dest; // $s0
// 		struct _G2SVector3_Type *base; // $a0
// 		struct _G2SVector3_Type *offset; // $a1
// 		long alpha; // $v0
/* end block 1.2 */
// End offset: 0x8009074C
// End Line: 580
/* end block 1 */
// End offset: 0x80090840
// End Line: 603

/* begin block 2 */
// Start line: 1116
/* end block 2 */
// End Line: 1117

void G2Anim_GetControllerCurrentInterpVector(_G2Anim_Type *anim, int segNumber, int type, _G2SVector3_Type *vector)

{
  uchar uVar1;
  short sVar2;
  _G2AnimController_Type *p_Var3;
  _G2Matrix_Type *p_Var4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;

  p_Var3 = _G2Anim_FindController(anim, segNumber, type);
  if (p_Var3->duration == 0)
  {
    uVar1 = p_Var3->type;
    if (uVar1 == '\x12')
    {
      G2Anim_SegmentHasActiveChannels(anim, (uint)p_Var3->segNumber, (ushort)vector);
    }
    else
    {
      if (uVar1 == '\"')
      {
        G2Anim_SegmentHasActiveChannels(anim, (uint)p_Var3->segNumber, (ushort)vector);
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
      setCopReg(2, 0xc800, (uint) * (ushort *)p_Var3->data);
      setCopReg(2, 0xd000, (uint) * (ushort *)(p_Var3->data + 2));
      setCopReg(2, 0xd800, (uint) * (ushort *)(p_Var3->data + 4));
      setCopReg(2, 0x4800, (uint) * (ushort *)(p_Var3->data + 6));
      setCopReg(2, 0x5000, (uint) * (ushort *)(p_Var3->data + 8));
      setCopReg(2, 0x5800, (uint) * (ushort *)(p_Var3->data + 10));
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
      *(undefined4 *)vector = *(undefined4 *)p_Var3->data;
      vector->z = sVar2;
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_SetControllerCallbackData(struct _G2Anim_Type *anim /*$a0*/, int segNumber /*$a1*/, int type /*$a2*/, void *callbackData /*$s0*/)
// line 629, offset 0x80090854
/* begin block 1 */
// Start line: 630
// Start offset: 0x80090854
/* end block 1 */
// End offset: 0x80090854
// End Line: 630

/* begin block 2 */
// Start line: 1258
/* end block 2 */
// End Line: 1259

void G2Anim_SetControllerCallbackData(_G2Anim_Type *anim, int segNumber, int type, void *callbackData)

{
  _G2AnimController_Type *p_Var1;

  p_Var1 = _G2Anim_FindController(anim, segNumber, type);
  p_Var1->callbackData = callbackData;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_SetControllerAngleOrder(struct _G2Anim_Type *anim /*$a0*/, int segNumber /*$a1*/, int type /*$a2*/, int order /*$s0*/)
// line 648, offset 0x8009087c
/* begin block 1 */
// Start line: 649
// Start offset: 0x8009087C
// Variables:
// 		struct _G2AnimController_Type *controller; // $v0
/* end block 1 */
// End offset: 0x8009087C
// End Line: 649

/* begin block 2 */
// Start line: 1205
/* end block 2 */
// End Line: 1206

void G2Anim_SetControllerAngleOrder(_G2Anim_Type *anim, int segNumber, int type, int order)

{
  _G2AnimController_Type *p_Var1;

  p_Var1 = _G2Anim_FindController(anim, segNumber, type);
  p_Var1->flags = p_Var1->flags & 0xff00 | (ushort)order;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_SetController_Vector(struct _G2Anim_Type *anim /*$a0*/, int segNumber /*$a1*/, int type /*$a2*/, struct _G2SVector3_Type *vector /*$s0*/)
// line 668, offset 0x800908b4
/* begin block 1 */
// Start line: 669
// Start offset: 0x800908B4
// Variables:
// 		struct _G2AnimController_Type *controller; // $v0
/* end block 1 */
// End offset: 0x800908B4
// End Line: 669

/* begin block 2 */
// Start line: 1245
/* end block 2 */
// End Line: 1246

void G2Anim_SetController_Vector(_G2Anim_Type *anim, int segNumber, int type, _G2SVector3_Type *vector)

{
  short sVar1;
  _G2AnimController_Type *p_Var2;

  p_Var2 = _G2Anim_FindController(anim, segNumber, type);
  sVar1 = vector->z;
  *(undefined4 *)p_Var2->data = *(undefined4 *)vector;
  *(short *)(p_Var2->data + 4) = sVar1;
  p_Var2->flags = (ushort) * (byte *)&p_Var2->flags;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_SetInterpController_Vector(struct _G2Anim_Type *anim /*$s2*/, int segNumber /*$s3*/, int type /*$s4*/, struct _G2SVector3_Type *vector /*$s6*/, int duration /*stack 16*/)
// line 711, offset 0x800908fc
/* begin block 1 */
// Start line: 712
// Start offset: 0x800908FC
// Variables:
// 		struct _G2AnimController_Type *controller; // $s1
// 		struct _G2EulerAngles_Type eulerVector; // stack offset -48
// 		struct _G2SVector3_Type *base; // $s0
// 		struct _G2SVector3_Type *offset; // $a1
// 		struct _G2Quat_Type quat; // stack offset -40
/* end block 1 */
// End offset: 0x80090A38
// End Line: 753

/* begin block 2 */
// Start line: 1422
/* end block 2 */
// End Line: 1423

void G2Anim_SetInterpController_Vector(_G2Anim_Type *anim, int segNumber, int type, _G2SVector3_Type *vector, int duration)

{
  _G2AnimController_Type *p_Var1;
  short sVar2;
  int iVar3;
  _G2EulerAngles_Type _Stack48;
  _G2Quat_Type _Stack40;

  p_Var1 = _G2Anim_FindController(anim, segNumber, type);
  sVar2 = (short)duration;
  if ((p_Var1->type & 0x38) == 8)
  {
    _G2Anim_CopyVectorWithOrder(vector, &_Stack48, (uint) * (byte *)&p_Var1->flags);
    G2Quat_FromEuler_S((int)&_Stack40, (short *)&_Stack48);
    G2Anim_SetInterpController_Quat(anim, segNumber, type, &_Stack40, (int)sVar2);
  }
  else
  {
    G2Anim_GetControllerCurrentInterpVector(anim, segNumber, type, (_G2SVector3_Type *)p_Var1->data);
    iVar3 = (int)sVar2 + 1;
    *(short *)(p_Var1->data + 6) =
        (short)((((int)vector->x - (int)*(short *)p_Var1->data) * 0x1000) / iVar3);
    *(short *)(p_Var1->data + 8) =
        (short)((((int)vector->y - (int)*(short *)(p_Var1->data + 2)) * 0x1000) / iVar3);
    *(short *)(p_Var1->data + 10) =
        (short)((((int)vector->z - (int)*(short *)(p_Var1->data + 4)) * 0x1000) / iVar3);
    p_Var1->duration = sVar2;
    p_Var1->elapsedTime = 0;
    p_Var1->flags = (ushort) * (byte *)&p_Var1->flags | 0x4000;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_SetInterpController_Quat(struct _G2Anim_Type *anim /*$s1*/, int segNumber /*$a1*/, int type /*$a2*/, struct _G2Quat_Type *quat /*$s2*/, int duration /*stack 16*/)
// line 780, offset 0x80090a60
/* begin block 1 */
// Start line: 781
// Start offset: 0x80090A60
// Variables:
// 		struct _G2AnimController_Type *controller; // $s0

/* begin block 1.1 */
// Start line: 781
// Start offset: 0x80090A60
// Variables:
// 		struct _G2Quat_Type *source; // $s2

/* begin block 1.1.1 */
// Start line: 781
// Start offset: 0x80090A60
// Variables:
// 		unsigned long zw; // $a0
// 		unsigned long xy; // $v1
/* end block 1.1.1 */
// End offset: 0x80090A60
// End Line: 781
/* end block 1.1 */
// End offset: 0x80090A60
// End Line: 781
/* end block 1 */
// End offset: 0x80090A60
// End Line: 781

/* begin block 2 */
// Start line: 1560
/* end block 2 */
// End Line: 1561

void G2Anim_SetInterpController_Quat(_G2Anim_Type *anim, int segNumber, int type, _G2Quat_Type *quat, int duration)

{
  byte bVar1;
  _G2AnimController_Type *controller;
  undefined4 uVar2;
  undefined4 uVar3;

  controller = _G2Anim_FindController(anim, segNumber, type);
  _G2AnimController_GetCurrentInterpQuat(controller, anim, (_G2Quat_Type *)controller->data);
  uVar2 = *(undefined4 *)quat;
  uVar3 = *(undefined4 *)&quat->z;
  bVar1 = *(byte *)&controller->flags;
  controller->elapsedTime = 0;
  *(undefined4 *)(controller->data + 8) = uVar2;
  *(undefined4 *)(controller->data + 0xc) = uVar3;
  controller->flags = (ushort)bVar1 | 0x4000;
  controller->duration = (short)duration;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ _G2Anim_ApplyControllersToStoredFrame(struct _G2Anim_Type *anim /*$s2*/)
// line 810, offset 0x80090adc
/* begin block 1 */
// Start line: 811
// Start offset: 0x80090ADC
// Variables:
// 		int i; // $s0
/* end block 1 */
// End offset: 0x80090B24
// End Line: 820

/* begin block 2 */
// Start line: 1487
/* end block 2 */
// End Line: 1488

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
    } while (iVar1 < (int)(uint)anim->sectionCount);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ _G2Anim_BuildTransformsWithControllers(struct _G2Anim_Type *anim /*$s6*/)
// line 824, offset 0x80090b3c
/* begin block 1 */
// Start line: 825
// Start offset: 0x80090B3C
// Variables:
// 		struct _Segment *segment; // $a1
// 		struct _G2AnimController_Type *controller; // $s0
// 		struct _G2Matrix_Type *segMatrix; // $s5
// 		struct _G2Matrix_Type *parentMatrix; // $a1
// 		enum _G2Bool_Enum bRootTransUpdated; // $a3
// 		int segIndex; // $s1
// 		int segCount; // $s7
// 		unsigned long disabledBits[3]; // stack offset -56
// 		unsigned long disabledMask; // $s3
// 		unsigned long parentMask; // $v1
// 		unsigned long parentIndex; // $v0
/* end block 1 */
// End offset: 0x80090CE4
// End Line: 910

/* begin block 2 */
// Start line: 1516
/* end block 2 */
// End Line: 1517

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _G2Anim_BuildTransformsWithControllers(_G2Anim_Type *anim)

{
  byte bVar1;
  int iVar2;
  _G2Bool_Enum bRootTransUpdated;
  _G2AnimController_Type *controller;
  uint segIndex;
  uint *puVar3;
  uint uVar4;
  ushort *puVar5;
  _G2Matrix_Type *segMatrix;
  int iVar6;
  ulong local_38[4];

  uVar4 = 1;
  segIndex = 0;
  segMatrix = anim->segMatrices;
  local_38[0] = anim->disabledBits[0];
  local_38[1] = anim->disabledBits[1];
  bRootTransUpdated = (_G2Bool_Enum)((anim->section[0].flags & 0x88) == 0x80);
  local_38[2] = anim->disabledBits[2];
  iVar6 = anim->modelData->numSegments;
  controller = (_G2AnimController_Type *)(_CHAR____800d5168 + (uint)anim->controllerList * 0x24);
  if (0 < iVar6)
  {
    puVar5 = (ushort *)&anim->modelData->segmentList->parent;
    puVar3 = local_38;
    do
    {
      iVar2 = (uint)*puVar5 << 0x10;
      if ((iVar2 >> 0x10 != -1) && ((local_38[iVar2 >> 0x15] & 1 << (*puVar5 & 0x1f)) != 0))
      {
        *puVar3 = *puVar3 | uVar4;
      }
      if ((*puVar3 & uVar4) == 0)
      {
        if ((uint)controller->segNumber == segIndex)
        {
          _G2Anim_BuildSegTransformWithControllers(segMatrix, anim->segMatrices + (short)*puVar5, controller, bRootTransUpdated,
                                                   segIndex);
          bVar1 = controller->segNumber;
          while ((uint)bVar1 == segIndex)
          {
            controller = (_G2AnimController_Type *)(_CHAR____800d5168 + (uint)controller->next * 0x24);
            bVar1 = controller->segNumber;
          }
        }
        else
        {
          _G2Anim_BuildSegTransformNoControllers(segMatrix, anim->segMatrices + (short)*puVar5, bRootTransUpdated, segIndex);
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
  _G2Anim_UpdateControllers(anim);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ _G2Anim_BuildSegTransformWithControllers(struct _G2Matrix_Type *segMatrix /*$s2*/, struct _G2Matrix_Type *parentMatrix /*$s4*/, struct _G2AnimController_Type *controller /*$s0*/, enum _G2Bool_Enum bRootTransUpdated /*$s6*/, int segIndex /*stack 16*/)
// line 919, offset 0x80090d1c
/* begin block 1 */
// Start line: 920
// Start offset: 0x80090D1C
// Variables:
// 		struct _G2AnimSegValue_Type *segValue; // $s1
// 		struct _G2LVector3_Type scale; // stack offset -48
// 		unsigned long flags; // $s3

/* begin block 1.1 */
// Start line: 977
// Start offset: 0x80090F20
// Variables:
// 		struct _G2SVector3_Type *svector; // $v0
// 		struct _G2LVector3_Type *lvector; // $v1
/* end block 1.1 */
// End offset: 0x80090F20
// End Line: 977
/* end block 1 */
// End offset: 0x80090FC4
// End Line: 1004

/* begin block 2 */
// Start line: 1885
/* end block 2 */
// End Line: 1886

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _G2Anim_BuildSegTransformWithControllers(_G2Matrix_Type *segMatrix, _G2Matrix_Type *parentMatrix,
                                              _G2AnimController_Type *controller, _G2Bool_Enum bRootTransUpdated, int segIndex)

{
  byte bVar1;
  ushort uVar2;
  long lVar3;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar4;
  ulong uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  int local_30;
  int local_2c;
  int local_28;

  iVar4 = segIndex * 0x18;
  _G2Anim_BuildSegLocalRotMatrix((_G2AnimSegValue_Type *)(&_segValues + iVar4), segMatrix);
  bVar1 = controller->segNumber;
  uVar10 = 7;
  while ((uint)bVar1 == segIndex)
  {
    /* WARNING: Read-only address (ram,0x800d5168) is written */
    uVar5 = _G2AnimController_ApplyToSegValue(controller, (_G2AnimSegValue_Type *)(&_segValues + iVar4), segMatrix,
                                              parentMatrix);
    controller = (_G2AnimController_Type *)(_CHAR____800d5168 + (uint)controller->next * 0x24);
    bVar1 = controller->segNumber;
    uVar10 = uVar10 & uVar5;
  }
  /* WARNING: Read-only address (ram,0x800d5168) is written */
  setCopControlWord(2, 0, *(undefined4 *)parentMatrix->rotScale);
  setCopControlWord(2, 0x800, *(undefined4 *)(parentMatrix->rotScale + 2));
  setCopControlWord(2, 0x1000, *(undefined4 *)(parentMatrix->rotScale + 4));
  setCopControlWord(2, 0x1800, *(undefined4 *)(parentMatrix->rotScale + 6));
  setCopControlWord(2, 0x2000, *(undefined4 *)(parentMatrix->rotScale + 8));
  local_30 = (int)(short)*(ushort *)(&CHAR____800d49e4 + iVar4);
  local_2c = (int)(short)*(ushort *)(&CHAR____800d49e6 + iVar4);
  local_28 = (int)(short)*(ushort *)(&CHAR____800d49e8 + iVar4);
  if ((ushort)(*(ushort *)(&CHAR____800d49e4 + iVar4) | *(ushort *)(&CHAR____800d49e6 + iVar4) |
               *(ushort *)(&CHAR____800d49e8 + iVar4)) != 0x1000)
  {
    ScaleMatrix((int *)segMatrix, &local_30);
    segMatrix->scaleFlag = 1;
  }
  if ((uVar10 & 1) != 0)
  {
    setCopReg(2, 0x4800, (uint)(ushort)segMatrix->rotScale[0]);
    setCopReg(2, 0x5000, (uint)(ushort)segMatrix->rotScale[3]);
    setCopReg(2, 0x5800, (uint)(ushort)segMatrix->rotScale[6]);
    copFunction(2, 0x49e012);
    uVar2 = segMatrix->rotScale[2];
    uVar7 = getCopReg(2, 0x4800);
    uVar8 = getCopReg(2, 0x5000);
    uVar9 = getCopReg(2, 0x5800);
    setCopReg(2, 0x4800, (uint)(ushort)segMatrix->rotScale[1]);
    setCopReg(2, 0x5000, (uint)(ushort)segMatrix->rotScale[4]);
    setCopReg(2, 0x5800, (uint)(ushort)segMatrix->rotScale[7]);
    segMatrix->rotScale[0] = (short)uVar7;
    segMatrix->rotScale[3] = (short)uVar8;
    copFunction(2, 0x49e012);
    uVar7 = getCopReg(2, 0x4800);
    uVar8 = getCopReg(2, 0x5000);
    uVar6 = getCopReg(2, 0x5800);
    setCopReg(2, 0x4800, (uint)uVar2);
    setCopReg(2, 0x5000, (uint)(ushort)segMatrix->rotScale[5]);
    setCopReg(2, 0x5800, (uint)(ushort)segMatrix->rotScale[8]);
    segMatrix->rotScale[6] = (short)uVar9;
    segMatrix->rotScale[1] = (short)uVar7;
    copFunction(2, 0x49e012);
    segMatrix->rotScale[4] = (short)uVar8;
    segMatrix->rotScale[7] = (short)uVar6;
    uVar7 = getCopReg(2, 0x4800);
    uVar8 = getCopReg(2, 0x5000);
    uVar6 = getCopReg(2, 0x5800);
    segMatrix->rotScale[2] = (short)uVar7;
    segMatrix->rotScale[5] = (short)uVar8;
    segMatrix->rotScale[8] = (short)uVar6;
  }
  if ((uVar10 & 4) == 0)
  {
    (segMatrix->trans).x = (int)*(short *)(&CHAR____800d49ec + iVar4);
    (segMatrix->trans).y = (int)*(short *)(&CHAR____800d49ee + iVar4);
    (segMatrix->trans).z = (int)*(short *)(&CHAR____800d49f0 + iVar4);
  }
  else
  {
    if (segIndex == 0)
    {
      setCopControlWord(2, 0, *(undefined4 *)segMatrix->rotScale);
      setCopControlWord(2, 0x800, *(undefined4 *)(segMatrix->rotScale + 2));
      setCopControlWord(2, 0x1000, *(undefined4 *)(segMatrix->rotScale + 4));
      setCopControlWord(2, 0x1800, *(undefined4 *)(segMatrix->rotScale + 6));
      setCopControlWord(2, 0x2000, *(undefined4 *)(segMatrix->rotScale + 8));
    }
    setCopReg(2, in_zero, *(undefined4 *)(&CHAR____800d49ec + iVar4));
    setCopReg(2, in_at, *(undefined4 *)(&CHAR____800d49f0 + iVar4));
    copFunction(2, 0x486012);
    lVar3 = getCopReg(2, 0x19);
    (segMatrix->trans).x = lVar3;
    lVar3 = getCopReg(2, 0x1a);
    (segMatrix->trans).y = lVar3;
    lVar3 = getCopReg(2, 0x1b);
    (segMatrix->trans).z = lVar3;
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

// decompiled code
// original method signature:
// unsigned long /*$ra*/ _G2AnimController_ApplyToSegValue(struct _G2AnimController_Type *controller /*$a0*/, struct _G2AnimSegValue_Type *segValue /*$s0*/, struct _G2Matrix_Type *segMatrix /*$s3*/, struct _G2Matrix_Type *parentMatrix /*$s2*/)
// line 1014, offset 0x80091028
/* begin block 1 */
// Start line: 1015
// Start offset: 0x80091028
// Variables:
// 		struct _G2Matrix_Type tempMatrix; // stack offset -64
// 		struct _G2SVector3_Type tempVector; // stack offset -32
// 		unsigned long flags; // $s1

/* begin block 1.1 */
// Start line: 1063
// Start offset: 0x800912A4

/* begin block 1.1.1 */
// Start line: 1063
// Start offset: 0x800912A4
// Variables:
// 		unsigned short z; // $v1
// 		unsigned long xy; // $v0
/* end block 1.1.1 */
// End offset: 0x800912A4
// End Line: 1063
/* end block 1.1 */
// End offset: 0x800912A4
// End Line: 1063

/* begin block 1.2 */
// Start line: 1081
// Start offset: 0x80091350

/* begin block 1.2.1 */
// Start line: 1081
// Start offset: 0x80091350
// Variables:
// 		unsigned short z; // $v1
// 		unsigned long xy; // $v0
/* end block 1.2.1 */
// End offset: 0x80091350
// End Line: 1081
/* end block 1.2 */
// End offset: 0x80091350
// End Line: 1081
/* end block 1 */
// End offset: 0x800913B4
// End Line: 1097

/* begin block 2 */
// Start line: 2097
/* end block 2 */
// End Line: 2098

/* WARNING: Could not reconcile some variable overlaps */

ulong _G2AnimController_ApplyToSegValue(_G2AnimController_Type *controller, _G2AnimSegValue_Type *segValue,
                                        _G2Matrix_Type *segMatrix, _G2Matrix_Type *parentMatrix)

{
  ushort uVar1;
  ulong uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_20;
  short local_1c;

  if ((*(uint *)controller & 0xff020000) == 0)
  {
    uVar2 = _G2AnimController_ApplyWorldToParentMatrix(controller, parentMatrix);
    return uVar2;
  }
  uVar2 = 7;
  switch (controller->type)
  {
  case '\x01':
    uVar2 = (**(code **)controller->data)(controller, segValue, parentMatrix, segMatrix,
                                          *(undefined4 *)(controller->data + 4));
    break;
  case '\b':
    uVar2 = 6;
  case '\n':
    _G2AnimController_GetMatrix(controller, segMatrix);
    break;
  case '\x10':
    uVar2 = 5;
  case '\x12':
    _G2AnimController_GetVector(controller, (_G2SVector3_Type *)&local_20);
    *(undefined4 *)&segValue->scale = local_20;
    (segValue->scale).z = local_1c;
    break;
  case '\x16':
    _G2AnimController_GetVector(controller, (_G2SVector3_Type *)&local_20);
    (segValue->scale).x = (segValue->scale).x + (short)local_20;
    (segValue->scale).y = (segValue->scale).y + local_20._2_2_;
    (segValue->scale).z = (segValue->scale).z + local_1c;
    break;
  case ' ':
    uVar2 = 3;
    _G2AnimController_GetVector(controller, (_G2SVector3_Type *)&local_20);
    (segValue->trans).x = (short)local_20 - *(short *)&(parentMatrix->trans).x;
    (segValue->trans).y = local_20._2_2_ - *(short *)&(parentMatrix->trans).y;
    local_1c = local_1c - *(short *)&(parentMatrix->trans).z;
    goto LAB_800913ac;
  case '\"':
    _G2AnimController_GetVector(controller, (_G2SVector3_Type *)&local_20);
    *(undefined4 *)&segValue->trans = local_20;
    (segValue->trans).z = local_1c;
    break;
  case '&':
    _G2AnimController_GetVector(controller, (_G2SVector3_Type *)&local_20);
    (segValue->trans).x = (segValue->trans).x + (short)local_20;
    (segValue->trans).y = (segValue->trans).y + local_20._2_2_;
    local_1c = (segValue->trans).z + local_1c;
  LAB_800913ac:
    (segValue->trans).z = local_1c;
    break;
  case 'L':
    uVar2 = 6;
    setCopControlWord(2, 0, *(undefined4 *)parentMatrix->rotScale);
    setCopControlWord(2, 0x800, *(undefined4 *)(parentMatrix->rotScale + 2));
    setCopControlWord(2, 0x1000, *(undefined4 *)(parentMatrix->rotScale + 4));
    setCopControlWord(2, 0x1800, *(undefined4 *)(parentMatrix->rotScale + 6));
    setCopControlWord(2, 0x2000, *(undefined4 *)(parentMatrix->rotScale + 8));
    setCopReg(2, 0x4800, (uint)(ushort)segMatrix->rotScale[0]);
    setCopReg(2, 0x5000, (uint)(ushort)segMatrix->rotScale[3]);
    setCopReg(2, 0x5800, (uint)(ushort)segMatrix->rotScale[6]);
    copFunction(2, 0x49e012);
    uVar1 = segMatrix->rotScale[2];
    uVar4 = getCopReg(2, 0x4800);
    uVar5 = getCopReg(2, 0x5000);
    uVar6 = getCopReg(2, 0x5800);
    setCopReg(2, 0x4800, (uint)(ushort)segMatrix->rotScale[1]);
    setCopReg(2, 0x5000, (uint)(ushort)segMatrix->rotScale[4]);
    setCopReg(2, 0x5800, (uint)(ushort)segMatrix->rotScale[7]);
    segMatrix->rotScale[0] = (short)uVar4;
    segMatrix->rotScale[3] = (short)uVar5;
    copFunction(2, 0x49e012);
    uVar4 = getCopReg(2, 0x4800);
    uVar5 = getCopReg(2, 0x5000);
    uVar3 = getCopReg(2, 0x5800);
    setCopReg(2, 0x4800, (uint)uVar1);
    setCopReg(2, 0x5000, (uint)(ushort)segMatrix->rotScale[5]);
    setCopReg(2, 0x5800, (uint)(ushort)segMatrix->rotScale[8]);
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
    _G2AnimController_GetMatrix(controller, (_G2Matrix_Type *)&local_40);
    setCopControlWord(2, 0, local_40);
    setCopControlWord(2, 0x800, local_3c);
    setCopControlWord(2, 0x1000, local_38);
    setCopControlWord(2, 0x1800, local_34);
    setCopControlWord(2, 0x2000, local_30);
    setCopReg(2, 0x4800, (uint)(ushort)segMatrix->rotScale[0]);
    setCopReg(2, 0x5000, (uint)(ushort)segMatrix->rotScale[3]);
    setCopReg(2, 0x5800, (uint)(ushort)segMatrix->rotScale[6]);
    copFunction(2, 0x49e012);
    uVar1 = segMatrix->rotScale[2];
    uVar4 = getCopReg(2, 0x4800);
    uVar5 = getCopReg(2, 0x5000);
    uVar6 = getCopReg(2, 0x5800);
    setCopReg(2, 0x4800, (uint)(ushort)segMatrix->rotScale[1]);
    setCopReg(2, 0x5000, (uint)(ushort)segMatrix->rotScale[4]);
    setCopReg(2, 0x5800, (uint)(ushort)segMatrix->rotScale[7]);
    segMatrix->rotScale[0] = (short)uVar4;
    segMatrix->rotScale[3] = (short)uVar5;
    copFunction(2, 0x49e012);
    uVar4 = getCopReg(2, 0x4800);
    uVar5 = getCopReg(2, 0x5000);
    uVar3 = getCopReg(2, 0x5800);
    setCopReg(2, 0x4800, (uint)uVar1);
    setCopReg(2, 0x5000, (uint)(ushort)segMatrix->rotScale[5]);
    setCopReg(2, 0x5800, (uint)(ushort)segMatrix->rotScale[8]);
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

// decompiled code
// original method signature:
// void /*$ra*/ _G2Anim_UpdateControllers(struct _G2Anim_Type *anim /*$s1*/)
// line 1101, offset 0x800913d0
/* begin block 1 */
// Start line: 1102
// Start offset: 0x800913D0
// Variables:
// 		struct _G2AnimController_Type *controller; // $s0
// 		struct _G2AnimSection_Type *section; // $v1
// 		short elapsedTime; // $s2
/* end block 1 */
// End offset: 0x80091544
// End Line: 1151

/* begin block 2 */
// Start line: 2271
/* end block 2 */
// End Line: 2272

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _G2Anim_UpdateControllers(_G2Anim_Type *anim)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  _G2AnimSection_Type *p_Var4;
  _G2AnimController_Type *controller;

  if (anim->controllerList != 0)
  {
    sVar2 = G2Timer_GetFrameTime();
    controller = _CHAR____800d5168 + anim->controllerList;
    if (_CHAR____800d5168 < controller)
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
                p_Var4 = G2Anim_GetSectionWithSeg(anim, (uint)controller->segNumber);
                if ((p_Var4 != (_G2AnimSection_Type *)0x0) && (p_Var4->callback != (_func_8 *)0x0))
                {
                  (*p_Var4->callback)(anim, (uint)p_Var4->sectionID, 4, (uint)controller->type,
                                      (uint)controller->segNumber, controller->callbackData);
                }
              }
            }
            else
            {
              controller->flags = uVar1 & 0x7fff;
              _G2AnimControllerST_RemoveFromList((uint)controller->segNumber, (uint)controller->type, &anim->controllerList);
              _G2AnimController_InsertIntoList(controller, &anim->disabledControllerList);
            }
          }
        }
        controller = _CHAR____800d5168 + controller->next;
      } while (_CHAR____800d5168 < controller);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ _G2Anim_CopyVectorWithOrder(struct _G2SVector3_Type *sourceVector /*$a0*/, struct _G2EulerAngles_Type *destVector /*$a1*/, int order /*$a2*/)
// line 1157, offset 0x8009155c
/* begin block 1 */
// Start line: 2387
/* end block 1 */
// End Line: 2388

/* begin block 2 */
// Start line: 2390
/* end block 2 */
// End Line: 2391

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

// decompiled code
// original method signature:
// void /*$ra*/ _G2AnimSection_ApplyControllersToStoredFrame(struct _G2AnimSection_Type *section /*$s3*/)
// line 1181, offset 0x800915c0
/* begin block 1 */
// Start line: 1182
// Start offset: 0x800915C0
// Variables:
// 		struct _G2Anim_Type *anim; // $s7
// 		struct _G2AnimController_Type *controller; // $s0
// 		struct _G2AnimSegValue_Type *segValue; // $s1
// 		struct _Segment *segment; // $s6
// 		struct _G2Matrix_Type segMatrix; // stack offset -152
// 		struct _G2Matrix_Type parentMatrix; // stack offset -120
// 		struct _G2Matrix_Type invParentMatrix; // stack offset -88
// 		struct _G2EulerAngles_Type eulerAngles; // stack offset -56
// 		int segIndex; // $s2
// 		int segCount; // $fp

/* begin block 1.1 */
// Start line: 1237
// Start offset: 0x80091760
// Variables:
// 		struct _G2Quat_Type tempQuat; // stack offset -48

/* begin block 1.1.1 */
// Start line: 1239
// Start offset: 0x80091760
// Variables:
// 		struct _G2Quat_Type *dest; // $s1

/* begin block 1.1.1.1 */
// Start line: 1239
// Start offset: 0x80091760
// Variables:
// 		unsigned long zw; // $v1
// 		unsigned long xy; // $v0
/* end block 1.1.1.1 */
// End offset: 0x80091760
// End Line: 1239
/* end block 1.1.1 */
// End offset: 0x80091760
// End Line: 1239
/* end block 1.1 */
// End offset: 0x80091760
// End Line: 1239

/* begin block 1.2 */
// Start line: 1242
// Start offset: 0x8009177C
// Variables:
// 		struct _G2SVector3_Type *dest; // $s1

/* begin block 1.2.1 */
// Start line: 1242
// Start offset: 0x8009177C
// Variables:
// 		unsigned long mask; // $v0
// 		unsigned short z; // $v1
// 		unsigned long xy; // $a0
/* end block 1.2.1 */
// End offset: 0x8009177C
// End Line: 1242
/* end block 1.2 */
// End offset: 0x8009177C
// End Line: 1242
/* end block 1 */
// End offset: 0x80091804
// End Line: 1260

/* begin block 2 */
// Start line: 2436
/* end block 2 */
// End Line: 2437

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _G2AnimSection_ApplyControllersToStoredFrame(_G2AnimSection_Type *section)

{
  _G2Anim_Type *p_Var1;
  _G2Matrix_Type *p_Var2;
  _G2AnimController_Type *controller;
  _G2AnimSegValue_Type *segValue;
  uint uVar3;
  undefined4 *puVar4;
  _Segment *p_Var5;
  uint uVar6;
  _G2Matrix_Type _Stack152;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  long local_64;
  long local_60;
  long local_5c;
  undefined4 auStack88[8];
  uint local_38;
  ushort local_34;
  undefined4 local_30;
  undefined4 local_2c;

  p_Var1 = _G2AnimSection_GetAnim(section);
  if (p_Var1->controllerList != 0)
  {
    uVar3 = (uint)section->firstSeg;
    controller = (_G2AnimController_Type *)(_CHAR____800d5168 + (uint)p_Var1->controllerList * 0x24);
    segValue = (_G2AnimSegValue_Type *)(&_segValues + uVar3 * 0x18);
    uVar6 = uVar3 + section->segCount;
    p_Var5 = p_Var1->modelData->segmentList;
    if (uVar3 < uVar6)
    {
      puVar4 = (undefined4 *)(&CHAR____800d49e0 + uVar3 * 0x18);
      do
      {
        if ((uint)controller->segNumber == uVar3)
        {
          _G2Anim_BuildSegLocalRotMatrix(segValue, &_Stack152);
          if (p_Var1->segMatrices == (_G2Matrix_Type *)0x0)
          {
            MATH3D_SetUnityMatrix((MATRIX *)&local_78);
          }
          else
          {
            p_Var2 = p_Var1->segMatrices + p_Var5->parent;
            local_78 = *(undefined4 *)p_Var2->rotScale;
            local_74 = *(undefined4 *)(p_Var2->rotScale + 2);
            local_70 = *(undefined4 *)(p_Var2->rotScale + 4);
            local_6c = *(undefined4 *)(p_Var2->rotScale + 6);
            local_68 = *(undefined4 *)(p_Var2->rotScale + 8);
            local_64 = (p_Var2->trans).x;
            local_60 = (p_Var2->trans).y;
            local_5c = (p_Var2->trans).z;
          }
          while ((uint)controller->segNumber == uVar3)
          {
            if ((uVar3 != 0) || ((controller->type & 2) != 0))
            {
              if ((controller->type & 0x38) == 8)
              {
                _G2AnimController_ApplyToSegValue(controller, segValue, &_Stack152, (_G2Matrix_Type *)&local_78);
                if ((controller->type & 2) == 0)
                {
                  /* WARNING: Subroutine does not return */
                  TransposeMatrix((undefined4 *)(_G2Matrix_Type *)&local_78, auStack88);
                }
                if (*(ushort *)((int)puVar4 + 0x12) == 0)
                {
                  G2EulerAngles_FromMatrix((_G2EulerAngles_Type *)&local_38, &_Stack152, 0);
                  *(ushort *)puVar4 = local_34 & 0xfff;
                  *(uint *)&segValue->rotQuat = local_38 & 0xfff0fff;
                }
                else
                {
                  G2EulerAngles_ToMatrix_S((undefined2 *)&local_30, (short *)&_Stack152);
                  *(undefined4 *)&segValue->rotQuat = local_30;
                  *puVar4 = local_2c;
                }
              }
              else
              {
                _G2AnimController_ApplyToSegValue(controller, segValue, &_Stack152, (_G2Matrix_Type *)&local_78);
              }
            }
            controller = (_G2AnimController_Type *)(_CHAR____800d5168 + (uint)controller->next * 0x24);
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

// decompiled code
// original method signature:
// unsigned long /*$ra*/ _G2AnimController_ApplyWorldToParentMatrix(struct _G2AnimController_Type *controller /*$a0*/, struct _G2Matrix_Type *parentMatrix /*$s0*/)
// line 1265, offset 0x80091834
/* begin block 1 */
// Start line: 1266
// Start offset: 0x80091834
// Variables:
// 		struct _G2Matrix_Type tempMatrix; // stack offset -64
// 		struct _G2SVector3_Type tempSVector; // stack offset -32
// 		struct _G2LVector3_Type tempLVector; // stack offset -24
/* end block 1 */
// End offset: 0x80091974
// End Line: 1317

/* begin block 2 */
// Start line: 2618
/* end block 2 */
// End Line: 2619

ulong _G2AnimController_ApplyWorldToParentMatrix(_G2AnimController_Type *controller, _G2Matrix_Type *parentMatrix)

{
  byte bVar1;
  ulong uVar2;
  _G2AnimController_Type *controller_00;
  _G2Matrix_Type *parentMatrix_00;
  undefined auStack64[32];
  _G2SVector3_Type local_20;
  int local_18;
  int local_14;
  int local_10;

  bVar1 = controller->type;
  if (bVar1 == 0x20)
  {
    parentMatrix_00 = (_G2Matrix_Type *)&local_20;
    _G2AnimController_GetVector(controller, (_G2SVector3_Type *)parentMatrix_00);
    (parentMatrix->trans).x = (int)local_20.x;
    (parentMatrix->trans).y = (int)local_20.y;
    (parentMatrix->trans).z = (int)local_20.z;
    uVar2 = _G2AnimController_ApplyWorldToParentMatrix(controller, parentMatrix_00);
    return uVar2;
  }
  if (bVar1 < 0x21)
  {
    if (bVar1 != 8)
    {
      uVar2 = _G2AnimController_ApplyWorldToParentMatrix(controller, parentMatrix);
      return uVar2;
    }
    _G2AnimController_GetMatrix(controller, parentMatrix);
    uVar2 = _G2AnimController_ApplyWorldToParentMatrix(controller, parentMatrix);
    return uVar2;
  }
  if (bVar1 == 0x54)
  {
    _G2AnimController_GetVector(controller, &local_20);
    local_18 = (int)local_20.x;
    local_14 = (int)local_20.y;
    local_10 = (int)local_20.z;
    parentMatrix_00 = (_G2Matrix_Type *)&local_18;
    ScaleMatrix((int *)parentMatrix, (undefined4 *)parentMatrix_00);
    uVar2 = _G2AnimController_ApplyWorldToParentMatrix((_G2AnimController_Type *)parentMatrix, parentMatrix_00);
    return uVar2;
  }
  if (bVar1 < 0x55)
  {
    if (bVar1 != 0x4c)
    {
      uVar2 = _G2AnimController_ApplyWorldToParentMatrix(controller, parentMatrix);
      return uVar2;
    }
    _G2AnimController_GetMatrix(controller, (_G2Matrix_Type *)auStack64);
    controller_00 = (_G2AnimController_Type *)auStack64;
    MulMatrix2((undefined4 *)controller_00, (uint *)parentMatrix);
    uVar2 = _G2AnimController_ApplyWorldToParentMatrix(controller_00, parentMatrix);
    return uVar2;
  }
  if (bVar1 != 100)
  {
    uVar2 = _G2AnimController_ApplyWorldToParentMatrix(controller, parentMatrix);
    return uVar2;
  }
  _G2AnimController_GetVector(controller, &local_20);
  (parentMatrix->trans).x = (parentMatrix->trans).x + (int)local_20.x;
  (parentMatrix->trans).y = (parentMatrix->trans).y + (int)local_20.y;
  (parentMatrix->trans).z = (parentMatrix->trans).z + (int)local_20.z;
  return 7;
}

// decompiled code
// original method signature:
// void /*$ra*/ _G2AnimController_GetMatrix(struct _G2AnimController_Type *controller /*$s0*/, struct _G2Matrix_Type *matrix /*$s1*/)
// line 1325, offset 0x80091988
/* begin block 1 */
// Start line: 1326
// Start offset: 0x80091988
// Variables:
// 		struct _G2Quat_Type tempQuat; // stack offset -24
/* end block 1 */
// End offset: 0x80091A4C
// End Line: 1376

/* begin block 2 */
// Start line: 2747
/* end block 2 */
// End Line: 2748

void _G2AnimController_GetMatrix(_G2AnimController_Type *controller, _G2Matrix_Type *matrix)

{
  ushort uVar1;
  long ratio;
  _G2Quat_Type _Stack24;

  uVar1 = controller->flags;
  if ((uVar1 & 0x4000) == 0)
  {
    if ((uVar1 & 0xff) == 1)
    {
      RotMatrixZYX((ushort *)controller->data, (uint *)matrix);
    }
    else
    {
      if ((uVar1 & 0xff) == 0x15)
      {
        RotMatrix((ushort *)controller->data, (uint *)matrix);
      }
    }
  }
  else
  {
    if ((uVar1 & 0x2000) == 0)
    {
      ratio = _G2AnimAlphaTable_GetValue(controller->alphaTable,
                                         ((int)controller->elapsedTime << 0xc) / (int)controller->duration);
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

// decompiled code
// original method signature:
// void /*$ra*/ _G2AnimController_GetVector(struct _G2AnimController_Type *controller /*$a0*/, struct _G2SVector3_Type *vector /*$a1*/)
// line 1381, offset 0x80091a60
/* begin block 1 */
// Start line: 1384
// Start offset: 0x80091A60

/* begin block 1.1 */
// Start line: 1384
// Start offset: 0x80091A60
// Variables:
// 		struct _G2SVector3_Type *dest; // $a1

/* begin block 1.1.1 */
// Start line: 1384
// Start offset: 0x80091A60
// Variables:
// 		unsigned short z; // $v1
// 		unsigned long xy; // $v0
/* end block 1.1.1 */
// End offset: 0x80091A60
// End Line: 1384
/* end block 1.1 */
// End offset: 0x80091A60
// End Line: 1384

/* begin block 1.2 */
// Start line: 1389
// Start offset: 0x80091A84
// Variables:
// 		struct _G2SVector3_Type *dest; // $a1
// 		struct _G2SVector3_Type *base; // $a1
// 		struct _G2SVector3_Type *offset; // $v0
// 		long alpha; // $v1
/* end block 1.2 */
// End offset: 0x80091AE0
// End Line: 1389
/* end block 1 */
// End offset: 0x80091AE0
// End Line: 1394

/* begin block 2 */
// Start line: 2859
/* end block 2 */
// End Line: 2860

/* begin block 3 */
// Start line: 2861
/* end block 3 */
// End Line: 2862

void _G2AnimController_GetVector(_G2AnimController_Type *controller, _G2SVector3_Type *vector)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;

  sVar1 = *(short *)(controller->data + 4);
  *(undefined4 *)vector = *(undefined4 *)controller->data;
  vector->z = sVar1;
  if ((controller->flags & 0x4000) != 0)
  {
    setCopReg(2, 0xc800, (uint)(ushort)vector->x);
    setCopReg(2, 0xd000, (uint)(ushort)vector->y);
    setCopReg(2, 0xd800, (uint)(ushort)vector->z);
    setCopReg(2, 0x4800, (uint) * (ushort *)(controller->data + 6));
    setCopReg(2, 0x5000, (uint) * (ushort *)(controller->data + 8));
    setCopReg(2, 0x5800, (uint) * (ushort *)(controller->data + 10));
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

// decompiled code
// original method signature:
// struct _G2AnimController_Type * /*$ra*/ _G2Anim_FindController(struct _G2Anim_Type *anim /*$s2*/, int segNumber /*$s0*/, int type /*$s1*/)
// line 1400, offset 0x80091ae8
/* begin block 1 */
// Start line: 1401
// Start offset: 0x80091AE8
// Variables:
// 		struct _G2AnimController_Type *controller; // $v0
/* end block 1 */
// End offset: 0x80091B2C
// End Line: 1415

/* begin block 2 */
// Start line: 2897
/* end block 2 */
// End Line: 2898

_G2AnimController_Type *_G2Anim_FindController(_G2Anim_Type *anim, int segNumber, int type)

{
  _G2AnimController_Type *p_Var1;

  p_Var1 = _G2AnimControllerST_FindInList(segNumber, type, &anim->controllerList);
  if (p_Var1 == (_G2AnimController_Type *)0x0)
  {
    p_Var1 = _G2AnimControllerST_FindInList(segNumber, type, &anim->disabledControllerList);
  }
  return p_Var1;
}

// decompiled code
// original method signature:
// struct _G2AnimController_Type * /*$ra*/ _G2AnimController_Create(int segNumber /*$s1*/, int type /*$s2*/)
// line 1479, offset 0x80091b44
/* begin block 1 */
// Start line: 1480
// Start offset: 0x80091B44
// Variables:
// 		struct _G2AnimController_Type *controller; // $s0
/* end block 1 */
// End offset: 0x80091B44
// End Line: 1480

/* begin block 2 */
// Start line: 2958
/* end block 2 */
// End Line: 2959

_G2AnimController_Type *_G2AnimController_Create(int segNumber, int type)

{
  void *__s;

  __s = G2PoolMem_Allocate(&_controllerPool);
  /* WARNING: Subroutine does not return */
  memset(__s, 0, 0x24);
}

// decompiled code
// original method signature:
// struct _G2AnimController_Type * /*$ra*/ _G2AnimController_Destroy(struct _G2AnimController_Type *controller /*$a1*/)
// line 1499, offset 0x80091bac
/* begin block 1 */
// Start line: 1502
// Start offset: 0x80091BBC
// Variables:
// 		int nextControllerIndex; // $s0
/* end block 1 */
// End offset: 0x80091BFC
// End Line: 1515

/* begin block 2 */
// Start line: 3046
/* end block 2 */
// End Line: 3047

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_G2AnimController_Type *_G2AnimController_Destroy(_G2AnimController_Type *controller)

{
  ushort uVar1;

  do
  {
    uVar1 = controller->next;
    G2PoolMem_Free(&_controllerPool, controller);
    controller = _CHAR____800d5168 + uVar1;
    if (controller <= _CHAR____800d5168)
    {
      return controller;
    }
  } while (controller->type == '\0');
  return controller;
}

// decompiled code
// original method signature:
// void /*$ra*/ _G2AnimController_InsertIntoList(struct _G2AnimController_Type *controller /*$a3*/, unsigned short *listPtr /*$a1*/)
// line 1521, offset 0x80091c10
/* begin block 1 */
// Start line: 1522
// Start offset: 0x80091C10
// Variables:
// 		struct _G2AnimController_Type *testController; // $a2
/* end block 1 */
// End offset: 0x80091D00
// End Line: 1553

/* begin block 2 */
// Start line: 3092
/* end block 2 */
// End Line: 3093

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _G2AnimController_InsertIntoList(_G2AnimController_Type *controller, ushort *listPtr)

{
  _G2AnimController_Type *p_Var1;
  _G2AnimController_Type *p_Var2;

  p_Var2 = _CHAR____800d5168 + *listPtr;
  if (_CHAR____800d5168 < p_Var2)
  {
    p_Var1 = p_Var2;
    while (p_Var2 = p_Var1, p_Var1->segNumber <= controller->segNumber)
    {
      if (((p_Var1->segNumber == controller->segNumber) && (controller->type < p_Var1->type)) ||
          (p_Var2 = _CHAR____800d5168 + p_Var1->next, listPtr = (ushort *)p_Var1, p_Var1 = p_Var2,
           p_Var2 <= _CHAR____800d5168))
        break;
    }
  }
  ((_G2AnimController_Type *)listPtr)->next =
      (ushort)((int)((int)controller - (int)_CHAR____800d5168) * 0x38e38e39 >> 2);
  do
  {
    p_Var1 = controller;
    controller = _CHAR____800d5168 + p_Var1->next;
  } while (_CHAR____800d5168 < _CHAR____800d5168 + p_Var1->next);
  p_Var1->next = (ushort)((int)((int)p_Var2 - (int)_CHAR____800d5168) * 0x38e38e39 >> 2);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ _G2AnimController_GetCurrentInterpQuat(struct _G2AnimController_Type *controller /*$s0*/, struct _G2Anim_Type *anim /*$a3*/, struct _G2Quat_Type *quat /*$s1*/)
// line 1560, offset 0x80091d40
/* begin block 1 */
// Start line: 1561
// Start offset: 0x80091D40
// Variables:
// 		struct _G2EulerAngles_Type eulerVector; // stack offset -24

/* begin block 1.1 */
// Start line: 1591
// Start offset: 0x80091E18
// Variables:
// 		struct _G2Quat_Type *quat; // $s1
/* end block 1.1 */
// End offset: 0x80091E18
// End Line: 1591
/* end block 1 */
// End offset: 0x80091E68
// End Line: 1609

/* begin block 2 */
// Start line: 3170
/* end block 2 */
// End Line: 3171

void _G2AnimController_GetCurrentInterpQuat(_G2AnimController_Type *controller, _G2Anim_Type *anim, _G2Quat_Type *quat)

{
  uchar uVar1;
  ushort uVar2;
  long ratio;
  undefined4 uVar3;
  undefined auStackX0[16];
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
        *(undefined4 *)quat = 0;
        *(undefined4 *)&quat->z = 0x10000000;
      }
      else
      {
        if (uVar1 == '\x0e')
        {
          _G2Anim_CopyVectorWithOrder((_G2SVector3_Type *)controller->data, &_Stack24, (uint)uVar2 & 0xff);
        }
        else
        {
          G2Anim_SegmentHasActiveChannels(anim, (uint)controller->segNumber, (short)register0x00000074 - 0x18);
          _Stack24.order = 0;
        }
        G2Quat_FromEuler_S((int)quat, (short *)&_Stack24);
      }
    }
  }
  else
  {
    if ((uVar2 & 0x2000) == 0)
    {
      ratio = _G2AnimAlphaTable_GetValue(controller->alphaTable,
                                         ((int)controller->elapsedTime << 0xc) / (int)controller->duration);
      G2Quat_Slerp_VM(ratio, (_G2Quat_Type *)controller->data, (_G2Quat_Type *)(controller->data + 8),
                      quat, 0);
    }
    else
    {
      uVar3 = *(undefined4 *)(controller->data + 0xc);
      *(undefined4 *)quat = *(undefined4 *)(controller->data + 8);
      *(undefined4 *)&quat->z = uVar3;
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ _G2AnimController_GetSimpleWorldRotQuat(struct _G2AnimController_Type *controller /*$a0*/, struct _G2Anim_Type *anim /*$a3*/, struct _G2Quat_Type *quat /*$s1*/)
// line 1615, offset 0x80091e7c
/* begin block 1 */
// Start line: 1616
// Start offset: 0x80091E7C
// Variables:
// 		struct _Segment *segment; // $v0
// 		struct _G2Matrix_Type *parentMatrix; // $s0
// 		struct _G2Matrix_Type segMatrix; // stack offset -48
// 		int segNumber; // $v0
/* end block 1 */
// End offset: 0x80091E7C
// End Line: 1616

/* begin block 2 */
// Start line: 3280
/* end block 2 */
// End Line: 3281

void _G2AnimController_GetSimpleWorldRotQuat(int param_1, int param_2, undefined2 *param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  _G2Matrix_Type _Stack48;

  iVar3 = *(int *)(param_2 + 0x14);
  iVar2 = (uint) * (byte *)(param_1 + 3) * 0x18;
  sVar1 = *(short *)(*(int *)(*(int *)(param_2 + 0x10) + 0x1c) + iVar2 + 0x12);
  _G2Anim_BuildSegLocalRotMatrix((_G2AnimSegValue_Type *)(&gp0xffffef28 + iVar2), &_Stack48);
  MulMatrix2((undefined4 *)(iVar3 + (int)sVar1 * 0x20), (uint *)&_Stack48);
  G2EulerAngles_ToMatrix_S(param_3, (short *)&_Stack48);
  return;
}

// decompiled code
// original method signature:
// struct _G2AnimController_Type * /*$ra*/ _G2AnimControllerST_FindInList(int segNumber /*$a0*/, int type /*$a1*/, unsigned short *listPtr /*$a2*/)
// line 1645, offset 0x80091efc
/* begin block 1 */
// Start line: 1648
// Start offset: 0x80091EFC
// Variables:
// 		struct _G2AnimController_Type *controller; // $a2
/* end block 1 */
// End offset: 0x80091F64
// End Line: 1663

/* begin block 2 */
// Start line: 3368
/* end block 2 */
// End Line: 3369

/* begin block 3 */
// Start line: 3370
/* end block 3 */
// End Line: 3371

/* begin block 4 */
// Start line: 3372
/* end block 4 */
// End Line: 3373

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_G2AnimController_Type *_G2AnimControllerST_FindInList(int segNumber, int type, ushort *listPtr)

{
  ushort uVar1;
  _G2AnimController_Type *p_Var2;
  _G2AnimController_Type *p_Var3;

  uVar1 = *listPtr;
  while ((p_Var3 = _CHAR____800d5168 + uVar1, _CHAR____800d5168 < p_Var3 &&
                                                  (((uint)p_Var3->segNumber != segNumber || ((uint)p_Var3->type != type)))))
  {
    uVar1 = p_Var3->next;
  }
  p_Var2 = (_G2AnimController_Type *)0x0;
  if (p_Var3 != _CHAR____800d5168)
  {
    p_Var2 = p_Var3;
  }
  return p_Var2;
}

// decompiled code
// original method signature:
// struct _G2AnimController_Type * /*$ra*/ _G2AnimControllerST_FindPtrInList(int segNumber /*$a0*/, int type /*$a1*/, unsigned short **listPtrPtr /*$a2*/)
// line 1669, offset 0x80091f6c
/* begin block 1 */
// Start line: 1672
// Start offset: 0x80091F6C
// Variables:
// 		struct _G2AnimController_Type *controller; // $a3
/* end block 1 */
// End offset: 0x80091FFC
// End Line: 1693

/* begin block 2 */
// Start line: 3416
/* end block 2 */
// End Line: 3417

/* begin block 3 */
// Start line: 3418
/* end block 3 */
// End Line: 3419

/* begin block 4 */
// Start line: 3423
/* end block 4 */
// End Line: 3424

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_G2AnimController_Type *
_G2AnimControllerST_FindPtrInList(int segNumber, int type, ushort **listPtrPtr)

{
  _G2AnimController_Type *p_Var1;

  p_Var1 = _CHAR____800d5168 + **listPtrPtr;
  if (_CHAR____800d5168 < p_Var1)
  {
    do
    {
      if (((uint)p_Var1->segNumber == segNumber) && ((uint)p_Var1->type == type))
        break;
      *(_G2AnimController_Type **)listPtrPtr = p_Var1;
      p_Var1 = _CHAR____800d5168 + p_Var1->next;
    } while (_CHAR____800d5168 < p_Var1);
  }
  if (p_Var1 == _CHAR____800d5168)
  {
    *listPtrPtr = (ushort *)0x0;
    return (_G2AnimController_Type *)0x0;
  }
  return p_Var1;
}

// decompiled code
// original method signature:
// struct _G2AnimController_Type * /*$ra*/ _G2AnimControllerST_RemoveFromList(int segNumber /*$a0*/, int type /*$a1*/, unsigned short *listPtr /*$a2*/)
// line 1730, offset 0x8009200c
/* begin block 1 */
// Start line: 1733
// Start offset: 0x8009200C
// Variables:
// 		struct _G2AnimController_Type *controller; // $a3
// 		struct _G2AnimController_Type *stepController; // $a1
// 		struct _G2AnimController_Type *nextController; // $a0
/* end block 1 */
// End offset: 0x800920D4
// End Line: 1762

/* begin block 2 */
// Start line: 3460
/* end block 2 */
// End Line: 3461

/* begin block 3 */
// Start line: 3502
/* end block 3 */
// End Line: 3503

/* begin block 4 */
// Start line: 3506
/* end block 4 */
// End Line: 3507

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_G2AnimController_Type *_G2AnimControllerST_RemoveFromList(int segNumber, int type, ushort *listPtr)

{
  ushort uVar1;
  _G2AnimController_Type *p_Var2;
  _G2AnimController_Type *p_Var3;
  _G2AnimController_Type *p_Var4;

  p_Var3 = _CHAR____800d5168 + *listPtr;
  if (_CHAR____800d5168 < _CHAR____800d5168 + *listPtr)
  {
    do
    {
      if (((uint)p_Var3->segNumber == segNumber) && (p_Var4 = p_Var3, (uint)p_Var3->type == type))
        break;
      p_Var4 = _CHAR____800d5168 + p_Var3->next;
      listPtr = (ushort *)p_Var3;
      p_Var3 = p_Var4;
    } while (_CHAR____800d5168 < p_Var4);
    p_Var3 = p_Var4;
    if (_CHAR____800d5168 < p_Var4)
    {
      do
      {
        p_Var2 = p_Var3;
        p_Var3 = _CHAR____800d5168;
        uVar1 = p_Var2->next;
        ((_G2AnimController_Type *)listPtr)->next = uVar1;
        p_Var3 = p_Var3 + uVar1;
        if (p_Var3 <= _CHAR____800d5168)
          break;
      } while (p_Var3->type == '\0');
      p_Var2->next = 0;
      return p_Var4;
    }
  }
  return (_G2AnimController_Type *)0x0;
}
