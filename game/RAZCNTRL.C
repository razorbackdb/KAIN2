#include "THISDUST.H"
#include "RAZCNTRL.H"

void FX_ProcessRain(long *command)

{
  if ((*command & 0x20) == 0)
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
