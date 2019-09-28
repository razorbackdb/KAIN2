#include "THISDUST.H"
#include "STRMLOAD.H"

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

void STREAM_NextLoadCanFail(void)

{
  uGpffff9a30 = 1;
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
  _TFace *p_Var1;
  _TFace **pp_Var2;
  int iVar3;

  LOAD_InitCdLoader(bigFileName, voiceFileName);
  iVar3 = 0x26;
  pp_Var2 = &theCamera.data.Follow.oldTFace;
  p_Var1 = (_TFace *)0x800d26e4;
  shadow_vertices._0_4_ = &LoadQueue;
  shadow_vertices._4_4_ = 0;
  loadTail._0_4_ = 0;
  loadTail._4_4_ = 0;
  do
  {
    *pp_Var2 = p_Var1;
    pp_Var2 = pp_Var2 + -0x10;
    iVar3 = iVar3 + -1;
    p_Var1 = (_TFace *)&p_Var1[-6].normal;
  } while (-1 < iVar3);
  theCamera._1212_4_ = 0;
  /* WARNING: Read-only address (ram,0x800d26e4) is written */
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
  int iVar1;
  int iVar2;

  iVar1 = (int)shadow_vertices._0_4_;
  if (*shadow_vertices._4_4_ == 0)
  {
    loadTail._0_4_ = 0;
  }
  shadow_vertices._0_4_ = shadow_vertices._4_4_;
  iVar2 = *shadow_vertices._4_4_;
  *shadow_vertices._4_4_ = iVar1;
  shadow_vertices._4_4_ = (int *)iVar2;
  loadTail._4_4_ = loadTail._4_4_ + -1;
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

  if (loadTail._0_4_ == entry)
  {
    loadTail._0_4_ = prev;
  }
  if (prev == (_LoadQueueEntry *)0x0)
  {
    shadow_vertices._4_4_ = entry->next;
  }
  else
  {
    prev->next = entry->next;
  }
  p_Var1 = entry;
  entry->next = shadow_vertices._0_4_;
  shadow_vertices._0_4_ = p_Var1;
  loadTail._4_4_ = loadTail._4_4_ + -1;
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
  _LoadQueueEntry *p_Var2;

  p_Var1 = shadow_vertices._0_4_;
  if (shadow_vertices._0_4_ == (_LoadQueueEntry *)0x0)
  {
    /* WARNING: Subroutine does not return */
    DEBUG_FatalError(_spu_AllocBlockNum);
  }
  p_Var2 = (shadow_vertices._0_4_)->next;
  (shadow_vertices._0_4_)->next = (_LoadQueueEntry *)0x0;
  if (loadTail._0_4_ == (_LoadQueueEntry *)0x0)
  {
    shadow_vertices._4_4_ = shadow_vertices._0_4_;
    shadow_vertices._0_4_ = p_Var2;
  }
  else
  {
    *(_LoadQueueEntry **)loadTail._0_4_ = shadow_vertices._0_4_;
    shadow_vertices._0_4_ = p_Var2;
  }
  loadTail._0_4_ = p_Var1;
  loadTail._4_4_ = loadTail._4_4_ + 1;
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
  _LoadQueueEntry **pp_Var2;
  _LoadQueueEntry *p_Var3;
  _LoadQueueEntry *p_Var4;

  p_Var4 = shadow_vertices._4_4_;
  p_Var3 = shadow_vertices._0_4_;
  if (shadow_vertices._0_4_ == (_LoadQueueEntry *)0x0)
  {
    /* WARNING: Subroutine does not return */
    DEBUG_FatalError(_spu_AllocBlockNum);
  }
  if ((((shadow_vertices._4_4_ == (_LoadQueueEntry *)0x0) ||
        (sVar1 = (shadow_vertices._4_4_)->status, sVar1 == 1)) ||
       (sVar1 == 5)) ||
      ((sVar1 == 10 || (sVar1 == 8))))
  {
    shadow_vertices._4_4_ = shadow_vertices._0_4_;
    pp_Var2 = &(shadow_vertices._0_4_)->next;
    shadow_vertices._0_4_ = (shadow_vertices._0_4_)->next;
    *pp_Var2 = p_Var4;
  }
  else
  {
    pp_Var2 = &(shadow_vertices._0_4_)->next;
    shadow_vertices._0_4_ = (shadow_vertices._0_4_)->next;
    *pp_Var2 = (shadow_vertices._4_4_)->next;
    p_Var4->next = p_Var3;
  }
  if (loadTail._0_4_ == (_LoadQueueEntry *)0x0)
  {
    loadTail._0_4_ = p_Var3;
  }
  loadTail._4_4_ = loadTail._4_4_ + 1;
  return p_Var3;
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
    *numberInQueue = loadTail._4_4_;
  }
  return loadTail._4_4_;
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
  int *piVar1;
  short sVar2;
  void *pvVar3;
  _LoadQueueEntry *p_Var4;
  int iVar5;
  int iVar6;
  long takeBackSize;

  LOAD_ProcessReadQueue();
  iVar6 = shadow_vertices._4_4_;
  if (shadow_vertices._4_4_ == 0)
  {
    return loadTail._4_4_;
  }
  if ((DAT_800d10ec & 0x800) != 0)
  {
    sVar2 = *(short *)(shadow_vertices._4_4_ + 4);
    if (sVar2 == 1)
    {
      return loadTail._4_4_;
    }
    if (sVar2 == 5)
    {
      return loadTail._4_4_;
    }
    if (sVar2 == 8)
    {
      return loadTail._4_4_;
    }
    if (sVar2 == 10)
    {
      return loadTail._4_4_;
    }
  }
  switch ((int)(((uint) * (ushort *)(shadow_vertices._4_4_ + 4) - 1) * 0x10000) >> 0x10)
  {
  case 0:
    LOAD_NonBlockingReadFile((_NonBlockLoadEntry *)(shadow_vertices._4_4_ + 8));
    iVar5 = LOAD_ChangeDirectoryFlag();
    if (iVar5 == 0)
    {
      *(undefined2 *)(iVar6 + 4) = 2;
      if (*(char **)(iVar6 + 0x14) != (char *)0x0)
      {
        if (*(char *)(iVar6 + 7) != '\0')
        {
          MEMPACK_SetMemoryBeingStreamed(*(char **)(iVar6 + 0x14));
        }
        if (*(undefined4 **)(iVar6 + 0x3c) != (undefined4 *)0x0)
        {
          **(undefined4 **)(iVar6 + 0x3c) = *(undefined4 *)(iVar6 + 0x14);
        }
      }
    }
    else
    {
      p_Var4 = STREAM_AddQueueEntryToHead();
      takeBackSize = *(long *)(iVar6 + 0xc);
      (p_Var4->loadEntry).fileHash = 0;
      p_Var4->status = 10;
      (p_Var4->loadEntry).dirHash = takeBackSize;
    }
    break;
  case 1:
    iVar5 = LOAD_IsFileLoading();
    if (iVar5 != 0)
    {
      return loadTail._4_4_;
    }
    if ((*(char *)(iVar6 + 6) != '\0') && (*(long **)(iVar6 + 0x14) != (long *)0x0))
    {
      takeBackSize = LOAD_RelocBinaryData(*(long **)(iVar6 + 0x14), *(long *)(iVar6 + 0x18));
      if (*(char *)(iVar6 + 7) != '\0')
      {
        MEMPACK_Return(*(char **)(iVar6 + 0x14), takeBackSize);
      }
      *(undefined *)(iVar6 + 6) = 0;
    }
    if (*(int *)(iVar6 + 0x30) != 0)
    {
      *(undefined2 *)(iVar6 + 4) = 7;
      return loadTail._4_4_;
    }
    *(undefined2 *)(iVar6 + 4) = 4;
    if ((*(char *)(iVar6 + 7) != '\0') && (*(char **)(iVar6 + 0x14) != (char *)0x0))
    {
      MEMPACK_SetMemoryDoneStreamed(*(char **)(iVar6 + 0x14));
    }
    goto LAB_800600ac;
  case 4:
    pvVar3 = LOAD_InitBuffers();
    *(void **)(iVar6 + 0x14) = pvVar3;
    if (pvVar3 == (void *)0x0)
    {
      *(undefined2 *)(iVar6 + 4) = 6;
    }
    else
    {
      LOAD_CD_ReadPartOfFile((_NonBlockLoadEntry *)(iVar6 + 8));
      iVar5 = LOAD_ChangeDirectoryFlag();
      if (iVar5 == 0)
      {
        *(undefined2 *)(iVar6 + 4) = 6;
        *(undefined4 *)(iVar6 + 0x28) = 0;
      }
      else
      {
        p_Var4 = STREAM_AddQueueEntryToHead();
        takeBackSize = *(long *)(iVar6 + 0xc);
        (p_Var4->loadEntry).fileHash = 0;
        p_Var4->status = 10;
        (p_Var4->loadEntry).dirHash = takeBackSize;
        LOAD_CleanUpBuffers();
      }
    }
    break;
  case 5:
    iVar5 = LOAD_IsFileLoading();
    if (iVar5 == 0)
    {
      *(undefined2 *)(iVar6 + 4) = 4;
      STREAM_RemoveQueueHead();
      LOAD_CleanUpBuffers();
      if (*(code **)(iVar6 + 0x30) == VRAM_TransferBufferToVram)
      {
        VRAM_LoadReturn(*(void **)(iVar6 + 0x14), *(void **)(iVar6 + 0x34), *(void **)(iVar6 + 0x38));
      }
    }
    break;
  case 6:
    *(undefined2 *)(shadow_vertices._4_4_ + 4) = 4;
    STREAM_RemoveQueueHead();
    if ((*(char *)(iVar6 + 7) != '\0') && (*(char **)(iVar6 + 0x14) != (char *)0x0))
    {
      MEMPACK_SetMemoryDoneStreamed(*(char **)(iVar6 + 0x14));
    }
    if (*(int *)(iVar6 + 0x30) != 0)
    {
      STREAM_NextLoadFromHead();
      (**(code **)(iVar6 + 0x30))(*(undefined4 *)(iVar6 + 0x14), *(undefined4 *)(iVar6 + 0x34),
                                  *(undefined4 *)(iVar6 + 0x38));
      STREAM_NextLoadAsNormal();
    }
    break;
  case 7:
    piVar1 = (int *)(shadow_vertices._4_4_ + 8);
    *(undefined2 *)(shadow_vertices._4_4_ + 4) = 9;
    VOICEXA_Play(*piVar1, 0);
    break;
  case 8:
    iVar6 = VOICEXA_IsPlayingOrPaused();
    if (iVar6 != 0)
    {
      return loadTail._4_4_;
    }
    LOAD_InitCdStreamMode();
    goto LAB_800600ac;
  case 9:
    iVar5 = LOAD_ChangeDirectoryByID(*(int *)(shadow_vertices._4_4_ + 0xc));
    if (iVar5 == 0)
    {
      /* WARNING: Subroutine does not return */
      DEBUG_FatalError(s_Could_not_read_directory_hash__d_800cf510);
    }
    *(undefined2 *)(iVar6 + 4) = 0xb;
    break;
  case 10:
    iVar6 = LOAD_IsFileLoading();
    if (iVar6 != 0)
    {
      return loadTail._4_4_;
    }
  LAB_800600ac:
    STREAM_RemoveQueueHead();
  }
  return loadTail._4_4_;
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
  if (lVar2 != 0)
  {
    lVar2 = LOAD_GetSearchDirectory();
    (p_Var1->loadEntry).dirHash = lVar2;
    /* WARNING: Subroutine does not return */
    LOAD_SetSearchDirectory(0);
  }
  (p_Var1->loadEntry).dirHash = gCurDir;
  (p_Var1->loadEntry).retFunc = retFunc;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int STREAM_IsCdBusy(long *numberInQueue)

