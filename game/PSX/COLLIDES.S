// WARNING: This file's extension ('.S') indicates that it may not have been a C or C++ file.
// It should contain Ghidra's best effort at decompiling the machine language to C, 
// but TDR does not currently attempt to handle assembly language or other non-C/C++ code differently, 
// so any decompiled code below may not reflect the original project source code for this file.
// If the source file is from a library, you should replace it with the original library version of the file.
// Otherwise, manual reconstruction of the code may be required, 
// Especially if the original source code was assembly language which used hardware features inaccessible to C.
#include "THISDUST.H"
#include "COLLIDES.H"


// decompiled code
// original method signature: 
// void COLLIDE_NearestPointOnLine_S() /* COLLIDE_NearestPointOnLine_S method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 29, offset 0x80077960
	/* begin block 1 */
		// Start line: 59
	/* end block 1 */
	// End Line: 60

	/* begin block 2 */
		// Start line: 60
	/* end block 2 */
	// End Line: 61

	/* begin block 3 */
		// Start line: 61
	/* end block 3 */
	// End Line: 62

	/* begin block 4 */
		// Start line: 62
	/* end block 4 */
	// End Line: 63

	/* begin block 5 */
		// Start line: 63
	/* end block 5 */
	// End Line: 64

void COLLIDE_NearestPointOnLine_S(uint *param_1,uint *param_2,uint *param_3,uint *param_4)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 uVar14;
  
  uVar7 = *param_2;
  uVar1 = *(ushort *)(param_2 + 1);
  uVar8 = *param_3;
  uVar2 = *(ushort *)(param_3 + 1);
  setCopControlWord(2,0,uVar7);
  setCopControlWord(2,0x800,*param_4 << 0x10 | (uint)uVar1);
  setCopControlWord(2,0x1000,(uint)*(ushort *)(param_4 + 1) << 0x10 | *param_4 >> 0x10);
  uVar9 = (uVar8 & 0xffff) - (uVar7 & 0xffff);
  iVar11 = (uVar8 >> 0x10) - (uVar7 >> 0x10);
  iVar13 = (uint)uVar2 - (uint)uVar1;
  uVar3 = iVar11 * 0x10000 | uVar9 & 0xffff;
  setCopControlWord(2,0x1800,uVar3);
  setCopControlWord(2,0x2000,iVar13);
  setCopReg(2,0,uVar3);
  setCopReg(2,0x800,iVar13);
  copFunction(2,0x486012);
  iVar4 = getCopReg(2,0xc800);
  iVar5 = getCopReg(2,0xd000);
  iVar6 = getCopReg(2,0xd800);
  if (iVar6 != 0) {
    uVar3 = ((iVar4 - iVar5) * -0x1000) / iVar6;
    setCopReg(2,0x4800,uVar9);
    setCopReg(2,0x5000,iVar11);
    setCopReg(2,0x5800,iVar13);
  }
  if (0x1000 < uVar3) {
    if ((int)uVar3 < 1) {
      *param_1 = uVar7;
      *(ushort *)(param_1 + 1) = uVar1;
      return;
    }
    *param_1 = uVar8;
    *(ushort *)(param_1 + 1) = uVar2;
    return;
  }
  setCopReg(2,0x4000,uVar3);
  copFunction(2,0x198003d);
  uVar10 = getCopReg(2,0x4800);
  uVar12 = getCopReg(2,0x5000);
  uVar14 = getCopReg(2,0x5800);
  *(short *)param_1 = (short)(uVar7 & 0xffff) + (short)uVar10;
  *(short *)((int)param_1 + 2) = (short)(uVar7 >> 0x10) + (short)uVar12;
  *(ushort *)(param_1 + 1) = uVar1 + (short)uVar14;
  return;
}



// decompiled code
// original method signature: 
// void COLLIDE_IntersectLineAndPlane_S() /* COLLIDE_IntersectLineAndPlane_S method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 121, offset 0x80077a70
	/* begin block 1 */
		// Start line: 243
	/* end block 1 */
	// End Line: 244

	/* begin block 2 */
		// Start line: 244
	/* end block 2 */
	// End Line: 245

	/* begin block 3 */
		// Start line: 245
	/* end block 3 */
	// End Line: 246

	/* begin block 4 */
		// Start line: 246
	/* end block 4 */
	// End Line: 247

undefined4
COLLIDE_IntersectLineAndPlane_S
          (short *param_1,uint *param_2,uint *param_3,undefined4 *param_4,int param_5)

