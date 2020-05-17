#include "THISDUST.H"
#include "TIMERG2.H"


// decompiled code
// original method signature: 
// short /*$ra*/ G2Timer_GetFrameTime()
 // line 10, offset 0x800963c0
	/* begin block 1 */
		// Start line: 12
		// Start offset: 0x800963C0
		// Variables:
	// 		short atime; // $v1
	/* end block 1 */
	// End offset: 0x800963F4
	// End Line: 20

	/* begin block 2 */
		// Start line: 20
	/* end block 2 */
	// End Line: 21

	/* begin block 3 */
		// Start line: 21
	/* end block 3 */
	// End Line: 22

	/* begin block 4 */
		// Start line: 22
	/* end block 4 */
	// End Line: 23

/* WARNING: Unknown calling convention yet parameter storage is locked */

short G2Timer_GetFrameTime(void)

{
  short sVar1;
  uint uVar2;
  
  if (gameTrackerX.timeMult == 0) {
    uVar2 = 100;
  }
  else {
    uVar2 = gameTrackerX.timeMult * 0x19 >> 10;
  }
  sVar1 = (short)uVar2;
  if ((int)(uVar2 << 0x10) < 1) {
    sVar1 = 1;
  }
  return sVar1;
}





