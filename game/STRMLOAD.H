#ifndef STRMLOAD_H
#define STRMLOAD_H


extern void STREAM_NextLoadFromHead(); // 0x80060198

extern void STREAM_InitLoader(char *bigFileName, char *voiceFileName); // 0x800601A8

extern void STREAM_RemoveQueueHead(); // 0x80060204

extern void STREAM_RemoveQueueEntry(struct _LoadQueueEntry *entry, struct _LoadQueueEntry *prev); // 0x80060244

extern struct _LoadQueueEntry * STREAM_AddQueueEntryToTail(); // 0x800602A0

extern struct _LoadQueueEntry * STREAM_AddQueueEntryToHead(); // 0x800602E0

extern int STREAM_IsCdBusy(long *numberInQueue); // 0x80060370

extern int STREAM_PollLoadQueue(); // 0x80060390

extern struct _LoadQueueEntry * STREAM_SetUpQueueEntry(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer, int fromhead); // 0x80060730

extern void STREAM_QueueNonblockingLoads(char *fileName, unsigned char memType, void *retFunc, void *retData, void *retData2, void **retPointer, long relocateBinary); // 0x80060830

extern void LOAD_LoadToAddress(char *fileName, void *loadAddr, long relocateBinary); // 0x800608B8

extern void LOAD_NonBlockingBinaryLoad(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer, int memType); // 0x80060920

extern void LOAD_NonBlockingFileLoad(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer, int memType); // 0x80060964

extern void LOAD_NonBlockingBufferedLoad(char *fileName, void *retFunc, void *retData, void *retData2); // 0x800609A4

extern int LOAD_IsXAInQueue(); // 0x800609E0

extern void LOAD_PlayXA(int number); // 0x80060A20

extern long * LOAD_ReadFile(char *fileName, unsigned char memType); // 0x80060A68

extern void LOAD_ChangeDirectory(char *name); // 0x80060AB4

extern void LOAD_AbortFileLoad(char *fileName, void *retFunc); // 0x80060B14


#endif
