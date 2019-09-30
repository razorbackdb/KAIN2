#include "THISDUST.H"
#include "TIMER.H"


// decompiled code
// original method signature: 
// unsigned long /*$ra*/ TIMER_GetTimeMS()
 // line 41, offset 0x8003e314
	/* begin block 1 */
		// Start line: 42
		// Start offset: 0x8003E314
		// Variables:
	// 		unsigned long ticks; // $s1
	// 		unsigned long mticks; // $s0
	/* end block 1 */
	// End offset: 0x8003E314
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
 // line 72, offset 0x8003e3a4
	/* begin block 1 */
		// Start line: 73
		// Start offset: 0x8003E3A4
		// Variables:
	// 		unsigned long intrs; // $v1
	// 		unsigned long ticks; // $a2
	// 		unsigned long prevIntrs; // $a1
	// 		unsigned long prevTicks; // $a0
	// 		unsigned long diffIntrs; // $v1
	// 		unsigned long diffTicks; // $s0
	// 		unsigned long timeDiff; // $v1
	/* end block 1 */
	// End offset: 0x8003E478
	// End Line: 122

	/* begin block 2 */
		// Start line: 154
	/* end block 2 */
	// End Line: 155

ulong TIMER_TimeDiff(ulong x)

{
                    /* WARNING: Subroutine does not return */
  GetRCnt(0xf2000000);
}





