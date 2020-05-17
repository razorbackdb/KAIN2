#ifndef STRMLOAD_H
#define STRMLOAD_H


extern void STREAM_NextLoadFromHead(); // 0x8005FF80

extern void STREAM_NextLoadAsNormal(); // 0x8005FF90

extern void STREAM_InitLoader(char *bigFileName, char *voiceFileName); // 0x8005FF9C

extern void STREAM_RemoveQueueHead(); // 0x8005FFF8

extern void STREAM_RemoveQueueEntry(struct _LoadQueueEntry *entry, struct _LoadQueueEntry *prev); // 0x80060038

extern struct _LoadQueueEntry * STREAM_AddQueueEntryToTail(); // 0x80060094

extern struct _LoadQueueEntry * STREAM_AddQueueEntryToHead(); // 0x80060100

extern int STREAM_IsCdBusy(long *numberInQueue); // 0x800601B4

extern int STREAM_PollLoadQueue(); // 0x800601D4

extern struct _LoadQueueEntry * STREAM_SetUpQueueEntry(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer, int fromhead); // 0x800605C0

extern void STREAM_QueueNonblockingLoads(char *fileName, unsigned char memType, void *retFunc, void *retData, void *retData2, void **retPointer, long relocateBinary); // 0x800606C0

extern void LOAD_LoadToAddress(char *fileName, void *loadAddr, long relocateBinary); // 0x80060740

extern void LOAD_NonBlockingBinaryLoad(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer, int memType); // 0x800607A8

extern void LOAD_NonBlockingFileLoad(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer, int memType); // 0x800607EC

extern void LOAD_NonBlockingBufferedLoad(char *fileName, void *retFunc, void *retData, void *retData2); // 0x8006082C

extern int LOAD_IsXAInQueue(); // 0x80060868

extern void LOAD_PlayXA(int number); // 0x800608B0

extern long * LOAD_ReadFile(char *fileName, unsigned char memType); // 0x800608F8

extern void LOAD_ChangeDirectory(char *name); // 0x80060944

extern void LOAD_AbortDirectoryChange(char *name); // 0x800609A4

extern void LOAD_AbortFileLoad(char *fileName, void *retFunc); // 0x80060A2C


#endif
