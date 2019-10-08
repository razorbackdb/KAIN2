#include "THISDUST.H"
#include "LOCALSTR.H"

language_t localstr_get_language(void)

{
	return the_language;
}

void localstr_set_language(language_t lang)

{
	LocalizationHeader *pLVar1;
	LocalizationHeader *pLVar2;
	int iVar3;

	pLVar1 = (LocalizationHeader *)LOAD_ReadFile("\\LOCALS.TBL;1", 6);
	pLVar2 = pLVar1 + 1;
	LocalizationTable = pLVar1;
	if (pLVar1 != (LocalizationHeader *)0x0)
	{
		voiceList = (XAVoiceListEntry *)((int)&pLVar1->language + pLVar1->XATableOffset);
		iVar3 = 0;
		LocalStrings = (char **)pLVar2;
		if (0 < pLVar1->numStrings)
		{
			do
			{
				iVar3 = iVar3 + 1;
				pLVar2->language = (int)&pLVar1->language + pLVar2->language;
				pLVar2 = (LocalizationHeader *)&pLVar2->numXAfiles;
			} while (iVar3 < pLVar1->numStrings);
		}
		the_language = LocalizationTable->language;
	}
	return;
}

char *localstr_get(localstr_t id)

{
	if (LocalStrings == (char **)0x0)
	{
		return ".";
	}
	return LocalStrings[id];
}
