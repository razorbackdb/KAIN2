#include "THISDUST.H"
#include "STRMLOAD.H"

// int @0x800CF4E8, len = 0x00000004
gCurDir = 0x0;
// int @0x800CF4E4, len = 0x00000004
loadCanFail = 0x0;
// _LoadQueueEntry * @0x800D2724, len = 0x00000004
loadFree = null;
// int @0x800CF4E0, len = 0x00000004
loadFromHead = 0x0;
// _LoadQueueEntry * @0x800D2728, len = 0x00000004
loadHead = null;
// _LoadQueueEntry @0x800D1D24, len = 0x00000040
LoadQueue =
    {
        // _LoadQueueEntry * @0x800D1D24, len = 0x00000004
        .next = null,
        // short @0x800D1D28, len = 0x00000002
        .status = null,
        // char @0x800D1D2A, len = 0x00000001
        .relocateBinary = 0x00,
        // char @0x800D1D2B, len = 0x00000001
        .mempackUsed = 0x00,
        // _NonBlockLoadEntry @0x800D1D2C, len = 0x00000038
        .loadEntry =
            {
                // long @0x800D1D2C, len = 0x00000004
                .fileHash = null,
                // long @0x800D1D30, len = 0x00000004
                .dirHash = null,
                // long @0x800D1D34, len = 0x00000004
                .filePos = null,
                // long * @0x800D1D38, len = 0x00000004
                .loadAddr = null,
                // long @0x800D1D3C, len = 0x00000004
                .loadSize = null,
                // long @0x800D1D40, len = 0x00000004
                .checksum = null,
                // long @0x800D1D44, len = 0x00000004
                .checksumType = null,
                // long @0x800D1D48, len = 0x00000004
                .memType = null,
                // long @0x800D1D4C, len = 0x00000004
                .posInFile = null,
                // long @0x800D1D50, len = 0x00000004
                .mallocFailOk = null,
                // void * @0x800D1D54, len = 0x00000004
                .retFunc = null,
                // void * @0x800D1D58, len = 0x00000004
                .retData = null,
                // void * @0x800D1D5C, len = 0x00000004
                .retData2 = null,
                // void * * @0x800D1D60, len = 0x00000004
                .retPointer = null}};
// _LoadQueueEntry * @0x800D272C, len = 0x00000004
loadTail = null;
// int @0x800D2730, len = 0x00000004
numLoads = null;
// decompiled code
// original method signature:
// void /*$ra*/ STREAM_NextLoadFromHead()
// line 37, offset 0x8005fae8
/* begin block 1 */
// Start line: 74
/* end block 1 */
// End Line: 75

/* begin block 2 */
// Start line: 75
/* end block 2 */
// End Line: 76

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_NextLoadFromHead(void)

