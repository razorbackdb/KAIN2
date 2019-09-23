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
 // line 32, offset 0x80077f3c
	/* begin block 1 */
		// Start line: 65
	/* end block 1 */
	// End Line: 66

	/* begin block 2 */
		// Start line: 66
	/* end block 2 */
	// End Line: 67

	/* begin block 3 */
		// Start line: 67
	/* end block 3 */
	// End Line: 68

	/* begin block 4 */
		// Start line: 68
	/* end block 4 */
	// End Line: 69

	/* begin block 5 */
		// Start line: 69
	/* end block 5 */
	// End Line: 70

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
 // line 124, offset 0x8007804c
	/* begin block 1 */
		// Start line: 249
	/* end block 1 */
	// End Line: 250

	/* begin block 2 */
		// Start line: 250
	/* end block 2 */
	// End Line: 251

	/* begin block 3 */
		// Start line: 251
	/* end block 3 */
	// End Line: 252

	/* begin block 4 */
		// Start line: 252
	/* end block 4 */
	// End Line: 253

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
  undefined *puVar11;
  
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
    puVar11 = (undefined *)(((iVar3 - param_5) * -0x1000) / iVar4);
    setCopReg(2,0x4800,iVar5);
    setCopReg(2,0x5000,uVar7);
    setCopReg(2,0x5800,iVar9);
    if (puVar11 < &DAT_00001001) {
      setCopReg(2,0x4000,puVar11);
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
 // line 182, offset 0x80078124
	/* begin block 1 */
		// Start line: 365
	/* end block 1 */
	// End Line: 366

	/* begin block 2 */
		// Start line: 366
	/* end block 2 */
	// End Line: 367

	/* begin block 3 */
		// Start line: 367
	/* end block 3 */
	// End Line: 368

	/* begin block 4 */
		// Start line: 368
	/* end block 4 */
	// End Line: 369

	/* begin block 5 */
		// Start line: 369
	/* end block 5 */
	// End Line: 370

	/* begin block 6 */
		// Start line: 370
	/* end block 6 */
	// End Line: 371

	/* begin block 7 */
		// Start line: 371
	/* end block 7 */
	// End Line: 372

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
 // line 628, offset 0x800786a8
	/* begin block 1 */
		// Start line: 1257
	/* end block 1 */
	// End Line: 1258

	/* begin block 2 */
		// Start line: 1258
	/* end block 2 */
	// End Line: 1259

	/* begin block 3 */
		// Start line: 1259
	/* end block 3 */
	// End Line: 1260

	/* begin block 4 */
		// Start line: 1260
	/* end block 4 */
	// End Line: 1261

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
  FUN_800781b0();
  return;
}



// decompiled code
// original method signature: 
// void VM_ProcessVMObjectList_S() /* VM_ProcessVMObjectList_S method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 664, offset 0x8007871c
	/* begin block 1 */
		// Start line: 1329
	/* end block 1 */
	// End Line: 1330

	/* begin block 2 */
		// Start line: 1330
	/* end block 2 */
	// End Line: 1331

	/* begin block 3 */
		// Start line: 1331
	/* end block 3 */
	// End Line: 1332

	/* begin block 4 */
		// Start line: 1332
	/* end block 4 */
	// End Line: 1333

	/* begin block 5 */
		// Start line: 1333
	/* end block 5 */
	// End Line: 1334

	/* begin block 6 */
		// Start line: 1334
	/* end block 6 */
	// End Line: 1335

	/* begin block 7 */
		// Start line: 1335
	/* end block 7 */
	// End Line: 1336

	/* begin block 8 */
		// Start line: 1336
	/* end block 8 */
	// End Line: 1337

	/* begin block 9 */
		// Start line: 1337
	/* end block 9 */
	// End Line: 1338

	/* begin block 10 */
		// Start line: 1338
	/* end block 10 */
	// End Line: 1339

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
        FUN_800781b0();
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
 // line 735, offset 0x800787e0
	/* begin block 1 */
		// Start line: 1471
	/* end block 1 */
	// End Line: 1472

	/* begin block 2 */
		// Start line: 1472
	/* end block 2 */
	// End Line: 1473

	/* begin block 3 */
		// Start line: 1473
	/* end block 3 */
	// End Line: 1474

	/* begin block 4 */
		// Start line: 1474
	/* end block 4 */
	// End Line: 1475

	/* begin block 5 */
		// Start line: 1475
	/* end block 5 */
	// End Line: 1476

	/* begin block 6 */
		// Start line: 1476
	/* end block 6 */
	// End Line: 1477

uint BSP_SphereIntersectsViewVolume_S(undefined4 *puParm1,int iParm2)

{
  bool bVar1;
  int iVar2;
  undefined4 in_zero;
  undefined4 in_at;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  setCopControlWord(2,0,*(undefined4 *)(iParm2 + 8));
  setCopControlWord(2,0x800,*(undefined4 *)(iParm2 + 0xc));
  setCopControlWord(2,0x1000,*(undefined4 *)(iParm2 + 0x10));
  setCopControlWord(2,0x1800,*(undefined4 *)(iParm2 + 0x14));
  setCopControlWord(2,0x2000,*(undefined4 *)(iParm2 + 0x18));
  setCopReg(2,in_zero,*puParm1);
  setCopReg(2,in_at,puParm1[1]);
  copFunction(2,0x486012);
  iVar2 = -(uint)*(ushort *)((int)puParm1 + 6);
  iVar4 = getCopReg(2,0xc800);
  iVar5 = getCopReg(2,0xd000);
  iVar6 = getCopReg(2,0xd800);
  iVar4 = iVar4 - *(int *)(iParm2 + 0x48);
  uVar3 = (uint)(iVar2 < iVar4);
  if (iVar2 < iVar4) {
    bVar1 = iVar4 < (int)(*(int *)(iParm2 + 100) + (uint)*(ushort *)((int)puParm1 + 6));
    uVar3 = (uint)bVar1;
    if (bVar1) {
      bVar1 = iVar2 < iVar5 - *(int *)(iParm2 + 0x4c);
      uVar3 = (uint)bVar1;
      if ((bVar1) && (bVar1 = iVar2 < iVar6 - *(int *)(iParm2 + 0x50), uVar3 = (uint)bVar1, bVar1))
      {
        setCopControlWord(2,0,*(undefined4 *)(iParm2 + 0x28));
        setCopControlWord(2,0x800,*(undefined4 *)(iParm2 + 0x2c));
        setCopControlWord(2,0x1000,*(undefined4 *)(iParm2 + 0x30));
        copFunction(2,0x486012);
        iVar4 = getCopReg(2,0xc800);
        iVar5 = getCopReg(2,0xd000);
        bVar1 = iVar2 < iVar4 - *(int *)(iParm2 + 0x54);
        uVar3 = (uint)bVar1;
        if (bVar1) {
          uVar3 = (uint)(iVar2 < iVar5 - *(int *)(iParm2 + 0x58));
        }
      }
    }
  }
  return uVar3;
}



