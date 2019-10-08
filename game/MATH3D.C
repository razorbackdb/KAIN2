#include "THISDUST.H"
#include "MATH3D.H"

void MATH3D_Sort3VectorCoords(long *a, long *b, long *c)

{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar3 = *a;
  iVar1 = *b;
  iVar2 = *c;
  if (iVar3 < iVar1)
  {
    if (iVar2 < iVar3)
    {
      *c = iVar1;
      *b = iVar3;
      *a = iVar2;
      return;
    }
    if (iVar2 < iVar1)
    {
      *c = iVar1;
      *b = iVar2;
      return;
    }
  }
  else
  {
    if (iVar2 < iVar1)
    {
      *a = iVar2;
      *c = iVar3;
      return;
    }
    if (iVar2 < iVar3)
    {
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

long MATH3D_LengthXY(long x, long y, long z)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;

  if (x < 0)
  {
    x = -x;
  }
  if (y < 0)
  {
    y = -y;
  }
  if (z < 0)
  {
    z = -z;
  }
  iVar1 = x;
  if (x < y)
  {
    iVar1 = y;
    y = x;
  }
  iVar2 = z;
  iVar3 = y;
  iVar4 = iVar1;
  if ((y <= z) && (iVar2 = y, iVar3 = iVar1, iVar4 = z, z < iVar1))
  {
    iVar3 = z;
    iVar4 = iVar1;
  }
  iVar1 = iVar4 * 0x1e + iVar3 * 0xc + iVar2 * 9;
  if (iVar1 < 0)
  {
    iVar1 = iVar1 + 0x1f;
  }
  return iVar1 >> 5;
}

long MATH3D_LengthXYZ(long x, long y)

{
  int iVar1;
  u_int uVar2;

  if (x < 0)
  {
    x = -x;
  }
  if (y < 0)
  {
    y = -y;
  }
  if (y < x)
  {
    uVar2 = x ^ y;
    y = y ^ uVar2;
    x = uVar2 ^ y;
  }
  iVar1 = y * 0x1e + x * 0xc;
  if (iVar1 < 0)
  {
    iVar1 = iVar1 + 0x1f;
  }
  return iVar1 >> 5;
}

void CAMERA_Initialize(_Normal *normal)

{
  long lVar1;

  lVar1 = MATH3D_LengthXY((int)normal->x << 2, (int)normal->y << 2, (int)normal->z << 2);
  if (lVar1 != 0)
  {
 lVar1);
 lVar1);
 lVar1);
  }
  return;
}

short MATH3D_FastAtan2(long y, long x)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short sVar4;

  if (x == 0)
  {
    x = 1;
  }
  if (y != 0)
  {
    iVar3 = x;
    if (x < 0)
    {
      iVar3 = -x;
    }
    iVar2 = y;
    if (y < 0)
    {
      iVar2 = -y;
    }
    if (x < 1)
    {
      if (y < 1)
      {
        if (iVar2 < iVar3)
        {
 iVar3 + 0x800) * 0x10000) >> 0x10);
        }
 iVar2);
 sVar1 = 0xc00;
      }
      else
      {
        if (iVar3 < iVar2)
        {
 iVar2) + 0x400;
        }
 iVar3);
 sVar1 = 0x800;
      }
    }
    else
    {
      if (y < 1)
      {
        if (iVar3 <= iVar2)
        {
 iVar2) + 0xc00;
        }
 iVar3);
 sVar1 = 0x1000;
      }
      else
      {
        if (iVar2 <= iVar3)
        {
 iVar3);
        }
 iVar2);
 sVar1 = 0x400;
      }
    }
    return sVar1 - sVar4;
  }
  return (short)((u_short)(x < 1) << 0xb);
}

long MATH3D_FastSqrt(long square)