{
  ushort uVar1;
  undefined4 in_zero;
  undefined4 in_at;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  
  uVar2 = *param_2;
  uVar1 = *(ushort *)(param_2 + 1);
  iVar5 = (*param_3 & 0xffff) - (uVar2 & 0xffff);
  uVar7 = (*param_3 >> 0x10) - (uVar2 >> 0x10);
  iVar9 = (uint)*(ushort *)(param_3 + 1) - (uint)uVar1;
  setCopReg(2,in_zero,*param_4);
  setCopReg(2,in_at,param_4[1]);
  setCopControlWord(2,0,uVar2);
  setCopControlWord(2,0x800,(uint)uVar1 | iVar5 * 0x10000);
  setCopControlWord(2,0x1000,iVar9 * 0x10000 | uVar7 & 0xffff);
  copFunction(2,0x486012);
  iVar3 = getCopReg(2,0xc800);
  iVar4 = getCopReg(2,0xd000);
  if (iVar4 != 0) {
    uVar11 = ((iVar3 - param_5) * -0x1000) / iVar4;
    setCopReg(2,0x4800,iVar5);
    setCopReg(2,0x5000,uVar7);
    setCopReg(2,0x5800,iVar9);
    if (uVar11 < 0x1001) {
      setCopReg(2,0x4000,uVar11);
      copFunction(2,0x198003d);
      uVar6 = getCopReg(2,0x4800);
      uVar8 = getCopReg(2,0x5000);
      uVar10 = getCopReg(2,0x5800);
      *param_1 = (short)(uVar2 & 0xffff) + (short)uVar6;
      param_1[1] = (short)(uVar2 >> 0x10) + (short)uVar8;
      param_1[2] = uVar1 + (short)uVar10;
      return 1;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// void COLLIDE_NearestPointOnPlane_S() /* COLLIDE_NearestPointOnPlane_S method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 179, offset 0x80077b48
	/* begin block 1 */
		// Start line: 359
	/* end block 1 */
	// End Line: 360

	/* begin block 2 */
		// Start line: 360
	/* end block 2 */
	// End Line: 361

	/* begin block 3 */
		// Start line: 361
	/* end block 3 */
	// End Line: 362

	/* begin block 4 */
		// Start line: 362
	/* end block 4 */
	// End Line: 363

	/* begin block 5 */
		// Start line: 363
	/* end block 5 */
	// End Line: 364

	/* begin block 6 */
		// Start line: 364
	/* end block 6 */
	// End Line: 365

	/* begin block 7 */
		// Start line: 365
	/* end block 7 */
	// End Line: 366

void COLLIDE_NearestPointOnPlane_S(short *param_1,int *param_2,int param_3,undefined4 *param_4)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  uVar6 = *param_4;
  sVar1 = *(short *)(param_4 + 1);
  iVar2 = *param_2;
  setCopControlWord(2,0,uVar6);
  setCopControlWord(2,0x800,(int)sVar1);
  setCopReg(2,0,iVar2);
  setCopReg(2,0x800,(int)*(short *)(param_2 + 1));
  copFunction(2,0x486012);
  iVar7 = getCopReg(2,0xc800);
  setCopReg(2,0x4000,param_3 - iVar7);
  setCopReg(2,0x4800,(int)(short)iVar2);
  setCopReg(2,0x5000,iVar2 >> 0x10);
  setCopReg(2,0x5800,(int)*(short *)(param_2 + 1));
  copFunction(2,0x198003d);
  uVar3 = getCopReg(2,0x4800);
  uVar4 = getCopReg(2,0x5000);
  uVar5 = getCopReg(2,0x5800);
  *param_1 = (short)uVar3 + (short)uVar6;
  param_1[1] = (short)uVar4 + (short)((uint)uVar6 >> 0x10);
  param_1[2] = (short)uVar5 + sVar1;
  return;
}



// decompiled code
// original method signature: 
// void VM_ProcessVMObjectSetColor_S() /* VM_ProcessVMObjectSetColor_S method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 625, offset 0x800780cc
	/* begin block 1 */
		// Start line: 1251
	/* end block 1 */
	// End Line: 1252

	/* begin block 2 */
		// Start line: 1252
	/* end block 2 */
	// End Line: 1253

	/* begin block 3 */
		// Start line: 1253
	/* end block 3 */
	// End Line: 1254

	/* begin block 4 */
		// Start line: 1254
	/* end block 4 */
	// End Line: 1255

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VM_ProcessVMObjectSetColor_S(void)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_s2;
  undefined4 unaff_s3;
  undefined4 unaff_s4;
  undefined4 unaff_s5;
  undefined4 unaff_s6;
  undefined4 unaff_s7;
  undefined4 unaff_s8;
  undefined4 unaff_retaddr;
  
  _DAT_1f800000 = unaff_retaddr;
  _DAT_1f800004 = unaff_s0;
  _DAT_1f800008 = unaff_s1;
  _DAT_1f80000c = unaff_s2;
  _DAT_1f800010 = unaff_s3;
  _DAT_1f800014 = unaff_s4;
  DAT_1f800018 = unaff_s5;
  DAT_1f80001c = unaff_s6;
  DAT_1f800020 = unaff_s7;
  DAT_1f800024 = unaff_s8;
  FUN_80077bd4();
  return;
}



// decompiled code
// original method signature: 
// void VM_ProcessVMObjectList_S() /* VM_ProcessVMObjectList_S method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 661, offset 0x80078140
	/* begin block 1 */
		// Start line: 1323
	/* end block 1 */
	// End Line: 1324

	/* begin block 2 */
		// Start line: 1324
	/* end block 2 */
	// End Line: 1325

	/* begin block 3 */
		// Start line: 1325
	/* end block 3 */
	// End Line: 1326

	/* begin block 4 */
		// Start line: 1326
	/* end block 4 */
	// End Line: 1327

	/* begin block 5 */
		// Start line: 1327
	/* end block 5 */
	// End Line: 1328

	/* begin block 6 */
		// Start line: 1328
	/* end block 6 */
	// End Line: 1329

	/* begin block 7 */
		// Start line: 1329
	/* end block 7 */
	// End Line: 1330

	/* begin block 8 */
		// Start line: 1330
	/* end block 8 */
	// End Line: 1331

	/* begin block 9 */
		// Start line: 1331
	/* end block 9 */
	// End Line: 1332

	/* begin block 10 */
		// Start line: 1332
	/* end block 10 */
	// End Line: 1333

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VM_ProcessVMObjectList_S(int param_1)

{
  int iVar1;
  undefined4 unaff_s0;
  uint *puVar2;
  undefined4 unaff_s1;
  int iVar3;
  undefined4 unaff_s2;
  undefined4 unaff_s3;
  uint uVar4;
  undefined4 unaff_s4;
  undefined4 unaff_s5;
  undefined4 unaff_s6;
  undefined4 unaff_s7;
  undefined4 unaff_s8;
  undefined4 unaff_retaddr;
  
  iVar3 = *(int *)(param_1 + 8);
  puVar2 = *(uint **)(param_1 + 0xc);
  _DAT_1f800000 = unaff_retaddr;
  _DAT_1f800004 = unaff_s0;
  _DAT_1f800008 = unaff_s1;
  _DAT_1f80000c = unaff_s2;
  _DAT_1f800010 = unaff_s3;
  _DAT_1f800014 = unaff_s4;
  DAT_1f800018 = unaff_s5;
  DAT_1f80001c = unaff_s6;
  DAT_1f800020 = unaff_s7;
  DAT_1f800024 = unaff_s8;
  while (iVar3 != 0) {
    if ((*puVar2 & 2) == 0) {
      uVar4 = puVar2[3] + 1;
      if (*(int *)puVar2[9] <= (int)uVar4) {
        uVar4 = 0;
      }
      iVar1 = BSP_SphereIntersectsViewVolume_S(puVar2 + 4);
      puVar2[3] = uVar4;
      if (iVar1 != 0) {
        FUN_80077bd4();
      }
    }
    iVar3 = iVar3 + -1;
    puVar2 = puVar2 + 0xf;
  }
  return;
}



// decompiled code
// original method signature: 
// void BSP_SphereIntersectsViewVolume_S() /* BSP_SphereIntersectsViewVolume_S method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 732, offset 0x80078204
	/* begin block 1 */
		// Start line: 1465
	/* end block 1 */
	// End Line: 1466

	/* begin block 2 */
		// Start line: 1466
	/* end block 2 */
	// End Line: 1467

	/* begin block 3 */
		// Start line: 1467
	/* end block 3 */
	// End Line: 1468

	/* begin block 4 */
		// Start line: 1468
	/* end block 4 */
	// End Line: 1469

	/* begin block 5 */
		// Start line: 1469
	/* end block 5 */
	// End Line: 1470

	/* begin block 6 */
		// Start line: 1470
	/* end block 6 */
	// End Line: 1471

uint BSP_SphereIntersectsViewVolume_S(undefined4 *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 in_zero;
  undefined4 in_at;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  setCopControlWord(2,0,*(undefined4 *)(param_2 + 8));
  setCopControlWord(2,0x800,*(undefined4 *)(param_2 + 0xc));
  setCopControlWord(2,0x1000,*(undefined4 *)(param_2 + 0x10));
  setCopControlWord(2,0x1800,*(undefined4 *)(param_2 + 0x14));
  setCopControlWord(2,0x2000,*(undefined4 *)(param_2 + 0x18));
  setCopReg(2,in_zero,*param_1);
  setCopReg(2,in_at,param_1[1]);
  copFunction(2,0x486012);
  iVar2 = -(uint)*(ushort *)((int)param_1 + 6);
  iVar4 = getCopReg(2,0xc800);
  iVar5 = getCopReg(2,0xd000);
  iVar6 = getCopReg(2,0xd800);
  iVar4 = iVar4 - *(int *)(param_2 + 0x48);
  uVar3 = (uint)(iVar2 < iVar4);
  if (iVar2 < iVar4) {
    bVar1 = iVar4 < (int)(*(int *)(param_2 + 100) + (uint)*(ushort *)((int)param_1 + 6));
    uVar3 = (uint)bVar1;
    if (bVar1) {
      bVar1 = iVar2 < iVar5 - *(int *)(param_2 + 0x4c);
      uVar3 = (uint)bVar1;
      if ((bVar1) && (bVar1 = iVar2 < iVar6 - *(int *)(param_2 + 0x50), uVar3 = (uint)bVar1, bVar1))
      {
        setCopControlWord(2,0,*(undefined4 *)(param_2 + 0x28));
        setCopControlWord(2,0x800,*(undefined4 *)(param_2 + 0x2c));
        setCopControlWord(2,0x1000,*(undefined4 *)(param_2 + 0x30));
        copFunction(2,0x486012);
        iVar4 = getCopReg(2,0xc800);
        iVar5 = getCopReg(2,0xd000);
        bVar1 = iVar2 < iVar4 - *(int *)(param_2 + 0x54);
        uVar3 = (uint)bVar1;
        if (bVar1) {
          uVar3 = (uint)(iVar2 < iVar5 - *(int *)(param_2 + 0x58));
        }
      }
    }
  }
  return uVar3;
}



// decompiled code
// original method signature: 
// void RotMatrixZYX() /* RotMatrixZYX method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 793, offset 0x800782dc
	/* begin block 1 */
		// Start line: 1587
	/* end block 1 */
	// End Line: 1588

	/* begin block 2 */
		// Start line: 1588
	/* end block 2 */
	// End Line: 1589

	/* begin block 3 */
		// Start line: 1589
	/* end block 3 */
	// End Line: 1590

	/* begin block 4 */
		// Start line: 1590
	/* end block 4 */
	// End Line: 1591

	/* begin block 5 */
		// Start line: 1591
	/* end block 5 */
	// End Line: 1592

void RotMatrixZYX(short *param_1,uint *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  short sVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  
  iVar11 = *(int *)(&rcossin_tbl + ((int)param_1[2] & 0xfffU) * 4);
  uVar4 = iVar11 >> 0x10;
  if (((int)param_1[1] & 0xfffU | (int)*param_1 & 0xfffU) != 0) {
    iVar8 = *(int *)(&rcossin_tbl + ((int)*param_1 & 0xfffU) * 4);
    iVar6 = (int)(short)iVar11;
    iVar11 = *(int *)(&rcossin_tbl + ((int)param_1[1] & 0xfffU) * 4) >> 0x10;
    sVar5 = (short)*(int *)(&rcossin_tbl + ((int)param_1[1] & 0xfffU) * 4);
    setCopReg(2,0x4800,iVar11);
    setCopReg(2,0x5000,uVar4);
    setCopReg(2,0x5800,iVar6);
    setCopReg(2,0x4000,iVar8 >> 0x10);
    copFunction(2,0x198003d);
    *(short *)(param_2 + 3) = -sVar5;
    uVar7 = getCopReg(2,0x5000);
    uVar1 = getCopReg(2,0x4800);
    uVar9 = getCopReg(2,0x5800);
    *(short *)(param_2 + 4) = (short)uVar1;
    setCopReg(2,0x4800,iVar11);
    setCopReg(2,0x5000,uVar4);
    setCopReg(2,0x5800,iVar6);
    setCopReg(2,0x4000,(int)(short)iVar8);
    copFunction(2,0x198003d);
    *(short *)param_2 = (short)((int)(iVar11 * uVar4) >> 0xc);
    uVar1 = getCopReg(2,0x4800);
    uVar10 = getCopReg(2,0x5000);
    iVar8 = getCopReg(2,0x5800);
    *(undefined2 *)((int)param_2 + 0xe) = (short)uVar1;
    setCopReg(2,0x4800,uVar7);
    setCopReg(2,0x5000,uVar9);
    setCopReg(2,0x5800,uVar10);
    setCopReg(2,0x4000,(int)sVar5);
    copFunction(2,0x198003d);
    *(undefined2 *)((int)param_2 + 6) = (short)(iVar11 * iVar6 >> 0xc);
    uVar1 = getCopReg(2,0x4800);
    uVar2 = getCopReg(2,0x5000);
    uVar3 = getCopReg(2,0x5800);
    *(short *)((int)param_2 + 2) = (short)uVar3 - (short)uVar9;
    *(short *)(param_2 + 1) = (short)uVar1 + (short)iVar8;
    *(short *)(param_2 + 2) = (short)(iVar8 * (int)sVar5 >> 0xc) + (short)uVar7;
    *(short *)((int)param_2 + 10) = (short)uVar2 - (short)uVar10;
    return;
  }
  *param_2 = iVar11 * -0x10000 | uVar4 & 0xffff;
  param_2[1] = iVar11 * 0x10000;
  param_2[2] = uVar4 & 0xffff;
  param_2[3] = 0;
  *(undefined2 *)(param_2 + 4) = 0x1000;
  return;
}



// autogenerated function stub: 
// void rmzyx_onlyz() /* rmzyx_onlyz method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void rmzyx_onlyz() 
{ // line 891, offset 0x80078420
	/* begin block 1 */
		// Start line: 1783
	/* end block 1 */
	// End Line: 1784

	/* begin block 2 */
		// Start line: 1784
	/* end block 2 */
	// End Line: 1785

	/* begin block 3 */
		// Start line: 1785
	/* end block 3 */
	// End Line: 1786

	return null;
}


// decompiled code
// original method signature: 
// void RotMatrix() /* RotMatrix method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 907, offset 0x80078450
	/* begin block 1 */
		// Start line: 1815
	/* end block 1 */
	// End Line: 1816

	/* begin block 2 */
		// Start line: 1816
	/* end block 2 */
	// End Line: 1817

	/* begin block 3 */
		// Start line: 1817
	/* end block 3 */
	// End Line: 1818

void RotMatrix(short *param_1,uint *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  short sVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  
  iVar11 = *(int *)(&rcossin_tbl + ((int)param_1[2] & 0xfffU) * 4);
  uVar4 = iVar11 >> 0x10;
  if (((int)param_1[1] & 0xfffU | (int)*param_1 & 0xfffU) != 0) {
    iVar8 = *(int *)(&rcossin_tbl + ((int)*param_1 & 0xfffU) * 4);
    iVar6 = (int)(short)iVar11;
    iVar11 = *(int *)(&rcossin_tbl + ((int)param_1[1] & 0xfffU) * 4) >> 0x10;
    sVar5 = (short)*(int *)(&rcossin_tbl + ((int)param_1[1] & 0xfffU) * 4);
    setCopReg(2,0x4800,iVar11);
    setCopReg(2,0x5000,uVar4);
    setCopReg(2,0x5800,iVar6);
    setCopReg(2,0x4000,iVar8 >> 0x10);
    copFunction(2,0x198003d);
    *(short *)(param_2 + 1) = sVar5;
    uVar7 = getCopReg(2,0x5000);
    uVar1 = getCopReg(2,0x4800);
    uVar9 = getCopReg(2,0x5800);
    *(short *)(param_2 + 4) = (short)uVar1;
    setCopReg(2,0x4800,iVar11);
    setCopReg(2,0x5000,uVar4);
    setCopReg(2,0x5800,iVar6);
    setCopReg(2,0x4000,(int)(short)iVar8);
    copFunction(2,0x198003d);
    *(short *)param_2 = (short)((int)(iVar11 * uVar4) >> 0xc);
    uVar1 = getCopReg(2,0x4800);
    uVar10 = getCopReg(2,0x5000);
    iVar8 = getCopReg(2,0x5800);
    *(short *)((int)param_2 + 10) = -(short)uVar1;
    setCopReg(2,0x4800,uVar7);
    setCopReg(2,0x5000,uVar9);
    setCopReg(2,0x5800,uVar10);
    setCopReg(2,0x4000,(int)sVar5);
    copFunction(2,0x198003d);
    *(short *)((int)param_2 + 2) = -(short)(iVar11 * iVar6 >> 0xc);
    uVar1 = getCopReg(2,0x4800);
    uVar2 = getCopReg(2,0x5000);
    uVar3 = getCopReg(2,0x5800);
    *(short *)((int)param_2 + 6) = (short)uVar3 + (short)uVar9;
    *(short *)(param_2 + 3) = (short)iVar8 - (short)uVar1;
    *(short *)(param_2 + 2) = (short)uVar7 - (short)(iVar8 * (int)sVar5 >> 0xc);
    *(short *)((int)param_2 + 0xe) = (short)uVar2 + (short)uVar10;
    return;
  }
  *param_2 = iVar11 * -0x10000 | uVar4 & 0xffff;
  param_2[1] = iVar11 * 0x10000;
  param_2[2] = uVar4 & 0xffff;
  param_2[3] = 0;
  *(undefined2 *)(param_2 + 4) = 0x1000;
  return;
}



// autogenerated function stub: 
// void ApplyMatrix_S() /* ApplyMatrix_S method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void ApplyMatrix_S() 
{ // line 1004, offset 0x80078598
	/* begin block 1 */
		// Start line: 2009
	/* end block 1 */
	// End Line: 2010

	/* begin block 2 */
		// Start line: 2010
	/* end block 2 */
	// End Line: 2011

	return null;
}


// decompiled code
// original method signature: 
// void ScaleMatrix() /* ScaleMatrix method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 1025, offset 0x800785e8
	/* begin block 1 */
		// Start line: 2051
	/* end block 1 */
	// End Line: 2052

	/* begin block 2 */
		// Start line: 2052
	/* end block 2 */
	// End Line: 2053

	/* begin block 3 */
		// Start line: 2053
	/* end block 3 */
	// End Line: 2054

	/* begin block 4 */
		// Start line: 2054
	/* end block 4 */
	// End Line: 2055

	/* begin block 5 */
		// Start line: 2055
	/* end block 5 */
	// End Line: 2056

	/* begin block 6 */
		// Start line: 2056
	/* end block 6 */
	// End Line: 2057

int * ScaleMatrix(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  setCopReg(2,0x4800,(int)(short)*param_1);
  setCopReg(2,0x5000,param_1[1] >> 0x10);
  setCopReg(2,0x5800,(int)(short)param_1[3]);
  setCopReg(2,0x4000,*param_2);
  copFunction(2,0x198003d);
  uVar1 = getCopReg(2,0x4800);
  uVar2 = getCopReg(2,0x5000);
  uVar4 = getCopReg(2,0x5800);
  setCopReg(2,0x4000,param_2[1]);
  setCopReg(2,0x4800,*param_1 >> 0x10);
  setCopReg(2,0x5000,(int)(short)param_1[2]);
  setCopReg(2,0x5800,param_1[3] >> 0x10);
  *(short *)param_1 = (short)uVar1;
  copFunction(2,0x198003d);
  uVar1 = param_2[2];
  *(undefined2 *)((int)param_1 + 6) = (short)uVar2;
  uVar2 = getCopReg(2,0x4800);
  uVar3 = getCopReg(2,0x5000);
  uVar5 = getCopReg(2,0x5800);
  setCopReg(2,0x4000,uVar1);
  setCopReg(2,0x4800,(int)(short)param_1[1]);
  setCopReg(2,0x5000,param_1[2] >> 0x10);
  setCopReg(2,0x5800,(int)*(short *)(param_1 + 4));
  copFunction(2,0x198003d);
  *(short *)(param_1 + 3) = (short)uVar4;
  *(undefined2 *)((int)param_1 + 2) = (short)uVar2;
  *(short *)(param_1 + 2) = (short)uVar3;
  *(undefined2 *)((int)param_1 + 0xe) = (short)uVar5;
  uVar1 = getCopReg(2,0x4800);
  uVar2 = getCopReg(2,0x5000);
  uVar3 = getCopReg(2,0x5800);
  *(short *)(param_1 + 1) = (short)uVar1;
  *(undefined2 *)((int)param_1 + 10) = (short)uVar2;
  *(short *)(param_1 + 4) = (short)uVar3;
  return param_1;
}



// decompiled code
// original method signature: 
// void rsin() /* rsin method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 1090, offset 0x800786d0
	/* begin block 1 */
		// Start line: 2181
	/* end block 1 */
	// End Line: 2182

	/* begin block 2 */
		// Start line: 2182
	/* end block 2 */
	// End Line: 2183

	/* begin block 3 */
		// Start line: 2183
	/* end block 3 */
	// End Line: 2184

	/* begin block 4 */
		// Start line: 2184
	/* end block 4 */
	// End Line: 2185

	/* begin block 5 */
		// Start line: 2185
	/* end block 5 */
	// End Line: 2186

	/* begin block 6 */
		// Start line: 2186
	/* end block 6 */
	// End Line: 2187

int rsin(uint param_1)

{
  return (int)*(short *)(&rcossin_tbl + (param_1 & 0xfff) * 4);
}



// decompiled code
// original method signature: 
// void rcos() /* rcos method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 1104, offset 0x800786f0
	/* begin block 1 */
		// Start line: 2209
	/* end block 1 */
	// End Line: 2210

	/* begin block 2 */
		// Start line: 2210
	/* end block 2 */
	// End Line: 2211

int rcos(uint param_1)

{
  return (int)*(short *)(&LAB_800c7d8a + (param_1 & 0xfff) * 4);
}



// decompiled code
// original method signature: 
// void MATH3D_racos_S() /* MATH3D_racos_S method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 1114, offset 0x80078710
	/* begin block 1 */
		// Start line: 2229
	/* end block 1 */
	// End Line: 2230

	/* begin block 2 */
		// Start line: 2230
	/* end block 2 */
	// End Line: 2231

	/* begin block 3 */
		// Start line: 2231
	/* end block 3 */
	// End Line: 2232

	/* begin block 4 */
		// Start line: 2232
	/* end block 4 */
	// End Line: 2233

int MATH3D_racos_S(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = 0x200;
  iVar2 = 0x100;
  iVar4 = param_1;
  if (param_1 < 0) {
    iVar4 = -param_1;
  }
  do {
    if ((int)*(short *)(&LAB_800c7d8a + iVar1 * 4) == iVar4) break;
    iVar3 = iVar2 >> 1;
    if ((int)*(short *)(&LAB_800c7d8a + iVar1 * 4) - iVar4 < 0) {
      iVar2 = -iVar2;
    }
    iVar1 = iVar1 + iVar2;
    iVar2 = iVar3;
  } while (iVar3 != 0);
  if (param_1 < 0) {
    iVar1 = 0x800 - iVar1;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void SetGp() /* SetGp method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 1159, offset 0x80078770
	/* begin block 1 */
		// Start line: 2319
	/* end block 1 */
	// End Line: 2320

	/* begin block 2 */
		// Start line: 2320
	/* end block 2 */
	// End Line: 2321

	/* begin block 3 */
		// Start line: 2321
	/* end block 3 */
	// End Line: 2322

	/* begin block 4 */
		// Start line: 2322
	/* end block 4 */
	// End Line: 2323

	/* begin block 5 */
		// Start line: 2323
	/* end block 5 */
	// End Line: 2324

	/* begin block 6 */
		// Start line: 2324
	/* end block 6 */
	// End Line: 2325

	/* begin block 7 */
		// Start line: 2325
	/* end block 7 */
	// End Line: 2326

	/* begin block 8 */
		// Start line: 2326
	/* end block 8 */
	// End Line: 2327

void SetGp(void)

{
  return;
}



// decompiled code
// original method signature: 
// void memcpy() /* memcpy method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 1169, offset 0x80078778
	/* begin block 1 */
		// Start line: 2339
	/* end block 1 */
	// End Line: 2340

	/* begin block 2 */
		// Start line: 2340
	/* end block 2 */
	// End Line: 2341

	/* begin block 3 */
		// Start line: 2341
	/* end block 3 */
	// End Line: 2342

	/* begin block 4 */
		// Start line: 2342
	/* end block 4 */
	// End Line: 2343

	/* begin block 5 */
		// Start line: 2343
	/* end block 5 */
	// End Line: 2344

	/* begin block 6 */
		// Start line: 2344
	/* end block 6 */
	// End Line: 2345

	/* begin block 7 */
		// Start line: 2345
	/* end block 7 */
	// End Line: 2346

void * memcpy(void *__dest,void *__src,size_t __n)

{
  undefined uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  if (__n != 0) {
    puVar4 = (undefined *)__dest;
    puVar2 = (undefined4 *)__dest;
    if ((((uint)__dest | (uint)__src | __n) & 3) == 0) {
      do {
        uVar5 = *(undefined4 *)__src;
        __src = (undefined4 *)__src + 1;
        puVar3 = puVar2 + 1;
        __n = __n - 4;
        *puVar2 = uVar5;
        puVar2 = puVar3;
      } while ((__n & 0x1f) != 0);
      if (__n != 0) {
        do {
          uVar5 = *(undefined4 *)__src;
          uVar6 = ((undefined4 *)__src)[1];
          uVar7 = ((undefined4 *)__src)[2];
          uVar8 = ((undefined4 *)__src)[3];
          uVar9 = ((undefined4 *)__src)[4];
          uVar10 = ((undefined4 *)__src)[5];
          uVar11 = ((undefined4 *)__src)[6];
          uVar12 = ((undefined4 *)__src)[7];
          __n = __n - 0x20;
          __src = (undefined4 *)__src + 8;
          *puVar3 = uVar5;
          puVar3[1] = uVar6;
          puVar3[2] = uVar7;
          puVar3[3] = uVar8;
          puVar3[4] = uVar9;
          puVar3[5] = uVar10;
          puVar3[6] = uVar11;
          puVar3[7] = uVar12;
          puVar3 = puVar3 + 8;
        } while (__n != 0);
        return __dest;
      }
    }
    else {
      do {
        uVar1 = *(undefined *)__src;
        __src = (undefined *)__src + 1;
        __n = __n - 1;
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      } while (__n != 0);
    }
  }
  return __dest;
}



// decompiled code
// original method signature: 
// void BSP_MarkVisibleLeaves_S() /* BSP_MarkVisibleLeaves_S method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 1232, offset 0x80078830
	/* begin block 1 */
		// Start line: 2465
	/* end block 1 */
	// End Line: 2466

	/* begin block 2 */
		// Start line: 2466
	/* end block 2 */
	// End Line: 2467

	/* begin block 3 */
		// Start line: 2467
	/* end block 3 */
	// End Line: 2468

	/* begin block 4 */
		// Start line: 2468
	/* end block 4 */
	// End Line: 2469

	/* begin block 5 */
		// Start line: 2469
	/* end block 5 */
	// End Line: 2470

	/* begin block 6 */
		// Start line: 2470
	/* end block 6 */
	// End Line: 2471

	/* begin block 7 */
		// Start line: 2471
	/* end block 7 */
	// End Line: 2472

	/* begin block 8 */
		// Start line: 2472
	/* end block 8 */
	// End Line: 2473

	/* begin block 9 */
		// Start line: 2473
	/* end block 9 */
	// End Line: 2474

	/* begin block 10 */
		// Start line: 2474
	/* end block 10 */
	// End Line: 2475

	/* begin block 11 */
		// Start line: 2475
	/* end block 11 */
	// End Line: 2476

	/* begin block 12 */
		// Start line: 2476
	/* end block 12 */
	// End Line: 2477

	/* begin block 13 */
		// Start line: 2477
	/* end block 13 */
	// End Line: 2478

	/* begin block 14 */
		// Start line: 2478
	/* end block 14 */
	// End Line: 2479

	/* begin block 15 */
		// Start line: 2479
	/* end block 15 */
	// End Line: 2480

	/* begin block 16 */
		// Start line: 2480
	/* end block 16 */
	// End Line: 2481

	/* begin block 17 */
		// Start line: 2481
	/* end block 17 */
	// End Line: 2482

	/* begin block 18 */
		// Start line: 2482
	/* end block 18 */
	// End Line: 2483

	/* begin block 19 */
		// Start line: 2483
	/* end block 19 */
	// End Line: 2484

	/* begin block 20 */
		// Start line: 2484
	/* end block 20 */
	// End Line: 2485

	/* begin block 21 */
		// Start line: 2485
	/* end block 21 */
	// End Line: 2486

	/* begin block 22 */
		// Start line: 2486
	/* end block 22 */
	// End Line: 2487

	/* begin block 23 */
		// Start line: 2487
	/* end block 23 */
	// End Line: 2488

	/* begin block 24 */
		// Start line: 2488
	/* end block 24 */
	// End Line: 2489

	/* begin block 25 */
		// Start line: 2489
	/* end block 25 */
	// End Line: 2490

	/* begin block 26 */
		// Start line: 2490
	/* end block 26 */
	// End Line: 2491

	/* begin block 27 */
		// Start line: 2491
	/* end block 27 */
	// End Line: 2492

	/* begin block 28 */
		// Start line: 2492
	/* end block 28 */
	// End Line: 2493

	/* begin block 29 */
		// Start line: 2493
	/* end block 29 */
	// End Line: 2494

	/* begin block 30 */
		// Start line: 2494
	/* end block 30 */
	// End Line: 2495

	/* begin block 31 */
		// Start line: 2495
	/* end block 31 */
	// End Line: 2496

	/* begin block 32 */
		// Start line: 2496
	/* end block 32 */
	// End Line: 2497

	/* begin block 33 */
		// Start line: 2497
	/* end block 33 */
	// End Line: 2498

	/* begin block 34 */
		// Start line: 2498
	/* end block 34 */
	// End Line: 2499

	/* begin block 35 */
		// Start line: 2499
	/* end block 35 */
	// End Line: 2500

	/* begin block 36 */
		// Start line: 2500
	/* end block 36 */
	// End Line: 2501

	/* begin block 37 */
		// Start line: 2501
	/* end block 37 */
	// End Line: 2502

	/* begin block 38 */
		// Start line: 2502
	/* end block 38 */
	// End Line: 2503

	/* begin block 39 */
		// Start line: 2503
	/* end block 39 */
	// End Line: 2504

	/* begin block 40 */
		// Start line: 2504
	/* end block 40 */
	// End Line: 2505

	/* begin block 41 */
		// Start line: 2505
	/* end block 41 */
	// End Line: 2506

	/* begin block 42 */
		// Start line: 2506
	/* end block 42 */
	// End Line: 2507

	/* begin block 43 */
		// Start line: 2507
	/* end block 43 */
	// End Line: 2508

	/* begin block 44 */
		// Start line: 2508
	/* end block 44 */
	// End Line: 2509

	/* begin block 45 */
		// Start line: 2509
	/* end block 45 */
	// End Line: 2510

	/* begin block 46 */
		// Start line: 2510
	/* end block 46 */
	// End Line: 2511

	/* begin block 47 */
		// Start line: 2511
	/* end block 47 */
	// End Line: 2512

	/* begin block 48 */
		// Start line: 2512
	/* end block 48 */
	// End Line: 2513

	/* begin block 49 */
		// Start line: 2513
	/* end block 49 */
	// End Line: 2514

	/* begin block 50 */
		// Start line: 2514
	/* end block 50 */
	// End Line: 2515

	/* begin block 51 */
		// Start line: 2515
	/* end block 51 */
	// End Line: 2516

	/* begin block 52 */
		// Start line: 2516
	/* end block 52 */
	// End Line: 2517

	/* begin block 53 */
		// Start line: 2517
	/* end block 53 */
	// End Line: 2518

	/* begin block 54 */
		// Start line: 2518
	/* end block 54 */
	// End Line: 2519

	/* begin block 55 */
		// Start line: 2519
	/* end block 55 */
	// End Line: 2520

	/* begin block 56 */
		// Start line: 2520
	/* end block 56 */
	// End Line: 2521

	/* begin block 57 */
		// Start line: 2521
	/* end block 57 */
	// End Line: 2522

	/* begin block 58 */
		// Start line: 2522
	/* end block 58 */
	// End Line: 2523

	/* begin block 59 */
		// Start line: 2523
	/* end block 59 */
	// End Line: 2524

	/* begin block 60 */
		// Start line: 2524
	/* end block 60 */
	// End Line: 2525

	/* begin block 61 */
		// Start line: 2525
	/* end block 61 */
	// End Line: 2526

	/* begin block 62 */
		// Start line: 2526
	/* end block 62 */
	// End Line: 2527

	/* begin block 63 */
		// Start line: 2527
	/* end block 63 */
	// End Line: 2528

	/* begin block 64 */
		// Start line: 2528
	/* end block 64 */
	// End Line: 2529

	/* begin block 65 */
		// Start line: 2529
	/* end block 65 */
	// End Line: 2530

	/* begin block 66 */
		// Start line: 2530
	/* end block 66 */
	// End Line: 2531

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BSP_MarkVisibleLeaves_S(int **param_1,undefined4 *param_2,int *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int **ppiVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  undefined4 unaff_s0;
  int **ppiVar17;
  int **ppiVar18;
  undefined4 unaff_s1;
  undefined4 unaff_s2;
  undefined4 unaff_s3;
  undefined4 unaff_s4;
  undefined4 unaff_s5;
  undefined4 unaff_s6;
  undefined4 unaff_s7;
  int **ppiVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  int *piVar22;
  undefined4 unaff_s8;
  undefined4 unaff_retaddr;
  
  DAT_1f8000c0 = &DAT_1f8000c0;
  ppiVar19 = (int **)(param_3 + 1);
  iVar15 = depthQFogFar;
  if ((int)param_2[0x19] <= depthQFogFar) {
    iVar15 = param_2[0x19];
  }
  puVar1 = param_2 + 2;
  puVar2 = (undefined4 *)&DAT_1f800000;
  iVar4 = 0x40;
  DAT_1f800098 = unaff_s0;
  DAT_1f80009c = unaff_s1;
  DAT_1f8000a0 = unaff_s2;
  _DAT_1f8000a4 = unaff_s3;
  _DAT_1f8000a8 = unaff_s4;
  DAT_1f8000ac = unaff_s5;
  DAT_1f8000b0 = unaff_s6;
  DAT_1f8000b4 = unaff_s7;
  _DAT_1f8000b8 = unaff_s8;
  DAT_1f8000bc = unaff_retaddr;
  do {
    uVar16 = puVar1[1];
    uVar20 = puVar1[2];
    uVar21 = puVar1[3];
    *puVar2 = *puVar1;
    puVar2[1] = uVar16;
    puVar2[2] = uVar20;
    puVar2[3] = uVar21;
    puVar1 = puVar1 + 4;
    iVar4 = iVar4 + -0x10;
    puVar2 = puVar2 + 4;
  } while (iVar4 != 0);
  _DAT_1f800040 = *param_2;
  setCopControlWord(2,0,_DAT_1f800000);
  setCopControlWord(2,0x800,_DAT_1f800004);
  setCopControlWord(2,0x1000,_DAT_1f800008);
  setCopControlWord(2,0x1800,_DAT_1f80000c);
  setCopControlWord(2,0x2000,(uint)DAT_1f800010);
  setCopReg(2,0,_DAT_1f800040);
  setCopReg(2,0x800,(int)*(short *)(param_2 + 1));
  copFunction(2,0x486012);
  _DAT_1f800060 = getCopReg(2,0x19);
  _DAT_1f800064 = getCopReg(2,0x1a);
  _DAT_1f800068 = getCopReg(2,0x1b);
  setCopControlWord(2,0,DAT_1f800020);
  setCopControlWord(2,0x800,DAT_1f800024);
  setCopControlWord(2,0x1000,DAT_1f800028);
  copFunction(2,0x486012);
  puVar1 = (undefined4 *)param_2[0x1d];
  DAT_1f80006c = getCopReg(2,0x19);
  DAT_1f800070 = getCopReg(2,0x1a);
  iVar4 = (iVar15 << 0xf) / (int)param_2[0x1a];
  setCopReg(2,0x800,iVar15);
  setCopControlWord(2,0,*puVar1);
  setCopControlWord(2,0x800,puVar1[1]);
  setCopControlWord(2,0x1000,puVar1[2]);
  setCopControlWord(2,0x1800,puVar1[3]);
  setCopControlWord(2,0x2000,(uint)*(ushort *)(puVar1 + 4));
  uVar5 = (param_2[0x28] + -0xa0) * iVar4 >> 0xf & 0xffff;
  uVar6 = (param_2[0x2a] + -0x78) * iVar4 * 2 & 0xffff0000;
  uVar8 = (param_2[0x29] + -0xa0) * iVar4 >> 0xf & 0xffff;
  uVar10 = (param_2[0x2b] + -0x78) * iVar4 * 2 & 0xffff0000;
  setCopReg(2,0,uVar5 | uVar6);
  copFunction(2,0x486012);
  uVar16 = getCopReg(2,0x4800);
  uVar13 = getCopReg(2,0x5000);
  iVar15 = getCopReg(2,0x5800);
  setCopReg(2,0,uVar8 | uVar6);
  _DAT_1f800044 = CONCAT22((short)uVar16,*(short *)(param_2 + 1));
  _DAT_1f800048 = uVar13 & 0xffff | iVar15 << 0x10;
  copFunction(2,0x486012);
  uVar6 = getCopReg(2,0x4800);
  iVar15 = getCopReg(2,0x5000);
  uVar16 = getCopReg(2,0x5800);
  setCopReg(2,0,uVar8 | uVar10);
  _DAT_1f80004c = uVar6 & 0xffff | iVar15 << 0x10;
  DAT_1f800050 = (ushort)uVar16;
  copFunction(2,0x486012);
  uVar6 = getCopReg(2,0x4800);
  iVar15 = getCopReg(2,0x5000);
  uVar8 = getCopReg(2,0x5800);
  setCopReg(2,0,uVar5 | uVar10);
  DAT_1f800074 = uVar6 & 0xffff | iVar15 << 0x10;
  copFunction(2,0x486012);
  iVar15 = getCopReg(2,0x4800);
  uVar5 = getCopReg(2,0x5000);
  iVar4 = getCopReg(2,0x5800);
  DAT_1f800078 = uVar8 & 0xffff | iVar15 << 0x10;
  _DAT_1f80007c = uVar5 & 0xffff | iVar4 << 0x10;
  iVar15 = 2;
  if ((gameTrackerX.gameData.asmData.MorphTime == 1000) &&
     (iVar15 = 0, gameTrackerX.gameData.asmData.MorphType != 0)) {
    iVar15 = 1;
  }
  setCopControlWord(2,0,_DAT_1f800000);
  setCopControlWord(2,0x800,_DAT_1f800004);
  setCopControlWord(2,0x1000,_DAT_1f800008);
  setCopControlWord(2,0x1800,_DAT_1f80000c);
  setCopControlWord(2,0x2000,(uint)DAT_1f800010);
  param_1 = (int **)*param_1;
  ppiVar17 = (int **)&DAT_1f8000c4;
  do {
    ppiVar18 = ppiVar17 + -1;
    setCopReg(2,0,*param_1);
    setCopReg(2,0x800,param_1[1]);
    copFunction(2,0x486012);
    iVar4 = -((int)param_1[1] >> 0x10);
    if (iVar15 == 2) {
      iVar4 = iVar4 + -0x800;
    }
    iVar7 = getCopReg(2,0xc800);
    iVar9 = getCopReg(2,0xd000);
    iVar11 = getCopReg(2,0xd800);
    if (((iVar4 < iVar7 - _DAT_1f800060) && (iVar4 < iVar9 - _DAT_1f800064)) &&
       (iVar4 < iVar11 - _DAT_1f800068)) {
      setCopControlWord(2,0,DAT_1f800020);
      setCopControlWord(2,0x800,DAT_1f800024);
      setCopControlWord(2,0x1000,DAT_1f800028);
      copFunction(2,0x486012);
      iVar7 = getCopReg(2,0xc800);
      iVar9 = getCopReg(2,0xd000);
      if ((iVar4 < iVar7 - DAT_1f80006c) && (iVar4 < iVar9 - DAT_1f800070)) {
        if ((*(ushort *)((int)param_1 + 0xe) & 1) == 0) {
          *(int ***)ppiVar19 = param_1;
          ppiVar19 = ppiVar19 + 1;
        }
        else {
          ppiVar12 = param_1 + 10;
          if (iVar15 != 0) {
            ppiVar12 = param_1 + 9;
          }
          setCopControlWord(2,0,_DAT_1f800040);
          setCopControlWord(2,0x800,_DAT_1f800044);
          setCopControlWord(2,0x1000,_DAT_1f800048);
          setCopControlWord(2,0x1800,_DAT_1f80004c);
          setCopControlWord(2,0x2000,(uint)DAT_1f800050);
          setCopReg(2,0,param_1[2]);
          setCopReg(2,0x800,param_1[3]);
          copFunction(2,0x486012);
          iVar14 = (int)*ppiVar12 >> 0x10;
          iVar11 = (int)(short)*ppiVar12;
          piVar3 = param_1[5];
          piVar22 = param_1[6];
          iVar4 = getCopReg(2,0xc800);
          iVar7 = getCopReg(2,0xd000);
          iVar9 = getCopReg(2,0xd800);
          iVar4 = iVar4 - (int)param_1[4];
          if (iVar4 < 0) {
            if (piVar3 != (int *)0x0) {
              if (((iVar4 < iVar14) && (iVar7 + iVar4 < iVar14)) && (iVar9 + iVar4 < iVar14)) {
                setCopControlWord(2,0,DAT_1f800074);
                setCopControlWord(2,0x800,DAT_1f800078);
                setCopControlWord(2,0x1000,_DAT_1f80007c);
                copFunction(2,0x486012);
                iVar7 = getCopReg(2,0xc800);
                iVar9 = getCopReg(2,0xd000);
                if ((iVar7 + iVar4 < iVar14) && (iVar9 + iVar4 < iVar14)) goto LAB_80078d68;
              }
              *ppiVar17 = piVar3;
              ppiVar18 = ppiVar17;
            }
LAB_80078d68:
            if (piVar22 != (int *)0x0) {
              ppiVar18[1] = piVar22;
              ppiVar18 = ppiVar18 + 1;
            }
          }
          else {
            if (piVar22 != (int *)0x0) {
              if (((iVar11 < iVar4) && (iVar11 < iVar7 + iVar4)) && (iVar11 < iVar9 + iVar4)) {
                setCopControlWord(2,0,DAT_1f800074);
                setCopControlWord(2,0x800,DAT_1f800078);
                setCopControlWord(2,0x1000,_DAT_1f80007c);
                copFunction(2,0x486012);
                iVar7 = getCopReg(2,0xc800);
                iVar9 = getCopReg(2,0xd000);
                if ((iVar11 < iVar7 + iVar4) && (iVar11 < iVar9 + iVar4)) goto LAB_80078cd8;
              }
              *ppiVar17 = piVar22;
              ppiVar18 = ppiVar17;
            }
LAB_80078cd8:
            if (piVar3 != (int *)0x0) {
              ppiVar18[1] = piVar3;
              ppiVar18 = ppiVar18 + 1;
            }
          }
        }
      }
      setCopControlWord(2,0,_DAT_1f800000);
      setCopControlWord(2,0x800,_DAT_1f800004);
      setCopControlWord(2,0x1000,_DAT_1f800008);
      setCopControlWord(2,0x1800,_DAT_1f80000c);
      setCopControlWord(2,0x2000,(uint)DAT_1f800010);
    }
    param_1 = (int **)*ppiVar18;
    ppiVar17 = ppiVar18;
    if (param_1 == ppiVar18) {
      *param_3 = (int)ppiVar19 + (-4 - (int)param_3) >> 2;
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void G2Quat_FromMatrix_S() /* G2Quat_FromMatrix_S method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 1857, offset 0x80078e00
	/* begin block 1 */
		// Start line: 3715
	/* end block 1 */
	// End Line: 3716

	/* begin block 2 */
		// Start line: 3716
	/* end block 2 */
	// End Line: 3717

	/* begin block 3 */
		// Start line: 3717
	/* end block 3 */
	// End Line: 3718

	/* begin block 4 */
		// Start line: 3718
	/* end block 4 */
	// End Line: 3719

	/* begin block 5 */
		// Start line: 3719
	/* end block 5 */
	// End Line: 3720

	/* begin block 6 */
		// Start line: 3720
	/* end block 6 */
	// End Line: 3721

	/* begin block 7 */
		// Start line: 3721
	/* end block 7 */
	// End Line: 3722

	/* begin block 8 */
		// Start line: 3722
	/* end block 8 */
	// End Line: 3723

	/* begin block 9 */
		// Start line: 3723
	/* end block 9 */
	// End Line: 3724

	/* begin block 10 */
		// Start line: 3724
	/* end block 10 */
	// End Line: 3725

	/* begin block 11 */
		// Start line: 3725
	/* end block 11 */
	// End Line: 3726

	/* begin block 12 */
		// Start line: 3726
	/* end block 12 */
	// End Line: 3727

	/* begin block 13 */
		// Start line: 3727
	/* end block 13 */
	// End Line: 3728

int G2EulerAngles_ToMatrix_S(undefined2 *param_1,short *param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  short *psVar11;
  int iVar12;
  short *psVar13;
  int iVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  
  iVar9 = (int)*param_2;
  iVar12 = (int)param_2[4];
  iVar14 = (int)param_2[8];
  iVar8 = iVar9 + iVar12 + iVar14;
  if (0 < iVar8) {
    lVar7 = MATH3D_FastSqrt(iVar8 + 0x1000);
    sVar1 = param_2[7];
    sVar2 = param_2[5];
    sVar3 = param_2[2];
    sVar4 = param_2[6];
    sVar5 = param_2[3];
    sVar6 = param_2[1];
    param_1[3] = (short)(lVar7 >> 1);
    setCopReg(2,0x4800,(int)sVar1 - (int)sVar2);
    setCopReg(2,0x5000,(int)sVar3 - (int)sVar4);
    setCopReg(2,0x5800,(int)sVar5 - (int)sVar6);
    setCopReg(2,0x4000,0x800000 / lVar7);
    copFunction(2,0x198003d);
    uVar10 = getCopReg(2,0x4800);
    uVar15 = getCopReg(2,0x5000);
    uVar16 = getCopReg(2,0x5800);
    *param_1 = (short)uVar10;
    param_1[1] = (short)uVar15;
    param_1[2] = (short)uVar16;
    return 0x800000 / lVar7;
  }
  iVar19 = 0;
  iVar20 = 2;
  iVar21 = 4;
  iVar8 = iVar9;
  iVar17 = iVar12;
  iVar18 = iVar14;
  if (iVar9 < iVar12) {
    iVar19 = 2;
    iVar20 = 4;
    iVar21 = 0;
    iVar8 = iVar12;
    iVar17 = iVar14;
    iVar18 = iVar9;
  }
  if (iVar8 < iVar14) {
    iVar19 = 4;
    iVar20 = 0;
    iVar21 = 2;
    iVar8 = iVar14;
    iVar17 = iVar9;
    iVar18 = iVar12;
  }
  lVar7 = MATH3D_FastSqrt((iVar8 - (iVar17 + iVar18)) + 0x1000);
  *(undefined2 *)((int)param_1 + iVar19) = (short)(lVar7 >> 1);
  psVar11 = (short *)(iVar19 * 3 + (int)param_2);
  psVar13 = (short *)(iVar20 * 3 + (int)param_2);
  param_2 = (short *)(iVar21 * 3 + (int)param_2);
  setCopReg(2,0x4000,0x800000 / lVar7);
  setCopReg(2,0x4800,(int)*(short *)((int)param_2 + iVar20) - (int)*(short *)((int)psVar13 + iVar21)
           );
  setCopReg(2,0x5000,(int)*(short *)((int)psVar13 + iVar19) + (int)*(short *)((int)psVar11 + iVar20)
           );
  setCopReg(2,0x5800,(int)*(short *)((int)param_2 + iVar19) + (int)*(short *)((int)psVar11 + iVar21)
           );
  copFunction(2,0x198003d);
  uVar10 = getCopReg(2,0x4800);
  uVar15 = getCopReg(2,0x5000);
  uVar16 = getCopReg(2,0x5800);
  param_1[3] = (short)uVar10;
  *(undefined2 *)(iVar20 + (int)param_1) = (short)uVar15;
  *(undefined2 *)(iVar21 + (int)param_1) = (short)uVar16;
  return 0x800000 / lVar7;
}



// decompiled code
// original method signature: 
// void G2Quat_ToMatrix_S() /* G2Quat_ToMatrix_S method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 2035, offset 0x8007900c
	/* begin block 1 */
		// Start line: 4071
	/* end block 1 */
	// End Line: 4072

	/* begin block 2 */
		// Start line: 4072
	/* end block 2 */
	// End Line: 4073

	/* begin block 3 */
		// Start line: 4073
	/* end block 3 */
	// End Line: 4074

	/* begin block 4 */
		// Start line: 4074
	/* end block 4 */
	// End Line: 4075

	/* begin block 5 */
		// Start line: 4075
	/* end block 5 */
	// End Line: 4076

void G2Quat_ToMatrix_S(short *param_1,short *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  
  iVar7 = (int)*param_1;
  iVar13 = (int)param_1[3];
  iVar9 = (int)param_1[1];
  iVar11 = (int)param_1[2];
  setCopReg(2,0x4000,iVar7 << 1);
  setCopReg(2,0x4800,iVar7);
  setCopReg(2,0x5000,iVar13);
  setCopReg(2,0x5800,iVar9);
  copFunction(2,0x198003d);
  uVar1 = getCopReg(2,0xc800);
  uVar2 = getCopReg(2,0xd000);
  uVar3 = getCopReg(2,0xd800);
  setCopReg(2,0x4000,iVar9 << 1);
  setCopReg(2,0x4800,iVar9);
  setCopReg(2,0x5000,iVar13);
  setCopReg(2,0x5800,iVar11);
  copFunction(2,0x198003d);
  uVar4 = getCopReg(2,0xc800);
  uVar5 = getCopReg(2,0xd000);
  uVar6 = getCopReg(2,0xd800);
  setCopReg(2,0x4000,iVar11 << 1);
  setCopReg(2,0x4800,iVar11);
  setCopReg(2,0x5000,iVar13);
  setCopReg(2,0x5800,iVar7);
  copFunction(2,0x198003d);
  param_2[7] = (short)uVar6 + (short)uVar2;
  param_2[8] = 0x1000 - ((short)uVar1 + (short)uVar4);
  uVar8 = getCopReg(2,0xc800);
  uVar10 = getCopReg(2,0xd000);
  uVar12 = getCopReg(2,0xd800);
  *param_2 = 0x1000 - ((short)uVar4 + (short)uVar8);
  param_2[1] = (short)uVar3 - (short)uVar10;
  param_2[2] = (short)uVar12 + (short)uVar5;
  param_2[3] = (short)uVar3 + (short)uVar10;
  param_2[4] = 0x1000 - ((short)uVar1 + (short)uVar8);
  param_2[5] = (short)uVar6 - (short)uVar2;
  param_2[6] = (short)uVar12 - (short)uVar5;
  return;
}



// decompiled code
// original method signature: 
// void G2Quat_FromEuler_S() /* G2Quat_FromEuler_S method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 2116, offset 0x800790fc
	/* begin block 1 */
		// Start line: 4233
	/* end block 1 */
	// End Line: 4234

	/* begin block 2 */
		// Start line: 4234
	/* end block 2 */
	// End Line: 4235

	/* begin block 3 */
		// Start line: 4235
	/* end block 3 */
	// End Line: 4236

	/* begin block 4 */
		// Start line: 4236
	/* end block 4 */
	// End Line: 4237

	/* begin block 5 */
		// Start line: 4237
	/* end block 5 */
	// End Line: 4238

	/* begin block 6 */
		// Start line: 4238
	/* end block 6 */
	// End Line: 4239

	/* begin block 7 */
		// Start line: 4239
	/* end block 7 */
	// End Line: 4240

	/* begin block 8 */
		// Start line: 4240
	/* end block 8 */
	// End Line: 4241

	/* begin block 9 */
		// Start line: 4241
	/* end block 9 */
	// End Line: 4242

void G2Quat_FromEuler_S(int param_1,short *param_2)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined2 uVar11;
  int iVar12;
  undefined2 uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  
  iVar7 = (int)param_2[1];
  uVar1 = SEXT24(param_2[3]);
  iVar18 = (int)*param_2;
  iVar15 = (int)param_2[2];
  if ((uVar1 & 1) != 0) {
    iVar18 = (int)param_2[2];
    iVar15 = (int)*param_2;
  }
  if ((uVar1 & 4) != 0) {
    iVar7 = -iVar7;
  }
  iVar9 = *(int *)(&rcossin_tbl + (iVar7 >> 1 & 0xfffU) * 4) >> 0x10;
  iVar8 = (int)(short)*(int *)(&rcossin_tbl + (iVar7 >> 1 & 0xfffU) * 4);
  iVar14 = *(int *)(&rcossin_tbl + (iVar15 >> 1 & 0xfffU) * 4) >> 0x10;
  iVar7 = (int)(short)*(int *)(&rcossin_tbl + (iVar15 >> 1 & 0xfffU) * 4);
  setCopReg(2,0x4000,*(int *)(&rcossin_tbl + (iVar18 >> 1 & 0xfffU) * 4) >> 0x10);
  setCopReg(2,0x4800,iVar14);
  setCopReg(2,0x5000,iVar7);
  copFunction(2,0x198003d);
  iVar15 = getCopReg(2,0x4800);
  iVar17 = getCopReg(2,0x5000);
  setCopReg(2,0x4000,(int)(short)*(int *)(&rcossin_tbl + (iVar18 >> 1 & 0xfffU) * 4));
  setCopReg(2,0x4800,iVar14);
  setCopReg(2,0x5000,iVar7);
  copFunction(2,0x198003d);
  iVar7 = (int)(uVar1 & 0x18) >> 2;
  iVar18 = getCopReg(2,0x4800);
  iVar14 = getCopReg(2,0x5000);
  if ((uVar1 & 2) == 0) {
    setCopReg(2,0x4000,iVar9);
    setCopReg(2,0x4800,iVar18);
    setCopReg(2,0x5000,iVar14);
    setCopReg(2,0x5800,iVar17);
    copFunction(2,0x190003d);
    iVar2 = (int)(uVar1 & 4) >> 1;
    iVar4 = getCopReg(2,0xc800);
    iVar6 = getCopReg(2,0xd000);
    iVar12 = getCopReg(2,0xd800);
    setCopReg(2,0x4000,iVar8);
    setCopReg(2,0x4800,iVar17);
    setCopReg(2,0x5000,iVar15);
    setCopReg(2,0x5800,iVar18);
    copFunction(2,0x190003d);
    uVar1 = iVar7 + iVar2 + 2;
    if (4 < uVar1) {
      uVar1 = (iVar7 + iVar2) - 4;
    }
    iVar18 = (iVar7 - iVar2) + 4;
    iVar17 = getCopReg(2,0xc800);
    if (4 < iVar18) {
      iVar18 = (iVar7 - iVar2) + -2;
    }
    iVar10 = getCopReg(2,0xd000);
    iVar16 = getCopReg(2,0xd800);
    uVar3 = (undefined2)(iVar4 - iVar17 >> 0xc);
    sVar5 = (short)(iVar6 + iVar10 >> 0xc);
    uVar11 = (undefined2)(iVar12 - iVar16 >> 0xc);
    uVar13 = (undefined2)(iVar9 * iVar15 + iVar8 * iVar14 >> 0xc);
  }
  else {
    setCopReg(2,0x4000,iVar9);
    setCopReg(2,0x4800,iVar17 + iVar18);
    setCopReg(2,0x5000,iVar15 - iVar14);
    copFunction(2,0x198003d);
    iVar2 = (int)(uVar1 & 4) >> 1;
    _uVar3 = getCopReg(2,0x4800);
    uVar3 = (undefined2)_uVar3;
    _uVar3 = getCopReg(2,0x5000);
    uVar13 = (undefined2)_uVar3;
    setCopReg(2,0x4000,iVar8);
    setCopReg(2,0x4800,iVar15 + iVar14);
    setCopReg(2,0x5000,iVar17 - iVar18);
    copFunction(2,0x198003d);
    uVar1 = iVar7 + iVar2 + 2;
    if (4 < uVar1) {
      uVar1 = (iVar7 + iVar2) - 4;
    }
    iVar18 = (iVar7 - iVar2) + 4;
    _uVar3 = getCopReg(2,0x4800);
    sVar5 = (short)_uVar3;
    if (4 < iVar18) {
      iVar18 = (iVar7 - iVar2) + -2;
    }
    _uVar3 = getCopReg(2,0x5000);
    uVar11 = (undefined2)_uVar3;
  }
  if (iVar2 != 0) {
    sVar5 = -sVar5;
  }
  *(undefined2 *)(iVar7 + param_1) = uVar3;
  *(short *)(uVar1 + param_1) = sVar5;
  *(undefined2 *)(iVar18 + param_1) = uVar11;
  *(undefined2 *)(param_1 + 6) = uVar13;
  return;
}





