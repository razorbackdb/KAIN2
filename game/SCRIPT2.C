#include "THISDUST.H"
#include "SCRIPT2.H"

*void LitShaftInit(_Instance *instance, GameTracker *gameTracker)

{
  short sVar1;
  int iVar2;
  short *psVar3;

  psVar3 = (short *)instance->data;
  if (psVar3 == (short *)0x0)
  {
    return;
  }

  if (iVar2 != 700)
  {
    if (iVar2 < 0x2bd)
    {
      sVar1 = 0x1000;
      if (iVar2 != 600)
      {
        return;
      }
      goto code_r0x80060c5c;
    }
    if (iVar2 != 0x708)
    {
      if (iVar2 != 0x76c)
      {
        return;
      }
      instance->fadeValue = 0x1000;
      return;
    }
  }
  sVar1 = *psVar3;
code_r0x80060c5c:
  instance->fadeValue = sVar1;
  return;
