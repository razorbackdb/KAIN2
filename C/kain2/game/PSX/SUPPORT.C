#include "THISDUST.H"
#include "SUPPORT.H"

// decompiled code
// original method signature:
// int /*$ra*/ printf(char *fmt /*stack 0*/)
// line 57, offset 0x80074170
/* begin block 1 */
// Start line: 58
// Start offset: 0x80074170
// Variables:
// 		int len; // $s0
// 		char string[256]; // stack offset -264
/* end block 1 */
// End offset: 0x80074170
// End Line: 58

/* begin block 2 */
// Start line: 114
/* end block 2 */
// End Line: 115

int printf(char *fmt)

{
  int iVar1;
  undefined local_res4[12];
  char acStack264[256];

  iVar1 = vsprintf(acStack264, fmt, local_res4);
  puts(acStack264);
  return iVar1;
}

// decompiled code
// original method signature:
// int /*$ra*/ sprintf(char *string /*$a0*/, char *fmt /*stack 4*/)
// line 79, offset 0x800741c0
/* begin block 1 */
// Start line: 80
// Start offset: 0x800741C0
/* end block 1 */
// End offset: 0x800741C0
// End Line: 80

/* begin block 2 */
// Start line: 172
/* end block 2 */
// End Line: 173

int sprintf(char *string, char *fmt)

{
  int iVar1;
  undefined local_res8[8];

  iVar1 = vsprintf(string, fmt, local_res8);
  return iVar1;
}

// decompiled code
// original method signature:
// int /*$ra*/ vsprintf(char *str /*$s7*/, char *fmtstr /*$a1*/, void *argptr /*$s5*/)
// line 110, offset 0x800741f0
/* begin block 1 */
// Start line: 111
// Start offset: 0x800741F0
// Variables:
// 		int scopy; // $s4
// 		char *fmt; // $s3

/* begin block 1.1 */
// Start line: 121
// Start offset: 0x80074258
// Variables:
// 		int fsize; // $s0
// 		int pad; // $s6
// 		int left_just; // $fp
// 		int ts_len; // $s2
// 		char *temp_str; // $s1
// 		char buf[16]; // stack offset -56
/* end block 1.1 */
// End offset: 0x80074420
// End Line: 221
/* end block 1 */
// End offset: 0x80074430
// End Line: 223

/* begin block 2 */
// Start line: 220
/* end block 2 */
// End Line: 221

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
        while ((uint)bVar2 - 0x30 < 10)
        {
          bVar3 = *pbVar6;
          pbVar6 = pbVar6 + 1;
          bVar2 = *pbVar6;
          iVar5 = iVar5 * 10 + (uint)bVar3 + -0x30;
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
            __s = my_itoa((ulong)__s, &local_38, radix);
          }
        }
        argptr = (char **)argptr + 1;
        fmtstr = (char *)(pbVar7 + 1);
        sVar4 = strlen(__s);
        if (iVar5 == 0)
        {
        LAB_80074410:
          __dest = str + iVar8;
        }
        else
        {
          __dest = str + iVar8;
          if ((int)sVar4 < iVar5)
          {
            if (bVar1 == 0x2d)
            {
              strcpy(__dest, __s);
              memset(str + iVar8 + sVar4, __c, iVar5 - sVar4);
              iVar8 = iVar8 + sVar4 + (iVar5 - sVar4);
              goto LAB_80074420;
            }
            memset(__dest, __c, iVar5 - sVar4);
            iVar8 = iVar8 + (iVar5 - sVar4);
            goto LAB_80074410;
          }
        }
        strcpy(__dest, __s);
        iVar8 = iVar8 + sVar4;
      }
    }
    else
    {
      str[iVar8] = bVar1;
      fmtstr = (char *)((byte *)fmtstr + 1);
      iVar8 = iVar8 + 1;
    }
  LAB_80074420:
    bVar1 = *fmtstr;
  } while (true);
}

// decompiled code
// original method signature:
// char * /*$ra*/ my_itoa(unsigned long value /*$v1*/, char *str /*$a1*/, int radix /*$a2*/)
// line 231, offset 0x8007446c
/* begin block 1 */
// Start line: 232
// Start offset: 0x8007446C
// Variables:
// 		char *p; // $a0
// 		char *q; // $a3
// 		char digits[31]; // stack offset -32
/* end block 1 */
// End offset: 0x80074534
// End Line: 272

/* begin block 2 */
// Start line: 466
/* end block 2 */
// End Line: 467

char *my_itoa(ulong value, char *str, int radix)

{
  char cVar1;
  byte *pbVar2;
  char *pcVar3;
  byte local_20[32];

  cVar1 = DAT_800cf5b9;
  if (value == 0)
  {
    *str = DAT_800cf5b8;
    str[1] = cVar1;
  }
  else
  {
    if (0x22 < radix - 2U)
    {
      radix = 10;
    }
    pbVar2 = local_20;
    pcVar3 = str;
    if ((radix == 10) && (pbVar2 = local_20, pcVar3 = str, (int)value < 0))
    {
      *str = '-';
      pcVar3 = str + 1;
      value = -value;
      pbVar2 = local_20;
    }
    while (value != 0)
    {
      *pbVar2 = (char)(value % radix);
      value = value / (uint)radix;
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

// decompiled code
// original method signature:
// int /*$ra*/ atoi(char *str /*$a1*/)
// line 295, offset 0x8007453c
/* begin block 1 */
// Start line: 296
// Start offset: 0x8007453C
// Variables:
// 		int val; // $a2
// 		int neg; // $a3
/* end block 1 */
// End offset: 0x8007459C
// End Line: 316

/* begin block 2 */
// Start line: 590
/* end block 2 */
// End Line: 591

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
    iVar4 = iVar4 * 10 + -0x30 + (uint)bVar3;
  }
  if (cVar1 != '-')
  {
    return iVar4;
  }
  return -iVar4;
}

// decompiled code
// original method signature:
// int /*$ra*/ mytolower(int c /*$a0*/)
// line 319, offset 0x800745ac
/* begin block 1 */
// Start line: 618
/* end block 1 */
// End Line: 619

/* begin block 2 */
// Start line: 619
/* end block 2 */
// End Line: 620

int mytolower(int c)

{
  if (c - 0x41U < 0x1a)
  {
    c = c + 0x20;
  }
  return c;
}

// decompiled code
// original method signature:
// int /*$ra*/ strcmpi(char *s1 /*$s1*/, char *s2 /*$s2*/)
// line 325, offset 0x800745c8
/* begin block 1 */
// Start line: 327
// Start offset: 0x800745E4
// Variables:
// 		int c1; // $s0
// 		int c2; // $v0
/* end block 1 */
// End offset: 0x80074610
// End Line: 338

/* begin block 2 */
// Start line: 630
/* end block 2 */
// End Line: 631

int strcmpi(char *s1, char *s2)

{
  byte bVar1;
  int iVar2;
  int iVar3;

  do
  {
    bVar1 = *s1;
    s1 = (char *)((byte *)s1 + 1);
    iVar2 = mytolower((uint)bVar1);
    bVar1 = *s2;
    s2 = (char *)((byte *)s2 + 1);
    iVar3 = mytolower((uint)bVar1);
    if (iVar2 != iVar3)
    {
      return iVar2 - iVar3;
    }
  } while (iVar2 != 0);
  return 0;
}
