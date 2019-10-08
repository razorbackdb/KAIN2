#include "THISDUST.H"
#include "STRMLOAD.H"

void STREAM_NextLoadFromHead(void)

{
  loadBufferedFromHead = 1;
  return;
}

void STREAM_Init(char *bigFileName, char *voiceFileName)

{
  _LoadQueueEntry *p_Var1;
  _LoadQueueEntry *p_Var2;
  int iVar3;

  LOAD_InitCdLoader(bigFileName, voiceFileName);
  iVar3 = 0x26;
  p_Var2 = &_LoadQueueEntry_800da5a0;
  p_Var1 = &_LoadQueueEntry_800da610;
  loadFree = &LoadQueue;
  loadHead = (_LoadQueueEntry *)0x0;
  loadTail = (_LoadQueueEntry *)0x0;
  numLoads = 0;
  do
  {
    p_Var2->next = p_Var1;
    p_Var2 = p_Var2 + -1;
    iVar3 = iVar3 + -1;
    p_Var1 = p_Var1 + -1;
  } while (-1 < iVar3);
  _LoadQueueEntry_800da610.next = (_LoadQueueEntry *)0x0;
  return;
}

void STREAM_RemoveQueueEntry(void)

{
  _LoadQueueEntry **pp_Var1;
  _LoadQueueEntry *p_Var2;

  p_Var2 = loadFree;
  if (loadHead->next == (_LoadQueueEntry *)0x0)
  {
    loadTail = (_LoadQueueEntry *)0x0;
  }
  loadFree = loadHead;
  pp_Var1 = &loadHead->next;
  loadHead = loadHead->next;
  *pp_Var1 = p_Var2;
  numLoads = numLoads + -1;
  return;
}

void STREAM_RemoveQueueHead(_LoadQueueEntry *entry, _LoadQueueEntry *prev)

{
  _LoadQueueEntry *p_Var1;

  if (loadTail == entry)
  {
    loadTail = prev;
  }
  if (prev == (_LoadQueueEntry *)0x0)
  {
    loadHead = entry->next;
  }
  else
  {
    prev->next = entry->next;
  }
  p_Var1 = entry;
  entry->next = loadFree;
  loadFree = p_Var1;
  numLoads = numLoads + -1;
  return;
}

_LoadQueueEntry *STREAM_AddQueueEntryToTail(void)

{
  _LoadQueueEntry *p_Var1;
  _LoadQueueEntry *p_Var2;

  p_Var1 = loadFree;
  p_Var2 = loadFree->next;
  loadFree->next = (_LoadQueueEntry *)0x0;
  if (loadTail == (_LoadQueueEntry *)0x0)
  {
    loadHead = loadFree;
    loadFree = p_Var2;
  }
  else
  {
    loadTail->next = loadFree;
    loadFree = p_Var2;
  }
  loadTail = p_Var1;
  numLoads = numLoads + 1;
  return p_Var1;
}

_LoadQueueEntry *STREAM_SetUpQueueEntry(void)

{
  short sVar1;
  _LoadQueueEntry **pp_Var2;
  _LoadQueueEntry *p_Var3;
  _LoadQueueEntry *p_Var4;

  p_Var4 = loadHead;
  p_Var3 = loadFree;
  if ((((loadHead == (_LoadQueueEntry *)0x0) || (sVar1 = loadHead->status, sVar1 == 1)) ||
       (sVar1 == 5)) ||
      ((sVar1 == 10 || (sVar1 == 8))))
  {
    loadHead = loadFree;
    pp_Var2 = &loadFree->next;
    loadFree = loadFree->next;
    *pp_Var2 = p_Var4;
  }
  else
  {
    pp_Var2 = &loadFree->next;
    loadFree = loadFree->next;
    *pp_Var2 = loadHead->next;
    p_Var4->next = p_Var3;
  }
  if (loadTail == (_LoadQueueEntry *)0x0)
  {
    loadTail = p_Var3;
  }
  numLoads = numLoads + 1;
  return p_Var3;
}

int STREAM_IsCdBusy(long *numberInQueue)

{
  if (numberInQueue != (long *)0x0)
  {
    *numberInQueue = numLoads;
  }
  return numLoads;
}

int STREAM_PollLoadQueue(void)

