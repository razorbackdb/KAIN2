#include "THISDUST.H"
#include "SCRIPT.H"


// decompiled code
// original method signature: 
// void /*$ra*/ SCRIPT_CombineEulerAngles(struct _Rotation *combinedRotation /*$s1*/, struct _Rotation *inputRotation1 /*$a1*/, struct _Rotation *inputRotation2 /*$s0*/)
 // line 51, offset 0x8003d214
	/* begin block 1 */
		// Start line: 52
		// Start offset: 0x8003D214
		// Variables:
	// 		struct MATRIX rotMatrix1; // stack offset -88
	// 		struct MATRIX rotMatrix2; // stack offset -56
	// 		struct _G2EulerAngles_Type ea; // stack offset -24

		/* begin block 1.1 */
			// Start line: 52
			// Start offset: 0x8003D214
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.1 */
		// End offset: 0x8003D214
		// End Line: 52
	/* end block 1 */
	// End offset: 0x8003D214
	// End Line: 52

	/* begin block 2 */
		// Start line: 102
	/* end block 2 */
	// End Line: 103

void SCRIPT_CombineEulerAngles
               (_Rotation *combinedRotation,_Rotation *inputRotation1,_Rotation *inputRotation2)

{
  uint auStack88 [18];
  
                    /* WARNING: Subroutine does not return */
  RotMatrix((ushort *)inputRotation1,auStack88);
}



