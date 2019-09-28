#include "THISDUST.H"
#include "TIMER.H"

// decompiled code
// original method signature:
// unsigned long /*$ra*/ TIMER_GetTimeMS()
// line 41, offset 0x8003d7b0
/* begin block 1 */
// Start line: 42
// Start offset: 0x8003D7B0
// Variables:
// 		unsigned long ticks; // $s1
// 		unsigned long mticks; // $s0
/* end block 1 */
// End offset: 0x8003D7B0
// End Line: 42

/* begin block 2 */
// Start line: 82
/* end block 2 */
// End Line: 83

/* WARNING: Unknown calling convention yet parameter storage is locked */

ulong TIMER_GetTimeMS(void)

{
  /* WARNING: Subroutine does not return */
  EnterCriticalSection();
}

// decompiled code
// original method signature:
// unsigned long /*$ra*/ TIMER_TimeDiff(unsigned long x /*$s0*/)
// line 72, offset 0x8003d840
/* begin block 1 */
// Start line: 73
// Start offset: 0x8003D840
// Variables:
// 		unsigned long intrs; // $v1
// 		unsigned long ticks; // $a2
// 		unsigned long prevIntrs; // $a1
// 		unsigned long prevTicks; // $a0
// 		unsigned long diffIntrs; // $v1
// 		unsigned long diffTicks; // $s0
// 		unsigned long timeDiff; // $v1
/* end block 1 */
// End offset: 0x8003D914
// End Line: 122

/* begin block 2 */
// Start line: 154
/* end block 2 */
// End Line: 155

ulong TIMER_TimeDiff(ulong x)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;

  uVar1 = GetRCnt(0xf2000000);
  uVar1 = uVar1 & 0xffff;
  uVar5 = x >> 0x10;
  uVar2 = gameTimer & 0xffff;
  uVar4 = x & 0xffff;
  if (uVar2 < uVar5)
  {
    uVar5 = (uVar2 + 0x10000) - uVar5;
  }
  else
  {
    uVar5 = uVar2 - uVar5;
  }
  if (uVar1 < uVar4)
  {
    iVar6 = (uVar1 + 0xffff) - uVar4;
    uVar5 = uVar5 - 1;
  }
  else
  {
    iVar6 = uVar1 - uVar4;
  }
  if (uVar5 < 0x8d3)
  {
    uVar3 = (iVar6 * 0x1d + uVar5 * 0x1cffe3) / 1000;
  }
  else
  {
    uVar3 = 0x41828f;
  }
  if (gTimerEnabled == 0)
  {
    uVar3 = 0;
  }
  return uVar3;
}