{
  _LoadQueueEntry *p_Var1;
  code *pcVar2;
  long *plVar3;
  _LoadQueueEntry *p_Var4;
  int id;
  u_long uVar5;
  long **pplVar6;
  long takeBackSize;

  LOAD_ProcessReadQueue();
  p_Var1 = loadHead;
  if (loadHead == (_LoadQueueEntry *)0x0)
  {
    return numLoads;
  }
  if (gameTrackerX.debugFlags < 0)
  {
    FONT_Print("%s status %d\n");
  }
  switch ((int)(((u_int)(u_short)p_Var1->status - 1) * 0x10000) >> 0x10)
  {
  case 0:
    uVar5 = TIMER_GetTimeMS();
    p_Var1->endLoadTime = uVar5;
    LOAD_NonBlockingReadFile(&p_Var1->loadEntry);
    id = LOAD_ChangeDirectory();
    if (id == 0)
    {
      p_Var1->status = 2;
      if (p_Var1->mempackUsed != '\0')
      {
        MEMPACK_SetMemoryBeingStreamed((char *)(p_Var1->loadEntry).loadAddr);
      }
      pplVar6 = (long **)(p_Var1->loadEntry).retPointer;
      if (pplVar6 != (long **)0x0)
      {
        *pplVar6 = (p_Var1->loadEntry).loadAddr;
      }
    }
    else
    {
      p_Var4 = STREAM_SetUpQueueEntry();
      sprintf((p_Var4->loadEntry).fileName, "(%d)");
      takeBackSize = (p_Var1->loadEntry).dirHash;
      p_Var4->status = 10;
      (p_Var4->loadEntry).dirHash = takeBackSize;
    }
    break;
  case 1:
    id = LOAD_NonBlockingFileLoad();
    if (id != 0)
    {
      return numLoads;
    }
    uVar5 = TIMER_GetTimeMS();
    p_Var1->endLoadTime = uVar5 - p_Var1->endLoadTime;
    if (p_Var1->relocateBinary != '\0')
    {
      takeBackSize = LOAD_RelocBinaryData((p_Var1->loadEntry).loadAddr, (p_Var1->loadEntry).loadSize);
      if (p_Var1->mempackUsed != '\0')
      {
        MEMPACK_Return((char *)(p_Var1->loadEntry).loadAddr, takeBackSize);
      }
      p_Var1->relocateBinary = '\0';
    }
    if ((p_Var1->loadEntry).retFunc != (void *)0x0)
    {
      p_Var1->status = 7;
      return numLoads;
    }
    p_Var1->status = 4;
    if (p_Var1->mempackUsed != '\0')
    {
      MEMPACK_SetMemoryDoneStreamed((char *)(p_Var1->loadEntry).loadAddr);
    }
    goto LAB_80060710;
  case 4:
    plVar3 = (long *)LOAD_InitBuffers();
    (p_Var1->loadEntry).loadAddr = plVar3;
    uVar5 = TIMER_GetTimeMS();
    p_Var1->endLoadTime = uVar5;
    LOAD_CD_ReadPartOfFile(&p_Var1->loadEntry);
    id = LOAD_ChangeDirectory();
    if (id == 0)
    {
      p_Var1->status = 6;
      (p_Var1->loadEntry).posInFile = 0;
    }
    else
    {
      p_Var4 = STREAM_SetUpQueueEntry();
      sprintf((p_Var4->loadEntry).fileName, "(%d)");
      takeBackSize = (p_Var1->loadEntry).dirHash;
      p_Var4->status = 10;
      (p_Var4->loadEntry).dirHash = takeBackSize;
      LOAD_CleanUpBuffers();
    }
    break;
  case 5:
    id = LOAD_NonBlockingFileLoad();
    if (id == 0)
    {
      uVar5 = TIMER_GetTimeMS();
      p_Var1->status = 4;
      p_Var1->endLoadTime = uVar5 - p_Var1->endLoadTime;
      STREAM_RemoveQueueEntry();
      LOAD_CleanUpBuffers();
      if ((code *)(p_Var1->loadEntry).retFunc == VRAM_TransferBufferToVram)
      {
        VRAM_LoadReturn((p_Var1->loadEntry).loadAddr, (p_Var1->loadEntry).retData,
                        (p_Var1->loadEntry).retData2);
      }
    }
    break;
  case 6:
    p_Var1->status = 4;
    STREAM_RemoveQueueEntry();
    if (p_Var1->mempackUsed != '\0')
    {
      MEMPACK_SetMemoryDoneStreamed((char *)(p_Var1->loadEntry).loadAddr);
    }
    STREAM_NextLoadFromHead();
    pcVar2 = (code *)(p_Var1->loadEntry).retFunc;
    if (pcVar2 != (code *)0x0)
    {
      (*pcVar2)((p_Var1->loadEntry).loadAddr, (p_Var1->loadEntry).retData,
                (p_Var1->loadEntry).retData2);
    }
    break;
  case 7:
    id = (p_Var1->loadEntry).fileHash;
    p_Var1->status = 9;
    VOICEXA_Init(id, 0);
    break;
  case 8:
    id = VOICEXA_IsPlaying();
    if (id != 0)
    {
      return numLoads;
    }
    LOAD_InitCdStreamMode();
    goto LAB_80060710;
  case 9:
    uVar5 = TIMER_GetTimeMS();
    id = (p_Var1->loadEntry).dirHash;
    p_Var1->endLoadTime = uVar5;
    id = LOAD_ChangeDirectoryByID(id);
    if (id == 0)
    {
      DEBUG_FatalError("Could not read directory hash %d\n");
    }
    p_Var1->status = 0xb;
    break;
  case 10:
    id = LOAD_NonBlockingFileLoad();
    if (id != 0)
    {
      return numLoads;
    }
    uVar5 = TIMER_GetTimeMS();
    p_Var1->endLoadTime = uVar5 - p_Var1->endLoadTime;
  LAB_80060710:
    STREAM_RemoveQueueEntry();
  }
  return numLoads;
}