// decompiled code
// original method signature: 
// void /*$ra*/ SCRIPT_InstanceSplineInit(struct _Instance *instance /*$s2*/)
 // line 163, offset 0x8003d294
	/* begin block 1 */
		// Start line: 164
		// Start offset: 0x8003D294
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
			// Start offset: 0x8003D328
			// Variables:
		// 		struct _G2Quat_Type *q; // $a0
		// 		struct _G2EulerAngles_Type ea; // stack offset -80

			/* begin block 1.1.1 */
				// Start line: 195
				// Start offset: 0x8003D350
				// Variables:
			// 		struct MATRIX introTransform; // stack offset -72
			/* end block 1.1.1 */
			// End offset: 0x8003D388
			// End Line: 204

			/* begin block 1.1.2 */
				// Start line: 209
				// Start offset: 0x8003D39C
				// Variables:
			// 		struct _Rotation combinedRotation; // stack offset -72

				/* begin block 1.1.2.1 */
					// Start line: 209
					// Start offset: 0x8003D39C
					// Variables:
				// 		short _x1; // $v0
				// 		short _y1; // $v1
				// 		short _z1; // $a0
				/* end block 1.1.2.1 */
				// End offset: 0x8003D3F4
				// End Line: 220
			/* end block 1.1.2 */
			// End offset: 0x8003D3F4
			// End Line: 221
		/* end block 1.1 */
		// End offset: 0x8003D3F4
		// End Line: 223

		/* begin block 1.2 */
			// Start line: 227
			// Start offset: 0x8003D3FC
			// Variables:
		// 		struct _SVector *start_point; // $a3

			/* begin block 1.2.1 */
				// Start line: 235
				// Start offset: 0x8003D420
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
			// End offset: 0x8003D420
			// End Line: 235
		/* end block 1.2 */
		// End offset: 0x8003D47C
		// End Line: 244

		/* begin block 1.3 */
			// Start line: 248
			// Start offset: 0x8003D484
			// Variables:
		// 		struct _SVector *start_point; // $v1
		/* end block 1.3 */
		// End offset: 0x8003D4BC
		// End Line: 258
	/* end block 1 */
	// End offset: 0x8003D4BC
	// End Line: 259

	/* begin block 2 */
		// Start line: 303
	/* end block 2 */
	// End Line: 304

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
        G2Quat_ToMatrix_S((short *)quat,(short *)&multi->curRotMatrix);
        if (instance->intro != (Intro *)0x0) {
                    /* WARNING: Subroutine does not return */
          RotMatrix((ushort *)&instance->intro->rotation,(uint *)local_48);
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
 // line 266, offset 0x8003d4e4
	/* begin block 1 */
		// Start line: 267
		// Start offset: 0x8003D4E4
		// Variables:
	// 		short kf; // $s3
	// 		short frames; // $s2
	// 		struct SplineKey *key; // $a0
	// 		struct Spline *spline; // $s0
	// 		struct RSpline *rspline; // $s1

		/* begin block 1.1 */
			// Start line: 282
			// Start offset: 0x8003D570
			// Variables:
		// 		struct SplineRotKey *rkey; // $a0
		/* end block 1.1 */
		// End offset: 0x8003D5AC
		// End Line: 288

		/* begin block 1.2 */
			// Start line: 291
			// Start offset: 0x8003D5B4
			// Variables:
		// 		struct MultiSpline *multi; // $v0
		/* end block 1.2 */
		// End offset: 0x8003D60C
		// End Line: 300
	/* end block 1 */
	// End offset: 0x8003D60C
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
 // line 317, offset 0x8003d634
	/* begin block 1 */
		// Start line: 318
		// Start offset: 0x8003D634
		// Variables:
	// 		struct MultiSpline *multi; // $v0
	/* end block 1 */
	// End offset: 0x8003D65C
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
 // line 326, offset 0x8003d66c
	/* begin block 1 */
		// Start line: 327
		// Start offset: 0x8003D66C
		// Variables:
	// 		struct MultiSpline *multi; // $v0
	/* end block 1 */
	// End offset: 0x8003D694
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
 // line 338, offset 0x8003d6a4
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
 // line 346, offset 0x8003d704
	/* begin block 1 */
		// Start line: 348
		// Start offset: 0x8003D704
		// Variables:
	// 		struct MultiSpline *multi; // $a3
	/* end block 1 */
	// End offset: 0x8003D7A8
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
 // line 376, offset 0x8003d7b0
	/* begin block 1 */
		// Start line: 377
		// Start offset: 0x8003D7B0
		// Variables:
	// 		struct SplineDef *splineDef; // $v0
	/* end block 1 */
	// End offset: 0x8003D7D4
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
 // line 388, offset 0x8003d7dc
	/* begin block 1 */
		// Start line: 389
		// Start offset: 0x8003D7DC
		// Variables:
	// 		struct SplineDef *splineDef; // $v0
	/* end block 1 */
	// End offset: 0x8003D800
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
 // line 400, offset 0x8003d808
	/* begin block 1 */
		// Start line: 401
		// Start offset: 0x8003D808
		// Variables:
	// 		struct SplineDef *splineDef; // $v0
	/* end block 1 */
	// End offset: 0x8003D82C
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
 // line 412, offset 0x8003d834
	/* begin block 1 */
		// Start line: 413
		// Start offset: 0x8003D834
		// Variables:
	// 		struct _SVector pt; // stack offset -64

		/* begin block 1.1 */
			// Start line: 423
			// Start offset: 0x8003D874
			// Variables:
		// 		struct MATRIX segMatrix; // stack offset -56
		// 		struct _Position newPt; // stack offset -24
		// 		struct _Position localPt; // stack offset -16

			/* begin block 1.1.1 */
				// Start line: 426
				// Start offset: 0x8003D874
				// Variables:
			// 		short _x1; // $a1
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			// 		struct _SVector *_v0; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8003D874
			// End Line: 426

			/* begin block 1.1.2 */
				// Start line: 426
				// Start offset: 0x8003D874
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
			// End offset: 0x8003D874
			// End Line: 426
		/* end block 1.1 */
		// End offset: 0x8003D874
		// End Line: 426

		/* begin block 1.2 */
			// Start line: 440
			// Start offset: 0x8003D9DC
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
		// End offset: 0x8003DA14
		// End Line: 440
	/* end block 1 */
	// End offset: 0x8003DA14
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
  uint local_38 [10];
  short local_10;
  short local_e;
  short local_c;
  
  pIVar5 = instance->intro;
  if ((pIVar5 != (Intro *)0x0) && ((*(int *)&pIVar5->rotation != 0 || ((pIVar5->rotation).z != 0))))
  {
    local_10 = point->x;
    local_e = point->y;
    local_c = point->z;
                    /* WARNING: Subroutine does not return */
    RotMatrix((ushort *)&instance->intro->rotation,local_38);
  }
  sVar1 = (instance->initialPos).y;
  sVar2 = (instance->initialPos).z;
  sVar3 = point->y;
  sVar4 = point->z;
  (instance->position).x = (instance->initialPos).x + point->x;
  (instance->position).y = sVar1 + sVar3;
  (instance->position).z = sVar2 + sVar4;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SCRIPT_InstanceSplineSet(struct _Instance *instance /*$s2*/, short frameNum /*$fp*/, struct SplineDef *splineDef /*$s4*/, struct SplineDef *rsplineDef /*$s5*/, struct SplineDef *ssplineDef /*stack 16*/)
 // line 444, offset 0x8003da24
	/* begin block 1 */
		// Start line: 445
		// Start offset: 0x8003DA24
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
			// Start offset: 0x8003DBC8
			// Variables:
		// 		struct _G2Quat_Type q; // stack offset -88

			/* begin block 1.1.1 */
				// Start line: 509
				// Start offset: 0x8003DBE0
				// Variables:
			// 		struct MATRIX introTransform; // stack offset -80
			/* end block 1.1.1 */
			// End offset: 0x8003DBFC
			// End Line: 515
		/* end block 1.1 */
		// End offset: 0x8003DBFC
		// End Line: 515

		/* begin block 1.2 */
			// Start line: 523
			// Start offset: 0x8003DC20
			// Variables:
		// 		struct _Rotation rot; // stack offset -88

			/* begin block 1.2.1 */
				// Start line: 527
				// Start offset: 0x8003DC34
				// Variables:
			// 		struct _Rotation combinedRotation; // stack offset -80

				/* begin block 1.2.1.1 */
					// Start line: 527
					// Start offset: 0x8003DC34
					// Variables:
				// 		short _x1; // $v0
				// 		short _y1; // $v1
				// 		short _z1; // $a0
				/* end block 1.2.1.1 */
				// End offset: 0x8003DC7C
				// End Line: 537
			/* end block 1.2.1 */
			// End offset: 0x8003DC7C
			// End Line: 538
		/* end block 1.2 */
		// End offset: 0x8003DC7C
		// End Line: 540

		/* begin block 1.3 */
			// Start line: 544
			// Start offset: 0x8003DC8C
			// Variables:
		// 		struct _SVector scale; // stack offset -88
		/* end block 1.3 */
		// End offset: 0x8003DCCC
		// End Line: 552
	/* end block 1 */
	// End offset: 0x8003DCCC
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
  Spline *spline;
  Spline *spline_00;
  Spline *spline_01;
  undefined local_60 [8];
  short local_58 [4];
  uint local_50 [8];
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
                    /* WARNING: Subroutine does not return */
      SplineGetData(spline,splineDef,local_60);
    }
    if ((rsplineDef != (SplineDef *)0x0) && (spline_00 != (Spline *)0x0)) {
      SplineSetDef2FrameNumber(spline_00,rsplineDef,frameNum);
      if ((instance->flags & 1U) == 0) {
                    /* WARNING: Subroutine does not return */
        SplineGetData(spline_00,rsplineDef,local_58);
      }
      uVar1 = SplineGetQuatData(spline_00,rsplineDef,local_58);
      if (uVar1 != 0) {
        G2Quat_ToMatrix_S(local_58,(short *)&multi->curRotMatrix);
        if (instance->intro != (Intro *)0x0) {
                    /* WARNING: Subroutine does not return */
          RotMatrix((ushort *)&instance->intro->rotation,local_50);
        }
      }
    }
    if ((ssplineDef != (SplineDef *)0x0) && (spline_01 != (Spline *)0x0)) {
      SplineSetDef2FrameNumber(spline_01,ssplineDef,frameNum);
                    /* WARNING: Subroutine does not return */
      SplineGetData(spline_01,ssplineDef,local_58);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SCRIPT_SplineProcess(struct _Instance *instance /*$s4*/, struct MultiSpline *multi /*$fp*/, struct SplineDef *splineDef /*stack 8*/, struct SplineDef *rsplineDef /*$s7*/, struct SplineDef *ssplineDef /*stack 16*/, int direction /*stack 20*/, int isClass /*stack 24*/)
 // line 556, offset 0x8003dcfc
	/* begin block 1 */
		// Start line: 557
		// Start offset: 0x8003DCFC
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
			// Start offset: 0x8003DD58
			// Variables:
		// 		struct _SVector pt; // stack offset -88
		/* end block 1.1 */
		// End offset: 0x8003DDD4
		// End Line: 594

		/* begin block 1.2 */
			// Start line: 617
			// Start offset: 0x8003DE40
			// Variables:
		// 		struct _G2Quat_Type q; // stack offset -80

			/* begin block 1.2.1 */
				// Start line: 620
				// Start offset: 0x8003DE58
				// Variables:
			// 		struct MATRIX introTransform; // stack offset -72
			/* end block 1.2.1 */
			// End offset: 0x8003DE74
			// End Line: 626
		/* end block 1.2 */
		// End offset: 0x8003DE98
		// End Line: 632

		/* begin block 1.3 */
			// Start line: 638
			// Start offset: 0x8003DEAC
			// Variables:
		// 		struct _Rotation combinedRotation; // stack offset -72

			/* begin block 1.3.1 */
				// Start line: 638
				// Start offset: 0x8003DEAC
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			/* end block 1.3.1 */
			// End offset: 0x8003DEAC
			// End Line: 638
		/* end block 1.3 */
		// End offset: 0x8003DEAC
		// End Line: 638

		/* begin block 1.4 */
			// Start line: 662
			// Start offset: 0x8003DF04
			// Variables:
		// 		struct _SVector pt; // stack offset -80
		/* end block 1.4 */
		// End offset: 0x8003DFB0
		// End Line: 687
	/* end block 1 */
	// End offset: 0x8003DFB0
	// End Line: 688

	/* begin block 2 */
		// Start line: 1107
	/* end block 2 */
	// End Line: 1108

long SCRIPT_SplineProcess
               (_Instance *instance,MultiSpline *multi,SplineDef *splineDef,SplineDef *rsplineDef,
               SplineDef *ssplineDef,int direction,int isClass)

{
  ulong fracOffset;
  _SVector *point;
  ulong uVar1;
  Spline *spline;
  Spline *spline_00;
  uint uVar2;
  Spline *spline_01;
  undefined local_60 [8];
  undefined auStack88 [8];
  short asStack80 [4];
  uint local_48 [8];
  
  fracOffset = gameTrackerX.timeMult;
  uVar2 = 0xffffffff;
  spline_01 = multi->positional;
  spline = multi->scaling;
  spline_00 = (Spline *)multi->rotational;
  if (spline != (Spline *)0x0) {
    if (direction < 1) {
      if (-1 < direction) {
                    /* WARNING: Subroutine does not return */
        SplineGetData(spline,ssplineDef,auStack88);
      }
      point = SplineGetPreviousPoint(spline,ssplineDef);
    }
    else {
      point = SplineGetNextPoint(spline,ssplineDef);
    }
    uVar2 = 0;
    if (point == (_SVector *)0x0) {
      uVar2 = 1;
    }
    else {
      (instance->scale).x = point->x;
      (instance->scale).y = point->z;
      (instance->scale).z = point->y;
    }
  }
  if (spline_00 != (Spline *)0x0) {
    uVar2 = 0;
    if (direction < 1) {
      if ((direction < 0) &&
         (uVar1 = SplineGetOffsetPrev(spline_00,rsplineDef,fracOffset), uVar1 == 0)) {
        uVar2 = 1;
      }
    }
    else {
      uVar1 = SplineGetOffsetNext(spline_00,rsplineDef,fracOffset);
      uVar2 = (uint)(uVar1 == 0);
    }
    if (uVar2 == 0) {
      if ((instance->flags & 1U) == 0) {
                    /* WARNING: Subroutine does not return */
        SplineGetData(spline_00,rsplineDef,local_60);
      }
      uVar1 = SplineGetQuatData(spline_00,rsplineDef,asStack80);
      if (uVar1 == 0) {
        uVar2 = 1;
      }
      else {
        G2Quat_ToMatrix_S(asStack80,(short *)&multi->curRotMatrix);
        if (instance->intro != (Intro *)0x0) {
                    /* WARNING: Subroutine does not return */
          RotMatrix((ushort *)&instance->intro->rotation,local_48);
        }
      }
    }
  }
  if (spline_01 != (Spline *)0x0) {
    if (direction < 1) {
      if (-1 < direction) {
                    /* WARNING: Subroutine does not return */
        SplineGetData(spline_01,splineDef,asStack80);
      }
      point = SplineGetOffsetPreviousPoint(spline_01,splineDef,fracOffset);
    }
    else {
      point = SplineGetOffsetNextPoint(spline_01,splineDef,fracOffset);
    }
    uVar2 = 1;
    if (point != (_SVector *)0x0) {
      uVar2 = 0;
      if (isClass == 0) {
        (instance->position).x = point->x;
        (instance->position).y = point->y;
        (instance->position).z = point->z;
      }
      else {
        SCRIPT_RelativisticSpline(instance,point);
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SCRIPT_InstanceSplineProcess(struct _Instance *instance /*$s4*/, struct SplineDef *splineDef /*$s3*/, struct SplineDef *rsplineDef /*$s2*/, struct SplineDef *ssplineDef /*$s0*/, int direction /*stack 16*/)
 // line 716, offset 0x8003dfe4
	/* begin block 1 */
		// Start line: 717
		// Start offset: 0x8003DFE4
		// Variables:
	// 		struct MultiSpline *multi; // $s1
	// 		unsigned long isClass; // stack offset -28
	// 		unsigned long isParent; // stack offset -32
	/* end block 1 */
	// End offset: 0x8003E0CC
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
 // line 1038, offset 0x8003e0ec
	/* begin block 1 */
		// Start line: 2071
	/* end block 1 */
	// End Line: 2072

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
 // line 1046, offset 0x8003e134
	/* begin block 1 */
		// Start line: 1047
		// Start offset: 0x8003E134
		// Variables:
	// 		struct Object *object; // $s1

		/* begin block 1.1 */
			// Start line: 1069
			// Start offset: 0x8003E1C0
			// Variables:
		// 		struct Object *object; // $v0
		/* end block 1.1 */
		// End offset: 0x8003E1E0
		// End Line: 1074

		/* begin block 1.2 */
			// Start line: 1080
			// Start offset: 0x8003E208
			// Variables:
		// 		struct SVECTOR v; // stack offset -24
		/* end block 1.2 */
		// End offset: 0x8003E244
		// End Line: 1087

		/* begin block 1.3 */
			// Start line: 1093
			// Start offset: 0x8003E244
			// Variables:
		// 		struct FXSplinter *splinterData; // $a0
		// 		int facadeFlg; // $a1
		// 		short shardFlags; // $a2

			/* begin block 1.3.1 */
				// Start line: 1100
				// Start offset: 0x8003E268
				// Variables:
			// 		struct GenericTune *tune; // $v1
			/* end block 1.3.1 */
			// End offset: 0x8003E294
			// End Line: 1108
		/* end block 1.3 */
		// End offset: 0x8003E2E4
		// End Line: 1114
	/* end block 1 */
	// End offset: 0x8003E2FC
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
                    /* WARNING: Subroutine does not return */
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
                    /* WARNING: Could not recover jumptable at 0x8003e200. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&PTR_LAB_8001015c)[effect])();
  return;
}