{
  int iVar1;
  int iVar2;
  u_int uVar3;
  int iVar4;
  u_int uVar5;
  int iVar6;
  u_int uVar7;

  iVar4 = 0x1f;
  if (square == 0)
  {
    return 0;
  }
  uVar3 = 0x80000000;
  if (-1 < square)
  {
    do
    {
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
  while (uVar5 = uVar5 - 1, uVar5 != 0xffffffff)
  {
    iVar6 = iVar6 >> 2;
    iVar1 = iVar2 - (iVar4 + iVar6);
    uVar3 = (int)uVar3 >> 1;
    iVar4 = iVar4 >> 1;
    if (-1 < iVar1)
    {
      iVar4 = iVar4 + iVar6;
      uVar7 = uVar7 | uVar3;
      iVar2 = iVar1;
    }
  }
  iVar4 = iVar4 << 0xc;
  iVar1 = 0x1000;
  iVar6 = iVar2 << 0xc;
  while (true)
  {
    uVar3 = (int)uVar3 >> 1;
    iVar1 = iVar1 >> 2;
    if (uVar3 == 0)
      break;
    iVar2 = iVar6 - (iVar4 + iVar1);
    iVar4 = iVar4 >> 1;
    if (-1 < iVar2)
    {
      iVar4 = iVar4 + iVar1;
      uVar7 = uVar7 | uVar3;
      iVar6 = iVar2;
    }
  }
  return uVar7;
}

long MATH3D_FastSqrt0(long square)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  u_int uVar5;
  u_int uVar6;
  u_int uVar7;

  iVar4 = 0x1f;
  if (square == 0)
  {
    return 0;
  }
  uVar6 = 0x80000000;
  if (-1 < square)
  {
    do
    {
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
  while (uVar5 = uVar5 - 1, uVar5 != 0xffffffff)
  {
    uVar6 = (int)uVar6 >> 1;
    iVar4 = iVar4 >> 2;
    iVar2 = (iVar1 - iVar3) - iVar4;
    iVar3 = iVar3 >> 1;
    if (-1 < iVar2)
    {
      iVar3 = iVar3 + iVar4;
      uVar7 = uVar7 | uVar6;
      iVar1 = iVar2;
    }
  }
  return uVar7;
}

long MATH3D_DistanceBetweenPositions(_Position *pos1, _Position *pos2)

{
  u_long square;
  long lVar1;

  square = MATH3D_SquareLength((int)pos2->x - (int)pos1->x, (int)pos2->y - (int)pos1->y,
                               (int)pos2->z - (int)pos1->z);
  lVar1 = MATH3D_FastSqrt0(square);
  return lVar1;
}

short MATH3D_AngleBetweenVectors(_SVector *vector1, _SVector *vector2)

{
  u_int uVar1;
  u_int uVar2;
  int iVar3;

  iVar3 = (int)vector1->x * (int)vector2->x;
  if ((int)vector1->x == (int)vector2->x)
  {
    if ((vector1->y == vector2->y) && (vector1->z == vector2->z))
    {
      return 0;
    }
    iVar3 = (int)vector1->x * (int)vector2->x;
  }
  uVar2 = iVar3 + (int)vector1->y * (int)vector2->y + (int)vector1->z * (int)vector2->z + 0x800 >>
          0xc;
  if ((int)uVar2 < 0x1001)
  {
    iVar3 = uVar2 * uVar2;
    if (-0x1001 < (int)uVar2)
      goto LAB_80039f9c;
    uVar2 = 0xfffff000;
  }
  else
  {
    uVar2 = 0x1000;
  }
  iVar3 = uVar2 * uVar2;
LAB_80039f9c:
  uVar1 = MATH3D_FastSqrt0(0x1000000 - iVar3);
  iVar3 = ratan2(uVar1, uVar2);
  return (short)iVar3;
}

void MATH3D_RotMatAboutVec(_SVector *vec, MATRIX *mat, short angle)

{
  u_long uVar1;
  u_int uVar2;
  int iVar3;
  u_short local_60;
  undefined2 local_5e;
  undefined2 local_5c;
  u_int auStack88[8];
  u_char auStack56[8];

  if ((int)angle != 0)
  {
    uVar1 = MATH3D_SquareLength(0, (int)vec->y, (int)vec->z);
    uVar2 = MATH3D_FastSqrt0(uVar1 + 0x800);
    iVar3 = ratan2((int)vec->y, (int)vec->z);
    local_60 = -(short)iVar3;
    iVar3 = ratan2((int)vec->x, uVar2);
    local_5e = (undefined2)iVar3;
    local_5c = 0;
    RotMatrixY(&local_60, auStack88);
    TransposeMatrix(auStack88, auStack56);
    MulMatrix2(auStack56, (u_int *)mat);
    RotMatrixX((int)angle, (u_int *)mat);
    MulMatrix2(auStack88, (u_int *)mat);
  }
  return;
}

void MATH3D_SetUnityMatrix(MATRIX *mat)

{
  *(u_char *)mat->m = 0x1000;
  *(u_char *)(mat->m + 2) = 0;
  *(u_char *)(mat->m + 4) = 0x1000;
  *(u_char *)(mat->m + 6) = 0;
  mat->m[8] = 0x1000;
  return;
}

void AngleMoveToward(short *current_ptr, short destination, short step)

{
  u_short current;
  short sVar1;
  int iVar2;
  int iVar3;

  current = *current_ptr;
  sVar1 = CAMERA_AngleDifference(current, destination);
  iVar3 = (int)sVar1;
  if (iVar3 == 0)
  {
  LAB_8003a120:
    *current_ptr = destination;
    return;
  }
  iVar2 = iVar3;
  if (iVar3 < 0)
  {
    iVar2 = -iVar3;
  }
  if (iVar2 < step)
    goto LAB_8003a120;
  if (iVar3 < 1)
  {
    if (-1 < iVar3)
      goto LAB_8003a148;
    step = -step;
  }
  current = current + step;
LAB_8003a148:
  *current_ptr = current & 0xfff;
  return;
}

short CAMERA_AngleDifference(short current, short destination)

{
  u_short uVar1;

  uVar1 = destination - current & 0xfff;
  if (0x800 < uVar1)
  {
    uVar1 = uVar1 | 0xf000;
  }
  return (short)uVar1;
}

short MATH3D_AngleFromPosToPos(_Position *from, _Position *to)

{
  int iVar1;

  iVar1 = ratan2((int)from->y - (int)to->y, (int)from->x - (int)to->x);
  return (short)((short)iVar1 + 0xc00U & 0xfff);
}

void MATH3D_ZYXtoXYZ(_Rotation *rot)

{
  _G2Matrix_Type _Stack48;
  _G2EulerAngles_Type local_10;

  RotMatrixZYX((u_short *)rot, (u_int *)&_Stack48);
  G2EulerAngles_FromMatrix(&local_10, &_Stack48, 0x15);
  rot->x = local_10.x;
  rot->y = local_10.y;
  rot->z = local_10.z;
  return;
}

short MATH3D_ElevationFromPosToPos(_Position *from, _Position *to)

{
  int iVar1;
  int iVar2;
  long lVar3;

  iVar1 = (int)from->x - (int)to->x;
  iVar2 = (int)from->y - (int)to->y;
  lVar3 = MATH3D_FastSqrt0(iVar1 * iVar1 + iVar2 * iVar2);
  iVar1 = ratan2((int)to->z - (int)from->z, (int)(short)lVar3);
  return (short)(-(short)iVar1 & 0xfff);
}

void MATH3D_RotationFromPosToPos(_Position *from, _Position *to, _Rotation *rot)

{
  short sVar1;

  sVar1 = MATH3D_ElevationFromPosToPos(from, to);
  rot->x = sVar1;
  rot->y = 0;
  sVar1 = MATH3D_AngleFromPosToPos(from, to);
  rot->z = sVar1;
  return;
}

int MATH3D_veclen2(int ix, int iy)

{
  bool bVar1;
  u_int uVar2;

  if (ix < 0)
  {
    ix = -ix;
  }
  bVar1 = ix < iy;
  if (iy < 0)
  {
    iy = -iy;
    bVar1 = ix < iy;
  }
  if (bVar1)
  {
    uVar2 = ix ^ iy;
    iy = iy ^ uVar2;
    ix = uVar2 ^ iy;
  }
  iy = iy + (iy >> 1);
  return ((ix - (ix >> 5)) - (ix >> 7)) + (iy >> 2) + (iy >> 6);
}

void MATH3D_RotateAxisToVector(MATRIX *dest, MATRIX *src, _SVector *vec, MATH3D_AXIS axis)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  u_long square;
  int iVar4;
  int iVar5;
  long lVar6;
  u_int uVar7;
  u_short auStack64[16];
  short local_20;
  short local_1e;
  short local_1c;
  undefined2 local_1a;

  if (axis < AXIS_NEG_X)
  {
    psVar1 = src->m + axis;
    iVar3 = (int)*psVar1;
    iVar4 = (int)psVar1[3];
    iVar5 = (int)psVar1[6];
  }
  else
  {
    psVar1 = src->m + axis + ~AXIS_Z;
    iVar3 = -(int)*psVar1;
    iVar4 = -(int)psVar1[3];
    iVar5 = -(int)psVar1[6];
  }
  iVar2 = iVar4 * vec->z - iVar5 * vec->y;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xfff;
  }
  local_20 = (short)(iVar2 >> 0xc);
  iVar2 = iVar5 * vec->x - iVar3 * vec->z;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xfff;
  }
  local_1e = (short)(iVar2 >> 0xc);
  iVar2 = iVar3 * vec->y - iVar4 * vec->x;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xfff;
  }
  local_1c = (short)(iVar2 >> 0xc);
  iVar3 = iVar3 * vec->x + iVar4 * vec->y + iVar5 * vec->z;
  if (iVar3 < 0)
  {
    iVar3 = iVar3 + 0xfff;
  }
  iVar3 = MATH3D_racos_S(iVar3 >> 0xc);
  uVar7 = ((iVar3 << 0x10) >> 0x10) - ((iVar3 << 0x10) >> 0x1f) >> 1;
  square = MATH3D_SquareLength((int)local_20, (int)local_1e, (int)local_1c);
  if ((int)square < 1)
  {
    lVar6 = 0x1000;
  }
  else
  {
    lVar6 = MATH3D_FastSqrt0(square);
  }
  iVar3 = rsin(uVar7);
 lVar6);
 lVar6);
 lVar6);
 iVar3 = rcos(uVar7);
 local_1a = (undefined2)iVar3;
 G2Quat_ToMatrix_S(&local_20, (short *)auStack64);
 PopMatrix((u_char *)src, auStack64, (u_int *)dest);
 return;
}

