#ifndef STRMLOAD_H
#define STRMLOAD_H

extern void STREAM_NextLoadFromHead();

extern void STREAM_InitLoader(char *bigFileName, char *voiceFileName);

extern void STREAM_RemoveQueueHead();

extern void STREAM_RemoveQueueEntry(struct _LoadQueueEntry *entry, struct _LoadQueueEntry *prev);

extern struct _LoadQueueEntry *STREAM_AddQueueEntryToTail();

extern struct _LoadQueueEntry *STREAM_AddQueueEntryToHead();

extern int STREAM_IsCdBusy(long *numberInQueue);

extern int STREAM_PollLoadQueue();

extern struct _LoadQueueEntry *STREAM_SetUpQueueEntry(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer, int fromhead);

extern void STREAM_QueueNonblockingLoads(char *fileName, unsigned char memType, void *retFunc, void *retData, void *retData2, void **retPointer, long relocateBinary);

extern void LOAD_LoadToAddress(char *fileName, void *loadAddr, long relocateBinary);

extern void LOAD_NonBlockingBinaryLoad(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer, int memType);

extern void LOAD_NonBlockingFileLoad(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer, int memType);

extern void LOAD_NonBlockingBufferedLoad(char *fileName, void *retFunc, void *retData, void *retData2);

extern int LOAD_IsXAInQueue();

extern void LOAD_PlayXA(int number);

extern long *LOAD_ReadFile(char *fileName, unsigned char memType);

extern void LOAD_ChangeDirectory(char *name);

extern void LOAD_AbortFileLoad(char *fileName, void *retFunc);

#endif
