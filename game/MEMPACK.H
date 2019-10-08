#ifndef MEMPACK_H
#define MEMPACK_H

extern void MEMPACK_Init();

extern struct MemHeader *MEMPACK_GetSmallestBlockTopBottom(long allocSize);

extern struct MemHeader *MEMPACK_GetSmallestBlockBottomTop(long allocSize);

extern long MEMPACK_RelocatableType(long memType);

extern char *MEMPACK_Malloc(unsigned long allocSize, unsigned char memType);

extern void MEMORY_MergeAddresses(struct MemHeader *firstAddress, struct MemHeader *secondAddress);

extern void MEMPACK_Return(char *address, long takeBackSize);

extern void MEMPACK_Free(char *address);

extern void MEMPACK_FreeByType(unsigned char memType);

extern unsigned long MEMPACK_Size(char *address);

extern unsigned long MEMPACK_ReportFreeMemory();

extern void MEMPACK_ReportMemory2();

extern void MEMPACK_ReportMemory();

extern void MEMPACK_SetMemoryBeingStreamed(char *address);

extern void MEMPACK_SetMemoryDoneStreamed(char *address);

extern long MEMPACK_MemoryValidFunc(char *address);

extern char *MEMPACK_GarbageCollectMalloc(unsigned long *allocSize, unsigned char memType, unsigned long *freeSize);

extern void MEMPACK_GarbageSplitMemoryNow(unsigned long allocSize, struct MemHeader *bestAddress, long memType, unsigned long freeSize);

extern void MEMPACK_GarbageCollectFree(struct MemHeader *memAddress);

extern void MEMPACK_DoGarbageCollection();

extern void MEMPACK_RelocateAreaType(struct MemHeader *newAddress, long offset, struct Level *oldLevel);

extern void MEMPACK_RelocateG2AnimKeylistType(struct _G2AnimKeylist_Type **pKeylist, int offset, char *start, char *end);

extern void MEMPACK_RelocateObjectType(struct MemHeader *newAddress, long offset, struct Object *oldObject);

extern void MEMPACK_RelocateCDMemory(struct MemHeader *newAddress, long offset, struct _BigFileDir *oldDir);

#endif
