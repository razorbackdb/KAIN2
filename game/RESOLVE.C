
#include "RESOLVE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ RESOLVE_Pointers(struct RedirectList *redirectList /*$a0*/, long *data /*$a1*/, long *baseAddr /*$a2*/)
 // line 55, offset 0x8003d1dc
	/* begin block 1 */
		// Start line: 60
		// Start offset: 0x8003D1DC
		// Variables:
	// 		long *rdList; // $a0
	// 		int i; // $a3

		/* begin block 1.1 */
			// Start line: 64
			// Start offset: 0x8003D1EC
			// Variables:
		// 		long *handle; // $v1
		/* end block 1.1 */
		// End offset: 0x8003D1EC
		// End Line: 65
	/* end block 1 */
	// End offset: 0x8003D20C
	// End Line: 77

	/* begin block 2 */
		// Start line: 110
	/* end block 2 */
	// End Line: 111

	/* begin block 3 */
		// Start line: 114
	/* end block 3 */
	// End Line: 115

	/* begin block 4 */
		// Start line: 116
	/* end block 4 */
	// End Line: 117

/* File: C:\kain2\game\RESOLVE.C */

void RESOLVE_Pointers(RedirectList *redirectList,long *data,long *baseAddr)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = redirectList->numPointers;
  piVar2 = redirectList->data;
  while (iVar3 != 0) {
    iVar1 = *piVar2;
    iVar3 = iVar3 + -1;
    piVar2 = piVar2 + 1;
    *(int *)((int)data + iVar1) = *(int *)((int)data + iVar1) + (int)baseAddr;
  }
  return;
}





