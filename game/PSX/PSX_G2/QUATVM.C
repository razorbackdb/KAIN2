#include "THISDUST.H"
#include "QUATVM.H"


// decompiled code
// original method signature: 
// void /*$ra*/ G2Quat_Slerp_VM(long ratio /*$s2*/, struct _G2Quat_Type *quatA /*$s3*/, struct _G2Quat_Type *quatB /*$s5*/, struct _G2Quat_Type *quatOut /*$s6*/, int spin /*stack 16*/)
 // line 93, offset 0x80094138
	/* begin block 1 */
		// Start line: 94
		// Start offset: 0x80094138
		// Variables:
	// 		long beta; // $s1
	// 		short theta; // $s0
	// 		short cos_t; // $a0
	// 		long bflip; // $s4
	// 		long foo[4]; // stack offset -56
	// 		long cosTemp1; // $v1
	// 		long cosTemp2; // stack offset -40
	/* end block 1 */
	// End offset: 0x80094284
	// End Line: 150

	/* begin block 2 */
		// Start line: 135
	/* end block 2 */
	// End Line: 136

	/* begin block 3 */
		// Start line: 173
	/* end block 3 */
	// End Line: 174

void G2Quat_Slerp_VM(long ratio,_G2Quat_Type *quatA,_G2Quat_Type *quatB,_G2Quat_Type *quatOut,
                    int spin)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  short sVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  
  setCopReg(2,0x4800,(uint)(ushort)quatA->x);
  setCopReg(2,0x5000,(uint)(ushort)quatA->y);
  setCopReg(2,0x5800,(uint)(ushort)quatA->z);
  setCopControlWord(2,0,(uint)(ushort)(quatB->x | quatB->y));
  setCopControlWord(2,0x800,(uint)(ushort)quatB->z);
  copFunction(2,0x49e012);
  uVar11 = getCopReg(2,0x19);
  iVar5 = (uVar11 & 0xffff) + ((int)quatA->w * (int)quatB->w >> 0xc);
  bVar1 = iVar5 * 0x10000 < 0;
  sVar7 = (short)iVar5;
  if (bVar1) {
    sVar7 = -sVar7;
  }
  iVar5 = 0x1000 - ratio;
  if (0 < 0x1000 - (int)sVar7) {
    iVar5 = MATH3D_racos_S((int)sVar7);
    iVar2 = rsin((int)(short)iVar5);
    uVar11 = ratio * ((iVar5 + spin * 0x1000) * 0x10000 >> 0x10) >> 0xc;
    iVar5 = rsin((int)(short)iVar5 - uVar11);
    iVar5 = (iVar5 << 0xc) / (int)(short)iVar2;
    iVar3 = rsin(uVar11);
    ratio = (iVar3 << 0xc) / (int)(short)iVar2;
  }
  if (bVar1) {
    ratio = -ratio;
  }
  setCopReg(2,0x4800,(uint)(ushort)quatA->x);
  setCopReg(2,0x5000,(uint)(ushort)quatA->y);
  setCopReg(2,0x5800,(uint)(ushort)quatA->z);
  setCopReg(2,0x4000,iVar5);
  copFunction(2,0x198003d);
  setCopReg(2,0x4800,(uint)(ushort)quatB->x);
  setCopReg(2,0x5000,(uint)(ushort)quatB->y);
  setCopReg(2,0x5800,(uint)(ushort)quatB->z);
  setCopReg(2,0x4000,ratio);
  copFunction(2,0x1a8003e);
  iVar6 = (iVar5 * quatA->w >> 0xc) + (ratio * quatB->w >> 0xc);
  iVar5 = getCopReg(2,9);
  iVar2 = getCopReg(2,10);
  iVar3 = getCopReg(2,0xb);
  lVar4 = MATH3D_FastSqrt(iVar6 * iVar6 + iVar5 * iVar5 + iVar2 * iVar2 + iVar3 * iVar3 + 0x800 >>
                          0xc);
  setCopReg(2,0x4000,0x1000000 / lVar4);
  copFunction(2,0x198003d);
  quatOut->w = (short)(iVar6 * (0x1000000 / lVar4) >> 0xc);
  uVar8 = getCopReg(2,0x4800);
  uVar9 = getCopReg(2,0x5000);
  uVar10 = getCopReg(2,0x5800);
  quatOut->x = (short)uVar8;
  quatOut->y = (short)uVar9;
  quatOut->z = (short)uVar10;
  return;
}





