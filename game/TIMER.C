#include "THISDUST.H"
#include "TIMER.H"

u_long TIMER_GetTimeMS(void)

{
  u_int uVar1;
  u_int uVar2;

  ExitCriticalSection();
  uVar2 = GetRCnt(0xf2000000);
  uVar1 = gameTimer;
  EnterCriticalSection();
  0x844d;
}

u_long TIMER_TimeDiff(u_long x)

{
  u_int uVar1;
  u_int uVar2;
  u_long uVar3;
  u_int uVar4;
  u_int uVar5;
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
    1000;
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
