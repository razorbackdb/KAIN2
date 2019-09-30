#include "THISDUST.H"
#include "SUPPORT.H"


// decompiled code
// original method signature: 
// int /*$ra*/ printf(char *fmt /*stack 0*/)
 // line 57, offset 0x80073c48
	/* begin block 1 */
		// Start line: 58
		// Start offset: 0x80073C48
		// Variables:
	// 		int len; // $s0
	// 		char string[256]; // stack offset -264
	/* end block 1 */
	// End offset: 0x80073C48
	// End Line: 58

	/* begin block 2 */
		// Start line: 114
	/* end block 2 */
	// End Line: 115

int printf(char *fmt)

{
  undefined local_res4 [12];
  char acStack264 [256];
  
                    /* WARNING: Subroutine does not return */
  vsprintf(acStack264,fmt,local_res4);
}



// decompiled code
// original method signature: 
// int /*$ra*/ sprintf(char *string /*$a0*/, char *fmt /*stack 4*/)
 // line 79, offset 0x80073c98
	/* begin block 1 */
		// Start line: 80
		// Start offset: 0x80073C98
	/* end block 1 */
	// End offset: 0x80073C98
	// End Line: 80

	/* begin block 2 */
		// Start line: 172
	/* end block 2 */
	// End Line: 173

int sprintf(char *string,char *fmt)

{
  undefined local_res8 [8];
  
                    /* WARNING: Subroutine does not return */
  vsprintf(string,fmt,local_res8);
}



// decompiled code
// original method signature: 
// int /*$ra*/ vsprintf(char *str /*$s7*/, char *fmtstr /*$a1*/, void *argptr /*$s5*/)
 // line 110, offset 0x80073cc8
	/* begin block 1 */
		// Start line: 111
		// Start offset: 0x80073CC8
		// Variables:
	// 		int scopy; // $s4
	// 		char *fmt; // $s3

		/* begin block 1.1 */
			// Start line: 121
			// Start offset: 0x80073D30
			// Variables:
		// 		int fsize; // $s0
		// 		int pad; // $s6
		// 		int left_just; // $fp
		// 		int ts_len; // $s2
		// 		char *temp_str; // $s1
		// 		char buf[16]; // stack offset -56
		/* end block 1.1 */
		// End offset: 0x80073EF8
		// End Line: 221
	/* end block 1 */
	// End offset: 0x80073F08
	// End Line: 223

	/* begin block 2 */
		// Start line: 213
	/* end block 2 */
	// End Line: 214

int vsprintf(char *str,char *fmtstr,void *argptr)

{
  char cVar1;
  byte bVar2;
  ulong value;
  char *__s;
  byte *pbVar3;
  byte *pbVar4;
  int radix;
  char local_38;
  undefined local_37;
  
  cVar1 = *fmtstr;
  radix = 0;
  do {
    if (cVar1 == '\0') {
      str[radix] = '\0';
      return radix;
    }
    if (cVar1 == '%') {
      pbVar3 = (byte *)(fmtstr + 1);
      if (*pbVar3 != 0x25) {
        if (*pbVar3 == 0x2d) {
          pbVar3 = (byte *)(fmtstr + 2);
        }
        if (*pbVar3 == 0x30) {
          pbVar3 = pbVar3 + 1;
        }
        bVar2 = *pbVar3;
        while ((uint)bVar2 - 0x30 < 10) {
          pbVar3 = pbVar3 + 1;
          bVar2 = *pbVar3;
        }
        do {
          do {
            pbVar4 = pbVar3;
            bVar2 = *pbVar4;
            pbVar3 = pbVar4 + 1;
          } while (bVar2 == 0x4e);
          pbVar3 = pbVar4 + 1;
        } while ((((bVar2 == 0x46) || (pbVar3 = pbVar4 + 1, bVar2 == 0x68)) ||
                 (pbVar3 = pbVar4 + 1, bVar2 == 0x6c)) || (pbVar3 = pbVar4 + 1, bVar2 == 0x4c));
        bVar2 = *pbVar4;
        if (bVar2 == 99) {
          local_38 = *(char *)argptr;
          __s = &local_38;
          local_37 = 0;
        }
        else {
          if (bVar2 == 0x73) {
            __s = *(char **)argptr;
          }
          else {
            if ((bVar2 == 0x78) || (bVar2 == 0x58)) {
              value = *(ulong *)argptr;
              radix = 0x10;
            }
            else {
              value = *(ulong *)argptr;
              radix = 10;
            }
            __s = my_itoa(value,&local_38,radix);
          }
        }
                    /* WARNING: Subroutine does not return */
        strlen(__s);
      }
      str[radix] = '%';
      fmtstr = fmtstr + 2;
    }
    else {
      str[radix] = cVar1;
      fmtstr = fmtstr + 1;
    }
    radix = radix + 1;
    cVar1 = *fmtstr;
  } while( true );
}



