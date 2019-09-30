#include "THISDUST.H"
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

/* WARNING: Unknown calling convention yet parameter storage is locked */

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

void STREAM_InitLoader(char *bigFileName,char *voiceFileName)

{
  _LoadQueueEntry *p_Var1;
  _LoadQueueEntry *p_Var2;
  int iVar3;
  
  LOAD_InitCdLoader(bigFileName,voiceFileName);
  iVar3 = 0x26;
  p_Var2 = &_LoadQueueEntry_800da5a0;
  p_Var1 = &_LoadQueueEntry_800da610;
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
  _LoadQueueEntry_800da610.next = (_LoadQueueEntry *)0x0;
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
 // line 73, offset 0x80060244
	/* begin block 1 */
		// Start line: 162
	/* end block 1 */
	// End Line: 163

	/* begin block 2 */
		// Start line: 163
	/* end block 2 */
	// End Line: 164

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

/* WARNING: Unknown calling convention yet parameter storage is locked */

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

/* WARNING: Unknown calling convention yet parameter storage is locked */

int STREAM_PollLoadQueue(void)

{
  _LoadQueueEntry *p_Var1;
  code *pcVar2;
  long *plVar3;
  int voiceIndex;
  
  LOAD_ProcessReadQueue();
  p_Var1 = loadHead;
  if (loadHead != (_LoadQueueEntry *)0x0) {
    if (gameTrackerX.debugFlags < 0) {
                    /* WARNING: Subroutine does not return */
      FONT_Print("%s status %d\n");
    }
    switch((int)(((uint)(ushort)loadHead->status - 1) * 0x10000) >> 0x10) {
    case 0:
                    /* WARNING: Subroutine does not return */
      TIMER_GetTimeMS();
    case 1:
      voiceIndex = LOAD_IsFileLoading();
      if (voiceIndex == 0) {
                    /* WARNING: Subroutine does not return */
        TIMER_GetTimeMS();
      }
      break;
    case 4:
      plVar3 = (long *)LOAD_InitBuffers();
                    /* WARNING: Subroutine does not return */
      (p_Var1->loadEntry).loadAddr = plVar3;
      TIMER_GetTimeMS();
    case 5:
      voiceIndex = LOAD_IsFileLoading();
      if (voiceIndex == 0) {
                    /* WARNING: Subroutine does not return */
        TIMER_GetTimeMS();
      }
      break;
    case 6:
      loadHead->status = 4;
      STREAM_RemoveQueueHead();
      if (p_Var1->mempackUsed != '\0') {
        MEMPACK_SetMemoryDoneStreamed((char *)(p_Var1->loadEntry).loadAddr);
      }
      STREAM_NextLoadFromHead();
      pcVar2 = (code *)(p_Var1->loadEntry).retFunc;
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)((p_Var1->loadEntry).loadAddr,(p_Var1->loadEntry).retData,
                  (p_Var1->loadEntry).retData2);
      }
      break;
    case 7:
      voiceIndex = (loadHead->loadEntry).fileHash;
      loadHead->status = 9;
      VOICEXA_Play(voiceIndex,0);
      break;
    case 8:
      voiceIndex = VOICEXA_IsPlaying();
      if (voiceIndex == 0) {
        LOAD_InitCdStreamMode();
        STREAM_RemoveQueueHead();
      }
      break;
    case 9:
                    /* WARNING: Subroutine does not return */
      TIMER_GetTimeMS();
    case 10:
      voiceIndex = LOAD_IsFileLoading();
      if (voiceIndex == 0) {
                    /* WARNING: Subroutine does not return */
        TIMER_GetTimeMS();
      }
    }
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

_LoadQueueEntry *
STREAM_SetUpQueueEntry
          (char *fileName,void *retFunc,void *retData,void *retData2,void **retPointer,int fromhead)

{
  _LoadQueueEntry *p_Var1;
  
  if (fromhead == 0) {
    p_Var1 = STREAM_AddQueueEntryToTail();
  }
  else {
    p_Var1 = STREAM_AddQueueEntryToHead();
  }
                    /* WARNING: Subroutine does not return */
  strcpy((p_Var1->loadEntry).fileName,fileName);
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

void LOAD_LoadToAddress(char *fileName,void *loadAddr,long relocateBinary)

{
  _LoadQueueEntry *p_Var1;
  
  p_Var1 = STREAM_SetUpQueueEntry(fileName,(void *)0x0,(void *)0x0,(void *)0x0,(void **)0x0,0);
  (p_Var1->loadEntry).loadAddr = loadAddr;
  p_Var1->status = 1;
  p_Var1->relocateBinary = (char)relocateBinary;
  p_Var1->mempackUsed = '\0';
                    /* WARNING: Subroutine does not return */
  STREAM_PollLoadQueue();
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_NonBlockingBinaryLoad(char *fileName /*$a0*/, void *retFunc /*$t0*/, void *retData /*$t1*/, void *retData2 /*$a3*/, void **retPointer /*stack 16*/, int memType /*stack 20*/)
 // line 462, offset 0x80060920
	/* begin block 1 */
		// Start line: 975
	/* end block 1 */
	// End Line: 976

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
    p_Var1 = p_Var1 + 1;
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

long * LOAD_ReadFile(char *fileName,uchar memType)

{
  void *local_10 [2];
  
  STREAM_QueueNonblockingLoads(fileName,memType,(void *)0x0,(void *)0x0,(void *)0x0,local_10,0);
                    /* WARNING: Subroutine does not return */
  STREAM_PollLoadQueue();
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

void LOAD_ChangeDirectory(char *name)

{
  _LoadQueueEntry *p_Var1;
  
  p_Var1 = STREAM_AddQueueEntryToTail();
  gCurDir = LOAD_HashUnit(name);
  (p_Var1->loadEntry).dirHash = gCurDir;
  (p_Var1->loadEntry).fileHash = 0;
                    /* WARNING: Subroutine does not return */
  p_Var1->status = 10;
  sprintf((p_Var1->loadEntry).fileName,GlobalObjects);
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