int MATH3D_ConeDetect(_SVector *pos, int arc, int elevation)

{
  short sVar1;
  short sVar2;
  long x;
  int y;
  int x_00;

  x_00 = (int)pos->x;
  sVar2 = pos->y;
  y = x_00;
  if (x_00 < 0)
  {
    y = -x_00;
  }
  sVar1 = MATH3D_FastAtan2(y, -(int)sVar2);
  if (sVar1 < arc)
  {
    x = MATH3D_LengthXYZ(x_00, -(int)sVar2);
    y = (int)pos->z;
    if (y < 0)
    {
      y = -y;
    }
    sVar2 = MATH3D_FastAtan2(y, x);
    if (sVar2 < elevation)
    {
      return 1;
    }
  }
  return 0;
}

void MATH3D_CrossProduct(_SVector *t, _SVector *r, _SVector *s)

{
  t->x = (short)((int)r->y * (int)s->z - (int)r->z * (int)s->y >> 0xc);
  t->y = -(short)((int)r->x * (int)s->z - (int)r->z * (int)s->x >> 0xc);
  t->z = (short)((int)r->x * (int)s->y - (int)r->y * (int)s->x >> 0xc);
  return;
}

u_long MATH3D_SquareLength(long x, long y, long z)

{
  int iVar1;
  int iVar2;
  int iVar3;

  setCopReg(2, 0x4800, x);
  setCopReg(2, 0x5000, y);
  setCopReg(2, 0x5800, z);
  copFunction(2, 0xa00428);
  iVar1 = getCopReg(2, 0xc800);
  iVar2 = getCopReg(2, 0xd000);
  iVar3 = getCopReg(2, 0xd800);
  return iVar1 + iVar2 + iVar3;
}
