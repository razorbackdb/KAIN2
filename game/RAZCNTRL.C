#include "THISDUST.H"
#include "RAZCNTRL.H"


// decompiled code
// original method signature: 
// void /*$ra*/ ProcessRazControl(long *command /*$a0*/)
 // line 67, offset 0x800704b0
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
  if ((*command & 0x20) == 0) {
    Up = Up + 1;
    if (Down != 0) {
      Pending = Down;
    }
    Down = 0;
  }
  else {
    Up = 0;
    Down = Down + 1;
  }
  if (5 < Down) {
    Pending = Down;
  }
  if (2 < Up) {
    Pending = 0;
  }
  return;
}