// decompiled code
// original method signature: 
// void RotMatrixZYX() /* RotMatrixZYX method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 796, offset 0x800788b8
	/* begin block 1 */
		// Start line: 1593
	/* end block 1 */
	// End Line: 1594

	/* begin block 2 */
		// Start line: 1594
	/* end block 2 */
	// End Line: 1595

	/* begin block 3 */
		// Start line: 1595
	/* end block 3 */
	// End Line: 1596

	/* begin block 4 */
		// Start line: 1596
	/* end block 4 */
	// End Line: 1597

	/* begin block 5 */
		// Start line: 1597
	/* end block 5 */
	// End Line: 1598

	/* begin block 6 */
		// Start line: 1598
	/* end block 6 */
	// End Line: 1599

void RotMatrixZYX(ushort *param_1,uint *param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  
  uVar1 = param_1[1];
  uVar2 = *param_1;
  uVar4 = (int)(short)param_1[2] & 0x7ff;
  iVar12 = (int)ecostable[uVar4];
  uVar4 = SEXT24(SHORT_ARRAY_800c9910[uVar4]);
  if (((int)(short)param_1[2] & 0x800U) != 0) {
    iVar12 = -iVar12;
    uVar4 = -uVar4;
  }
  if ((uVar1 | uVar2) != 0) {
    uVar5 = (int)(short)uVar1 & 0x7ff;
    iVar11 = (int)ecostable[uVar5];
    iVar8 = (int)SHORT_ARRAY_800c9910[uVar5];
    if (((int)(short)uVar1 & 0x800U) != 0) {
      iVar8 = -iVar8;
      iVar11 = -iVar11;
    }
    uVar5 = (int)(short)uVar2 & 0x7ff;
    iVar10 = (int)ecostable[uVar5];
    iVar6 = (int)SHORT_ARRAY_800c9910[uVar5];
    if (((int)(short)uVar2 & 0x800U) != 0) {
      iVar10 = -iVar10;
      iVar6 = -iVar6;
    }
    setCopReg(2,0x4800,iVar8);
    setCopReg(2,0x5000,uVar4);
    setCopReg(2,0x5800,iVar12);
    setCopReg(2,0x4000,iVar6);
    copFunction(2,0x198003d);
    *(short *)(param_2 + 3) = -(short)iVar11;
    uVar13 = getCopReg(2,0x5000);
    uVar3 = getCopReg(2,0x4800);
    uVar14 = getCopReg(2,0x5800);
    *(short *)(param_2 + 4) = (short)uVar3;
    setCopReg(2,0x4800,iVar8);
    setCopReg(2,0x5000,uVar4);
    setCopReg(2,0x5800,iVar12);
    setCopReg(2,0x4000,iVar10);
    copFunction(2,0x198003d);
    *(short *)param_2 = (short)((int)(iVar8 * uVar4) >> 0xc);
    uVar3 = getCopReg(2,0x4800);
    uVar15 = getCopReg(2,0x5000);
    iVar10 = getCopReg(2,0x5800);
    *(undefined2 *)((int)param_2 + 0xe) = (short)uVar3;
    setCopReg(2,0x4800,uVar13);
    setCopReg(2,0x5000,uVar14);
    setCopReg(2,0x5800,uVar15);
    setCopReg(2,0x4000,iVar11);
    copFunction(2,0x198003d);
    *(undefined2 *)((int)param_2 + 6) = (short)(iVar8 * iVar12 >> 0xc);
    uVar3 = getCopReg(2,0x4800);
    uVar7 = getCopReg(2,0x5000);
    uVar9 = getCopReg(2,0x5800);
    *(short *)((int)param_2 + 2) = (short)uVar9 - (short)uVar14;
    *(short *)(param_2 + 1) = (short)uVar3 + (short)iVar10;
    *(short *)(param_2 + 2) = (short)(iVar10 * iVar11 >> 0xc) + (short)uVar13;
    *(short *)((int)param_2 + 10) = (short)uVar7 - (short)uVar15;
    return;
  }
  *param_2 = iVar12 * -0x10000 | uVar4 & 0xffff;
  param_2[1] = iVar12 * 0x10000;
  param_2[2] = uVar4 & 0xffff;
  param_2[3] = 0;
  *(undefined2 *)(param_2 + 4) = 0x1000;
  return;
}



// autogenerated function stub: 
// void rmzyx_1() /* rmzyx_1 method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void rmzyx_1() 
{ // line 818, offset 0x800788f4
	/* begin block 1 */
		// Start line: 1637
	/* end block 1 */
	// End Line: 1638

	/* begin block 2 */
		// Start line: 1638
	/* end block 2 */
	// End Line: 1639

	return null;
}


// autogenerated function stub: 
// void rmzyx_2() /* rmzyx_2 method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void rmzyx_2() 
{ // line 834, offset 0x80078928
	/* begin block 1 */
		// Start line: 1669
	/* end block 1 */
	// End Line: 1670

	/* begin block 2 */
		// Start line: 1670
	/* end block 2 */
	// End Line: 1671

	return null;
}


// autogenerated function stub: 
// void rmzyx_3() /* rmzyx_3 method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void rmzyx_3() 
{ // line 846, offset 0x80078950
	/* begin block 1 */
		// Start line: 1693
	/* end block 1 */
	// End Line: 1694

	/* begin block 2 */
		// Start line: 1694
	/* end block 2 */
	// End Line: 1695

	/* begin block 3 */
		// Start line: 1695
	/* end block 3 */
	// End Line: 1696

	/* begin block 4 */
		// Start line: 1696
	/* end block 4 */
	// End Line: 1697

	return null;
}


// autogenerated function stub: 
// void rmzyx_onlyz() /* rmzyx_onlyz method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void rmzyx_onlyz() 
{ // line 903, offset 0x80078a20
	/* begin block 1 */
		// Start line: 1807
	/* end block 1 */
	// End Line: 1808

	/* begin block 2 */
		// Start line: 1808
	/* end block 2 */
	// End Line: 1809

	/* begin block 3 */
		// Start line: 1809
	/* end block 3 */
	// End Line: 1810

	return null;
}


// decompiled code
// original method signature: 
// void RotMatrix() /* RotMatrix method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 918, offset 0x80078a4c
	/* begin block 1 */
		// Start line: 1837
	/* end block 1 */
	// End Line: 1838

	/* begin block 2 */
		// Start line: 1838
	/* end block 2 */
	// End Line: 1839

	/* begin block 3 */
		// Start line: 1839
	/* end block 3 */
	// End Line: 1840