_LoadQueueEntry *
STREAM_AddQueueEntryToHead(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer, int fromhead)

{
  _LoadQueueEntry *p_Var1;
  long lVar2;

  if (fromhead == 0)
  {
    p_Var1 = STREAM_AddQueueEntryToTail();
  }
  else
  {
    p_Var1 = STREAM_SetUpQueueEntry();
  }
  strcmp((p_Var1->loadEntry).fileName, fileName);
  lVar2 = LOAD_HashName(fileName);
  (p_Var1->loadEntry).fileHash = lVar2;
  lVar2 = LOAD_GetSearchDirectory();
  (p_Var1->loadEntry).dirHash = lVar2;
  (p_Var1->loadEntry).posInFile = 0;
  (p_Var1->loadEntry).checksumType = 1;
  lVar2 = LOAD_GetSearchDirectory();
  if (lVar2 == 0)
  {
    (p_Var1->loadEntry).dirHash = gCurDir;
    (p_Var1->loadEntry).retFunc = retFunc;
  }
  else
  {
    lVar2 = LOAD_GetSearchDirectory();
    (p_Var1->loadEntry).dirHash = lVar2;
    LOAD_SetSearchDirectory(0);
    (p_Var1->loadEntry).retFunc = retFunc;
  }
  (p_Var1->loadEntry).retData = retData;
  (p_Var1->loadEntry).retData2 = retData2;
  (p_Var1->loadEntry).retPointer = retPointer;
  if (retPointer != (void **)0x0)
  {
    *retPointer = (void *)0xfafbfcfd;
  }
  return p_Var1;
}

void STREAM_QueueNonblockingLoads(char *fileName, u_char memType, void *retFunc, void *retData, void *retData2,
                                  void **retPointer, long relocateBinary)

{
  short sVar1;
  _LoadQueueEntry *p_Var2;
  u_int fromhead;

  fromhead = 0;
  if (loadBufferedFromHead != 0)
  {
    fromhead = (u_int)(memType == '\0');
  }
  loadBufferedFromHead = 0;
  p_Var2 = STREAM_AddQueueEntryToHead(fileName, retFunc, retData, retData2, retPointer, fromhead);
  (p_Var2->loadEntry).loadAddr = (long *)0x0;
  p_Var2->mempackUsed = '\x01';
  (p_Var2->loadEntry).memType = (u_int)memType;
  p_Var2->relocateBinary = (char)relocateBinary;
  if (memType == '\0')
  {
    sVar1 = 5;
  }
  else
  {
    sVar1 = 1;
  }
  p_Var2->status = sVar1;
  return;
}

