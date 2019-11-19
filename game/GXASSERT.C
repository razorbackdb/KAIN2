#include "THISDUST.H"
#include "GXASSERT.H"


// decompiled code
// original method signature: 
// void /*$ra*/ GXFilePrint(char *fmt /*stack 0*/)
 // line 45, offset 0x80053114
	/* begin block 1 */
		// Start line: 46
		// Start offset: 0x80053114
		// Variables:
	// 		static char diag[256]; // offset 0x0
	/* end block 1 */
	// End offset: 0x80053114
	// End Line: 46

	/* begin block 2 */
		// Start line: 90
	/* end block 2 */
	// End Line: 91

void GXFilePrint(char *fmt)

{
  undefined local_res4 [12];
  
  vsprintf(&diag_24,fmt,local_res4);
  puts(&diag_24);
  return;
}