void RotMatrix(ushort *param_1,uint *param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  
  uVar1 = param_1[1];
  uVar2 = *param_1;
  uVar4 = (int)(short)param_1[2] & 0x7ff;
  iVar12 = (int)ecostable[uVar4];
  uVar4 = SEXT24(SHORT_ARRAY_800c9910[uVar4]);
  if (((int)(short)param_1[2] & 0x800U) != 0) {
    iVar12 = -iVar12;
    uVar4 = -uVar4;
  }
  if ((uVar1 | uVar2) != 0) {
    uVar5 = (int)(short)uVar1 & 0x7ff;
    iVar11 = (int)ecostable[uVar5];
    iVar8 = (int)SHORT_ARRAY_800c9910[uVar5];
    if (((int)(short)uVar1 & 0x800U) != 0) {
      iVar8 = -iVar8;
      iVar11 = -iVar11;
    }
    uVar5 = (int)(short)uVar2 & 0x7ff;
    iVar10 = (int)ecostable[uVar5];
    iVar6 = (int)SHORT_ARRAY_800c9910[uVar5];
    if (((int)(short)uVar2 & 0x800U) != 0) {
      iVar10 = -iVar10;
      iVar6 = -iVar6;
    }
    setCopReg(2,0x4800,iVar8);
    setCopReg(2,0x5000,uVar4);
    setCopReg(2,0x5800,iVar12);
    setCopReg(2,0x4000,iVar6);
    copFunction(2,0x198003d);
    *(short *)(param_2 + 1) = (short)iVar11;
    uVar13 = getCopReg(2,0x5000);
    uVar3 = getCopReg(2,0x4800);
    uVar14 = getCopReg(2,0x5800);
    *(short *)(param_2 + 4) = (short)uVar3;
    setCopReg(2,0x4800,iVar8);
    setCopReg(2,0x5000,uVar4);
    setCopReg(2,0x5800,iVar12);
    setCopReg(2,0x4000,iVar10);
    copFunction(2,0x198003d);
    *(short *)param_2 = (short)((int)(iVar8 * uVar4) >> 0xc);
    uVar3 = getCopReg(2,0x4800);
    uVar15 = getCopReg(2,0x5000);
    iVar10 = getCopReg(2,0x5800);
    *(short *)((int)param_2 + 10) = -(short)uVar3;
    setCopReg(2,0x4800,uVar13);
    setCopReg(2,0x5000,uVar14);
    setCopReg(2,0x5800,uVar15);
    setCopReg(2,0x4000,iVar11);
    copFunction(2,0x198003d);
    *(short *)((int)param_2 + 2) = -(short)(iVar8 * iVar12 >> 0xc);
    uVar3 = getCopReg(2,0x4800);
    uVar7 = getCopReg(2,0x5000);
    uVar9 = getCopReg(2,0x5800);
    *(short *)((int)param_2 + 6) = (short)uVar9 + (short)uVar14;
    *(short *)(param_2 + 3) = (short)iVar10 - (short)uVar3;
    *(short *)(param_2 + 2) = (short)uVar13 - (short)(iVar10 * iVar11 >> 0xc);
    *(short *)((int)param_2 + 0xe) = (short)uVar7 + (short)uVar15;
    return;
  }
  *param_2 = iVar12 * -0x10000 | uVar4 & 0xffff;
  param_2[1] = iVar12 * 0x10000;
  param_2[2] = uVar4 & 0xffff;
  param_2[3] = 0;
  *(undefined2 *)(param_2 + 4) = 0x1000;
  return;
}



// autogenerated function stub: 
// void rm_1() /* rm_1 method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void rm_1() 
{ // line 937, offset 0x80078a88
	/* begin block 1 */
		// Start line: 1875
	/* end block 1 */
	// End Line: 1876

	/* begin block 2 */
		// Start line: 1876
	/* end block 2 */
	// End Line: 1877

	return null;
}


// autogenerated function stub: 
// void rm_2() /* rm_2 method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void rm_2() 
{ // line 953, offset 0x80078abc
	/* begin block 1 */
		// Start line: 1907
	/* end block 1 */
	// End Line: 1908

	/* begin block 2 */
		// Start line: 1908
	/* end block 2 */
	// End Line: 1909

	return null;
}


// autogenerated function stub: 
// void rm_3() /* rm_3 method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void rm_3() 
{ // line 965, offset 0x80078ae4
	/* begin block 1 */
		// Start line: 1931
	/* end block 1 */
	// End Line: 1932

	/* begin block 2 */
		// Start line: 1932
	/* end block 2 */
	// End Line: 1933

	/* begin block 3 */
		// Start line: 1933
	/* end block 3 */
	// End Line: 1934

	/* begin block 4 */
		// Start line: 1934
	/* end block 4 */
	// End Line: 1935

	return null;
}


// decompiled code
// original method signature: 
// void RotMatrixX() /* RotMatrixX method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 1023, offset 0x80078bb8
	/* begin block 1 */
		// Start line: 2047
	/* end block 1 */
	// End Line: 2048

	/* begin block 2 */
		// Start line: 2048
	/* end block 2 */
	// End Line: 2049

	/* begin block 3 */
		// Start line: 2049
	/* end block 3 */
	// End Line: 2050

	/* begin block 4 */
		// Start line: 2050
	/* end block 4 */
	// End Line: 2051

undefined8 RotMatrixX(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  
  iVar2 = (int)SHORT_ARRAY_800c9910[param_1 & 0x7ff];
  iVar3 = (int)ecostable[param_1 & 0x7ff];
  if ((param_1 & 0x800) != 0) {
    iVar2 = -iVar2;
    iVar3 = -iVar3;
  }
  setCopReg(2,0x4000,iVar2);
  setCopReg(2,0x4800,(int)*(short *)(param_2 + 6));
  iVar7 = *(int *)(param_2 + 8) >> 0x10;
  iVar6 = (int)(short)*(int *)(param_2 + 8);
  setCopReg(2,0x5000,iVar6);
  setCopReg(2,0x5800,iVar7);
  copFunction(2,0x198003d);
  iVar10 = *(int *)(param_2 + 0xc) >> 0x10;
  iVar9 = (int)(short)*(int *)(param_2 + 0xc);
  uVar11 = getCopReg(2,0x4800);
  iVar12 = getCopReg(2,0x5000);
  iVar13 = getCopReg(2,0x5800);
  setCopReg(2,0x4000,iVar3);
  setCopReg(2,0x4800,iVar9);
  setCopReg(2,0x5000,iVar10);
  setCopReg(2,0x5800,(int)*(short *)(param_2 + 0x10));
  copFunction(2,0x198003d);
  uVar4 = getCopReg(2,0x4800);
  iVar1 = getCopReg(2,0x5000);
  iVar5 = getCopReg(2,0x5800);
  setCopReg(2,0x4800,(int)*(short *)(param_2 + 6));
  setCopReg(2,0x5000,iVar6);
  setCopReg(2,0x5800,iVar7);
  copFunction(2,0x198003d);
  iVar6 = getCopReg(2,0x4800);
  iVar7 = getCopReg(2,0x5000);
  uVar8 = getCopReg(2,0x5800);
  setCopReg(2,0x4000,iVar2);
  setCopReg(2,0x4800,iVar9);
  setCopReg(2,0x5000,iVar10);
  setCopReg(2,0x5800,(int)*(short *)(param_2 + 0x10));
  copFunction(2,0x198003d);
  *(short *)(param_2 + 6) = (short)uVar11 - (short)uVar4;
  *(uint *)(param_2 + 8) = iVar12 - iVar1 & 0xffffU | (iVar13 - iVar5) * 0x10000;
  iVar1 = getCopReg(2,0x4800);
  iVar5 = getCopReg(2,0x5000);
  uVar4 = getCopReg(2,0x5800);
  *(uint *)(param_2 + 0xc) = iVar6 + iVar1 & 0xffffU | (iVar7 + iVar5) * 0x10000;
  *(short *)(param_2 + 0x10) = (short)uVar8 + (short)uVar4;
  return CONCAT44(iVar2,iVar3);
}



