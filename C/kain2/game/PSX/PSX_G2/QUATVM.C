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

void G2Quat_Slerp_VM(long ratio,_G2Quat_Type *quatA,_G2Quat_Type *quatB,_G2Quat_Type *quatOut,
                    int spin)

{
  uint uVar1;
  int ratio_00;
  short sVar2;
  int local_38;
  
  setCopReg(2,0x4800,(uint)(ushort)quatA->x);
  setCopReg(2,0x5000,(uint)(ushort)quatA->y);
  setCopReg(2,0x5800,(uint)(ushort)quatA->z);
  setCopControlWord(2,0,(uint)(ushort)(quatB->x | quatB->y));
  setCopControlWord(2,0x800,(uint)(ushort)quatB->z);
  copFunction(2,0x49e012);
  uVar1 = getCopReg(2,0x19);
  ratio_00 = (uVar1 & 0xffff) + ((int)quatA->w * (int)quatB->w >> 0xc);
  sVar2 = (short)ratio_00;
  if (ratio_00 * 0x10000 < 0) {
    sVar2 = -sVar2;
  }
  ratio_00 = (int)sVar2;
  if (0 < 0x1000 - ratio_00) {
    ratio_00 = MATH3D_racos_S(ratio_00);
                    /* WARNING: Subroutine does not return */
    rsin((int)(short)ratio_00);
  }
  G2Quat_Slerp_VM(ratio_00,quatA,quatB,quatOut,local_38);
  return;
}





