#include "THISDUST.H"
#include "MAINVM.H"

// _G2AppDataVM_Type @0x800D517C, len = 0x00000008
_appDataVM =
	{
		// int @0x800D517C, len = 0x00000004
		.argc = null,
		// int * @0x800D5180, len = 0x00000004
		.argv = null};
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

	__main();
	ClearBss();
	iVar1 = MainG2(&_appDataVM);
	return iVar1;
}