// autogenerated function stub: 
// void RMX_0() /* RMX_0 method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void RMX_0() 
{ // line 1039, offset 0x80078be8
	/* begin block 1 */
		// Start line: 2079
	/* end block 1 */
	// End Line: 2080

	/* begin block 2 */
		// Start line: 2080
	/* end block 2 */
	// End Line: 2081

	return null;
}


// decompiled code
// original method signature: 
// void RotMatrixY() /* RotMatrixY method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 1114, offset 0x80078cec
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

undefined8 RotMatrixY(uint param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  
  iVar2 = (int)SHORT_ARRAY_800c9910[param_1 & 0x7ff];
  iVar3 = (int)ecostable[param_1 & 0x7ff];
  if ((param_1 & 0x800) != 0) {
    iVar2 = -iVar2;
    iVar3 = -iVar3;
  }
  setCopReg(2,0x4000,iVar2);
  setCopReg(2,0x5800,(int)*(short *)(param_2 + 1));
  iVar7 = (int)*param_2 >> 0x10;
  iVar6 = (int)(short)*param_2;
  setCopReg(2,0x4800,iVar6);
  setCopReg(2,0x5000,iVar7);
  copFunction(2,0x198003d);
  iVar10 = (int)param_2[3] >> 0x10;
  iVar9 = (int)(short)param_2[3];
  iVar11 = getCopReg(2,0x4800);
  iVar12 = getCopReg(2,0x5000);
  uVar13 = getCopReg(2,0x5800);
  setCopReg(2,0x4000,iVar3);
  setCopReg(2,0x4800,iVar9);
  setCopReg(2,0x5000,iVar10);
  setCopReg(2,0x5800,(int)*(short *)(param_2 + 4));
  copFunction(2,0x198003d);
  iVar4 = getCopReg(2,0x4800);
  iVar1 = getCopReg(2,0x5000);
  uVar5 = getCopReg(2,0x5800);
  setCopReg(2,0x4800,iVar6);
  setCopReg(2,0x5000,iVar7);
  setCopReg(2,0x5800,(int)*(short *)(param_2 + 1));
  copFunction(2,0x198003d);
  iVar6 = getCopReg(2,0x4800);
  iVar7 = getCopReg(2,0x5000);
  uVar8 = getCopReg(2,0x5800);
  setCopReg(2,0x4000,iVar2);
  setCopReg(2,0x4800,iVar9);
  setCopReg(2,0x5000,iVar10);
  setCopReg(2,0x5800,(int)*(short *)(param_2 + 4));
  copFunction(2,0x198003d);
  *param_2 = iVar11 + iVar4 & 0xffffU | (iVar12 + iVar1) * 0x10000;
  *(short *)(param_2 + 1) = (short)uVar13 + (short)uVar5;
  iVar1 = getCopReg(2,0x4800);
  iVar4 = getCopReg(2,0x5000);
  uVar5 = getCopReg(2,0x5800);
  param_2[3] = iVar1 - iVar6 & 0xffffU | (iVar4 - iVar7) * 0x10000;
  *(short *)(param_2 + 4) = (short)uVar5 - (short)uVar8;
  return CONCAT44(iVar2,iVar3);
}



// autogenerated function stub: 
// void RMY_0() /* RMY_0 method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void RMY_0() 
{ // line 1129, offset 0x80078d1c
	/* begin block 1 */
		// Start line: 2259
	/* end block 1 */
	// End Line: 2260

	/* begin block 2 */
		// Start line: 2260
	/* end block 2 */
	// End Line: 2261

	return null;
}


// decompiled code
// original method signature: 
// void RotMatrixZ() /* RotMatrixZ method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 1200, offset 0x80078e20
	/* begin block 1 */
		// Start line: 2401
	/* end block 1 */
	// End Line: 2402

	/* begin block 2 */
		// Start line: 2402
	/* end block 2 */
	// End Line: 2403

undefined8 RotMatrixZ(uint param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  
  iVar2 = (int)SHORT_ARRAY_800c9910[param_1 & 0x7ff];
  iVar3 = (int)ecostable[param_1 & 0x7ff];
  if ((param_1 & 0x800) != 0) {
    iVar2 = -iVar2;
    iVar3 = -iVar3;
  }
  iVar7 = (int)*param_2 >> 0x10;
  iVar6 = (int)(short)*param_2;
  iVar9 = (int)param_2[1] >> 0x10;
  iVar8 = (int)(short)param_2[1];
  setCopReg(2,0x4000,iVar2);
  setCopReg(2,0x4800,iVar6);
  setCopReg(2,0x5000,iVar7);
  setCopReg(2,0x5800,iVar8);
  copFunction(2,0x198003d);
  iVar11 = (int)param_2[2] >> 0x10;
  iVar10 = (int)(short)param_2[2];
  iVar12 = getCopReg(2,0x4800);
  iVar13 = getCopReg(2,0x5000);
  iVar14 = getCopReg(2,0x5800);
  setCopReg(2,0x4000,iVar3);
  setCopReg(2,0x4800,iVar9);
  setCopReg(2,0x5000,iVar10);
  setCopReg(2,0x5800,iVar11);
  copFunction(2,0x198003d);
  iVar4 = getCopReg(2,0x4800);
  iVar1 = getCopReg(2,0x5000);
  iVar5 = getCopReg(2,0x5800);
  setCopReg(2,0x4800,iVar6);
  setCopReg(2,0x5000,iVar7);
  setCopReg(2,0x5800,iVar8);
  copFunction(2,0x198003d);
  iVar6 = getCopReg(2,0x4800);
  iVar7 = getCopReg(2,0x5000);
  iVar8 = getCopReg(2,0x5800);
  setCopReg(2,0x4000,iVar2);
  setCopReg(2,0x4800,iVar9);
  setCopReg(2,0x5000,iVar10);
  setCopReg(2,0x5800,iVar11);
  copFunction(2,0x198003d);
  *param_2 = iVar12 - iVar4 & 0xffffU | (iVar13 - iVar1) * 0x10000;
  iVar1 = getCopReg(2,0x4800);
  iVar4 = getCopReg(2,0x5000);
  iVar9 = getCopReg(2,0x5800);
  param_2[1] = iVar14 - iVar5 & 0xffffU | (iVar6 + iVar1) * 0x10000;
  param_2[2] = iVar7 + iVar4 & 0xffffU | (iVar8 + iVar9) * 0x10000;
  return CONCAT44(iVar2,iVar3);
}



