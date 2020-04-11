#include "THISDUST.H"
#include "LOCALSTR.H"


// decompiled code
// original method signature: 
// enum language_t /*$ra*/ localstr_get_language()
 // line 46, offset 0x800b62c4
	/* begin block 1 */
		// Start line: 92
	/* end block 1 */
	// End Line: 93

	/* begin block 2 */
		// Start line: 93
	/* end block 2 */
	// End Line: 94

/* File: C:\kain2\game\LOCAL\LOCALSTR.C */

language_t localstr_get_language(void)

{
  return the_language;
}



// decompiled code
// original method signature: 
// void /*$ra*/ localstr_set_language(enum language_t lang /*$a0*/)
 // line 51, offset 0x800b62d0
	/* begin block 1 */
		// Start line: 52
		// Start offset: 0x800B62D0
		// Variables:
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x800B6350
	// End Line: 88

	/* begin block 2 */
		// Start line: 102
	/* end block 2 */
	// End Line: 103

/* File: C:\kain2\game\LOCAL\LOCALSTR.C */

void localstr_set_language(language_t lang)

{
  LocalizationHeader *pLVar1;
  LocalizationHeader *pLVar2;
  int iVar3;
  
  pLVar1 = (LocalizationHeader *)LOAD_ReadFileFromCD(s__LOCALS_TBL_1_800d0c5c,6);
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
 // line 92, offset 0x800b6360
	/* begin block 1 */
		// Start line: 94
		// Start offset: 0x800B6360
		// Variables:
	// 		static char BlankStr[2]; // offset 0x1c
	/* end block 1 */
	// End offset: 0x800B6388
	// End Line: 102

	/* begin block 2 */
		// Start line: 206
	/* end block 2 */
	// End Line: 207

	/* begin block 3 */
		// Start line: 207
	/* end block 3 */
	// End Line: 208

	/* begin block 4 */
		// Start line: 208
	/* end block 4 */
	// End Line: 209

/* File: C:\kain2\game\LOCAL\LOCALSTR.C */

char * localstr_get(localstr_t id)

{
  if (LocalStrings == (char **)0x0) {
    return &DAT_800d0c6c;
  }
  return LocalStrings[id];
}





