#include "THISDUST.H"
#include "MATH3D.H"


// decompiled code
// original method signature: 
// void /*$ra*/ MATH3D_Sort3VectorCoords(long *a /*$a0*/, long *b /*$a1*/, long *c /*$a2*/)
 // line 220, offset 0x80039a58
	/* begin block 1 */
		// Start line: 222
		// Start offset: 0x80039A58
		// Variables:
	// 		long a1; // $t0
	// 		long b1; // $v1
	// 		long c1; // $a3
	/* end block 1 */
	// End offset: 0x80039AD4
	// End Line: 256

	/* begin block 2 */
		// Start line: 371
	/* end block 2 */
	// End Line: 372

	/* begin block 3 */
		// Start line: 440
	/* end block 3 */
	// End Line: 441

	/* begin block 4 */
		// Start line: 372
	/* end block 4 */
	// End Line: 373

void MATH3D_Sort3VectorCoords(long *a,long *b,long *c)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *a;
  iVar1 = *b;
  iVar2 = *c;
  if (iVar3 < iVar1) {
    if (iVar2 < iVar3) {
      *c = iVar1;
      *b = iVar3;
      *a = iVar2;
      return;
    }
    if (iVar2 < iVar1) {
      *c = iVar1;
      *b = iVar2;
      return;
    }
  }
  else {
    if (iVar2 < iVar1) {
      *a = iVar2;
      *c = iVar3;
      return;
    }
    if (iVar2 < iVar3) {
      *a = iVar1;
      *b = iVar2;
      *c = iVar3;
      return;
    }
    *a = iVar1;
    *b = iVar3;
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MATH3D_LengthXYZ(long x /*$a0*/, long y /*$a1*/, long z /*$a2*/)
 // line 258, offset 0x80039adc
	/* begin block 1 */
		// Start line: 260
		// Start offset: 0x80039ADC
		// Variables:
	// 		long t; // $v0
	/* end block 1 */
	// End offset: 0x80039BA4
	// End Line: 309

	/* begin block 2 */
		// Start line: 447
	/* end block 2 */
	// End Line: 448

	/* begin block 3 */
		// Start line: 448
	/* end block 3 */
	// End Line: 449

	/* begin block 4 */
		// Start line: 449
	/* end block 4 */
	// End Line: 450

long MATH3D_LengthXYZ(long x,long y,long z)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (x < 0) {
    x = -x;
  }
  if (y < 0) {
    y = -y;
  }
  if (z < 0) {
    z = -z;
  }
  iVar1 = x;
  if (x < y) {
    iVar1 = y;
    y = x;
  }
  iVar2 = z;
  iVar3 = y;
  iVar4 = iVar1;
  if ((y <= z) && (iVar2 = y, iVar3 = iVar1, iVar4 = z, z < iVar1)) {
    iVar3 = z;
    iVar4 = iVar1;
  }
  iVar1 = iVar4 * 0x1e + iVar3 * 0xc + iVar2 * 9;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0x1f;
  }
  return iVar1 >> 5;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MATH3D_LengthXY(long x /*$a0*/, long y /*$a1*/)
 // line 312, offset 0x80039bac
	/* begin block 1 */
		// Start line: 555
	/* end block 1 */
	// End Line: 556

	/* begin block 2 */
		// Start line: 556
	/* end block 2 */
	// End Line: 557

long MATH3D_LengthXY(long x,long y)

{
  int iVar1;
  uint uVar2;
  
  if (x < 0) {
    x = -x;
  }
  if (y < 0) {
    y = -y;
  }
  if (y < x) {
    uVar2 = x ^ y;
    y = y ^ uVar2;
    x = uVar2 ^ y;
  }
  iVar1 = y * 0x1e + x * 0xc;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0x1f;
  }
  return iVar1 >> 5;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MATH3D_Normalize(struct _Normal *normal /*$s0*/)
 // line 328, offset 0x80039c0c
	/* begin block 1 */
		// Start line: 329
		// Start offset: 0x80039C0C
		// Variables:
	// 		long length; // $a1
	/* end block 1 */
	// End offset: 0x80039C8C
	// End Line: 345

	/* begin block 2 */
		// Start line: 656
	/* end block 2 */
	// End Line: 657

