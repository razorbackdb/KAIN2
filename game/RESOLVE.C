#include "THISDUST.H"
#include "RESOLVE.H"

void RESOLVE_Pointers(RedirectList *redirectList, long *data, long *baseAddr)

{
	int iVar1;
	int *piVar2;
	int iVar3;

	iVar3 = redirectList->numPointers;
	piVar2 = redirectList->data;
	while (iVar3 != 0)
	{
		iVar1 = *piVar2;
		iVar3 = iVar3 + -1;
		piVar2 = piVar2 + 1;
		*(int *)((int)data + iVar1) = *(int *)((int)data + iVar1) + (int)baseAddr;
	}
	return;
}
