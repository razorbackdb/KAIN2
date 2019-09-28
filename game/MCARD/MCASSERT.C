#include "THISDUST.H"
#include "MCASSERT.H"


// decompiled code
// original method signature: 
// void /*$ra*/ mcassert(char *exp /*$a3*/, char *file /*$a1*/, long line /*$a2*/)
 // line 10, offset 0x800b9dc0
	/* begin block 1 */
		// Start line: 20
	/* end block 1 */
	// End Line: 21

void mcassert(char *exp,char *file,long line)

{
  if (exp == (char *)0x0) {
    printf(s__s__ld__assertion_failure_800124c0);
  }
  else {
    printf(s__s__ld___s_800124b4);
  }
  trap(0x407);
  return;
}





