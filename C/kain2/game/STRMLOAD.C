#include "THISDUST.H"
#include "STRMLOAD.H"


// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_NextLoadFromHead()
 // line 36, offset 0x8005ff80
	/* begin block 1 */
		// Start line: 72
	/* end block 1 */
	// End Line: 73

	/* begin block 2 */
		// Start line: 73
	/* end block 2 */
	// End Line: 74

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_NextLoadFromHead(void)

{
  loadFromHead = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_NextLoadAsNormal()
 // line 41, offset 0x8005ff90
	/* begin block 1 */
		// Start line: 82
	/* end block 1 */
	// End Line: 83

	/* begin block 2 */
		// Start line: 83
	/* end block 2 */
	// End Line: 84

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_NextLoadAsNormal(void)

{
  loadFromHead = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_InitLoader(char *bigFileName /*$a0*/, char *voiceFileName /*$a1*/)
 // line 46, offset 0x8005ff9c
	/* begin block 1 */
		// Start line: 47
		// Start offset: 0x8005FF9C
		// Variables:
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x8005FFE4
	// End Line: 62

	/* begin block 2 */
		// Start line: 92
	/* end block 2 */
	// End Line: 93

void STREAM_InitLoader(char *bigFileName,char *voiceFileName)

{
  _LoadQueueEntry *p_Var1;
  _LoadQueueEntry *p_Var2;
  int iVar3;
  
  LOAD_InitCdLoader(bigFileName,voiceFileName);
  iVar3 = 0x26;
  p_Var2 = &_LoadQueueEntry_800dba24;
  p_Var1 = &_LoadQueueEntry_800dba94;
  loadFree = &LoadQueue;
  loadHead = (_LoadQueueEntry *)0x0;
  loadTail = (_LoadQueueEntry *)0x0;
  numLoads = 0;
  do {
    p_Var2->next = p_Var1;
    p_Var2 = p_Var2 + -1;
    iVar3 = iVar3 + -1;
    p_Var1 = p_Var1 + -1;
  } while (-1 < iVar3);
  _LoadQueueEntry_800dba94.next = (_LoadQueueEntry *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_RemoveQueueHead()
 // line 66, offset 0x8005fff8
	/* begin block 1 */
		// Start line: 68
		// Start offset: 0x8005FFF8
		// Variables:
	// 		struct _LoadQueueEntry *entry; // $a0
	/* end block 1 */
	// End offset: 0x80060018
	// End Line: 73

	/* begin block 2 */
		// Start line: 145
	/* end block 2 */
	// End Line: 146

	/* begin block 3 */
		// Start line: 146
	/* end block 3 */
	// End Line: 147

	/* begin block 4 */
		// Start line: 147
	/* end block 4 */
	// End Line: 148

/* WARNING: Unknown calling convention yet parameter storage is locked */

void STREAM_RemoveQueueHead(void)

{
  _LoadQueueEntry **pp_Var1;
  _LoadQueueEntry *p_Var2;
  
  p_Var2 = loadFree;
  if (loadHead->next == (_LoadQueueEntry *)0x0) {
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
 // line 78, offset 0x80060038
	/* begin block 1 */
		// Start line: 172
	/* end block 1 */
	// End Line: 173

	/* begin block 2 */
		// Start line: 173
	/* end block 2 */
	// End Line: 174

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
 // line 95, offset 0x80060094
	/* begin block 1 */
		// Start line: 96
		// Start offset: 0x80060094
		// Variables:
	// 		struct _LoadQueueEntry *entry; // $s0
	/* end block 1 */
	// End offset: 0x800600DC
	// End Line: 111

	/* begin block 2 */
		// Start line: 209
	/* end block 2 */
	// End Line: 210

/* WARNING: Unknown calling convention yet parameter storage is locked */

_LoadQueueEntry * STREAM_AddQueueEntryToTail(void)

{
  _LoadQueueEntry *p_Var1;
  
  p_Var1 = loadFree;
  if (loadFree == (_LoadQueueEntry *)0x0) {
    DEBUG_FatalError("CD ERROR: too many queue entries\n");
  }
  loadFree = p_Var1->next;
  p_Var1->next = (_LoadQueueEntry *)0x0;
  if (loadTail == (_LoadQueueEntry *)0x0) {
    loadHead = p_Var1;
  }
  else {
    loadTail->next = p_Var1;
  }
  loadTail = p_Var1;
  numLoads = numLoads + 1;
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct _LoadQueueEntry * /*$ra*/ STREAM_AddQueueEntryToHead()
 // line 116, offset 0x80060100
	/* begin block 1 */
		// Start line: 117
		// Start offset: 0x80060100
		// Variables:
	// 		struct _LoadQueueEntry *entry; // $s0
	/* end block 1 */
	// End offset: 0x80060194
	// End Line: 141

	/* begin block 2 */
		// Start line: 259
	/* end block 2 */
	// End Line: 260

/* WARNING: Unknown calling convention yet parameter storage is locked */

_LoadQueueEntry * STREAM_AddQueueEntryToHead(void)

{
  short sVar1;
  _LoadQueueEntry *p_Var2;
  _LoadQueueEntry *p_Var3;
  
  p_Var2 = loadFree;
  if (loadFree == (_LoadQueueEntry *)0x0) {
    DEBUG_FatalError("CD ERROR: too many queue entries\n");
  }
  p_Var3 = loadHead;
  loadFree = p_Var2->next;
  if ((((loadHead == (_LoadQueueEntry *)0x0) || (sVar1 = loadHead->status, sVar1 == 1)) ||
      (sVar1 == 5)) || ((sVar1 == 10 || (sVar1 == 8)))) {
    loadHead = p_Var2;
    p_Var2->next = p_Var3;
  }
  else {
    p_Var2->next = loadHead->next;
    p_Var3->next = p_Var2;
  }
  if (loadTail == (_LoadQueueEntry *)0x0) {
    loadTail = p_Var2;
  }
  numLoads = numLoads + 1;
  return p_Var2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_IsCdBusy(long *numberInQueue /*$a0*/)
 // line 150, offset 0x800601b4
	/* begin block 1 */
		// Start line: 334
	/* end block 1 */
	// End Line: 335

	/* begin block 2 */
		// Start line: 335
	/* end block 2 */
	// End Line: 336

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
 // line 167, offset 0x800601d4
	/* begin block 1 */
		// Start line: 168
		// Start offset: 0x800601D4

		/* begin block 1.1 */
			// Start line: 173
			// Start offset: 0x800601F8
			// Variables:
		// 		struct _LoadQueueEntry *queueEntry; // $s1

			/* begin block 1.1.1 */
				// Start line: 203
				// Start offset: 0x800602C0
				// Variables:
			// 		long size; // $v0
			/* end block 1.1.1 */
			// End offset: 0x800602F0
			// End Line: 209

			/* begin block 1.1.2 */
				// Start line: 251
				// Start offset: 0x800603B4
				// Variables:
			// 		struct _LoadQueueEntry *newQueue; // $s0
			/* end block 1.1.2 */
			// End offset: 0x800603B4
			// End Line: 251

			/* begin block 1.1.3 */
				// Start line: 283
				// Start offset: 0x80060450
				// Variables:
			// 		struct _LoadQueueEntry *newQueue; // $s0
			/* end block 1.1.3 */
			// End offset: 0x80060450
			// End Line: 283
		/* end block 1.1 */
		// End offset: 0x800605A8
		// End Line: 398
	/* end block 1 */
	// End offset: 0x800605AC
	// End Line: 401

	/* begin block 2 */
		// Start line: 368
	/* end block 2 */
	// End Line: 369

/* WARNING: Unknown calling convention yet parameter storage is locked */

int STREAM_PollLoadQueue(void)

{
  short sVar1;
  _LoadQueueEntry *p_Var2;
  code *pcVar3;
  long *plVar4;
  _LoadQueueEntry *p_Var5;
  int id;
  ulong uVar6;
  long **pplVar7;
  long takeBackSize;
  
  LOAD_ProcessReadQueue();
  p_Var2 = loadHead;
  if (loadHead == (_LoadQueueEntry *)0x0) {
    return numLoads;
  }
  if (gameTrackerX.debugFlags < 0) {
    FONT_Print("%s status %d\n");
  }
  if ((gameTrackerX.gameFlags & 0x800U) != 0) {
    sVar1 = p_Var2->status;
    if (sVar1 == 1) {
      return numLoads;
    }
    if (sVar1 == 5) {
      return numLoads;
    }
    if (sVar1 == 8) {
      return numLoads;
    }
    if (sVar1 == 10) {
      return numLoads;
    }
  }
  switch((int)(((uint)(ushort)p_Var2->status - 1) * 0x10000) >> 0x10) {
  case 0:
    uVar6 = TIMER_GetTimeMS();
    p_Var2->endLoadTime = uVar6;
    LOAD_NonBlockingReadFile(&p_Var2->loadEntry);
    id = LOAD_ChangeDirectoryFlag();
    if (id == 0) {
      p_Var2->status = 2;
      if (p_Var2->mempackUsed != '\0') {
        MEMPACK_SetMemoryBeingStreamed((char *)(p_Var2->loadEntry).loadAddr);
      }
      pplVar7 = (long **)(p_Var2->loadEntry).retPointer;
      if (pplVar7 != (long **)0x0) {
        *pplVar7 = (p_Var2->loadEntry).loadAddr;
      }
    }
    else {
      p_Var5 = STREAM_AddQueueEntryToHead();
      sprintf((p_Var5->loadEntry).fileName,"(%d)");
      takeBackSize = (p_Var2->loadEntry).dirHash;
      (p_Var5->loadEntry).fileHash = 0;
      p_Var5->status = 10;
      (p_Var5->loadEntry).dirHash = takeBackSize;
    }
    break;
  case 1:
    id = LOAD_IsFileLoading();
    if (id != 0) {
      return numLoads;
    }
    uVar6 = TIMER_GetTimeMS();
    p_Var2->endLoadTime = uVar6 - p_Var2->endLoadTime;
    if (p_Var2->relocateBinary != '\0') {
      takeBackSize = LOAD_RelocBinaryData((p_Var2->loadEntry).loadAddr,(p_Var2->loadEntry).loadSize)
      ;
      if (p_Var2->mempackUsed != '\0') {
        MEMPACK_Return((char *)(p_Var2->loadEntry).loadAddr,takeBackSize);
      }
      p_Var2->relocateBinary = '\0';
    }
    if ((p_Var2->loadEntry).retFunc != (void *)0x0) {
      p_Var2->status = 7;
      return numLoads;
    }
    p_Var2->status = 4;
    if (p_Var2->mempackUsed != '\0') {
      MEMPACK_SetMemoryDoneStreamed((char *)(p_Var2->loadEntry).loadAddr);
    }
    goto LAB_800605a0;
  case 4:
    plVar4 = (long *)LOAD_InitBuffers();
    (p_Var2->loadEntry).loadAddr = plVar4;
    uVar6 = TIMER_GetTimeMS();
    p_Var2->endLoadTime = uVar6;
    LOAD_CD_ReadPartOfFile(&p_Var2->loadEntry);
    id = LOAD_ChangeDirectoryFlag();
    if (id == 0) {
      p_Var2->status = 6;
      (p_Var2->loadEntry).posInFile = 0;
    }
    else {
      p_Var5 = STREAM_AddQueueEntryToHead();
      sprintf((p_Var5->loadEntry).fileName,"(%d)");
      takeBackSize = (p_Var2->loadEntry).dirHash;
      (p_Var5->loadEntry).fileHash = 0;
      p_Var5->status = 10;
      (p_Var5->loadEntry).dirHash = takeBackSize;
      LOAD_CleanUpBuffers();
    }
    break;
  case 5:
    id = LOAD_IsFileLoading();
    if (id == 0) {
      uVar6 = TIMER_GetTimeMS();
      p_Var2->status = 4;
      p_Var2->endLoadTime = uVar6 - p_Var2->endLoadTime;
      STREAM_RemoveQueueHead();
      LOAD_CleanUpBuffers();
      if ((code *)(p_Var2->loadEntry).retFunc == VRAM_TransferBufferToVram) {
        VRAM_LoadReturn((p_Var2->loadEntry).loadAddr,(p_Var2->loadEntry).retData,
                        (p_Var2->loadEntry).retData2);
      }
    }
    break;
  case 6:
    p_Var2->status = 4;
    STREAM_RemoveQueueHead();
    if (p_Var2->mempackUsed != '\0') {
      MEMPACK_SetMemoryDoneStreamed((char *)(p_Var2->loadEntry).loadAddr);
    }
    STREAM_NextLoadFromHead();
    pcVar3 = (code *)(p_Var2->loadEntry).retFunc;
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)((p_Var2->loadEntry).loadAddr,(p_Var2->loadEntry).retData,
                (p_Var2->loadEntry).retData2);
    }
    STREAM_NextLoadAsNormal();
    break;
  case 7:
    id = (p_Var2->loadEntry).fileHash;
    p_Var2->status = 9;
    VOICEXA_Play(id,0);
    break;
  case 8:
    id = VOICEXA_IsPlaying();
    if (id != 0) {
      return numLoads;
    }
    LOAD_InitCdStreamMode();
    goto LAB_800605a0;
  case 9:
    uVar6 = TIMER_GetTimeMS();
    id = (p_Var2->loadEntry).dirHash;
    p_Var2->endLoadTime = uVar6;
    id = LOAD_ChangeDirectoryByID(id);
    if (id == 0) {
      DEBUG_FatalError("Could not read directory hash %d\n");
    }
    p_Var2->status = 0xb;
    break;
  case 10:
    id = LOAD_IsFileLoading();
    if (id != 0) {
      return numLoads;
    }
    uVar6 = TIMER_GetTimeMS();
    p_Var2->endLoadTime = uVar6 - p_Var2->endLoadTime;
LAB_800605a0:
    STREAM_RemoveQueueHead();
  }
  return numLoads;
}



// decompiled code
// original method signature: 
// struct _LoadQueueEntry * /*$ra*/ STREAM_SetUpQueueEntry(char *fileName /*$s1*/, void *retFunc /*$s3*/, void *retData /*$s4*/, void *retData2 /*$s5*/, void **retPointer /*stack 16*/, int fromhead /*stack 20*/)
 // line 403, offset 0x800605c0
	/* begin block 1 */
		// Start line: 404
		// Start offset: 0x800605C0
		// Variables:
	// 		struct _LoadQueueEntry *currentEntry; // $s0
	/* end block 1 */
	// End offset: 0x80060698
	// End Line: 438

	/* begin block 2 */
		// Start line: 857
	/* end block 2 */
	// End Line: 858

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
  strcpy((p_Var1->loadEntry).fileName,fileName);
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
 // line 442, offset 0x800606c0
	/* begin block 1 */
		// Start line: 443
		// Start offset: 0x800606C0
		// Variables:
	// 		struct _LoadQueueEntry *currentEntry; // $v1
	// 		int fromhead; // $v0
	/* end block 1 */
	// End offset: 0x8006072C
	// End Line: 460

	/* begin block 2 */
		// Start line: 937
	/* end block 2 */
	// End Line: 938

void STREAM_QueueNonblockingLoads
               (char *fileName,uchar memType,void *retFunc,void *retData,void *retData2,
               void **retPointer,long relocateBinary)

{
  int fromhead;
  short sVar1;
  _LoadQueueEntry *p_Var2;
  
  fromhead = loadFromHead;
  loadFromHead = 0;
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
 // line 463, offset 0x80060740
	/* begin block 1 */
		// Start line: 464
		// Start offset: 0x80060740
		// Variables:
	// 		struct _LoadQueueEntry *currentEntry; // $v0
	/* end block 1 */
	// End offset: 0x80060794
	// End Line: 473

	/* begin block 2 */
		// Start line: 996
	/* end block 2 */
	// End Line: 997

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
 // line 486, offset 0x800607a8
	/* begin block 1 */
		// Start line: 1045
	/* end block 1 */
	// End Line: 1046

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
 // line 493, offset 0x800607ec
	/* begin block 1 */
		// Start line: 1063
	/* end block 1 */
	// End Line: 1064

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
 // line 499, offset 0x8006082c
	/* begin block 1 */
		// Start line: 1077
	/* end block 1 */
	// End Line: 1078

void LOAD_NonBlockingBufferedLoad(char *fileName,void *retFunc,void *retData,void *retData2)

{
  STREAM_QueueNonblockingLoads(fileName,'\0',retFunc,retData,retData2,(void **)0x0,0);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ LOAD_IsXAInQueue()
 // line 504, offset 0x80060868
	/* begin block 1 */
		// Start line: 506
		// Start offset: 0x80060868
		// Variables:
	// 		struct _LoadQueueEntry *entry; // $v1
	/* end block 1 */
	// End offset: 0x800608A0
	// End Line: 515

	/* begin block 2 */
		// Start line: 1088
	/* end block 2 */
	// End Line: 1089

	/* begin block 3 */
		// Start line: 1089
	/* end block 3 */
	// End Line: 1090

	/* begin block 4 */
		// Start line: 1091
	/* end block 4 */
	// End Line: 1092

/* WARNING: Unknown calling convention yet parameter storage is locked */

int LOAD_IsXAInQueue(void)

{
  _LoadQueueEntry *p_Var1;
  
  p_Var1 = loadHead;
  if (loadHead != (_LoadQueueEntry *)0x0) {
    do {
      if ((uint)(ushort)p_Var1->status - 8 < 2) {
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
 // line 517, offset 0x800608b0
	/* begin block 1 */
		// Start line: 518
		// Start offset: 0x800608B0
		// Variables:
	// 		struct _LoadQueueEntry *currentEntry; // $v0
	/* end block 1 */
	// End offset: 0x800608B0
	// End Line: 518

	/* begin block 2 */
		// Start line: 1116
	/* end block 2 */
	// End Line: 1117

void LOAD_PlayXA(int number)

{
  _LoadQueueEntry *p_Var1;
  
  p_Var1 = STREAM_AddQueueEntryToTail();
  p_Var1->status = 8;
  (p_Var1->loadEntry).fileHash = number;
  *(undefined4 *)(p_Var1->loadEntry).fileName = 0x63696f76;
  *(undefined2 *)((p_Var1->loadEntry).fileName + 4) = 0x65;
  return;
}



// decompiled code
// original method signature: 
// long * /*$ra*/ LOAD_ReadFile(char *fileName /*$a0*/, unsigned char memType /*$a1*/)
 // line 530, offset 0x800608f8
	/* begin block 1 */
		// Start line: 531
		// Start offset: 0x800608F8
		// Variables:
	// 		void *loadAddr; // stack offset -16
	/* end block 1 */
	// End offset: 0x80060930
	// End Line: 538

	/* begin block 2 */
		// Start line: 1145
	/* end block 2 */
	// End Line: 1146

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
 // line 541, offset 0x80060944
	/* begin block 1 */
		// Start line: 542
		// Start offset: 0x80060944
		// Variables:
	// 		struct _LoadQueueEntry *currentEntry; // $s0
	/* end block 1 */
	// End offset: 0x80060944
	// End Line: 542

	/* begin block 2 */
		// Start line: 1170
	/* end block 2 */
	// End Line: 1171

void LOAD_ChangeDirectory(char *name)

{
  _LoadQueueEntry *p_Var1;
  
  p_Var1 = STREAM_AddQueueEntryToTail();
  gCurDir = LOAD_HashUnit(name);
  (p_Var1->loadEntry).dirHash = gCurDir;
  (p_Var1->loadEntry).fileHash = 0;
  p_Var1->status = 10;
  sprintf((p_Var1->loadEntry).fileName,"dir %s");
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_AbortDirectoryChange(char *name /*$a0*/)
 // line 557, offset 0x800609a4
	/* begin block 1 */
		// Start line: 558
		// Start offset: 0x800609A4

		/* begin block 1.1 */
			// Start line: 562
			// Start offset: 0x800609B4
			// Variables:
		// 		struct _LoadQueueEntry *entry; // $a0
		// 		struct _LoadQueueEntry *prev; // $a1
		// 		long hash; // $v1
		/* end block 1.1 */
		// End offset: 0x80060A1C
		// End Line: 577
	/* end block 1 */
	// End offset: 0x80060A1C
	// End Line: 579

	/* begin block 2 */
		// Start line: 1212
	/* end block 2 */
	// End Line: 1213

	/* begin block 3 */
		// Start line: 1214
	/* end block 3 */
	// End Line: 1215

void LOAD_AbortDirectoryChange(char *name)

{
  _LoadQueueEntry *entry;
  _LoadQueueEntry *prev;
  _LoadQueueEntry *p_Var1;
  long lVar2;
  
  if (loadHead != (_LoadQueueEntry *)0x0) {
    lVar2 = LOAD_HashUnit(name);
    p_Var1 = loadHead->next;
    prev = loadHead;
    while (entry = p_Var1, entry != (_LoadQueueEntry *)0x0) {
      if ((entry->status == 10) && ((entry->loadEntry).dirHash == lVar2)) {
        STREAM_RemoveQueueEntry(entry,prev);
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
 // line 581, offset 0x80060a2c
	/* begin block 1 */
		// Start line: 582
		// Start offset: 0x80060A2C

		/* begin block 1.1 */
			// Start line: 585
			// Start offset: 0x80060A50
			// Variables:
		// 		struct _LoadQueueEntry *entry; // $s0
		// 		struct _LoadQueueEntry *prev; // $s1
		// 		long hash; // $v1
		/* end block 1.1 */
		// End offset: 0x80060AE0
		// End Line: 611
	/* end block 1 */
	// End offset: 0x80060AE0
	// End Line: 612

	/* begin block 2 */
		// Start line: 1272
	/* end block 2 */
	// End Line: 1273

	/* begin block 3 */
		// Start line: 1273
	/* end block 3 */
	// End Line: 1274

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





