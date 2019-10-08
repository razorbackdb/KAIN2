#include "THISDUST.H"
#include "QUATVM.H"

_int)(u_short)quatA->z);
setCopControlWord(2, 0, (u_int)(u_short)(quatB->x | quatB->y));
setCopControlWord(2, 0x800, (u_int)(u_short)quatB->z);
copFunction(2, 0x49e012);
(2, 0x19);
iVar5 = (uVar11 & 0xffff) + ((int)quatA->w * (int)quatB->w >> 0xc);
bVar1 = iVar5 * 0x10000 < 0;
sVar7 = (short)iVar5;
if (bVar1)
{
  sVar7 = -sVar7;
}
iVar5 = 0x1000 - ratio;
if (0 < 0x1000 - (int)sVar7)
{
  iVar5 = MATH3D_racos_S((int)sVar7);
  iVar2 = rsin((int)(short)iVar5);
  *((iVar5 + spin * 0x1000) * 0x10000 >> 0x10) >> 0xc;
  iVar5 = rsin((int)(short)iVar5 - uVar11);
  iVar5 = (iVar5 << 0xc) / (int)(short)iVar2;
  iVar3 = rsin(uVar11);
< 0xc) / (int)(short)iVar2;
}
ratio = -ratio;
}
,(u_int)(u_short)quatA->x);
setCopReg(2, 0x5000, (u_int)(u_short)quatA->y);
00,(u_int)(u_short)quatA->z);
setCopReg(2, 0x4000, iVar5);
copFunction(2, 0x198003d);
setCopReg(2, 0x4800, (u_int)(u_short)quatB->x);
setCopReg(2, 0x5000, (u_int)(u_short)quatB->y);
setCopReg(2, 0x5800, (u_int)(u_short)quatB->z);
setCopReg(2, 0x4000, ratio);
copFunction(2, 0x1a8003e);
iVar6 = (iVar5 * quatA->w >> 0xc) + (ratio * quatB->w >> 0xc);
iVar5 = getCopReg(2, 9);
iVar2 = getCopReg(2, 10);
iVar3 = getCopReg(2, 0xb);
lVar4 = MATH3D_FastSqrt(iVar6 * iVar6 + iVar5 * iVar5 + iVar2 * iVar2 + iVar3 * iVar3 + 0x800 >>
                        0xc);
setCopReg(2, 0x4000, 0x1000000 / lVar4);
copFunction(2, 0x198003d);
quatOut->w = (short)(iVar6 * (0x1000000 / lVar4) >> 0xc);
uVar8 = getCopReg(2, 0x4800);
uVar9 = getCopReg(2, 0x5000);
uVar10 = getCopReg(2, 0x5800);
quatOut->x = (short)uVar8;
quatOut->y = (short)uVar9;
quatOut->z = (short)uVar10;
return;
}  sVar7 = (short)iVar5;
  if (bVar1) {
    sVar7 = -sVar7;
  }
  iVar5 = 0x1000 - ratio;
  if (0 < 0x1000 - (int)sVar7) {
    iVar5 = MATH3D_racos_S((int)sVar7);
    iVar2 = rsin((int)(short)iVar5);
    uVar11 = ratio * ((iVar5 + spin * 0x1000) * 0x10000 >> 0x10) >> 0xc;
    iVar5 = rsin((int)(short)iVar5 - uVar11);
 (int)(short)iVar2;
    iVar3 = rsin(uVar11);
 (int)(short)iVar2;
  }
  if (bVar1) {
    ratio = -ratio;
  }
  setCopReg(2,0x4800,(u_int)(u_short)quatA->x);
  setCopReg(2,0x5000,(u_int)(u_short)quatA->y);
  setCopReg(2,0x5800,(u_int)(u_short)quatA->z);
  setCopReg(2,0x4000,iVar5);
  copFunction(2,0x198003d);
  setCopReg(2,0x4800,(u_int)(u_short)quatB->x);
  setCopReg(2,0x5000,(u_int)(u_short)quatB->y);
  setCopReg(2,0x5800,(u_int)(u_short)quatB->z);
  setCopReg(2,0x4000,ratio);
  copFunction(2,0x1a8003e);
  iVar6 = (iVar5 * quatA->w >> 0xc) + (ratio * quatB->w >> 0xc);
  iVar5 = getCopReg(2,9);
  iVar2 = getCopReg(2,10);
  iVar3 = getCopReg(2,0xb);
  lVar4 = MATH3D_FastSqrt(iVar6 * iVar6 + iVar5 * iVar5 + iVar2 * iVar2 + iVar3 * iVar3 + 0x800 >>
                          0xc);
 lVar4);
  copFunction(2,0x198003d);
 lVar4) >> 0xc);
  uVar8 = getCopReg(2,0x4800);
  uVar9 = getCopReg(2,0x5000);
  uVar10 = getCopReg(2,0x5800);
  quatOut->x = (short)uVar8;
  quatOut->y = (short)uVar9;
  quatOut->z = (short)uVar10;
  return;
}