// autogenerated function stub: 
// void RMZ_0() /* RMZ_0 method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void RMZ_0() 
{ // line 1214, offset 0x80078e50
	/* begin block 1 */
		// Start line: 2429
	/* end block 1 */
	// End Line: 2430

	/* begin block 2 */
		// Start line: 2430
	/* end block 2 */
	// End Line: 2431

	return null;
}


// autogenerated function stub: 
// void ApplyMatrix_S() /* ApplyMatrix_S method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void ApplyMatrix_S() 
{ // line 1295, offset 0x80078f60
	/* begin block 1 */
		// Start line: 2591
	/* end block 1 */
	// End Line: 2592

	/* begin block 2 */
		// Start line: 2592
	/* end block 2 */
	// End Line: 2593

	/* begin block 3 */
		// Start line: 2593
	/* end block 3 */
	// End Line: 2594

	/* begin block 4 */
		// Start line: 2594
	/* end block 4 */
	// End Line: 2595

	return null;
}


// decompiled code
// original method signature: 
// void ScaleMatrix() /* ScaleMatrix method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 1318, offset 0x80078fb0
	/* begin block 1 */
		// Start line: 2637
	/* end block 1 */
	// End Line: 2638

	/* begin block 2 */
		// Start line: 2638
	/* end block 2 */
	// End Line: 2639

	/* begin block 3 */
		// Start line: 2639
	/* end block 3 */
	// End Line: 2640

	/* begin block 4 */
		// Start line: 2640
	/* end block 4 */
	// End Line: 2641

	/* begin block 5 */
		// Start line: 2641
	/* end block 5 */
	// End Line: 2642

	/* begin block 6 */
		// Start line: 2642
	/* end block 6 */
	// End Line: 2643

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
 // line 1383, offset 0x80079098
	/* begin block 1 */
		// Start line: 2767
	/* end block 1 */
	// End Line: 2768

	/* begin block 2 */
		// Start line: 2768
	/* end block 2 */
	// End Line: 2769

	/* begin block 3 */
		// Start line: 2769
	/* end block 3 */
	// End Line: 2770

	/* begin block 4 */
		// Start line: 2770
	/* end block 4 */
	// End Line: 2771

int rsin(uint param_1)

{
  int iVar1;
  
  iVar1 = (int)ecostable[param_1 & 0x7ff];
  if ((param_1 & 0x800) != 0) {
    iVar1 = -iVar1;
  }
  return iVar1;
}



// autogenerated function stub: 
// void rsin_exit() /* rsin_exit method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void rsin_exit() 
{ // line 1397, offset 0x800790c0
	/* begin block 1 */
		// Start line: 2795
	/* end block 1 */
	// End Line: 2796

	return null;
}


// decompiled code
// original method signature: 
// void rcos() /* rcos method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 1400, offset 0x800790c8
	/* begin block 1 */
		// Start line: 2801
	/* end block 1 */
	// End Line: 2802

	/* begin block 2 */
		// Start line: 2802
	/* end block 2 */
	// End Line: 2803

int rcos(uint param_1)

{
  int iVar1;
  
  iVar1 = (int)SHORT_ARRAY_800c9910[param_1 & 0x7ff];
  if ((param_1 & 0x800) != 0) {
    iVar1 = -iVar1;
  }
  return iVar1;
}



// autogenerated function stub: 
// void rcos_exit() /* rcos_exit method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void rcos_exit() 
{ // line 1412, offset 0x800790f0
	/* begin block 1 */
		// Start line: 2825
	/* end block 1 */
	// End Line: 2826

	return null;
}


