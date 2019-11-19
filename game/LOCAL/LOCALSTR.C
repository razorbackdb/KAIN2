#include "THISDUST.H"
#include "LOCALSTR.H"


// decompiled code
// original method signature: 
// void /*$ra*/ localstr_set_language(enum language_t lang /*$a0*/)
 // line 50, offset 0x800b1abc
	/* begin block 1 */
		// Start line: 51
		// Start offset: 0x800B1ABC
		// Variables:
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x800B1B3C
	// End Line: 79

	/* begin block 2 */
		// Start line: 95
	/* end block 2 */
	// End Line: 96

	/* begin block 3 */
		// Start line: 96
	/* end block 3 */
	// End Line: 97

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
 // line 83, offset 0x800b1b4c
	/* begin block 1 */
		// Start line: 85
		// Start offset: 0x800B1B4C
		// Variables:
	// 		static char BlankStr[2]; // offset 0x1c
	/* end block 1 */
	// End offset: 0x800B1B74
	// End Line: 93

	/* begin block 2 */
		// Start line: 176
	/* end block 2 */
	// End Line: 177

	/* begin block 3 */
		// Start line: 177
	/* end block 3 */
	// End Line: 178

	/* begin block 4 */
		// Start line: 178
	/* end block 4 */
	// End Line: 179

char * localstr_get(localstr_t id)

{
  if (LocalStrings == (char **)0x0) {
    return ".";
  }
  return LocalStrings[id];
}





