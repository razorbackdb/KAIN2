#include "THISDUST.H"
#include "SUPPORT.H"

int printf(char *fmt)

{
  int iVar1;
  undefined local_res4[12];
  char acStack264[256];

  iVar1 = vsprintf(acStack264, fmt, local_res4);
  puts(acStack264);
  return iVar1;
}

int sprintf(char *string, char *fmt)

{
  int iVar1;
  undefined local_res8[8];

  iVar1 = vsprintf(string, fmt, local_res8);
  return iVar1;
}

int vsprintf(char *str, char *fmtstr, void *argptr)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  size_t sVar4;
  char *__dest;
  int radix;
  int iVar5;
  char *__s;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  int __c;
  char local_38;
  undefined local_37;

  bVar1 = *fmtstr;
  iVar8 = 0;
  do
  {
    if (bVar1 == 0)
    {
      str[iVar8] = '\0';
      return iVar8;
    }
    if (bVar1 == 0x25)
    {
      pbVar6 = (byte *)fmtstr + 1;
      bVar1 = *pbVar6;
      if (bVar1 == 0x25)
      {
        str[iVar8] = '%';
        iVar8 = iVar8 + 1;
        fmtstr = (char *)((byte *)fmtstr + 2);
      }
      else
      {
        if (bVar1 == 0x2d)
        {
          pbVar6 = (byte *)fmtstr + 2;
        }
        __c = 0x20;
        if (*pbVar6 == 0x30)
        {
          __c = 0x30;
          pbVar6 = pbVar6 + 1;
        }
        bVar2 = *pbVar6;
        iVar5 = 0;
        while ((u_int)bVar2 - 0x30 < 10)
        {
          bVar3 = *pbVar6;
          pbVar6 = pbVar6 + 1;
          bVar2 = *pbVar6;
          iVar5 = iVar5 * 10 + (u_int)bVar3 + -0x30;
        }
        do
        {
          do
          {
            pbVar7 = pbVar6;
            bVar2 = *pbVar7;
            pbVar6 = pbVar7 + 1;
          } while (bVar2 == 0x4e);
          pbVar6 = pbVar7 + 1;
        } while ((((bVar2 == 0x46) || (pbVar6 = pbVar7 + 1, bVar2 == 0x68)) ||
                  (pbVar6 = pbVar7 + 1, bVar2 == 0x6c)) ||
                 (pbVar6 = pbVar7 + 1, bVar2 == 0x4c));
        bVar2 = *pbVar7;
        if (bVar2 == 99)
        {
          local_38 = *(char *)argptr;
          __s = &local_38;
          local_37 = 0;
        }
        else
        {
          if (bVar2 == 0x73)
          {
            __s = *(char **)argptr;
          }
          else
          {
            if ((bVar2 == 0x78) || (bVar2 == 0x58))
            {
              __s = *(char **)argptr;
              radix = 0x10;
            }
            else
            {
              __s = *(char **)argptr;
              radix = 10;
            }
            __s = my_itoa((u_long)__s, &local_38, radix);
          }
        }
        argptr = (char **)argptr + 1;
        fmtstr = (char *)(pbVar7 + 1);
        sVar4 = strlen(__s);
        if (iVar5 == 0)
        {
        LAB_80073ee8:
          __dest = str + iVar8;
        }
        else
        {
          __dest = str + iVar8;
          if ((int)sVar4 < iVar5)
          {
            if (bVar1 == 0x2d)
            {
              strcmp(__dest, __s);
              memset(str + iVar8 + sVar4, __c, iVar5 - sVar4);
              iVar8 = iVar8 + sVar4 + (iVar5 - sVar4);
              goto LAB_80073ef8;
            }
            memset(__dest, __c, iVar5 - sVar4);
            iVar8 = iVar8 + (iVar5 - sVar4);
            goto LAB_80073ee8;
          }
        }
        strcmp(__dest, __s);
        iVar8 = iVar8 + sVar4;
      }
    }
    else
    {
      str[iVar8] = bVar1;
      fmtstr = (char *)((byte *)fmtstr + 1);
      iVar8 = iVar8 + 1;
    }
  LAB_80073ef8:
    bVar1 = *fmtstr;
  } while (true);
}

char *my_itoa(u_long value, char *str, int radix)

{
  char cVar1;
  byte *pbVar2;
  char *pcVar3;
  byte local_20[32];

  if (value == 0)
  {
    *str = '0';
    str[1] = '\0';
  }
  else
  {
    if (0x22 < radix - 2U)
    {
      radix = 10;
    }
    pbVar2 = local_20;
    pcVar3 = str;
    if ((radix == 10) && (pbVar2 = local_20, (int)value < 0))
    {
      *str = '-';
      pcVar3 = str + 1;
      value = -value;
      pbVar2 = local_20;
    }
    while (value != 0)
    {
      *pbVar2 = (char)(value % radix);
      (u_int) radix;
      pbVar2 = pbVar2 + 1;
    }
    pbVar2 = pbVar2 + -1;
    if (local_20 <= pbVar2)
    {
      do
      {
        cVar1 = '0';
        if (9 < *pbVar2)
        {
          cVar1 = 'W';
        }
        *pcVar3 = *pbVar2 + cVar1;
        pbVar2 = pbVar2 + -1;
        pcVar3 = pcVar3 + 1;
      } while (local_20 <= pbVar2);
    }
    *pcVar3 = '\0';
  }
  return str;
}

int atoi(char *str)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;

  iVar4 = 0;
  cVar1 = *str;
  if (cVar1 == '-')
  {
    str = str + 1;
  }
  bVar2 = *str;
  while (bVar2 != 0)
  {
    bVar3 = *str;
    str = (char *)((byte *)str + 1);
    bVar2 = *str;
    iVar4 = iVar4 * 10 + -0x30 + (u_int)bVar3;
  }
  if (cVar1 != '-')
  {
    return iVar4;
  }
  return -iVar4;
}

int mytolower(int c)

{
  if (c - 0x41U < 0x1a)
  {
    c = c + 0x20;
  }
  return c;
}

int strcpy(char *s1, char *s2)

{
  byte bVar1;
  int iVar2;
  int iVar3;

  do
  {
    bVar1 = *s1;
    s1 = (char *)((byte *)s1 + 1);
    iVar2 = mytolower((u_int)bVar1);
    bVar1 = *s2;
    s2 = (char *)((byte *)s2 + 1);
    iVar3 = mytolower((u_int)bVar1);
    if (iVar2 != iVar3)
    {
      return iVar2 - iVar3;
    }
  } while (iVar2 != 0);
  return 0;
}