// decompiled code
// original method signature: 
// void MATH3D_racos_S() /* MATH3D_racos_S method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 1415, offset 0x800790f8
	/* begin block 1 */
		// Start line: 2831
	/* end block 1 */
	// End Line: 2832

	/* begin block 2 */
		// Start line: 2852
	/* end block 2 */
	// End Line: 2853

	/* begin block 3 */
		// Start line: 2853
	/* end block 3 */
	// End Line: 2854

	/* begin block 4 */
		// Start line: 2854
	/* end block 4 */
	// End Line: 2855

	/* begin block 5 */
		// Start line: 2855
	/* end block 5 */
	// End Line: 2856

	/* begin block 6 */
		// Start line: 2856
	/* end block 6 */
	// End Line: 2857

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
    iVar2 = 0x100;
  }
  do {
    if ((int)SHORT_ARRAY_800c9910[iVar1] == iVar4) break;
    iVar3 = iVar2 >> 1;
    if ((int)SHORT_ARRAY_800c9910[iVar1] - iVar4 < 0) {
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
 // line 1482, offset 0x80079158
	/* begin block 1 */
		// Start line: 2965
	/* end block 1 */
	// End Line: 2966

	/* begin block 2 */
		// Start line: 2966
	/* end block 2 */
	// End Line: 2967

	/* begin block 3 */
		// Start line: 2967
	/* end block 3 */
	// End Line: 2968

	/* begin block 4 */
		// Start line: 2968
	/* end block 4 */
	// End Line: 2969

	/* begin block 5 */
		// Start line: 2969
	/* end block 5 */
	// End Line: 2970

	/* begin block 6 */
		// Start line: 2970
	/* end block 6 */
	// End Line: 2971

	/* begin block 7 */
		// Start line: 2971
	/* end block 7 */
	// End Line: 2972

	/* begin block 8 */
		// Start line: 2972
	/* end block 8 */
	// End Line: 2973

void SetGp(void)

{
  return;
}



// decompiled code
// original method signature: 
// void memcpy() /* memcpy method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 1492, offset 0x80079160
	/* begin block 1 */
		// Start line: 2985
	/* end block 1 */
	// End Line: 2986

	/* begin block 2 */
		// Start line: 2986
	/* end block 2 */
	// End Line: 2987

	/* begin block 3 */
		// Start line: 2987
	/* end block 3 */
	// End Line: 2988

	/* begin block 4 */
		// Start line: 2988
	/* end block 4 */
	// End Line: 2989

	/* begin block 5 */
		// Start line: 2989
	/* end block 5 */
	// End Line: 2990

	/* begin block 6 */
		// Start line: 2990
	/* end block 6 */
	// End Line: 2991

	/* begin block 7 */
		// Start line: 2991
	/* end block 7 */
	// End Line: 2992

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
 // line 1555, offset 0x80079218
	/* begin block 1 */
		// Start line: 3111
	/* end block 1 */
	// End Line: 3112

	/* begin block 2 */
		// Start line: 3112
	/* end block 2 */
	// End Line: 3113

	/* begin block 3 */
		// Start line: 3113
	/* end block 3 */
	// End Line: 3114

	/* begin block 4 */
		// Start line: 3114
	/* end block 4 */
	// End Line: 3115

	/* begin block 5 */
		// Start line: 3115
	/* end block 5 */
	// End Line: 3116

	/* begin block 6 */
		// Start line: 3116
	/* end block 6 */
	// End Line: 3117

	/* begin block 7 */
		// Start line: 3117
	/* end block 7 */
	// End Line: 3118

	/* begin block 8 */
		// Start line: 3118
	/* end block 8 */
	// End Line: 3119

	/* begin block 9 */
		// Start line: 3119
	/* end block 9 */
	// End Line: 3120

	/* begin block 10 */
		// Start line: 3120
	/* end block 10 */
	// End Line: 3121

	/* begin block 11 */
		// Start line: 3121
	/* end block 11 */
	// End Line: 3122

	/* begin block 12 */
		// Start line: 3122
	/* end block 12 */
	// End Line: 3123

	/* begin block 13 */
		// Start line: 3123
	/* end block 13 */
	// End Line: 3124

	/* begin block 14 */
		// Start line: 3124
	/* end block 14 */
	// End Line: 3125

	/* begin block 15 */
		// Start line: 3125
	/* end block 15 */
	// End Line: 3126

	/* begin block 16 */
		// Start line: 3126
	/* end block 16 */
	// End Line: 3127

	/* begin block 17 */
		// Start line: 3127
	/* end block 17 */
	// End Line: 3128

	/* begin block 18 */
		// Start line: 3128
	/* end block 18 */
	// End Line: 3129

	/* begin block 19 */
		// Start line: 3129
	/* end block 19 */
	// End Line: 3130

	/* begin block 20 */
		// Start line: 3130
	/* end block 20 */
	// End Line: 3131

	/* begin block 21 */
		// Start line: 3131
	/* end block 21 */
	// End Line: 3132

	/* begin block 22 */
		// Start line: 3132
	/* end block 22 */
	// End Line: 3133

	/* begin block 23 */
		// Start line: 3133
	/* end block 23 */
	// End Line: 3134

	/* begin block 24 */
		// Start line: 3134
	/* end block 24 */
	// End Line: 3135

	/* begin block 25 */
		// Start line: 3135
	/* end block 25 */
	// End Line: 3136

	/* begin block 26 */
		// Start line: 3136
	/* end block 26 */
	// End Line: 3137

	/* begin block 27 */
		// Start line: 3137
	/* end block 27 */
	// End Line: 3138

	/* begin block 28 */
		// Start line: 3138
	/* end block 28 */
	// End Line: 3139

	/* begin block 29 */
		// Start line: 3139
	/* end block 29 */
	// End Line: 3140

	/* begin block 30 */
		// Start line: 3140
	/* end block 30 */
	// End Line: 3141

	/* begin block 31 */
		// Start line: 3141
	/* end block 31 */
	// End Line: 3142

	/* begin block 32 */
		// Start line: 3142
	/* end block 32 */
	// End Line: 3143

	/* begin block 33 */
		// Start line: 3143
	/* end block 33 */
	// End Line: 3144

	/* begin block 34 */
		// Start line: 3144
	/* end block 34 */
	// End Line: 3145

	/* begin block 35 */
		// Start line: 3145
	/* end block 35 */
	// End Line: 3146

	/* begin block 36 */
		// Start line: 3146
	/* end block 36 */
	// End Line: 3147

	/* begin block 37 */
		// Start line: 3147
	/* end block 37 */
	// End Line: 3148

	/* begin block 38 */
		// Start line: 3148
	/* end block 38 */
	// End Line: 3149

	/* begin block 39 */
		// Start line: 3149
	/* end block 39 */
	// End Line: 3150

	/* begin block 40 */
		// Start line: 3150
	/* end block 40 */
	// End Line: 3151

	/* begin block 41 */
		// Start line: 3151
	/* end block 41 */
	// End Line: 3152

	/* begin block 42 */
		// Start line: 3152
	/* end block 42 */
	// End Line: 3153

	/* begin block 43 */
		// Start line: 3153
	/* end block 43 */
	// End Line: 3154

	/* begin block 44 */
		// Start line: 3154
	/* end block 44 */
	// End Line: 3155

	/* begin block 45 */
		// Start line: 3155
	/* end block 45 */
	// End Line: 3156

	/* begin block 46 */
		// Start line: 3156
	/* end block 46 */
	// End Line: 3157

	/* begin block 47 */
		// Start line: 3157
	/* end block 47 */
	// End Line: 3158

	/* begin block 48 */
		// Start line: 3158
	/* end block 48 */
	// End Line: 3159

	/* begin block 49 */
		// Start line: 3159
	/* end block 49 */
	// End Line: 3160

	/* begin block 50 */
		// Start line: 3160
	/* end block 50 */
	// End Line: 3161

	/* begin block 51 */
		// Start line: 3161
	/* end block 51 */
	// End Line: 3162

	/* begin block 52 */
		// Start line: 3162
	/* end block 52 */
	// End Line: 3163

	/* begin block 53 */
		// Start line: 3163
	/* end block 53 */
	// End Line: 3164

	/* begin block 54 */
		// Start line: 3164
	/* end block 54 */
	// End Line: 3165

	/* begin block 55 */
		// Start line: 3165
	/* end block 55 */
	// End Line: 3166

	/* begin block 56 */
		// Start line: 3166
	/* end block 56 */
	// End Line: 3167

	/* begin block 57 */
		// Start line: 3167
	/* end block 57 */
	// End Line: 3168

	/* begin block 58 */
		// Start line: 3168
	/* end block 58 */
	// End Line: 3169

	/* begin block 59 */
		// Start line: 3169
	/* end block 59 */
	// End Line: 3170

	/* begin block 60 */
		// Start line: 3170
	/* end block 60 */
	// End Line: 3171

	/* begin block 61 */
		// Start line: 3171
	/* end block 61 */
	// End Line: 3172

	/* begin block 62 */
		// Start line: 3172
	/* end block 62 */
	// End Line: 3173

	/* begin block 63 */
		// Start line: 3173
	/* end block 63 */
	// End Line: 3174

	/* begin block 64 */
		// Start line: 3174
	/* end block 64 */
	// End Line: 3175

	/* begin block 65 */
		// Start line: 3175
	/* end block 65 */
	// End Line: 3176

	/* begin block 66 */
		// Start line: 3176
	/* end block 66 */
	// End Line: 3177

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
  DAT_1f800040 = *param_2;
  setCopControlWord(2,0,_DAT_1f800000);
  setCopControlWord(2,0x800,_DAT_1f800004);
  setCopControlWord(2,0x1000,_DAT_1f800008);
  setCopControlWord(2,0x1800,_DAT_1f80000c);
  setCopControlWord(2,0x2000,(uint)DAT_1f800010);
  setCopReg(2,0,DAT_1f800040);
  setCopReg(2,0x800,(int)*(short *)(param_2 + 1));
  copFunction(2,0x486012);
  DAT_1f800060 = getCopReg(2,0x19);
  _DAT_1f800064 = getCopReg(2,0x1a);
  _DAT_1f800068 = getCopReg(2,0x1b);
  setCopControlWord(2,0,DAT_1f800020);
  setCopControlWord(2,0x800,DAT_1f800024);
  setCopControlWord(2,0x1000,DAT_1f800028);
  copFunction(2,0x486012);
  puVar2 = (undefined4 *)param_2[0x1d];
  DAT_1f80006c = getCopReg(2,0x19);
  DAT_1f800070 = getCopReg(2,0x1a);
  iVar4 = (iVar15 << 0xf) / (int)param_2[0x1a];
  setCopReg(2,0x800,iVar15);
  setCopControlWord(2,0,*puVar2);
  setCopControlWord(2,0x800,puVar2[1]);
  setCopControlWord(2,0x1000,puVar2[2]);
  setCopControlWord(2,0x1800,puVar2[3]);
  setCopControlWord(2,0x2000,(uint)*(ushort *)(puVar2 + 4));
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
  DAT_1f800050._0_2_ = (ushort)uVar16;
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
  _DAT_1f800078 = uVar8 & 0xffff | iVar15 << 0x10;
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
    if (((iVar4 < iVar7 - DAT_1f800060) && (iVar4 < iVar9 - _DAT_1f800064)) &&
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
          setCopControlWord(2,0,DAT_1f800040);
          setCopControlWord(2,0x800,_DAT_1f800044);
          setCopControlWord(2,0x1000,_DAT_1f800048);
          setCopControlWord(2,0x1800,_DAT_1f80004c);
          setCopControlWord(2,0x2000,(uint)(ushort)DAT_1f800050);
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
                setCopControlWord(2,0x800,_DAT_1f800078);
                setCopControlWord(2,0x1000,_DAT_1f80007c);
                copFunction(2,0x486012);
                iVar7 = getCopReg(2,0xc800);
                iVar9 = getCopReg(2,0xd000);
                if ((iVar7 + iVar4 < iVar14) && (iVar9 + iVar4 < iVar14)) goto LAB_80079750;
              }
              *ppiVar17 = piVar3;
              ppiVar18 = ppiVar17;
            }
LAB_80079750:
            if (piVar22 != (int *)0x0) {
              ppiVar18[1] = piVar22;
              ppiVar18 = ppiVar18 + 1;
            }
          }
          else {
            if (piVar22 != (int *)0x0) {
              if (((iVar11 < iVar4) && (iVar11 < iVar7 + iVar4)) && (iVar11 < iVar9 + iVar4)) {
                setCopControlWord(2,0,DAT_1f800074);
                setCopControlWord(2,0x800,_DAT_1f800078);
                setCopControlWord(2,0x1000,_DAT_1f80007c);
                copFunction(2,0x486012);
                iVar7 = getCopReg(2,0xc800);
                iVar9 = getCopReg(2,0xd000);
                if ((iVar11 < iVar7 + iVar4) && (iVar11 < iVar9 + iVar4)) goto LAB_800796c0;
              }
              *ppiVar17 = piVar22;
              ppiVar18 = ppiVar17;
            }
LAB_800796c0:
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
 // line 2180, offset 0x800797e8
	/* begin block 1 */
		// Start line: 4361
	/* end block 1 */
	// End Line: 4362

	/* begin block 2 */
		// Start line: 4362
	/* end block 2 */
	// End Line: 4363

	/* begin block 3 */
		// Start line: 4363
	/* end block 3 */
	// End Line: 4364

	/* begin block 4 */
		// Start line: 4364
	/* end block 4 */
	// End Line: 4365

	/* begin block 5 */
		// Start line: 4365
	/* end block 5 */
	// End Line: 4366

	/* begin block 6 */
		// Start line: 4366
	/* end block 6 */
	// End Line: 4367

	/* begin block 7 */
		// Start line: 4367
	/* end block 7 */
	// End Line: 4368

	/* begin block 8 */
		// Start line: 4368
	/* end block 8 */
	// End Line: 4369

	/* begin block 9 */
		// Start line: 4369
	/* end block 9 */
	// End Line: 4370

	/* begin block 10 */
		// Start line: 4370
	/* end block 10 */
	// End Line: 4371

	/* begin block 11 */
		// Start line: 4371
	/* end block 11 */
	// End Line: 4372

	/* begin block 12 */
		// Start line: 4372
	/* end block 12 */
	// End Line: 4373

	/* begin block 13 */
		// Start line: 4373
	/* end block 13 */
	// End Line: 4374

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
 // line 2358, offset 0x800799f4
	/* begin block 1 */
		// Start line: 4717
	/* end block 1 */
	// End Line: 4718

	/* begin block 2 */
		// Start line: 4718
	/* end block 2 */
	// End Line: 4719

	/* begin block 3 */
		// Start line: 4719
	/* end block 3 */
	// End Line: 4720

	/* begin block 4 */
		// Start line: 4720
	/* end block 4 */
	// End Line: 4721

	/* begin block 5 */
		// Start line: 4721
	/* end block 5 */
	// End Line: 4722

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
 // line 2439, offset 0x80079ae4
	/* begin block 1 */
		// Start line: 4879
	/* end block 1 */
	// End Line: 4880

	/* begin block 2 */
		// Start line: 4880
	/* end block 2 */
	// End Line: 4881

	/* begin block 3 */
		// Start line: 4881
	/* end block 3 */
	// End Line: 4882

	/* begin block 4 */
		// Start line: 4882
	/* end block 4 */
	// End Line: 4883

	/* begin block 5 */
		// Start line: 4883
	/* end block 5 */
	// End Line: 4884

	/* begin block 6 */
		// Start line: 4884
	/* end block 6 */
	// End Line: 4885

	/* begin block 7 */
		// Start line: 4885
	/* end block 7 */
	// End Line: 4886

	/* begin block 8 */
		// Start line: 4886
	/* end block 8 */
	// End Line: 4887

	/* begin block 9 */
		// Start line: 4887
	/* end block 9 */
	// End Line: 4888

void G2Quat_FromEuler_S(int param_1,short *param_2)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined2 uVar14;
  int iVar15;
  undefined2 uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  
  iVar10 = (int)param_2[1];
  uVar1 = SEXT24(param_2[3]);
  iVar11 = (int)*param_2;
  iVar18 = (int)param_2[2];
  if ((uVar1 & 1) != 0) {
    iVar11 = (int)param_2[2];
    iVar18 = (int)*param_2;
  }
  if ((uVar1 & 4) != 0) {
    iVar10 = -iVar10;
  }
  uVar7 = iVar11 >> 1 & 0x7ff;
  iVar4 = (int)ecostable[uVar7];
  iVar8 = (int)SHORT_ARRAY_800c9910[uVar7];
  if ((iVar11 >> 1 & 0x800U) != 0) {
    iVar4 = -iVar4;
    iVar8 = -iVar8;
  }
  uVar7 = iVar10 >> 1 & 0x7ff;
  iVar11 = (int)ecostable[uVar7];
  iVar12 = (int)SHORT_ARRAY_800c9910[uVar7];
  if ((iVar10 >> 1 & 0x800U) != 0) {
    iVar11 = -iVar11;
    iVar12 = -iVar12;
  }
  uVar7 = iVar18 >> 1 & 0x7ff;
  iVar10 = (int)ecostable[uVar7];
  iVar17 = (int)SHORT_ARRAY_800c9910[uVar7];
  if ((iVar18 >> 1 & 0x800U) != 0) {
    iVar10 = -iVar10;
    iVar17 = -iVar17;
  }
  setCopReg(2,0x4000,iVar8);
  setCopReg(2,0x4800,iVar17);
  setCopReg(2,0x5000,iVar10);
  copFunction(2,0x198003d);
  iVar18 = getCopReg(2,0x4800);
  iVar8 = getCopReg(2,0x5000);
  setCopReg(2,0x4000,iVar4);
  setCopReg(2,0x4800,iVar17);
  setCopReg(2,0x5000,iVar10);
  copFunction(2,0x198003d);
  iVar10 = (int)(uVar1 & 0x18) >> 2;
  iVar4 = getCopReg(2,0x4800);
  iVar17 = getCopReg(2,0x5000);
  if ((uVar1 & 2) == 0) {
    setCopReg(2,0x4000,iVar12);
    setCopReg(2,0x4800,iVar4);
    setCopReg(2,0x5000,iVar17);
    setCopReg(2,0x5800,iVar8);
    copFunction(2,0x190003d);
    iVar2 = (int)(uVar1 & 4) >> 1;
    iVar5 = getCopReg(2,0xc800);
    iVar9 = getCopReg(2,0xd000);
    iVar15 = getCopReg(2,0xd800);
    setCopReg(2,0x4000,iVar11);
    setCopReg(2,0x4800,iVar8);
    setCopReg(2,0x5000,iVar18);
    setCopReg(2,0x5800,iVar4);
    copFunction(2,0x190003d);
    uVar1 = iVar10 + iVar2 + 2;
    if (4 < uVar1) {
      uVar1 = (iVar10 + iVar2) - 4;
    }
    iVar4 = (iVar10 - iVar2) + 4;
    iVar8 = getCopReg(2,0xc800);
    if (4 < iVar4) {
      iVar4 = (iVar10 - iVar2) + -2;
    }
    iVar13 = getCopReg(2,0xd000);
    iVar19 = getCopReg(2,0xd800);
    uVar3 = (undefined2)(iVar5 - iVar8 >> 0xc);
    sVar6 = (short)(iVar9 + iVar13 >> 0xc);
    uVar14 = (undefined2)(iVar15 - iVar19 >> 0xc);
    uVar16 = (undefined2)(iVar12 * iVar18 + iVar11 * iVar17 >> 0xc);
  }
  else {
    setCopReg(2,0x4000,iVar12);
    setCopReg(2,0x4800,iVar8 + iVar4);
    setCopReg(2,0x5000,iVar18 - iVar17);
    copFunction(2,0x198003d);
    iVar2 = (int)(uVar1 & 4) >> 1;
    _uVar3 = getCopReg(2,0x4800);
    uVar3 = (undefined2)_uVar3;
    _uVar3 = getCopReg(2,0x5000);
    uVar16 = (undefined2)_uVar3;
    setCopReg(2,0x4000,iVar11);
    setCopReg(2,0x4800,iVar18 + iVar17);
    setCopReg(2,0x5000,iVar8 - iVar4);
    copFunction(2,0x198003d);
    uVar1 = iVar10 + iVar2 + 2;
    if (4 < uVar1) {
      uVar1 = (iVar10 + iVar2) - 4;
    }
    iVar4 = (iVar10 - iVar2) + 4;
    _uVar3 = getCopReg(2,0x4800);
    sVar6 = (short)_uVar3;
    if (4 < iVar4) {
      iVar4 = (iVar10 - iVar2) + -2;
    }
    _uVar3 = getCopReg(2,0x5000);
    uVar14 = (undefined2)_uVar3;
  }
  if (iVar2 != 0) {
    sVar6 = -sVar6;
  }
  *(undefined2 *)(iVar10 + param_1) = uVar3;
  *(short *)(uVar1 + param_1) = sVar6;
  *(undefined2 *)(iVar4 + param_1) = uVar14;
  *(undefined2 *)(param_1 + 6) = uVar16;
  return;
}



