#include "THISDUST.H"
#include "LOAD3D.H"


// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_InitCd()
 // line 231, offset 0x800372c8
	/* begin block 1 */
		// Start line: 279
	/* end block 1 */
	// End Line: 280

	/* begin block 2 */
		// Start line: 462
	/* end block 2 */
	// End Line: 463

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_InitCd(void)

{
  CdInit();
  ResetCallback();
  CdSetDebug(0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_CdSeekCallback(unsigned char intr /*$a0*/, unsigned char *result /*$a1*/)
 // line 255, offset 0x800372f8
	/* begin block 1 */
		// Start line: 327
	/* end block 1 */
	// End Line: 328

void LOAD_CdSeekCallback(uchar intr,uchar *result)

{
  uint uVar1;
  
  if (loadStatus.state == 1) {
    loadStatus.state = 2;
    uVar1 = GetRCnt(0xf2000000);
    crap1 = uVar1 & 0xffff | gameTimer << 0x10;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_CdDataReady()
 // line 267, offset 0x80037344
	/* begin block 1 */
		// Start line: 268
		// Start offset: 0x80037344

		/* begin block 1.1 */
			// Start line: 275
			// Start offset: 0x80037380
			// Variables:
		// 		struct _ReadQueueEntry *currentQueueFile; // $s0
		// 		long actualReadSize; // $a1

			/* begin block 1.1.1 */
				// Start line: 292
				// Start offset: 0x800373E4
				// Variables:
			// 		int status; // $s1
			/* end block 1.1.1 */
			// End offset: 0x80037450
			// End Line: 324
		/* end block 1.1 */
		// End offset: 0x80037450
		// End Line: 325
	/* end block 1 */
	// End offset: 0x80037450
	// End Line: 330

	/* begin block 2 */
		// Start line: 353
	/* end block 2 */
	// End Line: 354

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_CdDataReady(void)

{
  int iVar1;
  
  if (loadStatus.state == 3) {
    loadStatus.state = 4;
  }
  else {
    if (loadStatus.state == 4) {
      loadStatus.currentQueueFile.readCurSize =
           loadStatus.currentQueueFile.readCurSize + loadStatus.bytesTransferred;
      if (loadStatus.currentQueueFile.readStatus == 3) {
        loadStatus.currentQueueFile.readCurDest =
             (void *)((int)loadStatus.currentQueueFile.readCurDest + loadStatus.bytesTransferred);
        if (loadStatus.currentQueueFile.readCurSize == loadStatus.currentQueueFile.readSize) {
          loadStatus.state = 5;
        }
        else {
          loadStatus.state = 2;
        }
      }
      else {
        if (loadStatus.currentQueueFile.readStatus == 6) {
          iVar1 = 2;
          if (loadStatus.currentQueueFile.readCurSize == loadStatus.currentQueueFile.readSize) {
            iVar1 = 5;
          }
          if (loadStatus.currentQueueFile.retFunc != (void *)0x0) {
            (*(code *)loadStatus.currentQueueFile.retFunc)
                      (loadStatus.currentQueueFile.readCurDest,loadStatus.bytesTransferred,
                       (uint)(iVar1 == 5),loadStatus.currentQueueFile.retData,
                       loadStatus.currentQueueFile.retData2);
          }
          loadStatus.state = iVar1;
          if (loadStatus.currentQueueFile.readCurDest == loadStatus.buffer1) {
            loadStatus.currentQueueFile.readCurDest = loadStatus.buffer2;
          }
          else {
            loadStatus.currentQueueFile.readCurDest = loadStatus.buffer1;
          }
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_CdReadReady(unsigned char intr /*$a0*/, unsigned char *result /*$a1*/)
 // line 333, offset 0x80037464
	/* begin block 1 */
		// Start line: 334
		// Start offset: 0x80037464
		// Variables:
	// 		static int crap; // offset 0x0

		/* begin block 1.1 */
			// Start line: 344
			// Start offset: 0x80037490
			// Variables:
		// 		long crap[3]; // stack offset -40
		// 		int bytes; // $s0

			/* begin block 1.1.1 */
				// Start line: 366
				// Start offset: 0x80037504
				// Variables:
			// 		struct CdlLOC loc; // stack offset -24
			/* end block 1.1.1 */
			// End offset: 0x80037504
			// End Line: 369
		/* end block 1.1 */
		// End offset: 0x80037504
		// End Line: 369
	/* end block 1 */
	// End offset: 0x8003757C
	// End Line: 391

	/* begin block 2 */
		// Start line: 490
	/* end block 2 */
	// End Line: 491

void LOAD_CdReadReady(uchar intr,uchar *result)

{
  uint uVar1;
  int iVar2;
  byte abStack40 [16];
  byte abStack24 [8];
  
  if (loadStatus.state == 2) {
    if (intr == '\x01') {
      uVar1 = loadStatus.currentQueueFile.readSize - loadStatus.currentQueueFile.readCurSize;
      if (0x7ff < (int)uVar1) {
        uVar1 = 0x800;
      }
      loadStatus.state = 4;
      loadStatus.bytesTransferred = uVar1;
      CdGetSector((dword)abStack40,3);
      iVar2 = CdPosToInt(abStack40);
      if (loadStatus.currentSector == iVar2) {
        loadStatus.currentSector = loadStatus.currentSector + 1;
        CdGetSector((dword)loadStatus.currentQueueFile.readCurDest,uVar1 >> 2);
        LOAD_CdDataReady();
      }
      else {
        loadStatus.state = (uint)intr;
        CdIntToPos(loadStatus.currentSector,(char *)abStack24);
        CdControl(6,abStack24,(undefined *)0x0);
      }
    }
    else {
      if (intr == '\x05') {
        loadStatus.state = 6;
        loadStatus.currentQueueFile.readStatus = 4;
      }
      else {
        printf("something %x\n");
      }
    }
  }
  if (crap1 != 0) {
    loadStatus.seekTime = TIMER_TimeDiff(crap1);
    crap1 = 0;
  }
  loadStatus.sectorTime = TIMER_TimeDiff(crap_35);
  uVar1 = GetRCnt(0xf2000000);
  crap_35 = uVar1 & 0xffff | gameTimer << 0x10;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_UpdateCheckSum(long bytes /*$a1*/)
 // line 396, offset 0x800375c0
	/* begin block 1 */
		// Start line: 633
	/* end block 1 */
	// End Line: 634

	/* begin block 2 */
		// Start line: 636
	/* end block 2 */
	// End Line: 637

void LOAD_UpdateCheckSum(long bytes)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if ((loadStatus.currentQueueFile.checksumType == 1) && (iVar3 = bytes + -4, bytes != 0)) {
    do {
      iVar2 = *loadStatus.checkAddr;
      loadStatus.checkAddr = loadStatus.checkAddr + 1;
      loadStatus.checksum = loadStatus.checksum + iVar2;
      bVar1 = iVar3 != 0;
      iVar3 = iVar3 + -4;
    } while (bVar1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_DoCDReading()
 // line 411, offset 0x80037604
	/* begin block 1 */
		// Start line: 412
		// Start offset: 0x80037604
		// Variables:
	// 		long bytesLoaded; // $a0
	// 		long readSoFar; // $v0
	// 		long state; // $s0
	// 		long lastCheck; // $v1
	/* end block 1 */
	// End offset: 0x800376A0
	// End Line: 506

	/* begin block 2 */
		// Start line: 666
	/* end block 2 */
	// End Line: 667

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_DoCDReading(void)

{
  long lVar1;
  int bytes;
  
  lVar1 = loadStatus.state;
  bytes = loadStatus.currentQueueFile.readCurSize - loadStatus.lastCheckPos;
  loadStatus.lastCheckPos = loadStatus.currentQueueFile.readCurSize;
  if ((bytes != 0) && (loadStatus.currentQueueFile.checksumType != 0)) {
    LOAD_UpdateCheckSum(bytes);
  }
  if (lVar1 == 5) {
    if ((loadStatus.currentQueueFile.checksumType == 0) ||
       (loadStatus.checksum == loadStatus.currentQueueFile.checksum)) {
      loadStatus.currentQueueFile.readStatus = 0;
      if (loadStatus.currentDirLoading != 0) {
        loadStatus.currentDirLoading = 0;
        MEMPACK_SetMemoryDoneStreamed((char *)loadStatus.bigFile.currentDir);
      }
    }
    else {
      loadStatus.currentQueueFile.readStatus = 7;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_DoCDBufferedReading()
 // line 513, offset 0x800376b0
	/* begin block 1 */
		// Start line: 878
	/* end block 1 */
	// End Line: 879

	/* begin block 2 */
		// Start line: 880
	/* end block 2 */
	// End Line: 881

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_DoCDBufferedReading(void)

{
  if (loadStatus.state == 5) {
    loadStatus.currentQueueFile.readStatus = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_SetupFileToDoCDReading()
 // line 524, offset 0x800376cc
	/* begin block 1 */
		// Start line: 525
		// Start offset: 0x800376CC

		/* begin block 1.1 */
			// Start line: 525
			// Start offset: 0x800376CC
			// Variables:
		// 		struct CdlLOC loc; // stack offset -16
		/* end block 1.1 */
		// End offset: 0x80037708
		// End Line: 540
	/* end block 1 */
	// End offset: 0x80037708
	// End Line: 541

	/* begin block 2 */
		// Start line: 900
	/* end block 2 */
	// End Line: 901

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_SetupFileToDoCDReading(void)

{
  long lVar1;
  byte abStack16 [8];
  
  loadStatus.currentQueueFile.readStatus = 3;
  loadStatus.checksum = 0;
  loadStatus.lastCheckPos = 0;
  loadStatus.state = 1;
  loadStatus.currentQueueFile.readCurDest = loadStatus.currentQueueFile.readStartDest;
  loadStatus.checkAddr = (long *)loadStatus.currentQueueFile.readStartDest;
  lVar1 = loadStatus.currentQueueFile.readStartPos;
  if (loadStatus.currentQueueFile.readStartPos < 0) {
    lVar1 = loadStatus.currentQueueFile.readStartPos + 0x7ff;
  }
  loadStatus.currentSector = loadStatus.bigFile.bigfileBaseOffset + (lVar1 >> 0xb);
  CdIntToPos(loadStatus.currentSector,(char *)abStack16);
  CdControl(6,abStack16,(undefined *)0x0);
  loadStatus.cdWaitTime = TIMER_GetTimeMS();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_SetupFileToDoBufferedCDReading()
 // line 599, offset 0x80037748
	/* begin block 1 */
		// Start line: 600
		// Start offset: 0x80037748

		/* begin block 1.1 */
			// Start line: 600
			// Start offset: 0x80037748
			// Variables:
		// 		struct CdlLOC loc; // stack offset -16
		/* end block 1.1 */
		// End offset: 0x8003777C
		// End Line: 616
	/* end block 1 */
	// End offset: 0x8003777C
	// End Line: 617

	/* begin block 2 */
		// Start line: 1092
	/* end block 2 */
	// End Line: 1093

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_SetupFileToDoBufferedCDReading(void)

{
  long lVar1;
  byte abStack16 [8];
  
  loadStatus.currentQueueFile.readStatus = 6;
  loadStatus.checksum = 0;
  loadStatus.state = 1;
  loadStatus.checkAddr = (long *)loadStatus.currentQueueFile.readStartDest;
  lVar1 = loadStatus.currentQueueFile.readStartPos;
  if (loadStatus.currentQueueFile.readStartPos < 0) {
    lVar1 = loadStatus.currentQueueFile.readStartPos + 0x7ff;
  }
  loadStatus.currentSector = loadStatus.bigFile.bigfileBaseOffset + (lVar1 >> 0xb);
  CdIntToPos(loadStatus.currentSector,(char *)abStack16);
  CdControl(6,abStack16,(undefined *)0x0);
  loadStatus.cdWaitTime = TIMER_GetTimeMS();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_ProcessReadQueue()
 // line 624, offset 0x800377bc
	/* begin block 1 */
		// Start line: 625
		// Start offset: 0x800377BC

		/* begin block 1.1 */
			// Start line: 665
			// Start offset: 0x800378A4
			// Variables:
		// 		long cdWaitTimeDiff; // $v0

			/* begin block 1.1.1 */
				// Start line: 671
				// Start offset: 0x800378E4
				// Variables:
			// 		struct CdlLOC loc; // stack offset -16
			/* end block 1.1.1 */
			// End offset: 0x800378E4
			// End Line: 672
		/* end block 1.1 */
		// End offset: 0x80037950
		// End Line: 696
	/* end block 1 */
	// End offset: 0x80037950
	// End Line: 698

	/* begin block 2 */
		// Start line: 1178
	/* end block 2 */
	// End Line: 1179

	/* begin block 3 */
		// Start line: 1184
	/* end block 3 */
	// End Line: 1185

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_ProcessReadQueue(void)

{
  ulong uVar1;
  int iVar2;
  byte abStack16 [8];
  
  if (gameTrackerX.debugFlags < 0) {
    FONT_Print("CD St %d LS %d sk %d tm %d rd %d cs %d\n");
  }
  if (loadStatus.currentQueueFile.readStatus == 3) {
    LOAD_DoCDReading();
  }
  else {
    if (loadStatus.currentQueueFile.readStatus < 4) {
      if (loadStatus.currentQueueFile.readStatus == 1) {
        LOAD_SetupFileToDoCDReading();
      }
    }
    else {
      if (loadStatus.currentQueueFile.readStatus == 5) {
        LOAD_SetupFileToDoBufferedCDReading();
      }
      else {
        if (loadStatus.currentQueueFile.readStatus == 6) {
          LOAD_DoCDBufferedReading();
        }
      }
    }
  }
  if (loadStatus.currentQueueFile.readStatus == 7) {
    loadStatus.currentQueueFile.readStatus = 1;
  }
  else {
    if ((loadStatus.cdWaitTime != 0) &&
       (uVar1 = TIMER_GetTimeMS(), 0x20d0 < (int)(uVar1 - loadStatus.cdWaitTime))) {
      if ((loadStatus.currentQueueFile.readStatus == 3) ||
         (loadStatus.currentQueueFile.readStatus == 6)) {
        loadStatus.state = 0;
        CdReset(0);
        LOAD_InitCdStreamMode();
        loadStatus.state = 1;
        CdIntToPos(loadStatus.currentSector,(char *)abStack16);
        CdControl(6,abStack16,(undefined *)0x0);
        loadStatus.cdWaitTime = TIMER_GetTimeMS();
      }
      else {
        iVar2 = VOICEXA_IsPlaying();
        if (iVar2 == 0) {
          CdControlF(9,(byte *)0x0);
        }
        loadStatus.cdWaitTime = 0;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// char * /*$ra*/ LOAD_ReadFileFromCD(char *filename /*$s1*/, int memType /*$s2*/)
 // line 702, offset 0x80037960
	/* begin block 1 */
		// Start line: 703
		// Start offset: 0x80037960
		// Variables:
	// 		struct CdlFILE fp; // stack offset -40
	// 		int i; // $s0
	// 		char *readBuffer; // $s0
	/* end block 1 */
	// End offset: 0x80037A28
	// End Line: 747

	/* begin block 2 */
		// Start line: 1341
	/* end block 2 */
	// End Line: 1342

char * LOAD_ReadFileFromCD(char *filename,int memType)

{
  undefined4 *puVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uStack40;
  ulong local_24;
  
  iVar4 = 0;
  do {
    puVar1 = CdSearchFile(&uStack40,filename);
    if (puVar1 != (undefined4 *)0x0) break;
    CdReset(0);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 10);
  pcVar3 = (char *)0x0;
  if (iVar4 != 10) {
    pcVar2 = MEMPACK_Malloc(local_24,(uchar)memType);
    pcVar3 = (char *)0x0;
    if (pcVar2 != (char *)0x0) {
      iVar4 = CdPosToInt((byte *)&uStack40);
      loadStatus.currentQueueFile.readCurSize = 0;
      loadStatus.currentQueueFile.readStatus = 1;
      loadStatus.currentQueueFile.checksumType = 0;
      loadStatus.currentQueueFile.checksum = 0;
      loadStatus.currentQueueFile.readStartPos =
           (iVar4 - loadStatus.bigFile.bigfileBaseOffset) * 0x800;
      loadStatus.currentQueueFile.readSize = local_24;
      loadStatus.currentQueueFile.readStartDest = pcVar2;
      do {
        LOAD_ProcessReadQueue();
        iVar4 = LOAD_IsFileLoading();
      } while (iVar4 != 0);
      CdControlF(9,(byte *)0x0);
      pcVar3 = pcVar2;
    }
  }
  return pcVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_CdReadFromBigFile(long fileOffset /*$a0*/, unsigned long *loadAddr /*$a1*/, long bytes /*$a2*/, long chksumLevel /*$a3*/, long checksum /*stack 16*/)
 // line 749, offset 0x80037a40
	/* begin block 1 */
		// Start line: 1454
	/* end block 1 */
	// End Line: 1455

void LOAD_CdReadFromBigFile
               (long fileOffset,ulong *loadAddr,long bytes,long chksumLevel,long checksum)

{
  loadStatus.currentQueueFile.readStartPos = fileOffset;
  loadStatus.currentQueueFile.readSize = bytes;
  loadStatus.currentQueueFile.readCurSize = 0;
  loadStatus.currentQueueFile.readStartDest = loadAddr;
  loadStatus.currentQueueFile.readStatus = 1;
  loadStatus.currentQueueFile.checksum = checksum;
  loadStatus.currentQueueFile.checksumType = chksumLevel;
  return;
}



// decompiled code
// original method signature: 
// struct _BigFileDir * /*$ra*/ LOAD_ReadDirectory(struct _BigFileDirEntry *dirEntry /*$s0*/)
 // line 762, offset 0x80037a6c
	/* begin block 1 */
		// Start line: 763
		// Start offset: 0x80037A6C
		// Variables:
	// 		struct _BigFileDir *dir; // $s2
	// 		long sizeOfDir; // $s1
	/* end block 1 */
	// End offset: 0x80037A6C
	// End Line: 763

	/* begin block 2 */
		// Start line: 1484
	/* end block 2 */
	// End Line: 1485

_BigFileDir * LOAD_ReadDirectory(_BigFileDirEntry *dirEntry)

{
  _BigFileDir *loadAddr;
  ulong allocSize;
  
  allocSize = (int)dirEntry->numFiles * 0x10 + 4;
  loadAddr = (_BigFileDir *)MEMPACK_Malloc(allocSize,',');
  LOAD_CdReadFromBigFile(dirEntry->subDirOffset,(ulong *)loadAddr,allocSize,0,0);
  return loadAddr;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_InitCdLoader(char *bigFileName /*$s0*/, char *voiceFileName /*$a1*/)
 // line 824, offset 0x80037ad4
	/* begin block 1 */
		// Start line: 825
		// Start offset: 0x80037AD4
		// Variables:
	// 		struct CdlFILE fp; // stack offset -40
	// 		long i; // $s1

		/* begin block 1.1 */
			// Start line: 892
			// Start offset: 0x80037B84
			// Variables:
		// 		char *ptr; // $s0
		/* end block 1.1 */
		// End offset: 0x80037BEC
		// End Line: 916
	/* end block 1 */
	// End offset: 0x80037C14
	// End Line: 928

	/* begin block 2 */
		// Start line: 1610
	/* end block 2 */
	// End Line: 1611

void LOAD_InitCdLoader(char *bigFileName,char *voiceFileName)

{
  undefined4 *puVar1;
  ulong *loadAddr;
  int iVar2;
  ulong allocSize;
  undefined4 auStack40 [6];
  
  iVar2 = 0;
  loadStatus.state = 0;
  do {
    puVar1 = CdSearchFile(auStack40,bigFileName);
    if (puVar1 != (undefined4 *)0x0) break;
    CdReset(0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 10);
  if (iVar2 != 10) {
    LOAD_InitCdStreamMode();
    loadStatus.bigFile.bigfileBaseOffset = CdPosToInt((byte *)auStack40);
    loadStatus.cdWaitTime = 0;
    loadStatus.currentQueueFile.readStatus = 0;
    loadStatus.bigFile.currentDir = (_BigFileDir *)0x0;
    loadStatus.bigFile.currentDirID = 0;
    loadStatus.bigFile.cachedDir = (_BigFileDir *)0x0;
    loadStatus.bigFile.cachedDirID = 0;
    loadStatus.bigFile.searchDirID = 0;
    LOAD_CdReadFromBigFile(0,(ulong *)&loadStatus.bigFile.numSubDirs,4,0,0);
    do {
      LOAD_ProcessReadQueue();
      iVar2 = LOAD_IsFileLoading();
    } while (iVar2 != 0);
    CdControlF(9,(byte *)0x0);
    allocSize = loadStatus.bigFile.numSubDirs * 8 + 4;
    loadAddr = (ulong *)MEMPACK_Malloc(allocSize,'\b');
    CdSync(0,(undefined *)0x0);
    LOAD_CdReadFromBigFile(0,loadAddr,allocSize,0,0);
    loadStatus.bigFile.subDirList = (_BigFileDirEntry *)(loadAddr + 1);
    do {
      LOAD_ProcessReadQueue();
      iVar2 = LOAD_IsFileLoading();
    } while (iVar2 != 0);
    loadStatus.bigFile.rootDir = LOAD_ReadDirectory(loadStatus.bigFile.subDirList);
    do {
      LOAD_ProcessReadQueue();
      iVar2 = LOAD_IsFileLoading();
    } while (iVar2 != 0);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ LOAD_SetupFileInfo(struct _NonBlockLoadEntry *loadEntry /*$s0*/)
 // line 930, offset 0x80037c28
	/* begin block 1 */
		// Start line: 931
		// Start offset: 0x80037C28
		// Variables:
	// 		struct _BigFileEntry *fileInfo; // $v1
	/* end block 1 */
	// End offset: 0x80037CA0
	// End Line: 954

	/* begin block 2 */
		// Start line: 1872
	/* end block 2 */
	// End Line: 1873

int LOAD_SetupFileInfo(_NonBlockLoadEntry *loadEntry)

{
  _BigFileEntry *p_Var1;
  int iVar2;
  
  p_Var1 = LOAD_GetBigFileEntryByHash(loadEntry->fileHash);
  if (p_Var1 == (_BigFileEntry *)0x0) {
    iVar2 = 0;
    if (loadEntry->dirHash == loadStatus.bigFile.currentDirID) {
      DEBUG_FatalError("CD ERROR: File %s does not exist\n");
      iVar2 = 0;
    }
  }
  else {
    loadEntry->filePos = p_Var1->filePos;
    loadEntry->loadSize = p_Var1->fileLen;
    iVar2 = 1;
    loadEntry->checksum = p_Var1->checkSumFull;
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_NonBlockingReadFile(struct _NonBlockLoadEntry *loadEntry /*$s0*/)
 // line 957, offset 0x80037cb0
	/* begin block 1 */
		// Start line: 1927
	/* end block 1 */
	// End Line: 1928

void LOAD_NonBlockingReadFile(_NonBlockLoadEntry *loadEntry)

{
  int iVar1;
  long *plVar2;
  
  iVar1 = LOAD_SetupFileInfo(loadEntry);
  if (iVar1 == 0) {
    loadStatus.changeDir = 1;
  }
  else {
    if (loadEntry->loadAddr == (long *)0x0) {
      plVar2 = (long *)MEMPACK_Malloc(loadEntry->loadSize,*(uchar *)&loadEntry->memType);
      loadEntry->loadAddr = plVar2;
    }
    LOAD_CdReadFromBigFile
              (loadEntry->filePos,(ulong *)loadEntry->loadAddr,loadEntry->loadSize,
               loadEntry->checksumType,loadEntry->checksum);
    loadStatus.changeDir = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_CD_ReadPartOfFile(struct _NonBlockLoadEntry *loadEntry /*$s0*/)
 // line 977, offset 0x80037d34
	/* begin block 1 */
		// Start line: 978
		// Start offset: 0x80037D34
		// Variables:
	// 		struct _ReadQueueEntry *currentQueueReq; // $v1
	/* end block 1 */
	// End offset: 0x80037DC4
	// End Line: 1003

	/* begin block 2 */
		// Start line: 1967
	/* end block 2 */
	// End Line: 1968

void LOAD_CD_ReadPartOfFile(_NonBlockLoadEntry *loadEntry)

{
  int iVar1;
  
  iVar1 = LOAD_SetupFileInfo(loadEntry);
  if (iVar1 != 0) {
    loadStatus.currentQueueFile.readSize = loadEntry->loadSize;
    loadStatus.currentQueueFile.readCurSize = 0;
    loadStatus.currentQueueFile.readStartDest = loadEntry->loadAddr;
    loadStatus.currentQueueFile.readCurDest = loadEntry->loadAddr;
    loadStatus.currentQueueFile.readStartPos = loadEntry->filePos;
    loadStatus.currentQueueFile.readStatus = 5;
    loadStatus.currentQueueFile.checksumType = 0;
    loadStatus.currentQueueFile.checksum = loadEntry->checksum;
    loadStatus.currentQueueFile.retFunc = loadEntry->retFunc;
    loadStatus.currentQueueFile.retData = loadEntry->retData;
    loadStatus.currentQueueFile.retData2 = loadEntry->retData2;
  }
  loadStatus.changeDir = ZEXT14(iVar1 == 0);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ LOAD_HashName(char *string /*stack 0*/)
 // line 1016, offset 0x80037dd4
	/* begin block 1 */
		// Start line: 1017
		// Start offset: 0x80037DD4
		// Variables:
	// 		long sum; // $s5
	// 		long xor; // $s6
	// 		long length; // $s4
	// 		long ext; // $s7
	// 		char c; // $v1
	// 		long strl; // $s2
	// 		long endPos; // $fp
	// 		long i; // $s0
	// 		char *pos; // $s3
	/* end block 1 */
	// End offset: 0x80037EE4
	// End Line: 1060

	/* begin block 2 */
		// Start line: 2053
	/* end block 2 */
	// End Line: 2054

long LOAD_HashName(char *string)

{
  size_t sVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char *s2;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  iVar7 = 0;
  uVar8 = 0;
  iVar6 = 0;
  sVar1 = strlen(string);
  iVar5 = sVar1 - 1;
  pcVar2 = strchr(string,0x2e);
  uVar9 = 0;
  if (pcVar2 != (char *)0x0) {
    uVar4 = 0;
    s2 = "drm";
    do {
      iVar3 = strcmpi(pcVar2 + 1,s2);
      uVar9 = uVar4;
      if (iVar3 == 0) break;
      uVar4 = uVar4 + 1;
      s2 = s2 + 4;
      uVar9 = 0;
    } while ((int)uVar4 < 7);
    if ((int)uVar4 < 7) {
      iVar5 = sVar1 - 5;
    }
  }
  uVar4 = 0;
  while (-1 < iVar5) {
    uVar4 = (uint)(byte)string[iVar5];
    if (string[iVar5] != 0x5c) {
      if (uVar4 - 0x61 < 0x1a) {
        uVar4 = uVar4 & 0xdf;
      }
      uVar4 = uVar4 - 0x1a & 0xff;
      uVar10 = uVar4 * iVar6;
      iVar7 = iVar7 + uVar4;
      iVar6 = iVar6 + 1;
      uVar8 = uVar8 ^ uVar10;
    }
    iVar5 = iVar5 + -1;
    uVar4 = iVar6 << 0x1b;
  }
  return uVar4 | iVar7 << 0xf | uVar8 << 3 | uVar9;
}



// decompiled code
// original method signature: 
// long /*$ra*/ LOAD_HashUnit(char *name /*$a0*/)
 // line 1063, offset 0x80037f28
	/* begin block 1 */
		// Start line: 1065
		// Start offset: 0x80037F28
		// Variables:
	// 		int val; // $v1
	// 		int last; // $t0
	// 		int hash; // $a2
	// 		int num; // $a3
	// 		int flag; // $t1
	// 		char *c; // $a0
	/* end block 1 */
	// End offset: 0x80037FBC
	// End Line: 1099

	/* begin block 2 */
		// Start line: 2160
	/* end block 2 */
	// End Line: 2161

	/* begin block 3 */
		// Start line: 2161
	/* end block 3 */
	// End Line: 2162

	/* begin block 4 */
		// Start line: 2162
	/* end block 4 */
	// End Line: 2163

long LOAD_HashUnit(char *name)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = 0;
  iVar8 = 0;
  bVar1 = *name;
  bVar2 = false;
  uVar3 = 0;
  while (bVar1 != 0) {
    uVar5 = (uint)(byte)*name;
    if (uVar5 - 0x30 < 10) {
      iVar8 = iVar8 * 10 + -0x30 + uVar5;
      uVar6 = uVar3;
    }
    else {
      uVar6 = uVar5 - 0x61;
      if (uVar5 - 0x41 < 0x1a) {
        uVar6 = uVar5 - 0x41;
      }
      if (bVar2) {
        iVar4 = (uVar6 - uVar3) * 0x20;
      }
      else {
        iVar4 = uVar6 - uVar3;
      }
      iVar7 = iVar7 * 4 + iVar4;
      bVar2 = (bool)(bVar2 ^ 1);
    }
    name = (char *)((byte *)name + 1);
    bVar1 = *name;
    uVar3 = uVar6;
  }
  return (iVar7 + iVar8) * 0x10000 >> 0x10;
}



// decompiled code
// original method signature: 
// struct _BigFileEntry * /*$ra*/ LOAD_GetBigFileEntryByHash(long hash /*$a0*/)
 // line 1104, offset 0x80037fcc
	/* begin block 1 */
		// Start line: 1106
		// Start offset: 0x80037FCC
		// Variables:
	// 		int i; // $a1
	// 		struct _BigFileEntry *entry; // $v1
	/* end block 1 */
	// End offset: 0x8003804C
	// End Line: 1125

	/* begin block 2 */
		// Start line: 2265
	/* end block 2 */
	// End Line: 2266

	/* begin block 3 */
		// Start line: 2266
	/* end block 3 */
	// End Line: 2267

	/* begin block 4 */
		// Start line: 2269
	/* end block 4 */
	// End Line: 2270

_BigFileEntry * LOAD_GetBigFileEntryByHash(long hash)

{
  _BigFileEntry *p_Var1;
  int iVar2;
  
  if ((loadStatus.bigFile.currentDir != (_BigFileDir *)0x0) && (loadStatus.currentDirLoading == 0))
  {
    iVar2 = (loadStatus.bigFile.currentDir)->numFiles;
    p_Var1 = (_BigFileEntry *)(loadStatus.bigFile.currentDir + 1);
    while (iVar2 != 0) {
      iVar2 = iVar2 + -1;
      if (p_Var1->fileHash == hash) {
        return p_Var1;
      }
      p_Var1 = p_Var1 + 1;
    }
  }
  iVar2 = (loadStatus.bigFile.rootDir)->numFiles;
  p_Var1 = (_BigFileEntry *)(loadStatus.bigFile.rootDir + 1);
  while( true ) {
    if (iVar2 == 0) {
      return (_BigFileEntry *)0x0;
    }
    iVar2 = iVar2 + -1;
    if (p_Var1->fileHash == hash) break;
    p_Var1 = p_Var1 + 1;
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct _BigFileEntry * /*$ra*/ LOAD_GetBigFileEntry(char *fileName /*$a0*/)
 // line 1127, offset 0x80038054
	/* begin block 1 */
		// Start line: 1128
		// Start offset: 0x80038054
	/* end block 1 */
	// End offset: 0x80038054
	// End Line: 1128

	/* begin block 2 */
		// Start line: 2316
	/* end block 2 */
	// End Line: 2317

_BigFileEntry * LOAD_GetBigFileEntry(char *fileName)

{
  long hash;
  _BigFileEntry *p_Var1;
  
  hash = LOAD_HashName(fileName);
  p_Var1 = LOAD_GetBigFileEntryByHash(hash);
  return p_Var1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ LOAD_DoesFileExist(char *fileName /*$a0*/)
 // line 1183, offset 0x8003807c
	/* begin block 1 */
		// Start line: 1184
		// Start offset: 0x8003807C
		// Variables:
	// 		struct _BigFileEntry *entry; // $v0
	/* end block 1 */
	// End offset: 0x800380A0
	// End Line: 1189

	/* begin block 2 */
		// Start line: 2366
	/* end block 2 */
	// End Line: 2367

long LOAD_DoesFileExist(char *fileName)

{
  _BigFileEntry *p_Var1;
  uint uVar2;
  
  p_Var1 = LOAD_GetBigFileEntry(fileName);
  uVar2 = 0;
  if (p_Var1 != (_BigFileEntry *)0x0) {
    uVar2 = (uint)(p_Var1->fileLen != 0);
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_LoadTIM(long *addr /*$a1*/, long x_pos /*$t0*/, long y_pos /*$a2*/, long clut_x /*$s1*/, long clut_y /*stack 16*/)
 // line 1194, offset 0x800380b0
	/* begin block 1 */
		// Start line: 1195
		// Start offset: 0x800380B0
		// Variables:
	// 		struct RECT rect; // stack offset -24
	// 		long *clutAddr; // $s0
	/* end block 1 */
	// End offset: 0x8003813C
	// End Line: 1224

	/* begin block 2 */
		// Start line: 2400
	/* end block 2 */
	// End Line: 2401

void LOAD_LoadTIM(long *addr,long x_pos,long y_pos,long clut_x,long clut_y)

{
  long *plVar1;
  long *plVar2;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  
  plVar1 = addr + 2;
  plVar2 = (long *)0x0;
  if (addr[1] == 8) {
    plVar2 = addr + 5;
    plVar1 = addr + 0xd;
  }
  local_18 = (undefined2)x_pos;
  local_16 = (undefined2)y_pos;
  local_14 = *(undefined2 *)(plVar1 + 2);
  local_12 = *(undefined2 *)((int)plVar1 + 10);
  LoadImage((undefined4 *)&local_18,plVar1 + 3);
  if (plVar2 != (long *)0x0) {
    local_18 = (undefined2)clut_x;
    local_16 = (undefined2)clut_y;
    local_14 = 0x10;
    local_12 = 1;
    DrawSync(0);
    LoadImage((undefined4 *)&local_18,plVar2);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_LoadTIM2(long *addr /*$a1*/, long x_pos /*$a1*/, long y_pos /*$a2*/, long width /*$a3*/, long height /*stack 16*/)
 // line 1226, offset 0x80038150
	/* begin block 1 */
		// Start line: 1227
		// Start offset: 0x80038150
		// Variables:
	// 		struct RECT rect; // stack offset -16
	/* end block 1 */
	// End offset: 0x80038150
	// End Line: 1227

	/* begin block 2 */
		// Start line: 2472
	/* end block 2 */
	// End Line: 2473

void LOAD_LoadTIM2(long *addr,long x_pos,long y_pos,long width,long height)

{
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  local_10 = (undefined2)x_pos;
  local_e = (undefined2)y_pos;
  local_c = *(undefined2 *)(addr + 4);
  local_a = *(undefined2 *)((int)addr + 0x12);
  LoadImage((undefined4 *)&local_10,addr + 5);
  DrawSync(0);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ LOAD_RelocBinaryData(long *data /*$s0*/, long fileSize /*$s1*/)
 // line 1264, offset 0x80038198
	/* begin block 1 */
		// Start line: 1265
		// Start offset: 0x80038198
		// Variables:
	// 		long *lastMoveDest; // $v1
	// 		long tableSize; // $s3
	// 		struct RedirectList redirectListX; // stack offset -32
	// 		struct RedirectList *redirectList; // $a0
	/* end block 1 */
	// End offset: 0x80038230
	// End Line: 1285

	/* begin block 2 */
		// Start line: 2528
	/* end block 2 */
	// End Line: 2529

long LOAD_RelocBinaryData(long *data,long fileSize)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  RedirectList local_20;
  
  local_20.data = data + 1;
  local_20.numPointers = *data;
  iVar1 = local_20.numPointers + 0x200;
  if (iVar1 < 0) {
    iVar1 = local_20.numPointers + 0x3ff;
  }
  iVar1 = iVar1 >> 9;
  RESOLVE_Pointers(&local_20,data + iVar1 * 0x200,data);
  plVar3 = data + (fileSize + 3 >> 2) + iVar1 * -0x200;
  if (data < plVar3) {
    plVar2 = data + iVar1 * 0x200;
    do {
      *data = *plVar2;
      data = data + 1;
      plVar2 = data + iVar1 * 0x200;
    } while (data < plVar3);
  }
  return iVar1 << 0xb;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_CleanUpBuffers()
 // line 1357, offset 0x80038250
	/* begin block 1 */
		// Start line: 2714
	/* end block 1 */
	// End Line: 2715

	/* begin block 2 */
		// Start line: 2658
	/* end block 2 */
	// End Line: 2659

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_CleanUpBuffers(void)

{
  if (loadStatus.buffer1 != (void *)0x0) {
    MEMPACK_Free((char *)loadStatus.buffer1);
    loadStatus.buffer1 = (void *)0x0;
  }
  if (loadStatus.buffer2 != (void *)0x0) {
    MEMPACK_Free((char *)loadStatus.buffer2);
    loadStatus.buffer2 = (void *)0x0;
  }
  return;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ LOAD_InitBuffers()
 // line 1371, offset 0x80038298
	/* begin block 1 */
		// Start line: 2686
	/* end block 1 */
	// End Line: 2687

/* WARNING: Unknown calling convention yet parameter storage is locked */

void * LOAD_InitBuffers(void)

{
  loadStatus.buffer1 = MEMPACK_Malloc(0x800,'#');
  loadStatus.buffer2 = MEMPACK_Malloc(0x800,'#');
  return loadStatus.buffer1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_InitCdStreamMode()
 // line 1381, offset 0x800382d4
	/* begin block 1 */
		// Start line: 1382
		// Start offset: 0x800382D4
		// Variables:
	// 		unsigned char cdMode; // stack offset -16
	/* end block 1 */
	// End offset: 0x800382D4
	// End Line: 1382

	/* begin block 2 */
		// Start line: 2710
	/* end block 2 */
	// End Line: 2711

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_InitCdStreamMode(void)

{
  byte local_10 [8];
  
  local_10[0] = 0xa0;
  CdReadyCallback(LOAD_CdReadReady);
  CdSyncCallback(LOAD_CdSeekCallback);
  CdControl(0xe,local_10,(undefined *)0x0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_DumpCurrentDir()
 // line 1391, offset 0x8003831c
	/* begin block 1 */
		// Start line: 2733
	/* end block 1 */
	// End Line: 2734

	/* begin block 2 */
		// Start line: 2734
	/* end block 2 */
	// End Line: 2735

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_DumpCurrentDir(void)

{
  if (loadStatus.bigFile.currentDir != (_BigFileDir *)0x0) {
    MEMPACK_Free((char *)loadStatus.bigFile.currentDir);
    loadStatus.bigFile.currentDir = (_BigFileDir *)0x0;
    loadStatus.bigFile.currentDirID = 0;
  }
  if (loadStatus.bigFile.cachedDir != (_BigFileDir *)0x0) {
    MEMPACK_Free((char *)loadStatus.bigFile.cachedDir);
    loadStatus.bigFile.cachedDir = (_BigFileDir *)0x0;
    loadStatus.bigFile.cachedDirID = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ LOAD_ChangeDirectoryByID(int id /*$s1*/)
 // line 1407, offset 0x8003836c
	/* begin block 1 */
		// Start line: 1408
		// Start offset: 0x8003836C

		/* begin block 1.1 */
			// Start line: 1412
			// Start offset: 0x80038384
			// Variables:
		// 		int i; // $v1

			/* begin block 1.1.1 */
				// Start line: 1419
				// Start offset: 0x800383A4
				// Variables:
			// 		struct _BigFileDir *dir; // $a0
			/* end block 1.1.1 */
			// End offset: 0x800383C4
			// End Line: 1425
		/* end block 1.1 */
		// End offset: 0x8003845C
		// End Line: 1444
	/* end block 1 */
	// End offset: 0x80038460
	// End Line: 1447

	/* begin block 2 */
		// Start line: 2766
	/* end block 2 */
	// End Line: 2767

int LOAD_ChangeDirectoryByID(int id)

{
  _BigFileDir *p_Var1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  lVar2 = loadStatus.bigFile.currentDirID;
  p_Var1 = loadStatus.bigFile.currentDir;
  if (id != 0) {
    if (loadStatus.bigFile.currentDirID == id) {
      return 1;
    }
    if (loadStatus.bigFile.cachedDirID == id) {
      loadStatus.bigFile.currentDir = loadStatus.bigFile.cachedDir;
      loadStatus.bigFile.cachedDir = p_Var1;
      loadStatus.bigFile.currentDirID = id;
      loadStatus.bigFile.cachedDirID = lVar2;
      return 1;
    }
    iVar3 = 0;
    if (0 < loadStatus.bigFile.numSubDirs) {
      do {
        iVar4 = iVar3 + 1;
        if (id == (int)loadStatus.bigFile.subDirList[iVar3].streamUnitID) {
          if (loadStatus.bigFile.cachedDir != (_BigFileDir *)0x0) {
            MEMPACK_Free((char *)loadStatus.bigFile.cachedDir);
          }
          loadStatus.currentDirLoading = 1;
          loadStatus.bigFile.cachedDirID = loadStatus.bigFile.currentDirID;
          loadStatus.bigFile.cachedDir = loadStatus.bigFile.currentDir;
          loadStatus.bigFile.currentDir = LOAD_ReadDirectory(loadStatus.bigFile.subDirList + iVar3);
          MEMPACK_SetMemoryBeingStreamed((char *)loadStatus.bigFile.currentDir);
          loadStatus.bigFile.currentDirID = id;
          return 1;
        }
        iVar3 = iVar4;
      } while (iVar4 < loadStatus.bigFile.numSubDirs);
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_SetSearchDirectory(long id /*$a0*/)
 // line 1454, offset 0x80038474
	/* begin block 1 */
		// Start line: 2908
	/* end block 1 */
	// End Line: 2909

	/* begin block 2 */
		// Start line: 2875
	/* end block 2 */
	// End Line: 2876

void LOAD_SetSearchDirectory(long id)

{
  loadStatus.bigFile.searchDirID = id;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ LOAD_GetSearchDirectory()
 // line 1459, offset 0x80038480
	/* begin block 1 */
		// Start line: 2884
	/* end block 1 */
	// End Line: 2885

	/* begin block 2 */
		// Start line: 2885
	/* end block 2 */
	// End Line: 2886

/* WARNING: Unknown calling convention yet parameter storage is locked */

long LOAD_GetSearchDirectory(void)

{
  return loadStatus.bigFile.searchDirID;
}



// decompiled code
// original method signature: 
// int /*$ra*/ LOAD_ChangeDirectoryFlag()
 // line 1464, offset 0x8003848c
	/* begin block 1 */
		// Start line: 2894
	/* end block 1 */
	// End Line: 2895

	/* begin block 2 */
		// Start line: 2895
	/* end block 2 */
	// End Line: 2896

/* WARNING: Unknown calling convention yet parameter storage is locked */

int LOAD_ChangeDirectoryFlag(void)

{
  return loadStatus.changeDir;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_UpdateBigFilePointers(struct _BigFileDir *oldDir /*$a0*/, struct _BigFileDir *newDir /*$a1*/)
 // line 1469, offset 0x80038498
	/* begin block 1 */
		// Start line: 2904
	/* end block 1 */
	// End Line: 2905

	/* begin block 2 */
		// Start line: 2905
	/* end block 2 */
	// End Line: 2906

void LOAD_UpdateBigFilePointers(_BigFileDir *oldDir,_BigFileDir *newDir)

{
  if (loadStatus.bigFile.currentDir == oldDir) {
    loadStatus.bigFile.currentDir = newDir;
  }
  if (loadStatus.bigFile.cachedDir == oldDir) {
    loadStatus.bigFile.cachedDir = newDir;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ LOAD_IsFileLoading()
 // line 1484, offset 0x800384c8
	/* begin block 1 */
		// Start line: 2934
	/* end block 1 */
	// End Line: 2935

	/* begin block 2 */
		// Start line: 2940
	/* end block 2 */
	// End Line: 2941

/* WARNING: Unknown calling convention yet parameter storage is locked */

int LOAD_IsFileLoading(void)

{
  return (uint)(loadStatus.currentQueueFile.readStatus != 0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_StopLoad()
 // line 1526, offset 0x800384d4
	/* begin block 1 */
		// Start line: 3052
	/* end block 1 */
	// End Line: 3053

	/* begin block 2 */
		// Start line: 2986
	/* end block 2 */
	// End Line: 2987

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_StopLoad(void)

{
  if (loadStatus.currentDirLoading != 0) {
    loadStatus.currentDirLoading = 0;
  }
  loadStatus.currentQueueFile.readStatus = 0;
  loadStatus.state = 5;
  return;
}





