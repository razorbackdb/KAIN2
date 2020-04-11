
#include "QUATG2.H"


// decompiled code
// original method signature: 
// void /*$ra*/ G2Quat_ToEuler(struct _G2Quat_Type *quat /*$a0*/, struct _G2EulerAngles_Type *euler /*$s0*/, int order /*$s1*/)
 // line 74, offset 0x80095918
	/* begin block 1 */
		// Start line: 75
		// Start offset: 0x80095918
		// Variables:
	// 		struct _G2Matrix_Type tempMatrix; // stack offset -48
	/* end block 1 */
	// End offset: 0x80095918
	// End Line: 75

	/* begin block 2 */
		// Start line: 148
	/* end block 2 */
	// End Line: 149

/* File: C:\kain2\game\G2\QUATG2.C */

void G2Quat_ToEuler(_G2Quat_Type *quat,_G2EulerAngles_Type *euler,int order)

{
  _G2Matrix_Type _Stack48;
  
  G2Quat_ToMatrix_S((short *)quat,(short *)&_Stack48);
  G2EulerAngles_FromMatrix(euler,&_Stack48,order);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EulerAngles_FromMatrix(struct _G2EulerAngles_Type *euler /*$s3*/, struct _G2Matrix_Type *matrix /*$s4*/, long order /*stack 8*/)
 // line 328, offset 0x8009595c
	/* begin block 1 */
		// Start line: 329
		// Start offset: 0x8009595C
		// Variables:
	// 		long i; // $a2
	// 		long j; // $s5
	// 		long k; // stack offset -56
	// 		long n; // stack offset -52
	// 		long s; // $a1
	// 		long f; // stack offset -48

		/* begin block 1.1 */
			// Start line: 329
			// Start offset: 0x8009595C
			// Variables:
		// 		unsigned int o; // $v1
		/* end block 1.1 */
		// End offset: 0x8009595C
		// End Line: 329

		/* begin block 1.2 */
			// Start line: 336
			// Start offset: 0x800959FC
			// Variables:
		// 		long sy; // $s0
		/* end block 1.2 */
		// End offset: 0x80095ACC
		// End Line: 349

		/* begin block 1.3 */
			// Start line: 356
			// Start offset: 0x80095B08
			// Variables:
		// 		long cy; // $s5
		/* end block 1.3 */
		// End offset: 0x80095C30
		// End Line: 375

		/* begin block 1.4 */
			// Start line: 384
			// Start offset: 0x80095C74
			// Variables:
		// 		short t; // $v1
		/* end block 1.4 */
		// End offset: 0x80095C84
		// End Line: 387
	/* end block 1 */
	// End offset: 0x80095C84
	// End Line: 389

	/* begin block 2 */
		// Start line: 646
	/* end block 2 */
	// End Line: 647

/* File: C:\kain2\game\G2\QUATG2.C */

void G2EulerAngles_FromMatrix(_G2EulerAngles_Type *euler,_G2Matrix_Type *matrix,long order)

{
  short sVar1;
  uint uVar2;
  int y;
  int iVar3;
  long x;
  long lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  short local_res8;
  
  uVar5 = (uint)order >> 2 & 1;
  uVar6 = (uint)*(byte *)((int)&PTR_LAB_800d09cc + ((uint)order >> 3 & 3));
  uVar7 = (uint)(byte)(&DAT_800d09d4)[uVar6 + uVar5];
  uVar2 = (uint)(byte)(&DAT_800d09d4)[uVar6 - (uVar5 - 1)];
  if (((uint)order >> 1 & 1) == 1) {
    y = (int)matrix->rotScale[uVar6 * 3 + uVar7];
    iVar3 = (int)matrix->rotScale[uVar6 * 3 + uVar2];
    y = MATH3D_FastSqrt(y * y + iVar3 * iVar3 >> 0xc);
    if (y < 0x11) {
      x = ratan2(-(int)matrix->rotScale[uVar7 * 3 + uVar2],(int)matrix->rotScale[uVar7 * 4]);
      euler->x = (short)x;
      x = (long)matrix->rotScale[uVar6 * 4];
LAB_80095c20:
      x = ratan2(y,x);
      euler->y = (short)x;
      euler->z = 0;
      goto LAB_80095c30;
    }
    x = ratan2((int)matrix->rotScale[uVar6 * 3 + uVar7],(int)matrix->rotScale[uVar6 * 3 + uVar2]);
    euler->x = (short)x;
    x = ratan2(y,(int)matrix->rotScale[uVar6 * 4]);
    euler->y = (short)x;
    sVar1 = matrix->rotScale[uVar7 * 3 + uVar6];
    y = -(int)matrix->rotScale[uVar2 * 3 + uVar6];
  }
  else {
    y = (int)matrix->rotScale[uVar6 * 4];
    iVar3 = (int)matrix->rotScale[uVar7 * 3 + uVar6];
    x = MATH3D_FastSqrt(y * y + iVar3 * iVar3 >> 0xc);
    if (x < 0x11) {
      lVar4 = ratan2(-(int)matrix->rotScale[uVar7 * 3 + uVar2],(int)matrix->rotScale[uVar7 * 4]);
      euler->x = (short)lVar4;
      y = -(int)matrix->rotScale[uVar2 * 3 + uVar6];
      goto LAB_80095c20;
    }
    lVar4 = ratan2((int)matrix->rotScale[uVar2 * 3 + uVar7],(int)matrix->rotScale[uVar2 * 4]);
    euler->x = (short)lVar4;
    x = ratan2(-(int)matrix->rotScale[uVar2 * 3 + uVar6],x);
    euler->y = (short)x;
    sVar1 = matrix->rotScale[uVar7 * 3 + uVar6];
    y = (int)matrix->rotScale[uVar6 * 4];
  }
  x = ratan2((int)sVar1,y);
  euler->z = (short)x;
LAB_80095c30:
  if (uVar5 == 1) {
    euler->x = -euler->x;
    euler->z = -euler->z;
    euler->y = -euler->y;
  }
  if ((order & 1U) == 1) {
    sVar1 = euler->x;
    euler->x = euler->z;
    euler->z = sVar1;
  }
  local_res8 = (short)order;
  euler->order = local_res8;
  return;
}





