#ifndef MEMPACK_H
#define MEMPACK_H


extern void MEMPACK_Init(); // 0x800502F0

extern struct MemHeader * MEMPACK_GetSmallestBlockTopBottom(long allocSize); // 0x80050358

extern struct MemHeader * MEMPACK_GetSmallestBlockBottomTop(long allocSize); // 0x800503C0

extern long MEMPACK_RelocatableType(long memType); // 0x8005042C

extern char * MEMPACK_Malloc(unsigned long allocSize, unsigned char memType); // 0x80050464

extern void MEMORY_MergeAddresses(struct MemHeader *firstAddress, struct MemHeader *secondAddress); // 0x8005063C

extern void MEMPACK_Return(char *address, long takeBackSize); // 0x80050684

extern void MEMPACK_Free(char *address); // 0x80050708

extern void MEMPACK_FreeByType(unsigned char memType); // 0x800507BC

extern unsigned long MEMPACK_Size(char *address); // 0x80050854

extern unsigned long MEMPACK_ReportFreeMemory(); // 0x80050860

extern void MEMPACK_ReportMemory2(); // 0x80050870

extern void MEMPACK_ReportMemory(); // 0x800508A0

extern void MEMPACK_SetMemoryBeingStreamed(char *address); // 0x8005093C

extern void MEMPACK_SetMemoryDoneStreamed(char *address); // 0x80050948

extern long MEMPACK_MemoryValidFunc(char *address); // 0x80050954

extern char * MEMPACK_GarbageCollectMalloc(unsigned long *allocSize, unsigned char memType, unsigned long *freeSize); // 0x80050988

extern void MEMPACK_GarbageSplitMemoryNow(unsigned long allocSize, struct MemHeader *bestAddress, long memType, unsigned long freeSize); // 0x80050B00

extern void MEMPACK_GarbageCollectFree(struct MemHeader *memAddress); // 0x80050B24

extern void MEMPACK_DoGarbageCollection(); // 0x80050BD8

extern void MEMPACK_RelocateAreaType(struct MemHeader *newAddress, long offset, struct Level *oldLevel); // 0x80050DF0

extern void MEMPACK_RelocateG2AnimKeylistType(struct _G2AnimKeylist_Type **pKeylist, int offset, char *start, char *end); // 0x800516E8

extern void MEMPACK_RelocateObjectType(struct MemHeader *newAddress, long offset, struct Object *oldObject); // 0x80051788

extern void MEMPACK_RelocateCDMemory(struct MemHeader *newAddress, long offset, struct _BigFileDir *oldDir); // 0x80051CF8


#endif
