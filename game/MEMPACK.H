#ifndef MEMPACK_H
#define MEMPACK_H


extern void MEMPACK_Init(); // 0x8005137C

extern struct MemHeader * MEMPACK_GetSmallestBlockTopBottom(long allocSize); // 0x800513FC

extern struct MemHeader * MEMPACK_GetSmallestBlockBottomTop(long allocSize); // 0x80051464

extern long MEMPACK_RelocatableType(long memType); // 0x800514D0

extern char * MEMPACK_Malloc(unsigned long allocSize, unsigned char memType); // 0x800514F8

extern void MEMORY_MergeAddresses(struct MemHeader *firstAddress, struct MemHeader *secondAddress); // 0x800516E8

extern void MEMPACK_Return(char *address, long takeBackSize); // 0x80051730

extern void MEMPACK_Free(char *address); // 0x800517B4

extern void MEMPACK_FreeByType(unsigned char memType); // 0x80051868

extern unsigned long MEMPACK_Size(char *address); // 0x80051900

extern unsigned long MEMPACK_ReportFreeMemory(); // 0x8005190C

extern void MEMPACK_ReportMemory2(); // 0x8005191C

extern void MEMPACK_ReportMemory(); // 0x80051A08

extern void MEMPACK_SetMemoryBeingStreamed(char *address); // 0x80051BC8

extern void MEMPACK_SetMemoryDoneStreamed(char *address); // 0x80051BD4

extern long MEMPACK_MemoryValidFunc(char *address); // 0x80051BE0

extern char * MEMPACK_GarbageCollectMalloc(unsigned long *allocSize, unsigned char memType, unsigned long *freeSize); // 0x80051C14

extern void MEMPACK_GarbageSplitMemoryNow(unsigned long allocSize, struct MemHeader *bestAddress, long memType, unsigned long freeSize); // 0x80051D9C

extern void MEMPACK_GarbageCollectFree(struct MemHeader *memAddress); // 0x80051DC0

extern void MEMPACK_DoGarbageCollection(); // 0x80051E74

extern void MEMPACK_RelocateAreaType(struct MemHeader *newAddress, long offset, struct Level *oldLevel); // 0x80052058

extern void MEMPACK_RelocateG2AnimKeylistType(struct _G2AnimKeylist_Type **pKeylist, int offset, char *start, char *end); // 0x80052AD0

extern void MEMPACK_RelocateObjectType(struct MemHeader *newAddress, long offset, struct Object *oldObject); // 0x80052B70

extern int MEMPACK_AvailableMemory(); // 0x800530E0

extern void MEMPACK_RelocateCDMemory(struct MemHeader *newAddress, long offset, struct _BigFileDir *oldDir); // 0x800530F0


#endif