{
  loadFromHead = 1;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ STREAM_NextLoadCanFail()
// line 42, offset 0x8005faf8
/* begin block 1 */
// Start line: 84
/* end block 1 */
// End Line: 85

/* begin block 2 */
// Start line: 85
/* end block 2 */
// End Line: 86

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_NextLoadCanFail(void)

{
  loadCanFail = 1;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ STREAM_NextLoadAsNormal()
// line 47, offset 0x8005fb08
/* begin block 1 */
// Start line: 94
/* end block 1 */
// End Line: 95

/* begin block 2 */
// Start line: 95
/* end block 2 */
// End Line: 96

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_NextLoadAsNormal(void)

{
  loadFromHead = 0;
  loadCanFail = 0;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ STREAM_InitLoader(char *bigFileName /*$a0*/, char *voiceFileName /*$a1*/)
// line 53, offset 0x8005fb18
/* begin block 1 */
// Start line: 54
// Start offset: 0x8005FB18
// Variables:
// 		int i; // $a1
/* end block 1 */
// End offset: 0x8005FB5C
// End Line: 69

/* begin block 2 */
// Start line: 106
/* end block 2 */
// End Line: 107

void STREAM_InitLoader(char *bigFileName, char *voiceFileName)

{
  _LoadQueueEntry *p_Var1;
  _LoadQueueEntry *p_Var2;
  int iVar3;

  LOAD_InitCdLoader(bigFileName, voiceFileName);
  iVar3 = 0x26;
  p_Var2 = &_LoadQueueEntry_800d26a4;
  p_Var1 = &_LoadQueueEntry_800d26e4;
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
  _LoadQueueEntry_800d26e4.next = (_LoadQueueEntry *)0x0;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ STREAM_RemoveQueueHead()
// line 73, offset 0x8005fb6c
/* begin block 1 */
// Start line: 75
// Start offset: 0x8005FB6C
// Variables:
// 		struct _LoadQueueEntry *entry; // $a0
/* end block 1 */
// End offset: 0x8005FB8C
// End Line: 80

/* begin block 2 */
// Start line: 154
/* end block 2 */
// End Line: 155

/* begin block 3 */
// Start line: 155
/* end block 3 */
// End Line: 156

/* begin block 4 */
// Start line: 156
/* end block 4 */
// End Line: 157

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_RemoveQueueHead(void)

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

// decompiled code
// original method signature:
// void /*$ra*/ STREAM_RemoveQueueEntry(struct _LoadQueueEntry *entry /*$a0*/, struct _LoadQueueEntry *prev /*$a1*/)
// line 85, offset 0x8005fbac
/* begin block 1 */
// Start line: 181
/* end block 1 */
// End Line: 182

/* begin block 2 */
// Start line: 182
/* end block 2 */
// End Line: 183

void STREAM_RemoveQueueEntry(_LoadQueueEntry *entry, _LoadQueueEntry *prev)

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

// decompiled code
// original method signature:
// struct _LoadQueueEntry * /*$ra*/ STREAM_AddQueueEntryToTail()
// line 102, offset 0x8005fc08
/* begin block 1 */
// Start line: 103
// Start offset: 0x8005FC08
// Variables:
// 		struct _LoadQueueEntry *entry; // $s0
/* end block 1 */
// End offset: 0x8005FC50
// End Line: 118

/* begin block 2 */
// Start line: 218
/* end block 2 */
// End Line: 219

/* WARNING: Unknown calling convention yet parameter storage is locked */

_LoadQueueEntry *STREAM_AddQueueEntryToTail(void)

{
  _LoadQueueEntry *p_Var1;

  p_Var1 = loadFree;
  if (loadFree == (_LoadQueueEntry *)0x0)
  {
    DEBUG_FatalError(s_CD_ERROR__too_many_queue_entries_800cf4ec);
  }
  loadFree = p_Var1->next;
  p_Var1->next = (_LoadQueueEntry *)0x0;
  if (loadTail == (_LoadQueueEntry *)0x0)
  {
    loadHead = p_Var1;
  }
  else
  {
    loadTail->next = p_Var1;
  }
  loadTail = p_Var1;
  numLoads = numLoads + 1;
  return p_Var1;
}

// decompiled code
// original method signature:
// struct _LoadQueueEntry * /*$ra*/ STREAM_AddQueueEntryToHead()
// line 123, offset 0x8005fc74
/* begin block 1 */
// Start line: 124
// Start offset: 0x8005FC74
// Variables:
// 		struct _LoadQueueEntry *entry; // $s0
/* end block 1 */
// End offset: 0x8005FD08
// End Line: 148

/* begin block 2 */
// Start line: 268
/* end block 2 */
// End Line: 269

/* WARNING: Unknown calling convention yet parameter storage is locked */

_LoadQueueEntry *STREAM_AddQueueEntryToHead(void)

{
  short sVar1;
  _LoadQueueEntry *p_Var2;
  _LoadQueueEntry *p_Var3;

  p_Var2 = loadFree;
  if (loadFree == (_LoadQueueEntry *)0x0)
  {
    DEBUG_FatalError(s_CD_ERROR__too_many_queue_entries_800cf4ec);
  }
  p_Var3 = loadHead;
  loadFree = p_Var2->next;
  if ((((loadHead == (_LoadQueueEntry *)0x0) || (sVar1 = loadHead->status, sVar1 == 1)) ||
       (sVar1 == 5)) ||
      ((sVar1 == 10 || (sVar1 == 8))))
  {
    loadHead = p_Var2;
    p_Var2->next = p_Var3;
  }
  else
  {
    p_Var2->next = loadHead->next;
    p_Var3->next = p_Var2;
  }
  if (loadTail == (_LoadQueueEntry *)0x0)
  {
    loadTail = p_Var2;
  }
  numLoads = numLoads + 1;
  return p_Var2;
}

// decompiled code
// original method signature:
// int /*$ra*/ STREAM_IsCdBusy(long *numberInQueue /*$a0*/)
// line 157, offset 0x8005fd28
/* begin block 1 */
// Start line: 343
/* end block 1 */
// End Line: 344

/* begin block 2 */
// Start line: 344
/* end block 2 */
// End Line: 345

int STREAM_IsCdBusy(long *numberInQueue)

{
  if (numberInQueue != (long *)0x0)
  {
    *numberInQueue = numLoads;
  }
  return numLoads;
}

// decompiled code
// original method signature:
// int /*$ra*/ STREAM_PollLoadQueue()
// line 174, offset 0x8005fd48
/* begin block 1 */
// Start line: 175
// Start offset: 0x8005FD48

/* begin block 1.1 */
// Start line: 180
// Start offset: 0x8005FD68
// Variables:
// 		struct _LoadQueueEntry *queueEntry; // $s0

/* begin block 1.1.1 */
// Start line: 210
// Start offset: 0x8005FE10
// Variables:
// 		long size; // $v0
/* end block 1.1.1 */
// End offset: 0x8005FE3C
// End Line: 216

/* begin block 1.1.2 */
// Start line: 254
// Start offset: 0x8005FF14
// Variables:
// 		struct _LoadQueueEntry *newQueue; // $v0
/* end block 1.1.2 */
// End offset: 0x8005FF14
// End Line: 254

/* begin block 1.1.3 */
// Start line: 293
// Start offset: 0x8005FFAC
// Variables:
// 		struct _LoadQueueEntry *newQueue; // $v0
/* end block 1.1.3 */
// End offset: 0x8005FFAC
// End Line: 293
/* end block 1.1 */
// End offset: 0x800600B4
// End Line: 409
/* end block 1 */
// End offset: 0x800600B8
// End Line: 412

/* begin block 2 */
// Start line: 377
/* end block 2 */
// End Line: 378

/* WARNING: Unknown calling convention yet parameter storage is locked */

int STREAM_PollLoadQueue(void)

{
  short sVar1;
  _LoadQueueEntry *p_Var2;
  _LoadQueueEntry *p_Var3;
  int voiceIndex;
  long **pplVar4;
  long takeBackSize;
  long *data;

  LOAD_ProcessReadQueue();
  p_Var2 = loadHead;
  if (loadHead == (_LoadQueueEntry *)0x0)
  {
    return numLoads;
  }
  if ((gameTrackerX.gameFlags & 0x800U) != 0)
  {
    sVar1 = loadHead->status;
    if (sVar1 == 1)
    {
      return numLoads;
    }
    if (sVar1 == 5)
    {
      return numLoads;
    }
    if (sVar1 == 8)
    {
      return numLoads;
    }
    if (sVar1 == 10)
    {
      return numLoads;
    }
  }
  switch ((int)(((uint)(ushort)loadHead->status - 1) * 0x10000) >> 0x10)
  {
  case 0:
    LOAD_NonBlockingReadFile(&loadHead->loadEntry);
    voiceIndex = LOAD_ChangeDirectoryFlag();
    if (voiceIndex == 0)
    {
      data = (p_Var2->loadEntry).loadAddr;
      p_Var2->status = 2;
      if (data != (long *)0x0)
      {
        if (p_Var2->mempackUsed != '\0')
        {
          MEMPACK_SetMemoryBeingStreamed((char *)data);
        }
        pplVar4 = (long **)(p_Var2->loadEntry).retPointer;
        if (pplVar4 != (long **)0x0)
        {
          *pplVar4 = (p_Var2->loadEntry).loadAddr;
        }
      }
    }
    else
    {
      p_Var3 = STREAM_AddQueueEntryToHead();
      takeBackSize = (p_Var2->loadEntry).dirHash;
      (p_Var3->loadEntry).fileHash = 0;
      p_Var3->status = 10;
      (p_Var3->loadEntry).dirHash = takeBackSize;
    }
    break;
  case 1:
    voiceIndex = LOAD_IsFileLoading();
    if (voiceIndex != 0)
    {
      return numLoads;
    }
    if ((p_Var2->relocateBinary != '\0') &&
        (data = (p_Var2->loadEntry).loadAddr, data != (long *)0x0))
    {
      takeBackSize = LOAD_RelocBinaryData(data, (p_Var2->loadEntry).loadSize);
      if (p_Var2->mempackUsed != '\0')
      {
        MEMPACK_Return((char *)(p_Var2->loadEntry).loadAddr, takeBackSize);
      }
      p_Var2->relocateBinary = '\0';
    }
    if ((p_Var2->loadEntry).retFunc != (void *)0x0)
    {
      p_Var2->status = 7;
      return numLoads;
    }
    p_Var2->status = 4;
    if ((p_Var2->mempackUsed != '\0') && (data = (p_Var2->loadEntry).loadAddr, data != (long *)0x0))
    {
      MEMPACK_SetMemoryDoneStreamed((char *)data);
    }
    goto LAB_800600ac;
  case 4:
    data = (long *)LOAD_InitBuffers();
    (p_Var2->loadEntry).loadAddr = data;
    if (data == (long *)0x0)
    {
      p_Var2->status = 6;
    }
    else
    {
      LOAD_CD_ReadPartOfFile(&p_Var2->loadEntry);
      voiceIndex = LOAD_ChangeDirectoryFlag();
      if (voiceIndex == 0)
      {
        p_Var2->status = 6;
        (p_Var2->loadEntry).posInFile = 0;
      }
      else
      {
        p_Var3 = STREAM_AddQueueEntryToHead();
        takeBackSize = (p_Var2->loadEntry).dirHash;
        (p_Var3->loadEntry).fileHash = 0;
        p_Var3->status = 10;
        (p_Var3->loadEntry).dirHash = takeBackSize;
        LOAD_CleanUpBuffers();
      }
    }
    break;
  case 5:
    voiceIndex = LOAD_IsFileLoading();
    if (voiceIndex == 0)
    {
      p_Var2->status = 4;
      STREAM_RemoveQueueHead();
      LOAD_CleanUpBuffers();
      if ((code *)(p_Var2->loadEntry).retFunc == VRAM_TransferBufferToVram)
      {
        VRAM_LoadReturn((p_Var2->loadEntry).loadAddr, (p_Var2->loadEntry).retData,
                        (p_Var2->loadEntry).retData2);
      }
    }
    break;
  case 6:
    loadHead->status = 4;
    STREAM_RemoveQueueHead();
    if ((p_Var2->mempackUsed != '\0') && (data = (p_Var2->loadEntry).loadAddr, data != (long *)0x0))
    {
      MEMPACK_SetMemoryDoneStreamed((char *)data);
    }
    if ((p_Var2->loadEntry).retFunc != (void *)0x0)
    {
      STREAM_NextLoadFromHead();
      (*(code *)(p_Var2->loadEntry).retFunc)((p_Var2->loadEntry).loadAddr, (p_Var2->loadEntry).retData,
                                             (p_Var2->loadEntry).retData2);
      STREAM_NextLoadAsNormal();
    }
    break;
  case 7:
    voiceIndex = (loadHead->loadEntry).fileHash;
    loadHead->status = 9;
    VOICEXA_Play(voiceIndex, 0);
    break;
  case 8:
    voiceIndex = VOICEXA_IsPlayingOrPaused();
    if (voiceIndex != 0)
    {
      return numLoads;
    }
    LOAD_InitCdStreamMode();
    goto LAB_800600ac;
  case 9:
    voiceIndex = LOAD_ChangeDirectoryByID((loadHead->loadEntry).dirHash);
    if (voiceIndex == 0)
    {
      DEBUG_FatalError(s_Could_not_read_directory_hash__d_800cf510);
    }
    p_Var2->status = 0xb;
    break;
  case 10:
    voiceIndex = LOAD_IsFileLoading();
    if (voiceIndex != 0)
    {
      return numLoads;
    }
  LAB_800600ac:
    STREAM_RemoveQueueHead();
  }
  return numLoads;
}

// decompiled code
// original method signature:
// struct _LoadQueueEntry * /*$ra*/ STREAM_SetUpQueueEntry(char *fileName /*$s2*/, void *retFunc /*$s3*/, void *retData /*$s4*/, void *retData2 /*$s5*/, void **retPointer /*stack 16*/, int fromhead /*stack 20*/)
// line 414, offset 0x800600c8
/* begin block 1 */
// Start line: 415
// Start offset: 0x800600C8
// Variables:
// 		struct _LoadQueueEntry *currentEntry; // $s0
/* end block 1 */
// End offset: 0x8006018C
// End Line: 448

/* begin block 2 */
// Start line: 865
/* end block 2 */
// End Line: 866

_LoadQueueEntry *
STREAM_SetUpQueueEntry(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer, int fromhead)

{
  _LoadQueueEntry *p_Var1;
  long lVar2;

  if (fromhead == 0)
  {
    p_Var1 = STREAM_AddQueueEntryToTail();
  }
  else
  {
    p_Var1 = STREAM_AddQueueEntryToHead();
  }
  lVar2 = LOAD_HashName(fileName);
  (p_Var1->loadEntry).fileHash = lVar2;
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

// decompiled code
// original method signature:
// void /*$ra*/ STREAM_QueueNonblockingLoads(char *fileName /*$a0*/, unsigned char memType /*$s0*/, void *retFunc /*$a2*/, void *retData /*$a3*/, void *retData2 /*stack 16*/, void **retPointer /*stack 20*/, long relocateBinary /*stack 24*/)
// line 452, offset 0x800601b4
/* begin block 1 */
// Start line: 453
// Start offset: 0x800601B4
// Variables:
// 		struct _LoadQueueEntry *currentEntry; // $v1
// 		int fromhead; // $v0
/* end block 1 */
// End offset: 0x8006022C
// End Line: 472

/* begin block 2 */
// Start line: 943
/* end block 2 */
// End Line: 944

void STREAM_QueueNonblockingLoads(char *fileName, uchar memType, void *retFunc, void *retData, void *retData2,
                                  void **retPointer, long relocateBinary)

{
  int fromhead;
  short sVar1;
  _LoadQueueEntry *p_Var2;

  fromhead = loadFromHead;
  loadFromHead = 0;
  p_Var2 = STREAM_SetUpQueueEntry(fileName, retFunc, retData, retData2, retPointer, fromhead);
  p_Var2->mempackUsed = '\x01';
  fromhead = loadCanFail;
  (p_Var2->loadEntry).loadAddr = (long *)0x0;
  (p_Var2->loadEntry).memType = (uint)memType;
  loadCanFail = 0;
  p_Var2->relocateBinary = (char)relocateBinary;
  (p_Var2->loadEntry).mallocFailOk = fromhead;
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

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_LoadToAddress(char *fileName /*$a0*/, void *loadAddr /*$s0*/, long relocateBinary /*$s1*/)
// line 475, offset 0x80060240
/* begin block 1 */
// Start line: 476
// Start offset: 0x80060240
// Variables:
// 		struct _LoadQueueEntry *currentEntry; // $v0
/* end block 1 */
// End offset: 0x80060294
// End Line: 485

/* begin block 2 */
// Start line: 1011
/* end block 2 */
// End Line: 1012

void LOAD_LoadToAddress(char *fileName, void *loadAddr, long relocateBinary)

{
  _LoadQueueEntry *p_Var1;
  int iVar2;

  p_Var1 = STREAM_SetUpQueueEntry(fileName, (void *)0x0, (void *)0x0, (void *)0x0, (void **)0x0, 0);
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

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_NonBlockingBinaryLoad(char *fileName /*$a0*/, void *retFunc /*$t0*/, void *retData /*$t1*/, void *retData2 /*$a3*/, void **retPointer /*stack 16*/, int memType /*stack 20*/)
// line 498, offset 0x800602a8
/* begin block 1 */
// Start line: 1060
/* end block 1 */
// End Line: 1061

void LOAD_NonBlockingBinaryLoad(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer,
                                int memType)

{
  STREAM_QueueNonblockingLoads(fileName, (uchar)memType, retFunc, retData, retData2, retPointer, 1);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_NonBlockingFileLoad(char *fileName /*$a0*/, void *retFunc /*$v1*/, void *retData /*$t0*/, void *retData2 /*$a3*/, void **retPointer /*stack 16*/, int memType /*stack 20*/)
// line 505, offset 0x800602ec
/* begin block 1 */
// Start line: 1078
/* end block 1 */
// End Line: 1079

void LOAD_NonBlockingFileLoad(char *fileName, void *retFunc, void *retData, void *retData2, void **retPointer,
                              int memType)

{
  STREAM_QueueNonblockingLoads(fileName, (uchar)memType, retFunc, retData, retData2, retPointer, 0);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_NonBlockingBufferedLoad(char *fileName /*$a0*/, void *retFunc /*$v0*/, void *retData /*$v1*/, void *retData2 /*$a3*/)
// line 511, offset 0x8006032c
/* begin block 1 */
// Start line: 1092
/* end block 1 */
// End Line: 1093

void LOAD_NonBlockingBufferedLoad(char *fileName, void *retFunc, void *retData, void *retData2)

{
  STREAM_QueueNonblockingLoads(fileName, '\0', retFunc, retData, retData2, (void **)0x0, 0);
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ LOAD_IsXAInQueue()
// line 516, offset 0x80060368
/* begin block 1 */
// Start line: 518
// Start offset: 0x80060368
// Variables:
// 		struct _LoadQueueEntry *entry; // $v1
/* end block 1 */
// End offset: 0x800603A0
// End Line: 527

/* begin block 2 */
// Start line: 1103
/* end block 2 */
// End Line: 1104

/* begin block 3 */
// Start line: 1104
/* end block 3 */
// End Line: 1105

/* begin block 4 */
// Start line: 1106
/* end block 4 */
// End Line: 1107

/* WARNING: Unknown calling convention yet parameter storage is locked */

int LOAD_IsXAInQueue(void)

{
  _LoadQueueEntry *p_Var1;

  p_Var1 = loadHead;
  if (loadHead != (_LoadQueueEntry *)0x0)
  {
    do
    {
      if ((uint)(ushort)p_Var1->status - 8 < 2)
      {
        return 1;
      }
      p_Var1 = p_Var1->next;
    } while (p_Var1 != (_LoadQueueEntry *)0x0);
  }
  return 0;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_PlayXA(int number /*$s0*/)
// line 529, offset 0x800603b0
/* begin block 1 */
// Start line: 530
// Start offset: 0x800603B0
// Variables:
// 		struct _LoadQueueEntry *currentEntry; // $v0
/* end block 1 */
// End offset: 0x800603B0
// End Line: 530

/* begin block 2 */
// Start line: 1131
/* end block 2 */
// End Line: 1132

void LOAD_PlayXA(int number)

{
  _LoadQueueEntry *p_Var1;

  p_Var1 = STREAM_AddQueueEntryToTail();
  (p_Var1->loadEntry).fileHash = number;
  p_Var1->status = 8;
  return;
}

// decompiled code
// original method signature:
// long * /*$ra*/ LOAD_ReadFile(char *fileName /*$a0*/, unsigned char memType /*$a1*/)
// line 542, offset 0x800603e0
/* begin block 1 */
// Start line: 543
// Start offset: 0x800603E0
// Variables:
// 		void *loadAddr; // stack offset -16
/* end block 1 */
// End offset: 0x80060418
// End Line: 550

/* begin block 2 */
// Start line: 1158
/* end block 2 */
// End Line: 1159

long *LOAD_ReadFile(char *fileName, uchar memType)

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

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_ChangeDirectory(char *name /*$s1*/)
// line 553, offset 0x8006042c
/* begin block 1 */
// Start line: 554
// Start offset: 0x8006042C
// Variables:
// 		struct _LoadQueueEntry *currentEntry; // $s0
/* end block 1 */
// End offset: 0x8006042C
// End Line: 554

/* begin block 2 */
// Start line: 1183
/* end block 2 */
// End Line: 1184

void LOAD_ChangeDirectory(char *name)

{
  _LoadQueueEntry *p_Var1;

  p_Var1 = STREAM_AddQueueEntryToTail();
  gCurDir = LOAD_HashUnit(name);
  (p_Var1->loadEntry).dirHash = gCurDir;
  (p_Var1->loadEntry).fileHash = 0;
  p_Var1->status = 10;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_AbortDirectoryChange(char *name /*$a0*/)
// line 569, offset 0x80060478
/* begin block 1 */
// Start line: 570
// Start offset: 0x80060478

/* begin block 1.1 */
// Start line: 574
// Start offset: 0x80060488
// Variables:
// 		struct _LoadQueueEntry *entry; // $a0
// 		struct _LoadQueueEntry *prev; // $a1
// 		long hash; // $v1
/* end block 1.1 */
// End offset: 0x800604F0
// End Line: 589
/* end block 1 */
// End offset: 0x800604F0
// End Line: 591

/* begin block 2 */
// Start line: 1216
/* end block 2 */
// End Line: 1217

/* begin block 3 */
// Start line: 1218
/* end block 3 */
// End Line: 1219

void LOAD_AbortDirectoryChange(char *name)

{
  _LoadQueueEntry *entry;
  _LoadQueueEntry *prev;
  _LoadQueueEntry *p_Var1;
  long lVar2;

  if (loadHead != (_LoadQueueEntry *)0x0)
  {
    lVar2 = LOAD_HashUnit(name);
    p_Var1 = loadHead->next;
    prev = loadHead;
    while (entry = p_Var1, entry != (_LoadQueueEntry *)0x0)
    {
      if ((entry->status == 10) && ((entry->loadEntry).dirHash == lVar2))
      {
        STREAM_RemoveQueueEntry(entry, prev);
        return;
      }
      p_Var1 = entry->next;
      prev = entry;
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_AbortFileLoad(char *fileName /*$a0*/, void *retFunc /*$s3*/)
// line 593, offset 0x80060500
/* begin block 1 */
// Start line: 594
// Start offset: 0x80060500

/* begin block 1.1 */
// Start line: 597
// Start offset: 0x80060524
// Variables:
// 		struct _LoadQueueEntry *entry; // $s0
// 		struct _LoadQueueEntry *prev; // $s1
// 		long hash; // $v1
/* end block 1.1 */
// End offset: 0x800605B4
// End Line: 623
/* end block 1 */
// End offset: 0x800605B4
// End Line: 624

/* begin block 2 */
// Start line: 1276
/* end block 2 */
// End Line: 1277

/* begin block 3 */
// Start line: 1277
/* end block 3 */
// End Line: 1278

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
        STREAM_RemoveQueueEntry(entry, prev);
        return;
      }
      prev = entry;
      entry = entry->next;
    }
  }
  return;
}
