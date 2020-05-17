#include "THISDUST.H"
#include "MCASSERT.H"


// decompiled code
// original method signature: 
// void /*$ra*/ mcassert(char *exp /*$a3*/, char *file /*$a1*/, long line /*$a2*/)
 // line 10, offset 0x800b9a38
	/* begin block 1 */
		// Start line: 20
	/* end block 1 */
	// End Line: 21

void mcassert(char *exp,char *file,long line)

{
  if (exp == (char *)0x0) {
    printf("%s:%ld: assertion failure\n");
  }
  else {
    printf("%s:%ld: %s\n");
  }
  trap(0x407);
  return;
}





