#ifndef POOLMMG2_H
#define POOLMMG2_H

extern void G2PoolMem_InitPool(void *voidPool, int blockCount, int blockSize);

extern void G2PoolMem_ResetPool(void *voidPool);

extern void *G2PoolMem_Allocate(void *voidPool);

extern void G2PoolMem_Free(void *voidPool, void *block);

#endif
