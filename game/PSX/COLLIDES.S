






#include "THISDUST.H"
#include "COLLIDES.H"





 

		

	


		

	


		

	


		

	


		

	

void COLLIDE_NearestPointOnLine_S(u_int *param_1,u_int *param_2,u_int *param_3,u_int *param_4)

{
  u_short uVar1;
  u_short uVar2;
  u_int uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  u_int uVar7;
  u_int uVar8;
  u_int uVar9;
  u_char uVar10;
  int iVar11;
  u_char uVar12;
  int iVar13;
  u_char uVar14;
  
  uVar7 = *param_2;
  uVar1 = *(u_short *)(param_2 + 1);
  uVar8 = *param_3;
  uVar2 = *(u_short *)(param_3 + 1);
  setCopControlWord(2,0,uVar7);
  setCopControlWord(2,0x800,*param_4 << 0x10 | (u_int)uVar1);
  setCopControlWord(2,0x1000,(u_int)*(u_short *)(param_4 + 1) << 0x10 | *param_4 >> 0x10);
  uVar9 = (uVar8 & 0xffff) - (uVar7 & 0xffff);
  iVar11 = (uVar8 >> 0x10) - (uVar7 >> 0x10);
  iVar13 = (u_int)uVar2 - (u_int)uVar1;
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
 iVar6;
    setCopReg(2,0x4800,uVar9);
    setCopReg(2,0x5000,iVar11);
    setCopReg(2,0x5800,iVar13);
  }
  if (0x1000 < uVar3) {
    if ((int)uVar3 < 1) {
      *param_1 = uVar7;
      *(u_short *)(param_1 + 1) = uVar1;
      return;
    }
    *param_1 = uVar8;
    *(u_short *)(param_1 + 1) = uVar2;
    return;
  }
  setCopReg(2,0x4000,uVar3);
  copFunction(2,0x198003d);
  uVar10 = getCopReg(2,0x4800);
  uVar12 = getCopReg(2,0x5000);
  uVar14 = getCopReg(2,0x5800);
  *(short *)param_1 = (short)(uVar7 & 0xffff) + (short)uVar10;
  *(short *)((int)param_1 + 2) = (short)(uVar7 >> 0x10) + (short)uVar12;
  *(u_short *)(param_1 + 1) = uVar1 + (short)uVar14;
  return;
}






 

		

	


		

	


		

	


		

	

u_char
COLLIDE_IntersectLineAndBox
          (short *param_1,u_int *param_2,u_int *param_3,u_char *param_4,int param_5)

{
  u_short uVar1;
  u_char in_zero;
  u_char in_at;
  u_int uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  u_char uVar6;
  u_int uVar7;
  u_char uVar8;
  int iVar9;
  u_char uVar10;
  undefined *puVar11;
  
  uVar2 = *param_2;
  uVar1 = *(u_short *)(param_2 + 1);
  iVar5 = (*param_3 & 0xffff) - (uVar2 & 0xffff);
  uVar7 = (*param_3 >> 0x10) - (uVar2 >> 0x10);
  iVar9 = (u_int)*(u_short *)(param_3 + 1) - (u_int)uVar1;
  setCopReg(2,in_zero,*param_4);
  setCopReg(2,in_at,param_4[1]);
  setCopControlWord(2,0,uVar2);
  setCopControlWord(2,0x800,(u_int)uVar1 | iVar5 * 0x10000);
  setCopControlWord(2,0x1000,iVar9 * 0x10000 | uVar7 & 0xffff);
  copFunction(2,0x486012);
  iVar3 = getCopReg(2,0xc800);
  iVar4 = getCopReg(2,0xd000);
  if (iVar4 != 0) {
 iVar4);
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






 

		

	


		

	


		

	


		

	


		

	


		

	


		

	

void COLLIDE_NearestPointOnPlane_S(short *param_1,int *param_2,int param_3,u_char *param_4)

{
  short sVar1;
  int iVar2;
  u_char uVar3;
  u_char uVar4;
  u_char uVar5;
  u_char uVar6;
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
  param_1[1] = (short)uVar4 + (short)((u_int)uVar6 >> 0x10);
  param_1[2] = (short)uVar5 + sVar1;
  return;
}






 

		

	


		

	


		

	


		

	



void VM_ProcessVMObjectSetColor_S(void)

{
  u_char unaff_s0;
  u_char unaff_s1;
  u_char unaff_s2;
  u_char unaff_s3;
  u_char unaff_s4;
  u_char unaff_s5;
  u_char unaff_s6;
  u_char unaff_s7;
  u_char unaff_s8;
  u_char unaff_retaddr;
  
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
  FUN_80077b98();
  return;
}






 

		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	



void VM_ProcessVMObjectList_S(int param_1)

{
  int iVar1;
  u_char unaff_s0;
  u_int *puVar2;
  u_char unaff_s1;
  int iVar3;
  u_char unaff_s2;
  u_char unaff_s3;
  u_int uVar4;
  u_char unaff_s4;
  u_char unaff_s5;
  u_char unaff_s6;
  u_char unaff_s7;
  u_char unaff_s8;
  u_char unaff_retaddr;
  
  iVar3 = *(int *)(param_1 + 8);
  puVar2 = *(u_int **)(param_1 + 0xc);
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
        FUN_80077b98();
      }
    }
    iVar3 = iVar3 + -1;
    puVar2 = puVar2 + 0xf;
  }
  return;
}






 

		

	


		

	


		

	


		

	


		

	


		

	

