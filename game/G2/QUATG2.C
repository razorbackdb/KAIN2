#include "THISDUST.H"
#include "QUATG2.H"

void G2Quat_FromEuler_S(_G2Quat_Type *quat, _G2EulerAngles_Type *euler, int order)

{
  _G2Matrix_Type _Stack48;

  G2Quat_ToMatrix_S((short *)quat, (short *)&_Stack48);
  G2EulerAngles_FromMatrix(euler, &_Stack48, order);
  return;
}

void G2EulerAngles_FromMatrix(_G2EulerAngles_Type *euler, _G2Matrix_Type *matrix, long order)

{
  short sVar1;
  u_int uVar2;
  int iVar3;
  int iVar4;
  u_int uVar5;
  u_int uVar6;
  u_int uVar7;
  u_int uVar8;
  u_int uVar9;
  short local_res8;

  uVar6 = (u_int)order >> 2 & 1;
  uVar8 = (u_int) * (byte *)((int)&PTR_LAB_800d09cc + ((u_int)order >> 3 & 3));
  uVar9 = (u_int)(byte)(&DAT_800d09d4)[uVar8 + uVar6];
  uVar2 = (u_int)(byte)(&DAT_800d09d4)[uVar8 - (uVar6 - 1)];
  if (((u_int)order >> 1 & 1) == 1)
  {
    iVar3 = (int)matrix->rotScale[uVar8 * 3 + uVar9];
    iVar4 = (int)matrix->rotScale[uVar8 * 3 + uVar2];
    uVar5 = MATH3D_FastSqrt(iVar3 * iVar3 + iVar4 * iVar4 >> 0xc);
    if ((int)uVar5 < 0x11)
    {
      iVar3 = ratan2(-(int)matrix->rotScale[uVar9 * 3 + uVar2], (int)matrix->rotScale[uVar9 * 4]);
      euler->x = (short)iVar3;
      uVar7 = SEXT24(matrix->rotScale[uVar8 * 4]);
    LAB_80095c20:
      iVar3 = ratan2(uVar5, uVar7);
      euler->y = (short)iVar3;
      euler->z = 0;
      goto LAB_80095c30;
    }
    iVar3 = ratan2((int)matrix->rotScale[uVar8 * 3 + uVar9], (int)matrix->rotScale[uVar8 * 3 + uVar2]);
    euler->x = (short)iVar3;
    iVar3 = ratan2(uVar5, (int)matrix->rotScale[uVar8 * 4]);
    euler->y = (short)iVar3;
    sVar1 = matrix->rotScale[uVar9 * 3 + uVar8];
    uVar2 = -(int)matrix->rotScale[uVar2 * 3 + uVar8];
  }
  else
  {
    iVar3 = (int)matrix->rotScale[uVar8 * 4];
    iVar4 = (int)matrix->rotScale[uVar9 * 3 + uVar8];
    uVar7 = MATH3D_FastSqrt(iVar3 * iVar3 + iVar4 * iVar4 >> 0xc);
    if ((int)uVar7 < 0x11)
    {
      iVar3 = ratan2(-(int)matrix->rotScale[uVar9 * 3 + uVar2], (int)matrix->rotScale[uVar9 * 4]);
      euler->x = (short)iVar3;
      uVar5 = -(int)matrix->rotScale[uVar2 * 3 + uVar8];
      goto LAB_80095c20;
    }
    iVar3 = ratan2((int)matrix->rotScale[uVar2 * 3 + uVar9], (int)matrix->rotScale[uVar2 * 4]);
    euler->x = (short)iVar3;
    iVar3 = ratan2(-(int)matrix->rotScale[uVar2 * 3 + uVar8], uVar7);
    euler->y = (short)iVar3;
    sVar1 = matrix->rotScale[uVar9 * 3 + uVar8];
    uVar2 = SEXT24(matrix->rotScale[uVar8 * 4]);
  }
  iVar3 = ratan2((int)sVar1, uVar2);
  euler->z = (short)iVar3;
LAB_80095c30:
  if (uVar6 == 1)
  {
    euler->x = -euler->x;
    euler->z = -euler->z;
    euler->y = -euler->y;
  }
  if ((order & 1U) == 1)
  {
    sVar1 = euler->x;
    euler->x = euler->z;
    euler->z = sVar1;
  }
  local_res8 = (short)order;
  euler->order = local_res8;
  return;
}
