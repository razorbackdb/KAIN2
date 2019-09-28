//#include "THISDUST.H"
#include "MAINVM.H"

// decompiled code
// original method signature: 
// int /*$ra*/ main()
 // line 50, offset 0x800962c0
	/* begin block 1 */
		// Start line: 100
	/* end block 1 */
	// End Line: 101

/* WARNING: Unknown calling convention yet parameter storage is locked */

int main(void)

{
  int iVar1;
  _Terrain *in_a0;
  BSPTree *in_a1;
  _SVector *in_a2;
  _SVector *in_a3;
  _TFace *local_8;
  long in_stack_00000000;
  long in_stack_fffffffc;
  
  //ClearBss(in_a0,in_a1,in_a2,in_a3,local_8,in_stack_fffffffc,in_stack_00000000);
  iVar1 = MainG2(&_appDataVM);
  return iVar1;
}