u_int BSP_SphereIntersectsViewVolume_S(u_char *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  u_char in_zero;
  u_char in_at;
  u_int uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  setCopControlWord(2,0,*(u_char *)(param_2 + 8));
  setCopControlWord(2,0x800,*(u_char *)(param_2 + 0xc));
  setCopControlWord(2,0x1000,*(u_char *)(param_2 + 0x10));
  setCopControlWord(2,0x1800,*(u_char *)(param_2 + 0x14));
  setCopControlWord(2,0x2000,*(u_char *)(param_2 + 0x18));
  setCopReg(2,in_zero,*param_1);
  setCopReg(2,in_at,param_1[1]);
  copFunction(2,0x486012);
  iVar2 = -(u_int)*(u_short *)((int)param_1 + 6);
  iVar4 = getCopReg(2,0xc800);
  iVar5 = getCopReg(2,0xd000);
  iVar6 = getCopReg(2,0xd800);
  iVar4 = iVar4 - *(int *)(param_2 + 0x48);
  uVar3 = (u_int)(iVar2 < iVar4);
  if (iVar2 < iVar4) {
    bVar1 = iVar4 < (int)(*(int *)(param_2 + 100) + (u_int)*(u_short *)((int)param_1 + 6));
    uVar3 = (u_int)bVar1;
    if (bVar1) {
      bVar1 = iVar2 < iVar5 - *(int *)(param_2 + 0x4c);
      uVar3 = (u_int)bVar1;
      if ((bVar1) && (bVar1 = iVar2 < iVar6 - *(int *)(param_2 + 0x50), uVar3 = (u_int)bVar1, bVar1))
      {
        setCopControlWord(2,0,*(u_char *)(param_2 + 0x28));
        setCopControlWord(2,0x800,*(u_char *)(param_2 + 0x2c));
        setCopControlWord(2,0x1000,*(u_char *)(param_2 + 0x30));
        copFunction(2,0x486012);
        iVar4 = getCopReg(2,0xc800);
        iVar5 = getCopReg(2,0xd000);
        bVar1 = iVar2 < iVar4 - *(int *)(param_2 + 0x54);
        uVar3 = (u_int)bVar1;
        if (bVar1) {
          uVar3 = (u_int)(iVar2 < iVar5 - *(int *)(param_2 + 0x58));
        }
      }
    }
  }
  return uVar3;
}






 

		

	


		

	


		

	


		

	


		

	


		

	

void RotMatrixZYX(u_short *param_1,u_int *param_2)

