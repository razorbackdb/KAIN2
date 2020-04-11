
#include "STRMLOAD.H"


// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_NextLoadFromHead()
 // line 36, offset 0x80060198
	/* begin block 1 */
		// Start line: 72
	/* end block 1 */
	// End Line: 73

	/* begin block 2 */
		// Start line: 73
	/* end block 2 */
	// End Line: 74

/* File: C:\kain2\game\STRMLOAD.C */

void STREAM_NextLoadFromHead(void)

{
  loadBufferedFromHead = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_InitLoader(char *bigFileName /*$a0*/, char *voiceFileName /*$a1*/)
 // line 41, offset 0x800601a8
	/* begin block 1 */
		// Start line: 42
		// Start offset: 0x800601A8
		// Variables:
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x800601F0
	// End Line: 57

	/* begin block 2 */
		// Start line: 82
	/* end block 2 */
	// End Line: 83

/* File: C:\kain2\game\STRMLOAD.C */

void STREAM_InitLoader(char *bigFileName,char *voiceFileName)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  LOAD_InitCdLoader(bigFileName,voiceFileName);
  iVar3 = 0x26;
  puVar2 = &DAT_800da5a0;
  puVar1 = &DAT_800da610;
  loadFree = &LoadQueue;
  loadHead = 0;
  loadTail = 0;
  numLoads = 0;
  do {
    *(undefined4 **)puVar2 = puVar1;
    puVar2 = puVar2 + -0x1c;
    iVar3 = iVar3 + -1;
    puVar1 = puVar1 + -0x1c;
  } while (-1 < iVar3);
  DAT_800da610 = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_RemoveQueueHead()
 // line 61, offset 0x80060204
	/* begin block 1 */
		// Start line: 63
		// Start offset: 0x80060204
		// Variables:
	// 		struct _LoadQueueEntry *entry; // $a0
	/* end block 1 */
	// End offset: 0x80060224
	// End Line: 68

	/* begin block 2 */
		// Start line: 135
	/* end block 2 */
	// End Line: 136

	/* begin block 3 */
		// Start line: 136
	/* end block 3 */
	// End Line: 137

	/* begin block 4 */
		// Start line: 137
	/* end block 4 */
	// End Line: 138

/* File: C:\kain2\game\STRMLOAD.C */

void STREAM_RemoveQueueHead(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (int)loadFree;
  if (*loadHead == 0) {
    loadTail = 0;
  }
  loadFree = loadHead;
  iVar2 = *loadHead;
  *loadHead = iVar1;
  loadHead = (int *)iVar2;
  numLoads = numLoads + -1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_RemoveQueueEntry(struct _LoadQueueEntry *entry /*$a0*/, struct _LoadQueueEntry *prev /*$a1*/)
 // line 73, offset 0x80060244
	/* begin block 1 */
		// Start line: 162
	/* end block 1 */
	// End Line: 163

	/* begin block 2 */
		// Start line: 163
	/* end block 2 */
	// End Line: 164

/* File: C:\kain2\game\STRMLOAD.C */

void STREAM_RemoveQueueEntry(_LoadQueueEntry *entry,_LoadQueueEntry *prev)

{
  _LoadQueueEntry *p_Var1;
  
  if (loadTail == entry) {
    loadTail = prev;
  }
  if (prev == (_LoadQueueEntry *)0x0) {
    loadHead = entry->next;
  }
  else {
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
 // line 90, offset 0x800602a0
	/* begin block 1 */
		// Start line: 92
		// Start offset: 0x800602A0
		// Variables:
	// 		struct _LoadQueueEntry *entry; // $v1
	/* end block 1 */
	// End offset: 0x800602C8
	// End Line: 104

	/* begin block 2 */
		// Start line: 199
	/* end block 2 */
	// End Line: 200

	/* begin block 3 */
		// Start line: 200
	/* end block 3 */
	// End Line: 201

	/* begin block 4 */
		// Start line: 201
	/* end block 4 */
	// End Line: 202

/* File: C:\kain2\game\STRMLOAD.C */

_LoadQueueEntry * STREAM_AddQueueEntryToTail(void)

{
  _LoadQueueEntry *p_Var1;
  _LoadQueueEntry *p_Var2;
  
  p_Var1 = loadFree;
  p_Var2 = loadFree->next;
  loadFree->next = (_LoadQueueEntry *)0x0;
  if (loadTail == (_LoadQueueEntry *)0x0) {
    loadHead = loadFree;
    loadFree = p_Var2;
  }
  else {
    *(_LoadQueueEntry **)loadTail = loadFree;
    loadFree = p_Var2;
  }
  loadTail = p_Var1;
  numLoads = numLoads + 1;
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct _LoadQueueEntry * /*$ra*/ STREAM_AddQueueEntryToHead()
 // line 109, offset 0x800602e0
	/* begin block 1 */
		// Start line: 111
		// Start offset: 0x800602E0
		// Variables:
	// 		struct _LoadQueueEntry *entry; // $a0
	/* end block 1 */
	// End offset: 0x80060358
	// End Line: 132

	/* begin block 2 */
		// Start line: 241
	/* end block 2 */
	// End Line: 242

	/* begin block 3 */
		// Start line: 242
	/* end block 3 */
	// End Line: 243

	/* begin block 4 */
		// Start line: 243
	/* end block 4 */
	// End Line: 244

/* File: C:\kain2\game\STRMLOAD.C */

_LoadQueueEntry * STREAM_AddQueueEntryToHead(void)

{
  short sVar1;
  _LoadQueueEntry **pp_Var2;
  _LoadQueueEntry *p_Var3;
  _LoadQueueEntry *p_Var4;
  
  p_Var4 = loadHead;
  p_Var3 = loadFree;
  if ((((loadHead == (_LoadQueueEntry *)0x0) || (sVar1 = loadHead->status, sVar1 == 1)) ||
      (sVar1 == 5)) || ((sVar1 == 10 || (sVar1 == 8)))) {
    loadHead = loadFree;
    pp_Var2 = &loadFree->next;
    loadFree = loadFree->next;
    *pp_Var2 = p_Var4;
  }
  else {
    pp_Var2 = &loadFree->next;
    loadFree = loadFree->next;
    *pp_Var2 = loadHead->next;
    p_Var4->next = p_Var3;
  }
  if (loadTail == (_LoadQueueEntry *)0x0) {
    loadTail = p_Var3;
  }
  numLoads = numLoads + 1;
  return p_Var3;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_IsCdBusy(long *numberInQueue /*$a0*/)
 // line 141, offset 0x80060370
	/* begin block 1 */
		// Start line: 307
	/* end block 1 */
	// End Line: 308

	/* begin block 2 */
		// Start line: 308
	/* end block 2 */
	// End Line: 309

/* File: C:\kain2\game\STRMLOAD.C */

int STREAM_IsCdBusy(long *numberInQueue)

{
  if (numberInQueue != (long *)0x0) {
    *numberInQueue = numLoads;
  }
  return numLoads;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_PollLoadQueue()
 // line 158, offset 0x80060390
	/* begin block 1 */
		// Start line: 159
		// Start offset: 0x80060390

		/* begin block 1.1 */
			// Start line: 164
			// Start offset: 0x800603B4
			// Variables:
		// 		struct _LoadQueueEntry *queueEntry; // $s1

			/* begin block 1.1.1 */
				// Start line: 182
				// Start offset: 0x80060440
				// Variables:
			// 		long size; // $v0
			/* end block 1.1.1 */
			// End offset: 0x80060470
			// End Line: 188

			/* begin block 1.1.2 */
				// Start line: 229
				// Start offset: 0x8006052C
				// Variables:
			// 		struct _LoadQueueEntry *newQueue; // $s0
			/* end block 1.1.2 */
			// End offset: 0x8006052C
			// End Line: 229

			/* begin block 1.1.3 */
				// Start line: 260
				// Start offset: 0x800605C4
				// Variables:
			// 		struct _LoadQueueEntry *newQueue; // $s0
			/* end block 1.1.3 */
			// End offset: 0x800605C4
			// End Line: 260
		/* end block 1.1 */
		// End offset: 0x80060718
		// End Line: 374
	/* end block 1 */
	// End offset: 0x80060718
	// End Line: 376

	/* begin block 2 */
		// Start line: 341
	/* end block 2 */
	// End Line: 342

/* File: C:\kain2\game\STRMLOAD.C */

int STREAM_PollLoadQueue(void)

{
  void *pvVar1;
  _LoadQueueEntry *p_Var2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  long takeBackSize;
  
  LOAD_ProcessReadQueue();
  iVar3 = loadHead;
  if (loadHead == 0) {
    return numLoads;
  }
  if (DAT_800d218c < 0) {
    FONT_Print(s__s_status__d_800d0728);
  }
  switch((int)(((uint)*(ushort *)(iVar3 + 4) - 1) * 0x10000) >> 0x10) {
  case 0:
    uVar5 = TIMER_GetTimeMS();
    *(ulong *)(iVar3 + 0x6c) = uVar5;
    LOAD_NonBlockingReadFile((_NonBlockLoadEntry *)(iVar3 + 8));
    iVar4 = LOAD_ChangeDirectoryFlag();
    if (iVar4 == 0) {
      *(undefined2 *)(iVar3 + 4) = 2;
      if (*(char *)(iVar3 + 7) != '\0') {
        MEMPACK_SetMemoryBeingStreamed(*(char **)(iVar3 + 0x14));
      }
      if (*(undefined4 **)(iVar3 + 0x38) != (undefined4 *)0x0) {
        **(undefined4 **)(iVar3 + 0x38) = *(undefined4 *)(iVar3 + 0x14);
      }
    }
    else {
      p_Var2 = STREAM_AddQueueEntryToHead();
      sprintf((p_Var2->loadEntry).fileName,&LAB_800d0738,*(undefined4 *)(iVar3 + 0xc));
      takeBackSize = *(long *)(iVar3 + 0xc);
      p_Var2->status = 10;
      (p_Var2->loadEntry).dirHash = takeBackSize;
    }
    break;
  case 1:
    iVar4 = LOAD_IsFileLoading();
    if (iVar4 != 0) {
      return numLoads;
    }
    uVar5 = TIMER_GetTimeMS();
    *(int *)(iVar3 + 0x6c) = uVar5 - *(int *)(iVar3 + 0x6c);
    if (*(char *)(iVar3 + 6) != '\0') {
      takeBackSize = LOAD_RelocBinaryData(*(long **)(iVar3 + 0x14),*(long *)(iVar3 + 0x18));
      if (*(char *)(iVar3 + 7) != '\0') {
        MEMPACK_Return(*(char **)(iVar3 + 0x14),takeBackSize);
      }
      *(undefined *)(iVar3 + 6) = 0;
    }
    if (*(int *)(iVar3 + 0x2c) != 0) {
      *(undefined2 *)(iVar3 + 4) = 7;
      return numLoads;
    }
    *(undefined2 *)(iVar3 + 4) = 4;
    if (*(char *)(iVar3 + 7) != '\0') {
      MEMPACK_SetMemoryDoneStreamed(*(char **)(iVar3 + 0x14));
    }
    goto LAB_80060710;
  case 4:
    pvVar1 = LOAD_InitBuffers();
    *(void **)(iVar3 + 0x14) = pvVar1;
    uVar5 = TIMER_GetTimeMS();
    *(ulong *)(iVar3 + 0x6c) = uVar5;
    LOAD_CD_ReadPartOfFile((_NonBlockLoadEntry *)(iVar3 + 8));
    iVar4 = LOAD_ChangeDirectoryFlag();
    if (iVar4 == 0) {
      *(undefined2 *)(iVar3 + 4) = 6;
      *(undefined4 *)(iVar3 + 0x28) = 0;
    }
    else {
      p_Var2 = STREAM_AddQueueEntryToHead();
      sprintf((p_Var2->loadEntry).fileName,&LAB_800d0738,*(undefined4 *)(iVar3 + 0xc));
      takeBackSize = *(long *)(iVar3 + 0xc);
      p_Var2->status = 10;
      (p_Var2->loadEntry).dirHash = takeBackSize;
      LOAD_CleanUpBuffers();
    }
    break;
  case 5:
    iVar4 = LOAD_IsFileLoading();
    if (iVar4 == 0) {
      uVar5 = TIMER_GetTimeMS();
      *(undefined2 *)(iVar3 + 4) = 4;
      *(int *)(iVar3 + 0x6c) = uVar5 - *(int *)(iVar3 + 0x6c);
      STREAM_RemoveQueueHead();
      LOAD_CleanUpBuffers();
      if (*(code **)(iVar3 + 0x2c) == VRAM_TransferBufferToVram) {
        VRAM_LoadReturn(*(void **)(iVar3 + 0x14),*(void **)(iVar3 + 0x30),*(void **)(iVar3 + 0x34));
      }
    }
    break;
  case 6:
    *(undefined2 *)(iVar3 + 4) = 4;
    STREAM_RemoveQueueHead();
    if (*(char *)(iVar3 + 7) != '\0') {
      MEMPACK_SetMemoryDoneStreamed(*(char **)(iVar3 + 0x14));
    }
    STREAM_NextLoadFromHead();
    if (*(code **)(iVar3 + 0x2c) != (code *)0x0) {
      (**(code **)(iVar3 + 0x2c))
                (*(undefined4 *)(iVar3 + 0x14),*(undefined4 *)(iVar3 + 0x30),
                 *(undefined4 *)(iVar3 + 0x34));
    }
    break;
  case 7:
    *(undefined2 *)(iVar3 + 4) = 9;
    VOICEXA_Play(*(int *)(iVar3 + 8),0);
    break;
  case 8:
    iVar3 = VOICEXA_IsPlaying();
    if (iVar3 != 0) {
      return numLoads;
    }
    LOAD_InitCdStreamMode();
    goto LAB_80060710;
  case 9:
    uVar5 = TIMER_GetTimeMS();
    *(ulong *)(iVar3 + 0x6c) = uVar5;
    iVar4 = LOAD_ChangeDirectoryByID(*(int *)(iVar3 + 0xc));
    if (iVar4 == 0) {
      DEBUG_FatalError(s_Could_not_read_directory_hash__d_800d0740);
    }
    *(undefined2 *)(iVar3 + 4) = 0xb;
    break;
  case 10:
    iVar4 = LOAD_IsFileLoading();
    if (iVar4 != 0) {
      return numLoads;
    }
    uVar5 = TIMER_GetTimeMS();
    *(int *)(iVar3 + 0x6c) = uVar5 - *(int *)(iVar3 + 0x6c);
LAB_80060710:
    STREAM_RemoveQueueHead();
  }
  return numLoads;
}



// decompiled code
// original method signature: 
// struct _LoadQueueEntry * /*$ra*/ STREAM_SetUpQueueEntry(char *fileName /*$s1*/, void *retFunc /*$s3*/, void *retData /*$s4*/, void *retData2 /*$s5*/, void **retPointer /*stack 16*/, int fromhead /*stack 20*/)
 // line 379, offset 0x80060730
	/* begin block 1 */
		// Start line: 380
		// Start offset: 0x80060730
		// Variables:
	// 		struct _LoadQueueEntry *currentEntry; // $s0
	/* end block 1 */
	// End offset: 0x80060808
	// End Line: 414

	/* begin block 2 */
		// Start line: 796
	/* end block 2 */
	// End Line: 797

/* File: C:\kain2\game\STRMLOAD.C */

_LoadQueueEntry *
STREAM_SetUpQueueEntry
          (char *fileName,void *retFunc,void *retData,void *retData2,void **retPointer,int fromhead)

{
  _LoadQueueEntry *p_Var1;
  long lVar2;
  
  if (fromhead == 0) {
    p_Var1 = STREAM_AddQueueEntryToTail();
  }
  else {
    p_Var1 = STREAM_AddQueueEntryToHead();
  }
  strcpy();
  lVar2 = LOAD_HashName(fileName);
  (p_Var1->loadEntry).fileHash = lVar2;
  lVar2 = LOAD_GetSearchDirectory();
  (p_Var1->loadEntry).dirHash = lVar2;
  (p_Var1->loadEntry).posInFile = 0;
  (p_Var1->loadEntry).checksumType = 1;
  lVar2 = LOAD_GetSearchDirectory();
  if (lVar2 == 0) {
    (p_Var1->loadEntry).dirHash = gCurDir;
    (p_Var1->loadEntry).retFunc = retFunc;
  }
  else {
    lVar2 = LOAD_GetSearchDirectory();
    (p_Var1->loadEntry).dirHash = lVar2;
    LOAD_SetSearchDirectory(0);
    (p_Var1->loadEntry).retFunc = retFunc;
  }
  (p_Var1->loadEntry).retData = retData;
  (p_Var1->loadEntry).retData2 = retData2;
  (p_Var1->loadEntry).retPointer = retPointer;
  if (retPointer != (void **)0x0) {
    *retPointer = (void *)0xfafbfcfd;
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_QueueNonblockingLoads(char *fileName /*$a0*/, unsigned char memType /*$s0*/, void *retFunc /*$a2*/, void *retData /*$a3*/, void *retData2 /*stack 16*/, void **retPointer /*stack 20*/, long relocateBinary /*stack 24*/)
 // line 418, offset 0x80060830
	/* begin block 1 */
		// Start line: 419
		// Start offset: 0x80060830
		// Variables:
	// 		struct _LoadQueueEntry *currentEntry; // $a0
	// 		int fromhead; // $v1
	/* end block 1 */
	// End offset: 0x800608A8
	// End Line: 436

	/* begin block 2 */
		// Start line: 876
	/* end block 2 */
	// End Line: 877

/* File: C:\kain2\game\STRMLOAD.C */

void STREAM_QueueNonblockingLoads
               (char *fileName,uchar memType,void *retFunc,void *retData,void *retData2,
               void **retPointer,long relocateBinary)

{
  short sVar1;
  _LoadQueueEntry *p_Var2;
  uint fromhead;
  
  fromhead = 0;
  if (loadBufferedFromHead != 0) {
    fromhead = (uint)(memType == '\0');
  }
  loadBufferedFromHead = 0;
  p_Var2 = STREAM_SetUpQueueEntry(fileName,retFunc,retData,retData2,retPointer,fromhead);
  (p_Var2->loadEntry).loadAddr = (long *)0x0;
  p_Var2->mempackUsed = '\x01';
  (p_Var2->loadEntry).memType = (uint)memType;
  p_Var2->relocateBinary = (char)relocateBinary;
  if (memType == '\0') {
    sVar1 = 5;
  }
  else {
    sVar1 = 1;
  }
  p_Var2->status = sVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_LoadToAddress(char *fileName /*$a0*/, void *loadAddr /*$s0*/, long relocateBinary /*$s1*/)
 // line 439, offset 0x800608b8
	/* begin block 1 */
		// Start line: 440
		// Start offset: 0x800608B8
		// Variables:
	// 		struct _LoadQueueEntry *currentEntry; // $v0
	/* end block 1 */
	// End offset: 0x8006090C
	// End Line: 449

	/* begin block 2 */
		// Start line: 926
	/* end block 2 */
	// End Line: 927

/* File: C:\kain2\game\STRMLOAD.C */

void LOAD_LoadToAddress(char *fileName,void *loadAddr,long relocateBinary)

{
  _LoadQueueEntry *p_Var1;
  int iVar2;
  
  p_Var1 = STREAM_SetUpQueueEntry(fileName,(void *)0x0,(void *)0x0,(void *)0x0,(void **)0x0,0);
  (p_Var1->loadEntry).loadAddr = loadAddr;
  p_Var1->status = 1;
  p_Var1->relocateBinary = (char)relocateBinary;
  p_Var1->mempackUsed = '\0';
  do {
    iVar2 = STREAM_PollLoadQueue();
  } while (iVar2 != 0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_NonBlockingBinaryLoad(char *fileName /*$a0*/, void *retFunc /*$t0*/, void *retData /*$t1*/, void *retData2 /*$a3*/, void **retPointer /*stack 16*/, int memType /*stack 20*/)
 // line 462, offset 0x80060920
	/* begin block 1 */
		// Start line: 975
	/* end block 1 */
	// End Line: 976

/* File: C:\kain2\game\STRMLOAD.C */

void LOAD_NonBlockingBinaryLoad
               (char *fileName,void *retFunc,void *retData,void *retData2,void **retPointer,
               int memType)

{
  STREAM_QueueNonblockingLoads(fileName,(uchar)memType,retFunc,retData,retData2,retPointer,1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_NonBlockingFileLoad(char *fileName /*$a0*/, void *retFunc /*$v1*/, void *retData /*$t0*/, void *retData2 /*$a3*/, void **retPointer /*stack 16*/, int memType /*stack 20*/)
 // line 469, offset 0x80060964
	/* begin block 1 */
		// Start line: 993
	/* end block 1 */
	// End Line: 994

/* File: C:\kain2\game\STRMLOAD.C */

void LOAD_NonBlockingFileLoad
               (char *fileName,void *retFunc,void *retData,void *retData2,void **retPointer,
               int memType)

{
  STREAM_QueueNonblockingLoads(fileName,(uchar)memType,retFunc,retData,retData2,retPointer,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_NonBlockingBufferedLoad(char *fileName /*$a0*/, void *retFunc /*$v0*/, void *retData /*$v1*/, void *retData2 /*$a3*/)
 // line 475, offset 0x800609a4
	/* begin block 1 */
		// Start line: 1007
	/* end block 1 */
	// End Line: 1008

/* File: C:\kain2\game\STRMLOAD.C */

void LOAD_NonBlockingBufferedLoad(char *fileName,void *retFunc,void *retData,void *retData2)

{
  STREAM_QueueNonblockingLoads(fileName,'\0',retFunc,retData,retData2,(void **)0x0,0);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ LOAD_IsXAInQueue()
 // line 480, offset 0x800609e0
	/* begin block 1 */
		// Start line: 482
		// Start offset: 0x800609E0
		// Variables:
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x80060A18
	// End Line: 491

	/* begin block 2 */
		// Start line: 1018
	/* end block 2 */
	// End Line: 1019

	/* begin block 3 */
		// Start line: 1019
	/* end block 3 */
	// End Line: 1020

	/* begin block 4 */
		// Start line: 1021
	/* end block 4 */
	// End Line: 1022

/* File: C:\kain2\game\STRMLOAD.C */

int LOAD_IsXAInQueue(void)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = &LoadQueue;
  do {
    iVar2 = iVar2 + 1;
    if ((uint)*(ushort *)(puVar1 + 4) - 8 < 2) {
      return 1;
    }
    puVar1 = puVar1 + 0x70;
  } while (iVar2 < 0x28);
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_PlayXA(int number /*$s0*/)
 // line 493, offset 0x80060a20
	/* begin block 1 */
		// Start line: 494
		// Start offset: 0x80060A20
		// Variables:
	// 		struct _LoadQueueEntry *currentEntry; // $v0
	/* end block 1 */
	// End offset: 0x80060A20
	// End Line: 494

	/* begin block 2 */
		// Start line: 1047
	/* end block 2 */
	// End Line: 1048

/* File: C:\kain2\game\STRMLOAD.C */

void LOAD_PlayXA(int number)

{
  undefined2 uVar1;
  _LoadQueueEntry *p_Var2;
  
  p_Var2 = STREAM_AddQueueEntryToTail();
  p_Var2->status = 8;
  (p_Var2->loadEntry).fileHash = number;
  uVar1 = DAT_800d0768;
  *(undefined4 *)(p_Var2->loadEntry).fileName = DAT_800d0764;
  *(undefined2 *)((p_Var2->loadEntry).fileName + 4) = uVar1;
  return;
}



// decompiled code
// original method signature: 
// long * /*$ra*/ LOAD_ReadFile(char *fileName /*$a0*/, unsigned char memType /*$a1*/)
 // line 506, offset 0x80060a68
	/* begin block 1 */
		// Start line: 507
		// Start offset: 0x80060A68
		// Variables:
	// 		void *loadAddr; // stack offset -16
	/* end block 1 */
	// End offset: 0x80060AA0
	// End Line: 514

	/* begin block 2 */
		// Start line: 1076
	/* end block 2 */
	// End Line: 1077

/* File: C:\kain2\game\STRMLOAD.C */

long * LOAD_ReadFile(char *fileName,uchar memType)

{
  int iVar1;
  long *local_10 [2];
  
  STREAM_QueueNonblockingLoads(fileName,memType,(void *)0x0,(void *)0x0,(void *)0x0,local_10,0);
  do {
    iVar1 = STREAM_PollLoadQueue();
  } while (iVar1 != 0);
  return local_10[0];
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_ChangeDirectory(char *name /*$s1*/)
 // line 517, offset 0x80060ab4
	/* begin block 1 */
		// Start line: 518
		// Start offset: 0x80060AB4
		// Variables:
	// 		struct _LoadQueueEntry *currentEntry; // $s0
	/* end block 1 */
	// End offset: 0x80060AB4
	// End Line: 518

	/* begin block 2 */
		// Start line: 1101
	/* end block 2 */
	// End Line: 1102

/* File: C:\kain2\game\STRMLOAD.C */

void LOAD_ChangeDirectory(char *name)

{
  _LoadQueueEntry *p_Var1;
  
  p_Var1 = STREAM_AddQueueEntryToTail();
  gCurDir = LOAD_HashUnit(name);
  (p_Var1->loadEntry).dirHash = gCurDir;
  (p_Var1->loadEntry).fileHash = 0;
  p_Var1->status = 10;
  sprintf((p_Var1->loadEntry).fileName,s_dir__s_800d076c,name);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_AbortFileLoad(char *fileName /*$a0*/, void *retFunc /*$s3*/)
 // line 533, offset 0x80060b14
	/* begin block 1 */
		// Start line: 534
		// Start offset: 0x80060B14

		/* begin block 1.1 */
			// Start line: 537
			// Start offset: 0x80060B38
			// Variables:
		// 		struct _LoadQueueEntry *entry; // $s0
		// 		struct _LoadQueueEntry *prev; // $s1
		// 		long hash; // $v1
		/* end block 1.1 */
		// End offset: 0x80060BC8
		// End Line: 563
	/* end block 1 */
	// End offset: 0x80060BC8
	// End Line: 564

	/* begin block 2 */
		// Start line: 1143
	/* end block 2 */
	// End Line: 1144

	/* begin block 3 */
		// Start line: 1144
	/* end block 3 */
	// End Line: 1145

/* File: C:\kain2\game\STRMLOAD.C */

void LOAD_AbortFileLoad(char *fileName,void *retFunc)

{
  _LoadQueueEntry *prev;
  _LoadQueueEntry *entry;
  long lVar1;
  
  if (loadHead != (_LoadQueueEntry *)0x0) {
    lVar1 = LOAD_HashName(fileName);
    prev = (_LoadQueueEntry *)0x0;
    entry = loadHead;
    while (entry != (_LoadQueueEntry *)0x0) {
      if ((entry->loadEntry).fileHash == lVar1) {
        if (prev == (_LoadQueueEntry *)0x0) {
          LOAD_StopLoad();
        }
        if (entry->status == 6) {
          LOAD_CleanUpBuffers();
        }
        (*(code *)retFunc)((entry->loadEntry).loadAddr,(entry->loadEntry).retData,
                           (entry->loadEntry).retData2);
        STREAM_RemoveQueueEntry(entry,prev);
        return;
      }
      prev = entry;
      entry = entry->next;
    }
  }
  return;
}





