#include "THISDUST.H"
#include "RAZCNTRL.H"

// int @0x800CF590, len = 0x00000004
Down = 0x0;
// int @0x800CF588, len = 0x00000004
Pending = 0x0;
// long @0x800CF560, len = 0x00000004
RazielCommands = 0x8000;
// int @0x800CF58C, len = 0x00000004
Up = 0x0;
// decompiled code
// original method signature:
// void /*$ra*/ ProcessRazControl(long *command /*$a0*/)
// line 67, offset 0x80070694
/* begin block 1 */
// Start line: 134
/* end block 1 */
// End Line: 135

/* begin block 2 */
// Start line: 136
/* end block 2 */
// End Line: 137

void ProcessRazControl(long *command)

{
  if ((*command & LONG_800cf568) == 0)
  {
    Up = Up + 1;
    if (Down != 0)
    {
      Pending = Down;
    }
    Down = 0;
  }
  else
  {
    Up = 0;
    Down = Down + 1;
  }
  if (5 < Down)
  {
    Pending = Down;
  }
  if (2 < Up)
  {
    Pending = 0;
  }
  return;
}