{
  u_short uVar1;
  u_short uVar2;
  u_char uVar3;
  u_int uVar4;
  u_int uVar5;
  int iVar6;
  u_char uVar7;
  int iVar8;
  u_char uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  u_char uVar13;
  u_char uVar14;
  u_char uVar15;
  
  uVar1 = param_1[1];
  uVar2 = *param_1;
  uVar4 = (int)(short)param_1[2] & 0x7ff;
  iVar12 = (int)(&ecostable)[uVar4];
  uVar4 = SEXT24((&SHORT_800ca094)[uVar4]);
  if (((int)(short)param_1[2] & 0x800U) != 0) {
    iVar12 = -iVar12;
    uVar4 = -uVar4;
  }
  if ((uVar1 | uVar2) != 0) {
    uVar5 = (int)(short)uVar1 & 0x7ff;
    iVar11 = (int)(&ecostable)[uVar5];
    iVar8 = (int)(&SHORT_800ca094)[uVar5];
    if (((int)(short)uVar1 & 0x800U) != 0) {
      iVar8 = -iVar8;
      iVar11 = -iVar11;
    }
    uVar5 = (int)(short)uVar2 & 0x7ff;
    iVar10 = (int)(&ecostable)[uVar5];
    iVar6 = (int)(&SHORT_800ca094)[uVar5];
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





void rmzyx_1() 
{ 

		

	


		

	

	return null;
}




void rmzyx_2() 
{ 

		

	


		

	

	return null;
}




void rmzyx_3() 
{ 

		

	


		

	


		

	


		

	

	return null;
}




void rmzyx_onlyz() 
{ 

		

	


		

	


		

	

	return null;
}





 

		

	


		

	


		

	

u_longlong RotMatrixY(u_short *param_1,u_int *param_2)

{
  u_short uVar1;
  u_short uVar2;
  u_char in_v0;
  u_char uVar3;
  u_int uVar4;
  u_int uVar5;
  int iVar6;
  u_char uVar7;
  int iVar8;
  u_char uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  u_char uVar13;
  u_char uVar14;
  u_char uVar15;
  
  uVar1 = param_1[1];
  uVar2 = *param_1;
  uVar4 = (int)(short)param_1[2] & 0x7ff;
  iVar12 = (int)(&ecostable)[uVar4];
  uVar4 = SEXT24((&SHORT_800ca094)[uVar4]);
  if (((int)(short)param_1[2] & 0x800U) != 0) {
    iVar12 = -iVar12;
    uVar4 = -uVar4;
  }
  if ((uVar1 | uVar2) != 0) {
    uVar5 = (int)(short)uVar1 & 0x7ff;
    iVar11 = (int)(&ecostable)[uVar5];
    iVar8 = (int)(&SHORT_800ca094)[uVar5];
    if (((int)(short)uVar1 & 0x800U) != 0) {
      iVar8 = -iVar8;
      iVar11 = -iVar11;
    }
    uVar5 = (int)(short)uVar2 & 0x7ff;
    iVar10 = (int)(&ecostable)[uVar5];
    iVar6 = (int)(&SHORT_800ca094)[uVar5];
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
    iVar12 = iVar10 * iVar11 >> 0xc;
    *(short *)((int)param_2 + 6) = (short)uVar9 + (short)uVar14;
    *(short *)(param_2 + 3) = (short)iVar10 - (short)uVar3;
    *(short *)(param_2 + 2) = (short)uVar13 - (short)iVar12;
    *(short *)((int)param_2 + 0xe) = (short)uVar7 + (short)uVar15;
    return CONCAT44(iVar12,0x800c9894);
  }
  *param_2 = iVar12 * -0x10000 | uVar4 & 0xffff;
  param_2[1] = iVar12 * 0x10000;
  param_2[2] = uVar4 & 0xffff;
  param_2[3] = 0;
  *(undefined2 *)(param_2 + 4) = 0x1000;
  return CONCAT44(in_v0,0x800c0000) | 0x9894;
}





void rm_1() 
{ 

		

	


		

	

	return null;
}




void rm_2() 
{ 

		

	


		

	

	return null;
}




void rm_3() 
{ 

		

	


		

	


		

	


		

	

	return null;
}





 

		

	


		

	


		

	


		

	

undefined8 RotMatrixZ(u_int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  u_char uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  u_char uVar8;
  int iVar9;
  int iVar10;
  u_char uVar11;
  int iVar12;
  int iVar13;
  
  iVar2 = (int)(&SHORT_800ca094)[param_1 & 0x7ff];
  iVar3 = (int)(&ecostable)[param_1 & 0x7ff];
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
  *(u_int *)(param_2 + 8) = iVar12 - iVar1 & 0xffffU | (iVar13 - iVar5) * 0x10000;
  iVar1 = getCopReg(2,0x4800);
  iVar5 = getCopReg(2,0x5000);
  uVar4 = getCopReg(2,0x5800);
  *(u_int *)(param_2 + 0xc) = iVar6 + iVar1 & 0xffffU | (iVar7 + iVar5) * 0x10000;
  *(short *)(param_2 + 0x10) = (short)uVar8 + (short)uVar4;
  return CONCAT44(iVar2,iVar3);
}





void RMX_0() 
{ 

		

	


		

	

	return null;
}





 

		

	


		

	


		

	

undefined8 RotMatrix(u_int param_1,u_int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  u_char uVar5;
  int iVar6;
  int iVar7;
  u_char uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  u_char uVar13;
  
  iVar2 = (int)(&SHORT_800ca094)[param_1 & 0x7ff];
  iVar3 = (int)(&ecostable)[param_1 & 0x7ff];
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





void RMY_0() 
{ 

		

	


		

	

	return null;
}





 

		

	


		

	

undefined8 RotMatrixX(u_int param_1,u_int *param_2)

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
  
  iVar2 = (int)(&SHORT_800ca094)[param_1 & 0x7ff];
  iVar3 = (int)(&ecostable)[param_1 & 0x7ff];
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





void RMZ_0() 
{ 

		

	


		

	

	return null;
}




void ApplyMatrix_S() 
{ 

		

	


		

	


		

	


		

	

	return null;
}





 

		

	


		

	


		

	


		

	


		

	


		

	

int * ScaleMatrix(int *param_1,u_char *param_2)

{
  u_char uVar1;
  u_char uVar2;
  u_char uVar3;
  u_char uVar4;
  u_char uVar5;
  
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






 

		

	


		

	


		

	


		

	

int rsin(u_int param_1)

{
  int iVar1;
  
  iVar1 = (int)(&ecostable)[param_1 & 0x7ff];
  if ((param_1 & 0x800) != 0) {
    iVar1 = -iVar1;
  }
  return iVar1;
}





void rsin_exit() 
{ 

		

	

	return null;
}





 

		

	


		

	

int rcos(u_int param_1)

{
  int iVar1;
  
  iVar1 = (int)(&SHORT_800ca094)[param_1 & 0x7ff];
  if ((param_1 & 0x800) != 0) {
    iVar1 = -iVar1;
  }
  return iVar1;
}





void rcos_exit() 
{ 

		

	

	return null;
}





 

		

	


		

	


		

	


		

	


		

	


		

	

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
    if ((int)(&SHORT_800ca094)[iVar1] == iVar4) break;
    iVar3 = iVar2 >> 1;
    if ((int)(&SHORT_800ca094)[iVar1] - iVar4 < 0) {
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






 

		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	

void SetGp(void)

{
  return;
}






 

		

	


		

	


		

	


		

	


		

	


		

	


		

	

void * memcpy(void *__dest,void *__src,size_t __n)

{
  undefined uVar1;
  u_char *puVar2;
  u_char *puVar3;
  undefined *puVar4;
  u_char uVar5;
  u_char uVar6;
  u_char uVar7;
  u_char uVar8;
  u_char uVar9;
  u_char uVar10;
  u_char uVar11;
  u_char uVar12;
  
  if (__n != 0) {
    puVar4 = (undefined *)__dest;
    puVar2 = (u_char *)__dest;
    if ((((u_int)__dest | (u_int)__src | __n) & 3) == 0) {
      do {
        uVar5 = *(u_char *)__src;
        __src = (u_char *)__src + 1;
        puVar3 = puVar2 + 1;
        __n = __n - 4;
        *puVar2 = uVar5;
        puVar2 = puVar3;
      } while ((__n & 0x1f) != 0);
      if (__n != 0) {
        do {
          uVar5 = *(u_char *)__src;
          uVar6 = ((u_char *)__src)[1];
          uVar7 = ((u_char *)__src)[2];
          uVar8 = ((u_char *)__src)[3];
          uVar9 = ((u_char *)__src)[4];
          uVar10 = ((u_char *)__src)[5];
          uVar11 = ((u_char *)__src)[6];
          uVar12 = ((u_char *)__src)[7];
          __n = __n - 0x20;
          __src = (u_char *)__src + 8;
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






 

		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	



void BSP_MarkVisibleLeaves_S(int **param_1,u_char *param_2,int *param_3)

{
  u_char *puVar1;
  u_char *puVar2;
  int *piVar3;
  int iVar4;
  u_int uVar5;
  u_int uVar6;
  int iVar7;
  u_int uVar8;
  int iVar9;
  u_int uVar10;
  int iVar11;
  int **ppiVar12;
  u_int uVar13;
  int iVar14;
  int iVar15;
  u_char uVar16;
  u_char unaff_s0;
  int **ppiVar17;
  int **ppiVar18;
  u_char unaff_s1;
  u_char unaff_s2;
  u_char unaff_s3;
  u_char unaff_s4;
  u_char unaff_s5;
  u_char unaff_s6;
  u_char unaff_s7;
  int **ppiVar19;
  u_char uVar20;
  u_char uVar21;
  int *piVar22;
  u_char unaff_s8;
  u_char unaff_retaddr;
  
  DAT_1f8000c0 = &DAT_1f8000c0;
  ppiVar19 = (int **)(param_3 + 1);
  iVar15 = depthQFogFar;
  if ((int)param_2[0x19] <= depthQFogFar) {
    iVar15 = param_2[0x19];
  }
  puVar1 = param_2 + 2;
  puVar2 = (u_char *)&DAT_1f800000;
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
  setCopControlWord(2,0x2000,(u_int)DAT_1f800010);
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
  puVar1 = (u_char *)param_2[0x1d];
  DAT_1f80006c = getCopReg(2,0x19);
  DAT_1f800070 = getCopReg(2,0x1a);
 (int)param_2[0x1a];
  setCopReg(2,0x800,iVar15);
  setCopControlWord(2,0,*puVar1);
  setCopControlWord(2,0x800,puVar1[1]);
  setCopControlWord(2,0x1000,puVar1[2]);
  setCopControlWord(2,0x1800,puVar1[3]);
  setCopControlWord(2,0x2000,(u_int)*(u_short *)(puVar1 + 4));
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
  DAT_1f800050._0_2_ = (u_short)uVar16;
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
  setCopControlWord(2,0x2000,(u_int)DAT_1f800010);
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
        if ((*(u_short *)((int)param_1 + 0xe) & 1) == 0) {
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
          setCopControlWord(2,0x2000,(u_int)(u_short)DAT_1f800050);
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
                if ((iVar7 + iVar4 < iVar14) && (iVar9 + iVar4 < iVar14)) goto LAB_80079138;
              }
              *ppiVar17 = piVar3;
              ppiVar18 = ppiVar17;
            }
LAB_80079138:
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
                if ((iVar11 < iVar7 + iVar4) && (iVar11 < iVar9 + iVar4)) goto LAB_800790a8;
              }
              *ppiVar17 = piVar22;
              ppiVar18 = ppiVar17;
            }
LAB_800790a8:
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
      setCopControlWord(2,0x2000,(u_int)DAT_1f800010);
    }
    param_1 = (int **)*ppiVar18;
    ppiVar17 = ppiVar18;
    if (param_1 == ppiVar18) {
      *param_3 = (int)ppiVar19 + (-4 - (int)param_3) >> 2;
      return;
    }
  } while( true );
}






 

		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	

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
  u_char uVar10;
  short *psVar11;
  int iVar12;
  short *psVar13;
  int iVar14;
  u_char uVar15;
  u_char uVar16;
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
 lVar7);
    copFunction(2,0x198003d);
    uVar10 = getCopReg(2,0x4800);
    uVar15 = getCopReg(2,0x5000);
    uVar16 = getCopReg(2,0x5800);
    *param_1 = (short)uVar10;
    param_1[1] = (short)uVar15;
    param_1[2] = (short)uVar16;
 lVar7;
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
 lVar7);
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
 lVar7;
}






 

		

	


		

	


		

	


		

	


		

	

int G2Quat_ToMatrix_S(short *param_1,short *param_2)

{
  u_char uVar1;
  u_char uVar2;
  u_char uVar3;
  u_char uVar4;
  u_char uVar5;
  int iVar6;
  u_char uVar7;
  int iVar8;
  u_char uVar9;
  int iVar10;
  int iVar11;
  
  iVar6 = (int)*param_1;
  iVar11 = (int)param_1[3];
  iVar8 = (int)param_1[1];
  iVar10 = (int)param_1[2];
  setCopReg(2,0x4000,iVar6 << 1);
  setCopReg(2,0x4800,iVar6);
  setCopReg(2,0x5000,iVar11);
  setCopReg(2,0x5800,iVar8);
  copFunction(2,0x198003d);
  uVar1 = getCopReg(2,0xc800);
  uVar2 = getCopReg(2,0xd000);
  uVar3 = getCopReg(2,0xd800);
  setCopReg(2,0x4000,iVar8 << 1);
  setCopReg(2,0x4800,iVar8);
  setCopReg(2,0x5000,iVar11);
  setCopReg(2,0x5800,iVar10);
  copFunction(2,0x198003d);
  uVar4 = getCopReg(2,0xc800);
  iVar8 = getCopReg(2,0xd000);
  uVar5 = getCopReg(2,0xd800);
  setCopReg(2,0x4000,iVar10 << 1);
  setCopReg(2,0x4800,iVar10);
  setCopReg(2,0x5000,iVar11);
  setCopReg(2,0x5800,iVar6);
  copFunction(2,0x198003d);
  param_2[7] = (short)uVar5 + (short)uVar2;
  param_2[8] = 0x1000 - ((short)uVar1 + (short)uVar4);
  uVar7 = getCopReg(2,0xc800);
  uVar9 = getCopReg(2,0xd000);
  iVar6 = getCopReg(2,0xd800);
  *param_2 = 0x1000 - ((short)uVar4 + (short)uVar7);
  param_2[1] = (short)uVar3 - (short)uVar9;
  param_2[2] = (short)iVar6 + (short)iVar8;
  param_2[3] = (short)uVar3 + (short)uVar9;
  param_2[4] = 0x1000 - ((short)uVar1 + (short)uVar7);
  param_2[5] = (short)uVar5 - (short)uVar2;
  param_2[6] = (short)(iVar6 - iVar8);
  return iVar6 - iVar8;
}






 

		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	


		

	

void G2Quat_ToEuler(int param_1,short *param_2)

{
  u_int uVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  u_int uVar7;
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
  iVar4 = (int)(&ecostable)[uVar7];
  iVar8 = (int)(&SHORT_800ca094)[uVar7];
  if ((iVar11 >> 1 & 0x800U) != 0) {
    iVar4 = -iVar4;
    iVar8 = -iVar8;
  }
  uVar7 = iVar10 >> 1 & 0x7ff;
  iVar11 = (int)(&ecostable)[uVar7];
  iVar12 = (int)(&SHORT_800ca094)[uVar7];
  if ((iVar10 >> 1 & 0x800U) != 0) {
    iVar11 = -iVar11;
    iVar12 = -iVar12;
  }
  uVar7 = iVar18 >> 1 & 0x7ff;
  iVar10 = (int)(&ecostable)[uVar7];
  iVar17 = (int)(&SHORT_800ca094)[uVar7];
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





void eul_1() 
{ 

		

	


		

	

	return null;
}




void eul_2() 
{ 

		

	


		

	

	return null;
}




void eul_3() 
{ 

		

	


		

	


		

	


		

	


		

	


		

	

	return null;
}




