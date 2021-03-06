#include "THISDUST.H"
#include "SCRIPT.H"


// decompiled code
// original method signature: 
// void /*$ra*/ SCRIPT_CombineEulerAngles(struct _Rotation *combinedRotation /*$s1*/, struct _Rotation *inputRotation1 /*$a1*/, struct _Rotation *inputRotation2 /*$s0*/)
 // line 51, offset 0x8003ccbc
	/* begin block 1 */
		// Start line: 52
		// Start offset: 0x8003CCBC
		// Variables:
	// 		struct MATRIX rotMatrix1; // stack offset -88
	// 		struct MATRIX rotMatrix2; // stack offset -56
	// 		struct _G2EulerAngles_Type ea; // stack offset -24

		/* begin block 1.1 */
			// Start line: 52
			// Start offset: 0x8003CCBC
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.1 */
		// End offset: 0x8003CCBC
		// End Line: 52
	/* end block 1 */
	// End offset: 0x8003CCBC
	// End Line: 52

	/* begin block 2 */
		// Start line: 102
	/* end block 2 */
	// End Line: 103

void SCRIPT_CombineEulerAngles
               (_Rotation *combinedRotation,_Rotation *inputRotation1,_Rotation *inputRotation2)

{
  _G2Matrix_Type _Stack88;
  uint auStack56 [8];
  _G2EulerAngles_Type local_18;
  
  RotMatrix((ushort *)inputRotation1,(uint *)&_Stack88);
  RotMatrix((ushort *)inputRotation2,auStack56);
  MulMatrix2(auStack56,(uint *)&_Stack88);
  G2EulerAngles_FromMatrix(&local_18,&_Stack88,0x15);
  combinedRotation->x = local_18.x;
  combinedRotation->y = local_18.y;
  combinedRotation->z = local_18.z;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SCRIPT_InstanceSplineInit(struct _Instance *instance /*$s2*/)
 // line 163, offset 0x8003cd3c
	/* begin block 1 */
		// Start line: 164
		// Start offset: 0x8003CD3C
		// Variables:
	// 		struct Spline *spline; // $s3
	// 		struct RSpline *rspline; // $a0
	// 		struct Spline *sspline; // $s4
	// 		struct MultiSpline *multi; // $s0
	// 		struct SplineDef *sd; // $s5
	// 		struct SplineDef *rsd; // $s1
	// 		struct SplineDef *ssd; // $s6
	// 		unsigned long isParent; // stack offset -40
	// 		unsigned long isClass; // stack offset -36

		/* begin block 1.1 */
			// Start line: 187
			// Start offset: 0x8003CDD0
			// Variables:
		// 		struct _G2Quat_Type *q; // $a0
		// 		struct _G2EulerAngles_Type ea; // stack offset -80

			/* begin block 1.1.1 */
				// Start line: 195
				// Start offset: 0x8003CDF8
				// Variables:
			// 		struct MATRIX introTransform; // stack offset -72
			/* end block 1.1.1 */
			// End offset: 0x8003CE30
			// End Line: 204

			/* begin block 1.1.2 */
				// Start line: 209
				// Start offset: 0x8003CE44
				// Variables:
			// 		struct _Rotation combinedRotation; // stack offset -72

				/* begin block 1.1.2.1 */
					// Start line: 209
					// Start offset: 0x8003CE44
					// Variables:
				// 		short _x1; // $v0
				// 		short _y1; // $v1
				// 		short _z1; // $a0
				/* end block 1.1.2.1 */
				// End offset: 0x8003CE9C
				// End Line: 220
			/* end block 1.1.2 */
			// End offset: 0x8003CE9C
			// End Line: 221
		/* end block 1.1 */
		// End offset: 0x8003CE9C
		// End Line: 223

		/* begin block 1.2 */
			// Start line: 227
			// Start offset: 0x8003CEA4
			// Variables:
		// 		struct _SVector *start_point; // $a3

			/* begin block 1.2.1 */
				// Start line: 235
				// Start offset: 0x8003CEC8
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $a0
			// 		short _z0; // $v1
			// 		short _x1; // $a1
			// 		short _y1; // $a2
			// 		short _z1; // $a3
			// 		struct _Position *_v; // $v0
			// 		struct _Position *_v0; // $v1
			/* end block 1.2.1 */
			// End offset: 0x8003CEC8
			// End Line: 235
		/* end block 1.2 */
		// End offset: 0x8003CF24
		// End Line: 244

		/* begin block 1.3 */
			// Start line: 248
			// Start offset: 0x8003CF2C
			// Variables:
		// 		struct _SVector *start_point; // $v1
		/* end block 1.3 */
		// End offset: 0x8003CF64
		// End Line: 258
	/* end block 1 */
	// End offset: 0x8003CF64
	// End Line: 259

	/* begin block 2 */
		// Start line: 326
	/* end block 2 */
	// End Line: 327

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
  _Rotation local_48 [4];
  ulong local_28;
  ulong local_24;
  
  multi = SCRIPT_GetMultiSpline(instance,&local_28,&local_24);
  if (multi != (MultiSpline *)0x0) {
    def = SCRIPT_GetPosSplineDef(instance,multi,local_28,local_24);
    def_00 = SCRIPT_GetRotSplineDef(instance,multi,local_28,local_24);
    def_01 = SCRIPT_GetScaleSplineDef(instance,multi,local_28,local_24);
    spline = multi->positional;
    spline_00 = multi->scaling;
    if (multi->rotational != (RSpline *)0x0) {
      quat = SplineGetFirstRot(multi->rotational,def_00);
      if ((local_28 == 0) && (local_24 == 0)) {
        pMVar7 = &multi->curRotMatrix;
        G2Quat_ToMatrix_S((short *)quat,(short *)pMVar7);
        if (instance->intro != (Intro *)0x0) {
          RotMatrix((ushort *)&instance->intro->rotation,(uint *)local_48);
          MulMatrix0((undefined4 *)pMVar7,(ushort *)local_48,(uint *)pMVar7);
        }
        instance->flags = instance->flags | 1;
      }
      else {
        G2Quat_ToEuler(quat,&local_50,0);
        pIVar6 = instance->intro;
        (instance->rotation).x = local_50.x;
        (instance->rotation).y = local_50.y;
        (instance->rotation).z = local_50.z;
        SCRIPT_CombineEulerAngles(local_48,&instance->rotation,&pIVar6->rotation);
        (instance->rotation).x = local_48[0].x;
        (instance->rotation).y = local_48[0].y;
        (instance->rotation).z = local_48[0].z;
      }
    }
    if ((spline != (Spline *)0x0) &&
       (p_Var5 = SplineGetFirstPoint(spline,def), p_Var5 != (_SVector *)0x0)) {
      if (local_24 == 0) {
        (instance->position).x = p_Var5->x;
        (instance->position).y = p_Var5->y;
        (instance->position).z = p_Var5->z;
      }
      else {
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
       (p_Var5 = SplineGetFirstPoint(spline_00,def_01), p_Var5 != (_SVector *)0x0)) {
      (instance->scale).x = p_Var5->x;
      (instance->scale).y = p_Var5->y;
      (instance->scale).z = p_Var5->z;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ SCRIPTCountFramesInSpline(struct _Instance *instance /*$s4*/)
 // line 266, offset 0x8003cf8c
	/* begin block 1 */
		// Start line: 267
		// Start offset: 0x8003CF8C
		// Variables:
	// 		short kf; // $s3
	// 		short frames; // $s2
	// 		struct SplineKey *key; // $a0
	// 		struct Spline *spline; // $s0
	// 		struct RSpline *rspline; // $s1

		/* begin block 1.1 */
			// Start line: 282
			// Start offset: 0x8003D018
			// Variables:
		// 		struct SplineRotKey *rkey; // $a0
		/* end block 1.1 */
		// End offset: 0x8003D054
		// End Line: 288

		/* begin block 1.2 */
			// Start line: 291
			// Start offset: 0x8003D05C
			// Variables:
		// 		struct MultiSpline *multi; // $v0
		/* end block 1.2 */
		// End offset: 0x8003D0B4
		// End Line: 300
	/* end block 1 */
	// End offset: 0x8003D0B4
	// End Line: 302

	/* begin block 2 */
		// Start line: 468
	/* end block 2 */
	// End Line: 469

short SCRIPTCountFramesInSpline(_Instance *instance)

{
  ushort *puVar1;
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
  if (pSVar2 == (Spline *)0x0) {
    pRVar3 = ScriptGetRotSpline(instance);
    if (pRVar3 == (RSpline *)0x0) {
      pMVar4 = SCRIPT_GetMultiSpline(instance,(ulong *)0x0,(ulong *)0x0);
      if (pMVar4 != (MultiSpline *)0x0) {
        iVar6 = (int)pMVar4->scaling->numkeys;
        pSVar7 = pMVar4->scaling->key;
        sVar5 = 0;
        if (0 < iVar6) {
          do {
            iVar10 = iVar10 + 1;
            puVar1 = (ushort *)&pSVar7->count;
            pSVar7 = pSVar7 + 1;
            iVar9 = iVar9 + (uint)*puVar1;
            sVar5 = (short)iVar9;
          } while (iVar10 * 0x10000 >> 0x10 < iVar6);
        }
      }
    }
    else {
      pSVar8 = pRVar3->key;
      sVar5 = 0;
      if (0 < (int)pRVar3->numkeys) {
        do {
          iVar10 = iVar10 + 1;
          puVar1 = (ushort *)&pSVar8->count;
          pSVar8 = pSVar8 + 1;
          iVar9 = iVar9 + (uint)*puVar1;
        } while (iVar10 * 0x10000 >> 0x10 < (int)pRVar3->numkeys);
        sVar5 = (short)((uint)(iVar9 * 0x10000) >> 0x10);
      }
    }
  }
  else {
    pSVar7 = pSVar2->key;
    if (0 < (int)pSVar2->numkeys) {
      do {
        iVar10 = iVar10 + 1;
        puVar1 = (ushort *)&pSVar7->count;
        pSVar7 = pSVar7 + 1;
        iVar9 = iVar9 + (uint)*puVar1;
      } while (iVar10 * 0x10000 >> 0x10 < (int)pSVar2->numkeys);
      sVar5 = (short)((uint)(iVar9 * 0x10000) >> 0x10);
    }
  }
  return sVar5;
}



// decompiled code
// original method signature: 
// struct Spline * /*$ra*/ ScriptGetPosSpline(struct _Instance *instance /*$a0*/)
 // line 317, offset 0x8003d0dc
	/* begin block 1 */
		// Start line: 318
		// Start offset: 0x8003D0DC
		// Variables:
	// 		struct MultiSpline *multi; // $v0
	/* end block 1 */
	// End offset: 0x8003D104
	// End Line: 325

	/* begin block 2 */
		// Start line: 579
	/* end block 2 */
	// End Line: 580

Spline * ScriptGetPosSpline(_Instance *instance)

{
  MultiSpline *pMVar1;
  Spline *pSVar2;
  
  pMVar1 = SCRIPT_GetMultiSpline(instance,(ulong *)0x0,(ulong *)0x0);
  if (pMVar1 == (MultiSpline *)0x0) {
    pSVar2 = (Spline *)0x0;
  }
  else {
    pSVar2 = pMVar1->positional;
  }
  return pSVar2;
}



// decompiled code
// original method signature: 
// struct RSpline * /*$ra*/ ScriptGetRotSpline(struct _Instance *instance /*$a0*/)
 // line 326, offset 0x8003d114
	/* begin block 1 */
		// Start line: 327
		// Start offset: 0x8003D114
		// Variables:
	// 		struct MultiSpline *multi; // $v0
	/* end block 1 */
	// End offset: 0x8003D13C
	// End Line: 334

	/* begin block 2 */
		// Start line: 598
	/* end block 2 */
	// End Line: 599

RSpline * ScriptGetRotSpline(_Instance *instance)

{
  MultiSpline *pMVar1;
  RSpline *pRVar2;
  
  pMVar1 = SCRIPT_GetMultiSpline(instance,(ulong *)0x0,(ulong *)0x0);
  if (pMVar1 == (MultiSpline *)0x0) {
    pRVar2 = (RSpline *)0x0;
  }
  else {
    pRVar2 = pMVar1->rotational;
  }
  return pRVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SCRIPT_GetSplineFrameNumber(struct _Instance *instance /*$s0*/, struct SplineDef *splineDef /*$s1*/)
 // line 338, offset 0x8003d14c
	/* begin block 1 */
		// Start line: 623
	/* end block 1 */
	// End Line: 624

int SCRIPT_GetSplineFrameNumber(_Instance *instance,SplineDef *splineDef)

{
  ushort uVar1;
  Spline *spline;
  
  spline = ScriptGetPosSpline(instance);
  if (spline == (Spline *)0x0) {
    spline = (Spline *)ScriptGetRotSpline(instance);
  }
  else {
    spline = ScriptGetPosSpline(instance);
  }
  uVar1 = SplineGetFrameNumber(spline,splineDef);
  return (uint)uVar1;
}



// decompiled code
// original method signature: 
// struct MultiSpline * /*$ra*/ SCRIPT_GetMultiSpline(struct _Instance *instance /*$a0*/, unsigned long *isParent /*$a1*/, unsigned long *isClass /*$a2*/)
 // line 346, offset 0x8003d1ac
	/* begin block 1 */
		// Start line: 348
		// Start offset: 0x8003D1AC
		// Variables:
	// 		struct MultiSpline *multi; // $a3
	/* end block 1 */
	// End offset: 0x8003D250
	// End Line: 373

	/* begin block 2 */
		// Start line: 635
	/* end block 2 */
	// End Line: 636

	/* begin block 3 */
		// Start line: 640
	/* end block 3 */
	// End Line: 641

	/* begin block 4 */
		// Start line: 641
	/* end block 4 */
	// End Line: 642

	/* begin block 5 */
		// Start line: 642
	/* end block 5 */
	// End Line: 643

MultiSpline * SCRIPT_GetMultiSpline(_Instance *instance,ulong *isParent,ulong *isClass)

{
  MultiSpline *pMVar1;
  _Model *p_Var2;
  MultiSpline *pMVar3;
  
  pMVar3 = (MultiSpline *)0x0;
  if (isParent != (ulong *)0x0) {
    *isParent = 0;
  }
  if (isClass != (ulong *)0x0) {
    *isClass = 0;
  }
  if ((((instance != (_Instance *)0x0) && (instance->intro != (Intro *)0x0)) &&
      (pMVar1 = instance->intro->multiSpline, pMVar1 != (MultiSpline *)0x0)) &&
     ((pMVar3 = pMVar1, (instance->flags & 0x100002U) == 2 && (isParent != (ulong *)0x0)))) {
    *isParent = 1;
  }
  if (((pMVar3 == (MultiSpline *)0x0) &&
      (p_Var2 = *instance->object->modelList, p_Var2 != (_Model *)0x0)) &&
     (pMVar3 = p_Var2->multiSpline, isClass != (ulong *)0x0)) {
    *isClass = 1;
  }
  return pMVar3;
}



// decompiled code
// original method signature: 
// struct SplineDef * /*$ra*/ SCRIPT_GetPosSplineDef(struct _Instance *instance /*$a0*/, struct MultiSpline *multi /*$a1*/, unsigned long isParent /*$a2*/, unsigned long isClass /*$a3*/)
 // line 376, offset 0x8003d258
	/* begin block 1 */
		// Start line: 377
		// Start offset: 0x8003D258
		// Variables:
	// 		struct SplineDef *splineDef; // $v0
	/* end block 1 */
	// End offset: 0x8003D27C
	// End Line: 386

	/* begin block 2 */
		// Start line: 700
	/* end block 2 */
	// End Line: 701

	/* begin block 3 */
		// Start line: 702
	/* end block 3 */
	// End Line: 703

SplineDef *
SCRIPT_GetPosSplineDef(_Instance *instance,MultiSpline *multi,ulong isParent,ulong isClass)

{
  SplineDef *pSVar1;
  
  if ((isParent == 0) && (isClass == 0)) {
    pSVar1 = (SplineDef *)0x0;
    if (multi != (MultiSpline *)0x0) {
      pSVar1 = &multi->curPositional;
    }
    return pSVar1;
  }
  return (SplineDef *)&instance->work0;
}



// decompiled code
// original method signature: 
// struct SplineDef * /*$ra*/ SCRIPT_GetRotSplineDef(struct _Instance *instance /*$a0*/, struct MultiSpline *multi /*$a1*/, unsigned long isParent /*$a2*/, unsigned long isClass /*$a3*/)
 // line 388, offset 0x8003d284
	/* begin block 1 */
		// Start line: 389
		// Start offset: 0x8003D284
		// Variables:
	// 		struct SplineDef *splineDef; // $v0
	/* end block 1 */
	// End offset: 0x8003D2A8
	// End Line: 398

	/* begin block 2 */
		// Start line: 724
	/* end block 2 */
	// End Line: 725

	/* begin block 3 */
		// Start line: 726
	/* end block 3 */
	// End Line: 727

SplineDef *
SCRIPT_GetRotSplineDef(_Instance *instance,MultiSpline *multi,ulong isParent,ulong isClass)

{
  SplineDef *pSVar1;
  
  if ((isParent == 0) && (isClass == 0)) {
    pSVar1 = (SplineDef *)0x0;
    if (multi != (MultiSpline *)0x0) {
      pSVar1 = &multi->curRotational;
    }
    return pSVar1;
  }
  return (SplineDef *)&instance->work2;
}



// decompiled code
// original method signature: 
// struct SplineDef * /*$ra*/ SCRIPT_GetScaleSplineDef(struct _Instance *instance /*$a0*/, struct MultiSpline *multi /*$a1*/, unsigned long isParent /*$a2*/, unsigned long isClass /*$a3*/)
 // line 400, offset 0x8003d2b0
	/* begin block 1 */
		// Start line: 401
		// Start offset: 0x8003D2B0
		// Variables:
	// 		struct SplineDef *splineDef; // $v0
	/* end block 1 */
	// End offset: 0x8003D2D4
	// End Line: 410

	/* begin block 2 */
		// Start line: 748
	/* end block 2 */
	// End Line: 749

	/* begin block 3 */
		// Start line: 750
	/* end block 3 */
	// End Line: 751

SplineDef *
SCRIPT_GetScaleSplineDef(_Instance *instance,MultiSpline *multi,ulong isParent,ulong isClass)

{
  SplineDef *pSVar1;
  
  if ((isParent == 0) && (isClass == 0)) {
    pSVar1 = (SplineDef *)0x0;
    if (multi != (MultiSpline *)0x0) {
      pSVar1 = &multi->curScaling;
    }
    return pSVar1;
  }
  return (SplineDef *)&instance->work4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SCRIPT_RelativisticSpline(struct _Instance *instance /*$s0*/, struct _SVector *point /*$a3*/)
 // line 412, offset 0x8003d2dc
	/* begin block 1 */
		// Start line: 413
		// Start offset: 0x8003D2DC
		// Variables:
	// 		struct _SVector pt; // stack offset -64

		/* begin block 1.1 */
			// Start line: 423
			// Start offset: 0x8003D31C
			// Variables:
		// 		struct MATRIX segMatrix; // stack offset -56
		// 		struct _Position newPt; // stack offset -24
		// 		struct _Position localPt; // stack offset -16

			/* begin block 1.1.1 */
				// Start line: 426
				// Start offset: 0x8003D31C
				// Variables:
			// 		short _x1; // $a1
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			// 		struct _SVector *_v0; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8003D31C
			// End Line: 426

			/* begin block 1.1.2 */
				// Start line: 426
				// Start offset: 0x8003D31C
				// Variables:
			// 		short _y0; // $v1
			// 		short _z0; // $v0
			// 		short _x1; // $a1
			// 		short _y1; // $a3
			// 		short _z1; // $a2
			// 		struct _Position *_v; // $a0
			// 		struct _Position *_v0; // $v0
			// 		struct _Position *_v1; // $a2
			/* end block 1.1.2 */
			// End offset: 0x8003D31C
			// End Line: 426
		/* end block 1.1 */
		// End offset: 0x8003D31C
		// End Line: 426

		/* begin block 1.2 */
			// Start line: 440
			// Start offset: 0x8003D484
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $a0
		// 		short _z0; // $v1
		// 		short _x1; // $a1
		// 		short _y1; // $a2
		// 		short _z1; // $a3
		// 		struct _Position *_v; // $v0
		// 		struct _Position *_v0; // $v1
		/* end block 1.2 */
		// End offset: 0x8003D4BC
		// End Line: 440
	/* end block 1 */
	// End offset: 0x8003D4BC
	// End Line: 442

	/* begin block 2 */
		// Start line: 772
	/* end block 2 */
	// End Line: 773

void SCRIPT_RelativisticSpline(_Instance *instance,_SVector *point)

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
  else {
    local_10 = point->x;
    local_e = point->y;
    local_c = point->z;
    RotMatrix((ushort *)&instance->intro->rotation,(uint *)&local_38);
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



// decompiled code
// original method signature: 
// void /*$ra*/ SCRIPT_InstanceSplineSet(struct _Instance *instance /*$s2*/, short frameNum /*$fp*/, struct SplineDef *splineDef /*$s4*/, struct SplineDef *rsplineDef /*$s5*/, struct SplineDef *ssplineDef /*stack 16*/)
 // line 444, offset 0x8003d4cc
	/* begin block 1 */
		// Start line: 445
		// Start offset: 0x8003D4CC
		// Variables:
	// 		struct Spline *spline; // $s0
	// 		struct RSpline *rspline; // $s3
	// 		struct Spline *sspline; // $s7
	// 		struct MultiSpline *multi; // $s1
	// 		unsigned long isClass; // stack offset -44
	// 		unsigned long isParent; // stack offset -48
	// 		struct _SVector point; // stack offset -96

		/* begin block 1.1 */
			// Start line: 506
			// Start offset: 0x8003D670
			// Variables:
		// 		struct _G2Quat_Type q; // stack offset -88

			/* begin block 1.1.1 */
				// Start line: 509
				// Start offset: 0x8003D688
				// Variables:
			// 		struct MATRIX introTransform; // stack offset -80
			/* end block 1.1.1 */
			// End offset: 0x8003D6A4
			// End Line: 515
		/* end block 1.1 */
		// End offset: 0x8003D6A4
		// End Line: 515

		/* begin block 1.2 */
			// Start line: 523
			// Start offset: 0x8003D6C8
			// Variables:
		// 		struct _Rotation rot; // stack offset -88

			/* begin block 1.2.1 */
				// Start line: 527
				// Start offset: 0x8003D6DC
				// Variables:
			// 		struct _Rotation combinedRotation; // stack offset -80

				/* begin block 1.2.1.1 */
					// Start line: 527
					// Start offset: 0x8003D6DC
					// Variables:
				// 		short _x1; // $v0
				// 		short _y1; // $v1
				// 		short _z1; // $a0
				/* end block 1.2.1.1 */
				// End offset: 0x8003D724
				// End Line: 537
			/* end block 1.2.1 */
			// End offset: 0x8003D724
			// End Line: 538
		/* end block 1.2 */
		// End offset: 0x8003D724
		// End Line: 540

		/* begin block 1.3 */
			// Start line: 544
			// Start offset: 0x8003D734
			// Variables:
		// 		struct _SVector scale; // stack offset -88
		/* end block 1.3 */
		// End offset: 0x8003D774
		// End Line: 552
	/* end block 1 */
	// End offset: 0x8003D774
	// End Line: 554

	/* begin block 2 */
		// Start line: 840
	/* end block 2 */
	// End Line: 841

void SCRIPT_InstanceSplineSet
               (_Instance *instance,short frameNum,SplineDef *splineDef,SplineDef *rsplineDef,
               SplineDef *ssplineDef)

{
  MultiSpline *multi;
  ulong uVar1;
  Intro *pIVar2;
  Spline *spline;
  MATRIX *pMVar3;
  Spline *spline_00;
  Spline *spline_01;
  _SVector local_60;
  short local_58;
  short local_56;
  short local_54;
  _Rotation local_50 [4];
  ulong local_30;
  ulong local_2c;
  
  multi = SCRIPT_GetMultiSpline(instance,&local_30,&local_2c);
  if (multi != (MultiSpline *)0x0) {
    if (frameNum == -1) {
      frameNum = SCRIPTCountFramesInSpline(instance);
    }
    if (((local_30 != 0) || (local_2c != 0)) ||
       ((splineDef == (SplineDef *)0x0 &&
        ((rsplineDef == (SplineDef *)0x0 && (ssplineDef == (SplineDef *)0x0)))))) {
      splineDef = SCRIPT_GetPosSplineDef(instance,multi,local_30,local_2c);
      rsplineDef = SCRIPT_GetRotSplineDef(instance,multi,local_30,local_2c);
      ssplineDef = SCRIPT_GetScaleSplineDef(instance,multi,local_30,local_2c);
    }
    spline = multi->positional;
    spline_00 = (Spline *)multi->rotational;
    spline_01 = multi->scaling;
    if ((splineDef != (SplineDef *)0x0) && (spline != (Spline *)0x0)) {
      SplineSetDef2FrameNumber(spline,splineDef,frameNum);
      SplineGetData(spline,splineDef,&local_60);
      if (local_2c == 0) {
        (instance->position).x = local_60.x;
        (instance->position).y = local_60.y;
        (instance->position).z = local_60.z;
      }
      else {
        SCRIPT_RelativisticSpline(instance,&local_60);
      }
    }
    if ((rsplineDef != (SplineDef *)0x0) && (spline_00 != (Spline *)0x0)) {
      SplineSetDef2FrameNumber(spline_00,rsplineDef,frameNum);
      if ((instance->flags & 1U) == 0) {
        uVar1 = SplineGetData(spline_00,rsplineDef,&local_58);
        if (uVar1 != 0) {
          pIVar2 = instance->intro;
          (instance->rotation).x = local_58;
          (instance->rotation).y = local_56;
          (instance->rotation).z = local_54;
          SCRIPT_CombineEulerAngles(local_50,&instance->rotation,&pIVar2->rotation);
          (instance->rotation).x = local_50[0].x;
          (instance->rotation).y = local_50[0].y;
          (instance->rotation).z = local_50[0].z;
        }
      }
      else {
        uVar1 = SplineGetQuatData(spline_00,rsplineDef,&local_58);
        if (uVar1 != 0) {
          pMVar3 = &multi->curRotMatrix;
          G2Quat_ToMatrix_S(&local_58,(short *)pMVar3);
          if (instance->intro != (Intro *)0x0) {
            RotMatrix((ushort *)&instance->intro->rotation,(uint *)local_50);
            MulMatrix0((undefined4 *)pMVar3,(ushort *)local_50,(uint *)pMVar3);
          }
        }
      }
    }
    if ((ssplineDef != (SplineDef *)0x0) && (spline_01 != (Spline *)0x0)) {
      SplineSetDef2FrameNumber(spline_01,ssplineDef,frameNum);
      SplineGetData(spline_01,ssplineDef,&local_58);
      (instance->scale).x = local_58;
      (instance->scale).y = local_54;
      (instance->scale).z = local_56;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SCRIPT_SplineProcess(struct _Instance *instance /*$s4*/, struct MultiSpline *multi /*$fp*/, struct SplineDef *splineDef /*stack 8*/, struct SplineDef *rsplineDef /*$s7*/, struct SplineDef *ssplineDef /*stack 16*/, int direction /*stack 20*/, int isClass /*stack 24*/)
 // line 556, offset 0x8003d7a4
	/* begin block 1 */
		// Start line: 557
		// Start offset: 0x8003D7A4
		// Variables:
	// 		long retVal; // $s3
	// 		struct Spline *spline; // $s5
	// 		struct RSpline *rspline; // $s1
	// 		struct Spline *sspline; // $a0
	// 		struct _SVector *point; // $s2
	// 		struct _Rotation rot; // stack offset -96
	// 		long timeOff; // $s6

		/* begin block 1.1 */
			// Start line: 574
			// Start offset: 0x8003D800
			// Variables:
		// 		struct _SVector pt; // stack offset -88
		/* end block 1.1 */
		// End offset: 0x8003D87C
		// End Line: 594

		/* begin block 1.2 */
			// Start line: 617
			// Start offset: 0x8003D8E8
			// Variables:
		// 		struct _G2Quat_Type q; // stack offset -80

			/* begin block 1.2.1 */
				// Start line: 620
				// Start offset: 0x8003D900
				// Variables:
			// 		struct MATRIX introTransform; // stack offset -72
			/* end block 1.2.1 */
			// End offset: 0x8003D91C
			// End Line: 626
		/* end block 1.2 */
		// End offset: 0x8003D940
		// End Line: 632

		/* begin block 1.3 */
			// Start line: 638
			// Start offset: 0x8003D954
			// Variables:
		// 		struct _Rotation combinedRotation; // stack offset -72

			/* begin block 1.3.1 */
				// Start line: 638
				// Start offset: 0x8003D954
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			/* end block 1.3.1 */
			// End offset: 0x8003D954
			// End Line: 638
		/* end block 1.3 */
		// End offset: 0x8003D954
		// End Line: 638

		/* begin block 1.4 */
			// Start line: 662
			// Start offset: 0x8003D9AC
			// Variables:
		// 		struct _SVector pt; // stack offset -80
		/* end block 1.4 */
		// End offset: 0x8003DA58
		// End Line: 687
	/* end block 1 */
	// End offset: 0x8003DA58
	// End Line: 688

	/* begin block 2 */
		// Start line: 1107
	/* end block 2 */
	// End Line: 1108

long SCRIPT_SplineProcess
               (_Instance *instance,MultiSpline *multi,SplineDef *splineDef,SplineDef *rsplineDef,
               SplineDef *ssplineDef,int direction,int isClass)

{
  ulong uVar1;
  ulong fracOffset;
  Spline *spline;
  Intro *pIVar2;
  Spline *spline_00;
  MATRIX *pMVar3;
  _SVector *point;
  uint uVar4;
  Spline *spline_01;
  short local_60;
  short local_5e;
  short local_5c;
  _SVector _Stack88;
  _SVector _Stack80;
  _Rotation local_48 [4];
  
  fracOffset = gameTrackerX.timeMult;
  uVar4 = 0xffffffff;
  spline_01 = multi->positional;
  spline = multi->scaling;
  spline_00 = (Spline *)multi->rotational;
  point = (_SVector *)0x0;
  if (spline != (Spline *)0x0) {
    if (direction < 1) {
      if (direction < 0) {
        point = SplineGetPreviousPoint(spline,ssplineDef);
      }
      else {
        uVar1 = SplineGetData(spline,ssplineDef,&_Stack88);
        if (uVar1 != 0) {
          point = &_Stack88;
        }
      }
    }
    else {
      point = SplineGetNextPoint(spline,ssplineDef);
    }
    uVar4 = 0;
    if (point == (_SVector *)0x0) {
      uVar4 = 1;
    }
    else {
      (instance->scale).x = point->x;
      (instance->scale).y = point->z;
      (instance->scale).z = point->y;
    }
  }
  if (spline_00 != (Spline *)0x0) {
    uVar4 = 0;
    if (direction < 1) {
      if ((direction < 0) &&
         (uVar1 = SplineGetOffsetPrev(spline_00,rsplineDef,fracOffset), uVar1 == 0)) {
        uVar4 = 1;
      }
    }
    else {
      uVar1 = SplineGetOffsetNext(spline_00,rsplineDef,fracOffset);
      uVar4 = (uint)(uVar1 == 0);
    }
    if (uVar4 == 0) {
      if ((instance->flags & 1U) == 0) {
        uVar1 = SplineGetData(spline_00,rsplineDef,&local_60);
        if (uVar1 != 0) {
          pIVar2 = instance->intro;
          (instance->rotation).x = local_60;
          (instance->rotation).y = local_5e;
          (instance->rotation).z = local_5c;
          SCRIPT_CombineEulerAngles(local_48,&instance->rotation,&pIVar2->rotation);
          (instance->rotation).x = local_48[0].x;
          (instance->rotation).y = local_48[0].y;
          (instance->rotation).z = local_48[0].z;
          goto LAB_8003d9a4;
        }
      }
      else {
        uVar1 = SplineGetQuatData(spline_00,rsplineDef,&_Stack80);
        if (uVar1 != 0) {
          pMVar3 = &multi->curRotMatrix;
          G2Quat_ToMatrix_S((short *)&_Stack80,(short *)pMVar3);
          if (instance->intro != (Intro *)0x0) {
            RotMatrix((ushort *)&instance->intro->rotation,(uint *)local_48);
            MulMatrix0((undefined4 *)pMVar3,(ushort *)local_48,(uint *)pMVar3);
          }
          goto LAB_8003d9a4;
        }
      }
      uVar4 = 1;
    }
  }
LAB_8003d9a4:
  if (spline_01 != (Spline *)0x0) {
    if (direction < 1) {
      if (direction < 0) {
        point = SplineGetOffsetPreviousPoint(spline_01,splineDef,fracOffset);
      }
      else {
        fracOffset = SplineGetData(spline_01,splineDef,&_Stack80);
        if (fracOffset != 0) {
          point = &_Stack80;
        }
      }
    }
    else {
      point = SplineGetOffsetNextPoint(spline_01,splineDef,fracOffset);
    }
    uVar4 = 1;
    if (point != (_SVector *)0x0) {
      uVar4 = 0;
      if (isClass == 0) {
        (instance->position).x = point->x;
        (instance->position).y = point->y;
        (instance->position).z = point->z;
      }
      else {
        SCRIPT_RelativisticSpline(instance,point);
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SCRIPT_InstanceSplineProcess(struct _Instance *instance /*$s4*/, struct SplineDef *splineDef /*$s3*/, struct SplineDef *rsplineDef /*$s2*/, struct SplineDef *ssplineDef /*$s0*/, int direction /*stack 16*/)
 // line 716, offset 0x8003da8c
	/* begin block 1 */
		// Start line: 717
		// Start offset: 0x8003DA8C
		// Variables:
	// 		struct MultiSpline *multi; // $s1
	// 		unsigned long isClass; // stack offset -28
	// 		unsigned long isParent; // stack offset -32
	/* end block 1 */
	// End offset: 0x8003DB74
	// End Line: 747

	/* begin block 2 */
		// Start line: 1466
	/* end block 2 */
	// End Line: 1467

long SCRIPT_InstanceSplineProcess
               (_Instance *instance,SplineDef *splineDef,SplineDef *rsplineDef,SplineDef *ssplineDef
               ,int direction)

{
  MultiSpline *multi;
  long lVar1;
  ulong local_20;
  ulong local_1c;
  
  multi = SCRIPT_GetMultiSpline(instance,&local_20,&local_1c);
  lVar1 = -1;
  if (multi != (MultiSpline *)0x0) {
    if (((local_20 != 0) || (local_1c != 0)) ||
       ((splineDef == (SplineDef *)0x0 &&
        ((rsplineDef == (SplineDef *)0x0 && (ssplineDef == (SplineDef *)0x0)))))) {
      splineDef = SCRIPT_GetPosSplineDef(instance,multi,local_20,local_1c);
      rsplineDef = SCRIPT_GetRotSplineDef(instance,multi,local_20,local_1c);
      ssplineDef = SCRIPT_GetScaleSplineDef(instance,multi,local_20,local_1c);
    }
    lVar1 = SCRIPT_SplineProcess(instance,multi,splineDef,rsplineDef,ssplineDef,direction,local_1c);
  }
  return lVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SCRIPT_FadeOutProcess(struct _Instance *instance /*$a0*/)
 // line 1038, offset 0x8003db94
	/* begin block 1 */
		// Start line: 2076
	/* end block 1 */
	// End Line: 2077

	/* begin block 2 */
		// Start line: 1832
	/* end block 2 */
	// End Line: 1833

void SCRIPT_FadeOutProcess(_Instance *instance)

{
  int iVar1;
  
  iVar1 = (uint)(ushort)instance->fadeValue + (gameTrackerX.timeMult >> 5);
  instance->fadeValue = (short)iVar1;
  if (0xfff < iVar1 * 0x10000 >> 0x10) {
    INSTANCE_PlainDeath(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ScriptKillInstance(struct _Instance *instance /*$s2*/, int effect /*$s0*/)
 // line 1046, offset 0x8003dbdc
	/* begin block 1 */
		// Start line: 1047
		// Start offset: 0x8003DBDC
		// Variables:
	// 		struct Object *object; // $s1

		/* begin block 1.1 */
			// Start line: 1069
			// Start offset: 0x8003DC68
			// Variables:
		// 		struct Object *object; // $v0
		/* end block 1.1 */
		// End offset: 0x8003DC88
		// End Line: 1074

		/* begin block 1.2 */
			// Start line: 1080
			// Start offset: 0x8003DCB0
			// Variables:
		// 		struct SVECTOR v; // stack offset -24
		/* end block 1.2 */
		// End offset: 0x8003DCEC
		// End Line: 1087

		/* begin block 1.3 */
			// Start line: 1093
			// Start offset: 0x8003DCEC
			// Variables:
		// 		struct FXSplinter *splinterData; // $a0
		// 		int facadeFlg; // $a1
		// 		short shardFlags; // $a2

			/* begin block 1.3.1 */
				// Start line: 1100
				// Start offset: 0x8003DD10
				// Variables:
			// 		struct GenericTune *tune; // $v1
			/* end block 1.3.1 */
			// End offset: 0x8003DD3C
			// End Line: 1108
		/* end block 1.3 */
		// End offset: 0x8003DD8C
		// End Line: 1114
	/* end block 1 */
	// End offset: 0x8003DDA4
	// End Line: 1127

	/* begin block 2 */
		// Start line: 1848
	/* end block 2 */
	// End Line: 1849

void ScriptKillInstance(_Instance *instance,int effect)

{
  bool bVar1;
  int iVar2;
  Object *pOVar3;
  
  pOVar3 = instance->object;
  if ((pOVar3->oflags2 & 4U) != 0) {
    SOUND_EndInstanceSounds(pOVar3->soundData,instance->soundInstanceTbl);
  }
  if ((((pOVar3->oflags & 0x40000000U) != 0) && ((int *)instance->introData != (int *)0x0)) &&
     (iVar2 = *(int *)instance->introData, iVar2 != 0)) {
    SIGNAL_HandleSignal(instance,(Signal *)(iVar2 + 8),0);
  }
  bVar1 = (uint)effect < 8;
  if ((effect == 1) && (bVar1 = true, (instance->object->oflags & 0x8000U) != 0)) {
    effect = 5;
    bVar1 = true;
  }
  if (!bVar1) {
    INSTANCE_PlainDeath(instance);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x8003dca8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&PTR_LAB_800101b0)[effect])();
  return;
}





