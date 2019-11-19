#include "THISDUST.H"
#include "POOLMMG2.H"


// decompiled code
// original method signature: 
// void /*$ra*/ G2PoolMem_InitPool(void *voidPool /*$s1*/, int blockCount /*$s0*/, int blockSize /*$s2*/)
 // line 9, offset 0x80093c00
	/* begin block 1 */
		// Start line: 10
		// Start offset: 0x80093C00
	/* end block 1 */
	// End offset: 0x80093C00
	// End Line: 10

	/* begin block 2 */
		// Start line: 18
	/* end block 2 */
	// End Line: 19

void G2PoolMem_InitPool(void *voidPool,int blockCount,int blockSize)

{
  char *pcVar1;
  
  pcVar1 = MEMPACK_Malloc(blockCount * blockSize,'\x19');
  *(char **)((int)voidPool + 0xc) = pcVar1;
  pcVar1 = MEMPACK_Malloc(blockCount << 1,'\x19');
  *(char **)((int)voidPool + 8) = pcVar1;
  *(short *)voidPool = (short)blockSize;
  *(undefined2 *)((int)voidPool + 4) = (short)blockCount;
  G2PoolMem_ResetPool(voidPool);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2PoolMem_ResetPool(void *voidPool /*$a0*/)
 // line 32, offset 0x80093c6c
	/* begin block 1 */
		// Start line: 35
		// Start offset: 0x80093C6C
		// Variables:
	// 		struct _G2PoolMemPool_Type *pool; // $a0
	// 		int blockIndex; // $a1
	/* end block 1 */
	// End offset: 0x80093CA0
	// End Line: 48

	/* begin block 2 */
		// Start line: 81
	/* end block 2 */
	// End Line: 82

	/* begin block 3 */
		// Start line: 83
	/* end block 3 */
	// End Line: 84

	/* begin block 4 */
		// Start line: 94
	/* end block 4 */
	// End Line: 95

void G2PoolMem_ResetPool(void *voidPool)

{
  int iVar1;
  
  iVar1 = 0;
  *(undefined2 *)((int)voidPool + 2) = 0;
  if (*(short *)((int)voidPool + 4) != 0) {
    do {
      *(undefined2 *)(iVar1 * 2 + *(int *)((int)voidPool + 8)) = (short)iVar1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)(uint)*(ushort *)((int)voidPool + 4));
  }
  return;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ G2PoolMem_Allocate(void *voidPool /*$a0*/)
 // line 64, offset 0x80093ca8
	/* begin block 1 */
		// Start line: 67
		// Start offset: 0x80093CA8
		// Variables:
	// 		int blockIndex; // $a1
	/* end block 1 */
	// End offset: 0x80093CA8
	// End Line: 75

	/* begin block 2 */
		// Start line: 126
	/* end block 2 */
	// End Line: 127

	/* begin block 3 */
		// Start line: 131
	/* end block 3 */
	// End Line: 132

	/* begin block 4 */
		// Start line: 139
	/* end block 4 */
	// End Line: 140

void * G2PoolMem_Allocate(void *voidPool)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)((uint)*(ushort *)((int)voidPool + 2) * 2 + *(int *)((int)voidPool + 8));
  *(short *)((int)voidPool + 2) = *(ushort *)((int)voidPool + 2) + 1;
  return (void *)(*(int *)((int)voidPool + 0xc) + (uint)*(ushort *)voidPool * (uint)uVar1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2PoolMem_Free(void *voidPool /*$a0*/, void *block /*$a1*/)
 // line 85, offset 0x80093ce0
	/* begin block 1 */
		// Start line: 88
		// Start offset: 0x80093CE0
		// Variables:
	// 		int blockIndex; // $a1
	/* end block 1 */
	// End offset: 0x80093CE0
	// End Line: 94

	/* begin block 2 */
		// Start line: 178
	/* end block 2 */
	// End Line: 179

	/* begin block 3 */
		// Start line: 180
	/* end block 3 */
	// End Line: 181

	/* begin block 4 */
		// Start line: 186
	/* end block 4 */
	// End Line: 187

void G2PoolMem_Free(void *voidPool,void *block)

{
  ushort uVar1;
  
  uVar1 = *(short *)((int)voidPool + 2) - 1;
  *(ushort *)((int)voidPool + 2) = uVar1;
  *(undefined2 *)((uint)uVar1 * 2 + *(int *)((int)voidPool + 8)) =
       (short)((int)((int)block - *(int *)((int)voidPool + 0xc)) / (int)(uint)*(ushort *)voidPool);
  return;
}





