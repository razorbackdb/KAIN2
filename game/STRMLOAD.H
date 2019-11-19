#ifndef STRMLOAD_H
#define STRMLOAD_H


extern void STREAM_InitLoader(char *bigFileName, char *voiceFileName); // 0x80060E6C

extern void STREAM_RemoveQueueHead(); // 0x80060EC8

extern void STREAM_RemoveQueueEntry(struct _LoadQueueEntry *entry, struct _LoadQueueEntry *prev); // 0x80060F08

extern struct _LoadQueueEntry * STREAM_AddQueueEntryToTail(); // 0x80060F64

extern struct _LoadQueueEntry * STREAM_AddQueueEntryToHead(); // 0x80060FA4

extern int STREAM_IsCdBusy(long *numberInQueue); // 0x80060FE4

extern int STREAM_PollLoadQueue(); // 0x80061004

extern struct _LoadQueueEntry * STREAM_SetUpQueueEntry(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer, int fromhead); // 0x8006148C

extern void STREAM_QueueNonblockingLoads(char *fileName, unsigned char memType, void *retFunc, void *retData, void *retData2, void **retPointer, long relocateBinary); // 0x80061568

extern void LOAD_LoadToAddress(char *fileName, void *loadAddr, long relocateBinary); // 0x800615EC

extern void LOAD_NonBlockingBinaryLoad(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer, int memType); // 0x80061654

extern void LOAD_NonBlockingFileLoad(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer, int memType); // 0x80061698

extern void LOAD_NonBlockingBufferedLoad(char *fileName, void *retFunc, void *retData, void *retData2); // 0x800616D8

extern int LOAD_IsXAInQueue(); // 0x80061714

extern void LOAD_PlayXA(int number); // 0x80061754

extern long * LOAD_ReadFile(char *fileName, unsigned char memType); // 0x8006179C

extern void LOAD_ChangeDirectory(char *name); // 0x800617E8

extern void LOAD_AbortFileLoad(char *fileName, void *retFunc); // 0x80061844


#endif