// decompiled code
// original method signature: 
// char * /*$ra*/ my_itoa(unsigned long value /*$v1*/, char *str /*$a1*/, int radix /*$a2*/)
 // line 231, offset 0x80073f44
	/* begin block 1 */
		// Start line: 232
		// Start offset: 0x80073F44
		// Variables:
	// 		char *p; // $a0
	// 		char *q; // $a3
	// 		char digits[31]; // stack offset -32
	/* end block 1 */
	// End offset: 0x8007400C
	// End Line: 272

	/* begin block 2 */
		// Start line: 466
	/* end block 2 */
	// End Line: 467

char * my_itoa(ulong value,char *str,int radix)

{
  char cVar1;
  byte *pbVar2;
  char *pcVar3;
  byte local_20 [32];
  
  if (value == 0) {
    *str = '0';
    str[1] = '\0';
  }
  else {
    if (0x22 < radix - 2U) {
      radix = 10;
    }
    pbVar2 = local_20;
    pcVar3 = str;
    if ((radix == 10) && (pbVar2 = local_20, (int)value < 0)) {
      *str = '-';
      pcVar3 = str + 1;
      value = -value;
      pbVar2 = local_20;
    }
    while (value != 0) {
      *pbVar2 = (char)(value % radix);
      value = value / (uint)radix;
      pbVar2 = pbVar2 + 1;
    }
    pbVar2 = pbVar2 + -1;
    if (local_20 <= pbVar2) {
      do {
        cVar1 = '0';
        if (9 < *pbVar2) {
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
 // line 295, offset 0x80074014
	/* begin block 1 */
		// Start line: 296
		// Start offset: 0x80074014
		// Variables:
	// 		int val; // $a2
	// 		int neg; // $a3
	/* end block 1 */
	// End offset: 0x80074074
	// End Line: 316

	/* begin block 2 */
		// Start line: 584
	/* end block 2 */
	// End Line: 585

int atoi(char *str)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  
  iVar4 = 0;
  cVar1 = *str;
  if (cVar1 == '-') {
    str = str + 1;
  }
  bVar2 = *str;
  while (bVar2 != 0) {
    bVar3 = *str;
    str = (char *)((byte *)str + 1);
    bVar2 = *str;
    iVar4 = iVar4 * 10 + -0x30 + (uint)bVar3;
  }
  if (cVar1 != '-') {
    return iVar4;
  }
  return -iVar4;
}



// decompiled code
// original method signature: 
// int /*$ra*/ mytolower(int c /*$a0*/)
 // line 319, offset 0x80074084
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
  if (c - 0x41U < 0x1a) {
    c = c + 0x20;
  }
  return c;
}



// decompiled code
// original method signature: 
// int /*$ra*/ strcmpi(char *s1 /*$s1*/, char *s2 /*$s2*/)
 // line 325, offset 0x800740a0
	/* begin block 1 */
		// Start line: 327
		// Start offset: 0x800740BC
		// Variables:
	// 		int c1; // $s0
	// 		int c2; // $v0
	/* end block 1 */
	// End offset: 0x800740E8
	// End Line: 338

	/* begin block 2 */
		// Start line: 630
	/* end block 2 */
	// End Line: 631

int strcmpi(char *s1,char *s2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  do {
    bVar1 = *s1;
    s1 = (char *)((byte *)s1 + 1);
    iVar2 = mytolower((uint)bVar1);
    bVar1 = *s2;
    s2 = (char *)((byte *)s2 + 1);
    iVar3 = mytolower((uint)bVar1);
    if (iVar2 != iVar3) {
      return iVar2 - iVar3;
    }
  } while (iVar2 != 0);
  return 0;
}