void LOAD_LoadTIM(char *fileName, void *loadAddr, long relocateBinary)

{
  _LoadQueueEntry *p_Var1;
  int iVar2;

  p_Var1 = STREAM_AddQueueEntryToHead(fileName, (void *)0x0, (void *)0x0, (void *)0x0, (void **)0x0, 0);
  (p_Var1->loadEntry).loadAddr = loadAddr;
  p_Var1->status = 1;
  p_Var1->relocateBinary = (char)relocateBinary;
  p_Var1->mempackUsed = '\0';
  do
  {
    iVar2 = STREAM_PollLoadQueue();
  } while (iVar2 != 0);
  return;
}

void LOAD_NonBlockingBufferedLoad(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer,
                                  int memType)

{
  STREAM_QueueNonblockingLoads(fileName, (u_char)memType, retFunc, retData, retData2, retPointer, 1);
  return;
}

void LOAD_IsFileLoading(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer,
                        int memType)

{
  STREAM_QueueNonblockingLoads(fileName, (u_char)memType, retFunc, retData, retData2, retPointer, 0);
  return;
}

void LOAD_NonBlockingBinaryLoad(char *fileName, void *retFunc, void *retData, void *retData2)

{
  STREAM_QueueNonblockingLoads(fileName, '\0', retFunc, retData, retData2, (void **)0x0, 0);
  return;
}

int LOAD_IsXAInQueue(void)

{
  _LoadQueueEntry *p_Var1;
  int iVar2;

  iVar2 = 0;
  p_Var1 = &LoadQueue;
  do
  {
    iVar2 = iVar2 + 1;
    if ((u_int)(u_short)p_Var1->status - 8 < 2)
    {
      return 1;
    }
    p_Var1 = p_Var1 + 1;
  } while (iVar2 < 0x28);
  return 0;
}

void LOAD_PlayXA(int number)

{
  _LoadQueueEntry *p_Var1;

  p_Var1 = STREAM_AddQueueEntryToTail();
  p_Var1->status = 8;
  (p_Var1->loadEntry).fileHash = number;
  *(u_char *)(p_Var1->loadEntry).fileName = 0x63696f76;
  *(undefined2 *)((p_Var1->loadEntry).fileName + 4) = 0x65;
  return;
}

long *LOAD_ReadFileFromCD(char *fileName, u_char memType)

{
  int iVar1;
  long *local_10[2];

  STREAM_QueueNonblockingLoads(fileName, memType, (void *)0x0, (void *)0x0, (void *)0x0, local_10, 0);
  do
  {
    iVar1 = STREAM_PollLoadQueue();
  } while (iVar1 != 0);
  return local_10[0];
}

void LOAD_ReadDirectory(char *name)

{
  _LoadQueueEntry *p_Var1;

  p_Var1 = STREAM_AddQueueEntryToTail();
  gCurDir = LOAD_HashUnit(name);
  (p_Var1->loadEntry).dirHash = gCurDir;
  (p_Var1->loadEntry).fileHash = 0;
  p_Var1->status = 10;
  sprintf((p_Var1->loadEntry).fileName, "dir %s");
  return;
}

void LOAD_AbortFileLoad(char *fileName, void *retFunc)

{
  _LoadQueueEntry *prev;
  _LoadQueueEntry *entry;
  long lVar1;

  if (loadHead != (_LoadQueueEntry *)0x0)
  {
    lVar1 = LOAD_HashName(fileName);
    prev = (_LoadQueueEntry *)0x0;
    entry = loadHead;
    while (entry != (_LoadQueueEntry *)0x0)
    {
      if ((entry->loadEntry).fileHash == lVar1)
      {
        if (prev == (_LoadQueueEntry *)0x0)
        {
          LOAD_StopLoad();
        }
        if (entry->status == 6)
        {
          LOAD_CleanUpBuffers();
        }
        (*(code *)retFunc)((entry->loadEntry).loadAddr, (entry->loadEntry).retData,
                           (entry->loadEntry).retData2);
        STREAM_RemoveQueueHead(entry, prev);
        return;
      }
      prev = entry;
      entry = entry->next;
    }
  }
  return;
}
