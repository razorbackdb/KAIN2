//#include "THISDUST.H"
#include "SNMAIN.H"
#include "MAINVM.H"
#include "MAIN.H"
#include "DRAWS.H"
#include "DEBUG.H"

// _G2AppDataVM_Type @0x800D517C, len = 0x00000008_appDataVM = {
		// int @0x800D517C, len = 0x00000004.argc = null,
		// int * @0x800D5180, len = 0x00000004.argv = null};
// decompiled code
// original method signature:
// int /*$ra*/ main()
// line 50, offset 0x800962c0
/* begin block 1 */
// Start line: 100
/* end block 1 */
// End Line: 101

/* WARNING: Unknown calling convention yet parameter storage is locked */

void __main(void)

{	
	int __initialised = 0; //stub
	if (__initialised == 0)
	{
		__initialised = 1;
	}
	return;
}

void ClearBss(void)

{
  DebugMenuLine *pDVar1;
  
  /*pDVar1 = &eventMenu;
  do {
    pDVar1->type = DEBUG_LINE_TYPE_BIT;
    pDVar1 = (DebugMenuLine *)&pDVar1->lower;
  } while (pDVar1 < (DebugMenuLine *)&DAT_800dd340);*/
  return;
}

int main(void)

{
	int iVar1;

	__main();
	ClearBss();
	iVar1 = MainG2(&_appDataVM);
	return iVar1;
}
