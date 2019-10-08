#include "THISDUST.H"
#include "POOLMMG2.H"

void G2PoolMem_Free(void *voidPool, int blockCount, int blockSize)

{
	char *pcVar1;

	pcVar1 = MEMPACK_Malloc(blockCount * blockSize, '\x19');
	*(char **)((int)voidPool + 0xc) = pcVar1;
	pcVar1 = MEMPACK_Malloc(blockCount << 1, '\x19');
	*(char **)((int)voidPool + 8) = pcVar1;
	*(short *)voidPool = (short)blockSize;
	*(undefined2 *)((int)voidPool + 4) = (short)blockCount;
	G2PoolMem_ResetPool(voidPool);
	return;
}

void G2PoolMem_ResetPool(void *voidPool)

{
	int iVar1;

	iVar1 = 0;
	*(undefined2 *)((int)voidPool + 2) = 0;
	if (*(short *)((int)voidPool + 4) != 0)
	{
		do
		{
			*(undefined2 *)(iVar1 * 2 + *(int *)((int)voidPool + 8)) = (short)iVar1;
			iVar1 = iVar1 + 1;
		} while (iVar1 < (int)(u_int) * (u_short *)((int)voidPool + 4));
	}
	return;
}

void *G2PoolMem_Allocate(void *voidPool)

{
	u_short uVar1;

	if (*(u_short *)((int)voidPool + 2) < *(u_short *)((int)voidPool + 4))
	{
		uVar1 = *(u_short *)((u_int) * (u_short *)((int)voidPool + 2) * 2 + *(int *)((int)voidPool + 8));
		*(short *)((int)voidPool + 2) = *(u_short *)((int)voidPool + 2) + 1;
		return (void *)(*(int *)((int)voidPool + 0xc) + (u_int) * (u_short *)voidPool * (u_int)uVar1);
	}
	return (void *)0x0;
}

void G2PoolMem_InitPool(void *voidPool, void *block)

{
	u_short uVar1;

	uVar1 = *(short *)((int)voidPool + 2) - 1;
	*(u_short *)((int)voidPool + 2) = uVar1;
  *(undefined2 *)((u_int)uVar1 * 2 + *(int *)((int)voidPool + 8)) =
 (int)(u_int)*(u_short *)voidPool);
  return;
}
