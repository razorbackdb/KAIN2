#include "THISDUST.H"
#include "QUATVM.H"

// decompiled code
// original method signature:
// void /*$ra*/ G2Quat_Slerp_VM(long ratio /*$s2*/, struct _G2Quat_Type *quatA /*$s3*/, struct _G2Quat_Type *quatB /*$s5*/, struct _G2Quat_Type *quatOut /*$s6*/, int spin /*stack 16*/)
// line 93, offset 0x800962f4
/* begin block 1 */
// Start line: 94
// Start offset: 0x800962F4
// Variables:
// 		long beta; // $s1
// 		short theta; // $s0
// 		short cos_t; // $a0
// 		long bflip; // $s4
// 		long foo[4]; // stack offset -56
// 		long cosTemp1; // $v1
// 		long cosTemp2; // stack offset -40
/* end block 1 */
// End offset: 0x80096440
// End Line: 150

/* begin block 2 */
// Start line: 135
/* end block 2 */
// End Line: 136

/* begin block 3 */
// Start line: 186
/* end block 3 */
// End Line: 187

void G2Quat_Slerp_VM(long ratio, _G2Quat_Type *quatA, _G2Quat_Type *quatB, _G2Quat_Type *quatOut,
                     int spin)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;

  setCopReg(2, 0x4800, (uint)(ushort)quatA->x);
  setCopReg(2, 0x5000, (uint)(ushort)quatA->y);
  setCopReg(2, 0x5800, (uint)(ushort)quatA->z);
  setCopControlWord(2, 0, (uint)(ushort)(quatB->x | quatB->y));
  setCopControlWord(2, 0x800, (uint)(ushort)quatB->z);
  copFunction(2, 0x49e012);
  uVar2 = getCopReg(2, 0x19);
  iVar6 = (uVar2 & 0xffff) + ((int)quatA->w * (int)quatB->w >> 0xc);
  bVar1 = iVar6 * 0x10000 < 0;
  sVar8 = (short)iVar6;
  if (bVar1)
  {
    sVar8 = -sVar8;
  }
  iVar6 = 0x1000 - ratio;
  if (0x1000 - (int)sVar8 < 1)
  {
    if (bVar1)
    {
      ratio = -ratio;
    }
    setCopReg(2, 0x4800, (uint)(ushort)quatA->x);
    setCopReg(2, 0x5000, (uint)(ushort)quatA->y);
    setCopReg(2, 0x5800, (uint)(ushort)quatA->z);
    setCopReg(2, 0x4000, iVar6);
    copFunction(2, 0x198003d);
    setCopReg(2, 0x4800, (uint)(ushort)quatB->x);
    setCopReg(2, 0x5000, (uint)(ushort)quatB->y);
    setCopReg(2, 0x5800, (uint)(ushort)quatB->z);
    setCopReg(2, 0x4000, ratio);
    copFunction(2, 0x1a8003e);
    iVar7 = (iVar6 * quatA->w >> 0xc) + (ratio * quatB->w >> 0xc);
    iVar6 = getCopReg(2, 9);
    iVar3 = getCopReg(2, 10);
    iVar4 = getCopReg(2, 0xb);
    lVar5 = MATH3D_FastSqrt(iVar7 * iVar7 + iVar6 * iVar6 + iVar3 * iVar3 + iVar4 * iVar4 + 0x800 >>
                            0xc);
    setCopReg(2, 0x4000, 0x1000000 / lVar5);
    copFunction(2, 0x198003d);
    quatOut->w = (short)(iVar7 * (0x1000000 / lVar5) >> 0xc);
    uVar9 = getCopReg(2, 0x4800);
    uVar10 = getCopReg(2, 0x5000);
    uVar11 = getCopReg(2, 0x5800);
    quatOut->x = (short)uVar9;
    quatOut->y = (short)uVar10;
    quatOut->z = (short)uVar11;
    return;
  }
  iVar6 = MATH3D_racos_S((int)sVar8);
  /* WARNING: Subroutine does not return */
  rsin((int)(short)iVar6);
}