{
  long lVar1;
  _LoadQueueEntry *p_Var2;
  int fromhead;
  uint in_a1;
  void *in_a2;
  void *in_a3;
  void *in_stack_00000010;
  void **in_stack_00000014;
  char in_stack_00000018;

  fromhead = DAT_800d0fc4;
  DAT_800d0fc4 = 0;
  p_Var2 = STREAM_SetUpQueueEntry((char *)numberInQueue, in_a2, in_a3, in_stack_00000010, in_stack_00000014, fromhead);
  p_Var2->mempackUsed = '\x01';
  lVar1 = _DAT_800d0fc8;
  (p_Var2->loadEntry).loadAddr = (long *)0x0;
  (p_Var2->loadEntry).memType = in_a1 & 0xff;
  _DAT_800d0fc8 = 0;
  p_Var2->relocateBinary = in_stack_00000018;
  (p_Var2->loadEntry).mallocFailOk = lVar1;
  if ((in_a1 & 0xff) == 0)
  {
    fromhead = 5;
  }
  else
  {
    fromhead = 1;
  }
  p_Var2->status = (short)fromhead;
  return fromhead;
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

void LOAD_NonBlockingBinaryLoad(long *param_1)

{
  STREAM_IsCdBusy(param_1);
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
  STREAM_IsCdBusy((long *)fileName);
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
  STREAM_IsCdBusy((long *)fileName);
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
  int *piVar1;

  piVar1 = shadow_vertices._4_4_;
  if (shadow_vertices._4_4_ != (int *)0x0)
  {
    do
    {
      if ((uint) * (ushort *)(piVar1 + 1) - 8 < 2)
      {
        return 1;
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
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
  long *local_10;

  STREAM_IsCdBusy((long *)fileName);
  do
  {
    iVar1 = STREAM_PollLoadQueue();
  } while (iVar1 != 0);
  return local_10;
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

  if (shadow_vertices._4_4_ != (_LoadQueueEntry *)0x0)
  {
    lVar2 = LOAD_HashUnit(name);
    p_Var1 = (shadow_vertices._4_4_)->next;
    prev = shadow_vertices._4_4_;
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

  if (shadow_vertices._4_4_ != (_LoadQueueEntry *)0x0)
  {
    lVar1 = LOAD_HashName(fileName);
    prev = (_LoadQueueEntry *)0x0;
    entry = shadow_vertices._4_4_;
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
