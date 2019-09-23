#ifndef POOLMMG2_H
#define POOLMMG2_H

struct _G2PoolMemPool_Type // hashcode: 0x987744BB (dec: -1737014085)
{
	unsigned short blockSize;		   // size=0, offset=0 //  hashcode: 0xA084AE57 (dec: -1601917353), parent name: '_G2PoolMemPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short stackTop;		   // size=0, offset=2 //  hashcode: 0x41930E04 (dec: 1100156420), parent name: '_G2PoolMemPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short stackSize;		   // size=0, offset=4 //  hashcode: 0xBAA5D921 (dec: -1163536095), parent name: '_G2PoolMemPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short *stack;			   // size=0, offset=8 //  hashcode: 0xFBFD4500 (dec: -67287808), parent name: '_G2PoolMemPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2PoolMem_Type *blockPool; // size=0, offset=12 //  hashcode: 0xB9BCD220 (dec: -1178807776), parent name: '_G2PoolMemPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct _G2PoolMemPool_Type G2PoolMemPool;

extern void G2PoolMem_InitPool(void *voidPool, int blockCount, int blockSize); // 0x80095D9C

extern void G2PoolMem_ResetPool(void *voidPool); // 0x80095E08

extern void *G2PoolMem_Allocate(void *voidPool); // 0x80095E44

extern void G2PoolMem_Free(void *voidPool, void *block); // 0x80095EA0

#endif
