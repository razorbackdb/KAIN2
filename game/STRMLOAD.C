#include "THISDUST.H"
#include "STRMLOAD.H"


// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_InitLoader(char *bigFileName /*$a0*/, char *voiceFileName /*$a1*/)
 // line 32, offset 0x80060e6c
	/* begin block 1 */
		// Start line: 33
		// Start offset: 0x80060E6C
		// Variables:
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x80060EB4
	// End Line: 48

	/* begin block 2 */
		// Start line: 64
	/* end block 2 */
	// End Line: 65

void STREAM_InitLoader(char *bigFileName,char *voiceFileName)

{
  _LoadQueueEntry *p_Var1;
  _LoadQueueEntry *p_Var2;
  int iVar3;
  
  LOAD_InitCdLoader(bigFileName,voiceFileName);
  iVar3 = 0x3e;
  p_Var2 = &_LoadQueueEntry_800db1c0;
  p_Var1 = &_LoadQueueEntry_800db240;
  loadFree = &LoadQueue;
  loadHead = (_LoadQueueEntry *)0x0;
  loadTail = (_LoadQueueEntry *)0x0;
  numLoads = 0;
  do {
    p_Var2->next = p_Var1;
    p_Var2 = (_LoadQueueEntry *)(p_Var2[-2].loadEntry.fileName + 0x24);
    iVar3 = iVar3 + -1;
    p_Var1 = (_LoadQueueEntry *)(p_Var1[-2].loadEntry.fileName + 0x24);
  } while (-1 < iVar3);
  _LoadQueueEntry_800db240.next = (_LoadQueueEntry *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ STREAM_RemoveQueueHead()
 // line 52, offset 0x80060ec8
	/* begin block 1 */
		// Start line: 54
		// Start offset: 0x80060EC8
		// Variables:
	// 		struct _LoadQueueEntry *entry; // $a0
	/* end block 1 */
	// End offset: 0x80060EE8
	// End Line: 59

	/* begin block 2 */
		// Start line: 117
	/* end block 2 */
	// End Line: 118

	/* begin block 3 */
		// Start line: 118
	/* end block 3 */
	// End Line: 119

	/* begin block 4 */
		// Start line: 119
	/* end block 4 */
	// End Line: 120

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
 // line 64, offset 0x80060f08
	/* begin block 1 */
		// Start line: 144
	/* end block 1 */
	// End Line: 145

	/* begin block 2 */
		// Start line: 145
	/* end block 2 */
	// End Line: 146

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
 // line 81, offset 0x80060f64
	/* begin block 1 */
		// Start line: 83
		// Start offset: 0x80060F64
		// Variables:
	// 		struct _LoadQueueEntry *entry; // $v1
	/* end block 1 */
	// End offset: 0x80060F8C
	// End Line: 95

	/* begin block 2 */
		// Start line: 181
	/* end block 2 */
	// End Line: 182

	/* begin block 3 */
		// Start line: 182
	/* end block 3 */
	// End Line: 183

	/* begin block 4 */
		// Start line: 183
	/* end block 4 */
	// End Line: 184

/* WARNING: Unknown calling convention yet parameter storage is locked */

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
    loadTail->next = loadFree;
    loadFree = p_Var2;
  }
  loadTail = p_Var1;
  numLoads = numLoads + 1;
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct _LoadQueueEntry * /*$ra*/ STREAM_AddQueueEntryToHead()
 // line 100, offset 0x80060fa4
	/* begin block 1 */
		// Start line: 102
		// Start offset: 0x80060FA4
		// Variables:
	// 		struct _LoadQueueEntry *entry; // $a1
	/* end block 1 */
	// End offset: 0x80060FCC
	// End Line: 110

	/* begin block 2 */
		// Start line: 223
	/* end block 2 */
	// End Line: 224

	/* begin block 3 */
		// Start line: 224
	/* end block 3 */
	// End Line: 225

	/* begin block 4 */
		// Start line: 225
	/* end block 4 */
	// End Line: 226

/* WARNING: Unknown calling convention yet parameter storage is locked */

_LoadQueueEntry * STREAM_AddQueueEntryToHead(void)

{
  _LoadQueueEntry *p_Var1;
  _LoadQueueEntry *p_Var2;
  _LoadQueueEntry *p_Var3;
  
  p_Var1 = loadTail;
  p_Var2 = loadFree;
  p_Var3 = loadFree->next;
  loadFree->next = loadHead;
  if (p_Var1 == (_LoadQueueEntry *)0x0) {
    loadTail = loadFree;
  }
  loadFree = p_Var3;
  loadHead = p_Var2;
  numLoads = numLoads + 1;
  return p_Var2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_IsCdBusy(long *numberInQueue /*$a0*/)
 // line 119, offset 0x80060fe4
	/* begin block 1 */
		// Start line: 266
	/* end block 1 */
	// End Line: 267

	/* begin block 2 */
		// Start line: 267
	/* end block 2 */
	// End Line: 268

int STREAM_IsCdBusy(long *numberInQueue)

{
  if (numberInQueue != (long *)0x0) {
    *numberInQueue = numLoads;
  }
  return (uint)(loadHead != (_LoadQueueEntry *)0x0);
}



// decompiled code
// original method signature: 
// int /*$ra*/ STREAM_PollLoadQueue()
 // line 136, offset 0x80061004
	/* begin block 1 */
		// Start line: 137
		// Start offset: 0x80061004

		/* begin block 1.1 */
			// Start line: 142
			// Start offset: 0x80061024
			// Variables:
		// 		struct _LoadQueueEntry *queueEntry; // $s0

			/* begin block 1.1.1 */
				// Start line: 160
				// Start offset: 0x80061108
				// Variables:
			// 		long size; // $v0
			/* end block 1.1.1 */
			// End offset: 0x80061138
			// End Line: 166

			/* begin block 1.1.2 */
				// Start line: 208
				// Start offset: 0x80061214
				// Variables:
			// 		struct _LoadQueueEntry *newQueue; // $v0
			/* end block 1.1.2 */
			// End offset: 0x80061214
			// End Line: 208

			/* begin block 1.1.3 */
				// Start line: 236
				// Start offset: 0x800612B4
				// Variables:
			// 		struct _LoadQueueEntry *newQueue; // $v0
			/* end block 1.1.3 */
			// End offset: 0x800612B4
			// End Line: 236
		/* end block 1.1 */
		// End offset: 0x80061474
		// End Line: 337
	/* end block 1 */
	// End offset: 0x80061474
	// End Line: 339

	/* begin block 2 */
		// Start line: 300
	/* end block 2 */
	// End Line: 301

/* WARNING: Unknown calling convention yet parameter storage is locked */

int STREAM_PollLoadQueue(void)

{
  _LoadQueueEntry *p_Var1;
  long *plVar2;
  _LoadQueueEntry *p_Var3;
  int voiceIndex;
  ulong uVar4;
  code *pcVar5;
  long **pplVar6;
  long takeBackSize;
  
  LOAD_ProcessReadQueue();
  p_Var1 = loadHead;
  if (loadHead == (_LoadQueueEntry *)0x0) goto LAB_80061474;
  if (gameTrackerX.debugFlags < 0) {
    FONT_Print("%s status %d\n");
  }
  switch((int)(((uint)(ushort)p_Var1->status - 1) * 0x10000) >> 0x10) {
  case 0:
    if (gameTrackerX.debugFlags < 0) {
      GXFilePrint("Load %s %x\n");
    }
    uVar4 = TIMER_GetTimeMS();
    p_Var1[1].loadEntry.dirHash = uVar4;
    LOAD_NonBlockingReadFile(&p_Var1->loadEntry);
    voiceIndex = LOAD_ChangeDirectoryFlag();
    if (voiceIndex == 0) {
      p_Var1->status = 2;
      if (p_Var1->mempackUsed != '\0') {
        MEMPACK_SetMemoryBeingStreamed((char *)(p_Var1->loadEntry).loadAddr);
      }
      pplVar6 = (long **)(p_Var1->loadEntry).retPointer;
      if (pplVar6 != (long **)0x0) {
        *pplVar6 = (p_Var1->loadEntry).loadAddr;
      }
    }
    else {
      p_Var3 = STREAM_AddQueueEntryToHead();
      takeBackSize = (p_Var1->loadEntry).dirHash;
      p_Var3->status = 10;
      (p_Var3->loadEntry).dirHash = takeBackSize;
    }
    break;
  case 1:
    voiceIndex = LOAD_IsFileLoading();
    if (voiceIndex != 0) break;
    uVar4 = TIMER_GetTimeMS();
    p_Var1[1].loadEntry.dirHash = uVar4 - p_Var1[1].loadEntry.dirHash;
    if (gameTrackerX.debugFlags < 0) {
      GXFilePrint("Took %d ms to load %s size %d (%d b/s)\n");
    }
    if (p_Var1->relocateBinary != '\0') {
      takeBackSize = LOAD_RelocBinaryData((p_Var1->loadEntry).loadAddr,(p_Var1->loadEntry).loadSize)
      ;
      if (p_Var1->mempackUsed != '\0') {
        MEMPACK_Return((char *)(p_Var1->loadEntry).loadAddr,takeBackSize);
      }
      p_Var1->relocateBinary = '\0';
    }
    if ((p_Var1->loadEntry).retFunc != (void *)0x0) {
      p_Var1->status = 7;
      break;
    }
    p_Var1->status = 4;
    if (p_Var1->mempackUsed != '\0') {
      MEMPACK_SetMemoryDoneStreamed((char *)(p_Var1->loadEntry).loadAddr);
    }
    goto LAB_800613ac;
  default:
    GXFilePrint("Don\'t understand status number %d\n");
    break;
  case 4:
    plVar2 = (long *)LOAD_InitBuffers();
    (p_Var1->loadEntry).loadAddr = plVar2;
    uVar4 = TIMER_GetTimeMS();
    p_Var1[1].loadEntry.dirHash = uVar4;
    if (gameTrackerX.debugFlags < 0) {
      GXFilePrint("Buffer Load %s at %d\n");
    }
    LOAD_CD_ReadPartOfFile(&p_Var1->loadEntry);
    voiceIndex = LOAD_ChangeDirectoryFlag();
    if (voiceIndex == 0) {
      p_Var1->status = 6;
      (p_Var1->loadEntry).posInFile = 0;
    }
    else {
      p_Var3 = STREAM_AddQueueEntryToHead();
      takeBackSize = (p_Var1->loadEntry).dirHash;
      p_Var3->status = 10;
      (p_Var3->loadEntry).dirHash = takeBackSize;
      LOAD_CleanUpBuffers();
    }
    break;
  case 5:
    voiceIndex = LOAD_IsFileLoading();
    if (voiceIndex == 0) {
      uVar4 = TIMER_GetTimeMS();
      p_Var1[1].loadEntry.dirHash = uVar4 - p_Var1[1].loadEntry.dirHash;
      if (gameTrackerX.debugFlags < 0) {
        GXFilePrint("Took %d ms to load %s size %d (%d b/s)\n");
      }
      p_Var1->status = 4;
      STREAM_RemoveQueueHead();
      LOAD_CleanUpBuffers();
    }
    break;
  case 6:
    p_Var1->status = 4;
    STREAM_RemoveQueueHead();
    if (p_Var1->mempackUsed != '\0') {
      MEMPACK_SetMemoryDoneStreamed((char *)(p_Var1->loadEntry).loadAddr);
    }
    pcVar5 = (code *)(p_Var1->loadEntry).retFunc;
    loadBufferedFromHead = 1;
    if (pcVar5 != (code *)0x0) {
      (*pcVar5)((p_Var1->loadEntry).loadAddr,(p_Var1->loadEntry).retData,
                (p_Var1->loadEntry).retData2);
    }
    loadBufferedFromHead = 0;
    break;
  case 7:
    voiceIndex = (p_Var1->loadEntry).fileHash;
    p_Var1->status = 9;
    VOICEXA_Play(voiceIndex,0);
    break;
  case 8:
    voiceIndex = VOICEXA_IsPlaying();
    if (voiceIndex != 0) break;
    LOAD_InitCdStreamMode();
    goto LAB_800613ac;
  case 9:
    uVar4 = TIMER_GetTimeMS();
    p_Var1[1].loadEntry.dirHash = uVar4;
    if (gameTrackerX.debugFlags < 0) {
      GXFilePrint("Directory change %s at %d\n");
    }
    voiceIndex = LOAD_ChangeDirectoryByID((p_Var1->loadEntry).dirHash);
    if (voiceIndex == 0) {
      DEBUG_FatalError("Could not read directory hash %d\n");
    }
    p_Var1->status = 0xb;
    break;
  case 10:
    voiceIndex = LOAD_IsFileLoading();
    if (voiceIndex != 0) break;
    uVar4 = TIMER_GetTimeMS();
    p_Var1[1].loadEntry.dirHash = uVar4 - p_Var1[1].loadEntry.dirHash;
    if (gameTrackerX.debugFlags < 0) {
      GXFilePrint("Took %d ms to load %s\n");
    }
LAB_800613ac:
    STREAM_RemoveQueueHead();
  }
LAB_80061474:
  return (uint)(loadHead != (_LoadQueueEntry *)0x0);
}



// decompiled code
// original method signature: 
// struct _LoadQueueEntry * /*$ra*/ STREAM_SetUpQueueEntry(char *fileName /*$s2*/, void *retFunc /*$s3*/, void *retData /*$s4*/, void *retData2 /*$s5*/, void **retPointer /*stack 16*/, int fromhead /*stack 20*/)
 // line 342, offset 0x8006148c
	/* begin block 1 */
		// Start line: 343
		// Start offset: 0x8006148C
		// Variables:
	// 		struct _LoadQueueEntry *currentEntry; // $s0
	/* end block 1 */
	// End offset: 0x80061540
	// End Line: 372

	/* begin block 2 */
		// Start line: 718
	/* end block 2 */
	// End Line: 719

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
  (p_Var1->loadEntry).dirHash = lVar2;
  LOAD_SetSearchDirectory(0);
  (p_Var1->loadEntry).retFunc = retFunc;
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
 // line 376, offset 0x80061568
	/* begin block 1 */
		// Start line: 377
		// Start offset: 0x80061568
		// Variables:
	// 		struct _LoadQueueEntry *currentEntry; // $a0
	// 		int fromhead; // $v1
	/* end block 1 */
	// End offset: 0x800615DC
	// End Line: 393

	/* begin block 2 */
		// Start line: 788
	/* end block 2 */
	// End Line: 789

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
 // line 396, offset 0x800615ec
	/* begin block 1 */
		// Start line: 397
		// Start offset: 0x800615EC
		// Variables:
	// 		struct _LoadQueueEntry *currentEntry; // $v0
	/* end block 1 */
	// End offset: 0x80061640
	// End Line: 406

	/* begin block 2 */
		// Start line: 834
	/* end block 2 */
	// End Line: 835

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
 // line 419, offset 0x80061654
	/* begin block 1 */
		// Start line: 883
	/* end block 1 */
	// End Line: 884

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
 // line 426, offset 0x80061698
	/* begin block 1 */
		// Start line: 901
	/* end block 1 */
	// End Line: 902

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
 // line 432, offset 0x800616d8
	/* begin block 1 */
		// Start line: 915
	/* end block 1 */
	// End Line: 916

void LOAD_NonBlockingBufferedLoad(char *fileName,void *retFunc,void *retData,void *retData2)

{
  STREAM_QueueNonblockingLoads(fileName,'\0',retFunc,retData,retData2,(void **)0x0,0);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ LOAD_IsXAInQueue()
 // line 437, offset 0x80061714
	/* begin block 1 */
		// Start line: 439
		// Start offset: 0x80061714
		// Variables:
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x8006174C
	// End Line: 448

	/* begin block 2 */
		// Start line: 926
	/* end block 2 */
	// End Line: 927

	/* begin block 3 */
		// Start line: 927
	/* end block 3 */
	// End Line: 928

	/* begin block 4 */
		// Start line: 929
	/* end block 4 */
	// End Line: 930

/* WARNING: Unknown calling convention yet parameter storage is locked */

int LOAD_IsXAInQueue(void)

{
  _LoadQueueEntry *p_Var1;
  int iVar2;
  
  iVar2 = 0;
  p_Var1 = &LoadQueue;
  do {
    iVar2 = iVar2 + 1;
    if ((uint)(ushort)p_Var1->status - 8 < 2) {
      return 1;
    }
    p_Var1 = (_LoadQueueEntry *)&p_Var1[1].loadEntry.filePos;
  } while (iVar2 < 0x40);
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_PlayXA(int number /*$s0*/)
 // line 450, offset 0x80061754
	/* begin block 1 */
		// Start line: 451
		// Start offset: 0x80061754
		// Variables:
	// 		struct _LoadQueueEntry *currentEntry; // $v0
	/* end block 1 */
	// End offset: 0x80061754
	// End Line: 451

	/* begin block 2 */
		// Start line: 955
	/* end block 2 */
	// End Line: 956

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
 // line 463, offset 0x8006179c
	/* begin block 1 */
		// Start line: 464
		// Start offset: 0x8006179C
		// Variables:
	// 		void *loadAddr; // stack offset -16
	/* end block 1 */
	// End offset: 0x800617D4
	// End Line: 471

	/* begin block 2 */
		// Start line: 984
	/* end block 2 */
	// End Line: 985

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
 // line 474, offset 0x800617e8
	/* begin block 1 */
		// Start line: 475
		// Start offset: 0x800617E8
		// Variables:
	// 		struct _LoadQueueEntry *currentEntry; // $s0
	/* end block 1 */
	// End offset: 0x800617E8
	// End Line: 475

	/* begin block 2 */
		// Start line: 1009
	/* end block 2 */
	// End Line: 1010

void LOAD_ChangeDirectory(char *name)

{
  _LoadQueueEntry *p_Var1;
  long lVar2;
  
  p_Var1 = STREAM_AddQueueEntryToTail();
  lVar2 = LOAD_HashUnit(name);
  (p_Var1->loadEntry).dirHash = lVar2;
  (p_Var1->loadEntry).fileHash = 0;
  p_Var1->status = 10;
  sprintf((p_Var1->loadEntry).fileName,"dir %s");
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_AbortFileLoad(char *fileName /*$s2*/, void *retFunc /*$s3*/)
 // line 488, offset 0x80061844
	/* begin block 1 */
		// Start line: 489
		// Start offset: 0x80061844

		/* begin block 1.1 */
			// Start line: 492
			// Start offset: 0x8006186C
			// Variables:
		// 		struct _LoadQueueEntry *entry; // $s0
		// 		struct _LoadQueueEntry *prev; // $s1
		// 		long hash; // $v1
		/* end block 1.1 */
		// End offset: 0x80061914
		// End Line: 518
	/* end block 1 */
	// End offset: 0x80061914
	// End Line: 519

	/* begin block 2 */
		// Start line: 1044
	/* end block 2 */
	// End Line: 1045

	/* begin block 3 */
		// Start line: 1045
	/* end block 3 */
	// End Line: 1046

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
        GXFilePrint("Aborting file load %s %x %x %x\n");
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





