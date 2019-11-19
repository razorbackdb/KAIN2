#include "THISDUST.H"
#include "ANMCTRLR.H"


// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_AttachControllerToSeg(struct _G2Anim_Type *anim /*$s0*/, int segNumber /*$a1*/, int type /*$a2*/)
 // line 235, offset 0x8008e190
	/* begin block 1 */
		// Start line: 236
		// Start offset: 0x8008E190
	/* end block 1 */
	// End offset: 0x8008E190
	// End Line: 236

	/* begin block 2 */
		// Start line: 470
	/* end block 2 */
	// End Line: 471

void G2Anim_AttachControllerToSeg(_G2Anim_Type *anim,int segNumber,int type)

{
  _G2AnimController_Type *controller;
  
  controller = _G2AnimController_Create(segNumber,type);
  _G2AnimController_InsertIntoList(controller,&anim->controllerList);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_DetachControllerFromSeg(struct _G2Anim_Type *anim /*$s1*/, int segNumber /*$s2*/, int type /*$s3*/)
 // line 260, offset 0x8008e1c8
	/* begin block 1 */
		// Start line: 261
		// Start offset: 0x8008E1C8
		// Variables:
	// 		struct _G2AnimController_Type *controller; // $v0
	// 		unsigned short *controllerNextPtr; // stack offset -32
	/* end block 1 */
	// End offset: 0x8008E224
	// End Line: 286

	/* begin block 2 */
		// Start line: 530
	/* end block 2 */
	// End Line: 531

void G2Anim_DetachControllerFromSeg(_G2Anim_Type *anim,int segNumber,int type)

{
  _G2AnimController_Type *controller;
  ushort *local_20 [2];
  
  local_20[0] = &anim->controllerList;
  controller = _G2AnimControllerST_FindPtrInList(segNumber,type,local_20);
  if (controller == (_G2AnimController_Type *)0x0) {
    local_20[0] = &anim->disabledControllerList;
    controller = _G2AnimControllerST_FindPtrInList(segNumber,type,local_20);
  }
  controller = _G2AnimController_Destroy(controller);
  *local_20[0] = (ushort)((int)((int)controller - (int)_controllerPool.blockPool) * 0x38e38e39 >> 2)
  ;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_EnableController(struct _G2Anim_Type *anim /*$s2*/, int segNumber /*$s1*/, int type /*$a2*/)
 // line 339, offset 0x8008e288
	/* begin block 1 */
		// Start line: 340
		// Start offset: 0x8008E288
		// Variables:
	// 		struct _G2AnimController_Type *controller; // $s0
	// 		struct _G2Matrix_Type *segMatrix; // $v1
	/* end block 1 */
	// End offset: 0x8008E34C
	// End Line: 375

	/* begin block 2 */
		// Start line: 669
	/* end block 2 */
	// End Line: 670

void G2Anim_EnableController(_G2Anim_Type *anim,int segNumber,int type)

{
  _G2AnimController_Type *controller;
  _G2Matrix_Type *p_Var1;
  
  controller = _G2AnimControllerST_RemoveFromList(segNumber,type,&anim->disabledControllerList);
  if (controller != (_G2AnimController_Type *)0x0) {
    controller->duration = 0;
    controller->elapsedTime = 0;
    controller->flags = (ushort)*(byte *)&controller->flags;
    if (controller->type == '\b') {
      G2EulerAngles_ToMatrix_S
                ((undefined2 *)(controller->data + 8),(short *)(anim->segMatrices + segNumber));
    }
    else {
      if (controller->type == ' ') {
        p_Var1 = anim->segMatrices + segNumber;
        *(undefined2 *)controller->data = *(undefined2 *)&(p_Var1->trans).x;
        *(undefined2 *)(controller->data + 2) = *(undefined2 *)&(p_Var1->trans).y;
        *(undefined2 *)(controller->data + 4) = *(undefined2 *)&(p_Var1->trans).z;
      }
      else {
        memset(controller->data,0,0x10);
      }
    }
    _G2AnimController_InsertIntoList(controller,&anim->controllerList);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_DisableController(struct _G2Anim_Type *anim /*$s0*/, int segNumber /*$a1*/, int type /*$a2*/)
 // line 394, offset 0x8008e364
	/* begin block 1 */
		// Start line: 395
		// Start offset: 0x8008E364
		// Variables:
	// 		struct _G2AnimController_Type *controller; // $v0
	/* end block 1 */
	// End offset: 0x8008E394
	// End Line: 408

	/* begin block 2 */
		// Start line: 780
	/* end block 2 */
	// End Line: 781

void G2Anim_DisableController(_G2Anim_Type *anim,int segNumber,int type)

{
  _G2AnimController_Type *controller;
  
  controller = _G2AnimControllerST_RemoveFromList(segNumber,type,&anim->controllerList);
  if (controller != (_G2AnimController_Type *)0x0) {
    _G2AnimController_InsertIntoList(controller,&anim->disabledControllerList);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_InterpDisableController(struct _G2Anim_Type *anim /*$s2*/, int segNumber /*$s4*/, int type /*$s3*/, short duration /*$s5*/)
 // line 427, offset 0x8008e3a4
	/* begin block 1 */
		// Start line: 428
		// Start offset: 0x8008E3A4
		// Variables:
	// 		struct _G2AnimController_Type *controller; // $s1
	// 		struct _G2SVector3_Type zeroVector; // stack offset -48
	// 		struct _G2Quat_Type targetQuat; // stack offset -40
	/* end block 1 */
	// End offset: 0x8008E4A0
	// End Line: 472

	/* begin block 2 */
		// Start line: 845
	/* end block 2 */
	// End Line: 846

void G2Anim_InterpDisableController(_G2Anim_Type *anim,int segNumber,int type,short duration)

{
  _G2AnimController_Type *controller;
  _G2SVector3_Type _Stack48;
  _G2Quat_Type _Stack40;
  
  memset(&_Stack48,0,6);
  if ((duration == 0) || (type == 0x20)) {
    G2Anim_DisableController(anim,segNumber,type);
  }
  controller = _G2AnimControllerST_FindInList(segNumber,type,&anim->controllerList);
  if (controller != (_G2AnimController_Type *)0x0) {
    if (controller->type == '\b') {
      _G2AnimController_GetSimpleWorldRotQuat(controller,anim,&_Stack40);
      G2Anim_SetInterpController_Quat(anim,segNumber,type,&_Stack40,(int)duration);
    }
    else {
      G2Anim_SetInterpController_Vector(anim,segNumber,type,&_Stack48,(int)duration);
    }
    controller->flags = controller->flags | 0x8000;
  }
  return;
}



// decompiled code
// original method signature: 
// enum _G2Bool_Enum /*$ra*/ G2Anim_IsControllerActive(struct _G2Anim_Type *anim /*$a0*/, int segNumber /*$a1*/, int type /*$a2*/)
 // line 493, offset 0x8008e4c4
	/* begin block 1 */
		// Start line: 494
		// Start offset: 0x8008E4C4
		// Variables:
	// 		struct _G2AnimController_Type *controller; // $v0
	/* end block 1 */
	// End offset: 0x8008E500
	// End Line: 510

	/* begin block 2 */
		// Start line: 975
	/* end block 2 */
	// End Line: 976

_G2Bool_Enum G2Anim_IsControllerActive(_G2Anim_Type *anim,int segNumber,int type)

{
  _G2AnimController_Type *p_Var1;
  _G2Bool_Enum _Var2;
  
  p_Var1 = _G2AnimControllerST_FindInList(segNumber,type,&anim->controllerList);
  if (p_Var1 == (_G2AnimController_Type *)0x0) {
    _Var2 = G2FALSE;
  }
  else {
    _Var2 = (_G2Bool_Enum)((p_Var1->flags & 0x8000) == 0);
  }
  return _Var2;
}



// decompiled code
// original method signature: 
// enum _G2Bool_Enum /*$ra*/ G2Anim_IsControllerInterpolating(struct _G2Anim_Type *anim /*$a0*/, int segNumber /*$a1*/, int type /*$a2*/)
 // line 516, offset 0x8008e510
	/* begin block 1 */
		// Start line: 517
		// Start offset: 0x8008E510
		// Variables:
	// 		struct _G2AnimController_Type *controller; // $v0
	/* end block 1 */
	// End offset: 0x8008E554
	// End Line: 537

	/* begin block 2 */
		// Start line: 981
	/* end block 2 */
	// End Line: 982

_G2Bool_Enum G2Anim_IsControllerInterpolating(_G2Anim_Type *anim,int segNumber,int type)

{
  _G2AnimController_Type *p_Var1;
  _G2Bool_Enum _Var2;
  
  p_Var1 = _G2AnimControllerST_FindInList(segNumber,type,&anim->controllerList);
  if ((p_Var1 == (_G2AnimController_Type *)0x0) || ((p_Var1->flags & 0x4000) == 0)) {
    _Var2 = G2FALSE;
  }
  else {
    _Var2 = (_G2Bool_Enum)((p_Var1->flags & 0x2000) == 0);
  }
  return _Var2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_GetControllerCurrentInterpVector(struct _G2Anim_Type *anim /*$s1*/, int segNumber /*$a1*/, int type /*$a2*/, struct _G2SVector3_Type *vector /*$s0*/)
 // line 555, offset 0x8008e564
	/* begin block 1 */
		// Start line: 556
		// Start offset: 0x8008E564
		// Variables:
	// 		struct _G2AnimController_Type *controller; // $v1
	// 		struct _G2SVector3_Type *base; // $a0
	// 		struct _G2SVector3_Type *offset; // $a1
	// 		struct _G2Matrix_Type *segMatrix; // $v1

		/* begin block 1.1 */
			// Start line: 576
			// Start offset: 0x8008E5A8
			// Variables:
		// 		struct _G2SVector3_Type *source; // $a0
		// 		struct _G2SVector3_Type *dest; // $s0

			/* begin block 1.1.1 */
				// Start line: 576
				// Start offset: 0x8008E5A8
				// Variables:
			// 		unsigned short z; // $v1
			// 		unsigned long xy; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8008E5A8
			// End Line: 576
		/* end block 1.1 */
		// End offset: 0x8008E5A8
		// End Line: 576

		/* begin block 1.2 */
			// Start line: 577
			// Start offset: 0x8008E5BC
			// Variables:
		// 		struct _G2SVector3_Type *dest; // $s0
		// 		struct _G2SVector3_Type *base; // $a0
		// 		struct _G2SVector3_Type *offset; // $a1
		// 		long alpha; // $v0
		/* end block 1.2 */
		// End offset: 0x8008E5BC
		// End Line: 577
	/* end block 1 */
	// End offset: 0x8008E6B0
	// End Line: 600

	/* begin block 2 */
		// Start line: 1101
	/* end block 2 */
	// End Line: 1102

void G2Anim_GetControllerCurrentInterpVector
               (_G2Anim_Type *anim,int segNumber,int type,_G2SVector3_Type *vector)

{
  uchar uVar1;
  short sVar2;
  _G2AnimController_Type *p_Var3;
  _G2Matrix_Type *p_Var4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  p_Var3 = _G2Anim_FindController(anim,segNumber,type);
  if (p_Var3->duration == 0) {
    uVar1 = p_Var3->type;
    if (uVar1 == '\x12') {
      G2Anim_GetSegChannelValue(anim,(uint)p_Var3->segNumber,(ushort *)vector,0x70);
    }
    else {
      if (uVar1 == '\"') {
        G2Anim_GetSegChannelValue(anim,(uint)p_Var3->segNumber,(ushort *)vector,0x700);
      }
      else {
        if (uVar1 == ' ') {
          p_Var4 = anim->segMatrices + p_Var3->segNumber;
          vector->x = *(short *)&(p_Var4->trans).x;
          vector->y = *(short *)&(p_Var4->trans).y;
          vector->z = *(short *)&(p_Var4->trans).z;
        }
      }
    }
  }
  else {
    if ((p_Var3->flags & 0x2000) == 0) {
      setCopReg(2,0xc800,(uint)*(ushort *)p_Var3->data);
      setCopReg(2,0xd000,(uint)*(ushort *)(p_Var3->data + 2));
      setCopReg(2,0xd800,(uint)*(ushort *)(p_Var3->data + 4));
      setCopReg(2,0x4800,(uint)*(ushort *)(p_Var3->data + 6));
      setCopReg(2,0x5000,(uint)*(ushort *)(p_Var3->data + 8));
      setCopReg(2,0x5800,(uint)*(ushort *)(p_Var3->data + 10));
      setCopReg(2,0x4000,(int)p_Var3->elapsedTime);
      copFunction(2,0x1a8003e);
      uVar5 = getCopReg(2,0xc800);
      uVar6 = getCopReg(2,0xd000);
      uVar7 = getCopReg(2,0xd800);
      vector->x = (short)uVar5;
      vector->y = (short)uVar6;
      vector->z = (short)uVar7;
    }
    else {
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
 // line 626, offset 0x8008e6c4
	/* begin block 1 */
		// Start line: 627
		// Start offset: 0x8008E6C4
	/* end block 1 */
	// End offset: 0x8008E6C4
	// End Line: 627

	/* begin block 2 */
		// Start line: 1235
	/* end block 2 */
	// End Line: 1236

void G2Anim_SetControllerCallbackData(_G2Anim_Type *anim,int segNumber,int type,void *callbackData)

{
  _G2AnimController_Type *p_Var1;
  
  p_Var1 = _G2Anim_FindController(anim,segNumber,type);
  p_Var1->callbackData = callbackData;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_SetControllerAngleOrder(struct _G2Anim_Type *anim /*$a0*/, int segNumber /*$a1*/, int type /*$a2*/, int order /*$s0*/)
 // line 645, offset 0x8008e6ec
	/* begin block 1 */
		// Start line: 646
		// Start offset: 0x8008E6EC
		// Variables:
	// 		struct _G2AnimController_Type *controller; // $v0
	/* end block 1 */
	// End offset: 0x8008E6EC
	// End Line: 646

	/* begin block 2 */
		// Start line: 1199
	/* end block 2 */
	// End Line: 1200

void G2Anim_SetControllerAngleOrder(_G2Anim_Type *anim,int segNumber,int type,int order)

{
  _G2AnimController_Type *p_Var1;
  
  p_Var1 = _G2Anim_FindController(anim,segNumber,type);
  p_Var1->flags = p_Var1->flags & 0xff00 | (ushort)order;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_SetController_Vector(struct _G2Anim_Type *anim /*$a0*/, int segNumber /*$a1*/, int type /*$a2*/, struct _G2SVector3_Type *vector /*$s0*/)
 // line 665, offset 0x8008e724
	/* begin block 1 */
		// Start line: 666
		// Start offset: 0x8008E724
		// Variables:
	// 		struct _G2AnimController_Type *controller; // $v0
	/* end block 1 */
	// End offset: 0x8008E724
	// End Line: 666

	/* begin block 2 */
		// Start line: 1239
	/* end block 2 */
	// End Line: 1240

void G2Anim_SetController_Vector(_G2Anim_Type *anim,int segNumber,int type,_G2SVector3_Type *vector)

{
  short sVar1;
  _G2AnimController_Type *p_Var2;
  
  p_Var2 = _G2Anim_FindController(anim,segNumber,type);
  sVar1 = vector->z;
  *(undefined4 *)p_Var2->data = *(undefined4 *)vector;
  *(short *)(p_Var2->data + 4) = sVar1;
  p_Var2->flags = (ushort)*(byte *)&p_Var2->flags;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_SetInterpController_Vector(struct _G2Anim_Type *anim /*$s2*/, int segNumber /*$s3*/, int type /*$s4*/, struct _G2SVector3_Type *vector /*$s6*/, int duration /*stack 16*/)
 // line 708, offset 0x8008e76c
	/* begin block 1 */
		// Start line: 709
		// Start offset: 0x8008E76C
		// Variables:
	// 		struct _G2AnimController_Type *controller; // $s1
	// 		struct _G2EulerAngles_Type eulerVector; // stack offset -48
	// 		struct _G2SVector3_Type *base; // $s0
	// 		struct _G2SVector3_Type *offset; // $a1
	// 		struct _G2Quat_Type quat; // stack offset -40
	/* end block 1 */
	// End offset: 0x8008E8A8
	// End Line: 750

	/* begin block 2 */
		// Start line: 1390
	/* end block 2 */
	// End Line: 1391

void G2Anim_SetInterpController_Vector
               (_G2Anim_Type *anim,int segNumber,int type,_G2SVector3_Type *vector,int duration)

{
  _G2AnimController_Type *p_Var1;
  short sVar2;
  int iVar3;
  _G2EulerAngles_Type _Stack48;
  _G2Quat_Type _Stack40;
  
  p_Var1 = _G2Anim_FindController(anim,segNumber,type);
  sVar2 = (short)duration;
  if ((p_Var1->type & 0x38) == 8) {
    _G2Anim_CopyVectorWithOrder(vector,&_Stack48,(uint)*(byte *)&p_Var1->flags);
    G2Quat_FromEuler_S((int)&_Stack40,(short *)&_Stack48);
    G2Anim_SetInterpController_Quat(anim,segNumber,type,&_Stack40,(int)sVar2);
  }
  else {
    G2Anim_GetControllerCurrentInterpVector(anim,segNumber,type,(_G2SVector3_Type *)p_Var1->data);
    iVar3 = (int)sVar2 + 1;
    *(short *)(p_Var1->data + 6) =
         (short)((((int)vector->x - (int)*(short *)p_Var1->data) * 0x1000) / iVar3);
    *(short *)(p_Var1->data + 8) =
         (short)((((int)vector->y - (int)*(short *)(p_Var1->data + 2)) * 0x1000) / iVar3);
    *(short *)(p_Var1->data + 10) =
         (short)((((int)vector->z - (int)*(short *)(p_Var1->data + 4)) * 0x1000) / iVar3);
    p_Var1->duration = sVar2;
    p_Var1->elapsedTime = 0;
    p_Var1->flags = (ushort)*(byte *)&p_Var1->flags | 0x4000;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_SetInterpController_Quat(struct _G2Anim_Type *anim /*$s1*/, int segNumber /*$a1*/, int type /*$a2*/, struct _G2Quat_Type *quat /*$s2*/, int duration /*stack 16*/)
 // line 777, offset 0x8008e8d0
	/* begin block 1 */
		// Start line: 778
		// Start offset: 0x8008E8D0
		// Variables:
	// 		struct _G2AnimController_Type *controller; // $s0

		/* begin block 1.1 */
			// Start line: 778
			// Start offset: 0x8008E8D0
			// Variables:
		// 		struct _G2Quat_Type *source; // $s2

			/* begin block 1.1.1 */
				// Start line: 778
				// Start offset: 0x8008E8D0
				// Variables:
			// 		unsigned long zw; // $a0
			// 		unsigned long xy; // $v1
			/* end block 1.1.1 */
			// End offset: 0x8008E8D0
			// End Line: 778
		/* end block 1.1 */
		// End offset: 0x8008E8D0
		// End Line: 778
	/* end block 1 */
	// End offset: 0x8008E8D0
	// End Line: 778

	/* begin block 2 */
		// Start line: 1545
	/* end block 2 */
	// End Line: 1546

void G2Anim_SetInterpController_Quat
               (_G2Anim_Type *anim,int segNumber,int type,_G2Quat_Type *quat,int duration)

{
  byte bVar1;
  _G2AnimController_Type *controller;
  undefined4 uVar2;
  undefined4 uVar3;
  
  controller = _G2Anim_FindController(anim,segNumber,type);
  _G2AnimController_GetCurrentInterpQuat(controller,anim,(_G2Quat_Type *)controller->data);
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
 // line 807, offset 0x8008e94c
	/* begin block 1 */
		// Start line: 808
		// Start offset: 0x8008E94C
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8008E994
	// End Line: 817

	/* begin block 2 */
		// Start line: 1481
	/* end block 2 */
	// End Line: 1482

void _G2Anim_ApplyControllersToStoredFrame(_G2Anim_Type *anim)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (anim->sectionCount != '\0') {
    iVar2 = 0x24;
    do {
      _G2AnimSection_ApplyControllersToStoredFrame
                ((_G2AnimSection_Type *)(&anim->sectionCount + iVar2));
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x30;
    } while (iVar1 < (int)(uint)anim->sectionCount);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Anim_BuildTransformsWithControllers(struct _G2Anim_Type *anim /*$s6*/)
 // line 821, offset 0x8008e9ac
	/* begin block 1 */
		// Start line: 822
		// Start offset: 0x8008E9AC
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
	// End offset: 0x8008EB54
	// End Line: 907

	/* begin block 2 */
		// Start line: 1510
	/* end block 2 */
	// End Line: 1511

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
  uint local_38;
  ulong local_34;
  ulong local_30;
  
  uVar4 = 1;
  segIndex = 0;
  segMatrix = anim->segMatrices;
  local_38 = anim->disabledBits[0];
  local_34 = anim->disabledBits[1];
  bRootTransUpdated = (_G2Bool_Enum)((anim->section[0].flags & 0x88) == 0x80);
  local_30 = anim->disabledBits[2];
  iVar6 = anim->modelData->numSegments;
  controller = _controllerPool.blockPool + anim->controllerList;
  if (0 < iVar6) {
    puVar5 = (ushort *)&anim->modelData->segmentList->parent;
    puVar3 = &local_38;
    do {
      iVar2 = (uint)*puVar5 << 0x10;
      if ((iVar2 >> 0x10 != -1) && (((&local_38)[iVar2 >> 0x15] & 1 << (*puVar5 & 0x1f)) != 0)) {
        *puVar3 = *puVar3 | uVar4;
      }
      if ((*puVar3 & uVar4) == 0) {
        if ((uint)controller->segNumber == segIndex) {
          _G2Anim_BuildSegTransformWithControllers
                    (segMatrix,anim->segMatrices + (short)*puVar5,controller,bRootTransUpdated,
                     segIndex);
          bVar1 = controller->segNumber;
          while ((uint)bVar1 == segIndex) {
            controller = _controllerPool.blockPool + controller->next;
            bVar1 = controller->segNumber;
          }
        }
        else {
          _G2Anim_BuildSegTransformNoControllers
                    (segMatrix,anim->segMatrices + (short)*puVar5,bRootTransUpdated,segIndex);
        }
      }
      puVar5 = puVar5 + 0xc;
      bRootTransUpdated = G2FALSE;
      segMatrix = segMatrix + 1;
      uVar4 = uVar4 << 1;
      segIndex = segIndex + 1;
      if (uVar4 == 0) {
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
 // line 916, offset 0x8008eb8c
	/* begin block 1 */
		// Start line: 917
		// Start offset: 0x8008EB8C
		// Variables:
	// 		struct _G2AnimSegValue_Type *segValue; // $s1
	// 		struct _G2LVector3_Type scale; // stack offset -48
	// 		unsigned long flags; // $s3

		/* begin block 1.1 */
			// Start line: 974
			// Start offset: 0x8008ED94
			// Variables:
		// 		struct _G2SVector3_Type *svector; // $v0
		// 		struct _G2LVector3_Type *lvector; // $v1
		/* end block 1.1 */
		// End offset: 0x8008ED94
		// End Line: 974
	/* end block 1 */
	// End offset: 0x8008EE38
	// End Line: 1001

	/* begin block 2 */
		// Start line: 1879
	/* end block 2 */
	// End Line: 1880

void _G2Anim_BuildSegTransformWithControllers
               (_G2Matrix_Type *segMatrix,_G2Matrix_Type *parentMatrix,
               _G2AnimController_Type *controller,_G2Bool_Enum bRootTransUpdated,int segIndex)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  long lVar5;
  undefined4 in_zero;
  undefined4 in_at;
  ulong uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  int local_30;
  int local_2c;
  int local_28;
  
  _G2Anim_BuildSegLocalRotMatrix(&_segValues + segIndex,segMatrix);
  bVar1 = controller->segNumber;
  uVar11 = 7;
  while ((uint)bVar1 == segIndex) {
                    /* WARNING: Read-only address (ram,0x800d55b0) is written */
    uVar6 = _G2AnimController_ApplyToSegValue
                      (controller,&_segValues + segIndex,segMatrix,parentMatrix);
    controller = _controllerPool.blockPool + controller->next;
    bVar1 = controller->segNumber;
    uVar11 = uVar11 & uVar6;
  }
                    /* WARNING: Read-only address (ram,0x800d55b0) is written */
  setCopControlWord(2,0,*(undefined4 *)parentMatrix->rotScale);
  setCopControlWord(2,0x800,*(undefined4 *)(parentMatrix->rotScale + 2));
  setCopControlWord(2,0x1000,*(undefined4 *)(parentMatrix->rotScale + 4));
  setCopControlWord(2,0x1800,*(undefined4 *)(parentMatrix->rotScale + 6));
  setCopControlWord(2,0x2000,*(undefined4 *)(parentMatrix->rotScale + 8));
  uVar2 = (&_segValues)[segIndex].scale.x;
  local_30 = (int)(short)uVar2;
  uVar3 = (&_segValues)[segIndex].scale.y;
  local_2c = (int)(short)uVar3;
  uVar4 = (&_segValues)[segIndex].scale.z;
  local_28 = (int)(short)uVar4;
  if ((ushort)(uVar2 | uVar3 | uVar4) != 0x1000) {
    ScaleMatrix((int *)segMatrix,&local_30);
    segMatrix->scaleFlag = 1;
  }
  if ((uVar11 & 1) != 0) {
    setCopReg(2,0x4800,(uint)(ushort)segMatrix->rotScale[0]);
    setCopReg(2,0x5000,(uint)(ushort)segMatrix->rotScale[3]);
    setCopReg(2,0x5800,(uint)(ushort)segMatrix->rotScale[6]);
    copFunction(2,0x49e012);
    uVar2 = segMatrix->rotScale[2];
    uVar8 = getCopReg(2,0x4800);
    uVar9 = getCopReg(2,0x5000);
    uVar10 = getCopReg(2,0x5800);
    setCopReg(2,0x4800,(uint)(ushort)segMatrix->rotScale[1]);
    setCopReg(2,0x5000,(uint)(ushort)segMatrix->rotScale[4]);
    setCopReg(2,0x5800,(uint)(ushort)segMatrix->rotScale[7]);
    segMatrix->rotScale[0] = (short)uVar8;
    segMatrix->rotScale[3] = (short)uVar9;
    copFunction(2,0x49e012);
    uVar8 = getCopReg(2,0x4800);
    uVar9 = getCopReg(2,0x5000);
    uVar7 = getCopReg(2,0x5800);
    setCopReg(2,0x4800,(uint)uVar2);
    setCopReg(2,0x5000,(uint)(ushort)segMatrix->rotScale[5]);
    setCopReg(2,0x5800,(uint)(ushort)segMatrix->rotScale[8]);
    segMatrix->rotScale[6] = (short)uVar10;
    segMatrix->rotScale[1] = (short)uVar8;
    copFunction(2,0x49e012);
    segMatrix->rotScale[4] = (short)uVar9;
    segMatrix->rotScale[7] = (short)uVar7;
    uVar8 = getCopReg(2,0x4800);
    uVar9 = getCopReg(2,0x5000);
    uVar7 = getCopReg(2,0x5800);
    segMatrix->rotScale[2] = (short)uVar8;
    segMatrix->rotScale[5] = (short)uVar9;
    segMatrix->rotScale[8] = (short)uVar7;
  }
  if ((uVar11 & 4) == 0) {
    (segMatrix->trans).x = (int)(&_segValues)[segIndex].trans.x;
    (segMatrix->trans).y = (int)(&_segValues)[segIndex].trans.y;
    (segMatrix->trans).z = (int)(&_segValues)[segIndex].trans.z;
  }
  else {
    if (segIndex == 0) {
      setCopControlWord(2,0,*(undefined4 *)segMatrix->rotScale);
      setCopControlWord(2,0x800,*(undefined4 *)(segMatrix->rotScale + 2));
      setCopControlWord(2,0x1000,*(undefined4 *)(segMatrix->rotScale + 4));
      setCopControlWord(2,0x1800,*(undefined4 *)(segMatrix->rotScale + 6));
      setCopControlWord(2,0x2000,*(undefined4 *)(segMatrix->rotScale + 8));
    }
    setCopReg(2,in_zero,*(undefined4 *)&(&_segValues)[segIndex].trans);
    setCopReg(2,in_at,*(undefined4 *)&(&_segValues)[segIndex].trans.z);
    copFunction(2,0x486012);
    lVar5 = getCopReg(2,0x19);
    (segMatrix->trans).x = lVar5;
    lVar5 = getCopReg(2,0x1a);
    (segMatrix->trans).y = lVar5;
    lVar5 = getCopReg(2,0x1b);
    (segMatrix->trans).z = lVar5;
  }
  if (bRootTransUpdated != G2FALSE) {
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
 // line 1011, offset 0x8008ee9c
	/* begin block 1 */
		// Start line: 1012
		// Start offset: 0x8008EE9C
		// Variables:
	// 		struct _G2Matrix_Type tempMatrix; // stack offset -64
	// 		struct _G2SVector3_Type tempVector; // stack offset -32
	// 		unsigned long flags; // $s1

		/* begin block 1.1 */
			// Start line: 1060
			// Start offset: 0x8008F118

			/* begin block 1.1.1 */
				// Start line: 1060
				// Start offset: 0x8008F118
				// Variables:
			// 		unsigned short z; // $v1
			// 		unsigned long xy; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8008F118
			// End Line: 1060
		/* end block 1.1 */
		// End offset: 0x8008F118
		// End Line: 1060

		/* begin block 1.2 */
			// Start line: 1078
			// Start offset: 0x8008F1C4

			/* begin block 1.2.1 */
				// Start line: 1078
				// Start offset: 0x8008F1C4
				// Variables:
			// 		unsigned short z; // $v1
			// 		unsigned long xy; // $v0
			/* end block 1.2.1 */
			// End offset: 0x8008F1C4
			// End Line: 1078
		/* end block 1.2 */
		// End offset: 0x8008F1C4
		// End Line: 1078
	/* end block 1 */
	// End offset: 0x8008F228
	// End Line: 1094

	/* begin block 2 */
		// Start line: 2091
	/* end block 2 */
	// End Line: 2092

/* WARNING: Could not reconcile some variable overlaps */

ulong _G2AnimController_ApplyToSegValue
                (_G2AnimController_Type *controller,_G2AnimSegValue_Type *segValue,
                _G2Matrix_Type *segMatrix,_G2Matrix_Type *parentMatrix)

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
  
  if ((*(uint *)controller & 0xff020000) == 0) {
    uVar2 = _G2AnimController_ApplyWorldToParentMatrix(controller,parentMatrix);
    return uVar2;
  }
  uVar2 = 7;
  switch(controller->type) {
  case '\x01':
    uVar2 = (**(code **)controller->data)
                      (controller,segValue,parentMatrix,segMatrix,
                       *(undefined4 *)(controller->data + 4));
    break;
  case '\b':
    uVar2 = 6;
  case '\n':
    _G2AnimController_GetMatrix(controller,segMatrix);
    break;
  case '\x10':
    uVar2 = 5;
  case '\x12':
    _G2AnimController_GetVector(controller,(_G2SVector3_Type *)&local_20);
    *(undefined4 *)&segValue->scale = local_20;
    (segValue->scale).z = local_1c;
    break;
  case '\x16':
    _G2AnimController_GetVector(controller,(_G2SVector3_Type *)&local_20);
    (segValue->scale).x = (segValue->scale).x + (short)local_20;
    (segValue->scale).y = (segValue->scale).y + local_20._2_2_;
    (segValue->scale).z = (segValue->scale).z + local_1c;
    break;
  case ' ':
    uVar2 = 3;
    _G2AnimController_GetVector(controller,(_G2SVector3_Type *)&local_20);
    (segValue->trans).x = (short)local_20 - *(short *)&(parentMatrix->trans).x;
    (segValue->trans).y = local_20._2_2_ - *(short *)&(parentMatrix->trans).y;
    local_1c = local_1c - *(short *)&(parentMatrix->trans).z;
    goto LAB_8008f220;
  case '\"':
    _G2AnimController_GetVector(controller,(_G2SVector3_Type *)&local_20);
    *(undefined4 *)&segValue->trans = local_20;
    (segValue->trans).z = local_1c;
    break;
  case '&':
    _G2AnimController_GetVector(controller,(_G2SVector3_Type *)&local_20);
    (segValue->trans).x = (segValue->trans).x + (short)local_20;
    (segValue->trans).y = (segValue->trans).y + local_20._2_2_;
    local_1c = (segValue->trans).z + local_1c;
LAB_8008f220:
    (segValue->trans).z = local_1c;
    break;
  case 'L':
    uVar2 = 6;
    setCopControlWord(2,0,*(undefined4 *)parentMatrix->rotScale);
    setCopControlWord(2,0x800,*(undefined4 *)(parentMatrix->rotScale + 2));
    setCopControlWord(2,0x1000,*(undefined4 *)(parentMatrix->rotScale + 4));
    setCopControlWord(2,0x1800,*(undefined4 *)(parentMatrix->rotScale + 6));
    setCopControlWord(2,0x2000,*(undefined4 *)(parentMatrix->rotScale + 8));
    setCopReg(2,0x4800,(uint)(ushort)segMatrix->rotScale[0]);
    setCopReg(2,0x5000,(uint)(ushort)segMatrix->rotScale[3]);
    setCopReg(2,0x5800,(uint)(ushort)segMatrix->rotScale[6]);
    copFunction(2,0x49e012);
    uVar1 = segMatrix->rotScale[2];
    uVar4 = getCopReg(2,0x4800);
    uVar5 = getCopReg(2,0x5000);
    uVar6 = getCopReg(2,0x5800);
    setCopReg(2,0x4800,(uint)(ushort)segMatrix->rotScale[1]);
    setCopReg(2,0x5000,(uint)(ushort)segMatrix->rotScale[4]);
    setCopReg(2,0x5800,(uint)(ushort)segMatrix->rotScale[7]);
    segMatrix->rotScale[0] = (short)uVar4;
    segMatrix->rotScale[3] = (short)uVar5;
    copFunction(2,0x49e012);
    uVar4 = getCopReg(2,0x4800);
    uVar5 = getCopReg(2,0x5000);
    uVar3 = getCopReg(2,0x5800);
    setCopReg(2,0x4800,(uint)uVar1);
    setCopReg(2,0x5000,(uint)(ushort)segMatrix->rotScale[5]);
    setCopReg(2,0x5800,(uint)(ushort)segMatrix->rotScale[8]);
    segMatrix->rotScale[6] = (short)uVar6;
    segMatrix->rotScale[1] = (short)uVar4;
    copFunction(2,0x49e012);
    segMatrix->rotScale[4] = (short)uVar5;
    segMatrix->rotScale[7] = (short)uVar3;
    uVar4 = getCopReg(2,0x4800);
    uVar5 = getCopReg(2,0x5000);
    uVar3 = getCopReg(2,0x5800);
    segMatrix->rotScale[2] = (short)uVar4;
    segMatrix->rotScale[5] = (short)uVar5;
    segMatrix->rotScale[8] = (short)uVar3;
  case '\x0e':
    _G2AnimController_GetMatrix(controller,(_G2Matrix_Type *)&local_40);
    setCopControlWord(2,0,local_40);
    setCopControlWord(2,0x800,local_3c);
    setCopControlWord(2,0x1000,local_38);
    setCopControlWord(2,0x1800,local_34);
    setCopControlWord(2,0x2000,local_30);
    setCopReg(2,0x4800,(uint)(ushort)segMatrix->rotScale[0]);
    setCopReg(2,0x5000,(uint)(ushort)segMatrix->rotScale[3]);
    setCopReg(2,0x5800,(uint)(ushort)segMatrix->rotScale[6]);
    copFunction(2,0x49e012);
    uVar1 = segMatrix->rotScale[2];
    uVar4 = getCopReg(2,0x4800);
    uVar5 = getCopReg(2,0x5000);
    uVar6 = getCopReg(2,0x5800);
    setCopReg(2,0x4800,(uint)(ushort)segMatrix->rotScale[1]);
    setCopReg(2,0x5000,(uint)(ushort)segMatrix->rotScale[4]);
    setCopReg(2,0x5800,(uint)(ushort)segMatrix->rotScale[7]);
    segMatrix->rotScale[0] = (short)uVar4;
    segMatrix->rotScale[3] = (short)uVar5;
    copFunction(2,0x49e012);
    uVar4 = getCopReg(2,0x4800);
    uVar5 = getCopReg(2,0x5000);
    uVar3 = getCopReg(2,0x5800);
    setCopReg(2,0x4800,(uint)uVar1);
    setCopReg(2,0x5000,(uint)(ushort)segMatrix->rotScale[5]);
    setCopReg(2,0x5800,(uint)(ushort)segMatrix->rotScale[8]);
    segMatrix->rotScale[6] = (short)uVar6;
    segMatrix->rotScale[1] = (short)uVar4;
    copFunction(2,0x49e012);
    segMatrix->rotScale[4] = (short)uVar5;
    segMatrix->rotScale[7] = (short)uVar3;
    uVar4 = getCopReg(2,0x4800);
    uVar5 = getCopReg(2,0x5000);
    uVar3 = getCopReg(2,0x5800);
    segMatrix->rotScale[2] = (short)uVar4;
    segMatrix->rotScale[5] = (short)uVar5;
    segMatrix->rotScale[8] = (short)uVar3;
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Anim_UpdateControllers(struct _G2Anim_Type *anim /*$s1*/)
 // line 1098, offset 0x8008f244
	/* begin block 1 */
		// Start line: 1099
		// Start offset: 0x8008F244
		// Variables:
	// 		struct _G2AnimController_Type *controller; // $s0
	// 		struct _G2AnimSection_Type *section; // $v1
	// 		short elapsedTime; // $s2
	/* end block 1 */
	// End offset: 0x8008F3B8
	// End Line: 1148

	/* begin block 2 */
		// Start line: 2265
	/* end block 2 */
	// End Line: 2266

void _G2Anim_UpdateControllers(_G2Anim_Type *anim)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  _G2AnimSection_Type *p_Var4;
  _G2AnimController_Type *controller;
  
  if (anim->controllerList != 0) {
    sVar2 = G2Timer_GetFrameTime();
    controller = _controllerPool.blockPool + anim->controllerList;
    if (_controllerPool.blockPool < controller) {
      do {
        uVar1 = controller->flags;
        if ((uVar1 & 0x4000) != 0) {
          sVar3 = controller->elapsedTime + sVar2;
          if (controller->elapsedTime < controller->duration) {
            controller->elapsedTime = sVar3;
            if (controller->duration < sVar3) {
              controller->elapsedTime = controller->duration;
            }
          }
          else {
            if ((uVar1 & 0x8000) == 0) {
              if ((uVar1 & 0x2000) == 0) {
                controller->flags = uVar1 | 0x2000;
                p_Var4 = G2Anim_GetSectionWithSeg(anim,(uint)controller->segNumber);
                if ((p_Var4 != (_G2AnimSection_Type *)0x0) &&
                   (p_Var4->callback != (_func_4388 *)0x0)) {
                  (*p_Var4->callback)(anim,(uint)p_Var4->sectionID,4,(uint)controller->type,
                                      (uint)controller->segNumber,controller->callbackData);
                }
              }
            }
            else {
              controller->flags = uVar1 & 0x7fff;
              _G2AnimControllerST_RemoveFromList
                        ((uint)controller->segNumber,(uint)controller->type,&anim->controllerList);
              _G2AnimController_InsertIntoList(controller,&anim->disabledControllerList);
            }
          }
        }
        controller = _controllerPool.blockPool + controller->next;
      } while (_controllerPool.blockPool < controller);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Anim_CopyVectorWithOrder(struct _G2SVector3_Type *sourceVector /*$a0*/, struct _G2EulerAngles_Type *destVector /*$a1*/, int order /*$a2*/)
 // line 1154, offset 0x8008f3d0
	/* begin block 1 */
		// Start line: 2381
	/* end block 1 */
	// End Line: 2382

	/* begin block 2 */
		// Start line: 2384
	/* end block 2 */
	// End Line: 2385

void _G2Anim_CopyVectorWithOrder
               (_G2SVector3_Type *sourceVector,_G2EulerAngles_Type *destVector,int order)

{
  short sVar1;
  
  if (order == 1) {
    destVector->x = sourceVector->z;
    destVector->y = sourceVector->y;
    sVar1 = sourceVector->x;
    destVector->order = (short)order;
  }
  else {
    if (order != 0x15) {
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
 // line 1178, offset 0x8008f434
	/* begin block 1 */
		// Start line: 1179
		// Start offset: 0x8008F434
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
			// Start line: 1234
			// Start offset: 0x8008F5D8
			// Variables:
		// 		struct _G2Quat_Type tempQuat; // stack offset -48

			/* begin block 1.1.1 */
				// Start line: 1236
				// Start offset: 0x8008F5D8
				// Variables:
			// 		struct _G2Quat_Type *dest; // $s1

				/* begin block 1.1.1.1 */
					// Start line: 1236
					// Start offset: 0x8008F5D8
					// Variables:
				// 		unsigned long zw; // $v1
				// 		unsigned long xy; // $v0
				/* end block 1.1.1.1 */
				// End offset: 0x8008F5D8
				// End Line: 1236
			/* end block 1.1.1 */
			// End offset: 0x8008F5D8
			// End Line: 1236
		/* end block 1.1 */
		// End offset: 0x8008F5D8
		// End Line: 1236

		/* begin block 1.2 */
			// Start line: 1239
			// Start offset: 0x8008F5F4
			// Variables:
		// 		struct _G2SVector3_Type *dest; // $s1

			/* begin block 1.2.1 */
				// Start line: 1239
				// Start offset: 0x8008F5F4
				// Variables:
			// 		unsigned long mask; // $v0
			// 		unsigned short z; // $v1
			// 		unsigned long xy; // $a0
			/* end block 1.2.1 */
			// End offset: 0x8008F5F4
			// End Line: 1239
		/* end block 1.2 */
		// End offset: 0x8008F5F4
		// End Line: 1239
	/* end block 1 */
	// End offset: 0x8008F67C
	// End Line: 1257

	/* begin block 2 */
		// Start line: 2430
	/* end block 2 */
	// End Line: 2431

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
  undefined4 auStack88 [8];
  uint local_38;
  ushort local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  p_Var1 = _G2AnimSection_GetAnim(section);
  if (p_Var1->controllerList != 0) {
    uVar3 = (uint)section->firstSeg;
    controller = _controllerPool.blockPool + p_Var1->controllerList;
    segValue = &_segValues + uVar3;
    uVar6 = uVar3 + section->segCount;
    p_Var5 = p_Var1->modelData->segmentList;
    if (uVar3 < uVar6) {
      puVar4 = (undefined4 *)((int)&(&_segValues)[uVar3].rotQuat + 4);
      do {
        if ((uint)controller->segNumber == uVar3) {
          _G2Anim_BuildSegLocalRotMatrix(segValue,&_Stack152);
          if (p_Var1->segMatrices == (_G2Matrix_Type *)0x0) {
            MATH3D_SetUnityMatrix((MATRIX *)&local_78);
          }
          else {
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
          while ((uint)controller->segNumber == uVar3) {
            if ((uVar3 != 0) || ((controller->type & 2) != 0)) {
              if ((controller->type & 0x38) == 8) {
                _G2AnimController_ApplyToSegValue
                          (controller,segValue,&_Stack152,(_G2Matrix_Type *)&local_78);
                if ((controller->type & 2) == 0) {
                  TransposeMatrix((undefined4 *)(_G2Matrix_Type *)&local_78,auStack88);
                  MulMatrix2(auStack88,(uint *)&_Stack152);
                }
                if (*(ushort *)((int)puVar4 + 0x12) == 0) {
                  G2EulerAngles_FromMatrix((_G2EulerAngles_Type *)&local_38,&_Stack152,0);
                  *(ushort *)puVar4 = local_34 & 0xfff;
                  *(uint *)&segValue->rotQuat = local_38 & 0xfff0fff;
                }
                else {
                  G2EulerAngles_ToMatrix_S((undefined2 *)&local_30,(short *)&_Stack152);
                  *(undefined4 *)&segValue->rotQuat = local_30;
                  *puVar4 = local_2c;
                }
              }
              else {
                _G2AnimController_ApplyToSegValue
                          (controller,segValue,&_Stack152,(_G2Matrix_Type *)&local_78);
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



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ _G2AnimController_ApplyWorldToParentMatrix(struct _G2AnimController_Type *controller /*$a0*/, struct _G2Matrix_Type *parentMatrix /*$s0*/)
 // line 1262, offset 0x8008f6ac
	/* begin block 1 */
		// Start line: 1263
		// Start offset: 0x8008F6AC
		// Variables:
	// 		struct _G2Matrix_Type tempMatrix; // stack offset -64
	// 		struct _G2SVector3_Type tempSVector; // stack offset -32
	// 		struct _G2LVector3_Type tempLVector; // stack offset -24
	/* end block 1 */
	// End offset: 0x8008F7EC
	// End Line: 1314

	/* begin block 2 */
		// Start line: 2612
	/* end block 2 */
	// End Line: 2613

ulong _G2AnimController_ApplyWorldToParentMatrix
                (_G2AnimController_Type *controller,_G2Matrix_Type *parentMatrix)

{
  byte bVar1;
  _G2Matrix_Type _Stack64;
  _G2SVector3_Type local_20;
  int local_18;
  int local_14;
  int local_10;
  
  bVar1 = controller->type;
  if (bVar1 == 0x20) {
    _G2AnimController_GetVector(controller,&local_20);
    (parentMatrix->trans).x = (int)local_20.x;
    (parentMatrix->trans).y = (int)local_20.y;
    (parentMatrix->trans).z = (int)local_20.z;
  }
  else {
    if (bVar1 < 0x21) {
      if (bVar1 == 8) {
        _G2AnimController_GetMatrix(controller,parentMatrix);
      }
    }
    else {
      if (bVar1 == 0x54) {
        _G2AnimController_GetVector(controller,&local_20);
        local_18 = (int)local_20.x;
        local_14 = (int)local_20.y;
        local_10 = (int)local_20.z;
        ScaleMatrix((int *)parentMatrix,&local_18);
      }
      else {
        if (bVar1 < 0x55) {
          if (bVar1 == 0x4c) {
            _G2AnimController_GetMatrix(controller,&_Stack64);
            MulMatrix2((undefined4 *)&_Stack64,(uint *)parentMatrix);
          }
        }
        else {
          if (bVar1 == 100) {
            _G2AnimController_GetVector(controller,&local_20);
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



// decompiled code
// original method signature: 
// void /*$ra*/ _G2AnimController_GetMatrix(struct _G2AnimController_Type *controller /*$s0*/, struct _G2Matrix_Type *matrix /*$s1*/)
 // line 1322, offset 0x8008f800
	/* begin block 1 */
		// Start line: 1323
		// Start offset: 0x8008F800
		// Variables:
	// 		struct _G2Quat_Type tempQuat; // stack offset -24
	/* end block 1 */
	// End offset: 0x8008F8C4
	// End Line: 1373

	/* begin block 2 */
		// Start line: 2741
	/* end block 2 */
	// End Line: 2742

void _G2AnimController_GetMatrix(_G2AnimController_Type *controller,_G2Matrix_Type *matrix)

{
  ushort uVar1;
  long ratio;
  _G2Quat_Type _Stack24;
  
  uVar1 = controller->flags;
  if ((uVar1 & 0x4000) == 0) {
    if ((uVar1 & 0xff) == 1) {
      RotMatrixZYX((short *)controller->data,(uint *)matrix);
    }
    else {
      if ((uVar1 & 0xff) == 0x15) {
        RotMatrix((short *)controller->data,(uint *)matrix);
      }
    }
  }
  else {
    if ((uVar1 & 0x2000) == 0) {
      ratio = _G2AnimAlphaTable_GetValue
                        (controller->alphaTable,
                         ((int)controller->elapsedTime << 0xc) / (int)controller->duration);
      G2Quat_Slerp_VM(ratio,(_G2Quat_Type *)controller->data,(_G2Quat_Type *)(controller->data + 8),
                      &_Stack24,0);
      G2Quat_ToMatrix_S((short *)&_Stack24,(short *)matrix);
    }
    else {
      G2Quat_ToMatrix_S((short *)(controller->data + 8),(short *)matrix);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2AnimController_GetVector(struct _G2AnimController_Type *controller /*$a0*/, struct _G2SVector3_Type *vector /*$a1*/)
 // line 1378, offset 0x8008f8d8
	/* begin block 1 */
		// Start line: 1381
		// Start offset: 0x8008F8D8

		/* begin block 1.1 */
			// Start line: 1381
			// Start offset: 0x8008F8D8
			// Variables:
		// 		struct _G2SVector3_Type *dest; // $a1

			/* begin block 1.1.1 */
				// Start line: 1381
				// Start offset: 0x8008F8D8
				// Variables:
			// 		unsigned short z; // $v1
			// 		unsigned long xy; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8008F8D8
			// End Line: 1381
		/* end block 1.1 */
		// End offset: 0x8008F8D8
		// End Line: 1381

		/* begin block 1.2 */
			// Start line: 1386
			// Start offset: 0x8008F8FC
			// Variables:
		// 		struct _G2SVector3_Type *dest; // $a1
		// 		struct _G2SVector3_Type *base; // $a1
		// 		struct _G2SVector3_Type *offset; // $v0
		// 		long alpha; // $v1
		/* end block 1.2 */
		// End offset: 0x8008F958
		// End Line: 1386
	/* end block 1 */
	// End offset: 0x8008F958
	// End Line: 1391

	/* begin block 2 */
		// Start line: 2853
	/* end block 2 */
	// End Line: 2854

	/* begin block 3 */
		// Start line: 2855
	/* end block 3 */
	// End Line: 2856

void _G2AnimController_GetVector(_G2AnimController_Type *controller,_G2SVector3_Type *vector)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  sVar1 = *(short *)(controller->data + 4);
  *(undefined4 *)vector = *(undefined4 *)controller->data;
  vector->z = sVar1;
  if ((controller->flags & 0x4000) != 0) {
    setCopReg(2,0xc800,(uint)(ushort)vector->x);
    setCopReg(2,0xd000,(uint)(ushort)vector->y);
    setCopReg(2,0xd800,(uint)(ushort)vector->z);
    setCopReg(2,0x4800,(uint)*(ushort *)(controller->data + 6));
    setCopReg(2,0x5000,(uint)*(ushort *)(controller->data + 8));
    setCopReg(2,0x5800,(uint)*(ushort *)(controller->data + 10));
    setCopReg(2,0x4000,(int)controller->elapsedTime);
    copFunction(2,0x1a8003e);
    uVar2 = getCopReg(2,0xc800);
    uVar3 = getCopReg(2,0xd000);
    uVar4 = getCopReg(2,0xd800);
    vector->x = (short)uVar2;
    vector->y = (short)uVar3;
    vector->z = (short)uVar4;
  }
  return;
}



// decompiled code
// original method signature: 
// struct _G2AnimController_Type * /*$ra*/ _G2Anim_FindController(struct _G2Anim_Type *anim /*$s2*/, int segNumber /*$s0*/, int type /*$s1*/)
 // line 1397, offset 0x8008f960
	/* begin block 1 */
		// Start line: 1398
		// Start offset: 0x8008F960
		// Variables:
	// 		struct _G2AnimController_Type *controller; // $v0
	/* end block 1 */
	// End offset: 0x8008F9A4
	// End Line: 1412

	/* begin block 2 */
		// Start line: 2891
	/* end block 2 */
	// End Line: 2892

_G2AnimController_Type * _G2Anim_FindController(_G2Anim_Type *anim,int segNumber,int type)

{
  _G2AnimController_Type *p_Var1;
  
  p_Var1 = _G2AnimControllerST_FindInList(segNumber,type,&anim->controllerList);
  if (p_Var1 == (_G2AnimController_Type *)0x0) {
    p_Var1 = _G2AnimControllerST_FindInList(segNumber,type,&anim->disabledControllerList);
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct _G2AnimController_Type * /*$ra*/ _G2AnimController_Create(int segNumber /*$s1*/, int type /*$s2*/)
 // line 1476, offset 0x8008f9bc
	/* begin block 1 */
		// Start line: 1477
		// Start offset: 0x8008F9BC
		// Variables:
	// 		struct _G2AnimController_Type *controller; // $s0
	/* end block 1 */
	// End offset: 0x8008F9BC
	// End Line: 1477

	/* begin block 2 */
		// Start line: 2946
	/* end block 2 */
	// End Line: 2947

_G2AnimController_Type * _G2AnimController_Create(int segNumber,int type)

{
  _G2AnimController_Type *__s;
  
  __s = (_G2AnimController_Type *)G2PoolMem_Allocate(&_controllerPool);
  memset(__s,0,0x24);
  __s->next = 0;
  __s->segNumber = (uchar)segNumber;
  __s->type = (uchar)type;
  __s->flags = 0x15;
  return __s;
}



// decompiled code
// original method signature: 
// struct _G2AnimController_Type * /*$ra*/ _G2AnimController_Destroy(struct _G2AnimController_Type *controller /*$a1*/)
 // line 1495, offset 0x8008fa28
	/* begin block 1 */
		// Start line: 1498
		// Start offset: 0x8008FA38
		// Variables:
	// 		int nextControllerIndex; // $s0
	/* end block 1 */
	// End offset: 0x8008FA7C
	// End Line: 1511

	/* begin block 2 */
		// Start line: 3038
	/* end block 2 */
	// End Line: 3039

_G2AnimController_Type * _G2AnimController_Destroy(_G2AnimController_Type *controller)

{
  ushort uVar1;
  
  do {
    uVar1 = controller->next;
    G2PoolMem_Free(&_controllerPool,controller);
    controller = _controllerPool.blockPool + uVar1;
    if (controller <= _controllerPool.blockPool) {
      return controller;
    }
  } while (controller->type == '\0');
  return controller;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2AnimController_InsertIntoList(struct _G2AnimController_Type *controller /*$a3*/, unsigned short *listPtr /*$a1*/)
 // line 1517, offset 0x8008fa90
	/* begin block 1 */
		// Start line: 1518
		// Start offset: 0x8008FA90
		// Variables:
	// 		struct _G2AnimController_Type *testController; // $a2
	/* end block 1 */
	// End offset: 0x8008FB80
	// End Line: 1549

	/* begin block 2 */
		// Start line: 3084
	/* end block 2 */
	// End Line: 3085

void _G2AnimController_InsertIntoList(_G2AnimController_Type *controller,ushort *listPtr)

{
  _G2AnimController_Type *p_Var1;
  _G2AnimController_Type *p_Var2;
  
  p_Var2 = _controllerPool.blockPool + *listPtr;
  if (_controllerPool.blockPool < p_Var2) {
    p_Var1 = p_Var2;
    while (p_Var2 = p_Var1, p_Var1->segNumber <= controller->segNumber) {
      if (((p_Var1->segNumber == controller->segNumber) && (controller->type < p_Var1->type)) ||
         (p_Var2 = _controllerPool.blockPool + p_Var1->next, listPtr = (ushort *)p_Var1,
         p_Var1 = p_Var2, p_Var2 <= _controllerPool.blockPool)) break;
    }
  }
  ((_G2AnimController_Type *)listPtr)->next =
       (ushort)((int)((int)controller - (int)_controllerPool.blockPool) * 0x38e38e39 >> 2);
  do {
    p_Var1 = controller;
    controller = _controllerPool.blockPool + p_Var1->next;
  } while (_controllerPool.blockPool < _controllerPool.blockPool + p_Var1->next);
  p_Var1->next = (ushort)((int)((int)p_Var2 - (int)_controllerPool.blockPool) * 0x38e38e39 >> 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2AnimController_GetCurrentInterpQuat(struct _G2AnimController_Type *controller /*$s0*/, struct _G2Anim_Type *anim /*$a3*/, struct _G2Quat_Type *quat /*$s1*/)
 // line 1556, offset 0x8008fbc0
	/* begin block 1 */
		// Start line: 1557
		// Start offset: 0x8008FBC0
		// Variables:
	// 		struct _G2EulerAngles_Type eulerVector; // stack offset -24

		/* begin block 1.1 */
			// Start line: 1587
			// Start offset: 0x8008FC98
			// Variables:
		// 		struct _G2Quat_Type *quat; // $s1
		/* end block 1.1 */
		// End offset: 0x8008FC98
		// End Line: 1587
	/* end block 1 */
	// End offset: 0x8008FCE8
	// End Line: 1605

	/* begin block 2 */
		// Start line: 3162
	/* end block 2 */
	// End Line: 3163

void _G2AnimController_GetCurrentInterpQuat
               (_G2AnimController_Type *controller,_G2Anim_Type *anim,_G2Quat_Type *quat)

{
  uchar uVar1;
  ushort uVar2;
  long ratio;
  undefined4 uVar3;
  _G2EulerAngles_Type _Stack24;
  
  uVar2 = controller->flags;
  if ((uVar2 & 0x4000) == 0) {
    uVar1 = controller->type;
    if (uVar1 == '\b') {
      G2EulerAngles_ToMatrix_S
                ((undefined2 *)quat,(short *)(anim->segMatrices + controller->segNumber));
    }
    else {
      if (uVar1 == 'L') {
        *(undefined4 *)quat = 0;
        *(undefined4 *)&quat->z = 0x10000000;
      }
      else {
        if (uVar1 == '\x0e') {
          _G2Anim_CopyVectorWithOrder
                    ((_G2SVector3_Type *)controller->data,&_Stack24,(uint)uVar2 & 0xff);
        }
        else {
          G2Anim_GetSegChannelValue(anim,(uint)controller->segNumber,(ushort *)&_Stack24,7);
          _Stack24.order = 0;
        }
        G2Quat_FromEuler_S((int)quat,(short *)&_Stack24);
      }
    }
  }
  else {
    if ((uVar2 & 0x2000) == 0) {
      ratio = _G2AnimAlphaTable_GetValue
                        (controller->alphaTable,
                         ((int)controller->elapsedTime << 0xc) / (int)controller->duration);
      G2Quat_Slerp_VM(ratio,(_G2Quat_Type *)controller->data,(_G2Quat_Type *)(controller->data + 8),
                      quat,0);
    }
    else {
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
 // line 1611, offset 0x8008fcfc
	/* begin block 1 */
		// Start line: 1612
		// Start offset: 0x8008FCFC
		// Variables:
	// 		struct _Segment *segment; // $v0
	// 		struct _G2Matrix_Type *parentMatrix; // $s0
	// 		struct _G2Matrix_Type segMatrix; // stack offset -48
	// 		int segNumber; // $v0
	/* end block 1 */
	// End offset: 0x8008FCFC
	// End Line: 1612

	/* begin block 2 */
		// Start line: 3272
	/* end block 2 */
	// End Line: 3273

void _G2AnimController_GetSimpleWorldRotQuat
               (_G2AnimController_Type *controller,_G2Anim_Type *anim,_G2Quat_Type *quat)

{
  short sVar1;
  _G2Matrix_Type *p_Var2;
  _G2Matrix_Type _Stack48;
  
  p_Var2 = anim->segMatrices;
  sVar1 = anim->modelData->segmentList[controller->segNumber].parent;
  _G2Anim_BuildSegLocalRotMatrix(&_segValues + controller->segNumber,&_Stack48);
  MulMatrix2((undefined4 *)(p_Var2 + sVar1),(uint *)&_Stack48);
  G2EulerAngles_ToMatrix_S((undefined2 *)quat,(short *)&_Stack48);
  return;
}



// decompiled code
// original method signature: 
// struct _G2AnimController_Type * /*$ra*/ _G2AnimControllerST_FindInList(int segNumber /*$a0*/, int type /*$a1*/, unsigned short *listPtr /*$a2*/)
 // line 1641, offset 0x8008fd80
	/* begin block 1 */
		// Start line: 1644
		// Start offset: 0x8008FD80
		// Variables:
	// 		struct _G2AnimController_Type *controller; // $a2
	/* end block 1 */
	// End offset: 0x8008FDE8
	// End Line: 1659

	/* begin block 2 */
		// Start line: 3360
	/* end block 2 */
	// End Line: 3361

	/* begin block 3 */
		// Start line: 3362
	/* end block 3 */
	// End Line: 3363

	/* begin block 4 */
		// Start line: 3364
	/* end block 4 */
	// End Line: 3365

_G2AnimController_Type * _G2AnimControllerST_FindInList(int segNumber,int type,ushort *listPtr)

{
  ushort uVar1;
  _G2AnimController_Type *p_Var2;
  _G2AnimController_Type *p_Var3;
  
  uVar1 = *listPtr;
  while ((p_Var3 = _controllerPool.blockPool + uVar1, _controllerPool.blockPool < p_Var3 &&
         (((uint)p_Var3->segNumber != segNumber || ((uint)p_Var3->type != type))))) {
    uVar1 = p_Var3->next;
  }
  p_Var2 = (_G2AnimController_Type *)0x0;
  if (p_Var3 != _controllerPool.blockPool) {
    p_Var2 = p_Var3;
  }
  return p_Var2;
}



// decompiled code
// original method signature: 
// struct _G2AnimController_Type * /*$ra*/ _G2AnimControllerST_FindPtrInList(int segNumber /*$a0*/, int type /*$a1*/, unsigned short **listPtrPtr /*$a2*/)
 // line 1665, offset 0x8008fdf0
	/* begin block 1 */
		// Start line: 1668
		// Start offset: 0x8008FDF0
		// Variables:
	// 		struct _G2AnimController_Type *controller; // $a3
	/* end block 1 */
	// End offset: 0x8008FE80
	// End Line: 1689

	/* begin block 2 */
		// Start line: 3408
	/* end block 2 */
	// End Line: 3409

	/* begin block 3 */
		// Start line: 3410
	/* end block 3 */
	// End Line: 3411

	/* begin block 4 */
		// Start line: 3415
	/* end block 4 */
	// End Line: 3416

_G2AnimController_Type *
_G2AnimControllerST_FindPtrInList(int segNumber,int type,ushort **listPtrPtr)

{
  _G2AnimController_Type *p_Var1;
  
  p_Var1 = _controllerPool.blockPool + **listPtrPtr;
  if (_controllerPool.blockPool < p_Var1) {
    do {
      if (((uint)p_Var1->segNumber == segNumber) && ((uint)p_Var1->type == type)) break;
      *(_G2AnimController_Type **)listPtrPtr = p_Var1;
      p_Var1 = _controllerPool.blockPool + p_Var1->next;
    } while (_controllerPool.blockPool < p_Var1);
  }
  if (p_Var1 == _controllerPool.blockPool) {
    *listPtrPtr = (ushort *)0x0;
    return (_G2AnimController_Type *)0x0;
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct _G2AnimController_Type * /*$ra*/ _G2AnimControllerST_RemoveFromList(int segNumber /*$a0*/, int type /*$a1*/, unsigned short *listPtr /*$a2*/)
 // line 1726, offset 0x8008fe90
	/* begin block 1 */
		// Start line: 1729
		// Start offset: 0x8008FE90
		// Variables:
	// 		struct _G2AnimController_Type *controller; // $a3
	// 		struct _G2AnimController_Type *stepController; // $a1
	// 		struct _G2AnimController_Type *nextController; // $a0
	/* end block 1 */
	// End offset: 0x8008FF58
	// End Line: 1758

	/* begin block 2 */
		// Start line: 3445
	/* end block 2 */
	// End Line: 3446

	/* begin block 3 */
		// Start line: 3494
	/* end block 3 */
	// End Line: 3495

	/* begin block 4 */
		// Start line: 3498
	/* end block 4 */
	// End Line: 3499

_G2AnimController_Type * _G2AnimControllerST_RemoveFromList(int segNumber,int type,ushort *listPtr)

{
  ushort uVar1;
  _G2AnimController_Type *p_Var2;
  _G2AnimController_Type *p_Var3;
  _G2AnimController_Type *p_Var4;
  
  p_Var3 = _controllerPool.blockPool + *listPtr;
  if (_controllerPool.blockPool < _controllerPool.blockPool + *listPtr) {
    do {
      if (((uint)p_Var3->segNumber == segNumber) && (p_Var4 = p_Var3, (uint)p_Var3->type == type))
      break;
      p_Var4 = _controllerPool.blockPool + p_Var3->next;
      listPtr = (ushort *)p_Var3;
      p_Var3 = p_Var4;
    } while (_controllerPool.blockPool < p_Var4);
    p_Var3 = p_Var4;
    if (_controllerPool.blockPool < p_Var4) {
      do {
        p_Var2 = p_Var3;
        p_Var3 = _controllerPool.blockPool;
        uVar1 = p_Var2->next;
        ((_G2AnimController_Type *)listPtr)->next = uVar1;
        p_Var3 = p_Var3 + uVar1;
        if (p_Var3 <= _controllerPool.blockPool) break;
      } while (p_Var3->type == '\0');
      p_Var2->next = 0;
      return p_Var4;
    }
  }
  return (_G2AnimController_Type *)0x0;
}