// autogenerated function stub: 
// void eul_1() /* eul_1 method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void eul_1() 
{ // line 2491, offset 0x80079b50
	/* begin block 1 */
		// Start line: 4983
	/* end block 1 */
	// End Line: 4984

	/* begin block 2 */
		// Start line: 4984
	/* end block 2 */
	// End Line: 4985

	return null;
}


// autogenerated function stub: 
// void eul_2() /* eul_2 method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void eul_2() 
{ // line 2503, offset 0x80079b78
	/* begin block 1 */
		// Start line: 5007
	/* end block 1 */
	// End Line: 5008

	/* begin block 2 */
		// Start line: 5008
	/* end block 2 */
	// End Line: 5009

	return null;
}


// autogenerated function stub: 
// void eul_3() /* eul_3 method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void eul_3() 
{ // line 2515, offset 0x80079ba0
	/* begin block 1 */
		// Start line: 5031
	/* end block 1 */
	// End Line: 5032

	/* begin block 2 */
		// Start line: 5032
	/* end block 2 */
	// End Line: 5033

	/* begin block 3 */
		// Start line: 5033
	/* end block 3 */
	// End Line: 5034

	/* begin block 4 */
		// Start line: 5034
	/* end block 4 */
	// End Line: 5035

	/* begin block 5 */
		// Start line: 5035
	/* end block 5 */
	// End Line: 5036

	/* begin block 6 */
		// Start line: 5036
	/* end block 6 */
	// End Line: 5037

	return null;
}