void MATH3D_Normalize(_Normal *normal)

{
  long lVar1;
  
  lVar1 = MATH3D_LengthXYZ((int)normal->x << 2,(int)normal->y << 2,(int)normal->z << 2);
  if (lVar1 != 0) {
    normal->x = (short)(((int)normal->x << 0xe) / lVar1);
    normal->y = (short)(((int)normal->y << 0xe) / lVar1);
    normal->z = (short)(((int)normal->z << 0xe) / lVar1);
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ MATH3D_FastAtan2(long y /*$a0*/, long x /*$a1*/)
 // line 349, offset 0x80039c9c
	/* begin block 1 */
		// Start line: 351
		// Start offset: 0x80039C9C
		// Variables:
	// 		long ax; // $a3
	// 		long ay; // $a2
	/* end block 1 */
	// End offset: 0x80039DB0
	// End Line: 401

	/* begin block 2 */
		// Start line: 619
	/* end block 2 */
	// End Line: 620

	/* begin block 3 */
		// Start line: 620
	/* end block 3 */
	// End Line: 621

	/* begin block 4 */
		// Start line: 623
	/* end block 4 */
	// End Line: 624

short MATH3D_FastAtan2(long y,long x)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  
  if (x == 0) {
    x = 1;
  }
  if (y != 0) {
    iVar3 = x;
    if (x < 0) {
      iVar3 = -x;
    }
    iVar2 = y;
    if (y < 0) {
      iVar2 = -y;
    }
    if (x < 1) {
      if (y < 1) {
        if (iVar2 < iVar3) {
          return (short)((uint)(((iVar2 << 9) / iVar3 + 0x800) * 0x10000) >> 0x10);
        }
        sVar4 = (short)((iVar3 << 9) / iVar2);
        sVar1 = 0xc00;
      }
      else {
        if (iVar3 < iVar2) {
          return (short)((iVar3 << 9) / iVar2) + 0x400;
        }
        sVar4 = (short)((iVar2 << 9) / iVar3);
        sVar1 = 0x800;
      }
    }
    else {
      if (y < 1) {
        if (iVar3 <= iVar2) {
          return (short)((iVar3 << 9) / iVar2) + 0xc00;
        }
        sVar4 = (short)((iVar2 << 9) / iVar3);
        sVar1 = 0x1000;
      }
      else {
        if (iVar2 <= iVar3) {
          return (short)((iVar2 << 9) / iVar3);
        }
        sVar4 = (short)((iVar3 << 9) / iVar2);
        sVar1 = 0x400;
      }
    }
    return sVar1 - sVar4;
  }
  return (short)((ushort)(x < 1) << 0xb);
}



// decompiled code
// original method signature: 
// long /*$ra*/ MATH3D_FastSqrt(long square /*$a0*/)
 // line 456, offset 0x80039db8
	/* begin block 1 */
		// Start line: 458
		// Start offset: 0x80039DB8

		/* begin block 1.1 */
			// Start line: 458
			// Start offset: 0x80039DC0
			// Variables:
		// 		unsigned long result; // $t0
		// 		long remainder; // $v0
		// 		long mask; // $a1
		// 		long shift; // $a2
		// 		long mask_squared; // $a3
		// 		long result_shift; // $v1
		/* end block 1.1 */
		// End offset: 0x80039E90
		// End Line: 504
	/* end block 1 */
	// End offset: 0x80039E90
	// End Line: 506

	/* begin block 2 */
		// Start line: 835
	/* end block 2 */
	// End Line: 836

	/* begin block 3 */
		// Start line: 836
	/* end block 3 */
	// End Line: 837

long MATH3D_FastSqrt(long square)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar4 = 0x1f;
  if (square == 0) {
    return 0;
  }
  uVar3 = 0x80000000;
  if (-1 < square) {
    do {
      uVar3 = (int)uVar3 >> 1;
      iVar4 = iVar4 + -1;
    } while ((uVar3 & square) == 0);
  }
  uVar5 = iVar4 >> 1;
  uVar3 = 1 << (uVar5 + 6 & 0x1f);
  iVar4 = 1 << ((uVar5 & 0xf) << 1);
  uVar7 = uVar3;
  iVar6 = iVar4;
  iVar2 = square - iVar4;
  while (uVar5 = uVar5 - 1, uVar5 != 0xffffffff) {
    iVar6 = iVar6 >> 2;
    iVar1 = iVar2 - (iVar4 + iVar6);
    uVar3 = (int)uVar3 >> 1;
    iVar4 = iVar4 >> 1;
    if (-1 < iVar1) {
      iVar4 = iVar4 + iVar6;
      uVar7 = uVar7 | uVar3;
      iVar2 = iVar1;
    }
  }
  iVar4 = iVar4 << 0xc;
  iVar1 = 0x1000;
  iVar6 = iVar2 << 0xc;
  while( true ) {
    uVar3 = (int)uVar3 >> 1;
    iVar1 = iVar1 >> 2;
    if (uVar3 == 0) break;
    iVar2 = iVar6 - (iVar4 + iVar1);
    iVar4 = iVar4 >> 1;
    if (-1 < iVar2) {
      iVar4 = iVar4 + iVar1;
      uVar7 = uVar7 | uVar3;
      iVar6 = iVar2;
    }
  }
  return uVar7;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MATH3D_FastSqrt0(long square /*$a0*/)
 // line 511, offset 0x80039e98
	/* begin block 1 */
		// Start line: 513
		// Start offset: 0x80039E98

		/* begin block 1.1 */
			// Start line: 513
			// Start offset: 0x80039EA0
			// Variables:
		// 		unsigned long result; // $t0
		// 		long remainder; // $v0
		// 		long mask; // $a2
		// 		long shift; // $a1
		// 		long mask_squared; // $a3
		// 		long result_shift; // $v1
		/* end block 1.1 */
		// End offset: 0x80039F20
		// End Line: 546
	/* end block 1 */
	// End offset: 0x80039F20
	// End Line: 548

	/* begin block 2 */
		// Start line: 945
	/* end block 2 */
	// End Line: 946

	/* begin block 3 */
		// Start line: 946
	/* end block 3 */
	// End Line: 947

long MATH3D_FastSqrt0(long square)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar4 = 0x1f;
  if (square == 0) {
    return 0;
  }
  uVar6 = 0x80000000;
  if (-1 < square) {
    do {
      uVar6 = (int)uVar6 >> 1;
      iVar4 = iVar4 + -1;
    } while ((uVar6 & square) == 0);
  }
  uVar5 = iVar4 >> 1;
  uVar6 = 1 << (uVar5 & 0x1f);
  iVar4 = 1 << ((uVar5 & 0xf) << 1);
  uVar7 = uVar6;
  iVar3 = iVar4;
  iVar1 = square - iVar4;
  while (uVar5 = uVar5 - 1, uVar5 != 0xffffffff) {
    uVar6 = (int)uVar6 >> 1;
    iVar4 = iVar4 >> 2;
    iVar2 = (iVar1 - iVar3) - iVar4;
    iVar3 = iVar3 >> 1;
    if (-1 < iVar2) {
      iVar3 = iVar3 + iVar4;
      uVar7 = uVar7 | uVar6;
      iVar1 = iVar2;
    }
  }
  return uVar7;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MATH3D_DistanceBetweenPositions(struct _Position *pos1 /*$v0*/, struct _Position *pos2 /*$a1*/)
 // line 607, offset 0x80039f28
	/* begin block 1 */
		// Start line: 608
		// Start offset: 0x80039F28
	/* end block 1 */
	// End offset: 0x80039F28
	// End Line: 608

	/* begin block 2 */
		// Start line: 1214
	/* end block 2 */
	// End Line: 1215

long MATH3D_DistanceBetweenPositions(_Position *pos1,_Position *pos2)

{
  ulong square;
  long lVar1;
  
  square = MATH3D_SquareLength((int)pos2->x - (int)pos1->x,(int)pos2->y - (int)pos1->y,
                               (int)pos2->z - (int)pos1->z);
  lVar1 = MATH3D_FastSqrt0(square);
  return lVar1;
}



// decompiled code
// original method signature: 
// short /*$ra*/ MATH3D_AngleBetweenVectors(struct _SVector *vector1 /*$a0*/, struct _SVector *vector2 /*$a1*/)
 // line 616, offset 0x80039f74
	/* begin block 1 */
		// Start line: 617
		// Start offset: 0x80039F74
		// Variables:
	// 		long projection_length; // $s0
	/* end block 1 */
	// End offset: 0x8003A050
	// End Line: 636

	/* begin block 2 */
		// Start line: 1098
	/* end block 2 */
	// End Line: 1099

short MATH3D_AngleBetweenVectors(_SVector *vector1,_SVector *vector2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = (int)vector1->x * (int)vector2->x;
  if ((int)vector1->x == (int)vector2->x) {
    if ((vector1->y == vector2->y) && (vector1->z == vector2->z)) {
      return 0;
    }
    iVar3 = (int)vector1->x * (int)vector2->x;
  }
  uVar2 = iVar3 + (int)vector1->y * (int)vector2->y + (int)vector1->z * (int)vector2->z + 0x800 >>
          0xc;
  if ((int)uVar2 < 0x1001) {
    iVar3 = uVar2 * uVar2;
    if (-0x1001 < (int)uVar2) goto LAB_8003a02c;
    uVar2 = 0xfffff000;
  }
  else {
    uVar2 = 0x1000;
  }
  iVar3 = uVar2 * uVar2;
LAB_8003a02c:
  uVar1 = MATH3D_FastSqrt0(0x1000000 - iVar3);
  iVar3 = ratan2(uVar1,uVar2);
  return (short)iVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MATH3D_RotMatAboutVec(struct _SVector *vec /*$s1*/, struct MATRIX *mat /*$s2*/, short angle /*$a2*/)
 // line 638, offset 0x8003a060
	/* begin block 1 */
		// Start line: 639
		// Start offset: 0x8003A060
		// Variables:
	// 		long length; // $s0
	// 		struct SVECTOR rot_angs; // stack offset -96
	// 		struct MATRIX mat1; // stack offset -88
	// 		struct MATRIX mat2; // stack offset -56
	/* end block 1 */
	// End offset: 0x8003A114
	// End Line: 657

	/* begin block 2 */
		// Start line: 1142
	/* end block 2 */
	// End Line: 1143

void MATH3D_RotMatAboutVec(_SVector *vec,MATRIX *mat,short angle)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  ushort local_60;
  undefined2 local_5e;
  undefined2 local_5c;
  uint auStack88 [8];
  undefined4 auStack56 [8];
  
  if ((int)angle != 0) {
    uVar1 = MATH3D_SquareLength(0,(int)vec->y,(int)vec->z);
    uVar2 = MATH3D_FastSqrt0(uVar1 + 0x800);
    iVar3 = ratan2((int)vec->y,(int)vec->z);
    local_60 = -(short)iVar3;
    iVar3 = ratan2((int)vec->x,uVar2);
    local_5e = (undefined2)iVar3;
    local_5c = 0;
    RotMatrix(&local_60,auStack88);
    TransposeMatrix(auStack88,auStack56);
    MulMatrix2(auStack56,(uint *)mat);
    RotMatrixZ((int)angle,(uint *)mat);
    MulMatrix2(auStack88,(uint *)mat);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MATH3D_SetUnityMatrix(struct MATRIX *mat /*$a0*/)
 // line 659, offset 0x8003a130
	/* begin block 1 */
		// Start line: 1198
	/* end block 1 */
	// End Line: 1199

	/* begin block 2 */
		// Start line: 1199
	/* end block 2 */
	// End Line: 1200

void MATH3D_SetUnityMatrix(MATRIX *mat)

{
  *(undefined4 *)mat->m = 0x1000;
  *(undefined4 *)(mat->m + 2) = 0;
  *(undefined4 *)(mat->m + 4) = 0x1000;
  *(undefined4 *)(mat->m + 6) = 0;
  mat->m[8] = 0x1000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ AngleMoveToward(short *current_ptr /*$s3*/, short destination /*$a1*/, short step /*$a2*/)
 // line 675, offset 0x8003a14c
	/* begin block 1 */
		// Start line: 676
		// Start offset: 0x8003A14C
		// Variables:
	// 		long diff; // $a0
	// 		short current; // $s0
	/* end block 1 */
	// End offset: 0x8003A1DC
	// End Line: 695

	/* begin block 2 */
		// Start line: 1230
	/* end block 2 */
	// End Line: 1231

void AngleMoveToward(short *current_ptr,short destination,short step)

{
  ushort current;
  short sVar1;
  int iVar2;
  int iVar3;
  
  current = *current_ptr;
  sVar1 = AngleDiff(current,destination);
  iVar3 = (int)sVar1;
  if (iVar3 == 0) {
LAB_8003a1b0:
    *current_ptr = destination;
    return;
  }
  iVar2 = iVar3;
  if (iVar3 < 0) {
    iVar2 = -iVar3;
  }
  if (iVar2 < step) goto LAB_8003a1b0;
  if (iVar3 < 1) {
    if (-1 < iVar3) goto LAB_8003a1d8;
    step = -step;
  }
  current = current + step;
LAB_8003a1d8:
  *current_ptr = current & 0xfff;
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ AngleDiff(short current /*$a0*/, short destination /*$a1*/)
 // line 700, offset 0x8003a1f8
	/* begin block 1 */
		// Start line: 702
		// Start offset: 0x8003A1F8
	/* end block 1 */
	// End offset: 0x8003A210
	// End Line: 706

	/* begin block 2 */
		// Start line: 1284
	/* end block 2 */
	// End Line: 1285

	/* begin block 3 */
		// Start line: 1285
	/* end block 3 */
	// End Line: 1286

	/* begin block 4 */
		// Start line: 1287
	/* end block 4 */
	// End Line: 1288

short AngleDiff(short current,short destination)

{
  ushort uVar1;
  
  uVar1 = destination - current & 0xfff;
  if (0x800 < uVar1) {
    uVar1 = uVar1 | 0xf000;
  }
  return (short)uVar1;
}



// decompiled code
// original method signature: 
// short /*$ra*/ MATH3D_AngleFromPosToPos(struct _Position *from /*$a0*/, struct _Position *to /*$a1*/)
 // line 712, offset 0x8003a21c
	/* begin block 1 */
		// Start line: 713
		// Start offset: 0x8003A21C
	/* end block 1 */
	// End offset: 0x8003A21C
	// End Line: 713

	/* begin block 2 */
		// Start line: 1308
	/* end block 2 */
	// End Line: 1309

short MATH3D_AngleFromPosToPos(_Position *from,_Position *to)

{
  int iVar1;
  
  iVar1 = ratan2((int)from->y - (int)to->y,(int)from->x - (int)to->x);
  return (short)((short)iVar1 + 0xc00U & 0xfff);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MATH3D_ZYXtoXYZ(struct _Rotation *rot /*$s0*/)
 // line 723, offset 0x8003a254
	/* begin block 1 */
		// Start line: 724
		// Start offset: 0x8003A254
		// Variables:
	// 		struct MATRIX tempMat; // stack offset -48
	// 		struct _G2EulerAngles_Type ea; // stack offset -16
	/* end block 1 */
	// End offset: 0x8003A254
	// End Line: 724

	/* begin block 2 */
		// Start line: 1331
	/* end block 2 */
	// End Line: 1332

void MATH3D_ZYXtoXYZ(_Rotation *rot)

{
  _G2Matrix_Type _Stack48;
  _G2EulerAngles_Type local_10;
  
  RotMatrixZYX((ushort *)rot,(uint *)&_Stack48);
  G2EulerAngles_FromMatrix(&local_10,&_Stack48,0x15);
  rot->x = local_10.x;
  rot->y = local_10.y;
  rot->z = local_10.z;
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ MATH3D_ElevationFromPosToPos(struct _Position *from /*$s1*/, struct _Position *to /*$s0*/)
 // line 738, offset 0x8003a2b0
	/* begin block 1 */
		// Start line: 739
		// Start offset: 0x8003A2B0
	/* end block 1 */
	// End offset: 0x8003A2B0
	// End Line: 739

	/* begin block 2 */
		// Start line: 1361
	/* end block 2 */
	// End Line: 1362

short MATH3D_ElevationFromPosToPos(_Position *from,_Position *to)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  iVar1 = (int)from->x - (int)to->x;
  iVar2 = (int)from->y - (int)to->y;
  lVar3 = MATH3D_FastSqrt0(iVar1 * iVar1 + iVar2 * iVar2);
  iVar1 = ratan2((int)to->z - (int)from->z,(int)(short)lVar3);
  return (short)(-(short)iVar1 & 0xfff);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MATH3D_RotationFromPosToPos(struct _Position *from /*$s0*/, struct _Position *to /*$s2*/, struct _Rotation *rot /*$s1*/)
 // line 754, offset 0x8003a334
	/* begin block 1 */
		// Start line: 1394
	/* end block 1 */
	// End Line: 1395

void MATH3D_RotationFromPosToPos(_Position *from,_Position *to,_Rotation *rot)

{
  short sVar1;
  
  sVar1 = MATH3D_ElevationFromPosToPos(from,to);
  rot->x = sVar1;
  rot->y = 0;
  sVar1 = MATH3D_AngleFromPosToPos(from,to);
  rot->z = sVar1;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MATH3D_veclen2(int ix /*$v1*/, int iy /*$a1*/)
 // line 762, offset 0x8003a388
	/* begin block 1 */
		// Start line: 763
		// Start offset: 0x8003A388
		// Variables:
	// 		int t; // $a0
	/* end block 1 */
	// End offset: 0x8003A3BC
	// End Line: 776

	/* begin block 2 */
		// Start line: 1412
	/* end block 2 */
	// End Line: 1413

int MATH3D_veclen2(int ix,int iy)

{
  bool bVar1;
  uint uVar2;
  
  if (ix < 0) {
    ix = -ix;
  }
  bVar1 = ix < iy;
  if (iy < 0) {
    iy = -iy;
    bVar1 = ix < iy;
  }
  if (bVar1) {
    uVar2 = ix ^ iy;
    iy = iy ^ uVar2;
    ix = uVar2 ^ iy;
  }
  iy = iy + (iy >> 1);
  return ((ix - (ix >> 5)) - (ix >> 7)) + (iy >> 2) + (iy >> 6);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MATH3D_RotateAxisToVector(struct MATRIX *dest /*$s3*/, struct MATRIX *src /*$s2*/, struct _SVector *vec /*$a2*/, enum MATH3D_AXIS axis /*$a3*/)
 // line 784, offset 0x8003a3e8
	/* begin block 1 */
		// Start line: 785
		// Start offset: 0x8003A3E8
		// Variables:
	// 		struct MATRIX xform; // stack offset -64
	// 		struct _G2Quat_Type rot; // stack offset -32
	// 		long len; // $s0
	// 		int theta; // $s1
	// 		int sintheta; // $v0
	// 		int px; // $a3
	// 		int py; // $v1
	// 		int pz; // $a1
	/* end block 1 */
	// End offset: 0x8003A588
	// End Line: 820

	/* begin block 2 */
		// Start line: 1456
	/* end block 2 */
	// End Line: 1457

void MATH3D_RotateAxisToVector(MATRIX *dest,MATRIX *src,_SVector *vec,MATH3D_AXIS axis)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  ulong square;
  int iVar4;
  int iVar5;
  long lVar6;
  uint uVar7;
  ushort auStack64 [16];
  short local_20;
  short local_1e;
  short local_1c;
  undefined2 local_1a;
  
  if (axis < AXIS_NEG_X) {
    psVar1 = src->m + axis;
    iVar3 = (int)*psVar1;
    iVar4 = (int)psVar1[3];
    iVar5 = (int)psVar1[6];
  }
  else {
    psVar1 = src->m + axis + ~AXIS_Z;
    iVar3 = -(int)*psVar1;
    iVar4 = -(int)psVar1[3];
    iVar5 = -(int)psVar1[6];
  }
  iVar2 = iVar4 * vec->z - iVar5 * vec->y;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  local_20 = (short)(iVar2 >> 0xc);
  iVar2 = iVar5 * vec->x - iVar3 * vec->z;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  local_1e = (short)(iVar2 >> 0xc);
  iVar2 = iVar3 * vec->y - iVar4 * vec->x;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  local_1c = (short)(iVar2 >> 0xc);
  iVar3 = iVar3 * vec->x + iVar4 * vec->y + iVar5 * vec->z;
  if (iVar3 < 0) {
    iVar3 = iVar3 + 0xfff;
  }
  iVar3 = MATH3D_racos_S(iVar3 >> 0xc);
  uVar7 = ((iVar3 << 0x10) >> 0x10) - ((iVar3 << 0x10) >> 0x1f) >> 1;
  square = MATH3D_SquareLength((int)local_20,(int)local_1e,(int)local_1c);
  if ((int)square < 1) {
    lVar6 = 0x1000;
  }
  else {
    lVar6 = MATH3D_FastSqrt0(square);
  }
  iVar3 = rsin(uVar7);
  local_20 = (short)((local_20 * iVar3) / lVar6);
  local_1e = (short)((local_1e * iVar3) / lVar6);
  local_1c = (short)((local_1c * iVar3) / lVar6);
  iVar3 = rcos(uVar7);
  local_1a = (undefined2)iVar3;
  G2Quat_ToMatrix_S(&local_20,(short *)auStack64);
  MulMatrix0((undefined4 *)src,auStack64,(uint *)dest);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MATH3D_ConeDetect(struct _SVector *pos /*$s2*/, int arc /*$s0*/, int elevation /*$s4*/)
 // line 859, offset 0x8003a640
	/* begin block 1 */
		// Start line: 860
		// Start offset: 0x8003A640
		// Variables:
	// 		long y; // $s1
	// 		long x; // $s3

		/* begin block 1.1 */
			// Start line: 866
			// Start offset: 0x8003A69C
		/* end block 1.1 */
		// End offset: 0x8003A6D4
		// End Line: 872
	/* end block 1 */
	// End offset: 0x8003A6D8
	// End Line: 874

	/* begin block 2 */
		// Start line: 1718
	/* end block 2 */
	// End Line: 1719

int MATH3D_ConeDetect(_SVector *pos,int arc,int elevation)

{
  short sVar1;
  short sVar2;
  long x;
  int y;
  int x_00;
  
  x_00 = (int)pos->x;
  sVar2 = pos->y;
  y = x_00;
  if (x_00 < 0) {
    y = -x_00;
  }
  sVar1 = MATH3D_FastAtan2(y,-(int)sVar2);
  if (sVar1 < arc) {
    x = MATH3D_LengthXY(x_00,-(int)sVar2);
    y = (int)pos->z;
    if (y < 0) {
      y = -y;
    }
    sVar2 = MATH3D_FastAtan2(y,x);
    if (sVar2 < elevation) {
      return 1;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MATH3D_CrossProduct(struct _SVector *t /*$a0*/, struct _SVector *r /*$a1*/, struct _SVector *s /*$a2*/)
 // line 976, offset 0x8003a6f8
	/* begin block 1 */
		// Start line: 1952
	/* end block 1 */
	// End Line: 1953

	/* begin block 2 */
		// Start line: 1728
	/* end block 2 */
	// End Line: 1729

void MATH3D_CrossProduct(_SVector *t,_SVector *r,_SVector *s)

{
  t->x = (short)((int)r->y * (int)s->z - (int)r->z * (int)s->y >> 0xc);
  t->y = -(short)((int)r->x * (int)s->z - (int)r->z * (int)s->x >> 0xc);
  t->z = (short)((int)r->x * (int)s->y - (int)r->y * (int)s->x >> 0xc);
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ MATH3D_SquareLength(long x /*$v0*/, long y /*$a1*/, long z /*$a2*/)
 // line 989, offset 0x8003a79c
	/* begin block 1 */
		// Start line: 1748
	/* end block 1 */
	// End Line: 1749

ulong MATH3D_SquareLength(long x,long y,long z)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  setCopReg(2,0x4800,x);
  setCopReg(2,0x5000,y);
  setCopReg(2,0x5800,z);
  copFunction(2,0xa00428);
  iVar1 = getCopReg(2,0xc800);
  iVar2 = getCopReg(2,0xd000);
  iVar3 = getCopReg(2,0xd800);
  return iVar1 + iVar2 + iVar3;
}





