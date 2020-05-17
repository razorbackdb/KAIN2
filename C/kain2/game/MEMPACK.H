#ifndef MEMPACK_H
#define MEMPACK_H


extern void MEMPACK_Init(); // 0x80050090

extern struct MemHeader * MEMPACK_GetSmallestBlockTopBottom(long allocSize); // 0x800500F8

extern struct MemHeader * MEMPACK_GetSmallestBlockBottomTop(long allocSize); // 0x80050160

extern long MEMPACK_RelocatableType(long memType); // 0x800501CC

extern char * MEMPACK_Malloc(unsigned long allocSize, unsigned char memType); // 0x80050204

extern void MEMORY_MergeAddresses(struct MemHeader *firstAddress, struct MemHeader *secondAddress); // 0x800503CC

extern void MEMPACK_Return(char *address, long takeBackSize); // 0x80050414

extern void MEMPACK_Free(char *address); // 0x80050498

extern void MEMPACK_FreeByType(unsigned char memType); // 0x80050548

extern unsigned long MEMPACK_Size(char *address); // 0x800505E0

extern unsigned long MEMPACK_ReportFreeMemory(); // 0x800505EC

extern void MEMPACK_ReportMemory2(); // 0x800505FC

extern void MEMPACK_ReportMemory(); // 0x8005062C

extern void MEMPACK_SetMemoryBeingStreamed(char *address); // 0x800506C8

extern void MEMPACK_SetMemoryDoneStreamed(char *address); // 0x800506D4

extern long MEMPACK_MemoryValidFunc(char *address); // 0x800506E0

extern char * MEMPACK_GarbageCollectMalloc(unsigned long *allocSize, unsigned char memType, unsigned long *freeSize); // 0x80050714

extern void MEMPACK_GarbageSplitMemoryNow(unsigned long allocSize, struct MemHeader *bestAddress, long memType, unsigned long freeSize); // 0x8005088C

extern void MEMPACK_GarbageCollectFree(struct MemHeader *memAddress); // 0x800508B0

extern void MEMPACK_DoGarbageCollection(); // 0x80050960

extern void MEMPACK_RelocateAreaType(struct MemHeader *newAddress, long offset, struct Level *oldLevel); // 0x80050B78

extern void MEMPACK_RelocateG2AnimKeylistType(struct _G2AnimKeylist_Type **pKeylist, int offset, char *start, char *end); // 0x8005145C

extern void MEMPACK_RelocateObjectType(struct MemHeader *newAddress, long offset, struct Object *oldObject); // 0x800514FC

extern void MEMPACK_RelocateCDMemory(struct MemHeader *newAddress, long offset, struct _BigFileDir *oldDir); // 0x80051A6C


#endif
