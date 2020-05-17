#include "THISDUST.H"
#include "LOCALSTR.H"


// decompiled code
// original method signature: 
// enum language_t /*$ra*/ localstr_get_language()
 // line 50, offset 0x800b7630
	/* begin block 1 */
		// Start line: 100
	/* end block 1 */
	// End Line: 101

	/* begin block 2 */
		// Start line: 101
	/* end block 2 */
	// End Line: 102

/* WARNING: Unknown calling convention yet parameter storage is locked */

language_t localstr_get_language(void)

{
  return the_language;
}



// decompiled code
// original method signature: 
// void /*$ra*/ localstr_set_language(enum language_t lang /*$a0*/)
 // line 55, offset 0x800b763c
	/* begin block 1 */
		// Start line: 56
		// Start offset: 0x800B763C
		// Variables:
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x800B76BC
	// End Line: 92

	/* begin block 2 */
		// Start line: 110
	/* end block 2 */
	// End Line: 111

void localstr_set_language(language_t lang)

{
  LocalizationHeader *pLVar1;
  LocalizationHeader *pLVar2;
  int iVar3;
  
  pLVar1 = (LocalizationHeader *)LOAD_ReadFileFromCD("\\LOCALS.TBL;1",6);
  pLVar2 = pLVar1 + 1;
  LocalizationTable = pLVar1;
  if (pLVar1 != (LocalizationHeader *)0x0) {
    voiceList = (XAVoiceListEntry *)((int)&pLVar1->language + pLVar1->XATableOffset);
    iVar3 = 0;
    LocalStrings = (char **)pLVar2;
    if (0 < pLVar1->numStrings) {
      do {
        iVar3 = iVar3 + 1;
        pLVar2->language = (int)&pLVar1->language + pLVar2->language;
        pLVar2 = (LocalizationHeader *)&pLVar2->numXAfiles;
      } while (iVar3 < pLVar1->numStrings);
    }
    the_language = LocalizationTable->language;
  }
  return;
}



// decompiled code
// original method signature: 
// char * /*$ra*/ localstr_get(enum localstr_t id /*$a0*/)
 // line 96, offset 0x800b76cc
	/* begin block 1 */
		// Start line: 98
		// Start offset: 0x800B76CC
		// Variables:
	// 		static char BlankStr[2]; // offset 0x1c
	/* end block 1 */
	// End offset: 0x800B76F0
	// End Line: 106

	/* begin block 2 */
		// Start line: 214
	/* end block 2 */
	// End Line: 215

	/* begin block 3 */
		// Start line: 215
	/* end block 3 */
	// End Line: 216

	/* begin block 4 */
		// Start line: 216
	/* end block 4 */
	// End Line: 217

char * localstr_get(localstr_t id)

{
  if (LocalStrings == (char **)0x0) {
    return ".";
  }
  return LocalStrings[id];
}





