#ifndef POOLMMG2_H
#define POOLMMG2_H


extern void G2PoolMem_InitPool(void *voidPool, int blockCount, int blockSize); // 0x80095EDC

extern void G2PoolMem_ResetPool(void *voidPool); // 0x80095F48

extern void * G2PoolMem_Allocate(void *voidPool); // 0x80095F84

extern void G2PoolMem_Free(void *voidPool, void *block); // 0x80095FE0


#endif
