#ifndef POOLMMG2_H
#define POOLMMG2_H


extern void G2PoolMem_InitPool(void *voidPool, int blockCount, int blockSize); // 0x800957DC

extern void G2PoolMem_ResetPool(void *voidPool); // 0x80095848

extern void * G2PoolMem_Allocate(void *voidPool); // 0x80095884

extern void G2PoolMem_Free(void *voidPool, void *block); // 0x800958E0


#endif
